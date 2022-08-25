/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
*
* Filename:
* ---------
*   tst_venus_framework.cpp
*
* Project:
* -------- 
*   MAUI
*
* Description:
* ------------
*   3rd Party Integration Development Environment
*
* Author:
* -------
* -------
*
*============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*------------------------------------------------------------------------------
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__








#ifdef __VENUS_UI_ENGINE__

#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vcp_status_icon_bar.h"
#include "vcp_page_panel.h"
#include "vcp_list_menu.h"
#include "vcp_popup.h"
#include "vcp_image_button.h"
#include "vfx_pen.h"
#include "vfx_owner_draw.h"
#include "vfx_rect_frame.h"
#include "vfx_layer_control.h"
#include "mmi_rp_srv_venus_component_text_view_def.h"
#include "vcp_wheel_menu.h"


#endif

#ifdef __cplusplus
extern "C"
{
#endif




#include "GlobalResDef.h"
#include "AlertScreen.h"
#include "avk_fw_venus.h"


#ifdef __VENUS_UI_ENGINE__


	class TestBaseClass : public VfxAppCatScr
	{

	public:
		VfxTextFrame* m_message;
		VfxTextFrame* m_yes;
		VfxTextFrame* m_no;

		VfxWString m_wstrCaseName;
		int m_item_idx;

		virtual void startTest(VfxWString wstrCaseName,int item_idx)
		{
			m_wstrCaseName = wstrCaseName;
			m_item_idx = item_idx;
		}


		TestBaseClass()
		{


			m_message = NULL;
			m_yes = NULL;
			m_no = NULL;
		}



		void layout()
		{
			VfxSize scrSize = getSize();
			if (m_message != NULL)
			{
				m_message->setPos(0, scrSize.height - 60);
				m_message->setSize(scrSize.width, 40);
			}

			if (m_yes != NULL)
			{
				m_yes->setPos(10, scrSize.height - 20);    
			}

			if (m_no != NULL)
			{
				m_no->setPos(3 * (scrSize.width / 4), scrSize.height - 20);
			}
		}
		void confirm(const VfxWString &message)
		{
			if (m_message == NULL)
			{
				VFX_OBJ_CREATE(m_message, VfxTextFrame, this);
				m_message->setAutoResized(VFX_FALSE);
				m_message->setColor(VFX_COLOR_BLACK);
				VfxColor a = m_message->getColor();
				VfxColor b = VFX_COLOR_BLACK;
				VFX_ASSERT(a == b);
				m_message->setBgColor(VFX_COLOR_GREY);
				m_message->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
				m_message->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
				m_message->setFont(VFX_FONT_DESC_SMALL);
				m_message->setAutoAnimate(VFX_TRUE);
			}    
			m_message->setString(message);
			VfxWString a = m_message->getString();

			VFX_ASSERT(a == message);

			if (m_yes == NULL)
			{
				VFX_OBJ_CREATE(m_yes, VfxTextFrame, this);
				m_yes->setColor(VFX_COLOR_BLACK);
				m_yes->setBgColor(VFX_COLOR_GREY);
				m_yes->setString(VFX_WSTR("YES"));
				m_yes->setAutoAnimate(VFX_TRUE);
				//
				m_yes->setBorderColor(m_yes->getBorderColor());
				m_yes->setLineMode(m_yes->getLineMode());
				m_yes->setMinLineHeight(0);
				m_yes->setFullLineHeightMode(VFX_FALSE);
				m_yes->getLineCount();
				m_yes->getAutoFontResized();
				m_yes->setIndent(0);
				m_yes->setLineGap(1);
				m_yes->setVerticalToCenter(VFX_FALSE);
				//
			}

			if (m_no == NULL)
			{
				VFX_OBJ_CREATE(m_no, VfxTextFrame, this);
				//m_no->setAutoFontSize(VFX_FALSE);
				//VFX_ASSERT(VFX_FALSE == m_no->getAutoFontResized());
				m_no->setColor(VFX_COLOR_BLACK);
				m_no->setBgColor(VFX_COLOR_GREY);
				m_no->setString(VFX_WSTR("NO"));
				m_no->setAutoAnimate(VFX_TRUE);
				VfxAutoAnimate::initAnimateBegin();

				VfxAutoAnimate::initAnimateEnd();
			}

			layout();
		}

	public:
		void onYes()
		{
			//vs_tfw_trace_result((U16*)(m_wstrCaseName.getBuf()), MMI_TRUE, 0, VS_TA_FW_VENUS);
			//vs_tfw_finish_case_extern((vs_test_item_enum)m_item_idx, 12345);

			//GO BACK HISTORY
			//AVK_CASE_RESULT(AVK_PASS)
			//AVK_ASYN_DONE

			GoBackHistory();
			AVK_CASE_RESULT(AVK_PASS);
			AVK_ASYN_DONE();
		}
		void onNo()
		{
			//vs_tfw_trace_result((U16*)(m_wstrCaseName.getBuf()), MMI_FALSE, 0, VS_TA_FW_VENUS);
			//vs_tfw_finish_case_extern((vs_test_item_enum)m_item_idx, 12345);
			GoBackHistory();
			AVK_CASE_RESULT(AVK_FAIL);
			AVK_ASYN_DONE();
		}
	protected:
		
		
		// While the LCD screen has been rotate
		virtual void onRotate(
			const VfxScreenRotateParam &param // The parameter to rotate
		)
		{
			VfxScrRotateTypeEnum rotateFrom = param.rotateFrom;
			VfxScrRotateTypeEnum rotateTo = param.rotateTo;
			VfxMsec durTime = param.durTime;
			rotateFrom = rotateFrom;
			rotateTo = rotateTo;
			durTime= durTime;
			VfxAppCatScr::onRotate(param);
		
		}

	    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
	    {
			param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
	    }

        virtual void onInit()
		{
			VfxAppCatScr::onInit();
			setBgColor(VFX_COLOR_BLACK);
			registerKeyHandler(VFX_KEY_CODE_LSK);
			registerKeyHandler(VFX_KEY_CODE_RSK);
		}

		VfxBool onPenInput(VfxPenEvent &event)
		{
			if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
			{
	            VfxPen *penSrv = VFX_OBJ_GET_INSTANCE(VfxPen);
	            //penSrv->delayEvent(this, event);
				
				//penSrv->resumeDelayedEvent();
				VfxPoint point = convertPointTo(event.pos, m_yes);
				//
				VfxPoint point1 = convertPointFrom(point, m_yes);
				VfxPoint p0 = forceGetPos();
				VfxRect r0 =  forceGetBounds();
				VfxFloat o0 = forceGetOpacity();
				VfxFPoint anchor = forceGetAnchor();
				VfxColor c0 = forceGetBgColor();
				VfxColor bc0 = forceGetBorderColor();
				VfxS32 bw0 = forceGetBorderWidth();
				VfxFloat filterTiming = forceGetFilterTiming();
				VfxFloat fpeuser0 = forceGetFpeUser0();
				VfxTransform transform = forceGetTransform();
				//
				if (m_yes->getBounds().contains(point))
				{
					//PASS
					vfxPostInvoke0(this,&TestBaseClass::onYes);

					return VFX_TRUE;
				}
				if(event.pos.x>=0 &&event.pos.x<UI_device_width/2)
				{
					vfxPostInvoke0(this,&TestBaseClass::onYes);

					return VFX_TRUE;
				}

				point = convertPointTo(event.pos, m_no);
				if (m_no->getBounds().contains(point))
				{
					//FAIL
					vfxPostInvoke0(this,&TestBaseClass::onNo);
					return VFX_TRUE;
				}

				if(event.pos.x>UI_device_width/2 &&event.pos.x<UI_device_width)
				{
					vfxPostInvoke0(this,&TestBaseClass::onNo);

					return VFX_TRUE;
				}
			}

			return VfxAppCatScr::onPenInput(event);
		}



	protected:
		VfxBool onKeyInput(VfxKeyEvent &event)
		{

			if (event.keyCode == VFX_KEY_CODE_LSK && event.type == VFX_KEY_EVENT_TYPE_UP)
			{
				vfxPostInvoke0(this,&TestBaseClass::onYes);

				return VFX_TRUE;
			}
			else if (event.keyCode == VFX_KEY_CODE_RSK && event.type == VFX_KEY_EVENT_TYPE_UP)
			{
				vfxPostInvoke0(this,&TestBaseClass::onNo);

				return VFX_TRUE;
			}
			else
			{

				return VfxAppCatScr::onKeyInput(event);
			}
		}

		virtual void onEnter(
			VfxBool isBackward
			)
		{

		}


		virtual void onExit(
			VfxBool isBackward
			)
		{

		}

		virtual void onFocusChanged(VfxBool value)
		{

			VfxAppCatScr::onFocusChanged(value);

		}
	};




	class VTestPME: public TestBaseClass
	{

	public:
		void startTest(VfxWString wstrCaseName,int item_idx) 
		{
			TestBaseClass::startTest(wstrCaseName, item_idx);
			TestVfxCallback();
			TestVfxSignal();
			TestWeakPtr();
			TestPMEFunction();
			confirm(VFX_WSTR("Already Done,Press Yes"));
		}

		void TestVfxCallback() //0
		{
			VfxCallback0 tmp0(this, &VTestPME::OnVfxCallback0);
			VfxCallback0 tmp00 = tmp0;
			tmp0.invoke();

			VfxCallback1<VfxS32> tmp1(this, &VTestPME::OnVfxCallback1);
			VfxCallback1<VfxS32> tmp11= tmp1;
			tmp1.invoke(100);

			VfxCallback2<VfxS32,VfxS32> tmp2(this, &VTestPME::OnVfxCallback2);
			VfxCallback2<VfxS32,VfxS32> tmp22 = tmp2;
			tmp2.invoke(100,100);

			VfxCallback3<VfxS32,VfxS32,VfxS32> tmp3(this, &VTestPME::OnVfxCallback3);
			VfxCallback3<VfxS32,VfxS32,VfxS32> tmp33 = tmp3;
			tmp3.invoke(100,100,100);

			VfxCallback4<VfxS32,VfxS32,VfxS32,VfxS32> tmp4(this, &VTestPME::OnVfxCallback4);
			VfxCallback4<VfxS32,VfxS32,VfxS32,VfxS32> tmp44 = tmp4;
			tmp4.invoke(100,100,100,100);
		}
		void TestVfxSignal() //1
		{
			VfxSignal0  m_signal0;
			m_signal0.connect(this, &VTestPME::OnVfxSignal0);
			m_signal0.emit();
			m_signal0.postEmit();
			m_signal0.disconnect(this, &VTestPME::OnVfxSignal0);

			VfxSignal1<VfxS32>  m_signal1;
			m_signal1.connect(this, &VTestPME::OnVfxSignal1);
			m_signal1.emit(100);
			m_signal1.postEmit(100);
			m_signal1.disconnect(this, &VTestPME::OnVfxSignal1);

			VfxSignal2<VfxS32,VfxS32>  m_signal2;
			m_signal2.connect(this, &VTestPME::OnVfxSignal2);
			m_signal2.emit(100,100);
			m_signal2.postEmit(100,100);
			m_signal2.disconnect(this, &VTestPME::OnVfxSignal2);

			VfxSignal3<VfxS32,VfxS32,VfxS32>  m_signal3;
			m_signal3.connect(this, &VTestPME::OnVfxSignal3);
			m_signal3.emit(100,100,100);
			m_signal3.postEmit(100,100,100);
			m_signal3.disconnect(this, &VTestPME::OnVfxSignal3);

			VfxSignal4<VfxS32,VfxS32,VfxS32,VfxS32>  m_signal4;
			m_signal4.connect(this, &VTestPME::OnVfxSignal4);
			m_signal4.emit(100,100,100,100);
			m_signal4.postEmit(100,100,100,100);
			m_signal4.disconnect(this, &VTestPME::OnVfxSignal4);

		}
		void TestWeakPtr() //2
		{
			VfxTextFrame    *test;
			VfxTextFrame    *m_test;
			VfxWeakPtr <VfxTextFrame> m_weakptr_test;
			VFX_OBJ_CREATE(test, VfxTextFrame, this);
			VfxWeakPtr <VfxTextFrame> weakptr_test = test;
			VFX_ASSERT(weakptr_test == test);
			VFX_ASSERT(!(weakptr_test != test));
			VFX_OBJ_CLOSE(test);

			VFX_OBJ_CREATE(m_test, VfxTextFrame, this);
			m_weakptr_test = m_test;
			VfxWeakPtr <VfxTextFrame> aaa = m_weakptr_test;
			VFX_ASSERT(aaa == m_weakptr_test);
			VFX_ASSERT(!(aaa != m_weakptr_test));
			VFX_OBJ_CLOSE(m_test);
		}

		void TestPMEFunction()
		{
			vfxPostInvoke0(this, &VTestPME::OnVfxCallback0);
			vfxPostInvoke1(this, &VTestPME::OnVfxCallback1,100);
			vfxPostInvoke2(this, &VTestPME::OnVfxCallback2,100,100);		
			vfxPostInvoke3(this, &VTestPME::OnVfxCallback3,100,100,100);
			vfxPostInvoke4(this, &VTestPME::OnVfxCallback4,100,100,100,100);
		}


		void OnVfxCallback0()
		{
		}
		void OnVfxCallback1(VfxS32 a)
		{
			VFX_ASSERT(a ==100);
		}
		void OnVfxCallback2(VfxS32 a,VfxS32 b)
		{
			VFX_ASSERT(a ==100 && b ==100);

		}
		void OnVfxCallback3(VfxS32 a,VfxS32 b,VfxS32 c)
		{
			VFX_ASSERT(a ==100 && b ==100 && c==100);
		}
		void OnVfxCallback4(VfxS32 a,VfxS32 b, VfxS32 c,VfxS32 d)
		{
			VFX_ASSERT(a ==100 && b ==100 && c==100 && d ==100);
		}


		void OnVfxSignal0()
		{
		}
		void OnVfxSignal1(VfxS32 a)
		{
			VFX_ASSERT(a ==100);
		}
		void OnVfxSignal2(VfxS32 a,VfxS32 b)
		{
			VFX_ASSERT(a ==100 && b ==100);
		}
		void OnVfxSignal3(VfxS32 a,VfxS32 b,VfxS32 c)
		{
			VFX_ASSERT(a ==100 && b ==100 && c==100);
		}
		void OnVfxSignal4(VfxS32 a,VfxS32 b, VfxS32 c,VfxS32 d)
		{
			VFX_ASSERT(a ==100 && b ==100 && c==100 && d ==100);
		}

	};




	class VTestVfxAnimation: public TestBaseClass
	{
	public:

		void startTest(VfxWString wstrCaseName,int item_idx) 
		{
			TestBaseClass::startTest(wstrCaseName, item_idx);
			TestVfxAnimation();
			confirm(VFX_WSTR("see animation?"));
		}
		void TestVfxAnimation()//3
		{
			VfxAnimation* m_animation;
			VfxFrame *m_controlRect;

			VFX_OBJ_CREATE(m_controlRect, VfxFrame, this);
			m_controlRect->setPos(VfxPoint(120, 100));
			m_controlRect->setBounds(VfxRect(0, 0, 100, 100));
			m_controlRect->setAnchor(VfxFPoint(0.5, 0.5));
			m_controlRect->setBgColor(VFX_COLOR_RED);
			m_controlRect->setAutoAnimate(VFX_TRUE); 
			VfxBool bAuto = m_controlRect->getAutoAnimate();
			VFX_ASSERT(bAuto == VFX_TRUE);
			m_controlRect->setIsUnhittable(VFX_TRUE);
			VfxBool bh = m_controlRect->getIsUnhittable();
			VFX_ASSERT(bAuto == VFX_TRUE);

			m_controlRect->setQuality(VFX_RENDER_QUALITY_NORMAL);

			VFX_ASSERT(m_controlRect->getQuality()==VFX_RENDER_QUALITY_NORMAL);
			VfxColor c00 = VFX_COLOR_BLUE;
			m_controlRect->setBorderColor(c00);
			VFX_ASSERT(m_controlRect->getBorderColor() == c00);

			m_controlRect->setBorderWidth(1);
			VFX_ASSERT(m_controlRect->getBorderWidth() == 1);
			m_controlRect->setFilter(NULL);
			VFX_ASSERT(m_controlRect->getFilter() == NULL);

			m_controlRect->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RIGHT);
			VFX_ASSERT(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RIGHT ==m_controlRect->getContentPlacement() );
			m_controlRect->setOwnerDraw(NULL); 
			VFX_ASSERT(NULL == m_controlRect->getOwnerDraw());

			m_controlRect->setFilterTiming(2.2f);
			VFX_ASSERT(m_controlRect->getFilterTiming() == 2.2f);

			m_controlRect->setFpeUser0(0.123f);
			VFX_ASSERT(m_controlRect->getFpeUser0() == 0.123f);

			m_controlRect->setHidden(VFX_FALSE);
			VFX_ASSERT(VFX_FALSE == m_controlRect->getHidden());
			m_controlRect->setIsUnhittable(VFX_FALSE);
			VFX_ASSERT(VFX_FALSE ==m_controlRect->getIsUnhittable() );

			m_controlRect->setHints(VFX_FRAME_HINTS_DEFAULT);
			VFX_ASSERT(m_controlRect->getHints() == VFX_FRAME_HINTS_DEFAULT);

			VfxTransform t;
			t.setIdentity();
			t.data.affine.rz = VFX_DEG_TO_RAD(20);
			m_controlRect->setTransform(t);
			VFX_ASSERT(m_controlRect->getTransform() == t);

			//
			m_controlRect->setPosZ(m_controlRect->getPosZ());
			m_controlRect->getOpacity();
			m_controlRect->setImgContent(m_controlRect->getImgContent());
			m_controlRect->getIsOpaque();
			m_controlRect->getIsCached();
			m_controlRect->setCacheMode(m_controlRect->getCacheMode());
			m_controlRect->setOpaqueMode(m_controlRect->getOpaqueMode());
			m_controlRect->setCullingType(m_controlRect->getCullingType());
			m_controlRect->getIsZSortChild();
			m_controlRect->getParentFrame();

			m_controlRect->containPoint(VfxPoint(0,0));
			m_controlRect->getSize();
			m_controlRect->getRect();
			m_controlRect->hitTest(VfxPoint(0,0));
			m_controlRect->invalidate();
			//

			VFX_OBJ_CREATE(m_animation, VfxAnimation, this);

			VfxFloatTimeline *timeline1;
			VFX_OBJ_CREATE(timeline1, VfxFloatTimeline, m_animation);
			timeline1->setTarget(m_controlRect);
			timeline1->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
			timeline1->setFromValue(1.0f);
			timeline1->setToValue(0.0f);
			timeline1->setDurationTime(2000);
			timeline1->setRepeatCount(1000);
			timeline1->setAutoReversed(VFX_TRUE);
			m_animation->start();
		}
	};


	class VTestVfxFPointTimeline: public TestBaseClass
	{
	public:

		void onCJLStart(VfxBaseTimeline *timeline)
		{


		}
		void onCJLStop(VfxBaseTimeline *timeline, VfxBool isCompleted)
		{

		}

		void startTest(VfxWString wstrCaseName,int item_idx) 
		{
			TestBaseClass::startTest(wstrCaseName, item_idx);

			VfxFrame *m_controlRect;
			VFX_OBJ_CREATE(m_controlRect, VfxFrame, this);
			m_controlRect->setPos(VfxPoint(120, 100));
			VfxRect rect1(0, 0, 100, 100);
			m_controlRect->setBounds(rect1);
			VFX_ASSERT(rect1 == m_controlRect->getBounds());
			VfxFPoint fp1(0.5, 0.5);
			m_controlRect->setAnchor(fp1);
			VFX_ASSERT(fp1 == m_controlRect->getAnchor());
			m_controlRect->setBgColor(VFX_COLOR_RED);
			VFX_ASSERT(VFX_COLOR_RED == 	m_controlRect->getBgColor());
			m_controlRect->setAutoAnimate(VFX_TRUE); 
			VfxFPointTimeline* m_tlAnchor;
			VFX_OBJ_CREATE(m_tlAnchor, VfxFPointTimeline, this);     
			m_tlAnchor->getIsEnabled();
			m_tlAnchor->setStartDelay(0);
			m_tlAnchor->setIsFromCurrent(VFX_TRUE);
			m_tlAnchor->setFromValue(VfxFPoint(0.5, 0.5));
			m_tlAnchor->setToValue(VfxFPoint(0.8, 0.8));
			m_tlAnchor->setDurationTime(2000);
			m_tlAnchor->setDuration(2000);
			m_tlAnchor->setAutoReversed(VFX_TRUE);
			m_tlAnchor->setStartTime(200);
			m_tlAnchor->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
			m_tlAnchor->setTarget(m_controlRect);
			m_tlAnchor->getTarget();
			m_tlAnchor->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_ANCHOR_POINT);


			m_tlAnchor->m_signalStarted.connect(this, &VTestVfxFPointTimeline::onCJLStart);
			m_tlAnchor->m_signalStopped.connect(this, &VTestVfxFPointTimeline::onCJLStop); 
			m_tlAnchor->stop();
			m_tlAnchor->start();
			confirm(VFX_WSTR("see animation?"));
		}
	};


	class VTestVfxTransformTimeline : public TestBaseClass
	{
	public:
		VfxTimelineInterpolationRetEnum callback(
			void *output,
			const void *fromValue,
			const void *toValue,
			VfxTypeIdEnum typeId,
			VfxFloat t, 
			void *data,
			VfxU32 data_size)
		{

			return VFX_TIMELINE_INTERPOLATION_RET_DONE;

		}
		void startTest(VfxWString wstrCaseName,int item_idx) 
		{
			TestBaseClass::startTest(wstrCaseName, item_idx);

			VfxFrame *m_controlRect;
			VFX_OBJ_CREATE(m_controlRect, VfxFrame, this);
			m_controlRect->setPos(VfxPoint(120, 100));
			m_controlRect->setBounds(VfxRect(0, 0, 100, 100));
			m_controlRect->setAnchor(VfxFPoint(0.5, 0.5));
			m_controlRect->setBgColor(VFX_COLOR_RED);
			m_controlRect->setAutoAnimate(VFX_TRUE); 
			VfxTransform tempTransform;
			tempTransform.type = VFX_TRANSFORM_TYPE_AFFINE;       
			tempTransform.data.affine.sx = 0.9f;
			tempTransform.data.affine.sy = 0.9f;
			VfxTransformTimeline* m_smallTimeline;
			VFX_OBJ_CREATE(m_smallTimeline, VfxTransformTimeline, this);
			m_smallTimeline->setTarget(m_controlRect);
			m_smallTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
			m_smallTimeline->setDurationTime(2000);
			m_smallTimeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
			m_smallTimeline->setRepeatDuration(0);
			m_smallTimeline->setFromValue(VfxTransform());
			m_smallTimeline->setToValue(tempTransform);
			m_smallTimeline->setIsFromCurrent(VFX_FALSE);
			m_smallTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
			m_smallTimeline->getIsEnabled();



			m_smallTimeline->setCustomInterpolateFunc(NULL,0,0);
			m_smallTimeline->start();
			confirm(VFX_WSTR("see animation?"));

		}
	};


	class VTestVfxRectTimeline  : public TestBaseClass
	{
	public:
		void startTest(VfxWString wstrCaseName,int item_idx) 
		{
			TestBaseClass::startTest(wstrCaseName, item_idx);

			VfxFrame *m_controlRect;
			VFX_OBJ_CREATE(m_controlRect, VfxFrame, this);
			m_controlRect->setPos(VfxPoint(0, 0));
			m_controlRect->setBounds(VfxRect(0, 0, 100, 100));

			m_controlRect->setBgColor(VFX_COLOR_RED);
			m_controlRect->setAutoAnimate(VFX_TRUE); 

			VfxRect fromBounds = VfxRect(0, 0, 100, 100);
			VfxRect toBounds1 = VfxRect(0, 0, 100, 150);
			VfxRectTimeline* m_timeline2;
			VFX_OBJ_CREATE(m_timeline2, VfxRectTimeline, this);
			m_timeline2->setTarget(m_controlRect);
			m_timeline2->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BOUNDS);
			m_timeline2->setFromValue(fromBounds);
			m_timeline2->setToValue(toBounds1);
			m_timeline2->setDurationTime(2000);
			m_timeline2->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
			m_timeline2->setAutoReversed(VFX_FALSE);
			m_timeline2->start();
			confirm(VFX_WSTR("see animation?"));

		}
	};




	class VTestVfxTopLevel : public TestBaseClass
	{
	public:
		void startTest(VfxWString wstrCaseName,int item_idx) 
		{
			TestBaseClass::startTest(wstrCaseName, item_idx);
			VfxTopLevel* topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
			topLevel->enterToScreen(this);  
			VFX_ASSERT(topLevel->getActiveScr() == this);

			topLevel->setScreenRotateType(topLevel->getScreenRotateType());

			confirm(VFX_WSTR("Already Finished,Press YES"));
		}
	};




	class VfxCJLOwnerDraw:public VfxOwnerDraw
	{
	protected:	
		virtual void onInit()
		{
			VfxOwnerDraw::onInit();
			setResourceFromResId('CJL', IMG_GLOBAL_L1);

		}
		virtual void onDraw(VfxImageBuffer & dstBuffer, VfxRect & dstRect, VfxRect & srcRect)
		{

			VfxImageBuffer imgBuf;
			getResource('CJL', imgBuf);
		}
	};



	class VTestVfxImageFrame  : public TestBaseClass
	{
	public:
		VfxCJLOwnerDraw* m_pOwnerDraw;
		VfxImageFrame* m_imgBg;
		void startTest(VfxWString wstrCaseName,int item_idx) 
		{
			TestBaseClass::startTest(wstrCaseName, item_idx);

			VfxImageFrame *f1;
			VFX_OBJ_CREATE(f1, VfxImageFrame, this);


			f1->setResId(IMG_GLOBAL_L1);
			VFX_ASSERT(IMG_GLOBAL_L1 == f1->getResId());

			f1->setPos(VfxPoint(0, 0));


			VfxImageFrame *f2;
			VFX_OBJ_CREATE(f2, VfxImageFrame, this);
			VfxWString path = VFX_WSTR("E:\\SB_Default.gif");
			f2->setPath(path);
			VFX_ASSERT(path == f2->getPath());
			f2->setPos(VfxPoint(0, 100));



			VFX_OBJ_CREATE(m_imgBg, VfxImageFrame, this);
			m_imgBg->setIsOpaque(VFX_TRUE);


			m_imgBg->setSize(VfxSize(20,20));
			m_imgBg->setAutoAnimate(VFX_TRUE);




			VFX_OBJ_CREATE(m_pOwnerDraw, VfxCJLOwnerDraw, this);
			m_imgBg->setOwnerDraw(m_pOwnerDraw);


			//VfxImageFrame *f3;
			//VFX_OBJ_CREATE(f3, VfxImageFrame, this);
			//VfxImageSrc imagesrc(IMG_GLOBAL_L2);
			//f3->loadFromMem(imagesrc.getMem());
			//f3->setPos(VfxPoint(0, 200));

			confirm(VFX_WSTR("see image ?"));
		}
	};



	class VfxMyControlChild: public VfxControl
	{



	protected:

		virtual VfxBool onPenInput(
			VfxPenEvent &event         
			)
		{
			VfxPen *pen = VFX_OBJ_GET_INSTANCE(VfxPen);
			VfxPoint point = pen->getCurPenPos();
			VfxMsec time_0 = pen->getDownTimeStamp();
			VfxPoint point1 = pen->getDownPos();
			if(event.type != VFX_PEN_EVENT_TYPE_DOWN)
			{    	
				getParentControl()->capture();
			}

			return VFX_TRUE;

		}

		//virtual VfxBool onPenAbortAccepted(
		//	VfxControl * aborter, 
		//	VfxPenAbortReasonEnum reason
		//	)
		//{
		//	return VFX_FALSE;
		//}

	};

	class VfxMyControl: public VfxControl
	{
		virtual VfxBool onSerialize(
			VfxArchive &ar
			)
		{
			return VFX_TRUE;

		}


		virtual void onRestore(
			VfxArchive &ar
			)
		{
			//int i=0;
			//i = 0;
		}



		virtual VfxBool onKeyInput(
			VfxKeyEvent &event          
			)
		{
			return VFX_FALSE;
		}


		virtual void onUpdate() 
		{

		}

		virtual VfxBool onPenAbortAccepted(
			VfxControl * aborter, 
			VfxPenAbortReasonEnum reason
			)
		{
			return VFX_FALSE;
		}

	};
	class VTestVfxControl  : public TestBaseClass
	{
	public:
		VfxMyControl* m_pControl;
		VfxMyControlChild* m_pVfxMyControlChild;
		VfxFrame* m_pLastChild;

		void startTest(VfxWString wstrCaseName,int item_idx) 
		{
			TestBaseClass::startTest(wstrCaseName, item_idx);


			VFX_OBJ_CREATE(m_pControl, VfxMyControl, this);
			m_pControl->setIsDisabled(m_pControl->getIsDisabled());
			VFX_ASSERT(m_pControl->getParentControl() == this);
			VFX_ASSERT(m_pControl->findScreen() == this);
			VFX_ASSERT(m_pControl->getParentFrame()== this);

			m_pControl->setSize(240, 400);
			m_pControl->registerKeyHandler(VFX_KEY_CODE_CAMERA);
			m_pControl->checkUpdate();
			//			m_pControl->serialize();
			//			m_pControl->Restore(VfxArchive());
			//			m_pControl->processUpdate();

			VFX_OBJ_CREATE(m_pVfxMyControlChild, VfxMyControlChild, this);
			m_pVfxMyControlChild->setSize(240, 400);

			VFX_OBJ_CREATE(m_pLastChild, VfxFrame, this);
			m_pLastChild->setSize(240, 400);




			if(m_pControl->getParentControl()->getFirstChildFrame()->getNextFrame()->getPrevFrame() == m_pControl)
			{

			}


			VFX_ASSERT(m_pControl->getParentControl()->getLastChildFrame() == m_pLastChild);

			VfxFrame* p;
			VFX_OBJ_CREATE(p, VfxFrame, this);
			//p->setLayerHandle(p->getLayerHandle());
			p->setSize(240, 240);
			p->getPropertyEffectCallbackUserDataPtr();
			p->getPropertyEffectCallbackUserDataSize();
			p->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE);

			p->setAlignParent(VFX_FRAME_ALIGNER_SIDE_LEFT,VFX_FRAME_ALIGNER_MODE_SIDE);
			p->getImeMode();
			VfxKeypad::registerHandler(VFX_KEY_CODE_VOL_DOWN, this);
			VfxKeypad::unregisterHandler(VFX_KEY_CODE_VOL_DOWN, this);

			VfxFrame* p2222;
			VFX_OBJ_CREATE(p2222, VfxFrame, p);
			p2222->setSize(200, 200);
			if (p2222->getHandle() == NULL)
        	{
            //	p2222->processCreateHandle();
        	}
			
			m_pControl->getParentControl()->addChildFrame(p2222);

			if(m_pControl->getParentControl()->getLastChildFrame() == p2222)
			{

				p2222->removeFromParentFrame();
			}

			m_pControl->getParentControl()->insertChildFrameAfter(p, p2222);

			if(m_pControl->getParentControl()->getLastChildFrame() == p2222)
			{
				p2222->removeFromParentFrame();
			}


			m_pControl->getParentControl()->insertChildFrameBefore(m_pLastChild, p);
			if(m_pControl->getParentControl()->getLastChildFrame()->getPrevFrame() == p)
			{
				p->removeFromParentFrame();
			}


			m_pControl->getParentControl()->replaceChildFrameWith(m_pLastChild, p);
			m_pControl->getParentControl()->replaceChildFrameWith(p ,m_pLastChild );
			VFX_ASSERT(m_pControl->getParentControl()->getLastChildFrame() == m_pLastChild);

			m_pLastChild->bringToFront();

			m_pLastChild->sendToBack();

			VfxRectFrame* pRectFrame = NULL;

			VFX_OBJ_CREATE(pRectFrame, VfxRectFrame, this);
			pRectFrame->setFilledArea(NULL);
			VFX_OBJ_CLOSE(pRectFrame);


			confirm(VFX_WSTR("Already Finished,Press YES"));

		}
	};

	class Vfx_MyFrame :public VfxFrame
	{
	protected:
		void onParentFrameChanged(VfxFrame *origParentFrame)
		{
			return VfxFrame::onParentFrameChanged(origParentFrame);
		}
		virtual void onFocusChanged(VfxBool focused)
		{

		}
		virtual VfxBool onContainPoint(const VfxPoint & point) const
		{
			return VFX_TRUE;
		}
		virtual VfxBool onKeyInput(VfxKeyEvent & event)
		{
//			int i = 90;
//			i = 0;
			return VFX_FALSE;
		}
		virtual void onDraw(VfxDrawContext & dc)
		{
            dc.setFont(VFX_FONT_DESC_MEDIUM);
			dc.setClip(VfxRect(0,0,UI_device_width,UI_device_height));
			dc.setFillColor(VFX_COLOR_BLUE);
			dc.setStrokeColor(VFX_COLOR_GREEN);
			dc.fillRect(0, 0,10,10);
			dc.fillRect(VfxRect(0,10,10,10));
			dc.drawImage(0, 20, VfxImageSrc(IMG_GLOBAL_L1));

			dc.drawImage(VfxPoint(0,60), VfxImageSrc(IMG_GLOBAL_L2));
			dc.drawImageFromRes(0,100,IMG_GLOBAL_L3);
			dc.drawImageFromRes(VfxPoint(0,140),IMG_GLOBAL_L4);

			dc.drawResizedImage(
				VfxRect(40,120,20,20), 
				VfxImageSrc(IMG_GLOBAL_L5));

			dc.drawResizedImageFromRes(
				VfxRect(50,0,10,10), 
				IMG_GLOBAL_L6);

			dc.drawImageFromMem(90,110,vrt_sys_res_image_lock(IMG_GLOBAL_L23));
			dc.drawImageFromMem(VfxPoint(90,140),vrt_sys_res_image_lock(IMG_GLOBAL_L24));
			dc.drawResizedImageFromMem(VfxRect(90,170,30,30),vrt_sys_res_image_lock(IMG_GLOBAL_L25));

			U32 layer_handle;
			gdi_layer_get_base_handle(&layer_handle);

			gdi_layer_struct *layer = (gdi_layer_struct *)layer_handle;
			VFX_DEV_ASSERT(layer != NULL);

			VfxColorTypeEnum colorFormat;
			switch (layer->vcf)
			{
			case GDI_COLOR_FORMAT_16:
				colorFormat = VRT_COLOR_TYPE_RGB565;
				break;
			case GDI_COLOR_FORMAT_32:
				colorFormat = VRT_COLOR_TYPE_ARGB8888;
				break;
			case GDI_COLOR_FORMAT_32_PARGB:
				colorFormat = VRT_COLOR_TYPE_PARGB8888;
				break;
			default:
				VFX_DEV_ASSERT(0);
				colorFormat = VRT_COLOR_TYPE_UNKNOWN;
				break;
			};
			VfxImageBuffer imageBuf;

			imageBuf.ptr            = layer->buf_ptr;
			imageBuf.pitchBytes     = layer->width * layer->bits_per_pixel / 8;
			imageBuf.width          = 30;
			imageBuf.height         = 20;
			imageBuf.colorFormat    = colorFormat;
			dc.drawImageBuffer(VfxPoint(90,200), imageBuf);
			dc.drawImageBuffer(90,230, imageBuf);

			dc.setFont(VFX_FONT_DESC_SMALL);
			VfxWChar sz[2] = {'A','\0'};
			dc.drawText(100,0,sz);
			dc.drawText(VfxPoint(0,1),sz);


			dc.drawText(VfxPoint(0,20),VFX_WSTR("B"));
			dc.drawText(100,30,VFX_WSTR("C"));
			dc.drawText(100,40,sz,1);
			dc.drawText(VfxPoint(0,50),sz,1);

			VfxWChar sz1[2] = {'D','\0'};

			dc.drawTextBaseline(
				0, 
				70, 
				10, 
				10, 
				5, 
				sz1, 
				1);

			VfxWChar sz2[2] = {'E','\0'};

			dc.drawTextBaseline(
				VfxRect(100,100,10,10), 
				5, 
				sz2, 
				1);


			VfxWChar szLong[5] ={'A','B','C','D','\0'};
			dc.drawTextTruncated(
				100, 
				140, 
				szLong, 
				3
				);

			dc.drawTextTruncated(
				VfxPoint(0,160), 
				szLong, 
				3);
			dc.drawLine(170,140,200,140);

			dc.drawLine(VfxPoint(170,145),VfxPoint(170,145));

			dc.drawAaLine(170,150,200,150);

			dc.drawAaLine(VfxPoint(170,155),VfxPoint(200,155));
			const VfxWChar ellipsis[] = { '.','.','\0'};
			dc.setEllipsis(ellipsis);

		}
	};
	class VTestVfxDrawContext   : public TestBaseClass
	{
	public:
		void startTest(VfxWString wstrCaseName,int item_idx) 
		{
			TestBaseClass::startTest(wstrCaseName, item_idx);

			VFX_OBJ_CREATE(m_pVfxMyFrame, Vfx_MyFrame, this);
			m_pVfxMyFrame->setBgColor(VFX_COLOR_RED);
			m_pVfxMyFrame->setSize(UI_device_width,UI_device_height);

			m_pVfxMyFrame->m_signalBoundsChanged.connect(this, &VTestVfxDrawContext::onBoundsValueChange);

			confirm(VFX_WSTR("see letter image and line?"));
		}
	protected:

		void onBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds)
		{

		}


	private:
		Vfx_MyFrame* m_pVfxMyFrame;

	};


	class VTestBase   : public TestBaseClass
	{
		VfxWString m_strMember;

	public:
		void startTest(VfxWString wstrCaseName,int item_idx) 
		{
			TestBaseClass::startTest(wstrCaseName, item_idx);


			VFX_OBJ_ASSERT_VALID(this);

			VfxClassInfo *classInfo0 = VFX_OBJ_CLASS_INFO(VfxFrame);
			m_strMember = VFX_WSTR("<Member>");
			phaseString();
			phaseColor();
			phaseImageSrc();
			phaseImageList();
			TestPoint();
			TestRect();
			TestSize();
			TestTransform();
			TestMacro();
			confirm(VFX_WSTR("Already done,press Yes"));



		}
		VfxBool check(bool statement, const VfxWString &testName)
		{

			if (!statement)
			{

				return VFX_FALSE;
			}
			return VFX_TRUE;
		}

		void phaseString()
		{

			VfxWString strNull1(VFX_WSTR("ABC"));
			VfxWString strNull2;
			VfxWString strNull3 = strNull2;
			VfxWString strTemp1(m_strMember);
			VfxWString strTemp2(m_strMember);
			VfxWString strTemp3(VFX_WSTR("<Local>"));

			strNull1.setNull();
			check(strNull1.isNull(),        VFX_WSTR("VfxWString NULL #1"));
			check(strNull3.isNull(),        VFX_WSTR("VfxWString NULL #2"));
			check(!m_strMember.isNull(),    VFX_WSTR("VfxWString NULL #3"));
			check(!strTemp3.isNull(),       VFX_WSTR("VfxWString NULL #4"));

			check(strNull1 == VFX_WSTR_NULL,        VFX_WSTR("VfxWString compare #1"));
			check(strNull1 == strNull1,             VFX_WSTR("VfxWString compare #2"));
			check(strNull2 == strNull1,             VFX_WSTR("VfxWString compare #3"));
			check(strNull1 != strTemp1,             VFX_WSTR("VfxWString compare #4"));
			check(strTemp2 == VFX_WSTR("<Member>"), VFX_WSTR("VfxWString compare #5"));        
			check(strTemp1 == strTemp2,             VFX_WSTR("VfxWString compare #6"));
			check(strTemp2 == strTemp1,             VFX_WSTR("VfxWString compare #7"));
			check(strTemp2 != strTemp3,             VFX_WSTR("VfxWString compare #8"));
			check(strTemp3 == VFX_WSTR("<Local>"),  VFX_WSTR("VfxWString compare #9"));

			strTemp3 = strTemp1;        
			check(strTemp3 == VFX_WSTR("<Member>"), VFX_WSTR("VfxWString assign #1"));
			strTemp2 = strNull1;        
			check(strTemp2.isNull(),                VFX_WSTR("VfxWString assign #2"));
			strNull2 = strNull1;        
			check(strTemp2.isNull(),                VFX_WSTR("VfxWString assign #3"));
			strNull3 = VFX_WSTR("<Hello>");        
			check(strNull3 == VFX_WSTR("<Hello>"),  VFX_WSTR("VfxWString assign #4"));


			VfxWString strTemp4 = VFX_WSTR("ABC");
			check(strTemp4.getLength() == 3,        VFX_WSTR("VfxWString length #1"));

			VfxWChar *p = strTemp4.lockBuf(256);
			vfx_sys_wcscpy(p, (const VfxWChar *)L"12345");
			strTemp4.unlockBuf();
			check(strTemp4 == VFX_WSTR("12345"),    VFX_WSTR("VfxWString lock #1"));
			check(strTemp4.getLength() == 5,        VFX_WSTR("VfxWString lock #2"));

			check(strTemp4[0] == (VfxWChar)L'1',    VFX_WSTR("VfxWString at #1"));
			check(strTemp4[2] == (VfxWChar)L'3',    VFX_WSTR("VfxWString at #2"));
			check(strTemp4[5] == 0,                 VFX_WSTR("VfxWString at #3"));
		}

		void phaseColor()
		{

			VfxColor color0;
			check(color0.value == 0, VFX_WSTR("Zero VfxColor #1"));
			check(color0.getA() == 0, VFX_WSTR("Zero VfxColor #2"));
			check(color0.getR() == 0, VFX_WSTR("Zero VfxColor #3"));
			check(color0.getG() == 0, VFX_WSTR("Zero VfxColor #4"));
			check(color0.getB() == 0, VFX_WSTR("Zero VfxColor #5"));

			VfxColor color1(0x11, 0x22, 0x33, 0x44);
			check(color1.value == 0x11223344, VFX_WSTR("Construct VfxColor #1"));
			check(color1.getA() == 0x11, VFX_WSTR("Construct VfxColor #2"));
			check(color1.getR() == 0x22, VFX_WSTR("Construct VfxColor #3"));
			check(color1.getG() == 0x33, VFX_WSTR("Construct VfxColor #4"));
			check(color1.getB() == 0x44, VFX_WSTR("Construct VfxColor #5"));

			VfxColor color2(0xaabbccdd);
			check(color2.value == 0xaabbccdd, VFX_WSTR("Construct VfxColor #6"));

			VfxColor color3(color2);
			check(color3.value == 0xaabbccdd, VFX_WSTR("Construct VfxColor #7"));

			color3 = color1;
			check(color3.value == 0x11223344, VFX_WSTR("Assign VfxColor #1"));

			check(color3 == color1, VFX_WSTR("Compare VfxColor #1"));
			check(color3 != color2, VFX_WSTR("Compare VfxColor #2"));
			check(color3 == color3, VFX_WSTR("Compare VfxColor #3"));

			color1.setA(0x55);
			check(color1.value == 0x55223344, VFX_WSTR("Set VfxColor #1"));
			color1.setR(0x66);
			check(color1.value == 0x55663344, VFX_WSTR("Set VfxColor #2"));
			color1.setG(0x77);
			check(color1.value == 0x55667744, VFX_WSTR("Set VfxColor #3"));
			color1.setB(0x88);
			check(color1.value == 0x55667788, VFX_WSTR("Set VfxColor #4"));
			color1.isOpaque();
		}

		void phaseImageSrc()
		{

			// Null image source
			VfxImageSrc img0;
			check(img0.isNull(), VFX_WSTR("Null VfxImageSrc #1"));
			check(img0.getType() == VFX_IMAGE_SRC_TYPE_NULL, VFX_WSTR("Null VfxImageSrc #2"));
			check(img0 == VFX_IMAGE_SRC_NULL, VFX_WSTR("Null VfxImageSrc #3"));
			check(img0.getResId()== VFX_RES_ID_NULL, VFX_WSTR("Null VfxImageSrc #4"));
			img0.setNull();
			check(img0.isNull(), VFX_WSTR("Null VfxImageSrc #5"));

			// Resource ID
			VfxImageSrc img1(IMG_GLOBAL_L1);
			check(!img1.isNull(), VFX_WSTR("Res ID VfxImageSrc #1"));
			check(img1.getType() == VFX_IMAGE_SRC_TYPE_RES_ID, VFX_WSTR("Res ID VfxImageSrc #2"));
			check(img1.getResId() == IMG_GLOBAL_L1, VFX_WSTR("Res ID VfxImageSrc #3"));

			VfxImageSrc img2;
			img2.setResId(IMG_GLOBAL_L1);
			check(!img2.isNull(), VFX_WSTR("Res ID VfxImageSrc #4"));
			check(img2.getType() == VFX_IMAGE_SRC_TYPE_RES_ID, VFX_WSTR("Res ID VfxImageSrc #5"));
			check(img2.getResId() == IMG_GLOBAL_L1, VFX_WSTR("Res ID VfxImageSrc #6"));

			check(img1 == img2, VFX_WSTR("Res ID VfxImageSrc #7"));
			check(img1 == VfxImageSrc(IMG_GLOBAL_L1), VFX_WSTR("Res ID VfxImageSrc #8"));
			check(img1 != VfxImageSrc(IMG_GLOBAL_L2), VFX_WSTR("Res ID VfxImageSrc #9"));

			// Image Buffer
			VfxImageBuffer imgBuf1;
			imgBuf1.ptr         = (VfxU8 *)0x12345678;
			imgBuf1.pitchBytes  = 100;
			imgBuf1.width       = 200;
			imgBuf1.width       = 300;
			imgBuf1.colorFormat = VRT_COLOR_TYPE_RGB565;

			VfxImageSrc img3(imgBuf1);
			check(!img3.isNull(), VFX_WSTR("ImgBuf VfxImageSrc #1"));
			check(img3.getType() == VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER, VFX_WSTR("ImgBuf VfxImageSrc #2"));
			check(img3.getImageBuffer() == imgBuf1, VFX_WSTR("ImgBuf VfxImageSrc #3"));

			VfxImageSrc img4;
			img4.setImageBuffer(imgBuf1);
			check(!img4.isNull(), VFX_WSTR("ImgBuf VfxImageSrc #4"));
			check(img4.getType() == VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER, VFX_WSTR("ImgBuf VfxImageSrc #5"));
			check(img4 == VfxImageSrc(imgBuf1), VFX_WSTR("ImgBuf VfxImageSrc #6"));

			check(img3 == img4, VFX_WSTR("ImgBuf VfxImageSrc #7"));
			imgBuf1.ptr = (VfxU8 *)0x87654321;
			check(img3 != VfxImageSrc(imgBuf1), VFX_WSTR("ImgBuf VfxImageSrc #8"));

			// Path
			VfxImageSrc img5(VFX_WSTR("HELLO"));
			check(!img5.isNull(), VFX_WSTR("Path VfxImageSrc #1"));
			check(img5.getType() == VFX_IMAGE_SRC_TYPE_PATH, VFX_WSTR("Path VfxImageSrc #2"));
			check(img5.getPath() == VFX_WSTR("HELLO"), VFX_WSTR("Path VfxImageSrc #3"));

			VfxImageSrc img6;
			img6.setPath(VFX_WSTR("HELLO"));
			check(!img6.isNull(), VFX_WSTR("Path VfxImageSrc #4"));
			check(img6.getType() == VFX_IMAGE_SRC_TYPE_PATH, VFX_WSTR("Path VfxImageSrc #5"));
			check(img6.getPath() == VFX_WSTR("HELLO"), VFX_WSTR("Path VfxImageSrc #6"));

			check(img5 == img6, VFX_WSTR("Path VfxImageSrc #7"));
			check(img5 == VfxImageSrc(VFX_WSTR("HELLO")), VFX_WSTR("Path VfxImageSrc #8"));
			check(img5 != VfxImageSrc(VFX_WSTR("WORLD")), VFX_WSTR("Path VfxImageSrc #9"));

			// Remix
			check(img0 != img1, VFX_WSTR("Remix VfxImageSrc #1"));
			check(img1 != img3, VFX_WSTR("Remix VfxImageSrc #1"));
			check(img3 != img5, VFX_WSTR("Remix VfxImageSrc #2"));

			img0 = img1;
			check(img0.getResId() == IMG_GLOBAL_L1, VFX_WSTR("Remix VfxImageSrc #3"));

			img3 = img5;
			check(img3.getPath() == VFX_WSTR("HELLO"), VFX_WSTR("Remix VfxImageSrc #4"));


			VfxImageSrc img7;
			img7.setMem(NULL);
		}

		void phaseImageList()
		{

			// test add item
			VfxImageList imgListTmp1;
			imgListTmp1.setItemWithResId('IT06', IMG_GLOBAL_L1);
			imgListTmp1.setItemWithResId('IT07', IMG_GLOBAL_L2);
			imgListTmp1.setItemWithResId('IT08', IMG_GLOBAL_L3);
			imgListTmp1.setItemWithResId('IT09', IMG_GLOBAL_L4);
			imgListTmp1.setItemWithResId('IT10', IMG_GLOBAL_L5);

			imgListTmp1.setItemWithResId('IT06', IMG_GLOBAL_L6);
			imgListTmp1.setItemWithResId('IT07', IMG_GLOBAL_L7);
			imgListTmp1.setItemWithResId('IT08', IMG_GLOBAL_L8);
			imgListTmp1.setItemWithResId('IT09', IMG_GLOBAL_L9);
			imgListTmp1.setItemWithResId('IT10', IMG_GLOBAL_L10);

			// Test copy constructor
			VfxImageList imgListTemp2(imgListTmp1);

			// Test assign operator
			VfxImageList imgList;
			VfxS32 i;
			for (i = 1; i <= 100; i++)
			{
				imgList.setItemWithResId(i, IMG_GLOBAL_L11);
			}
			imgList = imgListTemp2;

			// Check the result
			check(imgList['IT06'].getResId() == IMG_GLOBAL_L6, VFX_WSTR("VfxImageList #1"));
			check(imgList['IT07'].getResId() == IMG_GLOBAL_L7, VFX_WSTR("VfxImageList #2"));
			check(imgList['IT08'].getResId() == IMG_GLOBAL_L8, VFX_WSTR("VfxImageList #3"));
			check(imgList['IT09'].getResId() == IMG_GLOBAL_L9, VFX_WSTR("VfxImageList #4"));
			check(imgList['IT10'].getResId() == IMG_GLOBAL_L10, VFX_WSTR("VfxImageList #5"));
			check(imgList['NONE'].isNull(), VFX_WSTR("VfxImageList #6"));

			// Check empty list
			VfxImageList emptyList;
			check(emptyList.isEmpty(), VFX_WSTR("Empty VfxImageList #1"));
			check(!imgListTmp1.isEmpty(), VFX_WSTR("Empty VfxImageList #2"));

			imgListTmp1 = emptyList;
			check(imgListTmp1.isEmpty(), VFX_WSTR("Empty VfxImageList #3"));

			imgListTemp2.removeItem('IT10');
			imgListTemp2.removeItem('IT09');
			imgListTemp2.removeItem('IT06');
			imgListTemp2.removeItem('IT07');
			imgListTemp2.removeItem('IT06');
			imgListTemp2.removeItem('IT07');
			imgListTemp2.removeItem('IT08');
			imgListTemp2.removeItem('IT09');
			imgListTemp2.removeItem('IT08');
			imgListTemp2.removeItem('IT09');
			check(imgListTemp2.isEmpty(), VFX_WSTR("Empty VfxImageList #4"));

			// Check remove
			imgList.setItem('NONE', VFX_IMAGE_SRC_NULL);
			check(imgList['NONE'].isNull(), VFX_WSTR("Remove VfxImageList #1"));
			imgList.setItem('IT08', VFX_IMAGE_SRC_NULL);
			check(imgList['IT08'].isNull(), VFX_WSTR("Remove VfxImageList #2"));
			imgList.removeItem('IT10');
			check(imgList['IT10'].isNull(), VFX_WSTR("Remove VfxImageList #3"));
			imgList.removeItem('IT10');
			check(imgList['IT10'].isNull(), VFX_WSTR("Remove VfxImageList #4"));
			check(!imgList.isEmpty(), VFX_WSTR("Remove VfxImageList #5"));
			check(imgList['IT06'].getResId() == IMG_GLOBAL_L6, VFX_WSTR("Remove VfxImageList #6"));
			check(imgList['IT07'].getResId() == IMG_GLOBAL_L7, VFX_WSTR("Remove VfxImageList #7"));
			check(imgList['IT09'].getResId() == IMG_GLOBAL_L9, VFX_WSTR("Remove VfxImageList #8"));


			// Check operator assign
			VfxImageList imgList2;
			imgList2.setItemWithResId('AA01', IMG_GLOBAL_L1);
			imgList2.setItemWithResId('AA02', IMG_GLOBAL_L2);

			VfxImageList imgList3;
			imgList3.setItemWithResId('BB01', IMG_GLOBAL_L1);
			imgList3.setItemWithResId('BB02', IMG_GLOBAL_L2);
			imgList3.setItemWithResId('BB03', IMG_GLOBAL_L2);

			VfxImageList imgList2b(imgList2);
			VfxImageList imgList3b(imgList3);

			imgList2 = imgList3;
			check(imgList2['AA02'] == VFX_IMAGE_SRC_NULL, VFX_WSTR("Assgin VfxImageList #1"));
			check(imgList2['BB02'] == VfxImageSrc(IMG_GLOBAL_L2), VFX_WSTR("Assgin VfxImageList #2"));

			imgList3b = imgList2b;
			check(imgList3b['BB02'] == VFX_IMAGE_SRC_NULL, VFX_WSTR("Assgin VfxImageList #3"));
			check(imgList3b['AA02'] == VfxImageSrc(IMG_GLOBAL_L2), VFX_WSTR("Assgin VfxImageList #4"));
		}

		void TestPoint()
		{
			VfxPoint p;
			VfxPoint p1(0,0);
			VfxPoint p2(p1);
			p = p2;
			VfxBool b  = (p == p2);
			b = (p!= p2);
			p1.isZero();
			p1.setZero();
		}

		void TestRect()
		{
			VfxRect r;
			VfxRect r1(0,0,10,10);
			VfxRect r2(VfxPoint(0,0),VfxSize(10,10));
			VfxRect r3(r2);
			r = r3;
			VfxBool b =(r ==r3);
			b = (r!= r3);
			r.getX();
			r.getY();
			r.getWidth();
			r.getHeight();
			r.getAbsWidth();
			r.getAbsHeight();
			r.getMinX();
			r.getMinY();
			r.getMaxX();
			r.getMaxY();
			r.getMidX();
			r.getMidY();
			r.getMidPoint();
			r.isEmpty();
			r.contains(VfxPoint(0,0));
			r.setZero();
			r.offsetWith(VfxPoint(0,0));
			r.offsetWith(0,0);
			r.intersectWith(r1);
			r.unionWith(r1);

		}

		void TestSize()
		{
			VfxSize s;
			VfxSize s1(10,10);
			VfxSize s2(s1);
			s = s2;
			VfxBool b = (s == s2);
			b  = (s!=s2);
			s.isEmpty();
			s.isZero();
		}
		void TestTransform()
		{
			VfxTransform t;
			t.init (VFX_TRANSFORM_TYPE_AFFINE );
			t.setIdentity();
			VfxTransform t1(t);
			VfxTransform t2;
			t2 =t1;
			VfxBool b = (t1 == t2);
			b = (t1 != t2);

		}

		void TestMacro()
		{
			VFX_COLOR_RES(0);
#if defined(__COSMOS_MMI_PACKAGE__)
		VFX_FONT_RES(VCP_FNT_TEXT_VIEW_TXT);
#endif

			void* m_data = NULL;

			VFX_ALLOC_MEM(m_data, 4, this);
			if(m_data)
			{

				VFX_FREE_MEM(m_data);
				m_data = NULL;
			}


//			VFX_ALIGN(4) VfxU8 buf[16];buf[0] = buf[1];

			VfxBase *p; 
			VFX_ALLOC_NEW(p, VfxBase, this);
			VFX_DELETE(p);

			VfxImageBuffer imageBuf;
			VfxImageBuffer* m_imageBuf = NULL;


			VFX_DEV_ASSERT(m_imageBuf == NULL);


			VFX_ALLOC_NEW_EX(m_imageBuf, VfxImageBuffer, this, (imageBuf));


			VFX_DELETE(m_imageBuf);
			VfxColor cs[] = {VFX_COLOR_AQUA,
				VFX_COLOR_BLACK,
				VFX_COLOR_BLUE,
				VFX_COLOR_FUCHSIA,
				VFX_COLOR_GREEN,
				VFX_COLOR_GREY,
				VFX_COLOR_OLIVE,
				VFX_COLOR_PURPLE,
				VFX_COLOR_RED,
				VFX_COLOR_SILVER,
				VFX_COLOR_TEAL,
				VFX_COLOR_TRANSPARENT,
				VFX_COLOR_WHITE,
				VFX_COLOR_YELLOW,
			};


			VfxFlag m_flags = 1;
			VFX_FLAG_CLEAR(m_flags, 0);
			VfxBool bf = VFX_FLAG_HAS(m_flags,0);
			bf = VFX_FLAG_HAS_ALL(m_flags,0);
			bf =bf;
			VFX_FLAG_SET(m_flags,1);


			VfxFontDesc font0(VFX_FONT_DESC_SIZE_MEDIUM, VFX_FONT_DESC_ATTR_BOLD);
			VfxFontDesc font1(VFX_FONT_DESC_SIZE_MEDIUM, VFX_FONT_DESC_ATTR_ITALIC);
			VfxFontDesc font2(VFX_FONT_DESC_SIZE_MEDIUM, VFX_FONT_DESC_ATTR_NORMAL);
			VfxFontDesc font3(VFX_FONT_DESC_SIZE_MEDIUM, VFX_FONT_DESC_ATTR_OBLIQUE);
			VfxFontDesc font4(VFX_FONT_DESC_SIZE_MEDIUM, VFX_FONT_DESC_ATTR_STRIKETHROUGH);
			VfxFontDesc font5(VFX_FONT_DESC_SIZE_MEDIUM, VFX_FONT_DESC_ATTR_UNDERLINE);


			VfxFontDesc f6(VFX_FONT_DESC_LARGE);  
			VfxFontDesc f7(VFX_FONT_DESC_MEDIUM);
			VfxFontDesc f8(VFX_FONT_DESC_SMALL);

			VfxFontDesc f9(VFX_FONT_DESC_VF_SIZE(20));
			VfxFontDesc f10(VFX_FONT_DESC_SIZE_MEDIUM,VFX_FONT_DESC_ATTR_MONOSPACE);
			f9.measureStr(NULL);
			VfxWString mesurestring = VFX_WSTR("aaa");
			f9.measureStr(NULL);
			f9.measureStr(mesurestring);
			f9.setAttr(0);

			VfxFPoint ppp(VFX_FPOINT_ZERO);

			VFX_ASSERT(VFX_ID_NULL == 0);
			VfxImageSrc imagesrc(VFX_IMAGE_SRC_NULL);

			VfxRect rrrr = VFX_RECT_ZERO;
			VfxPoint p90 = VFX_POINT_ZERO;

			VFX_ASSERT(VFX_RES_ID_NULL == 0);


			VfxSize SSS = VFX_SIZE_ZERO;
			VfxBaseTimeline* pBase = NULL;
			VfxRectTimeline *line = VFX_STATIC_CAST(pBase, VfxRectTimeline *);line=line;

			VfxTransform TR = VFX_TRANSFORM_IDENTITY;
			VfxWChar filepath[] = {'c',':','\\','\\','a','.','a'};
			vfx_sys_file_handle    m_handle = vfx_sys_file_open(filepath, VFX_UC_SYS_FILE_OPEN_MODE_READ);
			if(m_handle != NULL)
		 {
			 vfx_sys_file_close(m_handle);
		 }

			VfxWString str111 = VFX_WSTR_EMPTY;

			VfxWChar caption[40] = {0};
			kal_wsprintf(caption, "(%d)", 1);
			str111 = VFX_WSTR_MEM(caption);

			VfxWString str222 = VFX_WSTR_NULL;




			VfxWString str333 = VFX_WSTR_RES(0);

			VfxWString m_text = VFX_WSTR_STATIC((const VfxWChar *)caption);
			U32 macro[] = {VFX_SPECIAL_KEY_FLAG_ACCESSKEY,
				VFX_SPECIAL_KEY_FLAG_ALT,
				VFX_SPECIAL_KEY_FLAG_CAPSLOCK,
				VFX_SPECIAL_KEY_FLAG_CTRL,
				VFX_SPECIAL_KEY_FLAG_FN,
				VFX_SPECIAL_KEY_FLAG_NUMLOCK,
				VFX_SPECIAL_KEY_FLAG_SHIFT,
				VFX_TIMELINE_DEFAULT_DUR_TIME,
				VFX_TIMELINE_REPEAT_INFINITE
			};
			
			macro[0] = macro[0] ;
			class VfxCJLForEx:public VfxObject
			{
			public:
				VfxCJLForEx(int n){}

			};
			VfxCJLForEx* pEx;
			VFX_OBJ_CREATE_EX(pEx,VfxCJLForEx,this,(5));


//			VcpButton* pButton = NULL;
			VfxControl* pControl = NULL;
			VcpButton *pppppppp = VFX_OBJ_DYNAMIC_CAST(pControl, VcpButton);

			VFX_OBJ_CLOSE(pEx);

			VfxChar* pchar= "abcd";
			pchar = VFX_CONST_CAST(pchar,VfxChar*);
			float f = VFX_RAD_TO_DEG(20);
			f = VFX_DEG_TO_RAD(20);
			f =f;

			VfxTransform tempTransform;

			tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

			vfxAbs(0);
			vfxCeil(0);
			vfxCos(0);
			vfxFloor(0);
			vfxMax(0,0);
			vfxMin(0,0);
			vfxMsecDiff(0,0);
			vfxSin(0);
			vfxSqrt(0);
			int abcd = 0;
			int dcba = 1;
			vfxSwap(abcd,dcba);


		}


	};






	/***************************************************************************** 
	* Class VcpMyWheelMenu
	*****************************************************************************/
