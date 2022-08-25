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
 *   custom_img_config.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the FOTA (Firmware Over the Air) related setting.
 *
 * Author:
 * -------
 *   Carlos Yeh (mtk02377)     system auto generatorv7.10 -> p7.14 -> p7.15 + scatFrame v0.12 + sysGenUtility v0.49
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

#ifndef __CUSTOM_IMG_CONFIG_H__
#define __CUSTOM_IMG_CONFIG_H__

#ifdef __TINY_SYS_AP__
#include "kal_general_types.h"
#include "custom_fota.h"
#include "custom_FeatureConfig.h"
#endif // __TINY_SYS_AP__    
/****************************************************************************
   Following definitions are used to configure flash memory arrangement for Bootloader image

   Item 1. the maximum size of FOTA bootloader image
   Item 2. the ROM base address on Flash when NORFLASH_NON_XIP_SUPPORT is enabled
 ****************************************************************************/
#define BL_IMG_MAX_SIZE (0x40000)
#define ROM_BASE_ON_FLASH (0x1000A000)

/****************************************************************************
   Following definitions are used to configure flash memory arrangement for tiny system image

   Item 1. the begin address of TINYSYS_ROM1 image on flash when TINY_SYS is enabled
   Item 2. the begin address of TINYSYS_ROM2 image on flash when TINY_SYS is enabled
 ****************************************************************************/
#define TINYSYS_ROM1_BEGIN_ADDRESS 0x0
#define TINYSYS_ROM2_BEGIN_ADDRESS 0x0

/****************************************************************************
   Following definitions are used to configure flash memory arrangement for FOTA Engine image

   Item 1. the base address of FOTA update engine image

   Item 2. the maximum available flash memory size for update engine image

   Item 3. the maximum available flash memory size for update engine image back up

   Item 4. the maximum flash memory area for bootloader to search update engine image

   Item 5. the execution start address for bootloader to place update engine image
   Note: This value MUST be the same with scatter file setting

 ****************************************************************************/
#define FOTA_UE_FLASH_BASE_ADDRESS (0x0000A000)

#define FOTA_UE_RESIDENT_FLASH_SPACE_SIZE   (0x60000)

#define FOTA_UE_BACKUP_FLASH_SPACE_SIZE     (0x60000)

#define FOTA_UE_SEARCH_RANGE_SIZE  (0x400000)

#define FOTA_UE_EXECUTION_BASE     (0x00380000)

/****************************************************************************
   Following definitions are used to configure flash memory arrangement for MAUI image

   Item 1. the number of MAUI image binary parts

   Item 2. the start address and maximum available flash memory size for each MAUI image
   Note: This maximum available value specifies the size of flash memory that a image can 
         occupy except reserved flash blocks specified in Item 7. The start address should 
         be synchronized with the begin address of each image binary during update/delta 
         package generation process.

   Item 3. the start address of flash storage reserved for update package

   Item 4. the size of flash storage reserved for update package

   Item 5. the start address of back up area for update purpose

   Item 6. the maximum flash block number in update package area

   Item 7. the size of back up area for update purpose
   Note: Certain FOTA solution, like RedBend, requires a dedicate flash space to back up flash 
         content during update process. In contrast, some colution, such as Bitfone, would use
         leftover flash blocks that are not occupied by firmware image as back up area. In this case, 
         the value of maximum available flash memory has to be increased to compensate back up
         requirement.

   Item 8. the flash blocks reserved for flash management
   Note: This value specifies the amount of blocks that must be reseerved from
         the gap between maximum avilable flash size, Item2, and the flash memory size
         really occupied by firmware image.

 ****************************************************************************/

#define FOTA_MAUI_IMAGE_AMOUNT     (1)

