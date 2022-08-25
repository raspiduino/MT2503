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
 *   gif_decode_api.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  Prototypes of decode API for GIF decoder unified interface.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 03 08 2012 sophie.chen
 * removed!
 * .
 *
 * 11 22 2011 sophie.chen
 * removed!
 * .
 *
 * 11 11 2011 sophie.chen
 * removed!
 * .
 *
 * 09 26 2011 sophie.chen
 * removed!
 * .
 *
 * 09 23 2011 sophie.chen
 * removed!
 * .
 *
 * 08 31 2011 sophie.chen
 * removed!
 * .
 *
 * 03 15 2011 rey.su
 * removed!
 * .
 *
 * 03 15 2011 rey.su
 * removed!
 * .
 *
 * 02 25 2011 rey.su
 * removed!
 * .
 *
 * 02 21 2011 linson.du
 * removed!
 * .
 *
 * 12 14 2010 linson.du
 * removed!
 * .
 *
 * 11 24 2010 linson.du
 * removed!
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClaseCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _GIF_DECODER_API_H_
#define _GIF_DECODER_API_H_

/*
 * \headerfile gif_decode_api.h <gif_decode_api.h>
 * \anchor gif_decode_api.h
 */

#include "fsal.h"
#include "simple_memory_manager.h"
#include "drv_features_gif.h"

#if defined (__GIF_DEC_6268_SERIES__)
#include "gif_drv_dec_6268_series.h"
#endif

#if defined (__GIF_DEC_6276_SERIES__)
#include "gif_drv_dec_6276_series.h"
#endif

#include "kal_general_types.h"
#include "gfx_cache_switch_behavior_enum.h"

#ifdef GIF_WIN32
#undef get_ctrl_buffer
#undef free_ctrl_buffer
#define get_ctrl_buffer(X) malloc(X)
#define free_ctrl_buffer(X) free(X)
#endif

typedef enum {
   GIF_DEC_TYPE_HW = 0,
   GIF_DEC_TYPE_SW,
} GIF_DEC_TYPE_ENUM;



typedef enum {
   GIF_COLOR_FORMAT_8 = 1,
   GIF_COLOR_FORMAT_16 ,
   GIF_COLOR_FORMAT_24,
   GIF_COLOR_FORMAT_ARGB6666, //add at W1210
   GIF_COLOR_FORMAT_ARGB8888,
   GIF_COLOR_FORMAT_CUSTOM_1,
   GIF_COLOR_FORMAT_CUSTOM_2,
   GIF_COLOR_FORMAT_END,
} GIF_COLOR_FORMAT_ENUM;



typedef enum {
   GIF_DEC_STATE_STOP,
   GIF_DEC_STATE_READY,
   GIF_DEC_STATE_PAUSE,
   GIF_DEC_STATE_DECODING,
   GIF_DEC_STATE_COMPLETE,
}GIF_DEC_STATE_ENUM;



typedef enum {
   GIF_STATUS_OK = 0,
   GIF_STATUS_INVALID_HANDLE,
   GIF_STATUS_DEC_UNAVAILABLE,
   GIF_STATUS_DATA_UNAVAILABLE,
   GIF_STATUS_INVALID_PARAMETER,
   GIF_STATUS_INVALID_OPERATION,
   GIF_STATUS_INVALID_SOURCE_FILE,      ///< it means you should call "gifDecSetSourceFile" first
   GIF_STATUS_DEC_ERROR_INVALID_BUFFER,
   GIF_STATUS_DEC_ERROR_INVALID_FILE,
   GIF_STATUS_DEC_ERROR_PARSE,
   GIF_STATUS_DEC_MEMORY_LACK,
   GIF_STATUS_DEC_NON_SUPPORT,
   GIF_STATUS_DEC_NO_CLIP_WINDOW,
   GIF_STATUS_DEC_NO_READ_BUFFER,

   GIF_STATUS_NO_FRAME,
   GIF_STATUS_INVALID_FORMAT,
   GIF_STATUS_NOT_SUPPORT_RESIZING,
   GIF_STATUS_OUTPUT_WINDOW_NO_INTERSECTION,
   GIF_STATUS_DECODE_TIME_OUT
} GIF_STATUS_ENUM;

