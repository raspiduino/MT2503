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

#ifndef __idp_imgdma_ovl_mt6238_h__
#define __idp_imgdma_ovl_mt6238_h__

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
#include "idp_hw_common.h"
#include "img_common_enum.h"

/* ===================================================
 *                        OVL
 * =================================================== */

/** \defgroup imgdma_ovl OVL
 * @{
 */
#define IMGDMA_OVL_START_REG           (IMGDMA_base + 0x0700)
#define IMGDMA_OVL_CTRL_REG            (IMGDMA_base + 0x0704)
#define IMGDMA_OVL_BASE_ADDR_REG       (IMGDMA_base + 0x0708)
#define IMGDMA_OVL_CONFIG_REG          (IMGDMA_base + 0x070c)
#define IMGDMA_OVL_WIDTH_REG           (IMGDMA_base + 0x0710)
#define IMGDMA_OVL_HEIGHT_REG          (IMGDMA_base + 0x0714)
#define IMGDMA_OVL_H_COUNT_REG         (IMGDMA_base + 0x0718)
#define IMGDMA_OVL_V_COUNT_REG         (IMGDMA_base + 0x071C)
#define IMGDMA_OVL_COLOR_PALETTE_BASE  (IMGDMA_base + 0x0800)

#define REG_IMGDMA_OVL_START     *((volatile unsigned int *)(IMGDMA_base + 0x0700))
#define REG_IMGDMA_OVL_CTRL      *((volatile unsigned int *)(IMGDMA_base + 0x0704))
#define REG_IMGDMA_OVL_BASE_ADDR *((volatile unsigned int *)(IMGDMA_base + 0x0708))
#define REG_IMGDMA_OVL_CONFIG    *((volatile unsigned int *)(IMGDMA_base + 0x070c))
#define REG_IMGDMA_OVL_WIDTH     *((volatile unsigned int *)(IMGDMA_base + 0x0710))
#define REG_IMGDMA_OVL_HEIGHT    *((volatile unsigned int *)(IMGDMA_base + 0x0714))
#define REG_IMGDMA_OVL_H_COUNT   *((volatile unsigned int *)(IMGDMA_base + 0x0718))
#define REG_IMGDMA_OVL_V_COUNT   *((volatile unsigned int *)(IMGDMA_base + 0x071C))

#define IMGDMA_OVL_INT_BIT               0x00000001
#define IMGDMA_OVL_1BPP_PHOTO_FRAME_MASK 0x00000006
#define IMGDMA_OVL_1BPP_PHOTO_FRAME_BIT  0x00000000
#define IMGDMA_OVL_2BPP_PHOTO_FRAME_BIT  0x00000002
#define IMGDMA_OVL_4BPP_PHOTO_FRAME_BIT  0x00000004
#define IMGDMA_OVL_8BPP_PHOTO_FRAME_BIT  0x00000006
#define IMGDMA_OVL_AUTO_RESTART_BIT      0x00000008
#define IMGDMA_OVL_PALEN_BIT             0x00000010
#define IMGDMA_OVL_PSEL_BIT              0x00000020
#if defined(MT6268)
#define IMGDMA_OVL_OUTPUT_MASK           0x00000FC0
#else // chip option MT6238 MT6268A
#define IMGDMA_OVL_OUTPUT_MASK           0x000007C0
#endif // chip option
#define IMGDMA_OVL_OUTPUT_VDOENC_BIT     0x00000040
#define IMGDMA_OVL_OUTPUT_JPEG_BIT       0x00000080
#define IMGDMA_OVL_OUTPUT_Y2R0_BIT       0x00000100
#define IMGDMA_OVL_OUTPUT_DRZ_BIT        0x00000200
#define IMGDMA_OVL_OUTPUT_PRZ_BIT        0x00000400
#if defined(MT6268)
#define IMGDMA_OVL_OUTPUT_IPP1_BIT       0x00000800
#endif // chip option

#define IMGDMA_OVL_CONF_HRATIO_MASK      0x0000000F
#define IMGDMA_OVL_CONF_VRATIO_MASK      0x000000F0
#define IMGDMA_OVL_CONF_SOURCE_KEY_MASK  0x0000FF00

#define START_OVL() do { REG_IMGDMA_OVL_START = 1; } while(0)
#define STOP_OVL()  do { REG_IMGDMA_OVL_START = 0; } while(0)

#define ENABLE_IMGDMA_OVL_INT()            do { REG_IMGDMA_OVL_CTRL |= IMGDMA_OVL_INT_BIT; } while(0)
#define DISABLE_IMGDMA_OVL_INT()           do { REG_IMGDMA_OVL_CTRL &= ~IMGDMA_OVL_INT_BIT; } while(0)
#define ENABLE_IMGDMA_OVL_PAL()            do { REG_IMGDMA_OVL_CTRL |= IMGDMA_OVL_PALEN_BIT; } while(0)
#define DISABLE_IMGDMA_OVL_PAL()           do { REG_IMGDMA_OVL_CTRL &= ~IMGDMA_OVL_PALEN_BIT; } while(0)
#define ENABLE_IMGDMA_OVL_AUTO_RESATRT()   do { REG_IMGDMA_OVL_CTRL |= IMGDMA_OVL_AUTO_RESTART_BIT; } while(0)
#define DISABLE_IMGDMA_OVL_AUTO_RESATRT()  do { REG_IMGDMA_OVL_CTRL &= ~IMGDMA_OVL_AUTO_RESTART_BIT; } while(0)
#define ENABLE_IMGDMA_OVL_OVERLAY()        do { REG_IMGDMA_OVL_CTRL |= IMGDMA_OVL_PALEN_BIT; } while(0)
#define DISABLE_IMGDMA_OVL_OVERLAY()       do { REG_IMGDMA_OVL_CTRL &= ~IMGDMA_OVL_PALEN_BIT; } while(0)
#define SET_IMGDMA_OVL_SRC_IPP1()          do { REG_IMGDMA_OVL_CTRL &= ~IMGDMA_OVL_PSEL_BIT; } while(0)
#define SET_IMGDMA_OVL_SRC_CRZ()           do { REG_IMGDMA_OVL_CTRL |= IMGDMA_OVL_PSEL_BIT; } while(0)

