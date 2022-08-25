
#include "MMI_features.h"

#ifdef __MMI_GB_WINGUO__

#undef GB_PACKAGE

#include "MMI_include.h"
#include "Gui.h"
#include "Gui_themes.h"
//#include "Gdi_include.h"
// #include "gd_include.h"
// #include "fs_type.h"

//#include "GB_WG_PlatUi.h"
// #include "GB_DataTypeDef.h"
// #include "GB_WG_SkinManager.h"
// #include "GB_Math.h"
#include "GB_WG_Public.h"
#include "GB_WG_SystemInc.h"
#include "GB_WG_MTKPlatver.h"

#ifndef VER0840
#include "Gdi_image_bmp.h"
#include "Gdi_image_png.h"
#include "Gdi_image_gif.h"
#else
extern GDI_RESULT gdi_image_gif_draw(S32 ox, S32 oy, U8 *GIF_src, U32 size, U16 frame_number);
#endif
/////////// GUI /////////////
extern stFontAttribute wgui_dialer_box_f1;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
#define GB_FONT (0x80|16)
stFontAttribute g_psysFontVector = {0,0,0, GB_FONT,0,1};
#endif


static stFontAttribute* gb_wg_gui_get_sys_font(GB_WG_FONT text_font)
{
	stFontAttribute* psysFont= NULL;
	switch(text_font)
	{
	case GB_MMI_large_font: 
		psysFont = &MMI_large_font;
		break;
	case GB_MMI_medium_font:
		//  [6/2/2012 liangchuanhui]
		if (GB_WG_Get_isVirtual_key())
		{
			psysFont = &MMI_large_font;
		}
		else
		{
			psysFont = &MMI_medium_font;
		}
// 	#ifdef GBWG_VIRTUAL_KEY
// 		psysFont = &MMI_large_font;
// 	#else
// 		psysFont = &MMI_medium_font;
// 	#endif
		break;
	case GB_MMI_small_font:
		psysFont = &MMI_small_font;
		break;
	case GB_MMI_dialer_font:
		//  [6/2/2012 liangchuanhui]
		if (GB_WG_Get_isVirtual_key())
		{
			psysFont = &MMI_medium_font;
		}
		else
		{
			psysFont = &MMI_medium_font;//&wgui_dialer_box_f1;
		}
// #ifdef GBWG_VIRTUAL_KEY
// 		psysFont = &MMI_medium_font;
// #else
// 		psysFont = &MMI_medium_font;//&wgui_dialer_box_f1;
// #endif
		break;
	default:
		ASSERT(0);
		break;
	}
	return psysFont;
}

GB_BOOL GB_WG_UI_Measure_GetDefault(GB_INT* pWidth,GB_INT *pHeight)
{
	GB_CHARTYPE gb_wg_szTestW[]={0x5BBD,0x0000};//宽
	if(pWidth==GB_NULL||pHeight==GB_NULL)return GB_FALSE;
	gb_wg_gui_measure_string((GB_STRTYPE)gb_wg_szTestW,pWidth,pHeight, GB_MMI_medium_font);
	return GB_TRUE;
}

GB_BOOL GB_WG_UI_Measure_GetDefaultSmallFont(GB_INT* pWidth,GB_INT *pHeight)
{
	GB_CHARTYPE gb_wg_szTestH[]={0x9AD8,0x0000};//高
	if(pWidth==GB_NULL||pHeight==GB_NULL)return GB_FALSE;
	gb_wg_gui_measure_string((GB_STRTYPE)gb_wg_szTestH,pWidth,pHeight, GB_MMI_small_font);
	return GB_TRUE;
}

GB_INT gb_wg_gui_get_baseline_height(GB_WCHAR *pstr)
{
	if (pstr)
	{
		mmi_fe_get_string_info_param_struct query;
		memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
		query.String =(U8*)pstr;
		query.enableTruncated = MMI_FALSE;
		query.w = 0;
		query.n = mmi_ucs2strlen((S8*)pstr);				
		mmi_fe_get_string_widthheight(&query);
		return query.baseline;
	}
	return 0;
}

