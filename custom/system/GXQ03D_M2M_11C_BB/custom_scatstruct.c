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
 *   custom_scatstruct.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides the scatter file dependent APIs
 *
 * Author:
 * -------
 *   Claudia Lo (mtk01876)     system auto generator v1.73 -> p1.74 -> p1.75. + sysGenUtility v0.49
 * 
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision$
 * $Modtime$
 * $Log$
 *
 * 04 21 2014 yinli.liang
 *  [6261 Driver][cache/MPU] protect boot_zimage and zimage region after init
 * .
 *
 * 12 17 2013 yinli.liang
 *  [System Service][MAUI Kernel Internal Request] replace INT_RetrieveDSPTXRXBaseAddr() by scatstruct API
 * .
 *
 * 11 26 2013 yinli.liang
 *  [SystemService][Auto-Gen][scatGen][Request For Design Change]Support MPU protect Zimage&DCM area before decompress
 * .
 *
 * 11 19 2013 yinli.liang
 *  [System Service][MAUI Kernel Internal Request] provide the function is_code_addr()
 * .
 *
 * 09 10 2013 yinli.liang
 *  [SystemService][Auto-Gen][scatGen][Request For Design Change] For BT box support, ROM will shadow to RAM when NORFLASH_NON_XIP is enabled
 * .
 * 
 * 08 28 2012 carina.liao
 *  [SystemService][Auto-Gen][Sys Gen][Request For Design Change] Modify kal_bool custom_get_DSP_DMA_RegionInfo() in custom_scatstruct.c.template to support 256MB RAM on MT6256
 * .
 * 
 * 07 23 2012 carina.liao
 *  [SystemService][Auto-Gen][scatGen][Sys Gen][Request For Design Change] Support BOOT_CERT in custom_scatstruct.c in NAND project
 * sysgen2.pl v1.60
 * custom_scatstruct.c.template
 * (no version update)
 *
 * 07 18 2012 carina.liao
 *  [SystemService][Auto-Gen][scatGen][Sys Gen][Request For Design Change] Support BOOT_CERT in custom_scatstruct.c in NAND project
 * sysgen2.pl v1.60
 * scatInfo.pm v0.12
 *
 * 04 25 2012 qmei.yang
 *  [SystemService][Auto-Gen][Request For Design Change] Support dump ALICE in sysgen2 and cmmgen on 11B
 * Get ALICE compressed address and size from AliceGetCompressedDumpRegion()
 *
 * 04 25 2012 carina.liao
 *  [SystemService][Auto-Gen][scatGen][Sys Gen][Request For Design Change] Phase in ALICE to 11B
 * scatGen.pl
 * scatGenLib.pl v5.92 & v6.01
 * ckscatter.pl v0.48
 * sysgen2.pl v1.54
 * custom_scatstruct.c.template
 * custom_scatstruct.h.template
 *
 * 02 15 2012 qmei.yang
 *  [SystemService][Auto-Gen][Sys Gen][scatGen][Internal Refinement] Support cmmgen sync with sysgen2
 * Modify custom_query_dump_region() API
 *
 * 01 31 2012 qmei.yang
 *  [SystemService][Auto-Gen][Sys Gen][scatGen][Internal Refinement] Refactory sysgen2.pl
 * .
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "kal_general_types.h"
#include "init.h"
#include "cache_sw_int.h"
#include "cache_sw.h"
#include "custom_demp.h"

#ifdef __MTK_TARGET__
extern kal_uint32 custom_get_fat_addr();
extern kal_uint32 custom_get_fat_len();
extern void AliceGetCompressedDumpRegion(kal_uint32 *base, kal_uint32 *length);

/*******************************************************************************
 * Define import global data.
 *******************************************************************************/

