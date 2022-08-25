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
 * 04 18 2011 hung-wen.hsieh
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

#ifndef __idp_imgdma_irt2_mt6238_h__
#define __idp_imgdma_irt2_mt6238_h__

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
#include "idp_hw_common.h"

/* ===================================================
 *                        IRT2
 * =================================================== */

/** \defgroup imgdma_irt2 IRT2
 * @{
 */
#define IMGDMA_IRT2_START_REG         (IMGDMA_base + 0x0E00)
#define IMGDMA_IRT2_CTRL_REG          (IMGDMA_base + 0x0E04)
#define IMGDMA_IRT2_FIFO_REG          (IMGDMA_base + 0x0E08)
#define IMGDMA_IRT2_WIDTH_REG         (IMGDMA_base + 0x0E0C)
#define IMGDMA_IRT2_HEIGHT_REG        (IMGDMA_base + 0x0E10)
#define IMGDMA_IRT2_ALPHA_REG         (IMGDMA_base + 0x0E14)
#define IMGDMA_IRT2_FIFOLEN_REG       (IMGDMA_base + 0x0E18)
#define IMGDMA_IRT2_WRHCNT_REG        (IMGDMA_base + 0x0E1C)
#define IMGDMA_IRT2_WRVCNT_REG        (IMGDMA_base + 0x0E20)
#define IMGDMA_IRT2_RDHCNT_REG        (IMGDMA_base + 0x0E24)
#define IMGDMA_IRT2_RDVCNT_REG        (IMGDMA_base + 0x0E28)
#define IMGDMA_IRT2_FIFOCNT_REG       (IMGDMA_base + 0x0E2C)
#define IMGDMA_IRT2_WDYIDX_REG        (IMGDMA_base + 0x0E30)
#define IMGDMA_IRT2_RDYIDX_REG        (IMGDMA_base + 0x0E34)

#define REG_IMGDMA_IRT2_START         *((volatile unsigned int *)(IMGDMA_base + 0x0E00))
#define REG_IMGDMA_IRT2_CTRL          *((volatile unsigned int *)(IMGDMA_base + 0x0E04))
#define REG_IMGDMA_IRT2_FIFO          *((volatile unsigned int *)(IMGDMA_base + 0x0E08))
#define REG_IMGDMA_IRT2_WIDTH         *((volatile unsigned int *)(IMGDMA_base + 0x0E0C))
#define REG_IMGDMA_IRT2_HEIGHT        *((volatile unsigned int *)(IMGDMA_base + 0x0E10))
#define REG_IMGDMA_IRT2_ALPHA         *((volatile unsigned int *)(IMGDMA_base + 0x0E14))
#define REG_IMGDMA_IRT2_FIFOLEN       *((volatile unsigned int *)(IMGDMA_base + 0x0E18))
#define REG_IMGDMA_IRT2_WRHCNT        *((volatile unsigned int *)(IMGDMA_base + 0x0E1C))
#define REG_IMGDMA_IRT2_WRVCNT        *((volatile unsigned int *)(IMGDMA_base + 0x0E20))
#define REG_IMGDMA_IRT2_RDHCNT        *((volatile unsigned int *)(IMGDMA_base + 0x0E24))
#define REG_IMGDMA_IRT2_RDVCNT        *((volatile unsigned int *)(IMGDMA_base + 0x0E28))
#define REG_IMGDMA_IRT2_FIFOCNT       *((volatile unsigned int *)(IMGDMA_base + 0x0E2C))
#define REG_IMGDMA_IRT2_WDYIDX        *((volatile unsigned int *)(IMGDMA_base + 0x0E30))
#define REG_IMGDMA_IRT2_RDYIDX        *((volatile unsigned int *)(IMGDMA_base + 0x0E34))

#define IMGDMA_IRT2_CTRL_INT_BIT           0X00000001
#define IMGDMA_IRT2_CTRL_AUTOSTR_BIT       0X00000002
#define IMGDMA_IRT2_CTRL_ROT_MASK          0X0000000C
#define IMGDMA_IRT2_CTRL_FLIP_BIT          0X00000010
#define IMGDMA_IRT2_CTRL_INFMT_MASK        0X00000060
#define IMGDMA_IRT2_CTRL_OUTFMT_MASK       0X00000080
#define IMGDMA_IRT2_CTRL_LCD_BIT           0X00000100
#define IMGDMA_IRT2_CTRL_CTRL_PSEL_BIT     0X00000200

