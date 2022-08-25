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
 *   idp_image_effect.c
 *
 * Project:
 * --------
 *
 * Description:
 * ------------
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL

#include "drv_features_mdp.h"
#include "drv_comm.h"

#if defined(DRV_IDP_SUPPORT)

#include <idp_define.h>

#include "drv_comm.h"
#include "visual_comm.h"
#include "image_effect_post.h"
#include "idp_image_effect_pixel.h"
#include "img_common_enum.h"
#include "med_api.h"
#include "image_effect_post.h"
#include "ipp_enum.h"

static ipp_config_data_t ipp_config_data;

IMAGE_EFFECT_DEC_STRUCT image_effect_dec_para;
IMAGE_EFFECT_DEC_STRUCT image_adj_dec_para;

const kal_uint8 sine[91]={  0, 1, 2, 3, 4, 6, 7, 8, 9,10,
                            11,12,13,14,15,17,18,19,20,21,
                            22,23,24,25,26,27,28,29,30,31,
                            32,33,34,35,36,37,38,39,39,40,
                            41,42,43,44,44,45,46,47,48,48,
                            49,50,50,51,52,52,53,54,54,55,
                            55,56,57,57,58,58,58,59,59,60,
                            60,61,61,61,62,62,62,62,63,63,
                            63,63,63,64,64,64,64,64,64,64,
                            64};

const kal_uint8 gamma[9][17]={ {0,25, 9,7,5,5, 5, 4, 3,50,18,14,10,10,10, 8, 7},
                               {0,22,10,7,6,5, 5, 4, 4,44,20,14,12,10,10, 8, 9},
                               {0,18,10,7,7,6, 6, 5, 4,36,20,14,14,12,12,10, 9},
                               {0,12, 9,8,8,7, 7, 6, 6,24,18,16,16,14,14,12,14},
                               {0, 8, 8,8,8,8, 8, 8, 7,16,16,16,16,16,16,16,16},
                               {1, 5, 7,8,8,9, 8,10, 8,10,14,16,16,18,16,20,18},
                               {1, 3, 5,7,8,9,10,11,10, 6,10,14,16,18,20,22,23},
                               {1, 2, 3,6,8,9,11,12,12, 4, 6,12,16,18,22,24,27},
                               {1, 1, 3,5,7,9,12,13,13, 2, 6,10,14,18,24,26,30}};

const kal_uint8 coloradj_rb[9][7]={ {8, 3,16,16, 6,16,27},
                                    {8, 4,16,16, 8,16,25},
                                    {8, 6,16,16,12,16,21},
                                    {8, 7,16,16,14,16,19},
                                    {8, 8,16,16,16,16,16},
                                    {8,10,16,16,20,16,11},
                                    {8,12,16,16,23,16, 8},
                                    {8,13,16,16,26,16, 5},
                                    {8,14,16,16,28,16, 2}};

const kal_uint8 coloradj_g[9][7]={  {16, 6,32,32, 6,16,26},
                                    {16, 8,32,32, 8,16,25},
                                    {16,12,32,32,12,16,20},
                                    {16,14,32,32,14,16,19},
                                    {16,16,32,32,16,16,16},
                                    {16,20,32,32,20,16,12},
                                    {16,23,32,32,23,16, 8},
                                    {16,26,32,32,26,16, 6},
                                    {16,28,32,32,28,16, 3}};

#if defined(DRV_PIXEL_EFFECT_SUPPORT)
static void
effect_dec_grayscale(void)
{
  kal_bool result;
  kal_bool busy;
  kal_uint32 key;
  
  result = idp_image_effect_pixel_open(&key);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_config(
    key,
    
    IDP_IMAGE_EFFECT_PIXEL_INTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_INTMEM_SIZE, 0,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_SIZE, 0,
    
    IDP_IMAGE_EFFECT_PIXEL_SRC_ADDRESS, ipp_config_data.src_address,
    IDP_IMAGE_EFFECT_PIXEL_SRC_WIDTH, ipp_config_data.src_width,
    IDP_IMAGE_EFFECT_PIXEL_SRC_HEIGHT, ipp_config_data.src_height,
    IDP_IMAGE_EFFECT_PIXEL_SRC_COLOR_FMT, ipp_config_data.src_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_DEST_ADDRESS, ipp_config_data.dest_address,
    IDP_IMAGE_EFFECT_PIXEL_DEST_COLOR_FMT, ipp_config_data.dest_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_ROT_ANGLE, IMG_ROT_ANGLE_0,
    
    IDP_IMAGE_EFFECT_PIXEL_HSA, IDP_IMAGE_EFFECT_PIXEL_HSA_GRAY,
    IDP_IMAGE_EFFECT_PIXEL_CBA, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_INV, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_CLR, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_GMA, KAL_FALSE,
    
    IDP_IMAGE_EFFECT_PIXEL_COLORIZE_U, 0,
    IDP_IMAGE_EFFECT_PIXEL_COLORIZE_V, 0,
    
    0);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_start_all(key);
  ASSERT(KAL_TRUE == result);
  
  while (1)
  {
    result = idp_image_effect_pixel_is_busy(key, &busy);
    ASSERT(KAL_TRUE == result);
    
    if (KAL_TRUE == busy)
    {
    }
    else
    {
      break;
    }
  }
  
  result = idp_image_effect_pixel_close(key);
  ASSERT(KAL_TRUE == result);
}

