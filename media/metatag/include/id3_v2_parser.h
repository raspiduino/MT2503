/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  id3_v2_parser.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   meta tag parsing definitions
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef __ID3_V2_PARSER_H__
#define __ID3_V2_PARSER_H__

#include "meta_tag_parser.h"
#include "kal_general_types.h"

/*  Dependency compile option
*/
#if defined(__TAG_SUPPORT_ID3V2__)

/*  IN LINE MACRO 
*/
#define ID3_TAG_V2_MAGIC_SIZE                   3
#define ID3_TAG_V2_MAGIC_ID                     "ID3"
#define ID3_TAG_V2_HEADER_SIZE                  10

/*  ID3 v2.2
*/
#define ID3_TAG_V2_2_FLAG_ZERO                  0x3F
#define ID3_TAG_V2_2_FLAG_UNSYNCH               0x80
#define ID3_TAG_V2_2_FLAG_COMPRESS              0x40

#define ID3_TAG_V2_2_FRAME_HEADER_SIZE          6

/*  ID3 v2.3
*/
#define ID3_TAG_V2_3_FLAG_ZERO                  0x1F
#define ID3_TAG_V2_3_FLAG_UNSYNCH               ID3_TAG_V2_2_FLAG_UNSYNCH
#define ID3_TAG_V2_3_FLAG_EXT_HEADER            0x40
#define ID3_TAG_V2_3_FLAG_EXPERIMENTAL          0x20

#define ID3_TAG_V2_3_EXT_FLAG_ZERO              0x7FFF
#define ID3_TAG_V2_3_EXT_FLAG_CRC               0x8000

#define ID3_TAG_V2_3_FRAME_HEADER_SIZE          10

#define ID3_TAG_V2_3_FRAME_FLAG_ZERO            0x1F1F
#define ID3_TAG_V2_3_FRAME_FLAG_TAG_PRESERV     0x8000
#define ID3_TAG_V2_3_FRAME_FLAG_FILE_PRESERV    0x4000
#define ID3_TAG_V2_3_FRAME_FLAG_READ_ONLY       0x2000
#define ID3_TAG_V2_3_FRAME_FLAG_COMPRESS        0x0080
#define ID3_TAG_V2_3_FRAME_FLAG_ENCRYPT         0x0040
#define ID3_TAG_V2_3_FRAME_FLAG_GROUP_ID        0x0020

/*  ID3 v2.4
*/
#define ID3_TAG_V2_4_FLAG_ZERO                  0x0F
#define ID3_TAG_V2_4_FLAG_UNSYNCH               ID3_TAG_V2_3_FLAG_UNSYNCH
#define ID3_TAG_V2_4_FLAG_EXT_HEADER            ID3_TAG_V2_3_FLAG_EXT_HEADER
#define ID3_TAG_V2_4_FLAG_EXPERIMENTAL          ID3_TAG_V2_3_FLAG_EXPERIMENTAL
#define ID3_TAG_V2_4_FLAG_FOOTER                0x10

#define ID3_TAG_V2_4_EXT_FLAG_ZERO              0x8F
#define ID3_TAG_V2_4_EXT_FLAG_UPDATE            0x40
#define ID3_TAG_V2_4_EXT_FLAG_CRC               0x20
#define ID3_TAG_V2_4_EXT_FLAG_RESTRICTIONS      0x10

#define ID3_TAG_V2_4_FRAME_HEADER_SIZE          ID3_TAG_V2_3_FRAME_HEADER_SIZE

#define ID3_TAG_V2_4_FRAME_FLAG_ZERO            0x8FB0
#define ID3_TAG_V2_4_FRAME_FLAG_GROUP_ID        0x0040
#define ID3_TAG_V2_4_FRAME_FLAG_COMPRESS        0x0008
#define ID3_TAG_V2_4_FRAME_FLAG_ENCRYPT         0x0004
#define ID3_TAG_V2_4_FRAME_FLAG_UNSYNCH         0x0002
#define ID3_TAG_V2_4_FRAME_FLAG_DATA_LEN        0x0001
#define ID3_TAG_V2_4_FRAME_FLAG_TAG_PRESERV     0x4000
#define ID3_TAG_V2_4_FRAME_FLAG_FILE_PRESERV    0x2000
#define ID3_TAG_V2_4_FRAME_FLAG_READ_ONLY       0x1000

/*  define struct
*/
typedef enum
{
    ID3_TAG_FRAME_ERR_NONE = 0,        
    ID3_TAG_FRAME_ERR_NOT_SUPPORT,
    ID3_TAG_FRAME_ERR_TOTAL
        
}   id3_v2_tag_frame_error_enum;

typedef struct
{             
    kal_uint32 size;
    kal_uint32 padding_size;
    kal_uint32 crc;
    kal_uint16 flags;    
    kal_uint8  restrictions;
    
}   id3_v2_tag_ext_hdr_struct;

typedef struct
{             
    id3_v2_tag_ext_hdr_struct   exthdr;

    kal_uint32 size;
    kal_uint8  version;
    kal_uint8  flags;
    
}   id3_v2_tag_hdr_struct;

typedef struct
{   
    kal_uint8  id[4];          /*frame id string identify*/
    kal_uint32 size;           /*frame data size*/
    kal_uint16 flags;          /*frame flags*/
    kal_uint8  data_offset;
    kal_uint8  index;          /*frame index*/
    
}   id3_v2_tag_frame_hdr_struct;

typedef struct
{    
    kal_uint32	data_size;      
    kal_uint16  data_offset;
    kal_uint8   frame_ID;           /*meta_tag_txt_frame_enum*/ 
    
}   id3_v2_tag_frame_single_parse_struct;

typedef struct
{             
    const char* key_string[3];	    /*2.2 2.3 2.4 versions have different frame identify*/
    kal_uint16  key_frameID;        /*meta_tag_txt_frame_enum*/ 
    
}   id3_v2_tag_frame_key_struct;
/*  define function
*/
extern kal_uint8 id3_tag_v2_parse(
					kal_uint32 metaID, 
					meta_tag_internal_info_struct* pInternal
					);
extern kal_uint8 id3_tag_v2_parse_attach_cover(
					kal_uint32 metaID, 
					kal_uint8* pBuffer, 
					kal_uint32 bufferSize,
					meta_tag_internal_info_struct* pInternal
					);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#ifdef __TAG_SUPPORT_WRITE_BACK__
extern kal_uint8 id3_tag_v2_parse_to_write(kal_uint32 metaID, meta_tag_internal_info_struct* pInternal);
#endif

#endif  /*#if defined(__TAG_SUPPORT_ID3V2__)*/
#endif  /* __ID3_V2_PARSER_H__ */ 

