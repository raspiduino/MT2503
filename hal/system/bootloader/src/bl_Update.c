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
 *   bl_Update.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __CARD_DOWNLOAD__

#define STATIC

#include <string.h>
#include <bl_types.h>
#include <bl_init.h>
#include <bl_common.h>
#include <bl_features.h>
#include <bl_loader.h>
#include <msdc_adap_bl.h>
#include "bl_update.h"
#include "dcl.h"
#include "ftl.h"
#include "kbd_table.h"
#include "drvpdn.h"

#if defined(_NAND_FLASH_BOOTING_)
#include <nand_fdm.h>
#endif

#ifdef __FS_CARD_DOWNLOAD__
#include "fat_fs.h"
#endif /* __FS_CARD_DOWNLOAD__ */

#ifdef __SV5_ENABLED__
#include "cbr.h"
#include "br_GFH_parser.h"
#include "br_GFH_maui_info.h"
#include "br_GFH_flash_info.h"
#include "br_GFH_error.h"
#endif /* __SV5_ENABLED__ */

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
#define __CDL_SUPPORT_UPDATE_FAT__
#define __AUTO_START_CARD_DOWNLOAD__
#define __CDL_SUPPORT_BOOTCERT_V3__  //It can be removed if bootcert is put into ILB
#define __CDL_SUPPORT_BOOTCERT_V5__  //It can be removed if bootcert is put into CBR


#define TRIGGER_KEY               (DEVICE_KEY_DOWN) //This key is customizable. Please lookup kdb_table.h
#define HASH_LEN                  (20)
#define WORKING_BUF_LEN           (16*1024)     //Working buffer must larger than GFH + NFB Image header(image record at least)+signatures
#define MAX_BOOTCERT_LEN          (1024)        //1024 bytes
#define MAX_BOOTCERT_PAGE_NUM     (2)           //Smallest page size = 512 bytes, thus BOOTCERT will require 2 pages at most.

#ifdef _NAND_FLASH_BOOTING_
#define ASSERT_VALID_PARAM_IN_NAND_IMAEG_HEADER(x) if(!(x)) {BL_PRINT(LOG_ERROR, "bl_Update ASSERT @ %d\n\r", __LINE__); return BL_CD_ERROR_INVALID_PARAM_IN_NAND_IMAGE_HEADER;}
#endif
#define ASSERT_VALID_PARAM_IN_XIM_BODY(x)          if(!(x)) {BL_PRINT(LOG_ERROR, "bl_Update ASSERT @ %d\n\r", __LINE__); return BL_CD_ERROR_INVALID_PARAM_IN_XIM_BODY;}

#define DUMMY_FILENAME            "DUMMY"

//Phase definition for displaying progress bar
#define INIT_PHASE   0
#define VERIFY_PHASE 1
#define UPDATE_PHASE 2
#define FINISH_PHASE 3

#ifdef _NAND_FLASH_BOOTING_
//Indexes in image list
#define IL_REGIONINFO_HEAD_OFFSET      (0)
#define IL_REGIONINFO_TAIL_OFFSET      (1)

//Indexes in extra info
#define EXTRAINFO_PMAUI_IDX            (2)

//Indexes in NAND list
#define NANDLIST_PMAUI_IDX            (3)

//Indexes in nand image
#define XIM_IMAGE_BOOTLOADER_IDX       (0)
#define XIM_IMAGE_EXT_BOOTLOADER_IDX   (1)
#ifndef __SV5_ENABLED__
#define XIM_IMAGE_IMAGE_LIST_BLOCK_IDX (2)
#define XIM_MAUI_IDX                   (3)
#define GetSpaceidByNANDimgid(x)       (x - XIM_MAUI_IDX)          //x must larger than XIM_MAUI_IDX
#define GetILEidByNANDimgid(x)         (x - XIM_MAUI_IDX + ROMINFO_INDEX + 1)
#define GetExtraInfoidByNANDImgid(x)   (x - NANDLIST_PMAUI_IDX + EXTRAINFO_PMAUI_IDX)
#define GetExtraInfoidByILEid(x)       (x - (ROMINFO_INDEX + 1) + EXTRAINFO_PMAUI_IDX)
#else /* __SV5_ENABLED__ */
#define XIM_CBR_IDX                    (xim_cbr_index)
#define XIM_MAUI_IDX                   (xim_maui_index)
#define XIM_NAND_ADDED_NUM             (2)                       //boot_info and main_info
#define GetExtraInfoidByNANDimgid(x)   (x - XIM_NAND_ADDED_NUM)  //x must larger than XIM_MAUI_IDX
#define GetFlashLayoutidByNANDimgid(x) (x - XIM_MAUI_IDX)        //x must larger than XIM_MAUI_IDX
#endif /* __SV5_ENABLED__ */

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

#ifndef __SV5_ENABLED__

    kal_uint32 FS_Start_FB;
    kal_uint32 FS_Max_LB;
    kal_uint32 FS_Start_PB;
    kal_uint32 FS_FS_PBS;

#else /* __SV5_ENABLED__ */

    kal_uint32 IM_Ext_Ver;
    kal_uint32 reserve_1;
    kal_uint32 reserve_2;
    kal_uint32 reserve_3;

    kal_uint32 Boot_Info_Addr;
    kal_uint32 Main_Info_Addr;
    kal_uint32 Control_Info_Addr;
    kal_uint16 Boot_Info_Count;
    kal_uint16 Main_Info_Count;

#endif /* __SV5_ENABLED__ */

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
extern BOOTL_HEADER        BLHeader;
extern const kal_char      SUPER_BLOCK_PATTERN[];
extern const kal_uint32    IMAGE_LIST_BLOCK_TAIL_PATTERN[];
extern const kal_uint32    IMAGE_LIST_BLOCK_TEMP_PATTERN[];
extern const kal_uint32    IMAGE_LIST_BLOCK_BACKUP_PATTERN[];
extern const kal_uint32    IMAGE_LIST_BLOCK_FOTA_PATTERN[];
extern const kal_uint32    IMAGE_LIST_BLOCK_DLPKG_PATTERN[];
extern kal_bool CompareILBTailTag(const kal_uint32 *pTag1, const kal_uint32 *pTag2);
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

#ifdef __LCD_DRIVER_IN_BL__
extern void BL_LCDHWInit(void);
extern void BL_LCDSetBackLight(void);
extern void BL_ShowUpdateFirmwareInitBackground(void);
extern void BL_ShowUpdateFirmwareProgress(kal_uint16 percentage);
extern void BL_ShowUpdateFirmwareFail(kal_int32 r, kal_int32 g, kal_int32 b);
extern void BL_ShowUpdateFirmwareOK(void);
#endif /* __LCD_DRIVER_IN_BL__ */

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

static kal_uint32 dl_package_size = 0;
static kal_uint32 im_file_size = 0;

static kal_uint8 hash_value[HASH_LEN];

DL_PACKAGE_GFH *pDl_Package_GFH = NULL;

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

#ifndef __SV5_ENABLED__
// Buffer pointers for ILB pages
static kal_uint32 rominfo_page[CDL_MAX_PAGE_SIZE/4];
static kal_uint32 space_page[CDL_MAX_PAGE_SIZE/4];
static kal_uint32 imagelist_page[CDL_MAX_PAGE_SIZE/4];
static Nand_ImageList_S   *pImageList = NULL;
static Nand_ImageList_S   card_img_info;
#endif /* __SV5_ENABLED__ */

#else /* _NAND_FLASH_BOOTING_ */

kal_uint32 page_size = NOR_PAGE_SIZE;
static kal_uint32 page_size_with_spare = NOR_PAGE_SIZE;
static kal_uint32 mauiFirstBlock = 0;

#ifndef __SV5_ENABLED__
static kal_uint32 rominfo_buf[(NOR_PAGE_SIZE*2)>>2];   //Doulbe size for possible tag on the boundary
#else
static kal_uint32 flash_pmaui_gfh_buf[NOR_PAGE_SIZE>>2];
#endif

#endif /* _NAND_FLASH_BOOTING_ */

// SVx dependent variables
#ifdef __SV5_ENABLED__
static kal_uint32 pmaui_gfh_buf[CDL_MAX_PAGE_SIZE/4];
static FlashLayout flash_layout_info;
static Nand_ImageSpace_ST space_info;
static kal_uint32* pMauiInfoInCard; // It will point into pmaui_gfh_buf
static UPDATING_RECORD UpdatingRecord;
static kal_uint32 xim_cbr_index;
static kal_uint32 xim_maui_index;
#else
static kal_uint32 macr_buf[MAX_PAGE_SIZE_WITH_SPARE/4];
#endif /* __SV5_ENABLED__ */

static kal_uint32 image_count = 0;
static kal_uint32 fs_image_count = 0;
static kal_uint32 nand_image_header_len = 0;           //Length of NAND image header (excluding GFH)
static kal_uint32 header_block_count = 0;
static kal_uint32 extra_info_count = 0;

static kal_uint8 *pSignatureBegin = NULL;
static kal_uint32 signatureLength = 0;                 //2 signatures currently

static kal_uint32 codeRegionEndIndex = 0;

static kal_bool   last_cdl_fail_flag = KAL_FALSE;
static kal_bool   fsPartialUpdate = KAL_FALSE;
static kal_bool   codePartialUpdate = KAL_FALSE;
static kal_bool   ximFixedLayout = KAL_FALSE;        //If XIM is MBA is FOTA load, this flag will be raise

#if defined(__CDL_SUPPORT_BOOTCERT_V3__) || defined(__CDL_SUPPORT_BOOTCERT_V5__)
static kal_bool   isBootCertExist = KAL_FALSE;
#endif

#ifndef __SV5_ENABLED__
FTL_FuncTbl *g_ftlFuncTbl = &ftlFuncTbl;
#else
extern FTL_FuncTbl *g_ftlFuncTbl;
#endif

#ifdef __LCD_DRIVER_IN_BL__
static kal_bool lcd_inited = KAL_FALSE;
#endif /* __LCD_DRIVER_IN_BL__ */

#ifdef __FOTA_DM__
MTK_FOTA_ROM_Info_v1_ST fotaRomInfo;
#endif
/*************************************************************************
 * Declaration
 *************************************************************************/
BL_CD_ERROR_CODE bl_ReadXIMPage(kal_uint32 addr, kal_uint32 pageIdx, kal_uint32 page_count, kal_bool doHash);
STATIC kal_bool bl_IsValidBinInfoItem(GFH_DL_PACKAGE_EXTRA_INFO *pInfo);
STATIC kal_bool bl_IsMarkerFound(kal_uint32 mauiAddr);

#ifdef _NAND_FLASH_BOOTING_
#ifndef __SV5_ENABLED__
STATIC kal_uint32 bl_GetILBStart();
STATIC kal_uint32 bl_GetILBEnd();
BL_CD_ERROR_CODE bl_ScanILBArea(kal_uint32 ilbAreaStart, kal_uint32 ilbAreaEnd, kal_uint32 *pMainILB, kal_uint32 *pDlPkgILB);
#endif /* _NAND_FLASH_BOOTING_ */
#endif /* __SV5_ENABLED__ */

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

#ifdef __FS_CARD_DOWNLOAD__

static FS_HANDLE bl_fs_handle;             //For keeping the file handle got from FS
static kal_int32 bl_fs_seek_pointer;       //For record the file position during cardDL
static kal_uint32 msdc_inited = KAL_FALSE; //For checking if the msdc is inited


/***************************************************************************//**
 * @brief The interface for card DL to open file with File system existed.
 * 
 * This function is not alowed to be re-entrant. The API will init HW driver and open specific file
 * once be called.
 *
 * @param[in] filename    It is not used yet. Reserved the flexibility for future.
 *
 * @return  The error code. If the error code from FS is not recognizable, it just return
 *                the error code from FS.
 *
 ******************************************************************************/
kal_int32 bl_DL_Open(const kal_char *filename)
{

   if(msdc_inited == KAL_FALSE)
   {
   
#ifndef __OLD_PDN_ARCH__
#if defined(__DRV_SUPPORT_LPWR__)
 DRVPDN_Disable(PDN_DMA);
#else
 PDN_CLR(PDN_DMA);
#endif
#endif

      //Initialize the MS/SD host controller, It should be called only once at drv_init, or one BL stage.
      BL_MSDC_Init();
      msdc_inited = KAL_TRUE;
   }

   //Try to mount MSDC here to detect early msdc issue.
   //FS_Open() might also try to mount the device, but it will return directly if the first mount is already success.
   if(BL_MSDC_MountDevice(0, 0, 0) != 512)
   {
      BL_MSDC_DeInit();
      return BL_CD_ERROR_NO_CARD_FOUND;
   }   

   //The drive letter will be taken by FS and always be redirect to the correct card drive
   //Thus we can use any drive letter here
   bl_fs_handle = FS_Open(L"e:\\image.bin", 0);

   //Check the result of FS API, and convert it to BL error code
   if(bl_fs_handle >= FS_NO_ERROR)
   {
      return BL_CD_ERROR_NONE;
   }
   else if(bl_fs_handle == FS_DRIVE_NOT_FOUND)
   {
      return BL_CD_ERROR_NO_CARD_FOUND;
   }
   else if(bl_fs_handle == FS_FILE_NOT_FOUND)
   {
      return BL_CD_ERROR_NO_DL_PACKAGE_FOUND;
   }
   else //Something wrong in FS, just return the error code from FS
   {
      return bl_fs_handle;
   }
}


/***************************************************************************//**
 * @brief The interface for card DL to seek file with File system existed.
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
kal_int32 bl_DL_Seek(kal_uint32 offset, kal_int32 origin)
{
   ASSERT(origin == 0);
   
   bl_fs_seek_pointer = FS_Seek(bl_fs_handle, offset, FS_FILE_BEGIN);

   //Check the result of FS API, and convert it to BL error code
   if(bl_fs_seek_pointer >= FS_NO_ERROR)
   {
      return BL_CD_ERROR_NONE;
   }
   else
   {
      return bl_fs_seek_pointer;
   }
}


/***************************************************************************//**
 * @brief The interface for card DL to read file with File system existed.
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
kal_uint32 bl_DL_Read(void *buffer, kal_uint32 len)
{
   kal_uint32 read; 
   kal_int32  status;

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


/***************************************************************************//**
 * @brief The interface for card DL to close file with File system existed.
 * 
 * This function will close the file handler for cardDL, and deinit msdc.
 *
 ******************************************************************************/
void bl_DL_Close()
{
   //Close the file
   if(bl_fs_handle)
   {
      FS_Close(bl_fs_handle);
   }

   //deinit msdc
   if(msdc_inited == KAL_TRUE)
   {
      BL_MSDC_DeInit();

      msdc_inited = KAL_FALSE;
   }
}


#else /* __FS_CARD_DOWNLOAD__ */

static kal_uint32 msdc_seek_pointer = 0;
static kal_uint32 msdc_buffer_offset = 0;
static kal_uint32 msdc_sector_size = 512;
static kal_uint32 msdc_sector_count = 0;
static kal_uint32 msdc_buffer[4*1024/4];      //Internal use by the DL package adaption layer
static kal_uint32 msdc_inited = KAL_FALSE;

kal_int32 bl_DL_Open(const kal_char *filename)
{
   kal_int32 ret;
   FS_PartitionRecord DiskGeometry;
   BYTE MediaDescriptor;

   ASSERT(sizeof(msdc_buffer)%msdc_sector_size == 0);

   if(msdc_inited == KAL_FALSE)
   {
#ifndef __OLD_PDN_ARCH__
#if defined(__DRV_SUPPORT_LPWR__)
   DRVPDN_Disable(PDN_DMA);
#else
   PDN_CLR(PDN_DMA);
#endif
#endif

      BL_MSDC_Init();
      msdc_inited = KAL_TRUE;
   }

   if(BL_MSDC_MountDevice(0, 0, 0) != 512)
   {
      BL_MSDC_DeInit();
      return BL_CD_ERROR_NO_CARD_FOUND;
   }

   ret = BL_MSDC_GetDiskGeometry(&DiskGeometry, &MediaDescriptor);

   if(ret != 0)
   {
      BL_PRINT(LOG_CRIT, "BL_MSDC_GetDiskGeometry failed, ret=%d\n\r", ret);
      BL_MSDC_DeInit();
      return BL_CD_ERROR_MSDC_GET_DISK_GEO;
   }

   msdc_seek_pointer = 0;
   msdc_buffer_offset = INVALID_OFFSET;
   msdc_sector_size = 512;
   msdc_sector_count = DiskGeometry.Sectors;
   return 0;
}

kal_int32 bl_DL_Seek(kal_uint32 offset, kal_int32 origin)
{
   ASSERT(origin == 0);
   if(msdc_seek_pointer >= msdc_sector_size*msdc_sector_count)
   {
      return -1;
   }
   msdc_seek_pointer = offset;
   return 0;
}

kal_uint32 bl_DL_Read(void *buffer, kal_uint32 len)
{
   kal_uint8 *pBuf = buffer;
   kal_uint32 toRead = len;

   while(1)
   {
      if(msdc_buffer_offset != INVALID_OFFSET && msdc_seek_pointer >= msdc_buffer_offset)
      {
         kal_uint32 inbuf_offset = msdc_seek_pointer-msdc_buffer_offset;
         if(inbuf_offset < sizeof(msdc_buffer))
         {
            kal_uint32 n = MIN(sizeof(msdc_buffer)-inbuf_offset, toRead);
            memcpy(pBuf, ((kal_uint8*)msdc_buffer)+inbuf_offset, n);
            msdc_seek_pointer += n;
            pBuf += n;
            toRead -= n;
         }
      }

      if(toRead)
      {
         kal_uint32 start_sector = msdc_seek_pointer/msdc_sector_size;
         kal_int32 msdc_driver_status;

#if defined (__TRANSMISSION_DEBUG__)
         kal_uint32 i;
         for(i=0; i<sizeof(msdc_buffer)/4; i++)
            ((kal_uint32*)(msdc_buffer))[i] = msdc_seek_pointer;
#endif /* defined (__TRANSMISSION_DEBUG__) */

         msdc_driver_status = BL_MSDC_ReadSectors(start_sector, sizeof(msdc_buffer)/msdc_sector_size, msdc_buffer);

         if(msdc_driver_status != 0)
         {
            msdc_buffer_offset = INVALID_OFFSET;
            return 0;

         }
         msdc_buffer_offset = start_sector*msdc_sector_size;
      }
      else
      {
         break;
      }
   }

   return len;
}

void bl_DL_Close()
{
   if(msdc_inited == KAL_TRUE)
   {
      BL_MSDC_DeInit();

      msdc_inited = KAL_FALSE;
   }
}

#endif /* __FS_CARD_DOWNLOAD__ */

/*************************************************************************
 * Public interface
 *************************************************************************/

/**********************************************************
Description : To tell if CDL is under processing
Input       : None
Output      : None
***********************************************************/
kal_bool bl_IsCardDownloadGoing()
{

#ifndef _NAND_FLASH_BOOTING_

   if( bl_IsMarkerFound(MAUI_ROM_START_ADDR) )
   {
      BL_PRINT(LOG_DEBUG, "Last Card Download is failed. Re-download Now...\n\r");
      last_cdl_fail_flag = KAL_TRUE;
      return KAL_TRUE;
   }

#else /* _NAND_FLASH_BOOTING_ */

#ifdef __SV5_ENABLED__
   //Check if there is updating record
   if(CBR_GetRecordLen(E_CBR_IDX_CBR, CBR_RECORD_UPDATING_INFO)>0)
   {
      //Read the updating record
      if(CBR_ReadRecord(E_CBR_IDX_CBR, CBR_RECORD_UPDATING_INFO, (kal_uint8*)&UpdatingRecord, sizeof(UPDATING_RECORD), NULL) <= 0)
      {
         return KAL_FALSE;
      }

      //Check if the updating record is belong to CDL
      if(UpdatingRecord.m_info_type_magic == CDL_MARKER)
      {
         BL_PRINT(LOG_DEBUG, "Last Card Download is failed. Re-download Now...\n\r");
         last_cdl_fail_flag = KAL_TRUE;
         return KAL_TRUE;
      }
   }
#else /* __SV5_ENABLED__ */

   kal_uint32 mainILB = 0;
   kal_uint32 dlPkgILB = 0;

   //Init the FTL driver, because bl_ScanILBArea() will need to do read on flash
   if(g_ftlFuncTbl->FTL_Init(NULL) != FTL_SUCCESS)
   {
      return KAL_FALSE;
   }

   if(bl_ScanILBArea(bl_GetILBStart(), bl_GetILBEnd(), &mainILB, &dlPkgILB) != BL_CD_ERROR_NONE)
   {
      return KAL_FALSE;
   }

   if(dlPkgILB)
   {
      BL_PRINT(LOG_DEBUG, "Last Card Download is failed. Re-download Now...\n\r");
      last_cdl_fail_flag = KAL_TRUE;
      return KAL_TRUE;
   }

#endif /* __SV5_ENABLED__ */

#endif /* _NAND_FLASH_BOOTING_ */

   return KAL_FALSE;
}

