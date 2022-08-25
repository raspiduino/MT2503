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

#ifndef __idp_imgdma_irt1_mt6238_h__
#define __idp_imgdma_irt1_mt6238_h__

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
#include <mt6238/idp_mem.h>

/* ===================================================
 *                        IRT1
 * =================================================== */

/** \defgroup imgdma_irt1 IRT1
 * @{
 */
#define IMGDMA_IRT1_START_REG         (IMGDMA_base + 0x0D00)
#define IMGDMA_IRT1_CTRL_REG          (IMGDMA_base + 0x0D04)
#define IMGDMA_IRT1_FIFO_REG          (IMGDMA_base + 0x0D08)
#define IMGDMA_IRT1_WIDTH_REG         (IMGDMA_base + 0x0D0C)
#define IMGDMA_IRT1_HEIGHT_REG        (IMGDMA_base + 0x0D10)
#define IMGDMA_IRT1_FIFOLEN_REG       (IMGDMA_base + 0x0D14)
#define IMGDMA_IRT1_WRHCNT_REG        (IMGDMA_base + 0x0D18)
#define IMGDMA_IRT1_WRVCNT_REG        (IMGDMA_base + 0x0D1C)
#define IMGDMA_IRT1_RDHCNT_REG        (IMGDMA_base + 0x0D20)
#define IMGDMA_IRT1_RDVCNT_REG        (IMGDMA_base + 0x0D24)
#define IMGDMA_IRT1_FIFOCNT_REG       (IMGDMA_base + 0x0D28)
#define IMGDMA_IRT1_WDYIDX_REG        (IMGDMA_base + 0x0D2C)
#define IMGDMA_IRT1_RDYIDX_REG        (IMGDMA_base + 0x0D30)
#define IMGDMA_IRT1_BASE_ADD1_REG     (IMGDMA_base + 0x0D34)
#define IMGDMA_IRT1_BASE_ADD2_REG     (IMGDMA_base + 0x0D38)
#define IMGDMA_IRT1_LINE_PITCH1_REG   (IMGDMA_base + 0x0D3C)
#define IMGDMA_IRT1_LINE_PITCH2_REG   (IMGDMA_base + 0x0D40)
#define IMGDMA_IRT1_FRAME_PITCH1_REG  (IMGDMA_base + 0x0D44)
#define IMGDMA_IRT1_FRAME_PITCH2_REG  (IMGDMA_base + 0x0D48)
#define IMGDMA_IRT1_ALPHA_REG         (IMGDMA_base + 0x0D4C)
#define IMGDMA_IRT1_HCNT_REG          (IMGDMA_base + 0x0D50)
#define IMGDMA_IRT1_VCNT_REG          (IMGDMA_base + 0x0D54)
#if defined(MT6268)
#define IMGDMA_IRT1_HIGHP_THRESH_REG  (IMGDMA_base + 0x0DFC)
#endif // chip option


