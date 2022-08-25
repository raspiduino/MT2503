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

/*******************************************************************************
* Filename:
* ---------
*  ape_parser.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   ape parsing definitions
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
 * removed!
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include <stdlib.h>
#include "kal_release.h"
#include "fs_type.h"
#include "fat_fs.h"
#include "med_utility.h"

#include "lyrics_parser.h"
#include "app_str.h"
#include "Conversions.h"

#if defined(__TAG_SUPPORT_LYRICS_EXT__)

#define wc_isdigit(ch) (ch>= L'0' && ch <= L'9')
#define wc_isspace(ch) (ch== L' ' || ch == 0x3000)  /*full TAB SPACE*/
#define PRE_WORD       L"\x6211"                    /*L"ÎÒ" USE for testing word len*/

#define ENCODING_LEN    2

static const kal_uint8 g_cheset_utf8_bytes[16] = 
{
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 2, 2, 3, 4  /* we don't support UCS4 */
};


typedef enum
{
    UCS2_NONE,
    UCS2_LOCAL,
    UCS2_LE,
    UCS2_BE,
    UCS2_UTF8    

}	lyrics_encode_enum;

typedef enum
{
    READ_FAILED = 0,
    READ_END,
    READ_BUFFER_FULL,
    READ_CONTINUE
        
}	lyrics_read_err_enum;

typedef enum
{
    PARSE_FAILED = 0,
    PARSE_BUFFER_FULL,
    PARSE_CONTINUE,
    PARSE_END
        
}	lyrics_parse_err_enum;

typedef enum
{
    PARSE_SEARCH_BEG = 0,
    PARSE_SEARCH_END,
    PARSE_SEARCH_TXT,
    PARSE_SEARCH_LINE_END
        
}	lyrics_parse_status_enum;

typedef enum
{
    ADD_LINE_SKIP = 0,    
    ADD_LINE_BUFFER_FULL,
    ADD_LINE_SUCCESS
        
}	lyrics_add_line_err_enum;

typedef struct
{   
    void* (*f_malloc)(kal_uint32 size, kal_uint32 user_data);
    void  (*f_free  )(void* p, kal_uint32 user_data);
    kal_uint32   user_data;

    lyrics_meta_struct  meta_info;

    kal_uint32  meta_str_size;
    kal_uint32  meta_buf_size;
    kal_uint16* meta_str_buffer;

    kal_uint16  update_ms;
    kal_uint8   text_encoding;
    kal_uint8   parse_status;

    kal_uint8   data_read_buffer[LYRICS_MAX_LINE_SIZE+2];
    
}   lyrics_meta_hdl_struct;

/*  
*   define global variable
*/
static  lyrics_meta_hdl_struct* g_lyrics = NULL;

/*  
*   define function
*/
static  kal_uint8   f_get_encoding_type(kal_uint8* pstr);
static  kal_uint8   f_has_half_char(kal_uint8* pstr, kal_uint32 nstr);
static  kal_uint8   f_has_utf8_whole(kal_uint8* pstr, kal_uint32 nstr);
static  kal_int32   f_convert_to_ucs2(kal_uint16 type, kal_uint32 nsrc,
                                      kal_uint32 ndst, kal_uint8* psrc, 
                                      kal_uint8* pdst);
static  kal_uint8   f_prepare_data(FS_HANDLE handle, kal_uint32 filesize,
                                   kal_uint32* readsize_p);
static  kal_uint8   f_parse_data(kal_uint8 IsEnd);

static  void        f_memmove(kal_uint8* pBeg, kal_uint8* pOrg, kal_uint8* pDst);
static  kal_uint8   f_add_line(kal_uint16* pBeg, kal_uint16* pEnd);
static  void        f_Inert_Line(kal_uint16 lineID);
static  void        f_add_string(kal_uint16* pBeg, kal_uint16* pEnd);
/*****************************************************************************
 * FUNCTION
 *  lyrics_parse_create
 * DESCRIPTION
 *  parse lyrics   
 * PARAMETERS
 *  update_ms   [IN]    
 *  f_malloc    [IN]: used for memory alloc
 *  f_free      [IN]:
 *  kal_uint32  [IN]: user data
 * RETURNS
 *  success return lyrics_meta_struct, 
 *****************************************************************************/
lyrics_meta_struct*  lyrics_parse_create(kal_uint16 update_ms,
                                         void* (*f_malloc)(kal_uint32 size, kal_uint32 user_data),
                                         void  (*f_free)(void* p, kal_uint32 user_data),
                                         kal_uint32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 nHdleSize;
    kal_uint32 nLineBufSize;
    kal_uint8* mem_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    META_TAG_MSG_TRACE(FILE_ID_LYC_PARSER, update_ms);
    
    if (NULL != g_lyrics)
    {
        META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, g_lyrics);

        return  NULL;
    }
    if (NULL == f_malloc)
    {
        META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, f_malloc);
        ASSERT(0);
    }
    if (NULL == f_free)
    {
        META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, f_free);
        ASSERT(0);
    }
    nHdleSize   = sizeof(lyrics_meta_hdl_struct);
    nLineBufSize= sizeof(lyrics_line_struct)*LYRICS_MAX_LINES;
    mem_p = (kal_uint8*)f_malloc((nHdleSize+nLineBufSize+LYRICS_MAX_BUFFER_SIZE), user_data);
    
    if (NULL == mem_p)
    {
        META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, mem_p);
        return  NULL;
    }
    g_lyrics    = (lyrics_meta_hdl_struct*)mem_p;
    g_lyrics->f_malloc  = f_malloc;
    g_lyrics->f_free    = f_free;
    g_lyrics->user_data = user_data;

    g_lyrics->update_ms         = update_ms;
    if (g_lyrics->update_ms < 1)
    {
        g_lyrics->update_ms = 1;
    }   
    g_lyrics->meta_str_buffer   = (kal_uint16*)(mem_p + nHdleSize + nLineBufSize);     
    g_lyrics->meta_info.lines_p = (lyrics_line_struct*)(mem_p + nHdleSize);
    g_lyrics->meta_info.id_fst_line     = 0;
    g_lyrics->meta_info.line_count      = 0;
    g_lyrics->meta_info.ms_time_offset  =0;

    return  &g_lyrics->meta_info;
}


