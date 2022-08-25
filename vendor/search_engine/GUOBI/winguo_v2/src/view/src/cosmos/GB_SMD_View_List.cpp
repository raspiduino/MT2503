/*================================================================
*
* 文 件 名：GB_SMD_View_List.cpp
*
* 
* 文件描述：创建实现List基类
* 
*
* 
*
*       
*
* 
*
* 
*
* 作    者：Liyong [10/11/2012]
*
================================================================*/

#include "MMI_features.h"


#ifdef __MMI_GB_WINGUO_V2__

#include "inc\GB_SMD_View_List.h"
#include "mmi_rp_app_gb_winguo_def.h"

extern "C"
{
#include "GB_SMD_Element.h"
#include "GB_SMD_ElementCallLog.h"
#include "GB_SMD_ElementPhoneNum.h"
#include "GB_SMD_ElementApp.h"
extern GB_U16 GB_WG_SMD_List_Get_InputStr_Data(GB_U16 *pusInputStr);
};

WinguoSmartDialListContent::WinguoSmartDialListContent(GB_UINT index):m_index(index),m_icon(NULL),
pContentIcon(NULL),
pContentIconFlag(NULL),
Frame(NULL),
m_pAppName1(NULL),
m_pAppName2(NULL),
m_pAppName3(NULL),
m_StringFlag1(NULL),
m_StringFlag2(NULL),
m_StringFlag3(NULL)
{

};

