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
 *
 * Filename:
 * ---------
 * mp4_parser_udat.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MPEG-4 Parser for user data atom
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined(__M3GPMP4_FILE_FORMAT_SUPPORT__)

#include "mp4_parser.h"
#include "vcodec_v2_trc.h"

#include "kal_general_types.h"
#include "fsal.h"
#include "kal_public_api.h"
#include "mp4_common.h"

#ifdef __VE_MM_DCM_SUPPORT__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VECOM_ROCODE", rodata = "DYNAMIC_CODE_VECOM_RODATA"
#endif

MP4_Parser_Status mp4_read_metaarray(STMp4Parser *pstMp4Parser, kal_uint8 *pbData, kal_uint32 read_pos, kal_uint32 *real_size)
{
   FSAL_Seek(pstMp4Parser->pstFSAL, read_pos);

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL,(kal_uint8 *) pbData, *real_size))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   return MP4_PARSER_OK;
}

#ifdef __VE_MM_DCM_SUPPORT__
#pragma arm section code, rodata
#endif

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
#endif

/*
DESCRIPTION
   Parse Name of the track Box.
INPUT
   size: The size of Title Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

#ifdef __MTK_TARGET__  // To avoid MODIS build error

#define SKIP_SIZE 16

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
#endif

/*
DESCRIPTION
   Parse Genre Box.
INPUT
   size: The size of Title Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/
#ifdef __RICH_AUDIO_PROFILE__
extern const char *id3_tag_genres[];
#define ID3V1_TAG_GENRE_LEN 147
#endif
// Genre as an ID3v1 code
static MP4_Parser_Status mp4_parse_genre(STMp4Parser *pstMp4Parser, kal_uint32 gen_size)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   if(gen_size < 1)
      return MP4_PARSER_PARSE_ERROR;;

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, (gen_size-1)))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

#ifdef __RICH_AUDIO_PROFILE__
   {
      kal_uint8 genreIndex;

      if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &genreIndex, 1))!=FSAL_OK){
         return MP4_PARSER_FILE_READ_ERROR;
      }
      if( (genreIndex <= ID3V1_TAG_GENRE_LEN)&&(genreIndex>0) ){
      	 kal_int32 i = 0;
      	 genreIndex -= 1;
         while(id3_tag_genres[genreIndex][i] != '\0'){
//            pstMp4Parser->genre[i] = id3_tag_genres[genreIndex][i];
            if(pstMp4Parser->bHasUDTAExtBuff)
               pstMp4Parser->pUDTAExtInfo->genre[i] = id3_tag_genres[genreIndex][i];
            i++;
            if(i>23) break; // max string length
         }
      }
   }
#else
    if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 1))!=FSAL_OK)
       return MP4_PARSER_FILE_SEEK_ERROR;
#endif

   return MP4_PARSER_OK;
}
static MP4_Parser_Status mp4_parse_udta_itunes_thumbnail(STMp4Parser *pstMp4Parser, kal_uint32 itunes_thumbnail_size)
{
	 MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
	 
	 if(itunes_thumbnail_size>16){

	 	if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 8))!=FSAL_OK)
         return MP4_PARSER_FILE_SEEK_ERROR;

        itunes_thumbnail_size -= 8;  
		{
	        kal_uint32 type;
			
		if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &type))!=FSAL_OK)
			return MP4_PARSER_FILE_READ_ERROR;

		if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 4))!=FSAL_OK)
		   return MP4_PARSER_FILE_SEEK_ERROR;
             
        itunes_thumbnail_size -= 8;

         switch(type){
         	case BOX_TYPE_JPG:
			  	pstMp4Parser->pUDTAExtInfo->eThumbType = MP4_MIMETYPE_JPEG;
				pstMp4Parser->pUDTAExtInfo->thumbnaildataLen = itunes_thumbnail_size;
				FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->thumbnaildataPos);
				if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, itunes_thumbnail_size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR; 
               break;
         	case BOX_TYPE_PNG:
			  	pstMp4Parser->pUDTAExtInfo->eThumbType = MP4_MIMETYPE_PNG;
				pstMp4Parser->pUDTAExtInfo->thumbnaildataLen = itunes_thumbnail_size;
				FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->thumbnaildataPos);
				if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, itunes_thumbnail_size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR;   
               break;
            default: /* unrecognized type, skip the box */
				pstMp4Parser->pUDTAExtInfo->eThumbType = MP4_MIMETYPE_NONE;
               if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, itunes_thumbnail_size))!=FSAL_OK)
                   return MP4_PARSER_FILE_SEEK_ERROR;
             }  
        }
   }   

   return MP4_PARSER_OK;
}

 static MP4_Parser_Status mp4_parse_udta_itunes_text(STMp4Parser *pstMp4Parser, kal_uint32 itunes_text_size, kal_uint32 type)
{

   /* Track Header Box is a leaf node. */

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   if(itunes_text_size>SKIP_SIZE){

      if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, SKIP_SIZE))!=FSAL_OK)
         return MP4_PARSER_FILE_SEEK_ERROR;

      itunes_text_size -= SKIP_SIZE;

      {
         /* only support if bHasUDTAExtBuff */
         if(pstMp4Parser->bHasUDTAExtBuff)
         {
            kal_int32 size = itunes_text_size;
            pstMp4Parser->pUDTAExtInfo->bHasILSTData = KAL_TRUE;
            switch(type){
               case BOX_TYPE_NAM:   // Title
                  pstMp4Parser->pUDTAExtInfo->titleLen = size;
				  FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->titlePos);
				  if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR;      
                  break;
               case BOX_TYPE_ART:   // Artist
                  pstMp4Parser->pUDTAExtInfo->artistLen = size;
				  FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->artistPos);
				  if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR;
                  break;
               case BOX_TYPE_AUT:   // Author
	              pstMp4Parser->pUDTAExtInfo->authorLen = size;
				  FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->authorPos);
				  if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR;
                  break;
               case BOX_TYPE_CPY:   // Copyright
	              pstMp4Parser->pUDTAExtInfo->copyrightLen = size;
				  FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->copyrightPos);
				  if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR;
                  break;
               case BOX_TYPE_DAY:   // Date
	              pstMp4Parser->pUDTAExtInfo->dateLen = size;
				  FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->datePos);
				  if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR;
                  break;
               case BOX_TYPE_ALB:   // Album
                  pstMp4Parser->pUDTAExtInfo->albumLen = size;
				  FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->albumPos);
				  if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR;
                  break;
               case BOX_TYPE_DESC:
			   	  pstMp4Parser->pUDTAExtInfo->descriptionLen = size;
				  FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->descriptionPos);
				  if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR;
                  break;
               case BOX_TYPE_GEN:
			   	  pstMp4Parser->pUDTAExtInfo->genreLen = size;
				  FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->genrePos);
				  if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR;
                  break;
               case BOX_TYPE_CMT:   // Annotation
                  pstMp4Parser->pUDTAExtInfo->commentLen = size;
				  FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->commentPos);
				  if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR;
                  break;
               case BOX_TYPE_TOO:
			   	  pstMp4Parser->pUDTAExtInfo->encoderLen = size;
				  FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->encoderPos);
				  if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR;
                  break;
               case BOX_TYPE_aART:
			   	  pstMp4Parser->pUDTAExtInfo->album_artistLen = size;
				  FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->album_artistPos);
				  if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR;
                  break;
               case BOX_TYPE_LYR:
			   	  pstMp4Parser->pUDTAExtInfo->lyricsLen = size;
				  FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->lyricsPos);
				  if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR;
                  break;
               case BOX_TYPE_GRP:
			   	  pstMp4Parser->pUDTAExtInfo->groupingLen = size;
				  FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->groupingPos);
				  if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR;
                  break;
               case BOX_TYPE_CATG:  // Category
                  pstMp4Parser->pUDTAExtInfo->categoryLen = size;
				  FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->categoryPos);
				  if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR;
                  break;
            }
            itunes_text_size -= size;
         }

      }
   }

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, itunes_text_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   return MP4_PARSER_OK;
}

