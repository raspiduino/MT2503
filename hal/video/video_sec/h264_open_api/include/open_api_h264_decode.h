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
 *    open_api_h264_decode.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file defines H.264 control structure.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _H264_DECODE_H_
#define _H264_DECODE_H_

#define __H264_SLICEMAP_DEBUG__
#define __H264_DUMMY_B_SLICE_SUPPORT__
#define _H264_NEW_GMC_SETTING

#define EVENT_H264_DEC_DONE					((kal_uint32)0x00000001)
#define EVENT_H264_DEC_ERR           				((kal_uint32)0x00000002)
#define EVENT_H264_DMA_DONE         				((kal_uint32)0x00000004)

#define maxBYTE				0xff
#define maxUINT				0xffffffff
#define maxINT				0x7FFFFFFF	// 2^31-1

#define VIDEO_MAX(a,b)                 ( ((a)>(b))? a : b )
#define VIDEO_MIN(a,b)                 ( ((a)<(b))? a : b )

#define Buffer_WRITE(ptr,data)       (*(ptr) = (data))
#define Buffer_READ(ptr)             (*(ptr))         

#include "drv_features_video.h"
#if defined (__VE_VIDEO_ARCHI_V2__) 
#define VIDEO_ASSERT(_condition)    do{}while(0);
#define video_assert(_condition)    do{}while(0);
#define video_dbg_trace(a,b)    do{}while(0);
#endif

/*******************************************************************************
*   Private definition
*******************************************************************************/

#define H264_MAX_FRAME_SIZE     H264_MAX_FRAME_WIDTH*H264_MAX_FRAME_HEIGHT
//Allowed maximum frame size (W*H)
#define H264_MAX_FRAME_WIDTH    720
#define H264_MAX_FRAME_HEIGHT   480

// H264 working buffer size 
#define H264_MC_LINE_BUFFER_SIZE(_FRAME_WIDTH)          (((_FRAME_WIDTH+15)/16)*16*48*3/2) 
#define H264_MC_MV_BUFFER_SIZE                          3328
#define H264_CAVLC_BUFFER_SIZE                          520
#define H264_DEB_BUFFER_SIZE(_FRAME_WIDTH)              (((_FRAME_WIDTH+15)/16*8+8)*16)
#define H264_DEB_DATA_BUFFER0_SIZE                      512
#define H264_DEB_DATA_BUFFER1_SIZE                      512
#define H264_DEB_DATA_BUFFER01_SIZE                     (H264_DEB_DATA_BUFFER0_SIZE + H264_DEB_DATA_BUFFER1_SIZE)
// Maximum working memory for H264 hardware engine.
#define H264_MAX_WORK_MEMORY(_FRAME_WIDTH,_FRAME_HEIGHT)    (H264_MC_LINE_BUFFER_SIZE(_FRAME_WIDTH) + 16 + H264_MC_MV_BUFFER_SIZE + 16 + \
                                                                                                            H264_CAVLC_BUFFER_SIZE + H264_DEB_BUFFER_SIZE(_FRAME_WIDTH) + \
                                                                                                            H264_DEB_DATA_BUFFER0_SIZE + H264_DEB_DATA_BUFFER1_SIZE + 512+1500)
//DPB(level3) and frame buffer size
#define H264_MAX_FRAME_BUFFER_SIZE(_DPB_SIZE,_FRAME_SIZE)     (_DPB_SIZE + _FRAME_SIZE*3)
//Slice map struct size
#define H264_SLICE_MAP_STRUCT_SIZE(_FRAME_HEIGHT)   ((1024/16)*(_FRAME_HEIGHT/16)*2) 
//Slice conf struct size
#define H264_SLICE_CONF_STRUCT_SIZE(_FRAME_SIZE)   ((_FRAME_SIZE/16/16)*32) 
//Reference frame struct size
#define H264_REF_FRAME_STRUCT_SIZE  (64)
// Total HW buffer memory size
#define H264_HW_BUFFER_REGISTER_SIZE        0x50

#define H264_DEC_PLAYER_DPB_MAX_SIZE 3110400