#define VTST_RT_SAMPLE_MENU_1_CAMERA_DISTANCE       (240)
#define VTST_RT_SAMPLE_MENU_1_CELL_WIDTH            (160)
#define VTST_RT_SAMPLE_MENU_1_CELL_HEIGHT           (60)
#define VTST_RT_SAMPLE_MENU_1_SHIFT_X               (-20)
#define VTST_RT_SAMPLE_MENU_1_ANGLE                 (15)
#define VTST_RT_SAMPLE_MENU_1_RADIUS                (200)
#define VTST_RT_SAMPLE_MENU_1_TILE                  (30)
#define VTST_RT_SAMPLE_MENU_1_PAN                   (20)

	static const VfxU32 g_colorlst[] = {
		//VRT_COLOR_WHITE,
		VRT_COLOR_RED,
		VRT_COLOR_GREEN,
		VRT_COLOR_BLUE,
		VRT_COLOR_AQUA,
		VRT_COLOR_FUCHSIA,
		VRT_COLOR_YELLOW,
		VRT_COLOR_GREY,
		VRT_COLOR_TEAL,
		VRT_COLOR_PURPLE,
		VRT_COLOR_OLIVE,
		VRT_COLOR_SILVER,
	};
#define GCOLORCNT (sizeof(g_colorlst) / sizeof(g_colorlst[0]))

	static VfxS32 g_color_idx = 0;

	static VfxColor VtstPickupColor(VfxS32 index = -1)
	{
		if (index == -1)
		{
			index = g_color_idx++;
		}
		return VfxColor(g_colorlst[index % GCOLORCNT]);
	}

	class VtstRtSampleMenu11 : public VcpWheelMenu
	{
		typedef VtstRtSampleMenu11       Self;
		typedef VcpWheelMenu    Super;

		class MyCell : public VfxControl
		{
			VfxTextFrame     *m_textFrame;
			VfxBool          m_highlight;

		public:

			VtstRtSampleMenu11* getMenu()
			{
				if (getParentFrame())
					return (VtstRtSampleMenu11*) getParentFrame();
				return NULL;
			}

			VfxS32 getMenuPos()
			{
				return 0;
			}

			virtual void onInit()
			{
				VfxControl::onInit();

				VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);
				m_textFrame->setPos(VfxPoint(0, 0));
				m_textFrame->setColor(VFX_COLOR_WHITE);
				m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
				m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);  

				sendToBack();
				setOpacity(1.0f);
				setAnchor(VfxFPoint(0.5, 0.5));
				setBorderColor(VRT_COLOR_WHITE);
				setBorderWidth(1);

				setIsCached(VFX_TRUE);
				setIsOpaque(VFX_TRUE);
				setRect(VfxRect(0, 0, VTST_RT_SAMPLE_MENU_1_CELL_WIDTH, VTST_RT_SAMPLE_MENU_1_CELL_HEIGHT));

				m_highlight = VFX_FALSE;

				setAutoAnimate(VFX_TRUE);
			}
			virtual void onDeinit()
			{
				VfxControl::onDeinit();
			}
			void setHighlight(VfxBool isHighLight, VfxBool isAnim)
			{
				m_highlight = isHighLight;
				VfxAutoAnimate::begin();
				VfxAutoAnimate::setDisable(!isAnim);

				if (m_highlight)
				{
					setBorderWidth(5);
				}
				else
				{
					setBorderWidth(1);
				}            
				VfxAutoAnimate::commit();

				checkUpdate();
			}

			virtual void onUpdate()
			{
			}

			void adjustPos(const VfxRect &value)
			{
				m_textFrame->setBounds(VfxRect(0, 0, value.size.width, value.size.height));
			}
			virtual void setBounds(const VfxRect &value)
			{
				VfxControl::setBounds(value);
				adjustPos(value);
			}
			void setCaption(const VfxWString& string)
			{
				m_textFrame->setString(string);
			}
			void setTextVisible(VfxBool visible)
			{
				m_textFrame->setHidden(!visible);
			}
			void click()
			{
				VfxColor color = getBgColor();
				VfxAutoAnimate::begin();
				VfxAutoAnimate::setDisable(VFX_TRUE);
				setBgColor(0xFFFFFFFF);
				VfxAutoAnimate::commit();
				setBgColor(color);
			}
		};


		// Constructor / Destructor
	public:
		VtstRtSampleMenu11() : 
		  m_filterTimeline1(NULL),
			  m_filterTimeline2(NULL),
			  m_filterTimeline3(NULL),
			  m_filterTimeline4(NULL),
			  m_filterTimeline5(NULL)
		  {}
		  virtual ~VtstRtSampleMenu11(){}

		  // Override
	public:
		virtual void onInit()
		{       
			Super::onInit();
			m_cellTextVisible = VFX_FALSE;
			setIsZSortChild(VFX_TRUE);
		}

		struct MyWheelMenuUserData
		{
			VfxS32 index;
			VfxBool isEnter;
		};

		virtual VfxFrame* createCell(VfxS32 cell, VfxS32 subcell)
		{
			MyCell* item;
			VFX_OBJ_CREATE(item, MyCell, this);

			VfxWChar caption[40] = {0};
			kal_wsprintf(caption, "(%d)", cell);
			item->setCaption(VFX_WSTR_MEM(caption));
			item->setTextVisible(m_cellTextVisible);
			item->setHighlight(VFX_FALSE, VFX_FALSE);

			item->setBgColor(VtstPickupColor(1000 + cell));

			if (getFocus() == cell)
			{
				item->setHighlight(VFX_TRUE, VFX_TRUE);
			}

			MyWheelMenuUserData data;
			data.index = cell;
			data.isEnter = VFX_FALSE;
			setCellUserData(cell, subcell, item, &data, sizeof(MyWheelMenuUserData));

			item->setFilterTiming(1.0f);

			return item;
		}

		virtual void onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* frame)
		{
			if (cell == getFocus())
			{
				frame->bringToFront();
			}
		}

		virtual void onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame)
		{
			VFX_UNUSED(cell);
			VFX_UNUSED(subcell);
			VFX_OBJ_CLOSE(cellFrame);
		}

		virtual void onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem)
		{
			if (VCP_WHEELMENU_IS_VALID_INDEX(previousFocusItem))
			{
				MyCell* item = (MyCell*) getCellIfPresent(previousFocusItem);
				if (item)
				{
					item->setHighlight(VFX_FALSE, VFX_TRUE);
				}
			}
			if (VCP_WHEELMENU_IS_VALID_INDEX(focusItem))
			{
				MyCell* item = (MyCell*) getCellIfPresent(focusItem);
				if (item)
				{
					item->setHighlight(VFX_TRUE, VFX_TRUE);
				}
			}
		}

		void setCellTextVisible(VfxBool visible)
		{
			for (VfxS32 p = getFirstVisibleIndex(); p < getLastVisibleIndex(); p++)
			{
				MyCell* cell = (MyCell*)getCellIfPresent(p);
				if (cell)
				{
					cell->setTextVisible(visible);
				}
			}
		}

		virtual VfxBool onKeyInput(VfxKeyEvent &event)
		{
			if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
			{
				if (event.keyCode == VFX_KEY_CODE_ARROW_UP)
				{
					setFocus(getFocus() - 1);
					return VFX_TRUE;
				}
				if (event.keyCode == VFX_KEY_CODE_ARROW_DOWN)
				{
					setFocus(getFocus() + 1);
					return VFX_TRUE;
				}
				if (event.keyCode == VFX_KEY_CODE_CAMERA)
				{
					m_cellTextVisible = !m_cellTextVisible;
					setCellTextVisible(m_cellTextVisible);
					return VFX_TRUE;
				}
				if (event.keyCode == VFX_KEY_CODE_VOL_UP)
				{
					return VFX_TRUE;
				}
				if (event.keyCode == VFX_KEY_CODE_VOL_DOWN)
				{
					return VFX_TRUE;
				}

			}
			return Super::onKeyInput(event);
		}

		virtual void onDragStart() {}

		virtual void onDragEnd(VfxS32 xspeed, VfxS32 yspeed)
		{
			VFX_UNUSED(xspeed);
			if (yspeed == 0)
			{
				setFocus(VfxS32(getScrollIndex() + 0.5f));
			}
			else
			{
				VfxS32   s      = yspeed > 0 ? 1 : -1;
				VfxFloat m      = VFX_ABS(yspeed) / 333.3f;

				if (m > 3) m = 3;

				setFocus(VfxS32(getScrollIndex() - s * m + 0.5f), 300);
			}
		}

		virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset)
		{
			VFX_UNUSED(xoffset);
			setScrollIndex(getScrollIndex() - VfxFloat(yoffset) / VTST_RT_SAMPLE_MENU_1_CELL_HEIGHT, 0);
		}

		// Notify when the menu is tapped
		virtual void onTap(VfxPoint pt)
		{
			MyCell* item = (MyCell*) getCellIfPresent(getFocus());
			VfxMatrix3x3Ex inv = VfxMatrix3x3Ex(item->forceGetTransform().data.matrix3x3);
			inv.inverse();

			VfxPoint point = inv.transform(pt);
			point = convertPointTo(point, item);
			if (item->getBounds().contains(point))
			{
				setFocus(getFocus());
				item->click();
				return;
			}

			item = (MyCell*) getCellIfPresent(getFocus() - 1);
			inv = VfxMatrix3x3Ex(item->forceGetTransform().data.matrix3x3);
			inv.inverse();

			point = inv.transform(pt);
			point = convertPointTo(point, item);
			if (item->getBounds().contains(point))
			{
				setFocus(getFocus() - 1);
				return;
			}


			item = (MyCell*) getCellIfPresent(getFocus() + 1);
			inv = VfxMatrix3x3Ex(item->forceGetTransform().data.matrix3x3);
			inv.inverse();

			point = inv.transform(pt);
			point = convertPointTo(point, item);
			if (item->getBounds().contains(point))
			{
				setFocus(getFocus() + 1);
				return;
			}


			item = (MyCell*) getCellIfPresent(getFocus() - 2);
			inv = VfxMatrix3x3Ex(item->forceGetTransform().data.matrix3x3);
			inv.inverse();

			point = inv.transform(pt);
			point = convertPointTo(point, item);
			if (item->getBounds().contains(point))
			{
				setFocus(getFocus() - 2);
				return;
			}

			item = (MyCell*) getCellIfPresent(getFocus() + 2);
			inv = VfxMatrix3x3Ex(item->forceGetTransform().data.matrix3x3);
			inv.inverse();

			point = inv.transform(pt);
			point = convertPointTo(point, item);
			if (item->getBounds().contains(point))
			{
				setFocus(getFocus() + 2);
				return;
			}



		}

		virtual VfxS32 getCount()
		{
			return m_count;
		}

		virtual VfxS32 getBehindCount()
		{
			return 2;
		}

		virtual VfxS32 getAheadCount()
		{
			return 2;
		}

		static vrt_render_dirty_type_enum myFrameEffectCB(
			VfxS32                              cell,           // [IN] the cell index
			VfxS32                              subCell,        // [IN] the sub cell index
			VfxFloat                            cellRelPos,     // [IN] the cell position
			vrt_frame_visual_property_struct    *target_frame,  // [IN] the cell frame
			VfxFloat                            fPos,           // [IN] animating index value
			VfxS32                              focus,          // the focus value of the menu
			VfxRect                             viewBounds,     // the menu bounds
			void                                *userData,      // user data
			VfxU32                              userDataSize,   // user data size
			VcpWheelMenuState                   state,          // [IN] the state of Menu
			VfxFloat                            level           // [IN] the level of state
			)
		{
			VFX_UNUSED(focus);
			VFX_UNUSED(userDataSize);
			VFX_DEV_ASSERT(target_frame != NULL);
			VFX_DEV_ASSERT(userDataSize == sizeof(MyWheelMenuUserData));

			MyWheelMenuUserData* data = (MyWheelMenuUserData*)userData;

			VfxFloat offset = data->index - fPos; 

			VfxMatrix4x4 totalProject;
			VfxMatrix4x4 cameraView;
			VfxMatrix4x4 modelView;
			VfxMatrix4x4 RT;

			// set Camear parameters :
			// Se set translateX as viewBounds.size.width/2 and 
			// translateY as viewBounds.size.height/2.
			// So the 3D origin will project into the screen center.
			// Set CameraDistance & nearPlane will change the perspecitve
			// degree of 3D scene. We set those two parameter the same
			// becasue we want to the focused item the apply no transform.
			cameraView.setCamera(
				1.0f, 
				1.0f, 
				(VfxFloat)(viewBounds.size.width/2), 
				(VfxFloat)(viewBounds.size.height/2), 
				(VfxFloat)VTST_RT_SAMPLE_MENU_1_CAMERA_DISTANCE, 
				(VfxFloat)VTST_RT_SAMPLE_MENU_1_CAMERA_DISTANCE, 
				0, 
				0, 
				0);

			// set Model View :
			// The model view matirx decides the origin and direction of model.
			// We set the origin of each item to the center of item.
			// So we need to apply a negative translate. 
			// 160/2 is the item's half width and 60/2 is item's half height.
			modelView.setTranslation((VfxFloat)((-1 * VTST_RT_SAMPLE_MENU_1_CELL_WIDTH/2)), 
				(VfxFloat)(-1 * VTST_RT_SAMPLE_MENU_1_CELL_HEIGHT/2), 
				0);

			// set RT matrix :
			// RT matrix decide the rotate part and translate part of model.
			// The 3,7,11 is translate part of the matrix.
			// we want to shift x to negative direction a litte, and y z path
			// as a circle in Y plane. The 15.0f means there is 15 degree between
			// two item and the 200 is radius of this circle. If radius become
			// large, the distance between will become large.
        RT.m[12] = VTST_RT_SAMPLE_MENU_1_SHIFT_X;
        RT.m[13] = vfxSin(offset * VTST_RT_SAMPLE_MENU_1_ANGLE/ 180.0f * VFX_PI) * VTST_RT_SAMPLE_MENU_1_RADIUS;
        RT.m[14] = (1 - vfxCos(offset * VTST_RT_SAMPLE_MENU_1_ANGLE / 180.0f * VFX_PI)) * VTST_RT_SAMPLE_MENU_1_RADIUS;

			// The 0,1,2,4,5,6,8,9,10 is rotate part of the matrix.
			// we want to apply two rotate rotate by x axis by 30 degree,
			// then rotate by y axis by 20 degree. notice that the first applied
			// rotation will be put on the right side of matrix and the least 
			// applied rotation will be put on the left side of matrix. The
			// result of two rotation multiplying is list as follow:
			/*
        RT.m[5] = RT.m[10] = vfxCos(offset * 30.0f / 180.0f * VFX_PI);
        RT.m[6] = vfxSin(offset * 30.0f / 180.0f * VFX_PI);
        RT.m[9] = -1 * RT.m[9];
			*/

			VfxFloat cosA= vfxCos(offset * VTST_RT_SAMPLE_MENU_1_TILE / 180.0f * VFX_PI);
			VfxFloat sinA = vfxSin(offset * VTST_RT_SAMPLE_MENU_1_TILE / 180.0f * VFX_PI);
			VfxFloat cosB = vfxCos(offset * VTST_RT_SAMPLE_MENU_1_PAN / 180.0f * VFX_PI);
			VfxFloat sinB = vfxSin(offset * VTST_RT_SAMPLE_MENU_1_PAN / 180.0f * VFX_PI);

			RT.m[0] = cosB;
        RT.m[4] = sinB * sinA;
        RT.m[8] = -1 * sinB * cosA;
        
        RT.m[1] = 0;
        RT.m[5] = cosA;
        RT.m[9] = sinA;

        RT.m[2] = sinB;
        RT.m[6] = -1 * cosB * sinA;
			RT.m[10] = cosB * cosA;

			// Now we multiply cameraView, RT and modelview to get totalProject. 
			totalProject = cameraView * RT * modelView;

			// Set as 3x3 matrix for VRT rendering.
			target_frame->transform.type = VRT_TRANSFORM_TYPE_MATRIX3X3; 
			totalProject.initMatrix3x3(target_frame->transform.data.matrix3x3);

			if (VFX_ABS(offset) < 2)
			{
				target_frame->opacity = 1;
			}
			else
			{
				target_frame->opacity = 1.0f - (VFX_ABS(offset) - 2);
				if (target_frame->opacity < 0)
				{
					target_frame->opacity = 0;
				}
			}

			if (state != VCP_WHEEL_MENU_NORMAL_STATE)
			{
				VfxMatrix3x3Ex mat = VfxMatrix3x3Ex(target_frame->transform.data.matrix3x3);
				VfxMatrix3x3Ex tempMat;
            /*
            VfxFloat tx, ty;
            tx = mat.m[6];
            ty = mat.m[7];
            */
            VfxFloat p1x, p1y, p2x, p2y;

            p1x = mat.m[6]/mat.m[8];
            p1y = mat.m[7]/mat.m[8];
            
            p2x = (mat.m[0] * VTST_RT_SAMPLE_MENU_1_CELL_WIDTH + mat.m[3] * VTST_RT_SAMPLE_MENU_1_CELL_HEIGHT + mat.m[6]) /
                    (mat.m[2] * VTST_RT_SAMPLE_MENU_1_CELL_WIDTH + mat.m[5] * VTST_RT_SAMPLE_MENU_1_CELL_HEIGHT + mat.m[8]);
            
            p2y = (mat.m[1] * VTST_RT_SAMPLE_MENU_1_CELL_WIDTH + mat.m[4] * VTST_RT_SAMPLE_MENU_1_CELL_HEIGHT + mat.m[7]) /
                    (mat.m[2] * VTST_RT_SAMPLE_MENU_1_CELL_WIDTH + mat.m[5] * VTST_RT_SAMPLE_MENU_1_CELL_HEIGHT + mat.m[8]);

				tempMat.setTranslation((-1 * (p1x + p2x)/2), (-1 * (p1y + p2y)/2));
				mat = tempMat * mat;

				tempMat.setRotateByZ(VFX_DEG_TO_RAD(360 * level));
				mat = tempMat * mat;

				if (state == VCP_WHEEL_MENU_ENTER_STATE)
				{
					tempMat.setTranslation(200 - 200 * level, 0);
				}
				else
				{
					tempMat.setTranslation(-200 * level, 0);
				}
				mat = tempMat * mat;

				tempMat.setTranslation((p1x + p2x)/2 ,(p1y + p2y)/2);
				mat = tempMat * mat;

				mat.initMatrix3x3(target_frame->transform.data.matrix3x3);

			}

			target_frame->pos_z = VFX_ABS(offset);
			return VRT_RENDER_DIRTY_TYPE_DIRTY;
		}

		virtual VcpWheelMenuFrameEffectCBFuncPtr getFrameEffectCB()
		{
			return &VtstRtSampleMenu11::myFrameEffectCB;
		}

		virtual void onStateChangeFinished(VcpWheelMenuState finishedstate)
		{
			if (finishedstate == VCP_WHEEL_MENU_NORMAL_STATE)
			{
				VfxAutoAnimate::begin();
				VfxAutoAnimate::setDisable(VFX_TRUE);
				m_movingFrame->setPos(m_focusPos2);
				VfxAutoAnimate::commit();
				pushInSubCell(m_movingFrame, getFocus(),0);
			}
		}

		void setCount(VfxS32 count)
		{
			m_count = count;
			update();
		}

		void enter()
		{
			MyCell* item = (MyCell*) getCellIfPresent(getFocus());

			if (m_filterTimeline1 == NULL)
			{
				VFX_OBJ_CREATE(m_filterTimeline1, VfxFloatTimeline, this);
			}
			m_filterTimeline1->setFromValue(0.0f);
			m_filterTimeline1->setToValue(1.0f);
			m_filterTimeline1->setDurationTime(2000);
			m_filterTimeline1->setRepeatCount(1);
			m_filterTimeline1->setTarget(item);
			m_filterTimeline1->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
			m_filterTimeline1->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
			m_filterTimeline1->start();
			/*
			MyWheelMenuUserData data;
			data.index = getFocus();
			data.isEnter = VFX_TRUE;
			setCellUserData(getFocus(), 0, item, &data, sizeof(MyWheelMenuUserData));
			*/
			item = (MyCell*) getCellIfPresent(getFocus()-1);

			if (m_filterTimeline2 == NULL)
			{
				VFX_OBJ_CREATE(m_filterTimeline2, VfxFloatTimeline, this);
			}
			m_filterTimeline2->setFromValue(0.0f);
			m_filterTimeline2->setToValue(1.0f);
			m_filterTimeline2->setDurationTime(2000);
			m_filterTimeline2->setRepeatCount(1);
			m_filterTimeline2->setTarget(item);
			m_filterTimeline2->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
			m_filterTimeline2->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
			m_filterTimeline2->setStartTime(250);
			m_filterTimeline2->start(); 
			/*
			data.index = getFocus()-1;
			data.isEnter = VFX_TRUE;
			setCellUserData(getFocus()-1, 0, item, &data, sizeof(MyWheelMenuUserData));
			*/

			item = (MyCell*) getCellIfPresent(getFocus()+1);

			if (m_filterTimeline3 == NULL)
			{
				VFX_OBJ_CREATE(m_filterTimeline3, VfxFloatTimeline, this);
			}
			m_filterTimeline3->setFromValue(0.0f);
			m_filterTimeline3->setToValue(1.0f);
			m_filterTimeline3->setDurationTime(2000);
			m_filterTimeline3->setRepeatCount(1);
			m_filterTimeline3->setTarget(item);
			m_filterTimeline3->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
			m_filterTimeline3->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
			m_filterTimeline3->setStartTime(500);
			m_filterTimeline3->start(); 
			/*
			data.index = getFocus() + 1;
			data.isEnter = VFX_TRUE;
			setCellUserData(getFocus() + 1, 0, item, &data, sizeof(MyWheelMenuUserData));
			*/
			item = (MyCell*) getCellIfPresent(getFocus()-2);

			if (m_filterTimeline4 == NULL)
			{
				VFX_OBJ_CREATE(m_filterTimeline4, VfxFloatTimeline, this);
			}
			m_filterTimeline4->setFromValue(0.0f);
			m_filterTimeline4->setToValue(1.0f);
			m_filterTimeline4->setDurationTime(2000);
			m_filterTimeline4->setRepeatCount(1);
			m_filterTimeline4->setTarget(item);
			m_filterTimeline4->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
			m_filterTimeline4->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
        m_filterTimeline4->setStartTime(750);
			m_filterTimeline4->start(); 
			/*
			data.index = getFocus() -2;
			data.isEnter = VFX_TRUE;
			setCellUserData(getFocus() -2, 0, item, &data, sizeof(MyWheelMenuUserData));
			*/
			item = (MyCell*) getCellIfPresent(getFocus()+2);

			if (m_filterTimeline5 == NULL)
			{
				VFX_OBJ_CREATE(m_filterTimeline5, VfxFloatTimeline, this);
			}
			m_filterTimeline5->setFromValue(0.0f);
			m_filterTimeline5->setToValue(1.0f);
			m_filterTimeline5->setDurationTime(2000);
			m_filterTimeline5->setRepeatCount(1);
			m_filterTimeline5->setTarget(item);
			m_filterTimeline5->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
			m_filterTimeline5->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
			m_filterTimeline5->setStartTime(1000);
			m_filterTimeline5->start(); 
			/*
			data.index = getFocus() +2;
			data.isEnter = VFX_TRUE;
			setCellUserData(getFocus() +2, 0, item, &data, sizeof(MyWheelMenuUserData));
			*/
		}


		void leave()
		{
			MyCell* item = (MyCell*) getCellIfPresent(getFocus());

			if (m_filterTimeline1 == NULL)
			{
				VFX_OBJ_CREATE(m_filterTimeline1, VfxFloatTimeline, this);
			}
			m_filterTimeline1->setFromValue(0.0f);
			m_filterTimeline1->setToValue(1.0f);
			m_filterTimeline1->setDurationTime(2000);
			m_filterTimeline1->setRepeatCount(1);
			m_filterTimeline1->setTarget(item);
			m_filterTimeline1->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
			m_filterTimeline1->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
			m_filterTimeline1->start();

			MyWheelMenuUserData data;
			data.index = getFocus();
			data.isEnter = VFX_FALSE;
			setCellUserData(getFocus(), 0, item, &data, sizeof(MyWheelMenuUserData));

			item = (MyCell*) getCellIfPresent(getFocus()-1);

			if (m_filterTimeline2 == NULL)
			{
				VFX_OBJ_CREATE(m_filterTimeline2, VfxFloatTimeline, this);
			}
			m_filterTimeline2->setFromValue(0.0f);
			m_filterTimeline2->setToValue(1.0f);
			m_filterTimeline2->setDurationTime(2000);
			m_filterTimeline2->setRepeatCount(1);
			m_filterTimeline2->setTarget(item);
			m_filterTimeline2->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
			m_filterTimeline2->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
			m_filterTimeline2->setStartTime(250);
			m_filterTimeline2->start(); 

			data.index = getFocus()-1;
			data.isEnter = VFX_FALSE;
			setCellUserData(getFocus()-1, 0, item, &data, sizeof(MyWheelMenuUserData));


			item = (MyCell*) getCellIfPresent(getFocus()+1);

			if (m_filterTimeline3 == NULL)
			{
				VFX_OBJ_CREATE(m_filterTimeline3, VfxFloatTimeline, this);
			}
			m_filterTimeline3->setFromValue(0.0f);
			m_filterTimeline3->setToValue(1.0f);
			m_filterTimeline3->setDurationTime(2000);
			m_filterTimeline3->setRepeatCount(1);
			m_filterTimeline3->setTarget(item);
			m_filterTimeline3->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
			m_filterTimeline3->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
			m_filterTimeline3->setStartTime(500);
			m_filterTimeline3->start(); 

			data.index = getFocus() + 1;
			data.isEnter = VFX_FALSE;
			setCellUserData(getFocus() + 1, 0, item, &data, sizeof(MyWheelMenuUserData));

			item = (MyCell*) getCellIfPresent(getFocus()-2);

			if (m_filterTimeline4 == NULL)
			{
				VFX_OBJ_CREATE(m_filterTimeline4, VfxFloatTimeline, this);
			}
			m_filterTimeline4->setFromValue(0.0f);
			m_filterTimeline4->setToValue(1.0f);
			m_filterTimeline4->setDurationTime(2000);
			m_filterTimeline4->setRepeatCount(1);
			m_filterTimeline4->setTarget(item);
			m_filterTimeline4->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
			m_filterTimeline4->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
			m_filterTimeline4->setStartTime(750);
			m_filterTimeline4->start(); 

			data.index = getFocus() -2;
			data.isEnter = VFX_FALSE;
			setCellUserData(getFocus() -2, 0, item, &data, sizeof(MyWheelMenuUserData));

			item = (MyCell*) getCellIfPresent(getFocus()+2);

			if (m_filterTimeline5 == NULL)
			{
				VFX_OBJ_CREATE(m_filterTimeline5, VfxFloatTimeline, this);
			}
			m_filterTimeline5->setFromValue(0.0f);
			m_filterTimeline5->setToValue(1.0f);
			m_filterTimeline5->setDurationTime(2000);
			m_filterTimeline5->setRepeatCount(1);
			m_filterTimeline5->setTarget(item);
			m_filterTimeline5->getTarget();
			m_filterTimeline5->setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);
			m_filterTimeline5->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
			m_filterTimeline5->setStartTime(1000);
			m_filterTimeline5->start(); 

			data.index = getFocus() +2;
			data.isEnter = VFX_FALSE;
			setCellUserData(getFocus() +2, 0, item, &data, sizeof(MyWheelMenuUserData));
		}

		// Variable
	protected:
		VfxBool m_cellTextVisible;
		VfxS32  m_count;
		VfxFloatTimeline *m_filterTimeline1;
		VfxFloatTimeline *m_filterTimeline2;
		VfxFloatTimeline *m_filterTimeline3;
		VfxFloatTimeline *m_filterTimeline4;
		VfxFloatTimeline *m_filterTimeline5;
	public:
		VfxFrame *m_movingFrame;
		VfxPoint           m_focusPos2;
	};


	class VTestMatrix : public TestBaseClass
	{
	public:
		typedef VTestMatrix Self;
		typedef TestBaseClass   Super;

		// Variable
	public:
		VfxFrame          *m_background;
		VtstRtSampleMenu11 *m_menu;
		VfxFrame          *m_anotherFrame;
		VcpFrameEffect    *m_frameEffect;
		VfxFrame          *m_movingFrame;
		VfxFrame          *m_movingFrame2;
		VfxPoint           m_focusPos;
		VfxPoint           m_focusPos2;
		VfxBool           m_isLeave;

		// Constructor / Destructor
	public:
		VTestMatrix() : m_menu(NULL) {}

		// Override
	protected:


		virtual VfxBool onKeyInput(VfxKeyEvent &event)
		{
			if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
			{
				if (event.keyCode == VFX_KEY_CODE_1)
				{
#if !defined(__MMI_VUI_COSMOS_CP_SLIM__)
					m_menu->configureStatePara(VCP_WHEEL_MENU_ENTER_STATE, 2000, 250, VCP_WHEEL_MENU_FOCUS_FISRT);
					m_menu->changeState(VCP_WHEEL_MENU_ENTER_STATE);
#endif
					//enter();
				}
				if (event.keyCode == VFX_KEY_CODE_2)
				{
					m_movingFrame = m_menu->pullOutSubCell(m_menu->getFocus(),0);
#if !defined(__MMI_VUI_COSMOS_CP_SLIM__)
					m_menu->configureStatePara(VCP_WHEEL_MENU_LEAVE_STATE, 2000, 250, VCP_WHEEL_MENU_FOCUS_LAST);
					m_menu->changeState(VCP_WHEEL_MENU_LEAVE_STATE);
#endif
					// set pullout frame to the same position but transform = I
					VfxTransform tempTransform = m_movingFrame->forceGetTransform();
					m_focusPos2 = m_movingFrame->getPos();
					m_focusPos = VfxPoint((VfxS32)(m_movingFrame->getPos().x + tempTransform.data.matrix3x3.m[2]), (VfxS32)(m_movingFrame->getPos().y + tempTransform.data.matrix3x3.m[5]));
					VfxAutoAnimate::begin();
					VfxAutoAnimate::setDisable(VFX_TRUE);

					m_movingFrame2->setPos(10 + m_focusPos.x, 50 + m_focusPos.y);
					m_movingFrame2->setBounds(m_movingFrame->getBounds());

					m_movingFrame->setPos(m_focusPos.x, m_focusPos.y);
					// because value of mmi is the same as VfxTransform(), we need set another value first
					m_movingFrame->setTransform(tempTransform);
					m_movingFrame->setTransform(VfxTransform());

					VfxAutoAnimate::commit();

					m_anotherFrame->setHidden(VFX_FALSE);
					m_frameEffect->applyEffect(m_anotherFrame, VCP_EFFECT_TRANSFORMER, 3000, VCP_EFFECT_DIRECTION_FROM_NONE, VFX_FALSE, NULL, 0);
					m_frameEffect->m_signalFinished.connect(this, &VTestMatrix::onFrameEffectFinished);
					m_isLeave = VFX_TRUE;

					VfxAutoAnimate::begin();
					VfxAutoAnimate::setDuration(1000);
					m_movingFrame->setPos(45,55);
					m_movingFrame->setBounds(0, 0, 50, 50);
					m_movingFrame->setOpacity(0);

					m_movingFrame2->setPos(10 + 45, 50 + 55);
					m_movingFrame2->setBounds(0, 0, 50, 50);
					m_movingFrame2->setOpacity(1);
					VfxAutoAnimate::commit();
					//leave();
				}

				if (event.keyCode == VFX_KEY_CODE_3)
				{
					VfxAutoAnimate::begin();
					VfxAutoAnimate::setDuration(1000);
					m_movingFrame->setPos(m_focusPos);
					m_movingFrame->setBounds(0, 0, 160, 60);
					m_movingFrame->setOpacity(1);

					m_movingFrame2->setPos(10 + m_focusPos.x, 50 + m_focusPos.y);
					m_movingFrame2->setBounds(0, 0, 160, 60);
					m_movingFrame2->setOpacity(0);
					VfxAutoAnimate::commit();

					m_menu->setHidden(VFX_FALSE);
#if !defined(__MMI_VUI_COSMOS_CP_SLIM__)
					m_menu->configureStatePara(VCP_WHEEL_MENU_ENTER_STATE, 2000, 250, VCP_WHEEL_MENU_FOCUS_FISRT);
					m_menu->changeState(VCP_WHEEL_MENU_ENTER_STATE);
#endif
					m_anotherFrame->setHidden(VFX_FALSE);
					m_frameEffect->applyEffect(m_anotherFrame, VCP_EFFECT_TRANSFORMER, 3000, VCP_EFFECT_DIRECTION_FROM_NONE, VFX_TRUE, NULL, 0);
					m_frameEffect->m_signalFinished.connect(this, &VTestMatrix::onFrameEffectFinished);
					m_isLeave = VFX_FALSE;

					m_menu->m_movingFrame = m_movingFrame;
					m_menu->m_focusPos2 = m_focusPos2;

					//m_menu->pushInSubCell(m_movingFrame, m_menu->getFocus(),0);
				}

				if (event.keyCode == VFX_KEY_CODE_4)
				{
#if !defined(__MMI_VUI_COSMOS_CP_SLIM__)
					m_menu->configureStatePara(VCP_WHEEL_MENU_ENTER_STATE, 2000, 250, VCP_WHEEL_MENU_INCREASE);
					m_menu->changeState(VCP_WHEEL_MENU_ENTER_STATE);
#endif
				}

				if (event.keyCode == VFX_KEY_CODE_5)
				{
#if !defined(__MMI_VUI_COSMOS_CP_SLIM__)
					m_menu->configureStatePara(VCP_WHEEL_MENU_LEAVE_STATE, 2000, 250, VCP_WHEEL_MENU_DECREASE);
					m_menu->changeState(VCP_WHEEL_MENU_LEAVE_STATE);
#endif
				}

				if (event.keyCode == VFX_KEY_CODE_6)
				{
#if !defined(__MMI_VUI_COSMOS_CP_SLIM__)
					m_menu->configureStatePara(VCP_WHEEL_MENU_ENTER_STATE, 2000, 250, VCP_WHEEL_MENU_ALL_TOGETHER);
					m_menu->changeState(VCP_WHEEL_MENU_ENTER_STATE);
#endif
				}

				if (event.keyCode == VFX_KEY_CODE_7)
				{
					m_movingFrame = m_menu->pullOutSubCell(m_menu->getFocus(),0);
				}

				if (event.keyCode == VFX_KEY_CODE_8)
				{
					m_menu->pushInSubCell(m_movingFrame, m_menu->getFocus(),0);
				}
			}
			return Super::onKeyInput(event);
		}





		void onFrameEffectFinished(VfxFrame *target, VfxBool isCompleted)
		{
			if (isCompleted)
			{
				if (m_isLeave)
				{
					m_menu->setHidden(VFX_TRUE);
					m_menu->m_movingFrame = NULL;
				}
				else
				{
					m_anotherFrame->setHidden(VFX_TRUE);

				}
			}
		}
	public:
		virtual void startTest(VfxWString wstrCaseName,int item_idx)
		{
			TestBaseClass::startTest(wstrCaseName,  item_idx);
			VFX_OBJ_CREATE(m_background, VfxFrame, this);
			m_background->setPos(VfxPoint(10, 50));
			m_background->setBounds(VfxRect(0, 0, 220, 260));
			m_background->setBgColor(VFX_COLOR_BLACK);

			VFX_OBJ_CREATE(m_anotherFrame, VfxFrame, this);
			m_anotherFrame->setPos(VfxPoint(10, 50));
			m_anotherFrame->setBounds(VfxRect(0, 0, 220, 260));

			VfxFrame *tempFrame;


			VFX_OBJ_CREATE(tempFrame, VfxFrame, m_anotherFrame);
			tempFrame->setRect(0, 80, 220, 180);
			tempFrame->setBgColor(VFX_COLOR_GREEN);
			tempFrame->setIsCached(VFX_TRUE);

			VFX_OBJ_CREATE(tempFrame, VfxFrame, m_anotherFrame);
			tempFrame->setRect(0, 220, 220, 40);
			tempFrame->setBgColor(VFX_COLOR_SILVER);
			tempFrame->setIsCached(VFX_TRUE);

			VFX_OBJ_CREATE(tempFrame, VfxFrame, m_anotherFrame);
			tempFrame->setRect(180, 40, 30, 30);
			tempFrame->setBgColor(VFX_COLOR_FUCHSIA);
			tempFrame->setIsCached(VFX_TRUE);

			m_anotherFrame->setHidden(VFX_TRUE);


			// scrollable body
			VFX_OBJ_CREATE(m_menu, VtstRtSampleMenu11, this);

			m_menu->setPos(VfxPoint(10, 50));
			m_menu->setBounds(VfxRect(0, 0, 220, 260));
			m_menu->setFocused(VFX_TRUE);
			m_menu->setCount(50);
			m_menu->setFocus(25);

			VFX_OBJ_CREATE(m_movingFrame2, VfxFrame, this);        
			m_movingFrame2->setRect(20, 30, 160, 60);
			m_movingFrame2->setAnchor(VfxFPoint(0.5, 0.5));
			m_movingFrame2->setBgColor(VFX_COLOR_OLIVE);
			m_movingFrame2->setIsCached(VFX_TRUE);
			m_movingFrame2->setOpacity(0);
			m_movingFrame2->setAutoAnimate(VFX_TRUE);


			VFX_OBJ_CREATE(m_frameEffect, VcpFrameEffect, this);
			confirm(VFX_WSTR("already done,Press Yes"));

		}

	};

	class VfxCJLPopup : public VfxBasePopup 
	{
	public:
		VfxBool m_bEnter;
		VfxBool m_bExit;
		VfxBool m_bRotate;
		VfxBool m_bOutside;

		VfxBool m_bPlayTone;
		VfxBool m_bStopTone;
		VfxBool m_bneedPushHistory;
	protected:
		virtual void onEnter()
		{
			m_bEnter = VFX_TRUE;
		}
		virtual void onExit()
		{
			m_bExit = VFX_TRUE;

		}

		virtual void onPenInputOnOutside(VfxPenEvent & event)
		{
			m_bOutside = VFX_TRUE;
		}

		virtual void onPlayTone()
		{
			m_bPlayTone = VFX_TRUE;
		}
		virtual void onStopTone()
		{
			m_bStopTone = VFX_TRUE;
		}

		virtual VfxBool needPushHistory() const
		{
			return VFX_TRUE;
		}

	};

	class VTestVfxBasePopUp :public TestBaseClass
	{


	public:

		void onCJLPopupStateChanged(VfxBasePopup* popup, VfxBasePopupStateEnum state)
		{

		}

		VfxCJLPopup* m_pPopup;

		void startTest(VfxWString wstrCaseName,int item_idx)
		{


			TestBaseClass::startTest(wstrCaseName,  item_idx);
			VFX_OBJ_CREATE(m_pPopup, VfxCJLPopup, this);

			m_pPopup->m_signalPopupState.connect(this, &VTestVfxBasePopUp::onCJLPopupStateChanged);


			VcpEffectMorphFadeInData input;
			input.fromRect = VfxRect(0,0,100,100);
			m_pPopup->setFrameEffect(VCP_EFFECT_MORPH_FADE_IN, 500, VCP_EFFECT_DIRECTION_FROM_NONE, &input, sizeof(input));


			m_pPopup->setAutoDestory(VFX_TRUE);
			m_pPopup->hide(VFX_TRUE);
			m_pPopup->show(VFX_TRUE);
			m_pPopup->leave(VFX_TRUE);
			m_pPopup->exit(VFX_TRUE);
			confirm(VFX_WSTR("Already done,Press Yes"));
		}
	};

	class VfxCJLObject: public VfxObject
	{

	protected:

		virtual void onInit()
		{

		}


		virtual void onDeinit()
		{

		}
		virtual void onAfterInit()
		{

		}
		virtual void onBeforeDeinit()
		{

		}
		virtual void onAfterDeinit()
		{

		}

		virtual void onAddChild(VfxObject * childObj)
		{

		}

		virtual void onRemoveChild(VfxObject * childObj)
		{

		}
	};

	class VTestVfxObject:public TestBaseClass
	{
	public:
		VfxCJLObject* m_p;
		VfxCJLObject* m_p1;

		void startTest(VfxWString wstrCaseName,int item_idx)
		{
			TestBaseClass::startTest(wstrCaseName,  item_idx);
			VFX_OBJ_CREATE(m_p, VfxCJLObject, this);
			VFX_OBJ_CREATE(m_p1, VfxCJLObject, m_p);

            m_p->getChildCount();
			m_p->isKindOf(NULL);
			VfxObject::handleToObject(m_p->getObjHandle());

            VFX_OBJ_CLOSE(m_p);

			confirm(VFX_WSTR("Already done,Press Yes"));
		} 
	};



	class VTestVfxObjectList : public TestBaseClass
	{
	public:

		void startTest(VfxWString wstrCaseName,int item_idx)
		{

			TestBaseClass::startTest(wstrCaseName,  item_idx);
			VfxObjList pList1 ;
			VfxObjList pList2;
			VfxObjListEntry * pTemp = NULL;
			VfxCJLObject* pObject = NULL;
			VfxCJLObject* pObject1 = NULL;
			VfxCJLObject* pObject2 = NULL;
			VfxCJLObject* pObject3 = NULL;
			VfxBool b;
			VFX_OBJ_CREATE(pObject, VfxCJLObject, this);
			VFX_OBJ_CREATE(pObject1, VfxCJLObject, this);
			VFX_OBJ_CREATE(pObject2, VfxCJLObject, this);
			VFX_OBJ_CREATE(pObject3, VfxCJLObject, this);


//			pTemp = pTemp;
//			b = b;
			pList2 = pList1;
			pTemp = pList1.getHead();
			pTemp = pList1.getTail();
			pTemp = pList1.getValidHead();
			pTemp = pList1.getValidTail();
			b = pList1.isEmpty();
			VfxU32 count = pList1.getEntryCount();
			count = pList1.getValidCount();
			pList1.contains(pObject);

			VfxObjListEntry *pAppend = 	 pList1.append(pObject);
			VfxObjListEntry *pPrepend = 	 pList1.prepend(pObject3);
			pAppend->get();
			pAppend->getPrev();
			pAppend->getNext();
			pAppend->getValidPrev();
			pAppend->getValidNext();
			pList1.insertBefore(pAppend,pObject1);
			pList1.insertAfter(pAppend,pObject2);
			pList1.removePos(pAppend);
			pList1.removeOne(pObject2);
			pList1.removeAllInvalidate();
			pList1.clear();
			VFX_OBJ_CLOSE(pObject);
			VFX_OBJ_CLOSE(pObject1);
			VFX_OBJ_CLOSE(pObject2);
			VFX_OBJ_CLOSE(pObject3);
			confirm(VFX_WSTR("Already done,Press Yes"));	
		}
	};

	class VTestVfxPointTimeLine:public TestBaseClass
	{
	public:
		VfxPointTimeline* m_timelineTarget;
		VfxFrame* m_target;

		void startTest(VfxWString wstrCaseName,int item_idx)
		{

			TestBaseClass::startTest(wstrCaseName,  item_idx);
			TestFunction();
			confirm(VFX_WSTR("see animation?"));	

		}
		void TestFunction()
		{

			VFX_OBJ_CREATE(m_target, VfxFrame, this);
			m_target->setRect(VfxRect(10, 50 , 30, 30));
			m_target->setBorderColor(VFX_COLOR_RED);
			m_target->setBorderWidth(1);
			VFX_OBJ_CREATE(m_timelineTarget, VfxPointTimeline, this);
			m_timelineTarget->setTarget(m_target);
			m_timelineTarget->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
			m_timelineTarget->setStartDelay(0);
			m_timelineTarget->setDurationTime(500);
			m_timelineTarget->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
			m_timelineTarget->setAutoReversed(VFX_TRUE);
			m_timelineTarget->setFromValue(VfxPoint(10, 50 ));
			m_timelineTarget->setToValue(VfxPoint(200, 50 ));
			m_timelineTarget->start();


		}
	};

	VfxU8 pool[2048] = {0};

	class VTestVfxS32Timeline:public TestBaseClass
	{
	public:
		VfxS32Timeline *xPosTimeline;

		VfxFrame* m_target;

		void startTest(VfxWString wstrCaseName,int item_idx)
		{

			TestBaseClass::startTest(wstrCaseName,  item_idx);

			//
			VfxContext* pContext = NULL;
			VFX_OBJ_CREATE(pContext, VfxContext, VFX_SYS_GLOBAL_CONTEXT);
			pContext->assignPool(pool,2048);
			VFX_OBJ_CLOSE(pContext);




			//		
			VFX_OBJ_CREATE(m_target, VfxFrame, this);
			m_target->setRect(VfxRect(0, 0 , 30, 30));
			m_target->setBorderColor(VFX_COLOR_RED);
			m_target->setBorderWidth(1);
			m_target->setBgColor(VFX_COLOR_RED);



			//

			VfxColorTimeline *timeline2;
			VFX_OBJ_CREATE(timeline2, VfxColorTimeline, this);
			timeline2->setTarget(m_target);
			timeline2->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BACKGROUND_COLOR);
			timeline2->setFromValue(VFX_COLOR_RED);
			timeline2->setToValue(VFX_COLOR_BLUE);
			timeline2->setDurationTime(1000);
			timeline2->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
			timeline2->setAutoReversed(VFX_TRUE);
			timeline2->start();


			//


			VFX_OBJ_CREATE(xPosTimeline, VfxS32Timeline, this);
			xPosTimeline->setTarget(m_target);
			xPosTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
			xPosTimeline->setDurationTime(1000);
			xPosTimeline->setRepeatDuration(500);
			xPosTimeline->setAutoReversed(VFX_TRUE);
			xPosTimeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
			xPosTimeline->setFromValue(0);
			xPosTimeline->setToValue(100);
			xPosTimeline->getFromValue();
			xPosTimeline->getToValue();


			xPosTimeline->start(); 

			confirm(VFX_WSTR("see animation?"));	
		} 
	};


	class VTestVfxSizeTimeLine : public TestBaseClass
	{
	public:
		VfxFrame* m_target;
		VfxSizeTimeline* m_sizeTimeline;

		void startTest(VfxWString wstrCaseName,int item_idx) 
		{

			TestBaseClass::startTest(wstrCaseName, item_idx);

			VFX_OBJ_CREATE(m_target, VfxFrame, this);
			m_target->setRect(VfxRect(0, 0 , 30, 30));
			m_target->setBorderColor(VFX_COLOR_RED);
			m_target->setBorderWidth(1);

			VFX_OBJ_CREATE(m_sizeTimeline, VfxSizeTimeline, this);
			m_sizeTimeline->setTarget(m_target);
			m_sizeTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BOUNDS_SIZE);
			m_sizeTimeline->setDurationTime(1000);

			m_sizeTimeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);

			m_sizeTimeline->setFromValue(VfxSize(30, 30));
			m_sizeTimeline->setToValue(VfxSize(100, 100));
			m_sizeTimeline->start();
			confirm(VFX_WSTR("see animation?"));

		}

	};


	class VTestVfxScreen : public TestBaseClass
	{
	public:


		void startTest(VfxWString wstrCaseName,int item_idx) 
		{

			TestBaseClass::startTest(wstrCaseName, item_idx);
			VfxScreen* pScreen;

			VFX_OBJ_CREATE(pScreen, VfxScreen, this);
			if(pScreen->isPopupPresent())
			{
				pScreen->getActivePopup();
				pScreen->clearPopupStack();
			}

			//only 11A
//			pScreen->getContext();  
//			pScreen->setIsSmallScreen();
			VFX_OBJ_CLOSE(pScreen);
			confirm(VFX_WSTR("already done,press yes"));

		}

	};

	class VTestVfxTimer:public TestBaseClass
	{

	protected:
		void onTimerTick(VfxTimer *source)
		{
			VFX_UNUSED(source);


			VfxAutoAnimate::begin();
			VfxAutoAnimate::setDuration(2000);
			VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);

			if (m_tickCount & 0x1)
			{
				m_frame->setPos(VfxPoint(10, 50));
			}
			else
			{
				m_frame->setPos(VfxPoint(170, 50));
			}

			VfxAutoAnimate::commit();

			m_tickCount++;
		}

	public:
		VfxFrame           *m_box0;
		VfxFrame           *m_box1;
		VfxFrame           *m_frame;
		VfxTimer           *m_timer;
		VfxS32              m_tickCount;

		static VfxFloat fooTimingFunc(VfxFloat t, void *data, VfxU32 dataSize)
		{
			return t;
		}
		void startTest(VfxWString wstrCaseName,int item_idx) 
		{
			TestBaseClass::startTest(wstrCaseName, item_idx);

			m_tickCount = 0;

			VFX_OBJ_CREATE(m_box0, VfxFrame, this);
			m_box0->setRect(VfxRect(10, 50, 30, 30));
			m_box0->setBgColor(VFX_COLOR_RED);

			VFX_OBJ_CREATE(m_box0, VfxFrame, this);
			m_box0->setRect(VfxRect(170, 50, 30, 30));
			m_box0->setBgColor(VFX_COLOR_RED);

			VFX_OBJ_CREATE(m_frame, VfxFrame, this);
			m_frame->setRect(VfxRect(100, 50, 30, 30));
			m_frame->setBgColor(VFX_COLOR_YELLOW);
			m_frame->setAutoAnimate(VFX_TRUE);

			VFX_OBJ_CREATE(m_timer, VfxTimer, this);
			m_timer->setDuration(2000);
			m_timer->m_signalTick.connect(this, &VTestVfxTimer::onTimerTick);

			m_timer->setStartDelay(0);
			m_timer->getStartDelay();
			m_timer->getCurrentTime();
			m_timer->getIsEnabled();

			VfxAutoAnimate::begin();
			VfxAutoAnimate::setDuration(1000);
			VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
			m_frame->setPos(VfxPoint(10, 50));
			VfxAutoAnimate::commit();



			VfxAutoAnimate::begin();
			void *data = this;
			VfxAutoAnimate::setCustomTimingFunc(fooTimingFunc, &data, sizeof(data));
			setBgColor(VFX_COLOR_SILVER);

			VfxAutoAnimate::commit();

			m_timer->stop();
			m_timer->start();
			confirm(VFX_WSTR("see animation"));
		}

	};





	class VtstWaveFilter1 : public VfxFrameFilter
	{
		// Vairable
	public:
		VfxS32 m_distance;

		// Constructor / Destructor
	public:
		VtstWaveFilter1(){m_distance=0;}

		// Override
	protected:
		virtual BufferModeEnum onGetBufferMode() const
		{
			return BUFFER_MODE_OUT_OF_PLACE;
		}

		virtual VfxBool onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat level)
		{
			VfxImageBuffer a;

			getResource('CJL', a);
			return VFX_TRUE;
		}

		virtual void onInit()
		{
			VfxFrameFilter::onInit();
			setResourceFromResId('CJL',IMG_GLOBAL_L1);
		}
	};

	class VTestVfxFrameFilter:public TestBaseClass
	{
	public:
		VtstWaveFilter1* m_pFilter;

		void startTest(VfxWString wstrCaseName,int item_idx)
		{

			TestBaseClass::startTest(wstrCaseName, item_idx);
			VFX_OBJ_CREATE(m_pFilter, VtstWaveFilter1, this);
			m_pFilter->m_distance = 5;

			VfxTextFrame *text_frame;
			VFX_OBJ_CREATE(text_frame, VfxTextFrame, this);
			text_frame->setAutoResized(VFX_FALSE);
			text_frame->setPos(VfxPoint(0, 30));
			text_frame->setBounds(VfxRect(0, 0, 240, 40));
			text_frame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
			text_frame->setFilter(m_pFilter);

			VfxFloatTimeline *timeline;
			VFX_OBJ_CREATE(timeline, VfxFloatTimeline, this);
			timeline->setFromValue(0.0f);
			timeline->setToValue(1.0f);
			timeline->setDurationTime(1000);
			timeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
			timeline->setTarget(text_frame);
			timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
			timeline->start();  
			confirm(VFX_WSTR("already done,press yes"));
		}

	};

	class VTestMacro : public VfxObject
	{
		VFX_DECLARE_CLASS(VTestMacro);
	};

	VFX_IMPLEMENT_CLASS("VTestMacro", VTestMacro, VfxObject);

	class VfxCJLVisual: public VfxObject
	{
		VFX_DECLARE_CLASS(VfxCJLVisual);
	};

	VFX_IMPLEMENT_VIRTUAL_CLASS("VfxCJLVisual", VfxCJLVisual, VfxObject);


	class VfxCJLSigletion : public VfxObject
	{
		VFX_DECLARE_CLASS(VfxCJLSigletion);
		VFX_OBJ_DECLARE_SINGLETON_CLASS(VfxCJLSigletion);

    protected:
        virtual vrt_allocator_handle getAllocator()
        {
            VFX_ASSERT(0);
            return VfxObject::getAllocator();
        }
    };
	VFX_IMPLEMENT_CLASS("VfxCJLSigletion", VfxCJLSigletion, VfxObject);    
	VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VfxCJLSigletion);


	class MyClassCJL
	{
		VFX_DECLARE_NO_ASSIGN_CLASS(MyClassCJL);


	};

	class MyNoCopy
	{
		VFX_DECLARE_NO_COPY_CLASS(MyNoCopy);

	};
	VFX_IMPLEMENT_CONST(g_my_implement_const, VfxImageSrc, ());


	class VTestVfxLayerControl: public TestBaseClass
	{

	public:
		VfxLayerControl* m_pLayerControl;
		void startTest(VfxWString wstrCaseName,int item_idx) 
		{
			TestBaseClass::startTest(wstrCaseName, item_idx);

			VFX_OBJ_CREATE(m_pLayerControl, VfxLayerControl, this);
			m_pLayerControl->setIsOnTop(VFX_FALSE);
			m_pLayerControl->setHidden(VFX_FALSE);
			m_pLayerControl->setLayerHandle(0);
			confirm(VFX_WSTR("Already Done,Press Yes"));
			VFX_OBJ_CLOSE(m_pLayerControl);
		}
	};


	class VTestVfxVideoFrame: public TestBaseClass
	{
	public:
		VfxVideoFrame  *m_videoFrame;
	protected:

		virtual void onInit()
		{
			TestBaseClass::onInit();
			VFX_OBJ_CREATE(m_videoFrame, VfxVideoFrame, this);
			m_videoFrame->setPos(100, 120);
			m_videoFrame->setSize(160, 120);
			m_videoFrame->setMultimediaType(VfxVideoFrame::MULTIMEDIA_CAMERA);
			m_videoFrame->setBuffer(ASM_ANONYMOUS_ID);
			m_videoFrame->prepare();
			m_videoFrame->getIsReady();
			m_videoFrame->getDisplayLayerFlag();
			m_videoFrame->getHwLayerFlag();
			m_videoFrame->getLayerHandle();

		}

		virtual void onDeinit()
		{
			m_videoFrame->unPrepare();
			TestBaseClass::onDeinit();
		}



	public:
		void startTest(VfxWString wstrCaseName,int item_idx) 
		{
			TestBaseClass::startTest(wstrCaseName, item_idx);
			confirm(VFX_WSTR("already done,press yes"));
		}
	};







	VTestPME* g_pVTestPME;
	VTestVfxAnimation* g_pVTestVfxAnimation;
	VTestVfxFPointTimeline* g_pVTestVfxFPointTimeline;
	VTestVfxTransformTimeline* g_pVTestVfxTransformTimeline;
	VTestVfxRectTimeline* g_pVTestVfxRectTimeline;
	VTestVfxTopLevel* g_pVTestVfxTopLevel;
	VTestVfxImageFrame* g_pVTestVfxImageFrame;
	VTestVfxControl* g_pVTestVfxControl;
	VTestVfxDrawContext* g_pVTestVfxDrawContext;
	VTestBase * g_pVTestBase;
	VTestMatrix* g_pVTestMatrix;
	VTestVfxBasePopUp* g_pVTestVfxBasePopUp;
	VTestVfxObject* g_pVTestVfxObject;
	VTestVfxObjectList* g_pVTestVfxObjectList;
	VTestVfxPointTimeLine* g_pVTestVfxPointTimeLine;
	VTestVfxS32Timeline* g_pVTestVfxS32Timeline;
	VTestVfxSizeTimeLine* g_pVTestVfxSizeTimeLine;
	VTestVfxScreen* g_pVTestVfxScreen;
	VTestVfxTimer* g_pVTestVfxTimer;
	VTestVfxFrameFilter* g_pVTestVfxFrameFilter;
	VTestVfxLayerControl* g_pVTestVfxLayerControl;
	VTestVfxVideoFrame* g_pVTestVfxVideoFrame;

