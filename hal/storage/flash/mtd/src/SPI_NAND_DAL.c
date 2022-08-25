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
 *  SPI_NAND_DAL.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is a SPI-NAND Flash Device Abstraction Layer file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined(__NAND_FDM_50__) && defined(__SPI_NAND_SUPPORT__)

/*-----------------------------------------------------
 * Included Header Files
 *-----------------------------------------------------*/

#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
    // PC simulator
#else
#include "kal_public_api.h"
#include "page.h"
#include "flash_opt.h"
#endif
#include "custom_SNAND.h"
#include "SPI_NAND_MTD_FDM50_internal.h"
#include "NAND_DAL.h"
#include "NAND_DAL_internal.h"
#include "NAND_DAL_Version.h"
#include "system_trc.h"
#include "fs_errcode.h"
#include "fota_error.h"
#include "fs_type.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include "kal_trace.h"
#if defined(__SNAND_THIRD_ROM_RECHARGE__)
#include "bl_BootInfo.h"
#include "bl_FOTA.h"
#include "bl_loader.h"  // for bl_FOTA.h
#endif  // __SNAND_THIRD_ROM_RECHARGE__

/*-----------------------------------------------------
 * Local Definitions
 *-----------------------------------------------------*/

#ifdef FLASH_DISKDRV_DEBUG
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
    //#define pdn_nfi(expr) do { } while (0);
#endif

#if defined(__SMART_MD_NFI_DRIVER__)    // Smart phone start alone driver
	#ifndef _NAND_FLASH_BOOTING_
		#define _NAND_FLASH_BOOTING_
	#endif
#endif

/*-----------------------------------------------------
 * Local Variable Declarations
 *-----------------------------------------------------*/

#if defined (__NAND_LMT__)
extern const kal_bool bWholeImage;
#endif // defined (__NAND_LMT__)

static struct_map_cache MapCache[MAX_MULTIPAGE_NUM][2] = {0};
static kal_uint8 MapCacheCount[MAX_MULTIPAGE_NUM]={0};

const kal_uint8 ZEROBIT[256] ={
8, 7, 7, 6, 7, 6, 6, 5, 7, 6, 6, 5, 6, 5, 5, 4,
7, 6, 6, 5, 6, 5, 5, 4, 6, 5, 5, 4, 5, 4, 4, 3,
7, 6, 6, 5, 6, 5, 5, 4, 6, 5, 5, 4, 5, 4, 4, 3,
6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2,
7, 6, 6, 5, 6, 5, 5, 4, 6, 5, 5, 4, 5, 4, 4, 3,
6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2,
6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2,
5, 4, 4, 3, 4, 3, 3, 2, 4, 3, 3, 2, 3, 2, 2, 1,
7, 6, 6, 5, 6, 5, 5, 4, 6, 5, 5, 4, 5, 4, 4, 3,
6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2,
6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2,
5, 4, 4, 3, 4, 3, 3, 2, 4, 3, 3, 2, 3, 2, 2, 1,
6, 5, 5, 4, 5, 4, 4, 3, 5, 4, 4, 3, 4, 3, 3, 2,
5, 4, 4, 3, 4, 3, 3, 2, 4, 3, 3, 2, 3, 2, 2, 1,
5, 4, 4, 3, 4, 3, 3, 2, 4, 3, 3, 2, 3, 2, 2, 1,
4, 3, 3, 2, 3, 2, 2, 1, 3, 2, 2, 1, 2, 1, 1, 0};

static kal_uint32 DAL_spare_buff[64/4]; /*DAL buff (for Copy)*/
char NAND_text_buff[100]; /*For debug message*/

kal_bool DAL_is_initialized = KAL_FALSE;
kal_uint8 CurDiskIndex = 0;
flash_info_2 Flash_Info;
add_convert Add_Cnvt;
extern mtd_if_para Mtd_para;

#if defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(__SPI_NAND_SUPPORT__))
kal_bool DemandPageingRead = KAL_FALSE;
static kal_uint16 DAL_Bank_Array[MAX_MULTIPAGE_NUM]; /*For DAL_fdmxx function*/
static kal_uint16 DAL_Bank_Array2[MAX_MULTIPAGE_NUM]; /*For DAL_fdmCopy function*/
#if !defined(__NANDFDM_MULTI_INSTANCE__)
static kal_uint32 FAT_Start_ZoneNum = DWORD_INVALID;
static kal_uint32 FAT_Start_Section_Offset = DWORD_INVALID;
#else  // !defined(__NANDFDM_MULTI_INSTANCE__)
static kal_uint32 FAT_Start_ZoneNum[NAND_DISK_NUM];
static kal_uint32 FAT_Start_Section_Offset[NAND_DISK_NUM];
#endif  //  !defined(__NANDFDM_MULTI_INSTANCE__)
#if !defined(__NANDFDM_MULTI_INSTANCE__)

extern const kal_uint32 NFB_BASE_ADDRESS;

extern const kal_uint32 NFB_ALLOCATED_FAT_SPACE;

#else  // !defined(__NANDFDM_MULTI_INSTANCE__)

extern kal_uint32 NFB_BASE_ADDRESS[NAND_DISK_NUM];
extern kal_uint32 NFB_ALLOCATED_FAT_SPACE[NAND_DISK_NUM];
extern const kal_uint8 NANDDiskNum;

#endif  //  !defined(__NANDFDM_MULTI_INSTANCE__)

extern kal_bool use_interrupt;  // KAL_TRUE for using interrupt; KAL_FALSE for using polling

#endif /* _NAND_FLASH_BOOTING_ || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && __SPI_NAND_SUPPORT__) */

#if defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__)||defined(__SECURITY_OTP__) && defined(__SPI_NAND_SUPPORT__))
#if defined(__NFI_VERSION3_1__)
#define _DAL_MAX_PAGE_SIZE_          4096
#define _DAL_MAX_SPARE_SIZE_         128
#else
#define _DAL_MAX_PAGE_SIZE_          2048
#define _DAL_MAX_SPARE_SIZE_         64
#endif
static kal_uint32 NFB_tmp_D_Buff[_DAL_MAX_PAGE_SIZE_/4];
static kal_uint32 NFB_tmp_S_Buff[_DAL_MAX_SPARE_SIZE_/4];
#endif
/*
 ****** Definition of dbg_ASSERT and force_ASSERT ******
 dbg_ASSERT:
          - For basic load prevalidation use. The code is used for RD debug.
 Force_ASSERT:
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

#if defined(__AUDIO_DSP_LOWPOWER__)
NFI_Config_for_MP3_st NFI_ConfigforMP3;
#endif //#if defined(__AUDIO_DSP_LOWPOWER__)

#define devicePage(ceIdx) (Flash_Info.devicePage[ceIdx]) /*page number of the device*/
#define zonePage(ceIdx) (devicePage(ceIdx)/Flash_Info.zone_CE[ceIdx]) /*page number of the zone*/
#define diePage(ceIdx) (Flash_Info.diePage[ceIdx]) /*page number of the die*/
#define planePage(ceIdx) (Flash_Info.planePage[ceIdx]) /*page number of plane*/
#define devDriver(ceIdx) (Flash_Info.deviceInfo_CE[ceIdx].driverSet)

//#define DAL_VERIFICATION
//#define DAL_DEBUG_TEXT

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__) )
	// Basic load in MAUI
	kal_uint32 D_Buff[_DAL_MAX_PAGE_SIZE_/4*8 + 8];


	#if defined(__MTK_TARGET__)
	__attribute__((zero_init, section("NONCACHEDZI"))) kal_uint32 D_Buff_NC[_DAL_MAX_PAGE_SIZE_/4*8 + 8];
	#else
	kal_uint32 D_Buff_NC[_DAL_MAX_PAGE_SIZE_/4*8 + 8];
	#endif

	kal_uint32 S_Buff[512/4*8];
	kal_uint8 Mtd_Fail_Offset = 0xFF;
	kal_uint8 Fail_Bank = 0xFF;

#else // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__) )
	// Basic load in bootloader
	// MAUI load
	#if ( defined(__EMULATE_NFB_BIT_ERROE__) )
	kal_uint32 D_Buff[_DAL_MAX_PAGE_SIZE_/4*2 + 8];
	kal_uint32 S_Buff[_DAL_MAX_SPARE_SIZE_/4*2];
	#endif //( defined(__EMULATE_NFB_BIT_ERROE__) )

#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__) )

#if defined(__SNAND_THIRD_ROM_RECHARGE__) && (defined(_NAND_FLASH_BOOTING_) || (defined(__UP_PKG_ON_NAND__) && defined(__SPI_NAND_SUPPORT__)))

extern BL_Info_Wrapper_st g_pass_info;
kal_uint8   g_snand_trr_initialized = 0;
kal_uint8   g_snand_trr_enabled = 0;
kal_uint8   g_snand_trr_map_status = 0; // 0: no map in Log Block, 1: corrupted map, 2: valid map
kal_uint8   g_snand_trr_map_changed = 0;
kal_uint32  g_snand_trr_rom1_block_begin;
kal_uint32  g_snand_trr_rom2_block_begin;
kal_uint32  g_snand_trr_rom1_map_block;
kal_uint32  g_snand_trr_rom2_map_block;
kal_uint32  g_snand_trr_rom1_res_block_begin;
kal_uint32  g_snand_trr_rom1_res_block_end; // g_snand_trr_rom1_block_end
kal_int32   g_snand_trr_log_block = -1;
kal_int32   g_snand_trr_target_block = -1;
kal_int32   g_snand_trr_target_block_original = -1;
kal_int32   g_snand_trr_source_block = -1;
kal_uint32  g_snand_trr_seq_num = 0;
kal_int32   g_snand_temp_val;

#define     SNAND_MARK_CODE_BLOCK_LEN                                               (2)
kal_uint8   g_snand_mark_CODE_BLOCK[SNAND_MARK_CODE_BLOCK_LEN + 1]                  = {"TC"};   // Third rom Code

#define     SNAND_MARK_LOG_BLOGK_LEN                                                (11)
#define     SNAND_MARK_LOG_BLOCK_PAGE_OFFSET                                        (0)
kal_uint8   g_snand_mark_LOG_BLOCK[SNAND_MARK_LOG_BLOGK_LEN + 1]                    = {"0 LOG BLOCK"};

#define     SNAND_MARK_ERASE_TARGET_BLOCK_LEN                                       (20)
#define     SNAND_MARK_ERASE_TARGET_BLOCK_PAGE_OFFSET                               (1)
kal_uint8   g_snand_mark_ERASE_TARGET_BLOCK[SNAND_MARK_ERASE_TARGET_BLOCK_LEN + 1]  = {"1 ERASE TARGET BLOCK"};

#define     SNAND_MARK_RECHARGE_BEGIN_LEN                                           (16)
#define     SNAND_MARK_RECHARGE_BEGIN_PAGE_OFFSET                                   (2)
kal_uint8   g_snand_mark_RECHARGE_BEGIN[SNAND_MARK_RECHARGE_BEGIN_LEN + 1]          = {"2 RECHARGE BEGIN"};

#define     SNAND_MARK_RECHARGE_END_LEN                                             (14)
#define     SNAND_MARK_RECHARGE_END_PAGE_OFFSET                                     (3)
kal_uint8   g_snand_mark_RECHARGE_END[SNAND_MARK_RECHARGE_BEGIN_LEN + 1]            = {"3 RECHARGE END"};

#define     SNAND_MARK_MAX_PAGE_OFFSET                                              (SNAND_MARK_RECHARGE_END_PAGE_OFFSET)

#if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
#include    "wdt_hw.h"
#include    "wdt_sw.h"
#include    "in_defs.h"
#include    "dcl.h"

#define Cur_qbit (*(volatile kal_uint16 *)(TDMA_base + 0x00))
#define qwrap (*(volatile kal_uint16 *)(TDMA_base + 0x04))
#define dalay(us)  {\
    ASSERT(us<5000);\
    tqcnt1 = Cur_qbit;\
    while (1)\
    {        \
        tqcnt2 = Cur_qbit;\
        if (us < ( (tqcnt2 >= tqcnt1)? tqcnt2 - tqcnt1:(qwrap - tqcnt1) + tqcnt2 ) ) break;\
    }\
}

extern int  INC_Initialize_State;
kal_bool    g_snand_trr_reset_in_next_busy   = KAL_FALSE;    // flag for MTD to decide if reset is required
kal_bool    g_snand_trr_wdt_triggered        = KAL_FALSE;    // flag for MTD to decide if reset is required
kal_bool    g_snand_trr_bootup_time_recorded = KAL_FALSE;
kal_uint8   g_snand_trr_reset_position       = 0;            // where should we reset?
RTC_CTRL_GET_TIME_T     g_snand_trr_rtc_time;

void        snand_trr_test_wdt_reset(void);
void        snand_trr_test_get_rtc_time(DCL_CTRL_DATA_T * rtctime);
#endif  // __SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__

#endif  // __SNAND_THIRD_ROM_RECHARGE__ && (_NAND_FLASH_BOOTING_ || (__UP_PKG_ON_NAND__ && __SPI_NAND_SUPPORT__))

/*-----------------------------------------------------
 * API Declarations
 *-----------------------------------------------------*/

#if !defined(__FUE__)

extern void get_MTD_lock(void);
extern void free_MTD_lock(void);

#else /* __FUE__ */

#define init_MTD_lock()

#define get_MTD_lock()

#define free_MTD_lock()

#endif

/*-----------------------------------------------------
 * API Bodies
 *-----------------------------------------------------*/

#if ( defined(ECC_BIT_ERROR_TEST) || defined(__EMULATE_NFB_BIT_ERROE__) )

kal_bool ECCDisable = KAL_FALSE;

kal_uint32 EmulateBitError(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank, kal_uint16 PageAddr, kal_uint8 SectorNumPerPage, kal_uint32 *Data, kal_uint32 *Spare)
{

	kal_uint32 retVal, SectorNum, BitOffset, Offset;
    kal_bool Empty;

    retVal = DAL_ReadPage(Acc_Type, ZoneNo, Bank, PageAddr, 1, ((kal_uint8*)&Data[_DAL_MAX_PAGE_SIZE_/4])+4, (Acc_Type==CODE_ACC) ? NULL : (kal_uint8*)&Spare[_DAL_MAX_SPARE_SIZE_/4]) & 0xffff0000;
    if ( retVal != MTD_STATUS_NO_ERROR ) {
    	return retVal;
    }

    DAL_ReadPage(Acc_Type, ZoneNo, Bank, PageAddr, 1, (kal_uint8*)Data, (kal_uint8*)Spare);

    Empty = KAL_TRUE;
	for (Offset=0; Offset<SectorNumPerPage*0x10/4; Offset++) {
		if (Spare[Offset] != 0xffffffff) {
			Empty = KAL_FALSE;
			break;
		}
	}

    if (Empty==KAL_TRUE) {
    	return MTD_STATUS_ERROR;  // Return this to bypass this page.
    }

	for (SectorNum=0; SectorNum<SectorNumPerPage; SectorNum++) {
		if (1) {
    		for (Offset=(SectorNum*0x200)*8; Offset<(SectorNum*0x200+256)*8; Offset++) {
    			BitOffset = Offset & 0x07;
   				if (((kal_uint8*)Data)[Offset>>3] & (0x01 << BitOffset)) {
   					((kal_uint8*)Data)[Offset>>3] &= ~((0x01 << BitOffset));
   					break;
   				}
    		}
    		for (Offset=(SectorNum*0x200+511)*8; Offset>=(SectorNum*0x200+256)*8; Offset--) {
    			BitOffset = Offset & 0x07;
   				if (((kal_uint8*)Data)[Offset>>3] & (0x01 << BitOffset)) {
   					((kal_uint8*)Data)[Offset>>3] &= ~((0x01 << BitOffset));
   					break;
   				}
    		}
    		for (Offset=(SectorNum*0x10+(PageAddr&0x07))*8; Offset<(SectorNum*0x10+0x8)*8; Offset++) {
    			BitOffset = Offset & 0x07;
   				if (((kal_uint8*)Spare)[Offset>>3] & (0x01 << BitOffset)) {
   					((kal_uint8*)Spare)[Offset>>3] &= ~((0x01 << BitOffset));
   					break;
   				}
    		}
		}  else {
			// Here NFI will not return error when ECC code error. So Do the following two times may cause ECC failure.
			// ECC code error
			kal_uint32 StartAddr, EndAddr;

			if (Acc_Type==CODE_ACC) {
				StartAddr = (SectorNum*0x10+0x08+(rand() % 6))*8;
				EndAddr = (SectorNum*0x10+0x0e)*8;
			} else {
				StartAddr = (SectorNum*0x10+0x08+(PageAddr&0x07))*8;
				EndAddr = (SectorNum*0x10+0x10)*8;
			}
    		for (Offset=StartAddr; Offset<EndAddr; Offset++) {
    			BitOffset = Offset & 0x07;
   				if (((kal_uint8*)Spare)[Offset>>3] & (0x01 << BitOffset)) {
   					((kal_uint8*)Spare)[Offset>>3] &= ~((0x01 << BitOffset));
   					break;
   				}
    		}
		}
	}
	ECCDisable = KAL_TRUE;
	retVal = DAL_ProgramPage(Acc_Type, ZoneNo, Bank, PageAddr, 1, (kal_uint8*)Data, (kal_uint8*)Spare);
	ECCDisable = KAL_FALSE;

	return MTD_STATUS_NO_ERROR;
}

#endif // #if ( defined(ECC_BIT_ERROR_TEST) || defined(__EMULATE_NFB_BIT_ERROE__) )

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )

extern int rand(void);

typedef struct
{
    kal_uint8 ce;
    kal_uint8 die;
    kal_uint8 plane;
} phyAdd_struct;


#if ( !defined(__UBL__) )

void getPhyAdd_info (kal_uint8 ce_idx, kal_uint32 pageAdd, phyAdd_struct *p)
{
    kal_uint32 d_page;
    kal_uint16 blk_num;

    p->ce = ce_idx;

    d_page = ( (Flash_Info.deviceInfo_CE[ce_idx].supportMPType & EXTENDED_BLOCK) == EXTENDED_BLOCK) ? (diePage(ce_idx)/1024*(1024+16)) : diePage(ce_idx);
    p->die = pageAdd/d_page;

    blk_num = ( (pageAdd - p->die*d_page)/Flash_Info.blockPage ); /*the block number in the die*/
    d_page = (pageAdd - p->die*d_page); /*now d_page is the page offset in tearget die*/
    if ( (Flash_Info.deviceInfo_CE[ce_idx].supportMPType&(TWO_PLANE_OP|PLANE_INTERLACED)) == (TWO_PLANE_OP|PLANE_INTERLACED) )
    {
        p->plane = blk_num %2;
    }
    else if ( (Flash_Info.deviceInfo_CE[ce_idx].supportMPType&(FOUR_PLANE_OP|PLANE_INTERLACED)) == (FOUR_PLANE_OP|PLANE_INTERLACED) )
    {
        p->plane = blk_num %4;
    }
    else /*PLANE_CONTINUOUS */
    {
        if (d_page < planePage(ce_idx))
        {
            p->plane = d_page/planePage(ce_idx);
        }
        else if ( (Flash_Info.deviceInfo_CE[ce_idx].supportMPType&(TWO_PLANE_OP|PLANE_CONTINUOUS)) == (TWO_PLANE_OP|PLANE_CONTINUOUS) &&
             d_page < planePage(ce_idx)*2)
        {
            p->plane = d_page/planePage(ce_idx);
        }
        else if ( (Flash_Info.deviceInfo_CE[ce_idx].supportMPType&(FOUR_PLANE_OP|PLANE_CONTINUOUS)) == (FOUR_PLANE_OP|PLANE_CONTINUOUS) &&
                  d_page < planePage(ce_idx)*4 )
        {
            p->plane = d_page/planePage(ce_idx);
        }
        else
        {   /*only EXTENDED_BLOCK is possible to run here*/
            dbg_ASSERT(Flash_Info.deviceInfo_CE[ce_idx].supportMPType&EXTENDED_BLOCK);
            d_page -= diePage(ce_idx); /* - regular block area*/
            p->plane = d_page / (planePage(ce_idx) / 1024 * 16) ;
        }
    }
}

#if defined(ECC_BIT_ERROR_TEST)
void DAL_ECCTest(kal_bool Init)
{
    kal_uint32 i, j, k, l;
    kal_uint32 retVal, Offset;
    kal_uint16 b_arr[8];
    FLASH_INFO F_info;
    kal_uint8 *BufPtr = NULL;

	if (Init==KAL_TRUE) {
	    DAL_init();
	}
   	DAL_FDM_Flash_Info_Init (&F_info, 0);


    nandlog_print("ECC test start.\r\n");
    for (i=0;i< F_info.TotalZoneNum; i++)
    {
        for (j=0; j<F_info.PSectionNumInZone[i]; j++ )
        {
        	if ( (j & 0x7f)==0 ) {
	            nandlog_print("ECC already passed zone %xh, section %xh.\r\n",i,j);

        	}
            for (k=0; k<F_info.BankNumber; k++)
            {
                b_arr[k] = j;
                if ( (retVal = DAL_CheckBadBlock(FAT_ACC, i, b_arr, k, KAL_FALSE, D_Buff, S_Buff)) ==  MTD_STATUS_NO_ERROR)
                {
                    for (l=0;l<F_info.PageNumPerSection; l+=F_info.BankNumber)
                    {
                    	retVal = EmulateBitError(FAT_ACC, i, b_arr, k+l, F_info.SectorNumPerPage, D_Buff, S_Buff);
                        if ( retVal == MTD_STATUS_NO_ERROR )
                        {
                        	BufPtr = NULL;
						    kal_mem_set(D_Buff, 0xFF, _DAL_MAX_PAGE_SIZE_+4);
						    kal_mem_set(S_Buff, 0xFF, _DAL_MAX_SPARE_SIZE_);

						DAL_ECC_TEST:

							if (BufPtr==NULL)
							{
								BufPtr = (kal_uint8 *)D_Buff;
							}
							else
							{
								BufPtr = (kal_uint8 *)D_Buff_NC;
							}

	                        retVal = DAL_ReadPage(FAT_ACC, i, b_arr, k+l, 1, (kal_uint8*)(BufPtr+(l%4)), (kal_uint8*)S_Buff) & 0xffff0000;
	                        if ( retVal == MTD_STATUS_ERROR ) {
	                        	nandlog_print("[Error]DAL_ReadPage return MTD_STATUS_ERROR.\r\n");
	                            dbg_ASSERT(0);
	                        }
							if ( kal_mem_cmp((BufPtr+(l%4)), ((kal_uint8*)&D_Buff[_DAL_MAX_PAGE_SIZE_/4])+4, F_info.SectorNumPerPage*0x200 ) )  {
	                        	nandlog_print("[Error] Main buffer comparison failure.\r\n");
	                            dbg_ASSERT(0);
							}

		                    #if defined(__NFI_VERSION3_1__)

							for (Offset=0; Offset<F_info.SectorNumPerPage*0x10/4; Offset+=(0x10/4)) {
			                    if ( (DAL_GetFDMData(FDMDATA_LBA, &(S_Buff[Offset]))!= DAL_GetFDMData(FDMDATA_LBA, &(S_Buff[_DAL_MAX_SPARE_SIZE_/4 + Offset]))) ||
			                    	 (DAL_GetFDMData(FDMDATA_BM, &(S_Buff[Offset])) != DAL_GetFDMData(FDMDATA_BM, &(S_Buff[_DAL_MAX_SPARE_SIZE_/4 + Offset])))) {
		                        	nandlog_print("FDM data comparison failure.\r\n");
			                        dbg_ASSERT(0);
			                    }
							}

							#else // defined(__NFI_VERSION3_1__)

							for (Offset=0; Offset<F_info.SectorNumPerPage*0x10/4; Offset+=(0x10/4)) {
								if ( (S_Buff[Offset]!=S_Buff[_DAL_MAX_SPARE_SIZE_/4+Offset]) ||
									 (S_Buff[Offset+1]!=S_Buff[_DAL_MAX_SPARE_SIZE_/4+Offset+1]) ) {
		                        	nandlog_print("[Error] FDM data comparison failure.\r\n");
		                            dbg_ASSERT(0);
								}
							}

							#endif // defined(__NFI_VERSION3_1__)

							if (BufPtr == (kal_uint8 *)D_Buff)
							{
								goto DAL_ECC_TEST;
							}
                        }
                    }
                }
                else
                {
#ifdef DAL_DEBUG_TEXT
                    nandlog_print("Bad block(0x%X) at (Z,BIdx,Block) = (%d,%d,%d)\r\n",retVal,i,k,j);

#endif // DAL_DEBUG_TEXT
                }
            }
        }
    }
    nandlog_print("-> ECC error test pass\r\n ");
	if (Init==KAL_TRUE) {
	    DAL_ShutDown();
	}
}
#endif // ECC_BIT_ERROR_TEST

