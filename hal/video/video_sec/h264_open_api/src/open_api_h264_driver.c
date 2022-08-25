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
 *   open_api_h264_driver.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The file implements H.264 driver application dependence part
 *   functions.
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
#include "intrCtrl.h"
#include "h264_open_api_video_if.h"
#include "open_api_h264_decode.h"
#if defined (__VE_VIDEO_ARCHI_V2__)
#include "video_comm_v2.h"
#else
#include "video_comm.h"
#endif
#include "h264_dec_hw.h"
#include "open_api_h264_driver.h"
#include "open_api_h264_memory_management.h"
#include "mm_power_ctrl.h"
//#include "hisr_config.h"
#include "visualhisr.h"
#include "vcodec_v2_trc.h"
#include "dcl.h"
#ifdef dbg_print
#undef dbg_print
#define dbg_print(...)
#else
#define dbg_print(...)
#endif

/*******************************************************************************
*   Local global structure
*******************************************************************************/
//kal_uint32 H264_base = 0x800c1000;

typedef MEDIA_STATUS_CODE (*nalu_func_ptr)(H264_NAL_unit *prNALu);
nalu_func_ptr naluTypeFunc[32];

OPEN_API_MEM_INFO_T rMemInfo = {(H264_WORKING_INT_MEM_SIZE + 8192), // internal memory size
                                (H264_WORKING_EXT_MEM_SLICE_SIZE + H264_WORKING_EXT_MEM_STRUT_SIZE + 8192), // external memory size
                                KAL_FALSE  // YUV buffer should be non-cacheable
                                };

H264_NAL_unit nalu_slice;
H264_slice_info slice_temp;
kal_eventgrpid g_h264_dec_event_id = 0;
kal_uint32 currSliceID;
kal_uint32 g_frame_length;
kal_uint32 u4FrameWidth;
kal_uint32 u4FrameHeight;
vui_seq_parameters_t temp_v;
lastStatus_t lastStatus;
kal_bool fgTriggerHWDecode;
kal_bool fgDecodeSPSFailed;
kal_bool fgHasParsedSPS;
kal_bool fgHasParsedPPS;
kal_uint32 u4MaxSPSLen;
kal_uint32 u4MaxPPSLen;
kal_bool fgDisplayOrderMode;
kal_bool fgRealTriggerHW;
kal_bool fgSliceError = KAL_FALSE;
DCL_HANDLE g_H264GPTHandle = 0;
kal_bool fgReferenceCorrupted;
#include "dma_hw.h"
#include "dma_sw.h"
typedef struct
{
    kal_uint8 dma_handle;
    kal_bool dma_busy;
    void (*dma_callback)(void);
}h264_dec_error_dma_info;
static h264_dec_error_dma_info rH264HwDMAInfo;

// For debug useage
#define OUTPUT_ARRARY_SIZE  1000
kal_uint32 outputed_array[OUTPUT_ARRARY_SIZE];
kal_uint32 outputed_array_index;


//SPS/PPS error handling
kal_int32 last_parsed_sps_id;
kal_int32 last_parsed_pps_id;
kal_bool fgParameterError;

//Task insertion between GPT & HW decoder problem
kal_bool fgDecodingDone;
/*******************************************************************************
*   Extern global structure
*******************************************************************************/
extern H264_dec_info *g_open_api_h264_dec_info_ptr;
extern kal_int32 emuModifyPos;
extern H264_emulation_info g_open_api_h264_emu_info;
extern H264_DEC_ISR_PARAM  g_open_api_h264_dec_isr_param;
extern kal_int32 picCnt;
extern H264_DPB_list g_open_api_h264_DPB_list;
extern kal_uint32 emuSize;

/*******************************************************************************
*   Extern global structure
*******************************************************************************/
extern void h264_ref_marking(void);
extern MEDIA_STATUS_CODE h264_dec_ref_pic_marking(H264_sps_info *sps, H264_pps_info *pps, H264_slice_info *slice, H264_NAL_unit *nalu, kal_uint8 *p_addr, kal_uint32 *p_bitcnt);
extern void h264_make_ref_frame_list(H264_slice_info *slice);
extern void h264_pre_make_ref_frame(void);
extern MEDIA_STATUS_CODE h264_ref_pic_list_reordering(H264_pps_info *pps, H264_slice_info *slice, kal_uint8 *p_addr, kal_uint32 *p_bitcnt);
extern void h264_set_slice_header_vars(H264_sps_info *sps, H264_pps_info *pps, H264_slice_info *slice, H264_NAL_unit *nalu);
extern void open_api_h264_uitl_set_start_addr(kal_uint8 *p_addr);
extern kal_int64 h264_uitl_ue_long(kal_uint8 *p_addr, kal_uint32 *p_bitcnt);
extern kal_uint32 open_api_h264_uitl_u(kal_uint8 *p_addr, kal_uint32 *p_bitcnt, kal_int32 bit_len);
extern kal_int64 open_api_h264_uitl_se(kal_uint8 *p_addr, kal_uint32 *p_bitcnt);
extern kal_int32 h264_util_log2ceil(kal_int32 arg);
extern kal_uint32 open_api_h264_uitl_ue(kal_uint8 *p_addr, kal_uint32 *p_bitcnt);
extern kal_uint32 video_get_current_time(void);
extern kal_uint32 h264_util_align_mem(kal_uint32 start_addr, kal_uint32 bytes);
extern void open_api_h264_set_dpb_decode_done(void);
extern void open_api_h264_free_dpb(H264_DPB_entry* p_DPB);
extern void open_api_h264_decode_main(kal_uint32 frame_addr_offset,kal_uint32 dpb_addr);
extern H264_DPB_entry* open_api_h264_get_next_parse_dpb(kal_uint32 *p_frame_addr, kal_uint32 *p_frame_length);
extern MEDIA_STATUS_CODE h264_set_sps_vars(H264_sps_info *sps, kal_bool b_first);
extern void h264_extmem_init(void *start_ptr, kal_uint32 length);
extern kal_uint8 *h264_extmem_get_buffer(kal_uint32 size);
extern void h264_extmem_deinit(void);
extern void h264_intmem_init(void *start_ptr,kal_uint32 length);
extern kal_uint8 *h264_intmem_get_buffer(kal_uint32 size);
extern void h264_intmem_deinit(void);

// check this
extern kal_bool open_api_h264_add_dpb_info(kal_uint32 frame_addr, kal_uint32 frame_length);

/*******************************************************************************
*   Local function
*******************************************************************************/
static MEDIA_STATUS_CODE h264_parse_slice(H264_NAL_unit *prNALu, kal_uint32 *slice_index, kal_bool *p_b_redundant);
static MEDIA_STATUS_CODE h264_parse_sps(H264_NAL_unit *prNALu, kal_bool b_first);
static MEDIA_STATUS_CODE h264_parse_pps(H264_NAL_unit *prNALu);
kal_int32 _VideoH264IsNewAccessUnit(H264_NAL_unit *prNALu, H264_sps_info *prSPS, H264_pps_info *pps, H264_slice_info *prSlice);
static void init_global_vars(void);
void VideoH264InitIntr(void);
static kal_uint32 video_p2v_addr(kal_uint32 p_addr);
static kal_uint32 video_v2p_addr(kal_uint32 v_addr);
static void _VideoH264TimeOut(void *p);

/*******************************************************************************
*   Local function
*******************************************************************************/
kal_int32 output_a_pic_normal(H264_DPB_entry *out_dpbe)
{
	// display
	outputed_array[outputed_array_index] = (kal_uint32)(out_dpbe->frame_no);
	outputed_array_index = (outputed_array_index+1)%OUTPUT_ARRARY_SIZE;
    dbg_print("[DRV H264]output_a_pic_normal(), frame_no = %d\n\r", (kal_uint32)(outputed_array[outputed_array_index]));
    drv_trace2(TRACE_GROUP_10,OPEN_API_OUTPUTFRAME,(kal_uint32)out_dpbe->mem_addr,out_dpbe->is_corrupted);
	g_open_api_h264_dec_info_ptr->pfnOutputOneFrameCallback((kal_uint32)out_dpbe->mem_addr, out_dpbe->is_corrupted||fgReferenceCorrupted); 
	return 1;
}

void output_all_DPB_entries(kal_uint32 check_prior)
{
	kal_uint32 i, ind=0;
	H264_DPB_entry *dpbe, *dpb;
	kal_int32 minPOC, used_num;

	dbg_print("[DRV H264]output_all_DPB_entries()\n\r");
	if (check_prior == 1) // check if entries of DPB should be output.
	{
		used_num = g_open_api_h264_DPB_list.num_used ;
		while (used_num > 0)
		{
			minPOC = maxINT;
			dpb = g_open_api_h264_DPB_list.dpbe;
			for (i=0; i < (g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number+1);  i++)// find the one with smallest POC
			{
				dpbe = dpb++;
				if ((dpbe->b_dec_done == KAL_TRUE) && (dpbe->status_marked <= H264_unused_ref) && (dpbe->status_marked != -1) && (dpbe->isOutputed == 0) )// a ref pic and not output yet
				{
					if (dpbe->POC < minPOC)
					{
						minPOC = dpbe->POC;
						ind = i;
					}
				}
			}

			if (minPOC == maxINT)
			{
				break;
			}

			dpbe = &g_open_api_h264_DPB_list.dpbe[ind];
			if (output_a_pic_normal(dpbe) != 1)
			{
				return;
			}

			dpbe->isOutputed			=  1;
			dpbe->status_marked		= -1;
			//dpbe->pic_num			= -1;
			used_num-- ;
		}
	}
}

/*************************************************/
/* H264 driver error handling functions                               */
/*************************************************/

static void h264_dec_dma_callback(void)
{
    kal_set_eg_events(g_h264_dec_event_id, EVENT_H264_DMA_DONE, KAL_OR);
}

void h264_dec_dma_init(void)
{
#ifdef __VE_MTK_TARGET__	
    if(rH264HwDMAInfo.dma_handle == 0)
    {
        rH264HwDMAInfo.dma_handle = DMA_FullSize_GetChannel(DMA_H264);
        ASSERT(rH264HwDMAInfo.dma_handle!=0xff);
    }
    rH264HwDMAInfo.dma_busy = KAL_FALSE;
    rH264HwDMAInfo.dma_callback = NULL;
#endif    
}

void h264_dec_dma_deinit(void)
{
#ifdef __VE_MTK_TARGET__	
    if(rH264HwDMAInfo.dma_handle != 0)
    {
        // Release DMA handle
        DMA_FullSize_FreeChannel(rH264HwDMAInfo.dma_handle);    
        rH264HwDMAInfo.dma_handle = 0;
    }
    rH264HwDMAInfo.dma_busy = KAL_FALSE;
    rH264HwDMAInfo.dma_callback = NULL;
#endif    
}

static void h264_dec_copy_dma_V_callback(void)
{
#ifdef __VE_MTK_TARGET__	
    //DMA_FullSize_FreeChannel(g_h264_dma_info.dma_handle);
    rH264HwDMAInfo.dma_busy= KAL_FALSE;
    rH264HwDMAInfo.dma_callback();
#endif    
}

static void h264_dec_copy_dma_U_callback(void)
{
#ifdef __VE_MTK_TARGET__	
    DMA_INPUT input;
    DMA_SWCOPYMENU menu;
    kal_uint32 length;
    kal_uint32 total_mbs = g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_mbs*g_open_api_h264_dec_info_ptr->dec_param.pic_height_in_mbs;

    length = (total_mbs-g_open_api_h264_dec_info_ptr->dec_error_mb_num)*64;
    menu.srcaddr = (kal_uint32)(g_open_api_h264_dec_info_ptr->p_prev_dec_addr+(total_mbs*(256+64))+(g_open_api_h264_dec_info_ptr->dec_error_mb_num*64));
    menu.dstaddr = (kal_uint32)(g_open_api_h264_dec_info_ptr->p_curr_dec_addr+(total_mbs*(256+64))+(g_open_api_h264_dec_info_ptr->dec_error_mb_num*64));
    input.type = DMA_SWCOPY;
    input.menu = &menu;
    input.callback = h264_dec_copy_dma_V_callback;

    if ((menu.srcaddr|menu.dstaddr|length) & 0x01)
    {
        input.size = DMA_BYTE;
        input.count = length;
        if(length > 0xffff)
            input.count = 0xffff;
    }
    else if ((menu.srcaddr|menu.dstaddr|length) & 0x02)
    {
        input.size = DMA_SHORT;
        input.count = length>>1;
        if((length>>1) > 0xffff)
            input.count = 0xffff;
    }
    else
    {
        input.size = DMA_LONG;
        input.count = length>>2;
        if((length>>2) > 0xffff)
            input.count = 0xffff;
    }

    DMA_FullSize_Config(rH264HwDMAInfo.dma_handle,&input,KAL_TRUE);
#endif       
}


static void h264_dec_copy_dma_Y_callback(void)
{
#ifdef __VE_MTK_TARGET__
    DMA_INPUT input;
    DMA_SWCOPYMENU menu;
    kal_uint32 length;
    kal_uint32 total_mbs = g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_mbs*g_open_api_h264_dec_info_ptr->dec_param.pic_height_in_mbs;

    length = (total_mbs-g_open_api_h264_dec_info_ptr->dec_error_mb_num)*64;
    menu.srcaddr = (kal_uint32)(g_open_api_h264_dec_info_ptr->p_prev_dec_addr+(total_mbs*256)+(g_open_api_h264_dec_info_ptr->dec_error_mb_num*64));
    menu.dstaddr = (kal_uint32)(g_open_api_h264_dec_info_ptr->p_curr_dec_addr+(total_mbs*256)+(g_open_api_h264_dec_info_ptr->dec_error_mb_num*64));
    input.type = DMA_SWCOPY;
    input.menu = &menu;
    input.callback = h264_dec_copy_dma_U_callback;

    if ((menu.srcaddr|menu.dstaddr|length) & 0x01)
    {
        input.size = DMA_BYTE;
        input.count = length;
        if(length > 0xffff)
            input.count = 0xffff;
    }
    else if ((menu.srcaddr|menu.dstaddr|length) & 0x02)
    {
        input.size = DMA_SHORT;
        input.count = length>>1;
        if((length>>1) > 0xffff)
            input.count = 0xffff;
    }
    else
    {
        input.size = DMA_LONG;
        input.count = length>>2;
        if((length>>2) > 0xffff)
            input.count = 0xffff;
    }

    DMA_FullSize_Config(rH264HwDMAInfo.dma_handle,&input,KAL_TRUE);
#endif     
}

