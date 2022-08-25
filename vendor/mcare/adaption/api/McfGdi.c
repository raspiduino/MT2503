#ifdef __MCAREV31__
#ifndef _TENCENT_MCARE_ADP_
#define _TENCENT_MCARE_ADP_
#endif
#include "MAdpConfig.h"
#include "McfMisc.h"
#include "McfGdi.h"
#include "McfPlatform.h"
#include "McfTrace.h"

typedef struct  
{
	MBYTE		m_nBold;
	MBYTE		m_nItalic;
	MBYTE		m_nUnderline;
	MBYTE		m_nSize;
	MBYTE		m_nColor;
	MBYTE		m_nType;
	MBYTE		m_nOblique;
	MBYTE		m_nSmallCaps;
}McfFont;

extern const MBYTE MADP_SMALL_FONT;
extern const MBYTE MADP_MEDIUM_FONT;
extern const MBYTE MADP_LARGE_FONT;
extern const MBYTE MADP_GRADIENT_RECT_HOR;
extern const MBYTE MADP_GRADIENT_RECT_VER;

extern MVOID McfGuiMeasureString(const MWCHAR *pcwszStr,MINT len,MINT *pWidth,MINT *pHeight);
extern MVOID McfGuiPrintText(MINT x,MINT y,const MWCHAR*pcwszStr,MINT len);
extern MVOID McfGetCurrTextColor(MBYTE *pR, MBYTE *pG, MBYTE *pB);
extern MVOID McfSetTextColor( MBYTE r, MBYTE g, MBYTE b);
extern MVOID McfGuiSetFont(MBYTE fontSize,MBYTE bold,MBYTE italic,MBYTE underline);


#define  GDILOGENTERFUNC()  MCFAPI_GDI_PRINT(ALOG_INFO,MLOG_SDKGDI,"Enter"__MCR_FUNCTION__)
#define  GDILOGLEAVEFUNC()  MCFAPI_GDI_PRINT(ALOG_INFO,MLOG_SDKGDI,"Leave"__MCR_FUNCTION__)


#define RGB_TO_MCOLOR(a,r,g,b) 	((((a) & 0xff)<<24)|(((r) & 0xff)<<16)|(((g) & 0xff)<<8)|((b) & 0xff))
#define MCOLOR_A(mColor)   ((mColor)>>24)
#define MCOLOR_R(mColor)   ((mColor & 0x00ff0000)>>16 )
#define MCOLOR_G(mColor)   ((mColor & 0x0000ff00)>>8)
#define MCOLOR_B(mColor)   ((mColor & 0x000000ff))



//增加接口
MColor McfGDI_GetTextColor(MVOID)
{
	MColor mColor;
	MBYTE r = 0;
	MBYTE g = 0;
	MBYTE b = 0;

	GDILOGENTERFUNC();

	McfGetCurrTextColor(&r, &g, &b);
	mColor = gdi_act_color_from_rgb(255, r, g, b);

	GDILOGLEAVEFUNC();
	return mColor;
}


MINT McfGdi_SetTextColor(MBYTE r, MBYTE g, MBYTE b)
{
	MINT nRet = MGDI_SUCCESS;

	GDILOGENTERFUNC();

	McfSetTextColor(r,g,b); 

	GDILOGLEAVEFUNC();
	return nRet;
}

//更换类型MINT ==> MColor
MINT McfGdi_SetTextColor_Int(MColor rgb)
{
	MINT nRet = MGDI_SUCCESS;
	MUINT alpha,r,g,b;
	GDILOGENTERFUNC();

	gdi_act_color_to_rgb(&alpha, &r, &g, &b, rgb);
	McfSetTextColor(r,g,b);

	GDILOGLEAVEFUNC();
	return nRet;
}


MColor McfGdi_MakeMColorFromRGB(MBYTE r,  MBYTE g,  MBYTE b)
{
	MColor nRet = MGDI_SUCCESS;
	GDILOGENTERFUNC();

	nRet = gdi_act_color_from_rgb(255, r, g, b);

	GDILOGLEAVEFUNC();
	return nRet;
}

//新增API
MINT McfGdi_GetRGBFromMColor(MBYTE *pR, MBYTE *pG, MBYTE *pB, MColor nColor)
{
	MColor nRet = MGDI_SUCCESS;
	MUINT alpha = 0;

	MUINT r = 0;
	MUINT g = 0;
	MUINT b = 0;

	GDILOGENTERFUNC();
	gdi_act_color_to_rgb(&alpha, &r, &g, &b, nColor);

	*pR = r;
	*pG = g;
	*pB = b;

	GDILOGLEAVEFUNC();
	return nRet;
}


