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
*   meta_tag_api.c
*
* Project:
* --------
*   Maui
*
* Description:
* ------------
*   This file includes primary exported functions of audio module.
*
* Author:
* -------
 * -------
*
*==============================================================================
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
#include "Conversions.h"
//#include "kal_release.h"
//#include "app_buff_alloc.h"
#include "app_str.h"
#include "Drm_gprot.h"
#include "L1audio.h"
#include "med_main.h"
#include "med_utility.h"
#include "Aud_main.h"

#include "meta_tag_api.h"
#include "meta_tag_parser.h"
#include "kal_public_api.h"
#include "fs_type.h"
#include "kal_general_types.h"
#include "med_trc.h"
#include "kal_trace.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "drm_def.h"
#include "drm_errcode.h"
#include "fsal.h"
#include "med_global.h"
#include "med_v_struct.h"
#include "kal_public_defs.h"


#if defined(__META_DATA_PARSE_API__)

#if defined(__TAG_SUPPORT_APE__)
#include "ape_parser.h"
#endif

#if defined (__TAG_SUPPORT_ID3V1__) || defined (__TAG_SUPPORT_APE__)
#include "id3_v1_parser.h"
#endif

#if defined(__TAG_SUPPORT_ID3V2__)
#include "id3_v2_parser.h"
#endif

#if defined(__TAG_SUPPORT_KURO__)
#include "kuro_lrc_parser.h"
#endif

/*  DEFINE MACRO HERE
*/
#define META_TAG_MAX_HANDLE             0x0005
#define META_TAG_HAS_INIT               0x0001
#define META_TAG_HAS_PARSED             0x0002
#define META_TAG_HAS_AUDIO              0x0004
#define META_TAG_HAS_MUSIC              0x0008
#define META_TAG_HAS_FILE_OPENED        0x0100

#define META_GET_HANDLE(ID, handle_p)                                   \
    do                                                                  \
    {                                                                   \
        ASSERT(0 != ID);                                                \
                                                                        \
        handle_p = (meta_tag_handle_struct*)ID;                         \
        if (!(handle_p->flags & META_TAG_HAS_INIT))                     \
        {                                                               \
            /*error trace*/                                             \
            return  META_TAG_ERR_INVAILD_HANDLE;                        \
        }                                                               \
                                                                        \
    } while (0)

/*  define data struct
*/
typedef struct
{
    meta_tag_internal_info_struct   inter_info;

    FS_HANDLE   file_handle;               
    kal_uint32  attr_support;    
    kal_uint8*  buffer_p; 
    kal_uint32  buffer_size;
    kal_uint32  buffer_offset;
    kal_uint16  flags;   
    kal_uint8   file_format;
    kal_uint8   format;   
    
}   meta_tag_handle_struct;

/*  define function
*/
static  kal_uint8*  tag_getbuffer(
                        kal_uint32 metaID, 
                        kal_uint32 buffersize
                        );
static  kal_uint32  tag_file_read(
                        kal_uint32 metaID, 
                        kal_uint8* buffer, 
                        kal_uint32 readsize
                        );
kal_uint8   meta_write_file_rating(
                        kal_uint32 metaID, 
                        kal_uint16 *filepath, 
                        kal_int32 rating, 
                        kal_uint32 count);

static  kal_int32   tag_file_seek(
                        kal_uint32 metaID, 
                        kal_int32 offset, 
                        kal_uint8 seekpos
                        );
static  kal_uint32 tag_file_write(
                        kal_uint32 metaID, 
                        kal_uint8* buffer, 
                        kal_uint32 writesize
                        );
static  kal_int32   tag_file_getlocation(
                        kal_uint32 metaID
                        );
static  kal_int32 tag_file_commit(kal_uint32 metaID);
static  void        tag_clean_parser(
                        meta_tag_handle_struct* phandle
                        );
static  kal_uint8   tag_start_parser(
                        meta_tag_handle_struct* phandle
                        );
static  void        tag_check_text_attrs(
                        meta_tag_handle_struct* phandle
                        );
static  void        tag_check_integer_attrs(meta_tag_handle_struct* phandle);

#if defined (__TAG_SUPPORT_APE__)
static  kal_uint8   tag_has_ape(
                        meta_tag_handle_struct* phandle, 
                        kal_int32* pPos, 
                        kal_uint8* pFrom
                        );
#endif  /*defined (__TAG_SUPPORT_APE__)*/

#if defined (__TAG_SUPPORT_ID3V2__)
static  kal_uint8   tag_has_id3v2(
                        meta_tag_handle_struct* phandle, 
                        kal_int32* pPos, 
                        kal_uint8* pFrom
                        );
#endif  /*defined (__TAG_SUPPORT_ID3V2__)*/

#if defined (__TAG_SUPPORT_ID3V1__) || defined (__TAG_SUPPORT_APE__)
static  kal_uint8   tag_has_id3v1(
                        meta_tag_handle_struct* phandle, 
                        kal_int32* pPos, 
                        kal_uint8* pFrom
                        );
#endif  /*defined (__TAG_SUPPORT_ID3V1__)*/

#if defined (__TAG_SUPPORT_DCF__)
static  void        tag_get_meta_from_dcf_file(
                        meta_tag_handle_struct* phandle
                        );
#endif  /*defined (__TAG_SUPPORT_DCF__)*/

#if defined (__TAG_SUPPORT_DRIVER__)
static  kal_uint8   tag_get_meta_from_audio_driver(
                        meta_tag_handle_struct* phandle
                        );
#endif  /*defined (__TAG_SUPPORT_DRIVER__)*/

#if defined (__TAG_SUPPORT_KURO__)
static  kal_uint8   tag_get_meta_from_kuro(
                        meta_tag_handle_struct* phandle, kal_uint16* file_path
                        );
#endif

/*  DEFINE GLOBAL VARIABLE
*/
static  meta_tag_func_struct    g_func_file = 
{
    tag_getbuffer,
    tag_file_read,
    tag_file_seek,
    tag_file_write,
    tag_file_getlocation,
    tag_file_commit,
};  

static  kal_uint8 g_meta_handle_count = 0;

/*****************************************************************************
 * FUNCTION
 *  meta_parser_create
 * DESCRIPTION
 *  Create a meta parser handle
 * PARAMETERS
 *  buffer           [IN]        Buffer for feedback text attributes
 *  buffersize       [IN]        buffer size
 * RETURNS
 *  kal_uint32 meta parse handle, can not used in 64bit 
 *****************************************************************************/
kal_uint8  meta_parser_create(kal_uint8* buffer, kal_uint32 buffersize, kal_uint32 *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    meta_tag_handle_struct* phandle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    ASSERT(NULL != buffer);
    ASSERT(0 != buffersize);

    if (buffersize < META_TAG_PARSE_MIN_SIZE)
    {
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, buffersize);

        return  META_TAG_ERR_NOT_ENOUGH_BUFFER;
    }
    if (g_meta_handle_count == META_TAG_MAX_HANDLE)
    {
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, g_meta_handle_count);

        return  META_TAG_ERR_NO_HANDLE;
    }
    phandle = (meta_tag_handle_struct*)get_ctrl_buffer(
        sizeof(meta_tag_handle_struct));
    if (NULL == phandle)
    {
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, phandle);

        return  META_TAG_ERR_NO_MEMORY;
    }
    g_meta_handle_count++;
    kal_mem_set(phandle, 0, sizeof(meta_tag_handle_struct));
    
    phandle->buffer_p       = buffer;
    phandle->buffer_size    = buffersize;
    phandle->flags          = META_TAG_HAS_INIT;    
    
    *handle = (kal_int32)phandle;
    META_TAG_MSG_TRACE(FILE_ID_META_TAG_API, phandle);
    
    return  META_TAG_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  meta_parser_release
 * DESCRIPTION
 *  release a meta parser handle
 * PARAMETERS
 *  metaID           [IN]        meta parser handle ID
 * RETURNS
 *  kal_uint8, success return META_TAG_ERR_NONE
 *****************************************************************************/