kal_bool bl_CardDownloadTriggered()
{
#ifdef __AUTO_START_CARD_DOWNLOAD__
   return KAL_TRUE;
#else

   //Triggered by keypad
   if(BL_kbd_IsKeyPressed(TRIGGER_KEY))
   {
      return KAL_TRUE;
   }

   return KAL_FALSE;

#endif
}

void bl_ClearCardDownloadTrigger()
{
#ifdef __AUTO_START_CARD_DOWNLOAD__
#else
   //Clear dedicated flag if any
#endif
   return;
}

void bl_DetectPowerOff()
{
   //Query the power key, if it is pressed, do power off.
   //Exclude the key used for triggering card download
   if((BL_kbd_IsKeyPressed(DEVICE_KEY_POWER) || BL_kbd_IsKeyPressed(DEVICE_KEY_END))
   	 && !BL_kbd_IsKeyPressed(TRIGGER_KEY))
   {
      DCL_HANDLE pw_handle;
   	
      //Use dclpw to latch the power
      pw_handle=DclPW_Open(DCL_PW, FLAGS_NONE);
      DclPW_Control(pw_handle,PW_CMD_POWEROFF,NULL);
      DclPW_Close(pw_handle);
   }
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
      if(bl_ReadXIMPage((kal_uint32)page_buffer, page, 1, KAL_FALSE) != BL_CD_ERROR_NONE)
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
            if(bl_ReadXIMPage((kal_uint32)page_buffer, page, 1, KAL_FALSE) != BL_CD_ERROR_NONE)
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
BL_CD_ERROR_CODE bl_CheckFlashDeviceStatus()
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
            return BL_CD_ERROR_ADDRESS_OR_LENGTH_NOT_BLOCK_BOUNDARY;
         }
      }
   }
#endif

   return BL_CD_ERROR_NONE;
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
#ifdef __LCD_DRIVER_IN_BL__

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

#endif /* __LCD_DRIVER_IN_BL__ */
}



BL_CD_ERROR_CODE bl_UpdateProgress(kal_uint32 phase, kal_uint32 progress)
{
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
#ifdef __LCD_DRIVER_IN_BL__
      bl_DL_InitLCD();
      BL_ShowUpdateFirmwareProgress(totalProgress);
#endif /* __LCD_DRIVER_IN_BL__ */
      lastProgress = totalProgress;
   }

   return BL_CD_ERROR_NONE;
}

