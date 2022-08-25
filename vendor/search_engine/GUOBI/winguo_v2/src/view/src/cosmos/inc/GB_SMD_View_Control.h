#ifndef __GB_SMD_VIEW_CONTROL_H__
#define __GB_SMD_VIEW_CONTROL_H__

#include "GB_SMD_View_List.h"

class WinguoSMDBaseControlClass : public VfxFrame
{
	VFX_DECLARE_CLASS(WinguoSMDBaseControlClass);
public:
	WinguoSMDBaseControlClass();

public:
	virtual void onInit();
	virtual void onDeinit();

//控件的成员变量
private:
	VcpTextEditor     *m_textEditor;   //文本输入框
	VcpButton		  *m_imageButton;   //按钮

public:
	VcpTextEditor* getTextEditor();
	void setTextEditor(VfxFrame *pFrame);
	VcpButton* getImageButton();
	void setImageButton(VfxFrame *pFrame);
public:
	enum
	{
		TEXT_EDITOR_POS_X	       = 10,
		TEXT_EDITOR_POS_Y	       = 6,
		TEXT_EDITOR_POS_WIDTH      = 254,
		TEXT_EDITOR_POS_HEIGHT     = 40,
		TEXT_ZISE                  = 20,
		TEXT_EDITOR_LEFT_MARGIN    = 4,
		TEXT_EDITOR_TOP_MARGIN     = 11,
		TEXT_EDITOR_RIGHT_MARGIN   = 0,
		TEXT_EDITOR_BOTTOM_MARGIN  = 0,
		BUTTON_POS_X		       = 291,
		BUTTON_POS_Y		       = 25,
		BUTTON_POS_WIDTH	       = 40,
		BUTTON_POS_HEIGHT	       = 40,
	};
	
};

#endif /*__GB_SMD_VIEW_CONTROL_H__*/