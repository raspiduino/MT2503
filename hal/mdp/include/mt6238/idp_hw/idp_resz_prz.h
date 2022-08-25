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
 * 04 18 2011 hung-wen.hsieh
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

#ifndef __idp_resz_prz_mt6238_h__
#define __idp_resz_prz_mt6238_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include "drv_features_mdp.h"
#include "drv_comm.h"
#include <idp_define.h>

#if defined(DRV_IDP_6238_SERIES)

#include "reg_base.h"
#include "kal_public_api.h"
#include "idp_core.h"
#include "idp_resz.h"
#include "idp_hw_common.h"

#include "..\idp_mem.h"

/* ===============================================================
 *                       PRZ definition
 * =============================================================== */
/** \defgroup prz Post processing resizer
 * \ingroup resizer
 * @{
 */
#define PRZ_CONFIG_REG             (PRZ_base + 0x00)
#define PRZ_CTRL_REG               (PRZ_base + 0x04)
#define PRZ_STATUS_REG             (PRZ_base + 0x08)
#define PRZ_INT_STATUS_REG         (PRZ_base + 0x0C)
#define PRZ_SOURCE_IMAGE_SIZE_REG  (PRZ_base + 0x10)
#define PRZ_TARGET_IMAGE_SIZE_REG  (PRZ_base + 0x14)
#define PRZ_H_RATIO_REG            (PRZ_base + 0x18)
#define PRZ_V_RATIO_REG            (PRZ_base + 0x1C)
#define PRZ_H_RESIDUAL_REG         (PRZ_base + 0x20)
#define PRZ_V_RESIDUAL_REG         (PRZ_base + 0x24)
#define PRZ_BLOCK_CS_CFG_REG       (PRZ_base + 0x30)
#define PRZ_Y_LINE_BUFFER_ADDR_REG (PRZ_base + 0x34)
#define PRZ_U_LINE_BUFFER_ADDR_REG (PRZ_base + 0x38)
#define PRZ_V_LINE_BUFFER_ADDR_REG (PRZ_base + 0x3C)
#define PRZ_FINE_RESIZE_CFG_REG    (PRZ_base + 0x40)
#define PRZ_LINE_BUFFER_SIZE_REG   (PRZ_base + 0x50)
#define PRZ_WORK_MEM_ADDR_REG      (PRZ_base + 0x5C)
////ctfang: resizer debug config register
#define RESZ_BASE                  (PRZ_base)
#define RESZ_DBGCFG                (RESZ_BASE + 0x90)

#define REG_PRZ_CONFIG             *((volatile unsigned int *) (PRZ_base + 0x00))
#define REG_PRZ_CTRL               *((volatile unsigned int *) (PRZ_base + 0x04))
#define REG_PRZ_STATUS             *((volatile unsigned int *) (PRZ_base + 0x08))
#define REG_PRZ_INT_STATUS         *((volatile unsigned int *) (PRZ_base + 0x0C))
#define REG_PRZ_SOURCE_IMAGE_SIZE  *((volatile unsigned int *) (PRZ_base + 0x10))
#define REG_PRZ_TARGET_IMAGE_SIZE  *((volatile unsigned int *) (PRZ_base + 0x14))
#define REG_PRZ_H_RATIO            *((volatile unsigned int *) (PRZ_base + 0x18))
#define REG_PRZ_V_RATIO            *((volatile unsigned int *) (PRZ_base + 0x1C))
#define REG_PRZ_H_RESIDUAL         *((volatile unsigned int *) (PRZ_base + 0x20))
#define REG_PRZ_V_RESIDUAL         *((volatile unsigned int *) (PRZ_base + 0x24))
#define REG_PRZ_BLOCK_CS_CFG       *((volatile unsigned int *) (PRZ_base + 0x30))
#define REG_PRZ_Y_LINE_BUFFER_ADDR *((volatile unsigned int *) (PRZ_base + 0x34))
#define REG_PRZ_U_LINE_BUFFER_ADDR *((volatile unsigned int *) (PRZ_base + 0x38))
#define REG_PRZ_V_LINE_BUFFER_ADDR *((volatile unsigned int *) (PRZ_base + 0x3C))
#define REG_PRZ_FINE_RESIZE_CFG    *((volatile unsigned int *) (PRZ_base + 0x40))
#define REG_PRZ_LINE_BUFFER_SIZE   *((volatile unsigned int *) (PRZ_base + 0x50))
#define REG_PRZ_WORK_MEM_ADDR      *((volatile unsigned int *) (PRZ_base + 0x5C))
////ctfang: SW work-around for PRZ HW bug CR#10197417
#define REG_RESZ_DBGCFG            *((volatile unsigned int *) RESZ_DBGCFG)

