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
 *   idp_imgdma_ovl.h
 *
 * Project:
 * --------
 *   Maui
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
 * 09 20 2011 chelun.tsai
 * removed!
 * .
 *
 * 05 27 2011 chelun.tsai
 * removed!
 * MT6526 E2 MDP driver.
 *
 * 05 05 2011 chelun.tsai
 * removed!
 * last check in befor sample back.
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_imgdma_ovl_mt6256_e2_h__
#define __idp_imgdma_ovl_mt6256_e2_h__

#ifndef THIS_FILE_BELONGS_TO_IMAGE_DATA_PATH_MODULE_INTERNAL
#error "Hay~! Man~! You can not include this file directly~!"
#endif

#include <idp_define.h>
#include "drv_features_mdp.h"

#if defined(DRV_IDP_MT6256_E2_SERIES)

#include "idp_imgdma.h"
#include <idp_core.h>
#include "idp_hw_common.h"
#include "img_common_enum.h"
#include "reg_base.h"

#ifndef MDP_C_MODEL

#define OVL_DMA_BASE OVL_DMA_base

#define IMGDMA_OVL_IRQ_FLAG_REG         (OVL_DMA_BASE+0x000)  
#define IMGDMA_OVL_IRQ_FLAG_CLR_REG     (OVL_DMA_BASE+0x008)  
#define IMGDMA_OVL_CFG_REG              (OVL_DMA_BASE+0x018)  
#define IMGDMA_OVL_IN_SEL_REG           (OVL_DMA_BASE+0x020)  
#define IMGDMA_OVL_STOP_REG             (OVL_DMA_BASE+0x028)  
#define IMGDMA_OVL_EN_REG               (OVL_DMA_BASE+0x030)  
#define IMGDMA_OVL_RESET_REG            (OVL_DMA_BASE+0x038)  
#define IMGDMA_OVL_LOCK_REG             (OVL_DMA_BASE+0x03C)  
#define IMGDMA_OVL_QUEUE_RSTA_REG       (OVL_DMA_BASE+0x040)  
#define IMGDMA_OVL_RD_BASE_REG          (OVL_DMA_BASE+0x048)  
#define IMGDMA_OVL_RPT_ADVANCE_REG      (OVL_DMA_BASE+0x050)  
#define IMGDMA_OVL_QUEUE_WSTA_REG       (OVL_DMA_BASE+0x058)  
#define IMGDMA_OVL_WR_BASE_REG          (OVL_DMA_BASE+0x060)  
#define IMGDMA_OVL_WPT_ADVANCE_REG      (OVL_DMA_BASE+0x068)  
#define IMGDMA_OVL_QUEUE_DATA_REG       (OVL_DMA_BASE+0x070)  
#define IMGDMA_OVL_QUEUE_BASE_REG       (OVL_DMA_BASE+0x078)  
#define IMGDMA_OVL_EXEC_CNT_REG         (OVL_DMA_BASE+0x080)  
#define IMGDMA_OVL_HEADER_BASE_REG      (OVL_DMA_BASE+0x100)  
#define IMGDMA_OVL_MASK_BASE_REG        (OVL_DMA_BASE+0x108)  
#define IMGDMA_OVL_SRC_SIZE_REG         (OVL_DMA_BASE+0x110)  
#define IMGDMA_OVL_OFFSET_REG           (OVL_DMA_BASE+0x118)  
#define IMGDMA_OVL_MASK_SRC_SIZE_REG    (OVL_DMA_BASE+0x120)  
#define IMGDMA_OVL_MASK_DST_SIZE_REG    (OVL_DMA_BASE+0x128)  
#define IMGDMA_OVL_MASK_CFG_REG         (OVL_DMA_BASE+0x130)  
#define IMGDMA_OVL_CON_REG              (OVL_DMA_BASE+0x138)  
#define IMGDMA_OVL_CUR_SRC_POSITION_REG (OVL_DMA_BASE+0x140)  
#define IMGDMA_OVL_CUR_MASK_POSITION    (OVL_DMA_BASE+0x148)    
#define IMGDMA_OVL_PAL_COLOR_00_REG     (OVL_DMA_BASE+0x800)