#endif





	void vs_venus_001(void)
	{

#ifdef __VENUS_UI_ENGINE__

		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_001_exit, vs_venus_001, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}
		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestPME, VTestPME, VfxAppCatScr::getContext());
		g_pVTestPME->startTest(VFX_WSTR("vs_venus_001"),1);
#else
		WCHAR wszBuf[] = {'v','s','\0'};

		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_001);
#endif
	}



	void vs_venus_002(void)
	{
#ifdef __VENUS_UI_ENGINE__

		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_002_exit, vs_venus_002, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}
		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestVfxAnimation, VTestVfxAnimation, VfxAppCatScr::getContext());
		g_pVTestVfxAnimation->startTest(VFX_WSTR("vs_venus_002"),2);
#else
		WCHAR wszBuf[] = {'v','s','\0'};

		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_002);
#endif
	}


	void vs_venus_003(void)
	{
#ifdef __VENUS_UI_ENGINE__

		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_003_exit, vs_venus_003, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}

		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestVfxFPointTimeline, VTestVfxFPointTimeline, VfxAppCatScr::getContext());
		g_pVTestVfxFPointTimeline->startTest(VFX_WSTR("vs_venus_003"),3);
#else
		WCHAR wszBuf[] = {'v','s','\0'};

		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_003);