kal_uint8   meta_parser_release(kal_uint32 metaID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    meta_tag_handle_struct* phandle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    META_TAG_MSG_TRACE(FILE_ID_META_TAG_API, g_meta_handle_count);
    META_GET_HANDLE(metaID, phandle);

    tag_clean_parser(phandle);
    phandle->flags = 0;
    free_ctrl_buffer((void*)phandle);

    ASSERT(g_meta_handle_count > 0);
    g_meta_handle_count--;
    
    return  META_TAG_ERR_NONE;
}

#ifdef __TAG_SUPPORT_WRITE_BACK__
kal_uint8   meta_write_file_info(kal_uint32 metaID,	kal_uint16 *filepath, meta_tag_write_item_enum tagID,	kal_uint32 para1, kal_uint32 para2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
	  kal_uint8 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(tagID)
	{
	case META_TAG_WRITE_ITEM_RATING:
		ret = meta_write_file_rating(metaID, filepath, para1, para2);
		break;
	default:
		ret = META_TAG_ERR_NOT_SUPPORT;
		break;
	}	
	return ret;
}

/*****************************************************************************
 * FUNCTION
 *  meta_parse_file
 * DESCRIPTION
 *  parse meta data from music file
 * PARAMETERS
 *  metaID          [IN]    meta parser handle ID
 *  filepath        [IN]    music file path
 * RETURNS
 *  kal_uint8, success return META_TAG_ERR_NONE
 *****************************************************************************/
kal_uint8   meta_write_file_rating(kal_uint32 metaID, kal_uint16 *filepath, kal_int32 rating, kal_uint32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
	meta_tag_handle_struct* phandle; 
	kal_int16   u16FileFormat;
    kal_int32   s32Location = 0;
    kal_uint8   u8Ret, u8SeekFrom;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ASSERT(NULL != filepath);
    META_GET_HANDLE(metaID, phandle);

	tag_clean_parser(phandle);

	/* check if is valid format*/
	u16FileFormat = med_get_media_type(filepath);
	if ((MED_TYPE_AAC != u16FileFormat) && (MED_TYPE_DAF != u16FileFormat) &&
		(MED_TYPE_MUSICAM != u16FileFormat) && (MED_TYPE_BSAC != u16FileFormat))
    {
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, u16FileFormat);        
        return  META_TAG_ERR_NOT_SUPPORT;
    }

	phandle->file_handle = FS_Open(filepath, FS_READ_WRITE);
	if (phandle->file_handle <= FS_NO_ERROR)
	{
		META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, phandle->file_handle); 
		return META_TAG_ERR_OPEN_FILE_FAILED;
	}
	phandle->flags |= META_TAG_HAS_FILE_OPENED;
	phandle->inter_info.func_p = &g_func_file;

	/* check if has id3v2 tag*/
#if defined (__TAG_SUPPORT_ID3V2__)
    u8Ret   = tag_has_id3v2(phandle, &s32Location, &u8SeekFrom);
#else
    u8Ret   = META_TAG_ERR_NOT_SUPPORT;
#endif
	if (META_TAG_ERR_NONE != u8Ret)
	{
		return u8Ret;
	}
	
	if ((rating < 0) || (rating > 255))
	{
		META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, rating); 
		phandle->inter_info.music_info.user_rate = 0;
	}
	else
	{
		phandle->inter_info.music_info.user_rate = rating;
	}	
	phandle->inter_info.music_info.play_count = count;
	phandle->inter_info.func_p->tag_seek(metaID, s32Location, u8SeekFrom);
	
	return id3_tag_v2_parse_to_write(metaID, &phandle->inter_info);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  meta_parse_file
 * DESCRIPTION
 *  parse meta data from music file
 * PARAMETERS
 *  metaID          [IN]    meta parser handle ID
 *  filepath        [IN]    music file path
 * RETURNS
 *  kal_uint8, success return META_TAG_ERR_NONE
 *****************************************************************************/
kal_uint8   meta_parse_file(kal_uint32 metaID, kal_uint16 *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return  meta_parse_file_with_encoding_type(metaID, filepath, 
        META_TAG_TEXT_ENCODING_UCS2);
}

/*****************************************************************************
 * FUNCTION
 *  meta_parse_file
 * DESCRIPTION
 *  parse meta data from music file
 * PARAMETERS
 *  metaID          [IN]    meta parser handle ID
 *  filepath        [IN]    music file path
 *  preferEncoding  [IN]    charset prefer encoding type, will help to transfer to it,
                            Currently only support ucs2
 * RETURNS
 *  kal_uint8, success return META_TAG_ERR_NONE
 *****************************************************************************/
kal_uint8  meta_parse_file_with_encoding_type(kal_uint32 metaID, 
                                              kal_uint16 *filepath,
                                              kal_uint8  preferEncoding)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    meta_tag_handle_struct* phandle;  
    kal_int16   u16FileFormat;
    kal_uint8   u8Ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    ASSERT(NULL != filepath);
    META_GET_HANDLE(metaID, phandle);

    tag_clean_parser(phandle);
   
    u16FileFormat = med_get_media_type(filepath);
    if (MED_TYPE_NONE == u16FileFormat)
    {
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, u16FileFormat);
        
        return  META_TAG_ERR_NOT_SUPPORT;
    }
    phandle->file_format = (kal_uint8)u16FileFormat;
    META_TAG_MSG_TRACE(FILE_ID_META_TAG_API, phandle->file_format);

#if defined (__DRM_SUPPORT__)
    phandle->file_handle = 
        DRM_open_file(filepath, FS_READ_ONLY, DRM_PERMISSION_PLAY);    
    if (phandle->file_handle <= DRM_RESULT_OK)
#else
    phandle->file_handle = FS_Open(filepath, FS_READ_ONLY);    
    if (phandle->file_handle <= FS_NO_ERROR)
#endif
    {
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, phandle->file_handle);

        return  META_TAG_ERR_OPEN_FILE_FAILED;
    }              
    phandle->inter_info.func_p = &g_func_file;
    phandle->inter_info.prefer_charset = preferEncoding;

#if defined (__TAG_SUPPORT_DCF__)
#ifndef __DRM_EXTERNAL__
    if (0 == DRM_validate_permission(phandle->file_handle, 
        NULL, DRM_PERMISSION_PLAY))
    {
        /*parser meta from dcf*/
        tag_get_meta_from_dcf_file(phandle);
        DRM_close_file(phandle->file_handle);

        META_TAG_MSG_TRACE(FILE_ID_META_TAG_API, phandle->format);

        return  META_TAG_ERR_NONE;
    }
#endif
#endif  
#if defined (__TAG_SUPPORT_DRIVER__)  
    u8Ret = tag_get_meta_from_audio_driver(phandle);
#endif  /*(__TAG_SUPPORT_DRIVER__)*/

    switch (phandle->file_format)
    {
#if defined(DAF_DECODE) || defined(AAC_DECODE)
        
#if defined(DAF_DECODE)
    case MED_TYPE_DAF:
    #ifdef MUSICAM_DECODE
    case MED_TYPE_MUSICAM:
    #endif
#endif
#if defined(AAC_DECODE)    
    case MED_TYPE_AAC:
    case MED_TYPE_BSAC:
#endif
#if defined(__APE_DECODE__)    
    case MED_TYPE_APE:
#endif

        u8Ret = tag_start_parser(phandle);
        if (META_TAG_ERR_NONE == u8Ret && 
            META_TAG_FMT_TOTAL != phandle->format)
        {
            phandle->flags |= META_TAG_HAS_FILE_OPENED;

            META_TAG_MSG_TRACE(FILE_ID_META_TAG_API, phandle->format);
            
            return  u8Ret;
        }
        break; 
#endif      
    default:
        break;
    }          
