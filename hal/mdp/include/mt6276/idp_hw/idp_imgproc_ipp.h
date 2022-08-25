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
 * 10 12 2011 chrono.wu
 * removed!
 * .
 *
 * 01 07 2011 chrono.wu
 * removed!
 * .
 *
 * 12 06 2010 gellmann.chang
 * removed!
 * .
 *
 * 11 23 2010 gellmann.chang
 * removed!
 * .
 *
 * 10 18 2010 holmes.chiou
 * removed!
 * .
 *
 * removed!
 * removed!
 * MT6255 HQA check-in
 *
 * removed!
 * removed!
 * DVT check-in
 *
 * removed!
 * removed!
 * MDP driver
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_imgproc_ipp_mt6276_h__
#define __idp_imgproc_ipp_mt6276_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>

#if defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6256_SERIES) || defined(DRV_IDP_MT6276E2_SERIES)

#include "idp_imgproc.h"
#include "idp_hw_common.h"
#include "idp_image_effect_pixel.h"
#include "reg_base.h"
#include "idp_core.h"

/* register definition of IMGPROC IPP config*/
#ifndef MDP_C_MODEL
#define IMGPROC_BASE    IMGPROC_base
#define IMGPROC_IPP_CFG_REG             (IMGPROC_BASE + 0x0000)
#define IMGPROC_R2Y_CFG_REG             (IMGPROC_BASE + 0x0004)
#define IMGPROC_HUE11_REG               (IMGPROC_BASE + 0x0100)
#define IMGPROC_HUE12_REG               (IMGPROC_BASE + 0x0104)
#define IMGPROC_HUE21_REG               (IMGPROC_BASE + 0x0108)
#define IMGPROC_HUE22_REG               (IMGPROC_BASE + 0x010C)
#define IMGPROC_SAT_REG                 (IMGPROC_BASE + 0x0110)
#define IMGPROC_BRIADJ1_REG             (IMGPROC_BASE + 0x0120)
#define IMGPROC_BRIADJ2_REG             (IMGPROC_BASE + 0x0124)
#define IMGPROC_CONADJ_REG              (IMGPROC_BASE + 0x0128)
#define IMGPROC_COLORIZEU_REG           (IMGPROC_BASE + 0x0130)
#define IMGPROC_COLORIZEV_REG           (IMGPROC_BASE + 0x0134)
#define IMGPROC_COLOR1R_OFFX_REG        (IMGPROC_BASE + 0x0200)
#define IMGPROC_COLOR2R_OFFX_REG        (IMGPROC_BASE + 0x0204)
#define IMGPROC_COLOR1G_OFFX_REG        (IMGPROC_BASE + 0x0208)
#define IMGPROC_COLOR2G_OFFX_REG        (IMGPROC_BASE + 0x020C)
#define IMGPROC_COLOR1B_OFFX_REG        (IMGPROC_BASE + 0x0210)
#define IMGPROC_COLOR2B_OFFX_REG        (IMGPROC_BASE + 0x0214)
#define IMGPROC_COLOR1R_OFFY_REG        (IMGPROC_BASE + 0x0220)
#define IMGPROC_COLOR2R_OFFY_REG        (IMGPROC_BASE + 0x0224)
#define IMGPROC_COLOR1G_OFFY_REG        (IMGPROC_BASE + 0x0228)
#define IMGPROC_COLOR2G_OFFY_REG        (IMGPROC_BASE + 0x022C)
#define IMGPROC_COLOR1B_OFFY_REG        (IMGPROC_BASE + 0x0230)
#define IMGPROC_COLOR2B_OFFY_REG        (IMGPROC_BASE + 0x0234)
#define IMGPROC_COLOR0R_SLP_REG         (IMGPROC_BASE + 0x0240)
#define IMGPROC_COLOR1R_SLP_REG         (IMGPROC_BASE + 0x0244)
#define IMGPROC_COLOR2R_SLP_REG         (IMGPROC_BASE + 0x0248)
#define IMGPROC_COLOR0G_SLP_REG         (IMGPROC_BASE + 0x0250)
#define IMGPROC_COLOR1G_SLP_REG         (IMGPROC_BASE + 0x0254)
#define IMGPROC_COLOR2G_SLP_REG         (IMGPROC_BASE + 0x0258)
#define IMGPROC_COLOR0B_SLP_REG         (IMGPROC_BASE + 0x0260)
#define IMGPROC_COLOR1B_SLP_REG         (IMGPROC_BASE + 0x0264)
#define IMGPROC_COLOR2B_SLP_REG         (IMGPROC_BASE + 0x0268)
#define IMGPROC_EN_REG                  (IMGPROC_BASE + 0x0320)
#define IMGPROC_IPP_RGB_DETECT_REG      (IMGPROC_BASE + 0x0324)
#define IMGPROC_IPP_RGB_REPLACE_REG     (IMGPROC_BASE + 0x0328)

