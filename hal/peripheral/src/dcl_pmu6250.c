/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *    dcl_pmu6250.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for PMU 6250 driver.
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
#include "reg_base.h"
#include "drv_comm.h"
#include "init.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"
#include "custom_hw_default.h"
#include "device.h"

#if (defined(PMU_6250_REG_API))

#if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__)

#define BL_ISINK_LEVEL                          (PWM_MAX_BACKLIGHT_LEVEL)

#else

#define BL_ISINK_LEVEL                          (PWM_MAX_LEVEL)

#endif // End of #if defined(__MULTI_LEVEL_BACKLIGHT_SUPPORT__)

extern PMU_CONTROL_HANDLER pmu_control_handler;
DCL_UINT16 pmu_parameter_size = 0;

const PMU_MOD_BASEADDR_ENTRY pmu_ldo_bb_profile[]=
{
	{VRF,  		    VRF_CON0},
	{VTCXO,  		VTCXO_CON0},
	{VA,			VA_CON0},
	{VCAMA,			VCAMA_CON0},
	{VCAMD,			VCAMD_CON0},
	{VIO28,			VIO28_CON0},
	{VUSB,			VUSB_CON0},
	{VBT,			VBT_CON0},
	{VSIM1,			VSIM1_CON0},
	{VSIM2,			VSIM2_CON0},
	{VRTC,			VRTC_CON0},
	{VIBR,			VIBR_CON0},
	{VMC,			VMC_CON0},
	{VSF,			VSF_CON0},
	{VIO18,			VIO18_CON0},
	{VCORE,			VCORE_CON0},
};

DCL_UINT16 pmu_ldo_bb_size;

DCL_UINT8 pmuModtoIdx[PMU_LDO_BUCK_MAX];