#if defined(__FOTA_DM__) || defined(__MULTIPLE_BINARY_FILES__)

   #if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)

      #if defined(__FOTA_DM__) 
         #if defined(MAX_ROM_SIZE)
            #define MAX_LENGTH_ROM  (MAX_ROM_SIZE)
         #else  /* MAX_ROM_SIZE */
            #define MAX_LENGTH_ROM  (0x300000)
         #endif  /* MAX_ROM_SIZE */
      #else
         #define MAX_LENGTH_ROM  (0xFFFFFFFF)
      #endif /* __FOTA_DM__ */

      #if defined(__FOTA_DM__)
         #if defined(MAX_SECONDARY_ROM_SIZE)
            #define MAX_LENGTH_SECONDARY_ROM  (MAX_SECONDARY_ROM_SIZE)
         #else  /* MAX_SECONDARY_ROM_SIZE */
            #define MAX_LENGTH_SECONDARY_ROM  (0xB00000)
         #endif  /* MAX_SECONDARY_ROM_SIZE */
      #else
         #define MAX_LENGTH_SECONDARY_ROM  (0xFFFFFFFF)
      #endif /* __FOTA_DM__ */

      #if defined(__FOTA_DM__)       
         #if defined(MAX_THIRD_ROM_SIZE)
            #define MAX_LENGTH_THIRD_ROM  (MAX_THIRD_ROM_SIZE)
         #else  /* MAX_THIRD_ROM_SIZE */
            #define MAX_LENGTH_THIRD_ROM  (0x200000)
         #endif  /* MAX_THIRD_ROM_SIZE */
      #else
         #define MAX_LENGTH_THIRD_ROM  (0xFFFFFFFF)
      #endif /* __FOTA_DM__ */

      #if defined(__FOTA_DM__) 
         #if defined(MAX_DEMAND_PAGING_ROM0_SIZE)
            #define MAX_LENGTH_DEMAND_PAGING_ROM0  (MAX_DEMAND_PAGING_ROM0_SIZE)
         #else  /* MAX_DEMAND_PAGING_ROM0_SIZE */
            #define MAX_LENGTH_DEMAND_PAGING_ROM0  (0x3C00000)
         #endif  /* MAX_DEMAND_PAGING_ROM0_SIZE */
      #else
         #define MAX_LENGTH_DEMAND_PAGING_ROM0  (0xFFFFFFFF)
      #endif /* __FOTA_DM__ */
   
      #if defined(MAX_LANG_PACK_ROM_SIZE)
         #define MAX_LENGTH_LANG_PACK_ROM  (MAX_LANG_PACK_ROM_SIZE)
      #else  /* MAX_LANG_PACK_ROM_SIZE */
         #define MAX_LENGTH_LANG_PACK_ROM  (0x800000)
      #endif  /* MAX_LANG_PACK_ROM_SIZE */
   
      #if defined(MAX_CUSTPACK_ROM_SIZE)
         #define MAX_LENGTH_CUSTPACK_ROM  (MAX_CUSTPACK_ROM_SIZE)
      #else  /* MAX_CUSTPACK_ROM_SIZE */
         #define MAX_LENGTH_CUSTPACK_ROM  (0x800000)
      #endif  /* MAX_CUSTPACK_ROM_SIZE */

      #define MAX_LENGTH_DSP_ROM  (0x100000)

   #else  /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */
   
      #if defined(__FOTA_DM__)
         #if defined(MAX_ROM_SIZE)
            #define MAX_LENGTH_ROM  (MAX_ROM_SIZE)
         #else  /* MAX_ROM_SIZE */
            #define MAX_LENGTH_ROM  (0x002D7000)
         #endif  /* MAX_ROM_SIZE */
      #else
         #define MAX_LENGTH_ROM     (0xFFFFFFFF)
      #endif

      #if defined(__FOTA_DM__)
         #if defined(MAX_LANG_PACK_ROM_SIZE)
            #define MAX_LENGTH_LANG_PACK_ROM  (MAX_LANG_PACK_ROM_SIZE)
         #else  /* MAX_LANG_PACK_ROM_SIZE */
            #define MAX_LENGTH_LANG_PACK_ROM  (0x0)
         #endif  /* MAX_LANG_PACK_ROM_SIZE */
      #else
         #define MAX_LENGTH_LANG_PACK_ROM     (0xFFFFFFFF)
      #endif

      #if defined(__FOTA_DM__)
         #if defined(MAX_CUSTPACK_ROM_SIZE)
           #define MAX_LENGTH_CUSTPACK_ROM  (MAX_CUSTPACK_ROM_SIZE)
         #else  /* MAX_CUSTPACK_ROM_SIZE */
            #define MAX_LENGTH_CUSTPACK_ROM  (0x0)
         #endif  /* MAX_CUSTPACK_ROM_SIZE */
      #else
         #define MAX_LENGTH_CUSTPACK_ROM     (0xFFFFFFFF)
      #endif

      #if defined(__FOTA_DM__)
         #define MAX_LENGTH_JUMP_TABLE  (0x0)
      #else
         #define MAX_LENGTH_JUMP_TABLE  (0xFFFFFFFF)
      #endif
   
   #endif  /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */

#else

   #if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
      #define MAX_LENGTH_ROM                 (0xFFFFFFFF)
      #define MAX_LENGTH_SECONDARY_ROM       (0xFFFFFFFF)
      #define MAX_LENGTH_THIRD_ROM           (0xFFFFFFFF)
      #define MAX_LENGTH_DEMAND_PAGING_ROM0  (0xFFFFFFFF)
      #define MAX_LENGTH_LANG_PACK_ROM       (0xFFFFFFFF)
      #define MAX_LENGTH_CUSTPACK_ROM        (0xFFFFFFFF)
      #define MAX_LENGTH_DSP_ROM             (0xFFFFFFFF)
   #else  /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */
      #define MAX_LENGTH_ROM                 (0xFFFFFFFF)
      #define MAX_LENGTH_LANG_PACK_ROM       (0xFFFFFFFF)
      #define MAX_LENGTH_CUSTPACK_ROM        (0xFFFFFFFF)
      #define MAX_LENGTH_JUMP_TABLE          (0xFFFFFFFF)
   #endif  /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */

