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
 *    open_api_h264_driver.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file defines driver application dependence definition.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef _H264_DRIVER_H_
#define _H264_DRIVER_H_

//#define __DRV_VIDEO_H264_REG_DBG__
#ifdef __DRV_VIDEO_H264_REG_DBG__

#define OPEN_API_WriteReg(addr,data)    DRV_DBG_WriteReg(addr,data)
#define OPEN_API_Reg(addr)              DRV_DBG_Reg(addr)
#define OPEN_API_WriteReg32(addr,data)  DRV_DBG_WriteReg32(addr,data)
#define OPEN_API_Reg32(addr)            DRV_DBG_Reg32(addr)

#else //__DRV_VIDEO_REG_DBG__
#define OPEN_API_WriteReg(addr,data)    DRV_WriteReg(addr,data)
#define OPEN_API_Reg(addr)              DRV_Reg(addr)
#define OPEN_API_WriteReg32(addr,data)  DRV_WriteReg32(addr,data)
#define OPEN_API_Reg32(addr)            DRV_Reg32(addr)

#endif //__DRV_VIDEO_H264_REG_DBG__

typedef struct {
	kal_int8		nal_ref_idc;
	kal_uint8		nal_unit_type;
	kal_int8		field_pic_flag;
	kal_int8		bottom_field_flag;
	kal_int8		pic_order_cnt_type;
	kal_uint8		spsID;
	kal_uint8		ppsID;
	kal_int8		isIDR;
	kal_int8		isForRef;
	kal_uint32		NumBytesInNALunit;
	kal_uint32		frame_num;
	kal_uint32		idr_pic_id;
	kal_uint32		pic_order_cnt_lsb;
	kal_int32		prevRefPOClsb;
	kal_int32		prevRefPOCmsb;
	kal_int32		delta_pic_order_cnt_bottom;
	kal_int32		delta_pic_order_cnt[2];
	kal_int32		picCnt;
	kal_int32		recInd;
} lastStatus_t;	// incluing Pic, NALU status

typedef enum {
	Unspecified,
	sliceOfnonIDR_rbsp,
	sliceDPA,
	sliceDPB,
	sliceDPC,
	sliceOfIDR_rbsp,
	SEI_rbsp,
	SPS_rbsp,
	PPS_rbsp,
	AUDelimiter_rbsp,
	endOfSeq_rbsp,
	endOfStream_rbsp,
	fillerData_rbsp,
	SPSext_rbsp,
	Reserved14,
	Reserved15,
	Reserved16,
	Reserved17,
	Reserved18,
	sliceOfAuxPic_rbsp
} naluType;

typedef enum {
	MP4FileContainer,
	ByteStream
}FileFormatType;


typedef struct
{
	kal_uint8		bit_rate_scale;                           			// u(4)
	kal_uint8		cpb_size_scale;                           			// u(4)
    	kal_uint8		cbr_flag[H264_MAX_DPB_ENTRY];					// u(1)
	kal_uint8		initial_cpb_removal_delay_length_minus1;  	// u(5)
	kal_uint8		cpb_removal_delay_length_minus1;          	// u(5)
	kal_uint8		dpb_output_delay_length_minus1;           	// u(5)
	kal_uint8		time_offset_length;                       			// u(5)
	kal_uint32		cpb_cnt_minus1;                           			// ue(v)	
	kal_uint32		bit_rate_value_minus1 [H264_MAX_DPB_ENTRY]; 	// ue(v)
	kal_uint32		cpb_size_value_minus1 [H264_MAX_DPB_ENTRY]; 	// ue(v)
} hrd_parameters_t;

typedef struct
{
	kal_uint8			aspect_ratio_info_present_flag;		// u(1)
	kal_uint8			aspect_ratio_idc;                       		// u(8)
	kal_uint32			sar_width;                              			// u(16)
	kal_uint32			sar_height;                             			// u(16)
	kal_uint8			overscan_info_present_flag;            	// u(1)
	kal_uint8   			overscan_appropriate_flag;             	// u(1)
	kal_uint8   			video_signal_type_present_flag;         	// u(1)
	kal_uint8			video_format;                           		// u(3)
	kal_uint8			video_full_range_flag;                  		// u(1)
	kal_uint8			colour_description_present_flag;        	// u(1)
	kal_uint8			colour_primaries;                       		// u(8)
	kal_uint8			transfer_characteristics;               		// u(8)
	kal_uint8			matrix_coefficients;                    		// u(8)
	kal_uint8			chroma_location_info_present_flag;      	// u(1)
	kal_uint32			chroma_sample_loc_type_top_field;       // ue(v)
	kal_uint32			chroma_sample_loc_type_bottom_field;	// ue(v)
	kal_uint8			timing_info_present_flag;               		// u(1)
	kal_uint32			num_units_in_tick;                      		// u(32)
	kal_uint32			time_scale;                             			// u(32)
	kal_uint8			fixed_frame_rate_flag;                  		// u(1)
	kal_uint8			nal_hrd_parameters_present_flag;        // u(1)
	hrd_parameters_t	nal_hrd_parameters;                    		// hrd_paramters_t
	kal_uint8			vcl_hrd_parameters_present_flag;		// u(1)
	hrd_parameters_t	vcl_hrd_parameters;                    		// hrd_paramters_t
	// if ((nal_hrd_parameters_present_flag || (vcl_hrd_parameters_present_flag))
	kal_uint8			low_delay_hrd_flag;                     		// u(1)
	kal_uint8			pic_struct_present_flag;                		// u(1)
	kal_uint8			bitstream_restriction_flag;             		// u(1)
	kal_uint8			motion_vectors_over_pic_boundaries_flag;	// u(1)
	kal_uint32			max_bytes_per_pic_denom;                	// ue(v)
	kal_uint32			max_bits_per_mb_denom;                  	// ue(v)
	kal_uint32			log2_max_mv_length_vertical;            	// ue(v)
	kal_uint32			log2_max_mv_length_horizontal;          	// ue(v)
	kal_uint32			num_reorder_frames;                     	// ue(v)
	kal_uint32			max_dec_frame_buffering;                	// ue(v)
} vui_seq_parameters_t;

typedef struct
{
    MEDIA_STATUS_CODE (*init)(void *param);
    MEDIA_STATUS_CODE (*close)(void);
    kal_bool (*decode)(MEM_NODE_TYPE_T bitstream_addr, kal_uint32 bitstream_length, MEM_NODE_TYPE_T yuv_addr);
    void (*get_param)(OPEN_API_PARAM_TYPE_T rType, void *pParam, kal_uint32 u4Size);
    void (*set_param)(OPEN_API_PARAM_TYPE_T rType, void *pParam, kal_uint32 u4Size);
    void (*intr_hdlr)(void);
    void (*timeout_recover)(void);
}VIDEO_DEC_DRIVER_TYPE_T;

#endif /*H264_DECODE_H*/
