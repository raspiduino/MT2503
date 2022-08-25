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

#ifndef __idp_imgdma_ibr2_mt6238_h__
#define __idp_imgdma_ibr2_mt6238_h__

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

/* ===================================================
 *                        IBR2
 * =================================================== */
/** \defgroup imgdma_ibr2 IBR2
 * @{
 */
#define IMGDMA_IBR2_START_REG         (IMGDMA_base + 0x0600)
#define IMGDMA_IBR2_CTRL_REG          (IMGDMA_base + 0x0604)
#define IMGDMA_IBR2_BASE_ADDR_REG     (IMGDMA_base + 0x0608)
#define IMGDMA_IBR2_BASE2_ADDR_REG    (IMGDMA_base + 0x060c)
#define IMGDMA_IBR2_WIDTH_REG         (IMGDMA_base + 0x0610)
#define IMGDMA_IBR2_HEIGHT_REG        (IMGDMA_base + 0x0614)
#define IMGDMA_IBR2_PIXEL_NUMBER_REG  (IMGDMA_base + 0x0618)

#define REG_IMGDMA_IBR2_START         *((volatile unsigned int *)(IMGDMA_base + 0x0600))
#define REG_IMGDMA_IBR2_CTRL          *((volatile unsigned int *)(IMGDMA_base + 0x0604))
#define REG_IMGDMA_IBR2_BASE_ADDR     *((volatile unsigned int *)(IMGDMA_base + 0x0608))
#define REG_IMGDMA_IBR2_BASE2_ADDR    *((volatile unsigned int *)(IMGDMA_base + 0x060c))
#define REG_IMGDMA_IBR2_WIDTH         *((volatile unsigned int *)(IMGDMA_base + 0x0610))
#define REG_IMGDMA_IBR2_HEIGHT        *((volatile unsigned int *)(IMGDMA_base + 0x0614))
#define REG_IMGDMA_IBR2_PIXEL_NUMBER  *((volatile unsigned int *)(IMGDMA_base + 0x0618))

/* bit mapping of IBR2 control register */
#define IMGDMA_IBR2_INT_BIT           0x00000001
#define IMGDMA_IBR2_AUTO_RESTART_BIT  0x00000002
#define IMGDMA_IBR2_ROTATE_MASK       0x0000000C
#define IMGDMA_IBR2_FLIP_BIT          0x00000010
#define IMGDMA_IBR2_FMT_MASK          0x00000060
#define IMGDMA_IBR2_CTRL_SWZ          0X00000080

/* macros of IBR2 start register */
#define START_IBR2() do { REG_IMGDMA_IBR2_START = 1; } while(0)
#define STOP_IBR2()  do { REG_IMGDMA_IBR2_START = 0; } while(0)

#define ENABLE_IMGDMA_IBR2_INT()       do { REG_IMGDMA_IBR2_CTRL |= IMGDMA_IBR2_INT_BIT; } while(0)
#define DISABLE_IMGDMA_IBR2_INT()      do { REG_IMGDMA_IBR2_CTRL &= ~IMGDMA_IBR2_INT_BIT; } while(0)
#define ENABLE_IMGDMA_IBR2_RESTART()   do { REG_IMGDMA_IBR2_CTRL |= IMGDMA_IBR2_AUTO_RESTART_BIT; } while(0)
#define DISABLE_IMGDMA_IBR2_RESTART()  do { REG_IMGDMA_IBR2_CTRL &= ~IMGDMA_IBR2_AUTO_RESTART_BIT; } while(0)

/**
 * \brief Check if IBR2 is started or not.
 */
#define IS_IMGDMA_IBR2_START()                         \
  ((0x1 == (REG_IMGDMA_IBR2_START & 0x1))       \
   ? KAL_TRUE                                   \
   : KAL_FALSE)

#define SET_IMGDMA_IBR2_ROTATE(rotate)                \
  do {                                                \
    REG_IMGDMA_IBR2_CTRL &= ~IMGDMA_IBR2_ROTATE_MASK; \
    REG_IMGDMA_IBR2_CTRL |= (rotate<<2);              \
  } while(0)

