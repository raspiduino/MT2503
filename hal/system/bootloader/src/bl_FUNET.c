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
 *   bl_FUNET.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if defined(__FUNET_ENABLE__) && defined (__SV5_ENABLED__)


#define STATIC

#include <string.h>
#include <bl_types.h>
#include <bl_init.h>
#include <bl_common.h>
#include <bl_features.h>
#include <bl_loader.h>
//#include <msdc_adap_bl.h>
#include "bl_funet.h"
#include "dcl.h"
#include "ftl.h"
#include "kbd_table.h"
#include "drvpdn.h"
#include "bl_mtk_bb_reg.h"

#if defined(_NAND_FLASH_BOOTING_)
#include <nand_fdm.h>
#endif

#include "fs_gprot.h"

#include "cbr.h"
#include "br_GFH_parser.h"
#include "br_GFH_maui_info.h"
#include "br_GFH_flash_info.h"
#include "br_GFH_error.h"

#ifdef __FOTA_DM__
#include "custom_img_config.h"
#include "fue_err.h"
#include "fue.h"
#include "SSF_ROMinfo.h"
#include "SSF_ROMInfo_type.h"
#endif

#ifdef __EXT_BOOTLOADER__ 

/*************************************************************************
 * Macro and const definition
 *************************************************************************/
//#define __TRANSMISSION_DEBUG__

#define TRIGGER_KEY               (DEVICE_KEY_DOWN) //This key is customizable. Please lookup kdb_table.h
#define HASH_LEN                  (20)
#define WORKING_BUF_LEN           (16*1024)     //Working buffer must larger than GFH + NFB Image header(image record at least)+signatures
#define JUMP_TBL_LEN              (1*1024)     //Working buffer must larger than GFH + NFB Image header(image record at least)+signatures


#ifdef _NAND_FLASH_BOOTING_
#define ASSERT_VALID_PARAM_IN_NAND_IMAEG_HEADER(x) if(!(x)) {BL_PRINT(LOG_ERROR, "bl_Update ASSERT @ %d\n\r", __LINE__); return BL_FUNET_ERROR_INVALID_PARAM_IN_NAND_IMAGE_HEADER;}
#endif
#define ASSERT_VALID_PARAM_IN_XIM_BODY(x)          if(!(x)) {BL_PRINT(LOG_ERROR, "bl_Update ASSERT @ %d\n\r", __LINE__); return BL_FUNET_ERROR_INVALID_PARAM_IN_XIM_BODY;}

#define DUMMY_FILENAME            "DUMMY"

//Phase definition for displaying progress bar
#define INIT_PHASE   0
#define VERIFY_PHASE 1
#define UPDATE_PHASE 2
#define FINISH_PHASE 3

#ifdef _NAND_FLASH_BOOTING_

//Indexes in nand image
#define XIM_MAUI_IDX                   (xim_maui_index)
#define XIM_NAND_ADDED_NUM             (2)                       //boot_info and main_info
#define GetExtraInfoidByNANDimgid(x)   (x - XIM_NAND_ADDED_NUM)  //x must larger than XIM_MAUI_IDX
#define GetFlashLayoutidByNANDimgid(x) (x - XIM_MAUI_IDX)        //x must larger than XIM_MAUI_IDX

#endif /* _NAND_FLASH_BOOTING_ */

#define IS_OVERLAP(s1, l1, s2, l2) (((s1)>=(s2) && (s1)<(s2)+(l2)) || ((s2)>=(s1) && (s2)<(s1)+(l1)))

#define REMAPPING_MASK (custom_RAM_baseaddr()-1)
#ifdef __RAM_FLASH_REMAP_DONE_IN_EMI_INIT__
#define MAUI_ROM_START_ADDR (custom_ROM_baseaddr())   //Memory is remapped by HW, no need to remap the address here.
#define ROM_ADDR_MASK (custom_RAM_baseaddr())
#else
#define MAUI_ROM_START_ADDR (custom_ROM_baseaddr() & REMAPPING_MASK)
#define ROM_ADDR_MASK (0)
#endif
#define BOOTLOADER_ROM_REGION_LEN (custom_ROM_baseaddr()-custom_RAM_baseaddr())

/*************************************************************************
 * Structure definition
 *************************************************************************/
#if defined(_NAND_FLASH_BOOTING_)

typedef struct
{
    kal_uint16 page_size;
    kal_uint16 block_size;
    kal_uint16 plane_size;
    kal_uint16 addr_cycle;
    kal_uint8  io_width;
    kal_uint8  feature_set[3];
    kal_uint16 FDM_ver;
    kal_uint16 ECC_ver;

    kal_uint32 IM_Ext_Ver;
    kal_uint32 reserve_1;
    kal_uint32 reserve_2;
    kal_uint32 reserve_3;

    kal_uint32 Boot_Info_Addr;
    kal_uint32 Main_Info_Addr;
    kal_uint32 Control_Info_Addr;
    kal_uint16 Boot_Info_Count;
    kal_uint16 Main_Info_Count;


} DL_PACKAGE_NAND_IMAGE_HEADER;

typedef struct
{
   kal_uint32 start_block;
   kal_uint32 blocks;
   kal_uint32 feature_bit;
   kal_uint32 max_block;
} DL_PACKAGE_NAND_IMAGE_HEADER_IMG_RECORD;

typedef struct
{
   kal_uint32 size;
   kal_uint32 log2phy[1];
} DL_PACKAGE_NAND_IMAGE_HEADER_FDM5_MAP_TBL;

typedef struct
{
   kal_uint32 dummy;
} DL_PACKAGE_NOR_IMAGE_HEADER;

typedef struct {
	kal_uint32	RPB_Size;
	kal_uint32	GroupNum;
	kal_uint32	PhyicalBlkNum;
	kal_uint32	DataBlkNum;
	kal_uint32	RvdBlkNum;
	kal_uint32	RvdBlkStartAddr;
	kal_uint32	RemapStartLogAddr;
	kal_uint32	BRMTSize;
	kal_uint16	PageSize;	// Only useful for ImageMaker. In NAND writer case, this field is reserved.
	kal_uint16	BlockSize;	// Only useful for ImageMaker. In NAND writer case, this field is reserved.
	kal_uint32	RVD[3];
} REGION_PARAM_BLOCK_HEADER;

typedef struct {
	kal_uint32	GroupNo:8;
	kal_uint32	PhyBlkAddr:24;
} BLOCK_MAPPING_TABLE_ENTRY;

typedef struct {
   struct {
      kal_uint32 Base;
      kal_uint32 Size;
   } fs[8];
} FS_LAYOUT;

#endif /* _NAND_FLASH_BOOTING_ */

/*************************************************************************
 * External reference definition
 *************************************************************************/
#if defined(_NAND_FLASH_BOOTING_)
#else  /* _NAND_FLASH_BOOTING_ */
extern kal_uint32  Image$$EXT_READ_WRITE$$ZI$$Limit;
#endif /* _NAND_FLASH_BOOTING_ */

extern BL_Info_Wrapper_st  BL_Shared_info;
extern kal_bool bl_Alg_Hash_Init(void);
extern kal_bool bl_Alg_Hash_Append(kal_uint32 addr, kal_uint32 len);
extern kal_bool bl_Alg_Hash_Finish(kal_uint32 digest, kal_uint32 len);
extern kal_bool bl_Alg_Asym_Decrypt(kal_uint32 dest_addr, kal_uint32 src_addr, kal_uint32 len, kal_uint32 key, kal_uint32 key_len);

extern kal_uint32 SST_Get_Platform_ID(kal_uint32 rom_base, kal_uint8 *ver_buf, kal_uint32 len);
extern kal_uint32 SST_Get_MAUI_Feature_Combination(kal_uint32 rom_base, kal_uint32 *pFeatureCombination);
extern kal_uint32 SST_Get_MAUI_Paired_Version(kal_uint32 rom_base);
extern kal_uint32 SST_Get_SW_Version(kal_uint32 rom_base, kal_uint8 *ver_buf, kal_uint32 len);
extern kal_bool CheckFeatureCompatibility(kal_uint32 featureSet);

extern kal_bool BL_kbd_IsKeyPressed(kal_uint8 key);

// Raymond : LCD related code, mark it now and you can remove it if it is really unnecessary
/*#if defined(__LCD_DRIVER_IN_BL__)
extern void BL_LCDHWInit(void);
extern void BL_LCDSetBackLight(void);
extern void BL_ShowUpdateFirmwareInitBackground(void);
extern void BL_ShowUpdateFirmwareProgress(kal_uint16 percentage);
extern void BL_ShowUpdateFirmwareFail(kal_int32 r, kal_int32 g, kal_int32 b);
extern void BL_ShowUpdateFirmwareOK(void);
#endif*/ /* __LCD_DRIVER_IN_BL__ */

extern kal_uint32 custom_get_CDL_asymmetric_key_len(void);
extern const kal_uint8* custom_get_CDL_asymmetric_key(void);
extern kal_bool custom_CDL_check_dl_package_version(kal_uint8 *romSwVer, kal_uint8 *pkgSwVer, kal_uint8 *pkgLimit);
extern kal_bool custom_CDL_check_dl_platform_id(kal_uint8 *romPID, kal_uint8 *pkgPID, kal_uint8 *pkgLimit);
extern kal_bool custom_CDL_customer_info_check(kal_uint32 *pCustomerInfo, kal_uint32 len);
extern FTL_FuncTbl ftlFuncTbl;

#ifdef __FOTA_DM__
extern kal_uint32 g_maui_image_info_validity;
extern MTK_FOTA_ROM_Info_v1_ST   g_maui_image_info;
#endif

/*************************************************************************
 * Global variables definition
 *************************************************************************/
kal_uint32 page_buffer[MAX_PAGE_SIZE_WITH_SPARE/4];           //Read/write buffer for NAND driver
static kal_uint8  work_buf[WORKING_BUF_LEN];                           //Working buffer for GFH, Image Header, signatures
static kal_uint8  jump_tbl_buf[JUMP_TBL_LEN ];

static kal_uint32 dl_package_size = 0;
static kal_uint32 im_file_size = 0;

static kal_uint8 hash_value[HASH_LEN];

DL_PACKAGE_GFH *pDl_Package_GFH = NULL;

/*IOT FOTA Header is used for offset info of each binary 

    Binary Structure
===      GFH        ===
=== IOT_FOTA_HEADER ===
=== PACKAGE_CONTENT ===
===   SIGNAURE1     ===
===   SIGNATURE2    ===
*/
const IOT_HEADER *pDl_IOT_HEADER = NULL;



/********
Image Buffer
***/
/*This value should sync with decompression API*/
#define DECOMPRESS_WORK_BUF_LEN        40960 // 40*1024 = 40K

extern kal_uint32 Image$$EXT_BL_IOT_FOTA_DECOMPRESSION_BUF$$ZI$$Limit;
extern kal_uint32 Image$$EXT_BL_IOT_FOTA_DECOMPRESSION_BUF$$ZI$$Length;
extern kal_uint32 Image$$EXT_BL_IOT_FOTA_DECOMPRESSION_BUF$$ZI$$Base;
extern kal_uint32 Image$$EXT_BL_IOT_FOTA_IMAGE_BUF$$ZI$$Base;
extern kal_uint32 Image$$EXT_BL_IOT_FOTA_IMAGE_BUF$$ZI$$Length;

extern kal_uint32 Image$$EXT_BL_IOT_FOTA_WORKING_BUF$$ZI$$Base;

/*This buffer for decompression API*/
kal_uint8 *  decompress_work_buf = 0;

/*This buffer for compressed image*/
kal_uint8 *  image_buf = 0;

/*This buffer for decompressed image*/
kal_uint8 *  decompression_buf = 0;

#pragma arm section zidata = "EXT_BL_IOT_FOTA_RAM_DUMMY_END"
kal_uint32  ram_dummy_end[1] ;
#pragma arm section zidata

kal_bool isCompressed = 0;


// Flash dependent variables
#if defined(_NAND_FLASH_BOOTING_)
static kal_uint32 remap_tbl[(64*1024)/4];                              //REMAP table for 1. filesystem. the BRMT is 64K at most, 2. ENFB remap table, assume max item is 4096
static BLOCK_MAPPING_TABLE_ENTRY map_tbl[8192];                        //MAP table for filesystem.
static DL_PACKAGE_NAND_IMAGE_HEADER *pDl_Package_Nand_Image_Header = NULL;
static DL_PACKAGE_NAND_IMAGE_HEADER_IMG_RECORD *pMAUIImage = NULL;
static DL_PACKAGE_NAND_IMAGE_HEADER_IMG_RECORD *pFSImage = NULL;

static DL_PACKAGE_NAND_IMAGE_HEADER_FDM5_MAP_TBL *pFDM5MappingTbl = NULL;
static kal_uint32 FDM5MappingTblLen = 0;
static kal_uint32 FDM5MappingTblEntryNum = 0;
static kal_uint32 pFDM5MappingTblOffset = 0;

// NAND-related parameters
kal_uint32 page_size = 0;
kal_uint32 page_per_block = 0;
static kal_uint32 block_size = 0;
static kal_uint32 page_size_with_spare = 0;
static kal_uint32 block_size_with_spare = 0;
Nand_ImageSpace_ST *pSpaceInfo = NULL;

#else /* _NAND_FLASH_BOOTING_ */

kal_uint32 page_size = NOR_PAGE_SIZE;
static kal_uint32 page_size_with_spare = NOR_PAGE_SIZE;
static kal_uint32 mauiFirstBlock = 0;

static kal_uint32 flash_pmaui_gfh_buf[NOR_PAGE_SIZE>>2];

#endif /* _NAND_FLASH_BOOTING_ */

// SVx dependent variables
static kal_uint32 pmaui_gfh_buf[FUNET_MAX_PAGE_SIZE/4];
static FlashLayout flash_layout_info;
static Nand_ImageSpace_ST space_info;
static kal_uint32* pMauiInfoInCard; // It will point into pmaui_gfh_buf
static UPDATING_RECORD UpdatingRecord;
static kal_uint32 xim_cbr_index;
static kal_uint32 xim_maui_index;

static kal_uint32 image_count = 0;
static kal_uint32 fs_image_count = 0;
static kal_uint32 nand_image_header_len = 0;           //Length of NAND image header (excluding GFH)
static kal_uint32 header_block_count = 0;
static kal_uint32 extra_info_count = 0;

static kal_uint8 *pSignatureBegin = NULL;
static kal_uint32 signatureLength = 0;                 //2 signatures currently

static kal_uint32 codeRegionEndIndex = 0;

static kal_bool   last_funet_fail_flag = KAL_FALSE;
//static kal_bool   fsPartialUpdate = KAL_FALSE;
static kal_bool   codePartialUpdate = KAL_FALSE;
static kal_bool   ximFixedLayout = KAL_FALSE;        //If XIM is MBA is FOTA load, this flag will be raised
static kal_bool   mbaUpdate = KAL_FALSE;             //IF update bin have MBA, this flag wil be raised



extern FTL_FuncTbl *g_ftlFuncTbl;

// Raymond : LCD related code, mark it now and you can remove it if it is really unnecessary
/*#if defined(__LCD_DRIVER_IN_BL__) 
static kal_bool lcd_inited = KAL_FALSE;
#endif*/ /* __LCD_DRIVER_IN_BL__ */

#ifdef __FOTA_DM__
MTK_FOTA_ROM_Info_v1_ST fotaRomInfo;
#endif
/*************************************************************************
 * Declaration
 *************************************************************************/
BL_FUNET_ERROR_CODE bl_ReadXIMPage(kal_uint32 addr, kal_uint32 pageIdx, kal_uint32 page_count, kal_bool doHash);
STATIC kal_bool bl_IsValidBinInfoItem(GFH_DL_PACKAGE_EXTRA_INFO *pInfo);
STATIC kal_bool bl_IsMarkerFound(kal_uint32 mauiAddr);

static kal_bool bl_IsFUNETMarkerFound();

/*************************************************************************
 * Test code
 *************************************************************************/


#if defined(__TRANSMISSION_DEBUG__)

static const kal_uint32 CRC_TBL_LEN = 256;
static kal_uint32 crc_table[CRC_TBL_LEN]; /* Table of CRCs of all 8-bit messages. */
static kal_uint32 crc_init = 0;


STATIC void Build_CRC_TBL(void)
{
    kal_uint32 c;
    kal_int32 n, k;

    for (n = 0; n < CRC_TBL_LEN; n++)
    {

        c = (kal_uint32)n;

        for (k = 0; k < 8; k++)
        {

            if (c & 1)
            {

                c = TRANSMISSION_DBG_MAGIC ^ (c >> 1);
            }
            else
            {

                c = c >> 1;
            }
        }

        crc_table[n] = c;
    }
}

STATIC kal_uint32 Update_CRC(kal_uint32 crc, kal_uint8 *buf, kal_uint32 len)
{
    kal_uint32 n, c = crc;
    if(!crc_init)
    {
       Build_CRC_TBL();
       crc_init = 702;
    }

    for (n = 0; n < len; n++)
    {

        c = crc_table[(c ^ buf[n]) & TRANSMISSION_WRAP_MASK] ^ (c >> 8);
    }

    return c;
}

#endif /* defined (__TRANSMISSION_DEBUG__) */

/*************************************************************************
 * General storage adatpation interfaces
 *************************************************************************/


static kal_int32 bl_fs_handle;             //For keeping the file handle got from FS
static kal_int32 bl_fs_seek_pointer;       //For record the file position during file system update on the net (FUNET)
static kal_int8 *pbl_ram_seek_pointer;      //For record the file position on the external ram (FUNET)
static kal_int32 bl_fs_postion;         //To record the current file position

/***************************************************************************//**
 * @brief The interface for FUNET to open file with File system existed.
 * 
 * This function is not alowed to be re-entrant.
 *
 * @param[in] filename    It is not used yet. Reserved the flexibility for future.
 *
 * @return  The error code. If the error code from FS is not recognizable, it just return
 *                the error code from FS.
 *
 ******************************************************************************/
kal_int32 bl_DL_Open(const kal_char *filename)
{

   //The drive letter will be taken by FS and always be redirect to the correct card drive
   //Thus we can use any drive letter here
   bl_fs_handle = FS_Open(FUNET_PKG_PATH, FS_READ_WRITE);

   //Check the result of FS API, and convert it to BL error code
   if(bl_fs_handle >= FS_NO_ERROR)
   {
   	  bl_fs_postion = 0;
      return BL_FUNET_ERROR_NONE;
   }
   else //Something wrong in FS, just return the error code from FS
   {
      if (bl_fs_handle == FS_FILE_NOT_FOUND || bl_fs_handle == FS_PATH_NOT_FOUND)
      {
          return BL_FUNET_ERROR_NO_DL_PACKAGE_FOUND;
      }
      return bl_fs_handle;
   }
}

/***************************************************************************//**
 * @brief The interface for FUNET to seek file with File system existed.
 * 
 * This function redirects to the subset functionaility of FS_seek.
 *
 * @param[in] offset    The offset of file from the file begin.
 * @param[in] origin    Reserved
 *
 * @return  The error code. If the error code from FS is not recognizable, it just return
 *                the error code from FS.
 *
 ******************************************************************************/

kal_int32 bl_fs_Seek(kal_uint32 offset, kal_int32 origin)
{
   ASSERT(origin == 0);
   
   bl_fs_seek_pointer = FS_Seek(bl_fs_handle, offset, 0);

   //Check the result of FS API, and convert it to BL error code
   if(bl_fs_seek_pointer >= FS_NO_ERROR)
   {
   	  bl_fs_postion = offset;
      return BL_FUNET_ERROR_NONE;
   }
   else
   {
      return bl_fs_seek_pointer;
   }
}







