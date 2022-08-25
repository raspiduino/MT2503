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
 *   bl_FOTA.c
 *
 * Project:
 * --------
 *   FOTA support functions for bootloader
 *
 * Description:
 * ------------
 *   Reponsible for loading FOTA image.
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
#if defined(__FOTA_DM__)
#include "kal_general_types.h"
#include <bl_fota.h>
#include <bl_loader.h>
#include "fue_err.h"
#include "custom_fota.h"
#include "custom_img_config.h"
#include "fue.h"
#include "SSF_fue_support.h"
#include <SSF_ROMInfo.h>
#include <SSF_Block_Info.h>

#include "br_time_stamp.h"
#ifdef __TIME_STAMP__ 
#include "br_time_stamp_cb.h"
#include "bl_time_stamp_id.h"
#endif

#ifdef __SV5_ENABLED__
#include "ftl.h"
#endif

/**********************************************************
 External Variable reference
 ***********************************************************/
extern BOOTL_HEADER  BLHeader;

/**********************************************************
 External function reference
 ***********************************************************/

extern kal_uint32 custom_get_NORFLASH_Base(void);
extern kal_uint32 custom_Block_Size(kal_uint32 nor_addr);
extern kal_uint32 custom_Convert_to_execution(kal_uint32 nor_addr);
extern kal_uint32 custom_Block_Base(kal_uint32 nor_addr);
extern kal_uint32 custom_RAM_baseaddr(void);
extern kal_bool SSF_VerifyFOTAUAImage(kal_uint32 addr, kal_uint32 len, to_blk_size blk_size_func, to_exec_addr to_exec_func);
extern void SST_Secure_SetUAOffset(kal_uint32 ua_offset);
extern kal_uint32 SSF_GetUAImageExecutionAddress(void);
extern kal_uint32 SSF_GetUABaseAddress(void);
extern void Initialize_NOR_Info(void);

extern void dbg_print(kal_char *fmt,...);

/**********************************************************
 External variable reference
 ***********************************************************/
extern kal_uint32 g_Bl_Secure_Test;

extern const kal_uint32 FOTA_IMG_SPACE_INFO_PAGE;
extern const kal_uint32 FOTA_IMG_LIST_INFO_PAGE;
extern const kal_uint32 FOTA_IMG_VERSION_INFO_PAGE;

#ifdef __SV5_ENABLED__
extern FTL_FuncTbl *g_ftlFuncTbl;
#endif
/**********************************************************
 Global constant Variable
 ***********************************************************/
#define SEARCH_STEP_SIZE (0x1000)

#if !defined(_NAND_FLASH_BOOTING_) && !defined(__EMMC_BOOTING__)
#include "drvflash.h"
#include "flash_mtd.h"

NOR_MTD_FlashInfo  fue_nor_flash_info;
//volatile kal_uint32 processing_irqCnt;

/**********************************************************
Description : look forward FOTA image information position.
Input       : None
Output      : None
Assumptions : FUE image is programmed to flash in block aligned manner
              FUE image infomation is placed in the first 2KB area of binary image
***********************************************************/
static kal_bool bl_searchFOTAImage(kal_uint32 start_addr, kal_uint32 *ua_base, kal_uint32 *load_addr,\
                                   kal_uint32 *img_len, SearchImageInfo_func search_func)
{
   _FGAL_ERROR_CODE  status;
   kal_uint32        info_len = 0;
   kal_int32         total_length = FOTA_UE_SEARCH_RANGE_SIZE;
   kal_uint32        step_len = SEARCH_STEP_SIZE;
   kal_uint32        img_ptr = start_addr;
   kal_uint32        img_size = 0;
   kal_uint32        img_begin = 0;
   kal_uint32        curr_step = 0; /* in terms of pages */
   kal_uint32        blk_mask = 0;
   kal_bool          ua_org_ok = KAL_FALSE;
   kal_bool          ua_backup_ok = KAL_FALSE;
   kal_uint32        ua_found = KAL_FALSE;

   *ua_base = INVALID_DWORD;
   *load_addr = INVALID_DWORD;
   total_length = ((total_length+step_len-1)/step_len)*step_len;

   while(total_length > 0)
   {
      /* check whether image info. exists */
      step_len = custom_Block_Size((kal_uint32)img_ptr);
      if(search_func((kal_uint8 *)img_ptr, step_len, NULL, NULL))
      {
         /* pattern found */
         dbg_print("bl_searchFOTAImageInfo: target pattern is found!!\n\r");
         /* check image validity */
         img_size = SSF_GetUAImageRange();
         img_begin = SSF_GetUABaseAddress();
         if(img_size <= FOTA_UE_RESIDENT_FLASH_SPACE_SIZE)
         {
            img_begin = custom_Block_Base((kal_uint32)img_ptr);
            /* verify UA image invalidity */
            SST_Secure_SetUAOffset(img_begin - SSF_GetUABaseAddress());
            if(SSF_VerifyFOTAUAImage(img_begin, img_size, custom_Block_Size, custom_Convert_to_execution))
            {
               *ua_base = img_begin;
               *img_len = img_size;
               *load_addr = SSF_GetUALoadAddress() | custom_RAM_baseaddr();//SSF_GetUAImageExecutionAddress();
               ua_found = KAL_TRUE;
               break;
            }
         }
         /*
         else
            skip unreasonable img_size, caused by incomplete update??
         */
      }
      img_ptr += step_len;
      curr_step++;
      total_length -= step_len;
   }
   return ua_found;
}

