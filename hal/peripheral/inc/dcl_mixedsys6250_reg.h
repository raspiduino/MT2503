/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *	dcl_mixedsysxxxx_reg.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for mixed sys registers' definitions.
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
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "dcl_pmu6250_hw.h"

/* The definition of register's offset */

#define CON0_MIXED_OFFSET           				0x00

#define CON1_MIXED_OFFSET           				0x04

#define CON2_MIXED_OFFSET           				0x08

#define CON3_MIXED_OFFSET           				0x0C

#define CON4_MIXED_OFFSET           				0x10

#define CON5_MIXED_OFFSET           				0x14

#define CON6_MIXED_OFFSET           				0x18

#define CON7_MIXED_OFFSET           				0x1C

#define CON8_MIXED_OFFSET           				0x20

#define CON9_MIXED_OFFSET           				0x24

#define CON10_MIXED_OFFSET           				0x28
#define CONA_MIXED_OFFSET           				0x28

#define CON11_MIXED_OFFSET           				0x2C
#define CONB_MIXED_OFFSET           				0x2C

#define CON12_MIXED_OFFSET           				0x30
#define CONC_MIXED_OFFSET           				0x30

#define CON13_MIXED_OFFSET           				0x34
#define COND_MIXED_OFFSET           				0x34

#define CON14_MIXED_OFFSET           				0x38
#define CONE_MIXED_OFFSET           				0x38

#define CON15_MIXED_OFFSET           				0x3C
#define CONF_MIXED_OFFSET           				0x3C

/* Base Address of Registers */

#define WR_PATH_CON             (MIXED_BASE_ADDR + 0x0000)

#define AFUNC_DIN_CON           (MIXED_BASE_ADDR + 0x0004)

#define AFUNC_XOSC_CON          (MIXED_BASE_ADDR + 0x0010)

#define AFUNC_RTC_CON           (MIXED_BASE_ADDR + 0x0014)

#define ABIST_CON0              (MIXED_BASE_ADDR + 0x0020)

#define ABIST_CON1              (MIXED_BASE_ADDR + 0x0024)

#define ABIST_CON2              (MIXED_BASE_ADDR + 0x0028)

#define ABIST_CON3              (MIXED_BASE_ADDR + 0x002C)

#define APB_CON0                (MIXED_BASE_ADDR + 0x0050)

#define APB_CON1                (MIXED_BASE_ADDR + 0x0054)

#define LDO_CON0                (MIXED_BASE_ADDR + 0x00C0)

#define LDO_CON1                (MIXED_BASE_ADDR + 0x00C4)

#define LDO_CON2                (MIXED_BASE_ADDR + 0x00C8)

#define VRF_CON0                (MIXED_BASE_ADDR + 0x0100)

#define VRF_CON1                (MIXED_BASE_ADDR + 0x0104)

#define VRF_CON2                (MIXED_BASE_ADDR + 0x0108)

#define VTCXO_CON0              (MIXED_BASE_ADDR + 0x0110)

#define VTCXO_CON1              (MIXED_BASE_ADDR + 0x0114)

#define VTCXO_CON2              (MIXED_BASE_ADDR + 0x0118)

#define VA_CON0                 (MIXED_BASE_ADDR + 0x0120)

#define VA_CON1                 (MIXED_BASE_ADDR + 0x0124)

#define VA_CON2                 (MIXED_BASE_ADDR + 0x0128)

#define VCAMA_CON0              (MIXED_BASE_ADDR + 0x0130)

#define VCAMA_CON1              (MIXED_BASE_ADDR + 0x0134)

#define VCAMA_CON2              (MIXED_BASE_ADDR + 0x0138)

#define VCAMD_CON0              (MIXED_BASE_ADDR + 0x0140)

#define VCAMD_CON1              (MIXED_BASE_ADDR + 0x0144)

#define VCAMD_CON2              (MIXED_BASE_ADDR + 0x0148)

#define VIO28_CON0              (MIXED_BASE_ADDR + 0x0150)

#define VIO28_CON1              (MIXED_BASE_ADDR + 0x0154)

#define VIO28_CON2              (MIXED_BASE_ADDR + 0x0158)

#define VUSB_CON0               (MIXED_BASE_ADDR + 0x0160)

#define VUSB_CON1               (MIXED_BASE_ADDR + 0x0164)

#define VUSB_CON2               (MIXED_BASE_ADDR + 0x0168)

#define VBT_CON0                (MIXED_BASE_ADDR + 0x0170)

#define VBT_CON1                (MIXED_BASE_ADDR + 0x0174)

#define VBT_CON2                (MIXED_BASE_ADDR + 0x0178)

#define VSIM1_CON0              (MIXED_BASE_ADDR + 0x0180)

#define VSIM1_CON1              (MIXED_BASE_ADDR + 0x0184)

#define VSIM1_CON2              (MIXED_BASE_ADDR + 0x0188)

#define VSIM2_CON0              (MIXED_BASE_ADDR + 0x0190)

#define VSIM2_CON1              (MIXED_BASE_ADDR + 0x0194)

#define VSIM2_CON2              (MIXED_BASE_ADDR + 0x0198)

#define VRTC_CON0               (MIXED_BASE_ADDR + 0x01A0)

#define VRTC_CON1               (MIXED_BASE_ADDR + 0x01A4)

#define VRTC_CON2               (MIXED_BASE_ADDR + 0x01A8)

#define VIBR_CON0               (MIXED_BASE_ADDR + 0x01B0)

#define VIBR_CON1               (MIXED_BASE_ADDR + 0x01B4)

#define VIBR_CON2               (MIXED_BASE_ADDR + 0x01B8)

#define VMC_CON0                (MIXED_BASE_ADDR + 0x01C0)

#define VMC_CON1                (MIXED_BASE_ADDR + 0x01C4)

#define VMC_CON2                (MIXED_BASE_ADDR + 0x01C8)

#define VSF_CON0                (MIXED_BASE_ADDR + 0x01D0)

#define VSF_CON1                (MIXED_BASE_ADDR + 0x01D4)

#define VSF_CON2                (MIXED_BASE_ADDR + 0x01D8)

#define VSF_CON3                (MIXED_BASE_ADDR + 0x01DC)

#define VIO18_CON0              (MIXED_BASE_ADDR + 0x0200)

#define VIO18_CON1              (MIXED_BASE_ADDR + 0x0204)

#define VIO18_CON2              (MIXED_BASE_ADDR + 0x0208)

#define VCORE_CON0              (MIXED_BASE_ADDR + 0x0230)

#define VCORE_CON2              (MIXED_BASE_ADDR + 0x0238)

#define VCORE_CON3              (MIXED_BASE_ADDR + 0x023C)

#define OC_CON0                 (MIXED_BASE_ADDR + 0x0E00)

#define OC_CON1                 (MIXED_BASE_ADDR + 0x0E04)

#define OC_CON3                 (MIXED_BASE_ADDR + 0x0E0C)

#define OC_CON4                 (MIXED_BASE_ADDR + 0x0E10)

#define OC_CON5                 (MIXED_BASE_ADDR + 0x0E14)

#define OC_CON7                 (MIXED_BASE_ADDR + 0x0E1C)

#define OC_CON8                 (MIXED_BASE_ADDR + 0x0E20)

#define OC_CON9                 (MIXED_BASE_ADDR + 0x0E24)

#define OC_CON11                (MIXED_BASE_ADDR + 0x0E2C)

#define CHR_CON0                (MIXED_BASE_ADDR + 0x0A00)

#define CHR_CON1                (MIXED_BASE_ADDR + 0x0A04)

#define CHR_CON2                (MIXED_BASE_ADDR + 0x0A08)

#define CHR_CON3                (MIXED_BASE_ADDR + 0x0A0C)

#define CHR_CON4                (MIXED_BASE_ADDR + 0x0A10)

#define CHR_CON5                (MIXED_BASE_ADDR + 0x0A14)

#define CHR_CON6                (MIXED_BASE_ADDR + 0x0A18)

#define CHR_CON7                (MIXED_BASE_ADDR + 0x0A1C)

#define CHR_CON8                (MIXED_BASE_ADDR + 0x0A20)

#define CHR_CON9                (MIXED_BASE_ADDR + 0x0A24)

#define CHR_CON10               (MIXED_BASE_ADDR + 0x0A28)

#define CHR_CON11               (MIXED_BASE_ADDR + 0x0A2C)

#define CHR_CON12               (MIXED_BASE_ADDR + 0x0A30)

#define CHR_CON13               (MIXED_BASE_ADDR + 0x0A34)

#define CHR_CON14               (MIXED_BASE_ADDR + 0x0A38)

#define CHR_CON15               (MIXED_BASE_ADDR + 0x0A3C)

#define STRUP_CON0              (MIXED_BASE_ADDR + 0x0A80)

#define STRUP_CON1              (MIXED_BASE_ADDR + 0x0A84)

#define STRUP_CON2              (MIXED_BASE_ADDR + 0x0A88)

#define STRUP_CON3              (MIXED_BASE_ADDR + 0x0A8C)

#define STRUP_CON4              (MIXED_BASE_ADDR + 0x0A90)

#define TEST_CON0               (MIXED_BASE_ADDR + 0x0F00)

#define TEST_CON1               (MIXED_BASE_ADDR + 0x0F04)

#define TEST_CON2               (MIXED_BASE_ADDR + 0x0F08)

#define TEST_CON3               (MIXED_BASE_ADDR + 0x0F0C)

#define BOOST_CON3              (MIXED_BASE_ADDR + 0x0B0C)

#define ISINKS_CON0             (MIXED_BASE_ADDR + 0x0C00)

#define ISINKS_CON1             (MIXED_BASE_ADDR + 0x0C04)

#define ISINKS_CON2             (MIXED_BASE_ADDR + 0x0C08)

#define ISINK0_CON0             (MIXED_BASE_ADDR + 0x0C10)

#define ISINK1_CON0             (MIXED_BASE_ADDR + 0x0C20)

#define ISINK2_CON0             (MIXED_BASE_ADDR + 0x0C30)

#define ISINK3_CON0             (MIXED_BASE_ADDR + 0x0C40)

#define KPLED_CON0              (MIXED_BASE_ADDR + 0x0C80)

#define SPK_CON0                (MIXED_BASE_ADDR + 0x0D00)

#define SPK_CON3                (MIXED_BASE_ADDR + 0x0D0C)

#define SPK_CON6                (MIXED_BASE_ADDR + 0x0D18)

#define SPK_CON7                (MIXED_BASE_ADDR + 0x0D1C)

#define SPK_CON8                (MIXED_BASE_ADDR + 0x0D20)

#define RSV_CON0                (MIXED_BASE_ADDR + 0x0F80)

#define RSV_CON1                (MIXED_BASE_ADDR + 0x0F84)

#define RSV_CON2                (MIXED_BASE_ADDR + 0x0F88)

#define RSV_CON3                (MIXED_BASE_ADDR + 0x0F8C)

#define RSV_CON4                (MIXED_BASE_ADDR + 0x0F90)

#define RSV_CON5                (MIXED_BASE_ADDR + 0x0F94)

#define DCXO_PCON0              (MIXED_BASE_ADDR + 0x0FE0)

#define DCXO_PCON1              (MIXED_BASE_ADDR + 0x0FE4)

#define DCXO_PCON2              (MIXED_BASE_ADDR + 0x0FE8)

#define DCXO_PCON3              (MIXED_BASE_ADDR + 0x0FEC)

#define FQMTR_CON0              (MIXED_BASE_ADDR + 0x0FF0)

#define FQMTR_CON1              (MIXED_BASE_ADDR + 0x0FF4)

#define FQMTR_CON2              (MIXED_BASE_ADDR + 0x0FF8)

#define FQMTR_CON3              (MIXED_BASE_ADDR + 0x0FFC)


/* Offset, Mask, Shift of Registers */

#define CCI_SEL_26M_OFFSET                          CON0_MIXED_OFFSET
#define CCI_SEL_26M_MASK                            0x0020
#define CCI_SEL_26M_SHIFT                           5

#define CCI_PRST_MODE_OFFSET                        CON0_MIXED_OFFSET
#define CCI_PRST_MODE_MASK                          0x0004
#define CCI_PRST_MODE_SHIFT                         2

#define CCI_ABIST_MODE_OFFSET                       CON0_MIXED_OFFSET
#define CCI_ABIST_MODE_MASK                         0x0002
#define CCI_ABIST_MODE_SHIFT                        1

#define CCI_ACD_MODE_OFFSET                         CON0_MIXED_OFFSET
#define CCI_ACD_MODE_MASK                           0x0001
#define CCI_ACD_MODE_SHIFT                          0

#define A_FUNC_DOE_OFFSET                           CON0_MIXED_OFFSET
#define A_FUNC_DOE_MASK                             0x00FF
#define A_FUNC_DOE_SHIFT                            0

#define XOSC_LPDTB_OFFSET                           CON0_MIXED_OFFSET
#define XOSC_LPDTB_MASK                             0x8000
#define XOSC_LPDTB_SHIFT                            15

#define XOSC_CPDTB_OFFSET                           CON0_MIXED_OFFSET
#define XOSC_CPDTB_MASK                             0x4000
#define XOSC_CPDTB_SHIFT                            14

#define A_FUNC_DDLO_VRTC_EN_OFFSET                  CON0_MIXED_OFFSET
#define A_FUNC_DDLO_VRTC_EN_MASK                    0x0800
#define A_FUNC_DDLO_VRTC_EN_SHIFT                   11

#define A_FUNC_DDLO_VRTC_OFFSET                     CON0_MIXED_OFFSET
#define A_FUNC_DDLO_VRTC_MASK                       0x0400
#define A_FUNC_DDLO_VRTC_SHIFT                      10

#define A_FUNC_XOSC_LPDRST_OFFSET                   CON0_MIXED_OFFSET
#define A_FUNC_XOSC_LPDRST_MASK                     0x0200
#define A_FUNC_XOSC_LPDRST_SHIFT                    9

#define A_FUNC_XOSC_LPDEN_OFFSET                    CON0_MIXED_OFFSET
#define A_FUNC_XOSC_LPDEN_MASK                      0x0100
#define A_FUNC_XOSC_LPDEN_SHIFT                     8

