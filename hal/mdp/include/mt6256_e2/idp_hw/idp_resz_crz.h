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
 *   idp_resz_crz.h
 *
 * Project:
 * --------
 *   Maui
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
 * 09 20 2011 chelun.tsai
 * removed!
 * .
 *
 * 05 27 2011 chelun.tsai
 * removed!
 * MT6526 E2 MDP driver.
 *
 * 05 19 2011 chelun.tsai
 * removed!
 * camera capture ok.
 *
 * 05 15 2011 chelun.tsai
 * removed!
 * MT6256 E2 Video playback IT ok.
 *
 * 05 05 2011 chelun.tsai
 * removed!
 * last check in befor sample back.
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_resz_crz_mt6256_e2_h__
#define __idp_resz_crz_mt6256_e2_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>
#include "drv_features_mdp.h"

#if defined(DRV_IDP_MT6256_E2_SERIES)

#include "idp_imgdma.h"
#include "idp_resz.h"
#include "idp_hw_common.h"

#include "reg_base.h"
#include "idp_core.h"

/* ===============================================================
 *                       CRZ definition
 * =============================================================== */
/** \defgroup crz Capture resizer
 * \ingroup resizer
 * @{
 */

#define CRZ_MAX_INPUT_WIDTH         (8191)
#define CRZ_MAX_INPUT_HEIGHT        (8191)
#define CRZ_MAX_OUTPUT_WIDTH        (8191)
#define CRZ_MAX_OUTPUT_HEIGHT       (8191)
#define CRZ_MAX_UPSCALE_RATIO       (64)
#define CRZ_MAX_DOWNSCALE_RATIO     (2048)
 
#ifndef MDP_C_MODEL
#define  CRZ_BASE CRZ_base
#define CRZ_CFG_REG                 (CRZ_BASE + 0x00)
#define CRZ_CON_REG                 (CRZ_BASE + 0x04)
#define CRZ_STA_REG                 (CRZ_BASE + 0x08)
#define CRZ_INT_REG                 (CRZ_BASE + 0x0C)
#define CRZ_SRCSZ1_REG              (CRZ_BASE + 0x10)
#define CRZ_TARSZ1_REG              (CRZ_BASE + 0x14)
#define CRZ_HRATIO1_REG             (CRZ_BASE + 0x18)
#define CRZ_VRATIO1_REG             (CRZ_BASE + 0x1C)
#define CRZ_LOCK_REG                (CRZ_BASE + 0x20)
#define CRZ_FRCFG_REG               (CRZ_BASE + 0x40)
#define CRZ_BUSYU_REG               (CRZ_BASE + 0x80)
#define CRZ_BUSYD_REG               (CRZ_BASE + 0x84)
#define CRZ_ORIGSZ_REG              (CRZ_BASE + 0xF0)
#define CRZ_CROPLR_REG              (CRZ_BASE + 0xF4)
#define CRZ_CROPTB_REG              (CRZ_BASE + 0xF8)

#define REG_CRZ_CFG                 *((volatile unsigned int *)(CRZ_CFG_REG))
#define REG_CRZ_CON                 *((volatile unsigned int *)(CRZ_CON_REG))
#define REG_CRZ_STA                 *((volatile unsigned int *)(CRZ_STA_REG))
#define REG_CRZ_INT                 *((volatile unsigned int *)(CRZ_INT_REG))
#define REG_CRZ_SRCSZ1              *((volatile unsigned int *)(CRZ_SRCSZ1_REG))
#define REG_CRZ_TARSZ1              *((volatile unsigned int *)(CRZ_TARSZ1_REG))
#define REG_CRZ_HRATIO1             *((volatile unsigned int *)(CRZ_HRATIO1_REG))
#define REG_CRZ_VRATIO1             *((volatile unsigned int *)(CRZ_VRATIO1_REG))
#define REG_CRZ_LOCK                *((volatile unsigned int *)(CRZ_LOCK_REG))
#define REG_CRZ_FRCFG               *((volatile unsigned int *)(CRZ_FRCFG_REG))
#define REG_CRZ_BUSYU               *((volatile unsigned int *)(CRZ_BUSYU_REG))
#define REG_CRZ_BUSYD               *((volatile unsigned int *)(CRZ_BUSYD_REG))
#define REG_CRZ_ORIGSZ              *((volatile unsigned int *)(CRZ_ORIGSZ_REG))
#define REG_CRZ_CROPLR              *((volatile unsigned int *)(CRZ_CROPLR_REG))
#define REG_CRZ_CROPTB              *((volatile unsigned int *)(CRZ_CROPTB_REG))

