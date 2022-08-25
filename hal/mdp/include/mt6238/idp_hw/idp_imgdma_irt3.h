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

#ifndef __idp_imgdma_irt3_mt6238_h__
#define __idp_imgdma_irt3_mt6238_h__

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
 *                        IRT3
 * =================================================== */

/** \defgroup imgdma_irt3 IRT3
 * @{
 */
#define IMGDMA_IRT3_START_REG         (IMGDMA_base + 0x0F00)
#define IMGDMA_IRT3_CTRL_REG          (IMGDMA_base + 0x0F04)
#define IMGDMA_IRT3_FIFO_REG          (IMGDMA_base + 0x0F08)
#define IMGDMA_IRT3_WIDTH_REG         (IMGDMA_base + 0x0F0C)
#define IMGDMA_IRT3_HEIGHT_REG        (IMGDMA_base + 0x0F10)
#define IMGDMA_IRT3_FIFOLEN_REG       (IMGDMA_base + 0x0F14)
#define IMGDMA_IRT3_WRHCNT_REG        (IMGDMA_base + 0x0F18)
#define IMGDMA_IRT3_WRVCNT_REG        (IMGDMA_base + 0x0F1C)
#define IMGDMA_IRT3_RDHCNT_REG        (IMGDMA_base + 0x0F20)
#define IMGDMA_IRT3_RDVCNT_REG        (IMGDMA_base + 0x0F24)
#define IMGDMA_IRT3_FIFOCNT_REG       (IMGDMA_base + 0x0F28)
#define IMGDMA_IRT3_WDYIDX_REG        (IMGDMA_base + 0x0F2C)
#define IMGDMA_IRT3_RDYIDX_REG        (IMGDMA_base + 0x0F30)
#define IMGDMA_IRT3_BASE_ADDR1_REG    (IMGDMA_base + 0x0F34)
#define IMGDMA_IRT3_BASE_ADDR2_REG    (IMGDMA_base + 0x0F38)
#define IMGDMA_IRT3_LINE_PITCH1_REG   (IMGDMA_base + 0x0F3C)
#define IMGDMA_IRT3_LINE_PITCH2_REG   (IMGDMA_base + 0x0F40)
#define IMGDMA_IRT3_FRAME_PITCH1_REG  (IMGDMA_base + 0x0F44)
#define IMGDMA_IRT3_FRAME_PITCH2_REG  (IMGDMA_base + 0x0F48)
#define IMGDMA_IRT3_ALPHA_REG         (IMGDMA_base + 0x0F4C)
#define IMGDMA_IRT3_HCNT_REG          (IMGDMA_base + 0x0F50)
#define IMGDMA_IRT3_VCNT_REG          (IMGDMA_base + 0x0F54)


#define REG_IMGDMA_IRT3_START         *((volatile unsigned int *)(IMGDMA_base + 0x0F00))
#define REG_IMGDMA_IRT3_CTRL          *((volatile unsigned int *)(IMGDMA_base + 0x0F04))
#define REG_IMGDMA_IRT3_FIFO          *((volatile unsigned int *)(IMGDMA_base + 0x0F08))
#define REG_IMGDMA_IRT3_WIDTH         *((volatile unsigned int *)(IMGDMA_base + 0x0F0C))
#define REG_IMGDMA_IRT3_HEIGHT        *((volatile unsigned int *)(IMGDMA_base + 0x0F10))
#define REG_IMGDMA_IRT3_FIFOLEN       *((volatile unsigned int *)(IMGDMA_base + 0x0F14))
#define REG_IMGDMA_IRT3_WRHCNT        *((volatile unsigned int *)(IMGDMA_base + 0x0F18))
#define REG_IMGDMA_IRT3_WRVCNT        *((volatile unsigned int *)(IMGDMA_base + 0x0F1C))
#define REG_IMGDMA_IRT3_RDHCNT        *((volatile unsigned int *)(IMGDMA_base + 0x0F20))
#define REG_IMGDMA_IRT3_RDVCNT        *((volatile unsigned int *)(IMGDMA_base + 0x0F24))
#define REG_IMGDMA_IRT3_FIFOCNT       *((volatile unsigned int *)(IMGDMA_base + 0x0F28))
#define REG_IMGDMA_IRT3_WDYIDX        *((volatile unsigned int *)(IMGDMA_base + 0x0F2C))
#define REG_IMGDMA_IRT3_RDYIDX        *((volatile unsigned int *)(IMGDMA_base + 0x0F30))
#define REG_IMGDMA_IRT3_BASE_ADDR1    *((volatile unsigned int *)(IMGDMA_base + 0x0F34))
#define REG_IMGDMA_IRT3_BASE_ADDR2    *((volatile unsigned int *)(IMGDMA_base + 0x0F38))
#define REG_IMGDMA_IRT3_LINE_PITCH1   *((volatile unsigned int *)(IMGDMA_base + 0x0F3C))
#define REG_IMGDMA_IRT3_LINE_PITCH2   *((volatile unsigned int *)(IMGDMA_base + 0x0F40))
#define REG_IMGDMA_IRT3_FRAME_PITCH1  *((volatile unsigned int *)(IMGDMA_base + 0x0F44))
#define REG_IMGDMA_IRT3_FRAME_PITCH2  *((volatile unsigned int *)(IMGDMA_base + 0x0F48))
#define REG_IMGDMA_IRT3_ALPHA         *((volatile unsigned int *)(IMGDMA_base + 0x0F4C))
#define REG_IMGDMA_IRT3_HCNT          *((volatile unsigned int *)(IMGDMA_base + 0x0F50))
#define REG_IMGDMA_IRT3_VCNT          *((volatile unsigned int *)(IMGDMA_base + 0x0F54))