#define A_FUNC_XOSC_PWDB_OFFSET                     CON0_MIXED_OFFSET
#define A_FUNC_XOSC_PWDB_MASK                       0x0080
#define A_FUNC_XOSC_PWDB_SHIFT                      7

#define A_FUNC_XOSC_AMPSEL_OFFSET                   CON0_MIXED_OFFSET
#define A_FUNC_XOSC_AMPSEL_MASK                     0x0040
#define A_FUNC_XOSC_AMPSEL_SHIFT                    6

#define A_FUNC_XOSC_AMPEN_OFFSET                    CON0_MIXED_OFFSET
#define A_FUNC_XOSC_AMPEN_MASK                      0x0020
#define A_FUNC_XOSC_AMPEN_SHIFT                     5

#define A_FUNC_XOSC_CALI_OFFSET                     CON0_MIXED_OFFSET
#define A_FUNC_XOSC_CALI_MASK                       0x001F
#define A_FUNC_XOSC_CALI_SHIFT                      0

#define A_FUNC_32K_MON_SEL_OFFSET                   CON0_MIXED_OFFSET
#define A_FUNC_32K_MON_SEL_MASK                     0xC000
#define A_FUNC_32K_MON_SEL_SHIFT                    14

#define A_FUNC_XOSC32_ENB_OFFSET                    CON0_MIXED_OFFSET
#define A_FUNC_XOSC32_ENB_MASK                      0x0100
#define A_FUNC_XOSC32_ENB_SHIFT                     8

#define A_FUNC_TEST_DCXO_GLITCH_MODE_OFFSET         CON0_MIXED_OFFSET
#define A_FUNC_TEST_DCXO_GLITCH_MODE_MASK           0x0010
#define A_FUNC_TEST_DCXO_GLITCH_MODE_SHIFT          4

#define A_FUNC_EOSC32_STP_CHOP_EN_OFFSET            CON0_MIXED_OFFSET
#define A_FUNC_EOSC32_STP_CHOP_EN_MASK              0x0002
#define A_FUNC_EOSC32_STP_CHOP_EN_SHIFT             1

#define A_FUNC_DCXO_STP_LVSH_EN_OFFSET              CON0_MIXED_OFFSET
#define A_FUNC_DCXO_STP_LVSH_EN_MASK                0x0001
#define A_FUNC_DCXO_STP_LVSH_EN_SHIFT               0

#define ABIST_FINISH_OFFSET                         CON0_MIXED_OFFSET
#define ABIST_FINISH_MASK                           0x8000
#define ABIST_FINISH_SHIFT                          15

#define ABIST_PASS_OFFSET                           CON0_MIXED_OFFSET
#define ABIST_PASS_MASK                             0x4000
#define ABIST_PASS_SHIFT                            14

#define ABIST_MON_CFG_OFFSET                        CON0_MIXED_OFFSET
#define ABIST_MON_CFG_MASK                          0x0100
#define ABIST_MON_CFG_SHIFT                         8

#define ABIST_HMON_SEL_OFFSET                       CON1_MIXED_OFFSET
#define ABIST_HMON_SEL_MASK                         0xFF00
#define ABIST_HMON_SEL_SHIFT                        8

#define ABIST_LMON_SEL_OFFSET                       CON1_MIXED_OFFSET
#define ABIST_LMON_SEL_MASK                         0x00FF
#define ABIST_LMON_SEL_SHIFT                        0

#define ABIST_MON_CHG_OFFSET                        CON2_MIXED_OFFSET
#define ABIST_MON_CHG_MASK                          0x8000
#define ABIST_MON_CHG_SHIFT                         15

#define ABIST_HMON_OUT_OFFSET                       CON2_MIXED_OFFSET
#define ABIST_HMON_OUT_MASK                         0x00F0
#define ABIST_HMON_OUT_SHIFT                        4

#define ABIST_LMON_OUT_OFFSET                       CON2_MIXED_OFFSET
#define ABIST_LMON_OUT_MASK                         0x000F
#define ABIST_LMON_OUT_SHIFT                        0

#define ABIST_HMON_DATA_OFFSET                      CON3_MIXED_OFFSET
#define ABIST_HMON_DATA_MASK                        0x00F0
#define ABIST_HMON_DATA_SHIFT                       4

#define ABIST_LMON_DATA_OFFSET                      CON3_MIXED_OFFSET
#define ABIST_LMON_DATA_MASK                        0x000F
#define ABIST_LMON_DATA_SHIFT                       0

#define C2A_SIM2SEL_SEL_OFFSET                      CON1_MIXED_OFFSET
#define C2A_SIM2SEL_SEL_MASK                        0x2000
#define C2A_SIM2SEL_SEL_SHIFT                       13

#define CCI_C2A_SIM2SEL_OFFSET                      CON1_MIXED_OFFSET
#define CCI_C2A_SIM2SEL_MASK                        0x1000
#define CCI_C2A_SIM2SEL_SHIFT                       12

#define C2A_SIM1SEL_SEL_OFFSET                      CON1_MIXED_OFFSET
#define C2A_SIM1SEL_SEL_MASK                        0x0200
#define C2A_SIM1SEL_SEL_SHIFT                       9

#define CCI_C2A_SIM1SEL_OFFSET                      CON1_MIXED_OFFSET
#define CCI_C2A_SIM1SEL_MASK                        0x0100
#define CCI_C2A_SIM1SEL_SHIFT                       8

#define VCORE_SRCLKENA_SEL_OFFSET                   CON0_MIXED_OFFSET
#define VCORE_SRCLKENA_SEL_MASK                     0x0C00
#define VCORE_SRCLKENA_SEL_SHIFT                    10

#define VA_SRCLKENA_SEL_OFFSET                      CON0_MIXED_OFFSET
#define VA_SRCLKENA_SEL_MASK                        0x0300
#define VA_SRCLKENA_SEL_SHIFT                       8

#define VTCXO_SRCLKENA_SEL_OFFSET                   CON0_MIXED_OFFSET
#define VTCXO_SRCLKENA_SEL_MASK                     0x00C0
#define VTCXO_SRCLKENA_SEL_SHIFT                    6

#define VRF_SRCLKENA_SEL_OFFSET                     CON0_MIXED_OFFSET
#define VRF_SRCLKENA_SEL_MASK                       0x0030
#define VRF_SRCLKENA_SEL_SHIFT                      4

#define CCI_SRCLKEN_OFFSET                          CON0_MIXED_OFFSET
#define CCI_SRCLKEN_MASK                            0x0001
#define CCI_SRCLKEN_SHIFT                           0

#define RG_ALDOS_RESER_OFFSET                       CON1_MIXED_OFFSET
#define RG_ALDOS_RESER_MASK                         0x00FF
#define RG_ALDOS_RESER_SHIFT                        0

#define RG_DLDO_RSV_OFFSET                          CON2_MIXED_OFFSET
#define RG_DLDO_RSV_MASK                            0x00FF
#define RG_DLDO_RSV_SHIFT                           0

#define QI_VRF_STATUS_OFFSET                        CON0_MIXED_OFFSET
#define QI_VRF_STATUS_MASK                          0x8000
#define QI_VRF_STATUS_SHIFT                         15

#define VRF_OC_FLAG_OFFSET                          CON0_MIXED_OFFSET
#define VRF_OC_FLAG_MASK                            0x4000
#define VRF_OC_FLAG_SHIFT                           14

#define VRF_OC_AUTOFF_OFFSET                        CON0_MIXED_OFFSET
#define VRF_OC_AUTOFF_MASK                          0x1000
#define VRF_OC_AUTOFF_SHIFT                         12

#define RG_VRF_NDIS_EN_OFFSET                       CON0_MIXED_OFFSET
#define RG_VRF_NDIS_EN_MASK                         0x0400
#define RG_VRF_NDIS_EN_SHIFT                        10

#define RG_VRF_BIST_EN_OFFSET                       CON0_MIXED_OFFSET
#define RG_VRF_BIST_EN_MASK                         0x0008
#define RG_VRF_BIST_EN_SHIFT                        3

#define RG_VRF_RS_OFFSET                            CON0_MIXED_OFFSET
#define RG_VRF_RS_MASK                              0x0004
#define RG_VRF_RS_SHIFT                             2

#define VRF_ON_SEL_OFFSET                           CON0_MIXED_OFFSET
#define VRF_ON_SEL_MASK                             0x0002
#define VRF_ON_SEL_SHIFT                            1

#define RG_VRF_EN_OFFSET                            CON0_MIXED_OFFSET
#define RG_VRF_EN_MASK                              0x0001
#define RG_VRF_EN_SHIFT                             0

#define RG_VRF_CAL_OFFSET                           CON1_MIXED_OFFSET
#define RG_VRF_CAL_MASK                             0x00F0
#define RG_VRF_CAL_SHIFT                            4

#define VRF_STB_TD_OFFSET                           CON2_MIXED_OFFSET
#define VRF_STB_TD_MASK                             0x00C0
#define VRF_STB_TD_SHIFT                            6

#define VRF_OC_TD_OFFSET                            CON2_MIXED_OFFSET
#define VRF_OC_TD_MASK                              0x0030
#define VRF_OC_TD_SHIFT                             4

#define QI_VTCXO_STATUS_OFFSET                      CON0_MIXED_OFFSET
#define QI_VTCXO_STATUS_MASK                        0x8000
#define QI_VTCXO_STATUS_SHIFT                       15

#define VTCXO_OC_FLAG_OFFSET                        CON0_MIXED_OFFSET
#define VTCXO_OC_FLAG_MASK                          0x4000
#define VTCXO_OC_FLAG_SHIFT                         14

#define VTCXO_OC_AUTOFF_OFFSET                      CON0_MIXED_OFFSET
#define VTCXO_OC_AUTOFF_MASK                        0x1000
#define VTCXO_OC_AUTOFF_SHIFT                       12

#define RG_VTCXO_NDIS_EN_OFFSET                     CON0_MIXED_OFFSET
#define RG_VTCXO_NDIS_EN_MASK                       0x0400
#define RG_VTCXO_NDIS_EN_SHIFT                      10

#define RG_VTCXO_BIST_EN_OFFSET                     CON0_MIXED_OFFSET
#define RG_VTCXO_BIST_EN_MASK                       0x0008
#define RG_VTCXO_BIST_EN_SHIFT                      3

#define VTCXO_ON_SEL_OFFSET                         CON0_MIXED_OFFSET
#define VTCXO_ON_SEL_MASK                           0x0002
#define VTCXO_ON_SEL_SHIFT                          1

#define RG_VTCXO_EN_OFFSET                          CON0_MIXED_OFFSET
#define RG_VTCXO_EN_MASK                            0x0001
#define RG_VTCXO_EN_SHIFT                           0

#define RG_VTCXO_CAL_OFFSET                         CON1_MIXED_OFFSET
#define RG_VTCXO_CAL_MASK                           0x00F0
#define RG_VTCXO_CAL_SHIFT                          4

#define VTCXO_MODE_SEL_OFFSET                       CON1_MIXED_OFFSET
#define VTCXO_MODE_SEL_MASK                         0x0002
#define VTCXO_MODE_SEL_SHIFT                        1

#define RG_VTCXO_LP_EN_OFFSET                       CON1_MIXED_OFFSET
#define RG_VTCXO_LP_EN_MASK                         0x0001
#define RG_VTCXO_LP_EN_SHIFT                        0

#define VTCXO_STB_TD_OFFSET                         CON2_MIXED_OFFSET
#define VTCXO_STB_TD_MASK                           0x00C0
#define VTCXO_STB_TD_SHIFT                          6

#define VTCXO_OC_TD_OFFSET                          CON2_MIXED_OFFSET
#define VTCXO_OC_TD_MASK                            0x0030
#define VTCXO_OC_TD_SHIFT                           4

#define QI_VA_STATUS_OFFSET                         CON0_MIXED_OFFSET
#define QI_VA_STATUS_MASK                           0x8000
#define QI_VA_STATUS_SHIFT                          15

#define VA_OC_FLAG_OFFSET                           CON0_MIXED_OFFSET
#define VA_OC_FLAG_MASK                             0x4000
#define VA_OC_FLAG_SHIFT                            14

#define VA_OC_AUTOFF_OFFSET                         CON0_MIXED_OFFSET
#define VA_OC_AUTOFF_MASK                           0x1000
#define VA_OC_AUTOFF_SHIFT                          12

#define RG_VA_NDIS_EN_OFFSET                        CON0_MIXED_OFFSET
#define RG_VA_NDIS_EN_MASK                          0x0400
#define RG_VA_NDIS_EN_SHIFT                         10

#define RG_VA_BIST_EN_OFFSET                        CON0_MIXED_OFFSET
#define RG_VA_BIST_EN_MASK                          0x0008
#define RG_VA_BIST_EN_SHIFT                         3

#define RG_VA_RS_OFFSET                             CON0_MIXED_OFFSET
#define RG_VA_RS_MASK                               0x0004
#define RG_VA_RS_SHIFT                              2

#define RG_VA_EN_OFFSET                             CON0_MIXED_OFFSET
#define RG_VA_EN_MASK                               0x0001
#define RG_VA_EN_SHIFT                              0

#define RG_VA_CAL_OFFSET                            CON1_MIXED_OFFSET
#define RG_VA_CAL_MASK                              0x00F0
#define RG_VA_CAL_SHIFT                             4

#define VA_MODE_SEL_OFFSET                          CON1_MIXED_OFFSET
#define VA_MODE_SEL_MASK                            0x0002
#define VA_MODE_SEL_SHIFT                           1

#define RG_VA_LP_EN_OFFSET                          CON1_MIXED_OFFSET
#define RG_VA_LP_EN_MASK                            0x0001
#define RG_VA_LP_EN_SHIFT                           0

#define VA_STB_TD_OFFSET                            CON2_MIXED_OFFSET
#define VA_STB_TD_MASK                              0x00C0
#define VA_STB_TD_SHIFT                             6

#define VA_OC_TD_OFFSET                             CON2_MIXED_OFFSET
#define VA_OC_TD_MASK                               0x0030
#define VA_OC_TD_SHIFT                              4

#define QI_VCAMA_STATUS_OFFSET                      CON0_MIXED_OFFSET
#define QI_VCAMA_STATUS_MASK                        0x8000
#define QI_VCAMA_STATUS_SHIFT                       15

