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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef DAF_DRV_DOT_H
#define DAF_DRV_DOT_H

#include "fsal.h"

#include "l1audio.h"
#include "audio_def.h"
//#include "media.h"
#include "ast.h"

//#define DEBUG_DUMP_LOG
//#define DAF_DEBUG_ENABLE

//#define MUSICAM_DEBUG_ENABLE
//#define MUSICAM_DECODE

#define XING_SUPPORT

#if defined XING_SUPPORT
#define FRAMES_FLAG     0x0001
#define BYTES_FLAG      0x0002
#define TOC_FLAG        0x0004
#define VBR_SCALE_FLAG  0x0008

#define FRAMES_AND_BYTES (FRAMES_FLAG | BYTES_FLAG)

// structure to receive extracted header, toc may be NULL
typedef struct {
    kal_int32   h_id;       // from MPEG header, 0=MPEG2, 1=MPEG1
    kal_int32   samprate;   // determined from MPEG header
    kal_int32   flags;      // from Xing header data
    kal_int32   frames;     // total bit stream frames from Xing header data
    kal_int32   bytes;      // total bit stream bytes from Xing header data
    kal_int32   vbr_scale;  // encoded vbr scale from Xing header data
    kal_uint8   toc[100];  // pointer to unsigned char toc_buffer[100]
                         // may be NULL if toc not desired
}   XHEADDATA;
#endif // #if defined XING_SUPPORT

extern struct { // to accelerate Real-Resuming
   kal_uint32 uCurOffset;
   kal_uint32 uResumeFrameOffset;
} audResumeInfo;

// ======================================================= //
//      DSP State of DAF                                   //
// ======================================================= //
#define DAF_DSP_STATE_IDLE            0
#define DAF_DSP_STATE_NORMAL_PLAY     1
#define DAF_DSP_STATE_START           3
#define DAF_DSP_STATE_STOP            5
#define DAF_DSP_STATE_END             7
#define DAF_DSP_STATE_WAIT1           9
#define DAF_DSP_STATE_WAIT2          11

/* =================================================== */
/*      AUDLP State                                    */
/* =================================================== */
#define DAF_STATE_PLAY         1
#define DAF_STATE_PAUSE        2
#define DAF_STATE_IDLE         3
#define MAX_FRAME_CHECK_LEN    (4608) // MAX search length of Frame Header Sync.
#define MP3FrmLen_MIN_BS_SIZE 4*1024

#if defined(MT6253) || defined(MT6251) || defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)
#define DAF_PAGE_NUM 1
#else
#define DAF_PAGE_NUM 2
#endif
#define DAF_DMBUFF_PAGE_NUM                 3

#define DAF_MAX_DATA_REQUESTED 1024
#define MAX_CONTINUOUS_ERROR_LEN         4096

// If there are consecutive frame error, driver stops the playback
// The suggest value is 25.
// 0: means that we don't enable the check

#if defined(MT6251)
#define ERROR_FRAME_THRESHOLD     5
#else
#define ERROR_FRAME_THRESHOLD     0
#endif

typedef struct mh_internal {
   MHdl             mh;
   STFSAL           *pstFSAL;
   audInfoStruct    *description;
   kal_uint64       uSamplesPerFrame;
   kal_uint64       uCurFrame;
   kal_uint64       frameDur; // in ms * 10E-6
   kal_uint8        buf[DAF_MAX_DATA_REQUESTED];
   kal_uint8        bCacheHeader[5];
   kal_uint8        bCacheHeaderNum;
   kal_bool         fReadHeader;
   kal_bool         isStreaming;
   kal_bool         DAF_Decode_EOF;
   kal_uint32       trimStartOffset;
   kal_uint32       trimStopOffset;
   kal_uint32       trimCurrentOffset;
   kal_uint32       fileOffset;
   kal_uint32       lastFrameOffset;
   kal_uint32       resumeFrameOffset;
   kal_uint32       uFileSize;
   kal_uint32       uID3V2Size;
   kal_uint32       uSampleRate;
   kal_uint32       uMLayer;
   kal_uint32       uDurUpdateThd;
   kal_uint32       uFirstFrameSize;
   kal_uint32       uFirstBR;
   kal_int32        DAF_DSP_Data_Cnt;
   kal_uint16       DAF_DSP_Write_Idx;
   kal_uint16       wDspReadIdx;
   kal_uint16       wHeader1;
   kal_uint16       wHeader2;
   kal_uint16       uPrevDspFrmCnt;
   Media_Event      end_status;
   AudioSeekTable  *AudioSeekTbl;
#if defined XING_SUPPORT
   XHEADDATA        stXing;
   kal_bool         fXing; // bit0: checked ? bit1: Xing Header exist ?
#endif // #if defined XING_SUPPORT
   kal_uint16       wFrameSizeTbl[15]; // The first word is valid indicator of the table
   kal_uint16       wExistFrmSizeTbl[15];
   kal_uint32       wFSTblIdx;
   kal_uint16       errorCnt;
   // auto fill silence when video playback
   kal_uint16       parser_sr;  //sampling rate from parser
   kal_uint8        parser_ch;  //channel number from parser
   kal_uint8        uChannelNumber;
   kal_uint8        uMPEGVer;

} dafMediaHdl;

// For cache table
void dafMFSetCacheTbl( MHdl *hdl, kal_uint8 *ptr, kal_uint32 usize );
void dafMFBuildCache( MHdl *hdl, Media_Status *eLastRet, kal_uint32 *uProgress, kal_bool fLimitFrameNumber);
kal_uint32 dafMFGetCacheDur(MHdl *hdl);
kal_uint32 dafMFGetTotalDuration( MHdl *hdl );

// Internal use
kal_bool dafReachNextFrame(dafMediaHdl *ihdl, kal_uint16 *wFHdrW1, kal_uint16 *wFHdrW2, kal_int32 UpdateFlag);
void dafUpdateInfo(dafMediaHdl *ihdl, kal_uint16 wFHdrW1, kal_uint16 wFHdrW2);
kal_bool dafGetBitRateIdx(kal_uint16 wFHdrW1, kal_uint16 wFHdrW2, kal_int16* wBitRateIdx);
kal_bool dafSeek( dafMediaHdl *ihdl, kal_bool cacheEnable );
AST_Status dafASTParseFileHeader(void *hdlptr, kal_uint32 *FirstFrameOffset);
AST_Status dafASTParseFrame(void *hdlptr, kal_uint32 *CurOffset, kal_uint32 *ParseFrameNum);

#endif