GB_INT gb_wg_gui_get_char_defult_Height(GB_VOID)
{
	GB_INT nWidth;
	GB_INT nHeight;
	GB_WG_UI_Measure_GetDefault(&nWidth, &nHeight);
	return nHeight;
}

// GB_INT 	gb_wg_gui_get_char_width(GB_CHARTYPE text)
// {
// 	return gui_get_character_width(text);
// }

GB_VOID gb_wg_gui_measure_character(GB_CHARTYPE character,GB_INT *width,GB_INT*height, GB_WG_FONT text_font)
{
	gb_wg_gui_set_font(text_font);
	gui_measure_character(character,width,height);
}

GB_VOID gb_wg_gui_measure_string_n(GB_STRTYPE text,GB_UINT n,GB_INT* width,GB_INT* height, GB_WG_FONT text_font)
{
	gb_wg_gui_set_font(text_font);
	gui_measure_string_n(text,n,width,height);
}

GB_INT gb_wg_gui_get_string_width(GB_STRTYPE text, GB_WG_FONT text_font)
{
	gb_wg_gui_set_font(text_font);
	return gui_get_string_width(text);
}

GB_INT gb_wg_gui_get_string_height(GB_STRTYPE text, GB_WG_FONT text_font)
{
	gb_wg_gui_set_font(text_font);
	return gui_get_string_height(text);
}

GB_VOID gb_wg_gui_measure_string(GB_STRTYPE text,GB_INT* width,GB_INT* height, GB_WG_FONT text_font)
{
	gb_wg_gui_set_font(text_font);
	gui_measure_string(text,width,height);
}


GB_VOID gb_wg_gui_measure_image(GB_U8*  image,GB_INT* width,GB_INT* height)/////change bill
{
	gui_measure_image(image,width,height);
}


GB_VOID gb_wg_gui_set_font(GB_WG_FONT text_font)
{
	gui_set_font(gb_wg_gui_get_sys_font(text_font));
}

static gdi_color gb_wg_to_sys_gdi_color(GB_COLOR color)
{
	return gdi_act_color_from_rgb(255, (GB_BYTE)((color>>16) & 0xFF), 
				(GB_BYTE)((color>>8) & 0xFF), 
				(GB_BYTE)(color & 0xFF));
}
static color gb_wg_to_sys_color(GB_COLOR c)
{
	return gui_color((GB_BYTE)((c>>16) & 0xFF), 
				(GB_BYTE)((c>>8) & 0xFF), 
				(GB_BYTE)(c & 0xFF));
}

GB_VOID gb_wg_gui_set_text_color(GB_COLOR color)
{
	gui_set_text_color(gb_wg_to_sys_color(color));
}

// GB_VOID gb_wg_gui_move_text_cursor(GB_UINT x,GB_UINT y)
// {
// 	gui_move_text_cursor(x,y);
// }

GB_VOID gb_wg_print_text(GB_INT x, GB_INT y, GB_U16* str_ptr)
{	
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
	S32 baseline;
	baseline = gui_get_string_height(str_ptr) - 2;
	mmi_fe_show_string_baseline(x, y, (GB_U8*)str_ptr, baseline, 0);
#else
	gui_move_text_cursor(x, y);
	gui_print_text(str_ptr);
#endif
}

// GB_VOID gb_wg_gui_print_text(GB_STRTYPE str)
// {
// 	gui_print_text(str);
// }

GB_VOID gb_wg_ShowString_n(GB_UINT x,GB_UINT y,
						   GB_WG_FONT font, GB_STRTYPE str, 
						   GB_INT len, GB_INT height)
{
	GB_WCHAR widthstr[5]={0x6211, 0x6f56,'o', 'k', 0};
	gb_wg_gui_set_font(font);
	gb_wg_ShowString_n_baseline(x, y, font, str, len, gb_wg_gui_get_baseline_height(widthstr));
	//ShowString_n(x, y, *(gb_wg_gui_get_sys_font(font)), 0, (GB_U8*)str, len, height);
}

