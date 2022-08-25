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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   exif.c
 *
 * Project:
 * --------
 *   MT6226,MT6227,MT6228,MT6229
 *
 * Description:
 * ------------
 *   This file is intends for Exif encoder.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if (defined(EXIF_SUPPORT) || defined(PICTBRIDGE_SUPPORT))
#include <stdio.h>
#include <string.h>

#include "exif.h"
#include "exif_table.h"

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "dcl_rtc.h"
#include "fs_type.h"
#include "fsal.h"
#include "dcl.h"


static STFSAL exif_FSAL;
static kal_uint32 exif_FileSize;


static kal_bool _exif_get_next_marker(kal_uint16* marker)
{
   kal_uint8 byte0=0,byte1=0;
   
   //printf("exif_FileSize:%d\n",exif_FileSize);
   
   if(exif_FSAL.uFileOffset>exif_FileSize) return KAL_FALSE;
   
   while(FSAL_Read_Bytes(&exif_FSAL, &byte1,1)==FSAL_OK)
   {
      //printf("exif_FSAL.uFileOffset: %x, byte0:%x, byte1:%x\n",exif_FSAL.uFileOffset,byte0,byte1);
      if(byte0==0xff && byte1!=0xff) 
      {
         (*marker)=(byte0<<8) | byte1 ;
         //printf(" getMarker %x%x\n",byte0,byte1);
         return KAL_TRUE;
      }
      byte0=byte1;
   }
   return KAL_FALSE;
}


//--Read uint16 as big endian--
static FSAL_Status _exif_direct_read_uint16(kal_uint16 *pwValue)
{
   kal_uint8 data[2];
   FSAL_Status ret;
   
   if(exif_FSAL.uFileOffset+2>exif_FileSize) return FSAL_READ_ERROR;
   
   if((ret=FSAL_Read_Bytes(&exif_FSAL, data, 2))!=FSAL_OK)
      return ret;
   
   *pwValue = (kal_uint16)((data[0]<<8) + (data[1]));
   
   return FSAL_OK;
}


static FSAL_Status _exif_seek_buffer(kal_uint32 offset, kal_uint8 ref)
{
   if(ref==FS_FILE_BEGIN)
   {
      if(offset<exif_FileSize)
         return FSAL_Seek(&exif_FSAL,offset);	 
      else
         return FSAL_SEEK_ERROR;
   }
   else if(ref==FS_FILE_CURRENT)
   {
      if(exif_FSAL.uFileOffset+offset<exif_FileSize) 
         return FSAL_Seek(&exif_FSAL,exif_FSAL.uFileOffset+offset);
      else
         return FSAL_SEEK_ERROR;
   }
   else
      return FSAL_SEEK_ERROR;
}


#if(defined(EXIF_SUPPORT))

extern kal_char* release_verno(void);
extern void exif_update_MTK_para_struct(exif_MTK_para_struct *exif_MTK_para);

exif_cam_para_struct exif_cam_para;
exif_interoperability_para_struct exif_interoperability_para;
exif_ASCII exif_sys_time[20]={'y','y','y','y',':','m','m',':','d','d',' ','h','h',':','m','m',':','s','s','\0'};


/* Global variables  */
static kal_uint32 exif_IFD0_Entry_Switch = 0x0000; /* Switch off all cam &cus entries as default */
static kal_uint32 exif_ExifIFD_Entry_Switch = 0x0000; /* Switch off all cam & cus entries as default */
static kal_uint32 exif_ExIFD_Entry_Switch = 0x0000; 
static kal_uint32 exif_IFD1_Entry_Switch = 0x007F;
static kal_uint32 exif_InteroperabilityIFD_Entry_Switch = 0x0001;

static kal_bool exif_cam_para_get = KAL_FALSE;
static kal_bool exif_cus_para_get = KAL_FALSE;
static kal_bool exif_AscOrder;
static kal_uint8 exif_next_ExIFD_entry;
static kal_uint8 exif_ExIFD_Number_of_Entry = 0;

static exif_LONG exif_ExifIFD_Offset;
static exif_LONG exif_GPSIFD_Offset;
static exif_LONG exif_IFD1_Offset;

static kal_uint16 exif_IFD0_Entry_Size;
static kal_uint16 exif_ExifIFD_Entry_Size;
static kal_uint16 exif_IFD1_Entry_Size;
static kal_uint16 exif_InteroperabilityIFD_Entry_Size;
static kal_uint32 exif_IFD_TiffHeader_Offset;

/* Number of entries of each IFD */
static kal_uint16 exif_IFD0_count;
static kal_uint16 exif_ExifIFD_count;
static kal_uint16 exif_IFD1_count;
static kal_uint16 exif_InteroperabilityIFD_count;

/* Buffer pointer*/
static kal_uint8* exif_Buffer;
static kal_uint16 exif_BufferSize;
static kal_uint16 exif_App1Size;

static exif_MTK_para_struct exif_MTK_para;
static exif_thumbnail_para_struct exif_thumbnail_para;
static exif_extend_entry_struct* exif_ExIFD;

/* Exif Headers */
static kal_uint8 exif_Header[EXIF_HEADER_SIZE]={0xff,0xe1,0x00,0x00,'E','x','i','f','\0',0};
static const kal_uint8 exif_tiffHeader[TIFF_HEADER_SIZE]={0x49,0x49,0x2a,0x00,0x08,0x00,0x00,0x00};

static kal_uint8 exif_parser_buffer[EXIF_PARSER_BUFFER_SIZE];
static EXIF_DEC_STATE exif_decoder_state = EXIF_DEC_IDLE_STATE;

//--Exif para--
static kal_uint16 exif_ByteOrder;
static kal_uint32 exif_TiffOffset;
static kal_uint32 exif_ReqBufferSize;
static kal_uint32 exif_UsedBufferSize;

static kal_char** exif_valueArr;
static kal_uint16* exif_tagArr;

//--IFD0 para--
static kal_uint32 exif_IFD0_entry_pos;
static kal_uint16 exif_IFD0_entry_num;

//--ExifIFD para--
static kal_uint32 exif_ExifIFD_entry_pos;
static kal_uint16 exif_ExifIFD_entry_num;

static const kal_uint32 exif_sizeTable[] = { 9, 99, 999, 9999, 99999, 999999, 9999999,
                           99999999, 999999999, 0xffffffff};
static const kal_uint8 exif_DigitTable[]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};


/* tables */
exif_entry_struct IFD0[IFD0_Number_of_Entry]=
{
   //{exif_tag_Make, EXIF_ASCII, 0, exif_cus_para.Make},
   //{exif_tag_Model, EXIF_ASCII, 0, exif_cus_para.Model},
   {exif_tag_Orientation, EXIF_SHORT, 1, &exif_cam_para.Orientation},
   {exif_tag_XResolution, EXIF_RATIONAL, 1, &exif_cam_para.XResolution},
   {exif_tag_YResolution, EXIF_RATIONAL, 1, &exif_cam_para.YResolution},
   {exif_tag_ResolutionUnit, EXIF_SHORT, 1, &exif_cam_para.ResolutionUnit},
   
   {exif_tag_Software, EXIF_ASCII, 0, &exif_cam_para.Software},
   {exif_tag_DateTime, EXIF_ASCII, 0, &exif_cam_para.DateTime},
   {exif_tag_ImageDescription, EXIF_ASCII, 0, &exif_cam_para.ImageDescription},
   {exif_tag_YCbCrPositioning, EXIF_SHORT, 1, &exif_cam_para.YCbCrPositioning},
   {exif_tag_ExifIFD, EXIF_LONG, 1, &exif_ExifIFD_Offset},
   {exif_tag_GPSIFD, EXIF_LONG, 1, &exif_GPSIFD_Offset}
};
   