#endif
	}



	void vs_venus_004(void)
	{
#ifdef __VENUS_UI_ENGINE__

		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_004_exit, vs_venus_004, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}

		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestVfxTransformTimeline, VTestVfxTransformTimeline, VfxAppCatScr::getContext());
		g_pVTestVfxTransformTimeline->startTest(VFX_WSTR("vs_venus_004"),4);
#else
		WCHAR wszBuf[] = {'v','s','\0'};

		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_004);
#endif
	}



	void vs_venus_005(void)
	{
#ifdef __VENUS_UI_ENGINE__


		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_005_exit, vs_venus_005, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}
		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestVfxRectTimeline, VTestVfxRectTimeline, VfxAppCatScr::getContext());
		g_pVTestVfxRectTimeline->startTest(VFX_WSTR("vs_venus_005"),5);
#else
		WCHAR wszBuf[] = {'v','s','\0'};

		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_005);
#endif
	}



	void vs_venus_006(void)
	{
#ifdef __VENUS_UI_ENGINE__

		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_006_exit, vs_venus_006, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}
		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestVfxTopLevel, VTestVfxTopLevel, VfxAppCatScr::getContext());
		g_pVTestVfxTopLevel->startTest(VFX_WSTR("vs_venus_006"),6);
#else
		WCHAR wszBuf[] = {'v','s','\0'};

		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_006);