// spec defined numbers
#define H264_MAX_REF_FRAMES_IN_PIC_ORDER_CNT_CYCLE  256
#define H264_MAX_SLICE_GROUP  8  // constraint for Baseline profile in Annex A
#define H264_MAX_REF_ENTRY 16
#define H264_MAX_DPB_ENTRY 16
#define H264_MAX_SPS_NUMBER 32
#define H264_MAX_PPS_NUMBER 256
#define H264_MAX_SLICE_NUMBER  (H264_MAX_FRAME_SIZE/16/16)
#define H264_MAX_MB_NUMBER  (H264_MAX_FRAME_SIZE/16/16)
#define H264_BASELINE_PROFILE_IDC  66

#define H264_MAX_SLICE_CMD_MEM_SIZE  4*1024

#define H264_AVC_FILE_CONFIG_DATA_LENGTH  5

// error concealment size
#define H264_ERROR_CONCEAL_MAX_WIDTH  320
#define H264_ERROR_CONCEAL_MIN_WIDTH  320
#define H264_ERROR_CONCEAL_MAX_HEIGHT 240
#define H264_ERROR_CONCEAL_MIN_HEIGHT 240

/*******************************************************************************
*   Private Structures
*******************************************************************************/

// H264 NAL unit
typedef struct 
{	
    kal_int32   forbidden_zero_bit;
    kal_int32   nal_ref_idc;
    kal_int32   nal_unit_type;
    kal_uint32  NumBytesInNALunit;

    kal_uint8   *RBSP;
    kal_uint8   *SODB;

} H264_NAL_unit;

//H264 NALU type
typedef enum 
{
    H264_unspecified,
    H264_sliceOfnonIDR,
    H264_sliceDPA,
    H264_sliceDPB,
    H264_sliceDPC,
    H264_sliceOfIDR,
    H264_SEI_rbsp,
    H264_SPS_rbsp,
    H264_PPS_rbsp,
    H264_AUDelimiter,
    H264_endOfSeq,
    H264_endOfStream,
    H264_fillerData,
    H264_SPSext_rbsp,
    H264_reserved14,
    H264_reserved15,
    H264_reserved16,
    H264_reserved17,
    H264_reserved18,
    H264_sliceOfAuxPic_rbsp
} H264_nalu_type;

// H264 slice type
typedef enum
{
    H264_slice_typeP,
    H264_slice_typeB,
    H264_slice_typeI,
    H264_slice_typeSP,
    H264_slice_typeSI,
    H264_slice_typeP2,
    H264_slice_typeB2,
    H264_slice_typeI2,
    H264_slice_typeSP2,
    H264_slice_typeSI2
} H264_slice_type;

//H264 work memory type
typedef enum
{
    H264_WORK_MEM_MC_LINE,
    H264_WORK_MEM_MC_MV,
    H264_WORK_MEM_CAVLC,
    H264_WORK_MEM_DBK01,
    H264_WORK_MEM_DBK,
    H264_WORK_MEM_MAX
}H264_WORK_MEM_TYPE;

// H264 work memory informaiton
typedef struct
{
    H264_WORK_MEM_TYPE type;
    kal_uint32 align;
    kal_uint32 size;
    kal_bool b_assigned;
}H264_work_mem_info;

// H264 picture reorder command
typedef struct H264_reorder_cmd 
{	
    kal_uint32 	reordering_of_pic_nums_idc;				// ue(v)
    kal_uint32 	abs_diff_pic_num_minus1;				// ue(v)
    kal_uint32 	long_term_pic_num;						// ue(v)
    struct H264_reorder_cmd		*nextCmd;
}H264_ref_pic_reorder_cmd;

// H264 picture marking command
typedef struct H264_pic_marking 
{
    kal_uint32	memory_management_control_operation;	// ue(v)
    kal_uint32	difference_of_pic_nums_minus1;			// ue(v)
    kal_uint32	long_term_pic_num;						// ue(v)
    kal_uint32	long_term_frame_idx;					// ue(v)
    kal_uint32	max_long_term_frame_idx_plus1;			// ue(v)
    struct H264_pic_marking		*nextCmd;
} H264_ref_pic_marking;

