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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *  SPI_NAND_MTD_FDM50.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is a SPI-NAND Flash MTD driver for NAND FDM 5.0.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *              HISTORY
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
 *==============================================================================
 *******************************************************************************/
#if defined(__NAND_FDM_50__) && defined(__SPI_NAND_SUPPORT__)

/*-----------------------------------------------------
 * Included Header Files
 *-----------------------------------------------------*/
#if defined __MTK_TARGET__
    #include "kal_general_types.h"
    #include "kal_public_api.h"
    #include "flash_opt.h"
    #include "fs_gprot.h"       // for file system error codes
    #include "reg_base.h"
    #include "intrCtrl.h"       // for IRQ related APIs
    #include "custom_SNAND.h"
    #include "combo_SNAND_config.h"
    #include "NAND_MTD_FDM50_internal.h"
    #include "SPI_NAND_MTD_FDM50_internal.h"
    #include "SPI_NAND_DevConfig.h"
    #include "dma_sw.h"
    #include "dma_hw.h"
    #include "drvpdn.h"         // for power control (SNAND_PowerCtl)
    #include "l1sm_public.h"    // for sleep mode lock and unlock (SNAND_PowerCtl)
    #include "drv_comm.h"
    #include "drv_hisr.h"       // for DRV_NFI_HISR_ID
    #include "NAND_DAL.h"
  	#include "NAND_DAL_internal.h"
	#include "kal_trace.h"
    #include "kal_internal_api.h"
    #include "dcl.h"
    #include "us_timer.h"       // for delay APIs
    #include "cache_sw.h"       // for judge if user buffer is cacheable
    #if defined(__SNAND_DYNAMIC_SWITCH_CACHEABILITY__)
    #include "mmu.h"
    #endif
#elif defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__) // PC Simulator
    #include <stdio.h>
    #include "fat_fs.h"
    #include "SPI_NAND_MTD_FDM50_internal.h"
    #include "SPI_NAND_DAL.h"
  	#include "NAND_DAL_internal.h"
   #if defined DAL_DLL_VERSION
       #define ASSERT(expr)    {if(!(expr)) { MTD_WriteErrMsg("[dbg_ASSERT]",#expr,__FILE__ ,__LINE__,0,0,0);return MTD_STATUS_ERROR;}}
       #define EXT_ASSERT(expr, x, y, z)  {if(!(expr)) { MTD_WriteErrMsg("[force_ASSERT]",#expr,__FILE__,__LINE__,x,y,z);return MTD_STATUS_ERROR;}}
   #else
   #include <assert.h>
   #define ASSERT    assert
   #define EXT_ASSERT(e, x, y, z)  assert(e)
   #endif
   #define NAND_LOGGING
    #define kal_mem_set  memset
    #define kal_mem_cpy memcpy
    #define kal_mem_cmp memcmp

    #define kal_retrieve_eg_events(a,b,c,d,e) do { } while (0);
    #define kal_query_systemInit() (KAL_FALSE)
    #define INT_QueryExceptionStatus() (KAL_FALSE)
#endif

#if defined(__SNAND_AP_MONITOR__)
kal_uint32          g_snand_apm_cnt = 0;
kal_uint32          g_snand_apm_wrapped = 0;
SNAND_AP_STRUCT     g_snand_apm_data[SNAND_APM_DATA_MAX_CNT];
kal_uint32          g_snand_apm_block_monitor_data[SNAND_APM_BLOCK_MONITOR_MAX_CNT][64];
#endif  // __SNAND_AP_MONITOR__

/*-----------------------------------------------------
 * Test Configurations
 *-----------------------------------------------------*/

#if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
extern kal_bool     g_snand_trr_reset_in_next_busy;
extern void         snand_trr_test_wdt_reset(void);
#endif

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__) // PC Simulator
#else
#include "us_timer.h"
void NANDTest_Reset(void);
extern kal_bool ResetInNextBusy;
extern kal_uint32 wSBusyTimeR, wEBusyTimeR, wTotalBusyTimeR, wTotalBusyNumR;
extern kal_uint32 wSBusTimeR, wEBusTimeR, wTotalBusTimeR, wTotalBusNumR, wSetDMATimeR;
extern kal_uint32 wSBusyTimeW, wEBusyTimeW, wTotalBusyTimeW, wTotalBusyNumW;
extern kal_uint32 wSBusTimeW, wEBusTimeW, wTotalBusTimeW, wTotalBusNumW;
extern kal_bool ProfileDetail;
#endif

/*
FDM_UT_Item ==  0  Basic test - MTD/DAL/FDM Layer Test
FDM_UT_Item ==  1  Stressing test - FDM Layer Test
*/

kal_uint8 FDM_UT_Item = 0;
kal_uint32 FDM_ERROR_BIT[8] = {0};

#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

/*-----------------------------------------------------
 * Local Definitions
 *-----------------------------------------------------*/

/*
 ****** Definition of dbg_ASSERT and force_ASSERT ******
 dbg_ASSERT:
          - For basic load prevalidation use. The code is used for RD debug.
 force_ASSERT:
          - For normal check, if those parameters are incorrect, system will fail.
          - We expect it should be found in the earlier stage.
*/
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__))
    #if defined __UBL__ /*bootloader case*/
        #if defined BL_DEBUG
            #define dbg_ASSERT(expr) {if(!(expr)) {dbg_print("dbg_ASSERT:%s line:%d\n",__FILE__,__LINE__);while(1); }}
        #else
            #define dbg_ASSERT(expr) {do { } while (0);}
        #endif
    #else
        #define dbg_ASSERT(expr) ASSERT(expr)
    #endif
#else
    #if defined __UBL__ /*bootloader case*/
        #if defined BL_DEBUG
            #define dbg_ASSERT(expr) {if(!(expr)) {dbg_print("dbg_ASSERT:%s line:%d\n",__FILE__,__LINE__);while(1); }}
        #else
            #define dbg_ASSERT(expr) {do { } while (0);}
        #endif
    #else
        #define dbg_ASSERT(expr) {do { } while (0);}
    #endif
#endif

#if defined __UBL__ /*bootloader case*/
    #define force_ASSERT(expr, e1, e2, e3) {if(!(expr)) {dbg_print("force_ASSERT:%s line:%d e1:%d,e2:%d,e3:%d\n",__FILE__,__LINE__, e1, e2, e3);while(1);}}
#else
    #define force_ASSERT(expr, e1, e2, e3) {EXT_ASSERT(expr, e1, e2, e3);}
#endif

/*-----------------------------------------------------
 * Local API Declaration
 *-----------------------------------------------------*/

void                SNAND_PowerInit(void);
void                SNAND_Reset(kal_uint32 rst_flag);
kal_uint32          SNAND_Util_GetTimeUS(void);
kal_uint32          SNAND_Util_GetTimeDurationUS(kal_uint32 time_begin, kal_uint32 time_end);
kal_bool            SNAND_Util_IsTimeout(kal_uint32 start_us, kal_uint32 timeout_us);
kal_uint8           SNAND_GPIO_Setting(void);
void                SNAND_Dev_Command_Ext(SNAND_Mode mode, const kal_uint8 cmd[], kal_uint8 data[], const kal_uint32 outl, const kal_uint32 inl);
kal_uint32          SNAND_ReverseByteOrder(kal_uint32 num);
void                SNAND_MacEnable(SNAND_Mode mode);
void                SNAND_MacTrigger(void);
void                SNAND_MacLeave(void);
kal_uint32          nAND_RESET(void);
void                SNAND_COMMON_ECCCon(kal_bool ecc_enable);


/*-----------------------------------------------------
 * External API Declaration
 *-----------------------------------------------------*/

extern kal_uint32   INT_GetCurrentTime(void);

#if defined(__UBL__) && defined(__SNAND_STT_EN__)
extern void         stt_snand_set_pll(kal_uint32 speed);
#endif

/*-----------------------------------------------------
 * Global Variables
 *-----------------------------------------------------*/

kal_uint8   g_b_snand_sm_handler;
kal_uint32  g_l_snand_combo_mem_idx = 0xFFFFFFFF;

#if defined(__SNAND_BI_CACHE__)
kal_uint32 g_snand_bi_cache_checked[(SNAND_BI_CACHE_CNT / 8) / sizeof(kal_uint32)] = {0};
kal_uint32 g_snand_bi_cache_bad[(SNAND_BI_CACHE_CNT / 8) / sizeof(kal_uint32)] = {0};
#endif  // __SNAND_BI_CACHE__

#if defined(__SNAND_SW_CRC__)
crc_t  g_snand_crcTable[256] = {    // CRC-16-CCITT
0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5,
0x60c6, 0x70e7, 0x8108, 0x9129, 0xa14a, 0xb16b,
0xc18c, 0xd1ad, 0xe1ce, 0xf1ef, 0x1231, 0x0210,
0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6,
0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c,
0xf3ff, 0xe3de, 0x2462, 0x3443, 0x0420, 0x1401,
0x64e6, 0x74c7, 0x44a4, 0x5485, 0xa56a, 0xb54b,
0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d,
0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6,
0x5695, 0x46b4, 0xb75b, 0xa77a, 0x9719, 0x8738,
0xf7df, 0xe7fe, 0xd79d, 0xc7bc, 0x48c4, 0x58e5,
0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823,
0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969,
0xa90a, 0xb92b, 0x5af5, 0x4ad4, 0x7ab7, 0x6a96,
0x1a71, 0x0a50, 0x3a33, 0x2a12, 0xdbfd, 0xcbdc,
0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a,
0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03,
0x0c60, 0x1c41, 0xedae, 0xfd8f, 0xcdec, 0xddcd,
0xad2a, 0xbd0b, 0x8d68, 0x9d49, 0x7e97, 0x6eb6,
0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70,
0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a,
0x9f59, 0x8f78, 0x9188, 0x81a9, 0xb1ca, 0xa1eb,
0xd10c, 0xc12d, 0xf14e, 0xe16f, 0x1080, 0x00a1,
0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067,
0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c,
0xe37f, 0xf35e, 0x02b1, 0x1290, 0x22f3, 0x32d2,
0x4235, 0x5214, 0x6277, 0x7256, 0xb5ea, 0xa5cb,
0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d,
0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447,
0x5424, 0x4405, 0xa7db, 0xb7fa, 0x8799, 0x97b8,
0xe75f, 0xf77e, 0xc71d, 0xd73c, 0x26d3, 0x36f2,
0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634,
0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9,
0xb98a, 0xa9ab, 0x5844, 0x4865, 0x7806, 0x6827,
0x18c0, 0x08e1, 0x3882, 0x28a3, 0xcb7d, 0xdb5c,
0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a,
0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0,
0x2ab3, 0x3a92, 0xfd2e, 0xed0f, 0xdd6c, 0xcd4d,
0xbdaa, 0xad8b, 0x9de8, 0x8dc9, 0x7c26, 0x6c07,
0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1,
0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba,
0x8fd9, 0x9ff8, 0x6e17, 0x7e36, 0x4e55, 0x5e74,
0x2e93, 0x3eb2, 0x0ed1, 0x1ef0
};
#endif  // __SNAND_SW_CRC__

#if defined(__SNAND_DEBUG__)
kal_uint32 g_snand_dbg_buf[(2112 + 4) / 4];
kal_uint32 g_snand_dbg_buf2[(2112 + 4) / 4];
kal_uint32 g_snand_dbg_spare[(64 + 4) / 4];
kal_uint32 g_snand_dbg_spare2[(64 + 4) / 4];
kal_uint32 g_snand_dbg_error_code = 0;
kal_uint32 g_snand_dbg_error_code2 = 0;
#endif  // __SNAND_DEBUG__

#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__) // PC Simulator
    char* file_name[2];
    void* file_hd[2];
    kal_uint8 user_def_cs_num;
    kal_uint32 user_def_id_data[2][2];/*2 CS, each need 2 DWORD size to describe*/
    kal_uint8 cur_CS;
    kal_uint32 DummyNFI_Reg[1]; /*For simulator*/
    kal_uint8 MTD_simu_buff[(4096+256)];
    const kal_uint32 DummyNFI_PSTA[1] = {0};
    #define PDN_CON0 ((volatile kal_uint16 *)(DummyNFI_Reg))  /*For simulator*/
    #define NFI_PSTA      ((volatile UINT32P)(DummyNFI_PSTA)) /*always return ready*/
    //simulation test
    static unsigned int PageWriteError, SpareWriteError, EraseError, PageReadError, SpareReadError;
#endif

#define NFI_EVENT   0x1
#if defined __MTK_TARGET__

#endif  // defined __MTK_TARGET__

#if (defined __UBL__)||(defined __FUE__)
static const kal_eventgrpid  nfi_egid = NULL;
#else // (defined __UBL__)||(defined __FUE__)
static kal_eventgrpid  nfi_egid = NULL;
#endif // (defined __UBL__)||(defined __FUE__)

kal_uint8               g_c_snand_io_protocol       = SNAND_SPI;
static kal_bool         g_b_snand_is_initialized    = KAL_FALSE;
static kal_uint8        g_c_snand_num_CS            = 1;

#if defined(__UBL__) && defined(__SNAND_STT_EN__)
extern kal_uint32       g_snand_clock;
#endif

/*
 * !!!!!! REMARKS !!!!!!!
 *
 * Please ensure MTD internal buffer is un-cacheable!!
 * Otherwise data may not be transferred sucessfully by DMA!!
 *
 */

#if !defined(__GNUC__)
    #ifdef __DYNAMIC_SWITCH_CACHEABILITY__
    #pragma arm section zidata = "NONCACHEDZI"
    #endif // __DYNAMIC_SWITCH_CACHEABILITY__

    #ifdef __UBL__
    #pragma arm section zidata = "EXT_UN_INIT_ZI"
    #endif // __UBL__
#endif // __GNUC__

__align(32) kal_uint8   g_snand_data_buf[SNAND_AUTO_BUF_SIZE];

#if !defined(__GNUC__)
    #ifdef __DYNAMIC_SWITCH_CACHEABILITY__
    #pragma arm section zidata
    #endif // __DYNAMIC_SWITCH_CACHEABILITY__
#endif // __GNUC__

#if defined(__MTK_TARGET__)
extern kal_bool INT_QueryExceptionStatus(void);
#endif // defined(__MTK_TARGET__)

extern char NAND_text_buff[100]; /*For debug message*/
extern const kal_uint8 ZEROBIT[256];

#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
    extern flash_list g_snand_id_table[];
#else
	extern const flash_list g_snand_id_table[];
#endif

extern flash_info_2 Flash_Info;
extern flash_list Default_ID_Table;
extern const kal_uint8 ID_512_Mask[8];
extern const kal_uint8 ID_2K_Mask[8];

extern NAND_MTD_SUB_DRIVER MTK_SPI_NAND_SUB_DRIVER_1;

//  Declaration for NAND flash booting

#if defined(_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(__SPI_NAND_SUPPORT__))

kal_uint32 NFB_FLASH_BASE_PAGE;
kal_int32                  NFBPageSize;
#if !defined(__NANDFDM_MULTI_INSTANCE__)
extern const kal_uint32   NFB_BASE_ADDRESS;
extern const kal_uint32 NFB_ALLOCATED_FAT_SPACE;
#else  // !defined(__NANDFDM_MULTI_INSTANCE__)
extern kal_uint32   NFB_BASE_ADDRESS[NAND_DISK_NUM];
extern kal_uint32 NFB_ALLOCATED_FAT_SPACE[NAND_DISK_NUM];
extern kal_uint8 CurDiskIndex;
#endif  // !defined(__NANDFDM_MULTI_INSTANCE__)
extern kal_bool DemandPageingRead;

#endif  // _NAND_FLASH_BOOTING_ || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && __SPI_NAND_SUPPORT__)

#if defined DAL_VERIFICATION
extern kal_uint8 Mtd_Fail_Offset;
#endif

// For NAND flash booting
kal_bool use_interrupt;  // KAL_TRUE for using interrupt; KAL_FALSE for using polling

mtd_if_para Mtd_para;

#if defined(__COMBO_MEMORY_SUPPORT__)
kal_uint8 ComboNANDID[8];
#endif

/*-----------------------------------------------------
 * API Bodies
 *-----------------------------------------------------*/

void SNAND_PowerInit()
{
#if (defined __UBL__) || (defined __FUE__)
    /*NFI should be power on at bootload and fota case*/
#elif defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
    /*Do nothing*/
#else
    g_b_snand_sm_handler = L1SM_GetHandle();
#endif
}

void SNAND_PowerCtl(kal_bool ON)
{
#if (defined __UBL__) || (defined __FUE__)
    /*NFI should be power on at bootload and fota case*/
#elif defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
    /*Do nothing*/
#else
    if (ON) // power up
    {
        PDN_CLR(PDN_NFI); //power up dev
        L1SM_SleepDisable(g_b_snand_sm_handler); //lock sleep mode
    }
    else    // power down
    {
        PDN_SET(PDN_NFI); //power down dev
        L1SM_SleepEnable(g_b_snand_sm_handler);  //unlock sleep mode
    }
#endif
}

#if defined(__SNAND_BI_CACHE__)
kal_uint32 snand_bicache_get_value(kal_uint32 * list, kal_uint32 index)
{
    kal_uint32 x, y;

    x = index / (8 * sizeof(kal_uint32));
    y = index % (8 * sizeof(kal_uint32));

    return ((list[x] >> y) & 0x00000001);
}


void snand_bicache_set_value(kal_uint32 * list, kal_uint32 index, kal_uint32 val)
{
    kal_uint32 x, y;
    kal_uint32 bit_mask;

    x = index / (8 * sizeof(kal_uint32));
    y = index % (8 * sizeof(kal_uint32));
    bit_mask = 1 << y;

    if (1 == val)
    {
        list[x] = list[x] | bit_mask;
    }
    else    // 0
    {
        list[x] = list[x] & ~bit_mask;
    }
}
#endif  // __SNAND_BI_CACHE__

#if !defined(__FUE__)

NAND_MTD_LOCK nfi_mtd_lock = {0, NULL, NULL};

// ===========================================================
//     Function definition
// ===========================================================

void init_MTD_lock(void)
{
    #if defined __UBL__ /*bootloader case*/
    #elif defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__) /*PC simulator*/
    #else
    if (nfi_mtd_lock.mtd_enhmutex == NULL)
    {
        nfi_mtd_lock.mtd_enhmutex = kal_create_enh_mutex("MTD_NFI_LOCK");
        nfi_mtd_lock.lock_count = 0;
        nfi_mtd_lock.owner_id = NULL;
    }
    #endif
}