exif_entry_struct ExifIFD[ExifIFD_Number_of_Entry]=
{
   {exif_tag_ExposureTime, EXIF_RATIONAL, 1, &exif_cam_para.ExposureTime},
   {exif_tag_FNumber, EXIF_RATIONAL, 1, &exif_cam_para.FNumber},
   {exif_tag_ExposureProgram, EXIF_SHORT, 1, &exif_cam_para.ExposureProgram},
   {exif_tag_ISOSpeedRatings, EXIF_SHORT, 1, &exif_cam_para.ISOSpeedRatings},
   {exif_tag_ExifVersion, EXIF_UNDEFINED, 4, &exif_cam_para.ExifVersion},
   
   {exif_tag_DateTimeOriginal, EXIF_ASCII, 0, &exif_cam_para.DateTimeOriginal},
   {exif_tag_DateTimeDigitized, EXIF_ASCII, 0, &exif_cam_para.DateTimeDigitized},
   {exif_tag_ComponentsConfig, EXIF_UNDEFINED, 4, &exif_cam_para.ComponentsConfig},
   {exif_tag_ExposureBiasValue, EXIF_SRATIONAL, 1, &exif_cam_para.ExposureBiasValue},
   {exif_tag_MeteringMode, EXIF_SHORT, 1, &exif_cam_para.MeteringMode},
   
   {exif_tag_LightSource, EXIF_SHORT, 1, &exif_cam_para.LightSource},
   {exif_tag_Flash, EXIF_SHORT, 1, &exif_cam_para.Flash},
   {exif_tag_MakerNote, EXIF_UNDEFINED, sizeof(exif_MTK_para_struct), &exif_MTK_para},
   //{exif_tag_UserComment, EXIF_UNDEFINED, exif_Count_UserComment, &exif_cus_para.UserComment},
   {exif_tag_FlashpixVersion, EXIF_UNDEFINED, 4, &exif_cam_para.FlashpixVersion},
   
   {exif_tag_ColorSpace, 	EXIF_SHORT, 1, &exif_cam_para.ColorSpace},
   {exif_tag_PixelXDimension, EXIF_LONG,	1, &exif_cam_para.PixelXDimension},
   {exif_tag_PixelYDimension, EXIF_LONG, 1, &exif_cam_para.PixelYDimension},
   
   {exif_tag_InteroperabilityIFDPointer, EXIF_LONG, 1, &exif_cam_para.InteroperabilityIFDPointer},
   
   {exif_tag_ExposureMode, EXIF_SHORT, 1, &exif_cam_para.ExposureMode},
   {exif_tag_DigitalZoomRatio, EXIF_RATIONAL, 1, &exif_cam_para.DigitalZoomRatio},
   
   {exif_tag_SceneCaptureType, EXIF_SHORT, 1, &exif_cam_para.SceneCaptureType}
};

exif_entry_struct IFD1[IFD1_Number_of_Entry]=
{
    {exif_tag_Compression,                  EXIF_SHORT,     1,  &exif_thumbnail_para.Compression},
    {exif_tag_Orientation,                  EXIF_SHORT,     1,  &exif_thumbnail_para.Orientation},
    {exif_tag_XResolution,                  EXIF_RATIONAL,  1,  &exif_thumbnail_para.XResolution},
    {exif_tag_YResolution,                  EXIF_RATIONAL,  1,  &exif_thumbnail_para.YResolution},
    {exif_tag_ResolutionUnit,               EXIF_SHORT,     1,  &exif_thumbnail_para.ResolutionUnit},
    {exif_tag_JPEGInterchangeFormat,        EXIF_LONG,      1,  &exif_thumbnail_para.JPEGInterchangeFormat},
    {exif_tag_JPEGInterchangeFormatLength,  EXIF_LONG,      1,  &exif_thumbnail_para.JPEGInterchangeFormatLength},
};

exif_entry_struct InteroperabilityIFD[InteroperabilityIFD_Number_of_Entry]=
{
    {exif_tag_InteroperabilityIndex,        EXIF_ASCII,     0,  &exif_interoperability_para.InteroperabilityIndex},
};


static void _exif_fillin_ascii(kal_uint8 *Buffer, kal_uint32 *Offset, kal_char *Value, kal_uint32 count)
{
   kal_uint32 j;
   
   ASSERT(count>0);
   
   for(j=0;j<count;j++)
      Buffer[(*Offset)++]=Value[j];
   
   if(count & 1 !=0)/*Force to half-word aligned*/
      Buffer[(*Offset)++]=0x00;
}


static void _exif_fillin_16(kal_uint8 *Buffer, kal_uint32 *Offset, kal_uint16 Value)
{
   Buffer[(*Offset)++]=Value & 0xff;
   Buffer[(*Offset)++]=Value>>8 & 0xff;
}


static void _exif_fillin_32(kal_uint8 *Buffer, kal_uint32 *Offset, kal_uint32 Value)
{
   Buffer[(*Offset)++]=Value & 0xff;
   Buffer[(*Offset)++]=Value>>8 & 0xff;
   Buffer[(*Offset)++]=Value>>16 & 0xff;
   Buffer[(*Offset)++]=Value>>24 & 0xff;
}


static void _exif_fillin_tag(exif_entry_struct *Exif_entry, kal_uint32 *IFD_entry_offset, kal_uint32 *IFD_value_offset)
{
   kal_uint32	ValueOffset;
   kal_uint16	j;
   
   ASSERT(Exif_entry->count>0);
   
   _exif_fillin_16(exif_Buffer, IFD_entry_offset, Exif_entry->tag);
   
   _exif_fillin_16(exif_Buffer, IFD_entry_offset, Exif_entry->type);
   
   _exif_fillin_32(exif_Buffer, IFD_entry_offset, Exif_entry->count);
   
   switch(Exif_entry->type)
   {
      case EXIF_UNDEFINED:
         //printf("FillinTag EXIF_UNDEFINED\n");
         if(Exif_entry->count>4)
         {
            ValueOffset=*IFD_value_offset-exif_IFD_TiffHeader_Offset;
            _exif_fillin_32(exif_Buffer, IFD_entry_offset, ValueOffset);
            _exif_fillin_ascii(exif_Buffer,IFD_value_offset,(exif_UNDEFINED*)Exif_entry->value,Exif_entry->count);
         }
         else
         {
            for(j=0;j<Exif_entry->count;j++)
            {
               exif_Buffer[(*IFD_entry_offset)++]=((exif_UNDEFINED*)Exif_entry->value)[j];
            }
            for(j=Exif_entry->count;j<4;j++)
               exif_Buffer[(*IFD_entry_offset)++]=0x00;
         }
         break;
      
      case EXIF_ASCII:
         //printf("FillinTag EXIF_ASCII\n");
         if(Exif_entry->count>4)
         {
            ValueOffset=*IFD_value_offset-exif_IFD_TiffHeader_Offset;
            _exif_fillin_32(exif_Buffer, IFD_entry_offset, ValueOffset);
            _exif_fillin_ascii(exif_Buffer,IFD_value_offset,*((kal_char**)Exif_entry->value),Exif_entry->count);
         }
         else
         {
            for(j=0;j<Exif_entry->count;j++)
            {
               exif_Buffer[(*IFD_entry_offset)++]=(*((kal_char**)Exif_entry->value))[j];
            }
            for(j=Exif_entry->count;j<4;j++)
               exif_Buffer[(*IFD_entry_offset)++]=0x00;
         }
         break;		
      case EXIF_LONG:
         //printf("FillinTag EXIF_LONG\n");
         if(Exif_entry->count==1)
            _exif_fillin_32(exif_Buffer, IFD_entry_offset,((exif_LONG*)Exif_entry->value)[0]);
         else
         {
            ValueOffset=*IFD_value_offset-exif_IFD_TiffHeader_Offset;
            _exif_fillin_32(exif_Buffer, IFD_entry_offset, ValueOffset);
            for(j=0;j<Exif_entry->count;j++)
               _exif_fillin_32(exif_Buffer, IFD_value_offset,((exif_LONG*)Exif_entry->value)[j]);
         }
         break;
      case EXIF_SRATIONAL:
      case EXIF_RATIONAL:
         //printf("FillinTag EXIF_RATIONAL\n");
         ValueOffset=*IFD_value_offset-exif_IFD_TiffHeader_Offset;
         _exif_fillin_32(exif_Buffer, IFD_entry_offset, ValueOffset);
         
         for(j=0;j<Exif_entry->count;j++)
         {
            _exif_fillin_32(exif_Buffer, IFD_value_offset, ((exif_RATIONAL*)Exif_entry->value)[j][0]);
            _exif_fillin_32(exif_Buffer, IFD_value_offset, ((exif_RATIONAL*)Exif_entry->value)[j][1]);
         }
         break;
      case EXIF_SHORT:
         //printf("FillinTag EXIF_SHORT, count:%d\n",Exif_entry->count);
         if(Exif_entry->count==1)
         {
            _exif_fillin_16(exif_Buffer, IFD_entry_offset,((exif_SHORT*)Exif_entry->value)[0]);
            _exif_fillin_16(exif_Buffer, IFD_entry_offset,0);
         }
         else if(Exif_entry->count==2)
         {
            _exif_fillin_16(exif_Buffer, IFD_entry_offset,((exif_SHORT*)Exif_entry->value)[0]);
            _exif_fillin_16(exif_Buffer, IFD_entry_offset,((exif_SHORT*)Exif_entry->value)[1]);
         }
         else if(Exif_entry->count>2)
         {
            ValueOffset=*IFD_value_offset-exif_IFD_TiffHeader_Offset;
            _exif_fillin_32(exif_Buffer, IFD_entry_offset, ValueOffset);
            for(j=0;j<Exif_entry->count;j++)
               _exif_fillin_16(exif_Buffer, IFD_value_offset,((exif_SHORT*)Exif_entry->value)[j]);
         }
         break;
      default :
         ASSERT(0);
   }
}


static kal_bool _exif_is_switched_on(kal_uint8 IFD,kal_uint8 Entry)
{
   kal_uint32 mask=1<<Entry;
   kal_bool ret = KAL_FALSE;
   
   switch(IFD)
   {
      case EXIF_IFD0:
         ret = ((exif_IFD0_Entry_Switch & mask)>>Entry)?KAL_TRUE:KAL_FALSE;
         break;
      case EXIF_EXIFIFD:
         ret = ((exif_ExifIFD_Entry_Switch & mask)>>Entry)?KAL_TRUE:KAL_FALSE;
         break;
      case EXIF_EXIFD:
         ret = ((exif_ExIFD_Entry_Switch & mask)>>Entry)?KAL_TRUE:KAL_FALSE;
         break;
      default:
         ASSERT(0);
         break;
   }
   return ret;
}