#define IMGDMA_IRT3_CTRL_INT_BIT           0X00000001
#define IMGDMA_IRT3_CTRL_AUTOSTR_BIT       0X00000002
#define IMGDMA_IRT3_CTRL_ROT_MASK          0X0000000C
#define IMGDMA_IRT3_CTRL_FLIP_BIT          0X00000010
#define IMGDMA_IRT3_CTRL_OUTFMT_MASK       0X00000180
#define IMGDMA_IRT3_CTRL_PITCH_BIT         0X00000200
#if defined(MT6268)
#define IMGDMA_IRT3_CTRL_ORDER_BIT         0x00000800
#endif // chip option

/**
 * \brief Check if IRT3 is started or not.
 */
#define IS_IMGDMA_IRT3_START()                         \
  ((0x1 == (REG_IMGDMA_IRT3_START & 0x1))              \
   ? KAL_TRUE                                          \
   : KAL_FALSE)

#define ENABLE_IRT3_INT()                             \
  do {                                                \
    REG_IMGDMA_IRT3_CTRL |= IMGDMA_IRT3_CTRL_INT_BIT; \
  } while(0)

#define DISABLE_IRT3_INT()                              \
  do {                                                  \
    REG_IMGDMA_IRT3_CTRL &= ~IMGDMA_IRT3_CTRL_INT_BIT;  \
  } while(0)

#define ENABLE_IRT3_AUTOSTART()                           \
  do {                                                    \
    REG_IMGDMA_IRT3_CTRL |= IMGDMA_IRT3_CTRL_AUTOSTR_BIT; \
  } while(0)

#define DISABLE_IRT3_AUTOSTART()                            \
  do {                                                      \
    REG_IMGDMA_IRT3_CTRL &= ~IMGDMA_IRT3_CTRL_AUTOSTR_BIT;  \
  } while(0)

#define SET_IRT3_ROTATE_DIR(rot)                        \
  do {                                                  \
    REG_IMGDMA_IRT3_CTRL &= ~IMGDMA_IRT3_CTRL_ROT_MASK; \
    REG_IMGDMA_IRT3_CTRL |= (rot << 2);                 \
  } while(0)

#define ENABLE_IRT3_FLIP()                              \
  do {                                                  \
    REG_IMGDMA_IRT3_CTRL |= IMGDMA_IRT3_CTRL_FLIP_BIT;  \
  } while(0)

#define DISABLE_IRT3_FLIP()                             \
  do {                                                  \
    REG_IMGDMA_IRT3_CTRL &= ~IMGDMA_IRT3_CTRL_FLIP_BIT; \
  } while(0)

#define SET_IRT3_OUTPUT_FMT(fmt)                            \
  do {                                                      \
    REG_IMGDMA_IRT3_CTRL &= ~IMGDMA_IRT3_CTRL_OUTFMT_MASK;  \
    REG_IMGDMA_IRT3_CTRL |= (fmt << 7);                     \
  } while(0)

#define ENABLE_IRT3_PITCH()                             \
  do {                                                  \
    REG_IMGDMA_IRT3_CTRL |= IMGDMA_IRT3_CTRL_PITCH_BIT; \
  } while(0)

#define DISABLE_IRT3_PITCH()                              \
  do {                                                    \
    REG_IMGDMA_IRT3_CTRL &= ~IMGDMA_IRT3_CTRL_PITCH_BIT;  \
  } while(0)

#define START_IRT3()                            \
  do {                                          \
    REG_IMGDMA_IRT3_START = 1;                  \
  } while(0)