/* bit mapping of PRZ config register */
#define PRZ_CONFIG_LINE_BUF_SEL_BIT 0x00000080
#define PRZ_CONFIG_PIXEL_SRC_MASK   0x0000000F
#define PRZ_CONFIG_SRC_SEL_BIT      0x00000020
#define PRZ_CONFIG_CONT_RUN_BIT     0x00000010
#define PRZ_CONFIG_BWA0_MASK        0x000F0000
#define PRZ_CONFIG_BWB0_MASK        0x00F00000

#define PRZ_CONFIG_PIXEL_SRC_IMAGE_ROTATOR         1
#define PRZ_CONFIG_PIXEL_SRC_MP4_DEBLOCKING        2
#define PRZ_CONFIG_PIXEL_SRC_IBW4_DMA              3
#define PRZ_CONFIG_PIXEL_SRC_R2Y                   4
#define PRZ_CONFIG_PIXEL_SRC_JPEG_DECODER          5

/* bit mapping of PRZ control register */
#define PRZ_CTRL_RESET_MASK                   0x00070000
#define PRZ_CTRL_ENABLE_MASK                  0x00000007
#define PRZ_CTRL_BLOCK_CS_ENABLE_BIT          0x00000001
#define PRZ_CTRL_H_FINE_RESIZE_ENABLE_BIT     0x00000002
#define PRZ_CTRL_V_FINE_RESIZE_ENABLE_BIT     0x00000004
#define PRZ_CTRL_BLOCK_CS_RESET_BIT           0x00010000
#define PRZ_CTRL_H_FINE_RESIZE_RESET_BIT      0x00020000
#define PRZ_CTRL_V_FINE_RESIZE_RESET_BIT      0x00040000
#if defined(MT6268)
#define PRZ_CTRL_INIT_PROCESS_ENABLE          0x00000010
#endif // chip option

/* bit mapping of PRZ status register */
#define PRZ_CTRL_BLOCK_CS_BUSY_BIT       0x00000001
#define PRZ_CTRL_H_FINE_RESIZE_BUSY_BIT  0x00000002
#define PRZ_CTRL_V_FINE_RESIZE_BUSY_BIT  0x00000004
#define PRZ_CTRL_BLOCK_CS_INTRA_BUSY_BIT 0x00000010

/* bit mapping of PRZ interrupt status register */
#define PRZ_CTRL_BLOCK_CS_INT_BIT        0x00000001
#define PRZ_CTRL_H_FINE_RESIZE_INT_BIT   0x00000002
#define PRZ_CTRL_V_FINE_RESIZE_INT_BIT   0x00000004

/* bit mapping of PRZ source and target size register */
#define PRZ_IMAGE_SIZE_WIDTH_MASK   0x0000FFFF
#define PRZ_IMAGE_SIZE_HEIGHT_MASK  0xFFFF0000

/* bit mapping of PRZ block coarse shrink config register */
#define PRZ_BLOCK_CS_CFG_BLOCK_INTR_ENABLE_BIT    0x00010000
#define PRZ_BLOCK_CS_CFG_V_V_SAMPLE_FACTOR_MASK   0x0000C000
#define PRZ_BLOCK_CS_CFG_V_H_SAMPLE_FACTOR_MASK   0x00003000
#define PRZ_BLOCK_CS_CFG_U_V_SAMPLE_FACTOR_MASK   0x00000C00
#define PRZ_BLOCK_CS_CFG_U_H_SAMPLE_FACTOR_MASK   0x00000300
#define PRZ_BLOCK_CS_CFG_Y_V_SAMPLE_FACTOR_MASK   0x000000C0
#define PRZ_BLOCK_CS_CFG_Y_H_SAMPLE_FACTOR_MASK   0x00000030
#define PRZ_BLOCK_CS_CFG_CS_FACTOR_MASK           0x00000003

