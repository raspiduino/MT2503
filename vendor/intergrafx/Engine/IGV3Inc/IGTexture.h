/**
@file IGTexture.h 
@brief 

@par Last updated:


@par Copyright (c) 2005 InterGrafx, Inc. All rights reserved.
InterGrafx CONFIDENTIAL AND PROPRIETARY
@par
This source is the sole property of InterGrafx Inc. Reproduction or
Utilization of this source in whole or in part is forbidden without
The written consent of InterGrafx Inc.

@par History:


@par Description:
more description here.
*/
#ifndef IG_TEXTURE_H
#define IG_TEXTURE_H

#include "IGComDef.h"
#include "IGInputStream.h"
#include "IGMemoryPool.h"

/*--------------------------------------------------------------------*\
|   IGTexture object struct
\*--------------------------------------------------------------------*/


typedef struct _IGColorFormatRec
{
    iguint32 m_rHigh;
    iguint32 m_gHigh;
    iguint32 m_bHigh;

    iguint32 m_rMask;
    iguint32 m_gMask;
    iguint32 m_bMask;

    iguint32 m_rHiMask;
    iguint32 m_gHiMask;
    iguint32 m_bHiMask;

}  IGColorFormat;

typedef struct _IGTextureRec
{
    igbool          m_keyColorEnabled;
    igcolor         m_keyColor;
    iguint32        m_uMask;
    iguint32        m_vMask;
	iguint8*        m_texelsa;
    igcolor*        m_texels;
    iguint32        m_width;
    iguint32        m_height;
    iguint32        m_uBits;
    iguint32        m_vBits;
	IGColorFormat   m_colorFormat;
    char            m_name[ IG_NAMELEN+1 ];    
}  IGTexture;


