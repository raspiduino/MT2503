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
 * 08 25 2010 ct.fang
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

#ifndef __idp_resz_crz_mt6238_h__
#define __idp_resz_crz_mt6238_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include "drv_features_mdp.h"
#include "drv_comm.h"
#include <idp_define.h>

#if defined(DRV_IDP_6238_SERIES)

#include "reg_base.h"
#include "idp_core.h"
#include "idp_resz.h"
#include "idp_hw_common.h"

/* ===============================================================
 *                       CRZ definition
 * =============================================================== */
/** \defgroup crz Capture resizer
 * \ingroup resizer
 * @{
 */
#define CRZ_CONFIG_REG              (CRZ_base + 0x00)
#define CRZ_CTRL_REG                (CRZ_base + 0x04)
#define CRZ_STATUS_REG              (CRZ_base + 0x08)
#define CRZ_INT_STATUS_REG          (CRZ_base + 0x0C)
#define CRZ_SOURCE_IMAGE_SIZE_REG   (CRZ_base + 0x10)
#define CRZ_TARGET_IMAGE_SIZE_REG   (CRZ_base + 0x14)
#define CRZ_H_RATIO_REG             (CRZ_base + 0x18)
#define CRZ_V_RATIO_REG             (CRZ_base + 0x1C)
#define CRZ_FRCG_REG                (CRZ_base + 0x40)

#define REG_CRZ_CONFIG              *((volatile unsigned int *)(CRZ_CONFIG_REG))
#define REG_CRZ_CTRL                *((volatile unsigned int *)(CRZ_CTRL_REG))
#define REG_CRZ_STATUS              *((volatile unsigned int *)(CRZ_STATUS_REG))
#define REG_CRZ_INT_STATUS          *((volatile unsigned int *)(CRZ_INT_STATUS_REG))
#define REG_CRZ_SOURCE_IMAGE_SIZE   *((volatile unsigned int *)(CRZ_SOURCE_IMAGE_SIZE_REG))
#define REG_CRZ_TARGET_IMAGE_SIZE   *((volatile unsigned int *)(CRZ_TARGET_IMAGE_SIZE_REG))
#define REG_CRZ_H_RATIO             *((volatile unsigned int *)(CRZ_H_RATIO_REG))
#define REG_CRZ_V_RATIO             *((volatile unsigned int *)(CRZ_V_RATIO_REG))
#define REG_CRZ_FRCG                *((volatile unsigned int *)(CRZ_FRCG_REG))

/* bit mapping of CRZ config register */
#define CRZ_CONFIG_PIXEL_SRC_MASK   (0x00000007)

#define CRZ_CONFIG_PIXEL_SRC_CAMERA_ISP        (0)
#define CRZ_CONFIG_PIXEL_SRC_IMAGE_ROTATOR_0   (1)
#define CRZ_CONFIG_PIXEL_SRC_MPEG4_DEBLOCKING  (2)
#define CRZ_CONFIG_PIXEL_SRC_PRZ               (3)
#define CRZ_CONFIG_PIXEL_SRC_R2Y_0             (4) 

#define CRZ_OUTPUT_MASK             (0x00000070)
#define CRZ_OUTPUT_OVL              (0x00000010)
#define CRZ_OUTPUT_IPP1             (0x00000020)
#define CRZ_OUTPUT_Y2R1             (0x00000040)

#define CRZ_CONFIG_CONT_RUN_BIT     (0x00000100)
#define CRZ_CONFIG_LINE_BUF_SEL_BIT (0x00000200)
#define CRZ_CONFIG_DONE_INT         (0x00000400)
#define CRZ_CONFIG_START_INT        (0x00000800)
#define CRZ_CTRL_LBMAX_MASK         (0x03ff0000)

#define CRZ_CONFIG_NORFDB           (0x00004000)
#define CRZ_CONFIG_VSRSTEN          (0x00002000)
#define CRZ_CONFIG_ECV              (0x00001000)

