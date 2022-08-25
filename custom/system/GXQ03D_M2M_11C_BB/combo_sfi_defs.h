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
 *   combo_sfi_defs.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   defines flash ID table
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

#ifndef _COMBO_SFI_DEFS_H
#define _COMBO_SFI_DEFS_H

#include "flash_sfi_release.h"
//-----------------------------------------------------------------------------
// Combo MEM HW Settings
//-----------------------------------------------------------------------------
#define COMBO_SFI_VER   1



#define _SFI_SIP_SerialFlash

#if defined(_SFI_SIP_SerialFlash)
  #define SFI_COMBO_COUNT    1
#elif defined(__COMBO_MEMORY_SUPPORT__)
  #if !defined(__DUAL_SERIAL_FLASH_SUPPORT__)
    #define SFI_COMBO_COUNT    COMBO_MEM_ENTRY_COUNT
  #else
    #define SFI_COMBO_COUNT    DUAL_COMBO_MEM_ENTRY_COUNT
  #endif
#else
  #define SFI_COMBO_COUNT    1
#endif

#if defined(MT6250) || defined(MT6280) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
typedef struct 
{
  #if defined(__SFI_CLK_166MHZ__) && defined(MT6260)
    kal_uint32      HWConf_166M[10];    // to be defined by SFI/EMI owner
    kal_uint8       DevInit_166M[32];   // to be defined by SFI/EMI owner  (reserved for serial flash)
  #endif //defined(__SFI_CLK_166MHZ__)
  #if defined(__SFI_CLK_130MHZ__)
    kal_uint32      HWConf_130M[10];    // to be defined by SFI/EMI owner
    kal_uint8       DevInit_130M[32];   // to be defined by SFI/EMI owner  (reserved for serial flash)
  #endif //defined(__SFI_CLK_130MHZ__)
  #if defined(__SFI_CLK_104MHZ__)
    kal_uint32      HWConf_104M[10];    // to be defined by SFI/EMI owner
    kal_uint8       DevInit_104M[32];   // to be defined by SFI/EMI owner  (reserved for serial flash)
  #endif //defined(__SFI_CLK_104MHZ__)
  #if defined(__SFI_CLK_78MHZ__) || defined(__SFI_CLK_80MHZ__)
    kal_uint32      HWConf_78M[10];     // to be defined by SFI/EMI owner
    kal_uint8       DevInit_78M[32];    // to be defined by SFI/EMI owner  (reserved for serial flash)
  #endif //defined(__SFI_CLK_78MHZ__)
    kal_uint32      HWConf_26M[8];      // to be defined by SFI/EMI owner

} CMEMEntrySFI;
#else
typedef struct 
{
    kal_uint32      HWConf_104M[9];     // to be defined by SFI/EMI owner
    kal_uint8       DevInit_104M[32];   // to be defined by SFI/EMI owner  (reserved for serial flash)
    kal_uint32      HWConf_78M[9];      // to be defined by SFI/EMI owner
    kal_uint8       DevInit_78M[32];    // to be defined by SFI/EMI owner  (reserved for serial flash)
    kal_uint32      HWConf_13M[7];      // to be defined by SFI/EMI owner

} CMEMEntrySFI;
#endif

#if defined(MT6250) || defined(MT6280) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
typedef struct 
{
  #if defined(__SFI_CLK_166MHZ__) && defined(MT6260)
    kal_uint32      HWConf_166M[5];     // to be defined by SFI/EMI owner
  #endif //defined(__SFI_CLK_166MHZ__)
  #if defined(__SFI_CLK_130MHZ__)
    kal_uint32      HWConf_130M[5];     // to be defined by SFI/EMI owner
  #endif //defined(__SFI_CLK_130MHZ__)
  #if defined(__SFI_CLK_104MHZ__)
    kal_uint32      HWConf_104M[5];     // to be defined by SFI/EMI owner
  #endif //defined(__SFI_CLK_104MHZ__)
  #if defined(__SFI_CLK_78MHZ__) || defined(__SFI_CLK_80MHZ__)
    kal_uint32      HWConf_78M[5];      // to be defined by SFI/EMI owner
  #endif //defined(__SFI_CLK_78MHZ__)
    kal_uint32      HWConf_26M[3];      // to be defined by SFI/EMI owner
} CMEMEntrySFI_DCM;
#else
typedef struct 
{
    kal_uint32      HWConf_104M[5];     // to be defined by SFI/EMI owner
    kal_uint32      HWConf_78M[5];      // to be defined by SFI/EMI owner
    kal_uint32      HWConf_13M[3];      // to be defined by SFI/EMI owner
} CMEMEntrySFI_DCM;
#endif


typedef struct 
{
    kal_uint32      HWConf[16];         // to be defined by EMI owner
} CMEMEntryEMI;

typedef struct 
{
#if defined(MT6251) || defined(MT6255) || defined(MT6250) || defined(MT6280) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    char               m_identifier[16];   // MTK_COMBO_ID_INFO
#elif defined(MT6253L)||defined(MT6252)
  #ifdef __SV5_ENABLED__
    GFH_Header_Type    mem_info;
  #else
    char               m_identifier[16];   // MTK_COMBO_ID_INFO
  #endif
#endif //defined(MT6251) || defined(MT6255) || defined(MT6250) || defined(MT6280) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    unsigned int       m_ver;
    unsigned int       Count;
    CMEMEntrySFI       List[SFI_COMBO_COUNT];  // to be defined by SFI/EMI owner
} CMEMEntrySFIList;

typedef struct 
{
    CMEMEntrySFI_DCM      List[SFI_COMBO_COUNT];  // to be defined by SFI/EMI owner
} CMEMEntrySFIList_dcm;

#endif

