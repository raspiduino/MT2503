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
 *   rtfiles.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file contains core functions of file system.
 *
 * Author:
 * -------
 *
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *============================================================================
 ****************************************************************************/

/**************************************************************************/
/*                                                                        */
/*  File: BUFFERS.C                              Copyright (c) 1998,2002  */
/*  Version: 4.0                                 On Time Informatik GmbH  */
/*                                                                        */
/*                                                                        */
/*                                      On Time        /////////////----- */
/*                                    Informatik GmbH /////////////       */
/* --------------------------------------------------/////////////        */
/*                                  Real-Time and System Software         */
/*                                                                        */
/**************************************************************************/

/*
 * Include
 */
#include "kal_release.h"

#include "fs_gprot.h"
#include "fs_internal_api.h"
#include "rtfiles.h"
#include "rtfex.h"
#include "rtfbuf.h"
#include "fs_utility.h"
#include "fs_kal.h"
#include "kal_trace.h"
#include "fs_trc.h"

// Trace
#define fs_util_trace_err_noinfo(error_code) fs_util_trace_err_slim(error_code, rtfbuf_c, __LINE__)

// Defines
#ifndef SECTOR_SIZE
#define SECTOR_SIZE (512)
#endif

// Assert
#define fs_assert_local(expr) fs_assert(expr, rtfbuf_c)
#define fs_ext_assert_local(expr, e1, e2, e3) fs_ext_assert(expr, rtfbuf_c, e1, e2, e3)

#ifdef _MSC_VER
   #define INTERN _fastcall
#elif defined __BORLANDC__
   #define INTERN __fastcall
#else
   #define INTERN
#endif

///////////////////////////////////////////////////////////////////////////////
/// RTF Cache
///////////////////////////////////////////////////////////////////////////////
#if !defined(__FS_CACHE_SUPPORT__) || defined(__FS_CARD_DOWNLOAD__)||defined(__FS_FUNET_ENABLE__)

#define B_FREE    0x00
#define B_VALID   0x01   // buffer has valid data
#define B_DIRTY   0x02   // buffer has valid data and must be written to disk
#define B_INUSE   0x04   // buffer is being accessed by RTFiles
#define B_BUSY    0x08   // buffer is being accessed by a device driver
#define B_SINGLE  0x10   // single buffer for emergent use only /* Guarantee fixed disk access, Karen Hsu, 2005/05/19 */


/*
 * Locals
 */

#ifdef __FS_DEBUG__
static RTFBufferStatistic BufferStat = { 0 };
#endif
static RTFBuffer * FirstBuffer = NULL;
#ifdef __FS_DEDICATED_BUFFER__
   RTFMutex *MTMemLock = NULL;
#endif

#if !defined(__MTK_TARGET__) || defined(GEN_FOR_PC) || defined(__RESOURCE_GEN_) || defined(NVRAM_AUTO_GEN)
    #define __fs_cache_align(x)
#elif defined(__ARMCC_VERSION)
    #define __fs_cache_align(x)   __align(x)
#elif defined(__GNUC__)
    #ifdef __DYNAMIC_SWITCH_CACHEABILITY_
    #define __fs_cache_align(x)   __attribute__ ((aligned(x), zero_init, section ("NONCACHEDZI")))
    #else
    #define __fs_cache_align(x)   __attribute__ ((aligned(x)))
    #endif
#endif

#if !defined(__GNUC__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)
#pragma arm section zidata = "NONCACHEDZI"
#endif // !__GNUC__ && __DYNAMIC_SWITCH_CACHEABILITY__

//#ifdef __FS_CARD_SUPPORT__
#if defined(__FS_CARD_SUPPORT__)||defined(__FS_FUNET_ENABLE__)
   #ifndef _NAND_FLASH_BOOTING_
      #define __FS_EMERGENT_NOR_BUFFER_SUPPORT__
      RTFBuffer g_Emergent_NOR_Buffer;
      __fs_cache_align(FS_CACHE_ALIGNMENT_OFFSET) BYTE g_Emergent_NOR_BufferData[RTF_MIN_BUFFER_SIZE];
   #endif
   #ifdef NAND_SUPPORT
      #define __FS_EMERGENT_NAND_BUFFER_SUPPORT__
      RTFBuffer g_Emergent_NAND_Buffer;
      __fs_cache_align(FS_CACHE_ALIGNMENT_OFFSET) BYTE g_Emergent_NAND_BufferData[RTF_MIN_BUFFER_SIZE];
   #endif
      #define __FS_EMERGENT_CARD_BUFFER_SUPPORT__
      RTFBuffer g_Emergent_Card_Buffer;
      __fs_cache_align(FS_CACHE_ALIGNMENT_OFFSET) BYTE g_Emergent_Card_BufferData[RTF_MIN_BUFFER_SIZE];
#else
   #if (defined NAND_SUPPORT) && !(defined _NAND_FLASH_BOOTING_)
      #define __FS_EMERGENT_NOR_BUFFER_SUPPORT__
      RTFBuffer g_Emergent_NOR_Buffer;
      __fs_cache_align(FS_CACHE_ALIGNMENT_OFFSET) BYTE g_Emergent_NOR_BufferData[RTF_MIN_BUFFER_SIZE];
      #define __FS_EMERGENT_NAND_BUFFER_SUPPORT__
      RTFBuffer g_Emergent_NAND_Buffer;
      __fs_cache_align(FS_CACHE_ALIGNMENT_OFFSET) BYTE g_Emergent_NAND_BufferData[RTF_MIN_BUFFER_SIZE];
   #endif
#endif /* __FS_CARD_SUPPORT__ */

#ifdef __FS_DEDICATED_BUFFER__
BYTE  gFS_DedicatedBufferLock = 0;  // flag to indicate if FS dedicated buffer has been allocated
#endif /* __FS_DEDICATED_BUFFER__ */

#if !defined(__GNUC__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)
#pragma arm section zidata
#endif // !__GNUC__ && __DYNAMIC_SWITCH_CACHEABILITY__

/*-----------------------------------*/
static void INTERN UpFront(RTFBuffer * B)
{
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
   if (B->Flags & B_SINGLE)
      return;
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

   if (B != FirstBuffer)
   {
      // unlink it
      B->Prev->Next = B->Next;
      B->Next->Prev = B->Prev;

      // link into front
      B->Next = FirstBuffer;
      B->Prev = FirstBuffer->Prev;

      B->Next->Prev = B;
      B->Prev->Next = B;

      FirstBuffer = B;
   }
}

/*-----------------------------------*/
static void INTERN ToTail(RTFBuffer * B)
{
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
   if (B->Flags & B_SINGLE)
      return;
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

   if (B == FirstBuffer)
      FirstBuffer = FirstBuffer->Next;
   else
   {
      // unlink it
      B->Prev->Next = B->Next;
      B->Next->Prev = B->Prev;

      B->Next = FirstBuffer;
      B->Prev = FirstBuffer->Prev;

      B->Next->Prev = B;
      B->Prev->Next = B;
   }
}

/*******************************************************************//**
 * Unlink specified device's inuse buffer
 *
 * @par Category:
 * File System
 *
 * this is called by UnlockDevice, GetBuffer, SearchBuffer and SafeUnlock
 **********************************************************************/
void FreeBuffer(RTFDevice * Dev)
{
   if (Dev->DevData.B)
   {
      Dev->DevData.B->Flags &= ~B_INUSE;
      Dev->DevData.B = NULL;
   }
}

/*******************************************************************//**
 * Discard specified buffer
 *
 * @par Category:
 * File System
 *
 * This function handles related flags and links in buffer structure.
 **********************************************************************/
