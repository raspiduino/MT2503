#ifndef _PLAYER_H
#define _PLAYER_H

#include <memory>
#include "AVLib.h"
#include "VideoSample.h"
#include "RgbFormat.h"

namespace AVLib
{
    class AudioPlaybackEngine;

    class AudioPlayer
    {
    public:
        AVLIB_API AudioPlayer();
        AVLIB_API ~AudioPlayer();

        AVLIB_API bool OpenFile(LPCWSTR filename);
        AVLIB_API bool OpenBuffer(const char *buffer, int bufferSize);
        AVLIB_API bool PlayStream();
        AVLIB_API bool StopStream();
        AVLIB_API bool SeekStream(LONGLONG position);
        AVLIB_API bool GetCurrentPosition(LONGLONG *currentPosition);
        AVLIB_API bool GetDuration(LONGLONG *duration);
        AVLIB_API bool GetBitrate(LONGLONG *bitrate);
        AVLIB_API bool CloseStream();
        AVLIB_API bool IsPlaybackFinished();
        AVLIB_API bool IsStreamSeekable();
        AVLIB_API bool SetVolume(long volume);
        AVLIB_API bool SetRate(double rate);
        AVLIB_API void SetCallbackFunction(
                    void (*callbackFunction)(int, void *), void *callbackData);

    private:
        // Disallow copy constructor and copy assignment operator
        AudioPlayer(const AudioPlayer &);
        AudioPlayer& operator=(const AudioPlayer &);

        std::auto_ptr<AudioPlaybackEngine> m_PlaybackEngine;
    };

    //////////////////////////////////////////////////////////////////////////

    class VideoPlaybackEngine;

    class VideoPlayer
    {
    public:
        AVLIB_API VideoPlayer();
        AVLIB_API ~VideoPlayer();

        AVLIB_API bool OpenFile(LPCWSTR filename);
        AVLIB_API bool OpenBuffer(const char *buffer, int bufferSize);
        AVLIB_API bool PlayStream();
        AVLIB_API bool StopStream();
        AVLIB_API bool SeekStream(LONGLONG position);
        AVLIB_API bool GetCurrentPosition(LONGLONG *currentPosition);
        AVLIB_API bool GetDuration(LONGLONG *duration);
        AVLIB_API bool CloseStream();
        AVLIB_API bool IsPlaybackFinished();
        AVLIB_API bool IsStreamSeekable();
        AVLIB_API bool SetVolume(long volume);
        AVLIB_API bool SetRate(double rate);
        AVLIB_API void SetCallbackFunction(
                    void (*callbackFunction)(int, void *), void *callbackData);

        AVLIB_API void SetRgbFormat(RgbFormat format);
        AVLIB_API VideoSample* GetVideoSample();
        AVLIB_API void FreeVideoSample(VideoSample *videoSample);
        AVLIB_API std::pair<LONG, LONG> GetVideoResolution();
        //for preview
        AVLIB_API bool SeekStreamForPreview(LONGLONG position);    
        AVLIB_API bool IsStreamSeekableForPreview();       
        AVLIB_API VideoSample* GetVideoSampleForPreview();

    
    private:
        // Disallow copy constructor and copy assignment operator
        VideoPlayer(const VideoPlayer &);
        VideoPlayer& operator=(const VideoPlayer &);

        std::auto_ptr<VideoPlaybackEngine> m_PlaybackEngine;
    };
}

#endif // _PLAYER_H