kal_int32 bl_DL_Seek(kal_uint32 offset, kal_int32 origin)
{
   U32 image_buf_limit = (kal_uint32)(&Image$$EXT_BL_IOT_FOTA_DECOMPRESSION_BUF$$ZI$$Limit);

   ASSERT(origin == 0);

   if(isCompressed)
   {
       pbl_ram_seek_pointer = ((kal_uint8*)decompression_buf)+offset;

       //Check the result of FS API, and convert it to BL error code
       if(pbl_ram_seek_pointer >= 0 && (U32)pbl_ram_seek_pointer < image_buf_limit)
       {
          return BL_FUNET_ERROR_NONE;
       }
       else
       {
          BL_PRINT(LOG_DEBUG, "Seek failed out of memory range...\n\r"); 
          return -1 ;
       }

   }
   else
   {
       bl_fs_seek_pointer = FS_Seek(bl_fs_handle, offset, FS_FILE_BEGIN);

       //Check the result of FS API, and convert it to BL error code
       if(bl_fs_seek_pointer >= FS_NO_ERROR)
       {
          return BL_FUNET_ERROR_NONE;
       }
       else
       {
          return bl_fs_seek_pointer;
       }

   }
  
}



/***************************************************************************//**
 * @brief The interface for FUNET to read file with File system existed.
 * 
 * This function must be used after bl_DL_Open(). It will use the pre-defined file handle to
 * get the file into buffer.
 *
 * @param[in] buffer    The buffer to be put the read data.
 * @param[in] len         The length to read
 *
 * @return  If there is no error, The return value is the same as the input len. It is due to its caller
 *                expect there is no error only when the return == len.
 *
 ******************************************************************************/
kal_uint32 bl_fs_Read(void *buffer, kal_uint32 len)
{
   kal_uint32 read; 
   kal_int32  status;

   status = FS_Read(bl_fs_handle, buffer, len, &read);

   //Check the result of FS API, and convert it to BL error code
   if(status >= FS_NO_ERROR)
   {
   	  bl_fs_postion += len;
      // Ignore the remaining length if it encountered the file end
      return len;
   }
   else
   {
      return -1;
   }
}

kal_uint32 bl_DL_Read(void *buffer, kal_uint32 len)
{

   U32 image_buf_limit = (kal_uint32)(&Image$$EXT_BL_IOT_FOTA_DECOMPRESSION_BUF$$ZI$$Limit);

   kal_uint32 read; 
   kal_int32  status;
  

   if(isCompressed)
   {
       memcpy(buffer, pbl_ram_seek_pointer, len);
       pbl_ram_seek_pointer += len;

       //Check if seek pointer is still in valid range
       if(pbl_ram_seek_pointer >= 0 && (U32)pbl_ram_seek_pointer < image_buf_limit)
       {
          return len;
       }
       else
       {
          BL_PRINT(LOG_DEBUG, "Read failed out of memory range...\n\r");  
          return -1;
       }
   }
   else
   {
       status = FS_Read(bl_fs_handle, buffer, len, &read);
       //Check the result of FS API, and convert it to BL error code
       if(status == FS_NO_ERROR)
       {
          // Ignore the remaining length if it encountered the file end
          return len;
       }
       else
       {
          return 0;
       }
   }
}



/***************************************************************************//**
 * @brief The interface for FUNET to close file with File system existed.
 * 
 * This function will close the file handler for cardDL, and deinit msdc.
 *
 ******************************************************************************/
void bl_DL_Close()
{
   //Close the file
   if(bl_fs_handle)
   {
   	  bl_fs_postion = 0;
      FS_Close(bl_fs_handle);
   }

}

typedef struct {
	kal_uint32	partitionNumber;
	kal_uint32	type;
	kal_uint32	sourceAddress;
	kal_uint32	sourceSize;
	kal_uint32	destinationAddress;
	kal_uint32	destinationSize;
} COMPRESSED_BIN_HEADER;

kal_bool bl_checkIsCompressed(kal_uint8 *image_buf)
{
	COMPRESSED_BIN_HEADER * compressedHeader = (COMPRESSED_BIN_HEADER*)image_buf;
	kal_uint32 magic_num1 = compressedHeader->partitionNumber;
	kal_uint32 magic_num2 = compressedHeader->type;
	kal_uint32 magic_num3 = compressedHeader->sourceAddress;

	/*Beginning 12 byte of compressed binary can use as magic number*/
	if( (magic_num1 == 1) && (magic_num2 == 0) && (magic_num3 == 24))
		return KAL_TRUE;
	else
		return KAL_FALSE;
}


BL_FUNET_ERROR_CODE bl_readFiletoRam()
{

    typedef void (*ZImageNotifyFunction)(kal_uint32, kal_uint32);
    extern void ZImageDecompressByPartition(kal_uint32 source, kal_uint32 destination,kal_uint32 notifyLength, kal_uint32 notifyTotalLength,kal_uint32 *notifyCurrentLength, ZImageNotifyFunction notifyFunction);
    extern kal_bool SetZImageWorkingMemory(kal_uint32 workingBuffer, kal_uint32 workingSize);
	
    kal_uint32 len;
    kal_uint32 file_size;
    kal_uint32 work_buf = (kal_uint32)decompress_work_buf;
    kal_uint32 source = (kal_uint32)image_buf;
    kal_uint32 dest = (kal_uint32)decompression_buf;
    kal_uint32 source_length = (kal_uint32)(&Image$$EXT_BL_IOT_FOTA_IMAGE_BUF$$ZI$$Length);
    kal_uint32 dest_length=    (kal_uint32)(&Image$$EXT_BL_IOT_FOTA_DECOMPRESSION_BUF$$ZI$$Length);
    DL_PACKAGE_GFH *pPackage_GFH = NULL;

    isCompressed = KAL_FALSE;

    /*Dummy reference for variable linking*/
    ram_dummy_end[0] =1;

    /*Get size of update file*/
    len = FS_GetFileSize(bl_fs_handle,&file_size);    
    BL_PRINT(LOG_DEBUG, " image.bin size:%x\n\r", file_size);

    /*Check compressed file size */
    CacheInit(); 

    if(len > source_length)
    {
        file_size = source_length;
        BL_PRINT(LOG_DEBUG, "Warning: Image Size is larger than image_buf, this image don't support decompressed feature\n\r");
        //return BL_FUNET_ERROR_COMPRESSED_BINARY_TOO_LARGE; 
    }
    else
    {
        /*Read From fs to RAM*/      
        if( bl_fs_Read(image_buf, file_size) !=  file_size)
        {
          return BL_FUNET_ERROR_COPY_TO_RAM_FAIL;
        }

        bl_fs_Seek(0,0);

       /*Decompression*/
       isCompressed = bl_checkIsCompressed(image_buf);
    }
  
	if(isCompressed)
	{
	    BL_PRINT(LOG_DEBUG, "This is Compressed binary!\n\r");
		SetZImageWorkingMemory(work_buf,DECOMPRESS_WORK_BUF_LEN);
		ZImageDecompressByPartition(source, dest,0,0,NULL,NULL);
	}
    else
	{
	    decompression_buf = image_buf;
		memcpy(decompression_buf,image_buf,file_size);
	}
    CacheDeinit();


    /*Check de-compressed file size */
    pPackage_GFH = (DL_PACKAGE_GFH*)decompression_buf;
    if(isCompressed && pPackage_GFH->gfh_file_info.m_file_len > dest_length)
    {
        return BL_FUNET_ERROR_DECOMPRESSED_BINARY_TOO_LARGE; 
    }
    
     
   pbl_ram_seek_pointer = (kal_uint8*)decompression_buf;
   
   return BL_FUNET_ERROR_NONE;
     
}

/*************************************************************************
 * Public interface
 *************************************************************************/

/**********************************************************
Description : To tell if FUNET is under processing
Input       : None
Output      : None
***********************************************************/
kal_bool bl_IsFUNETGoing()
{

#ifndef _NAND_FLASH_BOOTING_

   if(bl_IsFUNETMarkerFound())
   {
      BL_PRINT(LOG_DEBUG, "Last FUNET is failed. Re-update Now...\n\r");
      last_funet_fail_flag = KAL_TRUE;
      return KAL_TRUE;
      
   }
   
#else /* _NAND_FLASH_BOOTING_ */

   //Check if there is updating record
   if(CBR_GetRecordLen(E_CBR_IDX_CBR, CBR_RECORD_UPDATING_INFO)>0)
   {
      //Read the updating record
      if(CBR_ReadRecord(E_CBR_IDX_CBR, CBR_RECORD_UPDATING_INFO, (kal_uint8*)&UpdatingRecord, sizeof(UPDATING_RECORD), NULL) <= 0)
      {
         return KAL_FALSE;
      }

      //Check if the updating record is belong to FUNET
      if(UpdatingRecord.m_info_type_magic == FUNET_MARKER)
      {
      	 BL_PRINT(LOG_DEBUG, "Last FUNET is failed. Re-update Now...\n\r");

         last_funet_fail_flag = KAL_TRUE;
         return KAL_TRUE;
      }
   }

#endif /* _NAND_FLASH_BOOTING_ */

   return KAL_FALSE;
}


void bl_ClearFUNETTrigger()
{
   return;
}

/*************************************************************************
 * Utilities
 *************************************************************************/
#ifdef _NAND_FLASH_BOOTING_

kal_uint32 bl_PhyBlockIdx2Logical(kal_uint32 physicalIdx)
{
   kal_uint32 logicalIdx = INVALID_BLOCK_IDX;
   kal_uint32 i;
   if(pFDM5MappingTbl)
   {
      for(i=0; i<FDM5MappingTblEntryNum; i++)
      {
         if(pFDM5MappingTbl->log2phy[i] == physicalIdx)
         {
            logicalIdx = i;
            break;
         }
      }
   }
   else
   {
      kal_uint32 page = pFDM5MappingTblOffset/page_size;
      kal_uint32 *p = (kal_uint32*)((kal_uint8*)page_buffer + pFDM5MappingTblOffset%page_size+4);
      if(bl_ReadXIMPage((kal_uint32)page_buffer, page, 1, KAL_FALSE) != BL_FUNET_ERROR_NONE)
      {
         return INVALID_BLOCK_IDX;
      }

      for(i=0; i<FDM5MappingTblEntryNum; i++)
      {
         if(*p == physicalIdx)
         {
            //Debug only if(logicalIdx != INVALID_BLOCK_IDX) ASSERT(logicalIdx == i);
            logicalIdx = i;
            break;
         }

         if((kal_uint8*)(++p) >= (kal_uint8*)page_buffer+page_size)
         {
            page++;
            if(bl_ReadXIMPage((kal_uint32)page_buffer, page, 1, KAL_FALSE) != BL_FUNET_ERROR_NONE)
            {
               return INVALID_BLOCK_IDX;
            }
            p = page_buffer;
         }
      }
   }

   return logicalIdx;
}

#else /* _NAND_FLASH_BOOTING_ */

kal_uint32 bl_AddrToBlockIdx(kal_uint32 addr, FTL_OptParam *opt_param)
{
   kal_uint32 Block;
   kal_uint32 Page;
   kal_uint32 status;
   
   status = g_ftlFuncTbl->FTL_AddrToBlockPage(addr, &Block, &Page, opt_param);

   ASSERT(status == FTL_SUCCESS);

   return Block;
}

#endif /* _NAND_FLASH_BOOTING_ */

STATIC kal_bool bl_IsAddrOnBoundary(kal_uint32 addr)
{
#ifdef _NAND_FLASH_BOOTING_
   return (addr%block_size == 0);
#else
   return (addr == 0 || (bl_AddrToBlockIdx(addr-1, NULL) + 1 == bl_AddrToBlockIdx(addr, NULL)));
#endif /* _NAND_FLASH_BOOTING_ */
}


kal_bool bl_IsRegionOverlap(kal_uint32 addr1, kal_uint32 len1, kal_uint32 addr2, kal_uint32 len2)
{
   if(addr2>=addr1 && addr2<addr1+len1)
   {
      return KAL_TRUE;
   }
   if(addr1>=addr2 && addr1<addr2+len2)
   {
      return KAL_TRUE;
   }

   return KAL_FALSE;
}


/**********************************************************
Description : Called after flash driver is initialized. Do whatever check related to the flash
Input       : None
Output      : Status of the check
***********************************************************/
BL_FUNET_ERROR_CODE bl_CheckFlashDeviceStatus()
{

//NOR platform might not be block aligned
#ifdef _NAND_FLASH_BOOTING_

   kal_uint32 i;

   GFH_DL_PACKAGE_INFO_v2 *pPkgInfo = &pDl_Package_GFH->gfh_dl_package_info;
   for(i=0; i<sizeof(pPkgInfo->m_extra_info)/sizeof(pPkgInfo->m_extra_info[0]); i++)
   {
      if(pPkgInfo->m_extra_info[i].m_bin_type == GFH_FILE_NONE)
      {
         break;
      }

      if(bl_IsValidBinInfoItem(&pPkgInfo->m_extra_info[i]))
      {
         if(!bl_IsAddrOnBoundary(pPkgInfo->m_extra_info[i].m_bin_start_addr) ||
            !bl_IsAddrOnBoundary(pPkgInfo->m_extra_info[i].m_bin_start_addr + pPkgInfo->m_extra_info[i].m_bin_length) )
         {
            return BL_FUNET_ERROR_ADDRESS_OR_LENGTH_NOT_BLOCK_BOUNDARY;
         }
      }
   }
#endif

   return BL_FUNET_ERROR_NONE;
}

kal_bool bl_DL_SignatureVerify(kal_uint8 *pHash, kal_uint32 hash_len, kal_uint8 *sig, kal_uint32 sig_len)
{
   char sig_buf[32];

   bl_Alg_Asym_Decrypt((kal_uint32)sig_buf, (kal_uint32)sig, sig_len, (kal_uint32)custom_get_CDL_asymmetric_key(), custom_get_CDL_asymmetric_key_len());

   /* Compare the hash value */
   if (memcmp(pHash, sig_buf, hash_len) != 0)
   {
      return KAL_FALSE;
   }
   return KAL_TRUE;
}


void bl_DL_InitLCD()
{
// Raymond : LCD related code, mark it now and you can remove it if it is really unnecessary	
/*#if defined(__LCD_DRIVER_IN_BL__)

   if(!lcd_inited)
   {
      BL_PRINT(LOG_INFO, "Init LCD\n\r");
      BL_LCDHWInit();
      BL_ShowUpdateFirmwareInitBackground();
      BL_LCDSetBackLight();

      {
         DCL_HANDLE rtc_handler;
         DCL_HANDLE pw_handle;

         //before call dclpw, rtc is needed to be initialized
         rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
         DclRTC_Control(rtc_handler, RTC_CMD_SETXOSC, (DCL_CTRL_DATA_T *)NULL);
         DclRTC_Control(rtc_handler, RTC_CMD_HW_INIT, (DCL_CTRL_DATA_T *)NULL);
         DclRTC_Close(rtc_handler);

         //Use dclpw to latch the power
         pw_handle=DclPW_Open(DCL_PW, FLAGS_NONE);
         DclPW_Control(pw_handle,PW_CMD_POWERON,NULL);
         DclPW_Close(pw_handle);
      }

      lcd_inited = KAL_TRUE;

      //Re-init MSDC driver to reset GPIO ping
      bl_DL_Close();
      bl_DL_Open(DUMMY_FILENAME);
   }

#endif*/ /* __LCD_DRIVER_IN_BL__ */
}



BL_FUNET_ERROR_CODE bl_UpdateProgress(kal_uint32 phase, kal_uint32 progress)
{
// Raymond : LCD related code, mark it now and you can remove it if it is really unnecessary
/*
   //phase 0: initialzation, 10%
   //phase 1: verification,  30%
   //phase 2: upgrading,     50%
   //phase 3: finishing,     10%

   const kal_uint32 phasePortion[] = {10, 30, 50, 10};
   const kal_uint32 step = 1;

   static kal_uint32 lastProgress = 0;
   kal_uint32 totalProgress = 0;
   kal_uint32 i;

   ASSERT(phase<sizeof(phasePortion)/sizeof(*phasePortion) && progress<=100);

   for(i=0; i<phase; i++)
   {
      totalProgress += phasePortion[i];
   }
   totalProgress += progress*phasePortion[i]/100;

   WacthDogRestart();

   if(totalProgress >= lastProgress+step)
   {


#if defined(__LCD_DRIVER_IN_BL__)
      bl_DL_InitLCD();
      BL_ShowUpdateFirmwareProgress(totalProgress);
#endif // __LCD_DRIVER_IN_BL__ 
      lastProgress = totalProgress;
   }
*/

   return BL_FUNET_ERROR_NONE;
}

BL_FUNET_ERROR_CODE FTL_ERROR_TO_FUNET_ERROR(FTL_STATUS_CODE ftlErrorCode)
{
   switch(ftlErrorCode)
   {
   case FTL_SUCCESS:
   case FTL_ERROR_ECC_CORRECTED:
      return BL_FUNET_ERROR_NONE;

   case FTL_ERROR_READ_FAILURE:
      return BL_FUNET_ERROR_FLASH_READ;

   case FTL_ERROR_WRITE_FAILURE:
      return BL_FUNET_ERROR_FLASH_PROGRAM;

   case FTL_ERROR_ERASE_FAILURE:
      return BL_FUNET_ERROR_FLASH_ERASE;

   case FTL_ERROR_BAD_BLOCK:
      return BL_FUNET_ERROR_FLASH_BAD_BLOCK;

   }

   return BL_FUNET_ERROR_FLASH_OTHER_ERROR;
}


/*************************************************************************
 * Flash high level access utilities
 *************************************************************************/

STATIC FTL_STATUS_CODE bl_EraseAndMarkBad(kal_uint32 flashBlockIdx, FTL_OptParam *opt_param)
{
   FTL_STATUS_CODE status;

   status = g_ftlFuncTbl->FTL_CheckGoodBlock(flashBlockIdx, opt_param);

   if(status == FTL_ERROR_BAD_BLOCK)
   {
      BL_PRINT(LOG_DEBUG, "Bad block found before erasing @ %d%s\n\r", flashBlockIdx, (opt_param==NULL)?"":"(P)");
   }
   else
   {
      status = g_ftlFuncTbl->FTL_EraseBlock(flashBlockIdx, opt_param);

      if(status == FTL_ERROR_BAD_BLOCK)
      {
         g_ftlFuncTbl->FTL_MarkBadBlock(flashBlockIdx, opt_param);
         BL_PRINT(LOG_DEBUG, "Runtime bad block found after erasing @ %d%s\n\r", flashBlockIdx, (opt_param==NULL)?"":"(P)");
      }
   }

   return status;
}


/*************************************************************************
 * XIM high level access utilities
 *************************************************************************/

kal_int32 bl_GetImgIdx(GFH_FILE_TYPE bin_type)
{
   kal_uint32 i;
   for(i = 0; i < GFH_DL_PKG_EXTRA_INFO_COUNT; i++)
   {
      if(pDl_IOT_HEADER->m_extra_info[i].m_bin_type == bin_type)
      {
         return i;
      }
   }
   return -1;
}


STATIC kal_bool bl_IsValidBinInfoItem(GFH_DL_PACKAGE_EXTRA_INFO *pInfo)
{
   if( pInfo->m_bin_start_addr != INVALID_ADDR && pInfo->m_bin_length != INVALID_LEN )
   {
      return KAL_TRUE;
   }
   return KAL_FALSE;
}


