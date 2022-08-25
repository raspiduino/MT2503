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
 * mp4_parser.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MPEG-4 Parser
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined(__M3GPMP4_FILE_FORMAT_SUPPORT__)

#include "mp4_parser.h"
#include "vcodec_v2_trc.h"

#include "kal_general_types.h"
#include "fsal.h"
#include "mp4_common.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "l1audio.h"
#include "string.h"
#include "mot_utility.h"


#define SHOW_4_HEX(str, data)             \
   printf("%s:%x%x%x%x(hex)\n", str, (data[0]), (data[1]), (data[2]), (data[3]));

#define SHOW_4_CHAR(str, data)               \
   printf("%s:%c%c%c%c(char)\n", str, (data[0]), (data[1]), (data[2]), (data[3]));


/*
DESCRIPTION
   Parse the base class Box.
   The file pointer advances after the base class Box.
OUTPUT
   container_box_size: the size of the container box. (size of 0 handling)
OUTPUT
   *size: The size of the box excluding Box
   *type: The type of the box
RETURN
   MP4_PARSER_OK: Successful
   MP4_PARSER_64BIT_NOT_SUPPORT: We do not support 64-bit integers
   MP4_PARSER_LARGER_31BIT_NOT_SUPPORT: We do not support numbers larger than 31 bits
*/
MP4_Parser_Status mp4_parse_box(STMp4Parser *pstMp4Parser, kal_uint32 container_box_size, Parse_Box_Entry *BoxInfo)
{
    kal_uint32 u4size=0, u4type=0;
    MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

    if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &u4size))!=FSAL_OK)
        return MP4_PARSER_FILE_READ_ERROR;

    if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &u4type))!=FSAL_OK)
        return MP4_PARSER_FILE_READ_ERROR;

    MotUtilityParseBox(u4size,u4type,BoxInfo,pstMp4Parser->OpenType);	

    #if MP4_PARSER_VERBOSE
    printf("type=%c%c%c%c size=%u\n",
        (BoxInfo->type>>24) & 0xFF, (BoxInfo->type>>16) & 0xFF, (BoxInfo->type>>8) & 0xFF, BoxInfo->type & 0xFF, BoxInfo->size);
    #endif

    BoxInfo->Len = 8;
    if(BoxInfo->size==1)
    {
        BoxInfo->Len = 16;
        /* large size indication */
		 // Pibben for 64 bit, actually we do not support 64 bits; force the size limited in 0~2^32-1)
        if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &BoxInfo->size))!=FSAL_OK)
            return MP4_PARSER_FILE_READ_ERROR;
        if(BoxInfo->size != 0)
        {
            //ASSERT(0);
            return MP4_PARSER_64BIT_NOT_SUPPORT;
        }
        if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &BoxInfo->size))!=FSAL_OK)
            return MP4_PARSER_FILE_READ_ERROR;

    }
    else if (BoxInfo->size == 0)
    {
        BoxInfo->size = container_box_size;
    }
/*
   if (type == BOX_TYPE_UUID) {
      unsigned char usertype[16];
      res = fread(&usertype, 16, 1, fpMp4);
      if(res!=1) break;
   } */
   /* Do not support size larger than 31 bits */
   /*if((*size)&0x80000000)
      return MP4_PARSER_LARGER_31BIT_NOT_SUPPORT;*/

    return MP4_PARSER_OK;
}

#ifdef __VE_MM_DCM_SUPPORT__
#include "dcmgr.h" //DCM

#pragma arm section code = "DYNAMIC_CODE_VECOM_ROCODE", rodata = "DYNAMIC_CODE_VECOM_RODATA"
#endif

static MP4_Parser_Status mp4_parse_first_3flags(STMp4Parser *pstMp4Parser, kal_uint8 *pu1Version,
                                                                            kal_uint8 *pu1Flag, kal_uint32 *pu4EntryCount)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, pu1Version, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, pu1Flag, 3))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, pu4EntryCount))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   return MP4_PARSER_OK;
}
static MP4_Parser_Status mp4_parse_first_2flags_skip_n(STMp4Parser *pstMp4Parser, kal_uint8 *pu1Version,
                                                                            kal_uint8 *pu1Flag, kal_uint16 u2SkipNum)
{
    MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

    if ((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, pu1Version, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if ((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, pu1Flag, 3))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if (*pu1Version==1) /* We do not support 64 bit values. */
      return MP4_PARSER_64BIT_NOT_SUPPORT;

    if (u2SkipNum > 0)
    {
   /* creation_time */
        if ((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, u2SkipNum))!=FSAL_OK)
          return MP4_PARSER_PARSE_ERROR;
    }

   return MP4_PARSER_OK;
}

/*
DESCRIPTION
   Parse the File Type Box.
INPUT
   size: The size of File Type Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   Other values: Parse error
*/

static MP4_Parser_Status mp4_parse_ftyp(STMp4Parser *pstMp4Parser, kal_uint32 ftyp_size)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   if (ftyp_size<8)
      return MP4_PARSER_PARSE_ERROR;

   if ((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, ftyp_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   return MP4_PARSER_OK;
}


/*
DESCRIPTION
   Seek to the specified atom in the specified range.
   The file pointer advances after the base class Box.
INPUT
   uBoxType: The type of box to look for
   uRange: Search inside the following uRange bytes
OUTPUT
   *uSizeBox: The size of the box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: refer to mp4_parse_box
*/

MP4_Parser_Status mp4_seek_atom(STMp4Parser *pstMp4Parser, kal_uint32 uBoxType, kal_uint32 uRange, kal_uint32 *uSizeBox)
{
   MP4_Parser_Status ret;
   Parse_Box_Entry BoxInfo;

   MP4_PARSER_CHECK_ARG(uSizeBox!=NULL);

   while(uRange > 0) {

      if((ret=mp4_parse_box(pstMp4Parser, uRange, &BoxInfo))!=MP4_PARSER_OK)
         return ret;
      uRange -= BoxInfo.Len;
      BoxInfo.size -= BoxInfo.Len;

      if(BoxInfo.type==uBoxType) {
         *uSizeBox = BoxInfo.size;
         return MP4_PARSER_OK;
      }
      else { /* unrecognized type, skip the box */
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, BoxInfo.size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
      }
      uRange -= BoxInfo.size;
   }
   if (uRange!=0)
      return MP4_PARSER_PARSE_ERROR;
   return MP4_PARSER_ATOM_NOT_FOUND;
}

/*
DESCRIPTION
   Parse the base descriptor. (Refer to ISO 14496-1)
OUTPUT
   *type: The type of the box
   *size: The size of the box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   Other values: Parse error
*/
static MP4_Parser_Status mp4_parse_base_descriptor(STMp4Parser *pstMp4Parser, kal_uint8 *tag, kal_uint32 *size)
{
   kal_uint8 tmp;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL || size!=NULL);

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, tag, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &tmp, 1))!=FSAL_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   *size = (tmp & 0x7F);
   while(tmp&0x80) {
      if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &tmp, 1))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;
      *size = ((*size) << 7) + (tmp & 0x7F);
   }
   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Movie Header Box.
INPUT
   size: The size of Movie Header Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   MP4_PARSER_PARSE_ERROR: Parse error
*/

static MP4_Parser_Status mp4_parse_mvhd(STMp4Parser *pstMp4Parser, kal_uint32 mvhd_size)
{
   /* Move Header Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];

   if(mvhd_size<100)
      return MP4_PARSER_PARSE_ERROR;

   //version: 1
   //flag: 3
   //creation time: 4
   //modification time: 4
   if (mp4_parse_first_2flags_skip_n(pstMp4Parser, &version, flags, 8) != MP4_PARSER_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &(pstMp4Parser->timescale)))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &(pstMp4Parser->duration)))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 76))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &(pstMp4Parser->next_track_ID)))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   mvhd_size -= 100;
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, mvhd_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   pstMp4Parser->bHasMVHD = KAL_TRUE;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Track Header Box.
INPUT
   size: The size of Track Header Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_tkhd(STMp4Parser *pstMp4Parser, kal_uint32 tkhd_size)
{
   /* Track Header Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];
   kal_uint32 creation_time;
   kal_uint32 modification_time;
   kal_uint32 track_ID;
   kal_uint32 duration;
   kal_uint32 width;
   kal_uint32 height;
   STMp4Track *prTrack;

   if(tkhd_size<84)
      return MP4_PARSER_PARSE_ERROR;

   if (mp4_parse_first_3flags(pstMp4Parser, &version, flags, &creation_time) != MP4_PARSER_OK)
        return MP4_PARSER_FILE_READ_ERROR;
   if(version==1) /* We do not support 64 bit values. */
      return MP4_PARSER_64BIT_NOT_SUPPORT;

   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &modification_time))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &track_ID))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 4))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &duration))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 52))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &width))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &height))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   tkhd_size -= 84;
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, tkhd_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   prTrack = &(pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack]);

   prTrack->track_ID = track_ID;
   prTrack->bHasTKHD = KAL_TRUE;

   return MP4_PARSER_OK;
}

/*
DESCRIPTION
   Parse the Media Header Box.
INPUT
   size: The size of Media Header Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_mdhd(STMp4Parser *pstMp4Parser, kal_uint32 mdhd_size)
{
   /* Media Header Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];
   kal_uint32 uTimeScale;
   kal_uint32 uDuration;
   STMp4Track *prTrack;

   if (mdhd_size<24)
      return MP4_PARSER_PARSE_ERROR;
   //version & flag
   //creation time:4
   //modification time: 4
   if (mp4_parse_first_2flags_skip_n(pstMp4Parser, &version, flags, 8) != MP4_PARSER_OK)
      return MP4_PARSER_FILE_READ_ERROR;
   if ((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &uTimeScale))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   if ((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &uDuration))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   prTrack = &pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack];

   prTrack->uMediaTimeScale = uTimeScale;
   prTrack->uMediaDuration = uDuration;

   if ((uTimeScale & 0x80000000) || (uTimeScale == 0)){
      return MP4_PARSER_PARSE_TIMESCALE_ERROR;
   }

   /* ISO-639-2/T language code: 4 */
   mdhd_size -= 20;

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, mdhd_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   prTrack->bHasMDHD = KAL_TRUE;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Handler Reference Box.
INPUT
   size: The size of Handler Reference Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_hdlr(STMp4Parser *pstMp4Parser, kal_uint32 hdlr_size)
{
   /* Handler Reference Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];
   kal_uint32 *puHandlerType;
   STMp4Track *prTrack;
#ifdef __VE_PRIRATE_3D_FORMAT__
    kal_uint8 name[MP4_HDLR_NAM_LEN+1];
#endif

   if(hdlr_size<24)
      return MP4_PARSER_PARSE_ERROR;

    /* version(8), flags(24), pre_defined(32) */
   if (mp4_parse_first_2flags_skip_n(pstMp4Parser, &version, flags, 4) != MP4_PARSER_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   MP4_PARSER_ASSERT(pstMp4Parser->bCurTrack < MP4_NUM_TRACKS);

   prTrack = &pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack];

   puHandlerType = &(prTrack->handler_type);

    /* handler_type(32) */
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, puHandlerType))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

    if (HDLR_TYPE_SOUN == *puHandlerType)
    {
      pstMp4Parser->bAudioTrack = pstMp4Parser->bCurTrack;
    }
    else if (HDLR_TYPE_VIDE == *puHandlerType)
    {
      pstMp4Parser->bVideoTrack = pstMp4Parser->bCurTrack;
   }
    hdlr_size -= 12;

    /* reserved(32*3) */
    if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 12))!=FSAL_OK)
        return MP4_PARSER_FILE_SEEK_ERROR;
   hdlr_size -= 12;