const PMU_FLAG_TABLE_ENTRY pmu_flags_table[]=
{
    {LDO_BUCK_EN,                LDO_BUCK_EN_OFFSET,                 LDO_BUCK_EN_MASK,               LDO_BUCK_EN_SHIFT               },
    {LDO_BUCK_ON_SEL,            LDO_BUCK_ON_SEL_OFFSET,             LDO_BUCK_ON_SEL_MASK,           LDO_BUCK_ON_SEL_SHIFT           },
    {LDO_BUCK_RS,                LDO_BUCK_RS_OFFSET,                 LDO_BUCK_RS_MASK,               LDO_BUCK_RS_SHIFT               },
    {LDO_BUCK_VOL_SEL,           LDO_BUCK_VOL_SEL_OFFSET,            LDO_BUCK_VOL_SEL_MASK,          LDO_BUCK_VOL_SEL_SHIFT          },
    {LDO_BUCK_NDIS_EN,           LDO_BUCK_NDIS_EN_OFFSET,            LDO_BUCK_NDIS_EN_MASK,          LDO_BUCK_NDIS_EN_SHIFT          },
    {LDO_BUCK_STB_SEL,           LDO_BUCK_STB_SEL_OFFSET,            LDO_BUCK_STB_SEL_MASK,          LDO_BUCK_STB_SEL_SHIFT          },
    {LDO_BUCK_OC_AUTO_OFF,       LDO_BUCK_OC_AUTO_OFF_OFFSET,        LDO_BUCK_OC_AUTO_OFF_MASK,      LDO_BUCK_OC_AUTO_OFF_SHIFT      },
    {LDO_BUCK_OCFB_EN,           LDO_BUCK_OCFB_EN_OFFSET,            LDO_BUCK_OCFB_EN_MASK,          LDO_BUCK_OCFB_EN_SHIFT          },
    {LDO_BUCK_OC_FLAG,           LDO_BUCK_OC_FLAG_OFFSET,            LDO_BUCK_OC_FLAG_MASK,          LDO_BUCK_OC_FLAG_SHIFT          },
    {LDO_BUCK_STATUS,            LDO_BUCK_STATUS_OFFSET,             LDO_BUCK_STATUS_MASK,           LDO_BUCK_STATUS_SHIFT           },
    {LDO_CAL,                    LDO_CAL_OFFSET,                     LDO_CAL_MASK,                   LDO_CAL_SHIFT                   },
    {LDO_OC_TD,                  LDO_OC_TD_OFFSET,                   LDO_OC_TD_MASK,                 LDO_OC_TD_SHIFT                 },
    {LDO_STB_TD,                 LDO_STB_TD_OFFSET,                  LDO_STB_TD_MASK,                LDO_STB_TD_SHIFT                },
    {BUCK_VOSEL_SLEEP,           BUCK_VOSEL_SLEEP_OFFSET,            BUCK_VOSEL_SLEEP_MASK,          BUCK_VOSEL_SLEEP_SHIFT          },
    {BUCK_SFSTREN,               BUCK_SFSTREN_OFFSET,                BUCK_SFSTREN_MASK,              BUCK_SFSTREN_SHIFT              },
    {ADC_EN,                     ADC_EN_OFFSET,                      ADC_EN_MASK,                    ADC_EN_SHIFT                    },
    {ISINK_EN,                   ISINK_EN_OFFSET,                    ISINK_EN_MASK,                  ISINK_EN_SHIFT                  },
    {ISINK_MODE,                 ISINK_MODE_OFFSET,                  ISINK_MODE_MASK,                ISINK_MODE_SHIFT                },
    {ISINK_STEP,                 ISINK_STEP_OFFSET,                  ISINK_STEP_MASK,                ISINK_STEP_SHIFT                },
#if defined(__MEUT__)
    {ABIST_HMON_SEL,             ABIST_HMON_SEL_OFFSET,              ABIST_HMON_SEL_MASK,            ABIST_HMON_SEL_SHIFT            },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {ABIST_LMON_SEL,             ABIST_LMON_SEL_OFFSET,              ABIST_LMON_SEL_MASK,            ABIST_LMON_SEL_SHIFT            },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {ABIST_HMON_DATA,            ABIST_HMON_DATA_OFFSET,             ABIST_HMON_DATA_MASK,           ABIST_HMON_DATA_SHIFT           },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {ABIST_LMON_DATA,            ABIST_LMON_DATA_OFFSET,             ABIST_LMON_DATA_MASK,           ABIST_LMON_DATA_SHIFT           },
#endif // End of #if defined(__MEUT__)
    {C2A_SIM2SEL_SEL,            C2A_SIM2SEL_SEL_OFFSET,             C2A_SIM2SEL_SEL_MASK,           C2A_SIM2SEL_SEL_SHIFT           },
    {CCI_C2A_SIM2SEL,            CCI_C2A_SIM2SEL_OFFSET,             CCI_C2A_SIM2SEL_MASK,           CCI_C2A_SIM2SEL_SHIFT           },
    {C2A_SIM1SEL_SEL,            C2A_SIM1SEL_SEL_OFFSET,             C2A_SIM1SEL_SEL_MASK,           C2A_SIM1SEL_SEL_SHIFT           },
    {CCI_C2A_SIM1SEL,            CCI_C2A_SIM1SEL_OFFSET,             CCI_C2A_SIM1SEL_MASK,           CCI_C2A_SIM1SEL_SHIFT           },
    {CCI_SRCLKEN,                CCI_SRCLKEN_OFFSET,                 CCI_SRCLKEN_MASK,               CCI_SRCLKEN_SHIFT               },
    {RG_VA_LP_EN,                RG_VA_LP_EN_OFFSET,                 RG_VA_LP_EN_MASK,               RG_VA_LP_EN_SHIFT               },
    {VSIM1_GPLDO_EN,             VSIM1_GPLDO_EN_OFFSET,              VSIM1_GPLDO_EN_MASK,            VSIM1_GPLDO_EN_SHIFT            },
    {VSIM2_GPLDO_EN,             VSIM2_GPLDO_EN_OFFSET,              VSIM2_GPLDO_EN_MASK,            VSIM2_GPLDO_EN_SHIFT            },
    {ISINK_STP_EN,               ISINK_STP_EN_OFFSET,                ISINK_STP_EN_MASK,              ISINK_STP_EN_SHIFT              },
#if defined(__MEUT__)
    {VSF_OC_INT_EN,              VSF_OC_INT_EN_OFFSET,               VSF_OC_INT_EN_MASK,             VSF_OC_INT_EN_SHIFT             },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VMC_OC_INT_EN,              VMC_OC_INT_EN_OFFSET,               VMC_OC_INT_EN_MASK,             VMC_OC_INT_EN_SHIFT             },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VIBR_OC_INT_EN,             VIBR_OC_INT_EN_OFFSET,              VIBR_OC_INT_EN_MASK,            VIBR_OC_INT_EN_SHIFT            },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VRTC_OC_INT_EN,             VRTC_OC_INT_EN_OFFSET,              VRTC_OC_INT_EN_MASK,            VRTC_OC_INT_EN_SHIFT            },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VSIM2_OC_INT_EN,            VSIM2_OC_INT_EN_OFFSET,             VSIM2_OC_INT_EN_MASK,           VSIM2_OC_INT_EN_SHIFT           },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VSIM1_OC_INT_EN,            VSIM1_OC_INT_EN_OFFSET,             VSIM1_OC_INT_EN_MASK,           VSIM1_OC_INT_EN_SHIFT           },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VBT_OC_INT_EN,              VBT_OC_INT_EN_OFFSET,               VBT_OC_INT_EN_MASK,             VBT_OC_INT_EN_SHIFT             },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VUSB_OC_INT_EN,             VUSB_OC_INT_EN_OFFSET,              VUSB_OC_INT_EN_MASK,            VUSB_OC_INT_EN_SHIFT            },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VIO28_OC_INT_EN,            VIO28_OC_INT_EN_OFFSET,             VIO28_OC_INT_EN_MASK,           VIO28_OC_INT_EN_SHIFT           },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VCAMD_OC_INT_EN,            VCAMD_OC_INT_EN_OFFSET,             VCAMD_OC_INT_EN_MASK,           VCAMD_OC_INT_EN_SHIFT           },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VCAMA_OC_INT_EN,            VCAMA_OC_INT_EN_OFFSET,             VCAMA_OC_INT_EN_MASK,           VCAMA_OC_INT_EN_SHIFT           },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VA_OC_INT_EN,               VA_OC_INT_EN_OFFSET,                VA_OC_INT_EN_MASK,              VA_OC_INT_EN_SHIFT              },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VTCXO_OC_INT_EN,            VTCXO_OC_INT_EN_OFFSET,             VTCXO_OC_INT_EN_MASK,           VTCXO_OC_INT_EN_SHIFT           },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VRF_OC_INT_EN,              VRF_OC_INT_EN_OFFSET,               VRF_OC_INT_EN_MASK,             VRF_OC_INT_EN_SHIFT             },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VIO18_OC_INT_EN,            VIO18_OC_INT_EN_OFFSET,             VIO18_OC_INT_EN_MASK,           VIO18_OC_INT_EN_SHIFT           },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VCORE_OC_INT_EN,            VCORE_OC_INT_EN_OFFSET,             VCORE_OC_INT_EN_MASK,           VCORE_OC_INT_EN_SHIFT           },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {SPK_OC_INT_EN,              SPK_OC_INT_EN_OFFSET,               SPK_OC_INT_EN_MASK,             SPK_OC_INT_EN_SHIFT             },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VSF_OC_FLAG_WR,             VSF_OC_FLAG_WR_OFFSET,              VSF_OC_FLAG_WR_MASK,            VSF_OC_FLAG_WR_SHIFT            },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VMC_OC_FLAG_WR,             VMC_OC_FLAG_WR_OFFSET,              VMC_OC_FLAG_WR_MASK,            VMC_OC_FLAG_WR_SHIFT            },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VIBR_OC_FLAG_WR,            VIBR_OC_FLAG_WR_OFFSET,             VIBR_OC_FLAG_WR_MASK,           VIBR_OC_FLAG_WR_SHIFT           },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VRTC_OC_FLAG_WR,            VRTC_OC_FLAG_WR_OFFSET,             VRTC_OC_FLAG_WR_MASK,           VRTC_OC_FLAG_WR_SHIFT           },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VSIM2_OC_FLAG_WR,           VSIM2_OC_FLAG_WR_OFFSET,            VSIM2_OC_FLAG_WR_MASK,          VSIM2_OC_FLAG_WR_SHIFT          },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VSIM1_OC_FLAG_WR,           VSIM1_OC_FLAG_WR_OFFSET,            VSIM1_OC_FLAG_WR_MASK,          VSIM1_OC_FLAG_WR_SHIFT          },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VBT_OC_FLAG_WR,             VBT_OC_FLAG_WR_OFFSET,              VBT_OC_FLAG_WR_MASK,            VBT_OC_FLAG_WR_SHIFT            },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VUSB_OC_FLAG_WR,            VUSB_OC_FLAG_WR_OFFSET,             VUSB_OC_FLAG_WR_MASK,           VUSB_OC_FLAG_WR_SHIFT           },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VIO28_OC_FLAG_WR,           VIO28_OC_FLAG_WR_OFFSET,            VIO28_OC_FLAG_WR_MASK,          VIO28_OC_FLAG_WR_SHIFT          },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VCAMD_OC_FLAG_WR,           VCAMD_OC_FLAG_WR_OFFSET,            VCAMD_OC_FLAG_WR_MASK,          VCAMD_OC_FLAG_WR_SHIFT          },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VCAMA_OC_FLAG_WR,           VCAMA_OC_FLAG_WR_OFFSET,            VCAMA_OC_FLAG_WR_MASK,          VCAMA_OC_FLAG_WR_SHIFT          },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VA_OC_FLAG_WR,              VA_OC_FLAG_WR_OFFSET,               VA_OC_FLAG_WR_MASK,             VA_OC_FLAG_WR_SHIFT             },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VTCXO_OC_FLAG_WR,           VTCXO_OC_FLAG_WR_OFFSET,            VTCXO_OC_FLAG_WR_MASK,          VTCXO_OC_FLAG_WR_SHIFT          },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VRF_OC_FLAG_WR,             VRF_OC_FLAG_WR_OFFSET,              VRF_OC_FLAG_WR_MASK,            VRF_OC_FLAG_WR_SHIFT            },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VIO18_OC_FLAG_WR,           VIO18_OC_FLAG_WR_OFFSET,            VIO18_OC_FLAG_WR_MASK,          VIO18_OC_FLAG_WR_SHIFT          },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VCORE_OC_FLAG_WR,           VCORE_OC_FLAG_WR_OFFSET,            VCORE_OC_FLAG_WR_MASK,          VCORE_OC_FLAG_WR_SHIFT          },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {SPK_OC_FLAG_WR,             SPK_OC_FLAG_WR_OFFSET,              SPK_OC_FLAG_WR_MASK,            SPK_OC_FLAG_WR_SHIFT            },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {QI_VSF_OC_STATUS,           QI_VSF_OC_STATUS_OFFSET,            QI_VSF_OC_STATUS_MASK,          QI_VSF_OC_STATUS_SHIFT          },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {QI_VMC_OC_STATUS,           QI_VMC_OC_STATUS_OFFSET,            QI_VMC_OC_STATUS_MASK,          QI_VMC_OC_STATUS_SHIFT          },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {QI_VIBR_OC_STATUS,          QI_VIBR_OC_STATUS_OFFSET,           QI_VIBR_OC_STATUS_MASK,         QI_VIBR_OC_STATUS_SHIFT         },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {VRTC_OC_STATUS,             VRTC_OC_STATUS_OFFSET,              VRTC_OC_STATUS_MASK,            VRTC_OC_STATUS_SHIFT            },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {QI_VSIM2_OC_STATUS,         QI_VSIM2_OC_STATUS_OFFSET,          QI_VSIM2_OC_STATUS_MASK,        QI_VSIM2_OC_STATUS_SHIFT        },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {QI_VSIM1_OC_STATUS,         QI_VSIM1_OC_STATUS_OFFSET,          QI_VSIM1_OC_STATUS_MASK,        QI_VSIM1_OC_STATUS_SHIFT        },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {QI_VBT_OC_STATUS,           QI_VBT_OC_STATUS_OFFSET,            QI_VBT_OC_STATUS_MASK,          QI_VBT_OC_STATUS_SHIFT          },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {QI_VUSB_OC_STATUS,          QI_VUSB_OC_STATUS_OFFSET,           QI_VUSB_OC_STATUS_MASK,         QI_VUSB_OC_STATUS_SHIFT         },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {QI_VIO28_OC_STATUS,         QI_VIO28_OC_STATUS_OFFSET,          QI_VIO28_OC_STATUS_MASK,        QI_VIO28_OC_STATUS_SHIFT        },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {QI_VCAMD_OC_STATUS,         QI_VCAMD_OC_STATUS_OFFSET,          QI_VCAMD_OC_STATUS_MASK,        QI_VCAMD_OC_STATUS_SHIFT        },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {QI_VCAMA_OC_STATUS,         QI_VCAMA_OC_STATUS_OFFSET,          QI_VCAMA_OC_STATUS_MASK,        QI_VCAMA_OC_STATUS_SHIFT        },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {QI_VA_OC_STATUS,            QI_VA_OC_STATUS_OFFSET,             QI_VA_OC_STATUS_MASK,           QI_VA_OC_STATUS_SHIFT           },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {QI_VTCXO_OC_STATUS,         QI_VTCXO_OC_STATUS_OFFSET,          QI_VTCXO_OC_STATUS_MASK,        QI_VTCXO_OC_STATUS_SHIFT        },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {QI_VRF_OC_STATUS,           QI_VRF_OC_STATUS_OFFSET,            QI_VRF_OC_STATUS_MASK,          QI_VRF_OC_STATUS_SHIFT          },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {QI_VIO18_OC_STATUS,         QI_VIO18_OC_STATUS_OFFSET,          QI_VIO18_OC_STATUS_MASK,        QI_VIO18_OC_STATUS_SHIFT        },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {QI_VCORE_OC_STATUS,         QI_VCORE_OC_STATUS_OFFSET,          QI_VCORE_OC_STATUS_MASK,        QI_VCORE_OC_STATUS_SHIFT        },
#endif // End of #if defined(__MEUT__)
#if defined(__MEUT__)
    {NI_SPK_OC_DET,              NI_SPK_OC_DET_OFFSET,               NI_SPK_OC_DET_MASK,             NI_SPK_OC_DET_SHIFT             },
