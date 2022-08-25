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
 *   AP_BtSS.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines Big-Tiny System Switch Stuffs
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define __AP_BTSS_C__

#if !defined(__TINY_SYS__)

/* include AP_BtSS.h to let those exported variables defined */
#include "AP_BtSS.h"

void AP_BtSS_init(void)
{
	__AP_local_BtSS_mode = AP_BTSS_INVALID_MODE;
}

kal_int32 AP_BtSS_idle_handler(void)
{
	return -1 * __LINE__;
}

#else /* defined(__TINY_SYS__) */

#include "cache_hw_int.h"
#include "cache_sw_int.h"
#include "kal_general_types.h"
#include "maui_GFH_body.h"
#include "br_GFH_error.h"
#include "kal_trace.h"
#include "kal_public_defs.h"
#include "kal_internal_api.h"
#include "kal_public_api.h"
#include "hisr_config.h"
#include "intrCtrl.h"
#include "AP_BtSS.h"
#include "AP_BtSS_callbacks.h"
#include "ts_mem_config.h"
#include "custom_tsconfig.h"
#include "wdt_hw.h"
#include "wdt_sw.h"
#include "AP_CSCI_static.h"
#include "csci.h"
#include "kal_ts_error_handling.h"
#include "emi_tiny.h"

/*
    Macro Declaration
*/

#define AP_BtSS_CleanAndInvalidateCache() \
    MTKL1CACHE_CleanAllCacheLines(); \
    MTKL1CACHE_InvalidAllCacheLines();

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))
#endif

#define TINY_SW_LISR_CODE SW_TRIGGER_CODE2


/*
    Prototype Declaration
*/

static kal_int32 _AP_BtSS_SwitchToTiny(AP_BtSS_mode mode);
static void AP_BtSS_BackupAPTcmInfo(void);
static void AP_BtSS_RetrieveAPTcmInfo(void);
static void AP_BtSS_BackupDSPRamInfo(void);
static void AP_BtSS_RetrieveDSPRamInfo(void);
static void AP_BtSS_StoreAPShareInfo(void);
static void AP_BtSS_ConfigCacheMPUSetting(void);
static void AP_BtSS_RestoreCacheMPUSetting(void);
static void AP_BtSS_LoadTYImageFromEMI(void);
static void AP_BtSS_LoadTYImageFromFlash(void);
static void AP_BtSS_RaisePLL(void);
static void AP_BtSS_DownPLL(void);
static void AP_BtSS_RestoreWDTSetting(void);
void AP_BtSS_JumpToTinyEntry(void);

#if defined(MT6260)
    static void AP_BtSS_RetrieveExcVectorTable(void);
#endif


/*
    Extern Declaration
*/

extern kal_uint32 Image$$INTSRAM_CODE$$Base;
extern kal_uint32 Image$$INTSRAM_DUMMY_END$$Base;
extern kal_uint32 Image$$ROM$$Base;
extern kal_uint32 INT_Table_END;
CSCI_EXTERN_VAR(kal_uint32,g_TINY_CSD_Mem_Dump_Flag);

extern void AP_BtSS_SaveContextAndRun(void);

/*lei: add common header files for timer status sync temporarly.*/
#include "timer_status_sync.h"
//extern void NU_TIMER_Backup(kal_uint32 addr);
extern void USCOUNTER_Backup(void);
extern void TMC_Timer_Interrupt(void);
extern kal_bool AP_check_timer_allow_for_hibernation(Sleep_Time *sleep_info);


/*
    Global Declaration
*/

/* Put all BtSS related code to EMI, due to NOR can't be access@26M */
#pragma arm section code = "SNORCODE", rodata = "SNORCONST"


kal_uint32 ap_tcm_backup_addr=AP_INTSRAM_BAK_BASE;
kal_uint32 ty_image_backup_addr=TS_MM_DUMP_BASE;

kal_uint32 dspram_backup_addr=AP_DSPRAM_BAK_BASE;
kal_uint32 dspram_cpsz = MAX_AP_DSPRAM_BAK_SIZE;