void DiscardOtherBuffer(RTFBuffer * B)
{

   /* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
   if (B->Flags & B_SINGLE)
      B->Flags = B_SINGLE;
   else
   /* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

      B->Flags = 0;
   B->recoverable_flag = RTF_NORMAL_WRITE;
   ToTail(B);
}

/*******************************************************************//**
 * Discard device's in-use buffer
 *
 * @par Category:
 * File System
 *
 * This function handles the device structure. Buffer structure is handled by DiscardOtherBuffer().
 **********************************************************************/
void DiscardBuffer(RTFDevice * Dev)
// this frees a buffer
{

   DiscardOtherBuffer(Dev->DevData.B);
   Dev->DevData.B = NULL;
}

/*-----------------------------------*/
void AllocBuffers(void)
{
   RTFBuffer * B;
   UINT i;

   if (FirstBuffer)
      return;

/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
#ifdef __FS_EMERGENT_NOR_BUFFER_SUPPORT__
   g_Emergent_NOR_Buffer.Flags |= B_SINGLE;
   g_Emergent_NOR_Buffer.recoverable_flag = RTF_NORMAL_WRITE;
   g_Emergent_NOR_Buffer.Data = g_Emergent_NOR_BufferData;
#endif

#ifdef __FS_EMERGENT_NAND_BUFFER_SUPPORT__
   g_Emergent_NAND_Buffer.Flags |= B_SINGLE;
   g_Emergent_NAND_Buffer.recoverable_flag = RTF_NORMAL_WRITE;
   g_Emergent_NAND_Buffer.Data = g_Emergent_NAND_BufferData;
#endif
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

#ifdef __FS_EMERGENT_CARD_BUFFER_SUPPORT__  /* PATCH , WCP_SW, 2006/08/03, ADD BEGIN */
   g_Emergent_Card_Buffer.Flags |= B_SINGLE;
   g_Emergent_Card_Buffer.recoverable_flag = RTF_NORMAL_WRITE;
   g_Emergent_Card_Buffer.Data = g_Emergent_Card_BufferData;
#endif /* PATCH , WCP_SW, 2006/08/03, ADD END */

#ifdef __FS_DEBUG__
   BufferStat.TotalBuffers = FS_MAX_BUFFERS;
#endif

   #if 0 // [SLIM]
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif

   if (((DWORD) gFS_Data.BufferTable) % 4)
      fs_err_internal_fatal(FS_ERR_BUFFER_02, NULL);

   for (i=0; i<FS_MAX_BUFFERS; i++)
   {
      B = gFS_Data.BufferTable + i;
      B->Num = i;
      B->recoverable_flag = RTF_NORMAL_WRITE;
      B->Data = gFS_Data.BufferData + (i*RTF_MIN_BUFFER_SIZE);
      B->Next = B + 1;
      B->Prev = B - 1;
   }

   FirstBuffer = gFS_Data.BufferTable;

   FirstBuffer->Prev = FirstBuffer + FS_MAX_BUFFERS - 1;
   FirstBuffer->Prev->Next = FirstBuffer;
}

#ifdef __FS_DEBUG__

/*-----------------------------------*/
void RTFAPI RTFBufferInfo(RTFBufferStatistic * BufferInfo)
{
   RTFBuffer * B;

#ifdef DEBUG
   UINT Test = 0;
#endif

   if (FirstBuffer == 0)
      AllocBuffers();

   *BufferInfo = BufferStat;

   BufferInfo->CacheHits = BufferInfo->PhysicalBufferReads ? 100 * (BufferInfo->CachedBufferReads) / (BufferInfo->PhysicalBufferReads + BufferInfo->CachedBufferReads) : 0;

   BufferInfo->ValidBuffers = 0;

   B = FirstBuffer;
   do
   {
      if (B->Flags & B_VALID)
         BufferInfo->ValidBuffers++;
#ifdef DEBUG
      if (B->Flags & B_DIRTY)
         Test++;
#endif
      B = B->Next;
   } while (B != FirstBuffer);
#ifdef DEBUG
   if (Test != BufferStat.DirtyBuffers)
      fs_err_internal_fatal(FS_ERR_BUFFER_03, NULL);
#endif
}

#endif

/*-----------------------------------*/
static void INTERN ReadBuffer(RTFBuffer * B)
{
    fs_util_time_init_with_duration();
    fs_util_time_start();


   XTRY
      case XCODE:
         B->Flags |= B_BUSY;
         rtf_core_read_sectors(B->Dev, B->Data, B->Sector, 1, 0);

         #ifdef __FS_DEBUG__
         BufferStat.PhysicalBufferReads++;
         #endif

         B->Flags |= B_VALID;
         break;
      default:
         ToTail(B);
         B->Flags &= ~B_INUSE;
         break;
      case XFINALLY:
         B->Flags &= ~B_BUSY;

         fs_util_time_stop();
         fs_util_time_set_duration();

         fs_util_trace_device_io(B->Dev->DeviceFlags | MT_IO_TRACE_READ | MT_IO_TRACE_CACHE_OUT | (B->Flags & FS_BTYPE_MASK), B->Sector, 1, fs_util_time_query_duration());
         fs_util_trace_info4(TRACE_GROUP_5, FS_CACHE_READ, (kal_uint32)B->Sector, 1, (kal_uint32)B, NULL, NULL);
         break;
   XENDX
}

/*******************************************************************//**
 * Write specified buffer to disk
 *
 * @par Category:
 * File System
 *
 * @remarks
 * If number of FAT table > 1, FAT table data will be "mirrored" to all other FAT tables!
 **********************************************************************/
static void INTERN WriteBuffer(RTFBuffer * B)
{
    fs_util_time_init_with_duration();
    fs_util_time_start();


   #ifdef DEBUG
   if (B->Flags != (B_INUSE | B_VALID | B_DIRTY))
      fs_err_internal_fatal(FS_ERR_BUFFER_04, NULL);
   #endif

   XTRY
      case XCODE:

         B->Flags |= B_BUSY;

         // recoverable_flag indicates if it has to use recoverablewritesector or not
         if (B->recoverable_flag == RTF_RECOVERABLE_WRITE)
           rtf_core_write_sectors(B->Dev, B->Data, B->Sector, 1, 0, RTF_RECOVERABLE_WRITE);
         else
           rtf_core_write_sectors(B->Dev, B->Data, B->Sector, 1, 0, RTF_NORMAL_WRITE);

         // clear the recoverable_flag
         B->recoverable_flag = RTF_NORMAL_WRITE;

         /* clear dirty flag */
         B->Flags &= ~B_DIRTY;

         #ifdef __FS_DEBUG__
         BufferStat.PhysicalBufferWrites++;
         BufferStat.AsynchBufferFlushs += (B->FirstDirtyTime != B->Dev->DevData.AccessCount);
         BufferStat.DirtyBuffers--;
         #endif

         // check if this is a FAT sector and we have to
         // take care of other FATs
         // We will ignore any errors here, but we do want
         // critical errors.

         {
            int i, FATs;

            if ((B->FATSectorInfo) && ((B->Dev->DeviceFlags & RTF_DEVICE_SINGLE_FAT) == 0))
               FATs = B->FATSectorInfo->FATCount;
            else
               FATs = 1;

            if (FATs > 1)
            {
               if(B->Flags & B_SINGLE)
                   B->Flags = B_VALID | B_INUSE | B_BUSY | B_SINGLE;
               else
                   B->Flags = B_VALID | B_INUSE | B_BUSY;

               for (i=1; i<FATs; i++)
               {
                  rtf_core_write_sectors(B->Dev, B->Data, B->Sector + i * B->FATSectorInfo->SectorsPerFAT, 1, NO_RAISE, RTF_NORMAL_WRITE);
#ifdef __FS_DEBUG__
                  BufferStat.PhysicalBufferWrites++;
                  BufferStat.AsynchBufferFlushs += B->FirstDirtyTime != B->Dev->DevData.AccessCount;
#endif
               }
               if(B->Flags & B_SINGLE)
                   B->Flags = B_VALID | B_INUSE | B_SINGLE;
               else
                   B->Flags = B_VALID | B_INUSE;
            }
         }
         break;
      default: // only the first FAT can raise exceptions
         B->Flags &= ~B_INUSE;
         break;
      case XFINALLY:
         B->Flags &= ~B_BUSY;

         fs_util_time_stop();
         fs_util_time_set_duration();
         fs_util_trace_device_io(B->Dev->DeviceFlags | MT_IO_TRACE_WRITE | MT_IO_TRACE_CACHE_OUT | (B->Flags & FS_BTYPE_MASK), B->Sector, 1, fs_util_time_query_duration());
         fs_util_trace_info4(TRACE_GROUP_5, FS_CACHE_WRITE, (kal_uint32)B->Sector, 1, (kal_uint32)B, NULL, NULL);

         break;
   XENDX
}

void RTFAPI AdjustBuffer(void)
{
   RTFBuffer * B;

   FlushAllBuffers(gFS_Data.DriveTable[0].Dev);
   DiscardAllBuffers(gFS_Data.DriveTable[0].Dev);

   B = FirstBuffer->Next;
   do
   {
      B->Flags |= B_INUSE;
      B->Dev = 0x0;
      B = B->Next;
   }while (B != FirstBuffer);

   FirstBuffer->Next = FirstBuffer;
}

/*-----------------------------------*/
void *SearchBuffer(RTFDevice * Dev, RTFSector Sector)
{
   RTFBuffer * B;    // selected buffer

   #ifdef DEBUG
   if (!RTFSYSOwnMutex(RTFLock))
      fs_err_internal_fatal(FS_ERR_BUFFER_05, NULL);
   #endif

   if (Dev->DevData.B && (Dev->DevData.B->Sector == Sector))
      return Dev->DevData.B->Data;

/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
#ifdef __FS_EMERGENT_NOR_BUFFER_SUPPORT__
   B = &g_Emergent_NOR_Buffer;
   if (B->Flags & B_VALID)
   {
      if ((B->Sector == Sector) && (B->Dev == Dev))
      {
         B->Flags |= B_INUSE;
         FreeBuffer(Dev);
         Dev->DevData.B = B;
         return B->Data;
      }
   }
#endif

#ifdef __FS_EMERGENT_NAND_BUFFER_SUPPORT__
   B = &g_Emergent_NAND_Buffer;
   if (B->Flags & B_VALID)
   {
      if ((B->Sector == Sector) && (B->Dev == Dev))
      {
         B->Flags |= B_INUSE;
         FreeBuffer(Dev);
         Dev->DevData.B = B;
         return B->Data;
      }
   }
#endif
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

#ifdef __FS_EMERGENT_CARD_BUFFER_SUPPORT__ /* PATCH , WCP_SW, 2006/08/03, ADD BEGIN */
   B = &g_Emergent_Card_Buffer;
   if (B->Flags & B_VALID)
   {
      if ((B->Sector == Sector) && (B->Dev == Dev))
      {
         B->Flags |= B_INUSE;
         FreeBuffer(Dev);
         Dev->DevData.B = B;
         return B->Data;
      }
   }
#endif /* PATCH , WCP_SW, 2006/08/03, ADD END */

   // search forward for the sector in question

   B = FirstBuffer;
   do
   {
      if (B->Flags & B_VALID)
      {
         if ((B->Sector == Sector) && (B->Dev == Dev))
         {
            #ifdef DEBUG
            if (B->Flags & (B_INUSE | B_BUSY))  // double allocation
               fs_err_internal_fatal(FS_ERR_BUFFER_06, NULL);
            #endif

            /* move matched buffer to the front, and set it as device's INUSE buffer */
            UpFront(B);
            B->Flags |= B_INUSE;
            FreeBuffer(Dev);
            Dev->DevData.B = B;
            return B->Data;
         }
      }
      else
         return NULL;
      B = B->Next;
   } while (B != FirstBuffer);
   return NULL;
}

/*-----------------------------------*/
void *GetBuffer(RTFDevice * Dev, RTFSector Sector, UINT Flags)
{
   RTFBuffer * B;    // selected buffer

   #ifdef DEBUG
   if (!RTFSYSOwnMutex(RTFLock))
      fs_err_internal_fatal(FS_ERR_BUFFER_07, NULL);
   if (Dev->DevData.AltBuffer)
      fs_err_internal_fatal(FS_ERR_BUFFER_08, NULL);
   #endif

   /* check if device's B pointer (INUSE buffer) is matched. */
   if ((Flags & ALT_BUFFER) == 0)
   {
      if (Dev->DevData.B)
      {
         if ((Dev->DevData.B->Sector == Sector)&&(Dev == Dev->DevData.B->Dev))
         {
            /* if device's INUSE buffer is matched, bingo! use it! */
            return Dev->DevData.B->Data;
         }
         else
         {
            /* if not matched, unlink it (clean INUSE flag and B pointer) */
            FreeBuffer(Dev);
         }
      }
   }

   // search forward for the sector in question or an invalid (free) buffer

   B = FirstBuffer;
   do
   {
      //check Valid flag before get buffer NIKI_21062 Jeffrey
      if ((B->Flags != 0))
      {
         if ((B->Sector == Sector) && (B->Dev == Dev)&&(B->Flags & B_VALID))
         {
            #ifdef __FS_DEBUG_CACHE__
            if (B->Flags & (B_INUSE | B_BUSY))  // double allocation
               fs_err_internal_fatal(FS_ERR_BUFFER_09, NULL);
            if ((B->Flags & B_VALID) == 0)
               fs_err_internal_fatal(FS_ERR_BUFFER_10, NULL);
            #endif

            #ifdef __FS_DEBUG__
            BufferStat.CachedBufferReads++;
            #endif

            B->Flags |= B_INUSE;

            goto SaveAndExit;
         }
      }
      else // not allocated buffers follow the first unallocated buffer
      {
         #ifdef __FS_DEBUG_CACHE__
         {
            RTFBuffer * B1 = B;
            do
            {
            	//check Valid flag before get buffer NIKI_21062 Jeffrey
               if ((B1->Flags != 0)&&(B1->Flags & B_VALID))
                  fs_err_internal_fatal(FS_ERR_BUFFER_11, NULL);
               B1 = B1->Next;
            }
            while (B1 != FirstBuffer);
         }
         #endif

         goto ReadAndExit;
      }
      B = B->Next;
   } while (B != FirstBuffer);

   #ifdef __FS_DEBUG__
   BufferStat.BuffersDiscarded++; // we have to discard one
   #endif

   // now search backwards (oldest first) for a buffer to discard:
   // for any buffer on the same device
   // or for a clean buffer

   B = FirstBuffer->Prev;
   do
   {
      if (((B->Flags & B_INUSE) == 0) &&   /* it's not in use and (we can't change other device's INUSE buffer!) */
          ((B->Dev == Dev) ||               /* it's occupied by this device or (to replace any buffer occupied by this device) */
           ((B->Flags & B_DIRTY) == 0)))    /* it's not dirty (to replace other device's non-INUSE and non-dirty buffer */
      {
         #ifdef __FS_DEBUG_CACHE__
         if (B->Flags & B_BUSY)
            fs_err_internal_fatal(FS_ERR_BUFFER_12, NULL);
         #endif

         /* flush buffer if it is dirty */
         if (B->Flags & B_DIRTY)
         {
            #ifdef __FS_DEBUG_CACHE__
            if (B->Dev != Dev)
               fs_err_internal_fatal(FS_ERR_BUFFER_13, NULL);
            #endif

            /* set INUSE flag because we will use this buffer later */
            B->Flags        |= B_INUSE;

            WriteBuffer(B);
         }
         goto ReadAndExit;
      }
      B = B->Prev;
   } while (B != FirstBuffer->Prev);

   /* B is FirstBuffer->Prev here */

/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
#ifdef __FS_EMERGENT_NOR_BUFFER_SUPPORT__
   if(Dev->DeviceFlags & MT_DEVICE_NOR_FLASH)
   {
      B = &g_Emergent_NOR_Buffer;
      B->Flags |= B_INUSE;
      if ((B->Sector == Sector) && (B->Dev == Dev))
         goto SaveAndExit;
      else
         goto ReadAndExit;
   }
#endif

#ifdef __FS_EMERGENT_NAND_BUFFER_SUPPORT__
   if(Dev->DeviceFlags & MT_DEVICE_NAND_FLASH)
   {
      B = &g_Emergent_NAND_Buffer;
      B->Flags |= B_INUSE;
      if ((B->Sector == Sector) && (B->Dev == Dev))
         goto SaveAndExit;
      else
         goto ReadAndExit;
   }
#endif
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

#ifdef __FS_EMERGENT_CARD_BUFFER_SUPPORT__ /* PATCH , WCP_SW, 2006/08/03, ADD BEGIN */
   if(Dev->DeviceFlags & RTF_DEVICE_REMOVABLE)
   {
      B = &g_Emergent_Card_Buffer;
      B->Flags |= B_INUSE;
      if ((B->Sector == Sector) && (B->Dev == Dev))
         goto SaveAndExit;
      else
         goto ReadAndExit;
   }
#endif /* PATCH , WCP_SW, 2006/08/03, ADD END */

   fs_util_trace_err_noinfo(RTF_OUT_OF_BUFFERS);
   fs_util_trace_info2(TRACE_ERROR, FS_ERR_GETBUFFER_OUT_OF_BUFFERS, Sector, fs_conf_get_devtype_by_devflag(Dev->DeviceFlags), NULL);


   /* if no buffer satisfies the conditions, raise an exception */
   XRAISE(RTF_OUT_OF_BUFFERS);

ReadAndExit:
   B->Dev           = Dev;
   B->Sector        = Sector;
   B->FATSectorInfo = NULL;

   // for emergency buffer
   if (B->Flags & B_SINGLE)
   {
      B->Flags = (B_SINGLE | B_INUSE);
   }
   else
      B->Flags         = B_INUSE;

   B->recoverable_flag = RTF_NORMAL_WRITE;

   B->Flags |= (Flags&FS_BTYPE_MASK);

   if (Flags & NO_LOAD)
      B->Flags |= B_VALID;
   else
      ReadBuffer(B);

SaveAndExit:
   UpFront(B);

   /* udpate B pointer */
   if (Flags & ALT_BUFFER)
      Dev->DevData.AltBuffer = B;
   else
      Dev->DevData.B = B;
   return B->Data;
}

/*-----------------------------------*/
#ifdef __FS_DEBUG__
static void INTERN FlushOldest(RTFDevice * Dev)
{
   // search backwards (oldest first) for a buffer to commit

   RTFBuffer * B = FirstBuffer->Prev;

   do
   {
      if ((B->Flags & B_DIRTY) && (B->Dev == Dev))
      {
         #ifdef DEBUG
         if (B->Flags & B_BUSY)
            fs_err_internal_fatal(FS_ERR_BUFFER_16, NULL);
         #endif
         if (B->Flags & B_INUSE)
            WriteBuffer(B);
         else
         {
            B->Flags |= B_INUSE;
            WriteBuffer(B);
            B->Flags &= ~B_INUSE;
         }
         return;
      }
      B = B->Prev;
   } while (B != FirstBuffer->Prev);

   #ifdef DEBUG
   // Some debugging. This is actually not a fatal error.
   // The file system can keep on going if no buffer to commit is found.
   // The only danger now is a critical error on an other device, which
   // could throw an out-of-buffer exception
   fs_err_internal_fatal(FS_ERR_BUFFER_17, NULL);
   #endif
}
#endif

/*-----------------------------------*/
void SetDirty(RTFDevice * Dev)
{
   RTFBuffer * B = Dev->DevData.B;
   #ifdef DEBUG
   if (B == NULL)
       fs_err_internal_fatal(FS_ERR_BUFFER_18, NULL);
   if ((B->Flags & B_INUSE) == 0)
       fs_err_internal_fatal(FS_ERR_BUFFER_19, NULL);
   if ((B->Flags & B_VALID) == 0)
       fs_err_internal_fatal(FS_ERR_BUFFER_20, NULL);
   #endif

   if (B->Flags & B_DIRTY)
#ifdef __FS_DEBUG__
      BufferStat.CachedBufferWrites += (B->LastDirtyTime != B->Dev->DevData.AccessCount);
#else
   ;
#endif
   else
   {
      B->Flags |= B_DIRTY;
#ifdef __FS_DEBUG__
      if (++BufferStat.DirtyBuffers > BufferStat.MaxDirtyBuffers)
         BufferStat.MaxDirtyBuffers = BufferStat.DirtyBuffers;
#endif
      B->FirstDirtyTime = B->Dev->DevData.AccessCount;
   }
   B->LastDirtyTime = B->Dev->DevData.AccessCount;

   // prevent from human errors
   B->recoverable_flag = RTF_NORMAL_WRITE;

#ifdef __FS_DEBUG__
   if (BufferStat.DirtyBuffers > (FS_MAX_BUFFERS-2))
      FlushOldest(Dev);
#endif

/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
   if (B->Flags & B_SINGLE)
      WriteBuffer(B);
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

}

/*-----------------------------------*/
void SetRecoverableFlag(RTFDevice * Dev, BYTE block_type)
{
   RTFBuffer * B = Dev->DevData.B;
   #ifdef DEBUG
   if (B == NULL)
       fs_err_internal_fatal(FS_ERR_BUFFER_21, NULL);
   #endif

   if (block_type == FS_BLOCK_PROTECTION_ENUM)
      B->recoverable_flag = RTF_RECOVERABLE_WRITE;
   else
      B->recoverable_flag = RTF_NORMAL_WRITE;
}

/*******************************************************************//**
 * Commit device's INUSE buffer
 *
 * @par Category:
 * File System
 **********************************************************************/
void RTFAPI CommitBuffer(RTFDevice * Dev)
// write a buffer if it is dirty
{
   RTFBuffer * B = Dev->DevData.B;
   #ifdef DEBUG
   if (B == NULL)
       fs_err_internal_fatal(FS_ERR_BUFFER_22, NULL);
   if ((B->Flags & B_INUSE) == 0)
       fs_err_internal_fatal(FS_ERR_BUFFER_23, NULL);
   if ((B->Flags & B_VALID) == 0)
       fs_err_internal_fatal(FS_ERR_BUFFER_24, NULL);
   #endif
   if (B->Flags & B_DIRTY)
      WriteBuffer(B);
}

/*-----------------------------------*/
void RTFAPI DiscardAllBuffers(RTFDevice * Dev)
{
   RTFBuffer * B;

Again:
   B = FirstBuffer;
   do
   {
      if ((B->Flags & B_VALID) == 0)
      {
         #ifdef DEBUG
         {
            RTFBuffer * B1 = B;
            do
            {
               if (B1->Flags != 0)
                  fs_err_internal_fatal(FS_ERR_BUFFER_25, NULL);
               B1 = B1->Next;
            }
            while (B1 != FirstBuffer);
         }
         #endif
         return;
      }
      else
         if (B->Dev == Dev)
         {
            if (Dev->DevData.B == B)
               DiscardBuffer(Dev);
            else
               DiscardOtherBuffer(B);
            goto Again;
         }
      B = B->Next;
   } while (B != FirstBuffer);
}

/*-----------------------------------*/
void RTFAPI DiscardBuffersRange(RTFDevice * Dev, RTFSector Sector, RTFSector Count, int Commit)
{
   RTFBuffer * B;

/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD START */
//don't put these two cases behind
#ifdef __FS_EMERGENT_NOR_BUFFER_SUPPORT__
   B = &g_Emergent_NOR_Buffer;
   if ((B->Dev == Dev) && (B->Sector >= Sector) && (B->Sector < (Sector+Count)))
   {
      B->Flags = B_SINGLE;
      B->recoverable_flag = RTF_NORMAL_WRITE;
      if (Dev->DevData.B == B)
         Dev->DevData.B = NULL;
   }
#endif

#ifdef __FS_EMERGENT_NAND_BUFFER_SUPPORT__
   B = &g_Emergent_NAND_Buffer;
   if ((B->Dev == Dev) && (B->Sector >= Sector) && (B->Sector < (Sector+Count)))
   {
      B->Flags = B_SINGLE;
      B->recoverable_flag = RTF_NORMAL_WRITE;
      if (Dev->DevData.B == B)
         Dev->DevData.B = NULL;
   }
#endif
/* Guarantee fixed disk access, Karen Hsu, 2005/05/19, ADD END */

#ifdef __FS_EMERGENT_Card_BUFFER_SUPPORT__ /* PATCH , WCP_SW, 2006/08/03, ADD BEGIN */
   B = &g_Emergent_Card_Buffer;
   if ((B->Dev == Dev) && (B->Sector >= Sector) && (B->Sector < (Sector+Count)))
   {
      B->Flags = B_SINGLE;
      B->recoverable_flag = RTF_NORMAL_WRITE;
      if (Dev->DevData.B == B)
         Dev->DevData.B = NULL;
   }
#endif /* PATCH , WCP_SW, 2006/08/03, ADD END */

Again:
   B = FirstBuffer;
   do
   {
      if ((B->Flags & B_VALID) == 0)
      {
         #ifdef DEBUG
         {
            RTFBuffer * B1 = B;
            do
            {
               if (B1->Flags != 0)
                  fs_err_internal_fatal(FS_ERR_BUFFER_26, NULL);
               B1 = B1->Next;
            }
            while (B1 != FirstBuffer);
         }
         #endif
         return;
      }
      else
      {
         if ((B->Dev == Dev) && (B->Sector >= Sector) && (B->Sector < (Sector + Count)))
         {
            if ((B->Flags & B_DIRTY) && Commit)
            {
               #ifdef DEBUG
               if (B->Flags & B_BUSY)
                  fs_err_internal_fatal(FS_ERR_BUFFER_27, NULL);
               #endif
               if (B->Flags & B_INUSE)
                  WriteBuffer(B);
               else
               {
                  B->Flags |= B_INUSE;
                  WriteBuffer(B);
                  B->Flags &= ~B_INUSE;
               }
            }
            if (Dev->DevData.B == B)
               DiscardBuffer(Dev);
            else
               DiscardOtherBuffer(B);
            goto Again;
         }
      }
      B = B->Next;
   } while (B != FirstBuffer);
}

/*******************************************************************//**
 * Flush all buffers occupied by a specified device
 *
 * @par Category:
 * File System
 *
 * @note
 * Keep device's B pointer after flush all its buffers.
 **********************************************************************/
void RTFAPI FlushAllBuffers(RTFDevice * Dev)
{
   RTFBuffer * B;

Again:
   B = FirstBuffer;
   do
   {
      if ((B->Flags & B_DIRTY) && (B->Dev == Dev))
      {
         #ifdef DEBUG
         if (B->Flags & B_BUSY)
            fs_err_internal_fatal(FS_ERR_BUFFER_28, NULL);
         #endif

         /* do not modify device's B pointer and buffer's INUSE flag */
         if (B->Flags & B_INUSE)
            WriteBuffer(B);
         else
         {
            /* WriteBuffer requires flag INUSE, DIRTY and VALID, so set INUSE before call WriteBuffer */
            B->Flags |= B_INUSE;
            WriteBuffer(B);
            B->Flags &= ~B_INUSE;
         }
         goto Again;
      }
      B = B->Next;
   } while (B != FirstBuffer);
}

/*******************************************************************//**
 * Flush all FAT data buffer of a specified device
 *
 * @par Category:
 * File System
 **********************************************************************/
void FlushFAT(RTFDevice * Dev)
{
   RTFBuffer * B;

Again:
   B = FirstBuffer;
   do
   {
      if ((B->Flags & B_DIRTY) && B->FATSectorInfo && (B->Dev == Dev))
      {
         #ifdef DEBUG
         if (B->Flags & B_BUSY)
            fs_err_internal_fatal(FS_ERR_BUFFER_29, NULL);
         if (B->FATSectorInfo->Dev != Dev)
            fs_err_internal_fatal(FS_ERR_BUFFER_30, NULL);
         #endif
         if (B->Flags & B_INUSE)
            WriteBuffer(B);
         else
         {
            B->Flags |= B_INUSE;
            WriteBuffer(B);
            B->Flags &= ~B_INUSE;
         }
         goto Again;
      }
      B = B->Next;
   } while (B != FirstBuffer);
}

/*******************************************************************//**
 * Flush all buffers of a specified device by the order of logical sector number
 *
 * @par Category:
 * File System
 *
 * @note
 * In FAT12/16, FAT will always be committed before directory entry!
 **********************************************************************/
void RTFAPI FlushAllBuffersInGeometryOrder(RTFDevice * Dev)
{
   RTFBuffer * B;
   RTFBuffer * W;

Again:
   B = FirstBuffer;
   W = NULL;
   do
   {
      if ((B->Flags & B_DIRTY) && (B->Dev == Dev))
      {
         #ifdef DEBUG
         if (B->Flags & B_BUSY)
            fs_err_internal_fatal(FS_ERR_BUFFER_31, NULL);
         #endif
         if (W == NULL || W->Sector > B->Sector)
         {
            W = B;
         }
      }
      B = B->Next;
   } while (B != FirstBuffer);

   if (W != NULL)
   {
      if (W->Flags & B_INUSE)
      {
         WriteBuffer(W);
      }
      else
      {
         W->Flags |= B_INUSE;
         WriteBuffer(W);
         W->Flags &= ~B_INUSE;
      }
      goto Again;
   }
}




#ifdef DEBUG
/*-----------------------------------*/
static void INTERN EntryExitCheck(RTFDevice * Dev, _XData * XD)
{
   int i;

   if (FirstBuffer == NULL) // buffers not initialized yet
      return;
   if ((XD == NULL) || (XD->Next == NULL)) // are we leaving the the file system?
   {
      RTFBuffer * B;

      if (Dev->DevData.B)
         fs_err_internal_fatal(FS_ERR_BUFFER_32, NULL);

      // check that the buffer chain is not corrupted

      B = FirstBuffer;
      for (i=0; i<FS_MAX_BUFFERS-1; i++)
         B = B->Next;
      if (B == FirstBuffer)
         fs_err_internal_fatal(FS_ERR_BUFFER_33, NULL);
      B = B->Next;
      if (B != FirstBuffer)
         fs_err_internal_fatal(FS_ERR_BUFFER_34, NULL);

      // now check backward links
      B = FirstBuffer->Prev;
      for (i=0; i<FS_MAX_BUFFERS-1; i++)
         B = B->Prev;
      if (B == FirstBuffer->Prev)
         fs_err_internal_fatal(FS_ERR_BUFFER_35, NULL);
      B = B->Prev;
      if (B != FirstBuffer->Prev)
         fs_err_internal_fatal(FS_ERR_BUFFER_36, NULL);

      // check that not buffers of this drive are in use or busy
      B = gFS_Data.BufferTable;
      for (i=0; i<FS_MAX_BUFFERS; i++)
      {
         if ((B->Dev == Dev) && (B->Flags & (B_INUSE | B_BUSY)))
            fs_err_internal_fatal(FS_ERR_BUFFER_37, NULL);
         B++;
      }

      // check that RTFiles and the drive are locked
      if (!RTFSYSOwnMutex(RTFLock) || !RTFSYSOwnMutex(Dev->DevData.Lock))
         fs_err_internal_fatal(FS_ERR_BUFFER_38, NULL);

   }
   else  // we are not leaving, so make sure the next exception handler is in scope
      if ((void*) XD <= (void*) &XD)
          fs_err_internal_fatal(FS_ERR_BUFFER_39, NULL);
}

/*-----------------------------------*/
static void INTERN CheckReleased(_XData * XD)
{
   RTFDevice * Dev;

   if ((XD == NULL) || (XD->Next == NULL)) // are we leaving the file system?
   {
      for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)
         if (RTFSYSOwnMutex(Dev->DevData.Lock))
            fs_err_internal_fatal(FS_ERR_BUFFER_40, NULL);
      if (RTFSYSOwnMutex(RTFLock))
         fs_err_internal_fatal(FS_ERR_BUFFER_41, NULL);
   }
}
#endif



