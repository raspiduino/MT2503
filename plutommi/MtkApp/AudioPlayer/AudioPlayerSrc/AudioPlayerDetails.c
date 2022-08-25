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
*   AudioPlayerDetails.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Audio player's external API which used without audio player compile option.
*
* Author:
* -------
*  
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
*==============================================================================
*******************************************************************************/
#include "MMI_features.h"
#if defined(__MMI_AUDIO_PLAYER__)
#ifdef __MMI_AUDIO_PLAYER_DETAILS_SUPPORT__
#include "Conversions.h"
#include "mdi_datatype.h"
#include "inlinecuigprot.h"

//#if !defined(__LOW_COST_SUPPORT_COMMON__)
#define __MMI_AUDPLY_NEW_META_PARSER__
//#endif
#ifdef __MMI_AUDPLY_NEW_META_PARSER__
#include "meta_tag_parser.h"
#else
#include "aud_daf_parser.h"
#endif

#include "mdi_audio.h"
#include "Drm_gprot.h"
#include "AudioPlayerDef.h"
#include "AudioPlayerPlayList.h"
#include "AudioPlayerType.h"
#include "AudioPlayerProt.h"
#include "Filemgrsrvgprot.h"


#include "MMIDataType.h"
#include "aud_id3_parser.h"
#include "gui_data_types.h"

#include "GlobalResDef.h"
#include "mmi_rp_app_audioplayer_def.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "Unicodexdcl.h"
#include "mmi_media_app_trc.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "CustDataRes.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "CommonScreens.h"
#include "FrameworkBackwardCompatible_Int.h"
#include "Wgui_categories_text_viewer.h"
extern audply_struct g_audply;
mmi_id g_details_id = 0;


#ifdef __MMI_AUDPLY_NEW_META_PARSER__
#define AUDPLY_DETAILS_TITLE_MAX_LEN		(META_TAG_FRAME_MAX_LEN)
#define AUDPLY_DETAILS_ARTIST_MAX_LEN		(META_TAG_FRAME_MAX_LEN)
#define AUDPLY_DETAILS_ALBUM_MAX_LEN		(META_TAG_FRAME_MAX_LEN)
#define AUDPLY_DETAILS_GENRE_MAX_LEN		(META_TAG_FRAME_MAX_LEN)
#define AUDPLY_DETAILS_YEAR_MAX_LEN			(4 + 1)
//#define AUDPLY_DETAILS_COPYRIGHTS_MAX_LEN	(META_TAG_FRAME_MAX_LEN)
#define AUDPLY_DETAILS_DURATION_MAX_LEN		(10 + 1)
#define AUDPLY_DETAILS_SIZE_MAX_LEN			(10 + 1)
#define AUDPLY_DETAILS_QUALITY_MAX_LEN		(24 + 1)
#define AUDPLY_DETAILS_FILENAME_MAX_LEN		(SRV_FMGR_PATH_MAX_FILE_NAME_LEN )
#define AUDPLY_DETAILS_TRACKNUM_MAX_LEN		(10 + 1)
#else
#define AUDPLY_DETAILS_TITLE_MAX_LEN		(MAX_ID3_TITLE_LEN + 1)
#define AUDPLY_DETAILS_ARTIST_MAX_LEN		(MAX_ID3_ARTIST_LEN + 1)
#define AUDPLY_DETAILS_ALBUM_MAX_LEN		(MAX_ID3_ALBUM_LEN + 1)
#define AUDPLY_DETAILS_GENRE_MAX_LEN		(MAX_ID3_GENRE_LEN + 1)
#define AUDPLY_DETAILS_YEAR_MAX_LEN			(MAX_ID3_YEAR_LEN + 1)
//#define AUDPLY_DETAILS_COPYRIGHTS_MAX_LEN	(MAX_ID3_COPYRIGHT_LEN + 1)
#define AUDPLY_DETAILS_DURATION_MAX_LEN		(MAX_ID3_DURATION_LEN + 1)
#define AUDPLY_DETAILS_SIZE_MAX_LEN			(10 + 1)
#define AUDPLY_DETAILS_QUALITY_MAX_LEN		(24 + 1)
#define AUDPLY_DETAILS_FILENAME_MAX_LEN		(SRV_FMGR_PATH_MAX_FILE_NAME_LEN )
#define AUDPLY_DETAILS_TRACKNUM_MAX_LEN		(MAX_ID3_TRACKNUM_LEN + 1)
#endif

