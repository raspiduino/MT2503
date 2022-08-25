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
*   val_clipper_if.h
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
*****************************************************************************/

#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__

#ifndef VAL_CLIPPER_IF_H
#define VAL_CLIPPER_IF_H

#include "val_if.h"


/* The following files are newly added for RHR. */
// #include "kal_non_specific_general_types.h"  // for kal_uint32
#include "kal_general_types.h"                  // for kal_uint32


/*****************************************************************************
* Define the operations here.
* Please make sure the last operation is <= VAL_CLIPPER_OP_MAX.
*****************************************************************************/
#define VAL_CLIPPER_OP_OP1                          (VAL_CLIPPER_OP_BASE +  0)
#define VAL_CLIPPER_OP_OP2                          (VAL_CLIPPER_OP_BASE +  1)
#define VAL_CLIPPER_OP_OP3                          (VAL_CLIPPER_OP_BASE +  2)
#define VAL_CLIPPER_OP_OP4                          (VAL_CLIPPER_OP_BASE +  3)


/*****************************************************************************
* Define the data structures associated with the operations defined above.
*****************************************************************************/
typedef enum {
    VAL_CLIPPER_CALLBACK_UNKNOWN,
    VAL_CLIPPER_CALLBACK_SOMETHING_1,
    VAL_CLIPPER_CALLBACK_SOMETHING_2,
    VAL_CLIPPER_CALLBACK_SOMETHING_3,
} VAL_CLIPPER_CALLBACK_T;


typedef void (*PFN_VAL_CLIPPER_CALLBACK_T)(VAL_CLIPPER_CALLBACK_T eType,
        void *pvData, kal_uint32 u4DataLen);


/*
typedef enum
{
    VAL_CLIPPER_OP1_DATA_0,
    VAL_CLIPPER_OP1_DATA_1,
    VAL_CLIPPER_OP1_DATA_2,
    VAL_CLIPPER_OP1_DATA_3
} VAL_CLIPPER_OP1_DATA_T;


typedef enum
{
    VAL_CLIPPER_OP2_DATA_0,
    VAL_CLIPPER_OP2_DATA_1,
    VAL_CLIPPER_OP2_DATA_2,
    VAL_CLIPPER_OP2_DATA_3
} VAL_CLIPPER_OP2_DATA_T;


typedef struct {
    kal_uint32 u4IntBufferSize;
    kal_uint8 *pu1IntBufferAddr;
    kal_uint32 u4ExtBufferSize;
    kal_uint8 *pu1ExtBufferAddr;
    kal_uint32 u4FrameWidth;
    kal_uint32 u4FrameHeight;
    kal_uint32 u4Bitrate;
} VAL_CLIPPER_INIT_T;
*/


#endif  // VAL_CLIPPER_IF_H

#endif  // __VE_VIDEO_ARCHI_V2__