#endif // End of #if defined(__MEUT__)
    {RGS_BC11_CMP_OUT,           RGS_BC11_CMP_OUT_OFFSET,            RGS_BC11_CMP_OUT_MASK,          RGS_BC11_CMP_OUT_SHIFT          },
    {RG_BC11_BIAS_EN,            RG_BC11_BIAS_EN_OFFSET,             RG_BC11_BIAS_EN_MASK,           RG_BC11_BIAS_EN_SHIFT           },
    {RG_BC11_VREF_VTH,           RG_BC11_VREF_VTH_OFFSET,            RG_BC11_VREF_VTH_MASK,          RG_BC11_VREF_VTH_SHIFT          },
    {RG_BC11_IPU_EN,             RG_BC11_IPU_EN_OFFSET,              RG_BC11_IPU_EN_MASK,            RG_BC11_IPU_EN_SHIFT            },
    {RG_BC11_IPD_EN,             RG_BC11_IPD_EN_OFFSET,              RG_BC11_IPD_EN_MASK,            RG_BC11_IPD_EN_SHIFT            },
    {RG_BC11_VSRC_EN,            RG_BC11_VSRC_EN_OFFSET,             RG_BC11_VSRC_EN_MASK,           RG_BC11_VSRC_EN_SHIFT           },
    {RG_BC11_CMP_EN,             RG_BC11_CMP_EN_OFFSET,              RG_BC11_CMP_EN_MASK,            RG_BC11_CMP_EN_SHIFT            },
    {RG_ISINKS_STEP_DOUBLE,      RG_ISINKS_STEP_DOUBLE_OFFSET,       RG_ISINKS_STEP_DOUBLE_MASK,     RG_ISINKS_STEP_DOUBLE_SHIFT     },
    {ISINK_STP_TC,               ISINK_STP_TC_OFFSET,                ISINK_STP_TC_MASK,              ISINK_STP_TC_SHIFT              },
    {ISINK_PHASE_MODE,           ISINK_PHASE_MODE_OFFSET,            ISINK_PHASE_MODE_MASK,          ISINK_PHASE_MODE_SHIFT          },
    {RG_KPLED_SEL,               RG_KPLED_SEL_OFFSET,                RG_KPLED_SEL_MASK,              RG_KPLED_SEL_SHIFT              },
    {KPLED_MODE,                 KPLED_MODE_OFFSET,                  KPLED_MODE_MASK,                KPLED_MODE_SHIFT                },
    {RG_KPLED_EN,                RG_KPLED_EN_OFFSET,                 RG_KPLED_EN_MASK,               RG_KPLED_EN_SHIFT               },
    {RG_SPK_VOL,                 RG_SPK_VOL_OFFSET,                  RG_SPK_VOL_MASK,                RG_SPK_VOL_SHIFT                },
    {RG_SPK_EN,                  RG_SPK_EN_OFFSET,                   RG_SPK_EN_MASK,                 RG_SPK_EN_SHIFT                 },
    {RG_SPK_OC_EN,               RG_SPK_OC_EN_OFFSET,                RG_SPK_OC_EN_MASK,              RG_SPK_OC_EN_SHIFT              },
    {RG_SPK_OBIAS,               RG_SPK_OBIAS_OFFSET,                RG_SPK_OBIAS_MASK,              RG_SPK_OBIAS_SHIFT              },
    {RG_SPK_CALIBR_SEL,          RG_SPK_CALIBR_SEL_OFFSET,           RG_SPK_CALIBR_SEL_MASK,         RG_SPK_CALIBR_SEL_SHIFT         },
    {RG_SPK_CALIBR_EN,           RG_SPK_CALIBR_EN_OFFSET,            RG_SPK_CALIBR_EN_MASK,          RG_SPK_CALIBR_EN_SHIFT          },
    {ISINK_CH3_STP_MODE,         ISINK_CH3_STP_MODE_OFFSET,          ISINK_CH3_STP_MODE_MASK,        ISINK_CH3_STP_MODE_SHIFT        },
    {ISINK_CH2_STP_MODE,         ISINK_CH2_STP_MODE_OFFSET,          ISINK_CH2_STP_MODE_MASK,        ISINK_CH2_STP_MODE_SHIFT        },
    {ISINK_CH1_STP_MODE,         ISINK_CH1_STP_MODE_OFFSET,          ISINK_CH1_STP_MODE_MASK,        ISINK_CH1_STP_MODE_SHIFT        },
    {ISINK_CH0_STP_MODE,         ISINK_CH0_STP_MODE_OFFSET,          ISINK_CH0_STP_MODE_MASK,        ISINK_CH0_STP_MODE_SHIFT        },
};
/*
PMU_MOD_BASEADDR_ENTRY pmu_strup_profile[] =
{
	{STRUP,		STRUP_CON0}
};

PMU_MOD_BASEADDR_ENTRY pmu_spk_profile[]=
{
	{SPK,		SPK_CON0}
};

PMU_MOD_BASEADDR_ENTRY pmu_kpled_profile[]=
{
    {KPLED,  		    KPLED_CON0}
};
*/

const PMU_MOD_BASEADDR_ENTRY pmu_chr_profile[]=
{
    {CHR,  		        CHR_CON0}
};


const PMU_MOD_BASEADDR_ENTRY pmu_isink_profile[]=
{
	{ISINK0,			ISINK0_CON0},
	{ISINK1,			ISINK1_CON0},
	{ISINK2,			ISINK2_CON0},
	{ISINK3,			ISINK3_CON0},
};

void pmu_flags_table_check(void)
{
    kal_uint32 i, flags_table_size = GETARRNUM(pmu_flags_table);
    const PMU_FLAG_TABLE_ENTRY *pFlag = &pmu_flags_table[0];

    for(i = 0; i < flags_table_size; i++)
    {
        if(i != pFlag->flagname)
        {
            ASSERT(0);
        }
        pFlag++;
    }
}

DCL_STATUS pmu_set_abist(PMU_FLAGS_LIST_ENUM flagname, DCL_UINT32 val)
{
	return pmu_set_register_value(ABIST_CON0, flagname, val);
}

DCL_UINT16 pmu_get_abist(PMU_FLAGS_LIST_ENUM flagname)
{
	return pmu_get_register_value(ABIST_CON0, flagname);
}

DCL_STATUS pmu_set_ldo_buck(PMU_LDO_BUCK_LIST_ENUM mod, PMU_FLAGS_LIST_ENUM flagname, DCL_UINT32 val)
{
	DCL_UINT8 baseAddressIdx;
	const PMU_MOD_BASEADDR_ENTRY *pEntry;

	if (mod >= PMU_LDO_BUCK_MAX)
	    ASSERT(0);

	baseAddressIdx = pmuModtoIdx[mod];

	pEntry = &pmu_ldo_bb_profile[baseAddressIdx];

	if (pEntry->modidx!=mod)
		ASSERT(0);

	return pmu_set_register_value(pEntry->addr, flagname, val);
}

DCL_UINT16 pmu_get_ldo_buck(PMU_LDO_BUCK_LIST_ENUM mod, PMU_FLAGS_LIST_ENUM flagname)
{
    DCL_UINT8 baseAddressIdx;
	const PMU_MOD_BASEADDR_ENTRY *pEntry;

	if (mod >= PMU_LDO_BUCK_MAX)
	    ASSERT(0);

	baseAddressIdx = pmuModtoIdx[mod];

	pEntry = &pmu_ldo_bb_profile[baseAddressIdx];

	if (pEntry->modidx!=mod)
		ASSERT(0);
	return pmu_get_register_value(pEntry->addr, flagname);
}

DCL_STATUS pmu_set_spk(PMU_FLAGS_LIST_ENUM flagname, DCL_UINT32 val)
{
	return pmu_set_register_value(SPK_CON0, flagname, val);
}

DCL_UINT16 pmu_get_spk(PMU_FLAGS_LIST_ENUM flagname)
{
	return pmu_get_register_value(SPK_CON0, flagname);
}

DCL_STATUS pmu_set_isink(PMU_ISINK_LIST_ENUM isink,PMU_FLAGS_LIST_ENUM flagname, DCL_UINT32 val)
{
	return pmu_set_register_value(pmu_isink_profile[isink].addr, flagname, val);
}

DCL_UINT16 pmu_get_isink(PMU_ISINK_LIST_ENUM isink,PMU_FLAGS_LIST_ENUM flagname)
{
	return pmu_get_register_value(pmu_isink_profile[isink].addr, flagname);
}

DCL_STATUS pmu_set_kpled(PMU_FLAGS_LIST_ENUM flagname, DCL_UINT32 val)
{
	return pmu_set_register_value(KPLED_CON0, flagname, val);
}

DCL_STATUS pmu_set_chr(PMU_FLAGS_LIST_ENUM flagname, DCL_UINT32 val)
{
	return pmu_set_register_value(CHR_CON0, flagname, val);
}

DCL_UINT16 pmu_get_chr(PMU_FLAGS_LIST_ENUM flagname)
{
	return pmu_get_register_value(CHR_CON0, flagname);
}

DCL_STATUS pmu_set_pmic_oc(PMU_FLAGS_LIST_ENUM flagname, DCL_UINT32 val)
{
	return pmu_set_register_value(OC_CON0, flagname, val);
}

DCL_UINT16 pmu_get_pmic_oc(PMU_FLAGS_LIST_ENUM flagname)
{
	return pmu_get_register_value(OC_CON0, flagname);
}

DCL_STATUS pmu_set_apb(PMU_FLAGS_LIST_ENUM flagname, DCL_UINT32 val)
{
    return pmu_set_register_value(APB_CON0, flagname, val);
}
// Prarmeter table

// LDO & BUCK

const DCL_INT32 vrf_cal[]=
{
    PMU_VOLT_CAL_00_000000_V,       PMU_VOLT_CAL_MINUS_00_020000_V, PMU_VOLT_CAL_MINUS_00_040000_V,	PMU_VOLT_CAL_MINUS_00_060000_V,
	PMU_VOLT_CAL_MINUS_00_080000_V, PMU_VOLT_CAL_MINUS_00_100000_V,	PMU_VOLT_CAL_MINUS_00_120000_V,	PMU_VOLT_CAL_MINUS_00_140000_V,
	PMU_VOLT_CAL_01_600000_V,		PMU_VOLT_CAL_01_400000_V,	    PMU_VOLT_CAL_01_200000_V,		PMU_VOLT_CAL_01_000000_V,
	PMU_VOLT_CAL_00_800000_V,		PMU_VOLT_CAL_00_600000_V,       PMU_VOLT_CAL_00_400000_V,		PMU_VOLT_CAL_00_200000_V
};

