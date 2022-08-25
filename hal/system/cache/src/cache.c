/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   cache.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the functionality of Code and Data cache.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************************
 * README
 * Test platform after revision
 * [1] NOR Flash boot without remap , MT6229_EVB
 * [2] NAND Flash boot , MT6228_EVB
 * [3] NOR Flash boot with remap , MT6225 + Single Bank NOR Flash , for example CRYSTAL25 V3 SB
 ********************************************************************************************/


/*******************************************************************************
 * Include header files.
 *******************************************************************************/

#include "cache_hw_int.h"
#include "cache_sw_int.h"
#include "cache_sw.h"
#include "init.h"
#include "cp15.h"
#include "mmu.h"
#include "custom_scatstruct.h"
#if defined(__MTK_MMU__)
#include "custom_emi_release.h"
#endif /* __MTK_MMU__ */
#include "system_trc.h"
#include "init_trc_api.h"
#include "kal_trace.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "drv_comm.h"
#if defined(__KAL_VM__) && !defined(__FUE__) && !defined(__UBL__)
#include "kal_vm.h"
#endif /* __KAL_VM__ && !__FUE__ && !__UBL__ */
#include "config_hw.h"
    
#if defined(MT6238) || defined(MT6239)
extern ECO_VERSION mt6238_version;
#endif /* MT6238 || MT6239 */

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
extern unsigned int cache_line_nr;
extern unsigned int cache_line_nr_per_way;
#endif /* __ARM9_MMU__ || __ARM11_MMU__ */

#if defined(__MTK_MMU__)
// to resolve build warnings
kal_int32 clean_and_invalidate_l1cache(kal_uint32 addr, kal_uint32 len);
#endif /* __MTK_MMU__ */

extern kal_uint32 query_opposite_switchable_cacheaddr_ram(kal_uint32 addr);

#ifdef __MTK_TARGET__

/*******************************************************************************
 * Define import functions.
 *******************************************************************************/

extern void RestoreIRQMask(kal_uint32 ret);
extern kal_uint32 SaveAndSetIRQMask(void);
extern kal_uint32 custom_get_NORFLASH_ROMSpace(void);
extern kal_int32 query_is_l1cache_cacheable(kal_uint32 addr, kal_uint32 len, kal_uint32 query_ram);


/*******************************************************************************
 * Define global data.
 *******************************************************************************/

#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)
static kal_uint16 MPUChannelStatus = 0;
static kal_uint16 CodeCacheChannelStatus = 0;
static const kal_uint32 CACHE_CHANNEL_OFFSET_TABLE[15] = {0xa, 0xb, 0xc, 0xd, 0xe, 0xf, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18};
#endif  /* __MTK_L1_CACHEABLE__ */

#if defined(__MTK_L2CACHEABLE__)
static kal_bool l2c_fbbr = 0, l2c_mpeg4 = 0;
#endif  /* __MTK_L2_CACHEABLE__ */

/*************************************************************************
* FUNCTION
*  GateDG
*
* DESCRIPTION
*  This function used to gate DMA and GMC.
*  NoteXXX: This function is dedicated for IDLE.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  0
*
*************************************************************************/

#if defined(__MTK_L2CACHEABLE__)

#pragma arm section code = "INTSRAM_ROCODE"

kal_uint32 GateDG(void)
{
   kal_uint32 val = 0;

   /* NoteXXX: no need to disable IRQ since idle task already did it */

   /* check MPEG4 mode */
   if (l2c_mpeg4 == KAL_TRUE)
   { 
#if !defined(MT6238) && !defined(MT6239)
      val |= DataCacheLocking2Way;
#endif /* !MT6238 */
   }

   /* check FBBR */
   if (l2c_fbbr == KAL_TRUE)
      val |= DataCacheFBBR;

   /* get DMA and GMC */
   val |= DataCacheGATEDG;

#if defined(MT6238) || defined(MT6239)
   if((*EMI_CONN & DRAM_TYPE_MASK) != DRAM_TYPE_DDR)
   {
      /* config L2 data cache. */
   *L2C_CON = val | DataCacheEnabled;
   }
#else
   *L2C_CON = val | DataCacheEnabled;
#endif /* MT6238 || MT6239*/

   /* no need to wait for data cache ready since it will block all accesses automatically */
//   DataCacheWaitCommandReady();

   return 0;
}

#pragma arm section code

#endif /* __MTK_L2CACHEABLE__ */

/*************************************************************************
* FUNCTION
*  UngateDG
*
* DESCRIPTION
*  This function used to un-gate DMA and GMC.
*  NoteXXX: This function is dedicated for IDLE.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  val   -   useless
*
* RETURNS
*  None
*
*************************************************************************/

#if defined(__MTK_L2CACHEABLE__)

#pragma arm section code = "INTSRAM_ROCODE"

void UngateDG(kal_uint32 val)
{
   val = 0;

   /* NoteXXX: no need to disable IRQ since idle task already did it */

   /* check MPEG4 mode */
   if (l2c_mpeg4 == KAL_TRUE)
   {
#if !defined(MT6238) && !defined(MT6239) 
      val |= DataCacheLocking2Way;
#endif /* !MT6238 */
   }

   /* check FBBR */
   if (l2c_fbbr == KAL_TRUE)
      val |= DataCacheFBBR;

   /* un-gate DMA and GMC */
#if defined(MT6238) || defined(MT6239)
   if((*EMI_CONN & DRAM_TYPE_MASK) != DRAM_TYPE_DDR)
   {
      /* config L2 data cache. */
      *L2C_CON = val | DataCacheEnabled;
   }
#else
   *L2C_CON = val | DataCacheEnabled;
#endif /* MT6238 || MT6239*/

   /* no need to wait for data cache ready since it will block all accesses automatically */
//   DataCacheWaitCommandReady();
}

#pragma arm section code

#endif /* __MTK_L2CACHEABLE__ */

/*************************************************************************
* FUNCTION
*  EnableFBBR
*
* DESCRIPTION
*  This function used to eanble FBBR.
*  NoteXXX: This function is dedicated for JAVA.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  0
*
*************************************************************************/

#if defined(__MTK_L2CACHEABLE__)

kal_uint32 EnableFBBR(void)
{
   kal_uint32 saved, val = 0;

   /* disable IRQ */
   saved = SaveAndSetIRQMask();

   /* save flag */
   l2c_fbbr = KAL_TRUE;

   /* check MPEG4 mode */
   if (l2c_mpeg4 == KAL_TRUE)
   {
#if !defined(MT6238) && !defined(MT6239) 
      val |= DataCacheLocking2Way;
#endif /* !MT6238 */
   }

   /* enable FBBR */
   val |= DataCacheFBBR;

#if defined(MT6238) || defined(MT6239)
   if((*EMI_CONN & DRAM_TYPE_MASK) != DRAM_TYPE_DDR)
   {
      /* config L2 data cache. */
   *L2C_CON = val | DataCacheEnabled;
   }
#else
      *L2C_CON = val | DataCacheEnabled;
#endif /* MT6238 || MT6239*/

   /* restore IRQ */
   RestoreIRQMask(saved);

   /* wait for data cache ready */
   /* no need to disable IRQ since data cache will block all accesses */
   DataCacheWaitCommandReady();

   return 0;
}

#endif /* __MTK_L2CACHEABLE__ */

/*************************************************************************
* FUNCTION
*  DisableFBBR
*
* DESCRIPTION
*  This function used to disable FBBR.
*  NoteXXX: This function is dedicated for JAVA.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  val   -   useless
*
* RETURNS
*  None
*
*************************************************************************/

#if defined(__MTK_L2CACHEABLE__)

void DisableFBBR(kal_uint32 val)
{
   kal_uint32 saved;

   val = 0;

   /* disable IRQ */
   saved = SaveAndSetIRQMask();

   /* save flag */
   l2c_fbbr = KAL_FALSE;

   /* check MPEG4 mode */
   if (l2c_mpeg4 == KAL_TRUE)
   {
#if !defined(MT6238) && !defined(MT6239) 
      val |= DataCacheLocking2Way;
#endif /* !MT6238 && !MT6239 */
   }

   /* disable FBBR */
#if defined(MT6238) || defined(MT6239)
   if((*EMI_CONN & DRAM_TYPE_MASK) != DRAM_TYPE_DDR)
   {
      /* config L2 data cache. */
      *L2C_CON = val | DataCacheEnabled;
   }
#else
   *L2C_CON = val | DataCacheEnabled;
#endif /* MT6238 || MT6239*/

   /* restore IRQ */
   RestoreIRQMask(saved);

   /* wait for data cache ready */
   /* no need to disable IRQ since data cache will block all accesses */
   DataCacheWaitCommandReady();
}

#endif /* __MTK_L2CACHEABLE__ */

/*************************************************************************
* FUNCTION
*  Lock2WaysForMPEG4
*
* DESCRIPTION
*  This function used to lock 2 cache ways for VIDEO ENCODE.
*  NoteXXX: this function is dedicated for VIDEO ENCODE.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  0
*
*************************************************************************/

#if defined(__MTK_L2CACHEABLE__)

#if !defined(MT6238) && !defined(MT6239)

kal_uint32 Lock2WaysForMPEG4(void)
{
   kal_uint32 saved, val = 0;

   /* disable IRQ */
   saved = SaveAndSetIRQMask();

   /* set flag */
   l2c_mpeg4 = KAL_TRUE;

   /* check FBBR */
   if (l2c_fbbr == KAL_TRUE)
      val |= DataCacheFBBR;

   /* lock 2 cache ways */
   val |= DataCacheLocking2Way;

   *L2C_CON = val | DataCacheEnabled;

   /* restore IRQ */
   RestoreIRQMask(saved);

   /* wait for data cache ready */
   /* no need to disable IRQ since data cache will block all accesses */
   DataCacheWaitCommandReady();

   return 0;
}

#endif /* !MT6238 && !MT6239 */

#endif /* __MTK_L2CACHEABLE__ */

/*************************************************************************
* FUNCTION
*  Unlock2WaysForMPEG4
*
* DESCRIPTION
*  This function used to unlock 2 ways reserved by VIDEO ENCODE.
*  NoteXXX: This function is dedicated for VIDEO ENCODE.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  val   -   useless
*
* RETURNS
*  None
*
*************************************************************************/

#if defined(__MTK_L2CACHEABLE__)

#if !defined(MT6238) && !defined(MT6239)

void Unlock2WaysForMPEG4(kal_uint32 val)
{
   kal_uint32 saved;

   val = 0;

   /* disable IRQ */
   saved = SaveAndSetIRQMask();

   /* save flag */
   l2c_mpeg4 = KAL_FALSE;

   if (l2c_fbbr == KAL_TRUE)
      val |= DataCacheFBBR;

   /* un-lock 2 cache ways */
   *L2C_CON = val | DataCacheEnabled;

   /* restore IRQ */
   RestoreIRQMask(saved);

   /* wait for data cache ready */
   /* no need to disable IRQ since data cache will block all accesses */
   DataCacheWaitCommandReady();
}

#endif /* !MT6238 && !MT6239 */

#endif /* __MTK_L2CACHEABLE__ */

/*************************************************************************
* FUNCTION
*  invalidate_arm9_icache
*
* DESCRIPTION
*  This function invalidates the buffer's data in ICache.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr     -   address of the buffer
*  len      -   length of the buffer (in bytes)
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/

#if defined(__ARM9_MMU__)

kal_int32 invalidate_arm9_icache(kal_uint32 addr, kal_uint32 len)
{
   /*
    * NoteXXX: Each cache line in ARM9 DCache is 32B. Every invalidate operation
    *          must aligned in a 32B address.
    *
    */

   if (addr & CPU_CACHE_LINE_SIZE_MASK) {
      ASSERT(0);
   } else if (len & CPU_CACHE_LINE_SIZE_MASK) {
      ASSERT(0);
   } else {
      cp15_invalidate_icache_region(addr, len/CPU_CACHE_LINE_SIZE);
   }

   return 0;   
}

#endif  /* __ARM9_MMU__ */

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) || defined(__WRITE_THROUGH_CACHEABLE__)
kal_int32 invalidate_icache(kal_uint32 addr, kal_uint32 len)
{
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
   /*
    * NoteXXX: Each cache line in ARM9/ARM11 ICache is 32B. Every invalidate operation
    *          must aligned in a 32B address.
    *
    */

   if (addr & CPU_CACHE_LINE_SIZE_MASK) {
      ASSERT(0);
   } else if (len & CPU_CACHE_LINE_SIZE_MASK) {
      ASSERT(0);
   } else {
#if defined(__MTK_MMU__)
      invalidate_l1cache(addr, len);
#else
      cp15_invalidate_icache_region(addr, len/CPU_CACHE_LINE_SIZE);
#endif /* __MTK_MMU__ */
   }

   return 0;   

#else /* __DYNAMIC_SWITCH_CACHEABILITY__ */


   kal_uint32 i = 0;	

   /* NoteXXX: Each cache line in MTK L1 Cache is 32B. Every invalidate operation must aligned in a 32B address. */
   if (addr & CPU_CACHE_LINE_SIZE_MASK) {
      ASSERT(0);
   } else if (len & CPU_CACHE_LINE_SIZE_MASK) {
      ASSERT(0);
   } else {
#if defined(MT6225) || defined(MT6253)
      /* faster for MT6253 & MT6225 if the len is larger than 8K */
      if(len >= 8 * 1024) {
         MTKL1CACHE_InvalidAllCacheLines();
      }
#endif /* MT6225 || MT6253 */
   	
      for(i = 0; i < len/CPU_CACHE_LINE_SIZE; i++) {
         InvalidCodeCacheByAlignedAddr(addr);
         addr += CPU_CACHE_LINE_SIZE;
      }
   }

   return 0;
#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ */
}

#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ || __WRITE_THROUGH_CACHEABLE__ */

/*************************************************************************
* FUNCTION
*  invalidate_arm9_dcache
*
* DESCRIPTION
*  This function invalidates the buffer's data in DCache.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr     -   address of the buffer
*  len      -   length of the buffer (in bytes)
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/

#if defined(__ARM9_MMU__)

kal_int32 invalidate_arm9_dcache(kal_uint32 addr, kal_uint32 len)
{
    /*
     * NoteXXX: Each cache line in ARM9 DCache is 32B. Every invalidate operation
     *          must aligned in a 32B address.
     *
     */

    if (addr & CPU_CACHE_LINE_SIZE_MASK)
    {
        ASSERT(0);
    }
    else if (len & CPU_CACHE_LINE_SIZE_MASK)
    {
        ASSERT(0);
    }
    else
    {
      cp15_invalidate_dcache_region(addr, len/CPU_CACHE_LINE_SIZE);
   }

   return 0;
}

#endif  /* __ARM9_MMU__ */