#define ENABLE_IMGDMA_IBR2_FLIP()  do { REG_IMGDMA_IBR2_CTRL |= IMGDMA_IBR2_FLIP_BIT; } while(0)
#define DISABLE_IMGDMA_IBR2_FLIP() do { REG_IMGDMA_IBR2_CTRL &= ~IMGDMA_IBR2_FLIP_BIT; } while(0)

#define SET_IMGDMA_IBR2_LCD_FMT(fmt)                \
  do {                                              \
    REG_IMGDMA_IBR2_CTRL &= ~IMGDMA_IBR2_FMT_MASK;  \
    REG_IMGDMA_IBR2_CTRL |= (fmt<<5);               \
  } while(0)

enum
{
  IDP_IMGDMA_IBR2_MASK_INTR_EN,
  IDP_IMGDMA_IBR2_MASK_INTR_CB,
  IDP_IMGDMA_IBR2_MASK_INTR_CB_PARAM,
  IDP_IMGDMA_IBR2_MASK_AUTO_RESTART,
  IDP_IMGDMA_IBR2_MASK_FLIP,
  IDP_IMGDMA_IBR2_MASK_ROT_ANGLE,
  IDP_IMGDMA_IBR2_MASK_COLOR_FMT,
  IDP_IMGDMA_IBR2_MASK_BASE1_ADDR,
  IDP_IMGDMA_IBR2_MASK_BASE2_ADDR,
  IDP_IMGDMA_IBR2_MASK_WIDTH,
  IDP_IMGDMA_IBR2_MASK_HEIGHT,
  
  IDP_IMGDMA_IBR2_MASK_LAST
};

/**
 * \brief IBR2 structure
 *
 * Programmers can use this structure to set up IBR2.
 */
typedef struct
{
  kal_uint32 mask[(IDP_IMGDMA_IBR2_MASK_LAST / 32) + 1];
  
  kal_bool intr_en; /**< interrup enable */
  idp_lisr_intr_cb_t intr_cb;
  idp_lisr_intr_cb_param_t intr_cb_param;
  
  kal_bool auto_restart; /**< auto restart enable */
  kal_bool flip; /**< flip enable */
  
  img_rot_angle_enum_t rot_angle; /**< rotate value */
  /** RGB565, RGB888, ARGB8888 */
  //img_color_fmt_rgb_enum_t color_fmt;
  kal_uint32 color_fmt;
  
  kal_uint32 base1_addr; /**< buffer 1 base address */
  kal_uint32 base2_addr; /**< buffer 2 base address */
  kal_uint32 width; /**< source width */
  kal_uint32 height; /**< source height */
} idp_imgdma_ibr2_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_ibr2)

extern void *idp_imgdma_ibr2_intr_cb_param;
extern void (*idp_imgdma_ibr2_intr_cb)(void *);

extern kal_bool idp_imgdma_ibr2_config_real(
    idp_imgdma_ibr2_struct * const ibr2_struct,
  kal_bool const config_to_hardware);

extern kal_bool idp_imgdma_ibr2_stop_real(
  idp_imgdma_ibr2_struct const * const ibr2_struct);

extern kal_bool idp_imgdma_ibr2_start_real(
  idp_imgdma_ibr2_struct const * const ibr2_struct);

extern kal_bool idp_imgdma_ibr2_is_busy_real(
  kal_bool * const busy,
  idp_imgdma_ibr2_struct const * const ibr2_struct);

extern kal_bool idp_imgdma_ibr2_get_working_mem_real(
  kal_bool const use_internal_mem,
  idp_imgdma_ibr2_struct const * const ibr2_struct,
  kal_bool const do_alloc,
  kal_uint32 const max_allowable_size);

extern void idp_imgdma_ibr2_close_real(void);

/** @} */

#endif // defined(DRV_IDP_6238_SERIES)

#endif // __idp_imgdma_ibr2_mt6238_h__
