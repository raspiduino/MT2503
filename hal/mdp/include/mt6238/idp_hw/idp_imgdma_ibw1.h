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
 * add to source control recursely
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_imgdma_ibw1_mt6238_h__
#define __idp_imgdma_ibw1_mt6238_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include "reg_base.h"
#include "drv_features_mdp.h"
#include "drv_comm.h"
#include <idp_define.h>

#if defined(DRV_IDP_6238_SERIES)

#include <idp_core.h>
#include "idp_imgdma.h"
#include "img_common_enum.h"

/* ===================================================
 *                        IBW1
 * =================================================== */

/** \defgroup imgdma_ibw1 IBW1
 * @{
 */
#define IMGDMA_IBW1_START_REG           (IMGDMA_base + 0x0300)
#define IMGDMA_IBW1_CTRL_REG            (IMGDMA_base + 0x0304)
#define IMGDMA_IBW1_ALPHA_REG           (IMGDMA_base + 0x0308)
#define IMGDMA_IBW1_BASE_ADDR1_REG      (IMGDMA_base + 0x030C)
#define IMGDMA_IBW1_BASE_ADDR2_REG      (IMGDMA_base + 0x0310)
#define IMGDMA_IBW1_WIDTH_REG           (IMGDMA_base + 0x0314)
#define IMGDMA_IBW1_HEIGHT_REG          (IMGDMA_base + 0x0318)
#define IMGDMA_IBW1_CLIP_LEFT_RIGHT_REG (IMGDMA_base + 0x031C)
#define IMGDMA_IBW1_CLIP_TOP_BOTTOM_REG (IMGDMA_base + 0x0320)
#define IMGDMA_IBW1_DEST_PITCH1_REG     (IMGDMA_base + 0x0324)
#define IMGDMA_IBW1_DEST_PITCH2_REG     (IMGDMA_base + 0x0328)
#define IMGDMA_IBW1_H_COUNT_REG         (IMGDMA_base + 0x032C)
#define IMGDMA_IBW1_V_COUNT_REG         (IMGDMA_base + 0x0330)

#define REG_IMGDMA_IBW1_START           *((volatile unsigned int *)(IMGDMA_base + 0x0300))
#define REG_IMGDMA_IBW1_CTRL            *((volatile unsigned int *)(IMGDMA_base + 0x0304))
#define REG_IMGDMA_IBW1_ALPHA           *((volatile unsigned int *)(IMGDMA_base + 0x0308))
#define REG_IMGDMA_IBW1_BASE_ADDR1      *((volatile unsigned int *)(IMGDMA_base + 0x030C))
#define REG_IMGDMA_IBW1_BASE_ADDR2      *((volatile unsigned int *)(IMGDMA_base + 0x0310))
#define REG_IMGDMA_IBW1_WIDTH           *((volatile unsigned int *)(IMGDMA_base + 0x0314))
#define REG_IMGDMA_IBW1_HEIGHT          *((volatile unsigned int *)(IMGDMA_base + 0x0318))
#define REG_IMGDMA_IBW1_CLIP_LEFT_RIGHT *((volatile unsigned int *)(IMGDMA_base + 0x031C))
#define REG_IMGDMA_IBW1_CLIP_TOP_BOTTOM *((volatile unsigned int *)(IMGDMA_base + 0x0320))
#define REG_IMGDMA_IBW1_DEST_PITCH1     *((volatile unsigned int *)(IMGDMA_base + 0x0324))
#define REG_IMGDMA_IBW1_DEST_PITCH2     *((volatile unsigned int *)(IMGDMA_base + 0x0328))
#define REG_IMGDMA_IBW1_H_COUNT         *((volatile unsigned int *)(IMGDMA_base + 0x032C))
#define REG_IMGDMA_IBW1_V_COUNT         *((volatile unsigned int *)(IMGDMA_base + 0x0330))

