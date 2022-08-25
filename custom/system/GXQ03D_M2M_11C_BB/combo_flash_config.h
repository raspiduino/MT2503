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
 *   combo_flash_config.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the Flash configurations for Combo Memory.
 *
 * Author:
 * -------
 *   Chun-Hung Wu(mtk03818)   EMI auto generator V8.268
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

#ifdef __NVRAM_BACKUP_PARTITION__
#define CMEM_MAX_BLOCKS       (NOR_ALLOCATED_FAT_SPACE/NOR_BLOCK_SIZE)+(((NVRAM_BACKUP_PARTITION_SIZE + NOR_BLOCK_SIZE - 1) & ~(NOR_BLOCK_SIZE - 1))/NOR_DISK0_BLOCK_SIZE)
#else
#define CMEM_MAX_BLOCKS       831
#endif
#define CMEM_MAX_SECTORS      6624

COMBO_MEM_TYPE_MODIFIER COMBO_MEM_TYPE_NAME COMBO_MEM_INST_NAME = {
    COMBO_MEM_STRUCT_HEAD
    {   // KH25U6439FZNI_10G
        CMEM_FDM_NOR_DEFAULT,
        64,      // Page Buffer Program Size
        (4| 32| 64), // Unifom Blocks
        {   // BlockInfo Start
            {0x0,0x1000},
            DISK0_REGION_INFO_LAYOUT,
            EndRegionInfo,
            EndRegionInfo,
            EndRegionInfo,
            EndRegionInfo,
            EndRegionInfo,
            EndRegionInfo
        },  // BlockInfo End
        {   // BankInfo Start
            {0x800000,1},
            EndBankInfo,
            EndBankInfo,
            EndBankInfo,
            EndBankInfo,
            EndBankInfo,
            EndBankInfo,
            EndBankInfo
        }  // BankInfo End
    }

    COMBO_MEM_STRUCT_FOOT
};
