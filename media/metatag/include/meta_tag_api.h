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
*   meta_tag_api.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   meta tag parsing definitions, compile option define in med_global.h
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
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef __META_TAG_API_H__
#define __META_TAG_API_H__

//#include "Conversions.h"
//#include "L1audio.h"
#include "med_global.h"
#include "kal_general_types.h"

#if defined(__META_DATA_PARSE_API__)

/* Meta parser return enum value */
typedef enum
{
    META_TAG_ERR_NONE = 0,          /* No error */      
    META_TAG_ERR_NO_MEMORY,         /* Not enough memory */
    META_TAG_ERR_NO_HANDLE,         /* No valid handler */
    META_TAG_ERR_NO_INPUT,          /* Get meta info without parser file in advance */
    META_TAG_ERR_OPEN_FILE_FAILED,  /* Failed to open file */
    META_TAG_ERR_INVAILD_HANDLE,    /* The passin meta parser handler id is invalid */  
    META_TAG_ERR_INVAILD_DATA,      /* The data in file is invalid */ 
    META_TAG_ERR_NOT_SUPPORT,       /* Meta format is not support */
    META_TAG_ERR_NOT_ENOUGH_BUFFER, /* The buffer size is not enough to store the meta data */
    META_TAG_ERR_NOT_ENOUGH_PADDING,
    META_TAG_ERR_INPUT_PARAM,
    META_TAG_ERR_INVALID_CALL,
    META_TAG_ERR_HAS_CANELED,
    META_TAG_ERR_TOTAL
        
}   meta_tag_error_enum;

/* Meta parser return enum value */
typedef enum
{
    META_TAG_WRITE_ITEM_RATING = 0,          /* No error */      
    META_TAG_WRITE_ITEM_TOTAL        
}   meta_tag_write_item_enum;

/* Meta data text frame type */
typedef enum
{
    META_TAG_FRAME_ARTIST= 0,       /* artist */      
    META_TAG_FRAME_AUTHOR,          /* author */  
    META_TAG_FRAME_ALBUM ,          /* album */  
    META_TAG_FRAME_TITLE ,          /* title */  
    META_TAG_FRAME_COPYRIGHT,       /* copy right */     
    META_TAG_FRAME_GENRE,           /* genre */
    META_TAG_FRAME_DESCRIPTION,     /* description */
    META_TAG_FRAME_TXT_TOTAL

}   meta_tag_txt_frame_enum;

/* Meta data other frame type */
typedef enum
{
    META_TAG_FRAME_YEAR = META_TAG_FRAME_TXT_TOTAL,   /* year */     
    META_TAG_FRAME_TRACKNUM,                          /* track number */
    META_TAG_FRAME_RATING,
    //META_TAG_FRAME_SYNCLYRICS,                        /* lyrics,not support yet */  
    META_TAG_FRAME_PICTURE,                           /* picture */   
    META_TAG_FRAME_DURATION,                          /* duration */   
    META_TAG_FRAME_BITRATE,                           /* bit rate */    
    META_TAG_FRAME_TOTAL

}   meta_tag_frame_enum;

/* Meta format type */
typedef enum
{
    META_TAG_FMT_OTHER  = 0,
    META_TAG_FMT_IDV3_1,            /* id3 version 1 */
    META_TAG_FMT_IDV3_2,            /* id3 version 2.2~2.4 */
    META_TAG_FMT_APE,               /* ape */
    META_TAG_FMT_WM,                /* window media meta format */
    META_TAG_FMT_UDTA,              /* user data box in 3gpp or mp4 files */
    META_TAG_FMT_DCF,               /* user data box in DCF (drm file header) files */
    META_TAG_FMT_TOTAL
        
}   meta_tag_format_enum;

