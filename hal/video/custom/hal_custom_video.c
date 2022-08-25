/*****************************************************************************
 * Filename:
 * ---------
 * hal_custom_video.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for customization of video features
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_features_video.h"
#include "hal_custom_video.h"
#include "hal_custom_video_if.h"
#include "kal_general_types.h"

VIDEO_CUSTOM_ERR_T HalCustomQueryVideoSettings(kal_uint32 u4Param, void* pOutput)
{
#if defined(__VIDEO_ARCHI_V2__)
    switch(u4Param)
    {
    case HALC_I_FRM_RATE:
        {
            kal_uint32* pu4Param = (kal_uint32*)pOutput;
            *pu4Param = I_FRAME_REFRESH_RATE;
        }
        break;
    default:
        return VC_ERR_INVALID_PARAM;
        //break;
    }

    return VC_ERR_NONE;
#else
    return VC_ERR_INVALID_PARAM;
#endif //__VIDEO_ARCHI_V2__
}

#define MPLVP_SETTING_NUM 4
/******************************************************************************
* customization of "A/V sync. mechanism"
******************************************************************************/
typedef struct
{
    kal_uint64 u8Settings[MPLVP_SETTING_NUM];
    //cust[0]   : the delta time of A/V to trigger jump to i event. delta time: millisecond
    //cust[1]   : the delta time of A/V to trigger stop audio and re-sync A/V event. delta time: millisecond
    //cust[2]   : the delta time to find the jumping target. delta time: millisecond
    //cust[3]   : N/A
    //cust[4]   : N/A
    //cust[5]   : N/A
    //cust[6]   : reserved
    //cust[7]   : reserved
    //cust[8]   : reserved
    //cust[9]   : reserved

} mply_custom_struct;

#if defined (__MPEG4_DEC_SUPPORT__)
static mply_custom_struct rMPLVP_MP4Setting =
    #if defined(MP4_CUSTOM_TABLE_SETTING_ENABLE)
    {MP4_CUSTOM_TABLE_SETTING_0,
     MP4_CUSTOM_TABLE_SETTING_1,
     MP4_CUSTOM_TABLE_SETTING_2,
     MP4_CUSTOM_TABLE_SETTING_3
     };
    #else /*default setting*/
        #if defined(MT6253) || defined(MT6252) || defined(MT6252H)
        {500,  99999999,  2000, 2000};
        #else
#ifdef __VE_DURATION_MODE__
        {2000,  99999999,  3000, 3500};
#else
        {100,  99999999,  3000, 3500};
#endif
        #endif
    #endif

    #if defined (__VE_STREAM_SUPPORT__)
    static mply_custom_struct rMPLVP_MP4StrmSetting =
#ifdef __VE_DURATION_MODE__
            {2000,  99999999,  3000, 2000};
#else
            {500,  99999999,  3000, 500};
#endif
    #endif
#endif

#if defined (__H264_DEC_SUPPORT__)
static mply_custom_struct rMPLVP_H264Setting =
    #if defined(H264_CUSTOM_TABLE_SETTING_ENABLE)
    {H264_CUSTOM_TABLE_SETTING_0,
     H264_CUSTOM_TABLE_SETTING_1,
     H264_CUSTOM_TABLE_SETTING_2,
     H264_CUSTOM_TABLE_SETTING_3
     };
    #else /*default setting*/
#ifdef __VE_DURATION_MODE__
    {2000,  99999999,  3000, 3500};
#else
    {100,  99999999,  3000, 3500};
#endif
    #endif

    #if defined (__VE_STREAM_SUPPORT__)
    static mply_custom_struct rMPLVP_H264StrmSetting =
#ifdef __VE_DURATION_MODE__
        {2000,  99999999,  3000, 2000};
#else
        {500,  99999999,  3000, 500};
#endif

    #if defined (__VE_STREAM_CMMB_SUPPORT__)
    static mply_custom_struct rMPLVP_H264CMMBSetting =
#ifdef __VE_DURATION_MODE__
        {2000,  99999999,  3000, 2000};
#else    
        {3500,  99999999,  3000, 3500};
#endif        
    #endif
    #endif
#endif

#if defined (__VP8_DEC_SW_SUPPORT__)
static mply_custom_struct rMPLVP_VP8Setting =
    #if defined(VP8_CUSTOM_TABLE_SETTING_ENABLE)
    {VP8_CUSTOM_TABLE_SETTING_0,
     VP8_CUSTOM_TABLE_SETTING_1,
     VP8_CUSTOM_TABLE_SETTING_2,
     VP8_CUSTOM_TABLE_SETTING_3
     };
    #else /*default setting*/
