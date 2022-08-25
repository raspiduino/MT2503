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
 * 06 29 2011 peter.wang
 * removed!
 * .
 *
 * 05 23 2011 peter.wang
 * removed!
 * .
 *
 * 05 09 2011 peter.wang
 * removed!
 * .
 *
 * 04 22 2011 peter.wang
 * removed!
 * .
 *
 * 12 30 2010 cm.huang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 * 11 17 2010 cm.huang
 * NULL
 * .
 *
 * 11 09 2010 cm.huang
 * NULL
 * .
 *
 * 11 01 2010 cm.huang
 * NULL
 * .
 *
 * 10 20 2010 cm.huang
 * NULL
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
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_resz_crz_mt6253_h__
#define __idp_resz_crz_mt6253_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>

#if defined(DRV_IDP_6253_SERIES)

#include "idp_resz.h"
#include "idp_hw_common.h"
#include "idp_core.h"
#include <mm_comm_def.h>
#include "drvpdn.h"
/* ===============================================================
 *                       CRZ definition
 * =============================================================== */
/**
 * \defgroup crz Capture resizer
 * \ingroup resizer
 * @{
 */
#define RESZ_base               (PRZ_base)

#define RESZ_CONFIG             (RESZ_base + 0x00)
#define RESZ_CTRL               (RESZ_base + 0x04)
#define RESZ_STA                (RESZ_base + 0x08)
#define RESZ_INT_STATUS         (RESZ_base + 0x0C)
#define RESZ_SRCSZ1             (RESZ_base + 0x10)
#define RESZ_TARSZ1             (RESZ_base + 0x14)
#define RESZ_HRATIO1            (RESZ_base + 0x18)
#define RESZ_VRATIO1            (RESZ_base + 0x1C)
#define RESZ_HRES1              (RESZ_base + 0x20)
#define RESZ_VRES1              (RESZ_base + 0x24)
#define RESZ_FRCG               (RESZ_base + 0x40)
#define RESZ_PRWMBASE           (RESZ_base + 0x5C)
#define RESZ_SRCSZ2             (RESZ_base + 0x60)
#define RESZ_TARSZ2             (RESZ_base + 0x64)
#define RESZ_HRATIO2            (RESZ_base + 0x68)
#define RESZ_VRATIO2            (RESZ_base + 0x6C)
#define RESZ_HRES2              (RESZ_base + 0x70)
#define RESZ_VRES2              (RESZ_base + 0x74)
#define RESZ_OUTMODE            (RESZ_base + 0x80)
#define RESZ_TMBASE_RGB1        (RESZ_base + 0x84)
#define RESZ_TMBASE_RGB2        (RESZ_base + 0x88)
#define RESZ_DBGCFG             (RESZ_base + 0x90)
#define RESZ_TAR_YBASE          (RESZ_base + 0xD0)
#define RESZ_TAR_UBASE          (RESZ_base + 0xD4)
#define RESZ_TAR_VBASE          (RESZ_base + 0xD8)
#define RESZ_SRC_YBASE          (RESZ_base + 0xDC)
#define RESZ_SRC_UBASE          (RESZ_base + 0xE0)
#define RESZ_SRC_VBASE          (RESZ_base + 0xE4)
#define RESZ_GUC1_REG           (RESZ_base + 0xE8)
#if defined(MT6253)
// below HW registers are unavailable in MT6253T
#define RESZ_GUC2_REG           (RESZ_base + 0xEC)
#define RESZ_GMCCON_REG         (RESZ_base + 0xF0)
#define RESZ_CLIPLR_REG         (RESZ_base + 0xF4)
#define RESZ_CLIPTB_REG         (RESZ_base + 0xF8)
#define RESZ_PITCH_REG          (RESZ_base + 0xFC)
#endif  // #if defined(MT6253)