#define REG_IMGDMA_OVL_IRQ_FLAG             *((volatile unsigned int*)IMGDMA_OVL_IRQ_FLAG_REG)        
#define REG_IMGDMA_OVL_IRQ_FLAG_CLR         *((volatile unsigned int*)IMGDMA_OVL_IRQ_FLAG_CLR_REG)    
#define REG_IMGDMA_OVL_CFG                  *((volatile unsigned int*)IMGDMA_OVL_CFG_REG)             
#define REG_IMGDMA_OVL_IN_SEL               *((volatile unsigned int*)IMGDMA_OVL_IN_SEL_REG)          
#define REG_IMGDMA_OVL_STOP                 *((volatile unsigned int*)IMGDMA_OVL_STOP_REG)            
#define REG_IMGDMA_OVL_EN                   *((volatile unsigned int*)IMGDMA_OVL_EN_REG)              
#define REG_IMGDMA_OVL_RESET                *((volatile unsigned int*)IMGDMA_OVL_RESET_REG)           
#define REG_IMGDMA_OVL_LOCK                 *((volatile unsigned int*)IMGDMA_OVL_LOCK_REG)            
#define REG_IMGDMA_OVL_QUEUE_RSTA           *((volatile unsigned int*)IMGDMA_OVL_QUEUE_RSTA_REG)      
#define REG_IMGDMA_OVL_RD_BASE              *((volatile unsigned int*)IMGDMA_OVL_RD_BASE_REG)         
#define REG_IMGDMA_OVL_RPT_ADVANCE          *((volatile unsigned int*)IMGDMA_OVL_RPT_ADVANCE_REG)     
#define REG_IMGDMA_OVL_QUEUE_WSTA           *((volatile unsigned int*)IMGDMA_OVL_QUEUE_WSTA_REG)      
#define REG_IMGDMA_OVL_WR_BASE              *((volatile unsigned int*)IMGDMA_OVL_WR_BASE_REG)         
#define REG_IMGDMA_OVL_WPT_ADVANCE          *((volatile unsigned int*)IMGDMA_OVL_WPT_ADVANCE_REG)     
#define REG_IMGDMA_OVL_QUEUE_DATA           *((volatile unsigned int*)IMGDMA_OVL_QUEUE_DATA_REG)      
#define REG_IMGDMA_OVL_QUEUE_BASE           *((volatile unsigned int*)IMGDMA_OVL_QUEUE_BASE_REG)      
#define REG_IMGDMA_OVL_EXEC_CNT             *((volatile unsigned int*)IMGDMA_OVL_EXEC_CNT_REG)        
#define REG_IMGDMA_OVL_HEADER_BASE          *((volatile unsigned int*)IMGDMA_OVL_HEADER_BASE_REG)     
#define REG_IMGDMA_OVL_MASK_BASE            *((volatile unsigned int*)IMGDMA_OVL_MASK_BASE_REG)       
#define REG_IMGDMA_OVL_SRC_SIZE             *((volatile unsigned int*)IMGDMA_OVL_SRC_SIZE_REG)        
#define REG_IMGDMA_OVL_OFFSET               *((volatile unsigned int*)IMGDMA_OVL_OFFSET_REG)          
#define REG_IMGDMA_OVL_MASK_SRC_SIZE        *((volatile unsigned int*)IMGDMA_OVL_MASK_SRC_SIZE_REG)   
#define REG_IMGDMA_OVL_MASK_DST_SIZE        *((volatile unsigned int*)IMGDMA_OVL_MASK_DST_SIZE_REG)   
#define REG_IMGDMA_OVL_MASK_CFG             *((volatile unsigned int*)IMGDMA_OVL_MASK_CFG_REG)        
#define REG_IMGDMA_OVL_CON                  *((volatile unsigned int*)IMGDMA_OVL_CON_REG)             
#define REG_IMGDMA_OVL_CUR_SRC_POSITION     *((volatile unsigned int*)IMGDMA_OVL_CUR_SRC_POSITION_REG)
#define REG_IMGDMA_OVL_CUR_MASK_POSITION    *((volatile unsigned int*)IMGDMA_OVL_CUR_MASK_POSITION)    
#define REG_IMGDMA_OVL_PAL_COLOR_00         *((volatile unsigned int*)IMGDMA_OVL_PAL_COLOR_00_REG)    
#else //MDP_C_MODEL
#define REG_IMGDMA_OVL_IRQ_FLAG             (OVL_DMA_STATUS_FLAG)   
#define REG_IMGDMA_OVL_IRQ_FLAG_CLR         (OVL_DMA_STATUS_FLAG_CLR)
#define REG_IMGDMA_OVL_CFG                  (OVL_DMA_CFG)
#define REG_IMGDMA_OVL_IN_SEL               (OVL_DMA_IN_SEL)
#define REG_IMGDMA_OVL_STOP                 (OVL_DMA_STOP)
#define REG_IMGDMA_OVL_EN                   (OVL_DMA_EN)
#define REG_IMGDMA_OVL_RESET                (OVL_DMA_RESET)
#define REG_IMGDMA_OVL_LOCK                 (OVL_DMA_LOCK)
#define REG_IMGDMA_OVL_QUEUE_RSTA           (OVL_DMA_QUEUE_RSTA)
#define REG_IMGDMA_OVL_RD_BASE              (OVL_DMA_RD_BASE)
#define REG_IMGDMA_OVL_RPT_ADVANCE          (OVL_DMA_RPT_ADV)
#define REG_IMGDMA_OVL_QUEUE_WSTA           (OVL_DMA_QUEUE_WSTA)
#define REG_IMGDMA_OVL_WR_BASE              (OVL_DMA_WR_BASE)
#define REG_IMGDMA_OVL_WPT_ADVANCE          (OVL_DMA_WPT_ADV)
#define REG_IMGDMA_OVL_QUEUE_DATA           (OVL_DMA_QUEUE_DATA)
#define REG_IMGDMA_OVL_QUEUE_BASE           (OVL_DMA_QUEUE_BASE)
#define REG_IMGDMA_OVL_EXEC_CNT             (OVL_DMA_EXEC_CNT)
#define REG_IMGDMA_OVL_HEADER_BASE          (OVL_DMA_HEADER_BASE)
#define REG_IMGDMA_OVL_MASK_BASE            (OVL_DMA_MASK_BASE)
#define REG_IMGDMA_OVL_SRC_SIZE             (OVL_DMA_SRC_SIZE)
#define REG_IMGDMA_OVL_OFFSET               (OVL_DMA_OFFSET)
#define REG_IMGDMA_OVL_MASK_SRC_SIZE        (OVL_DMA_MASK_SRC_SIZE)
#define REG_IMGDMA_OVL_MASK_DST_SIZE        (OVL_DMA_MASK_DST_SIZE)
#define REG_IMGDMA_OVL_MASK_CFG             (OVL_DMA_MASK_CFG)
#define REG_IMGDMA_OVL_CON                  (OVL_DMA_CON)
#define REG_IMGDMA_OVL_CUR_SRC_POSITION     (OVL_DMA_CUR_SRC_POSITION)
#define REG_IMGDMA_OVL_CUR_MASK_POSITION    (OVL_DMA_CUR_MASK_SRC_POSITION)
#define REG_IMGDMA_OVL_PAL_COLOR_00         (OVL_DMA_PAL_COLOR_00)
#define REG_IMGDMA_OVL_PAL_COLOR_01         (OVL_DMA_PAL_COLOR_01)
#define REG_IMGDMA_OVL_PAL_COLOR_02         (OVL_DMA_PAL_COLOR_02)
#define REG_IMGDMA_OVL_PAL_COLOR_03         (OVL_DMA_PAL_COLOR_03)
#define REG_IMGDMA_OVL_PAL_COLOR_04         (OVL_DMA_PAL_COLOR_04)
#define REG_IMGDMA_OVL_PAL_COLOR_05         (OVL_DMA_PAL_COLOR_05)
#define REG_IMGDMA_OVL_PAL_COLOR_06         (OVL_DMA_PAL_COLOR_06)
#define REG_IMGDMA_OVL_PAL_COLOR_07         (OVL_DMA_PAL_COLOR_07)
#define REG_IMGDMA_OVL_PAL_COLOR_08         (OVL_DMA_PAL_COLOR_08)
#define REG_IMGDMA_OVL_PAL_COLOR_09         (OVL_DMA_PAL_COLOR_09)
#define REG_IMGDMA_OVL_PAL_COLOR_0A         (OVL_DMA_PAL_COLOR_0A)
#define REG_IMGDMA_OVL_PAL_COLOR_0B         (OVL_DMA_PAL_COLOR_0B)
#define REG_IMGDMA_OVL_PAL_COLOR_0C         (OVL_DMA_PAL_COLOR_0C)
#define REG_IMGDMA_OVL_PAL_COLOR_0D         (OVL_DMA_PAL_COLOR_0D)
#define REG_IMGDMA_OVL_PAL_COLOR_0E         (OVL_DMA_PAL_COLOR_0E)
#define REG_IMGDMA_OVL_PAL_COLOR_0F         (OVL_DMA_PAL_COLOR_0F)
#define REG_IMGDMA_OVL_PAL_COLOR_10         (OVL_DMA_PAL_COLOR_10)
#define REG_IMGDMA_OVL_PAL_COLOR_11         (OVL_DMA_PAL_COLOR_11)
#define REG_IMGDMA_OVL_PAL_COLOR_12         (OVL_DMA_PAL_COLOR_12)
#define REG_IMGDMA_OVL_PAL_COLOR_13         (OVL_DMA_PAL_COLOR_13)
#define REG_IMGDMA_OVL_PAL_COLOR_14         (OVL_DMA_PAL_COLOR_14)
#define REG_IMGDMA_OVL_PAL_COLOR_15         (OVL_DMA_PAL_COLOR_15)
#define REG_IMGDMA_OVL_PAL_COLOR_16         (OVL_DMA_PAL_COLOR_16)
#define REG_IMGDMA_OVL_PAL_COLOR_17         (OVL_DMA_PAL_COLOR_17)
#define REG_IMGDMA_OVL_PAL_COLOR_18         (OVL_DMA_PAL_COLOR_18)
#define REG_IMGDMA_OVL_PAL_COLOR_19         (OVL_DMA_PAL_COLOR_19)
#define REG_IMGDMA_OVL_PAL_COLOR_1A         (OVL_DMA_PAL_COLOR_1A)
#define REG_IMGDMA_OVL_PAL_COLOR_1B         (OVL_DMA_PAL_COLOR_1B)
#define REG_IMGDMA_OVL_PAL_COLOR_1C         (OVL_DMA_PAL_COLOR_1C)
#define REG_IMGDMA_OVL_PAL_COLOR_1D         (OVL_DMA_PAL_COLOR_1D)
#define REG_IMGDMA_OVL_PAL_COLOR_1E         (OVL_DMA_PAL_COLOR_1E)
#define REG_IMGDMA_OVL_PAL_COLOR_1F         (OVL_DMA_PAL_COLOR_1F)
#define REG_IMGDMA_OVL_PAL_COLOR_20         (OVL_DMA_PAL_COLOR_20)
#define REG_IMGDMA_OVL_PAL_COLOR_21         (OVL_DMA_PAL_COLOR_21)
#define REG_IMGDMA_OVL_PAL_COLOR_22         (OVL_DMA_PAL_COLOR_22)
#define REG_IMGDMA_OVL_PAL_COLOR_23         (OVL_DMA_PAL_COLOR_23)
#define REG_IMGDMA_OVL_PAL_COLOR_24         (OVL_DMA_PAL_COLOR_24)
#define REG_IMGDMA_OVL_PAL_COLOR_25         (OVL_DMA_PAL_COLOR_25)
#define REG_IMGDMA_OVL_PAL_COLOR_26         (OVL_DMA_PAL_COLOR_26)
#define REG_IMGDMA_OVL_PAL_COLOR_27         (OVL_DMA_PAL_COLOR_27)
#define REG_IMGDMA_OVL_PAL_COLOR_28         (OVL_DMA_PAL_COLOR_28)
#define REG_IMGDMA_OVL_PAL_COLOR_29         (OVL_DMA_PAL_COLOR_29)
#define REG_IMGDMA_OVL_PAL_COLOR_2A         (OVL_DMA_PAL_COLOR_2A)
#define REG_IMGDMA_OVL_PAL_COLOR_2B         (OVL_DMA_PAL_COLOR_2B)
#define REG_IMGDMA_OVL_PAL_COLOR_2C         (OVL_DMA_PAL_COLOR_2C)
#define REG_IMGDMA_OVL_PAL_COLOR_2D         (OVL_DMA_PAL_COLOR_2D)
#define REG_IMGDMA_OVL_PAL_COLOR_2E         (OVL_DMA_PAL_COLOR_2E)
#define REG_IMGDMA_OVL_PAL_COLOR_2F         (OVL_DMA_PAL_COLOR_2F)
#define REG_IMGDMA_OVL_PAL_COLOR_30         (OVL_DMA_PAL_COLOR_30)
#define REG_IMGDMA_OVL_PAL_COLOR_31         (OVL_DMA_PAL_COLOR_31)
#define REG_IMGDMA_OVL_PAL_COLOR_32         (OVL_DMA_PAL_COLOR_32)
#define REG_IMGDMA_OVL_PAL_COLOR_33         (OVL_DMA_PAL_COLOR_33)
#define REG_IMGDMA_OVL_PAL_COLOR_34         (OVL_DMA_PAL_COLOR_34)
#define REG_IMGDMA_OVL_PAL_COLOR_35         (OVL_DMA_PAL_COLOR_35)
#define REG_IMGDMA_OVL_PAL_COLOR_36         (OVL_DMA_PAL_COLOR_36)
#define REG_IMGDMA_OVL_PAL_COLOR_37         (OVL_DMA_PAL_COLOR_37)
#define REG_IMGDMA_OVL_PAL_COLOR_38         (OVL_DMA_PAL_COLOR_38)
#define REG_IMGDMA_OVL_PAL_COLOR_39         (OVL_DMA_PAL_COLOR_39)
#define REG_IMGDMA_OVL_PAL_COLOR_3A         (OVL_DMA_PAL_COLOR_3A)
#define REG_IMGDMA_OVL_PAL_COLOR_3B         (OVL_DMA_PAL_COLOR_3B)
#define REG_IMGDMA_OVL_PAL_COLOR_3C         (OVL_DMA_PAL_COLOR_3C)
#define REG_IMGDMA_OVL_PAL_COLOR_3D         (OVL_DMA_PAL_COLOR_3D)
#define REG_IMGDMA_OVL_PAL_COLOR_3E         (OVL_DMA_PAL_COLOR_3E)
#define REG_IMGDMA_OVL_PAL_COLOR_3F         (OVL_DMA_PAL_COLOR_3F)
#define REG_IMGDMA_OVL_PAL_COLOR_40         (OVL_DMA_PAL_COLOR_40)
#define REG_IMGDMA_OVL_PAL_COLOR_41         (OVL_DMA_PAL_COLOR_41)
#define REG_IMGDMA_OVL_PAL_COLOR_42         (OVL_DMA_PAL_COLOR_42)
#define REG_IMGDMA_OVL_PAL_COLOR_43         (OVL_DMA_PAL_COLOR_43)
#define REG_IMGDMA_OVL_PAL_COLOR_44         (OVL_DMA_PAL_COLOR_44)
#define REG_IMGDMA_OVL_PAL_COLOR_45         (OVL_DMA_PAL_COLOR_45)
#define REG_IMGDMA_OVL_PAL_COLOR_46         (OVL_DMA_PAL_COLOR_46)
#define REG_IMGDMA_OVL_PAL_COLOR_47         (OVL_DMA_PAL_COLOR_47)
#define REG_IMGDMA_OVL_PAL_COLOR_48         (OVL_DMA_PAL_COLOR_48)
#define REG_IMGDMA_OVL_PAL_COLOR_49         (OVL_DMA_PAL_COLOR_49)
#define REG_IMGDMA_OVL_PAL_COLOR_4A         (OVL_DMA_PAL_COLOR_4A)
#define REG_IMGDMA_OVL_PAL_COLOR_4B         (OVL_DMA_PAL_COLOR_4B)
#define REG_IMGDMA_OVL_PAL_COLOR_4C         (OVL_DMA_PAL_COLOR_4C)
#define REG_IMGDMA_OVL_PAL_COLOR_4D         (OVL_DMA_PAL_COLOR_4D)
#define REG_IMGDMA_OVL_PAL_COLOR_4E         (OVL_DMA_PAL_COLOR_4E)
#define REG_IMGDMA_OVL_PAL_COLOR_4F         (OVL_DMA_PAL_COLOR_4F)
#define REG_IMGDMA_OVL_PAL_COLOR_50         (OVL_DMA_PAL_COLOR_50)
#define REG_IMGDMA_OVL_PAL_COLOR_51         (OVL_DMA_PAL_COLOR_51)
#define REG_IMGDMA_OVL_PAL_COLOR_52         (OVL_DMA_PAL_COLOR_52)
#define REG_IMGDMA_OVL_PAL_COLOR_53         (OVL_DMA_PAL_COLOR_53)
#define REG_IMGDMA_OVL_PAL_COLOR_54         (OVL_DMA_PAL_COLOR_54)
#define REG_IMGDMA_OVL_PAL_COLOR_55         (OVL_DMA_PAL_COLOR_55)
#define REG_IMGDMA_OVL_PAL_COLOR_56         (OVL_DMA_PAL_COLOR_56)
#define REG_IMGDMA_OVL_PAL_COLOR_57         (OVL_DMA_PAL_COLOR_57)
#define REG_IMGDMA_OVL_PAL_COLOR_58         (OVL_DMA_PAL_COLOR_58)
#define REG_IMGDMA_OVL_PAL_COLOR_59         (OVL_DMA_PAL_COLOR_59)
#define REG_IMGDMA_OVL_PAL_COLOR_5A         (OVL_DMA_PAL_COLOR_5A)
#define REG_IMGDMA_OVL_PAL_COLOR_5B         (OVL_DMA_PAL_COLOR_5B)
#define REG_IMGDMA_OVL_PAL_COLOR_5C         (OVL_DMA_PAL_COLOR_5C)
#define REG_IMGDMA_OVL_PAL_COLOR_5D         (OVL_DMA_PAL_COLOR_5D)
#define REG_IMGDMA_OVL_PAL_COLOR_5E         (OVL_DMA_PAL_COLOR_5E)
#define REG_IMGDMA_OVL_PAL_COLOR_5F         (OVL_DMA_PAL_COLOR_5F)
#define REG_IMGDMA_OVL_PAL_COLOR_60         (OVL_DMA_PAL_COLOR_60)
#define REG_IMGDMA_OVL_PAL_COLOR_61         (OVL_DMA_PAL_COLOR_61)
#define REG_IMGDMA_OVL_PAL_COLOR_62         (OVL_DMA_PAL_COLOR_62)
#define REG_IMGDMA_OVL_PAL_COLOR_63         (OVL_DMA_PAL_COLOR_63)
#define REG_IMGDMA_OVL_PAL_COLOR_64         (OVL_DMA_PAL_COLOR_64)
#define REG_IMGDMA_OVL_PAL_COLOR_65         (OVL_DMA_PAL_COLOR_65)
#define REG_IMGDMA_OVL_PAL_COLOR_66         (OVL_DMA_PAL_COLOR_66)
#define REG_IMGDMA_OVL_PAL_COLOR_67         (OVL_DMA_PAL_COLOR_67)
#define REG_IMGDMA_OVL_PAL_COLOR_68         (OVL_DMA_PAL_COLOR_68)
#define REG_IMGDMA_OVL_PAL_COLOR_69         (OVL_DMA_PAL_COLOR_69)
#define REG_IMGDMA_OVL_PAL_COLOR_6A         (OVL_DMA_PAL_COLOR_6A)
#define REG_IMGDMA_OVL_PAL_COLOR_6B         (OVL_DMA_PAL_COLOR_6B)
#define REG_IMGDMA_OVL_PAL_COLOR_6C         (OVL_DMA_PAL_COLOR_6C)
#define REG_IMGDMA_OVL_PAL_COLOR_6D         (OVL_DMA_PAL_COLOR_6D)
#define REG_IMGDMA_OVL_PAL_COLOR_6E         (OVL_DMA_PAL_COLOR_6E)
#define REG_IMGDMA_OVL_PAL_COLOR_6F         (OVL_DMA_PAL_COLOR_6F)
#define REG_IMGDMA_OVL_PAL_COLOR_70         (OVL_DMA_PAL_COLOR_70)
#define REG_IMGDMA_OVL_PAL_COLOR_71         (OVL_DMA_PAL_COLOR_71)
#define REG_IMGDMA_OVL_PAL_COLOR_72         (OVL_DMA_PAL_COLOR_72)
#define REG_IMGDMA_OVL_PAL_COLOR_73         (OVL_DMA_PAL_COLOR_73)
#define REG_IMGDMA_OVL_PAL_COLOR_74         (OVL_DMA_PAL_COLOR_74)
#define REG_IMGDMA_OVL_PAL_COLOR_75         (OVL_DMA_PAL_COLOR_75)
#define REG_IMGDMA_OVL_PAL_COLOR_76         (OVL_DMA_PAL_COLOR_76)
#define REG_IMGDMA_OVL_PAL_COLOR_77         (OVL_DMA_PAL_COLOR_77)
#define REG_IMGDMA_OVL_PAL_COLOR_78         (OVL_DMA_PAL_COLOR_78)
#define REG_IMGDMA_OVL_PAL_COLOR_79         (OVL_DMA_PAL_COLOR_79)
#define REG_IMGDMA_OVL_PAL_COLOR_7A         (OVL_DMA_PAL_COLOR_7A)
#define REG_IMGDMA_OVL_PAL_COLOR_7B         (OVL_DMA_PAL_COLOR_7B)
#define REG_IMGDMA_OVL_PAL_COLOR_7C         (OVL_DMA_PAL_COLOR_7C)
#define REG_IMGDMA_OVL_PAL_COLOR_7D         (OVL_DMA_PAL_COLOR_7D)
#define REG_IMGDMA_OVL_PAL_COLOR_7E         (OVL_DMA_PAL_COLOR_7E)
#define REG_IMGDMA_OVL_PAL_COLOR_7F         (OVL_DMA_PAL_COLOR_7F)
#define REG_IMGDMA_OVL_PAL_COLOR_80         (OVL_DMA_PAL_COLOR_80)
#define REG_IMGDMA_OVL_PAL_COLOR_81         (OVL_DMA_PAL_COLOR_81)
#define REG_IMGDMA_OVL_PAL_COLOR_82         (OVL_DMA_PAL_COLOR_82)
#define REG_IMGDMA_OVL_PAL_COLOR_83         (OVL_DMA_PAL_COLOR_83)
#define REG_IMGDMA_OVL_PAL_COLOR_84         (OVL_DMA_PAL_COLOR_84)
#define REG_IMGDMA_OVL_PAL_COLOR_85         (OVL_DMA_PAL_COLOR_85)
#define REG_IMGDMA_OVL_PAL_COLOR_86         (OVL_DMA_PAL_COLOR_86)
#define REG_IMGDMA_OVL_PAL_COLOR_87         (OVL_DMA_PAL_COLOR_87)
#define REG_IMGDMA_OVL_PAL_COLOR_88         (OVL_DMA_PAL_COLOR_88)
#define REG_IMGDMA_OVL_PAL_COLOR_89         (OVL_DMA_PAL_COLOR_89)
#define REG_IMGDMA_OVL_PAL_COLOR_8A         (OVL_DMA_PAL_COLOR_8A)
#define REG_IMGDMA_OVL_PAL_COLOR_8B         (OVL_DMA_PAL_COLOR_8B)
#define REG_IMGDMA_OVL_PAL_COLOR_8C         (OVL_DMA_PAL_COLOR_8C)
#define REG_IMGDMA_OVL_PAL_COLOR_8D         (OVL_DMA_PAL_COLOR_8D)
#define REG_IMGDMA_OVL_PAL_COLOR_8E         (OVL_DMA_PAL_COLOR_8E)
#define REG_IMGDMA_OVL_PAL_COLOR_8F         (OVL_DMA_PAL_COLOR_8F)
#define REG_IMGDMA_OVL_PAL_COLOR_90         (OVL_DMA_PAL_COLOR_90)
#define REG_IMGDMA_OVL_PAL_COLOR_91         (OVL_DMA_PAL_COLOR_91)
#define REG_IMGDMA_OVL_PAL_COLOR_92         (OVL_DMA_PAL_COLOR_92)
#define REG_IMGDMA_OVL_PAL_COLOR_93         (OVL_DMA_PAL_COLOR_93)
#define REG_IMGDMA_OVL_PAL_COLOR_94         (OVL_DMA_PAL_COLOR_94)
#define REG_IMGDMA_OVL_PAL_COLOR_95         (OVL_DMA_PAL_COLOR_95)
#define REG_IMGDMA_OVL_PAL_COLOR_96         (OVL_DMA_PAL_COLOR_96)
#define REG_IMGDMA_OVL_PAL_COLOR_97         (OVL_DMA_PAL_COLOR_97)
#define REG_IMGDMA_OVL_PAL_COLOR_98         (OVL_DMA_PAL_COLOR_98)
#define REG_IMGDMA_OVL_PAL_COLOR_99         (OVL_DMA_PAL_COLOR_99)
#define REG_IMGDMA_OVL_PAL_COLOR_9A         (OVL_DMA_PAL_COLOR_9A)
#define REG_IMGDMA_OVL_PAL_COLOR_9B         (OVL_DMA_PAL_COLOR_9B)
#define REG_IMGDMA_OVL_PAL_COLOR_9C         (OVL_DMA_PAL_COLOR_9C)
#define REG_IMGDMA_OVL_PAL_COLOR_9D         (OVL_DMA_PAL_COLOR_9D)
#define REG_IMGDMA_OVL_PAL_COLOR_9E         (OVL_DMA_PAL_COLOR_9E)
#define REG_IMGDMA_OVL_PAL_COLOR_9F         (OVL_DMA_PAL_COLOR_9F)
#define REG_IMGDMA_OVL_PAL_COLOR_A0         (OVL_DMA_PAL_COLOR_A0)
#define REG_IMGDMA_OVL_PAL_COLOR_A1         (OVL_DMA_PAL_COLOR_A1)
#define REG_IMGDMA_OVL_PAL_COLOR_A2         (OVL_DMA_PAL_COLOR_A2)
#define REG_IMGDMA_OVL_PAL_COLOR_A3         (OVL_DMA_PAL_COLOR_A3)
#define REG_IMGDMA_OVL_PAL_COLOR_A4         (OVL_DMA_PAL_COLOR_A4)
#define REG_IMGDMA_OVL_PAL_COLOR_A5         (OVL_DMA_PAL_COLOR_A5)
#define REG_IMGDMA_OVL_PAL_COLOR_A6         (OVL_DMA_PAL_COLOR_A6)
#define REG_IMGDMA_OVL_PAL_COLOR_A7         (OVL_DMA_PAL_COLOR_A7)
#define REG_IMGDMA_OVL_PAL_COLOR_A8         (OVL_DMA_PAL_COLOR_A8)
#define REG_IMGDMA_OVL_PAL_COLOR_A9         (OVL_DMA_PAL_COLOR_A9)
#define REG_IMGDMA_OVL_PAL_COLOR_AA         (OVL_DMA_PAL_COLOR_AA)
#define REG_IMGDMA_OVL_PAL_COLOR_AB         (OVL_DMA_PAL_COLOR_AB)
#define REG_IMGDMA_OVL_PAL_COLOR_AC         (OVL_DMA_PAL_COLOR_AC)
#define REG_IMGDMA_OVL_PAL_COLOR_AD         (OVL_DMA_PAL_COLOR_AD)
#define REG_IMGDMA_OVL_PAL_COLOR_AE         (OVL_DMA_PAL_COLOR_AE)
#define REG_IMGDMA_OVL_PAL_COLOR_AF         (OVL_DMA_PAL_COLOR_AF)
#define REG_IMGDMA_OVL_PAL_COLOR_B0         (OVL_DMA_PAL_COLOR_B0)
#define REG_IMGDMA_OVL_PAL_COLOR_B1         (OVL_DMA_PAL_COLOR_B1)
#define REG_IMGDMA_OVL_PAL_COLOR_B2         (OVL_DMA_PAL_COLOR_B2)
#define REG_IMGDMA_OVL_PAL_COLOR_B3         (OVL_DMA_PAL_COLOR_B3)
#define REG_IMGDMA_OVL_PAL_COLOR_B4         (OVL_DMA_PAL_COLOR_B4)
#define REG_IMGDMA_OVL_PAL_COLOR_B5         (OVL_DMA_PAL_COLOR_B5)
#define REG_IMGDMA_OVL_PAL_COLOR_B6         (OVL_DMA_PAL_COLOR_B6)
#define REG_IMGDMA_OVL_PAL_COLOR_B7         (OVL_DMA_PAL_COLOR_B7)
#define REG_IMGDMA_OVL_PAL_COLOR_B8         (OVL_DMA_PAL_COLOR_B8)
#define REG_IMGDMA_OVL_PAL_COLOR_B9         (OVL_DMA_PAL_COLOR_B9)
#define REG_IMGDMA_OVL_PAL_COLOR_BA         (OVL_DMA_PAL_COLOR_BA)
#define REG_IMGDMA_OVL_PAL_COLOR_BB         (OVL_DMA_PAL_COLOR_BB)
#define REG_IMGDMA_OVL_PAL_COLOR_BC         (OVL_DMA_PAL_COLOR_BC)
#define REG_IMGDMA_OVL_PAL_COLOR_BD         (OVL_DMA_PAL_COLOR_BD)
#define REG_IMGDMA_OVL_PAL_COLOR_BE         (OVL_DMA_PAL_COLOR_BE)
#define REG_IMGDMA_OVL_PAL_COLOR_BF         (OVL_DMA_PAL_COLOR_BF)
#define REG_IMGDMA_OVL_PAL_COLOR_C0         (OVL_DMA_PAL_COLOR_C0)
#define REG_IMGDMA_OVL_PAL_COLOR_C1         (OVL_DMA_PAL_COLOR_C1)
#define REG_IMGDMA_OVL_PAL_COLOR_C2         (OVL_DMA_PAL_COLOR_C2)
#define REG_IMGDMA_OVL_PAL_COLOR_C3         (OVL_DMA_PAL_COLOR_C3)
#define REG_IMGDMA_OVL_PAL_COLOR_C4         (OVL_DMA_PAL_COLOR_C4)
#define REG_IMGDMA_OVL_PAL_COLOR_C5         (OVL_DMA_PAL_COLOR_C5)
#define REG_IMGDMA_OVL_PAL_COLOR_C6         (OVL_DMA_PAL_COLOR_C6)
#define REG_IMGDMA_OVL_PAL_COLOR_C7         (OVL_DMA_PAL_COLOR_C7)
#define REG_IMGDMA_OVL_PAL_COLOR_C8         (OVL_DMA_PAL_COLOR_C8)
#define REG_IMGDMA_OVL_PAL_COLOR_C9         (OVL_DMA_PAL_COLOR_C9)
#define REG_IMGDMA_OVL_PAL_COLOR_CA         (OVL_DMA_PAL_COLOR_CA)
#define REG_IMGDMA_OVL_PAL_COLOR_CB         (OVL_DMA_PAL_COLOR_CB)
#define REG_IMGDMA_OVL_PAL_COLOR_CC         (OVL_DMA_PAL_COLOR_CC)
#define REG_IMGDMA_OVL_PAL_COLOR_CD         (OVL_DMA_PAL_COLOR_CD)
#define REG_IMGDMA_OVL_PAL_COLOR_CE         (OVL_DMA_PAL_COLOR_CE)
#define REG_IMGDMA_OVL_PAL_COLOR_CF         (OVL_DMA_PAL_COLOR_CF)
#define REG_IMGDMA_OVL_PAL_COLOR_D0         (OVL_DMA_PAL_COLOR_D0)
#define REG_IMGDMA_OVL_PAL_COLOR_D1         (OVL_DMA_PAL_COLOR_D1)
#define REG_IMGDMA_OVL_PAL_COLOR_D2         (OVL_DMA_PAL_COLOR_D2)
#define REG_IMGDMA_OVL_PAL_COLOR_D3         (OVL_DMA_PAL_COLOR_D3)
#define REG_IMGDMA_OVL_PAL_COLOR_D4         (OVL_DMA_PAL_COLOR_D4)
#define REG_IMGDMA_OVL_PAL_COLOR_D5         (OVL_DMA_PAL_COLOR_D5)
#define REG_IMGDMA_OVL_PAL_COLOR_D6         (OVL_DMA_PAL_COLOR_D6)
#define REG_IMGDMA_OVL_PAL_COLOR_D7         (OVL_DMA_PAL_COLOR_D7)
#define REG_IMGDMA_OVL_PAL_COLOR_D8         (OVL_DMA_PAL_COLOR_D8)
#define REG_IMGDMA_OVL_PAL_COLOR_D9         (OVL_DMA_PAL_COLOR_D9)
#define REG_IMGDMA_OVL_PAL_COLOR_DA         (OVL_DMA_PAL_COLOR_DA)
#define REG_IMGDMA_OVL_PAL_COLOR_DB         (OVL_DMA_PAL_COLOR_DB)
#define REG_IMGDMA_OVL_PAL_COLOR_DC         (OVL_DMA_PAL_COLOR_DC)
#define REG_IMGDMA_OVL_PAL_COLOR_DD         (OVL_DMA_PAL_COLOR_DD)
#define REG_IMGDMA_OVL_PAL_COLOR_DE         (OVL_DMA_PAL_COLOR_DE)
#define REG_IMGDMA_OVL_PAL_COLOR_DF         (OVL_DMA_PAL_COLOR_DF)
#define REG_IMGDMA_OVL_PAL_COLOR_E0         (OVL_DMA_PAL_COLOR_E0)
#define REG_IMGDMA_OVL_PAL_COLOR_E1         (OVL_DMA_PAL_COLOR_E1)
#define REG_IMGDMA_OVL_PAL_COLOR_E2         (OVL_DMA_PAL_COLOR_E2)
#define REG_IMGDMA_OVL_PAL_COLOR_E3         (OVL_DMA_PAL_COLOR_E3)
#define REG_IMGDMA_OVL_PAL_COLOR_E4         (OVL_DMA_PAL_COLOR_E4)
#define REG_IMGDMA_OVL_PAL_COLOR_E5         (OVL_DMA_PAL_COLOR_E5)
#define REG_IMGDMA_OVL_PAL_COLOR_E6         (OVL_DMA_PAL_COLOR_E6)
#define REG_IMGDMA_OVL_PAL_COLOR_E7         (OVL_DMA_PAL_COLOR_E7)
#define REG_IMGDMA_OVL_PAL_COLOR_E8         (OVL_DMA_PAL_COLOR_E8)
#define REG_IMGDMA_OVL_PAL_COLOR_E9         (OVL_DMA_PAL_COLOR_E9)
#define REG_IMGDMA_OVL_PAL_COLOR_EA         (OVL_DMA_PAL_COLOR_EA)
#define REG_IMGDMA_OVL_PAL_COLOR_EB         (OVL_DMA_PAL_COLOR_EB)
#define REG_IMGDMA_OVL_PAL_COLOR_EC         (OVL_DMA_PAL_COLOR_EC)
#define REG_IMGDMA_OVL_PAL_COLOR_ED         (OVL_DMA_PAL_COLOR_ED)
#define REG_IMGDMA_OVL_PAL_COLOR_EE         (OVL_DMA_PAL_COLOR_EE)
#define REG_IMGDMA_OVL_PAL_COLOR_EF         (OVL_DMA_PAL_COLOR_EF)
#define REG_IMGDMA_OVL_PAL_COLOR_F0         (OVL_DMA_PAL_COLOR_F0)
#define REG_IMGDMA_OVL_PAL_COLOR_F1         (OVL_DMA_PAL_COLOR_F1)
#define REG_IMGDMA_OVL_PAL_COLOR_F2         (OVL_DMA_PAL_COLOR_F2)
#define REG_IMGDMA_OVL_PAL_COLOR_F3         (OVL_DMA_PAL_COLOR_F3)
#define REG_IMGDMA_OVL_PAL_COLOR_F4         (OVL_DMA_PAL_COLOR_F4)
#define REG_IMGDMA_OVL_PAL_COLOR_F5         (OVL_DMA_PAL_COLOR_F5)
#define REG_IMGDMA_OVL_PAL_COLOR_F6         (OVL_DMA_PAL_COLOR_F6)
#define REG_IMGDMA_OVL_PAL_COLOR_F7         (OVL_DMA_PAL_COLOR_F7)
#define REG_IMGDMA_OVL_PAL_COLOR_F8         (OVL_DMA_PAL_COLOR_F8)
#define REG_IMGDMA_OVL_PAL_COLOR_F9         (OVL_DMA_PAL_COLOR_F9)
#define REG_IMGDMA_OVL_PAL_COLOR_FA         (OVL_DMA_PAL_COLOR_FA)
#define REG_IMGDMA_OVL_PAL_COLOR_FB         (OVL_DMA_PAL_COLOR_FB)
#define REG_IMGDMA_OVL_PAL_COLOR_FC         (OVL_DMA_PAL_COLOR_FC)
#define REG_IMGDMA_OVL_PAL_COLOR_FD         (OVL_DMA_PAL_COLOR_FD)
#define REG_IMGDMA_OVL_PAL_COLOR_FE         (OVL_DMA_PAL_COLOR_FE)
#define REG_IMGDMA_OVL_PAL_COLOR_FF         (OVL_DMA_PAL_COLOR_FF)
#endif //MDP_C_MODEL