const DCL_UINT32 vcama_vosel[]=
{
	PMU_VOLT_01_500000_V,   PMU_VOLT_01_800000_V,   PMU_VOLT_02_500000_V,   PMU_VOLT_02_800000_V
};

const DCL_UINT32 vcamd_vosel[]=
{
	PMU_VOLT_01_300000_V,   PMU_VOLT_01_500000_V,   PMU_VOLT_01_800000_V,   PMU_VOLT_02_500000_V,
	PMU_VOLT_02_800000_V,   PMU_VOLT_03_000000_V,   PMU_VOLT_03_300000_V
};

const DCL_UINT32 vsim1_vosel[]=
{
	PMU_VOLT_01_800000_V,   PMU_VOLT_03_000000_V
};

const DCL_UINT32 vmc_vosel[]=
{
	PMU_VOLT_03_300000_V,   PMU_VOLT_02_800000_V,   PMU_VOLT_01_800000_V,   PMU_VOLT_01_600000_V,
};

const DCL_UINT32 vsf_vosel[]=
{
    PMU_VOLT_01_800000_V,   PMU_VOLT_03_300000_V
};

const DCL_UINT32 vcore_vosel[]=
{
    PMU_VOLT_01_200000_V,   PMU_VOLT_01_225000_V,   PMU_VOLT_01_250000_V,   PMU_VOLT_01_275000_V,
    PMU_VOLT_01_300000_V,   PMU_VOLT_01_325000_V,   PMU_VOLT_01_350000_V,   PMU_VOLT_01_350000_V,
    PMU_VOLT_01_350000_V,   PMU_VOLT_01_350000_V,   PMU_VOLT_01_350000_V,   PMU_VOLT_01_350000_V,
    PMU_VOLT_01_350000_V,   PMU_VOLT_01_350000_V,   PMU_VOLT_01_350000_V,   PMU_VOLT_01_350000_V,
    PMU_VOLT_01_350000_V,   PMU_VOLT_01_350000_V,   PMU_VOLT_00_850000_V,   PMU_VOLT_00_875000_V,
    PMU_VOLT_00_900000_V,   PMU_VOLT_00_925000_V,   PMU_VOLT_00_950000_V,   PMU_VOLT_00_975000_V,
    PMU_VOLT_01_000000_V,   PMU_VOLT_01_025000_V,   PMU_VOLT_01_050000_V,   PMU_VOLT_01_075000_V,
    PMU_VOLT_01_100000_V,   PMU_VOLT_01_125000_V,   PMU_VOLT_01_150000_V,   PMU_VOLT_01_175000_V
};

const DCL_UINT32 cci_c2a_simsel[] =
{
    PMU_VOLT_01_800000_V,   PMU_VOLT_03_000000_V,
};

// ISINK
const DCL_UINT32 isink_step[]=
{
	ISINK_STEP_04_MA,   ISINK_STEP_08_MA,   ISINK_STEP_12_MA,   ISINK_STEP_16_MA,   ISINK_STEP_20_MA,   ISINK_STEP_24_MA,
	ISINK_STEP_32_MA,   ISINK_STEP_40_MA,   ISINK_STEP_48_MA
};

// SPK
const DCL_INT32 spk_vol[]=
{
	PMU_SPK_VOL_MINUS_06_00_dB,	PMU_SPK_VOL_MINUS_03_00_dB,	PMU_SPK_VOL_06_00_dB,	PMU_SPK_VOL_12_00_dB
};

const PMU_PARAMETER_TABLE_ENTRY pmu_parameter_table[]=
{
	//LDO group
	{ENC(LDO_BUCK_SET_VOLTAGE, VCAMA),				vcama_vosel,		NULL,				GETARRNUM(vcama_vosel)	    },
	{ENC(LDO_BUCK_SET_VOLTAGE, VCAMD),				vcamd_vosel,		NULL,				GETARRNUM(vcamd_vosel)	    },
	{ENC(LDO_BUCK_SET_VOLTAGE, VSIM1),				vsim1_vosel,	    NULL,				GETARRNUM(vsim1_vosel)	    },
	{ENC(LDO_BUCK_SET_VOLTAGE, VSIM2),				vcamd_vosel,	    NULL,				GETARRNUM(vcamd_vosel)	    }, // Share VCAMD
	{ENC(LDO_BUCK_SET_VOLTAGE, VIBR),				vcamd_vosel,	    NULL,				GETARRNUM(vcamd_vosel)	    }, // Share VCAMD
	{ENC(LDO_BUCK_SET_VOLTAGE, VMC),				vmc_vosel,	        NULL,				GETARRNUM(vmc_vosel)	    },
	{ENC(LDO_BUCK_SET_VOLTAGE, VSF),				vsf_vosel,		    NULL,				GETARRNUM(vsf_vosel)	    },
	{ENC(LDO_BUCK_SET_CCI_C2A_SIM_VOSEL, ALLMOD),   cci_c2a_simsel,     NULL,               GETARRNUM(cci_c2a_simsel)   },
	{ENC(LDO_SET_CAL, VSF),			        	    vrf_cal,	        NULL,				GETARRNUM(vrf_cal)	        }, // Share VRF
	//BUCK group
	{ENC(LDO_BUCK_SET_VOLTAGE, VCORE),				vcore_vosel,		NULL,				GETARRNUM(vcore_vosel)	    },
	{ENC(LDO_BUCK_SET_SLEEP_VOLTAGE, VCORE),		vcore_vosel,		NULL,				GETARRNUM(vcore_vosel)	    },
	//ISINK
	{ENC(ISINK_SET_STEP, ALLMOD),					isink_step,		    NULL,				GETARRNUM(isink_step)		},
	//SPK
	{ENC(SPK_SET_VOL,SPK),							spk_vol,			NULL,				GETARRNUM(spk_vol)		    }
};

const PMU_VOLTAGE_ENUM voltage_calibration_idx[]=
{
    PMU_VOLT_03_300000_V,   PMU_VOLT_03_000000_V,   PMU_VOLT_02_900000_V,   PMU_VOLT_02_800000_V,
    PMU_VOLT_02_500000_V,   PMU_VOLT_01_800000_V,   PMU_VOLT_01_600000_V,	PMU_VOLT_01_500000_V,
    PMU_VOLT_01_300000_V, 	PMU_VOLT_01_200000_V
};

const DCL_UINT8 voltage_calibration_tab[10][24]=
{
// 3.3V
    {  0,  0,  0,  0,  0,  7,  6,  5,  4,  3,  2,  1,  1,  0,  0,  0, 15, 15, 14, 13, 12, 11, 10, 10},
// 3.0V
    {  0,  0,  0,  0,  8,  7,  6,  5,  4,  3,  2,  1,  1,  0,  0,  0, 15, 15, 14, 13, 13, 12, 11, 10},
// 2.9V
    {  0,  0,  0,  0,  7,  6,  5,  4,  4,  3,  2,  1,  1,  0,  0,  0, 15, 15, 14, 13, 13, 12, 11, 11},
// 2.8V
    {  0,  0,  0,  0,  7,  6,  5,  4,  3,  3,  2,  1,  1,  0,  0,  0, 15, 15, 14, 14, 13, 12, 11, 11},
// 2.5V
    {  0,  0,  0,  7,  6,  5,  5,  4,  3,  2,  2,  1,  1,  0,  0,  0, 15, 15, 15, 14, 13, 12, 12, 11},
// 1.8V
    {  0,  0,  0,  5,  4,  4,  3,  3,  2,  2,  1,  1,  1,  0,  0,  0, 15, 15, 15, 14, 14, 13, 13, 13},
// 1.6V
    {  0,  0,  0,  5,  4,  3,  3,  2,  2,  1,  1,  1,  0,  0,  0,  0,  0, 15, 15, 15, 14, 14, 13, 13},
// 1.5V
    {  0,  0,  7,  4,  4,  3,  3,  2,  2,  1,  1,  1,  0,  0,  0,  0,  0, 15, 15, 15, 14, 14, 13, 13},
// 1.3V
    {  7,  7,  6,  4,  3,  3,  2,  2,  2,  1,  1,  1,  0,  0,  0,  0,  0, 15, 15, 15, 14, 14, 14, 14},
// 1.2V
    {  2,  1,  1, 15, 14, 14, 13, 13, 13, 12, 12, 12, 11, 11, 11, 11, 11, 11, 10, 10, 10,  9,  9,  9}
};

DCL_UINT8 voltage_calibration_size;
DCL_BOOLEAN pmu_calibration_cv_enable = DCL_FALSE;
DCL_BOOLEAN pmu_calibration_ov_enable = DCL_FALSE;
DCL_UINT8 pmu_calibration_cv_val = 0;
DCL_UINT8 pmu_calibration_ov_val = 0;

DCL_UINT8 pmu6250_ldo_cal(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT32 vol);
void pmu6250_spk_init(PMU_CTRL_SPK_MODE_ENUM mode);

void pmu6250_spk_enable(DCL_BOOL enable);

void pmu6250_bl_init(void);

void pmu6250_bl_enable(DCL_BOOL enable);