// H264 reference picture entry information
typedef struct 
{
    kal_int32  index_to_DPB;
    kal_int32  num;
} H264_ref_pic_entry;

// H264 RPE type 
typedef enum
{
    H264_rpe_short_term,
    H264_rpe_long_term
}H264_rpe_status;

// H264 reference type
typedef enum 
{
    H264_shortterm_ref,
    H264_longterm_ref,
    H264_unused_ref,
    H264_non_existing
} H264_ref_pic_status;

// H264 reference picture list information
typedef struct 
{
    kal_int32  num_STR_used;
    kal_int32  num_LTR_used;
    kal_int32  max_longterm_frame_idx;
    kal_int32  longterm_frame_idx;
    kal_int32  num_ref_frames;
    H264_rpe_status  rpeStatus[H264_MAX_REF_ENTRY];	
    H264_rpe_status  rpeStatus_temp[H264_MAX_REF_ENTRY];
    H264_rpe_status  rpeStatus_temp_reorder[H264_MAX_REF_ENTRY];	
    H264_ref_pic_entry  strpe[H264_MAX_REF_ENTRY];
    H264_ref_pic_entry  ltrpe[H264_MAX_REF_ENTRY];
    H264_ref_pic_entry  *rpe[H264_MAX_REF_ENTRY];
    H264_ref_pic_entry  *rpe_temp[H264_MAX_REF_ENTRY];
    H264_ref_pic_entry  *rpe_temp_reorder[H264_MAX_REF_ENTRY];
}H264_ref_pic_list;

// H264 DPB information
typedef struct 
{
    kal_bool b_used;
    kal_uint32 index;
    kal_uint32 index_to_list;    // index to frame list
    kal_int32  status_marked;
    kal_int32  pic_num;			   // picNum = frame_num for Baseline
    kal_uint32  frame_no;		  // Scott, used only for debugging
    kal_int32  top_POC;			  // top POC
    kal_int32  bottom_POC;		  // bottom POC
    kal_int32  POC;			        // POC = min(topFOC, bottomFOC);
    kal_bool b_dec_done;
    #ifdef __H264_DUMMY_B_SLICE_SUPPORT__
    kal_bool B_slice_exists;
    #endif
    kal_bool is_corrupted;
    kal_int32 isOutputed;		// -1 : default, 0: stored in the DPB, need to output; 1: no needed for output.
    
    kal_uint8  *mem_addr;
} H264_DPB_entry;

// H264 DPB list information
typedef struct 
{
	H264_DPB_entry  dpbe[H264_MAX_DPB_ENTRY+1];
	kal_int32            num_used;
	kal_int32            last_POC;	// POC of last frame outputed
	kal_uint8           *p_buffer;
	kal_uint32          wait_for_free;
} H264_DPB_list;	// Decoded Picture Buffer

typedef struct H264_frame_entry
{
    kal_uint32 addr;
    kal_uint32 length;
    //kal_uint32 time; //unit: AV interrupt	
    kal_uint32 frame_no; //in decoding order, will be used in video seek
    //kal_bool b_dec_done;
    kal_bool b_used;
    kal_uint32 index; //index to frame_list
    kal_uint32 index_to_entry;
    struct H264_frame_entry *p_next_dpb;
    struct H264_frame_entry *p_prev_dpb;
    H264_DPB_entry *p_dpb;
}H264_dpb_frame_entry;

typedef struct
{
    kal_uint32 max_queue_num;
    H264_dpb_frame_entry *p_start;
    H264_dpb_frame_entry *p_end;
    H264_dpb_frame_entry *p_next_parse;
    // list entry may be used once display time is up but previous decode is not done
    // so list entry should be more than real dpb entry
    H264_dpb_frame_entry  frame_list[H264_MAX_DPB_ENTRY*2];
    H264_DPB_entry *p_dpb_decode;
    H264_DPB_entry *p_prev_display;
    kal_uint64 display_time;
    kal_uint64 prev_display_time;

     H264_DPB_entry *p_lastest_display;//The final displayed frame.
    kal_uint64 lastest_display_time;   

    //#ifdef __DRV_STREAM_SUPPORT__
    kal_uint32 last_IDR_no; //Record the first IDR as the first display frame. Used in MTV
    //#endif
}H264_dpb_frame_info;


