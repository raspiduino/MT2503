#ifndef _mcfgdi_h_
#define _mcfgdi_h_

#include "McfCommon.h"

MColor McfGDI_GetTextColor(MVOID);

MINT McfGdi_SetTextColor(MBYTE nR, MBYTE nG, MBYTE nB);

MINT McfGdi_SetTextColor_Int(MColor rgb);

MColor McfGdi_MakeMColorFromRGB(MBYTE nR, MBYTE nG, MBYTE nB);

MINT McfGdi_GetRGBFromMColor(MBYTE *pR, MBYTE *pG, MBYTE *pB, MColor nColor);

MINT McfGdi_SetFont(MINT nFontSize, MINT nFontAttr);

MINT McfGdi_GetCharWidth(MVOID);

MINT  McfGdi_GetCharHeight(MVOID);

MINT  McfGdi_GetTextWidth(MWCHAR* pText);

MINT  McfGdi_GetNTextWidth(MWCHAR* pText,  MINT n);

MVOID McfGdi_GetTextWidthHeight(MWCHAR *pText,  MINT* pWidth, MINT* pHeight);

MVOID McfGdi_GetNTextWidthHeight(MWCHAR *pText,  MINT nCount, MINT* pWidth,  MINT* pHeight);

MINT McfGdi_DrawText(MINT nX,  MINT nY,  const MWCHAR* pcwszStr);

MINT  McfGdi_DrawTextN(MINT nX, MINT nY,  const MWCHAR* pcwszStr,  MINT nLen);

MVOID McfGdi_DrawPoint(MINT nX,  MINT nY,  MColor pixel_color);

MVOID McfGdi_DrawRect(MINT nX1,  MINT nY1, MINT nX2,  MINT nY2,MColor frame_color);

MVOID McfGdi_FillRect(MINT nX1,  MINT nY1, MINT nX2,  MINT nY2, MColor rect_color);

MVOID McfGdi_DrawFrameRect(MINT nX1,  MINT nY1, MINT nX2,  MINT nY2, MColor rect_color, MColor frame_color);

MVOID McfGdi_DrawLine(MINT nX1,  MINT nY1, MINT nX2,  MINT nY2, MColor line_color);

MINT McfGdi_GetScrWidth(MVOID);

MINT McfGdi_GetScrHeight(MVOID);

MVOID McfGdi_BeginDraw(MVOID);

MVOID McfGdi_EndDraw(MVOID);

MBYTE* McfGdi_GetBufferPtr(MVOID);

MColor McfGdi_GetPixel(MINT nX,  MINT nY);

MVOID McfGdi_PushClip(MVOID);

MVOID McfGdi_PopClip(MVOID);

MVOID McfGdi_SetClip(MINT nX1,  MINT nY1, MINT nX2,  MINT nY2);

MINT McfGdi_GetClip(MINT* pX, MINT* pY, MINT* pX2, MINT* pY2);

MVOID McfGdi_ResetClip(MVOID);

MINT McfGdi_DrawImage(MINT nX,  MINT nY, const MBYTE* pImgData, MUINT nDataSize);

MINT McfGdi_GetImageInfo(const MBYTE* pImageData,  MUINT nDataSize, MImageInfo* pMImageInfo);

MVOID McfGdi_DisplayWarnning(MWCHAR *pMessage);

MVOID McfGdi_DisplayPopUp(MWCHAR *pMessage, MINT nTime);

MVOID McfGdi_StopDisplayPopUp(MVOID);

MBOOL McfGdi_IsTouchScreen(MVOID);


#endif //_MCR_GDI_H
