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

#ifndef __idp_imgproc_ipp_mt6238_h__
#define __idp_imgproc_ipp_mt6238_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include "drv_features_mdp.h"
#include "drv_comm.h"
#include <idp_define.h>

#if defined(DRV_IDP_6238_SERIES)

#include "idp_core.h"
#include "reg_base.h"
#include "idp_imgproc.h"
#include "idp_hw_common.h"
#include "idp_image_effect_pixel.h"

/* register definition of IMGPROC IPP config*/
#define IMGPROC_IPP_CFG       (IMGPROC_base + 0x0000)
#define IMGPROC_IPP_SDTCON    (IMGPROC_base + 0x000C)
#define IMGPROC_HUE11         (IMGPROC_base + 0x0100)
#define IMGPROC_HUE12         (IMGPROC_base + 0x0104)
#define IMGPROC_HUE21         (IMGPROC_base + 0x0108)
#define IMGPROC_HUE22         (IMGPROC_base + 0x010C)
#define IMGPROC_SATADJ        (IMGPROC_base + 0x0110)
#define IMGPROC_BRIADJ1       (IMGPROC_base + 0x0120)
#define IMGPROC_BRIADJ2       (IMGPROC_base + 0x0124)
#define IMGPROC_CONADJ        (IMGPROC_base + 0x0128)
#define IMGPROC_COLORIZE_U    (IMGPROC_base + 0x0130)
#define IMGPROC_COLORIZE_V    (IMGPROC_base + 0x0134)
#define IMGPROC_GAMMA_OFF0    (IMGPROC_base + 0x0170) 
#define IMGPROC_GAMMA_OFF1    (IMGPROC_base + 0x0174) 
#define IMGPROC_GAMMA_OFF2    (IMGPROC_base + 0x0178)
#define IMGPROC_GAMMA_OFF3    (IMGPROC_base + 0x017C)
#define IMGPROC_GAMMA_OFF4    (IMGPROC_base + 0x0180)
#define IMGPROC_GAMMA_OFF5    (IMGPROC_base + 0x0184)
#define IMGPROC_GAMMA_OFF6    (IMGPROC_base + 0x0188)
#define IMGPROC_GAMMA_OFF7    (IMGPROC_base + 0x018C)

#define IMGPROC_GAMMA_SLP0    (IMGPROC_base + 0x0190)
#define IMGPROC_GAMMA_SLP1    (IMGPROC_base + 0x0194)
#define IMGPROC_GAMMA_SLP2    (IMGPROC_base + 0x0198)
#define IMGPROC_GAMMA_SLP3    (IMGPROC_base + 0x019C)
#define IMGPROC_GAMMA_SLP4    (IMGPROC_base + 0x01A0)
#define IMGPROC_GAMMA_SLP5    (IMGPROC_base + 0x01A4)
#define IMGPROC_GAMMA_SLP6    (IMGPROC_base + 0x01A8)
#define IMGPROC_GAMMA_SLP7    (IMGPROC_base + 0x01AC)
 
#define IMGPROC_GAMMA_CON       (IMGPROC_base + 0x01B0)

#define IMGPROC_COLOR1R_OFFX    (IMGPROC_base + 0x0200)
#define IMGPROC_COLOR1R_OFFY    (IMGPROC_base + 0x0220)

#define IMGPROC_COLOR2R_OFFX    (IMGPROC_base + 0x0204)
#define IMGPROC_COLOR2R_OFFY    (IMGPROC_base + 0x0224)

#define IMGPROC_COLOR1G_OFFX    (IMGPROC_base + 0x0208)
#define IMGPROC_COLOR1G_OFFY    (IMGPROC_base + 0x0228)

#define IMGPROC_COLOR2G_OFFX    (IMGPROC_base + 0x020C)
#define IMGPROC_COLOR2G_OFFY    (IMGPROC_base + 0x022C)

#define IMGPROC_COLOR1B_OFFX    (IMGPROC_base + 0x0210)
#define IMGPROC_COLOR1B_OFFY    (IMGPROC_base + 0x0230)

