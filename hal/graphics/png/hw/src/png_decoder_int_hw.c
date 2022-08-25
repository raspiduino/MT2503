/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *    png_decoder_int_hw.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   PNG decoder API
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
/// #include "drv_comm.h" 

#include "kal_general_types.h"
#include "png_drv_common.h"
#include "rs_buffer.h"
#include "png_decode_enum.h"
#include "png_info.h"
#include "png_status.h"
#include "kal_public_api.h"
#include "png_decode_structure.h"
#include "string.h"
#include "drv_features_png.h"    

#if defined(USE_HW_PNG_DECODER)

#include "png_decode.h"
#include "png_chunk.h"

#define SIG_BYTES_TO_CHECK          8
#define SIG_START_OFFSET            0
#define TYPE_FIELD_IN_BYTES         4
#define LENGTH_FIELD_IN_BYTES       4
#define CRC_FIELD_IN_BYTES          4

#define PALETTE_MAX_ENTRY           256

#define PNG_COLOR_MASK_PALETTE   1
#define PNG_COLOR_MASK_COLOR     2
#define PNG_COLOR_MASK_ALPHA     4


typedef enum {
   PARSER_STATE_READ_LEN = 0,
   PARSER_STATE_READ_TYPE,
   PARSER_STATE_READ_DATA,
   PARSER_STATE_READ_CRC
} PARSER_STATE_ENUM;


/**
 * @brief this struct is to maintain information currently parsed
 */
typedef struct PARSER_INFO_T {

   kal_uint32 mode;                             ///< check chunk ordering
   kal_uint32 crc;                              ///< crc of current parsed chunk
   kal_uint32 data_len;                         ///< data filed size of current parsed chunk
   kal_uint8 chunk_name[TYPE_FIELD_IN_BYTES];   ///< type name of current parsed chunk
   PNG_CHUNK_TYPE chunk_type;                   ///< type enum of current parsed chunk
   PARSER_STATE_ENUM state;                     ///< parser state must be maintained for streaming file parsing
   kal_uint32 read_data_bytes;                  ///< parsed bytes of a chunk

} PARSER_INFO;


static callback_func_ptr _png_callback = NULL;      // callback function
static RS_BUFFER *_local_rsb = NULL;
volatile static PNG_DECODER_STATE_ENUM _decoder_state = PNG_DECODER_STATE_IDLE;
static PARSER_INFO _parser_st = {0};
static MY_PNG_INFO _png_st = {0};
static PNG_HW_INFO _hwcfg_st = {0};

// valid bit depth is given by color type index
static kal_uint8 color_depth_mask[7] = {
   0x1F,     //Greyscale: 1, 2, 4, 8, 16     8b'00011111
   0,
   0x18,     // RGB: 8, 16                   8b'00011000
   0x0F,     // Palette: 1, 2, 4, 8          8b'00001111
   0x18,     // GA: 8, 16                    8b'00011000
   0,
   0x18      // RGBA: 8, 16                  8b'00011000
};


// internal API
static void _pngInterruptHandler(PNG_STATUS_ENUM decode_ret);
static PNG_PARSE_RET _pngHeaderParser(RS_BUFFER *rsb);
static PNG_PARSE_RET _pngSignature(kal_uint8* sig, kal_uint8 start, kal_uint8 num_to_check);
static void _setChunkType(void);
static PNG_PARSE_RET _pngIHDR(RS_BUFFER *rsb);
static PNG_PARSE_RET _pngPLTE(RS_BUFFER *rsb);
static PNG_PARSE_RET _pngtRNS(RS_BUFFER *rsb);
static PNG_PARSE_RET _pngbKGD(RS_BUFFER *rsb);
static PNG_PARSE_RET _pngIDAT(RS_BUFFER *rsb);
static PNG_PARSE_RET _pngIEND(RS_BUFFER *rsb);
static PNG_PARSE_RET _pngUnknown(RS_BUFFER *rsb);



PNG_STATUS_ENUM
pngInit(void)
{
   PNG_STATUS_ENUM ret;

   //!!! DO NOT change the following invoking order
   ret = png_drv_poweron();
   pngReset();

   return ret;
}



PNG_STATUS_ENUM pngFinalize(void)
{
   // verify decoder state
   if (PNG_DECODER_STATE_DECODING == _decoder_state)
   {
      return PNG_STATUS_INVALID_OPERATION;
   }

   return (png_drv_poweroff());
}



/**
 *  @brief the function will be invoked after hw png decoder raises an interrupt
     then GDI/AP registered callback function will be invoked in this function
 *  @param decode_ret decoder status indicated by PNG_STATUS_ENUM
 */