void DAL_Test (void)
{
    kal_uint32 i,j,k,l;
    static kal_uint32 count = 0;
    kal_uint32 retVal;
    kal_uint16 b_arr[8];
    FLASH_INFO F_info;
    kal_uint8 *BufPtr = NULL;

    DAL_init();
    DAL_FDM_Flash_Info_Init (&F_info, 0);

    nandlog_print("Count:%d -- TotalZoneNum:%d,BankNumber:%d\r\n",count, F_info.TotalZoneNum,F_info.BankNumber);

    count++;
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

    #if 1

DAL_TEST_START:

	if (BufPtr==NULL)
	{
		BufPtr = (kal_uint8 *)D_Buff;
	}
	else
	{
		BufPtr = (kal_uint8 *)D_Buff_NC;
	}

    nandlog_print("-> Erase Test... \r\n");
    /*Erase all*/
    for (i=0;i< F_info.TotalZoneNum; i++)
    {
        for (j=0; j<F_info.PSectionNumInZone[i]; j++ )
        {
        	if ( (j & 0x7f)==0 ) {
	            nandlog_print("Erase test already passed zone %xh, section %xh.\r\n",i,j);

        	}

            for (k=0;k< F_info.BankNumber; k++)
            {
                b_arr[k] = j;
                if ( (retVal = DAL_CheckBadBlock(FAT_ACC, i, b_arr, k,KAL_FALSE,D_Buff, S_Buff)) ==  MTD_STATUS_NO_ERROR)
                {
                    if ((DAL_EraseBlock(FAT_ACC, i,b_arr, k, 1) & 0xffff)==MTD_STATUS_ERROR) {
                    	goto BAD_BLOCK;
                    }
                    retVal = DAL_ReadPage(FAT_ACC, i,b_arr,k,1,(kal_uint8*)BufPtr,(kal_uint8*)S_Buff );
                    if ( retVal != MTD_STATUS_NO_ERROR )
                    {
                        nandlog_print("(Z,BIdx,Block) = (%d,%d,%d) read error in 1st page\r\n",i,k,j);

                    }
                    for (l=0;l< F_info.SectorNumPerPage * 512;l++ )
                    {
                        if (BufPtr[l] != 0xFF )
                        {
	                        nandlog_print("[Error] After erase, data is not empty.\r\n");

                            dbg_ASSERT(0);
                        }
                    }
                    #if defined(__NFI_VERSION3_1__)

                    if ( (DAL_GetFDMData(FDMDATA_LBA, S_Buff)!=(kal_uint16)0xffff) ||
                    	 (DAL_GetFDMData(FDMDATA_BM, S_Buff)!=(kal_uint16)0xffff) ) {
                        nandlog_print("[Error] After erase, data is not empty.\r\n");

                        dbg_ASSERT(0);
                    }

					#else // defined(__NFI_VERSION3_1__)

                    for (l=0;l< F_info.SectorNumPerPage * 16/4;l++ )
                    {
                        if (S_Buff[l] != 0xFFFFFFFF )
                        {
                            dbg_ASSERT(0);
                        }
                    }

                    #endif // defined(__NFI_VERSION3_1__)
                }
                else
                {
BAD_BLOCK:
                    nandlog_print("Bad block(0x%X) at (Z,BIdx,Block) = (%d,%d,%d)\r\n",retVal,i,k,j);
#ifdef DAL_DEBUG_TEXT

#endif // DAL_DEBUG_TEXT
                }
            }
        }
    }
    nandlog_print("-> Erase check pass \r\n");

    kal_mem_set(S_Buff, 0xFF, sizeof(S_Buff));
    /*Program all with the logic address*/
    nandlog_print("-> Program test... \r\n");
    for (i=0;i< F_info.TotalZoneNum; i++)
    {
        for (j=0; j<F_info.PSectionNumInZone[i]; j++ )
        {
        	if ( (j & 0x7f)==0 ) {
	            nandlog_print("Program test already passed zone %xh, section %xh.\r\n",i,j);

        	}

            for (k=0;k< F_info.BankNumber; k++)
            {
                b_arr[k] = j;
                if ( (retVal = DAL_CheckBadBlock(FAT_ACC, i, b_arr, k,KAL_FALSE,D_Buff, S_Buff)) ==  MTD_STATUS_NO_ERROR)
                {
                    for (l=0;l< F_info.PageNumPerSection ; l+= F_info.BankNumber)
                    {
                        kal_sprintf((char*)(BufPtr + (l%4)),"(Z,BIdx,Block,Page) = (%d,%d,%d,%d)\n",i,k,j,k+l );
						            DAL_SetFDMData((kal_uint16)j, (kal_uint16)j, FDMDATA_EMPTY | FDMDATA_LBA | FDMDATA_BM, S_Buff);
                        retVal = DAL_ProgramPage(FAT_ACC, i,b_arr,k+l,1,(kal_uint8*)(BufPtr + (l%4)),(kal_uint8*)S_Buff );
                        if ( retVal != MTD_STATUS_NO_ERROR )
                        {
                            nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) program error\r\n",i,k,j,k+l );

                            //dbg_ASSERT(0);
                            continue;
                        }

						kal_mem_set(S_Buff, 0xFF, sizeof(S_Buff));
						kal_mem_set(BufPtr, 0xFF, sizeof(D_Buff));
                        retVal = DAL_ReadPage(FAT_ACC, i,b_arr,k+l,1,(kal_uint8*)(BufPtr + (l%4)),(kal_uint8*)S_Buff ) & 0xffff0000;
                        if ( retVal == MTD_STATUS_ERROR )
                        {
                            nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) read error\r\n",i,k,j,k+l );

                            dbg_ASSERT(0);
                        }
                        kal_sprintf(NAND_text_buff,"(Z,BIdx,Block,Page) = (%d,%d,%d,%d)\n",i,k,j,k+l );
                        if (strcmp(NAND_text_buff,(char*)(BufPtr + (l%4)))!=0)
                        {
                            nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) content error\r\n",i,k,j,k+l );

                            dbg_ASSERT(0);
                        }

                    }
                }
                else
                {
#ifdef DAL_DEBUG_TEXT
                    nandlog_print("Bad block(0x%X) at (Z,BIdx,Block) = (%d,%d,%d)\r\n",retVal,i,k,j);

#endif
                }
            }
        }
    }
    nandlog_print("-> Program check pass \r\n");

    /*Read all with the logic address*/
    nandlog_print("-> Read compare... \r\n");
    for (i=0;i< F_info.TotalZoneNum; i++)
    {
        for (j=0; j<F_info.PSectionNumInZone[i]; j++ )
        {
        	if ( (j & 0x7f)==0 ) {
	            nandlog_print("Read compare test already passed zone %xh, section %xh.\r\n",i,j);

        	}
            for (k=0;k< F_info.BankNumber; k++)
            {
                b_arr[k] = j;
                if ( (retVal = DAL_CheckBadBlock(FAT_ACC, i, b_arr, k,KAL_FALSE,D_Buff, S_Buff)) ==  MTD_STATUS_NO_ERROR)
                {
                    for (l=0;l< F_info.PageNumPerSection ; l+= F_info.BankNumber)
                    {
                        retVal = DAL_ReadPage(FAT_ACC, i,b_arr,k+l,1,(kal_uint8*)BufPtr,(kal_uint8*)S_Buff ) & 0xffff0000;
                        if ( retVal == MTD_STATUS_ERROR )
                        {
                            nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) read error\r\n",i,k,j,k+l );

                            dbg_ASSERT(0);
                        }
                        kal_sprintf(NAND_text_buff,"(Z,BIdx,Block,Page) = (%d,%d,%d,%d)\n",i,k,j,k+l );
                        if (strcmp(NAND_text_buff,(char*)BufPtr)!=0)
                        {
                            nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) content error\r\n",i,k,j,k+l );

                            dbg_ASSERT(0);
                        }
                        if ( (DAL_GetFDMData(FDMDATA_LBA, S_Buff)!=(kal_uint16)j) ||
                        	 (DAL_GetFDMData(FDMDATA_BM, S_Buff)!=(kal_uint16)j) ) {
                            nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) spare error\r\n",i,k,j,k+l );

                            dbg_ASSERT(0);
                        }
                    }
                }
                else
                {
#ifdef DAL_DEBUG_TEXT
                    nandlog_print("Bad block(0x%X) at (Z,BIdx,Block) = (%d,%d,%d)\r\n",retVal,i,k,j);

#endif // DAL_DEBUG_TEXT
                }
            }
        }
    }
    nandlog_print("-> Read back check pass \r\n");

    if (BufPtr == (kal_uint8 *)D_Buff)
    {
    	goto DAL_TEST_START;
    }

    #endif
    DAL_ShutDown();
}

void DAL_Section_Test (void)
{
    kal_uint32 i,j,k,l,m;
    static kal_uint32 count = 0;
    kal_uint32 retVal = MTD_STATUS_NO_ERROR;
    kal_uint16 b_arr[8];
    FLASH_INFO F_info;

    DAL_init();
    DAL_FDM_Flash_Info_Init (&F_info, 0);

    nandlog_print("Count:%d -- TotalZoneNum:%d,BankNumber:%d\r\n",count, F_info.TotalZoneNum,F_info.BankNumber);

    /*Get the good section to test*/
    for (i=0;i< F_info.TotalZoneNum; i++)
    {
        for (j=0; j<F_info.PSectionNumInZone[i]; j+=0x20 )
        {
TEST_START:
            /*Bad block check*/
            for (k=0;k< F_info.BankNumber; k++)
            {
                b_arr[k] = j;
                if ( (retVal = DAL_CheckBadBlock(FAT_ACC, i, b_arr, k,KAL_FALSE,D_Buff, S_Buff)) !=  MTD_STATUS_NO_ERROR)
                    break;
            }
            if (k != F_info.BankNumber)
            {
                nandlog_print("Bad block(0x%X) at (Z,BIdx,Block) = (%d,%d,%d)\r\n",retVal,i,k,j);

                continue; /*go to next section*/
            }
            else
            {
			    /*continuous access test from 0 ~ bankNumber*/
			    nandlog_print("Bank operation test\r\n");
			    for (k=0;k< F_info.BankNumber; k++)
			    {
			        for (l=k;l<F_info.BankNumber;l++ )
			        {
			            nandlog_print("(Z,Section, Page) = (%d,%d,%d) -> (%d,%d,%d) test start\r\n",i,j,k,i,j,l);

			            /*Erase*/
			            retVal = DAL_EraseBlock(FAT_ACC, i,b_arr, k, l-k+1 );
			            if ( retVal != MTD_STATUS_NO_ERROR )
			            {
			                nandlog_print("(Z,Section) = (%d,%d) erase fail\r\n",i,j);

			                goto TEST_START;
			                //dbg_ASSERT(0);
			            }
			            /*Read back check*/
			            retVal = DAL_ReadPage(FAT_ACC, i,b_arr,k,l-k+1,(kal_uint8*)D_Buff,(kal_uint8*)S_Buff );
			            if ( retVal != MTD_STATUS_NO_ERROR )
			            {
			                nandlog_print("(Z,Section) = (%d,%d) read fail\r\n",i,j);

			                dbg_ASSERT(0);
			            }
			            for (m=0;m< F_info.SectorNumPerPage * 512/4 * (l-k+1) ;m++ )
			            {
			                if (D_Buff[m] != 0xFFFFFFFF )
			                {
			                    nandlog_print("(Z,Section) = (%d,%d) read main check fail\r\n",i,j);

			                    dbg_ASSERT(0);
			                }
			            }
	                    #if defined(__NFI_VERSION3_1__)

			            for (m=0; m<F_info.SectorNumPerPage * 16/4 * (l-k+1); m += (16/4) )
			            {
		                    if ( (DAL_GetFDMData(FDMDATA_LBA, &(S_Buff[m]))!=(kal_uint16)0xffff) ||
		                    	 (DAL_GetFDMData(FDMDATA_BM, &(S_Buff[m]))!=(kal_uint16)0xffff) ) {
		                        nandlog_print("[Error] After erase, data is not empty.\r\n");

		                        dbg_ASSERT(0);
		                    }
			            }

						#else // defined(__NFI_VERSION3_1__)

			            for (m=0;m< F_info.SectorNumPerPage * 16/4 * (l-k+1) ;m++ )
			            {
			                if (S_Buff[m] != 0xFFFFFFFF )
			                {
			                    nandlog_print("(Z,Section) = (%d,%d) read spare check fail\r\n",i,j);

			                    dbg_ASSERT(0);
			                }
			            }

			            #endif //  defined(__NFI_VERSION3_1__)

			            /*Write*/
			            for (m=0;m<(l-k+1);m++)
			            {
			                kal_sprintf((char *)&D_Buff[Flash_Info.pageSize*m/4],"(Z,BIdx,Block,Page) = (%d,%d,%d,%d)\n",i,m+k,j,0);
			            }
						DAL_SetFDMData((kal_uint16)j, (kal_uint16)j, FDMDATA_EMPTY | FDMDATA_LBA | FDMDATA_BM, S_Buff);
			            retVal = DAL_ProgramPage(FAT_ACC, i,b_arr,k,l-k+1,(kal_uint8*)D_Buff,(kal_uint8*)S_Buff );
			            if ( retVal != MTD_STATUS_NO_ERROR )
			            {
			                nandlog_print("(Z,Section) = (%d,%d) program fail\r\n",i,j);

			                goto TEST_START;
			                //dbg_ASSERT(0);
			            }
			            kal_mem_set(D_Buff, 0xFF, (l-k+1)*Flash_Info.pageSize );
			            /*Read back check*/
			            retVal = DAL_ReadPage(FAT_ACC, i,b_arr,k,l-k+1,(kal_uint8*)D_Buff,(kal_uint8*)S_Buff );
			            if ( retVal != MTD_STATUS_NO_ERROR )
			            {
			                nandlog_print("(Z,Section) = (%d,%d) read operation fail\r\n",i,j);

			                dbg_ASSERT(0);
			            }
			            for (m=0;m<(l-k+1);m++)
			            {
			                kal_sprintf(NAND_text_buff,"(Z,BIdx,Block,Page) = (%d,%d,%d,%d)\n",i,m+k,j,0);
			                if (strcmp(NAND_text_buff,(char*)&D_Buff[Flash_Info.pageSize*m/4])!=0)
			                {
			                    nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) content error\r\n",i,m+k,j,0 );

			                    dbg_ASSERT(0);
			                }
			            }
			            if ( (DAL_GetFDMData(FDMDATA_LBA, S_Buff)!=(kal_uint16)j) ||
			            	 (DAL_GetFDMData(FDMDATA_BM, S_Buff)!=(kal_uint16)j) ) {
			                nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) Spare content error\r\n",i,0,j,0 );

			                dbg_ASSERT(0);
			            }

			            /*Copy test*/
			            retVal = DAL_CopyPage(FAT_ACC, i,b_arr,b_arr, k,k+F_info.BankNumber, l-k+1 ,(kal_uint8*)D_Buff,(kal_uint8*)S_Buff,
			                                  sizeof(D_Buff)/Flash_Info.pageSize,0 );
			            if ( retVal != MTD_STATUS_NO_ERROR )
			            {
			                nandlog_print("(Z,Section) = (%d,%d) Copy fail\r\n",i,j);

			                goto TEST_START;
			                //dbg_ASSERT(0);
			            }
			            kal_mem_set(D_Buff, 0xFF, (l-k+1)*Flash_Info.pageSize );
			            /*Read back check*/
			            retVal = DAL_ReadPage(FAT_ACC, i,b_arr,k+F_info.BankNumber,l-k+1,(kal_uint8*)D_Buff,(kal_uint8*)S_Buff );
			            if ( retVal != MTD_STATUS_NO_ERROR )
			            {
			                nandlog_print("(Z,Section) = (%d,%d) read operation fail\r\n",i,j);

			                dbg_ASSERT(0);
			            }
			            for (m=0;m<(l-k+1);m++)
			            {
			                kal_sprintf(NAND_text_buff,"(Z,BIdx,Block,Page) = (%d,%d,%d,%d)\n",i,m+k,j,0);
			                if (strcmp(NAND_text_buff,(char*)&D_Buff[Flash_Info.pageSize*m/4])!=0)
			                {
			                    nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) content error\r\n",i,m+k,j,1 );

			                    dbg_ASSERT(0);
			                }
			            }
			            if ( (DAL_GetFDMData(FDMDATA_LBA, S_Buff)!=(kal_uint16)j) ||
			            	 (DAL_GetFDMData(FDMDATA_BM, S_Buff)!=(kal_uint16)j) ) {
			                nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) Spare content error\r\n",i,0,j,0 );

			                dbg_ASSERT(0);
			            }
			#if defined DAL_VERIFICATION
			            /*DAL_MarkBlockBad and DAL_CheckBlockBad*/
			            DAL_MarkBlockBad(FAT_ACC, i, b_arr, k, KAL_TRUE, D_Buff, S_Buff);
			            retVal = DAL_CheckBadBlock (FAT_ACC, i, b_arr, k, KAL_FALSE, D_Buff, S_Buff);
			            if ( (retVal&MTD_STATUS_FDM_BAD) != MTD_STATUS_FDM_BAD )
			            {
			                nandlog_print("(Z,BIdx,Block) = (%d,%d,%d) read operation fail\r\n",i,k,j);

			                dbg_ASSERT(0);
			            }
			            nandlog_print("(Z,Section, Page) = (%d,%d,%d) -> (%d,%d,%d) test success\r\n",i,j,k,i,j,l);

			#endif
			        }
			    }

			    nandlog_print("Continueous program test\r\n");
			    /*bank number aligned continuous access test (cache operation test)*/
			    if (sizeof(D_Buff) >= Flash_Info.bankNum * Flash_Info.pageSize*2 )
			    {
			        for (l=F_info.BankNumber*2;l <= sizeof(D_Buff)/Flash_Info.pageSize;l+=F_info.BankNumber )
			        {
			            nandlog_print("(Z,Section, Page) = (%d,%d,%d) -> (%d,%d,%d) test start\r\n",i,j,0,i,j,l-1);

			            /*Erase*/
			            retVal = DAL_EraseBlock(FAT_ACC, i,b_arr, 0, F_info.BankNumber );
			            if ( retVal != MTD_STATUS_NO_ERROR )
			            {
			                nandlog_print("(Z,Section) = (%d,%d) erase fail\r\n",i,j);

			                goto TEST_START;
			            }
			            /*Read back check*/
			            retVal = DAL_ReadPage(FAT_ACC, i,b_arr,0, F_info.BankNumber, (kal_uint8*)D_Buff,(kal_uint8*)S_Buff );
			            if ( retVal != MTD_STATUS_NO_ERROR )
			            {
			                nandlog_print("(Z,Section) = (%d,%d) read fail\r\n",i,j);

			                dbg_ASSERT(0);
			            }
			            for (m=0;m< F_info.SectorNumPerPage * 512/4 * F_info.BankNumber ;m++ )
			            {
			                if (D_Buff[m] != 0xFFFFFFFF )
			                {
			                    nandlog_print("(Z,Section) = (%d,%d) read check fail\r\n",i,j);

			                    dbg_ASSERT(0);
			                }
			            }
			            /*Write*/
			            for (m=0;m<l;m++)
			            {
			                kal_sprintf((char*)&D_Buff[Flash_Info.pageSize*m/4],"(Z,BIdx,Block,Page) = (%d,%d,%d,%d)\n",i,m%F_info.BankNumber,j,m/F_info.BankNumber);
			            }
						DAL_SetFDMData((kal_uint16)j, (kal_uint16)j, FDMDATA_EMPTY | FDMDATA_LBA | FDMDATA_BM, S_Buff);
			            retVal = DAL_ProgramPage(FAT_ACC, i,b_arr,0,l,(kal_uint8*)D_Buff,(kal_uint8*)S_Buff );
			            if ( retVal != MTD_STATUS_NO_ERROR )
			            {
			                nandlog_print("(Z,Section) = (%d,%d) program fail\r\n",i,j);

			                dbg_ASSERT(0);
			            }
			            kal_mem_set(D_Buff, 0xFF, l*Flash_Info.pageSize );
			            /*Read back check*/
			            retVal = DAL_ReadPage(FAT_ACC, i,b_arr,0,l,(kal_uint8*)D_Buff,(kal_uint8*)S_Buff );
			            if ( retVal != MTD_STATUS_NO_ERROR )
			            {
			                nandlog_print("(Z,Section) = (%d,%d) read operation fail\r\n",i,j);

			                dbg_ASSERT(0);
			            }
			            for (m=0;m<l;m++)
			            {
			                kal_sprintf(NAND_text_buff,"(Z,BIdx,Block,Page) = (%d,%d,%d,%d)\n",i,m%F_info.BankNumber,j,m/F_info.BankNumber);
			                if (strcmp(NAND_text_buff,(char*)&D_Buff[Flash_Info.pageSize*m/4])!=0)
			                {
			                    nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) content error\r\n",i,m%F_info.BankNumber,j,m/F_info.BankNumber);

			                    dbg_ASSERT(0);
			                }
			            }
			            if ( (DAL_GetFDMData(FDMDATA_LBA, S_Buff)!=(kal_uint16)j) ||
			            	 (DAL_GetFDMData(FDMDATA_BM, S_Buff)!=(kal_uint16)j) ) {
			                nandlog_print("(Z,BIdx,Block,Page) = (%d,%d,%d,%d) Spare content error\r\n",i,0,j,0 );

			                dbg_ASSERT(0);
			            }
			            nandlog_print("(Z,Section, Page) = (%d,%d,%d) -> (%d,%d,%d) test succes\r\n",i,j,0,i,j,l-1);

			        }

			    }

            }
        }
    }
    DAL_ShutDown();
    nandlog_print("Test finish... \r");
}

/****************************************************************************
 * Function:
 *
 * Parameters:
 *
 * Returns:
 *
 * Description: While box test (make condition to let DAL returns error then check the error value
 *
 ****************************************************************************/
void DAL_WhileBox_Test (void)
{
    kal_uint32 i,j=0,k,l,m;
    kal_uint32 retVal = MTD_STATUS_NO_ERROR;
    kal_uint16 b_arr[8];
    FLASH_INFO F_info;

    DAL_init();
    DAL_FDM_Flash_Info_Init (&F_info, 0);

    /*Get the good section to test*/
    for (i=0;i< F_info.TotalZoneNum; i++)
    {
        for (j=0; j<F_info.PSectionNumInZone[i]; j++ )
        {
            /*Bad block check*/
            for (k=0;k< F_info.BankNumber; k++)
            {
                b_arr[k] = j;
                if ( (retVal = DAL_CheckBadBlock(FAT_ACC, i, b_arr, k,KAL_FALSE,D_Buff, S_Buff)) !=  MTD_STATUS_NO_ERROR)
                    break;
            }
            if (k != F_info.BankNumber)
            {
                nandlog_print("Bad block(0x%X) at (Z,BIdx,Block) = (%d,%d,%d)\r\n",retVal,i,k,j);

                continue; /*go to next section*/
            }
            else
            {
                goto MAIN;
            }
        }
    }
MAIN:
    /*DAL_EraseBlock test*/
    Fail_Bank = 0xFF; /*Reset*/
    for (k=0;k< F_info.BankNumber; k++)
    {
        for (l=k;l<F_info.BankNumber;l++ )
        {
            Fail_Bank = l;
            retVal = DAL_EraseBlock(FAT_ACC, i,b_arr, k, l-k+1 );
            dbg_ASSERT(retVal != MTD_STATUS_NO_ERROR);
            dbg_ASSERT((retVal&0xFFFF0000) == MTD_STATUS_ERROR);
            if ( (retVal&0xFFFF) != (1<<Fail_Bank) )
            {
                nandlog_print("DAL_EraseBlock get wrong return at (Z,BIdx) = (%d,%d)\r\n",i,l);

                dbg_ASSERT(0);
            }
        }
    }
    nandlog_print("Erase check pass \r\n");
    /*DAL_ProgramPage test*/
    Fail_Bank = 0xFF; /*Reset*/
    for (k=0;k< F_info.BankNumber; k++)
    {
        for (l=k;l<F_info.BankNumber;l++ )
        {
            for (m=0;m<(l-k+1);m++)
            {
                kal_sprintf((char*)&D_Buff[Flash_Info.pageSize*m/4],"(Z,BIdx,Block,Page) = (%d,%d,%d,%d)\n",i,m+k,j,0);
            }
            Fail_Bank = l;
            retVal = DAL_ProgramPage(FAT_ACC, i,b_arr, k, l-k+1 ,(kal_uint8*)D_Buff,(kal_uint8*)S_Buff );
            dbg_ASSERT(retVal != MTD_STATUS_NO_ERROR);
            dbg_ASSERT((retVal&0xFFFF0000) == MTD_STATUS_ERROR);
            if ( (retVal&0xFFFF) != (1<<Fail_Bank) )
            {
                nandlog_print("DAL_ProgramPage get wrong return at (Z,BIdx) = (%d,%d)\r\n",i,l);

                dbg_ASSERT(0);
            }
        }
    }
    nandlog_print("-> Write check pass \r\n");
    /*DAL_ReadPage test*/
    Fail_Bank = 0xFF; /*Reset*/
    for (k=0;k< F_info.BankNumber; k++)
    {
        for (l=k;l<F_info.BankNumber;l++ )
        {
            Fail_Bank = l;
            retVal = DAL_ReadPage(FAT_ACC, i,b_arr, k, l-k+1 ,(kal_uint8*)D_Buff,(kal_uint8*)S_Buff );
            dbg_ASSERT(retVal != MTD_STATUS_NO_ERROR);
            dbg_ASSERT((retVal&0xFFFF0000) == MTD_STATUS_ERROR);
            if ( (retVal&0xFFFF) != (1<<Fail_Bank) )
            {
                nandlog_print("DAL_ReadPage get wrong return at (Z,BIdx) = (%d,%d)\r\n",i,l);

                dbg_ASSERT(0);
            }
        }
    }
    nandlog_print("-> Read check pass \r\n");
    /*DAL_CopyPage test*/
    Fail_Bank = 0xFF; /*Reset*/
    {
        for (k=0;k< F_info.BankNumber; k++)
        {
            for (l=k;l<F_info.BankNumber;l++ )
            {
                Fail_Bank = l;
                retVal = DAL_CopyPage(FAT_ACC, i,b_arr,b_arr, k,k+F_info.BankNumber, l-k+1 ,(kal_uint8*)D_Buff,(kal_uint8*)S_Buff,
                                      sizeof(D_Buff)/Flash_Info.pageSize,0 );
                dbg_ASSERT(retVal != MTD_STATUS_NO_ERROR);
                dbg_ASSERT((retVal&0xFFFF0000) == MTD_STATUS_ERROR);
                if ( (retVal&0xFFFF) != (1<<Fail_Bank) )
                {
                    nandlog_print("DAL_CopyPage get wrong return at (Z,BIdx) = (%d,%d)\r\n",i,l);

                    dbg_ASSERT(0);
                }
            }
        }
    }
    nandlog_print("-> Copy check pass \r\n");
    DAL_ShutDown();
}
#endif // ( !defined(__UBL__) )
#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )


