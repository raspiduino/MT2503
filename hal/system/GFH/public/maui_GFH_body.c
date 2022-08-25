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
 *   maui_GFH_body.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contain the GFH body and content for all MAUI parts
 *
 * Author:
 * -------
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __SV5_ENABLED__

#include "br_GFH.h"
#include "br_GFH_file_info.h"
#include "br_GFH_maui_info.h"
#include "br_GFH_flash_info.h"
#include "br_GFH_cbr_info.h"
#include "br_GFH_maui_sec.h"
#include "br_GFH_MBA_info.h"
#include "br_GFH_secure_ro_info.h"
#include "br_GFH_binary_location.h"
#include "SST_init.h"

#include "GFH_defs.h"
#include "maui_GFH_body.h"

#include "feature_def.h"
#include "bl_features.h"
#include "cbr_record_def.h"

#include "custom_img_config.h"
#include "custom_secure_config.h"

#include "kal_general_types.h"
#include "mba_resource.h"
#include "custom_jump_tbl.h"

#ifdef _NAND_FLASH_BOOTING_
#include "NAND_DAL_VERSION.h"
#endif

#ifdef __BOOT_CERT_V2__
#include "boot_cert_pattern.h"
#endif 

#include "flash_opt.h"

//==============================================================================
// Linker symbols
//==============================================================================

extern kal_uint32 Image$$ROM$$Base;

extern kal_uint32 Image$$ROM_GFH$$Length;
extern kal_uint32 Load$$ROM_GFH$$Base;

extern kal_uint32 Image$$SECONDARY_ROM_GFH$$Length;
extern kal_uint32 Load$$SECONDARY_ROM_GFH$$Base;

#ifdef __DEMAND_PAGING__
extern kal_uint32 Image$$DEMAND_PAGING_ROM0_GFH$$Length;
extern kal_uint32 Load$$DEMAND_PAGING_ROM0_GFH$$Base;
#endif /* __DEMAND_PAGING__ */

extern kal_uint32 Load$$LANG_PACK_ROM_GFH$$Base;
extern kal_uint32 Image$$LANG_PACK_ROM_GFH$$Length;
extern kal_uint32 Load$$CUSTPACK_ROM_GFH$$Base;
extern kal_uint32 Image$$CUSTPACK_ROM_GFH$$Length;
extern kal_uint32 Load$$JUMP_TABLE_GFH$$Base;
extern kal_uint32 Image$$JUMP_TABLE_GFH$$Length;
extern kal_uint32 Load$$THIRD_ROM_GFH$$Base;
extern kal_uint32 Image$$THIRD_ROM_GFH$$Length;


extern kal_uint32 Image$$SECURE_RO_S_GFH$$Length;
extern kal_uint32 Load$$SECURE_RO_S_GFH$$Base;

extern kal_uint32 Image$$SECURE_RO_ME_GFH$$Length;
extern kal_uint32 Load$$SECURE_RO_ME_GFH$$Base;

extern kal_uint32 Load$$VIVA_GFH$$Base;
extern kal_uint32 Image$$VIVA_GFH$$Length;

extern kal_uint32 Load$$TRACK_GFH_RO$$Base;
extern kal_uint32 Image$$TRACK_GFH_RO$$Length;
extern kal_uint32 Load$$TRACK_GFH_RW$$Base;
extern kal_uint32 Image$$TRACK_GFH_RW$$Length;
extern kal_uint32 Load$$TRACK_NVRAM_GFH$$Base;
extern kal_uint32 Image$$TRACK_NVRAM_GFH$$Length;

//Define the signature type of MAUI binaries
#ifdef __MTK_SECURE_PLATFORM__
#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else

#define P_MAUI_SIGNATURE_TYPE      SIG_NONE
#define P_MAUI_SIGNATURE_LEN       SIG_NONE_LEN
#define S_MAUI_SIGNATURE_TYPE      SIG_NONE
#define S_MAUI_SIGNATURE_LEN       SIG_NONE_LEN

#define SECURE_RO_SIGNATURE_TYPE   SIG_PHASH
#define SECURE_RO_SIGNATURE_LEN    SIG_PHASH_LEN

#endif /* __MTK_SECURE_PLATFORM__ */

//==============================================================================
// MAUI's GFH header body
//==============================================================================

#pragma arm section rodata = "MAUI_GFH"