/* Switch On/Off IFD entries */
static void _exif_set_IFD_entry_switch(kal_uint8 IFD,kal_uint8 Entry,kal_uint8 action)
{
   kal_uint32* IFD_switch;
   kal_uint32	mask;
   
   mask=1 << Entry;
   
   switch(IFD)
   {
      case EXIF_IFD0:
         IFD_switch=&exif_IFD0_Entry_Switch;
         break;
      case EXIF_EXIFIFD:
         IFD_switch=&exif_ExifIFD_Entry_Switch;
         break;
      case EXIF_EXIFD:
         IFD_switch=&exif_ExIFD_Entry_Switch;
         break;
      default: 
         ASSERT(0);
         return;
   }
   
   switch(action) 
   {
      case EXIF_SWITCH_ON:
         *IFD_switch |=mask;
         break;
      case EXIF_SWITCH_OFF:
         *IFD_switch &=~mask;
         break;
      default: 
         ASSERT(0);
         return;
   }
   
}


static void _exif_set_cam_entry_switch(kal_uint8 action)
{
   kal_uint8 i;
   
   for(i=EXIF_ORIENTATION;i<=EXIF_YCBCR_POSITIONING;i++)
      _exif_set_IFD_entry_switch(EXIF_IFD0,i,action);
   
   _exif_set_IFD_entry_switch(EXIF_IFD0, EXIF_EXIF_IFD, EXIF_SWITCH_ON);
   
   for(i=EXIF_EXPOSURE_TIME;i<EXIF_MAKER_NOTE;i++)
      _exif_set_IFD_entry_switch(EXIF_EXIFIFD,i,action);
   
   for(i=EXIF_FLASHPIX_VERSION;i<=EXIF_SCENE_CAPTURE_TYPE;i++)
      _exif_set_IFD_entry_switch(EXIF_EXIFIFD,i,action);
}


static kal_uint8 _exif_get_next_extended_tag(kal_uint8 IFD,kal_uint16 MinTag)
{
   kal_uint8 j,index=255;
   
   if(!exif_AscOrder)
   {
      for(j=0;j<exif_ExIFD_Number_of_Entry;j++)
      {
         if( _exif_is_switched_on(EXIF_EXIFD,j) && 
         exif_ExIFD[j].exif_IFD_type==IFD && 
         exif_ExIFD[j].entry.tag<MinTag)
         {
            index=j;
            MinTag=exif_ExIFD[j].entry.tag;
         }
      }
   }
   else
   {
      if(exif_next_ExIFD_entry<exif_ExIFD_Number_of_Entry && 
      _exif_is_switched_on(EXIF_EXIFD,exif_next_ExIFD_entry) &&
      exif_ExIFD[exif_next_ExIFD_entry].exif_IFD_type==IFD &&
      exif_ExIFD[exif_next_ExIFD_entry].entry.tag<MinTag)
      {
      
         //printf("exif_ExIFD:%x MinTag:%x\n",exif_ExIFD[exif_next_ExIFD_entry].entry.tag,MinTag);
         index=exif_next_ExIFD_entry++;
      }
   
   }
   
   /* switch off the selected tag */
   if(index<EXIF_MAXIMUM_NUMBER_OF_EXIFD_ENTRIES)
   {
   
      _exif_set_IFD_entry_switch(EXIF_EXIFD,index,EXIF_SWITCH_OFF);
   
   }
   else if(index>=EXIF_MAXIMUM_NUMBER_OF_EXIFD_ENTRIES && index !=255)
      ASSERT(0);
   
   
   //printf("count:%d index:%d\n",count,index);
   return index;
}


static kal_bool _exif_fillin_header(kal_uint8* Buffer,kal_uint32 BufferOffset)
{
   kal_uint32 i;
   kal_uint32 mask;
   kal_uint32 j;
   kal_uint32 IFD_entry_offset;
   kal_uint32 IFD_value_offset;
   
   exif_Buffer=Buffer;
   exif_next_ExIFD_entry=0;
   
   if(!exif_cam_para_get && !exif_cus_para_get)
      return KAL_FALSE;
   
   if(exif_IFD0_count==0 && exif_ExifIFD_count==0)
      return KAL_TRUE;
   
   /*--Fill in the length field of app0 marker--*/
   ////exif_Header[2]=(exif_BufferSize-2)>>8 & 0xff;
   ////exif_Header[3]=(exif_BufferSize-2) & 0xff;
   exif_Header[2]=(exif_App1Size-2)>>8 & 0xff;
   exif_Header[3]=(exif_App1Size-2) & 0xff;
   
   //-- copy JPEG,EXIF header --
   IFD_entry_offset=BufferOffset;
   for(j=0;j<EXIF_HEADER_SIZE;j++)
      Buffer[IFD_entry_offset++]=exif_Header[j];
   
   //-- copy TiffHeader --
   for(j=0;j<TIFF_HEADER_SIZE;j++)
      Buffer[IFD_entry_offset++]=exif_tiffHeader[j];
   
   /************* Fillin IFD0 entries *************/
   IFD_value_offset=IFD_entry_offset+exif_IFD0_Entry_Size;
   
   mask=1;
   
   _exif_fillin_16(Buffer, &IFD_entry_offset, exif_IFD0_count);//Fill in number of IFD0 entries
   
   
   for(i=0;i<EXIF_EXIF_IFD;i++)
   {
      if((exif_IFD0_Entry_Switch & mask)==0)// This entry is switched off
      {
         mask<<=1;
         continue;
      }
   
      if(IFD0[i].type==EXIF_ASCII && *((kal_char**)IFD0[i].value)==0)
      {
         mask<<=1;
         continue;
      }
      //-- check Extended tags --
      while((j=_exif_get_next_extended_tag(EXIF_IFD0,IFD0[i].tag))!=255)
      {
         _exif_fillin_tag(&exif_ExIFD[j].entry,&IFD_entry_offset,&IFD_value_offset);
      }
      _exif_fillin_tag(&IFD0[i],&IFD_entry_offset,&IFD_value_offset);
   
      mask<<=1;
   }
   
   //--Fillin ExifIFD entry of IFD0--
   if(exif_ExifIFD_count>0 && _exif_is_switched_on(EXIF_IFD0,EXIF_EXIF_IFD))
   {
      //-- check IFD0 Extended tags (before IFD0.ExifIFD tag)--
      while((j=_exif_get_next_extended_tag(EXIF_IFD0,IFD0[EXIF_EXIF_IFD].tag))!=255)
      {
         _exif_fillin_tag(&exif_ExIFD[j].entry,&IFD_entry_offset,&IFD_value_offset);
      }
      _exif_fillin_tag(&IFD0[EXIF_EXIF_IFD],&IFD_entry_offset,&IFD_value_offset);
   }
   
   //-- check Rest IFD0 Extended tags --
   while((j=_exif_get_next_extended_tag(EXIF_IFD0,exif_tag_MAXIMUM))!=255)
   {
      _exif_fillin_tag(&exif_ExIFD[j].entry,&IFD_entry_offset,&IFD_value_offset);
   }
   
   ////_exif_fillin_32(Buffer, &IFD_entry_offset,0);//no next IFD(IFD1)
   _exif_fillin_32(Buffer, &IFD_entry_offset, exif_IFD1_Offset);
   
   
   /************* Fill in exif_IFD entries *************/
   if((exif_IFD0_Entry_Switch & (1<<EXIF_EXIF_IFD))!=0)
   {
      IFD_entry_offset=IFD_value_offset;
      IFD_value_offset=IFD_entry_offset+exif_ExifIFD_Entry_Size;
      mask=1;
      
      _exif_fillin_16(Buffer, &IFD_entry_offset,exif_ExifIFD_count);//Fill in number of IFD0 entries
      
      for(i=0;i<ExifIFD_Number_of_Entry;i++)
      {
         if((exif_ExifIFD_Entry_Switch & mask)==0)// This entry is switched off
         {
            mask<<=1;
            continue;
         }
         
         if(ExifIFD[i].type==EXIF_ASCII && *((kal_char**)ExifIFD[i].value)==0)
         {
            mask<<=1;
            continue;
         }
      
         while((j=_exif_get_next_extended_tag(EXIF_EXIFIFD,ExifIFD[i].tag))!=255)
         {
            _exif_fillin_tag(&exif_ExIFD[j].entry,&IFD_entry_offset,&IFD_value_offset);
         }
         
         _exif_fillin_tag(&ExifIFD[i],&IFD_entry_offset,&IFD_value_offset);
         
         mask<<=1;
      }
      //-- check Rest ExifIFD Extended tags --
      while((j=_exif_get_next_extended_tag(EXIF_EXIFIFD,exif_tag_MAXIMUM))!=255)
      {
         _exif_fillin_tag(&exif_ExIFD[j].entry,&IFD_entry_offset,&IFD_value_offset);
      }
      
      _exif_fillin_32(Buffer, &IFD_entry_offset,0);//no next IFD(IFD1)
   }
   
   /************* Fillin InteroperabilityIFD entries *************/
   IFD_entry_offset=IFD_value_offset;
   IFD_value_offset=IFD_entry_offset+exif_InteroperabilityIFD_Entry_Size;
   
   mask=1;
   
   _exif_fillin_16(Buffer, &IFD_entry_offset, exif_InteroperabilityIFD_count);//Fill in number of IFD0 entries
   
   
   for(i=0;i<InteroperabilityIFD_Number_of_Entry;i++)
   {
      if((exif_InteroperabilityIFD_Entry_Switch & mask)==0)// This entry is switched off
      {
         mask<<=1;
         continue;
      }
      
      if(IFD1[i].type==EXIF_ASCII && *((kal_char**)IFD1[i].value)==0)
      {
         mask<<=1;
         continue;
      }
      
      //-- check Extended tags --
      _exif_fillin_tag(&InteroperabilityIFD[i],&IFD_entry_offset,&IFD_value_offset);
      
      mask<<=1;
   }
   
   _exif_fillin_32(Buffer, &IFD_entry_offset,0);//no next IFD(IFD1)
   
   /************* Fillin IFD1 entries *************/
   IFD_entry_offset=IFD_value_offset;
   IFD_value_offset=IFD_entry_offset+exif_IFD1_Entry_Size;
   
   mask=1;
   
   _exif_fillin_16(Buffer, &IFD_entry_offset, exif_IFD1_count);//Fill in number of IFD0 entries
   
   
   for(i=0;i<IFD1_Number_of_Entry;i++)
   {
      if((exif_IFD1_Entry_Switch & mask)==0)// This entry is switched off
      {
         mask<<=1;
         continue;
      }
      
      if(IFD1[i].type==EXIF_ASCII && *((kal_char**)IFD1[i].value)==0)
      {
         mask<<=1;
         continue;
      }
      
      //-- check Extended tags --
      _exif_fillin_tag(&IFD1[i],&IFD_entry_offset,&IFD_value_offset);
      
      mask<<=1;
   }
   
   _exif_fillin_32(Buffer, &IFD_entry_offset,0);//no next IFD(IFD1)
   
   
   
   exif_cam_para_get=KAL_FALSE;
   //exif_cus_para_get=KAL_FALSE;
   //_exif_set_IFD_entry_switch(EXIF_EXIFIFD,EXIF_MAKER_NOTE,EXIF_SWITCH_OFF);
   return	KAL_TRUE; 
}