#if defined (__DRM_SUPPORT__)    
    DRM_close_file(phandle->file_handle);
#else
    FS_Close(phandle->file_handle);
#endif  
    META_TAG_MSG_TRACE(FILE_ID_META_TAG_API, phandle->format);

    if (phandle->flags & (META_TAG_HAS_AUDIO | META_TAG_HAS_MUSIC))
    {        
        return META_TAG_ERR_NONE; 
    }
    else
    {
        META_TAG_MSG_TRACE(FILE_ID_META_TAG_API, u8Ret);
        return  u8Ret;
    }
}


/*****************************************************************************
 * FUNCTION
 *  meta_get_format
 * DESCRIPTION
 *  get meta tag format
 * PARAMETERS
 *  metaID          [IN]    meta parser handle ID
 *  pFormat         [OUT]   
 * RETURNS
 *  kal_uint8, success return META_TAG_ERR_NONE
 *****************************************************************************/
kal_uint8   meta_get_format(kal_uint32 metaID, kal_uint8* pFormat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    meta_tag_handle_struct* phandle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    ASSERT(NULL != pFormat);
    META_GET_HANDLE(metaID, phandle);

    if (phandle->flags & META_TAG_HAS_PARSED)
    {
        *pFormat = phandle->format;

        return  META_TAG_ERR_NONE;
    }
    return  META_TAG_ERR_NO_INPUT;
}


/*****************************************************************************
 * FUNCTION
 *  meta_get_audio_info
 * DESCRIPTION
 *  get meta audio information
 * PARAMETERS
 *  metaID          [IN]    meta parser handle ID
 *  pGet            [OUT]   
 * RETURNS
 *  kal_uint8, success return META_TAG_ERR_NONE
 *****************************************************************************/
kal_uint8   meta_get_audio_info(
                kal_uint32 metaID, 
                meta_tag_audio_info_struct** pGet
                )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    meta_tag_handle_struct* phandle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    ASSERT(NULL != pGet);
    META_GET_HANDLE(metaID, phandle);

    if (!(phandle->flags & META_TAG_HAS_PARSED))
    {
        return  META_TAG_ERR_NO_INPUT;
    }    
    if (!(phandle->flags & META_TAG_HAS_AUDIO))
    { 
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, phandle->flags);

        return  META_TAG_ERR_NO_INPUT;
    }
    *pGet = &phandle->inter_info.audio_info;

    return  META_TAG_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  meta_get_audio_info
 * DESCRIPTION
 *  get meta audio information
 * PARAMETERS
 *  metaID          [IN]    meta parser handle ID
 *  pGet            [OUT]   
 * RETURNS
 *  kal_uint8, success return META_TAG_ERR_NONE
 *****************************************************************************/
kal_uint8   meta_get_music_info(
                kal_uint32 metaID, 
                meta_tag_music_info_struct** pGet
                )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    meta_tag_handle_struct* phandle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    ASSERT(NULL != pGet);
    META_GET_HANDLE(metaID, phandle);
    
    if (!(phandle->flags & META_TAG_HAS_PARSED))
    {
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, phandle->flags);

        return  META_TAG_ERR_NO_INPUT;
    } 
    if (!(phandle->flags & META_TAG_HAS_MUSIC))
    { 
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, phandle->flags);
        
        return  META_TAG_ERR_NO_INPUT;
    }
    *pGet = &phandle->inter_info.music_info;
    
    return  META_TAG_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  meta_get_attach_cover_info
 * DESCRIPTION
 *  get meta attach cover image information
 * PARAMETERS
 *  metaID          [IN]    meta parser handle ID
 *  pGet            [OUT]   
 * RETURNS
 *  kal_uint8, success return META_TAG_ERR_NONE
 *****************************************************************************/
kal_uint8   meta_get_attach_cover_info(
                kal_uint32 metaID, 
                meta_tag_img_info_struct** pGet
                )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    meta_tag_handle_struct* phandle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    ASSERT(NULL != pGet);
    META_GET_HANDLE(metaID, phandle);
    
    if (!(phandle->flags & META_TAG_HAS_PARSED))
    {
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, phandle->flags);

        return  META_TAG_ERR_NO_INPUT;
    } 
    *pGet = &phandle->inter_info.image_info;
    
    return  META_TAG_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  meta_get_attach_cover_data
 * DESCRIPTION
 *  get attached picture from meta data
 * PARAMETERS
 *  metaID          [IN]        meta parser handle ID
 *  pBuffer         [IN & OUT]  input buffer for store image data
 *  BufferSize
 * RETURNS
 *  kal_uint8, success return META_TAG_ERR_NONE
 *****************************************************************************/
kal_uint8   meta_get_attach_cover_data(
                kal_uint32 metaID, 
                kal_uint8* pBuffer, 
                kal_uint32 BufferSize
                )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    meta_tag_handle_struct* phandle;
    kal_uint8 nRet = META_TAG_ERR_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    ASSERT(NULL != pBuffer);
    ASSERT(0 != BufferSize);
    META_GET_HANDLE(metaID, phandle);
    ASSERT(BufferSize >= phandle->inter_info.image_info.data_size);
    ASSERT(phandle->inter_info.image_info.frame_location > 0);

    phandle->inter_info.func_p->tag_seek(metaID, 
        phandle->inter_info.image_info.frame_location, FUNC_SEEK_SET);

    switch(phandle->format)
    {
#if defined (__TAG_SUPPORT_ID3V2__)   
    case META_TAG_FMT_IDV3_2:   

        nRet = id3_tag_v2_parse_attach_cover(metaID, pBuffer, BufferSize,
            &phandle->inter_info);
    	break;
#endif  /*defined (__TAG_SUPPORT_ID3V2__)*/
    default:

        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, phandle->format);

        nRet = META_TAG_ERR_NOT_SUPPORT;
        break;
    }
    return  nRet;
}


/*****************************************************************************
 * FUNCTION
 *  meta_get_sync_lyrics_info
 * DESCRIPTION
 *  get meta attach lyrics information
 * PARAMETERS
 *  metaID          [IN]    meta parser handle ID
 *  pGet            [OUT]   
 * RETURNS
 *  kal_uint8, success return META_TAG_ERR_NONE
 *****************************************************************************/
kal_uint8   meta_get_sync_lyrics_info(
                kal_uint32 metaID, 
                meta_tag_sync_lyc_info_struct** pGet
                )
{
    return META_TAG_ERR_NOT_SUPPORT;
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
#endif
}


/*****************************************************************************
 * FUNCTION
 *  meta_get_sync_lyrics_data
 * DESCRIPTION
 *  get attached lyrics from meta data
 * PARAMETERS
 *  metaID          [IN]        meta parser handle ID
 *  pBuffer         [IN & OUT]  input buffer for store data
 *  BufferSize
 * RETURNS
 *  kal_uint8, success return META_TAG_ERR_NONE
 *****************************************************************************/
