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
 *    fue_emmc_adapt.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This is adaption layer between FGAL and FTL for eMMC driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================*/

#ifdef __EMMC_BOOTING__

/********************************************************/
/*                  Include Header Files                */
/********************************************************/

#include "kal_release.h"

#include "ftl.h"
#include "fue_err.h"
#include "fue.h"
#include "fue_init.h"

#include "SSF_fue_support.h"


/*******************************************************************************
 *  Driver declaration
 *******************************************************************************/
 
/*******************************************************************************
 *  Global variable
 *******************************************************************************/

/*******************************************************************************
 *  Declaration for NAND flash booting
 *******************************************************************************/
extern FTL_FuncTbl ftlFuncTbl;
FTL_FuncTbl *g_ftlFuncTbl = &ftlFuncTbl;

/*******************************************************************************
 *  External reference functions
 *******************************************************************************/

/********************************************************************************
 * NAND Flash Generic Access Layer
 *******************************************************************************/
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

_FGAL_ERROR_CODE FGAL2FTL_Init(void)
{
   g_ftlFuncTbl->FTL_Init(NULL);

   return ERROR_FGAL_NONE;
}

/*******************************************************************************/
_FGAL_ERROR_CODE FGAL2FTL_Query_Info(Logical_Flash_info_st* info)
{
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
   
   return ERROR_FGAL_NONE;
}

/*******************************************************************************/
_FGAL_ERROR_CODE FGAL2FTL_Read_Page(kal_uint32* ptr, kal_uint32 blk, kal_uint32 page)
{
   FTL_STATUS_CODE    status       = FTL_SUCCESS;
   _FGAL_ERROR_CODE   result       = ERROR_FGAL_NONE;
   kal_uint32         page_size    = g_ftlFuncTbl->FTL_GetPageSize();
   kal_uint32         block_size   = g_ftlFuncTbl->FTL_GetBlockSize(0, NULL);
   kal_uint32         page_per_block = block_size/page_size;

   if( page >= page_per_block )
   {
      fue_dbg_print("FGAL2FTL_Read_Page: page_index:%d is beyond block boundary:%d!!\n\r", page, page_per_block);
      result = ERROR_FGAL_BEYOND_BLOCK;
   }
   else
   {
      //ASSERT(buff_ptr != NULL);
      status = g_ftlFuncTbl->FTL_ReadPage(blk, page, ptr, NULL);
      result = ftl_error_2_fgal(status);
   }
   return result;
}


/*******************************************************************************/
_FGAL_ERROR_CODE FGAL2FTL_Write_Page(kal_uint32* ptr, kal_uint32 blk, kal_uint32 page)
{
   FTL_STATUS_CODE    status       = FTL_SUCCESS;
   _FGAL_ERROR_CODE   result       = ERROR_FGAL_NONE;
   kal_uint32         page_size    = g_ftlFuncTbl->FTL_GetPageSize();
   kal_uint32         block_size   = g_ftlFuncTbl->FTL_GetBlockSize(0, NULL);
   kal_uint32         page_per_block = block_size/page_size;

   if( page >= page_per_block )
   {
      fue_dbg_print("FGAL2FTL_Write_Page: page_index:%d is beyond block boundary:%d!!\n\r", page, page_per_block);
      result = ERROR_FGAL_BEYOND_BLOCK;
   }
   else
   {
      status = g_ftlFuncTbl->FTL_WritePage(blk, page, ptr, NULL);
      result = ftl_error_2_fgal(status);
   }
   return result;
}

/*******************************************************************************/
_FGAL_ERROR_CODE FGAL2FTL_Erase_Block(kal_uint32 blk)
{
   FTL_STATUS_CODE    status       = FTL_SUCCESS;
   _FGAL_ERROR_CODE   result       = ERROR_FGAL_NONE;

   status = g_ftlFuncTbl->FTL_EraseBlock(blk, NULL);
   result = ftl_error_2_fgal(status);

   return result;
}

/*******************************************************************************/
_FGAL_ERROR_CODE FGAL2FTL_Is_Good_Block(kal_uint32 blk_idx)
{
   return ERROR_FGAL_NONE;
}

/*******************************************************************************/
_FGAL_ERROR_CODE FGAL2FTL_Mard_Bad_Block(kal_uint32 blk_idx)
{
   return ERROR_FGAL_NONE;
}

/*******************************************************************************/
_FGAL_ERROR_CODE FGAL2FTL_Is_Empty_Page(kal_uint32 *buff, kal_uint32 blk_idx, kal_uint32 page_idx)
{

   _FGAL_ERROR_CODE   result       = ERROR_FGAL_NONE;

   result = FGAL2FTL_Read_Page(buff, blk_idx, page_idx);

   if(result == ERROR_FGAL_NONE)
   {
      kal_uint32 i;
      for(i=0; i<g_ftlFuncTbl->FTL_GetPageSize()/4; i++)
      {
         if(buff[i] != 0xffffffff)
         {
            return ERROR_FGAL_NON_EMPTY_CHECK;
         }
      }

      return ERROR_FGAL_NONE;
   }

   return result;
   
}

/*******************************************************************************/
kal_uint32 FGAL2FTL_Block_Size(kal_uint32 blk_idx)
{
   return g_ftlFuncTbl->FTL_GetBlockSize(blk_idx, NULL);
}

/*******************************************************************************/
kal_uint32 FGAL2FTL_Block_Index(kal_uint32 blk_addr)
{
   return blk_addr/g_ftlFuncTbl->FTL_GetBlockSize(0, NULL);
}

/*******************************************************************************/
_FGAL_ERROR_CODE FGAL2FTL_Lock_Block(kal_uint32 blk, kal_bool locked)
{
   return ERROR_FGAL_NONE;
}

#endif /* __EMMC_BOOTING__ */
