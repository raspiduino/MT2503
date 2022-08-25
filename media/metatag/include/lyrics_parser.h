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
*  lyrics_parser.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   lyrics parsing definitions
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
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef __LYRICS_PARSER_H__
#define __LYRICS_PARSER_H__

#include "meta_tag_parser.h"

/*  Dependency compile option
*/
#if defined(__TAG_SUPPORT_LYRICS_EXT__)

/*  define macro 
*/
#define LYRICS_PRE_DEFINE_SIZE   8600      /*lyrics memory size*/

#define LYRICS_MAX_LINES        200
#define LYRICS_MAX_LINE_SIZE    254
#define LYRICS_MAX_CHAR_INLINE  128
#if ((defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)) && !defined(__MMI_VECTOR_FONT_SUPPORT__))
    #define LYRICS_MAX_BUFFER_SIZE  4400
#else
    #define LYRICS_MAX_BUFFER_SIZE  5000    /*min size 520*/
#endif
#define LYRICS_MAX_PARSE_SIEZE  1024 * 100  /*MAX support size*/
#define LYRICS_EXT              L".lrc"
#define LYRICS_MIN_SIZE			30
#define LYRICS_MAX_SIZE			(LYRICS_MAX_BUFFER_SIZE/2)

typedef enum
{
    LYRICS_ERR_NONE = 0,        
    LYRICS_ERR_NO_MEMORY,
    LYRICS_ERR_NO_HANDLE,  
    LYRICS_ERR_NO_INPUT,
    LYRICS_ERR_INVAILD_FILE_PATH, 
    LYRICS_ERR_OPEN_FILE_FAILED, 
    LYRICS_ERR_INVAILD_HANDLE,   
    LYRICS_ERR_INVAILD_DATA,  
    LYRICS_ERR_NOT_SUPPORT, 
    LYRICS_ERR_NOT_ENOUGH_BUFFER, 

    LYRICS_ERR_TOTAL
        
}   lyrics_error_enum;

/*  define struct
*/
typedef struct
{             
    kal_uint16* st_text;
    kal_int32   ln_text;      
    kal_int32   id_time;/*Time index for update interval*/  
    kal_uint16  id_next;    
    kal_uint16  id_prev; 
    
}   lyrics_line_struct;

typedef struct
{             
    lyrics_line_struct*  lines_p;/*line content array*/

    kal_uint16  id_fst_line;
    kal_uint16  line_count;
    kal_int32   ms_time_offset;
    kal_int16   line_count_org;
    
}   lyrics_meta_struct;
/*  define function
*/
extern lyrics_meta_struct*  
lyrics_parse_create(kal_uint16 update_ms,
                    void* (*f_malloc)(kal_uint32 size, kal_uint32 user_data),
                    void  (*f_free)(void* p, kal_uint32 user_data),
                    kal_uint32 user_data);

extern kal_uint8    lyrics_parse_file(kal_uint16* music_file_name);
extern kal_uint8    lyrics_convert_file_name(kal_uint16* music_file_name,
                                             kal_uint16* music_title_name,
                                             kal_uint16* lyric_file_name);
extern kal_uint8    lyrics_convert_file_name_with_length(kal_uint16* music_file_name,
                                                         kal_uint16* music_title_name,
                                                         kal_uint16* lyric_file_name,
                                                         kal_uint32 size);

extern kal_uint8    lyrics_format_line(lyrics_meta_struct* plyrics,
                            kal_uint16 view_w, 
                            kal_uint32 duration_ms,
                            kal_int32 (*f_get_string_w_n)(kal_uint16* text, kal_int32 n));
extern kal_uint8    lyrics_unformat_line(lyrics_meta_struct* plyrics);
extern kal_uint16   lyrics_get_line(lyrics_meta_struct* plyrics, kal_uint16 times);
extern kal_uint16   lyrics_get_line_ex(lyrics_meta_struct* plyrics, 
                            kal_uint16 lineID, kal_uint16 times);
extern kal_uint8    lyrics_set_err_text(lyrics_meta_struct* plyrics, 
                                        kal_uint16* err_str);
extern kal_uint8 lyrics_parse_release(void);
#endif  /*#if defined(__TAG_SUPPORT_LYRICS_EXT__)*/
#endif  /* __LYRICS_PARSER_H__ */ 