/*****************************************************************************
 * FUNCTION
 *  lyrics_parse_release
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  success return 1, 
 *****************************************************************************/
kal_uint8 lyrics_parse_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    META_TAG_MSG_TRACE(FILE_ID_LYC_PARSER, g_lyrics);

    if (NULL == g_lyrics)
    {
        META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, g_lyrics);
        
        return  LYRICS_ERR_INVAILD_HANDLE;
    }
    g_lyrics->f_free(g_lyrics, g_lyrics->user_data);
    g_lyrics = NULL;    

    return  LYRICS_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  lyrics_convert_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  music_file_name [IN]: input file name;
 *  plyrics_p [OUT]:    output lyrics information 
 * RETURNS
 *  success return 1, 
 *****************************************************************************/
kal_uint8    lyrics_convert_file_name(kal_uint16* music_file_name,
                                      kal_uint16* music_title_name,
                                      kal_uint16* lyric_file_name)
{
    return lyrics_convert_file_name_with_length(music_file_name, 
                                         music_title_name,
                                         lyric_file_name,
                                         259);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  lyrics_convert_file_name_with_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  music_file_name [IN]: input file name;
 *  plyrics_p [OUT]:    output lyrics information 
 * RETURNS
 *  success return 1, 
 *****************************************************************************/
extern kal_uint8    lyrics_convert_file_name_with_length(kal_uint16* music_file_name,
                                                         kal_uint16* music_title_name,
                                                         kal_uint16* lyric_file_name,
                                                         kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16* file_name_p, *chr_find, *path_p;
    kal_uint32 total_len;
    FS_HANDLE	handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (NULL == music_file_name || NULL == lyric_file_name)
    {
        META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, 0);
        return  LYRICS_ERR_NO_INPUT;
    }
    /*prepare file name*/
    app_ucs2_strncpy((kal_int8*)lyric_file_name, (kal_int8*)music_file_name, size);    

    path_p = (kal_uint16*)app_ucs2_strchr((const kal_int8*)(lyric_file_name+1), L':');
    if (NULL == path_p)
    {
        META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, 0);
        return  LYRICS_ERR_INVAILD_FILE_PATH;
    }    
    file_name_p = path_p;
    chr_find    = path_p;

    while((chr_find = (kal_uint16*)app_ucs2_strchr((const kal_int8*)(chr_find+1), L'\\')) 
        != NULL )
    {
        file_name_p = chr_find;
    } 
    path_p = file_name_p+1;

    //check total length
    {
        kal_uint32 title_len = app_ucs2_strlen((kal_int8*)music_title_name);
        kal_uint32 folder_len = path_p - music_file_name;
        total_len = title_len + folder_len + 4;
    }
    if ((NULL != music_title_name) && (total_len <= size))
    {
        app_ucs2_strncpy((kal_int8*)path_p, (kal_int8*)music_title_name, size);
        app_ucs2_strcat((kal_int8*)lyric_file_name, (kal_int8*)LYRICS_EXT);

        handle = FS_Open((kal_uint16*)lyric_file_name, FS_READ_ONLY);
        if (handle >= FS_NO_ERROR)
        {
            FS_Close(handle);
            return  LYRICS_ERR_NONE;
        }    
        else
        {
            app_ucs2_strncpy((kal_int8*)path_p, 
                (kal_int8*)(music_file_name+(path_p-lyric_file_name)), size);
        }
    }
    file_name_p = NULL;
    chr_find    = path_p;

    while((chr_find = (kal_uint16*)app_ucs2_strchr((const kal_int8*)(chr_find), L'.')) 
        != NULL )
    {
        file_name_p = chr_find;
        chr_find++;
    }    
    if (file_name_p == NULL)
    {
        META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, 0);
        return  LYRICS_ERR_INVAILD_FILE_PATH;
    }
    *file_name_p = 0;
    app_ucs2_strncat((kal_int8*)lyric_file_name, (kal_int8*)LYRICS_EXT, size);

    handle = FS_Open((kal_uint16*)lyric_file_name, FS_READ_ONLY);
    if (handle < FS_NO_ERROR)
    {
        META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, handle);

        if (FS_FILE_NOT_FOUND == handle || FS_PATH_NOT_FOUND == handle)
        {
            return  LYRICS_ERR_INVAILD_FILE_PATH;
        }
        else
        {
            return  LYRICS_ERR_OPEN_FILE_FAILED;
        }        
	}
    FS_Close(handle);

    return  LYRICS_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  lyrics_parse_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  music_file_name [IN]: input file name;
 * RETURNS
 *  success return 1, 
 *****************************************************************************/
