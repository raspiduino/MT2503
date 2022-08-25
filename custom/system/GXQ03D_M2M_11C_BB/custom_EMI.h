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
 *   custom_EMI.h
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

#ifndef __CUSTOM_EMI__
#define __CUSTOM_EMI__

#include "kal_general_types.h"
#include "MemoryDevice_TypeDef.h"

/**
  *    for definition of COMBO_MEM_ENTRY_COUNT and __EMI_DEVICE_MODE_BURST__
  */
#include "custom_MemoryDevice.h"
#include "custom_EMI_release.h"

#define __EMI_COMBO_ENTRY_COUNT     1

#define __EMI_DCM_COMBO_INDEX_UND   0xffffffff

/*
 ****************************************************************************
 Define the driving and cache/prefetch setting (optional)
 ****************************************************************************
*/

/* start of MCP0 */

#if defined(__EMI_CLK_130MHZ__)
/* EMI GENA value */
#define EMI_GENERAL_A_VAL_MCP0         0x00000011

#define EMI_RDCT_VAL_MCP0              0x00000001

#define EMI_DSRAM_VAL_MCP0             0x00005000
#define EMI_MSRAM_VAL_MCP0             0x00001001

#define EMI_IDL_C_VAL_MCP0             0x0
#define EMI_IDL_D_VAL_MCP0             0x0
#define EMI_IDL_E_VAL_MCP0             0x0

#define EMI_ODL_C_VAL_MCP0             0x0
#define EMI_ODL_D_VAL_MCP0             0x0
#define EMI_ODL_E_VAL_MCP0             0x0
#define EMI_ODL_F_VAL_MCP0             0x0

/* EMI_DRV value */
#define EMI_IO_A_VAL_MCP0              0x00010001
#define EMI_IO_B_VAL_MCP0              0x00010001

#else
Error!!
#endif









/*
    1. EMI_NOR_CMD_num_max, EMI_PSRAM_CMD_num_max will be the largest one of all valid MCP
       for all OPs which are not used by certain MCP, the OP must be MEM_CMD_OP_NOP
    2. Some fields are moved to MTK_Combo_List
*/
typedef struct
{

    kal_char m_identifier[8];

    /**
      * EMI control register value.
      */

    kal_uint32 EMI_GENA_value;

    kal_uint32 EMI_RDCT_value;

    kal_uint32 EMI_IDL_C_value;
    kal_uint32 EMI_IDL_D_value;
    kal_uint32 EMI_IDL_E_value;

    kal_uint32 EMI_ODL_C_value;
    kal_uint32 EMI_ODL_D_value;
    kal_uint32 EMI_ODL_E_value;
    kal_uint32 EMI_ODL_F_value;

    kal_uint32 EMI_IO_A_value;
    kal_uint32 EMI_IO_B_value;

    kal_uint32 EMI_DSRAM_value;
    kal_uint32 EMI_MSRAM_value;

} MTK_EMI_Info;

/**
  * List of All valid MCPs
  */

typedef struct
{
    /**
      * header pattern information.
      */
    kal_char m_identifier[16];
    /**
      * chip version information.
      * m_ver = 1 for MT6253
      */
    kal_uint32 m_ver;
    /**
      * switch op version information.
      * m_ver = 1 for initial version.
      */
    kal_uint8 op_ver;


    kal_uint8 reserved_1;
    kal_uint8 reserved_2;

    /**
      * Numbers of MCPs
      */
    kal_uint8 mcps_num;

    /** List of all MCP
      *
      */
    MTK_EMI_Info mem_info[__EMI_COMBO_ENTRY_COUNT];

} MTK_EMI_List;






/****************************************************
 * This part is for auto-gen validity CHECK *
 * Don't modify any content in this comment section *


 ****************************************************/

#endif /* __CUSTOM_EMI__ */

#endif //#if defined(MT6261) || defined(MT2501) || defined(MT2502)