static void
effect_dec_sepia(void)
{
  kal_bool result;
  kal_bool busy;
  kal_uint32 key;
  
  result = idp_image_effect_pixel_open(&key);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_config(
    key,

    IDP_IMAGE_EFFECT_PIXEL_INTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_INTMEM_SIZE, 0,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_SIZE, 0,
    
    IDP_IMAGE_EFFECT_PIXEL_SRC_ADDRESS, ipp_config_data.src_address,
    IDP_IMAGE_EFFECT_PIXEL_SRC_WIDTH, ipp_config_data.src_width,
    IDP_IMAGE_EFFECT_PIXEL_SRC_HEIGHT, ipp_config_data.src_height,
    IDP_IMAGE_EFFECT_PIXEL_SRC_COLOR_FMT, ipp_config_data.src_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_DEST_ADDRESS, ipp_config_data.dest_address,
    IDP_IMAGE_EFFECT_PIXEL_DEST_COLOR_FMT, ipp_config_data.dest_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_ROT_ANGLE, IMG_ROT_ANGLE_0,
    
    IDP_IMAGE_EFFECT_PIXEL_HSA, IDP_IMAGE_EFFECT_PIXEL_HSA_COLORIZE,
    IDP_IMAGE_EFFECT_PIXEL_CBA, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_INV, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_CLR, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_GMA, KAL_FALSE,
    
    IDP_IMAGE_EFFECT_PIXEL_COLORIZE_U, -30,
    IDP_IMAGE_EFFECT_PIXEL_COLORIZE_V, 36,
    
    0);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_start_all(key);
  ASSERT(KAL_TRUE == result);
  
  while (1)
  {
    result = idp_image_effect_pixel_is_busy(key, &busy);
    ASSERT(KAL_TRUE == result);
    
    if (KAL_TRUE == busy)
    {
    }
    else
    {
      break;
    }
  }
  
  result = idp_image_effect_pixel_close(key);
  ASSERT(KAL_TRUE == result);
}

static void
effect_dec_sepiagreen(void)
{
  kal_bool result;
  kal_bool busy;
  kal_uint32 key;
  
  result = idp_image_effect_pixel_open(&key);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_config(
    key,
    
    IDP_IMAGE_EFFECT_PIXEL_INTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_INTMEM_SIZE, 0,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_SIZE, 0,
    
    IDP_IMAGE_EFFECT_PIXEL_SRC_ADDRESS, ipp_config_data.src_address,
    IDP_IMAGE_EFFECT_PIXEL_SRC_WIDTH, ipp_config_data.src_width,
    IDP_IMAGE_EFFECT_PIXEL_SRC_HEIGHT, ipp_config_data.src_height,
    IDP_IMAGE_EFFECT_PIXEL_SRC_COLOR_FMT, ipp_config_data.src_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_DEST_ADDRESS, ipp_config_data.dest_address,
    IDP_IMAGE_EFFECT_PIXEL_DEST_COLOR_FMT, ipp_config_data.dest_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_ROT_ANGLE, IMG_ROT_ANGLE_0,
    
    IDP_IMAGE_EFFECT_PIXEL_HSA, IDP_IMAGE_EFFECT_PIXEL_HSA_COLORIZE,
    IDP_IMAGE_EFFECT_PIXEL_CBA, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_INV, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_CLR, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_GMA, KAL_FALSE,
    
    IDP_IMAGE_EFFECT_PIXEL_COLORIZE_U, -30,
    IDP_IMAGE_EFFECT_PIXEL_COLORIZE_V, -30,
    
    0);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_start_all(key);
  ASSERT(KAL_TRUE == result);
  
  while (1)
  {
    result = idp_image_effect_pixel_is_busy(key, &busy);
    ASSERT(KAL_TRUE == result);
    
    if (KAL_TRUE == busy)
    {
    }
    else
    {
      break;
    }
  }
  
  result = idp_image_effect_pixel_close(key);
  ASSERT(KAL_TRUE == result);
}

static void
effect_dec_sepiablue(void)
{
  kal_bool result;
  kal_bool busy;
  kal_uint32 key;
  
  result = idp_image_effect_pixel_open(&key);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_config(
    key,

    IDP_IMAGE_EFFECT_PIXEL_INTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_INTMEM_SIZE, 0,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_SIZE, 0,
    
    IDP_IMAGE_EFFECT_PIXEL_SRC_ADDRESS, ipp_config_data.src_address,
    IDP_IMAGE_EFFECT_PIXEL_SRC_WIDTH, ipp_config_data.src_width,
    IDP_IMAGE_EFFECT_PIXEL_SRC_HEIGHT, ipp_config_data.src_height,
    IDP_IMAGE_EFFECT_PIXEL_SRC_COLOR_FMT, ipp_config_data.src_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_DEST_ADDRESS, ipp_config_data.dest_address,
    IDP_IMAGE_EFFECT_PIXEL_DEST_COLOR_FMT, ipp_config_data.dest_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_ROT_ANGLE, IMG_ROT_ANGLE_0,
    
    IDP_IMAGE_EFFECT_PIXEL_HSA, IDP_IMAGE_EFFECT_PIXEL_HSA_COLORIZE,
    IDP_IMAGE_EFFECT_PIXEL_CBA, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_INV, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_CLR, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_GMA, KAL_FALSE,
    
    IDP_IMAGE_EFFECT_PIXEL_COLORIZE_U, 88,
    IDP_IMAGE_EFFECT_PIXEL_COLORIZE_V, -30,
    
    0);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_start_all(key);
  ASSERT(KAL_TRUE == result);
  
  while (1)
  {
    result = idp_image_effect_pixel_is_busy(key, &busy);
    ASSERT(KAL_TRUE == result);
    
    if (KAL_TRUE == busy)
    {
    }
    else
    {
      break;
    }
  }
  
  result = idp_image_effect_pixel_close(key);
  ASSERT(KAL_TRUE == result);
}