//////
#define REG_RESZ_CONFIG             (*((volatile unsigned int *)(RESZ_CONFIG)))
#define REG_RESZ_CTRL               (*((volatile unsigned int *)(RESZ_CTRL)))
#define REG_RESZ_STA                (*((volatile unsigned int *)(RESZ_STA)))
#define REG_RESZ_INT_STATUS         (*((volatile unsigned int *)(RESZ_INT_STATUS)))
#define REG_RESZ_SRCSZ1             (*((volatile unsigned int *)(RESZ_SRCSZ1)))
#define REG_RESZ_TARSZ1             (*((volatile unsigned int *)(RESZ_TARSZ1)))
#define REG_RESZ_HRATIO1            (*((volatile unsigned int *)(RESZ_HRATIO1)))
#define REG_RESZ_VRATIO1            (*((volatile unsigned int *)(RESZ_VRATIO1)))
#define REG_RESZ_HRES1              (*((volatile unsigned int *)(RESZ_HRES1)))
#define REG_RESZ_VRES1              (*((volatile unsigned int *)(RESZ_VRES1)))
#define REG_RESZ_FRCG               (*((volatile unsigned int *)(RESZ_FRCG)))
#define REG_RESZ_PRWMBASE           (*((volatile unsigned int *)(RESZ_PRWMBASE)))
#define REG_RESZ_SRCSZ2             (*((volatile unsigned int *)(RESZ_SRCSZ2)))
#define REG_RESZ_TARSZ2             (*((volatile unsigned int *)(RESZ_TARSZ2)))
#define REG_RESZ_HRATIO2            (*((volatile unsigned int *)(RESZ_HRATIO2)))
#define REG_RESZ_VRATIO2            (*((volatile unsigned int *)(RESZ_VRATIO2)))
#define REG_RESZ_HRES2              (*((volatile unsigned int *)(RESZ_HRES2)))
#define REG_RESZ_VRES2              (*((volatile unsigned int *)(RESZ_VRES2)))
#define REG_RESZ_OUTMODE            (*((volatile unsigned int *)(RESZ_OUTMODE)))
#define REG_RESZ_TMBASE_RGB1        (*((volatile unsigned int *)(RESZ_TMBASE_RGB1)))
#define REG_RESZ_TMBASE_RGB2        (*((volatile unsigned int *)(RESZ_TMBASE_RGB2)))
#define REG_RESZ_DBGCFG             (*((volatile unsigned int *)(RESZ_DBGCFG)))
#define REG_RESZ_TAR_YBASE          (*((volatile unsigned int *)(RESZ_TAR_YBASE)))
#define REG_RESZ_TAR_UBASE          (*((volatile unsigned int *)(RESZ_TAR_UBASE)))
#define REG_RESZ_TAR_VBASE          (*((volatile unsigned int *)(RESZ_TAR_VBASE)))
#define REG_RESZ_SRC_YBASE          (*((volatile unsigned int *)(RESZ_SRC_YBASE)))
#define REG_RESZ_SRC_UBASE          (*((volatile unsigned int *)(RESZ_SRC_UBASE)))
#define REG_RESZ_SRC_VBASE          (*((volatile unsigned int *)(RESZ_SRC_VBASE)))
#define REG_RESZ_GUC1               (*((volatile unsigned int *)(RESZ_GUC1_REG)))
#if defined(MT6253)
// below HW registers are unavailable in MT6253T
#define REG_RESZ_GUC2               (*((volatile unsigned int *)(RESZ_GUC2_REG)))
#define REG_RESZ_GMCCON             (*((volatile unsigned int *)(RESZ_GMCCON_REG)))
#define REG_RESZ_CLIPLR             (*((volatile unsigned int *)(RESZ_CLIPLR_REG)))
#define REG_RESZ_CLIPTB             (*((volatile unsigned int *)(RESZ_CLIPTB_REG)))
#define REG_RESZ_PITCH              (*((volatile unsigned int *)(RESZ_PITCH_REG)))
#endif  // #if defined(MT6253)


/////bit mapping of registers
/* bit mapping of RESZ configure register */
#define RESZ_CFG_PASS1_INPUT_BIT          (0x00000001)
#define RESZ_CFG_PASS2_INPUT_BIT          (0x00000002)
#define RESZ_CFG_PCON_BIT                 (0x00000010)
#define RESZ_CFG_PRUN2_BIT                (0x00000020)
#define RESZ_CFG_RESET_MASK               (0x000001C0)
#define RESZ_CFG_NORGBDB_BIT              (0x00000200)

