/*****************************************************************************
 * Filename:
 * ---------
 * custom_video_enc_setting_mjpeg.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file defines the frame rate table for MJPEG.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
****************************************************************************/
#ifndef VIDEO_RECORDER_SETTING_MJPEG_H
#define VIDEO_RECORDER_SETTING_MJPEG_H


/// __AVI_ENC_SUPPORT__ is a global option.
#ifdef __AVI_ENC_SUPPORT__


#include "custom_video_enc_types.h"
#include "custom_video_enc_if.h"
#include "custom_video_enc_types_mjpeg.h"

#if defined(MT6255)
   #include "custom_emi_release.h"
#endif

/// Check custom_rec_set_table() in mcu\custom\drv\Camera_common\custom_rec_config.c


#if defined(MT6236) || defined(MT6236B)

   #ifdef CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST

   static const VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T _rMjpegFrameRateTable[] =
   {
       /// Video live Wallpaper
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_320x480, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {120, 75, 120, 75, 2949120}
       },
       ///Video live Wallpaper

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {120, 75, 120, 75, 2949120}
       }
   };

   #else

   static const VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T _rMjpegFrameRateTable[] =
   {
       /// Video live Wallpaper
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_320x480, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {120, 75, 120, 75, 2949120}
       },
       ///Video live Wallpaper

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {120, 75, 120, 75, 2949120}
       },

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {150, 75, 150, 75, 921600}
       },

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {150, 75, 150, 75, 212890}
       },

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {150, 75, 150, 75, 212890}
       }
   };

   #endif

#elif defined(MT6253) || defined(MT6252) || defined(MT6252H)
   #ifdef CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST

   static const VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T _rMjpegFrameRateTable[] =
   {
       ///Video live Wallpaper
       #if defined(__LOW_COST_SUPPORT_ULC__)
       #else
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_240x320, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {160, 100, 80, 50, 983040}
       },
       #endif
       ///Video live Wallpaper

       #if defined(__LOW_COST_SUPPORT_ULC__)
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 150, 75, 608256}
       }
       #else
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {160, 100, 80, 50, 983040}
       }
       #endif

   };

   #else

   static const VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T _rMjpegFrameRateTable[] =
   {
       ///Video live Wallpaper
       #if defined(__LOW_COST_SUPPORT_ULC__)
       #else
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_240x320, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {160, 100, 80, 50, 983040}
       },
       #endif
       ///Video live Wallpaper

       #if defined(__LOW_COST_SUPPORT_ULC__)
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 150, 75, 608256}
       },
       #else
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {160, 100, 80, 50, 983040}
       },
       #endif

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {200, 150, 100, 75, 202752}
       },

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {200, 150, 100, 75, 141926}
       },

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {200, 150, 100, 75, 141926}
       }
   };

   #endif

#elif defined(MT6235) || defined(MT6235B)
   #ifdef CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST

   static const VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T _rMjpegFrameRateTable[] =
   {
       ///Video live Wallpaper
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_240x320, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 150, 75, 1843200}
       },
       ///Video live Wallpaper

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_352x288, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 150, 75, 2433024}
       }
   };

   #else

   static const VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T _rMjpegFrameRateTable[] =
   {
       ///Video live Wallpaper
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_240x320, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 150, 75, 1843200}
       },
       ///Video live Wallpaper

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_352x288, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 150, 75, 2433024}
       },

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 150, 75, 304128}
       },

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 150, 75, 212890}
       },

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 150, 75, 212890}
       }
   };

   #endif