/*This read function ignore DL_PACKAGE_GFH */
BL_FUNET_ERROR_CODE bl_ReadXIMPageX(kal_uint32 addr, kal_uint32 pageIdx, kal_uint32 page_count, kal_bool with_spare, kal_bool doHash)
{
   BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;
   kal_uint32 offset = pDl_Package_GFH->gfh_file_info.m_content_offset  + pageIdx*page_size_with_spare;
   kal_uint32 read = 0;

   if(bl_DL_Seek(offset, 0) != 0)
   {
      return BL_FUNET_ERROR_PACKAGE_SEEK_FAIL;
   }

   while(status == BL_FUNET_ERROR_NONE && read < page_count)
   {
      if(bl_DL_Read((kal_uint32*)addr, page_size_with_spare) != page_size_with_spare)
      {
         status = BL_FUNET_ERROR_PACKAGE_READ_FAIL;
      }

      if(status == BL_FUNET_ERROR_NONE && doHash)
      {
         bl_Alg_Hash_Append(addr, page_size_with_spare);
      }

      addr += (with_spare ? page_size_with_spare : page_size);
      read++;
   }

   return status;
}

BL_FUNET_ERROR_CODE bl_ReadXIMByte(kal_uint32 addr, kal_uint32 byteIdx, kal_uint32 byte_count, kal_bool doHash)
{
   BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;
   kal_uint32 offset = pDl_Package_GFH->gfh_file_info.m_content_offset  + byteIdx;
   kal_uint32 read = 0;

   if(bl_DL_Seek(offset, 0) != 0)
   {
      return BL_FUNET_ERROR_PACKAGE_SEEK_FAIL;
   }

    if(bl_DL_Read((kal_uint32*)addr, byte_count) != byte_count)
    {
       status = BL_FUNET_ERROR_PACKAGE_READ_FAIL;
    }
  
    if(status == BL_FUNET_ERROR_NONE && doHash)
    {
       bl_Alg_Hash_Append(addr, byte_count);
    }
  
   return status;
}



BL_FUNET_ERROR_CODE bl_ReadXIMPage(kal_uint32 addr, kal_uint32 pageIdx, kal_uint32 page_count, kal_bool doHash)
{
   return bl_ReadXIMPageX(addr, pageIdx, page_count, KAL_FALSE, doHash);
}

//Write one block from BIN body to flash, without spare, via DAL, auto-find good block
BL_FUNET_ERROR_CODE bl_WriteXimBlockToFlash(kal_uint32 ximBodyOffset, kal_uint32 flashBlockIdx, kal_uint32 *pWrittenBlockIdx, kal_uint32 *pinfo, kal_uint32 OffsetInImage)
{
   FTL_STATUS_CODE status = FTL_SUCCESS;
   kal_uint32 i;

   if( bl_DL_Seek(pDl_Package_GFH->gfh_file_info.m_content_offset + OffsetInImage, 0) != 0)
   {
      return BL_FUNET_ERROR_PACKAGE_SEEK_FAIL;
   }

   for(;; flashBlockIdx++)
   {
#if defined(__TRANSMISSION_DEBUG__)
      kal_uint32 crc = crc_init;
#endif /* defined (__TRANSMISSION_DEBUG__) */

#ifdef _NAND_FLASH_BOOTING_
      kal_uint32 pageToWrite = page_per_block;
#else
      kal_uint32 pageToWrite = g_ftlFuncTbl->FTL_GetBlockSize(flashBlockIdx, NULL) / g_ftlFuncTbl->FTL_GetPageSize();
#endif /* _NAND_FLASH_BOOTING_ */
      status = bl_EraseAndMarkBad(flashBlockIdx, NULL);

      if(status == FTL_ERROR_BAD_BLOCK)
      {
         continue;
      }

      for(i=0; status==FTL_SUCCESS && i<pageToWrite; i++)
      {
#if defined(__TRANSMISSION_DEBUG__)
         memset(page_buffer, TRANSMISSION_DBG_PATTERN, page_size_with_spare);
#endif /* defined (__TRANSMISSION_DEBUG__) */

         if(bl_DL_Read(page_buffer, page_size_with_spare) != page_size_with_spare)
         {
            return BL_FUNET_ERROR_PACKAGE_READ_FAIL;
         }

#if defined(__TRANSMISSION_DEBUG__)
         crc = Update_CRC(crc, (kal_uint8*)page_buffer, page_size);
#endif /* defined (__TRANSMISSION_DEBUG__) */


#ifdef __FOTA_DM__
#ifdef _NAND_FLASH_BOOTING_
         if(g_maui_image_info_validity != MTK_MAUI_HEAD_INFO_VALID)
         {
            SSF_SearchMAUIImageHead((kal_uint8*)page_buffer, page_size, NULL, 0);
         }
#endif
#endif

         status = g_ftlFuncTbl->FTL_WritePage(flashBlockIdx, i, page_buffer, NULL);

         
      }

      if(status != FTL_SUCCESS)
      {
         if(status != FTL_ERROR_BAD_BLOCK)
         {
            BL_PRINT(LOG_CRIT, "Unknown flash error!!!!! %d\n\r", status);
         }
         //skip this block and re-program
         status = g_ftlFuncTbl->FTL_MarkBadBlock(flashBlockIdx, NULL);
         continue;
      }

#if defined(__TRANSMISSION_DEBUG__)
      BL_PRINT(LOG_DEBUG, "(%x) ", crc);
#endif /* defined (__TRANSMISSION_DEBUG__) */

      //success
      break;
   }

   if(status == FTL_SUCCESS && pWrittenBlockIdx != NULL)
   {
      *pWrittenBlockIdx = flashBlockIdx;
   }

   return FTL_ERROR_TO_FUNET_ERROR(status);
}


//Get SVx specific information

void bl_getFATregion(kal_uint32 *buf, kal_uint32* fat_addr, kal_uint32* fat_len)
{
   GFH_FLASH_INFO_v1 *pFlashInfo;
   kal_uint32 addr, len;

   *fat_addr = 0;
   *fat_len = 0;

   if(GFH_Find((U32)buf, GFH_FLASH_INFO, (void **)&pFlashInfo) == B_OK)
   {
      //The index of m_flash_info: 0-NOR, 1-NAND, 2-EMMC
      addr = pFlashInfo->m_flash_info[pDl_Package_GFH->gfh_dl_package_info.m_im_device].m_fat_begin_addr;
      len = pFlashInfo->m_flash_info[pDl_Package_GFH->gfh_dl_package_info.m_im_device].m_fat_length;

      if(len!=0 && len!=INVALID_LEN && addr!=0 && addr!=INVALID_ADDR)
      {
         *fat_addr = addr;
         *fat_len = len;
      }
   }
}

void bl_getSDSregion(kal_uint32 *buf, kal_uint32* sds_addr, kal_uint32* sds_len)
{
   GFH_MAUI_INFO_v1 *pMauiInfo;
   kal_uint32 addr, len;

   *sds_addr = 0;
   *sds_len = 0;

   if(GFH_Find((U32)buf, GFH_MAUI_INFO, (void **)&pMauiInfo) == B_OK)
   {

      addr = pMauiInfo->m_sds_base_addr;
      len = pMauiInfo->m_sds_len;

      if(len!=0 && len!=INVALID_LEN && addr!=0 && addr!=INVALID_ADDR)
      {
         *sds_addr = addr;
         *sds_len = len;
      }
   }
}


/*************************************************************************
 * Image updaters
 *************************************************************************/
#ifdef _NAND_FLASH_BOOTING_

kal_uint32 bl_GetSpareSize(kal_uint32 page_size)
{
   return page_size/32;
}

Nand_Update_Area_ST *bl_FUNET_NewSpaceInfo(kal_uint32 n)
{
   if (n < 10)
      return &(pSpaceInfo->m_image_space[n]);
   else
      return &(pSpaceInfo->m_image_ext_space[n-10]);
}

STATIC kal_bool bl_isFSImageRecord(DL_PACKAGE_NAND_IMAGE_HEADER_IMG_RECORD *pImage)
{
   return (pImage->feature_bit & FS_IMAGE_MASK) ? KAL_TRUE : KAL_FALSE;
}

STATIC kal_bool bl_isENFBImage(DL_PACKAGE_NAND_IMAGE_HEADER_IMG_RECORD *pImage)
{
   return (pImage->feature_bit & ENFB_MASK) ? KAL_TRUE : KAL_FALSE;
}

STATIC kal_bool bl_isRSImage(DL_PACKAGE_NAND_IMAGE_HEADER_IMG_RECORD *pImage)
{
   return (pImage->feature_bit & RS_IMAGE_MASK) ? KAL_TRUE : KAL_FALSE;
}

STATIC kal_bool bl_isPImage(DL_PACKAGE_NAND_IMAGE_HEADER_IMG_RECORD *pImage)
{
   return (pImage->feature_bit & P_IMAGE_MASK) ? KAL_TRUE : KAL_FALSE;
}

STATIC kal_bool bl_isFOTAReservoir(DL_PACKAGE_NAND_IMAGE_HEADER_IMG_RECORD *pImage)
{
   return (pImage->feature_bit & U_MASK) ? KAL_TRUE : KAL_FALSE;   
}

STATIC kal_bool bl_isFOTABackupSpace(DL_PACKAGE_NAND_IMAGE_HEADER_IMG_RECORD *pImage)
{
   return (pImage->feature_bit & B_MASK) ? KAL_TRUE : KAL_FALSE;   
}


//Write 3rd MAP block to flash, without spare, via DAL, auto-find good block
BL_FUNET_ERROR_CODE bl_Write3rdROMBlockToNand(kal_uint32 *p3rdROMMapTbl, kal_uint32 size, kal_uint32 flashBlockIdx, kal_uint32 *pWrittenBlockIdx)
{
   FTL_STATUS_CODE status = FTL_SUCCESS;
   kal_uint32 i;

   for(;; flashBlockIdx++)
   {
      kal_uint8 *p = (kal_uint8*)p3rdROMMapTbl;
      kal_uint32 toWrite = size;

      status = bl_EraseAndMarkBad(flashBlockIdx, NULL);

      if(status == FTL_ERROR_BAD_BLOCK)
      {
         continue;
      }

      for(i=0; status==FTL_SUCCESS && i<page_per_block; i++)
      {
         memset(page_buffer, INVALID_1B_CONTENT, page_size);

         if(toWrite)
         {
            kal_uint32 n = MIN(page_size, toWrite);
            memcpy(page_buffer, p, n);
            toWrite -= n;
            p += n;
         }

         status = g_ftlFuncTbl->FTL_WritePage(flashBlockIdx, i, page_buffer, NULL);
      }

      if(status != FTL_SUCCESS)
      {
         if(status != FTL_ERROR_BAD_BLOCK)
         {
            BL_PRINT(LOG_CRIT, "Unknown Flash error!!!!! %d\n\r", status);
         }
         //skip this block and re-program
         status = g_ftlFuncTbl->FTL_MarkBadBlock(flashBlockIdx, NULL);
         continue;
      }

      //success
      break;
   }

   if(status == FTL_SUCCESS && pWrittenBlockIdx != NULL)
   {
      *pWrittenBlockIdx = flashBlockIdx;
   }

   return FTL_ERROR_TO_FUNET_ERROR(status);
}


/***************************************************************************//**
 * @brief The function for read data from flash
 * 
 * This function is used for readout data from flash and store data into ram
 *
 * @param[in] buf_ptr    The buffer pointer for storing data onto ram.
 * @param[in] BlkNo       The block number on flash to be read out. (read start position)
 * @param[in] length      The length to be read out
 * @param[in] bDAL
 *
 * @return  BL_FUNET_ERROR_CODE
 *
 ******************************************************************************/
BL_FUNET_ERROR_CODE bl_ReadDataFromFlash(kal_uint32 *buf_ptr, kal_uint32 BlkNo, kal_int32 length, FTL_OptParam *opt_param)
{
   kal_uint32  pageNo = 0;
   kal_uint32  page_size = g_ftlFuncTbl->FTL_GetPageSize();
   //kal_uint32  page_per_block = g_ftlFuncTbl->FTL_GetBlockSize(0, KAL_FALSE)/page_size;
   kal_bool    goodBlockChecked = KAL_FALSE;

   if(length == 0)
   {
      return BL_FUNET_ERROR_NONE;
   }   

   while(length>0)
   { 
      if(!goodBlockChecked)
      {
         while( g_ftlFuncTbl->FTL_CheckGoodBlock(BlkNo, opt_param) == FTL_ERROR_BAD_BLOCK )
         {
            /* Skip the bad block */
            BL_PRINT(LOG_INFO, "\n\rBad block at block %d\n\r", BlkNo);
            
            BlkNo++;
         }

         goodBlockChecked = KAL_TRUE;
      }

      if(length >= page_size)
      {
         if( g_ftlFuncTbl->FTL_ReadPage(BlkNo, pageNo, buf_ptr, opt_param) != FTL_SUCCESS )
         {
            BL_PRINT(LOG_CRIT, "Read error at block %d, page %d\n\r", BlkNo, pageNo);
            return BL_FUNET_ERROR_FLASH_READ;
         }

         pageNo++;
         length -= page_size;
         (kal_uint32)buf_ptr += page_size;
      }
      else
      {
         if( g_ftlFuncTbl->FTL_ReadPage(BlkNo, pageNo, page_buffer, opt_param) != FTL_SUCCESS )
         {
            BL_PRINT(LOG_CRIT, "Read error at block %d, page %d\n\r", BlkNo, pageNo);
            return BL_FUNET_ERROR_FLASH_READ;
         }

         memcpy(buf_ptr,page_buffer,length);

         pageNo++;
         length = 0;
         (kal_uint32)buf_ptr += length;
      }

      ASSERT(length>=0);

      /* Looking for the next good block */
      if (pageNo == page_per_block)
      {
         BlkNo++;
         pageNo = 0;
         goodBlockChecked = KAL_FALSE;

         WacthDogRestart();
         BL_PRINT(LOG_INFO, ".");       
      }
   }

   return BL_FUNET_ERROR_NONE;
}


BL_FUNET_ERROR_CODE bl_DoUpdateMiscImg(kal_uint32 *pFlashBlockIdx, kal_uint32 imageIdx)
{
   BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;
   DL_PACKAGE_NAND_IMAGE_HEADER_IMG_RECORD *pImage = pMAUIImage+imageIdx;
   kal_uint32 i;
   kal_uint32 flash_max_block_num = 0;


   //Partial update only updates the resource bins, which are not manipulate here.
   if(codePartialUpdate == KAL_TRUE)
   {
      return status;
   }

   //Currently, bl_DoUpdateMiscImg only process FOTAReservoir and FOTABackupSpace
   if(!bl_isFOTAReservoir(pImage) && !bl_isFOTABackupSpace(pImage))
   {
      return status;
   }

   BL_PRINT(LOG_DEBUG, "=>Erase data from xim=%d->%d: ", pImage->start_block, pImage->start_block+pImage->blocks-1);

   for(i=0; i<pImage->blocks; i++)
   {
      BL_PRINT(LOG_DEBUG, "%d->%d, ", pImage->start_block+i, *pFlashBlockIdx);

      //Do not need to take care the bad block here. So simply erase as many blocks as described in  pImage->blocks
      bl_EraseAndMarkBad(*pFlashBlockIdx, NULL);

      bl_UpdateProgress(UPDATE_PHASE, ((pImage->start_block+i)*page_per_block*100/(im_file_size/page_size_with_spare)));

      //Update the SpaceInfo for FOTA information
      if(i == 0)
      {
         if(pSpaceInfo)
         {
            if(bl_isFOTAReservoir(pImage))
            {
               pSpaceInfo->m_package_start = *pFlashBlockIdx;
            }
            if(bl_isFOTABackupSpace(pImage))
            {
               pSpaceInfo->m_backup_start= *pFlashBlockIdx;
            }
         }
      }

      (*pFlashBlockIdx)++;
   }
   BL_PRINT(LOG_DEBUG, "done\n\r");

   if(pSpaceInfo)
   {
      if(bl_isFOTAReservoir(pImage))
      {
         pSpaceInfo->m_package_last = *pFlashBlockIdx-1;  
      }
      if(bl_isFOTABackupSpace(pImage))
      {
         pSpaceInfo->m_backup_last = *pFlashBlockIdx-1;
      }
   }

   return status;
}