#ifdef __VE_PRIRATE_3D_FORMAT__
    if(hdlr_size >= MP4_HDLR_NAM_LEN)
    {
        if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, name, MP4_HDLR_NAM_LEN))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
        name[MP4_HDLR_NAM_LEN] = 0; // String ending character
        if(strcmp((char *)name, "MTK3D") == 0)
        {
            prTrack->bPrivate3DFormat = KAL_TRUE;
        }
        hdlr_size -= MP4_HDLR_NAM_LEN;
    }
#endif

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, hdlr_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   prTrack->bHasHDLR = KAL_TRUE;

   return MP4_PARSER_OK;
}

/*
DESCRIPTION
   Parse Elementary Stream Descriptor(ESD) Box.
   Refer to 14496-14 and 14496-1.
INPUT
   size: The size of ESD Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

MP4_Parser_Status mp4_parse_esds(STMp4Parser *pstMp4Parser, kal_int32 esds_size)
{
   /* ESD Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];

   /* ES Descriptor */
   kal_uint16 ES_ID;
   kal_uint8 flag;

   /* Decoder COnfig Descriptor */
   kal_uint8 objectTypeIndication;
   kal_uint8 streamType;
   kal_uint32 bufferSizeDB;
   kal_uint32 maxBitrate;
   kal_uint32 avgBitrate;

   if (mp4_parse_first_2flags_skip_n(pstMp4Parser, &version, flags, 0) != MP4_PARSER_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   esds_size -= 4;

   /* ES_Descriptor */
   {
      MP4_Parser_Status ret;
      kal_uint8 tag;
      kal_uint32 size;
      kal_uint32 pos1, pos2;

      MP4_PARSER_FILE_GET_CUR_POS(pos1);
      if((ret=mp4_parse_base_descriptor(pstMp4Parser, &tag, &size))!=MP4_PARSER_OK)
         return ret;
      MP4_PARSER_FILE_GET_CUR_POS(pos2);
      esds_size -= pos2-pos1;

      if(tag!=0x03) /* ES_DescrTag */
         return MP4_PARSER_ES_DESCR_TAG_EXPECTED;

      if((pstMp4Parser->eFSALErr=FSAL_Read_UINT16(pstMp4Parser->pstFSAL, &ES_ID))!=FSAL_OK)
         return MP4_PARSER_PARSE_ERROR;

      if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &flag, 1))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
      esds_size -= 3;
   }

   /* DecoderConfigDescription */
   {
      MP4_Parser_Status ret;
      kal_uint8 tag;
      kal_uint32 size;
      kal_uint32 pos1, pos2;

      MP4_PARSER_FILE_GET_CUR_POS(pos1);
      if((ret=mp4_parse_base_descriptor(pstMp4Parser, &tag, &size))!=MP4_PARSER_OK)
         return ret;
      MP4_PARSER_FILE_GET_CUR_POS(pos2);
      esds_size -= (pos2-pos1);
      if(tag!=0x04) /* DecoderConfigDescrTag */
         return MP4_PARSER_PARSE_ERROR;

      if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &objectTypeIndication, 1))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;

      if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &streamType, 1))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;

      streamType = (unsigned char)(streamType >> 2);

      if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, (kal_uint8*)&bufferSizeDB, 3))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;

      if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &maxBitrate))!=FSAL_OK)
         return MP4_PARSER_PARSE_ERROR;

      if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &avgBitrate))!=FSAL_OK)
         return MP4_PARSER_PARSE_ERROR;

      esds_size -= 13;
   }

   /* DecoderSpecificInfo */
   if(0x6B == objectTypeIndication || 0x69 == objectTypeIndication)
   {
       pstMp4Parser->bAudioType[pstMp4Parser->bCurTrack] = MP4_AUDIO_MP3;
       pstMp4Parser->uAudioMaxBitrate = maxBitrate;
       pstMp4Parser->uAudioAvgBitrate = avgBitrate;
   }

   {
      MP4_Parser_Status ret;
      kal_uint8 tag;
      kal_uint32 size;
      kal_uint32 pos1, pos2;

      MP4_PARSER_FILE_GET_CUR_POS(pos1);
      if ((ret=mp4_parse_base_descriptor(pstMp4Parser, &tag, &size))!=MP4_PARSER_OK)
         return ret;
      MP4_PARSER_FILE_GET_CUR_POS(pos2);
      esds_size -= pos2-pos1;
      #if 0 // pibben
/* under construction !*/
/* under construction !*/
      #else
      if (tag==0x05) /* DecSpecificInfoTag */
      #endif
      {
      if (0x05==streamType) { /* streamType == Audio Stream */

         if (0x40==objectTypeIndication)
         {
            /* objectType == 14496-3 */
            if((ret=mp4_parse_decoder_config_14496_3(pstMp4Parser, size))!=MP4_PARSER_OK)
               return ret;
            esds_size -= size;

            if(pstMp4Parser->bAudioObjectType ==22)
               pstMp4Parser->bAudioType[pstMp4Parser->bCurTrack] = MP4_AUDIO_BSAC;
            else if((pstMp4Parser->bAudioObjectType ==2)||(pstMp4Parser->bAudioObjectType ==5))
               pstMp4Parser->bAudioType[pstMp4Parser->bCurTrack] = MP4_AUDIO_AAC;
            else
            	 pstMp4Parser->bAudioType[pstMp4Parser->bCurTrack] = MP4_AUDIO_NONE;

            pstMp4Parser->uAudioMaxBitrate = maxBitrate;
            pstMp4Parser->uAudioAvgBitrate = avgBitrate;
         }
         else if(0x67 == objectTypeIndication)
         {
             /* MPEG-2 AAC LC  */
             /* 13818-7 ADIF header if present */
             pstMp4Parser->bAudioType[pstMp4Parser->bCurTrack] = MP4_AUDIO_AAC;

             pstMp4Parser->bAudioSamplingFreqIndex[pstMp4Parser->bCurTrack] = convertSamplingFreqToIndex(pstMp4Parser->uAudioSampleRate[pstMp4Parser->bCurTrack]);

             pstMp4Parser->uAudioMaxBitrate = maxBitrate;
             pstMp4Parser->uAudioAvgBitrate = avgBitrate;

             pstMp4Parser->bAudioChannelConfig[pstMp4Parser->bCurTrack] = pstMp4Parser->uAudioChannelCount[pstMp4Parser->bCurTrack];
         }
         else if (objectTypeIndication==0xD0)
         {
            /* amr produced by PacketVideo Author, not standard */
         }
      } else if (0x04==streamType) { /* streamType == Visual Stream */
         if (0x20==objectTypeIndication) {
            /* objectType == 14496-2 */
            /* for video, the following is video-object-sequence */
            pstMp4Parser->bVideoType[pstMp4Parser->bCurTrack] = MP4_VIDEO_MPEG4;
            MP4_PARSER_FILE_GET_CUR_POS(pstMp4Parser->uVOSOffset);
            pstMp4Parser->uVOSSize = size;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
         }
      }
      }

   }

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, esds_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Sample Description Box.
INPUT
   size: The size of Sample Description Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_stsd(STMp4Parser *pstMp4Parser, kal_uint32 stsd_size)
{
   /* Sample Description Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];
   kal_uint32 entry_count;
   Parse_Box_Entry BoxInfo;


   if (mp4_parse_first_3flags(pstMp4Parser, &version, flags, &entry_count) != MP4_PARSER_OK)
      return MP4_PARSER_FILE_READ_ERROR;

   stsd_size -= 8;

   if(entry_count>1)
      return MP4_PARSER_EXTERNAL_DATA_REFERENCE;
   else if(entry_count==1) {
      /* The following may be Audio Sample Entry or Visual Sample Entry */
      MP4_Parser_Status ret;

      if((ret=mp4_parse_box(pstMp4Parser, stsd_size,&BoxInfo))!=MP4_PARSER_OK)
         return ret;

      stsd_size -= BoxInfo.Len;
      BoxInfo.size -= BoxInfo.Len;

      switch(BoxInfo.type) {
      case SAMPLE_FMT_ENCV:
      case SAMPLE_FMT_MP4V:
         ret=mp4_parse_mp4v(pstMp4Parser, BoxInfo.size);
         break;
      case SAMPLE_FMT_ENCA:
      case SAMPLE_FMT_MP4A:
         pstMp4Parser->uMP4A_FMT_size = BoxInfo.size + 8 ;
         MP4_PARSER_FILE_GET_CUR_POS(pstMp4Parser->uMP4A_FMT_offset);
         ret=mp4_parse_mp4a(pstMp4Parser, BoxInfo.size);
         break;
      case SAMPLE_FMT_MP3:
      	 pstMp4Parser->bAudioType[pstMp4Parser->bCurTrack] = MP4_AUDIO_MP3;
      	 ret=mp4_parse_mp4a(pstMp4Parser, BoxInfo.size); // Use mp4a function to parse AudioSampleEntry
      	 break;
      case SAMPLE_FMT_SAMR:
         pstMp4Parser->bAudioType[pstMp4Parser->bCurTrack] = MP4_AUDIO_AMR;
         ret=mp4_parse_samr(pstMp4Parser, BoxInfo.size);
         break;
      case SAMPLE_FMT_SAWB:
         pstMp4Parser->bAudioType[pstMp4Parser->bCurTrack] = MP4_AUDIO_AMR_WB;
         ret=mp4_parse_samr(pstMp4Parser, BoxInfo.size);
         break;
      case SAMPLE_FMT_S263:
         pstMp4Parser->bVideoType[pstMp4Parser->bCurTrack] = MP4_VIDEO_H263;
         ret=mp4_parse_s263(pstMp4Parser, BoxInfo.size);
         break;
#ifdef __VE_H264_DEC_SUPPORT__
      case SAMPLE_FMT_AVC1:
          pstMp4Parser->bVideoType[pstMp4Parser->bCurTrack] = MP4_VIDEO_H264;
          ret=mp4_parse_s264(pstMp4Parser, BoxInfo.size);
         break;
#endif
      case SAMPLE_FMT_JPEG:
          pstMp4Parser->bVideoType[pstMp4Parser->bCurTrack] = MP4_VIDEO_MJPG;
          if((ret=mp4_parse_mjpg(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            return ret;
         break;

      default:
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, BoxInfo.size))!=FSAL_OK)
            return MP4_PARSER_PARSE_ERROR;
      }
      if (ret != MP4_PARSER_OK)
      {
        return ret;
      }
      stsd_size -= BoxInfo.size;
   }

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, stsd_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasSTSD = KAL_TRUE;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Decoding Time To Sample Box.
INPUT
   size: The size of Decoding Time To Sample Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   Other values: Parse error
