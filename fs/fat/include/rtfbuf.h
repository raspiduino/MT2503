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
 *   rtfbuf.h
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

/* RTFiles buffer management */

#ifndef __RTFBUF_H__
#define __RTFBUF_H__

#define BITS                  (8*sizeof(int))          // default # of bits in integer
#define FMAX                  (1 << (BITS/2))          // max number of file handles
#define UMAX                  ((1 << (BITS/2-1)) - 1)  // max Unique value for file handles

// flags specifying how buffers are loaded and errors should be handled
#define NO_RAISE     0x00000001
#define NO_CRITICAL  0x00000002
#define NO_LOAD      0x00000004
#define ALT_BUFFER   0x00000008

/*
 * Default buffer size for Count Free Cluster
 *
 * If no FS dedicated buffer, get 2 KB control buffer instead
 * !NOTE! Please do not change the size without discussing with control buffer's owner!
 */
#define FS_DEFAULT_BUFF_SIZE_COUNT_FREE_CLUSTER (2 FS_KB)
#define FS_DEFAULT_BUFF_SIZE_COPY_FILE          (2 FS_KB)

// Interface to File System
//-----------------------------------------------------------------------------
extern void FreeBuffer(RTFDevice * Dev);
extern void DiscardOtherBuffer(RTFBuffer * B);
extern void DiscardBuffer(RTFDevice * Dev);
extern void *SearchBuffer(RTFDevice * Dev, RTFSector Sector);
extern void SetDirty(RTFDevice * Dev);
extern void CommitBuffer(RTFDevice * Dev);
extern void DiscardAllBuffers(RTFDevice * Dev);
extern void DiscardBuffersRange(RTFDevice * Dev, RTFSector Sector, RTFSector Count, int Commit);
extern void FlushAllBuffers(RTFDevice * Dev);
extern void FlushFAT(RTFDevice * Dev);
extern void RTFAPI FlushAllBuffersInGeometryOrder(RTFDevice * Dev);

#if defined(__FS_CACHE_SUPPORT__) && !defined(__FS_CARD_DOWNLOAD__)
extern void MTCacheInit(void);
extern void *CacheBufferFill(RTFDevice *TargetDevice, RTFDrive *TargetDrive, RTFSector SectorAddress, UINT Flags, kal_int32 PrefetchSectors);
#define GetBuffer(Dev, SectorAddress, Flags)                      CacheBufferFill(Dev, NULL, SectorAddress, Flags, 0)
#define GetBufferDIR(Dev, SectorAddress, PrefetchSectors)         CacheBufferFill(Dev, NULL, SectorAddress, FS_BTYPE_DIR, PrefetchSectors)
#define GetBufferDIRNoLoad(Dev, SectorAddress)                    CacheBufferFill(Dev, NULL, SectorAddress, FS_BTYPE_DIR | NO_LOAD, 1)
#define GetBufferFAT(Drive, SectorAddress, PrefetchSectors)       CacheBufferFill(Drive->Dev, Drive, SectorAddress, FS_BTYPE_FAT, PrefetchSectors)
extern kal_uint32 GetFATPrefetchSectors(RTFile *f);
extern kal_uint32 GetFATPrefetchSectorsEx(RTFDrive *drive, kal_uint32 offset);
#define GetFATPrefetchSectorsByOffset(drive, offset)  ((((offset>>drive->ClusterShift)*(drive->FATType))>>12)+1)
#define SetRecoverableFlag(Dev, Flag)

// Cache Profile
extern void CacheProfileConsume(RTFBuffer *ptr);
extern void CacheProfileFree(RTFBuffer *ptr);
extern kal_int32 CacheProfileGetLineSize(RTFDevice *TargetDevice, kal_uint32 Flags);
extern kal_int32 CacheProfileGetConsumedSize(RTFDevice *TargetDevice, kal_uint32 Flags);
extern kal_int32 CacheProfileAllocatable(RTFDevice *TargetDevice, kal_uint32 Flags, kal_uint32 DemandSectorLength);
// Cache Operation
extern void CacheBufferFlushAll(void);

#else // defined(__FS_CACHE_SUPPORT__) && !defined(__FS_CARD_DOWNLOAD__)
extern void AllocBuffers(void);
extern void RTFAPI MTBufInit(const kal_uint32 buf_addr, const kal_uint32 buf_size);
extern void SetRecoverableFlag(RTFDevice * Dev, BYTE block_type);

#ifdef __FS_DEDICATED_BUFFER__
#define MTCacheInit() do { AllocBuffers(); MTBufInit((kal_uint32)gFS_DedicatedBufferPool, FS_DEDICATED_BUFFER_SIZE); } while(0)
#else
#define MTCacheInit() do { AllocBuffers(); } while(0)
#endif

#ifdef __FS_INTERVAL_BUFFER__
int   fs_srv_buf_alloc(void);
void *fs_srv_buf_get(RTFDevice * Dev, RTFSector Sector, UINT Flags);
int   fs_srv_buf_final(void);
#endif  // __FS_INTERVAL_BUFFER__

extern void *GetBuffer(RTFDevice *Dev, RTFSector SectorAddress, UINT Flags);
#define GetBufferDIR(Dev, SectorAddress, PrefetchSectors)         GetBuffer(Dev, SectorAddress, FS_BTYPE_DIR)
#define GetBufferDIRNoLoad(Dev, SectorAddress)                    GetBuffer(Dev, SectorAddress, FS_BTYPE_DIR | NO_LOAD)
#define GetBufferFAT(Drive, SectorAddress, PrefetchSectors)       GetBuffer(Drive->Dev, SectorAddress, FS_BTYPE_FAT)
#define GetFATPrefetchSectors(a)                                  (0)
#define GetFATPrefetchSectorsByOffset(drive, offset)              (0)

#endif // defined(__FS_CACHE_SUPPORT__) && !defined(__FS_CARD_DOWNLOAD__)


// Dedicate Buffe
//-----------------------------------------------------------------------------
#ifdef __FS_DEDICATED_BUFFER__
// FS dedicated buffer allocation times limitation
#define FS_INT_DBUF_ALLOC_MAX_TIMES (2)

// FS dedicated buffer allocation method
#define FS_INT_DBUF_ALLOC_PRECISE   (0x1)
#define FS_INT_DBUF_ALLOC_GREEDY    (0x2)

typedef struct
{
   kal_uint32  free_addr;
   kal_uint32  free_size;
   kal_uint32  allocated_size[FS_INT_DBUF_ALLOC_MAX_TIMES];
   kal_uint32  allocated_addr[FS_INT_DBUF_ALLOC_MAX_TIMES];
   kal_taskid  allocated_task;
   kal_uint8   allocated_times;
} fs_buffer_alloc_data_struct;

extern int MTBufCheckRange(unsigned int addr);
extern int MTBufAlloc(unsigned int size, unsigned char **buf, unsigned int flag);
extern void MTBufFree(unsigned int size, unsigned char **buf);

extern UINT                gFS_DedicatedBufferPool[];
extern const UINT          FS_DEDICATED_BUFFER_SIZE;
extern const UINT          FS_BUFF_SIZE_MOVE;
extern const UINT          FS_BUFF_SIZE_COUNT_FREE_CLUSTER;
#endif /* __FS_DEDICATED_BUFFER__ */

#endif /* __RTFBUF_H__ */