GB_VOID gb_wg_ShowString(GB_UINT x,GB_UINT y,GB_WG_FONT font,GB_STRTYPE str,GB_INT height)
{
	GB_WCHAR widthstr[5]={0x6211, 0x6f56,'o', 'k', 0};
	gb_wg_gui_set_font(font);
	gb_wg_ShowString_n_baseline(x, y, font, str, gb_wg_wcslen(str), gb_wg_gui_get_baseline_height(widthstr));
//	ShowString(x,y,*(gb_wg_gui_get_sys_font(font)),0,(GB_U8*)str,height);
}

GB_VOID gb_wg_ShowString_n_baseline(GB_UINT x,GB_UINT y,GB_WG_FONT font,GB_STRTYPE str,GB_INT len,GB_INT baseline)
{
	gb_wg_gui_set_font(font);
	if (r2lMMIFlag)
	{
		x += gb_wg_gui_get_string_width(str, font);
		ShowString_n_baseline(x,y,*(gb_wg_gui_get_sys_font(font)),0,(GB_U8*)str,len,baseline);
	}
	else
	{
		ShowString_n_baseline(x,y,*(gb_wg_gui_get_sys_font(font)),0,(GB_U8*)str,len,baseline);
	}
}


////////////////////////////
GB_ULONG GB_WG_GetULong_Browser(GB_BYTE* pData)
{
	GB_ULONG tmp;
	if(pData==0){
		return 0;
	}
	tmp = 0;
	tmp += pData[0]; tmp = tmp<<8; 
	tmp += pData[1]; tmp = tmp<<8; 
	tmp += pData[2]; tmp = tmp<<8; 
	tmp += pData[3]; 
	return tmp;
}
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
#endif
GB_INT     GB_WG_UI_MeasureImgSize(GB_BYTE * pData,GB_INT nSize,GB_INT*pWidth,GB_INT* pHeight,GB_WG_GDIHANDLE *pHandle){
	GB_INT type,w,h,i,tmp;
	unsigned short wGifW,wGifH;
	
	type = g_GB_WG_IMG_TYPE_ERR;
	w = h = 0;
	if(pData==0||nSize<4){
		return g_GB_WG_IMG_TYPE_ERR;
	}
	if(pData[0] == 'B' && pData[1] == 'M'){  //bmp 
		if(nSize<54){
			return g_GB_WG_IMG_TYPE_ERR;
		}
		if(pWidth!=0){
			*pWidth = (GB_INT)GB_WG_GetULong_Browser(&pData[18]);
		}
		if(pHeight!=0){
			*pHeight = (GB_INT)GB_WG_GetULong_Browser(&pData[22]);
		}
		return g_GB_WG_IMG_TYPE_BMP;
	} 
	else if(pData[0]==0x89&&pData[1]==0x50&&pData[2]==0x4E&&pData[3]==0x47&&
		pData[4]==0x0d&&pData[5]==0x0a&&pData[6]==0x1a&&pData[7]==0x0a){ // png
		if(pWidth==0&&pHeight==0){
			return g_GB_WG_IMG_TYPE_PNG;			
		}	
		i=8;
		while(i+12<=nSize){
			tmp = (GB_INT)GB_WG_GetULong_Browser(&pData[i]);
			if(i+12+tmp>nSize){
				return g_GB_WG_IMG_TYPE_ERR;
			}
			i += 4;
			if(pData[i]==0x49&&pData[i+1]==0x48&&pData[i+2]==0x44&&pData[i+3]==0x52&&tmp>8){
				if(pWidth!=0){
					*pWidth = (GB_INT)GB_WG_GetULong_Browser(&pData[i+4]);
				}
				if(pHeight!=0){
					*pHeight = (GB_INT)GB_WG_GetULong_Browser(&pData[i+8]);
				}
				return g_GB_WG_IMG_TYPE_PNG;
			}
			i += 8+tmp;
		}
		return g_GB_WG_IMG_TYPE_ERR;
	}
	else if(pData[0] == 'G' && pData[1] == 'I' && pData[2] == 'F'){ // gif
		if(nSize<13){
			return g_GB_WG_IMG_TYPE_ERR;
		}
		if(pWidth!=0){			
//			*pWidth = (GB_INT)GB_WG_GetUShort_Browser(&pData[6]);
			memcpy(&wGifW,&pData[6],2);
			*pWidth = (GB_INT)wGifW;
		}
		if(pHeight!=0){
//			*pHeight = (GB_INT)GB_WG_GetUShort_Browser(&pData[8]);
			memcpy(&wGifH,&pData[8],2);
			*pHeight = (GB_INT)wGifH;
		}
		return g_GB_WG_IMG_TYPE_GIF;
	}
	//else if(pData[0]==0xFF&&pData[1]==0xD8&&pData[nSize-2]==0xFF&&pData[nSize-1]==0xD9){
	else if(pData[0]==0xFF&&pData[1]==0xD8)
	{
		// 可能尾部 有空余符号 add by zhangwei-jerry 20111128
		GB_INT realSize = nSize;
		while (pData[realSize - 1] == '\0')
		{
			realSize--;
		}

		if (pData[realSize-2]==0xFF&&pData[realSize-1]==0xD9)
		{
			if(pWidth==0&&pHeight==0){
				return g_GB_WG_IMG_TYPE_JPG;			
			}	
			i = realSize-2;		
			while(i>0){
				i--; 			
				if(pData[i] < 0xC0) continue; 
				if(pData[i] > 0xC3) continue; 
				i--; 
				if(pData[i] != 0xFF) continue; 
				i+=5; 
				break; 
			}
			if(i<5||i+4>realSize){
				return g_GB_WG_IMG_TYPE_ERR;
			}	
			if(pWidth!=0){
				*pWidth = pData[i+2]*256+pData[i+3];
			}
			if(pHeight!=0){
				*pHeight = pData[i]*256+pData[i+1];
			}	
			return g_GB_WG_IMG_TYPE_JPG;
		}			
	}
	
	return g_GB_WG_IMG_TYPE_ERR;	
}