/* bit mapping of IBW1 and IBW2 control register */
#define IMGDMA_IBW1_INT_BIT            0x00000001
#define IMGDMA_IBW1_DEST_PITCH_BIT     0x00000002
#define IMGDMA_IBW1_TRIGGER_LCD_BIT    0x00000004
#define IMGDMA_IBW1_AUTO_RESTART_BIT   0x00000008
#define IMGDMA_IBW1_DC_ENABLE_BIT      0x00000010
#define IMGDMA_IBW1_PAN_ENABLE_BIT     0x00000020
#define IMGDMA_IBW1_OUTPUT_FORMAT_MASK 0x000000C0

/**
 * \brief Check if IBW1 is started or not.
 */
#define IS_IMGDMA_IBW1_START()                         \
  ((0x1 == (REG_IMGDMA_IBW1_START & 0x1))              \
   ? KAL_TRUE                                          \
   : KAL_FALSE)

/* macros of IBW1,IBW2 start register */
#define START_IBW1() do { REG_IMGDMA_IBW1_START = 1; } while(0)
#define STOP_IBW1()  do { REG_IMGDMA_IBW1_START = 0; } while(0)

#define ENABLE_IBW1_INT()  do { REG_IMGDMA_IBW1_CTRL |= IMGDMA_IBW1_INT_BIT; } while(0)
#define DISABLE_IBW1_INT() do { REG_IMGDMA_IBW1_CTRL &= ~IMGDMA_IBW1_INT_BIT; } while(0)

#define ENABLE_IBW1_DEST_PITCH()    do { REG_IMGDMA_IBW1_CTRL |= IMGDMA_IBW1_DEST_PITCH_BIT; } while(0)
#define DISABLE_IBW1_DEST_PITCH()   do { REG_IMGDMA_IBW1_CTRL &= ~IMGDMA_IBW1_DEST_PITCH_BIT; } while(0)
#define ENABLE_IBW1_TRIGGER_LCD()   do { REG_IMGDMA_IBW1_CTRL |= IMGDMA_IBW1_TRIGGER_LCD_BIT; } while(0)
#define DISABLE_IBW1_TRIGGER_LCD()  do { REG_IMGDMA_IBW1_CTRL &= ~IMGDMA_IBW1_TRIGGER_LCD_BIT; } while(0)
#define ENABLE_IBW1_AUTO_RESTART()  do { REG_IMGDMA_IBW1_CTRL |= IMGDMA_IBW1_AUTO_RESTART_BIT; } while(0)
#define DISABLE_IBW1_AUTO_RESTART() do { REG_IMGDMA_IBW1_CTRL &= ~IMGDMA_IBW1_AUTO_RESTART_BIT; } while(0)

#define ENABLE_IBW1_DC()    do { REG_IMGDMA_IBW1_CTRL |= IMGDMA_IBW1_DC_ENABLE_BIT; } while(0)
#define DISABLE_IBW1_DC()   do { REG_IMGDMA_IBW1_CTRL &= ~IMGDMA_IBW1_DC_ENABLE_BIT; } while(0)
#define ENABLE_IBW1_PAN()   do { REG_IMGDMA_IBW1_CTRL |= IMGDMA_IBW1_PAN_ENABLE_BIT; } while(0)
#define DISABLE_IBW1_PAN()  do { REG_IMGDMA_IBW1_CTRL &= ~IMGDMA_IBW1_PAN_ENABLE_BIT; } while(0)

#define SET_IBW1_OUTPUT_FORMAT(format)                        \
  do {                                                        \
    REG_IMGDMA_IBW1_CTRL &= ~IMGDMA_IBW1_OUTPUT_FORMAT_MASK;  \
    REG_IMGDMA_IBW1_CTRL |= (format<<6);                      \
  } while(0)

