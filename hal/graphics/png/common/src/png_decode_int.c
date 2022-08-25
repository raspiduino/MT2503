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
/*******************************************************************************
 * Filename:
 * ---------
 *  png_decoder_int.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  PNG HAL internal control code
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *==============================================================================
 *******************************************************************************/
 
#include "png_decoder_int.h"
#include "png_decode_structure.h"
#include "png_decode_enum.h"
#include "kal_general_types.h"
#include "rs_buffer.h"
#include "png_decode.h"
#include "fsal.h"
#include "string.h"
#include "png_decoder.h"
#include "drv_features_png.h"
    
PNG_STATUS_ENUM pngDecParseImage(PNG_DECODER_HANDLE handle)
{
    
    kal_uint32 pngImageWidth  = 0;
    kal_uint32 pngImageHeight = 0;

    #if defined(USE_HW_PNG_DECODER)
    if (PNG_DECODER_TYPE_HW == handle->decoderType)
    {
        int ret_value = 0;
        PNG_STATUS_ENUM ret_status;
        handle->g_hwpng_rsb_buf       = handle->fileBufferAddr;
        handle->g_hwpng_rsb_buf_size  = handle->fileBufferSize;
        handle->g_hwpng_read_fp  = handle->fileHandle;
        handle->g_hwpng_src_size = handle->fileSize;

        if (!handle->isRSBControlInit)
        {
            ret_value = rsbInit(&handle->g_hwpng_rsb,
                                 handle->g_hwpng_rsb_buf,
                                 handle->g_hwpng_rsb_buf_size,
                                 RSB_BIG_ENDIAN,
                                 RSB_OP_SEQUENTIAL_BUFFER);
            handle->isRSBControlInit = 1;
        }

        if (1 != ret_value)
        {
            handle->lastStatus = PNG_STATUS_ERROR_RSB_INIT_FAILED;
            return handle->lastStatus;
        }

        /// read and parsing the source image
        do
        {
            kal_uint8 *write_ptr;
            kal_bool is_src_end;
            kal_int32 read_size;

            read_size = min(rsbGetSpaceAvailable(&handle->g_hwpng_rsb), handle->g_hwpng_src_size);

            if (handle->g_hwpng_src_size == read_size)
            {
                is_src_end = KAL_TRUE;
            }
            else
            {
                is_src_end = KAL_FALSE;
            }

            rsbGetWritePointer(&handle->g_hwpng_rsb, (void **)&write_ptr);
            FSAL_Read_Bytes(handle->g_hwpng_read_fp, write_ptr, read_size);
            rsbAdjustWritePointer(&handle->g_hwpng_rsb, read_size);

            handle->g_hwpng_src_size -= read_size;
            ret_status = pngSetSourceData(&handle->g_hwpng_rsb, is_src_end);

            if ((0 == read_size) && (PNG_STATUS_DECODE_INCOMPLETE == ret_status))
            {
                ////  incomplete or truncate source
                handle->lastStatus = PNG_STATUS_INVALID_SOURCE_FILE;
                return handle->lastStatus;
            }
        } while (PNG_STATUS_DECODE_INCOMPLETE == ret_status);

        pngGetImgDimension(&pngImageWidth, &pngImageHeight);
    }
    #endif
    
    #if defined(USE_SW_PNG_DECODER)
    if (PNG_DECODER_TYPE_SW == handle->decoderType)
    {
        kal_uint8 BUFFER[24];
        kal_uint8 *buffer;

        FSAL_Peek_Bytes(handle->fileHandle, BUFFER, 24);

        buffer = BUFFER;   /// success get data

         /* PNG signature */
        if (memcmp(buffer, "\x89PNG\x0d\x0a\x1a\x0a", 8) == 0)
        {
            /* must be IHDR, length = 13, but LSB */
            if (*((kal_uint32*) (buffer + 8)) == (13 << 24))
            {
                /* must be 'IHDR' */
                if (memcmp(buffer + 12, "IHDR", 4) == 0)
                {
                    buffer += 16;
                    pngImageWidth = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | (buffer[3]);
                    buffer += 4;
                    pngImageHeight = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | (buffer[3]);
                }
            }
        }
    }
    #endif

    handle->pngImageWidth  = pngImageWidth;
    handle->pngImageHeight = pngImageHeight;

    return PNG_STATUS_OK;
}