#else // MDP_C_MODEL
#define REG_CRZ_CFG                (CRZ_CFG    )
#define REG_CRZ_CON                (CRZ_CON    )
#define REG_CRZ_STA                (CRZ_STA    )
#define REG_CRZ_INT                (CRZ_INT    )
#define REG_CRZ_SRCSZ1             (CRZ_SRCSZ1 )
#define REG_CRZ_TARSZ1             (CRZ_TARSZ1 )
#define REG_CRZ_HRATIO1            (CRZ_HRATIO1)
#define REG_CRZ_VRATIO1            (CRZ_VRATIO1)
#define REG_CRZ_FRCFG              (CRZ_FRCFG  )
#define REG_CRZ_BUSYU              (CRZ_BUSYU  )
#define REG_CRZ_BUSYD              (CRZ_BUSYD  )
#define REG_CRZ_LOCK               *((volatile unsigned int *)(0x100000)) //do not use
#define REG_CRZ_ORIGSZ             (CRZ_ORIGSZ )
#define REG_CRZ_CROPLR             (CRZ_CROPLR )
#define REG_CRZ_CROPTB             (CRZ_CROPTB )
#endif // MDP_C_MODEL


/* bit mapping of CRZ config register */
#define CRZ_CFG_NOVS_MODE           (0x00000001)
#define CRZ_CFG_TAR                 (0x00000010)
#define CRZ_CFG_422CONV             (0x00000040)
#define CRZ_CFG_PCON                (0x00000100)
#define CRZ_CFG_LBSEL               (0x00000200)
#define CRZ_CFG_INTEN0              (0x00000400)
#define CRZ_CFG_INTEN1              (0x00000800)
#define CRZ_CFG_ECV                 (0x00001000)
#define CRZ_CFG_NORFDB              (0x00004000)
#define CRZ_CFG_BYPASS              (0x00008000)
#define CRZ_CFG_LBMAX_MASK          (0x03ff0000)
#define CRZ_CFG_ERRINTEN0           (0x04000000)
#define CRZ_CFG_ERRINTEN1           (0x08000000)
#define CRZ_CFG_VSRSTEN0            (0x20000000)
#define CRZ_CFG_VSRSTEN1            (0x40000000)
#define CRZ_CFG_INIT                (0x80000000)

/* bit mapping of CRZ control register */
#define CRZ_CON_RST_BIT             (0x00010000)
#define CRZ_CON_ENA_BIT             (0x00000001)

/* Macros of CRZ status register */
/* Output interface busy */
#define CRZ_STA_BUSYO               (0x00000001)
/* Input interface busy */
#define CRZ_STA_BUSYI               (0x00000002)
/* Crop interface busy */
#define CRZ_STA_BUSYC               (0x00000004)
/* Input pixel number is not enough */
#define CRZ_STA_ERR0                (0x00000010)
/* Output too slow */
#define CRZ_STA_ERR1                (0x00000020)
/* Init signal at output stage */
#define CRZ_STA_ERR2                (0x00000040)
/* Init signal at input stage */
#define CRZ_STA_ERR3                (0x00000080)

/* bit mapping of CRZ interrupt register */
// TODO: TBD
/* frame end interrupt */
#define CRZ_INT_FEDINT              (0x00000001)
/* frame start interrupt */
#define CRZ_INT_FSTINT              (0x00000002)
/*input pixel number is not enough*/
#define CRZ_INT_ERRINT0             (0x00000010)
/*output too slow*/
#define CRZ_INT_ERRINT1             (0x00000020)

/* bit mapping of CRZ source and target size register */
#define CRZ_IMAGE_SIZE_WIDTH_MASK   (0x00001FFF)
#define CRZ_IMAGE_SIZE_HEIGHT_MASK  (0x1FFF0000)

/* REG_CRZ_LOCK */
#define CRZ_LOCK_BIT                (0x00000001)

/* REG_CRZ_CROPLR */
#define CRZ_CROP_EN                 (0x80000000)

// busy check
#define IS_CRZ_INPUT_BUSY       (REG_CRZ_STA & CRZ_STA_BUSYI)
#define IS_CRZ_OUTPUT_BUSY      (REG_CRZ_STA & CRZ_STA_BUSYO)
#define IS_CRZ_CROP_BUSY        (REG_CRZ_STA & CRZ_STA_BUSYC)