/* definition of resizer block CS register */
#define BLOCK_CS_1_1        0x00000000
#define BLOCK_CS_1_4        0x00000001
#define BLOCK_CS_1_16       0x00000002
#define BLOCK_CS_1_64       0x00000003
#define BLOCK_Y_H_FACTOR_1  0x00000000
#define BLOCK_Y_H_FACTOR_2  0x00000010
#define BLOCK_Y_H_FACTOR_4  0x00000020
#define BLOCK_NO_Y_H_COMP   0x00000030
#define BLOCK_Y_V_FACTOR_1  0x00000000
#define BLOCK_Y_V_FACTOR_2  0x00000040
#define BLOCK_Y_V_FACTOR_4  0x00000080
#define BLOCK_NO_Y_V_COMP   0x000000C0
#define BLOCK_U_H_FACTOR_1  0x00000000
#define BLOCK_U_H_FACTOR_2  0x00000100
#define BLOCK_U_H_FACTOR_4  0x00000200
#define BLOCK_NO_U_H_COMP   0x00000300
#define BLOCK_U_V_FACTOR_1  0x00000000
#define BLOCK_U_V_FACTOR_2  0x00000400
#define BLOCK_U_V_FACTOR_4  0x00000800
#define BLOCK_NO_U_V_COMP   0x00000CC0
#define BLOCK_V_H_FACTOR_1  0x00000000
#define BLOCK_V_H_FACTOR_2  0x00001000
#define BLOCK_V_H_FACTOR_4  0x00002000
#define BLOCK_NO_V_H_COMP   0x00003000
#define BLOCK_V_V_FACTOR_1  0x00000000
#define BLOCK_V_V_FACTOR_2  0x00004000
#define BLOCK_V_V_FACTOR_4  0x00008000
#define BLOCK_NO_V_V_COMP   0x0000C000

/* bit mapping of PRZ fine resize config register */
#define PRZ_FINE_RESIZE_VRSS_BIT           0x00000001
#define PRZ_H_FINE_RESIZE_INT              0x00000010
#define PRZ_V_FINE_RESIZE_INT              0x00000020
#define PRZ_FINE_RESIZE_CS_FACTOR_MASK     0x00000300
#define PRZ_FINE_RESIZE_OUTPUT_MASK        0x0000E000
#define PRZ_FINE_RESIZE_OUTPUT_CRZ         0x00002000
#define PRZ_FINE_RESIZE_OUTPUT_IPP1        0x00004000
#define PRZ_FINE_RESIZE_OUTPUT_Y2R1        0x00008000
#define PRZ_FINE_RESIZE_WORK_MEM_SIZE_MASK 0xFFFF0000

/* bit mapping of PRZ line buffer size register */
#define PRZ_LINE_BUFF_SIZE_MASK  0x0000FFFF
 
/*output module*/
#define PRZ_OUTPUT_MASK     0x0000e000
#define PRZ_OUTPUT_CRZ      0x00002000 /**< Only for source from JPEG Decoder */
#define PRZ_OUTPUT_IPP1     0x00004000 /**< If not output to CRZ, output to IPP1 and Y2R1 are not MUTEX */
#define PRZ_OUTPUT_Y2R1     0x00008000

#define IDP_RESZ_PRZ_FINE_RESZ_MAX_INPUT_WIDTH  (4095)
#define IDP_RESZ_PRZ_FINE_RESZ_MAX_INPUT_HEIGHT (4095)

#define IDP_RESZ_PRZ_FINE_RESZ_MAX_OUTPUT_WIDTH  (4095)
#define IDP_RESZ_PRZ_FINE_RESZ_MAX_OUTPUT_HEIGHT (4095)