kal_uint8 lyrics_parse_file(kal_uint16* music_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  	lyrics_line_struct* pLines;
  	FS_HANDLE	handle;
	kal_uint32	nRet, nParse, nSize, nReadSize;
    kal_uint16  LineID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    if (NULL == g_lyrics)
    {
        META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, g_lyrics);
        
        return  LYRICS_ERR_NO_INPUT;
    }
    if (NULL == music_file_name)
    {
        META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, 0);
        return  LYRICS_ERR_NO_INPUT;
    }    

	handle = FS_Open((kal_uint16*)music_file_name, FS_READ_ONLY);
	if (handle < FS_NO_ERROR)
	{
		META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, handle);
        if (FS_FILE_NOT_FOUND == handle || FS_PATH_NOT_FOUND == handle)
        {
            return  LYRICS_ERR_INVAILD_FILE_PATH;
        }
        else
        {
            return  LYRICS_ERR_OPEN_FILE_FAILED;
        }  
	}
	if (FS_GetFileSize(handle, &nSize) < FS_NO_ERROR)
	{
		META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, nSize);
		FS_Close(handle);
		return  LYRICS_ERR_INVAILD_DATA;
    }
	if (nSize < LYRICS_MIN_SIZE)
	{
		META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, nSize);
		FS_Close(handle);
		return  LYRICS_ERR_INVAILD_DATA;
	}
	if (nSize >=  LYRICS_MAX_PARSE_SIEZE)
	{
		META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, nSize);
		nSize = LYRICS_MAX_PARSE_SIEZE;
	}
	
    g_lyrics->meta_buf_size         = 0;
    g_lyrics->meta_str_size         = 0;
    g_lyrics->meta_info.id_fst_line = 0;
    g_lyrics->meta_info.line_count  = 0;
    g_lyrics->meta_info.ms_time_offset =0;

    g_lyrics->text_encoding         = UCS2_NONE;
    g_lyrics->parse_status          = PARSE_SEARCH_BEG;

    nRet = READ_CONTINUE;
	while (nRet == READ_CONTINUE)
	{
        nRet = f_prepare_data(handle, nSize, &nReadSize);  
        if (READ_END == nRet)
        {
            nParse = f_parse_data(1);
        }
        else if (READ_CONTINUE == nRet)
        {
            nParse = f_parse_data(0);
            /*error happened or line buffer full*/
            if (PARSE_FAILED == nParse || PARSE_BUFFER_FULL == nParse)
            {
                break;
            }
        }
        nSize -= nReadSize;
	}
	FS_Close(handle);   

    /*check if has valid content*/
    if (g_lyrics->meta_info.line_count == 0)
    {
        META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, g_lyrics->meta_info.line_count);
        return LYRICS_ERR_INVAILD_DATA;
	}

    /*There may have timestamp before lyrics text find*/
    g_lyrics->meta_info.line_count_org = g_lyrics->meta_info.line_count;
    g_lyrics->meta_str_buffer[g_lyrics->meta_str_size/ENCODING_LEN] = 0;

    pLines = g_lyrics->meta_info.lines_p;
    LineID = g_lyrics->meta_info.id_fst_line;
    
    while (LineID < LYRICS_MAX_LINES)
    {          
        pLines[LineID].id_time -= 
            g_lyrics->meta_info.ms_time_offset/g_lyrics->update_ms;
        LineID = pLines[LineID].id_next; 
    }    

    return  LYRICS_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  lyrics_set_err_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  plyrics:
 *  err_str:
 * RETURNS
 *  success return 1, 
 *****************************************************************************/
kal_uint8 lyrics_set_err_text(lyrics_meta_struct* plyrics, kal_uint16* err_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (NULL == g_lyrics)
    {
        META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, g_lyrics);
        
        return  LYRICS_ERR_NO_INPUT;
    }
    if (NULL == err_str || plyrics != &g_lyrics->meta_info)
    {
        META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, plyrics);
        return  LYRICS_ERR_NO_INPUT;
    }
    g_lyrics->meta_buf_size         = 0;
    g_lyrics->meta_str_size         = 0;
    g_lyrics->meta_info.id_fst_line = 0;
    g_lyrics->meta_info.line_count  = 0;

    app_ucs2_strcpy((kal_int8*)g_lyrics->meta_str_buffer, (kal_int8*)err_str);

    g_lyrics->meta_info.lines_p[g_lyrics->meta_info.line_count].id_time = 0; 
    g_lyrics->meta_info.lines_p[g_lyrics->meta_info.line_count].st_text = 
        g_lyrics->meta_str_buffer;
    g_lyrics->meta_info.lines_p[g_lyrics->meta_info.line_count].ln_text = 0;
    f_Inert_Line(g_lyrics->meta_info.line_count);

    return  LYRICS_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  lyrics_format_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  success return LYRICS_ERR_NONE, 
 *****************************************************************************/