#if defined(MT6268)
#define CRZ_CONFIG_FORCE_RESET_WHEN_VSYNC                   (0x20000000)
#define CRZ_CONFIG_FORCE_RESET_WHEN_VSYNC_AND_FRAME_UNDONE  (0x40000000)
#define CRZ_CONFIG_INIT_PROCESS                             (0x80000000)
#endif // chip option

/* bit mapping of CRZ control register */
#define CRZ_CTRL_RESET_MASK         (0x00010000)
#define CRZ_CTRL_ENABLE_MASK        (0x00000001)

/* bit mapping of CRZ interrupt status register */
#define CRZ_INT_STATUS_DONE_INT_BIT   (0x00000001)
#define CRZ_INT_STATUS_START_INT_BIT  (0x00000002)

/* bit mapping of CRZ source and target size register */
#define CRZ_IMAGE_SIZE_WIDTH_MASK     (0x0000FFFF)
#define CRZ_IMAGE_SIZE_HEIGHT_MASK    (0xFFFF0000)

/* Macros of CRZ status register */
#define CRZ_STATUS_INPUT_BUSY_BIT  (1 << 0)
#define CRZ_STATUS_OUTPUT_BUSY_BIT (1 << 1)

#define CRZ_STATUS_ERR0_BIT__PIXEL_NOT_ENOUGH     (0x00000010)
#define CRZ_STATUS_ERR1_BIT__OUTPUT_TOO_SLOW      (0x00000020)
#define CRZ_STATUS_ERR2_BIT__INIT_AT_OUTPUT_STAGE (0x00000040)
#define CRZ_STATUS_ERR3_BIT__INIT_AT_INPUT_STAGE  (0x00000080)

#define IS_CRZ_INPUT_BUSY  (REG_CRZ_STATUS & CRZ_STATUS_INPUT_BUSY_BIT)
#define IS_CRZ_OUTPUT_BUSY (REG_CRZ_STATUS & CRZ_STATUS_OUTPUT_BUSY_BIT)

#define CRZ_IS_PIXEL_NOT_ENOUGH() \
  ((CRZ_STATUS_ERR0_BIT__PIXEL_NOT_ENOUGH == (REG_CRZ_STATUS & CRZ_STATUS_ERR0_BIT__PIXEL_NOT_ENOUGH)) ? KAL_TRUE : KAL_FALSE)

#define CRZ_CLEAR_PIXEL_NOT_ENOUGH_BIT() \
  do { \
    REG_CRZ_STATUS |= CRZ_STATUS_ERR0_BIT__PIXEL_NOT_ENOUGH; \
  } while (0)

/**
 * \brief Check if CRZ is started or not.
 */
#if defined(MT6268)
#define ENABLE_CRZ_HW_FRAME_SYNC()                              \
  do {                                                          \
    REG_CRZ_CONFIG |= CRZ_CONFIG_INIT_PROCESS;                  \
  } while (0)

#define DISABLE_CRZ_HW_FRAME_SYNC()                             \
  do {                                                          \
    REG_CRZ_CONFIG &= ~CRZ_CONFIG_INIT_PROCESS;                 \
  } while (0)
#endif  // chip option

#define IS_CRZ_START()                                                  \
  ((CRZ_CTRL_ENABLE_MASK == (REG_CRZ_CTRL & CRZ_CTRL_ENABLE_MASK))      \
   ? KAL_TRUE                                                           \
   : KAL_FALSE)

/* macros of CRZ config register */
#define SET_CRZ_UV_SEL(usel, vsel)                              \
  do {                                                          \
    REG_CRZ_FRCG = 0;                                           \
    REG_CRZ_FRCG = ((((usel) & 0x1F) << 8) | ((vsel) & 0x1F));  \
  } while(0)

#define SET_CRZ_ECV(ecv)                           \
  do {                                             \
    REG_CRZ_CONFIG &= ~CRZ_CONFIG_ECV;             \
    REG_CRZ_CONFIG |= (ecv<<12);                   \
  } while(0)

#define SET_CRZ_DEDICATED_MEMORY()                                  \
  do { REG_CRZ_CONFIG |= CRZ_CONFIG_LINE_BUF_SEL_BIT; } while(0)

