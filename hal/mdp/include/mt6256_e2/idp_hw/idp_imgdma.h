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
 * 12 07 2011 chelun.tsai
 * removed!
 * .
 *
 * 09 20 2011 chelun.tsai
 * removed!
 * .
 *
 * 07 27 2011 chelun.tsai
 * removed!
 * .
 *
 * 07 01 2011 chelun.tsai
 * removed!
 * .
 *
 * 05 27 2011 chelun.tsai
 * removed!
 * MT6526 E2 MDP driver.
 *
 * 05 23 2011 chelun.tsai
 * removed!
 * video encode ok.
 *
 * 05 05 2011 chelun.tsai
 * removed!
 * last check in befor sample back.
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
#ifndef __idp_imgdma_mt6256_e2_h__
#define __idp_imgdma_mt6256_e2_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif


#include <idp_define.h>
#include "drv_features_mdp.h"

#if defined(DRV_IDP_MT6256_E2_SERIES)

#include "reg_base.h"
#include "IntrCtrl.h"
#include "idp_core.h"
#include "img_common_enum.h"
#include "idp_hw_common.h"

/* RDMA MAX input size */
#define RDMA_MAX_INPUT_WIDTH                    (65535)
#define RDMA_MAX_INPUT_HEIGHT                   (65535)

/*** MDP Engine connect setting ***/
#ifndef MDP_C_MODEL
#define MMSYS_CONFIG_BASE                       (MMCONFG_base)
#define IMGDMA_MMSYS_MDP_BRZ_OUTPUT_SEL_REG     (MMSYS_CONFIG_BASE + 0x40)
#define IMGDMA_MMSYS_MDP_CRZ_OUTPUT_SEL_REG     (MMSYS_CONFIG_BASE + 0x44)
#define IMGDMA_MMSYS_MDP_PRZ_OUTPUT_SEL_REG     (MMSYS_CONFIG_BASE + 0x48)
#define IMGDMA_MMSYS_MDP_RDMA_OUTPUT_SEL_REG    (MMSYS_CONFIG_BASE + 0x4C)
#define IMGDMA_MMSYS_MDP_MUX_OUTPUT_SEL_REG     (MMSYS_CONFIG_BASE + 0x50)
#define IMGDMA_MMSYS_MDP_JPEGDMA_INPUT_SEL_REG  (MMSYS_CONFIG_BASE + 0x5C)
#define IMGDMA_MMSYS_MDP_OVL_INPUT_SEL_REG      (MMSYS_CONFIG_BASE + 0x60)
#define IMGDMA_MMSYS_MDP_IPP_INPUT_SEL_REG      (MMSYS_CONFIG_BASE + 0x64)
#define IMGDMA_MMSYS_MDP_MUX_INPUT_SEL_REG      (MMSYS_CONFIG_BASE + 0x68)
#define IMGDMA_MMSYS_MDP_VDOROT_INPUT_SEL_REG   (MMSYS_CONFIG_BASE + 0x6C)
#define IMGDMA_MMSYS_MDP_RGBROT0_INPUT_SEL_REG  (MMSYS_CONFIG_BASE + 0x70)
#define IMGDMA_MMSYS_MDP_VRZ_INPUT_SEL_REG      (MMSYS_CONFIG_BASE + 0x74)
#define IMGDMA_MMSYS_MDP_CRZ_INPUT_SEL_REG      (MMSYS_CONFIG_BASE + 0x78)
#define IMGDMA_MMSYS_MDP_PRZ_INPUT_SEL_REG      (MMSYS_CONFIG_BASE + 0x7C)

