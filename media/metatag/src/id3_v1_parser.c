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
*  id3_v1_parser.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   id3 v1 parsing definitions
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
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include <stdlib.h>
#include "kal_trace.h"
#include "id3_v1_parser.h"
#include "meta_tag_api.h"
#include "kal_general_types.h"
#include "meta_tag_parser.h"
#include "string.h"
#include "kal_public_api.h"
#include "med_trc.h"
#include "Conversions.h"

#if defined(__TAG_SUPPORT_ID3V1__)

/*  define global variable
*/
#define ID3_TAG_GENRE_NUM           148

static  const char * const g_genres[ID3_TAG_GENRE_NUM] = 
{
    "Blues",            "Classic Rock",     "Country",          "Dance",        
    "Disco",            "Funk",             "Grunge",           "Hip-Hop", 
    "Jazz",             "Metal",            "New Age",          "Oldies",
    "Other",            "Pop",              "R&B",              "Rap", 
    "Reggae",           "Rock",             "Techno",           "Industrial",
    "Alternative",      "Ska",              "Death Metal",      "Pranks",       
    "Soundtrack",       "Euro-Techno",      "Ambient",          "Trip-Hop",
    "Vocal",            "Jazz+Funk",        "Fusion",           "Trance",
    "Classical",        "Instrumental",     "Acid",             "House",
    "Game",             "Sound Clip",       "Gospel",           "Noise",
    "AlternRock",       "Bass",             "Soul",             "Punk",
    "Space",            "Meditative",       "Instrumental Pop", "Instrumental Rock",
    "Ethnic",           "Gothic",           "Darkwave",         "Techno-Industrial",
    "Electronic",       "Pop-Folk",         "Eurodance",        "Dream",
    "Southern Rock",    "Comedy",           "Cult",             "Gangsta",
    "Top 40",           "Christian Rap",    "Pop/Funk",         "Jungle",
    "Native American",  "Cabaret",          "New Wave",         "Psychedelic",
    "Rave",             "Showtunes",        "Trailer",          "Lo-Fi",
    "Tribal",           "Acid Punk",        "Acid Jazz",        "Polka",
    "Retro",            "Musical",          "Rock & Roll",      "Hard Rock",
    "Folk",             "Folk-Rock",        "National Folk",    "Swing",
    "Fast Fusion",      "Bebob",            "Latin",            "Revival",
    "Celtic",           "Bluegrass",        "Avantgarde",       "Gothic Rock",
    "Progressive Rock", "Psychedelic Rock", "Symphonic Rock",   "Slow Rock",
    "Big Band",         "Chorus",           "Easy Listening",   "Acoustic",
    "Humour",           "Speech",           "Chanson",          "Opera",
    "Chamber Music",    "Sonata",           "Symphony",         "Booty Bass",
    "Primus",           "Porn Groove",      "Satire",           "Slow Jam",
    "Club",             "Tango",            "Samba",            "Folklore",
    "Ballad",           "Power Ballad",     "Rhythmic Soul",    "Freestyle",
    "Duet",             "Punk Rock",        "Drum Solo",        "A capella",
    "Euro-House",       "Dance Hall",       "Goa",              "Drum & Bass",
    "Club-House",       "Hardcore",         "Terror",           "Indie",
    "BritPop",          "Negerpunk",        "Polsk Punk",       "Beat",
    "Christian Gangsta Rap", "Heavy Metal", "Black Metal",      "Crossover",
    "Contemporary Christian","Christian Rock",   "Merengue",    "Salsa",
    "Thrash Metal",     "Anime",            "JPop",             "Synthpop"
};
static  const   id3_v1_tag_frame_struct g_frame[] = 
{
    {META_TAG_FRAME_TITLE,          3,  30},
    {META_TAG_FRAME_ARTIST,         33, 30},
    {META_TAG_FRAME_ALBUM,          63, 30},
    {META_TAG_FRAME_DESCRIPTION,    97, 30},
};


/*****************************************************************************
 * FUNCTION
 *  id3_tag_v1_get_genre
 * DESCRIPTION
 *  get genre by index
 * PARAMETERS
 *  genreID      [IN]        index of Genre
 * RETURNS
 *  success return Genre's name,
 *****************************************************************************/
const char*  id3_tag_v1_get_genre(kal_int32 genreID)
{
    if (genreID >= 0 && genreID < ID3_TAG_GENRE_NUM)
    {
        return  g_genres[genreID];
    }
    return  NULL;
}


/*****************************************************************************
* FUNCTION
*  id3_tag_v1_u16_parse_number
* DESCRIPTION
*  
* PARAMETERS
*  text            [?]         UCS2 and its format is *((0-9)+)*, i.e. (12) or (123), ....etc.
*  text_size       [IN]        (word)
* RETURNS
*  kal_int32
*****************************************************************************/
kal_int32 id3_tag_v1_u16_parse_number(kal_uint16 *text, kal_int32 text_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 s32Ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (s32Ret = -1; text_size != 0; text_size--, text++)
    {
        if (*text >= L'0' && *text <= L'9')
        {
            if (s32Ret < 0)    /* check if it's the first time */
            {
                s32Ret = 0;
            }
            s32Ret = s32Ret * 10 + (kal_int32)(*text - L'0');
        }
        else if (*text == L'(' )
        {
            if (s32Ret >= 0)
            {
                break;  /* finish */
            }
        }
		else
		{
			break;
		}
    }
    return s32Ret;
}

/*****************************************************************************
 * FUNCTION
 *  id3_tag_v1_parse
 * DESCRIPTION
 *  parse id3 v1 meta 
 * PARAMETERS
 *  metaID      [IN]        meta parser handle ID
 *  pInternal   [IN/OUT]    information for output
 * RETURNS
 *  success return META_TAG_ERR_NONE,
 *****************************************************************************/
