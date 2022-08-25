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
 *   custom_img_config.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements image information feature.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"
#include "custom_fota.h"
#include "custom_img_config.h"
#include "fue_err.h"
#include "fue.h"
#include "SSF_ROMInfo_type.h"
#include "SSF_ROMInfo.h"

#ifdef __SECURE_DATA_STORAGE__
#include "custom_secure_config.h"
#endif /* __SECURE_DATA_STORAGE__ */


#if !defined(__UBL__) && !defined(__FUE__)
#ifdef __MTK_TARGET__
#pragma arm section rodata = "MAUI_FOTA_HEAD_INFO"
#endif
const MTK_FOTA_ROM_Info_v1_ST IMG_FOTA_INFO =
{
   { "MTK_FOTA_ROMINFO_V01",
     0x6e659a9a },
   "N/A",
   "N/A",
   MTK_FOTA_ROMINFO_VERSION,
   FOTA_MAUI_IMAGE_AMOUNT,
   FOTA_MAUI_FLASH_SPACE,
   FOTA_PACKAGE_STORAGE_BASE,
   FOTA_PACKAGE_STORAGE_SIZE,
   FOTA_BACKUP_STORAGE_BASE,
   FOTA_BACKUP_STORAGE_SIZE,
   FOTA_EXTRA_RESERVED_BLOCKS,
   0x85
};

#ifdef __MTK_TARGET__
#pragma arm section rodata
#endif

/*************************************************************************
 * Global function definition
 *************************************************************************/
/*******************************************************************************/
kal_uint32 SSF_GetMAUIImageNumber(void)
{
   return IMG_FOTA_INFO.m_fota_image_number;
}
/*******************************************************************************/
kal_uint32 SSF_GetMAUIImageLength(kal_uint32 idx)
{
   return IMG_FOTA_INFO.m_fota_updatable_area[idx].m_image_load_size;
}
/*******************************************************************************/
kal_uint32 SSF_GetMAUIImageLoadAddr(kal_uint32 idx)
{
   return IMG_FOTA_INFO.m_fota_updatable_area[idx].m_image_base_address;
}

#ifdef __SECURE_DATA_STORAGE__

kal_uint32 custom_GetSDSTotalSize(void)
{
   return SDS_TOTAL_SIZE;
}

kal_uint32 custom_GetSDSStartAddr(void)
{
   return SDS_START_ADDR;
}

kal_uint32 custom_GetSDSReservedSize(void)
{
   return SDS_RESERVED_SIZE;
}

#endif /* __SECURE_DATA_STORAGE__ */

#endif /* !__UBL__ */

#if defined(__FUE__)

#ifdef __MTK_TARGET__
#pragma arm section rodata = "UA_HEAD"
#endif

STORAGE_QUALIFIER const MTK_UA_ROMInfo_Head_v1_ST IMG_UA_HEAD_INFO = 
{
   {"MTK_UA_ROMINFO_HEAD_V01",
    0xA7C8A3D2},
   "N/A",
   "N/A",
   MTK_UA_HEAD_ROMINFO_VERSION,
   {FOTA_UE_FLASH_BASE_ADDRESS, FOTA_UE_EXECUTION_BASE, FOTA_UE_RESIDENT_FLASH_SPACE_SIZE},
   0xF8
};
 
/*******************************************************************************/
kal_uint32 SSF_GetUpdateAgentAvailableSize(void)
{
   return IMG_UA_HEAD_INFO.m_ua_head_info.m_ua_max_length;
}

/*******************************************************************************/
extern const kal_uint32 FOTA_FUE_BACKUP_SPACE;
kal_uint32 SSF_GetUpdateAgentBackupSize(void)
{
   return FOTA_FUE_BACKUP_SPACE;
}

#endif /* __FUE__ */

#ifndef __SV5_ENABLED__
#if defined(__UBL__) && defined(__EXT_BOOTLOADER__)

#if  defined(__MTK_TARGET__)
extern kal_uint32 Image$$EXT_READ_ONLY$$Base;
#define BL_LOAD_BASE ((kal_uint32)&Image$$EXT_READ_ONLY$$Base)
#else
#define BL_LOAD_BASE 0
#endif

#ifdef __MTK_TARGET__
#pragma arm section rodata = "HEAD_BL"
#endif
STORAGE_QUALIFIER const MTK_BL_ROMInfo_v1_ST IMG_BL_INFO = 
{
   {"MTK_BOOT_LOADER_ROMINFO_V01",
    0
   },
   "N/A",
   "N/A",
   MTK_BL_ROMINFO_VERSION,
   BL_LOAD_BASE,
   BL_IMG_MAX_SIZE,
   BL_IMG_MAX_SIZE,
   0
};
#ifdef __MTK_TARGET__
#pragma arm section rodata
#endif

STORAGE_QUALIFIER MTK_UA_ROMInfo_Head_v1_ST IMG_UA_HEAD_INFO;
/*************************************************************************
 * Global function definition
 *************************************************************************/
/*******************************************************************************/
kal_uint32 SSF_GetBootloaderSize(void)
{
   return IMG_BL_INFO.m_bl_length;
}

/*******************************************************************************/
kal_uint32 SSF_GetBootloaderAreaSize(void)
{
   return IMG_BL_INFO.m_bl_max_length;
}
#endif /* __BL__ */
#endif /* __SV5_ENABLED__ */
