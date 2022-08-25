/*================================================================
*
* 文 件 名：GB_SMD_View_Control.cpp
*
* 
* 文件描述：创建实现Control基类
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

#include "inc\GB_SMD_View_Control.h"

VFX_IMPLEMENT_CLASS("WinguoSMDBaseControlClass", WinguoSMDBaseControlClass, VfxFrame);
WinguoSMDBaseControlClass::WinguoSMDBaseControlClass():
m_textEditor(NULL),
m_imageButton(NULL)
{

}

void WinguoSMDBaseControlClass::onInit()
{
	VfxFrame::onInit();
}

void WinguoSMDBaseControlClass::onDeinit()
{
	if (m_textEditor)
	{
		VFX_OBJ_CLOSE(m_textEditor);
		m_textEditor = NULL;
	}

	if (m_imageButton)
	{
		VFX_OBJ_CLOSE(m_imageButton);
		m_imageButton = NULL;
	}
	VfxFrame::onDeinit();
}

VcpTextEditor* WinguoSMDBaseControlClass::getTextEditor()
{
	if (m_textEditor)
	{
		return m_textEditor;
	}
	return NULL;
}

void WinguoSMDBaseControlClass::setTextEditor(VfxFrame *pFrame)
{
	if (m_textEditor == NULL)
	{
		VFX_OBJ_CREATE(m_textEditor, VcpTextEditor, pFrame);
	}
}

VcpButton* WinguoSMDBaseControlClass::getImageButton()
{
	if (m_imageButton)
	{
		return m_imageButton;
	}
	return NULL;
}

void WinguoSMDBaseControlClass::setImageButton(VfxFrame *pFrame)
{
	if (m_imageButton == NULL)
	{
		VFX_OBJ_CREATE(m_imageButton, VcpButton, pFrame);
	}
}

#endif /*#ifdef __MMI_GB_WINGUO_V2__*/