//#define IMGDMA_OVL_INT_BIT                0x00000001
//#define IMGDMA_OVL_1BPP_PHOTO_FRAME_MASK  0x00000006
//#define IMGDMA_OVL_1BPP_PHOTO_FRAME_BIT   0x00000000
//#define IMGDMA_OVL_2BPP_PHOTO_FRAME_BIT   0x00000002
//#define IMGDMA_OVL_4BPP_PHOTO_FRAME_BIT   0x00000004
//#define IMGDMA_OVL_8BPP_PHOTO_FRAME_BIT   0x00000006
//#define IMGDMA_OVL_AUTO_RESTART_BIT       0x00000008
//#define IMGDMA_OVL_PALEN_BIT              0x00000010
//#define IMGDMA_OVL_PSEL_BIT               0x00000020
//#define IMGDMA_OVL_OUTPUT_MASK            0x000007C0
//#define IMGDMA_OVL_OUTPUT_VDOENC_BIT      0x00000040
//#define IMGDMA_OVL_OUTPUT_JPEG_BIT        0x00000080
//#define IMGDMA_OVL_OUTPUT_Y2R0_BIT        0x00000100
//#define IMGDMA_OVL_OUTPUT_VRZ_BIT         0x00000200
//#define IMGDMA_OVL_OUTPUT_PRZ_BIT         0x00000400
//#define IMGDMA_OVL_CONF_HRATIO_MASK       0x0000000F
//#define IMGDMA_OVL_CONF_VRATIO_MASK       0x000000F0
//#define IMGDMA_OVL_CONF_SOURCE_KEY_MASK   0x0000FF00