typedef enum{
   GIF_DISPOSAL_NO_ACTION,
   GIF_DISPOSAL_NOT_DISPOSAL,
   GIF_DISPOSAL_RESTORE_BG,
   GIF_DISPOSAL_RESTORE_PRE,      ///< not support (handle as GIF_RESTORE_BG)
   GIF_DISPOSAL_RSVD   
}GIF_DISPOSAL_METHOD_ENUM;

typedef struct GIF_RECTANGLE_T
{
   kal_int32 x;                        ///< X coordinate of the left-top point.
   kal_int32 y;                        ///< Y coordinate of the left-top point.
   kal_uint32 w;                       ///< Width of the rectangle.
   kal_uint32 h;                       ///< Height of the rectangle.
} GIF_RECTANGLE;

typedef kal_uint32 gif_color;
typedef kal_int32 (*gif_check_abort)(void);

typedef struct GIF_DECODER_T{
   kal_bool en_disposal;

   kal_bool     transparent_enable;
   kal_uint8    transparent_index;  ///<  the color index of transparent color

   GIF_DEC_TYPE_ENUM codec_type;    ///< HW or SW
   kal_uint32   flag;
   kal_uint32   frame_number;
   STFSAL       *fsal_handle;       ///< fsal handle
   kal_uint32   image_file_size;    ///< size of image file
   GIF_DEC_STATE_ENUM dec_state;    ///< decoder state
   kal_uint32   cache_id;
   kal_uint32   *cache_work_buffer; /// working buffer for geting cache id

   kal_uint32   source_key;         ///< Source Key
   GIF_STATUS_ENUM    last_status;

   void        (*set_index_palette_func)(kal_uint8 index, gif_color color);
   gif_color   *index_palette;      // TODO: working memory, sw init, get palette
   kal_uint16  index_palette_size;

   kal_int16    *stack;             ///< gif decoder working buffer
   kal_int32    *tree_buffer;       ///< gif decoder working buffer

   gif_color    *active_palette;    ///< Active palette address
   kal_uint16   act_palette_size;   ///< Active palette size

   kal_int16    *resizer_buffer;                ///< resizer buffer
   kal_int32    resizer_buffer_elements_cnt;    ///< size of resize buffer

   void *canvasBuffer;                          ///< Pointer to the canvas buffer.
   GIF_COLOR_FORMAT_ENUM canvasFormat;          ///< Canvas color format.
   GIF_RECTANGLE canvasWnd;                     ///< Canvas area.
   kal_uint32 canvasBytesPerPixel;              ///< Bytes per pixel in canvas

   GIF_RECTANGLE outputWnd;                     ///< output window Cordinate
   GIF_RECTANGLE clipWnd;                       ///< clip window Cordinate

   GIF_RECTANGLE imageWnd;                      ///< image Cordinate

   /// Working memory control variables
   void *intMemoryAddr;                         ///< Start address of internal working memory.
   kal_uint32 intMemorySize;                    ///< Size of internal working memory.
   STSMM intMemorySMM;                          ///< Internal memory control unit

   void *extMemoryAddr;                         ///< Start address of external working memory.
   kal_uint32 extMemorySize;                    ///< Size of external working memory.
   STSMM extMemorySMM;                          ///< external memory control unit

   kal_uint8 *fsalCacheAddr;                    ///< Start address of FSAL cache.
   kal_uint32 fsalCacheSize;                    ///< Size of FSAL cache.

   /// callback function
   gif_check_abort check_abort_func;            ///< Pointer to check abort function
   void (*callback)(kal_uint32 status, kal_uint32 fn); ///< Pointer to callback function

#if defined(__GIF_DEC_6268_SERIES__) || defined (__GIF_DEC_6276_SERIES__)
   gif_config_struct hw_config;
   gif_info_struct hw_info;
#endif

   GFX_CACHE_SWITCH_BEHAVIOR_ENUM dst_buffer_cache_switch_behavior;
   GIF_COLOR_FORMAT_ENUM palette_format;
} GIF_DECODER;