// H264 SPS information
typedef struct 
{
    kal_bool   b_used;
    kal_uint8  profile_idc;					// u(8)
    kal_uint8  constraint_set0_flag;			// u(1)
    kal_uint8  constraint_set1_flag;			// u(1)
    kal_uint8  constraint_set2_flag;			// u(1)
    kal_uint8  constraint_set3_flag;			// u(1)
    kal_uint8  level_idc;					// u(8)
    kal_uint8  seq_parameter_set_id;		// ue(v)

    kal_uint8  chroma_format_idc;						// ue(v), 4:2:0
    kal_uint8  residual_colour_transform_flag;			// u(1), residual color transform not applied.
    kal_uint8  bit_depth_luma_minus8;					// ue(v)
    kal_uint8  bit_depth_chroma_minus8;				// ue(v)
    kal_uint8  qpprime_y_zero_transform_bypass_flag;	// u(1)
    kal_uint8  seq_scaling_matrix_present_flag;			// u(1)
    kal_uint8  log2_max_frame_num_minus4;			// ue(v)
    kal_uint8  pic_order_cnt_type;						// ue(v)
    kal_uint8  log2_max_pic_order_cnt_lsb_minus4;		// ue(v)
    kal_uint8  num_ref_frames;							// ue(v)
    kal_uint8  gaps_in_frame_num_value_allowed_flag;	// u(1)
    kal_uint16  pic_width_in_mbs_minus1;				// ue(v)
    kal_uint16  pic_height_in_map_units_minus1;			// ue(v)
    kal_uint8  frame_mbs_only_flag;						// u(1)
    kal_uint8  mb_adaptive_frame_field_flag;				// u(1)
    kal_uint8  direct_8x8_inference_flag;					// u(1)
    kal_uint8  frame_cropping_flag;						// u(1)
    kal_uint8  vui_parameters_present_flag;				// u(1)

    kal_uint32  delta_pic_order_always_zero_flag;		// u(1)
    kal_int32    offset_for_non_ref_pic;					// se(v)
    kal_int32    offset_for_top_to_bottom_field;			// se(v)
    kal_uint32  num_ref_frames_in_pic_order_cnt_cycle;	// ue(v)
    kal_int32    offset_for_ref_frame[H264_MAX_REF_FRAMES_IN_PIC_ORDER_CNT_CYCLE];  // se(v)
    kal_uint32  frame_crop_left_offset;					// ue(v)
    kal_uint32  frame_crop_right_offset;					// ue(v)
    kal_uint32  frame_crop_top_offset;					// ue(v)
    kal_uint32  frame_crop_bottom_offset;				// ue(v)
} H264_sps_info;

// H264 PPS information
typedef struct 
{
    kal_bool   b_used;
    kal_uint8  pic_parameter_set_id;					// ue(v);
    kal_uint8  seq_parameter_set_id;					// ue(v);
    kal_uint8  entropy_coding_mode_flag;				// u(1);
    kal_uint8  pic_order_present_flag;					// u(1);
    kal_uint8  num_slice_groups_minus1;				// ue(v);
    kal_uint8  slice_group_map_type;					// ue(v);
    kal_uint8  slice_group_change_direction_flag;			// u(1);
    kal_uint8  slice_group_id[H264_MAX_MB_NUMBER];		// u(v);
    kal_uint8  num_ref_idx_l0_active_minus1;			// ue(v);
    kal_uint8  num_ref_idx_l1_active_minus1;			// ue(v);
    kal_uint8  weighted_pred_flag;						// u(1);
    kal_uint8  weighted_bipred_idc;						// u(2);
    kal_uint8  deblocking_filter_control_present_flag;		// u(1);
    kal_uint8  constrained_intra_pred_flag;				// u(1);
    kal_uint8  redundant_pic_cnt_present_flag;			// u(1);
    kal_uint8  transform_8x8_mode_flag;				// u(1);
    kal_uint8  pic_scaling_matrix_present_flag;			// u(1);
    kal_uint32	run_length_minus1[H264_MAX_SLICE_GROUP];// ue(v);
    kal_uint32 	top_left[H264_MAX_SLICE_GROUP];			 // ue(v);
    kal_uint32 	bottom_right[H264_MAX_SLICE_GROUP];		 // ue(v);
    kal_uint32 	slice_group_change_rate_minus1;		    // ue(v);
    kal_uint32 	pic_size_in_map_units_minus1;		    // ue(v);
    kal_int32   pic_init_qp_minus26;					    // se(v);
    kal_int32   pic_init_qs_minus26;					    // se(v);
    kal_int32   chroma_qp_index_offset;				    // se(v);
    kal_int32   second_chroma_qp_index_offset;		    // se(v);
} H264_pps_info;