#define IMGPROC_COLOR2B_OFFX    (IMGPROC_base + 0x0214)
#define IMGPROC_COLOR2B_OFFY    (IMGPROC_base + 0x0234)

#define IMGPROC_COLOR0R_SLP     (IMGPROC_base + 0x0240)
#define IMGPROC_COLOR1R_SLP     (IMGPROC_base + 0x0244)
#define IMGPROC_COLOR2R_SLP     (IMGPROC_base + 0x0248)

#define IMGPROC_COLOR0G_SLP     (IMGPROC_base + 0x0250)
#define IMGPROC_COLOR1G_SLP     (IMGPROC_base + 0x0254)
#define IMGPROC_COLOR2G_SLP     (IMGPROC_base + 0x0258)

#define IMGPROC_COLOR0B_SLP     (IMGPROC_base + 0x0260)
#define IMGPROC_COLOR1B_SLP     (IMGPROC_base + 0x0264)
#define IMGPROC_COLOR2B_SLP     (IMGPROC_base + 0x0268)

#define IMGPROC_IPP_RGB_DETECT  (IMGPROC_base + 0x0324)
#define IMGPROC_IPP_RGB_RPLACE  (IMGPROC_base + 0x0328)
 
#define REG_IMGPROC_IPP_CFG       *((volatile unsigned int *)(IMGPROC_base + 0x0000))
#define REG_IMGPROC_IPP_SDTCON    *((volatile unsigned int *)(IMGPROC_base + 0x000C))
#define REG_IMGPROC_HUE11         *((volatile unsigned int *)(IMGPROC_base + 0x0100))
#define REG_IMGPROC_HUE12         *((volatile unsigned int *)(IMGPROC_base + 0x0104))
#define REG_IMGPROC_HUE21         *((volatile unsigned int *)(IMGPROC_base + 0x0108))
#define REG_IMGPROC_HUE22         *((volatile unsigned int *)(IMGPROC_base + 0x010C))
#define REG_IMGPROC_SATADJ        *((volatile unsigned int *)(IMGPROC_base + 0x0110))
#define REG_IMGPROC_BRIADJ1       *((volatile unsigned int *)(IMGPROC_base + 0x0120))
#define REG_IMGPROC_BRIADJ2       *((volatile unsigned int *)(IMGPROC_base + 0x0124))
#define REG_IMGPROC_CONADJ        *((volatile unsigned int *)(IMGPROC_base + 0x0128))
#define REG_IMGPROC_COLORIZE_U    *((volatile unsigned int *)(IMGPROC_base + 0x0130))
#define REG_IMGPROC_COLORIZE_V    *((volatile unsigned int *)(IMGPROC_base + 0x0134))
#define REG_IMGPROC_GAMMA_OFF0    *((volatile unsigned int *)(IMGPROC_base + 0x0170))
#define REG_IMGPROC_GAMMA_OFF1    *((volatile unsigned int *)(IMGPROC_base + 0x0174))
#define REG_IMGPROC_GAMMA_OFF2    *((volatile unsigned int *)(IMGPROC_base + 0x0178))
#define REG_IMGPROC_GAMMA_OFF3    *((volatile unsigned int *)(IMGPROC_base + 0x017C))
#define REG_IMGPROC_GAMMA_OFF4    *((volatile unsigned int *)(IMGPROC_base + 0x0180))
#define REG_IMGPROC_GAMMA_OFF5    *((volatile unsigned int *)(IMGPROC_base + 0x0184))
#define REG_IMGPROC_GAMMA_OFF6    *((volatile unsigned int *)(IMGPROC_base + 0x0188))
#define REG_IMGPROC_GAMMA_OFF7    *((volatile unsigned int *)(IMGPROC_base + 0x018C)) 
#define REG_IMGPROC_GAMMA_SLP0    *((volatile unsigned int *)(IMGPROC_base + 0x0190))
#define REG_IMGPROC_GAMMA_SLP1    *((volatile unsigned int *)(IMGPROC_base + 0x0194))
#define REG_IMGPROC_GAMMA_SLP2    *((volatile unsigned int *)(IMGPROC_base + 0x0198))
#define REG_IMGPROC_GAMMA_SLP3    *((volatile unsigned int *)(IMGPROC_base + 0x019C))
#define REG_IMGPROC_GAMMA_SLP4    *((volatile unsigned int *)(IMGPROC_base + 0x01A0))
#define REG_IMGPROC_GAMMA_SLP5    *((volatile unsigned int *)(IMGPROC_base + 0x01A4))
#define REG_IMGPROC_GAMMA_SLP6    *((volatile unsigned int *)(IMGPROC_base + 0x01A8))
#define REG_IMGPROC_GAMMA_SLP7    *((volatile unsigned int *)(IMGPROC_base + 0x01AC))
 