///bit mapping of control regsiter
#define RESZ_CON_ENABLE_BIT               (0x00000001)
#define RESZ_CON_RST_BIT                  (0x00010000)

///bit mapping of interrupt regsiter
#define RESZ_INT_LCD_BIT                  (0x00000001) /**< Interrupt bit for LCD direct couple complete. */
#define RESZ_INT_MEMO1_BIT                (0x00000002) /**< Interrupt bit for 1st pass memory output done. */
#define RESZ_INT_FSTART_BIT               (0x00000004) /**< Interrupt bit for frame start. */
#define RESZ_INT_PXDINT_BIT               (0x00000008) /**< Interrupt bit for pixel drop occurance. */
#define RESZ_INT_MEMO2_BIT                (0x00000010) /**< Interrupt bit for 2nd pass memory output done. */

///bit mapping of fine resizing configuration
#define RESZ_FRCFG_VRSS_BIT               (0x00000001)
#define RESZ_FRCFG_AVG0_BIT               (0x00000002)
#define RESZ_FRCFG_AVG1_BIT               (0x00000004)
#define RESZ_FRCFG_PCSF1_MASK             (0x00000030)
#define RESZ_FRCFG_PCSF2_MASK             (0x000000C0)
#define RESZ_FRCFG_LCDINT_BIT             (0x00000100)
#define RESZ_FRCFG_MEMO1INT_BIT           (0x00000200)
#define RESZ_FRCFG_FSTARTINT_BIT          (0x00000400)
#define RESZ_FRCFG_PXDINT_BIT             (0x00000800)
#define RESZ_FRCFG_MEMO2INT_BIT           (0x00001000)
#define RESZ_FRCFG_FSTART21_BIT           (0x00002000)
#define RESZ_FRCFG_WMSZ_MASK              (0x03FF0000)

///bit mapping of outpu mode configuration
#define RESZ_OUTMODE1_MASK                (0x00000003)
#define RESZ_OUTMODE2_MASK                (0x0000000C)
#define RESZ_OUTMODE2_MASK                (0x0000000C)

#define RESZ_OUTPUT_RGB565_BIT            (0x00000000)
#define RESZ_OUTPUT_YUV420_BIT            (0x00000001)
#define RESZ_OUTPUT_DCLCD_BIT             (0x00000002)
#define RESZ_OUTPUT_YUV420_DCLCD_BIT      (0x00000003)
#define RESZ_OUTPUT_FMT_MASK              (0x00000003)
#define RESZ_OUTPUT_HW_LCD_BIT            (0x00000010)

#define RESZ_H_RATIO_SHIFT_BITS           (20)
#define RESZ_V_RATIO_SHIFT_BITS           (20)

#define RESZ_CTRL_RESET_MASK              (0x00010000)
#define RESZ_CTRL_ENABLE_MASK             (0x00000001)

/* macros of RESZ config register */
#define RESZ_SET_PASS1_CAM_INPUT() \
    do { \
        REG_RESZ_CONFIG &= ~RESZ_CFG_PASS1_INPUT_BIT; \
    } while(0)

#define RESZ_SET_PASS1_YUV420_INPUT() \
    do { \
        REG_RESZ_CONFIG |= RESZ_CFG_PASS1_INPUT_BIT; \
    } while(0)

#define RESZ_SET_PASS2_CAM_INPUT() \
    do { \
        REG_RESZ_CONFIG &= ~RESZ_CFG_PASS2_INPUT_BIT; \
    } while(0)

#define RESZ_SET_PASS2_YUV420_INPUT() \
    do { \
        REG_RESZ_CONFIG |= RESZ_CFG_PASS2_INPUT_BIT; \
    } while(0)

#define RESZ_ENABLE_CONTINOUS() \
    do { \
        REG_RESZ_CONFIG |= RESZ_CFG_PCON_BIT; \
    } while(0)

#define RESZ_DISABLE_CONTINOUS() \
    do { \
        REG_RESZ_CONFIG &= ~RESZ_CFG_PCON_BIT; \
    } while(0)

#define RESZ_ENABLE_2PASS() \
    do { \
        REG_RESZ_CONFIG |= RESZ_CFG_PRUN2_BIT; \
    } while(0)