GB_INT GB_WG_UI_DrawImg(GB_BYTE * pData,GB_INT nSize,
						GB_INT offsetX,GB_INT offsetY,GB_INT dispW,GB_INT dispH,
						GB_INT width,GB_INT height,
						GB_INT xPos,GB_INT yPos,GB_Rect *pClipRect,GB_WG_GDIHANDLE *pHandle,GB_BOOL bClip)
{
	GB_INT type;
	type = GB_WG_UI_MeasureImgSize(pData,nSize,0,0,pHandle);
	if(type==g_GB_WG_IMG_TYPE_ERR||type>g_GB_WG_IMG_TYPE_JPG){
		return -1;
	}
	if(bClip){
		gdi_layer_push_clip();
		gdi_layer_set_clip(pClipRect->xPos,pClipRect->yPos,pClipRect->width,pClipRect->height);
	}
	switch(type){
	case g_GB_WG_IMG_TYPE_BMP:
		gdi_image_bmp_draw(xPos-offsetX,yPos-offsetY,pData,nSize);
		break;
	case g_GB_WG_IMG_TYPE_PNG:
		gdi_image_png_draw(xPos-offsetX,yPos-offsetY,pData,nSize);
		break;
	case g_GB_WG_IMG_TYPE_GIF:
		gdi_image_gif_draw(xPos-offsetX,yPos-offsetY,pData,nSize,0);
		break;
	case g_GB_WG_IMG_TYPE_JPG:
		gdi_image_jpeg_draw(xPos-offsetX,yPos-offsetY,pData,nSize);
		break;
	}
	if(bClip){
		gdi_layer_pop_clip();
	}
	return 0;
}


// GB_COLORSYS GB_WG_UI_MakeColorSystem(GB_INT color)
// {
// 	return gdi_act_color_from_rgb(255, 
// 						(GB_BYTE)((color>>16)&0xFF),
// 						(GB_BYTE)((color>>8)&0xFF),
// 						(GB_BYTE)(color&0xFF));
// }