BL_FUNET_ERROR_CODE bl_DoUpdateMAUI(kal_uint32 *pFlashBlockIdx, kal_uint32 imageIdx)
{
   BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;
   DL_PACKAGE_NAND_IMAGE_HEADER_IMG_RECORD *pImage = pMAUIImage+imageIdx;
   kal_uint32 i;
   kal_uint32 flash_max_block_num = 0;
   kal_uint32 flash_bound_block = pImage->max_block ? (*pFlashBlockIdx + pImage->max_block -1) : INVALID_BLOCK_IDX;
   kal_uint32 FlashLayoutid = GetFlashLayoutidByNANDimgid(imageIdx);
   kal_uint32 *pRemapTbl = bl_isENFBImage(pImage) ? ((kal_uint32*)remap_tbl) : NULL;
   kal_uint32 pBootCertData = NULL;

   //Make sure the max_block is valid when it is fixed layout, except BootCert
   if((ximFixedLayout == KAL_TRUE) && (pBootCertData == NULL))
   {
      if(pImage->max_block == 0)
      {         
         return BL_FUNET_ERROR_INVALID_XIM_IMG_MAX_BLOCK_NUMBER;
      }
   }

   if(codePartialUpdate == KAL_TRUE)
   {
      //The new max block number must not be larger than original when doing partial update 
      flash_max_block_num = (flash_layout_info.region[FlashLayoutid].u.nandEmmc.boundPage + 1 -
                        flash_layout_info.region[FlashLayoutid].u.nandEmmc.startPage)/page_per_block;
      if((flash_max_block_num < pImage->max_block) || (pImage->max_block < pImage->blocks))
      {
         return BL_FUNET_ERROR_XIM_IMG_SIZE_EXCEED_MAX_VALUE;
      }

      //The start block should use the original flash_layout_info
      *pFlashBlockIdx = flash_layout_info.region[FlashLayoutid].u.nandEmmc.startPage/page_per_block;

      //The boundary block shoud keep the same as original while doing partial update.
      flash_bound_block = flash_layout_info.region[FlashLayoutid].u.nandEmmc.boundPage/page_per_block;
   } 

   if(pImage->blocks*4 > sizeof(remap_tbl))
   {
      BL_PRINT(LOG_ERROR, "Block count=%d, large then %d\n\r", pImage->blocks, sizeof(remap_tbl)/4);
      return BL_FUNET_ERROR_3RDROM_REMAP_TBL_TOO_SMALL;
   }

   if(pRemapTbl)
   {
      //Skip the first block for 3rd ROM. NAND XIM always put the mapping table at the first block.
      //But new rule is to put it at last. So skip first block in XIM's 3rd ROM, and write the table after all 3rd ROM data are written.
      pImage->start_block++;
      pImage->blocks--;
   }

   BL_PRINT(LOG_DEBUG, "=>Writing data from xim=%d->%d: ", pImage->start_block, pImage->start_block+pImage->blocks-1);

   for(i=0; i<pImage->blocks; i++)
   {
      kal_uint32 origBlock = *pFlashBlockIdx;
      BL_PRINT(LOG_DEBUG, "%d->%d, ", pImage->start_block+i, *pFlashBlockIdx);

      status = bl_WriteXimBlockToFlash((pImage->start_block+i)*block_size_with_spare, *pFlashBlockIdx, pFlashBlockIdx, NULL, i*block_size);

      if(origBlock != *pFlashBlockIdx && status == BL_FUNET_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "%d->%d, ", pImage->start_block+i, *pFlashBlockIdx);
      }

      if(status != BL_FUNET_ERROR_NONE)
      {
         BL_PRINT(LOG_ERROR, "Error when writing block %d, status%d\n\r", *pFlashBlockIdx, status);
         return status;
      }

      bl_UpdateProgress(UPDATE_PHASE, ((pImage->start_block+i)*page_per_block*100/(im_file_size/page_size_with_spare)));

      if(*pFlashBlockIdx > flash_bound_block)
      {
         BL_PRINT(LOG_ERROR, "Maximum block exceeds, max=%d\n\r", flash_bound_block);
         return BL_FUNET_ERROR_OVER_RESERVED_BOUNDARY;
      }

      //Update the flash layout and space info when first block is successfully written.
      //Do not update them when doing partial update.
      //Note that we keep the flexity that the image boundary can be changed while doing full update.
      if((i == 0)  && (codePartialUpdate == KAL_FALSE))
      {
         flash_layout_info.region[FlashLayoutid].u.nandEmmc.startPage = (*pFlashBlockIdx)*page_per_block;

         if(pSpaceInfo)
         {
            bl_FUNET_NewSpaceInfo(FlashLayoutid)->m_image_start = *pFlashBlockIdx;
         }
      }

      //Update 3rd ROM remap block if necessary
      if(pRemapTbl)
      {
         pRemapTbl[i] = *pFlashBlockIdx;
      }

      (*pFlashBlockIdx)++;
   }
   BL_PRINT(LOG_DEBUG, "done\n\r");

   //If it is 3RD ROM, append its remapping table
   if(pRemapTbl)
   {
      BL_PRINT(LOG_DEBUG, "=>Write 3rd ROM remap block @ %d...", *pFlashBlockIdx);
      if( bl_Write3rdROMBlockToNand(pRemapTbl, pImage->blocks*4, *pFlashBlockIdx, pFlashBlockIdx) != BL_FUNET_ERROR_NONE)
      {
         return BL_FUNET_ERROR_3RDROM_REMAP_TBL_WRITE_FAILURE;
      }
      BL_PRINT(LOG_DEBUG, " done @ %d\n\r", *pFlashBlockIdx);

      (*pFlashBlockIdx)++;
   }
   
   //Update the last block in space info
   if(pSpaceInfo)
   {
      bl_FUNET_NewSpaceInfo(FlashLayoutid)->m_image_last = *pFlashBlockIdx-1;

      //Do not update pSpaceInfo boundary when doing partial update.
      //Note that we keep the flexity that the image boundary can be changed while doing full update.
      if(codePartialUpdate == KAL_FALSE)
      {
         if(flash_bound_block != INVALID_BLOCK_IDX)
         {
            bl_FUNET_NewSpaceInfo(FlashLayoutid)->m_image_end = flash_bound_block;
         }
         else
         {
            bl_FUNET_NewSpaceInfo(FlashLayoutid)->m_image_end = *pFlashBlockIdx-1;
         }
      }
   }

   //Do not update flash layout when doing partial update.
   //Note that we keep the flexity that the image boundary can be changed while doing full update.
   if(codePartialUpdate == KAL_FALSE)
   {
      if(flash_bound_block != INVALID_BLOCK_IDX)
      {
         flash_layout_info.region[FlashLayoutid].u.nandEmmc.boundPage = ((flash_bound_block+1)*page_per_block)-1;
      }
      else
      {
         flash_layout_info.region[FlashLayoutid].u.nandEmmc.boundPage = ((*pFlashBlockIdx)*page_per_block)-1;
      }
   }

   //Erase unused space if max block is specified
   if(flash_bound_block != INVALID_BLOCK_IDX)
   {
      BL_PRINT(LOG_DEBUG, "=>Erase block for reserved space:");
      for(;*pFlashBlockIdx <= flash_bound_block; (*pFlashBlockIdx)++)
      {
         BL_PRINT(LOG_DEBUG, "%d ", *pFlashBlockIdx);
         bl_EraseAndMarkBad(*pFlashBlockIdx, NULL);
      }
      BL_PRINT(LOG_DEBUG, "done\n\r");
   }

   return BL_FUNET_ERROR_NONE;
}


BL_FUNET_ERROR_CODE bl_DoUpdate()
{
   kal_uint32 i;
   BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;  
   kal_uint32 flashImgIdx = 0; //For record the processed image index on flash
   kal_uint32 ExtraInfoid;
   DL_PACKAGE_NAND_IMAGE_HEADER_IMG_RECORD *pImage;

   //All image listed in v5 img layout could be updated, thus use the index start from 0 to get the start block
   kal_uint32 flashBlockIdx = (BL_Shared_info.m_bl_flash_layout.region[0].u.nandEmmc.startPage)/page_per_block;

   //i is the nand xim image id
   for(i=0; i<image_count; i++)
   {
      if(i < XIM_MAUI_IDX) //Bootloader and CBR are not updateable here
      {
         continue;
      }

      if(GetFlashLayoutidByNANDimgid(i) < flash_layout_info.regionCount)
      {
         //Here only process the nand img idx which can be mapped to flash_layout or extra_info.
         //All valid operation combination should be checked in bl_ExtraInfoCheck()
         //The philosophy here is to simply believe the operation is correct
         
         if(pDl_Package_GFH->gfh_dl_package_info.m_extra_info[GetExtraInfoidByNANDimgid(i)].m_operation == IM_DOWNLOAD)
         {
            BL_PRINT(LOG_INFO, "Updating MAUI %d @ block %d\n\r", i, flashBlockIdx);
      
            status = bl_DoUpdateMAUI(&flashBlockIdx, i);
               
            if(status != BL_FUNET_ERROR_NONE)
            {
                return status;
            }
            BL_PRINT(LOG_INFO, "Update of MAUI %d done\n\r\n\r", i);
         }
      }
      else
      {
         //Some nand img might not be able to map to flash layout. Process these img here.
      
         BL_PRINT(LOG_INFO, "Updating Misc Img %d @ block %d\n\r", i, flashBlockIdx);
      
         status = bl_DoUpdateMiscImg(&flashBlockIdx, i);

         if(status != BL_FUNET_ERROR_NONE)
         {
             return status;
         }
         BL_PRINT(LOG_INFO, "Update of Misc Img %d done\n\r\n\r", i);
      }
   }

   //handle the filesystem
   /*if(status == BL_FUNET_ERROR_NONE)
   {
      status = bl_ProcessFilesystem(flashBlockIdx);
   }*/

   return status;
}


#else /* _NAND_FLASH_BOOTING_ */

/***************************************************************************//**
 * @brief The function is for partially updating NOR block from XIM data
 * 
 * This function will readout the unchanged part in flash block to a buffer, then copy the data in
 * card into such buffer. At the end, write the buffer back to the flash block to finish the NOR
 * partial update.
 *
 * @param[in] update_start_addr  The start address in flash to be updated
 * @param[in] length                      The length to be readout in the card's block
 * @param[in] op                            The operation to be proccesed, it could be IM_DOWNLOAD or IM_ERASE
 *
 * @return  BL_FUNET_ERROR_CODE
 *
 ******************************************************************************/
BL_FUNET_ERROR_CODE bl_WriteBINToPartialFlashBlock(kal_uint32 update_start_addr, kal_uint32 length, IM_OPERATION op, kal_uint32 *pinfo, kal_uint32 OffsetInImage)
{ 
   kal_uint32 status;
   kal_uint32 blk_start_addr, blk_end_addr, start_offset, end_offset;
   kal_uint32 bakbuf = (kal_uint32)&Image$$EXT_READ_WRITE$$ZI$$Limit;
   kal_uint32 flash_blk_idx = bl_AddrToBlockIdx(update_start_addr, NULL);
   kal_uint32 flash_page_idx;
   kal_uint32 update_end_addr = update_start_addr + length;
   kal_uint32 blksize = g_ftlFuncTbl->FTL_GetBlockSize(flash_blk_idx, NULL);
   kal_uint32 *bufptr;

   //Get blk_start_addr
   status = g_ftlFuncTbl->FTL_BlockPageToAddr(flash_blk_idx, 0, &blk_start_addr, NULL);
   
   //Get blk_end_addr
   blk_end_addr = blk_start_addr + blksize;

   //Check the pre-request: the updated region can not cross other block
   ASSERT(update_end_addr<=(blk_start_addr+blksize));

   //Calculate the offset
   start_offset = update_start_addr - blk_start_addr;
   end_offset = update_end_addr - blk_start_addr;

   //--Build the updated block data: --
   //1.Prepare the upper part (original part)
   //The input address is got from card, it is not remapped, thus here need to remap it if necessary
   memcpy((kal_uint32*)bakbuf, (kal_uint32*)(blk_start_addr|ROM_ADDR_MASK), start_offset);  
   
   //2.Prepare the bottom part (original part)
   //The input address is got from card, it is not remapped, thus here need to remap it if necessary
   memcpy((kal_uint32*)(bakbuf+end_offset), (kal_uint32*)(update_end_addr|ROM_ADDR_MASK), blk_end_addr-update_end_addr);
   
   //3.Prepare the middle part (updated part)
   //Note that there is no spare region in NOR, thus here skip the relatied processing to simlify the flow.
   if( bl_DL_Seek(pDl_Package_GFH->gfh_file_info.m_content_offset + OffsetInImage, 0) != 0)
   {
      return BL_FUNET_ERROR_PACKAGE_SEEK_FAIL;
   }
   if(op == IM_DOWNLOAD)
   {
      if(bl_DL_Read((kal_uint32*)(bakbuf+start_offset), length)!= length)
      {
         return BL_FUNET_ERROR_PACKAGE_READ_FAIL;
      }
   }
   else if(op == IM_ERASE)
   {
      memset((kal_uint32*)(bakbuf+start_offset), (kal_int32)INVALID_4B_CONTENT, length);
   }
   //--The updated block data had been built --

   //Erase flash block
   if(bl_EraseAndMarkBad(flash_blk_idx, NULL) == FTL_ERROR_BAD_BLOCK)
   {
      return BL_FUNET_ERROR_FLASH_BAD_BLOCK;
   }

   //Write bakbuf to flash block
   flash_page_idx = 0;
   for(bufptr = (kal_uint32*)bakbuf; (kal_uint32)bufptr < bakbuf + blksize; (kal_uint32)bufptr += page_size)
   {
      status = g_ftlFuncTbl->FTL_WritePage(flash_blk_idx, flash_page_idx, bufptr, NULL);

      if(status != FTL_SUCCESS)
      {
         return BL_FUNET_ERROR_FLASH_PROGRAM;
      }
      
      flash_page_idx++;
   }

   ASSERT(blksize==flash_page_idx*page_size);

   return BL_FUNET_ERROR_NONE;

}

/***************************************************************************//**
 * @brief The function is for partially updating NOR block with given data
 * 
 * This function will readout the unchanged part in flash block to a buffer, then copy the data in
 * card into such buffer. At the end, write the buffer back to the flash block to finish the NOR
 * partial update.
 *
 * @param[in] update_start_addr  The start address in flash to be updated
 * @param[in] length                      The length to be readout in the card's block
 * @param[in] src_data_addr         The source data address to be write on to flash
 *
 * @return  BL_FUNET_ERROR_CODE
 *
 ******************************************************************************/
BL_FUNET_ERROR_CODE bl_PartialUpdateNORblock(kal_uint32 update_start_addr, kal_uint32 length, kal_uint32 src_data_addr)
{ 
   kal_uint32 status;
   kal_uint32 blk_start_addr, blk_end_addr, start_offset, end_offset;
   kal_uint32 bakbuf = (kal_uint32)&Image$$EXT_READ_WRITE$$ZI$$Limit;
   kal_uint32 flash_blk_idx = bl_AddrToBlockIdx(update_start_addr, NULL);
   kal_uint32 flash_page_idx;
   kal_uint32 update_end_addr = update_start_addr + length;
   kal_uint32 blksize = g_ftlFuncTbl->FTL_GetBlockSize(flash_blk_idx, NULL);
   kal_uint32 *bufptr;

   //Get blk_start_addr
   status = g_ftlFuncTbl->FTL_BlockPageToAddr(flash_blk_idx, 0, &blk_start_addr, NULL);
   
   //Get blk_end_addr
   blk_end_addr = blk_start_addr + blksize;

   //Check the pre-request: the updated region can not cross other block
   ASSERT(update_end_addr<=(blk_start_addr+blksize));

   //Calculate the offset
   start_offset = update_start_addr - blk_start_addr;
   end_offset = update_end_addr - blk_start_addr;

   //--Build the updated block data: --
   //1.Prepare the upper part (original part)
   memcpy((kal_uint32*)bakbuf, (kal_uint32*)blk_start_addr, start_offset);  
   
   //2.Prepare the bottom part (original part)
   memcpy((kal_uint32*)(bakbuf+end_offset), (kal_uint32*)update_end_addr, blk_end_addr-update_end_addr);
   
   //3.Prepare the middle part (updated part)
   memcpy((kal_uint32*)(bakbuf+start_offset), (kal_uint32*)src_data_addr, length); 
   //--The updated block data had been built --

   //Erase flash block
   if(bl_EraseAndMarkBad(flash_blk_idx, NULL) == FTL_ERROR_BAD_BLOCK)
   {
      return BL_FUNET_ERROR_FLASH_BAD_BLOCK;
   }

   //Write bakbuf to flash block
   flash_page_idx = 0;
   for(bufptr = (kal_uint32*)bakbuf; (kal_uint32)bufptr < bakbuf + blksize; (kal_uint32)bufptr += page_size)
   {
      status = g_ftlFuncTbl->FTL_WritePage(flash_blk_idx, flash_page_idx, bufptr, NULL);

      if(status != FTL_SUCCESS)
      {
         return BL_FUNET_ERROR_FLASH_PROGRAM;
      }
      
      flash_page_idx++;
   }

   ASSERT(blksize==flash_page_idx*page_size);

   return BL_FUNET_ERROR_NONE;

}


BL_FUNET_ERROR_CODE bl_DoUpdateMAUI(kal_uint32 addr, kal_uint32 length, IM_OPERATION op, kal_int32 bin_offset, kal_uint32* pInfo)
{
   BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;
   kal_uint32 i;
   kal_uint32 flashBlockIdx = bl_AddrToBlockIdx(addr, NULL);
   kal_uint32 blockEnd      = bl_AddrToBlockIdx(addr+length-1, NULL);
   kal_uint32 addrEnd       = addr + length;
   kal_uint32 partialUpdateStart, partialUpdateEnd, updatingLength;
   kal_uint32 partialUpdateFlag = KAL_FALSE;
   kal_uint32 p = addr;

   ASSERT(op == IM_DOWNLOAD || op == IM_ERASE);

   BL_PRINT(LOG_DEBUG, "=>Writing data from xim=%d->%d (0x%x~0x%x): ", flashBlockIdx, blockEnd, addr, addr+length);

   for(; flashBlockIdx<=blockEnd; flashBlockIdx++)
   {
      kal_uint32 origBlock = flashBlockIdx;

      //In MBA case, the start address of image might not align block size. Manipulate it here.
      partialUpdateFlag = KAL_FALSE;

      //Check if the first flash block need partial update
      if((p==addr) && (!bl_IsAddrOnBoundary(p)))
      {
         partialUpdateStart = addr;
         partialUpdateFlag = KAL_TRUE;
      }
      else
      {
         partialUpdateStart = p;
      }
      //Check if the last flash block need partial update
      if((flashBlockIdx==blockEnd) && (!bl_IsAddrOnBoundary(addrEnd)))
      {
         partialUpdateEnd = addrEnd;
         partialUpdateFlag = KAL_TRUE;
      }
      else
      {
         //Set partialUpdateEnd to the end of this block
         g_ftlFuncTbl->FTL_BlockPageToAddr(flashBlockIdx+1, 0, &partialUpdateEnd, NULL);
      }
      
      //Do partial update if needed
      if(partialUpdateFlag)
      {
         if(flashBlockIdx == mauiFirstBlock && flashBlockIdx == mauiFirstBlock+1)
         {  //The first block of maui image must be block aligned
            return BL_FUNET_ERROR_ADDRESS_OR_LENGTH_NOT_BLOCK_BOUNDARY;
         }
      
         updatingLength = partialUpdateEnd - partialUpdateStart;

         BL_PRINT(LOG_DEBUG, "%d(0x%x-0x%x), ", flashBlockIdx, partialUpdateStart, partialUpdateEnd);
         
         status = bl_WriteBINToPartialFlashBlock(partialUpdateStart, updatingLength, op, pInfo, bin_offset);

         bin_offset +=updatingLength;
         
         p += updatingLength;
      }
      else
      {

            if(op == IM_DOWNLOAD)
            {
               BL_PRINT(LOG_DEBUG, "%d(0x%x), ", flashBlockIdx, p);

               status = bl_WriteXimBlockToFlash(p, flashBlockIdx, &flashBlockIdx, pInfo, bin_offset);

               if(origBlock != flashBlockIdx && status == BL_FUNET_ERROR_NONE)
               {
                  //Impossible: There should not be bad blocks in NOR flash...
                  ASSERT(0);
               }
            }
            else if(op == IM_ERASE)
            {
               BL_PRINT(LOG_DEBUG, "E %d(0x%x), ", flashBlockIdx, p);

               bl_EraseAndMarkBad(flashBlockIdx, NULL);

               status = BL_FUNET_ERROR_NONE;
            }            

         bin_offset += g_ftlFuncTbl->FTL_GetBlockSize(flashBlockIdx, NULL);
         
         p += g_ftlFuncTbl->FTL_GetBlockSize(flashBlockIdx, NULL);
      }

      if(status != BL_FUNET_ERROR_NONE)
      {
         BL_PRINT(LOG_ERROR, "Error when processing block %d, status%d\n\r", flashBlockIdx, status);
         return status;
      }

      bl_UpdateProgress(UPDATE_PHASE, p*100/im_file_size);
      
   }

   BL_PRINT(LOG_DEBUG, "done\n\r");

   return BL_FUNET_ERROR_NONE;
}


BL_FUNET_ERROR_CODE bl_DoUpdate()
{
   BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;
   kal_uint32 i;
   kal_uint32* pInfo;
   GFH_FILE_TYPE binType;

   //Find the first MAUI binary starting address
   for(i=0; status == BL_FUNET_ERROR_NONE && i<GFH_DL_PKG_EXTRA_INFO_COUNT; i++)
   {
      if(pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_type == GFH_FILE_NONE)
      {
         break;
      }

      pInfo = NULL;


      if( bl_IsValidBinInfoItem(&pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i]) )
      {
         binType = pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_type;

         if((!codePartialUpdate) || (!ximFixedLayout))
         {  //MAUI will be only updated in full update
            if( ( binType >= V_MAUI_BINARY &&
                  binType <  V_MAUI_BINARY_END) ||
                 (binType == FOTA_UE))
            {              
               status = bl_DoUpdateMAUI(pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_start_addr,
                                        pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_length,
                                        pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_operation,
                                        pDl_IOT_HEADER->m_extra_info[bl_GetImgIdx(binType)].m_bin_offset,
                                        pInfo);
            }         
         }

         //When MBA is on, scatter file will ensure each bin file is block aligned.
         //Thus we do not need to consider the case that one page has the data from two bin.
         if( binType >= V_RESOURCE_BINARY &&
             binType <  V_RESOURCE_BINARY_END)
         {
            status = bl_DoUpdateMAUI(pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_start_addr,
                                     pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_length,
                                     pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_operation,
                                     pDl_IOT_HEADER->m_extra_info[bl_GetImgIdx(binType)].m_bin_offset,
                                     NULL);
         }      
      }
   }

   return status;
}