extern kal_uint32 Image$$ROM_GFH$$Base;
extern kal_uint32 Image$$ROM_GFH$$RO$$Base;
extern kal_uint32 Image$$ROM_GFH$$Length;
extern kal_uint32 Image$$ROM_GFH$$RO$$Length;
extern kal_uint32 Image$$ROM_GFH$$ZI$$Limit;
extern kal_uint32 Image$$ROM$$Base;
extern kal_uint32 Image$$ROM$$RO$$Base;
extern kal_uint32 Image$$ROM$$Length;
extern kal_uint32 Image$$ROM$$RO$$Length;
extern kal_uint32 Image$$ROM$$ZI$$Limit;
extern kal_uint32 Image$$ROM0$$Base;
extern kal_uint32 Image$$ROM0$$RO$$Base;
extern kal_uint32 Image$$ROM0$$Length;
extern kal_uint32 Image$$ROM0$$RO$$Length;
extern kal_uint32 Image$$ROM0$$ZI$$Limit;
extern kal_uint32 Image$$ROMHEAD$$Base;
extern kal_uint32 Image$$ROMHEAD$$RO$$Base;
extern kal_uint32 Image$$ROMHEAD$$Length;
extern kal_uint32 Image$$ROMHEAD$$RO$$Length;
extern kal_uint32 Image$$ROMHEAD$$ZI$$Limit;
extern kal_uint32 Image$$ROM_VIDEO$$Base;
extern kal_uint32 Image$$ROM_VIDEO$$RO$$Base;
extern kal_uint32 Image$$ROM_VIDEO$$Length;
extern kal_uint32 Image$$ROM_VIDEO$$RO$$Length;
extern kal_uint32 Image$$ROM_VIDEO$$ZI$$Limit;
extern kal_uint32 Image$$ROM1$$Base;
extern kal_uint32 Image$$ROM1$$RO$$Base;
extern kal_uint32 Image$$ROM1$$Length;
extern kal_uint32 Image$$ROM1$$RO$$Length;
extern kal_uint32 Image$$ROM1$$ZI$$Limit;
extern kal_uint32 Image$$SINGLE_BANK_CODE$$Base;
extern kal_uint32 Image$$SINGLE_BANK_CODE$$RO$$Base;
extern kal_uint32 Image$$SINGLE_BANK_CODE$$Length;
extern kal_uint32 Image$$SINGLE_BANK_CODE$$RO$$Length;
extern kal_uint32 Image$$SINGLE_BANK_CODE$$ZI$$Limit;
extern kal_uint32 Image$$EXTSRAM_ALICE$$Base;
extern kal_uint32 Image$$EXTSRAM_ALICE$$RO$$Base;
extern kal_uint32 Image$$EXTSRAM_ALICE$$Length;
extern kal_uint32 Image$$EXTSRAM_ALICE$$RO$$Length;
extern kal_uint32 Image$$EXTSRAM_ALICE$$ZI$$Limit;
extern kal_uint32 Image$$EXTSRAM$$Base;
extern kal_uint32 Image$$EXTSRAM$$RO$$Base;
extern kal_uint32 Image$$EXTSRAM$$Length;
extern kal_uint32 Image$$EXTSRAM$$RO$$Length;
extern kal_uint32 Image$$EXTSRAM$$ZI$$Limit;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI_MMIPOOL$$Base;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI_MMIPOOL$$RO$$Base;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI_MMIPOOL$$Length;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI_MMIPOOL$$RO$$Length;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI_MMIPOOL$$ZI$$Limit;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI$$Base;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI$$RO$$Base;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI$$Length;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI$$RO$$Length;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI$$ZI$$Limit;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW$$Base;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW$$RO$$Base;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW$$Length;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW$$RO$$Length;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW$$ZI$$Limit;
extern kal_uint32 Image$$CACHED_EXTSRAM$$Base;
extern kal_uint32 Image$$CACHED_EXTSRAM$$RO$$Base;
extern kal_uint32 Image$$CACHED_EXTSRAM$$Length;
extern kal_uint32 Image$$CACHED_EXTSRAM$$RO$$Length;
extern kal_uint32 Image$$CACHED_EXTSRAM$$ZI$$Limit;
extern kal_uint32 Image$$CACHED_EXTSRAM_NVRAM_LTABLE$$Base;
extern kal_uint32 Image$$CACHED_EXTSRAM_NVRAM_LTABLE$$RO$$Base;
extern kal_uint32 Image$$CACHED_EXTSRAM_NVRAM_LTABLE$$Length;
extern kal_uint32 Image$$CACHED_EXTSRAM_NVRAM_LTABLE$$RO$$Length;
extern kal_uint32 Image$$CACHED_EXTSRAM_NVRAM_LTABLE$$ZI$$Limit;
extern kal_uint32 Image$$EXTSRAM_GADGET$$Base;
extern kal_uint32 Image$$EXTSRAM_GADGET$$RO$$Base;
extern kal_uint32 Image$$EXTSRAM_GADGET$$Length;
extern kal_uint32 Image$$EXTSRAM_GADGET$$RO$$Length;
extern kal_uint32 Image$$EXTSRAM_GADGET$$ZI$$Limit;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_RW$$Base;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_RW$$RO$$Base;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_RW$$Length;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_RW$$RO$$Length;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_RW$$ZI$$Limit;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL$$Base;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL$$RO$$Base;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL$$Length;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL$$RO$$Length;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL$$ZI$$Limit;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI$$Base;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI$$RO$$Base;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI$$Length;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI$$RO$$Length;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI$$ZI$$Limit;
extern kal_uint32 Image$$CACHED_DUMMY_END$$Base;
extern kal_uint32 Image$$CACHED_DUMMY_END$$RO$$Base;
extern kal_uint32 Image$$CACHED_DUMMY_END$$Length;
extern kal_uint32 Image$$CACHED_DUMMY_END$$RO$$Length;
extern kal_uint32 Image$$CACHED_DUMMY_END$$ZI$$Limit;
extern kal_uint32 Image$$EXTSRAM_DSP_TX$$Base;
extern kal_uint32 Image$$EXTSRAM_DSP_TX$$RO$$Base;
extern kal_uint32 Image$$EXTSRAM_DSP_TX$$Length;
extern kal_uint32 Image$$EXTSRAM_DSP_TX$$RO$$Length;
extern kal_uint32 Image$$EXTSRAM_DSP_TX$$ZI$$Limit;
extern kal_uint32 Image$$EXTSRAM_DSP_RX$$Base;
extern kal_uint32 Image$$EXTSRAM_DSP_RX$$RO$$Base;
extern kal_uint32 Image$$EXTSRAM_DSP_RX$$Length;
extern kal_uint32 Image$$EXTSRAM_DSP_RX$$RO$$Length;
extern kal_uint32 Image$$EXTSRAM_DSP_RX$$ZI$$Limit;
extern kal_uint32 Image$$SHOULDBE_EMPTYSECTION$$Base;
extern kal_uint32 Image$$SHOULDBE_EMPTYSECTION$$RO$$Base;
extern kal_uint32 Image$$SHOULDBE_EMPTYSECTION$$Length;
extern kal_uint32 Image$$SHOULDBE_EMPTYSECTION$$RO$$Length;
extern kal_uint32 Image$$SHOULDBE_EMPTYSECTION$$ZI$$Limit;
extern kal_uint32 Image$$EMIINIT_CODE$$Base;
extern kal_uint32 Image$$EMIINIT_CODE$$RO$$Base;
extern kal_uint32 Image$$EMIINIT_CODE$$Length;
extern kal_uint32 Image$$EMIINIT_CODE$$RO$$Length;
extern kal_uint32 Image$$EMIINIT_CODE$$ZI$$Limit;
extern kal_uint32 Image$$INTSRAM_CODE$$Base;
extern kal_uint32 Image$$INTSRAM_CODE$$RO$$Base;
extern kal_uint32 Image$$INTSRAM_CODE$$Length;
extern kal_uint32 Image$$INTSRAM_CODE$$RO$$Length;
extern kal_uint32 Image$$INTSRAM_CODE$$ZI$$Limit;
extern kal_uint32 Image$$INTSRAM_DATA$$Base;
extern kal_uint32 Image$$INTSRAM_DATA$$RO$$Base;
extern kal_uint32 Image$$INTSRAM_DATA$$Length;
extern kal_uint32 Image$$INTSRAM_DATA$$RO$$Length;
extern kal_uint32 Image$$INTSRAM_DATA$$ZI$$Limit;
extern kal_uint32 Image$$INTSRAM_DATA_PREINIT$$Base;
extern kal_uint32 Image$$INTSRAM_DATA_PREINIT$$RO$$Base;
extern kal_uint32 Image$$INTSRAM_DATA_PREINIT$$Length;
extern kal_uint32 Image$$INTSRAM_DATA_PREINIT$$RO$$Length;
extern kal_uint32 Image$$INTSRAM_DATA_PREINIT$$ZI$$Limit;
extern kal_uint32 Image$$INTSRAM_DUMMY_END$$Base;
extern kal_uint32 Image$$INTSRAM_DUMMY_END$$RO$$Base;
extern kal_uint32 Image$$INTSRAM_DUMMY_END$$Length;
extern kal_uint32 Image$$INTSRAM_DUMMY_END$$RO$$Length;
extern kal_uint32 Image$$INTSRAM_DUMMY_END$$ZI$$Limit;
extern kal_uint32 Image$$ROM_SIGNATURE_SECTION$$Base;
extern kal_uint32 Image$$ROM_SIGNATURE_SECTION$$RO$$Base;
extern kal_uint32 Image$$ROM_SIGNATURE_SECTION$$Length;
extern kal_uint32 Image$$ROM_SIGNATURE_SECTION$$RO$$Length;
extern kal_uint32 Image$$ROM_SIGNATURE_SECTION$$ZI$$Limit;
extern kal_uint32 Image$$VIVA_GFH$$Base;
extern kal_uint32 Image$$VIVA_GFH$$RO$$Base;
extern kal_uint32 Image$$VIVA_GFH$$Length;
extern kal_uint32 Image$$VIVA_GFH$$RO$$Length;
extern kal_uint32 Image$$VIVA_GFH$$ZI$$Limit;
extern kal_uint32 Image$$VIVA$$Base;
extern kal_uint32 Image$$VIVA$$RO$$Base;
extern kal_uint32 Image$$VIVA$$Length;
extern kal_uint32 Image$$VIVA$$RO$$Length;
extern kal_uint32 Image$$VIVA$$ZI$$Limit;
extern kal_uint32 Image$$ALICE$$Base;
extern kal_uint32 Image$$ALICE$$RO$$Base;
extern kal_uint32 Image$$ALICE$$Length;
extern kal_uint32 Image$$ALICE$$RO$$Length;
extern kal_uint32 Image$$ALICE$$ZI$$Limit;
extern kal_uint32 Image$$TRACK_GFH_RO$$Base;
extern kal_uint32 Image$$TRACK_GFH_RO$$RO$$Base;
extern kal_uint32 Image$$TRACK_GFH_RO$$Length;
extern kal_uint32 Image$$TRACK_GFH_RO$$RO$$Length;
extern kal_uint32 Image$$TRACK_GFH_RO$$ZI$$Limit;
extern kal_uint32 Image$$TRACK_RO$$Base;
extern kal_uint32 Image$$TRACK_RO$$RO$$Base;
extern kal_uint32 Image$$TRACK_RO$$Length;
extern kal_uint32 Image$$TRACK_RO$$RO$$Length;
extern kal_uint32 Image$$TRACK_RO$$ZI$$Limit;
extern kal_uint32 Image$$TRACK_GFH_RW$$Base;
extern kal_uint32 Image$$TRACK_GFH_RW$$RO$$Base;
extern kal_uint32 Image$$TRACK_GFH_RW$$Length;
extern kal_uint32 Image$$TRACK_GFH_RW$$RO$$Length;
extern kal_uint32 Image$$TRACK_GFH_RW$$ZI$$Limit;
extern kal_uint32 Image$$TRACK_RAM$$Base;
extern kal_uint32 Image$$TRACK_RAM$$RO$$Base;
extern kal_uint32 Image$$TRACK_RAM$$Length;
extern kal_uint32 Image$$TRACK_RAM$$RO$$Length;
extern kal_uint32 Image$$TRACK_RAM$$ZI$$Limit;
extern kal_uint32 Image$$TRACK_NVRAM_GFH$$Base;
extern kal_uint32 Image$$TRACK_NVRAM_GFH$$RO$$Base;
extern kal_uint32 Image$$TRACK_NVRAM_GFH$$Length;
extern kal_uint32 Image$$TRACK_NVRAM_GFH$$RO$$Length;
extern kal_uint32 Image$$TRACK_NVRAM_GFH$$ZI$$Limit;
extern kal_uint32 Image$$TRACK_NVRAM$$Base;
extern kal_uint32 Image$$TRACK_NVRAM$$RO$$Base;
extern kal_uint32 Image$$TRACK_NVRAM$$Length;
extern kal_uint32 Image$$TRACK_NVRAM$$RO$$Length;
extern kal_uint32 Image$$TRACK_NVRAM$$ZI$$Limit;
extern kal_uint32 Image$$DUMP_VECTOR_TABLE$$Base;
extern kal_uint32 Image$$DUMP_VECTOR_TABLE$$RO$$Base;
extern kal_uint32 Image$$DUMP_VECTOR_TABLE$$Length;
extern kal_uint32 Image$$DUMP_VECTOR_TABLE$$RO$$Length;
extern kal_uint32 Image$$DUMP_VECTOR_TABLE$$ZI$$Limit;
extern kal_uint32 Load$$ROM_SIGNATURE_SECTION$$Base;



