/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *   ast.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Audio Seek Table (AST).
 *   The AST is a file-offset frame-number mapping table.
 *   AST helps accelerate the seek response time
 *
 * Author:
 * -------
 * -------
 *
 *===========================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *===========================================================
*****************************************************************************/

#ifndef _AST_DOT_H_
#define _AST_DOT_H_

#define AAC_AST_MIN_ENTRY_SIZE 100
#define DAF_AST_MIN_ENTRY_SIZE 100
#define AMR_AST_MIN_ENTRY_SIZE 100
#define DRA_AST_MIN_ENTRY_SIZE 100

#define LIMIT_AST_BUILD_TABLE_FRAMES

#if defined LIMIT_AST_BUILD_TABLE_FRAMES
#define MAX_BUILD_FRAME_NUMBER     50
#endif

typedef enum {
   AST_SUCCESS = 0,
   AST_FAIL,
   AST_EOF,
   AST_PARSE_FRAME_FAIL,
   AST_PARSE_FRAME_BREAK,
   AST_PARSE_FILE_HEADER_FAIL
} AST_Status;


typedef struct {
   unsigned int FramesPerEntry;
   unsigned int MaxEntryNumbers;
   unsigned short CurrentIndex;
   unsigned short IsDone;
   unsigned short IsFail;
   unsigned short IsBreak;
#if !defined(__AUDIO_COMPONENT_SUPPORT__)
   AST_Status (*ASTParseFileHeader)(void *hdlptr, unsigned int *FirstFrameOffset);  
#else 
   AST_Status (*ASTParseFileHeader)(void *hdlptr, unsigned int *FirstFrameOffset, unsigned int *uFrameDur);  
#endif
   AST_Status (*ASTParseFrame)(void *hdlptr, unsigned int *CurOffset, unsigned int *ParseFrameNum);
   unsigned int *AccumulateFrames;
   unsigned int *AccumulateOffset;
   unsigned int uFrameDuration; //ps ms / 1000000
} AudioSeekTable;


void AST_UpdateTable(AudioSeekTable *ASTable, unsigned int CurOffset, unsigned int CurFrames) ;
AST_Status AST_BuildTable(void *hdlptr, AudioSeekTable *ASTable, unsigned int *Progress, unsigned int FileSize, char fLimitFrameNumber);
unsigned int AST_Seek(void *hdlptr, AudioSeekTable *ASTable, unsigned int *SeekFrame);
unsigned int AST_GetIndexedFrames(AudioSeekTable *ASTable);
unsigned int AST_EstimateTotalFrames(AudioSeekTable *ASTable, unsigned int FileSize);
#if !defined(__AUDIO_COMPONENT_SUPPORT__)
AST_Status AST_InitTable(AudioSeekTable *ASTable, unsigned int MinFramePerEntry, unsigned int BufSize,
                                   AST_Status (*ASTParseFrame)(void *hdlptr, unsigned int *CurOffset, unsigned int *ParseFrameNum), 
                                   AST_Status (*ASTParseFileHeader)(void *hdlptr, unsigned int *FirstFrameOffset));
#else                                   
AST_Status AST_InitTable(AudioSeekTable *ASTable, unsigned int MinFramePerEntry, unsigned int BufSize,
                                   AST_Status (*ASTParseFrame)(void *hdlptr, unsigned int *CurOffset, unsigned int *ParseFrameNum), 
                                   AST_Status (*ASTParseFileHeader)(void *hdlptr, unsigned int *FirstFrameOffset, unsigned int *uFrameDur));

#endif
AST_Status AST_SetFrameDuration(AudioSeekTable *ASTable, unsigned int uFrameDuration);
unsigned int AST_GetFrameDuration(AudioSeekTable *ASTable);

#endif