kal_uint8   meta_get_sync_lyrics_data(
                kal_uint32 metaID, 
                kal_uint8* pBuffer, 
                kal_uint32 BufferSize
                )
{
    return META_TAG_ERR_NOT_SUPPORT;
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
#if defined (__TAG_SUPPORT_ID3V2__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  /*defined (__TAG_SUPPORT_ID3V2__)*/
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
 *  tag_clean_parser
 * DESCRIPTION
 *  clean parse status and clean parse information
 * PARAMETERS
 *  phandle         [IN]    meta parser handle
 * RETURNS
 *  void
 *****************************************************************************/
static  void    tag_clean_parser(meta_tag_handle_struct* phandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (phandle->flags & META_TAG_HAS_FILE_OPENED)
    {
        phandle->flags &= ~META_TAG_HAS_FILE_OPENED;
#if defined (__DRM_SUPPORT__)    
        DRM_close_file(phandle->file_handle);
#else
        FS_Close(phandle->file_handle);
#endif
    }
    phandle->flags &= ~(META_TAG_HAS_PARSED|META_TAG_HAS_AUDIO|META_TAG_HAS_MUSIC);
    phandle->format         = META_TAG_FMT_OTHER;
    phandle->attr_support   = 0;
    phandle->buffer_offset  = 0;

    kal_mem_set(&phandle->inter_info, 0, sizeof(meta_tag_internal_info_struct));

    phandle->inter_info.music_info.bits_rate = -1;
    phandle->inter_info.music_info.duration = -1;
    phandle->inter_info.music_info.track_count = -1;
    phandle->inter_info.music_info.track_number = -1;
    phandle->inter_info.music_info.year = -1;
}


/*****************************************************************************
 * FUNCTION
 *  tag_start_parser
 * DESCRIPTION
 *  start paser meta data
 * PARAMETERS
 *  phandle         [IN]    meta parser handle
 * RETURNS
 *  kal_uint8, success return META_TAG_ERR_NONE
 *****************************************************************************/
static  kal_uint8    tag_start_parser(meta_tag_handle_struct* phandle)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined (__TAG_SUPPORT_ID3V1__)
    kal_uint32  u32Id3v1Attr;
#endif
    kal_uint32  metaID;
    kal_int32   s32Location;
    kal_uint8   u8Ret, u8SeekFrom;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    metaID  = (kal_uint32)phandle;    
#if defined (__TAG_SUPPORT_ID3V2__)
    u8Ret   = tag_has_id3v2(phandle, &s32Location, &u8SeekFrom);
#else
    u8Ret   = META_TAG_ERR_NOT_SUPPORT;
#endif  /*#if defined (__TAG_SUPPORT_ID3V2__)*/

    switch(u8Ret)
    {
#if defined (__TAG_SUPPORT_ID3V2__)    
    case META_TAG_ERR_NONE:

        phandle->inter_info.func_p->tag_seek(metaID, s32Location, u8SeekFrom);
        u8Ret = id3_tag_v2_parse(metaID, &phandle->inter_info);

        if (META_TAG_ERR_NONE == u8Ret)
        {
            phandle->format = META_TAG_FMT_IDV3_2;
        }
    	break;
#endif  /*#if defined (__TAG_SUPPORT_ID3V2__)*/

#if defined (__TAG_SUPPORT_APE__) 
    case META_TAG_ERR_NOT_SUPPORT:

        u8Ret = tag_has_ape(phandle, &s32Location, &u8SeekFrom);
        if (META_TAG_ERR_NONE == u8Ret)
        {
            phandle->inter_info.func_p->tag_seek(metaID, s32Location, u8SeekFrom);
            u8Ret = ape_tag_parse(metaID, &phandle->inter_info);
            if (META_TAG_ERR_NONE == u8Ret)
            {
                phandle->format = META_TAG_FMT_APE;
            }
        }
        break;
#endif  /*#if defined (__TAG_SUPPORT_APE__) */
    default:
        
        break;
    }
    if (META_TAG_ERR_NOT_SUPPORT != u8Ret &&
        META_TAG_ERR_NONE != u8Ret)
    {
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, u8Ret);

        return  u8Ret;
    }    
    tag_check_integer_attrs(phandle);
    tag_check_text_attrs(phandle);

#if defined (__TAG_SUPPORT_ID3V1__)
    u32Id3v1Attr = phandle->attr_support & META_TAG_ATTR_IDV3_1;
    if ((META_TAG_FMT_OTHER == phandle->format) || 
        (u32Id3v1Attr != META_TAG_ATTR_IDV3_1))
    {
        u8Ret = tag_has_id3v1(phandle, &s32Location, &u8SeekFrom);
        if (META_TAG_ERR_NONE == u8Ret)
        {
            phandle->inter_info.func_p->tag_seek(metaID, s32Location, u8SeekFrom);
            u8Ret = id3_tag_v1_parse(metaID, &phandle->inter_info);
            if (META_TAG_ERR_NONE == u8Ret && 
                META_TAG_FMT_OTHER == phandle->format)
            {
                phandle->format = META_TAG_FMT_IDV3_1;
            }
        }
        if (META_TAG_ERR_NOT_SUPPORT != u8Ret &&
            META_TAG_ERR_NONE != u8Ret)
        {
            META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, u8Ret);

            return  u8Ret;
        }
    }   
#endif  /*#if defined (__TAG_SUPPORT_ID3V1__)*/
    tag_check_text_attrs(phandle);
    tag_check_integer_attrs(phandle);

    phandle->flags |= META_TAG_HAS_PARSED;
    if (phandle->attr_support != 0)
    {
        phandle->flags |= META_TAG_HAS_MUSIC;
    }
    return  META_TAG_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  tag_start_parser
 * DESCRIPTION
 *  start parser meta data
 * PARAMETERS
 *  phandle         [IN]    meta parser handle
 * RETURNS
 *  kal_uint8, success return META_TAG_ERR_NONE
 *****************************************************************************/
static  void tag_check_text_attrs(meta_tag_handle_struct* phandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   i;    
    kal_uint32  attrs[META_TAG_FRAME_TXT_TOTAL] = 
    {
        META_TAG_ATTR_ARTIST,
        META_TAG_ATTR_AUTHOR,
        META_TAG_ATTR_ALBUM, 
        META_TAG_ATTR_TITLE,
        META_TAG_ATTR_COPYRIGHT,
        META_TAG_ATTR_GENRE,
        META_TAG_ATTR_DESCRIPTION,
    };
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phandle->attr_support = 0;

    for (i = 0; i < META_TAG_FRAME_TXT_TOTAL; i++)
    {
        if (NULL == phandle->inter_info.music_info.txt_frame[i].data)
        {
            continue;
        }
        if (0 == phandle->inter_info.music_info.txt_frame[i].data_size)
        {
            continue;
        }        
        phandle->attr_support |= attrs[i];
    }
    if (phandle->inter_info.music_info.year >= 0)
    {
        phandle->attr_support |= META_TAG_ATTR_YEAR;
    }
    if (phandle->inter_info.music_info.track_number > 0)
    {
        phandle->attr_support |= META_TAG_ATTR_TRACKNUM;
    }
	if (phandle->inter_info.music_info.user_rate >= 0)
	{
		phandle->attr_support |= META_TAG_ATTR_RATING;
	}
}


/*****************************************************************************
 * FUNCTION
 *  tag_check_integer_attrs
 * DESCRIPTION
 * Check the integer value is legal
 * PARAMETERS
 *  phandle         [IN]    meta parser handle
 * RETURNS
 *  kal_uint8, success return META_TAG_ERR_NONE
 *****************************************************************************/
static  void tag_check_integer_attrs(meta_tag_handle_struct* phandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (phandle->inter_info.music_info.track_count > META_TAG_MAX_TRACK)
    {
        phandle->inter_info.music_info.track_count = META_TAG_MAX_TRACK;
    }
    if (phandle->inter_info.music_info.track_number > META_TAG_MAX_TRACK)
    {
        phandle->inter_info.music_info.track_number = META_TAG_MAX_TRACK;
    }
    if (phandle->inter_info.music_info.year > META_TAG_MAX_YEAR)
    {
        phandle->inter_info.music_info.year = -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  tag_getbuffer
 * DESCRIPTION
 *  get buffer for saving MATA data
 * PARAMETERS
 *  phandle         [IN]    meta handle ID
 *  buffersize      [IN]    buffer size
 * RETURNS
 *  kal_uint8*, return allocate buffer address
 *****************************************************************************/
static  kal_uint8* tag_getbuffer(kal_uint32 metaID, kal_uint32 buffersize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    meta_tag_handle_struct* phandle;
    kal_uint8* pBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    phandle = (meta_tag_handle_struct*)metaID;
    if (phandle->buffer_size < phandle->buffer_offset+buffersize)
    {
        /*error trace*/
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, buffersize);
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, phandle->buffer_size);
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, phandle->buffer_offset);

        return  NULL;
    }
    pBuffer = phandle->buffer_p+phandle->buffer_offset;
    phandle->buffer_offset += buffersize;

    return  pBuffer;
}


