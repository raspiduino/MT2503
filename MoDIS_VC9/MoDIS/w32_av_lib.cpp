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
 *   w32_av_lib.cpp
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Main function of Audio & Video play on MoDIS
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include <windows.h>
#include <TCHAR.h>

#include <assert.h>
#include <algorithm>
#include <utility>

#include "AVLib\Player.h"
#include "w32_av_types.h"

extern "C"
{
#include "kal_general_types.h"
} 

//Willie, for test
//typedef boolean kal_bool;
//#define KAL_TRUE true
//#define KAL_FALSE false
//typedef __int64 kal_int64;
int GetPhysicalFilePath(LPCWSTR virtualFilePath, LPWSTR physicalFilePath);

/*
[From Nuance vendor feedback]      
As we discussed last time, we need to resolve the ¡°operator new¡± crash in Modis. 
It is quite complicated to re-route ¡°new¡± definition in NMC since NMC overrides new in quite some ways, 
such as class level redefinition, placement new, dynamic array, etc. 
The good news is that there is an easy way to fix in w32_av_lib.cpp: overwrite "new"and"delete" operater.
1. Only do this in NMC project
2. Can not do this in project including Gadget function,or re-define error
Modifier: MTK80753
*/
#ifdef __NMC_SUPPORT__
#ifndef __GADGET_SUPPORT__
#include <new>
static inline void* operator new(size_t size)
{
	return malloc(size);
}
static inline void* operator new[](size_t size)
{
	return malloc(size);
}
static inline void operator delete(void *p)
{
	free(p);
}
static inline void operator delete[](void *p)
{
	free(p);
}
#endif
#endif

//
// Initialization/deinitialization API
//
extern "C"
kal_bool w32_AV_Initialize()
{
    // Initialize COM
    HRESULT result = ::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
    return SUCCEEDED(result) ? KAL_TRUE : KAL_FALSE;
}

extern "C"
kal_bool w32_AV_Uninitialize()
{
    ::CoUninitialize();
    return KAL_TRUE;
}


//
// Audio API
//
static const int MAX_AUDIO_PLAYERS = 10;

static AVLib::AudioPlayer *g_Audio_Players[MAX_AUDIO_PLAYERS] = { NULL };

static w32_Audio_UserCallback
            g_Audio_UserCallbacks[MAX_AUDIO_PLAYERS] = { NULL };

//static UINT_PTR g_Audio_TimerIDs[MAX_AUDIO_PLAYERS] = { 0 };

// May be accessed by MoDIS and other threads simultaneously
// Lock needed?
static bool g_Audio_TimerEnabled[MAX_AUDIO_PLAYERS] = { false };

//Check is playing stream or not
static bool g_Is_StreamPlaying = 0 ;

static void w32_Audio_Callback(int event, void *callbackData)
{
    AudioHandle handle = reinterpret_cast<AudioHandle>(callbackData);
    g_Audio_UserCallbacks[handle](handle, static_cast<w32_Audio_Event>(event));
}

extern "C"
void w32_Audio_OnTimer()
{
    for (AudioHandle handle=0; handle<MAX_AUDIO_PLAYERS; handle++)
    {
        if (g_Audio_Players[handle] != NULL &&
            g_Audio_TimerEnabled[handle] &&
            g_Audio_Players[handle]->IsPlaybackFinished())
        {
            g_Audio_TimerEnabled[handle] = false;
            g_Audio_UserCallbacks[handle](
                    handle, w32_AudioEvent_PlaybackFinished);
        }
    }
}

static AudioHandle w32_Audio_FindFreeHandle()
{
    for (AudioHandle handle=0; handle<MAX_AUDIO_PLAYERS; handle++)
    {
        if (g_Audio_Players[handle] == NULL)
        {
            return handle;
        }
    }

    return AudioHandle_Invalid;
}

static bool w32_Audio_IsInvalidHandle(AudioHandle handle)
{
    return (handle < 0) ||
           (handle >= MAX_AUDIO_PLAYERS) ||
           (g_Audio_Players[handle] == NULL);
}

