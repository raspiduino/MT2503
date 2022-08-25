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
 *    dcl_pmu6250_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for PMU6250 s/w setting.
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef __DCL_PMU6260_SW_H_STRUCT__
#define __DCL_PMU6260_SW_H_STRUCT__

#include "dcl_pmic_features.h"

#if defined(PMU_6260_REG_API)

/* Charger external interrupt is fixed. */
#define PMU_CHR_EINT_PIN         21
#define PMU_OC_EINT_PIN          22
#define PMU_CHR_OVP_EINT_PIN     23
#define PMU_CHR_LDO_EINT_PIN     24

/* adc number for measuring VBAT/VISENSE/VCHARGER is fixed internally. */
#define PMU_ADC_VBAT_CH_NUM      0
#define PMU_ADC_VISENSE_CH_NUM   1
#define PMU_ADC_VCHARGER_CH_NUM  2
#define PMU_ADC_VBATTEMP_CH_NUM  3

/* adc factor for VBAT/VISENSE/VCHARGER */
#define PMU_ADC_FACTOR_VBAT      100
#define PMU_ADC_FACTOR_VISENSE   100

#define PMU_ADC_FACTOR_VCHARGER  473  // (369/39 * 50)

#define PMU_ADC_FACTOR_VBATTEMP  50

#define LDO_GROUP (OFFSEL(BUCK_GROUP))
#define BUCK_GROUP (M(VCORE))

typedef enum
{
    LDO_BUCK_EN,
    LDO_BUCK_ON_SEL,
    LDO_BUCK_RS,
    LDO_BUCK_VOL_SEL,
    LDO_BUCK_NDIS_EN,
    LDO_BUCK_STB_SEL,
    LDO_BUCK_OC_AUTO_OFF,
    LDO_BUCK_OCFB_EN,
    LDO_BUCK_OC_FLAG,
    LDO_BUCK_STATUS,
    LDO_CAL,
    LDO_OC_TD,
    LDO_STB_TD,
    BUCK_VOSEL_SLEEP,
    BUCK_SFSTREN,
    ADC_EN,
    ISINK_EN,
    ISINK_MODE,
    ISINK_STEP,
#if defined(__MEUT__)
    ABIST_HMON_SEL,
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    ABIST_LMON_SEL,
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    ABIST_HMON_DATA,
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    ABIST_LMON_DATA,
#endif // End of #if defined(__MEUT__)
    C2A_SIM2SEL_SEL,
    CCI_C2A_SIM2_VOSEL,
    C2A_SIM1SEL_SEL,
    CCI_C2A_SIM1_VOSEL,
    CCI_SRCLKEN,
    QI_VA_LP_EN,
    VSIM1_GPLDO_EN,
    VSIM2_GPLDO_EN,
    QI_VSF_LP_EN,
    RG_VSF_IL_CAL,
    RG_VSF_AWL_EN,
    RG_VSF_COMP_EN,
    VCORE_SFSTREN,
#if defined(__MEUT__)
    SPK_OC_INT_EN,
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    SPK_OC_FLAG_WR,
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    QI_VSF_OC_STATUS,
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    QI_VMC_OC_STATUS,
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    QI_VIBR_OC_STATUS,
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    QI_VSIM2_OC_STATUS,
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    QI_VSIM1_OC_STATUS,
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    QI_VUSB_OC_STATUS,
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    QI_VIO28_OC_STATUS,
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    QI_VCAMD_OC_STATUS,
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    QI_VCAMA_OC_STATUS,
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    QI_VA_OC_STATUS,
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    QI_VRF_OC_STATUS,
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    QI_VIO18_OC_STATUS,
#endif // End of #if defined(__MEUT__)
    QI_VCORE_OC_STATUS,
#if defined(__MEUT__)
    NI_SPK_OC_DET,
#endif // End of #if defined(__MEUT__)
    ISINK_STP_TC,
    ISINK_PHASE_TC,
    ISINK0_STP_MODE,
    ISINK0_PHASE_MODE,
    ISINK1_STP_MODE,
    ISINK1_PHASE_MODE,
    ISINK2_STP_MODE,
    ISINK2_PHASE_MODE,
    ISINK3_STP_MODE,
    ISINK3_PHASE_MODE,
    KPLED_MODE,
    NI_KPLED_EN,
    RG_SPK_VOL,
    RG_SPK_EN,
    RG_SPK_OC_EN,
    RG_SPK_OBIAS,
    RG_SPK_CALIBR_SEL,
    RG_SPK_CALIBR_EN,
    RG_SPK_ISENSE_EN,
    RG_SPK_ISENSE_GAINSEL,
    RG_SPK_ISENSE_REFSEL,
    RG_SPK_ISENSE_TEST_EN,
    RG_VCP_BST_BP,
    RG_VCP_CLK_SEL,
    RGS_BC11_CMP_OUT,
    RG_BC11_BIAS_EN,
    RG_BC11_VREF_VTH,
    RG_BC11_IPU_EN,
    RG_BC11_IPD_EN,
    RG_BC11_VSRC_EN,
    RG_BC11_CMP_EN,
    PMU_COMMAND_MAX
}PMU_FLAGS_LIST_ENUM;

#endif // End of #if defined(PMU_6260_REG_API)

#endif // End of #ifndef __DCL_PMU6260_SW_H_STRUCT__
