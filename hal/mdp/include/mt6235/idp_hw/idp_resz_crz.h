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
 * 09 01 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 04 15 2011 hung-wen.hsieh
 * removed!
 * .
 *
 * 12 08 2010 hung-wen.hsieh
 * removed!
 * .
 *
 * 12 01 2010 hung-wen.hsieh
 * removed!
 * .
 *
 * 11 23 2010 hung-wen.hsieh
 * removed!
 * .
 *
 * 11 09 2010 hung-wen.hsieh
 * NULL
 * MT6235 IDP V1 => V2 Check In
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_resz_crz_mt6235_h__
#define __idp_resz_crz_mt6235_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include "drv_features_mdp.h"
#include <idp_define.h>

#if defined(DRV_IDP_6235_SERIES)

#include "reg_base.h"
#include "idp_core.h"
#include "idp_resz.h"

#include <idp_define.h>
#include <idp_core.h>

#include "idp_hw_common.h"
#include "drv_comm.h"
#include "drvpdn.h"  

//modify for build pass
#define DRVPDN_CON0              (CONFIG_base+0x0300)
#define DRVPDN_CON1              (CONFIG_base+0x0304)
#define DRVPDN_CON2              (CONFIG_base+0x0308)
#define DRVPDN_CON3              (CONFIG_base+0x030c)

#define DRVPDN_CON0_SET          (CONFIG_base+0x0310)
#define DRVPDN_CON1_SET          (CONFIG_base+0x0314)
#define DRVPDN_CON2_SET          (CONFIG_base+0x0318)
#define DRVPDN_CON3_SET          (CONFIG_base+0x031c)
#define DRVPDN_CON0_CLR          (CONFIG_base+0x0320)
#define DRVPDN_CON1_CLR          (CONFIG_base+0x0324)
#define DRVPDN_CON2_CLR          (CONFIG_base+0x0328)
#define DRVPDN_CON3_CLR          (CONFIG_base+0x032c)

#define DRVPDN_CON3_ICE           0x0001
#define DRVPDN_CON3_RESZLB        0x0002
#define DRVPDN_CON3_CRZ           0x0004
#define DRVPDN_CON3_TV            0x0008
#define DRVPDN_CON3_IMGPROC       0x0010
#define DRVPDN_CON3_PNG           0x0020
#define DRVPDN_CON3_GIF           0x0040
#define DRVPDN_CON3_GCMQ          0x0080
#define DRVPDN_CON3_G2D           0x0100
#define DRVPDN_CON3_MP4           0x0200
#define DRVPDN_CON3_JPEG          0x0400
#define DRVPDN_CON3_DRZ           0x0800
#define DRVPDN_CON3_ISP           0x1000
#define DRVPDN_CON3_DCT           0x2000
#define DRVPDN_CON3_IMGDMA        0x4000
#define DRVPDN_CON3_PRZ           0x8000

#define PDN_RESZ 3

/* ===============================================================
 *                       CRZ definition
 * =============================================================== */
/** \defgroup crz Capture resizer
 * \ingroup resizer
 * @{
 */
#define  CRZ_BASE CRZ_base

#define RESZ_base                  (CRZ_base)
#define CRZ_CFG_REG                (RESZ_base + 0x00)
#define CRZ_CON_REG                (RESZ_base + 0x04)
#define CRZ_STA_REG                (RESZ_base + 0x08)
#define CRZ_INT_REG                (RESZ_base + 0x0C)
#define CRZ_SRCSZ1_REG             (RESZ_base + 0x10)
#define CRZ_TARSZ1_REG             (RESZ_base + 0x14)
#define CRZ_HRATIO1_REG            (RESZ_base + 0x18)
#define CRZ_VRATIO1_REG            (RESZ_base + 0x1C)
#define CRZ_GMC_REG                (RESZ_base + 0x3C)/*6235*/
#define CRZ_FRCFG_REG              (RESZ_base + 0x40)
#define CRZ_Y_BASE_REG             (RESZ_base + 0x44)/*6235*/
#define CRZ_U_BASE_REG             (RESZ_base + 0x48)/*6235*/
#define CRZ_V_BASE_REG             (RESZ_base + 0x4C)/*6235*/
#define CRZ_RGB_BASE1_REG          (RESZ_base + 0x84)/*6235*/
#define CRZ_RGB_BASE2_REG          (RESZ_base + 0x88)/*6235*/
#define CRZ_TMBASE_RGB1_REG        (RESZ_base + 0x84)/*6235*/
#define CRZ_TMBASE_RGB2_REG        (RESZ_base + 0x88)/*6235*/
#define CRZ_OUT_PIXEL_REG          (RESZ_base + 0xB8)/*6235*/


