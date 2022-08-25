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
 *   video_subtitle_codec_if.c
 *
 * Project:
 * --------
 *	MTK
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
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
 *
 ****************************************************************************/

#include "drv_features_video.h"
#if defined(__VE_VIDEO_ARCHI_V2__) && defined(__VE_SUBTITLE_SUPPORT__)


#include "vcodec_v2_trc.h"
#include "drv_comm.h"                       // for drv_trace1(), drv_trace8()
#include "video_subtitle_codec_ssa.h"


/*****************************************************************************
*
*****************************************************************************/
VSD_CODEC_API_T* GetVsdCodecApi(VSD_CODEC_T eVsdCodec)
{
    VSD_CODEC_API_T *prApi = NULL;

    drv_trace1(TRACE_GROUP_10, VSD_CODEC_TYPE, eVsdCodec);

    switch (eVsdCodec)
    {
    case VSD_CODEC_UTF8:
    case VSD_CODEC_SSA_ASS:
        prApi = GetVsdSsaCodecApi(eVsdCodec);
        break;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 0  // Not supported for now.

    default:
        ASSERT(0);
        break;
    }

    return prApi;
}


/*****************************************************************************
*
*****************************************************************************/
VIDEO_ERROR_TYPE_T ReleaseVsdCodecApi(VSD_CODEC_T eVsdCodec, VSD_CODEC_API_T *prHandle)
{
    VIDEO_ERROR_TYPE_T eError = VIDEO_ERROR_NONE;

    switch (eVsdCodec)
    {
    case VSD_CODEC_UTF8:
    case VSD_CODEC_SSA_ASS:
        eError = ReleaseVsdSsaCodecApi(prHandle);
        break;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // 0  // Not supported for now.

    default:
        ASSERT(0);
        break;
    }

    return eError;
}


#endif  // defined(__VE_VIDEO_ARCHI_V2__) && defined(__VE_SUBTITLE_SUPPORT__)