#ifdef __FS_DEDICATED_BUFFER__

fs_buffer_alloc_data_struct _gfs_dedicated_buffer;

void RTFAPI MTBufInit(const kal_uint32 buf_addr, const kal_uint32 buf_size)
{
   kal_uint32 offset;

   // 1. initialize FS dedicated buffer allocation data
   _gfs_dedicated_buffer.free_addr = (kal_uint32)buf_addr;
   _gfs_dedicated_buffer.free_size = (kal_uint32)buf_size;

   // 2. let buffer pool be 4-byte aligned
   offset = _gfs_dedicated_buffer.free_addr & 0x3;

   if (offset > 0)
   {
      offset = 4 - offset;
      _gfs_dedicated_buffer.free_addr += offset;
      _gfs_dedicated_buffer.free_size = buf_size - offset;
   }

   _gfs_dedicated_buffer.allocated_times = 0;
}

int RTFAPI MTBufCheckRange(unsigned int addr)
{
   if ((addr >= (unsigned int)gFS_DedicatedBufferPool) &&
   	   (addr < (unsigned int)gFS_DedicatedBufferPool + FS_DEDICATED_BUFFER_SIZE))
      return 1;
   else
      return 0;
}


int RTFAPI MTBufAlloc(unsigned int size, unsigned char **buf, unsigned int flag)
{
   kal_uint32     i;
   kal_taskid     task_id;

   fs_lock_get_mutex(_gfs_lock_common, FS_INFINITE);

   /*
    * check
    * 1. If allocator is the correct task?
    * 2. If free size is available?
    * 3. If allocation times is valid?
    */

   task_id = kal_get_current_thread_ID();

   // check 1
   if (0 < _gfs_dedicated_buffer.allocated_times || 0 == size)
   {
      if (task_id != _gfs_dedicated_buffer.allocated_task)
      {
         *buf = NULL;
         size = 0;

         goto MTBufAlloc_Exit;
      }
   }

   // check 2
   if (((flag & FS_INT_DBUF_ALLOC_PRECISE) && (size > _gfs_dedicated_buffer.free_size)) ||   // check for precise allocation
        (0 == _gfs_dedicated_buffer.free_size)) // check for greedy allocation
   {
      *buf = NULL;
      size = 0;

      goto MTBufAlloc_Exit;
   }

   // check 3
   if (_gfs_dedicated_buffer.allocated_times < FS_INT_DBUF_ALLOC_MAX_TIMES)
   {
      /*
       * We have exactly free size for either precise or greedy allocation.
       */

      *buf = (unsigned char*)_gfs_dedicated_buffer.free_addr; // must be a 4-byte aligned address

      // calculate correct allocation size
      if (size > _gfs_dedicated_buffer.free_size)
      {
         size = _gfs_dedicated_buffer.free_size;
      }

      // register this allocation
      i = _gfs_dedicated_buffer.allocated_times;
      _gfs_dedicated_buffer.allocated_times++;
      _gfs_dedicated_buffer.allocated_addr[i] = _gfs_dedicated_buffer.free_addr;
      _gfs_dedicated_buffer.allocated_size[i] = size;

      // calculate new free address (let new free address be 4-byte aligned)
      _gfs_dedicated_buffer.free_addr += size;
      _gfs_dedicated_buffer.free_size -= size;

      i = _gfs_dedicated_buffer.free_addr & 0x3;

      if (i > 0)
      {
         i = 4 - i;

         if (_gfs_dedicated_buffer.free_size >= i) // consider offset for 4-byte aligned new free address
         {
            _gfs_dedicated_buffer.free_addr += i;
            _gfs_dedicated_buffer.free_size -= i;
         }
         else
         {
            _gfs_dedicated_buffer.free_addr += _gfs_dedicated_buffer.free_size;
            _gfs_dedicated_buffer.free_size = 0;
         }
      }

      // register task id
      _gfs_dedicated_buffer.allocated_task = task_id;
   }

MTBufAlloc_Exit:

   fs_lock_free_mutex(_gfs_lock_common);

   return size;
}