*/

static MP4_Parser_Status mp4_parse_stts(STMp4Parser *pstMp4Parser, kal_uint32 stts_size)
{
   /* Decoding Time To Sample Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];
   kal_uint32 entry_count;
   STMp4Track *prTrack;
#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_PARSE_STTS);
#endif

   if (mp4_parse_first_3flags(pstMp4Parser, &version, flags, &entry_count) != MP4_PARSER_OK)
        return MP4_PARSER_FILE_READ_ERROR;

   prTrack = &(pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack]);

   prTrack->uTimeToSampleTableEntryCount = entry_count;
   MP4_PARSER_FILE_GET_CUR_POS(prTrack->uOffsetTimeToSampleTable);
   stts_size-=8;


   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, stts_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   prTrack->bHasSTTS = KAL_TRUE;

   /* Initilize STTS cache table */
   prTrack->uSTTSCacheTableEntryCount = 0;
   prTrack->uSTTSCacheTableStepSize = 0;
   prTrack->pSTTSCacheTable = NULL;

   return MP4_PARSER_OK;
}

/*
DESCRIPTION
   Parse the Composition Time To Sample Box.
INPUT
   size: The size of Composition Time To Sample Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   Other values: Parse error
*/
#ifdef __VE_MP4_PARSER_SUPPORT_CTTS__
static MP4_Parser_Status mp4_parse_ctts(STMp4Parser *pstMp4Parser, kal_uint32 ctts_size)
{
   /* Composition Time To Sample Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];
   kal_uint32 entry_count;
   STMp4Track *pt_Mp4Track;

#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_PARSE_CTTS);
#endif

   if (mp4_parse_first_3flags(pstMp4Parser, &version, flags, &entry_count) != MP4_PARSER_OK)
        return MP4_PARSER_FILE_READ_ERROR;

   pt_Mp4Track = &(pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack]);

   pt_Mp4Track->uCTimeToSampleTableEntryCount = entry_count;
   MP4_PARSER_FILE_GET_CUR_POS(pt_Mp4Track->uCOffsetTimeToSampleTable);
   ctts_size-=8;

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, ctts_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   pt_Mp4Track->bHasCTTS = KAL_TRUE;

   /* Initilize CTTS cache table */
   pt_Mp4Track->uCTTSCacheTableEntryCount = 0;
   pt_Mp4Track->uCTTSCacheTableStepSize = 0;
   pt_Mp4Track->pCTTSCacheTable = NULL;

   return MP4_PARSER_OK;
}
#endif
/*
DESCRIPTION
   Parse the Sample To Chunk Box.
INPUT
   size: The size of Sample To Chunk Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   Other values: Parse error
*/