/****************************************************************************
 * Function:
 *
 * Parameters:
 *
 * Returns:
 *
 * Description: It will change Flash_Info.multiProgram
 *                             Flash_Info.zone_CE
 *                             Flash_Info.bank_CE
 *                             Flash_Info.supportMPType
 *              according to the Flash_Info.deviceInfo_CE[ceIdx].driverSet and Flash_Info.supportMPType
 ****************************************************************************/
kal_uint32 init_multiProgram ( void )
{
    kal_uint8   m_idx, ce_idx;
    kal_uint16  supportMPType_ce[2] = {0,0};
    kal_uint32  bank_len_zone;

    kal_mem_set( Flash_Info.multiProgram, 0x00, sizeof(Flash_Info.multiProgram));

    for (ce_idx=0; ce_idx<2;ce_idx++)
    {
        for (m_idx=0; m_idx<MAX_MULTIPAGE_FUNCTION_NUM;m_idx++)
        {
            Flash_Info.multiProgram[ce_idx][m_idx].startAlign = 0xFF;
        }
    }

    /*Operation function setting for each CE device*/
    for (ce_idx=0; ce_idx<2; ce_idx++)
    {
        if (Flash_Info.valid_CE[ce_idx] == KAL_FALSE)
        {
            continue;
        }

        supportMPType_ce[ce_idx] = Flash_Info.supportMPType[ce_idx]& (~(CACHE_PROGRAM|TWO_DIE_INTERLEAVE_OP|TWO_PLANE_OP|FOUR_PLANE_OP));

        m_idx = 1;

        Flash_Info.bank_CE[ce_idx] = 1;

        /*non-support operation */
        dbg_ASSERT((Flash_Info.supportMPType[ce_idx] & (TWO_DIE_INTERLEAVE_OP|FOUR_PLANE_OP)) != (TWO_DIE_INTERLEAVE_OP|FOUR_PLANE_OP));
        dbg_ASSERT((Flash_Info.supportMPType[ce_idx] & (TWO_PLANE_OP|FOUR_PLANE_OP)) != (TWO_PLANE_OP|FOUR_PLANE_OP));

        if ( (devDriver(ce_idx)->ProgramPage != NULL) )
        {
            Flash_Info.multiProgram[ce_idx][m_idx].func_p = devDriver(ce_idx)->ProgramPage ;
            Flash_Info.multiProgram[ce_idx][m_idx].multiPageNum = 1;
            Flash_Info.multiProgram[ce_idx][m_idx].startAlign = 1; /*any position % 1 == 0*/

            if (m_idx == 1)
            {
                Flash_Info.bank_CE[ce_idx] = 1;
            }

            m_idx++;
        }
        else
        {
            //ASSERT(0);  // TODO: STANLEYC
        }

        /*set Flash_Info.supportMPType[ce_idx]*/
        Flash_Info.supportMPType[ce_idx] = supportMPType_ce[ce_idx];

        /*set Flash_Info.zone_CE[ce_idx]*/
        /*bank_len_zone must be smaller than planePage(ce_idx)*/
        bank_len_zone = devicePage(ce_idx)/Flash_Info.bank_CE[ce_idx] < planePage(ce_idx) ? devicePage(ce_idx)/Flash_Info.bank_CE[ce_idx] : planePage(ce_idx);
        Flash_Info.zone_CE[ce_idx] = devicePage(ce_idx)/(bank_len_zone*Flash_Info.bank_CE[ce_idx]);
    }

    return MTD_STATUS_NO_ERROR;
}
/****************************************************************************
 * Function:
 *
 * Parameters:
 *
 * Returns:
 *
 * Description: It will change Flash_Info.multiErase
 *                             Flash_Info.supportMEType
 *              according to the Flash_Info.deviceInfo_CE[ceIdx].driverSet and Flash_Info.supportMEType
 ****************************************************************************/
kal_uint32 init_multiErase ( void )
{
    kal_uint8   m_idx, ce_idx;
    kal_uint16  supportMEType_ce[2] = {0,0};

    kal_mem_set( Flash_Info.multiErase, 0x00, sizeof(Flash_Info.multiErase));

    for (ce_idx=0; ce_idx<2;ce_idx++)
    {
        for (m_idx=0; m_idx<MAX_MULTIPAGE_FUNCTION_NUM;m_idx++)
        {
            Flash_Info.multiErase[ce_idx][m_idx].startAlign = 0xFF;
        }
    }

    /*Operation function setting for each CE device*/
    for (ce_idx=0; ce_idx<2;ce_idx++)
    {
        if (Flash_Info.valid_CE[ce_idx] == KAL_FALSE)
        {
            continue;
        }

        Flash_Info.supportMEType[ce_idx] &= Flash_Info.supportMPType[ce_idx]; /*Multi Block erase support must follow (or less than) Multi-Page erase support*/

        supportMEType_ce[ce_idx] = Flash_Info.supportMEType[ce_idx] & (~(TWO_DIE_INTERLEAVE_OP|TWO_PLANE_OP|FOUR_PLANE_OP));

        m_idx = 0;

        /*1 page operation check */
        if ( (devDriver(ce_idx)->EraseBlock != NULL) )
        {
            Flash_Info.multiErase[ce_idx][m_idx].func_p = devDriver(ce_idx)->EraseBlock ;
            Flash_Info.multiErase[ce_idx][m_idx].multiPageNum = 1;
            Flash_Info.multiErase[ce_idx][m_idx].startAlign = 1; /*any position % 1 == 0*/
            m_idx++;
        }
        else
        {
            //ASSERT(0);  // TODO: STANLEYC
        }

        /*set Flash_Info.supportMEType[ce_idx]*/
        Flash_Info.supportMEType[ce_idx] = supportMEType_ce[ce_idx];
    }

    return MTD_STATUS_NO_ERROR;
}

kal_uint32 init_CE_interleave (void)
{
    Flash_Info.CE_interleave_Flag = KAL_FALSE;
    Flash_Info.CE_cache_interleave_Flag = KAL_FALSE;

    return MTD_STATUS_NO_ERROR;
}

#if defined(__AUDIO_DSP_LOWPOWER__)
void DAL_MP3InitVariable(void)
{
    NFI_ConfigforMP3.nfi_ACCCON_reg = *NFI_ACCCON;
    NFI_ConfigforMP3.nfi_page_size = Flash_Info.pageSize;
    NFI_ConfigforMP3.nfi_spare_size = 16;
    NFI_ConfigforMP3.nfi_pages_per_block = Flash_Info.blockPage;
    NFI_ConfigforMP3.nfi_fdm_size = 8;// FDM size fixed to 8 Bytes
    NFI_ConfigforMP3.nfi_sector_num = (Flash_Info.pageSize/512);
    NFI_ConfigforMP3.nfi_data_sectors = (Flash_Info.pageSize/512);
    if(Flash_Info.pageSize==512)
    {
        NFI_ConfigforMP3.nfi_col_num = 1;
        NFI_ConfigforMP3.nfi_row_num = (Flash_Info.deviceInfo_CE[0].address_cycle-1);
    }
    else
    {
        NFI_ConfigforMP3.nfi_col_num = 2;
        NFI_ConfigforMP3.nfi_row_num = (Flash_Info.deviceInfo_CE[0].address_cycle-2);
    }
    if(Flash_Info.deviceInfo_CE[0].IOWidth==16)
    {
        NFI_ConfigforMP3.nfi_io_width = 1;
    }
    else
    {
        NFI_ConfigforMP3.nfi_io_width = 0;
    }
}
#endif //#if defined(__AUDIO_DSP_LOWPOWER__)

/****************************************************************************
 * Function:
 *
 * Parameters:  void
 *
 * Returns:     FS_NO_ERROR
 *              FS_NAND_DEVICE_NOT_SUPPORTED
 *              FS_FLASH_MOUNT_ERROR
 * Description:
 *
 ****************************************************************************/
 /*Note: Please DO NOT modify the function name, because append2.pl use this function name to identify
* __NAND_FDM_50__ and apply the MTK_ROMInfo_v06_ST */

kal_int32 DAL_init (void)
{
    kal_int32 retVal;

    get_MTD_lock();
    kal_mem_set(&Flash_Info,0x00, sizeof(Flash_Info) );

    /*Get CE# ID and set dev_driver, devicePage*/ /*2 CE must : same block size, same page size, same EXTENDED_BLOCK or not*/ /*same PLANE_INTERLACED or PLANE_CONTINUOUS ??*/
    retVal = MTD_MountDevice();

    if (retVal != FS_NO_ERROR)
    {
        DAL_is_initialized = KAL_TRUE;
        free_MTD_lock();

        return retVal;
    }

    // fill-in FlashInfo

    Flash_Info.pageSize = Flash_Info.deviceInfo_CE[0].pageSize;
    Flash_Info.spareSize = Flash_Info.deviceInfo_CE[0].spareSize;

    #if !(defined __UBL__)
    force_ASSERT( sizeof(DAL_spare_buff) >= Flash_Info.spareSize,sizeof(DAL_spare_buff),Flash_Info.spareSize,0);
    #endif

    Flash_Info.blockPage = Flash_Info.deviceInfo_CE[0].blockPage;

    /*Operation function setting for each CE device*/
    Flash_Info.supportMPType[0] = Flash_Info.deviceInfo_CE[0].supportMPType;
    Flash_Info.supportMPType[1] = (Flash_Info.valid_CE[1] == KAL_TRUE) ?  Flash_Info.deviceInfo_CE[1].supportMPType : 0;

    init_multiProgram ();

    Flash_Info.supportMEType[0] = Flash_Info.deviceInfo_CE[0].supportMEType;
    Flash_Info.supportMEType[1] = Flash_Info.deviceInfo_CE[1].supportMEType;
    init_multiErase ();

    /* Set Flash_Info.CE_interleave parameters*/
    init_CE_interleave();

    Flash_Info.bankNum = (Flash_Info.CE_interleave_Flag == KAL_FALSE ? (Flash_Info.bank_CE[0]):(Flash_Info.bank_CE[0]+Flash_Info.bank_CE[1]));
    Flash_Info.zoneNum = (Flash_Info.CE_interleave_Flag == KAL_FALSE ? (Flash_Info.zone_CE[0]+Flash_Info.zone_CE[1]):(Flash_Info.zone_CE[0]));

    force_ASSERT( MAX_MULTIPAGE_NUM >= Flash_Info.bankNum,Flash_Info.bankNum,0,0 );

    kal_mem_set(MapCache, 0xFF, sizeof(MapCache));
    kal_mem_set(MapCacheCount, 0xFF, sizeof(MapCacheCount));

    DAL_is_initialized = KAL_TRUE;

#if defined (__AUDIO_DSP_LOWPOWER__)
    DAL_MP3InitVariable();
#endif //__AUDIO_DSP_LOWPOWER__

    free_MTD_lock();

    return FS_NO_ERROR;
}
/****************************************************************************
 * Function:
 *
 * Parameters:  void
 *
 * Returns:     FS_NO_ERROR
 *
 * Description:
 *
 ****************************************************************************/
kal_int32 DAL_ShutDown (void)
{
    kal_int32 retVal;

    get_MTD_lock();
    retVal = MTD_ShutDown();
    free_MTD_lock();

    return retVal;
}

kal_int32 DAL_FDM_Flash_Info_Init ( FLASH_INFO* fdm_flash_info, kal_uint32 DiskIndex)
{
    kal_uint32 FAT_start_position;
    kal_uint32 FAT_length;
    kal_uint32 zone_len;
    kal_uint16 i;
    kal_uint8  FAT_start_z, FAT_end_z;
    kal_uint32 sectionPage = 0;

    get_MTD_lock();

    /*fill fdm_flash_info->BankNumber*/
    fdm_flash_info->BankNumber = Flash_Info.bankNum;
    /*fill fdm_flash_info->SectorNumPerPage*/
    fdm_flash_info->SectorNumPerPage = Flash_Info.pageSize/512;
    /*fill fdm_flash_info->PageNumPerSection*/
    fdm_flash_info->PageNumPerSection = fdm_flash_info->BankNumber * Flash_Info.blockPage;
    /*fill fdm_flash_info->PageNumPerSection*/
    sectionPage = fdm_flash_info->PageNumPerSection;

    for (i = 0; i < 32; i++)
    {
        if (sectionPage == (kal_uint32)(1<<i))
            break;
    }

    dbg_ASSERT(i < 32);

    fdm_flash_info->SectionShiftNum = i;

    /*fill fdm_flash_info->Plane_PagePair*/
    fdm_flash_info->Plane_PagePair = KAL_FALSE;

    #if (defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(__SPI_NAND_SUPPORT__)) ) && (!defined(__UBL__)||(defined(__UBL__)&&defined(__NAND_SUPPORT_RAW_DISK__)))

	#if !defined(__NANDFDM_MULTI_INSTANCE__)
    FAT_start_position = NFB_BASE_ADDRESS;
    FAT_length = NFB_ALLOCATED_FAT_SPACE;
	#else // !defined(__NANDFDM_MULTI_INSTANCE__)
    FAT_start_position = NFB_BASE_ADDRESS[DiskIndex];
    FAT_length = NFB_ALLOCATED_FAT_SPACE[DiskIndex];
	#endif // !defined(__NANDFDM_MULTI_INSTANCE__)

    FAT_start_position = (FAT_start_position + (Flash_Info.pageSize -1)) / Flash_Info.pageSize ; /*move to page aligned and unit by page*/
    FAT_start_position = (FAT_start_position + (sectionPage - 1)) / sectionPage * sectionPage; /*move to section aligned*/
    FAT_length /= Flash_Info.pageSize; /*reduce size to page aligned and unit by page*/
    FAT_length = FAT_length / sectionPage * sectionPage; /*reduce size to section aligned*/

    #else

    FAT_start_position = 0;  /*unit by page*/
    FAT_length = devicePage(0) + (Flash_Info.valid_CE[1] == KAL_TRUE ? devicePage(1) : 0); /*full NAND size is used for FAT */
    FAT_length = (Flash_Info.supportMPType[0]& EXTENDED_BLOCK) ? FAT_length/1024*(1024+16):FAT_length; /*consider EXTENDED_BLOCK size*/
    FAT_length = FAT_length / sectionPage * sectionPage; /*reduce size to section aligned*/

    #endif /* _NAND_FLASH_BOOTING_ || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && __SPI_NAND_SUPPORT__) */

    /*calculate zone_len*/
    if ( Flash_Info.valid_CE[1] == KAL_TRUE )
    {
        dbg_ASSERT( zonePage(0) == zonePage(1) );
    }
    zone_len = zonePage(0);

    /*fill fdm_flash_info->ExtendBlock*/
    fdm_flash_info->ExtendBlock = KAL_FALSE;

    FAT_start_z = FAT_start_position / zone_len;
    FAT_end_z = ( FAT_start_position+FAT_length - 1 ) / zone_len;

    /*fill fdm_flash_info->TotalZoneNum*/
    fdm_flash_info->TotalZoneNum = FAT_end_z - FAT_start_z + 1;
    dbg_ASSERT(fdm_flash_info->TotalZoneNum <= NUM_OF_ZONES);

    /*fill fdm_flash_info->PSectionNumInZone*/
    /*first one*/
    fdm_flash_info->PSectionNumInZone[0] =
        (zone_len - (FAT_start_position % zone_len)) < FAT_length ? (zone_len - (FAT_start_position % zone_len))/sectionPage : FAT_length/sectionPage;

    for (i = FAT_start_z + 1; i < FAT_end_z; i++)
    {
        fdm_flash_info->PSectionNumInZone[i - FAT_start_z] = zone_len/sectionPage;
    }

#if defined(__NANDFDM_MULTI_INSTANCE__)
    fdm_flash_info->TotalPSectionNumInZone = zone_len/sectionPage;
#endif // defined(__NANDFDM_MULTI_INSTANCE__)

    if (FAT_end_z > FAT_start_z)
       fdm_flash_info->PSectionNumInZone[FAT_end_z - FAT_start_z] = ( (( FAT_start_position+ FAT_length - 1)  % zone_len) + 1)/sectionPage;/*last one*/

    #if defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(__SPI_NAND_SUPPORT__))
    /*Fill the global variables FAT_Start_ZoneNum and FAT_Start_Section_Offset*/
	#if !defined(__NANDFDM_MULTI_INSTANCE__)
    FAT_Start_ZoneNum = FAT_start_z;
    FAT_Start_Section_Offset = (FAT_start_position % zone_len)/sectionPage;
	#else // !defined(__NANDFDM_MULTI_INSTANCE__)
    FAT_Start_ZoneNum[DiskIndex] = FAT_start_z;
    FAT_Start_Section_Offset[DiskIndex] = (FAT_start_position % zone_len)/sectionPage;
	#endif //!defined(__NANDFDM_MULTI_INSTANCE__)

	#if defined (__NAND_LMT__)
	{
		extern kal_uint32 IM_FAT_Start_Section;
		extern kal_uint32 IM_FAT_Start_Zone;

		IM_FAT_Start_Section = FAT_Start_Section_Offset;
		IM_FAT_Start_Zone = FAT_Start_ZoneNum;
		if (!bWholeImage) {

			FAT_Start_Section_Offset = 0;
			FAT_Start_ZoneNum = 0;
		}
	}

	#endif // defined (__NAND_LMT__)

    #endif /* _NAND_FLASH_BOOTING_ || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && __SPI_NAND_SUPPORT__) */

    free_MTD_lock();

    return MTD_STATUS_NO_ERROR;
}


kal_uint32 readMapCache(add_convert* AddInfo,kal_uint8* ce_p, kal_uint32* Zoffset_p,kal_uint32* Boffset_p )
{
    kal_uint8 bIdx = AddInfo->pageIdx%Flash_Info.bankNum;
    if ( AddInfo->bankArry[bIdx] == MapCache[bIdx][0].blockNum )
    {
        if (AddInfo->zoneNum == MapCache[bIdx][0].zoneNum )
        {
            *Zoffset_p = MapCache[bIdx][0].zoneOffset;
            *Boffset_p = MapCache[bIdx][0].bankOffset;
            *ce_p = MapCache[bIdx][0].ce;
            return KAL_TRUE;
        }
    }
    else if ( AddInfo->bankArry[bIdx] == MapCache[bIdx][1].blockNum )
    {
        if (AddInfo->zoneNum == MapCache[bIdx][1].zoneNum )
        {
            *Zoffset_p = MapCache[bIdx][1].zoneOffset;
            *Boffset_p = MapCache[bIdx][1].bankOffset;
            *ce_p = MapCache[bIdx][1].ce;
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;
}

kal_uint32 writeMapCache(add_convert* AddInfo, kal_uint32 Zoffset,kal_uint32 Boffset )
{
    kal_uint8 bIdx = AddInfo->pageIdx%Flash_Info.bankNum;
    kal_uint8 cnt = MapCacheCount[bIdx]%2;

    MapCache[bIdx][cnt].zoneNum = AddInfo->zoneNum;
    MapCache[bIdx][cnt].blockNum = AddInfo->bankArry[bIdx];

    MapCache[bIdx][cnt].ce = AddInfo->ce;
    MapCache[bIdx][cnt].zoneOffset = Zoffset;
    MapCache[bIdx][cnt].bankOffset = Boffset;

    MapCacheCount[bIdx] = cnt ? 0:1;
    return KAL_TRUE;
}

/*Can not support EXTENDED_BLOCK now*/
kal_uint32 addressMap(add_convert* AddInfo)
{

    kal_uint8  ce_idx, zoneNum;
    kal_uint32 zoneOffset;
    kal_uint8  cacheHitFlag;
    kal_uint8  bk_idx_die; /*bank index refer to the die*/
    kal_uint32 bankOffset, pageOffset;
    kal_uint16 blk_num;
    kal_uint32 tmp, bank_len_zone;

    ce_idx = BYTE_INVALID;
    zoneOffset = DWORD_INVALID;
    bankOffset = DWORD_INVALID;
    cacheHitFlag = readMapCache(AddInfo,&ce_idx,&zoneOffset,&bankOffset);

    /*Get the zoneOffset (unit by page) -- Start*/
    if ( zoneOffset == DWORD_INVALID)
    {
        #if defined(__NANDFDM_TOTAL_BBM__)
        bk_idx_die = AddInfo->pageIdx%Flash_Info.bankNum; /*now bk_idx_die is bk_idx of all Flash*/
        blk_num = AddInfo->bankArry[bk_idx_die];
        if(blk_num&BBM_GLOBAL_ADDR)
        {
        zoneNum = 0;
        }
        else
        {
        zoneNum = AddInfo->zoneNum;
        }
        #else  //#if defined(__NANDFDM_TOTAL_BBM__)
        zoneNum = AddInfo->zoneNum;
        #endif //#if defined(__NANDFDM_TOTAL_BBM__)

        if (zoneNum < Flash_Info.zone_CE[0])
            ce_idx = 0;
        else
        {
            ce_idx = 1;
            zoneNum -= Flash_Info.zone_CE[0];
        }

        dbg_ASSERT( zoneNum <= Flash_Info.zone_CE[ce_idx]);

        tmp = planePage(ce_idx)*Flash_Info.bank_CE[ce_idx]; /* tmp = n die size, n = bank_CE[ce_idx]/die plane Numer (deviceInfo_CE[ceIdx].planeNum) */
        zoneOffset =  tmp* (zoneNum/(tmp/zonePage(ce_idx)))  ; /*here zoneOffset is page that part of die aligned */
        zoneNum -= (zoneOffset/zonePage(ce_idx)); /*here zoneNum is reminder part of !(die aligned)*/

        bank_len_zone = zonePage(ce_idx)/Flash_Info.bank_CE[ce_idx];
        tmp = bank_len_zone * zoneNum; /* tmp = bank_len_zone * zoneNum */

        zoneOffset += tmp;
    }

    /*Get the zoneOffset (unit by page) -- End*/
    /*Get the bankOffset (unit by page) -- Start*/
    if (bankOffset == DWORD_INVALID)
    {
        bk_idx_die = AddInfo->pageIdx%Flash_Info.bankNum; /*now bk_idx_die is bk_idx of all Flash*/
        blk_num = AddInfo->bankArry[bk_idx_die];

        #if defined(__NANDFDM_TOTAL_BBM__)
        if(blk_num&BBM_GLOBAL_ADDR)
        {
          blk_num &=(~BBM_GLOBAL_ADDR);
        }
        #endif

         /*now bk_idx_die is bk_idx of ce_idx*/
        bankOffset = 0;

         /*now bk_idx_die is bk_idx of die*/
        bankOffset += bk_idx_die*planePage(ce_idx)+ blk_num* Flash_Info.blockPage;
    }

    /*Get the bankOffset (unit by page) -- End*/

    /*Get the pageOffset (unit by page) -- Start*/
    dbg_ASSERT( AddInfo->pageIdx < Flash_Info.bankNum*Flash_Info.blockPage);
    pageOffset = AddInfo->pageIdx/Flash_Info.bankNum;
    /*Get the bankOffset (unit by page) -- End*/

    /*fill to AddInfo*/
    AddInfo->phyPage = zoneOffset + bankOffset + pageOffset;
    AddInfo->ce = ce_idx;

    #if defined(__NANDFDM_TOTAL_BBM__)
    if(AddInfo->phyPage>=Flash_Info.devicePage[0])
    {
      ASSERT(Flash_Info.valid_CE[1]==KAL_TRUE);
      AddInfo->ce = 1;
      AddInfo->phyPage = (AddInfo->phyPage-Flash_Info.devicePage[0]);
    }
    #endif

	force_ASSERT(AddInfo->phyPage<Flash_Info.devicePage[AddInfo->ce],
		AddInfo->phyPage, Flash_Info.devicePage[AddInfo->ce], AddInfo->ce);

    if (cacheHitFlag == KAL_FALSE)
        writeMapCache(AddInfo,zoneOffset,bankOffset);

    return MTD_STATUS_NO_ERROR;
}


/****************************************************************************
 * Function:
 *
 * Parameters:  Spare - spare buffer, only FDM Data (about 8 bytes) inside
 *                      if Spare == NULL, mean the spare data is careless
 *
 * Returns:     Low 2 byte: error Page
 *              High 2 byte: error code
 * Description:
 *
 ****************************************************************************/
kal_int32 DAL_ProgramPage(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank, kal_uint16 PageAddr, kal_uint16 PageLength, kal_uint8 *Data, kal_uint8 *Spare)
{
    kal_uint8  m_idx = 0;
    kal_uint8  bk_idx_ce;
    kal_uint8  ce_idx = 0;
    kal_uint16 writingLen,writenLen,  i;
    kal_uint32 (*mtd_fp) (mtd_if_para*);
    kal_uint32 retVal = MTD_STATUS_NO_ERROR;
   	#if defined(__DEMAND_PAGING__) && !defined(__FUE__) && !defined(__UBL__)
    kal_uint32 LockLength = PageLength*Flash_Info.pageSize;
    #endif

    SNAND_TIME_INIT(2, PageLength);
    SNAND_TIME_RECORD(0);

		// Get demand lock before MTD lock to keep to avoid potential dead lock.
		// eg. Get MTD but can not get demand lock.
    #if defined(__DEMAND_PAGING__) && !defined(__FUE__) && !defined(__UBL__)
    if (Acc_Type == FAT_ACC) {
	    demp_lock_pages(DEMP_LOCK_NAND, (kal_uint32)Data, LockLength);
    }
    #endif

    get_MTD_lock();

    #if defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(__SPI_NAND_SUPPORT__))
    if (Acc_Type == FAT_ACC)
    {
        for (i=0;i< Flash_Info.bankNum; i++)
        {
            #if defined(__NANDFDM_TOTAL_BBM__)
            if(Bank[i]&BBM_GLOBAL_ADDR)
            {
            DAL_Bank_Array[i] = Bank[i];
            }
            else
            #endif //#if defined(__NANDFDM_TOTAL_BBM__)
	        if (ZoneNo == 0)
    	    {
                #if !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset;
                #else // !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset[CurDiskIndex];
                #endif //!defined(__NANDFDM_MULTI_INSTANCE__)
            }
            else
            {
                DAL_Bank_Array[i] = Bank[i];
            }
        }

        Bank = DAL_Bank_Array;

        #if !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum;
        #else // !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum[CurDiskIndex];
        #endif // !defined(__NANDFDM_MULTI_INSTANCE__)
    }
    #else
    if (Acc_Type != FAT_ACC)
    {
        dbg_ASSERT(0);

        #if defined (_NAND_FLASH_BOOTING_)
	    if (Acc_Type == FAT_ACC) {
    	    demp_unlock_pages(DEMP_LOCK_NAND, (kal_uint32)Data, LockLength);
	    }
        #endif

        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }
    #endif /* _NAND_FLASH_BOOTING_ || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && __SPI_NAND_SUPPORT__))*/

    /*boundary check*/
    if ( (ZoneNo >= Flash_Info.zoneNum) || ( PageAddr+PageLength > Flash_Info.bankNum*Flash_Info.blockPage ) )
    {
    	force_ASSERT(0,ZoneNo,(PageAddr+PageLength),0);

        #if defined(__DEMAND_PAGING__) && !defined(__FUE__) && !defined(__UBL__)
	    if (Acc_Type == FAT_ACC) {
	        demp_unlock_pages(DEMP_LOCK_NAND, (kal_uint32)Data, LockLength);
	    }
        #endif

        free_MTD_lock();

        return MTD_STATUS_PARA_ERROR;
    }

    writenLen = 0;
    kal_mem_set(&Mtd_para, 0x00,sizeof(Mtd_para));
    Add_Cnvt.zoneNum = ZoneNo ;
    Add_Cnvt.bankArry = Bank;

    while ( PageLength )
    {
        /*Get the mtd_fp, m_idx & writingLen*/
        mtd_fp = NULL;
        writingLen = 0;

        if (mtd_fp == NULL)
        {
            Add_Cnvt.pageIdx = PageAddr;
            addressMap(&Add_Cnvt);
            ce_idx = Add_Cnvt.ce;
            bk_idx_ce = PageAddr%Flash_Info.bankNum;

            for (m_idx=0; m_idx< MAX_MULTIPAGE_FUNCTION_NUM; m_idx++)
            {
                if ( Flash_Info.multiProgram[ce_idx][m_idx].func_p != NULL
                     && ((bk_idx_ce%Flash_Info.multiProgram[ce_idx][m_idx].startAlign) ==0))
                {
                    writingLen = (Flash_Info.multiProgram[ce_idx][m_idx].multiPageNum);
                    mtd_fp = MTD_Program;
                    break;
                }
            }
        }

        dbg_ASSERT(writingLen <= PageLength);
        dbg_ASSERT(writingLen == 1);
        dbg_ASSERT(mtd_fp != NULL);

        /* Fill Mtd_para*/
        Mtd_para.buff = &Data[(writenLen*Flash_Info.pageSize)];
        Mtd_para.spare = &Spare[0];
        Mtd_para.m_idx = m_idx;
        Mtd_para.length = writingLen;

        dbg_ASSERT(writingLen <= MAX_MULTIPAGE_NUM);

        for ( i = 0; i < writingLen; i++)
        {
            if (Acc_Type == RAW_ACC)
            {
		    	kal_uint32 ZoneLen;

			    ZoneLen = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);
		 	    Mtd_para.pageIdx[i] = ((ZoneNo*ZoneLen) + (Bank[0]*Flash_Info.bankNum)) * Flash_Info.blockPage + PageAddr + i;
		 	    Mtd_para.ce = 0;
		    }
            else
		    {
                Add_Cnvt.pageIdx = PageAddr+i;
                addressMap(&Add_Cnvt);
                Mtd_para.pageIdx[i] = Add_Cnvt.phyPage;
                Mtd_para.ce = Add_Cnvt.ce;
		    }

            if (Flash_Info.deviceInfo_CE[Add_Cnvt.ce].deviceSize*1024*1024 <= Flash_Info.pageSize*Add_Cnvt.phyPage)
            {
                dbg_ASSERT (0);

                #if defined(__DEMAND_PAGING__) && !defined(__FUE__) && !defined(__UBL__)
			    if (Acc_Type == FAT_ACC) {
                    demp_unlock_pages(DEMP_LOCK_NAND, (kal_uint32 )Data, LockLength);
			    }
                #endif

                free_MTD_lock();

                return MTD_STATUS_PARA_ERROR;
            }
        }

        #if defined DAL_VERIFICATION
        if (Fail_Bank != 0xFF)
        {   /*test case*/
            if (Fail_Bank >=PageAddr && Fail_Bank<(PageAddr+writingLen) )
                Mtd_Fail_Offset = Fail_Bank - PageAddr;
        }
        #endif

        Mtd_para.opFlag |= ONE_SPARE;

        /*call MTD function*/
        retVal = mtd_fp(&Mtd_para);

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__) )
		if ((PFTrigger==KAL_TRUE) && (PFTestCase & PF_DAL_TRIGGER)) {
			kal_uint8 Index, Count;

			PFTrigger = KAL_FALSE;
			for (Index=0; Index<writingLen; Index++) {
				Count=0;
				while (1) {
					if (ProgBadAddr[Count].Zone==0xff) {
						break;
					}
					if ( (ZoneNo==ProgBadAddr[Count].Zone) &&
						 ((Add_Cnvt.bankArry[(PageAddr+Index) % Flash_Info.bankNum]&(~BBM_GLOBAL_ADDR))==ProgBadAddr[Count].Block) &&
						 ((ProgBadAddr[Count].Page==0xffff) || (Add_Cnvt.pageIdx==ProgBadAddr[Count].Page)) )
					{
						retVal |= (0x01 << ((PageAddr+Index) % Flash_Info.bankNum));
            if(PF_EF_AutoTest== KAL_TRUE)
            {
              nandlog_print("Program Before PFTestCase:0x%X Block:0x%X Page:0x%X\r\n",PFTestCase,ProgBadAddr[Count].Block,Add_Cnvt.pageIdx );

              PFTestCase &=(~PFTrigerByTestCase);
              nandlog_print("Program After PFTestCase:0x%X Block:0x%X Page:0x%X\r\n",PFTestCase,ProgBadAddr[Count].Block,Add_Cnvt.pageIdx );

            }
					}
					Count++;
				}

			}
		}
#endif

        #if defined DAL_VERIFICATION
        if (Fail_Bank != 0xFF)
        {   /*test case*/
            if (Fail_Bank >=PageAddr && Fail_Bank<(PageAddr+writingLen) )
                Mtd_Fail_Offset = 0xFF; /*Reset*/
        }
        #endif

        if ( retVal != MTD_STATUS_NO_ERROR)
        {
            retVal = (retVal&0xFFFF0000)|((retVal&0x0000FFFF)<<(PageAddr%Flash_Info.bankNum));
            break;
        }

        /*set PageAddr & PageLength*/
        PageAddr += writingLen;
        writenLen += writingLen;
        PageLength -= writingLen;
    }

    #if defined(__DEMAND_PAGING__) && !defined(__FUE__) && !defined(__UBL__)
    if (Acc_Type == FAT_ACC) {
	    demp_unlock_pages(DEMP_LOCK_NAND, (kal_uint32 )Data, LockLength);
    }
    #endif

    free_MTD_lock();

    SNAND_TIME_RECORD(1);
    SNAND_dbg_time_add_record(SNAND_SW_LAYER_DAL, SNAND_DEV_PROGRAM, SNAND_TIME_GET_DURATION_US(0, 1));

    return retVal;
}


