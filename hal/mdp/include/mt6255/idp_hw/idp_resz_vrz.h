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
 * 05 08 2012 chrono.wu
 * removed!
 * .
 *
 * 11 29 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 10 25 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 09 24 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 09 13 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_resz_vrz_mt6255_h__
#define __idp_resz_vrz_mt6255_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include "drv_features_mdp.h"

#if defined(DRV_IDP_MT6255_SERIES)

#include "idp_resz.h"
#include "idp_hw_common.h"

#include "idp_core.h"

/* ===============================================================
 *                       VRZ definition
 * =============================================================== */
/** \defgroup vrz Drop resizer
 * \ingroup resizer
 * @{
 */
#ifndef MDP_C_MODEL
#define VRZ_BASE VRZ_base
#define VRZ_CFG_REG             (VRZ_BASE + 0x0000) 
#define VRZ_CON_REG             (VRZ_BASE + 0x0004)
#define VRZ_STA_REG             (VRZ_BASE + 0x0008)
#define VRZ_INT_REG             (VRZ_BASE + 0x000C)
#define VRZ_SRCSZ_REG           (VRZ_BASE + 0x0010)
#define VRZ_TARSZ_REG           (VRZ_BASE + 0x0014)
#define VRZ_HRATIO_REG          (VRZ_BASE + 0x0018)
#define VRZ_VRATIO_REG          (VRZ_BASE + 0x001C)
#define VRZ_HRES_REG            (VRZ_BASE + 0x0020)
#define VRZ_VRES_REG            (VRZ_BASE + 0x0024)
#define VRZ_LOCK_REG            (VRZ_BASE + 0x002C)
#define VRZ_ORIGSZ_REG          (VRZ_BASE + 0x0030)
#define VRZ_CROPLR_REG          (VRZ_BASE + 0x0034)
#define VRZ_CROPTB_REG          (VRZ_BASE + 0x0038)
#define VRZ_FRCFG_REG           (VRZ_BASE + 0x0040)

#define REG_VRZ_CFG          *((volatile unsigned int *)(VRZ_CFG_REG))        
#define REG_VRZ_CON          *((volatile unsigned int *)(VRZ_CON_REG))        
#define REG_VRZ_STA          *((volatile unsigned int *)(VRZ_STA_REG))        
#define REG_VRZ_INT          *((volatile unsigned int *)(VRZ_INT_REG))        
#define REG_VRZ_SRCSZ        *((volatile unsigned int *)(VRZ_SRCSZ_REG))      
#define REG_VRZ_TARSZ        *((volatile unsigned int *)(VRZ_TARSZ_REG))      
#define REG_VRZ_HRATIO       *((volatile unsigned int *)(VRZ_HRATIO_REG))      
#define REG_VRZ_VRATIO       *((volatile unsigned int *)(VRZ_VRATIO_REG))     
#define REG_VRZ_HRES         *((volatile unsigned int *)(VRZ_HRES_REG))        
#define REG_VRZ_VRES         *((volatile unsigned int *)(VRZ_VRES_REG))       
#define REG_VRZ_LOCK         *((volatile unsigned int *)(VRZ_LOCK_REG))       
#define REG_VRZ_ORIGSZ       *((volatile unsigned int *)(VRZ_ORIGSZ_REG))       
#define REG_VRZ_CROPLR       *((volatile unsigned int *)(VRZ_CROPLR_REG))       
#define REG_VRZ_CROPTB       *((volatile unsigned int *)(VRZ_CROPTB_REG))       
#define REG_VRZ_FRCFG        *((volatile unsigned int *)(VRZ_FRCFG_REG))      