/*****************************************************************************
 * FUNCTION
 *  tag_file_read
 * DESCRIPTION
 *  read MATA data from file
 * PARAMETERS
 *  phandle         [IN]    meta handle ID
 *  buffer          [IN]    buffer for store reading data
 *  readsize        [IN]    need reading size
 * RETURNS
 *  kal_uint32, return real readed data size
 *****************************************************************************/
static  kal_uint32 tag_file_read(
                    kal_uint32 metaID, 
                    kal_uint8* buffer, 
                    kal_uint32 readsize
                    )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    meta_tag_handle_struct* phandle;
    kal_uint32 nRead;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    
    phandle = (meta_tag_handle_struct*)metaID;
#if defined (__DRM_SUPPORT__)
    if (FS_NO_ERROR == 
        DRM_read_file(phandle->file_handle, buffer, readsize, &nRead))
#else
    if (FS_NO_ERROR == 
        FS_Read(phandle->file_handle, buffer, readsize, &nRead))
#endif
    {
        return  nRead;
    }
    META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, phandle->file_handle);

    return  0;
}


/*****************************************************************************
 * FUNCTION
 *  tag_file_seek
 * DESCRIPTION
 *  seek MATA data from file
 * PARAMETERS
 *  phandle         [IN]    meta handle ID
 *  offset          [IN]    seek offset
 *  seekpos         [IN]    seek from
 * RETURNS
 *  kal_uint32, return real readed data size
 *****************************************************************************/
static  kal_int32 tag_file_seek(
                    kal_uint32 metaID, 
                    kal_int32 offset, 
                    kal_uint8 seekpos
                    )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    meta_tag_handle_struct* phandle;
    kal_int32 seekret;
    kal_uint8  seekfrom[FUNC_SEEK_TOTAL] = 
    {
        FS_FILE_BEGIN,
        FS_FILE_CURRENT,
        FS_FILE_END
    };
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    
    phandle = (meta_tag_handle_struct*)metaID;
#if defined (__DRM_SUPPORT__)
    seekret = DRM_seek_file(phandle->file_handle, offset, seekfrom[seekpos]);
#else
    seekret = FS_Seek(phandle->file_handle, offset, seekfrom[seekpos]);
#endif

    return  seekret;
}

/*****************************************************************************
 * FUNCTION
 *  tag_file_write
 * DESCRIPTION
 *  seek MATA data from file
 * PARAMETERS
 *  phandle         [IN]    meta handle ID
 *  offset          [IN]    seek offset
 *  seekpos         [IN]    seek from
 * RETURNS
 *  kal_uint32, return real readed data size
 *****************************************************************************/
static  kal_uint32 tag_file_write(
                    kal_uint32 metaID, 
                    kal_uint8* buffer, 
                    kal_uint32 writesize
                    )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    meta_tag_handle_struct* phandle;
    kal_uint32 nWrite;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    
    phandle = (meta_tag_handle_struct*)metaID;
    if (FS_NO_ERROR == 
        FS_Write(phandle->file_handle, buffer, writesize, &nWrite))
    {
        return  nWrite;
    }
    META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, phandle->file_handle);

    return  0;
}


/*****************************************************************************
 * FUNCTION
 *  tag_file_getlocation
 * DESCRIPTION
 *  get MATA data reading file position
 * PARAMETERS
 *  phandle         [IN]    meta handle ID
 * RETURNS
 *  kal_uint32, return real readed data size
 *****************************************************************************/
static  kal_int32 tag_file_getlocation(kal_uint32 metaID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    meta_tag_handle_struct* phandle;
    kal_int32 s32Ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    
    phandle = (meta_tag_handle_struct*)metaID;
#if defined (__DRM_SUPPORT__)
    if (FS_NO_ERROR != 
        DRM_file_pos(phandle->file_handle, (kal_uint32*)&s32Ret))
#else
    if (FS_NO_ERROR != 
        FS_GetFilePosition(phandle->file_handle, (UINT*)&s32Ret))    
#endif
    {
        s32Ret = -1;

        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, phandle->file_handle);
    }
    return  s32Ret;
}

/*****************************************************************************
 * FUNCTION
 *  tag_file_commit
 * DESCRIPTION
 *  get MATA data reading file position
 * PARAMETERS
 *  phandle         [IN]    meta handle ID
 * RETURNS
 *  kal_uint32, return real readed data size
 *****************************************************************************/
static  kal_int32 tag_file_commit(kal_uint32 metaID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    meta_tag_handle_struct* phandle;
    kal_int32 s32Ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    
    phandle = (meta_tag_handle_struct*)metaID;
    if (FS_NO_ERROR != FS_Commit(phandle->file_handle))    
    {
        s32Ret = -1;
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, phandle->file_handle);
    }
    return  s32Ret;
}

#if defined (__TAG_SUPPORT_APE__)
/*****************************************************************************
 * FUNCTION
 *  tag_has_ape
 * DESCRIPTION
 *  whether the input data has ape tag
 * PARAMETERS
 *  phandle         [IN]    meta parser handle
 *  pPos            [OUT]   return ape start pos
 * RETURNS
 *  if success return META_TAG_ERR_NONE
 *****************************************************************************/
static  kal_uint8 tag_has_ape(
                    meta_tag_handle_struct* phandle, 
                    kal_int32* pPos, 
                    kal_uint8* pFrom
                    )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  metaID, readret;
    kal_int32   seeksize, seekret;
    kal_uint8   buffer[APE_TAG_MAGIC_SIZE], u8Tmp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    metaID = (kal_uint32)phandle;

    if (META_TAG_ERR_NONE == tag_has_id3v1(phandle, &seekret, &u8Tmp))
    {
        seeksize = 0-(APE_TAG_FOOTER_SIZE+ID3_TAG_V1_SIZE);        
    }
    else
    {
        seeksize = 0-APE_TAG_FOOTER_SIZE;
    }
    seekret = phandle->inter_info.func_p->tag_seek(
        metaID, seeksize, FUNC_SEEK_END);
    if (seekret < 0)
    {
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, seekret);

        return  META_TAG_ERR_INVAILD_DATA;
    }
    readret = phandle->inter_info.func_p->tag_read(
        metaID, buffer, APE_TAG_MAGIC_SIZE);
    if (readret != APE_TAG_MAGIC_SIZE)
    {
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, readret);

        return  META_TAG_ERR_INVAILD_DATA;
    }
    if (0 == kal_mem_cmp(buffer, APE_TAG_MAGIC_ID, APE_TAG_MAGIC_SIZE))
    {
        *pPos   = seeksize;
        *pFrom  = FUNC_SEEK_END;

        return  META_TAG_ERR_NONE;
    }
    return  META_TAG_ERR_NOT_SUPPORT;
}
#endif  /*#if defined (__TAG_SUPPORT_APE__)*/


#if defined (__TAG_SUPPORT_ID3V2__)
/*****************************************************************************
 * FUNCTION
 *  tag_has_id3v2
 * DESCRIPTION
 *  whether the input data has idv3 v2.2~v2.4 tag
 * PARAMETERS
 *  phandle         [IN]    meta parser handle
 * RETURNS
 *  if success return META_TAG_ERR_NONE
 *****************************************************************************/
