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
 *   sw_video_resizer.h
 *
 *
 * Description:
 * ------------
 *   software video resizer functions
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
 *****************************************************************************/
 
#ifndef _SW_VIDEO_RESIZER_H_
#define _SW_VIDEO_RESIZER_H_

#include "kal_general_types.h"

//#define SW_VIDEO_RESIZER_PROFILING

#define SW_VIDEO_RESIZER_SCALE_BITS 19

typedef enum
{
   IMAGE_FORMAT_GRAY,
   IMAGE_FORMAT_Y_ONLY,

   IMAGE_FORMAT_RGB565,
   IMAGE_FORMAT_RGB888,
   IMAGE_FORMAT_ARGB8888,
   IMAGE_FORMAT_BGR565,

   IMAGE_FORMAT_YUV420,
   IMAGE_FORMAT_YUV422,
   IMAGE_FORMAT_YUV444,
   IMAGE_FORMAT_YUV422V,
   IMAGE_FORMAT_UYVY,

   IMAGE_FORMAT_INDEX

} IMAGE_FORMAT_ENUM;

typedef enum
{
   SW_VIDEO_YUV420_DROP_RESIZE_RGB565,
   SW_VIDEO_YUV420_DD_RESIZE_RGB565,
   SW_VIDEO_YUV420_BYPASS_RESIZE_RGB565,
   SW_VIDEO_YUV420_IP_HYBRID_RESIZE_RGB565,
   SW_VIDEO_YUV420_IP_PARTIAL_RESIZE_RGB565,
   SW_VIDEO_YUV420_IP_RESIZE_RGB565,
   SW_VIDEO_RGB565_DD_RESIZE_RGB565,
   SW_VIDEO_RGB565_DD_RESIZE_YUV420,
   SW_VIDEO_RGB565_BYPASS_RESIZE_YUV420,
   SW_VIDEO_YUV420_PACK_UYVY422,
   SW_VIDEO_RESIZER_FUNC_NUM
}SW_VIDEO_RESIZER_FUNC_ENUM;

typedef enum
{
 SW_VIDEO_RESIZER_SUCCESS,
 SW_VIDEO_RESIZER_FAIL,
 SW_VIDEO_RESIZER_BUFF_INSUFFICIENT,
 SW_VIDEO_RESIZER_FUNC_NOT_SUPPORT,
 SW_VIDEO_RESIZER_IS_BUSY,
 SW_VIDEO_RESIZER_PARTIAL_SIZE_ERROR,
 SW_VIDEO_RESIZER_NEED_INIT_ERROR,
 SW_VIDEO_RESIZER_INIT_ARGUMENT_ERROR
}SW_VIDEO_RESIZER_STATUS_ENUM;


#ifdef SW_VIDEO_RESIZER_PROFILING
typedef struct
{
   kal_uint32 total_ms;
   kal_uint32 count;
   kal_uint32 avg_ms;
   kal_uint32 worst_ms;
}SW_VIDEO_RESIZER_PROFILE_STRUCT;
#endif

typedef struct
{
   kal_uint32 *int_ram_start_ptr;
   kal_uint32 int_ram_total_length;
   kal_uint32 int_ram_index;
   kal_bool   int_ram_init;
} SW_VIDEO_RESIZER_MEM_STRUCT;