kal_uint8 lyrics_format_line(lyrics_meta_struct* plyrics,
                             kal_uint16 view_w,
                             kal_uint32 duration_ms,
                             kal_int32 (*f_get_string_w_n)(kal_uint16* text, kal_int32 n))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    lyrics_line_struct* pLines;
    kal_int32   i, LineW, prevLineW, Line_d_t, Line_count, Line_len, wWord, Base_time, Line_time;
    kal_uint16  LineID, nextID;
    kal_uint16  *pStr, Line_left, bStop = 0, view_d_w;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (NULL == plyrics || NULL == f_get_string_w_n)
    {
        META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, plyrics);
        return  LYRICS_ERR_NO_INPUT;
    }
    pLines = plyrics->lines_p;
    if (NULL == pLines || plyrics->line_count >= LYRICS_MAX_LINES ||
        plyrics->line_count < 1)
    {
        META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, plyrics->line_count);
        return  LYRICS_ERR_INVAILD_DATA;
    }    
    LineID      = plyrics->id_fst_line;
    Line_left   = LYRICS_MAX_LINES - plyrics->line_count;
    /*save one word len for remove word prev or next lines*/
    wWord = f_get_string_w_n(PRE_WORD, 1);
    if (view_w > wWord)
    {
        view_w -= wWord;
    }
    META_TAG_MSG_TRACE(FILE_ID_LYC_PARSER, wWord);
    META_TAG_MSG_TRACE(FILE_ID_LYC_PARSER, view_w); 

    while (LineID < LYRICS_MAX_LINES)
    {                
        /*save the value before add offset time*/
        if (NULL == pLines[LineID].st_text)
        {    
            LineID = pLines[LineID].id_next;
            continue;
        }
        Base_time = pLines[LineID].id_time;
        pLines[LineID].ln_text = app_ucs2_strlen((kal_int8*)pLines[LineID].st_text);
        
        if (0 == bStop)
        {
            nextID  = pLines[LineID].id_next;
            LineW   = f_get_string_w_n(pLines[LineID].st_text, pLines[LineID].ln_text);
            if (LineW > view_w)
            {
                if (nextID < LYRICS_MAX_LINES)
                {
                    Line_d_t = pLines[nextID].id_time - Base_time;
                }
                else
                {
                    Line_d_t = duration_ms/g_lyrics->update_ms - Base_time;
                    if (Line_d_t < 0)
                    {
                        META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, Line_d_t);
                        Line_d_t = 0;
                    }
                }
                META_TAG_MSG_TRACE(FILE_ID_LYC_PARSER, LineW);                               
                /*add wWord for line may add one word for line adjustment*/
                Line_count = (LineW + view_w - 1 + wWord)/view_w;    

                if (Line_count > Line_d_t && Line_d_t > 0)
                {   /*Time update min step*/
                    //Line_count = Line_d_t;
                }
                if (Line_count > Line_left + 1)
                {   /*max line can be split*/
                    Line_count = Line_left + 1;
                    bStop   = 1;
                }
                Line_left  -= (Line_count-1);
                pStr        = pLines[LineID].st_text;
                Line_time   = Line_d_t/Line_count;
                Line_len    = pLines[LineID].ln_text;
                view_d_w    = LineW/Line_count;
                /*use the value after add offset time*/
                Base_time   = pLines[LineID].id_time;

                for (i = 0; i < Line_count - 1; i++)
                {
                    /*re-caculate view_d_w*/
                    LineW = f_get_string_w_n(pStr, Line_len);
                    view_d_w = LineW/(Line_count-i);

                    pLines[LineID].ln_text = Line_len/(Line_count-i);
                    LineW = f_get_string_w_n(pStr, pLines[LineID].ln_text);
                    prevLineW = LineW;

                    if (LineW > view_d_w)
                    {
                        while (LineW > view_d_w && pLines[LineID].ln_text > 0)
                        {
                            pLines[LineID].ln_text--;
                            prevLineW = LineW;
                            LineW = f_get_string_w_n(pStr, pLines[LineID].ln_text);
                        }
                        if (prevLineW - view_d_w < view_d_w - LineW)
                        {
                            pLines[LineID].ln_text++;
                        }
                    }
                    else
                    {
                        while (LineW < view_d_w && pLines[LineID].ln_text < Line_len)
                        {
                            pLines[LineID].ln_text++;
                            prevLineW = LineW;
                            LineW = f_get_string_w_n(pStr, pLines[LineID].ln_text);
                        }
                        if (view_d_w - prevLineW < LineW - view_d_w)
                        {
                            pLines[LineID].ln_text--;
                        }
                    }
                    /*
                    **  remove last single char to next line
                    **  xxxx z ---->xxxx
                    **    zzz  ---->zzzz 
                    */
                    if (pLines[LineID].ln_text > 2 && 
                        pLines[LineID].ln_text < Line_len &&
                        wc_isspace(pStr[pLines[LineID].ln_text-2]) &&
                        !wc_isspace(pStr[pLines[LineID].ln_text-1]) &&
                        !wc_isspace(pStr[pLines[LineID].ln_text]))
                    {
                        pLines[LineID].ln_text--;
                    }
                    /*
                    **  remove first single char to previous line
                    **    xxx   ---->xxxx
                    **   x zzzz  ---->zzzz 
                    */
                    if (pLines[LineID].ln_text > 0 && 
                        pLines[LineID].ln_text + 2 < Line_len &&
                        wc_isspace(pStr[pLines[LineID].ln_text+1]) &&
                        !wc_isspace(pStr[pLines[LineID].ln_text]) &&
                        !wc_isspace(pStr[pLines[LineID].ln_text-1]))
                    {
                        pLines[LineID].ln_text++;

						/*Do not add a char if  out of view_w*/
						LineW = f_get_string_w_n(pStr, pLines[LineID].ln_text);
						if (LineW >= view_w + wWord)
						{
							pLines[LineID].ln_text--;
						}
                    }
                    pLines[plyrics->line_count].id_prev  = LineID;
                    pLines[LineID].id_next  = plyrics->line_count;
                    pLines[LineID].id_time  = Base_time+Line_time*i; 
                    pLines[LineID].st_text  = pStr;

                    Line_len -= pLines[LineID].ln_text;
                    pStr += pLines[LineID].ln_text;
                    /*Remove the blank before first char*/
                    while (wc_isspace(*pStr))
                    {
                        pStr++;
                        Line_len--;
                    }
                    LineID = pLines[LineID].id_next;

                    plyrics->line_count++;
                }    
                pLines[LineID].ln_text  = Line_len;                
                pLines[LineID].id_time  = Base_time+Line_time*i; 
                pLines[LineID].st_text  = pStr;  
                pLines[LineID].id_next  = nextID;
                if (nextID < LYRICS_MAX_LINES)
                {
                    pLines[nextID].id_prev = LineID;
                }
            }
        }
        LineID = pLines[LineID].id_next;        
    }    
    return  LYRICS_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  lyrics_unformat_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  success return LYRICS_ERR_NONE, 
 *****************************************************************************/