extern "C"
AudioHandle w32_Audio_OpenFile(LPCWSTR filePath,
                               w32_Audio_UserCallback callback)
{
    AudioHandle freeHandle = w32_Audio_FindFreeHandle();

    if (freeHandle == AudioHandle_Invalid)
    {
        return AudioHandle_Invalid;
    }

    g_Audio_Players[freeHandle] = new AVLib::AudioPlayer;

    if (g_Audio_Players[freeHandle] == NULL)
    {
        return AudioHandle_Invalid;
    }

    WCHAR physicalFilePath[1024];
    GetPhysicalFilePath(filePath, physicalFilePath);

    if (!g_Audio_Players[freeHandle]->OpenFile(physicalFilePath))
    {
        delete g_Audio_Players[freeHandle];
        g_Audio_Players[freeHandle] = NULL;
        return AudioHandle_Invalid;
    }
	
	//Let system know that we have opened this file
//	FS_HANDLE fs_handle = FS_Open (filePath, FS_READ_ONLY);
//	if( fs_handle < 0 )	//can not open
//	{
//       delete g_Audio_Players[freeHandle];
//        g_Audio_Players[freeHandle] = NULL;	
//		return AudioHandle_Invalid;
//	}
//	g_Audio_FS_HANDLE[freeHandle] = fs_handle ;

    g_Audio_UserCallbacks[freeHandle] = callback;
    g_Audio_Players[freeHandle]->SetCallbackFunction(
                    w32_Audio_Callback, reinterpret_cast<void *>(freeHandle));
	//Open file, seek it from the beginning
	g_Audio_Players[freeHandle]->SeekStream(0);
    return freeHandle;
}

extern "C"
AudioHandle w32_Audio_OpenBuffer(const char *buffer,
                                 int bufferSize,
                                 w32_Audio_UserCallback callback)
{
    AudioHandle freeHandle = w32_Audio_FindFreeHandle();

    if (freeHandle == AudioHandle_Invalid)
    {
        return AudioHandle_Invalid;
    }

    g_Audio_Players[freeHandle] = new AVLib::AudioPlayer;

    if (g_Audio_Players[freeHandle] == NULL)
    {
        return AudioHandle_Invalid;
    }

    if (!g_Audio_Players[freeHandle]->OpenBuffer(buffer, bufferSize))
    {
        delete g_Audio_Players[freeHandle];
        g_Audio_Players[freeHandle] = NULL;

        return AudioHandle_Invalid;
    }

    g_Audio_UserCallbacks[freeHandle] = callback;
    g_Audio_Players[freeHandle]->SetCallbackFunction(
                    w32_Audio_Callback, reinterpret_cast<void *>(freeHandle));

    return freeHandle;
}

extern "C"
kal_bool w32_Audio_Play(AudioHandle handle)
{
    if (w32_Audio_IsInvalidHandle(handle))
    {
        return KAL_FALSE;
    }

    if (g_Audio_UserCallbacks[handle] != NULL)
    {
        g_Audio_TimerEnabled[handle] = true;
        //g_Audio_TimerIDs[handle] =
        //        ::SetTimer(NULL, 0, 200, (TIMERPROC) w32_Audio_OnTimer);
    }

    return g_Audio_Players[handle]->PlayStream() ? KAL_TRUE : KAL_FALSE;
}

extern "C"
kal_bool w32_Audio_Stop(AudioHandle handle)
{
    if (w32_Audio_IsInvalidHandle(handle))
    {
        return KAL_FALSE;
    }

    return g_Audio_Players[handle]->StopStream() ? KAL_TRUE : KAL_FALSE;
}

extern "C"
kal_bool w32_Audio_Seek(AudioHandle handle, kal_int64 position)
{
    if (w32_Audio_IsInvalidHandle(handle))
    {
        return KAL_FALSE;
    }

    return g_Audio_Players[handle]->SeekStream(position) ?
                                            KAL_TRUE : KAL_FALSE;
} 

extern "C"
kal_bool w32_Audio_GetCurrentPosition(AudioHandle handle,
                                      kal_int64 *currentPosition)
{
    if (w32_Audio_IsInvalidHandle(handle))
    {
        return KAL_FALSE;
    }

    return g_Audio_Players[handle]->GetCurrentPosition(currentPosition) ?
                                                        KAL_TRUE : KAL_FALSE;
}

extern "C"
kal_bool w32_Audio_GetDuration(AudioHandle handle, kal_int64 *duration)
{
    if (w32_Audio_IsInvalidHandle(handle))
    {
        return KAL_FALSE;
    }

    return g_Audio_Players[handle]->GetDuration(duration) ?
                                                KAL_TRUE : KAL_FALSE;
}

extern "C"
kal_bool w32_Audio_IsPlaybackFinished(AudioHandle handle)
{
    if (w32_Audio_IsInvalidHandle(handle))
    {
        return KAL_FALSE;
    }

    return g_Audio_Players[handle]->IsPlaybackFinished() ?
                                                KAL_TRUE : KAL_FALSE;
}

