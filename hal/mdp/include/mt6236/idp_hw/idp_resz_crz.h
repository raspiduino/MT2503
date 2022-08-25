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
 *    idp_resz_crz.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    CRZ HW driver interface for MT6236
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
 * 10 12 2011 chrono.wu
 * removed!
 * .
 *
 * 11 23 2010 chrono.wu
 * removed!
 * .
 *
 * removed!
 * removed!
 * Add a handler for not completed frame
 *
 * removed!
 * removed!
 * Add a force reset function for exception handler
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
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_resz_crz_mt6236_h__
#define __idp_resz_crz_mt6236_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>
#include "reg_base.h"
#include "idp_core.h"

#if defined(DRV_IDP_MT6236_SERIES)

#include "idp_resz.h"
#include "idp_hw_common.h"

/* ===============================================================
 *                       CRZ definition
 * =============================================================== */
/** 
 * \defgroup crz Capture resizer
 * \ingroup resizer
 * @{
 */
#define CRZ_MAX_INPUT_WIDTH         (4095)
#define CRZ_MAX_INPUT_HEIGHT        (4095)
#define CRZ_MAX_OUTPUT_WIDTH        (4095)
#define CRZ_MAX_OUTPUT_HEIGHT       (4095)
#define CRZ_MAX_UPSCALE_RATIO       (64)
#define CRZ_MAX_DOWNSCALE_RATIO     (2048)


#define CRZ_BASE                    (CRZ_base)

#define CRZ_CFG_REG                 (CRZ_BASE + 0x00)
#define CRZ_CON_REG                 (CRZ_BASE + 0x04)
#define CRZ_STA_REG                 (CRZ_BASE + 0x08)
#define CRZ_INT_REG                 (CRZ_BASE + 0x0C)
#define CRZ_SRCSZ1_REG              (CRZ_BASE + 0x10)
#define CRZ_TARSZ1_REG              (CRZ_BASE + 0x14)
#define CRZ_HRATIO1_REG             (CRZ_BASE + 0x18)
#define CRZ_VRATIO1_REG             (CRZ_BASE + 0x1C)
#define CRZ_FRCFG_REG               (CRZ_BASE + 0x40)
#define CRZ_BUSYU_REG               (CRZ_BASE + 0x80)
#define CRZ_BUSYD_REG               (CRZ_BASE + 0x84)
#define CRZ_FRAME_COUNT_REG         (CRZ_BASE + 0xB8)

#ifndef MDP_C_MODEL
#define REG_CRZ_CFG                 *((volatile unsigned int *)(CRZ_CFG_REG))
#define REG_CRZ_CON                 *((volatile unsigned int *)(CRZ_CON_REG))
#define REG_CRZ_STA                 *((volatile unsigned int *)(CRZ_STA_REG))
#define REG_CRZ_INT                 *((volatile unsigned int *)(CRZ_INT_REG))
#define REG_CRZ_SRCSZ1              *((volatile unsigned int *)(CRZ_SRCSZ1_REG))
#define REG_CRZ_TARSZ1              *((volatile unsigned int *)(CRZ_TARSZ1_REG))
#define REG_CRZ_HRATIO1             *((volatile unsigned int *)(CRZ_HRATIO1_REG))
#define REG_CRZ_VRATIO1             *((volatile unsigned int *)(CRZ_VRATIO1_REG))
#define REG_CRZ_FRCFG               *((volatile unsigned int *)(CRZ_FRCFG_REG))
#define REG_CRZ_BUSYU               *((volatile unsigned int *)(CRZ_BUSYU_REG))
#define REG_CRZ_BUSYD               *((volatile unsigned int *)(CRZ_BUSYD_REG))
#define REG_CRZ_FRAME_COUNT         *((volatile unsigned int *)(CRZ_FRAME_COUNT_REG))
#else // MDP_C_MODEL
#define REG_CRZ_CFG                 CRZ_CFG
#define REG_CRZ_CON                 CRZ_CON
#define REG_CRZ_STA                 CRZ_STA
#define REG_CRZ_INT                 CRZ_INT
#define REG_CRZ_SRCSZ1              CRZ_SRCSZ1
#define REG_CRZ_TARSZ1              CRZ_TARSZ1
#define REG_CRZ_HRATIO1             CRZ_HRATIO1
#define REG_CRZ_VRATIO1             CRZ_VRATIO1
#define REG_CRZ_FRCFG               CRZ_FRCFG
#define REG_CRZ_BUSYU               CRZ_BUSYU
#define REG_CRZ_BUSYD               CRZ_BUSYD
#endif // MDP_C_MODEL