#endif /* _NAND_FLASH_BOOTING_ */

/*************************************************************************
 * update markers
 *************************************************************************/
#ifdef _NAND_FLASH_BOOTING_

BL_FUNET_ERROR_CODE bl_UpdateImageInfo(void)
{
   //Calculate the checksum in space info
   if(pSpaceInfo)
   {
      kal_uint32 checksum = 0;
      kal_uint32 *p = (kal_uint32*)pSpaceInfo;

      for(; p <(kal_uint32*)(&pSpaceInfo->m_image_space_chksum); p++)
      {
         checksum += *p;
      }

      pSpaceInfo->m_image_space_chksum = checksum;
   }

   if(CBR_WriteRecord(E_CBR_IDX_CBR, CBR_RECORD_FLASH_LAYOUT, (kal_uint8 *)&flash_layout_info, sizeof(FlashLayout), NULL) != CBR_SUCCESS)
   {
      return BL_FUNET_ERROR_FAIL_TO_WRITE_CBR_IMAGE_INFO;
   }

   if(CBR_WriteRecord(E_CBR_IDX_CBR, CBR_RECORD_FLASH_SPACE_INFO, (kal_uint8 *)&space_info, sizeof(Nand_ImageSpace_ST), NULL) != CBR_SUCCESS)
   {
      return BL_FUNET_ERROR_FAIL_TO_WRITE_CBR_SPACE_INFO;
   }
   
   if(CBR_WriteRecord(E_CBR_IDX_CBR, CBR_RECORD_MAUI_INFO, (kal_uint8 *)pMauiInfoInCard, sizeof(GFH_MAUI_INFO_v1), NULL) != CBR_SUCCESS)
   {
      BL_PRINT(LOG_INFO, "Note: Could not write maui info to CBR\n\r");
   }

   return BL_FUNET_ERROR_NONE;
}

#else /* _NAND_FLASH_BOOTING_ */

STATIC kal_bool bl_IsMarkerFound(kal_uint32 mauiAddr)
{
   kal_uint32 i;
   kal_uint32 blockIdx;
   kal_uint32 markerAddr;

   g_ftlFuncTbl->FTL_Init(NULL);

   blockIdx = bl_AddrToBlockIdx(mauiAddr, NULL);

   markerAddr = mauiAddr + g_ftlFuncTbl->FTL_GetBlockSize(blockIdx, NULL);

   for(i=0; i<page_size/4; i++)
   {
      if(*((kal_uint32*)(markerAddr)+i) != FUNET_MARKER)
      {
         return KAL_FALSE;

      }
   }

   return KAL_TRUE;
}

BL_FUNET_ERROR_CODE bl_MarkCDL(kal_uint32 mauiAddr)
{
   FTL_STATUS_CODE status;
   kal_uint32 i;

   ASSERT(mauiAddr < MAUI_ROM_START_ADDR - BOOTLOADER_ROM_REGION_LEN + custom_get_NORFLASH_Size());

   mauiFirstBlock = bl_AddrToBlockIdx(mauiAddr, NULL);

   //If last FUNET is fail, we should not do the backup again. Because we might loss power during
   //updating the maui info block.
   if(last_funet_fail_flag == KAL_FALSE)
   {
      //Prepare FUNET pattern
      for(i=0; i<sizeof(page_buffer)/4; i++)
      {
         *((kal_uint32*)(page_buffer)+i) = FUNET_MARKER;
      }

      //Erase the MAUI's second block to prevent ROM INFO
      status = g_ftlFuncTbl->FTL_EraseBlock(mauiFirstBlock+1, NULL);

      //Note that the minimum page number in 1 block is 2.
      //It is due to the smallest block size of serial flash is 4kb.

      //Assume maui bin is larger than 2 block

      //Write the ROM info to page 1
      if(status == FTL_SUCCESS)
      {
         status = g_ftlFuncTbl->FTL_WritePage(mauiFirstBlock+1, 1, flash_pmaui_gfh_buf, NULL);
      }

      //Write the marker @ page 0
      if(status == FTL_SUCCESS)
      {
         status = g_ftlFuncTbl->FTL_WritePage(mauiFirstBlock+1, 0, page_buffer, NULL);
      }

      if(status != FTL_SUCCESS)
      {
         BL_PRINT(LOG_ERROR, "Cannot write maker to MAUI's 2nd block, status=%d\n\r", status);
         return BL_FUNET_ERROR_ERASE_MARKER_BLOCK;
      }
   }

   return BL_FUNET_ERROR_NONE;
}

/*
 * Close FUNET package handler
 */
BL_FUNET_ERROR_CODE bl_FUNET_ClosePKG()
{
    BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;	
    kal_int32 fs_err = FS_NO_ERROR;
    	
    fs_err = FS_Close(bl_fs_handle);
    
		if(fs_err != FS_NO_ERROR)
		{
        BL_PRINT(LOG_DEBUG, "File to close pkg...%d\n\r", fs_err);
		    status = BL_FUNET_ERROR_FAIL_TO_CLOSE_FILE;
		}
		
		return status;

}
/*
 * Re-Open FUNET package handler and seek it to previous operation position
 */
BL_FUNET_ERROR_CODE bl_FUNET_ReOpenPKG()
{

    BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;	
    kal_int32 fs_err = FS_NO_ERROR;
        
    // open handler for pkg again
		bl_fs_handle = FS_Open(FUNET_PKG_PATH, FS_READ_WRITE);
				    
		if(bl_fs_handle < 0)
		{
	      fs_err = bl_fs_handle;
				status = BL_FUNET_ERROR_FAIL_TO_OPEN_FILE;
	  }

    if(status == BL_FUNET_ERROR_NONE)
    {	
	      fs_err = FS_Seek(bl_fs_handle, bl_fs_postion, 0);
	      if(fs_err < FS_NO_ERROR)
	      {
	          status = BL_FUNET_ERROR_FAIL_TO_SEEK_FILE;
	      }
    }
    
    if(status != BL_FUNET_ERROR_NONE)
    {
        BL_PRINT(LOG_DEBUG, "File to re-open pkg...%d\n\r", fs_err);
    }
    
    return status;
}

/* 
 * Create update info if it does not exist.
 * The update info contains 1. FUNET_Update_Info structure (64 bytes) 2. MAUI gfh info => will be write in runtime
 */
kal_int32 bl_FUNET_CreateUpdateInfo()
{
   kal_int32 ui_handle;
   FUNET_Update_Info ui;
   kal_int32 write;
   kal_int32 fs_err = FS_NO_ERROR;
   BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;	


   status = bl_FUNET_ClosePKG();


   if(status == BL_FUNET_ERROR_NONE)
   {
    	 // create update info if it does not exist
       if(FS_Open(UI_PATH, FS_READ_ONLY) <= 0)
       {
           ui_handle = FS_Open(UI_PATH, FS_CREATE_ALWAYS);
           
           if(ui_handle >= 0)
           {
               ui.m_ver = FUNET_UI_VERSION;
               ui.m_error_code = BL_FUNET_ERROR_NONE;
               ui.m_is_read = 0;
               memset(ui.m_marker, 0x0, FUNET_MARKER_REGION_SIZE);
               
               fs_err = FS_Write(ui_handle, &ui, sizeof(ui), &write);
               
               if(fs_err != FS_NO_ERROR)
               {
                   return fs_err;
               }
               else
               {
                   fs_err = FS_Close(ui_handle);
                   if(fs_err != FS_NO_ERROR)
                   {
                       return fs_err;
                   }
               }
           }
           else
           {
               return ui_handle;
           }
       }
   }

   if(status == BL_FUNET_ERROR_NONE)
   {
       status = bl_FUNET_ReOpenPKG();
   }

   return status;
}

/* 
 * Create status info if it does not exist.
 * The update info contains 1. FUNET_Update_Info (32bytes)
 */

kal_int32 bl_FUNET_CreateStatusInfo()
{
   kal_int32 ui_handle;
   FUNET_Update_Info ui;
   BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;	


   status = bl_FUNET_ClosePKG();


   if(status == BL_FUNET_ERROR_NONE)
   {
      ui_handle = FS_Open(UPDATED_STATUS_PATH, FS_CREATE_ALWAYS);
           
       if(ui_handle < 0)
       {
           return BL_FUNET_ERROR_FAIL_TO_CREATE_UI;
       }

   }


   status = bl_FUNET_ReOpenPKG();
 
   return status;
}



/*
 * RAW read update info
 */
BL_FUNET_ERROR_CODE bl_FUNET_ReadUI(kal_uint32 offset, void * buffer, kal_int32 buffer_size , const kal_wchar *FileName)
{
    BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;	
    kal_int32 fs_err = FS_NO_ERROR;
    kal_int32 ui_handle;
    kal_int32 read, write;
    kal_uint32 i;
    FUNET_Update_Info ui;
	
	
	  status = bl_FUNET_ClosePKG();

    
    if(status == BL_FUNET_ERROR_NONE)
    {
    	  // open update update_info
		    ui_handle = FS_Open(FileName, FS_READ_WRITE);
		    if(ui_handle < 0) //Something wrong in FS, just give the error code from FS
		    {  
		        fs_err = ui_handle;
		        status = BL_FUNET_ERROR_FAIL_TO_OPEN_FILE;
		    }
    }
    
    if(status == BL_FUNET_ERROR_NONE)
    {
        fs_err = FS_Seek(ui_handle, offset, 0);
        if(fs_err < FS_NO_ERROR)
		    {
		        status = BL_FUNET_ERROR_FAIL_TO_SEEK_FILE;
		    }
    }
    
    if(status == BL_FUNET_ERROR_NONE)
    {
        fs_err = FS_Read(ui_handle, buffer, buffer_size, &read);
				
        if(fs_err != FS_NO_ERROR)
		    {
		        status = BL_FUNET_ERROR_FAIL_TO_READ_FILE;
		    }
    }
    
    
    if(status == BL_FUNET_ERROR_NONE)
    {
    	  fs_err = FS_Close(ui_handle);
		    if(fs_err != FS_NO_ERROR)
		    {
		        status = BL_FUNET_ERROR_FAIL_TO_CLOSE_FILE;
		    }
    }   
		
	if(status == BL_FUNET_ERROR_NONE)
	{
		  status = bl_FUNET_ReOpenPKG();
	}


		BL_PRINT(LOG_DEBUG, "File operation status...%d\n\r", fs_err);
	  
	  return status;
    
}
/*
 * RAW write update info
 */
BL_FUNET_ERROR_CODE bl_FUNET_WriteUI(kal_uint32 offset, void * buffer, kal_int32 buffer_size, const kal_wchar *FileName)
{
    BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;	
    kal_int32 fs_err = FS_NO_ERROR;
    kal_int32 ui_handle;
    kal_int32 write;
    //FUNET_Update_Info ui;
	
	
	status = bl_FUNET_ClosePKG();

    /*if(status == BL_FUNET_ERROR_NONE)
    {
		    if(bl_FUNET_CreateUpdateInfo() != 0)
			  {
			  	 status = BL_FUNET_ERROR_FAIL_TO_CREATE_UI;
			  }
	  }*/
    
    if(status == BL_FUNET_ERROR_NONE)
    {
    	  // open update update_info
		    ui_handle = FS_Open(FileName, FS_READ_WRITE);
		    if(ui_handle < 0) //Something wrong in FS, just give the error code from FS
		    {  
		        fs_err = ui_handle;
		        status = BL_FUNET_ERROR_FAIL_TO_OPEN_FILE;
		    }
    }
    
    if(status == BL_FUNET_ERROR_NONE)
    {
        fs_err = FS_Seek(ui_handle, offset, 0);
        if(fs_err < FS_NO_ERROR)
		    {
		        status = BL_FUNET_ERROR_FAIL_TO_SEEK_FILE;
		    }
    }
    
    if(status == BL_FUNET_ERROR_NONE)
    {
        fs_err = FS_Write(ui_handle, buffer, buffer_size, &write);
        if(fs_err != FS_NO_ERROR)
		    {
		        status = BL_FUNET_ERROR_FAIL_TO_WRITE_FILE;
		    }
    }
    
    if(status == BL_FUNET_ERROR_NONE)
    {
    	  fs_err = FS_Close(ui_handle);
		    if(fs_err != FS_NO_ERROR)
		    {
		        status = BL_FUNET_ERROR_FAIL_TO_CLOSE_FILE;
		    }
    }   

		
    if(status == BL_FUNET_ERROR_NONE)
    {
		    status = bl_FUNET_ReOpenPKG();
	 }

    BL_PRINT(LOG_DEBUG, "File operation status...%d\n\r", fs_err);
		
	  
	  return status;
    
}



/*
 * Check if the marker in update info structure is "FUNTFUNTFUNTFUNT..."
 */
STATIC kal_bool bl_IsFUNETMarkerFound()
{
   kal_int32 ui_handle;
   kal_int32 read;
   kal_uint32 i;
   kal_bool marker_found = KAL_TRUE;
   FUNET_Update_Info ui;
   
   ui_handle = FS_Open(UI_PATH, 0);

   if(ui_handle < 0)
   {
      //BL_PRINT(LOG_DEBUG, "Open FS failed...%d\n\r", ui_handle);
      marker_found = KAL_FALSE;
   }
   else
   {
       if(FS_Read(ui_handle, &ui, sizeof(ui), &read) == FS_NO_ERROR)
	     {
	         for(i=0; i<sizeof(ui.m_marker)/4; i++)
	         {
	             if(*((kal_uint32*)(ui.m_marker)+i) != FUNET_MARKER)
		           {
		               marker_found = KAL_FALSE;
		           }
		       }
	     }
	     else
	     {
		       marker_found = KAL_FALSE;
	     } 	   
       FS_Close(ui_handle);
 	 }
 	 
 	 return marker_found;
   
}
/*
 * 1. Write marker to UI structure
 * 2. Write flash information to UI (this is according to original CardDL 
 *    which will use flash information to verify pkg body => bl_VerifyPKGBody()) 
 */
BL_FUNET_ERROR_CODE bl_MarkFUNET()
{
	
    BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;	
    FUNET_Update_Info ui;
    kal_uint32 i;
    

    status = bl_FUNET_CreateUpdateInfo();


    if(status == BL_FUNET_ERROR_NONE)    
    {
        status = bl_FUNET_ReadUI(0, &ui, sizeof(FUNET_Update_Info),UI_PATH);
    }

    if(status == BL_FUNET_ERROR_NONE)    
    {
		    // write marker
		    for(i=0; i<sizeof(ui.m_marker)/4; i++)
		    {
		        *((kal_uint32*)(ui.m_marker)+i) = FUNET_MARKER;
		    }
		    // 1. Write marker to UI structure    
		    bl_FUNET_WriteUI(0, &ui, sizeof(FUNET_Update_Info), UI_PATH);
    }
    
    // 2. Write flash information to UI (this is according to original CardDL
    if(status == BL_FUNET_ERROR_NONE)    
    {
        bl_FUNET_WriteUI(sizeof(FUNET_Update_Info), flash_pmaui_gfh_buf, sizeof(flash_pmaui_gfh_buf),UI_PATH);
    }
    
    return status;
	
	
}


/*
 * Clear the marker in UI structure
 */
BL_FUNET_ERROR_CODE bl_UnMarkFUNET()
{
    BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;	
    FUNET_Update_Info ui;
    kal_uint32 i;
    
    status = bl_FUNET_ReadUI(0, &ui, sizeof(FUNET_Update_Info),UI_PATH);
    
    if(status == BL_FUNET_ERROR_NONE)    
    {
		    // clear
		    for(i=0; i<sizeof(ui.m_marker)/4; i++)
		    {
		        *((kal_uint32*)(ui.m_marker)+i) = 0x0;
		    }
		    
		    bl_FUNET_WriteUI(0, &ui, sizeof(FUNET_Update_Info),UI_PATH);
    }
  
    return status;
}

/*
 * 1. Write update status to  structure
 */
BL_FUNET_ERROR_CODE bl_MarkStatus(BL_FUNET_ERROR_CODE updateStatus)
{
	
    BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;	
    FUNET_Update_Status ui;
    kal_uint32 i;
    
    status = bl_FUNET_CreateStatusInfo();

    if(status == BL_FUNET_ERROR_NONE)    
    {
        memset(&ui, 0, sizeof(FUNET_Update_Status));
		// write marker
		ui.m_ver = 0;
		ui.m_error_code = updateStatus;
		ui.m_marker = FUNET_MARKER;
		    
		// 1. Write marker to UI structure    
		bl_FUNET_WriteUI(0, &ui, sizeof(FUNET_Update_Status), UPDATED_STATUS_PATH);

	    BL_PRINT(LOG_DEBUG, "Status update Done...%d\n\r", status);
    }
    
    return status;	
}

BL_FUNET_ERROR_CODE bl_UnMarkStatus()
{
	BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;
    kal_int32 ui_handle;

    status = bl_FUNET_ClosePKG();

    ui_handle = FS_Delete(UPDATED_STATUS_PATH);
    
   
    if(status == BL_FUNET_ERROR_NONE)
    {
	    status = bl_FUNET_ReOpenPKG();
	}

	return status;
}


/*
BL_FUNET_ERROR_CODE bl_WriteMarkerBlocks(kal_uint32 mauiAddr)
{
   BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;

   ASSERT(mauiFirstBlock == bl_AddrToBlockIdx(mauiAddr, NULL));

   BL_PRINT(LOG_DEBUG, "Write %d, 0x%x\n\r", mauiFirstBlock, mauiAddr);
   //The MAUI address is at bank1 if it is remapped, the XIM address is start from 0x0, thus the mauiAddr needs to be remapped.
   status = bl_WriteXimBlockToFlash(mauiAddr&REMAPPING_MASK, mauiFirstBlock, NULL, NULL, 0);

   if(status == FTL_SUCCESS)
   {
      kal_uint32 p = mauiAddr + g_ftlFuncTbl->FTL_GetBlockSize(mauiFirstBlock, NULL);
      BL_PRINT(LOG_DEBUG, "Write %d, 0x%x\n\r", mauiFirstBlock+1, p);

      //The MAUI address is at bank1 if it is remapped, the XIM address is start from 0x0, thus the p needs to be remapped.
      status = bl_WriteXimBlockToFlash(p&REMAPPING_MASK, mauiFirstBlock+1, NULL, NULL, 0);
   }

   if(status != FTL_SUCCESS)
   {
      BL_PRINT(LOG_ERROR, "Cannot write data to makers, status=%d\n\r", status);
      return BL_FUNET_ERROR_WRITE_MARKER_BLOCK;
   }

   return BL_FUNET_ERROR_NONE;
}
*/

#endif /* _NAND_FLASH_BOOTING_ */


/*************************************************************************
 * load rom_info/maui_info
 *************************************************************************/
 