typedef GIF_DECODER*   GIF_DECODER_HANDLE;


/**
 * @brief            Get the GIF decoder handle.
 * @param codecType  specify whether HW codec or SW codec is to be acquired
 * @param handlePtr  pointer to obtain the decoder handle
 * @return           If the function succeeds, the return value is GIF_STATUS_OK and the handle is returned in handlePtr;
 *                   otherwise some error happened and the handlePtr will be NULL.
 * @remarks
 */
GIF_STATUS_ENUM gifDecGetHandle(GIF_DEC_TYPE_ENUM codecType, GIF_DECODER_HANDLE* handlePtr);



/**
 * @brief         Release the GIF decoder handle.
 * @param handlePtr pointer to the decoder handle to be released
 * @return        If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
GIF_STATUS_ENUM gifDecReleaseHandle(GIF_DECODER_HANDLE* handlePtr);






/**
 * @brief         Set the source file and read buffer for the decoder.
 * @param handle  the decoder handle in use
 * @param fp      the pointer to FSAL structure
 * @return        If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks
 *
 */
GIF_STATUS_ENUM gifDecSetSourceFile(GIF_DECODER_HANDLE handle, STFSAL *fp);




/**
 * @brief               Query the file buffer for the decoder.
 * @param handle        the decoder handle in use
 * @param readBufferSizeBest     pointer to unsigned int to obtain the best file read buffer size
 * @param readBufferSizeMinimum  pointer to unsigned int to obtain the minimum file read buffer size
 * @param fsalCacheSizeBest      pointer to unsigned int to obtain the best FSAL cache buffer size
 * @param fsalCacheSizeMinimum   pointer to unsigned int to obtain the minimum FSAL cache buffer size
 * @return              If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
GIF_STATUS_ENUM gifDecQueryFileBuffer (GIF_DECODER_HANDLE handle,
                                            kal_uint32 *readBufferSizeBest,
                                            kal_uint32 *readBufferSizeMinimum,
                                            kal_uint32 *fsalCacheSizeBest,
                                            kal_uint32 *fsalCacheSizeMinimum);


 /**
  * @brief         Set the source file and read buffer for the decoder.
  * @param handle  the decoder handle in use
  * @param readBufferAddr   the starting address of file read buffer
  * @param readBufferSize   the size of file read buffer
  * @param fsalCacheAddr    the starting address of FSAL cache buffer
  * @param fsalCacheSize    the size of FSAL cache buffer
  * @return        If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
  * @remarks       The cache buffer for FSAL is not necessary; however, with the cache buffer provided, the performance
  *                of file access through FSAL will be greatly improved.
  */
GIF_STATUS_ENUM gifDecSetFileBuffer(GIF_DECODER_HANDLE handle,
                                            void *readBufferAddr,
                                            kal_uint32 readBufferSize,
                                            void *fsalCacheAddr,
                                            kal_uint32 fsalCacheSize);


/**
 * @brief         Get the source image dimension of the GIF image.
 * @param handle  the decoder handle in use
 * @param width   pointer to unsigned short to obtain the width of the GIF image
 * @param height  pointer to unsigned short to obtain the height of the GIF image
 * @return        If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
GIF_STATUS_ENUM gifDecGetSrcDimension(GIF_DECODER_HANDLE handle,
                                                kal_uint16 *width,
                                                kal_uint16 *height);



/**
 * @brief         Set the destination buffer where the GIF will be decoded to.
 * @param handle  the decoder handle in use
 * @param bufferAddr  the starting address of destination buffer
 * @param bufferSize  the destination buffer size
 * @param width   the width of the destination buffer
 * @param height  the height of the destination buffer
 * @param colorFormat  the color format of the destination buffer
 * @return        If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
GIF_STATUS_ENUM gifDecSetDstRGBBufferInfo(GIF_DECODER_HANDLE handle,
                                        void * bufferAddr, kal_uint32 bufferSize,
                                        kal_uint32 width, kal_uint32 height,
                                        GIF_COLOR_FORMAT_ENUM colorFormat);



 /**
 * @brief         Set the destination window.
 * @param handle  the decoder handle in use
 * @param x       the x coordinate of the left-top of the the destination window
 * @param y       the y coordinate of the left-top of the the destination window
 * @param width       the width of the destination window
 * @param height       the height of the destination window
 * @return        If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
GIF_STATUS_ENUM gifDecSetDstWindow(GIF_DECODER_HANDLE handle,
                                        kal_int32 x, kal_int32 y,
                                        kal_uint32 width, kal_uint32 height);



/**
 * @brief         Set the destination clip window.
 * @param handle  the decoder handle in use
 * @param x       the x coordinate of the left-top of the the destination clip window
 * @param y       the y coordinate of the left-top of the the destination clip window
 * @param width       the width of the destination clip window
 * @param height       the height of the destination clip window
 * @return        If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks       Notice that the destination clip window is in the destination buffer coordinate.
 */