void RTFAPI MTBufFree(unsigned int size, unsigned char **buf)
{
   kal_uint8   i;
   kal_taskid  task_id;

   if (NULL == *buf || 0 == size)
   {
      *buf = NULL;
      return;
   }

   fs_lock_get_mutex(_gfs_lock_common, FS_INFINITE);

   // Check 1. Owner task
   task_id = kal_get_current_thread_ID();

   if (task_id != _gfs_dedicated_buffer.allocated_task)
   {
      fs_assert_local(0);
   }

   // Check 2. Allocation times
   i = _gfs_dedicated_buffer.allocated_times;

   if (0 == i)
   {
      fs_assert_local(0);
   }

   // Check 3. Allocated size

   i = i - 1; // get index

   if (size != _gfs_dedicated_buffer.allocated_size[i])
   {
      fs_assert_local(0);
   }

   // Check 4. Allocated address
   if ((kal_uint32)(*buf) != _gfs_dedicated_buffer.allocated_addr[i])
   {
      fs_assert_local(0);
   }

   // update free memory information
   size = _gfs_dedicated_buffer.free_addr - _gfs_dedicated_buffer.allocated_addr[i];
   _gfs_dedicated_buffer.free_size += size;
   _gfs_dedicated_buffer.free_addr = _gfs_dedicated_buffer.allocated_addr[i];

   // free memory
   _gfs_dedicated_buffer.allocated_size[i] = _gfs_dedicated_buffer.allocated_addr[i] = 0;
   _gfs_dedicated_buffer.allocated_times--;

   *buf = NULL;

   if (0 == _gfs_dedicated_buffer.allocated_times)
   {
      _gfs_dedicated_buffer.allocated_task = 0;
   }

   fs_lock_free_mutex(_gfs_lock_common);
}