#define STOP_IRT3()                             \
  do {                                          \
    REG_IMGDMA_IRT3_START = 0;                  \
  } while(0)

#define SET_IMGDMA_IRT3_FIFO_ADDR(addr)         \
  do {                                          \
    REG_IMGDMA_IRT3_FIFO = addr;                \
  } while(0)

#define SET_IMGDMA_IRT3_WIDTH(width)            \
  do {                                          \
    REG_IMGDMA_IRT3_WIDTH = width;              \
  } while(0)

#define SET_IMGDMA_IRT3_HEIGHT(height)          \
  do {                                          \
    REG_IMGDMA_IRT3_HEIGHT = height;            \
  } while(0)

#define SET_IMGDMA_IRT3_ALPHA(alpha)            \
  do {                                          \
    REG_IMGDMA_IRT3_ALPHA = alpha;              \
  } while(0)

#define SET_IMGDMA_IRT3_FIFOLEN(len)            \
  do {                                          \
    REG_IMGDMA_IRT3_FIFOLEN = len;              \
  } while(0)
#define SET_IMGDMA_IRT3_BUFF1_ADDR(addr)        \
  do {                                          \
    REG_IMGDMA_IRT3_BASE_ADDR1 = addr;          \
  } while(0)

#define SET_IMGDMA_IRT3_BUFF2_ADDR(addr)        \
  do {                                          \
    REG_IMGDMA_IRT3_BASE_ADDR2 = addr;          \
  } while(0)

#define SET_IMGDMA_IRT3_BUFF1_LINE_PITCH(num)   \
  do {                                          \
    REG_IMGDMA_IRT3_LINE_PITCH1 = num;          \
  } while(0)

#define SET_IMGDMA_IRT3_BUFF2_LINE_PITCH(num)   \
  do {                                          \
    REG_IMGDMA_IRT3_LINE_PITCH2 = num;          \
  } while(0)

#define SET_IMGDMA_IRT3_BUFF1_FRAME_PITCH(num)  \
  do {                                          \
    REG_IMGDMA_IRT3_FRAME_PITCH1 = num;         \
  } while(0)

#define SET_IMGDMA_IRT3_BUFF2_FRAME_PITCH(num)  \
  do {                                          \
    REG_IMGDMA_IRT3_FRAME_PITCH2 = num;         \
  } while(0)

/**
 * \brief IRT3 structure
 *
 * Programmers can use this structure to set up IRT3.
 */
typedef struct
{
  kal_bool       intr_en; /**< enable int or not */
  idp_lisr_intr_cb_t intr_cb;
  idp_lisr_intr_cb_param_t intr_cb_param;

  kal_bool       restart; /**< restart or not */
  kal_bool       pitch_enable; /**< enable pitch or not */
  kal_uint32     fifo_base_addr; /**< fifo addr */
  kal_uint16     width; /**< width */
  kal_uint16     height; /**< height */
  kal_uint16     fifo_len; /**< fifo len */
  kal_uint32     frame1_base_addr; /**< base1 addr */
  kal_uint32     frame2_base_addr; /**< base2 addr */
  kal_uint32     buf1_line_pitch; /**< buf1 line pitch */
  kal_uint32     buf2_line_pitch; /**< buf2 line pitch */
  kal_uint32     buf1_frame_pitch; /**< buf1 frame pitch */
  kal_uint32     buf2_frame_pitch; /**< buf2 frame pitch */
  kal_uint8      alpha; /**< alpha value */
  
  //img_color_fmt_rgb_enum_t color_fmt;
  kal_uint32 color_fmt;

  img_rot_angle_enum_t  rot_angle; /**< rotate direction */
  kal_bool       flip; /**< flip or not */
} idp_imgdma_irt3_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_irt3)

extern void *idp_imgdma_irt3_intr_cb_param;
extern void (*idp_imgdma_irt3_intr_cb)(void *);

extern kal_bool idp_imgdma_irt3_config_real(
    idp_imgdma_irt3_struct * const irt3_struct,
    kal_bool const config_to_hardware);

extern kal_bool idp_imgdma_irt3_stop_real(
  idp_imgdma_irt3_struct const * const irt3_struct);

extern kal_bool idp_imgdma_irt3_get_working_mem_real(
  kal_bool const use_internal_mem,
  idp_imgdma_irt3_struct * const irt3_struct,
  kal_bool const do_alloc,
  kal_uint32 const max_allowable_size);

extern void idp_imgdma_irt3_close_real(void);

/** @} */

#endif // defined(DRV_IDP_6238_SERIES)

#endif // __idp_imgdma_irt3_mt6238_h__