/****************************************************************************
 * Function:
 *
 * Parameters:  Spare - spare buffer, it will put all the spare data of the page
 *
 * Returns:     Low 2 byte: error code
 *              High 2 byte: error Page
 * Description:
 *
 ****************************************************************************/
kal_int32 DAL_ReadPage_internal(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank, kal_uint16 PageAddr, kal_uint16 PageLength, kal_uint8 *Data, kal_uint8 *Spare)
{
    kal_uint16  readingLen,Done_Len, i;
    kal_uint32 (*mtd_fp) (mtd_if_para*);
    kal_uint32 retVal = MTD_STATUS_NO_ERROR, mtd_retVal;

    get_MTD_lock();

    #if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
    {
        RTC_CTRL_GET_TIME_T rtc_time_local;
        kal_uint32 duration;

        if (KAL_TRUE == g_snand_trr_bootup_time_recorded)
        {
            snand_trr_test_get_rtc_time((DCL_CTRL_DATA_T *)&rtc_time_local);

            if (rtc_time_local.u1Sec > g_snand_trr_rtc_time.u1Sec)
            {
                duration = rtc_time_local.u1Sec - g_snand_trr_rtc_time.u1Sec;
            }
            else
            {
                duration = g_snand_trr_rtc_time.u1Sec - rtc_time_local.u1Sec;
            }

            if ((duration > 30) ||
                (g_snand_trr_rtc_time.u1Min < rtc_time_local.u1Min) ||
                (g_snand_trr_rtc_time.u1Hour < rtc_time_local.u1Hour))
            {
                snand_trr_test_wdt_reset();
            }
        }
    }
    #endif  // __SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__

    #if defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(__SPI_NAND_SUPPORT__))
    if (Acc_Type == FAT_ACC)
    {
        for (i=0;i< Flash_Info.bankNum; i++)
        {
            #if defined(__NANDFDM_TOTAL_BBM__)
            if(Bank[i]&BBM_GLOBAL_ADDR)
            {
                DAL_Bank_Array[i] = Bank[i];
            }
            else
            #endif //#if defined(__NANDFDM_TOTAL_BBM__)
	        if (ZoneNo == 0)
	        {
                #if !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset;
                #else // !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset[CurDiskIndex];
                #endif // !defined(__NANDFDM_MULTI_INSTANCE__)
	        } else {
                DAL_Bank_Array[i] = Bank[i];
	        }
        }

        Bank = DAL_Bank_Array;

        #if !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum;
        #else  // !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum[CurDiskIndex];
        #endif	// !defined(__NANDFDM_MULTI_INSTANCE__)
    }
    #else
    if (Acc_Type != FAT_ACC)
    {
        dbg_ASSERT(0);

        free_MTD_lock();

        return MTD_STATUS_PARA_ERROR;
    }
    #endif /* _NAND_FLASH_BOOTING_ || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && __SPI_NAND_SUPPORT__)) */

    /*boundary check*/
    if ( (ZoneNo >= Flash_Info.zoneNum) || ( PageAddr+PageLength > Flash_Info.bankNum*Flash_Info.blockPage ) )
    {
    	force_ASSERT(0,ZoneNo,(PageAddr+PageLength),0);

        free_MTD_lock();

        return MTD_STATUS_PARA_ERROR;
    }

    Done_Len = 0;
    kal_mem_set(&Mtd_para, 0x00,sizeof(Mtd_para));
    Add_Cnvt.zoneNum = ZoneNo ;
    Add_Cnvt.bankArry = Bank;

    while ( PageLength )
    {
        /*Get the mtd_fp, m_idx & readingLen*/
        readingLen = 1;
        mtd_fp = MTD_Read;

        /* Fill Mtd_para*/
        Mtd_para.buff = &Data[(Done_Len*Flash_Info.pageSize)];

        if (Spare==NULL) {

        	Mtd_para.spare = NULL;
        } else {
	        Mtd_para.spare = &Spare[(Done_Len*Flash_Info.spareSize)];
        }

        Mtd_para.length = readingLen;

        for ( i = 0; i < readingLen; i++)
        {
            Add_Cnvt.pageIdx = PageAddr+i;
            addressMap(&Add_Cnvt);
            Mtd_para.pageIdx[i] = Add_Cnvt.phyPage;
            Mtd_para.ce = Add_Cnvt.ce;

            if (Flash_Info.deviceInfo_CE[Add_Cnvt.ce].deviceSize*1024*1024 <= Flash_Info.pageSize*Add_Cnvt.phyPage)
            {
                dbg_ASSERT (0);
                free_MTD_lock();
                return MTD_STATUS_PARA_ERROR;
            }
        }

        #if defined DAL_VERIFICATION
        if (Fail_Bank != 0xFF)
        {   /*test case*/
            if (Fail_Bank >=PageAddr && Fail_Bank<(PageAddr+readingLen) )
                Mtd_Fail_Offset = Fail_Bank - PageAddr;
        }
        #endif

        /*call MTD function*/
        mtd_retVal = mtd_fp(&Mtd_para);

        #if defined DAL_VERIFICATION
        if (Fail_Bank != 0xFF)
        {   /*test case*/
            if (Fail_Bank >=PageAddr && Fail_Bank<(PageAddr+readingLen) )
                Mtd_Fail_Offset = 0xFF; /*Reset*/
        }
        #endif

        if (mtd_retVal != MTD_STATUS_NO_ERROR)
        {
            retVal |= (mtd_retVal&0xFFFF0000)|((mtd_retVal&0x0000FFFF)<<(PageAddr%Flash_Info.bankNum));
            //break;/*Do not stop even read error*/
        }

        /*set PageAddr & PageLength*/
        PageAddr += readingLen;
        Done_Len += readingLen;
        PageLength -= readingLen;
    }

    free_MTD_lock();

    return retVal;
}

//if read fail, retry twice
kal_int32 DAL_ReadPage(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank, kal_uint16 PageAddr, kal_uint16 PageLength, kal_uint8 *Data, kal_uint8 *Spare)
{
	kal_uint32 retVal = MTD_STATUS_NO_ERROR;
	kal_uint32 trycount = 0;
    #if defined(__SNAND_DEBUG__)
    kal_uint32 lr;
    #endif

    SNAND_TIME_INIT(2, PageLength);

    #if defined(__SNAND_DEBUG__)
    SNAND_GET_RETURN_ADDRESS(lr);
    #endif

    SNAND_TIME_RECORD(0);

	retVal = DAL_ReadPage_internal(Acc_Type, ZoneNo, Bank, PageAddr, PageLength, Data, Spare);

	if ((retVal & 0xffff0000) == MTD_STATUS_ERROR)
	{

DAL_ReadPage_Retry_R:

		trycount++;

        #if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
            #if defined(__SNAND_DEBUG__)
                nandlog_print("DAL_ReadPage Retry %d time, lr: %x\r\n", trycount, lr);
            #else
                nandlog_print("DAL_ReadPage Retry %d time\r\n", trycount);
            #endif
        #endif

		if ((DAL_ReadPage_internal(Acc_Type, ZoneNo, Bank, PageAddr, PageLength, Data, Spare)& 0xffff0000) == MTD_STATUS_ERROR)
		{
			if (trycount < 3)
			{
				goto DAL_ReadPage_Retry_R;
			}
		}
	}
	//return first time read return value, even second time read succeed.
	//when first time read fail, caller will know this page is risky.

    SNAND_TIME_RECORD(1);
    SNAND_dbg_time_add_record(SNAND_SW_LAYER_DAL, SNAND_DEV_READ, SNAND_TIME_GET_DURATION_US(0, 1));

	return retVal;
}
/****************************************************************************
 * Function:    DAL_CopyPage
 *
 * Parameters:  kal_uint8 ZoneNo     The Zone number
 *              kal_uint16 *srcBank  The copy source bank array
 *              kal_uint16 *dstBank  The copy source bank array
 *              kal_uint16 PageLength The desired copy length (unit by page)
 *              kal_uint8 *Data_buff   copy function Working buffer
 *              kal_uint8 *Spare_buff  copy function Working buffer
 *              kal_uint32 buff_len  Working buffer length, unit by page
 *              kal_uint8  SDataNumber - The number of Upper layer sending Data in Spare_buff,
 *                                      if >= 1 means dst spare should be assigned with data in Spare_buff
 * Returns:     Low 2 byte: error code
 *              High 2 byte: error Page
 * Description: [Important Note]: If PageLength > 1 The source pages should have the same spare content!
 *
 ****************************************************************************/
kal_int32 DAL_CopyPage(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *srcBank, kal_uint16 *dstBank, kal_uint16 srcPageAddr, kal_uint16 dstPageAddr, kal_uint16 PageLength, kal_uint8 *Data_buff, kal_uint8 *Spare_buff, kal_uint32 buff_len, kal_uint8 SDataNumber)
{
    kal_bool   fgNeedCheckBound = KAL_TRUE;
    kal_uint8  m_idx = 0;
    kal_uint8  bCurrZone;
    kal_uint16 writingLen, i;
    kal_uint16 *pCurrSrcBank,*pCurrDstBank;

    kal_uint32 (*mtd_program_fp) (mtd_if_para*);
    kal_uint32 retVal= MTD_STATUS_NO_ERROR, mtd_retVal;
    bCurrZone = ZoneNo;
    pCurrSrcBank = srcBank;
    pCurrDstBank = dstBank;
    writingLen = 0;

    while ( PageLength )
    {
        get_MTD_lock();

        #if defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(__SPI_NAND_SUPPORT__))
        if (Acc_Type == FAT_ACC)
        {
            for (i=0;i< Flash_Info.bankNum; i++)
            {
                #if (defined(__NANDFDM_TOTAL_BBM__) && defined(__NANDFDM_MULTI_INSTANCE__))
                if(srcBank[i]&BBM_GLOBAL_ADDR)
                {
                    DAL_Bank_Array[i] = srcBank[i];
                }
                else
                {
                    if (ZoneNo == 0)
                    {
                        DAL_Bank_Array[i] = srcBank[i] + FAT_Start_Section_Offset[CurDiskIndex];
                    }
                    else
                    {
                        DAL_Bank_Array[i] = srcBank[i];
                    }
                }

                if(dstBank[i]&BBM_GLOBAL_ADDR)
                {
                    DAL_Bank_Array2[i] = dstBank[i];
                }
                else
                {
                    if (ZoneNo == 0)
                    {
                        DAL_Bank_Array2[i] = dstBank[i] + FAT_Start_Section_Offset[CurDiskIndex];
                    } else {
                        DAL_Bank_Array2[i] = dstBank[i];
                    }
                }
                #else
    	        if (ZoneNo == 0)
    	        {
                    #if !defined(__NANDFDM_MULTI_INSTANCE__)
                    DAL_Bank_Array[i] = srcBank[i] + FAT_Start_Section_Offset;
                    DAL_Bank_Array2[i] = dstBank[i] + FAT_Start_Section_Offset;
                    #else  // !defined(__NANDFDM_MULTI_INSTANCE__)
                    DAL_Bank_Array[i] = srcBank[i] + FAT_Start_Section_Offset[CurDiskIndex];
                    DAL_Bank_Array2[i] = dstBank[i] + FAT_Start_Section_Offset[CurDiskIndex];
                    #endif // !defined(__NANDFDM_MULTI_INSTANCE__)
    	        } else {
                    DAL_Bank_Array[i] = srcBank[i];
                    DAL_Bank_Array2[i] = dstBank[i];
    	        }
                #endif //#if defined(__NANDFDM_TOTAL_BBM__)
            }

            pCurrSrcBank = DAL_Bank_Array;
            pCurrDstBank = DAL_Bank_Array2;

            #if !defined(__NANDFDM_MULTI_INSTANCE__)
            bCurrZone = ZoneNo + FAT_Start_ZoneNum;
            #else  // !defined(__NANDFDM_MULTI_INSTANCE__)
            bCurrZone = ZoneNo +  FAT_Start_ZoneNum[CurDiskIndex];
            #endif // !defined(__NANDFDM_MULTI_INSTANCE__)
        }
        #else
        if (Acc_Type != FAT_ACC)
        {
            dbg_ASSERT(0);
            free_MTD_lock();
            return MTD_STATUS_PARA_ERROR;
        }
        #endif /* _NAND_FLASH_BOOTING || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && __SPI_NAND_SUPPORT__)) */

        if (fgNeedCheckBound == KAL_TRUE)
        {
            fgNeedCheckBound = KAL_FALSE;

            /*parameter check*/
            if ( bCurrZone >= Flash_Info.zoneNum || srcPageAddr+PageLength > Flash_Info.bankNum*Flash_Info.blockPage ||
                 dstPageAddr+PageLength > Flash_Info.bankNum*Flash_Info.blockPage ||
                 (srcPageAddr%Flash_Info.bankNum) != (dstPageAddr%Flash_Info.bankNum) || SDataNumber >= Flash_Info.spareSize)
            {
                force_ASSERT(0,bCurrZone,(srcPageAddr+PageLength),0);
                free_MTD_lock();
                return MTD_STATUS_PARA_ERROR;
            }
        }

        if (SDataNumber > 0)
        {
            // For SPI-NAND, SDataNumber must be 6 to align spare data format for FDM (Use magic number temporarily, need improvement)
            if (6 != SDataNumber)
            {
                dbg_ASSERT(0);
            }

            DAL_SetFDMData(0, 0, FDMDATA_EMPTY, DAL_spare_buff);

            {
                kal_uint16 val;

                val = DAL_GetFDMData(FDMDATA_BM, (kal_uint32 *)Spare_buff);
                DAL_SetFDMData(val, 0, FDMDATA_BM, DAL_spare_buff);

                val = DAL_GetFDMData(FDMDATA_PA, (kal_uint32 *)Spare_buff);
                DAL_SetFDMData(val, 0, FDMDATA_PA, DAL_spare_buff);

                val = DAL_GetFDMData(FDMDATA_LBA, (kal_uint32 *)Spare_buff);
                DAL_SetFDMData(0, val, FDMDATA_LBA, DAL_spare_buff);
            }
        }

        /*read + write method*/
        Add_Cnvt.zoneNum = bCurrZone ;

        /*Get the mtd_program_fp, m_idx & writingLen*/
        mtd_program_fp = MTD_Program;
        writingLen = 1;

        dbg_ASSERT(writingLen <= PageLength);
        dbg_ASSERT(mtd_program_fp != NULL);

        /*here get all information to process multi-page write, now read data out*/

        /* Fill Mtd_para*/
        kal_mem_set(&Mtd_para, 0x00,sizeof(Mtd_para));

        Mtd_para.length = 1; /*single read only*/
        Add_Cnvt.bankArry = pCurrSrcBank;

        for (i = 0; i < writingLen; i++)
        {
            Add_Cnvt.pageIdx = srcPageAddr+i;
            addressMap(&Add_Cnvt);
            Mtd_para.pageIdx[0] = Add_Cnvt.phyPage;
            Mtd_para.ce = Add_Cnvt.ce;
            Mtd_para.buff = &Data_buff[ i*Flash_Info.pageSize ];

      	    if (SDataNumber>0) {
	            Mtd_para.spare = &Spare_buff[0];
      		} else {
	            Mtd_para.spare = &Spare_buff[ i*Flash_Info.spareSize ];
      		}

            if (Flash_Info.deviceInfo_CE[Add_Cnvt.ce].deviceSize*1024*1024 <= Flash_Info.pageSize*Add_Cnvt.phyPage)
            {
                dbg_ASSERT (0);
                free_MTD_lock();
                return MTD_STATUS_PARA_ERROR;
            }

            /*call MTD_Read function*/
            mtd_retVal = MTD_Read(&Mtd_para);

            if ((mtd_retVal & 0xffff0000) == MTD_STATUS_ERROR)
            {
            	kal_uint8 try_count = 0;

DAL_COPY_PAGE_RETRY:

            	//re-try to read the same page when read fail.
            	if (try_count < 3)
            	{
				    #if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
            		nandlog_print("DAL_CopyPage Retry %d time\r\n", try_count);
				    #endif

	            	mtd_retVal = MTD_Read(&Mtd_para);

					if ((mtd_retVal & 0xffff0000) == MTD_STATUS_ERROR)
					{
						try_count++;
						goto DAL_COPY_PAGE_RETRY;
					}
            	}
            }
        }

        /*Now process the write part*/

        /* Fill Mtd_para*/
        kal_mem_set(&Mtd_para, 0x00,sizeof(Mtd_para));
        Mtd_para.buff = Data_buff;
        Mtd_para.spare = (SDataNumber > 0 ? (kal_uint8*)DAL_spare_buff : Spare_buff);
        Mtd_para.m_idx = m_idx;
        Mtd_para.length = writingLen;
        Add_Cnvt.bankArry = pCurrDstBank;

        for ( i = 0; i < writingLen; i++)
        {
            Add_Cnvt.pageIdx = dstPageAddr+i;
            addressMap(&Add_Cnvt);
            Mtd_para.pageIdx[i] = Add_Cnvt.phyPage;
            Mtd_para.ce = Add_Cnvt.ce;

            if (Flash_Info.deviceInfo_CE[Add_Cnvt.ce].deviceSize*1024*1024 <= Flash_Info.pageSize*Add_Cnvt.phyPage)
            {
                dbg_ASSERT (0);
                free_MTD_lock();
                return MTD_STATUS_PARA_ERROR;
            }
        }

        #if defined DAL_VERIFICATION
        if (Fail_Bank != 0xFF)
        {   /*test case*/
            if (Fail_Bank >=srcPageAddr && Fail_Bank<(srcPageAddr+writingLen) )
                Mtd_Fail_Offset = Fail_Bank - srcPageAddr;
        }
        #endif

        /*call MTD function*/
        if (SDataNumber>0) {
	        Mtd_para.opFlag |= ONE_SPARE;
        } else {
	        Mtd_para.opFlag &= (~ONE_SPARE);
        }

        mtd_retVal = mtd_program_fp(&Mtd_para);

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((PFTrigger==KAL_TRUE) && (PFTestCase & PF_DAL_TRIGGER)) {
			kal_uint8 Index, Count;

			PFTrigger = KAL_FALSE;
			for (Index=0; Index<writingLen; Index++) {
				Count=0;
				while (1) {
					if (ProgBadAddr[Count].Zone==0xff) {
						break;
					}
					if ( (bCurrZone==ProgBadAddr[Count].Zone) &&
						 ((Add_Cnvt.bankArry[(dstPageAddr+Index) % Flash_Info.bankNum]&(~BBM_GLOBAL_ADDR))==ProgBadAddr[Count].Block) &&
						 ((ProgBadAddr[Count].Page==0xffff) || (Add_Cnvt.pageIdx==ProgBadAddr[Count].Page)) )
					{
						retVal |= (0x01 << ((dstPageAddr+Index) % Flash_Info.bankNum));
            if(PF_EF_AutoTest== KAL_TRUE)
            {
              nandlog_print("Copy Before PFTestCase:0x%X Block:0x%X Page:0x%X\r\n",PFTestCase,ProgBadAddr[Count].Block,Add_Cnvt.pageIdx );

              PFTestCase &=(~PFTrigerByTestCase);
              nandlog_print("Copy After PFTestCase:0x%X Block:0x%X Page:0x%X\r\n",PFTestCase,ProgBadAddr[Count].Block,Add_Cnvt.pageIdx );


            }
					}
					Count++;
				}

			}
		}
#endif

        #if defined DAL_VERIFICATION
        if (Fail_Bank != 0xFF)
        {   /*test case*/
            if (Fail_Bank >=srcPageAddr && Fail_Bank<(srcPageAddr+writingLen) )
                Mtd_Fail_Offset = 0xFF; /*Reset*/
        }
        #endif

        if ( mtd_retVal != MTD_STATUS_NO_ERROR)
        {
            retVal |= (mtd_retVal&0xFFFF0000)|((mtd_retVal&0x0000FFFF)<<(dstPageAddr%Flash_Info.bankNum));
            break;
        }

        /*set PageAddr & PageLength*/
        srcPageAddr += writingLen;
        dstPageAddr += writingLen;
        PageLength -= writingLen;

        free_MTD_lock();
    }

    return retVal;
}