GB_VOID WinguoSmartDialListContent::onCreateElements()
{ 
	GB_U32 x = 0;
	GB_U32 y = 0;
	GB_U32  xgap = 0;
	GB_U32  ygap = 0;
	GB_USHORT *pTempStr1 = NULL;
	GB_UINT Str1Len = 0;
	GB_USHORT *pTempStr2 = NULL;
	GB_UINT Str2Len = 0;
	GB_USHORT *pTempStr3 = NULL;
	GB_UINT Str3Len = 0;
	GB_U16               Cach_Type = 0;
	GB_U32				 nId = 0;
	GB_SMD_ElementShowInfoStr    ShowInfo={0};

	GB_SMD_GetCachDataByIndex(m_index, &Cach_Type, &nId);//获取nId
	GB_SMD_GetCachShowDataByIndex(m_index, &ShowInfo);
	setSize(VfxSize(LCD_WIDTH, GB_WG_LIST_HEIGHT));

	// icon
	VFX_OBJ_CREATE(pContentIcon, VfxImageFrame, this);
	xgap = GB_WG_LIST_MARGIN;
	ygap = GB_WG_LIST_MARGIN;
	x = xgap;
	y = ygap;
	pContentIcon->setMem(ShowInfo.pimg);

	//电话本和通话记录的的图片比较小，调节中间位置显示
	if (pContentIcon->getSize().width < GB_WG_LIST_APPICON_SIZE)
	{
		x = xgap*2;
		y = ygap*2;
	}
	if (pContentIcon->getSize().width > GB_WG_LIST_APPICON_SIZE)
	{
		pContentIcon->setSize(GB_WG_LIST_APPICON_SIZE, GB_WG_LIST_APPICON_SIZE);
	}
	pContentIcon->setPos(x, y);

	//创建一个联系人多个号码的图标
	if (GB_SMD_PhoneNumGetCountById(nId) > 1 && Cach_Type == GBMD_CachType_PhoneBook)	
	{
		x = getSize().width - xgap*4;
		y = ygap*2;
		VFX_OBJ_CREATE(pContentIconFlag, VfxImageFrame, this);
		pContentIconFlag->setPos(x, y);
		pContentIconFlag->setResId(IMG_WG_WINGUO_SKIN_LIST_NORMAL_FLAG);
	}

	//创建一个方框用来放置text1和text2
	x = GB_WG_LIST_APPICON_SIZE + xgap*2;
	y = getSize().height*1/5;
	VFX_OBJ_CREATE(Frame, VfxFrame, this);
	Frame->setPos(x, y);
	Frame->setSize(getSize().width - xgap*6 - x, getSize().height*3/5);
	Frame->setAnchor(0, 0);
	//Frame->setBgColor(VFX_COLOR_YELLOW);

	//创建下标字符串内容
	VfxFontDesc fontDesc; //字体 

	// text1
	VFX_OBJ_CREATE(m_pAppName1, VfxTextFrame, Frame);
	VFX_OBJ_CREATE(m_pAppName2, VfxTextFrame, Frame); 
	VFX_OBJ_CREATE(m_pAppName3, VfxTextFrame, Frame);

	//text2
	VFX_OBJ_CREATE(m_StringFlag1, VfxTextFrame, Frame);
	VFX_OBJ_CREATE(m_StringFlag2, VfxTextFrame, Frame);
	VFX_OBJ_CREATE(m_StringFlag3, VfxTextFrame, Frame);

	// 第一行
	{
		//x = GB_WG_LIST_APPICON_SIZE + xgap*2;
		//y = getSize().height*1/5;
		fontDesc.size = VFX_FONT_DESC_VF_SIZE(GB_WG_LIST_APP_NAME_SIZE);

		m_pAppName1->setPos(0, 0); 
		m_pAppName1->setFont(fontDesc);
		m_pAppName1->setColor(GB_WG_GREY);
		if (*ShowInfo.subject.InfoString == '\0')
		{
			m_pAppName1->setString(VFX_WSTR_RES(STR_GB_WINGUO_UNNAMED));
		}
		else
		{
			m_pAppName1->setString(ShowInfo.subject.InfoString);
		}
		if (ShowInfo.subject.nHighlightLen == 0)
		{
			if (m_pAppName1->getSize().width > Frame->getSize().width)
			{
				m_pAppName1->setSize(Frame->getSize().width, m_pAppName1->getSize().height); 
				m_pAppName1->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);//设置文本对齐方式
				m_pAppName1->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);//添加截断字符串的结束失踪文本。
			}
		}
		
		if (ShowInfo.subject.nHighlightLen > 0)
		{
			Str1Len = ShowInfo.subject.pHighlightStart - ShowInfo.subject.InfoString;
			Str1Len = GB_MIN(GB_SMD_INFOSTING_MAXLEN, Str1Len);
			//ASSERT(Str1Len >= 0 && Str1Len <= GB_SMD_INFOSTING_MAXLEN);
 			if (Str1Len > 0)
 			{
				VFX_ALLOC_MEM(pTempStr1, (Str1Len+1)*sizeof(*pTempStr1), this);//  [10/24/2012 Liyong]字符串以\0结尾要加1（勿忘\0的长度）
				memset(pTempStr1, 0, (Str1Len+1)*sizeof(*pTempStr1));
				gb_wg_wcsncpy(pTempStr1, ShowInfo.subject.InfoString, Str1Len);
				m_pAppName1->setString(pTempStr1);
				VFX_FREE_MEM(pTempStr1);
				if (m_pAppName1->getSize().width > Frame->getSize().width)
				{
					m_pAppName1->setSize(Frame->getSize().width, m_pAppName1->getSize().height); 
					m_pAppName1->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);//设置文本对齐方式
					m_pAppName1->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);//添加截断字符串的结束失踪文本。
				}
			}
			else
			{
				m_pAppName1->setString(NULL);
			}

 			m_pAppName2->setPos(m_pAppName1->getSize().width, 0);
			m_pAppName2->setFont(fontDesc);
			m_pAppName2->setColor(GB_WG_BLUE);
			Str2Len = ShowInfo.subject.nHighlightLen;
			VFX_ALLOC_MEM(pTempStr2, (Str2Len+1)*sizeof(*pTempStr2), this);
			memset(pTempStr2, 0, (Str2Len+1)*sizeof(*pTempStr2));
			gb_wg_wcsncpy(pTempStr2, ShowInfo.subject.pHighlightStart, Str2Len);
			m_pAppName2->setString(pTempStr2);
			VFX_FREE_MEM(pTempStr2);
			if (m_pAppName2->getSize().width > Frame->getSize().width - m_pAppName1->getSize().width)
			{
				m_pAppName2->setSize(Frame->getSize().width - m_pAppName1->getSize().width, m_pAppName2->getSize().height); 
				m_pAppName2->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);//设置文本对齐方式
				m_pAppName2->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);//添加截断字符串的结束失踪文本。
			}

 			m_pAppName3->setPos(m_pAppName1->getSize().width + m_pAppName2->getSize().width, 0);
			m_pAppName3->setFont(fontDesc);
			m_pAppName3->setColor(GB_WG_GREY);
			Str3Len = (ShowInfo.subject.InfoString + gb_wg_wcslen(ShowInfo.subject.InfoString)) 
						- (ShowInfo.subject.InfoString + ShowInfo.subject.nHighlightLen);
			if (Str3Len > 0)
			{
				VFX_ALLOC_MEM(pTempStr3, (Str3Len+1)*sizeof(*pTempStr3), this);
				memset(pTempStr3, 0, (Str3Len+1)*sizeof(*pTempStr3));
				gb_wg_wcsncpy(pTempStr3, ShowInfo.subject.pHighlightStart + ShowInfo.subject.nHighlightLen, Str3Len);
				m_pAppName3->setString(pTempStr3);
				VFX_FREE_MEM(pTempStr3);
				if (m_pAppName3->getSize().width > Frame->getSize().width - m_pAppName1->getSize().width - m_pAppName2->getSize().width)
				{
					m_pAppName3->setSize(Frame->getSize().width - m_pAppName1->getSize().width - m_pAppName2->getSize().width, m_pAppName3->getSize().height); 
					m_pAppName3->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);//设置文本对齐方式
					m_pAppName3->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);//添加截断字符串的结束失踪文本。
				}
			}
		}

	}
	// 第二行
	{
		//x = GB_WG_LIST_APPICON_SIZE + xgap*2;
		y = Frame->getSize().height*3/5;
		fontDesc.size = VFX_FONT_DESC_VF_SIZE(GB_WG_LIST_APP_FLAG_NAME_SIZE);

		m_StringFlag1->setPos(0, y);
		m_StringFlag1->setFont(fontDesc);
		m_StringFlag1->setColor(GB_WG_GREY);

		if (*ShowInfo.explain.InfoString == '\0')
		{
			m_StringFlag1->setString(VFX_WSTR_RES(STR_GB_WINGUO_NO_NUMBER));
		}
		else
		{
			m_StringFlag1->setString(ShowInfo.explain.InfoString);
		}
		
		if (ShowInfo.explain.nHighlightLen == 0)
		{
			if (m_StringFlag1->getSize().width > Frame->getSize().width)
			{
				m_StringFlag1->setSize(Frame->getSize().width, m_StringFlag1->getSize().height); 
				m_StringFlag1->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);//设置文本对齐方式
				m_StringFlag1->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);//添加截断字符串的结束失踪文本。
			}
		}

		if (ShowInfo.explain.nHighlightLen > 0)
		{
			Str1Len = ShowInfo.explain.pHighlightStart - ShowInfo.explain.InfoString;
			Str1Len = GB_MIN(GB_SMD_INFOSTING_MAXLEN, Str1Len);
			//ASSERT(Str1Len >= 0 && Str1Len <= GB_SMD_INFOSTING_MAXLEN);
			if (Str1Len > 0)
			{
				VFX_ALLOC_MEM(pTempStr1, (Str1Len+1)*sizeof(*pTempStr1), this);
				memset(pTempStr1, 0, (Str1Len+1)*sizeof(*pTempStr1));
				gb_wg_wcsncpy(pTempStr1, ShowInfo.explain.InfoString, Str1Len);
				m_StringFlag1->setString(pTempStr1);
				VFX_FREE_MEM(pTempStr1);
				if (m_StringFlag1->getSize().width > Frame->getSize().width)
				{
					m_StringFlag1->setSize(Frame->getSize().width, m_StringFlag1->getSize().height); 
					m_StringFlag1->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);//设置文本对齐方式
					m_StringFlag1->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);//添加截断字符串的结束失踪文本。
				}
			}
			else
			{
				m_StringFlag1->setString(NULL);
			}

			m_StringFlag2->setPos(m_StringFlag1->getSize().width, y);
			m_StringFlag2->setFont(fontDesc);
			m_StringFlag2->setColor(GB_WG_BLUE);
			Str2Len = ShowInfo.explain.nHighlightLen;
			VFX_ALLOC_MEM(pTempStr2, (Str2Len+1)*sizeof(*pTempStr2), this);
			memset(pTempStr2, 0, (Str2Len+1)*sizeof(*pTempStr2));
			gb_wg_wcsncpy(pTempStr2, ShowInfo.explain.pHighlightStart, Str2Len);
			m_StringFlag2->setString(pTempStr2);
			VFX_FREE_MEM(pTempStr2);
			if (m_StringFlag2->getSize().width > Frame->getSize().width - m_StringFlag1->getSize().width)
			{
				m_StringFlag2->setSize(Frame->getSize().width - m_StringFlag1->getSize().width, m_StringFlag2->getSize().height); 
				m_StringFlag2->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);//设置文本对齐方式
				m_StringFlag2->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);//添加截断字符串的结束失踪文本。
			}

			m_StringFlag3->setPos(m_StringFlag1->getSize().width + m_StringFlag2->getSize().width, y);
			m_StringFlag3->setFont(fontDesc);
			m_StringFlag3->setColor(GB_WG_GREY);
			Str3Len = (ShowInfo.explain.InfoString + gb_wg_wcslen(ShowInfo.explain.InfoString)) 
				- (ShowInfo.explain.InfoString + ShowInfo.explain.nHighlightLen);
			if (Str3Len > 0)
			{
				VFX_ALLOC_MEM(pTempStr3, (Str3Len+1)*sizeof(*pTempStr3), this);
				memset(pTempStr3, 0, (Str3Len+1)*sizeof(*pTempStr3));
				gb_wg_wcsncpy(pTempStr3, ShowInfo.explain.pHighlightStart + ShowInfo.explain.nHighlightLen, Str3Len);
				m_StringFlag3->setString(pTempStr3);
				VFX_FREE_MEM(pTempStr3);
				if (m_StringFlag3->getSize().width > Frame->getSize().width - m_StringFlag1->getSize().width - m_StringFlag2->getSize().width)
				{
					m_StringFlag3->setSize(Frame->getSize().width - m_StringFlag1->getSize().width  - m_StringFlag2->getSize().width, m_StringFlag3->getSize().height); 
					m_StringFlag3->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);//设置文本对齐方式
					m_StringFlag3->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);//添加截断字符串的结束失踪文本。
				}
			}
		}
	}

}

