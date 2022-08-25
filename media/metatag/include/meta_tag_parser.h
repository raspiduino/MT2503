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
*  meta_tag_parser.h
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
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef __META_TAG_PARSER_H__
#define __META_TAG_PARSER_H__

#include "kal_general_types.h"
//#include "Conversions.h"
#include "meta_tag_api.h"
#include "med_trc.h"

#if defined(__META_DATA_PARSE_API__)

/*
*   DEFINE INLINE COMPILE OPTION
*/
#if defined(__META_DATA_PARSE_SUPPORT_ID3V2__)
#define __TAG_SUPPORT_ID3V2__
#endif

#if defined(__META_DATA_PARSE_SUPPORT_ID3V1__)
#define __TAG_SUPPORT_ID3V1__
#endif

#if defined(__META_DATA_PARSE_SUPPORT_APE__)
#define __TAG_SUPPORT_APE__
#endif

#if defined(__META_DATA_PARSE_SUPPORT_LYRICS_EXT__)
#define __TAG_SUPPORT_LYRICS_EXT__
#endif

#if defined(__META_DATA_PARSE_SUPPORT_DRIVER__) 
#define __TAG_SUPPORT_DRIVER__
#endif

#if defined(__META_DATA_PARSE_SUPPORT_DCF__) && defined (__DRM_SUPPORT__)
#define __TAG_SUPPORT_DCF__
#endif

#if 0 //ndef __LOW_COST_SUPPORT_COMMON__
/* under construction !*/
#endif

/*  DEFINE FILE TRACE GROUP
*/
#define FILE_ID_META_TAG_API        100
#define FILE_ID_ID3_V2_PARSER       200
#define FILE_ID_ID3_V1_PARSER       300
#define FILE_ID_APE_PARSER          400
#define FILE_ID_LYC_PARSER          500
#define FILE_ID_KUR_PARSER          600
#define FILE_ID_META_TAG_API_ASYNC  700
#define FILE_ID_META_SEQ_ID         800

/*  DEFINE MACRO HERE
*/

#define META_TAG_ATTR_ARTIST        0x00000001
#define META_TAG_ATTR_AUTHOR        0x00000002
#define META_TAG_ATTR_ALBUM         0x00000004
#define META_TAG_ATTR_TITLE         0x00000008

#define META_TAG_ATTR_COPYRIGHT     0x00000010
#define META_TAG_ATTR_GENRE         0x00000020
#define META_TAG_ATTR_YEAR          0x00000040
#define META_TAG_ATTR_TRACKNUM      0x00000080 

#define META_TAG_ATTR_DESCRIPTION   0x00000100
#define META_TAG_ATTR_SYNCLYRICS    0x00000200
#define META_TAG_ATTR_PICTURE       0x00000400
#define META_TAG_ATTR_DURATION      0x00000800 

#define META_TAG_ATTR_BITRATE       0x00001000
#define META_TAG_ATTR_RATING 	    0x00002000 

#define META_TAG_ATTR_IDV3_1                            \
    (META_TAG_ATTR_TITLE | META_TAG_ATTR_DESCRIPTION    \
    |META_TAG_ATTR_ARTIST | META_TAG_ATTR_ALBUM         \
    |META_TAG_ATTR_YEAR | META_TAG_ATTR_GENRE | META_TAG_ATTR_TRACKNUM)

#ifdef __TAG_SUPPORT_WRITE_BACK__
#define META_TAG_ID3_V2_ATTR_NUMBER 11
#else
#define META_TAG_ID3_V2_ATTR_NUMBER 10
#endif /* __TAG_SUPPORT_WRITE_BACK__ */

#define META_TAG_DCF_ATTR_NUMBER    4
#define META_TAG_DCF_FRAME_MAX_SIZE (2*META_TAG_FRAME_MAX_SIZE)

#define META_TAG_APE_ATTR_NUMBER    9

#define META_TAG_ATTR_APE                               \
    (META_TAG_ATTR_TITLE | META_TAG_ATTR_DESCRIPTION    \
    |META_TAG_ATTR_ARTIST | META_TAG_ATTR_ALBUM         \
    |META_TAG_ATTR_YEAR | META_TAG_ATTR_GENRE           \
    |META_TAG_ATTR_TRACKNUM | META_TAG_ATTR_COPYRIGHT	\
    |META_TAG_ATTR_AUTHOR)


#define META_TAG_MAX_YEAR           9999
#define META_TAG_MAX_TRACK          99999
/*  DEFINE ENUM STRUCT
*/
typedef enum
{
    FUNC_SEEK_SET = 0,    
    FUNC_SEEK_CUR,
    FUNC_SEEK_END,
    FUNC_SEEK_TOTAL
        
}   meta_tag_input_seek_enum;

typedef struct
{    
    kal_uint16 dcf_attr;              
    kal_uint16 tag_attr;
    
}   meta_tag_dcf_map_struct;