/****************************************************************************
 * Function:
 *
 * Parameters:
 *
 * Returns:     Low 2 byte: error code
 *              High 2 byte: error Page
 * Description:
 *
 ****************************************************************************/
kal_int32 DAL_EraseBlock(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank,kal_uint8 start, kal_uint8 length)
{
    kal_uint8  m_idx = 0;
    kal_uint8  bk_idx_ce;
    kal_uint8  ce_idx = 0;
    kal_uint8  erasingLen, i;
    kal_uint32 (*mtd_fp) (mtd_if_para*);
    kal_uint32 retVal = MTD_STATUS_NO_ERROR;

    SNAND_TIME_INIT(2, 1);
    SNAND_TIME_RECORD(0);

    get_MTD_lock();

    #if defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(__SPI_NAND_SUPPORT__))
    if (Acc_Type == FAT_ACC)
    {
        for (i=0;i< Flash_Info.bankNum; i++)
        {
            #if defined(__NANDFDM_TOTAL_BBM__)
            if(Bank[i]&BBM_GLOBAL_ADDR)
            {
                DAL_Bank_Array[i] = Bank[i];
            }
            else
            #endif //#if defined(__NANDFDM_TOTAL_BBM__)
	        if (ZoneNo == 0)
	        {
                #if !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset;
                #else // !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset[CurDiskIndex];
                #endif //!defined(__NANDFDM_MULTI_INSTANCE__)
	        } else {
                DAL_Bank_Array[i] = Bank[i];
	        }
        }

        Bank = DAL_Bank_Array;

        #if !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum;
        #else // !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum[CurDiskIndex];
        #endif //!defined(__NANDFDM_MULTI_INSTANCE__)
    }
    #else
    if (Acc_Type != FAT_ACC)
    {
        dbg_ASSERT(0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }
    #endif /* _NAND_FLASH_BOOTING_ || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && __SPI_NAND_SUPPORT__)) */

    /*boundary check*/
    if ( ZoneNo >= Flash_Info.zoneNum || start+length > Flash_Info.bankNum )
    {
        force_ASSERT(0,ZoneNo,0,0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }

    kal_mem_set(&Mtd_para, 0x00,sizeof(Mtd_para));
    Add_Cnvt.zoneNum = ZoneNo ;
    Add_Cnvt.bankArry = Bank;

    while ( length )
    {
        /*Get the mtd_fp, m_idx & erasingLen*/
        mtd_fp = NULL;
        erasingLen = 0;
        Add_Cnvt.pageIdx = start;
        addressMap(&Add_Cnvt);
        ce_idx = Add_Cnvt.ce;
        bk_idx_ce = start%Flash_Info.bankNum;

        for (m_idx=0; m_idx< MAX_MULTIPAGE_FUNCTION_NUM; m_idx++)
        {
            if ( Flash_Info.multiErase[ce_idx][m_idx].func_p != NULL
                 && ((bk_idx_ce%Flash_Info.multiErase[ce_idx][m_idx].startAlign) ==0)
                 && length >= Flash_Info.multiErase[ce_idx][m_idx].multiPageNum )
            {
                erasingLen = (Flash_Info.multiErase[ce_idx][m_idx].multiPageNum);
                mtd_fp = MTD_Erase;
                break;
            }
        }

        /*here m_idx point to the corresponding multiErase function */
        dbg_ASSERT(erasingLen < MAX_MULTIPAGE_NUM);
        dbg_ASSERT(erasingLen <= length);
        dbg_ASSERT(mtd_fp != NULL);

        /* Fill Mtd_para*/
        Mtd_para.buff = NULL;
        Mtd_para.spare = NULL;
        Mtd_para.m_idx = m_idx;
        Mtd_para.length = erasingLen;

        for ( i = 0; i < erasingLen; i++)
        {
            if (Acc_Type == RAW_ACC) {
		    	kal_uint32 ZoneLen;

			    ZoneLen = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);
		 	    Mtd_para.pageIdx[i] = ((ZoneNo*ZoneLen) + (Bank[0]*Flash_Info.bankNum) + start + i)* Flash_Info.blockPage;
		 	    Mtd_para.ce = 0;
		    } else {
	            Add_Cnvt.pageIdx = start + i; /*first page of block*/
	            addressMap(&Add_Cnvt);
	            Mtd_para.pageIdx[i] = Add_Cnvt.phyPage;
	            Mtd_para.ce = Add_Cnvt.ce;
		    }

            if (Flash_Info.deviceInfo_CE[Add_Cnvt.ce].deviceSize*1024*1024 <= Flash_Info.pageSize*Add_Cnvt.phyPage)
            {
                dbg_ASSERT (0);
                free_MTD_lock();
                return MTD_STATUS_PARA_ERROR;
            }
        }

        #if defined DAL_VERIFICATION
        if (Fail_Bank != 0xFF)
        {   /*test case*/
            if (Fail_Bank >=start && Fail_Bank<(start+erasingLen) )
                Mtd_Fail_Offset = Fail_Bank - start;
        }
        #endif

        /*call MTD function*/
        retVal = mtd_fp(&Mtd_para);
        #if defined DAL_VERIFICATION
        if (Fail_Bank != 0xFF)
        {   /*test case*/
            if (Fail_Bank >=start && Fail_Bank<(start+erasingLen) )
                Mtd_Fail_Offset = 0xFF; /*Reset*/
        }
        #endif

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))
		if ((EFTrigger==KAL_TRUE) && (EFTestCase & EF_DAL_TRIGGER)) {
			kal_uint8 Index, Count;

			EFTrigger = KAL_FALSE;
			for (Index=0; Index<erasingLen; Index++) {
				Count=0;
				while (1) {
					if (EraseBadAddr[Count].Zone==0xff) {
						break;
					}
					if ( (ZoneNo==EraseBadAddr[Count].Zone) &&
						 ((Add_Cnvt.bankArry[start+Index]&(~BBM_GLOBAL_ADDR))==EraseBadAddr[Count].Block) &&
						 ((start+Index)==EraseBadAddr[Count].Bank) )
					{
						retVal |= (0x01 << (start+Index));
            if(PF_EF_AutoTest==KAL_TRUE)
            {
              nandlog_print("Before EFTestCase:0x%X \r\n",EFTestCase);

              EFTestCase &=(~EFTrigerByTestCase);
              nandlog_print("After EFTestCase:0x%X \r\n",EFTestCase);


            }
					}
					Count++;
				}

			}
		}
#endif

        if ( retVal != MTD_STATUS_NO_ERROR)
        {
            retVal = (retVal&0xFFFF0000)|((retVal&0x0000FFFF)<<start);
            break;
        }

        start += erasingLen;
        length -= erasingLen;
    }

    free_MTD_lock();

    SNAND_TIME_RECORD(1);
    SNAND_dbg_time_add_record(SNAND_SW_LAYER_DAL, SNAND_DEV_ERASE, SNAND_TIME_GET_DURATION_US(0, 1));

    return retVal;
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
kal_int32 DAL_MarkBlockBad(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank,kal_uint8 Block_offset, kal_bool EraseBlock, kal_uint32 *Data_buff, kal_uint32 *Spare_buff)
{
    kal_uint8  m_idx = 0;
    kal_uint8  ce_idx = 0;
   	kal_uint32 ZoneLen = 0;

    get_MTD_lock();

    #if defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(__SPI_NAND_SUPPORT__))
    if (Acc_Type == FAT_ACC)
    {
	    kal_uint8  i;
        for (i=0;i< Flash_Info.bankNum; i++)
        {
            #if defined(__NANDFDM_TOTAL_BBM__)
            if(Bank[i]&BBM_GLOBAL_ADDR)
            {
                DAL_Bank_Array[i] = Bank[i];
            }
            else
            #endif //#if defined(__NANDFDM_TOTAL_BBM__)
	        if (ZoneNo == 0)
	        {
                #if !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset;
                #else // !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset[CurDiskIndex];
                #endif //!defined(__NANDFDM_MULTI_INSTANCE__)
	        } else {
                DAL_Bank_Array[i] = Bank[i];
	        }
        }

        Bank = DAL_Bank_Array;
        #if !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum;
        #else // !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum[CurDiskIndex];
        #endif //!defined(__NANDFDM_MULTI_INSTANCE__)
    }
    #else
    if (Acc_Type != FAT_ACC)
    {
        dbg_ASSERT(0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }
    #endif /* _NAND_FLASH_BOOTING || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && __SPI_NAND_SUPPORT__)) */

    /*boundary check*/
    if ( ZoneNo >= Flash_Info.zoneNum || Block_offset >= Flash_Info.bankNum )
    {
        force_ASSERT(0,ZoneNo,0,0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }

    if (Acc_Type == RAW_ACC) {
	    ZoneLen = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);
    }

    kal_mem_set(&Mtd_para, 0x00,sizeof(Mtd_para));
    Add_Cnvt.zoneNum = ZoneNo ;
    Add_Cnvt.bankArry = Bank;
    Add_Cnvt.pageIdx = Block_offset; /*first page of block*/
    addressMap(&Add_Cnvt);

    if (Flash_Info.deviceInfo_CE[Add_Cnvt.ce].deviceSize*1024*1024 <= Flash_Info.pageSize*Add_Cnvt.phyPage)
    {
        dbg_ASSERT (0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }

    if (EraseBlock == KAL_TRUE)
    {
        ce_idx = Add_Cnvt.ce;

        for (m_idx=0; m_idx< MAX_MULTIPAGE_FUNCTION_NUM; m_idx++)
        {
            if ( 1 == Flash_Info.multiErase[ce_idx][m_idx].multiPageNum
                 && Flash_Info.multiErase[ce_idx][m_idx].func_p != NULL)
                break;
        }

        dbg_ASSERT( m_idx != MAX_MULTIPAGE_FUNCTION_NUM );

        /* Fill Mtd_para*/
        Mtd_para.buff = NULL;
        Mtd_para.spare = NULL;
        Mtd_para.m_idx = m_idx;
        Mtd_para.length = 1;

	    if (Acc_Type == RAW_ACC) {
	 	    Mtd_para.pageIdx[0] = ((ZoneNo*ZoneLen) + (Bank[0]*Flash_Info.bankNum) + Block_offset) * Flash_Info.blockPage;
	 	    Mtd_para.ce = 0;
	    }
        else
	    {
            Mtd_para.pageIdx[0] = Add_Cnvt.phyPage;
            Mtd_para.ce = Add_Cnvt.ce;
	    }

        MTD_Erase(&Mtd_para);
    }

    /*Read the target page back*/
    /* Fill Mtd_para*/
    kal_mem_set(&Mtd_para, 0x00,sizeof(Mtd_para));
    Mtd_para.length = 1; /*single read only*/
    Mtd_para.m_idx = 0; /*No use*/

    if (Acc_Type == RAW_ACC) {
 	    Mtd_para.pageIdx[0] = ((ZoneNo*ZoneLen) + (Bank[0]*Flash_Info.bankNum) + Block_offset) * Flash_Info.blockPage;
 	    Mtd_para.ce = 0;

    }
    else
    {
        Mtd_para.pageIdx[0] = Add_Cnvt.phyPage;
        Mtd_para.ce = Add_Cnvt.ce;
 	}

    Mtd_para.buff = (kal_uint8*)&Data_buff[0];
    Mtd_para.spare = (kal_uint8*)&Spare_buff[0];

    MTD_Read(&Mtd_para);

    ((kal_uint8 *)Spare_buff)[0] = 0x00;
    SNAND_COMMON_SetBadBlockMark(SNAND_COMMON_GetBadBlockMark(Spare_buff) & FDM_BAD_BLOCK_MARK_2K, Spare_buff); // use &= to adapte the original mark, ex: 0x00(early bad)

    /* Fill Mtd_para*/
    Mtd_para.buff = (kal_uint8*)Data_buff;
    Mtd_para.spare =(kal_uint8*) Spare_buff;
    Mtd_para.m_idx = 0; /*No use*/
    Mtd_para.length = 1; /*No use*/

    if (Acc_Type == RAW_ACC)
    {
 	    Mtd_para.pageIdx[0] = ((ZoneNo*ZoneLen) + (Bank[0]*Flash_Info.bankNum) + Block_offset) * Flash_Info.blockPage;
 	    Mtd_para.ce = 0;
    }
    else
    {
        Mtd_para.pageIdx[0] = Add_Cnvt.phyPage;
        Mtd_para.ce = Add_Cnvt.ce;
	}

    MTD_MarkBlockBad(&Mtd_para);

    free_MTD_lock();

    return MTD_STATUS_NO_ERROR;
}

/****************************************************************************
 * Function:
 *
 * Parameters:   kal_bool newFlash This flag make condition to check: if BI != 0xFF_FF, it's early bad
 *
 * Returns:      MTD_STATUS_NO_ERROR - The block is a good block
 *               MTD_STATUS_EARLY_BAD - The block is a bad block of early bad
 *               MTD_STATUS_FDM_BAD - The block is a bad block of FDM bad
 *               (MTD_STATUS_EARLY_BAD|MTD_STATUS_FDM_BAD)
 * Description:
 *
 ****************************************************************************/
kal_int32 DAL_CheckBadBlock (DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank,kal_uint8 Block_offset, kal_bool newFlash, kal_uint32 *Data_buff, kal_uint32 *Spare_buff)
{
    kal_uint32 mtd_retVal, retVal = MTD_STATUS_NO_ERROR;
    kal_bool FirstCheck = KAL_TRUE;

    get_MTD_lock();

    #if defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(__SPI_NAND_SUPPORT__))
    if (Acc_Type == FAT_ACC)
    {
	    kal_uint8 i;

        for (i=0;i< Flash_Info.bankNum; i++)
        {
            #if defined(__NANDFDM_TOTAL_BBM__)
            if(Bank[i]&BBM_GLOBAL_ADDR)
            {
                DAL_Bank_Array[i] = Bank[i];
            }
            else
            #endif //#if defined(__NANDFDM_TOTAL_BBM__)
	        if (ZoneNo == 0)
	        {
                #if !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset;
                #else  // !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset[CurDiskIndex];
                #endif  // !defined(__NANDFDM_MULTI_INSTANCE__)
	        }
            else
	        {
                DAL_Bank_Array[i] = Bank[i];
	        }
        }

        Bank = DAL_Bank_Array;

        #if !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum;
        #else  // !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum[CurDiskIndex];
        #endif  // !defined(__NANDFDM_MULTI_INSTANCE__)
    }
    #else
    if (Acc_Type != FAT_ACC)
    {
        dbg_ASSERT(0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }
    #endif /* _NAND_FLASH_BOOTING_ || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && __SPI_NAND_SUPPORT__)) */
    /*boundary check*/
    if ( ZoneNo >= Flash_Info.zoneNum || Block_offset >= Flash_Info.bankNum )
    {
        force_ASSERT(0,ZoneNo,0,0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }

    kal_mem_set(&Mtd_para, 0x00,sizeof(Mtd_para));
    Add_Cnvt.zoneNum = ZoneNo ;
    Add_Cnvt.bankArry = Bank;
    Add_Cnvt.pageIdx = Block_offset; /*first page of block*/
    addressMap(&Add_Cnvt);

    if (Flash_Info.deviceInfo_CE[Add_Cnvt.ce].deviceSize*1024*1024 <= Flash_Info.pageSize*Add_Cnvt.phyPage)
    {
        dbg_ASSERT (0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }

    /* Fill Mtd_para*/
    Mtd_para.buff = (kal_uint8*)Data_buff;
    Mtd_para.spare = (kal_uint8*)Spare_buff;
    Mtd_para.m_idx = 0; /*No use*/
    Mtd_para.length = 1; /*No use*/

    if (Acc_Type == RAW_ACC)
    {
    	kal_uint32 ZoneLen;

	    ZoneLen = zonePage(0);
 	    Mtd_para.pageIdx[0] = ((ZoneNo*ZoneLen) + (Bank[0]*Flash_Info.bankNum) + Block_offset) * Flash_Info.blockPage;
	    Mtd_para.ce = 0;
    }
    else
    {
	    Mtd_para.pageIdx[0] = Add_Cnvt.phyPage; /*2k page need to check 2nd page in newFlash case*/
	    Mtd_para.ce = Add_Cnvt.ce;
    }

MTD_BB_CHECK:

    mtd_retVal = MTD_CheckBlockBad(&Mtd_para);  // read vendor's bad block mark

    if (mtd_retVal != MTD_STATUS_NO_ERROR) /*no early bad mark in MTD, check the FDM mark whether be OK*/
    {
        retVal |= MTD_STATUS_EARLY_BAD;
    }

    if (0xFFFF != SNAND_COMMON_GetBadBlockMark(Spare_buff))
    {
        retVal |= MTD_STATUS_FDM_BAD;
    }

    if (FirstCheck == KAL_TRUE) // TODO: CONFIRM NEW FLASH FLOW
    {
    	FirstCheck = KAL_FALSE;

	    if (newFlash == KAL_TRUE)
	    {
	        if (Flash_Info.pageSize == 512)
	        {
	            if ( ((FDMData_512*)Spare_buff)->BI != 0xFF )
	            {
	                retVal |= MTD_STATUS_EARLY_BAD;
	            }

	            if ( (retVal & MTD_STATUS_EARLY_BAD) != MTD_STATUS_EARLY_BAD )
	            {
	                Mtd_para.pageIdx[0] ++; /*second page*/
	                MTD_CheckBlockBad(&Mtd_para);

		            if ( ((FDMData_512*)Spare_buff)->BI != 0xFF )
            		{
		                retVal |= MTD_STATUS_EARLY_BAD;
            		}
	            }
	        }
	        else
	        {
	        	// Offset 0 and offset 2048.
	        	if ( Mtd_para.buff[0] != 0xff ) {
	                retVal |= MTD_STATUS_EARLY_BAD;
	        	}

	            if ( ((FDMData_2k*)Spare_buff)->BI != 0xFFFF )
				{
	                retVal |= MTD_STATUS_EARLY_BAD;
				}

	            /*for 2k page, the bad mark is possible to put at 2nd page*/
	            if ( (retVal & MTD_STATUS_EARLY_BAD) != MTD_STATUS_EARLY_BAD )
	            {
			        if (Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[0]==POWERFLASH) {
				        // last page
				        Mtd_para.pageIdx[0] += (Flash_Info.blockPage-1);
			        } else {
				        // second page
                        Mtd_para.pageIdx[0] ++;
			        }

	                MTD_CheckBlockBad(&Mtd_para);

		        	if ( Mtd_para.buff[0] != 0xff ) {
		                retVal |= MTD_STATUS_EARLY_BAD;
		        	}

 	                if ( ((FDMData_2k*)Spare_buff)->BI != 0xFFFF )
                    {
	                    retVal |= MTD_STATUS_EARLY_BAD;
	                }
	            }
	        }

            // For code image bad block check, no new flash case.
	        if (Acc_Type == CODE_ACC)
            {
	        	goto MTD_BB_CHECK;
	        }
	    }
        else
        {
	    	// No new flash
	        if (Acc_Type == CODE_ACC)
            {
			    // second page
		        Mtd_para.pageIdx[0] ++;

	        	goto MTD_BB_CHECK;
	        }
	    }
    }

    free_MTD_lock();
    return retVal;
}

// Description
//	This function is only used for FOTA for compatility.
kal_uint8 IsGoodBlock(void* D, void * Spare)
{
    kal_uint8  good_block = 1;

    if (0xFFFF != DAL_GetFDMData(FDMDATA_BI, Spare))
    {
        good_block = 0;
    }

    return good_block;
}

/****************************************************************************
 * Function:   DAL_NAND_Reset
 *
 * Parameters: void
 *
 * Returns:    MTD_STATUS_NO_ERROR
 *
 * Description:
 *
 ****************************************************************************/
kal_int32 DAL_NAND_Reset(void)
{
    get_MTD_lock();

    if ( Flash_Info.valid_CE[0] == KAL_TRUE )
    {
        Mtd_para.ce = 0;
        MTD_NAND_Reset(&Mtd_para);
    }

    free_MTD_lock();

    return MTD_STATUS_NO_ERROR;
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
kal_uint16 DAL_GetFDMData(kal_uint8 FDMType, kal_uint32 *Spare_buff)
{
	kal_uint16 Data = 0;

    if (FDMDATA_BI == FDMType)
    {
        Data = SNAND_COMMON_GetBadBlockMark(Spare_buff);
    }
    else
    {
        if (SNAND_SPARE_FORMAT_MTK_1 == Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[7])
        {
            switch (FDMType)
            {
                case FDMDATA_BM:
                case FDMDATA_PA:
                case FDMDATA_4XCTL:
                    Data = ((FDMDataU_2K_MTK_1 *)Spare_buff) -> BM_PA;
                    break;
                case FDMDATA_LBA:
                    Data = ((FDMDataU_2K_MTK_1 *)Spare_buff) -> LBA;
                    break;
                default:
                    dbg_ASSERT(0);
            }
        }
        else if (SNAND_SPARE_FORMAT_MTK_2 == Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[7])
        {
            switch (FDMType)
            {
                case FDMDATA_BM:
                case FDMDATA_PA:
                case FDMDATA_4XCTL:
                    Data = ((FDMDataU_2K_MTK_2 *)Spare_buff) -> BM_PA;
                    break;
                case FDMDATA_LBA:
                    Data = ((FDMDataU_2K_MTK_2 *)Spare_buff) -> LBA;
                    break;
                default:
                    dbg_ASSERT(0);
            }
        }
    }
	return Data;
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
void DAL_SetFDMData(kal_uint16 BMPA, kal_uint16 LBA, kal_uint8 Option, kal_uint32 *Spare_buff)
{
      // ID_info[7] is borrowed to store SPI-NAND Spare Format
    if (SNAND_SPARE_FORMAT_MTK_1 == Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[7])
    {
        if (Option & FDMDATA_EMPTY)
        {
            kal_mem_set(Spare_buff, 0xFF, sizeof(FDMDataU_2K_MTK_1) );
        }

        if (Option & (FDMDATA_BM | FDMDATA_PA))
        {
            ((FDMDataU_2K_MTK_1*)Spare_buff) -> BM_PA = BMPA;
        }

        if (Option & FDMDATA_LBA)
        {
            ((FDMDataU_2K_MTK_1*)Spare_buff) -> LBA = LBA;
        }
    }
    else if (SNAND_SPARE_FORMAT_MTK_2 == Flash_Info.deviceInfo_CE[Mtd_para.ce].ID_info[7])
    {
        if (Option & FDMDATA_EMPTY)
        {
            kal_mem_set(Spare_buff, 0xFF, sizeof(FDMDataU_2K_MTK_2) );
        }

        if (Option & (FDMDATA_BM | FDMDATA_PA))
        {
            ((FDMDataU_2K_MTK_2*)Spare_buff) -> BM_PA = BMPA;
        }

        if (Option & FDMDATA_LBA)
        {
            ((FDMDataU_2K_MTK_2*)Spare_buff) -> LBA = LBA;
        }
    }
}

/****************************************************************************
 * Function:     DAL_GetDALVersion
 *
 * Parameters:
 *
 * Returns:      DAL_VERISON
 *
 * Description:  Return the DAL version of this load
 *
 ****************************************************************************/
kal_uint8 DAL_GetDALVersion(void)
{
    return DAL_MINOR_VER2;  // TODO: NEED NEW VERSION?
}

/****************************************************************************
 * Function:     DAL_GetDALVersion
 *
 * Parameters:   dal_ver    The DAL version that record at File system
 *
 * Returns:      KAL_TRUE   Format it
 *               KAL_FALSE  Do not format it
 *
 * Description:  FDM uses this fucntion to query DAL if format trigger or not
 *
 ****************************************************************************/
kal_bool DAL_FormatQuery(kal_uint8 dal_ver)
{
    return dal_ver != DAL_VERISON ? KAL_TRUE : KAL_FALSE ;
}

kal_bool NANDsanitycheck_Factory(void)
{
    if ( DAL_is_initialized == 0 )
    {
        FLASH_INFO F_info;
        DAL_init();
        DAL_FDM_Flash_Info_Init (&F_info, 0);
    }
    return (kal_bool)Flash_Info.valid_CE[0];
}

void DAL_GetDeviceInfo (kal_uint8 cs, flash_list* p)
{
    if (Flash_Info.valid_CE[cs] == KAL_TRUE)
    {
        kal_mem_cpy(p, &Flash_Info.deviceInfo_CE[cs], sizeof(flash_list));
    }
    else
    {
        kal_mem_set(p, 0xFF, sizeof(flash_list) ); /*Reset value*/
    }
}
/****************************************************************************
 * Function:
 *
 * Parameters:  Block       Logic block in code view (input)
 *              Page        The page index in the Block (input)
 *              cs_p        output of chip select
 *              page_idx_p  output of physical page index
 * Returns:     MTD_STATUS_NO_ERROR
 *
 * Description:
 *
 ****************************************************************************/
#if defined(FLASH_DISKDRV_DEBUG) || (defined _NAND_FLASH_BOOTING_)
kal_int32 DAL_NFB_AddressConvert(kal_uint32 Block, kal_uint32 Page, kal_uint8* cs_p, kal_uint32* page_idx_p)
{
    kal_uint32 zone_len;
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 k, retVal = MTD_STATUS_NO_ERROR;

    get_MTD_lock();

    zone_len = zonePage(0);

    /*calculate the DAL parameter*/
    zone_off = Block/zone_len;
    Block -= zone_off*zone_len;

    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (Block/Flash_Info.bankNum);
    }

    Page = Page*Flash_Info.bankNum + Block%Flash_Info.bankNum ;
    Add_Cnvt.zoneNum = zone_off ;
    Add_Cnvt.bankArry = b_arr;
    Add_Cnvt.pageIdx = Page;
    retVal = addressMap(&Add_Cnvt);
    *cs_p = Add_Cnvt.ce;
    *page_idx_p = Add_Cnvt.phyPage;

    if (Flash_Info.deviceInfo_CE[Add_Cnvt.ce].deviceSize*1024*1024 <= Flash_Info.pageSize*Add_Cnvt.phyPage)
    {
        dbg_ASSERT (0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }

    free_MTD_lock();

    return retVal;
}


#endif

#if defined(_NAND_FLASH_BOOTING_) || (defined(__UP_PKG_ON_NAND__) && defined(__SPI_NAND_SUPPORT__))

#if defined(__SNAND_THIRD_ROM_RECHARGE__)

#if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
void snand_trr_test_wdt_reset(void)
{
    kal_uint32 start_time,end_time;
    kal_uint32 tqcnt1, tqcnt2;

    dalay(Cur_qbit % 300); /*delay 0~300us randomly*/

    SNAND_Reset(SNAND_RST_CON);

    SNAND_Reset(SNAND_RST_DEV);

    // WDT Reset.
    SaveAndSetIRQMask();

    // delay 1 tick to ensure WDT setting done
    start_time = drv_get_current_time();

    while(1)
    {
        end_time = drv_get_current_time();

        if(drv_get_duration_tick(start_time,end_time)>1)
        {
            break;
        }
    }

    WDT_SetValue(2);    // reset after 15 us
    SNAND_WriteReg32(WDT_MODE, WDT_MODE_KEY | WDT_MODE_ENABLE);
    SNAND_WriteReg32(WDT_RESTART, WDT_RESTART_KEY);
    SNAND_WriteReg32(WDT_SWRST, WDT_SWRST_KEY); // issue software-triggered watchdog reset

    while(1);
}

void snand_trr_test_set_reset_position()
{
    srand(INT_GetCurrentTime());
    g_snand_trr_reset_position += rand();
    g_snand_trr_reset_position ^= INT_GetCurrentTime();
    g_snand_trr_reset_position %= 1000;
}


kal_bool snand_trr_test_if_trigger_recharge()
{
    kal_uint32 val = 0;

    srand(INT_GetCurrentTime());
    val += rand();
    val ^= INT_GetCurrentTime();
    val %= 100;

    if (val < 5)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

void snand_trr_test_get_rtc_time(DCL_CTRL_DATA_T * rtctime)
{
    DCL_HANDLE rtc_handler;

    rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
    DclRTC_Control(rtc_handler, RTC_CMD_GET_TIME, rtctime);
    DclRTC_Close(rtc_handler);
}
#endif  // __SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__

kal_uint32 NFB_IfThirdROMMapChanged()
{
    kal_uint32 ret;

    ret = g_snand_trr_map_changed;

    g_snand_trr_map_changed = 0;

    return ret;
}

kal_int32 snand_trr_mtd_check_bad_block(kal_uint32 phy_block)
{
    Mtd_para.buff = (kal_uint8 *)NFB_tmp_D_Buff;
    Mtd_para.spare = (kal_uint8 *)NFB_tmp_S_Buff;
    Mtd_para.m_idx = 0;     // No use
    Mtd_para.length = 1;    // No use
    Mtd_para.pageIdx[0] = phy_block * Flash_Info.blockPage;
    Mtd_para.ce = 0;
    Mtd_para.opFlag = 0;

    return MTD_CheckBlockBad(&Mtd_para);
}

kal_int32 snand_trr_mtd_mark_bad_block(kal_uint32 phy_block)
{
    kal_mem_set(NFB_tmp_D_Buff, 0xFF, _DAL_MAX_PAGE_SIZE_);
    kal_mem_set(NFB_tmp_S_Buff, 0xFF, _DAL_MAX_SPARE_SIZE_);

    Mtd_para.buff = (kal_uint8 *)NFB_tmp_D_Buff;
    Mtd_para.spare = (kal_uint8 *)NFB_tmp_S_Buff;
    Mtd_para.m_idx = 0;     // No use
    Mtd_para.length = 1;    // No use
    Mtd_para.pageIdx[0] = phy_block * Flash_Info.blockPage;
    Mtd_para.ce = 0;
    Mtd_para.opFlag = 0;

    return MTD_MarkBlockBad(&Mtd_para);
}

kal_int32 snand_trr_mtd_read_page(kal_uint32 row_addr, kal_uint8 * buf_data, kal_uint8 * buf_spare)
{
    Mtd_para.buff = buf_data;
    Mtd_para.spare = buf_spare;
    Mtd_para.m_idx = 0;
    Mtd_para.length = 1;
    Mtd_para.pageIdx[0] = row_addr;
    Mtd_para.ce = 0;
    Mtd_para.opFlag = 0;

    return MTD_Read(&Mtd_para);
}

kal_int32 snand_trr_mtd_program_page(kal_uint32 row_addr, kal_uint8 * buf_data, kal_uint8 * buf_spare)
{
    Mtd_para.buff = buf_data;
    Mtd_para.spare = buf_spare;
    Mtd_para.m_idx = 0;
    Mtd_para.length = 1;
    Mtd_para.pageIdx[0] = row_addr;
    Mtd_para.ce = 0;
    Mtd_para.opFlag = 0;

    return MTD_Program(&Mtd_para);
}

kal_int32 snand_trr_mtd_erase_block(kal_uint32 phy_block)
{
    Mtd_para.buff = NULL;
    Mtd_para.spare = NULL;
    Mtd_para.m_idx = 0;
    Mtd_para.length = 1;
    Mtd_para.pageIdx[0] = phy_block * Flash_Info.blockPage;
    Mtd_para.ce = 0;
    Mtd_para.opFlag = 0;

    return MTD_Erase(&Mtd_para);
}

void snand_trr_init()
{
    kal_int32 ret;
    kal_uint32 i, j, third_rom_cnt;
    FlashLayout *flashLayoutPtr = (FlashLayout*)&(g_pass_info.m_bl_flash_layout);
    Nand_ImageSpace_ST* imageSpacePtr = (Nand_ImageSpace_ST*)&(g_pass_info.m_bl_image_space);

    if (0 == g_snand_trr_initialized)
    {
        if (0 == DAL_is_initialized)
        {
            ret = DAL_init();
            force_ASSERT(ret == FS_NO_ERROR, ret, 0, 0);
        }

        #if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
        if (KAL_FALSE == g_snand_trr_bootup_time_recorded)
        {
            snand_trr_test_get_rtc_time((DCL_CTRL_DATA_T *)&g_snand_trr_rtc_time);

            g_snand_trr_bootup_time_recorded = KAL_TRUE;
        }
        #endif

        g_snand_trr_enabled = 0;

        // read third rom mapping table

        for (i = 2, third_rom_cnt = 0; i < flashLayoutPtr->regionCount; i++)
        {
            if (flashLayoutPtr->region[i].binaryType == THIRD_ROM)
            {
                if (0 == third_rom_cnt) // 1st Third ROM
                {
                    // 0. get geometry
                    g_snand_trr_rom1_block_begin = flashLayoutPtr->region[i].u.nandEmmc.startPage / Flash_Info.blockPage;

                    // 1. get reserved block end
                    g_snand_trr_rom1_res_block_end = flashLayoutPtr->region[i].u.nandEmmc.boundPage / Flash_Info.blockPage;   // this can also use g_snand_trr_rom1_res_block_end = imageSpacePtr->m_image_space[i].m_image_end;

                    // 2. get reserved block start
                    if (i < 10)
                    {
                        g_snand_trr_rom1_map_block = imageSpacePtr->m_image_space[i].m_image_last + 1;
                    }
                    else
                    {
                        g_snand_trr_rom1_map_block = imageSpacePtr->m_image_ext_space[i - 10].m_image_last + 1;
                    }

                    g_snand_trr_rom1_res_block_begin = g_snand_trr_rom1_map_block + 1;

                    // check if reserved block is enough
                    if ((g_snand_trr_rom1_res_block_begin >= g_snand_trr_rom1_res_block_end) ||
                        (g_snand_trr_rom1_res_block_end - g_snand_trr_rom1_res_block_begin < 2))
                    {
                        return;
                    }

                    // 3. get third rom 1's mapping table block

                    for (j = g_snand_trr_rom1_map_block; j <= g_snand_trr_rom1_res_block_end; j++)
                    {
                        ret = snand_trr_mtd_check_bad_block(j);

                        if (MTD_STATUS_NO_ERROR == ret)
                        {
                            g_snand_trr_rom1_map_block = j;
                            break;
                        }
                    }

                    if (j > g_snand_trr_rom1_res_block_end) // all reserved blocks are bad, no mapping table is found
                    {
                        return; // mapping table is not found, TRR is not enabled
                    }

                    // continue to find the 2nd third rom
                    third_rom_cnt++;
                }
                else    // 2nd Third ROM
                {
                    // 4. get third rom 2's mapping table block

                    if (i < 10)
                    {
                        g_snand_trr_rom2_map_block = imageSpacePtr->m_image_space[i].m_image_last + 1;
                    }
                    else
                    {
                        g_snand_trr_rom2_map_block = imageSpacePtr->m_image_ext_space[i - 10].m_image_last + 1;
                    }

                    // 5. get range of rom 2

                    g_snand_trr_rom2_block_begin = flashLayoutPtr->region[i].u.nandEmmc.startPage / Flash_Info.blockPage;
                    //g_snand_trr_rom2_block_end = flashLayoutPtr->region[i].u.nandEmmc.boundPage / Flash_Info.blockPage;

                    g_snand_trr_enabled = 1;

                    break;
                }
            }
        }

        if (1 == g_snand_trr_enabled)
        {
            // do powerloss handling

            #if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
            snand_trr_test_set_reset_position();
            #endif

            ret = snand_trr_handle_powerloss();

            if (ret >= 0)
            {
                snand_trr_recharge(ret, NULL);
            }
        }

        g_snand_trr_initialized = 1;
    }


}

// check if block in reserved region is already used
kal_int32 snand_trr_if_block_used(kal_uint32 block)
{
    kal_int32 ret;
    kal_uint16 crc_read, crc_gen;
    kal_uint32 i, j;

    // check if block is used (third rom code, log block, target block ...etc)

    if ((block == g_snand_trr_log_block) ||
        (block == g_snand_trr_target_block))
    {
        return 1;
    }

    // detect if it is recharged code block (read Page 0, check its spare)
    ret = snand_trr_mtd_read_page(block * Flash_Info.blockPage, (kal_uint8 *)NFB_tmp_D_Buff, (kal_uint8 *)NFB_tmp_S_Buff);

    if (MTD_STATUS_ERROR == (ret & 0xFFFF0000)) // read error, we can do nothing here, just return "used"
    {
        return 1;
    }

    crc_read = snand_crc_get((kal_uint8 *)NFB_tmp_S_Buff);

    if (0xFFFF != crc_read)
    {
        crc_gen = (kal_uint16)(snand_crc_gen((kal_uint8 *)NFB_tmp_D_Buff, Flash_Info.pageSize));

        if (crc_read == crc_gen)    // CRC OK!
        {
            if (2 == g_snand_trr_map_status)    // valid map is found in Log Block, orphan Code Block is possible in reserved area
            {
                // find if this block existed in the map in Log Block

                for (i = 1; i < Flash_Info.blockPage; i++)
                {
                    ret = snand_trr_mtd_read_page(g_snand_trr_log_block * Flash_Info.blockPage + i, (kal_uint8 *)NFB_tmp_D_Buff, (kal_uint8 *)NFB_tmp_S_Buff);

                    for (j = 0; j < SNAND_PAGE_SIZE / sizeof(kal_uint32); j++)
                    {
                        if (0xFFFFFFFF == ((kal_uint32 *)NFB_tmp_D_Buff)[j])    // the end of map
                        {
                            i = Flash_Info.blockPage;   // leave for-loop-i

                            break;
                        }
                        else
                        {
                            if (block == ((kal_uint32 *)NFB_tmp_D_Buff)[j])
                            {
                                return 1;   // found in Map!
                            }
                        }
                    }
                }
            }
            else    // no map or corrupted map is found in Log Block, orphan code block is impossible
            {
                return 1;
            }
        }
    }

    return 0;
}

kal_int32 snand_trr_find_good_block(kal_uint32 start_block, kal_int32 inc, kal_uint32 find_for_map)
{
    kal_int32 ret;

    dbg_ASSERT((find_for_map == 0) || (find_for_map == 1));

    while (1)
    {
        if ((start_block > g_snand_trr_rom1_res_block_end) ||
            (start_block < (g_snand_trr_rom1_res_block_begin - find_for_map)))  // including original Map Block in ROM1 if find_for_map = 1. In find_for_map = 0 case, do not return map block number to avoid map block being erased.
        {
            return SNAND_TRR_ERR_GOOD_BLOCK_UNAVAILABLE;
        }

        if (MTD_STATUS_NO_ERROR == snand_trr_mtd_check_bad_block(start_block))
        {
            if (0 == snand_trr_if_block_used(start_block))
            {
                return start_block;
            }
        }

        start_block = start_block + inc;
    }
}

void snand_trr_set_log_block_title(kal_uint8 * buf, kal_uint32 seq_num, kal_uint32 target_block)
{
    kal_uint32  i, j;
    kal_uint16  crc;

    kal_mem_set(buf, ' ', SNAND_MARK_LOG_BLOGK_LEN + 1 + 8 + 1 + 4 + 1 + sizeof(kal_uint16));
    kal_mem_cpy(buf, g_snand_mark_LOG_BLOCK, SNAND_MARK_LOG_BLOGK_LEN);

    // seq num
    for (i = 10000000, j = 1; i != 0; i = i / 10, j++)
    {
        buf[SNAND_MARK_LOG_BLOGK_LEN + j] = ((seq_num / i) % 10) + '0';
    }

    // target block
    for (i = 1000, j = 1 + 8 + 1; i != 0; i = i / 10, j++)
    {
        buf[SNAND_MARK_LOG_BLOGK_LEN + j] = ((target_block / i) % 10) + '0';
    }

    // crc
    crc = snand_crc_gen(buf, SNAND_MARK_LOG_BLOGK_LEN + 1 + 8 + 1 + 4 + 1); // calculate "0 LOG BLOCK SSSSSSSS BBBB "

    *((kal_uint16 *)(buf + SNAND_MARK_LOG_BLOGK_LEN + 1 + 8 + 1 + 4 + 1)) = crc;    // NOTE: CRC must be placed in 2-byte-algined location!

}

kal_int32 snand_trr_get_src_block(kal_uint32 target_block)
{
    kal_uint32  page, entry_in_page = 0, val, found;
    kal_int32   ret;
    kal_uint32  start_page, end_page, map_block;

    // get target_block's block offset in ROM1's map

    found = 0;

    if (2 == g_snand_trr_map_status)    // powerloss case & map in Log Block is completed => read map in Log Block because current Map Block may be already updated before powerloss.
    {
        start_page = 1;
        end_page = Flash_Info.blockPage;
        map_block = g_snand_trr_log_block;
    }
    else    // if powerloss case, map in Log Block is not existd or corrupted => we can find original target block in current Map Block.
    {
        start_page = 0;
        end_page = Flash_Info.blockPage;
        map_block = g_snand_trr_rom1_map_block;
    }

    for (page = start_page; page < end_page; page++)
    {
        ret = snand_trr_mtd_read_page((map_block * Flash_Info.blockPage) + page, (kal_uint8 *)NFB_tmp_D_Buff, NULL);

        if ((ret & 0xFFFF0000) == MTD_STATUS_ERROR)
        {
            force_ASSERT(0, 0, 0, 0);   // read ROM1's map block failed, third ROM is dead
            //return SNAND_TRR_ERR_SRC_BLOCK_NOT_FOUND;
        }

        for (entry_in_page= 0; entry_in_page < (SNAND_PAGE_SIZE / sizeof(kal_uint32)); entry_in_page++)
        {
            val = ((kal_uint32 *)NFB_tmp_D_Buff)[entry_in_page];

            if (target_block == val)
            {
                found = 1;
                break;
            }

            if (0xFFFFFFFF == val)    // end of ROM1's map
            {
                break;
            }
        }

        if (1 == found)
        {
            break;
        }
    }

    if (0 == found)
    {
        force_ASSERT(0, 0, 0, 0);
        //return SNAND_TRR_ERR_SRC_BLOCK_NOT_FOUND;
    }

    // here we get page and entry_in_page
    // find the block with the same page and entry_in_page in ROM2's map

    if (2 == g_snand_trr_map_status)
    {
        page = page - 1;    // Map[0] is in Log Block[1]
    }

    ret = snand_trr_mtd_read_page((g_snand_trr_rom2_map_block * Flash_Info.blockPage) + page, (kal_uint8 *)NFB_tmp_D_Buff, NULL);

    if ((ret & 0xFFFF0000) == MTD_STATUS_ERROR)
    {
        force_ASSERT(0, 0, 0, 0);   // read ROM2's map block failed, third ROM is dead
        //return SNAND_TRR_ERR_SRC_BLOCK_NOT_FOUND;
    }

    val = ((kal_uint32 *)NFB_tmp_D_Buff)[entry_in_page];

    if ((0xFFFFFFFF == val) ||
        (val < g_snand_trr_rom2_block_begin) ||
        (val >= g_snand_trr_rom2_map_block))    // end of ROM2's map or out of range
    {
        force_ASSERT(0, 0, 0, 0);
        //return SNAND_TRR_ERR_SRC_BLOCK_NOT_FOUND;
    }

    return (kal_int32)val;
}

kal_int32 snand_trr_get_log_block_title(kal_uint8 * buf, kal_uint32 * seq_num, kal_uint32 * target_block)
{
    kal_uint32  seq_num_local, target_block_local, i, j;
    kal_uint16  crc_read, crc_gen;

    if (1 == kal_mem_cmp(buf, g_snand_mark_LOG_BLOCK, SNAND_MARK_LOG_BLOGK_LEN))
    {
        return SNAND_TRR_ERR_LOG_BLOCK_MARK_NOT_FOUND;
    }

    // get and check crc

    crc_read = *((kal_uint16 *)(buf + SNAND_MARK_LOG_BLOGK_LEN + 1 + 8 + 1 + 4 + 1));   // NOTE: CRC must be placed in 2-byte-algined location!

    crc_gen = (kal_uint16)snand_crc_gen(buf, SNAND_MARK_LOG_BLOGK_LEN + 1 + 8 + 1 + 4 + 1);

    if (crc_gen != crc_read)
    {
        return SNAND_TRR_ERR_LOG_BLOCK_MARK_NOT_FOUND;  // crc check error
    }

    // get target block

    target_block_local = 0;

    for (i = 1000, j = SNAND_MARK_LOG_BLOGK_LEN + 1 + 8 + 1; i != 0; i = i / 10, j++)
    {
        target_block_local = target_block_local + i * (buf[j] - '0');
    }

    // get seq num

    seq_num_local = 0;

    for (i = 10000000, j = SNAND_MARK_LOG_BLOGK_LEN + 1; i != 0; i = i / 10, j++)
    {
        seq_num_local = seq_num_local + i * (buf[j] - '0');
    }

    *seq_num = seq_num_local;
    *target_block = target_block_local;

    return SNAND_TRR_NO_ERROR;
}

kal_int32 snand_trr_recharge(kal_uint32 stage, kal_uint32 * new_target_block)
{
    kal_int32   ret, i, j, k;
    kal_int32   sub_stage, this_stage, this_sub_stage;
    kal_uint16  crc;
    kal_int32   status = SNAND_TRR_NO_ERROR;

    if (0 == g_snand_trr_enabled)
    {
        return;
    }

    get_MTD_lock();

    // start re-charge
    DAL_NAND_Reset();

    while (1)
    {
        // Find a good block (as Log Block)

        if (0 == stage)
        {
            g_snand_trr_log_block = snand_trr_find_good_block(g_snand_trr_rom1_res_block_end, -1, 0);

            if (g_snand_trr_log_block < SNAND_TRR_NO_ERROR)
            {
                status = g_snand_trr_log_block;
                goto SNAND_TRR_RECHARGE_END;
            }

            stage++;    // go through
        }

        // Erase Log Block (if failed, mark as bad block, go to 0)

        if (1 == stage)
        {
            #if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
            if (1 == g_snand_trr_reset_position) g_snand_trr_reset_in_next_busy = KAL_TRUE;
            #endif

            ret = snand_trr_mtd_erase_block(g_snand_trr_log_block);

            if (MTD_STATUS_NO_ERROR != ret)
            {
                snand_trr_mtd_mark_bad_block(g_snand_trr_log_block);
                stage = 0;
                continue;
            }

            stage++;    // go through
        }

        // Add mark "LOG BLOCK SSSSSSSS BBBB CCC" in Log Block's Page 0 (SSSSSSSS is a incrasing unique sequential number, BBBB is target block number, CCC is CRC code for Log Block)

        if (2 == stage)
        {
            kal_mem_set(NFB_tmp_D_Buff, 0xFF, _DAL_MAX_PAGE_SIZE_);
            kal_mem_set(NFB_tmp_S_Buff, 0xFF, _DAL_MAX_SPARE_SIZE_);

            g_snand_trr_seq_num++;

            snand_trr_set_log_block_title((kal_uint8 *)NFB_tmp_D_Buff, g_snand_trr_seq_num, g_snand_trr_target_block);

            #if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
            if (2 == g_snand_trr_reset_position) g_snand_trr_reset_in_next_busy = KAL_TRUE;
            #endif

            ret = snand_trr_mtd_program_page(g_snand_trr_log_block * Flash_Info.blockPage + SNAND_MARK_LOG_BLOCK_PAGE_OFFSET, (kal_uint8 *)NFB_tmp_D_Buff, (kal_uint8 *)NFB_tmp_S_Buff);

            if (MTD_STATUS_NO_ERROR != ret)
            {
                snand_trr_mtd_mark_bad_block(g_snand_trr_log_block);
                stage = 0;
                continue;
            }

            stage++;    // go through
        }

        if (3 == stage)
        {
            stage += 2;    // go through
        }

        // if traget block is bad, we will be here. Find a good block as new target block

        if (4 == stage)
        {
            g_snand_temp_val = snand_trr_find_good_block(g_snand_trr_rom1_res_block_end, -1, 0);

            if (g_snand_temp_val < SNAND_TRR_NO_ERROR)  // no good block as new target block, exit recharge
            {
                status = g_snand_temp_val;
                goto SNAND_TRR_RECHARGE_END;
            }

            if (-1 == g_snand_trr_target_block_original) // remember the origianl target block
            {
                g_snand_trr_target_block_original = g_snand_trr_target_block;
            }

            g_snand_trr_target_block = g_snand_temp_val;

            g_snand_trr_map_changed = 1;

            stage++;    // go through
        }

        // Erase Target block n

        if (5 == stage)
        {
            ret = snand_trr_mtd_check_bad_block(g_snand_trr_target_block);  // check bad block again for powerloss handling

            if (MTD_STATUS_NO_ERROR != ret)
            {
                stage = 4;

                continue;   // go back to find a free block as new target block
            }

            #if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
            if (3 == g_snand_trr_reset_position) g_snand_trr_reset_in_next_busy = KAL_TRUE;
            #endif

            ret = snand_trr_mtd_erase_block(g_snand_trr_target_block);

            if (MTD_STATUS_NO_ERROR != ret)
            {
                snand_trr_mtd_mark_bad_block(g_snand_trr_target_block);

                stage = 4;

                continue;   // go back to find a free block as new target block
            }

            stage++;    // go through
        }

        // if target block is changed, copy original map (page 0 to 62) to Log Block (page 1 to 63)

        if (6 == stage)
        {
            if (-1 != g_snand_trr_target_block_original) // if target block is changed
            {
                if (2 == g_snand_trr_map_status)    // valid map is already in Log Block
                {
                    stage++;    // go next stage
                    continue;
                }

                for (i = 0; i < Flash_Info.blockPage; i++)
                {
                    ret = snand_trr_mtd_read_page(g_snand_trr_rom1_map_block * Flash_Info.blockPage + i, (kal_uint8 *)NFB_tmp_D_Buff, (kal_uint8 *)NFB_tmp_S_Buff);

                    if (MTD_STATUS_ERROR == (ret & 0xFFFF0000))
                    {
                        force_ASSERT(0, 0, 0, 0);   // read rom1 map error, third rom is dead
                    }

                    // page 63 of Map Block, if any data in it, we could not service this big map, assert
                    if (i == Flash_Info.blockPage)
                    {
                        if (0xFFFFFFFF != ((kal_uint32 *)NFB_tmp_D_Buff)[0])
                        {
                            force_ASSERT(0, 0, 0, 0);
                        }
                        else
                        {
                            break;  // leave copy map
                        }
                    }

                    // add crc code for every map page in Log Block
                    for (j = 0; j < Flash_Info.spareSize; j++)
                    {
                        ((kal_uint8 *)(NFB_tmp_S_Buff))[j] = 0xFF;
                    }

                    crc = (kal_uint16)snand_crc_gen((kal_uint8 *)NFB_tmp_D_Buff, Flash_Info.pageSize);

                    snand_crc_set(crc, (kal_uint8 *)NFB_tmp_S_Buff);

                    // write it to Log Block (1 to 63)

                    #if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
                    if (4 == g_snand_trr_reset_position) g_snand_trr_reset_in_next_busy = KAL_TRUE;
                    #endif

                    ret = snand_trr_mtd_program_page(g_snand_trr_log_block * Flash_Info.blockPage + (i + 1), (kal_uint8 *)NFB_tmp_D_Buff, (kal_uint8 *)NFB_tmp_S_Buff);

                    if (ret != MTD_STATUS_NO_ERROR)
                    {
                        snand_trr_mtd_mark_bad_block(g_snand_trr_log_block);

                        stage = 0;

                        break;   // go back to find a free block as new Log Block
                    }
                }
            }

            stage++;    // go through
        }

        // Copy data from Third ROM 2 to Target Block

        if (7 == stage)
        {
            this_stage = stage;

            if (-1 == g_snand_trr_target_block_original)
            {
                g_snand_trr_source_block = snand_trr_get_src_block(g_snand_trr_target_block);
            }
            else
            {
                g_snand_trr_source_block = snand_trr_get_src_block(g_snand_trr_target_block_original);
            }


            if (g_snand_trr_source_block < SNAND_TRR_NO_ERROR)
            {
                force_ASSERT(0, 0, 0, 0);   // get source block failed, third rom is dead
            }

            // copy from last page to page 0, and add CRC code in page 0
            for (i = Flash_Info.blockPage - 1; i >= 0; i--)
            {
                ret = snand_trr_mtd_read_page(g_snand_trr_source_block * Flash_Info.blockPage + i, (kal_uint8 *)NFB_tmp_D_Buff, (kal_uint8 *)NFB_tmp_S_Buff);

                if (MTD_STATUS_ERROR == (ret & 0xFFFF0000))
                {
                    force_ASSERT(0, 0, 0, 0);   // read source data error, third rom is dead
                }

                if (0 == i) // last copied page (page 0)
                {
                    for (j = 0; j < Flash_Info.spareSize; j++)
                    {
                        ((kal_uint8 *)(NFB_tmp_S_Buff))[j] = 0xFF;
                    }

                    crc = (kal_uint16)snand_crc_gen((kal_uint8 *)NFB_tmp_D_Buff, Flash_Info.pageSize);
                    snand_crc_set(crc, (kal_uint8 *)NFB_tmp_S_Buff);
                }

                #if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
                if (5 == g_snand_trr_reset_position) g_snand_trr_reset_in_next_busy = KAL_TRUE;
                #endif

                ret = snand_trr_mtd_program_page(g_snand_trr_target_block * Flash_Info.blockPage + i, (kal_uint8 *)NFB_tmp_D_Buff, (kal_uint8 *)NFB_tmp_S_Buff);

                if (ret != MTD_STATUS_NO_ERROR)
                {
                    snand_trr_mtd_mark_bad_block(g_snand_trr_target_block);

                    stage = 4;

                    break;   // go back to find a free block as new target block
                }
            }

            if (stage != this_stage)
            {
                continue;   // go back stage "stage"
            }

            stage++;    // go through
        }

        // if target block is changed, update map here

        if (8 == stage)
        {
            this_stage = stage;

            if (-1 != g_snand_trr_target_block_original) // target block is changed
            {
                sub_stage = 0;

                while (1)
                {
                    // find a free block as new Map Block (starting from top)

                    if (0 == sub_stage)
                    {
                        g_snand_temp_val = snand_trr_find_good_block(g_snand_trr_rom1_map_block, 1, 1);    // start search from current origianl Map Block

                        if (g_snand_temp_val < SNAND_TRR_NO_ERROR)
                        {
                            force_ASSERT(0, 0, 0, 0);  // no good block as new map block, assert (assert in next boot-up too)
                        }

                        // erase new Map Block

                        #if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
                        if (6 == g_snand_trr_reset_position) g_snand_trr_reset_in_next_busy = KAL_TRUE;
                        #endif

                        ret = snand_trr_mtd_erase_block(g_snand_temp_val);

                        if (ret != MTD_STATUS_NO_ERROR)
                        {
                            snand_trr_mtd_mark_bad_block(g_snand_temp_val);

                            sub_stage= 0;

                            continue;   // go back to find a free block as new map block again
                        }
                        else
                        {
                            g_snand_trr_rom1_map_block = g_snand_temp_val;
                        }

                        sub_stage++;    // go through
                    }

                    if (1 == sub_stage)
                    {
                        // write udpated map to new Map Block

                        this_sub_stage = sub_stage;

                        dbg_ASSERT(g_snand_trr_target_block_original != -1);

                        j = 0;

                        for (i = 0; i < Flash_Info.blockPage - 1; i++)
                        {
                            ret = snand_trr_mtd_read_page(g_snand_trr_log_block * Flash_Info.blockPage + (i + 1), (kal_uint8 *)NFB_tmp_D_Buff, (kal_uint8 *)NFB_tmp_S_Buff);

                            if (MTD_STATUS_ERROR == (ret & 0xFFFF0000))
                            {
                                // go stage 0 to find a new block as Log Block
                            }

                            // update target block in map

                            for (k = 0; k < SNAND_PAGE_SIZE / sizeof(kal_uint32); k++)
                            {
                                if (((kal_uint32 *)NFB_tmp_D_Buff)[k] == g_snand_trr_target_block_original)
                                {
                                    if (0 != j)
                                    {
                                        force_ASSERT(0, 0, 0, 0);
                                    }

                                    ((kal_uint32 *)NFB_tmp_D_Buff)[k] = g_snand_trr_target_block;

                                    j = 1;
                                }
                            }

                            // write it to New Map Block (0 to 62)

                            #if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
                            if (7 == g_snand_trr_reset_position) g_snand_trr_reset_in_next_busy = KAL_TRUE;
                            #endif

                            ret = snand_trr_mtd_program_page(g_snand_trr_rom1_map_block * Flash_Info.blockPage + i, (kal_uint8 *)NFB_tmp_D_Buff, (kal_uint8 *)NFB_tmp_S_Buff);

                            if (ret != MTD_STATUS_NO_ERROR)
                            {
                                snand_trr_mtd_mark_bad_block(g_snand_trr_rom1_map_block);

                                sub_stage = 0;

                                break;   // go back to find a free block as new Map Block
                            }
                        }

                        if (sub_stage != this_sub_stage)
                        {
                            continue;   // go back the beginning of sub_stage
                        }

                        sub_stage++;    // go through
                    }

                    break;
                }
            }

            if (stage != this_stage)
            {
                continue;   // go back the beginning of stage
            }

            stage++;   // go through
        }

        // Erase Log Block

        if (9 == stage)
        {
            if (-1 == g_snand_trr_target_block_original)    // no updating map before, just erase Log Block
            {
                #if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
                if (8 == g_snand_trr_reset_position) g_snand_trr_reset_in_next_busy = KAL_TRUE;
                #endif

                ret = snand_trr_mtd_erase_block(g_snand_trr_log_block);

                if (MTD_STATUS_NO_ERROR != ret)
                {
                    snand_trr_mtd_mark_bad_block(g_snand_trr_log_block);
                }
            }
            else    // to avoid corrupted map in Log Block due to powerloss during erasing Log Block, make a false Log Block with no map, and then erase the original Log Block
            {
                snand_trr_retore_log_block(9999); // inside: original Log Block will be erased after false Log Block is created

                #if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
                if (9 == g_snand_trr_reset_position) g_snand_trr_reset_in_next_busy = KAL_TRUE;
                #endif

                ret = snand_trr_mtd_erase_block(g_snand_trr_log_block);   // erase false Log Block

                if (MTD_STATUS_NO_ERROR != ret)
                {
                    snand_trr_mtd_mark_bad_block(g_snand_trr_log_block);
                }
            }
        }

        break;
    }

SNAND_TRR_RECHARGE_END:

    if ((SNAND_TRR_NO_ERROR == status) && (NULL != new_target_block))
    {
        *new_target_block = g_snand_trr_target_block;
    }

    g_snand_trr_log_block = -1;
    g_snand_trr_target_block = -1;
    g_snand_trr_target_block_original = -1;
    g_snand_trr_source_block = -1;

    free_MTD_lock();

    return status;
}

kal_int32 snand_trr_retore_log_block(kal_uint32 target_block)
{
    kal_int32 new_log_block, ret;
    kal_uint32 i, need_restart;

    while (1)
    {
        // Find a good block as new Log Block

        new_log_block = snand_trr_find_good_block(g_snand_trr_rom1_res_block_end, -1, 0);

        if (new_log_block < SNAND_TRR_NO_ERROR)
        {
            return new_log_block;   // no good block is available, restore failed.
        }

        // Erase new Log Block (if failed, mark as bad block, go to L1)

        #if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
        if (10 == g_snand_trr_reset_position) g_snand_trr_reset_in_next_busy = KAL_TRUE;
        #endif

        ret = snand_trr_mtd_erase_block(new_log_block);

        if (MTD_STATUS_NO_ERROR != ret)
        {
            snand_trr_mtd_mark_bad_block(new_log_block);
            continue;   // re-start
        }

        // Add mark "LOG BLOCK SSSSSSSS BBBB" in New Log Block's Page 0

        kal_mem_set(NFB_tmp_D_Buff, 0xFF, _DAL_MAX_PAGE_SIZE_);
        kal_mem_set(NFB_tmp_S_Buff, 0xFF, _DAL_MAX_SPARE_SIZE_);

        g_snand_trr_seq_num++;

        snand_trr_set_log_block_title((kal_uint8 *)NFB_tmp_D_Buff, g_snand_trr_seq_num, target_block);

        #if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
        if (11 == g_snand_trr_reset_position) g_snand_trr_reset_in_next_busy = KAL_TRUE;
        #endif

        ret = snand_trr_mtd_program_page(new_log_block * Flash_Info.blockPage + SNAND_MARK_LOG_BLOCK_PAGE_OFFSET, (kal_uint8 *)NFB_tmp_D_Buff, (kal_uint8 *)NFB_tmp_S_Buff);

        if (MTD_STATUS_NO_ERROR != ret)
        {
            snand_trr_mtd_mark_bad_block(new_log_block);
            continue;   // re-start
        }

        // Erase old log block

        #if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
        if (12 == g_snand_trr_reset_position) g_snand_trr_reset_in_next_busy = KAL_TRUE;
        #endif

        ret = snand_trr_mtd_erase_block(g_snand_trr_log_block);

        if (MTD_STATUS_NO_ERROR != ret)
        {
            snand_trr_mtd_mark_bad_block(g_snand_trr_log_block);
        }

        g_snand_trr_log_block = new_log_block;

        break;
    }

    return SNAND_TRR_NO_ERROR;
}

kal_uint32 snand_trr_if_empty(kal_uint8 * buf, kal_uint32 length)
{
    kal_uint32 i;

    for (i = 0; i < length; i++)
    {
        if (buf[i] != 0xFF)
        {
            return 0;
        }
    }

    return 1;
}

kal_int32 snand_trr_handle_powerloss()
{
    kal_uint32 seq_num_max = 0;
    kal_uint32 i, seq_num_tmp, target_block_tmp;
    kal_int32  log_block = -1;
    kal_int32  target_block;
    kal_int32  ret;
    kal_uint8  stage;
    kal_uint16 crc_read, crc_gen;

    get_MTD_lock();

    g_snand_trr_log_block = -1;
    g_snand_trr_target_block = -1;

    target_block = -1;

    // find if any valid log block existed. Get the one with the largest sequential number
    for (i = g_snand_trr_rom1_res_block_end; i >= g_snand_trr_rom1_res_block_begin; i--)
    {
        if (MTD_STATUS_NO_ERROR == snand_trr_mtd_check_bad_block(i))
        {
            // read if it has LOG BLOCK mark
            ret = snand_trr_mtd_read_page(i * Flash_Info.blockPage + SNAND_MARK_LOG_BLOCK_PAGE_OFFSET, (kal_uint8 *)NFB_tmp_D_Buff, NULL);

            if (MTD_STATUS_ERROR == (ret & 0xFFFF0000)) // read error, skip this error block
            {
                continue;
            }

            ret = snand_trr_get_log_block_title((kal_uint8 *)NFB_tmp_D_Buff, &seq_num_tmp, &target_block_tmp);

            if (SNAND_TRR_NO_ERROR == ret) // a valid log block is found
            {
                if (seq_num_tmp > seq_num_max)
                {
                    seq_num_max = seq_num_tmp;
                    log_block = i;
                    target_block = target_block_tmp;
                }
            }
        }
    }

    if ((9999 != target_block) && (-1 != target_block))
    {
        if ((target_block >= g_snand_trr_rom1_block_begin) &&
            (target_block <= g_snand_trr_rom1_res_block_end))
        {
            g_snand_trr_target_block = target_block;
            g_snand_trr_log_block = log_block;
            g_snand_trr_seq_num = seq_num_max;
            stage = -1;
        }
        // else, g_snand_trr_target_block is undefined, and this Log Block with invalid target_block will be erased below
    }

    // check if log block has map inside

    if (g_snand_trr_log_block != -1)
    {
        g_snand_trr_map_status = 0; // no map

        for (i = 1; i < Flash_Info.blockPage; i++)
        {
            ret = snand_trr_mtd_read_page(g_snand_trr_log_block * Flash_Info.blockPage + i, (kal_uint8 *)NFB_tmp_D_Buff, (kal_uint8 *)NFB_tmp_S_Buff);

            crc_read = snand_crc_get((kal_uint8 *)NFB_tmp_S_Buff);

            if (0xFFFF == crc_read)
            {
                if (2 == g_snand_trr_map_status)    // if there is a valid map page before, the whole map should be corrupted because all pages' CRC should not be 0xFFFF
                {
                    g_snand_trr_map_status = 1;     // corrupted map

                    break;
                }
                else    // no valid map page before
                {
                    if (1 == snand_trr_if_empty((kal_uint8 *)NFB_tmp_D_Buff, Flash_Info.pageSize))
                    {
                        continue;   // this page is empty, go to next page
                    }
                }
            }

            // here, this page is not empty or crc_read is not 0xFFFF, check CRC

            crc_gen = snand_crc_gen((kal_uint8 *)NFB_tmp_D_Buff, Flash_Info.pageSize);

            if (crc_gen != crc_read)
            {
                g_snand_trr_map_status = 1; // a corrupted map is found

                break;
            }
            else    // crc is the same
            {
                g_snand_trr_map_status = 2; // assume all maps are valid first, go to next page
            }
        }
    }

    // 1. Erase all other old Log Blocks or Error Blocks to avoid them occupying free blocks
    // 2. Erase false Log Block (target_block = 9999)
    for (i = g_snand_trr_rom1_res_block_end; i >= g_snand_trr_rom1_res_block_begin; i--)
    {
        if (i == g_snand_trr_log_block)
        {
            continue;   // skip correct Log Block
        }

        if (MTD_STATUS_NO_ERROR == snand_trr_mtd_check_bad_block(i))
        {
            // read if it has LOG BLOCK mark

            ret = snand_trr_mtd_read_page(i * Flash_Info.blockPage + SNAND_MARK_LOG_BLOCK_PAGE_OFFSET, (kal_uint8 *)NFB_tmp_D_Buff, NULL);

            if (MTD_STATUS_ERROR == (ret & 0xFFFF0000)) // read error, erase error blocks
            {
                #if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
                if (14 == g_snand_trr_reset_position) g_snand_trr_reset_in_next_busy = KAL_TRUE;
                #endif

                ret = snand_trr_mtd_erase_block(i);

                if (MTD_STATUS_NO_ERROR != ret)
                {
                    snand_trr_mtd_mark_bad_block(i);
                }

                continue;
            }

            if (-1 == target_block) // if we did not find Log Block before, just continue to erase all other error blocks
            {
                continue;
            }

            ret = snand_trr_get_log_block_title((kal_uint8 *)NFB_tmp_D_Buff, &seq_num_tmp, &target_block_tmp);

            if (SNAND_TRR_NO_ERROR == ret) // a valid log block is found, this log block should be old Log Block
            {
                #if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
                if (15 == g_snand_trr_reset_position) g_snand_trr_reset_in_next_busy = KAL_TRUE;
                #endif

                ret = snand_trr_mtd_erase_block(i);

                if (MTD_STATUS_NO_ERROR != ret)
                {
                    snand_trr_mtd_mark_bad_block(i);
                }
            }
        }
    }

    if ((9999 == target_block) || (-1 == target_block))   // here, we already erased False Log Block and erased all error blocks,  do nothing and then leave re-rharge
    {
        free_MTD_lock();
        return -1;
    }

    // now we got a valid Log Block, continue to re-charge

    if (2 == g_snand_trr_map_status)    // good Log Block with valid map
    {
        g_snand_trr_target_block_original = g_snand_trr_target_block;
        stage = 4;
    }
    else    // good Log Block without map or with corrupted map, make a new Log Block to re-start recharge
    {
        ret = snand_trr_retore_log_block(g_snand_trr_target_block);
        stage = 5;
    }

    free_MTD_lock();

    dbg_ASSERT(stage != -1);

    return stage;
}

#else   // !__SNAND_THIRD_ROM_RECHARGE__

kal_uint32 NFB_IfThirdROMMapChanged()
{
    return 0;
}

#endif  // __SNAND_THIRD_ROM_RECHARGE__


int NFB_ErasePhysicalBlock(kal_uint32 PhyBlock, kal_bool DALRemap)
{
    //FLASH_INFO F_info;
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 NFBStatus = -1,k;
    kal_uint32 zone_len, BankNo;

    if (DAL_is_initialized == 0)
    {
        NFBStatus = DAL_init();
        force_ASSERT( NFBStatus == FS_NO_ERROR ,NFBStatus ,0 ,0);
    }

    //DAL_FDM_Flash_Info_Init (&F_info, 0);
    if (PhyBlock == 0xFFFFFFFF) /*1st access access of NFB*/
    {
        return Flash_Info.deviceInfo_CE[0].IOWidth;
    }

    DAL_NAND_Reset();

    zone_len = zonePage(0);

    /*calculate the DAL parameter*/
    zone_off = PhyBlock/zone_len;
    PhyBlock -= zone_off*zone_len;

    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (PhyBlock/Flash_Info.bankNum);
    }

    BankNo = PhyBlock%Flash_Info.bankNum;
    NFBStatus = DAL_CheckBadBlock (DALRemap ? CODE_ACC : RAW_ACC, zone_off, b_arr, BankNo, KAL_FALSE, NFB_tmp_D_Buff, NFB_tmp_S_Buff);

    if ( NFBStatus != MTD_STATUS_NO_ERROR )
    {
        return ERROR_NFB_BAD_BLOCK;
    }

	NFBStatus = DAL_EraseBlock(DALRemap ? CODE_ACC : RAW_ACC, zone_off, b_arr, BankNo, 1) & 0xffff;

	if (NFBStatus) {
		// Program failure.
		return ERROR_NFB_ERASE;
	}

    return ERROR_NFB_SUCCESS;

}

int NFB_ProgramPhysicalSpare(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data, kal_bool chksum, kal_bool DALRemap)
{
    //FLASH_INFO F_info;
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 NFBStatus = -1,k;
    kal_uint32 zone_len;

    if (DAL_is_initialized == 0)
    {
        NFBStatus = DAL_init();
        force_ASSERT( NFBStatus == FS_NO_ERROR ,NFBStatus ,0 ,0);
    }

    if (PhyBlock == 0xFFFFFFFF && PhyPage == 0xFFFFFFFF) /*1st access access of NFB*/
    {
        return Flash_Info.deviceInfo_CE[0].IOWidth;
    }

    DAL_NAND_Reset();

    zone_len = zonePage(0);

    /*calculate the DAL parameter*/
    zone_off = PhyBlock/zone_len;
    PhyBlock -= zone_off*zone_len;

    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (PhyBlock/Flash_Info.bankNum);
    }

    PhyPage = PhyPage*Flash_Info.bankNum + PhyBlock%Flash_Info.bankNum ;

    kal_mem_set(NFB_tmp_D_Buff, 0xFF, Flash_Info.pageSize);

	NFBStatus = DAL_ProgramPage(DALRemap ? CODE_ACC : RAW_ACC, zone_off, b_arr, PhyPage, 1, (kal_uint8*)NFB_tmp_D_Buff, (kal_uint8*)Data) & 0xffff;

	if (NFBStatus)
    {
		// Program failure.
		return ERROR_NFB_PROGRAM;
	}

    return ERROR_NFB_SUCCESS;

}

int NFB_ProgramPhysicalPage(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data, kal_bool DALRemap)
{
    //FLASH_INFO F_info;
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 NFBStatus = -1,k;
    kal_uint32 zone_len;

    if (DAL_is_initialized == 0)
    {
        NFBStatus = DAL_init();
        force_ASSERT( NFBStatus == FS_NO_ERROR ,NFBStatus ,0 ,0);
    }

    //DAL_FDM_Flash_Info_Init (&F_info, 0);
    if ( PhyBlock==0xFFFFFFFF && PhyPage==0xFFFFFFFF ) /*1st access access of NFB*/
    {
        return Flash_Info.deviceInfo_CE[0].IOWidth;
    }

    DAL_NAND_Reset();

    zone_len = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);

    /*calculate the DAL parameter*/
    zone_off = PhyBlock/zone_len;
    PhyBlock -= zone_off*zone_len;

    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (PhyBlock/Flash_Info.bankNum);
    }

    PhyPage = PhyPage*Flash_Info.bankNum + PhyBlock%Flash_Info.bankNum ;

    NFBStatus = DAL_CheckBadBlock (DALRemap ? CODE_ACC : RAW_ACC, zone_off,b_arr, PhyBlock%Flash_Info.bankNum, KAL_FALSE, NFB_tmp_D_Buff, NFB_tmp_S_Buff);

    if ( NFBStatus != MTD_STATUS_NO_ERROR )
    {
        return ERROR_NFB_BAD_BLOCK;
    }

    kal_mem_set(NFB_tmp_S_Buff, 0xFF, 64);

	NFBStatus = DAL_ProgramPage(DALRemap ? CODE_ACC : RAW_ACC, zone_off, b_arr, PhyPage, 1, Data, (kal_uint8*)NFB_tmp_S_Buff) & 0xffff;

	if (NFBStatus) {
		// Program failure.
		return ERROR_NFB_PROGRAM;
	}

    return Flash_Info.pageSize;
}

int	NFB_MarkBadBlock(kal_uint32 PhyBlock, kal_bool DALRemap)
{
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 NFBStatus = -1,k;
    kal_uint32 zone_len;

    if ( DAL_is_initialized == 0 )
    {
        NFBStatus = DAL_init();
        force_ASSERT( NFBStatus == FS_NO_ERROR ,NFBStatus ,0 ,0);
    }

    DAL_NAND_Reset();

    zone_len = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);

    /*calculate the DAL parameter*/
    zone_off = PhyBlock/zone_len;
    PhyBlock -= zone_off*zone_len;

    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (PhyBlock/Flash_Info.bankNum);
    }

	NFBStatus = DAL_MarkBlockBad(DALRemap ? CODE_ACC : RAW_ACC, zone_off, b_arr, PhyBlock%Flash_Info.bankNum, KAL_TRUE, NFB_tmp_D_Buff, NFB_tmp_S_Buff);

	if (NFBStatus) {
		return ERROR_NFB_PROGRAM;
	}

    return ERROR_NFB_SUCCESS;

}

int	NFB_ProgramPhysicalPageWithSpare(kal_uint32 PhyBlock, kal_uint32 PhyPage, void *Data, void *Spare, kal_bool DALRemap)
{
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 NFBStatus = -1,k;
    kal_uint32 zone_len;

    if ( DAL_is_initialized == 0 )
    {
        NFBStatus = DAL_init();
        force_ASSERT( NFBStatus == FS_NO_ERROR ,NFBStatus ,0 ,0);
    }

    DAL_NAND_Reset();

    zone_len = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);

    /*calculate the DAL parameter*/
    zone_off = PhyBlock/zone_len;
    PhyBlock -= zone_off*zone_len;

    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (PhyBlock/Flash_Info.bankNum);
    }

    PhyPage = PhyPage*Flash_Info.bankNum + PhyBlock%Flash_Info.bankNum ;

    NFBStatus = DAL_CheckBadBlock (DALRemap ? CODE_ACC : RAW_ACC, zone_off,b_arr, PhyBlock%Flash_Info.bankNum, KAL_FALSE, NFB_tmp_D_Buff, NFB_tmp_S_Buff);

    if ( NFBStatus != MTD_STATUS_NO_ERROR )
    {
        return ERROR_NFB_BAD_BLOCK;
    }

	NFBStatus = DAL_ProgramPage(DALRemap ? CODE_ACC : RAW_ACC, zone_off, b_arr, PhyPage, 1, (kal_uint8*)Data, (kal_uint8*)Spare) & 0xffff;

	if (NFBStatus) {
		// Program failure.
		return ERROR_NFB_PROGRAM;
	}

    return Flash_Info.pageSize;

}