#define REG_IMGPROC_GAMMA_CON        *((volatile unsigned int *)(IMGPROC_base + 0x01B0))
#define REG_IMGPROC_COLOR1R_OFFX     *((volatile unsigned int *)(IMGPROC_base + 0x0200))
#define REG_IMGPROC_COLOR2R_OFFX     *((volatile unsigned int *)(IMGPROC_base + 0x0204))

#define REG_IMGPROC_COLOR1G_OFFX     *((volatile unsigned int *)(IMGPROC_base + 0x0208))
#define REG_IMGPROC_COLOR2G_OFFX     *((volatile unsigned int *)(IMGPROC_base + 0x020C))

#define REG_IMGPROC_COLOR1B_OFFX     *((volatile unsigned int *)(IMGPROC_base + 0x0210))
#define REG_IMGPROC_COLOR2B_OFFX     *((volatile unsigned int *)(IMGPROC_base + 0x0214))

#define REG_IMGPROC_COLOR1R_OFFY     *((volatile unsigned int *)(IMGPROC_base + 0x0220))
#define REG_IMGPROC_COLOR2R_OFFY     *((volatile unsigned int *)(IMGPROC_base + 0x0224))

#define REG_IMGPROC_COLOR1G_OFFY     *((volatile unsigned int *)(IMGPROC_base + 0x0228))
#define REG_IMGPROC_COLOR2G_OFFY     *((volatile unsigned int *)(IMGPROC_base + 0x022C))

#define REG_IMGPROC_COLOR1B_OFFY     *((volatile unsigned int *)(IMGPROC_base + 0x0230))
#define REG_IMGPROC_COLOR2B_OFFY     *((volatile unsigned int *)(IMGPROC_base + 0x0234))

#define REG_IMGPROC_COLOR0R_SLP      *((volatile unsigned int *)(IMGPROC_base + 0x0240))
#define REG_IMGPROC_COLOR1R_SLP      *((volatile unsigned int *)(IMGPROC_base + 0x0244))
#define REG_IMGPROC_COLOR2R_SLP      *((volatile unsigned int *)(IMGPROC_base + 0x0248))

#define REG_IMGPROC_COLOR0G_SLP      *((volatile unsigned int *)(IMGPROC_base + 0x0250))
#define REG_IMGPROC_COLOR1G_SLP      *((volatile unsigned int *)(IMGPROC_base + 0x0254))
#define REG_IMGPROC_COLOR2G_SLP      *((volatile unsigned int *)(IMGPROC_base + 0x0258))

#define REG_IMGPROC_COLOR0B_SLP      *((volatile unsigned int *)(IMGPROC_base + 0x0260))
#define REG_IMGPROC_COLOR1B_SLP      *((volatile unsigned int *)(IMGPROC_base + 0x0264))
#define REG_IMGPROC_COLOR2B_SLP      *((volatile unsigned int *)(IMGPROC_base + 0x0268))

#define REG_IMGPROC_IPP_RGB_DETECT   *((volatile unsigned int *)(IMGPROC_base + 0x0324))
#define REG_IMGPROC_IPP_RGB_RPLACE   *((volatile unsigned int *)(IMGPROC_base + 0x0328))
 