#ifdef __VE_DURATION_MODE__
    {2000,  99999999,  2000, 2000};
#else
    {500,  99999999,  2000, 2000};
#endif
    #endif

    #if defined (__VE_STREAM_SUPPORT__)
    static mply_custom_struct rMPLVP_VP8StrmSetting =
#ifdef __VE_DURATION_MODE__
        {2000,  99999999,  3000, 2000};
#else
        {500,  99999999,  2000, 2000};
#endif
    #endif
#endif

#if defined (__RM_DEC_SUPPORT__)
static mply_custom_struct rMPLVP_RMSetting =
    #if defined(RM_CUSTOM_TABLE_SETTING_ENABLE)
    {RM_CUSTOM_TABLE_SETTING_0,
     RM_CUSTOM_TABLE_SETTING_1,
     RM_CUSTOM_TABLE_SETTING_2,
     RM_CUSTOM_TABLE_SETTING_3
     };
    #else /*default setting*/
#ifdef __VE_DURATION_MODE__
    { 2000, 10000,  2000, 2000};
#else
    { 30, 10000,  2000, 2000};
#endif
    #endif

    #if defined (__VE_STREAM_SUPPORT__)
    static mply_custom_struct rMPLVP_RMStrmSetting =
#ifdef __VE_DURATION_MODE__
        {2000, 10000,  2000, 2000};
#else
        { 30, 10000,  2000, 2000};
#endif
    #endif
#endif

__inline static kal_uint64 _MPLVP_GetPlayerSetting(mply_custom_format_enum eFormat, kal_uint32 u4IDX)
{
    if (u4IDX >= MPLVP_SETTING_NUM)
    {
        return 0;
    }

    switch(eFormat)
    {
#if defined (__MPEG4_DEC_SUPPORT__)
    case MPLY_CUSTOM_FORMAT_MP4:
        return rMPLVP_MP4Setting.u8Settings[u4IDX];
    //break;
#endif
#if defined (__H264_DEC_SUPPORT__)
    case MPLY_CUSTOM_FORMAT_H264:
        return rMPLVP_H264Setting.u8Settings[u4IDX];
    //break;
#endif
#if defined (__RM_DEC_SUPPORT__)
    case MPLY_CUSTOM_FORMAT_RM:
        return rMPLVP_RMSetting.u8Settings[u4IDX];
    //break;
#endif
#if defined (__VP8_DEC_SW_SUPPORT__)
    case MPLY_CUSTOM_FORMAT_VP8:
        return rMPLVP_VP8Setting.u8Settings[u4IDX];
    //break;
#endif
    default:
        return 0;
    }
}

#if defined (__VE_STREAM_SUPPORT__)
__inline static kal_uint64 _MPLVP_GetStreamingSetting(mply_custom_format_enum eFormat, kal_uint32 u4IDX)
{
    u4IDX -= CUS_IDX_STREAMING_SETTING_START;
    if (u4IDX >= MPLVP_SETTING_NUM)
    {
        return 0;
    }

    switch(eFormat)
    {
#if defined (__MPEG4_DEC_SUPPORT__)
    case MPLY_CUSTOM_FORMAT_MP4:
        return rMPLVP_MP4StrmSetting.u8Settings[u4IDX];
    break;
#endif
#if defined (__H264_DEC_SUPPORT__)
    case MPLY_CUSTOM_FORMAT_H264:
        return rMPLVP_H264StrmSetting.u8Settings[u4IDX];
    break;
#endif
#if defined (__RM_DEC_SUPPORT__)
    case MPLY_CUSTOM_FORMAT_RM:
        return rMPLVP_RMStrmSetting.u8Settings[u4IDX];
    break;
#endif
#if defined (__VP8_DEC_SW_SUPPORT__)
    case MPLY_CUSTOM_FORMAT_VP8:
        return rMPLVP_VP8StrmSetting.u8Settings[u4IDX];
    break;
#endif
    default:
        return 0;
    }
}