static void
effect_dec_colorinv(void)
{
  kal_bool result;
  kal_bool busy;
  kal_uint32 key;
  
  result = idp_image_effect_pixel_open(&key);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_config(
    key,
    
    IDP_IMAGE_EFFECT_PIXEL_INTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_INTMEM_SIZE, 0,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_SIZE, 0,
    
    IDP_IMAGE_EFFECT_PIXEL_SRC_ADDRESS, ipp_config_data.src_address,
    IDP_IMAGE_EFFECT_PIXEL_SRC_WIDTH, ipp_config_data.src_width,
    IDP_IMAGE_EFFECT_PIXEL_SRC_HEIGHT, ipp_config_data.src_height,
    IDP_IMAGE_EFFECT_PIXEL_SRC_COLOR_FMT, ipp_config_data.src_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_DEST_ADDRESS, ipp_config_data.dest_address,
    IDP_IMAGE_EFFECT_PIXEL_DEST_COLOR_FMT, ipp_config_data.dest_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_ROT_ANGLE, IMG_ROT_ANGLE_0,
    
    IDP_IMAGE_EFFECT_PIXEL_HSA, IDP_IMAGE_EFFECT_PIXEL_HSA_NONE,
    IDP_IMAGE_EFFECT_PIXEL_CBA, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_INV, KAL_TRUE,
    IDP_IMAGE_EFFECT_PIXEL_CLR, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_GMA, KAL_FALSE, // [MAUI_02136095] 
    
    IDP_IMAGE_EFFECT_PIXEL_GAMMA, 0,
    
    IDP_IMAGE_EFFECT_PIXEL_OFF0, 0,
    IDP_IMAGE_EFFECT_PIXEL_OFF1, 0,
    IDP_IMAGE_EFFECT_PIXEL_OFF2, 0,
    IDP_IMAGE_EFFECT_PIXEL_OFF3, 0,
    IDP_IMAGE_EFFECT_PIXEL_OFF4, 0,
    IDP_IMAGE_EFFECT_PIXEL_OFF5, 0,
    IDP_IMAGE_EFFECT_PIXEL_OFF6, 0,
    IDP_IMAGE_EFFECT_PIXEL_OFF7, 0,
    
    IDP_IMAGE_EFFECT_PIXEL_SLP0, 0x10,
    IDP_IMAGE_EFFECT_PIXEL_SLP1, 0x10,
    IDP_IMAGE_EFFECT_PIXEL_SLP2, 0x10,
    IDP_IMAGE_EFFECT_PIXEL_SLP3, 0x10,
    IDP_IMAGE_EFFECT_PIXEL_SLP4, 0x10,
    IDP_IMAGE_EFFECT_PIXEL_SLP5, 0x10,
    IDP_IMAGE_EFFECT_PIXEL_SLP6, 0x10,
    IDP_IMAGE_EFFECT_PIXEL_SLP7, 0x10,
    
    0);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_start_all(key);
  ASSERT(KAL_TRUE == result);
  
  while (1)
  {
    result = idp_image_effect_pixel_is_busy(key, &busy);
    ASSERT(KAL_TRUE == result);
    
    if (KAL_TRUE == busy)
    {
    }
    else
    {
      break;
    }
  }
  
  result = idp_image_effect_pixel_close(key);
  ASSERT(KAL_TRUE == result);
}

static void
effect_dec_grayinv(void)
{
  kal_bool result;
  kal_bool busy;
  kal_uint32 key;
  
  result = idp_image_effect_pixel_open(&key);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_config(
    key,

    IDP_IMAGE_EFFECT_PIXEL_INTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_INTMEM_SIZE, 0,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_SIZE, 0,
    
    IDP_IMAGE_EFFECT_PIXEL_SRC_ADDRESS, ipp_config_data.src_address,
    IDP_IMAGE_EFFECT_PIXEL_SRC_WIDTH, ipp_config_data.src_width,
    IDP_IMAGE_EFFECT_PIXEL_SRC_HEIGHT, ipp_config_data.src_height,
    IDP_IMAGE_EFFECT_PIXEL_SRC_COLOR_FMT, ipp_config_data.src_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_DEST_ADDRESS, ipp_config_data.dest_address,
    IDP_IMAGE_EFFECT_PIXEL_DEST_COLOR_FMT, ipp_config_data.dest_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_ROT_ANGLE, IMG_ROT_ANGLE_0,
    
    IDP_IMAGE_EFFECT_PIXEL_HSA, IDP_IMAGE_EFFECT_PIXEL_HSA_COLORIZE,
    IDP_IMAGE_EFFECT_PIXEL_CBA, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_INV, KAL_TRUE,
    IDP_IMAGE_EFFECT_PIXEL_CLR, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_GMA, KAL_FALSE,
    
    IDP_IMAGE_EFFECT_PIXEL_COLORIZE_U, 0,
    IDP_IMAGE_EFFECT_PIXEL_COLORIZE_V, 0,
    
    0);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_start_all(key);
  ASSERT(KAL_TRUE == result);
  
  while (1)
  {
    result = idp_image_effect_pixel_is_busy(key, &busy);
    ASSERT(KAL_TRUE == result);
    
    if (KAL_TRUE == busy)
    {
    }
    else
    {
      break;
    }
  }
  
  result = idp_image_effect_pixel_close(key);
  ASSERT(KAL_TRUE == result);
}
#endif