DCL_BOOL pmu6250_cust_isink_en[PMU_ISINK_MAX];
static PMU_CTRL_ISINK_STEP_ENUM pmu_cust_isink_step[PMU_ISINK_MAX];
static PMU_CTRL_ISINK_STEP_GROUP_ENUM pmu_cust_isink_step_group = ISINK_STEP_GROUP_A;
const static PMU_CTRL_ISINK_STEP_ENUM pmu6250_isink_step_lookup_table[ISINK_STEP_GROUP_MAX][ISINK_STEP_INDEX_MAX] =
    {{ISINK_STEP_04_MA, ISINK_STEP_08_MA, ISINK_STEP_12_MA,
      ISINK_STEP_16_MA, ISINK_STEP_20_MA, ISINK_STEP_24_MA},
     {ISINK_STEP_08_MA, ISINK_STEP_16_MA, ISINK_STEP_24_MA,
      ISINK_STEP_32_MA, ISINK_STEP_40_MA, ISINK_STEP_48_MA} };

DCL_UINT32 bl_support_level;
DCL_BOOL bl_use_pwm;

DCL_STATUS dcl_pmu6250_control_handler(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_UINT16 val;
	SW_SECVERSION SW_SecVersion = INT_SW_SecVersion();
	// LDO and BUCK
	if (cmd > LDO_BUCK_SET_CMDS_START && cmd < LDO_BUCK_SET_CMDS_END)
	{
		PMU_CTRL_LDO_BUCK_CTRL *pLdoBuckCtrl = &(data->rPMULdoBuckCtrl);
		PMU_LDO_BUCK_LIST_ENUM mod = pLdoBuckCtrl->mod;

		switch(cmd)
		{
			case LDO_BUCK_SET_EN:
			{
				PMU_CTRL_LDO_BUCK_SET_EN *pLdoBuckCtrl = &(data->rPMULdoBuckSetEn);
				pmu_set_ldo_buck(mod, LDO_BUCK_EN, pLdoBuckCtrl->enable);
			}
			break;

			case LDO_BUCK_SET_ON_SEL:
			{
				PMU_CTRL_LDO_BUCK_SET_ON_SEL *pLdoBuckCtrl = &(data->rPMULdoBuckSetOnSel);
				pmu_set_ldo_buck(mod, LDO_BUCK_ON_SEL, pLdoBuckCtrl->onSel);

			}
			break;

			case LDO_BUCK_SET_RS:
			{
				PMU_CTRL_LDO_BUCK_SET_RS *pLdoBuckCtrl = &(data->rPMULdoBuckSetRs);
                pmu_set_ldo_buck(mod, LDO_BUCK_RS, pLdoBuckCtrl->rs);
			}
			break;

			case LDO_BUCK_SET_VOLTAGE:
			{
				PMU_CTRL_LDO_BUCK_SET_VOLTAGE *pLdoBuckCtrl = &(data->rPMULdoBuckSetVoltage);
				val = PMU_Parameter_to_Value(ENC(LDO_BUCK_SET_VOLTAGE, mod), pLdoBuckCtrl->voltage);

				if (val == PARAMETER_UNKNOWN)
					return STATUS_UNSUPPORTED;
				pmu_set_ldo_buck(mod, LDO_BUCK_VOL_SEL, val);

				pmu6250_ldo_cal(pLdoBuckCtrl->mod, pLdoBuckCtrl->voltage);
			}
			break;

			case LDO_BUCK_SET_NDIS_EN:
			{
				PMU_CTRL_LDO_BUCK_SET_NDIS_EN *pLdoBuckCtrl = &(data->rPMULdoBuckSetNdisEn);
				pmu_set_ldo_buck(mod, LDO_BUCK_NDIS_EN, pLdoBuckCtrl->enable);
			}
			break;

			case LDO_BUCK_SET_STB_EN:
			{
				PMU_CTRL_LDO_BUCK_SET_STB_EN *pLdoBuckCtrl = &(data->rPMULdoBuckSetStbEn);
				pmu_set_ldo_buck(mod, LDO_BUCK_STB_SEL, pLdoBuckCtrl->enable);
			}
			break;

			case LDO_BUCK_SET_OC_AUTO_OFF:
			{
				PMU_CTRL_LDO_BUCK_SET_OC_AUTO_OFF *pLdoBuckCtrl = &(data->rPMULdoBuckSetOcAutoOff);
				pmu_set_ldo_buck(mod, LDO_BUCK_OC_AUTO_OFF, pLdoBuckCtrl->enable);
			}
			break;

			case LDO_BUCK_SET_OCFB_EN:
			{
				PMU_CTRL_LDO_BUCK_SET_OCFB_EN *pLdoBuckCtrl = &(data->rPMULdoBuckSetOcfbEn);
				pmu_set_ldo_buck(mod, LDO_BUCK_OCFB_EN, pLdoBuckCtrl->enable);
			}
			break;

			case LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE:
			{
				PMU_CTRL_LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE *pLdoBuckCtrl = &(data->rPMULdoBuckSetVoltageCalibrationCode);
				pmu_set_ldo_buck(mod, LDO_CAL, pLdoBuckCtrl->voltageCalibrationCode);
			}
			break;

			case LDO_BUCK_SET_OC_TD: // For DVT Usage
			{
				PMU_CTRL_LDO_BUCK_SET_OC_TD *pLdoBuckCtrl = &(data->rPMULdoBuckSetOcTd);
				if (ISLDO(mod))
				{
					pmu_set_ldo_buck(mod, LDO_OC_TD, pLdoBuckCtrl->deglitchTimeIdx);
				}
				else
				{
                    return STATUS_UNSUPPORTED;
                }
			}
			break;

			case LDO_BUCK_SET_STB_TD: // For DVT Usage
			{
				PMU_CTRL_LDO_BUCK_SET_STB_TD *pLdoBuckCtrl = &(data->rPMULdoBuckSetStbTd);
				if (ISLDO(mod))
				{
					pmu_set_ldo_buck(mod, LDO_STB_TD, pLdoBuckCtrl->delayTimeIdx);
				}
				else
				{
                    return STATUS_UNSUPPORTED;
                }
			}
			break;

			case LDO_BUCK_SET_SLEEP_VOLTAGE:
			{
				if (ISLDO(mod))
				{
                    return STATUS_UNSUPPORTED;
                }
				else
				{
					PMU_CTRL_LDO_BUCK_SET_SLEEP_VOLTAGE *pLdoBuckCtrl = &(data->rPMULdoBuckSetSleepVoltage);
					val = PMU_Parameter_to_Value(ENC(LDO_BUCK_SET_SLEEP_VOLTAGE, mod), pLdoBuckCtrl->sleepVoltage);

					if (val == PARAMETER_UNKNOWN)
						return STATUS_UNSUPPORTED;
					pmu_set_ldo_buck(mod, BUCK_VOSEL_SLEEP, val);
				}
			}
			break;

			case LDO_BUCK_SET_VOLTAGE_EN: // Combination Command
			{
				PMU_CTRL_LDO_BUCK_SET_VOLTAGE_EN *pLdoBuckCtrl = &(data->rPMULdoBuckSetVoltageEn);
				PMU_CTRL_LDO_BUCK_SET_VOLTAGE ldoBuckVoltage;
				PMU_CTRL_LDO_BUCK_SET_EN	ldoBuckEn;

				ldoBuckEn.mod = pLdoBuckCtrl->mod;
				ldoBuckEn.enable = DCL_TRUE;
				ldoBuckVoltage.mod = pLdoBuckCtrl->mod;
				ldoBuckVoltage.voltage = pLdoBuckCtrl->voltage;

				dcl_pmu6250_control_handler(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&ldoBuckVoltage);
				dcl_pmu6250_control_handler(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&ldoBuckEn);
			}
			break;

			case LDO_BUCK_SET_VSIM_GPLDO_EN:
			{
				PMU_CTRL_LDO_BUCK_SET_VSIM_GPLDO_EN *pLdoBuckCtrl = &(data->rPMULdoBuckSetVsimGpldoEn);
                pmu_set_ldo_buck(mod, VSIM1_GPLDO_EN, pLdoBuckCtrl->enable);
			}
			break;

			case LDO_BUCK_SET_VSIM2_GPLDO_EN:
			{
				PMU_CTRL_LDO_BUCK_SET_VSIM2_GPLDO_EN *pLdoBuckCtrl = &(data->rPMULdoBuckSetVsim2GpldoEn);
                pmu_set_ldo_buck(mod, VSIM2_GPLDO_EN, pLdoBuckCtrl->enable);
			}
			break;

			case LDO_BUCK_SET_CCI_SRCLKEN:
			{
				PMU_CTRL_LDO_BUCK_SET_CCI_SRCLKEN *pLdoBuckCtrl = &(data->rPMULdoBuckSetCciSrclken);
                pmu_set_ldo_buck(mod, CCI_SRCLKEN, pLdoBuckCtrl->enable);
			}
			break;

            case LDO_BUCK_SET_CCI_C2A_SIM_VOSEL:
            {
                PMU_CTRL_LDO_BUCK_SET_CCI_C2A_SIM_VOSEL *pLdoBuckCtrl = (PMU_CTRL_LDO_BUCK_SET_CCI_C2A_SIM_VOSEL *)data;
                val = PMU_Parameter_to_Value(ENC(LDO_BUCK_SET_CCI_C2A_SIM_VOSEL, mod), pLdoBuckCtrl->voltage);

                if (VSIM == pLdoBuckCtrl->mod)
                {
                    pmu_set_apb(CCI_C2A_SIM1SEL, val);
                }
                else if (VSIM2 == pLdoBuckCtrl->mod)
                {
                    pmu_set_apb(CCI_C2A_SIM2SEL, val);
                }
                else
                {
                    return STATUS_UNSUPPORTED;
                }
            }
            break;
            
            case LDO_SET_CAL:
            {
                PMU_CTRL_LDO_SET_CAL *pLdoCtrl = &(data->rPMULdoSetCal);
                if (ISLDO(mod))
                {
    			    val = PMU_Parameter_to_Value(ENC(LDO_SET_CAL, mod), pLdoCtrl->voltage);

    			    if (val == PARAMETER_UNKNOWN)
    				    return STATUS_UNSUPPORTED;
    			    pmu_set_ldo_buck(mod, LDO_CAL, val);
                }
                else
				{
                    return STATUS_UNSUPPORTED;
                }
            }
            break;

			default:
			return STATUS_UNSUPPORTED;
		}
	}

	switch(cmd)
	{
		case SPK_SET_VOL:
		{
			PMU_CTRL_SPK_SET_VOL *pSpkCtrl = &(data->rPMUSpkSetVol);
			val = PMU_Parameter_to_Value(ENC(SPK_SET_VOL, SPK), pSpkCtrl->dbm);

			if (val == PARAMETER_UNKNOWN)
				return STATUS_UNSUPPORTED;

			pmu_set_spk(RG_SPK_VOL, val);
		}
		break;

		case SPK_GET_VOL_VALUE:
		{
			PMU_CTRL_SPK_GET_VOL_VALUE *pSpkCtrl = &(data->rPMUSpkGetVolValue);
		    pSpkCtrl->volValue = pmu_get_spk(RG_SPK_VOL);
		}
		break;

		case SPK_SET_EN:
		{
			PMU_CTRL_SPK_SET_EN *pSpkCtrl = &(data->rPMUSpkSetEn);

			if (pSpkCtrl->step == PMU_CTRL_STEP1)
			{
				pmu6250_spk_enable(pSpkCtrl->enable);
			}
			else if (pSpkCtrl->step == PMU_CTRL_STEP2)
			{
				if (pSpkCtrl->enable == DCL_TRUE)
				{
					// pmu_set_spk(SPK_PG_SLEW_I, 1);
				}
			}
		}
		break;

		case SPK_SET_CALIBR_SEL:
		{
			PMU_CTRL_SPK_SET_CALIBR_SEL *pSpkCtrl = &(data->rPMUSpkSetCalibrSel);
            // Note: For MT6250 the calibration path select is in opposite
            // That specification is 0: SPK_P, 1: SPK_N. (Datasheet is correct)
            // But due to AFE & PMU's drivers are all wrong, we decided that we will keep this code forever.
            // We didn¡¦t change the direction of pSpkCtrl->path.
            // Which means for PMU Driver, it is 0: SPK_N, 1: SPK_P.
            // DO NOT CHANGE THIS PART FOREVER!!!
			pmu_set_spk(RG_SPK_CALIBR_SEL, pSpkCtrl->path);
		}
		break;

		case SPK_SET_CALIBR_EN:
		{
			PMU_CTRL_SPK_SET_CALIBR_EN *pSpkCtrl = &(data->rPMUSpkSetCalibrEn);
			pmu_set_spk(RG_SPK_CALIBR_EN, pSpkCtrl->enable);
		}
		break;

		case BL_SET_INIT:
		{
			pmu6250_bl_init();
		}
        break;

		case BL_SET_EN:
		{
			PMU_CTRL_BL_SET_EN *pBlCtrl = &(data->rPMUBlSetEn);
			pmu6250_bl_enable(pBlCtrl->enable);
		}
		break;

        case BL_SET_LEVEL:
        {
            PMU_CTRL_BL_SET_LEVEL *pBlCtrl = (PMU_CTRL_BL_SET_LEVEL *)data;
            PMU_CTRL_ISINK_SET_STEP isink_step;

            //E1 workaround solution for RF de-sense performance
            if (SW_SEC_0 == SW_SecVersion)
            {
                switch (pBlCtrl->blLevel)
                {
                    case LED_LIGHT_LEVEL1:
                        isink_step.step = ISINK_STEP_04_MA;
                        break;
                    case LED_LIGHT_LEVEL2:
                        isink_step.step = ISINK_STEP_08_MA;
                        break;
                    case LED_LIGHT_LEVEL3:
                        isink_step.step = ISINK_STEP_12_MA;
                        break;
                    case LED_LIGHT_LEVEL4:
                        isink_step.step = ISINK_STEP_16_MA;
                        break;
                    case LED_LIGHT_LEVEL5:
                        isink_step.step = ISINK_STEP_20_MA;
                        break;
                    default:
                        break;                            
                }

                isink_step.isink = ISINK0;
                DclPMU_Control(handle, ISINK_SET_STEP, (DCL_CTRL_DATA_T *)&isink_step);

                isink_step.isink = ISINK1;
                DclPMU_Control(handle, ISINK_SET_STEP, (DCL_CTRL_DATA_T *)&isink_step);

                isink_step.isink = ISINK2;
                DclPMU_Control(handle, ISINK_SET_STEP, (DCL_CTRL_DATA_T *)&isink_step);

                isink_step.isink = ISINK3;
                DclPMU_Control(handle, ISINK_SET_STEP, (DCL_CTRL_DATA_T *)&isink_step);
            }
        }
        break;

        case BL_GET_SUPPORT_LEVEL:
        {
            PMU_CTRL_BL_GET_SUPPORT_LEVEL *pBlCtrl = &(data->rPMUBlGetSupportLevel);
            pBlCtrl->blSupportLevel = bl_support_level;
        }
        break;

        case BL_GET_USE_PWM_QUERY:
        {
            PMU_CTRL_BL_GET_USE_PWM_QUERY *pBlCtrl = &(data->rPMUBlGetUsePwmQuery);
            pBlCtrl->blUsePwmQuery = bl_use_pwm;
        }
        break;

		case ISINK_SET_EN:
		{
			PMU_CTRL_ISINK_SET_EN *pIsinkCtrl = &(data->rPMUIsinkSetEn);
			if (pIsinkCtrl->isink < PMU_ISINK_MAX)
				pmu6250_cust_isink_en[pIsinkCtrl->isink] = pIsinkCtrl->enable;
		}
		break;

		case ISINK_SET_MODE:
		{
			PMU_CTRL_ISINK_SET_MODE  *pIsinkCtrl = &(data->rPMUIsinkSetMode);
			if (pIsinkCtrl->isink < PMU_ISINK_MAX)
				pmu_set_isink(pIsinkCtrl->isink, ISINK_MODE, pIsinkCtrl->mode);
		}
		break;

		case ISINK_SET_STEP:
		{
			PMU_CTRL_ISINK_SET_STEP *pIsinkCtrl = &(data->rPMUIsinkSetStep);

			if(SW_SecVersion >= SW_SEC_1)
			{
                pmu_cust_isink_step[pIsinkCtrl->isink] = pIsinkCtrl->step;
			}
			else
			{
				if(pIsinkCtrl->step > ISINK_STEP_24_MA)
				{
					pmu_cust_isink_step[pIsinkCtrl->isink] = ISINK_STEP_24_MA;
				}
                else
                {
                    pmu_cust_isink_step[pIsinkCtrl->isink] = pIsinkCtrl->step;
                }
			}
		}
		break;


        case ISINK_SET_STEP_GROUP:
        {
            PMU_CTRL_ISINK_SET_STEP_GROUP *pIsinkCtrl = (PMU_CTRL_ISINK_SET_STEP_GROUP *)data;

            if (SW_SecVersion >= SW_SEC_1)
            {
                pmu_cust_isink_step_group = pIsinkCtrl->group;
            }
            else
            {
                return STATUS_UNSUPPORTED;
            }
        }
        break;

        case ISINK_SET_STEP_INDEX:
        {
            PMU_CTRL_ISINK_SET_STEP_INDEX *pIsinkCtrl = (PMU_CTRL_ISINK_SET_STEP_INDEX *)data;

            if (SW_SecVersion >= SW_SEC_1)
            {
                ASSERT(pmu_cust_isink_step_group < ISINK_STEP_GROUP_MAX);
                ASSERT(pIsinkCtrl->isink < PMU_ISINK_MAX);
                ASSERT(pIsinkCtrl->index < ISINK_STEP_INDEX_MAX);
                
                pmu_cust_isink_step[pIsinkCtrl->isink] =
                    pmu6250_isink_step_lookup_table[pmu_cust_isink_step_group][pIsinkCtrl->index];
            }
            else
            {
                return STATUS_UNSUPPORTED;
            }
        }
        break;

		case ISINK_SET_STP_EN:
		{
			PMU_CTRL_ISINK_SET_STP_EN *pIsinkCtrl = &(data->rPMUIsinkSetStpEn);
			
			if (SW_SecVersion >= SW_SEC_1)
			{
				PMU_DRV_SetData16(VCORE_CON0 + ISINK_STP_EN_OFFSET, ISINK_STP_EN_MASK, (pIsinkCtrl->enable << ISINK_STP_EN_SHIFT));
			}
			else
			{
				return STATUS_UNSUPPORTED;
			}
		}
		break;
		
		case ISINK_SET_STEP_DOUBLE:
		{
			PMU_CTRL_ISINK_SET_STEP_DOUBLE *pIsinkCtrl = &(data->rPMUIsinkSetStepDouble);
			if (SW_SecVersion >= SW_SEC_1)
			{
				PMU_DRV_SetData16(ISINKS_CON0 + RG_ISINKS_STEP_DOUBLE_OFFSET, RG_ISINKS_STEP_DOUBLE_MASK, (pIsinkCtrl->enable << RG_ISINKS_STEP_DOUBLE_SHIFT));
			}
			else
			{
				return STATUS_UNSUPPORTED;
			}
		}
		break;
		
		case ISINK_SET_STEP_MODE:
		{
			PMU_CTRL_ISINK_SET_STEP_MODE *pIsinkCtrl = &(data->rPMUIsinkSetStepMode);
			
			if (SW_SecVersion >= SW_SEC_1)
			{
				switch (pIsinkCtrl->isink)
				{
					case ISINK0:
						PMU_DRV_SetData16(RSV_CON0 + ISINK_CH0_STP_MODE_OFFSET, ISINK_CH0_STP_MODE_MASK, (pIsinkCtrl->enable << ISINK_CH0_STP_MODE_SHIFT));
						break;
						
					case ISINK1:
						PMU_DRV_SetData16(RSV_CON0 + ISINK_CH1_STP_MODE_OFFSET, ISINK_CH1_STP_MODE_MASK, (pIsinkCtrl->enable << ISINK_CH1_STP_MODE_SHIFT));
						break;
					
					case ISINK2:
						PMU_DRV_SetData16(RSV_CON0 + ISINK_CH2_STP_MODE_OFFSET, ISINK_CH2_STP_MODE_MASK, (pIsinkCtrl->enable << ISINK_CH2_STP_MODE_SHIFT));
						break;

					case ISINK3:
						PMU_DRV_SetData16(RSV_CON0 + ISINK_CH3_STP_MODE_OFFSET, ISINK_CH3_STP_MODE_MASK, (pIsinkCtrl->enable << ISINK_CH3_STP_MODE_SHIFT));
						break;
					
					default:														
						ASSERT(0); // No this channel
						break;
				}
			}
			else
			{
				return STATUS_UNSUPPORTED;
			}
		}
		break;

		case KPLED_SET_SEL:
		{
			PMU_CTRL_KPLED_SET_SEL *pKpledCtrl = &(data->rPMUKpledSetSel);
			pmu_set_kpled(RG_KPLED_SEL, pKpledCtrl->sel);
		}
		break;

		case KPLED_SET_MODE:
		{
			PMU_CTRL_KPLED_SET_MODE *pKpledCtrl = &(data->rPMUKpledSetMode);
			pmu_set_kpled(KPLED_MODE, pKpledCtrl->mode);
		}
		break;

		case KPLED_SET_EN:
		{
			PMU_CTRL_KPLED_SET_EN *pKpledCtrl = &(data->rPMUKpledSetEn);
			pmu_set_kpled(RG_KPLED_EN, pKpledCtrl->enable);
		}
		break;

		case CHR_SET_ADC_MEASURE_EN:
		{
			PMU_CTRL_CHR_SET_ADC_MEASURE_EN *pChrCtrl = &(data->rPMUChrSetAdcMeasureEn);
			if (pChrCtrl->enable)
			{
				pmu_set_chr(ADC_EN, 7); // AUXADC input source enable for VCHR, VSEN, VBAT
			}
			else
			{
				pmu_set_chr(ADC_EN, 0);
			}
		}
		break;

 		case MISC_SET_REGISTER_VALUE:
		{
			PMU_CTRL_MISC_SET_REGISTER_VALUE *pChrCtrl = &(data->rPMUMiscSetRegisterValue);
            if ((MIXED_BASE_ADDR + pChrCtrl->offset) > MIXED_BASE_ADDR_END)
                return STATUS_UNSUPPORTED;
			PWIC_DRV_WriteReg16((MIXED_BASE_ADDR + pChrCtrl->offset), pChrCtrl->value);
		}
		break;

		case MISC_GET_REGISTER_VALUE:
		{
			PMU_CTRL_MISC_GET_REGISTER_VALUE *pChrCtrl = &(data->rPMUMiscGetRegisterValue);
            if ((MIXED_BASE_ADDR + pChrCtrl->offset) > MIXED_BASE_ADDR_END)
                return STATUS_UNSUPPORTED;
			pChrCtrl->value = PWIC_DRV_ReadReg16((MIXED_BASE_ADDR_END + pChrCtrl->offset));
		}
		break;

		default:
		return STATUS_UNSUPPORTED;
	}

	return STATUS_OK;
}