void get_MTD_lock(void)
{
    #if defined __UBL__ /*bootloader case*/
    /*Do nothing*/
    #elif defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__) /*PC simulator*/
    /*Do nothing*/
    #else
    //kal_uint32 mask = 0;/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
    if( kal_query_systemInit() || INT_QueryExceptionStatus() )
        return;
    //mask = SaveAndSetIRQMask();/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
    if (kal_if_hisr() == KAL_TRUE || kal_if_lisr() == KAL_TRUE) /*MAUI_00756114*/
    {
        kal_uint32 retaddr0=0;
				#if defined(__MTK_TARGET__)
					#if defined(__ARMCC_VERSION)
						retaddr0 = __return_address();
					#elif defined(__GNUC__)
						retaddr0 = __builtin_return_address(0);
					#endif /* __RVCT__ , __GNUC__ */
				#endif  /* __MTK_TARGET__ */
        EXT_ASSERT(0, retaddr0, 0, 0);
    }
    // start of kuohong MP3
#if defined(__AUDIO_DSP_LOWPOWER__)
    AUDMA_LOCK(AUDMA_ID_NFI);
#endif
    // end of kuohong MP3
    if( kal_get_task_self_id() == nfi_mtd_lock.owner_id )
    {
        force_ASSERT(0 != nfi_mtd_lock.lock_count, nfi_mtd_lock.lock_count, (kal_uint32)nfi_mtd_lock.owner_id, (kal_uint32)nfi_mtd_lock.mtd_enhmutex);
        nfi_mtd_lock.lock_count++;
        //RestoreIRQMask(mask);/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
    }
    else
    {
        if(nfi_mtd_lock.mtd_enhmutex == NULL)
        {
              init_MTD_lock();
        }
        //RestoreIRQMask(mask);/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
        kal_take_enh_mutex(nfi_mtd_lock.mtd_enhmutex);
        nfi_mtd_lock.owner_id = kal_get_task_self_id();
        nfi_mtd_lock.lock_count++;
    }
    #endif
}

void free_MTD_lock(void)
{
    #if defined __UBL__ /*bootloader case*/
    /*Do nothing*/
    #elif defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__) /*PC simulator*/
    /*Do nothing*/
    #else
    //kal_uint32 mask = 0;/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
    if( kal_query_systemInit() || INT_QueryExceptionStatus() )
        return;
    //mask = SaveAndSetIRQMask();/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
#if defined(__AUDIO_DSP_LOWPOWER__)
    // start of kuohong MP3
    AUDMA_UNLOCK(AUDMA_ID_NFI);
    // end of kuohong MP3
#endif
    if( kal_get_task_self_id() == nfi_mtd_lock.owner_id )
    {
        force_ASSERT(nfi_mtd_lock.lock_count > 0, nfi_mtd_lock.lock_count, (kal_uint32)nfi_mtd_lock.owner_id, (kal_uint32)nfi_mtd_lock.mtd_enhmutex);
        nfi_mtd_lock.lock_count--;
        if(0 == nfi_mtd_lock.lock_count)
        {
            nfi_mtd_lock.owner_id = NULL;
            //RestoreIRQMask(mask);/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
            if(nfi_mtd_lock.mtd_enhmutex != NULL)
            {
              kal_give_enh_mutex(nfi_mtd_lock.mtd_enhmutex);
            }
        }
        //else /*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
            //RestoreIRQMask(mask);/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
    }
    else
    {
        //RestoreIRQMask(mask);/*Remove unnecessary disable IRQ 2007/05/24 Yehudi Chang*/
        force_ASSERT(0, (kal_uint32)nfi_mtd_lock.owner_id, (kal_uint32)kal_get_task_self_id(), (kal_uint32)nfi_mtd_lock.mtd_enhmutex);
    }
    #endif
}

#else /* !defined(__FUE__) */
#define init_MTD_lock()
#define get_MTD_lock()
#define free_MTD_lock()
#endif /* !defined(__FUE__) */

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
void dump_memory_to_uart_log(kal_uint32* buff, kal_uint32 leng)
{
	kal_uint32 offset;
	kal_uint32 length;
	length = leng;
	offset = 0;
	SNAND_dbg_print("!! dump start address %xh !! \r\n", (kal_uint32)buff);

	while(length > 0)
	{
		{
			SNAND_dbg_print("%xh, %xh, %xh, %xh\r\n", buff[offset+0], buff[offset+1], buff[offset+2], buff[offset+3]);
		}
		offset += 4;
		length -= 16;
	}

	SNAND_dbg_print("!! dump end !!\r\n");
}
#endif

void SNAND_WaitUS(kal_uint32 timeout_us)
{
    ust_busy_wait(timeout_us);
}

// fake MTD driver for DAL initialization (Need to refine DAL/MTD layer for better code structure in the future)
kal_uint32 single_Page_Program (mtd_drv_para *para) { return MTD_STATUS_NO_ERROR; };
kal_uint32 single_Page_Read (mtd_drv_para *para) { return MTD_STATUS_NO_ERROR; };
kal_uint32 single_Block_Erase (mtd_drv_para *para) { return MTD_STATUS_NO_ERROR; };

kal_uint32 SNAND_ReverseByteOrder(kal_uint32 num)
{
   kal_uint32 ret = 0;

   ret |= ((num >> 24) & 0x000000FF);
   ret |= ((num >> 8)  & 0x0000FF00);
   ret |= ((num << 8)  & 0x00FF0000);
   ret |= ((num << 24) & 0xFF000000);

   return ret;
}

kal_uint32 SNAND_GPRAM_Write_C1A3(const kal_uint32 cmd, const kal_uint32 address)
{
    return ((SNAND_ReverseByteOrder(address) & 0xFFFFFF00) | (cmd & 0xFF));
}

/**
 * @brief This funciton enables MAC mode for issuing commands to serial flash.
 *
 * @remarks: !NOTE! This function must be used with SNAND_MacTrigger in pair!
 */
void SNAND_MacEnable(SNAND_Mode mode)
{
    int mac;

    mac = *RW_SNAND_MAC_CTL;

    // SPI
    if (SNAND_SPI == mode)
    {
        mac &= ~SNAND_MAC_SIO_SEL;   // Clear SIO_SEL to send command in SPI style
        mac |= SNAND_MAC_EN;         // Enable Macro Mode
    }
    // QPI
    else
    {
        /*
         * SFI V2: QPI_EN only effects direct read mode, and it is moved into DIRECT_CTL in V2
         *         There's no need to clear the bit again.
         */
        mac |= (SNAND_MAC_SIO_SEL | SNAND_MAC_EN);  // Set SIO_SEL to send command in QPI style, and enable Macro Mode
    }

    SNAND_WriteReg32(RW_SNAND_MAC_CTL, mac);
}

/**
 * @brief This funciton triggers SFI to issue command to serial flash, wait SFI until ready.
 *
 * @remarks: !NOTE! This function must be used with SNAND_MacEnable in pair!
 */
void SNAND_MacTrigger(void)
{
    kal_uint32 mac;

    mac = *RW_SNAND_MAC_CTL;

    // Trigger SFI: Set TRIG and enable Macro mode
    mac |= (SNAND_TRIG | SNAND_MAC_EN);
    SNAND_WriteReg32(RW_SNAND_MAC_CTL, mac);

    /*
     * Wait for SFI ready
     * Step 1. Wait for WIP_READY becoming 1 (WIP register is ready)
     */
    while (!(*RW_SNAND_MAC_CTL & SNAND_WIP_READY));

    /*
     * Step 2. Wait for WIP becoming 0 (Controller finishes command write process)
     */
    while (*RW_SNAND_MAC_CTL & SNAND_WIP);


}

/**
 * @brief This funciton leaves Macro mode and enters Direct Read mode
 *
 * @remarks: !NOTE! This function must be used after SNAND_MacTrigger
 */
void SNAND_MacLeave(void)
{
    kal_uint32 mac;

    // clear SF_TRIG and leave mac mode
    mac = *RW_SNAND_MAC_CTL;

    /*
     * Clear following bits
     * SF_TRIG: Confirm the macro command sequence is completed
     * SNAND_MAC_EN: Leaves macro mode, and enters direct read mode
     * SNAND_MAC_SIO_SEL: Always reset quad macro control bit at the end
     */
    mac &= ~(SNAND_TRIG | SNAND_MAC_EN | SNAND_MAC_SIO_SEL);
    SNAND_WriteReg32(RW_SNAND_MAC_CTL, mac);
}

void SNAND_Dev_Command(const kal_uint32 cmd, kal_uint8 outlen)
{
    SNAND_WriteReg32(RW_SNAND_GPRAM_DATA, cmd);
    SNAND_WriteReg32(RW_SNAND_MAC_OUTL, outlen);
    SNAND_WriteReg32(RW_SNAND_MAC_INL , 0);
    SNAND_MacEnable(SNAND_SPI);
    SNAND_MacTrigger();
    SNAND_MacLeave();

    return;
}

void SNAND_Dev_Command_Ext(SNAND_Mode mode, const kal_uint8 cmd[], kal_uint8 data[], const kal_uint32 outl, const kal_uint32 inl)
{
    kal_uint32   tmp;
    kal_uint32   i, j;
    SNAND_P_U8  p_data, p_tmp;

    p_tmp=(SNAND_P_U8)(&tmp);

    // Moving commands into SFI GPRAM
    for (i = 0, p_data = ((SNAND_P_U8)RW_SNAND_GPRAM_DATA); i < outl; p_data += 4)
    {
        // Using 4 bytes aligned copy, by moving the data into the temp buffer and then write to GPRAM
        for (j = 0, tmp = 0; i < outl && j < 4; i++, j++)
        {
            p_tmp[j] = cmd[i];
        }

        SNAND_WriteReg32(p_data, tmp);
    }

    SNAND_WriteReg32(RW_SNAND_MAC_OUTL, outl);
    SNAND_WriteReg32(RW_SNAND_MAC_INL, inl);
    SNAND_MacEnable(mode);
    SNAND_MacTrigger();
    SNAND_MacLeave();

    // for NULL data, this loop will be skipped
    for (i = 0, p_data = ((SNAND_P_U8)RW_SNAND_GPRAM_DATA + outl); i < inl; ++i, ++data, ++p_data)
    {
        *data = SNAND_ReadReg8(p_data);
    }

    return;
}

void SNAND_GPRAM_Write(kal_uint32 gpram_offset, void* buff, kal_int32 length)
{
    kal_uint32 i;
    kal_uint8 *p_data=(kal_uint8*)buff;
    SNAND_Uint tmp;

    gpram_offset += (kal_uint32)RW_SNAND_GPRAM_DATA;

    // source address is 4-byte aligned, and gpram_offset is 4-bytes aligned, too
    if (0 == ((kal_uint32)buff & 0x3))    {
        for (;length > 0; gpram_offset+=4, p_data+=4, length-=4)        {
            SNAND_WriteReg32(gpram_offset, *(kal_uint32*)p_data);
        }
    }
    // source address is 2-byte aligned
    else if (0 == ((kal_uint32)p_data & 0x1))     {
        for (;length > 0; gpram_offset+=4, p_data+=4, length-=4)        {
            tmp.u16[0]=*(kal_uint16*)p_data;
            tmp.u16[1]=*((kal_uint16*)p_data + 1);
            SNAND_WriteReg32(gpram_offset, tmp.u32); // save local_data to SFI GPRAM
        }
    }
    // source data is NOT 2-byte aligned
    else    {
        for (;length > 0; gpram_offset+=4, length-=4)  {
            for (i=0; i<4 && i<length; i++) {
                tmp.u8[i]=*p_data++;
            }
            SNAND_WriteReg32(gpram_offset, tmp.u32); // save local_data to SFI GPRAM
        }
    }
}

void SNAND_MemCpy_ExtToInt(void * any_aligned_src, void* four_byte_aligned_dst, kal_int32 length)
{
    kal_uint32 i;
    kal_uint8 * p_src = (kal_uint8 *)any_aligned_src;
    kal_uint8 * p_dst = (kal_uint8 *)four_byte_aligned_dst;

    // dst address is 4-bytes aligned
    if (0 == ((kal_uint32)p_src & 0x3))
    {
        for (i = 0; length > 0; i += 4, length -= 4)
        {
            *(kal_uint32 *)(p_dst + i) = *(kal_uint32 *)(p_src + i);
        }
    }
    // dst address is 2-bytes aligned
    else if (0 == ((kal_uint32)p_src & 0x1))
    {
        for (i = 0; length > 0; i += 2, length -= 2)
        {
            *(kal_uint16 *)(p_dst + i) = *(kal_uint16 *)(p_src + i);
        }
    }
    // dst address is not 2-byte aligned
    else
    {
        for (i = 0; length > 0; i += 1, length -= 1)
        {
            *(p_dst + i) = *(p_src + i);
        }
    }
}

void SNAND_MemCpy_IntToExt(void * four_byte_aligned_src, void* any_aligned_dst, kal_int32 length)
{
    kal_uint32 i;
    kal_uint8 * p_src = (kal_uint8 *)four_byte_aligned_src;
    kal_uint8 * p_dst = (kal_uint8 *)any_aligned_dst;

    // dst address is 4-bytes aligned
    if (0 == ((kal_uint32)p_dst & 0x3))
    {
        for (i = 0; length > 0; i += 4, length -= 4)
        {
            *(kal_uint32 *)(p_dst + i) = *(kal_uint32 *)(p_src + i);
        }
    }
    // dst address is 2-bytes aligned
    else if (0 == ((kal_uint32)p_dst & 0x1))
    {
        for (i = 0; length > 0; i += 2, length -= 2)
        {
            *(kal_uint16 *)(p_dst + i) = *(kal_uint16 *)(p_src + i);
        }
    }
    // dst address is not 2-byte aligned
    else
    {
        for (i = 0; length > 0; i += 1, length -= 1)
        {
            *(p_dst + i) = *(p_src + i);
        }
    }
}


void SNAND_EnableSPIQ(kal_bool Enable)
{
    kal_uint8   regval;

    if ((SNAND_SPI == g_c_snand_io_protocol && KAL_FALSE == Enable) ||
        (SNAND_SPIQ == g_c_snand_io_protocol && KAL_TRUE == Enable))
    {
        return;
    }

    // read QE in status register
    *RW_SNAND_GPRAM_DATA = SNAND_CMD_GET_FEATURES | (SNAND_CMD_FEATURES_OTP << 8);
    *RW_SNAND_MAC_OUTL = 2;
    *RW_SNAND_MAC_INL = 1;
    SNAND_MacEnable(SNAND_SPI);
    SNAND_MacTrigger();
    SNAND_MacLeave();
    regval = SNAND_ReadReg8(((SNAND_P_U8)RW_SNAND_GPRAM_DATA + 2));

    if (KAL_FALSE == Enable)    // disable x4
    {
        if ((regval & SNAND_OTP_QE) == 0)
        {
            return;
        }
        else
        {
            regval = regval & ~SNAND_OTP_QE;
        }
    }
    else    // enable x4
    {
        if ((regval & SNAND_OTP_QE) == 1)
        {
            return;
        }
        else
        {
            regval = regval | SNAND_OTP_QE;
        }
    }

    // if goes here, it means QE needs to be set as new different value

    // write status register
    *RW_SNAND_GPRAM_DATA = SNAND_CMD_SET_FEATURES | (SNAND_CMD_FEATURES_OTP << 8) | (regval << 16);
    *RW_SNAND_MAC_OUTL = 3;
    *RW_SNAND_MAC_INL = 0;
    SNAND_MacEnable(SNAND_SPI);
    SNAND_MacTrigger();
    SNAND_MacLeave();

    if (Enable) g_c_snand_io_protocol = SNAND_SPIQ;
    else g_c_snand_io_protocol = SNAND_SPI;
}