#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) || defined(__WRITE_THROUGH_CACHEABLE__)
kal_int32 invalidate_dcache(kal_uint32 addr, kal_uint32 len)
{
#if  defined(__DYNAMIC_SWITCH_CACHEABILITY__)
   /*
    * NoteXXX: Each cache line in ARM9 DCache is 32B. Every invalidate operation
    *          must aligned in a 32B address.
    *
    */
   if ((addr & CPU_CACHE_LINE_SIZE_MASK) ||
   	   (len & CPU_CACHE_LINE_SIZE_MASK))
   {
      EXT_ASSERT(0, addr, len, 0);
   } else {
#if defined(__MTK_MMU__)
      invalidate_l1cache(addr, len);
#else
      /* ARM Cache Operation */
      kal_uint32 operate_line_nr;
      operate_line_nr=len / CPU_CACHE_LINE_SIZE;
      
      /* 
       * If operating length larger than cache size,
       * We will do a full cache clean+invalidate to improve the responsiveness
       * Note that we will do this no matter it is a MMv2 buffer or not
       */
      if(operate_line_nr>cache_line_nr)
      {
          cp15_clean_and_invalidate_all_dcache_by_setway();
          return 0;
      }
#if defined(__KAL_VM__) && !defined(__FUE__) && !defined(__UBL__)
      if(is_flmm_va(addr))
      {
   	     return flmm_invalidate_dcache(addr, len);
      }
#endif /* __KAL_VM__ && !__FUE__ && !__UBL__ */

      cp15_invalidate_dcache_region(addr, len/CPU_CACHE_LINE_SIZE);
#endif /* __MTK_MMU__ */
   }

   return 0;
#else /* __DYNAMIC_SWITCH_CACHEABILITY__ */

   kal_uint32 i = 0;	

   /* NoteXXX: Each cache line in MTK L1 Cache is 32B. Every invalidate operation must aligned in a 32B address. */
   if ((addr & CPU_CACHE_LINE_SIZE_MASK) ||
   	   (len & CPU_CACHE_LINE_SIZE_MASK))
   {
      EXT_ASSERT(0, addr, len, 0);
   } else {
#if defined(MT6225) || defined(MT6253)
      /* faster for MT6253 & MT6225 if the len is larger than 8K */
      if(len >= 8 * 1024) {
         MTKL1CACHE_InvalidAllCacheLines();
      }
#endif /* MT6225 || MT6253 */
   	
      for(i = 0; i < len/CPU_CACHE_LINE_SIZE; i++) {
         InvalidCodeCacheByAlignedAddr(addr);
         addr += CPU_CACHE_LINE_SIZE;
      }
   }

   return 0;

#endif  /* __DYNAMIC_SWITCH_CACHEABILITY__ */
}

#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ || __WRITE_THROUGH_CACHEABLE__ */

/*************************************************************************
* FUNCTION
*  clean_arm9_dcache
*
* DESCRIPTION
*  This function cleans the buffer's data in DCache.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr     -   address of the buffer
*  len      -   length of the buffer (in bytes)
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/

#if defined(__ARM9_MMU__)

kal_int32 clean_arm9_dcache(kal_uint32 addr, kal_uint32 len)
{
   /*
    * NoteXXX: Each cache line in ARM9 DCache is 32B. Every invalidate operation
    *          must aligned in a 32B address.
    *
    */

   if (addr & CPU_CACHE_LINE_SIZE_MASK) {
      ASSERT(0);
   } else if (len & CPU_CACHE_LINE_SIZE_MASK) {
      ASSERT(0);
   } else {
      cp15_clean_dcache_region(addr, len/CPU_CACHE_LINE_SIZE);
   }

   /* drain write buffer to ensure data is flushed */
   cp15_drain_write_buffer();

   return 0;
}
#endif  /* __ARM9_MMU__ */


#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
kal_int32 clean_dcache(kal_uint32 addr, kal_uint32 len)
{
   /*
    * NoteXXX: Each cache line in ARM9 DCache is 32B. Every invalidate operation
    *          must aligned in a 32B address.
    *
    */

   if ((addr & CPU_CACHE_LINE_SIZE_MASK) ||
       (len & CPU_CACHE_LINE_SIZE_MASK))
   {
      EXT_ASSERT(0, addr, len, 0);
   } else {
#if defined(__MTK_MMU__)
    clean_l1cache(addr, len);
#else
      /* For ARM9/ARM11/CR4 */
      kal_uint32 operate_line_nr;
      operate_line_nr=len / CPU_CACHE_LINE_SIZE;
      /* 
       * If operating length larger than cache size,
       * We will do a full cache clean to improve the responsiveness
       * Note that we will do this no matter it is a MMv2 buffer or not
       */
      if(operate_line_nr>cache_line_nr)
      {
          cp15_clean_all_dcache_by_setway();
          cp15_drain_write_buffer();
          return 0;
      }
#if defined(__KAL_VM__) && !defined(__FUE__) && !defined(__UBL__)
      if(is_flmm_va(addr))
      {
   	     return flmm_clean_dcache(addr, len);
      }
#endif /* __KAL_VM__ && !__FUE__ && !__UBL__ */

      cp15_clean_dcache_region(addr, len/CPU_CACHE_LINE_SIZE);
#endif /* __MTK_MMU__ */
   }

#if !defined(__MTK_MMU__)
   /* drain write buffer to ensure data is flushed */
   cp15_drain_write_buffer();
#endif /* __MTK_MMU__ */

   return 0;
}
#endif  /* __DYNAMIC_SWITCH_CACHEABILITY__ */

/*************************************************************************
* FUNCTION
*  clean_and_invalidate_arm9_dcache
*
* DESCRIPTION
*  This function cleans and invalidates the buffer's data in DCache.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr     -   address of the buffer
*  len      -   length of the buffer (in bytes)
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/

#if defined(__ARM9_MMU__)

kal_int32 clean_and_invalidate_arm9_dcache(kal_uint32 addr, kal_uint32 len)
{
   /*
    * NoteXXX: Each cache line in ARM9 DCache is 32B. Every invalidate operation
    *          must aligned in a 32B address.
    *
    */

   if (addr & CPU_CACHE_LINE_SIZE_MASK) {
      ASSERT(0);
   } else if (len & CPU_CACHE_LINE_SIZE_MASK) {
      ASSERT(0);
   } else {
      cp15_clean_and_invalidate_dcache_region(addr, len/CPU_CACHE_LINE_SIZE);
   }

   /* drain write buffer to ensure data is flushed */
   cp15_drain_write_buffer();

   return 0;
}

#endif  /* __ARM9_MMU__ */


#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
kal_int32 clean_and_invalidate_dcache(kal_uint32 addr, kal_uint32 len)
{
   /*
    * NoteXXX: Each cache line in ARM9 DCache is 32B. Every invalidate operation
    *          must aligned in a 32B address.
    *
    */

   if ((addr & CPU_CACHE_LINE_SIZE_MASK) ||
   	   (len & CPU_CACHE_LINE_SIZE_MASK))
   {
      EXT_ASSERT(0, addr, len, 0);
   } else {
#if defined(__MTK_MMU__)
    //clean_l1cache(addr, len);
    //invalidate_l1cache(addr, len);
    clean_and_invalidate_l1cache(addr,len);
#else
      /* For ARM9/ARM11/CR4 */
      kal_uint32 operate_line_nr;
      operate_line_nr=len / CPU_CACHE_LINE_SIZE;
      /* 
       * If operating length larger than cache size,
       * We will do a full cache clean+invalidate to improve the responsiveness
       * Note that we will do this no matter it is a MMv2 buffer or not
       */
      if(operate_line_nr>cache_line_nr)
      {
          cp15_clean_and_invalidate_all_dcache_by_setway();
          cp15_drain_write_buffer();
          return 0;
      }
#if defined(__KAL_VM__) && !defined(__FUE__) && !defined(__UBL__)
      if(is_flmm_va(addr))
      {
   	     return flmm_clean_and_invalidate_dcache(addr, len);
      }
#endif /* __KAL_VM__ && !__FUE__ && !__UBL__ */

      cp15_clean_and_invalidate_dcache_region(addr, len/CPU_CACHE_LINE_SIZE);
#endif /* __MTK_MMU__ */
   }

#if !defined(__MTK_MMU__)
   /* drain write buffer to ensure data is flushed */
   cp15_drain_write_buffer();
#endif /* __MTK_MMU__ */

   return 0;
}
#endif  /* __DYNAMIC_SWITCH_CACHEABILITY__ */


/*************************************************************************
* FUNCTION
*  MPUGetChannel
*
* DESCRIPTION
*  This function used to get MPU channel
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  Channel is numbered from 0 up to 7
*
* RETURNS
*
*************************************************************************/

#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)

kal_bool MPUGetChannel(kal_uint16 *channel)
{
   kal_uint16  i, status;
   kal_uint32  interruptMask;
      
   interruptMask = SaveAndSetIRQMask();
   
   status = MPUChannelStatus;
   
   for (i=0; i<MPU_CHANNEL_NUM; i++)
   {
      if ( status&0x01)
         status >>= 1;
      else
         break;
   }
   
   if ( i>=MPU_CHANNEL_NUM )
   {
      RestoreIRQMask(interruptMask);   
      return KAL_FALSE;
   }  
   
   *channel = i;
   
/* To be revised - START */
#if !defined(__FUE__) && !defined(__UBL__)
#if defined(PROTECT_REGION_BEFORE_INIT)
    {
        extern volatile kal_uint16 gChannel_mode;
        extern volatile kal_uint16 gChannel_protect;
        if (gChannel_mode == 0)
            gChannel_protect = i;
        else if (gChannel_mode == 1)
        {
            *channel = gChannel_protect;
            RestoreIRQMask(interruptMask);
            return KAL_TRUE;
        }
    }
#endif 
#endif
/* To be revised - END */

   MPUChannelStatus |= (0x01 << i);
   
   RestoreIRQMask(interruptMask);
   
   return KAL_TRUE;
}

#endif /* __MTK_L1CACHEABLE__ */

/*************************************************************************
* FUNCTION
*  MPUFreeChannel
*
* DESCRIPTION
*  This function used to get MPU channel
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  Channel is numbered from 0 up to 7
*   
*
* RETURNS
*
*************************************************************************/

#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)

kal_bool MPUFreeChannel(kal_uint16 *channel)
{   
   kal_uint16  channel_no = *channel;
   kal_uint32  interruptMask;
   
   ASSERT(channel_no<MPU_CHANNEL_NUM);
   
   interruptMask = SaveAndSetIRQMask();
   
   MPUChannelStatus &= ~(0x01 << channel_no);
   
   RestoreIRQMask(interruptMask);
   
   return KAL_TRUE;
}

#endif /* __MTK_L1CACHEABLE__ */

/*************************************************************************
* FUNCTION
*  CodeCacheGetChannel
*
* DESCRIPTION
*  This function used to get MPU channel
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  Channel is numbered from 0 up to 7
*
* RETURNS
*
*************************************************************************/

#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)

kal_bool CodeCacheGetChannel(kal_uint16 *channel)
{
   kal_uint16  i, status;
   kal_uint32  interruptMask;
      
   interruptMask = SaveAndSetIRQMask();
   
   status = CodeCacheChannelStatus;
   
   for (i=0; i<CACHE_CHANNEL_NUM; i++)
   {
      if ( status&0x01)
         status >>= 1;
      else
         break;
   }
   
   if ( i>=CACHE_CHANNEL_NUM )
   {
      RestoreIRQMask(interruptMask);   
      return KAL_FALSE;
   }  
   
   *channel = i;
   CodeCacheChannelStatus |= (0x01 << i);
   
   RestoreIRQMask(interruptMask);
   
   return KAL_TRUE;
}

#endif /* __MTK_L1CACHEABLE__ */


/*************************************************************************
* FUNCTION
*  CodeCacheFreeChannel
*
* DESCRIPTION
*  This function used to get MPU channel
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  Channel is numbered from 0 up to 7
*   
*
* RETURNS
*
*************************************************************************/

#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)

kal_bool CodeCacheFreeChannel(kal_uint16 *channel)
{   
   kal_uint16 channel_no = *channel;
   kal_uint32 interruptMask;
   
   ASSERT(channel_no<CACHE_CHANNEL_NUM);
   
   interruptMask = SaveAndSetIRQMask();
   
   CodeCacheChannelStatus &= ~(0x01 << channel_no);
   
   RestoreIRQMask(interruptMask);
   
   return KAL_TRUE;
}

#endif /* __MTK_L1CACHEABLE__ */

/*************************************************************************
* FUNCTION
*  CodeCacheConifg
*
* DESCRIPTION
*   This function could be used to configure code cache.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/

#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)

#pragma arm section code = "INTSRAM_ROCODE"

void CodeCacheConfig(CacheType type, kal_bool enable)
{  
   kal_uint32  interruptMask;
   
   interruptMask = SaveAndSetIRQMask();

   *CACHE_CON &= ~(0x0d);
   /* Invalid all cache line */
   *CACHE_OP = 0x03;
   /* Reset counters */
   *CACHE_HCNT0L = 0x00;
   *CACHE_HCNT0U = 0x00;
   *CACHE_CCNT0L = 0x00;
   *CACHE_CCNT0U = 0x00;
   *CACHE_HCNT1L = 0x00;
   *CACHE_HCNT1U = 0x00;
   *CACHE_CCNT1L = 0x00;
   *CACHE_CCNT1U = 0x00;
   
   if ( enable && (type!=NO_CACHE) ) {
      *CACHE_CON &= ~L1CACHE_GEN_CACHESIZE_MASK;
      
#if defined(__MTK_MMU__)

#if defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)

#if defined(__EMI_DEVICE_MODE_PAGE__)
      *CACHE_CON &= 0x7FFF;
      *CACHE_CON |= (type | 0x008d);
#else
      *CACHE_CON |= (type | 0x808d);
#endif /* */

#else
      *CACHE_CON |= (type | 0x800d);
#endif /* MT6253E || MT6253L */

#elif defined(MT6251)
#if defined(MT6251_S00)
      *CACHE_CON |= (type | 0xd80d); // MDRF_EN=0b'1, MDRF_TCM=0b'1, WRAP8=0b'1, RANDOM_CNT=0b'10
#else
      *CACHE_CON |= (type | 0xf80d); // MDRF_EN=0b'1, LF_IDLE_DIS=0b'1, MDRF_TCM=0b'1, WRAP8=0b'1, RANDOM_CNT=0b'10
#endif /* MT6251_S00 */
#else
      *CACHE_CON |= (type | 0x0d);
#endif /* __MTK_MMU__ */
   }
   RestoreIRQMask(interruptMask);
}

#pragma arm section code

#endif /* __MTK_L1CACHEABLE__ */

/*************************************************************************
* FUNCTION
*  CodeCacheSetting
*
* DESCRIPTION
*  This function used to initialization a cache region.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  This sub-routine takes care of the range alignment, also the least
*  cacheable region.
*
* RETURNS
*
*************************************************************************/

#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)

#pragma arm section code = "INTSRAM_ROCODE"

void CodeCacheSetting(CacheMenuType *cacheMenu)
{
   kal_uint32  setting, range, index, size;
   kal_uint32  interruptMask;

   ASSERT (cacheMenu->c_channel<CACHE_CHANNEL_NUM);
   ASSERT (cacheMenu->c_range<=MAX_CACHE_CHANNEL_LEN);
        
   /* Look forward the least-fit range */
   index = CACHE_SIZE_INDEX;
   size = MAX_CACHE_CHANNEL_LEN;
   range = cacheMenu->c_range;
   while ( range<size )
   {
      index--;
      size >>= 1;
      ASSERT(size >= MIN_CACHE_CHANNEL_LEN);
   }
   range = (RegionSize)((index)<<1);
   
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   setting = (cacheMenu->c_addr & 0xfffff000);
   if ( cacheMenu->c_enable )
      setting |= 0x00000100;;
#else /* MT6250 || MT6260 */
   setting = ((cacheMenu->c_addr & (0xffffffff << index)) & 0xfffffc00) | range;
   if ( cacheMenu->c_enable )
      setting |= 0x41;
#endif /* MT6250 */
   interruptMask = SaveAndSetIRQMask();
   
   *(MPU_CACHE0+cacheMenu->c_channel) = setting;
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   *(MPU_PROT0_END+cacheMenu->c_channel) = cacheMenu->c_addr + cacheMenu->c_range;
#endif /* MT6250 */   
   
#if defined(__MTK_MMU__)
#if !defined(MT6253E_S00)&&!defined(MT6253L_S00)&&!defined(MT6252H_S00)&&!defined(MT6252_S00)
   *MPU_CHANNEL_EN |= 1<<cacheMenu->c_channel;
#endif /* defined(MT6253E_S00)||defined(MT6253L_S00) */
#endif /* defined(__MTK_MMU__) */
   RestoreIRQMask(interruptMask);
}

#pragma arm section code

#endif /* __MTK_L1CACHEABLE__ */


/*************************************************************************
* FUNCTION
*  CodeCacheClearAllSetting
*
* DESCRIPTION
*  This function used to initialization a cache region.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  This sub-routine takes care of the range alignment, also the least
*  cacheable region.
*
* RETURNS
*
*************************************************************************/