/**
 * \brief Check if PRZ is started or not.
 */
#define IS_PRZ_START()                                                  \
  (((REG_PRZ_CTRL & PRZ_CTRL_ENABLE_MASK) != 0)                         \
   ? KAL_TRUE                                                           \
   : KAL_FALSE)

/* Macros of PRZ control register */
#define SET_PRZ_SRC(src)                            \
  do {                                              \
    REG_PRZ_CONFIG &= ~PRZ_CONFIG_PIXEL_SRC_MASK;   \
    REG_PRZ_CONFIG |= src;                          \
  } while(0)

#define SET_PRZ_OUTPUT(module)                      \
  do {                                              \
    REG_PRZ_FINE_RESIZE_CFG &= ~PRZ_OUTPUT_MASK;    \
    REG_PRZ_FINE_RESIZE_CFG |= module;              \
  } while(0)

#define SET_PRZ_BWA0(value)                     \
  do {                                          \
    REG_PRZ_CONFIG &= ~PRZ_CONFIG_BWA0_MASK;    \
    REG_PRZ_CONFIG |= (value << 16);            \
  } while(0)

#define SET_PRZ_BWB0(value)                     \
  do {                                          \
    REG_PRZ_CONFIG &= ~PRZ_CONFIG_BWB0_MASK;    \
    REG_PRZ_CONFIG |= (value << 24);            \
  } while(0)

#define SET_PRZ_PIXEL_MODE()        do { REG_PRZ_CONFIG |= PRZ_CONFIG_SRC_SEL_BIT; } while(0)
#define SET_PRZ_BLOCK_MODE()        do { REG_PRZ_CONFIG &= ~PRZ_CONFIG_SRC_SEL_BIT; } while(0)
#define SET_PRZ_CONT_RUN_MODE()     do { REG_PRZ_CONFIG |= PRZ_CONFIG_CONT_RUN_BIT; } while(0)
#define SET_PRZ_SINGLE_RUN_MODE()   do { REG_PRZ_CONFIG &= ~PRZ_CONFIG_CONT_RUN_BIT; } while(0)
#define SET_PRZ_SHARED_MEMORY()     do { REG_PRZ_CONFIG &= ~PRZ_CONFIG_LINE_BUF_SEL_BIT; } while(0)
#define SET_PRZ_DEDICATED_MEMORY()  do { REG_PRZ_CONFIG |= PRZ_CONFIG_LINE_BUF_SEL_BIT; } while(0)

/* Macros of PRZ control register */
//ctfang: MT6268B uses the same register for HW frame sync, so we cannot write the whole register
#if defined(MT6268)
#define RESET_PRZ()                                         \
  do {                                                      \
    REG_PRZ_CTRL &= ~PRZ_CTRL_ENABLE_MASK;                  \
    REG_PRZ_CTRL |= PRZ_CTRL_RESET_MASK;                    \
    REG_PRZ_CTRL &= ~PRZ_CTRL_RESET_MASK;                   \
  } while(0)
#else // chip option MT6238 MT6268A
#define RESET_PRZ()                       do { REG_PRZ_CTRL = PRZ_CTRL_RESET_MASK; REG_PRZ_CTRL = 0; } while(0)
#endif // chip option
#define SET_BLOCK_CS_RESET()              do { REG_PRZ_CTRL |= PRZ_CTRL_BLOCK_CS_RESET_BIT; } while(0)
#define CLEAR_BLOCK_CS_RESET()            do { REG_PRZ_CTRL &= ~PRZ_CTRL_BLOCK_CS_RESET_BIT; } while(0)
#define SET_PRZ_H_FINE_RESIZE_RESET()     do { REG_PRZ_CTRL |= PRZ_CTRL_H_FINE_RESIZE_RESET_BIT; } while(0)
#define CLEAR_PRZ_H_FINE_RESIZE_RESET()   do { REG_PRZ_CTRL &= ~PRZ_CTRL_H_FINE_RESIZE_RESET_BIT; } while(0)
#define SET_PRZ_V_FINE_RESIZE_RESET()     do { REG_PRZ_CTRL |= PRZ_CTRL_V_FINE_RESIZE_RESET_BIT; } while(0)
#define CLEAR_PRZ_V_FINE_RESIZE_RESET()   do { REG_PRZ_CTRL &= ~PRZ_CTRL_V_FINE_RESIZE_RESET_BIT; } while(0)

