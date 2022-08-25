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

#ifdef __cplusplus
extern "C"
{
#endif

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#include "common\owfimage.h"
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


#ifdef OWF_IMAGE_INTERNAL_PIXEL_IS_FLOAT
#define roundSubPixel(p) ((OWFuint32)((p) + 0.5f))
#else
#define roundSubPixel(p) (p)
#endif


/*----------------------------------------------------------------------------*/
OWF_API_CALL void
OWF_IMAGE_Ctor(void* self)
{
    self = self;
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL void
OWF_IMAGE_Dtor(void* self)
{
    OWF_IMAGE* image;

    image = (OWF_IMAGE*)self;

    if (image && image->data)
    {
        if (!image->foreign)
        {
            OWF_Image_FreeData(&image->data);
        }
    }

    if (image)
    {
        memset(image, 0, sizeof(OWF_IMAGE));
    }
}

#if defined(OWF_IMAGE_INTERNAL_PIXEL_IS_FLOAT)
/*----------------------------------------------------------------------------*/
static OWFfloat
NonLinear(OWFfloat x)
{
    if (x <= 0.00304f)
    {
        return 12.92f * x;
    }
    return 1.0556f * pow(x, 1.f/2.4f) - 0.0556f;
}

/*----------------------------------------------------------------------------*/
static OWFfloat
Linear(OWFfloat x)
{
    if (x <= 0.03928)
    {
        return x / 12.92f;
    }
    return pow((x + 0.0556f) / 1.0556f, 2.4f);
}
#endif

/*----------------------------------------------------------------------------*/
OWF_API_CALL void
OWF_Image_NonLinearizeData(OWF_IMAGE* image)\
{
#if defined(OWF_IMAGE_INTERNAL_PIXEL_IS_FLOAT)
    OWFpixel*            ptr;
    OWFint               count;

    OWF_ASSERT(image != NULL && image->data != NULL);
    OWF_ASSERT(image->format.pixelFormat==OWF_IMAGE_ARGB_INTERNAL);

    if (!image->format.linear)
    {
        return;
    }

    ptr = (OWFpixel*) image->data;
    count = image->width * image->height;

    while (count > 0)
    {
        ptr->color.red   = (OWFsubpixel) NonLinear(ptr->color.red /
                               OWF_RED_MAX_VALUE) * OWF_RED_MAX_VALUE;
        ptr->color.green = (OWFsubpixel) NonLinear(ptr->color.green /
                               OWF_GREEN_MAX_VALUE) * OWF_GREEN_MAX_VALUE;
        ptr->color.blue  = (OWFsubpixel) NonLinear(ptr->color.blue /
                               OWF_BLUE_MAX_VALUE) * OWF_BLUE_MAX_VALUE;

        --count;
        ptr++;
    }

    image->format.linear = OWF_FALSE;
#endif
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL void
OWF_Image_LinearizeData(OWF_IMAGE* image)
{
#if defined(OWF_IMAGE_INTERNAL_PIXEL_IS_FLOAT)
    OWFpixel*               ptr;
    OWFuint                 count;

    OWF_ASSERT(image != NULL && image->data != NULL);
    OWF_ASSERT(image->format.pixelFormat==OWF_IMAGE_ARGB_INTERNAL);

    if (image->format.linear)
    {
        return;
    }

    ptr = (OWFpixel*) image->data;
    count = image->width * image->height;

    while (count > 0)
    {
        ptr->color.red   = (OWFsubpixel) Linear(ptr->color.red /
                               OWF_RED_MAX_VALUE) * OWF_RED_MAX_VALUE;
        ptr->color.green = (OWFsubpixel) Linear(ptr->color.green /
                               OWF_GREEN_MAX_VALUE) * OWF_GREEN_MAX_VALUE;
        ptr->color.blue  = (OWFsubpixel) Linear(ptr->color.blue /
                               OWF_BLUE_MAX_VALUE) * OWF_BLUE_MAX_VALUE;
        --count;
        ptr += image->pixelSize;
    }

    image->format.linear = OWF_TRUE;
#endif
}

/*----------------------------------------------------------------------------*/
#define GAMMA(color, max, gamma) (max * pow(color/max, gamma))

OWF_API_CALL void
OWF_Image_Gamma(OWF_IMAGE* image, OWFfloat gamma)
{
#if defined(OWF_IMAGE_INTERNAL_PIXEL_IS_FLOAT)
    OWFpixel*            ptr;
    OWFint               count;

    OWF_ASSERT(image != NULL && image->data != NULL);
    OWF_ASSERT(image->format.pixelFormat==OWF_IMAGE_ARGB_INTERNAL);

    if (gamma == 1.0f)
    {
        return;
    }

    ptr = (OWFpixel*) image->data;
    count = image->width * image->height;

    while (count > 0)
    {
        ptr->color.red   =
            (OWFsubpixel) GAMMA(ptr->color.red, OWF_RED_MAX_VALUE, gamma);
        ptr->color.green =
            (OWFsubpixel) GAMMA(ptr->color.green, OWF_GREEN_MAX_VALUE, gamma);
        ptr->color.blue  =
            (OWFsubpixel) GAMMA(ptr->color.blue, OWF_BLUE_MAX_VALUE, gamma);

        --count;
        ptr++;
    }
#endif
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL void
OWF_Image_EdgeReplication(OWF_IMAGE* image)
{
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
#endif
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL OWFboolean
OWF_Image_SourceFormatConversion(OWF_IMAGE* dst, OWF_IMAGE* src)
{
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
#endif
    return OWF_FALSE;
}

/*----------------------------------------------------------------------------*/
OWF_PUBLIC OWFint
OWF_Image_GetStride(OWFint width, const OWF_IMAGE_FORMAT* format, OWFint minimumStride)
{
    OWFint                  size;
    OWFint                  pixelSize;

    // TODO: check if we need owfdebug.h
    //OWF_ASSERT(format); 

    pixelSize = OWF_Image_GetFormatPixelSize(format->pixelFormat);

    if (pixelSize < 0)
    {
        /* negative pixelSize means that pixel size is a fraction
         * (1/-pixelSize) of a byte, e.g. -8 means pixel has size
         * of one bit. */

        size = (width + 1) / -pixelSize;
    }
    else
    {
        size = width * pixelSize;
    }
    
    if (size<minimumStride)
    {
        size=minimumStride;
    }
    if (format->rowPadding)
    {
        size += format->rowPadding - 1;
        size -= size % format->rowPadding;
    }

    return size;
}


/*----------------------------------------------------------------------------*/
OWF_API_CALL OWFboolean
OWF_Image_DestinationFormatConversion(OWF_IMAGE* dst, OWF_IMAGE* src)
{
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
#endif
    return OWF_FALSE;
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL void
OWF_Image_Init(OWF_IMAGE* image)
{
    //OWF_ASSERT(NULL != image);
    memset(image, 0, sizeof(OWF_IMAGE));
}

/*----------------------------------------------------------------------------*/
OWF_PUBLIC OWF_IMAGE*
OWF_Image_Create(OWFint width,
                 OWFint height,
                 const OWF_IMAGE_FORMAT* format,
                 void* buffer,
                 OWFint minimumStride)
{
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
#endif
    // we cannot create since we don't have memory
    return NULL;
}

/*----------------------------------------------------------------------------*/
OWF_PUBLIC void OWF_Image_Destroy(OWF_IMAGE* image)
{
    // we don't need to destroy since the memory is not dynamically allocated.
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*----------------------------------------------------------------------------*/
OWF_API_CALL OWF_IMAGE*
OWF_Image_Copy(const OWF_IMAGE* image)
{
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
    // Without memory to allocate, we cannot support copy constructor.
    return NULL;
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL OWFboolean
OWF_Image_SetSize(OWF_IMAGE* image,
                  OWFint width,
                  OWFint height)
{
    OWFint                  size;
    OWFint                  stride;

    //OWF_ASSERT(image);
            
    /** note that this setsize ignores any specialised stride **/
    stride = OWF_Image_GetStride(width, &image->format, 0);
    size = height * stride;

    /* change source size if buffer have enough space */
    if (size > 0 && size <= image->dataMax)
    {
        image->height = height;
        image->width  = width;
        image->stride = stride;
        return OWF_TRUE;
    }
    return OWF_FALSE;
}
/*----------------------------------------------------------------------------*/
OWF_API_CALL void
OWF_Image_SetFlags(OWF_IMAGE* image,
                  OWFboolean premultiply,
                  OWFboolean linear)
{
    //OWF_ASSERT(image);
    //OWF_ASSERT(image->format.pixelFormat==OWF_IMAGE_ARGB_INTERNAL ||
    //           image->format.pixelFormat==OWF_IMAGE_L32);
            
    image->format.linear=linear;
    image->format.premultiplied=premultiply;
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL void
OWF_Image_SetPixelBuffer(OWF_IMAGE* image,      void* buffer)
{
    //OWF_ASSERT(image);
    //OWF_ASSERT(buffer);
    //OWF_ASSERT(image->foreign);
    if (image->foreign)
    {
        image->data = buffer;
    }
}
/*----------------------------------------------------------------------------*/
/* NEVER USED */
OWF_API_CALL OWFboolean
OWF_Image_SetPixelData(OWF_IMAGE* image,
                       OWFint width,
                       OWFint height,
                       const OWF_IMAGE_FORMAT* format,
                       void* buffer)
{
    OWFint                  size = 0,
                            stride = 0;

    //OWF_ASSERT(image && format);

    stride  = OWF_Image_GetStride(width, format, 0);
    size    = height * stride;

    if (size <= 0)
    {
        return OWF_FALSE; /* overflow */
    }

    if (!image->foreign)
    {
        OWF_Image_FreeData(&image->data);
    }

    image->format.pixelFormat   = format->pixelFormat;
    image->format.linear        = format->linear;
    image->format.premultiplied = format->premultiplied;
    image->format.rowPadding    = format->rowPadding;

    image->pixelSize    = OWF_Image_GetFormatPixelSize(format->pixelFormat);
    image->width        = width;
    image->height       = height;
    image->stride       = stride;
    image->foreign      = OWF_TRUE;
    image->dataMax      = size;
    image->data         = buffer;

    return OWF_TRUE;
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL OWFboolean
OWF_Image_Blit(OWF_IMAGE* dst,
               OWF_RECTANGLE const* dstRect,
               OWF_IMAGE const* src,
               OWF_RECTANGLE const* srcRect)
{
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
#endif
    return OWF_FALSE;
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL OWFpixel*
OWF_Image_GetPixelPtr(OWF_IMAGE* image,
                      OWFint x,
                      OWFint y)
{
    //OWF_ASSERT(image && image->format.pixelFormat==OWF_IMAGE_ARGB_INTERNAL);
    if (!(image && image->data))
    {
        return 0;
    }

    x = CLAMP(x, 0, image->width-1);
    y = CLAMP(y, 0, image->height-1);

    return (OWFpixel*)image->data + y * image->width  + x ;
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL void
OWF_Image_GetPixel(OWF_IMAGE* image,
                   OWFint x,
                   OWFint y,
                   OWFpixel* pixel)
{
    OWFpixel*               temp = NULL;

    //OWF_ASSERT(pixel);

    if (!(image && image->data))
    {
        return;
    }
    //OWF_ASSERT(image->format.pixelFormat==OWF_IMAGE_ARGB_INTERNAL);

    pixel->color.alpha = 0;
    pixel->color.red = 0;
    pixel->color.green = 0;
    pixel->color.blue = 0;

    if (x < 0 || y < 0 || x >= image->width || y >= image->height)
    {
        return;
    }

    temp = (OWFpixel*)image->data + y * image->width  + x;

    pixel->color.alpha = temp->color.alpha;
    pixel->color.red = temp->color.red;
    pixel->color.green = temp->color.green;
    pixel->color.blue = temp->color.blue;
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL void
OWF_Image_SetPixel(OWF_IMAGE* image,
                   OWFint x,
                   OWFint y,
                   OWFpixel const* pixel)
{
    OWFpixel*               data = NULL;

    if (!(image && image->data))
    {
        return;
    }
    //OWF_ASSERT(image->format.pixelFormat==OWF_IMAGE_ARGB_INTERNAL);

    if(x < 0 || y < 0 || x >= image->width || y >= image->height)
    {
        return;
    }


    data = (OWFpixel*)image->data + y * image->width + x;

    data->color.red = pixel->color.red;
    data->color.green = pixel->color.green;
    data->color.blue = pixel->color.blue;
    data->color.alpha = pixel->color.alpha;
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL OWFboolean
OWF_Image_PointSamplingStretchBlit(OWF_IMAGE* dst,
                                   OWF_RECTANGLE* dstRect,
                                   OWF_IMAGE* src,
                                   OWFfloat* srcRect)
{
#if defined(OWF_IMAGE_INTERNAL_PIXEL_IS_FLOAT)
    OWFint                  ox = 0, oy = 0;
    OWFfloat                dx = 0.f, dy = 0.f; 
    OWFint                  x, y;

    /* images must be valid */
    if (!((src != NULL) && (src->data != NULL) &&
          (dst != NULL) && (dst->data != NULL)))
    {
        return OWF_FALSE;
    }
    OWF_ASSERT(src->format.pixelFormat==OWF_IMAGE_ARGB_INTERNAL);
    OWF_ASSERT(dst->format.pixelFormat==OWF_IMAGE_ARGB_INTERNAL);

    /* ditto with rectangles, too */
    if (!((dstRect != NULL) && (dstRect->width && dstRect->height) &&
          (srcRect != NULL) && (srcRect[2] && srcRect[3])))
    {
        return OWF_FALSE;
    }

    /* Note: bounds check missing */

    if (src->pixelSize != dst->pixelSize)
    {
        return OWF_FALSE;
    }

    /* solve scaling ratios for image */
    dx = (OWFfloat) srcRect[2] / (OWFfloat) dstRect->width;
    dy = (OWFfloat) srcRect[3] / (OWFfloat) dstRect->height;

    for (y = 0; y < dstRect->height; y++)
    {
        for (x = 0; x < dstRect->width; x++)
        {
            OWFpixel*       pixel;     
            
            /* NOTE This code uses pixel center points to calculate distances
                    and factors. Results can differ slightly when pixel corner
                    coordinates are used */

            /* coordinates of nearest pixel in original image */
            ox = (int) floor((((OWFfloat) x + 0.5) * dx) + srcRect[0]);
            oy = (int) floor((((OWFfloat) y + 0.5) * dy) + srcRect[1]);   
            
            pixel = OWF_Image_GetPixelPtr(src,
                                          ox,
                                          oy);            
            
            OWF_Image_SetPixel(dst,
                               dstRect->x + x,
                               dstRect->y + y,
                               pixel);
        }
    }
    return OWF_TRUE;
#endif
    return OWF_FALSE;
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL OWFboolean
OWF_Image_BilinearStretchBlit(OWF_IMAGE* dst,
                              OWF_RECTANGLE* dstRect,
                              OWF_IMAGE* src,
                              OWFfloat* srcRect)
{
#if defined(OWF_IMAGE_INTERNAL_PIXEL_IS_FLOAT)
    OWFint                  x = 0, y = 0;
    OWFint                  ox = 0, oy = 0;
    OWFfloat                dx = 0.f, dy = 0.f, wx = 0.f, wy = 0.f;
    OWFfloat                w[2 * 2];
    OWFpixel*               sample[4];
    OWFpixel*               pixel = NULL;

    /* images must be valid */
    if (!((src != NULL) && (src->data != NULL) &&
          (dst != NULL) && (dst->data != NULL)))
    {
        return OWF_FALSE;
    }
    OWF_ASSERT(src->format.pixelFormat==OWF_IMAGE_ARGB_INTERNAL);
    OWF_ASSERT(dst->format.pixelFormat==OWF_IMAGE_ARGB_INTERNAL);

    /* ditto with rectangles, too */
    if (!((dstRect != NULL) && (dstRect->width && dstRect->height) &&
          (srcRect != NULL) && (srcRect[2] && srcRect[3])))
    {
        return OWF_FALSE;
    }

    if (src->pixelSize != dst->pixelSize)
    {
        return OWF_FALSE;
    }

    /* solve scaling ratios for image */
    dx = (OWFfloat) srcRect[2] / (OWFfloat) dstRect->width;
    dy = (OWFfloat) srcRect[3] / (OWFfloat) dstRect->height;

    for (y = 0; y < dstRect->height; y++)
    {
        for (x = 0; x < dstRect->width; x++)
        {
            OWFfloat tempOx, tempOy;            
            
            /* NOTE This code uses pixel center points to calculate distances
                    and factors. Results can differ slightly when pixel corner
                    coordinates are used */

            /* coordinates of nearest pixel in original image */
            tempOx = (((OWFfloat) x + 0.5) * dx) + srcRect[0];
            tempOy = (((OWFfloat) y + 0.5) * dy) + srcRect[1];            
            
            ox = (int) floor((((OWFfloat) x + 0.5) * dx) + srcRect[0]);
            oy = (int) floor((((OWFfloat) y + 0.5) * dy) + srcRect[1]);    

            /* Distances to nearest pixel, eg. fractional part of coordinate */    
            wx = (OWFfloat) ox + 0.5 - tempOx;
            wy = (OWFfloat) oy + 0.5 - tempOy;

            /* If distance is positive, we should use left or upper pixel for
             * second nearest pixel. */
            if (wx > 0.0)
            {
                ox--;
                wx = 1.0 - wx;
            }
            else
            {
                wx = -wx; /* abs */
            }

            if (wy > 0.0)
            {
                oy--;
                wy = 1.0 - wy;
            }
            else
            {
                wy = -wy;
            }
            
            /* Calculate weights for samples */
            w[0] = (1.0 - wx) * (1.0 - wy);
            w[1] = wx * (1.0 - wy);
            w[2] = (1.0 - wx) * wy;
            w[3] = wx * wy;

            /* get sample */
            sample[0] = OWF_Image_GetPixelPtr(src, ox + 0, oy + 0);
            sample[1] = OWF_Image_GetPixelPtr(src, ox + 1, oy + 0);
            sample[2] = OWF_Image_GetPixelPtr(src, ox + 0, oy + 1);
            sample[3] = OWF_Image_GetPixelPtr(src, ox + 1, oy + 1);

            /* get result pixel */
            pixel = OWF_Image_GetPixelPtr(dst, x, y);

            /* calculate final color */
            pixel->color.red   =
                sample[0]->color.red * w[0] + sample[1]->color.red * w[1] +
                sample[2]->color.red * w[2] + sample[3]->color.red * w[3] + OWF_BILINEAR_ROUNDING_VALUE;

            pixel->color.green =
                sample[0]->color.green * w[0] + sample[1]->color.green * w[1] +
                sample[2]->color.green * w[2] + sample[3]->color.green * w[3] + OWF_BILINEAR_ROUNDING_VALUE;

            pixel->color.blue  =
                sample[0]->color.blue * w[0] + sample[1]->color.blue * w[1] +
                sample[2]->color.blue * w[2] + sample[3]->color.blue * w[3] + OWF_BILINEAR_ROUNDING_VALUE;

            pixel->color.alpha =
                sample[0]->color.alpha * w[0] + sample[1]->color.alpha * w[1] +
                sample[2]->color.alpha * w[2] + sample[3]->color.alpha * w[3] + OWF_BILINEAR_ROUNDING_VALUE;
        }
    }
    return OWF_TRUE;
#endif
    return OWF_FALSE;
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL OWFboolean
OWF_Image_Stretch(OWF_IMAGE* dst,
                  OWF_RECTANGLE* dstRect,
                  OWF_IMAGE* src,
                  OWFfloat* srcRect,
                  OWF_FILTERING filter)
{
#if defined(OWF_IMAGE_INTERNAL_PIXEL_IS_FLOAT)
    OWFboolean          result = OWF_FALSE;

    switch (filter)
    {
        case OWF_FILTER_POINT_SAMPLING:
        {
            result = OWF_Image_PointSamplingStretchBlit(dst, dstRect, src,
                                                        srcRect);
            break;
        }
        case OWF_FILTER_BILINEAR:
        {
            result = OWF_Image_BilinearStretchBlit(dst, dstRect, src, srcRect);
            break;
        }
    }

    return result;
#endif
    return OWF_FALSE;
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL void
OWF_Image_Clear(OWF_IMAGE* image,
                OWFsubpixel red,
                OWFsubpixel green,
                OWFsubpixel blue,
                OWFsubpixel alpha)
{
    OWFint                  i, numPixels;
    OWFpixel*                pixels;

    //OWF_ASSERT(image != 0);
    //OWF_ASSERT(image->data != 0);
    //OWF_ASSERT(image->format.pixelFormat == OWF_IMAGE_ARGB_INTERNAL);

    numPixels = image->width * image->height;
    pixels = (OWFpixel*) image->data;

    // TODO: It seems very slow...
    for (i = 0; i < numPixels; i++)
    {
        pixels[i].color.red   = (OWFsubpixel) red;
        pixels[i].color.green = (OWFsubpixel) green;
        pixels[i].color.blue  = (OWFsubpixel) blue;
        pixels[i].color.alpha = (OWFsubpixel) alpha;
    }
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL void
OWF_Image_PremultiplyAlpha(OWF_IMAGE* image)
{
    OWFint       x, y;

    //OWF_ASSERT(image != 0);

    if (image->format.premultiplied)
    {
        return;
    }

    /* only for internal format */
    if (image->format.pixelFormat != OWF_IMAGE_ARGB_INTERNAL)
    {
        return;
    }

    for (y = 0; y < image->height; y++)
    {
        for (x = 0; x < image->width; x++)
        {
            OWFpixel* pixel;
            OWFsubpixel alpha;

            pixel = OWF_Image_GetPixelPtr(image, x, y);

            alpha = pixel->color.alpha;

            if (0 == alpha)
            {
                pixel->color.red =
                pixel->color.green =
                pixel->color.blue = 0;
            }
            else
            {
                pixel->color.red    = (pixel->color.red * alpha + OWF_PREMUL_ROUNDING_FACTOR) /
                                      OWF_ALPHA_MAX_VALUE;
                pixel->color.green  = (pixel->color.green * alpha + OWF_PREMUL_ROUNDING_FACTOR) /
                                      OWF_ALPHA_MAX_VALUE;
                pixel->color.blue   = (pixel->color.blue * alpha + OWF_PREMUL_ROUNDING_FACTOR) /
                                      OWF_ALPHA_MAX_VALUE;
            }
        }
    }

    image->format.premultiplied = OWF_TRUE;
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL void
OWF_Image_UnpremultiplyAlpha(OWF_IMAGE* image)
{
    OWFint       count;
    OWFpixel*    pixelPtr;

    //OWF_ASSERT(image != 0);

    if (!image->format.premultiplied)
    {
        return;
    }

    /* only for internal format */
    if (image->format.pixelFormat != OWF_IMAGE_ARGB_INTERNAL)
    {
        return;
    }

    count = image->width * image->height;
    pixelPtr = (OWFpixel*)image->data;

    while (count > 0)
    {

        OWFsubpixel a = pixelPtr->color.alpha;

#ifdef OWF_IMAGE_INTERNAL_PIXEL_IS_FLOAT
	      OWF_ASSERT(a <= OWF_ALPHA_MAX_VALUE && a >= OWF_ALPHA_MIN_VALUE);
#endif

        if (a > OWF_ALPHA_MIN_VALUE)
        {
            OWFsubpixel r = pixelPtr->color.red   * OWF_RED_MAX_VALUE / a;
            OWFsubpixel g = pixelPtr->color.green * OWF_GREEN_MAX_VALUE / a;
            OWFsubpixel b = pixelPtr->color.blue  * OWF_BLUE_MAX_VALUE / a;

            pixelPtr->color.red   = r;
            pixelPtr->color.green = g;
            pixelPtr->color.blue  = b;

            --count;
            pixelPtr++;
        }
    }

    image->format.premultiplied = OWF_TRUE;
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL void
OWF_Image_Rotate(OWF_IMAGE* dst,
                 OWF_IMAGE* src,
                 OWF_ROTATION rotation)
{
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
#endif
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL void
OWF_Image_Flip(OWF_IMAGE* image,
               OWF_FLIP_DIRECTION dir)
{
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
#endif
}

/*----------------------------------------------------------------------------*/
#define BLENDER_INNER_LOOP_BEGIN \
    OWFint rowCount = drect.height; \
    while (rowCount > 0) { \
        OWFint colCount = drect.width; \
        while (colCount > 0) { \
            if (!(blend->tsColor && COLOR_MATCH(SC, TSC))) \
            { \

#define BLENDER_INNER_LOOP_END \
                DA = blend->destinationFullyOpaque ? OWF_FULLY_OPAQUE : DA; \
            } /* end tsColor check */ \
            srcPtr ++; \
            dstPtr ++; \
            maskPtr++; \
            --colCount; \
        } \
        srcPtr += srcLineDelta; \
        dstPtr += dstLineDelta; \
        maskPtr += maskLineDelta; \
        --rowCount; \
    }

#define TSC blend->tsColor->color
#define SC srcPtr->color

/* Note: actually would be better to compare integer values
 * for TSC match -> eliminate float arithmetic pitfalls
 */
#define COLOR_MATCH(x, y) (x.red==y.red && x.green==y.green && x.blue==y.blue)

#define SA srcPtr->color.alpha
#define SR srcPtr->color.red
#define SG srcPtr->color.green
#define SB srcPtr->color.blue

#define DA dstPtr->color.alpha
#define DR dstPtr->color.red
#define DG dstPtr->color.green
#define DB dstPtr->color.blue

#define MA *maskPtr
#define GA blend->globalAlpha

OWF_API_CALL void
OWF_Image_Blend(OWF_BLEND_INFO* blend,
                OWF_TRANSPARENCY transparency)
{
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
#endif
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL void*
OWF_Image_AllocData(OWFint width, OWFint height, OWF_PIXEL_FORMAT pixelFormat)
{
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
#endif
    return NULL;
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL void
OWF_Image_FreeData(void** data)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL OWFint
OWF_Image_GetFormatPixelSize(OWF_PIXEL_FORMAT format)
{
    switch (format)
    {
        case OWF_IMAGE_ARGB_INTERNAL:
        {
            return sizeof(OWFpixel);
        }

        case OWF_IMAGE_ARGB8888:
        case OWF_IMAGE_XRGB8888:
        case OWF_IMAGE_L32:
        {
            return 4;
        }

        case OWF_IMAGE_RGB888: 
        case OWF_IMAGE_BGR888: 
        case OWF_IMAGE_ARGB6666:
        {
            return 3;
        }

        case OWF_IMAGE_RGB565:
        case OWF_IMAGE_L16:
        {
            return 2;
        }

        case OWF_IMAGE_L8:
        {
            return 1;
        }

        case OWF_IMAGE_L1:
        {
            /* Use negative numbers for divisor, e.g., -8 = 1/8. */
            /* L1 is 1 bit alpha, LSB->MSB, each row padded to 32-bit
             * boundary. */
            return -8;
        }
        case OWF_IMAGE_UYVY: 
        {
            return 2;
        }
        default:
        {
            return 0;
        }
    }

    //return 0;
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL OWFint
OWF_Image_GetFormatPadding(OWF_PIXEL_FORMAT format)
{
    OWFint                  padding = 1;

    switch (format)
    {
        case OWF_IMAGE_ARGB_INTERNAL:
        {
            padding = sizeof(OWFpixel);
            break;
        }

        case OWF_IMAGE_ARGB8888:
        case OWF_IMAGE_XRGB8888:
        case OWF_IMAGE_L32:
        {
            padding = 4;
            break;
        }

        /*
        case OWF_IMAGE_RGB888:
        {
            return 3;
        }
        */

        case OWF_IMAGE_RGB565:
        case OWF_IMAGE_L16:
        {
            padding = 2;
            break;
        }

        case OWF_IMAGE_L8:
        {
            padding = 1;
            break;
        }

        case OWF_IMAGE_L1:
        {
            /* Use negative numbers for divisor, e.g., -8 = 1/8. */
            /* L1 is 1 bit alpha, LSB->MSB, each row padded to 32-bit
             * boundary. */
            padding = 4;
            break;
        }
        case OWF_IMAGE_UYVY: 
        {
            padding = 4;
            break;
        }
        default:
        {
            break;
        }
    }

    //OWF_ASSERT(padding);

    return padding;
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL void
OWF_Image_SwapWidthAndHeight(OWF_IMAGE* image)
{
    /* swap w & h */
    image->width ^= image->height;
    image->height ^= image->width;
    image->width ^= image->height;

    image->stride = OWF_Image_GetStride(image->width, &image->format, 0);
}

/*----------------------------------------------------------------------------*/
OWF_API_CALL OWFboolean
OWF_Image_ConvertMask(OWF_IMAGE* output, OWF_IMAGE* input)
{
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
#endif
    return OWF_FALSE;
}


#ifdef __cplusplus
}
#endif