/*******************************************************************************
 * Define import global data.
 *******************************************************************************/

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)

#if defined(__DEMAND_PAGING__)
/* DEMP image table declaration */
static kal_uint16* demp_image_table[DEMP_BIN_NUM];

static kal_uint16 demp_main_image_table[DEMP_MAIN_BIN_SIZE * DEMP_BLOCK_PER_MB];
#if defined(__MBA_ON_DEMAND__)

/* more resource bin could be added */
#endif /* __MBA_ON_DEMAND__ */
#endif /* __DEMAND_PAGING__ */


/* define pool size for fine page table and coarse page table */
/*     CPT : 1 (TCM) 
 *       + 4 * (number of continous dynamic CACHEABLE default non-cacheable region)
 *       + 4 * (number of continous dynamic CACHEABLE default cacheable region)
 *       + 4 * (number of continous CACHED region)
 *       + 4 * (number of continous CACHED code region)
 *       + 2 * (number of non-cacched EXTSRAM RW region)
 *       + 2 * (number of non-cacched EXTSRAM RO region)
 *       + 2 * (number of multi load region) 
 *       + 1   (DSP_TX DSP_RX ... )
 *       +     (number of ROM - 1)
 *       + 2   (at the beginning and at the end of FAT)
 * */
#if defined(__ARM9_MMU__)
#define MAX_FPT_POOL_SIZE ( 0 )
#define MAX_CPT_POOL_SIZE (23 * 1 * 1024)
#elif defined(__ARM11_MMU__)
#define MAX_CPT_POOL_SIZE ( 23 * 1 * 1024)
#endif /* __ARM11_MMU__ */

#pragma arm section zidata = "PAGETABLE"
#if defined(__ARM9_MMU__)
/* memory pool of fine page table */
#if (MAX_FPT_POOL_SIZE > 0)
static __align(4 * 1024) kal_uint32 FPT_POOL[MAX_FPT_POOL_SIZE / 4];
#endif /* MAX_FPT_POOL_SIZE > 0 */
#endif /* __ARM9_MMU__ */
/* memory pool of coarse page table */
static __align(1024) kal_uint32 CPT_POOL[MAX_CPT_POOL_SIZE / 4];
#pragma arm section zidata

#endif /* __ARM9_MMU__ || __ARM11_MMU__ */

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)

#pragma arm section rwdata = "INTERNRW" , zidata = "INTERNZI"
static EXTSRAM_REGION_INFO_T DYNAMIC_CACHED_EXTSRAM_DNC_REGION[2];
static EXTSRAM_REGION_INFO_T DYNAMIC_CACHED_EXTSRAM_DC_REGION[2];
static EXTSRAM_REGION_INFO_T CACHED_EXTSRAM_REGION[2];
static EXTSRAM_REGION_INFO_T CACHED_EXTSRAM_CODE_REGION[1];
static EXTSRAM_REGION_INFO_T NONCACHED_EXTSRAM_REGION[4];
static EXTSRAM_REGION_INFO_T NONCACHED_EXTSRAM_RO_REGION[1];
static EXTSRAM_REGION_INFO_T CACHED_EXTCODE_REGION[2];

#pragma arm section rwdata , zidata

#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ */

#pragma arm section rwdata = "INTERNRW" , zidata = "INTERNZI"
static EXTSRAM_REGION_INFO_T MULTI_ROM_LOAD_REGION[1];

#pragma arm section rwdata , zidata

#if defined(__DSP_FCORE4__)
#pragma arm section rwdata = "INTSRAM_RW" , zidata = "INTSRAM_ZI"
static EXTSRAM_REGION_INFO_T MCU_C_DSP_C_REGION[2];
static EXTSRAM_REGION_INFO_T MCU_C_DSP_NC_REGION[1];
static EXTSRAM_REGION_INFO_T MCU_NC_DSP_C_REGION[1];
static EXTSRAM_REGION_INFO_T MCU_NC_DSP_NC_REGION[3];

#pragma arm section rwdata , zidata
#endif /* __DSP_FCORE4__ */


#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
#if defined(__ARM9_MMU__)
/*************************************************************************
* FUNCTION
*  custom_query_fpt_pool
*
* DESCRIPTION
*  This function gets the address and size of fpt pool.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_int32 custom_query_fpt_pool(kal_uint32 **pool, kal_uint32 *pool_size)
{
#if (MAX_FPT_POOL_SIZE > 0)
    *pool = FPT_POOL;
    *pool_size = MAX_FPT_POOL_SIZE;
#else /* MAX_FPT_POOL_SIZE > 0 */
    *pool = NULL;
    *pool_size = 0;
#endif /* MAX_FPT_POOL_SIZE > 0 */

    return 0;
}
#endif /* __ARM9_MMU__ */

/*************************************************************************
* FUNCTION
*  custom_query_cpt_pool
*
* DESCRIPTION
*  This function gets the address and size of cpt pool.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_int32 custom_query_cpt_pool(kal_uint32 **pool, kal_uint32 *pool_size)
{
    *pool = CPT_POOL;
    *pool_size = MAX_CPT_POOL_SIZE;

    return 0;
}

#endif /* __ARM9_MMU__ || __ARM11_MMU__ */

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)

