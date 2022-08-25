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
 *   custom_flash.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines flash related settings.
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



#ifdef REMAPPING
#define NOR_FLASH_BASE_ADDR 0x10000000
#define RAM_BASE_ADDR       0x00000000
#else
#define NOR_FLASH_BASE_ADDR 0x00000000
#define RAM_BASE_ADDR       0x10000000
#endif

/*
 ****************************************************************************
 PART 2:
 Essential Information of NOR Flash Geometry Layout Information
 ****************************************************************************
*/
/*******************************************************************************
   NOTICE: Fill the flash region information table, a region is the memory space
           that contains continuous sectors of equal size. Each region element
           in the table is the format as below:
           {S_sector, N_sector},
           S_sector: the size of sector in the region
           N_sector: the number of sectors in the region
 *******************************************************************************/
#define REGION_INFO_LAYOUT    {0x1000, 831},

#ifndef __NVRAM_BACKUP_PARTITION__
#define DISK0_REGION_INFO_LAYOUT    {0x1000, 831},
#define DISK1_REGION_INFO_LAYOUT    {0x1000, 831},
#endif

#define ENTIRE_DISK_REGION_INFO_LAYOUT    {0x1000, 2048},

/*******************************************************************************
   NOTICE. Modify the value of TOTAL_BLOCKS, which is the sum of the number of
           sectors in all regions.
           Note : The Maximum value of TOTAL_BLOCKS is (127).
 *******************************************************************************/

#ifdef __NVRAM_BACKUP_PARTITION__
#define TOTAL_BLOCKS    (NOR_ALLOCATED_FAT_SPACE/NOR_BLOCK_SIZE)+(((NVRAM_BACKUP_PARTITION_SIZE + NOR_BLOCK_SIZE - 1) & ~(NOR_BLOCK_SIZE - 1))/NOR_DISK0_BLOCK_SIZE)
#else
#define TOTAL_BLOCKS    831
#endif

/*******************************************************************************
   NOTICE. Modify the value of page buffer size in WORD for page buffer program
 *******************************************************************************/
//kal_uint32 PAGE_BUFFER_SIZE = 64;

#define BANK_INFO_LAYOUT    {0x33F000, 1}, \

/*******************************************************************************
   NOTICE. NOR FLASH BLOCKS SIZE LOOKUP TABLE
          Each entry element
          {Offset, Block_Size},
          Offset:     the offset address
          Block_Size: the size of block
 *******************************************************************************/
/*
FLASH_REGIONINFO_VAR_MODIFIER FlashBlockTBL NOTREADYYET[] =
{
    {0x0, 0x1000},
    EndBlockInfo
};
*/



#define NOR_FLASH_SIZE  0x00800000

const kal_char FLASH_ID[] = "{0xC2, 0x25, 0x37}";

/****************************************************
 * This part is for auto-gen validity CHECK *
 * Don't modify any content in this comment section *


 * NOR_FLASH_DENSITY: 0x00800000
 * NOR_FLASH_SIZE(Mb): 64

FLASH_REGIONINFO_VAR_MODIFIER FlashRegionInfo oriRegionInfo[] =
{
   {0x1000, 831},
   EndoriRegionInfo
};


static NORBankInfo oriBankInfo[] =
{
   {0x800000, 1}, \
   EndBankInfo
};

 ****************************************************/