kal_uint32 bl_loadFOTAImage(void)
{
   kal_uint32 base_addr = 0;
   kal_uint32 search_addr = 0;
   kal_uint32 ua_addr   = 0;
   kal_uint32 img_len   = 0;
   kal_uint32 load_addr = INVALID_DWORD;

   TS_BEGIN(TSID_BL_LOAD_FOTA_IMAGE);
   
   /* set up NOR flash information */
   Initialize_NOR_Info();
   /* search FOTA image */
   g_Bl_Secure_Test = 2;
   /* boot loader and FOTA image is block aligned */
   base_addr = custom_Block_Base(custom_get_NORFLASH_Base()) + custom_EXTBL_baseaddr();

   //BL_TODO: Optimze: to skip ExtBootloader and ExtBootloader backup if any
   
   search_addr = custom_Block_Base(base_addr);
   if(search_addr < base_addr)
   {
      search_addr += custom_Block_Size(base_addr);
   }
   
   if(bl_searchFOTAImage(search_addr, &ua_addr, &load_addr, &img_len, SSF_SearchUAImageHead))
   {
      /* Following steps are performed in bl_searchFOTAImage();
       * check FOTA image integrity 
       * search backed up FOTA image
       * check backed up FOTA image integrity */
      dbg_print("bl_loadFOTAImage: FOTA image is found on 0x%x!!\n\r", ua_addr);
      /* Since we may try to boot up UA backed up image, UA image can not be XIP. */
      memcpy((void *)load_addr, (void *)ua_addr, img_len);

      TS_END(TSID_BL_LOAD_FOTA_IMAGE);
   
      return custom_Convert_to_execution(load_addr);
   }

   return INVALID_DWORD;
}

#else   /* _NAND_FLASH_BOOTING_ */

#include "NAND_MTD.h"

kal_uint32 fue_header_buffer[FOTA_WORK_BUFFER_NUM][FOTA_FLASH_MAX_PAGE_SIZE>>2];
kal_uint32 BL_image_buffer[IMAGE_BUFFER_SIZE>>2];
kal_uint32 FUE_Map_tbl[FOTA_MAUI_MAPPING_TABLE_SIZE>>2];
kal_uint32 BL_page_buffer[FOTA_FLASH_MAX_PAGE_SIZE>>2];
kal_uint32 BL_spare_buffer[MAX_NAND_SPARE_SIZE>>2];
kal_uint32 BL_empty_spare[MAX_NAND_SPARE_SIZE>>2];
kal_uint32 nfi_spare_buffer[16];

extern BL_Info_Wrapper_st  BL_Shared_info;

extern FUE_ERROR_CODE FUE_NFB_Load_Backup_UA_ROM_Image(kal_uint32 start_blk, kal_uint32 *jmp_addr, kal_uint32 dest_addr,\
                                                       Flash_GAL_st *fgal, get_Reserved_Space get_base_func, \
                                                       dbg_trace_func dbg_trace);

extern FUE_ERROR_CODE FUE_NFB_Load_Initial_UA_ROM_Image(kal_uint32 start_blk, kal_uint32 *jmp_addr, kal_uint32 dest_addr,\
                                                        Flash_GAL_st *fgal, get_Reserved_Space get_base_func, \
                                                        dbg_trace_func dbg_trace);

extern FUE_ERROR_CODE FUE_NFB_Load_UA_ROM_Image(kal_uint16* tbl_ptr, kal_uint32 *jmp_addr, kal_uint32 dest_addr,\
                                                kal_uint32 buff_ptr[][FOTA_FLASH_MAX_PAGE_SIZE>>2], \
                                                kal_uint32 *buff_num, Flash_GAL_st *fgal, \
                                                get_Reserved_Space get_base_func, dbg_trace_func dbg_trace);

#if defined(__FUE_STRESS_TEST__)
#define BL_UA_SHARED_FOR_TEST (0x40002000)
kal_uint32 *bl_FOTA_load_tag = (kal_uint32 *)BL_UA_SHARED_FOR_TEST;
void bl_setBackupUALoad(kal_bool back_ua)
{
   if(back_ua)
   {
      *bl_FOTA_load_tag = BL_LOAD_BACKUP_UA_TAG;
   }
   else
   {
      *bl_FOTA_load_tag = 0;
   }
}
#endif /* __FUE_STRESS_TEST__ */

#ifdef __SV5_ENABLED__
_FGAL_ERROR_CODE ftl_error_2_fgal(FTL_STATUS_CODE ftlRet)
{
   switch(ftlRet)
   {
   case FTL_SUCCESS:
      return ERROR_FGAL_NONE;
      
   case FTL_ERROR_READ_FAILURE:
      return ERROR_FGAL_READ_FAILURE;
      
   case FTL_ERROR_WRITE_FAILURE:
      return ERROR_FGAL_WRITE_FAILURE;
    
   case FTL_ERROR_BAD_BLOCK:
      return ERROR_FGAL_BAD_BLOCK;

   case FTL_ERROR_OPERATION_RETRY:
      return ERROR_FGAL_OPERATION_RETRY;

   case FTL_ERROR_INVALID_PARAMETER:
      return ERROR_FGAL_INVALID_PARAMETER;

   case FTL_ERROR_ERASE_FAILURE:
      return ERROR_FGAL_ERASE_FAILURE;
      
   case FTL_ERROR_NON_EMPTY:
      return ERROR_FGAL_NON_EMPTY;
         
   case FTL_ERROR_NON_EMPTY_CHECK:
      return ERROR_FGAL_NON_EMPTY_CHECK;
      
   case FTL_ERROR_ECC_FAILURE:
      return ERROR_FGAL_ECC_FAILURE;
      
   case FTL_ERROR_ECC_CORRECTED:
      return ERROR_FGAL_ECC_CORRECTED;
      
   case FTL_ERROR_OTHER_ERROR:
   default:
   
      ASSERT(0);
   }
}
#endif