#define SET_CRZ_SHARED_MEMORY()                                     \
  do { REG_CRZ_CONFIG &= ~CRZ_CONFIG_LINE_BUF_SEL_BIT; } while(0)

#define SET_CRZ_CONT_RUN_MODE()                                 \
  do { REG_CRZ_CONFIG |= CRZ_CONFIG_CONT_RUN_BIT; } while(0)

#define SET_CRZ_SINGLE_RUN_MODE()                               \
  do { REG_CRZ_CONFIG &= ~CRZ_CONFIG_CONT_RUN_BIT; } while(0)

#define SET_CRZ_PIXEL_BASED_SRC(n)                                      \
  do {                                                                  \
    REG_CRZ_CONFIG &= ~CRZ_CONFIG_PIXEL_SRC_MASK;                       \
    REG_CRZ_CONFIG |= n;                                                \
  } while(0)

#define SET_CRZ_LBMAX(n)                        \
  do {                                          \
    REG_CRZ_CONFIG &= ~CRZ_CTRL_LBMAX_MASK;     \
    REG_CRZ_CONFIG |= (n << 16);                \
  } while(0)

#define SET_CRZ_OUTPUT(module)                  \
  do {                                          \
    REG_CRZ_CONFIG &= ~CRZ_OUTPUT_MASK;         \
    REG_CRZ_CONFIG |= module;                   \
  } while(0)

/* marcos of CRZ control register */
#define RESET_CRZ()                               \
  do {                                            \
    REG_CRZ_CTRL = CRZ_CTRL_RESET_MASK;           \
    REG_CRZ_CTRL = 0;                             \
  } while(0)

#define ENABLE_CRZ()                            \
  do {                                          \
    REG_CRZ_CTRL = CRZ_CTRL_ENABLE_MASK;        \
  } while(0)

/* Macros of CRZ source image size register */
#define SET_CRZ_SRC_SIZE(width, height) \
  do { REG_CRZ_SOURCE_IMAGE_SIZE = (width | (height << 16)); } while(0)

/* Macros of CRZ target image size register */
#define SET_CRZ_TARGET_SIZE(width, height) \
  do { REG_CRZ_TARGET_IMAGE_SIZE = (width | (height << 16)); } while(0)

#define ENABLE_CRZ_DONE_INT()                           \
  do {                                                  \
    REG_CRZ_CONFIG |= CRZ_CONFIG_DONE_INT;              \
  } while(0)

#define DISABLE_CRZ_DONE_INT()                          \
  do {                                                  \
    REG_CRZ_CONFIG &= ~CRZ_CONFIG_DONE_INT;             \
  } while(0)

#define ENABLE_CRZ_START_INT()                           \
  do {                                                   \
    REG_CRZ_CONFIG |= CRZ_CONFIG_START_INT;              \
  } while(0)

#define DISABLE_CRZ_START_INT()                          \
  do {                                                   \
    REG_CRZ_CONFIG &= ~CRZ_CONFIG_START_INT;             \
  } while(0)

enum
{
  IDP_RESZ_CRZ_MASK_IMAGE_SRC,
  IDP_RESZ_CRZ_MASK_OUTPUT_TO_OVL,
  IDP_RESZ_CRZ_MASK_OUTPUT_TO_IPP1,
  IDP_RESZ_CRZ_MASK_OUTPUT_TO_Y2R1,
  IDP_RESZ_CRZ_MASK_CONTINUS,
  IDP_RESZ_CRZ_MASK_DONE_INTR_EN,
  IDP_RESZ_CRZ_MASK_DONE_INTR_CB,
  IDP_RESZ_CRZ_MASK_DONE_INTR_CB_PARAM,
  IDP_RESZ_CRZ_MASK_START_INTR_EN,
  IDP_RESZ_CRZ_MASK_START_INTR_CB,
  IDP_RESZ_CRZ_MASK_START_INTR_CB_PARAM,
  IDP_RESZ_CRZ_MASK_SRC_HEIGHT,
  IDP_RESZ_CRZ_MASK_SRC_WIDTH,
  IDP_RESZ_CRZ_MASK_TAR_HEIGHT,
  IDP_RESZ_CRZ_MASK_TAR_WIDTH,
  IDP_RESZ_CRZ_MASK_USEL,
  IDP_RESZ_CRZ_MASK_VSEL,
  IDP_RESZ_CRZ_MASK_SET_ECV,
#if defined(MT6268)
  IDP_RESZ_CRZ_MASK_HW_FRAME_SYNC, 
#endif  // chip option
  