static FSAL_Status _exif_read_uint8(kal_uint8 *pwValue)
{
   if(exif_FSAL.uFileOffset+1>exif_FileSize) return FSAL_READ_ERROR;
   
   return FSAL_Read_Bytes(&exif_FSAL,pwValue, 1);
}


static FSAL_Status _exif_read_uint16(kal_uint16 *pwValue)
{
   kal_uint8 data[2];
   FSAL_Status ret;
   
   FSAL_CHECK_ARG(pwValue!=NULL);
   
   if(exif_FSAL.uFileOffset+2>exif_FileSize) return FSAL_READ_ERROR;
   
   if((ret=FSAL_Read_Bytes(&exif_FSAL, data, 2))!=FSAL_OK)
      return ret;
   
   if(exif_ByteOrder==EXIF_BIG_ENDIAN)
      *pwValue = (kal_uint16)((data[0]<<8) + (data[1]));
   else if(exif_ByteOrder==EXIF_LITTLE_ENDIAN)
      *pwValue = (kal_uint16)((data[1]<<8) + (data[0]));
   else
      return FSAL_FATAL_ERROR;
   
   return FSAL_OK;
}


static FSAL_Status _exif_read_uint32(kal_uint32 *puValue)
{
   kal_uint8 data[4];
   FSAL_Status ret;
   
   FSAL_CHECK_ARG(puValue!=NULL);
   
   if(exif_FSAL.uFileOffset+4>exif_FileSize) return FSAL_READ_ERROR;
   
   if((ret=FSAL_Read_Bytes(&exif_FSAL, data, 4))!=FSAL_OK)
      return ret;
   
   if(exif_ByteOrder==EXIF_BIG_ENDIAN)
      *puValue = (kal_uint32)((data[0]<<24) + (data[1]<<16) + (data[2]<<8) + (data[3]));
   else if(exif_ByteOrder==EXIF_LITTLE_ENDIAN)
      *puValue = (kal_uint32)((data[3]<<24) + (data[2]<<16) + (data[1]<<8) + (data[0]));
   else
      return FSAL_FATAL_ERROR;
   
   return FSAL_OK;
}


static void _exif_parse_acc_tag(kal_uint16 tag,kal_uint16 type)
{
   /* These tags are with built in info */
   switch(tag)
   {
      case exif_tag_Orientation:
         exif_ReqBufferSize+=EXIF_DEC_Orientation_MAX_LEN;
         return;
      case exif_tag_ResolutionUnit:
         exif_ReqBufferSize+=EXIF_DEC_ResolutionUnit_MAX_LEN;
         return;
      case exif_tag_YCbCrPositioning:
         exif_ReqBufferSize+=EXIF_DEC_YCbCrPositioning_MAX_LEN;
         return;
      case exif_tag_ExposureProgram:
         exif_ReqBufferSize+=EXIF_DEC_ExposureProgram_MAX_LEN;
         return;
      case exif_tag_ComponentsConfig:
         exif_ReqBufferSize+=EXIF_DEC_ComponentsConfig_MAX_LEN;
         return;
      case exif_tag_MeteringMode:
         exif_ReqBufferSize+=EXIF_DEC_MeteringMode_MAX_LEN;
         return;
      case exif_tag_LightSource:
         exif_ReqBufferSize+=EXIF_DEC_LightSource_MAX_LEN;
         return;
      case exif_tag_Flash:
         exif_ReqBufferSize+=EXIF_DEC_Flash_MAX_LEN;
         return;
      case exif_tag_ColorSpace:
         exif_ReqBufferSize+=EXIF_DEC_ColorSpace_MAX_LEN;
         return;
      case exif_tag_ExposureMode:
         exif_ReqBufferSize+=EXIF_DEC_ExposureMode_MAX_LEN;
         return;
      case exif_tag_SceneCaptureType:
         exif_ReqBufferSize+=EXIF_DEC_SceneCaptureType_MAX_LEN;
         return;
      default :
         break;
   }
   
   switch(type)
   {
      case EXIF_BYTE:
         exif_ReqBufferSize+=EXIF_BYTE_SHOW_LEN;
         break;
      case EXIF_ASCII:
         exif_ReqBufferSize+=EXIF_ASCII_SHOW_LEN;
         break;
      case EXIF_SHORT:
         exif_ReqBufferSize+=EXIF_SHORT_SHOW_LEN;
         break;
      case EXIF_LONG:
         exif_ReqBufferSize+=EXIF_LONG_SHOW_LEN;
         break;
      case EXIF_RATIONAL:
         exif_ReqBufferSize+=EXIF_RATIONAL_SHOW_LEN;
         break;
      case EXIF_SRATIONAL:
         exif_ReqBufferSize+=EXIF_SRATIONAL_SHOW_LEN;
         break;
      case EXIF_SLONG:
         exif_ReqBufferSize+=EXIF_SLONG_SHOW_LEN;
         break;
      case EXIF_UNDEFINED:
         exif_ReqBufferSize+=EXIF_UNDEFINED_SHOW_LEN;
         break;
   }
}


static kal_uint32 _exif_parse_long_string_size(kal_uint32 x)
{
   kal_uint16 i;
   for (i=0; ; i++)
      if (x <= exif_sizeTable[i])
         return i+1;
}


static kal_uint32 _exif_parse_slong_string_size(kal_int32 x)
{
   kal_uint16 i,p=0;
   if(x<0) 
   {
      x=-x;
      p++;
   }
   
   for (i=0; ; i++)
      if (x <= exif_sizeTable[i])
         return i+p+1;
}


static kal_uint32 _exif_parse_float_string_size(float fp)
{
   kal_uint32 len;
   
   len=sprintf((kal_char*)exif_parser_buffer,EXIF_RATIONAL_PRECISION,fp);
   ASSERT(len<EXIF_PARSER_BUFFER_SIZE);
   return len;
}