#define REG_IMGPROC_IPP_CFG             *((volatile unsigned int *)(IMGPROC_IPP_CFG_REG))
#define REG_IMGPROC_R2Y_CFG             *((volatile unsigned int *)(IMGPROC_R2Y_CFG_REG))
#define REG_IMGPROC_HUE11               *((volatile unsigned int *)(IMGPROC_HUE11_REG))
#define REG_IMGPROC_HUE12               *((volatile unsigned int *)(IMGPROC_HUE12_REG))
#define REG_IMGPROC_HUE21               *((volatile unsigned int *)(IMGPROC_HUE21_REG))
#define REG_IMGPROC_HUE22               *((volatile unsigned int *)(IMGPROC_HUE22_REG))
#define REG_IMGPROC_SAT                 *((volatile unsigned int *)(IMGPROC_SAT_REG))
#define REG_IMGPROC_BRIADJ1             *((volatile unsigned int *)(IMGPROC_BRIADJ1_REG))
#define REG_IMGPROC_BRIADJ2             *((volatile unsigned int *)(IMGPROC_BRIADJ2_REG))
#define REG_IMGPROC_CONADJ              *((volatile unsigned int *)(IMGPROC_CONADJ_REG))
#define REG_IMGPROC_COLORIZEU           *((volatile unsigned int *)(IMGPROC_COLORIZEU_REG))
#define REG_IMGPROC_COLORIZEV           *((volatile unsigned int *)(IMGPROC_COLORIZEV_REG))
#define REG_IMGPROC_COLOR1R_OFFX        *((volatile unsigned int *)(IMGPROC_COLOR1R_OFFX_REG))
#define REG_IMGPROC_COLOR2R_OFFX        *((volatile unsigned int *)(IMGPROC_COLOR2R_OFFX_REG))
#define REG_IMGPROC_COLOR1G_OFFX        *((volatile unsigned int *)(IMGPROC_COLOR1G_OFFX_REG))
#define REG_IMGPROC_COLOR2G_OFFX        *((volatile unsigned int *)(IMGPROC_COLOR2G_OFFX_REG))
#define REG_IMGPROC_COLOR1B_OFFX        *((volatile unsigned int *)(IMGPROC_COLOR1B_OFFX_REG))
#define REG_IMGPROC_COLOR2B_OFFX        *((volatile unsigned int *)(IMGPROC_COLOR2B_OFFX_REG))
#define REG_IMGPROC_COLOR1R_OFFY        *((volatile unsigned int *)(IMGPROC_COLOR1R_OFFY_REG))
#define REG_IMGPROC_COLOR2R_OFFY        *((volatile unsigned int *)(IMGPROC_COLOR2R_OFFY_REG))
#define REG_IMGPROC_COLOR1G_OFFY        *((volatile unsigned int *)(IMGPROC_COLOR1G_OFFY_REG))
#define REG_IMGPROC_COLOR2G_OFFY        *((volatile unsigned int *)(IMGPROC_COLOR2G_OFFY_REG))
#define REG_IMGPROC_COLOR1B_OFFY        *((volatile unsigned int *)(IMGPROC_COLOR1B_OFFY_REG))
#define REG_IMGPROC_COLOR2B_OFFY        *((volatile unsigned int *)(IMGPROC_COLOR2B_OFFY_REG))
#define REG_IMGPROC_COLOR0R_SLP         *((volatile unsigned int *)(IMGPROC_COLOR0R_SLP_REG))
#define REG_IMGPROC_COLOR1R_SLP         *((volatile unsigned int *)(IMGPROC_COLOR1R_SLP_REG))
#define REG_IMGPROC_COLOR2R_SLP         *((volatile unsigned int *)(IMGPROC_COLOR2R_SLP_REG))
#define REG_IMGPROC_COLOR0G_SLP         *((volatile unsigned int *)(IMGPROC_COLOR0G_SLP_REG))
#define REG_IMGPROC_COLOR1G_SLP         *((volatile unsigned int *)(IMGPROC_COLOR1G_SLP_REG))
#define REG_IMGPROC_COLOR2G_SLP         *((volatile unsigned int *)(IMGPROC_COLOR2G_SLP_REG))
#define REG_IMGPROC_COLOR0B_SLP         *((volatile unsigned int *)(IMGPROC_COLOR0B_SLP_REG))
#define REG_IMGPROC_COLOR1B_SLP         *((volatile unsigned int *)(IMGPROC_COLOR1B_SLP_REG))
#define REG_IMGPROC_COLOR2B_SLP         *((volatile unsigned int *)(IMGPROC_COLOR2B_SLP_REG))
#define REG_IMGPROC_EN                  *((volatile unsigned int *)(IMGPROC_EN_REG))
#define REG_IMGPROC_IPP_RGB_DETECT      *((volatile unsigned int *)(IMGPROC_IPP_RGB_DETECT_REG))
#define REG_IMGPROC_IPP_RGB_REPLACE     *((volatile unsigned int *)(IMGPROC_IPP_RGB_REPLACE_REG))
#else // MDP_C_MODEL
#define REG_IMGPROC_IPP_CFG             IMGPROC_IPP_CFG
#define REG_IMGPROC_R2Y_CFG             IMGPROC_R2Y_CFG
#define REG_IMGPROC_HUE11               IMGPROC_HUE11
#define REG_IMGPROC_HUE12               IMGPROC_HUE12
#define REG_IMGPROC_HUE21               IMGPROC_HUE21
#define REG_IMGPROC_HUE22               IMGPROC_HUE22
#define REG_IMGPROC_SAT                 IMGPROC_SATADJ
#define REG_IMGPROC_BRIADJ1             IMGPROC_BRIADJ1
#define REG_IMGPROC_BRIADJ2             IMGPROC_BRIADJ2
#define REG_IMGPROC_CONADJ              IMGPROC_CONADJ
#define REG_IMGPROC_COLORIZEU           IMGPROC_COLORIZEU
#define REG_IMGPROC_COLORIZEV           IMGPROC_COLORIZEV
#define REG_IMGPROC_COLOR1R_OFFX        IMGPROC_COLOR1R_OFFX
#define REG_IMGPROC_COLOR2R_OFFX        IMGPROC_COLOR2R_OFFX
#define REG_IMGPROC_COLOR1G_OFFX        IMGPROC_COLOR1G_OFFX
#define REG_IMGPROC_COLOR2G_OFFX        IMGPROC_COLOR2G_OFFX
#define REG_IMGPROC_COLOR1B_OFFX        IMGPROC_COLOR1B_OFFX
#define REG_IMGPROC_COLOR2B_OFFX        IMGPROC_COLOR2B_OFFX
#define REG_IMGPROC_COLOR1R_OFFY        IMGPROC_COLOR1R_OFFY
#define REG_IMGPROC_COLOR2R_OFFY        IMGPROC_COLOR2R_OFFY
#define REG_IMGPROC_COLOR1G_OFFY        IMGPROC_COLOR1G_OFFY
#define REG_IMGPROC_COLOR2G_OFFY        IMGPROC_COLOR2G_OFFY
#define REG_IMGPROC_COLOR1B_OFFY        IMGPROC_COLOR1B_OFFY
#define REG_IMGPROC_COLOR2B_OFFY        IMGPROC_COLOR2B_OFFY
#define REG_IMGPROC_COLOR0R_SLP         IMGPROC_COLOR0R_SLOPE
#define REG_IMGPROC_COLOR1R_SLP         IMGPROC_COLOR1R_SLOPE
#define REG_IMGPROC_COLOR2R_SLP         IMGPROC_COLOR2R_SLOPE
#define REG_IMGPROC_COLOR0G_SLP         IMGPROC_COLOR0G_SLOPE
#define REG_IMGPROC_COLOR1G_SLP         IMGPROC_COLOR1G_SLOPE
#define REG_IMGPROC_COLOR2G_SLP         IMGPROC_COLOR2G_SLOPE
#define REG_IMGPROC_COLOR0B_SLP         IMGPROC_COLOR0B_SLOPE
#define REG_IMGPROC_COLOR1B_SLP         IMGPROC_COLOR1B_SLOPE
#define REG_IMGPROC_COLOR2B_SLP         IMGPROC_COLOR2B_SLOPE
#define REG_IMGPROC_EN                  IMGPROC_EN
#define REG_IMGPROC_IPP_RGB_DETECT      IMGPROC_IPP_RGB_DETECT
#define REG_IMGPROC_IPP_RGB_REPLACE     IMGPROC_IPP_RGB_REPLACE
#endif // MDP_C_MODEL
 