/**
 * \brief Check if IRT2 is started or not.
 */
#define IS_IMGDMA_IRT2_START()                         \
  ((0x1 == (REG_IMGDMA_IRT2_START & 0x1))              \
   ? KAL_TRUE                                          \
   : KAL_FALSE)

#define ENABLE_IRT2_INT()                             \
  do {                                                \
    REG_IMGDMA_IRT2_CTRL |= IMGDMA_IRT2_CTRL_INT_BIT; \
  } while(0)

#define DISABLE_IRT2_INT()                              \
  do {                                                  \
    REG_IMGDMA_IRT2_CTRL &= ~IMGDMA_IRT2_CTRL_INT_BIT;  \
  } while(0)

#define ENABLE_IRT2_AUTOSTART()                           \
  do {                                                    \
    REG_IMGDMA_IRT2_CTRL |= IMGDMA_IRT2_CTRL_AUTOSTR_BIT; \
  } while(0)

#define DISABLE_IRT2_AUTOSTART()                            \
  do {                                                      \
    REG_IMGDMA_IRT2_CTRL &= ~IMGDMA_IRT2_CTRL_AUTOSTR_BIT;  \
  } while(0)

#define SET_IRT2_ROTATE_DIR(rot)                        \
  do {                                                  \
    REG_IMGDMA_IRT2_CTRL &= ~IMGDMA_IRT2_CTRL_ROT_MASK; \
    REG_IMGDMA_IRT2_CTRL |= (rot << 2);                 \
  } while(0)

#define ENABLE_IRT2_FLIP()                              \
  do {                                                  \
    REG_IMGDMA_IRT2_CTRL |= IMGDMA_IRT2_CTRL_FLIP_BIT;  \
  } while(0)

#define DISABLE_IRT2_FLIP()                             \
  do {                                                  \
    REG_IMGDMA_IRT2_CTRL &= ~IMGDMA_IRT2_CTRL_FLIP_BIT; \
  } while(0)

#define SET_IRT2_INPUT_FMT(fmt)                           \
  do {                                                    \
    REG_IMGDMA_IRT2_CTRL &= ~IMGDMA_IRT2_CTRL_INFMT_MASK; \
    REG_IMGDMA_IRT2_CTRL |= (fmt << 5);                   \
  } while(0)

#define SET_IRT2_OUTPUT_FMT(fmt)                            \
  do {                                                      \
    REG_IMGDMA_IRT2_CTRL &= ~IMGDMA_IRT2_CTRL_OUTFMT_MASK;  \
    REG_IMGDMA_IRT2_CTRL |= (fmt << 8);                     \
  } while(0)


#define ENABLE_IRT2_LCD_TRIGGER()                     \
  do {                                                \
    REG_IMGDMA_IRT2_CTRL |= IMGDMA_IRT2_CTRL_LCD_BIT; \
  } while(0)

#define DISABLE_IRT2_LCD_TRIGGER()                      \
  do {                                                  \
    REG_IMGDMA_IRT2_CTRL &= ~IMGDMA_IRT2_CTRL_LCD_BIT;  \
  } while(0)

#define SET_IRT2_OUT2Y2R0()                                   \
  do {                                                        \
    REG_IMGDMA_IRT2_CTRL &= ~IMGDMA_IRT2_CTRL_CTRL_PSEL_BIT;  \
  } while(0)

#define SET_IRT2_OUT2LCD()                                  \
  do {                                                      \
    REG_IMGDMA_IRT2_CTRL |= IMGDMA_IRT2_CTRL_CTRL_PSEL_BIT; \
  } while(0)

#define START_IRT2()                            \
  do {                                          \
    REG_IMGDMA_IRT2_START = 1;                  \
  } while(0)

#define STOP_IRT2()                             \
  do {                                          \
    REG_IMGDMA_IRT2_START = 0;                  \
  } while(0)

#define SET_IMGDMA_IRT2_FIFO_ADDR(addr)         \
  do {                                          \
    REG_IMGDMA_IRT2_FIFO = addr;                \
  } while(0)

#define SET_IMGDMA_IRT2_WIDTH(width)            \
  do {                                          \
    REG_IMGDMA_IRT2_WIDTH = width;              \
  } while(0)

#define SET_IMGDMA_IRT2_HEIGHT(height)          \
  do {                                          \
    REG_IMGDMA_IRT2_HEIGHT = height;            \
  } while(0)