static MP4_Parser_Status mp4_parse_stsc(STMp4Parser *pstMp4Parser, kal_uint32 stsc_size)
{
   /* Sample To Chunk Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];
   kal_uint32 entry_count;
   STMp4Track *prTrack;

   if (mp4_parse_first_3flags(pstMp4Parser, &version, flags, &entry_count) != MP4_PARSER_OK)
        return MP4_PARSER_FILE_READ_ERROR;

   prTrack = &(pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack]);

   prTrack->uSampleToChunkEntryCount = entry_count;
   MP4_PARSER_FILE_GET_CUR_POS(prTrack->uOffsetSampleToChunkTable);
   stsc_size-=8;

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, stsc_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   prTrack->bHasSTSC = KAL_TRUE;

   /* Initilize STSC cache table */
   prTrack->uSTSCCacheTableEntryCount = 0;
   prTrack->uSTSCCacheTableStepSize = 0;
   prTrack->pSTSCCacheTable = NULL;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Sample Sizes Box.
INPUT
   size: The size of Sample Sizes Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_stsz(STMp4Parser *pstMp4Parser, kal_int32 stsz_size)
{
   /* Sample Sizes Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];
   kal_uint32 sample_size;
   kal_uint32 sample_count;
   STMp4Track *prTrack;

   if (mp4_parse_first_3flags(pstMp4Parser, &version, flags, &sample_size) != MP4_PARSER_OK)
        return MP4_PARSER_FILE_READ_ERROR;

   prTrack = &(pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack]);

   if(sample_size!=0) {
     prTrack->uConstantSampleSize = sample_size;
   } else {
     prTrack->uConstantSampleSize = 0;
   }

   /* sample_count */
   if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &sample_count))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   prTrack->uSampleCount = sample_count;
   prTrack->bSampleCountUpdated = KAL_FALSE;

   stsz_size-=12;

   if(sample_size==0) {
      MP4_PARSER_FILE_GET_CUR_POS(prTrack->uOffsetSampleSizeTable);
   }

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, stsz_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Chunk Offset Box.
INPUT
   size: The size of Chunk Offset Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_stco(STMp4Parser *pstMp4Parser, kal_uint32 stco_size, kal_bool bIs64Bit)
{
   /* Chunk Offset Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];
   kal_uint32 entry_count;
   STMp4Track *pCurTrack;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   pCurTrack = &(pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack]);

   pCurTrack->uEntrySize = 4;
   if(bIs64Bit == KAL_TRUE)
   {
       pCurTrack->uEntrySize = 8;
   }

   if (mp4_parse_first_3flags(pstMp4Parser, &version, flags, &entry_count) != MP4_PARSER_OK)
        return MP4_PARSER_FILE_READ_ERROR;
   pCurTrack->uChunkCount = entry_count;

   stco_size-=8;

   MP4_PARSER_FILE_GET_CUR_POS(pCurTrack->uOffsetChunkOffsetTable);

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, stco_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   pCurTrack->bHasSTCO = KAL_TRUE;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Sync Sample Table Box.
INPUT
   size: The size of Sync Sample Table Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   Other values: Parse error
*/

static MP4_Parser_Status mp4_parse_stss(STMp4Parser *pstMp4Parser, kal_uint32 stss_size)
{
   /* Sync Sample Table Box is a leaf node. */
   kal_uint8 version;
   kal_uint8 flags[3];
   kal_uint32 entry_count;
   STMp4Track *prTrack;

   if (mp4_parse_first_3flags(pstMp4Parser, &version, flags, &entry_count) != MP4_PARSER_OK)
        return MP4_PARSER_FILE_READ_ERROR;

   prTrack = &pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack];

   prTrack->uSyncCount = entry_count;

   stss_size-=8;

   MP4_PARSER_FILE_GET_CUR_POS(prTrack->uOffsetSyncSampleTable);

   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, stss_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   /* Initilize STSS cache table */
   prTrack->uSTSSCacheTableEntryCount = 0;
   prTrack->uSTSSCacheTableStepSize = 0;
   prTrack->pSTSSCacheTable = NULL;

   prTrack->bHasSTSS = KAL_TRUE;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Sample Table Box.
INPUT
   size: The size of Sample Table Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_stbl(STMp4Parser *pstMp4Parser, kal_uint32 stbl_size)
{

   /* look for possible nodes of stbl's direct childs */
   while(stbl_size>0) {
      MP4_Parser_Status ret;
      Parse_Box_Entry BoxInfo;

	        // terminate by source
      if (pstMp4Parser->fgQuickClose == KAL_TRUE)
            return MP4_PARSER_PARSE_QUICK_CLOSED;

      if((ret=mp4_parse_box(pstMp4Parser, stbl_size,&BoxInfo))!=MP4_PARSER_OK)
         return ret;
      stbl_size-=BoxInfo.Len;
      BoxInfo.size -= BoxInfo.Len;

      switch(BoxInfo.type) {
      case BOX_TYPE_STSD:
         ret=mp4_parse_stsd(pstMp4Parser, BoxInfo.size);
         break;
      case BOX_TYPE_STTS:
         ret=mp4_parse_stts(pstMp4Parser, BoxInfo.size);
         break;
#ifdef __VE_MP4_PARSER_SUPPORT_CTTS__
      case BOX_TYPE_CTTS:
         ret=mp4_parse_ctts(pstMp4Parser, BoxInfo.size);
         break;
#endif
      case BOX_TYPE_STSC:
         ret=mp4_parse_stsc(pstMp4Parser, BoxInfo.size);
         break;
      case BOX_TYPE_STSZ:
         ret=mp4_parse_stsz(pstMp4Parser, BoxInfo.size);
         break;
      case BOX_TYPE_STCO:
         ret=mp4_parse_stco(pstMp4Parser, BoxInfo.size, KAL_FALSE);
         break;
      // Pibben for 64 bit
      case BOX_TYPE_CO64:
          ret=mp4_parse_stco(pstMp4Parser, BoxInfo.size, KAL_TRUE);
          break;
      case BOX_TYPE_STSS:
         ret=mp4_parse_stss(pstMp4Parser, BoxInfo.size);
         break;
      default: /* unrecognized type, skip the box */
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, BoxInfo.size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
      }
      if (ret != MP4_PARSER_OK){
        return ret;
      }
      stbl_size-=BoxInfo.size;
   }

   if (stbl_size!=0)
      return MP4_PARSER_PARSE_ERROR;

   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasSTBL = KAL_TRUE;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Media Information Box.
INPUT
   size: The size of Media Information Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_minf(STMp4Parser *pstMp4Parser, kal_uint32 minf_size)
{

   /* look for possible nodes of minf's direct childs */
   while(minf_size>0) {
      MP4_Parser_Status ret;
      Parse_Box_Entry BoxInfo;

      // terminate by source
      if (pstMp4Parser->fgQuickClose == KAL_TRUE)
         return MP4_PARSER_PARSE_QUICK_CLOSED;

      if((ret=mp4_parse_box(pstMp4Parser, minf_size,&BoxInfo))!=MP4_PARSER_OK)
         return ret;
      minf_size-=BoxInfo.Len;
      BoxInfo.size -= BoxInfo.Len;

      switch(BoxInfo.type) {
      case BOX_TYPE_STBL:
         if((ret=mp4_parse_stbl(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            return ret;
         break;
      default: /* unrecognized type, skip the box */
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, BoxInfo.size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
      }
      minf_size -= BoxInfo.size;
   }

   if (minf_size!=0)
      return MP4_PARSER_PARSE_ERROR;

   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasMINF = KAL_TRUE;

   return MP4_PARSER_OK;
}



/*
DESCRIPTION
   Parse the Media Box.
INPUT
   size: The size of Media Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Parse error
*/

static MP4_Parser_Status mp4_parse_mdia(STMp4Parser *pstMp4Parser, kal_uint32 mdia_size)
{
   MP4_Parser_Status ret;
   kal_uint32 uCurPos;
   kal_uint32 uSizeHdlr;
   Parse_Box_Entry BoxInfo;

   /* Look for hdlr first.
   It's because some boxes under minf may depend on the hdlr,
   however, hdlr does not always come before minf.
   It also let us recognize the type of the track (video or audio)
   before we encounter sample table.
   */

   MP4_PARSER_FILE_GET_CUR_POS(uCurPos);
   if((ret=mp4_seek_atom(pstMp4Parser, BOX_TYPE_HDLR, mdia_size, &uSizeHdlr))!=MP4_PARSER_OK)
      return ret;
   if((ret=mp4_parse_hdlr(pstMp4Parser, uSizeHdlr))!=MP4_PARSER_OK)
      return ret;
   if((pstMp4Parser->eFSALErr=FSAL_Seek(pstMp4Parser->pstFSAL, uCurPos))!=FSAL_OK)
      return MP4_PARSER_PARSE_ERROR;

   /* Look for possible nodes of mdia's direct childs */
   while(mdia_size > 0) {

      if((ret=mp4_parse_box(pstMp4Parser, mdia_size,&BoxInfo))!=MP4_PARSER_OK)
         return ret;
      mdia_size -= BoxInfo.Len;
      BoxInfo.size -= BoxInfo.Len;

      switch(BoxInfo.type) {
      case BOX_TYPE_MDHD:
         if((ret=mp4_parse_mdhd(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            return ret;
         break;
      case BOX_TYPE_HDLR:
         if((ret=mp4_parse_hdlr(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            return ret;
         break;
      case BOX_TYPE_MINF:
         if((ret=mp4_parse_minf(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            return ret;
         break;
      default: /* unrecognized type, skip the box */
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, BoxInfo.size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
      }
      mdia_size -= BoxInfo.size;
   }

   if (mdia_size!=0)
      return MP4_PARSER_PARSE_ERROR;

   pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack].bHasMDIA = KAL_TRUE;

   return MP4_PARSER_OK;
}


/*
DESCRIPTION
   Parse the Track Box.
INPUT
   size: The size of Track Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Parse error
*/

static MP4_Parser_Status mp4_parse_trak(STMp4Parser *pstMp4Parser, kal_uint32 trak_size)
{
   MP4_Parser_Status ret = MP4_PARSER_OK;
   STMp4Track *prTrack;
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   /* look for possible nodes of trak's direct childs */

   /* Initialize Track Structure of Current Track */
   prTrack = &pstMp4Parser->stMp4Track[pstMp4Parser->bCurTrack];

   if(pstMp4Parser->bCurTrack>=MP4_NUM_TRACKS)
      return MP4_PARSER_TOO_MANY_TRACKS;
   kal_mem_set((void *)prTrack, 0, sizeof(STMp4Track));
   prTrack->mTrackStatus_parse = MP4_PARSER_OK;
   prTrack->mTrackStatus_box = MP4_PARSER_OK;
   while(trak_size > 0) {
      Parse_Box_Entry BoxInfo;
      if((ret=mp4_parse_box(pstMp4Parser, trak_size, &BoxInfo))!=MP4_PARSER_OK)
         return ret;
      trak_size -= BoxInfo.Len;
      BoxInfo.size -= BoxInfo.Len;

      switch(BoxInfo.type) {
      case BOX_TYPE_TKHD:
         //if((ret=mp4_parse_tkhd(pstMp4Parser, size))!=MP4_PARSER_OK)
         //   return ret;
         ret=mp4_parse_tkhd(pstMp4Parser, BoxInfo.size);  //for support decode if either track is valid.
         break;
      case BOX_TYPE_MDIA:
         //if((ret=mp4_parse_mdia(pstMp4Parser, size))!=MP4_PARSER_OK)
         //   return ret;
         ret=mp4_parse_mdia(pstMp4Parser, BoxInfo.size);  //for support decode if either track is valid.
         break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #if 0
      default: /* unrecognized type, skip the box */
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, BoxInfo.size))!=FSAL_OK)
         {
            //return MP4_PARSER_FILE_SEEK_ERROR;
            ret = MP4_PARSER_FILE_SEEK_ERROR;
            break;
         }
      }
      if(ret != MP4_PARSER_OK)
         break;
      trak_size -= BoxInfo.size;
   }

   if (trak_size!=0)
   {
      prTrack->mTrackStatus_parse = ret;

      //return MP4_PARSER_PARSE_TRAK_ERROR;
   }

#ifdef FEATURE_PHONE_LIMIT
   if (prTrack->handler_type == HDLR_TYPE_SOUN)
   {
      switch(pstMp4Parser->bAudioType[pstMp4Parser->bCurTrack])
      {
        case MP4_AUDIO_AAC:
        case MP4_AUDIO_AMR:
        case MP4_AUDIO_AMR_WB:
        case MP4_AUDIO_BSAC:
            if(pstMp4Parser->bAudioSamplingFreqIndex[pstMp4Parser->bCurTrack] <= 0x02)
            {
                prTrack->mTrackStatus_parse = MP4_PARSER_SAMPLING_FREQ_NOT_SUPPORT;
                #ifdef MP4_PARSER_TRC_LOG
                kal_trace(TRACE_GROUP_4, VID_TRC_MP4_PARSER_SAMPLING_FREQ_NOT_SUPPORT, __LINE__);
                #endif
            }
            break;
        case MP4_AUDIO_MP3:
        default:
            break;
      }
   }
#endif

   {
      kal_uint32 uHandlerType = prTrack->handler_type;
      if (HDLR_TYPE_SOUN == uHandlerType || HDLR_TYPE_VIDE == uHandlerType)
      {
         if(HDLR_TYPE_SOUN == uHandlerType)
            pstMp4Parser->uAudioTrackNum++;
         if(HDLR_TYPE_VIDE == uHandlerType)
            pstMp4Parser->uVideoTrackNum++;

         if(pstMp4Parser->bCurTrack>=MP4_NUM_TRACKS)
            return MP4_PARSER_TOO_MANY_TRACKS;
         if(prTrack->mTrackStatus_parse == MP4_PARSER_OK)
            prTrack->bHasParsed = KAL_TRUE;

         pstMp4Parser->bCurTrack++;
      }
   }

   return MP4_PARSER_OK;
}

#ifdef __VE_PARSE_TRANSFORMATION_INFO__
static MP4_Parser_Status mp4_parse_TRNS(STMp4Parser *pstMp4Parser, kal_int32 tnrs_size)
{
    kal_uint8 mirror;
    kal_uint16 angle;

    MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

    if(tnrs_size<4)
    {
        if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, tnrs_size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
        return MP4_PARSER_OK;
    }

    if((pstMp4Parser->eFSALErr=FSAL_Read_UINT16(pstMp4Parser->pstFSAL, &angle))!=FSAL_OK)
        return MP4_PARSER_FILE_READ_ERROR;
    pstMp4Parser->u2RotateAngle = angle;

    if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &mirror, 1))!=FSAL_OK)
        return MP4_PARSER_FILE_READ_ERROR;
    pstMp4Parser->u1HMirror = mirror;

    if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, &mirror, 1))!=FSAL_OK)
        return MP4_PARSER_FILE_READ_ERROR;
    pstMp4Parser->u1VMirror = mirror;

    tnrs_size -= 4;

    if(tnrs_size > 0)
    {
        if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, tnrs_size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
    }

    return MP4_PARSER_OK;
}
#endif

static MP4_Parser_Status mp4_parse_IUAM(STMp4Parser *pstMp4Parser, kal_int32 IUAM_size)
{
    kal_uint8 name[MP4_VALIDITY_CHK_LENGTH+1];

    MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

    if(IUAM_size >= MP4_VALIDITY_CHK_LENGTH)
    {
        if((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, name, MP4_VALIDITY_CHK_LENGTH))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
        name[MP4_VALIDITY_CHK_LENGTH] = 0; // String ending character
        if(strcmp((char *)name, "http://www.mediatek.com") == 0)
        {
            pstMp4Parser->bPrivateEncodeFormat = KAL_TRUE;
        }
        IUAM_size -= MP4_VALIDITY_CHK_LENGTH;
    }
    else
    {
        if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, IUAM_size))!=FSAL_OK)
        {
            return MP4_PARSER_FILE_SEEK_ERROR;
        }
        IUAM_size = 0;
    }

    while(IUAM_size > 8)
    {
        MP4_Parser_Status ret;
        Parse_Box_Entry BoxInfo;
        if((ret=mp4_parse_box(pstMp4Parser, IUAM_size, &BoxInfo))!=MP4_PARSER_OK)
           return ret;
        IUAM_size -= BoxInfo.Len;
        BoxInfo.size -= BoxInfo.Len;

        switch(BoxInfo.type) {
        #ifdef __VE_PARSE_TRANSFORMATION_INFO__
        case BOX_TYPE_TRNS:
            if((ret=mp4_parse_TRNS(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
                return ret;
        break;
        #endif

        default: /* unrecognized type, skip the box */
          if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, BoxInfo.size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
      }
      IUAM_size -= BoxInfo.size;
    }


    return MP4_PARSER_OK;
}

/*
DESCRIPTION
   Parse the Movie Box.
INPUT
   size: The size of Movie Box excluding Box
RETURN
   MP4_PARSER_OK: Successful
   other values: Error
*/

static MP4_Parser_Status mp4_parse_moov(STMp4Parser *pstMp4Parser, kal_uint32 moov_size)
{
   kal_int32 local_moov_size;
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_FILE_GET_CUR_POS(pstMp4Parser->uMOOVOffset);
   local_moov_size = moov_size;
   /* look for possible nodes of moov's direct childs */
   while(moov_size > 0) {
      MP4_Parser_Status ret;
      Parse_Box_Entry BoxInfo;

	  // terminate by source
      if (pstMp4Parser->fgQuickClose == KAL_TRUE)
         return MP4_PARSER_PARSE_QUICK_CLOSED;
	  
      if((ret=mp4_parse_box(pstMp4Parser, moov_size, &BoxInfo))!=MP4_PARSER_OK)
         return ret;
      moov_size -= BoxInfo.Len;
      BoxInfo.size -= BoxInfo.Len;

      switch(BoxInfo.type) {
      case BOX_TYPE_MVHD:
         if((ret=mp4_parse_mvhd(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            return ret;
         break;
      case BOX_TYPE_TRAK:
    #ifdef __VE_PRIRATE_3D_FORMAT__
      case BOX_TYPE_TRAK_CAP:
    #endif
         if((ret=mp4_parse_trak(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            return ret;
         break;
      #if !defined __LOW_COST_SUPPORT_COMMON__ || defined __MOT_SUPPORT__ || defined __VE_KMV_SUPPORT__
      case BOX_TYPE_UDTA:  // From 3GPP 26.244 V7.2.0 (2007-06),
                           //it should reside within the Movie box, but may reside within the Track box.
         if((ret=mp4_parse_udta(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            return ret;
         break;
      #endif

        case BOX_TYPE_IUAM:
        if((ret=mp4_parse_IUAM(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
        {
            return ret;
        }
        break;

      default: /* unrecognized type, skip the box */
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, BoxInfo.size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
      }
      moov_size -= BoxInfo.size;
   }

   if (moov_size!=0)
      return MP4_PARSER_PARSE_MOOVSIZE_ERROR;

   if(local_moov_size > 0)
      pstMp4Parser->bHasMOOV = KAL_TRUE;

   return MP4_PARSER_OK;
}


static MP4_Parser_Status mp4_parse_mdat(STMp4Parser *pstMp4Parser, kal_uint32 mdat_size)
{
   //kal_int32 local_moov_size;
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   MP4_PARSER_FILE_GET_CUR_POS(pstMp4Parser->uMDATOffset);
   if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, mdat_size))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   pstMp4Parser->bHasMDAT = KAL_TRUE;
   return MP4_PARSER_OK;
}


static MP4_Parser_Status post_processing_chktrack(STMp4Parser *pstMp4Parser, kal_uint8 currTrack, kal_int16 *iTrackError)
{
   MP4_Parser_Status ret;
   STMp4Track *prMP4Track;
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   if(currTrack >= MP4_NUM_TRACKS)
      return MP4_PARSER_TOO_MANY_TRACKS;

   *iTrackError = 0;
   prMP4Track = &pstMp4Parser->stMp4Track[currTrack];

   if (prMP4Track->bHasTKHD != KAL_TRUE){
      ret = MP4_PARSER_NO_TKHD;
      goto mp4_miss_box;
   }
   if (prMP4Track->bHasMDIA != KAL_TRUE){
      ret = MP4_PARSER_NO_MDIA;
      goto mp4_miss_box;
   }
   if (prMP4Track->bHasMDHD != KAL_TRUE){
      ret = MP4_PARSER_NO_MDHD;
      goto mp4_miss_box;
   }
   if (prMP4Track->bHasHDLR != KAL_TRUE){
      ret = MP4_PARSER_NO_HDLR;
      goto mp4_miss_box;
   }
   if (prMP4Track->bHasMINF != KAL_TRUE){
      ret = MP4_PARSER_NO_MINF;
      goto mp4_miss_box;
   }
   if (prMP4Track->bHasSTBL != KAL_TRUE){
      ret = MP4_PARSER_NO_STBL;
      goto mp4_miss_box;
   }
   if (prMP4Track->bHasSTSD != KAL_TRUE){
      ret = MP4_PARSER_NO_STSD;
      goto mp4_miss_box;
   }
   if (prMP4Track->bHasSTTS != KAL_TRUE){
      ret = MP4_PARSER_NO_STTS;
      goto mp4_miss_box;
   }else{
      if(prMP4Track->uTimeToSampleTableEntryCount == 0)
      {
         ret = MP4_PARSER_NO_STTS;
         goto mp4_miss_box;
      }
   }
   if (prMP4Track->bHasSTSC != KAL_TRUE){
      ret = MP4_PARSER_NO_STSC;
      goto mp4_miss_box;
   }else{
      if(prMP4Track->uSampleToChunkEntryCount == 0)
      {
         ret = MP4_PARSER_NO_STSC;
         goto mp4_miss_box;
      }
   }


   if (prMP4Track->bHasSTCO != KAL_TRUE){
      ret = MP4_PARSER_NO_STCO;
      goto mp4_miss_box;
   }else{
      if(prMP4Track->uChunkCount == 0)
      {
         ret = MP4_PARSER_NO_STCO;
         goto mp4_miss_box;
      }
   }

//   if (prMP4Track->uMediaDuration & 0x80000000){
//      ret = MP4_PARSER_PARSE_DURATION_ERROR;
//      goto mp4_miss_box;
//   }
   {
       kal_uint32 uTimeScale;
       uTimeScale = prMP4Track->uMediaTimeScale;
       if ((uTimeScale & 0x80000000) || (uTimeScale == 0)){
          ret = MP4_PARSER_PARSE_TIMESCALE_ERROR;
          goto mp4_miss_box;
       }
   }

   return MP4_PARSER_OK;
mp4_miss_box:
   *iTrackError = 1;
   prMP4Track->mTrackStatus_box = ret;
   return MP4_PARSER_OK;
}

static MP4_Parser_Status post_processing(STMp4Parser *pstMp4Parser)
{
   MP4_Parser_Status ret;
   kal_int16 iAudioTrackError,iVideoTrackError;
   kal_uint8 bAudio,bVideo;
   STMp4Track *prMP4VidTrack, *prMP4AudTrack;
   kal_uint32 i;

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

#ifdef MP4_PARSER_TRC_LOG_DEBUG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_POST_PROCESSING);
#endif

#ifdef __VE_MP43GP_MULTI_TRACK__
   for(i=0; i<MP4_NUM_TRACKS; i++)
   {
       if(pstMp4Parser->stMp4Track[i].handler_type == HDLR_TYPE_SOUN)
       {
           if(pstMp4Parser->bAudioType[i] != MP4_AUDIO_NONE)
           {
               iAudioTrackError = 1;
               prMP4AudTrack = &pstMp4Parser->stMp4Track[i];
               if(prMP4AudTrack->mTrackStatus_parse ==  MP4_PARSER_OK)
               {
                   if((ret = post_processing_chktrack(pstMp4Parser, i, &iAudioTrackError)) != MP4_PARSER_OK)
                       return ret;
               }
               if(iAudioTrackError)
                   pstMp4Parser->bAudioType[i] = MP4_AUDIO_NONE;
           }
       }
       else if(pstMp4Parser->stMp4Track[i].handler_type == HDLR_TYPE_VIDE)
       {
           if(pstMp4Parser->bVideoType[i] != MP4_VIDEO_NONE)
           {
               iVideoTrackError = 1;
               prMP4VidTrack = &pstMp4Parser->stMp4Track[i];
               if(prMP4VidTrack->mTrackStatus_parse ==  MP4_PARSER_OK)
               {
                   if((ret = post_processing_chktrack(pstMp4Parser, i, &iVideoTrackError)) != MP4_PARSER_OK)
                       return ret;
               }
               if(iVideoTrackError)
                   pstMp4Parser->bVideoType[i] = MP4_VIDEO_NONE;
           }
       }
   }

   bAudio = MP4_RESERVED_TRACK_NO;
   bVideo = MP4_RESERVED_TRACK_NO;
   for(i=0; i<MP4_NUM_TRACKS; i++)
   {
       if(pstMp4Parser->bVideoType[i] != MP4_VIDEO_NONE)
       {
           bVideo = i;
       }
       if(pstMp4Parser->bAudioType[i] != MP4_AUDIO_NONE)
       {
           bAudio = i;
       }
       if((bVideo!=MP4_RESERVED_TRACK_NO) && (bAudio!=MP4_RESERVED_TRACK_NO))
       {
           break;
       }
   }
   if((!(bVideo==MP4_RESERVED_TRACK_NO)) || (!(bAudio==MP4_RESERVED_TRACK_NO)))
   {
       /* Check the existence of mandatory atoms */
       pstMp4Parser->bHasTRAK = KAL_TRUE;
   }
#else
   {
       kal_uint8 bAudioTrack,bVideoTrack;

       iAudioTrackError = 1;
       iVideoTrackError = 1;
       bAudio = bVideo = 0;

       bAudioTrack = pstMp4Parser->bAudioTrack;
       bVideoTrack = pstMp4Parser->bVideoTrack;

       prMP4AudTrack = &pstMp4Parser->stMp4Track[bAudioTrack];
       prMP4VidTrack = &pstMp4Parser->stMp4Track[bVideoTrack];
       if((bAudioTrack != MP4_RESERVED_TRACK_NO) && (bAudioTrack < MP4_NUM_TRACKS))
          bAudio = 1;
       if((bVideoTrack != MP4_RESERVED_TRACK_NO) && (bVideoTrack < MP4_NUM_TRACKS))
          bVideo = 1;

       if((pstMp4Parser->bAudioType[bAudioTrack] != MP4_AUDIO_NONE) && (pstMp4Parser->bAudioTrack != MP4_RESERVED_TRACK_NO))
       {
          if(prMP4AudTrack->mTrackStatus_parse ==  MP4_PARSER_OK)
          {
             if((ret = post_processing_chktrack(pstMp4Parser, bAudioTrack, &iAudioTrackError)) != MP4_PARSER_OK)
                return ret;
          }
       }
       if((pstMp4Parser->bVideoType[bVideoTrack] != MP4_VIDEO_NONE) && (pstMp4Parser->bVideoTrack != MP4_RESERVED_TRACK_NO))
       {
          if(prMP4VidTrack->mTrackStatus_parse ==  MP4_PARSER_OK)
          {
             if((ret = post_processing_chktrack(pstMp4Parser, bVideoTrack, &iVideoTrackError)) != MP4_PARSER_OK)
                return ret;
          }
       }

       if(iVideoTrackError)
          pstMp4Parser->bVideoType[bVideoTrack] = MP4_VIDEO_NONE;
       if(iAudioTrackError)
          pstMp4Parser->bAudioType[bAudioTrack] = MP4_AUDIO_NONE;

       if((!iAudioTrackError) || (!iVideoTrackError))
       {
             /* Check the existence of mandatory atoms */
             pstMp4Parser->bHasTRAK = KAL_TRUE;
       }
       else
       {
          if((iVideoTrackError) && (bVideo))
          {
             if((ret = prMP4VidTrack->mTrackStatus_parse) != MP4_PARSER_OK)
                return ret;
             if((ret = prMP4VidTrack->mTrackStatus_box) != MP4_PARSER_OK)
                return ret;
          }
          if((iAudioTrackError) && (bAudio))
          {
             if((ret = prMP4AudTrack->mTrackStatus_parse) != MP4_PARSER_OK)
                return ret;
             if((ret = prMP4AudTrack->mTrackStatus_box) != MP4_PARSER_OK)
                return ret;
          }
       }
   }
#endif

   /// Check the existence of mandatory atoms
   if (pstMp4Parser->bHasMOOV != KAL_TRUE)
      return MP4_PARSER_NO_MOOV;
   if (pstMp4Parser->bHasMVHD != KAL_TRUE)
      return MP4_PARSER_NO_MVHD;
   if (pstMp4Parser->bHasTRAK != KAL_TRUE)
      return MP4_PARSER_NO_TRAK;

   /// Prepare AAC frame header if necessary
   if ((ret=prepareAACFrameHeader(pstMp4Parser))!=MP4_PARSER_OK)
      return ret;

   return MP4_PARSER_OK;
}
#ifdef MP4PARSER_ENABLE_PARSE_FRONT_OF_FTYP
MP4_Parser_Status mp4_parse_ftypoffset(STMp4Parser *pstMp4Parser, kal_int32 FileLen, kal_int32 *pftypoffset)
{
   MP4_Parser_Status ret = MP4_PARSER_OK;
   kal_uint32 chkftyp = 0,chkftyptemp = 0;
   kal_uint32 cur_pos;
   kal_int32  ParsingLength;


   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL || pftypoffset!=NULL);

   if(FileLen < MP4_MAX_GARBAGE_SIZE)
      ParsingLength = FileLen;
   else
      ParsingLength = MP4_MAX_GARBAGE_SIZE;

   while(ParsingLength > 0)
   {
      if((pstMp4Parser->eFSALErr=FSAL_Read_UINT(pstMp4Parser->pstFSAL, &chkftyptemp))!=FSAL_OK)
         return MP4_PARSER_FILE_READ_ERROR;
      if ((pstMp4Parser->eFSALErr = FSAL_GetCurPos(pstMp4Parser->pstFSAL, &cur_pos)) != FSAL_OK )
         return MP4_PARSER_FILE_ACCESS_ERROR;
	  #ifdef __VE_MOT_DECRYPTION__
	      if((pstMp4Parser->OpenType == MED_MODE_MOT_PREVIEW) || (pstMp4Parser->OpenType == MED_MODE_MOT_FILE))
	      {
	          MotUtilityCrackTheCode(chkftyptemp,&chkftyp,1);
	      }
	  #endif
      if(chkftyp == BOX_TYPE_FTYP)
      {
         if(cur_pos > 7)
         {
            *pftypoffset = cur_pos - 8;
            return MP4_PARSER_OK;
         }
      }
      if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstMp4Parser->pstFSAL, (cur_pos-3) ))!=FSAL_OK)
         return MP4_PARSER_FILE_SEEK_ERROR;
      ParsingLength --;
   }
   return MP4_PARSER_PARSE_NO_FTYPHEADER;
}
#endif //MP4PARSER_ENABLE_PARSE_FRONT_OF_FTYP

#ifdef MP4_PARSER_TRC_LOG_DEBUG
static MP4_Parser_Status mp4_parse_fileinfo(STMp4Parser *pstMp4Parser)
{
	 STMp4Parser *ptr = pstMp4Parser;
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_FILEINFO_TRACK,ptr->bCurTrack,ptr->bAudioTrack,ptr->bVideoTrack);
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_FILEINFO_MVHD,ptr->timescale,ptr->duration,ptr->next_track_ID);
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_FILEINFO_MEDIATYPE,ptr->bAudioType[ptr->bAudioTrack],ptr->bVideoType[ptr->bVideoTrack],ptr->bAudioObjectType);
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_FILEINFO_14496_3,ptr->bAudioSamplingFreqIndex[ptr->bAudioTrack],ptr->uAudioAvgBitrate,ptr->uAudioMaxBitrate);
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_FILEINFO_DECDESCRIPTOR,ptr->uAudioAvgBitrate,ptr->uAudioMaxBitrate,ptr->bFramesPerSample);
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_FILEINFO_BSAC,ptr->uNumOfSubFrame,ptr->uLayerLength);
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_FILEINFO_CHKATOMS,ptr->bHasMOOV,ptr->bHasMVHD,ptr->bHasTRAK,ptr->bHasUDTA,ptr->bHasILST,ptr->bHasMETA);
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_FILEINFO_AUDIOREAD,ptr->uAudioReadSampleNo,ptr->uAudioReadSampleOffset,ptr->uAudioReadSampleFileOffset,ptr->uAudioSeekPointTime);
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_FILEINFO_FILEOFFSET,ptr->uMOOVOffset,ptr->uVOSOffset,ptr->uVOSSize,ptr->uOdkmSize,ptr->odkmOffset);
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_FILEINFO_H264,ptr->stMp4AVC.uParameterSetOffset,ptr->stMp4AVC.uParameterSetSize,ptr->stMp4AVC.uConfigOffset,ptr->stMp4AVC.uConfigSize);
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_FILEINFO_PLAYTIME,ptr->uPlaybackTimeBase,ptr->uPreviousInterruptCount);
}
#endif
/*--------- Public Functions ---------*/

