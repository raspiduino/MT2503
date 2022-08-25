#ifndef _W32_AV_TYPES_H
#define _W32_AV_TYPES_H

#include "AVLib\RgbFormat.h"


// Note:
//   Do not modify the event that has a corresponding definition in
//   AVLib::PlaybackEvent.

typedef enum
{
    w32_AudioEvent_OK = 0,              // Do not modify
    w32_AudioEvent_PlaybackFinished,    // Do not modify
    w32_AudioEvent_Error                // Do not modify
} w32_Audio_Event;

typedef enum
{
    w32_VideoEvent_OK = 0,              // Do not modify
    w32_VideoEvent_PlaybackFinished,    // Do not modify
    w32_VideoEvent_Error,               // Do not modify
    w32_VideoEvent_FrameIsReady
} w32_Video_Event;

typedef enum
{
    w32_ColorDepth_RGB555  = RgbFormat_555,
    w32_ColorDepth_RGB565  = RgbFormat_565,
    w32_ColorDepth_RGB24   = RgbFormat_24,
    w32_ColorDepth_RGB32   = RgbFormat_32,
    w32_ColorDepth_Invalid
} w32_ColorDepth;

typedef int AudioHandle;
#define AudioHandle_Invalid -1

typedef void (*w32_Audio_UserCallback)(AudioHandle handle,
                                       w32_Audio_Event event);

typedef void (*w32_Video_UserCallback)(w32_Video_Event event);

#endif // _W32_AV_TYPES_H