  IDP_RESZ_CRZ_MASK_LAST
};

enum idp_resz_crz_error_code_t
{
  IDP_RESZ_CRZ_NO_ERROR,
  IDP_RESZ_CRZ_ERROR_CODE_SRC_WIDTH_TOO_LARGE,
  IDP_RESZ_CRZ_ERROR_CODE_SRC_WIDTH_TOO_SMALL,
  IDP_RESZ_CRZ_ERROR_CODE_SRC_HEIGHT_TOO_LARGE,
  IDP_RESZ_CRZ_ERROR_CODE_SRC_HEIGHT_TOO_SMALL,
  IDP_RESZ_CRZ_ERROR_CODE_TAR_WIDTH_TOO_LARGE,
  IDP_RESZ_CRZ_ERROR_CODE_TAR_WIDTH_TOO_SMALL,
  IDP_RESZ_CRZ_ERROR_CODE_TAR_HEIGHT_TOO_LARGE,
  IDP_RESZ_CRZ_ERROR_CODE_TAR_HEIGHT_TOO_SMALL,
  IDP_RESZ_CRZ_ERROR_CODE_HW_LIMITATION
};
typedef enum idp_resz_crz_error_code_t idp_resz_crz_error_code_t;

enum
{
  IDP_RESZ_CRZ_QUERY_ERROR_CODE = 1
};

typedef struct
{
  kal_uint32                mask[(IDP_RESZ_CRZ_MASK_LAST / 32) + 1];
  
  idp_module_enum_t         image_src;
  
  kal_bool                  output_to_OVL;
  kal_bool                  output_to_IPP1;
  kal_bool                  output_to_Y2R1;
  
  kal_bool                  continous;

  kal_bool                  done_intr_en; 
  idp_lisr_intr_cb_t        done_intr_cb;
  idp_lisr_intr_cb_param_t  done_intr_cb_param;
  
  kal_bool                  start_intr_en; 
  idp_lisr_intr_cb_t        start_intr_cb;
  idp_lisr_intr_cb_param_t  start_intr_cb_param;
  
  kal_uint16                src_height;
  kal_uint16                src_width;
  kal_uint16                tar_height;
  kal_uint16                tar_width; 
  
  kal_uint32                usel;
  kal_uint32                vsel;
  
  kal_bool                  set_ecv;

  kal_bool                  reset; /***< [sw_frame_reset] KAL_TRUE, switch RST of CRZ_CON; KAL_FALSE, no effect. */
#if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
  kal_bool                  hw_frame_sync; /***< TRUE: enable HW frame sync in CRZ; FALSE: disable HW frame sync in CRZ. */
#endif  // #if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
} idp_resz_crz_struct;

IDP_HW_COMMON_API_DECLARATION(resz_crz)

extern kal_bool idp_resz_crz_config_real(
    idp_resz_crz_struct * const crz_struct,
    kal_bool const config_to_hardware);

extern kal_bool idp_resz_crz_stop_real(
  idp_resz_crz_struct const * const crz_struct);

extern kal_bool idp_resz_crz_get_working_mem_real(
  kal_bool const use_internal_mem,
  idp_resz_crz_struct * const crz_struct,
  kal_bool const do_alloc,
  kal_uint32 const max_allowable_size);

extern void idp_resz_crz_close_real(void);

extern kal_bool idp_resz_crz_is_busy_real(
  kal_bool * const busy,
  idp_resz_crz_struct const * const crz_struct);

/** @} */

#endif  // defined(DRV_IDP_6238_SERIES)

#endif  // __idp_resz_crz_mt6238_h__