#define REG_CRZ_CFG                 *((volatile unsigned int *)(CRZ_CFG_REG))
#define REG_CRZ_CON                 *((volatile unsigned int *)(CRZ_CON_REG))
#define REG_CRZ_STA                 *((volatile unsigned int *)(CRZ_STA_REG))
#define REG_CRZ_INT                 *((volatile unsigned int *)(CRZ_INT_REG))
#define REG_CRZ_SRCSZ1              *((volatile unsigned int *)(CRZ_SRCSZ1_REG))
#define REG_CRZ_TARSZ1              *((volatile unsigned int *)(CRZ_TARSZ1_REG))
#define REG_CRZ_HRATIO1             *((volatile unsigned int *)(CRZ_HRATIO1_REG))
#define REG_CRZ_VRATIO1             *((volatile unsigned int *)(CRZ_VRATIO1_REG))
#define REG_CRZ_GMC                 *((volatile unsigned int *)(CRZ_GMC_REG))
#define REG_CRZ_FRCFG               *((volatile unsigned int *)(CRZ_FRCFG_REG))
#define REG_CRZ_Y_BASE              *((volatile unsigned int *)(CRZ_Y_BASE_REG))/*6235*/
#define REG_CRZ_U_BASE              *((volatile unsigned int *)(CRZ_U_BASE_REG))/*6235*/
#define REG_CRZ_V_BASE              *((volatile unsigned int *)(CRZ_V_BASE_REG))/*6235*/
#define REG_CRZ_RGB_BASE1           *((volatile unsigned int *)(CRZ_RGB_BASE1_REG))/*6235*/
#define REG_CRZ_RGB_BASE2           *((volatile unsigned int *)(CRZ_RGB_BASE2_REG))/*6235*/
#define REG_CRZ_TMBASE_RGB1         *((volatile unsigned int *)(CRZ_TMBASE_RGB1_REG))/*6235*/
#define REG_CRZ_TMBASE_RGB2         *((volatile unsigned int *)(CRZ_TMBASE_RGB2_REG))/*6235*/
#define REG_CRZ_OUT_PIXEL           *((volatile unsigned int *)(CRZ_OUT_PIXEL_REG))/*6235*/

  
#define RESZ_CONFIG_OUTPUT_FMT_MASK   (0x00000030)
#define RESZ_CONFIG_CONT_RUN_BIT      (0x00000100)
#define RESZ_CONFIG_LINE_BUF_SEL_BIT  (0x00000200)
#define RESZ_CONFIG_FRAME_START_INT   (0x00000400)
#define RESZ_CONFIG_FRAME_END_INT     (0x00000800)
#define RESZ_CONFIG_ECV               (0x00001000)
#define RESZ_CONFIG_VSRSTEN           (0x00002000)
#define RESZ_CONFIG_NORFDB            (0x00004000)
#define RESZ_CONFIG_NORRGBDB          (0x00008000)/*6235*/
#define RESZ_CTRL_LBMAX_MASK          (0x03ff0000)
  
#define RESZ_USEL_DSEL_MASK           (0x0000FFFF)
#define RESZ_GMCPIXEL_MASK            (0xFFFF0000)
  
/* bit mapping of RESZ control register */
#define RESZ_CTRL_RESET_MASK          (0x00010000)
#define RESZ_CTRL_ENABLE_MASK         (0x00000001)
#define RESZ_FRAME_END_INT_BIT        (0x1)
#define RESZ_INT_PELVRINT             (0x1)

#define RESZ_FRAME_START_INT_BIT      (0x2)
  
                           
//#define RESZ_H_RATIO_SHIFT_BITS       (20)
                           
//#define RESZ_V_RATIO_SHIFT_BITS       (20)
                           
/* macros of RESZ config register */                           
#define RESZ_OUTPUT_FMT_RGB565        (0)
#define RESZ_OUTPUT_FMT_YUV420        (1)
#define RESZ_OUTPUT_FMT_YUV422        (3)

#define SET_RESZ_OUTPUT_FMT(fmt) \
  do { \
   REG_CRZ_CFG &= ~RESZ_CONFIG_OUTPUT_FMT_MASK; \
   REG_CRZ_CFG |= (fmt<<4); \
  } while(0)

#define SET_RESZ_ADDR(addr1,addr2) \
  do { \
    REG_CRZ_TMBASE_RGB1 = addr1; \
    REG_CRZ_TMBASE_RGB2 = addr2; \
  } while(0)