/* lyrics type */
typedef enum
{
    META_TAG_LYC_OTHER = 0,         /* others */
    META_TAG_LYC_LYRIC,             /* Stand lyrics */
    META_TAG_LYC_TXT,               /* lyrics */
    META_TAG_LYC_URL_WAP,           /* url to WAP */
    
    META_TAG_LYC_TOTAL

}   meta_tag_lyc_type_enum;

/* imgae type */
typedef enum
{
    META_TAG_IMG_PNG = 0,           /* png */
    META_TAG_IMG_JPG,               /* jpg */
    META_TAG_IMG_JPEG,              /* JPEG */    
    META_TAG_IMG_GIF,               /* gif */
    META_TAG_IMG_BMP,               /* BMP */
    META_TAG_IMG_URL_WAP,           /*url to WAP*/
    
    META_TAG_IMG_TOTAL

}   meta_tag_img_type_enum;

/* time stemp type  */
typedef enum
{
    META_TAG_TIMESTAMP_MS = 0,      /*milliseconds*/
    META_TAG_TIMESTAMP_FC,          /*frames count*/
    META_TAG_TIMESTAMP_TOTAL
        
}   meta_tag_time_stamp_enum;

/* Encoding type */
typedef enum
{
    META_TAG_TEXT_ENCODING_ISO_8859_1 = 0,      /* ISO-8859 */
    META_TAG_TEXT_ENCODING_UTF16,               /* UTF-16 */
    META_TAG_TEXT_ENCODING_UTF16_BE,            /* UTF-16 BE */
    META_TAG_TEXT_ENCODING_UTF8,                /* UTF-8 */
    META_TAG_TEXT_ENCODING_UCS2,                /* UCSII */
    META_TAG_TEXT_ENCODING_UNKNOWN,             /* unknow */
    META_TAG_TEXT_ENCODING_TOTAL
        
}   meta_tag_frame_text_encoding_enum;

typedef enum
{
    META_TAG_ASYNC_TYPE_PARSE,
    META_TAG_ASYNC_TYPE_CANCEL,
    META_TAG_ASYNC_TYPE_TOTAL
}   meta_tag_async_type_enum;

/* Meta data encoding length */
#define META_TAG_TEXT_ENCODE_LEN    2
/* Meta data max frame length */
#define META_TAG_FRAME_MAX_LEN      81
/* Meta data max frame buffer size  */
#define META_TAG_FRAME_MAX_SIZE     (META_TAG_FRAME_MAX_LEN*META_TAG_TEXT_ENCODE_LEN)

#if defined (__META_DATA_PARSE_SUPPORT_DRIVER__)
#define META_TAG_PARSE_MIN_SIZE     sizeof(audInfoStruct)
#else
#define META_TAG_PARSE_MIN_SIZE     (META_TAG_FRAME_MAX_SIZE*META_TAG_FRAME_TXT_TOTAL)
#endif

/* Meta tag text frame structure */
typedef struct
{
    kal_uint16* data;               /* data pointer,without null terminator */
    kal_uint16  data_size;          /* text data size */
    kal_uint8   data_encoding;      /* text frame data encoding type. defined in meta_tag_frame_text_encoding_enum */
    kal_uint8   reserve;            /* reserve */

}   meta_tag_txt_frame_struct;

/* Image tag data structure */
typedef struct
{
    kal_uint32  frame_location;     /* image frame offset */ 
    kal_uint32  data_size;          /* image data size */
    kal_uint16  data_offset;        /* image data offset */
    kal_uint8   mime_type;          /* image data type, defined in meta_tag_img_type_enum */
    kal_uint8   priority;           /* priority */
    
}   meta_tag_img_info_struct;

/* Lyrics tag data structure */
typedef struct
{
    kal_uint32  frame_location;     /* lryics frame offset */
    kal_uint32  data_size;          /* lyrcis buffer size */
    kal_uint16  data_offset;        /* lyrcis data offset */
    kal_uint8   data_encoding;      /* lyrcis encoding type */
    kal_uint8   lyc_type;           /* lyrics type, defined in meta_tag_lyc_type_enum */
    kal_uint8   time_stamp_fmt;     /* time stamp format, defined in eta_tag_time_stamp_enum */
    
}   meta_tag_sync_lyc_info_struct;

