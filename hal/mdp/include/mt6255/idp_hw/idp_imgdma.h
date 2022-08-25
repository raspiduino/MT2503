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
 *   idp_imgdma.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   image DMA
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
 * 05 08 2012 chrono.wu
 * removed!
 * .
 *
 * 02 23 2012 hung-wen.hsieh
 * removed!
 * .
 *
 * 11 29 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 10 25 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 09 24 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 09 13 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/** \defgroup idp Image data path
 * \brief This module defines image data path
 * @{
 */
/** \defgroup imgdma Image DMA
 * \brief This module defines image DMA.
 * @{
 */
#ifndef __idp_imgdma_mt6255_h__
#define __idp_imgdma_mt6255_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include "drv_features_mdp.h"

#if defined(DRV_IDP_MT6255_SERIES)

#include "reg_base.h"
#include "idp_core.h"
#include "img_common_enum.h"
#include "idp_hw_common.h"

/* RDMA MAX input size */
#define RDMA_MAX_INPUT_WIDTH                    (65535)
#define RDMA_MAX_INPUT_HEIGHT                   (65535)

#define MMSYS_CONFIG_BASE                       MMCONFG_base


/*** MDP Engine connect setting ***/
#ifndef MDP_C_MODEL
#define MMSYS_MDP_REQ_FLAG_0_REG                  (MMSYS_CONFIG_BASE + 0x0030)
#define IMGDMA_MMSYS_MDP_SEL_OUT_RDMA_REG         (MMSYS_CONFIG_BASE + 0x004C)

#define IMGDMA_MMSYS_MDP_SEL_IN_VDOROT_REG        (MMSYS_CONFIG_BASE + 0x006C)
#define IMGDMA_MMSYS_MDP_SEL_IN_RGBROT0_REG       (MMSYS_CONFIG_BASE + 0x0070)

#define REG_MMSYS_MDP_REQ_FLAG_0                  *((volatile unsigned int *)MMSYS_MDP_REQ_FLAG_0_REG)
#define REG_IMGDMA_MMSYS_MDP_SEL_OUT_RDMA         *((volatile unsigned int *)IMGDMA_MMSYS_MDP_SEL_OUT_RDMA_REG)      

#define REG_IMGDMA_MMSYS_MDP_SEL_IN_VDOROT        *((volatile unsigned int *)IMGDMA_MMSYS_MDP_SEL_IN_VDOROT_REG)      
#define REG_IMGDMA_MMSYS_MDP_SEL_IN_RGBROT0       *((volatile unsigned int *)IMGDMA_MMSYS_MDP_SEL_IN_RGBROT0_REG)      
   

#else  // MDP_C_MODEL

#endif // MDP_C_MODEL

//RDMA OUT
#define IMGDMA_MMSYS_MUX_RDMA_OUT_SEL_NONE() \
  do {REG_IMGDMA_MMSYS_MDP_SEL_OUT_RDMA = 0x03;} while(0)

#define IMGDMA_MMSYS_MUX_RDMA_OUT_SEL_VRZ() \
  do {REG_IMGDMA_MMSYS_MDP_SEL_OUT_RDMA = 0x00;} while(0)
                                
#define IMGDMA_MMSYS_MUX_RDMA_OUT_SEL_CRZ() \
  do {REG_IMGDMA_MMSYS_MDP_SEL_OUT_RDMA = 0x02;} while(0)

//VDOROT IN
#define IMGDMA_MMSYS_MUX_VDOROT_IN_SEL_NONE() \
  do {REG_IMGDMA_MMSYS_MDP_SEL_IN_VDOROT = 0x03;} while(0)
            
#define IMGDMA_MMSYS_MUX_VDOROT_IN_SEL_MOUT() \
  do {REG_IMGDMA_MMSYS_MDP_SEL_IN_VDOROT = 0x01;} while(0)

#define IMGDMA_MMSYS_MUX_VDOROT_IN_SEL_VRZ() \
  do {REG_IMGDMA_MMSYS_MDP_SEL_IN_VDOROT = 0x00;} while(0)

//RGBROT0 IN
#define IMGDMA_MMSYS_MUX_RGBROT0_IN_SEL_NONE() \
  do {REG_IMGDMA_MMSYS_MDP_SEL_IN_RGBROT0 = 0X03;} while(0)

