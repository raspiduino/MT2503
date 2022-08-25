/*****************************************************************************
 * Filename:
 * ---------
 * custom_video_enc_utility.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file provides interfaces for accessing customized video parameters.
 *   It shall not normally be modified.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/


#ifdef __VIDEO_ARCHI_V2__


#include "kal_release.h"
#include "custom_video_enc_if.h"


/*****************************************************************************
* Extract this function and use it as a common utility function.
*****************************************************************************/
CUSTOM_VENC_ERROR_T CustomVenc_MapWidthAndHeightToResolution(kal_uint16 u2Width,
        kal_uint16 u2Height, CUSTOM_VENC_RESOLUTION_T *peResolution)
{
    CUSTOM_VENC_ERROR_T eError;

    switch (u2Width)
    {
    case 96:
        if (u2Height == 128)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_96x128;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 120:
        if (u2Height == 160)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_120x160;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 128:
        if (u2Height == 96)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_128x96;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 144:
        if (u2Height == 176)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_144x176;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 160:
        if (u2Height == 120)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_160x120;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 176:
        if (u2Height == 144)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_176x144;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else if (u2Height == 208)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_176x208;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 240:
        if (u2Height == 320)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_240x320;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else if (u2Height == 400)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_240x400;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else if (u2Height == 432)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_240x432;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 288:
        if (u2Height == 352)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_288x352;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 320:
        if (u2Height == 240)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_320x240;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else if (u2Height == 480)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_320x480;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 352:
        if (u2Height == 288)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_352x288;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 368:
        if (u2Height == 640)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_368x640;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 400:
        if (u2Height == 240)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_400x240;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 432:
        if (u2Height == 240)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_432x240;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 480:
        if (u2Height == 320)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_480x320;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else if (u2Height == 640)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_480x640;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else if (u2Height == 720)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_480x720;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else if (u2Height == 800)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_480x800;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else if (u2Height == 848)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_480x848;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else if (u2Height == 864)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_480x864;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 576:
        if (u2Height == 720)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_576x720;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else if (u2Height == 704)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_576x704;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 608:
        if (u2Height == 800)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_608x800;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 640:
        if (u2Height == 368)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_640x368;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else if (u2Height == 480)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_640x480;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 704:
        if (u2Height == 576)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_704x576;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 768:
        if (u2Height == 1024)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_768x1024;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 720:
        if (u2Height == 480)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_720x480;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else if (u2Height == 576)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_720x576;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else if (u2Height == 1280)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_720x1280;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 800:
        if (u2Height == 480)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_800x480;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else if (u2Height == 608)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_800x608;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 848:
        if (u2Height == 480)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_848x480;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 864:
        if (u2Height == 480)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_864x480;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 960:
        if (u2Height == 1280)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_960x1280;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 1024:
        if (u2Height == 768)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_1024x768;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else if (u2Height == 1280)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_1024x1280;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 1088:
        if (u2Height == 1920)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_1088x1920;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 1152:
        if (u2Height == 1408)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_1152x1408;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 1200:
        if (u2Height == 1600)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_1200x1600;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 1280:
        if (u2Height == 720)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_1280x720;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else if (u2Height == 960)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_1280x960;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else if (u2Height == 1024)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_1280x1024;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 1408:
        if (u2Height == 1152)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_1408x1152;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 1600:
        if (u2Height == 1200)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_1600x1200;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    case 1920:
        if (u2Height == 1088)
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_1920x1088;
            eError = CUSTOM_VENC_ERROR_NONE;
        }
        else
        {
            *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
            eError = CUSTOM_VENC_ERROR_NO_MATCH;
        }
        break;

    default:
        *peResolution = CUSTOM_VENC_RESOLUTION_UNKNOWN;
        eError = CUSTOM_VENC_ERROR_NO_MATCH;
        break;
    }

    return eError;
}


#endif  // __VIDEO_ARCHI_V2__