#define RESZ_DISABLE_2PASS() \
    do { \
        REG_RESZ_CONFIG &= ~RESZ_CFG_PRUN2_BIT; \
    } while(0)

#define RESZ_SET_RESET_MODE(mode) \
    do { \
        REG_RESZ_CONFIG &= ~RESZ_CFG_RESET_MASK; \
        REG_RESZ_CONFIG |= (mode<<6); \
    } while(0)

#define RESZ_ENABLE_RGB_DOUBLE_BUF() \
    do { \
        REG_RESZ_CONFIG &= ~RESZ_CFG_NORGBDB_BIT; \
    } while(0)

#define RESZ_DISABLE_RGB_DOUBLE_BUF() \
    do { \
        REG_RESZ_CONFIG |= RESZ_CFG_NORGBDB_BIT; \
    } while(0)

#define RESZ_ENABLE_VRSS() \
    do { \
        REG_RESZ_FRCG |= RESZ_FRCFG_VRSS_BIT; \
    } while(0)

#define RESZ_DISABLE_VRSS() \
    do { \
        REG_RESZ_FRCG &= ~RESZ_FRCFG_VRSS_BIT; \
    } while(0)

#define RESZ_ENABLE_AVG0() \
    do { \
        REG_RESZ_FRCG |= RESZ_FRCFG_AVG0_BIT; \
    } while(0)

#define RESZ_DISABLE_AVG0() \
    do { \
        REG_RESZ_FRCG &= ~RESZ_FRCFG_AVG0_BIT; \
    } while(0)

#define RESZ_ENABLE_AVG1() \
    do { \
        REG_RESZ_FRCG |= RESZ_FRCFG_AVG1_BIT; \
    } while(0)

#define RESZ_DISABLE_AVG1() \
    do { \
        REG_RESZ_FRCG &= ~RESZ_FRCFG_AVG1_BIT; \
    } while(0)

/**
 * \def RESZ_SET_PASS1_PCSF
 * This macro sets the factor of pixel coarse shrinking for resier 1st pass.
 * @param [in] pcsf1 Of type RESZ_COARSE_ENUM.
 */
#define RESZ_SET_PASS1_PCSF(pcsf1) \
    do { REG_RESZ_FRCG = ((REG_RESZ_FRCG & 0xffffffcf) | (((pcsf1) & 0x3)<<4)); } while(0)

/**
 * \def RESZ_SET_PASS2_PCSF
 * This macro sets the factor of pixel coarse shrinking for resier 2nd pass.
 * @param [in] pcsf2 Of type RESZ_COARSE_ENUM.
 */
#define RESZ_SET_PASS2_PCSF(pcsf2) \
    do { REG_RESZ_FRCG = ((REG_RESZ_FRCG & 0xffffff3f) | (((pcsf2) & 0x3)<<6)); } while(0)

#define RESZ_ENABLE_LCDINT() \
        do { \
        REG_RESZ_FRCG |= RESZ_FRCFG_LCDINT_BIT; \
    } while(0)

#define RESZ_DISABLE_LCDINT() \
    do { \
        REG_RESZ_FRCG &= ~RESZ_FRCFG_LCDINT_BIT; \
    } while(0)

#define RESZ_ENABLE_MEMO1INT() \
    do { \
        REG_RESZ_FRCG |= RESZ_FRCFG_MEMO1INT_BIT; \
    } while(0)

#define RESZ_DISABLE_MEMO1INT() \
    do { \
        REG_RESZ_FRCG &= ~RESZ_FRCFG_MEMO1INT_BIT; \
    } while(0)

#define RESZ_ENABLE_FSTARTINT() \
    do { \
        REG_RESZ_FRCG |= RESZ_FRCFG_FSTARTINT_BIT; \
    } while(0)

#define RESZ_DISABLE_FSTARTINT() \
    do { \
        REG_RESZ_FRCG &= ~RESZ_FRCFG_FSTARTINT_BIT; \
    } while(0)

#define RESZ_ENABLE_PXDINT() \
    do { \
        REG_RESZ_FRCG |= RESZ_FRCFG_PXDINT_BIT; \
    } while(0)

#define RESZ_DISABLE_PXDINT() \
    do { \
        REG_RESZ_FRCG &= ~RESZ_FRCFG_PXDINT_BIT; \
    } while(0)