/*
DESCRIPTION
   Parse a MP4/3GPP file.
RETURN
   MP4_PARSER_OK: Successful
   other values: Not a correct MP4/3GPP file
*/
MP4_Parser_Status mp4_parse_core(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL)
{
   MP4_Parser_Status ret=MP4_PARSER_OK;
   kal_uint32 uFileLeftLen;
   kal_int32 iFTYPOffset;
   kal_uint32 i;
   Parse_Box_Entry BoxInfo;
#ifdef	__VE_PGDL_SUPPORT_YOUTUBE__
   kal_uint32 count=0;
#endif

   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL || pstFSAL!=NULL);

   //memset(pstMp4Parser,0,sizeof(STMp4Parser));   //remove to MP4_Parse

   /* Initialize Structure */
   pstMp4Parser->bCurTrack = 0;
   pstMp4Parser->bAudioTrack = MP4_RESERVED_TRACK_NO;
   pstMp4Parser->bVideoTrack = MP4_RESERVED_TRACK_NO;
   for(i=MP4_NUM_TRACKS; i!=0; i--)
   {
       pstMp4Parser->bAudioType[i-1] = MP4_AUDIO_NONE;
       pstMp4Parser->bVideoType[i-1] = MP4_VIDEO_NONE;
   }
   pstMp4Parser->bHasMOOV = KAL_FALSE;
   pstMp4Parser->bHasMDAT = KAL_FALSE;
   pstMp4Parser->bHasMVHD = KAL_FALSE;
   pstMp4Parser->bHasTRAK = KAL_FALSE;
   pstMp4Parser->bHasUDTA = KAL_FALSE;
   pstMp4Parser->uParserFinish = 0;
   pstMp4Parser->u4KMVFileLen = 0;
   pstMp4Parser->u4UUIDFileLen = 0;
   pstMp4Parser->bAddADTSFrameHeader = KAL_FALSE;
   pstMp4Parser->bAddADIFFrameHeader = KAL_FALSE;
   if(pstMp4Parser->bHasUDTAExtBuff)
   {
       pstMp4Parser->pUDTAExtInfo->bHasILSTData = KAL_FALSE;
   }
   iFTYPOffset = 0;