static  kal_uint8 tag_has_id3v2(
                    meta_tag_handle_struct* phandle, 
                    kal_int32* pPos, 
                    kal_uint8* pFrom
                    )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32  metaID, readret;
    kal_int32   seekret;
    kal_uint8   buffer[ID3_TAG_V2_MAGIC_SIZE];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    metaID = (kal_uint32)phandle;    
   
    seekret = phandle->inter_info.func_p->tag_seek(metaID, 0, FUNC_SEEK_SET);
    if (seekret < 0)
    {
        return  META_TAG_ERR_INVAILD_DATA;
    }
    readret = phandle->inter_info.func_p->tag_read(
        metaID, buffer, ID3_TAG_V2_MAGIC_SIZE);
    if (readret != ID3_TAG_V2_MAGIC_SIZE)
    {
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, readret);

        return  META_TAG_ERR_INVAILD_DATA;
    }
    if (0 == kal_mem_cmp(buffer, ID3_TAG_V2_MAGIC_ID, ID3_TAG_V2_MAGIC_SIZE))
    {
        *pPos   = 0;
        *pFrom  = FUNC_SEEK_SET;

        return  META_TAG_ERR_NONE;
    }
    return  META_TAG_ERR_NOT_SUPPORT;
}
#endif  /*#if defined (__TAG_SUPPORT_ID3V2__)*/


#if defined (__TAG_SUPPORT_ID3V1__) || defined (__TAG_SUPPORT_APE__)
/*****************************************************************************
 * FUNCTION
 *  tag_has_id3v1
 * DESCRIPTION
 *  whether the input data has idv1 tag
 * PARAMETERS
 *  phandle         [IN]    meta parser handle
 * RETURNS
 *  if success return META_TAG_ERR_NONE
 *****************************************************************************/
static  kal_uint8 tag_has_id3v1(
                    meta_tag_handle_struct* phandle, 
                    kal_int32* pPos, 
                    kal_uint8* pFrom
                    )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 metaID, readret;
    kal_int32 seekret;
    kal_uint8  buffer[ID3_TAG_V1_MAGIC_SIZE];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    metaID = (kal_uint32)phandle;    
    
    seekret = phandle->inter_info.func_p->tag_seek(
        metaID, 0-ID3_TAG_V1_SIZE, FUNC_SEEK_END);
    if (seekret < 0)
    {
        return  META_TAG_ERR_INVAILD_DATA;
    }
    readret = phandle->inter_info.func_p->tag_read(
        metaID, buffer, ID3_TAG_V1_MAGIC_SIZE);
    if (readret != ID3_TAG_V1_MAGIC_SIZE)
    {
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, readret);

        return  META_TAG_ERR_INVAILD_DATA;
    }
    if (0 == kal_mem_cmp(buffer, ID3_TAG_V1_MAGIC_ID, ID3_TAG_V1_MAGIC_SIZE))
    {
        *pPos   = 0-ID3_TAG_V1_SIZE;
        *pFrom  = FUNC_SEEK_END;

        return  META_TAG_ERR_NONE;
    }
    return  META_TAG_ERR_NOT_SUPPORT;
}
#endif  /*defined (__TAG_SUPPORT_ID3V1__) || defined (__TAG_SUPPORT_APE__)*/


#if defined (__TAG_SUPPORT_DCF__)
/*****************************************************************************
 * FUNCTION
 *  tag_get_meta_from_dcf_file
 * DESCRIPTION
 *  get meta data from drm header
 * PARAMETERS
 *  phandle         [IN]    meta parser handle
 * RETURNS
 *  void
 *****************************************************************************/
static  void    tag_get_meta_from_dcf_file(meta_tag_handle_struct* phandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   nSize, i, nRet, nBuffer;
    kal_uint8*  pBuffer;
    kal_uint8   metatmp[META_TAG_DCF_FRAME_MAX_SIZE+1];/*add 1 bytes for padding zero*/

    meta_tag_dcf_map_struct  meta_tag[META_TAG_DCF_ATTR_NUMBER] = 
    {
        {DRM_META_CONTENT_NAME,         META_TAG_FRAME_TITLE},
        {DRM_META_CONTENT_DESCRIPTION,  META_TAG_FRAME_DESCRIPTION},
        {DRM_META_CONTENT_VENDOR,       META_TAG_FRAME_AUTHOR},
        {DRM_META_COPYRIGHT,            META_TAG_FRAME_COPYRIGHT}        
    };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    for (i = 0; i < META_TAG_DCF_ATTR_NUMBER; i++)
    {
        nSize = DRM_get_meta_size(phandle->file_handle, (drm_meta_enum)meta_tag[i].dcf_attr);
        
        if (0 >= nSize)
        {
            continue;
        }
        if (nSize > META_TAG_DCF_FRAME_MAX_SIZE)
        {
            nSize = META_TAG_DCF_FRAME_MAX_SIZE;
        }

        nRet = DRM_get_meta_data(phandle->file_handle, (drm_meta_enum)meta_tag[i].dcf_attr, 
            (kal_char*)metatmp, nSize);
        if (0 > nRet)
        {
            META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, nRet);
            break;
        }
        metatmp[nSize] = 0;

        pBuffer = phandle->buffer_p+phandle->buffer_offset;
        nBuffer = phandle->buffer_size-phandle->buffer_offset;

        nSize   = mmi_chset_convert(CHSET_UTF8, CHSET_UCS2, (char*)metatmp, 
            (char*)pBuffer, (kal_int32)nBuffer);        
        if (nSize > META_TAG_FRAME_MAX_SIZE)
        {
            nSize = META_TAG_FRAME_MAX_SIZE;
        }
        phandle->buffer_offset += nSize;
        phandle->inter_info.music_info.txt_frame[meta_tag[i].tag_attr].data = 
            (kal_uint16*)pBuffer;
        phandle->inter_info.music_info.txt_frame[meta_tag[i].tag_attr].data_size = 
            nSize;
        phandle->inter_info.music_info.txt_frame[meta_tag[i].tag_attr].data_encoding = 
            META_TAG_TEXT_ENCODING_UCS2;
        if (phandle->buffer_offset >= phandle->buffer_size)
        {
            break;
        }
    }
    phandle->flags |= META_TAG_HAS_PARSED;
    phandle->format = META_TAG_FMT_DCF;   
    
    tag_check_text_attrs(phandle);
    tag_check_integer_attrs(phandle);
    if (phandle->attr_support != 0)
    {
        phandle->flags |= META_TAG_HAS_MUSIC;
    }
}
#endif  /*__TAG_SUPPORT_DCF__*/


#if defined (__TAG_SUPPORT_DRIVER__)
/*****************************************************************************
 * FUNCTION
 *  tag_get_meta_from_audio_driver
 * DESCRIPTION
 *  get meta data from AUDIO DRIVER
 * PARAMETERS
 *  phandle         [IN]    meta parser handle
 * RETURNS
 *  void
 *****************************************************************************/
