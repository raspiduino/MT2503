/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *   dpmgr.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Demand Paging Manager for audio
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "dpmgr.h"
#include "kal_trace.h"
#include "l1sp_trc.h"
#include "page.h"

#if defined(__DEMAND_PAGING__) && !defined(__EMPTY_MMI__)

/****************************************************************************/
/* The structure for demand paging manager                                  */
/****************************************************************************/
#define MAX_AUDIO_CONCURRENCY_ELEMENT 10

static struct {
   kal_uint32   state;
   DPMGR_Region regID[MAX_AUDIO_CONCURRENCY_ELEMENT];
   kal_uint8    uLoclCount[MAX_AUDIO_CONCURRENCY_ELEMENT];
} AudDPM;

/****************************************************************************/
/* The address and length decidec in link time                              */
/****************************************************************************/
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_WAVETABLE$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_WAVETABLE$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_WAV$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_WAV$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_MP3$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_MP3$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_AAC$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_AAC$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_AACV1$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_AACV1$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_AACV2$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_AACV2$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_AMR$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_AMR$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_AWB$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_AWB$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_COOK$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_COOK$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_APE$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_APE$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_DRA$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_DRA$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_WMA_16OB$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_WMA_16OB$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_WMA_44OB$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_WMA_44OB$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_WMA_44QB$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_WMA_44QB$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_BES_BASS$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_BES_BASS$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_BES_CF$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_BES_CF$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_BES_EQ$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_BES_EQ$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_BES_HEADPHONE$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_BES_HEADPHONE$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_BES_LIVE$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_BES_LIVE$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_BES_LOUDNESS$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_BES_LOUDNESS$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_BES_SURROUND$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_BES_SURROUND$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_BES_TS$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_BES_TS$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_BLISRC$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_BLISRC$$Length;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_VORBIS$$Base;
extern kal_uint32 Image$$DEMAND_PAGING_ROM_AUDIO_VORBIS$$Length;

/****************************************************************************/
/* The private function                                                     */
/****************************************************************************/
static kal_uint32 dpmgr_SearchIndex(DPMGR_Region id)
{
   kal_uint32 I;
   
   for (I=0; I<MAX_AUDIO_CONCURRENCY_ELEMENT; I++) {
      if ( ( AudDPM.state & (1<<I) ) && (AudDPM.regID[I] == id) ) {
         break;
      }
   }
   return I;
}

static kal_uint32 dpmgr_GetIndex(DPMGR_Region id)
{
   kal_uint32 I;
   
   for (I=0; I<MAX_AUDIO_CONCURRENCY_ELEMENT; I++) {
      if ( 0 == (AudDPM.state & (1<<I)) ) {
         break;
      }
   }
   
   ASSERT(I < MAX_AUDIO_CONCURRENCY_ELEMENT);

   AudDPM.state |= (1<<I);
   AudDPM.regID[I] = id;
   AudDPM.uLoclCount[I] = 0;
   
   return I;
}

static void dpmgr_FreeIndex(kal_uint32 index)
{
   ASSERT(index < MAX_AUDIO_CONCURRENCY_ELEMENT);
   ASSERT( AudDPM.state & (1<<index) );
   ASSERT( AudDPM.uLoclCount[index] == 0 );
   
   AudDPM.state &= ~(1<<index);
}

// To get the address and length
static void dpmgr_GetAddressLength(DPMGR_Region id, kal_uint32 *addr, kal_uint32 *len)
{
   kal_uint32 address, length;
   
   address = length = 0;
   
   switch (id) {
      case DPMGR_WAVETABLE:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_WAVETABLE$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_WAVETABLE$$Length;
         break;
      case DPMGR_WAV:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_WAV$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_WAV$$Length;
         break;
      case DPMGR_MP3:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_MP3$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_MP3$$Length;
         break;
      case DPMGR_AAC:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_AAC$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_AAC$$Length;
         break;
      case DPMGR_AACV1:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_AACV1$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_AACV1$$Length;
         break;
      case DPMGR_AACV2:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_AACV2$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_AACV2$$Length;
         break;
      case DPMGR_AMR:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_AMR$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_AMR$$Length;
         break;
      case DPMGR_AWB:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_AWB$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_AWB$$Length;
         break;
      case DPMGR_COOK:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_COOK$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_COOK$$Length;
         break;
      case DPMGR_APE:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_APE$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_APE$$Length;
         break;
      case DPMGR_DRA:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_DRA$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_DRA$$Length;
         break;
      case DPMGR_WMA16OB:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_WMA_16OB$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_WMA_16OB$$Length;
         break;
      case DPMGR_WMA44OB:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_WMA_44OB$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_WMA_44OB$$Length;
         break;
      case DPMGR_WMA44QB:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_WMA_44QB$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_WMA_44QB$$Length;
         break;
      case DPMGR_BES_BASS:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_BES_BASS$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_BES_BASS$$Length;
         break;
      case DPMGR_BES_CF:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_BES_CF$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_BES_CF$$Length;
         break;
      case DPMGR_BES_EQ:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_BES_EQ$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_BES_EQ$$Length;
         break;
      case DPMGR_BES_HEADPHONE:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_BES_HEADPHONE$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_BES_HEADPHONE$$Length;
         break;
      case DPMGR_BES_LIVE:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_BES_LIVE$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_BES_LIVE$$Length;
         break;
      case DPMGR_BES_LOUDNESS:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_BES_LOUDNESS$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_BES_LOUDNESS$$Length;
         break;
      case DPMGR_BES_SURROUND:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_BES_SURROUND$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_BES_SURROUND$$Length;
         break;
      case DPMGR_BES_TS:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_BES_TS$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_BES_TS$$Length;
         break;
      case DPMGR_BES_BLISRC:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_BLISRC$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_BLISRC$$Length;
         break;
      case DPMGR_VORBIS:
         address = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_VORBIS$$Base;
         length  = (kal_uint32)&Image$$DEMAND_PAGING_ROM_AUDIO_VORBIS$$Length;
         break;
      default:
         ASSERT(0);
   }
   
   *addr = address;
   *len = length;
}

