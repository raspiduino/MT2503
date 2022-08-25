/*****************************************************************************
 * Filename:
 * ---------
 * hal_custom_provider_if.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __HAL_CUSTOM_PROVIDER_IF_H__
#define __HAL_CUSTOM_PROVIDER_IF_H__

/******************************************************************************
*
*  Note that the definitions in this interface file should NOT be removed
*
******************************************************************************/

/******************************************************************************
* Settings of the bitstream buffer of proivder
******************************************************************************/
// MP4 Provider
//#define MP4_BUFFER_CUSTOM_SETTING_ENABLE
#ifdef MP4_BUFFER_CUSTOM_SETTING_ENABLE
    #define MP4_CUSTOM_AUDIO_MEM_SIZE    (8*1024)
    #define MP4_CUSTOM_VIDEO_MEM_SIZE    (50*1024)
#endif /* MP4_BUFFER_CUSTOM_SETTING_ENABLE */

// AVI Provider
//#define AVI_BUFFER_CUSTOM_SETTING_ENABLE
#ifdef AVI_BUFFER_CUSTOM_SETTING_ENABLE
    #define AVI_CUSTOM_AUDIO_MEM_SIZE    (8*1024)
    #define AVI_CUSTOM_VIDEO_MEM_SIZE    (50*1024)
#endif /* AVI_BUFFER_CUSTOM_SETTING_ENABLE */

// RM Provider
//#define RM_BUFFER_CUSTOM_SETTING_ENABLE
#ifdef RM_BUFFER_CUSTOM_SETTING_ENABLE
    #define RM_CUSTOM_AUDIO_MEM_SIZE    (128*1024)
    #define RM_CUSTOM_VIDEO_MEM_SIZE    (256*1024)
#endif /* RM_BUFFER_CUSTOM_SETTING_ENABLE */

// Streaming
//#define STREAMING_BUFFER_CUSTOM_SETTING_ENABLE
#ifdef STREAMING_BUFFER_CUSTOM_SETTING_ENABLE
    #define STREAMING_CUSTOM_AUDIO_MEM_SIZE    (96*1024)
    #define STREAMING_CUSTOM_VIDEO_MEM_SIZE   (464*1024)
#endif /* STREAMING_BUFFER_CUSTOM_SETTING_ENABLE */

#endif /* __HAL_CUSTOM_PROVIDER_IF_H__ */