// Interval Buffer

#ifdef __FS_INTERVAL_BUFFER__

struct fs_interval_buffer;
typedef struct
{
    kal_uint32 *address;
    kal_uint32  size;
    RTFDevice  *dev;
    kal_uint32  lba_addr;
    kal_uint32  lba_length;
    kal_uint32  handle;
    kal_uint8   valid;
} fs_interval_buffer;

fs_interval_buffer gfs_intbuf = {0};

// Initialization Funtion
int fs_srv_buf_alloc(void)
{
    kal_uint32 len;
    kal_int32 result=FS_NO_ERROR;

    gfs_intbuf.lba_addr   = 0;
    gfs_intbuf.lba_length = 0;
    gfs_intbuf.address    = NULL;
    gfs_intbuf.size       = FS_DEDICATED_BUFFER_SIZE;

    // Use FS buffer
    len=MTBufAlloc(gfs_intbuf.size, (unsigned char **)&(gfs_intbuf.address), FS_INT_DBUF_ALLOC_PRECISE);

    if (len==0) {
           gfs_intbuf.address = NULL;
           result=FS_FAIL_GET_MEM;
    }

    return result;
}

// Finalization Function
int fs_srv_buf_final(void)
{
    kal_int32 result=FS_NO_ERROR;

    if (gfs_intbuf.address!=NULL)   {
        MTBufFree(gfs_intbuf.size, (unsigned char **)&(gfs_intbuf.address));
    }

    return result;
}

void *fs_srv_buf_get(RTFDevice * Dev, RTFSector Sector, UINT Flags)
{
    void *buf_ptr=NULL;
    kal_int32 result=FS_NO_ERROR;
    kal_uint32 sector_offset;

    if (gfs_intbuf.address == NULL) {
        return GetBuffer(Dev, Sector, Flags);
    }

    if ( (gfs_intbuf.lba_length==0) ||
         (Sector < gfs_intbuf.lba_addr) ||
         (Sector >= (gfs_intbuf.lba_addr + gfs_intbuf.lba_length)))   {

        result=rtf_core_read_sectors(Dev, gfs_intbuf.address, Sector, (FS_DEDICATED_BUFFER_SIZE/SECTOR_SIZE), NO_RAISE);
        gfs_intbuf.lba_addr=Sector;
        gfs_intbuf.lba_length=(FS_DEDICATED_BUFFER_SIZE/SECTOR_SIZE);
    }

    if (result < FS_NO_ERROR)   {
        gfs_intbuf.lba_addr=0;
        gfs_intbuf.lba_length=0;
    }
    else {
        sector_offset = Sector - gfs_intbuf.lba_addr;
        buf_ptr = (void*)((kal_uint8*)gfs_intbuf.address + (sector_offset * SECTOR_SIZE));
    }

    return buf_ptr;
}

#endif // __FS_INTERVAL_BUFFER__
#endif /* __FS_DEDICATED_BUFFER__ */

#endif // !defined(__FS_CACHE_SUPPORT__) || defined(__FS_CARD_DOWNLOAD__)

///////////////////////////////////////////////////////////////////////////////
/// MT File System Cache
///////////////////////////////////////////////////////////////////////////////
#if defined(__FS_CACHE_SUPPORT__) && !defined(__FS_CARD_DOWNLOAD__)

//-----------------------------------------------------------------------------
// Definitions
//-----------------------------------------------------------------------------

// Definition of Flags
// b0-b7: Legacy RTF buffer type
#define B_VALID                   0x00000001            // buffer has valid data
#define B_DIRTY                   0x00000002            // buffer has valid data and must be written to disk
#define B_INUSE                   0x00000004            // buffer is being accessed by RTFiles
#define B_BUSY                    0x00000008            // buffer is being accessed by a device driver

// b8-b16: recoverable flag for MSP write
#define FS_BFLAG_RECOVERABLE      0x00000100
#define FS_BFLAG_RECOVERABLE_MASK 0x0000FF00

/* b17-b24: Buffer Type Enumeration (defined in fs_gprot.h)
FS_BTYPE_UNKNOWN                  0x00000000
FS_BTYPE_SYS                      0x00010000
FS_BTYPE_FAT                      0x00020000
FS_BTYPE_DAT                      0x00030000
FS_BTYPE_DIR                      0x00040000
FS_BTYPE_RAW                      0x00050000
FS_BTYPE_MASK                     0x00FF0000

// b25-b31: Trace Type Flags (defined in fs_utility.h)
MT_IO_TRACE_READ                  0x00000000
MT_IO_TRACE_WRITE                 0x01000000
MT_IO_TRACE_CACHE_IN              0x02000000
MT_IO_TRACE_CACHE_OUT             0x04000000
*/

//-----------------------------------------------------------------------------
// Variables
//-----------------------------------------------------------------------------
// Dedicate Buffer
#ifdef __FS_DEDICATED_BUFFER__
static FS_BufferList gFS_BufferListDedicate = {0};
kal_uint32 gFS_DedicateBufferConsumption=0;
#endif

// Cache Memory Pool
KAL_ADM_ID  gFS_CachePoolID;
extern BYTE gFS_CachePoolMem[];
static FS_BufferList gFS_BufferListCache = {0};
extern UINT FS_CACHE_POOL_SIZE;
extern UINT FS_CACHE_SIZE;

//-----------------------------------------------------------------------------
// Function Prototypes
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Initialization
//-----------------------------------------------------------------------------
void MTCacheInit(void);
void MTCacheConfig(kal_uint32 CacheSize);

//-----------------------------------------------------------------------------
// Layer 1: Interface to File System
//-----------------------------------------------------------------------------
// (Macro defined in rtfbuf.h)
// #define GetBuffer(Dev, SectorAddress, Flags)                      CacheBufferFill(Dev, NULL, SectorAddress, Flags, 0)
// #define GetBufferDIR(Dev, SectorAddress, PrefetchSectors)         CacheBufferFill(Dev, NULL, SectorAddress, FS_BTYPE_DIR, PrefetchSectors)
// #define GetBufferDIRNoLoad(Dev, SectorAddress)                    CacheBufferFill(Dev, NULL, SectorAddress, FS_BTYPE_DIR | NO_LOAD, 1)
// #define GetBufferFAT(Drive, SectorAddress, PrefetchSectors)       CacheBufferFill(Drive->Dev, Drive, SectorAddress, FS_BTYPE_FAT, PrefetchSectors)
void FreeBuffer(RTFDevice *TargetDevice);
void *SearchBuffer(RTFDevice * Dev, RTFSector Sector);
void DiscardBuffer(RTFDevice *TargetDevice);
void RTFAPI CommitBuffer(RTFDevice *TargetDevice);
void RTFAPI DiscardAllBuffers(RTFDevice *TargetDevice);
void RTFAPI DiscardBuffersRange(RTFDevice * TargetDevice, RTFSector SectorAddress, RTFSector SectorLength, int Commit);
void RTFAPI FlushAllBuffers(RTFDevice * Dev);
void FlushFAT(RTFDevice * TargetDevice);
void RTFAPI FlushAllBuffersInGeometryOrder(RTFDevice * TargetDevice);
// Pre-fetch information
kal_uint32 GetFATPrefetchSectors(RTFile *f);
kal_uint32 GetFATPrefetchSectorsEx(RTFDrive *drive, kal_uint32 offset);
// Dedicate Buffer interface
int RTFAPI MTBufCheckRange(unsigned int addr);
void RTFAPI MTBufFree(unsigned int size, unsigned char **buf);
int RTFAPI MTBufAlloc(unsigned int size, unsigned char **buf, unsigned int flag);

//-----------------------------------------------------------------------------
// Layer 2: Cache Operation
//-----------------------------------------------------------------------------
void *CacheBufferFill(RTFDevice *TargetDevice, RTFDrive *TargetDrive, RTFSector SectorAddress, UINT Flags, kal_int32 CacheBufferFill);
void  CacheBufferFlushAll(void);
static kal_int32 CacheAllocatableSectors(void);
static void CacheBufferFree(RTFBuffer *ptr);
static RTFBuffer *CacheBufferAllocate(kal_uint32 Flags, kal_uint32 SectorLength);
static void CacheBufferFlush(RTFBuffer *ptr);
static void CacheBufferFlushByLRU(RTFDevice *TargetDevice, kal_uint32 Flags, kal_uint32 DemandSectorLength);
static void CacheBufferFlushByType(RTFDevice * TargetDevice, kal_int32 Flags);
static void CacheBufferDiscard(RTFBuffer *ptr);
static kal_int32 BufferIntervalCheck(RTFBuffer *B, RTFSector SectorAddress, RTFSector SectorLength);
static kal_int32 IsCacheFull(RTFDevice *Dev);


//-----------------------------------------------------------------------------
// Layer 2, Object: List Structure
//-----------------------------------------------------------------------------
static void INTERN InsertToHead(FS_BufferList *List, RTFBuffer * B);
static void INTERN InsertToTail(FS_BufferList *List, RTFBuffer * B);
static void INTERN RemoveFromList(FS_BufferList *List, RTFBuffer * B);
static RTFBuffer *INTERN SearchListByData(FS_BufferList *List, void * DataPtr);

//-----------------------------------------------------------------------------
// Layer 2, Object: Cache Profile
//-----------------------------------------------------------------------------
void CacheProfileConsume(RTFBuffer *ptr);
void CacheProfileFree(RTFBuffer *ptr);
kal_int32 CacheProfileGetLineSize(RTFDevice *TargetDevice, kal_uint32 Flags);
kal_int32 CacheProfileGetConsumedSize(RTFDevice *TargetDevice, kal_uint32 Flags);
kal_int32 CacheProfileAllocatable(RTFDevice *TargetDevice, kal_uint32 Flags, kal_uint32 DemandSectorLength);

//-----------------------------------------------------------------------------
// Layer 3: Device Access
//-----------------------------------------------------------------------------
static void INTERN ReadBuffer(RTFBuffer * B, UINT Flags);
static void INTERN WriteBuffer(RTFBuffer * B);

//-------------------------------------------------- End of Function Prototypes

#ifndef FS_CACHE_TRACE
#undef fs_util_trace_info4
#define fs_util_trace_info4(...)
#endif