#if defined(MT6260)
kal_uint32 evt_addr = (kal_uint32)&Image$$ROM$$Base;
kal_uint32 evt_addr_end = (kal_uint32)&INT_Table_END;
#endif

kal_uint32 tcm_addr = (kal_uint32)&Image$$INTSRAM_CODE$$Base;
kal_uint32 tcm_addr_end = (kal_uint32)&Image$$INTSRAM_DUMMY_END$$Base;

kal_uint32 saved_cache_con;
kal_uint32 saved_mpu_proto[MPU_CHANNEL_NUM];
kal_uint32 saved_mpu_end[MPU_CHANNEL_NUM];

kal_uint32 tiny_rom1_base, tiny_rom2_base;
kal_uint32 tiny_lv1_base, tiny_lv2_base;

kal_hisrid tiny_hisrid = 0;
static kal_uint32 enable_switch_to_tiny = 1;

CSCI_DEFINE_VAR(AP_BtSS_mode, __BtSS_mode_in_csci);
CSCI_DEFINE_VAR(kal_uint32, tiny_entry_return_address);
CSCI_DEFINE_VAR(kal_uint32,Tiny_stack_error_code);
CSCI_DEFINE_VAR(kal_uint32, TS_BtSS_switch_clients); /* For debugging */

extern kal_bool is_Ts_memory_dump;

struct {
	kal_uint32 resume_cnt;
	kal_uint32 suspend_cnt;
	kal_uint32 hibernation_cnt;
	kal_uint32 hibernation_boot_cnt;
	kal_uint32 hisr_cnt;
	kal_uint32 invalid_mode_cnt;
	kal_int32 last_idle_handler_ret;
} AP_BtSS_stats;

#pragma arm section code = "INTSRAM_ROCODE", rwdata = "INTSRAM_RW" , rodata = "INTSRAM_RODATA" , zidata = "INTSRAM_ZI"


// FIXME: to build emi_tiny.c
unsigned int dqin_dly;
unsigned int dqsin_dly;


////////////////////////////////////////////////////////////////////////////////
// GPT
////////////////////////////////////////////////////////////////////////////////
#if !defined (GPT_base)
#define GPT_base                    (0xA00C0000) /*General Purpose Timer                                              */
#endif
#define GPT4_CON  ((volatile unsigned int *)(GPT_base + 0x28))
#define GPT4_DAT  ((volatile unsigned int *)(GPT_base + 0x2C))
#define GPT4_EN   (1<<0)
#define GPT4_LOCK (1<<1)

#define GPT4_MAX_TICK_CNT   ((U32)0xFFFFFFFF)

// 26MHz setting
#define GPT4_MAX_US_TIMEOUT ((U32)164926744)    // 0xFFFFFFFF * 38.4ns / 1000
#define GPT4_1US_TICK       ((U32)26)           //    1000 / 38.4ns = 26.042
// 26MHz: 1us = 26.042 ticks
#define TIME_TO_TICK_US(us) ((us)*GPT4_1US_TICK)

void __gpt4_busy_wait_us(U32 timeout_us);

#define GPT4_STOP() do { *GPT4_CON = 0; } while(0)

#define GPT4_INIT()                                     \
        do {                                               \
                /* default power on GPT  */             \
                                                        \
                /* // clear GPT4 first  */              \
                *GPT4_CON = 0;                          \
                                                        \
                /* // enable GPT4 without lock  */      \
                *GPT4_CON |= (GPT4_EN);                  \
        } while(0)


#define GPT4_GET_CURRENT_TICK() (*GPT4_DAT)

static void __gpt4_busy_wait_us(U32 timeout_us)
{
    U32 start_tick, timeout_tick;
    register U32 cur_tick;
    register U32 elapse_tick;

    GPT4_INIT();

    // get timeout tick
    timeout_tick  = TIME_TO_TICK_US(timeout_us);
    start_tick    = GPT4_GET_CURRENT_TICK();

    // wait for timeout
    do {
            // get current tick
            cur_tick = GPT4_GET_CURRENT_TICK();

            // check elapse time
            if( start_tick <= cur_tick ) {
                    elapse_tick = cur_tick - start_tick;
            }
            else {
                    elapse_tick = (GPT4_MAX_TICK_CNT-start_tick) + cur_tick;
            }

            // check if timeout
    } while ( timeout_tick > elapse_tick );
}