BL_FUNET_ERROR_CODE bl_LoadpMauiGFHInfoInBIN()
{
   kal_uint32 status = BL_FUNET_ERROR_NONE;
   GFH_FILE_INFO_v1 *FileInfo;

#ifdef __FOTA_DM__  
   kal_uint32 uaOffset = 1;
#else
   kal_uint32 uaOffset = 0;
#endif 

#ifdef _NAND_FLASH_BOOTING_
   kal_uint32 byteidx = (pMAUIImage[XIM_MAUI_IDX+uaOffset].start_block)*page_per_block*page_size; // to be modify
#else /* _NAND_FLASH_BOOTING_ */
   kal_uint32 byteidx = (pDl_IOT_HEADER->m_extra_info[bl_GetImgIdx(PRIMARY_MAUI)].m_bin_offset);
#endif /* _NAND_FLASH_BOOTING_ */

   //Read at least first 512 bytes of p-MAUI from it's begining
   //The page size is at least 512 bytes, thus here simply read a page from begining.
   status = bl_ReadXIMByte((kal_uint32)pmaui_gfh_buf, byteidx, page_size, KAL_FALSE);
   if(status != BL_FUNET_ERROR_NONE)
   {
      return status;
   }

   //Get the FILE info
   if(GFH_Find((U32)pmaui_gfh_buf, GFH_FILE_INFO, (void **)&FileInfo) != B_OK)
   {
      return BL_FUNET_ERROR_NO_PKG_GFH_FILE_INFO_FOUND;
   }

   //Make sure the size of pmaui_gfh_buf contains the full gfh
   if(FileInfo->m_content_offset > sizeof(pmaui_gfh_buf))
   {
      return BL_FUNET_ERROR_INSUFFICIENT_GFH_INFO_BUF;
   }

   //Read the whole GFH
   status = bl_ReadXIMByte((kal_uint32)pmaui_gfh_buf, byteidx, FileInfo->m_content_offset, KAL_FALSE);
   if(status != BL_FUNET_ERROR_NONE)
   {
      return status;
   }

   //Get the MAUI info
   if(GFH_Find((U32)pmaui_gfh_buf, GFH_MAUI_INFO, (void **)&pMauiInfoInCard) != B_OK)
   {
      return BL_FUNET_ERROR_NO_PKG_GFH_MAUI_INFO_FOUND;
   }

#ifdef _NAND_FLASH_BOOTING_
   //Get the flash layout from flash instead of from card. These value will be re-written during update.
   if(CBR_ReadRecord(E_CBR_IDX_CBR, CBR_RECORD_FLASH_LAYOUT, (kal_uint8 *)&flash_layout_info, sizeof(FlashLayout), NULL) <= 0)
   {
      return BL_FUNET_ERROR_UNABLE_TO_FIND_CBR_IMAGE_INFO;
   }

   //Get the space info from flash instead of from card. These value will be re-written during update.
   if(CBR_ReadRecord(E_CBR_IDX_CBR, CBR_RECORD_FLASH_SPACE_INFO, (kal_uint8 *)&space_info, sizeof(Nand_ImageSpace_ST), NULL) <= 0)
   {
      return BL_FUNET_ERROR_UNABLE_TO_FIND_CBR_SPACE_INFO;
   }

   pSpaceInfo = &space_info;
#endif /* _NAND_FLASH_BOOTING_ */

   return BL_FUNET_ERROR_NONE;
}


/*************************************************************************
 * MAIN functions
 *************************************************************************/

BL_FUNET_ERROR_CODE bl_InitialUpdate()
{
   BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;

#ifdef _NAND_FLASH_BOOTING_

   //If there is no CBR_RECORD_UPDATING_INFO, than we add it
   if(CBR_GetRecordLen(E_CBR_IDX_CBR, CBR_RECORD_UPDATING_INFO)<=0)
   {
      UpdatingRecord.m_info_type_magic = FUNET_MARKER;

      //The content of UpdatingRecord should be got during bl_VerifyPKGBody()
      if(CBR_AddRecord(E_CBR_IDX_CBR, CBR_RECORD_UPDATING_INFO, (kal_uint8 *)&UpdatingRecord, sizeof(UPDATING_RECORD), SDS_DP_NONE, NULL) != CBR_SUCCESS)
      {
         return BL_FUNET_ERROR_FAIL_TO_ADD_CBR_UPDATING_INFO;
      }
   }
   else
   {  //If CBR_RECORD_UPDATING_INFO is exist, it means some UA is doing update.
      if(last_funet_fail_flag == KAL_FALSE)
      {  //It means other update agent is doing update. FUNET agent should not try to do FUNET.
         return BL_FUNET_ERROR_OTHER_UA_IS_DOING_UPDATE;
      }
      //else, we are doing FUNET again to recover last FUNET fail
   }

#else /* _NAND_FLASH_BOOTING_ */

   /* !!! The bl_MarkCDL can be ignore in FUNET case */
   status = bl_MarkFUNET();


#endif /* _NAND_FLASH_BOOTING_ */

   return status;
}


BL_FUNET_ERROR_CODE bl_FinishUpdate()
{
   BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;

#ifdef _NAND_FLASH_BOOTING_

   if(CBR_DelRecord(E_CBR_IDX_CBR, CBR_RECORD_UPDATING_INFO) != CBR_SUCCESS)
   {
      return BL_FUNET_ERROR_FAIL_TO_DEL_CBR_UPDATING_INFO;
   }

#else

   /* !!! We still call bl_WriteMarkerBlocks in FUNET to make sure the 2nd block of MAUI to be written*/
   status = bl_UnMarkFUNET();

#endif

   if(status == BL_FUNET_ERROR_NONE)
   {
      bl_ClearFUNETTrigger();
   }

   return status;
}

BL_FUNET_ERROR_CODE bl_ExtraInfoCheck()
{
   kal_int32 i, j;
   kal_uint32 extraInfoFsCount = 0;
   kal_uint32 numUpdateCodeImg = 0;       //For checking if all maui image are all updated or not updated
   kal_uint32 codeImgExist  = KAL_FALSE;   //For checking if all maui image are all updated or not updated
   kal_uint32 vivaUpdate    = KAL_FALSE;
   kal_uint32 mauiUpdate    = KAL_FALSE;
   //FOR MBA check
   kal_uint32 custUpdate    = KAL_FALSE; 
   kal_uint32 langUpdate    = KAL_FALSE; 
   kal_uint32 jumpUpdate    = KAL_FALSE; 
   kal_uint32 fsStartAddr   = 0;


   GFH_DL_PACKAGE_INFO_v2 *pPkgInfo = &pDl_Package_GFH->gfh_dl_package_info;

   for(i=0; i<sizeof(pPkgInfo->m_extra_info)/sizeof(pPkgInfo->m_extra_info[0]); i++)
   {
      if(pPkgInfo->m_extra_info[i].m_bin_type == GFH_FILE_NONE)
      {
         extra_info_count = i;
         break;
      }

      BL_PRINT(LOG_DEBUG, "extraInfo[%d] bin_type=%x, addr=%x, size=%d, op=%d\n\r", i, pPkgInfo->m_extra_info[i].m_bin_type, pPkgInfo->m_extra_info[i].m_bin_start_addr, pPkgInfo->m_extra_info[i].m_bin_length, pPkgInfo->m_extra_info[i].m_operation);
      
      if(bl_IsValidBinInfoItem(&pPkgInfo->m_extra_info[i]) == KAL_FALSE)
      {
         continue;
      }

      //Check all valid operations
      if(!(pPkgInfo->m_extra_info[i].m_operation >= IM_DOWNLOAD && pPkgInfo->m_extra_info[i].m_operation <= IM_ERASE))
      {
         return BL_FUNET_ERROR_INVALID_BINARY_OPERATION;
      }

      //Only FS area allow erasing
      if(pPkgInfo->m_extra_info[i].m_operation == IM_ERASE)
      {
            return BL_FUNET_ERROR_INVALID_BINARY_OPERATION;
      }

      //Bootloader can not be updated
      if(((pPkgInfo->m_extra_info[i].m_bin_type == ARM_BL) || (pPkgInfo->m_extra_info[i].m_bin_type == ARM_EXT_BL) || (pPkgInfo->m_extra_info[i].m_bin_type == DUALMAC_DSP_BL)) && 
         (pPkgInfo->m_extra_info[i].m_operation != IM_SKIP) )
      {
         return BL_FUNET_ERROR_BOOTLOADER_CANNOT_BE_UPDATED;
      }

      //IOT FOTA don't support update FS
      if(pPkgInfo->m_extra_info[i].m_bin_type ==V_FILE_SYSTEM_BINARY)
      {
         return BL_FUNET_ERROR_FS_CANNOT_BE_UPDATED ;
      }
      

      // check MAUI exist and needed update
      if(pPkgInfo->m_extra_info[i].m_bin_type == V_MAUI_BINARY && pPkgInfo->m_extra_info[i].m_operation == IM_DOWNLOAD)
      {
            mauiUpdate = KAL_TRUE;
      }
      // check VIVA exist and needed update
      if(pPkgInfo->m_extra_info[i].m_bin_type == VIVA && pPkgInfo->m_extra_info[i].m_operation == IM_DOWNLOAD)
      {
            vivaUpdate = KAL_TRUE;
      }


      
      //The resource images and 3rd rom must be all updated, the only allowed operation for them is download.
      if((pPkgInfo->m_extra_info[i].m_bin_type >= V_RESOURCE_BINARY && pPkgInfo->m_extra_info[i].m_bin_type < V_RESOURCE_BINARY_END) ||
         (pPkgInfo->m_extra_info[i].m_bin_type == THIRD_ROM))
      {
         if(pPkgInfo->m_extra_info[i].m_operation != IM_DOWNLOAD)
         {
            return BL_FUNET_ERROR_INVALID_BINARY_OPERATION;
         }
      }

      //Check if the xim has FOTA or MBA layout
      if((pPkgInfo->m_extra_info[i].m_bin_type >= V_RESOURCE_BINARY && pPkgInfo->m_extra_info[i].m_bin_type < V_RESOURCE_BINARY_END) ||
         (pPkgInfo->m_extra_info[i].m_bin_type == FOTA_UE))
      {
         ximFixedLayout = KAL_TRUE;
      }

      //Check MBA (jump_tbl, cust_pack, lang_pack) exist and needed update
      if(pPkgInfo->m_extra_info[i].m_bin_type == CUSTOM_PACK && pPkgInfo->m_extra_info[i].m_operation == IM_DOWNLOAD)
      {
            custUpdate = KAL_TRUE;
      }

      if(pPkgInfo->m_extra_info[i].m_bin_type == LANGUAGE_PACK && pPkgInfo->m_extra_info[i].m_operation == IM_DOWNLOAD)
      {
            langUpdate = KAL_TRUE;
      }

      if(pPkgInfo->m_extra_info[i].m_bin_type == JUMP_TABLE && pPkgInfo->m_extra_info[i].m_operation == IM_DOWNLOAD)
      {
            jumpUpdate = KAL_TRUE;
      }

      //Check if it is partial update
      //For other images (except filesystem), they must be all updated, or all not updated
      if(((pPkgInfo->m_extra_info[i].m_bin_type >= V_MAUI_BINARY && pPkgInfo->m_extra_info[i].m_bin_type < V_MAUI_BINARY_END) ||
         (pPkgInfo->m_extra_info[i].m_bin_type >= V_MISC_BINARY && pPkgInfo->m_extra_info[i].m_bin_type < V_MISC_BINARY_END) ||
         (pPkgInfo->m_extra_info[i].m_bin_type >= V_SECURE_RO && pPkgInfo->m_extra_info[i].m_bin_type < V_SECURE_RO_END) ||
         (pPkgInfo->m_extra_info[i].m_bin_type >= V_SRD && pPkgInfo->m_extra_info[i].m_bin_type < V_SRD_END)) &&
         (pPkgInfo->m_extra_info[i].m_bin_type != THIRD_ROM))
      {
         codeImgExist = KAL_TRUE;
         
         //Count the image to be updated.
         if(pPkgInfo->m_extra_info[i].m_operation == IM_DOWNLOAD)
         {
            numUpdateCodeImg++;
         }
         //If there are some images do not want to be updated, it must be partial update mode.
         else
         {
            codePartialUpdate = KAL_TRUE;
         }

         //If codePartialUpdate is true, only resource and 3rd rom can be marked as IM_DOWNLOAD
         if(codePartialUpdate && numUpdateCodeImg)
         {
            return BL_FUNET_ERROR_INVALID_PARTIAL_UPDATE_PACKAGE;
         }
      }


#ifdef _NAND_FLASH_BOOTING_
      //Addr and Length is NA for NAND. IM has all information already, except for FAT region
      if(pPkgInfo->m_extra_info[i].m_bin_start_addr || pPkgInfo->m_extra_info[i].m_bin_length)
      {
         //if(!(pPkgInfo->m_extra_info[i].m_bin_type >= V_FILE_SYSTEM_BINARY && pPkgInfo->m_extra_info[i].m_bin_type < V_FILE_SYSTEM_BINARY_END))
         //{
            return BL_FUNET_ERROR_XIM_INVALID_PARAM;
         //}
      }

#else            
      //Check no one can touch bootloader region!!!
      //The NOR flash start address is pretended at 0x0. The DL package also assume flash is at 0x0.
      if(IS_OVERLAP(0, BOOTLOADER_ROM_REGION_LEN, pPkgInfo->m_extra_info[i].m_bin_start_addr, pPkgInfo->m_extra_info[i].m_bin_length) &&
         (pPkgInfo->m_extra_info[i].m_bin_type != ARM_BL) && (pPkgInfo->m_extra_info[i].m_bin_type != ARM_EXT_BL)
         && (pPkgInfo->m_extra_info[i].m_bin_type != DUALMAC_DSP_BL)
         && (pPkgInfo->m_extra_info[i].m_bin_type != FOTA_UE))
      {
         return BL_FUNET_ERROR_BOOTLOADER_CANNOT_BE_UPDATED;
      }

      //Check if any invalid binary is specified
      if(!( (pPkgInfo->m_extra_info[i].m_bin_type >= V_MAUI_BINARY && pPkgInfo->m_extra_info[i].m_bin_type < V_MAUI_BINARY_END) ||
            (pPkgInfo->m_extra_info[i].m_bin_type >= V_RESOURCE_BINARY && pPkgInfo->m_extra_info[i].m_bin_type < V_RESOURCE_BINARY_END) ||
            (pPkgInfo->m_extra_info[i].m_bin_type == ARM_BL) ||
            (pPkgInfo->m_extra_info[i].m_bin_type == ARM_EXT_BL) ||
            (pPkgInfo->m_extra_info[i].m_bin_type == DUALMAC_DSP_BL) ||
            (pPkgInfo->m_extra_info[i].m_bin_type == FOTA_UE) ) )
      {
         return BL_FUNET_ERROR_INVALID_UPDATING_BINARY;
      }

      if(pPkgInfo->m_extra_info[i].m_bin_type == SECONDARY_MAUI ||
         pPkgInfo->m_extra_info[i].m_bin_type == ON_DEMAND_PAGING ||
         pPkgInfo->m_extra_info[i].m_bin_type == THIRD_ROM ||
         pPkgInfo->m_extra_info[i].m_bin_type == IOT_WIFI_BIN )
      {
         return BL_FUNET_ERROR_INVALID_UPDATING_BINARY;
      }

      //MAUI should start with the address as the current one
      if(pPkgInfo->m_extra_info[i].m_bin_type == PRIMARY_MAUI)
      {
         //Since the DL-pkg is not remapped, the MAUI_ROM_START_ADDR should not remapped
         if(pPkgInfo->m_extra_info[i].m_bin_start_addr != (MAUI_ROM_START_ADDR&REMAPPING_MASK))
         {
            return BL_FUNET_ERROR_INVALID_BINARY_ADDRESS;
         }
      }

      //Check if there is any region overlapping the others
      for(j=0; j<i-1; j++)
      {
         if(bl_IsValidBinInfoItem(&pPkgInfo->m_extra_info[j]))
         {
            if( IS_OVERLAP(pPkgInfo->m_extra_info[i].m_bin_start_addr, pPkgInfo->m_extra_info[i].m_bin_length,
                           pPkgInfo->m_extra_info[j].m_bin_start_addr, pPkgInfo->m_extra_info[j].m_bin_length ))
               return BL_FUNET_ERROR_REGION_OVERLAP;
         }
      }


      fsStartAddr = MapToCurrentFlashAddr(get_NOR_FLASH_BASE_ADDRESS());
      /*
      Check no one can touch WIFI bin
      if((pPkgInfo->m_extra_info[i].m_bin_start_addr |ROM_ADDR_MASK) > (fsStartAddr - MAX_WIFI_BIN_SIZE))
      {
         return BL_FUNET_ERROR_OVERLAP_WITH_WIFI_BIN ;
      }
      */

      //Check no one can touch target FS retion 
      if((pPkgInfo->m_extra_info[i].m_bin_start_addr |ROM_ADDR_MASK) > fsStartAddr  )
      {
         return BL_FUNET_ERROR_OVERLAP_WITH_TARGET_FS ;
      }

#endif /* _NAND_FLASH_BOOTING_ */

   }


   //[CAUTION] extra_info_count is only used for NAND SV3 case, it should exclude the FS count.
   extra_info_count -= extraInfoFsCount;

   //If the package is for partial update, There might be no records for code image in extra_info.
   //Thus use codeImgExist to do negative checking
   if(!codeImgExist)
   {
      codePartialUpdate = KAL_TRUE;
   }
   
   if((codePartialUpdate == KAL_TRUE) && (ximFixedLayout == KAL_FALSE))
   {
      return BL_FUNET_ERROR_INVALID_BINARY_OPERATION;
   }

    /*Check combination of download image*/
    /*We only support following combination (MBA: jump_tbl + cust_pack + lang_pack)
      FULL:
         MAUI+VIVA or MAUI+VIVA+MBA
      Partial:
         MBA
     */

    /* we don't support case when only maui or viva is updated*/
   if(vivaUpdate ^ mauiUpdate)
   {
      return BL_FUNET_ERROR_PKG_PARTIAL_UPDATE_ERROR ;
   }
   
   /*MBA must be update together*/
   if(custUpdate & langUpdate & jumpUpdate)
   {
        mbaUpdate = KAL_TRUE;
   }
   if(!mbaUpdate && (custUpdate | langUpdate | jumpUpdate))
   {
      return BL_FUNET_ERROR_MBA_BIN_COMBINATION_ERROR;
   }


   return BL_FUNET_ERROR_NONE;
}


//Working buffer structure
// GFH                        <-- pDl_Package_GFH
// NAND_IMAEG_HEADER          <-- pDl_Package_Nand_Image_Header                                          (NAND Only)
// FDM MAPPING tbl            <-- pFDM5MappingTbl (May be NULL if mapping table is too big to load)      (NAND Only)
// Signature * 2              <-- pSignatureBegin