#endif
	}





	void vs_venus_007(void)
	{
#ifdef __VENUS_UI_ENGINE__

		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_007_exit, vs_venus_007, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}
		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestVfxImageFrame, VTestVfxImageFrame, VfxAppCatScr::getContext());
		g_pVTestVfxImageFrame->startTest(VFX_WSTR("vs_venus_007"),7);
#else
		WCHAR wszBuf[] = {'v','s','\0'};

		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_007);
#endif
	}




	void vs_venus_008(void)
	{
#ifdef __VENUS_UI_ENGINE__


		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_008_exit, vs_venus_008, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}
		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestVfxControl, VTestVfxControl, VfxAppCatScr::getContext());
		g_pVTestVfxControl->startTest(VFX_WSTR("vs_venus_008"),8);
#else
		WCHAR wszBuf[] = {'v','s','\0'};

		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_008);
#endif

	}



	void vs_venus_009(void)
	{
#ifdef __VENUS_UI_ENGINE__

		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_009_exit, vs_venus_009, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}
		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestVfxDrawContext, VTestVfxDrawContext, VfxAppCatScr::getContext());
		g_pVTestVfxDrawContext->startTest(VFX_WSTR("vs_venus_009"),9);
#else
		WCHAR wszBuf[] = {'v','s','\0'};

		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_009);
