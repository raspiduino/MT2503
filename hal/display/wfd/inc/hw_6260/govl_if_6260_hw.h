/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *    govl_if_6260_hw.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    The macro definitions for MT6255 GOVL(share G2D) HW registers.
 *    \remark The file name is weird but aligns display driver traditions.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __GOVL_IF_6260_HW_H__
#define __GOVL_IF_6260_HW_H__

// TODO: [m] define one display drv feature macro for MT6276 GOVL
// TODO: [m] It is only defined when in MT6276 E2 chip
//#if !defined(MT6276_S00)//???sht

#if defined(MT6260) 
#include "Reg_base_mt6260.h"
#elif defined(MT6261) || defined(MT2501) || defined(MT2502)
#include "Reg_base_mt6261.h"
#endif

#if defined(__MTK_TARGET__)

//#include "Cirq.h"
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
  #define IRQ_GOVL_CODE IRQ_G2D_CODE
  #define DRV_GOVL_HISR_ID IRQ_G2D_CODE
#endif



#define GOVL_base											  (G2D_base)

#define REG_GOVL_START                                        *(volatile kal_uint16 *)(GOVL_base + 0x0000)
#define REG_GOVL_MODE_CTRL                                    *(volatile kal_uint32 *)(GOVL_base + 0x0004)
#define REG_GOVL_RESET                                        *(volatile kal_uint16 *)(GOVL_base + 0x0008)
#define REG_GOVL_STATUS                                       *(volatile kal_uint16 *)(GOVL_base + 0x000C)
#define REG_GOVL_IRQ                                          *(volatile kal_uint32 *)(GOVL_base + 0x0010)
#define REG_GOVL_SLOW_DOWN                                    *(volatile kal_uint32 *)(GOVL_base + 0x0014)
#define REG_GOVL_CACHE_CON                                    *(volatile kal_uint32 *)(GOVL_base + 0x0018)
#define REG_GOVL_ROI_CON                                      *(volatile kal_uint32 *)(GOVL_base + 0x0040)
#define REG_GOVL_W2M_ADDR                                     *(volatile kal_uint32 *)(GOVL_base + 0x0044)
#define REG_GOVL_W2M_PITCH                                    *(volatile kal_uint32 *)(GOVL_base + 0x0048)
#define REG_GOVL_ROI_OFFSET                                   *(volatile kal_uint32 *)(GOVL_base + 0x004C)
#define REG_GOVL_ROI_SIZE                                     *(volatile kal_uint32 *)(GOVL_base + 0x0050)
#define REG_GOVL_ROI_BGCLR                                    *(volatile kal_uint32 *)(GOVL_base + 0x0054)

#define REG_GOVL_LT_EDGE_FILTER_USER_SPECIFIED_COLOR          *(volatile kal_uint32 *)(GOVL_base + 0x0054)//share reg for G2D linear transfer, sht

#define REG_GOVL_CLP_MIN                                      *(volatile kal_uint32 *)(GOVL_base + 0x0058)
#define REG_GOVL_CLP_MAX                                      *(volatile kal_uint32 *)(GOVL_base + 0x005C)

#define REG_GOVL_AVOIDANCE_COLOR                              *(volatile kal_uint32 *)(GOVL_base + 0x0060)
#define REG_GOVL_REPLACEMENT_COLOR                            *(volatile kal_uint32 *)(GOVL_base + 0x0064)

#define REG_GOVL_W2M_OFFSET                                   *(volatile kal_uint32 *)(GOVL_base + 0x0068)

#define REG_GOVL_SAD_SUM                                      *(volatile kal_uint32 *)(GOVL_base + 0x006C)
#define REG_GOVL_DI_CON                                       *(volatile kal_uint32 *)(GOVL_base + 0x0078)

#define REG_GOVL_L0_CON                                       *(volatile kal_uint32 *)(GOVL_base + 0x0080)
#define REG_GOVL_L0_ADDR                                      *(volatile kal_uint32 *)(GOVL_base + 0x0084)
#define REG_GOVL_L0_PITCH                                     *(volatile kal_uint16 *)(GOVL_base + 0x0088)
#define REG_GOVL_L0_OFFSET                                    *(volatile kal_uint32 *)(GOVL_base + 0x008C)
#define REG_GOVL_L0_SIZE                                      *(volatile kal_uint32 *)(GOVL_base + 0x0090)
#define REG_GOVL_L0_SRC_KEY                                   *(volatile kal_uint32 *)(GOVL_base + 0x0094)
#define REG_GOVL_L0_RECTANGLE_FILL_COLOR                      *(volatile kal_uint32 *)(GOVL_base + 0x0094)
#define REG_GOVL_L0_FONT_FOREGROUND_COLOR                     *(volatile kal_uint32 *)(GOVL_base + 0x0094)