GIF_STATUS_ENUM gifDecSetDstClipWindow(GIF_DECODER_HANDLE handle,
                                        kal_int32 x, kal_int32 y,
                                        kal_uint32 width, kal_uint32 height);




/**
 * @brief         Set the source key.
 * @param handle  the decoder handle in use
 * @param srcKeyEnable     the srcKeyEnable is true that means to enable source key
 * @param srcKeyValue       the color of source key
 * @return        If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
GIF_STATUS_ENUM gifDecSetSrcKey(GIF_DECODER_HANDLE handle,
                                        kal_bool srcKeyEnable,
                                        kal_uint32 srcKeyValue);



/**
 * @brief               Query the necessary working memory for the decoder.
 * @param handle        the decoder handle in use
 * @param intMemorySize      pointer to unsigned int to obtain the internal memory size
 * @param extMemorySize      pointer to unsigned int to obtain the external memory size
 * @return              If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
GIF_STATUS_ENUM gifDecQueryWorkingMemory(GIF_DECODER_HANDLE handle,
                                            kal_uint32 *intMemorySize,
                                            kal_uint32 *extMemorySize);



/**
 * @brief            Set the necessary working memory for the decoder.
 * @param handle     the decoder handle in use
 * @param intMemoryAddr  pointer to starting address of the internal working memory
 * @param intMemorySize    size of the internal working memory
 * @param extMemoryAddr  pointer to starting address of the external working memory
 * @param extMemorySize    size of the external working memory
 * @return           If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
GIF_STATUS_ENUM gifDecSetWorkingMemory(GIF_DECODER_HANDLE handle,
                                            void *intMemoryAddr,
                                            kal_uint32 intMemorySize,
                                            void *extMemoryAddr,
                                            kal_uint32 extMemorySize);



/**
 * @brief            Set the check-abort function.
 * @param handle     the decoder handle in use
 * @param fpcheckAbort    the function pointer of check abort function
 * @return           If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks          This feature takes effect only for SW GIF decoder.
 *                   The check-abort function will be invoked before the decoding of every line of GIF image frame.
 *                   If the check abort function returns non-zero value, the decoding process will be aborted.
 */
GIF_STATUS_ENUM gifDecSetCheckAbortFunction (GIF_DECODER_HANDLE handle,
                                                        gif_check_abort fpcheckAbort);




/**
 * @brief            Set the call-back function.
 * @param handle     the decoder handle in use
 * @param fpcheckAbort    the function pointer of call-back function
 * @return           If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks          This feature takes effect only for HW GIF decoder.
 *                   the call-back function will be called after decode GIF file in read buffer.
 */
GIF_STATUS_ENUM gifDecSetCallbackFunction (GIF_DECODER_HANDLE handle,
                            void (*gif_callback)(kal_uint32 status, kal_uint32 frame_number));