#define MD2GSYS_AHB_CON0 	((volatile unsigned int *)0x82C00214)
#define PMIC_VCORE_CON3		((volatile unsigned int *)0xA070023C)
#define CLK_CONDH           ((volatile unsigned int *)0xA001011C)
#define CLK_CONDE           ((volatile unsigned int *)0xA0010110)
#define CLK_CONDC           ((volatile unsigned int *)0xA0010108)
#define CLK_CONDF           ((volatile unsigned int *)0xA0010114)
#define PMIC_VCORE_CON0		((volatile unsigned int *)0xA0700230)

void switch_to_sensor_mode(void)
{
	unsigned int temp_reg;

	//enable VCORE VOSEL soft setting and set VCORE sleep mode voltage
	temp_reg = *PMIC_VCORE_CON3; //0xA070023C
	temp_reg = (temp_reg & 0xFE07) | 0x0008;
	*PMIC_VCORE_CON3 = temp_reg;

	//force DSP clock on while mask modem cock request
	temp_reg = *CLK_CONDH; //0xA001011C
	temp_reg &= 0xEFFF;
	*CLK_CONDH = temp_reg;

	//force slow clock on
	temp_reg = *CLK_CONDE; //0xA0010110
	temp_reg |= 0x2000;
	*CLK_CONDE = temp_reg;

	//all clock switch to XTAL path
	*CLK_CONDC = 0x8008; //0xA0010108
	while (*CLK_CONDC != 0x8008);

	//mask topsm PLL clock request, and turn off PLL
	*CLK_CONDF = 0x4000; //0xA0010114
	__gpt4_busy_wait_us(32);

	//VCORE change to lower power, VCORE=1.1v
	temp_reg = *PMIC_VCORE_CON0; //0xA0700230
	temp_reg &= 0xFE0F;
	*PMIC_VCORE_CON0 = temp_reg;
	__gpt4_busy_wait_us(320);

	//MD2G Power on sequence
	*((volatile unsigned int *)0x83000500) |= 0x1;
	*((volatile unsigned int *)0x83010A14) = 0x1;
	__gpt4_busy_wait_us(66);
	while (*((volatile unsigned int *)0x83010A24) !=0x1);

	//dynamically turn on/off AHB slave clock
	temp_reg = *MD2GSYS_AHB_CON0; //0x82C00214
	temp_reg |= 0x00000200;
	*MD2GSYS_AHB_CON0 = temp_reg;

	// Freeze DSP for safty.
	// L1D_DSP_FreezeDSP(0x3);
	*((volatile unsigned int *)0x83030000) = 0x6;

	// DSP in reset mode has more power consumption than boot mode.
	// Let DSP enter boot mode for better power consumption.
	// L1D_DSP_EnterBootMode(0x3);
	*((volatile unsigned int *)0x83030000) = 0x7;

	//set exception slave
	*((volatile unsigned int *)0xA0510008) = 0x1;
	*((volatile unsigned int *)0xA05000E0) |= 0x80000000;
}

void switch_to_ap_mode(void)
{
	unsigned int temp_reg;

	//VCORE change to higher power, VCORE=1.3v
	temp_reg = *PMIC_VCORE_CON0; //0xA0700230
	temp_reg = (temp_reg & 0xFE0F) | 0x0080;
	*PMIC_VCORE_CON0 = temp_reg;
	__gpt4_busy_wait_us(320);

	//unmask topsm PLL clock request, turn on PLL
	*CLK_CONDF = 0x0000; //0xA0010114
	__gpt4_busy_wait_us(120);

	//clock switch to XTAL + PLL path
	*CLK_CONDC = 0xB621; //0xA0010108
	while (*CLK_CONDC != 0xB621);

	//release force DSP clock on while mask modem cock request
	temp_reg = *CLK_CONDH; //0xA001011C
	temp_reg |= 0x1000;
	*CLK_CONDH = temp_reg;

	//release force slow clock on
	temp_reg = *CLK_CONDE; //0xA0010110
	temp_reg &= 0xDFFF;
	*CLK_CONDE = temp_reg;

	//set exception slave as normal
	*((volatile unsigned int *)0xA0510008) = 0x0;
	*((volatile unsigned int *)0xA05000E0) &= 0x7FFFFFFF;

	//MD2G Power off sequence
	*((volatile unsigned int *)0x83010A18) = 0x1;
	*((volatile unsigned int *)0x83000500) &= 0xFFFFFFFE;
	__gpt4_busy_wait_us(33);
}