kal_uint8 lyrics_unformat_line(lyrics_meta_struct* plyrics)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    lyrics_line_struct* pLines;
    kal_uint16  LineID, PrevID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (NULL == plyrics)
    {
        META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, plyrics);
        return  LYRICS_ERR_NO_INPUT;
    }
    pLines = plyrics->lines_p;
    if (NULL == pLines || plyrics->line_count < 1)
    {
        META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, plyrics->line_count);
        return  LYRICS_ERR_INVAILD_DATA;
    }    
    if (plyrics->line_count == plyrics->line_count_org)
    {
        META_TAG_MSG_TRACE(FILE_ID_LYC_PARSER, plyrics->line_count);
        return  LYRICS_ERR_NONE;
    }
    PrevID = plyrics->id_fst_line;
    LineID = pLines[PrevID].id_next; 

    while (LineID < LYRICS_MAX_LINES)
    {  
        if (LineID < plyrics->line_count_org)
        {
            PrevID = LineID;
        }
        else
        {
            /*delete id large then original line*/
            pLines[PrevID].ln_text += pLines[LineID].ln_text;
            pLines[PrevID].id_next = pLines[LineID].id_next; 
            if (pLines[PrevID].id_next < LYRICS_MAX_LINES)
            {
                pLines[pLines[PrevID].id_next].id_prev = PrevID;
            }            
            plyrics->line_count--;
        }
        LineID = pLines[LineID].id_next; 
    }    
    ASSERT(plyrics->line_count == plyrics->line_count_org);

    return  LYRICS_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  lyrics_get_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  success return 1, 
 *****************************************************************************/
kal_uint16   lyrics_get_line(lyrics_meta_struct* plyrics, kal_uint16 times)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 LineID, prevID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == plyrics)
    {
        return  LYRICS_MAX_LINES;
    }
    LineID = plyrics->id_fst_line;
    if (LineID >= LYRICS_MAX_LINES || plyrics->line_count < 1)
    {
        return  LYRICS_MAX_LINES;
    }
    prevID = LineID;
    while (plyrics->lines_p[LineID].id_time < times && LineID < LYRICS_MAX_LINES)
    {
        prevID = LineID;
        LineID = plyrics->lines_p[LineID].id_next;
    }
    return  prevID;
}


/*****************************************************************************
 * FUNCTION
 *  lyrics_get_line_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  success return 1, 
 *****************************************************************************/
kal_uint16   lyrics_get_line_ex(lyrics_meta_struct* plyrics, 
                                kal_uint16 lineID, kal_uint16 times)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 prevID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == plyrics)
    {
        return  LYRICS_MAX_LINES;
    }
    if (lineID >= LYRICS_MAX_LINES)
    {
        lineID = plyrics->id_fst_line;
    }
    if (plyrics->line_count < 1 || lineID >= LYRICS_MAX_LINES)
    {
        return  LYRICS_MAX_LINES;
    }
    if (plyrics->lines_p[lineID].id_time < times)
    {
        prevID = lineID;
        while (plyrics->lines_p[lineID].id_time < times && 
            lineID < LYRICS_MAX_LINES)
        {
            prevID = lineID;
            lineID = plyrics->lines_p[lineID].id_next;
        }
        return  prevID;
    }
    
    if (plyrics->lines_p[lineID].id_time > times)
    {
        prevID = lineID;
        while (plyrics->lines_p[lineID].id_time >= times && 
            lineID < LYRICS_MAX_LINES)
        {
            prevID = lineID;
            lineID = plyrics->lines_p[lineID].id_prev;
        }
    }
    return  lineID;
}


/*****************************************************************************
 * FUNCTION
 *  f_prepare_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  success return 1, 
 *****************************************************************************/