#define REG_IMGDMA_MMSYS_MDP_BRZ_OUTPUT_SEL       *((volatile unsigned int *)IMGDMA_MMSYS_MDP_BRZ_OUTPUT_SEL_REG) 
#define REG_IMGDMA_MMSYS_MDP_CRZ_OUTPUT_SEL       *((volatile unsigned int *)IMGDMA_MMSYS_MDP_CRZ_OUTPUT_SEL_REG) 
#define REG_IMGDMA_MMSYS_MDP_PRZ_OUTPUT_SEL       *((volatile unsigned int *)IMGDMA_MMSYS_MDP_PRZ_OUTPUT_SEL_REG)
#define REG_IMGDMA_MMSYS_MDP_RDMA_OUTPUT_SEL      *((volatile unsigned int *)IMGDMA_MMSYS_MDP_RDMA_OUTPUT_SEL_REG)
#define REG_IMGDMA_MMSYS_MDP_MUX_OUTPUT_SEL       *((volatile unsigned int *)IMGDMA_MMSYS_MDP_MUX_OUTPUT_SEL_REG)
#define REG_IMGDMA_MMSYS_MDP_JPEGDMA_INPUT_SEL    *((volatile unsigned int *)IMGDMA_MMSYS_MDP_JPEGDMA_INPUT_SEL_REG)
#define REG_IMGDMA_MMSYS_MDP_OVL_INPUT_SEL        *((volatile unsigned int *)IMGDMA_MMSYS_MDP_OVL_INPUT_SEL_REG)
#define REG_IMGDMA_MMSYS_MDP_IPP_INPUT_SEL        *((volatile unsigned int *)IMGDMA_MMSYS_MDP_IPP_INPUT_SEL_REG)
#define REG_IMGDMA_MMSYS_MDP_MUX_INPUT_SEL        *((volatile unsigned int *)IMGDMA_MMSYS_MDP_MUX_INPUT_SEL_REG)
#define REG_IMGDMA_MMSYS_MDP_VDOROT_INPUT_SEL     *((volatile unsigned int *)IMGDMA_MMSYS_MDP_VDOROT_INPUT_SEL_REG) 
#define REG_IMGDMA_MMSYS_MDP_RGBROT0_INPUT_SEL    *((volatile unsigned int *)IMGDMA_MMSYS_MDP_RGBROT0_INPUT_SEL_REG)
#define REG_IMGDMA_MMSYS_MDP_VRZ_INPUT_SEL        *((volatile unsigned int *)IMGDMA_MMSYS_MDP_VRZ_INPUT_SEL_REG)
#define REG_IMGDMA_MMSYS_MDP_CRZ_INPUT_SEL        *((volatile unsigned int *)IMGDMA_MMSYS_MDP_CRZ_INPUT_SEL_REG)
#define REG_IMGDMA_MMSYS_MDP_PRZ_INPUT_SEL        *((volatile unsigned int *)IMGDMA_MMSYS_MDP_PRZ_INPUT_SEL_REG)
#else  // MDP_C_MODEL

#endif // MDP_C_MODEL


// BRZ
#define IMGDMA_MMSYS_BRZ_OUTPUT_SEL_NONE() \
    do {REG_IMGDMA_MMSYS_MDP_BRZ_OUTPUT_SEL = 0x3;} while(0)

#define IMGDMA_MMSYS_BRZ_OUTPUT_SEL_PRZ() \
    do {REG_IMGDMA_MMSYS_MDP_BRZ_OUTPUT_SEL = 0x0;} while(0)

#define IMGDMA_MMSYS_BRZ_OUTPUT_SEL_CRZ() \
    do {REG_IMGDMA_MMSYS_MDP_BRZ_OUTPUT_SEL = 0x1;} while(0)


// CRZ
#define IMGDMA_MMSYS_CRZ_OUTPUT_SEL_NONE() \
    do {REG_IMGDMA_MMSYS_MDP_CRZ_OUTPUT_SEL = 0x3;} while(0)

#define IMGDMA_MMSYS_CRZ_OUTPUT_SEL_IPP() \
    do {REG_IMGDMA_MMSYS_MDP_CRZ_OUTPUT_SEL = 0x0;} while(0)

#define IMGDMA_MMSYS_CRZ_OUTPUT_SEL_OVL() \
    do {REG_IMGDMA_MMSYS_MDP_CRZ_OUTPUT_SEL = 0x1;} while(0)

#define IMGDMA_MMSYS_CRZ_INPUT_SEL_NONE() \
    do {REG_IMGDMA_MMSYS_MDP_CRZ_INPUT_SEL = 0x3;} while(0)