#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)

#pragma arm section code = "INTSRAM_ROCODE"

void CodeCacheClearAllSetting(void)
{
   kal_uint32  status, index;

   *CACHE_CON &= ~(0x01);

   status = CodeCacheChannelStatus;

   for (index=0 ; index<CACHE_CHANNEL_NUM ; index++)
   {
      if ( status&0x01)
      {
         *(MPU_CACHE0+index) = 0;
      }
      status >>= 1;
   }
}

#pragma arm section code

#endif /* __MTK_L1CACHEABLE__ */


/*************************************************************************
* FUNCTION
*  MPUSetting
*
* DESCRIPTION
*  This function used to initialization a cache region.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  This sub-routine takes care of the range alignment, also the least
*  protectable region.
*
* RETURNS
*
*************************************************************************/

#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)

#pragma arm section code = "INTSRAM_ROCODE"

void MPUSetting(MPUMenuType *menu)
{
   kal_uint32 setting, range, index, size;
   kal_uint32 interruptMask;

   ASSERT (menu->m_channel<MPU_CHANNEL_NUM);
   ASSERT (menu->m_range<=MAX_MPU_CHANNEL_LEN);

   /* Look forward the least-fit range */
   index = MPU_SIZE_INDEX;
   size = MAX_MPU_CHANNEL_LEN;
   range = menu->m_range;
   while ( range<size )
   {
      index--;
      size >>= 1;
      ASSERT(size >= MIN_MPU_CHANNEL_LEN);
   }
   
#if defined(__MTK_MMU__)
#if defined(MT6253E_S00)||defined(MT6253L_S00)||defined(MT6252H_S00)||defined(MT6252_S00)
   range = (RegionSize)((index)<<1);
#else
   range = (RegionSize)(index);
#endif /* defined(MT6253E_S00)||defined(MT6253L_S00) */
#else
   range = (RegionSize)((index)<<1);
#endif /* defined(__MTK_MMU__) */
   
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   setting = (menu->m_addr & 0xfffff000) | menu->m_attribute;
#else /* MT6250 */
   setting = ((menu->m_addr & (0xffffffff << index)) & 0xfffffc00) | menu->m_attribute | range;
#endif /* MT6250 */
   
#if defined(__MTK_MMU__)
#if defined(MT6253E_S00)||defined(MT6253L_S00)||defined(MT6252H_S00)||defined(MT6252_S00)
   if ( menu->m_enable )
      setting |= 0x00000001;
#endif /* defined(MT6253E_S00)||defined(MT6253L_S00) */
#else
   if ( menu->m_enable )
      setting |= 0x00000001;
#endif /* defined(__MTK_MMU__) */

#if defined(__MTK_MMU__)
   if ( menu->m_cacheable )
      setting |= 0x00000100;
#endif /* __MTK_MMU__ */  
      
   interruptMask = SaveAndSetIRQMask();
   
   *(MPU_PROT0+menu->m_channel) = setting;
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   *(MPU_PROT0_END+menu->m_channel) = menu->m_addr + menu->m_range;
#endif /* MT6250 */
   
#if defined(__MTK_MMU__)
#if !defined(MT6253E_S00)&&!defined(MT6253L_S00)&&!defined(MT6252H_S00)&&!defined(MT6252_S00) 
   *MPU_CHANNEL_EN |= 1<<menu->m_channel;
#endif /* defined(MT6253E_S00)||defined(MT6253L_S00) */
#endif /* defined(__MTK_MMU__) */

   *CACHE_CON |= 0x02;
   
   RestoreIRQMask(interruptMask);
}

#pragma arm section code

#endif /* __MTK_L1CACHEABLE__ */


/*************************************************************************
* FUNCTION
*  MPUClearAllSetting
*
* DESCRIPTION
*  This function used to initialization a cache region.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  This sub-routine takes care of the range alignment, also the least
*  protectable region.
*
* RETURNS
*
*************************************************************************/

#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)

#pragma arm section code = "INTSRAM_ROCODE"

void MPUClearAllSetting(void)
{
   kal_uint32  status, index;

   *CACHE_CON &= ~(0x02);

   status = CodeCacheChannelStatus;

   for (index=0; index<MPU_CHANNEL_NUM; index++)
   {
      if ( status&0x01)
      {
         *(MPU_PROT0+index) = 0xc0;
      }
      status >>= 1;
   }
}

#pragma arm section code

#endif /* __MTK_L1CACHEABLE__ */


/*************************************************************************
* FUNCTION
*  CacheAccessHitCount
*
* DESCRIPTION
*  Return the hit count on code cache, the first 4 regions are collected on
*  group 1, while others at group 2.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/

#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)

#pragma arm section code = "INTSRAM_ROCODE"

void CacheAccessHitCount(CodeCacheHitCount *ret)
{
   ret->hitCount1 = *(volatile kal_uint64 *)(CACHE_HCNT0L);
   ret->accessCount1 = *(volatile kal_uint64 *)(CACHE_CCNT0L);
   
   ret->hitCount2 = *(volatile kal_uint64 *)(CACHE_HCNT1L);
   ret->accessCount2 = *(volatile kal_uint64 *)(CACHE_CCNT1L);
}

#pragma arm section code

#endif /* __MTK_L1CACHEABLE__ */

/*************************************************************************
* FUNCTION
*  DataCacheConfig
*
* DESCRIPTION
*  This function used to configure Data cache.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/

#if defined(__MTK_L2CACHEABLE__)

#pragma arm section code = "INTSRAM_ROCODE"

kal_bool DataCacheConfig(kal_bool enable, kal_bool reservedForMPEG4)
{
   kal_uint32 tempValue;
   kal_uint32 interruptMask;
   kal_bool   status;
   
   interruptMask = SaveAndSetIRQMask();
   
   // Bypass data cache
   *L2C_CON = DataCacheDisabled;
   // Wait for command finishing
   DataCacheWaitCommandReady();
   
   // Invalidate all cache lines
   *L2C_CON = DataCacheInvalidateAll;
   // Wait for command finishing
   DataCacheWaitCommandReady();
   
   if ( enable )
   {      
      tempValue = DataCacheEnabled;
      
      if ( reservedForMPEG4 )
      {
#if !defined(MT6238) && !defined(MT6239)
          tempValue |= DataCacheLocking2Way;
#endif /* !MT6238 */
      }

#if defined(MT6238) || defined(MT6239)
	/* SHK: Force GMC not bypass L2 cache to prevent L2 data inconsistency issue under L2 ON configuration. */
		tempValue |= DataCacheGMCNotBypassL2;
#endif	/* MT6238 || MT6239 */

			
      *L2C_CON = tempValue;
             
      // Wait for command finishing
      DataCacheWaitCommandReady();
      
      status = KAL_TRUE;
   }
   else
      status = KAL_FALSE;
      
   RestoreIRQMask(interruptMask);
  
   return status;
}

#pragma arm section code

#endif /* __MTK_L2CACHEABLE__ */

/*************************************************************************
* FUNCTION
*  SetupRemap
*
* DESCRIPTION
*  This function used to configure the Remap by Segment input
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*    start_addr
*    end_addr
*    total_size
*
* RETURNS
*
*************************************************************************/

#if defined(__MTK_MMU__)

static void SetupRemap(kal_uint32 phy_addr, kal_uint32 virt_addr, kal_uint32 total_size)
{
   kal_uint32     range, index;
   kal_uint32     channel_idx = 0;
   kal_uint32     size;

   while (total_size > 0) {

      /* try to find a max-fit size */
      for (size = MIN_MPU_CHANNEL_LEN; size <= MAX_MPU_CHANNEL_LEN; size <<= 1) {

         /* check if the start address is aligned to the size */
         if (phy_addr & (size-1)) {
               
            /* not aligned */

            /* revert to the previous size */
            size >>= 1;

            break;

         }

         /* check if size best hit */
         if (size == total_size) {
            
            break;
         }

         /* Now determine if coverage premitted or not */
         if (size > total_size) {

            ASSERT(0);
         }

         /* exit when reach max size */
         if (size == MAX_MPU_CHANNEL_LEN) {

            break;
         }

      } /* for ( size = MIN_MPU_CHANNEL_LEN ... MAX_MPU_CHANNEL_LEN ) */

	    /* Look forward the least-fit range */
	    index = MPU_SIZE_INDEX;
	    range = size;
	    size = MAX_MPU_CHANNEL_LEN;
	    while ( range<size )
	    {
	       index--;
	       size >>= 1;
	       ASSERT(size >= MIN_MPU_CHANNEL_LEN);
	    }
	    range = (RegionSize)((index)<<1);
   
      /* specify the start address of MPU setting */
      *(NCREMAP_LO0+(channel_idx<<1)) = phy_addr;
      *(NCREMAP_HI0+(channel_idx<<1)) = virt_addr|range|1;
      channel_idx++;
      if(channel_idx>=REMAP_CHANNEL_NUM)
      {
          ASSERT(0);
      }
      
      /* move start_addr to the next address */
      virt_addr += size;
      phy_addr += size;

      /* calculate the remaining size of the remaining part */
      if (size >= total_size) {

         /* no remaining part */

         total_size = 0;

      } else {

         total_size -= size;
      }
   }
}

#endif /* __MTK_MMU__ */

/*************************************************************************
* FUNCTION
*  SetupMPUbyROMSegment
*
* DESCRIPTION
*  This function used to configure the MPU by Segment input
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*    start_addr
*    end_addr
*    total_size
*
* RETURNS
*
*************************************************************************/

#if defined(__MTK_L1CACHEABLE__)

static kal_uint32 SetupMPUbyROMSegment(kal_uint32 start_addr, kal_uint32 end_addr, kal_uint32 total_size)
{
   MPUMenuType    MPUsetting;
   kal_uint32     size;
   kal_bool       retval;
   kal_uint32     mpu_end_addr = 0;

#if defined(__MTK_MMU__)

#if defined(MT6253E_S00) || defined(MT6253L_S00) || defined(MT6252H_S00) || defined(MT6252_S00)
   /* specify the attribute of MPU setting */
   MPUsetting.m_attribute = READABLE_BUT_NON_WRITEABLE;   
#else
   /* specify the attribute of MPU setting */
   MPUsetting.m_attribute = PRIV_RO_USER_RO;
#endif /* defined(MT6253E_S00) || defined(MT6253L_S00) */
   
#else
   /* specify the attribute of MPU setting */
   MPUsetting.m_attribute = READABLE_BUT_NON_WRITEABLE;   
#endif /* defined(__MTK_MMU__) */

   /* specify enable flag of MPU setting */
   MPUsetting.m_enable = 1;   

   /* check start address align to MIN_MPU_CHANNEL_LEN */
   ASSERT( (start_addr & (MIN_MPU_CHANNEL_LEN-1)) == 0x0 );

   /* check end address & start address + total_size */
   ASSERT( start_addr + total_size <= end_addr );

#if defined (MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)

   /* specify the start address of MPU setting */
   MPUsetting.m_addr = start_addr;

   /* specify the range of MPU setting */
   MPUsetting.m_range = total_size;

   /* update the end address of MPU coverage */
   mpu_end_addr = start_addr + total_size;

   /* get a MPU cahnnel */
   retval = MPUGetChannel(&MPUsetting.m_channel);

   /* ensure that a channel is available */
   ASSERT(retval == KAL_TRUE);

   /* configure the MPU */
   MPUSetting(&MPUsetting);

#else
   while (total_size > 0) {

      /* try to find a max-fit size */
      for (size = MIN_MPU_CHANNEL_LEN; size <= MAX_MPU_CHANNEL_LEN; size <<= 1) {

         /* check if the start address is aligned to the size */
         if (start_addr & (size-1)) {
               
            /* not aligned */

            /* revert to the previous size */
            size >>= 1;

            break;

         }

         /* check if size best hit */
         if (size == total_size) {
            
            break;
         }

         /* Now determine if coverage premitted or not */
         if (size > total_size) {

            /* check if the configuration of this size will overwrite the next region */
            if ((start_addr + size) > end_addr) {

               /* revert to the previous size */
               size >>= 1;

            }

            /* find the fit size and exit */
            break;
         }

         /* exit when reach max size */
         if (size == MAX_MPU_CHANNEL_LEN) {

            break;
         }

      } /* for ( size = MIN_MPU_CHANNEL_LEN ... MAX_MPU_CHANNEL_LEN ) */

      /* specify the start address of MPU setting */
      MPUsetting.m_addr = start_addr;

      /* specify the range of MPU setting */
      MPUsetting.m_range = size;

      /* update the end address of MPU coverage */
      mpu_end_addr = start_addr + size;

      /* get a MPU cahnnel */
      retval = MPUGetChannel(&MPUsetting.m_channel);

      /* ensure that a channel is available */
      ASSERT(retval == KAL_TRUE);

      /* configure the MPU */
      MPUSetting(&MPUsetting);
   
      /* move start_addr to the next address */
      start_addr += size;

      /* calculate the remaining size of the remaining part */
      if (size >= total_size) {

         /* no remaining part */

         total_size = 0;

      } else {

         total_size -= size;
      }
   }
#endif
   
   return mpu_end_addr;
}

#endif /* __MTK_L1CACHEABLE__ */

/*************************************************************************
* FUNCTION
*  SetupMPUCacheByROMSegment
*
* DESCRIPTION
*  This function used to configure the MPU and Cache by Segment input
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*    start_addr
*    end_addr
*    total_size
*
* RETURNS
*
*************************************************************************/

#if defined(__MTK_MMU__)

static kal_uint32 SetupMPUCacheByROMSegment(kal_uint32 start_addr, kal_uint32 end_addr, kal_uint32 total_size, MPU_ATTRIBUTE mpu_attr, kal_uint32 cacheable)
{
   MPUMenuType    MPUsetting;
   kal_uint32     size;
   kal_bool       retval;
   kal_uint32     mpu_end_addr = 0;

   /* specify the attribute of MPU setting */
   MPUsetting.m_attribute = mpu_attr;   
   
   /* specify the cacheability of MPU setting */
   if(PAGE_CACHEABLE==cacheable)
   MPUsetting.m_cacheable = 1;
   else
       MPUsetting.m_cacheable = 0;

   /* specify enable flag of MPU setting */
   MPUsetting.m_enable = 1;   

   /* check start address align to MIN_MPU_CHANNEL_LEN */
   ASSERT( (start_addr & (MIN_MPU_CHANNEL_LEN-1)) == 0x0 );

   /* check end address & start address + total_size */
   ASSERT( start_addr + total_size <= end_addr );
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   /* Check start address 4KB align */
   ASSERT((start_addr & CACHE_CH_SIZE_4KB_MASK)==0);
#endif /* MT6250 */

#if defined (MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)

   /* specify the start address of MPU setting */
   MPUsetting.m_addr = start_addr;

   /* specify the range of MPU setting */
   MPUsetting.m_range = total_size;

   /* update the end address of MPU coverage */
   mpu_end_addr = start_addr + total_size;

   /* Round-up 4KB for end address */
   ROUNDUP_4KB(mpu_end_addr);
   ASSERT(mpu_end_addr<=end_addr);
   MPUsetting.m_range = mpu_end_addr - MPUsetting.m_addr;
   
   /* get a MPU cahnnel */
   retval = MPUGetChannel(&MPUsetting.m_channel);

   /* ensure that a channel is available */
   ASSERT(retval == KAL_TRUE);

   /* configure the MPU */
   MPUSetting(&MPUsetting);

#else
   while (total_size > 0) {

      /* try to find a max-fit size */
      for (size = MIN_MPU_CHANNEL_LEN; size <= MAX_MPU_CHANNEL_LEN; size <<= 1) {

         /* check if the start address is aligned to the size */
         if (start_addr & (size-1)) {
               
            /* not aligned */

            /* revert to the previous size */
            size >>= 1;

            break;

         }

         /* check if size best hit */
         if (size == total_size) {
            
            break;
         }

         /* Now determine if coverage premitted or not */
         if (size > total_size) {

            /* check if the configuration of this size will overwrite the next region */
            if ((start_addr + size) > end_addr) {

               /* revert to the previous size */
               size >>= 1;

            }

            /* find the fit size and exit */
            break;
         }

         /* exit when reach max size */
         if (size == MAX_MPU_CHANNEL_LEN) {

            break;
         }

      } /* for ( size = MIN_MPU_CHANNEL_LEN ... MAX_MPU_CHANNEL_LEN ) */

      /* specify the start address of MPU setting */
      MPUsetting.m_addr = start_addr;

      /* specify the range of MPU setting */
      MPUsetting.m_range = size;

      /* update the end address of MPU coverage */
      mpu_end_addr = start_addr + size;

      /* get a MPU cahnnel */
      retval = MPUGetChannel(&MPUsetting.m_channel);

      /* ensure that a channel is available */
      ASSERT(retval == KAL_TRUE);

      /* configure the MPU */
      MPUSetting(&MPUsetting);
   
      /* move start_addr to the next address */
      start_addr += size;

      /* calculate the remaining size of the remaining part */
      if (size >= total_size) {

         /* no remaining part */

         total_size = 0;

      } else {

         total_size -= size;
      }
   }
#endif

   return mpu_end_addr;
}

