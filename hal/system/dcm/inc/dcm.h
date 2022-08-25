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
 *   dcm.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines device information related stuff
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
 *
 * removed!
 * removed!
 * removed!
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

#include "dma_hw.h"
#include "config_hw.h"
#include "drvpdn.h"
#include "reg_base.h"
#include "l1_interface.h"

#ifndef _DCM_H
#define _DCM_H

#define DRV_Reg16(addr)               (*(volatile kal_uint16 *)(addr))
#define DRV_Reg32(addr)               (*(volatile kal_uint32 *)(addr))
#define DRV_Reg8(addr)                (*(volatile kal_uint8 *)(addr))



#if defined (MT6250)
#define __HW_DCM__
#define __USE_HW_DCM_CYCLE_COUNTER__

#define DCM_LPM_CON         ((volatile kal_uint32*)(CONFIG_base+0x0500))
#define DCM_LPM_TTL_TIME    ((volatile kal_uint32*)(CONFIG_base+0x0504))
#define DCM_LPM_L2H_CNT     ((volatile kal_uint32*)(CONFIG_base+0x0508))
#define DCM_LPM_HIDUR_TIME  ((volatile kal_uint32*)(CONFIG_base+0x050C))
#define DCM_LPM_LGST_HIDUR  ((volatile kal_uint32*)(CONFIG_base+0x0510))
#define DCM_LPM_GDUR_CNT    ((volatile kal_uint32*)(CONFIG_base+0x0514))
#define LPM_MAX_SRC 0xf

#define DCM_PDN_COND0     ((volatile kal_uint32*)(CONFIG_base+0x0300))
#define DCM_PDN_COND1     ((volatile kal_uint32*)(CONFIG_base+0x0304))
#define DCM_PDN_COND2     ((volatile kal_uint32*)(CONFIG_base+0x0308))

#define ARM_SLEEP_CON          ((volatile UINT16P)(ARM_CONFG_base+0x0040))
#define DCM_ENABLE_CHECK       (KAL_TRUE)

#endif  //#if defined (MT6250)


#if defined (MT6260)
#define __HW_DCM__

#define DCM_LPM_CON         ((volatile kal_uint32*)(CONFIG_base+0x0500))
#define DCM_LPM_TTL_TIME    ((volatile kal_uint32*)(CONFIG_base+0x0504))
#define DCM_LPM_L2H_CNT     ((volatile kal_uint32*)(CONFIG_base+0x0508))
#define DCM_LPM_HIDUR_TIME  ((volatile kal_uint32*)(CONFIG_base+0x050C))
#define DCM_LPM_LGST_HIDUR  ((volatile kal_uint32*)(CONFIG_base+0x0510))
#define DCM_LPM_GDUR_CNT    ((volatile kal_uint32*)(CONFIG_base+0x0514))

#define DCM_PDN_COND0     ((volatile kal_uint32*)(CONFIG_base+0x0300))
#define DCM_PDN_COND1     ((volatile kal_uint32*)(CONFIG_base+0x0304))
#define DCM_PDN_COND2     ((volatile kal_uint32*)(CONFIG_base+0x0308))


#define ARM_SLEEP_CON          ((volatile UINT16P)(ARM_CONFG_base+0x0040))
#define DCM_ENABLE_CHECK       (KAL_TRUE)


#define MT6260_CONDE_EMI_DCM_EN     (0x5<<7)
#define MT6260_CONDE_EMI_DCM_MASK   (0x7<<7)
#define MT6260_EMI_DCM_ENABLE()  do { *PLL_CLK_CONDE = *PLL_CLK_CONDE | MT6260_CONDE_EMI_DCM_EN ; } while(0)
#define MT6260_EMI_DCM_DISABLE()  do { *PLL_CLK_CONDE = *PLL_CLK_CONDE & ~MT6260_CONDE_EMI_DCM_MASK ; } while(0)

#endif //#if defined (MT6260)


#if defined(MT6261) || defined(MT2502) || defined(MT2501)
#if !defined (MT6261)
#define MT6261 
#endif

#define __HW_DCM__
#define __USE_HW_DCM_CYCLE_COUNTER__

#define DCM_LPM_CON         ((volatile kal_uint32*)(CONFIG_base+0x0500))
#define DCM_LPM_TTL_TIME    ((volatile kal_uint32*)(CONFIG_base+0x0504))
#define DCM_LPM_L2H_CNT     ((volatile kal_uint32*)(CONFIG_base+0x0508))
#define DCM_LPM_HIDUR_TIME  ((volatile kal_uint32*)(CONFIG_base+0x050C))
#define DCM_LPM_LGST_HIDUR  ((volatile kal_uint32*)(CONFIG_base+0x0510))
#define DCM_LPM_GDUR_CNT    ((volatile kal_uint32*)(CONFIG_base+0x0514))
#define LPM_MAX_SRC 0x15

#define DCM_PDN_COND0     ((volatile kal_uint32*)(CONFIG_base+0x0300))
#define DCM_PDN_COND1     ((volatile kal_uint32*)(CONFIG_base+0x0304))
#define DCM_PDN_COND2     ((volatile kal_uint32*)(CONFIG_base+0x0308))



#define ARM_SLEEP_CON          ((volatile UINT16P)(ARM_CONFG_base+0x0040))
#define DCM_ENABLE_CHECK       (KAL_TRUE)


#endif //#if defined(MT6261) || defined(MT2502) || defined(MT2501)



kal_int32 arm_enter_standby_mode(kal_int32);

#endif /* _DCM_H */