/**********************************************************
Description : NAND flash reserved area information query function.
Input       : None
Output      : None
Assumptions : 
***********************************************************/
void bl_queryReservedFlashBase(kal_uint32 *base_addr, kal_uint32 *end_addr)
{
    Nand_ImageSpace_ST  *ImageSpace = &BL_Shared_info.m_bl_image_space;

    if(INVALID_DWORD != ImageSpace->m_backup_last)
    {
        *base_addr = ((ImageSpace->m_backup_last+1) << (BLOCK_SHIFT-PAGE_SHIFT)) * BLHeader.NFIinfo.pageSize;
    }
    else if(INVALID_DWORD != ImageSpace->m_package_last)
    {
        *base_addr = ((ImageSpace->m_package_last+1) << (BLOCK_SHIFT-PAGE_SHIFT)) * BLHeader.NFIinfo.pageSize;
    }
    else
    {
        *base_addr = INVALID_DWORD;
    }

    if(INVALID_DWORD != ImageSpace->m_reserved_last)
    {
        *end_addr = (ImageSpace->m_reserved_last<<(BLOCK_SHIFT-PAGE_SHIFT))*BLHeader.NFIinfo.pageSize;
    }
    else if( INVALID_DWORD != *base_addr )
    {
        *end_addr = *base_addr + MAUI_INVISIBLE_SPACE_SIZE;
    }
    else
    {
        *end_addr = INVALID_DWORD;
    }

}

/**********************************************************
Description : NAND flash information query function.
Input       : None
Output      : None
Assumptions : 
***********************************************************/
_FGAL_ERROR_CODE bl_queryFlashInfo(Logical_Flash_info_st *info)
{

#ifdef __SV5_ENABLED__
   kal_uint32 pageSize = g_ftlFuncTbl->FTL_GetPageSize();
   kal_uint32 blockSize = g_ftlFuncTbl->FTL_GetBlockSize(0, NULL);
   kal_uint32 pagePerBlock = blockSize/pageSize;

   ASSERT(info != NULL);
   
   info->Flash_page_size = pageSize;
   info->Flash_block_size = blockSize;

   info->Flash_offset_shift = 0;
   while(pagePerBlock) { info->Flash_offset_shift++ ; pagePerBlock>>=1; };   
   info->Flash_offset_shift--;
   
   info->Flash_block_shift = 0;
   while(blockSize) { info->Flash_block_shift++ ; blockSize>>=1; };
   info->Flash_block_shift--;
#else
   ASSERT(info != NULL);
   info->Flash_page_size = BLHeader.NFIinfo.pageSize;
   info->Flash_block_size = BLHeader.NFIinfo.pageSize << (BLOCK_SHIFT-PAGE_SHIFT);
   info->Flash_offset_shift = (BLOCK_SHIFT-PAGE_SHIFT);
   info->Flash_block_shift = BLOCK_SHIFT;
#endif

   return ERROR_FGAL_NONE;
}

/**********************************************************
Description : NAND flash block check function.
Input       : None
Output      : None
Assumptions : 
***********************************************************/
_FGAL_ERROR_CODE bl_isGoodBlock(kal_uint32 blk_index)
{
   _FGAL_ERROR_CODE   result       = ERROR_FGAL_NONE;
   kal_uint32         addr1        = 0;
   kal_uint16         addr2        = 0;
   kal_uint32         page_shift   = PAGE_SHIFT;
   kal_uint32         blk_shift    = BLOCK_SHIFT;
   kal_uint32         page_idx     = 0;

#ifdef __SV5_ENABLED__
   FTL_STATUS_CODE ftlRet = g_ftlFuncTbl->FTL_CheckGoodBlock(blk_index, NULL);
   
   result = ftl_error_2_fgal(ftlRet);
#else
   page_idx = blk_index << (blk_shift - page_shift);

   if ( BLHeader.NFIinfo.addressCycle > 4 )
   {
      if ( page_idx & 0xffff0000 )
         addr2 = (kal_uint16)(page_idx>>page_shift);
      else
         addr2 = 0;
   }
   addr1 = page_idx << page_shift;
   if ( KAL_TRUE == GoodBlockChecking(&BLHeader.NFIinfo, addr1, addr2) )
   {
      result = ERROR_FGAL_NONE;
   }
   else
   {
      result = ERROR_FGAL_BAD_BLOCK;
   }
#endif
   return result;
}

