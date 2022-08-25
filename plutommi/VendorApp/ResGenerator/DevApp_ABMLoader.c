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
*  LAWS PRINCIPLES.	ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  ABMLoader.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  Alpha BitMap (ABM) encoder
 *
 *  1. The search algorithm of the color index table is binary search.
 *  2. The ABM encoder only support 8, 24, and 32-bit bitmap input.
 *  3. ABM only supports up to 65536 colors.
 *  4. The ABM palette color format is:
 *     a. 16-bit for 16-bit MAIN BASE LAYER (MOST CASE)
 *     b. 24-bit for 24-bit and 32-bit MAIN BASE LAYER
 * 
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *			   HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * THIS FILE IS USED FOR RESOURCE GENERATOR AND MTE ONLY.
 */
#if !defined(__MTK_TARGET__) || defined(__RESOURCE_GEN_)

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include <stdio.h>
#include "MMI_features.h"
#include "ABMLoader.h"
#include "gui_resource_type.h"

#include "gdi_include.h"
#include "gdi_image_alpha_bmp_v2_internal.h"

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
#include "ImageGetDimension.h"
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

/*RHR*/
#include "MMIDataType.h"

/***************************************************************************** 
 * extern variable
 *****************************************************************************/
extern S32 g_ressize;
extern int toolFlag;
extern FILE *dest_file;
extern MMI_BOOL g_is9slice;
extern void mmi_rg_write_9slice_header(U8 real_imagetype, FILE *outfile, MMI_BOOL is_binary);

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
extern FILE *enfb_img_data_file;
extern int enfbFlag;
extern U32 enfb_offset;
extern U32 enfb_size;
extern MMI_BOOL ENFBAssociatedIDAdded;
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
/* check 16-bit RGB color format */
#define RGB_16_BIT_TYPE         DRV_RGB_TO_HW(0, 255, 0)
#define COLOR_FORMAT_RGB3553    0xE007  /* 6205B, 6218 */
#define COLOR_FORMAT_RGB565     0x07E0  /* other than 6205B and 6218 */


/*
 * color primitives
 */
#define GET_32(bp)  ((U32)((bp)[0] | ((bp)[1] << 8) | ((bp)[2] << 16) | ((bp)[3] << 24)))
#define GET_24(bp)  ((U32)((bp)[0] | ((bp)[1] << 8)) | ((bp)[2] << 16))
#define GET_16(bp)  ((U32)((bp)[0] | ((bp)[1] << 8)))
    
#define PUT_16(mem, c)  *((U16*)(mem)) = (c)
#define PUT_24(mem, c)             \
    do                             \
    {                              \
        U8 *mem_8 = (U8*)(mem);    \
        mem_8[0] = (c);            \
        mem_8[1] = (c) >> 8;       \
        mem_8[2] = (c) >> 16;      \
    } while (0)
    
#define ARGB(a, r, g, b)            (((a) << 24) | ((r) << 16) | ((g) << 8) | (b))
#define RGB(r, g, b)                (((r) << 16) | ((g) << 8) | (b))
    
/* RGB888 */
#define R_OF_RGB888(c)              (((c) <<  8) >> 24)
#define G_OF_RGB888(c)              (((c) << 16) >> 24)
#define B_OF_RGB888(c)              (((c) << 24) >> 24)
    
/* ARGB8888 */
#define A_OF_ARGB8888(c)            ((c) >> 24)
#define R_OF_ARGB8888(c)            R_OF_RGB888(c)
#define G_OF_ARGB8888(c)            G_OF_RGB888(c)
#define B_OF_ARGB8888(c)            B_OF_RGB888(c)
    
/* RGB565 */
#define R_OF_RGB565(c)              (((c) << 16) >> 27)
#define G_OF_RGB565(c)              (((c) << 21) >> 26)
#define B_OF_RGB565(c)              (((c) << 27) >> 27)
    
/* RGB3553 */
#define R_OF_RGB3553(c)             (((c) << 24) >> 27)
#define G_OF_RGB3553(c)             ((((c) & 0x7) << 3) | (((c) >> 13) & 0x7))
#define B_OF_RGB3553(c)             (((c) << 19) >> 27)
 
/* RGB16 */
#define R_OF_RGB16(c)               ((RGB_16_BIT_TYPE == COLOR_FORMAT_RGB565) ? R_OF_RGB565(c) : R_OF_RGB3553(c))
#define G_OF_RGB16(c)               ((RGB_16_BIT_TYPE == COLOR_FORMAT_RGB565) ? G_OF_RGB565(c) : G_OF_RGB3553(c))
#define B_OF_RGB16(c)               ((RGB_16_BIT_TYPE == COLOR_FORMAT_RGB565) ? B_OF_RGB565(c) : B_OF_RGB3553(c))

#define RGB565(r, g, b)             (((r) << 11) | ((g) << 5) | (b))
#define RGB3553(r, g, b)            (((r) << 3) | ((b) << 8) | ((g) >> 3) | (((g) & 0x7) << 13))
    
#define ARGB8888_TO_RGB565(c)       RGB565(R_OF_ARGB8888(c) >> 3, G_OF_ARGB8888(c) >> 2, B_OF_ARGB8888(c) >> 3)
#define ARGB8888_TO_RGB3553(c)      RGB3553(R_OF_ARGB8888(c) >> 3, G_OF_ARGB8888(c) >> 2, B_OF_ARGB8888(c) >> 3)

#define ARGB8888_TO_RGB16(c)        ((RGB_16_BIT_TYPE == COLOR_FORMAT_RGB565) ? ARGB8888_TO_RGB565(c) : ARGB8888_TO_RGB3553(c))


/* 
 * color reduction algorithms
 */
#define COLOR_REDUCE_24_TO_16(c)    ((c) & 0xFFF8FCF8)  /* clear R[2:0], G[1:0], B[2:0] */
#define COLOR_REDUCE_24_TO_18(c)    ((c) & 0xFFFCFCFC)  /* clear R[1:0], G[1:0], B[1:0] */

// TODO: SHOULD USE COLOR_REDUCE_24_TO_18 for 18-bit panels (to reduce unique colors)
#define COLOR_REDUCE(c)             ((g_abm_palette_bpp == 16) ? COLOR_REDUCE_24_TO_16(c) : (c))


/*
 * ABM bitstream writer
 */
/* initialize bitstream variables */
#define BW_INIT(mem_ptr)                \
    {                                   \
        U32 bits_buf;                   \
        U16 *bits_mem_ptr;              \
        U32 bits_left;                  \
                                        \
        bits_mem_ptr = mem_ptr;         \
        bits_buf = 0;                   \
        bits_left = 0;

/* flush bitstream buffer */
#define BW_END()                        \
        if (bits_left > 0)              \
        {                               \
            *bits_mem_ptr++ = bits_buf; \
        }                               \
    }

/* write bpp bits of data into the bitstream */
#define BW_WRITE(data, bpp)                                     \
    bits_buf |= ((data) & ((1 << (bpp)) - 1)) << bits_left;     \
    bits_left += bpp;                                           \
    if (bits_left >= 16)                                        \
    {                                                           \
        *bits_mem_ptr++ = bits_buf;                             \
        bits_buf >>= 16;                                        \
        bits_left -= 16;                                        \
    }


/* PBM header size */
#define PBM_HEADER_SIZE                 13


/*
 * windows bitmap
 */
#define BITMAPFILEHEADER_SIZE           14
#define BITMAPINFO_HEADER_SIZE          40


/*
 * ABM encoder
 */
#define ABM_MAX_COLOR_NUM               65536                   /* ABM supports up to 65536 colors */
#define ABM_HEADER_SIZE                 12
#define ABM_PALETTE_BPP                 ((MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL == 16) ? 16 : 24)

#define TRANSPARENT_COLOR_24            RGB(10, 11, 12)         /* transparent color of 24-bit bitmap */
#define TRANSPARENT_COLOR_32            ARGB(255, 10, 11, 12)   /* transparent color of 32-bit bitmap */


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef U32 mycolor;

/* abm encoder structure*/
typedef struct
{
    S32     bmp_width;                  /* bitmap width */
    S32     bmp_height;                 /* bitmap height */
    S32     bmp_bpp;                    /* bitmap bits per pixel */
    S32     bmp_palette_num;            /* number of colors in the palette */  
    mycolor bmp_palette[256];           /* bitmap palette (8-bit bpp max) */    
    U8      *bmp_pixel_start_p;         /* pointer to bitmap data */
    U32     line_padding_bytes;         /* line padding bytes */
    
    S32     x1, y1, x2, y2;             /* image bounding box */

    S32     src_key_color_enable;       /* for PBM source key color */
    S32     is_windows_bmp;             /* windows BMP 32-bit is always XRGB8888, not expected ARGB8888. */
    S32     is_fully_opaque;
} abm_enc_struct;

/* color index table */
typedef struct
{
    mycolor color_table[ABM_MAX_COLOR_NUM]; /* color index table */
    S32     color_num;                      /* number of colors in the table */
    
    S32     last_search_idx;                /* last search index */
} color_index_table_struct;

