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
 *
 * Project:
 * --------
 *	 Maui
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
 * 09 30 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 11 23 2010 hung-wen.hsieh
 * removed!
 * .
 *
 * 10 18 2010 ct.fang
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * add to source control recursely
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_imgdma_ibr1_mt6238_h__
#define __idp_imgdma_ibr1_mt6238_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include "reg_base.h"
#include "drv_features_mdp.h"
#include "drv_comm.h"
#include <idp_define.h>

#if defined(DRV_IDP_6238_SERIES)

#include "idp_imgdma.h"
#include <idp_core.h>
#include "img_common_enum.h"

/** \defgroup imgdma_ibr1 IBR1
 *
 * \brief This module defines the functionalities which IBR1
 * has.
 *
 * The input type of IBR1 includes:
 * - RGB565
 * - RGB888
 * - BGR888
 * @{
 */
#define IMGDMA_IBR1_START_REG         (IMGDMA_base + 0x0500)
#define IMGDMA_IBR1_CTRL_REG          (IMGDMA_base + 0x0504)
#define IMGDMA_IBR1_BASE_ADDR_REG     (IMGDMA_base + 0x0508)
#define IMGDMA_IBR1_PIXEL_NUMBER_REG  (IMGDMA_base + 0x050C)
#define IMGDMA_IBR1_REMAIN_PIXEL_REG  (IMGDMA_base + 0x0510)

#define REG_IMGDMA_IBR1_START                *((volatile unsigned int *)(IMGDMA_base + 0x0500))
#define REG_IMGDMA_IBR1_CTRL                 *((volatile unsigned int *)(IMGDMA_base + 0x0504))
#define REG_IMGDMA_IBR1_BASE_ADDR            *((volatile unsigned int *)(IMGDMA_base + 0x0508))
#define REG_IMGDMA_IBR1_PIXEL_NUMBER         *((volatile unsigned int *)(IMGDMA_base + 0x050C))
#define REG_IMGDMA_IBR1_REMAIN_PIXEL_NUMBER  *((volatile unsigned int *)(IMGDMA_base + 0x0510))

/* bit mapping of IBR1 control register */
#define IMGDMA_IBR1_INT_BIT           0x00000001
#define IMGDMA_IBR1_DATA_FORMAT_BIT   0x00000002
#define IMGDMA_IBR1_DATA_ORDER_BIT    0x00000004

#define IMGDMA_IBR1_INPUT_RGB565   0x00000000
#define IMGDMA_IBR1_INPUT_RGB888   0x00000002

/* macros of IBR1 start register */
/**
 * \brief Start IBR1
 */
#define START_IBR1()                            \
  do { REG_IMGDMA_IBR1_START = 1; } while(0)
/**
 * \brief Stop IBR1
 */
#define STOP_IBR1()                             \
  do { REG_IMGDMA_IBR1_START = 0; } while(0)

/* macros of IBR1 control register */
/**
 * \brief Check if IBR1 is started or not.
 */
#define IS_IMGDMA_IBR1_START()                         \
  ((0x1 == (REG_IMGDMA_IBR1_START & 0x1))              \
   ? KAL_TRUE                                          \
   : KAL_FALSE)

#define SET_IMGDMA_IBR1_DATA_ORDER_RGB888                             \
  do { REG_IMGDMA_IBR1_CTRL |= IMGDMA_IBR1_DATA_ORDER_BIT; } while(0)

#define SET_IMGDMA_IBR1_DATA_ORDER_BGR888                               \
  do { REG_IMGDMA_IBR1_CTRL &= ~IMGDMA_IBR1_DATA_ORDER_BIT; } while(0)

#define SET_IMGDMA_IBR1_DATA_RGB565                                     \
  do { REG_IMGDMA_IBR1_CTRL &= ~IMGDMA_IBR1_DATA_FORMAT_BIT; } while(0)

#define SET_IMGDMA_IBR1_DATA_RGB888                                     \
  do { REG_IMGDMA_IBR1_CTRL |= IMGDMA_IBR1_DATA_FORMAT_BIT; } while(0)

#define ENABLE_IMGDMA_IBR1_INT                                  \
  do { REG_IMGDMA_IBR1_CTRL |= IMGDMA_IBR1_INT_BIT; } while(0)

#define DISABLE_IMGDMA_IBR1_INT                                 \
  do { REG_IMGDMA_IBR1_CTRL &= ~IMGDMA_IBR1_INT_BIT; } while(0)

/**
 * \brief IBR1 structure
 *
 * Programmers can use this structure to set up IBR1.
 */
typedef struct
{
  kal_uint32 base_addr; /**< base address */
  kal_uint32 pixel_number; /**< pixel numbers */
  
  //img_color_fmt_rgb_enum_t color_fmt; /**< RGB565 or RGB888 */
  kal_uint32 color_fmt; /**< RGB565 or RGB888 */ 
  
  kal_bool intr_en; /**< interrup enable */
  idp_lisr_intr_cb_t intr_cb;
  idp_lisr_intr_cb_param_t intr_cb_param;
} idp_imgdma_ibr1_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_ibr1)

extern void *idp_imgdma_ibr1_intr_cb_param;
extern void (*idp_imgdma_ibr1_intr_cb)(void *);

extern kal_bool idp_imgdma_ibr1_config_real(
    idp_imgdma_ibr1_struct * const ibr1_struct,
    kal_bool const config_to_hardware);

extern kal_bool idp_imgdma_ibr1_stop_real(
  idp_imgdma_ibr1_struct const * const ibr1_struct);

extern kal_bool idp_imgdma_ibr1_get_working_mem_real(
  kal_bool const use_internal_mem,
  idp_imgdma_ibr1_struct const * const ibr1_struct,
  kal_bool const do_alloc,
  kal_uint32 const max_allowable_size);

extern void idp_imgdma_ibr1_close_real(void);
/** @} */

#endif // defined(DRV_IDP_6238_SERIES)

#endif // __idp_imgdma_ibr1_mt6238_h__