#endif /* __MTK_L1CACHEABLE__ */

/*************************************************************************
* FUNCTION
*  dynamic_switch_cacheable_region
*
* DESCRIPTION
*  This function used to configure the CACHE by Segment input
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*    start_addr
*    end_addr
*    total_size
*    cacheable
*
* RETURNS
*
*************************************************************************/

#if defined(__MTK_L1CACHEABLE__)

kal_uint32 dynamic_switch_cacheable_region(kal_uint32 start_addr, kal_uint32 end_addr, kal_uint32 total_size, kal_uint32 cacheable)
{
   CacheMenuType  CACHEsetting;
   kal_uint32     size;
   kal_bool       retval;
   kal_uint32     cache_ch;
   kal_uint32     cache_ch_addr;      
   kal_uint32     cache_ch_sz;   
   kal_uint32     cacheSetting;   
   kal_uint32     interruptMask;

   if(L1CACHE_CH_CACHEABLE == cacheable) {
   /* specify enable flag of CACHE setting */
      CACHEsetting.c_enable = cacheable;      

   /* check start address align to MIN_CACHE_CHANNEL_LEN */
   ASSERT( (start_addr & (MIN_CACHE_CHANNEL_LEN-1)) == 0x0 );
   /* check end address & start address + total_size */
   ASSERT( start_addr + total_size <= end_addr );
   
   while (total_size > 0) {

      /* try to find a max-fit size */
      for (size = MIN_CACHE_CHANNEL_LEN; size <= MAX_CACHE_CHANNEL_LEN; size <<= 1) {
         /* check if the start address is aligned to the size */
         if (start_addr & (size-1)) {              
            /* not aligned */
            /* revert to the previous size */
            size >>= 1;
            break;
         }

         /* check if size best hit */
         if (size == total_size) {           
            break;
         }

         /* Now determine if coverage premitted or not */
         if (size > total_size) {
            /* check if the configuration of this size will overwrite the next region */
            if ((start_addr + size) > end_addr) {

               /* revert to the previous size */
               size >>= 1;
            }

            /* find the fit size and exit */
            break;
         }

         /* exit when reach max size */
         if (size == MAX_CACHE_CHANNEL_LEN) {
            break;
         }

      } /* for ( size = MIN_CACHE_CHANNEL_LEN ... MAX_CACHE_CHANNEL_LEN ) */

      /* specify the start address of CACHE setting */
      CACHEsetting.c_addr = start_addr;
      /* specify the range of CACHE setting */
      CACHEsetting.c_range = size;
      /* get a CACHE cahnnel */
      retval = CodeCacheGetChannel(&CACHEsetting.c_channel);

      /* ensure that a channel is available */
      ASSERT(retval == KAL_TRUE);

      /* configure the CACHE */
      CodeCacheSetting(&CACHEsetting);
      /* move start_addr to the next address */
      start_addr += size;

      /* calculate the remaining size of the remaining part */
      if (size >= total_size) {
         /* no remaining part */
         total_size = 0;
      } else {
         total_size -= size;
      }
   }
   } else if(L1CACHE_CH_NONCACHEABLE == cacheable) {
      while(total_size > 0) {
         cache_ch = query_is_l1cache_cacheable(start_addr, total_size, 0);
         

         /*
          * NoteXXX: kal_adm_free() may input a memory region which is not fully cacheable.
          *          This will result in no cache channel is found for the noncacheable
          *          region at the tail of the input memory region.
          *          Bypass it for temporary solution.
          */
#if 0
/* under construction !*/
/* under construction !*/
#endif
         if (cache_ch == -1) {
            break;
         }
         
         interruptMask = SaveAndSetIRQMask();  
         cacheSetting = *(MPU_CACHE0+cache_ch);   
         RestoreIRQMask(interruptMask);

         cache_ch_addr = cacheSetting & L1CACHE_CH_ADDR_MASK;
         cache_ch_sz = (1 << CACHE_CHANNEL_OFFSET_TABLE[((cacheSetting & L1CACHE_CH_SIZE_MASK)>>1)]);
		 
         if((cache_ch_addr == start_addr) && 
	     ((cache_ch_addr + cache_ch_sz >= start_addr+total_size) ||
            (cache_ch_addr + cache_ch_sz > start_addr))) {       
            
            cacheSetting &= (~L1CACHE_CH_ENABLE_MASK);
            cacheSetting &= (~L1CACHE_CH_CACHEABLE_MASK);
         
            interruptMask = SaveAndSetIRQMask();  		 
            *(MPU_CACHE0+cache_ch) = cacheSetting;
         
            CodeCacheChannelStatus &= (~(0x01 << cache_ch));		 
            RestoreIRQMask(interruptMask);

		total_size -= cache_ch_sz;
		start_addr += cache_ch_sz; 
         } else {
             break;
         }
      }	  	  
   } else {
      ASSERT(0);
   }
   
   return 0;
}

#endif /* __MTK_L1CACHEABLE__ */

/*************************************************************************
* FUNCTION
*  free_all_channels
*
* DESCRIPTION
*  This function used to free all channels in a spesific region.
*  [NOTE] This API is for SW video used only!
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*    start_addr
*    end_addr
*
* RETURNS
*
*************************************************************************/

#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)

kal_uint32 free_all_channels(kal_uint32 start_addr, kal_uint32 end_addr)
{
    kal_uint32 interruptMask;	
    kal_uint32 cacheSetting;
    kal_uint32 cache_ch_addr;
    kal_uint32 cache_ch_sz;
    kal_uint16 cache_ch;

    for(cache_ch = 0; cache_ch < CACHE_CHANNEL_NUM; cache_ch++) {
        interruptMask = SaveAndSetIRQMask();  
        cacheSetting = *(MPU_CACHE0 + cache_ch);
        RestoreIRQMask(interruptMask);

        /* check if the channel is being used */
        if((L1CACHE_CH_ENABLE == (cacheSetting & L1CACHE_CH_ENABLE_MASK)) && 
	    (L1CACHE_CH_CACHEABLE == (cacheSetting & L1CACHE_CH_CACHEABLE_MASK))) {
      
            cache_ch_addr = cacheSetting & L1CACHE_CH_ADDR_MASK;
            cache_ch_sz = (1 << CACHE_CHANNEL_OFFSET_TABLE[((cacheSetting & L1CACHE_CH_SIZE_MASK)>>1)]);

            /* check if the channel is involvoed in the buffer */
            if(cache_ch_addr < end_addr && (cache_ch_addr + cache_ch_sz) > start_addr) {
                /* release the cache channel */
                cacheSetting &= (~L1CACHE_CH_ENABLE_MASK);
                cacheSetting &= (~L1CACHE_CH_CACHEABLE_MASK);
			 
                interruptMask = SaveAndSetIRQMask();  		 
                *(MPU_CACHE0 + cache_ch) = cacheSetting;
         
                CodeCacheChannelStatus &= (~(0x01 << cache_ch));		 
                RestoreIRQMask(interruptMask);			 
            }
        }
    }

    return 0;
}

#endif /* __MTK_L1CACHEABLE__ */

/*************************************************************************
* FUNCTION
*  SetupCACHEbyROMSegment
*
* DESCRIPTION
*  This function used to configure the CACHE by Segment input
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*    start_addr
*    end_addr
*    total_size
*
* RETURNS
*
*************************************************************************/

#if defined(__MTK_L1CACHEABLE__)

static void SetupCACHEbyROMSegment(kal_uint32 start_addr, kal_uint32 end_addr, kal_uint32 total_size)
{
   dynamic_switch_cacheable_region(start_addr, end_addr, total_size, L1CACHE_CH_CACHEABLE);  
}

#endif /* __MTK_L1CACHEABLE__ */

/*************************************************************************
* FUNCTION
*  SetupMPUonTCM
*
* DESCRIPTION
*  This function used to configure the MPU on TCM
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__)

#if defined(__MTK_L1CACHEABLE__)

static void SetupMPUonTCM(void)
{
   MPUMenuType    MPUsetting;
   kal_bool retval;

   /* specify the start address */
   MPUsetting.m_addr = custom_get_INTSRAMCODE_Base();

   /* specify the total size */
   MPUsetting.m_range = custom_get_INTSRAMCODE_End() - MPUsetting.m_addr;

#if defined(__MTK_MMU__)
   /* specify the cacheability of MPU setting */
   MPUsetting.m_cacheable = 0;
#if defined(MT6253E_S00) || defined(MT6253L_S00) || defined(MT6252H_S00) || defined(MT6252_S00)
   /* specify the attribute of MPU setting */
   MPUsetting.m_attribute = READABLE_WRITEABLE;
#else
   /* specify the attribute of MPU setting */
   MPUsetting.m_attribute = PRIV_RW_USER_RO;
#endif 
#else
   /* specify the attribute of MPU setting */
   MPUsetting.m_attribute = READABLE_BUT_NON_WRITEABLE;
#endif /* __MTK_MMU__ */

   /* specify enable flag of MPU setting */
   MPUsetting.m_enable = 1;

   /* get a MPU cahnnel */
   retval = MPUGetChannel(&MPUsetting.m_channel);

   /* ensure that a channel is available */
   ASSERT(retval == KAL_TRUE);

   /* configure the MPU */
   MPUSetting(&MPUsetting);
}

#endif /* __MTK_L1CACHEABLE__ */

#endif /* !__FUE__ && !__UBL__ */

/*************************************************************************
* FUNCTION
*  SetupMPUCacheByFeature
*
* DESCRIPTION
*  This function used to configure the CACHE by Segment input
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__)

#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)

static void SetupMPUCacheByFeature(void)
{
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

   /*
    * Configure RAM code for single bank support as READABLE_BUT_NON_WRITEABLE.
    */

#if defined(__MTK_MMU__)

#if defined(MT6253E_S00)||defined(MT6253L_S00) || defined(MT6252H_S00) || defined(MT6252_S00)
   SetupMPUCacheByROMSegment(custom_get_SINGLEBANKCODE_and_VectorTable_Base(), custom_get_SINGLEBANKCODE_End(), custom_get_SINGLEBANKCODE_End()-custom_get_SINGLEBANKCODE_and_VectorTable_Base(), READABLE_BUT_NON_WRITEABLE, PAGE_CACHEABLE);
#elif defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) /* MT6253E_S00 || MT6253L_S00 || MT6252H_S00 || MT6252_S00 */
   {
#if !defined(__NORFLASH_NON_XIP_SUPPORT__)
      kal_uint32 endAddress = custom_get_SINGLEBANKCODE_End();
#if defined(__ALICE_SUPPORT__)
      endAddress = custom_get_EXTSRAM_ALICE_End();
#endif /* __ALICE_SUPPORT__ */
      SetupMPUCacheByROMSegment(0, endAddress, endAddress, PRIV_RO_USER_RO, PAGE_CACHEABLE);
#endif /* __NORFLASH_NON_XIP_SUPPORT__ */
   }
#else /* MT6250 */
   SetupMPUCacheByROMSegment(custom_get_SINGLEBANKCODE_and_VectorTable_Base(), custom_get_SINGLEBANKCODE_End(), custom_get_SINGLEBANKCODE_End()-custom_get_SINGLEBANKCODE_and_VectorTable_Base(), PRIV_RO_USER_RO, PAGE_CACHEABLE);
#endif /* MT6253E_S00 || MT6253L_S00 */

#else

#if defined(MT6251)
   SetupMPUbyROMSegment(custom_get_SINGLEBANKCODE_and_VectorTable_Base(), custom_get_SINGLEBANKCODE_End(), custom_get_SINGLEBANKCODE_End()-custom_get_SINGLEBANKCODE_and_VectorTable_Base());
   SetupMPUbyROMSegment(custom_get_SINGLEBANKCODE_and_VectorTable_Base()&0x0FFFFFFF, custom_get_SINGLEBANKCODE_End()&0x0FFFFFFF, (custom_get_SINGLEBANKCODE_End()&0x0FFFFFFF)-(custom_get_SINGLEBANKCODE_and_VectorTable_Base()&0x0FFFFFFF));
#else
   /* The cache region starts from 0 to save the cache channel.
      If start address of this setting is changed, need to check if scatter gen modification is required. */
   SetupMPUbyROMSegment(custom_get_SINGLEBANKCODE_and_VectorTable_Base(), custom_get_SINGLEBANKCODE_End(), custom_get_SINGLEBANKCODE_End()-custom_get_SINGLEBANKCODE_and_VectorTable_Base());
#endif /* MT6251 */

#endif /* __MTK_MMU__ */

#if !defined(MT6251) && !defined(MT6253E) && !defined(MT6253L)  && !defined(MT6252) && !defined(MT6252H) && !defined(__MTK_MMU__) /* SINGLE_BANK_CODE is placed in the internal RAM */
   /*
    * SINGLE_BANK_CODE Code Cache configuration.
    */

   /* The cache region starts from 0 to save the cache channel.
      If start address of this setting is changed, need to check if scatter gen modification is required. */
   SetupCACHEbyROMSegment(custom_get_SINGLEBANKCODE_and_VectorTable_Base(), custom_get_SINGLEBANKCODE_End(), custom_get_SINGLEBANKCODE_End());
   
#endif /* !MT6251 && !MT6253E && !MT6253L */

#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

}

#endif /* __MTK_L1CACHEABLE__ */

#endif /* !__FUE__ && !__UBL__ */

/*************************************************************************
* FUNCTION
*  clean_l1cache
*
* DESCRIPTION
*  This function clean the buffer's data in L1Cache.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr     -   address of the buffer
*  len      -   length of the buffer (in bytes)
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/

#if (!defined(__FUE__) && !defined(__UBL__)) || defined(__MTK_MMU__)

#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)

kal_int32 clean_l1cache(kal_uint32 addr, kal_uint32 len)
{
#if !defined(__ARM9_MMU__)

   kal_uint32 i = 0, j;	

   /* NoteXXX: Each cache line in MTK L1 Cache is 32B. Every invalidate operation must aligned in a 32B address. */
   if ((addr & CPU_CACHE_LINE_SIZE_MASK) ||
   	   (len & CPU_CACHE_LINE_SIZE_MASK))
   {
      EXT_ASSERT(0, addr, len, 0);
   } else {
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
      if(len >= CPU_CACHE_SIZE)
      {
          for(j=0;j<CPU_CACHE_WAY_COUNT;j++)
          {
              for (i = 0; i < CPU_CACHE_LINE_NUMBER_PER_WAY; i++)
              {
                  MTKL1CACHE_CleanCacheLines_by_SetWay(i, j);
              }
          }
          return 0;
      } 
#endif /* MT6250 */
      for(i = 0; i < len/CPU_CACHE_LINE_SIZE; i++) {
         CleanCodeCacheByAlignedAddr(addr);
         addr += CPU_CACHE_LINE_SIZE;
      }
   }

   return 0;