#if defined(__VE_STREAM_CMMB_SUPPORT__)
static kal_uint64 _MPLVP_GetCMMBSetting(mply_custom_format_enum eFormat, kal_uint32 u4IDX)
{
    u4IDX -= CUS_IDX_CMMB_SETTING_START;
    if (u4IDX >= MPLVP_SETTING_NUM)
    {
        return 0;
    }

    switch(eFormat)
    {
#if defined (__H264_DEC_SUPPORT__)
    case MPLY_CUSTOM_FORMAT_H264:
        return rMPLVP_H264CMMBSetting.u8Settings[u4IDX];
    break;
#endif
    default:
        return 0;
    }
}
#endif
#endif

kal_uint64 mply_custom_get_cust(mply_custom_format_enum eFormat, kal_uint32 u4IDX)
{
#if defined (__VE_STREAM_SUPPORT__)
    #if defined(__VE_STREAM_CMMB_SUPPORT__)
    if (u4IDX >= CUS_IDX_CMMB_SETTING_START)
    {
        return _MPLVP_GetCMMBSetting(eFormat, u4IDX);
    }
    else
    #endif
    if (u4IDX >= CUS_IDX_STREAMING_SETTING_START)
    {
        return _MPLVP_GetStreamingSetting(eFormat, u4IDX);
    }
    else
#endif
    {
        return _MPLVP_GetPlayerSetting(eFormat, u4IDX);
    }
}

static void _MPLVP_SetPlayerSetting(mply_custom_format_enum eFormat, kal_uint32 u4IDX, kal_uint64 u4NewSetting)
{
    if (u4IDX >= MPLVP_SETTING_NUM)
    {
        return;
    }

    switch(eFormat)
    {
#if defined (__MPEG4_DEC_SUPPORT__)
    case MPLY_CUSTOM_FORMAT_MP4:
        rMPLVP_MP4Setting.u8Settings[u4IDX] = u4NewSetting;
    break;
#endif
#if defined (__H264_DEC_SUPPORT__)
    case MPLY_CUSTOM_FORMAT_H264:
        rMPLVP_H264Setting.u8Settings[u4IDX] = u4NewSetting;
    break;
#endif
#if defined (__RM_DEC_SUPPORT__)
    case MPLY_CUSTOM_FORMAT_RM:
        rMPLVP_RMSetting.u8Settings[u4IDX] = u4NewSetting;
    break;
#endif
#if defined (__VP8_DEC_SW_SUPPORT__)
    case MPLY_CUSTOM_FORMAT_VP8:
        rMPLVP_VP8Setting.u8Settings[u4IDX] = u4NewSetting;
    break;
#endif
    default:
        return;
    }
}

#if defined (__VE_STREAM_SUPPORT__)
static void _MPLVP_SetStreamingSetting(mply_custom_format_enum eFormat, kal_uint32 u4IDX, kal_uint64 u4NewSetting)
{
    u4IDX -= CUS_IDX_STREAMING_SETTING_START;
    if (u4IDX >= MPLVP_SETTING_NUM)
    {
        return;
    }

    switch(eFormat)
    {
#if defined (__MPEG4_DEC_SUPPORT__)
    case MPLY_CUSTOM_FORMAT_MP4:
        rMPLVP_MP4StrmSetting.u8Settings[u4IDX] = u4NewSetting;
    break;
#endif
#if defined (__H264_DEC_SUPPORT__)
    case MPLY_CUSTOM_FORMAT_H264:
        rMPLVP_H264StrmSetting.u8Settings[u4IDX] = u4NewSetting;
    break;
#endif
#if defined (__RM_DEC_SUPPORT__)
    case MPLY_CUSTOM_FORMAT_RM:
        rMPLVP_RMStrmSetting.u8Settings[u4IDX] = u4NewSetting;
    break;
#endif
#if defined (__VP8_DEC_SW_SUPPORT__)
    case MPLY_CUSTOM_FORMAT_VP8:
        rMPLVP_VP8StrmSetting.u8Settings[u4IDX] = u4NewSetting;
    break;
#endif
    default:
        return;
        }
}
#endif

void mply_custom_set_cust(mply_custom_format_enum eFormat, kal_uint32 u4IDX, kal_uint64 u4NewSetting)
{
#if defined (__VE_STREAM_SUPPORT__)
    if (u4IDX >= CUS_IDX_STREAMING_SETTING_START)
    {
        _MPLVP_SetStreamingSetting(eFormat, u4IDX, u4NewSetting);
    }
    else
#endif
    {
        _MPLVP_SetPlayerSetting(eFormat, u4IDX, u4NewSetting);
    }
}