extern "C"
kal_bool w32_Audio_GetBitrate(AudioHandle handle, kal_int64 *bitrate)
{
    if (w32_Audio_IsInvalidHandle(handle))
    {
        return KAL_FALSE;
    }

    return g_Audio_Players[handle]->GetBitrate(bitrate) ? KAL_TRUE : KAL_FALSE;
}

extern "C"
kal_bool w32_Audio_CloseFile(AudioHandle handle)
{
    if (w32_Audio_IsInvalidHandle(handle))
    {
        return KAL_FALSE;
    }

    if (!g_Audio_Players[handle]->CloseStream())
    {
        return KAL_FALSE;
    }

	//Close this file with FS
	//If g_Audio_FS_HANDLE[handle] != -1, then this file is open by w32_Audio_OpenFile
//	if( g_Audio_FS_HANDLE[handle] != -1 )
//	{
//		if( FS_Close( g_Audio_FS_HANDLE[handle] ) < 0 )  //can not close 
//		{
//			return KAL_FALSE;
//		}
//		g_Audio_FS_HANDLE[handle] = -1;
//	}
		
    delete g_Audio_Players[handle];
    g_Audio_Players[handle] = NULL;

    g_Audio_UserCallbacks[handle] = NULL;
    g_Audio_TimerEnabled[handle] = false;

    /*
    if (g_Audio_TimerIDs[handle] != 0)
    {
        ::KillTimer(NULL, g_Audio_TimerIDs[handle]);
        g_Audio_TimerIDs[handle] = 0;
    }
    */

    return KAL_TRUE;
}

extern "C"
kal_bool w32_Audio_CloseBuffer(AudioHandle handle)
{
    return w32_Audio_CloseFile(handle);
}


//
// Video API
//
class Mutex
{
public:
    explicit Mutex(LPCTSTR name)
        : m_Mutex(NULL)
    {
        m_Mutex = ::CreateMutex(NULL, FALSE, name);

        if (m_Mutex == NULL)
        {
            assert(0);
        }
    }

    ~Mutex()
    {
        assert(m_Mutex != NULL);

        if (!::CloseHandle(m_Mutex))
        {
            assert(0);
        }
    }

    bool Acquire()
    {
        assert(m_Mutex != NULL);

        switch (::WaitForSingleObject(m_Mutex, 100))
        {
            case WAIT_OBJECT_0:
                return true;

            case WAIT_ABANDONED:
                assert(0);
                break;

            case WAIT_TIMEOUT:
                return false;

            default:
                assert(0);
                break;
        }

        assert(0);
        return false;
    }

    void Release()
    {
        assert(m_Mutex != NULL);

        if (ReleaseMutex(m_Mutex) == 0)
        {
            assert(0);
        }
    }

private:
    Mutex(const Mutex &);
    Mutex& operator=(const Mutex &);

private:
    HANDLE m_Mutex;
};

class Lock
{
public:
    explicit Lock(Mutex &mutex)
        : m_Mutex(mutex),
          m_OwnsLock(false)
    {
        while (!m_Mutex.Acquire())
            ;

        m_OwnsLock = true;
    }

    Lock(Mutex &mutex, int retryCount)
        : m_Mutex(mutex),
          m_OwnsLock(false)
    {
        int _retryCount = retryCount;

        while (_retryCount-- > 0)
        {
            if (m_Mutex.Acquire())
            {
                m_OwnsLock = true;
                return;
            }
        }
    }

    ~Lock()
    {
        if (OwnsLock())
        {
            m_Mutex.Release();
        }
    }

    bool OwnsLock()
    {
        return m_OwnsLock;
    }

private:
    Lock(const Lock &);
    Lock& operator=(const Lock &);

private:
    Mutex &m_Mutex;
    bool m_OwnsLock;
};

static Mutex g_Video_Mutex(_T("Video Protection Mutex"));

static AVLib::VideoPlayer *g_Video_Player = NULL;
static w32_Video_UserCallback g_Video_UserCallback = NULL;
static bool g_Video_HasNotifiedFinishEvent = false;

static char *g_Video_FrameBuffer = NULL;
static int g_Video_Width = -1;
static int g_Video_Height = -1;
static w32_ColorDepth g_Video_ColorDepth = w32_ColorDepth_Invalid;