#define IMGDMA_OVL_THRESHOLD_MASK         0x00000070


// Enable
#define IMGDMA_OVL_START() \
    do { REG_IMGDMA_OVL_EN = 0x1; } while(0)

// Stop, engine stops at the frame end
#define IMGDMA_OVL_STOP() \
    do { REG_IMGDMA_OVL_STOP = 0x1; } while(0)

// Is OVL enabled?
#define IMGDMA_OVL_IS_ENABLED() \
    ((0x1 == (REG_IMGDMA_OVL_EN & 0x1)) ? KAL_TRUE : KAL_FALSE)

// Warm reset, stops after GMC transaction done...
#define IMGDMA_OVL_WARM_RESET() \
    do { REG_IMGDMA_OVL_RESET = 0x2; \
         while(0x2 == (REG_IMGDMA_OVL_RESET&0x2));} while(0)

// Hard reset, do not use
//#define IMGDMA_OVL_HARD_RESET() \
//    do { REG_IMGDMA_OVL_RESET = 0x1; \
//         REG_IMGDMA_OVL_RESET = 0x0; } while(0)

// WARNING: only effective when engine not enabled
#define IMGDMA_OVL_BYPASS_MODE() \
    do { REG_IMGDMA_OVL_IN_SEL = 0x8000; } while(0)