/*bit define of IMGPROC_IPP_CFG*/
#define IMGPROC_IPP_NR_EN_BIT                0X00000001            
#define IMGPROC_IPP_CB_EN_BIT                0X00000010            
#define IMGPROC_IPP_HUE_EN_BIT               0X00000020            
#define IMGPROC_IPP_SAT_EN_BIT               0X00000100   
#define IMGPROC_IPP_CLRIZE_EN_BIT            0X00000200
#define IMGPROC_IPP_SDT_EN_BIT               0X00001000            
#define IMGPROC_IPP_Y2R0_EN_BIT              0X00010000            
#define IMGPROC_IPP_ROUND_EN_BIT             0X00020000            
#define IMGPROC_IPP_CLRADJ_EN_BIT            0X00100000            
#define IMGPROC_IPP_GAMMA_EN_BIT             0X01000000            
#define IMGPROC_IPP_INV_EN_BIT               0X10000000            
#define IMGPROC_IPP_SDT1_EN_BIT              0X20000000             
#define IMGPROC_IPP_RGB_DETECT_EN_BIT        0X40000000        

/*bit define of IMGPROC_IPP_SDTCON*/ 
#define IMGPROC_DITHERING_BD1_MASK           (0X0700)
#define IMGPROC_DITHERING_BD2_MASK           (0X0070)
#define IMGPROC_DITHERING_BD3_MASK           (0X0007)
#define IMGPROC_DITHERING_SEED1_MASK         (0XF00000)
#define IMGPROC_DITHERING_SEED2_MASK         (0XF0000)
#define IMGPROC_DITHERING_SEED3_MASK         (0XF000)
   
#define IPP_FILTER_NONE							0x0
#define IPP_FILTER_LINEAR_LP					0x5
#define IPP_FILTER_LINEAR_HP					0x6
#define IPP_FILTER_LINEAR_HP_SCALE_DOWN	0x7
#define IPP_FILTER_BLUR							0x9
#define IPP_FILTER_MORE_BLUR					0xA
#define IPP_FILTER_UNSHARP						0xB
#define IPP_FILTER_MAXIMUM_RANKING			0xC
#define IPP_FILTER_MEDIAN_RANKING			0xD
#define IPP_FILTER_MINIMUM_RANKING			0xE

#define IPP_COLOR_RGB565				0
#define IPP_COLOR_RGB888				1

/*IPP source and outout selection*/
#define IMGPROC_IPP_IO_CRZ_TO_IPP1        0X00000001
#define IMGPROC_IPP_IO_PRZ_TO_IPP1        0X00000002
#define IMGPROC_IPP_IO_MP4DEBLK_TO_IPP1   0X00000004
#define IMGPROC_IPP_IO_IRT0_TO_IPP1       0X00000008
#if defined(MT6268)
#define IMGPROC_IPP_IO_OVL_TO_IPP1        0X00000010
#define IMGPROC_IPP_IO_OVL_TO_Y2R0        0X00000020
#define IMGPROC_IPP_IO_IPP1_TO_OVL        0X00000040
#define IMGPROC_IPP_IO_IPP2_TO_IBW2       0X00000080
#else // chip option MT6238 MT6268A
#define IMGPROC_IPP_IO_OVL_TO_Y2R0        0X00000010
#define IMGPROC_IPP_IO_IPP1_TO_OVL        0X00000020
#define IMGPROC_IPP_IO_IPP2_TO_IBW2       0X00000040
#endif // chip option
 
#define SET_IMGPROC_IPP_SRC(src)                                \
  do {                                                          \
    REG_IMGPROC_R2Y_SRC &= ~IMGPROC_R2Y_SRC_IPP_IO_MASK ;       \
    REG_IMGPROC_R2Y_SRC |= ((src)&IMGPROC_R2Y_SRC_IPP_IO_MASK); \
  } while(0)