/* Audio related info structure */
typedef struct
{
    kal_uint32  duration;           /* duration in second */
    kal_uint32  bits_rate;          /* bit rate */

    kal_uint16  sample_rate;        /* sample rate */
    kal_uint8   sample_bits;        /* sample bits. can not be parser now */         
    kal_uint8   channel_number;     /* channel number */
    
}   meta_tag_audio_info_struct;

/* Music related info structure */
typedef struct 
{
    meta_tag_txt_frame_struct   txt_frame[META_TAG_FRAME_TXT_TOTAL]; /* text frame data */

    kal_int32   track_number;       /* track number, when tag not support this ATTR, value < 0 */
    kal_int32   track_count;        /* track count, when tag not support this ATTR, value < 0 */ 
    kal_int32   duration;           /* duration, when tag not support this ATTR, value < 0 */ 
    kal_int32   year;               /* year, when tag not support this ATTR, value < 0 */     
    kal_int32   bits_rate;          /* bit rate, when tag not support this ATTR, value < 0 */ 
    kal_int32   user_rate;          /* User rate: 0~255 */
    kal_uint32  play_count;         /* play count */

}   meta_tag_music_info_struct;

typedef struct
{
    meta_tag_music_info_struct *music_info;
    meta_tag_audio_info_struct *audio_info;
    meta_tag_img_info_struct   *cover_info;
    kal_bool has_image;
}   meta_tag_async_info_struct;



typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 seqID;
    kal_uint32 metaID;
    kal_uint32 type;
    kal_uint32 imgBufSize;
    kal_uint8* imgBuf; 
    kal_wchar* filePath;
}
media_meta_tag_parse_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 seqID;
    kal_uint32 type;
    kal_uint32 result;
    meta_tag_music_info_struct *music_info;
    meta_tag_audio_info_struct *audio_info;
    meta_tag_img_info_struct   *cover_info;
    kal_bool has_image;
}
media_meta_tag_parse_cnf_struct;


extern kal_uint8   meta_write_file_info(
                        kal_uint32 metaID,
                        kal_uint16 *filepath, 
                        meta_tag_write_item_enum tagID,
                        kal_uint32 para1, 
                        kal_uint32 para2);

/*****************************************************************************
* FUNCTION
*  meta_parser_create
* DESCRIPTION
*  Create a meta parser handle.
* PARAMETERS
*  buffer : [IN] Buffer for feedback text attributes 
*  buffersize : [IN] buffer size.
*  handle : [OUT] meta parse handle 
* RETURNS
*  error code.
* EXAMPLE
* <code>
*
*  meta_tag_audio_info_struct* audio_info_p = NULL;
*  meta_tag_music_info_struct* music_info_p = NULL;
*
*  UI_string_type file_path = L"C:\test\a.mp3";
*  U8* meta_parser_buf = NULL;
*  U32 meta_parser_hdlr = 0;
*  U8  meta_parser_ret = 0;
*
*  meta_parser_buf = mmi_frm_scrmem_alloc_framebuffer(META_TAG_PARSE_MIN_SIZE);
*  if (NULL != meta_parser_buf)
*  {
*      meta_parser_ret = meta_parser_create(meta_parser_buf, META_TAG_PARSE_MIN_SIZE, &meta_parser_hdlr);        
*      if (META_TAG_ERR_NONE == meta_parser_ret)
*      {
*          meta_parser_ret = meta_parse_file(meta_parser_hdlr, (kal_uint16*)file_path);
*          if (META_TAG_ERR_NONE == meta_parser_ret)
*          {
*              meta_parser_ret = meta_get_music_info(meta_parser_hdlr, &music_info_p);
*              if (META_TAG_ERR_NONE == meta_parser_ret)
*              {
*                  ...
*              }
*              meta_parser_ret = meta_get_audio_info(meta_parser_hdlr, &audio_info_p);
*              if (META_TAG_ERR_NONE == meta_parser_ret)
*              {
*                  ...
*              }
*          }
*          else
*          {
*              ...
*          }
*          meta_parser_release(meta_parser_hdlr);
*      }
*      else
*      {
*          ...
*      }
*      mmi_frm_scrmem_free(meta_parser_buf);
*  }
*
*  
* </code>
*****************************************************************************/
extern kal_uint8  meta_parser_create(kal_uint8* buffer, kal_uint32 buffersize, kal_uint32 *handle);