#pragma arm section code, rodata, rwdata


/* main function of BtSS entry called from Idle Task */

static kal_int32 _AP_BtSS_SwitchToTiny(AP_BtSS_mode mode)
{
	if (!enable_switch_to_tiny)
		return -1 * __LINE__;

    /* Get the required addr info before switch to 26M */
    /* Note: must ensure NOT to access NOR under 26M */
    custom_get_TINYSYS_ROM1_LV_Info(&tiny_lv1_base);
    custom_get_TINYSYS_ROM2_LV_Info(&tiny_lv2_base);


    if (mode==AP_BTSS_SUSPEND)
    {
        /* Backup 12K TCM to external ram */
        AP_BtSS_BackupAPTcmInfo();

        /* Down the PLL to 26M for power saving */
        AP_BtSS_DownPLL();

        /* Backup 45K DSP Ram to external ram */
        AP_BtSS_BackupDSPRamInfo();

        /* Disable MMU, MPU & Config all cache to 44K TCM */
        AP_BtSS_ConfigCacheMPUSetting();

        /* Load tiny binary into TCM from EMI, due to NOR must at 260M access */
        AP_BtSS_LoadTYImageFromEMI();

        /*
               * Inform Tiny it's suspend mode
               * We set the share info variable to SUSPEND mode at the last step.
               * Keep the time window of `__BtSS_mode_in_csci is set` as short as possible
               * Tiny system will clear this varaible when it boots up (TS_BtSS_init())
               */
        AP_BtSS_set_mode(AP_BTSS_SUSPEND);

        /* Store AP mode share info to TS visiable space */
        /* note: after this point CSCI info won't be exchanged */
        AP_BtSS_StoreAPShareInfo();

        /* Save ALL mode CPU registers and jump to Tiny */
        AP_BtSS_SaveContextAndRun();

        /*
                  Suspend Wakeup From Here for Resuming...
		*/

        #if defined(MT6260)
		    /* Copy exception table from ROM to low vector address */
            AP_BtSS_RetrieveExcVectorTable();
		#endif

		if (g_TINY_CSD_Mem_Dump_Flag == TINY_DUMP)
		{
			is_Ts_memory_dump = KAL_TRUE;
			CSD_AP_Read_EMI_Data(Tiny_stack_error_code);
		}
		else
		{
			is_Ts_memory_dump = KAL_FALSE;
		}

        /* Enable MMU, MPU & Config back to 32K cache + 12K TCM */
        AP_BtSS_RestoreCacheMPUSetting();

	    /* Restore 12K TCM from external ram */
        AP_BtSS_RetrieveAPTcmInfo();

        /* Restore 45K DSP Ram from external ram */
        AP_BtSS_RetrieveDSPRamInfo();

        /* Raise PLL after recover is done */
        AP_BtSS_RaisePLL();

		CSD_AP_Stack_error();
		/* WDT reinit because tiny had set WDT */
		AP_BtSS_RestoreWDTSetting();

    }
    else if (mode==AP_BTSS_HIBERNATION)
    {
        /* Down the PLL to 26M for power saving */
        AP_BtSS_DownPLL();

        /* Disable MMU, MPU & Config all cache to 44K TCM */
        AP_BtSS_ConfigCacheMPUSetting();

        /* Load tiny binary into TCM from EMI, due to NOR must at 260M access */
        AP_BtSS_LoadTYImageFromEMI();

        /*
               * Inform Tiny it's hibernation mode
               * We set the share info variable to SUSPEND mode at the last step.
               * Keep the time window of `__BtSS_mode_in_csci is set` as short as possible
               * Tiny system will clear this varaible when it boots up (TS_BtSS_init())
               */
        AP_BtSS_set_mode(AP_BTSS_HIBERNATION);

        /* Store AP mode share info to TS visiable space */
        /* note: after this point CSCI info won't be exchanged */
        AP_BtSS_StoreAPShareInfo();

        /* Jump to Tiny directly w/o saving context */
        AP_BtSS_JumpToTinyEntry();

        /*
		    Should never return here...
             */

        while(1);

    }

	return 0;
}