/* Bit-Stream data structure */
typedef struct
{
    U8 *mem_ptr;
    U32 buf;
    U32 buf_bits;
} ab2_bs_struct;


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static U32 g_abm_palette_bpp = ((MMI_MAIN_BASE_LAYER_BITS_PER_PIXEL == 16) ? 16 : 24);
/* file buffer to keep the whole bitmap file */
static U8 g_file_buf[ABMENC_BMP_FILE_BUFFER_SIZE];
static U8 buffer[ABMENC_BMP_FILE_BUFFER_SIZE];

/* color index table */
static color_index_table_struct g_color_idx_tab;
static color_index_table_struct * const cit = &g_color_idx_tab; /* Color Index Table -> cit */

/* abm encoder context */
static abm_enc_struct g_abm_enc;
static abm_enc_struct * const abm_enc = &g_abm_enc;

/* table to calculate ceiling(log2(x)) */
static const U16 log2_table[15] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768};


/***************************************************************************** 
 * static Function
 *****************************************************************************/
static S32  search_color(mycolor search_color);
static void insert_color_at(mycolor c, S32 insert_idx);
static void add_color_if_new(mycolor c);
static U32  get_normal_color_num(void);

static U32  get_file_size(FILE *fp);
static S32  parse_bitmap(U8* bmp_data_p, U32 input_bmp_file_size);

static void update_image_bounding_box(S32 x, S32 y);
static void limit_image_bounding_box(void);

static U32  log2_ceiling(U32 x);

static void abmenc_build_color_index_table(void);
static U32  abmenc_encode(U8* out_mem_p);


/*****************************************************************************
 * FUNCTION
 *  search_color
 * DESCRIPTION
 *  search a color in the color table (binary search)
 * PARAMETERS
 *  search_color       [IN] color to search
 * RETURNS
 *  color index in the color table if found, otherwise ABMENC_COLOR_NOT_FOUND (-1)
 *****************************************************************************/
static S32 search_color(mycolor search_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     start_idx, end_idx, center_idx;
    mycolor c;   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start_idx = 0;
    end_idx = cit->color_num - 1;

    while (start_idx <= end_idx) 
    {
        center_idx = (start_idx + end_idx) / 2;
        c = cit->color_table[center_idx];

        if (search_color < c)
        {
            start_idx = center_idx + 1;
        }
        else if (search_color > c)
        {
            end_idx = center_idx - 1;
        }
        else
        {
            return center_idx;
        }
    } 

    /* keep the search index to speed up the search-and-insert operation, add_color_if_new() */
    cit->last_search_idx = start_idx;

    return ABMENC_COLOR_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  insert_color_at
 * DESCRIPTION
 *  insert a color at a specified index in the color table
 * PARAMETERS
 *  c                [IN] color to add  
 *  insert_idx       [IN] insertion index of the table
 * RETURNS
 *  void
 *****************************************************************************/
static void insert_color_at(mycolor c, S32 insert_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (insert_idx >= ABM_MAX_COLOR_NUM)
    {
        return;
    }    
    
    /* insert at insert_idx */
    for (i = cit->color_num - 1; i >= insert_idx; i--)
    {
        cit->color_table[i + 1] = cit->color_table[i];
    }

    cit->color_table[insert_idx] = c;
    cit->color_num++;    
}


/*****************************************************************************
 * FUNCTION
 *  add_color_if_new
 * DESCRIPTION
 *  add a color if the color does not exist in the table
 * PARAMETERS
 *  c       [IN] color to add
 * RETURNS
 *  void
 *****************************************************************************/
static void add_color_if_new(mycolor c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     insert_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    insert_idx = search_color(c);

    if (insert_idx == ABMENC_COLOR_NOT_FOUND)
    {
        insert_idx = cit->last_search_idx;
    }
    else
    {   /* found in the table, return */
        return;
    }

    insert_color_at(c, insert_idx);
}


/*****************************************************************************
 * FUNCTION
 *  get_normal_color_num
 * DESCRIPTION
 *  get the number of NORMAL colors
 * PARAMETERS
 *  void
 * RETURNS
 *  number of OPAQUE colors (alpha = 255) in the color index table
 *****************************************************************************/
static U32 get_normal_color_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < cit->color_num; i++)
    {
        if (A_OF_ARGB8888(cit->color_table[i]) != 255)
        {
            break;
        }
    }

    return i;
}


/*****************************************************************************
 * FUNCTION
 *  get_file_size
 * DESCRIPTION
 *  return the file size in bytes
 * PARAMETERS
 *  fp       [IN]   file pointer
 * RETURNS
 *  file size in bytes
 *****************************************************************************/
static U32 get_file_size(FILE *fp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32     fpos, file_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* save the current file position */
    fpos = ftell(fp);

    /* seek to the EOF */    
    fseek(fp, 0, SEEK_END);

    /* get file size */
    file_size = ftell(fp);

    /* restore the old file position */
    fseek(fp, fpos, SEEK_SET);

    return file_size;
}


/*****************************************************************************
 * FUNCTION
 *  parse_bitmap
 * DESCRIPTION
 *  parse and verify the bitmap header (BITMAPFILEHEADER and BITMAPINFO)
 * PARAMETERS
 *  bitmap_p       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static S32 parse_bitmap(U8* bmp_data_p, U32 input_bmp_file_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32     bmp_w, bmp_h, bmp_bpp;
    S32     i;
    U32     bi_size;
    U32     compression;
    U32     line_size;

    U8      *pal_color_p;

    mycolor pal_first_color;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check the "BM" magic number */
    if ((bmp_data_p[0] != 'B') || (bmp_data_p[1] != 'M'))
    {
        return ABM_ENC_INPUT_BITMAP_ERROR;
    }

    /* verify the bitmap file size */
    if (GET_32(bmp_data_p + 2) != input_bmp_file_size)
    {
        return ABM_ENC_INPUT_BITMAP_ERROR;
    }

    /* verify the BITMAPINFO HEADER size field */
    bi_size = GET_32(bmp_data_p + 14);
    if (bi_size < BITMAPINFO_HEADER_SIZE)
    {
        return ABM_ENC_INPUT_BITMAP_ERROR;
    }

    /* get bitmap width, height, and bits per pixel */
    bmp_w = GET_32(bmp_data_p + 18);
    bmp_h = GET_32(bmp_data_p + 22);
    bmp_bpp = GET_16(bmp_data_p + 28);

    /* only support 8, 24, and 32 bpp */
    if ((bmp_bpp != 4) && (bmp_bpp != 8) && (bmp_bpp != 24) && (bmp_bpp != 32))
    {
        return ABM_ENC_INPUT_BITMAP_ERROR;
    }

    /* only support bottom-up bitmap */
    if (((S32)bmp_h <= 0) || ((S32)bmp_w <= 0))
    {
        return ABM_ENC_INPUT_BITMAP_ERROR;
    }

    /* limit image dimension to 1024x1024 */
    if (((S32)bmp_h > 1024) || ((S32)bmp_w > 1024))
    {
        return ABM_ENC_INPUT_BITMAP_ERROR;
    }

    /* must be uncompressed (BI_RGB = 0 and BI_BITFIELDS = 3) */
    compression = GET_32(bmp_data_p + 30);
    if ((compression != 0) && (compression != 3))
    {
        return ABM_ENC_INPUT_BITMAP_ERROR;
    }

    /* get the palette color num */
    if (bmp_bpp <= 8)
    {
        abm_enc->bmp_palette_num = GET_32(bmp_data_p + 46);
        if (abm_enc->bmp_palette_num == 0)
        {
            abm_enc->bmp_palette_num = 256;
        }
    }
    else
    {
        abm_enc->bmp_palette_num = 0;
    }

    /* make sure palette color number is 256 maximally */
    if (abm_enc->bmp_palette_num > 256)
    {
        return ABM_ENC_INPUT_BITMAP_ERROR;
    }

    /* line size in bytes */
    if(bmp_bpp == 4)
    {
        abm_enc->line_padding_bytes = ((bmp_w + 7) / 8 * 8 - bmp_w)/2;
    }
    else
    {
        line_size = bmp_bpp * bmp_w / 8;
        abm_enc->line_padding_bytes = (line_size + 3) / 4 * 4 - line_size;
    }
    
    abm_enc->bmp_width = bmp_w;
    abm_enc->bmp_height = bmp_h;
    abm_enc->bmp_bpp = bmp_bpp;

    /* get palette */
    pal_color_p = bmp_data_p + BITMAPFILEHEADER_SIZE + bi_size;
    pal_first_color = GET_32(pal_color_p);

    for (i = 0; i < abm_enc->bmp_palette_num; i++)
    {
        abm_enc->bmp_palette[i] = GET_32(pal_color_p + i * 4);

        /* A of ARGB quad is reserved as 0, convert it to opacity 255 */
        if (abm_enc->src_key_color_enable && (abm_enc->bmp_palette[i] == pal_first_color))
        {   
            /* 
             * The transparency color is the first color in the palette.
             * Any equivalent color is also the transpareny color.
             *
             * ONLY VALID FOR PBM AND BMP FILES.
             */
            abm_enc->bmp_palette[i] = 0;    /* force alpha value 0 */
        }
        else
        {
            abm_enc->bmp_palette[i] |= 0xFF000000; /* opaque color, alpha value 255 */
        }
    }

    /* bitmap pixel start offset */
    abm_enc->bmp_pixel_start_p = bmp_data_p + GET_32(bmp_data_p + 10);

    return ABM_ENC_OK;
}