#define ENABLE_BLOCK_CS_BLOCK()           do { REG_PRZ_CTRL |= PRZ_CTRL_BLOCK_CS_ENABLE_BIT; } while(0)
#define DISABLE_BLOCK_CS_BLOCK()          do { REG_PRZ_CTRL &= ~PRZ_CTRL_BLOCK_CS_ENABLE_BIT; } while(0)
#define ENABLE_PRZ_H_LINE()               do { REG_PRZ_CTRL |= PRZ_CTRL_H_FINE_RESIZE_ENABLE_BIT; } while(0)
#define DISABLE_PRZ_H_LINE()              do { REG_PRZ_CTRL &= ~PRZ_CTRL_H_FINE_RESIZE_ENABLE_BIT; } while(0)
#define ENABLE_PRZ_V_LINE()               do { REG_PRZ_CTRL |= PRZ_CTRL_V_FINE_RESIZE_ENABLE_BIT; } while(0)
#define DISABLE_PRZ_V_LINE()              do { REG_PRZ_CTRL &= ~PRZ_CTRL_V_FINE_RESIZE_ENABLE_BIT; } while(0)
//ctfang: MT6268B uses the same register for HW frame sync, so we cannot write the whole register
#if defined(MT6268)
#define ENABLE_PRZ()                                        \
  do {                                                      \
    REG_PRZ_CTRL &= ~PRZ_CTRL_RESET_MASK;                   \
    REG_PRZ_CTRL |= PRZ_CTRL_ENABLE_MASK;                   \
  } while(0)
#define ENABLE_PRZ_HW_FRAME_SYNC()        do { REG_PRZ_CTRL |= PRZ_CTRL_INIT_PROCESS_ENABLE; } while(0)
#define DISABLE_PRZ_HW_FRAME_SYNC()       do { REG_PRZ_CTRL &= ~PRZ_CTRL_INIT_PROCESS_ENABLE; } while(0)
#else // chip option MT6238 MT6268A
#define ENABLE_PRZ()                      do { REG_PRZ_CTRL = PRZ_CTRL_ENABLE_MASK; } while(0)
#endif // chip option

/* Macros of PRZ status register */
#define IS_BLOCK_CS_BUSY          (REG_PRZ_STATUS & PRZ_CTRL_BLOCK_CS_BUSY_BIT)
#define IS_PRZ_H_FINE_RESIZE_BUSY (REG_PRZ_STATUS & PRZ_CTRL_H_FINE_RESIZE_BUSY_BIT)
#define IS_PRZ_V_FINE_RESIZE_BUSY (REG_PRZ_STATUS & PRZ_CTRL_V_FINE_RESIZE_BUSY_BIT)
#define IS_BLOCK_CS_INTRA_BUSY    (REG_PRZ_STATUS & PRZ_CTRL_BLOCK_CS_INTRA_BUSY_BIT)

/* Macros of PRZ source image size register */
#define SET_PRZ_SRC_SIZE(width, height)                     \
  do {                                                      \
    REG_PRZ_SOURCE_IMAGE_SIZE = (width | (height << 16));   \
  } while(0)

/* Macros of PRZ target image size register */
#define SET_PRZ_TARGET_SIZE(width, height)                  \
  do {                                                      \
    REG_PRZ_TARGET_IMAGE_SIZE = (width | (height << 16));   \
  } while(0)

/* Macros of resizer block coarse shrinking config register */
#define SET_PRZ_BLOCK_CS_V_V_FACTOR(factor)                                   \
  do {                                                                        \
    ASSERT((1 == factor) || (2 == factor) || (4 == factor) || (6 == factor)); \
    REG_PRZ_BLOCK_CS_CFG &= ~PRZ_BLOCK_CS_CFG_V_V_SAMPLE_FACTOR_MASK;         \
    REG_PRZ_BLOCK_CS_CFG |= ((factor>>1)<<14);                                \
  } while(0)