// Check if CRZ is started or not.
#define IS_CRZ_START() \
  ((CRZ_CON_ENA_BIT == (REG_CRZ_CON & CRZ_CON_ENA_BIT)) ? KAL_TRUE : KAL_FALSE)

/* macros of CRZ config register */
#define CRZ_SET_UD_SEL(usel, dsel) \
  do { REG_CRZ_FRCFG = ((((usel) & 0x1F) << 8) | ((dsel) & 0x1F)); } while(0)

#define CRZ_FRCFG_DSEL_DEFAULT (15)
#define CRZ_FRCFG_USEL_DEFAULT (8)

//#define SET_CRZ_ECV(ecv)         \
//  do {                           \
//    REG_CRZ_CFG &= ~CRZ_CFG_ECV; \
//    REG_CRZ_CFG |= (ecv<<12);    \
//  } while(0)

// Use RESZ_LB, must use this
#define SET_CRZ_DEDICATED_MEMORY() \
  do { REG_CRZ_CFG |= CRZ_CFG_LBSEL; } while(0)

// CRZ cannot work w/o RESZ_LB
#define SET_CRZ_SHARED_MEMORY() \
  do { REG_CRZ_CFG &= ~CRZ_CFG_LBSEL; } while(0)

#define SET_CRZ_CONT_RUN_MODE() \
  do { REG_CRZ_CFG |= CRZ_CFG_PCON; } while(0)

#define SET_CRZ_SINGLE_RUN_MODE() \
  do { REG_CRZ_CFG &= ~CRZ_CFG_PCON; } while(0)

#define CRZ_SRC_NOVSYNC_MODE() \
  do { REG_CRZ_CFG |= CRZ_CFG_NOVS_MODE; } while(0)

#define CRZ_SRC_VSYNC_MODE() \
  do { REG_CRZ_CFG &= ~CRZ_CFG_NOVS_MODE; } while(0)

#define SET_CRZ_LBMAX(n) \
  do { REG_CRZ_CFG = ((REG_CRZ_CFG & (~CRZ_CFG_LBMAX_MASK)) | (n << 16)); } while(0)

// If bypass, only CRZ_CFG.SRC is in use.
#define CRZ_BYPASS_ENABLE() \
  do { REG_CRZ_CFG |= CRZ_CFG_BYPASS; } while(0)

#define CRZ_BYPASS_DISABLE() \
  do { REG_CRZ_CFG &= ~CRZ_CFG_BYPASS; } while(0)

// This macro is used to stop CRZ...
#define RESET_CRZ() \
    do { REG_CRZ_CON = CRZ_CON_RST_BIT; \
         REG_CRZ_CON = 0; } while(0)

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
    do { REG_CRZ_CFG |= CRZ_CFG_INTEN0; } while(0)

#define DISABLE_CRZ_DONE_INT() \
    do { REG_CRZ_CFG &= ~CRZ_CFG_INTEN0; } while(0)

#define ENABLE_CRZ_START_INT() \
    do { REG_CRZ_CFG |= CRZ_CFG_INTEN1; } while(0)

#define DISABLE_CRZ_START_INT() \
    do { REG_CRZ_CFG &= ~CRZ_CFG_INTEN1; } while(0)

#define ENABLE_CRZ_ERR0_INT() \
    do { REG_CRZ_CFG |= CRZ_CFG_ERRINTEN0; } while(0)

#define DISABLE_CRZ_ERR0_INT() \
    do { REG_CRZ_CFG &= ~CRZ_CFG_ERRINTEN0; } while(0)
      
#define ENABLE_CRZ_HW_FRAME_SYNC() \
  do { REG_CRZ_CFG |= CRZ_CFG_INIT; } while (0)

#define DISABLE_CRZ_HW_FRAME_SYNC() \
  do { REG_CRZ_CFG &= ~CRZ_CFG_INIT; } while (0)

#define ENABLE_CRZ_DOUBLE_REGISTER() \
  do { REG_CRZ_CFG &= ~CRZ_CFG_NORFDB; } while (0)

#define DISABLE_CRZ_DOUBLE_REGISTER() \
  do { REG_CRZ_CFG |= CRZ_CFG_NORFDB; } while (0)

#define ENABLE_CRZ_LOCK() \
  do { REG_CRZ_LOCK |= CRZ_LOCK_BIT; } while (0)
  
#define DISABLE_CRZ_LOCK() \
  do { REG_CRZ_LOCK &= ~CRZ_LOCK_BIT; } while (0)