// auto write x4
kal_uint32 SNAND_COMMON_RawWriteAuto(SNAND_MTD_DRV_PARA * para)
{
    kal_uint32  status    = MTD_STATUS_NO_ERROR;
    kal_uint32  polling_times;
    kal_uint32  reg;
    kal_uint32  len_to_write;
    kal_uint32  event_group;
    kal_bool    internal_buf_used = KAL_TRUE;

    SNAND_TIME_INIT(4, 1);
    SNAND_TIME_RECORD(0);

    // setup read length (started from col_addr, ended at spare_start + spare_bytes
    len_to_write = para->page_size - para->col_addr;

    if (para->data_bytes > len_to_write)
    {
        return MTD_STATUS_PARA_ERROR;
    }

    #if defined(__SNAND_AP_MONITOR__)
    snand_apm_add_record(SNAND_AP_WRITE, para->row_addr / 64, para->row_addr % 64, 0);
    #endif

    if (para->spare)
    {
        len_to_write += para->spare_bytes;

        #if defined(__SNAND_CLEAR_SPARE_BEFORE_PROGRAM__)
        /*
         * Set spare area other than SPARE[0] to 0xFF to avoid ECC UNCORRECTABLE due to unexpected data shift
         */
        if (SNAND_SPARE_FORMAT_MTK_1 == Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[7])
        {
            kal_uint32 offset;

            offset = (kal_uint32)&(((FDMDataU_2K_MTK_1 *)(para->spare))->Unused) - (kal_uint32)&(((FDMDataU_2K_MTK_1 *)(para->spare))->Reserved1[0]);

            for (; offset < Flash_Info.deviceInfo_CE[Mtd_para.ce].spareSize; offset++)
            {
                para->spare[offset] = 0xFF;
            }
        }
        else if (SNAND_SPARE_FORMAT_MTK_2 == Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[7])
        {
            kal_uint32 offset;

            offset = (kal_uint32)&(((FDMDataU_2K_MTK_2 *)(para->spare))->Unused) - (kal_uint32)&(((FDMDataU_2K_MTK_2 *)(para->spare))->Reserved1[0]);

            for (; offset < Flash_Info.deviceInfo_CE[Mtd_para.ce].spareSize; offset++)
            {
                para->spare[offset] = 0xFF;
            }
        }
        #endif  // __SNAND_CLEAR_SPARE_BEFORE_PROGRAM__

    }

    SNAND_EnableSPIQ(KAL_TRUE);

    if ((KAL_FALSE == INT_QueryIsCachedRAM(para->data, para->data_bytes)) &&
        (0 == ((kal_uint32)para->data & 0x3)))
    {
        if (para->spare)
        {
            if ((KAL_FALSE == INT_QueryIsCachedRAM(para->spare, para->spare_bytes)) &&
                (para->spare == para->data + para->page_size))
            {
                internal_buf_used = KAL_FALSE;
            }
        }
        else
        {
            internal_buf_used = KAL_FALSE;
        }
    }

    #if defined(__SNAND_SW_CRC__)
    {
        kal_uint16 crc_code_fdm_data;

        if ((para->spare) &&
            ((para->row_addr / SNAND_PAGE_PER_BLOCK) >= (NAND_FLASH_BASE_ADDRESS / (SNAND_PAGE_SIZE * SNAND_PAGE_PER_BLOCK))))  // file system only
        {
            crc_code_fdm_data = snand_crc_gen_for_spare(para->spare);

            snand_crc_set(crc_code_fdm_data, para->spare);
        }
    }
    #endif  // __SNAND_SW_CRC__

    if (KAL_TRUE == internal_buf_used)
    {
        kal_mem_cpy((void *)(&(g_snand_data_buf[para->col_addr])), (void *)(para->data), para->data_bytes);

        if (para->spare)
        {
            kal_mem_cpy((void *)(&(g_snand_data_buf[para->page_size])), (void *)(para->spare), para->spare_bytes);
        }
    }

    //------ SNF Part ------

    // set SPI-NAND command
    *RW_SNAND_PG_CTL1 = (SNAND_CMD_WRITE_ENABLE | (SNAND_CMD_PROGRAM_LOAD_X4 << SNAND_PG_LOAD_CMD_OFFSET) | (SNAND_CMD_PROGRAM_EXECUTE << SNAND_PG_EXE_CMD_OFFSET));

    // set program load address
    *RW_SNAND_PG_CTL2 = para->col_addr & SNAND_PG_LOAD_ADDR_MASK;

    // set program execution address
    *RW_SNAND_PG_CTL3 = para->row_addr;

    /*
     * set get feature polling limit
     *
     * Standby period = polling_cycle * base_time_slot
     * Base_time_slot = SPI_NAND_CLOCK_CYCLE * 128
     *
     * Example:
     * spi-nand clock=100M, 1T=10ns, then base_time_slot = 1.28us. The polling cycle value should be set to meet the Standby_period ~= spec time.
     *
     * Spec:
     * [MTK_INTERNAL_SPI_NAND_1] Page Program Time: Max 0.7 ms
     */
    *RW_SNAND_GF_CTL3 = ((SNAND_LOOP_LIMIT_NO_LIMIT << SNAND_GF_LOOP_LIMIT_OFFSET) & SNAND_GF_LOOP_LIMIT_MASK) | (1 & SNAND_GF_POLLING_CYCLE_MASK);

    // set SNF data length
    *RW_SNAND_MISC_CTL2 = len_to_write | (len_to_write << SNAND_PROGRAM_LOAD_BYTE_LEN_OFFSET);;

    // set SNF timing
    reg = *RW_SNAND_MISC_CTL;

    reg &= ~SNAND_DATA_READ_MODE_MASK;
    reg |= ((SNAND_DATA_READ_MODE_X4 << SNAND_DATA_READ_MODE_OFFSET) & SNAND_DATA_READ_MODE_MASK);

    reg |= SNAND_PG_LOAD_X4_EN;

    *RW_SNAND_MISC_CTL = reg;

    //------ NFI Part ------

    // reset NFI
    SNAND_Reset(SNAND_RST_CON);

    // set NFI page format
    *RW_NFI_PAGEFMT = NFI_PAGE_SIZE_2K | (NFI_SPARE_SIZE_16B << NFI_SPARE_SIZE_OFFSET);

    // set NFI configurations
    *RW_NFI_CNFG = (NFI_OP_MODE_PROGRAM_PROCESS << NFI_OP_MODE_OFFSET) | NFI_DMA_MODE | NFI_DMA_BURST_EN | (NFI_READ_MODE_RAM_TO_FLASH << NFI_READ_MODE_OFFSET);

    // set NFI buffer address
    if (KAL_TRUE == internal_buf_used)
    {
        *RW_NFI_STRADDR = (kal_uint32)(&(g_snand_data_buf[para->col_addr]));
    }
    else
    {
        *RW_NFI_STRADDR = (kal_uint32)para->data;
    }

    // set dummy command to trigger NFI enter custom mode
    *RW_NFI_CMD = NFI_CMD_DUMMY_PG;

    // set NFI data length
    *RW_NFI_SPIDMA = NFI_SPIDMA_SEC_EN | len_to_write;;

    SNAND_TIME_RECORD(1);

    if (nfi_egid && use_interrupt == KAL_TRUE)
    {
        // trigger interrupt waiting
        reg = *RW_NFI_INTR; // read clear
        *RW_NFI_INTR_EN = NFI_AUTO_PROG_INTR_EN;
    }

    // trigger data transfer
    *RW_NFI_CON = (1 << NFI_SEC_NUM_OFFSET) | NFI_BWR;

    #if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
    if ((ProfileDetail == KAL_TRUE) && (FDM_UT_Item == 10))
    {
        wSBusyTimeW = ust_get_current_time();
        wTotalBusyNumW++;
    }

    if (ResetInNextBusy == KAL_TRUE)
    {
        NANDTest_Reset();
    }
    #endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

    #if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
    if (KAL_TRUE == g_snand_trr_reset_in_next_busy)
    {
        snand_trr_test_wdt_reset();
    }
    #endif  // __SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__

    if (nfi_egid && use_interrupt == KAL_TRUE)
    {
        kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
    }
    else
    {
        for (polling_times = 1;;polling_times++)
        {
            reg = *RW_SNAND_STA_CTL1;

            if ((reg & SNAND_AUTO_PROGRAM) == 0)
            {
                continue;
            }
            else
            {
                break;
            }
        }
    }

    SNAND_TIME_RECORD(2);

    // check get feature status
    reg = *RW_SNAND_GF_CTL1 & SNAND_GF_STATUS_MASK;

    SNAND_dbg_check_GF_status(reg, para->row_addr);

    if ((reg & SNAND_STATUS_PROGRAM_FAIL) != 0)
    {
        status = MTD_STATUS_ERROR;
    }

    // clear trigger bit
    reg = *RW_NFI_CON;
    reg &= ~NFI_BWR;
    *RW_NFI_CON = reg;

    // set 1 then set 0 to clear done flag
    reg = *RW_SNAND_STA_CTL1;
    *RW_SNAND_STA_CTL1 = SNAND_AUTO_PROGRAM;
    *RW_SNAND_STA_CTL1 = 0;

    // reset NFI
    SNAND_Reset(SNAND_RST_CON);

    SNAND_EnableSPIQ(KAL_FALSE);

    #if (defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
    if (6 == FDM_UT_Item || 8 == FDM_UT_Item)   // program confirm only in Normal Powerloss Test & Busy Powerloss Test
    {
        SNAND_dbg_program_confirm(para->data, para->spare, para->row_addr);
    }
    #endif

    SNAND_TIME_RECORD(3);
    SNAND_dbg_time_add_record(SNAND_SW_LAYER_MTD_LOWER, SNAND_DEV_PROGRAM, SNAND_TIME_GET_DURATION_US(0, 3));
    SNAND_dbg_time_add_record(SNAND_SW_LAYER_HW, SNAND_DEV_PROGRAM, SNAND_TIME_GET_DURATION_US(1, 2));

    if (MTD_STATUS_ERROR == status)
    {
        nAND_RESET();   // for program fail case, we will come here to reset device
        return (status | 1);
    }

    return status;
}

// auto read x4
kal_uint32 SNAND_COMMON_RawReadAuto(SNAND_MTD_DRV_PARA * para)
{
    kal_uint32  status    = MTD_STATUS_NO_ERROR;
    kal_uint32  polling_times;
    kal_uint32  reg;
    kal_uint32  len_to_read;
    kal_uint32  event_group;
    kal_bool    internal_buf_used = KAL_TRUE;

    SNAND_TIME_INIT(4, 1);
    SNAND_TIME_RECORD(0);

    // setup read length (started from col_addr, ended at spare_start + spare_bytes
    len_to_read = para->page_size - para->col_addr;

    if (para->data_bytes > len_to_read)
    {
        return MTD_STATUS_PARA_ERROR;
    }

    if (para->spare)
    {
        len_to_read += para->spare_bytes;
    }

    if ((KAL_FALSE == INT_QueryIsCachedRAM(para->data, para->data_bytes)) &&
        (0 == ((kal_uint32)para->data & 0x3)))
    {
        if (para->spare)
        {
            if ((KAL_FALSE == INT_QueryIsCachedRAM(para->spare, para->spare_bytes)) &&
                (para->spare == para->data + para->page_size))
            {
                internal_buf_used = KAL_FALSE;
            }
        }
        else
        {
            internal_buf_used = KAL_FALSE;
        }
    }

    SNAND_EnableSPIQ(KAL_TRUE);

    //------ SNF Part ------

    // set PAGE READ command & address
    *RW_SNAND_RD_CTL1 = ((SNAND_CMD_PAGE_READ << SNAND_PAGE_READ_CMD_OFFSET) | (para->row_addr & SNAND_PAGE_READ_ADDRESS_MASK));

    // set DATA READ dummy cycle and command (use default value, ignored)
    reg = *RW_SNAND_RD_CTL2;
    reg &= ~SNAND_DATA_READ_CMD_MASK;
    reg |= SNAND_CMD_RANDOM_READ_SPIQ & SNAND_DATA_READ_CMD_MASK;
    *RW_SNAND_RD_CTL2 = reg;

    // set DATA READ address
    *RW_SNAND_RD_CTL3 = (para->col_addr & SNAND_DATA_READ_ADDRESS_MASK);

    // set SNF data length
    *RW_SNAND_MISC_CTL2 = (len_to_read | (len_to_read << SNAND_PROGRAM_LOAD_BYTE_LEN_OFFSET));

    /*
     * set get feature polling limit
     *
     * Standby period = polling_cycle * base_time_slot
     * Base_time_slot = SPI_NAND_CLOCK_CYCLE * 128
     *
     * Example:
     * spi-nand clock=100M, 1T=10ns, then base_time_slot = 1.28us. The polling cycle value should be set to meet the Standby_period ~= spec time.
     *
     * Spec:
     * [MTK_INTERNAL_SPI_NAND_1] Page Program Time: Max 0.7 ms
     */
    *RW_SNAND_GF_CTL3 = ((0xE << SNAND_GF_LOOP_LIMIT_OFFSET) & SNAND_GF_LOOP_LIMIT_MASK) | (0x18 & SNAND_GF_POLLING_CYCLE_MASK);

    // set SNF timing
    reg = *RW_SNAND_MISC_CTL;

    // if 4T FIFO is enabled, use default FIFO_RD_LTC

    reg &= ~SNAND_DATA_READ_MODE_MASK;
    reg |= (SNAND_DATA_READ_MODE_X4 << SNAND_DATA_READ_MODE_OFFSET);

    reg &= ~SNAND_PG_LOAD_X4_EN;    // dummy operation

    *RW_SNAND_MISC_CTL = reg;

    //------ NFI Part ------

    // reset NFI
    SNAND_Reset(SNAND_RST_CON);

    // set NFI page format
    *RW_NFI_PAGEFMT = NFI_PAGE_SIZE_2K; // dummy setting

    *RW_NFI_SPIDMA = (NFI_SPIDMA_SEC_EN | (len_to_read & NFI_SPIDMA_SEC_SIZE_MASK));

    // set NFI buffer address
    if (KAL_TRUE == internal_buf_used)
    {
        *RW_NFI_STRADDR = (kal_uint32)(&(g_snand_data_buf[0]));
    }
    else
    {
        *RW_NFI_STRADDR = (kal_uint32)para->data;
    }

    // set NFI configurations
    *RW_NFI_CNFG = ((NFI_OP_MODE_CUSTOM_PROCESS << NFI_OP_MODE_OFFSET) | NFI_DMA_MODE | NFI_DMA_BURST_EN | (NFI_READ_MODE_FLASH_TO_RAM << NFI_READ_MODE_OFFSET));

    // set dummy command to trigger NFI enter custom mode
    *RW_NFI_CMD = NFI_CMD_DUMMY_RD;

    //time[1] = INT_GetCurrentTime();

    SNAND_TIME_RECORD(1);

    if (nfi_egid && use_interrupt == KAL_TRUE)
    {
        // trigger interrupt waiting
        reg = *RW_NFI_INTR; // read clear
        *RW_NFI_INTR_EN = NFI_AHB_DONE_EN; // triger AHB_DONE for auto-read
    }

    // trigger data transfer
    *RW_NFI_CON = ((1 << NFI_SEC_NUM_OFFSET) | NFI_BRD);

    #if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
    if ((ProfileDetail == KAL_TRUE) && (FDM_UT_Item == 10))
    {
        wSBusyTimeW = ust_get_current_time();
        wTotalBusyNumW++;
    }

    if (ResetInNextBusy == KAL_TRUE)
    {
        //NANDTest_Reset();
    }
    #endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

    if (nfi_egid && use_interrupt == KAL_TRUE)
    {
        kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
    }
    else
    {
        // 1. wait for SPI-NAND => SNF done
        for (polling_times = 1; ; polling_times++)
        {
            reg = *RW_SNAND_STA_CTL1;

            if (0 != (reg & SNAND_AUTO_READ))
            {
                break;
            }
        }

        // 2. polling NFI_BYTELEN (NFI DMA Byte Len Register)
        //    PS. wait NFI FIFO until all data is transferred to DMA FIFO (then DMA FIFO will transfer data to AHB Master)

        for (polling_times = 1;;polling_times++)
        {
            reg = *RW_NFI_BYTELEN;

            reg = (reg & NFI_BUS_SEC_CNTR_MASK) >> NFI_BUS_SEC_CNTR_OFFSET;

            if (1 == reg)
            {
                break;
            }
        }

        // 3. wait for NFI_MASTERSTA ready
        //    PS. wait AHB Master until all data is transferred to bus

        SNAND_Reset(SNAND_RST_WAIT_READY);
    }

    SNAND_TIME_RECORD(2);

    reg = *RW_SNAND_GF_CTL1 & SNAND_GF_STATUS_MASK;

    SNAND_dbg_check_GF_status(reg, para->row_addr);

    if (reg & SNAND_STATUS_OIP)
    {
        status = MTD_STATUS_ERROR;  // timeout! need reset device!

        SNAND_dbg_print("[MTD INFO] Read Timeout! row:%d\n\r", para->row_addr);
    }
    else if ((reg & SNAND_STATUS_ECC_STATUS_MASK) == SNAND_STATUS_TOO_MANY_ERROR_BITS)
    {
        status = MTD_STATUS_ERROR;
    }

    // clear trigger bit
    reg = *RW_NFI_CON;
    reg &= ~NFI_BRD;
    *RW_NFI_CON = reg;

    // set 1 then set 0 to clear done flag
    reg = *RW_SNAND_STA_CTL1;
    *RW_SNAND_STA_CTL1 = SNAND_AUTO_READ;
    *RW_SNAND_STA_CTL1 = 0;

    if (KAL_TRUE == internal_buf_used)
    {
        kal_mem_cpy((void *)(para->data), (void *)(&(g_snand_data_buf[para->col_addr])), para->data_bytes);

        // copy spare data from MTD buffer (non-cacheable) to user buffer
        if (para->spare)
        {
            kal_mem_cpy((void *)(para->spare), (void *)(&(g_snand_data_buf[para->page_size])), para->spare_bytes);
        }
    }

    SNAND_EnableSPIQ(KAL_FALSE);

    SNAND_TIME_RECORD(3);
    SNAND_dbg_time_add_record(SNAND_SW_LAYER_MTD_LOWER, SNAND_DEV_READ, SNAND_TIME_GET_DURATION_US(0, 3));
    SNAND_dbg_time_add_record(SNAND_SW_LAYER_HW, SNAND_DEV_READ, SNAND_TIME_GET_DURATION_US(1, 2));

    if (status == MTD_STATUS_ERROR)
    {
        nAND_RESET();
        return (status | 1);
    }
    else if (status == MTD_STATUS_CORRECTED)
    {
        return (status | 1);
    }

    return status;
}

// custom read x4

#if defined(__SNAND_AP_MONITOR__)
void snand_apm_init()
{
    kal_uint32 i, j;
    static kal_uint32 apm_init = 0;

    if (1 == apm_init)
    {
        return;
    }

    // for specific block monitor
    for (i = 0; i < SNAND_APM_BLOCK_MONITOR_MAX_CNT; i++)
    {
        for (j = 0; j < 64; j++)
        {
            g_snand_apm_block_monitor_data[i][j] = 0;
        }
    }

    apm_init = 1;
}

void snand_apm_add_record(SNAND_AP_OPERATION op, kal_uint16 block, kal_uint16 page, kal_uint8 hit)
{
    kal_uint32 time;

    time = INT_GetCurrentTime();

    if (g_snand_apm_cnt >= SNAND_APM_DATA_MAX_CNT)
    {
        g_snand_apm_wrapped++;
        g_snand_apm_cnt = 0;
    }

    g_snand_apm_data[g_snand_apm_cnt].op = op;
    g_snand_apm_data[g_snand_apm_cnt].hit = hit;
    g_snand_apm_data[g_snand_apm_cnt].block = block;
    g_snand_apm_data[g_snand_apm_cnt].page = page;
    g_snand_apm_data[g_snand_apm_cnt].time = time;

    g_snand_apm_cnt++;

    // for specific block monitor
    if (0 == hit)
    {
        g_snand_apm_block_monitor_data[block][page]++;
    }
}
#endif