MINT McfGdi_SetFont(MINT nFontSize, MINT nFontAttr)
{
	MINT nRet = MGDI_SUCCESS;
	McfFont mcrFont = {0};

	GDILOGENTERFUNC();

	mcrFont.m_nBold = MFALSE;
	mcrFont.m_nColor = 0;
	mcrFont.m_nItalic = MFALSE;
	mcrFont.m_nOblique = MFALSE;
	mcrFont.m_nSmallCaps = MFALSE;
	mcrFont.m_nType = 1;
	mcrFont.m_nUnderline = MFALSE;

	switch (nFontSize)
	{
	case MGDI_FONTSIZE_SMALL:
		{
			mcrFont.m_nSize = (MBYTE)MADP_SMALL_FONT;
			break;
		}
	case MGDI_FONTSIZE_MEDIUM:
		{
			mcrFont.m_nSize = (MBYTE)MADP_MEDIUM_FONT;
			break;
		}
	case MGDI_FONTSIZE_LARGE:
		{
			mcrFont.m_nSize = (MBYTE)MADP_LARGE_FONT;
			break;
		}
	default:
		{
			mcrFont.m_nSize = (MBYTE)MADP_MEDIUM_FONT;
			break;
		}
	}

	if (nFontAttr & MGDI_FONTATTR_BOLD)
	{
		mcrFont.m_nBold = MTRUE;
	}

	if (nFontAttr & MGDI_FONTATTR_ITALIC)
	{
		mcrFont.m_nItalic = MTRUE;
	}

	if (nFontAttr & MGDI_FONTATTR_UNDERLINE)
	{
		mcrFont.m_nUnderline = MTRUE;
	}

	McfGuiSetFont(mcrFont.m_nSize,mcrFont.m_nBold,mcrFont.m_nItalic,mcrFont.m_nUnderline);

	GDILOGLEAVEFUNC();
	return nRet;
}


MINT  McfGdi_GetTextWidth( MWCHAR* pText)
{
	MINT nRet = MGDI_SUCCESS;
	MINT nHeight = 0;
	GDILOGENTERFUNC();
	if (pText)
	{
		McfGuiMeasureString(pText,McfStdC_wcslen(pText), &nRet, &nHeight);
	}
	else
	{
		nRet = MGDI_PARAM_ERR;
	}

	GDILOGLEAVEFUNC();
	return nRet;
}


MINT  McfGdi_GetNTextWidth(MWCHAR* pText,  MINT n)
{
	MINT nRet = MGDI_SUCCESS;
	MINT nHeight = 0;
	GDILOGENTERFUNC();
	if (pText)
	{
		//ret = gui_get_string_width_n(pText,n); 
		McfGuiMeasureString(pText, n, &nRet, &nHeight);
	}
	else
	{
		nRet = MGDI_PARAM_ERR;
	}

	GDILOGLEAVEFUNC();
	return nRet;
}


MVOID McfGdi_GetTextWidthHeight( MWCHAR *pText,  MINT* pWidth, MINT* pHeight)
{
	GDILOGENTERFUNC();
	if (pText && pWidth && pHeight)
	{
		McfGuiMeasureString(pText,McfStdC_wcslen( pText),pWidth,pHeight);
	}
	GDILOGLEAVEFUNC();
}

MVOID McfGdi_GetNTextWidthHeight( MWCHAR *pText,  MINT nCount, MINT* pWidth,  MINT* pHeight)
{
	GDILOGENTERFUNC();
	if (pText && pWidth && pHeight)
	{
		McfGuiMeasureString(pText, nCount, pWidth,pHeight);
	}
	GDILOGLEAVEFUNC();
}

MINT McfGdi_DrawText( MINT nX,  MINT nY, const MWCHAR* pcwszStr)
{
	MINT nRet = MGDI_SUCCESS;
	MINT nLen =McfStdC_wcslen(pcwszStr);
	GDILOGENTERFUNC();
	if (pcwszStr)
	{
		McfGuiPrintText(nX, nY, pcwszStr,nLen);
	}
	else
	{
		nRet = MGDI_PARAM_ERR;
	}

	GDILOGLEAVEFUNC();
	return nRet;
}