#if defined(DRV_PIXEL_EFFECT_SUPPORT)
static void
adj_dec_hue(void)
{
  kal_bool result;
  kal_bool busy;
  kal_uint32 key;
  idp_image_effect_pixel_hsa_enum_t hsa;
  kal_uint8 c11 = 0, c12 = 0, c21 = 0, c22 = 0;
  
  if (0 == image_adj_dec_para.adj_level)
  {
    hsa = IDP_IMAGE_EFFECT_PIXEL_HSA_NONE;
  }
  else
  {
    hsa = IDP_IMAGE_EFFECT_PIXEL_HSA_HUE;
  }
  
  if (image_adj_dec_para.adj_level <= 90)
  {
    c11 =  sine[90 - image_adj_dec_para.adj_level];
    c12 =  sine[image_adj_dec_para.adj_level];
    c21 = -sine[image_adj_dec_para.adj_level];
    c22 =  sine[90 - image_adj_dec_para.adj_level];
  }
  else if ((image_adj_dec_para.adj_level > 90) &&
           (image_adj_dec_para.adj_level <= 180))
  {
    c11 = -sine[image_adj_dec_para.adj_level - 90];
    c12 =  sine[180 - image_adj_dec_para.adj_level];
    c21 = -sine[180 - image_adj_dec_para.adj_level];
    c22 = -sine[image_adj_dec_para.adj_level - 90];
  }
  else if ((image_adj_dec_para.adj_level > 180) &&
           (image_adj_dec_para.adj_level <= 270))
  {
    c11 = -sine[270 - image_adj_dec_para.adj_level];
    c12 = -sine[image_adj_dec_para.adj_level - 180];
    c21 =  sine[image_adj_dec_para.adj_level - 180];
    c22 = -sine[270 - image_adj_dec_para.adj_level];
  }
  else if ((image_adj_dec_para.adj_level > 270) &&
           (image_adj_dec_para.adj_level <= 360))
  {
    c11 =  sine[image_adj_dec_para.adj_level - 270];
    c12 = -sine[360 - image_adj_dec_para.adj_level];
    c21 =  sine[360 - image_adj_dec_para.adj_level];
    c22 =  sine[image_adj_dec_para.adj_level - 270];
  }
  else
  {
    ASSERT(0);
  }
  
  result = idp_image_effect_pixel_open(&key);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_config(
    key,
    
    IDP_IMAGE_EFFECT_PIXEL_INTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_INTMEM_SIZE, 0,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_SIZE, 0,
    
    IDP_IMAGE_EFFECT_PIXEL_SRC_ADDRESS, ipp_config_data.src_address,
    IDP_IMAGE_EFFECT_PIXEL_SRC_WIDTH, ipp_config_data.src_width,
    IDP_IMAGE_EFFECT_PIXEL_SRC_HEIGHT, ipp_config_data.src_height,
    IDP_IMAGE_EFFECT_PIXEL_SRC_COLOR_FMT, ipp_config_data.src_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_DEST_ADDRESS, ipp_config_data.dest_address,
    IDP_IMAGE_EFFECT_PIXEL_DEST_COLOR_FMT, ipp_config_data.dest_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_ROT_ANGLE, IMG_ROT_ANGLE_0,
    
    IDP_IMAGE_EFFECT_PIXEL_HSA, hsa,
    
    IDP_IMAGE_EFFECT_PIXEL_C11, c11,
    IDP_IMAGE_EFFECT_PIXEL_C12, c12,
    IDP_IMAGE_EFFECT_PIXEL_C21, c21,
    IDP_IMAGE_EFFECT_PIXEL_C22, c22,
    
    IDP_IMAGE_EFFECT_PIXEL_CBA, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_INV, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_CLR, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_GMA, KAL_FALSE,
    
    0);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_start_all(key);
  ASSERT(KAL_TRUE == result);
  
  while (1)
  {
    result = idp_image_effect_pixel_is_busy(key, &busy);
    ASSERT(KAL_TRUE == result);
    
    if (KAL_TRUE == busy)
    {
    }
    else
    {
      break;
    }
  }
  
  result = idp_image_effect_pixel_close(key);
  ASSERT(KAL_TRUE == result);
}