#define REG_IMGDMA_IRT1_START         *((volatile unsigned int *)(IMGDMA_base + 0x0D00))
#define REG_IMGDMA_IRT1_CTRL          *((volatile unsigned int *)(IMGDMA_base + 0x0D04))
#define REG_IMGDMA_IRT1_FIFO          *((volatile unsigned int *)(IMGDMA_base + 0x0D08))
#define REG_IMGDMA_IRT1_WIDTH         *((volatile unsigned int *)(IMGDMA_base + 0x0D0C))
#define REG_IMGDMA_IRT1_HEIGHT        *((volatile unsigned int *)(IMGDMA_base + 0x0D10))
#define REG_IMGDMA_IRT1_FIFOLEN       *((volatile unsigned int *)(IMGDMA_base + 0x0D14))
#define REG_IMGDMA_IRT1_WRHCNT        *((volatile unsigned int *)(IMGDMA_base + 0x0D18))
#define REG_IMGDMA_IRT1_WRVCNT        *((volatile unsigned int *)(IMGDMA_base + 0x0D1C))
#define REG_IMGDMA_IRT1_RDHCNT        *((volatile unsigned int *)(IMGDMA_base + 0x0D20))
#define REG_IMGDMA_IRT1_RDVCNT        *((volatile unsigned int *)(IMGDMA_base + 0x0D24))
#define REG_IMGDMA_IRT1_FIFOCNT       *((volatile unsigned int *)(IMGDMA_base + 0x0D28))
#define REG_IMGDMA_IRT1_WDYIDX        *((volatile unsigned int *)(IMGDMA_base + 0x0D2C))
#define REG_IMGDMA_IRT1_RDYIDX        *((volatile unsigned int *)(IMGDMA_base + 0x0D30))
#define REG_IMGDMA_IRT1_BASE_ADD1     *((volatile unsigned int *)(IMGDMA_base + 0x0D34))
#define REG_IMGDMA_IRT1_BASE_ADD2     *((volatile unsigned int *)(IMGDMA_base + 0x0D38))
#define REG_IMGDMA_IRT1_LINE_PITCH1   *((volatile unsigned int *)(IMGDMA_base + 0x0D3C))
#define REG_IMGDMA_IRT1_LINE_PITCH2   *((volatile unsigned int *)(IMGDMA_base + 0x0D40))
#define REG_IMGDMA_IRT1_FRAME_PITCH1  *((volatile unsigned int *)(IMGDMA_base + 0x0D44))
#define REG_IMGDMA_IRT1_FRAME_PITCH2  *((volatile unsigned int *)(IMGDMA_base + 0x0D48))
#define REG_IMGDMA_IRT1_ALPHA         *((volatile unsigned int *)(IMGDMA_base + 0x0D4C))
#define REG_IMGDMA_IRT1_HCNT          *((volatile unsigned int *)(IMGDMA_base + 0x0D50))
#define REG_IMGDMA_IRT1_VCNT          *((volatile unsigned int *)(IMGDMA_base + 0x0D54))
#if defined(MT6268)
#define REG_IMGDMA_IRT1_HIGHP_THRESH  *((volatile unsigned int *) IMGDMA_IRT1_HIGHP_THRESH_REG)
#endif // chip option

#define IMGDMA_IRT1_CTRL_INT_BIT           0X00000001
#define IMGDMA_IRT1_CTRL_AUTOSTR_BIT       0X00000002
#define IMGDMA_IRT1_CTRL_ROT_MASK          0X0000000C
#define IMGDMA_IRT1_CTRL_FLIP_BIT          0X00000010
#define IMGDMA_IRT1_CTRL_FMT_MASK          0X00000180
#define IMGDMA_IRT1_CTRL_PITCH_BIT         0X00000200
#define IMGDMA_IRT1_CTRL_LCD_BIT           0X00000400
#if defined(MT6268)
#define IMGDMA_IRT1_CTRL_ORDER_BIT         0x00000800
#define IMGDMA_IRT1_CTRL_SCRSEL_BIT        0x00001000
#define IMGDMA_IRT1_CTRL_HIGH_PRI_EN       0x00002000
#endif // chip option

/**
 * \brief Check if IRT1 is started or not.
 */
#define IS_IMGDMA_IRT1_START()                         \
  ((0x1 == (REG_IMGDMA_IRT1_START & 0x1))              \
   ? KAL_TRUE                                          \
   : KAL_FALSE)

#define ENABLE_IRT1_INT()                             \
  do {                                                \
    REG_IMGDMA_IRT1_CTRL |= IMGDMA_IRT1_CTRL_INT_BIT; \
  } while(0)

#define DISABLE_IRT1_INT()                              \
  do {                                                  \
    REG_IMGDMA_IRT1_CTRL &= ~IMGDMA_IRT1_CTRL_INT_BIT;  \
  } while(0)

#define ENABLE_IRT1_AUTOSTART()                           \
  do {                                                    \
    REG_IMGDMA_IRT1_CTRL |= IMGDMA_IRT1_CTRL_AUTOSTR_BIT; \
  } while(0)

#define DISABLE_IRT1_AUTOSTART()                            \
  do {                                                      \
    REG_IMGDMA_IRT1_CTRL &= ~IMGDMA_IRT1_CTRL_AUTOSTR_BIT;  \
  } while(0)

#define SET_IRT1_ROTATE_DIR(rot)                        \
  do {                                                  \
    REG_IMGDMA_IRT1_CTRL &= ~IMGDMA_IRT1_CTRL_ROT_MASK; \
    REG_IMGDMA_IRT1_CTRL |= (rot << 2);                 \
  } while(0)

#define ENABLE_IRT1_FLIP()                              \
  do {                                                  \
    REG_IMGDMA_IRT1_CTRL |= IMGDMA_IRT1_CTRL_FLIP_BIT;  \
  } while(0)