/* bit mapping of CRZ config register */
// TODO: TBD
#define CRZ_CONFIG_PIXEL_SRC_MASK               0x00000007
#define CRZ_CONFIG_PIXEL_SRC_CAMERA_ISP         (0)
#define CRZ_CONFIG_PIXEL_SRC_IMAGE_ROTATOR_0    (1)
#define CRZ_CONFIG_PIXEL_SRC_MPEG4_DEBLOCKING   (2)
#define CRZ_CONFIG_PIXEL_SRC_PRZ                (3)
#define CRZ_CONFIG_PIXEL_SRC_R2Y_0              (4) 

// TODO: TBD
#define CRZ_CONFIG_CONT_RUN_BIT                             (0x00000100)
#define CRZ_CONFIG_LINE_BUF_SEL_BIT                         (0x00000200)
#define CRZ_CONFIG_DONE_INT                                 (0x00000400)
#define CRZ_CONFIG_START_INT                                (0x00000800)
#define CRZ_CTRL_LBMAX_MASK                                 (0x03ff0000)
#define CRZ_CONFIG_FORCE_RESET_WHEN_VSYNC                   (0x20000000)
#define CRZ_CONFIG_FORCE_RESET_WHEN_VSYNC_AND_FRAME_UNDONE  (0x40000000)
#define CRZ_CONFIG_INIT_PROCESS                             (0x80000000)

// TODO: TBD
#define CRZ_CONFIG_NORFDB                       (0x00004000)
#define CRZ_CONFIG_VSRSTEN                      (0x00002000)
#define CRZ_CONFIG_ECV                          (0x00001000)

/* bit mapping of CRZ control register */
#define CRZ_CON_RST_BIT                         (0x00010000)
#define CRZ_CON_ENA_BIT                         (0x00000001)

/* bit mapping of CRZ interrupt status register */
// TODO: TBD
#define CRZ_INT_STATUS_DONE_INT_BIT             (0x00000001)
#define CRZ_INT_STATUS_START_INT_BIT            (0x00000002)

/* bit mapping of CRZ source and target size register */
// TODO: TBD
#define CRZ_IMAGE_SIZE_WIDTH_MASK               0x0000FFFF
#define CRZ_IMAGE_SIZE_HEIGHT_MASK              0xFFFF0000

/* Macros of CRZ status register */
// TODO: TBD
#define CRZ_STATUS_INPUT_BUSY_BIT               (0x2)
#define CRZ_STATUS_OUTPUT_BUSY_BIT              (0x1)

// TODO: different from MT6238 series, check with Abrams if the two bits 2 switched
#define IS_CRZ_INPUT_BUSY                       (REG_CRZ_STA & CRZ_STATUS_INPUT_BUSY_BIT)
#define IS_CRZ_OUTPUT_BUSY                      (REG_CRZ_STA & CRZ_STATUS_OUTPUT_BUSY_BIT)

#define IS_CRZ_FRAME_SYNC()                     (REG_CRZ_STA&0x90)

#define CRZ_CLEAR_FRAME_SYNC()                      \
  do {                                              \
    REG_CRZ_STA |= 0x90;                            \
  } while(0)

#define CRZ_STA_ERR0                            (0x00000010)

#define IS_CRZ_FRAME_NOT_ENOUGH() \
  ((CRZ_STA_ERR0 == (REG_CRZ_STA & CRZ_STA_ERR0)) ? KAL_TRUE : KAL_FALSE)

/**
 * \brief Check if CRZ is started or not.
 */
