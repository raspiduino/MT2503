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
 *   ivlw_common.h
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
 *============================================================================
 ****************************************************************************/
#ifndef __IVLW_COMMON_H__
#define __IVLW_COMMON_H__

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
#define __IVLW_SWLA_DEBUG__
#define IVLW_ENCRYPT_HEADER
#define IVLW_VERSION_CTRL

#define IVLW_ENC_FRAME_ALIGN_NUM           (32 * 1024)
#define IVLW_MAX_IMAGE_WIDTH               (1024)
#define IVLW_MAX_IMAGE_HEIGHT              (1024)
#define IVLW_MAX_FRAME_COUNT               (1024)
#define IVLW_MAX_PARTITION_COUNT           (64)

#define IVLW_PIXEL_DATA_MAX_ALIGNMENT_NUM  (64)
#define IVLW_PIXEL_DATA_PADING_PATERN      (0)
#define IVLW_FILE_NAME_LEN                 (256)


#define V0_IVLW_PIXEL_DATA_START_PATERN       0x5C5C5C5C
#define V0_IVLW_PIXEL_DATA_START_PATERN_SIZE  4

#define V1_IVLW_PIXEL_DATA_START_PATERN       0
#define V1_IVLW_PIXEL_DATA_START_PATERN_SIZE  0



#if defined(IVLW_DECODER_STANDALONE)
/* portable 64-bit unsigned integer */
   typedef unsigned __int64     ivlw_uint64;
/* portable 64-bit signed integer */
   typedef __int64              ivlw_int64;
#else
/* portable 64-bit unsigned integer */
   typedef unsigned long long   ivlw_uint64;
/* portable 64-bit signed integer */
   typedef signed long long     ivlw_int64;
#endif

#define IVLW_ENCODER_VERSION_NUM 1
/*
** IVLW_ENCODER_VERSION_NUM 1: Modification
** 1. Move encryption key to file head and using 8 bytes to present it.
** 2. Frame: 32KB alignment
**
*/


typedef enum
{
   IVLW_ALG_AB2,
   IVLW_ALG_NONE,
   IVLW_ALG_MAV = 0x004D4156, // ASCII code "MAV"
   IVLW_ALG_RSVD
}IVLW_ALGORITHM;


typedef enum
{
   IVLW_FILE_TYPE_VLW,
   IVLW_FILE_TYPE_MAV,
   IVLW_FILE_TYPE_RSVD
}IVLW_FILE_TYPE;


typedef enum
{
   IVLW_COLOR_RGB565,
   IVLW_COLOR_RGB888,
   IVLW_COLOR_ARGB8888,
   IVLW_COLOR_YUV,
   IVLW_COLOR_RSVD
}IVLW_COLOR_FORMAT;


typedef enum
{
   IVLW_FALSE = 0,
   IVLW_TRUE
}IVLW_BOOL;


typedef enum
{
   IVLW_READ_FILE_SYNC = 0,
   IVLW_READ_FILE_ASYNC,
   IVLW_READ_FILE_RSVD
}IVLW_FILE_ACCESS_MODE_ENUM;


typedef struct
{
   unsigned int frame_offset;  // point to the frame's IVLW_PIXEL_DATA_START_PATERN
   unsigned int compressed_data_size; //not including the length of IVLW_PIXEL_DATA_START_PATERN
   unsigned int pading_count;
}IVLW_Frame_Header_Struct;


typedef struct
{
   unsigned int p_frame_count;
   unsigned int start_frame_index;
}IVLW_Partition_Header_Struct;

typedef struct
{
#if defined(IVLW_VERSION_CTRL)
   unsigned int verion;
#endif
   IVLW_ALGORITHM compress_algorithm;
   unsigned int img_width;
   unsigned int img_height;
   unsigned int img_format;
   unsigned int total_frame_count;
   unsigned int total_partition_count;
}IVLW_Header_FIXED_PART_Struct;

//#if (0 == IVLW_ENCODER_VERSION_NUM)
   // we will put the encryption key in the end 4 bytes of the file.
   #define V0_IVLW_ENCRYPT_KEY_OFFSET                     0xFFFFFFFF
   #define V0_IVLW_ENCRYPT_KEY_TOTAL_SIZE                 4
   #define V0_IVLW_ENCRYPT_KEY_WITH_DUMMY_DATA_TOTAL_SIZE 4
   #define V0_IVLW_HEADER_FIXED_PART_OFFSET              (0)
//#else
   // we will put the encryption key in the first 8 bytes of the file.
   #define V1_IVLW_ENCRYPT_KEY_OFFSET                     0
   #define V1_IVLW_ENCRYPT_KEY_TOTAL_SIZE                 4
   #define V1_IVLW_ENCRYPT_KEY_WITH_DUMMY_DATA_TOTAL_SIZE 8
   #define V1_IVLW_HEADER_FIXED_PART_OFFSET              (8)
//#endif

#define IVLW_HEADER_FIXED_PART_LEN (sizeof(IVLW_Header_FIXED_PART_Struct))
#define V0_IVLW_HEADER_PARTITION_PART_OFFSET  (IVLW_HEADER_FIXED_PART_LEN + V0_IVLW_HEADER_FIXED_PART_OFFSET)
#define V1_IVLW_HEADER_PARTITION_PART_OFFSET  (IVLW_HEADER_FIXED_PART_LEN + V1_IVLW_HEADER_FIXED_PART_OFFSET)


#define IVLE_PARTITION_HEADER_SIZE (sizeof(IVLW_Partition_Header_Struct))
#define IVLE_FRAME_HEADER_SIZE (sizeof(IVLW_Frame_Header_Struct))
typedef struct
{
   IVLW_Header_FIXED_PART_Struct fixed_header;

   unsigned int total_partition_header_size;
   IVLW_Partition_Header_Struct *partition_header; //

   unsigned int total_frame_header_size;
   IVLW_Frame_Header_Struct *frame_header; //random access table;   
}IVLW_Header_Struct;



typedef void* (*alloc_func) (void* opaque, unsigned int items, unsigned int size);
typedef void (*free_func)  (void* opaque, void* address);


#define IVLW_SWAP_2(x) ( (((x) & 0xff) << 8) | ((unsigned short)(x) >> 8) )
#define IVLW_SWAP_4(x) ( ((x) << 24) | \
         (((x) << 8) & 0x00ff0000) | \
         (((x) >> 8) & 0x0000ff00) | \
         ((x) >> 24) )


#define IVLW_SWAP_4_1203(x) ( (((x) >> 24)& 0x000000ff) | \
         (((x) << 8) & 0x0000ff00) | \
          ((x) & 0x00ff0000)| \
         (((x) << 16)& 0xff000000 ))

#define IVLW_SWAP_BACK_4_3210(x) ( (((x) << 24)& 0xff000000) | \
         (((x) >> 8) & 0xff) | \
          ((x) & 0x00ff0000)| \
         (((x) >> 16)& 0x0000ff00 ))

#endif //__IVLW_COMMON_H__
