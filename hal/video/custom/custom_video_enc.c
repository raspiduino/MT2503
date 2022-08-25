/*****************************************************************************
 * Filename:
 * ---------
 * custom_video_enc.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/


#ifdef __VIDEO_ARCHI_V2__


/* __MPEG4_ENC_SUPPORT__ is a global option. */
/* __ATV_RECORD_SUPPORT__ is a global option. */
/* __AVI_ENC_SUPPORT__ is a global option??? */
/* __VIDEO_VT_SUPPORT__ is a local option. */


#include "drv_features_video.h"             // for __VIDEO_VT_SUPPORT__
#include "drv_comm.h"                       // for drv_trace1(), drv_trace8()
#include "kal_release.h"
#include "custom_video_enc_setting.h"
#include "custom_video_enc_mpeg4.h"
#include "custom_video_enc_h264.h"
#include "custom_video_enc_mjpeg.h"
#include "custom_video_enc_matv.h"
#include "custom_video_enc_vt.h"
#include "custom_video_enc.h"
#include "vcodec_v2_trc.h"


/*****************************************************************************
*
*****************************************************************************/
static CUSTOM_VENC_MGR_T _rCustomVideoEncMgr;


/*****************************************************************************
*
*****************************************************************************/
CUSTOM_VENC_ERROR_T CustomVenc_Ctrl(CUSTOM_VENC_OP_T eOp,
    void *pvInput, kal_uint32 u4InputSize, void *pvOutput, kal_uint32 u4OutputSize)
{
    CUSTOM_VENC_ERROR_T eError;
    kal_uint32 *pu4Input, *pu4Output;

    if (eOp == CUSTOM_VENC_OP_SET_USER)
    {
        CUSTOM_VENC_USER_T *pvUser;
        PFN_CUSTOM_VENC_CTRL pfnCustomVencCtrl = NULL;

        if (!(sizeof(CUSTOM_VENC_USER_T) == u4InputSize))  { ASSERT(0); }
        pvUser = (CUSTOM_VENC_USER_T*)pvInput;
        if (!(pvUser != NULL))  { ASSERT(0); }
        switch (*pvUser)
        {
#ifdef __MPEG4_ENC_SUPPORT__
        case CUSTOM_VENC_USER_REC_MPEG4:
            eError = CustomVenc_GetMpeg4CtrlFunction(&pfnCustomVencCtrl);
            if (!(eError == CUSTOM_VENC_ERROR_NONE))  { ASSERT(0); }
            _rCustomVideoEncMgr.eCurrentUser = CUSTOM_VENC_USER_REC_MPEG4;
            break;
#endif  // __MPEG4_ENC_SUPPORT__

#ifdef __ATV_RECORD_SUPPORT__
        case CUSTOM_VENC_USER_MATV_MPEG4_NTSC:
            eError = CustomVenc_GetMatvCtrlFunction(&pfnCustomVencCtrl);
            if (!(eError == CUSTOM_VENC_ERROR_NONE))  { ASSERT(0); }
            _rCustomVideoEncMgr.eCurrentUser = CUSTOM_VENC_USER_MATV_MPEG4_NTSC;
            break;
        case CUSTOM_VENC_USER_MATV_MPEG4_PAL:
            eError = CustomVenc_GetMatvCtrlFunction(&pfnCustomVencCtrl);
            if (!(eError == CUSTOM_VENC_ERROR_NONE))  { ASSERT(0); }
            _rCustomVideoEncMgr.eCurrentUser = CUSTOM_VENC_USER_MATV_MPEG4_PAL;
            break;

        case CUSTOM_VENC_USER_MATV_MJPEG_NTSC:
            eError = CustomVenc_GetMatvMjpegCtrlFunction(&pfnCustomVencCtrl);
            if (!(eError == CUSTOM_VENC_ERROR_NONE))  { ASSERT(0); }
            _rCustomVideoEncMgr.eCurrentUser = CUSTOM_VENC_USER_MATV_MJPEG_NTSC;
            break;
        case CUSTOM_VENC_USER_MATV_MJPEG_PAL:
            eError = CustomVenc_GetMatvMjpegCtrlFunction(&pfnCustomVencCtrl);
            if (!(eError == CUSTOM_VENC_ERROR_NONE))  { ASSERT(0); }
            _rCustomVideoEncMgr.eCurrentUser = CUSTOM_VENC_USER_MATV_MJPEG_PAL;
            break;
#endif  // __ATV_RECORD_SUPPORT__

#ifdef __AVI_ENC_SUPPORT__
        case CUSTOM_VENC_USER_REC_MJPEG:
            eError = CustomVenc_GetMjpegCtrlFunction(&pfnCustomVencCtrl);
            if (!(eError == CUSTOM_VENC_ERROR_NONE))  { ASSERT(0); }
            _rCustomVideoEncMgr.eCurrentUser = CUSTOM_VENC_USER_REC_MJPEG;
            break;
#endif  // __AVI_ENC_SUPPORT__

#ifdef __VIDEO_VT_SUPPORT__
        case CUSTOM_VENC_USER_VT_MPEG4:
            eError = CustomVenc_GetVtCtrlFunction(&pfnCustomVencCtrl);
            if (!(eError == CUSTOM_VENC_ERROR_NONE))  { ASSERT(0); }
            _rCustomVideoEncMgr.eCurrentUser = CUSTOM_VENC_USER_VT_MPEG4;
            break;
#endif // __VIDEO_VT_SUPPORT__


#ifdef __H264_ENC_SUPPORT__
        case CUSTOM_VENC_USER_REC_H264:
            eError = CustomVenc_GetH264CtrlFunction(&pfnCustomVencCtrl);
            if (!(eError == CUSTOM_VENC_ERROR_NONE))  { ASSERT(0); }
            _rCustomVideoEncMgr.eCurrentUser = CUSTOM_VENC_USER_REC_H264;
            break;
#endif  // __H264_ENC_SUPPORT__


        default:
            ASSERT(0);
            break;
        }
        _rCustomVideoEncMgr.pfnCustomVencCtrl = pfnCustomVencCtrl;
    }

    if (!(_rCustomVideoEncMgr.pfnCustomVencCtrl != NULL))  { ASSERT(0); }

    drv_trace2(TRACE_GROUP_10, CUSTOM_VENC_TABLE_CTRL_BEGIN, (kal_uint32)(_rCustomVideoEncMgr.eCurrentUser), (kal_uint32)eOp);
    eError = _rCustomVideoEncMgr.pfnCustomVencCtrl(eOp, pvInput, u4InputSize, pvOutput, u4OutputSize);

    pu4Input = (kal_uint32*)pvInput;
    pu4Output = (kal_uint32*)pvOutput;
    drv_trace8(TRACE_GROUP_10, CUSTOM_VENC_TABLE_CTRL_END, (kal_uint32)eOp, (kal_uint32)pvInput, ((pu4Input == NULL) ? 0 : *pu4Input), u4InputSize, (kal_uint32)pvOutput, ((pu4Output == NULL) ? 0 : *pu4Output), u4OutputSize, __LINE__);

    return eError;
}

CUSTOM_VENC_ERROR_T CustomVenc_Ctrl_Get_NumOf_Recorder_Users(CUSTOM_VENC_USER_T **UserTable, kal_uint32 *u4NumUser)
{
    if (!(sizeof(_rVideoEncRecUserSupport) != 0))  { ASSERT(0); }
    if (!(sizeof(_rVideoEncRecUserSupport[0]) != 0))  { ASSERT(0); }
    *u4NumUser = (kal_uint32)((sizeof(_rVideoEncRecUserSupport) / sizeof(_rVideoEncRecUserSupport[0])) - 1);
    if (!(*u4NumUser != 0)) { ASSERT(0); }
    *UserTable = (CUSTOM_VENC_USER_T *)&(_rVideoEncRecUserSupport[1]);
    return CUSTOM_VENC_ERROR_NONE;
}


#endif  // __VIDEO_ARCHI_V2__