#elif defined(MT6256)

   static const VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T _rMjpegFrameRateTable[] =
   {
       //////Video live Wallpaper
       ///#if defined(__MMI_MAINLCD_480X800__)    /// WVGA
       ///{
       ///    /// Upper table begins.
       ///    {CUSTOM_VENC_RESOLUTION_480x800, CUSTOM_VENC_QUALITY_FINE,
       ///    CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
       ///    ///  Lower table begins.
       ///    {300, 150, 300, 150, 18432000}
       ///},
       ///
       ///{
       ///    /// Upper table begins.
       ///    {CUSTOM_VENC_RESOLUTION_480x800, CUSTOM_VENC_QUALITY_GOOD,
       ///    CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
       ///    ///  Lower table begins.
       ///    {300, 150, 300, 150, 9216000}
       ///},
       ///
       ///{
       ///    /// Upper table begins.
       ///    {CUSTOM_VENC_RESOLUTION_480x800, CUSTOM_VENC_QUALITY_NORMAL,
       ///    CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
       ///    ///  Lower table begins.
       ///    {300, 150, 300, 150, 6451200}
       ///},
       ///
       ///{
       ///    /// Upper table begins.
       ///    {CUSTOM_VENC_RESOLUTION_480x800, CUSTOM_VENC_QUALITY_LOW,
       ///    CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
       ///    ///  Lower table begins.
       ///    {300, 150, 300, 150, 6451200}
       ///},
       ///#elif defined(__MMI_MAINLCD_240X320__)  /// QVGA
       ///{
       ///    /// Upper table begins.
       ///    {CUSTOM_VENC_RESOLUTION_240x320, CUSTOM_VENC_QUALITY_FINE,
       ///    CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
       ///    ///  Lower table begins.
       ///    {300, 150, 300, 150, 3686400}
       ///},
       ///
       ///{
       ///    /// Upper table begins.
       ///    {CUSTOM_VENC_RESOLUTION_240x320, CUSTOM_VENC_QUALITY_GOOD,
       ///    CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
       ///    ///  Lower table begins.
       ///    {300, 150, 300, 150, 1843200}
       ///},
       ///
       ///{
       ///    /// Upper table begins.
       ///    {CUSTOM_VENC_RESOLUTION_240x320, CUSTOM_VENC_QUALITY_NORMAL,
       ///    CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
       ///    ///  Lower table begins.
       ///    {300, 150, 300, 150, 1290240}
       ///},
       ///
       ///{
       ///    /// Upper table begins.
       ///    {CUSTOM_VENC_RESOLUTION_240x320, CUSTOM_VENC_QUALITY_LOW,
       ///    CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
       ///    ///  Lower table begins.
       ///    {300, 150, 300, 150, 1290240}
       ///},
       ///#elif defined(__MMI_MAINLCD_240X400__)  /// WQVGA
       ///{
       ///    /// Upper table begins.
       ///    {CUSTOM_VENC_RESOLUTION_240x400, CUSTOM_VENC_QUALITY_FINE,
       ///    CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
       ///    ///  Lower table begins.
       ///    {300, 150, 300, 150, 4608000}
       ///},
       ///
       ///{
       ///    /// Upper table begins.
       ///    {CUSTOM_VENC_RESOLUTION_240x400, CUSTOM_VENC_QUALITY_GOOD,
       ///    CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
       ///    ///  Lower table begins.
       ///    {300, 150, 300, 150, 2304000}
       ///},
       ///
       ///{
       ///    /// Upper table begins.
       ///    {CUSTOM_VENC_RESOLUTION_240x400, CUSTOM_VENC_QUALITY_NORMAL,
       ///    CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
       ///    ///  Lower table begins.
       ///    {300, 150, 300, 150, 1612800}
       ///},
       ///
       ///{
       ///    /// Upper table begins.
       ///    {CUSTOM_VENC_RESOLUTION_240x400, CUSTOM_VENC_QUALITY_LOW,
       ///    CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
       ///    ///  Lower table begins.
       ///    {300, 150, 300, 150, 1612800}
       ///},
       ///#elif defined(__MMI_MAINLCD_320X480__)  /// HVGA
       ///{
       ///    /// Upper table begins.
       ///    {CUSTOM_VENC_RESOLUTION_320x480, CUSTOM_VENC_QUALITY_FINE,
       ///    CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
       ///    ///  Lower table begins.
       ///    {300, 150, 300, 150, 7372800}
       ///},
       ///
       ///{
       ///    /// Upper table begins.
       ///    {CUSTOM_VENC_RESOLUTION_320x480, CUSTOM_VENC_QUALITY_GOOD,
       ///    CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
       ///    ///  Lower table begins.
       ///    {300, 150, 300, 150, 3686400}
       ///},
       ///
       ///{
       ///    /// Upper table begins.
       ///    {CUSTOM_VENC_RESOLUTION_320x480, CUSTOM_VENC_QUALITY_NORMAL,
       ///    CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
       ///    ///  Lower table begins.
       ///    {300, 150, 300, 150, 2580480}
       ///},
       ///
       ///{
       ///    /// Upper table begins.
       ///    {CUSTOM_VENC_RESOLUTION_320x480, CUSTOM_VENC_QUALITY_LOW,
       ///    CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
       ///    ///  Lower table begins.
       ///    {300, 150, 300, 150, 2580480}
       ///},
       ///#endif
       //////Video live Wallpaper

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_1280x720, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {130, 75, 130, 75, 19169280}
       },

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_1280x720, CUSTOM_VENC_QUALITY_GOOD,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {150, 75, 150, 75, 11059200}
       },

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_1280x720, CUSTOM_VENC_QUALITY_NORMAL,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {150, 75, 150, 75, 7741440}
       },

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_1280x720, CUSTOM_VENC_QUALITY_LOW,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {150, 75, 150, 75, 7741440}
       },

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_640x368, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 300, 150, 11059200}
       },

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_640x368, CUSTOM_VENC_QUALITY_GOOD,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 300, 150, 5529600}
       },

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_640x368, CUSTOM_VENC_QUALITY_NORMAL,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 300, 150, 3870720}
       },

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_640x368, CUSTOM_VENC_QUALITY_LOW,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 300, 150, 3870720}
       }
   };