#ifndef __SV5_ENABLED__
/**********************************************************
Description : NAND flash page rmpty content checking function.
Input       : None
Output      : None
Assumptions : 
***********************************************************/
kal_bool bl_checkEmpty(kal_uint32 *buff_ptr, kal_uint32* spare_ptr, kal_uint32 page_size)
{
   kal_uint32 chk_idx = 0;
   kal_uint32 spare_size = 0;
   if(4096 == page_size)
   {
      spare_size = 128;
   }
   else if(2048 == page_size)
   {
      spare_size = 64;
   }
   else
   {
      spare_size = 16;
   }

   for(chk_idx = 0 ; chk_idx < (page_size>>2) ; chk_idx++)
   {
      if(INVALID_DWORD != buff_ptr[chk_idx])
         return KAL_FALSE;
   }

   for(chk_idx = 0 ; chk_idx < (spare_size>>2) ; chk_idx++)
   {
      if(INVALID_DWORD != spare_ptr[chk_idx])
         return KAL_FALSE;
   }

   return KAL_TRUE;
}
#endif

   
/**********************************************************
Description : NAND flash page loading function.
Input       : None
Output      : None
Assumptions : 
***********************************************************/
_FGAL_ERROR_CODE bl_loadSinglePage(kal_uint32 *buff_ptr, kal_uint32 blk_index, kal_uint32 page_index)
{
#ifdef __SV5_ENABLED__
   FTL_STATUS_CODE    status       = FTL_SUCCESS;
   _FGAL_ERROR_CODE   result       = ERROR_FGAL_NONE;
   kal_uint32         page_size    = g_ftlFuncTbl->FTL_GetPageSize();
   kal_uint32         block_size   = g_ftlFuncTbl->FTL_GetBlockSize(0, NULL);
   kal_uint32         page_per_block = block_size/page_size;

   if( page_index >= page_per_block )
   {
      dbg_print("bl_loadSinglePage: page_index:%d is beyond block boundary:%d!!\n\r", page_index, page_per_block);
      result = ERROR_FGAL_BEYOND_BLOCK;
   }
   else
   {
      //ASSERT(buff_ptr != NULL);
      status = g_ftlFuncTbl->FTL_ReadPage(blk_index, page_index, buff_ptr, NULL);
      result = ftl_error_2_fgal(status);
   }
#else
   _RET_CODE          status       = NFI_SUCCESS;
   _FGAL_ERROR_CODE   result       = ERROR_FGAL_NONE;
   kal_uint32         page_size    = BLHeader.NFIinfo.pageSize;
   kal_uint32         page_shift   = PAGE_SHIFT;
   kal_uint32         blk_shift    = BLOCK_SHIFT;
   kal_uint32         base_page    = 0;
   kal_uint32         addr1        = 0;
   kal_uint16         addr2        = 0;

   if( page_index >= (1 << (blk_shift - page_shift)) )
   {
      dbg_print("bl_loadSinglePage: page_index:%d is beyond block boundary:%d!!\n\r", page_index, 1 << (blk_shift-page_shift));
      result = ERROR_FGAL_BEYOND_BLOCK;
   }
   else
   {
      //ASSERT(buff_ptr != NULL);
      base_page = blk_index << (blk_shift-page_shift);
      page_index += base_page;
      if ( BLHeader.NFIinfo.addressCycle > 4 )
      {
         if ( page_index & 0xffff0000 )
            addr2 = (kal_uint16)(page_index>>page_shift);
         else
            addr2 = 0;
      }
      addr1 = page_index << page_shift;
      status = NFI_PageRead(buff_ptr, BL_spare_buffer, page_size, BLHeader.NFIinfo.addressCycle,
                            addr1, addr2, page_size, KAL_TRUE, KAL_FALSE);

#if !defined (__NFI_VERSION2__) && !defined(__NFI_VERSION3__) && !defined(__NFI_VERSION3_1__)
      if ( status != NFI_SUCCESS )
      {
         if( (DMA_TRANSFER_DATA_TIMEOUT == status) || (NFI_READ_DATA_TIMEOUT == status) )
             result = ERROR_FGAL_OPERATION_RETRY;
         else
             result = ERROR_FGAL_READ_FAILURE;
         _errorExit(status, page_index, buff_ptr);
      }

      status = NFI_ParityCheck(buff_ptr, BL_spare_buffer, BLHeader.NFIinfo.addressCycle, addr1, 
                               addr2, page_size, BLHeader.NFIinfo.IOInterface, 512);
      if ( status < 0 )
      {
         //_errorExit(status, page_index, buff_ptr);
         status = NFI_SpareRead(BL_empty_spare, BLHeader.NFIinfo.addressCycle, addr1, addr2, page_size, BLHeader.NFIinfo.IOInterface);
         if ( status!=NFI_SUCCESS )
         {
             result = ERROR_FGAL_READ_FAILURE;
             _errorExit(status, page_index, BL_empty_spare);
         }
         if(bl_checkEmpty(buff_ptr, BL_empty_spare, page_size))
         {
            result = ERROR_FGAL_NONE;
         }
         else
         {
            result = ERROR_FGAL_ECC_FAILURE;
         }
      }
      else
      {
         result = ERROR_FGAL_NONE;
      }
#else /* __NFI_VERSION2__ */
      if(NFI_ECC_1BIT_CORRECT == status)
          result = ERROR_FGAL_ECC_CORRECTED;
      else if(NFI_ECC_2BITS_ERR == status)
          result = ERROR_FGAL_ECC_FAILURE;
      else if( (DMA_TRANSFER_DATA_TIMEOUT == status) || (NFI_READ_DATA_TIMEOUT == status) )
          result = ERROR_FGAL_OPERATION_RETRY;
      else if(NFI_SUCCESS != status)
      {
          result = ERROR_FGAL_READ_FAILURE;
          _errorExit(status, page_index, buff_ptr);
      }
#endif /* __NFI_VERSION2__ */
   }
#endif
   return result;
}

