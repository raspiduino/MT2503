#ifndef _W32_AV_LIB_H
#define _W32_AV_LIB_H

#include "w32_av_types.h"


//
// Initialization/deinitialization API
//

// Every THREAD must call w32_AV_Initiailze() before using any A/V functions
extern kal_bool w32_AV_Initialize();

// Every THREAD must call w32_AV_Uninitiailze() after A/V functions are no
// longer needed
extern kal_bool w32_AV_Uninitialize();

//
// Audio API
//

extern AudioHandle w32_Audio_OpenFile(LPCWSTR filePath,
                                      w32_Audio_UserCallback callback);

extern AudioHandle w32_Audio_OpenBuffer(const char *buffer,
                                        int bufferSize,
                                        w32_Audio_UserCallback callback);

extern kal_bool w32_Audio_Play(AudioHandle handle);
extern kal_bool w32_Audio_Stop(AudioHandle handle);
extern kal_bool w32_Audio_Seek(AudioHandle handle, kal_int64 position);

// In 100-nanosecond (i.e. 10^7 means one second)
extern kal_bool w32_Audio_GetCurrentPosition(AudioHandle handle,
                                             kal_int64 *currentPosition);
extern kal_bool w32_Audio_GetDuration(AudioHandle handle,
                                      kal_int64 *duration);

extern kal_bool w32_Audio_IsPlaybackFinished(AudioHandle handle);
extern kal_bool w32_Audio_GetBitrate(AudioHandle handle, kal_int64 *bitrate);
extern kal_bool w32_Audio_CloseFile(AudioHandle handle);
extern kal_bool w32_Audio_CloseBuffer(AudioHandle handle);

//
// Video API
//

extern kal_bool w32_Video_OpenFile(LPCWSTR filePath,
                                   w32_Video_UserCallback callback);

extern kal_bool w32_Video_OpenBuffer(const char *buffer,
                                     int bufferSize,
                                     w32_Video_UserCallback callback);

extern kal_bool w32_Video_Play(char *frameBuffer,
                               int width,
                               int height,
                               w32_ColorDepth colorDepth,
                               kal_bool playAudio,
                               double rate);

extern kal_bool w32_Video_Stop();
extern kal_bool w32_Video_Seek(kal_int64 position);

// In 100-nanosecond (i.e. 10^7 means one second)
extern kal_bool w32_Video_GetCurrentPosition(kal_int64 *currentPosition);
extern kal_bool w32_Video_GetDuration(kal_int64 *duration);
extern kal_bool w32_Video_GetResolution(int *width, int *height);
extern kal_bool w32_Video_IsPlaybackFinished();
extern kal_bool w32_Video_CloseFile();
extern kal_bool w32_Video_CloseBuffer();
extern kal_bool w32_Video_PreviewFrame(char *frameBuffer,
                                                   int width,
                                                   int height,
                                                   w32_ColorDepth colorDepth,
                                                   kal_int64 position) ;
#endif // _W32_AV_LIB_H
