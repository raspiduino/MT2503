/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010-2011
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
 *    flatten_api_internal_6236.h
 *
 * Project:
 * --------
 *    MAUI/HAL/flatten
 *
 * Description:
 * ------------
 *    Flatten related function
 *
 * Author:
 * -------
 * -------
 *    
 *============================================================================
 * HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * $Log$
 *
 * 11 01 2011 xiaoyong.ye
 * removed!
 * Improve LWF MT6236 flatten none-blocking mode support.
 *
 * 10 20 2011 xiaoyong.ye
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _FLATTEN_API_INTERNAL_6236_H_
#define _FLATTEN_API_INTERNAL_6236_H_

#if defined(MT6236) || defined(MT6236B)
/*****************************************************************************
 *  Local macro definitions
 ****************************************************************************/
#define IS_LAYER_ENABLE(layer_enable_bit, layer_n)  (layer_enable_bit & ((1<<(DRV_GOVL_LAYER_TOTAL_COUNT-layer_n-1))<<28)) //layer_n=0,1,...
#define FLATTEN_GOVL_TIMEOUT_INTERVAL 1500
#define IS_GOVL_SUPPORTED_EVENT(event) (event == FLATTEN_EVENT_DATA_TRANSFER_COMPLETE_MTK)
#define GOVL_HW_LAYER_ENABLE_BIT(n) (1 << (31 - n))
#define SUPPORT_LAYER_OFFSET_FUNC() KAL_TRUE
#define CONVERT_TO_GOVL_HW_PITCH_UNIT(stride, bpp) ((stride)/(bpp))
#define FLATTEN_HW_ROT_ENABLE       0x80000000
#define FLATTEN_HW_FLIP_ENABLE      0x40000000 

#define _FLATTEN_SWAP16(a, b)\
{\
   kal_uint16 tmp;\
   tmp = a;\
   a = b;\
   b = tmp;\
}

#define _FLATTEN_SWAP32(a, b)\
{\
   kal_uint32 tmp;\
  tmp = a;\
   a = b;\
   b = tmp;\
}
/*****************************************************************************
 *  Local variables
 ****************************************************************************/

/*****************************************************************************
 *  Local function definitions
****************************************************************************/ 


/*****************************************************************************
 *  Include directives
 ****************************************************************************/
#include "kal_release.h"
#include "flatten_api.h"

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 *  Local type definitions
 ****************************************************************************/

typedef enum
{      
   FLATTEN_GOVL_TRANSFER_COMPLETE_EVENT =   0x00000001,
   FLATTEN_GROT_TRANSFER_COMPLETE_EVENT =   0x00000002,
   FLATTEN_GOVL_GROT_TRANSFER_COMPLETE_ALL =  0x00000003
}  FLATTEN_GOVL_GROT_EVENT_ENUM;


typedef enum
{
   FLATTEN_GOVL_HW_TRANSFER_COMPLETE_EVENT =   0x00000001
}  FLATTEN_GOVL_HW_EVENT_DEF_ENUM;

typedef enum
{
   FLATTEN_GROT_HW_TRANSFER_COMPLETE_EVENT =   0x00000001
}  FLATTEN_GROT_HW_EVENT_DEF_ENUM;

typedef enum
{ FLATTEN_EVENT_INVALID                         = 0x7580,
  FLATTEN_EVENT_DATA_TRANSFER_COMPLETE_MTK      = 0x7581, /**< <b>[MTK]</b> This event indicates that a data transmission is completed. */
  FLATTEN_EVENT_FORCE_32BIT                     = 0x7FFFFFFF
} FLATTENEventType;

   //! GOVL_LAYER_COLOR_FORMAT_ENUM enum.
   /*! More detailed enum description. */
typedef enum
{
   FLATTEN_GOVL_LAYER_8BPP_INDEX = 0, /*!< Layer framebuffer color format: index color */
   FLATTEN_GOVL_LAYER_RGB565,/*!< Layer framebuffer color format: RGB565 */
   FLATTEN_GOVL_LAYER_YUYV422,/*!< Layer framebuffer color format: YUYV422 */
   FLATTEN_GOVL_LAYER_RGB888,/*!< Layer framebuffer color format: RGB888 */
   FLATTEN_GOVL_LAYER_ARGB8888,/*!< Layer framebuffer color format: ARGB8888 */
   FLATTEN_GOVL_LAYER_PARGB8888,/*!< Layer framebuffer color format: PARGB8888 */
   FLATTEN_GOVL_LAYER_RSVD /*!<Reserved */
} FLATTEN_GOVL_LAYER_FORMAT_ENUM;