BL_CD_ERROR_CODE FTL_ERROR_TO_CD_ERROR(FTL_STATUS_CODE ftlErrorCode)
{
   switch(ftlErrorCode)
   {
   case FTL_SUCCESS:
   case FTL_ERROR_ECC_CORRECTED:
      return BL_CD_ERROR_NONE;

   case FTL_ERROR_READ_FAILURE:
      return BL_CD_ERROR_FLASH_READ;

   case FTL_ERROR_WRITE_FAILURE:
      return BL_CD_ERROR_FLASH_PROGRAM;

   case FTL_ERROR_ERASE_FAILURE:
      return BL_CD_ERROR_FLASH_ERASE;

   case FTL_ERROR_BAD_BLOCK:
      return BL_CD_ERROR_FLASH_BAD_BLOCK;

   }

   return BL_CD_ERROR_FLASH_OTHER_ERROR;
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

kal_int32 bl_GetGFHImgIdx(GFH_FILE_TYPE bin_type)
{
   kal_uint32 i;
   for(i = 0; i < GFH_DL_PKG_EXTRA_INFO_COUNT; i++)
   {
      if(pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_type == bin_type)
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

STATIC IM_OPERATION bl_ExtraInfoGetFSOperation(kal_uint32 fsIndex)
{
   kal_uint32 i, index = 0;
   GFH_DL_PACKAGE_INFO_v2 *pPkgInfo = &pDl_Package_GFH->gfh_dl_package_info;

   for(i=0; i<sizeof(pPkgInfo->m_extra_info)/sizeof(pPkgInfo->m_extra_info[0]); i++)
   {
      if(pPkgInfo->m_extra_info[i].m_bin_type == GFH_FILE_NONE)
      {
         break;
      }

      if(pPkgInfo->m_extra_info[i].m_bin_type >= V_FILE_SYSTEM_BINARY && pPkgInfo->m_extra_info[i].m_bin_type < V_FILE_SYSTEM_BINARY_END)
      {
         if(index == fsIndex)
         {
            return pPkgInfo->m_extra_info[i].m_operation;
         }
         index++;
      }
   }

   return IM_DOWNLOAD;
}

STATIC IM_OPERATION bl_QueryBinaryOperation(kal_uint32 addr)
{
   kal_uint32 i;

   GFH_DL_PACKAGE_INFO_v2 *pPkgInfo = &pDl_Package_GFH->gfh_dl_package_info;
   for(i=0; i<sizeof(pPkgInfo->m_extra_info)/sizeof(pPkgInfo->m_extra_info[0]); i++)
   {
      if(pPkgInfo->m_extra_info[i].m_bin_type == GFH_FILE_NONE)
      {
         break;
      }

      if(bl_IsValidBinInfoItem(&pPkgInfo->m_extra_info[i]) &&
         pPkgInfo->m_extra_info[i].m_bin_type >= V_FILE_SYSTEM_BINARY &&
         pPkgInfo->m_extra_info[i].m_bin_type <  V_FILE_SYSTEM_BINARY_END)
      {
         if(addr >= pPkgInfo->m_extra_info[i].m_bin_start_addr &&
            addr < pPkgInfo->m_extra_info[i].m_bin_start_addr + pPkgInfo->m_extra_info[i].m_bin_length)
         {
            return pPkgInfo->m_extra_info[i].m_operation;
         }
      }
   }

   return IM_DOWNLOAD;
}


BL_CD_ERROR_CODE bl_ReadXIMPageX(kal_uint32 addr, kal_uint32 pageIdx, kal_uint32 page_count, kal_bool with_spare, kal_bool doHash)
{
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;
   kal_uint32 offset = pDl_Package_GFH->gfh_file_info.m_content_offset + pageIdx*page_size_with_spare;
   kal_uint32 read = 0;

   if(bl_DL_Seek(offset, 0) != 0)
   {
      return BL_CD_ERROR_PACKAGE_SEEK_FAIL;
   }

   while(status == BL_CD_ERROR_NONE && read < page_count)
   {
      if(bl_DL_Read((kal_uint32*)addr, page_size_with_spare) != page_size_with_spare)
      {
         status = BL_CD_ERROR_PACKAGE_READ_FAIL;
      }

      if(status == BL_CD_ERROR_NONE && doHash)
      {
         bl_Alg_Hash_Append(addr, page_size_with_spare);
      }

      addr += (with_spare ? page_size_with_spare : page_size);
      read++;
   }

   return status;
}


BL_CD_ERROR_CODE bl_ReadXIMPage(kal_uint32 addr, kal_uint32 pageIdx, kal_uint32 page_count, kal_bool doHash)
{
   return bl_ReadXIMPageX(addr, pageIdx, page_count, KAL_FALSE, doHash);
}

//Write one block from XIM body to flash, without spare, via DAL, auto-find good block
BL_CD_ERROR_CODE bl_WriteXimBlockToFlash(kal_uint32 ximBodyOffset, kal_uint32 flashBlockIdx, kal_uint32 *pWrittenBlockIdx, kal_uint32 *pinfo, kal_uint32 OffsetInImage)
{
   FTL_STATUS_CODE status = FTL_SUCCESS;
   kal_uint32 i;

   if( bl_DL_Seek(pDl_Package_GFH->gfh_file_info.m_content_offset + ximBodyOffset, 0) != 0)
   {
      return BL_CD_ERROR_PACKAGE_SEEK_FAIL;
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
            return BL_CD_ERROR_PACKAGE_READ_FAIL;
         }

#if defined(__TRANSMISSION_DEBUG__)
         crc = Update_CRC(crc, (kal_uint8*)page_buffer, page_size);
#endif /* defined (__TRANSMISSION_DEBUG__) */

#ifndef __SV5_ENABLED__
#if defined(__BIND_TO_CHIP_BASIC__) || defined(__BIND_TO_CHIP__) || defined(__BIND_TO_KEY__)
         if(pinfo)
         {
            SST_ContentPreprocess(pinfo, OffsetInImage, page_buffer, page_size);
         }
#endif
#endif /* __SV5_ENABLED__ */

#ifdef __FOTA_DM__
#ifdef _NAND_FLASH_BOOTING_
         if(g_maui_image_info_validity != MTK_MAUI_HEAD_INFO_VALID)
         {
            SSF_SearchMAUIImageHead((kal_uint8*)page_buffer, page_size, NULL, 0);
         }
#endif
#endif

         status = g_ftlFuncTbl->FTL_WritePage(flashBlockIdx, i, page_buffer, NULL);

         OffsetInImage += page_size;
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

   return FTL_ERROR_TO_CD_ERROR(status);
}


//Get SVx specific information
#ifndef __SV5_ENABLED__
#if defined(__BIND_TO_CHIP_BASIC__) || defined(__BIND_TO_CHIP__) || defined(__BIND_TO_KEY__)

extern kal_uint32* SST_GetMACRInfo(kal_uint32 *pRomInfo, kal_uint32 *pOffset, kal_uint32 *pLen);
extern void *SST_Search_MAUI_Rom_Info(kal_uint32 rom_base, kal_uint32 length);

BL_CD_ERROR_CODE bl_getMACRInfo(kal_uint32 pmauiOffset, kal_uint32** pinfo)
{
   kal_uint32* pMauiInfo = NULL;
   volatile kal_uint32 macr_Offset = 0; //Use volatile to notify compiler that it will be modified by other function
   volatile kal_uint32 macr_Len = 0;

#ifdef _NAND_FLASH_BOOTING_
   pMauiInfo = SST_Search_MAUI_Rom_Info((kal_uint32)rominfo_page, sizeof(rominfo_page));
#else /* _NAND_FLASH_BOOTING_ */
   pMauiInfo = SST_Search_MAUI_Rom_Info((kal_uint32)rominfo_buf, sizeof(rominfo_buf));
#endif /* _NAND_FLASH_BOOTING_ */
   
   if(pMauiInfo == NULL)
   {
      return BL_CD_ERROR_GET_ROMINFO_FAIL;
   }
   
   //Get the MACR of MAUI info. It is the preprocess of binding P-Image to chip.
   *pinfo = SST_GetMACRInfo(pMauiInfo, &macr_Offset, &macr_Len);     
   
   if(*pinfo == NULL)
   {     
      //macr_buf should reserve enough space
      if(macr_Len > sizeof(macr_buf));
      {
         return BL_CD_ERROR_INSUFFICIENT_MACR_BUF;
      }
   
      // TODO: check the offset
      if(bl_DL_Seek(pmauiOffset + macr_Offset, 0) != 0)
      {
         return BL_CD_ERROR_PACKAGE_SEEK_FAIL;
      }	  
   
      if(bl_DL_Read(macr_buf, macr_Len) != macr_Len)
      {
         return BL_CD_ERROR_PACKAGE_READ_FAIL;
      }
   
      *pinfo = macr_buf;
   }  

   return BL_CD_ERROR_NONE;
}

#endif /* defined(__BIND_TO_CHIP_BASIC__) || defined(__BIND_TO_CHIP__) || defined(__BIND_TO_KEY__) */

extern void bl_int_getFATregion(kal_uint32 *buf, kal_uint32* fat_addr, kal_uint32* fat_len);
extern void bl_int_getSDSregion(kal_uint32 *buf, kal_uint32* sds_addr, kal_uint32* sds_len);

void bl_getFATregion(kal_uint32 *buf, kal_uint32* fat_addr, kal_uint32* fat_len)
{
   bl_int_getFATregion(buf, fat_addr, fat_len);
}


void bl_getSDSregion(kal_uint32 *buf, kal_uint32* sds_addr, kal_uint32* sds_len)
{
   bl_int_getSDSregion(buf, sds_addr, sds_len);
}


#else /* __SV5_ENABLED__ */

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


#endif /* __SV5_ENABLED__ */


/*************************************************************************
 * Image updaters
 *************************************************************************/
#ifdef _NAND_FLASH_BOOTING_

kal_uint32 bl_GetSpareSize(kal_uint32 page_size)
{
   return page_size/32;
}

Nand_Update_Area_ST *bl_CDL_NewSpaceInfo(kal_uint32 n)
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
BL_CD_ERROR_CODE bl_Write3rdROMBlockToNand(kal_uint32 *p3rdROMMapTbl, kal_uint32 size, kal_uint32 flashBlockIdx, kal_uint32 *pWrittenBlockIdx)
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

   return FTL_ERROR_TO_CD_ERROR(status);
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
 * @return  BL_CD_ERROR_CODE
 *
 ******************************************************************************/
BL_CD_ERROR_CODE bl_ReadDataFromFlash(kal_uint32 *buf_ptr, kal_uint32 BlkNo, kal_int32 length, FTL_OptParam *opt_param)
{
   kal_uint32  pageNo = 0;
   kal_uint32  page_size = g_ftlFuncTbl->FTL_GetPageSize();
   //kal_uint32  page_per_block = g_ftlFuncTbl->FTL_GetBlockSize(0, KAL_FALSE)/page_size;
   kal_bool    goodBlockChecked = KAL_FALSE;

   if(length == 0)
   {
      return BL_CD_ERROR_NONE;
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
            return BL_CD_ERROR_FLASH_READ;
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
            return BL_CD_ERROR_FLASH_READ;
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

   return BL_CD_ERROR_NONE;
}


BL_CD_ERROR_CODE bl_DoUpdateMiscImg(kal_uint32 *pFlashBlockIdx, kal_uint32 imageIdx)
{
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;
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


BL_CD_ERROR_CODE bl_checkToEraseFat(kal_uint32 code_boundary_blk)
{
   kal_uint32 i,j;
   kal_uint32 start_addr, fat_len, flashBlockIdx, numBlktoErase;
   GFH_DL_PACKAGE_INFO_v2 *pPkgInfo = &pDl_Package_GFH->gfh_dl_package_info;
   kal_uint32 legal_fat_addr, legal_fat_len;
   kal_uint32 sds_addr, sds_len;
   kal_uint32 code_boundary_address;

#ifdef __SV5_ENABLED__
   bl_getFATregion(pmaui_gfh_buf, &legal_fat_addr, &legal_fat_len);
   bl_getSDSregion(pmaui_gfh_buf, &sds_addr, &sds_len);
#else
   bl_getFATregion(rominfo_page, &legal_fat_addr, &legal_fat_len);
   bl_getSDSregion(rominfo_page, &sds_addr, &sds_len);
#endif

   //Check if code region is overlapped with FAT region
   if(legal_fat_len != 0)
   {
      code_boundary_address = code_boundary_blk*block_size - 1;
      if((code_boundary_address >= legal_fat_addr) && (code_boundary_address < legal_fat_addr+legal_fat_len))
      {
         BL_PRINT(LOG_INFO, "Code-FAT overlap! last code address:%x, FAT address:%x, FAT len:%x\n\r\n\r", code_boundary_address, legal_fat_addr, legal_fat_len);
         return BL_CD_ERROR_CODE_FAT_OVERLAPED;
      }
   }   

   //Scan whole extra_info to get the file system entry
   for(i=0; i<sizeof(pPkgInfo->m_extra_info)/sizeof(pPkgInfo->m_extra_info[0]); i++)
   {
      if(pPkgInfo->m_extra_info[i].m_bin_type >= V_FILE_SYSTEM_BINARY && pPkgInfo->m_extra_info[i].m_bin_type < V_FILE_SYSTEM_BINARY_END)
      {
         //It only process the case that the operation is ERASE
         //Note that the given start adress and length should be block aligned
         if(pPkgInfo->m_extra_info[i].m_operation == IM_ERASE)
         {
            start_addr = pPkgInfo->m_extra_info[i].m_bin_start_addr;
            fat_len = pPkgInfo->m_extra_info[i].m_bin_length;

#ifdef __SECURE_DATA_STORAGE__
            //Check the earse range regard with SDS rage
            if(sds_len != 0)
            {
               if(bl_IsRegionOverlap(start_addr, fat_len, sds_addr, sds_len))
               {
                  BL_PRINT(LOG_INFO, "SDS can't be erased! SDS address:%x, SDS length:%x\n\r\n\r", sds_addr, sds_len);
                  return BL_CD_ERROR_EARSE_SDS;
               }
            }
#endif /* __SECURE_DATA_STORAGE__ */

            flashBlockIdx = (start_addr+block_size-1)/block_size; //make sure the start address is block aligned
            numBlktoErase = fat_len/block_size;

            BL_PRINT(LOG_DEBUG, "Start to Erase FAT region %d from %x, len=%x\n\r", i, start_addr, fat_len);

            for(j=flashBlockIdx; j<flashBlockIdx+numBlktoErase; j++)
            {
               BL_PRINT(LOG_DEBUG, "%d, ", j);

               bl_EraseAndMarkBad(j, NULL);
            }

            BL_PRINT(LOG_INFO, "Erase FAT %d done\n\r\n\r", i);
         }
      }
   }

   //Do nothing even bad block is found
   return BL_CD_ERROR_NONE;
}

#ifdef   __CDL_SUPPORT_UPDATE_FAT__

//Write REMAP buffer with spare from original REMAP block, without DAL, stop if bad block
BL_CD_ERROR_CODE bl_WriteNandRemapBlockToFS(kal_uint32 remapTblBlockIdx, kal_uint16 *remapTbl, kal_uint32 remapTblSize, kal_uint32 flashBlockIdx)
{
   FTL_STATUS_CODE status = FTL_SUCCESS;
   kal_uint32 i;
   kal_uint32 remapTblSizeToWrite = remapTblSize;
   FTL_OptParam opt_param = {KAL_TRUE, KAL_FALSE}; 

   if( bl_DL_Seek(pDl_Package_GFH->gfh_file_info.m_content_offset + remapTblBlockIdx*(block_size_with_spare), 0) != 0)
   {
      return BL_CD_ERROR_PACKAGE_SEEK_FAIL;
   }

   status = bl_EraseAndMarkBad(flashBlockIdx, &opt_param);

   for(i=0; status==FTL_SUCCESS && i<page_per_block; i++)
   {
      kal_uint32 toWrite = MIN(remapTblSizeToWrite, page_size);

      if(bl_DL_Read(page_buffer, page_size_with_spare) != page_size_with_spare)
      {
         return BL_CD_ERROR_PACKAGE_READ_FAIL;
      }

      memcpy(page_buffer, (kal_uint8*)remapTbl+i*page_size, toWrite);
      remapTblSizeToWrite -= toWrite;

      status = NFB_ProgramPhysicalPageWithSpareX(flashBlockIdx, i, page_buffer, ((kal_uint8*)page_buffer)+page_size, KAL_FALSE);
      if(status > 0)
      {
         if(status != page_size)
         {
            return BL_CD_ERROR_NFI_UNEXPECED_BEHAVIOR;
         }
         status = FTL_SUCCESS;
      }
   }

   if(status != FTL_SUCCESS)
   {
      if(status != FTL_ERROR_BAD_BLOCK)
      {
         BL_PRINT(LOG_CRIT, "Unknown flash error!!!!! %d\n\r", status);
      }
      g_ftlFuncTbl->FTL_MarkBadBlock(flashBlockIdx, &opt_param);
   }

   return FTL_ERROR_TO_CD_ERROR(status);
}

//Write NAND block to flash, with spare, without DAL, stop if bad block
BL_CD_ERROR_CODE bl_WriteNandBlockToFS(kal_uint32 ximBlockIdx, kal_uint32 flashBlockIdx)
{
   FTL_STATUS_CODE status = FTL_SUCCESS;
   kal_uint32 i;
   FTL_OptParam opt_param = {KAL_TRUE, KAL_FALSE}; 

   if( bl_DL_Seek(pDl_Package_GFH->gfh_file_info.m_content_offset + ximBlockIdx*(block_size_with_spare), 0) != 0)
   {
      return BL_CD_ERROR_PACKAGE_SEEK_FAIL;
   }

   status = bl_EraseAndMarkBad(flashBlockIdx, &opt_param);

   for(i=0; status==FTL_SUCCESS && i<page_per_block; i++)
   {
      if(bl_DL_Read(page_buffer, page_size_with_spare) != page_size_with_spare)
      {
         return BL_CD_ERROR_PACKAGE_READ_FAIL;
      }

      status = NFB_ProgramPhysicalPageWithSpareX(flashBlockIdx, i, page_buffer, ((kal_uint8*)page_buffer)+page_size, KAL_FALSE);
      if(status > 0)
      {
         if(status != page_size)
         {
            return BL_CD_ERROR_NFI_UNEXPECED_BEHAVIOR;
         }
         status = FTL_SUCCESS;
      }
   }

   if(status != FTL_SUCCESS)
   {
      if(status != FTL_ERROR_BAD_BLOCK)
      {
         BL_PRINT(LOG_CRIT, "Unknown flash error!!!!!\n\r", status);
      }
      g_ftlFuncTbl->FTL_MarkBadBlock(flashBlockIdx, &opt_param);
   }

   return FTL_ERROR_TO_CD_ERROR(status);
}


STATIC BLOCK_MAPPING_TABLE_ENTRY bl_GetMapEntry(kal_uint32 index)
{
   return map_tbl[index];
}

STATIC kal_uint32 bl_FindNextReplacement(kal_uint32 startIndex, kal_uint32 endIndex, kal_uint32 group, kal_uint32 *pPhysicalBlock)
{
   kal_uint32 i;
   BLOCK_MAPPING_TABLE_ENTRY entry;
   kal_int32 step = (endIndex>=startIndex) ? 1 : -1;

   endIndex += step;

   for(i=startIndex; i!=endIndex; i+=step)
   {
      entry = bl_GetMapEntry(i);
      if(entry.GroupNo == group)
      {
         if(pPhysicalBlock)
         {
            *pPhysicalBlock = entry.PhyBlkAddr;
            return i;
         }
      }
   }

   return 0;
}

BL_CD_ERROR_CODE bl_LoadBRMTFromIM(kal_uint32 BRMTXimIdx, kal_uint16 *pBRMT, kal_uint32 BRMTSize)
{
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;
   kal_uint32 toRead = BRMTSize;
   kal_uint32 pageIdx = BRMTXimIdx*page_per_block;
   kal_uint8 *pDst = (kal_uint8*)pBRMT;

   while(toRead)
   {
      kal_uint32 n = MIN(toRead, page_size);
      status = bl_ReadXIMPage((kal_uint32)page_buffer, pageIdx, 1, KAL_FALSE);
      if(status != BL_CD_ERROR_NONE)
      {
         return status;
      }
      memcpy(pDst, page_buffer, n);
      toRead -= n;
      pDst += n;
      pageIdx++;
   }

   return status;
}


BL_CD_ERROR_CODE bl_DoUpdateFilesystemRegion(kal_uint32 regionStartIdx, kal_uint32 *pNextRegionStartIdx, IM_OPERATION op)
{
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;

   REGION_PARAM_BLOCK_HEADER *pRegionBlock;

   FS_LAYOUT  fsLayout;

   kal_uint32 BRMTXimIdx;
   kal_uint32 dataBlockXimStart;
   kal_uint32 dataBlockNum;
   kal_uint32 fsBlockNum;
   kal_uint32 groupNum;
   kal_uint32 remapStartLogAddr;
   kal_uint32 BRMTSize;
   kal_uint32 reservedStartAddr;
   kal_uint32 reservedBlockNum;

   kal_uint32 flashBlockIdx;
   kal_uint16* pNextReservedBlock;

   kal_uint32 fsCount = 0;

   kal_uint32 FDMVer;
   kal_uint32 i = 0;
   kal_uint16 *pBRMT = (kal_uint16*)remap_tbl;
   kal_bool   totalBBMIm = KAL_FALSE;
   kal_bool   useBRMTonFlash = KAL_FALSE;
   kal_bool   BRMTUpdated = KAL_FALSE;

   kal_uint32 nextFs = 0;

   FTL_OptParam opt_param = {KAL_TRUE, KAL_FALSE}; 

   status = bl_ReadXIMPageX((kal_uint32)page_buffer, regionStartIdx*page_per_block, 1, KAL_TRUE, KAL_FALSE);

   if(status != BL_CD_ERROR_NONE)
   {
      return status;
   }

   pRegionBlock = (REGION_PARAM_BLOCK_HEADER*)page_buffer;

   //Sanity test
   ASSERT_VALID_PARAM_IN_XIM_BODY(sizeof(REGION_PARAM_BLOCK_HEADER) <= page_size_with_spare);
   ASSERT_VALID_PARAM_IN_XIM_BODY(pRegionBlock->PhyicalBlkNum < sizeof(remap_tbl)/2-8);
   ASSERT_VALID_PARAM_IN_XIM_BODY(pRegionBlock->BlockSize*1024 == block_size);
   ASSERT_VALID_PARAM_IN_XIM_BODY(pRegionBlock->PageSize == page_size);
   ASSERT_VALID_PARAM_IN_XIM_BODY(pRegionBlock->RPB_Size < sizeof(remap_tbl));
   ASSERT_VALID_PARAM_IN_XIM_BODY(pRegionBlock->RemapStartLogAddr*pRegionBlock->GroupNum == pRegionBlock->RvdBlkStartAddr);
   ASSERT_VALID_PARAM_IN_XIM_BODY(pRegionBlock->RvdBlkStartAddr+pRegionBlock->RvdBlkNum == pRegionBlock->PhyicalBlkNum);

   BRMTXimIdx        = regionStartIdx + pRegionBlock->RPB_Size;
   dataBlockXimStart = BRMTXimIdx + 1;
   dataBlockNum      = pRegionBlock->DataBlkNum;
   fsBlockNum        = pRegionBlock->PhyicalBlkNum;
   groupNum          = pRegionBlock->GroupNum;
   remapStartLogAddr = pRegionBlock->RemapStartLogAddr;
   BRMTSize          = pRegionBlock->BRMTSize;
   reservedStartAddr = pRegionBlock->RvdBlkStartAddr;
   reservedBlockNum  = pRegionBlock->RvdBlkNum;

   pNextReservedBlock= (kal_uint16*)(pBRMT + BRMTSize/sizeof(pBRMT[0]) - 8);

   //Find next region
   *pNextRegionStartIdx = dataBlockXimStart + dataBlockNum;

   if(sizeof(remap_tbl) < BRMTSize)
   {
      return BL_CD_ERROR_TOO_LARGE_BRMT;
   }

   //Load BRMT on IM file
   status = bl_LoadBRMTFromIM(BRMTXimIdx, pBRMT, BRMTSize);
   if(status != BL_CD_ERROR_NONE)
   {
      return status;
   }

   //Sanity test: IM's BRMT should be all zero in its remapping records
   {
      for(i=0; i<dataBlockNum; i++)
      {
         ASSERT_VALID_PARAM_IN_XIM_BODY(pBRMT[i] == 0);
      }
   }

   FDMVer = (*(kal_uint32*)(pNextReservedBlock - 18)) & FDMVER_MASK;
   ASSERT_VALID_PARAM_IN_XIM_BODY(FDMVer==FDMVER_205 || FDMVer==FDMVER_005 || (FDMVer&FDMVER_105_MASK)==FDMVER_105);

   //Check if total BBM enabled
   if(FDMVer == FDMVER_205)
   {
      totalBBMIm = KAL_TRUE;
   }

#ifdef __NANDFDM_TOTAL_BBM__
   if(!totalBBMIm)
   {
      return BL_CD_ERROR_NON_TOTALBBM_IM_ON_TOTALBBM_TARGET;
   }

   BL_PRINT(LOG_INFO, "TotalBBM enabled\n\r");

   //Sanity test: If total BBM is enabled, there should be only one visible filesystem area
   ASSERT_VALID_PARAM_IN_XIM_BODY(fs_image_count == 1);

   //Copy the flash layout out from the BRMT in the IM file
   memcpy(&fsLayout, pNextReservedBlock-50, sizeof(fsLayout));

   //Since the target is total BBM enabled, try to load existing BRMT on the flash
   {
      kal_uint32 retSize;
      kal_uint32 ret = FDM5_BLReadBRMT((kal_uint8*)pBRMT, sizeof(remap_tbl), &retSize);
      
      if(ret ==  BLBRMT_ERRCODE_NOERR)
      {
         //Check if the 2 BRMT are matched in their layout
         if(BRMTSize != retSize || memcmp(pNextReservedBlock-50, &fsLayout, sizeof(fsLayout)) != 0)
         {
            //Not allow only update some of file system when the layout is mismatched
            if(fsPartialUpdate)
            {
               return BL_CD_ERROR_MISMATCHED_BRMT;
            }

            //Leave useBRMTonFlash false since the layout is change and BRMT need to be refreshed
            BL_PRINT(LOG_WARN, "Mismatch BRMT, BRMT on flash will be completed overwritten\n\r");
            
            //Re-read the BRMT on IM
            status = bl_LoadBRMTFromIM(BRMTXimIdx, pBRMT, BRMTSize);
            if(status != BL_CD_ERROR_NONE)
            {
               return status;
            }
         }
         else
         {
            BL_PRINT(LOG_INFO, "Use BRMT on flash, partially updating on totalBBM FS enabled\n\r");
            useBRMTonFlash = KAL_TRUE;
         }
      }
      else if(ret == BLBRMT_ERRCODE_BRMT_NOT_FOUND)
      {
         if(fsPartialUpdate)
         {
            return BL_CD_ERROR_NEED_TO_UPDATE_ALL_FS;
         }
         
        // It's fine
        BL_PRINT(LOG_INFO, "No BRMT on flash, refresh \n\r");
      }
      else
      {
         BL_PRINT(LOG_ERROR, "Read BRMT failed, FDM error=%d\n\r", ret);
         return BL_CD_ERROR_READ_BRMT_FAIL;
      }
   }

   //Prepare filesystem layout
   {
      kal_uint32 base = fsLayout.fs[0].Base;

      for(i=0; i<sizeof(fsLayout.fs)/sizeof(fsLayout.fs[0]); i++)
      {
         if(fsLayout.fs[i].Base == 0 && fsLayout.fs[i].Size == 0)
         {
            break;
         }

         BL_PRINT(LOG_INFO, "fs[%d] = (%x, %d)\r\n", i, fsLayout.fs[i].Base, fsLayout.fs[i].Size);

         ASSERT_VALID_PARAM_IN_XIM_BODY(fsLayout.fs[i].Base % block_size == 0);
         ASSERT_VALID_PARAM_IN_XIM_BODY(fsLayout.fs[i].Size % block_size == 0);

         fsLayout.fs[i].Base -= base;
         fsLayout.fs[i].Base /= block_size;
         fsLayout.fs[i].Size /= block_size;

         if(i != 0)
         {
            ASSERT_VALID_PARAM_IN_XIM_BODY(fsLayout.fs[i-1].Base+fsLayout.fs[i-1].Size == fsLayout.fs[i].Base);
         }

         fsCount++;
      }
   }

   //The operation of total BBM IM is inside the filesystem, which will be looked up later
   op = IM_DOWNLOAD;

 #else
   if(totalBBMIm)
   {
      return BL_CD_ERROR_TOTALBBM_IM_ON_NON_TOTALBBM_TARGET;
   }
#endif /* __NANDFDM_TOTAL_BBM__ */


   if(useBRMTonFlash == KAL_FALSE)
   {
      for(i=0; i<groupNum; i++)
      {
         ASSERT(pNextReservedBlock[i]==remapStartLogAddr);  //Only for debug
         pNextReservedBlock[i] = remapStartLogAddr;
      }
   }

   //Load MAP table
   {
      kal_uint32 toRead = fsBlockNum*sizeof(BLOCK_MAPPING_TABLE_ENTRY);
      kal_uint32 pageIdx = regionStartIdx*page_per_block;
      kal_uint8 *pDst = (kal_uint8*)map_tbl;
      kal_uint32 offset = sizeof(REGION_PARAM_BLOCK_HEADER);

      while(toRead)
      {
         kal_uint32 n = MIN(toRead, page_size_with_spare-offset);
         status = bl_ReadXIMPageX((kal_uint32)page_buffer, pageIdx, 1, KAL_TRUE, KAL_FALSE);
         if(status != BL_CD_ERROR_NONE)
         {
            return status;
         }
         memcpy(pDst, (kal_uint8*)page_buffer+offset, n);
         offset = 0;
         toRead -= n;
         pDst += n;
         pageIdx++;
      }
   }

   //Check if the code region has been overlapped to file system due to too many bad blocks
   {
      //Use first entry of map table as the first logical block
      kal_uint32 fsLogicalStart = bl_PhyBlockIdx2Logical(map_tbl[0].PhyBlkAddr);
      if(fsLogicalStart == INVALID_BLOCK_IDX)
      {
         return BL_CD_ERROR_INVALID_FDM_MAPTBL;
      }
      if(fsLogicalStart < codeRegionEndIndex)
      {
         BL_PRINT(LOG_ERROR, "FS region (starting from %d) overlaps Code region (ended with %d) maybe due to too many badk block in bad block or invalid XIM file\n\r", fsLogicalStart, codeRegionEndIndex);
         return BL_CD_ERROR_CODE_FS_OVERLAPED;
      }
   }

   if(op == IM_SKIP)
   {
      BL_PRINT(LOG_INFO, "This region belongs to a filesystem which should be skiped\n\r");
      return BL_CD_ERROR_NONE;
   }

   //Erase all reserved block if we are not going to use the BRMT in the flash drive
   if(useBRMTonFlash == KAL_FALSE)
   {
      BL_PRINT(LOG_DEBUG, "=>Erase reserved block id=%d->%d: ", reservedStartAddr, reservedStartAddr+reservedBlockNum-1);
      for(i=0; i<reservedBlockNum; i++)
      {
         flashBlockIdx = bl_GetMapEntry(reservedStartAddr+i).PhyBlkAddr;

         if(flashBlockIdx == 0)
         {
            return BL_CD_ERROR_INVALID_XIM_CONTENT;
         }

         if(op == IM_DOWNLOAD || op == IM_ERASE)
         {
            BL_PRINT(LOG_DEBUG, "%d(P), ", flashBlockIdx);
            bl_EraseAndMarkBad(flashBlockIdx, &opt_param);
         }
      }
      BL_PRINT(LOG_DEBUG, "done\n\r");
   }

   BL_PRINT(LOG_DEBUG, "=>Writing data from fs_index=%d->%d: ", 0, dataBlockNum-1);

   //Write all data block to fs region
   for(i=0; i<dataBlockNum; i++)
   {
      kal_uint32 group;
      BLOCK_MAPPING_TABLE_ENTRY entry;

      //For total bbm, we have to distinguish the file system inside one IM binary, and get it's operation code
      if(totalBBMIm)
      {
         if(nextFs < fsCount && i == fsLayout.fs[nextFs].Base)
         {
            op = bl_ExtraInfoGetFSOperation(nextFs);
            BL_PRINT(LOG_INFO, "Switch total BBM fs=%d, op=%d\n\r", nextFs, op);
            nextFs++;
         }
      }

      entry = bl_GetMapEntry(i);
      flashBlockIdx = entry.PhyBlkAddr;
      group = entry.GroupNo;

      bl_UpdateProgress(UPDATE_PHASE, ((dataBlockXimStart+i)*page_per_block*100/(im_file_size/page_size_with_spare)));

      //When total BBM is enabled, bad blocks may have been remapped
      if(pBRMT[i])
      {
         kal_uint32 replaceIdx = pBRMT[i]*groupNum;

         entry = bl_GetMapEntry(replaceIdx);

         BL_PRINT(LOG_DEBUG, "Found existing bad remap block %d(P)->id %d, %d(P)\n\r", flashBlockIdx, replaceIdx, entry.PhyBlkAddr);

         flashBlockIdx = entry.PhyBlkAddr;
         ASSERT(group == entry.GroupNo);
      }

      while(1)
      {
         if(op == IM_DOWNLOAD)
         {
            BL_PRINT(LOG_DEBUG, "%d->%d(P), ", i, flashBlockIdx);

            status = bl_WriteNandBlockToFS(dataBlockXimStart+i, flashBlockIdx);
         }
         else if(op == IM_ERASE)
         {
            BL_PRINT(LOG_DEBUG, "%E %d(P), ", flashBlockIdx);

            bl_EraseAndMarkBad(flashBlockIdx, &opt_param);

            //Do nothing even bad block is found
            status = BL_CD_ERROR_NONE;
         }
         else if(op == IM_SKIP)
         {
            BL_PRINT(LOG_DEBUG, "S", flashBlockIdx);
            status = BL_CD_ERROR_NONE;
         }

         if(status == BL_CD_ERROR_NONE)
         {
            break;
         }
         else
         {
            kal_uint32 nextReplacementIdx;

            if(status != BL_CD_ERROR_FLASH_BAD_BLOCK)
            {
               BL_PRINT(LOG_CRIT, "Unexpected error when processing FS block to %d(P), status=%d\n\r", flashBlockIdx, status);
               return status;
            }

            nextReplacementIdx = bl_FindNextReplacement(pNextReservedBlock[group]*groupNum, fsBlockNum-1, group, &flashBlockIdx);

            if(!nextReplacementIdx)
            {
               BL_PRINT(LOG_ERROR, "Too many bad block to find a placement, failed to update\n\r");
               return BL_CD_ERROR_TOO_MANY_BAD_BLOCK;
            }

            BL_PRINT(LOG_DEBUG, "Found replacement @ id %d, %d(P)\n\r", nextReplacementIdx, flashBlockIdx);

            pBRMT[i] = nextReplacementIdx/groupNum;
            pNextReservedBlock[group] = nextReplacementIdx/groupNum+1;
            BRMTUpdated = KAL_TRUE;
         }
      }
   }
   BL_PRINT(LOG_DEBUG, "done\n\r");

   //Write BRMT block

   //When to write BRMT?
   //1. Total BBM + existing BRMT in FS + BRMT updated => FDM function
   //2. Total BBM + first time                         => Raw write
   //3. Non Total BBM                                  => Raw write


   if(totalBBMIm && useBRMTonFlash && BRMTUpdated)
   {
#ifdef __NANDFDM_TOTAL_BBM__
      kal_uint32 ret = FDM5_BLWriteBRMT((kal_uint8*)pBRMT, BRMTSize);
      BL_PRINT(LOG_DEBUG, "=>Update BRMT in the drive, ret=%d\n\r", ret);
      if(ret != BLBRMT_ERRCODE_NOERR)
      {
         return BL_CD_ERROR_WRITE_BRMT_FAIL;
      }
#endif /* __NANDFDM_TOTAL_BBM__ */      
   }
   else if((totalBBMIm == KAL_TRUE && useBRMTonFlash == KAL_FALSE) ||
           (totalBBMIm == KAL_FALSE) )
   {
      kal_uint32 remapBlockIdx;
      kal_uint32 remapReservedStart = pNextReservedBlock[0]*groupNum;
      kal_uint32 remapReservedEnd   = fsBlockNum-1;

      remapBlockIdx = bl_FindNextReplacement(remapReservedEnd, remapReservedStart, 0, &flashBlockIdx);
      remapReservedEnd--;

      while(1)
      {
         BL_PRINT(LOG_DEBUG, "=>Writing BRMT to %d(P)\n\r", flashBlockIdx);

         status = bl_WriteNandRemapBlockToFS(BRMTXimIdx, pBRMT, BRMTSize, flashBlockIdx);

         if(status == BL_CD_ERROR_NONE)
         {
            break;
         }
         else
         {
            if(status != BL_CD_ERROR_FLASH_BAD_BLOCK)
            {
               BL_PRINT(LOG_CRIT, "Unexpected error when writing BRMT to %d(P), status=%d\n\r", flashBlockIdx, status);
               return status;
            }

            remapBlockIdx = bl_FindNextReplacement(remapReservedEnd, remapReservedStart, 0, &flashBlockIdx);
            remapReservedEnd--;

            if(!remapBlockIdx)
            {
               BL_PRINT(LOG_ERROR, "Too many bad block to program BRMT, failed to update\n\r");
               return BL_CD_ERROR_TOO_MANY_BAD_BLOCK;
            }

            BL_PRINT(LOG_DEBUG, "Found replacement @ %d, %d(P)\n\r", remapBlockIdx, flashBlockIdx);
         }
      }
   }

   return BL_CD_ERROR_NONE;
}


BL_CD_ERROR_CODE bl_DoUpdateFilesystem(kal_uint32 imageIdx)
{
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;
   DL_PACKAGE_NAND_IMAGE_HEADER_IMG_RECORD *pImage = pFSImage + imageIdx;
   kal_uint32 regionStartIdx = pImage->start_block;
   kal_uint32 i;
   IM_OPERATION op = bl_ExtraInfoGetFSOperation(imageIdx);

   for(i=0; status==BL_CD_ERROR_NONE && regionStartIdx<pImage->start_block+pImage->blocks; i++)
   {
      BL_PRINT(LOG_INFO, "Updating region %d\n\r", i);
      status = bl_DoUpdateFilesystemRegion(regionStartIdx, &regionStartIdx, op);
   }

   return status;
}

#endif /*  __CDL_SUPPORT_UPDATE_FAT__ */

BL_CD_ERROR_CODE bl_ProcessFilesystem(kal_uint32 flashBlockIdx)
{
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;
   kal_uint32 i;
   
   //Check if it is want to erase FAT

   //The normal FAT erase function is only for the card download without FAT donwload functionality.
   //The fs_image_count is come from nand header. If user has no fs image for download,
   //there will be no fs image in nand header.
   //The normal FAT erase function just add a reacord in GFH header to notify CDL engine to do erase.
   //There will no fs image in nand header.
   if(0==fs_image_count)
   {
      status = bl_checkToEraseFat(flashBlockIdx);
   }
#ifdef   __CDL_SUPPORT_UPDATE_FAT__
   //The function for update FAT is only available when there is fs image in nand header.
   else if(0<fs_image_count)
   {
      codeRegionEndIndex = flashBlockIdx;

      for(i=0; i<fs_image_count; i++)
      {
         BL_PRINT(LOG_INFO, "Updating FS %d\n\r", i);

         status = bl_DoUpdateFilesystem(i);
         if(status != BL_CD_ERROR_NONE)
         {
            return status;
         }
         BL_PRINT(LOG_INFO, "Update of FS %d done\n\r\n\r", i);
      }
   }

#endif /* __CDL_SUPPORT_UPDATE_FAT__ */

   return status;

}

#ifndef __SV5_ENABLED__

Nand_ImageInfo_S *bl_GetCardImageInfo(kal_uint32 n)
{
   if (n < 10)
      return &(card_img_info.m_image[n]);
   else
      return &(card_img_info.m_image_ext[n-10]);
}


Nand_ImageInfo_S *bl_CDL_NewImageInfo(kal_uint32 n)
{
   if (n < 10)
      return &(pImageList->m_image[n]);
   else
      return &(pImageList->m_image_ext[n-10]);
}


/***************************************************************************//**
 * @brief Get the bin type by Image list index
 * 
 * This function mapped the ILE index into extra-info's index, and get the image type information
 * contained in extra-info.
 * Use the extra info to help checking the image type of ILE (image list entry).
 * Skip the images before pMAUI, since those image can not be mapped to ILE.
 * It assumes the oder of maui images are the same between ILE and extra info .
 *
 * @param[in] ile_id    The index in image list.
 *
 * @return  GFH_FILE_TYPE
 *
 ******************************************************************************/
GFH_FILE_TYPE bl_GetBinTypeByILEid(kal_uint32 ile_id)
{
   kal_int32  extra_info_id;
   GFH_DL_PACKAGE_INFO_v2 *pPkgInfo = &pDl_Package_GFH->gfh_dl_package_info;

   //map the id into extra info
   extra_info_id = GetExtraInfoidByILEid(ile_id);
   
   if((extra_info_id >= EXTRAINFO_PMAUI_IDX) && (extra_info_id < GFH_DL_PKG_EXTRA_INFO_COUNT))
   {
      return pPkgInfo->m_extra_info[extra_info_id].m_bin_type;
   }
   else
   {
      return GFH_FILE_NONE;
   }
}


GFH_FILE_TYPE bl_GetBinTypeByNANDImgid(kal_uint32 nand_img_id)
{
   kal_int32  extra_info_id;
   GFH_DL_PACKAGE_INFO_v2 *pPkgInfo = &pDl_Package_GFH->gfh_dl_package_info;

   //map the id into extra info
   extra_info_id = GetExtraInfoidByNANDImgid(nand_img_id);
   
   if((extra_info_id >= EXTRAINFO_PMAUI_IDX) && (extra_info_id < GFH_DL_PKG_EXTRA_INFO_COUNT))
   {
      return pPkgInfo->m_extra_info[extra_info_id].m_bin_type;
   }
   else
   {
      return GFH_FILE_NONE;
   }
}

#ifdef __CDL_SUPPORT_BOOTCERT_V3__

BL_CD_ERROR_CODE bl_backupBootCert(kal_uint32 blockidx, kal_uint32 pageidx)
{
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;
   kal_uint32 bootcertidx;
   kal_uint32 bootcertblk;
   kal_bool   isFlashHasBootCert = KAL_FALSE;
   kal_uint32 i;

   //Check if there is BootCert and is needed to be updated
   for(bootcertidx = 0; bootcertidx < BL_Shared_info.m_bl_image_list.m_image_count; bootcertidx++)
   {
      if(GetImageInfo(bootcertidx)->m_reserved == BCERT_ILE_MARKER)
      {
         isFlashHasBootCert = KAL_TRUE;
         break;
      }
   }

   if(isFlashHasBootCert && isBootCertExist)
   {
      bootcertblk = GetImageInfo(bootcertidx)->m_start_block;
      //Do backup BootCert
      for(i = 0; i <= MAX_BOOTCERT_PAGE_NUM; i++)
      {
         status = g_ftlFuncTbl->FTL_ReadPage(bootcertblk, i, page_buffer, NULL);

         if(status != FTL_SUCCESS)
         {
            return FTL_ERROR_TO_CD_ERROR(status);
         }
         
         status = g_ftlFuncTbl->FTL_WritePage(blockidx, pageidx+i, page_buffer, NULL);

         if(status != FTL_SUCCESS)
         {
            return FTL_ERROR_TO_CD_ERROR(status);
         }
      }
   }
   else if(!isFlashHasBootCert && !isBootCertExist)
   {  
      //There is no bootcert
      //return BL_CD_ERROR_NONE;
   }
   else
   {
      return BL_CD_ERROR_NO_BOOT_CERT_EXIST;
   }

   return status;
}


BL_CD_ERROR_CODE bl_restoreBootCert(kal_uint32 flashBlockIdx, kal_uint32 *pWrittenBlockIdx)
{
   FTL_STATUS_CODE status = FTL_SUCCESS;
   kal_uint32 i;
   kal_uint32 src_pageidx = page_per_block-MAX_BOOTCERT_PAGE_NUM-1;
   kal_uint32 mainILB = 0;
   kal_uint32 dlPkgILB = 0;

   bl_ScanILBArea(bl_GetILBStart(), bl_GetILBEnd(), &mainILB, &dlPkgILB);

   for(;; flashBlockIdx++)
   {
      //The MAX_BOOTCERT_LEN must not larger than block size
      if(MAX_BOOTCERT_LEN > g_ftlFuncTbl->FTL_GetBlockSize(flashBlockIdx, NULL))
      {
         return BL_CD_ERROR_BOOTCERT_EXCEED_BLOCKSIZE;
      }

      status = bl_EraseAndMarkBad(flashBlockIdx, NULL);

      if(status == FTL_ERROR_BAD_BLOCK)
      {
         continue;
      }

      for(i = 0; (status==FTL_SUCCESS) && (i<MAX_BOOTCERT_PAGE_NUM); i++)
      {
         status = g_ftlFuncTbl->FTL_ReadPage(dlPkgILB, src_pageidx+i, page_buffer, NULL);

         if(status != FTL_SUCCESS)
         {
            break;
         }
      
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

      break;
   }

   if(status == FTL_SUCCESS && pWrittenBlockIdx != NULL)
   {
      *pWrittenBlockIdx = flashBlockIdx;
   }

   return FTL_ERROR_TO_CD_ERROR(status);

}

#endif /* __CDL_SUPPORT_BOOTCERT_V3__ */

/***************************************************************************//**
 * @brief The function will extract some information and update to image list
 * 
 * This function will search the secinfo in p-maui and s-maui, then update their position into
 * image list
 *
 ******************************************************************************/
BL_CD_ERROR_CODE bl_PrepareImageList()
{
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE; 
   kal_uint32 img_idx, blk_idx;
   kal_int32  img_length;
   kal_uint32 load_offset;
   kal_uint32 blk_offset, badblk_count;
   kal_uint32 update_ile_idx;
   
   for(img_idx=0; img_idx<pImageList->m_image_count; img_idx++)
   {    
      //Check the condition to be updated
      if(bl_GetBinTypeByILEid(img_idx) == PRIMARY_MAUI)
      {
         update_ile_idx = IL_REGIONINFO_HEAD_OFFSET;
      }
      else if(bl_GetBinTypeByILEid(img_idx) == SECONDARY_MAUI)
      {
         update_ile_idx = IL_REGIONINFO_TAIL_OFFSET;
      }
      else
      {
         update_ile_idx = -1;
      }
   
      if((update_ile_idx == IL_REGIONINFO_HEAD_OFFSET) || (update_ile_idx == IL_REGIONINFO_TAIL_OFFSET))
      {               
         load_offset = bl_CDL_NewImageInfo(update_ile_idx)->m_load_addr - bl_CDL_NewImageInfo(img_idx)->m_load_addr;
         
         //calculate the theoretical block offset
         blk_offset = bl_CDL_NewImageInfo(img_idx)->m_start_block + (load_offset/block_size);

         img_length = bl_CDL_NewImageInfo(img_idx)->m_length;

         badblk_count = 0;  

         //Count the bad block before region_info to calculate the correct region_info block offset in flash
         for(blk_idx = bl_CDL_NewImageInfo(img_idx)->m_start_block; blk_idx <= blk_offset; blk_idx++)
         {
            status = g_ftlFuncTbl->FTL_CheckGoodBlock(blk_idx, NULL);
            
            if(status == FTL_ERROR_BAD_BLOCK)
            {
               badblk_count++;
            }
            else if(status != FTL_SUCCESS)
            {
               return status;
            }
         
            img_length -= block_size;
         }

         bl_CDL_NewImageInfo(update_ile_idx)->m_start_block = blk_offset + badblk_count;
         //m_reserved field is for record the offset in block
         bl_CDL_NewImageInfo(update_ile_idx)->m_reserved = load_offset % block_size;

      }
   }

   return status;
}


BL_CD_ERROR_CODE bl_DoUpdateMAUI(kal_uint32 *pFlashBlockIdx, kal_uint32 imageIdx, kal_uint32 *pInfo)
{
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;
   DL_PACKAGE_NAND_IMAGE_HEADER_IMG_RECORD *pImage = pMAUIImage+imageIdx;
   kal_uint32 i;
   kal_uint32 flash_max_block_num = 0;
   kal_uint32 flash_bound_block = pImage->max_block ? (*pFlashBlockIdx + pImage->max_block -1) : INVALID_BLOCK_IDX;
   kal_uint32 spaceInfoId = GetSpaceidByNANDimgid(imageIdx);
   kal_uint32 ILEid = GetILEidByNANDimgid(imageIdx);
   kal_uint32 *pRemapTbl = bl_isENFBImage(pImage) ? ((kal_uint32*)remap_tbl) : NULL;
   kal_bool   isBootCert = KAL_FALSE;

#ifdef __CDL_SUPPORT_BOOTCERT_V3__
   //Check if it is boot cert. Boot Cert need special proccessing
   if(bl_GetBinTypeByNANDImgid(imageIdx) == BOOT_CERT_CTRL)
   {
      isBootCert = KAL_TRUE;
   }
#endif /* __CDL_SUPPORT_BOOTCERT_V3__ */

   //Make sure the max_block is valid, except BootCert
   if((ximFixedLayout == KAL_TRUE) && (isBootCert == KAL_FALSE))
   {
      if(pImage->max_block == 0)
      {         
         return BL_CD_ERROR_INVALID_XIM_IMG_MAX_BLOCK_NUMBER;
      }
   }

   if(pImage->blocks*4 > sizeof(remap_tbl))
   {
      BL_PRINT(LOG_ERROR, "Block count=%d, large then %d\n\r", pImage->blocks, sizeof(remap_tbl)/4);
      return BL_CD_ERROR_3RDROM_REMAP_TBL_TOO_SMALL;
   }

   if(pRemapTbl)
   {  //It is 3rd ROM
      //Skip the first block for 3rd ROM. NAND XIM always put the mapping table at the first block.
      //But new rule is to put it at last. So skip first block in XIM's 3rd ROM, and write the table after all 3rd ROM data are written.
      pImage->start_block++;
      pImage->blocks--;

      //Find the true start page of 3rd-rom when doing partial update
      if(codePartialUpdate == KAL_TRUE)
      {
         //The block id of first 3-rd rom is at the first word of remapping table.
         //The mapping table is pointed by 3rd-rom's image list
         *pFlashBlockIdx = GetImageInfo(ILEid)->m_start_block;

         //read the remaping table of 3rd-rom from flash
         status = g_ftlFuncTbl->FTL_ReadPage(*pFlashBlockIdx, 0, page_buffer, NULL);

         if(status != FTL_SUCCESS)
         {
            return FTL_ERROR_TO_CD_ERROR((FTL_STATUS_CODE)status);
         }

         //The first block id for 3rd-rom is at the first entry of mapping table.               
         *pFlashBlockIdx = page_buffer[0];
         
         //Re-calculate the bound block, it is becuase the start block index is updated.  
         flash_bound_block = pImage->max_block ? (*pFlashBlockIdx + pImage->max_block -1) : INVALID_BLOCK_IDX;
      }
   }
   else
   {  //It is normal image
      if(codePartialUpdate == KAL_TRUE)
      {
         if(pSpaceInfo && (bl_CDL_NewSpaceInfo(spaceInfoId)->m_image_end != 0))
         {
            flash_max_block_num = bl_CDL_NewSpaceInfo(spaceInfoId)->m_image_end - bl_CDL_NewSpaceInfo(spaceInfoId)->m_image_start + 1;

            //The new max block number must not be larger than original when doing partial update 
            if((flash_max_block_num < pImage->max_block) || (pImage->max_block < pImage->blocks))
            {
               return BL_CD_ERROR_XIM_IMG_SIZE_EXCEED_MAX_VALUE;
            }  

            //The boundary block shoud keep the same as original while doing partial update.
            flash_bound_block = bl_CDL_NewSpaceInfo(spaceInfoId)->m_image_end;
         }

         //The start block should use the original ILE info
         *pFlashBlockIdx = GetImageInfo(ILEid)->m_start_block;      

         //Re-calculate the bound block, it is becuase the start block index is updated.  
         flash_bound_block = pImage->max_block ? (*pFlashBlockIdx + pImage->max_block -1) : INVALID_BLOCK_IDX;
      } 
   }

   BL_PRINT(LOG_DEBUG, "=>Writing data from xim=%d->%d: ", pImage->start_block, pImage->start_block+pImage->blocks-1);

   for(i=0; i<pImage->blocks; i++)
   {
      kal_uint32 origBlock = *pFlashBlockIdx;
      BL_PRINT(LOG_DEBUG, "%d->%d, ", pImage->start_block+i, *pFlashBlockIdx);

#ifdef __CDL_SUPPORT_BOOTCERT_V3__
      if(isBootCert)
      {  //If the image is bootcert, restore it from the backup in ILB region
         status = bl_restoreBootCert(*pFlashBlockIdx, pFlashBlockIdx);
      }
      else
      {
         status = bl_WriteXimBlockToFlash((pImage->start_block+i)*block_size_with_spare, *pFlashBlockIdx, pFlashBlockIdx, pInfo, i*block_size);
      }
#else /* __CDL_SUPPORT_BOOTCERT_V3__ */
      status = bl_WriteXimBlockToFlash((pImage->start_block+i)*block_size_with_spare, *pFlashBlockIdx, pFlashBlockIdx, pInfo, i*block_size);
#endif /* __CDL_SUPPORT_BOOTCERT_V3__ */
      
      if(origBlock != *pFlashBlockIdx && status == BL_CD_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "%d->%d, ", pImage->start_block+i, *pFlashBlockIdx);
      }

      if(status != BL_CD_ERROR_NONE)
      {
         BL_PRINT(LOG_ERROR, "Error when writing block %d, status%d\n\r", *pFlashBlockIdx, status);
         return status;
      }

      bl_UpdateProgress(UPDATE_PHASE, ((pImage->start_block+i)*page_per_block*100/(im_file_size/page_size_with_spare)));

      if(*pFlashBlockIdx > flash_bound_block)
      {
         BL_PRINT(LOG_ERROR, "Maximum block exceeds, max=%d\n\r", flash_bound_block);
         return BL_CD_ERROR_OVER_RESERVED_BOUNDARY;
      }

      //Update the image list and space info when first block is successfully written
      if(i == 0)
      {
         bl_CDL_NewImageInfo(ILEid)->m_load_addr = bl_GetCardImageInfo(ILEid)->m_load_addr;
         bl_CDL_NewImageInfo(ILEid)->m_length    = bl_GetCardImageInfo(ILEid)->m_length;

         if(codePartialUpdate == KAL_FALSE)
         {
            bl_CDL_NewImageInfo(ILEid)->m_start_block = *pFlashBlockIdx;
         
            if(pSpaceInfo)
            {
               bl_CDL_NewSpaceInfo(spaceInfoId)->m_image_start = *pFlashBlockIdx;
            }
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

   //Record the last block in space info
   if(pSpaceInfo)
   {
      bl_CDL_NewSpaceInfo(spaceInfoId)->m_image_last = *pFlashBlockIdx-1;

      if(codePartialUpdate == KAL_FALSE)
      {
         if(flash_bound_block != INVALID_BLOCK_IDX)
         {
            bl_CDL_NewSpaceInfo(spaceInfoId)->m_image_end = flash_bound_block;
         }
         else
         {
            bl_CDL_NewSpaceInfo(spaceInfoId)->m_image_end = *pFlashBlockIdx-1;
         }
      }
   }

   //Write 3RD ROM table
   if(pRemapTbl)
   {
      BL_PRINT(LOG_DEBUG, "=>Write 3rd ROM remap block @ %d...", *pFlashBlockIdx);

      if( bl_Write3rdROMBlockToNand(pRemapTbl, pImage->blocks*4, *pFlashBlockIdx, pFlashBlockIdx) != BL_CD_ERROR_NONE)
      {
         return BL_CD_ERROR_3RDROM_REMAP_TBL_WRITE_FAILURE;
      }
      BL_PRINT(LOG_DEBUG, " done @ %d\n\r", *pFlashBlockIdx);

      bl_CDL_NewImageInfo(ILEid)->m_start_block = *pFlashBlockIdx;         

      (*pFlashBlockIdx)++;
   }

   //Erase unused space if max block is specified
   if(flash_bound_block != INVALID_BLOCK_IDX)
   {
      BL_PRINT(LOG_DEBUG, "=>Erase block for FOTA reserved space:");
      for(;*pFlashBlockIdx <= flash_bound_block; (*pFlashBlockIdx)++)
      {
         BL_PRINT(LOG_DEBUG, "%d ", *pFlashBlockIdx);
         bl_EraseAndMarkBad(*pFlashBlockIdx, NULL);
      }
      BL_PRINT(LOG_DEBUG, "done\n\r");
   }

   return BL_CD_ERROR_NONE;
}



BL_CD_ERROR_CODE bl_DoUpdate()
{
   kal_uint32 i,j;
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;  
   kal_uint32 flashImgIdx = 0; //For record the processed image index on flash
   kal_uint32 *pInfo;
   DL_PACKAGE_NAND_IMAGE_HEADER_IMG_RECORD *pImage;
   kal_uint32 flashBlockIdx = GetImageInfo(ROMINFO_INDEX+1)->m_start_block; //MAUI starting block aligns current one
   kal_uint32 extrainfoId;

   for(i=0; i<image_count; i++)
   {
      if(i < XIM_MAUI_IDX)
      {
         //Bootloader and ILB are not updateable here
         continue;
      }

      pInfo = NULL;

#if defined(__BIND_TO_CHIP_BASIC__) || defined(__BIND_TO_CHIP__) || defined(__BIND_TO_KEY__)
      pImage = pMAUIImage + i;

      if(bl_isPImage(pImage))
      {
         status = bl_getMACRInfo(pDl_Package_GFH->gfh_file_info.m_content_offset + pImage->start_block*block_size_with_spare, &pInfo);
         if(status != BL_CD_ERROR_NONE)
         {
            return status;
         }
      }
#endif /* defined(__BIND_TO_CHIP_BASIC__) || defined(__BIND_TO_CHIP__) || defined(__BIND_TO_KEY__) */

      extrainfoId = GetExtraInfoidByNANDImgid(i);

      if(extrainfoId < extra_info_count)
      {
         if(pDl_Package_GFH->gfh_dl_package_info.m_extra_info[extrainfoId].m_operation == IM_DOWNLOAD)
         {

            BL_PRINT(LOG_INFO, "Updating MAUI %d @ block %d\n\r", i, flashBlockIdx);
      
            status = bl_DoUpdateMAUI(&flashBlockIdx, i, pInfo);
               
            if(status != BL_CD_ERROR_NONE)
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

         if(status != BL_CD_ERROR_NONE)
         {
             return status;
         }
         BL_PRINT(LOG_INFO, "Update of Misc Img %d done\n\r\n\r", i);
      }
   }

   //handle the filesystem
   if(status == BL_CD_ERROR_NONE)
   {
      status = bl_ProcessFilesystem(flashBlockIdx);
   }
   
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_SECURE_PLATFORM__ */

   return status;
}

#else /* __SV5_ENABLED__ */

#ifdef __CDL_SUPPORT_BOOTCERT_V5__

BL_CD_ERROR_CODE bl_backupBootCert(kal_uint32 backup_addr)
{
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;
   kal_uint32 bootcertidx;
   kal_uint32 bootcertblk;
   kal_bool isFlashHasBootCert = KAL_FALSE;

   //Check if there is BootCert and is needed to be updated
   for(bootcertidx = 0; bootcertidx < flash_layout_info.regionCount; bootcertidx++)
   {
      if(flash_layout_info.region[bootcertidx].binaryType == BOOT_CERT_CTRL)
      {
         isFlashHasBootCert = KAL_TRUE;
         break;
      }
   }

   if(isFlashHasBootCert && isBootCertExist)
   {
      //Do backup BootCert
      bootcertblk = flash_layout_info.region[bootcertidx].u.nandEmmc.startPage/page_per_block;
      status = bl_ReadDataFromFlash((kal_uint32*)backup_addr, bootcertblk, MAX_BOOTCERT_LEN, NULL);      
   }
   else if(!isFlashHasBootCert && !isBootCertExist)
   {  
      //There is no bootcert
      //return BL_CD_ERROR_NONE;
   }
   else
   {
      return BL_CD_ERROR_NO_BOOT_CERT_EXIST;
   }

   return status;
}


BL_CD_ERROR_CODE bl_restoreBootCert(kal_uint32 backup_addr, kal_uint32 flashBlockIdx, kal_uint32 *pWrittenBlockIdx)
{
   FTL_STATUS_CODE status = FTL_SUCCESS;
   kal_uint32 i;
   kal_uint32 pageToWrite = (MAX_BOOTCERT_LEN/page_size) + 1; 
   kal_uint32 remainingLength = MAX_BOOTCERT_LEN;
   kal_uint32 lenthToWrite;

   for(;; flashBlockIdx++)
   {
      //The MAX_BOOTCERT_LEN must not larger than block size
      if(MAX_BOOTCERT_LEN > g_ftlFuncTbl->FTL_GetBlockSize(flashBlockIdx, NULL))
      {
         return BL_CD_ERROR_BOOTCERT_EXCEED_BLOCKSIZE;
      }

      status = bl_EraseAndMarkBad(flashBlockIdx, NULL);

      if(status == FTL_ERROR_BAD_BLOCK)
      {
         continue;
      }

      for(i=0; status==FTL_SUCCESS && i<pageToWrite; i++)
      {
         lenthToWrite = (remainingLength>page_size) ? page_size : remainingLength;
      
         memset(page_buffer, 0x0, page_size_with_spare);
         memcpy(page_buffer, (kal_uint32*)backup_addr, lenthToWrite);
      
         status = g_ftlFuncTbl->FTL_WritePage(flashBlockIdx, i, page_buffer, NULL);

         remainingLength -= lenthToWrite;
         backup_addr += lenthToWrite;
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

      break;
   }

   if(status == FTL_SUCCESS && pWrittenBlockIdx != NULL)
   {
      *pWrittenBlockIdx = flashBlockIdx;
   }

   return FTL_ERROR_TO_CD_ERROR(status);

}

#endif /* __CDL_SUPPORT_BOOTCERT_V5__ */


BL_CD_ERROR_CODE bl_DoUpdateMAUI(kal_uint32 *pFlashBlockIdx, kal_uint32 imageIdx)
{
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;
   DL_PACKAGE_NAND_IMAGE_HEADER_IMG_RECORD *pImage = pMAUIImage+imageIdx;
   kal_uint32 i;
   kal_uint32 flash_max_block_num = 0;
   kal_uint32 flash_bound_block = pImage->max_block ? (*pFlashBlockIdx + pImage->max_block -1) : INVALID_BLOCK_IDX;
   kal_uint32 FlashLayoutid = GetFlashLayoutidByNANDimgid(imageIdx);
   kal_uint32 *pRemapTbl = bl_isENFBImage(pImage) ? ((kal_uint32*)remap_tbl) : NULL;
   kal_uint32 pBootCertData = NULL;

#ifdef __CDL_SUPPORT_BOOTCERT_V5__
   //Check if it is boot cert. Boot Cert need special proccessing
   if(flash_layout_info.region[FlashLayoutid].binaryType == BOOT_CERT_CTRL)
   {
      pBootCertData = (kal_uint32)(UpdatingRecord.m_reserve);
   }
#endif /* __CDL_SUPPORT_BOOTCERT_V5__ */

   //Make sure the max_block is valid when it is fixed layout, except BootCert
   if((ximFixedLayout == KAL_TRUE) && (pBootCertData == NULL))
   {
      if(pImage->max_block == 0)
      {         
         return BL_CD_ERROR_INVALID_XIM_IMG_MAX_BLOCK_NUMBER;
      }
   }

   if(codePartialUpdate == KAL_TRUE)
   {
      //The new max block number must not be larger than original when doing partial update 
      flash_max_block_num = (flash_layout_info.region[FlashLayoutid].u.nandEmmc.boundPage + 1 -
                        flash_layout_info.region[FlashLayoutid].u.nandEmmc.startPage)/page_per_block;
      if((flash_max_block_num < pImage->max_block) || (pImage->max_block < pImage->blocks))
      {
         return BL_CD_ERROR_XIM_IMG_SIZE_EXCEED_MAX_VALUE;
      }

      //The start block should use the original flash_layout_info
      *pFlashBlockIdx = flash_layout_info.region[FlashLayoutid].u.nandEmmc.startPage/page_per_block;

      //The boundary block shoud keep the same as original while doing partial update.
      flash_bound_block = flash_layout_info.region[FlashLayoutid].u.nandEmmc.boundPage/page_per_block;
   } 

   if(pImage->blocks*4 > sizeof(remap_tbl))
   {
      BL_PRINT(LOG_ERROR, "Block count=%d, large then %d\n\r", pImage->blocks, sizeof(remap_tbl)/4);
      return BL_CD_ERROR_3RDROM_REMAP_TBL_TOO_SMALL;
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

#ifdef __CDL_SUPPORT_BOOTCERT_V5__
      if(pBootCertData == NULL)
      {  //write normal image from xim to flash
         status = bl_WriteXimBlockToFlash((pImage->start_block+i)*block_size_with_spare, *pFlashBlockIdx, pFlashBlockIdx, NULL, i*block_size);
      }
      else
      {  //Write back the backup BootCert
         status = bl_restoreBootCert(pBootCertData, *pFlashBlockIdx, pFlashBlockIdx);
      }
#else /* __CDL_SUPPORT_BOOTCERT_V5__ */
      status = bl_WriteXimBlockToFlash((pImage->start_block+i)*block_size_with_spare, *pFlashBlockIdx, pFlashBlockIdx, NULL, i*block_size);
#endif /* __CDL_SUPPORT_BOOTCERT_V5__ */

      if(origBlock != *pFlashBlockIdx && status == BL_CD_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "%d->%d, ", pImage->start_block+i, *pFlashBlockIdx);
      }

      if(status != BL_CD_ERROR_NONE)
      {
         BL_PRINT(LOG_ERROR, "Error when writing block %d, status%d\n\r", *pFlashBlockIdx, status);
         return status;
      }

      bl_UpdateProgress(UPDATE_PHASE, ((pImage->start_block+i)*page_per_block*100/(im_file_size/page_size_with_spare)));

      if(*pFlashBlockIdx > flash_bound_block)
      {
         BL_PRINT(LOG_ERROR, "Maximum block exceeds, max=%d\n\r", flash_bound_block);
         return BL_CD_ERROR_OVER_RESERVED_BOUNDARY;
      }

      //Update the flash layout and space info when first block is successfully written.
      //Do not update them when doing partial update.
      //Note that we keep the flexity that the image boundary can be changed while doing full update.
      if((i == 0)  && (codePartialUpdate == KAL_FALSE))
      {
         flash_layout_info.region[FlashLayoutid].u.nandEmmc.startPage = (*pFlashBlockIdx)*page_per_block;

         if(pSpaceInfo)
         {
            bl_CDL_NewSpaceInfo(FlashLayoutid)->m_image_start = *pFlashBlockIdx;
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
      if( bl_Write3rdROMBlockToNand(pRemapTbl, pImage->blocks*4, *pFlashBlockIdx, pFlashBlockIdx) != BL_CD_ERROR_NONE)
      {
         return BL_CD_ERROR_3RDROM_REMAP_TBL_WRITE_FAILURE;
      }
      BL_PRINT(LOG_DEBUG, " done @ %d\n\r", *pFlashBlockIdx);

      (*pFlashBlockIdx)++;
   }
   
   //Update the last block in space info
   if(pSpaceInfo)
   {
      bl_CDL_NewSpaceInfo(FlashLayoutid)->m_image_last = *pFlashBlockIdx-1;

      //Do not update pSpaceInfo boundary when doing partial update.
      //Note that we keep the flexity that the image boundary can be changed while doing full update.
      if(codePartialUpdate == KAL_FALSE)
      {
         if(flash_bound_block != INVALID_BLOCK_IDX)
         {
            bl_CDL_NewSpaceInfo(FlashLayoutid)->m_image_end = flash_bound_block;
         }
         else
         {
            bl_CDL_NewSpaceInfo(FlashLayoutid)->m_image_end = *pFlashBlockIdx-1;
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

   return BL_CD_ERROR_NONE;
}


BL_CD_ERROR_CODE bl_DoUpdate()
{
   kal_uint32 i;
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;  
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
               
            if(status != BL_CD_ERROR_NONE)
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

         if(status != BL_CD_ERROR_NONE)
         {
             return status;
         }
         BL_PRINT(LOG_INFO, "Update of Misc Img %d done\n\r\n\r", i);
      }
   }

   //handle the filesystem
   if(status == BL_CD_ERROR_NONE)
   {
      status = bl_ProcessFilesystem(flashBlockIdx);
   }

   return status;
}


#endif /* __SV5_ENABLED__ */

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
 * @return  BL_CD_ERROR_CODE
 *
 ******************************************************************************/
BL_CD_ERROR_CODE bl_WriteXimToPartialFlashBlock(kal_uint32 update_start_addr, kal_uint32 length, IM_OPERATION op, kal_uint32 *pinfo, kal_uint32 OffsetInImage)
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
   if( bl_DL_Seek(pDl_Package_GFH->gfh_file_info.m_content_offset + update_start_addr, 0) != 0)
   {
      return BL_CD_ERROR_PACKAGE_SEEK_FAIL;
   }
   if(op == IM_DOWNLOAD)
   {
      if(bl_DL_Read((kal_uint32*)(bakbuf+start_offset), length)!= length)
      {
         return BL_CD_ERROR_PACKAGE_READ_FAIL;
      }
#ifndef __SV5_ENABLED__
#if defined(__BIND_TO_CHIP_BASIC__) || defined(__BIND_TO_CHIP__) || defined(__BIND_TO_KEY__)
      if(pinfo)
      {
         //The length must be 8 bytes aligned, but the region we interested must not in the unaligned last 8 bytes
         //in the image's end. Thus here we simply discard the unaligned tail. 
         SST_ContentPreprocess(pinfo, OffsetInImage, (kal_uint32*)(bakbuf+start_offset), (length>>3)<<3);
      }
#endif
#endif /* __SV5_ENABLED__ */
   }
   else if(op == IM_ERASE)
   {
      memset((kal_uint32*)(bakbuf+start_offset), (kal_int32)INVALID_4B_CONTENT, length);
   }
   //--The updated block data had been built --

   //Erase flash block
   if(bl_EraseAndMarkBad(flash_blk_idx, NULL) == FTL_ERROR_BAD_BLOCK)
   {
      return BL_CD_ERROR_FLASH_BAD_BLOCK;
   }

   //Write bakbuf to flash block
   flash_page_idx = 0;
   for(bufptr = (kal_uint32*)bakbuf; (kal_uint32)bufptr < bakbuf + blksize; (kal_uint32)bufptr += page_size)
   {
      status = g_ftlFuncTbl->FTL_WritePage(flash_blk_idx, flash_page_idx, bufptr, NULL);

      if(status != FTL_SUCCESS)
      {
         return BL_CD_ERROR_FLASH_PROGRAM;
      }
      
      flash_page_idx++;
   }

   ASSERT(blksize==flash_page_idx*page_size);

   return BL_CD_ERROR_NONE;

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
 * @return  BL_CD_ERROR_CODE
 *
 ******************************************************************************/
BL_CD_ERROR_CODE bl_PartialUpdateNORblock(kal_uint32 update_start_addr, kal_uint32 length, kal_uint32 src_data_addr)
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
      return BL_CD_ERROR_FLASH_BAD_BLOCK;
   }

   //Write bakbuf to flash block
   flash_page_idx = 0;
   for(bufptr = (kal_uint32*)bakbuf; (kal_uint32)bufptr < bakbuf + blksize; (kal_uint32)bufptr += page_size)
   {
      status = g_ftlFuncTbl->FTL_WritePage(flash_blk_idx, flash_page_idx, bufptr, NULL);

      if(status != FTL_SUCCESS)
      {
         return BL_CD_ERROR_FLASH_PROGRAM;
      }
      
      flash_page_idx++;
   }

   ASSERT(blksize==flash_page_idx*page_size);

   return BL_CD_ERROR_NONE;

}


BL_CD_ERROR_CODE bl_DoUpdateMAUI(kal_uint32 addr, kal_uint32 length, IM_OPERATION op, kal_uint32* pInfo)
{
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;
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
            return BL_CD_ERROR_ADDRESS_OR_LENGTH_NOT_BLOCK_BOUNDARY;
         }
      
         updatingLength = partialUpdateEnd - partialUpdateStart;

         BL_PRINT(LOG_DEBUG, "%d(0x%x-0x%x), ", flashBlockIdx, partialUpdateStart, partialUpdateEnd);
         
         status = bl_WriteXimToPartialFlashBlock(partialUpdateStart, updatingLength, op, pInfo, p-addr);
         
         p += updatingLength;
      }
      else
      {
         if(flashBlockIdx != mauiFirstBlock && flashBlockIdx != mauiFirstBlock+1)
         {
            if(op == IM_DOWNLOAD)
            {
               BL_PRINT(LOG_DEBUG, "%d(0x%x), ", flashBlockIdx, p);

               status = bl_WriteXimBlockToFlash(p, flashBlockIdx, &flashBlockIdx, pInfo, p-addr);

               if(origBlock != flashBlockIdx && status == BL_CD_ERROR_NONE)
               {
                  //Impossible: There should not be bad blocks in NOR flash...
                  ASSERT(0);
               }
            }
            else if(op == IM_ERASE)
            {
               BL_PRINT(LOG_DEBUG, "E %d(0x%x), ", flashBlockIdx, p);

               bl_EraseAndMarkBad(flashBlockIdx, NULL);

               status = BL_CD_ERROR_NONE;
            }            
         }

         p += g_ftlFuncTbl->FTL_GetBlockSize(flashBlockIdx, NULL);
      }

      if(status != BL_CD_ERROR_NONE)
      {
         BL_PRINT(LOG_ERROR, "Error when processing block %d, status%d\n\r", flashBlockIdx, status);
         return status;
      }

      bl_UpdateProgress(UPDATE_PHASE, p*100/im_file_size);
      
   }

   BL_PRINT(LOG_DEBUG, "done\n\r");

   return BL_CD_ERROR_NONE;
}


BL_CD_ERROR_CODE bl_DoUpdateFilesystem(kal_uint32 addr, kal_uint32 length, IM_OPERATION op)
{
   kal_uint32 sds_addr, sds_len;

   if(op == IM_SKIP)
   {
      BL_PRINT(LOG_INFO, "This region belongs to a filesystem which should be skiped\n\r");
      return BL_CD_ERROR_NONE;
   }

#ifdef __SECURE_DATA_STORAGE__
#ifdef __SV5_ENABLED__
   bl_getSDSregion(pmaui_gfh_buf, &sds_addr, &sds_len);
#else
   bl_getSDSregion(rominfo_buf, &sds_addr, &sds_len);
#endif

   //Check the earse range regard with SDS rage
   if(sds_len != 0)
   {
      if(bl_IsRegionOverlap(addr, length, sds_addr, sds_len))
      {
         BL_PRINT(LOG_INFO, "SDS can't be erased! SDS address:%x, SDS length:%x\n\r\n\r", sds_addr, sds_len);
         return BL_CD_ERROR_EARSE_SDS;
      }
   }
#endif /* __SECURE_DATA_STORAGE__ */

   //No special procedure needed for NOR filesystem, just call routines for MAUI
   return bl_DoUpdateMAUI(addr, length, op, NULL);
}

BL_CD_ERROR_CODE bl_DoUpdate()
{
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;
   kal_uint32 i;
   kal_uint32* pInfo;

   //Find the first MAUI binary starting address
   for(i=0; status == BL_CD_ERROR_NONE && i<GFH_DL_PKG_EXTRA_INFO_COUNT; i++)
   {
      if(pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_type == GFH_FILE_NONE)
      {
         break;
      }

      pInfo = NULL;

#ifndef __SV5_ENABLED__        
#if defined(__BIND_TO_CHIP_BASIC__) || defined(__BIND_TO_CHIP__) || defined(__BIND_TO_KEY__)
      if(pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_type == PRIMARY_MAUI)
      {
         status = bl_getMACRInfo(pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_start_addr, &pInfo);
         if(status != BL_CD_ERROR_NONE)
         {
            return status;
         }
      }
#endif /* defined(__BIND_TO_CHIP_BASIC__) || defined(__BIND_TO_CHIP__) || defined(__BIND_TO_KEY__) */
#endif /* __SV5_ENABLED__ */

      if( bl_IsValidBinInfoItem(&pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i]) )
      {

         if((!codePartialUpdate) || (!ximFixedLayout))
         {  //MAUI will be only updated in full update
            if(( pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_type >= V_MAUI_BINARY &&
                pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_type <  V_MAUI_BINARY_END) ||
                (pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_type == FOTA_UE))
            {
               status = bl_DoUpdateMAUI(pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_start_addr,
                                        pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_length,
                                        pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_operation,
                                        pInfo);
            }         
         }

         //When MBA is on, scatter file will ensure each bin file is block aligned.
         //Thus we do not need to consider the case that one page has the data from two bin.
         if( pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_type >= V_RESOURCE_BINARY &&
             pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_type <  V_RESOURCE_BINARY_END)
         {
            status = bl_DoUpdateMAUI(pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_start_addr,
                                     pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_length,
                                     pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_operation,
                                     NULL);
         }

         if( pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_type >= V_FILE_SYSTEM_BINARY &&
             pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_type <  V_FILE_SYSTEM_BINARY_END)
         {
            status = bl_DoUpdateFilesystem(pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_start_addr,
                                           pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_bin_length,
                                           pDl_Package_GFH->gfh_dl_package_info.m_extra_info[i].m_operation);
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

#ifndef __SV5_ENABLED__

STATIC kal_uint32 bl_GetILBStart()
{
   kal_uint32 ilbStart = BL_Shared_info.m_bl_ilb_info.m_bl_ilb_start;
   ASSERT(ilbStart != 0);
   return ilbStart;
}


STATIC kal_uint32 bl_GetILBEnd()
{
   kal_uint32 ilbEnd = MIN(GetImageInfo(ROMINFO_INDEX+1)->m_start_block-1, bl_GetILBStart()+BL_MAX_ILB_COUNT-1);
   return ilbEnd;
}


NFB_ILB_TYPE bl_GetILBType(kal_uint32 blockIdx)
{
   extern BOOTL_HEADER BLHeader;
   FTL_STATUS_CODE status;

   status = g_ftlFuncTbl->FTL_ReadPage(blockIdx, 0, page_buffer, NULL);

   if(status == FTL_SUCCESS)
   {
      // detect if it is a image list block
      if (strcmp((kal_char *)page_buffer, SUPER_BLOCK_PATTERN) != 0)
      {
         //Not image list block
         //BL_PRINT(LOG_ERROR, "Unrecognized block @ ILM area, idx=%d\n\r", blockIdx);
         return NFB_ILB_EMPTY;
      }

      memset(page_buffer, 0, sizeof(page_buffer));

      //Read the tail
      status = g_ftlFuncTbl->FTL_ReadPage(blockIdx, BLHeader.pagesPerBlock-1, page_buffer, NULL);

      if(status == FTL_SUCCESS || status == FTL_ERROR_READ_FAILURE)
      {
         if(CompareILBTailTag(page_buffer, IMAGE_LIST_BLOCK_TAIL_PATTERN))
         {
            return NFB_ILB_MAUI;
         }
         else if(CompareILBTailTag(page_buffer, IMAGE_LIST_BLOCK_TEMP_PATTERN))
         {
            return NFB_ILB_TEMP;
         }
         else if(CompareILBTailTag(page_buffer, IMAGE_LIST_BLOCK_BACKUP_PATTERN))
         {
            return NFB_ILB_BAKUP;
         }
         else if(CompareILBTailTag(page_buffer, IMAGE_LIST_BLOCK_FOTA_PATTERN))
         {
            return NFB_ILB_FOTA;
         }
         else if(CompareILBTailTag(page_buffer, IMAGE_LIST_BLOCK_DLPKG_PATTERN))
         {
            return NFB_ILB_DLPKG;
         }
      }
   }

   if(status == FTL_ERROR_BAD_BLOCK)
   {
      //Treat it as available block
      return NFB_ILB_NONE;
   }

   return NFB_ILB_EMPTY;
}

kal_uint32 bl_SearchForILBType(kal_uint32 ilbAreaStart, kal_uint32 ilbAreaEnd, NFB_ILB_TYPE type)
{
   kal_uint32 blockIdx;

   for(blockIdx=ilbAreaStart; blockIdx<=ilbAreaEnd; blockIdx++)
   {
      if(bl_GetILBType(blockIdx) == type)
      {
         return blockIdx;
      }
   }

   return 0;
}

/* Specific function to find a empty block that doesn't break the rule of Main ILB and dlPkgILB
   To find a block for dlPkgIlb, search the block after MainILB and then the block before MainILB.
   Finding a block for MainILB is done in a oppside manner */
/* flag is a helper to skip some block since we may have already known some blocks are malfunctioning, so that
   we can just skip them to get better robustness */

kal_uint32 bl_SearchForEmptyILBSpace(kal_uint32 ilbAreaStart, kal_uint32 ilbAreaEnd, kal_uint32 starter, NFB_ILB_TYPE type, kal_uint32 *pFlag)
{
   kal_int32 step = (type==NFB_ILB_DLPKG) ? -1 : 1;
   kal_uint32 i;
   NFB_ILB_TYPE ilbType;

   ASSERT(ilbAreaEnd-ilbAreaStart+1 <= 32 && BL_MAX_ILB_COUNT<=32);
   ASSERT(type == NFB_ILB_DLPKG || type == NFB_ILB_MAUI);
   ASSERT(starter == 0 || (starter >= ilbAreaStart && starter<=ilbAreaEnd));

   //Stage 1, search the empty block and there are no other blocks between the found one and target except bad ones
   for(i=starter-step; starter!=0 && i>=ilbAreaStart && i<=ilbAreaEnd; i-=step)
   {
      if((1<<(i-ilbAreaStart)) & *pFlag)
      {
         continue;
      }

      ilbType = bl_GetILBType(i);
      if(ilbType != NFB_ILB_NONE)
      {
         if(ilbType == NFB_ILB_EMPTY)
         {
            *pFlag |= (1<<(i-ilbAreaStart));
            return i;
         }
         break;
      }
   }

   //Let stage 2 handle the case without search base
   if(starter == 0)
   {
      starter = ilbAreaStart-1;
      step = 1;
   }

   //Stage 2, find any one empty block in the other way
   for(i=starter+step; starter!=0 && i>=ilbAreaStart && i<=ilbAreaEnd; i+=step)
   {
      if((1<<(i-ilbAreaStart)) & *pFlag)
      {
         continue;
      }

      ilbType = bl_GetILBType(i);
      if(ilbType == NFB_ILB_EMPTY)
      {
         *pFlag |= (1<<(i-ilbAreaStart));
         return i;
      }
   }

   return 0;
}


BL_CD_ERROR_CODE bl_ScanILBArea(kal_uint32 ilbAreaStart, kal_uint32 ilbAreaEnd, kal_uint32 *pMainILB, kal_uint32 *pDlPkgILB)
{
   kal_uint32 blockIdx;

   ASSERT(pMainILB && pDlPkgILB);

   *pMainILB = 0;
   *pDlPkgILB = 0;

   //Search for the image list block, and do the sanity test by the way
   for(blockIdx=ilbAreaStart; blockIdx<=ilbAreaEnd; blockIdx++)
   {
      NFB_ILB_TYPE ilbType = bl_GetILBType(blockIdx);

      switch(ilbType)
      {
         case NFB_ILB_MAUI:
         {
            if(pMainILB)
            {
               if(*pMainILB != 0)
               {
                  return BL_CD_ERROR_MULTIPLE_MAIN_ILB;
               }
               *pMainILB = blockIdx;
            }
            break;
         }

         case NFB_ILB_DLPKG:
         {
            if(pDlPkgILB)
            {
               if(*pDlPkgILB != 0)
               {
                  return BL_CD_ERROR_MULTIPLE_DLPKG_ILB;
               }
               *pDlPkgILB = blockIdx;
            }
            break;
         }

         case NFB_ILB_EMPTY:
         case NFB_ILB_NONE:
            break;

         default:
            BL_PRINT(LOG_ERROR, "Found unexpacted ILB, type=%d @ block %d\n\r", ilbType, blockIdx);
            return BL_CD_ERROR_UNEXPECTED_ILB_TYPE;
      }
   }

   //Sanity test, if dlPkgILB is after Main ILB, then there should be no blocks other than bad ones
   if(pMainILB && pDlPkgILB && *pMainILB && *pDlPkgILB)
   {
      if(*pMainILB < *pDlPkgILB)
      {
         kal_uint32 i;
         for(i=*pMainILB+1; i<*pDlPkgILB; i++)
         {
            ASSERT(bl_GetILBType(i) == NFB_ILB_NONE);
         }
      }
   }

   return BL_CD_ERROR_NONE;
}

BL_CD_ERROR_CODE bl_UpdateImageList(kal_uint32 ilbAreaStart, kal_uint32 ilbAreaEnd)
{
   FTL_STATUS_CODE status;
   kal_uint32 blockIdx;
   kal_uint32 mainILB  = 0;
   kal_uint32 dlPkgILB = 0;
   kal_uint32 i;
   kal_uint32 validILBmask = 0;
   kal_uint32 uaOffset = 0;

#ifdef __FOTA_DM__
   uaOffset = 1;
#endif

   //ROMInfo should be the in the first block of MAUI
   pImageList->m_image[ROMINFO_INDEX].m_start_block = pImageList->m_image[ROMINFO_INDEX+1+uaOffset].m_start_block;

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

   if(bl_ScanILBArea(ilbAreaStart, ilbAreaEnd, &mainILB, &dlPkgILB) != BL_CD_ERROR_NONE)
   {
      return BL_CD_ERROR_SCAN_ILB_FAIL;
   }

   if(!dlPkgILB)
   {
      ASSERT(0);
      return BL_CD_ERROR_UNABLE_TO_FIND_DLPKG_ILB;
   }

   if(!mainILB)
   {
      blockIdx = bl_SearchForEmptyILBSpace(ilbAreaStart, ilbAreaEnd, dlPkgILB, NFB_ILB_MAUI, &validILBmask);
   }
   else
   {
      blockIdx = mainILB;
   }

   if(!blockIdx)
   {
      BL_PRINT(LOG_ERROR, "Unable to find a empty block for new MainILB\n\r");
      return BL_CD_ERROR_OUT_OF_ILB_AREA;
   }

   while(1)
   {
      BL_PRINT(LOG_DEBUG, "Updating Main ILB(%d)", blockIdx);

      status = bl_EraseAndMarkBad(blockIdx, NULL);

      if(status == FTL_SUCCESS)
      {
         for(i=0; status==FTL_SUCCESS && i<page_per_block; i++)
         {
            kal_uint32 *pBuf;

            if(i == IMAGE_SPACE_PAGE_INDEX && pSpaceInfo)
            {
               pBuf = space_page;
            }
            else if(i == IMAGE_LIST_PAGE_INDEX)
            {
               pBuf = imagelist_page;
            }
            else if(i == VERSION_INFO_PAGE_INDEX)
            {
               pBuf = rominfo_page;
            }
            else
            {
               if( bl_ReadXIMPage((kal_uint32)page_buffer, pMAUIImage[XIM_IMAGE_IMAGE_LIST_BLOCK_IDX].start_block*page_per_block+i, 1, KAL_FALSE) != 0 )
               {
                  return BL_CD_ERROR_PACKAGE_READ_FAIL;
               }

               pBuf = page_buffer;
            }

            BL_PRINT(LOG_DEBUG, ".");

            status = g_ftlFuncTbl->FTL_WritePage(blockIdx, i, pBuf, NULL);
         }

         if(status == FTL_SUCCESS)
         {
            BL_PRINT(LOG_DEBUG, "done\n\r", i, blockIdx);
            break;
         }

         //Erase again to make sure no confusing data in it
         NFB_ErasePhysicalBlockX(blockIdx, KAL_TRUE);

         //Mark it bad if the falure is due to bad block
         if(status == FTL_ERROR_BAD_BLOCK)
         {
            BL_PRINT(LOG_WARN, "\n\rBad block found in ILB area @ block %d page %d\n\r", blockIdx, i);
            g_ftlFuncTbl->FTL_MarkBadBlock(blockIdx, NULL);
         }
         else
         {
             BL_PRINT(LOG_CRIT, "\n\rUnexpected error in ILB area @ block %d page %d, status=%d\n\r", blockIdx, i, status);
         }
      }

      //Note: if occuring any abnormal NAND behavior, try our best to write the main ILB or the target won't boot up
      blockIdx = bl_SearchForEmptyILBSpace(ilbAreaStart, ilbAreaEnd, dlPkgILB, NFB_ILB_MAUI, &validILBmask);

      if(!blockIdx)
      {
         return BL_CD_ERROR_OUT_OF_ILB_AREA;
      }
   }

   return BL_CD_ERROR_NONE;

}

BL_CD_ERROR_CODE bl_MarkPkgDLB(kal_uint32 ilbAreaStart, kal_uint32 ilbAreaEnd)
{
   FTL_STATUS_CODE status = BL_CD_ERROR_NONE;
   kal_uint32 blockIdx;

   kal_uint32 mainILB  = 0;
   kal_uint32 dlPkgILB = 0;
   kal_uint32 validILBmask = 0;

   //If last cdl is fail, we should not do the backup again. Because we might loss power during
   //updating the ILB blocks.
   if(last_cdl_fail_flag == KAL_TRUE)
   {
      return BL_CD_ERROR_NONE;
   }

   if(bl_ScanILBArea(ilbAreaStart, ilbAreaEnd, &mainILB, &dlPkgILB) != BL_CD_ERROR_NONE)
   {
      return BL_CD_ERROR_SCAN_ILB_FAIL;
   }

   ASSERT(!mainILB || BL_Shared_info.m_bl_ilb_info.m_bl_ilb_blk == mainILB);

   if(dlPkgILB != 0)
   {
      //Alread in update state
      BL_PRINT(LOG_WARN, "Already in Card DL state\n\r");
      return BL_CD_ERROR_NONE;
   }

   blockIdx = bl_SearchForEmptyILBSpace(ilbAreaStart, ilbAreaEnd, mainILB, NFB_ILB_DLPKG, &validILBmask);

   if(!blockIdx)
   {
      BL_PRINT(LOG_ERROR, "No free block between %d to %d to lunch update by card\n\r", ilbAreaStart, ilbAreaEnd);
      return BL_CD_ERROR_OUT_OF_ILB_AREA;
   }

   while(1)
   {
      kal_uint32 i;

      BL_PRINT(LOG_DEBUG, "Copying MainILB(%d)->dlPkgILB(%d)", mainILB, blockIdx);

      status = bl_EraseAndMarkBad(blockIdx, NULL);

      if(status == FTL_SUCCESS)
      {
         for(i=0; status==FTL_SUCCESS && i<page_per_block; i++)
         {
            status = g_ftlFuncTbl->FTL_ReadPage(mainILB, i, page_buffer, NULL);

            if(status != FTL_SUCCESS)
            {
               BL_PRINT(LOG_CRIT, "\n\rUnable to read origianl main ILB, terminated\n\r");
               return BL_CD_ERROR_ILB_READ_FAILURE;
            }
            
            if(i == page_per_block-1)
            {
               memcpy(page_buffer, IMAGE_LIST_BLOCK_DLPKG_PATTERN, 28);
            }
#ifdef __CDL_SUPPORT_BOOTCERT_V3__
            else if(i == page_per_block-MAX_BOOTCERT_PAGE_NUM-1)
            {
               //the number of page in a block should larger than 4 info page + 1 tail page + 2 bootcert bak page
               ASSERT(page_per_block>=(4+1+MAX_BOOTCERT_PAGE_NUM));
            
               //backup bootcert
               bl_backupBootCert(blockIdx, i);
               continue;
            }
            else if((i > page_per_block-MAX_BOOTCERT_PAGE_NUM-1) && (i!=(page_per_block-1)))
            {
               //bl_backupBootCert() will write the pages after page_per_block-MAX_BOOTCERT_PAGE_NUM-1
               //Thus skip these pages to avoid bootcert data corruption.
               continue;
            }
#endif

            BL_PRINT(LOG_DEBUG, ".");
            status = g_ftlFuncTbl->FTL_WritePage(blockIdx, i, page_buffer, NULL);
         }

         if(status == FTL_SUCCESS)
         {
            break;
         }

         //Erase again to make sure no confusing data in it
         g_ftlFuncTbl->FTL_EraseBlock(blockIdx, NULL);

         //Mark it bad if the falure is due to bad block
         if(status == FTL_ERROR_BAD_BLOCK)
         {
            BL_PRINT(LOG_WARN, "\n\rBad block found in ILB area @ block %d page %d\n\r", blockIdx, i);
            g_ftlFuncTbl->FTL_MarkBadBlock(blockIdx, NULL);
         }
         else
         {
             BL_PRINT(LOG_CRIT, "\n\rUnexpected error in ILB area @ block %d page %d, status=%d\n\r", blockIdx, i, status);
         }
      }

      if(status == FTL_ERROR_BAD_BLOCK)
      {
         blockIdx = bl_SearchForEmptyILBSpace(ilbAreaStart, ilbAreaEnd, mainILB, NFB_ILB_DLPKG, &validILBmask);

         if(!blockIdx)
         {
            BL_PRINT(LOG_ERROR, "No replacement block between %d to %d to lunch update by card\n\r", ilbAreaStart, ilbAreaEnd);
            return BL_CD_ERROR_OUT_OF_ILB_AREA;
         }
      }
      else
      {
         BL_PRINT(LOG_CRIT, "Unexpectaed error in NAND device, stop updating for safe, status=%d\n\r", status);
         return BL_CD_ERROR_FLASH_OTHER_ERROR;
      }
   }
   BL_PRINT(LOG_DEBUG, "done\n\r");

   return BL_CD_ERROR_NONE;

}

BL_CD_ERROR_CODE bl_ErasePkgDLB(kal_uint32 ilbAreaStart, kal_uint32 ilbAreaEnd)
{
   kal_uint32 mainILB = 0;
   kal_uint32 dlPkgILB = 0;

   bl_ScanILBArea(ilbAreaStart, ilbAreaEnd, &mainILB, &dlPkgILB);

   if(mainILB)
   {
      //Erase DLPKG ILB to finish the update

      ASSERT(dlPkgILB);

      BL_PRINT(LOG_DEBUG, "Erasing dlPkgILB(%d)\n\r", dlPkgILB);

      bl_EraseAndMarkBad(dlPkgILB, NULL);

      //Copy update image to internal memory to keep on boot up

      memcpy(&BL_Shared_info.m_bl_image_list, pImageList, sizeof(BL_Shared_info.m_bl_image_list));
      if(pSpaceInfo)
      {
         memcpy(&BL_Shared_info.m_bl_image_space, pSpaceInfo, sizeof(BL_Shared_info.m_bl_image_space));
      }

      return BL_CD_ERROR_NONE;
   }
   else
   {
      BL_PRINT(LOG_CRIT, "MAIN ILB is not found, how to finished?\n\r");
      ASSERT(0);
      return BL_CD_ERROR_UNABLE_TO_FIND_MAIN_ILB;
   }
}

#else /* __SV5_ENABLED__ */

BL_CD_ERROR_CODE bl_UpdateImageInfo(void)
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
      return BL_CD_ERROR_FAIL_TO_WRITE_CBR_IMAGE_INFO;
   }

   if(CBR_WriteRecord(E_CBR_IDX_CBR, CBR_RECORD_FLASH_SPACE_INFO, (kal_uint8 *)&space_info, sizeof(Nand_ImageSpace_ST), NULL) != CBR_SUCCESS)
   {
      return BL_CD_ERROR_FAIL_TO_WRITE_CBR_SPACE_INFO;
   }
   
   if(CBR_WriteRecord(E_CBR_IDX_CBR, CBR_RECORD_MAUI_INFO, (kal_uint8 *)pMauiInfoInCard, sizeof(GFH_MAUI_INFO_v1), NULL) != CBR_SUCCESS)
   {
      BL_PRINT(LOG_INFO, "Note: Could not write maui info to CBR\n\r");
   }

   return BL_CD_ERROR_NONE;
}

#endif /* __SV5_ENABLED__ */

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
      if(*((kal_uint32*)(markerAddr)+i) != CDL_MARKER)
      {
         return KAL_FALSE;

      }
   }




   return KAL_TRUE;
}

BL_CD_ERROR_CODE bl_MarkCDL(kal_uint32 mauiAddr)
{
   FTL_STATUS_CODE status;
   kal_uint32 i;

   ASSERT(mauiAddr < MAUI_ROM_START_ADDR - BOOTLOADER_ROM_REGION_LEN + custom_get_NORFLASH_Size());

   mauiFirstBlock = bl_AddrToBlockIdx(mauiAddr, NULL);

   //If last cdl is fail, we should not do the backup again. Because we might loss power during
   //updating the maui info block.
   if(last_cdl_fail_flag == KAL_FALSE)
   {
      //Prepare CDL pattern
      for(i=0; i<sizeof(page_buffer)/4; i++)
      {
         *((kal_uint32*)(page_buffer)+i) = CDL_MARKER;
      }

      //Erase the MAUI's second block to prevent ROM INFO
      status = g_ftlFuncTbl->FTL_EraseBlock(mauiFirstBlock+1, NULL);

      //Note that the minimum page number in 1 block is 2.
      //It is due to the smallest block size of serial flash is 4kb.

      //Assume maui bin is larger than 2 block

#ifndef __SV5_ENABLED__
      //Write the ROM info to page 1
      if(status == FTL_SUCCESS)
      {
         status = g_ftlFuncTbl->FTL_WritePage(mauiFirstBlock+1, 1, rominfo_buf, NULL);
      }
#else /* __SV5_ENABLED__ */
      //Write the ROM info to page 1
      if(status == FTL_SUCCESS)
      {
         status = g_ftlFuncTbl->FTL_WritePage(mauiFirstBlock+1, 1, flash_pmaui_gfh_buf, NULL);
      }
#endif /* __SV5_ENABLED__ */

      //Write the marker @ page 0
      if(status == FTL_SUCCESS)
      {
         status = g_ftlFuncTbl->FTL_WritePage(mauiFirstBlock+1, 0, page_buffer, NULL);
      }

      if(status != FTL_SUCCESS)
      {
         BL_PRINT(LOG_ERROR, "Cannot write maker to MAUI's 2nd block, status=%d\n\r", status);
         return BL_CD_ERROR_ERASE_MARKER_BLOCK;
      }
   }

   return BL_CD_ERROR_NONE;
}

BL_CD_ERROR_CODE bl_WriteMarkerBlocks(kal_uint32 mauiAddr)
{
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;

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
      return BL_CD_ERROR_WRITE_MARKER_BLOCK;
   }

   return BL_CD_ERROR_NONE;
}

#endif /* _NAND_FLASH_BOOTING_ */


/*************************************************************************
 * load rom_info/maui_info
 *************************************************************************/
#ifndef __SV5_ENABLED__

#ifdef _NAND_FLASH_BOOTING_

BL_CD_ERROR_CODE bl_LoadILBInXIM()
{
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;
   kal_uint32 i;

   //Read space info in XIM
   if(status == BL_CD_ERROR_NONE)
   {
      status = bl_ReadXIMPage((kal_uint32)space_page, pMAUIImage[XIM_IMAGE_IMAGE_LIST_BLOCK_IDX].start_block*page_per_block+IMAGE_SPACE_PAGE_INDEX, 1, KAL_FALSE);
   }

   //Read image list in XIM
   if(status == BL_CD_ERROR_NONE)
   {
      status = bl_ReadXIMPage((kal_uint32)imagelist_page, pMAUIImage[XIM_IMAGE_IMAGE_LIST_BLOCK_IDX].start_block*page_per_block+IMAGE_LIST_PAGE_INDEX, 1, KAL_FALSE);
   }

   //Read ROM info in XIM
   if(status == BL_CD_ERROR_NONE)
   {
      status = bl_ReadXIMPage((kal_uint32)rominfo_page, pMAUIImage[XIM_IMAGE_IMAGE_LIST_BLOCK_IDX].start_block*page_per_block+VERSION_INFO_PAGE_INDEX, 1, KAL_FALSE);
   }

   if(status == BL_CD_ERROR_NONE)
   {
      //The default spaceinfo is from flash
      //It will be modified during the updating
      if((((Nand_ImageSpace_ST*)space_page)->m_image_space_id == FOTA_IMAGE_END_ID) ||
         (((Nand_ImageSpace_ST*)space_page)->m_image_count != 0))
      {
         pSpaceInfo = (Nand_ImageSpace_ST*)space_page;

         memcpy((kal_uint32*)pSpaceInfo, (kal_uint32*)(&BL_Shared_info.m_bl_image_space), sizeof(Nand_ImageSpace_ST));
      }

      //The default image list info is from card, except the start block is from flash
      //It will be modified during the updating
      pImageList = (Nand_ImageList_S*)imagelist_page;

      //Save the image info from card
      memcpy((kal_uint32*)(&card_img_info), (kal_uint32*)pImageList, sizeof(Nand_ImageList_S));

      //The default image info is from flash, it will be modified during update, the new info might be from card
      memcpy((kal_uint32*)pImageList, (kal_uint32*)(&BL_Shared_info.m_bl_image_list), sizeof(Nand_ImageList_S));

   }

   if(status != BL_CD_ERROR_NONE)
   {
      BL_PRINT(LOG_ERROR, "bl_LoadILBInXIM falure = %d\n\r", status);
   }

   return status;
}


#else /* _NAND_FLASH_BOOTING_ */

BL_CD_ERROR_CODE bl_LoadRomInfoInXIM()
{
   extern void *SST_Search_MAUI_Rom_Info(kal_uint32 rom_base, kal_uint32 length);

   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;
   GFH_DL_PACKAGE_INFO_v2 *pPkgInfo = &pDl_Package_GFH->gfh_dl_package_info;
   

   kal_bool found = KAL_FALSE;
   kal_uint32 i, pageIdx;
   kal_uint32 totalPages = im_file_size/page_size;

   kal_uint32 *p = NULL;

   //Get the start address of p-maui, we search the infomation directly from it
   //to avoid ambiguous. It is because the searched pattern might occur in bootloader region.
   kal_uint32 mauiSearchBase = MAUI_ROM_START_ADDR;

   //Here we use page_size_with_spare as the divider to calculate the pageIdx. It is
   //because bl_ReadXIMPage use this number as page unit. (The XIM header is excluded)
   pageIdx = mauiSearchBase/page_size_with_spare;

   //Always pre-load the next page in case the structure lies on the boundary of pages
   status = bl_ReadXIMPage((kal_uint32)rominfo_buf, pageIdx, 2, KAL_FALSE);

   //The first 2 page is already loaded into rominfo_buf
   pageIdx += 2;

   for(; status == BL_CD_ERROR_NONE && pageIdx<totalPages; pageIdx++)
   {
      p = (kal_uint32*)SST_Search_MAUI_Rom_Info((kal_uint32)rominfo_buf, sizeof(rominfo_buf));

      if(p && p < rominfo_buf + page_size/sizeof(*rominfo_buf))
      {
         memcpy(rominfo_buf, p, page_size);
         found = KAL_TRUE;
         break;
      }

      memcpy(rominfo_buf, rominfo_buf + page_size/sizeof(*rominfo_buf), page_size);
      status = bl_ReadXIMPage((kal_uint32)rominfo_buf + page_size, pageIdx, 1, KAL_FALSE);
   }

   if(status == BL_CD_ERROR_NONE)
   {
      if(!found)
      {
         BL_PRINT(LOG_ERROR, "No ROM Info found in PKG\n\r");
         status = BL_CD_ERROR_NO_PKG_ROM_INFO_FOUND;
      }
   }
   else
   {
      BL_PRINT(LOG_ERROR, "bl_LoadRomInfoInXIM falure = %d\n\r", status);
   }

   return status;
}

#endif /* _NAND_FLASH_BOOTING_ */

#else /* __SV5_ENABLED__ */

BL_CD_ERROR_CODE bl_LoadpMauiGFHInfoInXIM()
{
   kal_uint32 status = BL_CD_ERROR_NONE;
   GFH_FILE_INFO_v1 *FileInfo;

#ifdef __FOTA_DM__  
   kal_uint32 uaOffset = 1;
#else
   kal_uint32 uaOffset = 0;
#endif 

#ifdef _NAND_FLASH_BOOTING_
   kal_uint32 pageidx = (pMAUIImage[XIM_MAUI_IDX+uaOffset].start_block)*page_per_block;
#else /* _NAND_FLASH_BOOTING_ */
   kal_uint32 pageidx = (pDl_Package_GFH->gfh_dl_package_info.m_extra_info[bl_GetGFHImgIdx(PRIMARY_MAUI)].m_bin_start_addr)/page_size_with_spare;
#endif /* _NAND_FLASH_BOOTING_ */

   //Read at least first 512 bytes of p-MAUI from it's begining
   //The page size is at least 512 bytes, thus here simply read a page from begining.
   status = bl_ReadXIMPage((kal_uint32)pmaui_gfh_buf, pageidx, 1, KAL_FALSE);
   if(status != BL_CD_ERROR_NONE)
   {
      return status;
   }

   if(GFH_Find((U32)pmaui_gfh_buf, GFH_FILE_INFO, (void **)&FileInfo) != B_OK)
   {
      return BL_CD_ERROR_NO_PKG_GFH_FILE_INFO_FOUND;
   }

   //Make sure the size of pmaui_gfh_buf contains the full gfh
   if(FileInfo->m_content_offset > sizeof(pmaui_gfh_buf))
   {
      return BL_CD_ERROR_INSUFFICIENT_GFH_INFO_BUF;
   }

   //Read the whole GFH
   status = bl_ReadXIMPage((kal_uint32)pmaui_gfh_buf, pageidx, (FileInfo->m_content_offset/page_size)+1, KAL_FALSE);
   if(status != BL_CD_ERROR_NONE)
   {
      return status;
   }

   //Get the MAUI info
   if(GFH_Find((U32)pmaui_gfh_buf, GFH_MAUI_INFO, (void **)&pMauiInfoInCard) != B_OK)
   {
      return BL_CD_ERROR_NO_PKG_GFH_MAUI_INFO_FOUND;
   }

#ifdef _NAND_FLASH_BOOTING_
   //Get the flash layout from flash instead of from card. These value will be re-written during update.
   if(CBR_ReadRecord(E_CBR_IDX_CBR, CBR_RECORD_FLASH_LAYOUT, (kal_uint8 *)&flash_layout_info, sizeof(FlashLayout), NULL) <= 0)
   {
      return BL_CD_ERROR_UNABLE_TO_FIND_CBR_IMAGE_INFO;
   }

   //Get the space info from flash instead of from card. These value will be re-written during update.
   if(CBR_ReadRecord(E_CBR_IDX_CBR, CBR_RECORD_FLASH_SPACE_INFO, (kal_uint8 *)&space_info, sizeof(Nand_ImageSpace_ST), NULL) <= 0)
   {
      return BL_CD_ERROR_UNABLE_TO_FIND_CBR_SPACE_INFO;
   }

   pSpaceInfo = &space_info;
#endif /* _NAND_FLASH_BOOTING_ */

   return BL_CD_ERROR_NONE;
}

#endif /* __SV5_ENABLED__ */

/*************************************************************************
 * MAIN functions
 *************************************************************************/

BL_CD_ERROR_CODE bl_InitialUpdate()
{
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;

#ifdef _NAND_FLASH_BOOTING_

#ifndef __SV5_ENABLED__
   status = bl_MarkPkgDLB(bl_GetILBStart(), bl_GetILBEnd());
#else /*  __SV5_ENABLED__ */
   //If there is no CBR_RECORD_UPDATING_INFO, than we add it
   if(CBR_GetRecordLen(E_CBR_IDX_CBR, CBR_RECORD_UPDATING_INFO)<=0)
   {
      UpdatingRecord.m_info_type_magic = CDL_MARKER;

#ifdef __CDL_SUPPORT_BOOTCERT_V5__
      //BootCert is backuped in CBR
      status = bl_backupBootCert((kal_uint32)UpdatingRecord.m_reserve);
      if(status != BL_CD_ERROR_NONE)
      {
         return status;
      }
#endif /* #ifdef __CDL_SUPPORT_BOOTCERT_V5__ */

      //The content of UpdatingRecord should be got during bl_VerifyPKGBody()
      if(CBR_AddRecord(E_CBR_IDX_CBR, CBR_RECORD_UPDATING_INFO, (kal_uint8 *)&UpdatingRecord, sizeof(UPDATING_RECORD), SDS_DP_NONE, NULL) != CBR_SUCCESS)
      {
         return BL_CD_ERROR_FAIL_TO_ADD_CBR_UPDATING_INFO;
      }
   }
   else
   {  //If CBR_RECORD_UPDATING_INFO is exist, it means some UA is doing update.
      if(last_cdl_fail_flag == KAL_FALSE)
      {  //It means other update agent is doing update. CDL agent should not try to do CDL.
         return BL_CD_ERROR_OTHER_UA_IS_DOING_UPDATE;
      }
      //else, we are doing cdl again to recover last cdl fail
   }
#endif /*  __SV5_ENABLED__ */

#else /* _NAND_FLASH_BOOTING_ */

   status = bl_MarkCDL(MAUI_ROM_START_ADDR);

#endif /* _NAND_FLASH_BOOTING_ */

   return status;
}


BL_CD_ERROR_CODE bl_FinishUpdate()
{
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;

#ifdef _NAND_FLASH_BOOTING_
#ifndef __SV5_ENABLED__
   status = bl_ErasePkgDLB(bl_GetILBStart(), bl_GetILBEnd());
#else /*  __SV5_ENABLED__ */
   if(CBR_DelRecord(E_CBR_IDX_CBR, CBR_RECORD_UPDATING_INFO) != CBR_SUCCESS)
   {
      return BL_CD_ERROR_FAIL_TO_DEL_CBR_UPDATING_INFO;
   }
#endif /*  __SV5_ENABLED__ */
#else
   status = bl_WriteMarkerBlocks(MAUI_ROM_START_ADDR);

#ifdef __MTK_SECURE_PLATFORM__   
#ifndef __SV5_ENABLED__
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
#endif /* __SV5_ENABLED__ */
#endif /* __MTK_SECURE_PLATFORM__ */

#endif

   if(status == BL_CD_ERROR_NONE)
   {
      bl_ClearCardDownloadTrigger();
   }

   return status;
}

BL_CD_ERROR_CODE bl_ExtraInfoCheck()
{
   kal_int32 i, j;
   kal_uint32 extraInfoFsCount = 0;
   kal_uint32 numUpdateCodeImg = 0;       //For checking if all maui image are all updated or not updated
   kal_uint32 codeImgExist = KAL_FALSE;   //For checking if all maui image are all updated or not updated


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
         return BL_CD_ERROR_INVALID_BINARY_OPERATION;
      }

      //Only FS area allow erasing
      if(pPkgInfo->m_extra_info[i].m_operation == IM_ERASE)
      {
         if(!(pPkgInfo->m_extra_info[i].m_bin_type >= V_FILE_SYSTEM_BINARY && pPkgInfo->m_extra_info[i].m_bin_type < V_FILE_SYSTEM_BINARY_END))
         {
            return BL_CD_ERROR_INVALID_BINARY_OPERATION;
         }
      }

#if defined(__CDL_SUPPORT_BOOTCERT_V3__) || defined(__CDL_SUPPORT_BOOTCERT_V5__)
      if(pPkgInfo->m_extra_info[i].m_bin_type == BOOT_CERT_CTRL) 
      {
         isBootCertExist = KAL_TRUE;
      }
#endif

      //Bootloader can not be updated
      if(((pPkgInfo->m_extra_info[i].m_bin_type == ARM_BL) || (pPkgInfo->m_extra_info[i].m_bin_type == ARM_EXT_BL) || (pPkgInfo->m_extra_info[i].m_bin_type == DUALMAC_DSP_BL)) && 
         (pPkgInfo->m_extra_info[i].m_operation != IM_SKIP) )
      {
         return BL_CD_ERROR_BOOTLOADER_CANNOT_BE_UPDATED;
      }

      //Mark it if not all file system are going to be updated
      if((pPkgInfo->m_extra_info[i].m_operation >= IM_SKIP && pPkgInfo->m_extra_info[i].m_operation < IM_INVALID) &&
         (pPkgInfo->m_extra_info[i].m_bin_type >= V_FILE_SYSTEM_BINARY && pPkgInfo->m_extra_info[i].m_bin_type < V_FILE_SYSTEM_BINARY_END))         
      {
         fsPartialUpdate = KAL_TRUE;
      }

      // TODO: remove the restriction
      //The resource images and 3rd rom must be all updated, the only allowed operation for them is download.
      if((pPkgInfo->m_extra_info[i].m_bin_type >= V_RESOURCE_BINARY && pPkgInfo->m_extra_info[i].m_bin_type < V_RESOURCE_BINARY_END) ||
         (pPkgInfo->m_extra_info[i].m_bin_type == THIRD_ROM))
      {
         if(pPkgInfo->m_extra_info[i].m_operation != IM_DOWNLOAD)
         {
            return BL_CD_ERROR_INVALID_BINARY_OPERATION;
         }
      }

      //Check if the xim has FOTA or MBA layout
      if((pPkgInfo->m_extra_info[i].m_bin_type >= V_RESOURCE_BINARY && pPkgInfo->m_extra_info[i].m_bin_type < V_RESOURCE_BINARY_END) ||
         (pPkgInfo->m_extra_info[i].m_bin_type == FOTA_UE))
      {
         ximFixedLayout = KAL_TRUE;
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
            return BL_CD_ERROR_INVALID_PARTIAL_UPDATE_PACKAGE;
         }
      }

#ifdef _NAND_FLASH_BOOTING_
      //Addr and Length is NA for NAND. IM has all information already, except for FAT region
      if(pPkgInfo->m_extra_info[i].m_bin_start_addr || pPkgInfo->m_extra_info[i].m_bin_length)
      {
         if(!(pPkgInfo->m_extra_info[i].m_bin_type >= V_FILE_SYSTEM_BINARY && pPkgInfo->m_extra_info[i].m_bin_type < V_FILE_SYSTEM_BINARY_END))
         {
            return BL_CD_ERROR_XIM_INVALID_PARAM;
         }
      }

      if(pPkgInfo->m_extra_info[i].m_bin_type >= V_FILE_SYSTEM_BINARY && pPkgInfo->m_extra_info[i].m_bin_type < V_FILE_SYSTEM_BINARY_END)
      {
         extraInfoFsCount++;
      }
#else            
      //Check no one can touch bootloader region!!!
      //The NOR flash start address is pretended at 0x0. The DL package also assume flash is at 0x0.
      if(IS_OVERLAP(0, BOOTLOADER_ROM_REGION_LEN, pPkgInfo->m_extra_info[i].m_bin_start_addr, pPkgInfo->m_extra_info[i].m_bin_length) &&
         (pPkgInfo->m_extra_info[i].m_bin_type != ARM_BL) && (pPkgInfo->m_extra_info[i].m_bin_type != ARM_EXT_BL)
         && (pPkgInfo->m_extra_info[i].m_bin_type != DUALMAC_DSP_BL)
         && (pPkgInfo->m_extra_info[i].m_bin_type != FOTA_UE))
      {
         return BL_CD_ERROR_BOOTLOADER_CANNOT_BE_UPDATED;
      }

      //Check if any invalid binary is specified
      if(!( (pPkgInfo->m_extra_info[i].m_bin_type >= V_MAUI_BINARY && pPkgInfo->m_extra_info[i].m_bin_type < V_MAUI_BINARY_END) ||
            (pPkgInfo->m_extra_info[i].m_bin_type >= V_RESOURCE_BINARY && pPkgInfo->m_extra_info[i].m_bin_type < V_RESOURCE_BINARY_END) ||
            (pPkgInfo->m_extra_info[i].m_bin_type >= V_FILE_SYSTEM_BINARY && pPkgInfo->m_extra_info[i].m_bin_type < V_FILE_SYSTEM_BINARY_END) ||
            (pPkgInfo->m_extra_info[i].m_bin_type == ARM_BL) ||
            (pPkgInfo->m_extra_info[i].m_bin_type == ARM_EXT_BL) ||
            (pPkgInfo->m_extra_info[i].m_bin_type == DUALMAC_DSP_BL) ||
            (pPkgInfo->m_extra_info[i].m_bin_type == FOTA_UE) ) )
      {
         return BL_CD_ERROR_INVALID_UPDATING_BINARY;
      }

      if(pPkgInfo->m_extra_info[i].m_bin_type == SECONDARY_MAUI ||
         pPkgInfo->m_extra_info[i].m_bin_type == ON_DEMAND_PAGING ||
         pPkgInfo->m_extra_info[i].m_bin_type == THIRD_ROM )
      {
         return BL_CD_ERROR_INVALID_UPDATING_BINARY;
      }

      //MAUI should start with the address as the current one
      if(pPkgInfo->m_extra_info[i].m_bin_type == PRIMARY_MAUI)
      {
         //Since the DL-pkg is not remapped, the MAUI_ROM_START_ADDR should not remapped
         if(pPkgInfo->m_extra_info[i].m_bin_start_addr != (MAUI_ROM_START_ADDR&REMAPPING_MASK))
         {
            return BL_CD_ERROR_INVALID_BINARY_ADDRESS;
         }
      }

      //Check if there is any region overlapping the others
      for(j=0; j<i-1; j++)
      {
         if(bl_IsValidBinInfoItem(&pPkgInfo->m_extra_info[j]))
         {
            if( IS_OVERLAP(pPkgInfo->m_extra_info[i].m_bin_start_addr, pPkgInfo->m_extra_info[i].m_bin_length,
                           pPkgInfo->m_extra_info[j].m_bin_start_addr, pPkgInfo->m_extra_info[j].m_bin_length ))
               return BL_CD_ERROR_REGION_OVERLAP;
         }
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
      return BL_CD_ERROR_INVALID_BINARY_OPERATION;
   }

   return BL_CD_ERROR_NONE;
}


//Working buffer structure
// GFH                        <-- pDl_Package_GFH
// NAND_IMAEG_HEADER          <-- pDl_Package_Nand_Image_Header                                          (NAND Only)
// FDM MAPPING tbl            <-- pFDM5MappingTbl (May be NULL if mapping table is too big to load)      (NAND Only)
// Signature * 2              <-- pSignatureBegin

BL_CD_ERROR_CODE bl_LoadAndCheckPKGHeader()
{
   //Read the GFH
   pDl_Package_GFH = (DL_PACKAGE_GFH*)work_buf;

   memset(pDl_Package_GFH, 0, sizeof(DL_PACKAGE_GFH));

   if( bl_DL_Read(pDl_Package_GFH, sizeof(DL_PACKAGE_GFH)) != sizeof(DL_PACKAGE_GFH) )
   {
      return BL_CD_ERROR_NO_DL_PACKAGE_FOUND;
   }

   //Check if there are marks of DL package
   if(GFH_GET_MAGIC(pDl_Package_GFH->gfh_file_info.m_gfh_hdr.m_magic_ver)       != GFH_HDR_MAGIC ||
      GFH_GET_MAGIC(pDl_Package_GFH->gfh_dl_package_info.m_gfh_hdr.m_magic_ver) != GFH_HDR_MAGIC ||
      pDl_Package_GFH->gfh_file_info.m_file_type != CARD_DOWNLOAD_PACKAGE                        ||
      pDl_Package_GFH->gfh_dl_package_info.m_gfh_hdr.m_type != GFH_DL_PACKAGE_INFO               ||
      strcmp((kal_char*)pDl_Package_GFH->gfh_dl_package_info.m_identifier, GFH_DL_PACKAGE_ID)
      )
   {
      return BL_CD_ERROR_NO_DL_PACKAGE_FOUND;
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
      return BL_CD_ERROR_PACKAGE_READ_FAIL;
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
      BL_CD_ERROR_CODE status = bl_ExtraInfoCheck();
      if(status != BL_CD_ERROR_NONE)
      {
         return status;
      }
   }

   return BL_CD_ERROR_NONE;
}

BL_CD_ERROR_CODE bl_ParseAndVerifyPKGHeader()
{
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;
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

      //Also assume all the image records can be loaded in to the working buffer, or error BL_CD_ERROR_INSUFFICIENT_WORKING_BUF occurs

      read_page = MIN((pWorkBufEnd-(kal_uint8*)pDl_Package_Nand_Image_Header)/page_size, page_per_block);
      status = bl_ReadXIMPage((kal_uint32)pDl_Package_Nand_Image_Header, 0, read_page, KAL_TRUE);

      if(status != BL_CD_ERROR_NONE)
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
         return BL_CD_ERROR_INSUFFICIENT_WORKING_BUF;
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

         if(status != BL_CD_ERROR_NONE)
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
       return BL_CD_ERROR_INSUFFICIENT_WORKING_BUF;
   }

   //"Signatures+GFH+ImageHeader" are bigger than the DL package? Impossible...
   ASSERT_VALID_PARAM_IN_NAND_IMAEG_HEADER(dl_package_size >= signatureLength + nand_image_header_len + pDl_Package_GFH->gfh_file_info.m_content_offset);
#endif /* _NAND_FLASH_BOOTING_ */

   //Seek and read
   if(bl_DL_Seek(dl_package_size - signatureLength, 0) != 0)
   {
      status = BL_CD_ERROR_PACKAGE_SEEK_FAIL;
   }

   if(status == BL_CD_ERROR_NONE)
   {
      if(bl_DL_Read(pSignatureBegin, signatureLength) != signatureLength)
      {
         status = BL_CD_ERROR_PACKAGE_READ_FAIL;
      }
   }

   if(custom_get_CDL_asymmetric_key_len() && status == BL_CD_ERROR_NONE)
   {
      if( bl_DL_SignatureVerify(hash_value, sizeof(hash_value), pSignatureBegin, signatureLength/2) == KAL_FALSE)
      {
         BL_PRINT(LOG_WARN, "Invalud header signature\n\r");
         status = BL_CD_ERROR_INVALIDE_HEADER_SIG;
      }
   }

#ifdef __SV5_ENABLED__
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
#endif /* __SV5_ENABLED__ */

   return status;

}

BL_CD_ERROR_CODE bl_VerifyPKGBody()
{
   /* Check the integrity of body of the DL package, and version by the way */
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;
   kal_uint32 currentPage = 0;
   kal_uint32 rominfo_addr = 0;


   kal_uint32 pkgFC;
   kal_uint32 pkgPairedVer, romPairedVer;
   kal_uint8  pkgSWVer[64], romSWVer[64];
   kal_uint8  pkgPlatformId[128], romPlatformId[128];
   kal_uint32 romSearchBase = MAUI_ROM_START_ADDR;

   const kal_uint32 updateFreq = (im_file_size/page_size_with_spare) * 0.05; //Update progress bar every 5%

   if(bl_DL_Seek(currentPage*page_size_with_spare, 0) != 0)
   {
      return BL_CD_ERROR_PACKAGE_SEEK_FAIL;
   }

   if(custom_get_CDL_asymmetric_key_len())
   {
      bl_Alg_Hash_Init();

      //Hash the header
      bl_Alg_Hash_Append((kal_uint32)pDl_Package_GFH, sizeof(*pDl_Package_GFH));

      while(currentPage < im_file_size/page_size_with_spare)
      {
         status = bl_ReadXIMPage((kal_uint32)page_buffer, currentPage, 1, KAL_TRUE);

         if(status != BL_CD_ERROR_NONE)
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

      bl_Alg_Hash_Finish((kal_uint32)hash_value, sizeof(hash_value));

      if( bl_DL_SignatureVerify(hash_value, sizeof(hash_value), pSignatureBegin+signatureLength/2, signatureLength/2) == KAL_FALSE )
      {
         BL_PRINT(LOG_WARN, "Invalid body signature\n\r");
         status = BL_CD_ERROR_INVALIDE_BODY_SIG;
      }

      BL_PRINT(LOG_DEBUG, "done\n\r");
   }

   //Loading version related info and let customer to do check

#ifndef __SV5_ENABLED__

   //Load the info from T-flash (SV3)
   if(status == BL_CD_ERROR_NONE)
   {
#ifdef _NAND_FLASH_BOOTING_
      status = bl_LoadILBInXIM();
      rominfo_addr = (kal_uint32)rominfo_page;
#else /* _NAND_FLASHING_BOOTING_ */
      status = bl_LoadRomInfoInXIM();
      rominfo_addr = (kal_uint32)rominfo_buf;
#endif /* _NAND_FLASHING_BOOTING_ */

      pkgPairedVer = SST_Get_MAUI_Paired_Version(rominfo_addr);
      SST_Get_MAUI_Feature_Combination(rominfo_addr, &pkgFC);
      SST_Get_SW_Version(rominfo_addr, pkgSWVer, sizeof(pkgSWVer));
      SST_Get_Platform_ID(rominfo_addr, pkgPlatformId, sizeof(pkgPlatformId));
   }

   //Load the info from flash (rom)
   if(status == BL_CD_ERROR_NONE)
   {
      romPairedVer = SST_Get_MAUI_Paired_Version(romSearchBase);
      SST_Get_SW_Version(romSearchBase, romSWVer, sizeof(romSWVer));
      SST_Get_Platform_ID(romSearchBase, romPlatformId, sizeof(romPlatformId));
   }
   
#else  /* #ifndef __SV5_ENABLED__ */

   //Load the info from T-flash (SV5)
   if(status == BL_CD_ERROR_NONE)
   {
      GFH_MAUI_INFO_v1 *pMauiInfo;
	  
      status = bl_LoadpMauiGFHInfoInXIM();
      if(status != BL_CD_ERROR_NONE)
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
   if(status == BL_CD_ERROR_NONE)
   {
      GFH_MAUI_INFO_v1 *pMauiInfoInTarget;      

#ifdef _NAND_FLASH_BOOTING_
      extern GFH_MAUI_INFO_v1 *bl_GetMAUIInfo(void);

      //If last CDL is failed. the GFH might be corrupted. Thus use the version in the MAUI info backuped in CBR.
      if(last_cdl_fail_flag == KAL_TRUE)
      {
         //The UpdatingRecord should already be got successfully in bl_IsCardDownloadGoing()
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

      //If last CDL is failed. the GFH might be corrupted.
      //Thus use the version in the MAUI info backuped at 2nd page of 2nd block
      if(last_cdl_fail_flag == KAL_TRUE)
      {
         kal_uint32 addr = maui_addr + g_ftlFuncTbl->FTL_GetBlockSize(bl_AddrToBlockIdx(maui_addr, NULL), NULL) + page_size;
      
         if(GFH_Find((U32)addr, GFH_MAUI_INFO, (void **)&pMauiInfoInTarget) != B_OK)
         {
            return BL_CD_ERROR_NO_ROM_GFH_MAUI_INFO_FOUND;
         }
      }
      else
      {  //There is no "Last update fail", thus get the maui info from GFH
         if(GFH_Find((U32)maui_addr, GFH_MAUI_INFO, (void **)&pMauiInfoInTarget) != B_OK)
         {
            return BL_CD_ERROR_NO_ROM_GFH_MAUI_INFO_FOUND;
         }
         //backup the flash pmaui gfh info into global variable
         memcpy(flash_pmaui_gfh_buf, (void*)maui_addr, page_size);
      }
         
#endif /* _NAND_FLASH_BOOTING_*/
        
      romPairedVer = pMauiInfoInTarget->m_bl_maui_paired_ver;
      memcpy(romSWVer, pMauiInfoInTarget->m_project_id, sizeof(romSWVer));
      memcpy(romPlatformId, pMauiInfoInTarget->m_platform_id, sizeof(romPlatformId));

   }

#endif /* #ifndef __SV5_ENABLED__*/

   

   //Check the info
   if(status == BL_CD_ERROR_NONE)
   {
      //Call customer's function to check

      //Paired version of BL must be matched the one in XIM

      if(romPairedVer == 0)
      {
         return BL_CD_ERROR_NO_ROM_INFO_FOUND;
      }
      if(pkgPairedVer == 0)
      {
         return BL_CD_ERROR_NO_PKG_ROM_INFO_FOUND;
      }

      if(pkgPairedVer != romPairedVer)
      {
         return BL_CD_ERROR_MISMATCHED_BL_PAIRED_VERION;
      }

      //Chech if the current BL can support the features in XIM
      
      if(CheckFeatureCompatibility(pkgFC) == KAL_FALSE)
      {
         return BL_CD_ERROR_INCOMPATIBLE_FEATURES;
      }

      //Check if this upgrade/downgrade is allowed. Cusomter can choose the criteria

      //Make sure they are all null-terminated
      pDl_Package_GFH->gfh_dl_package_info.m_project_id[sizeof(pDl_Package_GFH->gfh_dl_package_info.m_project_id)-1] = 0;
      pkgSWVer[sizeof(pkgSWVer)-1] = 0;
      romSWVer[sizeof(romSWVer)-1] = 0;

      if( custom_CDL_check_dl_package_version(romSWVer, pkgSWVer, pDl_Package_GFH->gfh_dl_package_info.m_project_id) == KAL_FALSE )
      {
         return BL_CD_ERROR_MISMATCH_DLPKG_SW_VER;
      }

      //Make sure they are all null-terminated
      pDl_Package_GFH->gfh_dl_package_info.m_platform_id[sizeof(pDl_Package_GFH->gfh_dl_package_info.m_platform_id)-1] = 0;
      pkgPlatformId[sizeof(pkgPlatformId)-1] = 0;
      romPlatformId[sizeof(romPlatformId)-1] = 0;

      if( custom_CDL_check_dl_platform_id(romPlatformId, pkgPlatformId, pDl_Package_GFH->gfh_dl_package_info.m_platform_id) == KAL_FALSE )
      {
         return BL_CD_ERROR_MISMATCH_DLPKG_PLATFORM_ID;
      }

      if( custom_CDL_customer_info_check((kal_uint32*)&pDl_Package_GFH->gfh_dl_package_info.m_customer_info, sizeof(pDl_Package_GFH->gfh_dl_package_info.m_customer_info)) != KAL_TRUE)
      {
         return BL_CD_ERROR_CUSTOM_CHECK_FAIL;
      }
   }

   return status;
}

void bl_ShowCDLSuccess(void)
{
#ifdef __LCD_DRIVER_IN_BL__
   BL_ShowUpdateFirmwareOK();
#endif /* __LCD_DRIVER_IN_BL__ */
}

void bl_ShowCDLError(BL_CD_ERROR_CODE status)
{
#ifdef __LCD_DRIVER_IN_BL__
   kal_uint32 i;

   typedef struct {
      BL_CD_ERROR_CODE error_start;
      BL_CD_ERROR_CODE error_end;
      kal_uint16 rgb[3];
   } ERROR_MAP;

   const ERROR_MAP error_map[] =
   {
      {BL_CD_ERROR_INVALID_XIM_START,          BL_CD_ERROR_INVALID_XIM_END,           {255, 255,   0} }, //Yellow
      {BL_CD_ERROR_VERSION_ERROR_START,        BL_CD_ERROR_VERSION_ERROR_END,         {255,   0, 255} }, //Purple
      {BL_CD_ERROR_ILB_ERROR_START,            BL_CD_ERROR_ILB_ERROR_END,             {  0, 255, 255} }, //Light blue
      {BL_CD_ERROR_UPDATE_ERROR_START,         BL_CD_ERROR_UPDATE_ERROR_END,          {255,   0,   0} }, //Red
      {BL_CD_ERROR_PACKAGE_ACCESS_ERROR_START, BL_CD_ERROR_PACKAGE_ACCESS_ERROR_END,  {  0,   0, 255} }, //Blue
      {BL_CD_ERROR_FLASH_ERROR_START,          BL_CD_ERROR_FLASH_ERROR_END,           {  0, 255,   0} }, //Green
   };

   if(status == BL_CD_ERROR_NONE)
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
#endif /* __LCD_DRIVER_IN_BL__ */

}

BL_CD_ERROR_CODE bl_UpdateMain(kal_bool forcedExec)
{
   BL_CD_ERROR_CODE status = BL_CD_ERROR_NONE;
   
#if defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
#endif

   BL_PRINT(LOG_DEBUG, "Acessing T-FLASH...\n\r");
   //Step1. Open update file
   status = bl_DL_Open(DUMMY_FILENAME);

   if(status == BL_CD_ERROR_NONE)
   {
      //Step2. Check if valid PKG file exists
      status = bl_LoadAndCheckPKGHeader();
   }
   else
   {
      BL_PRINT(LOG_DEBUG, "Open T-FLASH failed...%d\n\r", status);
   }

   if(status == BL_CD_ERROR_NO_CARD_FOUND || status == BL_CD_ERROR_NO_DL_PACKAGE_FOUND)
   {
      BL_PRINT(LOG_INFO, "No Card found or no update package found, %d\n\r", status);
      if(forcedExec)
      {
         bl_ShowCDLError(status);
      }
      else
      {
         bl_ClearCardDownloadTrigger();
      }

      bl_DL_Close();

      return status;
   }

   BL_PRINT(LOG_INFO, "\n\r");

   //Step3. Integrity check
   if(status == BL_CD_ERROR_NONE)
   {
      bl_UpdateProgress(VERIFY_PHASE, 0);
      BL_PRINT(LOG_INFO, "[Check header]\n\r");
      status = bl_ParseAndVerifyPKGHeader();
      if(status != BL_CD_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "Update Package Herader is bad...%d\n\r", status);
   }
   }

   if(status == BL_CD_ERROR_NONE)
   {
      BL_PRINT(LOG_INFO, "[Check body]\n\r");
      status = bl_VerifyPKGBody();
      if(status != BL_CD_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "Update Package Body is bad...%d\n\r", status);
      }
   }

#ifdef __BAD_BLOCK_EMULATION__

   if(status == BL_CD_ERROR_NONE)
   {
      extern flash_info_2 Flash_Info;
      kal_uint32 totalBlock = Flash_Info.deviceInfo_CE[0].deviceSize*1024/(block_size/1024);
      bl_MakeBadBlockTable(ilbStart, ilbEnd, ilbEnd+1, totalBlock-1);
   }

#endif

   //Step4.0 Init flash driver and check device status
   if(status == BL_CD_ERROR_NONE)
   {
      if(g_ftlFuncTbl->FTL_Init(NULL) != FTL_SUCCESS)
      {
         status = BL_CD_ERROR_FLASH_INIT_FAIL;
      }

      if(status != BL_CD_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "Init FTL is failed...%d\n\r", status);
   }

   }

   if(status == BL_CD_ERROR_NONE)
   {
      status = bl_CheckFlashDeviceStatus();
      if(status != BL_CD_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "Check falsh device is failed..%d\n\r", status);
   }

   }

   //Step4.1 Start to updating
   if(status == BL_CD_ERROR_NONE)
   {
      BL_PRINT(LOG_INFO, "[Initiate update]\n\r");
      status = bl_InitialUpdate();
      if(status != BL_CD_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "Initial Update is failed...%d\n\r", status);
      }
   }

   if(status == BL_CD_ERROR_NONE)
   {
      if(pDl_Package_GFH->gfh_dl_package_info.m_reserve1[0] & 0x02)
      {
         kal_uint32 i,j;

#ifdef _NAND_FLASH_BOOTING_
#ifndef __SV5_ENABLED__
         i = bl_GetILBEnd()+1;
         j = pDl_Package_Nand_Image_Header->plane_size*1024/pDl_Package_Nand_Image_Header->block_size-1;
#else /* __SV5_ENABLED__ */
         i = (BL_Shared_info.m_bl_flash_layout.region[0].u.nandEmmc.startPage)/page_per_block;
         j = pDl_Package_Nand_Image_Header->plane_size*1024/pDl_Package_Nand_Image_Header->block_size-1;
#endif /* __SV5_ENABLED__ */

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
      if(status != BL_CD_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "DoUpdate Body is failed...%d\n\r", status);
      }

   }

   //Step5. Post-process and clean up
   if(status == BL_CD_ERROR_NONE)
   {
      bl_UpdateProgress(FINISH_PHASE, 0);

#ifdef _NAND_FLASH_BOOTING_
      BL_PRINT(LOG_WARN, "[Update image list block]\n\r");

#ifndef __SV5_ENABLED__
      status = bl_UpdateImageList(bl_GetILBStart(), bl_GetILBEnd());

      if(status != BL_CD_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "Update ILB is failed...%d\n\r", status);
      }
#else /* __SV5_ENABLED__ */

      status = bl_UpdateImageInfo();

      if(status != BL_CD_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "Update Image Info is failed...%d\n\r", status);
      }

#endif /* __SV5_ENABLED__ */

#endif /* _NAND_FLASH_BOOTING_ */
   }

   if(status == BL_CD_ERROR_NONE)
   {
      bl_UpdateProgress(FINISH_PHASE, 50);
      BL_PRINT(LOG_INFO, "[Clean up]\n\r");

      status = bl_FinishUpdate();
      if(status != BL_CD_ERROR_NONE)
      {
         BL_PRINT(LOG_DEBUG, "Cannot finish...%d\n\r", status);
      }

   }

   if(status == BL_CD_ERROR_NONE)
   {
      bl_UpdateProgress(FINISH_PHASE, 100);
      bl_ShowCDLSuccess();
      bl_DL_Close();

      BL_PRINT(LOG_INFO, "[Update done]\n\r");
      WacthDogDisable();
      while(1)
      {
         bl_DetectPowerOff();
      }
   }
   else
   {
      bl_ShowCDLError(status);
      WacthDogDisable();
      while(1)
      {
         BL_PRINT(LOG_ERROR, "***Something wrong during update, status=%d\n\r", status);
         bl_DetectPowerOff();
      }
   }

   return status;
}

#endif /* __EXT_BOOTLOADER__ */

#endif /* __CARD_DOWNLOAD__ */