static  kal_uint8 f_prepare_data(FS_HANDLE handle, kal_uint32 filesize,
                                 kal_uint32* readsize_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16  *pDst;
    kal_uint32	nRead, nGet, nDst, nSrc, nBuf, nData;
	kal_uint8   *pSrc;
	kal_uint8   nBackward;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    nGet    = 0;  
    nDst    = 0;
    pSrc	= g_lyrics->data_read_buffer;
    pDst	= g_lyrics->meta_str_buffer + 
        (g_lyrics->meta_str_size + g_lyrics->meta_buf_size)/ENCODING_LEN;
    nBuf    = LYRICS_MAX_BUFFER_SIZE - g_lyrics->meta_str_size - 
        g_lyrics->meta_buf_size;
    nDst    = g_lyrics->meta_buf_size;
    if (g_lyrics->meta_buf_size > ENCODING_LEN)
    {
        /*remove last end char*/
        pDst -= (ENCODING_LEN/ENCODING_LEN);
        nBuf += ENCODING_LEN;
        nDst -= ENCODING_LEN;
    }

    while (nGet < filesize)
    {
        nSrc    = LYRICS_MAX_LINE_SIZE;
        if (nSrc > filesize - nGet)
        {
            nSrc = filesize - nGet;
        }
        /*check whether buffer is enough for store*/
        switch(g_lyrics->text_encoding)
        {
        case UCS2_BE:
        case UCS2_LE:

            if (nSrc >= nBuf)
            {
                if (0 == nGet)
                {
                    *readsize_p = nGet;
                    return  READ_BUFFER_FULL;
                }
                else
                {
                    /*add last end char*/
                    g_lyrics->meta_buf_size = nDst + ENCODING_LEN;

                    *readsize_p = nGet;
                    return  READ_CONTINUE;
                }
            }
        	break;
        default:

            if (nSrc * ENCODING_LEN >= nBuf)
            {
                if (0 == nGet)
                {
                    *readsize_p = nGet;
                    return  READ_BUFFER_FULL;
                }
                else
                {
                    /*add last end char*/
                    g_lyrics->meta_buf_size = nDst + ENCODING_LEN;

                    *readsize_p = nGet;
                    return  READ_CONTINUE;
                }
            }
            break;
        }
        if (FS_Read(handle, pSrc, nSrc, &nRead) < FS_NO_ERROR)
        {
            META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, nRead);

            return  READ_FAILED;
        }
        if (nSrc != nRead)
        {
            META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, nRead);

            return  READ_FAILED;
        }
        if (UCS2_NONE == g_lyrics->text_encoding)
        {
            g_lyrics->text_encoding = f_get_encoding_type(pSrc);
        }
        if (UCS2_LOCAL == g_lyrics->text_encoding)
        {
            if (f_has_half_char(pSrc, nRead))
            {
                nRead -= 1;
                if (FS_Seek(handle, -1, SEEK_CUR) < FS_NO_ERROR)
                {
                    META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, nRead);
                    
                    return  READ_FAILED;
                }
            }
        }
		else if (UCS2_UTF8 == g_lyrics->text_encoding)
		{
			nBackward = f_has_utf8_whole(pSrc, nRead);
			if (nBackward > 0)
            {
                nRead -= nBackward;
                if (FS_Seek(handle, -nBackward, SEEK_CUR) < FS_NO_ERROR)
                {
                    META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, nRead);
                    
                    return  READ_FAILED;
                }
            }
		}
        pSrc[nRead+0] = 0;
        pSrc[nRead+1] = 0;
        nData   = f_convert_to_ucs2(g_lyrics->text_encoding, nRead, nBuf, 
            pSrc, (kal_uint8*)pDst);
        if (nData < ENCODING_LEN)
        {
            META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, nRead);
            return  READ_FAILED;
        }
        /*remove end char*/
        nData -= ENCODING_LEN;

        nGet += nRead;        
        pDst += (nData/ENCODING_LEN);
        nBuf -= nData;
        nDst += nData;

        if (nSrc < LYRICS_MAX_LINE_SIZE)
        {
            break;
        }
    }
    /*add last end char*/
    g_lyrics->meta_buf_size = nDst + ENCODING_LEN;
    *readsize_p = nGet;

    return  READ_END;
}


/*****************************************************************************
 * FUNCTION
 *  f_parse_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  success return 1, 
 *****************************************************************************/
static  kal_uint8   f_parse_data(kal_uint8 IsEnd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16  *pBeg, *pEnd, *pSrc, *pOrg;
    kal_uint8   bAddLine;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pSrc = g_lyrics->meta_str_buffer+g_lyrics->meta_str_size/ENCODING_LEN;
    pBeg = pSrc;
    pEnd = pSrc;
    pOrg = pSrc;
    
    while (NULL != pBeg || NULL != pEnd)
    {
        if (PARSE_SEARCH_END == g_lyrics->parse_status)
        {
            pEnd = (kal_uint16*)app_ucs2_strchr((kal_int8*)pBeg, L']');
            if (NULL == pEnd)
            {
                if (pBeg == pSrc)
                {
                    return  PARSE_FAILED;
                }
                pSrc = g_lyrics->meta_str_buffer+g_lyrics->meta_str_size/ENCODING_LEN;
                f_memmove((kal_uint8*)pBeg, (kal_uint8*)pOrg, (kal_uint8*)pSrc);

                return  PARSE_CONTINUE;
            }
            bAddLine = f_add_line(pBeg, pEnd);
            if (ADD_LINE_SUCCESS == bAddLine)
            {
                g_lyrics->parse_status = PARSE_SEARCH_TXT;
            }
            else
            {
                g_lyrics->parse_status = PARSE_SEARCH_BEG;
            }
        }
        else
        {
            pBeg = (kal_uint16*)app_ucs2_strchr((kal_int8*)pEnd, L'[');
            if (NULL == pBeg)
            {
                if (0 != IsEnd)
                {
                    if (g_lyrics->meta_info.line_count > 0)
                    {
                        pBeg = pSrc + g_lyrics->meta_buf_size/ENCODING_LEN;
                        f_add_string(pEnd, pBeg);

                        return  PARSE_END;
                    }
                    return  PARSE_FAILED;
                }
                if (pEnd == pSrc)
                {
                    pBeg = pSrc + g_lyrics->meta_buf_size/ENCODING_LEN;
                    f_add_string(pEnd, pBeg);

                    return  PARSE_BUFFER_FULL;
                }
                pSrc = g_lyrics->meta_str_buffer+g_lyrics->meta_str_size/ENCODING_LEN;
                f_memmove((kal_uint8*)pEnd, (kal_uint8*)pOrg, (kal_uint8*)pSrc);

                return  PARSE_CONTINUE;
            }
            if ((pBeg > pEnd + 1) && (PARSE_SEARCH_TXT == g_lyrics->parse_status))
            {     
                f_add_string(pEnd, pBeg);
            }
            g_lyrics->parse_status = PARSE_SEARCH_END;
        }
    }    
    return  PARSE_FAILED;
}


/*****************************************************************************
 * FUNCTION
 *  f_memmove
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  success return 1, 
 *****************************************************************************/
