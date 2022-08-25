/* Copyright (c) 2009 The Khronos Group Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and/or associated documentation files (the
 * "Materials"), to deal in the Materials without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Materials, and to
 * permit persons to whom the Materials are furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Materials.
 *
 * THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
 */

#ifndef __OWFIMAGE_H__
#define __OWFIMAGE_H__

#include "owftypes.h"


#ifdef __cplusplus
extern "C" {
#endif

#undef USE_FLOAT_PIXEL

/* 
 *  This is and always should be the only place where USE_FLOAT_PIXEL is
 *  defined so if #define USE_FLOAT_PIXEL is absent in owfimage.h then it
 *  can be assumed it is not defined elsewhere.
 *  \remark <b>[MTK]</b> We don't use float pixel.
 */ 
//#define USE_FLOAT_PIXEL

/* --
* internal pixel format
*/
#ifdef USE_FLOAT_PIXEL
#define OWF_IMAGE_INTERNAL_PIXEL_IS_FLOAT

typedef OWFfloat            OWFsubpixel; /* subpixel representation */

#define OWF_RED_MIN_VALUE   0.0f
#define OWF_RED_MAX_VALUE   1.0f
#define OWF_GREEN_MIN_VALUE 0.0f
#define OWF_GREEN_MAX_VALUE 1.0f
#define OWF_BLUE_MIN_VALUE  0.0f
#define OWF_BLUE_MAX_VALUE  1.0f

#define OWF_ALPHA_MIN_VALUE 0.0f
#define OWF_ALPHA_MAX_VALUE 1.0f

#define OWF_FULLY_OPAQUE        OWF_ALPHA_MAX_VALUE
#define OWF_FULLY_TRANSPARENT   OWF_ALPHA_MIN_VALUE

#define OWF_BYTE_MAX_VALUE  255.0f

#define OWF_BILINEAR_ROUNDING_VALUE 0.0f
#define OWF_BLEND_ROUNDING_VALUE 0.0f
#define OWF_PREMUL_ROUNDING_FACTOR  0.0f

#else
#undef OWF_IMAGE_INTERNAL_PIXEL_IS_FLOAT

typedef OWFuint8            OWFsubpixel; /* subpixel representation */

#define OWF_RED_MIN_VALUE         0
#define OWF_RED_MAX_VALUE       255
#define OWF_GREEN_MIN_VALUE       0
#define OWF_GREEN_MAX_VALUE     255
#define OWF_BLUE_MIN_VALUE        0
#define OWF_BLUE_MAX_VALUE      255
#define OWF_ALPHA_MIN_VALUE       0
#define OWF_ALPHA_MAX_VALUE     255
#define OWF_FULLY_OPAQUE        OWF_ALPHA_MAX_VALUE
#define OWF_FULLY_TRANSPARENT   OWF_ALPHA_MIN_VALUE

#define OWF_BYTE_MAX_VALUE      255

#define OWF_BILINEAR_ROUNDING_VALUE 0.5f
#define OWF_BLEND_ROUNDING_VALUE (OWF_ALPHA_MAX_VALUE/2)
#define OWF_PREMUL_ROUNDING_FACTOR (OWF_ALPHA_MAX_VALUE/2)

#endif

/*
 * Byte order of different color formats
 * these are used when converting from/to
 * internal format
 */

#define ARGB8888_ALPHA_MASK         0xFF000000
#define ARGB8888_RED_MASK           0x00FF0000
#define ARGB8888_GREEN_MASK         0x0000FF00
#define ARGB8888_BLUE_MASK          0x000000FF
#define ARGB8888_ALPHA_SHIFT        24
#define ARGB8888_RED_SHIFT          16
#define ARGB8888_GREEN_SHIFT        8
#define ARGB8888_BLUE_SHIFT         0

#define RGB565_ALPHA_MASK   0xFFFF
#define RGB565_RED_MASK     0xF800
#define RGB565_GREEN_MASK   0x07E0
#define RGB565_BLUE_MASK    0x001F

/* These are used when converting from RGB565 to ARGB8888. */
#define RGB565_ALPHA_SHIFT  16
#define RGB565_RED_SHIFT    11
#define RGB565_GREEN_SHIFT  5

/* subpixels per pixel */
#define OWF_PIXEL_SIZE      4

/* subpixel in bytes */
#define OWF_SUBPIXEL_SIZE   sizeof(OWFsubpixel)
#define OWF_BYTES_PER_PIXEL (OWF_PIXEL_SIZE * OWF_SUBPIXEL_SIZE)

#pragma pack(push, 1)
typedef union {
    struct {
        OWFsubpixel         blue;
        OWFsubpixel         green;
        OWFsubpixel         red;
        OWFsubpixel         alpha;
    } color;
    OWFsubpixel             subpixel[OWF_PIXEL_SIZE];
    OWFuint8                pixelbytes[OWF_BYTES_PER_PIXEL];
} OWFpixel;
#pragma pack(pop)

/* -- */

/* filters used in OWF_Image_Stretch */
typedef enum {
    OWF_FILTER_POINT_SAMPLING,  /* nearest pixel */
    OWF_FILTER_BILINEAR        /* nearest 4 */
} OWF_FILTERING;

typedef struct {
    OWFint                  width;
    OWFint                  height;
    OWFint                  stride; /**< number of bytes per line */
    OWFint                  pixelSize; /**< pixel size in bytes */
    OWF_IMAGE_FORMAT        format;
    OWFboolean              foreign; /**< The data buffer is allocated outside. */
    OWFint                  dataMax; /* data buffer max size */
    //OWFboolean              alphaEnable; /**< MTK: Enable global alpha for flatten */
    OWFint                  alpha; /** MTK: desired target alpha for ARGB format fow w2mem*/
    void*                   data;
} OWF_IMAGE;

/* This typedef denotes an owned OWF_IMAGE, as opposed to a temporary association.
 * Owned instances must be destroyed when the containing object is destroyed.
 */
typedef OWF_IMAGE* OWF_IMAGE_INST;

typedef enum {
    OWF_FLIP_NONE,
    OWF_FLIP_VERTICALLY     = 1,
    OWF_FLIP_HORIZONTALLY   = 2
} OWF_FLIP_DIRECTION;

typedef enum {
    OWF_ROTATION_0          = 0,
    OWF_ROTATION_90         = 90,
    OWF_ROTATION_180        = 180,
    OWF_ROTATION_270        = 270
} OWF_ROTATION;

typedef enum {
    OWF_TRANSPARENCY_NONE,
    OWF_TRANSPARENCY_GLOBAL_ALPHA   = (1 << 0),
    OWF_TRANSPARENCY_SOURCE_ALPHA   = (1 << 1),
    OWF_TRANSPARENCY_MASK           = (1 << 2),
    OWF_TRANSPARENCY_COLOR_KEY      = (1 << 3)
} OWF_TRANSPARENCY;

typedef struct _OWF_BLEND_INFO {
    struct {
        OWF_IMAGE*          image;
        OWF_RECTANGLE*      rectangle;
    } destination;

    struct {
        OWF_IMAGE*          image;
        OWF_RECTANGLE*      rectangle;
    } source;

    OWF_IMAGE*              mask;
    OWFsubpixel             globalAlpha;
    OWFboolean              destinationFullyOpaque;
    OWFpixel*               tsColor;
} OWF_BLEND_INFO;


/*!---------------------------------------------------------------------------
 *  \brief Initialize image object
 *
 *  \param
 *
 *  \return
 *----------------------------------------------------------------------------*/
OWF_API_CALL void
OWF_Image_FreeData(void** buffer);

/*!---------------------------------------------------------------------------
 *  \param image            Image to resize
 *  \param width            New width of the image
 *
 *  \param image            Image to resize
 *  \param premultiply      Image data is premultiplied
 *  \param dstRect          Destination rectangle
 *  \param src              Source image
 *  \param src              Source image
 *  \brief
 *
 *  \param
 *
 *  \return
 *----------------------------------------------------------------------------*/
OWF_API_CALL OWFint
OWF_Image_GetFormatPixelSize(OWF_PIXEL_FORMAT format);

/*!---------------------------------------------------------------------------
 *  \brief
 *
 *  \param
 *
 *  \return
 *----------------------------------------------------------------------------*/
OWF_API_CALL OWFint
OWF_Image_GetFormatPixelSize(OWF_PIXEL_FORMAT format);


/*!---------------------------------------------------------------------------
 *  \brief Return pointer to given pixel in image.
 *
 *  \param image            Image
 *  \param x                X-coordinate of the pixel (0..width-1)
 *  \param y                Y-coordinate of the pixel (0..height-1)
 *
 *  The x & y coordinates will be clamped to [0..width-1, 0..height-1]
 *
 *  \return Pointer to given pixel
 *----------------------------------------------------------------------------*/
OWF_API_CALL OWFpixel*
OWF_Image_GetPixelPtr(OWF_IMAGE* image,
                      OWFint x,
                      OWFint y);

/*!---------------------------------------------------------------------------
 * \brief Return stride (aligned row size in bytes) calculated from image
 * width and pixelSize. If pixelSize is negative image width must be divisible
 * by pixelSize.
 *
 * \param width             Width of image
 * \param pixelSize         Size of single pixel in bytes. Negative size
 *                          means value is a divisor (i.e. 1/pixelSize)
 * \param padding           Number of bits each row is padded to.

 * \return Row size in bytes.
 *----------------------------------------------------------------------------*/
OWF_PUBLIC OWFint
OWF_Image_GetStride(OWFint width,
                    const OWF_IMAGE_FORMAT* format,
                    OWFint minimumStride);


#ifdef __cplusplus
}
#endif

#endif  /* __OWFIMAGE_H__ */