#elif defined(MT6255)

   #ifndef CUSTOM_VENC_USE_REDUCED_SELECTION
      #error "the table was setup in nokia style. please replace it"
   #endif

   #include "custom_emi_release.h"

   #ifdef CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST
      static const VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T _rMjpegFrameRateTable[] =
      {
          ///Video live Wallpaper
          ///Video live Wallpaper

          #if defined(__EMI_CLK_200MHZ__)
          {
              /// Upper table begins.
              {CUSTOM_VENC_RESOLUTION_800x480, CUSTOM_VENC_QUALITY_FINE,
              CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
              /// Lower table begins.
              {300, 150, 150, 75, 9216000}
          },
          #else
          {
              /// Upper table begins.
              {CUSTOM_VENC_RESOLUTION_640x480, CUSTOM_VENC_QUALITY_FINE,
              CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
              /// Lower table begins.
              {300, 150, 150, 75, 7372800}
          },
          #endif

      };
   #else
      static const VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T _rMjpegFrameRateTable[] =
      {
          ///Video live Wallpaper
          ///Video live Wallpaper

          #if defined(__EMI_CLK_200MHZ__)
          {
              /// Upper table begins.
              {CUSTOM_VENC_RESOLUTION_800x480, CUSTOM_VENC_QUALITY_FINE,
              CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
              /// Lower table begins.
              {300, 150, 150, 75, 9216000}
          },
          #else
          {
              /// Upper table begins.
              {CUSTOM_VENC_RESOLUTION_640x480, CUSTOM_VENC_QUALITY_FINE,
              CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
              /// Lower table begins.
              {300, 150, 150, 75, 7372800}
          },
          #endif

          {
              /// Upper table begins.
              {CUSTOM_VENC_RESOLUTION_640x480, CUSTOM_VENC_QUALITY_GOOD,
              CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
              /// Lower table begins.
              {300, 150, 150, 75, 3686400}
          },

          {
              /// Upper table begins.
              {CUSTOM_VENC_RESOLUTION_640x480, CUSTOM_VENC_QUALITY_NORMAL,
              CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
              /// Lower table begins.
              {300, 150, 150, 75, 2580480}
          },

          {
              /// Upper table begins.
              {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_LOW,
              CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
              /// Lower table begins.
              {300, 150, 300, 150, 2580480}
          }
      };
   #endif

#elif defined(MT6250)

   #ifdef CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST

   static const VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T _rMjpegFrameRateTable[] =
   {
       ///Video live Wallpaper
       #if defined(__MED_VIDEO_ULC__)
       #else
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_WALLPAPER, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins. bitrate = width * height * fps * bits/byte * compression ratio (15 * 8 * 0.2 = 24)
           {300, 150, 150, 75, CUSTOM_VENC_WALLPAPER_WIDTH * CUSTOM_VENC_WALLPAPER_HEIGHT * 24}
       },
       #endif
       ///Video live Wallpaper

       #if defined(__MED_VIDEO_ULC__)
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 150, 75, 608256}
       }
       #else
           #if defined(__MJPEG_ENC_SW_SLIM__)
           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 1843200}
           }
           #else
           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_FINE,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 3686400}
           }
           #endif
       #endif

   };

   #else

   static const VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T _rMjpegFrameRateTable[] =
   {
       ///Video live Wallpaper
       #if defined(__MED_VIDEO_ULC__)
       #else
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_WALLPAPER, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins. bitrate = width * height * fps * bits/byte * compression ratio (15 * 8 * 0.2 = 24)
           {300, 150, 150, 75, CUSTOM_VENC_WALLPAPER_WIDTH * CUSTOM_VENC_WALLPAPER_HEIGHT * 24}
       },
       #endif
       ///Video live Wallpaper

       #if defined(__MED_VIDEO_ULC__)
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 150, 75, 608256}
       },

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 150, 75, 304128}
       },
    
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {200, 150, 100, 75, 141926}
       },
    
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {200, 150, 100, 75, 141926}
       }
       #else
           #if defined(__MJPEG_ENC_SW_SLIM__)
           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 1843200}
           },

           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 921600}
           },

           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 212890}
           },

           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 212890}
           }
           #else
           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_FINE,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {240, 150, 120, 75, 1474560}
           },

           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 921600}
           },

           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 212890}
           },

           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 212890}
           }
           #endif
       #endif
   };

   #endif

