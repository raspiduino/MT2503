/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   spi_nand_v2.h
 *
 * Project:
 * --------
 *   BOOTROM
 *
 * Description:
 * ------------
 *   SPI-NAND Flash driver version 2
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __SPI_NAND_MTD_FDM50_INTERNAL_H__
#define __SPI_NAND_MTD_FDM50_INTERNAL_H__

//#define __SNAND_DEBUG__

#if !defined(__UBL__)
#define __SNAND_BI_CACHE__
#define __SNAND_SW_CRC__    // also required by __SNAND_THIRD_ROM_RECHARGE__
    #if defined(__SV5_ENABLED__) && defined(MT6260)
        #define __SNAND_THIRD_ROM_RECHARGE__    // NOTE: Can't be enabled in bootloader stage because ReCharge engine needs to refer to flash layout structure (MAUI only)
        //#define __SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__  // for UT busy powerloss
    #endif
#endif

#define __SNAND_CLEAR_SPARE_BEFORE_PROGRAM__

#if defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__)
    #define __SNAND_READ_DISTURBANCE_TEST__
#endif

#include "kal_general_types.h"
#include "reg_base.h"
#include "snand_hw.h"
#include "NAND_MTD_FDM50_internal.h"
#include "flash_opt.h"  // for NAND_FLASH_BASE_ADDRESS

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
    /*
     * Switch cacheable buffer to un-cacheable if possible in MTD
     * Disabled because of low effectivity and high risk (use system service private cache API)
     */

    //#define __SNAND_DYNAMIC_SWITCH_CACHEABILITY__
#endif