MINT  McfGdi_DrawTextN( MINT nX, MINT nY, const MWCHAR* pcwszStr, MINT nLen)
{
	MINT nRet = MGDI_SUCCESS;
	GDILOGENTERFUNC();
	if (pcwszStr)
	{
		McfGuiPrintText(nX, nY, pcwszStr,nLen);
	}
	else
	{
		nRet = MGDI_PARAM_ERR;
	}

	GDILOGLEAVEFUNC();
	return nRet;
}



MVOID McfGdi_DrawPoint( MINT nX,  MINT nY,  MColor nPixelColor)
{
	GDILOGENTERFUNC();
	gdi_draw_point(nX, nY, nPixelColor);
	GDILOGLEAVEFUNC();
}


MVOID McfGdi_DrawRect( MINT nX1,  MINT nY1, MINT nX2,  MINT nY2, MColor nFrameColor)
{
	GDILOGENTERFUNC();
	gdi_draw_rect(nX1, nY1, nX2, nY2, nFrameColor);
	GDILOGLEAVEFUNC();
}

MVOID McfGdi_FillRect( MINT nX1,  MINT nY1,  MINT nX2,  MINT nY2,  MColor nRectColor)
{
	GDILOGENTERFUNC();
	gdi_draw_solid_rect(nX1, nY1, nX2, nY2, nRectColor);
	GDILOGLEAVEFUNC();
}

MVOID McfGdi_DrawFrameRect( MINT nX1,  MINT nY1,  MINT nX2, MINT nY2, MColor nRectColor, MColor nFrameColor)
{
	GDILOGENTERFUNC();
	gdi_draw_frame_rect(nX1, nY1, nX2, nY2, nRectColor, nFrameColor, 1);
	GDILOGLEAVEFUNC();
}


/*
MVOID McfGdi_FillGradRect( MINT nX1,  MINT nY1,  MINT nX2, MINT nY2,  MColor nStartColor,  MColor nEndColor)
{
	GDILOGENTERFUNC();
	gdi_draw_gradient_rect(nX1, nY1, nX2, nY2, nStartColor, nEndColor, 0, 0, MADP_GRADIENT_RECT_HOR);
	GDILOGLEAVEFUNC();
}

MVOID McfGdi_FillVGradRect(MINT nX1,  MINT nY1,  MINT nX2, MINT nY2,  MColor nStartColor, MColor nEndColor)
{
	GDILOGENTERFUNC();
	gdi_draw_gradient_rect(nX1, nY1, nX2, nY2, nStartColor, nEndColor, 0, 0, MADP_GRADIENT_RECT_VER);
	GDILOGLEAVEFUNC();
}*/

MVOID McfGdi_DrawLine(MINT nX1,  MINT nY1,  MINT nX2, MINT nY2,  MColor nLineColor)
{
	GDILOGENTERFUNC();
	gdi_draw_line(nX1, nY1, nX2, nY2, nLineColor);
	GDILOGLEAVEFUNC();
}


MBYTE* McfGdi_GetBufferPtr(MVOID)
{
	MBYTE* pBuffer = MNULL;
	GDILOGENTERFUNC();
	gdi_layer_get_buffer_ptr(&pBuffer);
	GDILOGLEAVEFUNC();
	return pBuffer;
}

MColor McfGdi_GetPixel(MINT nX, MINT nY)
{
	MColor nRet = 0;

	GDILOGENTERFUNC();
	nRet = gdi_act_get_pixel(nX, nY);

	GDILOGLEAVEFUNC();
	return nRet;
}

MVOID McfGdi_PushClip(MVOID)
{
	GDILOGENTERFUNC();
	gdi_layer_push_clip();
	GDILOGLEAVEFUNC();
}

MVOID McfGdi_PopClip(MVOID)
{
	GDILOGENTERFUNC();
	gdi_layer_pop_clip();
	GDILOGLEAVEFUNC();
}

MVOID McfGdi_SetClip(MINT nX1, MINT nY1, MINT nX2, MINT nY2)
{
	GDILOGENTERFUNC();
	gdi_layer_set_clip(nX1, nY1, nX2, nY2);
	GDILOGLEAVEFUNC();
}

MINT McfGdi_GetClip(MINT* pX1, MINT* pY1, MINT* pX2, MINT* pY2)
{
	MINT nRet = MGDI_SUCCESS;
	GDILOGENTERFUNC();

	if (pX1 && pY1 && pX2 && pY2)
	{
		gdi_layer_get_clip(pX1, pY1, pX2, pY2);
	}
	else
	{
		nRet = MGDI_PARAM_ERR;
	}

	GDILOGLEAVEFUNC();
	return nRet;

}


