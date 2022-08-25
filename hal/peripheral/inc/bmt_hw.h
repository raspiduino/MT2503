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
 *    bmt_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines bmt hw register
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
#ifndef _BMT_HW_H
#define _BMT_HW_H

#include "dcl.h"
#include "reg_base.h"
#include "dcl_mixedsys_reg.h"
// ============================================================
// define
// ============================================================
#define DRV_BMT_WriteReg(addr,data)              DRV_WriteReg(addr,data)
#define DRV_BMT_Reg(addr)                        DRV_Reg(addr)                      
#define DRV_BMT_WriteReg32(addr,data)            DRV_WriteReg32(addr,data)          
#define DRV_BMT_Reg32(addr)                      DRV_Reg32(addr)                    
#define DRV_BMT_WriteReg8(addr,data)             DRV_WriteReg8(addr,data)           
#define DRV_BMT_Reg8(addr)                       DRV_Reg8(addr)                     
#define DRV_BMT_ClearBits(addr,data)             DRV_ClearBits(addr,data)           
#define DRV_BMT_SetBits(addr,data)               DRV_SetBits(addr,data)             
#define DRV_BMT_SetData(addr, bitmask, value)    DRV_SetData(addr, bitmask, value)  
#define DRV_BMT_ClearBits32(addr,data)           DRV_ClearBits32(addr,data)         
#define DRV_BMT_SetBits32(addr,data)             DRV_SetBits32(addr,data)           
#define DRV_BMT_SetData32(addr, bitmask, value)  DRV_SetData32(addr, bitmask, value)
#define DRV_BMT_ClearBits8(addr,data)            DRV_ClearBits8(addr,data)          
#define DRV_BMT_SetBits8(addr,data)              DRV_SetBits8(addr,data)            
#define DRV_BMT_SetData8(addr, bitmask, value)   DRV_SetData8(addr, bitmask, value) 
// ============================================================
// ENUM
// ============================================================


// ============================================================
// structure
// ============================================================


// ============================================================
// typedef
// ============================================================
#if defined(MT6255PMU) || defined(MT6256PMU)
#define VBAT_CV_VTH_SIZE		24
#define	CS_VTH_SIZE				 8
#define VCDT_HV_VTH_SIZE		16

#elif defined(MT6250PMU)
#define VBAT_CV_VTH_SIZE		25
#define	CS_VTH_SIZE				 8
#define VCDT_HV_VTH_SIZE		16

#elif defined(MT6260PMU)
#define VBAT_CV_VTH_SIZE		29
#define	CS_VTH_SIZE				 8
#define VCDT_HV_VTH_SIZE		16
#ifdef __DRV_BMT_HIGH_BATTERY_SUPPORT__
#define VBAT_OV_VTH_SIZE         8
#endif

#elif defined(MT6261PMU)
#define VBAT_CV_VTH_SIZE		29
#define	CS_VTH_SIZE				16 
#define VCDT_HV_VTH_SIZE		16
#ifdef __DRV_BMT_HIGH_BATTERY_SUPPORT__
#define VBAT_OV_VTH_SIZE         8
#endif

#else
#define VBAT_CV_VTH_SIZE		25
#define	CS_VTH_SIZE				 8
#define VCDT_HV_VTH_SIZE		16
#ifdef __DRV_BMT_HIGH_BATTERY_SUPPORT__
#define VBAT_OV_VTH_SIZE         8
#endif

#endif


// ============================================================
// External Variables
// ============================================================
extern const DCL_UINT32 chr_VBAT_CV_VTH[VBAT_CV_VTH_SIZE];
extern const DCL_UINT32 chr_CS_VTH[CS_VTH_SIZE];
extern const DCL_UINT32 chr_VCDT_HV_VTH[VCDT_HV_VTH_SIZE];
#ifdef __DRV_BMT_HIGH_BATTERY_SUPPORT__
extern const DCL_UINT32 chr_VBAT_OV_VTH[VBAT_OV_VTH_SIZE];
#endif
// ============================================================
// External function
// ============================================================
extern DCL_UINT32 bmt_parameter_to_value(const DCL_UINT32 *parameter,const DCL_UINT32 array_size, const DCL_UINT32 val);
extern DCL_STATUS bmt_set_register_value(const DCL_UINT32 offset, const DCL_UINT32 mask, const DCL_UINT32 value);
#endif