/* bit define of IMGPROC_IPP_CFG */
//#define IMGPROC_IPP_NR_EN_BIT                 0X00000001 /**< No such function in MT6276 IPP */
#define IMGPROC_IPP_CB_EN_BIT                   0X00000010
#define IMGPROC_IPP_HUE_EN_BIT                  0X00000020
#define IMGPROC_IPP_SAT_EN_BIT                  0X00000100
#define IMGPROC_IPP_CLRIZE_EN_BIT               0X00000200
//#define IMGPROC_IPP_SDT_EN_BIT                0X00001000 /**< No such function in MT6276 IPP */
#define IMGPROC_IPP_Y2R0_EN_BIT                 0X00010000
#define IMGPROC_IPP_ROUND_Y2R_BIT               0X00020000
#define IMGPROC_IPP_CLRADJ_EN_BIT               0X00100000
//#define IMGPROC_IPP_GAMMA_EN_BIT              0X01000000 /**< No such function in MT6276 IPP */
#define IMGPROC_IPP_INV_EN_BIT                  0X10000000
//#define IMGPROC_IPP_SDT1_EN_BIT               0X20000000 /**< No such function in MT6276 IPP */
#define IMGPROC_IPP_RGB_DETECT_EN_BIT           0X40000000

/* bit mapping of IMGPROC_R2Y_CFG */
#define IMGPROC_R2Y_CFG_R2Y_EN                  0x00000001
#define IMGPROC_R2Y_CFG_ROUND_R2Y               0x00000002