DCL_UINT8 pmu6250_ldo_cal(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT32 vol)
{
	DCL_UINT32 i = 0;

	if (pmu_calibration_cv_enable == DCL_TRUE && ldo != VCORE)
	{
		DCL_UINT8 size = voltage_calibration_size;
		for (i = 0; i < size; i++)
		{
			if (voltage_calibration_idx[i] == vol)
			{
				pmu_set_ldo_buck(ldo, LDO_CAL, voltage_calibration_tab[i][pmu_calibration_cv_val]);
				break;
			}
		}
	}
	return 0;
}

#if !defined(__UBL__) && !defined(__FUE__)
void pmu6250_efuse_calibration(void)
{
	// E-FUSE calibration
	DCL_UINT32 val32;
	DCL_UINT16 val16;
	BMT_CTRL_SET_CHR_TRIMMING_DATA bmt_trimming_data;
	DCL_HANDLE bmt_handle = DclBMT_Open(DCL_BMT, FLAGS_NONE);
	voltage_calibration_size = sizeof(voltage_calibration_idx) / sizeof(voltage_calibration_idx[0]);

	// 1. CV Trim
	// Read (EFUSE_BASE + 0x100)[12] := RG_VBAT_CV_VTH_EN(1b)
	// Read (EFUSE_BASE + 0x100)[17:13] := RG_VBAT_CV_VTH(5b)
	// Apply to RG_VBAT_CV_VTH[4:0]
	val32 = PMU_DRV_ReadReg32(EFUSE_base + 0x10C);
	// val32 = 0x0003F000;
	if (val32 & 0x00001000) // Bit12: RG_VBAT_CV_VTH_EN, CV Trim Enable Bit
	{
		pmu_calibration_cv_enable = DCL_TRUE;
		pmu_calibration_cv_val = (DCL_UINT8)((val32 & 0x0003E000) >> 13); // Bits [17:13]
	}

	// 2. OV Trim
	// Read (EFUSE_BASE + 0x100)[7] := RG_OVP_TRIM_EN(1b)
	// Read (EFUSE_BASE + 0x104)[11:8] := RG_OVP_TRIM(4b)
	// Apply to RG_OVP_TRIM[3:0]
	val32 = PMU_DRV_ReadReg32(EFUSE_base + 0x10C);
	// val32 = 0x00000F80;
	if (val32 & 0x00000080) // Bit7: RG_OVP_TRIM_EN, OV Trim Enable Bit
	{
		pmu_calibration_ov_enable = DCL_TRUE;
		pmu_calibration_ov_val = (DCL_UINT8)((val32 & 0x00000F00) >> 8); // Bits [11:8]
	}

	// 3. IBIAS Trim
	// Read (EFUSE_BASE + 0x100)[2] := RG_IBIAS_TRIM_EN(1b)
	// Read (EFUSE_BASE + 0x100)[6:3] := RG_IBIAS_TRIM(4b)
	// Apply to RG_IBIAS_TRIM[3:0]
	val32 = PMU_DRV_ReadReg32(EFUSE_base + 0x10C);
	if (val32 & 0x00000004) // Bit2: RG_IBIAS_TRIM_EN, IBIAS Trim Enable Bit
	{
		val16 = (DCL_UINT16)((val32 & 0x00000078) >> 3); // Bits [6:3]
		PMU_DRV_SetData16((TEST_CON0 + RG_IBIAS_TRIM_OFFSET), RG_IBIAS_TRIM_MASK, (val16 << RG_IBIAS_TRIM_SHIFT));
	}

	bmt_trimming_data.CV_Trim_Enable = pmu_calibration_cv_enable;
	bmt_trimming_data.OV_Trim_Enable = pmu_calibration_ov_enable;
	bmt_trimming_data.CV_Trim_Data = pmu_calibration_cv_val;
	bmt_trimming_data.OV_Trim_Data = pmu_calibration_ov_val;

	DclBMT_Control(bmt_handle, BMT_CMD_SET_CHR_EFUSE_TRIMMING_DATA, (DCL_CTRL_DATA_T *)&bmt_trimming_data);
	DclBMT_Close(bmt_handle);

	/*
	const PMU_VOLTAGE_ENUM voltage_calibration_idx[]=
	{
    	PMU_VOLT_03_300000_V,
    	PMU_VOLT_03_000000_V,
    	PMU_VOLT_02_900000_V,
    	PMU_VOLT_02_800000_V,
    	PMU_VOLT_02_500000_V,
    	PMU_VOLT_01_800000_V,
    	PMU_VOLT_01_600000_V,
    	PMU_VOLT_01_500000_V,
    	PMU_VOLT_01_300000_V,
		PMU_VOLT_01_200000_V
	};
	ALDO	VRF		Default ON	2.8 ok
	ALDO	VA		Default ON	2.8 ok
	ALDO	VTCXO	Default ON	2.8 ok
	ALDO	VCAMA	Default OFF	1.5/1.8/2.5/2.8 ok
	ALDO	VBT		Default OFF	2.8 ok
	DLDO	VIO28	Default ON	2.8 ok
	DLDO	VSIM1	Default OFF	1.8/3.0 ok
	DLDO	VSIM2	Default OFF	1.3/1.5/1.8/2.5/2.8/3.0/3.3 ok
	DLDO	VUSB	Default ON	3.3 ok
	DLDO	VIO18	Default ON	1.8 ok
	DLDO	VCORE	Default ON	0.85~1.35
	DLDO	VCAMD	Default OFF	1.3/1.5/1.8/2.5/2.8/3.0/3.3 ok
	DLDO	VIBR	Default OFF	1.3/1.5/1.8/2.5/2.8/3.0/3.3 ok
	DLDO	VMC		Default OFF	1.6/1.8/2.8/3.0 ok
	DLDO	VSF		Default ON	1.8/3.3 ok
	RTCLDO	VRTC	Default ON	2.8 ok
	*/
	// Only trimmed default on LDOs
	pmu6250_ldo_cal(VRF, PMU_VOLT_02_800000_V);
	pmu6250_ldo_cal(VTCXO,PMU_VOLT_02_800000_V);
	pmu6250_ldo_cal(VA, PMU_VOLT_02_800000_V);
//	pmu6250_ldo_cal(VCAMA, PMU_VOLT_01_500000_V); // Test Only
//	pmu6250_ldo_cal(VCAMD, PMU_VOLT_02_500000_V); // Test Only
	pmu6250_ldo_cal(VIO28, PMU_VOLT_02_800000_V);
	pmu6250_ldo_cal(VUSB, PMU_VOLT_03_300000_V);
//	pmu6250_ldo_cal(VBT, PMU_VOLT_02_800000_V); // Test Only
//	pmu6250_ldo_cal(VSIM1, PMU_VOLT_03_000000_V); // Test Only
//	pmu6250_ldo_cal(VSIM2, PMU_VOLT_03_000000_V); // Test Only
	pmu6250_ldo_cal(VRTC, PMU_VOLT_02_800000_V);
//	pmu6250_ldo_cal(VIBR, PMU_VOLT_01_300000_V); // Test Only
//	pmu6250_ldo_cal(VMC, PMU_VOLT_01_600000_V); // Test Only
	pmu6250_ldo_cal(VSF, PMU_VOLT_01_800000_V);
	pmu6250_ldo_cal(VIO18, PMU_VOLT_01_800000_V);
	
}
#endif // End of #if !defined(__UBL__) && !defined(__FUE__)