const MAUI_GFH g_maui_gfh = 
{
      //GFH_FILE_INFO_v1
      {  
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,
         
         MAUI_VERSION,
#ifndef __FACTORY_BIN__         
         PRIMARY_MAUI,
#else
         PRIMARY_FACTORY_BIN,
#endif
         MAUI_DEVICE_TYPE,
         P_MAUI_SIGNATURE_TYPE,
         
#ifndef __XIP_SHADOWING__
         (kal_uint32)(&Load$$ROM_GFH$$Base),
#else
         ROM_BASE_ON_FLASH,
#endif
         GFH_FILE_SIZE_BY_POST_BUILD,
         MAX_LENGTH_ROM,
         (kal_uint32)(&Image$$ROM_GFH$$Length),
         P_MAUI_SIGNATURE_LEN,
         (kal_uint32)(&Image$$ROM$$Base),
         BINARY_ATTRIBUTE
      },

      //GFH_MAUI_INFO_v2
      {  
         GFH_HEADER(GFH_MAUI_INFO, 2),

         //platform_id & project_id
         "N/A",
         "N/A",

         BL_MAUI_PAIRED_VER,
         FEATURE_COMBINATION,
         FEATURE_COMBINATINO_EX,
         0,
         SW_MINOR_VER,
#if defined(__SECURE_DATA_STORAGE__)
         SDS_START_ADDR, 
         SDS_TOTAL_SIZE,
#elif defined(__NVRAM_BACKUP_PARTITION__)
         NOR_BOOTING_NOR_DISK0_BASE_ADDRESS,
         NOR_BOOTING_NOR_DISK0_SIZE,
#else
         0,
         0,
#endif
         MIN_FLASHTOOL_VER_REQURIEMENT,
#ifdef __BOOT_CERT_V2__
         (kal_uint32)&g_SRD_INFO,
         (kal_uint32)sizeof(g_SRD_INFO),
#else
         0,0,
#endif
         {0}
         /* In XIP shadowing, the original m_load_addr field in FILE_INFO is used as flash address but not load address.
            However, we need load address to calculate jump_offset. Hence, the reserved region is used. */
#ifdef __XIP_SHADOWING__
         ,{
            (kal_uint32)(&Load$$ROM_GFH$$Base), 
            0
          }
#endif         
         
      },

      //GFH_FLASH_INFO_v1
      {
         GFH_HEADER(GFH_FLASH_INFO, 1),
#ifdef _NAND_FLASH_BOOTING_            
         { 0x30, (FDM_MAJOR_VER+0x30), (FDM_MINOR_VER1+0x30), (FDM_MINOR_VER2+0x30),
           0x30, (DAL_MAJOR_VER+0x30), (DAL_MINOR_VER1+0x30), (DAL_MINOR_VER2+0x30) 
         },
#endif            
      },

      //GFH_CBR_INFO_v2
      {
         GFH_HEADER(GFH_CBR_INFO, 2),
         CBR_REGION_NORMAL_BLOCK_NUM,
         CBR_REGION_SPARE_BLOCK_NUM,
         0,
         0
      },
      
      //GFH_MBA_INFO_V1
      {
      	 GFH_HEADER(GFH_MBA_INFO, 1),
      	 MAX_BIN_SUPPORT,
         (kal_uint32)(RESOURCE_TYPE_LANG_PACK + CURRENT_LANG_PACK_RES_VERSION),
         (kal_uint32)(RESOURCE_TYPE_CUSTPACK + CURRENT_CUSTPACK_RES_VERSION), 
         0,
         0,
         0	
      },

#ifdef __MTK_SECURE_PLATFORM__      
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_SECURE_PLATFORM__ */

#ifdef __FOTA_DM__
      //GFH_FOTA_INFO_v1
      {
         GFH_HEADER(GFH_FOTA_INFO, 1),
         FOTA_PACKAGE_STORAGE_BASE,
         FOTA_PACKAGE_STORAGE_SIZE,
         FOTA_BACKUP_STORAGE_BASE,
         FOTA_BACKUP_STORAGE_SIZE,
         FOTA_EXTRA_RESERVED_BLOCKS,       
      },
#endif
/*
#ifdef __XIP_SHADOWING__
      //GFH_BINARY_LOCATION_v1
      {
         GFH_HEADER(GFH_BINARY_LOCATION, 1),
#ifndef __FACTORY_BIN__ 
         MAUI_ROM_START_ADDR
#else
         FACTORY_ROM_START_ADDR
#endif
      },
#endif
*/
};