#define VCAMA_OC_FLAG_OFFSET                        CON0_MIXED_OFFSET
#define VCAMA_OC_FLAG_MASK                          0x4000
#define VCAMA_OC_FLAG_SHIFT                         14

#define VCAMA_OCFB_EN_OFFSET                        CON0_MIXED_OFFSET
#define VCAMA_OCFB_EN_MASK                          0x2000
#define VCAMA_OCFB_EN_SHIFT                         13

#define VCAMA_OC_AUTOFF_OFFSET                      CON0_MIXED_OFFSET
#define VCAMA_OC_AUTOFF_MASK                        0x1000
#define VCAMA_OC_AUTOFF_SHIFT                       12

#define RG_VCAMA_NDIS_EN_OFFSET                     CON0_MIXED_OFFSET
#define RG_VCAMA_NDIS_EN_MASK                       0x0400
#define RG_VCAMA_NDIS_EN_SHIFT                      10

#define RG_VCAMA_VOSEL_OFFSET                       CON0_MIXED_OFFSET
#define RG_VCAMA_VOSEL_MASK                         0x0030
#define RG_VCAMA_VOSEL_SHIFT                        4

#define RG_VCAMA_BIST_EN_OFFSET                     CON0_MIXED_OFFSET
#define RG_VCAMA_BIST_EN_MASK                       0x0008
#define RG_VCAMA_BIST_EN_SHIFT                      3

#define RG_VCAMA_EN_OFFSET                          CON0_MIXED_OFFSET
#define RG_VCAMA_EN_MASK                            0x0001
#define RG_VCAMA_EN_SHIFT                           0

#define RG_VCAMA_CAL_OFFSET                         CON1_MIXED_OFFSET
#define RG_VCAMA_CAL_MASK                           0x00F0
#define RG_VCAMA_CAL_SHIFT                          4

#define VCAMA_STB_TD_OFFSET                         CON2_MIXED_OFFSET
#define VCAMA_STB_TD_MASK                           0x00C0
#define VCAMA_STB_TD_SHIFT                          6

#define VCAMA_OC_TD_OFFSET                          CON2_MIXED_OFFSET
#define VCAMA_OC_TD_MASK                            0x0030
#define VCAMA_OC_TD_SHIFT                           4

#define QI_VCAMD_STATUS_OFFSET                      CON0_MIXED_OFFSET
#define QI_VCAMD_STATUS_MASK                        0x8000
#define QI_VCAMD_STATUS_SHIFT                       15

#define VCAMD_OC_FLAG_OFFSET                        CON0_MIXED_OFFSET
#define VCAMD_OC_FLAG_MASK                          0x4000
#define VCAMD_OC_FLAG_SHIFT                         14

#define VCAMD_OC_AUTOFF_OFFSET                      CON0_MIXED_OFFSET
#define VCAMD_OC_AUTOFF_MASK                        0x1000
#define VCAMD_OC_AUTOFF_SHIFT                       12

#define RG_VCAMD_NDIS_EN_OFFSET                     CON0_MIXED_OFFSET
#define RG_VCAMD_NDIS_EN_MASK                       0x0400
#define RG_VCAMD_NDIS_EN_SHIFT                      10

#define RG_VCAMD_VOSEL_OFFSET                       CON0_MIXED_OFFSET
#define RG_VCAMD_VOSEL_MASK                         0x0070
#define RG_VCAMD_VOSEL_SHIFT                        4

#define RG_VCAMD_BIST_EN_OFFSET                     CON0_MIXED_OFFSET
#define RG_VCAMD_BIST_EN_MASK                       0x0008
#define RG_VCAMD_BIST_EN_SHIFT                      3

#define RG_VCAMD_EN_OFFSET                          CON0_MIXED_OFFSET
#define RG_VCAMD_EN_MASK                            0x0001
#define RG_VCAMD_EN_SHIFT                           0

#define RG_VCAMD_CAL_OFFSET                         CON1_MIXED_OFFSET
#define RG_VCAMD_CAL_MASK                           0x00F0
#define RG_VCAMD_CAL_SHIFT                          4

#define VCAMD_STB_TD_OFFSET                         CON2_MIXED_OFFSET
#define VCAMD_STB_TD_MASK                           0x00C0
#define VCAMD_STB_TD_SHIFT                          6

#define VCAMD_OC_TD_OFFSET                          CON2_MIXED_OFFSET
#define VCAMD_OC_TD_MASK                            0x0030
#define VCAMD_OC_TD_SHIFT                           4

#define QI_VIO28_STATUS_OFFSET                      CON0_MIXED_OFFSET
#define QI_VIO28_STATUS_MASK                        0x8000
#define QI_VIO28_STATUS_SHIFT                       15

#define VIO28_OC_FLAG_OFFSET                        CON0_MIXED_OFFSET
#define VIO28_OC_FLAG_MASK                          0x4000
#define VIO28_OC_FLAG_SHIFT                         14

#define VIO28_OC_AUTOFF_OFFSET                      CON0_MIXED_OFFSET
#define VIO28_OC_AUTOFF_MASK                        0x1000
#define VIO28_OC_AUTOFF_SHIFT                       12

#define RG_VIO28_NDIS_EN_OFFSET                     CON0_MIXED_OFFSET
#define RG_VIO28_NDIS_EN_MASK                       0x0400
#define RG_VIO28_NDIS_EN_SHIFT                      10

#define RG_VIO28_BIST_EN_OFFSET                     CON0_MIXED_OFFSET
#define RG_VIO28_BIST_EN_MASK                       0x0008
#define RG_VIO28_BIST_EN_SHIFT                      3

#define RG_VIO28_EN_OFFSET                          CON0_MIXED_OFFSET
#define RG_VIO28_EN_MASK                            0x0001
#define RG_VIO28_EN_SHIFT                           0

#define RG_VIO28_CAL_OFFSET                         CON1_MIXED_OFFSET
#define RG_VIO28_CAL_MASK                           0x00F0
#define RG_VIO28_CAL_SHIFT                          4

#define VIO28_STB_TD_OFFSET                         CON2_MIXED_OFFSET
#define VIO28_STB_TD_MASK                           0x00C0
#define VIO28_STB_TD_SHIFT                          6

#define VIO28_OC_TD_OFFSET                          CON2_MIXED_OFFSET
#define VIO28_OC_TD_MASK                            0x0030
#define VIO28_OC_TD_SHIFT                           4

#define QI_VUSB_STATUS_OFFSET                       CON0_MIXED_OFFSET
#define QI_VUSB_STATUS_MASK                         0x8000
#define QI_VUSB_STATUS_SHIFT                        15

#define VUSB_OC_FLAG_OFFSET                         CON0_MIXED_OFFSET
#define VUSB_OC_FLAG_MASK                           0x4000
#define VUSB_OC_FLAG_SHIFT                          14

#define VUSB_OC_AUTOFF_OFFSET                       CON0_MIXED_OFFSET
#define VUSB_OC_AUTOFF_MASK                         0x1000
#define VUSB_OC_AUTOFF_SHIFT                        12

#define RG_VUSB_NDIS_EN_OFFSET                      CON0_MIXED_OFFSET
#define RG_VUSB_NDIS_EN_MASK                        0x0400
#define RG_VUSB_NDIS_EN_SHIFT                       10

#define RG_VUSB_BIST_EN_OFFSET                      CON0_MIXED_OFFSET
#define RG_VUSB_BIST_EN_MASK                        0x0008
#define RG_VUSB_BIST_EN_SHIFT                       3

#define RG_VUSB_EN_OFFSET                           CON0_MIXED_OFFSET
#define RG_VUSB_EN_MASK                             0x0001
#define RG_VUSB_EN_SHIFT                            0

#define RG_VUSB_CAL_OFFSET                          CON1_MIXED_OFFSET
#define RG_VUSB_CAL_MASK                            0x00F0
#define RG_VUSB_CAL_SHIFT                           4

#define VUSB_STB_TD_OFFSET                          CON2_MIXED_OFFSET
#define VUSB_STB_TD_MASK                            0x00C0
#define VUSB_STB_TD_SHIFT                           6

#define VUSB_OC_TD_OFFSET                           CON2_MIXED_OFFSET
#define VUSB_OC_TD_MASK                             0x0030
#define VUSB_OC_TD_SHIFT                            4

#define QI_VBT_STATUS_OFFSET                        CON0_MIXED_OFFSET
#define QI_VBT_STATUS_MASK                          0x8000
#define QI_VBT_STATUS_SHIFT                         15

#define VBT_OC_FLAG_OFFSET                          CON0_MIXED_OFFSET
#define VBT_OC_FLAG_MASK                            0x4000
#define VBT_OC_FLAG_SHIFT                           14

#define VBT_OC_AUTOFF_OFFSET                        CON0_MIXED_OFFSET
#define VBT_OC_AUTOFF_MASK                          0x1000
#define VBT_OC_AUTOFF_SHIFT                         12

#define RG_VBT_NDIS_EN_OFFSET                       CON0_MIXED_OFFSET
#define RG_VBT_NDIS_EN_MASK                         0x0400
#define RG_VBT_NDIS_EN_SHIFT                        10

#define RG_VBT_BIST_EN_OFFSET                       CON0_MIXED_OFFSET
#define RG_VBT_BIST_EN_MASK                         0x0008
#define RG_VBT_BIST_EN_SHIFT                        3

#define VBT_ON_SEL_OFFSET                           CON0_MIXED_OFFSET
#define VBT_ON_SEL_MASK                             0x0002
#define VBT_ON_SEL_SHIFT                            1

#define RG_VBT_EN_OFFSET                            CON0_MIXED_OFFSET
#define RG_VBT_EN_MASK                              0x0001
#define RG_VBT_EN_SHIFT                             0

#define RG_VBT_CAL_OFFSET                           CON1_MIXED_OFFSET
#define RG_VBT_CAL_MASK                             0x00F0
#define RG_VBT_CAL_SHIFT                            4

#define VBT_STB_TD_OFFSET                           CON2_MIXED_OFFSET
#define VBT_STB_TD_MASK                             0x00C0
#define VBT_STB_TD_SHIFT                            6

#define VBT_OC_TD_OFFSET                            CON2_MIXED_OFFSET
#define VBT_OC_TD_MASK                              0x0030
#define VBT_OC_TD_SHIFT                             4

#define QI_VSIM1_STATUS_OFFSET                      CON0_MIXED_OFFSET
#define QI_VSIM1_STATUS_MASK                        0x8000
#define QI_VSIM1_STATUS_SHIFT                       15

#define VSIM1_OC_FLAG_OFFSET                        CON0_MIXED_OFFSET
#define VSIM1_OC_FLAG_MASK                          0x4000
#define VSIM1_OC_FLAG_SHIFT                         14

#define VSIM1_OC_AUTOFF_OFFSET                      CON0_MIXED_OFFSET
#define VSIM1_OC_AUTOFF_MASK                        0x1000
#define VSIM1_OC_AUTOFF_SHIFT                       12

#define RG_VSIM1_NDIS_EN_OFFSET                     CON0_MIXED_OFFSET
#define RG_VSIM1_NDIS_EN_MASK                       0x0400
#define RG_VSIM1_NDIS_EN_SHIFT                      10

#define RG_VSIM1_VOSEL_OFFSET                       CON0_MIXED_OFFSET
#define RG_VSIM1_VOSEL_MASK                         0x0010
#define RG_VSIM1_VOSEL_SHIFT                        4

#define RG_VSIM1_BIST_EN_OFFSET                     CON0_MIXED_OFFSET
#define RG_VSIM1_BIST_EN_MASK                       0x0008
#define RG_VSIM1_BIST_EN_SHIFT                      3

#define RG_VSIM1_EN_OFFSET                          CON0_MIXED_OFFSET
#define RG_VSIM1_EN_MASK                            0x0001
#define RG_VSIM1_EN_SHIFT                           0

#define RG_VSIM1_CAL_OFFSET                         CON1_MIXED_OFFSET
#define RG_VSIM1_CAL_MASK                           0x00F0
#define RG_VSIM1_CAL_SHIFT                          4

#define VSIM1_STB_TD_OFFSET                         CON2_MIXED_OFFSET
#define VSIM1_STB_TD_MASK                           0x00C0
#define VSIM1_STB_TD_SHIFT                          6

#define VSIM1_OC_TD_OFFSET                          CON2_MIXED_OFFSET
#define VSIM1_OC_TD_MASK                            0x0030
#define VSIM1_OC_TD_SHIFT                           4

#define VSIM1_GPLDO_EN_OFFSET                       CON2_MIXED_OFFSET
#define VSIM1_GPLDO_EN_MASK                         0x0002
#define VSIM1_GPLDO_EN_SHIFT                        1

#define QI_VSIM2_STATUS_OFFSET                      CON0_MIXED_OFFSET
#define QI_VSIM2_STATUS_MASK                        0x8000
#define QI_VSIM2_STATUS_SHIFT                       15

#define VSIM2_OC_FLAG_OFFSET                        CON0_MIXED_OFFSET
#define VSIM2_OC_FLAG_MASK                          0x4000
#define VSIM2_OC_FLAG_SHIFT                         14

#define VSIM2_OC_AUTOFF_OFFSET                      CON0_MIXED_OFFSET
#define VSIM2_OC_AUTOFF_MASK                        0x1000
#define VSIM2_OC_AUTOFF_SHIFT                       12

#define RG_VSIM2_NDIS_EN_OFFSET                     CON0_MIXED_OFFSET
#define RG_VSIM2_NDIS_EN_MASK                       0x0400
#define RG_VSIM2_NDIS_EN_SHIFT                      10

#define RG_VSIM2_VOSEL_OFFSET                       CON0_MIXED_OFFSET
#define RG_VSIM2_VOSEL_MASK                         0x0070
#define RG_VSIM2_VOSEL_SHIFT                        4

#define RG_VSIM2_BIST_EN_OFFSET                     CON0_MIXED_OFFSET
#define RG_VSIM2_BIST_EN_MASK                       0x0008
#define RG_VSIM2_BIST_EN_SHIFT                      3

#define RG_VSIM2_EN_OFFSET                          CON0_MIXED_OFFSET
#define RG_VSIM2_EN_MASK                            0x0001
#define RG_VSIM2_EN_SHIFT                           0