/**********************************************************
Description : NAND flash empty page check function.
Input       : None
Output      : None
Assumptions : 
***********************************************************/
_FGAL_ERROR_CODE bl_isEmptyPage(kal_uint32 *buff_ptr, kal_uint32 blk_index, kal_uint32 page_index)
{
   _RET_CODE          status       = NFI_SUCCESS;
   _FGAL_ERROR_CODE   result       = ERROR_FGAL_NONE;
   _FGAL_ERROR_CODE   rtn_val       = ERROR_FGAL_NONE;
   kal_uint32         page_size    = BLHeader.NFIinfo.pageSize;
   kal_uint32         page_shift   = PAGE_SHIFT;
   kal_uint32         blk_shift    = BLOCK_SHIFT;
   kal_uint32         spare_size   = 0;
   kal_uint32         base_page    = 0;
   kal_uint32         addr1        = 0;
   kal_uint16         addr2        = 0;
   kal_uint32         idx          = 0;
   kal_bool           empty_content = KAL_TRUE;

#ifdef __SV5_ENABLED__
   ASSERT(0);
#else

   if( page_index >= (1 << (blk_shift - page_shift)) )
   {
      dbg_print("bl_isEmptyPage: page_index:%d is beyond block boundary:%d!!\n\r", page_index, 1 << (blk_shift-page_shift));
      rtn_val = ERROR_FGAL_BEYOND_BLOCK;
   }
   else
   {
      //ASSERT(buff_ptr != NULL);
      base_page = blk_index << (blk_shift-page_shift);
      page_index += base_page;
      if ( BLHeader.NFIinfo.addressCycle > 4 )
      {
         if ( page_index & 0xffff0000 )
            addr2 = (kal_uint16)(page_index>>page_shift);
         else
            addr2 = 0;
      }
      addr1 = page_index << page_shift;
      status = NFI_PageRead(buff_ptr, BL_spare_buffer, page_size, BLHeader.NFIinfo.addressCycle,
                            addr1, addr2, page_size, KAL_TRUE, KAL_FALSE);

#if !defined (__NFI_VERSION2__) && !defined(__NFI_VERSION3__) && !defined(__NFI_VERSION3_1__)

      if ( status != NFI_SUCCESS )
      {
         if( (DMA_TRANSFER_DATA_TIMEOUT == status) || (NFI_READ_DATA_TIMEOUT == status) )
             result = ERROR_FGAL_OPERATION_RETRY;
         else
             result = ERROR_FGAL_READ_FAILURE;
         _errorExit(status, page_index, buff_ptr);
      }

      status = NFI_ParityCheck(buff_ptr, BL_spare_buffer, BLHeader.NFIinfo.addressCycle, addr1, 
                               addr2, page_size, BLHeader.NFIinfo.IOInterface, 512);
      if ( status < 0 )
      {
         //_errorExit(status, page_index, buff_ptr);
         result = ERROR_FGAL_ECC_FAILURE;
      }
      else
      {
         result = ERROR_FGAL_NONE;
      }
#else /* __NFI_VERSION2__ */
      if(NFI_ECC_1BIT_CORRECT == status)
          result = ERROR_FGAL_ECC_CORRECTED;
      else if(NFI_ECC_2BITS_ERR == status)
          result = ERROR_FGAL_ECC_FAILURE;
      else if( (DMA_TRANSFER_DATA_TIMEOUT == status) || (NFI_READ_DATA_TIMEOUT == status) )
          result = ERROR_FGAL_OPERATION_RETRY;
      else if(NFI_SUCCESS != status)
      {
          result = ERROR_FGAL_READ_FAILURE;
          _errorExit(status, page_index, buff_ptr);
      }
#endif /* __NFI_VERSION2__ */

      /* check whether page is empty */
      if(512 == page_size)
      {
         spare_size = 16;
      }
      else if(2048 == page_size)
      {
         spare_size = 64;
      }
      else if(4096 == page_size)
      {
         spare_size = 128;
      }      
      else
      {
         status = FUE_UNSUPPORTED_TYPE;
         rtn_val = ERROR_FGAL_INVALID_PARAMETER;
         _errorExit(status, page_index, buff_ptr);
      }

      if(ERROR_FGAL_READ_FAILURE != result)
      {
         status = NFI_SpareRead(BL_empty_spare, BLHeader.NFIinfo.addressCycle, addr1, addr2, page_size, BLHeader.NFIinfo.IOInterface);
         if ( status!=NFI_SUCCESS )
         {
             result = ERROR_FGAL_READ_FAILURE;
             _errorExit(status, page_index, BL_empty_spare);
         }
         empty_content = bl_checkEmpty(buff_ptr, BL_empty_spare, page_size);

         if(empty_content)
         {
            rtn_val =  ERROR_FGAL_NONE;
         }
         else
         {
            if(ERROR_FGAL_ECC_FAILURE == result)
            {
               rtn_val = ERROR_FGAL_NON_EMPTY;
            }
            else
            {
               rtn_val = ERROR_FGAL_NON_EMPTY_CHECK;
            }
         }
      }
      else
      {
         rtn_val = ERROR_FGAL_OPERATION_RETRY;
      }
   }
#endif   
   return rtn_val;
}

/**********************************************************
Description : NAND flash block index calculation function.
Input       : None
Output      : None
Assumptions : 
***********************************************************/
kal_uint32 bl_flashBlockIndex(kal_uint32 blk_address)
{
#ifdef __SV5_ENABLED__
   return blk_address/g_ftlFuncTbl->FTL_GetBlockSize(0, NULL);
#else
   kal_uint32         page_size    = BLHeader.NFIinfo.pageSize;
   kal_uint32         page_shift   = PAGE_SHIFT;
   kal_uint32         blk_shift    = BLOCK_SHIFT;

   return ((blk_address/page_size)>>(blk_shift-page_shift));
#endif
}

/**********************************************************
Description : NAND flash block size calculation function.
Input       : None
Output      : None
Assumptions : 
***********************************************************/
kal_uint32 bl_flashBlockSize(kal_uint32 blk_index)
{
#ifdef __SV5_ENABLED__
   return g_ftlFuncTbl->FTL_GetBlockSize(blk_index, NULL);
#else
   kal_uint32         page_size    = BLHeader.NFIinfo.pageSize;
   kal_uint32         page_shift   = PAGE_SHIFT;
   kal_uint32         blk_shift    = BLOCK_SHIFT;

   return (page_size << (blk_shift-page_shift));
#endif
}

Flash_GAL_st  BL_flash_gal =
{
   NULL,
   bl_queryFlashInfo,
   bl_loadSinglePage,
   NULL,
   bl_isGoodBlock,
   NULL,
   NULL,
   bl_isEmptyPage,
   NULL,
   bl_flashBlockSize,
   bl_flashBlockIndex
};

/**********************************************************
Description : look forward FUE image information position.
Input       : None
Output      : None
Assumptions : FUE image is programmed to flash in block aligned manner
***********************************************************/
kal_uint32 bl_getUAImageIndex()
{
#if defined(__MTK_SECURE_PLATFORM__) && (defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__))
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else

   return 1;

#endif

}