#else   /* !__ARM9_MMU__ */

   return -1;

#endif  /* !__ARM9_MMU__ */
}

#endif /* __MTK_L1CACHEABLE__ */

#endif /* !__FUE__ && !__UBL__ */

/*************************************************************************
* FUNCTION
*  invalidate_l1cache
*
* DESCRIPTION
*  This function invalidates the buffer's data in L1Cache.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr     -   address of the buffer
*  len      -   length of the buffer (in bytes)
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__) || defined(__MTK_MMU__)

#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)

kal_int32 invalidate_l1cache(kal_uint32 addr, kal_uint32 len)
{
#if !defined(__ARM9_MMU__) && !defined(__ARM11_MMU__)

   kal_uint32 i = 0;	

   /* NoteXXX: Each cache line in MTK L1 Cache is 32B. Every invalidate operation must aligned in a 32B address. */
   if ((addr & CPU_CACHE_LINE_SIZE_MASK) ||
   	   (len & CPU_CACHE_LINE_SIZE_MASK))
   {
      EXT_ASSERT(0, addr, len, 0);
   } else {
#if defined(MT6225) || defined(MT6253)
      /* faster for MT6253 & MT6225 if the len is larger than 8K */
      if(len >= 8 * 1024) {
         MTKL1CACHE_InvalidAllCacheLines();
      }
#endif /* MT6225 || MT6253 */
   	
#if defined(MT6250)
      // FIXME:
      // We need to profile the parameter of CleanAndInvalidate for new chips
      // then we can safely apply the compile option
      if(len >= CPU_INVALIDATE_THRESHOLD)
      {
          // If invalidate size over CPU_INVALIDATE_THRESHOLD
          // We do clean_and_invalidate. with this size it should be operate as clean_and_invalidate all
          clean_and_invalidate_l1cache(addr, len);
          return 0;
      }
#endif /* MT6250 */
      for(i = 0; i < len/CPU_CACHE_LINE_SIZE; i++) {
         InvalidCodeCacheByAlignedAddr(addr);
         addr += CPU_CACHE_LINE_SIZE;
      }
   }

   return 0;

#else   /* !__ARM9_MMU__ && !__ARM11_MMU__*/

   return -1;

#endif  /* !__ARM9_MMU__ && !__ARM11_MMU__*/
}

#endif /* __MTK_L1CACHEABLE__ */

#endif /* !__FUE__ && !__UBL__ */

/*************************************************************************
* FUNCTION
*  invalidate_l1cache
*
* DESCRIPTION
*  This function clean and invalidates the buffer's data in L1Cache.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr     -   address of the buffer
*  len      -   length of the buffer (in bytes)
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__) || defined(__MTK_MMU__)

#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)

kal_int32 clean_and_invalidate_l1cache(kal_uint32 addr, kal_uint32 len)
{
#if !defined(__ARM9_MMU__) && !defined(__ARM11_MMU__)
    kal_uint32 i = 0, j=0;
    kal_uint32 lock_counter=0;
    kal_uint32 irq_mask;

    /* NoteXXX: Each cache line in MTK L1 Cache is 32B. Every invalidate operation must aligned in a 32B address. */
    if ((addr & CPU_CACHE_LINE_SIZE_MASK) ||
        (len & CPU_CACHE_LINE_SIZE_MASK))
    {
        EXT_ASSERT(0, addr, len, 0);
    }
    else
    {
#if defined(MT6225) || defined(MT6253)
        /* faster for MT6253 & MT6225 if the len is larger than 8K */
        if (len >= 8 * 1024)
        {
            MTKL1CACHE_InvalidAllCacheLines();
        }
#endif /* MT6225 || MT6253 */

#if defined(MT6250)
        // FIXME:
        // We need to profile the parameter of CleanAndInvalidate for new chips
        // then we can safely apply the compile option
        if(len >= CPU_CACHE_SIZE)
        {
            // Clean and invalidat size larger than cache size,
            // do clean and invalidate all by set way
            for(j=0;j<CPU_CACHE_WAY_COUNT;j++)
            {
                irq_mask=SaveAndSetIRQMask();
                for (i = 0, lock_counter=0; i < CPU_CACHE_LINE_NUMBER_PER_WAY; i++, lock_counter++)
                {
                    if(lock_counter==CPU_CACHE_OP_LOCK_COUNTER)
                    {
                        RestoreIRQMask(irq_mask);
                        lock_counter=0;
                        irq_mask=SaveAndSetIRQMask();
                    }
                    MTKL1CACHE_CleanCacheLines_by_SetWay(i, j);
                    MTKL1CACHE_InvalidateCacheLines_by_SetWay(i, j);
                }
                RestoreIRQMask(irq_mask);
            } 
            return 0;
        } 
#endif /* MT6250 */
        // otherwise clean and invalidate by lines
        // not that if we operate by line, no need to lock IRQ
        for (i = 0; i < len / CPU_CACHE_LINE_SIZE; i++)
        {
            CleanCodeCacheByAlignedAddr(addr);
            InvalidCodeCacheByAlignedAddr(addr);
            addr += CPU_CACHE_LINE_SIZE;
        }              
    }

    return 0;

#else   /* !__ARM9_MMU__ && !__ARM11_MMU__*/
    return -1;
#endif  /* !__ARM9_MMU__ && !__ARM11_MMU__*/
}

#endif /* __MTK_L1CACHEABLE__ */

#endif /* !__FUE__ && !__UBL__ */

/*************************************************************************
* FUNCTION
*  invalidate_wt_cache
*
* DESCRIPTION
*  This function invalidates the buffer's data in L1Cache.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr     -   address of the buffer
*  len      -   length of the buffer (in bytes)
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__)

#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)

kal_int32 invalidate_wt_cache(kal_uint32 addr, kal_uint32 len)
{
#if defined(__ARM9_MMU__) || !defined(__WRITE_THROUGH_CACHEABLE__)
   return -1;

#else /* __ARM9_MMU__ || !__WRITE_THROUGH_CACHEABLE__ */
/* under construction !*/
#if defined(MT6253) && defined(__WRITE_THROUGH_CACHEABLE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* MT6253 */
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
#endif /* __ARM9_MMU__ || !__WRITE_THROUGH_CACHEABLE__ */

}

#endif /* __MTK_L1CACHEABLE__ */

#endif /* !__FUE__ && !__UBL__ */


/*************************************************************************
* FUNCTION
*  query_is_l1cache_cacheable
*
* DESCRIPTION
*  This function return the found channel if specified region is cacheable.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr     -   address of the buffer
*  len      -   length of the buffer (in bytes)
*  query_ram   - if only query ram part. 
*
* RETURNS
*  i for successly found channel; -1 for not found.
*
*************************************************************************/
   
#if defined(__MTK_L1CACHEABLE__)

kal_int32 query_is_l1cache_cacheable(kal_uint32 addr, kal_uint32 len, kal_uint32 query_ram)
   {
#if !defined(__ARM9_MMU__) && !defined(__ARM11_MMU__)
   kal_uint32 interruptMask;	
   kal_uint32 cacheSetting;
   kal_uint32 cache_ch_addr;
   kal_uint32 cache_ch_sz;
   kal_uint16 i;	   
#if defined(__WRITE_THROUGH_CACHEABLE__) && !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
/* under construction !*/
#endif /* __WRITE_THROUGH_CACHEABLE__ && !__FUE__ && !__UBL__ */
   
   if(query_ram) {
      /* SHK: If the addr/len lies at CODE/RO region, return false. */	 	
#if !defined(__FUE__) && !defined(__UBL__)
#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
      if((addr >= custom_get_1st_ROM_ROMBase() && ((addr+len) <= (custom_get_1st_ROM_ROMBase()+custom_get_1st_ROM_ROMLength()))) || 
			(addr >= custom_get_2nd_ROM_ROMBase() && ((addr+len) <= (custom_get_2nd_ROM_ROMBase()+custom_get_2nd_ROM_ROMLength())))) {
         return -1;
      }
#else /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */
      if(addr >= custom_get_1st_ROM_ROMBase() && ((addr+len) <= (custom_get_1st_ROM_ROMBase()+custom_get_1st_ROM_ROMLength()))) {
         return -1;
      }
#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */

#else /* !__FUE__ && !__UBL__ */
      return -1;
#endif /* !__FUE__ && !_UBL__ */
   }
   
#if defined(__WRITE_THROUGH_CACHEABLE__) && !defined(__FUE__) && !defined(__UBL__)
/* under construction !*/
/* under construction !*/
#if defined(MT6253)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* MT6253 */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __WRITE_THROUGH_CACHEABLE__ && !__FUE__ && !__UBL__ */
   
   for(i = 0; i < CACHE_CHANNEL_NUM; i++) {
      interruptMask = SaveAndSetIRQMask();  
      cacheSetting = *(MPU_CACHE0+i);   
      RestoreIRQMask(interruptMask);

      if((L1CACHE_CH_ENABLE == (cacheSetting & L1CACHE_CH_ENABLE_MASK)) && 
	  (L1CACHE_CH_CACHEABLE == (cacheSetting & L1CACHE_CH_CACHEABLE_MASK))) {
      
         cache_ch_addr = cacheSetting & L1CACHE_CH_ADDR_MASK;
         cache_ch_sz = (1 << CACHE_CHANNEL_OFFSET_TABLE[((cacheSetting & L1CACHE_CH_SIZE_MASK)>>1)]);
         
         if((cache_ch_addr == addr) && 
	     ((cache_ch_addr + cache_ch_sz >= addr+len) ||
            (cache_ch_addr + cache_ch_sz > addr))) {	  
             return i;
          }
         }
      }
      
         return -1;

#else   /* !__ARM9_MMU__ && !__ARM11_MMU__ */

   return -1;

#endif  /* !__ARM9_MMU__ && !__ARM11_MMU__ */
}

#endif /* __MTK_L1CACHEABLE__ */

/*************************************************************************
* FUNCTION
*  query_l1cache_free_ch_num
*
* DESCRIPTION
*  This function return the num of found channels.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*  i for successly total found channels; 0 for not found. -1 on no L1 cache platform.
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__)

#if defined(__MTK_L1CACHEABLE__)

kal_int32 query_l1cache_free_ch_num(void)
  {
#if !defined(__ARM9_MMU__) && !defined(__ARM11_MMU__)
   kal_uint32 interruptMask;	
   kal_uint32 cacheSetting;
   kal_uint32 free_cache_ch_num = 0;
   kal_uint16 i;	   

   for(i = 0; i < CACHE_CHANNEL_NUM; i++) {
      interruptMask = SaveAndSetIRQMask();  
      cacheSetting = *(MPU_CACHE0+i);   
      RestoreIRQMask(interruptMask);
    
      if(L1CACHE_CH_ENABLE != (cacheSetting & L1CACHE_CH_ENABLE_MASK)) {
	   free_cache_ch_num++;
    }
  }
  
   return free_cache_ch_num;
  
#else   /* !__ARM9_MMU__ && !__ARM11_MMU__ */
  
   return -1;

#endif  /* !__ARM9_MMU__ && !__ARM11_MMU__ */
}

#endif /* __MTK_L1CACHEABLE__ */

#endif /* !__FUE__ && !__UBL__ */

/*************************************************************************
* FUNCTION
*  is_predef_dyna_c_region
*
* DESCRIPTION
*  This is used to determine whether the input region is a predefined dynamic switchable buffer.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  0
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__)

#if defined(__ARM9_MMU__) || defined(__DYNAMIC_SWITCH_CACHEABILITY__)

kal_uint32 is_predef_dyna_c_region(kal_uint32 vaddr, kal_uint32 len)
{
   kal_uint32 ret = 0;
   
   EXTSRAM_REGION_INFO_T *regionp;	
   kal_uint32 buf_addr;
   kal_int32 buf_len;
   kal_uint32 i; 
   kal_uint32 buf_start;

#if defined(__KAL_VM__) && !defined(__FUE__) && !defined(__UBL__)
   if (is_flmm_va(vaddr)) {
      return 1;
   }
#endif /* __KAL_VM__ && !__FUE__ && !__UBL__ */

   for(i = 0; i < 2; i++) {
      if(i%2==0) {
          vaddr = MAP2CREGPA(vaddr);         
      } else {
         vaddr = MAP2CREGVA(vaddr);
      }

      custom_query_dynamic_cached_extsram_default_nc_region(&regionp);
     
      while (regionp->addr != 0 || regionp->len != 0) {      
         if (regionp->len == 0)  { 
            regionp++;
            continue;
         }   
         buf_start = regionp->addr;
         buf_addr = buf_start + regionp->len;
         ROUNDUP_4KB(buf_addr);
         ROUNDDOWN_4KB(buf_start);
         buf_len = buf_addr - buf_start;

         if((vaddr >= buf_start) &&
	      (vaddr <= buf_start+buf_len)) {   
            ret = 1;
            return ret;			
         }   

         regionp++;	  
      }

      custom_query_dynamic_cached_extsram_default_c_region(&regionp);

      while (regionp->addr != 0 || regionp->len != 0) {      
         if (regionp->len == 0)  { 
            regionp++;
            continue;
         }   
         buf_start = regionp->addr;
         buf_addr = buf_start + regionp->len;
         ROUNDUP_4KB(buf_addr);
         ROUNDDOWN_4KB(buf_start);
         buf_len = buf_addr - buf_start;

         if((vaddr >= buf_start) &&
	      (vaddr <= buf_start+buf_len)) {   
            ret = 1;
            return ret;			
         }   

         regionp++;	  
      }			
   }

#if !defined(__MTK_MMU__)
   if(INT_QueryIsSysRAM(vaddr)) {
      ret = 1;
      return ret;			      
   }
#endif /* __MTK_MMU__ */
   
   return ret;   
}

#endif  /* __ARM9_MMU__ || __DYNAMIC_SWITCH_CACHEABILITY__ */

#endif /* !__FUE__ && !__UBL__ */

/*************************************************************************
* FUNCTION
*  dynamic_switch_cacheable_region
*
* DESCRIPTION
*  This is used to dynamically change a region's cacheable/noncacheable attribute.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  vaddr
*  len
*  cacheable
*
* RETURNS
*  0 for successfully switch.
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__)

#if defined(__ARM9_MMU__) || defined(__DYNAMIC_SWITCH_CACHEABILITY__)

kal_uint32 dynamic_switch_cacheable_region(void *vaddr, kal_uint32 len, kal_uint32 cacheable)
{
   kal_uint32 c;
   kal_uint32 ret = 0;   	
   kal_uint32 is_sysram = 0;   
   kal_uint32 op_addr;

   op_addr = (kal_uint32)(*(kal_uint32 *)vaddr);
#if !defined(__MTK_MMU__)
   is_sysram = INT_QueryIsSysRAM(op_addr);
#endif /* __MTK_MMU__ */
   
   if( !is_predef_dyna_c_region(op_addr, len) || 
   	  !IS_CACHE_LINE_SIZE_ALIGNED(*(kal_uint32 *)vaddr) ||
   	!IS_CACHE_LINE_SIZE_ALIGNED(len)) {
      ASSERT(0);   	
   }

   is_sysram == 0? (c = INT_QueryIsCachedRAM(op_addr, len)): (c = INT_QueryIsCachedSysRAM(op_addr, len));

   if(c == cacheable) {
       return ret;
   }

#if defined(__KAL_VM__) && !defined(__FUE__) && !defined(__UBL__)
       if(is_flmm_va(op_addr)||is_flmm_pa(op_addr))
       {
   	       return flmm_dynamic_switch_cacheable_region(vaddr, len, cacheable);
       }
#endif /* __KAL_VM__ && !__FUE__ && !__UBL__ */