//-----------------------------------------------------------------------------
// Function Body
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Initialization
//-----------------------------------------------------------------------------
//-----------------------------------------------
void MTCacheInit(void)
{
    RTFDevice *Dev;

    // init function of buffers
    gFS_CachePoolID = kal_adm_create(gFS_CachePoolMem, FS_CACHE_POOL_SIZE, NULL, KAL_TRUE);

    // First initialization
    for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)    {
        kal_mem_set(&Dev->DevData.CacheProfile, 0, sizeof(FS_CacheProfile));
    }

    // default cache size is entire pool
    MTCacheConfig(FS_CACHE_SIZE);
}

//-----------------------------------------------
void MTCacheConfig(kal_uint32 CacheSize)
{
    RTFDevice *Dev;
    kal_uint32 factor, nand_factor, card_factor;

    // 32KB: Card(8+8) NAND(2+2) Others(12KB)
    // 16KB: Card(4+4) NAND(1+1) Others(6KB)
    // 8KB:  All 1s

    fs_util_trace_info1(TRACE_FUNC, FS_CACHE_CONFIG, CacheSize/1024, NULL);

    card_factor=fs_util_floor_power_of_two(CacheSize/512/4);
    nand_factor=fs_util_floor_power_of_two(CacheSize/512/16);

    // Limit NAND flash maximum line size to 1KB to speed up first boot time.
    if (nand_factor) nand_factor=1;

    for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)    {
        // To support runtime-configuration, modify only line size, keep consumed size
        kal_mem_set(&Dev->DevData.CacheProfile.line_size, 0, sizeof(kal_int16)*FS_BTYPE_INDEX(FS_BTYPE_MAX));

        if (Dev->DeviceFlags & FS_DEVICE_NAND_FLASH) {
            factor=nand_factor;  // NAND: max 2 sectors
        }
        else if (Dev->DeviceFlags & FS_DEVICE_REMOVABLE) {
            factor=card_factor;  // Card: 16 sectors (1/4, 32KB = 8KB*2)
        }
        else {
            factor=0;  // NOR: 1 sector
        }

        Dev->DevData.CacheProfile.line_size[FS_BTYPE_INDEX(FS_BTYPE_FAT)] = factor;   // 2^N sectors
        Dev->DevData.CacheProfile.line_size[FS_BTYPE_INDEX(FS_BTYPE_DIR)] = factor;   // 2^N sectors
    }
}
//------------------------------------------------------- End of Initialization

//-----------------------------------------------------------------------------
// Layer 1: Interface to File System
//-----------------------------------------------------------------------------

/*******************************************************************//**
 * Unlink specified device's inuse buffer
 *
 * @par Category:
 * File System
 *
 * this is called by UnlockDevice, GetBuffer, SearchBuffer and SafeUnlock
 **********************************************************************/
void FreeBuffer(RTFDevice * Dev)
{
   if (Dev->DevData.B)
   {
      Dev->DevData.B->Flags &= ~B_INUSE;  // Mark as NOT in-use, keep it in the cache
      Dev->DevData.B = NULL;
   }
}

/*******************************************************************//**
 * Discard device's in-use buffer
 *
 * @par Category:
 * File System
 *
 * This function handles the device structure. Buffer structure is handled by DiscardOtherBuffer().
 **********************************************************************/
void DiscardBuffer(RTFDevice * Dev)
{
   if (Dev->DevData.B)
   {
      CacheBufferDiscard(Dev->DevData.B);
      Dev->DevData.B = NULL;
   }
}

/*******************************************************************//**
 * Commit device's INUSE buffer
 *
 * @par Category:
 * File System
 **********************************************************************/
void RTFAPI CommitBuffer(RTFDevice * Dev)
{
    RTFBuffer *B;

    B = Dev->DevData.B;

    // write the in-use buffer if it is dirty
    if (B->Flags& B_DIRTY)   {
        WriteBuffer(B);
    }
}

/*******************************************************************//**
 * Flush all buffers occupied by a specified device
 *
 * @par Category:
 * File System
 *
 * @note
 * Keep device's B pointer after flush all its buffers.
 **********************************************************************/
void RTFAPI FlushAllBuffers(RTFDevice * Dev)
{
    FlushAllBuffersInGeometryOrder(Dev);
}

/*******************************************************************//**
 * Flush all FAT data buffer of a specified device
 *
 * @par Category:
 * File System
 **********************************************************************/
void FlushFAT(RTFDevice * TargetDevice)
{
    CacheBufferFlushByType(TargetDevice, FS_BTYPE_FAT);
}

/*******************************************************************//**
 * Flush all buffers of a specified device by the order of logical sector number
 *
 * @par Category:
 * File System
 *
 * @note
 * In FAT12/16, FAT will always be committed before directory entry!
 **********************************************************************/
void RTFAPI FlushAllBuffersInGeometryOrder(RTFDevice * TargetDevice)
{
    // Write buffer in following order
    // Cluster > FAT > Directory Entry > Others
    CacheBufferFlushByType(TargetDevice, FS_BTYPE_DAT);
    CacheBufferFlushByType(TargetDevice, FS_BTYPE_FAT);
    CacheBufferFlushByType(TargetDevice, FS_BTYPE_DIR);
    CacheBufferFlushByType(TargetDevice, FS_BTYPE_MASK);
}

//-----------------------------------------------
void *SearchBuffer(RTFDevice * Dev, RTFSector Sector)
{
    // Return the data buffer pointer to to the sector buffer
    // If it was not exist in cache, return NULL

    void *result = NULL;
    RTFBuffer *ptr, *next = NULL;

    for (ptr=gFS_BufferListCache.FirstBuffer; ptr!=NULL; ) {
        next=ptr->Next;

        /*
        if (ptr->Dev != Dev) continue;
        if (Sector < ptr->SectorAddress) continue;
        if ((ptr->SectorAddress + ptr->SectorLength) <= Sector) continue;
        */
        if (ptr->Dev == Dev)
            if ((ptr->SectorAddress <= Sector) &&
                ((ptr->SectorAddress + ptr->SectorLength) > Sector)) {
                Dev->DevData.B = ptr;
                result = ((kal_uint8*)(ptr->Data) + (SECTOR_SIZE* (Sector - ptr->SectorAddress)));
                fs_util_trace_info4(TRACE_GROUP_5, FS_CACHE_HIT, (kal_uint32)ptr->SectorAddress, (kal_uint32)ptr->SectorLength, (kal_uint32)ptr, NULL, NULL);

                // Move this buffer to list head (Most Recently Used)
                if (gFS_BufferListCache.FirstBuffer != ptr) {
                    RemoveFromList(&gFS_BufferListCache, ptr);
                    InsertToHead(&gFS_BufferListCache, ptr);
                }
                break;
            }
        ptr=next;
    }

    return result;
}

//-----------------------------------------------
void SetDirty(RTFDevice * Dev)
{
   RTFBuffer * B = Dev->DevData.B;

   // Mark current in use buffer as dirty B_DIRTY
   B->Flags |= B_DIRTY;

   // Mark recoverable_flag as RTF_NORMAL_WRITE
   // B->Flags &= ~FS_BFLAG_RECOVERABLE;

   // If this is the last buffer (cache full & others all dirty)
   // Flush it directedly
   // Send cache thrashing warning
   if (IsCacheFull(Dev))    {
       CacheBufferFlush(B);
   }
}

//-----------------------------------------------
void RTFAPI DiscardAllBuffers(RTFDevice * TargetDevice)
{
    RTFBuffer *ptr, *prev;
    // discard all buffers without commit

    // For All Buffers
    for (ptr=gFS_BufferListCache.LastBuffer; ptr!=NULL; )  {
        prev=ptr->Prev;
        // The same device
        if ((ptr->Dev == TargetDevice))  {
           CacheBufferDiscard(ptr);
        }
        ptr=prev;
    }
}

//-----------------------------------------------
void RTFAPI DiscardBuffersRange(RTFDevice * TargetDevice, RTFSector SectorAddress, RTFSector SectorLength, int Commit)
{
    RTFBuffer *ptr, *prev;
    // Discard buffers in range,
    // If Commit!=0, wirte the dirty buffers

    // For All Buffers
    for (ptr=gFS_BufferListCache.LastBuffer; ptr!=NULL; )  {
        prev=ptr->Prev;
        // The same device
        if ((ptr->Dev == TargetDevice))  {
            // IntervalCheck
            if (BufferIntervalCheck(ptr, SectorAddress, SectorLength))  {
                if (Commit) CacheBufferFlush(ptr);
                else CacheBufferDiscard(ptr);
            }
        }
        ptr=prev;
    }
}

//-----------------------------------------------
kal_uint32 GetFATPrefetchSectors(RTFile *f)
{
    return GetFATPrefetchSectorsEx(f->Drive, (f->DirEntry.Dir.FileSize - f->FilePointer));
}

//-----------------------------------------------
kal_uint32 GetFATPrefetchSectorsEx(RTFDrive *drive, kal_uint32 offset)
{
    kal_uint32 clusters;
    kal_uint32 fat_sectors;

    clusters = offset >> drive->ClusterShift;
    fat_sectors = (clusters * (drive->FATType >> 2)) >> 10 + 1;
    return fat_sectors;
}


#ifdef __FS_DEDICATED_BUFFER__
// Note: FS Dedicate buffer shares the memory from FS Cache.
// Use RTFLock instead of common lock, since FS Cache is protected by RTFLock
//-----------------------------------------------
int RTFAPI MTBufCheckRange(unsigned int addr)
{
    RTFBuffer *ptr;

    RTFSYSLockMutex(RTFLock, RTF_INFINITE);
    ptr=SearchListByData(&gFS_BufferListDedicate, (void*)addr);
    RTFSYSFreeMutex(RTFLock);
    if (ptr==NULL) return 0;
    return 1;
}

//-----------------------------------------------
int RTFAPI MTBufAlloc(unsigned int size, unsigned char **buf, unsigned int flag)
{
    RTFBuffer *ptr=NULL;
    int SectorLength;

    RTFSYSLockMutex(RTFLock, RTF_INFINITE);

    /*
    * check
    * 1. If allocator is the correct task?
    * 2. If free size is available?
    * 3. If allocation times is valid?
    */

    // 1. Check Total Dedicate Buffer Consunmption
    //    Downgrade cacheline size at first time (bound by size)
    // 2. Flush All Buffers
    // 3. Allocate New Buffer

    if ((((gFS_DedicateBufferConsumption + size) > FS_DEDICATED_BUFFER_SIZE) && (flag == FS_INT_DBUF_ALLOC_PRECISE)) ||
          (gFS_DedicateBufferConsumption == FS_DEDICATED_BUFFER_SIZE)) {
         *buf = NULL;
         size = 0;

         goto MTBufAlloc_Exit;
    }

    // First allocation
    if ((gFS_DedicateBufferConsumption == 0) && (size>0))  {
        MTCacheConfig(FS_CACHE_SIZE - FS_DEDICATED_BUFFER_SIZE);
        CacheBufferFlushAll();
    }

    if (flag == FS_INT_DBUF_ALLOC_GREEDY)  {
        size = FS_DEDICATED_BUFFER_SIZE - gFS_DedicateBufferConsumption;
    }
    else {
    // FS_INT_DBUF_ALLOC_PRECISE
    }

    SectorLength = (size+SECTOR_SIZE-1) / SECTOR_SIZE;

    do {
        // If not enough, select & flush victim buffer
        CacheBufferFlushByLRU(NULL, FS_BTYPE_DEDICATE, SectorLength);
        // Allocate Buffer from ADM
        ptr=CacheBufferAllocate(FS_BTYPE_DEDICATE, SectorLength);
    } while (ptr==NULL);

    gFS_DedicateBufferConsumption += (SectorLength * SECTOR_SIZE);

    *buf = ptr->Data;
    ptr->SectorAddress = (kal_uint32)kal_get_current_thread_ID();
    ptr->SectorLength = SectorLength;

    // Insert to Dedicate Buffer List
    InsertToHead(&gFS_BufferListDedicate, ptr);

MTBufAlloc_Exit:
    RTFSYSFreeMutex(RTFLock);
    return size;
}