static  void f_memmove(kal_uint8* pBeg, kal_uint8* pOrg, kal_uint8* pDst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  nSize;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nSize = pBeg - pOrg;
    g_lyrics->meta_buf_size -= nSize;
    nSize = LYRICS_MAX_BUFFER_SIZE - 
        (pDst-(kal_uint8*)g_lyrics->meta_str_buffer);
    
    if (g_lyrics->meta_buf_size > 0)
    {
        if (g_lyrics->meta_buf_size > nSize)
        {
            /*The source buffer reduced for buffer overflower*/
            META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, g_lyrics->meta_buf_size);
            META_TAG_ERR_TRACE(FILE_ID_LYC_PARSER, nSize);
            g_lyrics->meta_buf_size = nSize;
        }
        kal_mem_cpy(pDst, pBeg, g_lyrics->meta_buf_size);
    }    
}


/*****************************************************************************
 * FUNCTION
 *  f_add_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *   pBeg must be L'['
 *	 pEnd must be L']'
 * RETURNS
 *  success return 1, 
 *****************************************************************************/
static  kal_uint8   f_add_line(kal_uint16* pBeg, kal_uint16* pEnd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #define TIME_TAG_NUM 4
    kal_uint32  nMsTimes;
    kal_int32   aNum[TIME_TAG_NUM], hh, mm, ss, ms, nLen, i, j, nNum;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_lyrics->meta_info.line_count >= LYRICS_MAX_LINES)
    {
        return  ADD_LINE_BUFFER_FULL;
    }
    nLen = pEnd - pBeg;
    if (nLen < 3)
    {
        return  ADD_LINE_SKIP;
    }
	hh		= 0;
	mm		= 0;
	ss		= 0;
    ms		= 0;
	nNum	= 0;
	i		= 1;
	j		= 0;

	while ( i < nLen )
	{
		while (wc_isdigit(pBeg[i+j])) j++;

		if (j < 1)
		{
			if (i == 1)
			{
				if (0 == app_ucs2_strncmp((kal_int8*)(pBeg+1), (kal_int8*)(L"offset:"), 7) && nLen > 7)
				{
					g_lyrics->meta_info.ms_time_offset = app_ucs2_atoi((kal_int8*)(pBeg+8));        
				}
			}
			return  ADD_LINE_SKIP;
		}

		if (L':' == pBeg[i+j])
		{
			aNum[nNum++] = app_ucs2_atoi((kal_int8*)(pBeg+i));	
			i += j+1;
			j = 0;
		}
		else 
		{
			aNum[nNum++] = app_ucs2_atoi((kal_int8*)(pBeg+i));

			if (L'.' == pBeg[i+j])
			{
				i += j+1;
				ms = app_ucs2_atoi((kal_int8*)(pBeg+i));				
				j = 0;
				while (wc_isdigit(pBeg[i+j])) j++;
				
				if (j > 1 && ms > 0)
				{
					while (j < 3)
					{
						ms *= 10;
						j++;
					}
				}
			}
			else
			{
				if (L']' != pBeg[i+j])	/*strictly check, not allow other char in time stamp*/
				{
					return  ADD_LINE_SKIP;
				}
			}
			break;
		}
		if (TIME_TAG_NUM <= nNum)
		{
			return	ADD_LINE_SKIP;
		}
	}
	if (nNum > 0)
	{
		ss = aNum[nNum-1];
		nNum--;
		if (nNum > 0)
		{
			mm = aNum[nNum-1];
			nNum--;
			if (nNum > 0)
			{
				hh = aNum[nNum-1];
			}
		}
	}

	if (hh > 100 || mm > 60 || ss > 60 || ms > 1000)
	{
		/*not legal format*/
		return  ADD_LINE_SKIP;
	}
	nMsTimes = ((hh * 3600 + mm * 60 + ss)*1000+ms)/g_lyrics->update_ms;
	g_lyrics->meta_info.lines_p[g_lyrics->meta_info.line_count].id_time = nMsTimes; 
	g_lyrics->meta_info.lines_p[g_lyrics->meta_info.line_count].st_text = 
		g_lyrics->meta_str_buffer + g_lyrics->meta_str_size/ENCODING_LEN;
	f_Inert_Line(g_lyrics->meta_info.line_count);
	
    return  ADD_LINE_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  f_Inert_Line
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  success return 1, 
 *****************************************************************************/
static  void f_Inert_Line(kal_uint16 lineID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    lyrics_line_struct* pLines;
    kal_uint16  prevID, currID, nCount;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pLines = g_lyrics->meta_info.lines_p;

    if (0 == g_lyrics->meta_info.line_count)
    {
        pLines[lineID].id_next = LYRICS_MAX_LINES;
        pLines[lineID].id_prev = LYRICS_MAX_LINES;

        g_lyrics->meta_info.id_fst_line = lineID;
        g_lyrics->meta_info.line_count ++;
        return;
    }    
    prevID = g_lyrics->meta_info.id_fst_line;
    if (pLines[lineID].id_time < pLines[prevID].id_time)
    {
        pLines[lineID].id_prev = pLines[prevID].id_prev;        
        pLines[lineID].id_next = prevID;
        pLines[prevID].id_prev = lineID;

        g_lyrics->meta_info.id_fst_line = lineID;
        g_lyrics->meta_info.line_count ++;
        return;
    }
    nCount = 1;
    currID = pLines[prevID].id_next;
    
    while (currID < LYRICS_MAX_LINES && nCount < g_lyrics->meta_info.line_count)
    {
        if (pLines[currID].id_time > pLines[lineID].id_time)
            break;

        prevID = currID;
        currID = pLines[prevID].id_next;
        nCount ++;
    }
    pLines[prevID].id_next = lineID;
    pLines[lineID].id_prev = prevID;
    pLines[lineID].id_next = currID;
    if (currID < LYRICS_MAX_LINES)
    {
        pLines[currID].id_prev = lineID;
    }
    g_lyrics->meta_info.line_count ++;
}


