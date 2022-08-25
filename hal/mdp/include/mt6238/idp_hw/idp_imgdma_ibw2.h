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
 * add to source control recursely
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_imgdma_ibw2_mt6238_h__
#define __idp_imgdma_ibw2_mt6238_h__

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

/* ===================================================
 *                        IBW2
 * =================================================== */

/** \defgroup imgdma_ibw2 IBW2
 * @{
 */
#define IMGDMA_IBW2_START_REG           (IMGDMA_base + 0x0400)
#define IMGDMA_IBW2_CTRL_REG            (IMGDMA_base + 0x0404)
#define IMGDMA_IBW2_BASE_ALPHA          (IMGDMA_base + 0x0408)
#define IMGDMA_IBW2_WIDTH_REG           (IMGDMA_base + 0x040C)
#define IMGDMA_IBW2_HEIGHT_REG          (IMGDMA_base + 0x0410)
#define IMGDMA_IBW2_CLIP_LEFT_RIGHT_REG (IMGDMA_base + 0x0414)
#define IMGDMA_IBW2_CLIP_TOP_BOTTOM_REG (IMGDMA_base + 0x0418)
#define IMGDMA_IBW_PIXEL_COUNT_REG      (IMGDMA_base + 0x041C)
#define IMGDMA_IBW_LINE_COUNT_REG       (IMGDMA_base + 0x0420)

#define REG_IMGDMA_IBW2_START           *((volatile unsigned int *)(IMGDMA_base + 0x0400))
#define REG_IMGDMA_IBW2_CTRL            *((volatile unsigned int *)(IMGDMA_base + 0x0404))
#define REG_IMGDMA_IBW2_ALPHA           *((volatile unsigned int *)(IMGDMA_base + 0x0408))
#define REG_IMGDMA_IBW2_WIDTH           *((volatile unsigned int *)(IMGDMA_base + 0x040C))
#define REG_IMGDMA_IBW2_HEIGHT          *((volatile unsigned int *)(IMGDMA_base + 0x0410))
#define REG_IMGDMA_IBW2_CLIP_LEFT_RIGHT *((volatile unsigned int *)(IMGDMA_base + 0x0414))
#define REG_IMGDMA_IBW2_CLIP_TOP_BOTTOM *((volatile unsigned int *)(IMGDMA_base + 0x0418))
#define REG_IMGDMA_IBW2_PIXEL_COUNT     *((volatile unsigned int *)(IMGDMA_base + 0x041C))
#define REG_IMGDMA_IBW2_LINE_COUNT      *((volatile unsigned int *)(IMGDMA_base + 0x0420))

#define IMGDMA_IBW2_OUT2IRT1_ENABLE_BIT 0x00000080
#define IMGDMA_IBW2_DC_ENABLE_BIT       0x00000040
#define IMGDMA_IBW2_PAN_ENABLE_BIT      0x00000008
#define IMGDMA_IBW2_AUTO_RESTART_BIT    0x00000004
#define IMGDMA_IBW2_TRIGGER_LCD_BIT     0x00000002
#define IMGDMA_IBW2_INT_BIT             0x00000001

#define START_IBW2() do { REG_IMGDMA_IBW2_START = 1; } while(0)
#define STOP_IBW2()  do { REG_IMGDMA_IBW2_START = 0; } while(0)

/**
 * \brief Check if IBW2 is started or not.
 */
#define IS_IMGDMA_IBW2_START()                              \
  ((0x1 == (REG_IMGDMA_IBW2_START & 0x1))                   \
   ? KAL_TRUE                                               \
   : KAL_FALSE)