//-----------------------------------------------
void RTFAPI MTBufFree(unsigned int size, unsigned char **buf)
{
   RTFBuffer *ptr=NULL;
   int SectorLength;
   kal_taskid  task_id;

   if (NULL == *buf || 0 == size)
   {
      *buf = NULL;
      return;
   }

   RTFSYSLockMutex(RTFLock, RTF_INFINITE);

   task_id = kal_get_current_thread_ID();
   SectorLength = (size+SECTOR_SIZE-1) / SECTOR_SIZE;

   ptr = SearchListByData(&gFS_BufferListDedicate, *buf);

   if (ptr!=NULL)   {
        // Check: Owner task
        if ((kal_uint32)task_id != ptr->SectorAddress) {
            fs_assert_local(0);
        }

        // Check: Allocated size
        if (SectorLength != ptr->SectorLength)   {
            fs_assert_local(0);
        }

        gFS_DedicateBufferConsumption =  gFS_DedicateBufferConsumption - (SectorLength * SECTOR_SIZE);
        RemoveFromList(&gFS_BufferListDedicate, ptr);
        CacheBufferFree(ptr);

        // Restore Cache Configuration
        if (gFS_DedicateBufferConsumption == 0) {
            MTCacheConfig(FS_CACHE_SIZE);
        }
       *buf = NULL;
   }
   else {  // The targe buffer is not exist in the buffer list, double free.
        fs_assert_local(0);
   }

   RTFSYSFreeMutex(RTFLock);
}

#endif /* __FS_DEDICATED_BUFFER__ */


//------------------------------------ End of Layer 1: Interface to File System

//-----------------------------------------------------------------------------
// Layer 2: Cache Operation
//-----------------------------------------------------------------------------
//-----------------------------------------------
static kal_int32 CacheAllocatableSectors(void)
{
    kal_int32 max_alloc_size;

    // Query Allocatable Space in Pool
    max_alloc_size = kal_adm_get_max_alloc_size(gFS_CachePoolID);

    // Subtract buffer overhead
    max_alloc_size = max_alloc_size - sizeof(RTFBuffer);
    if (max_alloc_size < 0) return 0;

    // Convert bytes to sector
    max_alloc_size = max_alloc_size>> 9;

    return max_alloc_size;
}


//-----------------------------------------------
static kal_int32 IsCacheFull(RTFDevice *Dev)
{
    RTFBuffer *ptr;

    if (CacheAllocatableSectors() > 0) return 0;

    for (ptr=gFS_BufferListCache.FirstBuffer; ptr!=NULL; ptr=ptr->Next) {
        if (ptr->Flags & B_BUSY) continue;
        if ((ptr->Flags & (B_DIRTY | B_INUSE)) == 0) return 0;
        if (ptr->Dev == Dev) return 0;
    }

    return -1;
}

//-----------------------------------------------
static void CacheBufferFree(RTFBuffer *ptr)
{
    fs_util_trace_info4(TRACE_GROUP_5, FS_CACHE_DISCARD, (kal_uint32)ptr->SectorAddress, (kal_uint32)ptr->SectorLength, (kal_uint32)ptr, NULL, NULL);
    if (ptr->Dev != NULL) CacheProfileFree(ptr);
    kal_mem_set(ptr, 0, sizeof(RTFBuffer));
    kal_adm_free(gFS_CachePoolID , ptr);
}

//-----------------------------------------------
static RTFBuffer *CacheBufferAllocate(kal_uint32 Flags, kal_uint32 SectorLength)
{
    RTFBuffer *ptr;
    kal_uint32 allocate_size;

    allocate_size = (SectorLength * SECTOR_SIZE) + sizeof(RTFBuffer);

    if (SectorLength > 1) {
        // Large buffers are alloacted from topmost address
        // ptr=kal_adm_alloc_topmost(gFS_CachePoolID , allocate_size, 4);
        ptr=kal_adm_alloc_c_topmost(gFS_CachePoolID , allocate_size, 32);
    }
    else {
        // Small buffers are allocated from lower addresss
        // ptr=kal_adm_alloc(gFS_CachePoolID , allocate_size);
        ptr=kal_adm_alloc_cacheable(gFS_CachePoolID , allocate_size, PAGE_SIZE_4KB);
    }

    if (ptr!=NULL)  {
        kal_mem_set(ptr, 0, sizeof(RTFBuffer));
        ptr->Data = ((kal_uint8*)ptr) + sizeof(RTFBuffer);
    }

    return ptr;
}

//-----------------------------------------------
static void CacheBufferDiscard(RTFBuffer *ptr)
{
    if (ptr->Data!=NULL)    {
        RemoveFromList(&gFS_BufferListCache, ptr);
        CacheBufferFree(ptr);
    }
}

//-----------------------------------------------
static void CacheBufferFlush(RTFBuffer *ptr)
{
    if (ptr->Data!=NULL)    {
        RemoveFromList(&gFS_BufferListCache, ptr);

        if (ptr->Flags & B_DIRTY)   {
            WriteBuffer(ptr);
        }

        CacheBufferFree(ptr);
    }
}

//-----------------------------------------------
void CacheBufferFlushAll(void)
{
    RTFDevice *Dev;
    kal_uint32 i=0;

    fs_util_trace_info0(TRACE_FUNC, FS_CACHE_FLUSH_ALL, NULL);

    // To Avoid Dead Lock, RTF Lock Must be released before taking other device locks.
    // <Dead Lock Scenario>
    // Task A: Holding Device 0 Lock & RTF Lock, Waiting Device 1 Lock - CacheBufferFlushAll()
    // Task B: Holding Device 1 Lock, Waiting RTF Lock - rtf_core_write_sectors()
    // => Task A must release RTF Lock to avoid Dead Lock.

    if (kal_query_systemInit() == KAL_FALSE) {
        while (RTFSYSOwnMutex(RTFLock))    {
            i++;
            RTFSYSFreeMutex(RTFLock);
        }
    }

    for (Dev = gFS_DeviceList; Dev->DeviceType; Dev++)  {
        // 1. Get Device Lock & RTF Lock
        RTFSYSLockMutex(Dev->DevData.Lock, RTF_INFINITE);
        RTFSYSLockMutex(RTFLock, RTF_INFINITE);
        // 2. Flush Buffer in Geometry Order
        FlushAllBuffersInGeometryOrder(Dev);
        // 3. Release Device Lock & RTF Lock
        RTFSYSFreeMutex(RTFLock);
        RTFSYSFreeMutex(Dev->DevData.Lock);
    }

    while (i!=0) {
        i--;
        RTFSYSLockMutex(RTFLock, RTF_INFINITE);
    }
}

//-----------------------------------------------
static void CacheBufferFlushByType(RTFDevice * TargetDevice, kal_int32 Flags)
{
    RTFBuffer *ptr, *prev;

    // Write all FAT buffers
    for (ptr=gFS_BufferListCache.LastBuffer; ptr!=NULL; )  {
        prev=ptr->Prev;
        if ((ptr->Dev == TargetDevice) && (ptr->Flags & Flags))  {
            CacheBufferFlush(ptr);
        }
        ptr=prev;
    }
}

//-----------------------------------------------
static kal_int32 BufferIntervalCheck(RTFBuffer *B, RTFSector SectorAddress, RTFSector SectorLength)
{
    if ( ((B->SectorAddress + B->SectorLength) <= SectorAddress) ||   // Mismatch case 1: Buffer is before the given interval
         ((SectorAddress + SectorLength) <= B->SectorAddress)) {      // Mismatch case 2: Buffer is after the given interval
        return 0;
    }

    return  (SectorAddress - B->SectorAddress);
}

//-----------------------------------------------
// LRU Priority
// 1. Valid buffer
// 2. Same device's dirty buffer
// 3. Flush All Buffer
static void CacheBufferFlushByLRU(RTFDevice *TargetDevice, kal_uint32 Flags, kal_uint32 DemandSectorLength)
{
    RTFBuffer *ptr, *prev;
    kal_uint32 btype;

    btype=Flags & FS_BTYPE_MASK;

    // Becase of deivce lock, a deivce will only have one FAT and one DIR buffer at a time.
    // Flush the buffer of the same type (FAT/DIR) in the same device
    if ((btype == FS_BTYPE_FAT) || (btype == FS_BTYPE_DIR)) {
            if (CacheProfileAllocatable(TargetDevice, Flags, DemandSectorLength) <0)

                for (ptr=gFS_BufferListCache.LastBuffer; ptr!=NULL; )  {
                    prev=ptr->Prev;
                    if ((ptr->Dev == TargetDevice) && ((ptr->Flags & FS_BTYPE_MASK) == btype) && (ptr->SectorLength > 1))   {
                        fs_util_trace_info4(TRACE_GROUP_5, FS_CACHE_LRU, (kal_uint32)ptr->SectorAddress, (kal_uint32)ptr->SectorLength, (kal_uint32)ptr, NULL, NULL);
                        CacheBufferFlush(ptr);
                        if (CacheProfileAllocatable(TargetDevice, Flags, DemandSectorLength) >=0 ) break;

                    }
                    ptr=prev;
                }
        // Error Handling, The FAT/DIR buffer squeeze the normal buffers
    }

    //  Already have enough space, return directly
    if (CacheAllocatableSectors() >= DemandSectorLength) return;

    // 1. Flush valid buffers
    for (ptr=gFS_BufferListCache.LastBuffer; ptr!=NULL; )  {
        prev=ptr->Prev;
        if (((ptr->Flags & B_INUSE) == 0) && ((ptr->Flags & B_DIRTY) == 0))   {
            fs_util_trace_info4(TRACE_GROUP_5, FS_CACHE_LRU, (kal_uint32)ptr->SectorAddress, (kal_uint32)ptr->SectorLength, (kal_uint32)ptr, NULL, NULL);
            CacheBufferFlush(ptr);
            if (CacheAllocatableSectors() >= DemandSectorLength) return;
        }
        ptr=prev;
    }

    // 2. Flush dirty buffers of the same device
    for (ptr=gFS_BufferListCache.LastBuffer; ptr!=NULL; )  {
        prev=ptr->Prev;
        if ((ptr->Dev == TargetDevice) && ((ptr->Flags & B_INUSE) == 0))  {
            fs_util_trace_info4(TRACE_GROUP_5, FS_CACHE_LRU, (kal_uint32)ptr->SectorAddress, (kal_uint32)ptr->SectorLength, (kal_uint32)ptr, NULL, NULL);
            CacheBufferFlush(ptr);
            if (CacheAllocatableSectors() >= DemandSectorLength) return;
        }
        ptr=prev;
    }

    // 3. Error Handling: Flush All Buffers
    CacheBufferFlushAll();

    return;
}