#define DISABLE_IRT1_FLIP()                             \
  do {                                                  \
    REG_IMGDMA_IRT1_CTRL &= ~IMGDMA_IRT1_CTRL_FLIP_BIT; \
  } while(0)

#define SET_IRT1_OUTPUT_FMT(fmt)                        \
  do {                                                  \
    REG_IMGDMA_IRT1_CTRL &= ~IMGDMA_IRT1_CTRL_FMT_MASK; \
    REG_IMGDMA_IRT1_CTRL |= (fmt << 7);                 \
  } while(0)

#define ENABLE_IRT1_PITCH()                             \
  do {                                                  \
    REG_IMGDMA_IRT1_CTRL |= IMGDMA_IRT1_CTRL_PITCH_BIT; \
  } while(0)

#define DISABLE_IRT1_PITCH()                              \
  do {                                                    \
    REG_IMGDMA_IRT1_CTRL &= ~IMGDMA_IRT1_CTRL_PITCH_BIT;  \
  } while(0)

#define ENABLE_IRT1_LCD_TRIGGER()                     \
  do {                                                \
    REG_IMGDMA_IRT1_CTRL |= IMGDMA_IRT1_CTRL_LCD_BIT; \
  } while(0)

#define DISABLE_IRT1_LCD_TRIGGER()                      \
  do {                                                  \
    REG_IMGDMA_IRT1_CTRL &= ~IMGDMA_IRT1_CTRL_LCD_BIT;  \
  } while(0)

#define START_IRT1()                            \
  do {                                          \
    REG_IMGDMA_IRT1_START = 1;                  \
  } while(0)

#define STOP_IRT1()                             \
  do {                                          \
    REG_IMGDMA_IRT1_START = 0;                  \
  } while(0)

#define SET_IMGDMA_IRT1_FIFO_ADDR(addr)         \
  do {                                          \
    REG_IMGDMA_IRT1_FIFO = addr;                \
  } while(0)

#define SET_IMGDMA_IRT1_WIDTH(width)            \
  do {                                          \
    REG_IMGDMA_IRT1_WIDTH = width;              \
  } while(0)

#define SET_IMGDMA_IRT1_HEIGHT(height)          \
  do {                                          \
    REG_IMGDMA_IRT1_HEIGHT = height;            \
  } while(0)

#define SET_IMGDMA_IRT1_FIFOLEN(len)            \
  do {                                          \
    REG_IMGDMA_IRT1_FIFOLEN = len;              \
  } while(0)

#define SET_IMGDMA_IRT1_BUFF1_ADDR(addr)        \
  do {                                          \
    REG_IMGDMA_IRT1_BASE_ADD1 = addr;           \
  } while(0)

#define SET_IMGDMA_IRT1_BUFF2_ADDR(addr)        \
  do {                                          \
    REG_IMGDMA_IRT1_BASE_ADD2 = addr;           \
  } while(0)

#define SET_IMGDMA_IRT1_BUFF1_LINE_PITCH(num)   \
  do {                                          \
    REG_IMGDMA_IRT1_LINE_PITCH1 = num;          \
  } while(0)

#define SET_IMGDMA_IRT1_BUFF2_LINE_PITCH(num)   \
  do {                                          \
    REG_IMGDMA_IRT1_LINE_PITCH2 = num;          \
  } while(0)

#define SET_IMGDMA_IRT1_BUFF1_FRAME_PITCH(num)  \
  do {                                          \
    REG_IMGDMA_IRT1_FRAME_PITCH1 = num;         \
  } while(0)

#define SET_IMGDMA_IRT1_BUFF2_FRAME_PITCH(num)  \
  do {                                          \
    REG_IMGDMA_IRT1_FRAME_PITCH2 = num;         \
  } while(0)

#define SET_IMGDMA_IRT1_ALPHA(value)            \
  do {                                          \
    REG_IMGDMA_IRT1_ALPHA = value;              \
  } while(0)