#define SET_IMGDMA_IRT2_ALPHA(alpha)            \
  do {                                          \
    REG_IMGDMA_IRT2_ALPHA = alpha;              \
  } while(0)

#define SET_IMGDMA_IRT2_FIFOLEN(len)            \
  do {                                          \
    REG_IMGDMA_IRT2_FIFOLEN = len;              \
  } while(0)

typedef enum
{
  IRT2_OUTPUT_FMT_SW_ARGB = 0,
  IRT2_OUTPUT_FMT_HW_ARGB = 1
} IMGDMA_IRT2_OUTPUT_FMT_ENUM;

enum
{
  IDP_IMGDMA_IRT2_MASK_INTR_EN,
  IDP_IMGDMA_IRT2_MASK_INTR_CB,
  IDP_IMGDMA_IRT2_MASK_INTR_CB_PARAM,
  IDP_IMGDMA_IRT2_MASK_RESTART,
  IDP_IMGDMA_IRT2_MASK_TRIGGER_LCD,
  IDP_IMGDMA_IRT2_MASK_FIFO_BASE_ADDR,
  IDP_IMGDMA_IRT2_MASK_WIDTH,
  IDP_IMGDMA_IRT2_MASK_HEIGHT,
  IDP_IMGDMA_IRT2_MASK_FIFO_LEN,
  IDP_IMGDMA_IRT2_MASK_ALPHA,
  IDP_IMGDMA_IRT2_MASK_OUT_FMT,
  IDP_IMGDMA_IRT2_MASK_IN_COLOR_FMT,
  IDP_IMGDMA_IRT2_MASK_ROT_ANGLE,
  IDP_IMGDMA_IRT2_MASK_FLIP,
  IDP_IMGDMA_IRT2_MASK_OUTPUT,
  
  IDP_IMGDMA_IRT2_MASK_LAST
};

/**
 * \brief IRT2 structure
 *
 * Programmers can use this structure to set up IRT2.
 */
typedef struct
{
  kal_uint32                  mask[(IDP_IMGDMA_IRT2_MASK_LAST / 32) + 1];
  
  kal_bool                    intr_en; /**< enable int or not */
  idp_lisr_intr_cb_t          intr_cb;
  idp_lisr_intr_cb_param_t    intr_cb_param;

  kal_bool                    restart; /**< restart or not */
  kal_bool                    trigger_lcd; /**< trigger lcd or not */
  kal_uint32                  fifo_base_addr; /**< fifo addr */
  kal_uint16                  width; /**< width */
  kal_uint16                  height; /**< height */
  kal_uint16                  fifo_len; /**< fifo len */
  kal_uint8                   alpha; /**< alpha value */
  
  IMGDMA_IRT2_OUTPUT_FMT_ENUM out_fmt;
  //img_color_fmt_rgb_enum_t    in_color_fmt;
  kal_uint32     			  in_color_fmt;
  
  img_rot_angle_enum_t        rot_angle; /**< rotate direction */
  kal_bool                    flip; /**< flip or not */
  idp_module_enum_t           output;
} idp_imgdma_irt2_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_irt2)

extern void *idp_imgdma_irt2_intr_cb_param;
extern void (*idp_imgdma_irt2_intr_cb)(void *);

extern kal_bool idp_imgdma_irt2_config_real(
    idp_imgdma_irt2_struct * const irt2_struct,
    kal_bool const config_to_hardware);

extern kal_bool idp_imgdma_irt2_stop_real(
  idp_imgdma_irt2_struct const * const irt2_struct);

extern kal_bool idp_imgdma_irt2_start_real(
  idp_imgdma_irt2_struct const * const irt2_struct);

extern kal_bool idp_imgdma_irt2_get_working_mem_size_real(
  idp_imgdma_irt2_struct * const irt2_struct,
  kal_uint32 * const size);

extern kal_bool idp_imgdma_irt2_get_working_mem_real(
  kal_bool const use_internal_mem,
  idp_imgdma_irt2_struct * const irt2_struct,
  kal_bool const do_alloc,
  kal_uint32 const max_allowable_size);

extern kal_bool idp_imgdma_irt2_is_busy_real(
  kal_bool * const busy,
  idp_imgdma_irt2_struct const * const irt2_struct);

extern void idp_imgdma_irt2_close_real(void);

extern kal_bool 
idp_imgdma_irt2_is_hw_trigger_pending(void);

/** @} */

#endif // defined(DRV_IDP_6238_SERIES)

#endif // __idp_imgdma_irt2_mt6238_h__