// H264 Slice information
typedef struct 
{
    kal_bool   b_used;
    kal_uint8  slice_type;								// ue(v)
    kal_uint8  pic_parameter_set_id;					// ue(v)
    kal_uint8  field_pic_flag;							// u(1)
    kal_uint8  bottom_field_flag;						// u(1)
    kal_uint8  redundant_pic_cnt;						// ue(v)
    kal_uint8  num_ref_idx_active_override_flag;		      // u(1)
    kal_uint8  num_ref_idx_l0_active_minus1;			// ue(v)
    kal_uint32 	first_mb_in_slice;						// ue(v)	
    kal_uint32 	frame_num;								// u(v)
    kal_bool    b_nal_ref_idc;
    kal_bool    b_idr;
    kal_uint32 	idr_pic_id;								// ue(v)
    kal_uint32 	pic_order_cnt_lsb;						// u(v)
    kal_int32  delta_pic_order_cnt_bottom;				// se(v)
    kal_int32  delta_pic_order_cnt[2];					// se(v)

    // The following section is for ref_pic_list_reordering()	
    kal_uint8  ref_pic_list_reordering_flag_l0;	                    // u(1)
    H264_ref_pic_reorder_cmd  *ref_pic_reorder_cmd;

    // The following section is for dec_ref_pic_marking()
    kal_uint8  no_output_of_prior_pics_flag;				// u(1)
    kal_uint8  long_term_reference_flag;					// u(1)
    kal_uint8  adaptive_ref_pic_marking_mode_flag;		// u(1)
    H264_ref_pic_marking   *ref_pic_marking;

    kal_uint32   disable_deblocking_filter_idc;				// ue(v)	
    kal_uint32 slice_group_change_cycle;				// u(v)
    kal_uint8   *slice_data;								// point to a memory address within CPB (after slice header)
    kal_uint8   slice_data_bit_offset;						// bit offset for slice_data
    kal_uint32  slice_start_addr;
    kal_uint32 slice_length;
      
    kal_int32   slice_qp_delta;							// se(v)

    kal_int32   slice_alpha_c0_offset_div2;				// se(v)
    kal_int32   slice_beta_offset_div2;					// se(v)

    // reference list parameters
    kal_uint64 ref_frame_index_list;
    //unsigned long long ref_frame_index_list;
    kal_bool    b_recInd;
    kal_uint32 index_recInd;
} H264_slice_info;