GB_VOID WinguoSmartDialListContent::onCloseElements()
{
	VFX_OBJ_CLOSE(pContentIcon);
	VFX_OBJ_CLOSE(m_pAppName1);
	VFX_OBJ_CLOSE(m_pAppName2);
	VFX_OBJ_CLOSE(m_pAppName3);
	VFX_OBJ_CLOSE(m_StringFlag1);
	VFX_OBJ_CLOSE(m_StringFlag2);
	VFX_OBJ_CLOSE(m_StringFlag3);
	VFX_OBJ_CLOSE(Frame);

	if (pContentIconFlag)
	{
		VFX_OBJ_CLOSE(pContentIconFlag);
	}
}

GB_VOID WinguoSmartDialListContent::onLayoutElements()
{

}

GB_VOID WinguoSmartDialListContent::onUpdateElements()
{               

}

VfxBool WinguoSmartDialListMenuContentProvider::getMenuEmptyText(
	VfxWString &text,                // [OUT] the text resource
	VcpListMenuTextColorEnum &color  // [OUT] the text color
	)
{
	if (0 < gb_wg_wcslen(TextBuff) && 0 == GB_WG_SMD_List_Get_InputStr_Data(TextBuff))
	{
		text = VFX_WSTR_RES(STR_GB_WINGUO_NOCONTENT);//无匹配内容
		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
	}
	else
	{
		text = VFX_WSTR_RES(STR_GB_WINGUO_NOAPPLICATION);//无应用记录
		color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
	}
	return GB_TRUE;
}

#endif /*#ifdef __MMI_GB_WINGUO_V2__*/