#define  FLATTEN_GOVL_LAYER_UYVY422 FLATTEN_GOVL_LAYER_YUYV422

typedef enum
{
   FLATTEN_GOVL_WMEM_COLOR_RGB565 = 0, /*!< Write to memory with RGB565 color format */  
   FLATTEN_GOVL_WMEM_COLOR_RGB888 = 2, /*!< Write to memory with RGB888 color format */
   FLATTEN_GOVL_WMEM_COLOR_ARGB8888_CONSTANT_ALPHA = 4, /*!< Write to memory with ARGB8888 color format with constant alpha value */
   FLATTEN_GOVL_WMEM_COLOR_ARGB8888_PIXEL_ALPHA = 6, /*!< Write to memory with ARGB8888 color format with per-pixel alpha value*/  
   FLATTEN_GOVL_WMEM_COLOR_RSVD = 7  /*!<Reserved */
} FLATTEN_GOVL_WMEM_COLOR_FORMAT_ENUM;

typedef enum
{
   FLATTEN_GOVL_LAYER_ROTATE_NORMAL = 0,
   FLATTEN_GOVL_LAYER_ROTATE_90,
   FLATTEN_GOVL_LAYER_ROTATE_180,
   FLATTEN_GOVL_LAYER_ROTATE_270,
   FLATTEN_GOVL_LAYER_FLIP,
   FLATTEN_GOVL_LAYER_FLIP_ROTATE_90,
   FLATTEN_GOVL_LAYER_FLIP_ROTATE_180,
   FLATTEN_GOVL_LAYER_FLIP_ROTATE_270,
   FLATTEN_GOVL_LAYER_FLIP_ROTATE_NOMO
}FLATTEN_GOVL_LAYER_ROTATE_ENUM;

typedef enum
{
   FLATTEN_GROT_STATUS_OK,
   FLATTEN_GROT_STATUS_ERR
}FLATTEN_GROT_STATUS_ENUM;

typedef enum
{
   FLATTEN_GROT_OUTPUT_ARGB8888 = 0,
   FLATTEN_GROT_OUTPUT_RGB888,   	
   FLATTEN_GROT_OUTPUT_RGB565,
   FLATTEN_GROT_OUTPUT_BGR888,
   FLATTEN_GROT_OUTPUT_YUYV422,   
   FLATTEN_GROT_OUTPUT_ERR
}FLATTEN_GROT_OUTPUT_FORMAT_ENUM;


typedef enum
{
   FLATTEN_GROT_INPUT_YUYV422 = 0, // GOVL can't output YUYV
   FLATTEN_GROT_INPUT_ARGB8888,
   FLATTEN_GROT_INPUT_RGB888,   	
   FLATTEN_GROT_INPUT_BGR888,
   FLATTEN_GROT_INPUT_ERR
}FLATTEN_GROT_INPUT_FORMAT_ENUM;

typedef  enum 
{
   FLATTEN_GROT_ANGLE_0 = 0,
   FLATTEN_GROT_ANGLE_90,
   FLATTEN_GROT_ANGLE_180,
   FLATTEN_GROT_ANGLE_270,
   FLATTEN_GROT_ANGLE_0_FLIP,   
   FLATTEN_GROT_ANGLE_90_FLIP,
   FLATTEN_GROT_ANGLE_180_FLIP,
   FLATTEN_GROT_ANGLE_270_FLIP,     
   FLATTEN_GROT_ANGLE_ERR
}FLATTEN_GROT_ANGLE_ENUM;



/*****************************************************************************
 *  Internal used macros
 ****************************************************************************/

/*****************************************************************************
 *  API function definitions
 ****************************************************************************/
void FlattenInit_6236(void);
FlattenResultEnum FlattenStart_6236(FlattenLayerStruct *, FlattenCtrlStruct *);

#ifdef __cplusplus
}
#endif

#endif  // #if defined(MT6236) || defined(MT6236B)

#endif //#ifndef _FLATTEN_API_INTERNAL_6236_H_