#if !defined(__MTK_MMU__)
   if(PAGE_CACHEABLE == cacheable) {
      is_sysram == 0? (*(kal_uint32*)vaddr = MAP2CREGVA(*(kal_uint32*)vaddr)): (*(kal_uint32*)vaddr = MAP2CREGVA_SYS(*(kal_uint32*)vaddr));
      is_sysram == 0? (op_addr = MAP2CREGVA(op_addr)): (op_addr = MAP2CREGVA_SYS(op_addr));
      invalidate_dcache(op_addr, len);
      cp15_drain_write_buffer();
   } else if(PAGE_NO_CACHE == cacheable) {
      clean_dcache(op_addr, len);   
      is_sysram == 0? (*(kal_uint32*)vaddr = MAP2CREGPA(*(kal_uint32*)vaddr)): (*(kal_uint32*)vaddr = MAP2CREGPA_SYS(*(kal_uint32*)vaddr));
      cp15_drain_write_buffer();
   } else {
       ASSERT(0);
   }
#else
   if(PAGE_CACHEABLE == cacheable) {
      if(is_sysram == 0)
      {
         *(kal_uint32*)vaddr = MAP2CREGVA(*(kal_uint32*)vaddr);
         op_addr = MAP2CREGVA(op_addr);
      }
      else
      {
         ASSERT(0);
      }
      invalidate_dcache(op_addr, len);
			
   } else if(PAGE_NO_CACHE == cacheable) {
      clean_dcache(op_addr, len);   
      if(is_sysram == 0)
      {
          *(kal_uint32*)vaddr = MAP2CREGPA(*(kal_uint32*)vaddr);
			}
			else
			{
			    ASSERT(0);
			}
   } else {
       ASSERT(0);
   }
#endif /* __MTK_MMU__ */

   return ret;
}

#endif  /* __ARM9_MMU__ || __DYNAMIC_SWITCH_CACHEABILITY__ */

#endif /* !__FUE__ && !__UBL__ */


/*************************************************************************
* FUNCTION
*  CachePreInit
*
* DESCRIPTION
*  This function used to pre-configure the overall cache setting to use I-cache for speeding up the following ops.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__)

void CachePreInit(void)
{
#if defined(__MTK_MMU__)

   /* setup MTK remap to map 0xFxxxxxxx to physical memory */  
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   SetupRemap(0x0, MAP2CREGVA(0x0), EMI_EXTSRAM_SIZE);
#else
   SetupRemap(RAM_BASE_ADDR, MAP2CREGVA(RAM_BASE_ADDR), EMI_EXTSRAM_SIZE);
#endif

#if !defined(MT6253E_S00)&&!defined(MT6253L_S00)&&!defined(MT6252H_S00)&&!defined(MT6252_S00) 
   *MPU_PROT0 = 0x100 | ( custom_get_1st_ROM_ROMBase()& 0xF8000000) ; /* 2MB from 0x0 */
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   *MPU_PROT0_END = ((custom_get_1st_ROM_ROMBase()& 0xF8000000) + SIZE_4KB)&(~CACHE_CH_SIZE_4KB_MASK);
#endif
   *MPU_CHANNEL_EN |= 1;
#endif /* !defined(MT6253E_S00)&&!defined(MT6253L_S00)&&!defined(MT6252H_S00)&&!defined(MT6252_S00) */

#endif /* __MTK_MMU__ */

#if defined(__MTK_L1CACHEABLE__)

#if !defined(TK6516) && !defined(MT6516)

#if defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
    *(MPU_CACHE0) = 0x117 | ( custom_get_1st_ROM_ROMBase()& 0xF8000000) ; /* 2MB from 0x0 */
#else
    *(MPU_CACHE0) = 0x55 | ( custom_get_1st_ROM_ROMBase()& 0xF8000000) ; /* 2MB from 0x0 */
#endif /* MT6253E || MT6253L */

   /* enable code cache */
   *CACHE_CON &= ~(0x0d);

   /* Invalid all cache line */
   *CACHE_OP = 0x03;

   /* Reset counters */
   *CACHE_HCNT0L = 0x00;
   *CACHE_HCNT0U = 0x00;
   *CACHE_CCNT0L = 0x00;
   *CACHE_CCNT0U = 0x00;
   *CACHE_HCNT1L = 0x00;
   *CACHE_HCNT1U = 0x00;
   *CACHE_CCNT1L = 0x00;
   *CACHE_CCNT1U = 0x00;

#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6268H)
   
   *CACHE_CON |= (CACHE_4WAY | 0x0d);

#elif defined(MT6225) || defined(MT6253T) || defined(MT6253)    /* MT6228 || MT6229 || MT6230 || MT6268T || MT6268H */

   *CACHE_CON |= (CACHE_2WAY | 0x0d);

#elif defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)

   *CACHE_CON |= (CACHE_4WAY | 0x800d);

#elif defined(MT6251)

#if defined(MT6251_S00)
      *CACHE_CON |= (CACHE_2WAY | 0xd80d); // MDRF_EN=0b'1, MDRF_TCM=0b'1, WRAP8=0b'1, RANDOM_CNT=0b'10
#else
      *CACHE_CON |= (CACHE_2WAY | 0xf80d); // MDRF_EN=0b'1, LF_IDLE_DIS=0b'1, DRF_TCM=0b'1, WRAP8=0b'1, RANDOM_CNT=0b'10
#endif /* MT6251_S00 */
   
#endif   /* MT6228 || MT6229 || MT6230 || MT6268T || MT6268H */

#endif  /* !TK6516 && !MT6516*/

#endif   /* __MTK_L1CACHEABLE__ */

    return;

}

#endif /* !__FUE__ && !__UBL__ */


/*************************************************************************
* FUNCTION
*  CustomizedCacheDeInit
*
* DESCRIPTION
*  This function used to clear the customized cache setting. Note that this function will not take care of MMU part. 
*  For MMU customization, pease use customized_mmu_deinit().
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/

#pragma arm section code = "INTSRAM_ROCODE"

void CustomizedCacheDeInit(void)
{
#if defined(__MTK_MMU__)
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   MTKL1CACHE_InvalidAllCacheLines();
   MPUClearAllSetting();
#endif // MT6250
#endif // __MTK_MMU__
#if defined(__MTK_L1CACHEABLE__)
   /* Inv code cache */
   MTKL1CACHE_InvalidAllCacheLines();

   /* disable code cache. */
   CodeCacheClearAllSetting();

   /* disable code mpu. */
   MPUClearAllSetting();
#endif   /* __MTK_L1CACHEABLE__ */


#if defined(__MTK_L2CACHEABLE__)

#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6268H)

      /* flush/Inv data cache */
      MTKL2CACHE_CleanAndInvalidateAllCacheLines();

      /* drain data cache write buffer */
      MTKL2CACHE_DrainWriteBuffer();
	 
      /* disable data cache */
      DataCacheConfig(KAL_FALSE, KAL_FALSE);

#elif defined(MT6238) || defined(MT6239)  /* MT6228 || MT6229 || MT6230 || MT6268T || MT6268H */

   if((*EMI_CONN & DRAM_TYPE_MASK) != DRAM_TYPE_DDR)
   {
      /* flush/Inv data cache */
      MTKL2CACHE_CleanAndInvalidateAllCacheLines();

      /* drain data cache write buffer */
      MTKL2CACHE_DrainWriteBuffer();
	 
      /* disable data cache */
      DataCacheConfig(KAL_FALSE, KAL_FALSE);
   }

#endif  /* MT6228 || MT6229 || MT6230 || MT6268T || MT6268H */

#endif   /* __MTK_L2CACHEABLE__ */
}

#pragma arm section code

/*************************************************************************
* FUNCTION
*  CustomizedCacheInit
*
* DESCRIPTION
*  This function used to configure the customized cache setting. Note that this function will not take care of MMU part. 
*  For MMU customization, pease use customized_mmu_init().
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/

void CustomizedCacheInit(kal_uint32 rom_start_addr, kal_uint32 rom_end_addr,  kal_uint32 rom_len)
{
/*********************************
 *
 * MTK MMU
 *
 ********************************/
#if defined(__MTK_MMU__)
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    /* Setup code cache channel */
    SetupMPUCacheByROMSegment(rom_start_addr, rom_end_addr, rom_len, PRIV_RO_USER_RO, PAGE_CACHEABLE);
    
    /* Enable Cache */
    CodeCacheConfig(CACHE_2WAY, KAL_TRUE);
#endif // MT6250 
#endif // __MTK_MMU__

/*********************************
  *
  * MTK L1 Cache Config
  *
  ********************************/
  
#if defined(__MTK_L1CACHEABLE__)
	 
   /*
    * MPU configuration.
    * Configure the region of code and RO as READABLE_BUT_NON_WRITEABLE.
    */
   SetupMPUbyROMSegment(rom_start_addr, rom_end_addr, rom_len);
   
   /*
    * Configure code and RO in the TCM as READABLE_BUT_NON_WRITEABLE.
    */
   SetupMPUonTCM();

   /*
    * Cache configuration.
    * Configure the region of code and RO as code-cacheable.
    */
   SetupCACHEbyROMSegment(rom_start_addr, rom_end_addr, rom_len);

   SetupMPUCacheByFeature();


#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(TK6516) || defined(MT6516) || defined(MT6268H)

   /* enable code cache */
   CodeCacheConfig(CACHE_4WAY, KAL_TRUE);

#elif defined(MT6225) || defined(MT6253T) || defined(MT6253) || defined(MT6251)     /* MT6228 || MT6229 || MT6230 || MT6268T || TK6516 || MT6516 || MT6268H */

   /* enable code cache */
   CodeCacheConfig(CACHE_2WAY, KAL_TRUE);

#endif  /* MT6228 || MT6229 || MT6230 || MT6268T || TK6516 || MT6516 || MT6268H */

#endif   /* __MTK_L1CACHEABLE__ */


/*********************************
  *
  * MTK L2 Cache Config
  *
  ********************************/

#if defined(__MTK_L2CACHEABLE__)

#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6268H)

   /* enable data cache */
   DataCacheConfig(KAL_TRUE, KAL_FALSE);

#elif defined(MT6238) || defined(MT6239)  /* MT6228 || MT6229 || MT6230 || MT6268T || MT6268H */

   if((*EMI_CONN & DRAM_TYPE_MASK) != DRAM_TYPE_DDR)
   {
      /* enable L2 data cache while do not reserve 2 ways for MPEG4. */
      DataCacheConfig(KAL_TRUE, KAL_FALSE);
   }

#endif  /* MT6228 || MT6229 || MT6230 || MT6268T || MT6268H */

#endif   /* __MTK_L2CACHEABLE__ */

}


/*************************************************************************
* FUNCTION
*  CacheInit
*
* DESCRIPTION
*  This function used to configure the overall cache setting.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__)

/* To be revised - START */
#if defined(PROTECT_REGION_BEFORE_INIT)

static Protect_Ram_Region_Before_Init_Struct_T  PROTECT_RAM_REGION[Protect_Region_max_ID];
volatile kal_uint16 gChannel_mode = 0;
volatile kal_uint16 gChannel_protect = 0;

kal_uint32 Get_MPU_Protect_Smallest_Size_Align_Increase(kal_uint32 Addr)
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    if(Addr & 0x00000FFF)	
        return( ((Addr>>12) +1)<<12);
    else
        return( (Addr>>12)<<12);	
#endif
}

kal_uint32 Get_MPU_Protect_Smallest_Size_Align_Decrease(kal_uint32 Addr)
{
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    return( (Addr>>12)<<12);
#endif
}

void MPU_Protect_Before_Init(void)
{
    kal_uint32 i;
    kal_uint32 endAddress;
    EXTSRAM_REGION_INFO_T region_temp;

#if !defined(__NORFLASH_NON_XIP_SUPPORT__)
    endAddress = custom_get_SINGLEBANKCODE_End();
#if defined(__ALICE_SUPPORT__)
    endAddress = custom_get_EXTSRAM_ALICE_End();
#endif /* __ALICE_SUPPORT__ */
#endif /* __NORFLASH_NON_XIP_SUPPORT__ */

    PROTECT_RAM_REGION[Vector_0xF_bank_Section].region_star_addr = MAP2CREGVA(RAM_BASE_ADDR); //0xF0000000
    PROTECT_RAM_REGION[Vector_0xF_bank_Section].attribute = NO_ACCESS;
    PROTECT_RAM_REGION[Normal_Section1].region_star_addr = Get_MPU_Protect_Smallest_Size_Align_Decrease(MAP2CREGVA(endAddress));
	PROTECT_RAM_REGION[Normal_Section1].attribute = PRIV_RW_USER_RO;

#if defined(__BOOT_ZIMAGE_SUPPORT__)
	custom_query_boot_zimage_region(&region_temp);
	PROTECT_RAM_REGION[Boot_Zimage_Section].region_star_addr = Get_MPU_Protect_Smallest_Size_Align_Increase(region_temp.addr);
	PROTECT_RAM_REGION[Boot_Zimage_Section].attribute = PRIV_RW_USER_RO;	 
#endif

#if defined(__ZIMAGE_SUPPORT__)
    custom_query_zimage_RO_region(&region_temp);
    PROTECT_RAM_REGION[Zimage_Section].region_star_addr = Get_MPU_Protect_Smallest_Size_Align_Increase(region_temp.addr);	
    PROTECT_RAM_REGION[Zimage_Section].attribute = NO_ACCESS;
    PROTECT_RAM_REGION[Zimage_Section+1].region_star_addr = Get_MPU_Protect_Smallest_Size_Align_Decrease(region_temp.addr+region_temp.len);
    PROTECT_RAM_REGION[Zimage_Section+1].attribute = PRIV_RW_USER_RO;
#endif

#if defined(__DCM_WITH_COMPRESSION__) || defined(__DYNAMIC_CODE_MANAGER__)
#if !defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
    custom_query_dcm_reigon(&region_temp);
    PROTECT_RAM_REGION[DCM_Section].region_star_addr = Get_MPU_Protect_Smallest_Size_Align_Increase(region_temp.addr);
    PROTECT_RAM_REGION[DCM_Section].attribute = NO_ACCESS;
    PROTECT_RAM_REGION[DCM_Section+1].region_star_addr = Get_MPU_Protect_Smallest_Size_Align_Decrease(region_temp.addr+region_temp.len);
    PROTECT_RAM_REGION[DCM_Section+1].attribute = PRIV_RW_USER_RO;
#endif
#endif
    PROTECT_RAM_REGION[Normal_section_dummy].region_star_addr = MAP2CREGVA(RAM_BASE_ADDR)+EMI_EXTSRAM_SIZE;//RAM  total size   should modifed a macro	

    for(i = 0;i<Normal_section_dummy;i++)
    {
        gChannel_mode = 0;
        SetupMPUCacheByROMSegment(PROTECT_RAM_REGION[i].region_star_addr , PROTECT_RAM_REGION[i+1].region_star_addr , PROTECT_RAM_REGION[i+1].region_star_addr-PROTECT_RAM_REGION[i].region_star_addr , PROTECT_RAM_REGION[i].attribute, PAGE_CACHEABLE);	
        PROTECT_RAM_REGION[i].channel =  gChannel_protect;
    }
}

void MPU_Unprotect_One_Region(Protect_Ram_Region_ID id)
{
    gChannel_mode = 1;
    gChannel_protect = PROTECT_RAM_REGION[id].channel;
    PROTECT_RAM_REGION[id].attribute = PRIV_RW_USER_RO;
    SetupMPUCacheByROMSegment(PROTECT_RAM_REGION[id].region_star_addr , PROTECT_RAM_REGION[id+1].region_star_addr , PROTECT_RAM_REGION[id+1].region_star_addr-PROTECT_RAM_REGION[id].region_star_addr ,PRIV_RW_USER_RO, PAGE_CACHEABLE);	
    gChannel_mode = 0;
}

void MPU_protect_One_Region(Protect_Ram_Region_ID id,MPU_ATTRIBUTE attribute)
{
    gChannel_mode = 1;
    gChannel_protect = PROTECT_RAM_REGION[id].channel;
    PROTECT_RAM_REGION[id].attribute = attribute;
    SetupMPUCacheByROMSegment(PROTECT_RAM_REGION[id].region_star_addr , PROTECT_RAM_REGION[id+1].region_star_addr , PROTECT_RAM_REGION[id+1].region_star_addr-PROTECT_RAM_REGION[id].region_star_addr ,attribute, PAGE_CACHEABLE);	
    gChannel_mode = 0;
}