#endif


#if defined(__MTK_TARGET__)

extern kal_uint32 Load$$ROM_GFH$$Base;

#define MAUI_LOAD_ADDRESS_ROM   ((kal_uint32)&Load$$ROM_GFH$$Base)

#else /* __MTK_TARGET__ */

#define MAUI_LOAD_ADDRESS_ROM   ((kal_uint32)0)
 
#endif /* __MTK_TARGET__ */

#define FOTA_MAUI_FLASH_SPACE      { {MAUI_LOAD_ADDRESS_ROM, MAX_LENGTH_ROM, 0x0}, \
                                     END_MAUI_INFO}


#define FOTA_PACKAGE_STORAGE_BASE  (0x103A1000)

#define FOTA_PACKAGE_STORAGE_SIZE  (0x00000000)

#define FOTA_PACKAGE_BLOCK_NUMBER  (4)

#define FOTA_BACKUP_STORAGE_BASE   (0x103A1000)

#define FOTA_BACKUP_STORAGE_SIZE   (0x00000000)

#define FOTA_RESERVED_FLASH_BLOCKS     (5)

/****************************************************************************
   Following definitions are used for MAUI image manageemt

   Item 1. the size of mapping table for MAUI ROM image

   Item 2. the size of mapping table for FUE ROM image

 ****************************************************************************/
#define FOTA_MAUI_MAPPING_TABLE_SIZE   (0x800)

/****************************************************************************
   Following definitions are used for NAND flash device configuration

   Item 1. the maximum page size of supported NAND flash device

 ****************************************************************************/
#define FOTA_FLASH_MAX_PAGE_SIZE       (0x800)

/****************************************************************************
   Following definitions are used for FUE update process

   Item 1. the maximum heap size for FUE

 ****************************************************************************/
#define FOTA_CUSTOM_POOL_SIZE       (0x200000)

/****************************************************************************
   Following definitions are used for FOTA update package certification flow

   Item 1. the maximum length of message authentication code (in bytes)

   Item 2. the maximum length of key to encrypt message authentication code (in bytes)

 ****************************************************************************/
#define FOTA_CUSTOM_PACKAGE_MAC_SIZE     (20)

#define FOTA_CUSTOM_PACKAGE_SIG_SIZE     (128)

#define FOTA_CUSTOM_PACKAGE_KEY_MAX_LEN  (128)

#define FOTA_EXTRA_RESERVED_BLOCKS       (5)

/* Following data structure should be modified according to requirements in adoption of third partys solution */
#define __FUE_DUMMY_UPDATE_SUPPORT__

#if defined(__FUE_DUMMY_UPDATE_SUPPORT__)

/*
 * !CAUTION! size of FOTA_Custom_Update_Info MUST be equal to 88 bytes
 */
typedef struct {
   kal_uint32 FOTA_test_info1;
   kal_uint32 FOTA_test_info2;
   kal_uint32 FOTA_test_info3;
   kal_uint32 FOTA_test_info4;
   kal_uint32 FOTA_test_padding[18];
} FOTA_Custom_Update_Info;

#elif defined(__FUE_HP_SUPPORT__)

#include "Hp_update.h"

#elif defined(__FUE_REDBEND_SUPPORT__)

#include "RedBend_update.h"

#else

#error "Unsupported FOTA update information!!"

#endif /* __FUE_DUMMY_UPDATE_SUPPORT__ */

typedef struct {
   kal_uint32 m_pkg_mod_key_len;
   kal_char   m_pkg_mod_key[(FOTA_CUSTOM_PACKAGE_KEY_MAX_LEN<<1)+1];
   kal_uint32 m_pkg_exp_key_len;
   kal_char   m_pkg_exp_key[(FOTA_CUSTOM_PACKAGE_KEY_MAX_LEN<<1)+1];
} FOTA_Custom_Package_Certificate_st;

/****************************************************************************
   Following definitions are used for CBR region attribute

   Item 1. the block used for store CBR data. Each Normal block will occupy 2 physical blocks

   Item 2. the block used for bad block replacement on NAND flash. For the device, it should be zero

  Total blocks occupied by CBR will be CBR_REGION_NORMAL_BLOCK_NUM*2+CBR_REGION_SPARE_BLOCK_NUM
 ****************************************************************************/
#define CBR_REGION_NORMAL_BLOCK_NUM     0

#define CBR_REGION_SPARE_BLOCK_NUM      0


#endif /* __CUSTOM_IMG_CONFIG_H__ */