#define REG_GOVL_L1_CON                                       *(volatile kal_uint32 *)(GOVL_base + 0x00C0)
#define REG_GOVL_L1_ADDR                                      *(volatile kal_uint32 *)(GOVL_base + 0x00C4)
#define REG_GOVL_L1_PITCH                                     *(volatile kal_uint16 *)(GOVL_base + 0x00C8)
#define REG_GOVL_L1_OFFSET                                    *(volatile kal_uint32 *)(GOVL_base + 0x00CC)
#define REG_GOVL_L1_SIZE                                      *(volatile kal_uint32 *)(GOVL_base + 0x00D0)
#define REG_GOVL_L1_SRC_KEY                                   *(volatile kal_uint32 *)(GOVL_base + 0x00D4)
#define REG_GOVL_L1_RECTANGLE_FILL_COLOR                      *(volatile kal_uint32 *)(GOVL_base + 0x00D4)
#define REG_GOVL_L1_FONT_FOREGROUND_COLOR                     *(volatile kal_uint32 *)(GOVL_base + 0x00D4)

#define REG_GOVL_L2_CON                                       *(volatile kal_uint32 *)(GOVL_base + 0x0100)
#define REG_GOVL_L2_ADDR                                      *(volatile kal_uint32 *)(GOVL_base + 0x0104)
#define REG_GOVL_L2_PITCH                                     *(volatile kal_uint16 *)(GOVL_base + 0x0108)
#define REG_GOVL_L2_OFFSET                                    *(volatile kal_uint32 *)(GOVL_base + 0x010C)
#define REG_GOVL_L2_SIZE                                      *(volatile kal_uint32 *)(GOVL_base + 0x0110)
#define REG_GOVL_L2_SRC_KEY                                   *(volatile kal_uint32 *)(GOVL_base + 0x0114)
#define REG_GOVL_L2_RECTANGLE_FILL_COLOR                      *(volatile kal_uint32 *)(GOVL_base + 0x0114)
#define REG_GOVL_L2_FONT_FOREGROUND_COLOR                     *(volatile kal_uint32 *)(GOVL_base + 0x0114)

#define REG_GOVL_L3_CON                                       *(volatile kal_uint32 *)(GOVL_base + 0x0140)
#define REG_GOVL_L3_ADDR                                      *(volatile kal_uint32 *)(GOVL_base + 0x0144)
#define REG_GOVL_L3_PITCH                                     *(volatile kal_uint16 *)(GOVL_base + 0x0148)
#define REG_GOVL_L3_OFFSET                                    *(volatile kal_uint32 *)(GOVL_base + 0x014C)
#define REG_GOVL_L3_SIZE                                      *(volatile kal_uint32 *)(GOVL_base + 0x0150)
#define REG_GOVL_L3_SRC_KEY                                   *(volatile kal_uint32 *)(GOVL_base + 0x0154)
#define REG_GOVL_L3_RECTANGLE_FILL_COLOR                      *(volatile kal_uint32 *)(GOVL_base + 0x0154)
#define REG_GOVL_L3_FONT_FOREGROUND_COLOR                     *(volatile kal_uint32 *)(GOVL_base + 0x0154)

#define GOVL_LAYER_ADDR_OFFSET                                (0x40)

#define REG_GOVL_LAYER_CON(n)                                 *((volatile kal_uint32 *) (GOVL_base + 0x0080 + (n) * GOVL_LAYER_ADDR_OFFSET))
#define REG_GOVL_LAYER_ADDR(n)                                *((volatile kal_uint32 *) (GOVL_base + 0x0084 + (n) * GOVL_LAYER_ADDR_OFFSET))
#define REG_GOVL_LAYER_PITCH(n)                               *((volatile kal_uint16 *) (GOVL_base + 0x0088 + (n) * GOVL_LAYER_ADDR_OFFSET))
#define REG_GOVL_LAYER_OFFSET(n)                              *((volatile kal_uint32 *) (GOVL_base + 0x008C + (n) * GOVL_LAYER_ADDR_OFFSET))
#define REG_GOVL_LAYER_SIZE(n)                                *((volatile kal_uint32 *) (GOVL_base + 0x0090 + (n) * GOVL_LAYER_ADDR_OFFSET))
#define REG_GOVL_LAYER_SRC_KEY(n)                             *((volatile kal_uint32 *) (GOVL_base + 0x0094 + (n) * GOVL_LAYER_ADDR_OFFSET))
#define REG_GOVL_LAYER_RECTANGLE_FILL_COLOR(n)                *((volatile kal_uint32 *) (GOVL_base + 0x0094 + (n) * GOVL_LAYER_ADDR_OFFSET))
#define REG_GOVL_LAYER_FONT_FOREGROUND_COLOR(n)               *((volatile kal_uint32 *) (GOVL_base + 0x0094 + (n) * GOVL_LAYER_ADDR_OFFSET))

#else   // #if defined(__MTK_TARGET__)
   