#define SET_RESZ_CONT_RUN_MODE() \
  do { REG_CRZ_CFG |= RESZ_CONFIG_CONT_RUN_BIT; } while(0)

#define SET_RESZ_SINGLE_RUN_MODE() \
  do { REG_CRZ_CFG &= ~RESZ_CONFIG_CONT_RUN_BIT; } while(0)

#define SET_RESZ_DEDICATED_MEMORY() \
  do { REG_CRZ_CFG |= RESZ_CONFIG_LINE_BUF_SEL_BIT; } while(0)

#define SET_RESZ_SHARED_MEMORY() \
  do { REG_CRZ_CFG &= ~RESZ_CONFIG_LINE_BUF_SEL_BIT; } while(0)

#define ENABLE_RESZ_FS_INT() \
  do { \
    REG_CRZ_CFG |= RESZ_CONFIG_FRAME_START_INT; \
  } while(0)

#define DISABLE_RESZ_FS_INT() \
  do { \
    REG_CRZ_CFG &= ~RESZ_CONFIG_FRAME_START_INT; \
  } while(0)

#define ENABLE_RESZ_FE_INT() \
  do { \
    REG_CRZ_CFG |= RESZ_CONFIG_FRAME_END_INT; \
  } while(0)

#define DISABLE_RESZ_FE_INT() \
  do { \
    REG_CRZ_CFG &= ~RESZ_CONFIG_FRAME_END_INT; \
  } while(0)  

#define SET_RESZ_ECV(ecv) \
  do { \
    REG_CRZ_CFG &= ~RESZ_CONFIG_ECV; \
    REG_CRZ_CFG |= (ecv<<12); \
  } while(0)

#define ENABLE_RESZ_VSYNC_RST() \
  do { \
    REG_CRZ_CFG |= RESZ_CONFIG_VSRSTEN; \
  } while(0)

#define DISABLE_RESZ_VSYNC_RST() \
  do { \
    REG_CRZ_CFG &= ~RESZ_CONFIG_VSRSTEN; \
  } while(0)

#define ENABLE_RESZ_REG_DOUBLE_BUF() \
  do { \
    REG_CRZ_CFG &= ~RESZ_CONFIG_NORFDB; \
  } while(0)

#define DISABLE_RESZ_REG_DOUBLE_BUF() \
  do { \
    REG_CRZ_CFG |=RESZ_CONFIG_NORFDB; \
  } while(0)

#define ENABLE_RESZ_RGB_DOUBLE_BUF() \
  do { \
    REG_CRZ_CFG &= ~RESZ_CONFIG_NORRGBDB; \
  } while(0)
   
#define DISABLE_RESZ_RGB_DOUBLE_BUF() \
  do { \
    REG_CRZ_CFG |= RESZ_CONFIG_NORRGBDB; \
  } while(0)
    
#define SET_RESZ_LBMAX(n) \
  do { \
    REG_CRZ_CFG &= ~RESZ_CTRL_LBMAX_MASK; \
    REG_CRZ_CFG |= (n << 16); \
  } while(0)
  
#define SET_RESZ_UD_SEL(usel, dsel) \
  do { \
    REG_CRZ_FRCFG = ((REG_CRZ_FRCFG & ~RESZ_USEL_DSEL_MASK) | ((usel<<8)|(dsel))); \
  } while(0)

#define SET_RESZ_GMCPIXEL(num) \
  do { \
    REG_CRZ_FRCFG = ((REG_CRZ_FRCFG & ~RESZ_GMCPIXEL_MASK) | (num<<16)); \
  } while(0)

/* marcos of RESZ control register */
#define RESET_RESZ() \
  do { \
    REG_CRZ_CON = RESZ_CTRL_RESET_MASK; \
    REG_CRZ_CON = 0; \
  } while(0)

#define ENABLE_RESZ() \
  do { \
    REG_CRZ_CON = RESZ_CTRL_ENABLE_MASK; \
  } while(0)

#define DISABLE_RESZ() \
  do { \
    REG_CRZ_CON &= ~RESZ_CTRL_ENABLE_MASK; \
  } while(0)
  
#define RESZ_START() \
  do { \
    REG_CRZ_CON = RESZ_CTRL_ENABLE_MASK; \
  } while(0)

/* Macros of RESZ status register */
#define RESZ_STATUS_INPUT_BUSY_BIT  (1 << 0)
#define RESZ_STATUS_OUTPUT_BUSY_BIT (1 << 1)
  