static kal_uint32 _exif_set_entry(kal_char** str,kal_char* buffer, exif_dec_entry_struct* Exif_entry)
{
   double	 fp;
   kal_uint32 len=0,count=0,value,value1;
   kal_uint16 value16;
   kal_uint8 value8;
   kal_int32 Svalue,Svalue1;
   

   if(Exif_entry->count<1) return 0;
   
   if(exif_ByteOrder==EXIF_LITTLE_ENDIAN)
   {
      value16=Exif_entry->value & 0xffff;
   }
   else
   {
      value16=(Exif_entry->value>>16);
   }
   
   switch(Exif_entry->tag)
   {
      case exif_tag_Orientation:
         if(value16<9)
         {
            *str=buffer;
            
            while(len<strlen(exif_Orientation_table[value16]) && len<EXIF_ASCII_SHOW_LEN-1)
            {
               buffer[len]=exif_Orientation_table[value16][len];
               len++;
            }
            buffer[len++]=0;
            return len;
         }
         break;
      case exif_tag_ResolutionUnit:
         if(value16<4)
         {
            *str=buffer;
            while(len<strlen(exif_ResolutionUnit_table[value16]) && len<EXIF_ASCII_SHOW_LEN-1)
            {
               buffer[len]=exif_ResolutionUnit_table[value16][len];
               len++;
            }
            buffer[len++]=0;
            return len;
         }
         break;
      case exif_tag_YCbCrPositioning:
         if(value16<3)
         {
            *str=buffer;
            while(len<strlen(exif_YCbCrPositioning_table[value16]) && len<EXIF_ASCII_SHOW_LEN-1)
            {
               buffer[len]=exif_YCbCrPositioning_table[value16][len];
               len++;
            }
            buffer[len++]=0;
            return len;
         }
         break;
      case exif_tag_ExposureProgram:
         if(value16<=8)
         {
            *str=buffer;
            while(len<strlen(exif_ExposureProgram_table[value16]) && len<EXIF_ASCII_SHOW_LEN-1)
            {
               buffer[len]=exif_ExposureProgram_table[value16][len];
               len++;
            }
            buffer[len++]=0;
            return len;
         }
         break;
      case exif_tag_ComponentsConfig:
         if((exif_ByteOrder==EXIF_LITTLE_ENDIAN && Exif_entry->value==0x030201) ||
         (exif_ByteOrder==EXIF_BIG_ENDIAN && Exif_entry->value==0x01020300))
         {
            *str=buffer;
            while(len<strlen(exif_ComponentsConfig_table[0]) && len<EXIF_ASCII_SHOW_LEN-1)
            {
               buffer[len]=exif_ComponentsConfig_table[0][len];
               len++;
            }
            buffer[len++]=0;
            return len;
         }
         else if((exif_ByteOrder==EXIF_LITTLE_ENDIAN && Exif_entry->value==0x060504) ||
         (exif_ByteOrder==EXIF_BIG_ENDIAN && Exif_entry->value==0x04050600))
         {
            *str=buffer;
            while(len<strlen(exif_ComponentsConfig_table[1]) && len<EXIF_ASCII_SHOW_LEN-1)
            {
               buffer[len]=exif_ComponentsConfig_table[1][len];
               len++;
            }
            buffer[len++]=0;
            return len;
         }
         break;
      case exif_tag_MeteringMode:
         if(value16==255)
            value16=8;
         else if(value16>7 && value16<255)
            value16=7;
         
         if(value16<=8)
         {
            *str=buffer;
            while(len<strlen(exif_MeteringMode_table[value16]) && len<EXIF_ASCII_SHOW_LEN-1)
            {
               buffer[len]=exif_MeteringMode_table[value16][len];
               len++;
            }
            buffer[len++]=0;
            return len;
         }
         break;
      case exif_tag_LightSource:
         if(value16<25)
         {
            *str=buffer;
            while(len<strlen(exif_LightSource_table[value16]) && len<EXIF_ASCII_SHOW_LEN-1)
            {
               buffer[len]=exif_LightSource_table[value16][len];
               len++;
            }
            buffer[len++]=0;
            return len;
         }
         break;
      case exif_tag_Flash:
         if(value16<96)
         {
            *str=buffer;
            while(len<strlen(exif_Flash_table[value16]) /*&& len<EXIF_ASCII_SHOW_LEN-1*/)
            {
               buffer[len]=exif_Flash_table[value16][len];
               len++;
            }
            buffer[len++]=0;
            return len;
         }
         break;
      case exif_tag_ColorSpace:
         if(value16==1)
         {
            *str="sRGB";
            return 0;
         }
         else if(value16==0xffff)
         {
            *str="Uncalibrated";
            return 0;
         }
         break;
      case exif_tag_ExposureMode:
         if(value16<3)
         {
            *str=buffer;
            while(len<strlen(exif_ExposureMode_table[value16]) && len<EXIF_ASCII_SHOW_LEN-1)
            {
               buffer[len]=exif_ExposureMode_table[value16][len];
               len++;
            }
            buffer[len++]=0;
            return len;
         }
         break;
      case exif_tag_SceneCaptureType:
         if(value16<4)
         {
            *str=buffer;
            while(len<strlen(exif_SceneCaptureType_table[value16]) && len<EXIF_ASCII_SHOW_LEN-1)
            {
               buffer[len]=exif_SceneCaptureType_table[value16][len];
               len++;
            }
            buffer[len++]=0;
            return len;
         }
         break;
      case exif_tag_FlashpixVersion:
      case exif_tag_ExifVersion:
      {
         if(_exif_seek_buffer(exif_FSAL.uFileOffset-4,FS_FILE_BEGIN)!=FSAL_OK)
            return 0;
         *str=buffer;
         _exif_read_uint8(&value8);
         if(value8!='0')
            buffer[len++]=value8;
         _exif_read_uint8(&value8);
         buffer[len++]=value8;
         buffer[len++]='.';
         _exif_read_uint8(&value8);
         buffer[len++]=value8;
         _exif_read_uint8(&value8);
         if(value8!='0')
            buffer[len++]=value8;
         buffer[len++]=0;
         return len;
      }
   }
   
   switch(Exif_entry->type)
   {
      case EXIF_BYTE:
         if(Exif_entry->count<=4)
         {
            if(_exif_seek_buffer(exif_FSAL.uFileOffset-4,FS_FILE_BEGIN)!=FSAL_OK)
               return 0;
         }
         else
         {
            if(_exif_seek_buffer(Exif_entry->value+exif_TiffOffset,FS_FILE_BEGIN)!=FSAL_OK)
               return 0;	
         }
         
         *str=buffer;
         
         while(count++<Exif_entry->count)
         {
            _exif_read_uint8(&value8);
            
            if(len+_exif_parse_long_string_size(value8)>=EXIF_BYTE_SHOW_LEN-2)
               break;
            
            len=sprintf(buffer+len,"%u",value8);
            buffer[len++]=' ';
         }
         
         buffer[len++]=0;
         //printf("***len:%d %s***",len,buffer[0]);
         return len;
      
      case EXIF_SHORT:
         if(Exif_entry->count<=2)
         {
            if(_exif_seek_buffer(exif_FSAL.uFileOffset-4,FS_FILE_BEGIN)!=FSAL_OK)
               return 0;
         }
         else
         {
            if(_exif_seek_buffer(Exif_entry->value+exif_TiffOffset,FS_FILE_BEGIN)!=FSAL_OK)
               return 0;	
         }
         *str=buffer;
         
         while(count++<Exif_entry->count)
         {
            _exif_read_uint16(&value16);
            if(len+_exif_parse_long_string_size(value16)>=EXIF_SHORT_SHOW_LEN-2)
               break;
            
            len=sprintf(buffer+len,"%u",value16);
            buffer[len++]=' ';
         }
         
         buffer[len++]=0;
         //printf("***len:%d %s***\n",len,buffer);
         return len;
      
      case EXIF_LONG:
         if(Exif_entry->count<=1)
         {
            if(_exif_seek_buffer(exif_FSAL.uFileOffset-4,FS_FILE_BEGIN)!=FSAL_OK)
               return 0;
         }
         else
         {
            if(_exif_seek_buffer(Exif_entry->value+exif_TiffOffset,FS_FILE_BEGIN)!=FSAL_OK)
               return 0;	
         }
         
         //printf("--StringLen:%d \n",_exif_parse_long_string_size(value));
         *str=buffer;
         while(count++<Exif_entry->count)
         {
            _exif_read_uint32(&value);
            
            if((len+_exif_parse_long_string_size(value) >= EXIF_LONG_SHOW_LEN-2))
               break;
            
            len=sprintf(buffer+len,"%u",value);
            buffer[len++]=' ';
         }
         
         buffer[len++]=0;
         //printf("***len:%d %s***\n",len,buffer);
         return len;
      
      case EXIF_SLONG:
         if(Exif_entry->count<=1)
         {
            if(_exif_seek_buffer(exif_FSAL.uFileOffset-4,FS_FILE_BEGIN)!=FSAL_OK)
               return 0;
         }
         else
         {
            if(_exif_seek_buffer(Exif_entry->value+exif_TiffOffset,FS_FILE_BEGIN)!=FSAL_OK)
               return 0;	
         }
         
         //printf("--StringLen:%d \n",stringSize(value));
         
         *str=buffer;
         while(count++<Exif_entry->count)
         {
            _exif_read_uint32(&value);
            Svalue=(kal_int32)value;
            
            if((len+_exif_parse_slong_string_size(Svalue) >= EXIF_SLONG_SHOW_LEN-2))
               break;
            
            len=sprintf(buffer+len,"%u",Svalue);
            buffer[len++]=' ';
         }
         
         buffer[len++]=0;
         //printf("***len:%d %s***",len,buffer[0]);
         return len;
      
      case EXIF_RATIONAL:
         if(_exif_seek_buffer(Exif_entry->value+exif_TiffOffset,FS_FILE_BEGIN)!=FSAL_OK)
            return 0;
         
         *str=buffer;
         if(Exif_entry->tag==exif_tag_ExposureTime)
         {
            while(count++<Exif_entry->count)
            {
               _exif_read_uint32(&value);
               _exif_read_uint32(&value1);
               
               if(len+_exif_parse_long_string_size(value)+_exif_parse_long_string_size(value1)+1 >= EXIF_RATIONAL_SHOW_LEN-2)
                  break;
               
               len=sprintf(buffer+len,"%u",value);
               buffer[len++]='/';
               len+=sprintf(buffer+len,"%u",value1);
               buffer[len++]=' ';
            }
         }
         else
         {
            while(count++<Exif_entry->count)
            {
               _exif_read_uint32(&value);
               _exif_read_uint32(&value1);
               
               if(value==0 || value1==0)
               {
                  buffer[len++]='0';
                  break;
               }
               
               fp=((double)value)/value1;
               
               if(len+_exif_parse_float_string_size(fp)+1 >= EXIF_RATIONAL_SHOW_LEN-2)
                  break;
               len=sprintf(buffer+len,EXIF_RATIONAL_PRECISION,fp);
               buffer[len++]=' ';
            }
         }
         buffer[len++]=0;
         return len;
      
      case EXIF_SRATIONAL:
         if(_exif_seek_buffer(Exif_entry->value+exif_TiffOffset,FS_FILE_BEGIN)!=FSAL_OK)
            return 0;
         
         *str=buffer;
         if(0)
         {
            while(count++<Exif_entry->count)
            {
               _exif_read_uint32(&value);
               _exif_read_uint32(&value1);
               
               if(len+_exif_parse_slong_string_size(value)+_exif_parse_slong_string_size(value1)+1 >= EXIF_SRATIONAL_SHOW_LEN-2)
                  break;
               
               len=sprintf(buffer+len,"%d",value);
               //printf("*** %d %d",_exif_parse_slong_string_size(value),_exif_parse_slong_string_size(value1));
               buffer[len++]='/';
               len+=sprintf(buffer+len,"%d",value1);
               buffer[len++]=' ';
            }
         }
         else
         {
            while(count++<Exif_entry->count)
            {
               _exif_read_uint32(&value);
               _exif_read_uint32(&value1);
               
               if(value==0 || value1==0)
               {
                  buffer[len++]='0';
                  break;
               }
               
               Svalue=(kal_int32)value;
               Svalue1=(kal_int32)value1;
               
               fp=((double)Svalue)/Svalue1;
               
               if(len+_exif_parse_float_string_size(fp)+1 >= EXIF_RATIONAL_SHOW_LEN-2)
                  break;
               len=sprintf(buffer+len,EXIF_RATIONAL_PRECISION,fp);
               buffer[len++]=' ';
            }
         }
         buffer[len++]=0;
         return len;
      
      case EXIF_ASCII:
         if(Exif_entry->count<=4)
         {
            if(_exif_seek_buffer(exif_FSAL.uFileOffset-4,FS_FILE_BEGIN)!=FSAL_OK)
               return 0;
         }
         else
         {
            if(_exif_seek_buffer(Exif_entry->value+exif_TiffOffset,FS_FILE_BEGIN)!=FSAL_OK)
               return 0;	
         }
         
         *str=buffer;
         
         while(count++<Exif_entry->count && len<EXIF_ASCII_SHOW_LEN-1)
         {
            _exif_read_uint8(&value8);
            
            if (0 == value8)
            {
               break;
            }
            
            //Check if the char is ASCII ot not
            if(value8>=32 && value8<127)
               buffer[len++]=(kal_char)(value8);
            else
               buffer[len++]=' ';
         }
         buffer[len++]=0;
         return len;

      case EXIF_UNDEFINED:
         if(Exif_entry->count<=4)
         {
            if(_exif_seek_buffer(exif_FSAL.uFileOffset-4,FS_FILE_BEGIN)!=FSAL_OK)
               return 0;
         }
         else
         {
            if(_exif_seek_buffer(Exif_entry->value+exif_TiffOffset,FS_FILE_BEGIN)!=FSAL_OK)
               return 0;
         }
         //printf("#### buffer:%d\n",buffer);
         *str=buffer;
         while(count++< Exif_entry->count && (len+3<EXIF_UNDEFINED_SHOW_LEN-2))
         {
            _exif_read_uint8(&value8);

            // translate byte to hex
            buffer[len++]=exif_DigitTable[value8/16];
            buffer[len++]=exif_DigitTable[value8%16];
            buffer[len++]=' ';
         }
         buffer[len++]=0;
         return len;

      default:
         *str=0;
         return 0;
   }
}