#define REG_GOVL_START                                        GOVL_hw_registers[0]
#define REG_GOVL_MODE_CTRL                                    GOVL_hw_registers[1]
#define REG_GOVL_RESET                                        GOVL_hw_registers[2]
#define REG_GOVL_STATUS                                       GOVL_hw_registers[3]
#define REG_GOVL_IRQ                                          GOVL_hw_registers[4]
#define REG_GOVL_SLOW_DOWN                                    GOVL_hw_registers[5]
#define REG_GOVL_CACHE_CON                                    GOVL_hw_registers[6]
#define REG_GOVL_ROI_CON                                      GOVL_hw_registers[7]
#define REG_GOVL_W2M_ADDR                                     GOVL_hw_registers[8]
#define REG_GOVL_W2M_PITCH                                    GOVL_hw_registers[9]
#define REG_GOVL_ROI_OFFSET                                   GOVL_hw_registers[10]
#define REG_GOVL_ROI_SIZE                                     GOVL_hw_registers[11]
#define REG_GOVL_ROI_BGCLR                                    GOVL_hw_registers[12]

#define REG_GOVL_LT_EDGE_FILTER_USER_SPECIFIED_COLOR          GOVL_hw_registers[12]

#define REG_GOVL_CLP_MIN                                      GOVL_hw_registers[13]
#define REG_GOVL_CLP_MAX                                      GOVL_hw_registers[14]

#define REG_GOVL_AVOIDANCE_COLOR                              GOVL_hw_registers[15]
#define REG_GOVL_REPLACEMENT_COLOR                            GOVL_hw_registers[16]

#define REG_GOVL_W2M_OFFSET                                   GOVL_hw_registers[17]

#define REG_GOVL_SAD_SUM                                      GOVL_hw_registers[18]

#define REG_GOVL_L0_CON                                       GOVL_hw_registers[19]
#define REG_GOVL_L0_ADDR                                      GOVL_hw_registers[20]
#define REG_GOVL_L0_PITCH                                     GOVL_hw_registers[21]
#define REG_GOVL_L0_OFFSET                                    GOVL_hw_registers[22]
#define REG_GOVL_L0_SIZE                                      GOVL_hw_registers[23]
#define REG_GOVL_L0_SRC_KEY                                   GOVL_hw_registers[24]
#define REG_GOVL_L0_RECTANGLE_FILL_COLOR                      GOVL_hw_registers[24]
#define REG_GOVL_L0_FONT_FOREGROUND_COLOR                     GOVL_hw_registers[24]

#define REG_GOVL_L1_CON                                       GOVL_hw_registers[25]
#define REG_GOVL_L1_ADDR                                      GOVL_hw_registers[26]
#define REG_GOVL_L1_PITCH                                     GOVL_hw_registers[27]
#define REG_GOVL_L1_OFFSET                                    GOVL_hw_registers[28]
#define REG_GOVL_L1_SIZE                                      GOVL_hw_registers[29]
#define REG_GOVL_L1_SRC_KEY                                   GOVL_hw_registers[30]
#define REG_GOVL_L1_RECTANGLE_FILL_COLOR                      GOVL_hw_registers[30]
#define REG_GOVL_L1_FONT_FOREGROUND_COLOR                     GOVL_hw_registers[30]

#define REG_GOVL_L2_CON                                       GOVL_hw_registers[31]
#define REG_GOVL_L2_ADDR                                      GOVL_hw_registers[32]
#define REG_GOVL_L2_PITCH                                     GOVL_hw_registers[33]
#define REG_GOVL_L2_OFFSET                                    GOVL_hw_registers[34]
#define REG_GOVL_L2_SIZE                                      GOVL_hw_registers[35]
#define REG_GOVL_L2_SRC_KEY                                   GOVL_hw_registers[36]
#define REG_GOVL_L2_RECTANGLE_FILL_COLOR                      GOVL_hw_registers[36]
#define REG_GOVL_L2_FONT_FOREGROUND_COLOR                     GOVL_hw_registers[36]

#define REG_GOVL_L3_CON                                       GOVL_hw_registers[37]
#define REG_GOVL_L3_ADDR                                      GOVL_hw_registers[38]
#define REG_GOVL_L3_PITCH                                     GOVL_hw_registers[39]
#define REG_GOVL_L3_OFFSET                                    GOVL_hw_registers[40]
#define REG_GOVL_L3_SIZE                                      GOVL_hw_registers[41]
#define REG_GOVL_L3_SRC_KEY                                   GOVL_hw_registers[42]
#define REG_GOVL_L3_RECTANGLE_FILL_COLOR                      GOVL_hw_registers[42]
#define REG_GOVL_L3_FONT_FOREGROUND_COLOR                     GOVL_hw_registers[42]

#define GOVL_LAYER_ADDR_OFFSET                                (0x6)