kal_int32 NFB_ReadPhysicalPage(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data)
{
    kal_uint8 zone_off;
    #if defined(__SNAND_THIRD_ROM_RECHARGE__)
    kal_uint8 retry_cnt = 0;
    kal_uint32 PhyPageOri = PhyPage;
    kal_int32  RechargeStatus = SNAND_TRR_NO_ERROR;
    #endif
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 NFBStatus = -1,k;
    static kal_uint32 zone_len = DWORD_INVALID;
    static kal_uint32 blockStatus[3] = {DWORD_INVALID,DWORD_INVALID,DWORD_INVALID}; /*record block status*/
#if ( defined(__EMULATE_NFB_BIT_ERROE__) )
    FLASH_INFO F_info;
	kal_bool CompareError = KAL_FALSE;
#endif // ( defined(__EMULATE_NFB_BIT_ERROE__) )

    if ( DAL_is_initialized == 0 )
    {
        NFBStatus = DAL_init();
        force_ASSERT( NFBStatus == FS_NO_ERROR ,NFBStatus ,0 ,0);
    }

NFB_ReadPhysicalPage_Retry:

    //DAL_FDM_Flash_Info_Init (&F_info, 0);   // 2010.1.11 mtk02493 remark for useless
    if ( PhyBlock==0xFFFFFFFF && PhyPage==0xFFFFFFFF ) /*1st access access of NFB*/
    {
        return Flash_Info.deviceInfo_CE[0].IOWidth;
    }

    DAL_NAND_Reset();

    if (zone_len == DWORD_INVALID)
    {
        zone_len = zonePage(0);
    }

    /*calculate the DAL parameter*/
    zone_off = PhyBlock/zone_len;
    PhyBlock -= zone_off*zone_len;

    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (PhyBlock/Flash_Info.bankNum);
    }

    PhyPage = PhyPage * Flash_Info.bankNum + PhyBlock % Flash_Info.bankNum ;

    get_MTD_lock(); /*protect blockStatus*/

    if ( (blockStatus[0]==zone_off) &&
    	 (blockStatus[1]==PhyBlock) )
    {
        free_MTD_lock();
    }
    else
    {
        free_MTD_lock();
        NFBStatus = DAL_CheckBadBlock (CODE_ACC, zone_off,b_arr, PhyBlock%Flash_Info.bankNum,KAL_FALSE,NFB_tmp_D_Buff,NFB_tmp_S_Buff);
        get_MTD_lock();
        blockStatus[0]=zone_off;
        blockStatus[1]=PhyBlock;
        blockStatus[2]=NFBStatus;
        free_MTD_lock();
    }

    if ( blockStatus[2] != MTD_STATUS_NO_ERROR )
    {
        return ERROR_NFB_BAD_BLOCK;
    }