static void
adj_dec_saturation(void)
{
  kal_bool result;
  kal_bool busy;
  kal_uint32 key;
  idp_image_effect_pixel_hsa_enum_t hsa;
  kal_uint16 satadj = image_adj_dec_para.adj_level;
  
  if (satadj < 128)
  {
    satadj /= 4;
  }
  else if ((satadj >= 128) && (satadj < 256))
  {
    satadj = ((satadj - 128) * 3 / 4) + 32;
  }
  else
  {
    ASSERT(0);
  }
  
  if (128 == image_adj_dec_para.adj_level)
  {
    hsa = IDP_IMAGE_EFFECT_PIXEL_HSA_NONE;
  }
  else
  {
    hsa = IDP_IMAGE_EFFECT_PIXEL_HSA_SAT;
  }
  
  result = idp_image_effect_pixel_open(&key);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_config(
    key,

    IDP_IMAGE_EFFECT_PIXEL_INTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_INTMEM_SIZE, 0,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_SIZE, 0,
    
    IDP_IMAGE_EFFECT_PIXEL_SRC_ADDRESS, ipp_config_data.src_address,
    IDP_IMAGE_EFFECT_PIXEL_SRC_WIDTH, ipp_config_data.src_width,
    IDP_IMAGE_EFFECT_PIXEL_SRC_HEIGHT, ipp_config_data.src_height,
    IDP_IMAGE_EFFECT_PIXEL_SRC_COLOR_FMT, ipp_config_data.src_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_DEST_ADDRESS, ipp_config_data.dest_address,
    IDP_IMAGE_EFFECT_PIXEL_DEST_COLOR_FMT, ipp_config_data.dest_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_ROT_ANGLE, IMG_ROT_ANGLE_0,
    
    IDP_IMAGE_EFFECT_PIXEL_HSA, hsa,
    
    IDP_IMAGE_EFFECT_PIXEL_SATADJ, satadj,
    
    IDP_IMAGE_EFFECT_PIXEL_CBA, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_INV, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_CLR, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_GMA, KAL_FALSE,
    
    0);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_start_all(key);
  ASSERT(KAL_TRUE == result);
  
  while (1)
  {
    result = idp_image_effect_pixel_is_busy(key, &busy);
    ASSERT(KAL_TRUE == result);
    
    if (KAL_TRUE == busy)
    {
    }
    else
    {
      break;
    }
  }
  
  result = idp_image_effect_pixel_close(key);
  ASSERT(KAL_TRUE == result);
}

static void
adj_dec_gamma(void)
{
  kal_bool result;
  kal_bool busy;
  kal_uint32 key;
  
  result = idp_image_effect_pixel_open(&key);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_config(
    key,

    IDP_IMAGE_EFFECT_PIXEL_INTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_INTMEM_SIZE, 0,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_SIZE, 0,
    
    IDP_IMAGE_EFFECT_PIXEL_SRC_ADDRESS, ipp_config_data.src_address,
    IDP_IMAGE_EFFECT_PIXEL_SRC_WIDTH, ipp_config_data.src_width,
    IDP_IMAGE_EFFECT_PIXEL_SRC_HEIGHT, ipp_config_data.src_height,
    IDP_IMAGE_EFFECT_PIXEL_SRC_COLOR_FMT, ipp_config_data.src_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_DEST_ADDRESS, ipp_config_data.dest_address,
    IDP_IMAGE_EFFECT_PIXEL_DEST_COLOR_FMT, ipp_config_data.dest_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_ROT_ANGLE, IMG_ROT_ANGLE_0,
    
    IDP_IMAGE_EFFECT_PIXEL_HSA, IDP_IMAGE_EFFECT_PIXEL_HSA_NONE,
    
    IDP_IMAGE_EFFECT_PIXEL_GAMMA, gamma[image_adj_dec_para.adj_level][0],
    
    IDP_IMAGE_EFFECT_PIXEL_OFF0, gamma[image_adj_dec_para.adj_level][1],
    IDP_IMAGE_EFFECT_PIXEL_OFF1, gamma[image_adj_dec_para.adj_level][2],
    IDP_IMAGE_EFFECT_PIXEL_OFF2, gamma[image_adj_dec_para.adj_level][3],
    IDP_IMAGE_EFFECT_PIXEL_OFF3, gamma[image_adj_dec_para.adj_level][4],
    IDP_IMAGE_EFFECT_PIXEL_OFF4, gamma[image_adj_dec_para.adj_level][5],
    IDP_IMAGE_EFFECT_PIXEL_OFF5, gamma[image_adj_dec_para.adj_level][6],
    IDP_IMAGE_EFFECT_PIXEL_OFF6, gamma[image_adj_dec_para.adj_level][7],
    IDP_IMAGE_EFFECT_PIXEL_OFF7, gamma[image_adj_dec_para.adj_level][8],
    
    IDP_IMAGE_EFFECT_PIXEL_SLP0, gamma[image_adj_dec_para.adj_level][9],
    IDP_IMAGE_EFFECT_PIXEL_SLP1, gamma[image_adj_dec_para.adj_level][10],
    IDP_IMAGE_EFFECT_PIXEL_SLP2, gamma[image_adj_dec_para.adj_level][11],
    IDP_IMAGE_EFFECT_PIXEL_SLP3, gamma[image_adj_dec_para.adj_level][12],
    IDP_IMAGE_EFFECT_PIXEL_SLP4, gamma[image_adj_dec_para.adj_level][13],
    IDP_IMAGE_EFFECT_PIXEL_SLP5, gamma[image_adj_dec_para.adj_level][14],
    IDP_IMAGE_EFFECT_PIXEL_SLP6, gamma[image_adj_dec_para.adj_level][15],
    IDP_IMAGE_EFFECT_PIXEL_SLP7, gamma[image_adj_dec_para.adj_level][16],
    
    IDP_IMAGE_EFFECT_PIXEL_CBA, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_INV, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_CLR, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_GMA, KAL_TRUE,
    
    0);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_start_all(key);
  ASSERT(KAL_TRUE == result);
  
  while (1)
  {
    result = idp_image_effect_pixel_is_busy(key, &busy);
    ASSERT(KAL_TRUE == result);
    
    if (KAL_TRUE == busy)
    {
    }
    else
    {
      break;
    }
  }
  
  result = idp_image_effect_pixel_close(key);
  ASSERT(KAL_TRUE == result);
}