BL_FUNET_ERROR_CODE bl_LoadAndCheckPKGHeader()
{
   //Read the GFH
   pDl_Package_GFH = (DL_PACKAGE_GFH*)work_buf;

   memset(pDl_Package_GFH, 0, sizeof(DL_PACKAGE_GFH));

   if( bl_DL_Read(pDl_Package_GFH, sizeof(DL_PACKAGE_GFH)) != sizeof(DL_PACKAGE_GFH) )
   {
      return BL_FUNET_ERROR_NO_DL_PACKAGE_FOUND;
   }

   //Check if there are marks of DL package
   if(GFH_GET_MAGIC(pDl_Package_GFH->gfh_file_info.m_gfh_hdr.m_magic_ver)       != GFH_HDR_MAGIC ||
      GFH_GET_MAGIC(pDl_Package_GFH->gfh_dl_package_info.m_gfh_hdr.m_magic_ver) != GFH_HDR_MAGIC ||
      pDl_Package_GFH->gfh_file_info.m_file_type != CARD_DOWNLOAD_PACKAGE                        ||
      pDl_Package_GFH->gfh_dl_package_info.m_gfh_hdr.m_type != GFH_DL_PACKAGE_INFO               ||
      strcmp((kal_char*)pDl_Package_GFH->gfh_dl_package_info.m_identifier, GFH_DL_PACKAGE_ID)
      )
   {
      return BL_FUNET_ERROR_NO_DL_PACKAGE_FOUND;
   }

   //Validate the GFH
   //Check version
   ASSERT_VALID_PARAM_IN_XIM_BODY(GFH_GET_VER(pDl_Package_GFH->gfh_file_info.m_gfh_hdr.m_magic_ver) == 1);
   ASSERT_VALID_PARAM_IN_XIM_BODY(GFH_GET_VER(pDl_Package_GFH->gfh_dl_package_info.m_gfh_hdr.m_magic_ver) == 2);

   //Sanity test
   ASSERT_VALID_PARAM_IN_XIM_BODY(pDl_Package_GFH->gfh_file_info.m_content_offset < pDl_Package_GFH->gfh_file_info.m_file_len);
   ASSERT_VALID_PARAM_IN_XIM_BODY(pDl_Package_GFH->gfh_file_info.m_file_len - pDl_Package_GFH->gfh_file_info.m_content_offset > 2048 );

#ifdef _NAND_FLASH_BOOTING_
   ASSERT_VALID_PARAM_IN_XIM_BODY(pDl_Package_GFH->gfh_dl_package_info.m_im_device == IM_NAND);
#else
   ASSERT_VALID_PARAM_IN_XIM_BODY(pDl_Package_GFH->gfh_dl_package_info.m_im_device == IM_NOR);
#endif

   dl_package_size = pDl_Package_GFH->gfh_file_info.m_file_len;
   im_file_size    = dl_package_size - pDl_Package_GFH->gfh_file_info.m_content_offset - pDl_Package_GFH->gfh_dl_package_info.m_sig_len*2;
   signatureLength = pDl_Package_GFH->gfh_dl_package_info.m_sig_len*2;

   //Sanity test: Check the sig offset
   ASSERT_VALID_PARAM_IN_XIM_BODY(pDl_Package_GFH->gfh_dl_package_info.m_sig_offset == dl_package_size - pDl_Package_GFH->gfh_dl_package_info.m_sig_len*2);

#ifdef _NAND_FLASH_BOOTING_
   //Read the beginning of NAND header to determin the page size
   pDl_Package_Nand_Image_Header = (DL_PACKAGE_NAND_IMAGE_HEADER*)((kal_uint8*)work_buf+sizeof(DL_PACKAGE_GFH));
   if( bl_DL_Read(pDl_Package_Nand_Image_Header, 2048) != 2048)
   {
      return BL_FUNET_ERROR_PACKAGE_READ_FAIL;
   }

   //Sanity test for DL_PACKAGE_NAND_IMAGE_HEADER. to enrich
   //Only support FDM 5.0
   ASSERT_VALID_PARAM_IN_NAND_IMAEG_HEADER(pDl_Package_Nand_Image_Header->FDM_ver == IM_FDMVER_500);
   //The block & page size in NAND Image header must be reasonable
   ASSERT_VALID_PARAM_IN_NAND_IMAEG_HEADER((pDl_Package_Nand_Image_Header->block_size*1024)%pDl_Package_Nand_Image_Header->page_size == 0);
   ASSERT_VALID_PARAM_IN_NAND_IMAEG_HEADER(pDl_Package_Nand_Image_Header->page_size == 512 || pDl_Package_Nand_Image_Header->page_size == 2048 || pDl_Package_Nand_Image_Header->page_size == 4096);

   //Compare NAND parameters with current ones
   ASSERT_VALID_PARAM_IN_NAND_IMAEG_HEADER(pDl_Package_Nand_Image_Header->page_size == BLHeader.NFIinfo.pageSize);
   ASSERT_VALID_PARAM_IN_NAND_IMAEG_HEADER(pDl_Package_Nand_Image_Header->block_size*1024 == BLHeader.pagesPerBlock*BLHeader.NFIinfo.pageSize);
   ASSERT_VALID_PARAM_IN_NAND_IMAEG_HEADER((pDl_Package_Nand_Image_Header->io_width==8 && BLHeader.NFIinfo.IOInterface==IO_8BITS) || (pDl_Package_Nand_Image_Header->io_width==16 && BLHeader.NFIinfo.IOInterface==IO_16BITS));
   ASSERT_VALID_PARAM_IN_NAND_IMAEG_HEADER(pDl_Package_Nand_Image_Header->addr_cycle == BLHeader.NFIinfo.addressCycle);

   //Copy necessary parameter to local variables
   block_size = pDl_Package_Nand_Image_Header->block_size*1024;
   page_size = pDl_Package_Nand_Image_Header->page_size;
   page_per_block = block_size/page_size;
   page_size_with_spare = pDl_Package_Nand_Image_Header->page_size + bl_GetSpareSize(pDl_Package_Nand_Image_Header->page_size);
   block_size_with_spare = page_size_with_spare*page_per_block;

   //Sanity test: The size of IM file must be multiple of block size
   ASSERT_VALID_PARAM_IN_NAND_IMAEG_HEADER(im_file_size%block_size_with_spare == 0);

#endif /* _NAND_FLASH_BOOTING_ */

   //Do basic test on the layout decription
   {
      BL_FUNET_ERROR_CODE status = bl_ExtraInfoCheck();
      if(status != BL_FUNET_ERROR_NONE)
      {
         return status;
      }
   }

   return BL_FUNET_ERROR_NONE;
}

BL_FUNET_ERROR_CODE bl_ParseAndVerifyPKGHeader()
{
   BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;
   kal_uint8 *pWorkBufEnd = ((kal_uint8*)work_buf) + sizeof(work_buf);
   kal_uint32 read_page;

   //Calculate the hash value of header part
   bl_Alg_Hash_Init();
   bl_Alg_Hash_Append((kal_uint32)pDl_Package_GFH, sizeof(*pDl_Package_GFH));

#ifdef _NAND_FLASH_BOOTING_
   {
      //Read the header data with all available buffer

      DL_PACKAGE_NAND_IMAGE_HEADER_IMG_RECORD emptyRecord, *pImage;
      memset(&emptyRecord, INVALID_1B_CONTENT, sizeof(emptyRecord));

      //Read a block at most since the minimum length of the NFB header is one block
      //Read more than 1 block may cause the need of re-calcuation the hash

      //Also assume all the image records can be loaded in to the working buffer, or error BL_FUNET_ERROR_INSUFFICIENT_WORKING_BUF occurs

      read_page = MIN((pWorkBufEnd-(kal_uint8*)pDl_Package_Nand_Image_Header)/page_size, page_per_block);
      status = bl_ReadXIMPage((kal_uint32)pDl_Package_Nand_Image_Header, 0, read_page, KAL_TRUE);

      if(status != BL_FUNET_ERROR_NONE)
      {
         return status;
      }

      pImage = (DL_PACKAGE_NAND_IMAGE_HEADER_IMG_RECORD*)(pDl_Package_Nand_Image_Header+1);


      //NAND flash always has bootloader
      pMAUIImage = pImage;
      pImage++;

      while( (kal_uint8*)(pImage+1) < pWorkBufEnd && memcmp(pImage, &emptyRecord, sizeof(emptyRecord))!=0 )
      {
          //Sanity test of the DL_PACKAGE_NAND_IMAGE_HEADER_IMG_RECORD record, to enrich
         if(pMAUIImage == NULL && !bl_isFSImageRecord(pImage))
         {
             pMAUIImage = pImage;
         }
         else if(pFSImage == NULL && bl_isFSImageRecord(pImage))
         {
             pFSImage = pImage;
         }
         pImage++;
      }

      if( (kal_uint8*)(pImage+1) >= pWorkBufEnd )
      {
         //The image record region is large than expected, something wrong
         return BL_FUNET_ERROR_INSUFFICIENT_WORKING_BUF;
      }

      //Calculate the number of image records
      if(pMAUIImage)
         image_count = pFSImage ? (pFSImage-pMAUIImage) : (pImage-pMAUIImage) ;

      if(pFSImage)
         fs_image_count = pImage-pFSImage;


      //Sanity test: NFB with FDM v5 must has at least 3 images in XIM
      ASSERT_VALID_PARAM_IN_NAND_IMAEG_HEADER(image_count > 3)

      //Parse FDM5's mapping tbl and estimate the end of NAND image header
      pFDM5MappingTbl = (DL_PACKAGE_NAND_IMAGE_HEADER_FDM5_MAP_TBL*)(pImage+1);
      pFDM5MappingTblOffset = (kal_uint8*)pFDM5MappingTbl-(kal_uint8*)pDl_Package_Nand_Image_Header;
      FDM5MappingTblLen = (pFDM5MappingTbl->size * sizeof(pFDM5MappingTbl->log2phy[0]) + sizeof(pFDM5MappingTbl->size));
      FDM5MappingTblEntryNum = pFDM5MappingTbl->size;

      nand_image_header_len = (kal_uint8*)pFDM5MappingTbl + FDM5MappingTblLen - (kal_uint8*)work_buf - pDl_Package_GFH->gfh_file_info.m_content_offset;

      //Calculate the block count of nand image header
      header_block_count = (nand_image_header_len+block_size-1)/block_size;

      if((kal_uint8*)pFDM5MappingTbl+FDM5MappingTblLen > pWorkBufEnd-signatureLength)
      {
         //Sorry, we don't have enough space for complete mapping table. Have to perform lookup on the fly
         pFDM5MappingTbl = NULL;
      }

      //Sanity test: the data block must be the first image
      ASSERT_VALID_PARAM_IN_NAND_IMAEG_HEADER(pMAUIImage[0].start_block == header_block_count);
      ASSERT_VALID_PARAM_IN_NAND_IMAEG_HEADER(pMAUIImage != NULL);
      //Sanity test: MAUI image must exists

      //Read and caculate the hash value of rest dummy data
      while(read_page < header_block_count*page_per_block)
      {
         status = bl_ReadXIMPage((kal_uint32)page_buffer, read_page, 1, KAL_TRUE);

         if(status != BL_FUNET_ERROR_NONE)
         {
            return status;
         }
         read_page++;
         bl_UpdateProgress(VERIFY_PHASE, (read_page*100/(im_file_size/page_size_with_spare)));
      }
   }
#endif /* _NAND_FLASH_BOOTING_ */

   bl_Alg_Hash_Finish((kal_uint32)hash_value, sizeof(hash_value));

   /* Read signature */

   pSignatureBegin = pWorkBufEnd - signatureLength;

#ifdef _NAND_FLASH_BOOTING_
   //Test if we still have space in the working buffer for the signature
   if( pSignatureBegin < ((kal_uint8*)pDl_Package_Nand_Image_Header) + nand_image_header_len)
   {
       //GFH + header(with image record) + signature > predefined size of working buf (32K)
       return BL_FUNET_ERROR_INSUFFICIENT_WORKING_BUF;
   }

   //"Signatures+GFH+ImageHeader" are bigger than the DL package? Impossible...
   ASSERT_VALID_PARAM_IN_NAND_IMAEG_HEADER(dl_package_size >= signatureLength + nand_image_header_len + pDl_Package_GFH->gfh_file_info.m_content_offset);
#endif /* _NAND_FLASH_BOOTING_ */

   //Seek and read
   if(bl_DL_Seek(dl_package_size - signatureLength, 0) != 0)
   {
      status = BL_FUNET_ERROR_PACKAGE_SEEK_FAIL;
   }

   if(status == BL_FUNET_ERROR_NONE)
   {
      if(bl_DL_Read(pSignatureBegin, signatureLength) != signatureLength)
      {
         status = BL_FUNET_ERROR_PACKAGE_READ_FAIL;
      }
   }

   if(custom_get_CDL_asymmetric_key_len() && status == BL_FUNET_ERROR_NONE)
   {
      if( bl_DL_SignatureVerify(hash_value, sizeof(hash_value), pSignatureBegin, signatureLength/2) == KAL_FALSE)
      {
         BL_PRINT(LOG_WARN, "Invalud header signature\n\r");
         status = BL_FUNET_ERROR_INVALIDE_HEADER_SIG;
      }
   }

   //Calculate the xim image index for CBR and p-MAUI
   #ifdef _NAND_FLASH_BOOTING_
   
   xim_cbr_index = pDl_Package_Nand_Image_Header->Boot_Info_Count;
   xim_maui_index = xim_cbr_index + 1;
   
   #else /* _NAND_FLASH_BOOTING_  */
   
   #ifdef __MTK_SECURE_PLATFORM__   
/* under construction !*/
/* under construction !*/
   #else /* __MTK_SECURE_PLATFORM__ */
   xim_cbr_index = -2;
   xim_maui_index = 3;
   #endif /* __MTK_SECURE_PLATFORM__ */
   #ifdef __DSP_FCORE4__
   xim_cbr_index++;
   xim_maui_index++;
   #endif
   
   #endif /* _NAND_FLASH_BOOTING_  */

   return status;

}

void bl_MBAGetEntry(MTK_Recource_Entry_V3* pEntry , GFH_FILE_TYPE bin_type, kal_uint32 entry_num)
{   
    kal_uint32 offset1 = pDl_IOT_HEADER->m_extra_info[bl_GetImgIdx(bin_type)].m_bin_offset;
    kal_uint32 offset2 = sizeof(GFH_FILE_INFO_v1);
    kal_uint32 offset3 = sizeof(MTK_Recource_Entry_V3) * entry_num;
    
    bl_ReadXIMByte((kal_uint32)pEntry, offset1 + offset2 + offset3, sizeof(MTK_Recource_Entry_V3), KAL_FALSE);
}



/*This check perform when MBA update exist*/
BL_FUNET_ERROR_CODE bl_MBABinaryCheck()
{
    BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;


    MTK_Recource_Entry_V3 JumpEntry ;
    MTK_Recource_Entry_V3 LangEntry ;
    MTK_Recource_Entry_V3 CustEntry ;
    kal_uint32 i = 0;
    
    //get Entry in cust_pack, lang_pack
    bl_MBAGetEntry(&LangEntry, LANGUAGE_PACK,0);
    bl_MBAGetEntry(&CustEntry, CUSTOM_PACK,0);

    //Check each enery in jump tbl
    for(i=0; i < RESOURCE_ENTRY_NUM; i++ )
    {
        bl_MBAGetEntry(&JumpEntry, JUMP_TABLE,i);

        if(JumpEntry.m_res_type == LangEntry.m_res_type)
        {
            if( !((JumpEntry.m_base_addr == LangEntry.m_base_addr)&& 
                 (JumpEntry.m_exec_addr == LangEntry.m_exec_addr)&&
                 (JumpEntry.m_content_size == LangEntry.m_content_size)) )
              {
                 status = BL_FUNET_ERROR_MBA_LANG_PACK_NOT_MATCH_ERROR ; 
              }
            
        }
        
        else if(JumpEntry.m_res_type == CustEntry.m_res_type)
        {
             if( !((JumpEntry.m_base_addr == CustEntry.m_base_addr)&& 
                  (JumpEntry.m_exec_addr == CustEntry.m_exec_addr)&&
                  (JumpEntry.m_content_size == CustEntry.m_content_size)))
              {
                 status = BL_FUNET_ERROR_MBA_LANG_PACK_NOT_MATCH_ERROR ; 
              }
        }
     
    }

    return status;
    
}

/*This check perform  when only update MBA*/
BL_FUNET_ERROR_CODE bl_MBAPartialUpdateCheck()
{
    int i = 0;
    int validResource = 0;
    kal_uint32 targetJumpTblAddr = 0;
    kal_uint32 binJumpTblAddr = 0;
    MTK_Recource_Entry_V3* pTargetResEntry;
    MTK_Recource_Entry_V3* pBinResEntry;
    
    /*Get jump_tbl addr from header */
    for(i=0;  i<GFH_DL_PKG_EXTRA_INFO_COUNT; i++)
    {
       if(pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_type == JUMP_TABLE)
       {
          //Bootloader NOR address is start from 0x1xxxxxxx, we need to remap address from header
          targetJumpTblAddr = pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_start_addr |ROM_ADDR_MASK;
       }
    }

    /*Check jump_tbl on target match with header. If match, we can find GFH_FILE_INFO at this address*/
    if(GFH_FILE_INFO_IsValid((GFH_FILE_INFO_v1*)targetJumpTblAddr) != 0 || ((GFH_FILE_INFO_v1*)targetJumpTblAddr)->m_file_type !=JUMP_TABLE )
    {
       return BL_FUNET_ERROR_MBA_JUMP_TABLE_ADDR_NOT_MATCH_WITH_TARGET;
    }

    pTargetResEntry =   (MTK_Recource_Entry_V3*)(targetJumpTblAddr + sizeof(GFH_FILE_INFO_v1));


   bl_DL_Seek( pDl_Package_GFH->gfh_file_info.m_content_offset + pDl_IOT_HEADER->m_extra_info[bl_GetImgIdx(JUMP_TABLE)].m_bin_offset , 0);        
   bl_DL_Read(jump_tbl_buf, JUMP_TBL_LEN);

   binJumpTblAddr =(kal_uint32)jump_tbl_buf;


        
    //get first Res_ENTRY in jump_tbl
    pBinResEntry    =   (MTK_Recource_Entry_V3*)(binJumpTblAddr + sizeof(GFH_FILE_INFO_v1));

    /*Important: When partial update, we assume the binary sequece in image.bin and target is the same, lang_pack -> cust_pack -> jump_tbl*/
    /*Check Resoure entry with target and binary*/
    for(i=0; i < RESOURCE_ENTRY_NUM; i++, pTargetResEntry++, pBinResEntry++)
    {
        /*Check is valid entry */
        if(pTargetResEntry->m_base_addr  == 0 )
        {
            if(pBinResEntry->m_base_addr == 0)
                continue;
            else
                return BL_FUNET_ERROR_MBA_ENRTY_VALID_CHECK_FAIL;
        }


        /*Check base address for only index0(Lang_pack), we assume index0 is the first MBA in the flash*/
        if(  i == 0 && pTargetResEntry->m_base_addr != pBinResEntry->m_base_addr)
        {
            return BL_FUNET_ERROR_MBA_BASE_ADDR_CHECK_FAIL;
        }


        /*Check Resource_Type, m_compressed, m_existed,MBA version*/
        if(   pTargetResEntry->m_compressed != pBinResEntry->m_compressed
           || pTargetResEntry->m_res_type   != pBinResEntry->m_res_type
           || pTargetResEntry->m_existed    != pBinResEntry->m_existed 
           ||strncmp(pTargetResEntry->m_type_ver,pBinResEntry->m_type_ver, sizeof(pTargetResEntry->m_type_ver))!=0)
        {
            return  BL_FUNET_ERROR_MBA_INFO_NOT_MATCH;
        }

        /*Check rule when compressed is enabled*/
        if(pTargetResEntry->m_compressed == 1)
        {
            if(   pBinResEntry->m_compressed_size > pTargetResEntry->m_compressed_size
               || pBinResEntry->m_max_ram_size    > pTargetResEntry->m_max_ram_size)
            {
                return BL_FUNET_ERROR_MBA_COMPRESSED_RULE_CHECK_FAIL ;
            }
        }
              
    }

    return BL_FUNET_ERROR_NONE;
}


