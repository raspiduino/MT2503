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
 *   custom_EMI_INFO.h
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


#if defined(MT6261) || defined(MT2501) || defined(MT2502)

#ifndef __CUSTOM_EMI_LIST__
#define __CUSTOM_EMI_LIST__

#include "kal_general_types.h"
#include "MemoryDevice_TypeDef.h"
/**
  *    for definition of COMBO_MEM_ENTRY_COUNT and __EMI_DEVICE_MODE_BURST__
  */
#include "custom_MemoryDevice.h"
#include "custom_EMI_release.h"
#include "custom_EMI.h"

#ifdef __SV5_ENABLED__
#include "br_GFH_emi_list.h"
#include "br_GFH.h"
#endif /* __SV5_ENABLED__ */

#ifdef __SV5_ENABLED__ // SV5 will always with __UBL__
#pragma arm section rodata = "BOOTLOADER_GFH_EXT"
#else
#pragma arm section rodata = "SECOND_PART"
#endif // __SV5_ENABLED__

#ifdef __SV5_ENABLED__
const GFH_EMI_LIST_v5 EMI_INFO_2 =
#else /* __SV5_ENABLED__ */
const MTK_EMI_List EMI_INFO_2 =
#endif /* __SV5_ENABLED__ */
{
#ifdef __SV5_ENABLED__
    GFH_HEADER(GFH_EMI_LIST, 5),
#else
    "MTK_CMB_EMI_LST",
#endif

    // chip_ver
    5,
    // op_ver
    #if defined(__EMI_DEVICE_LPDDR1__) && defined(__EMI_CLK_166MHZ__)
    0x01,
    #elif defined(__EMI_DEVICE_LPDDR1__) && defined(__EMI_CLK_200MHZ__)
    0x02,
    #elif defined(__EMI_DEVICE_LPDDR2__) && defined(__EMI_CLK_166MHZ__)
    0x11,
    #elif defined(__EMI_DEVICE_LPDDR2__) && defined(__EMI_CLK_200MHZ__)
    0x12,
    #else
    0,
    #endif

    0, // reserved_1
    0, // reserved_2

    1, // mcp_num
    /**
      * EMI/MEM configuration information of MCP0
      */
    "EMI_INF",

    EMI_GENERAL_A_VAL_MCP0,

    EMI_RDCT_VAL_MCP0,

    EMI_IDL_C_VAL_MCP0,
    EMI_IDL_D_VAL_MCP0,
    EMI_IDL_E_VAL_MCP0,

    EMI_ODL_C_VAL_MCP0,
    EMI_ODL_D_VAL_MCP0,
    EMI_ODL_E_VAL_MCP0,
    EMI_ODL_F_VAL_MCP0,

    EMI_IO_A_VAL_MCP0,
    EMI_IO_B_VAL_MCP0,

    EMI_DSRAM_VAL_MCP0,
    EMI_MSRAM_VAL_MCP0,

    /**
      * End of EMI/MEM configuration information of MCP0
      */


}; /* End of EMI_INFO_2 */

#pragma arm section rodata


#endif /* __CUSTOM_EMI_LIST__ */

#endif //#if defined(MT6261) || defined(MT2501) || defined(MT2502)