static void
adj_dec_coloradj(void)
{
#ifndef MED_NOT_PRESENT
  kal_bool result;
  kal_bool busy;
  kal_uint32 key;
  
  kal_uint8 r1x = 0;
  kal_uint8 r1y = 0;
  kal_uint8 r2x = 0;
  kal_uint8 r2y = 0;
  kal_uint8 r0slp = 0;
  kal_uint8 r1slp = 0;
  kal_uint8 r2slp = 0;
  kal_uint8 g1x = 0;
  kal_uint8 g1y = 0;
  kal_uint8 g2x = 0;
  kal_uint8 g2y = 0;
  kal_uint8 g0slp = 0;
  kal_uint8 g1slp = 0;
  kal_uint8 g2slp = 0;
  kal_uint8 b1x = 0;
  kal_uint8 b1y = 0;
  kal_uint8 b2x = 0;
  kal_uint8 b2y = 0;
  kal_uint8 b0slp = 0;
  kal_uint8 b1slp = 0;
  kal_uint8 b2slp = 0;
  
  switch (image_adj_dec_para.effect_index)
  {
  case CAM_ADJ_DEC_ADJR:
    r1x = coloradj_rb[image_adj_dec_para.adj_level][0];
    r1y = coloradj_rb[image_adj_dec_para.adj_level][1];
    r2x = coloradj_rb[image_adj_dec_para.adj_level][2];
    r2y = coloradj_rb[image_adj_dec_para.adj_level][3];
    r0slp = coloradj_rb[image_adj_dec_para.adj_level][4];
    r1slp = coloradj_rb[image_adj_dec_para.adj_level][5];
    r2slp = coloradj_rb[image_adj_dec_para.adj_level][6];
    g1x = 0;
    g1y = 0;
    g2x = 0;
    g2y = 0;
    g0slp = 16;
    g1slp = 16;
    g2slp = 16;
    b1x = 0;
    b1y = 0;
    b2x = 0;
    b2y = 0;
    b0slp = 16;
    b1slp = 16;
    b2slp = 16;
    break;
    
  case CAM_ADJ_DEC_ADJG:
    r1x = 0;
    r1y = 0;
    r2x = 0;
    r2y = 0;
    r0slp = 16;
    r1slp = 16;
    r2slp = 16;
    g1x = coloradj_g[image_adj_dec_para.adj_level][0];
    g1y = coloradj_g[image_adj_dec_para.adj_level][1];
    g2x = coloradj_g[image_adj_dec_para.adj_level][2];
    g2y = coloradj_g[image_adj_dec_para.adj_level][3];
    g0slp = coloradj_g[image_adj_dec_para.adj_level][4];
    g1slp = coloradj_g[image_adj_dec_para.adj_level][5];
    g2slp = coloradj_g[image_adj_dec_para.adj_level][6];
    b1x = 0;
    b1y = 0;
    b2x = 0;
    b2y = 0;
    b0slp = 16;
    b1slp = 16;
    b2slp = 16;
    break;
    
  case CAM_ADJ_DEC_ADJB:
    r1x = 0;
    r1y = 0;
    r2x = 0;
    r2y = 0;
    r0slp = 16;
    r1slp = 16;
    r2slp = 16;
    g1x = 0;
    g1y = 0;
    g2x = 0;
    g2y = 0;
    g0slp = 16;
    g1slp = 16;
    g2slp = 16;
    b1x = coloradj_rb[image_adj_dec_para.adj_level][0];
    b1y = coloradj_rb[image_adj_dec_para.adj_level][1];
    b2x = coloradj_rb[image_adj_dec_para.adj_level][2];
    b2y = coloradj_rb[image_adj_dec_para.adj_level][3];
    b0slp = coloradj_rb[image_adj_dec_para.adj_level][4];
    b1slp = coloradj_rb[image_adj_dec_para.adj_level][5];
    b2slp = coloradj_rb[image_adj_dec_para.adj_level][6];
    break;
    
  default:
    ASSERT(0);
    break;
  }
    
  result = idp_image_effect_pixel_open(&key);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_config(
    key,

    IDP_IMAGE_EFFECT_PIXEL_INTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_INTMEM_SIZE, 0,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_SIZE, 0,
    
    IDP_IMAGE_EFFECT_PIXEL_SRC_ADDRESS, ipp_config_data.src_address,
    IDP_IMAGE_EFFECT_PIXEL_SRC_WIDTH, ipp_config_data.src_width,
    IDP_IMAGE_EFFECT_PIXEL_SRC_HEIGHT, ipp_config_data.src_height,
    IDP_IMAGE_EFFECT_PIXEL_SRC_COLOR_FMT, ipp_config_data.src_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_DEST_ADDRESS, ipp_config_data.dest_address,
    IDP_IMAGE_EFFECT_PIXEL_DEST_COLOR_FMT, ipp_config_data.dest_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_ROT_ANGLE, IMG_ROT_ANGLE_0,
    
    IDP_IMAGE_EFFECT_PIXEL_HSA, IDP_IMAGE_EFFECT_PIXEL_HSA_NONE,
    IDP_IMAGE_EFFECT_PIXEL_CBA, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_INV, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_CLR, KAL_TRUE,
    IDP_IMAGE_EFFECT_PIXEL_GMA, KAL_FALSE,
    
    IDP_IMAGE_EFFECT_PIXEL_R1X, r1x,
    IDP_IMAGE_EFFECT_PIXEL_R1Y, r1y,
    IDP_IMAGE_EFFECT_PIXEL_R2X, r2x,
    IDP_IMAGE_EFFECT_PIXEL_R2Y, r2y,
    IDP_IMAGE_EFFECT_PIXEL_R0SLP, r0slp,
    IDP_IMAGE_EFFECT_PIXEL_R1SLP, r1slp,
    IDP_IMAGE_EFFECT_PIXEL_R2SLP, r2slp,
    IDP_IMAGE_EFFECT_PIXEL_G1X, g1x,
    IDP_IMAGE_EFFECT_PIXEL_G1Y, g1y,
    IDP_IMAGE_EFFECT_PIXEL_G2X, g2x,
    IDP_IMAGE_EFFECT_PIXEL_G2Y, g2y,
    IDP_IMAGE_EFFECT_PIXEL_G0SLP, g0slp,
    IDP_IMAGE_EFFECT_PIXEL_G1SLP, g1slp,
    IDP_IMAGE_EFFECT_PIXEL_G2SLP, g2slp,
    IDP_IMAGE_EFFECT_PIXEL_B1X, b1x,
    IDP_IMAGE_EFFECT_PIXEL_B1Y, b1y,
    IDP_IMAGE_EFFECT_PIXEL_B2X, b2x,
    IDP_IMAGE_EFFECT_PIXEL_B2Y, b2y,
    IDP_IMAGE_EFFECT_PIXEL_B0SLP, b0slp,
    IDP_IMAGE_EFFECT_PIXEL_B1SLP, b1slp,
    IDP_IMAGE_EFFECT_PIXEL_B2SLP, b2slp,
    
    0);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_start_all(key);
  ASSERT(KAL_TRUE == result);
  
  while (1)
  {
    result = idp_image_effect_pixel_is_busy(key, &busy);
    ASSERT(KAL_TRUE == result);
    
    if (KAL_TRUE == busy)
    {
    }
    else
    {
      break;
    }
  }
  
  result = idp_image_effect_pixel_close(key);
  ASSERT(KAL_TRUE == result);
#endif
}