BL_FUNET_ERROR_CODE bl_VerifyPKGBody()
{
   /* Check the integrity of body of the DL package, and version by the way */
   BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;
   kal_uint32 currentPage = 0;
   kal_uint32 rominfo_addr = 0;
   kal_uint32 remainByte = 0;

   kal_uint32 pkgFC;
   kal_uint32 pkgPairedVer, romPairedVer;
   kal_uint8  pkgSWVer[64], romSWVer[64];
   kal_uint8  pkgPlatformId[128], romPlatformId[128];
   kal_uint32 romSearchBase = MAUI_ROM_START_ADDR;

   const kal_uint32 updateFreq = (im_file_size/page_size_with_spare) * 0.05; //Update progress bar every 5%

   if(bl_DL_Seek(currentPage*page_size_with_spare, 0) != 0)
   {
      return BL_FUNET_ERROR_PACKAGE_SEEK_FAIL;
   }

   if(custom_get_CDL_asymmetric_key_len())
   {
      bl_Alg_Hash_Init();

      //Hash the header
      bl_Alg_Hash_Append((kal_uint32)pDl_Package_GFH, sizeof(*pDl_Package_GFH));

      while(currentPage < im_file_size/page_size_with_spare)
      {

            
         status = bl_ReadXIMPage((kal_uint32)page_buffer, currentPage, 1, KAL_TRUE);

         if(status != BL_FUNET_ERROR_NONE)
         {
            return status;
         }

         //Update status
         if((currentPage % updateFreq) == 0)
         {
            BL_PRINT(LOG_DEBUG, ".");
            bl_UpdateProgress(VERIFY_PHASE, (currentPage*100/(im_file_size/page_size_with_spare)));
         }
         currentPage++;
      }
      
      remainByte = im_file_size % page_size_with_spare;

      if(remainByte!=0)
      {        
        bl_ReadXIMByte((kal_uint32)page_buffer, currentPage*page_size_with_spare, remainByte, KAL_TRUE);
      }

      bl_Alg_Hash_Finish((kal_uint32)hash_value, sizeof(hash_value));

      if( bl_DL_SignatureVerify(hash_value, sizeof(hash_value), pSignatureBegin+signatureLength/2, signatureLength/2) == KAL_FALSE )
      {
         BL_PRINT(LOG_WARN, "Invalid body signature\n\r");
         status = BL_FUNET_ERROR_INVALIDE_BODY_SIG;
      }

      BL_PRINT(LOG_DEBUG, "done\n\r");
   }

   /*Get IOT_FOTA_HEADER*/ 
    pDl_IOT_HEADER =  (const IOT_HEADER*)((kal_uint8*)decompression_buf+ (pDl_Package_GFH->gfh_file_info.m_content_offset));

   if(!codePartialUpdate)
   {

       //Load the info from T-flash (SV5)
       if(status == BL_FUNET_ERROR_NONE)
       {
          GFH_MAUI_INFO_v1 *pMauiInfo;
    	  
          status = bl_LoadpMauiGFHInfoInBIN();
          if(status != BL_FUNET_ERROR_NONE)
          {
             return status;
          }
          
          pMauiInfo = (GFH_MAUI_INFO_v1*)pMauiInfoInCard;

          pkgPairedVer = pMauiInfo->m_bl_maui_paired_ver;
          pkgFC = pMauiInfo->m_feature_combination;
          memcpy(pkgSWVer, pMauiInfo->m_project_id, sizeof(pkgSWVer));
          memcpy(pkgPlatformId, pMauiInfo->m_platform_id, sizeof(pkgPlatformId));

       }

       //Load the info from flash (rom)
       if(status == BL_FUNET_ERROR_NONE)
       {
          GFH_MAUI_INFO_v1 *pMauiInfoInTarget;      

#ifdef _NAND_FLASH_BOOTING_
          extern GFH_MAUI_INFO_v1 *bl_GetMAUIInfo(void);

          //If last CDL is failed. the GFH might be corrupted. Thus use the version in the MAUI info backuped in CBR.
          if(last_funet_fail_flag == KAL_TRUE)
          {
             //The UpdatingRecord should already be got successfully in bl_IsFUNETGoing()
             pMauiInfoInTarget = &(UpdatingRecord.m_maui_info);
          }
          else
          {  //There is no "Last update fail", thus get the maui info from GFH
             pMauiInfoInTarget = bl_GetMAUIInfo();
             
             //backup the maui info into global variable
             memcpy(&(UpdatingRecord.m_maui_info), pMauiInfoInTarget, sizeof(GFH_MAUI_INFO_v1));
          }
#else /* _NAND_FLASH_BOOTING_ */     
          kal_uint32 maui_addr = MAUI_ROM_START_ADDR;

          //If last FUNET is failed. the GFH might be corrupted.
          // Thus, we also backup GFH in Update info
          if(last_funet_fail_flag == KAL_TRUE)
          {

             status = bl_FUNET_ReadUI(sizeof(FUNET_Update_Info), flash_pmaui_gfh_buf, sizeof(flash_pmaui_gfh_buf),UI_PATH);
             if(status == BL_FUNET_ERROR_NONE)
             {

                 if(GFH_Find((U32)flash_pmaui_gfh_buf, GFH_MAUI_INFO, (void **)&pMauiInfoInTarget) != B_OK)
                 {
                     return BL_FUNET_ERROR_NO_ROM_GFH_MAUI_INFO_FOUND;
                 }
             	
             }
             else
             {
                 return status;
             }                           
          }
          else
          {  //There is no "Last update fail", thus get the maui info from GFH
             if(GFH_Find((U32)maui_addr, GFH_MAUI_INFO, (void **)&pMauiInfoInTarget) != B_OK)
             {
                return BL_FUNET_ERROR_NO_ROM_GFH_MAUI_INFO_FOUND;
             }
             //backup the flash pmaui gfh info into global variable
             memcpy(flash_pmaui_gfh_buf, (void*)maui_addr, page_size);
          }
             
#endif /* _NAND_FLASH_BOOTING_*/
            
          romPairedVer = pMauiInfoInTarget->m_bl_maui_paired_ver;
          memcpy(romSWVer, pMauiInfoInTarget->m_project_id, sizeof(romSWVer));
          memcpy(romPlatformId, pMauiInfoInTarget->m_platform_id, sizeof(romPlatformId));

       }
       
       //Check the info
       if(status == BL_FUNET_ERROR_NONE)
       {
          //Call customer's function to check

          //Paired version of BL must be matched the one in XIM

          if(romPairedVer == 0)
          {
             return BL_FUNET_ERROR_NO_ROM_INFO_FOUND;
          }
          if(pkgPairedVer == 0)
          {
             return BL_FUNET_ERROR_NO_PKG_ROM_INFO_FOUND;
          }

          if(pkgPairedVer != romPairedVer)
          {
             return BL_FUNET_ERROR_MISMATCHED_BL_PAIRED_VERION;
          }

          //Chech if the current BL can support the features in XIM
          
          if(CheckFeatureCompatibility(pkgFC) == KAL_FALSE)
          {
             return BL_FUNET_ERROR_INCOMPATIBLE_FEATURES;
          }

          //Check if this upgrade/downgrade is allowed. Cusomter can choose the criteria

          //Make sure they are all null-terminated
          pDl_Package_GFH->gfh_dl_package_info.m_project_id[sizeof(pDl_Package_GFH->gfh_dl_package_info.m_project_id)-1] = 0;
          pkgSWVer[sizeof(pkgSWVer)-1] = 0;
          romSWVer[sizeof(romSWVer)-1] = 0;

          if( custom_CDL_check_dl_package_version(romSWVer, pkgSWVer, pDl_Package_GFH->gfh_dl_package_info.m_project_id) == KAL_FALSE )
          {
             return BL_FUNET_ERROR_MISMATCH_DLPKG_SW_VER;
          }

          //Make sure they are all null-terminated
          pDl_Package_GFH->gfh_dl_package_info.m_platform_id[sizeof(pDl_Package_GFH->gfh_dl_package_info.m_platform_id)-1] = 0;
          pkgPlatformId[sizeof(pkgPlatformId)-1] = 0;
          romPlatformId[sizeof(romPlatformId)-1] = 0;

          if( custom_CDL_check_dl_platform_id(romPlatformId, pkgPlatformId, pDl_Package_GFH->gfh_dl_package_info.m_platform_id) == KAL_FALSE )
          {
             return BL_FUNET_ERROR_MISMATCH_DLPKG_PLATFORM_ID;
          }

          if( custom_CDL_customer_info_check((kal_uint32*)&pDl_Package_GFH->gfh_dl_package_info.m_customer_info, sizeof(pDl_Package_GFH->gfh_dl_package_info.m_customer_info)) != KAL_TRUE)
          {
             return BL_FUNET_ERROR_CUSTOM_CHECK_FAIL;
          }
       }
   } //if(!codePartialUpdate)

   /*If it is partial, check MBA dependency rule*/
   if(status == BL_FUNET_ERROR_NONE & mbaUpdate)
   {
     status = bl_MBABinaryCheck();
   }
   
   if( status == BL_FUNET_ERROR_NONE && codePartialUpdate)
   {
     status = bl_MBAPartialUpdateCheck();
   }

   return status;
}

void bl_ShowFUNETSuccess(void)
{
// Raymond : LCD related code, mark it now and you can remove it if it is really unnecessary	
/*#if defined(__LCD_DRIVER_IN_BL__)
   BL_ShowUpdateFirmwareOK();
#endif*/ /* __LCD_DRIVER_IN_BL__ */
}

void bl_ShowFUNETError(BL_FUNET_ERROR_CODE status)
{
// Raymond : LCD related code, mark it now and you can remove it if it is really unnecessary
/*
#if defined(__LCD_DRIVER_IN_BL__)
   kal_uint32 i;

   typedef struct {
      BL_FUNET_ERROR_CODE error_start;
      BL_FUNET_ERROR_CODE error_end;
      kal_uint16 rgb[3];
   } ERROR_MAP;

   const ERROR_MAP error_map[] =
   {
      {BL_FUNET_ERROR_INVALID_XIM_START,          BL_FUNET_ERROR_INVALID_XIM_END,           {255, 255,   0} }, //Yellow
      {BL_FUNET_ERROR_VERSION_ERROR_START,        BL_FUNET_ERROR_VERSION_ERROR_END,         {255,   0, 255} }, //Purple
      {BL_FUNET_ERROR_ILB_ERROR_START,            BL_FUNET_ERROR_ILB_ERROR_END,             {  0, 255, 255} }, //Light blue
      {BL_FUNET_ERROR_UPDATE_ERROR_START,         BL_FUNET_ERROR_UPDATE_ERROR_END,          {255,   0,   0} }, //Red
      {BL_FUNET_ERROR_PACKAGE_ACCESS_ERROR_START, BL_FUNET_ERROR_PACKAGE_ACCESS_ERROR_END,  {  0,   0, 255} }, //Blue
      {BL_FUNET_ERROR_FLASH_ERROR_START,          BL_FUNET_ERROR_FLASH_ERROR_END,           {  0, 255,   0} }, //Green
   };

   if(status == BL_FUNET_ERROR_NONE)
   {
      return;
   }

   bl_DL_InitLCD();

   for(i=0; i<sizeof(error_map)/sizeof(*error_map); i++)
   {
      if(status <= error_map[i].error_start && status >= error_map[i].error_end)
      {
         BL_ShowUpdateFirmwareFail(error_map[i].rgb[0], error_map[i].rgb[1], error_map[i].rgb[2]);
         return;
      }
   }

   //Other erros
   BL_ShowUpdateFirmwareFail(0, 0, 0);
#endif*/ /* __LCD_DRIVER_IN_BL__ */

}

BL_FUNET_ERROR_CODE bl_UpdateMain(kal_bool forcedExec)
{
   BL_FUNET_ERROR_CODE status = BL_FUNET_ERROR_NONE;

   BL_PRINT(LOG_DEBUG, "%x\n\r", (&Image$$EXT_BL_IOT_FOTA_WORKING_BUF$$ZI$$Base)); 
   BL_PRINT(LOG_DEBUG, "%x\n\r", (&Image$$EXT_BL_IOT_FOTA_IMAGE_BUF$$ZI$$Base));
   BL_PRINT(LOG_DEBUG, "%x\n\r", (&Image$$EXT_BL_IOT_FOTA_DECOMPRESSION_BUF$$ZI$$Base));
   /*Init memory buffer*/   
   decompress_work_buf = (kal_uint8 *)(&Image$$EXT_BL_IOT_FOTA_WORKING_BUF$$ZI$$Base);
   image_buf = (kal_uint8 *)(&Image$$EXT_BL_IOT_FOTA_IMAGE_BUF$$ZI$$Base);
   decompression_buf = (kal_uint8 *)(&Image$$EXT_BL_IOT_FOTA_DECOMPRESSION_BUF$$ZI$$Base);
     
#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
#endif

   BL_PRINT(LOG_DEBUG, "Acessing T-FLASH...\n\r");
   //Step1. Open update file
   status = bl_DL_Open(DUMMY_FILENAME);
   
    /*IOT FOTA copy image to ram for decompressed*/
   if(status == BL_FUNET_ERROR_NONE)
   {
       //step1.1 copy update file from fs to ram, decompressed it if needed
      status = bl_readFiletoRam();
   }
   
   if(status != BL_FUNET_ERROR_NONE)
   {
        BL_PRINT(LOG_DEBUG, "Copy From Flash to RAM failed...%d\n\r", status);
        bl_DL_Close();
        return status;
   }
    
   if(status == BL_FUNET_ERROR_NONE)
   {
      //Step2. Check if valid PKG file exists
      status = bl_LoadAndCheckPKGHeader();
   }
   else
   {
      BL_PRINT(LOG_DEBUG, "Open T-FLASH failed...%d\n\r", status);
   }

   if(status == BL_FUNET_ERROR_NO_CARD_FOUND || status == BL_FUNET_ERROR_NO_DL_PACKAGE_FOUND)
   {
      BL_PRINT(LOG_INFO, "No Card found or no update package found, %d\n\r", status);
      if(forcedExec)
      {
         bl_ShowFUNETError(status);
      }
      else
      {
         bl_ClearFUNETTrigger();
      }

      bl_DL_Close();

      return status;
   }

   BL_PRINT(LOG_INFO, "\n\r");

   //Step3. Integrity check
   if(status == BL_FUNET_ERROR_NONE)
   {
      bl_UpdateProgress(VERIFY_PHASE, 0);
      BL_PRINT(LOG_INFO, "[Check header]\n\r");
      status = bl_ParseAndVerifyPKGHeader();
      if(status != BL_FUNET_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "Update Package Herader is bad...%d\n\r", status);
      }
   }

   if(status == BL_FUNET_ERROR_NONE)
   {
      BL_PRINT(LOG_INFO, "[Check body]\n\r");
      status = bl_VerifyPKGBody();
      if(status != BL_FUNET_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "Update Package Body is bad...%d\n\r", status);
      }
   }

#ifdef __BAD_BLOCK_EMULATION__

   if(status == BL_FUNET_ERROR_NONE)
   {
      extern flash_info_2 Flash_Info;
      kal_uint32 totalBlock = Flash_Info.deviceInfo_CE[0].deviceSize*1024/(block_size/1024);
      bl_MakeBadBlockTable(ilbStart, ilbEnd, ilbEnd+1, totalBlock-1);
   }

#endif

   //Step4.0 Init flash driver and check device status
   if(status == BL_FUNET_ERROR_NONE)
   {
      if(g_ftlFuncTbl->FTL_Init(NULL) != FTL_SUCCESS)
      {
         status = BL_FUNET_ERROR_FLASH_INIT_FAIL;
      }

      if(status != BL_FUNET_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "Init FTL is failed...%d\n\r", status);
      }

   }

   if(status == BL_FUNET_ERROR_NONE)
   {
      status = bl_CheckFlashDeviceStatus();
      if(status != BL_FUNET_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "Check falsh device is failed..%d\n\r", status);
      }

   }
    //return status;
   //Step4.1 Start to updating
   if(status == BL_FUNET_ERROR_NONE)
   {
      BL_PRINT(LOG_INFO, "[Initiate update]\n\r");
      status = bl_InitialUpdate();
      if(status != BL_FUNET_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "Initial Update is failed...%d\n\r", status);
      }
   }

   if(status == BL_FUNET_ERROR_NONE)
   {
      if(pDl_Package_GFH->gfh_dl_package_info.m_reserve1[0] & 0x02)
      {
         kal_uint32 i,j;

#ifdef _NAND_FLASH_BOOTING_
         i = (BL_Shared_info.m_bl_flash_layout.region[0].u.nandEmmc.startPage)/page_per_block;
         j = pDl_Package_Nand_Image_Header->plane_size*1024/pDl_Package_Nand_Image_Header->block_size-1;
         
         BL_PRINT(LOG_INFO, "Erase all availalbe blocks, from %d to %d ", i, j);

         for(; i<j; i++)
         {
            bl_EraseAndMarkBad(i, NULL);
            BL_PRINT(LOG_INFO, ".");
         }

#else /* _NAND_FLASH_BOOTING_ */
         kal_uint32 start = MAUI_ROM_START_ADDR;
         kal_uint32 length  = custom_get_NORFLASH_Size();
         kal_int32  endBlock = bl_AddrToBlockIdx(start+length-1, NULL);

         BL_PRINT(LOG_INFO, "Erase all availalbe blocks, from 0x%x to 0x%x ", start, start+length);

         for(i=bl_AddrToBlockIdx(start, NULL); i<endBlock; i++);
         {
            bl_EraseAndMarkBad(i, NULL);
            BL_PRINT(LOG_INFO, ".");
         }

#endif /* _NAND_FLASH_BOOTING_ */

         BL_PRINT(LOG_INFO, "done\n\r");
      }

      bl_UpdateProgress(UPDATE_PHASE, 0);
      BL_PRINT(LOG_INFO, "[Perform update]\n\r");

      status = bl_DoUpdate();
      if(status != BL_FUNET_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "DoUpdate Body is failed...%d\n\r", status);
      }

   }

   //Step5. Post-process and clean up
   if(status == BL_FUNET_ERROR_NONE)
   {
      bl_UpdateProgress(FINISH_PHASE, 0);

#ifdef _NAND_FLASH_BOOTING_
      BL_PRINT(LOG_WARN, "[Update image list block]\n\r");

      status = bl_UpdateImageInfo();

      if(status != BL_FUNET_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "Update Image Info is failed...%d\n\r", status);
      }

#endif /* _NAND_FLASH_BOOTING_ */
   }

   if(status == BL_FUNET_ERROR_NONE)
   {
      bl_UpdateProgress(FINISH_PHASE, 50);
      BL_PRINT(LOG_INFO, "[Clean up]\n\r");

      status = bl_FinishUpdate();
      if(status != BL_FUNET_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "Cannot finish...%d\n\r", status);
      }

   }
   /*Write update status to fs*/
   if(status == BL_FUNET_ERROR_NONE)
   {
      bl_UnMarkStatus();
   }else
   {
      bl_MarkStatus(status);
   }
  
   if(status == BL_FUNET_ERROR_NONE)
   {
      bl_UpdateProgress(FINISH_PHASE, 100);
      bl_ShowFUNETSuccess();
      bl_DL_Close();

      ClrRetnFlag(RETN_FUNET_FULL_DL_EN | RETN_FUNET_PARTIAL_DL_EN);
      BL_PRINT(LOG_INFO, "[FUNET] Update done, reboot now ...\n\r");
      SetWDTNormalResetFlag();
      WatchDogResetAll();      
   }
   else
   {
      ClrRetnFlag(RETN_FUNET_FULL_DL_EN | RETN_FUNET_PARTIAL_DL_EN);
      BL_PRINT(LOG_ERROR, "***Something wrong during update, status=%d\n\r", status);
      SetWDTNormalResetFlag();
      WatchDogResetAll();      
   }

   return status;
}

#endif /* __EXT_BOOTLOADER__ */

#endif /* __FUNET_ENABLE__ &&  __SV5_ENABLED__ */