#pragma arm section rodata

//==============================================================================
// MAUI's Signature
//==============================================================================
#pragma arm section rodata = "MAUI_SIGNATURE_SECTION"

#ifdef __MTK_SECURE_PLATFORM__
/* under construction !*/
#else
const unsigned long g_maui_sig                          = DUMMY_END;
#endif /* __MTK_SECURE_PLATFORM__ */

#pragma arm section rodata

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
//==============================================================================
// Secondary MAUI GFH header body
//==============================================================================
#pragma arm section rodata = "S_MAUI_GFH"

const S_MAUI_GFH g_s_maui_gfh = 
{
      //GFH_FILE_INFO_v1
      {  
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,
         
         MAUI_VERSION,
#ifndef __FACTORY_BIN__         
         SECONDARY_MAUI,
#else
         SECONDARY_FACTORY_BIN,
#endif
         MAUI_DEVICE_TYPE,
         S_MAUI_SIGNATURE_TYPE,
         
         (kal_uint32)(&Load$$SECONDARY_ROM_GFH$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         MAX_LENGTH_SECONDARY_ROM,
         (kal_uint32)(&Image$$SECONDARY_ROM_GFH$$Length),
         S_MAUI_SIGNATURE_LEN,
         0,
         BINARY_ATTRIBUTE
      },
};


#pragma arm section rodata


//==============================================================================
// Secondary MAUI's Signature
//==============================================================================
#pragma arm section rodata = "S_MAUI_SIGNATURE_SECTION"

#ifdef __MTK_SECURE_PLATFORM__
/* under construction !*/
#else
const unsigned long g_s_maui_sig                           = DUMMY_END;
#endif /* __MTK_SECURE_PLATFORM__ */

#pragma arm section rodata

#ifdef __DEMAND_PAGING__
//==============================================================================
// On-demond paging GFH header body
//==============================================================================
#pragma arm section rodata = "ODP_GFH"

const ODP_GFH g_odp_gfh = 
{
      //GFH_FILE_INFO_v1
      {  
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,
         
         MAUI_VERSION,
         ON_DEMAND_PAGING,
         MAUI_DEVICE_TYPE,
         SIG_NONE,
         
         (kal_uint32)(&Load$$DEMAND_PAGING_ROM0_GFH$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         MAX_LENGTH_DEMAND_PAGING_ROM0,
         (kal_uint32)(&Image$$DEMAND_PAGING_ROM0_GFH$$Length),
         0,
         0,
         BINARY_ATTRIBUTE
      },
};


#pragma arm section rodata
#endif /* __DEMAND_PAGING__ */

#endif /* defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) */


#ifdef __MULTIPLE_BINARY_FILES__
//==============================================================================
// LANG PACK GFH header body
//==============================================================================
#ifdef __MBA_LANG_ONLY__

#pragma arm section rodata = "LANG_PACK_GFH"
const LANG_PACK_GFH g_lang_pack_gfh = 
{
      //GFH_FILE_INFO_v1
      {  
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,
         
         MAUI_VERSION,
         LANGUAGE_PACK,
         MAUI_DEVICE_TYPE,
         SIG_NONE,
         
         (kal_uint32)(&Load$$LANG_PACK_ROM_GFH$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         MAX_LENGTH_LANG_PACK_ROM,
         (kal_uint32)(&Image$$LANG_PACK_ROM_GFH$$Length),
         0,
         0,
         BINARY_ATTRIBUTE
      },
};
#pragma arm section rodata

#endif
//==============================================================================
// CUSTPACK GFH header body
//==============================================================================
#ifdef __MBA_CUST_ONLY__

#pragma arm section rodata = "CUSTPACK_GFH"
const CUSTPACK_GFH g_custpack_gfh = 
{
      //GFH_FILE_INFO_v1
      {  
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,
         
         MAUI_VERSION,
         CUSTOM_PACK,
         MAUI_DEVICE_TYPE,
         SIG_NONE,
         
         (kal_uint32)(&Load$$CUSTPACK_ROM_GFH$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         MAX_LENGTH_CUSTPACK_ROM,
         (kal_uint32)(&Image$$CUSTPACK_ROM_GFH$$Length),
         0,
         0,
         BINARY_ATTRIBUTE
      },
};
#pragma arm section rodata

#endif
#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)

#else

//==============================================================================
// JUMP TABLE GFH header body
//==============================================================================
#pragma arm section rodata = "JUMP_TABLE_GFH"

const JUMP_TABLE_GFH g_jump_table_gfh = 
{
      //GFH_FILE_INFO_v1
      {  
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,
         
         MAUI_VERSION,
         JUMP_TABLE,
         MAUI_DEVICE_TYPE,
         SIG_NONE,
         
         (kal_uint32)(&Load$$JUMP_TABLE_GFH$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         MAX_LENGTH_JUMP_TABLE,
         (kal_uint32)(&Image$$JUMP_TABLE_GFH$$Length),
         0,
         0,
         BINARY_ATTRIBUTE
      },
};

#pragma arm section rodata

#endif /* defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) */


#endif /* __MULTIPLE_BINARY_FILES__ */

//==============================================================================
// THIRD ROM GFH header body
//==============================================================================

#ifdef __NFB_THIRD_ROM_SUPPORT__

#pragma arm section rodata = "THIRD_ROM_GFH"

const THIRD_ROM_GFH g_third_rom_gfh = 
{
      //GFH_FILE_INFO_v1
      {  
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,
         
         MAUI_VERSION,
         THIRD_ROM,
         MAUI_DEVICE_TYPE,
         SIG_NONE,
         
         (kal_uint32)(&Load$$THIRD_ROM_GFH$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         MAX_LENGTH_THIRD_ROM,
         (kal_uint32)(&Image$$THIRD_ROM_GFH$$Length),
         0,
         0,
         BINARY_ATTRIBUTE
      },
};

#pragma arm section rodata

#endif

#ifdef __SECURE_RO_ENABLE__
//==============================================================================
// SecureRO_S's GFH header body
//==============================================================================

#pragma arm section rodata = "SECURE_RO_S_GFH"

const SECURE_RO_GFH g_secure_s_gfh = 
{
      //GFH_FILE_INFO_v1
      {  
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,
         
         SECURE_RO_VERSION,
         SECURE_RO_S,
         FLASH_DEV_NONE,
         SECURE_RO_SIGNATURE_TYPE,
         
         (kal_uint32)(&Load$$SECURE_RO_S_GFH$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         GFH_FILE_MAX_SIZE_IGNORED,
         (kal_uint32)(&Image$$SECURE_RO_S_GFH$$Length),
         SECURE_RO_SIGNATURE_LEN
      },

      //GFH_SECURE_RO_INFO_v1
      {  
         GFH_HEADER(GFH_SECURE_RO_INFO, 1),
         FALSE,
         SECURE_RO_ENCRYPTED_BY_KEY
      },

      //GFH_CBR_RECORD_INFO_v1
      {  
         GFH_HEADER(GFH_CBR_RECORD_INFO, 1),
         CBR_RECORD_SECURE_RO_S
      },
 };

#pragma arm section rodata

//==============================================================================
// SecureRO_S's Signature
//==============================================================================
#pragma arm section rodata = "SECURE_RO_S_SIGNATURE_SECTION"
const unsigned long g_secure_ro_s_sig[SECURE_RO_SIGNATURE_LEN>>2] = {SIG_HASH_VER};
#pragma arm section rodata


//==============================================================================
// SecureRO_ME's GFH header body
//==============================================================================

#pragma arm section rodata = "SECURE_RO_ME_GFH"

const SECURE_RO_GFH g_secure_ro_me_gfh = 
{
      //GFH_FILE_INFO_v1
      {  
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,
         
         SECURE_RO_VERSION,
         SECURE_RO_ME,
         FLASH_DEV_NONE,
         SECURE_RO_SIGNATURE_TYPE,
         
         (kal_uint32)(&Load$$SECURE_RO_ME_GFH$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         GFH_FILE_MAX_SIZE_IGNORED,
         (kal_uint32)(&Image$$SECURE_RO_ME_GFH$$Length),
         SECURE_RO_SIGNATURE_LEN
      },

      //GFH_SECURE_RO_INFO_v1
      {
         GFH_HEADER(GFH_SECURE_RO_INFO, 1),
         TRUE,
         SECURE_RO_ENCRYPTED_BY_KEY
      },

      //GFH_CBR_RECORD_INFO_v1
      {  
         GFH_HEADER(GFH_CBR_RECORD_INFO, 1),
         CBR_RECORD_SECURE_RO_ME
      },

 };

#pragma arm section rodata

//==============================================================================
// SecureRO_ME's Signature
//==============================================================================
#pragma arm section rodata = "SECURE_RO_ME_SIGNATURE_SECTION"
const unsigned long g_secure_ro_me_sig[SECURE_RO_SIGNATURE_LEN>>2] = {SIG_HASH_VER};
#pragma arm section rodata

#endif /* __SECURE_RO_ENABLE__ */


//==============================================================================
// VIVA GFH header body
//==============================================================================

#ifdef __VI_ENABLED__

#pragma arm section rodata = "VIVA_GFH"

const VIVA_GFH g_viva_gfh =
{
      //GFH_FILE_INFO_v1
      {
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,

         MAUI_VERSION,
         VIVA,
         MAUI_DEVICE_TYPE,
         SIG_NONE,

         (kal_uint32)(&Load$$VIVA_GFH$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         GFH_FILE_MAX_SIZE_IGNORED,
         (kal_uint32)(&Image$$VIVA_GFH$$Length),
         0,
         0,
         BINARY_ATTRIBUTE
      },
};

#pragma arm section rodata

#endif



//==============================================================================
// TRACK GFH header body
//==============================================================================


#pragma arm section rodata = "TRACK_GFH_RO"

const TRACK_GFH g_track_gfh_ro =
{
      //GFH_FILE_INFO_v1
      {
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,

         MAUI_VERSION,
         V_CUSTOMIZED_FILE,
         MAUI_DEVICE_TYPE,
         SIG_NONE,

         (kal_uint32)(&Load$$TRACK_GFH_RO$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         GFH_FILE_MAX_SIZE_IGNORED,
         (kal_uint32)(&Image$$TRACK_GFH_RO$$Length),
         0,
         0,
         BINARY_ATTRIBUTE
      },
};

#pragma arm section rodata


#pragma arm section rodata = "TRACK_GFH_RW"

const TRACK_GFH g_track_gfh_rw =
{
      //GFH_FILE_INFO_v1
      {
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,

         MAUI_VERSION,
         V_CUSTOMIZED_FILE,
         MAUI_DEVICE_TYPE,
         SIG_NONE,

         (kal_uint32)(&Load$$TRACK_GFH_RW$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         GFH_FILE_MAX_SIZE_IGNORED,
         (kal_uint32)(&Image$$TRACK_GFH_RW$$Length),
         0,
         0,
         BINARY_ATTRIBUTE
      },
};

#pragma arm section rodata

//==============================================================================
// TRACK GFH header body
//==============================================================================


#pragma arm section rodata = "TRACK_NVRAM_GFH"

const TRACK_GFH g_track_nvram_gfh =
{
      //GFH_FILE_INFO_v1
      {
         GFH_HEADER(GFH_FILE_INFO, 1),
         GFH_FILE_INFO_ID,

         MAUI_VERSION,
         V_CUSTOMIZED_FILE,
         MAUI_DEVICE_TYPE,
         SIG_NONE,

         (kal_uint32)(&Load$$TRACK_NVRAM_GFH$$Base),
         GFH_FILE_SIZE_BY_POST_BUILD,
         GFH_FILE_MAX_SIZE_IGNORED,
         (kal_uint32)(&Image$$TRACK_NVRAM_GFH$$Length),
         0,
         0,
         BINARY_ATTRIBUTE
      },
};

#pragma arm section rodata



//==============================================================================
// Misc
//==============================================================================
kal_uint32 DummyReference()
{
    kal_uint32 size = 0;

    size += (kal_uint32)(&g_maui_gfh)+(kal_uint32)(&g_maui_sig);

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
    size += (kal_uint32)(&g_s_maui_gfh) + (kal_uint32)(&g_s_maui_sig);

#if defined(__DEMAND_PAGING__)
    size += (kal_uint32)(&g_odp_gfh);
#endif

#endif

#if defined(__SECURE_RO_ENABLE__)
    size += (kal_uint32)(&g_secure_s_gfh)+(kal_uint32)(&g_secure_ro_s_sig) + (kal_uint32)(&g_secure_ro_me_gfh) + (kal_uint32)(&g_secure_ro_me_sig);
#endif /* __SECURE_RO_ENABLE__ */

#if defined(__VI_ENABLED__)
    size += (kal_uint32)(&g_viva_gfh);
#endif
    size += (kal_uint32)(&g_track_gfh_ro);
    size += (kal_uint32)(&g_track_gfh_rw);
    size += (kal_uint32)(&g_track_nvram_gfh);
	
    return size;
}

#endif /* __SV5_ENABLED__ */