#define RESZ_ENABLE_MEMO2INT() \
    do { \
        REG_RESZ_FRCG |= RESZ_FRCFG_MEMO2INT_BIT; \
    } while(0)

#define RESZ_DISABLE_MEMO2INT() \
    do { \
        REG_RESZ_FRCG &= ~RESZ_FRCFG_MEMO2INT_BIT; \
    } while(0)

#define RESZ_ENABLE_FSTART21INT() \
    do { \
        REG_RESZ_FRCG |= RESZ_FRCFG_FSTART21_BIT; \
    } while(0)

#define RESZ_DISABLE_FSTART21INT() \
    do { \
        REG_RESZ_FRCG &= ~RESZ_FRCFG_FSTART21_BIT; \
    } while(0)

#define RESZ_SET_WMSZ(line) \
    do { \
        REG_RESZ_FRCG &= ~RESZ_FRCFG_WMSZ_MASK; \
        REG_RESZ_FRCG |= (line<<16); \
    } while(0)

#define RESZ_SET_OUTPUT1_FMT(fmt) \
    do { \
        REG_RESZ_OUTMODE &= ~RESZ_OUTPUT_FMT_MASK; \
        REG_RESZ_OUTMODE |= fmt; \
    } while(0)

#define RESZ_SET_OUTPUT2_FMT(fmt) \
    do { \
        REG_RESZ_OUTMODE &= ~(RESZ_OUTPUT_FMT_MASK<<2); \
        REG_RESZ_OUTMODE |= (fmt<<2); \
    } while(0)

#define RESZ_ENABLE_HW_LCD() \
    do { \
        REG_RESZ_OUTMODE |= RESZ_OUTPUT_HW_LCD_BIT; \
    } while(0)

#define RESZ_DISABLE_HW_LCD() \
    do { \
        REG_RESZ_OUTMODE &= ~RESZ_OUTPUT_HW_LCD_BIT; \
    } while(0)

///////
/* marcos of RESZ control register */

#define RESET_CRZ() \
    do { \
        REG_RESZ_CTRL = RESZ_CTRL_RESET_MASK; \
        REG_RESZ_CTRL = 0; \
    } while(0)

#define ENABLE_CRZ() \
    do { \
        REG_RESZ_CTRL = RESZ_CTRL_ENABLE_MASK; \
    } while(0)


/* macros for resizer clipping and pitching function */
#if defined(MT6253)
// below HW registers are unavailable in MT6253T
#define RESZ_ENABLE_CLIP() \
    do { REG_RESZ_CLIPLR |= 0x80000000; } while(0)

#define RESZ_DISABLE_CLIP() \
    do { REG_RESZ_CLIPLR &= ~0x80000000; } while(0)

// Note this!
#define RESZ_SET_CLIP_LEFT_RIGHT(left, right) \
    do { REG_RESZ_CLIPLR = ((REG_RESZ_CLIPLR&0x80000000) | \
                            ((((left)&0x7ff)<<16) | ((right)&0x7ff))); } while(0)

#define RESZ_SET_CLIP_TOP_BOTTOM(top, bottom) \
    do { REG_RESZ_CLIPLR = ((REG_RESZ_CLIPLR&0x80000000) | \
                            ((((top)&0x7ff)<<16) | ((bottom)&0x7ff))); } while(0)

#define RESZ_ENABLE_PITCH() \
    do { REG_RESZ_PITCH |= 0x80000000; } while(0)

#define RESZ_DISABLE_PITCH() \
    do { REG_RESZ_PITCH &= ~0x80000000; } while(0)

#define RESZ_SET_PITCH_WIDTH(pitch_width) \
    do { REG_RESZ_PITCH = ((REG_RESZ_PITCH&0x80000000) | \
                           ((pitch_width)&0x7ff)); } while(0)
#endif  // #if defined(MT6253)

/* Macros of RESZ source image size register */
#define RESZ_SET_SRC1_SIZE(width, height) \
    do { REG_RESZ_SRCSZ1 = ((width) | ((height) << 16)); } while(0)