static void w32_Video_Callback(int event, void *callbackData)
{
    // Ignore callbackData 
    g_Video_UserCallback(static_cast<w32_Video_Event>(event));
}

static kal_bool w32_Video_GetCurrentFrame_Internal(char *frameBuffer,
                                                   int width,
                                                   int height,
                                                   w32_ColorDepth colorDepth);

extern "C"
void w32_Video_OnTimer()
{
    Lock lock(g_Video_Mutex, 1);
    
    if( !g_Is_StreamPlaying )   //you can not get frame when stream is not playing
        return ;
    
    if (!lock.OwnsLock())
    {
        return;
    }

    if (g_Video_Player == NULL ||
        g_Video_UserCallback == NULL ||
        g_Video_FrameBuffer == NULL)
    {
        return;
    }

    if (g_Video_Player->IsPlaybackFinished())
    {
        if (!g_Video_HasNotifiedFinishEvent)
        {
            g_Video_UserCallback(w32_VideoEvent_PlaybackFinished);
            g_Video_HasNotifiedFinishEvent = true;
        }
        return;
    }

    if (w32_Video_GetCurrentFrame_Internal(g_Video_FrameBuffer,
                                           g_Video_Width,
                                           g_Video_Height,
                                           g_Video_ColorDepth))
    {
        g_Video_UserCallback(w32_VideoEvent_FrameIsReady);
    }
}

extern "C"
kal_bool w32_Video_OpenFile(LPCWSTR filePath,
                            w32_Video_UserCallback callback)
{
    Lock lock(g_Video_Mutex);

    g_Video_Player = new AVLib::VideoPlayer;

    if (g_Video_Player == NULL)
    {
        return KAL_FALSE;
    }

    g_Video_UserCallback = callback;
    g_Video_Player->SetCallbackFunction(&w32_Video_Callback, NULL);

    WCHAR physicalFilePath[1024];
    GetPhysicalFilePath(filePath, physicalFilePath);

    if (!g_Video_Player->OpenFile(physicalFilePath))
    {
        delete g_Video_Player;
        g_Video_Player = NULL;

        return KAL_FALSE;
    }

//	FS_HANDLE fs_handle = FS_Open( filePath, FS_READ_ONLY);
//	if( fs_handle < 0 )
//	{
//		return KAL_FALSE;
//	}
//	g_Video_FS_HANDLE = fs_handle;
    return KAL_TRUE;
}

extern "C"
kal_bool w32_Video_OpenBuffer(const char *buffer,
                              int bufferSize,
                              w32_Video_UserCallback callback)
{
    Lock lock(g_Video_Mutex);

    g_Video_Player = new AVLib::VideoPlayer;

    if (g_Video_Player == NULL)
    {
        return KAL_FALSE;
    }

    g_Video_UserCallback = callback;
    g_Video_Player->SetCallbackFunction(&w32_Video_Callback, NULL);

    if (!g_Video_Player->OpenBuffer(buffer, bufferSize))
    {
        delete g_Video_Player;
        g_Video_Player = NULL;

        return KAL_FALSE;
    }

    return KAL_TRUE;
}

extern "C"
kal_bool w32_Video_Play(char* frameBuffer,
                        int width,
                        int height,
                        w32_ColorDepth colorDepth,
                        kal_bool playAudio,
                        double rate)
{
    Lock lock(g_Video_Mutex);
    
    g_Is_StreamPlaying = 1 ; //is playing stream
    
    if (g_Video_Player == NULL)
    {
        return KAL_FALSE;
    }

    g_Video_HasNotifiedFinishEvent = false;

    g_Video_FrameBuffer = frameBuffer;
    g_Video_Width       = width;
    g_Video_Height      = height;
    g_Video_ColorDepth  = colorDepth;

    if (!playAudio)
    {
        g_Video_Player->SetVolume(-10000);
    }

    g_Video_Player->SetRate(rate);

    return g_Video_Player->PlayStream() ? KAL_TRUE : KAL_FALSE;
}

extern "C"
kal_bool w32_Video_Stop()
{
    Lock lock(g_Video_Mutex);
    g_Is_StreamPlaying = 0 ; //is not playing stream
    
    if (g_Video_Player == NULL)
    {
        return KAL_FALSE;
    }

    return g_Video_Player->StopStream() ? KAL_TRUE : KAL_FALSE;
}

extern "C"
kal_bool w32_Video_Seek(kal_int64 position)
{
    Lock lock(g_Video_Mutex);

    if (g_Video_Player == NULL)
    {
        return KAL_FALSE;
    }

    return g_Video_Player->SeekStream(position) ? KAL_TRUE : KAL_FALSE;
}

