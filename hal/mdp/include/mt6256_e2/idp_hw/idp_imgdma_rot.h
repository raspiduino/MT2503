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
 *   idp_imgdma_rgbrot0.h
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 02 23 2012 chelun.tsai
 * removed!
 * .
 *
 * 02 16 2012 chelun.tsai
 * NULL
 * .
 *
 * 09 20 2011 chelun.tsai
 * removed!
 * .
 *
 * 08 04 2011 chelun.tsai
 * removed!
 * .
 *
 * 05 27 2011 chelun.tsai
 * removed!
 * MT6526 E2 MDP driver.
 *
 * 05 19 2011 chelun.tsai
 * removed!
 * camera capture ok.
 *
 * 05 15 2011 chelun.tsai
 * removed!
 * MT6256 E2 Video playback IT ok.
 *
 * 05 05 2011 chelun.tsai
 * removed!
 * last check in befor sample back.
 *
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_imgdma_rot_mt6256_e2_h__
#define __idp_imgdma_rot_mt6256_e2_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>
#include "drv_features_mdp.h"

#if defined(DRV_IDP_MT6256_E2_SERIES)

//#include "idp_imgdma.h"
//#include <idp_core.h>
//#include "img_common_enum.h"
//#include "idp_hw_common.h"
//#include <mt6256_e2/idp_mem.h>