/*bit define of IMGPROC_IPP_SDTCON*/ 
// TODO: TBD
#define IMGPROC_DITHERING_BD1_MASK              (0X0700)
#define IMGPROC_DITHERING_BD2_MASK              (0X0070)
#define IMGPROC_DITHERING_BD3_MASK              (0X0007)
#define IMGPROC_DITHERING_SEED1_MASK            (0XF00000)
#define IMGPROC_DITHERING_SEED2_MASK            (0XF0000)
#define IMGPROC_DITHERING_SEED3_MASK            (0XF000)

// TODO: TBD
#define IPP_FILTER_NONE                         0x0
#define IPP_FILTER_LINEAR_LP                    0x5
#define IPP_FILTER_LINEAR_HP                    0x6
#define IPP_FILTER_LINEAR_HP_SCALE_DOWN         0x7
#define IPP_FILTER_BLUR                         0x9
#define IPP_FILTER_MORE_BLUR                    0xA
#define IPP_FILTER_UNSHARP                      0xB
#define IPP_FILTER_MAXIMUM_RANKING              0xC
#define IPP_FILTER_MEDIAN_RANKING               0xD
#define IPP_FILTER_MINIMUM_RANKING              0xE

#define IPP_COLOR_RGB565                        0
#define IPP_COLOR_RGB888                        1