#define IMGDMA_MMSYS_CRZ_INPUT_SEL_RDMA() \
    do {REG_IMGDMA_MMSYS_MDP_CRZ_INPUT_SEL = 0x0;} while(0)

#define IMGDMA_MMSYS_CRZ_INPUT_SEL_BRZ() \
    do {REG_IMGDMA_MMSYS_MDP_CRZ_INPUT_SEL = 0x1;} while(0)

#define IMGDMA_MMSYS_CRZ_INPUT_SEL_CAM() \
    do {REG_IMGDMA_MMSYS_MDP_CRZ_INPUT_SEL = 0x2;} while(0)


//PRZ
#define IMGDMA_MMSYS_PRZ_OUTPUT_SEL__NONE() \
    do {REG_IMGDMA_MMSYS_MDP_PRZ_OUTPUT_SEL = 0x03;} while(0)
    
#define IMGDMA_MMSYS_PRZ_OUTPUT_SEL_RGBROT0() \
    do {REG_IMGDMA_MMSYS_MDP_PRZ_OUTPUT_SEL = 0x0;} while(0)

#define IMGDMA_MMSYS_PRZ_OUTPUT_SEL_VDOROT() \
    do {REG_IMGDMA_MMSYS_MDP_PRZ_OUTPUT_SEL = 0x1;} while(0)

#define IMGDMA_MMSYS_PRZ_INPUT_SEL_NONE() \
    do {REG_IMGDMA_MMSYS_MDP_PRZ_INPUT_SEL = 0x7;} while(0)

#define IMGDMA_MMSYS_PRZ_INPUT_SEL_MUX() \
    do {REG_IMGDMA_MMSYS_MDP_PRZ_INPUT_SEL = 0x0;} while(0)

#define IMGDMA_MMSYS_PRZ_INPUT_SEL_BRZ() \
    do {REG_IMGDMA_MMSYS_MDP_PRZ_INPUT_SEL = 0x1;} while(0)

#define IMGDMA_MMSYS_PRZ_INPUT_SEL_MOUT() \
    do {REG_IMGDMA_MMSYS_MDP_PRZ_INPUT_SEL = 0x2;} while(0)

#define IMGDMA_MMSYS_PRZ_INPUT_SEL_MIMO() \
    do {REG_IMGDMA_MMSYS_MDP_PRZ_INPUT_SEL = 0x3;} while(0)


//RDMA
#define IMGDMA_MMSYS_RDMA_OUTPUT_SEL_NONE() \
    do {REG_IMGDMA_MMSYS_MDP_RDMA_OUTPUT_SEL = 0x3;} while(0)

#define IMGDMA_MMSYS_RDMA_OUTPUT_SEL_MUX() \
    do {REG_IMGDMA_MMSYS_MDP_RDMA_OUTPUT_SEL = 0x0;} while(0)

#define IMGDMA_MMSYS_RDMA_OUTPUT_SEL_OVL() \
    do {REG_IMGDMA_MMSYS_MDP_RDMA_OUTPUT_SEL = 0x1;} while(0)

#define IMGDMA_MMSYS_RDMA_OUTPUT_SEL_CRZ() \
    do {REG_IMGDMA_MMSYS_MDP_RDMA_OUTPUT_SEL = 0x2;} while(0)


//MUX
#define IMGDMA_MMSYS_MUX_OUTPUT_SEL_NONE() \
    do {REG_IMGDMA_MMSYS_MDP_MUX_OUTPUT_SEL = 0x3;} while(0)

#define IMGDMA_MMSYS_MUX_OUTPUT_SEL_PRZ() \
    do {REG_IMGDMA_MMSYS_MDP_MUX_OUTPUT_SEL = 0x0;} while(0)

#define IMGDMA_MMSYS_MUX_OUTPUT_SEL_VRZ() \
    do {REG_IMGDMA_MMSYS_MDP_MUX_OUTPUT_SEL = 0x1;} while(0)

#define IMGDMA_MMSYS_MUX_OUTPUT_SEL_JPEGDMA() \
    do {REG_IMGDMA_MMSYS_MDP_MUX_OUTPUT_SEL = 0x2;} while(0)
    