/*****************************************************************************
 * FUNCTION
 *  load_bmp_file
 * DESCRIPTION
 *  check the givn bitmap file and read into buffer
 * PARAMETERS
 *  buf             [IN]    pointer to buffer
 *  filename        [IN]    the file name to check
 * RETURNS
 *  return 0 if error. otherwise return the size of the file.
  *****************************************************************************/
static U32 load_bmp_file(U8 *buf, const U8 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fp = NULL;
    S32 file_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* open and check the input bitmap file */
    fp = fopen(filename, "rb");
    if (fp == NULL)
    {
        printf("[ABM enc] open file err: %s\n", filename);
        return 0;
    }

    /* get the file size of the input BMP file */
    file_size = get_file_size(fp);

    /* make sure the file buffer size is enough */
    if (file_size > ABMENC_BMP_FILE_BUFFER_SIZE)
    {
        fclose(fp);

        printf("[ABM enc] over buffer size: %s\n", filename);
        return 0;
    }

    /* read the whole file into the memory */
    if (fread(buf, file_size, 1, fp) != 1)
    {
        fclose(fp);
        
        printf("[ABM enc] read buffer err: %s\n", filename);
        return 0;
    }

    /* parse bitmap header */
    if (parse_bitmap(buf, file_size) == ABM_ENC_INPUT_BITMAP_ERROR)
    {
        fclose(fp);

        printf("[ABM enc] parse BMP err, %s\n", filename);
        return 0;
    }

    fclose(fp);
    
    return file_size;
}


/*****************************************************************************
 * FUNCTION
 *  update_image_bounding_box
 * DESCRIPTION
 *  update image bounding box (piggy-back in the first pass)
 * PARAMETERS
 *  x       [IN] x coordinate of non-transparent color
 *  y       [IN] y coordinate of non-transparent color
 * RETURNS
 *  void
 *****************************************************************************/
static void update_image_bounding_box(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x1, x2, y1, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x1 = abm_enc->x1;
    y1 = abm_enc->y1;
    x2 = abm_enc->x2;
    y2 = abm_enc->y2;

    /* x1 = min(x of non-transparent color) */
    if (x < x1)
    {
        x1 = x;
    }

    /* y1 = min(y of non-transparent color) */
    if (y < y1)
    {
        y1 = y;
    }

    /* x2 = max(x of non-transparent color) */
    if (x > x2)
    {
        x2 = x;
    }

    /* y2 = max(y of non-transparent color) */
    if (y > y2)
    {
        y2 = y;
    }

    abm_enc->x1 = x1;
    abm_enc->y1 = y1;
    abm_enc->x2 = x2;
    abm_enc->y2 = y2;
}


/*****************************************************************************
 * FUNCTION
 *  limit_image_bounding_box
 * DESCRIPTION
 *  limit the x1, y1, x2, and y2 within 8-bit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void limit_image_bounding_box(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     w, h, bottom_right_off_w, bottom_right_off_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    w = abm_enc->bmp_width;
    h = abm_enc->bmp_height;

    if (abm_enc->x1 > 255)
    {
        abm_enc->x1 = 255;
    }

    if (abm_enc->y1 > 255)
    {
        abm_enc->y1 = 255;
    }

    bottom_right_off_w = w - 1 - abm_enc->x2;
    if (bottom_right_off_w > 255)
    {
        bottom_right_off_w = 255;
        abm_enc->x2 = w - 1 - bottom_right_off_w;
    }

    bottom_right_off_h = h - 1 - abm_enc->y2;
    if (bottom_right_off_h > 255)
    {
        bottom_right_off_h = 255;
        abm_enc->y2 = h - 1 - bottom_right_off_h;
    }
}


/*****************************************************************************
 * FUNCTION
 *  abmenc_build_color_index_table
 * DESCRIPTION
 *  build the color index table (first pass)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void abmenc_build_color_index_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     x, y, w, h;
    S32     line_padding_bytes;
    U8      *pixel_p, *img_p;
    U8      pixel_nibble_index, last_nibble;
    U32     bmp_bpp;
    mycolor c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w = abm_enc->bmp_width;
    h = abm_enc->bmp_height;
    line_padding_bytes = abm_enc->line_padding_bytes;
    bmp_bpp = abm_enc->bmp_bpp;
    img_p = abm_enc->bmp_pixel_start_p;    

    /* initialize image bounding box */
    abm_enc->x1 = w;
    abm_enc->y1 = h;
    abm_enc->x2 = 0;
    abm_enc->y2 = 0;

    /* first pass: build color index table and find the image bounding box */
    pixel_p = img_p;

    /* Pixel nibble index holds the byte position for pixels. 
     * last_nibble flag is used to determine which nibble to read for the index. (First or last).
     */
    pixel_nibble_index = 0;
    last_nibble = 0;

    for (y = 0; y < h; y++)
    {
        for (x = 0; x < w; x++)
        {
            /* read pixel */
            if (bmp_bpp == 32)
            {   /* 32-bit bitmap */
                c = GET_32(pixel_p);
                pixel_p += 4;
               
                /* Windows 32-bit BMP is always 0x00RRGGBB. */                    
                if (abm_enc->is_windows_bmp)
                {
                    c |= 0xFF000000;
                }

                if (abm_enc->src_key_color_enable && (c == TRANSPARENT_COLOR_32))
                {   /* transparent color, alpha = 0 */
                    c = 0;
                }                
            }
            else if (bmp_bpp == 24)
            {   /* 24-bit bitmap */
                c = GET_24(pixel_p);
                pixel_p += 3;

                if (abm_enc->src_key_color_enable && (c == TRANSPARENT_COLOR_24))
                {   /* transparent color, alpha = 0 */
                    c = 0;
                }
                else
                {   /* opaque color, alpha = 255 */                    
                    c |= 0xFF000000;
                }
            }
            else if(bmp_bpp == 4)
            {   /* 4-bit bitmap */
                /* Alternate reading of nibbles, which are the index for the colors */
                if(!last_nibble)
                {
                    pixel_nibble_index = (U8)*pixel_p;  /* reads the byte for two pixels' indices */
                    pixel_p++;          /* Advances the pixel pointer */

                    /* Set last nibble flag ON to skip reading the byte again in the next pass. 
                      * The index will be read from the last nibble of pixel_nibble_index 
                      */
                    last_nibble = 1;        
                }
                else
                {
                    last_nibble = 0;
                }
                /* Read the nibbles, first nibble */
                c = abm_enc->bmp_palette[(U8)(pixel_nibble_index >> 4)];

                /* Puts the value of last nibble in first nibble */ 
                pixel_nibble_index = pixel_nibble_index  << 4;
            }
            else
            {   /* 8-bit bitmap */
                c = abm_enc->bmp_palette[*pixel_p++];                
            }

            /* add color if the color is not transparent color */
            if (A_OF_ARGB8888(c) != 0)
            {               
                /* only add unique color */
                add_color_if_new(COLOR_REDUCE(c));

                /* update image bounding box (notice bitmap is flipped, so we have to invert y here) */
                update_image_bounding_box(x, h - 1 - y);
            }

            /* containing a transparent color, this image is not fully opaque! */            
            if (A_OF_ARGB8888(c) != 255)
            {
                abm_enc->is_fully_opaque = 0;
            }
        }
        /* End of line. Taking care of padding. Will read first nibble for the next line. */
        last_nibble = 0;
        pixel_p += line_padding_bytes;
    }

    /* handle special case, all transparent color */
    if (abm_enc->x2 < abm_enc->x1)
    {
        /* 1 dummy point at the center of image to make best use of the bounding box*/
        abm_enc->x1 = w / 2;
        abm_enc->y1 = h / 2;
        abm_enc->x2 = abm_enc->x1;
        abm_enc->y2 = abm_enc->y1;
    }    
    
    limit_image_bounding_box();   
}


/*****************************************************************************
 * FUNCTION
 *  log2_ceiling
 * DESCRIPTION
 *  calculate ceiling(log2(x))
 * PARAMETERS
 *  x       [IN]    x must be in the range of [0, 65535]
 * RETURNS
 *  ceiling(log2(x))
 *****************************************************************************/
static U32 log2_ceiling(U32 x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    S32     i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 15; i++)
    {
        if (x <= log2_table[i])
            break;
    }

    return i + 1;
}