#elif defined(MT6260)

   #ifdef CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST

   static const VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T _rMjpegFrameRateTable[] =
   {
       ///Video live Wallpaper
       #if defined(__MED_VIDEO_ULC__)
       #else
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_WALLPAPER, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins. bitrate = width * height * fps * bits/byte * compression ratio (15 * 8 * 0.2 = 24)
           {300, 150, 150, 75, CUSTOM_VENC_WALLPAPER_WIDTH * CUSTOM_VENC_WALLPAPER_HEIGHT * 24}
       },
       #endif
       ///Video live Wallpaper

       #if defined(__MED_VIDEO_ULC__)
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 150, 75, 608256}
       }
       #else
           #if defined(__MJPEG_ENC_SW_SLIM__)
           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 1843200}
           }
           #else
           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_FINE,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 3686400}
           }
           #endif
       #endif

   };

   #else

   static const VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T _rMjpegFrameRateTable[] =
   {
       ///Video live Wallpaper
       #if defined(__MED_VIDEO_ULC__)
       #else
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_WALLPAPER, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins. bitrate = width * height * fps * bits/byte * compression ratio (15 * 8 * 0.2 = 24)
           {300, 150, 150, 75, CUSTOM_VENC_WALLPAPER_WIDTH * CUSTOM_VENC_WALLPAPER_HEIGHT * 24}
       },
       #endif
       ///Video live Wallpaper

       #if defined(__MED_VIDEO_ULC__)
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 150, 75, 608256}
       },

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 150, 75, 304128}
       },
    
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {200, 150, 100, 75, 141926}
       },
    
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {200, 150, 100, 75, 141926}
       }
       #else
           #if defined(__MJPEG_ENC_SW_SLIM__)
           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 1843200}
           },

           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 921600}
           },

           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 212890}
           },

           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 212890}
           }
           #else
           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_480x320, CUSTOM_VENC_QUALITY_FINE,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {240, 150, 120, 75, 1474560}
           },

           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 921600}
           },

           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 212890}
           },

           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 212890}
           }
           #endif
       #endif
   };

   #endif

