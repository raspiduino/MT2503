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
 *   fue.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This is FOTA FUE header
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h"
#include "custom_img_config.h"
#include "fue_err.h"

#ifndef __FUE_H__
#define __FUE_H__

/*****************************************************************************
 * Macro definition
 *****************************************************************************/

/* maximum updatable image number */
#define FOTA_MAX_IMAGE_AMOUNT  (10)

#define REMAPPING_ADDRESS 0x08000000

//#define FOTA_UA_IMAGE_SIZE               (0x20000)
//#define FOTA_UA_IMAGE_ADDRESS            (0x00000000)

#define FOTA_FUE_NFB_LOADER_SHARED_BASE  (0x40000000)

#define BL_IMAGE_LIST_VALID    (0x56534C49)
#define BL_HEADER_INFO_VALID   (0x41564842)

/* FUE test bench */
//#define __FUE_TEST__
//#define __FUE_STRESS_TEST__
//#define __FUE_UNIT_TEST__

#if defined(__FUE_STRESS_TEST__)

#define DEFAULT_UPDATE_TEST_PATTERN (0x55505453)

#define BL_LOAD_BACKUP_UA_TAG       (0x4C425541)

#endif

#define MAUI_IMAGE_INFO_RANGE    (0x400000)

#define MAUI_INVISIBLE_SPACE_SIZE (0x100000)

/* default content for non-occupied flash space */
#define FOTA_EMPTY_IMAGE_PATTERN (0xFF)

/* NAND flash access cache */
#define FUE_NAND_CACHE_VALID           (0x80000000)
#define FUE_NAND_CACHE_BLOCK_RANGE     (0x0000FFFF)
#define FUE_NAND_CACHE_BLOCK_MASK      (0x00FFFF00)
#define FUE_NAND_CACHE_BLOCK_OFFSET    (8)
#define FUE_NAND_CACHE_PAGE_RANGE      (0x000000FF)
#define FUE_NAND_CACHE_PAGE_MASK       (0x000000FF)
#define FUE_NAND_CACHE_PAGE_OFFSET     (0)

/*****************************************************************************
 * Option to enable/disable update package verification step
 *****************************************************************************/
//#define __FUE_BYPASS_PKG_VERIFICATION__

/*****************************************************************************
 * Type definition
 *****************************************************************************/
typedef struct {
   kal_uint32  m_tbl_map_block;
   kal_uint32  m_tbl_map_page;
} FOTA_MAP_Table_Info_st;

typedef struct {
   FOTA_MAP_Table_Info_st   m_fue_map;
} FOTA_FUE_Info_st;

typedef struct {
   kal_uint32  m_nvram_ro_base_addr;
   kal_uint32  m_nvram_ro_base_block;
   kal_uint32  m_nvram_ro_length;
} FOTA_NVRAM_RO_Info_st;

typedef struct {
   kal_uint32  m_pkg_area_start;
   kal_uint32  m_pkg_area_end;
} FOTA_Package_Area_Info_st;

typedef struct {
   kal_uint32                 m_image_base;
   kal_uint32                 m_image_size;
} FOTA_Image_Area_st;

typedef struct {
   kal_uint32              m_img_load_addr;
   kal_uint32              m_img_load_len;
   kal_uint32              m_img_reserved;
   kal_uint32              m_img_list_idx;
   FOTA_MAP_Table_Info_st  m_img_tbl_info;
} FOTA_Image_Load_Info_st;

typedef struct {
   kal_uint32                 m_fota_image_num;
   kal_uint32                 m_fota_third_rom_map;
   FOTA_FUE_Info_st           m_fota_fue_info;
   FOTA_NVRAM_RO_Info_st      m_fota_nvram_info;
   FOTA_Package_Area_Info_st  m_fota_pkg_area;
   FOTA_Image_Load_Info_st    m_fota_load_info[FOTA_MAX_IMAGE_AMOUNT];
} FOTA_Area_Info_Wrapper_st;

typedef struct {
   kal_uint32                 m_alloc_base;
   kal_uint32                 m_alloc_end;
} FOTA_Flash_Alloc_Range_st;

typedef struct {
    kal_uint32 m_fota_page_tag; /* bit31: valid, [23:8] physical block number,[7:0] page number */
    kal_uint32 m_fota_page_cache[FOTA_FLASH_MAX_PAGE_SIZE>>2];
} FOTA_NAND_Cache_Entry_st;

/*****************************************************************************
 * Constant definition
 *****************************************************************************/
#if defined(__FUE_STRESS_TEST__)
typedef enum {
   FUE_CREATE_INITIAL_BLOCK = 0x1000,
   FUE_FLUSH_INITIAL_RECORD,
   FUE_FLUSH_USER_RECORD,
   FUE_FLUSH_RECORD_REPLACE
} FUE_Test_Update_Point_st;
#endif

typedef enum
{
  FUE_UA_VERIFYING_PHASE = 0x45564155,  //"EVAU"
  FUE_UA_UPDATING_PHASE = 0x50554155,   //"PUAU"
  FUE_UA_COMPLETE_PHASE = 0x4F434155
} FUE_UA_INTERNAL_STATUS;

/*****************************************************************************
 * Data structure definition
 *****************************************************************************/
#if defined(_NAND_FLASH_BOOTING_)
#define FUE_Driver  FUE_Nand_Driver
#define FUE_Data    FUE_Nand_Data
#else /* !_NAND_FLASH_BOOTING_ */
#define FUE_Driver  FUE_Nor_Driver
#define FUE_Data    FUE_Nor_Data
#endif

/*****************************************************************************
 * Function declaration
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  FUE_Final
 * DESCRIPTION
 *  this function execte the last step of firmware update (mark update flag to UPDATE_DONE)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FUE_Final(void);

/*****************************************************************************
 * FUNCTION
 *  FUE_PutDest
 * DESCRIPTION
 *  this function store the content in buffer to rom, and encrypt the data for CHIP UID SUPPORT 
 * PARAMETERS
 *  StrmPtr: the pointer of zlib z_stream structure
 *  DestBuffer: the start address of ram buffer
 *  FinalFlag: indicate the last exection of this function, flush the data to rom
 * RETURNS
 *  void
 *****************************************************************************/
//kal_int32 FUE_PutDest(void* DestBuffer, z_stream* StrmPtr, kal_bool FinalFlag);
kal_int32 FUE_PutDest(void* DestBuffer, void* StrmPtr, kal_bool FinalFlag);

/*****************************************************************************
 * FUNCTION
 *  FUE_FirmwareUpdate
 * DESCRIPTION
 *  the main function of firmware update function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
FUE_ERROR_CODE FUE_FirmwareUpdate(void);

/*****************************************************************************
 * FUNCTION
 *  FUE_Start
 * DESCRIPTION
 *  the C main entry function 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void FUE_Start(void);

/*************************************************************************
* FUNCTION
*  dbg_trace_func
*
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
* NOTE
*
*************************************************************************/
typedef void (*dbg_trace_func)(kal_char *fmt,...);

typedef kal_uint32 (*fota_generic_get_func)(void);
typedef kal_bool   (*fota_power_on_func)(void);
typedef void       (*fota_show_progress_func)(kal_uint16 percentage);

typedef struct {
   fota_power_on_func      fota_power_on;
   fota_show_progress_func fota_show_progress;
   dbg_trace_func          fota_trace;
} FOTA_Helper_Func_st;


#endif /* __FUE_H__ */