/*
DESCRIPTION
   Parse the Track number Box.
INPUT
   size: The size of Title Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_trkn(STMp4Parser *pstMp4Parser, kal_uint32 trkn_size)
{
   /* Track Header Box is a leaf node. */

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   if(trkn_size<8)
      return MP4_PARSER_PARSE_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 8))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   trkn_size -= 8;

   {
      kal_int32 tmpSize = trkn_size;
      kal_uint32 tmpTrkn;

      if(tmpSize >= 8){
         tmpSize -= 8;
         trkn_size -= tmpSize;
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, tmpSize))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
         if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &tmpTrkn))!=FSAL_OK)
            return MP4_PARSER_FILE_READ_ERROR;

         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 4))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
         pstMp4Parser->trackNum = tmpTrkn;
      }else{
          if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, trkn_size))!=FSAL_OK)
             return MP4_PARSER_FILE_SEEK_ERROR;
      }
   }
   return MP4_PARSER_OK;
}

#endif // #ifdef __MTK_TARGET__

/*
DESCRIPTION
   Parse the iTunes/iPod Container Box.
INPUT
   size: The size of Track Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Parse error
*/

static MP4_Parser_Status mp4_parse_ilst(STMp4Parser *pstMp4Parser, kal_uint32 ilst_size)
{
   Parse_Box_Entry BoxInfo;

   /* look for possible nodes of ilst's direct childs */

   while(ilst_size > 0) {
      MP4_Parser_Status ret;

      if((ret=mp4_parse_box(pstMp4Parser, ilst_size, &BoxInfo))!=MP4_PARSER_OK)
         return ret;
      ilst_size -= BoxInfo.Len;
      BoxInfo.size -= BoxInfo.Len;

      switch(BoxInfo.type) {
#ifdef __MTK_TARGET__        // To avoid MODIS build error

      case BOX_TYPE_GNRE: // Genre
         if((ret=mp4_parse_genre(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            return ret;
         break;
      case BOX_TYPE_TRKN: // track num
         if((ret=mp4_parse_trkn(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            return ret;
         break;
      case BOX_TYPE_NAM:   // Title
      case BOX_TYPE_ART:   // Artist
      case BOX_TYPE_AUT:   // Author
      case BOX_TYPE_CPY:   // Copyright
      case BOX_TYPE_DAY:   // Date
      case BOX_TYPE_ALB:   // Album

      case BOX_TYPE_GEN:   // Genre ext
      case BOX_TYPE_DESC:  // Description
      case BOX_TYPE_CMT:   // Comment
      case BOX_TYPE_TOO:   // Encoder
      case BOX_TYPE_aART:  // Album Artist
      case BOX_TYPE_LYR:   // Lyrics
      case BOX_TYPE_GRP:   // Grouping
      case BOX_TYPE_CATG:  // Category
         if((ret=mp4_parse_udta_itunes_text(pstMp4Parser, BoxInfo.size, BoxInfo.type))!=MP4_PARSER_OK)
            return ret;
         break;
      case BOX_TYPE_COVR:  // Artwork
      	if((ret=mp4_parse_udta_itunes_thumbnail(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            return ret;
         break;


#endif // #ifdef __MTK_TARGET__

      default: /* unrecognized type, skip the box */
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, BoxInfo.size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
      }
      ilst_size -= BoxInfo.size;
   }

   if (ilst_size!=0)
      return MP4_PARSER_PARSE_ILST_ERROR;

   pstMp4Parser->bHasILST = KAL_TRUE;

   return MP4_PARSER_OK;
}


/*
DESCRIPTION
   Parse the udta text Box.
INPUT
   size: The size of title/yrrc/cprt/auth/albm Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_udta_text(STMp4Parser *pstMp4Parser, kal_int32 udta_text_size, kal_uint32 type)
{
   /* Track Header Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   if(udta_text_size<0)
      return MP4_PARSER_PARSE_ERROR;

   if(udta_text_size<7)
   {
      if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, udta_text_size))!=FSAL_OK)
         return MP4_PARSER_FILE_SEEK_ERROR;
      return MP4_PARSER_OK;
   }

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &version, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, flags, 3))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 2))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   udta_text_size -= 6;

   {
       kal_int32 size = udta_text_size;
      if(pstMp4Parser->bHasUDTAExtBuff)
      {
         switch(type)
         {
            case BOX_TYPE_TITL:
			   pstMp4Parser->pUDTAExtInfo->titleLen = size;
			   FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->titlePos);
			   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR;
               break;
            case BOX_TYPE_AUTH:
			   pstMp4Parser->pUDTAExtInfo->authorLen = size;
			   FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->authorPos);
			   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR;
               break;
            case BOX_TYPE_CPRT:
			   pstMp4Parser->pUDTAExtInfo->copyrightLen = size;
		       FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->copyrightPos);
			   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR;
               break;
            case BOX_TYPE_YRRC:
			   pstMp4Parser->pUDTAExtInfo->dateLen = size;
			   FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->datePos);
			   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR;
               break;
            case BOX_TYPE_PERF:
			   pstMp4Parser->pUDTAExtInfo->artistLen = size;
			   FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->artistPos);
			   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR;
               break;
         }
      }
//      else
//      {
//         if((ret=mp4_read_metaarray(pstMp4Parser, pstMp4Parser->title,
//                                    udta_text_size, &tmpSize, MP4_META_ARRAY_SIZE))!=MP4_PARSER_OK)
//            return ret;
//      }
      udta_text_size -= size;
   }

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, udta_text_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   return MP4_PARSER_OK;
}

/*
DESCRIPTION
   Parse the Album Box.
INPUT
   size: The size of Album Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_albm(STMp4Parser *pstMp4Parser, kal_int32 albm_size)
{
   /* Album Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   if(albm_size<0)
      return MP4_PARSER_PARSE_ERROR;

   if(albm_size<7)
   {
      if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, albm_size))!=FSAL_OK)
         return MP4_PARSER_FILE_SEEK_ERROR;
      return MP4_PARSER_OK;
   }

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &version, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, flags, 3))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 2))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   albm_size -= 6;

   {
     kal_int32 size = albm_size;
      if(pstMp4Parser->bHasUDTAExtBuff)
      {
	     pstMp4Parser->pUDTAExtInfo->albumLen = size;
	     FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->pUDTAExtInfo->albumPos);
		 if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, size))!=FSAL_OK)
				      return MP4_PARSER_FILE_SEEK_ERROR;
      }
//      else
//      {
//         if((ret=mp4_read_metaarray(pstMp4Parser, pstMp4Parser->album,
//                                    albm_size, &tmpSize, MP4_META_ARRAY_SIZE))!=MP4_PARSER_OK)
//            return ret;
//      }
      albm_size -= size;
   }

   //This is an optional field
   if(albm_size > 0)
   {
      pstMp4Parser->trackNum = 0;
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, (kal_uint8 *)&pstMp4Parser->trackNum, 1))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;
      albm_size -= 1;
   }
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, albm_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   return MP4_PARSER_OK;
}


/*
DESCRIPTION
   Parse the Meta Box.
INPUT
   size: The size of Meta Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_meta(STMp4Parser *pstMp4Parser, kal_int32 meta_size) // iTune/iPod
{
    Parse_Box_Entry BoxInfo;
    kal_uint8 data[4];
    kal_uint32 hdlrSize = 0;
    kal_uint8  ucheck_err = 0;
	
    MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

    /* look for possible nodes of meta's direct childs */
    if(meta_size > 8) {
        MP4_Parser_Status ret;

        // version
        if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, data, 1))!=FSAL_OK)
            return MP4_PARSER_FILE_READ_ERROR;
        // flags
        if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, data, 3))!=FSAL_OK)
            return MP4_PARSER_FILE_READ_ERROR;

        // get size of hdlr box
	if((ret=mp4_parse_box(pstMp4Parser, meta_size-12,&BoxInfo))!=MP4_PARSER_OK)
            return ret;
		
	hdlrSize = BoxInfo.size;


        if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, (kal_uint32)(hdlrSize-8)))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;

        meta_size -= (kal_int32)(hdlrSize+4);
        if(meta_size < 0)
        {
            ucheck_err = 1;
            goto mp4_parse_meta_end;
        }
        else if(meta_size < 8)
        {
            ucheck_err = 0;
            goto mp4_parse_meta_end;
        }
	    while(meta_size>0)
	    {
        if((ret=mp4_parse_box(pstMp4Parser, meta_size,&BoxInfo))!=MP4_PARSER_OK)
            return ret;
        meta_size -= BoxInfo.Len;
        BoxInfo.size -= BoxInfo.Len;
        if(meta_size < 0)
        {
            ucheck_err = 1;
            goto mp4_parse_meta_end;
        }
        switch(BoxInfo.type) {
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #if 0
        case BOX_TYPE_ILST:
            if((ret=mp4_parse_ilst(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
                return ret;
            break;
#ifdef __VE_KMV_SUPPORT__
		    case BOX_TYPE_UUID:
			    FSAL_GetCurPos(pstMp4Parser->pstFSAL, &pstMp4Parser->u4UUIDFileLen);
			    pstMp4Parser->u4UUIDFileLen -= BoxInfo.Len;
			    if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, BoxInfo.size))!=FSAL_OK)
                    return MP4_PARSER_FILE_SEEK_ERROR;
			    break;
#endif
        default: /* unrecognized type, skip the box */
            if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, BoxInfo.size))!=FSAL_OK)
                return MP4_PARSER_FILE_SEEK_ERROR;
        }
        meta_size -= BoxInfo.size;
    }
    }