GB_VOID GB_WG_Fill_Rect_Gradual(GB_INT x1, GB_INT y1, GB_INT x2, GB_INT y2, GB_COLOR color1,GB_COLOR color2)
{
	#if defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
	gb_wg_gui_fill_rectangle((GB_LONG)x1,(GB_LONG)y1,(GB_LONG)x2,(GB_LONG)y2,color1);
	#else
	if (color1 != color2)
	{
	UI_filled_area  filler = {0};
	static color g_color[2];
	color c;
	static GB_U8 perc[1] ={100};
	gradient_color gc = {g_color,perc,2};
	c.alpha=0xff;	
	c.r = (color1 >> 16)&0xff;
	c.g = (color1 >> 8)&0xff;
	c.b = color1&0xff;
	g_color[0] = c;
	c.r = (color2 >> 16)&0xff;
	c.g = (color2 >> 8)&0xff;
	c.b = color2 &0xff;
	g_color[1] = c;
	filler.flags = UI_FILLED_AREA_TYPE_GRADIENT_COLOR|UI_FILLED_AREA_VERTICAL_FILL;
	filler.gc = &gc;
	gui_draw_filled_area((GB_LONG)x1,(GB_LONG)y1,(GB_LONG)x2,(GB_LONG)y2,&filler);
	}
	else
	{
		gb_wg_gui_fill_rectangle((GB_LONG)x1,(GB_LONG)y1,(GB_LONG)x2,(GB_LONG)y2,color1);
	}
	#endif
}

GB_VOID GB_WG_Draw_Line(GB_INT startX,GB_INT startY,GB_INT endX,GB_INT endY, GB_COLOR color)
{
	gdi_draw_line(startX,startY,endX,endY,gb_wg_to_sys_gdi_color(color));
}

GB_VOID GB_WG_Draw_RoundRect(GB_INT x,GB_INT y,GB_INT width,GB_INT height, GB_COLOR color)
{
	gdi_draw_line(x+1,y,x+width-2,y,gb_wg_to_sys_gdi_color(color)); //上
	gdi_draw_line(x+1,y+height-1,x+width-2,y+height-1,gb_wg_to_sys_gdi_color(color)); //下
	gdi_draw_line(x,y+1,x,y+height-2,gb_wg_to_sys_gdi_color(color)); //左
	gdi_draw_line(x+width-1,y+1,x+width-1,y+height-2,gb_wg_to_sys_gdi_color(color)); //右
}

GB_VOID GB_WG_setPexel(GB_INT x,GB_INT y,GB_INT **triangleScanlineMinMaxArrays,GB_INT triangleDeltaY)
{
	y-=triangleDeltaY;
	if(triangleScanlineMinMaxArrays[y]==GB_NULL)
	{
		triangleScanlineMinMaxArrays[y]=(GB_INT*)GB_WG_Malloc(2*sizeof(GB_INT));
		
		if(triangleScanlineMinMaxArrays[y]==GB_NULL)return ;
		triangleScanlineMinMaxArrays[y][0]=x;
		triangleScanlineMinMaxArrays[y][1]=x;
	}
	else
	{
		
		if(x<triangleScanlineMinMaxArrays[y][0])//x<此扫描线的最小数值
		{
			triangleScanlineMinMaxArrays[y][0]=x;
		}
		else if(x>triangleScanlineMinMaxArrays[y][1])
		{//x>此扫描线的最大数值
			triangleScanlineMinMaxArrays[y][1]=x;
		}
	}
}   

GB_INT GB_WG_calculateLine(GB_INT x1,GB_INT y1,GB_INT x2,GB_INT y2,GB_INT **triangleScanlineMinMaxArrays,GB_INT triangleDeltaY)
{
	GB_INT iTag;
	GB_INT dx,dy,tx,ty,inc1,inc2,d,curx,cury;
	
	GB_WG_setPexel(x1,y1,triangleScanlineMinMaxArrays,triangleDeltaY);
	
	if(x1==x2 && y1==y2){
		return 1;
	}
	
	iTag=0;
	dx=GB_ABS(x2-x1);
	dy=GB_ABS(y2-y1);
	if(dx<dy)
	{
		GB_INT tmp;
		iTag=1;	
		
		tmp=x1;
		x1=y1;
		y1=tmp;
		
		tmp=x2;
		x2=y2;
		y2=tmp;
		
		tmp=dx;
		dx=dy;
		dy=tmp;
		
	}
	
	tx=(x2-x1)>0?1:-1;
	ty=(y2-y1)>0?1:-1;
	
	curx=x1;
	cury=y1;
	
	inc1=2*dy;
	inc2=2*(dy-dx);
	
	d=inc1-dx;
	//curx+=1;
	while(curx!=x2){
		if(d<=dy){
			d+=inc1;
		}else{
			cury+=ty;
			d+=inc2;
		}
		
		if(iTag>0)
			GB_WG_setPexel(cury,curx,triangleScanlineMinMaxArrays,triangleDeltaY);
		else
			GB_WG_setPexel(curx,cury,triangleScanlineMinMaxArrays,triangleDeltaY);
		
		curx+=tx;
	}
	return 0;
	
}

