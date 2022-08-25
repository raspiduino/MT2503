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
 *   custom_jump_tbl.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   source file for indirect jump table for multiple binary load
 *
 * Author:
 * -------
 * -------    system auto generator  V1.95 
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

#include "kal_general_types.h"
#include "mba_resource.h"
#include "custom_jump_tbl.h"
#include "custom_FeatureConfig.h"
#include "verno.h"

#if ( (defined(__MTK_TARGET__) || defined(KAL_ON_OSCAR) ) )

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) 
#define SYSTEM_JUMP_TABLE_VAR_MODIFIER  
#else    /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */
#define SYSTEM_JUMP_TABLE_VAR_MODIFIER const
#endif   /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */

SYSTEM_JUMP_TABLE_VAR_MODIFIER Type_Preamble_Content  system_jump_table[5] = { 
   /* Language Pack */
   {
     VERNO_STR,
     VERSION_PATTERN, 
     VERSION_NUMBER,
     LANG_PACK_ROM_COMPRESS,
     LANG_EXISTED,
     CONST_RES_LANG_PACK_LOAD_ADDR,
     CONST_RES_LANG_PACK_COMPRESSED_SIZE,
     (kal_uint32)CONFIG_LANG_PACK_ROM_DECOMPRESSED_SIZE,
     (kal_uint32)(RESOURCE_TYPE_LANG_PACK + CURRENT_LANG_PACK_RES_VERSION), 
     CONST_RES_LANG_PACK_EXEC_ADDR,
     CONST_RES_LANG_PACK_TBL_SIZE,
     CONST_RES_LANG_PACK_CONTENT_SIZE, 
     (kal_uint32)MAGIC_NUMBER
   },
   /*__CUSTPACK_MULTIBIN__ */
   { 
     VERNO_STR,
     VERSION_PATTERN, 
     VERSION_NUMBER,
     CUSTPACK_ROM_COMPRESS,
     CUST_EXISTED,
     CONST_RES_CUSTPACK_LOAD_ADDR,
     CONST_RES_CUSTPACK_COMPRESSED_SIZE,
     (kal_uint32)CONFIG_CUSTPACK_ROM_DECOMPRESSED_SIZE,
     (kal_uint32)(RESOURCE_TYPE_CUSTPACK+CURRENT_CUSTPACK_RES_VERSION),
     CONST_RES_CUSTPACK_EXEC_ADDR,
     CONST_RES_CUSTPACK_TBL_SIZE,
     CONST_RES_CUSTPACK_CONTENT_SIZE,
     (kal_uint32)MAGIC_NUMBER
   },
   { 
     VERNO_STR,
     VERSION_PATTERN, 
     VERSION_NUMBER,
     DEFAULT_NOT_COMPRESSED,
     (kal_uint16)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,     
     (kal_uint32)MAGIC_NUMBER

   },
   {
     VERNO_STR,
     VERSION_PATTERN, 
     VERSION_NUMBER,
     DEFAULT_NOT_COMPRESSED,
     (kal_uint16)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)MAGIC_NUMBER
   },
   {
     VERNO_STR,
     VERSION_PATTERN, 
     VERSION_NUMBER, 
     DEFAULT_NOT_COMPRESSED,
     (kal_uint16)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32 *)0,
     (kal_uint32)0,
     (kal_uint32)0,
     (kal_uint32)MAGIC_NUMBER
   }
}; 

#endif  /* __MTK_TARGET__ || KAL_ON_OSCAR && !__MAUI_BASIC__ && !__L1_STANDALONE__ */