#define REG_GOVL_LAYER_CON(n)                                 GOVL_hw_registers[19  + (n) * GOVL_LAYER_ADDR_OFFSET]
#define REG_GOVL_LAYER_ADDR(n)                                GOVL_hw_registers[20  + (n) * GOVL_LAYER_ADDR_OFFSET]
#define REG_GOVL_LAYER_PITCH(n)                               GOVL_hw_registers[21  + (n) * GOVL_LAYER_ADDR_OFFSET]
#define REG_GOVL_LAYER_OFFSET(n)                              GOVL_hw_registers[22  + (n) * GOVL_LAYER_ADDR_OFFSET]
#define REG_GOVL_LAYER_SIZE(n)                                GOVL_hw_registers[23  + (n) * GOVL_LAYER_ADDR_OFFSET]
#define REG_GOVL_LAYER_SRC_KEY(n)                             GOVL_hw_registers[24  + (n) * GOVL_LAYER_ADDR_OFFSET]
#define REG_GOVL_LAYER_RECTANGLE_FILL_COLOR(n)                GOVL_hw_registers[24  + (n) * GOVL_LAYER_ADDR_OFFSET]
#define REG_GOVL_LAYER_FONT_FOREGROUND_COLOR(n)               GOVL_hw_registers[24  + (n) * GOVL_LAYER_ADDR_OFFSET]

#endif  // #if defined(__MTK_TARGET__)

/// bit mapping of graphic 2D engine IRQ register
#define GOVL_START_BIT                                           0x00000001

/// GOVL_ENG_MODE,2D engine function mode
#define GOVL_MODE_CON_ENG_MODE_GOVL_BITBLT_BIT                   0x0001

/// bit mapping of graphic 2D engine IRQ register
#define GOVL_IRQ_ENABLE_BIT                                      0x00000001
#define GOVL_IRQ_STATUS_BIT                                      0x00010000


/// bit mapping of 2D engine common control register
#define GOVL_RESET_WARM_RESET_BIT                                0x0001
#define GOVL_RESET_HARD_RESET_BIT                                0x0002

/// bit mapping of graphic 2D engine status register
#define GOVL_STATUS_BUSY_BIT                                     0x00000001
#define GOVL_STATUS_TBUSY_BIT                                    0x00000002

#define GOVL_READ_BURST_TYPE_MASK                                0x03000000
#define GOVL_WRITE_BURST_TYPE_MASK                               0x00700000


#define GOVL_SLOW_DOWN_COUNT_MASK                                0x0000FFFF
#define GOVL_SLOW_DOWN_ENABLE_BIT                                0x80000000

#define GOVL_CACHE_CON_MAX_OUTSTANDING_MASK                      0x00F0


#define GOVL_ROI_CON_REPLACEMENT_ENABLE_BIT                      0x00200000       /// CLR_REP_EN
#define GOVL_ROI_CON_CLIP_ENABLE_BIT                             0x10000
#define GOVL_ROI_CON_DISABLE_BG_BIT                              0x80000
#define GOVL_ROI_CON_ENABLE_LAYER0_BIT                           0x80000000
#define GOVL_ROI_CON_ENABLE_LAYER1_BIT                           0x40000000
#define GOVL_ROI_CON_ENABLE_LAYER2_BIT                           0x20000000
#define GOVL_ROI_CON_ENABLE_LAYER3_BIT                           0x10000000
#define GOVL_ROI_CON_ENABLE_LAYER_MASK                           0xF0000000
#define GOVL_ROI_CON_CONSTANT_ALPHA_MASK                         0xFF00
#define GOVL_ROI_CON_ALPHA_ENABLE_BIT                            0x80
#define GOVL_ROI_CON_ENABLE_FORCE_TS_BIT                         0x20000

/// DST_CLR_MODE,destination color mode
#define GOVL_ROI_CON_W2M_COLOR_RGB565                            0x01
#define GOVL_ROI_CON_W2M_COLOR_RGB888                            0x03
#define GOVL_ROI_CON_W2M_COLOR_BGR888                            0x13 //0x0B 

#define GOVL_ROI_CON_W2M_COLOR_ARGB8888                          0x08 //0x04
#define GOVL_ROI_CON_W2M_COLOR_ARGB8565                          0x09
#define GOVL_ROI_CON_W2M_COLOR_ARGB6666                          0x0A

#define GOVL_ROI_CON_W2M_COLOR_PARGB8888                         0x0C //0x05
#define GOVL_ROI_CON_W2M_COLOR_PARGB8565                         0x0D
#define GOVL_ROI_CON_W2M_COLOR_PARGB6666                         0x0E
#define GOVL_ROI_CON_W2M_COLOR_MASK                              0x1F //0x0F

// TODO: [i] LX: Layer X
#define GOVL_LX_CON_ENABLE_SRC_KEY_BIT                           0x00800000
#define GOVL_LX_CON_ENABLE_RECT_BIT                              0x00400000
#define GOVL_LX_CON_ENABLE_FONT_BIT                              0x40000000
#define GOVL_LX_CON_AA_FONT_BIT_MASK                             0x30000000

#define GOVL_LX_CON_COLOR_UYVY                                   0x02 // This is not supported in output color format...

#define GOVL_LX_CON_COLOR_RGB565                                 0x01
#define GOVL_LX_CON_COLOR_RGB888                                 0x03
#define GOVL_LX_CON_COLOR_BGR888                                 0x13 //0x0B