#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_PARSE_START);
#endif
   pstMp4Parser->pstFSAL = pstFSAL;
   if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstFSAL, 0))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

   if ((pstMp4Parser->eFSALErr=FSAL_GetFileSize(pstFSAL, (kal_uint32*)&uFileLeftLen))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;

#ifdef MP4PARSER_ENABLE_PARSE_FRONT_OF_FTYP
   /* Parsing to find the begin of FTYP */
   if(uFileLeftLen > 7)
   {
      if ((ret=mp4_parse_box(pstMp4Parser, uFileLeftLen, &BoxInfo))!=MP4_PARSER_OK)
         BoxInfo.size-=BoxInfo.Len;
         return ret;
      if(BoxInfo->type != BOX_TYPE_FTYP)
      {
         if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstMp4Parser->pstFSAL, 0))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
         if ((ret=mp4_parse_ftypoffset(pstMp4Parser, uFileLeftLen,&iFTYPOffset))!=MP4_PARSER_OK)
            return ret;
      }
   }
   else
      return MP4_PARSER_PARSE_FILESIZE_ERROR;


   if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstMp4Parser->pstFSAL, iFTYPOffset))!=FSAL_OK)
      return MP4_PARSER_FILE_SEEK_ERROR;
#endif //MP4PARSER_ENABLE_PARSE_FRONT_OF_FTYP