#define IMGDMA_MMSYS_MUX_RGBROT0_IN_SEL_MOUT() \
  do {REG_IMGDMA_MMSYS_MDP_SEL_IN_RGBROT0 = 0X01;} while(0)

#define IMGDMA_MMSYS_MUX_RGBROT0_IN_SEL_VRZ() \
  do {REG_IMGDMA_MMSYS_MDP_SEL_IN_RGBROT0 = 0X00;} while(0)


typedef struct
{
    // main parameters
  idp_module_enum_t           input_src; // IDP_MODULE_NONE is for each module use default: ROTDMA0: MOUT0, ROTDMA1: MOUT1, ROTDMA2: VRZ
  img_rot_angle_enum_t        rot_angle; /**< rotate direction */
  kal_bool                    flip; /**< flip or not */

  kal_bool                    rgb_output;
  img_color_fmt_rgb_enum_t    rgb_color_fmt; /**< output rgb format */
  img_color_fmt_yuv_enum_t    yuv_color_fmt; /**< output yuv format */
  kal_bool                    block_base_yuv;
  kal_bool                    semi_planar_yuv;
  kal_bool                    uv_planar_v_lsb;
  kal_uint32                  y_dest_start_addr;
  kal_uint32                  u_dest_start_addr;
  kal_uint32                  v_dest_start_addr;
  kal_uint8                   alpha_value; /* for constant alpha ARGB8888 output */

  kal_uint16                  src_width; /**< width */
  kal_uint16                  src_height; /**< height */

  kal_bool                    pitch_enable; /**< pitch */
  kal_uint16                  pitch_bytes; /**< horizontal pitch WARNING! the pitch is applied to three buffers */

  kal_bool                    clip; /**< enable source clipping */
  kal_uint16                  clip_top;
  kal_uint16                  clip_bottom;
  kal_uint16                  clip_left;
  kal_uint16                  clip_right;

  kal_bool                    dither_en;  /**< dither enable */
  kal_bool                    rgb_rounding; /**< enable RGB rounding, only use when KAL_TRUE == output_rgb */
  kal_uint8                   dithering_seed1;
  kal_uint8                   dithering_seed2;
  kal_uint8                   dithering_seed3;

  // interrupt
  kal_bool                    intr_en; /**< enable int or not */
  idp_lisr_intr_cb_t          intr_cb;
  idp_lisr_intr_cb_param_t    intr_cb_param;

  //descriptor mode
  kal_bool                    descriptor_mode;
  kal_uint8                   queue_depth; /**[1,16] */
  kal_bool                    queue_empty_drop; /** otherwise: stall previous engine */
  kal_uint32                  des_queue_base_addr; //new: 6573 for future WinMo driver
  kal_uint32                  des_valid_seg_bitmap; //new: 6573 for future WinMo driver
  kal_uint32                  des_valid_seg_number; //new: 6573 for future WinMo driver
  kal_uint32                  *des_queue_data_addr; //new: 6573 for future WinMo driver

  kal_bool                    auto_loop; /**< auto loop mode */

  kal_bool                    hw_frame_sync;/**camera app, first beginning signal is from cam */

  kal_bool                    hw_trigger_rdma; /**< enable hw trigger RDMA */
  kal_bool                    hw_trigger_rdma_frame_sync_en; /** prevent tearing */
  kal_bool                    hw_trigger_rdma_frame_sync_drop; /** drop or stall previous engine */
  kal_bool                    hw_trigger_rdma_trigger_all_rest; /** trigger all rest RDMA des queue when ROT_DMA empty */

  kal_bool                    stall_prev_engine_when_off;
  kal_bool                    drop_prev_engine_when_off;

  // performance related
  kal_bool                    resample_en; /**< resample enable , for YUV2 & UYVY output */
  kal_bool                    isp_datapath; /**< isp datapath enable */ // ???
  kal_bool                    slow_down_en; /** slow the access EMI rate */
  kal_uint16                  slow_down_cnt; /** cnt: larger is slower */

  kal_bool                    single_buffer_fifo_mode_en; /**< fifo mode enable */
  kal_bool                    protect_en; /**< bus bandwidth protection for ROT_DMA enable */
  kal_bool                    double_buf_en; /**< double buffer of working memory */
  kal_bool                    ultra_high_en;
  kal_uint16                  bus_control_threshold; /** max emi burst type: HW default is 7 (burst 8-8) */
  kal_uint16                  main_lb_size_in_line; /** Sugguest to use 8 or 16 to fit all color format alignment. Size of working buffer 0. Unit is line number. */

  /** private member  */
  kal_uint16                  sample_rate;   //Use to calculate Main/Sub Buffer Size//
  kal_uint16                  output_size_in_bytes; /** output_s_in_byte = main_lb_s_in_line * size_unit.  size_unit: 4: ARGB8888& Block_yuv, 3: RGB888, 2: RGB565 & YUY2 & UYVY*/
  kal_uint32                  main_buf_line_size; /** calculated from main_lb_size_in_line & width*/
  kal_uint32                  main_blk_w; /** calculated from main_lb_size_in_line & width*/
  kal_uint32                  main_final_working_buf_size;
  kal_uint32                  sub_buf_line_size; /** calculated from sub_lb_size_in_line & width*/
  kal_uint32                  sub_blk_w; /** calculated from sub_lb_size_in_line & width*/
  kal_uint32                  sub_final_working_buf_size; /** calculated from sub_lb_size_in_line & width*/

  kal_bool                    hw_trigger_lcd; /**< enable hw trigger LCD */
  idp_lcd_hw_trigger_mode_t   hw_trigger_mode;
  kal_bool                    hw_trigger_rst_wait_lcd;

  /** private member section */
  kal_uint32                  _y_dest_start_addr;
  kal_uint32                  _u_dest_start_addr;
  kal_uint32                  _v_dest_start_addr;
  //not used, remove    kal_uint32          work_mem_line_count;
  kal_uint32                  wm_addr_0;
  kal_uint32                  wm_addr_1;
  kal_uint32                  wm_addr_2;
  kal_uint32                  wm_addr_3;

  //// For easy debugging...
  kal_uint8                   _yh;
  kal_uint8                   _yv;
  kal_uint8                   _uvh;
  kal_uint8                   _uvv;
  //kal_uint8         _uh;
  //kal_uint8         _uv;
  //kal_uint8         _vh;
  //kal_uint8         _vv;
} idp_imgdma_rotdma_struct;