// WARNING: only effective when engine not enabled
//#define IMGDMA_OVL_STALL_PREV_ENGINE_MODE() \
//    do { REG_IMGDMA_OVL_IN_SEL = 0x0; } while(0)
    
// WARNING: only effective when engine not enabled
//#define IMGDMA_OVL_DROP_PREV_ENGINE_MODE() \
//    do { REG_IMGDMA_OVL_IN_SEL = 0x1; } while(0)

// WARNING: only effective when engine not enabled
#define IMGDMA_OVL_NORMAL_MODE() \
    do { REG_IMGDMA_OVL_IN_SEL = 0; } while(0)

// Enable interrupt
#define IMGDMA_OVL_INTERRUPT_ENABLE() \
    do { REG_IMGDMA_OVL_CON |= 0x1; } while(0)

// Disable interrupt
#define IMGDMA_OVL_INTERRUPT_DISABLE() \
    do { REG_IMGDMA_OVL_CON &= ~0x1; } while(0)

// Enable frame sync
#define IMGDMA_OVL_FRAME_SYNC_ENABLE() \
    do { REG_IMGDMA_OVL_CFG |= 0x80000000; } while(0)

// Disable frame sync
#define IMGDMA_OVL_FRAME_SYNC_DISABLE() \
    do { REG_IMGDMA_OVL_CFG &= ~0x80000000; } while(0)