enum
{
  IDP_IMGDMA_IRT1_MASK_INTR_EN,
  IDP_IMGDMA_IRT1_MASK_INTR_CB,
  IDP_IMGDMA_IRT1_MASK_INTR_CB_PARAM,
  IDP_IMGDMA_IRT1_MASK_RESTART,
  IDP_IMGDMA_IRT1_MASK_PITCH_ENABLE,
  IDP_IMGDMA_IRT1_MASK_TRIGGER_LCD,
  IDP_IMGDMA_IRT1_MASK_WORK_MEM_LINE_COUNT,
  IDP_IMGDMA_IRT1_MASK_WORK_MEM_ADDR,
  IDP_IMGDMA_IRT1_MASK_WIDTH,
  IDP_IMGDMA_IRT1_MASK_HEIGHT,
  IDP_IMGDMA_IRT1_MASK_FRAME1_BASE_ADDR,
  IDP_IMGDMA_IRT1_MASK_FRAME2_BASE_ADDR,
  IDP_IMGDMA_IRT1_MASK_BUF1_LINE_PITCH,
  IDP_IMGDMA_IRT1_MASK_BUF2_LINE_PITCH,
  IDP_IMGDMA_IRT1_MASK_BUF1_FRAME_PITCH,
  IDP_IMGDMA_IRT1_MASK_BUF2_FRAME_PITCH,
  IDP_IMGDMA_IRT1_MASK_ALPHA,
  IDP_IMGDMA_IRT1_MASK_COLOR_FMT,
  IDP_IMGDMA_IRT1_MASK_ROT_ANGLE,
  IDP_IMGDMA_IRT1_MASK_FLIP,
#if defined(MT6268)
  IDP_IMGDMA_IRT1_MASK_HW_FRAME_SYNC,
#endif // chip option
  IDP_IMGDMA_IRT1_MASK_LCD_RD_PTR_ADVANCE,

  IDP_IMGDMA_IRT1_MASK_LAST
};

/**
 * \brief IRT1 structure
 *
 * Programmers can use this structure to set up IRT1.
 */
typedef struct
{
  kal_uint32                mask[(IDP_IMGDMA_IRT1_MASK_LAST / 32) + 1];
  
  kal_bool                  intr_en; /**< enable int or not */
  idp_lisr_intr_cb_t        intr_cb;
  idp_lisr_intr_cb_param_t  intr_cb_param;

  kal_bool                  restart; /**< restart or not */
  kal_bool                  pitch_enable; /**< enable pitch or not */
  kal_bool                  trigger_lcd; /**< trigger lcd or not */
  
  kal_uint32                work_mem_line_count;
  kal_uint32                work_mem_addr;
  
  kal_uint16                width; /**< width */
  kal_uint16                height; /**< height */
  kal_uint32                frame1_base_addr; /**< base1 addr */
  kal_uint32                frame2_base_addr; /**< base2 addr */
  kal_uint32                buf1_line_pitch; /**< buf1 line pitch */
  kal_uint32                buf2_line_pitch; /**< buf2 line pitch */
  kal_uint32                buf1_frame_pitch; /**< buf1 frame pitch */
  kal_uint32                buf2_frame_pitch; /**< buf2 frame pitch */
  kal_uint8                 alpha; /**< alpha value */
  //img_color_fmt_rgb_enum_t  color_fmt;
  kal_uint32	            color_fmt;
  img_rot_angle_enum_t      rot_angle; /**< rotate direction */
  kal_bool                  flip; /**< flip or not */
#if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
  kal_bool                  hw_frame_sync; /**< KAL_TRUE: enable HW frame sync; KAL_FALSE: disable. */
#endif // #if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
} idp_imgdma_irt1_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_irt1)

extern void *idp_imgdma_irt1_intr_cb_param;
extern void (*idp_imgdma_irt1_intr_cb)(void *);

extern kal_bool idp_imgdma_irt1_config_real(
    idp_imgdma_irt1_struct * const irt1_struct,
    kal_bool const config_to_hardware);

extern kal_bool idp_imgdma_irt1_stop_real(
  idp_imgdma_irt1_struct const * const irt1_struct);

extern kal_bool idp_imgdma_irt1_get_working_mem_real(
  kal_bool const use_internal_mem,
  idp_imgdma_irt1_struct * const irt1_struct,
  kal_bool const do_alloc,
  kal_uint32 const max_allowable_size);

extern kal_bool idp_imgdma_irt1_is_busy_real(
  kal_bool * const busy,
  idp_imgdma_irt1_struct const * const irt1_struct);

extern void idp_imgdma_irt1_close_real(void);


/** @} */

#endif // defined(DRV_IDP_6238_SERIES)

#endif // __idp_imgdma_irt1_mt6238_h__