/* Macros of RESZ target image size register */
#define RESZ_SET_TAR1_SIZE(width, height) \
    do { REG_RESZ_TARSZ1 = ((width) | ((height) << 16)); } while(0)

#define RESZ_SET_SRC2_SIZE(width, height) \
    do { REG_RESZ_SRCSZ2 = ((width) | ((height) << 16)); } while(0)

/* Macros of RESZ target image size register */
#define RESZ_SET_TAR2_SIZE(width, height) \
    do { REG_RESZ_TARSZ2 = ((width) | ((height) << 16)); } while(0)

#if defined(MDP_FW_TRIGGER_LCD)
#define RESZ_DBGCFG_NODB            (0x00000800)
#define ENABLE_RESZ_REG_DOUBLE_BUF() \
    do { \
        REG_RESZ_DBGCFG &= ~RESZ_DBGCFG_NODB; \
    } while(0)

#define DISABLE_RESZ_REG_DOUBLE_BUF() \
    do { \
        REG_RESZ_DBGCFG |=RESZ_DBGCFG_NODB; \
    } while(0)
#endif // #if defined(MDP_FW_TRIGGER_LCD)

///power control
// New PDN API for projects later than MT6253 and MT6236...
//#define RESZ_POWERON() DRVPDN_Disable(DRVPDN_CON3, DRVPDN_CON3_RESZ, PDN_RESZ);
#define RESZ_POWERON() DRVPDN_Disable(PDN_RESZ);
//#define RESZ_POWEROFF() DRVPDN_Enable(DRVPDN_CON3, DRVPDN_CON3_RESZ, PDN_RESZ);
#define RESZ_POWEROFF() DRVPDN_Enable(PDN_RESZ);


/**
 *  \def  CRZ_CHECK_BIT
 *  If this is defined, IDP_RESZ_CRZ_MASK will be checked, if set, the params
 *  are then really set to HW registers...
 */
//#define CRZ_CHECK_BIT


/* SW interface*/
typedef enum
{
    RESZ_COARSE_NONE = 0x0,
    RESZ_COARSE_1_2 = 0x1,
    RESZ_COARSE_1_4 = 0x2,
    RESZ_COARSE_1_8 = 0x3
} RESZ_COARSE_ENUM;

enum
{
    IDP_RESZ_CRZ_MASK__IMAGE_SRC1,
    IDP_RESZ_CRZ_MASK__IMAGE_SRC2,

    IDP_RESZ_CRZ_MASK__OUTPUT1_FORMAT,
    IDP_RESZ_CRZ_MASK__OUTPUT2_FORMAT,

    IDP_RESZ_CRZ_MASK__RGB_TAR_BASE1,
    IDP_RESZ_CRZ_MASK__RGB_TAR_BASE2,

    IDP_RESZ_CRZ_MASK__Y_TAR_BASE,
    IDP_RESZ_CRZ_MASK__U_TAR_BASE,
    IDP_RESZ_CRZ_MASK__V_TAR_BASE,

    IDP_RESZ_CRZ_MASK__Y_TAR_BASE1,
    IDP_RESZ_CRZ_MASK__U_TAR_BASE1,
    IDP_RESZ_CRZ_MASK__V_TAR_BASE1,

    IDP_RESZ_CRZ_MASK__WMBASE,
    IDP_RESZ_CRZ_MASK__WMSIZE,

    IDP_RESZ_CRZ_MASK__Y_SRC_BASE,
    IDP_RESZ_CRZ_MASK__U_SRC_BASE,
    IDP_RESZ_CRZ_MASK__V_SRC_BASE,

    IDP_RESZ_CRZ_MASK__SRC1_WIDTH,
    IDP_RESZ_CRZ_MASK__SRC1_HEIGHT,
    IDP_RESZ_CRZ_MASK__TAR1_WIDTH,
    IDP_RESZ_CRZ_MASK__TAR1_HEIGHT,

    IDP_RESZ_CRZ_MASK__SRC2_WIDTH,
    IDP_RESZ_CRZ_MASK__SRC2_HEIGHT,
    IDP_RESZ_CRZ_MASK__TAR2_WIDTH,
    IDP_RESZ_CRZ_MASK__TAR2_HEIGHT,