// Descriptor mode
#define IMGDMA_OVL_DESCRIPTOR_MODE() \
    do { REG_IMGDMA_OVL_CFG |= 0x80; } while(0)

// Register mode
#define IMGDMA_OVL_REGISTER_MODE() \
    do { REG_IMGDMA_OVL_CFG &= ~0xF80; } while(0)

// Auto loop mode
#define IMGDMA_OVL_AUTO_LOOP_ENABLE() \
    do { REG_IMGDMA_OVL_CFG |= 0x1; } while(0)

// Non auto loop mode
#define IMGDMA_OVL_AUTO_LOOP_DISABLE() \
    do { REG_IMGDMA_OVL_CFG &= ~0x1; } while(0)

#define IMGDMA_OVL_SET_QUEUE_DEPTH(depth) \
    do { REG_IMGDMA_OVL_CFG = \
        ((REG_IMGDMA_OVL_CFG & ~0x00000f00) | \
         (0x00000f00 & ((depth) << 8))); } while(0)

// Enable masking
#define IMGDMA_OVL_MASK_ENABLE() \
    do { REG_IMGDMA_OVL_CON |= 0x2; } while(0)

// Disable masking
#define IMGDMA_OVL_MASK_DISABLE() \
    do { REG_IMGDMA_OVL_CON &= ~0x2; } while(0)