MVOID McfGdi_ResetClip(MVOID)
{
	gdi_layer_reset_clip();
}


//////////////////////////////////////////////////////////////////////////
static MULONG __GetULong_B(MBYTE* pData)
{
	MULONG nTmp;
	if(pData==0)
	{
		return 0;
	}
	nTmp = 0;
	nTmp += pData[3]; nTmp = nTmp<<8; 
	nTmp += pData[2]; nTmp = nTmp<<8; 
	nTmp += pData[1]; nTmp = nTmp<<8; 
	nTmp += pData[0]; 

	return nTmp;
}

static MUSHORT __GetUShort_B(MBYTE* pData)
{
	MUSHORT nTmp;
	if(pData==0)
	{
		return 0;
	}
	nTmp = 0;
	nTmp += pData[1]; nTmp = nTmp<<8; 
	nTmp += pData[0]; 
	return nTmp;
}

static MULONG __GetULong_L(MBYTE* pData)
{
	MULONG nTmp;
	if(pData==0)
	{
		return 0;
	}
	nTmp = 0;
	nTmp += pData[0]; nTmp = nTmp<<8; 
	nTmp += pData[1]; nTmp = nTmp<<8; 
	nTmp += pData[2]; nTmp = nTmp<<8; 
	nTmp += pData[3]; 

	return nTmp;
}
/*
/ ************************************************************************ /
/ * 	MCF_IMG_ERR = 0x0,
MCF_IMG_BMP,
MCF_IMG_PNG,
MCF_IMG_GIF,
MCF_IMG_JPG,
MCF_IMG_TIF                                                                     * /
/ ************************************************************************ /*/

static MINT __helper_getsize(MBYTE* pData, MINT nSize, MUINT* pWidth, MUINT* pHeight) 
{
	MINT type;
	MINT w, h, i;
	MULONG tmp;
	//IShell*pIShell;
	//pIShell=(IShell*)QGetIShell();
	type = MGDI_IMG_ERR;
	w = h = 0;
	if(pData==0 || nSize < 4) 
	{
		return MGDI_IMG_ERR;
	}

	if(pData[0] == 'B' && pData[1] == 'M')
	{  //bmp 
		if(nSize<54)
		{
			return MGDI_IMG_ERR;
		}

		if(pWidth==0&&pHeight==0)
		{
			return MGDI_IMG_BMP;			
		}

		if(pWidth!=0)
		{
			*pWidth = (MUINT)__GetULong_B(&pData[18]);
		}
		if(pHeight!=0)
		{
			*pHeight = (MUINT)__GetULong_B(&pData[22]);
		}
		return MGDI_IMG_BMP;
	} 
	else if(pData[0]==0x89&&pData[1]==0x50&&pData[2]==0x4E&&pData[3]==0x47&&
		pData[4]==0x0d&&pData[5]==0x0a&&pData[6]==0x1a&&pData[7]==0x0a)
	{ // png
		if(pWidth==0&&pHeight==0)
		{
			return MGDI_IMG_PNG;			
		}	
		i=8;
		// png is converted
		while(i+12 <= nSize)
		{
			tmp = __GetULong_L(&pData[i]);
			if(i+12+tmp>(MULONG)nSize)
			{
				return MGDI_IMG_ERR;
			}
			i += 4;
			if(pData[i]==0x49 && pData[i+1]==0x48 && pData[i+2]==0x44 && pData[i+3]==0x52 && tmp>8)
			{
				if(pWidth!=0)
				{
					*pWidth = __GetULong_L(&pData[i+4]);
				}
				if(pHeight!=0)
				{
					*pHeight = __GetULong_L(&pData[i+8]);
				}
				return MGDI_IMG_PNG;
			}
			i += 8+tmp;
		}
		return MGDI_IMG_PNG;
	}
	else if(pData[0] == 'G' && pData[1] == 'I' && pData[2] == 'F'){ // gif
		if(nSize<13)
		{
			return MGDI_IMG_ERR;
		}

		if(pWidth==0&&pHeight==0)
		{
			return MGDI_IMG_GIF;			
		}

		if(pWidth!=0)
		{
			*pWidth = (MUINT)__GetUShort_B(&pData[6]);
		}
		if(pHeight!=0)
		{
			*pHeight = (MUINT)__GetUShort_B(&pData[8]);
		}
		return MGDI_IMG_GIF;
	}
	else if(pData[0]==0xFF&&pData[1]==0xD8&&pData[nSize-2]==0xFF&&pData[nSize-1]==0xD9)
	{
		if(pWidth==0&&pHeight==0)
		{
			return MGDI_IMG_JPG;			
		}	
		i = nSize-2;		
		while(i>0)
		{
			i--; 			
			if(pData[i] < 0xC0) continue; 
			if(pData[i] > 0xC3) continue; 
			i--; 
			if(pData[i] != 0xFF) continue; 
			i+=5; 
			break; 
		}
		if(i<5||i+4>nSize)
		{
			return MGDI_IMG_ERR;
		}	
		if(pWidth!=0)
		{
			*pWidth = pData[i+2]*256+pData[i+3];
		}
		if(pHeight!=0)
		{
			*pHeight = pData[i]*256+pData[i+1];
		}	
		return MGDI_IMG_JPG;			
	}
	else if(pData[0]==0xFF&&pData[1]==0xD8)
	{
		if(pWidth==0&&pHeight==0)
		{
			return MGDI_IMG_JPG;			
		}	
		i = nSize-5;		
		while(i>0)
		{
			i--; 			
			if(pData[i] < 0xC0) continue; 
			if(pData[i] > 0xC3) continue; 
			i--; 
			if(pData[i] != 0xFF) continue; 
			i+=5; 
			break; 
		}
		if(i<5||i+4>nSize)
		{
			return MGDI_IMG_ERR;
		}	
		if(pWidth!=0)
		{
			*pWidth = pData[i+2]*256+pData[i+3];
		}
		if(pHeight!=0)
		{
			*pHeight = pData[i]*256+pData[i+1];
		}	
		return MGDI_IMG_JPG;			
	}

	return MGDI_IMG_ERR;	
}