static void _exif_get_sys_time(void)
{
   DCL_STATUS DclRTC_status;
   DCL_HANDLE DclRTC_hdl;
   RTC_CTRL_GET_TIME_T DclRTC_time;
   
   DclRTC_hdl = DclRTC_Open(DCL_RTC, FLAGS_NONE);
   DclRTC_status = DclRTC_Control(DclRTC_hdl, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T*)&DclRTC_time);	
   
   if (DclRTC_status == STATUS_OK)
   {
      exif_sys_time[0]='2';
      if(DclRTC_time.u1Year>=100)
      {
         exif_sys_time[1]='1';
         DclRTC_time.u1Year-=100;
      }
      else
      {
         exif_sys_time[1]='0';
      }
      
      exif_sys_time[2]=(DclRTC_time.u1Year/10)+48;
      exif_sys_time[3]=(DclRTC_time.u1Year%10)+48;
      
      exif_sys_time[5]=(DclRTC_time.u1Mon/10)+48;
      exif_sys_time[6]=(DclRTC_time.u1Mon%10)+48;
      
      exif_sys_time[8]=(DclRTC_time.u1Day/10)+48;
      exif_sys_time[9]=(DclRTC_time.u1Day%10)+48;
      
      exif_sys_time[11]=(DclRTC_time.u1Hour/10)+48;
      exif_sys_time[12]=(DclRTC_time.u1Hour%10)+48;
      
      exif_sys_time[14]=(DclRTC_time.u1Min/10)+48;
      exif_sys_time[15]=(DclRTC_time.u1Min%10)+48;
      
      exif_sys_time[17]=(DclRTC_time.u1Sec/10)+48;
      exif_sys_time[18]=(DclRTC_time.u1Sec%10)+48;
   }
}


/* Set preDefined values to some of the IFD entries */
exif_cam_para_struct* exif_get_cam_para_struct(void)
{
   _exif_get_sys_time();
   
   exif_cam_para.Orientation=1;
   exif_cam_para.XResolution[0]=72;
   exif_cam_para.XResolution[1]=1;
   exif_cam_para.YResolution[0]=72;
   exif_cam_para.YResolution[1]=1;
   exif_cam_para.ResolutionUnit=2;	/* inches */
   
   exif_cam_para.Software=(kal_char*)release_verno();
   exif_cam_para.DateTime=exif_sys_time; //"yyyy:mm:dd hh:mm:ss";
   exif_cam_para.ImageDescription = NULL;
   
   exif_cam_para.YCbCrPositioning=2;/* co-siteded */
   
   /* Exif IFD default values */
   
   exif_cam_para.ExposureTime[0]=0;
   exif_cam_para.ExposureTime[1]=0;
   
   exif_cam_para.FNumber[0]=0;
   exif_cam_para.FNumber[1]=0;
   
   exif_cam_para.ExposureProgram=0;	/* Unknown*/
   
   exif_cam_para.ISOSpeedRatings=0;
   
   exif_cam_para.ExifVersion[3]='0';/* Supported Exif Version: 2.2*/
   exif_cam_para.ExifVersion[2]='2';
   exif_cam_para.ExifVersion[1]='2';
   exif_cam_para.ExifVersion[0]='0';
   
   exif_cam_para.DateTimeOriginal=0;
   exif_cam_para.DateTimeDigitized=0;
   
   exif_cam_para.ComponentsConfig[0]=1;	/* YCbCr */
   exif_cam_para.ComponentsConfig[1]=2;
   exif_cam_para.ComponentsConfig[2]=3;
   exif_cam_para.ComponentsConfig[3]=0;
   
   exif_cam_para.ExposureBiasValue[0]=0;
   exif_cam_para.ExposureBiasValue[1]=1;
   
   exif_cam_para.MeteringMode=0;
   exif_cam_para.LightSource=0;
   exif_cam_para.Flash=0;
   
   exif_cam_para.FlashpixVersion[3]='0';
   exif_cam_para.FlashpixVersion[2]='0';
   exif_cam_para.FlashpixVersion[1]='1';
   exif_cam_para.FlashpixVersion[0]='0';
   
   exif_cam_para.ColorSpace=1;	/* sRGB */
   
   exif_cam_para.PixelXDimension=0;
   exif_cam_para.PixelYDimension=0;
   
   exif_cam_para.ExposureMode=0; /* auto exposure */
   
   exif_cam_para.DigitalZoomRatio[0]=1;
   exif_cam_para.DigitalZoomRatio[1]=1;
   
   exif_cam_para.SceneCaptureType=0; /* standard */
   
   exif_cam_para_get=KAL_TRUE;
   _exif_set_cam_entry_switch(EXIF_SWITCH_ON);
   
   /* Temporly switch FNumber off*/
   _exif_set_IFD_entry_switch(EXIF_EXIFIFD,EXIF_FNUMBER,EXIF_SWITCH_OFF);
   
   exif_thumbnail_para.Compression = 6;
   exif_thumbnail_para.Orientation = 1;
   exif_thumbnail_para.XResolution[0] = 72;
   exif_thumbnail_para.XResolution[1] = 1;
   exif_thumbnail_para.YResolution[0] = 72;
   exif_thumbnail_para.YResolution[1] = 1;
   exif_thumbnail_para.ResolutionUnit = 2;
   
   exif_interoperability_para.InteroperabilityIndex = "R98";
   
   return &exif_cam_para;
}