#define GOVL_LX_CON_COLOR_ARGB8888                               0x08 //0x04
#define GOVL_LX_CON_COLOR_ARGB8565                               0x09
#define GOVL_LX_CON_COLOR_ARGB6666                               0x0A

#define GOVL_LX_CON_COLOR_PARGB8888                              0x0C //0x05
#define GOVL_LX_CON_COLOR_PARGB8565                              0x0D
#define GOVL_LX_CON_COLOR_PARGB6666                              0x0E
#define GOVL_LX_CON_COLOR_MASK                                   0x1F //0x0F

#define GOVL_LX_CON_CONSTANT_ALPHA_MASK                          0xFF00
#define GOVL_LX_CON_ALPHA_ENABLE_BIT                             0x80
#define GOVL_LX_CON_CCW_ROTATE_MASK                              0x70000
#define GOVL_LX_CON_CCW_ROTATE_000                               0x00000
#define GOVL_LX_CON_CCW_ROTATE_MIRROR_090                        0x10000
#define GOVL_LX_CON_CCW_ROTATE_MIRROR_000                        0x20000
#define GOVL_LX_CON_CCW_ROTATE_090                               0x30000
#define GOVL_LX_CON_CCW_ROTATE_MIRROR_180                        0x40000
#define GOVL_LX_CON_CCW_ROTATE_270                               0x50000
#define GOVL_LX_CON_CCW_ROTATE_180                               0x60000
#define GOVL_LX_CON_CCW_ROTATE_MIRROR_270                        0x70000

/**
 *  \def WARM_RESET_GOVL_ENGINE()
 *  \remark This macro might result in infinite loop if any problem in HW.
 */
#define WARM_RESET_GOVL_ENGINE() \
  do { \
    REG_GOVL_RESET = GOVL_RESET_WARM_RESET_BIT ; \
    while(REG_GOVL_STATUS & GOVL_STATUS_BUSY_BIT){} \
    REG_GOVL_RESET = GOVL_RESET_HARD_RESET_BIT ; \
    REG_GOVL_RESET = 0; \
  } while(0)

/**
 *  \def HARD_RESET_GOVL_ENGINE()
 *  \remark Possible bus hang
 */
#define HARD_RESET_GOVL_ENGINE() \
  do { \
    REG_GOVL_RESET = 0; \
    REG_GOVL_RESET = GOVL_RESET_HARD_RESET_BIT; \
    REG_GOVL_RESET = 0; \
  } while(0)

/// W2M
#define SET_GOVL_W2M_ADDR(addr) \
  do { REG_GOVL_W2M_ADDR = (addr); } while(0)

#define SET_GOVL_W2M_PITCH(pitch) \
  do { REG_GOVL_W2M_PITCH = (pitch); } while(0)

#define SET_GOVL_W2M_OFFSET(x, y) \
  do { \
    REG_GOVL_W2M_OFFSET = (((kal_int16)(x) & 0xFFFF)<< 16) | ((kal_int16)(y) & 0xFFFF); \
  } while(0)

/**
 *  \def SET_GOVL_W2M_COLOR_FORMAT
 *  \param format Should be one of GOVL_ROI_CON_W2M_COLOR_*
 */
#define SET_GOVL_W2M_COLOR_FORMAT(format) \
  do { \
    REG_GOVL_ROI_CON = (((format) & GOVL_ROI_CON_W2M_COLOR_MASK) | (REG_GOVL_ROI_CON & (~GOVL_ROI_CON_W2M_COLOR_MASK))); \
  } while(0)

/// ROI
#define DISABLE_GOVL_ROI_ALL_LAYER() \
  do { REG_GOVL_ROI_CON &= ~GOVL_ROI_CON_ENABLE_LAYER_MASK; } while(0)

/**
 *  \def ENABLE_GOVL_ROI_LAYER
 *  \param layer [0, 3]
 */
#define ENABLE_GOVL_ROI_LAYER(layer) \
  do { REG_GOVL_ROI_CON |= (1 << (31 - (layer))); } while(0)

#define GET_ENABLED_GOVL_ROI_LAYER() ((REG_GOVL_ROI_CON >> 28) & 0xF)

#define DISABLE_GOVL_ROI_CON_BG() \
  do { REG_GOVL_ROI_CON |= GOVL_ROI_CON_DISABLE_BG_BIT; } while(0)

#define SET_GOVL_ROI_CON_BG_COLOR(color) \
  do { REG_GOVL_ROI_BGCLR = (color); } while(0)

#define ENABLE_GOVL_ROI_CON_ALPHA() \
  do { REG_GOVL_ROI_CON |= GOVL_ROI_CON_ALPHA_ENABLE_BIT; } while(0)

#define SET_GOVL_ROI_CON_ALPHA(alpha) \
  do { \
    REG_GOVL_ROI_CON = ((((alpha) << 8) & GOVL_ROI_CON_CONSTANT_ALPHA_MASK) | (REG_GOVL_ROI_CON & (~GOVL_ROI_CON_CONSTANT_ALPHA_MASK))); \
  } while(0)