#define SET_PRZ_BLOCK_CS_V_H_FACTOR(factor)                                   \
  do {                                                                        \
    ASSERT((1 == factor) || (2 == factor) || (4 == factor) || (6 == factor)); \
    REG_PRZ_BLOCK_CS_CFG &= ~PRZ_BLOCK_CS_CFG_V_H_SAMPLE_FACTOR_MASK;         \
    REG_PRZ_BLOCK_CS_CFG |= ((factor>>1)<<12);                                \
  } while(0)

#define SET_PRZ_BLOCK_CS_U_V_FACTOR(factor)                                   \
  do {                                                                        \
    ASSERT((1 == factor) || (2 == factor) || (4 == factor) || (6 == factor)); \
    REG_PRZ_BLOCK_CS_CFG &= ~PRZ_BLOCK_CS_CFG_U_V_SAMPLE_FACTOR_MASK;         \
    REG_PRZ_BLOCK_CS_CFG |= ((factor>>1)<<10);                                \
  } while(0)

#define SET_PRZ_BLOCK_CS_U_H_FACTOR(factor)                                   \
  do {                                                                        \
    ASSERT((1 == factor) || (2 == factor) || (4 == factor) || (6 == factor)); \
    REG_PRZ_BLOCK_CS_CFG &= ~PRZ_BLOCK_CS_CFG_U_H_SAMPLE_FACTOR_MASK;         \
    REG_PRZ_BLOCK_CS_CFG |= ((factor>>1)<<8);                                 \
  } while(0)

#define SET_PRZ_BLOCK_CS_Y_V_FACTOR(factor)                                   \
  do {                                                                        \
    ASSERT((1 == factor) || (2 == factor) || (4 == factor) || (6 == factor)); \
    REG_PRZ_BLOCK_CS_CFG &= ~PRZ_BLOCK_CS_CFG_Y_V_SAMPLE_FACTOR_MASK;         \
    REG_PRZ_BLOCK_CS_CFG |= ((factor>>1)<<6);                                 \
  } while(0)

#define SET_PRZ_BLOCK_CS_Y_H_FACTOR(factor)                                   \
  do {                                                                        \
    ASSERT((1 == factor) || (2 == factor) || (4 == factor) || (6 == factor)); \
    REG_PRZ_BLOCK_CS_CFG &= ~PRZ_BLOCK_CS_CFG_Y_H_SAMPLE_FACTOR_MASK;         \
    REG_PRZ_BLOCK_CS_CFG |= ((factor>>1)<<4);                                 \
  } while(0)

#define SET_PRZ_BLOCK_CS_FACTOR(factor)                         \
  do {                                                          \
    REG_PRZ_BLOCK_CS_CFG &= ~PRZ_BLOCK_CS_CFG_CS_FACTOR_MASK;   \
    REG_PRZ_BLOCK_CS_CFG |= factor;                             \
  } while(0)

#define ENABLE_BLOCK_INT()                                          \
  do {                                                              \
    REG_PRZ_BLOCK_CS_CFG |= PRZ_BLOCK_CS_CFG_BLOCK_INTR_ENABLE_BIT; \
  } while(0)

#define DISABLE_BLOCK_INT()                                           \
  do {                                                                \
    REG_PRZ_BLOCK_CS_CFG &= ~PRZ_BLOCK_CS_CFG_BLOCK_INTR_ENABLE_BIT;  \
  } while(0)

/* macros of PRZ fine resizer config register */
#define SET_PRZ_FINE_RESIZE_WORK_MEM_SIZE(line)                     \
  do {                                                              \
    REG_PRZ_FINE_RESIZE_CFG &= ~PRZ_FINE_RESIZE_WORK_MEM_SIZE_MASK; \
    REG_PRZ_FINE_RESIZE_CFG |= (line<<16);                          \
  } while(0)