#endif
	}



	void vs_venus_010(void)
	{

#ifdef __VENUS_UI_ENGINE__

		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_010_exit, vs_venus_010, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}
		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestBase, VTestBase, VfxAppCatScr::getContext());
		g_pVTestBase->startTest(VFX_WSTR("vs_venus_010"),10);
#else
		WCHAR wszBuf[] = {'v','s','\0'};

		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_010);
#endif
	}


	void vs_venus_011(void)
	{
#ifdef __VENUS_UI_ENGINE__

		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_011_exit, vs_venus_011, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}
		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestMatrix, VTestMatrix, VfxAppCatScr::getContext());
		g_pVTestMatrix->startTest(VFX_WSTR("vs_venus_011"),11);
#else
		WCHAR wszBuf[] = {'v','s','\0'};

		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_011);
#endif
	}



	void vs_venus_012(void)
	{
#ifdef __VENUS_UI_ENGINE__

		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_012_exit, vs_venus_012, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}
		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestVfxBasePopUp, VTestVfxBasePopUp, VfxAppCatScr::getContext());
		g_pVTestVfxBasePopUp->startTest(VFX_WSTR("vs_venus_012"),12);
#else
		WCHAR wszBuf[] = {'v','s','\0'};
		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_012);
#endif

	}


	void vs_venus_013(void)
	{
#ifdef __VENUS_UI_ENGINE__

		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_013_exit, vs_venus_013, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}
		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestVfxObject, VTestVfxObject, VfxAppCatScr::getContext());
		g_pVTestVfxObject->startTest(VFX_WSTR("vs_venus_013"),13);