// Mask Uncompressed Mode
#define IMGDMA_OVL_MASK_UNCOMPRESSED() \
    do { REG_IMGDMA_OVL_CON &= ~0x4; } while(0)
    
// Mask Compressed Mode
#define IMGDMA_OVL_MASK_COMPRESSED() \
    do { REG_IMGDMA_OVL_CON |= 0x4; } while(0)


typedef struct
{
  idp_module_enum_t         input_src;
  kal_bool                  intr_en;            /**< interrup enable */
  idp_lisr_intr_cb_t        intr_cb;
  idp_lisr_intr_cb_param_t  intr_cb_param;
  kal_bool                  descriptor_mode;
  
  kal_bool                  restart;            /**< auto loop mode */
  kal_bool                  compressed_mode;
  kal_bool                  overlay_frame_mode; /**< KAL_TRUE to enable masking */
  kal_bool                  frame_sync_en;

  kal_bool                  bypass;
  
  kal_uint8                 queue_depth; 
  kal_uint32                des_queue_base_addr;

  kal_bool                  protect_en; /**< bus bandwidth protection for ROT_DMA enable */
  kal_bool                  ultra_high_en; 
  kal_uint16                bus_control_threshold; /** max emi burst type: HW default is 7 (burst 8-8) */

  /* overlay frame configuration */
  kal_uint32                overlay_mask_header_address;  /**< base address of header */   
  kal_uint32                overlay_mask_palette_address; /**< yuv palette color 00~ 0xff data */
  kal_uint32                overlay_mask_buffer_address;  /**< bsae address of the overlay frame buffer */
  kal_uint16                overlay_mask_src_width;       /**< overlay source mask width */
  kal_uint16                overlay_mask_src_height;      /**< overlay source mask height */
  kal_uint16                overlay_mask_dst_x;           /* mask dest horizontal offset */  
  kal_uint16                overlay_mask_dst_y;           /* mask dest vertical offset*/ 
  kal_uint16                overlay_mask_dst_width;       /**< overlay dest mask width */
  kal_uint16                overlay_mask_dst_height;      /**< overlay dest mask height */
  kal_uint16                overlay_frame_src_width;      /**< image source width */
  kal_uint16                overlay_frame_src_height;     /**< image source height */
  kal_uint8                 overlay_frame_source_key;     /**< source key of the overlay frame buffer */
} idp_imgdma_ovl_struct;