// H264 decoder related information
// these information is obtained from bitstream parser 
typedef struct
{
    // variables updated when a SPS is active.
    kal_int8     bit_depth_Y;               // = 8 + bit_depth_luma_minus8
    kal_int32   qp_bd_offset_Y;          // = 6 * bit_depth_luma_minus8
    kal_int8     bit_depth_C;               // = 8 + bit_depth_chroma_minus8
    kal_uint32  qp_bd_offset_C;         // = 6 * ( bit_depth_chroma_minus8 + residual_colour_transform_flag )
    kal_uint32  raw_Mb_bits;             // = 256 * BitDepthY + 2 * MbWidthC * MbHeightC * BitDepthC
    kal_int8     flat_4x4_16[16];         // = 16, with i = 0..15  (Todo: not so clear, see p78)
    kal_int8     flat_8x8_16[64];         // = 16, with i = 0..63
    kal_uint32  max_dpb_size;
    kal_uint32  max_DPB_number;          // Specified in A.3.1 or A.3.2
    kal_uint32  max_frame_num;      // = 2^(log2_max_frame_num_minus4+4)
    kal_uint32  max_pic_order_cnt_lsb;   // = 2^(log2_max_pic_order_cnt_lsb_minus4+4)
    kal_uint32  pic_width_in_mbs;           // = pic_width_in_mbs_minus1 + 1
    kal_uint32  pic_width_in_samples_L; // = PicWidthInMbs * 16
    kal_uint32  pic_width_in_samples_C; // = PicWidthInMbs * MbWidthC
    kal_uint32  pic_height_in_map_units; // = pic_height_in_map_units_minus1 + 1
    kal_uint32  frame_height_in_mbs;     // = (2 - frame_mbs_only_flag) * PicHeightInMapUnits
    kal_uint32  pic_size_in_map_nits;      // = PicWidthInMbs * PicHeightInMapUnits
    kal_int8     sub_width_C;                   // SubWidthC and SubHeightC are from Table 6-1
    kal_int8     sub_height_C;
    kal_int8     mb_width_C;                   // = 16 / SubWidthC
    kal_int8     mb_height_C;                  // = 16 / SubHeightC
    kal_int8     crop_unit_X;                    // the values of CropUnitX and CropUnitY depends on chroma_format_idc
    kal_int8     crop_unit_Y;      

    // variables updated when a slice
    kal_int8     mbaff_frame_flag; 
    kal_int8     prev_ppsID;
    kal_bool     prev_ref_pic_has_MMCO5;
    kal_uint32  pic_size_in_mbs;
    kal_uint32  prev_ref_frame_num;
    kal_uint32  pic_height_in_mbs;
    kal_uint32  pic_height_in_samples_L;
    kal_uint32  pic_height_in_samples_C;
    kal_uint32  max_pic_num;
    kal_uint32  curr_pic_num;
    kal_int32    frame_num_offset;
    kal_int32    pic_order_cnt_msb;
    kal_int32    prev_pic_order_cnt_msb;
    kal_int32    prev_pic_order_cnt_lsb;
    kal_int32    prev_frame_num_offset;
    kal_bool     prev_pic_has_MMCO5;
    kal_int32    prev_frame_num;
    kal_int32    prev_ref_pic_oder_cnt_msb;
    kal_int32    prev_ref_pic_oder_cnt_lsb;

    kal_int32 top_field_order_cnt;
    kal_int32 bottom_field_order_cnt;
    kal_int32 picture_order_cnt;
    kal_bool  cur_pic_has_MMCO5;
    H264_sps_info all_sps[H264_MAX_SPS_NUMBER];
    H264_pps_info all_pps[H264_MAX_PPS_NUMBER];
    H264_slice_info all_slice[H264_MAX_SLICE_NUMBER];
    kal_uint32 active_sps_id;
    kal_uint32 active_pps_id;
    kal_uint32 total_slice_num;
    kal_uint32 slice_order[H264_MAX_SLICE_NUMBER];
    kal_uint8 slice_cmd_memory[H264_MAX_SLICE_CMD_MEM_SIZE];   
    kal_uint32 slice_cmd_mem_index; 

    #ifdef __H264_DUMMY_B_SLICE_SUPPORT__
    /*Scott, We use this flag to identify if B-Slice exists in current frame*/
    kal_bool B_slice_exists;
    #endif

    H264_ref_pic_list ref_pic_list0;
    H264_DPB_list  *p_DPB_list;
    H264_DPB_entry *p_curr_dpb;
    kal_uint32 non_ref_DPB_index;
    kal_uint32 num_DPB_entry;
    kal_uint32 num_ref_frames;

    kal_uint32  num_slices;
    kal_uint32  current_slice_id;

    kal_uint32  slice_total_length; //used to config H264_DEC_DMA_LIMIT Register
    //kal_bool     b_dma_limit_check;
    kal_uint8    frame_type;
    kal_bool     b_ref_curr_frame;
    kal_int32    last_ref_index_to_DPB;    
    
    kal_uint8 	*emu_check_pos; 
    kal_uint8    *emu_end_pos;
    kal_uint8    *emu_pos_1;
    kal_uint8    *emu_pos_2;
    kal_uint32	 emu_modify_pos;
} H264_dec_param;