#ifdef __cplusplus
     extern "C" {
#endif

/*-----------------------------------------------------
 * Global Definitions
 *-----------------------------------------------------*/

#if defined(__SNAND_SW_CRC__)
typedef kal_uint16 crc_t;

#define _CRC_WIDTH  (8 * sizeof(crc_t))
#define _CRC_TOPBIT (1 << (_CRC_WIDTH - 1))
#define _CRC_POLYNOMIAL 0xD8
#endif

typedef struct
{
    kal_uint32  page_size;
    kal_uint32  row_addr;
    kal_uint32  col_addr;
    kal_uint32  data_bytes;
    kal_uint32  spare_bytes;    // spare area will be written in col_addr = page_size
    kal_uint8   * data;
    kal_uint8   * spare;
} SNAND_MTD_DRV_PARA;

// Supported SPI protocols
typedef enum {
     SNAND_UNDEF     = 0
    ,SNAND_SPI       = 1
    ,SNAND_SPIQ      = 2
} SNAND_Mode;

typedef enum {
     SNAND_PART_BEGIN       = 0
    ,SNAND_DATA_PART        = 0
    ,SNAND_SPARE_PART       = 1
    ,SNAND_PART_END         = 2
} SNAND_Data_Parts;

typedef union {
    kal_uint32   u32;
    kal_uint16   u16[2];
    kal_uint8    u8[4];
} SNAND_Uint;

// Register access macros
#define SNAND_ReadReg8(addr)          *((volatile unsigned char *)(addr))
#define SNAND_WriteReg16(addr, data)  *((volatile unsigned short *)(addr)) = (unsigned short)(data)
#define SNAND_WriteReg32(addr, data)  *((volatile unsigned int *)(addr)) = (unsigned int)(data)

// SPI-NAND Geometry
#define SNAND_PAGE_SIZE                         (2048)
#define SNAND_SPARE_SIZE                        (64)
#define SNAND_SECTOR_SIZE                       (512)
#define SNAND_MAC_MAX_DATA_SIZE                 (128)
#define SNAND_MAX_GPRAM_SIZE                    (160)
#define SNAND_FDM_SIZE                          (8)
#define SNAND_SECTOR_PER_PAGE                   (SNAND_PAGE_SIZE / SNAND_SECTOR_SIZE)
#define SNAND_PAGE_PER_BLOCK                    (64)
#define SNAND_SPARE_SIZE_PER_SECTOR             (16)
#define SNAND_MAX_GPRAM_DATA_SIZE               (512)

#if defined(__SNAND_BI_CACHE__)
    #define SNAND_BI_CACHE_CNT  (NAND_FLASH_BASE_ADDRESS / (SNAND_PAGE_SIZE * SNAND_PAGE_PER_BLOCK))
#endif  // __SNAND_BI_CACHE__

// SPI-NAND internal stuff
#define SNAND_AUTO_BUF_SIZE                     ((SNAND_PAGE_SIZE + (SNAND_SPARE_SIZE_PER_SECTOR * SNAND_SECTOR_PER_PAGE)) + 32)

// delay latency
#define SPI_NAND_RESET_LATENCY_US               (3 * 10)    // 0.3 us * 100
#define SPI_NAND_MAX_RDY_AFTER_RST_LATENCY_US   (10000)     // 10 ms
#define SPI_NAND_MAX_READ_BUSY_US               (100 * 40)  // period * 40, safe value (plus ECC engine processing time). MTK_INTERNAL_SPI_NAND_1 spec: Max 100 us
#define NFI_MAX_RESET_US                        (10)         // [By Designer Curtis Tsai] 50T @ 26Mhz (1923 ns) is enough

// debug stuff
#define SPI_NAND_MAX_POLLING_TIMES              (20)

// flag for SPI_NAND_Reset
#define SNAND_RST_CON                       (0x00000001)
#define SNAND_RST_DEV                       (0x00000002)
#define SNAND_RST_WAIT_READY                (0x00000004)

#if defined(__SNAND_AP_MONITOR__)

#define SNAND_APM_DATA_MAX_CNT              (10000)
#define SNAND_APM_BLOCK_MONITOR_MAX_CNT     (1024)

typedef enum
{
     SNAND_AP_READ = 0
    ,SNAND_AP_WRITE = 1
    ,SNAND_AP_ERASE = 2
} SNAND_AP_OPERATION;

typedef struct
{
    SNAND_AP_OPERATION  op;
    kal_uint8           hit;
    kal_uint16          block;
    kal_uint16          page;
    kal_uint32          time;
} SNAND_AP_STRUCT;

extern kal_uint32           g_snand_apm_cnt;
extern kal_uint32           g_snand_apm_wrapped;
extern SNAND_AP_STRUCT      g_snand_apm_data[SNAND_APM_DATA_MAX_CNT];
extern kal_uint32           g_snand_apm_block_monitor_data[SNAND_APM_BLOCK_MONITOR_MAX_CNT][64];

#endif  // __SNAND_AP_MONITOR__

//#define SNAND_COMMON_RawRead(a)             SNAND_COMMON_RawReadMac(a)
#define SNAND_COMMON_RawRead(a)             SNAND_COMMON_RawReadCustom(a)
//#define SNAND_COMMON_RawRead(a)             SNAND_COMMON_RawReadAuto(a)
#define SNAND_COMMON_RawWrite(a)            SNAND_COMMON_RawWriteAuto(a)
//#define SNAND_COMMON_RawWrite(a)            SNAND_COMMON_RawWriteMac(a)
#define SNAND_COMMON_BlockErase(a)          SNAND_COMMON_BlockEraseAuto(a)
//#define SNAND_COMMON_BlockErase(a)          SNAND_COMMON_BlockEraseMac(a)

#if defined(__MAUI_BASIC__) || defined(__SNAND_DEBUG__)
    #if !defined(__UBL__)
	    #define SNAND_dbg_print nandlog_print
    #else
        #define SNAND_dbg_print(...)
        #include "bl_common.h"  // for bl_print
    #endif
#else
    #define SNAND_dbg_print(...)
#endif

/*-----------------------------------------------------
 * Global API Declaration
 *-----------------------------------------------------*/

extern void         SNAND_COMMON_SetBadBlockMark(kal_uint16 mark, void * spare);
extern kal_uint16   SNAND_COMMON_GetBadBlockMark(void * spare);

#if defined(__SNAND_BI_CACHE__)
extern kal_uint32   snand_bicache_get_value(kal_uint32 * list, kal_uint32 index);
extern void         snand_bicache_set_value(kal_uint32 * list, kal_uint32 index, kal_uint32 val);
#endif  // __SNAND_BI_CACHE__

#if defined(__SNAND_SW_CRC__)
extern void         snand_crc_init(void);
extern crc_t        snand_crc_gen(kal_uint8 const message[], int nBytes);
extern kal_uint16   snand_crc_gen_for_spare(void * spare);
extern kal_uint16   snand_crc_get(void * spare);
extern void         snand_crc_set(kal_uint16 crc_code, void * spare);
extern crc_t        g_snand_crcTable[256];
#else
#define             snand_crc_init()
#define             snand_crc_gen(a, b)
#define             snand_crc_gen_for_spare(a)
#define             snand_crc_get(a)
#define             snand_crc_set(a, b)
#endif  // __SNAND_SW_CRC__

#if defined(__SNAND_THIRD_ROM_RECHARGE__)
extern kal_int32    snand_trr_handle_powerloss(void);
extern kal_int32    snand_trr_recharge(kal_uint32 stage, kal_uint32 * new_target_block);
#endif

#if defined(__SNAND_AP_MONITOR__)
extern void         snand_apm_init(void);
extern void         snand_apm_add_record(SNAND_AP_OPERATION op, kal_uint16 block, kal_uint16 page, kal_uint8 hit);
#endif  // __SNAND_AP_MONITOR__

/*-----------------------------------------------------
 * Debug Facility
 *-----------------------------------------------------*/
#if defined(__SNAND_DEBUG__)

#include "us_timer.h"

extern kal_uint32 INT_GetCurrentTime(void);

#define SNAND_TIME_INIT(timestamp_cnt, normalize_factor)                        kal_uint32 _time[timestamp_cnt]; kal_uint32 _normalize_factor = normalize_factor;
#define SNAND_TIME_RECORD(timestamp_slot)                                       _time[timestamp_slot] = ust_get_current_time()
#define SNAND_TIME_GET_DURATION_US(timestamp_slot_begin, timestamp_slot_end)    (ust_get_duration(_time[timestamp_slot_begin], _time[timestamp_slot_end]) * 12 / 13 / _normalize_factor)

typedef enum
{
     SNAND_SW_LAYER_FS          = 0
    ,SNAND_SW_LAYER_FDM         = 1
    ,SNAND_SW_LAYER_DAL         = 2
    ,SNAND_SW_LAYER_MTD_UPPER   = 3
    ,SNAND_SW_LAYER_MTD_LOWER   = 4
    ,SNAND_SW_LAYER_HW          = 5
    ,SNAND_SW_LAYER_CNT         = 6
} SNAND_Sw_Layer;

typedef enum
{
     SNAND_DEV_READ     = 0
    ,SNAND_DEV_PROGRAM  = 1
    ,SNAND_DEV_ERASE    = 2
    ,SNAND_DEV_CNT      = 3
} SNAND_Dev_Operation;

extern kal_uint32   g_snand_dbg_buf[(2112 + 4) / 4];
extern kal_uint32   g_snand_dbg_buf2[(2112 + 4) / 4];
extern kal_uint32   g_snand_dbg_spare[(64 + 4) / 4];
extern kal_uint32   g_snand_dbg_spare2[(64 + 4) / 4];
extern kal_uint32   g_snand_dbg_error_code;
extern kal_uint32   g_snand_dbg_error_code2;

extern void     SNAND_dbg_time_add_record(SNAND_Sw_Layer layer, SNAND_Dev_Operation op, kal_uint32 val);
extern void     SNAND_dbg_check_GF_status(kal_uint8 status, kal_uint32 row_addr);
extern void     SNAND_dbg_program_confirm(SNAND_P_U8 data, SNAND_P_U8 spare, kal_uint32 row_addr);
extern void     SNAND_dbg_time_init(void);
extern void     SNAND_dbg_time_dump(void);

#else   // !__SNAND_DEBUG__

#define         SNAND_TIME_INIT(timestamp_cnt, normalize_factor)
#define         SNAND_TIME_RECORD(timestamp_slot)
#define         SNAND_TIME_GET_DURATION_US(timestamp_slot_begin, timestamp_slot_end)

#define         SNAND_dbg_check_GF_status(a, b)
#define         SNAND_dbg_program_confirm(a, b, c)
#define         SNAND_dbg_time_add_record(a, b, c)
#define         SNAND_dbg_time_init()
#define         SNAND_dbg_time_dump()

#define         snand_dbg_crc_init()
#define         snand_dbg_crc_gen(a, b)
#define         snand_dbg_crc_get(a)
#define         snand_dbg_crc_set(a, b)

#endif // __SNAND_DEBUG__

#endif  // __SPI_NAND_MTD_FDM50_INTERNAL_H__