/*
*     [Target image]
*     <- tar_offset -><-tar_width-><-tar_offset ->
*     ------------------------------------------- <----
*     -               .           .             -     .
*     -               .           .             -     .
*     -     black     .  image    .    black    -     . -- tat_height
*     -               .           .             -     .
*     -               .           .             -     .
*     ------------------------------------------- <----
*
*     [Source image]
*     <-----------------src_width-------------->
*     ------------------------------------------  <----
*     -                                        -      .
*     -               S...........             -      .
*     -               .          .             -      . -- src_height
*     -               ...........E             -      .
*     -                                        -      .
*     ------------------------------------------  <----
*     S(Start Point):  (u4SrcClipX1, u4SrcClipY1)
*     E(End Point):    (u4SrcClipX2, u4SrcClipY2)
*
*     [Buffer vs image]
*     <----input_buff_width---->
*     <----src_width----->
*     ....................------
*     .                  .     -
*     .                  .     -
*     .                  .     -
*     ....................     -
*     -                        -
*     -                        -
*     --------------------------
*     Support YUV420 only
*     input_buff_width[0]: width of Y
*     input_buff_width[1]: width of U, should be half of Y
*     input_buff_width[2]: width of V, should be half of Y
*/
typedef struct
{
    kal_uint32 src_width;           // Original source width of the image
    kal_uint32 src_height;          // Original source height of the image

    kal_uint32 tar_offset;
    kal_uint32 tar_width;           // the width of target image */
    kal_uint32 tar_height;          // the height of target image */

    kal_uint32 u4SrcClipX1;         // The x position of top-left point of the clipping window [0:src_width-1]
    kal_uint32 u4SrcClipY1;         // The y position of top-left point of the clipping window [0:src_height-1]
    kal_uint32 u4SrcClipX2;         // The x position of bottom-right point of the clipping window [0:src_width-1]
    kal_uint32 u4SrcClipY2;         // The y position of bottom-left point of the clipping window [0:src_height-1]

    kal_uint32 input_buff_width[3];
} SW_VIDEO_RESIZER_CONFIG_STRUCT;


typedef struct
{
    SW_VIDEO_RESIZER_CONFIG_STRUCT cfg;
    kal_bool fgBusy;
    kal_uint32 u4OutputWidth;
    kal_uint32 u4OutputHeight;
    kal_uint32  image_buffer_width;
}SW_VIDEO_RESIZER_DCB_STRUCT;


typedef struct
{
   kal_uint8 *input_buffer[3];
   kal_uint8 *output_buffer[1];
} SW_VIDEO_RESIZER_PUT_STRUCT;

#define CLIP63(src)  (((unsigned int)(src) > 63)?(((unsigned int)(src) >> 26) ^ 0x3f):src)
#define CLIP31(src)  (((unsigned int)(src) > 31)?(((unsigned int)(src) >> 27) ^ 0x1f):src)

#define RED(value) ((value&0xF800)>>8)  //extract the red value from RGB565
#define GREEN(value) ((value&0x7E0)>>3) //extract the green value from RGB565
#define BLUE(value)  ((value&0x1F)<<3)  //extract the blue value from RGB565
#define RED_FAST(value)   (value&0xF800)
#define GREEN_FAST(value) (value&0x7E0) 
#define BLUE_FAST(value)  (value&0x1F)  
#define RGB2Y(r,g,b) ((306*r+601*g+117*b)>>10)
#define RGB2CB(b,y)  ((((b-y)*579)>>10)+128)
#define RGB2CR(r,y)  ((((r-y)*730)>>10)+128)

extern SW_VIDEO_RESIZER_STATUS_ENUM (*sw_video_resizer_put_data)(void*, void*);
SW_VIDEO_RESIZER_STATUS_ENUM sw_video_resizer_init(SW_VIDEO_RESIZER_CONFIG_STRUCT *sw_video_resizer_cfg);
void sw_video_resizer_deinit(void);
kal_uint32 get_sw_video_ip_buffer_size( kal_uint32 max_width, kal_uint32 max_height );
kal_bool sw_video_resizer_is_busy(kal_uint32 const key, kal_bool * const busy);

extern SW_VIDEO_RESIZER_STATUS_ENUM sw_video_yuv420_pack_uyvy422(
    SW_VIDEO_RESIZER_PUT_STRUCT *video_put,
    SW_VIDEO_RESIZER_CONFIG_STRUCT *prConfig
    );

#endif //_SW_VIDEO_RESIZER_H_
