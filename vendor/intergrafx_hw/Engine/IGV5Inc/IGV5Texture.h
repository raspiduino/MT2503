/*!
	@file IGV5Texture.h 

	@brief  header file for texture stuff

*/

#ifndef __IGV5TEXTURE_H
#define __IGV5TEXTURE_H

#include "IGV5Def.h"

#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!< if this texture is used as RenderTarget, set this bit flag in m_uUsage */
#define IGV5TU_RENDERTARGET 0x00000001

/*!< if you want IGV5Texture to keep a copy of loaded raw texture image (for quick reload, for example) */
#define IGV5TU_MANAGED 0x00000010

/*!< if you want IGV5Texture to free m_pPixels by itself (calling IGV5Memory_Free() ) unless it's NULL */
#define IGV5TU_ALLOCATED 0x000000020

/*!< if this texture is compressed, enable this flag */
#define IGV5TU_COMPRESSED 0x00000040

/*!< if this texture is cube map, automatically enable this flag */
#define IGV5TU_CUBEMAP 0x00000080

#define IGV5IMGFMT_UNKNOWN 0x00000000
#define IGV5IMGFMT_RGBA8888 0x00000001
#define IGV5IMGFMT_RGB888 0x00000002
#define IGV5IMGFMT_RGBA4444 0x00000003
#define IGV5IMGFMT_RGBA5551 0x00000004
#define IGV5IMGFMT_A8   0x00000005

/* Texture settings: filter */
#define IGV5TEXFILTER_LINEAR 0x0000010
#define IGV5TEXFILTER_NEAREST 0x0000001

/* Texture settings: tile and wrapping */
#define IGV5TEXWRAP_CLAMP 0x00010000
#define IGV5TEXWRAP_WRAP 0x00100000

/*!****************************************************************************
 @Struct      IGV5Texture
 @brief       Struct for texture object
******************************************************************************/
typedef struct {

	char m_sName[32];				/*!< tetxure name without path information */

	BYTE8 m_uStage;					/*!< OpenGL ES texture stage, default is 0 */
	BYTE8 m_uPixelSize;				/*!< size of pixel, in bytes */
	
	BYTE8 m_uFilter;				/*!< OpenGL ES texture filtering parameters */
	BYTE8 m_uWrapping;				/*!< OpenGL ES texture wrapping parameters */
	
	unsigned m_uUsage;				/*!< enumeration of usage bitflags */
	unsigned m_uFormat;				/*!< enumeration of pixel format */
	unsigned m_uWidth;				/*!< width of level 0 texture */
	unsigned m_uHeight;				/*!< height of level 0 texture */
	unsigned m_uPitch;				/*!< pitch of level 0 texture, in bytes */

	unsigned m_uDataLength;			/*!< data length, in bytes */
	BYTE8 *m_pPixels;				/*!< source pixels */

	unsigned m_uDeviceID;			/*!< OpenGL ES texture ID */
	

} IGV5Texture;

/*!****************************************************************************
 @Struct      ETCHeader
 @brief       Struct for texture object
******************************************************************************/
typedef struct {
	char	aName[6];
	unsigned short iBlank;
	/* NB: Beware endianess issues here. */
	unsigned char iPaddedWidthMSB;
	unsigned char iPaddedWidthLSB;
	unsigned char iPaddedHeightMSB;
	unsigned char iPaddedHeightLSB;
	unsigned char iWidthMSB;
	unsigned char iWidthLSB;
	unsigned char iHeightMSB;
	unsigned char iHeightLSB;
} ETCHeader;

/*!***************************************************************************
 @fn			IGV5Texture_SetName
 @param			pTex			Pointer to texture object
 @param			pName			texture name string
 @Return		IGV5ERR_NONE if successful
 @brief			Assign texture name, maximum 31 characters
*****************************************************************************/
IGV5Err IGV5Texture_SetName(IGV5Texture *pTex, char *pName);