void h264_dec_copy_prev_dpb(void (*dma_callback)(void))
{
#ifdef __VE_MTK_TARGET__	
   //kal_uint8 handle=0xff;
   DMA_INPUT input;
   DMA_SWCOPYMENU menu;
   kal_uint32 length;

   if((g_open_api_h264_dec_info_ptr->p_prev_dec_addr==0) || (g_open_api_h264_dec_info_ptr->p_curr_dec_addr==0))
        return;

    rH264HwDMAInfo.dma_callback = dma_callback;
        
    if((g_open_api_h264_dec_info_ptr->dec_error_mb_num > 6) && (dma_callback != NULL))
    {        
        kal_uint32 total_mbs = g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_mbs*g_open_api_h264_dec_info_ptr->dec_param.pic_height_in_mbs;
        length = (total_mbs-g_open_api_h264_dec_info_ptr->dec_error_mb_num)*256;
        menu.srcaddr = (kal_uint32)(g_open_api_h264_dec_info_ptr->p_prev_dec_addr+(g_open_api_h264_dec_info_ptr->dec_error_mb_num*256));
        menu.dstaddr = (kal_uint32)(g_open_api_h264_dec_info_ptr->p_curr_dec_addr+(g_open_api_h264_dec_info_ptr->dec_error_mb_num*256));
        input.type = DMA_SWCOPY;
        input.menu = &menu;
        if(rH264HwDMAInfo.dma_callback != NULL)
            input.callback = h264_dec_copy_dma_Y_callback;
        else
            input.callback = NULL;
    }
    else
    {
        length = g_open_api_h264_dec_info_ptr->width*g_open_api_h264_dec_info_ptr->height*3/2;
        menu.srcaddr = (kal_uint32)g_open_api_h264_dec_info_ptr->p_prev_dec_addr;
        menu.dstaddr = (kal_uint32)g_open_api_h264_dec_info_ptr->p_curr_dec_addr;
        input.type = DMA_SWCOPY;
        input.menu = &menu;
        if(rH264HwDMAInfo.dma_callback != NULL)
            input.callback = h264_dec_copy_dma_V_callback;
        else
            input.callback = NULL;
    }
    
    if ((menu.srcaddr|menu.dstaddr|length) & 0x01)
    {
        input.size = DMA_BYTE;
        input.count = length;
        if(length > 0xffff)
           input.count = 0xffff;
    }
    else if ((menu.srcaddr|menu.dstaddr|length) & 0x02)
    {
        input.size = DMA_SHORT;
        input.count = length>>1;
        if((length>>1) > 0xffff)
            input.count = 0xffff;
    }
    else
    {
        input.size = DMA_LONG;
        input.count = length>>2;
        if((length>>2) > 0xffff)
            input.count = 0xffff;
    }

    rH264HwDMAInfo.dma_busy = KAL_TRUE;
    DMA_FullSize_Config(rH264HwDMAInfo.dma_handle,&input,KAL_TRUE);
#endif
}