#define GOVL_WMEM_CTRL_ALPHA_MAX	      0xFF
#define GOVL_WMEM_CTRL_ALPHA_OFFSET    8   

#define SET_GOVL_ROI_OFFSET(x, y) \
  do { REG_GOVL_ROI_OFFSET = (((x) << 16) | (0xFFFF & (y))); } while(0)

#define SET_GOVL_ROI_SIZE(w, h) \
  do { REG_GOVL_ROI_SIZE = (((w) << 16) | (h)); } while(0)

#define GET_GOVL_ROI_SIZE_WIDTH() ((REG_GOVL_ROI_SIZE >> 16) & 0xFFFF)
#define GET_GOVL_ROI_SIZE_HEIGHT() ((REG_GOVL_ROI_SIZE) & 0xFFFF)


/// CACHE
#define SET_REG_GOVL_CACHE_CON_MAX_OUTSTANDING_NUM(n) \
  do { \
    REG_GOVL_CACHE_CON = ((((n) << 4) & GOVL_CACHE_CON_MAX_OUTSTANDING_MASK) | (REG_GOVL_CACHE_CON & (~GOVL_CACHE_CON_MAX_OUTSTANDING_MASK))); \
  } while(0)

/// Layer
#define CLR_GOVL_LAYER_CON(n) \
  do { REG_GOVL_LAYER_CON(n) = 0; } while(0)

#define SET_GOVL_LAYER_CON_COLOR_FORMAT(n, format) \
  do { \
    REG_GOVL_LAYER_CON(n) = (((format) & GOVL_LX_CON_COLOR_MASK) | (REG_GOVL_LAYER_CON(n) & (~GOVL_LX_CON_COLOR_MASK))); \
  } while(0)

#define GOVL_LAYER_CTRL_FORMAT_OFFSET        0

#define SET_GOVL_LAYER_CON_ALPHA(n, alpha) \
  do { \
    REG_GOVL_LAYER_CON(n) = ((((alpha) << 8) & GOVL_LX_CON_CONSTANT_ALPHA_MASK) | (REG_GOVL_LAYER_CON(n) & (~GOVL_LX_CON_CONSTANT_ALPHA_MASK))); \
  } while(0)

#define ENABLE_GOVL_LAYER_CON_ALPHA(n) \
  do { REG_GOVL_LAYER_CON(n) |= GOVL_LX_CON_ALPHA_ENABLE_BIT; } while(0)
#define GOVL_LAYER_CTRL_OPACITY_ENABLE_BIT          GOVL_LX_CON_ALPHA_ENABLE_BIT

#define DISABLE_GOVL_LAYER_CON_ALPHA(n) \
  do { REG_GOVL_LAYER_CON(n) &= ~GOVL_LX_CON_ALPHA_ENABLE_BIT; } while(0)

#define ENABLE_GOVL_LAYER_CON_RECT_FILL(n) \
  do { REG_GOVL_LAYER_CON(n) |= GOVL_LX_CON_ENABLE_RECT_BIT; } while(0)

#define DISABLE_GOVL_LAYER_CON_RECT_FILL(n) \
  do { REG_GOVL_LAYER_CON(n) &= ~GOVL_LX_CON_ENABLE_RECT_BIT; } while(0)

#define ENABLE_GOVL_LAYER_CON_FONT(n) \
  do { REG_GOVL_LAYER_CON(n) |= GOVL_LX_CON_ENABLE_FONT_BIT; } while(0)

// TODO: [i] not in use
#define SET_GOVL_LAYER_CON_AA_FONT_BIT(n, bit) \
  do { \
    REG_GOVL_LAYER_CON(n) &= ~GOVL_LX_CON_AA_FONT_BIT_MASK; \
    REG_GOVL_LAYER_CON(n) |= (bit); \
  } while(0)

#define ENABLE_GOVL_LAYER_CON_SRC_KEY(n) \
  do { REG_GOVL_LAYER_CON(n) |= GOVL_LX_CON_ENABLE_SRC_KEY_BIT; } while(0)
#define GOVL_LAYER_CTRL_SOURCE_KEY_ENABLE_BIT       GOVL_LX_CON_ENABLE_SRC_KEY_BIT

#define DISABLE_GOVL_LAYER_CON_SRC_KEY(n) \
  do { REG_GOVL_LAYER_CON(n) &= ~GOVL_LX_CON_ENABLE_SRC_KEY_BIT; } while(0)

/**
 *  \def SET_GOVL_LAYER_CON_ROTATE
 *  \param n Layer n [0, 3]
 *  \param rot one of GOVL_LX_CON_CCW_* or 
 */
#define GOVL_LAYER_CTRL_ROTATE_OFFSET               16
#define SET_GOVL_LAYER_CON_ROTATE(n, rot) \
  do { \
    REG_GOVL_LAYER_CON(n) = ((rot) | (REG_GOVL_LAYER_CON(n) & (~GOVL_LX_CON_CCW_ROTATE_MASK))); \
  } while(0)