#define RG_VSIM2_CAL_OFFSET                         CON1_MIXED_OFFSET
#define RG_VSIM2_CAL_MASK                           0x00F0
#define RG_VSIM2_CAL_SHIFT                          4

#define VSIM2_STB_TD_OFFSET                         CON2_MIXED_OFFSET
#define VSIM2_STB_TD_MASK                           0x00C0
#define VSIM2_STB_TD_SHIFT                          6

#define VSIM2_OC_TD_OFFSET                          CON2_MIXED_OFFSET
#define VSIM2_OC_TD_MASK                            0x0030
#define VSIM2_OC_TD_SHIFT                           4

#define VSIM2_GPLDO_EN_OFFSET                       CON2_MIXED_OFFSET
#define VSIM2_GPLDO_EN_MASK                         0x0002
#define VSIM2_GPLDO_EN_SHIFT                        1

#define VRTC_STATUS_OFFSET                          CON0_MIXED_OFFSET
#define VRTC_STATUS_MASK                            0x8000
#define VRTC_STATUS_SHIFT                           15

#define VRTC_OC_FLAG_OFFSET                         CON0_MIXED_OFFSET
#define VRTC_OC_FLAG_MASK                           0x4000
#define VRTC_OC_FLAG_SHIFT                          14

#define VRTC_OC_AUTOFF_OFFSET                       CON0_MIXED_OFFSET
#define VRTC_OC_AUTOFF_MASK                         0x1000
#define VRTC_OC_AUTOFF_SHIFT                        12

#define RG_VRTC_EN_OFFSET                           CON0_MIXED_OFFSET
#define RG_VRTC_EN_MASK                             0x0001
#define RG_VRTC_EN_SHIFT                            0

#define RG_VRTC_CAL_OFFSET                          CON1_MIXED_OFFSET
#define RG_VRTC_CAL_MASK                            0x00F0
#define RG_VRTC_CAL_SHIFT                           4

#define VRTC_STB_TD_OFFSET                          CON2_MIXED_OFFSET
#define VRTC_STB_TD_MASK                            0x00C0
#define VRTC_STB_TD_SHIFT                           6

#define VRTC_OC_TD_OFFSET                           CON2_MIXED_OFFSET
#define VRTC_OC_TD_MASK                             0x0030
#define VRTC_OC_TD_SHIFT                            4

#define QI_VIBR_STATUS_OFFSET                       CON0_MIXED_OFFSET
#define QI_VIBR_STATUS_MASK                         0x8000
#define QI_VIBR_STATUS_SHIFT                        15

#define VIBR_OC_FLAG_OFFSET                         CON0_MIXED_OFFSET
#define VIBR_OC_FLAG_MASK                           0x4000
#define VIBR_OC_FLAG_SHIFT                          14

#define VIBR_OC_AUTOFF_OFFSET                       CON0_MIXED_OFFSET
#define VIBR_OC_AUTOFF_MASK                         0x1000
#define VIBR_OC_AUTOFF_SHIFT                        12

#define RG_VIBR_STB_SEL_OFFSET                      CON0_MIXED_OFFSET
#define RG_VIBR_STB_SEL_MASK                        0x0800
#define RG_VIBR_STB_SEL_SHIFT                       11

#define RG_VIBR_NDIS_EN_OFFSET                      CON0_MIXED_OFFSET
#define RG_VIBR_NDIS_EN_MASK                        0x0400
#define RG_VIBR_NDIS_EN_SHIFT                       10

#define RG_VIBR_VOSEL_OFFSET                        CON0_MIXED_OFFSET
#define RG_VIBR_VOSEL_MASK                          0x0070
#define RG_VIBR_VOSEL_SHIFT                         4

#define RG_VIBR_BIST_EN_OFFSET                      CON0_MIXED_OFFSET
#define RG_VIBR_BIST_EN_MASK                        0x0008
#define RG_VIBR_BIST_EN_SHIFT                       3

#define RG_VIBR_EN_OFFSET                           CON0_MIXED_OFFSET
#define RG_VIBR_EN_MASK                             0x0001
#define RG_VIBR_EN_SHIFT                            0

#define RG_VIBR_CAL_OFFSET                          CON1_MIXED_OFFSET
#define RG_VIBR_CAL_MASK                            0x00F0
#define RG_VIBR_CAL_SHIFT                           4

#define VIBR_STB_TD_OFFSET                          CON2_MIXED_OFFSET
#define VIBR_STB_TD_MASK                            0x00C0
#define VIBR_STB_TD_SHIFT                           6

#define VIBR_OC_TD_OFFSET                           CON2_MIXED_OFFSET
#define VIBR_OC_TD_MASK                             0x0030
#define VIBR_OC_TD_SHIFT                            4

#define QI_VMC_STATUS_OFFSET                        CON0_MIXED_OFFSET
#define QI_VMC_STATUS_MASK                          0x8000
#define QI_VMC_STATUS_SHIFT                         15

#define VMC_OC_FLAG_OFFSET                          CON0_MIXED_OFFSET
#define VMC_OC_FLAG_MASK                            0x4000
#define VMC_OC_FLAG_SHIFT                           14

#define VMC_OC_AUTOFF_OFFSET                        CON0_MIXED_OFFSET
#define VMC_OC_AUTOFF_MASK                          0x1000
#define VMC_OC_AUTOFF_SHIFT                         12

#define RG_VMC_STB_SEL_OFFSET                       CON0_MIXED_OFFSET
#define RG_VMC_STB_SEL_MASK                         0x0800
#define RG_VMC_STB_SEL_SHIFT                        11

#define RG_VMC_NDIS_EN_OFFSET                       CON0_MIXED_OFFSET
#define RG_VMC_NDIS_EN_MASK                         0x0400
#define RG_VMC_NDIS_EN_SHIFT                        10

#define RG_VMC_VOSEL_OFFSET                         CON0_MIXED_OFFSET
#define RG_VMC_VOSEL_MASK                           0x0030
#define RG_VMC_VOSEL_SHIFT                          4

#define RG_VMC_BIST_EN_OFFSET                       CON0_MIXED_OFFSET
#define RG_VMC_BIST_EN_MASK                         0x0008
#define RG_VMC_BIST_EN_SHIFT                        3

#define RG_VMC_EN_OFFSET                            CON0_MIXED_OFFSET
#define RG_VMC_EN_MASK                              0x0001
#define RG_VMC_EN_SHIFT                             0

#define RG_VMC_CAL_OFFSET                           CON1_MIXED_OFFSET
#define RG_VMC_CAL_MASK                             0x00F0
#define RG_VMC_CAL_SHIFT                            4

#define VMC_STB_TD_OFFSET                           CON2_MIXED_OFFSET
#define VMC_STB_TD_MASK                             0x00C0
#define VMC_STB_TD_SHIFT                            6

#define VMC_OC_TD_OFFSET                            CON2_MIXED_OFFSET
#define VMC_OC_TD_MASK                              0x0030
#define VMC_OC_TD_SHIFT                             4

#define QI_VSF_STATUS_OFFSET                        CON0_MIXED_OFFSET
#define QI_VSF_STATUS_MASK                          0x8000
#define QI_VSF_STATUS_SHIFT                         15

#define VSF_OC_FLAG_OFFSET                          CON0_MIXED_OFFSET
#define VSF_OC_FLAG_MASK                            0x4000
#define VSF_OC_FLAG_SHIFT                           14

#define VSF_OC_AUTOFF_OFFSET                        CON0_MIXED_OFFSET
#define VSF_OC_AUTOFF_MASK                          0x1000
#define VSF_OC_AUTOFF_SHIFT                         12

#define RG_VSF_NDIS_EN_OFFSET                       CON0_MIXED_OFFSET
#define RG_VSF_NDIS_EN_MASK                         0x0400
#define RG_VSF_NDIS_EN_SHIFT                        10

#define RG_VSF_VOSEL_OFFSET                         CON0_MIXED_OFFSET
#define RG_VSF_VOSEL_MASK                           0x0010
#define RG_VSF_VOSEL_SHIFT                          4

#define RG_VSF_BIST_EN_OFFSET                       CON0_MIXED_OFFSET
#define RG_VSF_BIST_EN_MASK                         0x0008
#define RG_VSF_BIST_EN_SHIFT                        3

#define RG_VSF_EN_OFFSET                            CON0_MIXED_OFFSET
#define RG_VSF_EN_MASK                              0x0001
#define RG_VSF_EN_SHIFT                             0

#define RG_VSF_CAL_OFFSET                           CON1_MIXED_OFFSET
#define RG_VSF_CAL_MASK                             0x00F0
#define RG_VSF_CAL_SHIFT                            4

#define VSF_STB_TD_OFFSET                           CON2_MIXED_OFFSET
#define VSF_STB_TD_MASK                             0x00C0
#define VSF_STB_TD_SHIFT                            6

#define VSF_OC_TD_OFFSET                            CON2_MIXED_OFFSET
#define VSF_OC_TD_MASK                              0x0030
#define VSF_OC_TD_SHIFT                             4

#define VSF_AUTOFF_DLY_SEL_OFFSET                   CON3_MIXED_OFFSET
#define VSF_AUTOFF_DLY_SEL_MASK                     0x00F0
#define VSF_AUTOFF_DLY_SEL_SHIFT                    4

#define VSF_VOSEL_SEL_OFFSET                        CON3_MIXED_OFFSET
#define VSF_VOSEL_SEL_MASK                          0x0004
#define VSF_VOSEL_SEL_SHIFT                         2

#define VSF_AUTOFF_EN_OFFSET                        CON3_MIXED_OFFSET
#define VSF_AUTOFF_EN_MASK                          0x0001
#define VSF_AUTOFF_EN_SHIFT                         0

#define QI_VIO18_STATUS_OFFSET                      CON0_MIXED_OFFSET
#define QI_VIO18_STATUS_MASK                        0x8000
#define QI_VIO18_STATUS_SHIFT                       15

#define VIO18_OC_FLAG_OFFSET                        CON0_MIXED_OFFSET
#define VIO18_OC_FLAG_MASK                          0x4000
#define VIO18_OC_FLAG_SHIFT                         14

#define VIO18_OC_AUTOFF_OFFSET                      CON0_MIXED_OFFSET
#define VIO18_OC_AUTOFF_MASK                        0x1000
#define VIO18_OC_AUTOFF_SHIFT                       12

#define RG_VIO18_NDIS_EN_OFFSET                     CON0_MIXED_OFFSET
#define RG_VIO18_NDIS_EN_MASK                       0x0400
#define RG_VIO18_NDIS_EN_SHIFT                      10

#define RG_VIO18_BIST_EN_OFFSET                     CON0_MIXED_OFFSET
#define RG_VIO18_BIST_EN_MASK                       0x0008
#define RG_VIO18_BIST_EN_SHIFT                      3

#define RG_VIO18_EN_OFFSET                          CON0_MIXED_OFFSET
#define RG_VIO18_EN_MASK                            0x0001
#define RG_VIO18_EN_SHIFT                           0

#define RG_VIO18_CAL_OFFSET                         CON1_MIXED_OFFSET
#define RG_VIO18_CAL_MASK                           0x00F0
#define RG_VIO18_CAL_SHIFT                          4

#define VIO18_STB_TD_OFFSET                         CON2_MIXED_OFFSET
#define VIO18_STB_TD_MASK                           0x00C0
#define VIO18_STB_TD_SHIFT                          6

#define VIO18_OC_TD_OFFSET                          CON2_MIXED_OFFSET
#define VIO18_OC_TD_MASK                            0x0030
#define VIO18_OC_TD_SHIFT                           4

#define QI_VCORE_STATUS_OFFSET                      CON0_MIXED_OFFSET
#define QI_VCORE_STATUS_MASK                        0x8000
#define QI_VCORE_STATUS_SHIFT                       15

#define VCORE_OC_FLAG_OFFSET                        CON0_MIXED_OFFSET
#define VCORE_OC_FLAG_MASK                          0x4000
#define VCORE_OC_FLAG_SHIFT                         14

#define VCORE_OC_AUTOFF_OFFSET                      CON0_MIXED_OFFSET
#define VCORE_OC_AUTOFF_MASK                        0x1000
#define VCORE_OC_AUTOFF_SHIFT                       12

#define RG_VCORE_NDIS_EN_OFFSET                     CON0_MIXED_OFFSET
#define RG_VCORE_NDIS_EN_MASK                       0x0400
#define RG_VCORE_NDIS_EN_SHIFT                      10

#define RG_VCORE_VOSEL_OFFSET                       CON0_MIXED_OFFSET
#define RG_VCORE_VOSEL_MASK                         0x01F0
#define RG_VCORE_VOSEL_SHIFT                        4

#define RG_VCORE_BIST_EN_OFFSET                     CON0_MIXED_OFFSET
#define RG_VCORE_BIST_EN_MASK                       0x0008
#define RG_VCORE_BIST_EN_SHIFT                      3

#define RG_VCORE_RS_OFFSET                          CON0_MIXED_OFFSET
#define RG_VCORE_RS_MASK                            0x0004
#define RG_VCORE_RS_SHIFT                           2

#define RG_VCORE_EN_OFFSET                          CON0_MIXED_OFFSET
#define RG_VCORE_EN_MASK                            0x0001
#define RG_VCORE_EN_SHIFT                           0

#define VCORE_STB_TD_OFFSET                         CON2_MIXED_OFFSET
#define VCORE_STB_TD_MASK                           0x00C0
#define VCORE_STB_TD_SHIFT                          6

#define VCORE_OC_TD_OFFSET                          CON2_MIXED_OFFSET
#define VCORE_OC_TD_MASK                            0x0030
#define VCORE_OC_TD_SHIFT                           4

#define VCORE_VOSEL_SLEEP_OFFSET                    CON3_MIXED_OFFSET
#define VCORE_VOSEL_SLEEP_MASK                      0x01F0
#define VCORE_VOSEL_SLEEP_SHIFT                     4

#define ISINK_STP_EN_OFFSET                         CON3_MIXED_OFFSET
#define ISINK_STP_EN_MASK                           0x0008
#define ISINK_STP_EN_SHIFT                          3

#define VSF_OC_INT_EN_OFFSET                        CON0_MIXED_OFFSET
#define VSF_OC_INT_EN_MASK                          0x2000
#define VSF_OC_INT_EN_SHIFT                         13