extern void pmu6250_customization_init(void);

void initLdoBuckMapping(void)
{
	DCL_UINT32 i, j, size = pmu_ldo_bb_size;

	for (i = 0;i < PMU_LDO_BUCK_MAX;i++)
	{
		for (j = 0;j < size;j++)
		{
			if (pmu_ldo_bb_profile[j].modidx == i)
			{
				pmuModtoIdx[i] = j;
			}
		}
	}
}

extern void dcl_pmu6250_internal_init(void);
extern void pmu_drv_tool_customization_init(void);
extern kal_bool IsInWithOutBatteryMode(void);

void dcl_pmu6250_init(void)
{

	pmu_control_handler = dcl_pmu6250_control_handler;
	pmu_parameter_size = GETARRNUM(pmu_parameter_table);

	pmu_ldo_bb_size = GETARRNUM(pmu_ldo_bb_profile);
	initLdoBuckMapping();
	pmu_flags_table_check();

#if !defined(__UBL__) && !defined(__FUE__)
	pmu6250_efuse_calibration();
#endif // End of #if !defined(__UBL__) && !defined(__FUE__)

#ifdef __BACKUP_DOWNLOAD_RESTORE_WITHOUT_BATTERY__
#if !defined(__UBL__) && !defined(__FUE__)
	if(INT_GetSysStaByCmd(CHK_USB_META_WO_BAT, NULL) == KAL_FALSE)
#else
	if(IsInWithOutBatteryMode() == KAL_FALSE)
#endif
#endif // End of #ifdef __BACKUP_DOWNLOAD_RESTORE_WITHOUT_BATTERY__
    {
		dcl_pmu6250_internal_init();
	}

	// Oscar set ULC_DET_EN for Charger/USB plug out detection
	PMU_DRV_SetData16(MIXED_BASE_ADDR + 0x0A30, 0x80, 0x80);

	pmu6250_customization_init();


#if !defined(__UBL__) && !defined(__FUE__)
	pmu_drv_tool_customization_init();
#endif // End of #if !defined(__UBL__)
}