#define ENABLE_IPP_NR()          REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_NR_EN_BIT;
#define DISABLE_IPP_NR()         REG_IMGPROC_IPP_CFG &= ~IMGPROC_IPP_NR_EN_BIT; 
#define ENABLE_IPP_CB()          REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_CB_EN_BIT;
#define DISABLE_IPP_CB()         REG_IMGPROC_IPP_CFG &= ~IMGPROC_IPP_CB_EN_BIT; 
#define ENABLE_IPP_HUE()         REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_HUE_EN_BIT;
#define DISABLE_IPP_HUE()        REG_IMGPROC_IPP_CFG &= ~IMGPROC_IPP_HUE_EN_BIT;
#define ENABLE_IPP_SAT()         REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_SAT_EN_BIT;
#define DISABLE_IPP_SAT()        REG_IMGPROC_IPP_CFG &= ~IMGPROC_IPP_SAT_EN_BIT;
#define ENABLE_IPP_CLRIZE()      REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_CLRIZE_EN_BIT;
#define DISABLE_IPP_CLRIZE()     REG_IMGPROC_IPP_CFG &= IMGPROC_IPP_CLRIZE_EN_BIT
  
#define ENABLE_IPP_SDT0()        REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_SDT_EN_BIT;
#define DISABLE_IPP_SDT0()       REG_IMGPROC_IPP_CFG &= ~IMGPROC_IPP_SDT_EN_BIT;
 
#define ENABLE_IPP_Y2R0()        REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_Y2R0_EN_BIT;
#define DISABLE_IPP_Y2R0()       REG_IMGPROC_IPP_CFG &= ~IMGPROC_IPP_Y2R0_EN_BIT;
#define ENABLE_IPP_ROUND()       REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_ROUND_EN_BIT
#define DISABLE_IPP_ROUND()      REG_IMGPROC_IPP_CFG &= ~IMGPROC_IPP_ROUND_EN_BIT; 
#define ENABLE_IPP_CLRADJ()      REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_CLRADJ_EN_BIT;
#define DISABLE_IPP_CLRADJ()     REG_IMGPROC_IPP_CFG &= ~IMGPROC_IPP_CLRADJ_EN_BIT;   
#define ENABLE_IPP_GAMMA()       REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_GAMMA_EN_BIT;
#define DISABLE_IPP_GAMMA()      REG_IMGPROC_IPP_CFG &= ~IMGPROC_IPP_GAMMA_EN_BIT;
#define ENABLE_IPP_INV()         REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_INV_EN_BIT;
#define DISABLE_IPP_INV()        REG_IMGPROC_IPP_CFG &= ~IMGPROC_IPP_INV_EN_BIT;
#define ENABLE_IPP_SDT1()        REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_SDT1_EN_BIT;
#define DISABLE_IPP_SDT1()       REG_IMGPROC_IPP_CFG &= ~IMGPROC_IPP_SDT1_EN_BIT;
#define ENABLE_IPP_RGB_DETECT()  REG_IMGPROC_IPP_CFG |= IMGPROC_IPP_RGB_DETECT_EN_BIT;
#define DISABLE_IPP_RGB_DETECT() REG_IMGPROC_IPP_CFG &= ~IMGPROC_IPP_RGB_DETECT_EN_BIT;

#define SET_IMGPROC_HUE11(hue)        REG_IMGPROC_HUE11 = hue;
#define SET_IMGPROC_HUE12(hue)        REG_IMGPROC_HUE12 = hue;
#define SET_IMGPROC_HUE21(hue)        REG_IMGPROC_HUE21 = hue;
#define SET_IMGPROC_HUE22(hue)        REG_IMGPROC_HUE22 = hue;
 
#define SET_IMGPROC_SATADJ(sat)       REG_IMGPROC_SATADJ = sat;
#define SET_IMGPROC_BRIADJ1(bri)      REG_IMGPROC_BRIADJ1 = bri;
#define SET_IMGPROC_BRIADJ2(dark)     REG_IMGPROC_BRIADJ2 = dark;
#define SET_IMGPROC_CONADJ(con)       REG_IMGPROC_CONADJ = con;
#define SET_IMGPROC_COLORIZE_U(u)     REG_IMGPROC_COLORIZE_U = u;
#define SET_IMGPROC_COLORIZE_V(v)     REG_IMGPROC_COLORIZE_V = v;
            