kal_uint32 SNAND_COMMON_RawReadCustom(SNAND_MTD_DRV_PARA * para)
{
    /*
     * [Use Custom Read instead of Auto Read]
     *
     * Some SPI-NAND device has device ECC defect, which may raise OIP forever and let Auto Mode Get Feature hang.
     * In Custom Mode, Get Feature is operated by SW driver, therefore timeout mechanism could be added to avoid hang.
     */

    kal_uint32  status    = MTD_STATUS_NO_ERROR;
    kal_uint32  reg;
    kal_uint32  len_to_read;
    kal_uint32  event_group;
    kal_bool    internal_buf_used = KAL_TRUE, bTimeout;
    #if defined(__SNAND_DYNAMIC_SWITCH_CACHEABILITY__)
    kal_bool    dynamic_switched = KAL_FALSE;
    #endif
    kal_uint32  start_tick, end_tick;

    SNAND_TIME_INIT(4, 1);
    SNAND_TIME_RECORD(0);

    // setup read length (started from col_addr, ended at spare_start + spare_bytes

    len_to_read = para->page_size - para->col_addr;

    if (para->data_bytes > len_to_read)
    {
        return MTD_STATUS_PARA_ERROR;
    }

    #if defined(__SNAND_AP_MONITOR__)
    snand_apm_add_record(SNAND_AP_READ, para->row_addr / 64, para->row_addr % 64, 0);
    #endif

    #if defined(__SNAND_SW_CRC__)
    if ((para->row_addr / SNAND_PAGE_PER_BLOCK) >= (NAND_FLASH_BASE_ADDRESS / (SNAND_PAGE_SIZE * SNAND_PAGE_PER_BLOCK)))    // file system always enable FDM Data CRC checking
    {
        len_to_read = SNAND_PAGE_SIZE + SNAND_SPARE_SIZE;   // enforce read spare for CRC checking

        internal_buf_used = KAL_TRUE;
    }
    else    // non-file-system region
    #endif  // __SNAND_SW_CRC__
    {
        if (para->spare)
        {
            len_to_read += para->spare_bytes;
        }

        if ((KAL_FALSE == INT_QueryIsCachedRAM(para->data, para->data_bytes)) &&
            (0 == ((kal_uint32)para->data & 0x3)))
        {
            if (para->spare)
            {
                if ((KAL_FALSE == INT_QueryIsCachedRAM(para->spare, para->spare_bytes)) &&
                    (para->spare == para->data + para->page_size))
                {
                    internal_buf_used = KAL_FALSE;
                }
            }
            else    // no spare
            {
                internal_buf_used = KAL_FALSE;
            }
        }
        else    // cacheable
        {
            #if defined(__SNAND_DYNAMIC_SWITCH_CACHEABILITY__) && !defined(__UBL__)
            if ((NULL == para->spare) ||
                (para->spare && (para->spare == para->data + para->page_size)))
            {
                if (IS_CACHE_LINE_SIZE_ALIGNED((kal_uint32)(para->data)) &&
       	            IS_CACHE_LINE_SIZE_ALIGNED(len_to_read) &&
       	            is_predef_dyna_c_region((kal_uint32)(para->data), len_to_read))
       	        {
                    dynamic_switch_cacheable_region(para->data, len_to_read, PAGE_NO_CACHE);

                    dynamic_switched = KAL_TRUE;

                    internal_buf_used = KAL_FALSE;
                }
            }
            #endif
        }
    }

    // Read page to cache

    #if defined(__UBL__) && defined(__SNAND_STT_EN__)
    stt_snand_set_pll(26);
    #endif

    SNAND_TIME_RECORD(1);

    *RW_SNAND_GPRAM_DATA = SNAND_GPRAM_Write_C1A3(SNAND_CMD_PAGE_READ, para->row_addr); // PAGE_READ command + 3-byte address
    *RW_SNAND_MAC_OUTL = 1 + 3;
    *RW_SNAND_MAC_INL = 0;
    SNAND_MacEnable(SNAND_SPI);
    SNAND_MacTrigger();
    SNAND_MacLeave();

    // Get features (status polling)

    *RW_SNAND_GPRAM_DATA = (SNAND_CMD_GET_FEATURES | (SNAND_CMD_FEATURES_STATUS << 8));
    *RW_SNAND_MAC_OUTL = 2;
    *RW_SNAND_MAC_INL = 1;

    start_tick = SNAND_Util_GetTimeUS();

    for (bTimeout = KAL_FALSE;;)    // loop again to read status one more time if timeout
    {
        SNAND_MacEnable(SNAND_SPI);
        SNAND_MacTrigger();
        SNAND_MacLeave();

        reg = SNAND_ReadReg8(((SNAND_P_U8)RW_SNAND_GPRAM_DATA + 2));

        if ((reg & SNAND_STATUS_OIP) == 0)
        {
            break;
        }

        // if timeout, read status again above because timeout may due to context-switch
        if (KAL_TRUE == bTimeout)
        {
            SNAND_dbg_print("[MTD INFO] Read Timeout! row:%d(blk:%d)\n\r", para->row_addr, para->row_addr / 64);

            break;
        }

        end_tick = SNAND_Util_GetTimeUS();

        if (SNAND_Util_GetTimeDurationUS(start_tick, end_tick) > SPI_NAND_MAX_READ_BUSY_US)
        {
            bTimeout = KAL_TRUE;
        }
    }

    SNAND_TIME_RECORD(2);

    SNAND_dbg_check_GF_status(reg, para->row_addr);

    if (reg & SNAND_STATUS_OIP)
    {
        status = MTD_STATUS_ERROR;  // timeout! need reset device!
    }
    else if (reg & SNAND_STATUS_ECC_STATUS_MASK)
    {
        reg = reg & SNAND_STATUS_ECC_STATUS_MASK;

        if (SNAND_STATUS_TOO_MANY_ERROR_BITS == reg)
        {
            status = MTD_STATUS_ERROR;
        }
        else
        {
            status = MTD_STATUS_CORRECTED;
        }
    }

    // Read from cache

    //------ SNF Part ------

    SNAND_EnableSPIQ(KAL_TRUE);

    #if defined(__UBL__) && defined(__SNAND_STT_EN__)
    stt_snand_set_pll(g_snand_clock);
    #endif

    // set PAGE READ command & address
    *RW_SNAND_RD_CTL1 = ((SNAND_CMD_PAGE_READ << SNAND_PAGE_READ_CMD_OFFSET) | (para->row_addr & SNAND_PAGE_READ_ADDRESS_MASK));

    // set DATA READ dummy cycle and command (use default value, ignored)
    reg = *RW_SNAND_RD_CTL2;
    reg &= ~SNAND_DATA_READ_CMD_MASK;
    reg |= SNAND_CMD_RANDOM_READ_SPIQ & SNAND_DATA_READ_CMD_MASK;
    *RW_SNAND_RD_CTL2 = reg;

    // set DATA READ address
    *RW_SNAND_RD_CTL3 = (para->col_addr & SNAND_DATA_READ_ADDRESS_MASK);

    // set SNF data length
    *RW_SNAND_MISC_CTL2 = (len_to_read | (len_to_read << SNAND_PROGRAM_LOAD_BYTE_LEN_OFFSET));

    //*RW_SNAND_GF_CTL3 = ((0xF << SNAND_GF_LOOP_LIMIT_OFFSET) & SNAND_GF_LOOP_LIMIT_MASK) | (0x18 & SNAND_GF_POLLING_CYCLE_MASK);

    // set SNF timing
    reg = *RW_SNAND_MISC_CTL;

    // if 4T FIFO is enabled, use default FIFO_RD_LTC

    reg |= SNAND_DATARD_CUSTOM_EN;      // enable custom mode

    reg &= ~SNAND_DATA_READ_MODE_MASK;
    reg |= (SNAND_DATA_READ_MODE_X4 << SNAND_DATA_READ_MODE_OFFSET);

    reg &= ~SNAND_PG_LOAD_X4_EN;        // dummy operation

    *RW_SNAND_MISC_CTL = reg;

    //------ NFI Part ------

    // reset NFI
    SNAND_Reset(SNAND_RST_CON);

    // set NFI page format
    *RW_NFI_PAGEFMT = NFI_PAGE_SIZE_2K; // dummy setting

    *RW_NFI_SPIDMA = (NFI_SPIDMA_SEC_EN | (len_to_read & NFI_SPIDMA_SEC_SIZE_MASK));

    // set NFI buffer address
    if (KAL_TRUE == internal_buf_used)
    {
        *RW_NFI_STRADDR = (kal_uint32)(&(g_snand_data_buf[0]));
    }
    else
    {
        *RW_NFI_STRADDR = (kal_uint32)para->data;
    }

    // set NFI configurations
    *RW_NFI_CNFG = ((NFI_OP_MODE_CUSTOM_PROCESS << NFI_OP_MODE_OFFSET) | NFI_DMA_MODE | NFI_DMA_BURST_EN | (NFI_READ_MODE_FLASH_TO_RAM << NFI_READ_MODE_OFFSET));

    // set dummy command to trigger NFI enter custom mode
    *RW_NFI_CMD = NFI_CMD_DUMMY_RD;

    reg = *RW_NFI_INTR; // read clear

    if (nfi_egid && (KAL_TRUE == use_interrupt))  // Note nfi_egid = NULL in USB boot mode, bootloader and FOTA
    {
        // do nothing here, "interrupt read clear" have been done above
    }
    else
    {
        /*
         * (nfi_egid == NULL) || (use_interrupt == KAL_FALSE)
         *
         * (USB boot mode) || (bootloader) || (FOTA) || (Normal boot mode w/ polling, e.g., demand paging, system init and exception handler)
         */
        #if !defined(__UBL__)
        IRQMask(IRQ_NFI_CODE);  // In polling mode, mask NFI interrupt to prevent NFI interrupt is serviced and cleared by LISR. we will poll the interrupt below.
        #endif
    }

    *RW_NFI_INTR_EN = NFI_AHB_DONE_EN; // triger AHB_DONE for custom-read

    // trigger data transfer
    *RW_NFI_CON = ((1 << NFI_SEC_NUM_OFFSET) | NFI_BRD);

    #if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
    if ((ProfileDetail == KAL_TRUE) && (FDM_UT_Item == 10))
    {
        wSBusyTimeW = ust_get_current_time();
        wTotalBusyNumW++;
    }

    if (ResetInNextBusy == KAL_TRUE)
    {
        //NANDTest_Reset();
    }
    #endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

    if (nfi_egid && use_interrupt == KAL_TRUE)
    {
        kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
    }
    else
    {
        while(1)
        {
            reg = *RW_NFI_INTR;

            if (reg & NFI_AHB_DONE)
            {
                break;
            }
        }

        *RW_NFI_INTR_EN = 0;

        #if !defined(__UBL__)
        IRQClearInt(IRQ_NFI_CODE);
        IRQUnmask(IRQ_NFI_CODE);
        #endif
    }

    // clear trigger bit
    reg = *RW_NFI_CON;
    reg &= ~NFI_BRD;
    *RW_NFI_CON = reg;

    // set 1 then set 0 to clear done flag
    *RW_SNAND_STA_CTL1 = SNAND_CUSTOM_READ;
    *RW_SNAND_STA_CTL1 = 0;

    if (KAL_TRUE == internal_buf_used)
    {
        kal_mem_cpy((void *)(para->data), (void *)(&(g_snand_data_buf[para->col_addr])), para->data_bytes);

        // copy spare data from MTD buffer (non-cacheable) to user buffer
        if (para->spare)
        {
            kal_mem_cpy((void *)(para->spare), (void *)(&(g_snand_data_buf[para->page_size])), para->spare_bytes);
        }
    }

    SNAND_EnableSPIQ(KAL_FALSE);

    #if defined(__SNAND_SW_CRC__)
    while (1)
    {
        if ((para->row_addr / SNAND_PAGE_PER_BLOCK) >= (NAND_FLASH_BASE_ADDRESS / (SNAND_PAGE_SIZE * SNAND_PAGE_PER_BLOCK)))    // only check file system
        {
            kal_uint16 crc_code_fdm_data_g;
            kal_uint16 crc_code_fdm_data_r;

            // do not check CRC error in bad block. Check g_snand_data_buf because file system always use internal buffer
            if (0xFF != g_snand_data_buf[SNAND_PAGE_SIZE])
            {
                break;
            }

            crc_code_fdm_data_r = snand_crc_get(((kal_uint8 *)&(g_snand_data_buf[SNAND_PAGE_SIZE])));

            if (0xFFFF != crc_code_fdm_data_r)  // bypass empty page
            {
                crc_code_fdm_data_g = snand_crc_gen_for_spare(((kal_uint8 *)&(g_snand_data_buf[SNAND_PAGE_SIZE])));

                if (crc_code_fdm_data_r != crc_code_fdm_data_g)
                {
                    status = MTD_STATUS_ERROR;  // report read error to FDM
                }
            }
        }

        break;
    }
    #endif  // __SNAND_SW_CRC__

    SNAND_TIME_RECORD(3);
    SNAND_dbg_time_add_record(SNAND_SW_LAYER_MTD_LOWER, SNAND_DEV_READ, SNAND_TIME_GET_DURATION_US(0, 3));
    SNAND_dbg_time_add_record(SNAND_SW_LAYER_HW, SNAND_DEV_READ, SNAND_TIME_GET_DURATION_US(1, 2));

    #if defined(__SNAND_DYNAMIC_SWITCH_CACHEABILITY__) && !defined(__UBL__)
    if (KAL_TRUE == dynamic_switched)
    {
        dynamic_switch_cacheable_region(para->data, len_to_read, PAGE_CACHEABLE);
    }
    #endif

    if (MTD_STATUS_ERROR == status)
    {
        nAND_RESET();   // for timeout case, we will come here to reset device
        return (status | 1);
    }
    else if (MTD_STATUS_CORRECTED == status)
    {
        return (status | 1);
    }

    return status;
}

kal_uint16 SNAND_COMMON_GetBadBlockMark(void * spare)
{
    switch (Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[7])
    {
        case SNAND_SPARE_FORMAT_MTK_1:
            return ((FDMDataU_2K_MTK_1 *)spare)->BI;
        case SNAND_SPARE_FORMAT_MTK_2:
            return ((FDMDataU_2K_MTK_2 *)spare)->BI;
        default:
            dbg_ASSERT(0);
            return 0;
    }
}

void SNAND_COMMON_SetBadBlockMark(kal_uint16 mark, void * spare)
{
    switch (Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[7])
    {
        case SNAND_SPARE_FORMAT_MTK_1:
            ((FDMDataU_2K_MTK_1 *)spare)->BI = mark;
            break;
        case SNAND_SPARE_FORMAT_MTK_2:
            ((FDMDataU_2K_MTK_2 *)spare)->BI = mark;
            break;
        default:
            dbg_ASSERT(0);
            break;
    }
}

kal_uint32 SNAND_COMMON_RawReadMac(SNAND_MTD_DRV_PARA * para)
{
    kal_uint32      status    = MTD_STATUS_NO_ERROR;
    kal_uint32      col_addr;
    kal_uint32      cmd;
    kal_uint32      len_left;
    kal_uint32      len_read;
    SNAND_P_U8      pGPRAM;
    SNAND_P_U8      pBuff;
    kal_uint32      start_tick;
    kal_bool        bTimeout;
    SNAND_Data_Parts parts;

    // 1. Read page to cache

    cmd = SNAND_GPRAM_Write_C1A3(SNAND_CMD_PAGE_READ, para->row_addr); // PAGE_READ command + 3-byte address

    SNAND_WriteReg32(RW_SNAND_GPRAM_DATA, cmd);
    SNAND_WriteReg32(RW_SNAND_MAC_OUTL, 1 + 3);
    SNAND_WriteReg32(RW_SNAND_MAC_INL , 0);
    SNAND_MacEnable(SNAND_SPI);

    SNAND_MacTrigger();
    SNAND_MacLeave();

    // 2. Get features (status polling)

    cmd = SNAND_CMD_GET_FEATURES | (SNAND_CMD_FEATURES_STATUS << 8);

    SNAND_WriteReg32(RW_SNAND_GPRAM_DATA, cmd);
    SNAND_WriteReg32(RW_SNAND_MAC_OUTL, 2);
    SNAND_WriteReg32(RW_SNAND_MAC_INL , 1);

    start_tick = SNAND_Util_GetTimeUS();

    for (bTimeout = KAL_FALSE;;)    // loop again to read status one more time if timeout
    {
        SNAND_MacEnable(SNAND_SPI);

        SNAND_MacTrigger();
        SNAND_MacLeave();

        cmd = SNAND_ReadReg8(((SNAND_P_U8)RW_SNAND_GPRAM_DATA + 2));

        if ((cmd & SNAND_STATUS_OIP) == 0)
        {
            break;
        }

        if (KAL_TRUE == bTimeout)   // timeout (NOTE: read status again when timeout because timeout may due to context-switch)
        {
            status = MTD_STATUS_ERROR;

            SNAND_dbg_print( "[MTD Info] RawReadMac: Read Timeout! row: %d\n\r", para->row_addr);

            break;
        }

        bTimeout = SNAND_Util_IsTimeout(start_tick, SPI_NAND_MAX_READ_BUSY_US);
    }

    if (cmd & SNAND_STATUS_ECC_STATUS_MASK)
    {
        cmd = cmd & SNAND_STATUS_ECC_STATUS_MASK;

        if (SNAND_STATUS_TOO_MANY_ERROR_BITS == cmd)
        {
            status = MTD_STATUS_ERROR;
        }
        else
        {
            status = MTD_STATUS_CORRECTED;
        }
    }

    // 3. Read from cache

    for (parts = SNAND_PART_BEGIN; parts != SNAND_PART_END; parts++)
    {
        if (SNAND_DATA_PART == parts)   // data part
        {
            col_addr = para->col_addr;
            len_left = para->data_bytes;
            pBuff = (SNAND_P_U8)para->data;
        }

        else                            // spare part
        {
            if (NULL == para->spare)
            {
                break;  // no spare buffer assigned, leave
            }

            // spare buffer is assigned, continue to write spare area
            col_addr = para->page_size;
            len_left = para->spare_bytes;
            pBuff = (SNAND_P_U8)para->spare;
        }

        while (len_left)
        {
            cmd = SNAND_GPRAM_Write_C1A3(SNAND_CMD_RANDOM_READ, (col_addr << 8)); // PAGE_READ command + 2-byte column address + 1-byte dummy byte

            SNAND_WriteReg32(RW_SNAND_GPRAM_DATA, cmd);
            SNAND_WriteReg32(RW_SNAND_MAC_OUTL, 1 + 3);             // 1+3: C1A3

            pGPRAM = ((SNAND_P_U8)RW_SNAND_GPRAM_DATA) + 1 + 3;     // 1+3: C1A3

            // get read length in one round
            if (len_left >= (SNAND_MAC_MAX_DATA_SIZE))
            {
                len_read = (SNAND_MAC_MAX_DATA_SIZE);
                len_left -= (SNAND_MAC_MAX_DATA_SIZE);
            }
            else
            {
                len_read = len_left;
                len_left = 0;
            }

            SNAND_WriteReg32(RW_SNAND_MAC_INL, len_read);

            // trigger SFI to read data from device to GPRAM
            SNAND_MacEnable(SNAND_SPI);
            SNAND_MacTrigger();
            SNAND_MacLeave();

            // copy data from GPRAM to external buffer
            for (cmd = 0; cmd < len_read; cmd++, pGPRAM++, pBuff++)
            {
                *pBuff = SNAND_ReadReg8(pGPRAM);
            }

            col_addr += len_read;
        }

        if (SNAND_DATA_PART != parts)
        {
           pBuff = (SNAND_P_U8)para->spare;
        }
    }

    return status;
}

kal_uint32 SNAND_COMMON_RawWriteMac(SNAND_MTD_DRV_PARA * para)
{
    kal_uint32      status    = MTD_STATUS_NO_ERROR;
    kal_uint32      cmd;
    kal_uint32      len_left;
    kal_uint32      len_written;
    kal_uint32      col_addr;
    SNAND_P_U8      pBuff;
    SNAND_Data_Parts parts;

    // 1. Write Enable

    SNAND_Dev_Command(SNAND_CMD_WRITE_ENABLE, 1);

    // 2. Program Load

    for (parts = SNAND_PART_BEGIN; parts != SNAND_PART_END; parts++)
    {
        if (SNAND_DATA_PART == parts)   // data part
        {
            col_addr = para->col_addr;
            len_left = para->data_bytes;
            pBuff = (SNAND_P_U8)para->data;
        }

        else                            // spare part
        {
            if (NULL == para->spare)
            {
                break;  // no spare buffer assigned, leave
            }

            // spare buffer is assigned, continue to write spare area
            col_addr = para->page_size;
            len_left = para->spare_bytes;
            pBuff = (SNAND_P_U8)para->spare;
        }

        while (len_left)    // load data to device
        {
            cmd = SNAND_CMD_PROGRAM_RANDOM_LOAD | (SNAND_ReverseByteOrder(col_addr << 8) & 0x00FFFF00) | (*pBuff << 24);

            SNAND_WriteReg32(RW_SNAND_GPRAM_DATA, cmd);

            // get read length in one round
            if (len_left >= (SNAND_MAC_MAX_DATA_SIZE))
            {
                len_written = (SNAND_MAC_MAX_DATA_SIZE);
                len_left -= (SNAND_MAC_MAX_DATA_SIZE);
            }
            else
            {
                len_written = len_left;
                len_left = 0;
            }

            SNAND_WriteReg32(RW_SNAND_MAC_INL, 0);
            SNAND_WriteReg32(RW_SNAND_MAC_OUTL, 4 + len_written - 1);

            SNAND_GPRAM_Write(4, (void *)(pBuff + 1), (kal_int32)(len_written - 1));

            // trigger SFI to read data from device to GPRAM
            SNAND_MacEnable(SNAND_SPI);
            SNAND_MacTrigger();
            SNAND_MacLeave();

            pBuff += len_written;
            col_addr += len_written;
        }
    }

    // 3. Program Execute
    cmd = SNAND_GPRAM_Write_C1A3(SNAND_CMD_PROGRAM_EXECUTE, para->row_addr);

    SNAND_Dev_Command(cmd, 4);

    // 4. Status Polling
    cmd = SNAND_CMD_GET_FEATURES | (SNAND_CMD_FEATURES_STATUS << 8);

    SNAND_WriteReg32(RW_SNAND_GPRAM_DATA, cmd);
    SNAND_WriteReg32(RW_SNAND_MAC_OUTL, 2);
    SNAND_WriteReg32(RW_SNAND_MAC_INL , 1);

    while (1)
    {
        SNAND_MacEnable(SNAND_SPI);
        SNAND_MacTrigger();
        SNAND_MacLeave();

        cmd = SNAND_ReadReg8(((SNAND_P_U8)RW_SNAND_GPRAM_DATA + 2));

        if ((cmd & SNAND_STATUS_OIP) == 0)
        {
            if ((cmd & SNAND_STATUS_PROGRAM_FAIL) != 0)
            {
                status = MTD_STATUS_ERROR;
            }

            break;
        }
    }

    return status;
}

void SNAND_COMMON_ReadID(kal_uint8 id[])
{
    kal_uint8 cmd = SNAND_CMD_READ_ID;

    SNAND_Dev_Command_Ext(SNAND_SPI, &cmd, id, 1, SNAND_FLASH_ID_LENGTH + 1);
}