GB_VOID GB_WG_Fill_Triangle(GB_INT x1,GB_INT y1,GB_INT x2,GB_INT y2,GB_INT x3,GB_INT y3,GB_COLOR color){	
	GB_INT ymin,ymax;
	GB_INT index=0;	
	GB_INT nMaxItem=0;
	GB_INT triangleDeltaY=0;
	GB_INT **triangleScanlineMinMaxArrays=GB_NULL;
/*
#ifdef LOG_TO_OUTPUT	
	MTK_DebugInt(x1,UIDISP_MODEL,UIDISP_FUNC,LEVEL_TIP,GB_NULL);
	MTK_DebugInt(y1,UIDISP_MODEL,UIDISP_FUNC,LEVEL_TIP,GB_NULL);
	MTK_DebugRN("",UIDISP_MODEL,UIDISP_FUNC,LEVEL_TIP,GB_NULL);
	
	MTK_DebugInt(x2,UIDISP_MODEL,UIDISP_FUNC,LEVEL_TIP,GB_NULL);
	MTK_DebugInt(y2,UIDISP_MODEL,UIDISP_FUNC,LEVEL_TIP,GB_NULL);
	MTK_DebugRN("",UIDISP_MODEL,UIDISP_FUNC,LEVEL_TIP,GB_NULL);
	
	MTK_DebugInt(x3,UIDISP_MODEL,UIDISP_FUNC,LEVEL_TIP,GB_NULL);
	MTK_DebugInt(y3,UIDISP_MODEL,UIDISP_FUNC,LEVEL_TIP,GB_NULL);
	MTK_DebugRN("线坐标哦",UIDISP_MODEL,UIDISP_FUNC,LEVEL_TIP,GB_NULL);
#endif
*/

	ymax=GB_MAX(GB_MAX(y1,y2),y3);
	ymin=GB_MIN(y1,GB_MIN(y2,y3));
	nMaxItem = ymax-ymin+1;
	triangleScanlineMinMaxArrays= (GB_INT**)GB_WG_Malloc(nMaxItem*sizeof(GB_INT*));
	if(triangleScanlineMinMaxArrays==GB_NULL)return;
	for (index=0;index<nMaxItem;index++)
	{
		triangleScanlineMinMaxArrays[index]=GB_NULL;		
	}	
	triangleDeltaY=ymin;
	
	GB_WG_calculateLine(x1,y1,x2,y2,triangleScanlineMinMaxArrays,triangleDeltaY);
	GB_WG_calculateLine(x3,y3,x2,y2,triangleScanlineMinMaxArrays,triangleDeltaY);
	GB_WG_calculateLine(x1,y1,x3,y3,triangleScanlineMinMaxArrays,triangleDeltaY);
	
	
	for (index=0;index<nMaxItem;index++){
		GB_INT y=triangleDeltaY+index;	
		if(triangleScanlineMinMaxArrays[index]!=GB_NULL)
		{
			gdi_draw_line(triangleScanlineMinMaxArrays[index][0],
						 y,triangleScanlineMinMaxArrays[index][1],
						 y,gb_wg_to_sys_gdi_color(color));
		}
	}        
	
	for (index=0;index<nMaxItem;index++){
		if(triangleScanlineMinMaxArrays[index]!=GB_NULL)
		{
			GB_WG_Free(triangleScanlineMinMaxArrays[index]);
			triangleScanlineMinMaxArrays[index] = GB_NULL;
		}
	}
	GB_WG_Free(triangleScanlineMinMaxArrays);
	triangleScanlineMinMaxArrays = GB_NULL;
	
}