#define ENABLE_IMGPROC_GAMMA()      REG_IMGPROC_GAMMA_CON = 1;
#define DISABLE_IMGPROC_GAMMA()     REG_IMGPROC_GAMMA_CON = 0; 

#define ENABLE_IMGPROC_HW_IPP()      REG_IMGPROC_EN |= IMGPROC_HW_IPP_ENABLE_BIT;
#define DISABLE_IMGPROC_HW_IPP()     REG_IMGPROC_EN &= ~IMGPROC_HW_IPP_ENABLE_BIT; 
   
#define SET_IPP_RGB_DETECT(r,g,b)    REG_IMGPROC_IPP_RGB_DETECT =(r<<16)|(g<<8)|(b);
#define SET_IPP_RGB_REPLACE(r,g,b)   REG_IMGPROC_IPP_RGB_RPLACE =(r<<16)|(g<<8)|(b);

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
  idp_module_enum_t image_src;
  idp_module_enum_t image_dest;
  
  idp_image_effect_pixel_hsa_enum_t hsa; // hue and saturation adjustment
  kal_bool cba; // contrast and brightness adjustment enable
  kal_bool inv; // color invert enable
  kal_bool clr; // color adjustment enable
  kal_bool gma; // gamma correction enable
  
  /* The following fields are only useful if the hsa field
   * enabling HUE.
   */
  kal_int8 c11;
  kal_int8 c12;
  kal_int8 c21;
  kal_int8 c22;
  
  /* The following fields are only useful if the hsa field
   * enabling SAT.
   */
  kal_uint8 satadj;
  
  /* The following fields are only useful if the hsa field
   * enabling colorize.
   */
  kal_int8 colorize_u;
  kal_int8 colorize_v;
  
  /* The following fields are only useful if the 'gma'
   * field is KAL_TRUE.
   */
  kal_bool gamma;	// 1: gamma > 1, 0: gamma <= 1
  kal_uint8 off0;
  kal_uint8 off1;
  kal_uint8 off2;
  kal_uint8 off3;
  kal_uint8 off4;
  kal_uint8 off5;
  kal_uint8 off6;
  kal_uint8 off7;
  kal_uint8 slp0;
  kal_uint8 slp1;
  kal_uint8 slp2;
  kal_uint8 slp3;
  kal_uint8 slp4;
  kal_uint8 slp5;
  kal_uint8 slp6;
  kal_uint8 slp7;
  
  /* The following fields are only useful if the 'clr'
   * field is KAL_TRUE.
   */
  kal_uint8 r1x;
  kal_uint8 r1y;
  kal_uint8 r2x;
  kal_uint8 r2y;
  kal_uint8 r0slp;
  kal_uint8 r1slp;
  kal_uint8 r2slp;
  kal_uint8 g1x;
  kal_uint8 g1y;
  kal_uint8 g2x;
  kal_uint8 g2y;
  kal_uint8 g0slp;
  kal_uint8 g1slp;
  kal_uint8 g2slp;
  kal_uint8 b1x;
  kal_uint8 b1y;
  kal_uint8 b2x;
  kal_uint8 b2y;
  kal_uint8 b0slp;
  kal_uint8 b1slp;
  kal_uint8 b2slp;
  
  /* The following fields are only useful if the 'clr'
   * field is KAL_TRUE.
   */
  kal_uint8 bright;
  kal_uint8 dark;
  kal_uint8 contrast;
  
  kal_bool enable_rgb_dithering;
#if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
  kal_bool hw_frame_sync; /**< KAL_TRUE: enable, KAL_FALSE: disable. */
#endif // #if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
};
typedef struct idp_imgproc_ipp_struct idp_imgproc_ipp_struct;

IDP_HW_COMMON_API_DECLARATION(imgproc_ipp)

extern kal_bool idp_imgproc_ipp_stop_real(
  idp_imgproc_ipp_struct const * const ipp_struct);

extern void idp_imgproc_ipp_close_real(void);

#endif // defined(DRV_IDP_6238_SERIES)

#endif // __idp_imgproc_ipp_mt6238_h__
