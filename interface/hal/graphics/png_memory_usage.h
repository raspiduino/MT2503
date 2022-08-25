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
 *    png_memory_usage.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   PNG decoder header for memory usage
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PNG_MEMORY_USAGE_H__
#define __PNG_MEMORY_USAGE_H__

#include "drv_features.h"
/// #include "drv_features_png.h"

#if defined (PNG_WIN32_STANDALONE)
    // size in a unit of 4 bytes
    #define COLOR_TBL_MAX_SIZE    256                                // 256*4 bytes
    #define HCLEN_TBL_MAX_SIZE    32768                              // 128k bytes
    #define HLIT_TBL_MAX_SIZE     143                                // 572 bytes
    #define HDIST_TBL_MAX_SIZE    15                                 // 60 bytes
    #define LINE_BUF_MAX_SIZE     (2048 + 1)                         // (PNG_SRC_MAX_W + 1)*4 bytes
    #define LZ77_BUF_MAX_SIZE     (8192 + 4)                         // 32K bytes + 16 bytes
    #define TRNS_TBL_MAX_SIZE     64                                 // 256 bytes
        
    #define HW_PNG_MIN_RSB_BUF_SIZE 1024                             /// file buffer, 1024 bytes
    #define PNG_HW_INT_WORKING_MEM_SIZE ((COLOR_TBL_MAX_SIZE + 2 + HLIT_TBL_MAX_SIZE + 2 + HDIST_TBL_MAX_SIZE + 2 + LINE_BUF_MAX_SIZE + 2) * 4)
    #define PNG_HW_EXT_WORKING_MEM_SIZE ((HCLEN_TBL_MAX_SIZE + 2 + LZ77_BUF_MAX_SIZE + 2 + TRNS_TBL_MAX_SIZE + 2) * 4)      
#endif


#if defined(__MTK_TARGET__)   
    #if defined (USE_HW_PNG_DECODER) /// for platform which support only HW PNG
         /// #include "png_decode.h"     
         /// #include "png_drv_6238_series.h"
         /// #include "png_drv_6268_series.h"
         /// #include "png_drv_6276_series.h"
         
         /// #define PNG_MAX_INT_MEM_SIZE   PNG_HW_INT_WORKING_MEM_SIZE
         /// #define PNG_MAX_EXT_MEM_SIZE   (PNG_HW_EXT_WORKING_MEM_SIZE + HW_PNG_MIN_RSB_BUF_SIZE)    
		     #define PNG_MAX_INT_MEM_SIZE   0                                
		     #define PNG_MAX_EXT_MEM_SIZE   (165160 + 32 + 1024)    
    
    #elif defined (USE_SW_PNG_DECODER) /// for platform which support only SW PNG
         /// #include "png_decoder.h"       
         #define PNG_MAX_INT_MEM_SIZE   (0)
         #define PNG_MAX_EXT_MEM_SIZE   (1024 * 110 + 16 * 1024 + 2* 1024)  
                   
    #else                    /// for platform which not support both HW/SW PNG (6223 series)   
         #define PNG_MAX_INT_MEM_SIZE   (0)                                                          
         #define PNG_MAX_EXT_MEM_SIZE   (0)               
    #endif   // #ifdef USE_HW_PNG_DECODER
#else /// MoDIS 

   #ifdef USE_HW_PNG_DECODER
      #undef USE_HW_PNG_DECODER
      #if defined(USE_SW_PNG_DECODER)
      
          /// #include "png_decoder.h"
                    
          #define PNG_MAX_INT_MEM_SIZE   (0)
          #define PNG_MAX_EXT_MEM_SIZE   (1024 * 110 + 16 * 1024 + 2*1024)
          
      #endif   // #ifndef USE_SW_PNG_DECODER
   #elif defined(USE_SW_PNG_DECODER)      
          /// #include "png_decoder.h"                    
          #define PNG_MAX_INT_MEM_SIZE   (0)
          #define PNG_MAX_EXT_MEM_SIZE   (1024 * 110 + 16 * 1024 + 2*1024)
                
   #endif   // #ifdef USE_HW_PNG_DECODER
   
#endif   // #if defined(__MTK_TARGET__)

      
#endif /*__PNG_MEMORY_USAGE_H__*/ 
