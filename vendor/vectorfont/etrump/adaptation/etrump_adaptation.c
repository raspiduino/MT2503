/*****************************************************************************
 *
 * Filename:
 * ---------
 *  etrump_adaption.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  adaption layer for etrump engine
 *
 * Author:
 * -------
 *  
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 ****************************************************************************/

#if defined(FONT_ENGINE_ETRUMP)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_CACHE_H
//#include FT_INTERNAL_OBJECTS_H // need detail structure for hacking the memory allocate
#include FT_BITMAP_H

#include "mmi_include.h"
#include "font_engine_interface.h"
#include "gd_include.h"
#include "setjmp.h"
#ifdef WIN32
#include "kal_adm.h"
#endif
#include "gdi_image_alpha_bmp.h"

    #include "MMIDataType.h"
    #include "gdi_datatype.h"
    #include "kal_general_types.h"
    #include "kal_public_defs.h"
    #include "kal_public_api.h"
    #include "DebugInitDef_Int.h"
    #include "string.h"
    #include "stdio.h"
    #include "wchar.h"
    #include "gdi_include.h"
    #include "MMI_fw_trc.h"
    #include "kal_trace.h"
    #include "mmi_fw_trc.h"
    #include "gui_data_types.h"

#include "gdi_font.h"

#include "vector_font_resource_def.h"

#include "fs_gprot.h"

#include "et_common/et_common.h"
#include "textlayout/textlayout.h"

#include "CustFontDataHW.h"

#ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
#include "third_rom.h"
#include "ResThirdROMUtil.h"
#endif

#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
    #define POOL_SIZE 512*1024
#elif defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_FONT_THIRD_ROM_SUPPORT__) 
    #define POOL_SIZE 340*1024
#else
    #define POOL_SIZE (32 + POP_FONT_FILES*8 + 8)*1024
#endif
static unsigned char mem_pool[POOL_SIZE];


#if MMI_FE_EXT_RESOURCE_NUM > 0
fs_file_tbl_struct gFS_FileTable_VFont[MMI_FE_EXT_RESOURCE_NUM];
#endif

/*****************************************************************************
 * Define
 *****************************************************************************/
#define K(X)    ((X)*1024)
#define FREETYPE_FILE_NAME_LENGTH 64
#define TEST_FORMAT_CHAR(ch)  ((ch) >= 0x200C && (ch) <= 0x200F)
#define  FREETYPE_TEXT_LENGTH FE_MAX_CLUSTER_LEN*2


#if defined(__MMI_LANG_THAI__) \
 || defined(__MMI_INDIC_ALG__) \
 || defined(__MMI_LANG_MYANMAR__) \
 || defined(__MMI_LANG_LAO__)
#define OPENTYPE_SUPPORT
#endif
/*****************************************************************************
 * Typedef
 *****************************************************************************/
typedef struct
{
    U16 res_id;
    S32 face_index;
    S32 cmap_index;
    U32 scale_ratio;
    FT_Face face;
    FT_StreamRec stream;
#ifdef OPENTYPE_SUPPORT
    FT_Layout layout;
#endif //OPENTYPE_SUPPORT
    U8 font_name[FREETYPE_FILE_NAME_LENGTH];
} etrump_font_info, *etrump_font_info_p;

#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_FONT_THIRD_ROM_SUPPORT__) 
#define FONT_SIZE_MIN 9
#define FONT_SIZE_MAX 64

typedef struct
{
    S32 ascent;
    S32 descent;
} etrump_char_info;

static etrump_char_info et_char_info[15][FONT_SIZE_MAX-FONT_SIZE_MIN+1];

#define UNICODE_REGION_MAX  8
#define UNICODE_FONT_NUM    16

typedef struct
{
    U32  region_count;
    U16  start[UNICODE_REGION_MAX];
    U16  end[UNICODE_REGION_MAX];
    U16  resid;
} font_unicode_region;

static font_unicode_region unicode_region[UNICODE_FONT_NUM];
#endif
/*****************************************************************************
 * External functions
 *****************************************************************************/
extern U8 *GetFontResource(U16 ResId, S32 *size);
extern void gdi_draw_font_by_abm(
                S32 x, 
                S32 y, 
                gdi_color color, 
                U8 *font_data, 
                S32 char_width, 
                S32 char_height);
extern void gdi_font_prepare_4bits_font_palette(void *header,int header_size, gdi_color color);
extern unsigned long mmi_fe_font_file_reader(void* handle, unsigned long offset, unsigned char* buffer, unsigned long count);
extern void mmi_fe_font_file_closer(void* handle);
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__)
extern void* mmi_fe_get_font_stream_handle(U16 resid);
#endif
#ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
extern U8 *mmi_fe_get_font_resource(U16 ResId, mmi_fe_font_resource_type_enum *type, S32 *offset, S32 *size);
#else
extern U8 *mmi_fe_get_font_resource(U16 ResId, mmi_fe_font_resource_type_enum *type, S32 *size);
#endif
extern S32 mmi_fe_get_system_font_number(void);

/*****************************************************************************
 * Global variables
 *****************************************************************************/

/* error handling */
//static MMI_BOOL render_flag = MMI_FALSE;

/* font attribute */
static U32 etrump_font_attr;
static gdi_color etrump_text_color;
static gdi_color etrump_border_color;
/* font size */
static int etrump_size;
static U32 etrump_scale_ratio;

/* engine global context */
static FT_Library etrump_library; 
static FT_Face etrump_face; 
static etrump_font_info etrump_font_list[FE_MAX_FONT_FILE_NUMBER*FE_MAX_FONT_FAMILY_NUMBER];

/* header for amb */
static U32 etrump_4bits_text_color_header[((6+16)*2+16)/4];
static U32 etrump_4bits_border_color_header[((6+16)*2+16)/4];

static U8 etrump_bits_revise_table[256];

static MMI_BOOL is_color_init = MMI_FALSE;
static MMI_BOOL is_border_color_init = MMI_FALSE;

typedef struct
{
    U16 normal_data_size;
    U16 border_data_size;
    U8  data[1];
} etrump_render_data_struct;


#define MAX_BITMAP_SIZE (128*128/2)
static U32 etrump_render_data_pool[((sizeof(etrump_render_data_struct)+MAX_BITMAP_SIZE* 2)+3)/4];