/*****************************************************************************
 * FUNCTION
 *  get_encoding_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  success return encoding type, 
 *****************************************************************************/
static  void f_add_string(kal_uint16* pBeg, kal_uint16* pEnd)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16  *pStr;
    kal_uint16  nLen, i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*2 bytes for content , 2 bytes for end char*/
    if (g_lyrics->meta_str_size + 4 >= LYRICS_MAX_BUFFER_SIZE )
    {
        return;
    }
    if (*pBeg == L']')
        pBeg++;

    while (wc_isspace(*pBeg) && pBeg < pEnd)
    {
        pBeg++;
    }    

    pStr = g_lyrics->meta_str_buffer + g_lyrics->meta_str_size/ENCODING_LEN;
    nLen = pEnd - pBeg;

    for (i = 0; i < nLen; i++)
    {
        if (pBeg[i] == L'\n' || pBeg[i] == L'\r' || pBeg[i] == L'\t')
        {
            pStr[i] = 0;
            g_lyrics->meta_str_size += ENCODING_LEN;
            break;
        }        
        pStr[i] = pBeg[i] ;
        g_lyrics->meta_str_size += ENCODING_LEN;
        if (((g_lyrics->meta_str_size + 2) >= LYRICS_MAX_BUFFER_SIZE) ||
			(i >= LYRICS_MAX_CHAR_INLINE))
        {   /*buffer full*/
            break;
        }
    }   
    if (i > 0 && wc_isspace(pStr[i-1]))
    {
        for (; i > 0; i--)
        {
            if (!wc_isspace(pStr[i-1]))
            {
                pStr[i] = 0;
                break;
            }
            g_lyrics->meta_str_size -= ENCODING_LEN;
        }
    }
    if (0 != pStr[i])
    {
        pStr[i] = 0;
        g_lyrics->meta_str_size += ENCODING_LEN;
    }
}


/*****************************************************************************
 * FUNCTION
 *  get_encoding_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  success return encoding type, 
 *****************************************************************************/
static  kal_uint8   f_get_encoding_type(kal_uint8* pstr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pstr[0] == 0xEF && pstr[1] == 0xBB && pstr[2] == 0xBF)
    {
        return UCS2_UTF8;
    }
    else if (pstr[0] == 0xFE && pstr[1] == 0xFF)
    {
        return UCS2_BE;
    }
    else if (pstr[0] == 0xFF && pstr[1] == 0xFE)
    {
        return UCS2_LE;
    }
    return UCS2_LOCAL;
}

/*****************************************************************************
 * FUNCTION
 *  f_has_utf8_whole
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  return backward char number 
 *****************************************************************************/
static  kal_uint8 f_has_utf8_whole(kal_uint8* pstr, kal_uint32 nstr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_uint32  i = 1;
	kal_int32 	count;
    kal_uint8   j = 0;
	kal_uint8 	c;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while(i <= 4)
    {
        c = pstr[nstr - i];
        count = g_cheset_utf8_bytes[c >> 4];
        if (count == 1)
        {
            META_TAG_MSG_TRACE(FILE_ID_LYC_PARSER, j);
            break;
        }
        else if (count > 1)
        {
            j++;
            if (j == count)
            {
                META_TAG_MSG_TRACE(FILE_ID_LYC_PARSER, j);
                j = 0;
            }
            else
            {					
                META_TAG_MSG_TRACE(FILE_ID_LYC_PARSER, j);					
            }		
            break;
        }
        j++;
        i++;	 
    }
  
	META_TAG_MSG_TRACE(FILE_ID_LYC_PARSER, j);
    return  j;	
}

/*****************************************************************************
 * FUNCTION
 *  get_encoding_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  success return encoding type, 
 *****************************************************************************/
static  kal_uint8   f_has_half_char(kal_uint8* pstr, kal_uint32 nstr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_uint32  i;
    kal_uint8   j = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < nstr; i++)
    {
        if (pstr[i] <= 0x7f && 0 == j)
        {
            continue;
        }
        j = 1-j;
    }
    return  j;
}


/*****************************************************************************
 * FUNCTION
 *  get_encoding_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  success return encoding type, 
 *****************************************************************************/
static  kal_int32  f_convert_to_ucs2(kal_uint16 type, kal_uint32 nsrc,
                                     kal_uint32 ndst, kal_uint8* psrc, 
                                     kal_uint8* pdst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i, nRet = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(type)
    {
    case UCS2_LE:
        
        if (ndst > 2)
        {
            nRet = nsrc;
            if (nRet > (kal_int32)(ndst - 2))
                nRet = ndst - 2;

            kal_mem_cpy(pdst, psrc, nRet);
            pdst[nRet++] = 0;
            pdst[nRet++] = 0;
        }
        break;
    case UCS2_BE:  
              
        if (ndst > 2)
        {
            nRet = nsrc;
            if (nRet > (kal_int32)(ndst - 2))
                nRet = ndst - 2;

            for (i = 0; i < nRet ; i += 2)
            {
                pdst[i + 0] = psrc[i + 1];
                pdst[i + 1] = psrc[i + 0];
            }
            pdst[nRet++] = 0;
            pdst[nRet++] = 0;
        }
        break;
    case UCS2_UTF8:   
        
        nRet    = mmi_chset_convert(CHSET_UTF8, CHSET_UCS2, 
            (char*)psrc, (char*)pdst, ndst);
        break;
    case UCS2_LOCAL:        
    default:
          
        nRet = mmi_chset_text_to_ucs2((kal_uint8*)pdst, 
            ndst, psrc);
        break;
    }   
    return  nRet;
}

#endif  /*#if defined(__TAG_SUPPORT_LYRICS_EXT__)*/

