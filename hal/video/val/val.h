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
*   val.h
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
*****************************************************************************/


#ifndef VAL_H
#define VAL_H


#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__


#include "val_if.h"
#include "kal_public_api.h"
#include "kal_general_types.h"                  // for kal_uint32


/*****************************************************************************
* Definitions and macros related to scenarios (e.g. RECORDER).
*****************************************************************************/
#define VAL_SCENARIO_MAX_OPENED_PLAYER           0x2
#define VAL_SCENARIO_MAX_OPENED_RECORDER         0x1
#define VAL_SCENARIO_MAX_OPENED_CLIPPER          0x1
#define VAL_SCENARIO_MAX_OPENED_VT               0x1

// x shall be the structure "VAL_MANAGER_T:VAL_OPENED_SCENARIOS_T".
#define VAL_SCENARIO_NONE_IS_OPENED(x)          (((x).u1Player == 0) && ((x).u1Recorder == 0) && ((x).u1Clipper == 0) && ((x).u1VT == 0))
#define VAL_SCENARIO_PLAYER_IS_OPENED(x)        ((x).u1Player > 0)
#define VAL_SCENARIO_RECORDER_IS_OPENED(x)      ((x).u1Recorder > 0)
#define VAL_SCENARIO_CLIPPER_IS_OPENED(x)       ((x).u1Clipper > 0)
#define VAL_SCENARIO_VT_IS_OPENED(x)            ((x).u1VT > 0)

#define VAL_SCENARIO_PLAYER_IS_NOT_OPENED(x)    (! VAL_SCENARIO_PLAYER_IS_OPENED(x))
#define VAL_SCENARIO_RECORDER_IS_NOT_OPENED(x)  (! VAL_SCENARIO_RECORDER_IS_OPENED(x))
#define VAL_SCENARIO_CLIPPER_IS_NOT_OPENED(x)   (! VAL_SCENARIO_CLIPPER_IS_OPENED(x))
#define VAL_SCENARIO_VT_IS_NOT_OPENED(x)        (! VAL_SCENARIO_VT_IS_OPENED(x))

#define VAL_SCENARIO_OPEN_PLAYER(x)             do {((x).u1Player++); ASSERT((x).u1Player <= VAL_SCENARIO_MAX_OPENED_PLAYER);} while (0)
#define VAL_SCENARIO_OPEN_RECORDER(x)           do {((x).u1Recorder++); ASSERT((x).u1Recorder <= VAL_SCENARIO_MAX_OPENED_RECORDER);} while (0)
#define VAL_SCENARIO_OPEN_CLIPPER(x)            do {((x).u1Clipper++); ASSERT((x).u1Clipper <= VAL_SCENARIO_MAX_OPENED_CLIPPER);} while (0)
#define VAL_SCENARIO_OPEN_VT(x)                 do {((x).u1VT++); ASSERT((x).u1VT <= VAL_SCENARIO_MAX_OPENED_VT);} while (0)

#define VAL_SCENARIO_CLOSE_PLAYER(x)            do {ASSERT((x).u1Player > 0); ((x).u1Player--);} while (0)
#define VAL_SCENARIO_CLOSE_RECORDER(x)          do {ASSERT((x).u1Recorder > 0); ((x).u1Recorder--);} while (0)
#define VAL_SCENARIO_CLOSE_CLIPPER(x)           do {ASSERT((x).u1Clipper > 0); ((x).u1Clipper--);} while (0)
#define VAL_SCENARIO_CLOSE_VT(x)                do {ASSERT((x).u1VT > 0); ((x).u1VT--);} while (0)

#define VAL_SCENARIO_GET_OPENED_SCENARIOS(x)    (((kal_uint32)((x).u1Player)   << 24) ||    \
                                                 ((kal_uint32)((x).u1Recorder) << 16) ||    \
                                                 ((kal_uint32)((x).u1Clipper)  <<  8) ||    \
                                                 ((kal_uint32)((x).u1VT)       <<  0))


/*****************************************************************************
* VAL internal state
*****************************************************************************/
typedef enum
{
    VAL_STATE_DEINIT = 0,           // Set DEINIT to 0 on purpose.
    VAL_STATE_INIT,
    VAL_STATE_OPEN,
    VAL_STATE_CLOSE,
    VAL_STATE_MAX = 128             // Unused enumerator marks the one-byte watermark.
} VAL_STATE_T;


/*****************************************************************************
* Counter for opened VAL scenarios
*****************************************************************************/
typedef struct
{
    kal_uint8 u1Player;
    kal_uint8 u1Recorder;
    kal_uint8 u1Clipper;
    kal_uint8 u1VT;
} VAL_OPENED_SCENARIOS_T;


/*****************************************************************************
* VAL internal data structure
*****************************************************************************/
typedef struct
{
    VAL_STATE_T eState;
    VAL_OPENED_SCENARIOS_T rOpenedScenarios;
} VAL_MANAGER_T;


#endif  // __VE_VIDEO_ARCHI_V2__


#endif  // VAL_H