static kal_uint8 tag_get_meta_from_audio_driver(meta_tag_handle_struct* phandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    meta_tag_txt_frame_struct*  ptxt;
    audInfoStruct*  pGet;
    STFSAL          fs_handle;
    kal_int32       s32Tmp;

    Media_Status(*get_aud_info_f)(STFSAL*pstFSAL, audInfoStruct*contentInfo, 
        void *param) = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (phandle->buffer_size < sizeof(audInfoStruct))
    {
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, phandle->buffer_size);

        return  META_TAG_ERR_NOT_ENOUGH_BUFFER;
    }
    pGet = (audInfoStruct*)phandle->buffer_p;
    kal_mem_set(pGet, 0, sizeof(audInfoStruct));

    switch(phandle->file_format)
    {
#ifdef AMR_DECODE
    case MED_TYPE_AMR:
    case MED_TYPE_AMR_WB:
        get_aud_info_f  = AMR_GetContentDescInfo;
        break;
#endif /* AMR_DECODE */
#ifdef WAV_CODEC
    case MED_TYPE_WAV:
    case MED_TYPE_WAV_DVI_ADPCM:

        get_aud_info_f  = WAV_GetContentDescInfo;
        break;
    case MED_TYPE_PCM_8K:
    case MED_TYPE_PCM_16K:

        get_aud_info_f  = PCM_GetContentDescInfo;
        break;
#endif /*WAV_CODEC*/
    /*has no compile option for this type*/
#ifdef __VM_CODEC_SUPPORT__     
    case MED_TYPE_GSM_EFR:

        get_aud_info_f  = VM_GetContentDescInfo;
        break;
#endif /* __VM_CODEC_SUPPORT__ */
#ifdef AIFF_DECODE
    case MED_TYPE_AIFF:

        get_aud_info_f  = AIFF_GetContentDescInfo;
        break;
#endif /* AIFF_DECODE */
#ifdef AU_DECODE
    case MED_TYPE_AU:

        get_aud_info_f  = AU_GetContentDescInfo;
        break;
#endif /* AU_DECODE */
#if defined(DAF_DECODE)
    case MED_TYPE_DAF:
    #ifdef MUSICAM_DECODE
    case MED_TYPE_MUSICAM:
    #endif

        get_aud_info_f  = DAF_GetContentDescInfo;
        break;
#endif /*defined(DAF_DECODE)*/
#if defined(AAC_DECODE)    
    case MED_TYPE_AAC:
    case MED_TYPE_BSAC:

        get_aud_info_f  = AAC_GetContentDescInfo;
        break;
#endif /*defined(AAC_DECODE)*/
#if defined(M4A_DECODE) 
    case MED_TYPE_M4A:
        
        get_aud_info_f  = MP4S_GetContentDescInfo;
        phandle->format = META_TAG_FMT_UDTA;
        break;
#endif /*defined(M4A_DECODE)*/
#if defined(WMA_DECODE)
    case MED_TYPE_WMA:    

        get_aud_info_f  = WMA_GetContentDescInfo;
        phandle->format = META_TAG_FMT_WM;
        break;   
#endif /*defined(WMA_DECODE)*/

#if defined(MED_PURE_AUDIO)
    case MED_TYPE_MP4:    
    case MED_TYPE_3GP:    

        get_aud_info_f  = MP4S_GetContentDescInfo;
        phandle->format = META_TAG_FMT_UDTA;
        break;
#endif /* MED_PURE_AUDIO || MP4_DECODE */
#if defined(__APE_DECODE__)
    case MED_TYPE_APE:

        get_aud_info_f = APE_GetContentDescInfo;
        break;
#endif /*defined(__APE_DECODE__)*/
#ifdef __VORBIS_DECODE__
    case MED_TYPE_VORBIS:

        get_aud_info_f = VORBIS_GetContentDescInfo;
        break;
#endif
#ifdef __FLAC_DECODE__
    case MED_TYPE_FLAC:

        get_aud_info_f = FLAC_GetContentDescInfo;
        break;
#endif


/* only suuport for PlutoMMI */ 
#ifndef __MED_IN_ASM__
#ifdef __FLV_FILE_FORMAT_SUPPORT__
    case MED_TYPE_FLV:
    case MED_TYPE_F4V:
    case MED_TYPE_F4A:
        get_aud_info_f = FLV_GetContentDescInfo;
        break;
#endif /*__FLV_FILE_FORMAT_SUPPORT__*/
    
#ifdef __RM_DEC_SUPPORT__
    case MED_TYPE_RMVB:
    case MED_TYPE_RM:
    case MED_TYPE_RA:
    case MED_TYPE_RV:
        get_aud_info_f = RM_GetContentDescInfo;
        break;
#endif /*__RM_DEC_SUPPORT__*/
#endif /* __MED_IN_ASM__ */

    default:    
        /*
        *   no use to get amr/wav/vm file header information
        */
        return  META_TAG_ERR_NOT_SUPPORT;
    }

    if (FSAL_Open_WithHandle(&fs_handle, (void*)phandle->file_handle) != FSAL_OK)
    {        
        /*
        *   error trace
        */
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, phandle->file_handle);

        return  META_TAG_ERR_OPEN_FILE_FAILED;
    }
    
    s32Tmp = get_aud_info_f(&fs_handle, pGet, NULL);    
    if (MEDIA_SUCCESS != s32Tmp)
    {
        META_TAG_ERR_TRACE(FILE_ID_META_TAG_API, s32Tmp);
        /*
        *   error trace
        */
        return  META_TAG_ERR_INVAILD_DATA;
    }
    phandle->inter_info.audio_info.bits_rate    = pGet->bitRate;
    phandle->inter_info.audio_info.channel_number = (pGet->stereo?2:1);
    phandle->inter_info.audio_info.duration     = (pGet->time/1000);
    phandle->inter_info.audio_info.sample_rate  = pGet->sampleRate;
    phandle->flags |= META_TAG_HAS_AUDIO;

    phandle->flags |= META_TAG_HAS_PARSED;

    switch(phandle->file_format)
    {
#if defined(DAF_DECODE) || defined(AAC_DECODE)     
#if defined(DAF_DECODE)
    case MED_TYPE_DAF:
    #ifdef MUSICAM_DECODE
    case MED_TYPE_MUSICAM:
    #endif
#endif
#if defined(AAC_DECODE)    
    case MED_TYPE_AAC:
    case MED_TYPE_BSAC:
#endif
#if defined(__APE_DECODE__)    
    case MED_TYPE_APE:
#endif
       
        return  META_TAG_ERR_NONE;
#endif
    default:
        break;
    }

    phandle->inter_info.music_info.bits_rate    = (kal_int32)pGet->bitRate;
    phandle->inter_info.music_info.duration     = 
        (kal_int32)phandle->inter_info.audio_info.duration; 
	if ((kal_int32)pGet->trackNum > 0)
	{
		phandle->inter_info.music_info.track_number = (kal_int32)pGet->trackNum;
	}    

	s32Tmp = app_ucs2_strlen((kal_int8*)pGet->date);
	if (0 == meta_tag_is_empty_ucs2_item((kal_uint16*)pGet->date, s32Tmp))
	{
	    if ((kal_uint16)pGet->date[0] >= L'0' && (kal_uint16)pGet->date[0] <= '9')
        {
            phandle->inter_info.music_info.year = 
        	    (kal_int32)app_ucs2_atoi((const kal_int8*)pGet->date);
        }    	
	}

    ptxt = phandle->inter_info.music_info.txt_frame;    
    s32Tmp = app_ucs2_strlen((kal_int8*)pGet->artist);

    if (0 == meta_tag_is_empty_ucs2_item((kal_uint16*)pGet->artist, s32Tmp))
    {
        ptxt[META_TAG_FRAME_ARTIST].data        = pGet->artist;
        ptxt[META_TAG_FRAME_ARTIST].data_size   = 
            s32Tmp*META_TAG_TEXT_ENCODE_LEN;
        ptxt[META_TAG_FRAME_ARTIST].data_encoding = META_TAG_TEXT_ENCODING_UCS2;
    }

    s32Tmp = app_ucs2_strlen((kal_int8*)pGet->title);
    if (0 == meta_tag_is_empty_ucs2_item((kal_uint16*)pGet->title, s32Tmp))
    {
        ptxt[META_TAG_FRAME_TITLE].data        = pGet->title;
        ptxt[META_TAG_FRAME_TITLE].data_size   = 
            s32Tmp*META_TAG_TEXT_ENCODE_LEN;
        ptxt[META_TAG_FRAME_TITLE].data_encoding = META_TAG_TEXT_ENCODING_UCS2;
    }

    s32Tmp = app_ucs2_strlen((kal_int8*)pGet->album);
    if (0 == meta_tag_is_empty_ucs2_item((kal_uint16*)pGet->album, s32Tmp))
    {
        ptxt[META_TAG_FRAME_ALBUM].data        = pGet->album;
        ptxt[META_TAG_FRAME_ALBUM].data_size   = 
            s32Tmp*META_TAG_TEXT_ENCODE_LEN;
        ptxt[META_TAG_FRAME_ALBUM].data_encoding = META_TAG_TEXT_ENCODING_UCS2;
    }

    s32Tmp = app_ucs2_strlen((kal_int8*)pGet->copyright);
    if (0 == meta_tag_is_empty_ucs2_item((kal_uint16*)pGet->copyright, s32Tmp))
    {
        ptxt[META_TAG_FRAME_COPYRIGHT].data        = pGet->copyright;
        ptxt[META_TAG_FRAME_COPYRIGHT].data_size   = 
            s32Tmp*META_TAG_TEXT_ENCODE_LEN;
        ptxt[META_TAG_FRAME_COPYRIGHT].data_encoding = META_TAG_TEXT_ENCODING_UCS2;
    }

    s32Tmp = app_ucs2_strlen((kal_int8*)pGet->author);
    if (0 == meta_tag_is_empty_ucs2_item((kal_uint16*)pGet->author, s32Tmp))
    {
        ptxt[META_TAG_FRAME_AUTHOR].data        = pGet->author;
        ptxt[META_TAG_FRAME_AUTHOR].data_size   = 
            s32Tmp*META_TAG_TEXT_ENCODE_LEN;
        ptxt[META_TAG_FRAME_AUTHOR].data_encoding = META_TAG_TEXT_ENCODING_UCS2;
    }
    s32Tmp = app_ucs2_strlen((kal_int8*)pGet->genre);
    if (0 == meta_tag_is_empty_ucs2_item((kal_uint16*)pGet->genre, s32Tmp))
    {
        ptxt[META_TAG_FRAME_GENRE].data        = pGet->genre;
        ptxt[META_TAG_FRAME_GENRE].data_size   = 
            s32Tmp*META_TAG_TEXT_ENCODE_LEN;
        ptxt[META_TAG_FRAME_GENRE].data_encoding = META_TAG_TEXT_ENCODING_UCS2;
    }
    /*MAUI_01882574, add description tag for wma*/
    s32Tmp = app_ucs2_strlen((kal_int8*)pGet->comment);
    if (0 == meta_tag_is_empty_ucs2_item((kal_uint16*)pGet->comment, s32Tmp))
    {
        ptxt[META_TAG_FRAME_DESCRIPTION].data        = pGet->comment;
        ptxt[META_TAG_FRAME_DESCRIPTION].data_size   = 
            s32Tmp*META_TAG_TEXT_ENCODE_LEN;
        ptxt[META_TAG_FRAME_DESCRIPTION].data_encoding = META_TAG_TEXT_ENCODING_UCS2;
    }

    tag_check_integer_attrs(phandle);
    tag_check_text_attrs(phandle);
    
    if (phandle->attr_support != 0)
    {
        phandle->flags |= META_TAG_HAS_MUSIC;
    }    
    return  META_TAG_ERR_NONE;
}
#endif  /*#if defined (__TAG_SUPPORT_DRIVER__)*/

