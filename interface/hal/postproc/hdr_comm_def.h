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
 *   Hdr_comm_def.h
 *
 * Project:
 * --------
 *   All
 *
 * Description:
 * ------------
 *   HDR common define interface
 *
 * Author:
 * -------
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _HDR_COMM_DEF_H_
#define _HDR_COMM_DEF_H_

//#define SWHDR_SIM_MODE
//#define SWHDR_SIM_DEBUG_OUT_MODE
//#define __HDR_SUPPORT__	// for test


/* HDR Log only */
//#define HDR_LOG_ONLY

#ifdef HDR_LOG_ONLY
#include "fsal.h"
#include "fs_func.h"

typedef enum
{
    HDR_LOG_CAP_STR = 0,
    HDR_LOG_CAP_END,// 1

    HDR_LOG_CQV_CBK,// 2

    HDR_LOG_PPS_STR,// 3

    HDR_LOG_DEC_STR,// 4
    HDR_LOG_DEC_END,// 5

    HDR_LOG_HDR_STR,// 6
    HDR_LOG_HDR_CBK,// 7

    HDR_LOG_QVI_STR,// 8
    HDR_LOG_QVI_CBK,// 9

    HDR_LOG_ENC_STR,// 10
    HDR_LOG_ENC_CBK,// 11

    HDR_LOG_JAI_STR,// 12
    HDR_LOG_JAI_CBK,// 13

    HDR_LOG_PPS_END,// 14

    HDR_LOG_SAV_JPG,// 15

    HDR_LOG_NUM// 16
} CAL_HDR_LOG_ENUM;

//    HDR_LOG_PPI_TIME,// 4
//        HDR_LOG_PPI_CBK,// 6
typedef enum
{
    HDR_LOG_CAP_TIME = 0,
    HDR_LOG_PPS_TIME,// 1
    HDR_LOG_QTQ_TIME,// 2
    HDR_LOG_ALL_TIME,// 3
    HDR_LOG_DEC_TIME,// 4
    HDR_LOG_HDR_TIME,// 5
    HDR_LOG_QVI_TIME,// 6
    HDR_LOG_ENC_TIME,// 7
    HDR_LOG_JAI_TIME,// 8
    HDR_LOG_TIME_NUM// 9
} CAL_HDR_LOG_TIME_ENUM;

extern kal_uint32 CalHdrLogBuffer[HDR_LOG_NUM];
extern kal_uint32 CalHdrLogTime[HDR_LOG_TIME_NUM];
extern kal_wchar CalHdrLogFileName[25];
extern STFSAL CalHdrrWriteLog;
extern kal_uint32 CalHdrLogFileCount;
extern kal_uint32 CalHdrLogCapCount;

#endif
/* HDR Log only */

#include "kal_release.h"
#include "pp_comm_def.h"
#include "mm_comm_def.h"

/****************************************************************************
 *          High Dynamic Range (__HIGH_DYNAMIC_RANGE_SUPPORT__)
 ****************************************************************************/
/* HDR features */


typedef enum
{
	HDR_LEVEL_0,
	HDR_LEVEL_1,
	HDR_LEVEL_2,
	HDR_LEVEL_3,
	HDR_LEVEL_4,
	HDR_LEVEL_5,
	HDR_LEVEL_6,
	HDR_LEVEL_7,
	HDR_LEVEL_8,
	HDR_LEVEL_9,
	HDR_LEVEL_10,

	HDR_LEVEL_MAX
}	HDR_LEVEL_ENUM;


typedef enum
{
    HDR_STATE_IDLE,
    HDR_STATE_BUSY,
    HDR_STATE_READY
}   HDR_STATE_ENUM;


typedef struct
{
    HDR_STATE_ENUM  HdrState;
    kal_uint32  ImgBufferAddr;
    kal_uint16  ImgWidth;
    kal_uint16  ImgHeight;
    MM_IMAGE_FORMAT_ENUM  ImgFormat;
    kal_uint32 			HdrLog[32];
}	HDR_RESULT_STRUCT, *P_HDR_RESULT_STRUCT;


#endif  // _HDR_COMM_DEF_H_
