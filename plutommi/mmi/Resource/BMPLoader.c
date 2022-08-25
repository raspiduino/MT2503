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
 *  BMPLoader.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "ResDevice.h"
#include "ResBytestream.h"
#include "ImgDecoderDef.h"
#include "mmi_features.h"
#include "gui_config.h"
#include "ImageGetDimension.h"
#include "gui_resource_type.h"
#include "WriteResUtil.h"
#include "ResgenLogCAPI.h"

extern FILE *dest_file;
extern int toolFlag;

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
extern FILE *enfb_img_data_file;
extern U32 enfb_offset;
extern U32 enfb_size;
extern MMI_BOOL ENFBAssociatedIDAdded;
#endif

#define BMPLDR_TAG  "BMPLOADER"

#define BMPLDR_LOG_D(format, args...) RES_LOG_D((BMPLDR_TAG), (format) , ##args)
#define BMPLDR_LOG_V(format, args...) RES_LOG_V((BMPLDR_TAG), (format) , ##args)
#define BMPLDR_LOG_W(format, args...) RES_LOG_W((BMPLDR_TAG), (format) , ##args)
#define BMPLDR_LOG_E(format, args...) RES_LOG_E((BMPLDR_TAG), (format) , ##args)


static U8 BMP_load(bytestream *file, bitmap *b, S8 color_depth);