#else // #if !defined(MDP_C_MODEL)
#define REG_VRZ_CFG          (VRZ_CFG)        
#define REG_VRZ_CON          (VRZ_CON)
#define REG_VRZ_STA          (VRZ_STA)
#define REG_VRZ_INT          (VRZ_INT)        
#define REG_VRZ_SRCSZ        (VRZ_SRCSZ)      
#define REG_VRZ_TARSZ        (VRZ_TARSZ)      
#define REG_VRZ_HRATIO       (VRZ_HRATIO)      
#define REG_VRZ_VRATIO       (VRZ_VRATIO)     
#define REG_VRZ_HRES         (VRZ_HRES)        
#define REG_VRZ_VRES         (VRZ_VRES)       
#define REG_VRZ_LOCK         (VRZ_LOCK)       
#define REG_VRZ_ORIGSZ       (VRZ_ORIGSZ)       
#define REG_VRZ_CROPLR       (VRZ_CROPLR)       
#define REG_VRZ_CROPTB       (VRZ_CROPTB)       
#define REG_VRZ_FRCFG        (VRZ_FRCFG)      

#endif // #if !defined(MDP_C_MODEL)


#define VRZ_CFG_INITEN_BIT  0x80000000
#define VRZ_CFG_BYPASS_BIT  0x00008000
#define VRZ_CFG_NODB_BIT    0x00004000

#define VRZ_CFG_INTEN_BIT   0x00000400
#define VRZ_CFG_PCON_BIT    0x00000100

#define VRZ_CON_ENA_BIT     0x00000001
#define VRZ_CON_RST_BIT     0x00010000

#define VRZ_INT_INT_BIT     0x00000001

#define VRZ_FRCFG_WMSZ_MASK     0x003f0000
#define VRZ_FRCFG_SAEN_BIT      0x00000002
#define VRZ_FRCFG_VRSS_BIT      0x00000001
/** REG_VRZ_LOCK */
#define VRZ_LOCK_BIT 0x01
/** REG_VRZ_CROPLR */
#define VRZ_CROP_EN 0x80000000

#define VRZ_BYPASS_ENABLE() \
  do { REG_VRZ_CFG |= VRZ_CFG_BYPASS_BIT; } while(0)

#define VRZ_BYPASS_DISABLE() \
  do { REG_VRZ_CFG &= ~VRZ_CFG_BYPASS_BIT; } while(0)

#define VRZ_INTERRUPT_ENABLE() \
  do { REG_VRZ_CFG |= VRZ_CFG_INTEN_BIT; } while(0)
    
#define VRZ_INTERRUPT_DISABLE() \
  do { REG_VRZ_CFG &= ~VRZ_CFG_INTEN_BIT; } while(0)

#define ENABLE_VRZ_DOUBLE_REGISTER() \
  do { REG_VRZ_CFG &= ~VRZ_CFG_NODB_BIT; } while (0)
    
#define DISABLE_VRZ_DOUBLE_REGISTER() \
  do { REG_VRZ_CFG |= VRZ_CFG_NODB_BIT; } while (0)


#define VRZ_ENABLE_HW_FRAME_SYNC() \
  do { REG_VRZ_CFG |= VRZ_CFG_INITEN_BIT; } while (0)

#define VRZ_DISABLE_HW_FRAME_SYNC() \
  do { REG_VRZ_CFG &= ~VRZ_CFG_INITEN_BIT; } while (0)

#define VRZ_SET_CONT_RUN_MODE() \
  do { REG_VRZ_CFG |= VRZ_CFG_PCON_BIT; } while(0)

#define VRZ_SET_SINGLE_RUN_MODE() \
  do { REG_VRZ_CFG &= ~VRZ_CFG_PCON_BIT; } while(0)

#define VRZ_RESET() \
  do { REG_VRZ_CON = VRZ_CON_RST_BIT; \
       REG_VRZ_CON = 0; } while(0)

#define VRZ_IS_STARTED() \
   ((VRZ_CON_ENA_BIT == (REG_VRZ_CON & VRZ_CON_ENA_BIT)) ? KAL_TRUE : KAL_FALSE)

#define VRZ_START() \
  do { REG_VRZ_CON = VRZ_CON_ENA_BIT; } while(0)

#define VRZ_STOP() \
  do { REG_VRZ_CON &= ~VRZ_CON_ENA_BIT; } while(0)