/* When power on or hibernate init, load TY image from NOR to EMI */

static void AP_BtSS_LoadTYImageFromFlash(void)
{
    kal_uint32 i=0;
    kal_uint32 count=0;
    GFH_FILE_INFO_v1 *p_gfh_file_info_rom1;
    GFH_FILE_INFO_v1 *p_gfh_file_info_rom2;
    kal_uint32 rom1_image_len;
    kal_uint32 rom2_image_len;
    kal_uint32 status = B_OK;

    custom_get_TINYSYS_ROM1_on_Flash(&tiny_rom1_base);
    custom_get_TINYSYS_ROM2_on_Flash(&tiny_rom2_base);

    // perform FILE_INFO basic check
    p_gfh_file_info_rom1 = (GFH_FILE_INFO_v1 *)tiny_rom1_base;
    status = GFH_FILE_INFO_BasicCheck(p_gfh_file_info_rom1);

    if( E_ERROR <= status )
    {
        ASSERT(0);
    }

    p_gfh_file_info_rom2 = (GFH_FILE_INFO_v1 *)tiny_rom2_base;
    status = GFH_FILE_INFO_BasicCheck(p_gfh_file_info_rom2);

    if( E_ERROR <= status )
    {
        ASSERT(0);
    }

    rom1_image_len = p_gfh_file_info_rom1->m_file_len;
    rom2_image_len = p_gfh_file_info_rom2->m_file_len;

    for (i = 0; i < ((rom1_image_len+3) >> 2); i++)
    {
        *((volatile kal_uint32 *)ty_image_backup_addr + i )= *((volatile kal_uint32 *)tiny_rom1_base + i );
	    count = i+1;
    }

    for (i = 0; i < ((rom2_image_len+3) >> 2); i++)
    {
        *((volatile kal_uint32 *)ty_image_backup_addr + count + i )= *((volatile kal_uint32 *)tiny_rom2_base + i );
    }

}


/* When suspend and hibernate transition, load TY image from EMI to TCM */

static void AP_BtSS_LoadTYImageFromEMI(void)
{
    kal_uint32 i=0;
    kal_uint32 count=0;
    GFH_FILE_INFO_v1 *p_gfh_file_info_lv1;
    GFH_FILE_INFO_v1 *p_gfh_file_info_lv2;
    kal_uint32 lv1_image_len;
    kal_uint32 lv2_image_len;
    //kal_uint32 status = B_OK;

    // Check GFH again in case EMI error or corruption
    p_gfh_file_info_lv1 = (GFH_FILE_INFO_v1 *)ty_image_backup_addr;

/*
    status = GFH_FILE_INFO_BasicCheck(p_gfh_file_info_lv1);

    if( E_ERROR <= status )
    {
        ASSERT(0);
    }
*/

	lv1_image_len = p_gfh_file_info_lv1->m_file_len;

    p_gfh_file_info_lv2 = (GFH_FILE_INFO_v1 *)(ty_image_backup_addr+lv1_image_len);

/*
    status = GFH_FILE_INFO_BasicCheck(p_gfh_file_info_lv2);

    if( E_ERROR <= status )
    {
        ASSERT(0);
    }
*/

    lv2_image_len = p_gfh_file_info_lv2->m_file_len;

    for (i = 0; i < ((lv1_image_len+3) >> 2); i++)
    {
        *((volatile kal_uint32 *)tiny_lv1_base + i )= *((volatile kal_uint32 *)ty_image_backup_addr + i );
	    count = i+1;
    }

    for (i = 0; i < ((lv2_image_len+3) >> 2); i++)
    {
        *((volatile kal_uint32 *)tiny_lv2_base + i )= *((volatile kal_uint32 *)ty_image_backup_addr + count + i );
    }

}