#define VMC_OC_INT_EN_OFFSET                        CON0_MIXED_OFFSET
#define VMC_OC_INT_EN_MASK                          0x1000
#define VMC_OC_INT_EN_SHIFT                         12

#define VIBR_OC_INT_EN_OFFSET                       CON0_MIXED_OFFSET
#define VIBR_OC_INT_EN_MASK                         0x0800
#define VIBR_OC_INT_EN_SHIFT                        11

#define VRTC_OC_INT_EN_OFFSET                       CON0_MIXED_OFFSET
#define VRTC_OC_INT_EN_MASK                         0x0400
#define VRTC_OC_INT_EN_SHIFT                        10

#define VSIM2_OC_INT_EN_OFFSET                      CON0_MIXED_OFFSET
#define VSIM2_OC_INT_EN_MASK                        0x0200
#define VSIM2_OC_INT_EN_SHIFT                       9

#define VSIM1_OC_INT_EN_OFFSET                      CON0_MIXED_OFFSET
#define VSIM1_OC_INT_EN_MASK                        0x0100
#define VSIM1_OC_INT_EN_SHIFT                       8

#define VBT_OC_INT_EN_OFFSET                        CON0_MIXED_OFFSET
#define VBT_OC_INT_EN_MASK                          0x0080
#define VBT_OC_INT_EN_SHIFT                         7

#define VUSB_OC_INT_EN_OFFSET                       CON0_MIXED_OFFSET
#define VUSB_OC_INT_EN_MASK                         0x0040
#define VUSB_OC_INT_EN_SHIFT                        6

#define VIO28_OC_INT_EN_OFFSET                      CON0_MIXED_OFFSET
#define VIO28_OC_INT_EN_MASK                        0x0020
#define VIO28_OC_INT_EN_SHIFT                       5

#define VCAMD_OC_INT_EN_OFFSET                      CON0_MIXED_OFFSET
#define VCAMD_OC_INT_EN_MASK                        0x0010
#define VCAMD_OC_INT_EN_SHIFT                       4

#define VCAMA_OC_INT_EN_OFFSET                      CON0_MIXED_OFFSET
#define VCAMA_OC_INT_EN_MASK                        0x0008
#define VCAMA_OC_INT_EN_SHIFT                       3

#define VA_OC_INT_EN_OFFSET                         CON0_MIXED_OFFSET
#define VA_OC_INT_EN_MASK                           0x0004
#define VA_OC_INT_EN_SHIFT                          2

#define VTCXO_OC_INT_EN_OFFSET                      CON0_MIXED_OFFSET
#define VTCXO_OC_INT_EN_MASK                        0x0002
#define VTCXO_OC_INT_EN_SHIFT                       1

#define VRF_OC_INT_EN_OFFSET                        CON0_MIXED_OFFSET
#define VRF_OC_INT_EN_MASK                          0x0001
#define VRF_OC_INT_EN_SHIFT                         0

#define VIO18_OC_INT_EN_OFFSET                      CON1_MIXED_OFFSET
#define VIO18_OC_INT_EN_MASK                        0x0002
#define VIO18_OC_INT_EN_SHIFT                       1

#define VCORE_OC_INT_EN_OFFSET                      CON1_MIXED_OFFSET
#define VCORE_OC_INT_EN_MASK                        0x0001
#define VCORE_OC_INT_EN_SHIFT                       0

#define SPK_OC_INT_EN_OFFSET                        CON3_MIXED_OFFSET
#define SPK_OC_INT_EN_MASK                          0x0001
#define SPK_OC_INT_EN_SHIFT                         0

#define VSF_OC_FLAG_WR_OFFSET                       CON4_MIXED_OFFSET
#define VSF_OC_FLAG_WR_MASK                         0x2000
#define VSF_OC_FLAG_WR_SHIFT                        13

#define VMC_OC_FLAG_WR_OFFSET                       CON4_MIXED_OFFSET
#define VMC_OC_FLAG_WR_MASK                         0x1000
#define VMC_OC_FLAG_WR_SHIFT                        12

#define VIBR_OC_FLAG_WR_OFFSET                      CON4_MIXED_OFFSET
#define VIBR_OC_FLAG_WR_MASK                        0x0800
#define VIBR_OC_FLAG_WR_SHIFT                       11

#define VRTC_OC_FLAG_WR_OFFSET                      CON4_MIXED_OFFSET
#define VRTC_OC_FLAG_WR_MASK                        0x0400
#define VRTC_OC_FLAG_WR_SHIFT                       10

#define VSIM2_OC_FLAG_WR_OFFSET                     CON4_MIXED_OFFSET
#define VSIM2_OC_FLAG_WR_MASK                       0x0200
#define VSIM2_OC_FLAG_WR_SHIFT                      9

#define VSIM1_OC_FLAG_WR_OFFSET                     CON4_MIXED_OFFSET
#define VSIM1_OC_FLAG_WR_MASK                       0x0100
#define VSIM1_OC_FLAG_WR_SHIFT                      8

#define VBT_OC_FLAG_WR_OFFSET                       CON4_MIXED_OFFSET
#define VBT_OC_FLAG_WR_MASK                         0x0080
#define VBT_OC_FLAG_WR_SHIFT                        7

#define VUSB_OC_FLAG_WR_OFFSET                      CON4_MIXED_OFFSET
#define VUSB_OC_FLAG_WR_MASK                        0x0040
#define VUSB_OC_FLAG_WR_SHIFT                       6

#define VIO28_OC_FLAG_WR_OFFSET                     CON4_MIXED_OFFSET
#define VIO28_OC_FLAG_WR_MASK                       0x0020
#define VIO28_OC_FLAG_WR_SHIFT                      5

#define VCAMD_OC_FLAG_WR_OFFSET                     CON4_MIXED_OFFSET
#define VCAMD_OC_FLAG_WR_MASK                       0x0010
#define VCAMD_OC_FLAG_WR_SHIFT                      4

#define VCAMA_OC_FLAG_WR_OFFSET                     CON4_MIXED_OFFSET
#define VCAMA_OC_FLAG_WR_MASK                       0x0008
#define VCAMA_OC_FLAG_WR_SHIFT                      3

#define VA_OC_FLAG_WR_OFFSET                        CON4_MIXED_OFFSET
#define VA_OC_FLAG_WR_MASK                          0x0004
#define VA_OC_FLAG_WR_SHIFT                         2

#define VTCXO_OC_FLAG_WR_OFFSET                     CON4_MIXED_OFFSET
#define VTCXO_OC_FLAG_WR_MASK                       0x0002
#define VTCXO_OC_FLAG_WR_SHIFT                      1

#define VRF_OC_FLAG_WR_OFFSET                       CON4_MIXED_OFFSET
#define VRF_OC_FLAG_WR_MASK                         0x0001
#define VRF_OC_FLAG_WR_SHIFT                        0

#define VIO18_OC_FLAG_WR_OFFSET                     CON5_MIXED_OFFSET
#define VIO18_OC_FLAG_WR_MASK                       0x0002
#define VIO18_OC_FLAG_WR_SHIFT                      1

#define VCORE_OC_FLAG_WR_OFFSET                     CON5_MIXED_OFFSET
#define VCORE_OC_FLAG_WR_MASK                       0x0001
#define VCORE_OC_FLAG_WR_SHIFT                      0

#define SPK_OC_FLAG_WR_OFFSET                       CON7_MIXED_OFFSET
#define SPK_OC_FLAG_WR_MASK                         0x0001
#define SPK_OC_FLAG_WR_SHIFT                        0

#define QI_VSF_OC_STATUS_OFFSET                     CON8_MIXED_OFFSET
#define QI_VSF_OC_STATUS_MASK                       0x2000
#define QI_VSF_OC_STATUS_SHIFT                      13

#define QI_VMC_OC_STATUS_OFFSET                     CON8_MIXED_OFFSET
#define QI_VMC_OC_STATUS_MASK                       0x1000
#define QI_VMC_OC_STATUS_SHIFT                      12

#define QI_VIBR_OC_STATUS_OFFSET                    CON8_MIXED_OFFSET
#define QI_VIBR_OC_STATUS_MASK                      0x0800
#define QI_VIBR_OC_STATUS_SHIFT                     11

#define VRTC_OC_STATUS_OFFSET                       CON8_MIXED_OFFSET
#define VRTC_OC_STATUS_MASK                         0x0400
#define VRTC_OC_STATUS_SHIFT                        10

#define QI_VSIM2_OC_STATUS_OFFSET                   CON8_MIXED_OFFSET
#define QI_VSIM2_OC_STATUS_MASK                     0x0200
#define QI_VSIM2_OC_STATUS_SHIFT                    9

#define QI_VSIM1_OC_STATUS_OFFSET                   CON8_MIXED_OFFSET
#define QI_VSIM1_OC_STATUS_MASK                     0x0100
#define QI_VSIM1_OC_STATUS_SHIFT                    8

#define QI_VBT_OC_STATUS_OFFSET                     CON8_MIXED_OFFSET
#define QI_VBT_OC_STATUS_MASK                       0x0080
#define QI_VBT_OC_STATUS_SHIFT                      7

#define QI_VUSB_OC_STATUS_OFFSET                    CON8_MIXED_OFFSET
#define QI_VUSB_OC_STATUS_MASK                      0x0040
#define QI_VUSB_OC_STATUS_SHIFT                     6

#define QI_VIO28_OC_STATUS_OFFSET                   CON8_MIXED_OFFSET
#define QI_VIO28_OC_STATUS_MASK                     0x0020
#define QI_VIO28_OC_STATUS_SHIFT                    5

#define QI_VCAMD_OC_STATUS_OFFSET                   CON8_MIXED_OFFSET
#define QI_VCAMD_OC_STATUS_MASK                     0x0010
#define QI_VCAMD_OC_STATUS_SHIFT                    4

#define QI_VCAMA_OC_STATUS_OFFSET                   CON8_MIXED_OFFSET
#define QI_VCAMA_OC_STATUS_MASK                     0x0008
#define QI_VCAMA_OC_STATUS_SHIFT                    3

#define QI_VA_OC_STATUS_OFFSET                      CON8_MIXED_OFFSET
#define QI_VA_OC_STATUS_MASK                        0x0004
#define QI_VA_OC_STATUS_SHIFT                       2

#define QI_VTCXO_OC_STATUS_OFFSET                   CON8_MIXED_OFFSET
#define QI_VTCXO_OC_STATUS_MASK                     0x0002
#define QI_VTCXO_OC_STATUS_SHIFT                    1

#define QI_VRF_OC_STATUS_OFFSET                     CON8_MIXED_OFFSET
#define QI_VRF_OC_STATUS_MASK                       0x0001
#define QI_VRF_OC_STATUS_SHIFT                      0

#define QI_VIO18_OC_STATUS_OFFSET                   CON9_MIXED_OFFSET
#define QI_VIO18_OC_STATUS_MASK                     0x0002
#define QI_VIO18_OC_STATUS_SHIFT                    1

#define QI_VCORE_OC_STATUS_OFFSET                   CON9_MIXED_OFFSET
#define QI_VCORE_OC_STATUS_MASK                     0x0001
#define QI_VCORE_OC_STATUS_SHIFT                    0

#define NI_SPK_OC_DET_OFFSET                        CON11_MIXED_OFFSET
#define NI_SPK_OC_DET_MASK                          0x0001
#define NI_SPK_OC_DET_SHIFT                         0

#define RG_VCDT_HV_VTH_OFFSET                       CON0_MIXED_OFFSET
#define RG_VCDT_HV_VTH_MASK                         0xF000
#define RG_VCDT_HV_VTH_SHIFT                        12

#define RG_VCDT_LV_VTH_OFFSET                       CON0_MIXED_OFFSET
#define RG_VCDT_LV_VTH_MASK                         0x0F00
#define RG_VCDT_LV_VTH_SHIFT                        8

#define RGS_VCDT_HV_DET_OFFSET                      CON0_MIXED_OFFSET
#define RGS_VCDT_HV_DET_MASK                        0x0080
#define RGS_VCDT_HV_DET_SHIFT                       7

#define RGS_VCDT_LV_DET_OFFSET                      CON0_MIXED_OFFSET
#define RGS_VCDT_LV_DET_MASK                        0x0040
#define RGS_VCDT_LV_DET_SHIFT                       6

#define RGS_CHRDET_OFFSET                           CON0_MIXED_OFFSET
#define RGS_CHRDET_MASK                             0x0020
#define RGS_CHRDET_SHIFT                            5

#define CHR_EN_OFFSET                               CON0_MIXED_OFFSET
#define CHR_EN_MASK                                 0x0010
#define CHR_EN_SHIFT                                4

#define RG_CSDAC_EN_OFFSET                          CON0_MIXED_OFFSET
#define RG_CSDAC_EN_MASK                            0x0008
#define RG_CSDAC_EN_SHIFT                           3

#define RG_PCHR_AUTOMODE_OFFSET                     CON0_MIXED_OFFSET
#define RG_PCHR_AUTOMODE_MASK                       0x0004
#define RG_PCHR_AUTOMODE_SHIFT                      2

#define RGS_CHR_LDO_DET_OFFSET                      CON0_MIXED_OFFSET
#define RGS_CHR_LDO_DET_MASK                        0x0002
#define RGS_CHR_LDO_DET_SHIFT                       1

#define RG_VCDT_HV_EN_OFFSET                        CON0_MIXED_OFFSET
#define RG_VCDT_HV_EN_MASK                          0x0001
#define RG_VCDT_HV_EN_SHIFT                         0

#define RG_VBAT_CV_VTH_OFFSET                       CON1_MIXED_OFFSET
#define RG_VBAT_CV_VTH_MASK                         0x1F00
#define RG_VBAT_CV_VTH_SHIFT                        8

#define RG_VBAT_CC_VTH_OFFSET                       CON1_MIXED_OFFSET
#define RG_VBAT_CC_VTH_MASK                         0x0030
#define RG_VBAT_CC_VTH_SHIFT                        4

#define RGS_VBAT_CC_DET_OFFSET                      CON1_MIXED_OFFSET
#define RGS_VBAT_CC_DET_MASK                        0x0008
#define RGS_VBAT_CC_DET_SHIFT                       3