/************************************************************************
* FUNCTION
*  custom_query_dynamic_cached_extsram_default_nc_region
*
* DESCRIPTION
*  This function gets info of dynamic cached default non-cached EXT SRAM regions.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#pragma arm section code = "INTERNCODE"
kal_int32 custom_query_dynamic_cached_extsram_default_nc_region(EXTSRAM_REGION_INFO_T **region)
{
    *region = DYNAMIC_CACHED_EXTSRAM_DNC_REGION;

    return 0;
}
#pragma arm section code

/************************************************************************
* FUNCTION
*  custom_query_dynamic_cached_extsram_default_c_region
*
* DESCRIPTION
*  This function gets info of dynamic cached default cached EXT SRAM regions.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#pragma arm section code = "INTERNCODE"
kal_int32 custom_query_dynamic_cached_extsram_default_c_region(EXTSRAM_REGION_INFO_T **region)
{
    *region = DYNAMIC_CACHED_EXTSRAM_DC_REGION;

    return 0;
}
#pragma arm section code

/*************************************************************************
* FUNCTION
*  custom_query_cached_extsram_region
*
* DESCRIPTION
*  This function gets info of cached EXT SRAM regions.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#pragma arm section code = "INTERNCODE"
kal_int32 custom_query_cached_extsram_region(EXTSRAM_REGION_INFO_T **region)
{
    *region = CACHED_EXTSRAM_REGION;

    return 0;
}
#pragma arm section code

/*************************************************************************
* FUNCTION
*  custom_query_cached_extsram_code_region
*
* DESCRIPTION
*  This function gets info of cached EXT SRAM code regions.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#pragma arm section code = "INTERNCODE"
kal_int32 custom_query_cached_extsram_code_region(EXTSRAM_REGION_INFO_T **region)
{
    *region = CACHED_EXTSRAM_CODE_REGION;

    return 0;
}
#pragma arm section code

/*************************************************************************
* FUNCTION
*  custom_query_noncached_extsram_region
*
* DESCRIPTION
*  This function gets info of non-cached RW EXT SRAM regions.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#pragma arm section code = "INTERNCODE"
kal_int32 custom_query_noncached_extsram_region(EXTSRAM_REGION_INFO_T **region)
{
    *region = NONCACHED_EXTSRAM_REGION;

    return 0;
}
#pragma arm section code

/*************************************************************************
* FUNCTION
*  custom_query_noncached_extsram_ro_region
*
* DESCRIPTION
*  This function gets info of non-cached RO EXT SRAM regions.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#pragma arm section code = "INTERNCODE"
kal_int32 custom_query_noncached_extsram_ro_region(EXTSRAM_REGION_INFO_T **region)
{
    *region = NONCACHED_EXTSRAM_RO_REGION;

    return 0;
}
#pragma arm section code

/*************************************************************************
* FUNCTION
*  custom_query_cached_extcode_region
*
* DESCRIPTION
*  This function gets info of cached EXT CODE regions.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#pragma arm section code = "INTERNCODE"
kal_int32 custom_query_cached_extcode_region(EXTSRAM_REGION_INFO_T **region)
{
    *region = CACHED_EXTCODE_REGION;

    return 0;
}
#pragma arm section code

#if defined(__DEMAND_PAGING__)
/*************************************************************************
* FUNCTION
*  custom_get_demp_image_table
*
* DESCRIPTION
*  This function gets the image table for demand paging.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_demp_image_table(void)
{
    demp_image_table[DEMP_MAIN] = demp_main_image_table;

#if defined(__MBA_ON_DEMAND__)

#endif /* __MBA_ON_DEMAND__ */

    return (kal_uint32)demp_image_table;
}
#endif /* __DEMAND_PAGING__ */
#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ */


/*************************************************************************
* FUNCTION
*  custom_query_multi_rom_load_region
*
* DESCRIPTION
*  This function gets info of multi-rom load regions.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_query_multi_rom_load_region(EXTSRAM_REGION_INFO_T **region)
{
    *region = MULTI_ROM_LOAD_REGION;

    return 0;
}


#if defined(__DSP_FCORE4__)

/************************************************************************
* FUNCTION
*  custom_query_mcu_cacheable_dsp_cacheable_region
*
* DESCRIPTION
*  This function gets info of MCU cacheable DSP cacheable EXT SRAM regions.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_int32 custom_query_mcu_cacheable_dsp_cacheable_region(EXTSRAM_REGION_INFO_T **region)
{
    *region = MCU_C_DSP_C_REGION;

    return 0;
}

/************************************************************************
* FUNCTION
*  custom_query_mcu_cacheable_dsp_noncacheable_region
*
* DESCRIPTION
*  This function gets info of MCU cacheable DSP noncacheable EXT SRAM regions.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_int32 custom_query_mcu_cacheable_dsp_noncacheable_region(EXTSRAM_REGION_INFO_T **region)
{
    *region = MCU_C_DSP_NC_REGION;

    return 0;
}

/************************************************************************
* FUNCTION
*  custom_query_mcu_noncacheable_dsp_cacheable_region
*
* DESCRIPTION
*  This function gets info of MCU noncacheable DSP cacheable EXT SRAM regions.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_int32 custom_query_mcu_noncacheable_dsp_cacheable_region(EXTSRAM_REGION_INFO_T **region)
{
    *region = MCU_NC_DSP_C_REGION;

    return 0;
}

/************************************************************************
* FUNCTION
*  custom_query_mcu_cacheable_dsp_cacheable_region
*
* DESCRIPTION
*  This function gets info of MCU noncacheable DSP noncacheable EXT SRAM regions.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_int32 custom_query_mcu_noncacheable_dsp_noncacheable_region(EXTSRAM_REGION_INFO_T **region)
{
    *region = MCU_NC_DSP_NC_REGION;

    return 0;
}

#endif /* __DSP_FCORE4__ */