static void AP_BtSS_ConfigCacheMPUSetting(void)
{
    kal_uint8 index;

    /* Backup L1 cache register */
    saved_cache_con = *CACHE_CON;

    /* Disable MCEN/MPEN */
    *CACHE_CON &= ~(0x0f);

    /* Backup all MPU registers */
    for (index=0; index<MPU_CHANNEL_NUM; index++)
    {
		saved_mpu_proto[index] = *(MPU_PROT0+index);
		saved_mpu_end[index] = *(MPU_PROT0_END+index);
    }

    /* Invalid and Flush all cache lines */
    AP_BtSS_CleanAndInvalidateCache();

    /* Set 44KB TCM, 0kB cache (no cache) */
	*CACHE_CON = NO_CACHE;
}

static void AP_BtSS_RestoreCacheMPUSetting(void)
{
    kal_uint8 index;

    /* Restore all MPU registers */
    for (index=0; index<MPU_CHANNEL_NUM; index++)
    {
		*(MPU_PROT0+index) = saved_mpu_proto[index];
		*(MPU_PROT0_END+index) = saved_mpu_end[index];
    }

    /* Restore L1 cache register, 32K cache + 12K TCM */
    *CACHE_CON = saved_cache_con;
}


void AP_BtSS_JumpToTinyEntry(void)
{
    kal_int32 jmp_addr = (kal_int32)tiny_lv1_base;
    jmp_addr += ((GFH_FILE_INFO_v1*)(jmp_addr))->m_content_offset; // should be m_jump_offset?

    tiny_entry_return_address = __return_address();

    //TODO: do error handling?
    (( void (*)(void))jmp_addr)();
}

static void AP_BtSS_RaisePLL(void){
#if defined(MT6261) || defined(MT2502) || defined(MT2501)
	switch_to_ap_mode();
	EMI_DynamicClockSwitch(EMI_CLK_130MHZ);
#endif
}
static void AP_BtSS_DownPLL(void){
#if defined(MT6261) || defined(MT2502) || defined(MT2501)
	EMI_DynamicClockSwitch(EMI_CLK_13MHZ);
	switch_to_sensor_mode();
#endif
}

static void AP_BtSS_RestoreWDTSetting(void)
{
    DRV_WDT_WriteReg(WDT_RSTINTERVAL,WDT_RSTINTERVAL_VALUE);
}

static void AP_BtSS_StoreAPShareInfo(void)
{
    AP_CSCI_backup();
}

static void AP_BtSS_BackupDSPRamInfo(void)
{
    kal_uint32 i=0;

    for (i = 0; i < ((dspram_cpsz+3) >> 2); i++)
    {
        *((volatile kal_uint32 *)dspram_backup_addr + i )= *((volatile kal_uint32 *)tiny_lv2_base + i );
    }
}

static void AP_BtSS_RetrieveDSPRamInfo(void)
{
    kal_uint32 i=0;

    for (i = 0; i < ((dspram_cpsz+3) >> 2); i++)
    {
        *((volatile kal_uint32 *)tiny_lv2_base + i )= *((volatile kal_uint32 *)dspram_backup_addr + i );
    }
}

static void AP_BtSS_BackupAPTcmInfo(void)
{
    kal_uint32 i=0;
    kal_uint32 tcm_cpsz = tcm_addr_end - tcm_addr;

    for (i = 0; i < ((tcm_cpsz+3) >> 2); i++)
    {
        *((volatile kal_uint32 *)ap_tcm_backup_addr + i )= *((volatile kal_uint32 *)tcm_addr + i );
    }
}

static void AP_BtSS_RetrieveAPTcmInfo(void)
{
    kal_uint32 i=0;
    kal_uint32 tcm_cpsz = tcm_addr_end - tcm_addr;

    for (i = 0; i < ((tcm_cpsz+3) >> 2); i++)
    {
        *((volatile kal_uint32 *)tcm_addr + i )= *((volatile kal_uint32 *)ap_tcm_backup_addr + i );
    }
}

#if defined(MT6260)

