/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   custom_EMI_release.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the EMI (external memory interface) related setting.
 *
 * Author:
 * -------
 *   CM Huang(mtk00582)   EMI auto generator V8.268
 *
 *   Memory Device database last modified on 2018/8/25
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __CUSTOM_EMI_RELEASE__
#define __CUSTOM_EMI_RELEASE__

#include "kal_general_types.h"

/***********************************
 *
 * Definition
 *
 ***********************************/

/**
  * Define EMI's clock rate.
  * comes from EMI_CLK definition in custom_MemoryDevice.h, or highest freq in MDL
  */
#define __EMI_CLK_130MHZ__


/**
  * Define RAM size in Bytes.
  */
#define EMI_EXTSRAM_SIZE (((32)<<20)>> 3)


/**
  * Define NOR/RAM's starting address.
  */
#if defined(MT6253) || defined(MT6252H) || defined(MT6252) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#ifdef REMAPPING
#define FLASH_BASE_ADDR 0x10000000
#define RAM_BASE_ADDR   0x00000000
#else /* REMAPPING */
#define FLASH_BASE_ADDR 0x00000000
#define RAM_BASE_ADDR   0x10000000
#endif /* REMAPPING */
#endif /* MT6253 || MT6252H || MT6252 || MT6250 || MT6260 || MT6261 || MT2501 || MT2502 */


/***********************************
 *
 * Enum
 *
 ***********************************/

/**
  * EMI clock rate for query.
  */
typedef enum emi_clock_enum_t
{
    EMI_CLK_UNKNOWN = 0,
    EMI_CLK_13MHZ = 26,
    EMI_CLK_15_36MHZ = 30,
    EMI_CLK_26MHZ = 52,
    EMI_CLK_30_72MHZ = 60,
    EMI_CLK_39MHZ = 78,
    EMI_CLK_52MHZ = 104,
    EMI_CLK_61_44MHZ = 122,
    EMI_CLK_65MHZ = 130,
    EMI_CLK_78MHZ = 156,
    EMI_CLK_91MHZ = 182,
    EMI_CLK_104MHZ = 208,
    EMI_CLK_122_88MHZ = 244,
    EMI_CLK_130MHZ = 260,
    EMI_CLK_156MHZ = 312,
    EMI_CLK_166MHZ = 332,
    EMI_CLK_200MHZ = 400,
    EMI_CLK_208MHZ = 416,
    EMI_CLK_245_76MHZ = 490,
    EMI_CLK_333MHZ = 666,
    EMI_CLK_400MHZ = 800
} emi_clock_enum;

/**
  * EMI driving current for query.
  */
typedef enum emi_drv_enum_t
{
    EMI_DRV_UNKNOWN = 0,
    EMI_DRV_2MA = 2,
    EMI_DRV_4MA = 4,
    EMI_DRV_6MA = 6,
    EMI_DRV_8MA = 8,
    EMI_DRV_10MA = 10,
    EMI_DRV_12MA = 12,
    EMI_DRV_14MA = 14,
    EMI_DRV_16MA = 16,
    EMI_DRV_18MA = 18,
    EMI_DRV_20MA = 20
} emi_drv_enum;



/***********************************
 *
 * Exposed APIs.
 *
 ***********************************/

extern emi_clock_enum custom_EMI_QueryFullSpeedClock(void);

extern void custom_get_EXTSRAM_size(kal_uint32 *size);





#endif /* __CUSTOM_EMI_RELEASE__ */