/*****************************************************************************
* FUNCTION
*  meta_parser_release
* DESCRIPTION
*  Release a meta parser handler by metaID.
* PARAMETERS
*  metaID : [IN] meta parser handle ID. 
* RETURNS
*  If meta parser release fuccessful.
* RETURN VALUES
*  META_TAG_ERR_NONE: Release meta parser hanlder successful.
*  META_TAG_ERR_INVAILD_HANDLE: Can't find meta parser id to release.
* EXAMPLE
*  please refer example in meta_parser_create()
*****************************************************************************/
extern kal_uint8  meta_parser_release(kal_uint32 metaID);

/*****************************************************************************
* FUNCTION
*  meta_parse_file
* DESCRIPTION
*  parse meta data from music file.
* PARAMETERS
*  metaID :   [IN] meta parser handle ID.
*  filepath : [IN] music file path.
* RETURNS
*  Parse meta data result.
* RETURN VALUES
*  META_TAG_ERR_NONE: Prase file successful.
*  Others : Error happed defined in meta_tag_error_enum. 
* EXAMPLE
*  please refer example in meta_parser_create()
*****************************************************************************/
extern kal_uint8  meta_parse_file(kal_uint32 metaID, kal_uint16 *filepath);

/*****************************************************************************
* FUNCTION
*  meta_parse_file_with_encoding_type
* DESCRIPTION
*  parse meta data from music file.
* PARAMETERS
*  metaID :   [IN] meta parser handle ID.
*  filepath : [IN] music file path.
*  preferEncoding : [IN] meta parser will encoding meta data to preferEncoding type.Now only support META_TAG_TEXT_ENCODING_UCS2 and META_TAG_TEXT_ENCODING_UNKNOWN
* RETURNS
*  Parse meta data result.
* RETURN VALUES
*  META_TAG_ERR_NONE: Prase file successful.
*  Others : Error happed defined in meta_tag_error_enum. 
* EXAMPLE
* <code>
* UI_string_type file_path = L"C:\test\a.mp3";
* U8* meta_parser_buf = NULL;
* U32 meta_parser_hdlr = 0;
* U8  meta_parser_ret = 0;
* U8  prefer_encoding = META_TAG_TEXT_ENCODING_UCS2;
* U8  meta_format = META_TAG_FMT_TOTAL;

* meta_parser_buf = mmi_frm_scrmem_alloc_framebuffer(META_TAG_PARSE_MIN_SIZE);
* if (NULL != meta_parser_buf)
* {
*     meta_parser_ret = meta_parse_create(meta_parser_buf, META_TAG_PARSE_MIN_SIZE, meta_parser_hdlr);     
*     if (META_TAG_ERR_NONE == meta_parser_ret)
*     {
*         meta_parser_ret = meta_parse_file_with_encoding_type(meta_parser_hdlr, (kal_uint16*)file_path, prefer_encoding);
*         if (META_TAG_ERR_NONE == meta_parser_ret)
*         {
*             meta_parser_ret = meta_get_format(meta_parser_hdlr, &meta_format);
*             if (META_TAG_ERR_NONE == meta_parser_ret)
*             { ... }
*         }
*         else
*         {
*             ... 
*         }
*         meta_parser_release(meta_parser_hdlr);
*     }
*     else
*     {
*         ...
*     }
*     mmi_frm_scrmem_free(meta_parser_buf);
* }
*     
* </code>
*****************************************************************************/
extern kal_uint8  meta_parse_file_with_encoding_type(
                    kal_uint32 metaID, 
                    kal_uint16 *filepath,
                    kal_uint8  preferEncoding);