/*****************************************************************************
 * FUNCTION
 *  ab2_bs_init
 * DESCRIPTION
 *  Initialize the given bit-stream data structure.
 *  The first data will start at given memory pointer.
 * PARAMETERS
 *  bs              [INOUT] the bit-stream structure to be initialized
 *  mem_ptr         [IN]    the start memory to be a bit-stream
 * RETURNS
 *  void
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE void ab2_bs_init(ab2_bs_struct *bs, U8 *mem_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_ASSERT(bs != NULL);

    bs->mem_ptr     = mem_ptr;
    bs->buf         = 0;
    bs->buf_bits    = 0;
}


/*****************************************************************************
 * FUNCTION
 *  ab2_bs_write
 * DESCRIPTION
 *  Write given bits data to bit-stream. The data must less or equal 16 bits.
 * PARAMETERS
 *  bs              [IN]    the bit-stream
 *  data            [IN]    the bit data to write
 *  bits            [IN]    the number of bits to write (must <= 16)
 * RETURNS
 *  void 
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE void ab2_bs_write(ab2_bs_struct *bs, U32 data, U32 bits)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_ASSERT(bs != NULL);
    //MMI_ASSERT(bits <= 16);
    //MMI_ASSERT(data < (1 << bits));

    bs->buf |= (data << bs->buf_bits);
    bs->buf_bits += bits;
    
    /* write out 16 bits data if enough */
    if (bs->buf_bits >= 16)
    {
        *(U16 *)bs->mem_ptr = (U16)bs->buf;

        bs->buf >>= 16;
        bs->buf_bits -= 16;
        bs->mem_ptr += sizeof(U16);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ab2_bs_flush
 * DESCRIPTION
 *  Flush all data to bit-stream, it will be align to 2-bytes
 * PARAMETERS
 *  bs              [IN]    the bit-stream
 * RETURNS
 *  void 
 *****************************************************************************/
static void ab2_bs_flush(ab2_bs_struct *bs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_ASSERT(bs != NULL);

    if (bs->buf_bits > 0)
    {
        *(U16 *)bs->mem_ptr = (U16)bs->buf;

        bs->buf = 0;
        bs->buf_bits = 0;
        bs->mem_ptr += sizeof(U16);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ab2_bs_offset
 * DESCRIPTION
 *  Caculate the offset according by given base memory location
 * PARAMETERS
 *  bs              [IN]    the bit-stream
 *  base_ptr        [IN]    the base memory location
 * RETURNS
 *  The number of offset
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE U32 ab2_bs_offset(ab2_bs_struct *bs, const U8 *base_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_ASSERT(bs != NULL);
    //MMI_ASSERT(bs->buf_bits == 0);

    return bs->mem_ptr - base_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  ab2enc_color_preprocess
 * DESCRIPTION
 *  Preprocess the color to save to color table:
 *  - Prevent blue channel from saturation to get rid of source key 
 *    checking in the decoder
 *  - Pre-multiply alpha color
 * PARAMETERS
 *  color          [IN]     the color to preprocess
 * RETURNS
 *  The color has been processed
 *****************************************************************************/
static mycolor ab2enc_color_preprocess(mycolor color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mycolor a, r, g, b;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * prevent blue channel 
     */
    if (g_abm_palette_bpp == 16)
    {
        mycolor color16 = ARGB8888_TO_RGB16(color);
        if (B_OF_RGB16(color16) == 0x1F)
        {
            /* 5-bit B: 0x1F -> 0x1E */
            color -= 1 << 3;
        }
    }
    else
    {
        /* 24-bit and 32-bit ABM both use 24-bit palette */
        if (B_OF_ARGB8888(color) == 0xFF)
        {
            /* 8-bit B: 0xFF -> 0xFE */
            color -= 1;
        }
    }

    /* 
     * pre-multiply alpha color 
     */
    a = A_OF_ARGB8888(color);
    r = R_OF_ARGB8888(color);
    g = G_OF_ARGB8888(color);
    b = B_OF_ARGB8888(color);

    r = GDI_IMAGE_AB2_DIV_255(r * a);
    g = GDI_IMAGE_AB2_DIV_255(g * a);
    b = GDI_IMAGE_AB2_DIV_255(b * a);

    return ARGB(0xff - a, r, g, b);
}


/*****************************************************************************
 * FUNCTION
 *  ab2enc_get_pixel_format
 * DESCRIPTION
 *  Decide the pixel format to save to ABM file
 * PARAMETERS
 *  none
 * RETURNS
 *  The pixel format to save
 *****************************************************************************/
static U32 ab2enc_get_pixel_format(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 normal_color_cnt;
    U32 alpha_color_cnt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    normal_color_cnt    = get_normal_color_num();
    alpha_color_cnt     = cit->color_num - normal_color_cnt;
    
    if (abm_enc->src_key_color_enable || alpha_color_cnt == 0)
    {
        if (abm_enc->is_fully_opaque)
        {
            if (g_abm_palette_bpp == 16)
            {   
                return GDI_IMAGE_AB2_FORMAT_RGB565_FULLY_OPAQUE;
            }
            
            return GDI_IMAGE_AB2_FORMAT_RGB888_FULLY_OPAQUE;
        }
        else
        {
            if (g_abm_palette_bpp == 16)
            {   
                return GDI_IMAGE_AB2_FORMAT_RGB565_SRC_KEY;
            }
            
            return GDI_IMAGE_AB2_FORMAT_RGB888_SRC_KEY;
        }            
    }
    else
    {
        if (g_abm_palette_bpp == 16)
        {   
            return GDI_IMAGE_AB2_FORMAT_PARGB8565;
        }
        
        return GDI_IMAGE_AB2_FORMAT_PARGB8888;
    }
}


/*****************************************************************************
 * FUNCTION
 *  ab2enc_get_img_color_idx
 * DESCRIPTION
 *  Get the color index at poisition (x, y) of input image.
 * PARAMETERS
 *  param          [IN]     param usage
 * RETURNS
 *  The color index. 
 *  It will return GDI_IMAGE_AB2_INVALID_COLOR_IDX if error.
 *****************************************************************************/
static GDI_IMAGE_AB2_INLINE U32 ab2enc_get_img_color_idx(U32 x, U32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const bytes_per_pixel  = abm_enc->bmp_bpp / 8;
    const line_pitch_bytes = 
        bytes_per_pixel * abm_enc->bmp_width + abm_enc->line_padding_bytes;

    U8 *pixel_ptr;
    U8 pixel_nibble_index, last_nibble;
    S32 line_pitch_bytes_4bpp;
    
    mycolor color;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Pixel ptr should be specially handled for 4bpp as it will be chosen from nibbles */
    if(abm_enc->bmp_bpp == 4)
    {
        line_pitch_bytes_4bpp = 
            ((abm_enc->bmp_width + 7) / 8 * 8) /2;

        /* Pixel byte position = start address + reverse calculated Y + nibble index in byte for X */
        pixel_ptr = 
            abm_enc->bmp_pixel_start_p + 
            line_pitch_bytes_4bpp * (abm_enc->bmp_height - y - 1) +
            (x - (x % 2))/2;

        /* If x is odd, pixel color index lies in the last nibble. Set the last nibble flag ON */
        last_nibble = x % 2;
    }
    else
    {
        /* BMP file is saved by bottom-up format */
        pixel_ptr = 
            abm_enc->bmp_pixel_start_p + 
            line_pitch_bytes * (abm_enc->bmp_height - y - 1) +
            bytes_per_pixel * x;
    }

    /* read pixel */
    if (abm_enc->bmp_bpp == 32)
    {
        color = GET_32(pixel_ptr);

        /* Windows 32-bit BMP is always 0x00RRGGBB. */                    
        if (abm_enc->is_windows_bmp)
        {
            color |= 0xFF000000;
        }

        if (abm_enc->src_key_color_enable && (color == TRANSPARENT_COLOR_32))
        {
            /* transparent color, alpha = 0 */
            color = 0;
        }                
    }
    else if (abm_enc->bmp_bpp == 24)
    {
        color = GET_24(pixel_ptr);

        if (abm_enc->src_key_color_enable && (color == TRANSPARENT_COLOR_24))
        {   
            /* transparent color, alpha = 0 */
            color = 0;
        }
        else
        {   
            /* opaque color, alpha = 255 */                    
            color |= 0xFF000000;
        }
    }
    else if (abm_enc->bmp_bpp == 8)
    {   
        color = abm_enc->bmp_palette[*pixel_ptr];
    }
    else if(abm_enc->bmp_bpp == 4)
    {   
        /* Use the last_nibble flag as it is an indicator for whther it is for first nibble or last nibble */
        if(!last_nibble )
        {
            /* First nibble contains the color index */
            pixel_nibble_index = (U8)((*pixel_ptr) >> 4);
        }
        else
        {
            /* Last nibble contains the color index */
            pixel_nibble_index = (U8)((*pixel_ptr) & 0x0F);
        }
        color = abm_enc->bmp_palette[pixel_nibble_index];
    }
    else
    {
        return GDI_IMAGE_AB2_INVALID_COLOR_IDX;
    }

    if (A_OF_ARGB8888(color) == 0)
    {   
        /* index 0 is transparent color */
        return 0;
    }
    
    /* index 0 is reserved for transparent color, so +1 */
    return (U32)search_color(COLOR_REDUCE(color)) + 1;
}


/*****************************************************************************
 * FUNCTION
 *  ab2_encode_rle_repeat_code
 * DESCRIPTION
 *  Encode the RLE repeat code.
 * PARAMETERS
 *  os              [IN]    the bit stream to write
 *  color_idx       [IN]    the repeat color index to encode
 *  color_idx_bits  [IN]    the bits of the repeat color index
 *  cnt             [IN]    the number of repeat pixels
 * RETURNS
 *  void
 *****************************************************************************/
static void ab2_encode_rle_repeat_code(
    ab2_bs_struct *os, 
    U32 color_idx, 
    U32 color_idx_bits,
    U32 cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const U32 max_cnt = 128;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (cnt > max_cnt)
    {
        ab2_bs_write(os, max_cnt - 1, 8);
        ab2_bs_write(os, color_idx, color_idx_bits);

        cnt -= max_cnt;
    }

    if (cnt > 0)
    {
        ab2_bs_write(os, cnt - 1, 8);
        ab2_bs_write(os, color_idx, color_idx_bits);
    }
}


/*****************************************************************************
 * FUNCTION
 *  ab2_encode_rle_discount_code
 * DESCRIPTION
 *  Encode the RLE discontinue code.
 * PARAMETERS
 *  os              [IN]    the bit stream to write
 *  x               [IN]    x of the start poisition to encode
 *  y               [IN]    y of the start poisition to encode
 *  color_idx_bits  [IN]    the bits of the repeat color index
 *  cnt             [IN]    the number pixels to encode
 * RETURNS
 *  void
 *****************************************************************************/
static void ab2_encode_rle_discount_code(
    ab2_bs_struct *os, 
    U32 x, 
    U32 y, 
    U32 color_idx_bits,
    U32 cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const U32 max_cnt = 128;
    
    U32 x0 = abm_enc->x1;
    U32 x1 = abm_enc->x2;
    
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (cnt > max_cnt)
    {
        ab2_bs_write(os, 0x80 | (max_cnt - 1), 8);

        for (i = max_cnt; i != 0; i--)
        {
            U32 color_idx = ab2enc_get_img_color_idx(x, y);
            ab2_bs_write(os, color_idx, color_idx_bits);

            /* seek to next image pixel */
            x++;
            if (x > x1)
            {
                x = x0;
                y++;
            }
        }
        
        cnt -= max_cnt;
    } /* while (cnt > max_cnt) */

    if (cnt > 0)
    {
        ab2_bs_write(os, 0x80 | (cnt - 1), 8);

        for (i = cnt; i != 0; i--)
        {
            U32 color_idx = ab2enc_get_img_color_idx(x, y);
            ab2_bs_write(os, color_idx, color_idx_bits);

            /* seek to next image pixel */
            x++;
            if (x > x1)
            {
                x = x0;
                y++;
            }
        }
    } /* if (cnt > 0) */
}


/*****************************************************************************
 * FUNCTION
 *  ab2enc_encode_header
 * DESCRIPTION
 *  Encode the ABM v2 header
 * PARAMETERS
 *  mem_ptr         [IN]     buffer to write header
 * RETURNS
 *  Return the bytes written. If error, it will return 0
 *****************************************************************************/
static U32 ab2enc_encode_header(U8 *mem_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ab2_bs_struct os;

    U32 boundary_left   = abm_enc->x1;
    U32 boundary_top    = abm_enc->y1;
    U32 boundary_right  = abm_enc->bmp_width - 1 - abm_enc->x2;
    U32 boundary_bottom = abm_enc->bmp_height - 1 - abm_enc->y2;
    U32 pixel_format    = ab2enc_get_pixel_format();
    U32 algorithm       = GDI_IMAGE_AB2_ALGORITHM_RLE;

    U32 header_size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ab2_bs_init(&os, mem_ptr);

    ab2_bs_write(&os, (U32)abm_enc->bmp_width,  GDI_IMAGE_AB2_HEADER_WIDTH_BITS);
    ab2_bs_write(&os, (U32)abm_enc->bmp_height, GDI_IMAGE_AB2_HEADER_HEIGHT_BITS);

    ab2_bs_write(&os, boundary_left,    GDI_IMAGE_AB2_HEADER_BOUND_LEFT_BITS);
    ab2_bs_write(&os, boundary_top,     GDI_IMAGE_AB2_HEADER_BOUND_TOP_BITS);
    ab2_bs_write(&os, boundary_right,   GDI_IMAGE_AB2_HEADER_BOUND_RIGHT_BITS);
    ab2_bs_write(&os, boundary_bottom,  GDI_IMAGE_AB2_HEADER_BOUND_BOTTOM_BITS);
    
    ab2_bs_write(&os, pixel_format,     GDI_IMAGE_AB2_HEADER_FORMAT_BITS);
    ab2_bs_write(&os, algorithm,        GDI_IMAGE_AB2_HEADER_ALGORITHM_BITS);
    
    ab2_bs_write(&os, 0,                GDI_IMAGE_AB2_HEADER_RESERVED_1_BITS);

    header_size = ab2_bs_offset(&os, mem_ptr);

    //MMI_ASSERT(header_size == GDI_IMAGE_AB2_HEADER_SIZE);
    
    return header_size;
}


/*****************************************************************************
 * FUNCTION
 *  ab2enc_rle_encode_header
 * DESCRIPTION
 *  Encode ABM v2 RLE header
 * PARAMETERS
 *  mem_ptr         [OUT]    buffer to write header
 * RETURNS
 *  Return the bytes written. If error, it will return 0
 *****************************************************************************/
static U32 ab2enc_rle_encode_header(U8 *mem_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ab2_bs_struct os;
    
    U32 normal_color_cnt;
    U32 alpha_color_cnt;

    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ab2_bs_init(&os, mem_ptr);

    normal_color_cnt    = get_normal_color_num();
    alpha_color_cnt     = cit->color_num - normal_color_cnt;
    
    ab2_bs_write(&os, normal_color_cnt, 16);
    ab2_bs_write(&os, alpha_color_cnt,  16);

    for (i = 0; i < normal_color_cnt; i++)
    {
        mycolor color = ab2enc_color_preprocess(cit->color_table[i]);
        
        if (g_abm_palette_bpp == 16)
        {   
            ab2_bs_write(&os, ARGB8888_TO_RGB16(color), 16);
        }
        else if (g_abm_palette_bpp == 24)
        {
            ab2_bs_write(&os, color & 0xffff, 16);
            ab2_bs_write(&os, color >> 16, 8);
        }
        else
        {
            return 0;
        }
    } /* for (i = 0; i < normal_color_cnt; i++) */ 

    /* align to 2-bytes */
    ab2_bs_flush(&os);
    
    for (; i < normal_color_cnt + alpha_color_cnt; i++)
    {
        mycolor color = ab2enc_color_preprocess(cit->color_table[i]);
        
        if (g_abm_palette_bpp == 16)
        {   
            ab2_bs_write(&os, ARGB8888_TO_RGB16(color), 16);
            ab2_bs_write(&os, A_OF_ARGB8888(color), 8);
        }
        else if (g_abm_palette_bpp == 24)
        {
            ab2_bs_write(&os, color & 0xffff, 16);
            ab2_bs_write(&os, color >> 16, 16);
        }
        else
        {
            return 0;
        }
    } /* for (; i < normal_color_cnt + alpha_color_cnt; i++) */
    
    /* align to 2-bytes */
    ab2_bs_flush(&os);

    return ab2_bs_offset(&os, mem_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  ab2enc_rle_encode_body
 * DESCRIPTION
 *  Encode body of ABM v2 image by RLE
 * PARAMETERS
 *  mem_ptr         [OUT]    buffer to write header
 * RETURNS
 *  Return the bytes written. If error, it will return 0
 *****************************************************************************/
static U32 ab2enc_rle_encode_body(U8 *mem_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ab2_bs_struct os;
    
    U32 total_color_cnt;
    U32 color_idx_bits;
    U32 min_repeat_cnt;
    
    U32 last_color_idx;
    U32 counter;
    
    U32 x0 = abm_enc->x1;
    U32 y0 = abm_enc->y1;
    U32 x1 = abm_enc->x2;
    U32 y1 = abm_enc->y2;
    
    U32 discount_start_x, discount_start_y;
    U32 discount_sure;
    U32 discount_cnt;

    U32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /*
     * prepare encoded data
     */
    ab2_bs_init(&os, mem_ptr);

    /* 1 for transparent color */
    /* caculate the color index bits and the threshole of repeat number*/
    total_color_cnt = cit->color_num + 1;
    color_idx_bits  = log2_ceiling(total_color_cnt);
    min_repeat_cnt  = 1 + ((8 + (color_idx_bits - 1)) / color_idx_bits);

    /*
     * start to encode RLE body
     */
    last_color_idx = GDI_IMAGE_AB2_INVALID_COLOR_IDX;
    counter = 0;

    discount_start_x    = x0;
    discount_start_y    = y0;
    discount_sure       = 0;
    discount_cnt        = 0;

    /* for all image pixels */
    for (j = y0; j <= y1; j++)
    {
        for (i = x0; i <= x1; i++)
        {
            U32 color_idx = ab2enc_get_img_color_idx(i, j);
            if (color_idx != last_color_idx)
            {
                /* discontinue at current position */
                if (counter < min_repeat_cnt)
                {
                    /* repeat pixels is less than threshole, 
                     * counted into discountinue pixels */
                    discount_sure = (discount_cnt != 0);
                    discount_cnt += counter;
                }
                else
                {
                    /* output discount pixels if needed */
                    if (discount_cnt > 0)
                    {
                        if (discount_sure)
                        {
                            ab2_encode_rle_discount_code(
                                &os, 
                                discount_start_x,
                                discount_start_y,
                                color_idx_bits,
                                discount_cnt);
                        }
                        else
                        {
                            U32 iscount_color_index = 
                                ab2enc_get_img_color_idx(
                                    discount_start_x, 
                                    discount_start_y);                            
                            ab2_encode_rle_repeat_code(
                                &os, 
                                iscount_color_index,
                                color_idx_bits,
                                discount_cnt);
                        }

                        discount_sure   = 0;
                        discount_cnt    = 0;
                    }

                    /* output repeat pixels if needed */
                    if (counter > 0)
                    {
                        ab2_encode_rle_repeat_code(
                            &os,
                            last_color_idx,
                            color_idx_bits,
                            counter);

                        counter = 0;
                    }

                    discount_start_x = i;
                    discount_start_y = j;
                }

                last_color_idx = color_idx;
                counter = 1;
            }
            else
            {
                /* same as previous pixel color */
                counter++;
            }
        } /* for (i = x0; i <= x1; i++) */
    } /* for(j = y0; j <= y1; j++) */

    /*
     * Send the retail data
     */
    if (discount_cnt > 0)
    {
        if (counter < min_repeat_cnt)
        {
            discount_cnt += counter;
            counter = 0;
        }
        
        ab2_encode_rle_discount_code(
            &os,
            discount_start_x,
            discount_start_y,
            color_idx_bits,
            discount_cnt);
    }

    if (counter > 0)
    {
        ab2_encode_rle_repeat_code(
            &os,
            last_color_idx,
            color_idx_bits,
            counter);
    }

    /* flush all data of bitstream */
    ab2_bs_flush(&os);

    return ab2_bs_offset(&os, mem_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  ab2enc_encode
 * DESCRIPTION
 *  ABM v2 encoder main routine.
 *  Must prepare the image data and color table by calling 
 *  abmenc_build_color_index_table() before.
 * PARAMETERS
 *  out_mem_p       [OUT] output memory pointer
 * RETURNS
 *  Total ABMv2 data size. If error, it will return 0xffffffff.
 *****************************************************************************/
static U32 ab2enc_encode(U8* out_mem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ab2_header_size = 0;
    U32 rle_header_size = 0;
    U32 rle_body_size   = 0;
    U32 ab2_total_size  = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* out of ABM limit, return a large size to prevent choosing ABM */
    if (cit->color_num >= ABM_MAX_COLOR_NUM)
    {
        return 0xffffffff;
    }

    /* write header */
    ab2_header_size = ab2enc_encode_header(out_mem_p);
    if (ab2_header_size == 0)
    {
        return 0xffffffff;
    }
    out_mem_p += ab2_header_size;

    /* write AB2 RLE header and color table */
    rle_header_size = ab2enc_rle_encode_header(out_mem_p);
    if (rle_header_size == 0)
    {
        return 0xffffffff;
    }
    out_mem_p += rle_header_size;

    /* write AB2 RLE body */
    rle_body_size = ab2enc_rle_encode_body(out_mem_p);
    if (rle_body_size == 0)
    {
        return 0xffffffff;
    }
    out_mem_p += rle_body_size;


    ab2_total_size = ab2_header_size + rle_header_size + rle_body_size;

    return ab2_total_size;
}


/*****************************************************************************
 * FUNCTION
 *  abmenc_encode
 * DESCRIPTION
 *  abm encoder main routine
 * PARAMETERS
 *  out_mem_p       [OUT] output memory pointer
 * RETURNS
 *  ABM data size
 *****************************************************************************/
static U32 abmenc_encode(U8* out_mem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32     x, y, w, h, bottom_right_off_w, bottom_right_off_h;
    S32     bound_box_w, bound_box_h;
    S32     line_padding_bytes;
    U8      *img_p, *mem8_p;
    U32     p;
    U32     bpp;
    U16     *mem16_p;
    S32     normal_color_num, alpha_color_num, color_num;
    S32     i;

    U32     abm_size;
    U32     bmp_bpp;
    mycolor c, color16;
    mycolor a, r, g, b;
    U32     bytes_per_pixel;

    U32     bitstream_padding_byte;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w = abm_enc->bmp_width;
    h = abm_enc->bmp_height;   
    
    bmp_bpp = abm_enc->bmp_bpp;
    line_padding_bytes = abm_enc->line_padding_bytes;

    /* out of ABM limit, return a large size to prevent choosing ABM */
    if (cit->color_num >= ABM_MAX_COLOR_NUM)
    {
        return 0xFFFFFFFF;
    }

    color_num = cit->color_num + 1;                 /* 1 for transparent color 0 */
    normal_color_num = get_normal_color_num() + 1;  /* 1 for transparent color 0 */
    alpha_color_num = color_num - normal_color_num;
    bpp = log2_ceiling(color_num);
    
    /* 
     * fill the ABM 12-byte header 
     */
    mem16_p = (U16*)out_mem_p;
    mem16_p[0] = w;    
    mem16_p[1] = h;

    /* store fully opaque flag on the width MSB */
    if (abm_enc->is_fully_opaque)
    {
        mem16_p[0] |= 0x8000;
    }
    
    if (g_abm_palette_bpp!= 16)
    {
        mem16_p[1] |= 0x8000;    /* bit 15 is 1 to indicate it's 24-bit palette. */
    }
    
    mem16_p[2] = normal_color_num;  /* number of normal colors */
    mem16_p[3] = alpha_color_num;   /* number of alpha colors */

    /* bounding box info header (width and height offsets, not bounding box coordinates) */
    mem16_p[4] = (abm_enc->y1 << 8) | abm_enc->x1;
    bottom_right_off_w = w - 1 - abm_enc->x2;
    bottom_right_off_h = h - 1 - abm_enc->y2;
    mem16_p[5] = (bottom_right_off_h << 8) | bottom_right_off_w;

    mem16_p += 6;    

    mem8_p = (U8*)mem16_p;

    /* output color palette */
    for (i = 0; i < color_num - 1; i++)
    {
        c = cit->color_table[i];

        a = A_OF_ARGB8888(c);

        /* prevent blue channel from saturation to get rid of source key checking in the decoder */
        if (g_abm_palette_bpp== 16)
        {   /* 16-bit */
            color16 = ARGB8888_TO_RGB16(c);
            if (B_OF_RGB16(color16) == 0x1F)
            {
                c -= 1 << 3;    /* 5-bit B: 0x1F -> 0x1E */
            }
        }
        else
        {   /* 24-bit and 32-bit ABM both use 24-bit palette */
            if (B_OF_ARGB8888(c) == 0xFF)
            {
                c -= 1;         /* 8-bit B: 0xFF -> 0xFE */
            }
        }

        /* pre-calculate alpha color */
        r = R_OF_ARGB8888(c);
        g = G_OF_ARGB8888(c);
        b = B_OF_ARGB8888(c);

        r = GDI_IMAGE_AB2_DIV_255(r * a);
        g = GDI_IMAGE_AB2_DIV_255(g * a);
        b = GDI_IMAGE_AB2_DIV_255(b * a);

        c = RGB(r, g, b);

        if (g_abm_palette_bpp == 16)
        {   /* 16-bit palette */
            PUT_16(mem8_p, ARGB8888_TO_RGB16(c));
            mem8_p += 2;
        }
        else
        {   /* 24-bit palette */
            PUT_24(mem8_p, c);
            mem8_p += 3;
        }
    }

    /* output 1-byte alpha values of alpha colors */
    for (i = normal_color_num - 1; i < color_num - 1; i++)
    {
        /* inverted alpha due to precalculation */
        *mem8_p++ = 255 - A_OF_ARGB8888(cit->color_table[i]);
    }

    /* add a padding byte to meet 2-byte alignment for the bitstream */
    if ((U32)mem8_p & 1)
    {
        /* padding with 0xFF */
        *mem8_p++ = 0xFF;
        bitstream_padding_byte = 1;
    }
    else
    {
        bitstream_padding_byte = 0;
    }

    img_p = abm_enc->bmp_pixel_start_p;
    bytes_per_pixel = abm_enc->bmp_bpp / 8;

    /* calculate bounding box width and height */
    bound_box_w = abm_enc->x2 - abm_enc->x1 + 1;
    bound_box_h = abm_enc->y2 - abm_enc->y1 + 1;

    /* initialize the bitstream writer */
    BW_INIT((U16*)mem8_p);

    /* 2nd pass, output ABM packed pixels, and do vertical flipping (BMP nature) */
    for (y = abm_enc->y1; y <= abm_enc->y2; y++)
    {
        for (x = abm_enc->x1; x <= abm_enc->x2; x++)
        {
            p = ab2enc_get_img_color_idx(x, y);
            
            /* write the ABM pixel data into the bitstream */
            BW_WRITE(p, bpp);
        }
    }

    /* flush bitstream writer */
    BW_END();

    abm_size = ABM_HEADER_SIZE +                            /* header size */
               (color_num - 1) * g_abm_palette_bpp/ 8 +      /* palette size */
               alpha_color_num +                            /* 8-bit alpha channel */
               bitstream_padding_byte +                     /* a padding byte or not */
               (bound_box_w * bound_box_h * bpp + 15) / 16 * 16 / 8;    /* pixel data size (2-byte align) */

    return abm_size;
}


/*****************************************************************************
 * FUNCTION
 *  caculate_abm_size
 * DESCRIPTION
 *  caculate the image in ABM format size without data encoding.
 * PARAMETERS
 *  width           [IN]    width of image
 *  height          [IN]    height of image
 *  color_cnt       [IN]    bits per pixel of image
 * RETURNS
 *  The result size
  *****************************************************************************/
static U32 caculate_abm_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 bound_width, bound_height;
    U32 normal_color_cnt, alpha_color_cnt;
    U32 color_index_bits;
    
    U32 palette_size;
    U32 stream_size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bound_width         = abm_enc->x2 - abm_enc->x1 + 1;
    bound_height        = abm_enc->y2 - abm_enc->y1 + 1;

    normal_color_cnt    = get_normal_color_num();
    alpha_color_cnt     = cit->color_num - normal_color_cnt;
    
    color_index_bits = log2_ceiling(1 + normal_color_cnt + alpha_color_cnt);
    
    palette_size = 
        (normal_color_cnt + alpha_color_cnt) * g_abm_palette_bpp/ 8 +    /* palette size */
        alpha_color_cnt;                                                /* 8-bit alpha channel */
    palette_size = (palette_size + 1) & ~0x1;                           /* 2-bytes alignment */

    stream_size = ((bound_width * bound_height * color_index_bits + 7) / 8);
    stream_size = (stream_size + 1) & ~0x1;                             /* 2-bytes alignment */
    
    return ABM_HEADER_SIZE + palette_size + stream_size;
}


/*****************************************************************************
 * FUNCTION
 *  caculate_pbm_size
 * DESCRIPTION
 *  caculate the image in PBM format size without data encoding.
 * PARAMETERS
 *  width           [IN]    width of image
 *  height          [IN]    height of image
 *  bpp             [IN]    bits per pixel of image
 * RETURNS
 *  The result size
  *****************************************************************************/
static U32 caculate_pbm_size(U32 width, U32 height, U32 bpp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return PBM_HEADER_SIZE + width * height * bpp / 8;
}


/*****************************************************************************
 * FUNCTION
 *  ABM_load
 * DESCRIPTION
 *  ABM encoder interface
 * PARAMETERS
 *  in_bmp_filename       [IN]  input bitmap filename
 *  dev_bmp_bpp           [IN]  PBM color depth in bits
 *  image_type            [IN]  for decision whether to use ABM
 *  option                [IN]  select file format can be return
 *  data                  [OUT] output memory
 *  size                  [OUT] size of ABM image
 *  width                 [OUT] width of ABM image
 *  height                [OUT] height of ABM image
 * RETURNS
 *  return code to use ABM or not
 *  + ABM_ENC_RETURN_KEEP_ORIGINAL  0   donot use ABM  
 *  + ABM_ENC_RETURN_USE_ABM        1   use ABM
 *  + ABM_ENC_RETURN_USE_AB2        2   use ABMv2
 *****************************************************************************/
S32 ABM_load(
        U8  *in_bmp_filename,
        S32 dev_bmp_bpp,
        U8  image_type,
        abm_enc_option_flag_type option,
        U8  *data,
        S32 *size,
        S32 *width,
        S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 input_bmp_file_size;
    U32 ret = ABM_ENC_RETURN_KEEP_ORIGINAL;
    U32 ret_size = ABM_ENC_MAX_FILE_SIZE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* no file format can be encode, 
       do nothing and return the original format */
    if (option == 0)
    {
        return ABM_ENC_RETURN_KEEP_ORIGINAL;
    }

    /* no support bpps lower than 16-bit,
       do nothing and return the original format */
#if defined(DRV_MAINLCD_BIT_PER_PIXEL) && (DRV_MAINLCD_BIT_PER_PIXEL < 16)
    return ABM_ENC_RETURN_KEEP_ORIGINAL;
#endif

    /* initialize color index table and abm encoder context */
    cit->color_num = 0;
    memset(abm_enc, 0, sizeof(abm_enc_struct));

    abm_enc->is_fully_opaque = 1;

    /* enable source key color only for PBM and BMP */
    if ((image_type == IMAGE_TYPE_DEVICE_BITMAP) || (image_type == IMAGE_TYPE_BMP))
    {
       abm_enc->src_key_color_enable = 1;
    }

    /* It is necessary to identify PNG to BMP or originally BMP for 32-bit BMP files. */
    if (image_type != IMAGE_TYPE_PNG)
    {
       abm_enc->is_windows_bmp = 1;
    }


    /* load input bitmap file */
    input_bmp_file_size = load_bmp_file(g_file_buf, in_bmp_filename);
    if (input_bmp_file_size == 0)
    {
        return ABM_ENC_RETURN_KEEP_ORIGINAL;
    }

    #if defined(__RESOURCE_GEN_) && defined(__COSMOS_MMI__)
    if (g_is9slice)
    {
        option &= ~ABM_ENC_OPTION_FLAG_AB2;
        option |= ABM_ENC_OPTION_FLAG_24BIT;
        g_abm_palette_bpp = 24;

    }
    #endif

    /* Prepare image data and color table */
    abmenc_build_color_index_table();
    *width  = abm_enc->bmp_width;
    *height = abm_enc->bmp_height;


    do
    {

    #if defined(__COSMOS_MMI__)
    if (option & ABM_ENC_OPTION_FLAG_24BIT)
    {  
        ret_size = abmenc_encode(data);
        ret = ABM_ENC_RETURN_USE_ABM; 
        break;
    }  
    #endif
    
//#if (MAIN_MEDIA_LAYER_BITS_PER_PIXEL != 24)
    /* check if AB2 size is smaller */
    if (option & ABM_ENC_OPTION_FLAG_AB2)
    {
        U32 ab2_size = ab2enc_encode(data);
        if (ab2_size < ret_size)
        {
            ret_size = ab2_size;
            ret = ABM_ENC_RETURN_USE_AB2; 
        }
    }
//#endif
    
    /* check if ABM size is smaller */
    if (option & ABM_ENC_OPTION_FLAG_ABM)
    {
        U32 abm_size = caculate_abm_size();
        if (abm_size < ret_size)
        {
            ret_size = abmenc_encode(data);
            ret = ABM_ENC_RETURN_USE_ABM; 
        }
    }

    /* check if original size is smaller */
    if (option & ABM_ENC_OPTION_FLAG_ORIGINAL)
    {
        switch (image_type)
        {
            case IMAGE_TYPE_PNG:
            {
                /* no information, do nothing */ 
                break;
            }

            case IMAGE_TYPE_BMP:
            {
                if (input_bmp_file_size < ret_size)
                {
                    ret_size = input_bmp_file_size;
                    ret = ABM_ENC_RETURN_KEEP_ORIGINAL; 
                }        
                break;
            }
                
            case IMAGE_TYPE_DEVICE_BITMAP:
            {
                U32 pbm_size = caculate_pbm_size(*width, *height, dev_bmp_bpp);
                if (pbm_size < ret_size)
                {
                    ret_size = pbm_size;
                    ret = ABM_ENC_RETURN_KEEP_ORIGINAL; 
                }
                break;           
            }
                
            default:
                /* not supported, do nothing */
                break;
        }
    } /* if (option & ABM_ENC_OPTION_FLAG_ORIGINAL) */

    }while(0);

    #if defined(__RESOURCE_GEN_) && defined(__COSMOS_MMI__)

    if (g_is9slice)
    {
        g_abm_palette_bpp = ABM_PALETTE_BPP;

    }
    #endif

    /* Error handling */
    if (ret_size == ABM_ENC_MAX_FILE_SIZE)
    {
        *width = 0;
        *height = 0;
        *size = 0;
        return ABM_ENC_RETURN_KEEP_ORIGINAL;
    }

    *size = (S32)ret_size;

    return ret;
}


/* 
 * RESOURCE GENERATOR ONLY FUNCTIONS
 */
#if defined(__RESOURCE_GEN_)

#ifdef ABM_ENC_UNIT_TEST
#include <time.h>
/* 
 * unit test for abm encoder
 *
 * return 0: successful, otherwise: failed
 */
S32 abmenc_unit_test(void)
{
    S32 si, i;

    cit->color_num = 0;
    srand((unsigned)time(NULL));

    si = search_color(ARGB(255, 255, 255, 255));
    add_color_if_new(ARGB(255, 255, 255, 255));
    si = search_color(ARGB(255, 255, 255, 255));
    add_color_if_new(ARGB(255, 255, 255, 254));
    si = search_color(ARGB(255, 255, 255, 0));
    add_color_if_new(ARGB(0, 255, 255, 254));
    si = search_color(ARGB(255, 255, 255, 254));

    for (i = 0; i < 1000; i++)
    {
        add_color_if_new(rand());
    }

    /* make sure the color table is descending */        
    for (i = 0; i < cit->color_num - 1; i++)
    {        
        if (cit->color_table[i + 1] > cit->color_table[i])
        {
            return ABMENC_UNIT_TEST_FAILED;
        }
    }

    return ABMENC_UNIT_TEST_SUCCESSFUL;
}
#endif /* ABM_ENC_UNIT_TEST */

#if defined(__MMI_RESOURCE_IMAGE_COMPRESS__)
extern U8* mmi_rg_compress_image(U8 *buffer, S32 org_size, S32 *dest_size, S32 image_type, U32 width_height,  U8* symbol, int n_frames);
extern U8* mmi_rg_output_compressed_image(U8 *dest_buf, S32 dest_size,  FILE *outfile);
#endif /* __MMI_RESOURCE_IMAGE_COMPRESS__ */

static U8 abm_buffer[ABMENC_BMP_FILE_BUFFER_SIZE];
/*****************************************************************************
 * FUNCTION
 *  ABMLoader
 * DESCRIPTION
 *  ABM loader
 * PARAMETERS
 *  in_filename     [IN] input filename
 *  out_filename    [IN] output filename
 *  encode_option   [IN] encode options
 * RETURNS
 *  return value
 *****************************************************************************/
S32 ABMLoader(U8 *in_filename, U8 *out_filename, S32 encode_option)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *buffer = NULL/*[ABMENC_BMP_FILE_BUFFER_SIZE]*/;
    S32 width, height, size, ret, i;
    U32 width_height;
    FILE *outfile;
    U8 image_type = 0;
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    U32 enfb_width, enfb_height;
    S32 enfb_ret;
#endif
    S32 data_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reduce call stack size and avoid the risk of ABMENC_BMP_FILE_BUFFER_SIZE increase */
    buffer = abm_buffer;
    memset(buffer, 0, ABMENC_BMP_FILE_BUFFER_SIZE);

    /* temp solution:
     * check whether the input file is PBM */
    {
        int l;
        
        l = strlen(in_filename);
        if ((in_filename[l - 1] == 'M') &&
            (in_filename[l - 2] == 'B') &&
            (in_filename[l - 3] == 'P'))
        { 
            image_type = IMAGE_TYPE_DEVICE_BITMAP;
        }
        else if ((in_filename[l - 1] == 'P') &&
                 (in_filename[l - 2] == 'M') &&
                 (in_filename[l - 3] == 'B'))
        {
            image_type = IMAGE_TYPE_BMP;
        }
        else if ((in_filename[l - 1] == 'A') &&
                 (in_filename[l - 2] == 'P') &&
                 (in_filename[l - 3] == 'M') &&
                 (in_filename[l - 4] == 'B'))
        {
            image_type = IMAGE_TYPE_PNG;
        }
    }

    /* 
     * After we tested on the porject with hardware PNG, the PNG is larger
     * and slower than ABM/ABMv2. So we disable this checking.
     */
#if 0
#ifdef GDI_USING_HW_PNG
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* GDI_USING_HW_PNG */
#endif

    ret = ABM_load(
            in_filename,
            __MMI_DEVICE_BMP_FORMAT__,
            image_type,
            encode_option,
            buffer,
            &size,
            &width,
            &height);
    switch(ret)
    {
        case ABM_ENC_RETURN_USE_ABM:
            image_type = IMAGE_TYPE_ABM;
            break;

        case ABM_ENC_RETURN_USE_AB2:
            image_type = IMAGE_TYPE_AB2;
            break;

        default:
            return ret;
    }

    if ((size >> 24) > 0)
    {
        printf("image is too big:%s\n", in_filename);
    }
    g_ressize = size + 8;
    width_height = (((U32)width & 0XFFF) << 12) | ((U32)height & 0XFFF);

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    enfb_ret = Image_Test(in_filename, &enfb_width, &enfb_height);
    if (enfb_ret != ENFB_IMAGE_NONE)
    {
        enfbFlag = 1;
        if (enfb_ret == ENFB_IMAGE_ASSOCIATE)
        {
            ENFBAssociatedIDAdded = MMI_TRUE;
        }
    }
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    if (toolFlag != 1)
    {
        /* open output file */
        outfile = fopen(out_filename, "wb+");
        if (outfile == NULL)
        {
            printf("\nError creating %s", out_filename);
            return 0;
        }
    }

    data_size = size;
    if (g_is9slice)
    {
        data_size += 20;
    }

    /* write to CustPack */
    if (toolFlag == 1)
    {
        /* resource header */
        if (g_is9slice)
            fprintf(dest_file, "%c", IMAGE_TYPE_9SLICE);
        else
            fprintf(dest_file, "%c", image_type);
        fprintf(dest_file, "%c", 0x01);
        fprintf(dest_file, "%c%c%c",
                (data_size & 0x000000ff),
                (data_size & 0x0000ff00) >> 8,
                (data_size & 0x00ff0000) >> 16);
        fprintf(dest_file, "%c%c%c",
                (width_height & 0x000000ff),
                (width_height & 0x0000ff00) >> 8,
                (width_height & 0x00ff0000) >> 16);

        if (g_is9slice)
        {
            /* Write 9slice file header */
            mmi_rg_write_9slice_header(image_type, dest_file, MMI_TRUE);
        }
        
        /* ABM raw data */
        for (i = 0; i < size; i++)
        {
            fprintf(dest_file, "%c", buffer[i]);
        }
    }
    
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    /* write ENFB header to CustImgDataxxx.h and
     * image header/data to ENFB image data file */
    else if (enfbFlag == 1) 
    {
        enfb_size = 8 + data_size;
        
        /* write ENFB header to CustImgDataxxx.h */
        fprintf(outfile,
                "\n{\t0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X\t};\n",
                (U8) 255,                       //type
                (U8) ENFBAssociatedIDAdded,     //associated id
                (U8) 0,                         //reserved
                (U8) 0,                         //reserved
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
        if (g_is9slice)
            fprintf(enfb_img_data_file, "%c", IMAGE_TYPE_9SLICE);
        else
            fprintf(enfb_img_data_file, "%c", image_type);
        fprintf(enfb_img_data_file, "%c", 0x01);
        fprintf(enfb_img_data_file,
                "%c%c%c",
                (data_size & 0x000000ff),
                (data_size & 0x0000ff00) >> 8,
                (data_size & 0x00ff0000) >> 16);
        fprintf(enfb_img_data_file,
                "%c%c%c",
                (width_height & 0x000000ff),
                (width_height & 0x0000ff00) >> 8,
                (width_height & 0x00ff0000) >> 16);

        if (g_is9slice)
        {
            /* Write 9slice file header */
            mmi_rg_write_9slice_header(image_type, enfb_img_data_file, MMI_TRUE);
        }
        
        for (i = 0; i < size; i++)
        {
            fprintf(enfb_img_data_file, "%c", buffer[i]);
        }

        enfb_offset += enfb_size;
        enfbFlag = 0;
    }
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

    else
    {
        U8 *dest_buf;
        S32 dest_size = 0;
        
        fprintf(outfile, "{\n\t");

#if defined(__MMI_RESOURCE_IMAGE_COMPRESS__)
        dest_buf = mmi_rg_compress_image(buffer, size, &dest_size, image_type, width_height, in_filename, 1);
        if (dest_buf != NULL)
        {
            mmi_rg_output_compressed_image(dest_buf, dest_size, outfile);
        }
        else
#endif /* __MMI_RESOURCE_IMAGE_COMPRESS__ */
        {
            /* resource header */
            if (g_is9slice)
                fprintf(outfile, "0x%02X, ", IMAGE_TYPE_9SLICE);
            else
                fprintf(outfile, "0x%02X, ", image_type);
            fprintf(outfile, "0x%02X, ", 0x01);
            fprintf(outfile,
                    "0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X, 0x%02X,",
                    (data_size & 0x000000ff),
                    (data_size & 0x0000ff00) >> 8,
                    (data_size & 0x00ff0000) >> 16,
                    (width_height & 0x000000ff),
                    (width_height & 0x0000ff00) >> 8,
                    (width_height & 0x00ff0000) >> 16);

            if (g_is9slice)
            {
                /* Write 9slice file header */
                mmi_rg_write_9slice_header(image_type, outfile, MMI_FALSE);
            }

            for (i = 0; i < size; i++)
            {
                if ((i % 16) == 0)
                {
                    fprintf(outfile, "\n\t");
                }
                fprintf(outfile, "0x%02X, ", buffer[i]);
            }
        }

        fprintf(outfile, "\n};");
    }

    if (toolFlag != 1)
    {
        fclose(outfile);
    }

    // TODO: Fix the return code
    return ABM_ENC_RETURN_USE_ABM;
}

#endif /* defined(__RESOURCE_GEN_) */

#else /* !defined(__MTK_TARGET__) || defined(__RESOURCE_GEN_) */

/* avoid the target compilation warning */
char g_abm_loader_avoid_warning;

#endif /* !defined(__MTK_TARGET__) || defined(__RESOURCE_GEN_) */