enum
{
  IDP_IMGDMA_IBW1_MASK_INTR_EN,
  IDP_IMGDMA_IBW1_MASK_INTR_CB,
  IDP_IMGDMA_IBW1_MASK_INTR_CB_PARAM,
  IDP_IMGDMA_IBW1_MASK_AUTO_RESTART,
  IDP_IMGDMA_IBW1_MASK_LCD_TRIGGER,
  IDP_IMGDMA_IBW1_MASK_DC_COUPLE,
  IDP_IMGDMA_IBW1_MASK_COLOR_FMT,
  IDP_IMGDMA_IBW1_MASK_ALPHA,
  IDP_IMGDMA_IBW1_MASK_BASE1_ADDR,
  IDP_IMGDMA_IBW1_MASK_BASE2_ADDR,
  IDP_IMGDMA_IBW1_MASK_WIDTH,
  IDP_IMGDMA_IBW1_MASK_HEIGHT,
  IDP_IMGDMA_IBW1_MASK_PITCH_ENABLE,
  IDP_IMGDMA_IBW1_MASK_PITCH1_BYTES,
  IDP_IMGDMA_IBW1_MASK_PITCH2_BYTES,
  IDP_IMGDMA_IBW1_MASK_PAN,
  IDP_IMGDMA_IBW1_MASK_CLIP_LEFT,
  IDP_IMGDMA_IBW1_MASK_CLIP_RIGHT,
  IDP_IMGDMA_IBW1_MASK_CLIP_TOP,
  IDP_IMGDMA_IBW1_MASK_CLIP_BOTTOM,
#if defined(MT6268)
	IDP_IMGDMA_IBW1_MASK_HW_FRAME_SYNC,
#endif // chip option
  IDP_IMGDMA_IBW1_MASK_LAST
};

/**
 * \brief IBW1 structure
 *
 * Programmers can use this structure to set up IBW1.
 */
typedef struct
{
  kal_uint32                mask[(IDP_IMGDMA_IBW1_MASK_LAST / 32) + 1];
  
  kal_bool                  intr_en; /**< interrupt */
  idp_lisr_intr_cb_t        intr_cb;
  idp_lisr_intr_cb_param_t  intr_cb_param;
  
  kal_bool                  auto_restart; /**< auto restart */
  
  kal_bool                  lcd_trigger;
  kal_bool                  dc_couple;
  
  //img_color_fmt_rgb_enum_t  color_fmt; /**< output format */
  kal_uint32	            color_fmt; /**< output format */

  kal_uint8                 alpha;
  
  kal_uint32                base1_addr; /**< buffer base address */
  kal_uint32                base2_addr; /**< buffer base address */
  
  kal_uint16                width; /**< image width */
  kal_uint16                height; /**< image height */
  
  kal_bool                  pitch_enable; /**< pitch */
  kal_uint16                pitch1_bytes; /**< horizontal pitch 1 */
  kal_uint16                pitch2_bytes; /**< horizontal pitch 2 */
  
  kal_bool                  pan; /**< clip */
  kal_uint16                clip_left;
  kal_uint16                clip_right;
  kal_uint16                clip_top;
  kal_uint16                clip_bottom;
#if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
  kal_bool                  hw_frame_sync; /**< KAL_TRUE: enable HW frame sync; KAL_FALSE: disable. */
#endif // #if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
} idp_imgdma_ibw1_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_ibw1)

extern void *idp_imgdma_ibw1_intr_cb_param;
extern void (*idp_imgdma_ibw1_intr_cb)(void *);

extern kal_bool idp_imgdma_ibw1_config_real(
    idp_imgdma_ibw1_struct * const ibw1_struct,
    kal_bool const config_to_hardware);

extern kal_bool idp_imgdma_ibw1_stop_real(
  idp_imgdma_ibw1_struct const * const ibw1_struct);

extern kal_bool idp_imgdma_ibw1_start_real(
  idp_imgdma_ibw1_struct const * const ibw1_struct);

extern kal_bool idp_imgdma_ibw1_get_working_mem_real(
  kal_bool const use_internal_mem,
  idp_imgdma_ibw1_struct const * const ibw1_struct,
  kal_bool const do_alloc,
  kal_uint32 const max_allowable_size);

extern kal_bool idp_imgdma_ibw1_is_busy_real(
  kal_bool * const busy,
  idp_imgdma_ibw1_struct const * const ibw1_struct);

extern void idp_imgdma_ibw1_close_real(void);

extern kal_bool 
idp_imgdma_ibw1_is_hw_trigger_pending(void);
/** @} */

#endif // defined(DRV_IDP_6238_SERIES)

#endif // __idp_imgdma_ibw1_mt6238_h__