/*****************************************************************************
* FUNCTION
*  meta_get_format
* DESCRIPTION
*  get meta tag format.
* PARAMETERS
*  metaID :  [IN] meta parser handle ID.
*  pFormat : [OUT] Meta data format, defined in meta_tag_format_enum. 
* RETURNS
*  get format successful or fail.
* RETURN VALUES
*  META_TAG_ERR_NONE : get format success.
*  META_TAG_ERR_INVAILD_HANDLE  : metaID is invalid.. 
*  META_TAG_ERR_NO_INPUT : havn't parse a file 
* EXAMPLE
*  please refer example in meta_parse_file_with_encoding_type()
*****************************************************************************/
extern kal_uint8  meta_get_format(kal_uint32 metaID, kal_uint8* pFormat);

/*****************************************************************************
* FUNCTION
*  meta_get_audio_info
* DESCRIPTION
*  get meta audio information.
* PARAMETERS
*  metaID : [IN] meta parser handle ID.
*  pGet :   [OUT] the pointer of audio info structure.  
* RETURNS
*  get audio infomation successful or fail.
* RETURN VALUES
*  META_TAG_ERR_NONE : get format success.
*  META_TAG_ERR_INVAILD_HANDLE  : metaID is invalid.. 
*  META_TAG_ERR_NO_INPUT : havn't parse a file 
* EXAMPLE
*  please refer example in meta_parser_create()
*****************************************************************************/
extern kal_uint8  meta_get_audio_info(
                    kal_uint32 metaID, 
                    meta_tag_audio_info_struct** pGet
                    );

/*****************************************************************************
* FUNCTION
*  meta_get_music_info
* DESCRIPTION
*  get meta music information.
* PARAMETERS
*  metaID : [IN] meta parser handle ID.
*  pGet :   [OUT] the pointer of music info structure.   
* RETURNS
*  get music infomation successful or fail.
* RETURN VALUES
*  META_TAG_ERR_NONE : get format success.
*  META_TAG_ERR_INVAILD_HANDLE  : metaID is invalid.. 
*  META_TAG_ERR_NO_INPUT : havn't parse a file 
* EXAMPLE
*  please refer example in meta_parser_create()
*****************************************************************************/
extern kal_uint8  meta_get_music_info(
                    kal_uint32 metaID, 
                    meta_tag_music_info_struct** pGet
                    );