static void
_pngInterruptHandler(PNG_STATUS_ENUM decode_ret)
{
   kal_uint32 hw_count;

   if (PNG_DECODER_STATE_DECODING != _decoder_state)
   {
      /// GDI timeout in advance (assume pngReset() is invoked to reset state)
      /// ignore hw interrupt
      return;
   }

   // change decoder state
   _decoder_state = PNG_DECODER_STATE_PAUSE;

   // maintain png internal state
   switch (decode_ret) 
   {
      case PNG_STATUS_OK:
         break;

      case PNG_STATUS_DECODE_INCOMPLETE:
         // must rearrange buffer
         png_drv_get_comsumed_bytes(&hw_count);
         rsbAdjustReadPointer(_local_rsb, (kal_int32)hw_count);
         rsbRearrangeBuffer(_local_rsb);
         break;
         
      case PNG_STATUS_DECODE_TIMEOUT:
         png_drv_reset();

      default:
         png_drv_reset();
         // decode error
         break;
   }
   
   if (_png_callback)
   {    
      (*_png_callback)(decode_ret);
   }     
   
}



PNG_STATUS_ENUM
pngHookCallback(callback_func_ptr callback_func)
{
   if (!callback_func)
   {
      ASSERT(0);
   }

   _png_callback = callback_func;

   _hwcfg_st.ifSetCallback = KAL_TRUE;

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
pngSetWorkingBuffer(kal_uint32 *internalBuf, kal_uint32 *externalBuf)
{
   PNG_STATUS_ENUM   ret;

   if (!externalBuf)
   {
      ASSERT(0);
   }

   ret = png_drv_set_working_buffer(internalBuf, externalBuf, &_hwcfg_st);

   if (PNG_STATUS_OK != ret)
   {
      return ret;
   }

   _hwcfg_st.ifSetWorkingBuffer = KAL_TRUE;

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
pngSetSourceData(RS_BUFFER *rsb, kal_bool is_src_end)
{
   void *read_ptr;
   kal_int32 count;

   // verify source buffer pointer
   if (!rsb)
   {
      ASSERT(0);
   }

   if (!_hwcfg_st.ifSetWorkingBuffer)
   {  // working buffer must be set at first
      return PNG_STATUS_INVALID_OPERATION;
   }

   // verify decoder state
   if (PNG_DECODER_STATE_DECODING == _decoder_state)
   {
      return PNG_STATUS_IN_DECODING;
   }

   // IDAT chunk has not been parsed yet
   if (!(_parser_st.mode & PNG_HAVE_IDAT))
   {
      PNG_PARSE_RET ret;
      
      ret = _pngHeaderParser(rsb);

      if (PNG_PARSE_RET_INCOMPLETE == ret)
      {
         return PNG_STATUS_DECODE_INCOMPLETE;
      }
      else
      {
         // invalid source png image
         return PNG_STATUS_INVALID_SOURCE_FILE;
      }
   }
   else
   {
      // IDAT has been parsed
      _local_rsb = rsb;  // for hw interrrupt to update consumed bytes

      // hw decoder must start from IDAT.length
      rsbGetReadPointer(rsb, (void **)&read_ptr);
      count = rsbGetDataAvailable(rsb);
      png_drv_set_source_data((kal_uint32)read_ptr, count, is_src_end);
      _hwcfg_st.ifSetSourceData = KAL_TRUE;

      return PNG_STATUS_OK;
   }
}



PNG_STATUS_ENUM
pngSetCanvas(void *canvas_start_adr,
             kal_int32 width,
             kal_int32 height,
             PNG_DECODE_COLOR_FORMAT_ENUM out_color_format)
{
   if (!canvas_start_adr )
   {
      ASSERT(0);
   }

   _hwcfg_st.canvasStartAddr = canvas_start_adr;
   _hwcfg_st.canvas_width = width;
   _hwcfg_st.canvas_height = height;
   _hwcfg_st.canvasColorFormat = out_color_format;
   _hwcfg_st.ifSetCanvas = KAL_TRUE;

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
pngSetOutputWindow(kal_int32 up_left_x,
                   kal_int32 up_left_y,
                   kal_int32 dst_w,
                   kal_int32 dst_h)
{
   _hwcfg_st.outputWindow_x = up_left_x;
   _hwcfg_st.outputWindow_y = up_left_y;
   _hwcfg_st.outputWindowWidth = dst_w;
   _hwcfg_st.outputWindowHeight = dst_h;
   _hwcfg_st.ifSetOutputWindow = KAL_TRUE;

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
pngSetClipWindow(kal_int32 up_left_x,
                 kal_int32 up_left_y,
                 kal_int32 down_right_x,
                 kal_int32 down_right_y)
{
   _hwcfg_st.clipWindow_ul_x = up_left_x;
   _hwcfg_st.clipWindow_ul_y = up_left_y;
   _hwcfg_st.clipWindow_dr_x = down_right_x;
   _hwcfg_st.clipWindow_dr_y = down_right_y;
   _hwcfg_st.ifSetClipWindow = KAL_TRUE;

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
pngSetAlphaValue(kal_int32 userAlpha)
{
   _hwcfg_st.userSetAlphaValue = userAlpha;
   
   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
pngSetBlendingMode(PNG_BLEND_MODE_ENUM mode, PNG_DECODE_COLOR_FORMAT_ENUM color_format)
{
   _hwcfg_st.blendingMode = mode;
   _hwcfg_st.blend_buf_format = color_format;

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
pngSetBlendingBuffer(void *blend_buf_adr)
{
   if (!blend_buf_adr)
   {
      ASSERT(0);
   }

   _hwcfg_st.blendingBufferStartAddr = blend_buf_adr;

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
pngSetReplaceColor(png_color orgColor, png_color newColor)
{
   _hwcfg_st.orgReplacedColor = orgColor;
   _hwcfg_st.newReplaceColor = newColor;
   _hwcfg_st.ifSetColorReplacing = KAL_TRUE;

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
pngSetTimeoutValue(kal_int32 timeout_msec)
{
   _hwcfg_st.timeoutMsec = timeout_msec;

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
pngDecodeStart(void)
{
   PNG_STATUS_ENUM ret;

   if (PNG_DECODER_STATE_RESET != _decoder_state)
   {
       return PNG_STATUS_INVALID_OPERATION;
   }

   if (_hwcfg_st.ifSetWorkingBuffer &&
       _hwcfg_st.ifSetSourceData &&
       _hwcfg_st.ifSetCanvas &&
       _hwcfg_st.ifSetOutputWindow 
      )
   {
       _decoder_state = PNG_DECODER_STATE_READY;
   }

   // make sure mandatory function is invoked
   if (PNG_DECODER_STATE_READY != _decoder_state)
   {
      return PNG_STATUS_INVALID_OPERATION;
   }

   // set registers and trigger png HW decoder
   _decoder_state = PNG_DECODER_STATE_DECODING;
   ret =  png_drv_decode_start(&_hwcfg_st, &_png_st);
   if (PNG_STATUS_OK != ret)
   {
      _decoder_state = PNG_DECODER_STATE_READY;
   }

   return ret;
}



PNG_STATUS_ENUM
pngDecodeResume(void)
{

   if (_decoder_state != PNG_DECODER_STATE_PAUSE)
   {
      return PNG_STATUS_INVALID_OPERATION;
   }

   // NEW source data must be set before resume decoding
   if (!_hwcfg_st.ifSetSourceData)
   {
      return PNG_STATUS_INVALID_OPERATION;
   }

   _decoder_state = PNG_DECODER_STATE_DECODING;
   // to prevent next time resume without setting new source data
   _hwcfg_st.ifSetSourceData = KAL_FALSE;
   png_drv_decode_resume(&_hwcfg_st);

   return PNG_STATUS_OK;
}



PNG_STATUS_ENUM
pngReset(void)
{

   // reset decoder data structure
   (*png_memset)(&_parser_st, 0, sizeof(PARSER_INFO));
   (*png_memset)(&_png_st, 0, sizeof(MY_PNG_INFO));
   (*png_memset)(&_hwcfg_st, 0, sizeof(PNG_HW_INFO));

   _decoder_state = PNG_DECODER_STATE_RESET;
   _parser_st.state = PARSER_STATE_READ_LEN;

   _png_callback = NULL;    // callback function
   _local_rsb = NULL;

   png_drv_reset();
   
   png_drv_hook_irq_callback(&_pngInterruptHandler);

   return PNG_STATUS_OK;
}



/**
 *  @brief get the working buffer size that hw PNG Decoder required
 *  @param internal_mem_sz return internal memory size used by hw png decoder
 *  @param external_mem_sz return external memory size used by hw png decoder
 */
PNG_STATUS_ENUM
pngGetWorkingBufferSize(kal_uint32* internal_mem_sz, kal_uint32* external_mem_sz)
{

   png_drv_get_working_buffer_size(internal_mem_sz, external_mem_sz);

   return PNG_STATUS_OK;

}



/**
 *  @brief Return the image width and height (in pixel) parsed from png header
 */
PNG_STATUS_ENUM
pngGetImgDimension(kal_int32* src_w, kal_int32* src_h)
{

   if (!src_w || !src_h)
   {
      ASSERT(0);
   }

   if (!(_parser_st.mode & PNG_HAVE_IHDR))
   {
      // source image has been parsed
      return PNG_STATUS_INVALID_OPERATION;
   }
   else
   {
      *src_w = _png_st.width;
      *src_h = _png_st.height;
      return PNG_STATUS_OK;
   }

}



/**
 *  @brief output the file build-in background color when transparent
 */
PNG_STATUS_ENUM
pngSetBgColorOut(void)
{
   png_drv_set_bg_color_out(&_png_st);
   
   return PNG_STATUS_OK; 
}


kal_int32
pngFileAlphaExist(void)
{
	// this API should be invoked after png image is parsed
	if (!_hwcfg_st.ifSetSourceData)
	{
	  return -1;  // image information is not parsed
	}
	
	if ((_png_st.num_trans > 0) ||
      (PNG_COLOR_TYPE_GA == _png_st.color_type) ||
      (PNG_COLOR_TYPE_RGBA == _png_st.color_type))
	{
		return 1;  // file alpha exists
  }
  else
  {
  	return 0; // no file alpha
  }
}



kal_int32
pngFileTransparencyExist(void)
{
	// this API should be invoked after png image is parsed
	if (!_hwcfg_st.ifSetSourceData)
	{
	   return -1;  // image information is not parsed
	}
	
	if (_png_st.num_trans > 0)
	{
		return 1;  // file transparency exists
    }
    else
    {
    	return 0; // no file transparency
    }
}



PNG_STATUS_ENUM
pngGetDecodeStatus(void)
{
   kal_int32 status_code = -1;
   
   png_drv_get_decode_status(&status_code);
   
   return (PNG_STATUS_ENUM)status_code;
   
}


/// Robin, new added-in API
PNG_STATUS_ENUM
pngGetDecodeState(PNG_DECODER_STATE_ENUM *decodeState)
{
    *decodeState = _decoder_state;  
    return PNG_STATUS_OK;
}


static PNG_PARSE_RET
_pngHeaderParser(RS_BUFFER *rsb)
{

   PNG_PARSE_RET ret;
   kal_uint8 *read_ptr;
   kal_int32 count;

   if (!(_parser_st.mode & PNG_HAVE_SIGNATURE))
   {
      //first soruce buffer
      // check 8-byte signature
      kal_int32 count = rsbGetReadPointer(rsb, (void **)&read_ptr);
      ASSERT(8 <= count);
      ret = _pngSignature(read_ptr, SIG_START_OFFSET, SIG_BYTES_TO_CHECK);
      if (ret != PNG_PARSE_RET_OK)
      {
         return ret;
      }
      _parser_st.state = PARSER_STATE_READ_LEN;
      rsbAdjustReadPointer(rsb, SIG_BYTES_TO_CHECK);
   }

   do
   {
      if (PARSER_STATE_READ_LEN == _parser_st.state)
      {
         count = rsbGetDataAvailable(rsb);
         if (LENGTH_FIELD_IN_BYTES > count)
         {
            rsbRearrangeBuffer(rsb);            
            return PNG_PARSE_RET_INCOMPLETE;
         }
         rsbReadUint32(rsb, &_parser_st.data_len);
         // chunk length is parsed successfully
         _parser_st.state = PARSER_STATE_READ_TYPE;

      }
      else if (PARSER_STATE_READ_TYPE == _parser_st.state)
      {
         count = rsbGetDataAvailable(rsb);
         if (TYPE_FIELD_IN_BYTES > count)
         {
            rsbAdjustReadPointer(rsb, -4);            
            rsbRearrangeBuffer(rsb);            
            rsbAdjustReadPointer(rsb, 4);            
            return PNG_PARSE_RET_INCOMPLETE;
         }

         rsbReadUint8(rsb, &(_parser_st.chunk_name[0]));
         rsbReadUint8(rsb, &(_parser_st.chunk_name[1]));
         rsbReadUint8(rsb, &(_parser_st.chunk_name[2]));
         rsbReadUint8(rsb, &(_parser_st.chunk_name[3]));

         _setChunkType();
         _parser_st.state = PARSER_STATE_READ_DATA;

      }
      else if (PARSER_STATE_READ_DATA == _parser_st.state)
      {
         //  handle chunks according to the chunk type
         if (PNG_CHUNK_IHDR == _parser_st.chunk_type)
         {
            ret = _pngIHDR(rsb);
         }
         else if ( PNG_CHUNK_PLTE == _parser_st.chunk_type)
         {
            ret = _pngPLTE(rsb);
         }
         else if (PNG_CHUNK_tRNS == _parser_st.chunk_type)
         {
            ret = _pngtRNS(rsb);
         }
         else if (PNG_CHUNK_bKGD == _parser_st.chunk_type)
         {
            ret = _pngbKGD(rsb);
         }
         else if (PNG_CHUNK_IDAT == _parser_st.chunk_type)
         {
            ret = _pngIDAT(rsb);
         }
         else if (PNG_CHUNK_IEND == _parser_st.chunk_type)
         {
            // should not entered
            ret = _pngIEND(rsb);
         }
         else
         {
            ret = _pngUnknown(rsb);
         }

         if (PNG_PARSE_RET_OK == ret)
         {
            //  data field has been fully parsed
            _parser_st.state = PARSER_STATE_READ_CRC;
         }
         else if (PNG_PARSE_RET_INCOMPLETE == ret)
         {
            // parse  incomplete
            return ret;
         }
         else
         {
            // parse fail, reset buffer and internal structure
            pngReset();
            rsbPurge(rsb);
            return ret;
         }
      }
      else if (PARSER_STATE_READ_CRC == _parser_st.state)
      {
         count = rsbGetDataAvailable(rsb);
         if (CRC_FIELD_IN_BYTES > count)
         {
            rsbRearrangeBuffer(rsb);            
            return PNG_PARSE_RET_INCOMPLETE;
         }
         // skip CRC 4 bytes
         rsbAdjustReadPointer(rsb, CRC_FIELD_IN_BYTES);         
         _parser_st.state = PARSER_STATE_READ_LEN;
      }
      else
      {
          ASSERT(0);
      }

   } while(KAL_TRUE);

   return PNG_PARSE_RET_OK;

}



static void
_setChunkType(void)
{
   if (!(*png_memcmp)((void *)&(_parser_st.chunk_name[0]), "IHDR", TYPE_FIELD_IN_BYTES))
   {
      _parser_st.chunk_type = PNG_CHUNK_IHDR;
   }
   else if (!(*png_memcmp)((void *)&(_parser_st.chunk_name[0]), "PLTE", TYPE_FIELD_IN_BYTES))
   {
      _parser_st.chunk_type = PNG_CHUNK_PLTE;
   }
   else if (!(*png_memcmp)((void *)&(_parser_st.chunk_name[0]), "tRNS", TYPE_FIELD_IN_BYTES))
   {
      _parser_st.chunk_type = PNG_CHUNK_tRNS;
   }
   else if (!(*png_memcmp)((void *)&(_parser_st.chunk_name[0]), "bKGD", TYPE_FIELD_IN_BYTES))
   {
      _parser_st.chunk_type = PNG_CHUNK_bKGD;
   }
   else if (!(*png_memcmp)((void *)&(_parser_st.chunk_name[0]), "IDAT", TYPE_FIELD_IN_BYTES))
   {
      _parser_st.chunk_type = PNG_CHUNK_IDAT;
   }
   else if (!(*png_memcmp)((void *)&(_parser_st.chunk_name[0]), "IEND", TYPE_FIELD_IN_BYTES))
   {
      // should not entered
      _parser_st.chunk_type = PNG_CHUNK_IEND;
   }
   else
   {
      // handle unknown type chunk
      _parser_st.chunk_type = PNG_CHUNK_UNKNOWN;
   }
}



static PNG_PARSE_RET
_pngSignature(kal_uint8* sig, kal_uint8 start, kal_uint8 num_to_check)
{
   kal_uint32 ret;
   kal_uint8 png_signature[8] = {137, 80, 78, 71, 13, 10, 26, 10};

   if (num_to_check > 8)
   {
      num_to_check = 8;
   }
   else if (num_to_check < 1)
   {
      return (PNG_PARSE_RET_SIG_FEW_BYTE_CHECKED);
   }

   if (start > 7)
   {
      return (PNG_PARSE_RET_SIG_OFFSET_OVER);
   }

   if (start + num_to_check > 8)
   {
      num_to_check = 8 - start;
   }

   ret = (*png_memcmp)(sig+start, &png_signature[start], num_to_check);
   if ( 0 == ret)
   {
      _parser_st.mode |= PNG_HAVE_SIGNATURE;
      return PNG_PARSE_RET_OK;
   }
   else
   {
     return PNG_PARSE_RET_SIG_NOT_PNG;
   }

}




static PNG_PARSE_RET
_pngIHDR(RS_BUFFER *rsb)
{
   kal_uint8 tmp_value;
   kal_int32 count;

   if (_parser_st.chunk_type != PNG_CHUNK_IHDR)
   {
      ASSERT(0);
   }

   // verify IHDR chunk order
   if (_parser_st.mode & PNG_HAVE_IHDR)
   {
      return PNG_PARSE_RET_IHDR_INVALID_ORDER;
   }

   // verify IHDR chunk data length
   if ( _parser_st.data_len != 13)
   {
      return PNG_PARSE_RET_IHDR_INVALID_DATA_LENGTH;
   }

   //----------------IHDR data field--------------------------
   count = rsbGetDataAvailable(rsb);
   if (13 > count)
   {
      rsbAdjustReadPointer(rsb, -8);      
      rsbRearrangeBuffer(rsb);      
      rsbAdjustReadPointer(rsb, 8);      
      return PNG_PARSE_RET_INCOMPLETE;
   }

   //Width
   rsbReadUint32(rsb, &_png_st.width);
   if (0 == _png_st.width)
   {
      return PNG_PARSE_RET_IHDR_INVALID_WIDTH;
   }

   //Height
   rsbReadUint32(rsb, &_png_st.height);
   if (0 == _png_st.height)
   {
      return PNG_PARSE_RET_IHDR_INVALID_HEIGHT;
   }

   //Bit depth
   rsbReadUint8(rsb,  &_png_st.bit_depth);
   // bit depth error checking is delayed until color type is parsed

   //Color Type
   rsbReadUint8(rsb,  &_png_st.color_type);
   tmp_value = _png_st.color_type;
   if (tmp_value != 0  && tmp_value != 2  && tmp_value != 3  && tmp_value != 4  && tmp_value != 6 )
   {
      return PNG_PARSE_RET_IHDR_INVALID_COLOR_TYPE;
   }

   // check bit depth
   if (!(color_depth_mask[_png_st.color_type] & _png_st.bit_depth))
   {
      return PNG_PARSE_RET_IHDR_INVALID_BIT_DEPTH;
   }

   //compression method
   rsbReadUint8(rsb, &_png_st.compression_method);
   if (_png_st.compression_method != 0)
   {
      return PNG_PARSE_RET_IHDR_INVALID_COMPRESSION_METHOD;
   }

   //filter method
   rsbReadUint8(rsb, &_png_st.filter_method);
   if (_png_st.filter_method != 0)
   {
      return PNG_PARSE_RET_IHDR_INVALID_FILTER_METHOD;
   }

   //interlace method
   rsbReadUint8(rsb, &_png_st.interlace_method);
   if ((_png_st.interlace_method != 0) && (_png_st.interlace_method != 1))
   {
      return PNG_PARSE_RET_IHDR_INVALID_INTERLACE_METHOD;
   }

   _parser_st.mode |= PNG_HAVE_IHDR;
   return PNG_PARSE_RET_OK;
}



static PNG_PARSE_RET
_pngPLTE(RS_BUFFER *rsb)
{
   kal_uint32 pal_in_bytes;
   kal_uint32 max_pal_bytes;
   kal_uint32 valid_pal_entry;
   kal_int32 count;
   kal_uint8 *read_ptr;

   if (_parser_st.chunk_type != PNG_CHUNK_PLTE)
   {
      ASSERT(0);
   }

   // verify PLTE chunk order
   if (!(_parser_st.mode & PNG_HAVE_IHDR))
   {
      return PNG_PARSE_RET_PLTE_INVALID_ORDER_NO_IHDR_AHEAD;
   }
   else if (_parser_st.mode & PNG_HAVE_IDAT)
   {
      return PNG_PARSE_RET_PLTE_INVALID_ORDER_AFTER_IDAT;
   }
   else if (_parser_st.mode & PNG_HAVE_PLTE)
   {
      return PNG_PARSE_RET_PLTE_DUPLICATED;
   }

   if (!(_png_st.color_type & PNG_COLOR_MASK_COLOR))
   {
      return PNG_PARSE_RET_PLTE_ABSENCE_FOR_THIS_COLOR_TYPE;
   }

   // verify PLTE chunk data length
   pal_in_bytes = _parser_st.data_len;
   valid_pal_entry = (0x1 << _png_st.bit_depth); // bit-depth means the number of bits per index in palette type
   if (!valid_pal_entry)
   {
      valid_pal_entry = PALETTE_MAX_ENTRY;
   }
   max_pal_bytes = sizeof(png_color) * valid_pal_entry;

   if( pal_in_bytes > max_pal_bytes ||  (pal_in_bytes % sizeof(png_color)) != 0 )
   {
      return PNG_PARSE_RET_PLTE_INVALID_DATA_LENGTH;
   }

   //--------------------PLTE data field-----------------------

   // set the number of palette entries
   _png_st.num_palette = _parser_st.data_len / sizeof(png_color);

   count = rsbGetDataAvailable(rsb);
   if (_parser_st.data_len > (kal_uint32)count)
   {
      rsbAdjustReadPointer(rsb, -8);      
      rsbRearrangeBuffer(rsb);      
      rsbAdjustReadPointer(rsb, 8);      
      return PNG_PARSE_RET_INCOMPLETE;
   }

   ASSERT(_parser_st.data_len <= (kal_uint32)rsbGetReadPointer(rsb, (void **)&read_ptr));
   png_drv_fill_palette((kal_uint32*)_hwcfg_st.colorTableStartAddr, read_ptr, _parser_st.data_len);
   ASSERT(_parser_st.data_len == (kal_uint32)rsbAdjustReadPointer(rsb, _parser_st.data_len));

   _parser_st.mode |= PNG_HAVE_PLTE;
   _png_st.valid |= PNG_INFO_PLTE;
   return PNG_PARSE_RET_OK;

}



static PNG_PARSE_RET
_pngtRNS(RS_BUFFER *rsb)
{
   kal_uint32 bit_depth_mask;
   kal_int32 count;
   kal_uint8 *read_ptr;

   //for non-indexed color, mask off any bits in the tRNS value that
   // exceed the bit depth
   bit_depth_mask =  (1 << _png_st.bit_depth) - 1;

   if (_parser_st.chunk_type != PNG_CHUNK_tRNS)
   {
      ASSERT(0);
   }

   //verify tRNS chunk order
   if (!(_parser_st.mode & PNG_HAVE_IHDR))
   {
      return PNG_PARSE_RET_tRNS_INVALID_ORDER_NO_IHDR_AHEAD;
   }
   else if ((PNG_COLOR_TYPE_PALETTE == _png_st.color_type) &&
           !(_png_st.valid & PNG_INFO_PLTE))
   {
      return PNG_PARSE_RET_tRNS_INVALID_ORDER_NO_PLTE_AHEAD;
   }
   else if (_parser_st.mode & PNG_HAVE_IDAT)
   {
      return PNG_PARSE_RET_tRNS_INVALID_ORDER_AFTER_IDAT;
   }
   else if (_png_st.valid & PNG_INFO_tRNS)
   {
      return PNG_PARSE_RET_tRNS_DUPLICATED;
   }

   // ----------------tRNS data field-----------------------
   count = rsbGetDataAvailable(rsb);
   if (_parser_st.data_len > (kal_uint32)count)
   {
      rsbAdjustReadPointer(rsb, -8);      
      rsbRearrangeBuffer(rsb);      
      rsbAdjustReadPointer(rsb, 8);      
      return PNG_PARSE_RET_INCOMPLETE;
   }

   if (PNG_COLOR_TYPE_GRAY == _png_st.color_type)
   {
      if (_parser_st.data_len != 2)
      {
         //  2 bytes for a transparent greyscale value
         return PNG_PARSE_RET_tRNS_INVALID_DATA_LENGTH;
      }
      _png_st.num_trans = 1;
      rsbReadUint16(rsb, &(_png_st.trans.gray));
      _png_st.trans.gray &= bit_depth_mask;
   }
   else if (PNG_COLOR_TYPE_RGB == _png_st.color_type)
   {
      if (_parser_st.data_len != 6)
      {
         return PNG_PARSE_RET_tRNS_INVALID_DATA_LENGTH;
      }

      _png_st.num_trans = 1;
      rsbReadUint16(rsb, &(_png_st.trans.red));
      _png_st.trans.red &= bit_depth_mask;
      rsbReadUint16(rsb, &(_png_st.trans.green));
      _png_st.trans.green &= bit_depth_mask;
      rsbReadUint16(rsb, &(_png_st.trans.blue));
      _png_st.trans.blue &= bit_depth_mask;
   }
   else if (PNG_COLOR_TYPE_PALETTE == _png_st.color_type)
   {
      if (_parser_st.data_len > _png_st.num_palette ||
          _parser_st.data_len > PALETTE_MAX_ENTRY)
      {
         return PNG_PARSE_RET_tRNS_INVALID_DATA_LENGTH;
      }

      if (0 == _parser_st.data_len)
      {
         _png_st.num_trans = 0;
      }
      else
      {
         kal_int32 count = rsbGetReadPointer(rsb, (void **)&read_ptr);
         ASSERT(_parser_st.data_len <= (kal_uint32)count);
         png_drv_fill_alpha_table((kal_uint32*)_hwcfg_st.trnsTableAddr, read_ptr, _parser_st.data_len, _png_st.num_palette);
         count = rsbAdjustReadPointer(rsb, _parser_st.data_len);
         ASSERT(_parser_st.data_len == (kal_uint32)count);
         // actual trans number should be equal to palette entry number
         // note: the data length may be less then palette entry number
         _png_st.num_trans = _parser_st.data_len;
      }
   }
   else
   {
      _png_st.num_trans = 0;
      return PNG_PARSE_RET_tRNS_INVALID_FOR_THIS_COLOR_TYPE;
   }

   _png_st.valid |= PNG_INFO_tRNS;
   return PNG_PARSE_RET_OK;
}



static PNG_PARSE_RET
_pngbKGD(RS_BUFFER *rsb)
{
   kal_uint32 valid_data_len;
   png_color_16 entry;
   kal_int32 count;

   if (_parser_st.chunk_type != PNG_CHUNK_bKGD)
   {
      ASSERT(0);
   }

   //verify bKGD chunk order
   if (!(_parser_st.mode & PNG_HAVE_IHDR))
   {
      return PNG_PARSE_RET_bKGD_INVALID_ORDER_NO_IHDR_AHEAD;
   }
   else if (( PNG_COLOR_TYPE_PALETTE == _png_st.color_type) &&
            !(_png_st.valid & PNG_INFO_PLTE))
   {
      return PNG_PARSE_RET_bKGD_INVALID_ORDER_NO_PLTE_AHEAD;
   }
   else if (_parser_st.mode & PNG_HAVE_IDAT)
   {
      return PNG_PARSE_RET_bKGD_INVALID_ORDER_AFTER_IDAT;
   }
   else if (_png_st.valid & PNG_INFO_bKGD)
   {
      return PNG_PARSE_RET_bKGD_DUPLICATED;
   }

   // ------------------bKGD data field-------------------------
   if (PNG_COLOR_TYPE_PALETTE == _png_st.color_type)
   {
      valid_data_len = 1;  // 1 bytes:  palette index of the color to be used as background
   }
   else if (_png_st.color_type & PNG_COLOR_MASK_COLOR)
   {
      valid_data_len = 6;  // 6 bytes: RGB sample value seperately to be used as background
   }
   else if (PNG_COLOR_TYPE_GRAY == _png_st.color_type ||
            PNG_COLOR_TYPE_GA == _png_st.color_type)
   {
      valid_data_len = 2;  // 2 bytes: Greyscale value to be used as background
   }
   else
   {
      return PNG_PARSE_RET_INVALID_COLOR_TYPE;
   }

   if (_parser_st.data_len != valid_data_len)
   {
      return PNG_PARSE_RET_bKGD_INVALID_DATA_LENGTH;
   }

   count = rsbGetDataAvailable(rsb);
   if (_parser_st.data_len > (kal_uint32)count)
   {
      rsbAdjustReadPointer(rsb, -8);      
      rsbRearrangeBuffer(rsb);      
      rsbAdjustReadPointer(rsb, 8);      
      return PNG_PARSE_RET_INCOMPLETE;
   }

   if (PNG_COLOR_TYPE_PALETTE == _png_st.color_type)
   {
      if (_png_st.num_palette)
      {
         rsbReadUint8(rsb, &_png_st.background.index);
         if (_png_st.background.index > _png_st.num_palette)
         {
            return PNG_PARSE_RET_bKGD_INVALID_PALETTE_INDEX;
         }

         png_drv_get_plt_entry((kal_uint32*)_hwcfg_st.colorTableStartAddr, _png_st.background.index, &entry);

         _png_st.background.red = entry.red;
         _png_st.background.green = entry.green;
         _png_st.background.blue = entry.blue;
      }
   }
   else if (_png_st.color_type & PNG_COLOR_MASK_COLOR)
   {
      // RGB or RGBA
      rsbReadUint16(rsb, &_png_st.background.red);
      rsbReadUint16(rsb, &_png_st.background.green);
      rsbReadUint16(rsb, &_png_st.background.blue);
   }
   else
   {
      // Grey or GA
      rsbReadUint16(rsb, &_png_st.background.gray);
   }

   _png_st.valid |= PNG_INFO_bKGD;
   return PNG_PARSE_RET_OK;
}



static PNG_PARSE_RET
_pngIDAT(RS_BUFFER *rsb)
{
   if (_parser_st.chunk_type != PNG_CHUNK_IDAT)
   {
      ASSERT(0);
   }

   // verify the first IDAT chunk order
   if (!(_parser_st.mode & PNG_HAVE_IHDR))
   {
      return PNG_PARSE_RET_IDAT_INVALID_ORDER_NO_IHDR_AHEAD;
   }
   else if (( PNG_COLOR_TYPE_PALETTE == _png_st.color_type) &&
            !(_png_st.valid & PNG_INFO_PLTE))
   {
      return PNG_PARSE_RET_IDAT_INVALID_ORDER_NO_PLTE_AHEAD;
   }

   rsbGetDataAvailable(rsb);
   rsbAdjustReadPointer(rsb, -8);   
   rsbRearrangeBuffer(rsb);   
   _parser_st.mode |= PNG_HAVE_IDAT;

   return PNG_PARSE_RET_INCOMPLETE;
}



static PNG_PARSE_RET
_pngIEND(RS_BUFFER *rsb)
{
   if (_parser_st.chunk_type != PNG_CHUNK_IEND)
   {
      ASSERT(0);
   }

   //verify IEND chunk order
   if (!(_parser_st.mode & PNG_HAVE_IHDR) || !(_parser_st.mode & PNG_HAVE_IDAT))
   {
      return PNG_PARSE_RET_IEND_INVALID_ORDER;
   }

   if (_parser_st.data_len != 0)
   {
      return PNG_PARSE_RET_IEND_NON_EMPTY_DATA;
   }

   _parser_st.mode |= (PNG_HAVE_IEND | PNG_AFTER_IDAT);
   _parser_st.read_data_bytes = _parser_st.data_len;

   return PNG_PARSE_RET_OK;
}



static PNG_PARSE_RET
_pngUnknown(RS_BUFFER *rsb)
{
   kal_int32 count;

   if (_parser_st.chunk_type != PNG_CHUNK_UNKNOWN)
   {
      ASSERT(0);
   }

   if (_parser_st.mode & PNG_HAVE_IDAT)
   {
      return PNG_PARSE_RET_INVALID_STATE;
   }

   count = rsbGetDataAvailable(rsb);

   if ((kal_uint32)count < _parser_st.data_len)
   {
      _parser_st.data_len -= count;
      rsbAdjustReadPointer(rsb, count);
      return PNG_PARSE_RET_INCOMPLETE;
   }
   else
   {
      rsbAdjustReadPointer(rsb, _parser_st.data_len);
      return PNG_PARSE_RET_OK;
   }
}



//----------------internal use for testing------------------------------
void _pngDecGetState(PNG_DECODER_STATE_ENUM *dec_state)
{
   *dec_state = _decoder_state;
}



void _pngDecSetState(PNG_DECODER_STATE_ENUM new_dec_state)
{
   _decoder_state = new_dec_state;
}



void pngGetInfo(MY_PNG_INFO **my_info_ptr)
{
   if (!my_info_ptr)
   {
      ASSERT(0);
   }

   *my_info_ptr = &_png_st;
   return;
}



void pngGetHwCfg(PNG_HW_INFO **my_cfg_ptr)
{
   if (!my_cfg_ptr) {
      ASSERT(0);
   }

   *my_cfg_ptr = &_hwcfg_st;
   return;
}
#endif //   #if defined(USE_HW_PNG_DECODER)