#else
		WCHAR wszBuf[] = {'v','s','\0'};
		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_013);
#endif
	}


	void vs_venus_014(void)
	{


#ifdef __VENUS_UI_ENGINE__

		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_014_exit, vs_venus_014, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}
		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestVfxObjectList, VTestVfxObjectList, VfxAppCatScr::getContext());
		g_pVTestVfxObjectList->startTest(VFX_WSTR("vs_venus_014"),14);
#else
		WCHAR wszBuf[] = {'v','s','\0'};
		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_014);
#endif
	}



	void vs_venus_015(void)
	{
#ifdef __VENUS_UI_ENGINE__

		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_015_exit, vs_venus_015, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}
		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestVfxPointTimeLine, VTestVfxPointTimeLine, VfxAppCatScr::getContext());
		g_pVTestVfxPointTimeLine->startTest(VFX_WSTR("vs_venus_015"),15);
#else
		WCHAR wszBuf[] = {'v','s','\0'};
		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_015);
#endif

	}


	void vs_venus_016(void)
	{
#ifdef __VENUS_UI_ENGINE__

		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_016_exit, vs_venus_016, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}
		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestVfxS32Timeline, VTestVfxS32Timeline, VfxAppCatScr::getContext());
		g_pVTestVfxS32Timeline->startTest(VFX_WSTR("vs_venus_016"),16);