/*****************************************************************************
* FUNCTION
*  meta_get_attach_cover_info
* DESCRIPTION
*  get meta attach cover image information.
* PARAMETERS
*  metaID : [IN] meta parser handle ID.
*  pGet :   [OUT] the pointer of image info structure.    
* RETURNS
*  get cover image infomation successful or fail.
* RETURN VALUES
*  META_TAG_ERR_NONE : get format success.
*  META_TAG_ERR_INVAILD_HANDLE  : metaID is invalid.. 
*  META_TAG_ERR_NO_INPUT : havn't parse a file 
* EXAMPLE
* <code>
* 
* meta_tag_img_info_struct* image_info_p = NULL;
* UI_string_type file_path = L"C:\test\a.mp3";
* U8* meta_parser_buf = NULL;
* U8* buffer = NULL;
* U32 buffer_size;
* U32 meta_parser_hdlr = 0;
* U8  meta_parser_ret = 0;
* 
* meta_parser_buf = mmi_frm_scrmem_alloc_framebuffer(META_TAG_PARSE_MIN_SIZE);
* if (NULL != meta_parser_buf)
* {
*     meta_parser_ret = meta_parser_create(meta_parser_buf, META_TAG_PARSE_MIN_SIZE£¬&meta_parser_hdlr);        
*     if (META_TAG_ERR_NONE == meta_parser_ret)
*     {
*         meta_parser_ret = meta_parse_file(meta_parser_hdlr, (kal_uint16*)file_path);
*         if (META_TAG_ERR_NONE == meta_parser_ret)
*         {
*             meta_parser_ret = meta_get_attach_cover_info(meta_parser_hdlr, &image_info_p);
*             if (META_TAG_ERR_NONE == meta_parser_ret)
*             {
*                 buffer = mmi_frm_scrmem_alloc_framebuffer(GDI_LCD_WIDTH*GDI_LCD_HEIGHT*2);
*                 if (NULL !=  buffer)
*                 {
* 
*                     meta_parser_ret = meta_get_attach_cover_data(
*                                 meta_parser_hdlr, (kal_uint8*)buffer, GDI_LCD_WIDTH*GDI_LCD_HEIGHT*2);
*                     if (META_TAG_ERR_NONE == meta_parser_ret)
*                     { ... }
*                     mmi_frm_scrmem_free(buffer);
*                 }
*                 
*             }
*         }
*         else
*         {
*             ...
*         }
*         meta_parser_release(meta_parser_hdlr);
*     }
*     else
*     {
*         ...
*     }
*     mmi_frm_scrmem_free(meta_parser_buf);
* }

*     
* </code>
*****************************************************************************/
extern kal_uint8  meta_get_attach_cover_info(
                    kal_uint32 metaID, 
                    meta_tag_img_info_struct** pGet
                    );

/*****************************************************************************
* FUNCTION
*  meta_get_attach_cover_data
* DESCRIPTION
*  get attached picture from meta data..
* PARAMETERS
*  metaID : [IN] meta parser handle ID.
*  pBuffer :  [OUT] input buffer for store image data. 
*  BufferSize: [IN] image data buffer size.
* RETURNS
*  get cover image data successful or fail.
* RETURN VALUES
*  META_TAG_ERR_NONE : get format success.
*  Others : Error happed defined in meta_tag_error_enum.  
* EXAMPLE
*  please refer example in meta_get_attach_cover_info()
*****************************************************************************/
extern kal_uint8  meta_get_attach_cover_data(
                    kal_uint32 metaID, 
                    kal_uint8* pBuffer, 
                    kal_uint32 BufferSize
                    );
extern kal_uint8  meta_get_sync_lyrics_info(
                    kal_uint32 metaID, 
                    meta_tag_sync_lyc_info_struct** pGet
                    );
extern kal_uint8  meta_get_sync_lyrics_data(
                    kal_uint32 metaID, 
                    kal_uint8* pBuffer, 
                    kal_uint32 BufferSize
                    );



#define    META_TAG_EVT_PARSE    0x00000001
#define    META_TAG_EVT_CANCEL   0x00000002

#define META_WAIT_EVENT(evt_) do{                                   \
        kal_uint32 retrieved_events;                                \
        META_TAG_MSG_TRACE(0, (evt_));                              \
        kal_retrieve_eg_events(meta_tag_event, (evt_),              \
        KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0)

#define META_SET_EVENT(evt_) do{                                     \
        META_TAG_MSG_TRACE(1, (evt_));                               \
        kal_set_eg_events(meta_tag_event, (evt_),KAL_OR);            \
        } while(0)

extern void meta_parser_send_ilm(module_type dest_id, kal_uint16 msg_id, void *local_param_ptr);
extern void meta_parser_file_parse_hdlr(ilm_struct *ilm_ptr);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#endif /*#if defined(__META_DATA_PARSE_API__)*/
#endif /* __META_TAG_API_H__ */ 