extern "C"
kal_bool w32_Video_GetCurrentPosition(kal_int64 *currentPosition)
{
    Lock lock(g_Video_Mutex);

    if (g_Video_Player == NULL)
    {
        return KAL_FALSE;
    }

    return g_Video_Player->GetCurrentPosition(currentPosition) ?
                                                KAL_TRUE : KAL_FALSE;
}

extern "C"
kal_bool w32_Video_GetDuration(kal_int64 *duration)
{
    if (g_Video_Player == NULL)
    {
        return KAL_FALSE;
    }

    return g_Video_Player->GetDuration(duration) ? KAL_TRUE : KAL_FALSE;
}

extern "C"
kal_bool w32_Video_GetResolution(int *width, int *height)
{
    if (g_Video_Player == NULL)
    {
        return KAL_FALSE;
    }

    assert(width != NULL && height != NULL);

    std::pair<LONG, LONG> resolution = g_Video_Player->GetVideoResolution();
    *width  = static_cast<int>(resolution.first);
    *height = static_cast<int>(resolution.second);

    return KAL_TRUE;
}

static kal_bool w32_Video_GetCurrentFrame_Internal(char *frameBuffer,
                                                   int width,
                                                   int height,
                                                   w32_ColorDepth colorDepth)
{
    if (g_Video_Player == NULL)
    {
        return KAL_FALSE;
    }

    AVLib::VideoSample *videoSample = g_Video_Player->GetVideoSample();

    if (videoSample == NULL)
    {
        return KAL_FALSE;
    }

    videoSample->Scale(width, height);

    switch (colorDepth)
    {
        case w32_ColorDepth_RGB32:
            videoSample->ConvertToRGB32();
            break;

        case w32_ColorDepth_RGB24:
            videoSample->ConvertToRGB24();
            break;

        case w32_ColorDepth_RGB565:
            videoSample->ConvertToRGB565();
            break;

        case w32_ColorDepth_RGB555:
            videoSample->ConvertToRGB555();
            break;

        default:
            assert(0);
    }

    const int bytesPerPixel =
                videoSample->GetBitmapInformation().bmiHeader.biBitCount / 8;

    const int paddedWidth =
                videoSample->GetBitmapSize() / height / bytesPerPixel;
    
    const char *srcBuffer = videoSample->GetBitmapBuffer();
    char *dstBuffer = frameBuffer;

    //
    // Copy the bottom-up DIB into the frame buffer in top-down format
    //
    for (int i=0; i<height; i++)
    {
        const int srcOffset = i * paddedWidth * bytesPerPixel;
        const int dstOffset = (height - i - 1) * width * bytesPerPixel;

        std::copy(srcBuffer + srcOffset,
                  srcBuffer + srcOffset + width * bytesPerPixel,
                  dstBuffer + dstOffset);
    }

    g_Video_Player->FreeVideoSample(videoSample);
    return KAL_TRUE;
}

extern "C"
kal_bool w32_Video_IsPlaybackFinished()
{
    if (g_Video_Player == NULL)
    {
        return KAL_FALSE;
    }

    return g_Video_Player->IsPlaybackFinished() ? KAL_TRUE : KAL_FALSE;
}

extern "C"
kal_bool w32_Video_CloseFile()
{
    Lock lock(g_Video_Mutex);
    
    g_Is_StreamPlaying = 0 ; //is not playing stream
    
    if (g_Video_Player == NULL)
    {
        return KAL_FALSE;
    }

    if (!g_Video_Player->CloseStream())
    {
        return KAL_FALSE;
    }

//	if( g_Video_FS_HANDLE != -1 )
//	{
//		if( FS_Close( g_Video_FS_HANDLE ) < 0 ) //can not close
//		{
//			 return KAL_FALSE;
//		}
//		g_Video_FS_HANDLE = -1;
//	}
	
    delete g_Video_Player;
    g_Video_Player = NULL;

    g_Video_UserCallback = NULL;
    g_Video_HasNotifiedFinishEvent = false;

    g_Video_FrameBuffer = NULL;
    g_Video_Width       = -1;
    g_Video_Height      = -1;
    g_Video_ColorDepth  = w32_ColorDepth_Invalid;

    return KAL_TRUE;
}

extern "C"
kal_bool w32_Video_CloseBuffer()
{
    return w32_Video_CloseFile();
}


