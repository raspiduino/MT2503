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
*   val_if.h
*
* Project:
* --------
*	MediaTek
*
* Description:
* ------------
*
*
* Author:
* -------
 * -------
*
*=============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*-----------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
*****************************************************************************/


#ifndef VAL_IF_H
#define VAL_IF_H


/* The following files are newly added for RHR. */
// #include "kal_non_specific_general_types.h"  // for kal_uint32
#include "kal_general_types.h"                  // for kal_uint32
#include "video_recorder_source_component_if_v2.h"


/*****************************************************************************
* Definitions of base and maximum operations in each scenario (e.g. RECORDER).
* In order to have better compatibility, do not change these values.
*****************************************************************************/
#define VAL_UNKNOWN_OP              0L
#define VAL_PLAYER_OP_BASE          1L                                  //    1
#define VAL_PLAYER_OP_MAX           (VAL_PLAYER_OP_BASE + 2999)         // 3000
#define VAL_RECORDER_OP_BASE        (VAL_PLAYER_OP_MAX + 1)             // 3001
#define VAL_RECORDER_OP_MAX         (VAL_RECORDER_OP_BASE + 2999)       // 6000
#define VAL_CLIPPER_OP_BASE         (VAL_RECORDER_OP_MAX + 1)           // 6001
#define VAL_CLIPPER_OP_MAX          (VAL_CLIPPER_OP_BASE + 2999)        // 9000
#define VAL_VT_OP_BASE              (VAL_CLIPPER_OP_MAX + 1)            // 9001
#define VAL_VT_OP_MAX               (VAL_VT_OP_BASE + 2999)             // 12000


/*****************************************************************************
* VAL error code
*****************************************************************************/
typedef enum
{
    VAL_ERR_NONE = 0,
    VAL_ERR_NO_V2_ARCHITECTURE,         // __VIDEO_ARCHI_V2__ is not turned on
    VAL_ERR_INVALID_PARAMETER,
    VAL_ERR_INVALID_ERROR_CODE,

    VAL_ERR_ALREADY_INITED,             // VAL has been initialized.
    VAL_ERR_NOT_CLOSED,                 // VAL is not closed correctly
    VAL_ERR_NOT_INITED,                 // VAL has not been initialized.
    VAL_ERR_NOT_OPENED,                 // VAL has not been opened.

    VAL_ERR_PLAYER_ALREADY_OPENED,
    VAL_ERR_PLAYER_NOT_OPENED,

    VAL_ERR_RECORDER_ALREADY_OPENED,
    VAL_ERR_RECORDER_NOT_OPENED,
    VAL_ERR_RECORDER_RESOLUTION_NOT_SUPPORTED,
    VAL_ERR_RECORDER_NO_FRAME_ENCODED,
    VAL_ERR_RECORDER_GENERAL,           // FIXME
    VAL_ERR_RECORDER_FSAL,

    VAL_ERR_CLIPPER_ALREADY_OPENED,
    VAL_ERR_CLIPPER_NOT_OPENED,

    VAL_ERR_VT_ALREADY_OPENED,
    VAL_ERR_VT_NOT_OPENED,


    VAL_ERR_INIT_TWICE,                 // flow control
    VAL_ERR_CLOSE_BEFORE_INIT,          // flow control

    VAL_ERR_OUT_OF_MEMORY,              // memory management
    VAL_ERR_BUFFER_FULL,                // memory management
    VAL_ERR_BUFFER_EMPTY,                // memory management

    VAL_ERR_VT_STATUS_ERROR,
    VAL_ERR_VT_STATUS_UNSUPPORT,

    VAL_ERR_FILE_IO,                    // file I/O
    VAL_ERR_NO_SUCH_FILE,               // file I/O

    VAL_ERR_TIMER,                      // clock

    VAL_ERR_MAX = 32767                 // Unused enumerator ensuring that at least two bytes are used.
} VAL_ERROR_T;


/*****************************************************************************
* VAL scenarios
*****************************************************************************/
typedef enum
{
    VAL_SCENARIO_UNKNOWN,
    VAL_SCENARIO_PLAYER,
    VAL_SCENARIO_RECORDER,
    VAL_SCENARIO_VIDEO_CLIPPER,
    VAL_SCENARIO_VT,
    VAL_SCENARIO_MAX = 128              // Unused enumerator marks the one-byte watermark.
} VAL_SCENARIO_T;


/*****************************************************************************
* The following two function pointers are used by IDP/MDP for getting
* and returning YUV buffers.  MED gets these two function pointers through
* the VAL interface.  MED then passes them to IDP/MDP.
*****************************************************************************/
typedef kal_uint8* (*PFN_VAL_RECORDER_GET_RESERVED_FRAME_BUFFER_T)(void);
typedef kal_uint8* (*PFN_VAL_RECORDER_GET_BUFFER_T)(void);
typedef void (*PFN_VAL_RECORDER_COMPLETE_BUFFER_T)(kal_uint8 *pu1BuffAddr);


/*****************************************************************************
* Function prototypes of VAL are declared below.
* The operations are defined in the header file of each scenario.
*****************************************************************************/
VAL_ERROR_T VAL_Init(void);
VAL_ERROR_T VAL_Open(VAL_SCENARIO_T eScenario, void *pvInput,
        kal_uint32 u4InputLen);
VAL_ERROR_T VAL_Ctrl(VAL_SCENARIO_T eScenario, kal_uint32 u4Operation,
        void *pvInput, kal_uint32 u4InputLen, void *pvOutput,
        kal_uint32 u4OutputLen, kal_uint32 *pu4RealOutputLen);
VAL_ERROR_T VAL_Close(VAL_SCENARIO_T eScenario, void *pvInput,
        kal_uint32 u4InputLen);
VAL_ERROR_T VAL_DeInit(void);


#endif  // VAL_IF_H

