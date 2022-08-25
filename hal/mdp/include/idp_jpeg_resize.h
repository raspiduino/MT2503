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
 *
 * Project:
 * --------
 *	 Maui
 *
 * Description:
 * ------------
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
 * 12 17 2010 cm.huang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
 *
 * 11 15 2010 cm.huang
 * NULL
 * .
 *
 * removed!
 * removed!
 * Fix lint errors.
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_jpeg_resize_h__
#define __idp_jpeg_resize_h__

#include "kal_general_types.h"
#include <idp_core.h>

enum
{
  IDP_JPEG_RESIZE_INTMEM_START_ADDRESS = 1,
  IDP_JPEG_RESIZE_INTMEM_SIZE,
  IDP_JPEG_RESIZE_EXTMEM_START_ADDRESS,
  IDP_JPEG_RESIZE_EXTMEM_SIZE,
  
  IDP_JPEG_RESIZE_JPEG_REAL_WIDTH,
  IDP_JPEG_RESIZE_JPEG_REAL_HEIGHT,
  IDP_JPEG_RESIZE_JPEG_DUMMY_WIDTH,
  IDP_JPEG_RESIZE_JPEG_DUMMY_HEIGHT,
  IDP_JPEG_RESIZE_JPEG_NUMBER_OF_COMPONENT,
  IDP_JPEG_RESIZE_JPEG_Y_H_SAMPLE_FACTOR,
  IDP_JPEG_RESIZE_JPEG_Y_V_SAMPLE_FACTOR,
  IDP_JPEG_RESIZE_JPEG_U_H_SAMPLE_FACTOR,
  IDP_JPEG_RESIZE_JPEG_U_V_SAMPLE_FACTOR,
  IDP_JPEG_RESIZE_JPEG_V_H_SAMPLE_FACTOR,
  IDP_JPEG_RESIZE_JPEG_V_V_SAMPLE_FACTOR,
  
  IDP_JPEG_RESIZE_TARGET_WIDTH,
  IDP_JPEG_RESIZE_TARGET_HEIGHT,
  
  IDP_JPEG_RESIZE_JPEG_YUV_MODE,
  
  IDP_JPEG_RESIZE_ENABLE_THUMBNAIL,
  IDP_JPEG_RESIZE_THUMBNAIL_WIDTH,
  IDP_JPEG_RESIZE_THUMBNAIL_HEIGHT,
  IDP_JPEG_RESIZE_THUMBNAIL_BUFFER_ADDRESS,
  
  IDP_JPEG_RESIZE_ENABLE_OVERLAY,
  IDP_JPEG_RESIZE_OVERLAY_PALETTE_MODE,
  IDP_JPEG_RESIZE_OVERLAY_FRAME_SOURCE_KEY,
  IDP_JPEG_RESIZE_OVERLAY_FRAME_WIDTH,
  IDP_JPEG_RESIZE_OVERLAY_FRAME_HEIGHT,
  IDP_JPEG_RESIZE_OVERLAY_FRAME_BUFFER_ADDRESS,
  
  IDP_JPEG_RESIZE_LAST_USER_CONFIG
};

enum
{
  IDP_JPEG_RESIZE_QUERY_ERROR_CODE = 1
};


enum idp_jpeg_resize_error_code_t
{
  IDP_JPEG_RESIZE_NO_ERROR,
  IDP_JPEG_RESIZE_ERROR_CODE_SRC_WIDTH_TOO_LARGE,
  IDP_JPEG_RESIZE_ERROR_CODE_SRC_WIDTH_TOO_SMALL,
  IDP_JPEG_RESIZE_ERROR_CODE_SRC_HEIGHT_TOO_LARGE,
  IDP_JPEG_RESIZE_ERROR_CODE_SRC_HEIGHT_TOO_SMALL,
  IDP_JPEG_RESIZE_ERROR_CODE_TAR_WIDTH_TOO_LARGE,
  IDP_JPEG_RESIZE_ERROR_CODE_TAR_WIDTH_TOO_SMALL,
  IDP_JPEG_RESIZE_ERROR_CODE_TAR_HEIGHT_TOO_LARGE,
  IDP_JPEG_RESIZE_ERROR_CODE_TAR_HEIGHT_TOO_SMALL,
  IDP_JPEG_RESIZE_ERROR_CODE_NOT_ENOUGH_MEMORY,
  IDP_JPEG_RESIZE_ERROR_CODE_HW_LIMITATION
};
typedef enum idp_jpeg_resize_error_code_t idp_jpeg_resize_error_code_t;

typedef enum{
  IBR1_TYPE_RGB565,
  IBR1_TYPE_RGB888
}IMGDMA_DATA_TYPE_ENUM;

typedef enum{
  IBR1_ORDER_BGR888,
  IBR1_ORDER_RGB888
}IMGDMA_DATA_ORDER_ENUM;

extern kal_bool idp_jpeg_resize_open_real(             
  kal_uint32 * const key,                           
  char const * const filename,                      
  kal_uint32 const lineno);                         

extern kal_bool idp_jpeg_resize_close(                 
  kal_uint32 const key);                            

extern kal_bool idp_jpeg_resize_stop(                 
  kal_uint32 const key);                            

extern kal_bool idp_jpeg_resize_start_intermedia_pipe( 
  kal_uint32 const key);                            

extern kal_bool idp_jpeg_resize_start_input(           
  kal_uint32 const key);                            

extern kal_bool idp_jpeg_resize_start_output(          
  kal_uint32 const key);                            

extern kal_bool idp_jpeg_resize_start_all(             
  kal_uint32 const key);                            

extern kal_bool idp_jpeg_resize_config(
  kal_uint32 const key,
  ...);

extern kal_bool idp_jpeg_resize_configurable(
  kal_uint32 const key,
  ...);

extern kal_bool idp_jpeg_resize_config_fast(
  kal_uint32 const key,
  kal_uint32 const para_type,
  kal_uint32 const para_value);

extern kal_bool idp_jpeg_resize_query(
  kal_uint32 const key,
  ...);

extern kal_bool idp_jpeg_resize_config_and_start(
  kal_uint32 const key,
  ...);

extern kal_bool idp_jpeg_resize_is_busy(               
  kal_uint32 const key,                             
  kal_bool * const busy);

extern kal_bool idp_jpeg_resize_is_in_use(void);

#define idp_jpeg_resize_open(key) idp_jpeg_resize_open_real(key, __FILE__, __LINE__)

#endif
