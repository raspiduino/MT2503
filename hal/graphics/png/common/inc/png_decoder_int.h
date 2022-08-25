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
 *  png_decoder_int.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  PNG HAL internal include header file
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
 
#ifndef __PNG_DECODER_INT_H__
#define __PNG_DECODER_INT_H__

#include "png_decode_enum.h"
#include "png_decode_structure.h"
#include "kal_general_types.h"
#include "drv_features_png.h"
 
/// HW: 6238, 6239, 6268, 6276; SW:6225, 6235; NONE:6223
#if defined(__MTK_TARGET__) 
    #if defined (USE_HW_PNG_DECODER)            
        #include "png_decode.h"        
    #elif defined (USE_SW_PNG_DECODER) 
        #include "png_decoder.h"    
    #endif 
#else ///< For MoDIS
    #if defined (USE_SW_PNG_DECODER)
        #include "png_decoder.h"
    #endif
#endif

/// ASSERT defintion
/// #ifdef PNG_WIN32_STANDALONE
///    #ifdef WIN32
///       #ifndef ASSERT
///          #include "assert.h"
///          #define ASSERT assert
///       #endif
///    #else
///       #include "string.h"
///       #ifndef ASSERT
///          #define ASSERT(I) while(!(I)) {};
///       #endif
///    #endif
/// #else
///    #include "kal_release.h"
/// #endif

#if defined(__PNG_SLA_MEASURE__)
extern void SLA_CustomLogging(kal_char *customJob, kal_int32 saAction);
#endif


PNG_STATUS_ENUM pngDecParseImage(PNG_DECODER_HANDLE handle);

#if defined (USE_SW_PNG_DECODER)
extern void sw_png_hook_png_decode_progress_callback(kal_int32 (*png_decode_progress_callback)(void));
PNG_STATUS_ENUM pngDecSetupSWConfiguration(PNG_DECODER_HANDLE handle, png_config_struct *sw_png_cfg);
#endif

#endif