static void AP_BtSS_RetrieveExcVectorTable(void)
{
    kal_uint32 i=0;
    kal_uint32 evt_cpsz = evt_addr_end - evt_addr;

    for (i = 0; i < ((evt_cpsz+3) >> 2); i++)
    {
        *((volatile kal_uint32 *)0x0 + i )= *((volatile kal_uint32 *)evt_addr + i );
    }
}

#endif //defined(MT6260)

#pragma arm section code, rodata


int AP_BtSS_suspend(AP_BtSS_mode mode)
{
	if (mode == AP_BTSS_SUSPEND) {
		AP_BtSS_stats.suspend_cnt++;
	} else if (mode == AP_BTSS_HIBERNATION) {
		AP_BtSS_stats.hibernation_cnt++;
	}

	return 0;
}

int AP_BtSS_resume(AP_BtSS_mode mode)
{
	if (mode == AP_BTSS_SUSPEND) {
		AP_BtSS_stats.resume_cnt++;
	} else if (mode == AP_BTSS_HIBERNATION) {
		AP_BtSS_stats.hibernation_boot_cnt++;
	}

	return 0;
}

void tiny_hisr_handler(void)
{
	kal_int32 i;

	AP_BtSS_stats.hisr_cnt++;

	switch (AP_BtSS_get_mode())
	{
	case AP_BTSS_SUSPEND:
		for (i = 0; i < ARRAY_SIZE(BtSS_enter_AP_callbacks); i++)
			BtSS_enter_AP_callbacks[i](AP_BTSS_SUSPEND);
		vm_ts_ap_mode_callback(AP_BTSS_SUSPEND);
		break;
	case AP_BTSS_HIBERNATION:
		for (i = 0; i < ARRAY_SIZE(BtSS_enter_AP_callbacks); i++)
			BtSS_enter_AP_callbacks[i](AP_BTSS_HIBERNATION);
		vm_ts_ap_mode_callback(AP_BTSS_HIBERNATION);
		break;
	default:
		AP_BtSS_stats.invalid_mode_cnt++;
		break;
	}
}

static void tiny_lisr_handler(void)
{
	if (AP_BtSS_get_mode() == AP_BTSS_SUSPEND)
		timer_status_sync_enter_ap_callbacks();

	if (tiny_hisrid)
		kal_activate_hisr(tiny_hisrid);
	Deactivate_LISR(TINY_SW_LISR_CODE);
}

void AP_BtSS_init(void)
{
	/*
	  * __AP_local_BtSS_mode is a AP system global variable which is for AP_BtSS_get_mode()
	  */

	// FIXME:  Set	__AP_local_BtSS_mode according to CSCI and WDT here
	__AP_local_BtSS_mode = 0;
	AP_BtSS_LoadTYImageFromFlash();

	tiny_hisrid = kal_init_hisr(TINY_HISR);

	/* SW LISR Initilization */
	IRQ_Register_LISR(SW_code_handle2code(TINY_SW_LISR_CODE), tiny_lisr_handler, "tiny_lisr");
	IRQSensitivity(SW_code_handle2code(TINY_SW_LISR_CODE), LEVEL_SENSITIVE);
	IRQUnmask(SW_code_handle2code(TINY_SW_LISR_CODE));

	Activate_LISR(TINY_SW_LISR_CODE);

	/*
	  * AP_BtSS_set_mode() set the mode variable in share info area.
	  * Share info variable is used for
	  * 	1. detect if it's hibernation-boot when AP boots up
	  *	2. Propagate tiny system mode information from AP to TINY
	  *
	  * We have to clear the share info when AP boots up. Or
	  * If the share info mode was hibernation, AP fatal error occurs and watchdog resets.
	  * It will be determined as hibernation-boot, but which is not.
	  */
	AP_BtSS_set_mode(AP_BTSS_INVALID_MODE);

	if (HIBERNATION_EXCEPTION == AP_check_boot_up_source())
	{
		is_Ts_memory_dump = KAL_TRUE;
		CSD_AP_Read_EMI_Data(Tiny_stack_error_code);
	}
}