#if ( defined(__EMULATE_NFB_BIT_ERROE__) )
    DAL_FDM_Flash_Info_Init (&F_info, 0);   // 2010.1.11 mtk02493 move to here
	EmulateBitError(CODE_ACC, zone_off, b_arr, PhyPage, F_info.SectorNumPerPage, D_Buff, S_Buff);

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )
#if defined(__UBL__)
	dbg_print("NFB download into address %xh\n\r", Data);
#else // defined(__UBL__)
    nandlog_print("NFB download into address %xh\r\n", Data);

#endif // !defined(__UBL__)
#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )

#endif // ( defined(__EMULATE_NFB_BIT_ERROE__) )

    #if defined(__SNAND_THIRD_ROM_RECHARGE__)
    if (0 == g_snand_trr_initialized)
    {
        snand_trr_init();
    }
    #endif  // __SNAND_THIRD_ROM_RECHARGE__

    NFBStatus = DAL_ReadPage (CODE_ACC, zone_off, b_arr, PhyPage, 1, Data, (kal_uint8*)NULL); /*null spare buff point mean do not care spare data*/

    NFBStatus = NFBStatus & 0xffff0000;

    #if defined(__SNAND_THIRD_ROM_RECHARGE__)

    // check if in third rom

    if (1 == g_snand_trr_initialized)
    {
        if ((PhyBlock >= g_snand_trr_rom1_block_begin) &&
            (PhyBlock <= g_snand_trr_rom1_res_block_end) &&
            (PhyBlock != g_snand_trr_rom1_map_block))   // ROM1's map block does not support re-charge
        {
            #if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
            {
                if ((KAL_TRUE == snand_trr_test_if_trigger_recharge()) &&
                    (0 == retry_cnt))
                {
                    NFBStatus = MTD_STATUS_ERROR;   // trigger recharge
                }
            }
            #endif  // __SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__

            if ((MTD_STATUS_ERROR == NFBStatus) && (3 > retry_cnt))
            {
                get_MTD_lock();

                g_snand_trr_target_block = PhyBlock;

                #if defined(__SNAND_THIRD_ROM_RECHARGE_AUTO_TEST__)
                snand_trr_test_set_reset_position();
                #endif

                RechargeStatus = snand_trr_recharge(0, &PhyBlock);

                PhyPage = PhyPageOri;

                free_MTD_lock();

                retry_cnt++;

                if (SNAND_TRR_NO_ERROR == RechargeStatus)
                {
                    goto NFB_ReadPhysicalPage_Retry;
                }
            }
        }
    }
    #endif  // __SNAND_THIRD_ROM_RECHARGE__