// only use when CROP_EN = 1
#define SET_CRZ_ORIG_SIZE(w,h) \
  do { REG_CRZ_ORIGSZ = (h<<16)|(w); } while (0)

#define ENABLE_CRZ_CROP(left,right,top,bottom) \
  do { \
    REG_CRZ_CROPLR = (CRZ_CROP_EN | (left<<16) | (right)); \
    REG_CRZ_CROPTB = ((top<<16) | (bottom)); \
  } while (0)

#define DISABLE_CRZ_CROP() \
  do { REG_CRZ_CROPLR &= ~CRZ_CROP_EN; } while (0)

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
    IDP_RESZ_CRZ_MASK__IMAGE_SRC,
    IDP_RESZ_CRZ_MASK__OUTPUT_TO_OVL,
    IDP_RESZ_CRZ_MASK__OUTPUT_TO_IPP1,
    IDP_RESZ_CRZ_MASK__OUTPUT_TO_Y2R1,
    IDP_RESZ_CRZ_MASK__CONTINUS,
    IDP_RESZ_CRZ_MASK__DONE_INTR_EN,
    IDP_RESZ_CRZ_MASK__DONE_INTR_CB,
    IDP_RESZ_CRZ_MASK__DONE_INTR_CB_PARAM,
    IDP_RESZ_CRZ_MASK__START_INTR_EN,
    IDP_RESZ_CRZ_MASK__START_INTR_CB,
    IDP_RESZ_CRZ_MASK__START_INTR_CB_PARAM,
    IDP_RESZ_CRZ_MASK__SRC_HEIGHT,
    IDP_RESZ_CRZ_MASK__SRC_WIDTH,
    IDP_RESZ_CRZ_MASK__TAR_HEIGHT,
    IDP_RESZ_CRZ_MASK__TAR_WIDTH,
    IDP_RESZ_CRZ_MASK__USEL,
    IDP_RESZ_CRZ_MASK__VSEL,
    IDP_RESZ_CRZ_MASK__SET_ECV,
    IDP_RESZ_CRZ_MASK__HW_FRAME_SYNC, 
    
    IDP_RESZ_CRZ_MASK_LAST
};

typedef struct
{
    kal_uint32                mask[(IDP_RESZ_CRZ_MASK_LAST / 32) + 1];
    
    idp_module_enum_t         input_src;
    idp_module_enum_t         output_dst;

    kal_bool                  bypass;
    kal_bool                  continuous;
    kal_bool                  hw_frame_sync;
    
    kal_bool                  done_intr_en; 
    idp_lisr_intr_cb_t        done_intr_cb;
    idp_lisr_intr_cb_param_t  done_intr_cb_param;
    
    kal_bool                  start_intr_en;
    idp_lisr_intr_cb_t        start_intr_cb;
    idp_lisr_intr_cb_param_t  start_intr_cb_param;

    //kal_bool                  err0_intr_en;
    //idp_lisr_intr_cb_t        err0_intr_cb;
    //idp_lisr_intr_cb_param_t  err0_intr_cb_param;
    
    kal_bool                  crop_enable;
    kal_uint16                crop_left;
    kal_uint16                crop_right;
    kal_uint16                crop_top;
    kal_uint16                crop_bottom;
    
    kal_uint16                src_width;
    kal_uint16                src_height;
    kal_uint16                tar_width; 
    kal_uint16                tar_height;

    kal_bool                  set_usel_dsel;
    kal_uint32                usel;
    kal_uint32                dsel;
    
    kal_bool                  set_ecv;
} idp_resz_crz_struct;


    
extern void *idp_resz_crz_done_intr_cb_param;
extern void (*idp_resz_crz_done_intr_cb)(void *);

extern void *idp_resz_crz_start_intr_cb_param;
extern void (*idp_resz_crz_start_intr_cb)(void *);

extern void *idp_resz_crz_err0_intr_cb_param;
extern void (*idp_resz_crz_err0_intr_cb)(void *);

extern kal_bool
idp_resz_crz_is_busy_real(
    kal_bool * const p_busy,
    idp_resz_crz_struct const * const p_crz_struct);

extern kal_bool
idp_resz_crz_crop_update_real(
    idp_resz_crz_struct * const p_crz_struct);
    
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


IDP_HW_COMMON_API_DECLARATION(resz_crz)

#endif //#if defined(DRV_IDP_MT6256_E2_SERIES)
#endif // __idp_resz_crz_mt6256_e2_h__