/* macros of OVL control register */
/**
 * \brief Check if OVL is started or not.
 */
#define IS_IMGDMA_OVL_START()                          \
  ((0x1 == (REG_IMGDMA_OVL_START & 0x1))        \
   ? KAL_TRUE                                   \
   : KAL_FALSE)

#define SET_OVL_OVERLAY_MODE(mode)                            \
  do {                                                        \
    REG_IMGDMA_OVL_CTRL &= ~IMGDMA_OVL_1BPP_PHOTO_FRAME_MASK; \
    REG_IMGDMA_OVL_CTRL |= ((mode) << 1);                     \
  } while(0)

#define SET_OVL_OUTPUT_MODULE(module)               \
  do {                                              \
    REG_IMGDMA_OVL_CTRL &= ~IMGDMA_OVL_OUTPUT_MASK; \
    REG_IMGDMA_OVL_CTRL |= (module);                \
  } while(0)

#define SET_IMGDMA_OVL_SRC_KEY(color)                           \
  do {                                                          \
    REG_IMGDMA_OVL_CONFIG &= ~IMGDMA_OVL_CONF_SOURCE_KEY_MASK;  \
    REG_IMGDMA_OVL_CONFIG |= ((color) << 8);                    \
  } while(0)

#define SET_IMGDMA_OVL_V_RATIO(ratio)                       \
  do {                                                      \
    REG_IMGDMA_OVL_CONFIG &= ~IMGDMA_OVL_CONF_VRATIO_MASK;  \
    REG_IMGDMA_OVL_CONFIG |= ((ratio) << 4);                \
  } while(0)

#define SET_IMGDMA_OVL_H_RATIO(ratio)                       \
  do {                                                      \
    REG_IMGDMA_OVL_CONFIG &= ~IMGDMA_OVL_CONF_HRATIO_MASK;  \
    REG_IMGDMA_OVL_CONFIG |= (ratio);                       \
  } while(0)

/**
 * \brief OVL structure
 *
 * Programmers can use this structure to set up OVL.
 */
typedef struct
{
  kal_bool                  intr_en; /**< interrup enable */
  idp_lisr_intr_cb_t        intr_cb;
  idp_lisr_intr_cb_param_t  intr_cb_param;

  kal_bool                  restart; /**< 1: automatic reastart while current frame is finished */
  kal_bool                  overlay_frame_mode; /**< KAL_TRUE or KAL_FALSE */
  kal_bool                  output_vdoenc; /**< KAL_TRUE or KAL_FALSE */
  kal_bool                  ouput_jpeg; /**< KAL_TRUE or KAL_FALSE */
  kal_bool                  ouput_y2r0; /**< KAL_TRUE or KAL_FALSE */
  kal_bool                  ouput_drz; /**< KAL_TRUE or KAL_FALSE */
  kal_bool                  ouput_prz; /**< KAL_TRUE or KAL_FALSE */
#if defined(MT6268)
  kal_bool                  output_ipp1; /**< KAL_TRUE or KAL_FALSE */
#endif // chip option
  
  idp_module_enum_t         pixel_engine; /**< define pixel engine */
  /* overlay frame configuration */
  kal_uint32                overlay_frame_buffer_address; /**< bsae address of the overlay frame buffer */
  kal_uint16                overlay_frame_width; /**< overlay frame width */
  kal_uint16                overlay_frame_height; /**< overlay frame height */
  kal_uint16                overlay_frame_target_width; /**< overlay frame target width */
  kal_uint16                overlay_frame_target_height; /**< overlay frame target height */
  img_palette_mode_enum_t   overlay_palette_mode; /**< 1/2/4/8 bpp */
  kal_uint8                 overlay_frame_source_key; /**< source key of the overlay frame buffer */
#if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
  kal_bool                  hw_frame_sync; /**< KAL_TRUE: enable HW frame sync; KAL_FALSE: disable. */
#endif // #if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
} idp_imgdma_ovl_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_ovl)

extern void *idp_imgdma_ovl_intr_cb_param;
extern void (*idp_imgdma_ovl_intr_cb)(void *);

extern kal_bool idp_imgdma_ovl_set_palette(
  kal_uint32 const key,
  kal_uint8 const palette_size,
  kal_uint32 const * const palette_addr_ptr);

extern kal_bool idp_imgdma_ovl_config_real(
    idp_imgdma_ovl_struct * const ovl_struct,
    kal_bool const config_to_hardware);

extern kal_bool idp_imgdma_ovl_stop_real(
  idp_imgdma_ovl_struct const * const ovl_struct);

extern kal_bool idp_imgdma_ovl_get_working_mem_real(
  kal_bool const use_internal_mem,
  idp_imgdma_ovl_struct * const ovl_struct,
  kal_bool const do_alloc,
  kal_uint32 const max_allowable_size);

extern void idp_imgdma_ovl_close_real(void);


/** @} */

#endif // defined(DRV_IDP_6238_SERIES)

#endif // __idp_imgdma_ovl_mt6238_h__