#else
	void MPU_Protect_Before_Init(void){}
	void MPU_Unprotect_One_Region(Protect_Ram_Region_ID id){}
	void MPU_protect_One_Region(Protect_Ram_Region_ID id,MPU_ATTRIBUTE attribute){}
#endif
/* To be revised - END */

void CacheInit(void)
{

/*********************************
  *
  * MTK L1 Cache Config
  *
  ********************************/
  
#if defined(__MTK_L1CACHEABLE__) || defined(__MTK_MMU__)
   kal_uint32 mpu_end_addr;
#if defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__)
   kal_uint32 rom_start_addr = custom_get_1st_ROM_ROMBase();
   kal_uint32 rom_end_addr = custom_get_1st_ROM_RAMBase();
   kal_uint32 rom_len = custom_get_1st_ROM_ROMLength();
#else /* _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__ || __EMMC_BOOTING__ */

#if defined(TK6516)
   kal_uint32 rom_start_addr = (custom_get_1st_ROM_ROMBase() & 0x00000000);
#else /*defined(TK6516) */
   kal_uint32 rom_start_addr = (custom_get_1st_ROM_ROMBase() & 0xf8000000);
#endif /*defined(TK6516) */

   /* Ken: bootloader should be considered */
   kal_uint32 rom_end_addr = rom_start_addr + custom_get_NORFLASH_ROMSpace();
   kal_uint32 rom_len = (custom_get_1st_ROM_ROMBase() & ~0xf8000000) + custom_get_1st_ROM_ROMLength();
   
#if defined(__NORFLASH_NON_XIP_SUPPORT__)
   rom_end_addr = custom_get_SINGLEBANKCODE_End();
   rom_len = rom_end_addr - rom_start_addr;
#endif /* __NORFLASH_NON_XIP_SUPPORT__ */
   
#endif /* _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__ || __EMMC_BOOTING__ */

#if defined(__WRITE_THROUGH_CACHEABLE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __WRITE_THROUGH_CACHEABLE__ */
	 
   print_bootup_trace(SST_INIT_L1CACHE_ENTER);
	 
#if defined(__MTK_MMU__)

   /* make the EXTSRAM info table */
   custom_mk_ram_info();
   
   /*
    * MPU configuration.
    * Configure the region of code and RO as READABLE_BUT_NON_WRITEABLE and cacheable.
    */
#if defined(MT6253E_S00)||defined(MT6253L_S00) || defined(MT6252H_S00) || defined(MT6252_S00)
   mpu_end_addr = SetupMPUCacheByROMSegment(rom_start_addr, rom_end_addr, rom_len, READABLE_BUT_NON_WRITEABLE, PAGE_CACHEABLE);
   SetupMPUCacheByROMSegment(MAP2CREGVA(RAM_BASE_ADDR), MAP2CREGVA(RAM_BASE_ADDR)+EMI_EXTSRAM_SIZE, EMI_EXTSRAM_SIZE, READABLE_WRITEABLE, PAGE_CACHEABLE);
#else
   mpu_end_addr = SetupMPUCacheByROMSegment(rom_start_addr, rom_end_addr, rom_len, PRIV_RO_USER_RO, PAGE_CACHEABLE);
/* To be revised - START */
#if !defined(PROTECT_REGION_BEFORE_INIT)
   SetupMPUCacheByROMSegment(MAP2CREGVA(RAM_BASE_ADDR), MAP2CREGVA(RAM_BASE_ADDR)+EMI_EXTSRAM_SIZE, EMI_EXTSRAM_SIZE, PRIV_RW_USER_RO, PAGE_CACHEABLE);
//liming remove for MPU protect before init
#endif
/* To be revised - END */
#endif /* MT6253E_S00 || MT6253L_S00 */
   
#if defined(__ALICE_SUPPORT__) && !defined(_NAND_FLASH_BOOTING_) && !defined(__NOR_FLASH_BOOTING__) && !defined(__EMMC_BOOTING__)
   {
      kal_uint32 alice_start_addr = custom_get_ALICE_Base();
      kal_uint32 alice_length = custom_get_ALICE_Length();
      kal_uint32 alice_end_addr = alice_start_addr + alice_length;
#if defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
      /* Round to 4KB alignment */
      alice_start_addr = alice_start_addr & ~((kal_uint32)(0x1000 - 1)); /* Round down */
      alice_end_addr = (alice_end_addr + (0x1000 - 1)) & ~((kal_uint32)(0x1000 - 1)); /* Round up */
      alice_length = alice_end_addr - alice_start_addr; /* Get the length after rounding */
#endif /* MT6250 */
      SetupMPUCacheByROMSegment(alice_start_addr, alice_end_addr, alice_length, PRIV_RO_USER_RO, PAGE_CACHEABLE);
   }
#endif /* __ALICE_SUPPORT__ */
#else
   /*
    * MPU configuration.
    * Configure the region of code and RO as READABLE_BUT_NON_WRITEABLE.
    */
   mpu_end_addr = SetupMPUbyROMSegment(rom_start_addr, rom_end_addr, rom_len);
   
   /*
    * Configure code and RO in the TCM as READABLE_BUT_NON_WRITEABLE.
    */
   SetupMPUonTCM();

   /*
    * Cache configuration.
    */
   /* Configure the region of code and RO as code-cacheable. */
   SetupCACHEbyROMSegment(rom_start_addr, rom_end_addr, rom_len);
#endif   

   /*
    * Ken: verify the coverage of MPU/cache channels on ROM
    *      Note that here is an assumption that the coverage of
    *      MPU and cache channel on ROM are the same
    */
   ASSERT((rom_start_addr + rom_len) <= mpu_end_addr && mpu_end_addr <= rom_end_addr);

#if defined(__WRITE_THROUGH_CACHEABLE__)
/* under construction !*/
#if defined(__MTK_MMU__)
/* under construction !*/
#if defined(MT6253E_S00) || defined(MT6253L_S00) || defined(MT6252H_S00) || defined(MT6252_S00)
/* under construction !*/
#else
/* under construction !*/
#endif /* MT6253E_S00 || MT6253L_S00 || MT6258H_S00 || MT6258_S00 */
/* under construction !*/
#else
/* under construction !*/
#if defined(MT6253)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
#endif /* MT6253 */
/* under construction !*/
#endif /* __MTK_MMU__ */
/* under construction !*/
#endif /* __WRITE_THROUGH_CACHEABLE__ */

   SetupMPUCacheByFeature();


#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(TK6516) || defined(MT6516) || defined(MT6268H) || defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)

   /* enable code cache */
   CodeCacheConfig(CACHE_4WAY, KAL_TRUE);

#elif defined(MT6225) || defined(MT6253T) || defined(MT6253) || defined(MT6251)

   /* enable code cache */
   CodeCacheConfig(CACHE_2WAY, KAL_TRUE);

#endif

#if defined(MT6253) && defined(__WRITE_THROUGH_CACHEABLE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* MT6253 */

   print_bootup_trace(SST_INIT_L1CACHE_EXIT);

#endif   /* __MTK_L1CACHEABLE__ */



/*********************************
  *
  * ARM9 L1 Cache / MMU Config
  *
  ********************************/

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)

  {
    kal_uint32 cache_type;
    kal_uint32 cache_size;
    
    cache_type = cp15_read_cache_type();

#if defined(__ARM9_MMU__)
    cache_type = ((cache_type<<8)>>26)-3;
#elif defined(__ARM11_MMU__)
    cache_type = ((cache_type<<10)>>28)-3;
#else
    #error
#endif
    cache_size = 4096;
    while(cache_type--)
    {
        cache_size<<=1;
    }
    cache_line_nr = cache_size/CPU_CACHE_LINE_SIZE;
    cache_line_nr_per_way = cache_line_nr/4;
  }

  print_bootup_trace(SST_INIT_MMU_ENTER);
  MMU_Init();
  print_bootup_trace(SST_INIT_MMU_EXIT);

#endif  /* __ARM9_MMU__ || __ARM11_MMU__ */



/*********************************
  *
  * MTK L2 Cache Config
  *
  ********************************/

#if defined(__MTK_L2CACHEABLE__)

   print_bootup_trace(SST_INIT_L2CACHE_ENTER);

#if defined(MT6228) || defined(MT6229) || defined(MT6230) || defined(MT6268T) || defined(MT6268H)

   /* enable data cache */
   DataCacheConfig(KAL_TRUE, KAL_FALSE);

#elif defined(MT6238) || defined(MT6239)  /* MT6228 || MT6229 || MT6230 || MT6268T || MT6268H */

   if((*EMI_CONN & DRAM_TYPE_MASK) != DRAM_TYPE_DDR)
   {
      /* enable L2 data cache while do not reserve 2 ways for MPEG4. */
      DataCacheConfig(KAL_TRUE, KAL_FALSE);
   }

#endif  /* MT6228 || MT6229 || MT6230 || MT6268T || MT6268H */

   print_bootup_trace(SST_INIT_L2CACHE_EXIT);

#endif   /* __MTK_L2CACHEABLE__ */

}

#endif /* !__FUE__ && !__UBL__ */


/*************************************************************************
* FUNCTION
*  meut_init_cache
*
* DESCRIPTION
*  This function initializes cache for MEUT.
*
* PARAMETERS
*  None
*
* RETURNS
*  0 for success; -1 for failure
*************************************************************************/

#if defined(__MEUT__)

kal_int32 meut_init_cache(void)
{
   CacheInit();

   return 0;
}

#endif  /* __MEUT__ */


/*************************************************************************
* FUNCTION
*  CacheInitBalancedMAUI
*
* DESCRIPTION
*  This function used to configure the overall cache setting.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__)

#if defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__)

void CacheInitSecondaryMAUI(void)
{

/*********************************
  *
  * MTK L1 Cache Config
  *
  ********************************/
	
#if defined(__MTK_L1CACHEABLE__)

   kal_uint32 sec_rom_start_addr = custom_get_2nd_ROM_ROMBase();
   kal_uint32 sec_rom_end_addr = custom_get_2nd_ROM_RAMBase();
   kal_uint32 sec_rom_len = custom_get_2nd_ROM_ROMLength();
	 
   /* MPU configuration. Configure the SECONDARY_ROM region as READABLE_BUT_NON_WRITEABLE. */
   SetupMPUbyROMSegment(sec_rom_start_addr, sec_rom_end_addr, sec_rom_len);
   
   /* Cache configuration. Configure the SECONDARY_ROM region as code-cacheable. */
   SetupCACHEbyROMSegment(sec_rom_start_addr, sec_rom_end_addr, sec_rom_len);

#endif /* __MTK_L1CACHEABLE__ */

#if defined(__MTK_MMU__)

   kal_uint32 sec_rom_start_addr = custom_get_2nd_ROM_ROMBase();
   kal_uint32 sec_rom_end_addr = custom_get_2nd_ROM_RAMBase();
   kal_uint32 sec_rom_len = custom_get_2nd_ROM_ROMLength();
   kal_uint32 temp = sec_rom_start_addr;

   ROUNDDOWN_4KB(sec_rom_start_addr);
   //ROUNDUP_4KB(sec_rom_end_addr);
   sec_rom_len += temp - sec_rom_start_addr; /* Get the length after rounding */

   SetupMPUCacheByROMSegment(sec_rom_start_addr, sec_rom_end_addr, sec_rom_len, PRIV_RO_USER_RO, PAGE_CACHEABLE);

#if defined(__ALICE_SUPPORT__)
   {
      /* Code region */
      {
         kal_uint32 alice_start_addr = custom_get_ALICE_Base();
         kal_uint32 alice_length = custom_get_ALICE_Length();
         kal_uint32 alice_end_addr = alice_start_addr + alice_length;

         /* Round to 4KB alignment */
         ROUNDDOWN_4KB(alice_start_addr); /* Round down */
         ROUNDUP_4KB(alice_end_addr);     /* Round up */
         alice_length = alice_end_addr - alice_start_addr; /* Get the length after rounding */

         SetupMPUCacheByROMSegment(alice_start_addr, alice_end_addr, alice_length, PRIV_RO_USER_RO, PAGE_CACHEABLE);
      }

      /* Source data region */
      {
         extern void AliceGetCompressedDumpRegion(kal_uint32 *base, kal_uint32 *length);
         kal_uint32 alice_start_addr;
         kal_uint32 alice_length;
         kal_uint32 alice_end_addr;

         AliceGetCompressedDumpRegion(&alice_start_addr, &alice_length);
         alice_start_addr = (alice_start_addr & 0x0FFFFFFF) | INT_RetrieveRemappedFlashBaseAddr();
         alice_end_addr = alice_start_addr + alice_length;

         /* Round to 4KB alignment */
         ROUNDDOWN_4KB(alice_start_addr); /* Round down */
         ROUNDUP_4KB(alice_end_addr);     /* Round up */
         alice_length = alice_end_addr - alice_start_addr; /* Get the length after rounding */

         SetupMPUCacheByROMSegment(alice_start_addr, alice_end_addr, alice_length, PRIV_RO_USER_RO, PAGE_CACHEABLE);
      }
   }
#endif /* __ALICE_SUPPORT__ */

#endif


/*********************************
  *
  * ARM9 L1 Cache / MMU Config
  *
  ********************************/

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)

   MMU_InitSecondaryMAUI();

#endif  /* __ARM9_MMU__ || __ARM11_MMU__ */
}

#endif /* _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__ || __EMMC_BOOTING__ */

#endif /* !__FUE__ && !__UBL__ */

#if defined(MT6253) && defined(__WRITE_THROUGH_CACHEABLE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* MT6253 && __WRITE_THROUGH_CACHEABLE__ */

#endif /* __MTK_TARGET__ */

/*************************************************************************
* FUNCTION
*  query_opposite_switchable_cacheaddr_ram
*
* DESCRIPTION
*  This function used to query the opposite cache-switchable address
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*
* RETURNS
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__)

kal_uint32 query_opposite_switchable_cacheaddr_ram(kal_uint32 addr)
{
#if (defined(__ARM9_MMU__) || defined(__DYNAMIC_SWITCH_CACHEABILITY__)) && defined(__MTK_TARGET__)
   EXTSRAM_REGION_INFO_T *regionp;	
   kal_uint32 buf_addr;
   kal_uint32 buf_start;
   kal_int32 buf_len;

#if defined(__KAL_VM__)
   if(is_flmm_va(addr))
   {
       return flmm_virt_to_phys((void *)addr);
   }
   if (is_flmm_pa(addr))
   {
       return flmm_phys_to_virt((void *)addr);
   }
#endif /* __KAL_VM__ */
   
   custom_query_dynamic_cached_extsram_default_nc_region(&regionp);
   while (regionp->addr != 0 || regionp->len != 0)
   {      
      if (regionp->len == 0)
      { 
         regionp++;
         continue;
      }   
      buf_start = regionp->addr;
      buf_addr = regionp->addr + regionp->len;
      ROUNDUP_4KB(buf_addr);
      ROUNDDOWN_4KB(buf_start);
      buf_len = buf_addr - buf_start;

      if((addr >= buf_start) &&
	       (addr <= buf_start+buf_len))
      {   
         return MAP2CREGVA(addr);
      }
      if((addr >= MAP2CREGVA(buf_start)) &&
	       (addr <= MAP2CREGVA(buf_start+buf_len)))
      {
         return MAP2CREGPA(addr);
      }

      regionp++;
   }

   custom_query_dynamic_cached_extsram_default_c_region(&regionp);
   while (regionp->addr != 0 || regionp->len != 0)
   {      
      if (regionp->len == 0)
      { 
         regionp++;
         continue;
      }   
      buf_start = regionp->addr;
      buf_addr = regionp->addr + regionp->len;
      ROUNDUP_4KB(buf_addr);
      ROUNDDOWN_4KB(buf_start);
      buf_len = buf_addr - buf_start;

      if((addr >= buf_start) &&
         (addr <= buf_start+buf_len))
      {   
         return MAP2CREGPA(addr);
      }   
      if((addr >= MAP2CREGPA(buf_start)) &&
         (addr <= MAP2CREGPA(buf_start+buf_len)))
      {   
         return MAP2CREGVA(addr);
      } 

      regionp++;
   }

