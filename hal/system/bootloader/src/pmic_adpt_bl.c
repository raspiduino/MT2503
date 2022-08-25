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
 *    bl_pmic_adpt.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This module is the PMU/PMIC adaptation layer in bootloader
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include 	"drv_comm.h"
#include "dcl.h"

#if defined(__MINI_BOOTLOADER__)

#if defined(MT6260PMU)
extern void setWDTforESD(void);
#endif

void pmu6260_check_vcore_oc()
{
#if defined(MT6260PMU)
    volatile kal_uint32 count;
    volatile kal_uint16 value;

    //when oc occurred, oc status is not always keep high, polling 10 times to check oc status.
    for (count=0;count<10;count++)
    {
        //check vcore oc status
        value = DRV_Reg(0xA0700E24);
        if (0 != (value&0x1))
        {
            //set watch dog timeout time to 1 second.
            setWDTforESD();

            //decrease vcore voltage to 0.8V to release oc phenomenon.
            DRV_SetData(0xA0700230, 0x1F0, 0x140);

            ASSERT(0);
        }
    }
#endif
}

#else //#if defined(__MINI_BOOTLOADER__)

kal_bool pmic_adpt_charge_source(void)
{
	DCL_HANDLE handle;
	PMU_CTRL_CHR_GET_CHR_DET_STATUS chrStatus;
	handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	DclPMU_Control(handle, CHR_GET_CHR_DET_STATUS, (DCL_CTRL_DATA_T *)&chrStatus);
	DclPMU_Close(handle);

	return (kal_bool)chrStatus.enable;

}

#endif //#if defined(__MINI_BOOTLOADER__)

//kal_bool USBDL_Cable_IN(void)
//{
//	return pmic_adpt_charge_source();
//}