    IDP_RESZ_CRZ_MASK__PASS2_EN,
    IDP_RESZ_CRZ_MASK__CONTINOUS_EN,
    IDP_RESZ_CRZ_MASK__INT_EN,
    IDP_RESZ_CRZ_MASK__TRIGGER_LCD_EN,

    IDP_RESZ_CRZ_MASK__CLIP_EN,
    IDP_RESZ_CRZ_MASK__CLIP_TOP,
    IDP_RESZ_CRZ_MASK__CLIP_BOTTOM,
    IDP_RESZ_CRZ_MASK__CLIP_LEFT,
    IDP_RESZ_CRZ_MASK__CLIP_RIGHT,

    IDP_RESZ_CRZ_MASK__PITCH_EN,
    IDP_RESZ_CRZ_MASK__PITCH_WIDTH,

    IDP_RESZ_CRZ_MASK__PASS_1_DONE_INTR_EN,
    IDP_RESZ_CRZ_MASK__PASS_1_DONE_INTR_CB,
    IDP_RESZ_CRZ_MASK__PASS_1_DONE_INTR_CB_PARAM,

    IDP_RESZ_CRZ_MASK__PASS_2_DONE_INTR_EN,
    IDP_RESZ_CRZ_MASK__PASS_2_DONE_INTR_CB,
    IDP_RESZ_CRZ_MASK__PASS_2_DONE_INTR_CB_PARAM,

    IDP_RESZ_CRZ_MASK__START_INTR_EN,
    IDP_RESZ_CRZ_MASK__START_INTR_CB,
    IDP_RESZ_CRZ_MASK__START_INTR_CB_PARAM,

    IDP_RESZ_CRZ_MASK__PIXEL_DROPPED_INTR_EN,
    IDP_RESZ_CRZ_MASK__PIXEL_DROPPED_INTR_CB,
    IDP_RESZ_CRZ_MASK__PIXEL_DROPPED_INTR_CB_PARAM,

    //IDP_RESZ_CRZ_MASK__LCD_DC_DONE_INTR_EN,
    //IDP_RESZ_CRZ_MASK__LCD_DC_DONE_INTR_CB,
    //IDP_RESZ_CRZ_MASK__LCD_DC_DONE_INTR_CB_PARAM,

#if defined(MP4_ENCODE) //// sw video
    //IDP_RESZ_CRZ_MASK__MP4_ENCODE_GET_BUFFER_CB,
#endif // #if defined(MP4_ENCODE) //// sw video

#if defined(MJPG_ENCODE)
    //IDP_RESZ_CRZ_MASK__MJPG_START_ENCODE_CB,
#endif // #if defined(MJPG_ENCODE)

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
    /// input source
    idp_module_enum_t         image_src_1; /**< Input source for resizer 1st pass. */
    idp_module_enum_t         image_src_2; /**< Input source for resizer 2nd pass. */

    /// output format
    MM_IMAGE_COLOR_FORMAT_ENUM      output_color_fmt_1; /**< Output format of resizer 1st pass. */
    MM_IMAGE_COLOR_FORMAT_ENUM      output_color_fmt_2; /**< Output format of resizer 2nd pass. */

    /* RGB565 base address */
    kal_uint32                  rgb_tar_base1; /**< better 16x aligned. at least 4x aligned */
    kal_uint32                  rgb_tar_base2; /**< better 16x aligned. at least 4x aligned */

    /* YUV420 base address 0 */
    kal_uint32                  y_tar_base; /**< better 16x aligned. at least 4x aligned */
    kal_uint32                  u_tar_base; /**< better 16x aligned. at least 4x aligned */
    kal_uint32                  v_tar_base; /**< better 16x aligned. at least 4x aligned */

    /* YUV420 base address 1 */
    kal_uint32                  y_tar_base_1; /**< better 16x aligned. at least 4x aligned */
    kal_uint32                  u_tar_base_1; /**< better 16x aligned. at least 4x aligned */
    kal_uint32                  v_tar_base_1; /**< better 16x aligned. at least 4x aligned */

    /* base address of working memory */
    kal_uint32                  wmbase; /**< base address of working memory, must be 4x aligned. */
    kal_uint32                  wmsize; /**< line buffer count of working memory. */