#else
		WCHAR wszBuf[] = {'v','s','\0'};
		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_016);
#endif
	}

	void vs_venus_017(void)
	{

#ifdef __VENUS_UI_ENGINE__

		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_017_exit, vs_venus_017, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}
		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestVfxSizeTimeLine, VTestVfxSizeTimeLine, VfxAppCatScr::getContext());
		g_pVTestVfxSizeTimeLine->startTest(VFX_WSTR("vs_venus_017"),17);
#else
		WCHAR wszBuf[] = {'v','s','\0'};
		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_017);
#endif

	}

	void vs_venus_018(void)
	{
#ifdef __VENUS_UI_ENGINE__

		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_018_exit, vs_venus_018, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}
		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestVfxScreen, VTestVfxScreen, VfxAppCatScr::getContext());
		g_pVTestVfxScreen->startTest(VFX_WSTR("vs_venus_018"),18);
#else
		WCHAR wszBuf[] = {'v','s','\0'};
		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_018);
#endif


	}
	void vs_venus_019(void)
	{
#ifdef __VENUS_UI_ENGINE__

		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_019_exit, vs_venus_019, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}
		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestVfxTimer, VTestVfxTimer, VfxAppCatScr::getContext());
		g_pVTestVfxTimer->startTest(VFX_WSTR("vs_venus_019"),19);
#else
		WCHAR wszBuf[] = {'v','s','\0'};
		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_019);
#endif
	}

	void vs_venus_020(void)
	{

#ifdef __VENUS_UI_ENGINE__

		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_020_exit, vs_venus_020, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}
		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestVfxFrameFilter, VTestVfxFrameFilter, VfxAppCatScr::getContext());
		g_pVTestVfxFrameFilter->startTest(VFX_WSTR("vs_venus_020"),20);
#else
		WCHAR wszBuf[] = {'v','s','\0'};
		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_020);
#endif

	}


	void vs_venus_021(void)
	{

#ifdef __VENUS_UI_ENGINE__

		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_021_exit, vs_venus_021, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}
		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestVfxLayerControl, VTestVfxLayerControl, VfxAppCatScr::getContext());
		g_pVTestVfxLayerControl->startTest(VFX_WSTR("vs_venus_021"),21);
#else
		WCHAR wszBuf[] = {'v','s','\0'};
		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_021);
#endif

	}

	void vs_venus_022(void)
	{

#ifdef __VENUS_UI_ENGINE__

		MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_022_exit, vs_venus_022, MMI_FRM_FULL_SCRN);

		if (ret == MMI_FALSE)
		{
			return;
		}
		VfxAppCatScr::initalize();
		VFX_OBJ_CREATE(g_pVTestVfxVideoFrame, VTestVfxVideoFrame, VfxAppCatScr::getContext());
		g_pVTestVfxVideoFrame->startTest(VFX_WSTR("vs_venus_022"),22);
#else
		WCHAR wszBuf[] = {'v','s','\0'};
		//CJL_VS_TFW_SHOW_PLATFORM_NOT_SUPPORT(wszBuf, VS_TA_FW_VENUS, VS_VENUS_FW_022);
#endif

	}




	void vs_venus_001_exit(void)
	{
#ifdef __VENUS_UI_ENGINE__
		VFX_OBJ_CLOSE(g_pVTestPME);
		VfxAppCatScr::deinitalize();
#endif

	}
	void vs_venus_002_exit(void)
	{
#ifdef __VENUS_UI_ENGINE__
		VFX_OBJ_CLOSE(g_pVTestVfxAnimation);
		VfxAppCatScr::deinitalize();
#endif
	}

	void vs_venus_003_exit(void)
	{
#ifdef __VENUS_UI_ENGINE__

		VFX_OBJ_CLOSE(g_pVTestVfxFPointTimeline);
		VfxAppCatScr::deinitalize();
#endif
	}
	void vs_venus_004_exit(void)
	{
#ifdef __VENUS_UI_ENGINE__

		VFX_OBJ_CLOSE(g_pVTestVfxTransformTimeline);
		VfxAppCatScr::deinitalize();
#endif
	}
	void vs_venus_005_exit(void)
	{
#ifdef __VENUS_UI_ENGINE__

		VFX_OBJ_CLOSE(g_pVTestVfxRectTimeline);
		VfxAppCatScr::deinitalize();
#endif
	}
	void vs_venus_006_exit(void)
	{
#ifdef __VENUS_UI_ENGINE__

		VFX_OBJ_CLOSE(g_pVTestVfxTopLevel);
		VfxAppCatScr::deinitalize();
#endif
	}
	void vs_venus_007_exit(void)
	{
#ifdef __VENUS_UI_ENGINE__

		VFX_OBJ_CLOSE(g_pVTestVfxImageFrame);
		VfxAppCatScr::deinitalize();
#endif
	}
	void vs_venus_008_exit(void)
	{
#ifdef __VENUS_UI_ENGINE__

		VFX_OBJ_CLOSE(g_pVTestVfxControl);
		VfxAppCatScr::deinitalize();
#endif
	}

	void vs_venus_009_exit(void)
	{
#ifdef __VENUS_UI_ENGINE__

		VFX_OBJ_CLOSE(g_pVTestVfxDrawContext);
		VfxAppCatScr::deinitalize();
#endif
	}

	void vs_venus_010_exit(void)
	{
#ifdef __VENUS_UI_ENGINE__

		VFX_OBJ_CLOSE(g_pVTestBase);
		VfxAppCatScr::deinitalize();
#endif

	}

	void vs_venus_011_exit(void)
	{
#ifdef __VENUS_UI_ENGINE__

		VFX_OBJ_CLOSE(g_pVTestMatrix);
		VfxAppCatScr::deinitalize();
#endif
	}

	void vs_venus_012_exit(void)
	{
#ifdef __VENUS_UI_ENGINE__

		VFX_OBJ_CLOSE(g_pVTestVfxBasePopUp);
		VfxAppCatScr::deinitalize();
#endif


	}
	void vs_venus_013_exit(void)
	{
#ifdef __VENUS_UI_ENGINE__

		VFX_OBJ_CLOSE(g_pVTestVfxObject);
		VfxAppCatScr::deinitalize();
#endif
	}
	void vs_venus_014_exit(void)
	{


#ifdef __VENUS_UI_ENGINE__

		VFX_OBJ_CLOSE(g_pVTestVfxObjectList);
		VfxAppCatScr::deinitalize();
#endif
	}
	void vs_venus_015_exit(void)
	{				
#ifdef __VENUS_UI_ENGINE__

		VFX_OBJ_CLOSE(g_pVTestVfxPointTimeLine);
		VfxAppCatScr::deinitalize();
#endif


	}
	void vs_venus_016_exit(void)
	{				
#ifdef __VENUS_UI_ENGINE__

		VFX_OBJ_CLOSE(g_pVTestVfxS32Timeline);
		VfxAppCatScr::deinitalize();
#endif


	}

	void vs_venus_017_exit(void)
	{		
#ifdef __VENUS_UI_ENGINE__

		VFX_OBJ_CLOSE(g_pVTestVfxSizeTimeLine);
		VfxAppCatScr::deinitalize();
#endif

	}
	void vs_venus_018_exit(void)
	{		
#ifdef __VENUS_UI_ENGINE__

		VFX_OBJ_CLOSE(g_pVTestVfxScreen);
		VfxAppCatScr::deinitalize();
#endif		

	}
	void vs_venus_019_exit(void)
	{		
#ifdef __VENUS_UI_ENGINE__

		VFX_OBJ_CLOSE(g_pVTestVfxTimer);
		VfxAppCatScr::deinitalize();
#endif

	}
	void vs_venus_020_exit(void)
	{	
#ifdef __VENUS_UI_ENGINE__

		VFX_OBJ_CLOSE(g_pVTestVfxFrameFilter);
		VfxAppCatScr::deinitalize();
#endif


	}

	void vs_venus_021_exit(void)
	{	
#ifdef __VENUS_UI_ENGINE__

		VFX_OBJ_CLOSE(g_pVTestVfxLayerControl);
		VfxAppCatScr::deinitalize();
#endif


	}
		void vs_venus_022_exit(void)
		{	
#ifdef __VENUS_UI_ENGINE__
	
			VFX_OBJ_CLOSE(g_pVTestVfxVideoFrame);
			VfxAppCatScr::deinitalize();
#endif
	
	
		}






#ifdef __cplusplus
} 
#endif 

#endif /* __MAUI_SDK_TEST__ */




AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_001,L"VENUS_UI_ENGINE_001",AVK_VENUS_ENGINE);
AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_002,L"VENUS_UI_ENGINE_002",AVK_VENUS_ENGINE);
AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_003,L"VENUS_UI_ENGINE_003",AVK_VENUS_ENGINE);
AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_004,L"VENUS_UI_ENGINE_004",AVK_VENUS_ENGINE);
AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_005,L"VENUS_UI_ENGINE_005",AVK_VENUS_ENGINE);
AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_006,L"VENUS_UI_ENGINE_006",AVK_VENUS_ENGINE);
AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_007,L"VENUS_UI_ENGINE_007",AVK_VENUS_ENGINE);
AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_008,L"VENUS_UI_ENGINE_008",AVK_VENUS_ENGINE);
AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_009,L"VENUS_UI_ENGINE_009",AVK_VENUS_ENGINE);
AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_010,L"VENUS_UI_ENGINE_010",AVK_VENUS_ENGINE);
AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_011,L"VENUS_UI_ENGINE_011",AVK_VENUS_ENGINE);
AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_012,L"VENUS_UI_ENGINE_012",AVK_VENUS_ENGINE);
AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_013,L"VENUS_UI_ENGINE_013",AVK_VENUS_ENGINE);
AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_014,L"VENUS_UI_ENGINE_014",AVK_VENUS_ENGINE);
AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_015,L"VENUS_UI_ENGINE_015",AVK_VENUS_ENGINE);
AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_016,L"VENUS_UI_ENGINE_016",AVK_VENUS_ENGINE);
AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_017,L"VENUS_UI_ENGINE_017",AVK_VENUS_ENGINE);
AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_018,L"VENUS_UI_ENGINE_018",AVK_VENUS_ENGINE);
AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_019,L"VENUS_UI_ENGINE_019",AVK_VENUS_ENGINE);
AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_020,L"VENUS_UI_ENGINE_020",AVK_VENUS_ENGINE);
AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_021,L"VENUS_UI_ENGINE_021",AVK_VENUS_ENGINE);
AVK_ADD_ITEM(AVK_VENUS_UI_ITEM_022,L"VENUS_UI_ENGINE_022",AVK_VENUS_ENGINE);


AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL1,AVK_VENUS_UI_ITEM_001)
{    
	vs_venus_001();

}

AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL2,AVK_VENUS_UI_ITEM_002)
{
	vs_venus_002();

}

AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL3,AVK_VENUS_UI_ITEM_003)
{
	vs_venus_003();

}

AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL4,AVK_VENUS_UI_ITEM_004)
{
	vs_venus_004();

}

AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL5,AVK_VENUS_UI_ITEM_005)
{
	vs_venus_005();
}

AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL6,AVK_VENUS_UI_ITEM_006)
{
	vs_venus_006();

}

AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL7,AVK_VENUS_UI_ITEM_007)
{
	vs_venus_007();

}

AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL8,AVK_VENUS_UI_ITEM_008)
{
	vs_venus_008();

}

AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL9,AVK_VENUS_UI_ITEM_009)
{
	vs_venus_009();
}

AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL10,AVK_VENUS_UI_ITEM_010)
{
	vs_venus_010();
}

AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL11,AVK_VENUS_UI_ITEM_011)
{
	vs_venus_011();
}

AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL12,AVK_VENUS_UI_ITEM_012)
{
	vs_venus_012();
}

AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL13,AVK_VENUS_UI_ITEM_013)
{
	vs_venus_013();
}

AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL14,AVK_VENUS_UI_ITEM_014)
{
	vs_venus_014();
}

AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL15,AVK_VENUS_UI_ITEM_015)
{
	vs_venus_015();
}

AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL16,AVK_VENUS_UI_ITEM_016)
{
	vs_venus_016();
}

AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL17,AVK_VENUS_UI_ITEM_017)
{
	vs_venus_017();
}

AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL18,AVK_VENUS_UI_ITEM_018)
{
	vs_venus_018();
}

AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL19,AVK_VENUS_UI_ITEM_019)
{
	vs_venus_019();
}

AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL20,AVK_VENUS_UI_ITEM_020)
{
	vs_venus_020();
}

AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL21,AVK_VENUS_UI_ITEM_021)
{
	vs_venus_021();
}

AVK_MANUAL_CASE(AVK_VENUS_UI_MANUAL22,AVK_VENUS_UI_ITEM_022)
{
	vs_venus_022();
}