#if !defined(__MTK_MMU__)
   if(INT_QueryIsSysRAM(addr))
   {
      if(INT_QueryIsCachedSysRAM(addr, 0x4))
      {
         return MAP2CREGPA_SYS(addr);
      }
	  
      return MAP2CREGVA_SYS(addr);
   }
#endif /* __MTK_MMU__ */

   /* assert if the input address is not cache-switchable */
   ASSERT(0);
#endif  /* (__ARM9_MMU__ || __DYNAMIC_SWITCH_CACHEABILITY__) && __MTK_TARGET__ */

   return addr;
}

#endif /* !__FUE__ && !__UBL__ */

/*************************************************************************
* FUNCTION
*  virt_to_phys
*
* DESCRIPTION
*  This function used to query the physical address of a virtual address
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*
* RETURNS
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__)

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
kal_uint32 virt_to_phys(void * address)
#if defined(__MTK_TARGET__)
{	
   kal_uint32 retval = 0;
   kal_uint32 is_sysram = 0;   

#if !defined(__MTK_MMU__)
   is_sysram = INT_QueryIsSysRAM(address);
#endif /* __MTK_MMU__ */
   
#if defined(__KAL_VM__) && !defined(__FUE__) && !defined(__UBL__)
   if(is_flmm_va((kal_uint32)address))
   {
   	  return flmm_virt_to_phys(address);
   }
   else if(is_flmm_pa((kal_uint32)address))
   {
       return (kal_uint32)address;
   }
#endif /* __KAL_VM__ && !__FUE__ && !__UBL__ */

#if !defined(__MTK_MMU__)
   if(is_sysram == 0)
   {
      retval = MAP2CREGPA(address);
   }
   else
   {
      retval = MAP2CREGPA_SYS(address);
   }
#else
   if(is_sysram == 0)
   {
      retval = MAP2CREGPA(address);
   }
   else
   {
      ASSERT(0);
   }
#endif /* __MTK_MMU__ */
   
    return retval;
}
#else /* __MTK_TARGET__ */
{
    return 0;
}
#endif /* __MTK_TARGET__ */

#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ */

#endif /* !__FUE__ && !__UBL__ */

/*************************************************************************
* FUNCTION
*  phys_to_virt
*
* DESCRIPTION
*  This function used to query the physical address of a virtual address
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*
* RETURNS
*
*************************************************************************/

#if !defined(__FUE__) && !defined(__UBL__)

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
kal_uint32 phys_to_virt(void * address)
#if defined(__MTK_TARGET__)
{	
   kal_uint32 retval = 0;
   kal_uint32 is_sysram = 0;   

#if !defined(__MTK_MMU__)
   is_sysram = INT_QueryIsSysRAM(address);
#endif /* __MTK_MMU__ */
   
#if defined(__KAL_VM__) && !defined(__FUE__) && !defined(__UBL__)
   if(is_flmm_pa((kal_uint32)address))
   {
   	  return flmm_phys_to_virt(address);
   }
   else if ( is_flmm_va((kal_uint32)address))
   {
       return (kal_uint32)address;
   }
#endif /* __KAL_VM__ && !__FUE__ && !__UBL__ */

#if !defined(__MTK_MMU__)
   if(is_sysram == 0)
   {
      retval = MAP2CREGVA(address);
   }
   else
   {
      retval = MAP2CREGVA_SYS(address);
   }
#else
   if(is_sysram == 0)
   {
      retval = MAP2CREGVA(address);
   }
   else
   {
      ASSERT(0);
   }
#endif /* __MTK_MMU__ */
   
    return retval;
}
#else /* __MTK_TARGET__ */
{
    return 0;
}
#endif /* __MTK_TARGET__ */

#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ */

#endif /* !__FUE__ && !__UBL__ */

#if !defined(__FUE__) && !defined(__UBL__)
#if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)

void *map_back_memregion(void *ptr, void *region)
{
#if defined(__KAL_VM__) && !defined(__FUE__) && !defined(__UBL__)
    if (is_flmm_va((kal_uint32)region)) {
        if (is_flmm_pa((kal_uint32)ptr)) {
            return (void *)flmm_phys_to_virt(ptr);
        }
        else {
            return ptr;
        }
    }
    else if (is_flmm_pa((kal_uint32)region)) {
        if (is_flmm_va((kal_uint32)ptr)) {
            return (void *)flmm_virt_to_phys(ptr);
        }
        else {
            return ptr;
        }
    }
    else 
#endif /* __KAL_VM__ && !__FUE__ && !__UBL__ */
    return (void *)MAP2CREGNEWA(ptr, region);
}

#endif /* __MTK_TARGET__ && __DYNAMIC_SWITCH_CACHEABILITY__ */
#endif /* !__FUE__ && !__UBL__ */

extern kal_bool query_is_non_cached_ram(kal_uint32 addr, kal_uint32 len);

/*************************************************************************
* FUNCTION
*  query_is_noncached_ram
*
* DESCRIPTION
*  This function used to query if the memory is non-cacheable.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*  len - the length of the memory.
*
* RETURNS
*
*************************************************************************/
kal_int32 query_is_noncached_ram(kal_uint32 addr, kal_uint32 len)
#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__MTK_MMU__))
    #if !defined(__FUE__)
        #if defined(__KAL_VM__)
        {
            return (((((kal_uint32)(addr) & CREG_OFFSET) ^ CREG_OFFSET) != 0) && 
                                             ((((kal_uint32)(addr) & MMV2CREG_OFFSET) ^ MMV2CREG_OFFSET) != 0));
        }
        #else
        {
            return ((((kal_uint32)(addr) & CREG_OFFSET) ^ CREG_OFFSET) != 0);
        }
        #endif /* __KAL_VM__ */
    #else /* __FUE__ */
    {
        return query_is_non_cached_ram((kal_uint32)addr, (kal_uint32)len);
    }  
    #endif /* __FUE__ */
#elif defined(__MTK_TARGET__) && defined(__MTK_L1CACHEABLE__)
    #if !defined(__FUE__)
        #if defined(__WRITE_THROUGH_CACHEABLE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #else
        {
            return 1;
        }
        #endif /* __WRITE_THROUGH_CACHEABLE__ */
    #else /* __FUE__ */
    {
        return 1;
    }
    #endif /* __FUE__ */
#else
{
    return 1;   
}    
#endif /* __MTK_TARGET__ && (__ARM9_MMU__ || __ARM11_MMU__ || __MTK_MMU__) */

/*************************************************************************
* FUNCTION
*  query_is_cached_ram
*
* DESCRIPTION
*  This function used to query if the memory is cacheable.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*  len - the length of the memory.
*
* RETURNS
*
*************************************************************************/
kal_int32 query_is_cached_ram(kal_uint32 addr, kal_uint32 len)
#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__MTK_MMU__))
    #if !defined(__FUE__)
        #if defined(__KAL_VM__)
        {
            return (((((kal_uint32)(addr) & CREG_OFFSET) ^ CREG_OFFSET) == 0) || \
                                             ((((kal_uint32)(addr) & MMV2CREG_OFFSET) ^ MMV2CREG_OFFSET) == 0));
        }
        #else /* __KAL_VM__ */
        {
            return ((((kal_uint32)(addr) & CREG_OFFSET) ^ CREG_OFFSET) == 0);
        }
        #endif /* __KAL_VM__ */
    #else /* __FUE__ */
    ;
    #endif /* __FUE__ */
#elif defined(__MTK_TARGET__) && defined(__MTK_L1CACHEABLE__)
    #if !defined(__FUE__)
        #if defined(__WRITE_THROUGH_CACHEABLE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #else /* __WRITE_THROUGH_CACHEABLE__ */
        {
            return 0;
        }
        #endif /* __WRITE_THROUGH_CACHEABLE__ */
    #else /* !__FUE__ */
    ;
    #endif /* __FUE__ */
#else
{
        return 0;
}
#endif /* __MTK_TARGET__ && (__ARM9_MMU__ || __ARM11_MMU__ || __MTK_MMU__) */

/*************************************************************************
* FUNCTION
*  query_is_noncached_sys_ram
*
* DESCRIPTION
*  This function used to query if the sys ram is non-cacheable.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*  len - the length of the memory.
*
* RETURNS
*
*************************************************************************/
kal_int32 query_is_noncached_sys_ram(kal_uint32 addr, kal_uint32 len)
#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__MTK_MMU__))
    #if !defined(__FUE__)
    {
        return ((((kal_uint32)(addr) & CREG_SYS_OFFSET) ^ CREG_SYS_OFFSET) != 0);
    }
    #else /* __FUE__ */
    {
        return 1;
    }
    #endif /* __FUE__ */
#elif defined(__MTK_TARGET__) && defined(__MTK_L1CACHEABLE__)
    #if !defined(__FUE__)
    {
        return 1;
    }
    #else /* __FUE__ */
    {
        return 1;
    }
    #endif /* __FUE__ */
#else
{
    return 1;
}
#endif /* __MTK_TARGET__ && (__ARM9_MMU__ || __ARM11_MMU__ || __MTK_MMU__) */

/*************************************************************************
* FUNCTION
*  query_is_cached_sys_ram
*
* DESCRIPTION
*  This function used to query if the sys ram is cacheable.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*  len - the length of the memory.
*
* RETURNS
*
*************************************************************************/
kal_int32 query_is_cached_sys_ram(kal_uint32 addr, kal_uint32 len)
#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__MTK_MMU__))
    #if !defined(__FUE__)
    {
        return ((((kal_uint32)(addr) & CREG_SYS_OFFSET) ^ CREG_SYS_OFFSET) == 0);
    }
    #else /* __FUE__ */
    {
        return 0;
    }
    #endif /* __FUE__ */
#elif defined(__MTK_TARGET__) && defined(__MTK_L1CACHEABLE__)
    #if !defined(__FUE__)
    {
        return 0;
    }
    #else /* __FUE__ */
    {
        return 0;
    }
    #endif /* __FUE__ */
#else
{
    return 0;
}
#endif /* __MTK_TARGET__ && (__ARM9_MMU__ || __ARM11_MMU__ || __MTK_MMU__) */

/*************************************************************************
* FUNCTION
*  query_is_sys_ram
*
* DESCRIPTION
*  This function used to query if the memory is sys ram.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*
* RETURNS
*
*************************************************************************/
kal_int32 query_is_sys_ram(kal_uint32 addr)
#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__MTK_MMU__))
    #if !defined(__FUE__)
        #if defined(__MTK_MMU__)
        {
            return 0;
        }
        #else /* __MTK_MMU__ */
        {
            #if !defined(__UBL__)
            return (((((kal_uint32)(addr) & CREG_SYS_OFFSET) ^ CREG_SYS_OFFSET) == 0) || ((((kal_uint32)(addr) & CREG_SYS_OFFSET) ^ custom_get_SysRam_Base()) == 0));
            #else /* __EXT_BOOTLOADER__ */
            return 0;
            #endif /* __EXT_BOOTLOADER__ */
        }
        #endif /* __MTK_MMU__ */
    #else /* __FUE__ */
        #if defined(_NAND_FLASH_BOOTING_)
        ;
        #else /* _NAND_FLASH_BOOTING_ */
        {
            return 0;
        }
        #endif /* _NAND_FLASH_BOOTING_ */
    #endif /* __FUE__ */
#else
;
#endif /* __MTK_TARGET__ && (__ARM9_MMU__ || __ARM11_MMU__ || __MTK_MMU__) */

/*************************************************************************
* FUNCTION
*  query_is_non_mtkl1cached_ram
*
* DESCRIPTION
*  This function used to query if the memory is MTKL1 cacheabled
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*  len - the length of the memory
*
* RETURNS
*
*************************************************************************/
kal_int32 query_is_non_mtkl1cached_ram(kal_uint32 addr, kal_uint32 len)
#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__MTK_MMU__))
    #if !defined(__FUE__)
    {
        return 1;
    }
    #else /* __FUE__ */
    {
        return 1;
    }
    #endif /* __FUE__ */
#elif defined(__MTK_TARGET__) && defined(__MTK_L1CACHEABLE__)
    #if !defined(__FUE__)
    {
        return (query_is_l1cache_cacheable((kal_uint32)addr, len, 1) == -1);
    }
    #else
    {
        return 1;
    }
    #endif /* __FUE__ */
#else
{
    return 1;
}
#endif /* __MTK_TARGET__ && (__ARM9_MMU__ || __ARM11_MMU__ || __MTK_MMU__) */

/*************************************************************************
* FUNCTION
*  query_is_mtkl1cached_ram
*
* DESCRIPTION
*  This function used to query if the memory is MTKL1 cacheabled
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*  len - the length of the memory
*
* RETURNS
*
*************************************************************************/
kal_int32 query_is_mtkl1cached_ram(kal_uint32 addr, kal_uint32 len)
#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__MTK_MMU__))
    #if !defined(__FUE__)
    {
        return 0;
    }
    #else /* __FUE__ */
    {
        return 0;
    }
    #endif /* __FUE__ */
#elif defined(__MTK_TARGET__) && defined(__MTK_L1CACHEABLE__)
    #if !defined(__FUE__)
    {
        return (query_is_l1cache_cacheable((kal_uint32)addr, len, 1) != -1);
    }
    #else /* __FUE__ */
    {
        return 0;
    }
    #endif /* __FUE__ */
#else
{
    return 0;
}
#endif /* __MTK_TARGET__ && (__ARM9_MMU__ || __ARM11_MMU__ || __MTK_MMU__) */

/*************************************************************************
* FUNCTION
*  query_is_writethroughcached_ram
*
* DESCRIPTION
*  This function used to query if the memory is write through cacheable.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*  len - the length of the memory
*
* RETURNS
*
*************************************************************************/
kal_int32 query_is_writethroughcached_ram(kal_uint32 addr, kal_uint32 len)
#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__MTK_MMU__))
    #if !defined(__FUE__)
    {
        return 0;
    }
    #else /* __FUE__ */
    {
        return 0;
    }
    #endif /* __FUE__ */
#elif defined(__MTK_TARGET__) && defined(__MTK_L1CACHEABLE__)
    #if !defined(__FUE__)
        #if defined(__WRITE_THROUGH_CACHEABLE__)
            #if defined(MT6253)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #else /* MT6253 */
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* MT6253 */
        #else /* __WRITE_THROUGH_CACHEABLE__ */
        {
            return 0;
        }
        #endif /* __WRITE_THROUGH_CACHEABLE__ */
    #else /* __FUE__ */
    {
        return 0;
    }
    #endif /* __FUE__ */
#else
{
    return 0;
}
#endif /* __MTK_TARGET__ && (__ARM9_MMU__ || __ARM11_MMU__ || __MTK_MMU__) */

/*************************************************************************
* FUNCTION
*  INT_DynamicSwitchCacheableRegion
*
* DESCRIPTION
*  This function used to query if the memory is write through cacheable.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*  len - the length of the memory
*
* RETURNS
*
*************************************************************************/
#if defined(__MTK_TARGET__) && defined(__MTK_L1CACHEABLE__)
void INT_DynamicSwitchCacheableRegion(const kal_uint32 start, const kal_uint32 end, kal_uint32 total, kal_int32 c)
#if defined(__WRITE_THROUGH_CACHEABLE__)
    #if defined(MT6253)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else /* MT6253 */
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* MT6253 */
#else /* __WRITE_THROUGH_CACHEABLE__ */
{
    dynamic_switch_cacheable_region(start, end, total, c);
}
#endif /* __WRITE_THROUGH_CACHEABLE__ */
#endif /* __MTK_TARGET__ && __MTK_L1CACHEABLE__ */
    