#define SET_PRZ_FINE_RESIZE_OUTPUT_CRZ()                          \
  do {                                                            \
    REG_PRZ_FINE_RESIZE_CFG &= ~PRZ_FINE_RESIZE_OUTPUT_MASK;      \
    REG_PRZ_FINE_RESIZE_CFG |= PRZ_FINE_RESIZE_OUTPUT_CRZ;        \
  } while(0)

#define SET_PRZ_FINE_RESIZE_OUTPUT_Y2R1()                        \
  do {                                                           \
    REG_PRZ_FINE_RESIZE_CFG &= ~PRZ_FINE_RESIZE_OUTPUT_MASK;     \
    REG_PRZ_FINE_RESIZE_CFG |= PRZ_FINE_RESIZE_OUTPUT_Y2R1;      \
  } while(0)

#define SET_PRZ_FINE_RESIZE_OUTPUT_IPP1()                       \
  do {                                                          \
    REG_PRZ_FINE_RESIZE_CFG &= ~PRZ_FINE_RESIZE_OUTPUT_MASK;    \
    REG_PRZ_FINE_RESIZE_CFG |= PRZ_FINE_RESIZE_OUTPUT_IPP1;     \
  } while(0)

#define SET_PRZ_FINE_RESIZE_CS_FACTOR(factor)                      \
  do {                                                             \
    REG_PRZ_FINE_RESIZE_CFG &= ~PRZ_FINE_RESIZE_CS_FACTOR_MASK;    \
    REG_PRZ_FINE_RESIZE_CFG |= (factor << 8);                      \
  } while(0)

#define ENABLE_PRZ_FINE_RESIZE_VRSS()                     \
  do {                                                    \
    REG_PRZ_FINE_RESIZE_CFG |= PRZ_FINE_RESIZE_VRSS_BIT;  \
  } while(0)

#define DISABLE_PRZ_FINE_RESIZE_VRSS()                     \
  do {                                                     \
    REG_PRZ_FINE_RESIZE_CFG &= ~PRZ_FINE_RESIZE_VRSS_BIT;  \
  } while(0)

#define ENABLE_PRZ_H_RESIZE_INT()                       \
  do {                                                  \
    REG_PRZ_FINE_RESIZE_CFG |= PRZ_H_FINE_RESIZE_INT;   \
  } while(0)

#define DISABLE_PRZ_H_RESIZE_INT()                      \
  do {                                                  \
    REG_PRZ_FINE_RESIZE_CFG &= ~PRZ_H_FINE_RESIZE_INT;  \
  } while(0)

#define ENABLE_PRZ_V_RESIZE_INT()                       \
  do {                                                  \
    REG_PRZ_FINE_RESIZE_CFG |= PRZ_V_FINE_RESIZE_INT;   \
  } while(0)

#define DISABLE_PRZ_V_RESIZE_INT()                      \
  do {                                                  \
    REG_PRZ_FINE_RESIZE_CFG &= ~PRZ_V_FINE_RESIZE_INT;  \
  } while(0)

/* macros of PRZ line buffer size register */
#define SET_PRZ_FINE_RESIZE_LINE_BUFFER(n)      \
  do { REG_PRZ_LINE_BUFFER_SIZE = n; } while(0)

////ctfang: macros for forcing resizer to resize.
#define RESZ_FORCE_H_RESIZING()                         \
  do { REG_RESZ_DBGCFG |= 0x0400; } while(0)

#define RESZ_FORCE_V_RESIZING()                         \
  do { REG_RESZ_DBGCFG |= 0x0200; } while(0)
    
#define RESZ_CLEAR_FORCE_RESIZE_BITS()                  \
  do { REG_RESZ_DBGCFG &= ~0x0600; } while(0)