static void
adj_dec_brightness_contrast(void)
{
#ifndef MED_NOT_PRESENT
  kal_bool result;
  kal_bool busy;
  kal_uint32 key;

  kal_bool cba;
  kal_uint8 bright = 0;
  kal_uint8 dark = 0;
  kal_uint16 contrast = 0;
  
  if (128 == image_adj_dec_para.adj_level)
  {
    cba = KAL_FALSE;
  }
  else
  {
    cba = KAL_TRUE;
  }
  
  if (CAM_ADJ_DEC_BRIGHTNESS == image_adj_dec_para.effect_index)
  {
    if ((image_adj_dec_para.adj_level >= 128) &&
        (image_adj_dec_para.adj_level < 256))
    {
      bright = (image_adj_dec_para.adj_level - 128) << 1;
      dark = 0;
    }
    else if (image_adj_dec_para.adj_level < 128)
    {
      dark = ((128 - image_adj_dec_para.adj_level) << 1) - 1;
      bright = 0;
    }
    else
    {
      ASSERT(0);
    }
    
    contrast = 32;
  }
  else if (CAM_ADJ_DEC_CONTRAST == image_adj_dec_para.effect_index)
  {
    if (image_adj_dec_para.adj_level < 128)
    {
      image_adj_dec_para.adj_level /= 4;
    }
    else if ((image_adj_dec_para.adj_level >= 128) &&
             (image_adj_dec_para.adj_level < 256))
    {
      image_adj_dec_para.adj_level = ((image_adj_dec_para.adj_level - 128) * 3 / 4) + 32;
    }
    else
    {
      ASSERT(0);
    }
    
    contrast = image_adj_dec_para.adj_level;
    bright = 0;
    dark = 0;
  }
  
  result = idp_image_effect_pixel_open(&key);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_config(
    key,

    IDP_IMAGE_EFFECT_PIXEL_INTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_INTMEM_SIZE, 0,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_START_ADDRESS, NULL,
    IDP_IMAGE_EFFECT_PIXEL_EXTMEM_SIZE, 0,
    
    IDP_IMAGE_EFFECT_PIXEL_SRC_ADDRESS, ipp_config_data.src_address,
    IDP_IMAGE_EFFECT_PIXEL_SRC_WIDTH, ipp_config_data.src_width,
    IDP_IMAGE_EFFECT_PIXEL_SRC_HEIGHT, ipp_config_data.src_height,
    IDP_IMAGE_EFFECT_PIXEL_SRC_COLOR_FMT, ipp_config_data.src_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_DEST_ADDRESS, ipp_config_data.dest_address,
    IDP_IMAGE_EFFECT_PIXEL_DEST_COLOR_FMT, ipp_config_data.dest_color_fmt,
    
    IDP_IMAGE_EFFECT_PIXEL_ROT_ANGLE, IMG_ROT_ANGLE_0,
    
    IDP_IMAGE_EFFECT_PIXEL_HSA, IDP_IMAGE_EFFECT_PIXEL_HSA_NONE,
    IDP_IMAGE_EFFECT_PIXEL_CBA, cba,
    IDP_IMAGE_EFFECT_PIXEL_INV, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_CLR, KAL_FALSE,
    IDP_IMAGE_EFFECT_PIXEL_GMA, KAL_FALSE,
    
    IDP_IMAGE_EFFECT_PIXEL_BRIGHT, bright,
    IDP_IMAGE_EFFECT_PIXEL_DARK, dark,
    IDP_IMAGE_EFFECT_PIXEL_CONTRAST, contrast,
    
    0);
  ASSERT(KAL_TRUE == result);
  
  result = idp_image_effect_pixel_start_all(key);
  ASSERT(KAL_TRUE == result);
  
  while (1)
  {
    result = idp_image_effect_pixel_is_busy(key, &busy);
    ASSERT(KAL_TRUE == result);
    
    if (KAL_TRUE == busy)
    {
    }
    else
    {
      break;
    }
  }
  
  result = idp_image_effect_pixel_close(key);
  ASSERT(KAL_TRUE == result);
#endif
}
#endif