/*************************************************************************
* FUNCTION
*  custom_get_1st_ROM_ROMBase_On_Flash
*
* DESCRIPTION
*  Retrieve the base address of the 1st ROM On Flash when NOR flash booting
*  If NORFLASH_NON_XIP_SUPPORT enabled, ROM LV and EV will be both on RAM,This 
*  function retrieve the base address where flashtool download the ROM-binary
*  This function must sync with scatter file structure
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_1st_ROM_ROMBase_On_Flash(void)
{
   return 0x1000a000;
}


/*************************************************************************
* FUNCTION
*  custom_get_1st_ROM_ROMBase
*
* DESCRIPTION
*  Retrieve the base address of the 1st ROM (Load View)
*  This function must sync with scatter file structure
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_1st_ROM_ROMBase(void)
{
    return (kal_uint32)&Image$$ROM_GFH$$Base;
}

/*************************************************************************
* FUNCTION
*  custom_get_1st_ROM_ROMLength
*
* DESCRIPTION
*  Retrieve the actual ROM length of 1st ROM (Load View)
*  This function must sync with scatter file structure
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_1st_ROM_ROMLength(void)
{
    kal_uint32 Length = 0;
    Length += (kal_uint32)&Image$$ROM_GFH$$Length;
    Length += (kal_uint32)&Image$$ROM$$Length;
    Length += (kal_uint32)&Image$$ROM0$$Length;
    Length += (kal_uint32)&Image$$ROMHEAD$$Length;
    Length += (kal_uint32)&Image$$ROM_VIDEO$$Length;
    Length += (kal_uint32)&Image$$ROM1$$Length;

    return Length; 
}

/*************************************************************************
* FUNCTION
*  custom_get_1st_ROM_RAMBase
*
* DESCRIPTION
*  Retrieve the RAM base address of the 1st ROM (Load View)
*  This function must sync with scatter file structure
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_1st_ROM_RAMBase(void)
{
    return (kal_uint32)&Image$$SINGLE_BANK_CODE$$Base;
}

/*************************************************************************
* FUNCTION
*  custom_get_1st_ROM_RAMLength
*
* DESCRIPTION
*  Retrieve the actual RAM length of 1st ROM (Load View)
*  This function must sync with scatter file structure
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_1st_ROM_RAMLength(void)
{
    kal_uint32 RAMLength = 0;
    
    return RAMLength; 
}

/*************************************************************************
* FUNCTION
*  custom_get_1st_ROM_RAMEnd
*
* DESCRIPTION
*  Retrieve the actual end address of 1st ROM (Exec View)
*  This function must sync with scatter file structure
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_1st_ROM_RAMEnd(void)
{
    kal_uint32 EndAddr = 0;

    EndAddr  = (kal_uint32)&Image$$EXTSRAM_DSP_RX$$ZI$$Limit;

    return EndAddr; 
}

/*************************************************************************
* FUNCTION
*  custom_get_1st_ROM_LoadEnd
*
* DESCRIPTION
*  Retrieve the actual end address of 1st ROM (Load View)
*  This function must sync with scatter file structure
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_1st_ROM_LoadEnd(void)
{
    kal_uint32 EndAddr = 0;

    EndAddr  = (kal_uint32)&Load$$ROM_SIGNATURE_SECTION$$Base;
    EndAddr += (kal_uint32)&Image$$ROM_SIGNATURE_SECTION$$Length;

    return EndAddr; 
}

/*************************************************************************
* FUNCTION
*  custom_get_2nd_ROM_ROMBase
*
* DESCRIPTION
*  Retrieve the base address of the 2nd ROM (Load View)
*  This function must sync with scatter file structure
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_2nd_ROM_ROMBase(void)
{
    return 0;
}

/*************************************************************************
* FUNCTION
*  custom_get_2nd_ROM_ROMLength
*
* DESCRIPTION
*  Retrieve the actual ROM length of 2nd ROM (Load View)
*  This function must sync with scatter file structure
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_2nd_ROM_ROMLength(void)
{
    kal_uint32 Length = 0;



    return Length; 
}

/*************************************************************************
* FUNCTION
*  custom_get_2nd_ROM_RAMBase
*
* DESCRIPTION
*  Retrieve the RAM base address of the 2nd ROM (Load View)
*  This function must sync with scatter file structure
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_2nd_ROM_RAMBase(void)
{
    return 0;
}

/*************************************************************************
* FUNCTION
*  custom_get_2nd_ROM_RAMLength
*
* DESCRIPTION
*  Retrieve the actual RAM length of 2nd ROM (Load View)
*  This function must sync with scatter file structure
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_2nd_ROM_RAMLength(void)
{
    kal_uint32 RAMLength = 0;

    return RAMLength; 
}

/*************************************************************************
* FUNCTION
*  custom_get_2nd_ROM_RAMEnd
*
* DESCRIPTION
*  Retrieve the actual end address of 2nd ROM (Exec View)
*  This function must sync with scatter file structure
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_2nd_ROM_RAMEnd(void)
{
    kal_uint32 EndAddr = 0;

    return EndAddr; 
}

/*************************************************************************
* FUNCTION
*  custom_get_2nd_ROM_LoadEnd
*
* DESCRIPTION
*  Retrieve the actual end address of 2nd ROM (Load View)
*  This function must sync with scatter file structure
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_2nd_ROM_LoadEnd(void)
{
    kal_uint32 EndAddr = 0;

    return EndAddr; 
}

/*************************************************************************
* FUNCTION
*  custom_get_INTSRAMCODE_Base
*
* DESCRIPTION
*  Retrieve the base address of INTSRAM_CODE
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_INTSRAMCODE_Base(void)
{
    return (kal_uint32)&Image$$INTSRAM_CODE$$Base;
}

/*************************************************************************
* FUNCTION
*  custom_get_INTSRAMCODE_End
*
* DESCRIPTION
*  Retrieve the END address of INTSRAM_CODE
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_INTSRAMCODE_End(void)
{
    return (kal_uint32)&Image$$INTSRAM_CODE$$ZI$$Limit;
}
/*************************************************************************
* FUNCTION
*  custom_get_INTSRAMDATA_Base
*
* DESCRIPTION
*  Retrieve the base address of INTSRAM_DATA
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_INTSRAMDATA_Base(void)
{
    return (kal_uint32)&Image$$INTSRAM_DATA$$Base;
}

/*************************************************************************
* FUNCTION
*  custom_get_INTSRAMDATA_End
*
* DESCRIPTION
*  Retrieve the END address of INTSRAM_DATA
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_INTSRAMDATA_End(void)
{
    return (kal_uint32)&Image$$INTSRAM_DATA$$ZI$$Limit;
}
/*************************************************************************
* FUNCTION
*  custom_get_SysRam_Base
*
* DESCRIPTION
*  Retrieve the base address of INTSRAM_MULTIMEDIA
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_SysRam_Base(void)
{
    return 0xE0000000;
}

/*************************************************************************
* FUNCTION
*  custom_get_SysRam_End
*
* DESCRIPTION
*  Retrieve the END address of INTSRAM_MULTIMEDIA
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_SysRam_End(void)
{
    return 0xE0000000;
}
/*************************************************************************
* FUNCTION
*  custom_get_SysRam_MaxSize
*
* DESCRIPTION
*  Retrieve sysram max size
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_SysRam_MaxSize(void)
{
    return 0;
}

/*************************************************************************
* FUNCTION
*  custom_get_SysRam_Info
*
* DESCRIPTION
*  This function gets the start address and lenght of system RAM.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_int32 custom_get_SysRam_Info(kal_uint32 *addr, kal_uint32 *len)
{
    *addr = 0xFFFFFFFF;
    *len = 0x0;
    return -1;
}

#if defined(__CR4__)
/*************************************************************************
* FUNCTION
*  custom_get_INTSRAM_PHYSICAL_BOUNDARY_Base
*
* DESCRIPTION
*  Retrieve the base address of INTSRAM_PHYSICAL_BOUNDARY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_INTSRAM_PHYSICAL_BOUNDARY_Base(void)
{
    return (kal_uint32)&Image$$INTSRAM_DATA$$Base;
}
/*************************************************************************
* FUNCTION
*  custom_get_INTSRAM_PHYSICAL_BOUNDARY_MaxSize
*
* DESCRIPTION
*  Retrieve the MaxSize of INTSRAM_PHYSICAL_BOUNDARY 
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_INTSRAM_PHYSICAL_BOUNDARY_MaxSize(void)
{
    return 0;
}
#endif /*__CR4__*/

/*************************************************************************
* FUNCTION
*  custom_get_PROTECTED_RES_Base
*
* DESCRIPTION
*  Retrieve the base address of EXTSRAM_PROTECTED_RES
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_int32 custom_get_PROTECTED_RES_Base(void)
{
    return 0;
}

/*************************************************************************
* FUNCTION
*  custom_get_PROTECTED_RES_Length
*
* DESCRIPTION
*  Retrieve the length of EXTSRAM_PROTECTED_RES
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_int32 custom_get_PROTECTED_RES_Length(void)
{
    return 0;
}

/*************************************************************************
* FUNCTION
*  custom_get_BOOTCERT_StartAddr
*
* DESCRIPTION
*  Retrieve the base address of BOOT_CERT
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_BOOTCERT_StartAddr(void)
{
    return 0;
}

/*************************************************************************
* FUNCTION
*  custom_get_BOOTCERT_Length
*
* DESCRIPTION
*  Retrieve the length of BOOT_CERT
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_BOOTCERT_Length(void)
{
    kal_uint32 Length = 0;



    return Length;
}


/*************************************************************************
* FUNCTION
*  custom_get_SECUREMAC_Base
*
* DESCRIPTION
*  Retrieve the base address of __HIDDEN_SECURE_MAC
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_SECUREMAC_Base(void)
{
    return 0;
}

/*************************************************************************
* FUNCTION
*  custom_get_SECUREMAC_Length
*
* DESCRIPTION
*  Retrieve the length of __HIDDEN_SECURE_MAC
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_SECUREMAC_Length(void)
{
    return 0;
}


/*************************************************************************
* FUNCTION
*  custom_get_SECURERO_Base
*
* DESCRIPTION
*  Retrieve the base address of SECURE_RO
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_SECURERO_Base(void)
{
    return 0;
}

/*************************************************************************
* FUNCTION
*  custom_get_SECURERO_Length
*
* DESCRIPTION
*  Retrieve the length of SECURE_RO
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_SECURERO_Length(void)
{
    return 0;
}

/*************************************************************************
* FUNCTION
*  custom_get_SINGLEBANKCODE_and_VectorTable_Base
*
* DESCRIPTION
*  Retrieve the base address of SINGLE_BANK_CODE and vector table
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_SINGLEBANKCODE_and_VectorTable_Base(void)
{
    return (kal_uint32)&Image$$SINGLE_BANK_CODE$$Base & 0xF0000000;
}

/*************************************************************************
* FUNCTION
*  custom_get_SINGLEBANKCODE_Base
*
* DESCRIPTION
*  Retrieve the base address of SINGLE_BANK_CODE
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_SINGLEBANKCODE_Base(void)
{
    return (kal_uint32)&Image$$SINGLE_BANK_CODE$$Base;
}

/*************************************************************************
* FUNCTION
*  custom_get_SINGLEBANKCODE_End
*
* DESCRIPTION
*  Retrieve the END address of SINGLE_BANK_CODE
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_SINGLEBANKCODE_End(void)
{
    return (kal_uint32)&Image$$EXTSRAM_ALICE$$Base;
}

#if defined(__ALICE_SUPPORT__)
/*************************************************************************
* FUNCTION
*  custom_get_EXTSRAM_ALICE_End
*
* DESCRIPTION
*  Retrieve the END address of EXTSRAM_ALICE
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_EXTSRAM_ALICE_End(void)
{
    return (kal_uint32)&Image$$EXTSRAM$$Base;
}


/*************************************************************************
* FUNCTION
*  custom_get_ALICE_Base
*
* DESCRIPTION
*  Retrieve the base address of ALICE
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_ALICE_Base(void)
{
    return (kal_uint32)&Image$$ALICE$$Base;
}


/*************************************************************************
* FUNCTION
*  custom_get_ALICE_Length
*
* DESCRIPTION
*  Retrieve the length of ALICE
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_ALICE_Length(void)
{
    return (kal_uint32)&Image$$ALICE$$Length;
}
#endif /* __ALICE_SUPPORT__ */


