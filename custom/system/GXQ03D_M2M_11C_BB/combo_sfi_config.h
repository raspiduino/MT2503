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
 *   combo_sfi_config.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   defines flash configurations
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

//-----------------------------------------------------------------------------
// MCP Serial Flash HW settings (for ComboMEM only, do not include this header)
//-----------------------------------------------------------------------------
static const CMEMEntrySFIList combo_mem_hw_list = {   // (to be renamed by SFI owner)
#if defined(MT6251) || defined(MT6255) || defined(MT6250) || defined(MT6280) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    "COMBO_MEM_SFI",
#elif defined(MT6253L)||defined(MT6252)
    #ifdef __SV5_ENABLED__
    GFH_HEADER(GFH_EPP_PARAM, 1),
    #else
    "COMBO_MEM_SFI",
    #endif
#endif //defined(MT6251)
    COMBO_SFI_VER,           // SFI structure version
    SFI_COMBO_COUNT,   // defined in custom_Memorydevice.h
    {

        {   // KH25U6439FZNI_10G
            {   // HW config 104Mhz Start
                0x00010000,  // SFI_MAC_CTL
                0xEB0B5771,  // SFI_DIRECT_CTL
                0x52F80010,     //  SFI_MISC_CTL
                0x00000001,           // SFI_MISC_CTL2
                0x0,     // 1st SFI_DLY_CTL_2
                0x15000015,         // 1st SFI_DLY_CTL_3
                0x00040004,           // DRIVING
                0,                  // Reserved
                0,  // 2nd SFI_DLY_CTL_4
                0  // 2nd SFI_DLY_CTL_5
            },  // HW config End
            {
                SPI, 1, 0x35, QPI, 2, 0xC0, 0x02, SF_UNDEF,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 0, 0
            },
            {   // HW config 26Mhz Start
                0x00010000,  // SFI_MAC_CTL
                0xEB0B5771,  // SFI_DIRECT_CTL
                0x52F80000,     //  SFI_MISC_CTL
                0x00000001,     //  SFI_MISC_CTL2
                0x0,     // 1st SFI_DLY_CTL_2
                0x0,         // 1st SFI_DLY_CTL_3
                0x0,           // DRIVING
                0                 // Reserved
            }   // HW config End
        }

    }
};