// H264 parameter set information
typedef struct
{
    kal_uint32 data_addr;
    kal_uint32 size;
    kal_uint32 active_point;  // in case parameter set is carried in another elementary stream but not in file header
}H264_parameter_set;

// H264 decoder parameters
typedef struct
{
    kal_uint8 *int_mem_p_addr;
    kal_uint32 int_mem_size;
    kal_uint8 *ext_mem_p_addr;
    kal_uint32 ext_mem_size;
	
    kal_uint8 *working_memory;
    kal_uint32 working_memory_size;
    kal_uint8 *p_frame_buffer_memory;
    kal_uint8 *p_slice_group_memory;
    kal_uint8 *p_slice_map_memory;
    kal_uint8 *p_slice_conf_memory;
    kal_uint8 *p_ref_frame_memory;
    kal_uint32 frame_addr_offset;//used in update slice address offset

    // Callback function
    kal_bool b_pipeline_support;
    kal_uint32 bitstream_addr;
    kal_uint32 decoded_bitstream_addr;
    void (*pfnReturnBsBufferCallback)(kal_uint32 u4Address);
    void (*pfnSetFrameUnReferenceCallback)(kal_uint32 u4Address);
    void (*pfnOutputOneFrameCallback)(kal_uint32 u4Address, kal_bool fgCorruptedFrame);
    kal_uint32 (*pfnGetYUVBufferCallback)(void);
    kal_uint32 (*pfnVideoP2VAddrCallback)(kal_uint32 u4Address);
    kal_uint32 (*pfnVideoV2PAddrCallback)(kal_uint32 u4Address);

    // spec related parameters
    kal_bool b_parse_header;
    H264_dec_param  dec_param;
    H264_parameter_set parameter_set;
    kal_uint8 avc_config_data[H264_AVC_FILE_CONFIG_DATA_LENGTH];
    kal_uint32 nalu_length_size;
    
    kal_uint16 width;
    kal_uint16 height;
    kal_uint16 real_width;
    kal_uint16 real_height;	

    kal_uint16 crop_x0;
    kal_uint16 crop_x1;
    kal_uint16 crop_y0;
    kal_uint16 crop_y1;    

    /* frame numbers */	
    // Task prepare frame number.
    kal_uint32 prepare_frames_no;
    kal_uint32 hdr_add_frames_no;
    // Hisr decode frame number.
    kal_uint32 hdr_parse_frames_no;
    kal_uint32 hdr_display_frames_no;

    // set KAL_TRUE to send primitve to notify upper layer
    kal_bool isr_error_event_happen;

    // LISR decode frame number.
    kal_uint32 dec_frames_no;
    //kal_uint32 display_frame_no;

    //Rita temp solution, need to check with Scott
    kal_bool b_drop_display;
    kal_uint32 prev_drop_display_time;		
    
    kal_uint8 is_error_occur; //if error occurs, use this flag to pass guard time check in resume check.

    // for error copy
    kal_bool b_disable_prefetch;
    kal_bool b_dec_error;
    kal_bool b_dec_error_frame;
    kal_uint32 conceal_frame_no;
    kal_uint32 dec_error_mb_num;
    kal_uint8 *p_prev_dec_addr;
    kal_uint8 *p_curr_dec_addr;

    kal_uint32 timeout_value;
    kal_uint32 system_dpb_size;
} H264_dec_info;

//H264 enumulation code checking informaiton
typedef struct
{
    kal_uint8* start_addr;
    kal_uint32 index;
    kal_uint32 emu_match[128];
    kal_uint32 emu_index;
}H264_emulation_info; 

/* ISR file self checking parameters */
typedef struct
{
    kal_bool      b_check_reentry;
    kal_bool      b_check_av_error;
    kal_bool      check_vlc_addr;
    kal_bool      b_prev_error;
    kal_uint32   speed_recover_count;
}H264_DEC_ISR_PARAM;

#endif /*H264_DECODE_H*/