#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_PARSE_GETFILESIZE,uFileLeftLen);
#endif
   uFileLeftLen -= iFTYPOffset;

   while(uFileLeftLen > 7) {  // uFileLeftLen should >= 8 to guarantee the existence of chunk ID and chunk zise

      // terminate by source
      if (pstMp4Parser->fgQuickClose == KAL_TRUE)
         return MP4_PARSER_PARSE_QUICK_CLOSED;

      if ((ret=mp4_parse_box(pstMp4Parser, uFileLeftLen,&BoxInfo))!=MP4_PARSER_OK)
         return ret;


#ifdef	__VE_PGDL_SUPPORT_YOUTUBE__

      if(count<512)
      {
	 if((ret=MotUtilityPGDLParseBox(&BoxInfo,pstMp4Parser->OpenType))!=MP4_PARSER_OK)	
         return ret;
      }

      count= count+BoxInfo.size;
#endif


#ifdef __VE_KMV_SUPPORT__
      if(BOX_TYPE_STCO_CAP == BoxInfo.size)
      {
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, uFileLeftLen))!=FSAL_OK)
             return MP4_PARSER_FILE_SEEK_ERROR;
      }
      else
#endif

	  {
          pstMp4Parser->u4KMVFileLen += BoxInfo.size;

      uFileLeftLen -= BoxInfo.Len;
      BoxInfo.size -= BoxInfo.Len;

      switch (BoxInfo.type) {
      case BOX_TYPE_FTYP: {
         if ((ret=mp4_parse_ftyp(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            return ret;
         break;
      }
      case BOX_TYPE_MOOV: {
         if ((ret=mp4_parse_moov(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            return ret;
         break;
      }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #if 0

      case BOX_TYPE_MDAT: {
         if ((ret=mp4_parse_mdat(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            return ret;
         break;
      }

      default: /* unrecognized type, skip the box */
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, BoxInfo.size))!=FSAL_OK)
            return MP4_PARSER_FILE_SEEK_ERROR;
      }
      }

      if ((kal_uint32)uFileLeftLen < BoxInfo.size)
         break;
      uFileLeftLen -= BoxInfo.size;
#if MP4_PARSER_VERBOSE
      printf("uFileLeftLen=%d\n", uFileLeftLen);
#endif
   }
#ifdef MP4_PARSER_TRC_LOG_DEBUG
   mp4_parse_fileinfo(pstMp4Parser);
#endif
   if ((ret = post_processing(pstMp4Parser)) != MP4_PARSER_OK)
      return ret;

   if (uFileLeftLen != 0)
   {
   	  pstMp4Parser->uParserFinish = 2;
   	  ret = MP4_PARSER_WARNING_TRAILING_GARBAGE;
      goto mp4_parse_core_end;
   }

#if defined(MP4_DECODE)
   if (pstMp4Parser->bAudioType[pstMp4Parser->bAudioTrack] == MP4_AUDIO_AAC) {
      if (0 == Media_A2V_GetPlaybackInterruptTimeScaleFxdPnt(MEDIA_FORMAT_AAC,
                                                 pstMp4Parser->bAudioSamplingFreqIndex[pstMp4Parser->bAudioTrack])) {
         pstMp4Parser->bAudioType[pstMp4Parser->bAudioTrack] = MP4_AUDIO_NONE;
         pstMp4Parser->bAudioTrack = MP4_RESERVED_TRACK_NO;

      }
   }
#endif // #if defined(MP4_DECODE)

   pstMp4Parser->uParserFinish = 1;
   ret = MP4_PARSER_OK;
mp4_parse_core_end:
#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_PARSE_FINISH, pstMp4Parser->uParserFinish, (int)pstMp4Parser->bAudioTrack, (int)pstMp4Parser->bVideoTrack);
#endif
   return ret;
}

/*============================  Public Functions ============================*/

MP4_Parser_Status MP4_Parse(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL)
{
   MP4_Parser_Status ret;
   med_mode_enum OpenType;
   kal_bool fgQuickClose;
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);
   OpenType = pstMp4Parser->OpenType;
   fgQuickClose = pstMp4Parser->fgQuickClose;
   memset(pstMp4Parser,0,sizeof(STMp4Parser));
   pstMp4Parser->bHasUDTAExtBuff = KAL_FALSE;
   pstMp4Parser->OpenType = OpenType;
   pstMp4Parser->fgQuickClose = fgQuickClose;

   ret = mp4_parse_core(pstMp4Parser, pstFSAL);
   return ret;
}

MP4_Parser_Status MP4_Parse_UDTAExt(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL, void *pUDTAExtBuffer, kal_int32 UDTAExtBufSize)
{
   MP4_Parser_Status ret;
   med_mode_enum OpenType;
   kal_bool fgQuickClose;
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL || pUDTAExtBuffer!=NULL);
   OpenType = pstMp4Parser->OpenType;
   fgQuickClose = pstMp4Parser->fgQuickClose;
   memset(pstMp4Parser,0,sizeof(STMp4Parser));
   if(UDTAExtBufSize < sizeof(UDTAInfo))
      return MP4_PARSER_EXTMETA_BUFFERSIZE_ERROR;
   memset(pUDTAExtBuffer,0,sizeof(UDTAInfo));
   pstMp4Parser->pUDTAExtInfo = (UDTAInfo*)pUDTAExtBuffer;
   pstMp4Parser->bHasUDTAExtBuff = KAL_TRUE;
   pstMp4Parser->OpenType = OpenType;
   pstMp4Parser->fgQuickClose = fgQuickClose;

   ret = mp4_parse_core(pstMp4Parser, pstFSAL);
   return ret;
}

#ifdef __VE_MP43GP_MULTI_TRACK__
kal_uint32 MP4_GetTrackNum(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType)
{
    if(eTrackType == MP4_TRACK_AUDIO)
    {
        return pstMp4Parser->uAudioTrackNum;
    }
    else if(eTrackType == MP4_TRACK_VIDEO)
    {
        return pstMp4Parser->uVideoTrackNum;
    }
    else
    {
        ASSERT(0);
        return 0;
    }
}

void MP4_SetTrackIndex(STMp4Parser *pstMp4Parser, kal_uint32 track_id)
{
    if(pstMp4Parser->stMp4Track[track_id].handler_type == HDLR_TYPE_VIDE)
    {
        pstMp4Parser->bVideoTrack = track_id;
    }
    else if(pstMp4Parser->stMp4Track[track_id].handler_type == HDLR_TYPE_SOUN)
    {
        pstMp4Parser->bAudioTrack = track_id;
    }
}

/* Return the n-th track id of type eTrackType */
kal_uint32 MP4_GetTrackNoByTypeIdx(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType, kal_uint32 n)
{
    kal_uint32 i, j;
    kal_uint32 matchtype = HDLR_TYPE_SOUN;

    if(eTrackType == MP4_TRACK_VIDEO)
    {
        matchtype = HDLR_TYPE_VIDE;
    }

    j = 0;
    for(i=0; i<MP4_NUM_TRACKS; i++)
    {
        if(pstMp4Parser->stMp4Track[i].handler_type == matchtype)
        {
            if(j==n)
            {
                break;
            }
            j++;
        }
    }

    return i;
}

#endif

#ifdef __VE_PRIRATE_3D_FORMAT__
kal_bool MP4_IsVideo3DTrack(STMp4Parser *pstMp4Parser, kal_uint32 track_id)
{
    return pstMp4Parser->stMp4Track[track_id].bPrivate3DFormat;
}
#endif

#ifdef __VE_MM_DCM_SUPPORT__
#pragma arm section code, rodata
#endif

MP4_Parser_Status MP4_MetaHasAudioTrack(STMp4Parser *pstMp4Parser, kal_bool *pfAudTrack)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   if(pstMp4Parser->bAudioTrack == MP4_RESERVED_TRACK_NO)
      *pfAudTrack = KAL_FALSE;
   else
      *pfAudTrack = KAL_TRUE;

   return MP4_PARSER_OK;

}

MP4_Parser_Status MP4_MetaHasVideoTrack(STMp4Parser *pstMp4Parser, kal_bool *pfVidTrack)
{
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL);

   if(pstMp4Parser->bVideoTrack == MP4_RESERVED_TRACK_NO)
      *pfVidTrack = KAL_FALSE;
   else
      *pfVidTrack = KAL_TRUE;

   return MP4_PARSER_OK;

}

void MP4_Parser_Clone(STMp4Parser *pstMp4Parser_Src, STMp4Parser *pstMp4Parser_Dst, STFSAL *pstFSAL_Dst)
{
   MP4_PARSER_ASSERT_NO_RET_VAL(pstMp4Parser_Src!=NULL || pstMp4Parser_Dst!=NULL || pstFSAL_Dst!=NULL);
   kal_mem_cpy(pstMp4Parser_Dst, pstMp4Parser_Src, sizeof(STMp4Parser));
   pstMp4Parser_Dst->pstFSAL = pstFSAL_Dst;
}

#ifdef PGDL_SUPPORT
MP4_Parser_Status MP4_GetMdatBoxOffset(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL, kal_uint32 *puMetaOffset)
{
   MP4_Parser_Status ret=MP4_PARSER_OK;
   kal_uint32 uFileLeftLen,uFileLen_final;
   kal_uint32 uSizeTmp;
   Parse_Box_Entry BoxInfo;
#ifdef MP4_PARSER_TRC_LOG
   kal_uint32 uFileLen_backup = 0, moovbox_size = 0, MetaOffset = 0;
#endif
   kal_uint32 count=0;


   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL || pstFSAL!=NULL);

   pstMp4Parser->pstFSAL = pstFSAL;
   if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstFSAL, 0))!=FSAL_OK)
   {
      ret = MP4_PARSER_FILE_SEEK_ERROR;
      goto MP4_GetMdatBoxOffset_End;
   }
   if ((pstMp4Parser->eFSALErr=FSAL_GetFileSize(pstFSAL, (kal_uint32*)&uFileLeftLen))!=FSAL_OK)
   {
      ret = MP4_PARSER_FILE_SEEK_ERROR;
      goto MP4_GetMdatBoxOffset_End;
   }
#ifdef MP4_PARSER_TRC_LOG
   uFileLen_backup = uFileLeftLen;