#define IS_CRZ_START() \
  ((CRZ_CON_ENA_BIT == (REG_CRZ_CON & CRZ_CON_ENA_BIT)) ? KAL_TRUE : KAL_FALSE)

/* macros of CRZ config register */
#define CRZ_SET_UD_SEL(usel, dsel) \
  do { REG_CRZ_FRCFG = ((((usel) & 0x1F) << 8) | ((dsel) & 0x1F)); } while(0)

#define CRZ_FRCFG_DSEL_DEFAULT (15)
#define CRZ_FRCFG_USEL_DEFAULT (8)

// TODO: TBD
#define SET_CRZ_ECV(ecv)                            \
  do {                                              \
    REG_CRZ_CFG &= ~CRZ_CONFIG_ECV;                 \
    REG_CRZ_CFG |= (ecv<<12);                       \
  } while(0)

// Use RESZ_LB, must use this
#define SET_CRZ_DEDICATED_MEMORY() \
  do { REG_CRZ_CFG |= CRZ_CONFIG_LINE_BUF_SEL_BIT; } while(0)

// CRZ cannot work w/o RESZ_LB
// TODO: why this bit preserved?
#define SET_CRZ_SHARED_MEMORY() \
  do { REG_CRZ_CFG &= ~CRZ_CONFIG_LINE_BUF_SEL_BIT; } while(0)

#define SET_CRZ_CONT_RUN_MODE() \
  do { REG_CRZ_CFG |= CRZ_CONFIG_CONT_RUN_BIT; } while(0)

#define SET_CRZ_SINGLE_RUN_MODE() \
  do { REG_CRZ_CFG &= ~CRZ_CONFIG_CONT_RUN_BIT; } while(0)

#define CRZ_SRC_RDMA() \
  do { REG_CRZ_CFG |= 0x1; } while(0)

#define CRZ_SRC_CAMERA_IF() \
  do { REG_CRZ_CFG &= ~0x1; } while(0)

// TODO: check this...
#define SET_CRZ_LBMAX(n) \
  do { REG_CRZ_CFG = ((REG_CRZ_CFG & (~CRZ_CTRL_LBMAX_MASK)) | (n << 16)); } while(0)

// If bypass, only CRZ_CFG.SRC is in use.
#define CRZ_BYPASS_ENABLE() \
  do { REG_CRZ_CFG |= 0x8000; } while(0)

#define CRZ_BYPASS_DISABLE() \
  do { REG_CRZ_CFG &= ~0x8000; } while(0)

/* marcos of CRZ control register */
// This macro is used to stop CRZ...
// TODO: TBD
#define RESET_CRZ() \
    do { REG_CRZ_CON = CRZ_CON_RST_BIT; \
         REG_CRZ_CON = 0; } while(0)

// TODO: TBD
#define ENABLE_CRZ() \
    do { REG_CRZ_CON = CRZ_CON_ENA_BIT; } while(0)

#define CRZ_DISABLE() \
    do { REG_CRZ_CON &= ~CRZ_CON_ENA_BIT; } while(0)

/* Macros of CRZ source image size register */
#define SET_CRZ_SRC_SIZE(width, height) \
    do { REG_CRZ_SRCSZ1 = ((width) | ((height) << 16)); } while(0)

/* Macros of CRZ target image size register */
#define SET_CRZ_TARGET_SIZE(width, height) \
    do { REG_CRZ_TARSZ1 = ((width) | ((height) << 16)); } while(0)

#define ENABLE_CRZ_DONE_INT() \
    do { REG_CRZ_CFG |= CRZ_CONFIG_DONE_INT; } while(0)

#define DISABLE_CRZ_DONE_INT() \
    do { REG_CRZ_CFG &= ~CRZ_CONFIG_DONE_INT; } while(0)

#define ENABLE_CRZ_START_INT() \
    do { REG_CRZ_CFG |= CRZ_CONFIG_START_INT; } while(0)

#define DISABLE_CRZ_START_INT() \
    do { REG_CRZ_CFG &= ~CRZ_CONFIG_START_INT; } while(0)