typedef struct
{
    UI_character_type title[AUDPLY_DETAILS_TITLE_MAX_LEN];
    UI_character_type artist[AUDPLY_DETAILS_ARTIST_MAX_LEN];
    UI_character_type album[AUDPLY_DETAILS_ALBUM_MAX_LEN];
    UI_character_type genre[AUDPLY_DETAILS_GENRE_MAX_LEN];
    UI_character_type year[AUDPLY_DETAILS_YEAR_MAX_LEN];
    //UI_character_type copyright[AUDPLY_DETAILS_COPYRIGHTS_MAX_LEN];
    UI_character_type duration[AUDPLY_DETAILS_DURATION_MAX_LEN];
    UI_character_type size[AUDPLY_DETAILS_SIZE_MAX_LEN];
    UI_character_type quality[AUDPLY_DETAILS_QUALITY_MAX_LEN];
    UI_character_type filename[AUDPLY_DETAILS_FILENAME_MAX_LEN + 1];
    UI_character_type track_num[AUDPLY_DETAILS_TRACKNUM_MAX_LEN];
	U16 channel_num;
} mmi_audply_details_view_struct;


#define MMI_AUDPLY_MAX_DETAILS_FIELDS               (11)
static mmi_audply_details_view_struct* meta_data_p = NULL;

extern U8 PhnsetGetDefEncodingType(void);



typedef enum
{
    ITEM_ID_DETAIL_BGEIN = CUI_INLINE_ITEM_ID_BASE,
#ifdef __MMI_AUDIO_PLAYER_DETAIL_SHOW_MORE_INFO__
    ITEM_ID_DETAIL_FILENAME_CAPTION,
    ITEM_ID_DETAIL_FILENAME,
    ITEM_ID_DETAIL_CHANNEL_CAPTION,
    ITEM_ID_DETAIL_CHANNEL,
    ITEM_ID_DETAIL_QUALITY_CAPTION,
    ITEM_ID_DETAIL_QUALITY,
#endif
    ITEM_ID_DETAIL_SIZE_CAPTION,
    ITEM_ID_DETAIL_SIZE,
    ITEM_ID_DETAIL_DURATION_CAPTION,
    ITEM_ID_DETAIL_DURATION,
    ITEM_ID_DETAIL_TITLE_CAPTION,
    ITEM_ID_DETAIL_TITLE,
    ITEM_ID_DETAIL_ARTIST_CAPTION,
    ITEM_ID_DETAIL_ARTIST,
    ITEM_ID_DETAIL_ALBUM_CAPTION,
    ITEM_ID_DETAIL_ALBUM,
    ITEM_ID_DETAIL_GENRE_CAPTION,
    ITEM_ID_DETAIL_GENRE,
    ITEM_ID_DETAIL_YEAR_CAPTION,
    ITEM_ID_DETAIL_YEAR,
#ifdef __MMI_AUDPLY_DETAILS_SHOW_TRACK_NUM__    
    ITEM_ID_DETAIL_TRACK_NUM_CAPTION,
    ITEM_ID_DETAIL_TRACK_NUM,
#endif    
    AUDPLY_DETAILS_ITEMS_END,
    AUDPLY_DETAILS_ITEMS_NUM = AUDPLY_DETAILS_ITEMS_END - ITEM_ID_DETAIL_BGEIN - 1
}mmi_audply_detail_item_enum;
#ifdef __MMI_AUDIO_PLAYER_DETAIL_SHOW_MORE_INFO__
WCHAR detail_buffer[(AUDPLY_DETAILS_ITEMS_NUM + 6)*(MAX_SUBMENU_CHARACTERS)];

#else
WCHAR detail_buffer[AUDPLY_DETAILS_ITEMS_NUM * MAX_SUBMENU_CHARACTERS];

#endif
#if 0
#ifdef __MMI_AUDIO_PLAYER_DETAIL_SHOW_MORE_INFO__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_AUDPLY_DETAILS_SHOW_TRACK_NUM__    
/* under construction !*/
#endif
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
#ifdef __MMI_AUDIO_PLAYER_DETAIL_SHOW_MORE_INFO__    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#ifdef __MMI_AUDPLY_DETAILS_SHOW_TRACK_NUM__            
/* under construction !*/
/* under construction !*/
#endif
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
static void mmi_audply_details_set(void);
static void mmi_audply_details_free_asm(void);
static void mmi_audply_details_entry_scr(void);