#define RGS_VBAT_CV_DET_OFFSET                      CON1_MIXED_OFFSET
#define RGS_VBAT_CV_DET_MASK                        0x0004
#define RGS_VBAT_CV_DET_SHIFT                       2

#define RG_VBAT_CC_EN_OFFSET                        CON1_MIXED_OFFSET
#define RG_VBAT_CC_EN_MASK                          0x0002
#define RG_VBAT_CC_EN_SHIFT                         1

#define RG_VBAT_CV_EN_OFFSET                        CON1_MIXED_OFFSET
#define RG_VBAT_CV_EN_MASK                          0x0001
#define RG_VBAT_CV_EN_SHIFT                         0

#define RGS_CS_DET_OFFSET                           CON2_MIXED_OFFSET
#define RGS_CS_DET_MASK                             0x8000
#define RGS_CS_DET_SHIFT                            15

#define RG_CS_EN_OFFSET                             CON2_MIXED_OFFSET
#define RG_CS_EN_MASK                               0x0100
#define RG_CS_EN_SHIFT                              8

#define RG_CS_VTH_OFFSET                            CON2_MIXED_OFFSET
#define RG_CS_VTH_MASK                              0x000F
#define RG_CS_VTH_SHIFT                             0

#define RG_PCHR_TOLTC_OFFSET                        CON3_MIXED_OFFSET
#define RG_PCHR_TOLTC_MASK                          0x0700
#define RG_PCHR_TOLTC_SHIFT                         8

#define RG_PCHR_TOHTC_OFFSET                        CON3_MIXED_OFFSET
#define RG_PCHR_TOHTC_MASK                          0x0007
#define RG_PCHR_TOHTC_SHIFT                         0

#define RG_CSDAC_DLY_OFFSET                         CON4_MIXED_OFFSET
#define RG_CSDAC_DLY_MASK                           0x7000
#define RG_CSDAC_DLY_SHIFT                          12

#define RG_CSDAC_STP_OFFSET                         CON4_MIXED_OFFSET
#define RG_CSDAC_STP_MASK                           0x0700
#define RG_CSDAC_STP_SHIFT                          8

#define RG_CSDAC_STP_DEC_OFFSET                     CON4_MIXED_OFFSET
#define RG_CSDAC_STP_DEC_MASK                       0x0070
#define RG_CSDAC_STP_DEC_SHIFT                      4

#define RG_CSDAC_STP_INC_OFFSET                     CON4_MIXED_OFFSET
#define RG_CSDAC_STP_INC_MASK                       0x0007
#define RG_CSDAC_STP_INC_SHIFT                      0

#define RGS_BATON_UNDET_OFFSET                      CON5_MIXED_OFFSET
#define RGS_BATON_UNDET_MASK                        0x0400
#define RGS_BATON_UNDET_SHIFT                       10

#define RG_BATON_HT_EN_OFFSET                       CON5_MIXED_OFFSET
#define RG_BATON_HT_EN_MASK                         0x0200
#define RG_BATON_HT_EN_SHIFT                        9

#define RG_BATON_EN_OFFSET                          CON5_MIXED_OFFSET
#define RG_BATON_EN_MASK                            0x0100
#define RG_BATON_EN_SHIFT                           8

#define RG_VBAT_OV_VTH_OFFSET                       CON5_MIXED_OFFSET
#define RG_VBAT_OV_VTH_MASK                         0x0030
#define RG_VBAT_OV_VTH_SHIFT                        4

#define RGS_VBAT_OV_DET_OFFSET                      CON5_MIXED_OFFSET
#define RGS_VBAT_OV_DET_MASK                        0x0008
#define RGS_VBAT_OV_DET_SHIFT                       3

#define RG_VBAT_OV_DEG_OFFSET                       CON5_MIXED_OFFSET
#define RG_VBAT_OV_DEG_MASK                         0x0002
#define RG_VBAT_OV_DEG_SHIFT                        1

#define RG_VBAT_OV_EN_OFFSET                        CON5_MIXED_OFFSET
#define RG_VBAT_OV_EN_MASK                          0x0001
#define RG_VBAT_OV_EN_SHIFT                         0

#define RG_CSDAC_DATA_OFFSET                        CON6_MIXED_OFFSET
#define RG_CSDAC_DATA_MASK                          0x03FF
#define RG_CSDAC_DATA_SHIFT                         0

#define RG_PCHR_FT_CTRL_OFFSET                      CON7_MIXED_OFFSET
#define RG_PCHR_FT_CTRL_MASK                        0x0700
#define RG_PCHR_FT_CTRL_SHIFT                       8

#define RG_PCHR_RST_OFFSET                          CON7_MIXED_OFFSET
#define RG_PCHR_RST_MASK                            0x0040
#define RG_PCHR_RST_SHIFT                           6

#define RG_CSDAC_TESTMODE_OFFSET                    CON7_MIXED_OFFSET
#define RG_CSDAC_TESTMODE_MASK                      0x0020
#define RG_CSDAC_TESTMODE_SHIFT                     5

#define RG_PCHR_TESTMODE_OFFSET                     CON7_MIXED_OFFSET
#define RG_PCHR_TESTMODE_MASK                       0x0010
#define RG_PCHR_TESTMODE_SHIFT                      4

#define RGS_OTG_BVALID_DET_OFFSET                   CON7_MIXED_OFFSET
#define RGS_OTG_BVALID_DET_MASK                     0x0008
#define RGS_OTG_BVALID_DET_SHIFT                    3

#define RG_OTG_BVALID_EN_OFFSET                     CON7_MIXED_OFFSET
#define RG_OTG_BVALID_EN_MASK                       0x0001
#define RG_OTG_BVALID_EN_SHIFT                      0

#define RG_PCHR_FLAG_SEL_OFFSET                     CON8_MIXED_OFFSET
#define RG_PCHR_FLAG_SEL_MASK                       0x3F00
#define RG_PCHR_FLAG_SEL_SHIFT                      8

#define RG_PCHR_FLAG_EN_OFFSET                      CON8_MIXED_OFFSET
#define RG_PCHR_FLAG_EN_MASK                        0x0080
#define RG_PCHR_FLAG_EN_SHIFT                       7

#define RGS_PCHR_FLAG_OUT_OFFSET                    CON8_MIXED_OFFSET
#define RGS_PCHR_FLAG_OUT_MASK                      0x000F
#define RGS_PCHR_FLAG_OUT_SHIFT                     0

#define RGS_CHRWDT_OUT_OFFSET                       CON9_MIXED_OFFSET
#define RGS_CHRWDT_OUT_MASK                         0x8000
#define RGS_CHRWDT_OUT_SHIFT                        15

#define CHRWDT_FLAG_WR_OFFSET                       CON9_MIXED_OFFSET
#define CHRWDT_FLAG_WR_MASK                         0x0200
#define CHRWDT_FLAG_WR_SHIFT                        9

#define CHRWDT_INT_EN_OFFSET                        CON9_MIXED_OFFSET
#define CHRWDT_INT_EN_MASK                          0x0100
#define CHRWDT_INT_EN_SHIFT                         8

#define RG_CHRWDT_WR_OFFSET                         CON9_MIXED_OFFSET
#define RG_CHRWDT_WR_MASK                           0x0020
#define RG_CHRWDT_WR_SHIFT                          5

#define RG_CHRWDT_EN_OFFSET                         CON9_MIXED_OFFSET
#define RG_CHRWDT_EN_MASK                           0x0010
#define RG_CHRWDT_EN_SHIFT                          4

#define RG_CHRWDT_TD_OFFSET                         CON9_MIXED_OFFSET
#define RG_CHRWDT_TD_MASK                           0x000F
#define RG_CHRWDT_TD_SHIFT                          0

#define RG_USBDL_SET_OFFSET                         CON10_MIXED_OFFSET
#define RG_USBDL_SET_MASK                           0x8000
#define RG_USBDL_SET_SHIFT                          15

#define RG_USBDL_RST_OFFSET                         CON10_MIXED_OFFSET
#define RG_USBDL_RST_MASK                           0x4000
#define RG_USBDL_RST_SHIFT                          14

#define RG_BGR_UNCHOP_OFFSET                        CON10_MIXED_OFFSET
#define RG_BGR_UNCHOP_MASK                          0x2000
#define RG_BGR_UNCHOP_SHIFT                         13

#define RG_BGR_UNCHOP_PH_OFFSET                     CON10_MIXED_OFFSET
#define RG_BGR_UNCHOP_PH_MASK                       0x1000
#define RG_BGR_UNCHOP_PH_SHIFT                      12

#define RG_BGR_RSEL_OFFSET                          CON10_MIXED_OFFSET
#define RG_BGR_RSEL_MASK                            0x0700
#define RG_BGR_RSEL_SHIFT                           8

#define RG_ADCIN_CHR_EN_OFFSET                      CON10_MIXED_OFFSET
#define RG_ADCIN_CHR_EN_MASK                        0x0040
#define RG_ADCIN_CHR_EN_SHIFT                       6

#define RG_ADCIN_VSEN_EN_OFFSET                     CON10_MIXED_OFFSET
#define RG_ADCIN_VSEN_EN_MASK                       0x0020
#define RG_ADCIN_VSEN_EN_SHIFT                      5

#define RG_ADCIN_VBAT_EN_OFFSET                     CON10_MIXED_OFFSET
#define RG_ADCIN_VBAT_EN_MASK                       0x0010
#define RG_ADCIN_VBAT_EN_SHIFT                      4

#define RG_UVLO_VTHL_OFFSET                         CON10_MIXED_OFFSET
#define RG_UVLO_VTHL_MASK                           0x0003
#define RG_UVLO_VTHL_SHIFT                          0

#define RGS_BC11_CMP_OUT_OFFSET                     CON11_MIXED_OFFSET
#define RGS_BC11_CMP_OUT_MASK                       0x8000
#define RGS_BC11_CMP_OUT_SHIFT                      15

#define RG_BC11_RST_OFFSET                          CON11_MIXED_OFFSET
#define RG_BC11_RST_MASK                            0x0800
#define RG_BC11_RST_SHIFT                           11

#define RG_BC11_BB_CTRL_OFFSET                      CON11_MIXED_OFFSET
#define RG_BC11_BB_CTRL_MASK                        0x0400
#define RG_BC11_BB_CTRL_SHIFT                       10

#define RG_BC11_BIAS_EN_OFFSET                      CON11_MIXED_OFFSET
#define RG_BC11_BIAS_EN_MASK                        0x0200
#define RG_BC11_BIAS_EN_SHIFT                       9

#define RG_BC11_VREF_VTH_OFFSET                     CON11_MIXED_OFFSET
#define RG_BC11_VREF_VTH_MASK                       0x0100
#define RG_BC11_VREF_VTH_SHIFT                      8

#define RG_BC11_IPU_EN_OFFSET                       CON11_MIXED_OFFSET
#define RG_BC11_IPU_EN_MASK                         0x00C0
#define RG_BC11_IPU_EN_SHIFT                        6

#define RG_BC11_IPD_EN_OFFSET                       CON11_MIXED_OFFSET
#define RG_BC11_IPD_EN_MASK                         0x0030
#define RG_BC11_IPD_EN_SHIFT                        4

#define RG_BC11_VSRC_EN_OFFSET                      CON11_MIXED_OFFSET
#define RG_BC11_VSRC_EN_MASK                        0x000C
#define RG_BC11_VSRC_EN_SHIFT                       2

#define RG_BC11_CMP_EN_OFFSET                       CON11_MIXED_OFFSET
#define RG_BC11_CMP_EN_MASK                         0x0003
#define RG_BC11_CMP_EN_SHIFT                        0

#define RG_LOW_ICH_DB_OFFSET                        CON12_MIXED_OFFSET
#define RG_LOW_ICH_DB_MASK                          0x3F00
#define RG_LOW_ICH_DB_SHIFT                         8

#define RG_ULC_DET_EN_OFFSET                        CON12_MIXED_OFFSET
#define RG_ULC_DET_EN_MASK                          0x0080
#define RG_ULC_DET_EN_SHIFT                         7

#define RG_HWCV_EN_OFFSET                           CON12_MIXED_OFFSET
#define RG_HWCV_EN_MASK                             0x0040
#define RG_HWCV_EN_SHIFT                            6

#define RG_TRACKING_EN_OFFSET                       CON12_MIXED_OFFSET
#define RG_TRACKING_EN_MASK                         0x0010
#define RG_TRACKING_EN_SHIFT                        4

#define RG_CSDAC_MODE_OFFSET                        CON12_MIXED_OFFSET
#define RG_CSDAC_MODE_MASK                          0x0004
#define RG_CSDAC_MODE_SHIFT                         2

#define RG_VCDT_MODE_OFFSET                         CON12_MIXED_OFFSET
#define RG_VCDT_MODE_MASK                           0x0002
#define RG_VCDT_MODE_SHIFT                          1

#define RG_CV_MODE_OFFSET                           CON12_MIXED_OFFSET
#define RG_CV_MODE_MASK                             0x0001
#define RG_CV_MODE_SHIFT                            0

#define RG_DRV_ITUNE_OFFSET                         CON13_MIXED_OFFSET
#define RG_DRV_ITUNE_MASK                           0x0300
#define RG_DRV_ITUNE_SHIFT                          8

#define RG_OVP_TRIM_OFFSET                          CON13_MIXED_OFFSET
#define RG_OVP_TRIM_MASK                            0x000F
#define RG_OVP_TRIM_SHIFT                           0

#define RG_PCHR_RV1_OFFSET                          CON14_MIXED_OFFSET
#define RG_PCHR_RV1_MASK                            0xFF00
#define RG_PCHR_RV1_SHIFT                           8

#define RG_PCHR_RV2_OFFSET                          CON14_MIXED_OFFSET
#define RG_PCHR_RV2_MASK                            0x00FF
#define RG_PCHR_RV2_SHIFT                           0

#define RG_AUTO_POWER_ON_OFFSET                     CON15_MIXED_OFFSET
#define RG_AUTO_POWER_ON_MASK                       0x8000
#define RG_AUTO_POWER_ON_SHIFT                      15

#define RG_DAC_USBDL_MAX_OFFSET                     CON15_MIXED_OFFSET
#define RG_DAC_USBDL_MAX_MASK                       0x03FF
#define RG_DAC_USBDL_MAX_SHIFT                      0