/*************************************************************************
* FUNCTION
*  custom_query_zimage_region
*
* DESCRIPTION
*  Retrieve the base and length of ZIMAGE
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#if defined(__ZIMAGE_SUPPORT__)
void custom_query_zimage_region(EXTSRAM_REGION_INFO_T *region)
{
    region->addr = 0x0;
    region->len = 0x0;
}
void custom_query_zimage_RO_region(EXTSRAM_REGION_INFO_T *region)
{
    region->addr = 0x0;
    region->len = 0x0;
}
#endif /*__ZIMAGE_SUPPORT__*/

/*************************************************************************
* FUNCTION
*  custom_query_boot_zimage_region
*
* DESCRIPTION
*  Retrieve the base and length of BOOT_ZIMAGE
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#if defined(__BOOT_ZIMAGE_SUPPORT__)
void custom_query_boot_zimage_region(EXTSRAM_REGION_INFO_T *region)
{
    region->addr = 0x0;
    region->len = 0x0;
}
#endif /*__BOOT_ZIMAGE_SUPPORT__*/

/*************************************************************************
* FUNCTION
*  custom_query_dcm_reigon
*
* DESCRIPTION
*  Retrieve the base and length of DCM
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#if defined(__DCM_WITH_COMPRESSION__)
void custom_query_dcm_reigon(EXTSRAM_REGION_INFO_T *region)
{
    region->addr = 0x0;
    region->len = 0x0;
}
#endif /*__DCM_WITH_COMPRESSION__*/

/*************************************************************************
* FUNCTION
*  custom_get_DSPTXRX_Base
*
* DESCRIPTION
*  Retrieve the lowest base address of DSP_TX or DSP_RX
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_int32 custom_get_DSPTXRX_Base(void)
{
    return (kal_uint32)&Image$$EXTSRAM_DSP_TX$$Base;
}

/*************************************************************************
* FUNCTION
*  custom_get_DSPTXRX_Info
*
* DESCRIPTION
*  Retrieve the base address and length of DSP_TX or DSP_RX
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
extern kal_uint32 Image$$EXTSRAM_DSP_TX$$ZI$$Length;
extern kal_uint32 Image$$EXTSRAM_DSP_RX$$ZI$$Length;

kal_bool custom_get_DSPTXRX_Info(kal_uint32 *TX_Base, kal_uint32 *RX_Base,
                                 kal_uint32 *CS,
                                 kal_uint32 *TX_Size, kal_uint32 *RX_Size)
{
#if defined(SUPPORT_DSP_TXRX_BUFF)

   kal_uint32     chipSelect;
   kal_uint32     region_sz;

#if defined(IC_BURNIN_TEST)

   *TX_Base = 0;
   *RX_Base = 0;
   return KAL_TRUE;

#else
   *TX_Base = (kal_uint32)&Image$$EXTSRAM_DSP_TX$$Base;
   *RX_Base = (kal_uint32)&Image$$EXTSRAM_DSP_RX$$Base;

   region_sz = 4 * 1024;
   while (region_sz < ((kal_uint32)&Image$$EXTSRAM_DSP_TX$$Length
                      +(kal_uint32)&Image$$EXTSRAM_DSP_TX$$ZI$$Length))
   {
      region_sz = region_sz << 1;
   }
   *TX_Size = region_sz;

   region_sz = 4 * 1024;
   while (region_sz < ((kal_uint32)&Image$$EXTSRAM_DSP_RX$$Length
                      +(kal_uint32)&Image$$EXTSRAM_DSP_RX$$ZI$$Length))
   {
      region_sz = region_sz << 1;
   }
   *RX_Size = region_sz;

    chipSelect = (*TX_Base&0xF8000000) >> 27;
    ASSERT(chipSelect<2);
   
   *CS = chipSelect;
   return KAL_TRUE;
#endif /*IC_BURNIN_TEST*/

#else   /* SUPPORT_DSP_TXRX_BUFF */

   return KAL_FALSE;

#endif   /* SUPPORT_DSP_TXRX_BUFF */
}


/*************************************************************************
* FUNCTION
*  custom_get_FAT_StartAddr
*
* DESCRIPTION
*  Retrieve FAT base address
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_FAT_StartAddr(void)
{
    return (custom_get_fat_addr() | INT_RetrieveFlashBaseAddr());
}

/*************************************************************************
* FUNCTION
*  custom_get_FAT_Length
*
* DESCRIPTION
*  Retrieve FAT length
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_FAT_Length(void)
{
    return custom_get_fat_len();
}


/*************************************************************************
* FUNCTION
*  custom_get_MaxAvailableMemorySegment
*
* DESCRIPTION
*  Retrieve the pointer (16 Bytes aligned) and the length that unUsed memory segments
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/

void custom_get_MaxAvailableMemorySegment(kal_uint32 **Return_begin_addr, kal_uint32 *Return_segment_size)
{
    kal_uint32  MaxLength;
    kal_uint32  MaxBeginAddr;
    kal_uint32  LastRegionEnd;
    kal_uint32  ThisRegionBegin;

    MaxLength = 0;
    MaxBeginAddr = 0;

    {
        
        /* Direct Assign the Cached Region */
        ThisRegionBegin = (kal_uint32)&Image$$CACHED_DUMMY_END$$Base + 0;
        LastRegionEnd   = (kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI$$ZI$$Limit;
        LastRegionEnd   = (LastRegionEnd + 16) & 0xFFFFFFF0;
    }

    MaxLength       = (ThisRegionBegin & 0x0FFFFFFF) - (LastRegionEnd  & 0x0FFFFFFF);
    MaxBeginAddr    = LastRegionEnd;

    /* round to 4KB aligned */
    MaxBeginAddr = ((MaxBeginAddr + 4096 - 1) >> 12) << 12;

    if (MaxLength < 4096) {
        MaxLength = 0;
    } else {
        /* round down to 4KB aligned */
        MaxLength -= 4096;
        /* round up end address to 4KB aligned */
        MaxLength = (MaxLength / 4096) * 4096;
    }

        /* Convert to non-cached address */
    MaxBeginAddr  =  MAP2CREGPA(MaxBeginAddr);


    /* Now we get the maximum segments */
    *Return_begin_addr   = (kal_uint32 *)MaxBeginAddr;
    *Return_segment_size = MaxLength;
}