// Macros
// Set IPP bypass mode...MT6276 IPP and R2Y are combined into one
#define IMGPROC_IPP_BYPASS_MODE() \
    do { REG_IMGPROC_IPP_CFG = 0x0; \
         REG_IMGPROC_R2Y_CFG = 0x0; } while(0)

#define IMGPROC_IPP_START() \
    do { REG_IMGPROC_EN |= 0x1001; } while(0)

#define IMGPROC_IPP_STOP() \
    do { REG_IMGPROC_EN &= ~0x1; } while(0)

#define IMGPROC_IPP_RESET() \
    do { REG_IMGPROC_EN &= ~0x1000; \
         REG_IMGPROC_EN |= 0x1000; } while(0)

#define IMGPROC_IPP_FRAME_SYNC_ENABLE() \
    do { REG_IMGPROC_EN |= 0x2000; } while(0)

#define IMGPROC_IPP_FRAME_SYNC_DISABLE() \
    do { REG_IMGPROC_EN &= ~0x2000; } while(0)

#define ENABLE_IPP_CB()             REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_CB_EN_BIT;
#define DISABLE_IPP_CB()            REG_IMGPROC_IPP_CFG &= ~IMGPROC_IPP_CB_EN_BIT; 
#define ENABLE_IPP_HUE()            REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_HUE_EN_BIT;
#define DISABLE_IPP_HUE()           REG_IMGPROC_IPP_CFG &= ~IMGPROC_IPP_HUE_EN_BIT;
#define ENABLE_IPP_SAT()            REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_SAT_EN_BIT;
#define DISABLE_IPP_SAT()           REG_IMGPROC_IPP_CFG &= ~IMGPROC_IPP_SAT_EN_BIT;
#define ENABLE_IPP_CLRIZE()         REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_CLRIZE_EN_BIT;
#define DISABLE_IPP_CLRIZE()        REG_IMGPROC_IPP_CFG &= IMGPROC_IPP_CLRIZE_EN_BIT
#define ENABLE_IPP_Y2R()            REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_Y2R0_EN_BIT;
#define DISABLE_IPP_Y2R()           REG_IMGPROC_IPP_CFG &= ~IMGPROC_IPP_Y2R0_EN_BIT;
#define ENABLE_IPP_ROUND_Y2R()      REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_ROUND_Y2R_BIT
#define DISABLE_IPP_ROUND_Y2R()     REG_IMGPROC_IPP_CFG &= ~IMGPROC_IPP_ROUND_Y2R_BIT; 
#define ENABLE_IPP_CLRADJ()         REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_CLRADJ_EN_BIT;
#define DISABLE_IPP_CLRADJ()        REG_IMGPROC_IPP_CFG &= ~IMGPROC_IPP_CLRADJ_EN_BIT;   
#define ENABLE_IPP_INV()            REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_INV_EN_BIT;
#define DISABLE_IPP_INV()           REG_IMGPROC_IPP_CFG &= ~IMGPROC_IPP_INV_EN_BIT;
#define ENABLE_IPP_RGB_DETECT()     REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_RGB_DETECT_EN_BIT;
#define DISABLE_IPP_RGB_DETECT()    REG_IMGPROC_IPP_CFG &= ~IMGPROC_IPP_RGB_DETECT_EN_BIT;