#define VRZ_SET_SRC_SIZE(width, height) \
  do { REG_VRZ_SRCSZ = ((width) | ((height) << 16)); } while(0)

#define VRZ_SET_TARGET_SIZE(width, height) \
  do { REG_VRZ_TARSZ = ((width) | ((height) << 16)); } while(0)

#define VRZ_SET_WMSZ(n) \
  do { REG_VRZ_FRCFG = ((REG_VRZ_FRCFG & (~VRZ_FRCFG_WMSZ_MASK)) | (n << 16)); } while(0)

#define VRZ_SET_SRC_ACCUM_MODE() \
  do { REG_VRZ_FRCFG |= VRZ_FRCFG_SAEN_BIT; } while(0)

#define VRZ_SET_BILINEAR_MODE() \
  do { REG_VRZ_FRCFG &= ~VRZ_FRCFG_SAEN_BIT; } while(0)

#define ENABLE_VRZ_LOCK() \
  do { REG_VRZ_LOCK |= VRZ_LOCK_BIT; } while (0)
    
#define DISABLE_VRZ_LOCK() \
  do { REG_VRZ_LOCK &= ~VRZ_LOCK_BIT; } while (0)
  
#define SET_VRZ_ORIG_SIZE(w,h) \
  do { REG_VRZ_ORIGSZ = (h<<16)|(w); } while (0)
  
#define ENABLE_VRZ_CROP(left,right,top,bottom) \
  do { \
    REG_VRZ_CROPLR = (VRZ_CROP_EN | (left<<16) | (right)); \
    REG_VRZ_CROPTB = ((top<<16) | (bottom)); \
  } while (0)
  
#define DISABLE_VRZ_CROP() \
  do { REG_VRZ_CROPLR &= ~VRZ_CROP_EN; } while (0)

typedef struct
{
    kal_bool                  auto_restart;
    idp_module_enum_t         input_src;
    idp_module_enum_t         output_dst;

    kal_bool                  hw_frame_sync;
    kal_bool                  bypass;

    kal_bool                  intr_en;
    idp_lisr_intr_cb_t        intr_cb;
    idp_lisr_intr_cb_param_t  intr_cb_param;
    
    kal_bool                  src_accum_mode; /*Source accumulation downscaling mode */
    kal_uint16                coarse_ratio; /*[0,3] Horizontal coarse shrink*/
    kal_uint16                line_size;
    kal_uint16                src_height; /**< [1, 4095] */
    kal_uint16                src_width; /**< [1, 4095] */
    kal_uint16                tar_height; /**< [1, 4095] */
    kal_uint16                tar_width; /**< [1, 4095] */
    kal_uint32                wm_addr;

    kal_bool                  crop_enable;
    kal_uint16                crop_left;
    kal_uint16                crop_right;
    kal_uint16                crop_top;
    kal_uint16                crop_bottom;

} idp_resz_vrz_struct;
/** @} */

IDP_HW_COMMON_API_DECLARATION(resz_vrz)

extern void *idp_resz_vrz_intr_cb_param;
extern void (*idp_resz_vrz_intr_cb)(void *);

extern kal_bool 
idp_resz_vrz_config_real(
    idp_resz_vrz_struct * const p_vrz_struct, 
    kal_bool const config_to_hardware);

extern kal_bool 
idp_resz_vrz_get_working_mem_real(
    kal_bool const use_internal_mem,
    idp_resz_vrz_struct * const p_vrz_struct,
    kal_bool const do_alloc,
    kal_uint32 const max_allowable_size);

extern void
idp_resz_vrz_open_real(void);

extern kal_bool
idp_resz_vrz_start_real(
    idp_resz_vrz_struct const * const p_vrz_struct);

extern kal_bool
idp_resz_vrz_stop_real(
    idp_resz_vrz_struct const * const p_vrz_struct);

#endif // #if defined(DRV_IDP_MT6255_SERIES)
#endif // __idp_resz_vrz_mt6255_h__