/**
 * @brief            Enable or disable transparent
 * @param handle     the decoder handle in use
 * @param transparentEnable    the transparentEnable is true that means transparent enable
 * @return           If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
GIF_STATUS_ENUM gifDecSetTransparentEnable (GIF_DECODER_HANDLE handle, kal_bool transparentEnable);



/**
 * @brief         Start the decoding process.
 * @param handle  the decoder handle in use
 * @param frameNumber  the frame number of GIF image
 * @return        If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
GIF_STATUS_ENUM gifDecStart(GIF_DECODER_HANDLE handle, kal_int32 frameNumber);



/**
 * @brief         Resume the decoding process.
 * @param handle  the decoder handle in use
 * @return        If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks       If the decoder is in pause state, call gifDecResume to resume the decoding process.
 */
GIF_STATUS_ENUM gifDecResume(GIF_DECODER_HANDLE handle);



/**
 * @brief         Stop the decoding process.
 * @param handle  the decoder handle in use
 * @return        If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks       This feature takes effect only for HW GIF decoder
 */
GIF_STATUS_ENUM gifDecStop(GIF_DECODER_HANDLE handle);



/**
 * @brief         Get the state of the decoder.
 * @param handle  the decoder handle in use
 * @param state   pointer to GIF_DEC_STATE_ENUM to obtain the state
 * @return        If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
GIF_STATUS_ENUM gifDecGetState(GIF_DECODER_HANDLE handle, GIF_DEC_STATE_ENUM *state);



/**
 * @brief         Get transparent index from current frame of GIF image.
 * @param handle  the decoder handle in use
 * @param transparentIndex   pointer to obtain the transparent index
 * @return        If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
GIF_STATUS_ENUM gifDecGetTransparentIndex(GIF_DECODER_HANDLE handle, kal_uint8* transparentIndex);



/**
 * @brief         Get palette table from current frame of GIF image.
 * @param handle  the decoder handle in use
 * @param paletteAddr   pointer to obtain the palette table address
 * @param paletteSize   pointer to obtain the size of palette table
 * @return        If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
GIF_STATUS_ENUM gifDecGetPalette(GIF_DECODER_HANDLE handle, gif_color **paletteAddr, kal_uint16 *paletteSize);



/**
 * @brief         Get delay time from current frame of GIF image.
 * @param handle  the decoder handle in use
 * @param delayTime   pointer to obtain the delay time
 * @return        If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
GIF_STATUS_ENUM gifDecGetCurFrameDelayTime(GIF_DECODER_HANDLE handle, kal_uint32 *delayTime);



/**
 * @brief         Get all delay time from GIF image.
 * @param handle  the FSAL handle in use
 * @param frameCount   pointer to obtain frame number
 * @param frameDelayArray   pointer to obtain frame delay times
 * @param arraySize   the maximun size of frameDelayArray
 * @return        If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
GIF_STATUS_ENUM gifGetFrameDelay(STFSAL* pfsal,
                                        kal_int32 *frameCount,
                                        kal_uint32 *frameDelayArray,
                                        kal_uint32 arraySize);



/**
 * @brief         Get the source image dimension of the GIF image.
 * @param pfsal  pointer to the FSAL handle in use
 * @param width   pointer to obtain width of GIF image
 * @param height   pointer to obtain height of GIF image
 * @return        If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
 * @remarks
 */
GIF_STATUS_ENUM gifGetImageDimension(STFSAL* pfsal, kal_uint32 *width, kal_uint32 *height);



/**
  * @brief         Query decoder support resize or not.
  * @codecType type of decoder you request
  * @return        If support resize, the return value is GIF_STATUS_OK; otherwise the error code is returned.
  * @remarks
  */
GIF_STATUS_ENUM gifDecIsResizeSupport(GIF_DEC_TYPE_ENUM codecType);



/**
  * @brief         Reset decoder Cache.
  * @codecType type of decoder you request
  * @return         If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
  * @remarks
  */
GIF_STATUS_ENUM gifDecResetCache(GIF_DEC_TYPE_ENUM codecType);



/**
  * @brief            Query Is cache hit or not.
  * @pfsal      the pointer to FSAL handle in use
  * @x                image position
  * @y          image position
  * @codecType type of decoder you request
  * @return        If cache hit, the return value is KAL_TRUE; otherwise KAL_FALSE is returned.
  * @remarks     support sw part only
  */