#if defined(USE_SW_PNG_DECODER)
PNG_STATUS_ENUM pngDecSetupSWConfiguration(PNG_DECODER_HANDLE handle, png_config_struct *sw_png_cfg)
{

    /// unified buffer, set control buffer for SW PNG decoder
    sw_png_cfg->upper_buffer = handle->externalMem;

    // set source image information
    sw_png_cfg->decode_mode = PNG_DECODE_FILE;
    sw_png_cfg->file_handle = handle->fileHandle;

    sw_png_cfg->in_buffer_size = handle->fileBufferSize;
    sw_png_cfg->in_buffer_adrs = (kal_uint32)handle->fileBufferAddr;

    /// dithering only when image from file (control by GDI)
    #if defined(__SPATIAL_DITHERING__)
        sw_png_cfg->sd_enable = handle->ditheringEnable;
    #endif
    ///
    sw_png_cfg->_png_decode_progress_callback = handle->check_abort_func;
      
    // set output destination information
    sw_png_cfg->output_buffer_adrs = (kal_uint32)handle->canvasStartAddr;
    sw_png_cfg->output_buffer_size = handle->canvasBufferSize;
    sw_png_cfg->shadow_w = handle->canvasWidth;
    sw_png_cfg->shadow_h = handle->canvasHeight;
    
    sw_png_cfg->out_format = handle->canvasColorFormat;
    
    // alpha blending support
    {
        sw_png_cfg->bld_buffer_adrs = (kal_uint32)handle->blendingBufferStartAddr;

        sw_png_cfg->bld_buffer_width = handle->blendingBufferWidth;
        sw_png_cfg->bld_buffer_height = handle->blendingBufferHeight;
        
        if ((handle->blendingMode == PNG_BLEND_NONE) || (sw_png_cfg->bld_buffer_adrs == NULL))
        {
             /* output ARGB8888/ARGB6666 or PARGB8888 without alpha blending */ 
            sw_png_cfg->bld_buffer_format  = sw_png_cfg->out_format;
            sw_png_cfg->bld_buffer_width   = sw_png_cfg->shadow_w;
            sw_png_cfg->bld_buffer_height  = 0;                   
            sw_png_cfg->bld_buffer_adrs    = NULL;                        
        }
        else
        {    
            sw_png_cfg->bld_buffer_format = handle->blend_buf_format;
        }
    }

    // set clipping area
    sw_png_cfg->clip_en = KAL_TRUE;
    sw_png_cfg->clip_x1 = handle->clipWindow_ul_x;
    sw_png_cfg->clip_y1 = handle->clipWindow_ul_y;
    sw_png_cfg->clip_x2 = handle->clipWindow_dr_x;
    sw_png_cfg->clip_y2 = handle->clipWindow_dr_y;

    // set output destination area
    sw_png_cfg->dest_x = (kal_int16)handle->outputWindow_x;
    sw_png_cfg->dest_y = (kal_int16)handle->outputWindow_y;
    sw_png_cfg->expect_w = (kal_uint16) handle->outputWindowWidth;
    sw_png_cfg->expect_h = (kal_uint16) handle->outputWindowHeight;


    if (handle->clrRepEnable)
    {
        kal_uint32 src_key_value; 
        
        if (PNG_FORMAT_RGB565 == handle->canvasColorFormat)
        {
            src_key_value = (handle->newRepColor_R & 0x1F) << 11 |
                            (handle->newRepColor_G & 0x3F) << 5  |
                            (handle->newRepColor_B & 0x1F);
        }
        else if (PNG_FORMAT_ARGB6666 == handle->canvasColorFormat) 
        {
            src_key_value = (handle->newRepColor_R & 0x3F) << 12 |
                            (handle->newRepColor_G & 0x3F) << 6  |
                            (handle->newRepColor_B & 0x3F);
        }
        else
        {
            src_key_value = (handle->newRepColor_R |
                             handle->newRepColor_G |
                             handle->newRepColor_B);
        }
        sw_png_cfg->src_key = src_key_value;
    }
    else
    {
        sw_png_cfg->src_key = 0x01ffffff;
    }

    // misc
    sw_png_cfg->cal_work_buffer_info_func = NULL;
    sw_png_cfg->png_timeout_period = handle->timeoutMsec;

    return PNG_STATUS_OK;
}
#endif