/**********************************************************
Description : look forward FOTA image information position.
Input       : None
Output      : None
Assumptions : FUE image is programmed to flash in block aligned manner
***********************************************************/
static kal_bool bl_searchFOTAImageInfo(kal_uint32 start_blk, GetImageInfoSize_func size_func, \
                                       SearchImageInfo_func search_func)
{
#ifdef __SV5_ENABLED__
   FTL_STATUS_CODE status;
   kal_uint32  info_len = 0;
   kal_uint32  total_length = FOTA_UE_SEARCH_RANGE_SIZE;
   kal_uint32  step_len = IMAGE_BUFFER_SIZE;
   kal_uint32  page_size = g_ftlFuncTbl->FTL_GetPageSize();
   kal_uint32  found_blk = 0;
   kal_uint32  *buff_ptr = BL_image_buffer;
   kal_uint32  read_size = 0;
   kal_uint32  block = start_blk;
   kal_uint32  curPosition = 0; /* in terms of pages */
   kal_uint32  blk_mask = 0;

   if(step_len < page_size)
   {
      dbg_print("bl_searchFOTAImageInfo: buffer size is less than flash page size!!\n\r");
      ASSERT(0);
   }

   info_len = size_func();
   total_length = ((total_length+step_len-1)/step_len)*step_len;

   while(total_length)
   {
      /* read data to buffer */
      while(read_size < step_len)
      {

         if( 0 == curPosition)
         {
            while(1)
            {
               if ( g_ftlFuncTbl->FTL_CheckGoodBlock(block, NULL) == FTL_SUCCESS )
               {
                  break;
               }
               else
               {
                  dbg_print("bl_searchFOTAImageInfo: bad block on:%d!!\n\r", block);
                  block++;
               }
            }
         }


         status = g_ftlFuncTbl->FTL_ReadPage(block, curPosition, buff_ptr+(read_size>>2), NULL);

         if(status != FTL_SUCCESS && status != FTL_ERROR_ECC_CORRECTED)
         {
            //CARLOS dbg_print(status, curPosition, buff_ptr+(read_size>>2));
         }

         read_size += page_size;
         curPosition++;
      }
      /* check whether image info. exists */
      if(search_func((kal_uint8 *)buff_ptr, step_len, NULL, NULL))
      {
         /* pattern found */
         found_blk = block;
         dbg_print("bl_searchFOTAImageInfo: target pattern is found on blk:%d!!\n\r", found_blk);
         break;
      }
      read_size = 0;
      total_length -= step_len;
   }

#else
   _RET_CODE   status;
   kal_uint32  info_len = 0;
   kal_uint32  total_length = FOTA_UE_SEARCH_RANGE_SIZE;
   kal_uint32  step_len = IMAGE_BUFFER_SIZE;
   kal_uint32  page_size = BLHeader.NFIinfo.pageSize;
   kal_uint32  found_blk = 0;
   kal_uint32  *buff_ptr = BL_image_buffer;
   kal_uint32  read_size = 0;
   kal_uint32  blk_shift = BLOCK_SHIFT;
   kal_uint32  page_shift = PAGE_SHIFT;
   kal_uint32  addr1 = 0;
   kal_uint16  addr2 = 0;
   kal_uint32  curPosition = 0; /* in terms of pages */
   kal_uint32  blk_mask = 0;

   if(step_len < page_size)
   {
      dbg_print("bl_searchFOTAImageInfo: buffer size is less than flash page size!!\n\r");
      ASSERT(0);
   }
   blk_mask = (0xffffffff >> (32-(blk_shift - page_shift)));
   curPosition = start_blk << (blk_shift - page_shift);

   info_len = size_func();
   total_length = ((total_length+step_len-1)/step_len)*step_len;

   while(total_length)
   {
      /* read data to buffer */
      while(read_size < step_len)
      {
         addr1 = curPosition << page_shift;
         if ( BLHeader.NFIinfo.addressCycle > 4 )
         {
            if ( curPosition & 0xffff0000 )
               addr2 = (kal_uint16)(curPosition>>page_shift);
            else
               addr2 = 0;
         }

         if( 0 == (curPosition & blk_mask) )
         {
            while(1)
            {
               if ( GoodBlockChecking(&BLHeader.NFIinfo, addr1, addr2) == KAL_TRUE )
               {
                  break;
               }
               else
               {
                  dbg_print("bl_searchFOTAImageInfo: bad block on:%d!!\n\r", 
                            curPosition>>(blk_shift - page_shift));
                  curPosition += (1 << (blk_shift - page_shift));
                  addr1 = curPosition << page_shift;
                  if ( BLHeader.NFIinfo.addressCycle > 4 )
                  {
                     if ( curPosition & 0xffff0000 )
                        addr2 = (kal_uint16)(curPosition>>page_shift);
                     else
                        addr2 = 0;
                  }
               }
            }
         }

         status = NFI_PageRead(buff_ptr+(read_size>>2), BL_spare_buffer, page_size, BLHeader.NFIinfo.addressCycle,
                               addr1, addr2, page_size, KAL_TRUE, KAL_FALSE);
         if ( status != NFI_SUCCESS )
            _errorExit(status, curPosition, buff_ptr+(read_size>>2));

#if !defined (__NFI_VERSION2__) && !defined(__NFI_VERSION3__) && !defined(__NFI_VERSION3_1__)

         status = NFI_ParityCheck(buff_ptr+(read_size>>2), BL_spare_buffer, BLHeader.NFIinfo.addressCycle, addr1, 
                                  addr2, page_size, BLHeader.NFIinfo.IOInterface, 512);
#endif

         if ( status < 0 )
            _errorExit(status, curPosition, buff_ptr+(read_size>>2));
         read_size += page_size;
         curPosition++;
      }
      /* check whether image info. exists */
      if(search_func((kal_uint8 *)buff_ptr, step_len, NULL, NULL))
      {
         /* pattern found */
         found_blk = curPosition>>(blk_shift - page_shift);
         if(curPosition & blk_mask)
         {
            found_blk++;
         }
         dbg_print("bl_searchFOTAImageInfo: target pattern is found on blk:%d!!\n\r", found_blk);
         break;
      }
      read_size = 0;
      total_length -= step_len;
   }
#endif
   return KAL_FALSE;
}