kal_bool gifDecIsCacheHit(STFSAL* pfsal, kal_uint32 x, kal_uint32 y, GIF_DEC_TYPE_ENUM codecType);



/**
  * @brief        Reset cache entry
  * @pfsal        the pointer to FSAL handle in use
  * @x            image position
  * @y            image position
  * @codecType    type of decoder you request
  * @return       If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
  * @remarks
  */
GIF_STATUS_ENUM gifDecResetCacheEntry(STFSAL* pfsal, GIF_DEC_TYPE_ENUM codecType);




/**
  * @brief         Get the frame number of last decoded frame
  * @param handle  the decoder handle in use
  * @frameNumber   pointer to obtain frame number
  * @return        If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
  * @remarks
  */
GIF_STATUS_ENUM gifDecGetFrameNumberDecoded(GIF_DECODER_HANDLE handle, kal_uint32* frameNumber);


GIF_STATUS_ENUM gifDecSetDstBufferSwitchBehavior(GIF_DECODER_HANDLE handle, GFX_CACHE_SWITCH_BEHAVIOR_ENUM behavior);


GIF_STATUS_ENUM gifDecGetLastError(GIF_DECODER_HANDLE handle);


GIF_STATUS_ENUM gifCheckAnimation(STFSAL *pfsal, kal_uint32 *isAnimation);



/**
  * @brief        Query (frameIdx)th frame's disposal method
  * @handle       [IN]  the decoder handle in use. When handle is null, traverse the file from the file's begining to parse (frameIdx)th frame's disposal method.
  * @pfsal        [IN]  the pointer to FSAL handle in use
  * @frameIdx     [IN]  interested_frame index
  * @frameDisposal[OUT] disposal method
  * @return       If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
  * @remarks      This function would check GIF cache struct to get (frameIdx)th frame's disposal method. If the info not exit,
  *                  this function will then check if this file has been decoded image before? 
  *                  TRUE: traverse the file from the last read position to parse (frameIdx)th frame's disposal method. 
  *                  FALSE: traverse the file from the file's begining to parse (frameIdx)th frame's disposal method. 
  *                  Calling gifDecStart and then GIF driver construct a cache struct for this File.
  *                  When handle is null, traverse the file from the file's begining to parse (frameIdx)th frame's disposal method.
  */
GIF_STATUS_ENUM gifGetFrameNDisposalMethod(
    GIF_DECODER_HANDLE handle,
    STFSAL *pfsal,
    kal_int32 frameIdx,
    GIF_DISPOSAL_METHOD_ENUM *frameDisposal);


/**
  * @brief        Query all frames' disposal method
  * @pfsal               [IN]  the pointer to FSAL handle in use
  * @frameCount          [OUT] total frame count
  * @frameDisposalArray  [OUT] disposal method array
  * @arraySize           [IN]  disposal method array entry number
  * @return       If the function succeeds, the return value is GIF_STATUS_OK; otherwise the error code is returned.
  * @remarks      This function will traverse the file's begining to parse disposal method.
  */
GIF_STATUS_ENUM gifGetAllFrameDisposalMethod(
    STFSAL *pfsal,
    kal_int32 *frameCount, 
    GIF_DISPOSAL_METHOD_ENUM *frameDisposalArray, 
    kal_uint32 arraySize);


/*****************************************************************************
 * FUNCTION
 *  gif_sw_parse_file
 * DESCRIPTION
 *  Parse the whole GIF File, and output information to a file. This function is VC project only
 * PARAMETERS
 *  fsal_handle           [IN]  Gif file
 *  out_fsal_handle     [IN]  parser output file
 *  frame_count         [OUT]   number of frames in image
 * RETURNS
 *****************************************************************************/
GIF_STATUS_ENUM gifDecParseWholeFile(
  STFSAL* gif_fsal_handle,
  STFSAL* out_fsal_handle,
  kal_int32 *frame_count);


GIF_STATUS_ENUM gifDecSetColorPaletteFormat(GIF_DECODER_HANDLE handle,
                                          GIF_COLOR_FORMAT_ENUM colorFormat);

#endif