#ifdef __cplusplus
extern "C"
{
#endif

/*--------------------------------------------------------------------*\
|   IGTexture public interface
\*--------------------------------------------------------------------*/
/**
IGTexture constructor.
Allocates a new IGTexture with the specified associated image.
@param pMemPool
  Pointer to the memory pool where engine data is stored
@param iTexName
  Initial name of IGTexture; will be internally unique up to only
  @a MAXNAMELEN characters
@param iTexels
  Buffer whose first @a width * @a height elements contain image pixel data
  in X888 RGB format; scanlines are in top-down left-right order (each
  scanline's pixels are in left-right order and the first scanline is at the
  top of the image)
@param iWidth
  Width of the IGTexture image
@param iHeight
  Height of the IGTexture image
@param iRMask
  Color with all red bits set and all other bits cleared.
@param iGMask
  Color with all green bits set and all other bits cleared.
@param iBMask
  Color with all blue bits set and all other bits cleared.
@param pErr
  Stores error code raised by this function
@return
  Handle to newly created IGTexture; NULL if creation failed
@par Example:
@note
  The IGTexture allocates its own internal storage for the pixel data; it is
  the caller's responsibility to handle (e.g. dispose of) the argument
  buffer.
@code
  // pMemPool points to a previously allocated IGMemoryPool.
  // Color mask values are dependent on color format of the target device.
  // Red stripe, green stripe, blue stripe.
  iguint32 const akImage[] = {
    0xFF0000, 0xFF0000, 0xFF0000,
    0x00FF00, 0x00FF00, 0x00FF00,
    0x0000FF, 0x0000FF, 0x0000FF
  };

  IGTexture* hTex = IGTexture_new(pMemPool, "myTexture", akImage, 3L, 3L, 0xF00, 0xF0, 0xF, pErr);

  if (hTex) {
    ...
  }
@endcode
@see IGTexture_destroy
@see IGTexture_newFromByteArray
@see IGTexture_newFromFile
*/
IGTexture*      IGTexture_new       ( IGMemoryPool*         pMemPool, 
                                      const char*           iTexName, 
                                      const unsigned long*  iTexels, 
                                      unsigned long         iWidth, 
                                      unsigned long         iHeight,
                                      igcolor               iRMask, 
                                      igcolor               iGMask, 
                                      igcolor               iBMask, 
                                      IGErr*                pErr );

/**
* Creates an IGTexture in memory from a bitmap data array.
* Supported bmp formats are 1-, 4-, and 8-bit palettized (no RLE) and 24-bit
* absolute.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iStream
*   Array containing bitmap data
* @param iTexName
*   Initial name of IGTexture; will be internally unique up to only
*   @a MAXNAMELEN characters
* @param iRMask
*   Color with all red bits set and all other bits cleared.
* @param iGMask
*   Color with all green bits set and all other bits cleared.
* @param iBMask
*   Color with all blue bits set and all other bits cleared.
* @param pErr
*   Stores error code raised by this function
* @return
*   Handle to newly created IGTexture; NULL if creation failed
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // Color mask values are dependent on color format of the target device.
*   IGTexture* hTex = IGTexture_newFromByteArray(pMemPool, aMyBitmapData, "myTexture", 0xF00, 0xF0, 0xF, pErr);
* @endcode
* @see IGTexture_new
* @see IGTexture_newFromFile
* @see IGTexture_destroy
*/
IGTexture*      IGTexture_newFromByteArray
                                    ( IGMemoryPool*         pMemPool, 
                                      const unsigned char*  iByteArray, 
                                      const char*           iTexName, 
                                      igcolor               iRMask, 
                                      igcolor               iGMask, 
                                      igcolor               iBMask, 
                                      IGErr*                pErr );
    
IGTexture*      IGTexture_newFromFile
                                    ( IGMemoryPool*         pMemPool, 
                                      const char*           iFilename, 
                                      igcolor               iRMask, 
                                      igcolor               iGMask, 
                                      igcolor               iBMask, 
                                      IGErr*                pErr );
    
/**
* IGTexture destructor.
* Deallocates an IGTexture.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iTex
*   Handle to the IGTexture
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hTex references a previously allocated IGTexture.
*   if (hTex) {
*     IGTexture_destroy(pMemPool, hTex, pErr);
*   }
* @endcode
* @see IGTexture_new
*/
void            IGTexture_destroy   ( IGMemoryPool*         pMemPool, 
                                      IGTexture*            iTex, 
                                      IGErr*                pErr );
/**
* Converts a canonical X888 color to the color format of a given texture.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iTex
*  Texture whose color format we are converting to.
* @param i888Color
*   Canonical color
* @param pErr
*   Stores error code raised by this function
* @return
*   Device color corresponding to @a x888Color
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hTex references a previously allocated IGTexture.
*   // Get device representation of green.
*   igcolor devColor = IGTexture_getDeviceColor(pMemPool, hTex, 0x00FF00, pErr);
* @endcode
*/
igcolor         IGTexture_getDeviceColor
                                    ( IGMemoryPool*         pMemPool, 
                                      IGTexture*            iTex, 
                                      unsigned long         i888Color, 
                                      IGErr*                pErr );

unsigned long   IGTexture_getHeight ( IGMemoryPool*         pMemPool, 
                                      IGTexture*            iTex, 
                                      IGErr*                pErr );

unsigned long   IGTexture_getWidth  ( IGMemoryPool*         pMemPool, 
                                      IGTexture*            iTex, 
                                      IGErr*                pErr );


/**
* Sets the transparent key color of an IGTexture.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iTex
*   Handle to the IGTexture
* @param iColor
*   Key color; pixels of this color will not be drawn by the rasterizer
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // Set green pixels to be dropped.
*
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hTex references a previously allocated IGTexture.
*   igcolor greenColor = IGTexture_getDeviceColor(pMemPool, hTex, 0x00FF00, pErr)
*   IGTexture_setKeyColor(pMemPool, hTex, greenColor, pErr);
* @endcode
*/
void            IGTexture_setKeyColor
                                    ( IGMemoryPool*         pMemPool, 
                                      IGTexture*            iTex, 
                                      igcolor               iColor, 
                                      IGErr*                pErr );
igcolor         IGTexture_getKeyColor
                                    ( IGMemoryPool*         pMemPool, 
                                      IGTexture*            iTex, 
                                      IGErr*                pErr );

/**
* Enables or disables key-color transparency in an IGTexture.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iTex
*   Handle to the IGTexture
* @param iEnable
*   Whether or not to enable key-color transparency
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // Enable key color.
*
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hTex references a previously allocated IGTexture.
*   IGTexture_setKeyColorEnabled(pMemPool, hTex, IGBOOL_TRUE, pErr);
* @endcode
*/
void            IGTexture_setKeyColorEnabled
                                    ( IGMemoryPool*         pMemPool, 
                                      IGTexture*            iTex, 
                                      igbool                iEnable, 
                                      IGErr*                pErr );

igbool          IGTexture_getKeyColorEnabled
                                    ( IGMemoryPool*         pMemPool, 
                                      IGTexture*            iTex, 
                                      IGErr*                pErr );
/**
* Gets an IGTexture's name.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iTex
*   Handle to the IGTexture
* @param oTexName
*   The IGTexture's name is written to this buffer; must have a capacity of at
*   least @a MAXNAMELEN + 1 characters (to accommodate the null terminator)
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   char aNameDest[MAXNAMELEN + 1];
*
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hTex references a previously allocated IGTexture.
*   IGTexture_getName(pMemPool, hTex, aNameDest, pErr);
*
*   // aNameDest now contains the IGTexture's name.
* @endcode
* @see IGTexture_setName
* @see MAXNAMELEN
*/
void            IGTexture_getName   ( IGMemoryPool*         pMemPool, 
                                      IGTexture*            iTex, 
                                      char*                 oTexName, 
                                      IGErr*                pErr );
/**
* Sets an IGTexture's name.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iTex
*   Handle to the IGTexture
* @param iTexName
*   Name to set; will only be internally unique up to @a MAXNAMELEN characters
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hTex references a previously allocated IGTexture.
*   IGTexture_setName(pMemPool, hTex, "myTexture", pErr);
* @endcode
* @see IGTexture_getName
* @see MAXNAMELEN
*/
void            IGTexture_setName   ( IGMemoryPool*         pMemPool, 
                                      IGTexture*            iTex, 
                                      const char*           iTexName, 
                                      IGErr*                pErr );
/**
* Returns a pointer to an IGTexture's pixel array (the texture's m_pPixels field).
* @param pMemPool
*   Pointer to the memory pool where engine data is stored.
* @param iTex
*   Handle to the IGTexture.
* @param pErr
*   Stores error code raised by this function.
* @return
*   Pointer to the pixel array of the texture.
* @par Example:
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hTex references a previously allocated IGTexture.
*   igcolor* c = IGTexture_getPixelArray(pMemPool, hTex, pErr);
* @endcode
*/
igcolor*        IGTexture_getPixelArray
                                    ( IGMemoryPool*         pMemPool, 
                                      IGTexture*            iTex, 
                                      IGErr*                pErr );
/**
* Gets the color of one of the texels in an IGTexture.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iTex
*   Handle to the IGTexture.
* @param iU
*   Horizontal index of the texel to get the color of
* @param iV
*   Vertical index of the texel to get the color of
* @param pErr
*   Stores error code raised by this function
* @return
*   The color of that texel
* @code
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hTex references a previously allocated IGTexture.
*   igcolor c = IGTexture_getTexelColor(pMemPool, hTex, 50L, 50L, pErr);
* @endcode
*/
igcolor         IGTexture_getTexelColor
                                    ( IGMemoryPool*         pMemPool, 
                                      IGTexture*            iTex, 
                                      long                  iU, 
                                      long                  iV, 
                                      IGErr*                pErr );
/**
* Sets the color of one of the texels in an IGTexture.
* @param pMemPool
*   Pointer to the memory pool where engine data is stored
* @param iTex
*   Handle to the IGTexture
* @param iU
*   Horizontal index of the texel to set
* @param iV
*   Vertical index of the texel to set
* @param iColor
*   The color to set the texel to
* @param pErr
*   Stores error code raised by this function
* @return
*   void
* @par Example:
* @code
*   // Set pixel (50, 50) to red.
*
*   // pMemPool points to a previously allocated IGMemoryPool.
*   // hTex references a previously allocated IGTexture.
*   igcolor redColor = IGTexture_getDeviceColor(pMemPool, hTex, 0xFF0000, pErr)
*   IGTexture_setTexelColor(pMemPool, hTex, 50L, 50L, redColor, pErr);
* @endcode
*/
void            IGTexture_setTexelColor
                                    ( IGMemoryPool*         pMemPool, 
                                      IGTexture*            iTex, 
                                      long                  iU, 
                                      long                  iV, 
                                      igcolor               iColor, 
                                      IGErr*                pErr );


#ifdef __cplusplus
}
#endif

#endif//IG_TEXTURE_H