MINT McfGdi_GetImageInfo(const MBYTE* pImageData, MUINT nDataSize,MImageInfo* pMImageInfo)
{
	MINT nRet = MGDI_SUCCESS;
	GDILOGENTERFUNC();

	if (pImageData && nDataSize > 0 && pMImageInfo)
	{
		pMImageInfo->m_imageType = __helper_getsize((MBYTE*)pImageData,nDataSize,&pMImageInfo->m_nWidth,&pMImageInfo->m_nHeight);
		if (MGDI_IMG_ERR != pMImageInfo->m_imageType)
		{
			pMImageInfo->m_nImageSize = nDataSize;
			pMImageInfo->m_pImageBuffer = (MBYTE*)pImageData;
		} 
		else
		{
			nRet = MGDI_ERROR;
		}

	}
	else
	{
		nRet = MGDI_PARAM_ERR;
	}

	GDILOGLEAVEFUNC();
	return nRet;

}
//////////////////////////////////////////////////////////////////////////
static MINT __helper_DrawImageByType(MINT nX, MINT nY, const MBYTE* pImgData, MUINT nDataSize, MINT nImgType)
{
	MINT nRet = MGDI_SUCCESS;

	if (pImgData && nDataSize > 0)
	{
		switch (nImgType)
		{
		case MGDI_IMG_BMP:
			{
				gdi_image_bmp_draw(nX, nY, (MBYTE*)pImgData, nDataSize);
			}
			break;

		case MGDI_IMG_PNG:
			{
				gdi_image_png_draw(nX, nY,(MBYTE*)pImgData, nDataSize);
			}
			break;

		case MGDI_IMG_GIF:
			{
				gdi_image_gif_draw(nX, nY,(MBYTE*)pImgData, nDataSize, 0);
			}
			break;

		case MGDI_IMG_JPG:
			{
				gdi_image_jpeg_draw(nX, nY,(MBYTE*)pImgData, nDataSize);
			}
			break;

		default:
			{
				nRet = MGDI_ERROR;
			}
			break;
		}

	}
	else
	{
		nRet = MGDI_PARAM_ERR;
	}

	return nRet;
}


MINT McfGdi_DrawImage(MINT nX, MINT nY, const MBYTE* pImgData, MUINT nDataSize)
{
	MINT  nRet = MGDI_SUCCESS;
	GDILOGENTERFUNC();

	if (pImgData && nDataSize > 0)
	{
		MImageInfo tempImageInfo = {0};
		if (MGDI_SUCCESS == McfGdi_GetImageInfo(pImgData, nDataSize,&tempImageInfo))
		{
			nRet = __helper_DrawImageByType(nX, nY, pImgData, nDataSize, tempImageInfo.m_imageType);
		}
	}
	else
	{
		nRet = MGDI_PARAM_ERR;
	}

	GDILOGLEAVEFUNC();
	return nRet;  
}

#endif