exif_MTK_para_struct* exif_get_MTK_para_struct(void)
{
   strcpy(exif_MTK_para.title,"MediaTek");
   exif_MTK_para.version[0]=exif_MTK_specific_ver_main;
   exif_MTK_para.version[1]=exif_MTK_specific_ver_fraction;
   
   exif_update_MTK_para_struct(&exif_MTK_para);   
   
   exif_cam_para_get=KAL_TRUE;
   _exif_set_IFD_entry_switch(EXIF_EXIFIFD,EXIF_MAKER_NOTE,EXIF_SWITCH_ON);
   
   return &exif_MTK_para;
}

kal_uint32 eixf_burst_mode_fill_header(kal_uint8* Buffer)
{
   kal_uint8* NewBuffer;
   
   if(Buffer[0]==0xff && Buffer[1]==0xd8)
      return 0;
   
   NewBuffer=Buffer-exif_BufferSize-2;
   
   exif_IFD_TiffHeader_Offset=2+EXIF_HEADER_SIZE;
   exif_ExIFD_Entry_Switch=0xffffffff;
   
   exif_cam_para_get=KAL_TRUE;	 //Re-Eanble
   _exif_fillin_header(NewBuffer,2);
   
   NewBuffer[0]=0xff;
   NewBuffer[1]=0xd8;
   exif_cam_para_get=KAL_FALSE; //Disable
   
   return exif_BufferSize+2;
}


/*************************************************************************
* FUNCTION
*   exif_open_jpeg_file()
*
* DESCRIPTION
*   This function is to open a jpeg file for parsing the exif header
*
* PARAMETERS
*   void* file_name_p
*
* RETURNS
*   The size of buffer required to store the parsing result. If 0 is 
*	returned, it means finding no exif header or somthing error
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 exif_open_jpeg_file(void* file_name_p)
{
   FSAL_Status eFSALRet;
   kal_uint16 marker,JumpDest,halfword,tag,type;
   kal_uint8 byte0,i,byte[2];
   kal_bool Exif_Found=KAL_FALSE;
   
   if(exif_decoder_state!=EXIF_DEC_IDLE_STATE)
      exif_close_jpeg_file();
   
   eFSALRet = FSAL_Open(&exif_FSAL,file_name_p, FSAL_READ);
   
   if(eFSALRet !=FSAL_OK)
   {
      return 0;
   }
   FSAL_SetBuffer(&exif_FSAL, EXIF_PARSER_BUFFER_SIZE,exif_parser_buffer);
   
   eFSALRet = FSAL_Direct_GetFileSize(&exif_FSAL,&exif_FileSize);
   
   if(eFSALRet !=FSAL_OK)
   {
      return 0;
   }
   
   /* Check if it's a jpeg file */
   if(FSAL_Read_Bytes(&exif_FSAL, byte,2)==FSAL_OK)
   {
      if(byte[0]!=0xff || byte[1]!=0xD8)
         return 0;
   }
   
   while(!Exif_Found && _exif_get_next_marker(&marker))
   {
      //printf("exif_FSAL.uFileOffset: %d, marker:%x\n",exif_FSAL.uFileOffset,marker);
      
      if(marker>0xffe1 && marker<= 0xffef)
         marker=0xffe0;
      
      switch(marker)
      {
         case 0xffe0:
         
            if(_exif_direct_read_uint16(&JumpDest)!=FSAL_OK) return 0;
            
            JumpDest-=2;
            _exif_seek_buffer(JumpDest,FS_FILE_CURRENT);
            
            break;
         case 0xffe1:
            if(_exif_direct_read_uint16(&JumpDest)!=FSAL_OK) return 0;
            
            //JumpDest+=(exif_FSAL.uFileOffset-2);
            JumpDest-=2;
            
            
            Exif_Found=KAL_TRUE;
            for(i=0;i<6;i++)
            {
               if(_exif_read_uint8(&byte0)!=FSAL_OK) return 0;
               Exif_Found &=(byte0 == exif_Header[i+4]);
            }
            
            if(!Exif_Found)
            {
               _exif_seek_buffer(JumpDest,FS_FILE_CURRENT);
               Exif_Found=KAL_FALSE;
               break;
            }
            
            if(_exif_direct_read_uint16(&exif_ByteOrder)!=FSAL_OK) return 0;
            
            if(exif_ByteOrder!= EXIF_BIG_ENDIAN && exif_ByteOrder!= EXIF_LITTLE_ENDIAN)
            {
               _exif_seek_buffer(JumpDest,FS_FILE_CURRENT);
               Exif_Found=KAL_FALSE;
               break;
            }
            
            if(_exif_read_uint16(&halfword)!=FSAL_OK) return 0;
            
            if(halfword !=0x002a)
            {
               _exif_seek_buffer(JumpDest,FS_FILE_CURRENT);
               Exif_Found=KAL_FALSE;
            }
            break;
         case 0xffdb:
         case 0xffc0:
            return 0;
         
         default :
            break;
      }
   }
   
   //-- Exif Found!! --
   exif_TiffOffset=exif_FSAL.uFileOffset-4;
   
   if(_exif_read_uint32(&exif_IFD0_entry_pos)!=FSAL_OK) return 0;
   
   if(exif_IFD0_entry_pos<8) return 0;
   
   _exif_seek_buffer(exif_IFD0_entry_pos-8,FS_FILE_CURRENT);
   
   if(_exif_read_uint16(&exif_IFD0_entry_num)!=FSAL_OK) return 0;
   
   exif_IFD0_entry_pos+=exif_TiffOffset;
   
   //printf("IFD0_pos:%x,  IFD0 num:%x\n",exif_IFD0_entry_pos,exif_IFD0_entry_num);
   
   exif_ReqBufferSize=0;
   exif_ExifIFD_entry_pos=0;
   exif_ExifIFD_entry_num=0;
   
   //--acc IFD0--
   for(i=0;i<exif_IFD0_entry_num;i++)
   {
      if(_exif_read_uint16(&tag)!=FSAL_OK) return 0;
      if(_exif_read_uint16(&type)!=FSAL_OK) return 0;
      
      _exif_parse_acc_tag(tag,type);
      //printf("IFD0 tag:%x, type:%d ,Reqsize:%d\n",tag,type,exif_ReqBufferSize);
      
      if(tag==0x8769)
      {
         _exif_seek_buffer(4,FS_FILE_CURRENT);
         if(_exif_read_uint32(&exif_ExifIFD_entry_pos)!=FSAL_OK) return 0;
         
         exif_ExifIFD_entry_pos+=exif_TiffOffset;
      }
      else
         _exif_seek_buffer(8,FS_FILE_CURRENT);
   }
   
   //--acc ExifIFD--
   if(exif_ExifIFD_entry_pos>0)
   {
      _exif_seek_buffer(exif_ExifIFD_entry_pos,FS_FILE_BEGIN);
      if(_exif_read_uint16(&exif_ExifIFD_entry_num)!=FSAL_OK) return 0;
   }
   
   for(i=0;i<exif_ExifIFD_entry_num;i++)
   {
      if(_exif_read_uint16(&tag)!=FSAL_OK) return 0;
      if(_exif_read_uint16(&type)!=FSAL_OK) return 0;
   
      _exif_parse_acc_tag(tag,type);
      //printf("IFD0 tag:%x, type:%d ,Reqsize:%d\n",tag,type,exif_ReqBufferSize);
      _exif_seek_buffer(8,FS_FILE_CURRENT);
   }
   
   exif_ReqBufferSize+=(sizeof(tag) * (exif_IFD0_entry_num+exif_ExifIFD_entry_num));
   exif_ReqBufferSize+=(sizeof(void*) * (exif_IFD0_entry_num+exif_ExifIFD_entry_num));
   
   /* Force to 4 byte align */
   exif_ReqBufferSize+=3;
   
   exif_decoder_state=EXIF_DEC_PREPROCESS_DONE_STATE;
   return exif_ReqBufferSize;
}