#if ( defined(__EMULATE_NFB_BIT_ERROE__) )

	// The following needs to be tested only when secondary ROM is un-cachable.
	// Otherwise, kal_mem_cmp will corrupt the last page if the starting address is not cache line alignment.
	// That is because MTD use DMA move but kal_mem_cmp use CPU move and will have cache have the data of next oage.
	if ( kal_mem_cmp(Data, &D_Buff[_DAL_MAX_PAGE_SIZE_/4], F_info.SectorNumPerPage*0x200 - 32 ) )  {
		kal_uint32 Offset;
		for (Offset=0; Offset<Flash_Info.pageSize/4; Offset++) {
			if ( ((kal_uint32*)Data)[Offset] != D_Buff[(_DAL_MAX_PAGE_SIZE_/4)+Offset] ) {

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )

#if defined(__UBL__)
				dbg_print("NFB compare error in ECC test. Address %x. Wrong data=%x, Right data=%x\n\r", &(((kal_uint32*)Data)[Offset]),
	    			((kal_uint32*)Data)[Offset], D_Buff[(_DAL_MAX_PAGE_SIZE_/4)+Offset]);
#else // defined(__UBL__)
			    nandlog_print("NFB compare error in ECC test. Address %x. Wrong data=%x, Right data=%x\r\n", &(((kal_uint32*)Data)[Offset]),
	    			((kal_uint32*)Data)[Offset], D_Buff[(_DAL_MAX_PAGE_SIZE_/4)+Offset]);

#endif // defined(__UBL__)

#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )

			    CompareError = KAL_TRUE;
			}
		}
	}


	if (CompareError==KAL_TRUE) {

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )

#if defined(__UBL__)
		dbg_print("NFB compare error in ECC test.\n\r");
#else // defined(__UBL__)
	  	nandlog_print("NFB compare error in ECC test.\r\n");
#endif // defined(__UBL__)

#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )

		dbg_ASSERT(0);
	}

#endif // ( defined(__EMULATE_NFB_BIT_ERROE__) )

    #if defined(__FUE__)
        if ( NFBStatus == MTD_STATUS_ERROR ) {
        	return ERROR_NFB_READ;
        } else if ( NFBStatus != MTD_STATUS_NO_ERROR ) {
        	if (NFBStatus == MTD_STATUS_CORRECTED) {
        		return ERROR_NFB_ECC_CORRECTED;
        	}
        }
    #else // !__FUE__
        if (NFBStatus == MTD_STATUS_ERROR)
        {
        	return ERROR_NFB_READ;
        }
    #endif  // __FUE__

    return Flash_Info.pageSize;
}

int NFB_ReadPhysicalSpare(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data, kal_bool chksum)
{
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 NFBStatus = -1,k;
    kal_uint32 zone_len = DWORD_INVALID;
/*	kal_uint8  *byte_ptr = NULL;
	kal_uint16 *word_ptr = NULL;
	kal_uint8  *pack_byte = NULL;
	kal_uint16 temp_val = 0;
	kal_uint16 sum_val = 0;
	kal_uint32 spare_size = 0;
	kal_uint32 i = 0;*/


    if ( DAL_is_initialized == 0 )
    {
        NFBStatus = DAL_init();
        force_ASSERT( NFBStatus == FS_NO_ERROR ,NFBStatus ,0 ,0);
    }
    if ( PhyBlock==0xFFFFFFFF && PhyPage==0xFFFFFFFF ) /*1st access access of NFB*/
    {
        return Flash_Info.deviceInfo_CE[0].IOWidth;
    }

    DAL_NAND_Reset();

    zone_len = zonePage(0);

    /*calculate the DAL parameter*/
    zone_off = PhyBlock/zone_len;
    PhyBlock -= zone_off*zone_len;

    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (PhyBlock/Flash_Info.bankNum);
    }

    PhyPage = PhyPage*Flash_Info.bankNum + PhyBlock%Flash_Info.bankNum ;

    NFBStatus = DAL_ReadPage (CODE_ACC, zone_off, b_arr, PhyPage, 1, (kal_uint8*)NFB_tmp_D_Buff, (kal_uint8*)Data) & 0xffff0000;

	NFBStatus = ERROR_NFB_SUCCESS;

   return NFBStatus;
}

kal_int32 NFB_ReadPhysicalPageWithSpare(kal_uint32 PhyBlock, kal_uint32 PhyPage, kal_uint8* Data)
{
    //FLASH_INFO F_info;
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 NFBStatus = -1,k;
    static kal_uint32 zone_len = DWORD_INVALID;
    static kal_uint32 blockStatus[3] = {DWORD_INVALID,DWORD_INVALID,DWORD_INVALID}; /*record block status*/

    if ( DAL_is_initialized == 0 )
    {
        NFBStatus = DAL_init();
        force_ASSERT( NFBStatus == FS_NO_ERROR ,NFBStatus ,0 ,0);
    }
    //DAL_FDM_Flash_Info_Init (&F_info, 0);  //2010.01.12 kuohong remark
    if ( PhyBlock==0xFFFFFFFF && PhyPage==0xFFFFFFFF ) /*1st access access of NFB*/
    {
        return Flash_Info.deviceInfo_CE[0].IOWidth;
    }

    DAL_NAND_Reset();

    if (zone_len == DWORD_INVALID)
    {
        zone_len = (Flash_Info.CE_interleave_Flag == KAL_FALSE) ? zonePage(0) : zonePage(0) + zonePage(1);
    }

    /*calculate the DAL parameter*/
    zone_off = PhyBlock/zone_len;
    PhyBlock -= zone_off*zone_len;

    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (PhyBlock/Flash_Info.bankNum);
    }

    PhyPage = PhyPage*Flash_Info.bankNum + PhyBlock%Flash_Info.bankNum ;
    get_MTD_lock(); /*protect blockStatus*/

    if ( (blockStatus[0]==zone_off) &&
    	 (blockStatus[1]==PhyBlock) )
    {
        free_MTD_lock();
    }
    else
    {
        free_MTD_lock();
        NFBStatus = DAL_CheckBadBlock (CODE_ACC, zone_off,b_arr, PhyBlock%Flash_Info.bankNum,KAL_FALSE,NFB_tmp_D_Buff,NFB_tmp_S_Buff);
        get_MTD_lock();
        blockStatus[0]=zone_off;
        blockStatus[1]=PhyBlock;
        blockStatus[2]=NFBStatus;
        free_MTD_lock();
    }

    if ( blockStatus[2] != MTD_STATUS_NO_ERROR )
    {
        return ERROR_NFB_BAD_BLOCK;
    }

    NFBStatus = DAL_ReadPage (CODE_ACC,zone_off,b_arr,PhyPage,1,Data,(kal_uint8*)&Data[Flash_Info.pageSize]) & 0xffff0000;

    return Flash_Info.pageSize;
}

kal_int32 NFB_CheckGoodBlock2(kal_uint32 Block, kal_bool DALRemap)
{
    kal_uint32 zone_len;
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 k, retVal;

    zone_len = zonePage(0);

    /*calculate the DAL parameter*/
    zone_off = Block/zone_len;
    Block -= zone_off*zone_len;

    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (Block/Flash_Info.bankNum);
    }

    DAL_NAND_Reset();

    retVal = DAL_CheckBadBlock (DALRemap ? CODE_ACC : RAW_ACC, zone_off,b_arr, Block%Flash_Info.bankNum,KAL_FALSE,NFB_tmp_D_Buff,NFB_tmp_S_Buff);

    if (retVal == MTD_STATUS_NO_ERROR)
        return 0;
    else
        return -1;
}

kal_int32 NFB_CheckGoodBlock(kal_uint32 Block)
{
    return demp_CheckGoodBlock(Block);
}

kal_int32 demp_CheckGoodBlock(kal_uint32 Block) /*MAUI_00592819*/
{
    kal_uint32 zone_len;
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 k, retVal;

    zone_len = zonePage(0);

    /*calculate the DAL parameter*/
    zone_off = Block/zone_len;
    Block -= zone_off*zone_len;

    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (Block/Flash_Info.bankNum);
    }

    DAL_NAND_Reset();

    retVal = DAL_CheckBadBlock(CODE_ACC, zone_off, b_arr, Block%Flash_Info.bankNum,KAL_FALSE,NFB_tmp_D_Buff,NFB_tmp_S_Buff);

    if (retVal == MTD_STATUS_NO_ERROR)
        return 0;
    else
        return -1;
}
kal_int32 demp_ReadPhysicalPage(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data) /*MAUI_00592819*/
{
    kal_uint8 zone_off;
    kal_uint16 b_arr[MAX_MULTIPAGE_NUM];
    kal_int32 NFBStatus = -1,k;
    static kal_uint32 zone_len = DWORD_INVALID;
    kal_bool old_use_interrupt;
#if !defined(__FUE__) && !defined(__UBL__) && defined(__NFB_ON_DEMAND_PAGE_IN__)
    extern kal_uint32 kal_get_mytask_priority(void);
    extern NAND_MTD_LOCK nfi_mtd_lock;
    kal_int32 task_index, prio;
#endif /* !__FUE__ && !__UBL__ */

    /* Confirmed by CC, demp_ReadPhysicalPage will 100% be called after NFB_ReadPhysicalPage, so dont care DAL init stage*/
    if (zone_len == DWORD_INVALID)
    {
        zone_len = zonePage(0);
    }

    /*calculate the DAL parameter*/
    zone_off = PhyBlock/zone_len;
    PhyBlock -= zone_off*zone_len;

    for (k=0;k< Flash_Info.bankNum; k++)
    {
        b_arr[k] = (PhyBlock/Flash_Info.bankNum);
    }

    PhyPage = PhyPage*Flash_Info.bankNum + PhyBlock%Flash_Info.bankNum ;

    /* Confirmed by CC, demp_ReadPhysicalPage don't need to check bad block because demp_CheckGoodBlock will be called to know bad blocks position*/
#if !defined(__FUE__) && !defined(__UBL__) && defined(__NFB_ON_DEMAND_PAGE_IN__)
    if(nfi_mtd_lock.owner_id != NULL){
        kal_trace(SYSTRACE_GROUP_DEMP, DEMP_PAGE_LOCK_TAKEN,
                  *(kal_int32*)(((NU_TASK*)(nfi_mtd_lock.owner_id))->tc_argc), nfi_mtd_lock.lock_count);
    }
    else {
        kal_trace(SYSTRACE_GROUP_DEMP, DEMP_PAGE_LOCK_AVAILABLE);
    }
#endif /* !__FUE__ && !__UBL__ */

    get_MTD_lock();		// Need to use lock to protect use_interrupt.

#if !defined(__FUE__) && !defined(__UBL__) && defined(__NFB_ON_DEMAND_PAGE_IN__)
    kal_get_my_task_index(&task_index);
    prio = kal_get_mytask_priority();
    kal_trace(SYSTRACE_GROUP_DEMP, DEMP_PAGE_GET_LOCK, task_index, prio);
#endif /* !__FUE__ && !__UBL__ */

	DemandPageingRead = KAL_TRUE;
	old_use_interrupt = use_interrupt;
    use_interrupt = KAL_FALSE;	// Need to set FALSE to avoid context switch. If context switch, FT task in META mode will be swtich out and L1Audio get control and assert.
    NFBStatus = DAL_ReadPage (CODE_ACC,zone_off,b_arr,PhyPage,1,Data,(kal_uint8*)NULL) & 0xffff0000; /*null spare buff point mean do not care spare data*/
    use_interrupt = old_use_interrupt;
    DemandPageingRead = KAL_FALSE;

#if !defined(__FUE__) && !defined(__UBL__) && defined(__NFB_ON_DEMAND_PAGE_IN__)
    prio = kal_get_mytask_priority();
    kal_trace(SYSTRACE_GROUP_DEMP, DEMP_PAGE_FREE_LOCK, task_index, prio);
#endif /* !__FUE__ && !__UBL__ */

    free_MTD_lock();

    if ( NFBStatus == MTD_STATUS_ERROR )
        return -1;
    else
        return Flash_Info.pageSize;
}

#endif /* _NAND_FLASH_BOOTING_ || (__UP_PKG_ON_NAND__ && __SPI_NAND_SUPPORT__) */

#if defined(__SECURITY_OTP__)&& defined(__SPI_NAND_SUPPORT__)

kal_int32 DAL_OTPAccess(kal_int32 accesstype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{

	kal_int32 Status, PageAddr, AccessLength=0;
	kal_uint8 *BufAddr = (kal_uint8 *)BufferPtr;

	if (devDriver(0)->OTPAccess==NULL) {
		return FS_FLASH_OTP_UNKNOWERR;
	}

    if (DAL_is_initialized == 0) {
        Status = DAL_init();
        force_ASSERT(Status == FS_NO_ERROR, Status, 0, 0);
    }

    DAL_NAND_Reset();

    get_MTD_lock();


	while (1) {
	    PageAddr = Offset/Flash_Info.pageSize;
	    if (accesstype==FS_OTP_READ) {
			Status = devDriver(0)->OTPAccess(FS_OTP_READ, PageAddr, NFB_tmp_D_Buff, NFB_tmp_S_Buff);
			if (Status!=FS_NO_ERROR) {
				break;
			}
			AccessLength = Flash_Info.pageSize - (Offset % Flash_Info.pageSize);
			if (Length >= AccessLength) {
				kal_mem_cpy(BufAddr, ((kal_uint8*)NFB_tmp_D_Buff)+(Offset % Flash_Info.pageSize), AccessLength);
			} else {
				// Last time.
				kal_mem_cpy(BufAddr, ((kal_uint8*)NFB_tmp_D_Buff)+(Offset % Flash_Info.pageSize), Length);
			}
	    } else if (accesstype==FS_OTP_WRITE) {
	    	AccessLength = Flash_Info.pageSize - (Offset % Flash_Info.pageSize);
			kal_mem_set(NFB_tmp_D_Buff, 0xff, Flash_Info.pageSize);
			kal_mem_set(NFB_tmp_S_Buff, 0xff, Flash_Info.spareSize);
			if (Length >= AccessLength) {
				kal_mem_cpy(((kal_uint8*)NFB_tmp_D_Buff)+(Offset % Flash_Info.pageSize), BufAddr, AccessLength);
			} else {
				// Last time.
				kal_mem_cpy(((kal_uint8*)NFB_tmp_D_Buff)+(Offset % Flash_Info.pageSize), BufAddr, Length);
			}
			Status = devDriver(0)->OTPAccess(FS_OTP_WRITE, PageAddr, NFB_tmp_D_Buff, NFB_tmp_S_Buff);
	    } else {
			Status = devDriver(0)->OTPAccess(accesstype, PageAddr, NULL, NULL);
			break;
	    }

		Offset += AccessLength;
		BufAddr += AccessLength;
		if (Length <= AccessLength) {
			Length = 0;
			break;
		} else {
			Length -= AccessLength;
		}
	}
    free_MTD_lock();

	return Status;

}

kal_int32 DAL_OTPQueryLength(kal_uint32 *LengthPtr)
{
	kal_int32 Status;

	if (devDriver(0)->OTPQueryLength==NULL) {
		return FS_FLASH_OTP_UNKNOWERR;
	}

    if (DAL_is_initialized == 0) {
        Status = DAL_init();
        force_ASSERT(Status == FS_NO_ERROR, Status, 0, 0);
    }

    DAL_NAND_Reset();

    get_MTD_lock();
    Status = devDriver(0)->OTPQueryLength(LengthPtr);
    free_MTD_lock();

	return Status;
}

#else // __SECURITY_OTP__

kal_int32 DAL_OTPAccess(kal_int32 accesstype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length)
{
	return FS_UNSUPPORTED_DRIVER_FUNCTION;
}

kal_int32 DAL_OTPQueryLength(kal_uint32 *LengthPtr)
{
	return FS_UNSUPPORTED_DRIVER_FUNCTION;
}

#endif // __SECURITY_OTP__

kal_int32 DAL_GetDeviceIDInfo(void *pInfo)
{
	FS_DeviceInfo *DeviceInfo = (FS_DeviceInfo *)pInfo;
	kal_uint32 Index;

	for (Index=0; Index<8; Index++)
    {
		DeviceInfo->DeviceInfo.NAND.DeviceID[Index] = Flash_Info.deviceInfo_CE[0].ID_info[Index];
	}

	DeviceInfo->DeviceInfo.NAND.PageSize = Flash_Info.deviceInfo_CE[0].pageSize + Flash_Info.deviceInfo_CE[0].spareSize;
	DeviceInfo->DeviceInfo.NAND.BlockSize = Flash_Info.deviceInfo_CE[0].blockPage * DeviceInfo->DeviceInfo.NAND.PageSize;
	DeviceInfo->DeviceInfo.NAND.DeviceSize = Flash_Info.deviceInfo_CE[0].deviceSize + Flash_Info.deviceInfo_CE[1].deviceSize;

	return FS_NO_ERROR;
}
kal_uint32 DAL_GetBlockSize(void)
{
    return (Flash_Info.deviceInfo_CE[0].blockPage*Flash_Info.deviceInfo_CE[0].pageSize);
}
kal_uint32 DAL_GetPageSize(void)
{
    return (Flash_Info.deviceInfo_CE[0].pageSize);
}

kal_int32 DAL_LPage2PPage(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank, kal_uint16 PageAddr)
{
    kal_uint16  i;
    kal_uint32 retVal = MTD_STATUS_NO_ERROR;

    get_MTD_lock();

    #if defined (_NAND_FLASH_BOOTING_) || defined(__NANDFDM_MULTI_INSTANCE__) || (defined(__UP_PKG_ON_NAND__) && defined(__SPI_NAND_SUPPORT__))
    if (Acc_Type == FAT_ACC)
    {
        for (i=0;i< Flash_Info.bankNum; i++)
        {
            #if defined(__NANDFDM_TOTAL_BBM__)
            if(Bank[i]&BBM_GLOBAL_ADDR)
            {
                DAL_Bank_Array[i] = Bank[i];
            }
            else
            #endif //#if defined(__NANDFDM_TOTAL_BBM__)

	        if (ZoneNo == 0)
	        {
                #if !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset;
                #else // !defined(__NANDFDM_MULTI_INSTANCE__)
                DAL_Bank_Array[i] = Bank[i] + FAT_Start_Section_Offset[CurDiskIndex];
                #endif // !defined(__NANDFDM_MULTI_INSTANCE__)
	        } else {
                DAL_Bank_Array[i] = Bank[i];
	        }
        }

        Bank = DAL_Bank_Array;

        #if !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum;
        #else  // !defined(__NANDFDM_MULTI_INSTANCE__)
        ZoneNo += FAT_Start_ZoneNum[CurDiskIndex];
        #endif	// !defined(__NANDFDM_MULTI_INSTANCE__)
    }
    #else
    if (Acc_Type != FAT_ACC)
    {
        dbg_ASSERT(0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }
    #endif /* _NAND_FLASH_BOOTING_ || defined(__NANDFDM_MULTI_INSTANCE__) || (__UP_PKG_ON_NAND__ && __SPI_NAND_SUPPORT__)) */

    /*boundary check*/
    if ( (ZoneNo >= Flash_Info.zoneNum)  )
    {
        force_ASSERT(0,ZoneNo,0,0);
        free_MTD_lock();
        return MTD_STATUS_PARA_ERROR;
    }

    kal_mem_set(&Mtd_para, 0x00,sizeof(Mtd_para));
    Add_Cnvt.zoneNum = ZoneNo ;
    Add_Cnvt.bankArry = Bank;
    Add_Cnvt.pageIdx = PageAddr;
    addressMap(&Add_Cnvt);
    retVal = Add_Cnvt.phyPage; // Add_Cnvt.ce reserved for future use
    Mtd_para.ce = Add_Cnvt.ce;

    if (Flash_Info.deviceInfo_CE[Add_Cnvt.ce].deviceSize*1024*1024 <= Flash_Info.pageSize*Add_Cnvt.phyPage)
    {
      dbg_ASSERT (0);
      free_MTD_lock();
      return MTD_STATUS_PARA_ERROR;
    }

    free_MTD_lock();

    return retVal;
}
#endif  // __SPI_NAND_SUPPORT__ && __NAND_FDM_50__