#define ENABLE_IBW2_PAN()             do { REG_IMGDMA_IBW2_CTRL |= IMGDMA_IBW2_PAN_ENABLE_BIT; } while(0)
#define DISABLE_IBW2_PAN()            do { REG_IMGDMA_IBW2_CTRL &= ~IMGDMA_IBW2_PAN_ENABLE_BIT; } while(0)
#define ENABLE_IBW2_DC()              do { REG_IMGDMA_IBW2_CTRL |= IMGDMA_IBW2_DC_ENABLE_BIT; } while(0)
#define DISABLE_IBW2_DC()             do { REG_IMGDMA_IBW2_CTRL &= ~IMGDMA_IBW2_DC_ENABLE_BIT; } while(0)
#define ENABLE_IBW2_AUTO_RESTART()    do { REG_IMGDMA_IBW2_CTRL |= IMGDMA_IBW2_AUTO_RESTART_BIT; } while(0)
#define DISABLE_IBW2_AUTO_RESTART()   do { REG_IMGDMA_IBW2_CTRL &= ~IMGDMA_IBW2_AUTO_RESTART_BIT; } while(0)
#define ENABLE_IBW2_TRIGGER_LCD()     do { REG_IMGDMA_IBW2_CTRL |= IMGDMA_IBW2_TRIGGER_LCD_BIT; } while(0)
#define DISABLE_IBW2_TRIGGER_LCD()    do { REG_IMGDMA_IBW2_CTRL &= ~IMGDMA_IBW2_TRIGGER_LCD_BIT; } while(0)
#define ENABLE_IBW2_INT()             do { REG_IMGDMA_IBW2_CTRL |= IMGDMA_IBW2_INT_BIT; } while(0)
#define DISABLE_IBW2_INT()            do { REG_IMGDMA_IBW2_CTRL &= ~IMGDMA_IBW2_INT_BIT; } while(0)
#define ENABLE_IBW2_OUT2IRT1()        do { REG_IMGDMA_IBW2_CTRL |= IMGDMA_IBW2_OUT2IRT1_ENABLE_BIT; } while(0)
#define DISABLE_IBW2_OUT2IRT1()       do { REG_IMGDMA_IBW2_CTRL &= ~IMGDMA_IBW2_OUT2IRT1_ENABLE_BIT; } while(0)

/**
 * \brief IBW2 structure
 *
 * Programmers can use this structure to set up IBW2.
 */
typedef struct
{
  kal_uint16                width;
  kal_uint16                height;
  kal_uint16                clip_left;
  kal_uint16                clip_right;
  kal_uint16                clip_top;
  kal_uint16                clip_bottom;
  kal_bool                  lcd_trigger;

  kal_bool                  intr_en;
  idp_lisr_intr_cb_t        intr_cb;
  idp_lisr_intr_cb_param_t  intr_cb_param;

  kal_bool                  pan;
  kal_bool                  direct_couple;
  kal_bool                  restart;
  kal_bool                  output_IRT1;
#if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
  kal_bool                  hw_frame_sync;
#endif // #if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
} idp_imgdma_ibw2_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_ibw2)

extern void *idp_imgdma_ibw2_intr_cb_param;
extern void (*idp_imgdma_ibw2_intr_cb)(void *);

extern kal_bool idp_imgdma_ibw2_config_real(
    idp_imgdma_ibw2_struct * const ibw2_struct,
    kal_bool const config_to_hardware);

extern kal_bool idp_imgdma_ibw2_stop_real(
  idp_imgdma_ibw2_struct const * const ibw2_struct);

extern kal_bool idp_imgdma_ibw2_is_busy_real(
  kal_bool * const busy,
  idp_imgdma_ibw2_struct const * const ibw2_struct);

extern kal_bool idp_imgdma_ibw2_get_working_mem_real(
  kal_bool const use_internal_mem,
  idp_imgdma_ibw2_struct const * const ibw2_struct,
  kal_bool const do_alloc,
  kal_uint32 const max_allowable_size);

extern void idp_imgdma_ibw2_close_real(void);

/** @} */

#endif // defined(DRV_IDP_6238_SERIES)

#endif // __idp_imgdma_ibw2_mt6238_h__
