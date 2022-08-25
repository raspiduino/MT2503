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
 *   PcmSource.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   The header file of PCM source component.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef PCM_SOURCE_DOT_H
#define PCM_SOURCE_DOT_H

#include "kal_general_types.h"
#include "l1audio.h"
#include "common_def.h"
#if defined(__DSP_CHIP_DUALMAC__)
#include "fc_def.h"
#endif

// DSP information
#if defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00)
#define PAGE_NUM 2
#elif defined(MT6253) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
#define PAGE_NUM 1
#elif defined(MT6256_S01) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)   
#define PAGE_NUM 5
#else
#error The new chip should define DM page number
#endif

// Sample count in a frame (20ms)
#define  FRAME_BUF_SIZE_8K    160
#define  FRAME_BUF_SIZE_16K   320

#define  PCM_SOURCE_BUFSIZE   1280
#define  PCM_SOURCE_BUFNUM       2

#define  SRC_BUFSIZE 1024
#define  SRC_BUFNUM     1

typedef struct {   
   // Basic information
   kal_bool dedicated_mode;
   kal_bool CSD_Mode;
   kal_bool bWideBand;
   Media_Format format;
   kal_uint16 uChannelNum;
   kal_uint32 uSamplingFreq;

   // Interrupt magic number
   kal_uint16 intMagicNum;
   
} Pcm_SrcData;

typedef struct {   
   // Basic information
   kal_uint32 uSamplingFreq;
   kal_uint16 uChannelNum;
   kal_uint16 fc_aud_id;
   kal_uint16 assoc_fc_aud_id;
#if defined(__DSP_CHIP_DUALMAC__)
   AUD_OUTDEV_T dev;   
   FC_Buf *pBufInfo;
#endif
} PcmRut_SrcData;

void PcmRouteSrcMsgHandler(kal_uint16 msgOp, kal_uint32 msgData, void *userData);

typedef struct {
   kal_uint8  uOriChannelNum;
   kal_uint8  uOutputChannelNum;
   kal_uint16 uOriSamplingFreq;
   kal_uint16 uOutputSamplingFreq;
} Pcm_SourceFormat;

typedef struct {   
   // Basic information
   Pcm_SourceFormat sDataFormat;
   
   // Flag
   kal_bool dedicated_mode;
   kal_bool fI2S;
   kal_bool bWideBand;
   kal_bool fStereo;
   kal_uint8 uPreSilenceCount;

   // Interrupt magic number
   kal_uint16 intMagicNum;
   
} Pcm_SourceData;

typedef struct { 
   // Basic information
   Pcm_SourceFormat sDataFormat;
   
   // SRC: Sample Rate Convert
   void       *blisrc_handle;
   kal_uint8  *bli_workBufPtr;
   
   // Time Control
   kal_uint16 uDuration;
   kal_uint16 uByteLen;
} SRC_Data;


void Pcmsrc_ConvertEncCapability(Pcm_SourceFormat *pConfig, SrcCapParam *pCap);

#endif