#define GET_GOVL_LAYER_CON_ROTATE(layer_n) ((REG_GOVL_LAYER_CON(layer_n) & GOVL_LX_CON_CCW_ROTATE_MASK) >> GOVL_LAYER_CTRL_ROTATE_OFFSET)

#define SET_GOVL_LAYER_ADDR(n, addr) \
  do { REG_GOVL_LAYER_ADDR(n) = (addr); } while(0)

#define SET_GOVL_LAYER_PITCH(n, pitch) \
  do { REG_GOVL_LAYER_PITCH(n) = (pitch); } while(0)

#define SET_GOVL_LAYER_OFFSET(n, x, y) \
  do { REG_GOVL_LAYER_OFFSET(n) = (((x) << 16) | (0xFFFF & (y))); } while(0)

#define SET_GOVL_LAYER_SIZE(n, w, h) \
  do { REG_GOVL_LAYER_SIZE(n) = (((w) << 16) | (h)); } while(0)

#define SET_GOVL_LAYER_SRC_KEY(n, color) \
  do { REG_GOVL_LAYER_SRC_KEY(n) = (color); } while(0)

#define SET_GOVL_LAYER_RECTANGLE_FILL_COLOR(n, color) \
  do { REG_GOVL_LAYER_RECTANGLE_FILL_COLOR(n) = (color); } while(0)

#define SET_GOVL_LAYER_FONT_FOREGROUND_COLOR(n, color) \
  do { REG_GOVL_LAYER_FONT_FOREGROUND_COLOR(n) = color; } while(0)

/******************************************************************************
 * The following macros are to align MT6236 GOVL
 ******************************************************************************/
/*----------------------- GOVL INT -------------------------------------------*/
#define ENABLE_GOVL_TRANSFER_COMPLETE_INT \
  do { REG_GOVL_IRQ |= GOVL_IRQ_ENABLE_BIT; } while(0)
  
#define DISABLE_GOVL_TRANSFER_COMPLETE_INT \
  do { REG_GOVL_IRQ &= ~GOVL_IRQ_ENABLE_BIT; } while(0)

#define GOVL_CLEAR_INT_STATUS \
  do { REG_GOVL_IRQ &= ~GOVL_IRQ_STATUS_BIT; } while(0)

/*----------------------- GOVL START -----------------------------------------*/
#define GOVL_IS_RUNNING \
  ((REG_GOVL_STATUS & (GOVL_STATUS_BUSY_BIT|GOVL_STATUS_TBUSY_BIT))!=0x0)

#define START_GOVL_TRANSFER \
  do { \
    REG_GOVL_START = 0; \
    REG_GOVL_START = GOVL_START_BIT; \
  } while (0)
  
#define G2D_ENG_MODE_MASK 0x7
#define G2D_BITBLT_MODE 0x1
#define SET_GOVL_MODE \
  do { \
	REG_GOVL_MODE_CTRL &= ~G2D_ENG_MODE_MASK; \
	REG_GOVL_MODE_CTRL = G2D_BITBLT_MODE; \
  } while (0)


// TODO: [m] Double confirm this!!
#define STOP_GOVL_TRANSFER do { REG_GOVL_START = 0; } while(0)

/*----------------------- GOVL W2MEM -----------------------------------------*/
// TODO: [m] Not in use, remove?
/**
 *  \def SET_GOVL_ENABLE_LAYER
 *  \param n The HW bit mask of layer enable bit, which makes this macro chip-dependent and useless.
 */
#define SET_GOVL_ENABLE_LAYER(n) ASSERT(0)

#if 0   // From govl_if_6236_hw.h, the following are not in use...
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

// TODO: [i] Since this macro is not in use, we don't adapt it to MT6276 GOVL...
/** 
 *  \def SET_GOVL_WMEM_FORMAT
 *  \param format one of GOVL_WMEM_COLOR_FORMAT_ENUM 
 */
#define SET_GOVL_WMEM_FORMAT(format) SET_GOVL_W2M_COLOR_FORMAT(format)
//  do { \
//    REG_GOVL_WMEM_CTRL &= ~GOVL_WMEM_CTRL_COLOR_FORMAT_MASK; \
//    REG_GOVL_WMEM_CTRL |= format; \
//  } while (0)

#define SET_GOVL_WMEM_ALPHA_VAL(alpha_val)  SET_GOVL_ROI_CON_ALPHA(alpha_val)

// TODO: [i] Not supported by MT6276 GOVL
#define SET_GOVL_WMEM_DC_OUT(dc_flag) 

// TODO: [i] Not in use