IDP_HW_COMMON_API_DECLARATION(imgdma_ovl)


extern void *idp_imgdma_ovl_intr_cb_param;
extern void (*idp_imgdma_ovl_intr_cb)(void *);


extern kal_bool idp_imgdma_ovl_set_palette_real(
  kal_uint8 const palette_size,
  kal_uint32 const * const palette_addr_ptr);

extern kal_bool idp_imgdma_ovl_set_palette(
  kal_uint32 const key,
  kal_uint8 const palette_size,
  kal_uint32 const * const palette_addr_ptr);

extern kal_bool idp_imgdma_ovl_config_real(
  idp_imgdma_ovl_struct * const ovl_struct, 
    kal_bool const config_to_hardware);

extern kal_bool idp_imgdma_ovl_get_working_mem_real(
  kal_bool const use_internal_mem,
  idp_imgdma_ovl_struct * const ovl_struct,
  kal_bool const do_alloc,
  kal_uint32 const max_allowable_size);

extern kal_bool
idp_imgdma_ovl_start_real(
    idp_imgdma_ovl_struct const * const p_ovl_struct);

extern kal_bool
idp_imgdma_ovl_stop_real(
    idp_imgdma_ovl_struct const * const p_ovl_struct);

extern void
idp_imgdma_ovl_open_real(void);


#endif // #if defined(DRV_IDP_MT6256_E2_SERIES)
#endif // __idp_imgdma_ovl_mt6256_e2_h__