/* For FTE 3.0 audio layer widget*/

kal_eventgrpid meta_tag_event;
kal_bool meta_parser_cancel_flag; 

void meta_parser_send_ilm(module_type dest_id, kal_uint16 msg_id, void *local_param_ptr)
{
    ilm_struct *ilm_ptr = NULL;
    module_type src_id = kal_get_active_module_id();

    ilm_ptr = allocate_ilm(src_id);
    ilm_ptr->src_mod_id = src_id;
    ilm_ptr->dest_mod_id = dest_id;
    ilm_ptr->sap_id = (dest_id == MOD_MED_V) ? MED_V_SAP : MMI_MMI_SAP;
    ilm_ptr->msg_id = (msg_type) msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;

    msg_send_ext_queue(ilm_ptr);
}

/* Run in MED_V */

kal_uint8 meta_parser_file_parse_callback(kal_uint32 seqID, kal_uint32 metaID, 
                                          kal_uint8 result, kal_uint8 *imgBuf, kal_uint32 bufSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_meta_tag_parse_cnf_struct *rsp_p;
    meta_tag_music_info_struct *music_info;
    meta_tag_audio_info_struct *audio_info;
    meta_tag_img_info_struct   *cover_info;
    kal_uint8 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    META_TAG_MSG_TRACE(FILE_ID_META_TAG_API_ASYNC, meta_parser_cancel_flag);

    rsp_p = (media_meta_tag_parse_cnf_struct*) 
                construct_local_para(sizeof(media_meta_tag_parse_cnf_struct), TD_CTRL);
    rsp_p->seqID = seqID;
    rsp_p->type = META_TAG_ASYNC_TYPE_PARSE;
    rsp_p->result = result;
    if (META_TAG_ERR_NONE == result)
    {
        ret = meta_get_music_info(metaID, &music_info);
        if (META_TAG_ERR_NONE == ret)
        {
            rsp_p->music_info = music_info;
        }
        else
        {
            rsp_p->music_info = NULL;
        }
        ret = meta_get_audio_info(metaID, &audio_info);
        if (META_TAG_ERR_NONE == ret)
        {
            rsp_p->audio_info = audio_info;
        }
        else
        {
            rsp_p->audio_info = NULL;
        }
        ret = meta_get_attach_cover_info(metaID, &cover_info);
        if ((META_TAG_ERR_NONE == ret) && (bufSize >= cover_info->data_size) && (cover_info->data_size > 0))
        {
            rsp_p->has_image = KAL_TRUE;
            rsp_p->cover_info = cover_info;
            ret = meta_get_attach_cover_data(metaID, imgBuf, bufSize);
        }
        else
        {
            rsp_p->has_image = KAL_FALSE;
            rsp_p->cover_info = NULL;
        }
    }
    //already cancel
    if (meta_parser_cancel_flag)
    {
        return META_TAG_ERR_HAS_CANELED;
    }
    meta_parser_send_ilm(MOD_MMI, MSG_ID_MEDIA_META_PARSE_CNF, rsp_p);

    return META_TAG_ERR_NONE;
}


void meta_parser_file_parse_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_meta_tag_parse_req_struct *req_p = (media_meta_tag_parse_req_struct*)ilm_ptr->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    META_TAG_MSG_TRACE(FILE_ID_META_TAG_API_ASYNC, req_p->type);
    META_TAG_MSG_TRACE(FILE_ID_META_TAG_API_ASYNC, meta_parser_cancel_flag);
    
    if(META_TAG_ASYNC_TYPE_PARSE == req_p->type)
    {
        kal_uint8 ret;

        META_SET_EVENT(META_TAG_EVT_PARSE);
        //already cancel
        if (meta_parser_cancel_flag)
        {
            return;
        }
        ret = meta_parse_file(req_p->metaID, req_p->filePath);
        //already cancel
        if (meta_parser_cancel_flag)
        {
            return;
        }
        meta_parser_file_parse_callback(req_p->seqID, req_p->metaID, ret, req_p->imgBuf, req_p->imgBufSize);
    }
    else
    {
        media_meta_tag_parse_cnf_struct *rsp_p;
        
        META_SET_EVENT(META_TAG_EVT_CANCEL);

        rsp_p = (media_meta_tag_parse_cnf_struct*) 
                construct_local_para(sizeof(media_meta_tag_parse_cnf_struct), TD_CTRL);
        rsp_p->seqID = req_p->seqID; 
        rsp_p->type  = META_TAG_ASYNC_TYPE_CANCEL;

        meta_parser_send_ilm(MOD_MMI, MSG_ID_MEDIA_META_PARSE_CNF, rsp_p);
    }
}
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

#endif  /*#if defined(__META_DATA_PARSE_API__)*/