#define SET_GOVL_WMEM_PITCH(width)          SET_GOVL_W2M_PITCH(width)
#define SET_GOVL_WMEM_OFFSET(x, y)          SET_GOVL_W2M_OFFSET(x, y)
#define SET_GOVL_WMEM_ADDR(addr)            SET_GOVL_W2M_ADDR(addr)
#define SET_GOVL_WMEM_COLOR_FORMAT(format)  SET_GOVL_W2M_COLOR_FORMAT(format)
/*------------------------ GOVL ROI Macro ------------------------------------*/
// TODO: [i] already defined
//#define SET_GOVL_ROI_OFFSET(x, y)
// TODO: [i] already defined
//#define SET_GOVL_ROI_SIZE(column, row)
#define SET_GOVL_ROI_BK_COLOR(color)        SET_GOVL_ROI_CON_BG_COLOR(color)

/*----------------------- LCD LAYER Macro ------------------------------------*/
// TODO: [i] n in [0, 3]. 0 is the lowest layer.
#define REG_GOVL_LAYER_CTRL(n)                       REG_GOVL_LAYER_CON(n)
#define REG_GOVL_LAYER_COLOR_KEY(n)                  REG_GOVL_LAYER_SRC_KEY(n)
//#define REG_GOVL_LAYER_OFFSET(n)                     REG_GOVL_LAYER_OFFSET(n) // Already defined above
#define REG_GOVL_LAYER_BUFF_ADDR(n)                  REG_GOVL_LAYER_ADDR(n)
//#define REG_GOVL_LAYER_SIZE(n)                       REG_GOVL_LAYER_SIZE(n) // Already defined above
//#define REG_GOVL_LAYER_SCROLL_OFFSET(n) // Not in use
#define REG_GOVL_LAYER_MEM_OFFSET(n)                 REG_GOVL_LAYER_OFFSET(n)
#define REG_GOVL_LAYER_MEM_PITCH(n)                  REG_GOVL_LAYER_PITCH(n)

#define SET_GOVL_LAYER_SOURCE_KEY(layer_index, color) \
  SET_GOVL_LAYER_SRC_KEY(layer_index, color)

#define SET_GOVL_LAYER_WINDOW_OFFSET(layer_index, x, y) \
  SET_GOVL_LAYER_OFFSET(layer_index, x, y)

#define SET_GOVL_LAYER_WINDOW_SIZE(layer_index, width, height) \
  SET_GOVL_LAYER_SIZE(layer_index, width, height)

#define SET_GOVL_LAYER_WINDOW_WMEM_OFFSET(layer_index, x, y) \
  SET_GOVL_LAYER_OFFSET(layer_index, x, y)

// TODO: This width should be pitch in MT6276...the unit is byte not pixel
#define SET_GOVL_LAYER_WINDOW_WMEM_PITCH(layer_index, width) \
  SET_GOVL_LAYER_PITCH(layer_index, width)
  
#define GET_GOVL_LAYER_WINDOW_WIDTH(layer_index) \
  ((kal_uint16)((REG_GOVL_LAYER_SIZE(layer_index)>>16) & 0xFFFF))

#define GET_GOVL_LAYER_WINDOW_HEIGHT(layer_index) \
  ((kal_uint16)(REG_GOVL_LAYER_SIZE(layer_index) & 0xFFFF))

#define SET_GOVL_LAYER_WMEM_OFFSET(layer_index, x, y)  SET_GOVL_LAYER_WINDOW_WMEM_OFFSET(layer_index, x, y)
  
// TODO: rot value is a 8 bit and exactly the same as defined in MT6236 GOVL
// TODO: not in use so make it empty first
#define GET_GOVL_LAYER_ROTATE(layer_index)

// TODO: not in use so make it empty first
#define SET_GOVL_LAYER_ROTATE(layer_index, n)

// TODO: the color format is chip-dependent...
// TODO: not in use so make it empty first
#define GET_GOVL_LAYER_COLOR_FORMAT(layer_index)

// TODO: chip depedent...
typedef enum
{
   GOVL_BURST_SINGLE = 0,
   GOVL_BURST_4BEATS_2BYTES,		
   GOVL_BURST_4BEATS_4BYTES,
   GOVL_BURST_8BEATS_4BYTES,
   GOVL_BURST_16BEATS_4BYTES
} GOVL_BURST_TYPE_ENUM;

// TODO: chip depedent...
#define GOVL_GMC_BURST_TYPE_MASK 0x7

// TODO: chip depedent...Not in use
#define SET_GOVL_BURST_TYPE(burst_type)

#define GOVL_ROI_WMEM_OFFSETX_OFFSET            0
#define GOVL_ROI_WMEM_OFFSETY_OFFSET            16

//Not support
#define GOVL_LAYER_CTRL_DATA_SWAP_BIT           0

#define REG_GOVL_INT_ENABLE        REG_GOVL_IRQ
#define REG_GOVL_INT_STATUS        REG_GOVL_STATUS
#define GOVL_LAYER_ALPHA_VAL_OFFSET                 8
#define SET_GOVL_LAYER_CON_REG(layer_index, val)   REG_GOVL_LAYER_CTRL(layer_index) = val
#define SET_GOVL_WMEM_CON(val) REG_GOVL_ROI_CON = val


//#endif  // #if defined(MT6276_S01)

#endif  // __GOVL_IF_6260_HW_H__