GB_VOID GB_WG_Draw_Delta(GB_INT x,GB_INT y,GB_INT h,GB_COLOR fillColor,GB_INT flag)
{	
	GB_USHORT i,d;

	switch(flag){
	case GB_DIRECT_UP:
		d = 2*h-2;
		x = x+h-1;
		for(i = 0;i < h;i++){
			gdi_draw_line(x + i,y - i,x +d -i,y-i,gb_wg_to_sys_gdi_color(fillColor));
		}
		break;
	case GB_DIRECT_DOWN:
		d = 2*h-2;
		x = x+h-1;
		for(i = 0;i < h;i++){
			gdi_draw_line(x + i,y + i,x +d -i,y+ i,gb_wg_to_sys_gdi_color(fillColor));
		}
		break;
	case GB_DIRECT_LEFT:
		d = 2*h-2;
		x = x+h-1;
		for(i = 0;i < h;i++){
			gdi_draw_line(x-i,y+i,x-i,y+d-i,gb_wg_to_sys_gdi_color(fillColor));
		}
		break;
	case GB_DIRECT_RIGHT:
		d = 2*h-2;
		for(i = 0;i < h;i++){
			gdi_draw_line(x+i,y+i,x+i,y+d-i,gb_wg_to_sys_gdi_color(fillColor));
		}
		break;
	}
}

GB_INT GB_WG_GetImgWH(GB_BYTE * pData,GB_INT nSize,GB_INT* pWidth,GB_INT* pHeight)
{
	GB_INT ret = g_GB_WG_IMG_TYPE_ERR;
	
	GB_WG_GDIHANDLE gdiHandle;
	
	if (pData && nSize > 0)
	{
		ret = GB_WG_UI_MeasureImgSize(pData,nSize,pWidth,pHeight,&gdiHandle);
	}
	
	return ret;
}

GB_VOID gb_wg_gui_push_clip(GB_VOID)
{
	gui_push_clip();
}

GB_VOID gb_wg_gui_pop_clip(GB_VOID)
{
	gui_pop_clip();
}

GB_VOID gb_wg_gui_lock_double_buffer()
{
	gui_lock_double_buffer();
}

GB_VOID gb_wg_gui_unlock_double_buffer()
{
	gui_unlock_double_buffer();
}

GB_VOID gb_wg_gui_BLT_double_buffer(GB_INT x1,GB_INT y1,GB_INT x2,GB_INT y2)
{
	gui_BLT_double_buffer(x1,y1,x2,y2);
}

GB_VOID gb_wg_gui_get_clip(GB_INT *x1,GB_INT *y1,GB_INT*x2,GB_INT*y2)
{
	gui_get_clip(x1,y1,x2,y2);
}

// GB_VOID gb_wg_gui_draw_line(GB_UINT x1,GB_UINT y1,GB_UINT x2,GB_UINT y2,GB_COLOR color)
// {
// 	//gui_line(x1,y1,x2,y2, gb_wg_to_sys_color(color));
// 	GB_WG_Draw_Line(x1,y1,x2,y2,color);
// }

GB_VOID gb_wg_gui_draw_rectangle(GB_UINT x1,GB_UINT y1,GB_UINT x2,GB_UINT y2,GB_COLOR color)
{
	gui_draw_rectangle(x1,y1,x2,y2, gb_wg_to_sys_color(color));
}

GB_VOID gb_wg_gui_fill_rectangle(GB_UINT x1,GB_UINT y1,GB_UINT x2,GB_UINT y2,GB_COLOR color)
{
	gui_fill_rectangle(x1,y1,x2,y2, gb_wg_to_sys_color(color));
}


GB_VOID gb_wg_gdi_image_get_dimension(GB_U8 *img_src,GB_INT *width,GB_INT *height)
{
	gdi_image_get_dimension(img_src,width,height);
}

GB_VOID gb_wg_gdi_image_get_dimension_id(GB_INT img_id,GB_INT*width,GB_INT *height)
{
	gdi_image_get_dimension_id((GB_U16)(img_id+GB_WINGUO_BASE),width,height);
}