#elif defined(MT6261) || defined(MT2501) || defined(MT2502)

   #ifdef CUSTOM_VENC_MULTIPLE_CODEC_CO_EXIST

   static const VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T _rMjpegFrameRateTable[] =
   {
       ///Video live Wallpaper
       #if defined(__MED_VIDEO_ULC__)
       #else
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_WALLPAPER, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins. bitrate = width * height * fps * bits/byte * compression ratio (15 * 8 * 0.2 = 24)
           {300, 150, 150, 75, CUSTOM_VENC_WALLPAPER_WIDTH * CUSTOM_VENC_WALLPAPER_HEIGHT * 24}
       },
       #endif
       ///Video live Wallpaper

       #if defined(__MED_VIDEO_ULC__)
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 150, 75, 608256}
       }
       #else
           #if defined(__MJPEG_ENC_SW_SLIM__)
           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 1843200}
           }
           #else
           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 1843200}
           }
           #endif
       #endif

   };

   #else

   static const VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T _rMjpegFrameRateTable[] =
   {
       ///Video live Wallpaper
       #if defined(__MED_VIDEO_ULC__)
       #else
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_WALLPAPER, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins. bitrate = width * height * fps * bits/byte * compression ratio (15 * 8 * 0.2 = 24)
           {300, 150, 150, 75, CUSTOM_VENC_WALLPAPER_WIDTH * CUSTOM_VENC_WALLPAPER_HEIGHT * 24}
       },
       #endif
       ///Video live Wallpaper

       #if defined(__MED_VIDEO_ULC__)
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 150, 75, 608256}
       },

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {300, 150, 150, 75, 304128}
       },
    
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {200, 150, 100, 75, 141926}
       },
    
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {200, 150, 100, 75, 141926}
       }
       #else
           #if defined(__MJPEG_ENC_SW_SLIM__)
           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 1843200}
           },

           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 921600}
           },

           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 212890}
           },

           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 212890}
           }
           #else
           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_FINE,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 1843200}
           },

           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_320x240, CUSTOM_VENC_QUALITY_GOOD,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 921600}
           },

           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 212890}
           },

           {
               /// Upper table begins.
               {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
               CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
               ///  Lower table begins.
               {300, 150, 150, 75, 212890}
           }
           #endif
       #endif
   };

   #endif 

#else

   /******************************************************************************
   * For unknown IC.
   ******************************************************************************/
   static const VIDEO_ENC_REC_MJPEG_FRAME_RATE_TABLE_T _rMjpegFrameRateTable[] =
   {
       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_FINE,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {150, 150, 150, 75, 608256}
       },

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_GOOD,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {150, 150, 150, 75, 304128}
       },

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_NORMAL,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {150, 150, 150, 75, 212890}
       },

       {
           /// Upper table begins.
           {CUSTOM_VENC_RESOLUTION_176x144, CUSTOM_VENC_QUALITY_LOW,
           CUSTOM_VENC_STORAGE_ALL, CUSTOM_VENC_CODEC_MJPEG},
           ///  Lower table begins.
           {150, 150, 150, 75, 212890}
       }
   };

#endif
#endif  // __AVI_ENC_SUPPORT__


#endif  // VIDEO_RECORDER_SETTING_MJPEG_H