/*************************************************************************
* FUNCTION
*   exif_parse_jpeg_file()
*
* DESCRIPTION
*   This function is to parse the exif header of a jpeg file.
*   Before calling this function, one should move the decoder state to
*   EXIF_DEC_PREPROCESS_DONE_STATE by calling exif_open_jpeg_file().
*
* PARAMETERS
*   R_Buffer (Required Buffer for storing the result)
*
* RETURNS
*   Whether the parsing procedure finshied succeffuly
*
* GLOBALS AFFECTED
*
*************************************************************************/
EXIF_DEC_RESULT exif_parse_jpeg_file(kal_uint8* const R_Buffer,kal_uint32 BufferSize)
{
   kal_uint16 i;
   exif_dec_entry_struct Exif_entry;
   
   if(exif_decoder_state!=EXIF_DEC_PREPROCESS_DONE_STATE)
      return EXIF_FILE_NOT_OPEN;
   
   if(BufferSize < exif_ReqBufferSize)
      return EXIF_DEC_BUFFER_OVERFLOW;
   
   exif_tagArr=(kal_uint16*)R_Buffer;
   
   /* force to 4 byte align */
   exif_valueArr=(kal_char**)((((kal_uint32)R_Buffer+2*(exif_IFD0_entry_num+exif_ExifIFD_entry_num)+3)>>2)<<2);
   
   exif_UsedBufferSize=(sizeof(Exif_entry.tag)+ sizeof(void*)) * (exif_IFD0_entry_num+exif_ExifIFD_entry_num)+4;
   
   //printf("R_Buffer:%d tagArr:%d, valueArr:%d, value_offset:%d\n",R_Buffer,tagArr,valueArr,value_offset);
   //printf("exif_IFD0_entry_num:%d exif_ExifIFD_entry_num:%d\n",exif_IFD0_entry_num,exif_ExifIFD_entry_num);
   
   for(i=0;i<exif_IFD0_entry_num;i++)
   {
      exif_valueArr[i]=0;
      _exif_seek_buffer(exif_IFD0_entry_pos+2+i*12,FS_FILE_BEGIN);
      
      if(_exif_read_uint16(&Exif_entry.tag)!=FSAL_OK) return EXIF_DEC_FILE_READ_ERROR;
      if(_exif_read_uint16(&Exif_entry.type)!=FSAL_OK) return EXIF_DEC_FILE_READ_ERROR;
      if(_exif_read_uint32(&Exif_entry.count)!=FSAL_OK) return EXIF_DEC_FILE_READ_ERROR;
      if(_exif_read_uint32(&Exif_entry.value)!=FSAL_OK) return EXIF_DEC_FILE_READ_ERROR;
      
      
      exif_tagArr[i]=Exif_entry.tag;
      
      //printf("IFD0, tag:%x, type:%d, count:%d\n",Exif_entry.tag,Exif_entry.type,Exif_entry.count);
      
      exif_UsedBufferSize+=_exif_set_entry(&exif_valueArr[i],(kal_char*)(R_Buffer+exif_UsedBufferSize),&Exif_entry);
      
      //printf("value_offset:%d\n",value_offset);
   
   }
   
   for(i=exif_IFD0_entry_num;i<exif_IFD0_entry_num+exif_ExifIFD_entry_num;i++)
   {
      exif_valueArr[i]=0;
      _exif_seek_buffer(exif_ExifIFD_entry_pos+2+(i-exif_IFD0_entry_num)*12,FS_FILE_BEGIN);
      
      if(_exif_read_uint16(&Exif_entry.tag)!=FSAL_OK) return EXIF_DEC_FILE_READ_ERROR;
      if(_exif_read_uint16(&Exif_entry.type)!=FSAL_OK) return EXIF_DEC_FILE_READ_ERROR;
      if(_exif_read_uint32(&Exif_entry.count)!=FSAL_OK) return EXIF_DEC_FILE_READ_ERROR;
      if(_exif_read_uint32(&Exif_entry.value)!=FSAL_OK) return EXIF_DEC_FILE_READ_ERROR;
      
      
      exif_tagArr[i]=Exif_entry.tag;
      
      //printf("ExifIFD, tag:%x, type:%d, count:%d",Exif_entry.tag,Exif_entry.type,Exif_entry.count);
      
      exif_UsedBufferSize+=_exif_set_entry(&exif_valueArr[i],(kal_char*)(R_Buffer+exif_UsedBufferSize),&Exif_entry);
      
      //printf("value_offset:%d\n",value_offset);
   
   }
   
   
   exif_decoder_state=EXIF_DEC_PARSE_DONE_STATE;
   return EXIF_DEC_DONE;
}


/*************************************************************************
* FUNCTION
*   exif_get_tag_value()
*
* DESCRIPTION
*   This function is to retrive tag description string from a jpeg file.
*   Before calling this function, one should move the decoder state to
*   EXIF_DEC_PARSE_DONE_STATE by calling exif_parse_jpeg_file().
*
* PARAMETERS
*   kal_uint16 tag
*
* RETURNS
*   kal_char* description, the conetnt of the tag.
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_char* exif_get_tag_value(kal_uint16 tag)
{
   kal_uint16 i;
   
   if(exif_decoder_state!= EXIF_DEC_PARSE_DONE_STATE)
      return 0;
   
   for(i=0;i<exif_IFD0_entry_num+exif_ExifIFD_entry_num;i++)
   {
      if(tag==exif_tagArr[i])
         return exif_valueArr[i];
   }
   
   return 0;
}

/*************************************************************************
* FUNCTION
*   exif_close_jpeg_file()
*
* DESCRIPTION
*   This function is to close a jpeg file and clear the internal variables
*
* PARAMETERS
*   
*
* RETURNS
*   
*
* GLOBALS AFFECTED
*
*************************************************************************/
void exif_close_jpeg_file(void)
{
   exif_tagArr=0;
   exif_valueArr=0;
   FSAL_Close(&exif_FSAL);
   exif_decoder_state=EXIF_DEC_IDLE_STATE;
   
   exif_ByteOrder=0;
   exif_TiffOffset=0;
   exif_ReqBufferSize=0;
   exif_FileSize=0;
   
   //--IFD0 para--
   exif_IFD0_entry_pos=0;
   exif_IFD0_entry_num=0;
   
   //--ExifIFD para--
   exif_ExifIFD_entry_pos=0;
   exif_ExifIFD_entry_num=0;
}

#endif

/***************Used for picture-bridge*****************/
#if (defined(PICTBRIDGE_SUPPORT))

kal_bool exif_parse_jpeg_header(void* file_name_p,exif_header_info_struct* info)
{
   //STFSAL jpeg_FSAL;
   FSAL_Status eFSALRet = FSAL_OK;
   kal_bool return_value = KAL_TRUE;
   kal_uint16 marker = 0, JumpDest = 0;
   kal_uint8 byte[2];
   kal_uint8 buffer[EXIF_JPEG_PARSER_BUFFER_SIZE];
   
   eFSALRet = FSAL_Open(&exif_FSAL,file_name_p, FSAL_READ);
   
   if(eFSALRet !=FSAL_OK)
   {
      return KAL_FALSE;
   }
   FSAL_SetBuffer(&exif_FSAL,EXIF_JPEG_PARSER_BUFFER_SIZE,buffer);
   FSAL_Direct_GetFileSize(&exif_FSAL,&exif_FileSize); 
   
   /* Check if it's a jpeg file */
   if(FSAL_Read_Bytes(&exif_FSAL,byte,2)==FSAL_OK)
   {
      if(byte[0]!=0xff || byte[1]!=0xD8)
      {
         return_value=KAL_FALSE;
         goto end;
      }
   }
   
   while(_exif_get_next_marker(&marker))
   {
      //printf("jpeg_FSAL.uFileOffset: %x, marker:%x\n",jpeg_FSAL.uFileOffset,marker);
      
      if(marker>=0xffe0 && marker<= 0xffef)
         marker=0xffe0;
      
      switch(marker)
      {
         case 0xffdd: //Restart interval
         case 0xffdb: //DQT
         case 0xffe0: //APP
         case 0xffc4://DHT
         {
            if(_exif_direct_read_uint16(&JumpDest)!=FSAL_OK) 
            {
               return_value=KAL_FALSE;
               goto end;
            }
            
            JumpDest-=2;
            _exif_seek_buffer(JumpDest,FS_FILE_CURRENT);
            break;
         }
         
         case 0xffc0: //baseline
         case 0xffc2: //progresive
         {
            if(marker==0xffc2)
               info->progressive=KAL_FALSE;
            else 
               info->progressive=KAL_TRUE;
            
            _exif_seek_buffer(2,FS_FILE_CURRENT); // skip length
            _exif_seek_buffer(1,FS_FILE_CURRENT); // skip precision
            
            _exif_direct_read_uint16(&info->image_height);
            _exif_direct_read_uint16(&info->image_width);
            
            return_value=KAL_TRUE;
            //break;
            goto end;
         }
         
         case 0xFFDA://SOS
         case 0xFFD9://EOI
         default:
            return_value=KAL_FALSE;
            break;
      }
   }
   
   end:
      FSAL_Close(&exif_FSAL);
   return return_value;
}
#endif //(defined(PICTBRIDGE_SUPPORT))
#endif //(defined(EXIF_SUPPORT) || defined(PICTBRIDGE_SUPPORT))


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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

