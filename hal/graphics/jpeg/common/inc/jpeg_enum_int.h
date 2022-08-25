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
 *   jpeg_enum_int.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Enum of JPEG codec unified interface.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __JPEG_ENUM_INT_H__
#define __JPEG_ENUM_INT_H__

#define JPEG_MAX_COMPONENT_COUNT    3

/// Decoder
typedef enum {
   JPEG_PARSE_STATE_STOP = 0,
   JPEG_PARSE_STATE_WAITING_FOR_SOI,

   JPEG_PARSE_STATE_WAITING_FOR_MARKER,
   JPEG_PARSE_STATE_WAITING_FOR_LENGTH,
   JPEG_PARSE_STATE_WAITING_FOR_DATA,

   JPEG_PARSE_STATE_ERROR,
   JPEG_PARSE_STATE_COMPLETE
} JPEG_PARSE_STATE_ENUM;


/// Encoder
typedef enum {
   JPEG_APP_NINE_QUICK_VIEW_IMAGE_INFO = 0,     /// 
   JPEG_APP_NINE_HINT_INFO = 1,                 /// 
   JPEG_APP_NINE_NONE = 2,                      ///
   
} JPEG_APP_NINE_INFO_TYPE_ENUM;

#define APP_NINE_LENGTH          (0x16)



/// EXIF
typedef enum {
   JPEG_APP1_IFD_TYPE_IFD0 = 0,
   JPEG_APP1_IFD_TYPE_IFD1,
   JPEG_APP1_IFD_TYPE_EXIF,
   JPEG_APP1_IFD_TYPE_GPS,
   JPEG_APP1_IFD_TYPE_INTEROPERABILITY
} JPEG_APP1_IFD_TYPE_ENUM;

/*

typedef enum {
   JPEG_INFO_IMAGE_WIDTH = 0,
   JPEG_INFO_IMAGE_HEIGHT,
   JPEG_INFO_ENCODE_PROCESS,
   JPEG_INFO_FILE_SIZE,
   JPEG_INFO_SAMPLING_FORMAT
} JPEG_INFO_ENUM;



typedef enum {
   JPEG_OVL_PALETTE_1_BPP = 0,
   JPEG_OVL_PALETTE_2_BPP,
   JPEG_OVL_PALETTE_4_BPP,
   JPEG_OVL_PALETTE_8_BPP
} JPEG_OVL_PALETTE_DEPTH_ENUM;
*/

#endif