//
// Helper functions
//

static LPWSTR wcsrstr(LPCWSTR str, LPCWSTR substr)
{
    const int strLen = ::wcslen(str) + 1;
    LPWSTR reversedStr = new WCHAR[strLen];
    ::wcscpy(reversedStr, str);
    ::_wcsrev(reversedStr);

    const int substrLen = ::wcslen(substr) + 1;
    LPWSTR reversedSubstr = new WCHAR[substrLen];
	::wcscpy(reversedSubstr, substr);
    ::_wcsrev(reversedSubstr);

    LPWSTR ptr = ::wcsstr(reversedStr, reversedSubstr);
    
    if (ptr != NULL)
    {
        const int offset = ptr - reversedStr;
        ptr = const_cast<LPWSTR>(str) + (strLen - offset) - substrLen;
    }

    delete [] reversedStr;
    delete [] reversedSubstr;

    return ptr;
}

//
// Virtual file path     Physical file path
//
// C:\<dir*>\Test.mid => <Project>\mcu\MoDIS\WIN32FS\DRIVE_C\<dir(s)>\Test.mid
// D:\<dir*>\Test.mid => <Project>\mcu\MoDIS\WIN32FS\DRIVE_D\<dir(s)>\Test.mid
// E:\<dir*>\Test.mid => <Project>\mcu\MoDIS\WIN32FS\DRIVE_E\<dir(s)>\Test.mid
//
int GetPhysicalFilePath(LPCWSTR virtualFilePath, LPWSTR physicalFilePath)
{
    WCHAR modisExePath[1024];
    int i;

    if (::SearchPathW(NULL, L"MoDIS.exe", NULL, 1024, modisExePath, NULL) == 0)
    {
        return -1;
    }

    ::wcscpy(physicalFilePath, modisExePath);

    LPWSTR pathToBeReplaced = wcsrstr(physicalFilePath, L"MoDIS\\");

    if (pathToBeReplaced == NULL)
    {
        return -1;
    }
   for (i=0; i<::wcslen(virtualFilePath); i++)
    {
        if (virtualFilePath[i] == L'\\')
        {
            break;
        }
    }

    ::swprintf(pathToBeReplaced,
               L"WIN32FS\\DRIVE_%c\\%s",
               virtualFilePath[0],
               virtualFilePath + i + 1);

    return 0;
}

extern "C"
kal_bool w32_Video_PreviewFrame(char *frameBuffer,
                                                   int width,
                                                   int height,
                                                   w32_ColorDepth colorDepth,
                                                   kal_int64 position)
{
    Lock lock(g_Video_Mutex);
    
    if( g_Is_StreamPlaying ) //if is playing, we can not get preview
        return KAL_FALSE;
        
    if (g_Video_Player == NULL)
    {
        return KAL_FALSE;
    }
    
    if( !g_Video_Player->SeekStreamForPreview(position) )
        return KAL_FALSE ;
    
    AVLib::VideoSample *videoSample = g_Video_Player->GetVideoSampleForPreview();

    if (videoSample == NULL)
    {
        return KAL_FALSE;
    }

    videoSample->Scale(width, height);

    switch (colorDepth)
    {
        case w32_ColorDepth_RGB32:
            videoSample->ConvertToRGB32();
            break;

        case w32_ColorDepth_RGB24:
            videoSample->ConvertToRGB24();
            break;

        case w32_ColorDepth_RGB565:
            videoSample->ConvertToRGB565();
            break;

        case w32_ColorDepth_RGB555:
            videoSample->ConvertToRGB555();
            break;

        default:
            assert(0);
    }

    const int bytesPerPixel =
                videoSample->GetBitmapInformation().bmiHeader.biBitCount / 8;

    const int paddedWidth =
                videoSample->GetBitmapSize() / height / bytesPerPixel;
    
    const char *srcBuffer = videoSample->GetBitmapBuffer();
    char *dstBuffer = frameBuffer;

    //
    // Copy the bottom-up DIB into the frame buffer in top-down format
    //
    for (int i=0; i<height; i++)
    {
        const int srcOffset = i * paddedWidth * bytesPerPixel;
        const int dstOffset = (height - i - 1) * width * bytesPerPixel;

        std::copy(srcBuffer + srcOffset,
                  srcBuffer + srcOffset + width * bytesPerPixel,
                  dstBuffer + dstOffset);
    }

    g_Video_Player->FreeVideoSample(videoSample);
    return KAL_TRUE;
}