#define ENABLE_CRZ_HW_FRAME_SYNC() \
  do { REG_CRZ_CFG |= CRZ_CONFIG_INIT_PROCESS; } while (0)

#define DISABLE_CRZ_HW_FRAME_SYNC() \
  do { REG_CRZ_CFG &= ~CRZ_CONFIG_INIT_PROCESS; } while (0)

enum
{
    IDP_RESZ_CRZ_MASK__IMAGE_SRC,
    IDP_RESZ_CRZ_MASK__BYPASS,
    IDP_RESZ_CRZ_MASK__CONTINUOUS,
    IDP_RESZ_CRZ_MASK__HW_FRAME_SYNC,
    
    IDP_RESZ_CRZ_MASK__START_INTR_EN,
    IDP_RESZ_CRZ_MASK__START_INTR_CB,
    IDP_RESZ_CRZ_MASK__START_INTR_CB_PARAM,
    
    IDP_RESZ_CRZ_MASK__DONE_INTR_EN,
    IDP_RESZ_CRZ_MASK__DONE_INTR_CB,
    IDP_RESZ_CRZ_MASK__DONE_INTR_CB_PARAM,

    IDP_RESZ_CRZ_MASK__SRC_WIDTH,
    IDP_RESZ_CRZ_MASK__SRC_HEIGHT,

    IDP_RESZ_CRZ_MASK__TAR_WIDTH,
    IDP_RESZ_CRZ_MASK__TAR_HEIGHT,

    IDP_RESZ_CRZ_MASK__SET_USEL_DSEL,
    IDP_RESZ_CRZ_MASK__USEL,
    IDP_RESZ_CRZ_MASK__DSEL,
    
    IDP_RESZ_CRZ_MASK__SET_ECV,
    
    
    IDP_RESZ_CRZ_MASK__LAST
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
    kal_uint32                mask[(IDP_RESZ_CRZ_MASK__LAST / 32) + 1]; /**< bit map for CRZ params listed above, 
                                                                             set corresponding bit to 1 will set the 
                                                                             param to HW register */
    
    idp_module_enum_t         image_src; /**< IDP_MODULE_IMGDMA_RDMA0 or IDP_MODULE_OUTER_ISP */

    kal_bool                  bypass;
    kal_bool                  continuous;
    kal_bool                  hw_frame_sync;

    kal_bool                  start_intr_en;
    idp_lisr_intr_cb_t        start_intr_cb;
    idp_lisr_intr_cb_param_t  start_intr_cb_param;

    kal_bool                  done_intr_en; 
    idp_lisr_intr_cb_t        done_intr_cb;
    idp_lisr_intr_cb_param_t  done_intr_cb_param;

    kal_uint16                src_width;    
    kal_uint16                src_height;

    kal_uint16                tar_width;    
    kal_uint16                tar_height;

    kal_bool                  set_usel_dsel; /** KAL_TRUE, to use the following two values; KAL_FALSE, to use CRZ default values. */
    kal_uint32                usel;
    kal_uint32                dsel;
    
    kal_bool                  set_ecv;
} idp_resz_crz_struct;

IDP_HW_COMMON_API_DECLARATION(resz_crz)

extern kal_bool 
idp_resz_crz_config_real(
    idp_resz_crz_struct * const p_crz_struct, 
    kal_bool const config_to_hardware);

extern kal_bool 
idp_resz_crz_get_working_mem_real(
    kal_bool const use_internal_mem,
    idp_resz_crz_struct * const p_crz_struct,
    kal_bool const do_alloc,
    kal_uint32 const max_allowable_size);

extern kal_bool
idp_resz_crz_start_real(
    idp_resz_crz_struct const * const p_crz_struct);

extern kal_bool
idp_resz_crz_stop_real(
    idp_resz_crz_struct const * const p_crz_struct);

extern void
idp_resz_crz_open_real(void);

extern void 
idp_resz_crz_forced_reset(void);
/** @} */

#endif // #if defined(DRV_IDP_MT6236_SERIES)

#endif // #ifndef __idp_resz_crz_mt6236_h__

