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
 *   daf_drv.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   The header file for DAF driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef AMR_DRV_DOT_H
#define AMR_DRV_DOT_H

#include "fsal.h"

#include "l1audio.h"
#include "ast.h"
#include "audio_def.h"


#define HEADER_OK             0
#define HEADER_NO_DATA_FRAME  1
#define HEADER_ERROR          2

#define MAX_DATA_REQUESTED    1024
#define FRAME_DURATION        20

#if !defined(__AUDIO_COMPONENT_SUPPORT__)
typedef struct amrVar{
   kal_uint32        vm;
   kal_bool          bWideBand;
   kal_uint8         bCodecMode; /* Codec Mode for DSP Sherif Setting */
} amrInternal;

typedef struct mh_internal {
   MHdl              mh;
   amrInternal       amr;
   STFSAL            *pstFSAL;
   audInfoStruct     *description;
   Media_Event       end_status;
   kal_uint16        Tx_ordering_buffer[30];
   kal_uint16        Tx_data_buffer[30];
   kal_uint32        fileOffset;
   kal_uint32        lastFrameOffset;
   kal_uint32        uFileSize;
   kal_uint32        uDurUpdateThd;
   kal_uint8         buf[MAX_DATA_REQUESTED];
   AudioSeekTable   *AudioSeekTbl;
   kal_bool          isStreaming;
} amrMediaHdl;

// For cache table
void amrMFSetCacheTbl( MHdl *hdl, kal_uint8 *ptr, kal_uint32 usize );
void amrMFBuildCache( MHdl *hdl, Media_Status *eLastRet, kal_uint32 *uProgress, kal_bool fLimitFrameNumber);
kal_uint32 amrMFGetCacheDur(MHdl *hdl);
kal_uint32 amrMFGetTotalDuration( MHdl *hdl );

// Internal use
kal_bool amrChkFileHeader( amrMediaHdl *ihdl );
kal_bool amrSeek( amrMediaHdl *ihdl, kal_bool cacheEnable );
AST_Status amrASTParseFileHeader(void *hdlptr, kal_uint32 *FirstFrameOffset);
AST_Status amrASTParseFrame(void *hdlptr, kal_uint32 *CurOffset, kal_uint32 *ParseFrameNum);
kal_int32 amrGetBytesFromFile(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 fileOffset, kal_uint32 num_bytes, kal_uint8 *ptr);
kal_uint32 amrChkFrameHeader( amrMediaHdl *ihdl, kal_uint8  bFrameHeader, kal_uint8 *Tx_Type, kal_uint16 *lenSherifData, kal_uint16 *rd_bits );
kal_int32 amrWBChkFrameHeader( amrMediaHdl *ihdl, kal_uint8  bFrameHeader, kal_uint8 *Tx_Type, kal_uint16 *lenSherifData, kal_uint16 *rd_bits );

#endif //__AUDIO_COMPONENT_SUPPORT__
#endif 