//-----------------------------------------------
void *CacheBufferFill(RTFDevice *TargetDevice, RTFDrive *TargetDrive, RTFSector SectorAddress, UINT Flags, kal_int32 PrefetchSectors)
{
    int SectorLength;
    void *result;
    RTFBuffer *ptr=NULL;

    // Get buffer of the given sector address

    // Search for the demeand buffer in the list
    result=SearchBuffer(TargetDevice, SectorAddress);

    // Hit:  Return
    if (result!=NULL) return result;

    // Miss: Decide Prefetch Read Length From The Flags
    SectorLength = CacheProfileGetLineSize(TargetDevice, Flags);

    // Align the SectorLength to Phyiscal Boundary
    SectorLength = SectorLength - (SectorAddress % SectorLength);

    // Limit Prefetch Sectors
    if ((PrefetchSectors>0) && (SectorLength>PrefetchSectors))  {
        SectorLength = PrefetchSectors;
    }

    // Search buffers covered in the same range
    // -> Flush any buffer, if any of them hits
    DiscardBuffersRange(TargetDevice, SectorAddress, SectorLength, 1);

    do {
        // If not enough, select & flush victim buffer
        CacheBufferFlushByLRU(TargetDevice, Flags, SectorLength);

        // Allocate Buffer from ADM
        ptr=CacheBufferAllocate(Flags, SectorLength);
    } while (ptr==NULL);

    ptr->Dev = TargetDevice;
    ptr->Drive = TargetDrive;
    ptr->SectorAddress = SectorAddress;
    ptr->SectorLength = SectorLength;

    // Read Buffer
    if (Flags & NO_LOAD)    {
        ptr->Flags = (B_VALID | (Flags & FS_BTYPE_MASK));
    }
    else {
        ReadBuffer(ptr, Flags);
    }

    CacheProfileConsume(ptr);

    // Insert to LRU list
    InsertToHead(&gFS_BufferListCache, ptr);

    // Set in-use buffer
    TargetDevice->DevData.B = ptr;

    return ptr->Data;
}


//-----------------------------------------------------------------------------
// Layer 2, Object: List Structure
//-----------------------------------------------------------------------------
//-----------------------------------------------
static void INTERN InsertToHead(FS_BufferList *List, RTFBuffer * B)
{
    fs_util_trace_info4(TRACE_GROUP_5, FS_CACHE_LIST_INSERT, (kal_uint32)B->SectorAddress, (kal_uint32)B->SectorLength, (kal_uint32)B, NULL, NULL);

    if (List->FirstBuffer==NULL)  {
        List->LastBuffer = List->FirstBuffer = B;
    }
    else {
        B->Next=List->FirstBuffer;
        List->FirstBuffer->Prev=B;
        List->FirstBuffer=B;
    }
}

//-----------------------------------------------
static void INTERN InsertToTail(FS_BufferList *List, RTFBuffer * B)
{
    if (List->LastBuffer==NULL)   {
        List->LastBuffer = List->FirstBuffer = B;
    }
    else {
        B->Prev=List->LastBuffer;
        List->LastBuffer->Next=B;
        List->LastBuffer=B;
    }
}

//-----------------------------------------------
static void INTERN RemoveFromList(FS_BufferList *List, RTFBuffer * B)
{
    RTFBuffer *prev, *next;

    fs_util_trace_info4(TRACE_GROUP_5, FS_CACHE_LIST_REMOVE, (kal_uint32)B->SectorAddress, (kal_uint32)B->SectorLength, (kal_uint32)B, NULL, NULL);

    prev=B->Prev;
    next=B->Next;

    if (prev!=NULL) {
        prev->Next=next;
    }
    else {
        List->FirstBuffer = next;
    }

    if (next!=NULL) {
        next->Prev = prev;
    }
    else {
        List->LastBuffer = prev;
    }

    B->Prev = B->Next = NULL;
}

//-----------------------------------------------
static RTFBuffer *INTERN SearchListByData(FS_BufferList *List, void * DataPtr)
{
    RTFBuffer *ptr, *next = NULL;

    for (ptr=List->FirstBuffer; ptr!=NULL; ) {
        next=ptr->Next;
        if ((ptr->Data <= DataPtr) &&
            ((ptr->Data + ptr->SectorLength * SECTOR_SIZE) > DataPtr)) break;
        ptr=next;
    }
    return ptr;
}
//-------------------------------------- End of Layer 2, Object: List Structure

//-----------------------------------------------------------------------------
// Layer 2, Object: Cache Profile
//-----------------------------------------------------------------------------
//-----------------------------------------------
void CacheProfileConsume(RTFBuffer *ptr)
{
    FS_CacheProfile *dev_cache_profile = &ptr->Dev->DevData.CacheProfile;
    dev_cache_profile->consumed_size[FS_BTYPE_INDEX(ptr->Flags)] += ptr->SectorLength;
    return;
}

//-----------------------------------------------
void CacheProfileFree(RTFBuffer *ptr)
{
    FS_CacheProfile *dev_cache_profile = &ptr->Dev->DevData.CacheProfile;
    dev_cache_profile->consumed_size[FS_BTYPE_INDEX(ptr->Flags)] -= ptr->SectorLength;
    return;
}

//-----------------------------------------------
kal_int32 CacheProfileGetLineSize(RTFDevice *TargetDevice, kal_uint32 Flags)
{
    kal_int32 SectorLength;
    FS_CacheProfile *dev_cache_profile = &TargetDevice->DevData.CacheProfile;
    SectorLength = 1 << dev_cache_profile->line_size[FS_BTYPE_INDEX(Flags)];
    return SectorLength;
}

//-----------------------------------------------
kal_int32 CacheProfileGetConsumedSize(RTFDevice *TargetDevice, kal_uint32 Flags)
{
    kal_int32 Consumed;
    FS_CacheProfile *dev_cache_profile = &TargetDevice->DevData.CacheProfile;
    Consumed = dev_cache_profile->consumed_size[FS_BTYPE_INDEX(Flags)];
    return Consumed;
}

//-----------------------------------------------
kal_int32 CacheProfileAllocatable(RTFDevice *TargetDevice, kal_uint32 Flags, kal_uint32 DemandSectorLength)
{
    kal_int32 left;
    left=CacheProfileGetLineSize(TargetDevice, Flags) - CacheProfileGetConsumedSize(TargetDevice, Flags);
    return (1 + left - DemandSectorLength); // +1 to avoid cache trashing
}

//--------------------------------------- End of Layer 2, Object: Cache Profile


//-----------------------------------------------------------------------------
// Layer 3: Device Access
//-----------------------------------------------------------------------------
//-----------------------------------------------
static void INTERN ReadBuffer(RTFBuffer * B, UINT Flags)
{
   fs_util_time_init_with_duration();
   fs_util_time_start();

   XTRY
      case XCODE:
         B->Flags |= B_BUSY;
         rtf_core_read_sectors(B->Dev, B->Data, B->SectorAddress, B->SectorLength, 0);

         B->Flags |= B_VALID;
         break;

      default:
         InsertToTail(&gFS_BufferListCache, B);
         B->Flags &= ~B_INUSE;
         break;

      case XFINALLY:
         B->Flags &= ~B_BUSY;

         Flags=(Flags & FS_BTYPE_MASK);
         B->Flags |= Flags;

         fs_util_time_stop();
         fs_util_time_set_duration();

         fs_util_trace_device_io(B->Dev->DeviceFlags | MT_IO_TRACE_READ | MT_IO_TRACE_CACHE_OUT | Flags, B->SectorAddress, B->SectorLength, fs_util_time_query_duration());
         fs_util_trace_info4(TRACE_GROUP_5, FS_CACHE_READ, (kal_uint32)B->SectorAddress, (kal_uint32)B->SectorLength, (kal_uint32)B, NULL, NULL);

         break;
   XENDX
}

//-----------------------------------------------
static void INTERN WriteBuffer(RTFBuffer * B)
{
   RTFDevice *Dev;
   kal_uint32 Flags;
   fs_util_time_init_with_duration();
   fs_util_time_start();

   Dev=B->Dev;

   XTRY
      case XCODE:

         B->Flags |= B_BUSY;

         // recoverable_flag indicates if it has to use recoverablewritesector or not
         if (B->Flags & FS_BFLAG_RECOVERABLE)
           rtf_core_write_sectors(Dev, B->Data, B->SectorAddress, B->SectorLength, 0, RTF_RECOVERABLE_WRITE);
         else
           rtf_core_write_sectors(Dev, B->Data, B->SectorAddress, B->SectorLength, 0, RTF_NORMAL_WRITE);

         // clear the recoverable_flag
         B->Flags &= ~FS_BFLAG_RECOVERABLE;

         /* clear dirty flag */
         B->Flags &= ~B_DIRTY;

         // check if this is a FAT sector and we have to
         // take care of other FATs
         // We will ignore any errors here, but we do want
         // critical errors.
         {
            int i, FATs;

            if ((B->Drive) && ((Dev->DeviceFlags & RTF_DEVICE_SINGLE_FAT) == 0))
               FATs = B->Drive->FATCount;
            else
               FATs = 1;

            if (FATs > 1)
            {
               kal_uint32 flag_backup;
               flag_backup = B->Flags;
               B->Flags = B_VALID | B_INUSE | B_BUSY;
               for (i=1; i<FATs; i++)
               {
                  rtf_core_write_sectors(Dev, B->Data, B->SectorAddress + i * B->Drive->SectorsPerFAT, B->SectorLength, NO_RAISE, RTF_NORMAL_WRITE);
               }
               B->Flags = flag_backup;
            }
         }
         break;

      default: // only the first FAT can raise exceptions
         B->Flags &= ~B_INUSE;
         break;

      case XFINALLY:
         B->Flags &= ~B_BUSY;
         Flags = B->Flags & FS_BTYPE_MASK;

         fs_util_time_stop();
         fs_util_time_set_duration();
         fs_util_trace_device_io(Dev->DeviceFlags | MT_IO_TRACE_WRITE | MT_IO_TRACE_CACHE_OUT | Flags, B->SectorAddress, B->SectorLength, fs_util_time_query_duration());
         fs_util_trace_info4(TRACE_GROUP_5, FS_CACHE_WRITE, (kal_uint32)B->SectorAddress, (kal_uint32)B->SectorLength, (kal_uint32)B, NULL, NULL);

         break;
   XENDX

}
//----------------------------------------------- End of Layer 3: Device Access
#endif // defined(__FS_CACHE_SUPPORT__) && !defined(__FS_CARD_DOWNLOAD__)