#ifndef MED_NOT_PRESENT
img_color_fmt_rgb_enum_t convert_ipp_color_format_to_idp_color_format(IPP_COLOR_FORMAT_ENUM ipp_color_foramt)
{
   switch (ipp_color_foramt)
   {
   case IPP_COLOR_FORMAT_RGB565:
   	return IMG_COLOR_FMT_RGB565;
   
   case IPP_COLOR_FORMAT_RGB888:
   	return IMG_COLOR_FMT_RGB888;

  default:
    ASSERT(0);
    break;   
   }

   return IMG_COLOR_FMT_RGB565;
}
#endif

/* ========================================================
 *                   Exported functions
 * ======================================================== */
void
image_effect_dec_process(
  IMAGE_EFFECT_DEC_STRUCT *effect_dec_para)
{
#ifndef MED_NOT_PRESENT
  image_effect_dec_para.dest1_buffer_address = effect_dec_para->dest1_buffer_address;
  image_effect_dec_para.dest2_buffer_address = effect_dec_para->dest2_buffer_address;
  
  ipp_config_data.src_color_fmt = convert_ipp_color_format_to_idp_color_format((IPP_COLOR_FORMAT_ENUM) effect_dec_para->src_color_fmt);
  ipp_config_data.dest_color_fmt = convert_ipp_color_format_to_idp_color_format((IPP_COLOR_FORMAT_ENUM) effect_dec_para->dest_color_fmt);
  ipp_config_data.src_address = effect_dec_para->source_buffer_address;
  ipp_config_data.dest_address = effect_dec_para->dest1_buffer_address;
  ipp_config_data.src_width = effect_dec_para->image_width;
  ipp_config_data.src_height = effect_dec_para->image_height;
  	
  switch (ipp_config_data.dest_color_fmt)
  {
  case IMG_COLOR_FMT_RGB565:
  case IMG_COLOR_FMT_RGB888:
    break;
    
  default:
    ASSERT(0);
    break;
  }
  
  switch (effect_dec_para->effect_index)
  {  	
#if defined(DRV_PIXEL_EFFECT_SUPPORT)
  case CAM_EFFECT_DEC_GRAYSCALE:
    /* This effect only uses Camera register, hence, no
     * need to open IDP, config and close.
     */
    effect_dec_grayscale();
    break;
    
  case CAM_EFFECT_DEC_SEPIA:
    effect_dec_sepia();
    break;
    
  case CAM_EFFECT_DEC_SEPIAGREEN:
    effect_dec_sepiagreen();
    break;
    
  case CAM_EFFECT_DEC_SEPIABLUE:
    effect_dec_sepiablue();
    break;
    
  case CAM_EFFECT_DEC_COLORINV:
    effect_dec_colorinv();
    break;
    
  case CAM_EFFECT_DEC_GRAYINV:
    effect_dec_grayinv();
    break;
  default:
    ASSERT(0);
    break;
#endif	
  }
#endif
}

void
image_adj_dec_process(
  IMAGE_EFFECT_DEC_STRUCT *effect_dec_para)
{
#ifndef MED_NOT_PRESENT
  image_adj_dec_para.adj_level = effect_dec_para->adj_level;
  image_adj_dec_para.effect_index = effect_dec_para->effect_index;
  
  ipp_config_data.src_color_fmt = effect_dec_para->src_color_fmt;
  ipp_config_data.dest_color_fmt = effect_dec_para->dest_color_fmt;
  ipp_config_data.src_address = effect_dec_para->source_buffer_address;
  ipp_config_data.dest_address = effect_dec_para->dest1_buffer_address;
  ipp_config_data.src_width = effect_dec_para->image_width;
  ipp_config_data.src_height = effect_dec_para->image_height;
  
  switch (ipp_config_data.dest_color_fmt)
  {
  case IMG_COLOR_FMT_RGB565:
  case IMG_COLOR_FMT_RGB888:
    break;
    
  default:
    ASSERT(0);
    break;
  }
  
  switch (effect_dec_para->effect_index)
  {
#if defined(DRV_PIXEL_EFFECT_SUPPORT)
  case CAM_ADJ_DEC_HUE:
    adj_dec_hue();
    break;
    
  case CAM_ADJ_DEC_SATURATION:
    adj_dec_saturation();
    break;
    
  case CAM_ADJ_DEC_GAMMA:
    adj_dec_gamma();
    break;
    
  case CAM_ADJ_DEC_ADJR:
    adj_dec_coloradj();
    break;
    
  case CAM_ADJ_DEC_ADJG:
    adj_dec_coloradj();
    break;
    
  case CAM_ADJ_DEC_ADJB:
    adj_dec_coloradj();
    break;
    
  case CAM_ADJ_DEC_CONTRAST:
    adj_dec_brightness_contrast();
    break;
    
  case CAM_ADJ_DEC_BRIGHTNESS:
    adj_dec_brightness_contrast();
    break;
#endif
    
  default:
    ASSERT(0);
    break;
  }
#endif
}

#endif //#if defined(DRV_IDP_SUPPORT)