/*************************************************************************
* FUNCTION
*  custom_mk_ram_info
*
* DESCRIPTION
*  This function builds up EXTSRAM info tables.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__MTK_MMU__) || defined(__CR4__)
kal_int32 custom_mk_ram_info()
{
    /* This table contains all dynamic cacheable default non-cacheable regions. */
    DYNAMIC_CACHED_EXTSRAM_DNC_REGION[0].addr = (kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI_MMIPOOL$$Base;
    DYNAMIC_CACHED_EXTSRAM_DNC_REGION[0].len = (kal_uint32)((kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW$$Base + (kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW$$Length) - DYNAMIC_CACHED_EXTSRAM_DNC_REGION[0].addr;
    DYNAMIC_CACHED_EXTSRAM_DNC_REGION[1].addr = DYNAMIC_CACHED_EXTSRAM_DNC_REGION[1].len = 0;


    /* This table contains all dynamic cacheable default cacheable regions. */
    DYNAMIC_CACHED_EXTSRAM_DC_REGION[0].addr = (kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_RW$$Base;
    DYNAMIC_CACHED_EXTSRAM_DC_REGION[0].len = (kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI$$ZI$$Limit - DYNAMIC_CACHED_EXTSRAM_DC_REGION[0].addr;
    DYNAMIC_CACHED_EXTSRAM_DC_REGION[1].addr = DYNAMIC_CACHED_EXTSRAM_DC_REGION[1].len = 0;


    /* This table contains all cached regions. */
    CACHED_EXTSRAM_REGION[0].addr = (kal_uint32)&Image$$CACHED_EXTSRAM$$Base;
    CACHED_EXTSRAM_REGION[0].len = (kal_uint32)&Image$$EXTSRAM_GADGET$$ZI$$Limit - CACHED_EXTSRAM_REGION[0].addr;
    CACHED_EXTSRAM_REGION[1].addr = CACHED_EXTSRAM_REGION[1].len = 0;


    /* This table contains all cached code regions. */
    CACHED_EXTSRAM_CODE_REGION[0].addr = CACHED_EXTSRAM_CODE_REGION[0].len = 0;


    /* This table contains all non-cached rw regions. */
    NONCACHED_EXTSRAM_REGION[0].addr = (kal_uint32)&Image$$SINGLE_BANK_CODE$$Base;
    NONCACHED_EXTSRAM_REGION[0].len = (kal_uint32)&Image$$EXTSRAM$$ZI$$Limit - NONCACHED_EXTSRAM_REGION[0].addr;
    NONCACHED_EXTSRAM_REGION[1].addr = (kal_uint32)&Image$$EXTSRAM_DSP_TX$$Base;
    NONCACHED_EXTSRAM_REGION[1].len = 0x6000;
    NONCACHED_EXTSRAM_REGION[2].addr = (kal_uint32)&Image$$EXTSRAM_DSP_RX$$Base;
    NONCACHED_EXTSRAM_REGION[2].len = 0xf000;
    NONCACHED_EXTSRAM_REGION[3].addr = NONCACHED_EXTSRAM_REGION[3].len = 0;


    /* This table contains all non-cached ro regions. */
    NONCACHED_EXTSRAM_RO_REGION[0].addr = NONCACHED_EXTSRAM_RO_REGION[0].len = 0;


    /* This table contains all ROM load regions. */
    CACHED_EXTCODE_REGION[0].addr = (kal_uint32)&Image$$ROM_GFH$$Base;
    CACHED_EXTCODE_REGION[0].len = custom_get_1st_ROM_ROMLength();
    CACHED_EXTCODE_REGION[1].addr = CACHED_EXTCODE_REGION[1].len = 0;


    /* This table contains all extra load regions. */
    MULTI_ROM_LOAD_REGION[0].addr = MULTI_ROM_LOAD_REGION[0].len = 0;


    return 0;
}
#endif /* __ARM9_MMU__ || __ARM11_MMU__ || __MTK_MMU__ || __CR4__ */

#if defined(__DSP_FCORE4__)

/*************************************************************************
* FUNCTION
*  custom_mk_mcu_dsp_sharemem_info
*
* DESCRIPTION
*  This function builds up MCU-DSP Shared EXTSRAM info tables.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_int32 custom_mk_mcu_dsp_sharemem_info()
{
    /* This table contains all MCU-cacheable, DSP-cacheable shared regions. */
#if defined(__MED_IN_ASM__)
    #if __VIDEO_STANDALONE_MEMORY__
    MCU_C_DSP_C_REGION[0].addr = ((kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_VIDEOPOOL$$Base & (~0xf0000000));
    MCU_C_DSP_C_REGION[0].len = ((kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL$$Base & (~0xf0000000)) - MCU_C_DSP_C_REGION[0].addr;
    #else /* __VIDEO_STANDALONE_MEMORY__ */
    MCU_C_DSP_C_REGION[0].addr = ((kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL$$Base & (~0xf0000000));
    MCU_C_DSP_C_REGION[0].len = ((kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI$$Base & (~0xf0000000)) - MCU_C_DSP_C_REGION[0].addr;
    #endif /* __VIDEO_STANDALONE_MEMORY__ */
#else  /* __MED_IN_ASM__ */
    MCU_C_DSP_C_REGION[0].addr = (kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI_MMIPOOL$$Base;
    MCU_C_DSP_C_REGION[0].len = (kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI$$Base - MCU_C_DSP_C_REGION[0].addr;
#endif  /* __MED_IN_ASM__ */
    MCU_C_DSP_C_REGION[1].addr = MCU_C_DSP_C_REGION[1].len = 0;


    /* This table contains all MCU-cacheable, DSP-noncacheable shared regions. */
    MCU_C_DSP_NC_REGION[0].addr = MCU_C_DSP_NC_REGION[0].len = 0;


    /* This table contains all MCU-noncacheable, DSP-cacheable shared regions. */
    MCU_NC_DSP_C_REGION[0].addr = MCU_NC_DSP_C_REGION[0].len = 0;


    /* This table contains all MCU-noncacheable, DSP-noncacheable shared regions. */
    MCU_NC_DSP_NC_REGION[0].addr = (kal_uint32)&Image$$EXTSRAM_DSP_TX$$Base;
    MCU_NC_DSP_NC_REGION[0].len = 0x6000;
    MCU_NC_DSP_NC_REGION[1].addr = (kal_uint32)&Image$$EXTSRAM_DSP_RX$$Base;
    MCU_NC_DSP_NC_REGION[1].len = 0xf000;
    MCU_NC_DSP_NC_REGION[2].addr = MCU_NC_DSP_NC_REGION[2].len = 0;


    return 0;
}
#endif /* __DSP_FCORE4__ */

#if defined(MT6256)
/*************************************************************************
* FUNCTION
*  custom_get_DSPEXTRO_Base
*
* DESCRIPTION
*  Retrieve the lowest base address of DSP_RO regions
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_int32 custom_get_DSPEXTRO_Base(void)
{
    return (kal_uint32)&Image$$DSP_ROM$$Base;
}

/*************************************************************************
* FUNCTION
*  custom_get_DSPEXTRO_Length
*
* DESCRIPTION
*  Retrieve the length of DSP_RO regions
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_int32 custom_get_DSPEXTRO_Length(void)
{
    return 0;
}
/*************************************************************************
* FUNCTION
*  custom_get_DSPEXTRW_Base
*
* DESCRIPTION
*  Retrieve the lowest base address of DSP_RW regions
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_int32 custom_get_DSPEXTRW_Base(void)
{
    return (kal_uint32)&Image$$SECONDARY_EXTSRAM_DSP_RW_MCU_RW_TX1$$Base;
}

/*************************************************************************
* FUNCTION
*  custom_get_DSPEXTRW_Length
*
* DESCRIPTION
*  Retrieve the length of DSP_RW regions
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_int32 custom_get_DSPEXTRW_Length(void)
{
    return (0+0+0);
}

/*************************************************************************
* FUNCTION
*  custom_get_DSP_DMA_RegionInfo
*
* DESCRIPTION
*  Retrieve the information of DSP regions that need to be shared with DMA
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_bool custom_get_DSP_DMA_RegionInfo(kal_uint32 *TX_Base, kal_uint32 *RX_Base, kal_uint32 *CS, kal_uint32 *TX_Size, kal_uint32 *RX_Size)
{
   *TX_Base = (kal_uint32)&Image$$SECONDARY_EXTSRAM_DSP_RW_MCU_RW_DMA_RW_TX2_AND_RX$$Base;
   *RX_Base = (kal_uint32)&Image$$SECONDARY_EXTSRAM_DSP_DMA_RX$$Base;
   *TX_Size = 0;
   *RX_Size = 0;

   /*Note: TX_Base & RX_Base should be in the same region*/
   *CS      = (*TX_Base&0xF8000000) >> 27;

    return KAL_TRUE;
}
#else //!defined(MT6256)
/*************************************************************************
* FUNCTION
*  custom_get_DSP_ROM_ROMBase
*
* DESCRIPTION
*  Retrieve the base address of DSP_ROM (Load View)
*  This function must sync with scatter file structure
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_DSP_ROM_ROMBase(void)
{
    return 0;
}
/*************************************************************************
* FUNCTION
*  custom_get_DSP_ROM_ROMLength
*
* DESCRIPTION
*  Retrieve the actual ROM length of DSP_ROM (Load View)
*  This function must sync with scatter file structure
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_DSP_ROM_ROMLength(void)
{
    kal_uint32 ROMLength = 0;

    ROMLength += 0;

    return ROMLength; 
}
#endif

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
kal_uint32 custom_get_FLMM_PASPACE_Base(void)
{
    return (kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_FLMM_PASPACE$$Base & (~0xf0000000);
}

kal_uint32 custom_get_FLMM_PASPACE_End(void)
{
    return (kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_FLMM_PASPACE$$ZI$$Limit & (~0xf0000000);
}

kal_uint32 custom_get_FLMM_VASPACE_Base(void)
{
    return (kal_uint32)&Image$$FLMM_VASPACE$$Base;
}

kal_uint32 custom_get_FLMM_VASPACE_End(void)
{
    return (kal_uint32)&Image$$FLMM_VASPACE$$ZI$$Limit; 
}

kal_uint32 custom_get_FLMM_STACKSPACE_Base(void)
{
    return (kal_uint32)&Image$$FLMM_STACKSPACE$$Base;
}

kal_uint32 custom_get_FLMM_STACKSPACE_End(void)
{
    return (kal_uint32)&Image$$FLMM_STACKSPACE$$ZI$$Limit; 
}
#endif
/*************************************************************************
* FUNCTION
*  custom_get_NVRAM_LTABLE_Base
*
* DESCRIPTION
*  Retrieve the base address of NVRAM_LTABLE
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_NVRAM_LTABLE_Base(void)
{
    return (kal_uint32)&Image$$TRACK_NVRAM_GFH$$Base;
}

/*************************************************************************
* FUNCTION
*  custom_get_NVRAM_LTABLE_Length
*
* DESCRIPTION
*  Retrieve the length of NVRAM_LTABLE
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_get_NVRAM_LTABLE_Length(void)
{
    return (kal_uint32)&Image$$TRACK_NVRAM_GFH$$Length;
}


/*************************************************************************
* FUNCTION
*  custom_query_dump_region
*
* DESCRIPTION
*  This function builds up the table of DUMP REGIONs.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 custom_query_dump_region(EXTSRAM_REGION_INFO_T* region)
{
    region[0].addr = (kal_uint32)&Image$$ALICE$$Base;
    region[0].len = (kal_uint32)&Image$$ALICE$$ZI$$Limit - region[0].addr;
    {
    kal_uint32 aliceCompressedBase, aliceCompressedLength;
    AliceGetCompressedDumpRegion(&aliceCompressedBase, &aliceCompressedLength);
    region[1].addr = aliceCompressedBase;
    region[1].len = aliceCompressedLength;
    }
    region[2].addr = (kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI_MMIPOOL$$Base;
    region[2].len = (kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW$$ZI$$Limit - region[2].addr;
    region[3].addr = (kal_uint32)&Image$$SINGLE_BANK_CODE$$Base;
    region[3].len = (kal_uint32)&Image$$EXTSRAM$$ZI$$Limit - region[3].addr;
    region[4].addr = (kal_uint32)&Image$$EXTSRAM_DSP_TX$$Base;
    region[4].len = 0x6000;
    region[5].addr = (kal_uint32)&Image$$EXTSRAM_DSP_RX$$Base;
    region[5].len = 0xf000;
    region[6].addr = (kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_RW$$Base;
    region[6].len = (kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI$$ZI$$Limit - region[6].addr;
    region[6].addr = MAP2CREGPA(region[6].addr);
    region[7].addr = 0x0;
    region[7].len = 0x200;
    region[8].addr = (kal_uint32)&Image$$CACHED_EXTSRAM$$Base;
    region[8].len = (kal_uint32)&Image$$EXTSRAM_GADGET$$ZI$$Limit - region[8].addr;
    region[9].addr = (kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI_MMIPOOL$$Base;
    region[9].len = (kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW$$ZI$$Limit - region[9].addr;
    region[9].addr = MAP2CREGVA(region[9].addr);
    region[10].addr = (kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_RW$$Base;
    region[10].len = (kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI$$ZI$$Limit - region[10].addr;
    region[11].addr = (kal_uint32)&Image$$INTSRAM_CODE$$Base;
    region[11].len = 0x1200;
    region[12].addr = (kal_uint32)&Image$$INTSRAM_DATA$$Base;
    region[12].len = 0xe00;

    return DUMP_REGION_COUNT*2;
}

/*************************************************************************
* FUNCTION
*  custom_check_code_address
*
* DESCRIPTION
*  This function checks the input address is belongs to code region or not
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
static EXTSRAM_REGION_INFO_T TOTAL_CODE_REGION[11];

kal_bool custom_check_code_address(kal_uint32 address)
{
    kal_uint32 i;
    kal_bool ret = KAL_FALSE;
    TOTAL_CODE_REGION[0].addr = (kal_uint32)&Image$$ROM_GFH$$RO$$Base;
    TOTAL_CODE_REGION[0].len = custom_get_1st_ROM_ROMLength();
    TOTAL_CODE_REGION[1].addr = (kal_uint32)&Image$$SINGLE_BANK_CODE$$RO$$Base;
    TOTAL_CODE_REGION[1].len = (kal_uint32)&Image$$SINGLE_BANK_CODE$$RO$$Length;
    TOTAL_CODE_REGION[2].addr = (kal_uint32)&Image$$EMIINIT_CODE$$RO$$Base;
    TOTAL_CODE_REGION[2].len = (kal_uint32)&Image$$EMIINIT_CODE$$RO$$Length;
    TOTAL_CODE_REGION[3].addr = (kal_uint32)&Image$$INTSRAM_CODE$$RO$$Base;
    TOTAL_CODE_REGION[3].len = (kal_uint32)&Image$$INTSRAM_CODE$$RO$$Length;
    TOTAL_CODE_REGION[4].addr = (kal_uint32)&Image$$ALICE$$RO$$Base;
    TOTAL_CODE_REGION[4].len = (kal_uint32)&Image$$ALICE$$RO$$Length;
    TOTAL_CODE_REGION[5].addr = (kal_uint32)&Image$$TRACK_GFH_RO$$RO$$Base;
    TOTAL_CODE_REGION[5].len = (kal_uint32)&Image$$TRACK_GFH_RO$$RO$$Length;
    TOTAL_CODE_REGION[6].addr = (kal_uint32)&Image$$TRACK_RO$$RO$$Base;
    TOTAL_CODE_REGION[6].len = (kal_uint32)&Image$$TRACK_RO$$RO$$Length;
    TOTAL_CODE_REGION[7].addr = (kal_uint32)&Image$$TRACK_GFH_RW$$RO$$Base;
    TOTAL_CODE_REGION[7].len = (kal_uint32)&Image$$TRACK_GFH_RW$$RO$$Length;
    TOTAL_CODE_REGION[8].addr = (kal_uint32)&Image$$TRACK_RAM$$RO$$Base;
    TOTAL_CODE_REGION[8].len = (kal_uint32)&Image$$TRACK_RAM$$RO$$Length;
    TOTAL_CODE_REGION[9].addr = (kal_uint32)&Image$$TRACK_NVRAM$$RO$$Base;
    TOTAL_CODE_REGION[9].len = (kal_uint32)&Image$$TRACK_NVRAM$$RO$$Length;
    TOTAL_CODE_REGION[10].addr = 0x0;
    TOTAL_CODE_REGION[10].len = 0x200;
	
    for(i=0;i<sizeof(TOTAL_CODE_REGION)/sizeof(TOTAL_CODE_REGION[0]);i++)
    {
      if(TOTAL_CODE_REGION[i].len != 0
      	&& address >= TOTAL_CODE_REGION[i].addr
        && address < (TOTAL_CODE_REGION[i].addr + TOTAL_CODE_REGION[i].len)) 
      {
        ret = KAL_TRUE;
        break;
      }
    }

    return ret;
}
#endif /* __MTK_TARGET__ */