/* font family */
U16 etrump_font_res_list[FE_MAX_FONT_FILE_NUMBER*FE_MAX_FONT_FAMILY_NUMBER];
U8  etrump_font_number = 0;
U8  etrump_curr_font = 0;
U8  hp_customer_font = 0;  // highest priority customer font

static U8 sys_font_on_memory_card  = 0; 
/*****************************************************************************
 * Local functions
 *****************************************************************************/
static MMI_BOOL etrump_init(U16* font_list, U8 font_number);
static void etrump_reset_face_glyphs();
static void etrump_set_font_attr(U32 attr);
static void etrump_set_font_size(U32 size, U32 attr);
static void etrump_set_font_color(gdi_color foreground_rgb,gdi_color border_rgb);
#if defined(__MMI_VECTOR_FONT_KERNING__)
static MMI_BOOL etrump_get_font_data(
        U8 is_need_glyph_data,
        U16 ucs2, 
        U8** glyph_data,
        U32 *glyph_size,
        U32 *glyph_attr, 
        U16 *glyph_width,
        U16 *glyph_height,
        S32 *bearing_x,
        S32 *bearing_y, 
        S32 *advance_x,
        S32 *advance_y, 
        S32 *lsb_delta,
        S32 *rsb_delta,
        MMI_BOOL* valid);
#else
static MMI_BOOL etrump_get_font_data(
        U8 is_need_glyph_data,
        U16 ucs2, 
        U8** glyph_data,
        U32 *glyph_size,
        U32 *glyph_attr, 
        U16 *glyph_width,
        U16 *glyph_height,
        S32 *bearing_x,
        S32 *bearing_y, 
        S32 *advance_x,
        S32 *advance_y, 
        MMI_BOOL* valid);
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
static void etrump_show_font_data(
        U16 ucs2, 
        S32 x,
        S32 y,
        U8* glyph_ptr,
        U32 glyph_size,
        U32 glyph_attr,
        U16 glyph_width,
        U16 glyph_height,
        U32 bordered);
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_FONT_THIRD_ROM_SUPPORT__) 
static MMI_BOOL etrump_get_font_info(U16 resid, U32 font_size,S32 *height,S32 *ascent, S32 *descent, MMI_BOOL with_attr);
#else
static MMI_BOOL etrump_get_font_info(U32 font_size,S32 *height,S32 *ascent, S32 *descent, MMI_BOOL with_attr);
#endif
static void etrump_set_antialias(MMI_BOOL value);
static MMI_BOOL etrump_set_font(U16 fontres);
//static void etrump_restart(void);
#if defined(__MMI_VECTOR_FONT_KERNING__)
static MMI_BOOL etrump_get_font_kerning (U16 left_ucs2, U16 right_ucs2, signed long *x, signed long *y);
static MMI_BOOL etrump_has_kerning (void);
#endif



FILE *etrump_dummy_file_open(const char*filename, const char *mode) 
{
    MMI_ASSERT(0);
    return NULL;
}
int etrump_dummy_file_close(FILE *a) 
{
    MMI_ASSERT(0);
    return 0;
}
int etrump_dummy_file_seek(FILE *stream,long int offset,int origin) 
{
    MMI_ASSERT(0);
    return 0;
}
int etrump_dummy_file_tell(FILE *stream) 
{
    MMI_ASSERT(0);
    return 0;
}
int etrump_dummy_file_read(void *ptr,size_t size,size_t count,FILE *stream)
{
    MMI_ASSERT(0);
    return 0;
}
int etrump_dummy_file_error(FILE *stream)
{
    MMI_ASSERT(0);
    return 0;
}


static MMI_BOOL is_system_font_resid(U16 resid)
{
#ifndef __MMI_FONT_THIRD_ROM_SUPPORT__
    if (resid >= IMG_GLOBAL_FONT_1 && resid <= IMG_GLOBAL_FONT_MAX)
        return MMI_TRUE;
    else
#endif
        return MMI_FALSE;
}

#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_FONT_THIRD_ROM_SUPPORT__) 
static void etrump_set_font_info(FT_Face face, U16 resid)
{
    S32 i;
    FT_Size size;
    U16 tmp_resid = resid;

    if (resid > IMG_GLOBAL_FONT_MAX)
        tmp_resid = resid - IMG_GLOBAL_FONT_MAX + POP_FONT_FILES;
    else if (resid >= IMG_GLOBAL_FONT_1)
        tmp_resid = resid - IMG_GLOBAL_FONT_1;
    else
        tmp_resid = resid + POP_FONT_FILES + sys_font_on_memory_card;

    for (i = 0; i <= FONT_SIZE_MAX-FONT_SIZE_MIN; i++)
    {
        U32 font_size = FONT_SIZE_MIN+i;

        if (etrump_scale_ratio)
            font_size = font_size * etrump_scale_ratio / 64;

        FT_Set_Pixel_Sizes(face, font_size, 0);

        size = face->size;
        et_char_info[tmp_resid][i].ascent = (size->metrics.ascender)>>6;
        et_char_info[tmp_resid][i].descent = (-(size->metrics.descender)) >>6;
    }
}