GB_VOID gb_wg_gdi_draw_round_rect(GB_INT x1, GB_INT y1, GB_INT x2, GB_INT y2, GB_COLOR rect_color, GB_COLOR frame_color, GB_INT frame_width)
{
	#if defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
	gb_wg_gui_draw_rectangle(x1,y1,x2,y2,rect_color);
	#else
	gdi_draw_round_rect(x1,y1,x2,y2,gb_wg_to_sys_gdi_color(rect_color),
						gb_wg_to_sys_gdi_color(frame_color),frame_width);
	#endif
}

// GB_VOID gb_wg_gdi_draw_solid_rect(GB_INT x1, GB_INT y1, GB_INT x2, GB_INT y2, GB_COLOR rect_color)
// {
// 	gdi_draw_solid_rect(x1,y1,x2,y2,gb_wg_to_sys_gdi_color(rect_color));
// }

// GB_VOID gb_wg_gdi_layer_push_clip()
// {
// 	gdi_layer_push_clip();
// }

// GB_VOID gb_wg_gdi_layer_set_clip(GB_INT x1,GB_INT y1,GB_INT x2,GB_INT y2)
// {
// 	gdi_layer_set_clip(x1,y1,x2,y2);
// }

// GB_VOID gb_wg_gdi_layer_pop_clip()
// {
// 	gdi_layer_pop_clip();
// }

GB_VOID gb_wg_gdi_draw_rect(GB_INT x1, GB_INT y1, GB_INT x2, GB_INT y2, GB_COLOR rect_color)
{
	gdi_draw_rect(x1,y1,x2,y2,gb_wg_to_sys_gdi_color(rect_color));
}

GB_PU8 gb_wg_get_image(GB_INT img_id)
{
	return (GB_PU8)get_image((GB_U16)(img_id+GB_WINGUO_BASE));
}

GB_VOID gb_wg_gui_show_image(GB_INT x,GB_INT y,GB_PU8 img_src)
{
	gui_show_image(x,y,img_src);
}

GB_VOID gb_wg_gui_set_clip(GB_INT x1, GB_INT y1, GB_INT x2, GB_INT y2)
{
	gui_set_clip(x1,y1,x2,y2);
}

GB_STRTYPE gb_wg_get_string(GB_INT str_id)
{
	return (GB_STRTYPE)get_string((GB_U16)(str_id+GB_WINGUO_BASE));
}

// static scrolling_text GBMMI_List_scrolling_text={0};
// GB_VOID gb_wg_gui_draw_scrolling(GB_VOID)
// {
// 	gui_handle_scrolling_text(&GBMMI_List_scrolling_text);
// 	GBWinManager_DrawScreen(GB_WG_GetWinManager());
// }
// extern GB_VOID gb_wg_gui_show_scrolling_text(
// 											 GB_STRTYPE text,
// 											 GB_UINT x, 
// 											 GB_UINT y, 
// 											 GB_UINT width, 
// 											 GB_UINT height, 
// 											 GB_VOID (*draw_background)(GB_INT x1, GB_INT y1, GB_INT x2, GB_INT y2), 
// 											 GB_COLOR text_color,
// 											 GB_COLOR border_color,
// 											 GB_WG_FONT  ft)
// {
// 	gui_create_scrolling_text(&GBMMI_List_scrolling_text, x, y, width, height, text, gb_wg_gui_draw_scrolling, 
// 		draw_background, gb_wg_to_sys_color(text_color), gb_wg_to_sys_color(border_color));
// 	GBMMI_List_scrolling_text.text_font = *(gb_wg_gui_get_sys_font(ft));
// 	gui_show_scrolling_text(&GBMMI_List_scrolling_text);
// }
// GB_VOID gb_wg_gui_scrolling_text_stop(GB_VOID)
// {
// 	gui_scrolling_text_stop(&GBMMI_List_scrolling_text);
// }

GB_UINT gb_wg_get_bottombar_hight(GB_VOID)
{
	return MMI_button_bar_height;
//	return 0;
}


#endif /* #ifdef __MMI_GB_WINGUO__ */