#define ENABLE_IPP_R2Y()            REG_IMGPROC_R2Y_CFG |= IMGPROC_R2Y_CFG_R2Y_EN;
#define DISABLE_IPP_R2Y()           REG_IMGPROC_R2Y_CFG &= ~IMGPROC_R2Y_CFG_R2Y_EN;
#define ENABLE_IPP_ROUND_R2Y()      REG_IMGPROC_R2Y_CFG |= IMGPROC_R2Y_CFG_ROUND_R2Y;
#define DISABLE_IPP_ROUND_R2Y()     REG_IMGPROC_R2Y_CFG &= ~IMGPROC_R2Y_CFG_ROUND_R2Y;

#define SET_IMGPROC_HUE11(hue)      REG_IMGPROC_HUE11 = (hue)&0xff;
#define SET_IMGPROC_HUE12(hue)      REG_IMGPROC_HUE12 = (hue)&0xff;
#define SET_IMGPROC_HUE21(hue)      REG_IMGPROC_HUE21 = (hue)&0xff;
#define SET_IMGPROC_HUE22(hue)      REG_IMGPROC_HUE22 = (hue)&0xff;

#define SET_IMGPROC_SATADJ(sat)     REG_IMGPROC_SAT = (sat)&0x7f;

#define SET_IMGPROC_BRIADJ1(bri)    REG_IMGPROC_BRIADJ1 = (bri)&0xff;
#define SET_IMGPROC_BRIADJ2(dark)   REG_IMGPROC_BRIADJ2 = (dark)&0xff;

#define SET_IMGPROC_CONADJ(con)     REG_IMGPROC_CONADJ = (con)&0xff;

#define SET_IMGPROC_COLORIZE_U(u)   REG_IMGPROC_COLORIZEU = (u)&0xff;
#define SET_IMGPROC_COLORIZE_V(v)   REG_IMGPROC_COLORIZEV = (v)&0xff;

#define SET_IPP_RGB_DETECT(r,g,b)   REG_IMGPROC_IPP_RGB_DETECT = (((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff);
#define SET_IPP_RGB_REPLACE(r,g,b)  REG_IMGPROC_IPP_RGB_REPLACE = (((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff);

#define SET_IPP_HUE_SAT(n)                      \
  do {                                          \
    DISABLE_IPP_CLRIZE();                       \
    DISABLE_IPP_HUE();                          \
    DISABLE_IPP_SAT();                          \
                                                \
    switch (n)                                  \
    {                                           \
    case IDP_IMAGE_EFFECT_PIXEL_HSA_NONE:       \
      break;                                    \
                                                \
    case IDP_IMAGE_EFFECT_PIXEL_HSA_GRAY:       \
      ENABLE_IPP_CLRIZE();                      \
      break;                                    \
                                                \
    case IDP_IMAGE_EFFECT_PIXEL_HSA_COLORIZE:   \
      ENABLE_IPP_CLRIZE();                      \
      break;                                    \
                                                \
    case IDP_IMAGE_EFFECT_PIXEL_HSA_HUE:        \
      ENABLE_IPP_HUE();                         \
      break;                                    \
                                                \
    case IDP_IMAGE_EFFECT_PIXEL_HSA_SAT:        \
      ENABLE_IPP_SAT();                         \
      break;                                    \
                                                \
    case IDP_IMAGE_EFFECT_PIXEL_HSA_HUE_SAT:    \
      ENABLE_IPP_HUE();                         \
      ENABLE_IPP_SAT();                         \
      break;                                    \
    }                                           \
  } while(0)

struct idp_imgproc_ipp_struct
{
    kal_bool                          hw_frame_sync;
    kal_bool                          bypass; /**< just bypass IPP */