mp4_parse_meta_end:
    if(ucheck_err)
        return MP4_PARSER_PARSE_META_ERROR;
//    if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, meta_size))!=FSAL_OK)
//        return MP4_PARSER_FILE_SEEK_ERROR;
    if (meta_size!=0)
       return MP4_PARSER_PARSE_ERROR;

    pstMp4Parser->bHasMETA = KAL_TRUE;

    return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the User Data Box.
INPUT
   size: The size of Track Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Parse error
*/

MP4_Parser_Status mp4_parse_udta(STMp4Parser *pstMp4Parser, kal_uint32 udta_size)
{
   Parse_Box_Entry BoxInfo;

   /* look for possible nodes of udta's direct childs */

   while(udta_size > 8) {
      MP4_Parser_Status ret;

	              // terminate by source
      if (pstMp4Parser->fgQuickClose == KAL_TRUE)
         return MP4_PARSER_PARSE_QUICK_CLOSED;

      if((ret=mp4_parse_box(pstMp4Parser, udta_size, &BoxInfo))!=MP4_PARSER_OK)
         return ret;
      udta_size -= BoxInfo.Len;
      BoxInfo.size -= BoxInfo.Len;

      switch(BoxInfo.type) {
      case BOX_TYPE_TITL:
      case BOX_TYPE_AUTH:
      case BOX_TYPE_CPRT:
      case BOX_TYPE_YRRC:
      case BOX_TYPE_PERF:
         if((ret=mp4_parse_udta_text(pstMp4Parser, BoxInfo.size, BoxInfo.type))!=MP4_PARSER_OK)
            return ret;
         break;
      case BOX_TYPE_ALBM:
         if((ret=mp4_parse_albm(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            return ret;
         break;
      case BOX_TYPE_META: // iTune/iPod
         if ((ret=mp4_parse_meta(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            return ret;
         break;
      default: /* unrecognized type, skip the box */
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, BoxInfo.size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
      }
      udta_size -= BoxInfo.size;
   }

   if (udta_size!=0)
   {
      //ASSERT(0);
      //return MP4_PARSER_PARSE_UDTA_ERROR;
      if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, udta_size))!=FSAL_OK)
      {
         //ASSERT(0);
         return MP4_PARSER_FILE_SEEK_ERROR;
      }
   }

   pstMp4Parser->bHasUDTA = KAL_TRUE;

   return MP4_PARSER_OK;
}


#endif //(__M3GPMP4_FILE_FORMAT_SUPPORT__)