#ifdef __NOT_USED__
/**********************************************************
Description : look forward update agent image head position.
Input       : None
Output      : None
Assumptions : FUE image is programmed to flash in block aligned manner
***********************************************************/
static kal_bool bl_searchFOTAImageHead(kal_uint32 start_blk)
{
   return bl_searchFOTAImageInfo(start_blk, SSF_GetUAImageHeadSize, SSF_SearchUAImageHead);
}

/**********************************************************
Description : look forward update agent image tail position.
Input       : None
Output      : None
***********************************************************/
static kal_uint32 bl_searchFOTAImageTail(kal_uint32 start_blk)
{
   return bl_searchFOTAImageInfo(start_blk, SSF_GetUAImageTailSize, SSF_SearchUAImageTail);
}
#endif

#ifdef __NOT_USED__
/**********************************************************
Description : load image list information.
Input       : None
Output      : None
Assumptions : FUE image is programmed to flash in block aligned manner
***********************************************************/
kal_int32 bl_loadImageList(kal_uint32 start_blk)
{
   kal_int32      result       = FUE_IMGLIST_ERROR;
   kal_uint32     lst_blk      = INVALID_DWORD;
   kal_uint32     buff_len     = FOTA_FLASH_MAX_PAGE_SIZE;
   kal_uint32     search_range = BL_IMAGE_LIST_SEARCH_RANGE;
   kal_uint32     page_shift   = BLHeader.NFIinfo.pageShift;
   kal_uint32     page_size    = BLHeader.NFIinfo.pageSize;
   kal_uint32     blk_shift    = BLHeader.blockShift;
   kal_uint32     block_size   = 0;
   kal_uint32     blk_idx      = 0;
   kal_uint32     end_blk      = 0;
   
   block_size = page_size << (blk_shift-page_shift);
   search_range /= block_size;
   end_blk = start_blk+search_range;

   if(INVALID_DWORD != BL_Shared_info.m_bl_ilb_info.m_bl_ilb_blk)
   {
       blk_idx = BL_Shared_info.m_bl_ilb_info.m_bl_ilb_blk;
   }

   for(blk_idx = start_blk ; blk_idx < end_blk ; blk_idx++)
   {
      if( ERROR_FGAL_BAD_BLOCK == bl_isGoodBlock(blk_idx))
         continue;
      result = FUE_BlkInfo_Search_Img_ListBlock(blk_idx, BL_page_buffer, &buff_len, &BL_flash_gal, dbg_print);
      if(ERROR_FUE_NONE == result)
      {
         lst_blk = blk_idx;
         break;
      }
   }

   if( blk_idx < end_blk )/* image list block is found */
   {
      /* currently, image list occupies only one page */
      if(ERROR_FGAL_NONE == bl_loadSinglePage(BL_page_buffer, blk_idx, FOTA_IMG_LIST_INFO_PAGE))
      {
         /* copy image list to a global variable */
         kal_mem_cpy(&BL_Shared_info.m_bl_image_list, BL_page_buffer, sizeof(Nand_ImageList_S));
         if(ERROR_FGAL_NONE == bl_loadSinglePage(BL_page_buffer, blk_idx, FOTA_IMG_SPACE_INFO_PAGE))
         {
            /* copy image last block information to a global variable */
            kal_mem_cpy(&BL_Shared_info.m_bl_image_space, BL_page_buffer, sizeof(Nand_ImageSpace_ST));
            result = FUE_SUCCESS;
         }
      }
   }
   return result;
}

#endif