kal_uint8 id3_tag_v1_parse(
                kal_uint32 metaID, 
                meta_tag_internal_info_struct* pInternal
                )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32   nRet, i;
    kal_uint8*  pBuffer;
    kal_uint8   u8TmpBuf[ID3_TAG_V1_SIZE]; 
    kal_uint8   u8Tmp, u8Len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /*before read data, the tag position has been locate*/
    nRet = pInternal->func_p->tag_read(metaID, u8TmpBuf, ID3_TAG_V1_SIZE);
    if (nRet != ID3_TAG_V1_SIZE)
    {
        META_TAG_ERR_TRACE(FILE_ID_ID3_V1_PARSER, nRet);

        return  META_TAG_ERR_INVAILD_DATA;
    }
    /*check the data header, whether it is TAG*/
    if (0 != memcmp(u8TmpBuf, ID3_TAG_V1_MAGIC_ID, ID3_TAG_V1_MAGIC_SIZE))
    {
        META_TAG_ERR_TRACE(FILE_ID_ID3_V1_PARSER, META_TAG_ERR_INVAILD_DATA);

        return  META_TAG_ERR_INVAILD_DATA;
    }
    /*parse text attribute from TAG*/
    for (i = 0; i < 4; i++)
    {
        if (NULL != pInternal->music_info.txt_frame[g_frame[i].tag_attr].data)
            continue;
    
        if (meta_tag_is_empty_asci_item(u8TmpBuf+g_frame[i].tag_offset, 
            g_frame[i].tag_size))
            continue;

        pBuffer = pInternal->func_p->tag_getbuffer(metaID, ID3_TAG_V1_FRAME_SIZE);
        ASSERT(NULL != pBuffer);
        /*
        *   for string in buffer has no terminator, 
        *   so save the next string first char and set zero
        */
        u8Len = (kal_uint8)(g_frame[i].tag_offset+g_frame[i].tag_size);
               
        if (META_TAG_TEXT_ENCODING_UCS2 == pInternal->prefer_charset)
        {
            u8Tmp = u8TmpBuf[u8Len];
            u8TmpBuf[u8Len] = 0;

            nRet = mmi_chset_text_to_ucs2(
                pBuffer,
                (kal_int32)ID3_TAG_V1_FRAME_SIZE,
                u8TmpBuf+g_frame[i].tag_offset);

            u8TmpBuf[u8Len] = u8Tmp;

            if (nRet > 2)
            {
                nRet -= 2;
                pInternal->music_info.txt_frame[g_frame[i].tag_attr].data = 
                    (kal_uint16*)pBuffer;
            }
            else
            {
                pInternal->music_info.txt_frame[g_frame[i].tag_attr].data = NULL;
                nRet = 0;
            }  
            pInternal->music_info.txt_frame[g_frame[i].tag_attr].data_encoding = 
                pInternal->prefer_charset;
        }
        else
        {           
            u8Len = g_frame[i].tag_size;
            kal_mem_cpy((void*)pBuffer, 
                (const void*)(u8TmpBuf+g_frame[i].tag_offset), u8Len);
            
            if ((u8Len%2) != 0)
            {
                /*need sync char to 2 align*/
                pBuffer[u8Len] = 0;
                u8Len += 1;
            }
            pInternal->music_info.txt_frame[g_frame[i].tag_attr].data = 
                    (kal_uint16*)pBuffer;
            pInternal->music_info.txt_frame[g_frame[i].tag_attr].data_encoding = 
                META_TAG_TEXT_ENCODING_ISO_8859_1;

            nRet = u8Len;
        }    
        pInternal->music_info.txt_frame[g_frame[i].tag_attr].data_size = 
            (kal_uint16)nRet;    
    }
    /*get year attribute*/
    if (0 >= pInternal->music_info.year)
    {
        u8TmpBuf[97] = 0;
        if (u8TmpBuf[93] >= '0' && u8TmpBuf[93] <= '9')
        {
            pInternal->music_info.year = (kal_int32)atoi((const char*)(u8TmpBuf+93));
        }
        else
        {
            pInternal->music_info.year = -1;
        }
        
    }
    /*get track number for v1.1*/
    if ((0 == u8TmpBuf[125]) && (0 != u8TmpBuf[126]) && (pInternal->music_info.track_number <= 0))
    {
        pInternal->music_info.track_number = u8TmpBuf[126];
    }
    /*get genre from genre table*/
    if (NULL == pInternal->music_info.txt_frame[META_TAG_FRAME_GENRE].data && 
        u8TmpBuf[127] < ID3_TAG_GENRE_NUM)
    {
        pBuffer = pInternal->func_p->tag_getbuffer(metaID, ID3_TAG_V1_FRAME_SIZE);
        ASSERT(NULL != pBuffer);
        
        nRet = mmi_chset_convert(CHSET_UTF8, CHSET_UCS2, 
            (char*)g_genres[u8TmpBuf[127]], 
            (char*)pBuffer, 
            (kal_int32)ID3_TAG_V1_FRAME_SIZE);

		if (nRet > 2)
		{
			nRet -= 2;
		}        
        pInternal->music_info.txt_frame[META_TAG_FRAME_GENRE].data = 
            (kal_uint16*)pBuffer;
        pInternal->music_info.txt_frame[META_TAG_FRAME_GENRE].data_size = 
            (kal_uint16)nRet; 
        pInternal->music_info.txt_frame[META_TAG_FRAME_GENRE].data_encoding = 
            META_TAG_TEXT_ENCODING_UCS2; 
    }
    return  META_TAG_ERR_NONE;
}

#endif  /*#if defined(__TAG_SUPPORT_ID3V1__)*/

