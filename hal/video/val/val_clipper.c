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
*   val_clipper.c
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

#include "drv_features_video.h"
#if !defined(__VE_AVI_ENC_SUPPORT__)

#ifdef __VE_VIDEO_ARCHI_V2__

// #ifdef VAL_CLIPPER_ENABLED


#include "val.h"                // Internal data structure in VAL
#include "val_clipper.h"        // Internal data structure in VAL VIDEO CLIPPER
#include "val_clipper_if.h"     // Public data structure in VAL VIDEO CLIPPER
#include "val_if.h"             // Public interface of VAL
#include "kal_trace.h"          // for kal_prompt_trace()


/* The following files are newly added for RHR. */
// #include "stack_config.h"
// #include "kal_release.h"        // for kal_mem_set(), ASSERT()
#include "kal_public_api.h"
#include "kal_general_types.h"                  // for kal_uint32
#include "stack_config.h"


/*****************************************************************************
* Global variable(s)
*****************************************************************************/
static VAL_CLIPPER_MANAGER_T _rValClipperMgr;


/*****************************************************************************
*
*****************************************************************************/
VAL_ERROR_T VAL_CLIPPER_Init(void)
{
    kal_mem_set(&_rValClipperMgr, 0, sizeof(_rValClipperMgr));

    return VAL_ERR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
VAL_ERROR_T VAL_CLIPPER_DeInit(void)
{
    return VAL_ERR_NONE;
}


/*****************************************************************************
*
*****************************************************************************/
VAL_ERROR_T VAL_CLIPPER_Open(void *pvInput, kal_uint32 u4InputLen)
{
    VAL_ERROR_T eError = VAL_ERR_NONE;

    //kal_prompt_trace(MOD_VCODEC_V2, "VAL_CLIPPER_Open(): begins");

    //kal_prompt_trace(MOD_VCODEC_V2, "VAL_CLIPPER_Open(): ends");

    return eError;
}


/*****************************************************************************
*
*****************************************************************************/
VAL_ERROR_T VAL_CLIPPER_Ctrl(kal_uint32 u4Operation, void *pvInput,
        kal_uint32 u4InputLen, void *pvOutput, kal_uint32 u4OutputLen,
        kal_uint32 *pu4RealOutputLen)
{
    VAL_ERROR_T eError = VAL_ERR_NONE;

    //kal_prompt_trace(MOD_VCODEC_V2, "VAL_CLIPPER_Ctrl(): begins");

    if ((u4Operation < VAL_CLIPPER_OP_BASE) || (VAL_CLIPPER_OP_MAX < u4Operation))
    {
        //kal_prompt_trace(MOD_VCODEC_V2, "VAL_CLIPPER_Ctrl(): invalid operation %d", u4Operation);
        return VAL_ERR_INVALID_PARAMETER;
    }

    switch (u4Operation)
    {
    case VAL_CLIPPER_OP_OP1:
        // Call VAL_CLIPPER_OP_Handler1();
        break;

    case VAL_CLIPPER_OP_OP2:
        // Call VAL_CLIPPER_OP_Handler2();
        break;

    case VAL_CLIPPER_OP_OP3:
        // Call VAL_CLIPPER_OP_Handler3();
        break;

    case VAL_CLIPPER_OP_OP4:
        // Call VAL_CLIPPER_OP_Handler4();
        break;

    default:
        eError = VAL_ERR_INVALID_PARAMETER;
        ASSERT(0);
        break;
    }

    //kal_prompt_trace(MOD_VCODEC_V2, "VAL_CLIPPER_Ctrl(): ends");

    return eError;
}


/*****************************************************************************
*
*****************************************************************************/
VAL_ERROR_T VAL_CLIPPER_Close(void *pvInput, kal_uint32 u4InputLen)
{
    VAL_ERROR_T eError = VAL_ERR_NONE;

    //kal_prompt_trace(MOD_VCODEC_V2, "VAL_CLIPPER_Close(): begins");

    //kal_prompt_trace(MOD_VCODEC_V2, "VAL_CLIPPER_Close(): ends");

    return eError;
}


// #endif  // VAL_CLIPPER_ENABLED

#endif  // __VE_VIDEO_ARCHI_V2__

#endif  // !defined(__VE_AVI_ENC_SUPPORT__)