#endif
   uSizeTmp = 0;
   while(uFileLeftLen > 7) {  // uFileLeftLen should >= 8 to guarantee the existence of chunk ID and chunk zise

            // terminate by source
      if (pstMp4Parser->fgQuickClose == KAL_TRUE)
         return MP4_PARSER_PARSE_QUICK_CLOSED;

      if ((ret=mp4_parse_box(pstMp4Parser, uFileLeftLen, &BoxInfo))!=MP4_PARSER_OK)
         goto MP4_GetMdatBoxOffset_End;
      uFileLeftLen -= BoxInfo.Len;
      BoxInfo.size-=BoxInfo.Len;

#ifdef	__VE_PGDL_SUPPORT_YOUTUBE__

      if(count<512)
      {
	     if((ret=MotUtilityPGDLParseBox(&BoxInfo,pstMp4Parser->OpenType))!=MP4_PARSER_OK)	
             return ret;
      }

      count= count+BoxInfo.size;
#endif

      switch (BoxInfo.type) {
      case BOX_TYPE_FTYP: {
         if ((ret=mp4_parse_ftyp(pstMp4Parser, BoxInfo.size))!=MP4_PARSER_OK)
            goto MP4_GetMdatBoxOffset_End;
         break;
      }
      case BOX_TYPE_MOOV: {
         MP4_PARSER_FILE_GET_CUR_POS(uSizeTmp);
		 uSizeTmp += BoxInfo.size;
#ifdef MP4_PARSER_TRC_LOG
		 moovbox_size = BoxInfo.size;
#endif
		 *puMetaOffset = uSizeTmp;
		 ret = MP4_PARSER_OK;
		 goto MP4_GetMdatBoxOffset_End;
      }
      default: /* unrecognized type, skip the box */
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, BoxInfo.size))!=FSAL_OK)
         {
            ret = MP4_PARSER_FILE_SEEK_ERROR;
            goto MP4_GetMdatBoxOffset_End;
         }
      }
      if ((kal_uint32)uFileLeftLen < BoxInfo.size)
         break;
      uFileLeftLen -= BoxInfo.size;
   }
   ret = MP4_PARSER_NO_MOOV;
MP4_GetMdatBoxOffset_End:
#ifdef MP4_PARSER_TRC_LOG
   MetaOffset = *puMetaOffset;
#endif
   if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstFSAL, 0))!=FSAL_OK)
   {
      ret = MP4_PARSER_FILE_SEEK_ERROR;
   }
   uFileLen_final = 0;
   if ((pstMp4Parser->eFSALErr=FSAL_GetFileSize(pstFSAL, (kal_uint32*)&uFileLen_final))!=FSAL_OK)
   {
      ret = MP4_PARSER_FILE_SEEK_ERROR;
   }

#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_GETMDATBOXOFFSET, (int)ret, MetaOffset, uFileLen_backup, uFileLen_final, moovbox_size);
#endif

   return ret;
}
#endif /* defined(PGDL_SUPPORT) */

MP4_Parser_Status MP4_IsPDProfile(STMp4Parser *pstMp4Parser, STFSAL *pstFSAL, kal_bool *pfPD)
{
   MP4_Parser_Status ret=MP4_PARSER_OK;
   kal_uint32 uFileLeftLen;
   kal_int32 iFTYP,iMOOV;
   kal_uint32 major_brand, compatible_brand, ftyp_residual;
#ifdef MP4_PARSER_TRC_LOG
   kal_uint32 moovbox_size, uFileLen_backup;
#endif
   kal_uint32 ParseUsedSize;
   Parse_Box_Entry BoxInfo;
   MP4_PARSER_CHECK_ARG(pstMp4Parser!=NULL || pstFSAL!=NULL);

   iFTYP = 0;
   iMOOV = 0;
   major_brand = 0;
   compatible_brand = 0;
   ftyp_residual = 0;
#ifdef MP4_PARSER_TRC_LOG
   uFileLen_backup = 0;
   moovbox_size = 0;
#endif
   ParseUsedSize = 0;
   pstMp4Parser->pstFSAL = pstFSAL;
   if ((pstMp4Parser->eFSALErr=FSAL_Seek(pstFSAL, 0))!=FSAL_OK)
   {
      ret = MP4_PARSER_FILE_SEEK_ERROR;
      goto MP4_IsPDProfile_End;
   }

   if ((pstMp4Parser->eFSALErr=FSAL_GetFileSize(pstFSAL, (kal_uint32*)&uFileLeftLen))!=FSAL_OK)
   {
      ret = MP4_PARSER_FILE_SEEK_ERROR;
      goto MP4_IsPDProfile_End;
   }
#ifdef MP4_PARSER_TRC_LOG
   uFileLen_backup = uFileLeftLen;
#endif
   *pfPD = KAL_FALSE;
   while(uFileLeftLen > 7) {  // uFileLeftLen should >= 8 to guarantee the existence of chunk ID and chunk zise

      if ((ret=mp4_parse_box(pstMp4Parser, uFileLeftLen, &BoxInfo))!=MP4_PARSER_OK)
         goto MP4_IsPDProfile_End;
      uFileLeftLen -= BoxInfo.Len;
      ParseUsedSize += BoxInfo.Len;
      BoxInfo.size-=BoxInfo.Len;

      switch (BoxInfo.type) {
      case BOX_TYPE_FTYP: {


         if ((BoxInfo.size<8) || (uFileLeftLen < 8))
         {
            ret = MP4_PARSER_PARSE_ERROR;
            goto MP4_IsPDProfile_End;
         }

         if ((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, (kal_uint8 *)&major_brand, 4))!=FSAL_OK)
         {
            ret = MP4_PARSER_FILE_READ_ERROR;
            goto MP4_IsPDProfile_End;
         }
         ftyp_residual = BoxInfo.size - 4;

        // "3gr6" , "3gp6" , "3gp5"
		 if((major_brand == MAJOR_BRAND_3gr6) ||
		 	 (major_brand == MAJOR_BRAND_3gp6) ||
		 	 (major_brand == MAJOR_BRAND_3gp4) ||
		 	 //(major_brand == MAJOR_BRAND_isom) ||
		 	 (major_brand == MAJOR_BRAND_3gp5)     )
	 {
            iFTYP = 1;
         }
         else
         {
            //minor brand
            if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, 4))!=FSAL_OK)
            {
                ret = MP4_PARSER_FILE_SEEK_ERROR;
                goto MP4_IsPDProfile_End;
            }
            ftyp_residual -= 4;
            //compatible brand
            while(ftyp_residual >= 4)
            {
              if ((pstMp4Parser->eFSALErr=FSAL_Read_Bytes(pstMp4Parser->pstFSAL, (kal_uint8 *)&compatible_brand, 4))!=FSAL_OK)
              {
                ret = MP4_PARSER_FILE_READ_ERROR;
                goto MP4_IsPDProfile_End;
              }
              ftyp_residual -= 4;
              if((compatible_brand == MAJOR_BRAND_3gr6) ||
		 	     (compatible_brand == MAJOR_BRAND_3gp6) ||
		 	     (compatible_brand == MAJOR_BRAND_3gp4) ||
		 	     (compatible_brand == MAJOR_BRAND_isom) ||
		 	     (compatible_brand == MAJOR_BRAND_3gp5) ||
		 	     (compatible_brand == SAMPLE_FMT_AVC1))
		       {
                   iFTYP = 1;
                   break;
               }
            }
         }

         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, ftyp_residual))!=FSAL_OK)
         {
            ret = MP4_PARSER_FILE_SEEK_ERROR;
            goto MP4_IsPDProfile_End;
         }
		 //else
			//*pfPD = KAL_FALSE;

         //return MP4_PARSER_OK;
         break;
      }

      case BOX_TYPE_MOOV: {
         if ((BoxInfo.size<8) || (uFileLeftLen < 8))
         {
            ret = MP4_PARSER_PARSE_ERROR;
            goto MP4_IsPDProfile_End;
         }

         iMOOV = 1;
#ifdef MP4_PARSER_TRC_LOG
         moovbox_size = BoxInfo.size;
#endif
         break;
      }

      default: /* unrecognized type, skip the box */
         if((pstMp4Parser->eFSALErr=FSAL_Skip_Bytes(pstMp4Parser->pstFSAL, BoxInfo.size))!=FSAL_OK)
         {
            ret = MP4_PARSER_FILE_SEEK_ERROR;
            goto MP4_IsPDProfile_End;
         }
      }
      //if ((kal_uint32)uFileLeftLen < size)
      //   break;
      uFileLeftLen -= BoxInfo.size;
      ParseUsedSize += BoxInfo.size;

      if(iFTYP & iMOOV)
      {
         *pfPD = KAL_TRUE;
         ret = MP4_PARSER_OK;
         break;
      }
      else
         ret = MP4_PARSER_PARSE_ERROR;
   }

MP4_IsPDProfile_End:
#ifdef MP4_PARSER_TRC_LOG
   kal_trace(TRACE_GROUP_4, MP4PARSER_TRC_MP4_IsPDProfile, (int)ret, major_brand,(int)*pfPD,uFileLen_backup, moovbox_size);
#endif
   return ret;
}

#ifdef __VE_MP43GP_MULTI_TRACK__
kal_uint32 MP4_GetCurTrackID(STMp4Parser *pstMp4Parser, MP4_Track_Type eTrackType)
{
    kal_uint32 u4Ret = MP4_RESERVED_TRACK_NO;

    u4Ret = pstMp4Parser->bVideoTrack;
    if(eTrackType == MP4_TRACK_AUDIO)
    {
        u4Ret = pstMp4Parser->bAudioTrack;
    }
    return u4Ret;
}

MP4_Track_Type MP4_GetTrackType(STMp4Parser *pstMp4Parser, kal_uint32 track_id)
{
    MP4_Track_Type eRet = MP4_TRACK_AUDIO;

    if(pstMp4Parser->stMp4Track[track_id].handler_type == HDLR_TYPE_VIDE)
    {
        eRet = MP4_TRACK_VIDEO;
    }
    return eRet;
}
#endif

#ifdef __VE_PRIRATE_3D_FORMAT__
kal_uint32 MP4_Get3DTrackID(STMp4Parser *pstMp4Parser)
{
    kal_uint32 i;
    kal_uint32 u4Ret = MP4_RESERVED_TRACK_NO;

    for(i=0; i<MP4_NUM_TRACKS; i++)
    {
        // Find the 1st non-3D video track
        if((pstMp4Parser->stMp4Track[i].handler_type == HDLR_TYPE_VIDE) &&
           (pstMp4Parser->stMp4Track[i].bPrivate3DFormat == KAL_TRUE))
        {
            u4Ret = i;
            break;
        }
    }
    return u4Ret;
}
#endif

#endif //(__M3GPMP4_FILE_FORMAT_SUPPORT__)