/*************************************************************************
* FUNCTION
*  NFBMBA_loader_iteration_callback
*
* DESCRIPTION
*  This routine called when NFB MBA resource binary loaded
*
* PARAMETERS
*  addr        -   the resource binary begin address
*  len         -   the resource binary length 
*
* RETURNS
*  void
*
typedef struct
{
    kal_char ProjectID[PROJECTID_LEN];
    kal_uint32 Resource_version;
    kal_uint32 *StartAddress;
    kal_uint32 TableSize;
    kal_uint32 ContentSize;
    kal_uint32 Magic;
} Type_Preamble_Content;
*
************************************************************************/
extern kal_uint32 SSF_GetMAUIImageNumber(void);

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
void
NFBMBA_loader_iteration_callback(kal_uint32 addr, kal_uint32 length)
{
   #if defined(__MULTIPLE_BINARY_FILES__)
   static index=0;
   Type_Preamble_Content  *pHeader;

   pHeader = (Type_Preamble_Content *) addr;
   while( system_jump_table[index].Existed != 0x1 ){
      if(index < (MAX_BIN_SUPPORT-1)){
         index++;	
      }
      else{
      	 // exceed MAX_BIN_SUPPORT, should do nothing
      	 return ;
      }
   }
   system_jump_table[index].LoadAddress = (kal_uint32*) addr;
   system_jump_table[index].TableSize    = pHeader->TableSize;
   system_jump_table[index].ContentSize  = pHeader->ContentSize;
   //system_jump_table[index].Resource_version = pHeader->Resource_version;
   
   if (SSF_GetMAUIImageNumber() > 0)
   // dummy reference to keep IMG_FOTA_INFO
   {
   index++;
   }
   #endif /* __MULTIPLE_BINARY_FILES__ */
}
#endif   /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */

/*************************************************************************
* FUNCTION
*  NFBMBA_loader_getImageLength
*
* DESCRIPTION
*  This routine called when NFB MBA resource binary identified
*
* PARAMETERS
*  data        -   the resource binary begin address (only 1 page loaded)
*
* RETURNS
*  the image total length calculated from header
*
typedef struct
{
    kal_char ProjectID[PROJECTID_LEN];
    kal_uint32 Resource_version;
    kal_uint32 *StartAddress;
    kal_uint32 TableSize;
    kal_uint32 ContentSize;
    kal_uint32 Magic;
} Type_Preamble_Content;
*
************************************************************************/
#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
kal_uint32
NFBMBA_loader_getImageLength(void *data)
{
   #if defined(__MULTIPLE_BINARY_FILES__)
   Type_Preamble_Content  *pHeader;
   kal_uint32  len;
   
   pHeader = (Type_Preamble_Content *) data;
   len = pHeader->TableSize + pHeader->ContentSize;
   
   return len;

   #else  /* __MULTIPLE_BINARY_FILES__ */
   return 0;
   #endif /* __MULTIPLE_BINARY_FILES__ */
}
#endif   /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */

/*************************************************************************
* FUNCTION
*  NFBMBA_loader_getImageExecViewAddress
*
* DESCRIPTION
*  This routine called when NFB MBA resource binary identified
*
* PARAMETERS
*  data        -   the resource binary begin address (only 1 page loaded)
*
* RETURNS
*  the starting address of RESB retrieved from the header
*
typedef struct
{
    kal_char ProjectID[PROJECTID_LEN];
    kal_uint32 Resource_version;
    kal_uint32 *StartAddress;
    kal_uint32 TableSize;
    kal_uint32 ContentSize;
    kal_uint32 Magic;
} Type_Preamble_Content;
*
************************************************************************/
#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
kal_uint32
NFBMBA_loader_getImageExecViewAddress(void *data)
{
   #if defined(__MULTIPLE_BINARY_FILES__)
   Type_Preamble_Content  *pHeader;
   kal_uint32  addr;
   
   pHeader = (Type_Preamble_Content *) data;
   addr = (kal_uint32) pHeader->LoadAddress;
   
   return addr;

   #else  /* __MULTIPLE_BINARY_FILES__ */
   return 0;
   #endif /* __MULTIPLE_BINARY_FILES__ */
}
#endif   /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__*/