kal_uint32 SNAND_COMMON_UnlockFlash()
{
    kal_uint32 status    = MTD_STATUS_NO_ERROR;
    kal_uint32 cmd;
    kal_uint8  lock;
    kal_uint8  lock_new;

    // read original block lock settings
    cmd = SNAND_CMD_GET_FEATURES | (SNAND_CMD_FEATURES_BLOCK_LOCK << 8);
    SNAND_WriteReg32(RW_SNAND_GPRAM_DATA, cmd);
    SNAND_WriteReg32(RW_SNAND_MAC_OUTL, 2);
    SNAND_WriteReg32(RW_SNAND_MAC_INL , 1);
    SNAND_MacEnable(SNAND_SPI);

    SNAND_MacTrigger();
    SNAND_MacLeave();

    lock = SNAND_ReadReg8(((SNAND_P_U8)RW_SNAND_GPRAM_DATA + 2));

    lock_new = lock & ~SNAND_BLOCK_LOCK_BITS;

    if (lock != lock_new)
    {
        // write enable
        SNAND_Dev_Command(SNAND_CMD_WRITE_ENABLE, 1);

        // set features
        cmd = SNAND_CMD_SET_FEATURES | (SNAND_CMD_FEATURES_BLOCK_LOCK << 8) | (lock_new << 16);
        SNAND_Dev_Command(cmd, 3);
    }

    // cosnfrm if unlock is successfull
    cmd = SNAND_CMD_GET_FEATURES | (SNAND_CMD_FEATURES_BLOCK_LOCK << 8);
    SNAND_WriteReg32(RW_SNAND_GPRAM_DATA, cmd);
    SNAND_WriteReg32(RW_SNAND_MAC_OUTL, 2);
    SNAND_WriteReg32(RW_SNAND_MAC_INL , 1);
    SNAND_MacEnable(SNAND_SPI);

    SNAND_MacTrigger();
    SNAND_MacLeave();

    lock = SNAND_ReadReg8(((SNAND_P_U8)RW_SNAND_GPRAM_DATA + 2));

    if (lock & SNAND_BLOCK_LOCK_BITS)
    {
        status = MTD_STATUS_ERROR;
    }

    return status;
}