/*!***************************************************************************
 @fn			IGV5Texture_SetStage
 @param			pTex			Pointer to texture object
 @param				stage			texture stage to enable
 @Return			IGV5_TRUE if successful
 @brief		Assign and enable texture stage
*****************************************************************************/
IGV5Err IGV5Texture_SetStage(IGV5Texture *pTex, unsigned stage);

/*!***************************************************************************
 @fn			IGV5Texture_SetFormat
 @param			pTex			Pointer to texture object
 @param				uFormat			pixel format constant
 @Return			IGV5_TRUE if successful
 @brief		Assign texel format and calculate necessary information
*****************************************************************************/
IGV5Err IGV5Texture_SetFormat(IGV5Texture *pTex, unsigned uFormat);

/*!***************************************************************************
 @fn			IGV5Texture_SetFilter
 @param			pTex			Pointer to texture object
 @param			filter			filtering algorithm
 @Return		IGV5_TRUE if successful
 @brief			Assign filter algorithm 
*****************************************************************************/
IGV5Err IGV5Texture_SetFilter(IGV5Texture *pTex, unsigned filter);
IGV5Err IGV5Texture_SetWrapping(IGV5Texture *pTex, unsigned wrapping);

/*!***************************************************************************
 @fn			IGV5Texture_Download
 @param			pTex				Pointer to texture object
 @param			pAlternativePixels	Assign an user specified pixel array other than default texture
 @Return		IGV5_TRUE if successful
 @brief			Upload pixel data into HW 
*****************************************************************************/
IGV5Err IGV5Texture_Download(IGV5Texture *pTex, BYTE8 *pAlternativePixels);


/*!***************************************************************************
 @fn			IGV5Texture_CreateFromPixels
 @param			pTex			Pointer to texture object
 @param				uWidth			width of texture
 @param				uHeight			height of texture
 @param				uFormat			format of pixel map
 @Return			IGV5_TRUE if successful
 @brief		Create a texture from memory pixel buffer
*****************************************************************************/
IGV5Err IGV5Texture_CreateFromPixels(IGV5Texture *pTex, unsigned uWidth, unsigned uHeight, unsigned uFormat, unsigned usage, unsigned stage, unsigned filter, unsigned wrapping, BYTE8 *pSrcBits);

IGV5Err IGV5Texture_Create(GLuint *ipTex, char *pTexBits, unsigned w, unsigned h);
void IGV5Texture_Release(IGV5Texture *pTex);

/*unsigned short getWidth(ETCHeader *pHeader);
unsigned short getHeight(ETCHeader *pHeader);
unsigned short getPaddedWidth(ETCHeader *pHeader);
unsigned short getPaddedHeight(ETCHeader *pHeader); */

IGV5Err IGV5Texture_CreateTGAFromFile(IGV5Texture *pTex, unsigned usage, unsigned stage, unsigned filter, unsigned wrapping,char *pFile);
IGV5Err IGV5Texture_CreateTGAFromMem(IGV5Texture *pTex, unsigned usage, unsigned stage, unsigned filter, unsigned wrapping, char *pMemFile);

IGV5Err IGV5Texture_CreateDefault(void);
void IGV5Texture_ReleaseDefault(void);

/*!***************************************************************************
 @fn			IGV5Texture_Set
 @param			pTex			Pointer to texture object
 @param			stage			texture stage to be set
 @brief			Activate a texture for specified stage
*****************************************************************************/
void IGV5Texture_Set(IGV5Texture *pTex, unsigned stage);

/*!***************************************************************************
 @fn			IGV5Texture_SetBlankNormalMap
 @param			stage			texture stage to be set
 @brief			Activate a blank normal map texture for specified stage
*****************************************************************************/
void IGV5Texture_SetBlankNormalMap(unsigned stage);

/*!****************************************************************************
 @fn		IGV5Texture_GenerateNormalisationCubeMap
 @param			uiTextureSize		The size of the cube map's textures
 @brief		Generates a normalization cube map for the shaders to use
******************************************************************************/
IGV5Err IGV5Texture_GenerateNormalisationCubeMap(IGV5Texture *pCubeTex, int uiTextureSize);


#ifdef __cplusplus
}
#endif


#endif /* __IGV5TEXTURE_H */