static void dpmgr_IncreaseLockCount(kal_uint32 index, DPMGR_Region id)
{
   kal_uint32 uCount;
   
   ASSERT(index < MAX_AUDIO_CONCURRENCY_ELEMENT);
   ASSERT( AudDPM.state & (1<<index) );
   ASSERT(id == AudDPM.regID[index]);
   
   uCount = AudDPM.uLoclCount[index];
   AudDPM.uLoclCount[index]++;
   ASSERT(uCount < AudDPM.uLoclCount[index]);
   
   if (uCount == 0) {
      kal_uint32 regAddr, regLen;
      
      // To get the address and length
      dpmgr_GetAddressLength(id, &regAddr, &regLen);
      
      // Preload or lock
      demp_lock_pages(DEMP_LOCK_AUDIO, regAddr, regLen);
   }
}

static void dpmgr_DecreaseLockCount(kal_uint32 index, DPMGR_Region id)
{
   kal_uint32 uCount;
   
   ASSERT( AudDPM.state & (1<<index) );
   ASSERT(id == AudDPM.regID[index]);
   
   uCount = AudDPM.uLoclCount[index];
   AudDPM.uLoclCount[index]--;
   ASSERT(uCount > 0);
   
   if (uCount == 1) {
      kal_uint32 regAddr, regLen;
      
      // To get the address and length
      dpmgr_GetAddressLength(id, &regAddr, &regLen);
      
      // Unload ot unlock
      demp_unlock_pages(DEMP_LOCK_AUDIO, regAddr, regLen);
      
      // To free the index
      dpmgr_FreeIndex(index);
   }
}

/****************************************************************************/
/* The public function                                                      */
/****************************************************************************/
void DPMGR_Load_Internal(DPMGR_Region region, char* file_p, long line_p)
{
   kal_uint32 index;
   
   // Search the corresponding index
   index = dpmgr_SearchIndex(region);
   if (index == MAX_AUDIO_CONCURRENCY_ELEMENT) {
      index = dpmgr_GetIndex(region);
   }
   
   // Increase lock count
   dpmgr_IncreaseLockCount(index, region);

   kal_wap_trace( MOD_L1SP, TRACE_FUNC, "[AUD]DP Load Region %d, Count %d, file %s, line %d", region, AudDPM.uLoclCount[index], file_p, line_p);
}

void DPMGR_Unload_Internal(DPMGR_Region region, char* file_p, long line_p)
{
   kal_uint32 index;
   
   // Search the corresponding index
   index = dpmgr_SearchIndex(region);
   ASSERT(index < MAX_AUDIO_CONCURRENCY_ELEMENT);
   
   // Decrease lock count
   dpmgr_DecreaseLockCount(index, region);
   
   kal_wap_trace( MOD_L1SP, TRACE_FUNC, "[AUD]DP Unload Region %d, Count %d, file %s, line %d", region, AudDPM.uLoclCount[index], file_p, line_p);
}

#elif ((defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)) && defined(__DCM_WITH_COMPRESSION_AUDIO_CODEC__) )

#include "dcmgr.h"

static kal_uint32 mapToDCMId(DPMGR_Region region)
{
   if (region == DPMGR_MP3) {
      return DYNAMIC_CODE_COMPRESS_DAF;
   } else if (region == DPMGR_WAVETABLE) {
      return DYNAMIC_CODE_COMPRESS_WAVETABLE;
   }
   
   return DYNAMIC_CODE_COMPRESS_NONE;
}

/****************************************************************************/
/* The public function                                                      */
/****************************************************************************/
void DPMGR_Load_Internal(DPMGR_Region region, char* file_p, long line_p)
{
   kal_int32 reg = DYNAMIC_CODE_COMPRESS_NONE;
   
   reg = mapToDCMId(region);
   if (reg != DYNAMIC_CODE_COMPRESS_NONE) {
      DCM_Load(reg, 0, 0);
   }
   
   kal_wap_trace( MOD_L1SP, TRACE_FUNC, "[AUD]DP Load Region %d, Count %d, file %s, line %d", region, 0, file_p, line_p);
}

void DPMGR_Unload_Internal(DPMGR_Region region, char* file_p, long line_p)
{
   kal_int32 reg;
   
   reg = mapToDCMId(region);
   if (reg != DYNAMIC_CODE_COMPRESS_NONE) {
      DCM_Unload(reg);
   }

   kal_wap_trace( MOD_L1SP, TRACE_FUNC, "[AUD]DP Unload Region %d, Count %d, file %s, line %d", region, 0, file_p, line_p);
}

#else

/****************************************************************************/
/* The public function                                                      */
/****************************************************************************/
void DPMGR_Load_Internal(DPMGR_Region region, char* file_p, long line_p)
{
   kal_wap_trace( MOD_L1SP, TRACE_FUNC, "[AUD]DP Load Region %d, Count %d, file %s, line %d", region, 0, file_p, line_p);
}

void DPMGR_Unload_Internal(DPMGR_Region region, char* file_p, long line_p)
{
   kal_wap_trace( MOD_L1SP, TRACE_FUNC, "[AUD]DP Unload Region %d, Count %d, file %s, line %d", region, 0, file_p, line_p);
}

#endif
