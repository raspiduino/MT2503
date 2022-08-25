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
 *  png_decoder_structure.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  PNG HAL internal structure include header file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
 
#ifndef __PNG_DECODE_STRUCTURE_H__
#define __PNG_DECODE_STRUCTURE_H__

#include "rs_buffer.h"
#include "fsal.h"
#include "kal_general_types.h"
#include "drv_features_png.h"
#include "png_decode_enum.h"   
#include "gfx_cache_switch_behavior_enum.h"
#include "png_decoder.h"
   
typedef struct color_struct 
{
   kal_uint8 red;
   kal_uint8 green;
   kal_uint8 blue;
} png_color;
 
typedef struct png_color_16_struct 
{
   kal_uint8      index;
   kal_uint16        red;
   kal_uint16     green;
   kal_uint16     blue;
   kal_uint16      gray;
} png_color_16;
      
/// common structure for SW/HW PNG
typedef struct PNG_DECODER_T
{    
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && defined(__MTK_TARGET__)    
   GFX_CACHE_SWITCH_BEHAVIOR_ENUM  dstBufferCacheSwitchBehavior; 
#endif
   
   /// source buffer interface to GDI (both HW/SW PNG)
   /// handling input file buffer address, size      
   void                           *fileBufferAddr;
   kal_uint32                      fileBufferSize;   
                                  
   STFSAL                         *fileHandle;         ///< FSAL handle for file-mode usage
   kal_uint32                      fileSize;                 
   kal_uint32                      IsfileInMemory;
   kal_uint32                      imageOffsetInFile;
   
   /// source buffer interface to HW PNG driver
   kal_int32                       isRSBControlInit;
   RS_BUFFER                       g_hwpng_rsb;        ///< ring sequential buffer structure 
   void                           *g_hwpng_rsb_buf;    ///< used to load source
   kal_int32                       g_hwpng_rsb_buf_size;
   STFSAL                         *g_hwpng_read_fp;
   kal_int32                       g_hwpng_src_size;   ///< the size of un-read part of the png image   
   kal_uint8                      *g_hwpng_read_ptr;   ///< memory read pointer of png if png is from memory 
     
   /// decoder state, status        
   PNG_DECODER_TYPE_ENUM           decoderType;  
   PNG_STATUS_ENUM                 lastStatus;         ///< record the last status of PNG decoder
   PNG_DECODER_STATE_ENUM          decodeState;  
      
   void (*pngdec_callback)(PNG_STATUS_ENUM state);     ///< call back function of png decoder
      
   /// working buffer 
   void                            *internalMem; 
   void                            *externalMem;      
   
   
   /// destination buffer info.  
   void*                           canvasStartAddr;    
   kal_int32                       canvasWidth;       
   kal_int32                       canvasHeight;      
   kal_uint32                      canvasBufferSize;
    
   PNG_DECODE_COLOR_FORMAT_ENUM    canvasColorFormat;
   
   kal_int32                       outputWindow_x;       
   kal_int32                       outputWindow_y;       
   kal_int32                       outputWindowWidth;
   kal_int32                       outputWindowHeight;
                                   
   kal_int32                       clipWindow_ul_x;      
   kal_int32                       clipWindow_ul_y;
   kal_int32                       clipWindow_dr_x;     
   kal_int32                       clipWindow_dr_y;     
    
   /// for color replacement (and source key control)
   kal_bool                        clrRepEnable;
   kal_uint8                       orgRepColor_R; 
   kal_uint8                       orgRepColor_G;
   kal_uint8                       orgRepColor_B;   
                                   
   kal_uint8                       newRepColor_R;  
   kal_uint8                       newRepColor_G;  
   kal_uint8                       newRepColor_B;
                 
   /// alpha blending info.
   kal_int32                       userSetAlphaValue;   
   void*                           blendingBufferStartAddr;   
   kal_uint32                      blendingBufferWidth;
   kal_uint32                      blendingBufferHeight;
   PNG_BLEND_MODE_ENUM      blendingMode;           
   PNG_DECODE_COLOR_FORMAT_ENUM    blend_buf_format;       
   
   /// time out value
   kal_int32                       timeoutMsec;  
                                   
   ///                             
   kal_bool                        ditheringEnable;
   kal_bool                        sourceKeyEnable;
                                   
   kal_uint32                      pngImageWidth; 
   kal_uint32                      pngImageHeight;
           
   kal_int32 (*check_abort_func)(void);               ///< check abort function, only used for SW decoder. 
                                                      ///< This function will be invoked regularly during the decoding process.
                                                      ///< If the return value is non-zero, the decoding process will be terminated immediately.      
#if defined(USE_SW_PNG_DECODER)
   png_config_struct               png_dec_image_config;   
   png_inform_struct               png_dec_info;           
   PNG_STATUS_ENUM                 png_image_png_status;     
#endif
                                                      
} PNG_DECODER;

typedef PNG_DECODER* PNG_DECODER_HANDLE;


#endif /// __PNG_COMMON_STRUCTURE_H__