int AP_BtSS_SwitchToTiny(Sleep_Time *sleep_info)
{
	kal_int32 ret, i;

	if (!AP_BtSS_blocker_AP_HIBERNATION &&
		AP_check_timer_allow_for_hibernation(sleep_info) == KAL_TRUE
/*		sleep_info->sleep_status == NO_TIMER */) {
		static kal_uint32 tiny_hibernation_count;

		__AP_local_BtSS_mode = AP_BTSS_HIBERNATION;
		++tiny_hibernation_count;
	}
	else if (!AP_BtSS_blocker_AP_SUSPEND &&
		     kal_ticks_to_milli_secs(sleep_info->sleep_time) > 1800) {
		static kal_uint32 tiny_suspend_count;

		__AP_local_BtSS_mode = AP_BTSS_SUSPEND;
		++tiny_suspend_count;
	}
	else {
		ret = -1 * __LINE__;
		goto out;
	}

	for (i = 0; i < ARRAY_SIZE(BtSS_exit_AP_callbacks); i++) {
		ret = BtSS_exit_AP_callbacks[i](__AP_local_BtSS_mode);
		if (ret < 0)
		{
			return ret;
		}
	}

	ret = _AP_BtSS_SwitchToTiny(__AP_local_BtSS_mode);

	if (ret == 0) {
		/* Should never return here for Hibernation */
		Activate_LISR(TINY_SW_LISR_CODE);
	}

	// TODO: Save RTC time to check the sleep time

out:
	return ret;
}

#include "msdc_def.h"
extern kal_uint32 LockIRQ(void);
extern void RestoreIRQ(kal_uint32 irq);
extern kal_bool OSTD_CheckSleep_NoPause(void);
extern void OSTD_EnableNIRQ(void);
extern void OSTD_DisableNIRQ(void);
extern kal_bool AUDLP_Check_LowPower_Status(void);

kal_int32 AP_BtSS_idle_handler(void)
{
	extern kal_bool srv_mode_switch_is_network_service_available(void);
	Sleep_Time sleep_info;
	kal_uint32 _savedMask;
	kal_int32 ret = -1 * __LINE__;

	kal_get_sleep_time(&sleep_info);

	_savedMask = LockIRQ();
	 OSTD_EnableNIRQ();

	/* Get confirm. (return for next while loop if it is invalid sleep time) */
	if (kal_is_valid_sleep_time(&sleep_info) == 0)
	{
		//tst_sys_trace("Invalid sleep time");
		ret = -1 * __LINE__;
		goto out;
	}

	if (OSTD_CheckSleep_NoPause() == KAL_FALSE)
	{
		//tst_sys_trace("CheckSleep failed");
		ret = -1 * __LINE__;
		goto out;
	}

#if !defined(TELEPHONY_APP_NOT_PRESENT)
	if (srv_mode_switch_is_network_service_available())
	{
		ret = -1 * __LINE__;
		goto out;
	}
#endif


#if defined (MT6260)
	/* this workaround the issue that the MSDC drains 12mA in sleep mode */
	if (AUDLP_Check_LowPower_Status()==KAL_FALSE)
	{
		Idle_VMC_OnOff(KAL_FALSE);
	}
#endif

	ret = AP_BtSS_SwitchToTiny(&sleep_info);

out:
	/* Disable nIRQ wake-up event before I-Bit ON. */
	OSTD_DisableNIRQ();
	RestoreIRQ(_savedMask);

	AP_BtSS_stats.last_idle_handler_ret = ret;
	return ret;
}

CSCI_DEFINE_VAR(kal_uint32,APSYNC_TIMER_FLAG);
int timer_status_sync_exit_ap_callbacks(void)
{
    SET_APPSYNC_TIMER_INIT(); //WA to not GC'ed APSYNC_TIMER_FLAG
//	OSTD_Backup(OSTD_BACKUP_ADDRESS);
//	NU_TIMER_Backup(NU_TIMER_BACKUP_ADDRESS);
	USCOUNTER_Backup();
}

int timer_status_sync_enter_ap_callbacks(void)
{
	if(IS_APPSYNC_TIMER_EXPRIED() == 1)
	{
		TMC_Timer_Interrupt();
	}
}

#endif //defined(__TINY_SYS__)