typedef struct meta_tag_func_s
{
    kal_uint8* (*tag_getbuffer	)(kal_uint32 metaID, kal_uint32 buffersize);
    kal_uint32 (*tag_read       )(kal_uint32 metaID, kal_uint8* buffer, kal_uint32 readsize);
    kal_int32  (*tag_seek       )(kal_uint32 metaID, kal_int32 offset, kal_uint8 seekpos);
	kal_uint32 (*tag_write      )(kal_uint32 metaID, kal_uint8* buffer, kal_uint32 writesize);
    kal_int32  (*tag_getlocation)(kal_uint32 metaID);
	kal_int32  (*tag_commit		)(kal_uint32 metaID);
    
}   meta_tag_func_struct;

typedef struct
{    
    meta_tag_func_struct*           func_p;
    meta_tag_music_info_struct      music_info;
    meta_tag_audio_info_struct      audio_info;
    meta_tag_img_info_struct        image_info;
    meta_tag_sync_lyc_info_struct   lyric_info;
    
    kal_uint32 hdr_size;
    kal_uint16 hdr_flags;
    kal_uint8  hdr_version;   
    kal_uint8  prefer_charset;        
    
}   meta_tag_internal_info_struct;

typedef struct
{    
    kal_uint32 tag_frame;
    kal_uint32 tag_attr; 
    
}   meta_tag_attr_map_struct;

/*  DEFINE FUNCTION
*/
#define META_TAG_GET_UNSYNC_U35_BE(x)                                   \
    (((kal_uint32)(((kal_uint8*)(x))[0] & 0x7) << 28) |                 \
    ((kal_uint32)(((kal_uint8*)(x))[1] & 0x7F) << 21) |                 \
    ((kal_uint32)(((kal_uint8*)(x))[2] & 0x7F) << 14) |                 \
    ((kal_uint32)(((kal_uint8*)(x))[3] & 0x7F) << 7)  |                 \
    ((kal_uint32)((kal_uint8*)(x))[4] & 0x7F))

#define META_TAG_GET_UNSYNC_U32_BE(x)                                   \
    (((kal_uint32)(((kal_uint8*)(x))[0] & 0x7F) << 21) |                \
    ((kal_uint32)(((kal_uint8*)(x))[1] & 0x7F) << 14) |                 \
    ((kal_uint32)(((kal_uint8*)(x))[2] & 0x7F) << 7) |                  \
    ((kal_uint32)((kal_uint8*)(x))[3] & 0x7F))

#define META_TAG_GET_UNSYNC_U24_BE(x)                                   \
    (((kal_uint32)(((kal_uint8*)(x))[0] & 0x7F) << 14) |                \
    ((kal_uint32)(((kal_uint8*)(x))[1] & 0x7F) << 7) |                  \
    ((kal_uint32)((kal_uint8*)(x))[2] & 0x7F))

#define META_TAG_GET_U32_LE(x)                                          \
    (((kal_uint32)(((kal_uint8*)(x))[3]) << 24) |						\
	((kal_uint32)(((kal_uint8*)(x))[2]) << 16) |						\
    ((kal_uint32)(((kal_uint8*)(x))[1]) << 8) |							\
	((kal_uint32)((kal_uint8*)(x))[0]))

#define META_TAG_GET_U32_BE(x)                                          \
    (((kal_uint32)(((kal_uint8*)(x))[0]) << 24) |						\
	((kal_uint32)(((kal_uint8*)(x))[1]) << 16) |						\
    ((kal_uint32)(((kal_uint8*)(x))[2]) << 8) |							\
	((kal_uint32)((kal_uint8*)(x))[3]))

#define META_TAG_GET_U16_BE(x)                                          \
    (((kal_uint16)(((kal_uint8*)(x))[0]) << 8) |						\
	((kal_uint16)((kal_uint8*)(x))[1]))

#define META_TAG_ERR_TRACE(NO, VAL)										\
    kal_trace(TRACE_INFO, META_TAG_TRC_ERR_REPORT, NO, __LINE__, VAL)
#define META_TAG_MSG_TRACE(NO, VAL)										\
    kal_trace(TRACE_INFO, META_TAG_TRC_MSG_REPORT, NO, __LINE__, VAL)

#define META_GET_TERMINATOR_LEN(ENCODING, VAL)                          \
    do                                                                  \
    {                                                                   \
        switch(ENCODING)                                                \
        {                                                               \
        case META_TAG_TEXT_ENCODING_UTF16:                              \
        case META_TAG_TEXT_ENCODING_UTF16_BE:                           \
            VAL = 2;                                                    \
            break;                                                      \
        default:                                                        \
            VAL = 1;                                                    \
            break;                                                      \
        }                                                               \
    } while (0)

extern  kal_uint8  meta_tag_get_image_type(
						kal_uint8* pbuffer, 
						kal_uint32 size
						);
extern  kal_int32  meta_tag_find_terminator(
						kal_uint8* pbuffer, 
						kal_uint32 size,
                        kal_uint8  encoding
						);
extern  kal_int32  meta_tag_get_terminator_len(kal_uint8 encoding);
extern  kal_uint8  meta_tag_is_empty_asci_item(
						kal_uint8* pbuffer, 
						kal_uint32 size
						);
extern  kal_uint8  meta_tag_is_empty_ucs2_item(
						kal_uint16* pbuffer, 
						kal_uint32 size
						);
#endif  /*#if defined(__META_DATA_PARSE_API__)*/
#endif  /* __META_TAG_PARSER_H__ */ 