kal_uint32 bl_loadFOTAImage(void)
{
   kal_uint32 page_size    = BLHeader.NFIinfo.pageSize;
   kal_uint32 search_range = FOTA_UE_SEARCH_RANGE_SIZE;
   kal_uint32 block_size   = 0;
   kal_uint32 idx          = 0;
   kal_uint32 buff_len     = FOTA_FLASH_MAX_PAGE_SIZE;
   kal_uint32 table_len    = FOTA_MAUI_MAPPING_TABLE_SIZE; /*FOTA_FUE_MAPPING_TABLE_SIZE>>2;*/
   kal_uint32 page_count   = 0;
   FUE_ERROR_CODE result   = ERROR_FUE_NONE;
   kal_uint32 org_list[FUE_MAX_DUPLICATE_MAP_BLOCK];
   kal_uint32 org_num      = FUE_MAX_DUPLICATE_MAP_BLOCK;
   kal_uint32 jmp_addr     = INVALID_DWORD;
   kal_uint32 buff_num     = FOTA_WORK_BUFFER_NUM;
   _RET_CODE  status       = NFI_SUCCESS;
   kal_uint32 check_start  = INVALID_DWORD;
   kal_uint32 search_start = INVALID_DWORD;
   kal_uint32 valid_page   = 0;
   kal_uint32 valid_count  = 0;
   kal_uint32 start_blk    = 0;/* start block of FUE back up area */
   kal_uint32 fue_load_addr      = 0;
   MTK_FOTA_Map_Table_info_ST tbl_info;

#ifdef __SV5_ENABLED__   
   block_size = g_ftlFuncTbl->FTL_GetBlockSize(0, NULL);
   page_count = block_size/g_ftlFuncTbl->FTL_GetPageSize();
#else
   kal_uint32 blk_shift    = BLOCK_SHIFT;
   kal_uint32 page_shift   = PAGE_SHIFT;
   Nand_ImageList_S *ImageHeader = &BL_Shared_info.m_bl_image_list;   

   block_size = page_size << (blk_shift-page_shift);
   page_count = 1 <<  (blk_shift-page_shift);
#endif

   TS_BEGIN(TSID_BL_LOAD_FOTA_IMAGE);

   ASSERT( 0 == (search_range%block_size));

   /* help keep BL SecInfo */
   g_Bl_Secure_Test = 2;
   
   search_range = (search_range+block_size-1)/block_size;

   /* get FOTA binary information from image list*/
   BL_Shared_info.m_bl_ua_info.m_ua_map_blk = INVALID_DWORD;
   BL_Shared_info.m_bl_ua_info.m_ua_img_size = INVALID_DWORD;

#ifdef __SV5_ENABLED__
{
   if( GetBinaryRegionInFlash(FOTA_UE, &check_start, NULL) != KAL_TRUE)
   {
      check_start = INVALID_DWORD;
   }
   //FUE must be block aligned
   ASSERT(check_start % page_count == 0);
   check_start = check_start/page_count;

   //The load address is determined by the binary itself
   fue_load_addr = 0;   
}
#else
   fue_load_addr = ImageHeader->m_image[bl_getUAImageIndex()].m_load_addr;

   for(idx = 0 ; idx < ImageHeader->m_image_count ; idx++)
   {
      if(FOTA_ID_IMAGEHEADER == ImageHeader->m_image[idx].m_reserved)
      {
         check_start = ImageHeader->m_image[idx].m_start_block;
         if( ImageHeader->m_image[idx].m_length > FOTA_UE_RESIDENT_FLASH_SPACE_SIZE )
         {
            status = FUE_FOTA_IMAGE_TOO_BIG;
            _errorExit(status, 0, 0);
         }
         break;/* get FOTA image index in image list */
      }
   }
#endif

   
   if(INVALID_DWORD != check_start)
   {
      /* search MAP block */
#ifdef __SV5_ENABLED__
      search_start = check_start;    //SV5_TODO
#else
      search_start = check_start + (ImageHeader->m_image[idx].m_length+block_size-1)/block_size;
#endif
      
      for( idx = 0 ; idx < FUE_MAX_DUPLICATE_MAP_BLOCK ; idx++ )
      {
         org_list[idx] = INVALID_DWORD;
      }

      WacthDogRestart();
      result = FUE_BlkInfo_Search_UA_OrgMapBlock(search_start, search_range, org_list, &org_num,
                                                 fue_header_buffer, &buff_len, 
                                                 &BL_flash_gal , dbg_print);
      /* FOTA image space information */
      start_blk = BL_Shared_info.m_bl_image_space.m_image_space[0].m_image_start + 
                  (FOTA_UE_RESIDENT_FLASH_SPACE_SIZE+block_size-1)/block_size;
      if(ERROR_FUE_NONE == result)
      {
         if(org_num > 1)
         {
            /* power loss during update process - load back up update agent image */
            WacthDogRestart();
            result = FUE_NFB_Load_Backup_UA_ROM_Image(start_blk, &jmp_addr, fue_load_addr, \
                                                      &BL_flash_gal, bl_queryReservedFlashBase, dbg_print);
            #if defined(__FUE_STRESS_TEST__)
            bl_setBackupUALoad(KAL_TRUE);
            #endif /* __FUE_STRESS_TEST__ */
         }
         else
         {
            /* load FUE mapping table -- most recently updated one */
            WacthDogRestart();
            result = FUE_NFB_Load_Map_Table(org_list[0], FUE_Map_tbl, &table_len, BL_page_buffer, &buff_len, \
                                            &tbl_info, &BL_flash_gal, dbg_print);
            if(ERROR_FUE_NONE == result)
            {
               /* load FUE image into RAM */
               WacthDogRestart();
               result = FUE_NFB_Load_UA_ROM_Image((kal_uint16 *)FUE_Map_tbl, &jmp_addr, fue_load_addr,\
                                                  fue_header_buffer, &buff_num, &BL_flash_gal, bl_queryReservedFlashBase, \
                                                  dbg_print);

               if( ERROR_FUE_NONE != result )
               {
                  /* FOTA image under update process? -- load back up one */
                  WacthDogRestart();
                  result = FUE_NFB_Load_Backup_UA_ROM_Image(start_blk, &jmp_addr, fue_load_addr, \
                                                            &BL_flash_gal, bl_queryReservedFlashBase, dbg_print);
                  #if defined(__FUE_STRESS_TEST__)
                  bl_setBackupUALoad(KAL_TRUE);
                  #endif /* __FUE_STRESS_TEST__ */
               }
               else
               {
                  /* valid UA map block is found */
                  BL_Shared_info.m_bl_ua_info.m_ua_map_blk = org_list[0];
                  #if defined(__FUE_STRESS_TEST__)
                  bl_setBackupUALoad(KAL_FALSE);
                  #endif /* __FUE_STRESS_TEST__ */
               }
            }
            else if(ERROR_FUE_NOT_FOUND == result)
            {
               /* no valid table within the only map block -- building initial mapping table is not finished */
               result = FUE_NFB_Load_Initial_UA_ROM_Image(check_start, &jmp_addr, fue_load_addr,\
                                                          &BL_flash_gal, bl_queryReservedFlashBase, dbg_print);
            }
         }
      }
      else if(ERROR_FUE_NOT_FOUND == result)
      {
         /* initial boot up after flash download */
         /* load FUE image into RAM */
         WacthDogRestart();
         result = FUE_NFB_Load_Initial_UA_ROM_Image(check_start, &jmp_addr, fue_load_addr,\
                                                    &BL_flash_gal, bl_queryReservedFlashBase, dbg_print);
      }
      if(ERROR_FUE_NONE == result)
      {
#ifndef __SV5_ENABLED__
         /* valid UA image is found */
         BL_Shared_info.m_bl_ua_info.m_ua_img_size = SSF_GetUAImageLength()+SSF_GetUAImageTailSize();
#else
         BL_Shared_info.m_bl_ua_info.m_ua_img_size = ((GFH_FILE_INFO_v1*)(jmp_addr))->m_file_len;
#endif
      }
   }

   TS_END(TSID_BL_LOAD_FOTA_IMAGE);

   return jmp_addr;

}
#endif /* !_NAND_FLASH_BOOTING_ */

#endif /* __FOTA_DM__ */