#define IS_RESZ_INPUT_BUSY  (REG_CRZ_STA & RESZ_STATUS_INPUT_BUSY_BIT)
#define IS_RESZ_OUTPUT_BUSY (REG_CRZ_STA & RESZ_STATUS_OUTPUT_BUSY_BIT)
  
  
/* Macros of RESZ source image size register */
#define SET_RESZ_SRC_SIZE(width, height) \
  do { REG_CRZ_SRCSZ1 = (width | (height << 16)); } while(0)
  
/* Macros of RESZ target image size register */
#define SET_RESZ_TARGET_SIZE(width, height) \
  do { REG_CRZ_TARSZ1 = (width | (height << 16)); } while(0)
 
// power control
//modify for build pass 
/*
#define RESZ_POWERON(){}
#define RESZ_POWEROFF(){}
 */

#define RESZ_POWERON() \
    do { \
      DRVPDN_Disable(DRVPDN_CON3, DRVPDN_CON3_RESZLB, PDN_RESZ); \
      DRVPDN_Disable(DRVPDN_CON3, DRVPDN_CON3_CRZ, PDN_RESZ); \
    } while(0)

#define RESZ_POWEROFF() \
    do { \
      DRVPDN_Enable(DRVPDN_CON3, DRVPDN_CON3_RESZLB, PDN_RESZ); \
      DRVPDN_Enable(DRVPDN_CON3, DRVPDN_CON3_CRZ, PDN_RESZ); \
    } while(0)


/* Macros of get RESZ output line and pixel */
#define RESZ_OUTPUT_V_CNT     ((REG_CRZ_OUT_PIXEL & 0xFFFF0000) >> 16)
#define RESZ_OUTPUT_H_CNT     (REG_CRZ_OUT_PIXEL & 0x0000FFFF)

//#define RESZ_OUTPUT_V_CNT()\
//    do {((REG_RESZ_OUT_PIXEL & 0xFFFF0000) >> 16);} while (0)
//#define RESZ_OUTPUT_H_CNT()\ 
//    do {(REG_RESZ_OUT_PIXEL & 0x0000FFFF);} while (0)





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

typedef enum
{
  RESZ_COARSE_NONE,
  RESZ_COARSE_1_2,
  RESZ_COARSE_1_4,
  RESZ_COARSE_1_8 
} RESZ_COARSE_ENUM;



typedef struct
{
    kal_uint32                mask[(IDP_RESZ_CRZ_MASK_LAST / 32) + 1];
    
    kal_bool                  continous;
    kal_bool                  yuv_to_rgb;

    kal_bool                  hw_frame_sync;
    
    kal_bool                  done_intr_en; 
    idp_lisr_intr_cb_t        done_intr_cb;
    idp_lisr_intr_cb_param_t  done_intr_cb_param;
    
    kal_bool                  start_intr_en;
    idp_lisr_intr_cb_t        start_intr_cb;
    idp_lisr_intr_cb_param_t  start_intr_cb_param;
  
    kal_uint16                int_en;
    RESZ_COARSE_ENUM          coarse_resize;
    
    kal_uint16                source_height;
    kal_uint16                source_width;
    
    kal_uint16                target_height;
    kal_uint16                target_width; 

    kal_bool                  set_usel_dsel;
    kal_uint32                usel;
    kal_uint32                dsel;

    kal_uint32                fmt;

    /* RGB565 target base address */
    kal_uint32                rgb_tar_base1;
    kal_uint32                rgb_tar_base2;

    /* YUV420 target base address */
    kal_uint32                y_tar_base;
    kal_uint32                u_tar_base;
    kal_uint32                v_tar_base;

    /* base address of working memory */
    kal_uint32                wmbase;
    kal_uint32                wmsize;
    
    kal_bool                  set_ecv;
} idp_resz_crz_struct;

IDP_HW_COMMON_API_DECLARATION(resz_crz)
    
extern void *idp_resz_crz_done_intr_cb_param;
extern void (*idp_resz_crz_done_intr_cb)(void *);

extern void *idp_resz_crz_start_intr_cb_param;
extern void (*idp_resz_crz_start_intr_cb)(void *);


extern kal_bool 
idp_resz_crz_config_real(
    idp_resz_crz_struct * const p_crz_struct, 
    kal_bool const config_to_hardware);

extern kal_bool 
idp_resz_crz_update_real(
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
/** @} */

#endif // #if defined(DRV_IDP_6235_SERIES)
#endif // __idp_resz_crz_mt6235_h__
