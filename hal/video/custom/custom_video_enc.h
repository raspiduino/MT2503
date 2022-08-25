/*****************************************************************************
 * Filename:
 * ---------
 * custom_video_enc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file can be modified for customied video parameters.
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

#ifndef CUSTOM_VIDEO_ENC_H
#define CUSTOM_VIDEO_ENC_H


#include "custom_video_enc_if.h"


typedef struct
{
    PFN_CUSTOM_VENC_CTRL pfnCustomVencCtrl;
    CUSTOM_VENC_USER_T eCurrentUser;
} CUSTOM_VENC_MGR_T;


#endif  // CUSTOM_VIDEO_ENC_H

