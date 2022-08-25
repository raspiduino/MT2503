/** 
 *
 *	@file		IGV5Font.h	
 *
 *  @brief		Header file for bitmapped font definitions
 *
 *	@author		Code excerpt from ARM Mali sample
 *
*/

#ifndef __IGV5FONT_H
#define __IGV5FONT_H

#include "IGV5Texture.h"
#include "IGV5RuntimeContext.h"

#define FONT_WIDTH	8
#define FONT_HEIGHT	16

/* Bit experimental, allows drawing font chars bigger than the texture was.
 * Range 0.75..3.0 seems to work reasonably...
 */
#define FONT_SCALE	1.0f

#ifdef __cplusplus
extern "C" {
#endif

/*!***********************************************************************
 @fn		IGV5Font_Create
 @param		iWidth		width of pixels of viewport or display area
 @param		iHeight		height of pixels of viewport or display area
 @return	IGV5ERR_NONE if initalization is successful. 
 @brief		Initialize bitmapped font functionality
*************************************************************************/
IGV5Err IGV5Font_Create(int iWidth, int iHeight);


/*!***********************************************************************
 @fn		IGV5Font_ClearString
 @brief		Remove cached string and relative vertice data.
*************************************************************************/
void IGV5Font_ClearString(void);

/*!***********************************************************************
 @fn		IGV5Font_AddString
 @param		iStringX		pixel position of left corner of string
 @param		iStringY		pixel position of top corner of string 
 @param		pString			string to add into cache
 @brief		Add a string to cached string and prepare relative vertice data before rendering.
*************************************************************************/
void IGV5Font_AddString(IGV5RC *pThisRC, int iStringX, int iStringY, char *pString, int iR, int iG, int iB, int iA);


void IGV5Font_ReplaceString(IGV5RC *pThisRC, int iStringX, int iStringY, char *pString, int iR, int iG, int iB, int iA);
void IGV5Font_Draw(void);
void IGV5Font_Release(void);

void IGV5Font_DrawNum(IGV5RC *pThisRC, int iStringX, int iStringY, int iVal, DWORD dwColor);

//only suport 15 characters max! 
void IGV5Font_DrawTempString(IGV5RC *pThisRC, int iStringX, int iStringY, char *pStr, DWORD dwColor);

void IGV5Texture_Draw(IGV5RC *pThisRC, IGV5Texture *pTex, float iStringX, float iStringY, IGV5Rect *pSubRect, float fScaleX, float fScaleY, DWORD color);

void IGV5Texture_Draw2(IGV5RC *pThisRC, IGV5Texture *pTex, IGV5Texture *pAlphaTex, float iStringX, float iStringY, IGV5Rect *pSubRect, float fScaleX, float fScaleY, DWORD color);

#ifdef __cplusplus
}
#endif

#endif /* __font_h */

