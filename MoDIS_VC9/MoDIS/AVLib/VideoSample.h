#ifndef _VIDEO_SAMPLE_H
#define _VIDEO_SAMPLE_H

#include "AVLib.h"

namespace AVLib
{
    struct BitmapInformation
    {
        BITMAPINFOHEADER bmiHeader;
        RGBQUAD          bmiColors[3];
    };

    class AVLIB_API VideoSample
    {
    public:
        VideoSample(char *bitmapBuffer, const BitmapInformation &bitmapInfo);
        ~VideoSample();

        char* GetBitmapBuffer();
        BitmapInformation GetBitmapInformation();
        long GetBitmapWidth();
        long GetBitmapHeight();
        long GetBitmapSize();

        bool Scale(long newWidth, long newHeight);

        bool ConvertToRGB32();
        bool ConvertToRGB24();
        bool ConvertToRGB565();
        bool ConvertToRGB555();

		bool Save(TCHAR tszPath);
		bool SaveToClipboard();
		

    private:
        void AllocateBitmapBuffer(int size);
        void SetBitmapInformation(const BitmapInformation &bitmapInfo);
        bool IsRGB32();
        bool IsRGB24();
        bool IsRGB565();
        bool IsRGB555();

        char *m_BitmapBuffer;
        BitmapInformation m_BitmapInfo;
    };
}

#endif // _VIDEO_SAMPLE_H