static void _VideoH264WaitHwEvent(void)
{
    kal_uint32 event_group;

    if (fgRealTriggerHW)
    {
        kal_retrieve_eg_events(g_h264_dec_event_id, EVENT_H264_DEC_DONE|EVENT_H264_DEC_ERR, 
        						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
        if (event_group & EVENT_H264_DEC_ERR)
        {
            if ((g_open_api_h264_dec_info_ptr->p_curr_dec_addr != NULL) && 
                (g_open_api_h264_dec_info_ptr->p_prev_dec_addr != NULL))
            {
                h264_dec_copy_prev_dpb(h264_dec_dma_callback);
                kal_retrieve_eg_events(g_h264_dec_event_id, EVENT_H264_DMA_DONE, 
        	        					KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
            }
        } 
        if (g_open_api_h264_dec_info_ptr->decoded_bitstream_addr)
        {
            drv_trace1(TRACE_GROUP_10,OPEN_API_RETURNBSBUFFER,g_open_api_h264_dec_info_ptr->decoded_bitstream_addr);
            g_open_api_h264_dec_info_ptr->pfnReturnBsBufferCallback(g_open_api_h264_dec_info_ptr->decoded_bitstream_addr);
            g_open_api_h264_dec_info_ptr->decoded_bitstream_addr = NULL;
        }
        //else
        //{
        //    ASSERT(0);
        //}
        g_open_api_h264_dec_info_ptr->decoded_bitstream_addr = 0;
        fgRealTriggerHW = KAL_FALSE;
    }
}

MEDIA_STATUS_CODE _VideoH264HandleAccessUnitBoundary(H264_NAL_unit *prNALu)
{
	kal_uint32 event_group;
	kal_uint32 frame_addr_value, frame_addr_offset;
	H264_DPB_entry *p_cur_dpb; 
	kal_uint32 i, yuv_addr, index;
	H264_slice_info *slice; 
	kal_bool status;
	H264_DPB_entry *p_dpb;
    H264_DPB_list *p_DPB_list;

	frame_addr_offset=0;
	if (g_open_api_h264_dec_info_ptr->dec_param.all_slice[0].b_used != KAL_FALSE)		//If allSlice[0] (last AU) has valid data to be handled.
	{		
                if (g_open_api_h264_dec_info_ptr->b_pipeline_support)
                {
                    _VideoH264WaitHwEvent();
                }		
		p_cur_dpb = g_open_api_h264_dec_info_ptr->dec_param.p_curr_dpb;

		#ifdef __H264_DUMMY_B_SLICE_SUPPORT__
		g_open_api_h264_dec_info_ptr->dec_param.B_slice_exists=KAL_FALSE;
		#endif

    		g_open_api_h264_dec_info_ptr->dec_param.total_slice_num = currSliceID;

   		// Store POC information to DPB
		p_cur_dpb->pic_num = (kal_int32)g_open_api_h264_dec_info_ptr->dec_param.curr_pic_num;
		p_cur_dpb->top_POC = g_open_api_h264_dec_info_ptr->dec_param.top_field_order_cnt;
		p_cur_dpb->bottom_POC = g_open_api_h264_dec_info_ptr->dec_param.bottom_field_order_cnt;
		p_cur_dpb->POC = g_open_api_h264_dec_info_ptr->dec_param.picture_order_cnt;
		#ifdef __H264_DUMMY_B_SLICE_SUPPORT__
		p_cur_dpb->B_slice_exists=g_open_api_h264_dec_info_ptr->dec_param.B_slice_exists;
		#endif

		yuv_addr = g_open_api_h264_dec_info_ptr->pfnGetYUVBufferCallback();// changed to callback
        drv_trace1(TRACE_GROUP_10,OPEN_API_GETYUVBUFFER,yuv_addr);
		g_open_api_h264_dec_info_ptr->dec_param.p_curr_dpb->mem_addr = (kal_uint8  *)yuv_addr;
		
		if(g_open_api_h264_dec_info_ptr->dec_param.all_slice[0].slice_type==H264_slice_typeP && (g_open_api_h264_DPB_list.num_used<2 || picCnt==0))
		{
		    picCnt++;
		    fgRealTriggerHW = KAL_FALSE;
		    p_cur_dpb->is_corrupted = KAL_TRUE;
		    g_open_api_h264_dec_info_ptr->p_curr_dec_addr = (kal_uint8  *)yuv_addr;
		}
        else
        {
		    // Call HW decoding process
		    fgDecodingDone=KAL_FALSE;
		    open_api_h264_decode_main(frame_addr_offset, (kal_uint32)g_open_api_h264_dec_info_ptr->dec_param.p_curr_dpb);	// p_curr_dpb has the error!... mem_addr is null!

            if (g_open_api_h264_dec_info_ptr->b_pipeline_support)
            {
                SGPT_CTRL_START_T start;
	            start.u2Tick=g_open_api_h264_dec_info_ptr->timeout_value;
	            start.pfCallback=_VideoH264TimeOut;
	            start.vPara=NULL;
                //store the bitstream buffer for return
                if(g_open_api_h264_dec_info_ptr->decoded_bitstream_addr)
                {
                    drv_trace1(TRACE_GROUP_10,OPEN_API_RETURNBSBUFFER,g_open_api_h264_dec_info_ptr->decoded_bitstream_addr);
                    g_open_api_h264_dec_info_ptr->pfnReturnBsBufferCallback(g_open_api_h264_dec_info_ptr->decoded_bitstream_addr);
                    g_open_api_h264_dec_info_ptr->decoded_bitstream_addr = NULL;
                } 
                g_open_api_h264_dec_info_ptr->decoded_bitstream_addr = g_open_api_h264_dec_info_ptr->bitstream_addr;
                g_open_api_h264_dec_info_ptr->bitstream_addr = NULL;
                //if (g_open_api_h264_dec_info_ptr->decoded_bitstream_addr == NULL)
                //{
                //  ASSERT(0);
                //}
                ASSERT(g_open_api_h264_dec_info_ptr->timeout_value>=1 && g_open_api_h264_dec_info_ptr->timeout_value<=20);
                //GPTI_StartItem(g_H264GPTHandle,
                //        g_open_api_h264_dec_info_ptr->timeout_value,//10,   //100 ms
                //       _VideoH264TimeOut,
                //       NULL) ;
                DclSGPT_Control(g_H264GPTHandle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
            }     


		
		    picCnt++;

            video_dbg_trace(H264_DEC_DECODE_MAIN, picCnt);

            if (g_open_api_h264_dec_info_ptr->b_pipeline_support)
            {
                fgRealTriggerHW = KAL_TRUE;
            }              
            else
            {
		        //wait decode done/decode error event
   		        kal_retrieve_eg_events(g_h264_dec_event_id, EVENT_H264_DEC_DONE|EVENT_H264_DEC_ERR, 
						KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
            }
        }
        // previous frame reference marking should be executed after decode done
        h264_ref_marking();

        // If in non-display-ordering mode, we will output one decoded frame here
        //
        if (fgDisplayOrderMode == KAL_FALSE)
        {
            g_open_api_h264_dec_info_ptr->dec_param.p_curr_dpb->isOutputed = 1;
            output_a_pic_normal(g_open_api_h264_dec_info_ptr->dec_param.p_curr_dpb);

            p_DPB_list = g_open_api_h264_dec_info_ptr->dec_param.p_DPB_list;

            for (index=0; index < (g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number + 1); index++)
            {
                if ((p_DPB_list->dpbe[index].b_used == KAL_TRUE) && 
                    (p_DPB_list->dpbe[index].isOutputed == 1) &&
                    (p_DPB_list->dpbe[index].status_marked == H264_unused_ref) )
                {
                    open_api_h264_free_dpb(&p_DPB_list->dpbe[index]);
                    p_DPB_list->num_used--;
                }
            }
        }

		if (picCnt > 0)
		{
			// The bitstream mode has no frame length information. Use the total slice length
			status = open_api_h264_add_dpb_info((kal_uint32)prNALu->SODB, 0);
			if (status != KAL_TRUE)
			{
				video_dbg_trace(H264_DEC_ADD_DPB_INFO_ERROR, 0);           
			}
			g_open_api_h264_dec_info_ptr->hdr_add_frames_no++;   

			// get next dpb from dpb list
			p_dpb = open_api_h264_get_next_parse_dpb((kal_uint32*)&frame_addr_value, &g_frame_length);
			if (p_dpb == NULL)
			{
				//p_cur_dpb = g_open_api_h264_dec_info_ptr->dec_param.p_curr_dpb;
				video_dbg_trace(H264_DEC_PARSE_FRMAE_DPB_FULL_ERROR,g_open_api_h264_dec_info_ptr->hdr_parse_frames_no);           
				dbg_print("[DRV H264]hdr_parse_frames_no:%d\n\r", g_open_api_h264_dec_info_ptr->hdr_parse_frames_no);
                return VIDEO_ERROR;
			}
	
			g_open_api_h264_dec_info_ptr->dec_param.p_curr_dpb = p_dpb;  	//Set g_open_api_h264_dec_info_ptr->dec_param.p_curr_dpb

		}
		
		// Reset
		for (i = 0; i < currSliceID; i++) 
		{
			slice = &g_open_api_h264_dec_info_ptr->dec_param.all_slice[i];
			kal_mem_set(slice, 0, sizeof(H264_slice_info));
		}

	}
	else
	{
	  if (g_open_api_h264_dec_info_ptr->b_pipeline_support)
    {
        _VideoH264WaitHwEvent();
    }
  }
    // Set H/W decode flag
    //
    fgTriggerHWDecode = KAL_TRUE;

	g_open_api_h264_dec_info_ptr->dec_param.active_pps_id = maxUINT;
	currSliceID = 0;

    return MEDIA_STATUS_OK;
}

// The following fucntions are copied from JM. Need re-write.
static void _VideoH264ReadHRDParameters(kal_uint8 *p_data, kal_uint32 *p_bitcnt, hrd_parameters_t *hrd)
{
	kal_uint32 i, *p1, *p2;
	kal_uint8 *b;

	hrd->cpb_cnt_minus1 = open_api_h264_uitl_ue(p_data, p_bitcnt);
    if (hrd->cpb_cnt_minus1 > 31)
    {
        ASSERT(0);
        return;
    }
	hrd->bit_rate_scale = (kal_uint8)open_api_h264_uitl_u(p_data, p_bitcnt, 4);
	hrd->cpb_size_scale = (kal_uint8)open_api_h264_uitl_u(p_data, p_bitcnt, 4);

	p1 = hrd->bit_rate_value_minus1;
	p2 = hrd->cpb_size_value_minus1;
	b = hrd->cbr_flag;
	for( i=0; i <= hrd->cpb_cnt_minus1; i++ ) 
	{
		*(p1++) = open_api_h264_uitl_ue(p_data, p_bitcnt);
		*(p2++) = open_api_h264_uitl_ue(p_data, p_bitcnt);
		*(b++) = (kal_uint8)open_api_h264_uitl_u(p_data, p_bitcnt, 1);
	}

	hrd->initial_cpb_removal_delay_length_minus1 = (kal_uint8)open_api_h264_uitl_u(p_data, p_bitcnt, 5);
	hrd->cpb_removal_delay_length_minus1 = (kal_uint8)open_api_h264_uitl_u(p_data, p_bitcnt, 5);
	hrd->dpb_output_delay_length_minus1 = (kal_uint8)open_api_h264_uitl_u(p_data, p_bitcnt, 5);
	hrd->time_offset_length = (kal_uint8)open_api_h264_uitl_u(p_data, p_bitcnt, 5);
}

static void _VideoH264ReadVUI(kal_uint8 *p_data, kal_uint32 *bitcnt, H264_sps_info *sps)
{
	temp_v.aspect_ratio_info_present_flag = (kal_uint8)open_api_h264_uitl_u(p_data, bitcnt, 1);
    	if (temp_v.aspect_ratio_info_present_flag) 
    	{
      		temp_v.aspect_ratio_idc = (kal_uint8)open_api_h264_uitl_u(p_data, bitcnt, 8);
      		if (temp_v.aspect_ratio_idc == 255) 
      		{
        		temp_v.sar_width = open_api_h264_uitl_u(p_data, bitcnt, 16);
       		temp_v.sar_height = open_api_h264_uitl_u(p_data, bitcnt, 16);
      		}
	}
	temp_v.overscan_info_present_flag = (kal_uint8)open_api_h264_uitl_u(p_data, bitcnt, 1);
    	if (temp_v.overscan_info_present_flag) 
    	{
      		temp_v.overscan_appropriate_flag = (kal_uint8)open_api_h264_uitl_u(p_data, bitcnt, 1);
    	}

    	temp_v.video_signal_type_present_flag = (kal_uint8)open_api_h264_uitl_u(p_data, bitcnt, 1);
    	if (temp_v.video_signal_type_present_flag) 
    	{
      		temp_v.video_format = (kal_uint8)open_api_h264_uitl_u(p_data, bitcnt, 3);
      		temp_v.video_full_range_flag = (kal_uint8)open_api_h264_uitl_u(p_data, bitcnt, 1);
      		temp_v.colour_description_present_flag 	= (kal_uint8)open_api_h264_uitl_u(p_data, bitcnt, 1);
      		if (temp_v.colour_description_present_flag)
      		{
        		temp_v.colour_primaries = (kal_uint8)open_api_h264_uitl_u(p_data, bitcnt, 8);
        		temp_v.transfer_characteristics = (kal_uint8)open_api_h264_uitl_u(p_data, bitcnt, 8);
        		temp_v.matrix_coefficients = (kal_uint8)open_api_h264_uitl_u(p_data, bitcnt, 8);
      		}
    	}
    	temp_v.chroma_location_info_present_flag = (kal_uint8)open_api_h264_uitl_u(p_data, bitcnt, 1);
    	if(temp_v.chroma_location_info_present_flag) 
    	{
      		temp_v.chroma_sample_loc_type_top_field = open_api_h264_uitl_ue(p_data, bitcnt);
      		temp_v.chroma_sample_loc_type_bottom_field = open_api_h264_uitl_ue(p_data, bitcnt);
    	}
    	temp_v.timing_info_present_flag = (kal_uint8)open_api_h264_uitl_u(p_data, bitcnt, 1);
    	if (temp_v.timing_info_present_flag) 
    	{
      		temp_v.num_units_in_tick = open_api_h264_uitl_u(p_data, bitcnt, 32);
      		temp_v.time_scale = open_api_h264_uitl_u(p_data, bitcnt, 32);
      		temp_v.fixed_frame_rate_flag = (kal_uint8)open_api_h264_uitl_u(p_data, bitcnt, 1);
    	}
    	temp_v.nal_hrd_parameters_present_flag = (kal_uint8)open_api_h264_uitl_u(p_data, bitcnt, 1);
    	if (temp_v.nal_hrd_parameters_present_flag) 
    	{
      		_VideoH264ReadHRDParameters(p_data, bitcnt, &(temp_v.nal_hrd_parameters));
    	}
    	temp_v.vcl_hrd_parameters_present_flag = (kal_uint8)open_api_h264_uitl_u(p_data, bitcnt, 1);
    	if (temp_v.vcl_hrd_parameters_present_flag) 
    	{
      		_VideoH264ReadHRDParameters(p_data, bitcnt, &(temp_v.vcl_hrd_parameters));
    	}
    	if (temp_v.nal_hrd_parameters_present_flag || temp_v.vcl_hrd_parameters_present_flag) 
    	{
      		temp_v.low_delay_hrd_flag = (kal_uint8)open_api_h264_uitl_u(p_data, bitcnt, 1);
    	}
    	temp_v.pic_struct_present_flag = (kal_uint8)open_api_h264_uitl_u(p_data, bitcnt, 1);
    	temp_v.bitstream_restriction_flag = (kal_uint8)open_api_h264_uitl_u(p_data, bitcnt, 1);
    	if (temp_v.bitstream_restriction_flag) 
    	{
      		temp_v.motion_vectors_over_pic_boundaries_flag = (kal_uint8)open_api_h264_uitl_u(p_data, bitcnt, 1);
     		temp_v.max_bytes_per_pic_denom = open_api_h264_uitl_ue(p_data, bitcnt);
      		temp_v.max_bits_per_mb_denom = open_api_h264_uitl_ue(p_data, bitcnt);
      		temp_v.log2_max_mv_length_horizontal = open_api_h264_uitl_ue(p_data, bitcnt);
      		temp_v.log2_max_mv_length_vertical = open_api_h264_uitl_ue(p_data, bitcnt);
      		temp_v.num_reorder_frames = open_api_h264_uitl_ue(p_data, bitcnt);
      		temp_v.max_dec_frame_buffering = open_api_h264_uitl_ue(p_data, bitcnt);
    	}
	//sps->vui_seq_parameters = temp_v;
}

void _VideoH264VUIParameters(kal_uint8 *pu1SODB, kal_uint32 *bitcnt, H264_sps_info *sps)
{
	// The following two functions are copied from JM. Need re-write.
	// SODB
	_VideoH264ReadVUI(pu1SODB, bitcnt, sps);
	//InitVUI(sps);
}

void _VideoH264RBSPTrailingBits(kal_uint8 *p_addr, kal_uint32 *p_bitcnt)
{
	kal_uint32 curByte;
	kal_uint32 pos;		
	kal_uint32 rbsp_stop_one_bit;//, rbsp_alignment_zero_bit;
	kal_int32 consumedLens=0;

	curByte = (*p_bitcnt)/8;
	pos = (*p_bitcnt)&0x7;
	rbsp_stop_one_bit=p_addr[curByte]&(1<<(7-pos));
	consumedLens++;
	if (rbsp_stop_one_bit == 0)
	{
		dbg_print("Error! _VideoH264RBSPTrailingBits\n\r");	// must be 1
	}

	while((pos&7)!=7) {
		pos++;
		//rbsp_alignment_zero_bit = (p_addr[curByte+(pos>>3)])&(0x01<<(7-(pos&7)));
		consumedLens++;
		if (rbsp_stop_one_bit == 0)
		{
			dbg_print("Error! _VideoH264RBSPTrailingBits\n\r");	// must be 0
		}
	}
	(*p_bitcnt) += consumedLens;

}

static MEDIA_STATUS_CODE h264_parse_slice(H264_NAL_unit *prNALu, kal_uint32 *slice_index, kal_bool *p_b_redundant)
{
    H264_slice_info *slice = NULL;// = &g_open_api_h264_dec_info_ptr->dec_param.all_slice[*slice_index];
    H264_pps_info *pps;
    H264_sps_info *sps;
    kal_uint32 align_offset;
    kal_uint32 bitcnt = 0;
    MEDIA_STATUS_CODE status;
    kal_uint8 *pt = (kal_uint8*)emuModifyPos;
    kal_uint8 *p_data = prNALu->RBSP;
    kal_uint32 pa;

    // reset slice data first. Fux MAUI1413179
    // If data error and return error in the middle of parsing, the operation after decode done may be wrong
    //kal_mem_set(slice, 0, sizeof(H264_slice_info));
    
    //Fix MAUI_01297328 by SJ 20090113
    if (p_data == g_open_api_h264_emu_info.start_addr)
    {
        open_api_h264_uitl_set_start_addr(p_data);  
    }
    
    nalu_slice.forbidden_zero_bit = (p_data[0]>>7) & 1;
    nalu_slice.nal_ref_idc = (p_data[0]>>5) & 3;
    nalu_slice.nal_unit_type = (p_data[0]) & 0x1f;
    
    
    // Set slice data addr (PA), in case we can NOT complete the parse function
    // H/W will read the slice data addr when codec driver trigfer H/W to decode
    // If we do NOT set the addr, then H/W may read 0x00 (Un-inited) addr
    pa = g_open_api_h264_dec_info_ptr->pfnVideoV2PAddrCallback((kal_uint32)p_data);
    g_open_api_h264_dec_info_ptr->dec_param.all_slice[*slice_index].slice_data = (kal_uint8 *)pa;
    
    
    if ((nalu_slice.nal_unit_type != 1) && (nalu_slice.nal_unit_type != 5))
    {
        *p_b_redundant =KAL_TRUE;  
        video_dbg_trace(H264_DEC_PARSE_FRAME_DATA_ERROR,__LINE__);      
        dbg_print("[DRV H264]h264_dec_parse_frame_data() Error:, __LINE__:%d\n\r", __LINE__);
        return VIDEO_ERROR;
    }


    slice = &slice_temp;

    
    if(nalu_slice.nal_ref_idc!=0)
    {
        g_open_api_h264_dec_info_ptr->dec_param.b_ref_curr_frame = KAL_TRUE;
        slice->b_nal_ref_idc = KAL_TRUE;
    }
    else
    {
        slice->b_nal_ref_idc = KAL_FALSE;
    }
    bitcnt = 8;
    
    slice->first_mb_in_slice = open_api_h264_uitl_ue(p_data, &bitcnt); 
    slice->slice_type = (kal_uint8)open_api_h264_uitl_ue(p_data, &bitcnt); 
    if (slice->slice_type >= 5)
    {
        slice->slice_type -= 5;	// follow JM about this.
    }
    if ((slice->slice_type != H264_slice_typeP) && (slice->slice_type != H264_slice_typeI)) 
    {
        #ifdef __H264_DUMMY_B_SLICE_SUPPORT__
        if (slice->slice_type == H264_slice_typeB && nalu_slice.nal_ref_idc == 0)
        {
            //we don't support Reference to B-Slice  
            g_open_api_h264_dec_info_ptr->dec_param.B_slice_exists=KAL_TRUE;
        }
        else
        #endif
        {
            video_dbg_trace(H264_DEC_PARSE_FRAME_DATA_ERROR,__LINE__);    
            dbg_print("[DRV H264]h264_dec_parse_frame_data() Error:, __LINE__:%d\n\r", __LINE__);
            return VIDEO_ERROR;
        }
    }

    slice->pic_parameter_set_id = (kal_uint8)open_api_h264_uitl_ue(p_data, &bitcnt); 

    pps = &g_open_api_h264_dec_info_ptr->dec_param.all_pps[slice->pic_parameter_set_id];
    sps = &g_open_api_h264_dec_info_ptr->dec_param.all_sps[pps->seq_parameter_set_id];
    if(sps->b_used==KAL_FALSE || pps->b_used==KAL_FALSE)
    {
        //SPS/PPS error
        fgParameterError=KAL_TRUE;
        return VIDEO_ERROR;
    }

    slice->frame_num = open_api_h264_uitl_u(p_data, &bitcnt, sps->log2_max_frame_num_minus4+4);
    if(sps->frame_mbs_only_flag == 0) 
    {
    	video_dbg_trace(H264_DEC_PARSE_FRAME_DATA_ERROR,__LINE__);        
    	dbg_print("[DRV H264]h264_dec_parse_frame_data() Error:, __LINE__:%d\n\r", __LINE__);
    	return VIDEO_ERROR;
    } 
    
    // by default
    slice->field_pic_flag = 0;
    slice->bottom_field_flag = 0;

    if (nalu_slice.nal_unit_type == H264_sliceOfIDR) 
    {
        slice->b_idr = KAL_TRUE;
        slice->idr_pic_id = open_api_h264_uitl_ue(p_data, &bitcnt); 
        if (slice->idr_pic_id > 65535)
        {
        	video_dbg_trace(H264_DEC_PARSE_FRAME_DATA_ERROR,__LINE__);               
        	dbg_print("[DRV H264]h264_dec_parse_frame_data() Error:, __LINE__:%d\n\r", __LINE__);
        	return VIDEO_ERROR;
        }
    }
    else
    {
        slice->b_idr = KAL_FALSE;
    }

    // by default
    slice->pic_order_cnt_lsb = 0;	
    slice->delta_pic_order_cnt_bottom = 0;
    if (sps->pic_order_cnt_type == 0) 
    {
        slice->pic_order_cnt_lsb = open_api_h264_uitl_u(p_data, &bitcnt, sps->log2_max_pic_order_cnt_lsb_minus4+4);
        if ( (pps->pic_order_present_flag == 1)&&(slice->field_pic_flag == 0) )
        {
            slice->delta_pic_order_cnt_bottom = (kal_int32)open_api_h264_uitl_se(p_data, &bitcnt);      
        } 
        else 
        {
            slice->delta_pic_order_cnt_bottom = 0;
        }
    } 

    // by default
    slice->delta_pic_order_cnt[0] = 0;
    slice->delta_pic_order_cnt[1] = 0;
    if ( (sps->pic_order_cnt_type == 1)&&(sps->delta_pic_order_always_zero_flag == 0) )
    {
        slice->delta_pic_order_cnt[0] = (kal_int32)open_api_h264_uitl_se(p_data, &bitcnt);       
        if ( (pps->pic_order_present_flag == 1)&&(slice->field_pic_flag == 0) ) 
        {
            slice->delta_pic_order_cnt[1] = (kal_int32)open_api_h264_uitl_se(p_data, &bitcnt);       
        } 
    }

    // by default
    slice->redundant_pic_cnt = 0;
    *p_b_redundant = KAL_FALSE;
    if (pps->redundant_pic_cnt_present_flag==1) 
    {
        *p_b_redundant = KAL_TRUE;
        slice->redundant_pic_cnt = (kal_uint8)open_api_h264_uitl_ue(p_data, &bitcnt);     
        if (slice->redundant_pic_cnt > 127)
        {
        	video_dbg_trace(H264_DEC_PARSE_FRAME_DATA_ERROR,__LINE__);               
        	ASSERT(0);
        }
    } 

    if (slice->redundant_pic_cnt==0)
    {   
            if (_VideoH264IsNewAccessUnit(prNALu, sps, pps, slice))
            {	
                // Decode last AU by HW, store in DPB
                // _VideoH264HandleAccessUnitBoundary handles stuff about last AU

                _VideoH264HandleAccessUnitBoundary(prNALu);
            
                // initailize reference list parameters
                g_open_api_h264_dec_info_ptr->dec_param.ref_pic_list0.num_ref_frames = sps->num_ref_frames;

                g_open_api_h264_dec_info_ptr->dec_param.active_sps_id = pps->seq_parameter_set_id;
                g_open_api_h264_dec_info_ptr->dec_param.active_pps_id = slice->pic_parameter_set_id;
            }


        if (*slice_index == 0)
        {
            // set variables for the first slice in a picture
            h264_set_slice_header_vars(sps, pps, slice, &nalu_slice);
        }
            
        if (slice->slice_type == H264_slice_typeB) 
        {
          #ifdef __H264_DUMMY_B_SLICE_SUPPORT__
            //slice->ref_frame_index_list = 0xffffffffffffffff;
            slice->ref_frame_index_list = (kal_uint32)-1;
            return MEDIA_STATUS_OK;
          #else  
            video_dbg_trace(H264_DEC_PARSE_FRAME_DATA_ERROR,__LINE__);   
            dbg_print("[DRV H264]h264_dec_parse_frame_data() Error:, __LINE__:%d\n\r", __LINE__);
            return VIDEO_ERROR;
          #endif
        }    
        slice->num_ref_idx_active_override_flag = 0;
        slice->num_ref_idx_l0_active_minus1 = 0;
        if ( (slice->slice_type == H264_slice_typeP)||(slice->slice_type == H264_slice_typeSP)||(slice->slice_type == H264_slice_typeB) ) 
        {
            slice->num_ref_idx_active_override_flag = (kal_uint8)open_api_h264_uitl_u(p_data, &bitcnt, 1);
            if (slice->num_ref_idx_active_override_flag == 1) 
            {
                slice->num_ref_idx_l0_active_minus1 = (kal_uint8)open_api_h264_uitl_ue(p_data, &bitcnt);
                if (slice->num_ref_idx_l0_active_minus1>15)
                {
                	video_dbg_trace(H264_DEC_PARSE_FRAME_DATA_ERROR,__LINE__);       
                	dbg_print("[DRV H264]h264_dec_parse_frame_data() Error:, __LINE__:%d\n\r", __LINE__);
                    return VIDEO_ERROR;
                }    
            }
        } 

        status = h264_ref_pic_list_reordering(pps, slice, p_data, &bitcnt);
        if(status!=MEDIA_STATUS_OK)
        {
        	video_dbg_trace(H264_DEC_REF_PIC_R_ERROR,g_open_api_h264_dec_info_ptr->hdr_parse_frames_no);
        	dbg_print("[DRV H264]h264_ref_pic_list_reordering(), hdr_parse_frames_no:%d", g_open_api_h264_dec_info_ptr->hdr_parse_frames_no);  
        	return status;			// for Allegro_POC_CAVLC_B00_L30_5x6_10.264: Returning error causes the parsing slice cannot be stored! 
        }
        
        if (*slice_index == 0)
        {
            h264_pre_make_ref_frame();
        }
        h264_make_ref_frame_list(slice);	

        if (nalu_slice.nal_ref_idc != 0)
        {
            status=h264_dec_ref_pic_marking(sps, pps, slice, &nalu_slice, p_data, &bitcnt);

            if (status != MEDIA_STATUS_OK)
            {
            	video_dbg_trace(H264_DEC_PARSE_FRAME_DATA_ERROR,__LINE__);               
            	return status;        
            }
        }
        slice->slice_qp_delta = (kal_int32)open_api_h264_uitl_se(p_data, &bitcnt);

        // by default
        slice->disable_deblocking_filter_idc = 0;
        slice->slice_alpha_c0_offset_div2 = 0;
        slice->slice_beta_offset_div2 = 0;
        if(pps->deblocking_filter_control_present_flag==1) 
        {
            slice->disable_deblocking_filter_idc = open_api_h264_uitl_ue(p_data, &bitcnt);
            if (slice->disable_deblocking_filter_idc>2)
            {
            	   video_dbg_trace(H264_DEC_PARSE_FRAME_DATA_ERROR,__LINE__);   
            	   dbg_print("[DRV H264]h264_dec_parse_frame_data() Error:, __LINE__:%d\n\r", __LINE__);
                return VIDEO_ERROR;
            }    
            if(slice->disable_deblocking_filter_idc != 1) 
            {
                slice->slice_alpha_c0_offset_div2		= (kal_int32)open_api_h264_uitl_se(p_data, &bitcnt);
                slice->slice_beta_offset_div2			= (kal_int32)open_api_h264_uitl_se(p_data, &bitcnt);
                if ((-6>slice->slice_alpha_c0_offset_div2)||(slice->slice_alpha_c0_offset_div2>6))
                {
                	video_dbg_trace(H264_DEC_PARSE_FRAME_DATA_ERROR,__LINE__);           
                	dbg_print("[DRV H264]h264_dec_parse_frame_data() Error:, __LINE__:%d\n\r", __LINE__);
                    return VIDEO_ERROR;
                }    
                if ((-6>slice->slice_beta_offset_div2)||(slice->slice_beta_offset_div2>6))
                {
                	video_dbg_trace(H264_DEC_PARSE_FRAME_DATA_ERROR,__LINE__);               
                	dbg_print("[DRV H264]h264_dec_parse_frame_data() Error:, __LINE__:%d\n\r", __LINE__);
                    return VIDEO_ERROR;
                }    
            } 
        }
        
        if ((pps->num_slice_groups_minus1>0)&&(pps->slice_group_map_type>=3)&&(pps->slice_group_map_type<=5) ) 
        {
            kal_uint32 pic_size_in_map_units;
            kal_uint32 parse_size = 0;
            
            pic_size_in_map_units = (sps->pic_width_in_mbs_minus1 + 1) * (sps->pic_height_in_map_units_minus1 + 1);
            parse_size = pic_size_in_map_units/(pps->slice_group_change_rate_minus1 + 1);
#if defined(__H264_OPEN_API_DRIVER_FMO_BUG_FIXED__)
            if(pic_size_in_map_units%(pps->slice_group_change_rate_minus1 + 1))parse_size+=1;
#endif
            parse_size = (kal_uint32)h264_util_log2ceil((kal_int32)parse_size+1);
            slice->slice_group_change_cycle = open_api_h264_uitl_u(p_data, &bitcnt, (kal_int32)parse_size);
        }
        slice->slice_data = p_data + (bitcnt/8);
        slice->slice_data_bit_offset = (kal_uint8)(bitcnt & 0x7);
        align_offset = (kal_uint32)slice->slice_data & 0x3;
        if(align_offset != 0)
        {
            // force 4-byte aligned
            slice->slice_data_bit_offset += (kal_uint8)(align_offset*8);
            slice->slice_data = (kal_uint8*)(((kal_uint32)slice->slice_data) - align_offset); 
        }
        slice->slice_start_addr = (kal_uint32)p_data -1;  //keep slice start address, in recover case it will be used
    }
    
    	//find_end_of_nalu(&nalu);		// In order to find the 'NumBytesInNALunit'
    	nalu_slice.NumBytesInNALunit = prNALu->NumBytesInNALunit - g_open_api_h264_emu_info.emu_index/*emuSize*/ + 1;

    	//re-modify the removed 0x000003 code
	if ((pt >= slice->slice_data) && (pt < (slice->slice_data+4)))
	{
		video_dbg_trace(H264_DEC_ASSERT,__LINE__);
              ASSERT(0);
	}
	//reset modified emulation code addr
	emuModifyPos = 0;


    if(slice->redundant_pic_cnt==0)
    {
        slice->slice_length = nalu_slice.NumBytesInNALunit - (bitcnt/8);
    }


    // After parsing slice, transfer slice data to physical address
    // Upper layer video driver system only manage bitstream range VA -> PA
    // If there is byte alignment in codec driver (Ex: H.264 module alreays read 4-byte align addr
    // The addr configured to H/W may exceed managed bitstream range
    // Here it is codec driver's responsitbility to cover the offset
    // Ex: The passed in bitstream bufer addr: 0x1001, size 50
    //     Codec driver configure to H/W may be 0x0FFC
    //     Codec driver need to calculate the relative offset and fill 0x0FFC to H/W, 
    //     not through add translation mechanism (Provided by video driver),
    //     add translation only manage from 0x1001
    {
        //kal_uint32 pa;
        //pa = (kal_uint32)g_open_api_h264_dec_info_ptr->dec_param.all_slice[*slice_index].slice_data;
        if ((kal_uint32)slice->slice_data < (kal_uint32)p_data)
        {
            slice->slice_data = (kal_uint8 *) (pa - ((kal_uint32)p_data - (kal_uint32)slice->slice_data));
        }
        else
        {
        	   slice->slice_data = (kal_uint8 *) (pa + ((kal_uint32)slice->slice_data - (kal_uint32)p_data));
        }
    }
    //slice->slice_data = (kal_uint8 *)g_open_api_h264_dec_info_ptr->pfnVideoV2PAddrCallback((kal_uint32)slice->slice_data);
    	kal_mem_cpy(&g_open_api_h264_dec_info_ptr->dec_param.all_slice[*slice_index], slice, sizeof(H264_slice_info));
    	g_open_api_h264_dec_info_ptr->dec_param.all_slice[*slice_index].b_used = KAL_TRUE;


    if(*p_b_redundant==KAL_FALSE)
    {
    	// Accumulate the current slice size, check the DMA Limit when decoding. 
    	g_open_api_h264_dec_info_ptr->dec_param.slice_total_length += nalu_slice.NumBytesInNALunit-(bitcnt>>3);
    }

    
    
    return MEDIA_STATUS_OK;
}

static MEDIA_STATUS_CODE h264_parse_sps(H264_NAL_unit *prNALu, kal_bool b_first)
{
    H264_sps_info *sps = NULL; 
    kal_uint8 profile_idc, constraint_set0_flag, constraint_set1_flag, constraint_set2_flag, constraint_set3_flag;
    kal_uint8 level_idc, seq_parameter_set_id;
    //kal_uint32 reserved_zero_4bits;
    kal_uint32 bitcnt = 0;
    kal_uint32 index;
    kal_int32 lnt = lastStatus.nal_unit_type;
    kal_uint8 *p_data = prNALu->RBSP;

    //Fix MAUI_01297328 by SJ 20090113
    if (p_data == g_open_api_h264_emu_info.start_addr)
    {
    	 open_api_h264_uitl_set_start_addr(p_data);  
    }

    bitcnt = 8;
  
    // Clause 7.4.2.1 specify constraints for SPS parameters
    profile_idc = (kal_uint8)open_api_h264_uitl_u(p_data, &bitcnt, 8);
    dbg_print("[DRV H264]h264_parse_sps(), Profile:%d\n\r", profile_idc);
    if (profile_idc != H264_BASELINE_PROFILE_IDC)
    {
        return VIDEO_ERROR;
    }

    constraint_set0_flag	= (kal_uint8)open_api_h264_uitl_u(p_data, &bitcnt, 1);
    constraint_set1_flag	= (kal_uint8)open_api_h264_uitl_u(p_data, &bitcnt, 1);
    constraint_set2_flag	= (kal_uint8)open_api_h264_uitl_u(p_data, &bitcnt, 1);
    constraint_set3_flag	= (kal_uint8)open_api_h264_uitl_u(p_data, &bitcnt, 1);
    /*reserved_zero_4bits =*/ open_api_h264_uitl_u(p_data, &bitcnt, 4);
    level_idc = (kal_uint8)open_api_h264_uitl_u(p_data, &bitcnt, 8);
    dbg_print("[DRV H264]h264_parse_sps(), Level:%d\n\r", level_idc);
    if (level_idc > 30)
    {
        // not support level > 30
        return VIDEO_ERROR;
    }
    seq_parameter_set_id = (kal_uint8)open_api_h264_uitl_ue(p_data, &bitcnt);
    if (seq_parameter_set_id >= H264_MAX_SPS_NUMBER)
    {
        last_parsed_sps_id = -1;
        return VIDEO_ERROR;
    }
    last_parsed_sps_id = seq_parameter_set_id;
    if (!g_open_api_h264_dec_info_ptr->dec_param.all_sps[seq_parameter_set_id].b_used) 
    {
    	sps = &g_open_api_h264_dec_info_ptr->dec_param.all_sps[seq_parameter_set_id];
    	sps->b_used = KAL_TRUE;
    }
    else
    {
        //ASSERT(0);
        #if 1
        // Update an existing SPS. Todo: This only happens between two sequences. (clause 7.4.1.2.1)
        //if ( (lnt==endOfSeq_rbsp)||(lnt!=sliceOfnonIDR_rbsp)||(lnt!=sliceOfIDR_rbsp) )
        if (seq_parameter_set_id == g_open_api_h264_dec_info_ptr->dec_param.active_sps_id) 
        {
            _VideoH264HandleAccessUnitBoundary(prNALu);
            if (lnt == endOfSeq_rbsp)
            {
                //kal_mem_cpy(&g_open_api_h264_dec_info_ptr->dec_param.all_sps[seq_parameter_set_id], sps, sizeof(H264_sps_info));
                sps = &g_open_api_h264_dec_info_ptr->dec_param.all_sps[seq_parameter_set_id];
            }
            else 
            {	
                // in-between a sequence
                // Check if allSPS[ind] and sps are the same. If not, means video loss or invalid stream.
                /*
                if (!check_two_SPS_equal(allSPS[ind], sps)) 
                {
                    // Error handling: Maybe error occur?
                }
                else 
                {
                    // OK if the same.
                }
                */

                // Just update new sps information
                //
                sps = &g_open_api_h264_dec_info_ptr->dec_param.all_sps[seq_parameter_set_id];
            }
        } 
        else 
        {
            //kal_mem_cpy(&g_open_api_h264_dec_info_ptr->dec_param.all_sps[seq_parameter_set_id], sps, sizeof(H264_sps_info));
            sps = &g_open_api_h264_dec_info_ptr->dec_param.all_sps[seq_parameter_set_id];
        }
        #endif
    }
    sps->profile_idc = profile_idc;
    sps->constraint_set0_flag = constraint_set0_flag;
    sps->constraint_set1_flag = constraint_set1_flag;
    sps->constraint_set2_flag = constraint_set2_flag;
    sps->constraint_set3_flag = constraint_set3_flag;
    sps->level_idc = level_idc;
    sps->seq_parameter_set_id = seq_parameter_set_id;
    sps->chroma_format_idc	= 1; // 4:2:0
    sps->residual_colour_transform_flag = 0; // residual color transform not applied.
    sps->bit_depth_luma_minus8 = 0;
    sps->bit_depth_chroma_minus8 = 0;
    sps->qpprime_y_zero_transform_bypass_flag = 0;
    sps->seq_scaling_matrix_present_flag = 0;
    
    sps->log2_max_frame_num_minus4 = (kal_uint8)open_api_h264_uitl_ue(p_data, &bitcnt);	// To denote MaxFrameNum = 2^(log2_max_frame_num_minus4+4)
    if (sps->log2_max_frame_num_minus4 > 12)
    {
        return VIDEO_ERROR;
    }
    sps->pic_order_cnt_type = (kal_uint8)open_api_h264_uitl_ue(p_data, &bitcnt);
    if (sps->pic_order_cnt_type > 2)
    {
        return VIDEO_ERROR;
    }
    if (sps->pic_order_cnt_type == 0) 
    {
        sps->log2_max_pic_order_cnt_lsb_minus4 = (kal_uint8)open_api_h264_uitl_ue(p_data, &bitcnt);	// To denote MaxPicOrderCntLsb = 2^(log2_max_pic_order_cnt_lsb_minus4+4)
        if (sps->log2_max_pic_order_cnt_lsb_minus4 > 12)
        {
            return VIDEO_ERROR;
        }
    } 
    else if (sps->pic_order_cnt_type == 1) 
    {
        sps->delta_pic_order_always_zero_flag = open_api_h264_uitl_u(p_data, &bitcnt, 1);
        sps->offset_for_non_ref_pic = (kal_int32)open_api_h264_uitl_se(p_data, &bitcnt);
        sps->offset_for_top_to_bottom_field	 = (kal_int32)open_api_h264_uitl_se(p_data, &bitcnt);
        sps->num_ref_frames_in_pic_order_cnt_cycle = open_api_h264_uitl_ue(p_data, &bitcnt);
        if (sps->num_ref_frames_in_pic_order_cnt_cycle >= 256)
        {
            return VIDEO_ERROR;
        }
        for (index=0; index<sps->num_ref_frames_in_pic_order_cnt_cycle; index++)
        {
        	sps->offset_for_ref_frame[index] = (kal_int32)open_api_h264_uitl_se(p_data, &bitcnt);
        }
    }

    sps->num_ref_frames = (kal_uint8)open_api_h264_uitl_ue(p_data, &bitcnt);	// 0< sps->num_ref_frames <MaxDpbSize
    sps->gaps_in_frame_num_value_allowed_flag = (kal_uint8)open_api_h264_uitl_u(p_data, &bitcnt, 1);
    sps->pic_width_in_mbs_minus1 = (kal_uint16)open_api_h264_uitl_ue(p_data, &bitcnt);
    sps->pic_height_in_map_units_minus1 = (kal_uint16)open_api_h264_uitl_ue(p_data, &bitcnt);

    dbg_print("[DRV H264]h264_parse_sps(), Dimension: %d x %d\n\r",(sps->pic_width_in_mbs_minus1+1)*16,(sps->pic_height_in_map_units_minus1+1)*16);

    u4FrameWidth = (sps->pic_width_in_mbs_minus1+1)*16;
    u4FrameHeight = (sps->pic_height_in_map_units_minus1+1)*16;
   
    /*Scott, Hw Limitation & Memory Usage*/
    if (((sps->pic_width_in_mbs_minus1+1) > (H264_MAX_FRAME_WIDTH/16)) || 
        ((sps->pic_height_in_map_units_minus1+1) > (H264_MAX_FRAME_HEIGHT/16)))
    {
        return VIDEO_RESOLUTION_ERROR;
    }
    /*Scott, Hw Limitation*/    
    /*	 Modfied by SJ 20081212 according to H264_Functional_Spec.
     		 1.   Width in pixels must in the range of 32~720 
    		 2.	Height in pixels must in the range of 32~480
     */
    if ( ((sps->pic_width_in_mbs_minus1 + 1) < 2)  || ((sps->pic_height_in_map_units_minus1 + 1) < 2) )
    {
        return VIDEO_RESOLUTION_ERROR;      
    }
    /*Scott, Performance Limitation*/
    if(((sps->pic_width_in_mbs_minus1+1)*(sps->pic_height_in_map_units_minus1+1)) >
       (H264_MAX_FRAME_SIZE/16/16))
    {
        return VIDEO_RESOLUTION_ERROR;
    }

    sps->frame_mbs_only_flag = (kal_uint8)open_api_h264_uitl_u(p_data, &bitcnt, 1);
    if (sps->frame_mbs_only_flag != 1)
    {
        return VIDEO_ERROR;
    }
    sps->mb_adaptive_frame_field_flag = 0;
    sps->direct_8x8_inference_flag = (kal_uint8)open_api_h264_uitl_u(p_data, &bitcnt, 1);
    
    sps->frame_cropping_flag = (kal_uint8)open_api_h264_uitl_u(p_data, &bitcnt, 1);
    if (sps->frame_cropping_flag) 
    {
    	sps->frame_crop_left_offset = open_api_h264_uitl_ue(p_data, &bitcnt);
    	sps->frame_crop_right_offset = open_api_h264_uitl_ue(p_data, &bitcnt);
    	sps->frame_crop_top_offset = open_api_h264_uitl_ue(p_data, &bitcnt);
    	sps->frame_crop_bottom_offset = open_api_h264_uitl_ue(p_data, &bitcnt);
    } 
    else 
    {	// by default
    	sps->frame_crop_left_offset = 0;
    	sps->frame_crop_right_offset = 0;
    	sps->frame_crop_top_offset = 0;
    	sps->frame_crop_bottom_offset = 0;
    }
    sps->vui_parameters_present_flag	= (kal_uint8)open_api_h264_uitl_u(p_data, &bitcnt, 1);
    
    	if (sps->vui_parameters_present_flag)
    	{
    		//to do : if need vui information, parse vui info
    		_VideoH264VUIParameters(p_data, &bitcnt, sps);
    	}

    	_VideoH264RBSPTrailingBits(p_data, &bitcnt);

    if (picCnt == 0)
    {
    	//set SPS variables and allocate resources
    	if (h264_set_sps_vars(sps, b_first) != MEDIA_STATUS_OK)
       {
            return VIDEO_UNSUPPORT;
       }
    }
    fgHasParsedSPS = KAL_TRUE;
    
    if( prNALu->NumBytesInNALunit > u4MaxSPSLen )
      u4MaxSPSLen = prNALu->NumBytesInNALunit;

    return MEDIA_STATUS_OK;
}

/* Parse PPS information and store to related pps structure
* @param p_data start address of the PPS NALU
 * @param size total size of the PPS NALU
 * @return MEDIA_STATUS_CODE 
 */
static MEDIA_STATUS_CODE h264_parse_pps(H264_NAL_unit *prNALu)
{
	H264_pps_info *pps = NULL;
	H264_sps_info *sps = NULL;
	kal_uint32 pic_parameter_set_id;
	kal_uint32 bitcnt = 0;
	kal_uint32 index;
	kal_uint32 u_size;
	kal_int32 lnt = lastStatus.nal_unit_type;
    kal_uint8 *p_data = prNALu->RBSP;

	//Fix MAUI_01297328 by SJ 20090113
	if (p_data == g_open_api_h264_emu_info.start_addr)
	{
		open_api_h264_uitl_set_start_addr(p_data);  
	}

	bitcnt = 8;

	// Constraints for the following variables are specified in Clause 7.4.2.2
	pic_parameter_set_id = (kal_uint8)open_api_h264_uitl_ue(p_data, &bitcnt);
	if (pic_parameter_set_id >= H264_MAX_PPS_NUMBER)
	{
	    last_parsed_pps_id = -1;
		VIDEO_ASSERT(0);
		return VIDEO_ERROR;
	}
    last_parsed_pps_id = pic_parameter_set_id;
	if (!g_open_api_h264_dec_info_ptr->dec_param.all_pps[pic_parameter_set_id].b_used) 
	{
		pps = &g_open_api_h264_dec_info_ptr->dec_param.all_pps[pic_parameter_set_id];
		pps->b_used = KAL_TRUE;
	}
	else
	{
		#if 1
		if (pic_parameter_set_id == g_open_api_h264_dec_info_ptr->dec_param.active_pps_id) 
		{
			_VideoH264HandleAccessUnitBoundary(prNALu);
			if ( (lnt == AUDelimiter_rbsp) || (pic_parameter_set_id != g_open_api_h264_dec_info_ptr->dec_param.active_pps_id) ) 
			{
				// _VideoH264HandleAccessUnitBoundary may set activePPSID as maxUINT to indicate the end of an AU.
				//kal_mem_cpy(&g_open_api_h264_dec_info_ptr->dec_param.all_pps[pic_parameter_set_id], pps, sizeof(H264_pps_info));
				pps = &g_open_api_h264_dec_info_ptr->dec_param.all_pps[pic_parameter_set_id];
			}
			else 
			{	// in-between an access unit
				// Check if allPPS[ind] and pps are the same. If not, means video loss or invalid stream.
				/*
				if (!check_two_PPS_equal(allPPS[pps->pic_parameter_set_id], pps)) 
				{
					// Error handling: Maybe error occur?
				}
				else 
				{
					// OK if the same.
				}
				*/

                // Update PPS information
                //
			    pps = &g_open_api_h264_dec_info_ptr->dec_param.all_pps[pic_parameter_set_id];	
			}
		} 
		else 
		{
			//kal_mem_cpy(&g_open_api_h264_dec_info_ptr->dec_param.all_pps[pic_parameter_set_id], pps, sizeof(H264_pps_info));
			pps = &g_open_api_h264_dec_info_ptr->dec_param.all_pps[pic_parameter_set_id];
		}
		#endif
	}
	pps->pic_parameter_set_id = (kal_uint8)pic_parameter_set_id;

	pps->seq_parameter_set_id = (kal_uint8)open_api_h264_uitl_ue(p_data, &bitcnt);
	if (pps->seq_parameter_set_id >= H264_MAX_SPS_NUMBER)
	{
		VIDEO_ASSERT(0);
		return VIDEO_ERROR;
	}
	sps = &g_open_api_h264_dec_info_ptr->dec_param.all_sps[pps->seq_parameter_set_id];
	if (sps->b_used == KAL_FALSE)
	{
		VIDEO_ASSERT(0);
		return VIDEO_ERROR;
	}

	pps->entropy_coding_mode_flag = (kal_uint8)open_api_h264_uitl_u(p_data, &bitcnt, 1);     // 0:UVLC or CAVLC; 1: CABAC
	if (pps->entropy_coding_mode_flag!=0)
	{
		// for Baseline    
		VIDEO_ASSERT(0);
		return VIDEO_ERROR;
	} 
	pps->pic_order_present_flag = (kal_uint8)open_api_h264_uitl_u(p_data, &bitcnt, 1);    
	pps->num_slice_groups_minus1 = (kal_uint8)open_api_h264_uitl_ue(p_data, &bitcnt);     // Constraints specified in Annex A, 0-7for baseline
	if (pps->num_slice_groups_minus1 >= 8)
	{
		// for Baseline 
		VIDEO_ASSERT(0);
		return VIDEO_ERROR;
	} 

	if (pps->num_slice_groups_minus1>0) 
	{
		pps->slice_group_map_type = (kal_uint8)open_api_h264_uitl_ue(p_data, &bitcnt);
		//pps->slice_group_id = NULL;  
		if (pps->slice_group_map_type > 6)
		{
			// for Baseline
			VIDEO_ASSERT(0);
			return VIDEO_ERROR;
		} 

		if (pps->slice_group_map_type == 0) 
		{          
			// interleaved slice groups
			for (index=0; index <= pps->num_slice_groups_minus1; index++) 
			{
				pps->run_length_minus1[index] = open_api_h264_uitl_ue(p_data, &bitcnt); 
			}
		} 
		else if (pps->slice_group_map_type == 2) 
		{        
			// one or more "foreground" slice groups and a "leftover" slice group.
			for (index=0; index < pps->num_slice_groups_minus1; index++) 
			{
				pps->top_left[index] = open_api_h264_uitl_ue(p_data, &bitcnt); 
				pps->bottom_right[index] = open_api_h264_uitl_ue(p_data, &bitcnt); 
			}
		}
		else if ( (pps->slice_group_map_type == 3) ||
			(pps->slice_group_map_type == 4) ||
                    (pps->slice_group_map_type == 5) ) 
		{
			pps->slice_group_change_direction_flag  = (kal_uint8)open_api_h264_uitl_u(p_data, &bitcnt, 1); 
			pps->slice_group_change_rate_minus1 = open_api_h264_uitl_ue(p_data, &bitcnt); 
		} 
		else if (pps->slice_group_map_type == 6) 
		{
			pps->pic_size_in_map_units_minus1 = open_api_h264_uitl_ue(p_data, &bitcnt); 
			if ((pps->pic_size_in_map_units_minus1+1) != (kal_uint32)((sps->pic_width_in_mbs_minus1+1)*(sps->pic_height_in_map_units_minus1+1)))
			{
			       VIDEO_ASSERT(0);
				return VIDEO_ERROR;
			}
			u_size = h264_util_log2ceil(pps->num_slice_groups_minus1+1);
			for (index=0; index<=pps->pic_size_in_map_units_minus1; index++)
                pps->slice_group_id[index] = (kal_uint8)open_api_h264_uitl_u(p_data, &bitcnt, (kal_int32)u_size);
		}
	}

    pps->num_ref_idx_l0_active_minus1 = (kal_uint8)open_api_h264_uitl_ue(p_data, &bitcnt); 
    if (pps->num_ref_idx_l0_active_minus1 >= 32)
    {
        VIDEO_ASSERT(0);
        return VIDEO_ERROR;
    }
    pps->num_ref_idx_l1_active_minus1 = (kal_uint8)open_api_h264_uitl_ue(p_data, &bitcnt); 
    pps->weighted_pred_flag = (kal_uint8)open_api_h264_uitl_u(p_data, &bitcnt, 1);
    pps->weighted_bipred_idc = (kal_uint8)open_api_h264_uitl_u(p_data, &bitcnt, 2);
    if ((pps->weighted_bipred_idc!=0) ||(pps->weighted_pred_flag!=0))
    {
        // for Baseline
        VIDEO_ASSERT(0);
        return VIDEO_ERROR;
    } 
    pps->pic_init_qp_minus26 = (kal_int32)open_api_h264_uitl_se(p_data, &bitcnt);  
    pps->pic_init_qs_minus26 = (kal_int32)open_api_h264_uitl_se(p_data, &bitcnt);  
    pps->chroma_qp_index_offset = (kal_int32)open_api_h264_uitl_se(p_data, &bitcnt);
    
    pps->deblocking_filter_control_present_flag = (kal_uint8)open_api_h264_uitl_u(p_data, &bitcnt, 1);
    pps->constrained_intra_pred_flag = (kal_uint8)open_api_h264_uitl_u(p_data, &bitcnt, 1);
    pps->redundant_pic_cnt_present_flag = (kal_uint8)open_api_h264_uitl_u(p_data, &bitcnt, 1);

    // for baseline    
    pps->transform_8x8_mode_flag = 0; // 8x8 transform decoding process not in use
    pps->pic_scaling_matrix_present_flag = 0; // scaling list used for the pic shall be inferred to those specified by the SPS.
    pps->second_chroma_qp_index_offset = pps->chroma_qp_index_offset;
	
   	_VideoH264RBSPTrailingBits(p_data, &bitcnt);

    fgHasParsedPPS = KAL_TRUE;
    
    if( prNALu->NumBytesInNALunit > u4MaxPPSLen )
      u4MaxPPSLen = prNALu->NumBytesInNALunit;

    return MEDIA_STATUS_OK;
}

static kal_bool _VideoH264FlushBufferCommand(void)
{
    H264_DPB_list *p_DPB_list;
    kal_uint32 index;

    if (g_open_api_h264_dec_info_ptr->dec_param.p_DPB_list != NULL)
    {
        p_DPB_list = g_open_api_h264_dec_info_ptr->dec_param.p_DPB_list;
    }
    else
    {
        //ASSERT(0);
        return KAL_FALSE;
    }

    if (g_open_api_h264_dec_info_ptr->b_pipeline_support)
    {
        //wait last frame
        _VideoH264WaitHwEvent();
    }

    output_all_DPB_entries(1);

	  for (index=0; index < (g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number+1); index++)
    {
        if ((p_DPB_list->dpbe[index].b_used == KAL_TRUE) && (p_DPB_list->dpbe[index].isOutputed == 1)  )
        {
            open_api_h264_free_dpb(&p_DPB_list->dpbe[index]);
            p_DPB_list->num_used--;
        }
    }
    return KAL_TRUE;
}

/*******************************************************************************
*   Public driver interface
*******************************************************************************/
static void h264_dec_reset(void)
{
    kal_uint8 index;

    OPEN_API_WriteReg32(H264_DEC_COMD, H264_DEC_COMD_RST);
    for (index = 0; index < 5; index++);

    video_dbg_trace(H264_DEC_RESET, video_get_current_time());
}

static MEDIA_STATUS_CODE h264_dec_init(void *param)
{
    H264_DEC_INIT_PARAM_TYPE_T *p_init_param = (H264_DEC_INIT_PARAM_TYPE_T*)param;
    kal_uint32 dblk_addr0, dblk_addr1, mc_line_addr, mc_mv_addr, cavlc_addr;
    kal_uint32 dblk_size;
    kal_uint32 free_starting_addr;	// record the starting address of the unused mem.
    kal_uint32 slice_group_buffer_p_addr;		// ((1024/16)*(480/16)*2) = 3840
    kal_uint32 slice_map_buffer_p_addr;		// ((1024/16)*(480/16)*2) = 3840
    kal_uint32 slice_conf_buffer_p_addr;
    kal_uint32 ref_frame_buffer_p_addr;

    video_dbg_trace(H264_DEC_INIT, video_get_current_time());

    if (!param)
    {
        dbg_print("[Open_API_H264]Input parameter error %d!\n\r", __LINE__);
        return VIDEO_ERROR;
    }

    drv_trace4(TRACE_GROUP_10,OPEN_API_ENTERVIDEOH264DECOPEN,p_init_param->ext_mem_addr.p_addr,
        p_init_param->ext_mem_size,p_init_param->int_mem_addr.p_addr,p_init_param->int_mem_size);

    // Initalize H/W 
    // Switch on power of H.264 decoder 
    // And select GMC port for H.264
    //
    /*
    // For MT6516
	DRV_Reg(MMCG_CLR0) = MMCG_CON0_H264;
	*((volatile unsigned short *) (0x94000020)) = 1; //Switch GMC port to H264
    */
    
	#if defined(__OLD_PDN_DEFINE__)
    //*(volatile kal_uint16*)DRVPDN_CON0_CLR = (kal_uint16)(DRVPDN_CON0_H264);
    OPEN_API_WriteReg(DRVPDN_CON0_CLR, (kal_uint16)(DRVPDN_CON0_H264));
    #elif defined(__CLKG_DEFINE__)
	//DRV_Reg(MMCG_CLR0) = MMCG_CON0_H264;
	// Use mm power management instead
	mm_enable_power(MMPWRMGR_H264);    
    #endif 
#if 0
	#ifdef _H264_NEW_GMC_SETTING
	#if defined(MT6238) || defined(MT6239)
/* under construction !*/
/* under construction !*/
	#elif defined(MT6268) ||defined(MT6268A)
/* under construction !*/
/* under construction !*/
	#endif
	#else
/* under construction !*/
	#endif
#endif
    OPEN_API_WriteReg(H264_SWITCH_GMC_PORT, 1);

    // Check initial memory size
    //
    if ((p_init_param->int_mem_size < H264_WORKING_INT_MEM_SIZE) || (p_init_param->ext_mem_size < H264_WORKING_EXT_MEM_SLICE_SIZE + H264_WORKING_EXT_MEM_STRUT_SIZE))
    {
        ASSERT(0);
    }

    // Check input physical address is 8K aligned.
    //
    if ((p_init_param->int_mem_addr.p_addr & 0x1FFF) || (p_init_param->ext_mem_addr.p_addr & 0x1FFF))
    {
        ASSERT(0);
    }

    // The internal memory management is just managed in range of H264_WORKING_EXT_MEM_STRUT_SIZE
    // 
    h264_extmem_init((void*)(p_init_param->ext_mem_addr.v_addr + H264_WORKING_EXT_MEM_SLICE_SIZE), H264_WORKING_EXT_MEM_STRUT_SIZE);
    //h264_intmem_init((void*)(p_init_param->int_mem_addr.v_addr + H264_WORKING_INT_MEM_SIZE + H264_WORKING_EXT_MEM_SLICE_SIZE), H264_WORKING_EXT_MEM_STRUT_SIZE);

    // Allocate H.264 control structure & initialize to zero
    //
    g_open_api_h264_dec_info_ptr = (H264_dec_info *)h264_extmem_get_buffer(sizeof(H264_dec_info));
    kal_mem_set(g_open_api_h264_dec_info_ptr, 0, sizeof(H264_dec_info));

    // Allocate working memory first due to h/w buffer alignment issue
    //
    g_open_api_h264_dec_info_ptr->int_mem_p_addr = (kal_uint8 *)p_init_param->int_mem_addr.p_addr;
    g_open_api_h264_dec_info_ptr->int_mem_size = p_init_param->int_mem_size;
    g_open_api_h264_dec_info_ptr->ext_mem_p_addr = (kal_uint8 *)p_init_param->ext_mem_addr.p_addr;
    g_open_api_h264_dec_info_ptr->ext_mem_size = p_init_param->ext_mem_size;

    // Set display mode
    //
    fgDisplayOrderMode = p_init_param->fgDisplayOrderMode;
    
    // Assign callback functions
    //
    g_open_api_h264_dec_info_ptr->pfnOutputOneFrameCallback = p_init_param->pfnOutputOneFrameCallback;
    g_open_api_h264_dec_info_ptr->pfnSetFrameUnReferenceCallback = p_init_param->pfnSetFrameUnReferenceCallback;
    g_open_api_h264_dec_info_ptr->pfnGetYUVBufferCallback = p_init_param->pfnGetYUVBufferCallback;
    g_open_api_h264_dec_info_ptr->pfnVideoP2VAddrCallback = video_p2v_addr;
    g_open_api_h264_dec_info_ptr->pfnVideoV2PAddrCallback = video_v2p_addr;

    g_open_api_h264_dec_info_ptr->pfnReturnBsBufferCallback = p_init_param->pfnReturnBsBufferCallback;
    g_open_api_h264_dec_info_ptr->bitstream_addr = 0;
    g_open_api_h264_dec_info_ptr->decoded_bitstream_addr = 0;
    g_open_api_h264_dec_info_ptr->b_pipeline_support = KAL_FALSE;

    if(!g_H264GPTHandle)
    {
        //GPTI_GetHandle(&g_H264GPTHandle);
        g_H264GPTHandle=DclSGPT_Open(DCL_GPT_CB, 0);
    }

    //DBLK buffer allocation:
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

    free_starting_addr = (kal_uint32)(cavlc_addr + 520);

    // Check memory boundary
    //
    if (free_starting_addr > (kal_uint32)g_open_api_h264_dec_info_ptr->int_mem_p_addr + H264_WORKING_INT_MEM_SIZE)
    {
        ASSERT(0);
    }

    /* allocate hw structures memory */
    // note that the following ones should all allocate double, one for decoding one, the other for parsing one
    slice_map_buffer_p_addr = (kal_uint32)g_open_api_h264_dec_info_ptr->ext_mem_p_addr;
    g_open_api_h264_dec_info_ptr->p_slice_map_memory = (kal_uint8*) g_open_api_h264_dec_info_ptr->pfnVideoP2VAddrCallback(slice_map_buffer_p_addr);

    slice_conf_buffer_p_addr = h264_util_align_mem((slice_map_buffer_p_addr + H264_SLICE_MAP_STRUCT_SIZE(H264_MAX_FRAME_HEIGHT) + 32), 32);
    g_open_api_h264_dec_info_ptr->p_slice_conf_memory = (kal_uint8 *)g_open_api_h264_dec_info_ptr->pfnVideoP2VAddrCallback(slice_conf_buffer_p_addr);

    /* Reset slice config by SJ for CR "MAUI_01255993" 20081022. */
    kal_mem_set(g_open_api_h264_dec_info_ptr->p_slice_conf_memory , 0xff, (kal_uint32)(H264_SLICE_CONF_STRUCT_SIZE((H264_MAX_FRAME_SIZE)) + 32));

    ref_frame_buffer_p_addr = h264_util_align_mem((slice_conf_buffer_p_addr + (H264_SLICE_CONF_STRUCT_SIZE((H264_MAX_FRAME_SIZE)) + 32) + 64), 64);
    g_open_api_h264_dec_info_ptr->p_ref_frame_memory = (kal_uint8 *)g_open_api_h264_dec_info_ptr->pfnVideoP2VAddrCallback(ref_frame_buffer_p_addr);

    slice_group_buffer_p_addr = ref_frame_buffer_p_addr + 128;
    // This uses virtual memory space
    g_open_api_h264_dec_info_ptr->p_slice_group_memory = (kal_uint8 *)g_open_api_h264_dec_info_ptr->pfnVideoP2VAddrCallback(slice_group_buffer_p_addr);

    if ((kal_uint32)(g_open_api_h264_dec_info_ptr->p_slice_group_memory + H264_MAX_MB_NUMBER) >= (kal_uint32)g_open_api_h264_dec_info_ptr)
    {
        ASSERT(0);
    }

    // Structure init
    //
    g_open_api_h264_dec_info_ptr->hdr_parse_frames_no = 0;
    g_open_api_h264_dec_info_ptr->hdr_add_frames_no = 0;

    g_open_api_h264_dec_info_ptr->dec_param.prev_ppsID = 0;

    g_open_api_h264_dec_info_ptr->b_dec_error = KAL_FALSE;

    outputed_array_index = 0;

    init_global_vars();

    // Init ISR
    //
    VideoH264InitIntr();

    // Creat eventgroup
    //
    if(g_h264_dec_event_id == 0)
		g_h264_dec_event_id = kal_create_event_group("H264_DEC_EVEVT");

    // Reset H.264 decoder
    //
    h264_dec_reset();    

    h264_dec_dma_init();
    g_open_api_h264_dec_info_ptr->p_prev_dec_addr = NULL;
    g_open_api_h264_dec_info_ptr->p_curr_dec_addr = NULL;    
    g_open_api_h264_dec_info_ptr->dec_error_mb_num = 0xFFFFFFFF;

    g_open_api_h264_dec_info_ptr->timeout_value=10;
    g_open_api_h264_dec_info_ptr->system_dpb_size = 0xFFFFFFFF;

    return MEDIA_STATUS_OK;
}

static void h264_dec_intr_dlr(void)
{
    kal_uint32 status;
    kal_bool b_ret = KAL_FALSE;	

    if (g_open_api_h264_dec_info_ptr->b_pipeline_support)
    {
        //GPTI_StopItem(g_H264GPTHandle);
        DclSGPT_Control(g_H264GPTHandle,SGPT_CMD_STOP,0);
    }
    fgDecodingDone = KAL_TRUE;

    status = OPEN_API_Reg32(H264_DEC_IRQ_STS);	
    video_dbg_trace(H264_DEC_IRQ_STATUS, status);
    OPEN_API_WriteReg32(H264_DEC_IRQ_ACK, status);	

    if ((status&H264_DEC_IRQ_STS_DEC_DONE)
    #ifdef __H264_DUMMY_B_SLICE_SUPPORT__
    ||(g_open_api_h264_dec_info_ptr->dec_param.B_slice_exists)
    #endif
	 )
    {
    	video_dbg_trace(H264_DEC_INTR_DLR_END, 0);
    	open_api_h264_set_dpb_decode_done();
    	b_ret = KAL_TRUE;			
    }
    else if (status & H264_DEC_IRQ_STS_DMA_PAUSE)
    {
    	if (g_open_api_h264_dec_isr_param.check_vlc_addr == KAL_TRUE)
    	{
    		/* frame length is larger than 0xffff */
    		VIDEO_ASSERT(0);

    		/* Reload VLC DMA */
    		OPEN_API_WriteReg32(H264_DEC_DMA_LIMIT,0xffff);
    		OPEN_API_WriteReg32(H264_DEC_DMA_COMD, H264_DEC_DMA_COMD_RESUME);

    		video_dbg_trace(H264_DEC_INTR_DLR_END, 1);
    		return;
    	}
    	else
    	{
    		// HW decode wrong or software control wrong
    		video_dbg_trace(H264_DEC_INTR_DLR_END, 2);
    		VIDEO_ASSERT(0);

            h264_dec_reset();
    		open_api_h264_set_dpb_decode_done();
	    	b_ret = KAL_FALSE;		
       }
    }
    else
    {
    	// decode fail 
    	video_dbg_trace(H264_DEC_INTR_DLR_END, 3);
    	open_api_h264_set_dpb_decode_done();
    	h264_dec_reset();
    	b_ret = KAL_FALSE;		
    }	

    g_open_api_h264_dec_info_ptr->dec_frames_no++;
	
    if (b_ret == KAL_TRUE)
    {
        kal_set_eg_events(g_h264_dec_event_id, EVENT_H264_DEC_DONE, KAL_OR);
    }
    else
    {
        kal_uint16 *p_slice_map = (kal_uint16*)OPEN_API_Reg32(H264_DEC_SLICE_MAP_ADDR);
        g_open_api_h264_dec_info_ptr->dec_error_mb_num = (((OPEN_API_Reg32(H264_DEC_DEBUG_INFO8)>>6)&0x3f) *
                                                                                                    g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_mbs) 
                                                                                  + (OPEN_API_Reg32(H264_DEC_DEBUG_INFO8)&0x3f);
        if(g_open_api_h264_dec_info_ptr->dec_error_mb_num>=g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_mbs)
        {
            g_open_api_h264_dec_info_ptr->dec_error_mb_num-= g_open_api_h264_dec_info_ptr->dec_param.pic_width_in_mbs;
        }
                             
        if(p_slice_map[0] == 0xffff)
        {
            // no any slice
            // copy whole picture
            g_open_api_h264_dec_info_ptr->dec_error_mb_num = 0;
        }
        kal_set_eg_events(g_h264_dec_event_id, EVENT_H264_DEC_ERR, KAL_OR);
    }
}

static MEDIA_STATUS_CODE h264_dec_close(void)
{
	H264_DPB_list *p_DPB_list = g_open_api_h264_dec_info_ptr->dec_param.p_DPB_list;
	kal_uint32 index;

    drv_trace0(TRACE_GROUP_10,OPEN_API_ENTERVIDEOH264DECCLOSE);
    if (g_open_api_h264_dec_info_ptr->b_pipeline_support)
    {
        //wait last frame if it exists
        _VideoH264WaitHwEvent();
    }

	output_all_DPB_entries(1);

	for (index=0; index < (g_open_api_h264_dec_info_ptr->dec_param.max_DPB_number+1); index++)
    	{
    		if (  (p_DPB_list->dpbe[index].b_used == KAL_TRUE) && (p_DPB_list->dpbe[index].isOutputed == 1)  )
        	{
        		open_api_h264_free_dpb(&p_DPB_list->dpbe[index]);
        		p_DPB_list->num_used--;
    		}
	}
 
    // Remember to de init memory management
    h264_extmem_deinit();
    h264_intmem_deinit();

#if defined(__OLD_PDN_DEFINE__)
    //*(volatile kal_uint16*)DRVPDN_CON0_SET = (kal_uint16)(DRVPDN_CON0_H264);
    OPEN_API_WriteReg(DRVPDN_CON0_SET, (kal_uint16)(DRVPDN_CON0_H264));
#elif defined(__CLKG_DEFINE__)
    //DRV_Reg(MMCG_SET0) = MMCG_CON0_H264;
    // Use mm power management instead
    mm_disable_power(MMPWRMGR_H264);
#endif 	

    h264_dec_dma_deinit();

    g_open_api_h264_dec_info_ptr->timeout_value = 10;
    return MEDIA_STATUS_OK;
}

// This function is used to handle H/W is no reponse for some times
//
static void h264_dec_timeout_recover(void)
{
    
    h264_dec_reset();
    open_api_h264_set_dpb_decode_done();

    g_open_api_h264_dec_info_ptr->dec_frames_no++;

    // Set the event
    //
    kal_set_eg_events(g_h264_dec_event_id, EVENT_H264_DEC_ERR, KAL_OR);
}

static void h264_dec_get_param(OPEN_API_PARAM_TYPE_T rType, void *pParam, kal_uint32 u4Size)
{
    kal_uint32 *pu4Param;
    OPEN_API_MEM_INFO_T *prMemInfo;
    H264_DECODE_CROPPING_T *prCropping;

    if (!pParam)
    {
        dbg_print("[Open_API_H264]Input parameter error %d!\n\r", __LINE__);
        return;
    }
    
    switch(rType)
    {
    case OPEN_API_PARAM_WIDTH:
        if (u4Size != sizeof(kal_uint32))
        {
            ASSERT(0);
        }

        pu4Param = (kal_uint32 *)pParam;
        ASSERT(pu4Param);
        *pu4Param = u4FrameWidth;

        break;
    case OPEN_API_PARAM_HEIGHT:
        if (u4Size != sizeof(kal_uint32))
        {
            ASSERT(0);
        }
        
        pu4Param = (kal_uint32 *)pParam;
        ASSERT(pu4Param);
        *pu4Param = u4FrameHeight;

        break;
    case OPEN_API_PARAM_REAL_WIDTH:
        if (u4Size != sizeof(kal_uint32))
        {
            ASSERT(0);
        }

        pu4Param = (kal_uint32 *)pParam;
        ASSERT(pu4Param);
        *pu4Param = g_open_api_h264_dec_info_ptr->real_width;

        break;
    case OPEN_API_PARAM_REAL_HEIGHT:
        if (u4Size != sizeof(kal_uint32))
        {
            ASSERT(0);
        }
        
        pu4Param = (kal_uint32 *)pParam;
        ASSERT(pu4Param);
        *pu4Param = g_open_api_h264_dec_info_ptr->real_height;

        break;
    case OPEN_API_PARAM_MEM_INFO:
        if (u4Size != sizeof(OPEN_API_MEM_INFO_T))
        {
            ASSERT(0);
        }
        
        prMemInfo = (OPEN_API_MEM_INFO_T *)pParam;
        ASSERT(prMemInfo);

        prMemInfo->u4IntMemSize = rMemInfo.u4IntMemSize;
        prMemInfo->u4ExtMemSize = rMemInfo.u4ExtMemSize;
        prMemInfo->fgExtCacheable = rMemInfo.fgExtCacheable;
        prMemInfo->isBsCacheable = 0;
        prMemInfo->isFrameCacheable = 0;
        break;  
    case OPEN_API_PARAM_CROPPING_INFO:
        if (u4Size != sizeof(H264_DECODE_CROPPING_T))
        {
            ASSERT(0);
        }
        
        prCropping = (H264_DECODE_CROPPING_T *)pParam;
        ASSERT(prCropping);
        prCropping->u4LeftX = g_open_api_h264_dec_info_ptr->crop_x0;
        prCropping->u4RightX = g_open_api_h264_dec_info_ptr->crop_x1;
        prCropping->u4TopY = g_open_api_h264_dec_info_ptr->crop_y0;
        prCropping->u4BottomY = g_open_api_h264_dec_info_ptr->crop_y1;
        break;
    default:
        ASSERT(0);
        break;
    }
    drv_trace2(TRACE_GROUP_10,OPEN_API_ENTERVIDEOH264DECGETPARAM,rType,*(kal_uint32*)pParam);

}


static void h264_dec_set_param(OPEN_API_PARAM_TYPE_T rType, void *pParam, kal_uint32 u4Size)
{
    if (!pParam)
    {
        dbg_print("[Open_API_H264]Input parameter error %d!\n\r", __LINE__);
        return;
    }

    drv_trace2(TRACE_GROUP_10,OPEN_API_ENTERVIDEOH264DECSETPARAM,rType,*(kal_uint32*)pParam);

    // If parse sps,pps error happened, we will always return error
    // Because the codec can't decode any more. The uppper layer need 
    // to close and re-open codec
    //
    if (fgDecodeSPSFailed == KAL_TRUE)
    {
        return;
    }

    switch(rType)
    {
    case OPEN_API_PARAM_FLUSH_BUFFER_CMD:
        _VideoH264FlushBufferCommand();
        break;
    case OPEN_API_PARAM_TIMEOUT:
        g_open_api_h264_dec_info_ptr->timeout_value = *(kal_uint32*)pParam;
        if(g_open_api_h264_dec_info_ptr->timeout_value < 1)
            g_open_api_h264_dec_info_ptr->timeout_value = 1;
        if(g_open_api_h264_dec_info_ptr->timeout_value > 20)
            g_open_api_h264_dec_info_ptr->timeout_value = 20;
        break;
    default:
        ASSERT(0);
        break;
    }

}

VIDEO_DEC_DRIVER_TYPE_T h264_dec_driver =
{
    h264_dec_init,
    h264_dec_close,
    NULL,
    h264_dec_get_param,
    h264_dec_set_param,
    h264_dec_intr_dlr,
    h264_dec_timeout_recover
};

/*******************************************************************************
*   Public Video APIs
*******************************************************************************/
/*
MEDIA_STATUS_CODE error1(H264_NAL_unit *prNALu) 
{
	video_dbg_trace(H264_DEC_ERROR1_FUNC, 0);
	//while(1);
	ASSERT(0);
	return VIDEO_ERROR;
}
*/
MEDIA_STATUS_CODE slice_layer_without_partitioning_rbsp(H264_NAL_unit *prNALu)
{
	kal_bool b_redundant, status;
	kal_uint32 frame_addr_value;
	H264_DPB_entry *p_dpb;
       MEDIA_STATUS_CODE eRet;

	g_open_api_h264_dec_info_ptr->dec_param.slice_total_length = 0;
	if ((picCnt == 0) && (currSliceID == 0))
	{
		// The bitstream mode has no frame length information. Use the total slice length
    		status = open_api_h264_add_dpb_info((kal_uint32)prNALu->SODB, 0);
    		if (status != KAL_TRUE)
    		{
    			video_dbg_trace(H264_DEC_ADD_DPB_INFO_ERROR, 0);           
    			//return KAL_FALSE;
    		}
    		g_open_api_h264_dec_info_ptr->hdr_add_frames_no++;   

		// get next dpb from dpb list
		p_dpb = open_api_h264_get_next_parse_dpb((kal_uint32*)&frame_addr_value, &g_frame_length);
		if (p_dpb == NULL)
		{
			//p_cur_dpb = g_open_api_h264_dec_info_ptr->dec_param.p_curr_dpb;
			video_dbg_trace(H264_DEC_PARSE_FRMAE_DPB_FULL_ERROR,g_open_api_h264_dec_info_ptr->hdr_parse_frames_no);           
			dbg_print("[DRV H264]hdr_parse_frames_no:%d\n\r", g_open_api_h264_dec_info_ptr->hdr_parse_frames_no);
			//ASSERT(0);
			return VIDEO_ERROR;
		}	
		g_open_api_h264_dec_info_ptr->dec_param.p_curr_dpb = p_dpb;  	
	}

    video_dbg_trace(H264_DEC_CURRENT_SLICE_ID, currSliceID);
	eRet = h264_parse_slice(prNALu, &currSliceID, &b_redundant);

    if (eRet == VIDEO_ERROR)
    {
        if (!fgSliceError)
        {
            fgSliceError = KAL_TRUE;
        }
    }
    
    
    return MEDIA_STATUS_OK;
}

static MEDIA_STATUS_CODE dummy_nalu_type(H264_NAL_unit *prNALu)
{
	video_dbg_trace(H264_DEC_DUMMY_FUNC, 0);
    return MEDIA_STATUS_OK;
}

MEDIA_STATUS_CODE seq_parameter_set_rbsp(H264_NAL_unit *prNALu)
{

	return (h264_parse_sps(prNALu, KAL_TRUE));
}

MEDIA_STATUS_CODE pic_parameter_set_rbsp(H264_NAL_unit *prNALu)
{
	
	return (h264_parse_pps(prNALu));
}

static void _VideoH264SetLastNALuStatus(H264_NAL_unit *prNALu, lastStatus_t *lastSts)
{
	kal_int32 u4NaluType;
	H264_sps_info  *sps;
	H264_pps_info *pps;
	H264_slice_info *slice = &g_open_api_h264_dec_info_ptr->dec_param.all_slice[currSliceID];;

    if (!prNALu)
    {
        ASSERT(0);
        return;
    }
    u4NaluType = prNALu->nal_unit_type;

	lastSts->NumBytesInNALunit = prNALu->NumBytesInNALunit - g_open_api_h264_emu_info.emu_index/*emuSize*/ + 1;
	// nal_ref_idc of SEI is 0, which may confuse the judgement of "if (lastStatus.nal_ref_idc != 0) {" after HW_Decode()
	if ((u4NaluType == 6) || (u4NaluType == 12))
	{
		return;
	}

	//Rita modify for Allegor 0117
	//lastSts->nal_ref_idc = prNALu->nal_ref_idc;
	//lastSts->isForRef = (prNALu->nal_ref_idc != 0)?1:0;
	lastSts->nal_unit_type = u4NaluType;
	
	if ( ((u4NaluType == 1) || (u4NaluType == 5)) && (slice->redundant_pic_cnt == 0)) 
	{
		lastSts->nal_ref_idc = prNALu->nal_ref_idc;
        
		pps = &g_open_api_h264_dec_info_ptr->dec_param.all_pps[slice->pic_parameter_set_id];
		sps = &g_open_api_h264_dec_info_ptr->dec_param.all_sps[pps->seq_parameter_set_id];
		
		lastSts->frame_num = slice->frame_num;
		lastSts->idr_pic_id = slice->idr_pic_id;
		lastSts->spsID = pps->seq_parameter_set_id;
		lastSts->ppsID = slice->pic_parameter_set_id;
		lastSts->bottom_field_flag = (kal_int8)slice->bottom_field_flag;
		lastSts->field_pic_flag = (kal_int8)slice->field_pic_flag;
		lastSts->isIDR = (u4NaluType==5)?1:0;

		if (sps->pic_order_cnt_type == 0) 
		{
			lastSts->pic_order_cnt_type = 0;
			lastSts->pic_order_cnt_lsb = slice->pic_order_cnt_lsb;
			if (prNALu->nal_ref_idc != 0)
			{
				lastSts->prevRefPOClsb = (kal_int32)lastSts->pic_order_cnt_lsb;
			}
			lastSts->delta_pic_order_cnt_bottom	= slice->delta_pic_order_cnt_bottom;
		} 
		else if (sps->pic_order_cnt_type == 1) 
		{
			lastSts->pic_order_cnt_type = 1;
			lastSts->delta_pic_order_cnt[0] = slice->delta_pic_order_cnt[0];
			lastSts->delta_pic_order_cnt[1] = slice->delta_pic_order_cnt[1];
		}
		currSliceID++;	

		//s->enum_modify_pos = emuModifyPos;
		//lastSts->picCnt = picCnt;
	}
	// Todo: anything else?

}

// New access unit detection according to the requirement of new access unit from spec. Subclause 7.4.1.2.4
kal_int32 _VideoH264IsNewAccessUnit(H264_NAL_unit *prNALu, H264_sps_info *prSPS, H264_pps_info *pps, H264_slice_info *prSlice)
{
	kal_int32 result = 0;

	result |= (kal_int32)(lastStatus.frame_num != prSlice->frame_num);

	result |= (kal_int32)(lastStatus.ppsID != prSlice->pic_parameter_set_id);

	result |= (kal_int32)(lastStatus.field_pic_flag != prSlice->field_pic_flag);

	if ( (prSlice->field_pic_flag == 1) && (lastStatus.field_pic_flag == 1) ) 
	{
	    result |= (kal_int32)(lastStatus.bottom_field_flag != prSlice->bottom_field_flag);
	}

	result |= (kal_int32)((lastStatus.nal_ref_idc != prNALu->nal_ref_idc) && ((lastStatus.nal_ref_idc == 0) || (prNALu->nal_ref_idc == 0)));

	if (prSlice->idr_pic_id) 
	{
		result |= (kal_int32)(lastStatus.idr_pic_id != prSlice->idr_pic_id);
	}

	//Rita add for WJ08 file
	result |= (kal_int32)((lastStatus.nal_unit_type != prNALu->nal_unit_type) && (kal_int32)(lastStatus.nal_unit_type != 5) && (kal_int32)(prNALu->nal_unit_type == 5));

	if (prSPS->pic_order_cnt_type == 0) 
	{
		result |= (kal_int32)(lastStatus.pic_order_cnt_lsb != prSlice->pic_order_cnt_lsb);
		result |= (kal_int32)(lastStatus.delta_pic_order_cnt_bottom != prSlice->delta_pic_order_cnt_bottom);
	}

	if (prSPS->pic_order_cnt_type == 1) 
	{
		result |= (kal_int32)(lastStatus.delta_pic_order_cnt[0] != prSlice->delta_pic_order_cnt[0]);
		result |= (kal_int32)(lastStatus.delta_pic_order_cnt[1] != prSlice->delta_pic_order_cnt[1]);
	}

	return result;
}

static MEDIA_STATUS_CODE _VideoH264AccessUnitDelimiterRBSP(H264_NAL_unit *prNALu)
{
    //kal_int32 primary_pic_type;
    kal_uint32 bitcnt = 0;

    if( fgDecodingDone )
    {
        if(g_open_api_h264_dec_info_ptr->decoded_bitstream_addr)
        {
            drv_trace1(TRACE_GROUP_10,OPEN_API_RETURNBSBUFFER,g_open_api_h264_dec_info_ptr->bitstream_addr);
            g_open_api_h264_dec_info_ptr->pfnReturnBsBufferCallback(g_open_api_h264_dec_info_ptr->decoded_bitstream_addr);
        }
        g_open_api_h264_dec_info_ptr->decoded_bitstream_addr=NULL;
    }

    _VideoH264HandleAccessUnitBoundary(prNALu);
	
    
	
    /*primary_pic_type = (kal_int32)*/open_api_h264_uitl_u(prNALu->SODB, &bitcnt, 3);
    _VideoH264RBSPTrailingBits(prNALu->SODB, &bitcnt);

    return MEDIA_STATUS_OK;
}

static MEDIA_STATUS_CODE _VideoH264EndOfSeqRBSP(H264_NAL_unit *prNALu)
{
	// Nothing to do. Follow Clause 7.3.2.5
	_VideoH264HandleAccessUnitBoundary(prNALu);
    return MEDIA_STATUS_OK;
}

static MEDIA_STATUS_CODE _VideoH264EndOfStreamRBSP(H264_NAL_unit *prNALu)
{
	// Nothing to do. Follow Clause 7.3.2.6
	_VideoH264HandleAccessUnitBoundary(prNALu);
    return MEDIA_STATUS_OK;
}

static MEDIA_STATUS_CODE _VideoH264FillerDataRBSP(H264_NAL_unit *prNALu)
{
	//kal_uint8 c;
	kal_uint32 bitcnt = 0;

	while ( (/*c=*/(kal_uint8)open_api_h264_uitl_u(prNALu->SODB, &bitcnt, 8)) == maxBYTE);
	bitcnt -= 8;
	_VideoH264RBSPTrailingBits(prNALu->SODB, &bitcnt);

    return MEDIA_STATUS_OK;
}

static MEDIA_STATUS_CODE _VideoH264SeqParameterSetExtensionRBSP(H264_NAL_unit *prNALu)
{
	kal_uint32 	seq_parameter_set_id, aux_format_idc, bit_depth_aux_minus8;//, alpha_opaque_value, alpha_transparent_value;		// u(v)
	//kal_uint8	alpha_incr_flag, additional_extension_flag;		// u(1)
	kal_uint32   bitcnt = 0;

	seq_parameter_set_id = open_api_h264_uitl_ue(prNALu->SODB, &bitcnt);
	if (seq_parameter_set_id > 31)
	{
		dbg_print("_VideoH264SeqParameterSetExtensionRBSP\n\r");
	}
	aux_format_idc = open_api_h264_uitl_ue(prNALu->SODB, &bitcnt);
	if (aux_format_idc > 3)
	{
		dbg_print("_VideoH264SeqParameterSetExtensionRBSP\n\r");
	}
	if (aux_format_idc != 0) 
	{
		bit_depth_aux_minus8 = open_api_h264_uitl_ue(prNALu->SODB, &bitcnt);
		if (bit_depth_aux_minus8 > 4)
		{
			dbg_print("_VideoH264SeqParameterSetExtensionRBSP\n\r");
		}
		/*alpha_incr_flag = */(kal_uint8)open_api_h264_uitl_u(prNALu->SODB, &bitcnt, 1);
		/*alpha_opaque_value = */open_api_h264_uitl_u(prNALu->SODB, &bitcnt, (kal_int32)bit_depth_aux_minus8+9);
		/*alpha_transparent_value = */open_api_h264_uitl_u(prNALu->SODB, &bitcnt, (kal_int32)bit_depth_aux_minus8+9);
	}
	/*additional_extension_flag =*/ (kal_uint8)open_api_h264_uitl_u(prNALu->SODB, &bitcnt, 1);	// Should be 0. 1 for future use.
	_VideoH264RBSPTrailingBits(prNALu->SODB, &bitcnt);
    return MEDIA_STATUS_OK;
}

// Released functions
//

MEDIA_STATUS_CODE VideoH264DecOpen(void *param)
{
    return (h264_dec_driver.init(param));
}

MEDIA_STATUS_CODE VideoH264DecClose(void)
{
    return (h264_dec_driver.close());
}

void VideoH264DecGetParam(OPEN_API_PARAM_TYPE_T rType, void *pParam, kal_uint32 u4Size)
{
    h264_dec_driver.get_param(rType, pParam, u4Size);
}

void VideoH264DecSetParam(OPEN_API_PARAM_TYPE_T rType, void *pParam, kal_uint32 u4Size)
{
    h264_dec_driver.set_param(rType, pParam, u4Size);
}

void VideoH264DecInterruptHdlr(void)
{
    h264_dec_driver.intr_hdlr();
}

/*
void VideoH264DecTimeoutReset(void)
{
    h264_dec_driver.timeout_recover();
}
*/

// Decode a nalu by nalu type
H264_DECODE_STATUS_CODE_T VideoH264DecNALu(VIDEO_DECODE_PARAM_T *prParam)
{
    MEDIA_STATUS_CODE rStatus;
    H264_NAL_unit rNALu;

    // If parse sps,pps error happened, we will always return error
    // Because the codec can't decode any more. The uppper layer need 
    // to close and re-open codec
    //
    if (fgDecodeSPSFailed == KAL_TRUE)
    {
        return H264_STATUS_SPS_ERROR;
    }

    if (!prParam)
    {
        dbg_print("[Open_API_H264]Input parameter error %d!\n\r", __LINE__);
        return H264_STATUS_ERROR;
    }

    rNALu.RBSP = (kal_uint8 *)prParam->u4AddrOfNALu;
	  rNALu.forbidden_zero_bit = (rNALu.RBSP[0]>>7) & 1;
	  rNALu.nal_ref_idc = (rNALu.RBSP[0]>>5) & 3;
	  rNALu.nal_unit_type = (rNALu.RBSP[0]) & 0x1f;
	  rNALu.SODB = rNALu.RBSP + 1;
    rNALu.NumBytesInNALunit = prParam->u4LengthOfNALu;        

    video_dbg_trace(H264_DEC_NAL_TYPE, rNALu.nal_unit_type);

    drv_trace4(TRACE_GROUP_10,OPEN_API_ENTERVIDEOH264DECNALU, prParam->u4AddrOfNALu,prParam->u4LengthOfNALu,rNALu.nal_ref_idc,rNALu.nal_unit_type);

    emuSize = 0;

    if (rNALu.nal_unit_type == 1 || rNALu.nal_unit_type == 5)
    {
        if (fgHasParsedSPS == KAL_FALSE || fgHasParsedPPS == KAL_FALSE)
        {
            fgDecodeSPSFailed = KAL_TRUE;
            return H264_STATUS_SPS_ERROR;
        }
    }
    

    if (g_open_api_h264_dec_info_ptr->b_pipeline_support)
    {
        if (prParam->pReseved != NULL)
        {
            if(g_open_api_h264_dec_info_ptr->bitstream_addr)
            {
                drv_trace1(TRACE_GROUP_10,OPEN_API_RETURNBSBUFFER,g_open_api_h264_dec_info_ptr->bitstream_addr);
                g_open_api_h264_dec_info_ptr->pfnReturnBsBufferCallback(g_open_api_h264_dec_info_ptr->bitstream_addr);
            }
            g_open_api_h264_dec_info_ptr->bitstream_addr = (kal_uint32)prParam->pReseved;    
        }
        else if ((g_open_api_h264_dec_info_ptr->dec_param.all_slice[0].b_used == KAL_FALSE) && (fgSliceError == KAL_TRUE))
        {
            //whole frame error, return bitstream
            if(g_open_api_h264_dec_info_ptr->bitstream_addr)
            {
                drv_trace1(TRACE_GROUP_10,OPEN_API_RETURNBSBUFFER,g_open_api_h264_dec_info_ptr->bitstream_addr);
                g_open_api_h264_dec_info_ptr->pfnReturnBsBufferCallback(g_open_api_h264_dec_info_ptr->bitstream_addr);
                g_open_api_h264_dec_info_ptr->bitstream_addr = NULL;
                fgSliceError = KAL_FALSE;
            }
        }     
    }
    if( fgDecodingDone )
    {
        if(g_open_api_h264_dec_info_ptr->decoded_bitstream_addr)
        {
            drv_trace1(TRACE_GROUP_10,OPEN_API_RETURNBSBUFFER,g_open_api_h264_dec_info_ptr->bitstream_addr);
            g_open_api_h264_dec_info_ptr->pfnReturnBsBufferCallback(g_open_api_h264_dec_info_ptr->decoded_bitstream_addr);
        }
        g_open_api_h264_dec_info_ptr->decoded_bitstream_addr=NULL;
    }
    if  ( (rNALu.nal_unit_type == 7 && (u4MaxSPSLen > 0) && rNALu.NumBytesInNALunit > (u4MaxSPSLen << 1)) 
       || (rNALu.nal_unit_type == 8 && (u4MaxPPSLen > 0) && rNALu.NumBytesInNALunit > (u4MaxPPSLen << 1)) )
    {
        return H264_STATUS_ERROR;
    }

    fgParameterError=KAL_FALSE;
	  rStatus = naluTypeFunc[rNALu.nal_unit_type](&rNALu);
	  _VideoH264SetLastNALuStatus(&rNALu, &lastStatus);

    if (g_open_api_h264_dec_info_ptr->b_pipeline_support)
    {
        //delimiter & AU boundary
        if ((prParam->pReseved == NULL) && (KAL_TRUE == fgTriggerHWDecode))
        {
            //no hw decoding, return bitstream
            if (fgRealTriggerHW == KAL_FALSE)
            {
                if(g_open_api_h264_dec_info_ptr->bitstream_addr)
                {
                    drv_trace1(TRACE_GROUP_10,OPEN_API_RETURNBSBUFFER,g_open_api_h264_dec_info_ptr->bitstream_addr);
                    g_open_api_h264_dec_info_ptr->pfnReturnBsBufferCallback(g_open_api_h264_dec_info_ptr->bitstream_addr);
                    g_open_api_h264_dec_info_ptr->bitstream_addr=NULL;
                }
            }
        }
    }

    // Decide decode result
    //
    if (KAL_TRUE == fgTriggerHWDecode)
    {
        fgTriggerHWDecode = KAL_FALSE;
        return H264_STATUS_DECODE_OK;
    }
    else
    {
        if (rStatus == MEDIA_STATUS_OK)
        {
            return H264_STATUS_OK;
        }
        else
        {
            // There something wrong here.
            // If this is sps&pps parse error,
            // the codec can't decode any more dut to header error
            // 
            if (rNALu.nal_unit_type == 7 || rNALu.nal_unit_type == 8)
            {
                // fgDecodeSPSFailed will be clear if init_global_vars()
                // It means we need close and re-open codec.
                fgDecodeSPSFailed = KAL_TRUE;
                if(rNALu.nal_unit_type == 7 && last_parsed_sps_id>0)
                    g_open_api_h264_dec_info_ptr->dec_param.all_sps[last_parsed_sps_id].b_used=KAL_FALSE;
                if(rNALu.nal_unit_type == 8 && last_parsed_pps_id>0)
                    g_open_api_h264_dec_info_ptr->dec_param.all_pps[last_parsed_pps_id].b_used=KAL_FALSE;
                //return H264_STATUS_SPS_ERROR;
                return H264_STATUS_ERROR;
            }
            else
            {
                if(fgParameterError)
                    return H264_STATUS_SPS_ERROR;
                return H264_STATUS_ERROR;
            }
        }
    }

        
}


void VideoH264PipelineSupport(void)
{
    g_open_api_h264_dec_info_ptr->b_pipeline_support = KAL_TRUE;
}

void VideoH264SetRealDPBSize(kal_uint32 u4DPBSize)
{
    g_open_api_h264_dec_info_ptr->system_dpb_size = u4DPBSize;
}

static void init_global_vars(void)
{
	kal_int32 i;

    kal_mem_set(&nalu_slice, 0, sizeof(H264_NAL_unit));
    kal_mem_set(&slice_temp, 0, sizeof(H264_slice_info));
    kal_mem_set(&temp_v, 0, sizeof(vui_seq_parameters_t));
    kal_mem_set(&lastStatus, 0, sizeof(lastStatus_t));

	picCnt = 0;
	//CurrPicNum = 0;	//frame_num of current slice
	lastStatus.isIDR = 0;
	lastStatus.nal_unit_type = maxBYTE;
	lastStatus.frame_num = maxUINT;
	lastStatus.spsID = maxBYTE;
	lastStatus.ppsID = maxBYTE;

	emuModifyPos = 0;
	emuSize = 0;

    fgTriggerHWDecode = KAL_FALSE;
    fgDecodeSPSFailed = KAL_FALSE;
    fgHasParsedSPS = KAL_FALSE;
    fgHasParsedPPS = KAL_FALSE;
    u4MaxSPSLen = 0;
    u4MaxPPSLen = 0;

    fgRealTriggerHW = KAL_FALSE;

	g_open_api_h264_dec_info_ptr->dec_param.active_sps_id = maxUINT;
	g_open_api_h264_dec_info_ptr->dec_param.active_pps_id = maxUINT;
	currSliceID = 0;
	
	for (i = 0; i < H264_MAX_SPS_NUMBER; i++) 
	{
		g_open_api_h264_dec_info_ptr->dec_param.all_sps[i].b_used = KAL_FALSE;
	}

	for (i = 0; i < H264_MAX_PPS_NUMBER; i++) 
	{
		g_open_api_h264_dec_info_ptr->dec_param.all_pps[i].b_used = KAL_FALSE;
	}

	for (i = 0; i < H264_MAX_SPS_NUMBER; i++) 
	{
		g_open_api_h264_dec_info_ptr->dec_param.all_slice[i].b_used = KAL_FALSE;
	}
	
	naluTypeFunc[0] = dummy_nalu_type;//error1;
	naluTypeFunc[1] = slice_layer_without_partitioning_rbsp;
	naluTypeFunc[2] = dummy_nalu_type;//error1;
	naluTypeFunc[3] = dummy_nalu_type;//error1;
	naluTypeFunc[4] = dummy_nalu_type;//error1;
	naluTypeFunc[5] = slice_layer_without_partitioning_rbsp;
	naluTypeFunc[6] = dummy_nalu_type;
	naluTypeFunc[7] = seq_parameter_set_rbsp;
	naluTypeFunc[8] = pic_parameter_set_rbsp;
	naluTypeFunc[9] = _VideoH264AccessUnitDelimiterRBSP;
	naluTypeFunc[10] = _VideoH264EndOfSeqRBSP;
	naluTypeFunc[11] = _VideoH264EndOfStreamRBSP;
	naluTypeFunc[12] = _VideoH264FillerDataRBSP;
	naluTypeFunc[12] = dummy_nalu_type;
	naluTypeFunc[13] = _VideoH264SeqParameterSetExtensionRBSP;
	naluTypeFunc[14] = _VideoH264HandleAccessUnitBoundary;
	naluTypeFunc[15] = _VideoH264HandleAccessUnitBoundary;
	naluTypeFunc[16] = _VideoH264HandleAccessUnitBoundary;
	naluTypeFunc[17] = _VideoH264HandleAccessUnitBoundary;
	naluTypeFunc[18] = _VideoH264HandleAccessUnitBoundary;
	naluTypeFunc[19] = slice_layer_without_partitioning_rbsp;

	naluTypeFunc[20] = dummy_nalu_type;
	naluTypeFunc[21] = dummy_nalu_type;
	naluTypeFunc[22] = dummy_nalu_type;
	naluTypeFunc[23] = dummy_nalu_type;
	naluTypeFunc[24] = dummy_nalu_type;
	naluTypeFunc[25] = dummy_nalu_type;
	naluTypeFunc[26] = dummy_nalu_type;
	naluTypeFunc[27] = dummy_nalu_type;
	naluTypeFunc[28] = dummy_nalu_type;
	naluTypeFunc[29] = dummy_nalu_type;
	naluTypeFunc[30] = dummy_nalu_type;
	naluTypeFunc[31] = dummy_nalu_type;
}

/*******************************************************************************
*   Address maping
*******************************************************************************/

static kal_uint32 video_p2v_addr(kal_uint32 p_addr)
{
    return p_addr;
}

static kal_uint32 video_v2p_addr(kal_uint32 v_addr)
{
    return v_addr;
}

/*******************************************************************************
*   IRQ related
*******************************************************************************/

kal_hisrid rVideoH264DecHisrhdlr = NULL;

void VideoH264DecHISR(void)
{
    video_dbg_trace(H264_DEC_HISR, video_get_current_time());
    VideoH264DecInterruptHdlr();
    IRQUnmask(IRQ_H264_CODE);
}

void VideoH264DecLISR(void)
{
    video_dbg_trace(H264_DEC_LISR, video_get_current_time());
    IRQMask(IRQ_H264_CODE);
    //kal_activate_hisr(rVideoH264DecHisrhdlr);
    visual_active_hisr(VISUAL_H264_DEC_HISR_ID);
}

void VideoH264InitIntr(void)
{
    video_dbg_trace(INIT_H264_SYSTEM, video_get_current_time());
    if (rVideoH264DecHisrhdlr == NULL)
    {
        #if defined(__KAL_OLD_HISR_API__)
        rVideoH264DecHisrhdlr = kal_create_hisr("H264DecHISR",1,1024,VideoH264DecHISR,NULL);
        #else /*__KAL_OLD_HISR_API__*/
        //rVideoH264DecHisrhdlr = kal_init_hisr(H264DecHISR);
        VISUAL_Register_HISR(VISUAL_H264_DEC_HISR_ID,VideoH264DecHISR);
        #endif /*__KAL_OLD_HISR_API__*/
        
    }
    IRQ_Register_LISR(IRQ_H264_CODE, VideoH264DecLISR, "H264Dec");
    IRQSensitivity(IRQ_H264_CODE, LEVEL_SENSITIVE);
    IRQUnmask(IRQ_H264_CODE);
}

//GPT time out handler
static void _VideoH264TimeOut(void *p)
{
    if(fgDecodingDone)return;
    //GPTI_StopItem(g_H264GPTHandle);
    DclSGPT_Control(g_H264GPTHandle,SGPT_CMD_STOP,0);
    h264_dec_timeout_recover();
}
#endif /*#ifdef __VE_H264_HW_OPEN_API_SUPPORT__*/