#if(!WINGUI_DIRECT_IMAGE_DISPLAY)
static S32 BMP_write_color(
        U8 *start,
        U8 A,
        U8 R,
        U8 G,
        U8 B,
        S8 dest_color_depth,
        U8 transparent)
{
    switch (dest_color_depth)
    {
        case 32:
        {   
            U32 *color = (U32 *)start;

            if (transparent)
            {
                *color = (U32)RGB_TRANSPARENT_COLOR_32;
            }
            else
            {
                *color = (U32)MMI_RGB_TO_HW_FORMAT_32(A,R,G,B);
            }
            return 4;
            break;
        }
            
        case 24:
        {
            if (transparent)
            {
                *start = (U8)0x56;
                *(start+1) = (U8)0x34;
                *(start+2) = (U8)0x12;
            }
            else
            {
                *start = B;
                *(start+1) = G;
                *(start+2) = R;
            }
            return 3;
            break;
        }
            
        case 16:
        default:
        {
            U16 *color = (U16 *)start;

            if (transparent)
            {
                *color = (U16)RGB_TRANSPARENT_COLOR_16;
            }
            else
            {
                *color = (U16)MMI_RGB_TO_HW_FORMAT_16(A,R,G,B);
            }
            return 2;
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  BMP_write_line
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]         
 *  buffer          [?]         
 *  row_bytes       [IN]        
 *  color_depth     [IN]        
 *  dest_color_depth[IN]        
 *  width           [IN]        
 *  y               [IN]        
 *  palette         [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void BMP_write_line(
        bitmap *b,
        U8 *buffer,
        long int row_bytes,
        S8 color_depth,
        S8 dest_color_depth,
        long int width,
        long int y,
        U8 palette[][3])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 offset;
    U32 boffset = 0;
    U8 color_index;
    U8 data;
    S32 w;
    U8 A, R, G, B;
    U8 transparent = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(row_bytes);
    {
        S32 i, j;
        U8 *bitmap_data = b->data;
        U16 d;
        S32 ret;

        offset = y * b->row_bytes;
        switch (color_depth)
        {
            case 32:
                for (i = 0; i < width; i++)
                {
                    transparent = 0;
                    B = buffer[boffset++];
                    G = buffer[boffset++];
                    R = buffer[boffset++];
                    A = buffer[boffset++];
                    if ((A == 0xFF) && (R == 0x0A) && (G == 0x0B) && (B == 0x0C))
                    {
                        transparent = 1;
                    }
                    ret = BMP_write_color(bitmap_data+offset, A, R, G, B, dest_color_depth, transparent);
                    offset += ret;
                }
                break;
            case 24:
                for (i = 0; i < width; i++)
                {
                    transparent = 0;
                    B = buffer[boffset++];
                    G = buffer[boffset++];
                    R = buffer[boffset++];
                    A = 255;
                    if ((R == 0x0A) && (G == 0x0B) && (B == 0x0C))
                    {
                        transparent = 1;
                    }
                    ret = BMP_write_color(bitmap_data+offset, A, R, G, B, dest_color_depth, transparent);
                    offset += ret;
                }
                break;
            case 16:    /* RGB-555 */
                for (i = 0; i < width; i++)
                {
                    U16 data = 0;

                    data = ((U16*)buffer)[boffset++];
                    
                    transparent = 0;
                    R = ((data >> 10) & 0x1F) << 3;
                    G = ((data >> 5) & 0x1F) << 3;
                    B = (data & 0x1F) << 3;
                    A = 255;
                    if ((R == 0x0A) && (G == 0x0B) && (B == 0x0C))
                    {
                        transparent = 1;
                    }
                    ret = BMP_write_color(bitmap_data+offset, A, R, G, B, dest_color_depth, transparent);
                    offset += ret;
                }
                break;
            case 8:
                for (i = 0; i < width; i++)
                {
                    transparent = 0;
                    color_index = buffer[boffset++];
                    B = palette[color_index][2];
                    G = palette[color_index][1];
                    R = palette[color_index][0];
                    A = 255;
                    if (color_index == 0x00)
                    {
                        transparent = 1;
                    }
                    ret = BMP_write_color(bitmap_data+offset, A, R, G, B, dest_color_depth, transparent);
                    offset += ret;
                }
                break;
            case 4:
                w = (width >> 1);
                if (width & 1)
                {
                    w++;
                }
                for (i = 0; i < w; i++)
                {
                    data = buffer[boffset++];
                    for (j = 0; j < 2; j++)
                    {
                        if (((i << 1) + j) >= width)
                        {
                            break;
                        }
                        transparent = 0;
                        color_index = (U8) ((data >> ((1 - j) << 2)) & 0xf);
                        B = palette[color_index][2];
                        G = palette[color_index][1];
                        R = palette[color_index][0];
                        A = 255;
                        if (color_index == 0x00)
                        {
                            transparent = 1;
                        }
                        ret = BMP_write_color(bitmap_data+offset, A, R, G, B, dest_color_depth, transparent);
                        offset += ret;
                    }
                }
                break;
            case 1:
                w = (width >> 3);
                if (width & 7)
                {
                    w++;
                }
                for (i = 0; i < w; i++)
                {
                    data = buffer[boffset++];
                    for (j = 0; j < 8; j++)
                    {
                        if (((i << 3) + j) >= width)
                        {
                            break;
                        }
                        if (data & (1 << (7 - j)))
                        {
                            transparent = 0;
                            B = 255;
                            G = 255;
                            R = 255;
                            A = 255;
                            ret = BMP_write_color(bitmap_data+offset, A, R, G, B, dest_color_depth, transparent);
                            offset += ret;
                        }
                        else
                        {
                            transparent = 0;
                            B = 0;
                            G = 0;
                            R = 0;
                            A = 0;
                            ret = BMP_write_color(bitmap_data+offset, A, R, G, B, dest_color_depth, transparent);
                            offset += ret;
                        }
                    }
                }
                break;
        }
    }
}
#endif /* (!WINGUI_DIRECT_IMAGE_DISPLAY) */ 


/*****************************************************************************
 * FUNCTION
 *  BMP_load_file_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h           [?]     
 *  file        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void BMP_load_file_header(bitmap_file_header *h, bytestream *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->file_type = bytestream_fgetword(file);
    h->file_size = bytestream_fgetdword(file);
    h->reserved1 = bytestream_fgetword(file);
    h->reserved2 = bytestream_fgetword(file);
    h->bitmap_offset = bytestream_fgetdword(file);
}


/*****************************************************************************
 * FUNCTION
 *  BMP_load_info_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h           [?]     
 *  file        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void BMP_load_info_header(bitmap_info_header *h, bytestream *file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    h->header_size = bytestream_fgetdword(file);
    h->width = bytestream_fgetdword(file);
    h->height = bytestream_fgetdword(file);
    h->number_of_colors = bytestream_fgetword(file);
    h->bits_per_pixel = bytestream_fgetword(file);
    h->compression = bytestream_fgetdword(file);
    h->bitmap_size = bytestream_fgetdword(file);
    h->device_width = bytestream_fgetdword(file);
    h->device_height = bytestream_fgetdword(file);
    h->number_of_colors = bytestream_fgetdword(file);
    h->number_of_important_colors = bytestream_fgetdword(file);
}


#if(!WINGUI_DIRECT_IMAGE_DISPLAY)
/*****************************************************************************
 * FUNCTION
 *  BMP_load
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file            [?]         input bitmap file
 *  b               [?]         output bitmap
 *  color_depth     [IN]        output bitmap color depth
 * RETURNS
 *  
 *****************************************************************************/
static U8 BMP_load(bytestream *file, bitmap *b, S8 color_depth)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bitmap_file_header file_header;
    bitmap_info_header info_header;
    S32 ncolors, i, j, width, height;
    S32 bitmap_size, row_bytes, used_row_bytes, total_bits;
    S32 dest_row_bytes = 0;
    U8 *buffer;
    U8 palette[256][3];
    U32 image_static_row_data[(IMAGE_STATIC_ROW_DATA_SIZE + 3) / 4];   /* Made image_static_row_data as automatic data *///070306 Alpha layer
    U32 image_static_palette[(IMAGE_STATIC_PALETTE_SIZE + 3) / 4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BMP_load_file_header(&file_header, file);
    if (((file_header.file_type & 0xff) != 'B') &&
        ((file_header.file_type >> 8) != 'M'))
    {
        return (0);
    }
    
    BMP_load_info_header(&info_header, file);
    /* info_header.bits_per_pixel; */
    width = info_header.width;
    height = info_header.height;
    ncolors = 1 << info_header.bits_per_pixel;
    if (info_header.bits_per_pixel == 24)
    {
        used_row_bytes = width * 3;
    }
    else if (info_header.bits_per_pixel == 32)
    {
        used_row_bytes = width * 4;
    }
    else if (info_header.bits_per_pixel == 16)
    {
        used_row_bytes = width * 2;
    }
    else if (info_header.bits_per_pixel <= 8)
    {
        total_bits = width * info_header.bits_per_pixel;
        used_row_bytes = total_bits >> 3;   /* total_bits/8 */
        if ((total_bits % 8) > 0)
        {
            used_row_bytes += 1;    /* total_bits%8 */
        }
    }
    else
    {
        return (0);
    }
    
    if ((used_row_bytes % 4) > 0)
    {
        row_bytes = used_row_bytes + (4 - (used_row_bytes % 4));
    }
    else
    {
        row_bytes = used_row_bytes;
    }
    
    if (color_depth <= 8)
    {
        dest_row_bytes = width / (8 / color_depth);
        if ((width % (8 / color_depth)) > 0)
        {
            dest_row_bytes++;
        }
    }
    else
    {
        if (color_depth == 24)
        {
            dest_row_bytes = width * 3;
        }
        else if (color_depth == 32)
        {
            dest_row_bytes = width * 4;
        }
        else if ((color_depth == 12) || (color_depth == 16))
        {
            dest_row_bytes = width * 2;
        }
    }
    
    bitmap_size = dest_row_bytes * height;
    b->xsize = width;
    b->ysize = height;
    b->color_depth = color_depth;
    b->row_bytes = dest_row_bytes;
    
    if (color_depth <= 8)
    {
        // initial image_static_palette
        memset(image_static_palette, 0, (IMAGE_STATIC_PALETTE_SIZE + 3) / 4 * 4);
        b->palette = (U8*) image_static_palette;
    }
    else
    {
        b->palette = NULL;
    }
    
    if (info_header.bits_per_pixel <= 8)
    {
        for (i = 0; i < ncolors; i++)
        {
            palette[i][2] = bytestream_fgetbyte(file);
            palette[i][1] = bytestream_fgetbyte(file);
            palette[i][0] = bytestream_fgetbyte(file);
            bytestream_fgetbyte(file);
        }
    }
    
    bytestream_fseek(file, file_header.bitmap_offset, SEEK_SET);
    buffer = (U8*) image_static_row_data;
    for (j = height - 1; j >= 0; j--)
    {
        for (i = 0; i < row_bytes; i++)
        {
            buffer[i] = bytestream_fgetbyte(file);
        }
        BMP_write_line(b, buffer, row_bytes, (S8) info_header.bits_per_pixel, color_depth, width, j, palette);
    }
    return (1);
}
#endif /* (!WINGUI_DIRECT_IMAGE_DISPLAY) */ 


/*****************************************************************************
 * FUNCTION
 *  BMPLoader
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_filename         [?]     
 *  out_filename        [?]     
 * RETURNS
 *  
 *****************************************************************************/
int BMPLoader(char *in_filename, char *out_filename, S8 color_depth, U8* _9slice_filename, MMI_BOOL is9slice, SetImageProcessData * processData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bitmap outimage;
    FILE *infile;
    FILE *outfile;
    bytestream inimage;
    S32 file_length;
    U8 *buffer;
    S32 i, bitmap_size, total_data_size;
    U8 ret;
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    U32 enfb_width, enfb_height;
    S32 enfb_ret;
#endif
    U32 width, height, width_height;
    S32 data_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    infile = fopen(in_filename, "rb");
    if (infile == NULL)
    {
        BMPLDR_LOG_E("\nErr opening %s", in_filename);
        return 0;
    }

    outfile = fopen(out_filename, "wb+");
    if (outfile == NULL)
    {
        BMPLDR_LOG_E("\nErr creating %s", out_filename);
        fclose(infile);
        return 0;
    }

    fseek(infile, 0, SEEK_END);
    file_length = ftell(infile);
    fseek(infile, 0, SEEK_SET);
    buffer = (U8*) malloc(file_length);
    if (buffer == NULL)
    {
        BMPLDR_LOG_E("\nErr allocating memory of size %d bytes", file_length);
        fclose(infile);
        fclose(outfile);
        return 0;
    }

    fread(buffer, 1, file_length, infile);
    fclose(infile);
    bytestream_initialize(&inimage, buffer, file_length);

    U32 * image_static_buffer = NULL;
    image_static_buffer = malloc( (IMAGE_STATIC_BUFFER_SIZE + 3) / 4 * 4);
    memset(image_static_buffer, 0, (IMAGE_STATIC_PALETTE_SIZE + 3) / 4 * 4);
    outimage.data = image_static_buffer;

    ret = BMP_load(&inimage, &outimage, color_depth/*__MMI_DEVICE_BMP_FORMAT__*/);
    if (ret == 0)
    {
        BMPLDR_LOG_E("Format not supported %s", in_filename);
        free(buffer);
        fclose(outfile);
        free(image_static_buffer);
        return 0;
    }
    bitmap_size = outimage.row_bytes * outimage.ysize;
    total_data_size = bitmap_size + 13;
    if ((total_data_size >> 24) > 0)
    {
        fprintf(stderr, "image is too big:%s\n", in_filename);
    }

    if (Image_Get_Dimensions(in_filename, &width, &height) >= 0)
    {
        width_height = ((width & 0XFFF) << 12) | (height & 0XFFF);
    }
    else
    {
        BMPLDR_LOG_E("Get dimensions failed:\t%s", in_filename);
        free(image_static_buffer);
        return 0;
    }
    
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    enfb_ret = Image_Test(in_filename, &enfb_width, &enfb_height, processData->disable_enfb);
    if (enfb_ret != ENFB_IMAGE_NONE)
    {
        processData->enfb_flag = 1;
        if (enfb_ret == ENFB_IMAGE_ASSOCIATE)
        {
            ENFBAssociatedIDAdded = MMI_TRUE;
        }
    }
#endif

    if (processData)
    {
        processData->res_size = total_data_size;
    }
    data_size = total_data_size;
    
    if (is9slice) 
        data_size += 20;

    if (toolFlag == 1)
    {
        /* resource header */
        if (is9slice)
            fprintf(dest_file, "%c", IMAGE_TYPE_9SLICE);
        else             
            fprintf(dest_file, "%c", 0x04);
        fprintf(dest_file, "%c", 0x01);
        total_data_size = bitmap_size + 13;
        fprintf(
            dest_file,
            "%c%c%c",
            (data_size & 0x000000ff),
            (data_size & 0x0000ff00) >> 8,
            (data_size & 0x00ff0000) >> 16);
        fprintf(
            dest_file,
            "%c%c%c",
            (width_height & 0x000000ff),
            (width_height & 0x0000ff00) >> 8,
            (width_height & 0x00ff0000) >> 16);
        
        if (is9slice)
        {
            /* Write 9slice file header */
            mmi_rg_write_9slice_header(IMAGE_TYPE_DEVICE_BITMAP, _9slice_filename, dest_file, MMI_TRUE);
        }
        
        /* BMP resource header */
        fprintf(
            dest_file,
            "%c%c%c%c",
            (outimage.xsize & 0x000000ff),
            (outimage.xsize & 0x0000ff00) >> 8,
            (outimage.xsize & 0x00ff0000) >> 16,
            (outimage.xsize & 0xff000000) >> 24);
        fprintf(
            dest_file,
            "%c%c%c%c",
            (outimage.ysize & 0x000000ff),
            (outimage.ysize & 0x0000ff00) >> 8,
            (outimage.ysize & 0x00ff0000) >> 16,
            (outimage.ysize & 0xff000000) >> 24);
        fprintf(dest_file, "%c", outimage.color_depth);
        fprintf(
            dest_file,
            "%c%c%c%c",
            (outimage.row_bytes & 0x000000ff),
            (outimage.row_bytes & 0x0000ff00) >> 8,
            (outimage.row_bytes & 0x00ff0000) >> 16,
            (outimage.row_bytes & 0xff000000) >> 24);

        for (i = 0; i < bitmap_size; i++)
        {
            fprintf(dest_file, "%c", outimage.data[i]);
        }
    }
    
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    /* write ENFB header to CustImgDataxxx.h and
     * image header/data to ENFB image data file */
    else if (processData->enfb_flag == 1) 
    {
        enfb_size = 21 + bitmap_size;
        
        if (is9slice) 
            enfb_size += 20;
    
        /* write ENFB header to CustImgDataxxx.h */
        fprintf(
            outfile,
            "\n{\t0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X\t};\n",
            (U8) 255,//type
            (U8) ENFBAssociatedIDAdded,//associated id
            (U8) 0,//reserved
            (U8) 0,//reserved
            (U8) (enfb_offset & 0xff),
            (U8) ((enfb_offset >> 8) & 0xff),
            (U8) ((enfb_offset >> 16) & 0xff),
            (U8) ((enfb_offset >> 24) & 0xff),
            (U8) (enfb_size & 0xff),
            (U8) ((enfb_size >> 8) & 0xff),
            (U8) ((enfb_size >> 16) & 0xff),
            (U8) ((enfb_size >> 24) & 0xff));
        
        /* image header/data to ENFB image data file */
        /* resource header */
        if (is9slice)
            fprintf(enfb_img_data_file, "%c", IMAGE_TYPE_9SLICE);
        else          
            fprintf(enfb_img_data_file, "%c", 0x04);
        fprintf(enfb_img_data_file, "%c", 0x01);
        total_data_size = bitmap_size + 13;
        fprintf(
            enfb_img_data_file,
            "%c%c%c",
            (data_size & 0x000000ff),
            (data_size & 0x0000ff00) >> 8,
            (data_size & 0x00ff0000) >> 16);
        fprintf(
            enfb_img_data_file,
            "%c%c%c",
            (width_height & 0x000000ff),
            (width_height & 0x0000ff00) >> 8,
            (width_height & 0x00ff0000) >> 16);

        if (is9slice)
        {
            /* Write 9slice file header */
            mmi_rg_write_9slice_header(IMAGE_TYPE_DEVICE_BITMAP, _9slice_filename, enfb_img_data_file, MMI_TRUE);
        }
        
        /* BMP resource header */
        fprintf(
            enfb_img_data_file,
            "%c%c%c%c",
            (outimage.xsize & 0x000000ff),
            (outimage.xsize & 0x0000ff00) >> 8,
            (outimage.xsize & 0x00ff0000) >> 16,
            (outimage.xsize & 0xff000000) >> 24);
        fprintf(
            enfb_img_data_file,
            "%c%c%c%c",
            (outimage.ysize & 0x000000ff),
            (outimage.ysize & 0x0000ff00) >> 8,
            (outimage.ysize & 0x00ff0000) >> 16,
            (outimage.ysize & 0xff000000) >> 24);
        fprintf(enfb_img_data_file, "%c", outimage.color_depth);
        fprintf(
            enfb_img_data_file,
            "%c%c%c%c",
            (outimage.row_bytes & 0x000000ff),
            (outimage.row_bytes & 0x0000ff00) >> 8,
            (outimage.row_bytes & 0x00ff0000) >> 16,
            (outimage.row_bytes & 0xff000000) >> 24);

        for (i = 0; i < bitmap_size; i++)
        {
            fprintf(enfb_img_data_file, "%c", outimage.data[i]);
        }
        
        enfb_offset += enfb_size;
        processData->enfb_flag = 0;
    }
#endif
    
    else    /* Write to .c .h file */
    {
        fprintf(outfile, "{\n\t");

        /* resource header */
        if (is9slice)
            fprintf(outfile, "0x%02X, ", IMAGE_TYPE_9SLICE);
        else        
            fprintf(outfile, "0x%02X, ", 0x04);
        fprintf(outfile, "0x%02X, ", 0x01);
        total_data_size = bitmap_size + 13;
        fprintf(
            outfile,
            "0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X,\n\t",
            (data_size & 0x000000ff),
            (data_size & 0x0000ff00) >> 8,
            (data_size & 0x00ff0000) >> 16,
            (width_height & 0x000000ff),
            (width_height & 0x0000ff00) >> 8,
            (width_height & 0x00ff0000) >> 16);

        if (is9slice)
        {
            /* Write 9slice file header */
            ResgenImageOutStream * outstream;
            ImageOutStreamInit(&outstream);
            mmi_rg_write_9slice_header(IMAGE_TYPE_DEVICE_BITMAP, _9slice_filename, outstream, MMI_FALSE);
            ImageOutStreamOutputFile(outstream, outfile);
            ImageOutStreamDeinit(&outstream);
        }

        /* BMP resource header */
        fprintf(
            outfile,
            "0x%02X, 0x%02X, 0x%02X, 0x%02X, ",
            (outimage.xsize & 0x000000ff),
            (outimage.xsize & 0x0000ff00) >> 8,
            (outimage.xsize & 0x00ff0000) >> 16,
            (outimage.xsize & 0xff000000) >> 24);
        fprintf(
            outfile,
            "0x%02X, 0x%02X, 0x%02X, 0x%02X, ",
            (outimage.ysize & 0x000000ff),
            (outimage.ysize & 0x0000ff00) >> 8,
            (outimage.ysize & 0x00ff0000) >> 16,
            (outimage.ysize & 0xff000000) >> 24);
        fprintf(outfile, "0x%02X, ", outimage.color_depth);
        fprintf(
            outfile,
            "0x%02X, 0x%02X, 0x%02X, 0x%02X, ",
            (outimage.row_bytes & 0x000000ff),
            (outimage.row_bytes & 0x0000ff00) >> 8,
            (outimage.row_bytes & 0x00ff0000) >> 16,
            (outimage.row_bytes & 0xff000000) >> 24);

        for (i = 0; i < bitmap_size; i++)
        {
            if ((i % 16) == 0)
            {
                fprintf(outfile, "\n\t");
            }
            fprintf(outfile, "0x%02X, ", outimage.data[i]);
        }
        fprintf(outfile, "\n};");
    }

    fclose(outfile);
    free(buffer);
    free(image_static_buffer);
    return 1;
}

