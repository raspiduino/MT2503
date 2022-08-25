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
 *   mav_common.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Main include file of JPEG memory.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __MAV_COMMON_H__
#define __MAV_COMMON_H__

#ifdef WIN32
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#undef  get_ctrl_buffer
#undef  free_ctrl_buffer
#define get_ctrl_buffer(X) malloc(X)
#define free_ctrl_buffer(X) free(X)
#endif

//Feature Option
//#define __MAV_SWLA_DEBUG__
#define MAV_ENCRYPT_HEADER
#define MAV_SUPPORT_RAW_FORMAT
#define MAV_VERSION_CTRL

#if defined(MAV_DECODER_STANDALONE)
/* portable 64-bit unsigned integer */
   typedef unsigned __int64     mav_uint64;
/* portable 64-bit signed integer */
   typedef __int64              mav_int64;
#else
/* portable 64-bit unsigned integer */
   typedef unsigned long long   mav_uint64;
/* portable 64-bit signed integer */
   typedef signed long long     mav_int64;
#endif

#define MAV_ENCODER_VERSION_NUM 0

typedef enum
{
   MAV_ALG_AB2,
#if defined(MAV_SUPPORT_RAW_FORMAT)
   MAV_ALG_NONE,
#endif
   MAV_ALG_JPEG,
   MAV_ALG_RSVD
}MAV_ALGORITHM;


typedef enum
{
   MAV_COLOR_RGB565,
   MAV_COLOR_RGB888,
//   MAV_COLOR_ARGB8888,
   MAV_COLOR_RSVD
}MAV_COLOR_FORMAT;


typedef enum
{
   MAV_FALSE = 0,
   MAV_TRUE
}MAV_BOOL;


typedef enum
{
   MAV_READ_FILE_SYNC = 0,
   MAV_READ_FILE_ASYNC,
   MAV_READ_FILE_RSVD
}MAV_FILE_ACCESS_MODE_ENUM;


typedef struct
{
   unsigned int frame_offset;  // point to the frame's MAV_PIXEL_DATA_START_PATERN
   unsigned int compressed_data_size; //not including the length of MAV_PIXEL_DATA_START_PATERN
   unsigned int pading_count;
}MAV_Frame_Header_Struct;


typedef struct
{
   unsigned int p_frame_count;
   unsigned int start_frame_index;
}MAV_Partition_Header_Struct;


typedef struct
{
#if defined(MAV_VERSION_CTRL)
   unsigned int verion;
#endif
   MAV_ALGORITHM compress_algorithm;
   unsigned int img_width;
   unsigned int img_height;
   unsigned int img_format;
   unsigned int total_frame_count;
   unsigned int total_partition_count;
}MAV_Header_FIXED_PART_Struct;
#define MAV_HEADER_FIXED_PART_OFFSET (0)
#define MAV_HEADER_FIXED_PART_LEN (sizeof(MAV_Header_FIXED_PART_Struct))

#define MAV_HEADER_PARTITION_PART_OFFSET (MAV_HEADER_FIXED_PART_LEN)

#define MAV_PARTITION_HEADER_SIZE (sizeof(MAV_Partition_Header_Struct))
#define MAV_FRAME_HEADER_SIZE (sizeof(MAV_Frame_Header_Struct))
typedef struct
{
   MAV_Header_FIXED_PART_Struct fixed_header;

   unsigned int total_partition_header_size;
   MAV_Partition_Header_Struct *partition_header; //

   unsigned int total_frame_header_size;
   MAV_Frame_Header_Struct *frame_header; //random access table;   
}MAV_Header_Struct;

#define MAV_PIXEL_DATA_MAX_ALIGNMENT_NUM    (64)
#define MAV_PIXEL_DATA_PADING_PATERN 0x0
#define MAV_FILE_NAME_LEN           256
#define MAV_PIXEL_DATA_START_PATERN 0x5C5C5C5C
#define MAV_PIXEL_DATA_START_PATERN_SIZE 4


typedef void* (*alloc_func) (void* opaque, unsigned int items, unsigned int size);
typedef void (*free_func)  (void* opaque, void* address);


#define MAV_SWAP_2(x) ( (((x) & 0xff) << 8) | ((unsigned short)(x) >> 8) )
#define MAV_SWAP_4(x) ( ((x) << 24) | \
         (((x) << 8) & 0x00ff0000) | \
         (((x) >> 8) & 0x0000ff00) | \
         ((x) >> 24) )


#define MAV_SWAP_4_1203(x) ( (((x) >> 24)& 0x000000ff) | \
         (((x) << 8) & 0x0000ff00) | \
          ((x) & 0x00ff0000)| \
         (((x) << 16)& 0xff000000 ))

#define MAV_SWAP_BACK_4_3210(x) ( (((x) << 24)& 0xff000000) | \
         (((x) >> 8) & 0xff) | \
          ((x) & 0x00ff0000)| \
         (((x) >> 16)& 0x0000ff00 ))

#endif //__MAV_COMMON_H__