/**
 * Init IMGDMA HW engines
 */
extern void idp_imgdma_init(void);

/**
 * The LISR for IMGDMA interruption
 */
//extern void image_dma_LISR(void);

extern void
idp_imgdma_rotdma_get_main_buff_parameters(
    kal_bool is_rgb_format,
    img_color_fmt_yuv_enum_t yuv_format,  
    kal_uint16 sample_rate, 
    kal_bool fifo_mode, 
    kal_uint32 clip_w,
    kal_uint32 main_lb_s_in_line, 
    kal_uint32 *p_main_blk_w, 
    kal_uint32 *p_main_buf_line_size,
    kal_uint32 * p_main_working_buff_size);


extern void
idp_imgdma_rotdma_get_sub_buff_parameters(
    kal_bool is_rgb_format,
    img_color_fmt_yuv_enum_t yuv_format,  
    kal_uint16 sample_rate, 
    kal_bool fifo_mode, 
    kal_bool resample_mode, 
    kal_uint32 clip_w,
    kal_uint32 main_lb_s_in_line, 
    kal_uint32 *p_sub_blk_w, 
    kal_uint32 *p_sub_buf_line_size,
    kal_uint32 * p_sub_working_buff_size);


extern kal_bool
idp_imgdma_rotdma_get_dst_start_address_shift_byte(
    kal_bool                  input_rgb,
    img_color_fmt_rgb_enum_t  rgb_color_fmt,
    img_color_fmt_yuv_enum_t  yuv_color_fmt,
    img_rot_angle_enum_t      rot_angle,
    kal_uint32 y_dst_w_in_byte,
    kal_uint32 y_clip_w,
    kal_uint32 y_clip_h,    
    kal_uint32 *y_shift,
    kal_uint32 *uv_shift);


extern kal_uint32 
idp_imgdma_jpgdma_get_wb_bpp_x_nol(
    img_color_fmt_yuv_enum_t yuv_format);


#endif // #if defined(DRV_IDP_MT6255_SERIES)
#endif // __idp_imgdma_mt6255_h__