    idp_image_effect_pixel_hsa_enum_t hsa; /**< hue, saturation, and colorize (YUV) */
    kal_bool                          cba; /**< contrast and brightness adjustment enable (YUV) */
    kal_bool                          inv; /**< color invert enable (RGB) */
    kal_bool                          clr; /**< color adjustment enable (RGB) */
    kal_bool                          gma; /**< gamma correction enable, deprecated in MT6276 */
    kal_bool                          rgb_detect_replace;  /**< color replace (RGB) */
    kal_bool                          y2r_rounding_en; /**< Enable Y2R rounding (RGB) */
    kal_bool                          r2y_rounding_en; /**< Enable R2Y rounding (RGB) */
  
    /* The following fields are only useful if the hsa field
     * enabling HUE.
     */
    kal_int8                          c11;
    kal_int8                          c12;
    kal_int8                          c21;
    kal_int8                          c22;
  
    /* The following fields are only useful if the hsa field
     * enabling SAT.
     */
    kal_uint8                         satadj;
  
    /* The following fields are only useful if the hsa field
     * enabling colorize.
     */
    kal_int8                          colorize_u;
    kal_int8                          colorize_v;
  
    /* The following fields are only useful if the 'gma'
     * field is KAL_TRUE.
     */
    kal_bool                          gamma;	// 1: gamma > 1, 0: gamma <= 1
    kal_uint8                         off0;
    kal_uint8                         off1;
    kal_uint8                         off2;
    kal_uint8                         off3;
    kal_uint8                         off4;
    kal_uint8                         off5;
    kal_uint8                         off6;
    kal_uint8                         off7;
    kal_uint8                         slp0;
    kal_uint8                         slp1;
    kal_uint8                         slp2;
    kal_uint8                         slp3;
    kal_uint8                         slp4;
    kal_uint8                         slp5;
    kal_uint8                         slp6;
    kal_uint8                         slp7;
  
    /* The following fields are only useful if the 'clr'
     * field is KAL_TRUE.
     */
    kal_uint8                         r1x;
    kal_uint8                         r1y;
    kal_uint8                         r2x;
    kal_uint8                         r2y;
    kal_uint8                         r0slp;
    kal_uint8                         r1slp;
    kal_uint8                         r2slp;
    kal_uint8                         g1x;
    kal_uint8                         g1y;
    kal_uint8                         g2x;
    kal_uint8                         g2y;
    kal_uint8                         g0slp;
    kal_uint8                         g1slp;
    kal_uint8                         g2slp;
    kal_uint8                         b1x;
    kal_uint8                         b1y;
    kal_uint8                         b2x;
    kal_uint8                         b2y;
    kal_uint8                         b0slp;
    kal_uint8                         b1slp;
    kal_uint8                         b2slp;
  
    /* The following fields are only useful if the 'clr'
     * field is KAL_TRUE.
     */
    kal_uint8                         bright;
    kal_uint8                         dark;
    kal_uint8                         contrast;

    /*
     *
     */
    kal_uint8                         detect_r;
    kal_uint8                         detect_g;
    kal_uint8                         detect_b;
    kal_uint8                         replace_r;
    kal_uint8                         replace_g;
    kal_uint8                         replace_b;
  
    kal_bool                          enable_rgb_dithering; /**< Deprecated in MT6276 */
};
typedef struct idp_imgproc_ipp_struct idp_imgproc_ipp_struct;

extern kal_bool
idp_imgproc_ipp_start_real(
    idp_imgproc_ipp_struct const * const ipp_struct);

extern kal_bool
idp_imgproc_ipp_stop_real(
    idp_imgproc_ipp_struct const * const ipp_struct);

extern kal_bool
idp_imgproc_ipp_config_real(
    idp_imgproc_ipp_struct * const p_ipp_struct, 
    kal_bool const config_to_hardware);
    
extern void
idp_imgproc_ipp_open_real(void);

IDP_HW_COMMON_API_DECLARATION(imgproc_ipp)

#endif //#if defined(DRV_IDP_MT6276_SERIES) || defined(DRV_IDP_MT6256_SERIES)
#endif // __idp_imgproc_ipp_mt6276_h__