kal_uint32 SNAND_COMMON_BlockEraseAuto(const kal_uint32 row_addr)
{
    kal_uint32      status = MTD_STATUS_NO_ERROR;
    kal_uint32      reg;
    kal_uint32      polling_times, event_group;

    SNAND_TIME_INIT(4, 1);
    SNAND_TIME_RECORD(0);

    #if defined(__SNAND_AP_MONITOR__)
    snand_apm_add_record(SNAND_AP_ERASE, row_addr / 64, 0, 0);
    #endif

    // erase address
    *RW_SNAND_ER_CTL2 = row_addr;

    // set get feature behavior
    *RW_SNAND_GF_CTL3 = ((SNAND_LOOP_LIMIT_NO_LIMIT << SNAND_GF_LOOP_LIMIT_OFFSET) & SNAND_GF_LOOP_LIMIT_MASK) | (1 & SNAND_GF_POLLING_CYCLE_MASK);

    // set erase command
    *RW_SNAND_ER_CTL = (SNAND_CMD_BLOCK_ERASE << SNAND_ER_CMD_OFFSET);

    if (nfi_egid && use_interrupt == KAL_TRUE)
    {
        // trigger interrupt waiting

        reg = *RW_NFI_INTR; // read clear
        *RW_NFI_INTR_EN = NFI_AUTO_BLKER_INTR_EN;
    }

    SNAND_TIME_RECORD(1);

    // trigger auto erase
    reg = *RW_SNAND_ER_CTL;
    reg |= SNAND_AUTO_ERASE_TRIGGER;
    *RW_SNAND_ER_CTL = reg;

    #if (defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
    if (ResetInNextBusy == KAL_TRUE)
    {
        NANDTest_Reset();
    }
    #endif

    #if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
    if (KAL_TRUE == g_snand_trr_reset_in_next_busy)
    {
        snand_trr_test_wdt_reset();
    }
    #endif  // __SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__

    // wait for auto erase finish

    if (nfi_egid && use_interrupt == KAL_TRUE)
    {
        kal_retrieve_eg_events(nfi_egid, NFI_EVENT, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
    }
    else
    {
        for (polling_times = 1;;polling_times++)
        {
            reg = *RW_SNAND_STA_CTL1;

            if (0 != (reg & SNAND_AUTO_BLKER))
            {
                break;
            }
        }
    }

    SNAND_TIME_RECORD(2);

    // check get feature status
    reg = *RW_SNAND_GF_CTL1 & SNAND_GF_STATUS_MASK;

    SNAND_dbg_check_GF_status(reg, row_addr);

    if (0 != (reg & SNAND_STATUS_ERASE_FAIL))
    {
        status = MTD_STATUS_ERROR;
    }

    // set 1 then set 0 to clear done flag
    reg = *RW_SNAND_STA_CTL1;
    *RW_SNAND_STA_CTL1 = SNAND_AUTO_BLKER;
    *RW_SNAND_STA_CTL1 = 0;

    // clear trigger bit
    reg = *RW_SNAND_ER_CTL;
    reg &= ~SNAND_AUTO_ERASE_TRIGGER;
    *RW_SNAND_ER_CTL = reg;

    // reset NFI
    SNAND_Reset(SNAND_RST_CON);

    SNAND_TIME_RECORD(3);
    SNAND_dbg_time_add_record(SNAND_SW_LAYER_MTD_LOWER, SNAND_DEV_ERASE, SNAND_TIME_GET_DURATION_US(0, 3));
    SNAND_dbg_time_add_record(SNAND_SW_LAYER_HW, SNAND_DEV_ERASE, SNAND_TIME_GET_DURATION_US(1, 2));

    if (MTD_STATUS_ERROR == status)
    {
        nAND_RESET();   // for program fail case, we will come here to reset device
        return (status | 1);
    }

    return status;
}

kal_uint32 SNAND_COMMON_BlockEraseMac(const kal_uint32 row_addr)
{
    kal_uint32  status = MTD_STATUS_NO_ERROR;
    kal_uint32  cmd;

    // 1. Write Enable

    SNAND_Dev_Command(SNAND_CMD_WRITE_ENABLE, 1);

    // 2. Block Erase
    cmd = SNAND_GPRAM_Write_C1A3(SNAND_CMD_BLOCK_ERASE, row_addr); // BLOCK_ERASE command + 3-byte address

    SNAND_Dev_Command(cmd, 4);

    // 3. Status Polling
    cmd = SNAND_CMD_GET_FEATURES | (SNAND_CMD_FEATURES_STATUS << 8);

    SNAND_WriteReg32(RW_SNAND_GPRAM_DATA, cmd);
    SNAND_WriteReg32(RW_SNAND_MAC_OUTL, 2);
    SNAND_WriteReg32(RW_SNAND_MAC_INL , 1);

    // TODO: Add timeout mechanism

    while (1)
    {
        SNAND_MacEnable(SNAND_SPI);
        SNAND_MacTrigger();
        SNAND_MacLeave();

        cmd = SNAND_ReadReg8(((SNAND_P_U8)RW_SNAND_GPRAM_DATA + 2));

        if ((cmd & SNAND_STATUS_OIP) == 0)
        {
            if ((cmd & SNAND_STATUS_ERASE_FAIL) != 0)
            {
                status = MTD_STATUS_ERROR;
            }

            break;
        }
    }

    return status;
}

void SNAND_COMMON_ECCCon(kal_bool ecc_enable)
{
    kal_uint32 cmd;
    kal_uint8  otp;
    kal_uint8  otp_new;

    // read original otp settings

    cmd = SNAND_CMD_GET_FEATURES | (SNAND_CMD_FEATURES_OTP << 8);
    SNAND_WriteReg32(RW_SNAND_GPRAM_DATA, cmd);
    SNAND_WriteReg32(RW_SNAND_MAC_OUTL, 2);
    SNAND_WriteReg32(RW_SNAND_MAC_INL , 1);
    SNAND_MacEnable(SNAND_SPI);
    SNAND_MacTrigger();
    SNAND_MacLeave();
    otp = SNAND_ReadReg8(((SNAND_P_U8)RW_SNAND_GPRAM_DATA + 2));

    if (KAL_TRUE == ecc_enable)
    {
        otp_new = otp | SNAND_OTP_ECC_ENABLE;
    }
    else
    {
        otp_new = otp & ~SNAND_OTP_ECC_ENABLE;
    }

    if (otp != otp_new)
    {
        // write enable
        SNAND_Dev_Command(SNAND_CMD_WRITE_ENABLE, 1);

        // set features
        cmd = SNAND_CMD_SET_FEATURES | (SNAND_CMD_FEATURES_OTP << 8) | (otp_new << 16);
        SNAND_Dev_Command(cmd, 3);
    }
}

kal_uint32 SNAND_Util_GetTimeUS(void)
{
    return ust_get_current_time();
}

kal_uint32 SNAND_Util_GetTimeDurationUS(kal_uint32 time_begin, kal_uint32 time_end)
{
    return (ust_get_duration(time_begin, time_end) * 12 / 13);
}

kal_bool SNAND_Util_IsTimeout(kal_uint32 start_us, kal_uint32 timeout_us)
{
    register kal_uint32 cur_us;

    // get current tick
    cur_us = SNAND_Util_GetTimeUS();

    // check if timeout
    if (ust_get_duration(start_us, cur_us) >= timeout_us)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

void SNAND_Reset(kal_uint32 rst_flag)
{
    kal_uint8       cmd = SNAND_CMD_SW_RESET;
    kal_bool        bTimeout;
    kal_uint32      reg;
    kal_uint32      start_tick;

    if (rst_flag & SNAND_RST_WAIT_READY)
    {
        // wait for NFI Master Status being cleared

        start_tick = SNAND_Util_GetTimeUS();

        for (bTimeout = KAL_FALSE; bTimeout != KAL_TRUE;)
        {
            reg = *RW_NFI_MASTERSTA;

            if (0 == (reg & NFI_MASTERSTA_MASK))
            {
                break;
            }

            bTimeout = SNAND_Util_IsTimeout(start_tick, SPI_NAND_MAX_READ_BUSY_US);

            if (KAL_TRUE == bTimeout)
            {
                SNAND_dbg_print("[MTD INFO] Wait Ready Timeout!\n\r");
            }
        }
    }
    else if (rst_flag & SNAND_RST_CON)    // include NFI & SNF
    {
        //------ Part 1. NFI

        // 1-1. wait for NFI Master Status being cleared

        start_tick = SNAND_Util_GetTimeUS();

        for (bTimeout = KAL_FALSE; bTimeout != KAL_TRUE;)
        {
            reg = *RW_NFI_MASTERSTA;

            if (0 == (reg & NFI_MASTERSTA_MASK))
            {
                break;
            }

            bTimeout = SNAND_Util_IsTimeout(start_tick, NFI_MAX_RESET_US);

            if (KAL_TRUE == bTimeout)
            {
                SNAND_dbg_print("[MTD INFO] Reset Timeout!\n\r");
            }
        }

        // 1-2. reset NFI State Machine and Clear FIFO Counter

        *RW_NFI_CON = (NFI_FIFO_FLUSH | NFI_RST);

        // 1-3. wait for NAND Interface & NFI Internal FSM being reset

        start_tick = SNAND_Util_GetTimeUS();

        while (1)
        {
            reg = *RW_NFI_STA;

            if (0 == (reg & (NFI_STA_NFI_FSM_MASK | NFI_STA_NAND_FSM_MASK)))
            {
                break;
            }

            bTimeout = SNAND_Util_IsTimeout(start_tick, NFI_MAX_RESET_US);

            if (KAL_TRUE == bTimeout)
            {
                SNAND_dbg_print("[MTD INFO] Reset Timeout!\n\r");
            }
        }

        //------ Part  2. SNF: trigger SW_RST bit to reset state machine

        reg = *RW_SNAND_MISC_CTL;
        reg |= SNAND_SW_RST;
        SNAND_WriteReg32(RW_SNAND_MISC_CTL, reg);
        reg &= ~SNAND_SW_RST;
        SNAND_WriteReg32(RW_SNAND_MISC_CTL, reg);
    }
    else if (rst_flag & SNAND_RST_DEV)
    {
        // issue SW RESET command to device
        SNAND_Dev_Command_Ext(SNAND_SPI, &cmd, NULL, 1, 0);

        // wait for awhile, then polling status register (required by spec)
        SNAND_WaitUS(SPI_NAND_RESET_LATENCY_US);

        *RW_SNAND_GPRAM_DATA = (SNAND_CMD_GET_FEATURES | (SNAND_CMD_FEATURES_STATUS << 8));
        *RW_SNAND_MAC_OUTL = 2;
        *RW_SNAND_MAC_INL = 1;

        // polling status register
        start_tick = SNAND_Util_GetTimeUS();

        for (bTimeout = KAL_FALSE; bTimeout != KAL_TRUE;)
        {
            SNAND_MacEnable(SNAND_SPI);
            SNAND_MacTrigger();
            SNAND_MacLeave();

            cmd = SNAND_ReadReg8(((SNAND_P_U8)RW_SNAND_GPRAM_DATA + 2));

            if (0 == (cmd & SNAND_STATUS_OIP))
            {
                break;
            }

            bTimeout = SNAND_Util_IsTimeout(start_tick, SPI_NAND_RESET_LATENCY_US);
        }
    }
}

/****************************************************************************
 * Function:    SNAND_InitializeMTDData
 *
 * Parameters:
 *
 * Returns:
 *
 * Description: It gets ID and will change Flash_Info.deviceInfo_CE
 *                                         Flash_Info.valid_CE
 *                                         Flash_Info.devicePage
 ****************************************************************************/
kal_int32 SNAND_InitializeMTDData(void)       // read NAND ID and construct sub driver data
{
    const CMEMEntrySNAND *snand;
    kal_uint16 i, cs;
    kal_uint8  id_data[8];
    kal_uint32 totalSize = 0;

    /* Search NAND flash ID and */
    for(cs = 0; cs < g_c_snand_num_CS; cs++) /*[MAUI_00580753] apply g_c_snand_num_CS -- 2007/12/04*/
    {
        SNAND_Reset(SNAND_RST_WAIT_READY);

        SNAND_Reset(SNAND_RST_CON);

        SNAND_Reset(SNAND_RST_DEV);

        SNAND_Reset(SNAND_RST_CON);

        // read ID
        SNAND_COMMON_ReadID(id_data);

        id_data[0] = id_data[1];
        id_data[1] = id_data[2];
        id_data[2] = 0x00;

        #if defined(__COMBO_MEMORY_SUPPORT__)
        ComboNANDID[0] = (kal_uint8)id_data[0];
        ComboNANDID[1] = (kal_uint8)id_data[1];
        ComboNANDID[2] = 0x00;
        ComboNANDID[3] = 0x00;
        ComboNANDID[4] = 0x00;
        ComboNANDID[5] = 0x00;
        ComboNANDID[6] = 0x00;
        ComboNANDID[7] = 0x00;
        #endif

	    #if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
        MTD_Simu_SetIDData(id_data,cs);
        #endif

        #if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
            SNAND_dbg_print("CE%d ID = %x %x %x %x %x %x %x %x\r\n", cs,
             	id_data[0]&0xff, (id_data[0]>>8)&0xff, (id_data[0]>>16)&0xff, (id_data[0]>>24)&0xff,
             	id_data[1]&0xff, (id_data[1]>>8)&0xff, (id_data[1]>>16)&0xff, (id_data[1]>>24)&0xff);

        #endif

        kal_mem_set( Flash_Info.deviceInfo_CE[cs].ID_info, 0xFF, sizeof(Flash_Info.deviceInfo_CE[cs].ID_info) ); /*Reset value*/

        // get combo memory index
        if (0xFFFFFFFF == g_l_snand_combo_mem_idx)
        {
            g_l_snand_combo_mem_idx = *RW_SNAND_ER_CTL2;

            if (0xFFFFFF00 != (g_l_snand_combo_mem_idx & 0xFFFFFF00))
            {
                EXT_ASSERT(0, 0, 0, 0); // RW_SNAND_ER_CTL should not be changed because erase operation is not used before
            }

            g_l_snand_combo_mem_idx = g_l_snand_combo_mem_idx & 0x000000FF;

            if (0xFF == g_l_snand_combo_mem_idx)
            {
                return MTD_STATUS_ID_NOT_SUPPORT;
            }
        }

        // get combo memory entry
        snand = &(combo_mem_hw_list.List[g_l_snand_combo_mem_idx]);

        // copy flash_list structure to internal variable Flash_Info
        Flash_Info.deviceInfo_CE[cs].DevName_enum = (nand_Name)SPI_NAND_DUMMY_NAME;  // dummy entry for SPI-NAND

        for (i = 0; id_data[i] != 0; i++)
        {
            Flash_Info.deviceInfo_CE[cs].ID_info[i] = id_data[i];
        }

        for (; i < 8; i++)
        {
            Flash_Info.deviceInfo_CE[cs].ID_info[i] = 0;
        }

        Flash_Info.deviceInfo_CE[cs].IOWidth = 8;
        Flash_Info.deviceInfo_CE[cs].address_cycle = 3;
        Flash_Info.deviceInfo_CE[cs].planeNum = snand->plane_number;
        Flash_Info.deviceInfo_CE[cs].dieNum = 1;
        Flash_Info.deviceInfo_CE[cs].pageSize = snand->page_size_bytes;
        Flash_Info.deviceInfo_CE[cs].spareSize = snand->spare_size_bytes;
        Flash_Info.deviceInfo_CE[cs].blockPage = snand->block_size_kbytes * 1024 / snand->page_size_bytes;
        Flash_Info.deviceInfo_CE[cs].deviceSize = snand->total_size_mbits / 8;
        Flash_Info.deviceInfo_CE[cs].supportMPType = SIMPLE_OP;
        Flash_Info.deviceInfo_CE[cs].supportMEType = SIMPLE_OP;
        Flash_Info.deviceInfo_CE[cs].CopyBackType = SIMPLE_OP;

        Flash_Info.valid_CE[cs]   = KAL_TRUE;
        Flash_Info.devicePage[cs] = Flash_Info.deviceInfo_CE[cs].deviceSize * (1024 * 1024 / Flash_Info.deviceInfo_CE[cs].pageSize) ;
        Flash_Info.diePage[cs]    = Flash_Info.devicePage[cs] / Flash_Info.deviceInfo_CE[cs].dieNum ;
        Flash_Info.planePage[cs]  = Flash_Info.devicePage[cs] / Flash_Info.deviceInfo_CE[cs].dieNum / Flash_Info.deviceInfo_CE[cs].planeNum ;

        totalSize += Flash_Info.deviceInfo_CE[cs].deviceSize * 1024 * 1024;

        // set driver set & spare format (borrow Flash_Info.deviceInfo_CE[cs].ID_info[7]
        switch (snand->spare_format)
        {
            case SNAND_SPARE_FORMAT_MTK_1:
            case SNAND_SPARE_FORMAT_MTK_2:
                Flash_Info.deviceInfo_CE[cs].ID_info[7] = snand->spare_format;
                Flash_Info.deviceInfo_CE[cs].driverSet = &MTK_SPI_NAND_SUB_DRIVER_1;
                break;
            default:
                return MTD_STATUS_ID_NOT_SUPPORT;
        }
    }

    #if (defined(_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(__SPI_NAND_SUPPORT__)) ) && !defined(__UBL__)
        #if !defined(__NANDFDM_MULTI_INSTANCE__)
        dbg_ASSERT(totalSize >= NFB_ALLOCATED_FAT_SPACE + NFB_BASE_ADDRESS);
        #else  // !defined(__NANDFDM_MULTI_INSTANCE__)
        dbg_ASSERT(totalSize >= NFB_ALLOCATED_FAT_SPACE[CurDiskIndex] + NFB_BASE_ADDRESS[CurDiskIndex]);
        #endif  // !defined(__NANDFDM_MULTI_INSTANCE__)
    #endif

    #if defined(__SNAND_SW_CRC__)
    snand_crc_init();
    #endif

    #if defined(__SNAND_AP_MONITOR__)
    snand_apm_init();
    #endif

    return MTD_STATUS_NO_ERROR;
}
#if defined(__COMBO_MEMORY_SUPPORT__)
void MTD_ReadID(kal_uint32 id_num,kal_uint8* id_data)
{
  kal_mem_cpy(id_data,ComboNANDID,id_num );
}
#endif

/*******************************************************************************
 *  OTP functions
 *******************************************************************************/
kal_int32  SNAND_OTPAccess(kal_int32 accesstype, kal_uint32 PageAddr, void *BufferPtr, void *SparePtr)
{
      #if 0
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
      #endif

      return MTD_STATUS_ERROR;
}
kal_int32 SNAND_OTPQueryLength(kal_uint32 *Length)
{
      #if 0
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
      #endif

      return MTD_STATUS_ERROR;
}

/*******************************************************************************
 *  MTD functions
 *******************************************************************************/

#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)

#ifdef __NAND_LMT__

extern char ReadBackImage[2][100];

void SNAND_MTD_LMT_Open_Device_File(void)
{
	int i;
    for ( i = 0; i < 2 && (Flash_Info.valid_CE[i] == KAL_TRUE); i++)
    {
		file_name[i] = ReadBackImage[i];
        file_hd[i] = fopen(file_name[i], "rb+"); /*for read and update (not allow append)*/
    }
}

#else // __NAND_LMT__

void SNAND_MTD_Simu_Create_Device_File (void)
{
    int i, j, k;
    kal_uint32 devSize;
    #if 1
    file_name[0] = ".\\NANDflash_device0.img";
    file_name[1] = ".\\NANDflash_device1.img";
    #else
/* under construction !*/
/* under construction !*/
    #endif
    kal_mem_set(MTD_simu_buff, 0xFF, sizeof(MTD_simu_buff));
    for ( i = 0; i < 2 && (Flash_Info.valid_CE[i] == KAL_TRUE); i++)
    {
        devSize = Flash_Info.deviceInfo_CE[i].deviceSize*1024*1024;
        devSize = (Flash_Info.deviceInfo_CE[i].supportMPType& EXTENDED_BLOCK) == EXTENDED_BLOCK ? devSize/1024*(1024+16) : devSize;
        if( (file_hd[i] = fopen(file_name[i], "rb+")) == NULL )
        {
           // it doesn't exist
           file_hd[i] = fopen(file_name[i], "wb+");
           for (j=0;j < devSize/Flash_Info.deviceInfo_CE[i].pageSize; j++ )
           {
               fwrite(MTD_simu_buff, sizeof(char), (Flash_Info.deviceInfo_CE[i].pageSize+Flash_Info.deviceInfo_CE[i].spareSize), file_hd[i]);
           }
        }
        else
        {
           long file_size = 0;
           fseek(file_hd[i], 0, SEEK_END);
           file_size = ftell(file_hd[i]);

           if (file_size != devSize/Flash_Info.deviceInfo_CE[i].pageSize*(Flash_Info.deviceInfo_CE[i].pageSize+Flash_Info.deviceInfo_CE[i].spareSize) )
           {
              fseek(file_hd[i], 0, SEEK_SET);
              fclose(file_hd[i]);
              // truncate the file
              file_hd[i] = fopen(file_name[i], "wb");
              fclose(file_hd[i]);
              // reopen
              file_hd[i] = fopen(file_name[i], "wb+");
              for (j=0;j < devSize/Flash_Info.deviceInfo_CE[i].pageSize; j++ )
              {
                  fwrite(MTD_simu_buff, sizeof(char), (Flash_Info.deviceInfo_CE[i].pageSize+Flash_Info.deviceInfo_CE[i].spareSize), file_hd[i]);
              }
           }

           fseek(file_hd[i], 0, SEEK_END);
           if( 0 == ftell(file_hd[i]) )
           {
               for (j=0;j < devSize/Flash_Info.deviceInfo_CE[i].pageSize; j++ )
               {
                   fwrite(MTD_simu_buff, sizeof(char), (Flash_Info.deviceInfo_CE[i].pageSize+Flash_Info.deviceInfo_CE[i].spareSize), file_hd[i]);
               }
           }
        }
        fflush(file_hd[i]);
        fclose(file_hd[i]);
        file_hd[i] = fopen(file_name[i], "rb+"); /*for read and update (not allow append)*/
    }
}

#endif // __NAND_LMT__

void SNAND_MTD_Simu_SetUserDefID(kal_uint32 cs0_ID_0_3,kal_uint32 cs0_ID_4_7,kal_uint32 cs1_ID_0_3,kal_uint32 cs1_ID_4_7)
{
    user_def_cs_num = 2;
    user_def_id_data[0][0] = cs0_ID_0_3;
    user_def_id_data[0][1] = cs0_ID_4_7;
    user_def_id_data[1][0] = cs1_ID_0_3;
    user_def_id_data[1][1] = cs1_ID_4_7;
}

void SNAND_MTD_Simu_SetIDData(kal_uint32* id_data,kal_uint8 cs)
{
    id_data[0] = user_def_id_data[cs][0];
    id_data[1] = user_def_id_data[cs][1];
}


#if defined DAL_DLL_VERSION
void SNAND_MTD_WriteErrMsg(char* title, char* exp, char* f, kal_uint32 line, kal_uint32 e1, kal_uint32 e2, kal_uint32 e3)
{
    //char msg[128];
    char* file_name;
    void* file_hd = NULL;

    file_name = ".\\ErrMsg.txt";

    if( (file_hd = fopen(file_name, "a+")) != NULL )
    {
        fprintf(file_hd,"%s file:%s line:%d expr:%s e1:%d e2:%d e3:%d\r\n",title,f,line,exp,e1,e2,e3);

        fclose(file_hd);
    }
}
#endif

#endif

kal_int32 MTD_MountDevice( void)
{
    kal_int32 check_value = MTD_STATUS_NO_ERROR;

    // initialize power control handler
    SNAND_PowerInit();

    SNAND_PowerCtl(KAL_TRUE);

    if (!g_b_snand_is_initialized)
    {
        /*
         * set NFI conrol bin in GPIO
         * it should be consistent with GPIO_init() of custom\drv\misc_drv\XXX\gpio_drv.c
         */
        g_c_snand_num_CS = SNAND_GPIO_Setting();    // GPIO was configured in ext-bootloader

        #if defined(__UBL__)
            custom_snand_init_in_extbootloader();
        #endif

#if !(defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)) // if !(MTD driver simulation)

        // initialize DMA and interrupt

        *NFI_INTR_EN = 0x0;    // disable interrupt

        #if (defined __UBL__) || (defined __FUE__)
        /*Do not create nfi_egid in boot loader and fota case*/
        #else
        if ( stack_query_boot_mode() != USBMS_BOOT
            #if defined(__FUE__)
     		 && (stack_query_boot_mode() != FUE_BOOT )
            #endif
       	   )
        {
            nfi_egid = kal_create_event_group("NFI_EG");

            DRV_Register_HISR(DRV_NFI_HISR_ID, nfi_hisr);

            IRQ_Register_LISR(IRQ_NFI_CODE, nfi_lisr, "NFI_LISR");
            IRQSensitivity(IRQ_NFI_CODE, EDGE_SENSITIVE);
            IRQUnmask(IRQ_NFI_CODE);
        }
        #endif

#endif
    }

    // initialize FDM/DAL/MTD driver stuff and essential SPI-NAND device configurations for Maui

    SNAND_Reset(SNAND_RST_CON);

    check_value = SNAND_InitializeMTDData( );

    #if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__) && !defined(DAL_DLL_VERSION)

        #ifdef __NAND_LMT__
        MTD_LMT_Open_Device_File();
        #else // __NAND_LMT__
        MTD_Simu_Create_Device_File();
        #endif // __NAND_LMT__

    #endif

    // enable device ECC feasility
    SNAND_COMMON_ECCCon(KAL_TRUE);

    // unlock all blocks
    SNAND_COMMON_UnlockFlash();

    SNAND_Reset(SNAND_RST_CON);

    SNAND_PowerCtl(KAL_FALSE);

    g_b_snand_is_initialized = KAL_TRUE;

    if (MTD_STATUS_NO_ERROR == check_value)
    {
        return FS_NO_ERROR;
    }
    else if (MTD_STATUS_ID_NOT_SUPPORT == check_value)
    {
        return FS_NAND_DEVICE_NOT_SUPPORTED;
    }
    else
    {
        return FS_FLASH_MOUNT_ERROR;
    }
}   /*  End of MountDevice */

kal_uint32 MTD_Program (mtd_if_para* Para)
{
    kal_uint32 status = MTD_STATUS_NO_ERROR;
    kal_uint32 num_written_pages;
    SNAND_MTD_DRV_PARA drv_para;

    SNAND_TIME_INIT(2, 1);
    SNAND_TIME_RECORD(0);

    //------ Parameter Check Start ------
    dbg_ASSERT(Para->spare);
    dbg_ASSERT(Para->ce < 2);
    dbg_ASSERT(Flash_Info.pageSize % 512 == 0);
    dbg_ASSERT(Para->length == 1);
    //------ Parameter Check End --------

    /* SW Workaroud for HW Defects
     *
     * [MTK_INTERNAL_SPI_NAND_1 Application Note]
     * Block 1020~1023 can not be accessed and all the operations to this block were
     * prohibited.
     */
    if (SNAND_SPARE_FORMAT_MTK_1 == Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[7])
    {
        if (Para->pageIdx[0] >= (1020 * Flash_Info.blockPage))
        {
            return MTD_STATUS_ERROR;
        }
    }

    SNAND_PowerCtl(KAL_TRUE);

    if (! (nfi_egid && use_interrupt == KAL_TRUE) )
    {
        if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
            use_interrupt = KAL_TRUE;
    }

    drv_para.page_size = Flash_Info.pageSize;
    drv_para.data_bytes = Flash_Info.pageSize;  // TODO: MTD allowed col_addr ??
    drv_para.spare_bytes = Flash_Info.spareSize;
    drv_para.row_addr = Para->pageIdx[0];
    drv_para.col_addr = 0;
    drv_para.data = &Para->buff[0];
    drv_para.spare = &Para->spare[0];

    num_written_pages = 0;

    while (num_written_pages < Para->length)
    {
        if (ONE_SPARE & Para->opFlag)
        {
    	    drv_para.spare = &Para->spare[0];
        }

        status = SNAND_COMMON_RawWrite(&drv_para);
        num_written_pages++;

        drv_para.data += drv_para.data_bytes;
    }

    #if defined DAL_VERIFICATION
    if (Mtd_Fail_Offset != 0xFF)
    { /*test case*/
        status = MTD_STATUS_ERROR|(1<<Mtd_Fail_Offset);
    }
    #endif

    // add following two lines in order to reset FSM and disassert CS.
    SNAND_Reset(SNAND_RST_CON);

    SNAND_PowerCtl(KAL_FALSE);

    SNAND_TIME_RECORD(1);
    SNAND_dbg_time_add_record(SNAND_SW_LAYER_MTD_UPPER, SNAND_DEV_PROGRAM, SNAND_TIME_GET_DURATION_US(0, 1));

    return status;
}

kal_uint32 MTD_Read(mtd_if_para* Para)
{
    kal_uint32          status = MTD_STATUS_NO_ERROR;
    SNAND_MTD_DRV_PARA  drv_para;

    SNAND_TIME_INIT(2, 1);
    SNAND_TIME_RECORD(0);

    //------ Parameter Check Start ------
    #if (defined __UBL__) || (defined __FUE__)
    /*It's possible to read code to 0x0 at bootloader*/
    #else
    force_ASSERT(Para->buff,0,0,0);
    #endif
    dbg_ASSERT(1 == Para->length); // REMARKS! Support single page read only now!
    //------ Parameter Check End ------

    SNAND_PowerCtl(KAL_TRUE);

    if (! (nfi_egid && use_interrupt == KAL_TRUE) )
    {
        #if defined(_NAND_FLASH_BOOTING_) || (defined(__UP_PKG_ON_NAND__) && defined(__SPI_NAND_SUPPORT__))
        if(!DemandPageingRead && nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
        #else // _NAND_FLASH_BOOTING_
        if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
        #endif // _NAND_FLASH_BOOTING_ || (__UP_PKG_ON_NAND__ && __SPI_NAND_SUPPORT__)
            use_interrupt = KAL_TRUE;
    }

    drv_para.page_size = Flash_Info.pageSize;
    drv_para.data_bytes = Flash_Info.pageSize;
    drv_para.spare_bytes = Flash_Info.spareSize;
    drv_para.row_addr = Para->pageIdx[0];
    drv_para.col_addr = 0;
    drv_para.data = &Para->buff[0];
    drv_para.spare = &Para->spare[0];

    status = SNAND_COMMON_RawRead(&drv_para);

    #if defined DAL_VERIFICATION
    if (Mtd_Fail_Offset != 0xFF)
    { /*test case*/
        status = MTD_STATUS_ERROR|(1<<Mtd_Fail_Offset);
    }
    #endif

    SNAND_Reset(SNAND_RST_CON);

    SNAND_PowerCtl(KAL_FALSE);

    SNAND_TIME_RECORD(1);
    SNAND_dbg_time_add_record(SNAND_SW_LAYER_MTD_UPPER, SNAND_DEV_READ, SNAND_TIME_GET_DURATION_US(0, 1));

    return status;
}

kal_uint32 MTD_Erase(mtd_if_para* Para)
{
    kal_uint32 status = MTD_STATUS_NO_ERROR;

    SNAND_TIME_INIT(2, 1);
    SNAND_TIME_RECORD(0);

    //------ Parameter Check Start ------
    dbg_ASSERT(Flash_Info.pageSize % 512 == 0);
    dbg_ASSERT(Para->length <= 1);  // RAMARKS: Only allow 1 block erase now!
    //------ Parameter Check End ------

    /* SW Workaroud for HW Defects
     *
     * [MTK_INTERNAL_SPI_NAND_1 Application Note]
     * Block 1020~1023 can not be accessed and all the operations to this block were
     * prohibited.
     */
    if (SNAND_SPARE_FORMAT_MTK_1 == Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[7])
    {
        if (Para->pageIdx[0] >= (1020 * Flash_Info.blockPage))
        {
            return MTD_STATUS_ERROR;
        }
    }

    SNAND_PowerCtl(KAL_TRUE);

    if (! (nfi_egid && use_interrupt == KAL_TRUE) )
    {
        if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
            use_interrupt = KAL_TRUE;
    }

    status = SNAND_COMMON_BlockErase(Para->pageIdx[0]);

    #if defined DAL_VERIFICATION
    if (Mtd_Fail_Offset != 0xFF)
    { /*test case*/
        status = MTD_STATUS_ERROR|(1<<Mtd_Fail_Offset);
    }
    #endif

    SNAND_Reset(SNAND_RST_CON);

    SNAND_PowerCtl(KAL_FALSE);

    SNAND_TIME_RECORD(1);
    SNAND_dbg_time_add_record(SNAND_SW_LAYER_MTD_UPPER, SNAND_DEV_ERASE, SNAND_TIME_GET_DURATION_US(0, 1));

    return status;
}
/****************************************************************************
 * Function:
 *
 * Parameters:
 *
 * Returns:
 *
 * Description:
 *
 ****************************************************************************/
/*The content of MTD_MarkBlockBad would be different with BaseBand chip*/
/*Use FDM bad block mark*/
kal_uint32 MTD_MarkBlockBad (mtd_if_para* Para)
{
    kal_uint32          status = MTD_STATUS_NO_ERROR;
    SNAND_MTD_DRV_PARA  drv_para;
    kal_uint32          failPage;

    //------ Parameter Check Start ------
    dbg_ASSERT(Para->buff);
    dbg_ASSERT(Para->spare);
    dbg_ASSERT(Flash_Info.pageSize % 512 == 0);
    //------ Parameter Check End ------

    /* SW Workaroud for HW Defects
     *
     * [MTK_INTERNAL_SPI_NAND_1 Application Note]
     * Block 1020~1023 can not be accessed and all the operations to this block were
     * prohibited.
     */
    if (SNAND_SPARE_FORMAT_MTK_1 == Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[7])
    {
        if (Para->pageIdx[0] >= (1020 * Flash_Info.blockPage))
        {
            return MTD_STATUS_NO_ERROR;
        }
    }

    // mark bad in NAND spare

    /*The action of mark maybe different according to the BB chip's NFI version*/
    ((kal_uint8 *)(Para->spare))[0] = 0x00;
    SNAND_COMMON_SetBadBlockMark(SNAND_COMMON_GetBadBlockMark(Para->spare) & FDM_BAD_BLOCK_MARK_2K, Para->spare); // use &= to adapte the original mark, ex: 0x00(early bad)

    // single page program

    SNAND_PowerCtl(KAL_TRUE);

    if (! (nfi_egid && use_interrupt == KAL_TRUE) )
    {
        if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
            use_interrupt = KAL_TRUE;
    }

    drv_para.page_size = Flash_Info.pageSize;
    drv_para.data_bytes = Flash_Info.pageSize;
    drv_para.spare_bytes = Flash_Info.spareSize;
    drv_para.row_addr = Para->pageIdx[0];
    drv_para.col_addr = 0;
    drv_para.data = &Para->buff[0];
    drv_para.spare = &Para->spare[0];

    status = SNAND_COMMON_RawWrite(&drv_para);

    if (status != MTD_STATUS_NO_ERROR)
    {
        failPage = status & 0xFFFF;
        status = status & 0xFFFF0000;
        status |= failPage;
    }

    // add following two lines in order to reset FSM and disassert CS.
    SNAND_Reset(SNAND_RST_CON);

    SNAND_PowerCtl(KAL_FALSE);

    #if defined(__SNAND_BI_CACHE__)
    // set bad block mark in BI cache
    failPage = Para->pageIdx[0] / Flash_Info.blockPage;

    if (failPage < SNAND_BI_CACHE_CNT)
    {
        snand_bicache_set_value(g_snand_bi_cache_checked, failPage, 1);
        snand_bicache_set_value(g_snand_bi_cache_bad, failPage, 1);
    }
    #endif  // __SNAND_BI_CACHE__

    return status;
}

/****************************************************************************
 * Function:
 *
 * Parameters:
 *
 * Returns:      MTD_STATUS_ERROR - The block is a Bad block
 *               MTD_STATUS_NO_ERROR - Block mark is all 1 (or only 1 zero) in 1 byte
 * Description:  This function is use to check the early bad (manufacture mark bad)
 *
 ****************************************************************************/
/*The content of MTD_MarkBlockBad would be different with BaseBand chip*/
/*Use FDM bad block mark*/
kal_uint32 MTD_CheckBlockBad (mtd_if_para* Para)
{
    kal_uint32          status = MTD_STATUS_NO_ERROR;
    kal_uint32          mtd_status = MTD_STATUS_NO_ERROR;
    SNAND_MTD_DRV_PARA  drv_para;

    //------ Parameter Check Start ------
    dbg_ASSERT(Para->buff);
    dbg_ASSERT(Para->spare);
    dbg_ASSERT(Flash_Info.pageSize % 512 == 0);
    //------ Parameter Check End ------

    /* SW Workaroud for HW Defects
     *
     * [GigaDevice Application Note]
     * Block 1020~1023 can not be accessed and all the operations to this block were
     * prohibited.
     */
    if (SNAND_SPARE_FORMAT_MTK_1 == Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[7])
    {
        if (Para->pageIdx[0] >= (1020 * Flash_Info.blockPage))
        {
            SNAND_dbg_print("[MTD INFO] Bad Block Detected (GD Initial), row:%d(blk:%d)\n\r", Para->pageIdx[0], Para->pageIdx[0] / Flash_Info.blockPage);

            return MTD_STATUS_ERROR;
        }
    }

    #if defined(__SNAND_BI_CACHE__)
    // check bad block status by BI cache
    mtd_status = Para->pageIdx[0] / Flash_Info.blockPage;

    if (mtd_status < SNAND_BI_CACHE_CNT)
    {
        if (1 == snand_bicache_get_value(g_snand_bi_cache_checked, mtd_status))
        {
            if (1 == snand_bicache_get_value(g_snand_bi_cache_bad, mtd_status))
            {
                return MTD_STATUS_ERROR;
            }
            else
            {
                return MTD_STATUS_NO_ERROR;
            }
        }
    }
    #endif  // __SNAND_BI_CACHE__

    SNAND_PowerCtl(KAL_TRUE);

    if (! (nfi_egid && use_interrupt == KAL_TRUE) )
    {
        if(nfi_egid && (kal_query_systemInit() == KAL_FALSE && INT_QueryExceptionStatus() == KAL_FALSE))
            use_interrupt = KAL_TRUE;
    }

    drv_para.page_size = Flash_Info.pageSize;
    drv_para.data_bytes = Flash_Info.pageSize;
    drv_para.spare_bytes = Flash_Info.spareSize;
    drv_para.row_addr = Para->pageIdx[0];
    drv_para.col_addr = 0;
    drv_para.data = &Para->buff[0];
    drv_para.spare = &Para->spare[0];

    mtd_status = SNAND_COMMON_RawRead(&drv_para);

    SNAND_Reset(SNAND_RST_CON);

    SNAND_PowerCtl(KAL_FALSE);

    // check bad block Mark in NAND spare
    if ((Para->spare[0] != 0xFF))
    {
        status = MTD_STATUS_ERROR;

        #if defined(__UBL__)
        bl_print(LOG_INFO, "[MTD INFO] Bad Block Detected, row:%d(blk:%d), Spare[0]:%x, BI:%x\n\r", Para->pageIdx[0], Para->pageIdx[0] / Flash_Info.blockPage, Para->spare[0], SNAND_COMMON_GetBadBlockMark(Para->spare));
        #else
        SNAND_dbg_print("[MTD INFO] Bad Block Detected, row:%d(blk:%d), Spare[0]:%x, BI:%x\n\r", Para->pageIdx[0], Para->pageIdx[0] / Flash_Info.blockPage, Para->spare[0], SNAND_COMMON_GetBadBlockMark(Para->spare));
        #endif
    }
    else
    {
        if (mtd_status == MTD_STATUS_ERROR)
        {
            SNAND_dbg_print("[MTD INFO] Read Wrong But Early Bad mark is good, status:%x, row:%d(blk:%d), Spare[0]:%x, BI:%x\n\r", status, Para->pageIdx[0], Para->pageIdx[0] / Flash_Info.blockPage, Para->spare[0], SNAND_COMMON_GetBadBlockMark(Para->spare));
        }
    }

    #if defined(__SNAND_BI_CACHE__)
    // set bad block mark in BI cache
    mtd_status = Para->pageIdx[0] / Flash_Info.blockPage;

    if (mtd_status < SNAND_BI_CACHE_CNT)
    {
        snand_bicache_set_value(g_snand_bi_cache_checked, mtd_status, 1);

        if (MTD_STATUS_ERROR == status) // bad block
        {
            snand_bicache_set_value(g_snand_bi_cache_bad, mtd_status, 1);
        }
        else
        {
            snand_bicache_set_value(g_snand_bi_cache_bad, mtd_status, 0);
        }
    }
    #endif  // __SNAND_BI_CACHE__

    return status;
}

/****************************************************************************
 * Function:
 *
 * Parameters:
 *
 * Returns:  MTD_STATUS_NO_ERROR
 *
 * Description:
 *
 ****************************************************************************/
kal_uint32 MTD_NAND_Reset(mtd_if_para* Para)
{
    SNAND_PowerCtl(KAL_TRUE);

    SNAND_Reset(SNAND_RST_CON);

    SNAND_Reset(SNAND_RST_DEV);

    SNAND_PowerCtl(KAL_FALSE);

    return MTD_STATUS_NO_ERROR;
}

/*******************************************************************************/
kal_int32 MTD_ShutDown(void)
{
#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
    if( NULL != file_hd[0] )
       fclose(file_hd[0]);
    if( NULL != file_hd[1] )
       fclose(file_hd[1]);
#else
    #if defined(_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(__SPI_NAND_SUPPORT__))
        #if (defined __UBL__) || (defined __FUE__)
        #else
    		SNAND_PowerCtl(KAL_TRUE);
            SNAND_Reset(SNAND_RST_WAIT_READY);
            SNAND_PowerCtl(KAL_FALSE);
        #endif
    #endif /* _NAND_FLASH_BOOTING || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && __SPI_NAND_SUPPORT__) */
#endif

    return FS_NO_ERROR;
} /*  End of ShutDown */

#if !defined(__FUE__)

/*******************************************************************************/
void nfi_lisr(void)
{
    #if (defined __UBL__) || (defined __FUE__)
        // In bootloader and fota case, it should not get in
        force_ASSERT(0, 0, 0, 0);
    #elif defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
        // Do nothing
    #else
        IRQMask(IRQ_NFI_CODE);
        drv_active_hisr(DRV_NFI_HISR_ID);
    #endif
}


/*******************************************************************************/
void nfi_hisr(void)
{
    #if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
        // Do nothing
    #else
        #if (defined __UBL__) || (defined __FUE__)
            // In bootloader and fota case, it should not get in
            force_ASSERT(0, 0, 0, 0);
        #else
            kal_uint32 intr_status;

            intr_status = *RW_NFI_INTR; // read & clear
            *RW_NFI_INTR_EN = 0x0;      // reset all SNF interrupt settings

            // For AUTO-READ and CUSTOM-READ, wait NFI_AHB_DONE_EN to ensure bus operation (SNF to buffer) is done
            // For AUTO-PROGRAM, AUTO-ERASE and CUSTOM-PROGRAM, using its own interrupt signal is enough
            if (intr_status & (NFI_AUTO_PROG_INTR_EN | NFI_AUTO_BLKER_INTR_EN |
                               NFI_CUSTOM_PROG_DONE_INTR_EN |
                               NFI_AHB_DONE_EN))
            {
                kal_set_eg_events(nfi_egid, NFI_EVENT, KAL_OR);
            }
            else if (intr_status != 0)
            {
                force_ASSERT(0, intr_status, 0, 0);
            }

            IRQClearInt(IRQ_NFI_CODE);
            IRQUnmask(IRQ_NFI_CODE);
        #endif
    #endif
}


/*******************************************************************************/
void NFI_DMA_Callback(void)
{
    #if (defined __UBL__) || (defined __FUE__)
        // n bootloader and fota case, it should not get in */
        force_ASSERT(0, 0, 0, 0);
    #elif defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
        // Do nothing*/
    #else
        if (nfi_egid)
        {
            kal_set_eg_events(nfi_egid, NFI_EVENT, KAL_OR);
        }
    #endif
}

#else // !defined(__FUE__)

void NFI_DMA_Callback(void)
{
   dbg_ASSERT(0);
}

#endif // !defined(__FUE__)

kal_bool NAND_INT_USBBoot(void) // Backward compatible
{
    #if (defined(__FUE__)||defined(__UBL__))
        return KAL_FALSE;
    #else
    	PW_CTRL_IS_USB_BOOT CtrlVal;
    	DCL_HANDLE handle;
    	handle=DclPW_Open(DCL_PW, FLAGS_NONE);
    	DclPW_Control(handle, PW_CMD_IS_USB_BOOT,(DCL_CTRL_DATA_T *)&CtrlVal);
    	DclPW_Close(handle);
    	return (kal_bool)CtrlVal.val;
    #endif//#if (defined(__FUE__)||defined(__UBL__))
}

kal_uint32 nAND_RESET (void)    // reset API for SPI-NAND test
{
    SNAND_Reset(SNAND_RST_CON);

    SNAND_Reset(SNAND_RST_DEV);

    return MTD_STATUS_NO_ERROR;
}

#if defined(__SNAND_SW_CRC__)
void snand_crc_init(void)
{
    #if 0   // use static table instead (the same RAM consumption)
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
    #endif
}   /* snand_crc_init() */

crc_t snand_crc_gen(kal_uint8 const message[], int nBytes)
{
    kal_uint8 data;
    crc_t remainder = 0;
    kal_int32 byte;

    /*
     * Divide the message by the polynomial, a byte at a time.
     */
    for (byte = 0; byte < nBytes; ++byte)
    {
        data = message[byte] ^ (remainder >> (_CRC_WIDTH - 8));
        remainder = g_snand_crcTable[data] ^ (remainder << 8);
    }

    /*
     * The final remainder is the CRC.
     */

    if ((crc_t)(0xFFFFFFFF) == remainder)
    {
        remainder = remainder - 1;
    }

    return (remainder);

}   /* snand_crc_gen() */

kal_uint16 snand_crc_gen_for_spare(void * spare)
{
    if (SNAND_SPARE_FORMAT_MTK_1 == Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[7])
    {
        // calculate CRC of BM_PA + LBA
        return (kal_uint16)snand_crc_gen((kal_uint8 *)&(((FDMDataU_2K_MTK_1 *)(spare))->BM_PA), 2 * sizeof(kal_uint16));
    }
    else if (SNAND_SPARE_FORMAT_MTK_2 == Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[7])
    {
        // calculate CRC of BM_PA + LBA
        return (kal_uint16)snand_crc_gen((kal_uint8 *)&(((FDMDataU_2K_MTK_2 *)(spare))->BM_PA), 2 * sizeof(kal_uint16));
    }

    return 0;
}

kal_uint16 snand_crc_get(void * spare)
{
    if (SNAND_SPARE_FORMAT_MTK_1 == Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[7])
    {
        return ((FDMDataU_2K_MTK_1 *)spare)->PBA;
    }
    else if (SNAND_SPARE_FORMAT_MTK_2 == Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[7])
    {
        return ((FDMDataU_2K_MTK_2 *)spare)->PBA;
    }

    return 0;
}

void snand_crc_set(kal_uint16 crc_code, void * spare)
{
    if (SNAND_SPARE_FORMAT_MTK_1 == Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[7])
    {
        ((FDMDataU_2K_MTK_1 *)spare)->PBA = crc_code;
    }
    else if (SNAND_SPARE_FORMAT_MTK_2 == Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[7])
    {
        ((FDMDataU_2K_MTK_2 *)spare)->PBA = crc_code;
    }

    return;
}
#endif  // __SNAND_SW_CRC__


#if defined(__SNAND_DEBUG__)

#define SNAND_TIME_LOG_CNT  (100)

kal_uint32 g_snand_time[SNAND_SW_LAYER_CNT][SNAND_DEV_CNT][SNAND_TIME_LOG_CNT];
kal_uint32 g_snand_time_total[SNAND_SW_LAYER_CNT][SNAND_DEV_CNT] = {0};
kal_uint32 g_snand_time_cnt[SNAND_SW_LAYER_CNT][SNAND_DEV_CNT] = {0};
kal_uint32 g_snand_time_idx[SNAND_SW_LAYER_CNT][SNAND_DEV_CNT] = {0};

void SNAND_dbg_time_init()
{
    kal_mem_set((void *)g_snand_time_cnt, 0x00, sizeof(kal_uint32) * SNAND_SW_LAYER_CNT * SNAND_DEV_CNT);
    kal_mem_set((void *)g_snand_time_total, 0x00, sizeof(kal_uint32) * SNAND_SW_LAYER_CNT * SNAND_DEV_CNT);
}

void SNAND_dbg_time_dump()
{
    if (g_snand_time_cnt[SNAND_SW_LAYER_HW][SNAND_DEV_READ] != 0)
        SNAND_dbg_print("[SNAND TIME] HW-Read, Avg: %d us\n\r", g_snand_time_total[SNAND_SW_LAYER_HW][SNAND_DEV_READ] / g_snand_time_cnt[SNAND_SW_LAYER_HW][SNAND_DEV_READ]);
    if (g_snand_time_cnt[SNAND_SW_LAYER_MTD_LOWER][SNAND_DEV_READ] != 0)
        SNAND_dbg_print("[SNAND TIME] MTD-LOWER-Read, Avg: %d us\n\r", g_snand_time_total[SNAND_SW_LAYER_MTD_LOWER][SNAND_DEV_READ] / g_snand_time_cnt[SNAND_SW_LAYER_MTD_LOWER][SNAND_DEV_READ]);
    if (g_snand_time_cnt[SNAND_SW_LAYER_MTD_UPPER][SNAND_DEV_READ] != 0)
        SNAND_dbg_print("[SNAND TIME] MTD-UPPER-Read, Avg: %d us\n\r", g_snand_time_total[SNAND_SW_LAYER_MTD_UPPER][SNAND_DEV_READ] / g_snand_time_cnt[SNAND_SW_LAYER_MTD_UPPER][SNAND_DEV_READ]);
    if (g_snand_time_cnt[SNAND_SW_LAYER_DAL][SNAND_DEV_READ] != 0)
        SNAND_dbg_print("[SNAND TIME] DAL-Read, Avg: %d us\n\r", g_snand_time_total[SNAND_SW_LAYER_DAL][SNAND_DEV_READ] / g_snand_time_cnt[SNAND_SW_LAYER_DAL][SNAND_DEV_READ]);
    if (g_snand_time_cnt[SNAND_SW_LAYER_FDM][SNAND_DEV_READ] != 0)
        SNAND_dbg_print("[SNAND TIME] FDM-Read, Avg: %d us\n\r", g_snand_time_total[SNAND_SW_LAYER_FDM][SNAND_DEV_READ] / g_snand_time_cnt[SNAND_SW_LAYER_FDM][SNAND_DEV_READ]);

    if (g_snand_time_cnt[SNAND_SW_LAYER_HW][SNAND_DEV_PROGRAM] != 0)
        SNAND_dbg_print("[SNAND TIME] HW-Write, Avg: %d us\n\r", g_snand_time_total[SNAND_SW_LAYER_HW][SNAND_DEV_PROGRAM] / g_snand_time_cnt[SNAND_SW_LAYER_HW][SNAND_DEV_PROGRAM]);
    if (g_snand_time_cnt[SNAND_SW_LAYER_MTD_LOWER][SNAND_DEV_PROGRAM] != 0)
        SNAND_dbg_print("[SNAND TIME] MTD-LOWER-Write, Avg: %d us\n\r", g_snand_time_total[SNAND_SW_LAYER_MTD_LOWER][SNAND_DEV_PROGRAM] / g_snand_time_cnt[SNAND_SW_LAYER_MTD_LOWER][SNAND_DEV_PROGRAM]);
    if (g_snand_time_cnt[SNAND_SW_LAYER_MTD_UPPER][SNAND_DEV_PROGRAM] != 0)
        SNAND_dbg_print("[SNAND TIME] MTD-UPPER-Write, Avg: %d us\n\r", g_snand_time_total[SNAND_SW_LAYER_MTD_UPPER][SNAND_DEV_PROGRAM] / g_snand_time_cnt[SNAND_SW_LAYER_MTD_UPPER][SNAND_DEV_PROGRAM]);
    if (g_snand_time_cnt[SNAND_SW_LAYER_DAL][SNAND_DEV_PROGRAM] != 0)
        SNAND_dbg_print("[SNAND TIME] DAL-Write, Avg: %d us\n\r", g_snand_time_total[SNAND_SW_LAYER_DAL][SNAND_DEV_PROGRAM] / g_snand_time_cnt[SNAND_SW_LAYER_DAL][SNAND_DEV_PROGRAM]);
    if (g_snand_time_cnt[SNAND_SW_LAYER_FDM][SNAND_DEV_PROGRAM] != 0)
        SNAND_dbg_print("[SNAND TIME] FDM-Write, Avg: %d us\n\r", g_snand_time_total[SNAND_SW_LAYER_FDM][SNAND_DEV_PROGRAM] / g_snand_time_cnt[SNAND_SW_LAYER_FDM][SNAND_DEV_PROGRAM]);

    if (g_snand_time_cnt[SNAND_SW_LAYER_HW][SNAND_DEV_ERASE] != 0)
        SNAND_dbg_print("[SNAND TIME] HW-Erase, Avg: %d us\n\r", g_snand_time_total[SNAND_SW_LAYER_HW][SNAND_DEV_ERASE] / g_snand_time_cnt[SNAND_SW_LAYER_HW][SNAND_DEV_ERASE]);
    if (g_snand_time_cnt[SNAND_SW_LAYER_MTD_LOWER][SNAND_DEV_ERASE] != 0)
        SNAND_dbg_print("[SNAND TIME] MTD-LOWER-Erase, Avg: %d us\n\r", g_snand_time_total[SNAND_SW_LAYER_MTD_LOWER][SNAND_DEV_ERASE] / g_snand_time_cnt[SNAND_SW_LAYER_MTD_LOWER][SNAND_DEV_ERASE]);
    if (g_snand_time_cnt[SNAND_SW_LAYER_MTD_UPPER][SNAND_DEV_ERASE] != 0)
        SNAND_dbg_print("[SNAND TIME] MTD-UPPER-Erase, Avg: %d us\n\r", g_snand_time_total[SNAND_SW_LAYER_MTD_UPPER][SNAND_DEV_ERASE] / g_snand_time_cnt[SNAND_SW_LAYER_MTD_UPPER][SNAND_DEV_ERASE]);
    if (g_snand_time_cnt[SNAND_SW_LAYER_DAL][SNAND_DEV_ERASE] != 0)
        SNAND_dbg_print("[SNAND TIME] DAL-Erase, Avg: %d us\n\r", g_snand_time_total[SNAND_SW_LAYER_DAL][SNAND_DEV_ERASE] / g_snand_time_cnt[SNAND_SW_LAYER_DAL][SNAND_DEV_ERASE]);
}

void SNAND_dbg_time_add_record(SNAND_Sw_Layer layer, SNAND_Dev_Operation op, kal_uint32 val)
{
    g_snand_time[layer][op][g_snand_time_idx[layer][op]] = val;

    g_snand_time_cnt[layer][op]++;
    g_snand_time_total[layer][op] += val;

    g_snand_time_idx[layer][op]++;

    if (g_snand_time_idx[layer][op] >= SNAND_TIME_LOG_CNT)
    {
        g_snand_time_idx[layer][op] = 0;
    }
}

void SNAND_dbg_check_GF_status(kal_uint8 status, kal_uint32 row_addr)
{
    #if defined(__MAUI_BASIC__) && !defined(__FUE__)
    if (status != 0)
    {
        #if defined(__UBL__)
        bl_print(LOG_INFO, "r:%d,b:%d,", row_addr, row_addr / 64);
        #else
        SNAND_dbg_print("r:%d,b:%d,", row_addr, row_addr / 64);
        #endif

        if (status & SNAND_STATUS_OIP)
        {
            #if defined(__UBL__)
            bl_print(LOG_INFO, "O,");
            #else
            SNAND_dbg_print("O,");
            #endif
        }
        if (status & SNAND_STATUS_WEL)
        {
            SNAND_dbg_print("W,");
        }
        if (status & SNAND_STATUS_ERASE_FAIL)
        {
            SNAND_dbg_print("EF,");
        }
        if (status & SNAND_STATUS_PROGRAM_FAIL)
        {
            SNAND_dbg_print("PF,");
        }
        if ((status & SNAND_STATUS_ECC_STATUS_MASK) == SNAND_STATUS_TOO_MANY_ERROR_BITS)
        {
            #if defined(__UBL__)
            bl_print(LOG_INFO, "ECC_U,");
            #else
            SNAND_dbg_print("ECC_U,");
            #endif
        }
        else if ((status & SNAND_STATUS_ECC_STATUS_MASK) == SNAND_STATUS_ERROR_BITS_CORRECTED)
        {
            #if defined(__UBL__)
            bl_print(LOG_INFO, "ECC_C,");
            #else
            SNAND_dbg_print("ECC_C,");
            #endif
        }
        else if ((status & SNAND_STATUS_ECC_STATUS_MASK) == SNAND_STATUS_ERROR_BITS_CORRECTED_FULL)
        {
            #if defined(__UBL__)
            bl_print(LOG_INFO, "ECC_8,");
            #else
            SNAND_dbg_print("ECC_8,");
            #endif
        }

        #if defined(__UBL__)
        bl_print(LOG_INFO, "\n\r");
        #else
        SNAND_dbg_print("\n\r");
        #endif
    }
    #endif
}

void SNAND_dbg_dev_cache_confirm(SNAND_P_U8 data)
{
    #if !defined(__UBL__)
    kal_uint32 len_left = 2048;
    kal_uint8 cmd;
    kal_uint32 col_addr, len_read;
    SNAND_P_U8      pGPRAM, pBuff;

    col_addr = 0;

    pBuff = (SNAND_P_U8)(&g_snand_dbg_buf2[0]);

    kal_mem_set((void *)pBuff, 0x55, 2048);

    while (len_left)
    {
        cmd = SNAND_GPRAM_Write_C1A3(SNAND_CMD_RANDOM_READ, (col_addr << 8)); // PAGE_READ command + 2-byte column address + 1-byte dummy byte

        SNAND_WriteReg32(RW_SNAND_GPRAM_DATA, cmd);
        SNAND_WriteReg32(RW_SNAND_MAC_OUTL, 1 + 3);             // 1+3: C1A3

        pGPRAM = ((SNAND_P_U8)RW_SNAND_GPRAM_DATA) + 1 + 3;     // 1+3: C1A3

        // get read length in one round
        if (len_left >= (SNAND_MAC_MAX_DATA_SIZE))
        {
            len_read = (SNAND_MAC_MAX_DATA_SIZE);
            len_left -= (SNAND_MAC_MAX_DATA_SIZE);
        }
        else
        {
            len_read = len_left;
            len_left = 0;
        }

        SNAND_WriteReg32(RW_SNAND_MAC_INL, len_read);

        // trigger SFI to read data from device to GPRAM
        SNAND_MacEnable(SNAND_SPI);
        SNAND_MacTrigger();
        SNAND_MacLeave();

        // copy data from GPRAM to external buffer
        for (cmd = 0; cmd < len_read; cmd++, pGPRAM++, pBuff++)
        {
            *pBuff = SNAND_ReadReg8(pGPRAM);
        }

        col_addr += len_read;
    }

    pBuff = (SNAND_P_U8)(&g_snand_dbg_buf2[0]);

    for (len_left = 0; len_left < 2048; len_left++)
    {
        if (data[len_left] != pBuff[len_left])
        {
            dbg_ASSERT(0);
        }
    }
    #endif
}


void SNAND_dbg_program_confirm(SNAND_P_U8 data, SNAND_P_U8 spare, kal_uint32 row_addr)
{
    #if !defined(__UBL__)
    SNAND_P_U8 pRead;
    SNAND_MTD_DRV_PARA drv_para;
    kal_uint32 i, j, status;

    if (SNAND_SPARE_FORMAT_MTK_1 == Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[7])
    {
        if (row_addr >= ((1020 - 1) * Flash_Info.blockPage))    // +1 FlashTool remark block
        {
            return;
        }
    }

    if ((spare[0] != 0xFF) || (0xFFFF != SNAND_COMMON_GetBadBlockMark(spare)))
    {
        return;
    }

    SNAND_Reset(SNAND_RST_CON);

    SNAND_Reset(SNAND_RST_DEV);	// avoid device giving us cache data programmed just now

    pRead = (SNAND_P_U8)(&g_snand_dbg_buf[0]);

    drv_para.page_size = Flash_Info.pageSize;
    drv_para.data_bytes = Flash_Info.pageSize;
    drv_para.spare_bytes = Flash_Info.spareSize;
    drv_para.row_addr = row_addr;
    drv_para.col_addr = 0;
    drv_para.data = (kal_uint8 *)pRead;
    drv_para.spare = (kal_uint8 *)(pRead + 2048);

    status = SNAND_COMMON_RawRead(&drv_para);

    // data
    for (i = 0; i < 2048; i++)
    {
        if (pRead[i] != data[i])
        {
            if (MTD_STATUS_NO_ERROR != status)
            {
                SNAND_dbg_print("[MTD INFO] Prog Confirm Failed(data), ReadRet:%x,Write[%d]:%x,Read[%d]:%x\n\r", status, i, data[i], i, pRead[i]);
            }
            else    // all error bits should be corrected
            {
                dbg_ASSERT(0);
            }
        }
    }

    // spare
    if (spare)
    {
        if (pRead[2048] != spare[0])   // compare vendor's bad block mark
        {
            if (MTD_STATUS_NO_ERROR != status)
            {
                SNAND_dbg_print("[MTD INFO] Prog Confirm Failed(bbmark), ReadRet:%x,Write[0]:%x,Read[2048]:%x\n\r", status, spare[i], pRead[2048]);
            }
            else    // all error bits should be corrected
            {
                dbg_ASSERT(0);
            }
        }

        if (SNAND_SPARE_FORMAT_MTK_1 == Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[7])
        {
            for (j = 0; j < 4; j++)
            {
                for (i = 4; i < 4 + 8; i++)    // compare FDM data (MTK_1 format)
                {
                    if (pRead[2048 + (j * 16) + i] != spare[(j * 16) + i])
                    {
                        if (MTD_STATUS_NO_ERROR != status)
                        {
                            SNAND_dbg_print("[MTD INFO] Prog Confirm Failed(spare), ReadRet:%x,Write[%d]:%x,Read[%d]:%x\n\r", status, (j * 16) + i, spare[(j * 16) + i], 2048 + (j * 16) + i, pRead[2048 + (j * 16) + i]);
                        }
                        else    // all error bits should be corrected
                        {
                            dbg_ASSERT(0);
                        }
                    }
                }
            }
        }
        else if (SNAND_SPARE_FORMAT_MTK_2 == Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[7])
        {
            for (j = 0; j < 4; j++)
            {
                for (i = 8; i < 8; i++)    // compare FDM data (MTK_2 format)
                {
                    if (pRead[2048 + (j * 16) + i] != spare[(j * 16) + i])
                    {
                        if (MTD_STATUS_NO_ERROR != status)
                        {
                            SNAND_dbg_print("[MTD INFO] Prog Confirm Failed(spare), ReadRet:%x,Write[%d]:%x,Read[%d]:%x\n\r", status, (j * 16) + i, spare[(j * 16) + i], 2048 + (j * 16) + i, pRead[2048 + (j * 16) + i]);
                        }
                        else    // all error bits should be corrected
                        {
                            dbg_ASSERT(0);
                        }
                    }
                }
            }
        }
    }

    SNAND_Reset(SNAND_RST_CON);
    #endif
}


#if defined(__SNAND_READ_DISTURBANCE_TEST__)

#define SNAND_RDT_OLD_PAGE_CNT              (45)
#define SNAND_RDT_PAGE_READ_CNT_LIMIT       (100000)

__align(32) kal_uint8   g_snand_rd_buf[64][2048 + 64];
kal_uint32              g_snand_rd_read_cnt[64] = {0};
kal_uint32              g_snand_rd_old_page_list[SNAND_RDT_OLD_PAGE_CNT];

kal_uint32 snand_rbt_if_old_page(kal_uint32 page)
{
    kal_uint32 i;

    for (i = 0; i < SNAND_RDT_OLD_PAGE_CNT; i++)
    {
        if (page == g_snand_rd_old_page_list[i])
        {
            return 1;
        }
    }

    return 0;
}


kal_uint32 snand_rbt_memcmp(kal_uint8 * src, kal_uint8 * des, kal_uint32 len)
{
    kal_uint32 i;

    for (i = 0; i < len; i++)
    {
        if (src[i] != des[i])
        {
            SNAND_dbg_print("[HQA] snand_read_disturbance_test memcmp failed, src[%d]:%x, dst[%d]:%x\n\r", i, src[i], i, des[i]);
            //while(1);
            return 1;
        }
    }
    return 0;
}

void snand_read_disturbance_test(kal_uint32 pattern_option)
{
    kal_uint32 block = 70;
    kal_uint8 * p_data_read;
    kal_uint8 * p_data_written;
    kal_uint32 i, j, k, ret, read_cycles;
    mtd_if_para para;
    kal_uint8 err = 0;

    SNAND_dbg_print("[HQA] snand_read_disturbance_test (pattern: %d), block: %d\n\r", pattern_option, block);

    kal_mem_set(g_snand_rd_buf, 0x00, 64 * 2112);

_snand_read_disturbance_test_start:

    // choose a good block
    for (i = block;; i++)
    {
        read_cycles = SNAND_COMMON_BlockErase(i * Flash_Info.blockPage);

        if (MTD_STATUS_NO_ERROR == read_cycles)
        {
            block = i;
            break;
        }
    }

    SNAND_dbg_print("[HQA] snand_read_disturbance_test - generating patterns\n\r");

    if (0 == pattern_option)    // random pattern
    {
        // generate patterns
        for (i = 0; i < 64; i++)
        {
          /*
                 * Important!! leave the page 0 all 0x0!!
                 *
                 * Some NAND cell will have symtom like,
                 * Reading a page with many 0x00 will disturb the next page. (Case found: MTK_INTERNAL_SPI_NAND_1)
                 */
            for (j = 0; j < 2048; j++)
            {
                if(0 == i)
        		{
        			g_snand_rd_buf[i][j] = 0x00;
        		}
        		else
        		{
                    g_snand_rd_buf[i][j] = (kal_uint8)rand();
                }
            }

            for (j = 2048; j < (2048 + 64); j++)
            {
              	g_snand_rd_buf[i][j] = 0xFF;
            }
        }
    }
    else if (1 == pattern_option)   // sequential pattern
    {
        for (i = 0; i < 64; i++)
        {
           /*
                 * Important!! leave the page 0 all 0x0!!
                 *
                 * Some NAND cell will have symtom like,
                 * Reading a page with many 0x00 will disturb the next page. (Case found: MTK_INTERNAL_SPI_NAND_1)
                 */

            for (j = 0; j < 2048; j++)
            {
        		if(0 == i)
        		{
        			g_snand_rd_buf[i][j] = 0x00;
        		}
        		else
        		{
            	    g_snand_rd_buf[i][j] = i + j;
                }
            }

            for (j = 2048; j < (2048 + 64); j++)
            {
              	g_snand_rd_buf[i][j] = 0xFF;
            }
        }
    }
    else    // import data pattern from fixed location (e.g., imported by ICE)
    {
        p_data_read = (kal_uint8 *)(0x60000);

        for (i = 0; i < 64; i++)
        {
            for (j = 0; j < 2048; j++)
            {
                g_snand_rd_buf[i][j] = *p_data_read++;
            }
        }
    }

    SNAND_dbg_print("[HQA] snand_read_disturbance_test - programing patterns\n\r");

    // write pattern to device
    for (i = 0; i < 64; i++)
    {
        p_data_written = (kal_uint8 *)(&(g_snand_rd_buf[i][0]));

        para.buff = p_data_written;
        para.spare = p_data_written + 2048;
        para.ce = 0;
        para.length = 1;
        para.m_idx = 0;
        para.opFlag = 0;
        para.pageIdx[0] = (block * Flash_Info.blockPage) + i;

        ret = MTD_Program(&para);

        if (MTD_STATUS_NO_ERROR != ret)
        {
            block++;
            goto _snand_read_disturbance_test_start;
        }

        // program confirm

        p_data_read = (SNAND_P_U8)(&g_snand_dbg_buf[0]);

        para.buff = p_data_read;
        para.spare = NULL;
        para.ce = 0;
        para.length = 1;
        para.m_idx = 0;
        para.opFlag = 0;
        para.pageIdx[0] = (block * Flash_Info.blockPage) + i;

        g_snand_rd_read_cnt[i]++;

        MTD_Read(&para);

        snand_rbt_memcmp((kal_uint8 *)(&(g_snand_rd_buf[i][0])), (kal_uint8 *)(&g_snand_dbg_buf[0]), 2048);
    }

    SNAND_dbg_print("[HQA] snand_read_disturbance_test - testing phase 1\n\r");

    // make some pages old

    // 1. make old page list
    for (i = 0; i < SNAND_RDT_OLD_PAGE_CNT; i++)
    {
        g_snand_rd_old_page_list[i] = i;
    }

    // 2. make those pages old
    for (i = 0; i < SNAND_RDT_OLD_PAGE_CNT; i++)
    {
        for (j = 0; j < SNAND_RDT_PAGE_READ_CNT_LIMIT - 1; j++)
        {
            p_data_read = (SNAND_P_U8)(&g_snand_dbg_buf[0]);

            para.buff = p_data_read;
            para.spare = NULL;
            para.ce = 0;
            para.length = 1;
            para.m_idx = 0;
            para.opFlag = 0;
            para.pageIdx[0] = (block * Flash_Info.blockPage) + g_snand_rd_old_page_list[i];

            if (SNAND_RDT_PAGE_READ_CNT_LIMIT > g_snand_rd_read_cnt[g_snand_rd_old_page_list[i]])
            {
                g_snand_rd_read_cnt[g_snand_rd_old_page_list[i]]++;

                MTD_Read(&para);

                snand_rbt_memcmp((kal_uint8 *)(&g_snand_rd_buf[g_snand_rd_old_page_list[i]][0]), (kal_uint8 *)(&g_snand_dbg_buf[0]), 2048);
            }

            // randomly read other page and compare its contents

/*
                k = rand() % 64;

                if (0 == snand_rbt_if_old_page(k)) // only read non-old page
                {
                    p_data_read = (SNAND_P_U8)(&g_snand_dbg_buf[0]);

                    para.buff = p_data_read;
                    para.spare = NULL;
                    para.ce = 0;
                    para.length = 1;
                    para.m_idx = 0;
                    para.opFlag = 0;
                    para.pageIdx[0] = (block * Flash_Info.blockPage) + k;

                    g_snand_rd_read_cnt[k]++;

                    MTD_Read(&para);

                    snand_rbt_memcmp((kal_uint8 *)(&g_snand_rd_buf[k][0]), (kal_uint8 *)(&g_snand_dbg_buf[0]), 2048);
                }
*/
            if ((j % 100) == 0)
            {
            	k = 1;

                if (SNAND_RDT_PAGE_READ_CNT_LIMIT > g_snand_rd_read_cnt[k])
                {
                	SNAND_dbg_print("Read Page %d @ j=%d loop\r\n",k,j);
                    p_data_read = (SNAND_P_U8)(&g_snand_dbg_buf[0]);

                    para.buff = p_data_read;
                    para.spare = NULL;
                    para.ce = 0;
                    para.length = 1;
                    para.m_idx = 0;
                    para.opFlag = 0;
                    para.pageIdx[0] = (block * Flash_Info.blockPage) + k;

                    g_snand_rd_read_cnt[k]++;

                    MTD_Read(&para);

                    if (snand_rbt_memcmp((kal_uint8 *)(&g_snand_rd_buf[k][0]), (kal_uint8 *)(&g_snand_dbg_buf[0]), 2048) != 0)
                    {
                    	SNAND_dbg_print("DataCompare Error at Page:%d\r\n",k);

                    	err = 1;

                    	for(k = 0; k < 64; k++)
                    	{
			                p_data_read = (SNAND_P_U8)(&g_snand_dbg_buf[0]);

			                para.buff = p_data_read;
			                para.spare = NULL;
			                para.ce = 0;
			                para.length = 1;
			                para.m_idx = 0;
			                para.opFlag = 0;
			                para.pageIdx[0] = (block * Flash_Info.blockPage) + k;

			                g_snand_rd_read_cnt[k]++;

			                MTD_Read(&para);

			                if(snand_rbt_memcmp((kal_uint8 *)(&g_snand_rd_buf[k][0]), (kal_uint8 *)(&g_snand_dbg_buf[0]), 2048)!=0)
                			{
                				SNAND_dbg_print("NG at page:%d... \r\n",k);
                			}
                    	}
                    }
                }
            }

            if (1 == err)
            {
               goto snand_read_disturbance_test_error;
            }
        }

        SNAND_dbg_print("[HQA] snand_read_disturbance_test - page %d done\n\r", g_snand_rd_old_page_list[i]);
    }

    // 3. randomly read other page and compare its contents

    SNAND_dbg_print("[HQA] snand_read_disturbance_test - testing phase 2\n\r");

    for (i = 0; i < 200000; i++)
    {
        k = rand() % 64;

        if (0 == snand_rbt_if_old_page(k)) // only read non-old page
        {
            if (SNAND_RDT_PAGE_READ_CNT_LIMIT > g_snand_rd_read_cnt[k])
            {
                p_data_read = (SNAND_P_U8)(&g_snand_dbg_buf[0]);

                para.buff = p_data_read;
                para.spare = NULL;
                para.ce = 0;
                para.length = 1;
                para.m_idx = 0;
                para.opFlag = 0;
                para.pageIdx[0] = (block * Flash_Info.blockPage) + k;

                g_snand_rd_read_cnt[k]++;

                MTD_Read(&para);

                snand_rbt_memcmp((kal_uint8 *)(&g_snand_rd_buf[k][0]), (kal_uint8 *)(&g_snand_dbg_buf[0]), 2048);
            }
        }
    }

    SNAND_dbg_print("[HQA] snand_read_disturbance_test passed\n\r");

    goto snand_read_disturbance_test_exit;

snand_read_disturbance_test_error:

    SNAND_dbg_print("[HQA] snand_read_disturbance_test failed\n\r");

    while (1);

snand_read_disturbance_test_exit:

    return;

}

#else

void snand_read_disturbance_test(kal_uint32 pattern_option)
{
    SNAND_dbg_print("[HQA] snand_read_disturbance_test is disabled.\n\r");

    while (1);
}

#endif // __SNAND_READ_DISTURBANCE_TEST__

#endif // __SNAND_DEBUG__

#endif /*( defined(__NAND_FDM_50__) && defined(__SPI_NAND_SUPPORT__) )*/