//static pmic_adpt_bl_mode_enum bl_mode;
void pmu6250_bl_init(void)
{
    DCL_HANDLE handle;
    PMU_CTRL_ISINK_SET_STP_EN isink_stp_en;
    
    bl_support_level = BL_ISINK_LEVEL;
    bl_use_pwm = DCL_TRUE;

    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    isink_stp_en.enable = DCL_TRUE;
	DclPMU_Control(handle, ISINK_SET_STP_EN, (DCL_CTRL_DATA_T *)&isink_stp_en);
    DclPMU_Close(handle);
}

void pmu6250_bl_enable(DCL_BOOL enable)
{
	DCL_UINT32 i;
    DCL_BOOL enable_double_bit = DCL_FALSE;
    DCL_BOOL disable_double_bit = DCL_FALSE;
    PMU_CTRL_ISINK_SET_STEP_DOUBLE IsinkSetStepDouble;
    PMU_CTRL_ISINK_STEP_ENUM isink_step;
    PMU_CTRL_ISINK_SET_STEP_MODE isink_step_mode;
    DCL_UINT16 val;
    SW_SECVERSION SW_SecVersion = INT_SW_SecVersion();
    DCL_HANDLE handle;
    
	handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);

    if(SW_SecVersion >= SW_SEC_1)
    {
        //Verify isink step setting and determine double bit setting.
        for (i = 0;i < GETARRNUM(pmu_isink_profile); i++)
        {
            if (pmu6250_cust_isink_en[i])
            {
                switch (pmu_cust_isink_step[i])
                {
                    case ISINK_STEP_04_MA:
                    case ISINK_STEP_12_MA:
                    case ISINK_STEP_20_MA:
                        disable_double_bit |= DCL_TRUE;
                        break;
                    case ISINK_STEP_32_MA:
                    case ISINK_STEP_40_MA:
                    case ISINK_STEP_48_MA:
                        enable_double_bit |= DCL_TRUE;
                        break;
                    default:
                        break;
                }
            }
        }

        if ((DCL_TRUE == enable_double_bit) && (DCL_TRUE == disable_double_bit))
            ASSERT(0);

        IsinkSetStepDouble.enable = enable_double_bit;
        dcl_pmu6250_control_handler(handle, ISINK_SET_STEP_DOUBLE, (DCL_CTRL_DATA_T *)&IsinkSetStepDouble);
    }
    
	for (i = 0;i < GETARRNUM(pmu_isink_profile); i++)
	{
		if (pmu6250_cust_isink_en[i])
		{
            if (DCL_TRUE == enable_double_bit)
                isink_step = (PMU_CTRL_ISINK_STEP_ENUM)(pmu_cust_isink_step[i] >> 1);
            else
                isink_step = pmu_cust_isink_step[i];
            
            val=PMU_Parameter_to_Value(ENC(ISINK_SET_STEP, ALLMOD), isink_step);

			if (val!=PARAMETER_UNKNOWN)
				pmu_set_isink((PMU_ISINK_LIST_ENUM)i, ISINK_STEP, val);

            if(SW_SecVersion >= SW_SEC_1)
            {
                isink_step_mode.isink = (PMU_ISINK_LIST_ENUM)i;
                
                if (pmu_cust_isink_step[ISINK0] == pmu_cust_isink_step[i] &&
                    pmu_get_isink(isink_step_mode.isink, ISINK_MODE) == ISINK_PWM_MODE)
                {
                    isink_step_mode.enable = DCL_TRUE;
                }
                else
                {
                    isink_step_mode.enable = DCL_FALSE;
                }
                
		        DclPMU_Control(handle, ISINK_SET_STEP_MODE, (DCL_CTRL_DATA_T *)&isink_step_mode);
            }
            
			pmu_set_isink((PMU_ISINK_LIST_ENUM)i,ISINK_EN,(DCL_UINT32)enable);
		}
	}

    DclPMU_Close(handle);
}

static PMU_CTRL_SPK_MODE_ENUM spk_mode;
void pmu6250_spk_init(PMU_CTRL_SPK_MODE_ENUM mode)
{
    /*
	spk_mode = mode;

	switch (spk_mode)
	{
		case SPK_CLASS_D_MODE:
			// Class-D
			//pmu_set_spk(SPK_CCODE, 0);
			pmu_set_spk(SPKMODE, SPK_CLASS_D_MODE);
		break;
		case SPK_CLASS_AB_MODE:
			// Class-AB
		    //pmu_set_spk(SPKMODE, SPK_CLASS_AB_MODE);
			//pmu_set_spk(SPK_OC_EN, DCL_FALSE);
        	pmu_set_spk(SPKAB_OBIAS, 0);
		break;
		default:
		break;
	}
	*/
}

void pmu6250_spk_enable(DCL_BOOL enable)
{
	pmu_set_spk(RG_SPK_EN, (DCL_UINT32)enable);

	if (enable == DCL_FALSE)
	{
		// pmu_set_spk(SPK_PG_SLEW_I, 0);
	}

	switch (spk_mode)
	{
		case SPK_CLASS_D_MODE:
			// Class-D
			// pmu_set_spk(SPK_OC_EN, (DCL_UINT32)enable);
		break;
		case SPK_CLASS_AB_MODE:
			// Class-AB
			pmu_set_spk(RG_SPK_OC_EN, (DCL_UINT32)enable);
		break;
	}
}
#endif //#if (defined(PMU_6250_REG_API))