#ifndef __MMI_AUDPLY_NEW_META_PARSER__
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_check_all_empty
 * DESCRIPTION
 *  Checks whether all the elements in the string are 0
 * PARAMETERS
 *  str			[IN/OUT]
 *	len		    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_check_all_empty(UI_character_type *str, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U8 flag = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for (; i < len; i++)
    {
        if (str[i] == ' ' || str[i] == 0)
            flag = 1;
        else 
        {
            flag = 0;
            break;
        }
    }

    if (flag)
    {
    	memset (str, 0, len);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_details_get_meta
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_path			[IN]
 *	out_data_p		[OUT]
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_audply_details_get_meta(const UI_string_type in_path, mmi_audply_details_view_struct* out_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = 0;
    aud_info_struct* daf_info_p = NULL;
	UI_character_type filename[SRV_FMGR_PATH_MAX_FILE_NAME_LEN  + 1];
    UI_character_type ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN];
	U16 file_ext_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    daf_info_p = (aud_info_struct*)gui_malloc(sizeof(aud_info_struct));

    if (daf_info_p == NULL)
    {
        return MMI_AUDPLY_PLAYLIST_ERR_NO_MEM;
    }
    else
    {
	    if (get_aud_info(in_path, daf_info_p))
	    {
	    	out_data_p->channel_num = daf_info_p->channel_num;
	        mmi_ucs2ncpy((CHAR*)out_data_p->artist, (CHAR*)daf_info_p->artist, AUDPLY_DETAILS_ARTIST_MAX_LEN - 1);
            mmi_ucs2ncpy((CHAR*)out_data_p->title, (CHAR*)daf_info_p->title, AUDPLY_DETAILS_TITLE_MAX_LEN - 1);
            mmi_ucs2ncpy((CHAR*)out_data_p->album, (CHAR*)daf_info_p->album, AUDPLY_DETAILS_ALBUM_MAX_LEN - 1);
            mmi_ucs2ncpy((CHAR*)out_data_p->genre, (CHAR*)daf_info_p->genre, AUDPLY_DETAILS_GENRE_MAX_LEN - 1);
            mmi_ucs2ncpy((CHAR*)out_data_p->year, (CHAR*)daf_info_p->year, AUDPLY_DETAILS_YEAR_MAX_LEN - 1);
            mmi_ucs2ncpy((CHAR*)out_data_p->duration, (CHAR*)daf_info_p->duration, AUDPLY_DETAILS_DURATION_MAX_LEN - 1);
            mmi_ucs2ncpy((CHAR*)out_data_p->size, (CHAR*)daf_info_p->size, AUDPLY_DETAILS_SIZE_MAX_LEN - 1);
            mmi_ucs2ncpy((CHAR*)out_data_p->quality, (CHAR*)daf_info_p->quality, AUDPLY_DETAILS_QUALITY_MAX_LEN - 1);
            mmi_ucs2ncpy((CHAR*)out_data_p->filename, (CHAR*)daf_info_p->filename, AUDPLY_DETAILS_FILENAME_MAX_LEN);
            mmi_ucs2ncpy((CHAR*)out_data_p->track_num, (CHAR*)daf_info_p->track_num, AUDPLY_DETAILS_TRACKNUM_MAX_LEN - 1);         

	    /* Checking whether all are empty*/
            mmi_audply_check_all_empty(out_data_p->artist, AUDPLY_DETAILS_ARTIST_MAX_LEN - 1);
            mmi_audply_check_all_empty(out_data_p->title, AUDPLY_DETAILS_TITLE_MAX_LEN - 1);
            mmi_audply_check_all_empty(out_data_p->album, AUDPLY_DETAILS_ALBUM_MAX_LEN - 1);
            mmi_audply_check_all_empty(out_data_p->genre, AUDPLY_DETAILS_GENRE_MAX_LEN - 1);
            mmi_audply_check_all_empty(out_data_p->year, AUDPLY_DETAILS_YEAR_MAX_LEN - 1);
            mmi_audply_check_all_empty(out_data_p->duration, AUDPLY_DETAILS_DURATION_MAX_LEN - 1);
            mmi_audply_check_all_empty(out_data_p->size, AUDPLY_DETAILS_SIZE_MAX_LEN - 1);
            mmi_audply_check_all_empty(out_data_p->quality, AUDPLY_DETAILS_QUALITY_MAX_LEN - 1);
            mmi_audply_check_all_empty(out_data_p->track_num, AUDPLY_DETAILS_TRACKNUM_MAX_LEN - 1);         

		/* special case. */
			mmi_audply_extract_filename(filename, in_path);
			mmi_audply_split_filename_ext(filename, out_data_p->filename, ext);
			file_ext_index = mmi_audply_lookup_audio_file_format(ext);
	    #if !defined(__MMI_SHOW_DAF_FILE_EXT__) && defined(DAF_DECODE)   
		    if (file_ext_index == AUDPLY_AUDIO_FILE_TYPE_DAF
		    #ifdef MUSICAM_DECODE
		        || file_ext_index == AUDPLY_AUDIO_FILE_TYPE_MP2
		    #endif
		        )
		    {
		    	//do nothing, because the "out_data_p->filename" has not extensions now.
		    }
		    else
	    #endif
	    	{
				mmi_ucs2ncpy((CHAR*)out_data_p->filename, (CHAR*)filename, SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
	        }			
		#ifdef AAC_DECODE 	
	        if (file_ext_index == AUDPLY_AUDIO_FILE_TYPE_AAC)
	        {
				out_data_p->duration[0] = 0;
	        }
	    #endif   
        }
        else
        {
			ret = MMI_AUDPLY_PLAYLIST_ERR_META;
        }
    }
    mmi_audply_check_all_empty(out_data_p->filename, AUDPLY_DETAILS_FILENAME_MAX_LEN);
    gui_free(daf_info_p);

    return ret;
}

#else
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_details_get_meta_part1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_path			[IN]
 *	out_data_p		[OUT]
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_audply_details_get_meta_part1(const UI_string_type in_path, mmi_audply_details_view_struct* out_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    PU8 meta_parser_buffer = NULL;
    U32 meta_parser_hdlr = 0;
    U8 meta_parser_ret = 0;
    U8 meta_return_value = 0;
    U8 meta_audio_return_value = 0;
    meta_tag_music_info_struct* music_info_p = NULL;
	meta_tag_audio_info_struct* audio_info_p = NULL;

    MMI_BOOL parser_ready = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//memset(out_data_p, 0, sizeof(mmi_audply_details_view_struct));			
    meta_parser_buffer = mmi_frm_scrmem_alloc_framebuffer(META_TAG_PARSE_MIN_SIZE);
	if (meta_parser_buffer == NULL)
	{
	    return MMI_AUDPLY_PLAYLIST_ERR_NO_MEM;
	}
	else
	{
	    meta_parser_ret = meta_parser_create(meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, &meta_parser_hdlr);

	    if (meta_parser_ret > 0 && meta_parser_ret < META_TAG_ERR_TOTAL)
	    {
	         ret = MMI_AUDPLY_PLAYLIST_ERR_META; 
	    }
	    else
	    {
	        meta_return_value = meta_parse_file(meta_parser_hdlr, (kal_uint16*)in_path);

	        if (meta_return_value != 0)
	        {
	            ret = MMI_AUDPLY_PLAYLIST_ERR_META; 
                meta_parser_release(meta_parser_hdlr);
	        }
	        else
	        {
	        	meta_return_value = meta_get_music_info(meta_parser_hdlr, &music_info_p);
				meta_audio_return_value = meta_get_audio_info(meta_parser_hdlr, &audio_info_p);
				parser_ready = MMI_TRUE;
            }
        }
    }

    if (parser_ready && meta_return_value == META_TAG_ERR_NONE)
    {
		U16 string_len = 0;
	            
	    /* get data from meta context. */
		if (music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_size > 0)
		{
			string_len = (music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_size >> 1);
		    mmi_ucs2ncpy((CHAR*)out_data_p->artist, 
		                 (CHAR*)music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data,
		                 AUDPLY_DETAILS_ARTIST_MAX_LEN - 1);
	        string_len = (string_len > AUDPLY_DETAILS_ARTIST_MAX_LEN ? AUDPLY_DETAILS_ARTIST_MAX_LEN : string_len);
		    out_data_p->artist[string_len] = 0;
		}
		
		if (music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data_size > 0)
		{
			string_len = (music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data_size >> 1);
		    mmi_ucs2ncpy((CHAR*)out_data_p->album, 
		                 (CHAR*)music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data,
		                 AUDPLY_DETAILS_ALBUM_MAX_LEN - 1);
	        string_len = (string_len > AUDPLY_DETAILS_ALBUM_MAX_LEN ? AUDPLY_DETAILS_ALBUM_MAX_LEN : string_len);
		    out_data_p->album[string_len] = 0;
		}

		if (music_info_p->txt_frame[META_TAG_FRAME_TITLE].data_size > 0)
		{
			string_len = (music_info_p->txt_frame[META_TAG_FRAME_TITLE].data_size >> 1);
		    mmi_ucs2ncpy((CHAR*)out_data_p->title, 
		                 (CHAR*)music_info_p->txt_frame[META_TAG_FRAME_TITLE].data,
		                 AUDPLY_DETAILS_TITLE_MAX_LEN - 1);
	        string_len = (string_len > AUDPLY_DETAILS_TITLE_MAX_LEN ? AUDPLY_DETAILS_TITLE_MAX_LEN : string_len);
		    out_data_p->title[string_len] = 0;
		}

		if (music_info_p->txt_frame[META_TAG_FRAME_GENRE].data_size > 0)
		{
			string_len = (music_info_p->txt_frame[META_TAG_FRAME_GENRE].data_size >> 1);
		    mmi_ucs2ncpy((CHAR*)out_data_p->genre, 
		                 (CHAR*)music_info_p->txt_frame[META_TAG_FRAME_GENRE].data,
		                 AUDPLY_DETAILS_GENRE_MAX_LEN - 1);
	        string_len = (string_len > AUDPLY_DETAILS_GENRE_MAX_LEN ? AUDPLY_DETAILS_GENRE_MAX_LEN : string_len);
		    out_data_p->genre[string_len] = 0;
		}

		if (music_info_p->year > 0)
		{
		    kal_wsprintf((kal_wchar*)out_data_p->year, "%d", music_info_p->year);
		}
		else
		{
		    out_data_p->year[0] = 0;
		}

		if (music_info_p->track_number > 0)
		{
		    kal_wsprintf((kal_wchar*)out_data_p->track_num, "%d", music_info_p->track_number);
		}
		else
		{
		    out_data_p->track_num[0] = 0;
		}
    }
    if(parser_ready && meta_audio_return_value == META_TAG_ERR_NONE)
    { 
		if (audio_info_p->channel_number != 0)
		{
		    out_data_p->channel_num = audio_info_p->channel_number;
		}
        
		if (audio_info_p->bits_rate > 0 || audio_info_p->sample_rate > 0)
		{
		    UI_character_type temp[30];
		    U16 bitrate_fraction_1, bitrate_fraction_2, bitrate_fraction_3;
		    U16 samplerate_fraction_1, samplerate_fraction_2, samplerate_fraction_3;
		    
		    if (audio_info_p->bits_rate > 0)
		    {
		        bitrate_fraction_1 = audio_info_p->bits_rate / 100;
		        bitrate_fraction_1 = bitrate_fraction_1 - (bitrate_fraction_1 / 10) * 10;
		        bitrate_fraction_2 = audio_info_p->bits_rate / 10;
		        bitrate_fraction_2 = bitrate_fraction_2 - (bitrate_fraction_2 / 10) * 10;
		        bitrate_fraction_3 = audio_info_p->bits_rate - (audio_info_p->bits_rate / 10) * 10 ;
		        if (bitrate_fraction_3)
		        {
		            kal_wsprintf((kal_wchar*)out_data_p->quality, "%d.%d%d%dkbps", audio_info_p->bits_rate / 1000, bitrate_fraction_1, bitrate_fraction_2, bitrate_fraction_3);
		        }
		        else if (bitrate_fraction_2)
		        {
		            kal_wsprintf((kal_wchar*)out_data_p->quality, "%d.%d%dkbps", audio_info_p->bits_rate / 1000, bitrate_fraction_1, bitrate_fraction_2);
		        }
		        else if (bitrate_fraction_1)
		        {
		            kal_wsprintf((kal_wchar*)out_data_p->quality, "%d.%dkbps", audio_info_p->bits_rate / 1000, bitrate_fraction_1);
		        }
		        else
		        {
		            kal_wsprintf((kal_wchar*)out_data_p->quality, "%dkbps", audio_info_p->bits_rate / 1000);
		        }
		        
		        if (audio_info_p->sample_rate > 0)
		        {
		            mmi_ucs2ncat((CHAR*)out_data_p->quality, (CHAR*)L" / ", AUDPLY_DETAILS_QUALITY_MAX_LEN - 1);
		        }
		    }
		    
		    if (audio_info_p->sample_rate > 0)
		    {
		        samplerate_fraction_1 = audio_info_p->sample_rate / 100;
		        samplerate_fraction_1 = samplerate_fraction_1 - (samplerate_fraction_1 / 10) * 10;
		        samplerate_fraction_2 = audio_info_p->sample_rate / 10;
		        samplerate_fraction_2 = samplerate_fraction_2 - (samplerate_fraction_2 / 10) * 10;
		        samplerate_fraction_3 = audio_info_p->sample_rate - (audio_info_p->sample_rate / 10) * 10 ;

		        if (samplerate_fraction_3)
		        {
		            kal_wsprintf((kal_wchar*) temp, "%d.%d%d%dkHz", audio_info_p->sample_rate / 1000, samplerate_fraction_1, samplerate_fraction_2, samplerate_fraction_3);
		        }
		        else if (samplerate_fraction_2)
		        {
		            kal_wsprintf((kal_wchar*) temp, "%d.%d%dkHz", audio_info_p->sample_rate / 1000, samplerate_fraction_1, samplerate_fraction_2);
		        }
		        else if (samplerate_fraction_1)
		        {
		            kal_wsprintf((kal_wchar*) temp, "%d.%dkHz", audio_info_p->sample_rate / 1000, samplerate_fraction_1);
		        }
		        else
		        {
		            kal_wsprintf((kal_wchar*) temp, "%dkHz", audio_info_p->sample_rate / 1000);
		        }
		        mmi_ucs2ncat((CHAR*)out_data_p->quality, (CHAR*)temp, 25);
		    }
		}

		if (audio_info_p->duration)
		{
		    if (audio_info_p->duration < 3600)
		    {
		        U16 min = audio_info_p->duration / 60;
		        U16 sec = audio_info_p->duration % 60;
		        
		        kal_wsprintf((kal_wchar*)out_data_p->duration, "%02d:%02d", min, sec);
		    }
		    else
		    {
		        U16 hour = audio_info_p->duration / 3600;
		        U16 min = (audio_info_p->duration - hour * 3600) / 60;
		        U16 sec = (audio_info_p->duration - hour * 3600) % 60;
		        
		        kal_wsprintf((kal_wchar*)out_data_p->duration, "%d:%02d:%02d", hour, min, sec);
		    }
		}
    }
    if(parser_ready)
    {
        meta_parser_release(meta_parser_hdlr);
    }
    mmi_frm_scrmem_free(meta_parser_buffer);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_audply_details_get_meta_part2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_path			[IN]
 *	out_data_p		[OUT]
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_audply_details_get_meta_part2(const UI_string_type in_path, mmi_audply_details_view_struct* out_data_p)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	S32 ret = 0;
	FS_HANDLE handle = -1;
    U32 duration = 0;
    U32 file_size = 0;
    CHAR* filename_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = DRM_open_file((PU16)in_path, FS_READ_ONLY, DRM_PERMISSION_PLAY);
    
    if (handle < 0)
    {
        ret = handle;
    }
    else
    {
        DRM_file_size(handle, &file_size);
        DRM_close_file(handle);

        /* fill "size". */
        if (file_size >= 1024*1024)
	    {
	        file_size = file_size/1024 ;
	        kal_wsprintf((kal_wchar*)out_data_p->size, "%d.%dM", file_size / 1024, (file_size % 1024) / 103);
	    }
	    else if (file_size >= 1024)
	    {
	        kal_wsprintf((kal_wchar*)out_data_p->size, "%d.%dK", file_size / 1024, (file_size % 1024) / 103);
	    }
	    else
	    {
	        kal_wsprintf((kal_wchar*)out_data_p->size, "%dB", file_size);
	    }

		/* fill "filename". */	
        filename_p = mmi_ucs2rchr((CHAR*)in_path, (U16)L'\\');

        if (filename_p != NULL)
        {
            filename_p += 2;

            mmi_wcsncpy((WCHAR *)out_data_p->filename, (const WCHAR *)filename_p, SRV_FMGR_PATH_MAX_FILE_NAME_LEN );

            srv_fmgr_path_hide_extension((WCHAR*)(out_data_p->filename));
        }

		/* fill "duration" if it is empty. */
        if (out_data_p->duration[0] == 0)
        {
			mdi_audio_get_duration(in_path, &duration);
            if (duration)
	        {
	            duration /= 1000;
	            if (duration < 3600)
	            {
	                U16 min = duration / 60;
	                U16 sec = duration % 60;
	                
	                kal_wsprintf((kal_wchar*)out_data_p->duration, "%02d:%02d", min, sec);
	            }
	            else
	            {
	                U16 hour = duration / 3600;
	                U16 min = (duration - hour * 3600) / 60;
	                U16 sec = (duration - hour * 3600) % 60;
	                
	                kal_wsprintf((kal_wchar*)out_data_p->duration, "%d:%02d:%02d", hour, min, sec);
	            }
	        }
        }
    }
        
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_details_get_meta
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_path			[IN]
 *	out_data_p		[OUT]
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_audply_details_get_meta(const UI_string_type in_path, mmi_audply_details_view_struct* out_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ret = mmi_audply_details_get_meta_part1(in_path, out_data_p);

    if (ret >= 0 || ret == MMI_AUDPLY_PLAYLIST_ERR_META)
	{
		ret = mmi_audply_details_get_meta_part2(in_path, out_data_p);
	}
    return ret;
}

#endif

#if 0 /*should not check drm when entry detail screen*/
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
    #ifdef __DRM_SUPPORT__
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
    #endif /*__DRM_SUPPORT__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_details_prepare
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_audply_details_prepare(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type full_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_get_path(full_path, mmi_audply_playlist_get_current_highlight());

    if(meta_data_p == NULL)
    {
    meta_data_p = (mmi_audply_details_view_struct *)mmi_frm_scrmem_alloc(sizeof(mmi_audply_details_view_struct)); /*size is 858 bytes*/
		memset(meta_data_p,0,sizeof(mmi_audply_details_view_struct));
    }

    if (meta_data_p == NULL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_ENTRY_DETAIL_FAIL);
        return MMI_AUDPLY_PLAYLIST_ERR_NO_SPACE;
    }
	//memset (meta_data_p, 0, sizeof(mmi_audply_details_view_struct));
	//MMI_ASSERT(meta_data_p != NULL);
    ret = mmi_audply_details_get_meta(full_path, meta_data_p);

  	return ret;
}
void mmi_audply_details_rsk_up_hdlr(void)
{
    mmi_frm_group_close(g_details_id);
	g_details_id = 0;
}

static void mmi_audply_details_entry_scr(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_audply_details_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_audply_details_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    cui_event_inline_abort_struct *inline_evt = (cui_event_inline_abort_struct *)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        
        case EVT_ID_GROUP_ACTIVE:
        {
            mmi_audply_details_set();
			SetRightSoftkeyFunction(mmi_audply_details_rsk_up_hdlr, KEY_EVENT_UP);
            break;
        }
        case EVT_ID_GROUP_INACTIVE:
        case EVT_ID_SCRN_INACTIVE:
        case EVT_ID_SCRN_DEINIT:
        case EVT_ID_GROUP_DEINIT:
    {
            mmi_audply_details_free_asm();
            break;
        }
        default:
            break;
    }
	return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_details_free_asm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_details_free_asm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*history currHistory;*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (meta_data_p != NULL)
    {
        mmi_frm_scrmem_free(meta_data_p);
        meta_data_p = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_details_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_details_set(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    S32 ret = 0;
    U16* item_list[AUDPLY_DETAILS_ITEMS_NUM/2];
    U16 caption_list[AUDPLY_DETAILS_ITEMS_NUM/2];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_audply_details_prepare();
    if (ret < 0 && ret != MMI_AUDPLY_PLAYLIST_ERR_META)
    {
        return;
    }
    detail_buffer[0] = 0;
      
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
#endif /* __MMI_AUDIO_PLAYER_DETAIL_SHOW_MORE_INFO__ */ 



    caption_list[(ITEM_ID_DETAIL_SIZE - ITEM_ID_DETAIL_BGEIN -1)/2] = STR_ID_AUDPLY_DETAIL_SIZE;
    caption_list[(ITEM_ID_DETAIL_DURATION - ITEM_ID_DETAIL_BGEIN -1)/2] = STR_GLOBAL_TIME;
    caption_list[(ITEM_ID_DETAIL_TITLE - ITEM_ID_DETAIL_BGEIN -1)/2] = STR_ID_AUDPLY_DETAIL_TITLE;
    caption_list[(ITEM_ID_DETAIL_ARTIST - ITEM_ID_DETAIL_BGEIN -1)/2] = STR_ID_AUDPLY_DETAIL_ARTIST;
    caption_list[(ITEM_ID_DETAIL_ALBUM - ITEM_ID_DETAIL_BGEIN -1)/2] = STR_ID_AUDPLY_DETAIL_ALBUM;
    caption_list[(ITEM_ID_DETAIL_GENRE- ITEM_ID_DETAIL_BGEIN-1)/2] = STR_ID_AUDPLY_DETAIL_GENRE;
    caption_list[(ITEM_ID_DETAIL_YEAR- ITEM_ID_DETAIL_BGEIN -1)/2] = STR_ID_AUDPLY_DETAIL_YEAR;
	#ifdef __MMI_AUDIO_PLAYER_DETAIL_SHOW_MORE_INFO__
	caption_list[(ITEM_ID_DETAIL_FILENAME- ITEM_ID_DETAIL_BGEIN -1)/2] = STR_GLOBAL_FILENAME;
	caption_list[(ITEM_ID_DETAIL_CHANNEL - ITEM_ID_DETAIL_BGEIN -1)/2] = STR_ID_AUDPLY_DETAIL_CHANNEL;
	caption_list[(ITEM_ID_DETAIL_QUALITY - ITEM_ID_DETAIL_BGEIN -1)/2] = STR_ID_AUDPLY_DETAIL_QUALITY;
  	#endif
    item_list[(ITEM_ID_DETAIL_SIZE - ITEM_ID_DETAIL_BGEIN -1)/2] = meta_data_p->size;
    item_list[(ITEM_ID_DETAIL_DURATION - ITEM_ID_DETAIL_BGEIN -1)/2] = meta_data_p->duration;
    item_list[(ITEM_ID_DETAIL_TITLE - ITEM_ID_DETAIL_BGEIN -1)/2] = meta_data_p->title;
    item_list[(ITEM_ID_DETAIL_ARTIST - ITEM_ID_DETAIL_BGEIN -1)/2] = meta_data_p->artist;
    item_list[(ITEM_ID_DETAIL_ALBUM - ITEM_ID_DETAIL_BGEIN -1)/2] = meta_data_p->album;
    item_list[(ITEM_ID_DETAIL_GENRE- ITEM_ID_DETAIL_BGEIN-1)/2] = meta_data_p->genre;
    item_list[(ITEM_ID_DETAIL_YEAR- ITEM_ID_DETAIL_BGEIN -1)/2] = meta_data_p->year;
	#ifdef __MMI_AUDIO_PLAYER_DETAIL_SHOW_MORE_INFO__
	item_list[(ITEM_ID_DETAIL_FILENAME- ITEM_ID_DETAIL_BGEIN -1)/2] = meta_data_p->filename;
	if (meta_data_p->channel_num != 0)
    {
        U8* channel_p;
        if (meta_data_p->channel_num == 1)
        {
            channel_p = (PU8)GetString((U16)(STR_ID_AUDPLY_DETAIL_MONO));
        }
        else
        {
            channel_p = (PU8)GetString((U16)(STR_ID_AUDPLY_DETAIL_STEREO));
        }
	item_list[(ITEM_ID_DETAIL_CHANNEL- ITEM_ID_DETAIL_BGEIN -1)/2] =(U16*) channel_p;
	item_list[(ITEM_ID_DETAIL_QUALITY- ITEM_ID_DETAIL_BGEIN -1)/2] = meta_data_p->quality;
	}
  	#endif

    
    /* size */
    for( i = 0; i < AUDPLY_DETAILS_ITEMS_NUM/2;i++)
    {
        if(item_list[i][0] != 0)
        {
            kal_wstrcat((WCHAR*)detail_buffer,(WCHAR*) get_string(caption_list[i]));
            kal_wstrcat((WCHAR*)detail_buffer,L":\n"); 
            kal_wstrcat((WCHAR*)detail_buffer,(WCHAR*) item_list[i]);
            kal_wstrcat((WCHAR*)detail_buffer,L"\n");    

        }
        }
	detail_buffer[kal_wstrlen(detail_buffer)-1] = 0;
    ShowCategory74Screen(
                STR_GLOBAL_DETAILS,
                NULL,
                0,
                0,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                (PU8) detail_buffer,
                AUDPLY_DETAILS_ITEMS_NUM * MAX_SUBMENU_CHARACTERS,
                NULL);
    /* size */
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
#endif
#ifdef __MMI_AUDPLY_DETAILS_SHOW_TRACK_NUM__
    if (meta_data_p->track_num[0] != 0)
    {
        
        cui_inline_set_value(inline_id, ITEM_ID_DETAIL_TRACK_NUM, (void *)meta_data_p->track_num);

        cui_inline_set_item_attributes(
            inline_id, 
            ITEM_ID_DETAIL_TRACK_NUM, 
            CUI_INLINE_SET_ATTRIBUTE, 
            CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW); 
		
        
        icon_list[i] = IMG_GLOBAL_L1 + i / 2;
        i++;
        icon_list[i++] = 0;
    }
    else
    {
        cui_inline_delete_item(inline_id, ITEM_ID_DETAIL_TRACK_NUM_CAPTION);
        cui_inline_delete_item(inline_id, ITEM_ID_DETAIL_TRACK_NUM);
    }
#endif


}
void mmi_audply_details_exit(void)

{
		mmi_audply_details_free_asm();
}
void mmi_audply_detail_enter_screen(void)
{
	mmi_frm_scrn_enter(g_details_id,SCR_ID_AUDPLY_DETAIL,
        mmi_audply_details_exit, mmi_audply_detail_enter_screen,MMI_FRM_FULL_SCRN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_details_entry_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_audply_details_entry_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    mmi_id inline_id;
    S32 ret = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AUDPLY_TRC_ENTRY_DETAIL);
    
   
    ret = mmi_audply_details_prepare();
    if (ret < 0 && ret != MMI_AUDPLY_PLAYLIST_ERR_META)
    {
        mmi_audply_details_free_asm();
        mmi_audply_display_popup(ret, NULL, NULL);
        return;
    }
    mmi_audply_details_free_asm();


    g_details_id = mmi_frm_group_create_ex(
        GRP_ID_AUDPLY_OPTION, 
        GRP_ID_AUTO_GEN, 
        mmi_audply_details_group_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_audply_detail_enter_screen();


}

    

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_entry_detail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_audply_entry_detail(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type full_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_audply_playlist_get_path(full_path, mmi_audply_playlist_get_current_highlight());
    result = srv_fmgr_fs_path_exist(full_path);
    if(result >= 0)
    {
        mmi_audply_details_entry_scr();
    }
    else
    {
        mmi_display_popup((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_FILE_NOT_FOUND)),MMI_EVENT_FAILURE);
    }
}
#endif /* __MMI_AUDIO_PLAYER_DETAILS_SUPPORT__ */
#endif  /* __MMI_AUDIO_PLAYER__ */