#define QI_PWRKEY_DEB_OFFSET                        CON0_MIXED_OFFSET
#define QI_PWRKEY_DEB_MASK                          0x8000
#define QI_PWRKEY_DEB_SHIFT                         15

#define QI_PWRKEY_VCORE_OFFSET                      CON0_MIXED_OFFSET
#define QI_PWRKEY_VCORE_MASK                        0x4000
#define QI_PWRKEY_VCORE_SHIFT                       14

#define QI_TEST_MODE_POR_OFFSET                     CON0_MIXED_OFFSET
#define QI_TEST_MODE_POR_MASK                       0x2000
#define QI_TEST_MODE_POR_SHIFT                      13

#define QI_USB_DL_MODE_OFFSET                       CON0_MIXED_OFFSET
#define QI_USB_DL_MODE_MASK                         0x1000
#define QI_USB_DL_MODE_SHIFT                        12

#define PMU_THR_PWROFF_OFFSET                       CON0_MIXED_OFFSET
#define PMU_THR_PWROFF_MASK                         0x0800
#define PMU_THR_PWROFF_SHIFT                        11

#define QI_PMU_THR_STATUS_OFFSET                    CON0_MIXED_OFFSET
#define QI_PMU_THR_STATUS_MASK                      0x0700
#define QI_PMU_THR_STATUS_SHIFT                     8

#define RG_USBDL_EN_OFFSET                          CON0_MIXED_OFFSET
#define RG_USBDL_EN_MASK                            0x0010
#define RG_USBDL_EN_SHIFT                           4

#define THR_HWPDN_EN_OFFSET                         CON0_MIXED_OFFSET
#define THR_HWPDN_EN_MASK                           0x0008
#define THR_HWPDN_EN_SHIFT                          3

#define RG_THERMAL_DIS_OFFSET                       CON0_MIXED_OFFSET
#define RG_THERMAL_DIS_MASK                         0x0004
#define RG_THERMAL_DIS_SHIFT                        2

#define RG_THR_SEL_OFFSET                           CON0_MIXED_OFFSET
#define RG_THR_SEL_MASK                             0x0003
#define RG_THR_SEL_SHIFT                            0

#define RG_BIAS_GEN_FORCE_OFFSET                    CON1_MIXED_OFFSET
#define RG_BIAS_GEN_FORCE_MASK                      0x4000
#define RG_BIAS_GEN_FORCE_SHIFT                     14

#define RG_PMU_LEV_UNGATE_OFFSET                    CON1_MIXED_OFFSET
#define RG_PMU_LEV_UNGATE_MASK                      0x0100
#define RG_PMU_LEV_UNGATE_SHIFT                     8

#define RG_RST_DRVSEL_OFFSET                        CON1_MIXED_OFFSET
#define RG_RST_DRVSEL_MASK                          0x0020
#define RG_RST_DRVSEL_SHIFT                         5

#define RG_STRUP_TEST_OFFSET                        CON1_MIXED_OFFSET
#define RG_STRUP_TEST_MASK                          0x0010
#define RG_STRUP_TEST_SHIFT                         4

#define RG_PMU_PGDET_DIS_OFFSET                     CON1_MIXED_OFFSET
#define RG_PMU_PGDET_DIS_MASK                       0x0008
#define RG_PMU_PGDET_DIS_SHIFT                      3

#define RG_VREF_BG_OFFSET                           CON1_MIXED_OFFSET
#define RG_VREF_BG_MASK                             0x0007
#define RG_VREF_BG_SHIFT                            0

#define QI_STRUP_FLAG_OUT_OFFSET                    CON2_MIXED_OFFSET
#define QI_STRUP_FLAG_OUT_MASK                      0x0F00
#define QI_STRUP_FLAG_OUT_SHIFT                     8

#define RG_STRUP_FLAG_EN_OFFSET                     CON2_MIXED_OFFSET
#define RG_STRUP_FLAG_EN_MASK                       0x0080
#define RG_STRUP_FLAG_EN_SHIFT                      7

#define RG_STRUP_FLAG_SEL_OFFSET                    CON2_MIXED_OFFSET
#define RG_STRUP_FLAG_SEL_MASK                      0x000F
#define RG_STRUP_FLAG_SEL_SHIFT                     0

#define RG_ESDDEG_DLYSEL_OFFSET                     CON3_MIXED_OFFSET
#define RG_ESDDEG_DLYSEL_MASK                       0x000E
#define RG_ESDDEG_DLYSEL_SHIFT                      1

#define RG_ESDDEG_EN_OFFSET                         CON3_MIXED_OFFSET
#define RG_ESDDEG_EN_MASK                           0x0001
#define RG_ESDDEG_EN_SHIFT                          0

#define RG_STRUP_RSV_OFFSET                         CON4_MIXED_OFFSET
#define RG_STRUP_RSV_MASK                           0x3FFF
#define RG_STRUP_RSV_SHIFT                          0

#define THRDET_SEL_OFFSET                           CON0_MIXED_OFFSET
#define THRDET_SEL_MASK                             0x0010
#define THRDET_SEL_SHIFT                            4

#define INT_NODE_MUX_OFFSET                         CON0_MIXED_OFFSET
#define INT_NODE_MUX_MASK                           0x0007
#define INT_NODE_MUX_SHIFT                          0

#define RG_IBIAS_TRIM_OFFSET                        CON1_MIXED_OFFSET
#define RG_IBIAS_TRIM_MASK                          0x0F00
#define RG_IBIAS_TRIM_SHIFT                         8

#define TP_BUCK_OFFSET                              CON1_MIXED_OFFSET
#define TP_BUCK_MASK                                0x0030
#define TP_BUCK_SHIFT                               4

#define RG_TP_LED_OFFSET                            CON1_MIXED_OFFSET
#define RG_TP_LED_MASK                              0x000F
#define RG_TP_LED_SHIFT                             0

#define TESTMODE_RSV_OFFSET                         CON2_MIXED_OFFSET
#define TESTMODE_RSV_MASK                           0xFC00
#define TESTMODE_RSV_SHIFT                          10

#define RG_SV12_TMODE_OFFSET                        CON2_MIXED_OFFSET
#define RG_SV12_TMODE_MASK                          0x0200
#define RG_SV12_TMODE_SHIFT                         9

#define RG_THR_TMODE_OFFSET                         CON2_MIXED_OFFSET
#define RG_THR_TMODE_MASK                           0x0100
#define RG_THR_TMODE_SHIFT                          8

#define RG_IBIAS_TRIM_EN_OFFSET                     CON2_MIXED_OFFSET
#define RG_IBIAS_TRIM_EN_MASK                       0x0020
#define RG_IBIAS_TRIM_EN_SHIFT                      5

#define RG_THERMAL_TEST_OFFSET                      CON2_MIXED_OFFSET
#define RG_THERMAL_TEST_MASK                        0x0003
#define RG_THERMAL_TEST_SHIFT                       0

#define BP_OLT_CTRL_OFFSET                          CON3_MIXED_OFFSET
#define BP_OLT_CTRL_MASK                            0x0002
#define BP_OLT_CTRL_SHIFT                           1

#define BOOST_CKS_CHG_OFFSET                        CON3_MIXED_OFFSET
#define BOOST_CKS_CHG_MASK                          0x8000
#define BOOST_CKS_CHG_SHIFT                         15

#define BOOST_CKS_PRG_OFFSET                        CON3_MIXED_OFFSET
#define BOOST_CKS_PRG_MASK                          0x003F
#define BOOST_CKS_PRG_SHIFT                         0

#define RG_ISINKS_RSV_OFFSET                        CON0_MIXED_OFFSET
#define RG_ISINKS_RSV_MASK                          0x0C00
#define RG_ISINKS_RSV_SHIFT                         10

#define RG_ISINKS_STEP_DOUBLE_OFFSET                CON0_MIXED_OFFSET
#define RG_ISINKS_STEP_DOUBLE_MASK                  0x0200
#define RG_ISINKS_STEP_DOUBLE_SHIFT                 9

#define RG_ISINK_TEST_MODE_OFFSET                   CON0_MIXED_OFFSET
#define RG_ISINK_TEST_MODE_MASK                     0x0100
#define RG_ISINK_TEST_MODE_SHIFT                    8

#define ISINK_STP_TC_OFFSET                         CON0_MIXED_OFFSET
#define ISINK_STP_TC_MASK                           0x000C
#define ISINK_STP_TC_SHIFT                          2

#define ISINK_PHASE_MODE_OFFSET                     CON0_MIXED_OFFSET
#define ISINK_PHASE_MODE_MASK                       0x0002
#define ISINK_PHASE_MODE_SHIFT                      1

#define ISINKS_FORCE_OFF_OFFSET                     CON0_MIXED_OFFSET
#define ISINKS_FORCE_OFF_MASK                       0x0001
#define ISINKS_FORCE_OFF_SHIFT                      0

#define RG_ISINKS_VREF_CAL_OFFSET                   CON1_MIXED_OFFSET
#define RG_ISINKS_VREF_CAL_MASK                     0x001F
#define RG_ISINKS_VREF_CAL_SHIFT                    0

#define RG_ISINKS_TRIM_SEL_OFFSET                   CON2_MIXED_OFFSET
#define RG_ISINKS_TRIM_SEL_MASK                     0x0700
#define RG_ISINKS_TRIM_SEL_SHIFT                    8

#define RG_ISINKS_TRIM_EN_OFFSET                    CON2_MIXED_OFFSET
#define RG_ISINKS_TRIM_EN_MASK                      0x0001
#define RG_ISINKS_TRIM_EN_SHIFT                     0

#define QI_ISINK0_STATUS_OFFSET                     CON0_MIXED_OFFSET
#define QI_ISINK0_STATUS_MASK                       0x8000
#define QI_ISINK0_STATUS_SHIFT                      15

#define RG_ISINK0_CLKSEL_OFFSET                     CON0_MIXED_OFFSET
#define RG_ISINK0_CLKSEL_MASK                       0x2000
#define RG_ISINK0_CLKSEL_SHIFT                      13

#define ISINK0_CLKSEL_MODE_OFFSET                   CON0_MIXED_OFFSET
#define ISINK0_CLKSEL_MODE_MASK                     0x1000
#define ISINK0_CLKSEL_MODE_SHIFT                    12

#define RG_ISINKS_CH0_STEP_OFFSET                   CON0_MIXED_OFFSET
#define RG_ISINKS_CH0_STEP_MASK                     0x0070
#define RG_ISINKS_CH0_STEP_SHIFT                    4

#define RG_ISINK0_CHOP_ENB_OFFSET                   CON0_MIXED_OFFSET
#define RG_ISINK0_CHOP_ENB_MASK                     0x0004
#define RG_ISINK0_CHOP_ENB_SHIFT                    2

#define ISINK0_MODE_OFFSET                          CON0_MIXED_OFFSET
#define ISINK0_MODE_MASK                            0x0002
#define ISINK0_MODE_SHIFT                           1

#define RG_ISINKS_CH0_EN_OFFSET                     CON0_MIXED_OFFSET
#define RG_ISINKS_CH0_EN_MASK                       0x0001
#define RG_ISINKS_CH0_EN_SHIFT                      0

#define QI_ISINK1_STATUS_OFFSET                     CON0_MIXED_OFFSET
#define QI_ISINK1_STATUS_MASK                       0x8000
#define QI_ISINK1_STATUS_SHIFT                      15

#define RG_ISINK1_CLKSEL_OFFSET                     CON0_MIXED_OFFSET
#define RG_ISINK1_CLKSEL_MASK                       0x2000
#define RG_ISINK1_CLKSEL_SHIFT                      13

#define ISINK1_CLKSEL_MODE_OFFSET                   CON0_MIXED_OFFSET
#define ISINK1_CLKSEL_MODE_MASK                     0x1000
#define ISINK1_CLKSEL_MODE_SHIFT                    12

#define RG_ISINKS_CH1_STEP_OFFSET                   CON0_MIXED_OFFSET
#define RG_ISINKS_CH1_STEP_MASK                     0x0070
#define RG_ISINKS_CH1_STEP_SHIFT                    4

#define RG_ISINK1_CHOP_ENB_OFFSET                   CON0_MIXED_OFFSET
#define RG_ISINK1_CHOP_ENB_MASK                     0x0004
#define RG_ISINK1_CHOP_ENB_SHIFT                    2

#define ISINK1_MODE_OFFSET                          CON0_MIXED_OFFSET
#define ISINK1_MODE_MASK                            0x0002
#define ISINK1_MODE_SHIFT                           1

#define RG_ISINKS_CH1_EN_OFFSET                     CON0_MIXED_OFFSET
#define RG_ISINKS_CH1_EN_MASK                       0x0001
#define RG_ISINKS_CH1_EN_SHIFT                      0

#define QI_ISINK2_STATUS_OFFSET                     CON0_MIXED_OFFSET
#define QI_ISINK2_STATUS_MASK                       0x8000
#define QI_ISINK2_STATUS_SHIFT                      15

#define RG_ISINK2_CLKSEL_OFFSET                     CON0_MIXED_OFFSET
#define RG_ISINK2_CLKSEL_MASK                       0x2000
#define RG_ISINK2_CLKSEL_SHIFT                      13

#define ISINK2_CLKSEL_MODE_OFFSET                   CON0_MIXED_OFFSET
#define ISINK2_CLKSEL_MODE_MASK                     0x1000
#define ISINK2_CLKSEL_MODE_SHIFT                    12

#define RG_ISINKS_CH2_STEP_OFFSET                   CON0_MIXED_OFFSET
#define RG_ISINKS_CH2_STEP_MASK                     0x0070
#define RG_ISINKS_CH2_STEP_SHIFT                    4

#define RG_ISINK2_CHOP_ENB_OFFSET                   CON0_MIXED_OFFSET
#define RG_ISINK2_CHOP_ENB_MASK                     0x0004
#define RG_ISINK2_CHOP_ENB_SHIFT                    2

#define ISINK2_MODE_OFFSET                          CON0_MIXED_OFFSET
#define ISINK2_MODE_MASK                            0x0002
#define ISINK2_MODE_SHIFT                           1