static MMI_BOOL etrump_get_unicode_region(FT_Face face, U16 resid, U8 index)
{
    S32 error = 0;

    if (!face || !face->stream)
        return MMI_FALSE;

    error = FT_Face_Get_Unicode_Region(face, (FT_UniRegion *)&unicode_region[index]);
    if (error)
    {
        return MMI_FALSE;
    }
    else
    {
        unicode_region[index].resid = resid;
        return MMI_TRUE;
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  etrump_set_font_attr
 * DESCRIPTION
 *  To set font attribute
 * PARAMETERS
 *  U32   [IN]  the desired attirbute
 * RETURNS
 *  void
 *****************************************************************************/
static void etrump_set_font_attr(U32 attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    etrump_font_attr = attr;
}


/*****************************************************************************
 * FUNCTION
 *  etrump_set_antialias
 * DESCRIPTION
 *  To turn on or turn off antialias
 * PARAMETERS
 *  MMI_BOOL   [IN]  the desired value
 * RETURNS
 *  void
 *****************************************************************************/
static void etrump_set_antialias(MMI_BOOL value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (value)
        etrump_font_attr |= FE_FONT_ATTR_ANTIALIAS;
    if (!value)
        etrump_font_attr &= (~FE_FONT_ATTR_ANTIALIAS);
    
}


/*****************************************************************************
 * FUNCTION
 *  etrump_set_font_size
 * DESCRIPTION
 *  To set font size & attr
 * PARAMETERS
 *  U32   [IN]  the desired size
 *  U32   [IN]  the desired attribute
 * RETURNS
 *  void
 *****************************************************************************/
static void etrump_set_font_size(U32 size, U32 attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (etrump_size != size) 
    {
        etrump_size = size;

        if (etrump_scale_ratio)
            size = size * etrump_scale_ratio / 64;

        FT_Set_Pixel_Sizes(etrump_face, size, 0);
    }
    etrump_font_attr = attr;
}


/*****************************************************************************
 * FUNCTION
 *  etrump_set_font_color
 * DESCRIPTION
 *  To set font color
 * PARAMETERS
 *  gdi_color   [IN]  the font color
 *  gdi_color   [IN]  the background color 
 * RETURNS
 *  void
 *****************************************************************************/
static void etrump_set_font_color(gdi_color foreground_rgb,gdi_color border_rgb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(etrump_text_color != foreground_rgb || !is_color_init)
    {
        gdi_font_prepare_4bits_font_palette(etrump_4bits_text_color_header,
                                            sizeof(etrump_4bits_text_color_header),
                                            etrump_text_color = foreground_rgb);
        is_color_init = MMI_TRUE;
    }
    if(etrump_border_color != border_rgb || !is_border_color_init)
    {
        gdi_font_prepare_4bits_font_palette(etrump_4bits_border_color_header,
                                            sizeof(etrump_4bits_border_color_header),
                                            etrump_border_color = border_rgb);
        is_border_color_init = MMI_TRUE;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  etrump_get_font_info
 * DESCRIPTION
 *  To get font information regardless of the exact ucs2 character
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_FONT_THIRD_ROM_SUPPORT__) 
static MMI_BOOL etrump_get_font_info(U16 resid, U32 font_size,S32 *height,S32 *ascent, S32 *descent, MMI_BOOL with_attr)
{
    U16 tmp_resid = resid;

    if (tmp_resid == 0xff)
        tmp_resid = etrump_curr_font;
    else if (tmp_resid >= IMG_GLOBAL_FONT_MAX)
        tmp_resid = tmp_resid - IMG_GLOBAL_FONT_MAX + POP_FONT_FILES;
    else if (resid >= IMG_GLOBAL_FONT_1)
        tmp_resid = resid - IMG_GLOBAL_FONT_1;
    else
        tmp_resid = resid + POP_FONT_FILES + sys_font_on_memory_card;

    if (font_size < FONT_SIZE_MIN)
        font_size = FONT_SIZE_MIN;
    else if (font_size > FONT_SIZE_MAX)
        font_size = FONT_SIZE_MAX;

    *ascent = et_char_info[tmp_resid][font_size - FONT_SIZE_MIN].ascent;
    *descent = et_char_info[tmp_resid][font_size - FONT_SIZE_MIN].descent;

    if (with_attr) 
    {
        if (etrump_font_attr & FE_FONT_ATTR_BORDER)
        {
            *ascent  += 1;
            *descent += 1;
        }
    }

    *height = *ascent + *descent;

    return MMI_TRUE;
}
#else
static MMI_BOOL etrump_get_font_info(U32 font_size,S32 *height,S32 *ascent, S32 *descent, MMI_BOOL with_attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FT_Size size;
    U32 save_size = etrump_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (save_size != font_size)
        etrump_set_font_size(font_size, etrump_font_attr);
    
    size = etrump_face->size;
    *ascent = (size->metrics.ascender)>>6;
    *descent = (-(size->metrics.descender)) >>6;

    if (with_attr) 
    {
        if (etrump_font_attr & FE_FONT_ATTR_BORDER)
        {
            *ascent  += 1;
            *descent += 1;
        }
    }

    *height = *ascent + *descent;
    
    if(save_size != font_size)
        etrump_set_font_size(save_size, etrump_font_attr);

    return MMI_TRUE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  etrump_data_convert
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
S32 etrump_data_convert(U8* dest, U8* src, S32 pitch, S32 width, S32 height, S32 size, MMI_BOOL antialias)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 glyph_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (antialias)
    {
        int i;
        for(i = 0; i<size;i+=2)
        {
            *dest++ = (src[1]&0xf0) | (src[0] >> 4);
            src+=2;
        }
        glyph_size = (size +1)>>1;
    }
    else
    {
        int i,j;
        int skip_padding = ((pitch<<3) - width)>>3;
        int shift = 0;
        int base_shift = (8-width) & 0x7;

        glyph_size = (width*height+7)>>3;

        memset(dest,0,glyph_size);
        for(i=0;i<height;i++)
        {
            for(j=0;j<width;j+=8)
            {
                U32 s = (U32)(*src++);
                if(s)
                {
                    if(shift)
                    {
                        s <<= shift;
                        *dest++ |= etrump_bits_revise_table[s>>8];
                        *dest   |= etrump_bits_revise_table[s&0xff];
                    }
                    else
                        *dest++ |= etrump_bits_revise_table[s];
                }
                else
                    dest++;
            }
            if(base_shift && !shift) dest--;
            if((shift+=base_shift) >8) dest--;
            shift&=0x7;
            src+=skip_padding;
        }
    }
    return glyph_size;
}


/*****************************************************************************
 * FUNCTION
 *  etrump_map_char
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
#if defined(__MMI_VECTOR_FONT_KERNING__)
U16 etrump_map_char(U16 ucs2)
#else
static U16 etrump_map_char(U16 ucs2)
#endif /* __MMI_VECTOR_FONT_KERNING__ */
{
    U16 glyph_index;

    glyph_index = FT_Get_Char_Index(etrump_face, ucs2);
    return glyph_index;
}


/*****************************************************************************
 * FUNCTION
 *  etrump_get_font_data
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
#if defined(__MMI_VECTOR_FONT_KERNING__)
static MMI_BOOL etrump_get_font_data(
        U8 is_need_glyph_data,
        U16 ucs2, 
        U8** glyph_data,
        U32 *glyph_size,
        U32 *glyph_attr, 
        U16 *glyph_width,
        U16 *glyph_height,
        S32 *bearing_x,
        S32 *bearing_y, 
        S32 *advance_x,
        S32 *advance_y, 
        S32 *lsb_delta,
        S32 *rsb_delta,
        MMI_BOOL* valid)
#else
static MMI_BOOL etrump_get_font_data(
        U8 is_need_glyph_data,
        U16 ucs2, 
        U8** glyph_data,
        U32 *glyph_size,
        U32 *glyph_attr, 
        U16 *glyph_width,
        U16 *glyph_height,
        S32 *bearing_x,
        S32 *bearing_y, 
        S32 *advance_x,
        S32 *advance_y, 
        MMI_BOOL* valid)
#endif /* __MMI_VECTOR_FONT_KERNING__ */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FT_Error    error = 0;
    U8*         bitmap_buffer = NULL;
    //S32 loop = 0;
    S32 pitch = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    etrump_reset_face_glyphs();

    //render_flag = MMI_TRUE;
    *valid = MMI_TRUE;

    if ((is_need_glyph_data != 2) && (etrump_font_attr & (FE_FONT_ATTR_ITALIC|FE_FONT_ATTR_OBLIQUE))) 
    {
        FT_Matrix matrix;
        matrix.xx = (FT_Fixed)(   1 * 0x10000L);
        matrix.xy = (FT_Fixed)(0.25 * 0x10000L);
        matrix.yx = (FT_Fixed)(   0 * 0x10000L);
        matrix.yy = (FT_Fixed)(   1 * 0x10000L);

        FT_Set_Transform(etrump_face, &matrix, NULL);
    }
    
    {
        switch (is_need_glyph_data)
        {
            case 0:
                error = FT_Load_Char(etrump_face, ucs2, FT_LOAD_DEFAULT | ((etrump_font_attr & FE_FONT_ATTR_ANTIALIAS)? 0: FT_LOAD_TARGET_MONO));
                break;
            case 1:
                error = FT_Load_Char(etrump_face, ucs2, FT_LOAD_RENDER | ((etrump_font_attr & FE_FONT_ATTR_ANTIALIAS)? 0: FT_LOAD_TARGET_MONO));
                break;
            case 2:
                if (etrump_map_char(ucs2))
                {
                    *valid = MMI_TRUE;
                }
                else
                {
                    *valid = MMI_FALSE;
                }
                //render_flag = MMI_FALSE;
                return MMI_TRUE;
                        //break;
            case 3:
                error = FT_Load_Glyph(etrump_face, ucs2, FT_LOAD_RENDER | ((etrump_font_attr & FE_FONT_ATTR_ANTIALIAS)? 0: FT_LOAD_TARGET_MONO));
                break;
        }

        if (error)
        {
            *glyph_width  = 0;
            *glyph_height = 0;
            *bearing_x = 0;
            *bearing_y = 0;
            *advance_x = 0;
            *advance_y = 0;
#if defined(__MMI_VECTOR_FONT_KERNING__)
            *lsb_delta = 0;
            *rsb_delta = 0;
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
            *glyph_size = 0;
            //render_flag = MMI_FALSE;
            if (glyph_attr) 
                *glyph_attr = FE_GLYPH_ATTR_USING_FONT_ENGINE;
            return MMI_TRUE;
        }
                
        if (etrump_font_attr & (FE_FONT_ATTR_BOLD))
        {
            error = FT_Bitmap_Embolden(etrump_library, &(etrump_face->glyph->bitmap), (FT_Pos)0x40, 0);
        }

        if(is_need_glyph_data)
        {
            *glyph_width  = (U16)etrump_face->glyph->bitmap.width;
            *glyph_height = (U16)etrump_face->glyph->bitmap.rows;
            bitmap_buffer = etrump_face->glyph->bitmap.buffer;
            pitch = etrump_face->glyph->bitmap.pitch;
        }
        else
        {
            *glyph_width  = (U16)etrump_face->glyph->metrics.width >>6;
            *glyph_height = (U16)etrump_face->glyph->metrics.height>>6;
            bitmap_buffer = NULL;
        }
        *bearing_x = etrump_face->glyph->metrics.horiBearingX>>6;
        *bearing_y = etrump_face->glyph->metrics.horiBearingY>>6;
        *advance_x = etrump_face->glyph->advance.x >> 6;
        *advance_y = etrump_face->glyph->advance.y >> 6;
#if defined(__MMI_VECTOR_FONT_KERNING__)
        *lsb_delta = etrump_face->glyph->lsb_delta;
        *rsb_delta = etrump_face->glyph->rsb_delta;
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
    }

    if (is_need_glyph_data)
    {
        int size;
        etrump_render_data_struct *D = (etrump_render_data_struct*) etrump_render_data_pool;

        size = (*glyph_width) * (*glyph_height); 

        // convert 8 bits into 4 bits
        D->normal_data_size = etrump_data_convert(&(D->data[0]), bitmap_buffer, pitch,(*glyph_width), (*glyph_height), size, (MMI_BOOL) (etrump_font_attr & FE_FONT_ATTR_ANTIALIAS));
        D->normal_data_size = (D->normal_data_size+3) & (~3);
                
        *glyph_data = (U8*)D;
        (*glyph_size) = (U32)&(D->data[D->normal_data_size]) - (U32)D;    
    }

    if (etrump_font_attr & (FE_FONT_ATTR_ITALIC|FE_FONT_ATTR_OBLIQUE))
        FT_Set_Transform(etrump_face, NULL, NULL);

    if (glyph_attr) 
        *glyph_attr = FE_GLYPH_ATTR_USING_FONT_ENGINE;
    
    //render_flag = MMI_FALSE;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  etrump_show_font_data
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void etrump_show_font_data(
                            U16 ucs2, 
                            S32 x,
                            S32 y,
                            U8* glyph_ptr,
                            U32 glyph_size,
                            U32 glyph_attr,
                            U16 glyph_width,
                            U16 glyph_height,
                            U32 bordered)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_gray_bitmap;

    etrump_render_data_struct *D = (etrump_render_data_struct*)glyph_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (glyph_ptr == NULL || glyph_size == 0 || glyph_width ==0 || glyph_height == 0) return;

    if (etrump_font_attr & FE_FONT_ATTR_ANTIALIAS)
        is_gray_bitmap = MMI_TRUE;
    else
        is_gray_bitmap = MMI_FALSE;
    
    if (etrump_font_attr & FE_FONT_ATTR_BORDER)
    {    
        {
            gdi_color temp_text_color = 0, temp_border_color = 0;

            if (bordered == 1 || bordered == 3)
            {
                temp_text_color = /*0xFF000000 | */etrump_text_color;
            }
            if (bordered == 1 || bordered == 2)
            {
                temp_border_color = /*0xFF000000 | */etrump_border_color;
            }

            gdi_show_char_bordered(
                x,
                y,
                temp_text_color,
                temp_border_color,
                D->data,
                glyph_size,
                glyph_width,
                glyph_height,
                etrump_font_attr,
                is_gray_bitmap);
        }
    }
    else if (etrump_font_attr & FE_FONT_ATTR_ENGRAVE)
    {
        gdi_show_char(
            x,
            y,
            /*0xFF000000 | */etrump_border_color,
            D->data,
            glyph_size,
            glyph_width,
            glyph_height,
            etrump_font_attr,
            is_gray_bitmap);
        gdi_show_char(
            x,
            y + 1,
            /*0xFF000000 | */etrump_text_color,
            D->data,
            glyph_size,
            glyph_width,
            glyph_height,
            etrump_font_attr,
            is_gray_bitmap);
    }
    else if (glyph_size)
    {
        gdi_show_char(
            x,
            y,
            /*0xFF000000 | */etrump_text_color,
            D->data,
            glyph_size,
            glyph_width,
            glyph_height,
            etrump_font_attr,
            is_gray_bitmap);
    }
}


/*****************************************************************************
 * FUNCTION
 *  etrump_font_stream_reader
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
unsigned long etrump_font_stream_reader(FT_Stream stream,unsigned long offset,unsigned char* buffer,unsigned long count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FONT_THIRD_ROM_SUPPORT__
    MMI_ASSERT(0); // This function only support in ENFB
    return count;
#else
    if(count > 0)
    {
        if(stream->size < offset + count )
            count = stream->size - offset;
        
        offset += stream->descriptor.value;
        MMI_RESOURCE_NFB_RES_Load(ENFB_CONTENT_FONT, buffer, offset, count);
    }
    return count;
#endif
}


void etrump_font_stream_close(FT_Stream stream)
{
    // Resource didn't need to release any resource
}


/*****************************************************************************
 * FUNCTION
 *  etrump_font_file_reader
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
unsigned long etrump_font_file_reader(FT_Stream stream,unsigned long offset, unsigned char* buffer,unsigned long count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    return mmi_fe_font_file_reader((void*)stream->descriptor.value, offset, buffer, count);
}


/*****************************************************************************
 * FUNCTION
 *  etrump_font_file_close
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void etrump_font_file_close(FT_Stream stream)
{
    mmi_fe_font_file_closer((void*)stream->descriptor.value);
    stream->descriptor.value = 0;
}


  
//static FT_StreamRec g_stream[FE_MAX_FONT_FILE_NUMBER];

/*****************************************************************************
* FUNCTION
*  etrump_face_requester
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
FT_Error etrump_face_requester(FTC_FaceID face_id,FT_Library library,FT_Pointer request_data,FT_Face *aface) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FT_Error    error = 0;
    U8*         font_data;
    S32         font_size;
    //BOOL        is_enfb;
    U16 font_res;
    S32 face_index = 0;
    mmi_fe_font_resource_type_enum type; 
    #ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
    U32 offset;
    #endif

    //U32 res_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //res_id = etrump_font_list[etrump_curr_font].res_id;
    font_res = etrump_font_list[etrump_curr_font].res_id;
    face_index = etrump_font_list[etrump_curr_font].face_index;

    {
        FT_Open_Args args;
        #ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
        font_data = mmi_fe_get_font_resource(font_res, &type, &offset, &font_size);
        #else
        font_data = mmi_fe_get_font_resource(font_res, &type, &font_size);
        #endif
        
        switch (type)
        {
            case MMI_FE_FONT_OPEN_FILE_IVALID:
                error = FT_Err_Cannot_Open_Resource;
                return error;
                //break;
            case MMI_FE_FONT_OPEN_MEMORY:
                args.flags = FT_OPEN_MEMORY;
                args.memory_base = font_data;
                args.memory_size = font_size;
                break;
            case MMI_FE_FONT_OPEN_FILE_STREAM:
                {
                    FT_StreamRec* stream = &etrump_font_list[etrump_curr_font].stream;
                    memset(stream,0,sizeof(FT_StreamRec));
                    args.flags = FT_OPEN_STREAM;
                    args.stream = stream;

#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__)
                stream->descriptor.value = (FS_HANDLE)mmi_fe_get_font_stream_handle(font_res);
#else
                    stream->descriptor.value = 0;
#endif
                    stream->size             = font_size;
                    stream->read             = etrump_font_file_reader;
                    stream->close            = etrump_font_file_close;
                }
                break;
            #ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
            case MMI_FE_FONT_OPEN_ENFB_RESOURCE:
                {
                    FT_StreamRec* stream = &etrump_font_list[etrump_curr_font].stream;
                    memset(stream,0,sizeof(FT_StreamRec));
                    args.flags = FT_OPEN_STREAM;
                    args.stream = stream;

                    stream->descriptor.value = (long)offset;
                    stream->size             = font_size;
                    stream->read             = etrump_font_stream_reader;
                    stream->close            = etrump_font_stream_close;
                }
                break;
            #endif
        }

        error = FT_Open_Face(etrump_library,&args,face_index,aface);
        if (error)
            return error;

        {
            etrump_font_list[etrump_curr_font].face_index = (*aface)->face_index;
            etrump_font_list[etrump_curr_font].cmap_index = (*aface)->charmap ? FT_Get_Charmap_Index((*aface)->charmap):0;
            memcpy(etrump_font_list[etrump_curr_font].font_name, (*aface)->family_name, FREETYPE_FILE_NAME_LENGTH);
        }

        if ((*aface)->charmaps)
            (*aface)->charmap = (*aface)->charmaps[etrump_font_list[etrump_curr_font].cmap_index];
            
    }
    return error;
}


/*****************************************************************************
 * FUNCTION
 *  etrump_install_font_int
 * DESCRIPTION
 *  add font resource
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static mmi_fe_error_code etrump_install_font_int(U16 resid, etrump_font_info_p info_ptr, PU16 res_ptr, U8 region_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8*         font_data;
    S32         font_size;
    mmi_fe_font_resource_type_enum type; 
    FT_Face aface = NULL;
    FT_Open_Args args;
    //S32 num_faces;
    FT_Error error;
    #ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
    U32 offset;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Bady                                                */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
    font_data = mmi_fe_get_font_resource(resid, &type, &offset, &font_size);
    #else
    font_data = mmi_fe_get_font_resource(resid, &type, &font_size);
    #endif
    switch (type)
    {
        case MMI_FE_FONT_OPEN_FILE_IVALID:
            return MMI_FE_FONT_ERR_INVALID_FONT;
            //break;
        case MMI_FE_FONT_OPEN_MEMORY:
            args.flags = FT_OPEN_MEMORY;
            args.memory_base = font_data;
            args.memory_size = font_size;
            break;
        case MMI_FE_FONT_OPEN_FILE_STREAM:
            {
                static FT_StreamRec stream;
                memset(&stream,0,sizeof(stream));
                args.flags = FT_OPEN_STREAM;
                args.stream = &stream;
#if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__)
                stream.descriptor.value = (FS_HANDLE)mmi_fe_get_font_stream_handle(resid);
#else
                stream.descriptor.value = 0;
#endif
                stream.size             = font_size;
                stream.read             = etrump_font_file_reader;
                stream.close            = etrump_font_file_close;
            }
            break;
        #ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
        case MMI_FE_FONT_OPEN_ENFB_RESOURCE:
            {
                static FT_StreamRec stream;
                memset(&stream,0,sizeof(FT_StreamRec));
                args.flags = FT_OPEN_STREAM;
                args.stream = &stream;

                stream.descriptor.value = (long)offset;
                stream.size             = font_size;
                stream.read             = etrump_font_stream_reader;
                stream.close            = etrump_font_stream_close;
            }
            break;
        #endif

    }
    error = FT_Open_Face(etrump_library,&args,0,&aface);
    if (!error)
    {
        //num_faces = aface->num_faces;
        if (info_ptr)
        {
            info_ptr->res_id = resid;
            info_ptr->face_index = aface->face_index;
            info_ptr->cmap_index = aface->charmap ? FT_Get_Charmap_Index(aface->charmap):0;
            memcpy(info_ptr->font_name, aface->family_name, FREETYPE_FILE_NAME_LENGTH);
        }
        if (res_ptr)
        {
            *res_ptr = resid;
        }
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_FONT_THIRD_ROM_SUPPORT__) 
        etrump_set_font_info(aface, resid);
        etrump_get_unicode_region(aface, resid, region_index);
#endif
    }
    FT_Done_Face(aface);
    aface = NULL;

    if (!error)
    {
        return MMI_FE_FONT_ERR_NONE;
    }
    else
    {
        switch (error)
        {
            case FT_Err_Unknown_File_Format:
            case FT_Err_Invalid_File_Format:    
                return MMI_FE_FONT_ERR_INVALID_FONT;
                //break;
            default:
                return MMI_FE_FONT_ERR_OUT_OF_MEMORY;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  etrump_install_font
 * DESCRIPTION
 *  install font resource
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
S32 etrump_install_font(U16* font_list, U8 font_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_error_code error;
    S32 i = 0;
    S32 count = 0;
    /*----------------------------------------------------------------*/
    /* Code Bady                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_FONT_THIRD_ROM_SUPPORT__) 
    memset(unicode_region, 0, UNICODE_FONT_NUM * sizeof(font_unicode_region));
#endif

    for (i = 0; i < font_number; i++)
    {
        error = etrump_install_font_int(font_list[i], &etrump_font_list[count], &etrump_font_res_list[count], count);
        if (error == MMI_FE_FONT_ERR_NONE)
        {
            count ++;
        }
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  etrump_check_font_from_file
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static mmi_fe_error_code etrump_check_font_from_file(U16 resid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fe_error_code err;
    U8 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Bady                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
    for (i = 0; i < UNICODE_FONT_NUM; i++)
    {
        if(!unicode_region[i].region_count)
            break;
    }
#endif
    err = etrump_install_font_int(resid, &etrump_font_list[etrump_font_number], &etrump_font_res_list[etrump_font_number], i);

    return err;
}

/*****************************************************************************
 * FUNCTION
 *  etrump_set_font
 * DESCRIPTION
 *  set the active font resource
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static MMI_BOOL etrump_set_font(U16 fontres)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FT_Error error = 0;
    S32 i = 0;
    FT_Face aface = NULL;
    int temp_size = etrump_size;

    /*----------------------------------------------------------------*/
    /* Code Bady                                                */
    /*----------------------------------------------------------------*/
    for (i = 0; i < etrump_font_number; i ++)
    {
        if (etrump_font_list[i].res_id == fontres)
            break;
    }

    if (etrump_curr_font == i)
        return MMI_TRUE;
    
    etrump_curr_font = i;

    // if the highest priority customer font has been changed, 
    // delete it and create the new highest priority font.
    if (! is_system_font_resid(fontres))
    {
        if (hp_customer_font != fontres)
        {
            int j;

            hp_customer_font = fontres;

            for ( j = 0; j < etrump_font_number; j++)
            {
                if (etrump_font_list[j].res_id != hp_customer_font && !is_system_font_resid(etrump_font_list[j].res_id))
                {
                    U16 temp_resid = etrump_font_list[j].res_id;
#ifdef OPENTYPE_SUPPORT
                    if (etrump_font_list[j].layout)
                    {
                        FT_Done_Layout_Table(etrump_font_list[j].layout);
                    }
#endif
                    if (etrump_font_list[j].face)
                    {
                        FT_Done_Face(etrump_font_list[j].face);
                    }

                    memset(&etrump_font_list[j], 0, sizeof(etrump_font_info));

                    etrump_font_list[j].res_id = temp_resid;

                }
            }

        }
    }

    if (etrump_font_list[i].res_id == fontres)
    {
        if (etrump_font_list[i].face)
        {
            etrump_size = 0;
            etrump_face = etrump_font_list[i].face;
            etrump_scale_ratio = etrump_font_list[i].scale_ratio;
            etrump_set_font_size(temp_size, etrump_font_attr);
            return MMI_TRUE;
        }
    }

    if(etrump_font_list[i].face == NULL)
    {
        error = etrump_face_requester((FTC_FaceID)(etrump_font_list[i].res_id),etrump_library,NULL,&aface);
        if ( error )
        {
            /* can't access the font file. do not render anything */
            return MMI_FALSE;
        }

        etrump_font_list[i].face = aface;
        etrump_font_list[i].scale_ratio = (aface->units_per_EM << 6) / (aface->ascender - aface->descender);
        etrump_font_list[i].scale_ratio = etrump_font_list[i].scale_ratio * 8 / 7;

#ifdef OPENTYPE_SUPPORT
        FT_Load_Layout_Table( aface, &etrump_font_list[i].layout );
#endif //OPENTYPE_SUPPORT
    }
    
    etrump_face = etrump_font_list[i].face;
    etrump_scale_ratio = etrump_font_list[i].scale_ratio;

    etrump_size = 0;
    etrump_set_font_size(temp_size, etrump_font_attr);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  etrump_change_family
 * DESCRIPTION
 *  to change font family
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
BOOL etrump_change_family(U16 family_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Bady                                                */
    /*----------------------------------------------------------------*/
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  etrump_restart
 * DESCRIPTION
 *  to restart font engine
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
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
#if defined(OPENTYPE_SUPPORT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //OPENTYPE_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

/*****************************************************************************
 * FUNCTION
 *  etrump_get_font_name
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
mmi_fe_error_code etrump_get_font_name(U16 resid, U8* buffer, S32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Bady                                                */
    /*----------------------------------------------------------------*/
    for (i = 0; i < etrump_font_number; i ++)
    {
        if (etrump_font_list[i].res_id == resid)
            break;
    }

    memcpy(buffer, etrump_font_list[i].font_name, buf_size);
    return MMI_FE_FONT_ERR_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  etrump_init
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static MMI_BOOL etrump_init(U16* font_list, U8 font_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    FT_Error error = 0;
    ET_Platform platform;
    U8 sys_font_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Bady                                                */
    /*----------------------------------------------------------------*/
#if MMI_FE_EXT_RESOURCE_NUM > 0
    FS_SetFileTable(gFS_FileTable_VFont);
#endif    

    //render_flag = MMI_TRUE;
    etrump_face = NULL;

    if (etrump_library == NULL) {
        memset(&platform, 0, sizeof(ET_Platform));
        ET_Mempool_Initialize(mem_pool, POOL_SIZE, &platform.alloc, &platform.free);
        ET_Platform_Initialize(&platform);
        error = FT_Init_FreeType(&etrump_library);
        MMI_ASSERT(!error);
    }

    /* destroy all faces before installing */
    for (i = 0; i < (FE_MAX_FONT_FILE_NUMBER*FE_MAX_FONT_FAMILY_NUMBER); i++ )
    {
#ifdef OPENTYPE_SUPPORT
        if (etrump_font_list[i].layout)
        {
            FT_Done_Layout_Table(etrump_font_list[i].layout);
        }
#endif
        if (etrump_font_list[i].face)
        {
            FT_Done_Face(etrump_font_list[i].face);
        }
    }
    memset(etrump_font_list, 0, sizeof(etrump_font_info)*(FE_MAX_FONT_FILE_NUMBER*FE_MAX_FONT_FAMILY_NUMBER));

    /* initialize font list */
    sys_font_count = mmi_fe_get_system_font_number();
    if (sys_font_count < font_number)
    {
        if (is_system_font_resid(font_list[0]))
            hp_customer_font = font_list[sys_font_count];
        else
            hp_customer_font = font_list[0];
    }
    else
        hp_customer_font = 0xff;

    memcpy(etrump_font_res_list, font_list, sizeof(U16)*font_number);
    etrump_font_number = font_number;    
    etrump_curr_font = 0xff; /* initialize value */

    etrump_install_font(etrump_font_res_list, etrump_font_number);
    for (i = 0; i < etrump_font_number; i++)
    {
        //etrump_font_list[i].face = NULL;
        if(is_system_font_resid(etrump_font_res_list[i]))
            etrump_set_font(etrump_font_res_list[i]);
        else if(etrump_font_res_list[i] > IMG_GLOBAL_FONT_MAX)
            sys_font_on_memory_card++;
    }
    //render_flag = MMI_FALSE;

    /* prepare bit revise table */
    {   
        S32 i;
        for (i=0;i<256;i++)
        {
            S32 j = i;
            S32 k = 0;
            k |= j&1; k<<=1;j>>=1;
            k |= j&1; k<<=1;j>>=1;
            k |= j&1; k<<=1;j>>=1;
            k |= j&1; k<<=1;j>>=1;
            k |= j&1; k<<=1;j>>=1;
            k |= j&1; k<<=1;j>>=1;
            k |= j&1; k<<=1;j>>=1;
            k |= j&1;
            
            etrump_bits_revise_table[i] = k;

        }
    }

    etrump_text_color = 0;
    etrump_border_color = 0;
    etrump_curr_font = 0xff; /* initialize value */
    return MMI_TRUE;
}	

/*****************************************************************************
 * FUNCTION
 *  etrump_reset_face_glyphs
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void etrump_reset_face_glyphs()
{
    S32 i;
    //FT_Face face;
    for (i = 0; i < etrump_font_number; i++)
    {
        // recycle memory that was used by load(render) char(glph)
        // including glyph bitmap, outline and glyph loader
        FT_Reset_Glyph(etrump_font_list[i].face);
    }

}

/*****************************************************************************
 * FUNCTION
 *  etrump_shaper
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void etrump_shaper(U32 lang, U32 script, UI_string_type text, S32 text_len, S32 start_index, S32 run_len, mmi_fe_cluster_info_p cluster)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Bady                                                */
    /*----------------------------------------------------------------*/

#if defined(__MMI_INDIC_ALG__)
    mmi_fe_cluster_info pre_cluster;
    mmi_fe_cluster_info all_cluster;
    mmi_fe_cluster_info_init(&pre_cluster);
    mmi_fe_cluster_info_init(&all_cluster);
#endif

    etrump_reset_face_glyphs();

    //render_flag = MMI_TRUE;
    cluster->glyph_len = 0;

    switch( script ) {
#if defined(__MMI_LANG_THAI__)
        case MMI_FE_OT_SCRIPT_THAI:
            break;
#endif // __MMI_LANG_THAI__

#if defined(__MMI_INDIC_ALG__)
        case MMI_FE_OT_SCRIPT_DEVANAGARI:
        case MMI_FE_OT_SCRIPT_BENGALI:
        case MMI_FE_OT_SCRIPT_GUJARATI:
        case MMI_FE_OT_SCRIPT_GURMUKHI:
        case MMI_FE_OT_SCRIPT_KANNADA:
        case MMI_FE_OT_SCRIPT_MALAYALAM:
        case MMI_FE_OT_SCRIPT_ORIYA:
        case MMI_FE_OT_SCRIPT_TAMIL:
        case MMI_FE_OT_SCRIPT_TELUEU:
            break;
#endif // __MMI_INDIC_ALG__

#if defined(__MMI_LANG_LAO__)
        case MMI_FE_OT_SCRIPT_LAO:
            break;
#endif // __MMI_LANG_LAO__

#if defined(__MMI_LANG_MYANMAR__)
        case MMI_FE_OT_SCRIPT_MYANMAR:
            break;
#endif // __MMI_LANG_MYANMAR__


        default:
            for (i = 0; i < run_len; i ++)
            {
                if (!TEST_FORMAT_CHAR(text[start_index + i]))
                {
                    cluster->glyph_buf[cluster->glyph_len].glyph_index = etrump_map_char(text[start_index + i]);
                    cluster->glyph_len++;
                }
            }                 

            //render_flag = MMI_FALSE;
            return;
    }
#if defined(OPENTYPE_SUPPORT)
#if defined(__MMI_INDIC_ALG__)
    FT_Shape_OpenType_Info(etrump_font_list[etrump_curr_font].layout, text, text_len - run_len, 0, (MT_Cluster_Info)&pre_cluster);
    FT_Shape_OpenType_Info(etrump_font_list[etrump_curr_font].layout, text, text_len, 0, (MT_Cluster_Info)&all_cluster);
			   
    for (i = 0; i < all_cluster.glyph_len; i++)
    {
        memcpy(&cluster->glyph_buf[i], &all_cluster.glyph_buf[pre_cluster.glyph_len + i], sizeof(mmi_fe_glyph_ot_info));
    }
    cluster->glyph_len = all_cluster.glyph_len - pre_cluster.glyph_len;
#else
    FT_Shape_OpenType_Info(etrump_font_list[etrump_curr_font].layout, &text[start_index], run_len, 0, (MT_Cluster_Info)cluster );
#endif
#endif
	  //render_flag = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  etrump_check_script
 * DESCRIPTION
 *  to check the script and lang support
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL etrump_check_script(U32 lang, U32 script, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_FALSE;
}

#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_FONT_THIRD_ROM_SUPPORT__) 
MMI_BOOL etrump_get_font_resid(U16 ucs2, U16* res_id, U8* num)
{
    int i, j;
    int idx = 0;

    for (i = 0; i < UNICODE_FONT_NUM; i++)
    {
        int r_count = unicode_region[i].region_count;

        for (j = 0; j < r_count; j++)
        {
            if (ucs2 >= unicode_region[i].start[j] && ucs2 <= unicode_region[i].end[j])
            {
                res_id[idx] = unicode_region[i].resid;
                idx++;
                break;
            }
        }

        if (idx >= *num)
            break;
    }

    *num = idx;
    if(!idx)
        return MMI_FALSE;
    else
        return MMI_TRUE;
}
#endif

#if defined(__MMI_VECTOR_FONT_KERNING__)
#define FTAutoKern_AdjustF(prev, next)   (((next) - (prev) + 32) >> 6 << 16)

/*****************************************************************************
 * FUNCTION
 *  etrump_get_font_kerning
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL etrump_get_font_kerning (U16 left_ucs2, U16 right_ucs2, signed long *x, signed long *y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    signed long use_kerning;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //left_ucs2 = 0x0056;
    //right_ucs2 = 0x0041;
    *x = 0;
    *y = 0;
    use_kerning = FT_HAS_KERNING (etrump_face);

    if ( use_kerning && left_ucs2 && right_ucs2 ) 
    { 
        FT_Vector delta; 
        FT_UInt glyph_index_prev, glyph_index_curr;
        glyph_index_prev = left_ucs2;//FT_Get_Char_Index( etrump_face, left_ucs2);
        glyph_index_curr = right_ucs2;//FT_Get_Char_Index( etrump_face, right_ucs2 );

        FT_Get_Kerning( etrump_face, glyph_index_prev, glyph_index_curr, FT_KERNING_DEFAULT, &delta ); 
        *x = delta.x;
        *y = delta.y;
        return MMI_TRUE; 
    }
    return MMI_FALSE; 
}

/*****************************************************************************
 * FUNCTION
 *  etrump_has_kerning
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL etrump_has_kerning (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    signed long use_kerning;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    use_kerning = FT_HAS_KERNING (etrump_face);
    if (use_kerning) 
    { 
        return MMI_TRUE; 
    }
    return MMI_FALSE; 
}

#endif /* __MMI_VECTOR_FONT_KERNING__ */

const fe_table_struct font_engine_table=
{
    MMI_FE_ENGINE_VERSION_09B_FEATURE_SET,
    etrump_init,
    etrump_set_font_attr,
    etrump_set_font_size,
    etrump_set_font_color,
    etrump_get_font_data,
    etrump_show_font_data,
    etrump_get_font_info,
    etrump_set_antialias,
    etrump_set_font,
    etrump_shaper,
    etrump_check_font_from_file,
    etrump_get_font_name
#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__) || defined(__MMI_FONT_THIRD_ROM_SUPPORT__) 
    ,etrump_get_font_resid
#endif
#if defined(__MMI_VECTOR_FONT_KERNING__)
    ,etrump_get_font_kerning,
    etrump_map_char,
    etrump_has_kerning
#endif /* __MMI_VECTOR_FONT_KERNING__ */ 
};


#endif

