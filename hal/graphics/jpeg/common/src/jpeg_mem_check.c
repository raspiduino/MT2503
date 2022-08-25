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
 *   jpeg_mem_check.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
///#if !defined(JPEG_CODEC_STANDALONE)
#if defined(JPG_ENCODE) || defined(JPG_DECODE)

#include "jpeg_mem.h"
#include "jpeg_decode_structure.h"
//#include "swjd_structure.h"
#include "swje_structure.h"
#include "exif_dec_structure.h"

/// Check memory size
#define JPEG_CHECK_MEM_SIZE(A, B, name)                 static char _dummy_jpeg_##name##_mem_size[(A) < (B) ? 1 : -1];

#define JPEG_SW_DEC_BASIC_STRUCTURE_REAL_MEM_SIZE       1024 //(sizeof(SWJD_DATA_SOURCE) +                                                   \
                                                        //sizeof(SWJD_HUFFMAN_DECODER) + sizeof(SWJD_FRAGMENT_PROCESSOR) +              \
                                                        //sizeof(SWJD_DEQUANT_IDCT_UNIT) * 3  + sizeof(SWJD_HUFFMAN_DECODE_TABLE) * 8 + \
                                                        //sizeof(JPEG_FILE_INFO))

#define JPEG_SW_ENC_BASIC_STRUCTURE_REAL_MEM_SIZE       (((sizeof(SWJE_FRAGMENT_PROCESSOR) + 3) & 0xFFFFFFFC) +   \
                                                        (((sizeof(SWJE_FDCT_QUANT_UNIT) * 3) + 3) & 0xFFFFFFFC) + \
                                                        ((sizeof(SWJE_HUFFMAN_ENCODER) + 3) & 0xFFFFFFFC))

#define EXIF_APP1_INFO_STRUCTURE_REAL_MEM_SIZE          ((sizeof(EXIF_APP1_INFO) + 3) & 0xFFFFFFFC)

/// check the decoder memory size is correct or not
JPEG_CHECK_MEM_SIZE(JPEG_SW_DEC_BASIC_STRUCTURE_REAL_MEM_SIZE, JPEG_SW_DEC_BASIC_STRUCTURE_MEM_SIZE, dec_structure);
///#if (JPEG_SW_DEC_BASIC_STRUCTURE_MEM_SIZE) < (JPEG_SW_DEC_BASIC_STRUCTURE_REAL_MEM_SIZE)
///    #error "JPEG Decode Memory Size Error"
///#endif

/// check the encoder memory size is correct or not
JPEG_CHECK_MEM_SIZE(JPEG_SW_ENC_BASIC_STRUCTURE_REAL_MEM_SIZE, JPEG_SW_ENC_BASIC_STRUCTURE_MEM_SIZE, enc_structure);
///#if (SW_JPEG_ENC_BASIC_STRUCTURE_MEM_SIZE) < (JPEG_SW_ENC_BASIC_STRUCTURE_REAL_MEM_SIZE)
///    #error "JPEG Encode Memory Size Error"
///#endif

JPEG_CHECK_MEM_SIZE(EXIF_APP1_INFO_STRUCTURE_REAL_MEM_SIZE, EXIF_APP1_INFO_STRUCTURE_MEM_SIZE, exif_app1_info_structure);


#endif