    /* source YUV420 base address */
    kal_uint32                  y_src_base; /**< better 16x aligned. at least 4x aligned */
    kal_uint32                  u_src_base; /**< better 16x aligned. at least 4x aligned */
    kal_uint32                  v_src_base; /**< better 16x aligned. at least 4x aligned */

    /* source and target size of resizer 1st pass. */
    kal_uint16                  src1_width;
    kal_uint16                  src1_height;
    kal_uint16                  tar1_width;
    kal_uint16                  tar1_height;

    /* source and target size of resizer 2nd pass. */
    kal_uint16                  src2_width;
    kal_uint16                  src2_height;
    kal_uint16                  tar2_width;
    kal_uint16                  tar2_height;

    //kal_bool                  doublebuff_enable;
    kal_bool                    pass2_enable; /**< Enable 2nd pass of resizer. */
    kal_bool                    continuous; /**< Auto restart mode. */
    //kal_bool                    trigger_lcd; /**< Enable LCD HW trigger. */

    /* target clipping */
    kal_bool                    enable_clip; /**< Only applied to RGB565 output */
    kal_uint16                  clip_top; /**< [0, target height for RGB565 output) */
    kal_uint16                  clip_bottom; /**< [clip_top + 1, target height for RGB565 output) */
    kal_uint16                  clip_left; /**< [0, target width for RGB565 output) */
    kal_uint16                  clip_right; /**< [clip_right + 1, target width for RGB565 output) */

    /* target pitching */
    kal_bool                    enable_pitch; /**< Only applied to RGB565 output */
    kal_uint16                  pitch_width; /**< pitch width in pixel, should be even number */

    /* New callback functions. */
    kal_bool                  pass_1_done_intr_en;
    idp_lisr_intr_cb_t        pass_1_done_intr_cb;
    idp_lisr_intr_cb_param_t  pass_1_done_intr_cb_param;

    kal_bool                  pass_2_done_intr_en;
    idp_lisr_intr_cb_t        pass_2_done_intr_cb;
    idp_lisr_intr_cb_param_t  pass_2_done_intr_cb_param;

    kal_bool                  start_intr_en;
    idp_lisr_intr_cb_t        start_intr_cb;
    idp_lisr_intr_cb_param_t  start_intr_cb_param;

    kal_bool                  pixel_dropped_intr_en;
    idp_lisr_intr_cb_t        pixel_dropped_intr_cb;
    idp_lisr_intr_cb_param_t  pixel_dropped_intr_cb_param;

    //kal_bool                  lcd_dc_done_intr_en;
    //idp_lisr_intr_cb_t        lcd_dc_done_intr_cb;
    //idp_lisr_intr_cb_param_t  lcd_dc_done_intr_cb_param;

    /* Legacy I/F callback functions. (Deprecated) */
    void                        (*cb)(void *para);
    void                        (*resize_cb)(kal_uint8 return_code); /**< Resizer done. */
    void                        (*frame_start_cb)(kal_uint8 return_code); /**< The callback of frame start. Designed for digital zooming. */
#if defined(MP4_ENCODE) //// sw video
    ///KKKKK new callback function
    //kal_uint32                  (*get_buffer_cb)(void); /**< Notify SW video encoder to provide another YUV420 frame buffer and start to do MP4 encode. */
#endif // #if defined(MP4_ENCODE) //// sw video

#if defined(MJPG_ENCODE)
    //void                        (*cbfxn_mjpg_start_encode_cb)(kal_uint8 return_code); /**< Notify MED to start to do JPEG encode in MJPEG encode scenario. */
#endif // #if defined(MJPG_ENCODE)
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
idp_resz_crz_close_real(void);

extern void
idp_resz_crz_open_real(void);

extern void
idp_resz_crz_forced_reset(void);

extern kal_bool
idp_resz_crz_is_busy_real(
    kal_bool * const p_busy,
    idp_resz_crz_struct const * const p_crz_struct);

extern kal_bool
rszr_check_size_limitation(
    kal_uint32 source_width,
    kal_uint32 source_height,
    kal_uint32 target_width,
    kal_uint32 target_height);

#endif // #if defined(DRV_IDP_6253_SERIES)

#endif // #ifndef __idp_resz_crz_mt6253_h__