typedef struct
{
    // main parameters
  idp_module_enum_t       input_src; // IDP_MODULE_NONE is for each module use default: ROTDMA0: MOUT0, ROTDMA1: MOUT1, ROTDMA2: VRZ
  img_rot_angle_enum_t    rot_angle; /**< rotate direction */
  kal_bool                flip;      /**< flip or not */
  kal_bool                rgb_output;
  
  img_color_fmt_rgb_enum_t    rgb_color_fmt; /**< output rgb format */
  img_color_fmt_yuv_enum_t    yuv_color_fmt; /**< output yuv format */
  kal_bool              block_base_yuv; 
  kal_bool              semi_planar_yuv;
  kal_bool              uv_planar_v_lsb;
  kal_uint32            y_dest_start_addr;
  kal_uint32            u_dest_start_addr;
  kal_uint32            v_dest_start_addr;
  kal_uint8             alpha_value; /* for constant alpha ARGB8888 output */
    
  kal_uint16            src_width; /**< width */
  kal_uint16            src_height; /**< height */
  
  kal_bool              pitch_enable; /**< pitch */
  kal_uint16            pitch_bytes; /**< horizontal pitch WARNING! the pitch is applied to three buffers */ 
  
  kal_bool              clip; /**< enable source clipping */
  kal_uint16            clip_left;
  kal_uint16            clip_right;
  kal_uint16            clip_top;
  kal_uint16            clip_bottom;
  
  kal_bool              dither_en;  /**< dither enable */
  kal_bool              rgb_rounding; /**< enable RGB rounding, only use when KAL_TRUE == output_rgb */
  kal_uint8             dithering_seed1;  
  kal_uint8             dithering_seed2;
  kal_uint8             dithering_seed3;
  
  // interrupt
  kal_bool                    intr_en; /**< enable int or not */
  idp_lisr_intr_cb_t          intr_cb;
  idp_lisr_intr_cb_param_t    intr_cb_param;
  
  //descriptor mode
  kal_bool            descriptor_mode;
  kal_uint8           queue_depth; /**[1,16] */
  kal_bool            queue_empty_drop; /** otherwise: stall previous engine */
  kal_uint32          des_queue_base_addr; //new: 6573 for future WinMo driver
  kal_uint32          des_valid_seg_bitmap; //new: 6573 for future WinMo driver 
  kal_uint32          des_valid_seg_number; //new: 6573 for future WinMo driver 
  kal_uint32          *des_queue_data_addr; //new: 6573 for future WinMo driver

  kal_bool            auto_loop; /**< auto loop mode */
  
  kal_bool            hw_frame_sync;/**camera app, first beginning signal is from cam */
  
  kal_bool            hw_trigger_rdma; /**< enable hw trigger RDMA */    
  kal_bool            hw_trigger_rdma_frame_sync_en; /** prevent tearing */
  kal_bool            hw_trigger_rdma_frame_sync_drop; /** drop or stall previous engine */
  kal_bool            hw_trigger_rdma_trigger_all_rest; /** trigger all rest RDMA des queue when ROT_DMA empty */

  kal_bool            stall_prev_engine_when_off;
  kal_bool            drop_prev_engine_when_off;
  
  // performance related
  kal_bool            resample_en; /**< resample enable , for YUV2 & UYVY output */
  kal_bool            isp_datapath; /**< isp datapath enable */ // ???
  kal_bool            slow_down_en; /** slow the access EMI rate */
  kal_uint16          slow_down_cnt; /** cnt: larger is slower */
  
  kal_bool            single_buffer_fifo_mode_en; /**< fifo mode enable */
  kal_bool            protect_en; /**< bus bandwidth protection for ROT_DMA enable */
  //kal_bool            double_buf_en; /**< double buffer of working memory */
  kal_bool            ultra_high_en; 
  kal_uint16          bus_control_threshold; /** max emi burst type: HW default is 7 (burst 8-8) */
  kal_uint16          main_lb_size_in_line; /** Sugguest to use 8 or 16 to fit all color format alignment. Size of working buffer 0. Unit is line number. */
  
  //// rmmu
  kal_bool           rmmu_en;
  //private
  kal_bool           _rmmu_reverse_fwd_dir;//0: engine write address is from low to high, 1: engine write address is from high to low
  //private  kal_bool         _rmmu_wrap;// enable when internal working memory is smaller than virtual memory table
  
  kal_uint32          rmmu_virt_base_addr;// dependent on rmmu_wrap
  kal_uint32          rmmu_pageTb_addr;// dependent on rmmu_wrap
  kal_uint32          rmmu_pageTb_size;
  kal_uint32          rmmu_intern_wm_addr;
  kal_uint32          rmmu_intern_wm_size;
  
  /** private member  */
  kal_uint16           sample_rate;   //Use to calculate Main/Sub Buffer Size//
  kal_uint16           output_size_in_bytes; /** output_s_in_byte = main_lb_s_in_line * size_unit.  size_unit: 4: ARGB8888& Block_yuv, 3: RGB888, 2: RGB565 & YUY2 & UYVY*/
  kal_uint32           main_buf_line_size; /** calculated from main_lb_size_in_line & width*/
  kal_uint32           main_blk_w; /** calculated from main_lb_size_in_line & width*/
  kal_uint32           main_final_working_buf_size; 
  kal_uint32           sub_buf_line_size; /** calculated from sub_lb_size_in_line & width*/
  kal_uint32           sub_blk_w; /** calculated from sub_lb_size_in_line & width*/
  kal_uint32           sub_final_working_buf_size; /** calculated from sub_lb_size_in_line & width*/
  
  
  
  //remove on MT6573    kal_bool            hw_trigger_lcd; /**< enable hw trigger LCD */
  //remove on MT6573    idp_lcd_hw_trigger_mode_t   hw_trigger_mode;
  //remove on MT6573    kal_bool            hw_trigger_rst_wait_lcd;
  
  kal_bool                    hw_trigger_lcd; /**< enable hw trigger LCD */
  idp_lcd_hw_trigger_mode_t   hw_trigger_mode;
  kal_bool                    hw_trigger_rst_wait_lcd;
  
  /** private member section */
  kal_uint32            _y_dest_start_addr;
  kal_uint32            _u_dest_start_addr;
  kal_uint32            _v_dest_start_addr;
  kal_uint32            wm_addr_0;
  kal_uint32            wm_addr_1;
  kal_uint32            wm_addr_2;
  kal_uint32            wm_addr_3;
  //kal_uint8             _yh;
  //kal_uint8             _yv;
  //kal_uint8             _uvh;
  //kal_uint8             _uvv; 
} idp_imgdma_rot_struct;
  



#endif // #if defined(__idp_imgdma_rot_mt6256_e2_h__)
#endif // __idp_imgdma_RGBROT0_mt6256_e2_h__