#define IMGDMA_MMSYS_MUX_INPUT_SEL_NONE() \
    do {REG_IMGDMA_MMSYS_MDP_MUX_INPUT_SEL = 0x3;} while(0)

#define IMGDMA_MMSYS_MUX_INPUT_SEL_MIMO() \
    do {REG_IMGDMA_MMSYS_MDP_MUX_INPUT_SEL = 0x0;} while(0)

#define IMGDMA_MMSYS_MUX_INPUT_SEL_RDMA() \
    do {REG_IMGDMA_MMSYS_MDP_MUX_INPUT_SEL = 0x1;} while(0)


//JPEGDMA
#define IMGDMA_MMSYS_JPEGDMA_INPUT_SEL_NONE() \
    do {REG_IMGDMA_MMSYS_MDP_JPEGDMA_INPUT_SEL = 0x3;} while(0)

#define IMGDMA_MMSYS_JPEGDMA_INPUT_SEL_MOUT() \
    do {REG_IMGDMA_MMSYS_MDP_JPEGDMA_INPUT_SEL = 0x0;} while(0)

#define IMGDMA_MMSYS_JPEGDMA_INPUT_SEL_MUX() \
    do {REG_IMGDMA_MMSYS_MDP_JPEGDMA_INPUT_SEL = 0x1;} while(0)


//OVL
#define IMGDMA_MMSYS_OVL_INPUT_SEL_NONE() \
    do {REG_IMGDMA_MMSYS_MDP_OVL_INPUT_SEL = 0x3 ;} while(0)

#define IMGDMA_MMSYS_OVL_INPUT_SEL_RDMA() \
    do {REG_IMGDMA_MMSYS_MDP_OVL_INPUT_SEL = 0x0;} while(0)

#define IMGDMA_MMSYS_OVL_INPUT_SEL_CRZ() \
    do {REG_IMGDMA_MMSYS_MDP_OVL_INPUT_SEL = 0x1;} while(0)


//IPP
#define IMGDMA_MMSYS_IPP_INPUT_SEL_NONE() \
    do {REG_IMGDMA_MMSYS_MDP_IPP_INPUT_SEL = 0x3;} while(0)

#define IMGDMA_MMSYS_IPP_INPUT_SEL_MIMO() \
    do {REG_IMGDMA_MMSYS_MDP_IPP_INPUT_SEL = 0x0;} while(0)

#define IMGDMA_MMSYS_IPP_INPUT_SEL_CRZ() \
    do {REG_IMGDMA_MMSYS_MDP_IPP_INPUT_SEL = 0x1;} while(0)


//VDOROT
#define IMGDMA_MMSYS_VDOROT_INPUT_SEL_NONE() \
    do {REG_IMGDMA_MMSYS_MDP_VDOROT_INPUT_SEL = 0x3;} while(0)

#define IMGDMA_MMSYS_VDOROT_INPUT_SEL_PRZ() \
    do {REG_IMGDMA_MMSYS_MDP_VDOROT_INPUT_SEL = 0x0;} while(0)

#define IMGDMA_MMSYS_VDOROT_INPUT_SEL_MOUT() \
    do {REG_IMGDMA_MMSYS_MDP_VDOROT_INPUT_SEL = 0x1;} while(0)


//RGBROT
#define IMGDMA_MMSYS_RGBROT0_INPUT_SEL_NONE() \
    do {REG_IMGDMA_MMSYS_MDP_RGBROT0_INPUT_SEL = 0x3;} while(0)

#define IMGDMA_MMSYS_RGBROT0_INPUT_SEL_PRZ() \
    do {REG_IMGDMA_MMSYS_MDP_RGBROT0_INPUT_SEL = 0x0;} while(0)

#define IMGDMA_MMSYS_RGBROT0_INPUT_SEL_MOUT() \
    do {REG_IMGDMA_MMSYS_MDP_RGBROT0_INPUT_SEL = 0x1;} while(0)


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


#endif // #if defined(DRV_IDP_MT6256_E2_SERIES)
#endif // __idp_imgdma_mt6256_e2_h__