enum idp_resz_prz_error_code_t
{
  IDP_RESZ_PRZ_NO_ERROR,
  IDP_RESZ_PRZ_ERROR_CODE_SRC_WIDTH_TOO_LARGE,
  IDP_RESZ_PRZ_ERROR_CODE_SRC_WIDTH_TOO_SMALL,
  IDP_RESZ_PRZ_ERROR_CODE_SRC_HEIGHT_TOO_LARGE,
  IDP_RESZ_PRZ_ERROR_CODE_SRC_HEIGHT_TOO_SMALL,
  IDP_RESZ_PRZ_ERROR_CODE_TAR_WIDTH_TOO_LARGE,
  IDP_RESZ_PRZ_ERROR_CODE_TAR_WIDTH_TOO_SMALL,
  IDP_RESZ_PRZ_ERROR_CODE_TAR_HEIGHT_TOO_LARGE,
  IDP_RESZ_PRZ_ERROR_CODE_TAR_HEIGHT_TOO_SMALL, 
  IDP_RESZ_PRZ_ERROR_CODE_NOT_ENOUGH_MEMORY
};
typedef enum idp_resz_prz_error_code_t idp_resz_prz_error_code_t;

enum
{
  IDP_RESZ_PRZ_QUERY_ERROR_CODE = 1
};

typedef struct
{
  idp_module_enum_t         image_src;
  
  kal_bool                  output_to_CRZ;
  kal_bool                  output_to_IPP1;
  kal_bool                  output_to_Y2R1;
  
  kal_bool                  dedicate_memory;
  kal_bool                  continous;   
  
  kal_bool                  coarse_intr_en; 
  idp_lisr_intr_cb_t        coarse_intr_cb;
  idp_lisr_intr_cb_param_t  coarse_intr_cb_param;
  
  kal_bool                  h_intr_en; 
  idp_lisr_intr_cb_t        h_intr_cb;
  idp_lisr_intr_cb_param_t  h_intr_cb_param;
  
  kal_bool                  v_intr_en; 
  idp_lisr_intr_cb_t        v_intr_cb;
  idp_lisr_intr_cb_param_t  v_intr_cb_param;
  
  kal_bool                  coarse_en;
  kal_uint32                coarse_ratio;
  
  kal_uint16                orig_src_width;
  
  kal_uint16                src_height;
  kal_uint16                src_width; 
  kal_uint16                tar_height;
  kal_uint16                tar_width; 
  
  kal_uint32                work_mem_line_count;
  kal_uint32                work_mem_addr;
  
  kal_uint32                y_line_buff_addr;
  kal_uint32                u_line_buff_addr;
  kal_uint32                v_line_buff_addr; 
  kal_uint32                y_line_buff_size;
  
  kal_uint8                 y_h_factor;
  kal_uint8                 y_v_factor;
  kal_uint8                 u_h_factor;
  kal_uint8                 u_v_factor;
  kal_uint8                 v_h_factor;
  kal_uint8                 v_v_factor; 

  kal_bool                  reset; /***< [sw_frame_reset] KAL_TRUE, switch PELHRRST and PELVRRST of PRZ_CON; KAL_FALSE, no effect. */

#if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
  kal_bool                  hw_frame_sync; /**< KAL_TRUE: enable; KAL_FALSE: disable. */  
#endif // #if defined(DRV_IDP_FEATURE__HW_FRAME_SYNC)
} idp_resz_prz_struct;

IDP_HW_COMMON_API_DECLARATION(resz_prz)

extern kal_bool idp_resz_prz_config_real(
    idp_resz_prz_struct * const prz_struct,
    kal_bool const config_to_hardware);

extern kal_bool idp_resz_prz_stop_real(
  idp_resz_prz_struct const * const prz_struct);

extern kal_bool idp_resz_prz_start_real(
  idp_resz_prz_struct const * const prz_struct);

extern kal_bool idp_resz_prz_get_working_mem_size_real(
  idp_resz_prz_struct * const prz_struct,
  kal_uint32 * const size);

extern kal_bool idp_resz_prz_get_working_mem_real(
  kal_bool use_internal_mem,
  idp_resz_prz_struct * const prz_struct,
  kal_bool const do_alloc,
  kal_uint32 const max_allowable_size);

extern void idp_resz_prz_close_real(void);

/** @} */

#endif
#endif