#define RG_ISINKS_CH2_EN_OFFSET                     CON0_MIXED_OFFSET
#define RG_ISINKS_CH2_EN_MASK                       0x0001
#define RG_ISINKS_CH2_EN_SHIFT                      0

#define QI_ISINK3_STATUS_OFFSET                     CON0_MIXED_OFFSET
#define QI_ISINK3_STATUS_MASK                       0x8000
#define QI_ISINK3_STATUS_SHIFT                      15

#define RG_ISINK3_CLKSEL_OFFSET                     CON0_MIXED_OFFSET
#define RG_ISINK3_CLKSEL_MASK                       0x2000
#define RG_ISINK3_CLKSEL_SHIFT                      13

#define ISINK3_CLKSEL_MODE_OFFSET                   CON0_MIXED_OFFSET
#define ISINK3_CLKSEL_MODE_MASK                     0x1000
#define ISINK3_CLKSEL_MODE_SHIFT                    12

#define RG_ISINKS_CH3_STEP_OFFSET                   CON0_MIXED_OFFSET
#define RG_ISINKS_CH3_STEP_MASK                     0x0070
#define RG_ISINKS_CH3_STEP_SHIFT                    4

#define RG_ISINK3_CHOP_ENB_OFFSET                   CON0_MIXED_OFFSET
#define RG_ISINK3_CHOP_ENB_MASK                     0x0004
#define RG_ISINK3_CHOP_ENB_SHIFT                    2

#define ISINK3_MODE_OFFSET                          CON0_MIXED_OFFSET
#define ISINK3_MODE_MASK                            0x0002
#define ISINK3_MODE_SHIFT                           1

#define RG_ISINKS_CH3_EN_OFFSET                     CON0_MIXED_OFFSET
#define RG_ISINKS_CH3_EN_MASK                       0x0001
#define RG_ISINKS_CH3_EN_SHIFT                      0

#define QI_KPLED_STATUS_OFFSET                      CON0_MIXED_OFFSET
#define QI_KPLED_STATUS_MASK                        0x8000
#define QI_KPLED_STATUS_SHIFT                       15

#define KPLED_SFSTREN_OFFSET                        CON0_MIXED_OFFSET
#define KPLED_SFSTREN_MASK                          0x0400
#define KPLED_SFSTREN_SHIFT                         10

#define KPLED_SFSTRTC_OFFSET                        CON0_MIXED_OFFSET
#define KPLED_SFSTRTC_MASK                          0x0300
#define KPLED_SFSTRTC_SHIFT                         8

#define RG_KPLED_SEL_OFFSET                         CON0_MIXED_OFFSET
#define RG_KPLED_SEL_MASK                           0x0070
#define RG_KPLED_SEL_SHIFT                          4

#define KPLED_MODE_OFFSET                           CON0_MIXED_OFFSET
#define KPLED_MODE_MASK                             0x0002
#define KPLED_MODE_SHIFT                            1

#define RG_KPLED_EN_OFFSET                          CON0_MIXED_OFFSET
#define RG_KPLED_EN_MASK                            0x0001
#define RG_KPLED_EN_SHIFT                           0

#define SPK_OC_FLAG_OFFSET                          CON0_MIXED_OFFSET
#define SPK_OC_FLAG_MASK                            0x4000
#define SPK_OC_FLAG_SHIFT                           14

#define SPK_OC_AUTOFF_OFFSET                        CON0_MIXED_OFFSET
#define SPK_OC_AUTOFF_MASK                          0x1000
#define SPK_OC_AUTOFF_SHIFT                         12

#define RG_SPK_VOL_OFFSET                           CON0_MIXED_OFFSET
#define RG_SPK_VOL_MASK                             0x0030
#define RG_SPK_VOL_SHIFT                            4

#define RG_SPK_EN_OFFSET                            CON0_MIXED_OFFSET
#define RG_SPK_EN_MASK                              0x0001
#define RG_SPK_EN_SHIFT                             0

#define RG_SPK_IN_FLOAT_B_OFFSET                    CON3_MIXED_OFFSET
#define RG_SPK_IN_FLOAT_B_MASK                      0x4000
#define RG_SPK_IN_FLOAT_B_SHIFT                     14

#define RG_SPK_IN_TIE_HIGH_OFFSET                   CON3_MIXED_OFFSET
#define RG_SPK_IN_TIE_HIGH_MASK                     0x1000
#define RG_SPK_IN_TIE_HIGH_SHIFT                    12

#define RG_SPK_OUT_FLOAT_B_OFFSET                   CON3_MIXED_OFFSET
#define RG_SPK_OUT_FLOAT_B_MASK                     0x0800
#define RG_SPK_OUT_FLOAT_B_SHIFT                    11

#define SPK_OC_CTRL_OFFSET                          CON3_MIXED_OFFSET
#define SPK_OC_CTRL_MASK                            0x000C
#define SPK_OC_CTRL_SHIFT                           2

#define RG_SPK_RSV_OFFSET                           CON6_MIXED_OFFSET
#define RG_SPK_RSV_MASK                             0x0F00
#define RG_SPK_RSV_SHIFT                            8

#define RG_SPK_PBIAS_OFFSET                         CON7_MIXED_OFFSET
#define RG_SPK_PBIAS_MASK                           0x0400
#define RG_SPK_PBIAS_SHIFT                          10

#define RG_SPK_OC_EN_OFFSET                         CON7_MIXED_OFFSET
#define RG_SPK_OC_EN_MASK                           0x0100
#define RG_SPK_OC_EN_SHIFT                          8

#define RG_SPK_VCM_SEL_OFFSET                       CON7_MIXED_OFFSET
#define RG_SPK_VCM_SEL_MASK                         0x0080
#define RG_SPK_VCM_SEL_SHIFT                        7

#define RG_VCM_IBSEL_OFFSET                         CON7_MIXED_OFFSET
#define RG_VCM_IBSEL_MASK                           0x0040
#define RG_VCM_IBSEL_SHIFT                          6

#define RG_SPK_OBIAS_OFFSET                         CON7_MIXED_OFFSET
#define RG_SPK_OBIAS_MASK                           0x0030
#define RG_SPK_OBIAS_SHIFT                          4

#define RG_SPK_CALIBR_SEL_OFFSET                    CON8_MIXED_OFFSET
#define RG_SPK_CALIBR_SEL_MASK                      0x0200
#define RG_SPK_CALIBR_SEL_SHIFT                     9

#define RG_SPK_CALIBR_EN_OFFSET                     CON8_MIXED_OFFSET
#define RG_SPK_CALIBR_EN_MASK                       0x0040
#define RG_SPK_CALIBR_EN_SHIFT                      6

#define RG_SPK_CHANNELSEL_OFFSET                    CON8_MIXED_OFFSET
#define RG_SPK_CHANNELSEL_MASK                      0x000C
#define RG_SPK_CHANNELSEL_SHIFT                     2

#define PMIC_RSV0_OFFSET                            CON0_MIXED_OFFSET
#define PMIC_RSV0_MASK                              0xFFFF
#define PMIC_RSV0_SHIFT                             0

#define PMIC_RSV1_OFFSET                            CON1_MIXED_OFFSET
#define PMIC_RSV1_MASK                              0xFFFF
#define PMIC_RSV1_SHIFT                             0

#define PMIC_RSV2_OFFSET                            CON2_MIXED_OFFSET
#define PMIC_RSV2_MASK                              0xFFFF
#define PMIC_RSV2_SHIFT                             0

#define PMIC_RSV3_OFFSET                            CON3_MIXED_OFFSET
#define PMIC_RSV3_MASK                              0xFFFF
#define PMIC_RSV3_SHIFT                             0

#define ISINK_CH3_STP_MODE_OFFSET                   CON4_MIXED_OFFSET
#define ISINK_CH3_STP_MODE_MASK                     0x8000
#define ISINK_CH3_STP_MODE_SHIFT                    15

#define ISINK_CH2_STP_MODE_OFFSET                   CON4_MIXED_OFFSET
#define ISINK_CH2_STP_MODE_MASK                     0x4000
#define ISINK_CH2_STP_MODE_SHIFT                    14

#define ISINK_CH1_STP_MODE_OFFSET                   CON4_MIXED_OFFSET
#define ISINK_CH1_STP_MODE_MASK                     0x2000
#define ISINK_CH1_STP_MODE_SHIFT                    13

#define ISINK_CH0_STP_MODE_OFFSET                   CON4_MIXED_OFFSET
#define ISINK_CH0_STP_MODE_MASK                     0x1000
#define ISINK_CH0_STP_MODE_SHIFT                    12

#define PMIC_RSV4_OFFSET                            CON4_MIXED_OFFSET
#define PMIC_RSV4_MASK                              0x0FFF
#define PMIC_RSV4_SHIFT                             0

#define PMIC_RSV5_OFFSET                            CON5_MIXED_OFFSET
#define PMIC_RSV5_MASK                              0xFFFF
#define PMIC_RSV5_SHIFT                             0

#define GSM_DCXO_CTL_EN_OFFSET                      CON0_MIXED_OFFSET
#define GSM_DCXO_CTL_EN_MASK                        0x0400
#define GSM_DCXO_CTL_EN_SHIFT                       10

#define BT_DCXO_CTL_EN_OFFSET                       CON0_MIXED_OFFSET
#define BT_DCXO_CTL_EN_MASK                         0x0200
#define BT_DCXO_CTL_EN_SHIFT                        9

#define EXT_DCXO_CTL_EN_OFFSET                      CON0_MIXED_OFFSET
#define EXT_DCXO_CTL_EN_MASK                        0x0100
#define EXT_DCXO_CTL_EN_SHIFT                       8

#define BUF1_COCLK_EN_OFFSET                        CON0_MIXED_OFFSET
#define BUF1_COCLK_EN_MASK                          0x0020
#define BUF1_COCLK_EN_SHIFT                         5

#define FRC_BB26MCK_EN_OFFSET                       CON0_MIXED_OFFSET
#define FRC_BB26MCK_EN_MASK                         0x0010
#define FRC_BB26MCK_EN_SHIFT                        4

#define FRC_DCXO_F26M_RDY_OFFSET                    CON0_MIXED_OFFSET
#define FRC_DCXO_F26M_RDY_MASK                      0x0008
#define FRC_DCXO_F26M_RDY_SHIFT                     3

#define FRC_GSM_SGLSTGE_OFFSET                      CON0_MIXED_OFFSET
#define FRC_GSM_SGLSTGE_MASK                        0x0004
#define FRC_GSM_SGLSTGE_SHIFT                       2

#define FRC_BT_SGLSTGE_OFFSET                       CON0_MIXED_OFFSET
#define FRC_BT_SGLSTGE_MASK                         0x0002
#define FRC_BT_SGLSTGE_SHIFT                        1

#define FRC_EXT_SGLSTGE_OFFSET                      CON0_MIXED_OFFSET
#define FRC_EXT_SGLSTGE_MASK                        0x0001
#define FRC_EXT_SGLSTGE_SHIFT                       0

#define DCXO_EN_TD_OFFSET                           CON1_MIXED_OFFSET
#define DCXO_EN_TD_MASK                             0xFF00
#define DCXO_EN_TD_SHIFT                            8

#define DCXO_BUF_EN_TD_OFFSET                       CON1_MIXED_OFFSET
#define DCXO_BUF_EN_TD_MASK                         0x00FF
#define DCXO_BUF_EN_TD_SHIFT                        0

#define DCXO_RDY_TD_OFFSET                          CON2_MIXED_OFFSET
#define DCXO_RDY_TD_MASK                            0xFF00
#define DCXO_RDY_TD_SHIFT                           8

#define EXT_BUF2_EN_OFFSET                          CON2_MIXED_OFFSET
#define EXT_BUF2_EN_MASK                            0x0002
#define EXT_BUF2_EN_SHIFT                           1

#define EXT_BUF1_EN_OFFSET                          CON2_MIXED_OFFSET
#define EXT_BUF1_EN_MASK                            0x0001
#define EXT_BUF1_EN_SHIFT                           0

#define FPM_CNT_RST_OFFSET                          CON3_MIXED_OFFSET
#define FPM_CNT_RST_MASK                            0x1000
#define FPM_CNT_RST_SHIFT                           12

#define DCXO_CON_RSV1_OFFSET                        CON3_MIXED_OFFSET
#define DCXO_CON_RSV1_MASK                          0x00F8
#define DCXO_CON_RSV1_SHIFT                         3

#define BUF2_COCLK_EN_OFFSET                        CON3_MIXED_OFFSET
#define BUF2_COCLK_EN_MASK                          0x0004
#define BUF2_COCLK_EN_SHIFT                         2

#define DCXO_CON_RSV0_OFFSET                        CON3_MIXED_OFFSET
#define DCXO_CON_RSV0_MASK                          0x0003
#define DCXO_CON_RSV0_SHIFT                         0

#define FQMTR_BUSY_OFFSET                           CON0_MIXED_OFFSET
#define FQMTR_BUSY_MASK                             0x8000
#define FQMTR_BUSY_SHIFT                            15

#define FQMTR_EN_OFFSET                             CON0_MIXED_OFFSET
#define FQMTR_EN_MASK                               0x4000
#define FQMTR_EN_SHIFT                              14

#define FQMTR_RST_OFFSET                            CON0_MIXED_OFFSET
#define FQMTR_RST_MASK                              0x2000
#define FQMTR_RST_SHIFT                             13

#define FQMTR_MODE_OFFSET                           CON0_MIXED_OFFSET
#define FQMTR_MODE_MASK                             0x1000
#define FQMTR_MODE_SHIFT                            12

#define FQMTR_RSV_OFFSET                            CON1_MIXED_OFFSET
#define FQMTR_RSV_MASK                              0x0F00
#define FQMTR_RSV_SHIFT                             8

#define FQMTR_TCKSEL_OFFSET                         CON1_MIXED_OFFSET
#define FQMTR_TCKSEL_MASK                           0x0007
#define FQMTR_TCKSEL_SHIFT                          0

#define FQMTR_DATA_OFFSET                           CON2_MIXED_OFFSET
#define FQMTR_DATA_MASK                             0xFFFF
#define FQMTR_DATA_SHIFT                            0

#define FQMTR_WINSET_OFFSET                         CON3_MIXED_OFFSET
#define FQMTR_WINSET_MASK                           0xFFFF
#define FQMTR_WINSET_SHIFT                          0
