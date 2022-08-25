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





#ifdef __VENUS_3D_UI_ENGINE__

    
#include "vfx_config.h"       

#include "vfx_frame.h"
#include "vfx_animation.h"
#include "vfx_world.h"
#include "vfx_camera.h"
#include "vfx_light.h"
#include "vfx_mesh.h"
#include "vfx_material.h"
#include "vfx_pass.h"
#include "vfx_shader.h"
#include "vfx_shader_uniforms.h"
#include "vfx_bounding_volume.h"
#include "vfx_texture.h"
#include "vfx_skinned_mesh.h"
#include "vfx_compositing_mode.h"
#include "vfx_blender.h"
#include "vfx_render_buffer.h"
#include "vfx_asset_loader.h"
#include "vcp_button.h"
#include "vcp_slider.h"
#include "gles2\gl2.h"
#include "vfx_owner_draw.h"
#include "vfx_polygon_mode.h"
#include "vfx_stencil.h"
#include "vfx_render_target.h"


#include "FileMgrSrvGprot.h"
#include "GlobalResDef.h"
#include "AlertScreen.h"





#define AVK_V3D_CREATE_SCRN(_idx, _id, _title, _className) \
    _className* g_p##_idx; \
    void vs_venus_3d_##_idx##_exit(void) \
    { \
        VFX_OBJ_CLOSE(g_p##_idx); \
        VfxAppCatScr::deinitalize(); \
    } \
    void vs_venus_3d_##_idx(void) \
    { \
        MMI_BOOL ret = mmi_frm_scrn_enter(GRP_ID_AVK, 6789, vs_venus_3d_##_idx##_exit, vs_venus_3d_##_idx, MMI_FRM_FULL_SCRN); \
        if (ret == MMI_FALSE) \
        {                                                 \
            return;                                       \
        }                                                 \
        VfxAppCatScr::initalize();                        \
        VFX_OBJ_CREATE(g_p##_idx, _className, VfxAppCatScr::getContext()); \
        (g_p##_idx)->startTest(VFX_WSTR(_title), _id); \
    } \
    AVK_ADD_ITEM(AVK_V3D_ENGINE_ITEM_##_idx, L##_title, AVK_V3D_ENGINE); \
    AVK_MANUAL_CASE(AVK_V3D_ENGINE_MANUAL_##_idx, AVK_V3D_ENGINE_ITEM_##_idx) \
    { \
        vs_venus_3d_##_idx(); \
    }






class AvkV3dBaseScr : public VfxAppCatScr
{
public:
	VfxTextFrame* m_message;
	VfxTextFrame* m_yes;
	VfxTextFrame* m_no;
	VfxTextFrame* m_title;

	VfxWString m_wstrCaseName;
	int m_item_idx;
    
public:
    AvkV3dBaseScr()
    {
        m_message = NULL;
        m_yes = NULL;
        m_no = NULL;
        m_title = NULL;

    }

protected:
    virtual void onInit()
	{
		VfxAppCatScr::onInit();
		setBgColor(VFX_COLOR_BLUE);
		registerKeyHandler(VFX_KEY_CODE_LSK);
		registerKeyHandler(VFX_KEY_CODE_RSK);
	}

	virtual VfxBool onPenInput(VfxPenEvent &event)
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
				vfxPostInvoke0(this,&AvkV3dBaseScr::onYes);

				return VFX_TRUE;
			}
		

			point = convertPointTo(event.pos, m_no);
			if (m_no->getBounds().contains(point))
			{
				//FAIL
				vfxPostInvoke0(this,&AvkV3dBaseScr::onNo);
				return VFX_TRUE;
			}

	
		}

		return VfxAppCatScr::onPenInput(event);
	}

    VfxBool onKeyInput(VfxKeyEvent &event)
        {
    
            if (event.keyCode == VFX_KEY_CODE_LSK && event.type == VFX_KEY_EVENT_TYPE_UP)
            {
                vfxPostInvoke0(this,&AvkV3dBaseScr::onYes);
    
                return VFX_TRUE;
            }
            else if (event.keyCode == VFX_KEY_CODE_RSK && event.type == VFX_KEY_EVENT_TYPE_UP)
            {
                vfxPostInvoke0(this,&AvkV3dBaseScr::onNo);
    
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

public:

	virtual void startTest(VfxWString wstrCaseName,int item_idx)
	{
		m_wstrCaseName = wstrCaseName;       
		m_item_idx = item_idx;        
	}

	void layout()
	{
		VfxSize scrSize = getSize();
		if (m_message != NULL)
		{
            m_message->setAnchor(0,1);
			m_message->setPos(0, scrSize.height);
			m_message->setSize(scrSize.width, 80);
		}

		if (m_yes != NULL)
		{
            m_yes->setAnchor(0,1);
			m_yes->setPos(10, scrSize.height);   
            m_yes->setSize(100, 80);
		}

		if (m_no != NULL)
		{
            m_no->setAnchor(1,1);
			m_no->setPos(scrSize.width - 10, scrSize.height);
            m_no->setSize(100, 80);            
		}
        if (m_title != NULL)
		{
            m_title->setPos(10, 10);
        }
	}
	void confirm(const VfxWString &message)
	{
        VfxFontDesc  fontDesc;
        fontDesc.size = VFX_FONT_DESC_VF_SIZE(35);
		if (m_message == NULL)
		{
			VFX_OBJ_CREATE(m_message, VfxTextFrame, this);
			m_message->setAutoResized(VFX_FALSE);
			m_message->setColor(VFX_COLOR_BLACK);
			m_message->setBgColor(VFX_COLOR_GREY);
			m_message->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
			m_message->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
			m_message->setFont(VFX_FONT_DESC_SMALL);
		}    
		m_message->setString(message);
		if (m_yes == NULL)
		{
			VFX_OBJ_CREATE(m_yes, VfxTextFrame, this);
			m_yes->setColor(VFX_COLOR_BLACK);
			m_yes->setBgColor(VFX_COLOR_GREY);
			m_yes->setString(VFX_WSTR("YES"));
            m_yes->setFont(fontDesc);
            m_yes->setAutoResized(VFX_FALSE);
            m_yes->setVerticalToCenter(VFX_TRUE);



		}

		if (m_no == NULL)
		{
			VFX_OBJ_CREATE(m_no, VfxTextFrame, this);
			m_no->setColor(VFX_COLOR_BLACK);
			m_no->setBgColor(VFX_COLOR_GREY);
			m_no->setString(VFX_WSTR("NO"));
            m_no->setFont(fontDesc);
            m_no->setAutoResized(VFX_FALSE);
            m_no->setVerticalToCenter(VFX_TRUE);
			m_no->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);            


		}
        if(m_title == NULL)
        {
            VFX_OBJ_CREATE(m_title, VfxTextFrame, this); 
            m_title->setColor(VFX_COLOR_BLACK);
			m_title->setBgColor(VFX_COLOR_GREY);
            m_title->setString(VFX_WSTR_MEM(m_wstrCaseName));
        }
        
		layout();
	}

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




};





/***************************************************************************** 
 * Class AvkV3d3DPick
 *****************************************************************************/


class AvkV3d3DPick: public AvkV3dBaseScr
{

// Variable
public:
    VfxFrame *m_frame;
    VfxWorld *m_world;
    VfxCamera *m_camera;
    VfxBoxMesh *m_boxMesh1;
    VfxBoxMesh *m_boxMesh2;
    VfxSphereMesh *m_sphereMesh1;
    VfxSphereMesh *m_sphereMesh2;
    VfxSphereMesh *m_sphereMesh3;
    VfxVector3fTimeline *m_clickAnimation;

// Constructor / Destructor
public:
    AvkV3d3DPick() : 
        m_frame(NULL), 
        m_world(NULL),
        m_camera(NULL),
        m_boxMesh1(NULL),
        m_boxMesh2(NULL),
        m_sphereMesh1(NULL),
        m_sphereMesh2(NULL),
        m_sphereMesh3(NULL),
        m_clickAnimation(NULL)
    {
    }

// Override
protected:
        
    virtual VfxBool onPenInput(VfxPenEvent &event)
    {
        VfxBool ret = AvkV3dBaseScr::onPenInput(event);

        if(ret == VFX_FALSE)
        {
            VfxPoint pos = event.getRelPos(m_frame);
            VfxSize size = m_frame->getSize();            
            VfxFloat w = (VfxFloat)size.width;
            VfxFloat h = (VfxFloat)size.height;
    
            VfxVector3f orig;
            m_camera->getWorldPosition(orig);
    
            VfxVector3f worldPos = m_camera->unproject(VfxVector3f(
                (VfxFloat)(pos.x * 2) / w - 1.0f,
                -((VfxFloat)(pos.y * 2) / h - 1.0f),
                -1.0f));
            VfxVector3f dir = worldPos - orig;
            
            if (event.type == VFX_PEN_EVENT_TYPE_DOWN ||
                event.type == VFX_PEN_EVENT_TYPE_MOVE)
            {
                VfxNode *pickNode = m_world->pick(orig, dir);
                
                if (pickNode == m_boxMesh1 || pickNode == m_boxMesh2)
                {
                    setBgColor(VFX_COLOR_GREEN);
                }
                else if (pickNode == m_sphereMesh1 || pickNode == m_sphereMesh2)
                {
                    setBgColor(VFX_COLOR_YELLOW);
                }
                else if (pickNode != NULL)
                {
                    setBgColor(VFX_COLOR_RED);
                }
                else
                {
                    setBgColor(VFX_COLOR_BLACK);
                }
            }                
        }
        
        
        return ret;
    }

public:
	virtual void startTest(VfxWString wstrCaseName,int item_idx) 
	{
		AvkV3dBaseScr::startTest(wstrCaseName, item_idx);
		confirm(VFX_WSTR("3D Pick OK?"));


        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        VfxS32 w = main_screen_size.width;
        VfxS32 h = main_screen_size.height;

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setSize(w, h);

        /* Wrold */
        VFX_OBJ_CREATE(m_world, VfxWorld, m_frame);
        m_frame->setWorld(m_world);

        /* Camera */
        VFX_OBJ_CREATE(m_camera, VfxCamera, m_world);
        m_camera->setPerspective(VFX_PI / 2, (VfxFloat)w / h, 20.0f, 2000.0f);
        m_camera->setTranslation(0.0f, 0.0f, 20.0f);
        m_camera->rotateX(VFX_PI / 12.0f);
        m_camera->rotateZ(-VFX_PI / 12.0f);
        m_world->setActiveCamera(m_camera);

        /* Box */
        const VfxVector3f boxSize(30.0f, 40.0f, 50.0f);

        VFX_OBJ_CREATE_EX(m_boxMesh1, VfxBoxMesh, m_world, (boxSize.x, boxSize.y, boxSize.z));
        m_boxMesh1->setTranslation(VfxVector3f(boxSize.x, boxSize.y, -200.0f));
        m_boxMesh1->setRotation(normalize(VfxVector3f(1.0f)), VFX_PI / 2);
        m_boxMesh1->setPickable(VFX_TRUE);

        m_boxMesh1->setBoundingVolume(
            VfxBoundingVolume(
                VfxVector3f(0.0f),
                length2(boxSize),
                boxSize * 0.5f));
        
        VFX_OBJ_CREATE_EX(m_boxMesh2, VfxBoxMesh, m_world, (boxSize.x, boxSize.y, boxSize.z));
        m_boxMesh2->setTranslation(VfxVector3f(boxSize.x, -boxSize.y, -200.0f));
        m_boxMesh2->setRotation(normalize(VfxVector3f(1.0f)), VFX_PI / 2);
        m_boxMesh2->setPickable(VFX_TRUE);

        m_boxMesh2->setBoundingVolume(
            VfxBoundingVolume(
                VfxVector3f(0.0f),
                boxSize * 0.5f));
        
        /* Sphere */
        const VfxFloat sphereRadius = 15.0f;

        VFX_OBJ_CREATE_EX(m_sphereMesh1, VfxSphereMesh, m_world, (sphereRadius));
        m_sphereMesh1->setTranslation(boxSize.x / 2, boxSize.y / 2, -150.0f);
        m_sphereMesh1->setPickable(VFX_TRUE);

        m_sphereMesh1->setBoundingVolume(
            VfxBoundingVolume(
                VfxVector3f(0.0f),
                sphereRadius * sphereRadius,
                VfxVector3f(sphereRadius)));

        VFX_OBJ_CREATE_EX(m_sphereMesh2, VfxSphereMesh, m_world, (sphereRadius));
        m_sphereMesh2->setTranslation(boxSize.x / 2, -boxSize.y / 2, -150.0f);
        m_sphereMesh2->setPickable(VFX_TRUE);

        m_sphereMesh2->setBoundingVolume(
            VfxBoundingVolume(
                VfxVector3f(0.0f),
                sphereRadius * sphereRadius));

        VFX_OBJ_CREATE_EX(m_sphereMesh3, VfxSphereMesh, m_world, (sphereRadius * 0.5f));
        m_sphereMesh3->setTranslation(-boxSize.x / 2, 0, -150.0f);

        m_sphereMesh3->setBoundingVolume(
            VfxBoundingVolume(
                VfxVector3f(0.0f),
                sphereRadius * sphereRadius));
           

	}

};


     
/***************************************************************************** 
 * Class AvkV3d3DMesh
 *****************************************************************************/

class AvkV3d3DMesh : public AvkV3dBaseScr
{
// Variable
public:
    VfxFrame *m_frame;

// Constructor / Destructor
public:
    AvkV3d3DMesh()
    {
    }

// Override
public:
  
    virtual void startTest(VfxWString wstrCaseName,int item_idx) 
    {
        AvkV3dBaseScr::startTest(wstrCaseName, item_idx);
        confirm(VFX_WSTR("Text mesh OK?"));
        
        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);
               

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

        /* Wrold */
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, m_frame);
        m_frame->setWorld(world);

        /* Camera */
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        camera->setPerspective(
            VRT_PI_2, 
            (vrt_float)main_screen_size.width / (vrt_float)main_screen_size.height, 
            20.0f, 
            2000.0f);
        camera->setLookAt(
            VrtVector3f(0.0f, 0.0f, 20.0f), 
            VrtVector3f(0, 0, 0), 
            VrtVector3f(0, 1, 0));
        world->setActiveCamera(camera);

        VfxGroup *group;
        VFX_OBJ_CREATE(group, VfxGroup, world);
        
        VfxTextMesh *centerMesh = NULL;
        VfxTextMesh *mesh;
        VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("L"), 0, VFX_TEXT_MESH_ALIGN_MODE_LEFT));
        mesh->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_LARGE, VFX_FONT_DESC_EFFECT_BORDER));
        mesh->setTextColor(VFX_COLOR_GREEN);
        mesh->setTextBorderColor(VFX_COLOR_WHITE);
        mesh->setBackgroundColor(VFX_COLOR_BLACK);
        mesh->setTranslation(-10, 10, -10);
        mesh->setRotationY(VFX_PI / 4);

        VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("C"), 0, VFX_TEXT_MESH_ALIGN_MODE_CENTER));
        mesh->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_LARGE, VFX_FONT_DESC_EFFECT_BORDER));
        mesh->setTextColor(VFX_COLOR_YELLOW);
        mesh->setTextBorderColor(VFX_COLOR_WHITE);
        mesh->setBackgroundColor(VFX_COLOR_BLACK);
        mesh->setTranslation(0, 10, -10);
        mesh->setRotationY(0);
        centerMesh = mesh;
        
        VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("R"), 0, VFX_TEXT_MESH_ALIGN_MODE_RIGHT));
        mesh->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_LARGE, VFX_FONT_DESC_EFFECT_BORDER));
        mesh->setTextColor(VFX_COLOR_RED);
        mesh->setTextBorderColor(VFX_COLOR_WHITE);
        mesh->setBackgroundColor(VFX_COLOR_BLACK);
        mesh->setTranslation(10, 10, -10);
        mesh->setRotationY(-VFX_PI / 4);
        
        VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("Hey!"), 1, VFX_TEXT_MESH_ALIGN_MODE_LEFT, VFX_TEXT_MESH_VALIGN_MODE_TOP));
        mesh->setTextColor(VFX_COLOR_GREEN);
        mesh->setBackgroundColor(VFX_COLOR_BLACK);
        mesh->setTranslation(-10, 5, -10);
        mesh->setRotationY(VFX_PI / 4);

        VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("Hey!"), 1, VFX_TEXT_MESH_ALIGN_MODE_CENTER, VFX_TEXT_MESH_VALIGN_MODE_TOP));
        mesh->setTextColor(VFX_COLOR_YELLOW);
        mesh->setBackgroundColor(VFX_COLOR_BLACK);
        mesh->setTranslation(0, 5, -10);
        mesh->setRotationY(0);
        
        VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("Hey!"), 1, VFX_TEXT_MESH_ALIGN_MODE_RIGHT, VFX_TEXT_MESH_VALIGN_MODE_TOP));
        mesh->setTextColor(VFX_COLOR_RED);
        mesh->setBackgroundColor(VFX_COLOR_BLACK);
        mesh->setTranslation(10, 5, -10);
        mesh->setRotationY(-VFX_PI / 4);
        
        VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("Hey!"), 1, VFX_TEXT_MESH_ALIGN_MODE_LEFT, VFX_TEXT_MESH_VALIGN_MODE_CENTER));
        mesh->setTextColor(VFX_COLOR_GREEN);
        mesh->setBackgroundColor(VFX_COLOR_BLACK);
        mesh->setTranslation(-10, 0, -10);
        mesh->setRotationY(VFX_PI / 4);

        VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("Hey!"), 1, VFX_TEXT_MESH_ALIGN_MODE_CENTER, VFX_TEXT_MESH_VALIGN_MODE_CENTER));
        mesh->setTextColor(VFX_COLOR_YELLOW);
        mesh->setBackgroundColor(VFX_COLOR_BLACK);
        mesh->setTranslation(0, 0, -10);
        mesh->setRotationY(0);
        
        VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("Hey!"), 1, VFX_TEXT_MESH_ALIGN_MODE_RIGHT, VFX_TEXT_MESH_VALIGN_MODE_CENTER));
        mesh->setTextColor(VFX_COLOR_RED);
        mesh->setBackgroundColor(VFX_COLOR_BLACK);
        mesh->setTranslation(10, 0, -10);
        mesh->setRotationY(-VFX_PI / 4);
        
        VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("Hey!"), 1, VFX_TEXT_MESH_ALIGN_MODE_LEFT, VFX_TEXT_MESH_VALIGN_MODE_BOTTOM));
        mesh->setTextColor(VFX_COLOR_GREEN);
        mesh->setBackgroundColor(VFX_COLOR_BLACK);
        mesh->setTranslation(-10, -5, -10);
        mesh->setRotationY(VFX_PI / 4);

        VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("Hey!"), 1, VFX_TEXT_MESH_ALIGN_MODE_CENTER, VFX_TEXT_MESH_VALIGN_MODE_BOTTOM));
        mesh->setTextColor(VFX_COLOR_YELLOW);
        mesh->setBackgroundColor(VFX_COLOR_BLACK);
        mesh->setTranslation(0, -5, -10);
        mesh->setRotationY(0);
        
        VFX_OBJ_CREATE_EX(mesh, VfxTextMesh, group, (8, 3, VFX_WSTR("Hey!"), 1, VFX_TEXT_MESH_ALIGN_MODE_RIGHT, VFX_TEXT_MESH_VALIGN_MODE_BOTTOM));
        mesh->setTextColor(VFX_COLOR_RED);
        mesh->setBackgroundColor(VFX_COLOR_BLACK);
        mesh->setTranslation(10, -5, -10);
        mesh->setRotationY(-VFX_PI / 4);
        

        VfxQuaternionfTimeline *rtl;
        VFX_OBJ_CREATE(rtl, VfxQuaternionfTimeline, centerMesh);
        rtl->setTarget(centerMesh);
        rtl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
        rtl->setFromValue(normalize(VfxQuaternionf(0,0,1,-0.5)));
        rtl->setToValue(normalize(VfxQuaternionf(0,0,1,0.5)));
        rtl->setDuration(2000);
        rtl->setAutoReversed(VFX_TRUE);
        rtl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        rtl->start();
    
    }

       
};








/***************************************************************************** 
 * Class AvkV3d3DAnimation
 *****************************************************************************/

class AvkV3d3DAnimationB01 : public AvkV3dBaseScr
{
// Variable
public:
    VfxFrame *m_frame;


// Constructor / Destructor
public:
    AvkV3d3DAnimationB01()
    : m_frame(NULL)
    {
    }

// Override
public:  
    virtual void startTest(VfxWString wstrCaseName,int item_idx) 
    {
        AvkV3dBaseScr::startTest(wstrCaseName, item_idx);
        confirm(VFX_WSTR("2D Keyframe OK?"));

        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        VfxS32 w = (main_screen_size.width) / 6;
        VfxS32 h = main_screen_size.height / 5;

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

        VfxFrame *frame;
        VfxKeyframeSequence *kfs;
        VfxKeyframeTimeline *kf_tl;

        /* Step */
        VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
        frame->setSize(VfxSize(10, 10));
        frame->setBgColor(VFX_COLOR_WHITE);

        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, frame, (5, VFX_TYPE_ID_POINT));
        kfs->setKeyframe(0, 0,    &VfxPoint(w * 1, h * 1));
        kfs->setKeyframe(1, 500,  &VfxPoint(w * 2, h * 1 - 50));
        kfs->setKeyframe(2, 1000, &VfxPoint(w * 3, h * 1));
        kfs->setKeyframe(3, 1500, &VfxPoint(w * 4, h * 1 - 50));
        kfs->setKeyframe(4, 2000, &VfxPoint(w * 5, h * 1));

        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, frame);
        kf_tl->setTarget(frame);
        kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_STEP);
        kf_tl->setDuration(2000);
        kf_tl->setAutoReversed(VFX_TRUE);
        kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        kf_tl->start();

        /* Linear */
        VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
        frame->setSize(VfxSize(10, 10));
        frame->setBgColor(VFX_COLOR_WHITE);

        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, frame, (5, VFX_TYPE_ID_POINT));
        kfs->setKeyframe(0, 0,    &VfxPoint(w * 1, h * 2));
        kfs->setKeyframe(1, 500,  &VfxPoint(w * 2, h * 2 - 50));
        kfs->setKeyframe(2, 1000, &VfxPoint(w * 3, h * 2));
        kfs->setKeyframe(3, 1500, &VfxPoint(w * 4, h * 2 - 50));
        kfs->setKeyframe(4, 2000, &VfxPoint(w * 5, h * 2));

        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, frame);
        kf_tl->setTarget(frame);
        kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);        
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
        kf_tl->setDuration(2000);
        kf_tl->setAutoReversed(VFX_TRUE);
        kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        kf_tl->start();

        /* Spline */
        VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
        frame->setSize(VfxSize(10, 10));
        frame->setBgColor(VFX_COLOR_WHITE);

        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, frame, (5, VFX_TYPE_ID_POINT));
        kfs->setKeyframe(0, 0,    &VfxPoint(w * 1, h * 3));
        kfs->setKeyframe(1, 500,  &VfxPoint(w * 2, h * 3 - 50));
        kfs->setKeyframe(2, 1000, &VfxPoint(w * 3, h * 3));
        kfs->setKeyframe(3, 1500, &VfxPoint(w * 4, h * 3 - 50));
        kfs->setKeyframe(4, 2000, &VfxPoint(w * 5, h * 3));

        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, frame);
        kf_tl->setTarget(frame);
        kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);         
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SPLINE);
        kf_tl->setDuration(2000);
        kf_tl->setAutoReversed(VFX_TRUE);
        kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        kf_tl->start();

    }

};

class AvkV3d3DAnimationB02 : public AvkV3dBaseScr
{
// Variable
public:
    VfxFrame *m_frame;


// Constructor / Destructor
public:
    AvkV3d3DAnimationB02()
    : m_frame(NULL)
    {
    }

// Override
public:  
    virtual void startTest(VfxWString wstrCaseName,int item_idx) 
    {
        AvkV3dBaseScr::startTest(wstrCaseName, item_idx);
        confirm(VFX_WSTR("3D Keyframe OK?"));


        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        VfxS32 w = main_screen_size.width / 6;
        VfxS32 h = main_screen_size.height / 6;

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

        /* Wrold */
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, m_frame);
        m_frame->setWorld(world);

        /* Camera */
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        camera->setScreen(
            0,
            0,
            (VfxFloat)main_screen_size.width,
            (VfxFloat)main_screen_size.height,
            (VfxFloat)-main_screen_size.height,
            (VfxFloat)main_screen_size.height);
        world->setActiveCamera(camera);

        VfxSphereMesh *mesh;
        VfxBoxMesh *box;
        VfxKeyframeSequence *kfs;
        VfxKeyframeTimeline *kf_tl;

        /* Step */
        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));

        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
        kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 1, 0));
        kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 1 - 50, 0));
        kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 1, 0));
        kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 1 - 50, 0));
        kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 1, 0));

        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, mesh);
        kf_tl->setTarget(mesh);
        kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);        
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_STEP);
        kf_tl->setDuration(2000);
        kf_tl->setAutoReversed(VFX_TRUE);
        kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        kf_tl->start();

        /* Linear */
        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));

        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
        kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 2, 0));
        kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 2 - 50, 0));
        kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 2, 0));
        kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 2 - 50, 0));
        kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 2, 0));


        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, mesh);
        kf_tl->setTarget(mesh);
        kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
        kf_tl->setDuration(2000);
        kf_tl->setAutoReversed(VFX_TRUE);
        kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        kf_tl->start();

        /* Spline */
        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));

        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
        kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 3, 0));
        kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 3 - 50, 0));
        kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 3, 0));
        kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 3 - 50, 0));
        kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 3, 0));


        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, mesh);
        kf_tl->setTarget(mesh);
        kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SPLINE);
        kf_tl->setDuration(2000);
        kf_tl->setAutoReversed(VFX_TRUE);
        kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        kf_tl->start();

        /* Slerp */
        VFX_OBJ_CREATE_EX(box, VfxBoxMesh, world, (40.0f));
        box->setTranslation(VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 4, 0));

        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, box, (4, VFX_TYPE_ID_QUAT));
        kfs->setKeyframe(0, 0,    &VfxQuaternionf(VfxVector3f(1, 0, 0), 0));
        kfs->setKeyframe(1, 667,  &VfxQuaternionf(VfxVector3f(0, 1, 0), 0));
        kfs->setKeyframe(2, 1333, &VfxQuaternionf(VfxVector3f(0, 0, 1), 0));
        kfs->setKeyframe(3, 2000, &VfxQuaternionf(VfxVector3f(1, 0, 0), 0));

        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, box);
        kf_tl->setTarget(box);
        kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SLERP);
        kf_tl->setDuration(2000);
        kf_tl->setAutoReversed(VFX_TRUE);
        kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        kf_tl->start();

        /* Squad */
        VFX_OBJ_CREATE_EX(box, VfxBoxMesh, world, (40.0f));
        box->setTranslation(VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 5, 0));

        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, box, (4, VFX_TYPE_ID_QUAT));
        kfs->setKeyframe(0, 0,    &VfxQuaternionf(VfxVector3f(1, 0, 0), 0));
        kfs->setKeyframe(1, 667,  &VfxQuaternionf(VfxVector3f(0, 1, 0), 0));
        kfs->setKeyframe(2, 1333, &VfxQuaternionf(VfxVector3f(0, 0, 1), 0));
        kfs->setKeyframe(3, 2000, &VfxQuaternionf(VfxVector3f(1, 0, 0), 0));

        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, box);
        kf_tl->setTarget(box);
        kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SQUAD);
        kf_tl->setDuration(2000);
        kf_tl->setAutoReversed(VFX_TRUE);
        kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        kf_tl->start();


    }
};


class AvkV3d3DAnimationB03 : public AvkV3dBaseScr
{
// Variable
public:
    VfxFrame *m_frame;


// Constructor / Destructor
public:
    AvkV3d3DAnimationB03()
    : m_frame(NULL)
    {
    }

// Override
public:  
    virtual void startTest(VfxWString wstrCaseName,int item_idx) 
    {
        AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
        confirm(VFX_WSTR("3D From/To Timline OK?"));      

        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

        /* Wrold */
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, m_frame);
        m_frame->setWorld(world);

        /* Camera */
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        camera->setPerspective(VRT_PI_2, (vrt_float)main_screen_size.width / (vrt_float)main_screen_size.height, 1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(2, 5, 5), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));
        world->setActiveCamera(camera);

        /* Mesh */
        VfxSphereMesh *mesh;
        VFX_OBJ_CREATE(mesh, VfxSphereMesh, world);

        /* Timeline */
        VfxFloatTimeline *tl;
        VFX_OBJ_CREATE(tl, VfxFloatTimeline, mesh);
        tl->setTarget(mesh);
        tl->setTargetPropertyId(VRT_NODE_PROPERTY_ID_OPACITY);
        tl->setFromValue(0.0f);
        tl->setToValue(1.0f);
        tl->setDuration(2000);
        tl->setAutoReversed(VFX_TRUE);
        tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        tl->start();
        


    }
};

class AvkV3d3DAnimationB04 : public AvkV3dBaseScr
{
// Variable
public:
    VfxFrame *m_frame;

// Constructor / Destructor
public:
    AvkV3d3DAnimationB04()
    : m_frame(NULL)
    {
    }

// Override
public:  
    virtual void startTest(VfxWString wstrCaseName,int item_idx) 
    {
        AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
        confirm(VFX_WSTR("Color Keyframe OK?"));


        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        VfxS32 w = main_screen_size.width / 2;
        VfxS32 h = main_screen_size.height / 2;

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setSize(w, h);
        m_frame->setPos(w/2, h/2);

        /* Color keyframe timeline */
        VfxKeyframeSequence *kfs;
        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, m_frame, (4, VFX_TYPE_ID_COLOR));
        kfs->setKeyframe(0, 0,    &VfxColor(VFX_COLOR_WHITE));
        kfs->setKeyframe(1, 667,  &VfxColor(VFX_COLOR_YELLOW));
        kfs->setKeyframe(2, 1333, &VfxColor(VFX_COLOR_GREEN));
        kfs->setKeyframe(3, 2000, &VfxColor(VFX_COLOR_WHITE));

        VfxKeyframeTimeline *kf_tl;
        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, m_frame);
        kf_tl->setTarget(m_frame);
        kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_BACKGROUND_COLOR);
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
        kf_tl->setDuration(2000);
        kf_tl->setAutoReversed(VFX_TRUE);
        kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        kf_tl->start();
        

    }
};

class AvkV3d3DAnimationB05 : public AvkV3dBaseScr
{
// Variable
public:
    VfxFrame *m_frame;

// Constructor / Destructor
public:
    AvkV3d3DAnimationB05()
    : m_frame(NULL)
    {
    }

// Override
public:  
    virtual void startTest(VfxWString wstrCaseName,int item_idx) 
    {
        AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
        confirm(VFX_WSTR("Virtual Animatable Property OK?"));

        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

        /* Wrold */
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, m_frame);
        m_frame->setWorld(world);

        /* Camera */
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        camera->setPerspective(VRT_PI_2, (vrt_float)main_screen_size.width / (vrt_float)main_screen_size.height, 1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(2, 5, 5), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));
        world->setActiveCamera(camera);

        VfxGroup *group;
        VfxBoxMesh *mesh;
        VfxVector3fTimeline *tl;
        VfxQuaternionfTimeline *qtl;
        /* Group 1 */
        VFX_OBJ_CREATE(group, VfxGroup, world);
        group->setTranslation(-2, 0, 0);
        VFX_OBJ_CREATE(mesh, VfxBoxMesh, group);
        VFX_OBJ_CREATE(tl, VfxVector3fTimeline, mesh);
        tl->setTarget(mesh);
        tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        tl->setFromValue(VfxVector3f(0, 0, 0));
        tl->setToValue(VfxVector3f(0, 2, 0));
        tl->setDuration(2000);
        tl->setAutoReversed(VFX_TRUE);
        tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        tl->start();

        /* Group 2 */
        VFX_OBJ_CREATE(group, VfxGroup, world);
        group->setTranslation(2, 0, 0);
        VFX_OBJ_CREATE(mesh, VfxBoxMesh, group);
        VFX_OBJ_CREATE(tl, VfxVector3fTimeline, mesh);
        tl->setTarget(mesh);
        tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_SCALE);
        tl->setFromValue(VfxVector3f(0.5f));
        tl->setToValue(VfxVector3f(2.0f));
        tl->setDuration(2000);
        tl->setAutoReversed(VFX_TRUE);
        tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        tl->start();

        /* Group 3 */
        VFX_OBJ_CREATE(group, VfxGroup, world);
        group->setTranslation(0, 0, -2);
        VFX_OBJ_CREATE(mesh, VfxBoxMesh, group);
        VFX_OBJ_CREATE(qtl, VfxQuaternionfTimeline, mesh);
        qtl->setTarget(mesh);
        qtl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
        qtl->setFromValue(VfxQuaternionf(1,0,0,0));
        qtl->setToValue(VfxQuaternionf(0,1,0,0));
        qtl->setDuration(2000);
        qtl->setAutoReversed(VFX_TRUE);
        qtl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        qtl->start();

        /* Group 4 */
        VFX_OBJ_CREATE(group, VfxGroup, world);
        group->setTranslation(0, 0, 2);
        VFX_OBJ_CREATE(mesh, VfxBoxMesh, group);
        VFX_OBJ_CREATE(qtl, VfxQuaternionfTimeline, mesh);
        qtl->setTarget(mesh);
        qtl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
        qtl->setFromValue(VfxQuaternionf(1,0,0,0));
        qtl->setToValue(VfxQuaternionf(0,1,0,0));
        qtl->setDuration(2000);
        qtl->setAutoReversed(VFX_TRUE);
        qtl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        qtl->start();
        VFX_OBJ_CREATE(tl, VfxVector3fTimeline, mesh);
        tl->setTarget(mesh);
        tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_SCALE);
        tl->setFromValue(VfxVector3f(0.5f));
        tl->setToValue(VfxVector3f(2.0f));
        tl->setDuration(2000);
        tl->setAutoReversed(VFX_TRUE);
        tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        tl->start();
        VFX_OBJ_CREATE(tl, VfxVector3fTimeline, mesh);
        tl->setTarget(mesh);
        tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        tl->setFromValue(VfxVector3f(0, 0, 0));
        tl->setToValue(VfxVector3f(0, 2, 0));
        tl->setDuration(2000);
        tl->setAutoReversed(VFX_TRUE);
        tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        tl->start();


    }
};

class AvkV3d3DAnimationB06 : public AvkV3dBaseScr
{
// Variable
public:
    VfxFrame *m_frame;

// Constructor / Destructor
public:
    AvkV3d3DAnimationB06()
    : m_frame(NULL)
    {
    }

// Override
public:  
    virtual void startTest(VfxWString wstrCaseName,int item_idx) 
    {
        AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
        confirm(VFX_WSTR("Shader Uniform Timeline OK?"));

        
        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        VfxS32 w = main_screen_size.width / 2;
        VfxS32 h = main_screen_size.height / 2;

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setSize(w, h);
        m_frame->setPos(w/2, h/2);

        VfxMaterial *material;
        VFX_OBJ_CREATE(material, VfxMaterial, m_frame);
        m_frame->setMaterial(material);

        VfxPass *pass;
        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(0, pass);

        static const vrt_char fShader[] =
        "precision mediump float;           \n"
        "varying vec4 vColor;               \n"
        "varying vec2 vTexCoord;            \n"
        "uniform vec4 uColor0;              \n"
        "uniform vec4 uColor1;              \n"
        "void main()                        \n"
        "{                                  \n"
        "   gl_FragColor = mix(uColor0, uColor1, vTexCoord.x);  \n"
        "}                          \n";
        VfxShaderProgram *program;
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (NULL, fShader));
        pass->setShaderProgram(program);

        VfxShaderUniforms *uniforms;
        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);

        VfxShaderVariable *var;
        VfxVector4fTimeline *tl;                

        var = uniforms->addUniformVariable(VFX_STR("uColor0"), VFX_TYPE_ID_VEC4, 1);
        VFX_OBJ_CREATE(tl, VfxVector4fTimeline, var);
        tl->setTarget(var);
        tl->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_VEC4);
        tl->setFromValue(VfxVector4f(1.0f, 0.0f, 0.0f, 1.0f));
        tl->setToValue(VfxVector4f(0.0f, 1.0f, 0.0f, 1.0f));
        tl->setDuration(2000);
        tl->setAutoReversed(VFX_TRUE);
        tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        tl->start();

        var = uniforms->addUniformVariable(VFX_STR("uColor1"), VFX_TYPE_ID_VEC4, 1);
        VFX_OBJ_CREATE(tl, VfxVector4fTimeline, var);
        tl->setTarget(var);
        tl->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_VEC4);
        tl->setFromValue(VfxVector4f(1.0f, 1.0f, 0.0f, 1.0f));
        tl->setToValue(VfxVector4f(0.0f, 0.0f, 1.0f, 1.0f));
        tl->setDuration(2000);
        tl->setAutoReversed(VFX_TRUE);
        tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        tl->start();

        

    }
};

class AvkV3d3DAnimationB07 : public AvkV3dBaseScr
{
// Variable
public:
    VfxFrame *m_frame;

// Constructor / Destructor
public:
    AvkV3d3DAnimationB07()
    : m_frame(NULL)
    {
    }

// Override
public:  
    virtual void startTest(VfxWString wstrCaseName,int item_idx) 
    {
        AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
        confirm(VFX_WSTR("Start Delay OK?"));

        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);        
        VfxS32 w = main_screen_size.width / 6;
        VfxS32 h = main_screen_size.height / 6;

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

        /* Wrold */
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, m_frame);
        m_frame->setWorld(world);

        /* Camera */
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        camera->setScreen(
            0,
            0,
            (VfxFloat)main_screen_size.width,
            (VfxFloat)main_screen_size.height,
            (VfxFloat)-main_screen_size.height,
            (VfxFloat)main_screen_size.height);
        world->setActiveCamera(camera);

        VfxSphereMesh *mesh;
        VfxKeyframeSequence *kfs;
        VfxKeyframeTimeline *kf_tl;


        /* Linear */
        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));
        mesh->setTranslation(VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 2, 0));

        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
        kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 2, 0));
        kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 2 - 50, 0));
        kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 2, 0));
        kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 2 - 50, 0));
        kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 2, 0));

        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, mesh);
        kf_tl->setTarget(mesh);
        kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
        kf_tl->setStartDelay(500);
        kf_tl->setDuration(2000);
        kf_tl->start();

        /* Linear */
        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));
        mesh->setTranslation(VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 3, 0));

        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
        kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 3, 0));
        kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 3 - 50, 0));
        kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 3, 0));
        kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 3 - 50, 0));
        kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 3, 0));

        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, mesh);
        kf_tl->setTarget(mesh);
        kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
        kf_tl->setStartDelay(1000);
        kf_tl->setDuration(2000);
        kf_tl->start();


        /* Linear */
        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));
        mesh->setTranslation(VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 4, 0));

        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
        kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 4, 0));
        kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 4 - 50, 0));
        kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 4, 0));
        kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 4 - 50, 0));
        kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 4, 0));

        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, mesh);
        kf_tl->setTarget(mesh);
        kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
        kf_tl->setStartDelay(1500);
        kf_tl->setDuration(2000);
        kf_tl->start();



    }
};

class AvkV3d3DAnimationB08 : public AvkV3dBaseScr
{
// Variable
public:
    VfxFrame *m_frame;

// Constructor / Destructor
public:
    AvkV3d3DAnimationB08()
    : m_frame(NULL)
    {
    }

// Override
public:  
    virtual void startTest(VfxWString wstrCaseName,int item_idx) 
    {
        AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
        confirm(VFX_WSTR("KeyFrame Speed Control OK?"));

        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        VfxS32 w = main_screen_size.width / 6;
        VfxS32 h = main_screen_size.height / 6;

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

        /* Wrold */
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, m_frame);
        m_frame->setWorld(world);

        /* Camera */
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        camera->setScreen(
            0,
            0,
            (VfxFloat)main_screen_size.width,
            (VfxFloat)main_screen_size.height,
            (VfxFloat)-main_screen_size.height,
            (VfxFloat)main_screen_size.height);
        world->setActiveCamera(camera);

        VfxSphereMesh *mesh;
        VfxKeyframeSequence *kfs;
        VfxKeyframeTimeline *kf_tl;


        /* Linear */
        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));
        mesh->setTranslation(VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 2, 0));
        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
        kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 2, 0));
        kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 2 - 50, 0));
        kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 2, 0));
        kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 2 - 50, 0));
        kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 2, 0));

        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, mesh);
        kf_tl->setTarget(mesh);
        kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
        kf_tl->setDuration(2000);
        kf_tl->start();

        /* Linear */
        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));
        mesh->setTranslation(VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 3, 0));

        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
        kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 3, 0));
        kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 3 - 50, 0));
        kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 3, 0));
        kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 3 - 50, 0));
        kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 3, 0));

        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, mesh);
        kf_tl->setTarget(mesh);
        kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
        kf_tl->setDuration(4000);
        kf_tl->start();


        /* Linear */
        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));
        mesh->setTranslation(VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 4, 0));

        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
        kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 4, 0));
        kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 4 - 50, 0));
        kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 4, 0));
        kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 4 - 50, 0));
        kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 4, 0));

        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, mesh);
        kf_tl->setTarget(mesh);
        kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
        kf_tl->setDuration(8000);
        kf_tl->start();



    }
};






/***************************************************************************** 
 * Class VtstRt3DAutoAnimate
 *****************************************************************************/

class AvkV3d3DAutoAnimateB09 : public AvkV3dBaseScr
{
// Variable
public:
    VfxFrame *m_frame;
    VfxBoxMesh *m_mesh;

// Constructor / Destructor
public:
    AvkV3d3DAutoAnimateB09() : m_frame(NULL), m_mesh(NULL)
    {
    }

// Override
public:  
    virtual void startTest(VfxWString wstrCaseName,int item_idx) 
    {
        AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
        confirm(VFX_WSTR("No animation OK?"));

        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

       
                
        VfxMsec du = 4000;
        
        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

        /* Wrold */
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, m_frame);
        m_frame->setWorld(world);

        /* Camera */
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        camera->setPerspective(VRT_PI_2, (vrt_float)main_screen_size.width / (vrt_float)main_screen_size.height, 1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(2, 5, 5), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));
        world->setActiveCamera(camera);

        VfxGroup *group;
        VfxBoxMesh *mesh;

        /* Group 1 */
        VFX_OBJ_CREATE(group, VfxGroup, world);
        group->setTranslation(-2, 0, 0);
        VFX_OBJ_CREATE(mesh, VfxBoxMesh, group);
        mesh->setAutoAnimate(VFX_TRUE);

        // auto animation
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDuration(du);
        
        // auto animation
        mesh->setTranslation(VfxVector3f(0, 2, 0));

        VfxAutoAnimate::commit();

         
    }
};

        
class AvkV3d3DAutoAnimateB10 : public AvkV3dBaseScr
{
// Variable
public:
    VfxFrame *m_frame;
    VfxBoxMesh *m_mesh;

// Constructor / Destructor
public:
    AvkV3d3DAutoAnimateB10() : m_frame(NULL), m_mesh(NULL)
    {
    }
    
// Override
public:  
    virtual void startTest(VfxWString wstrCaseName,int item_idx) 
    {
        AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
        confirm(VFX_WSTR("Initial time animation OK?"));
        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        VfxMsec du = 4000;
        
        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

        /* Wrold */
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, m_frame);
        m_frame->setWorld(world);

        /* Camera */
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        camera->setPerspective(VRT_PI_2, (vrt_float)main_screen_size.width / (vrt_float)main_screen_size.height, 1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(2, 5, 5), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));
        world->setActiveCamera(camera);

        VfxGroup *group;
        VfxBoxMesh *mesh;

        /* Group 1 */
        VFX_OBJ_CREATE(group, VfxGroup, world);
        group->setTranslation(-2, 0, 0);
        VFX_OBJ_CREATE(mesh, VfxBoxMesh, group);
        mesh->setAutoAnimate(VFX_TRUE);

        // auto animation
        VfxAutoAnimate::initAnimateBegin();
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDuration(du);
        
        // auto animation
        mesh->setTranslation(VfxVector3f(0, 2, 0));

        VfxAutoAnimate::commit();
        VfxAutoAnimate::initAnimateEnd();
   }
};



      
class AvkV3d3DAutoAnimateB11 : public AvkV3dBaseScr
{
// Variable
public:
    VfxFrame *m_frame;
    VfxBoxMesh *m_mesh;

// Constructor / Destructor
public:
    AvkV3d3DAutoAnimateB11() : m_frame(NULL), m_mesh(NULL)
    {
    }

protected:
    virtual void onInit()
    {
        AvkV3dBaseScr::onInit();
        
        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

        /* Wrold */
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, m_frame);
        m_frame->setWorld(world);

        /* Camera */
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        camera->setPerspective(VRT_PI_2, (vrt_float)main_screen_size.width / (vrt_float)main_screen_size.height, 1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(2, 5, 5), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));
        world->setActiveCamera(camera);

        VfxGroup *group;

        /* Group 1 */
        VFX_OBJ_CREATE(group, VfxGroup, world);        
        VFX_OBJ_CREATE(m_mesh, VfxBoxMesh, group);
        m_mesh->setAutoAnimate(VFX_TRUE);
    }
    
// Override
public:  
    virtual void startTest(VfxWString wstrCaseName,int item_idx) 
    {
        AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
        confirm(VFX_WSTR("Normal animation OK?"));        
        // auto animation
        m_mesh->setTranslation(VfxVector3f(0, 2, 0));

    }
};






/***************************************************************************** 
 * Class AvkV3dTimelineChain
 *****************************************************************************/

class AvkV3dTimelineChainC01 : public AvkV3dBaseScr
{
// Variable
public:
    VfxFrame *m_frame;

// Constructor / Destructor
public:
    AvkV3dTimelineChainC01() : 
        m_frame(NULL)
    {
    }

    
// Override
public:  
    virtual void startTest(VfxWString wstrCaseName,int item_idx) 
    {
        AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
        confirm(VFX_WSTR("Timeline Chain OK?"));       
     

        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

   
        VfxS32 w = main_screen_size.width / 6;
        VfxS32 h = main_screen_size.height / 6;

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

        /* create reference time */
        VfxFloatTimeline *t;
        VFX_OBJ_CREATE(t, VfxFloatTimeline, m_frame);
        t->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
        t->setTarget(m_frame);
        t->setDuration(1000);
        t->setFromValue(0.0f);
        t->setToValue(1.0f);
        t->setAutoReversed(VFX_TRUE);
        t->setRepeatCount(3);

        /* Start reference timeline */
        t->start();

        /* create animation */
        VfxAnimation *animation;
        VFX_OBJ_CREATE(animation, VfxAnimation, m_frame);

        /* Wrold */
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, m_frame);
        m_frame->setWorld(world);

        /* Camera */
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        camera->setScreen(
            0,
            0,
            (VfxFloat)main_screen_size.width,
            (VfxFloat)main_screen_size.height,
            (VfxFloat)-main_screen_size.height,
            (VfxFloat)main_screen_size.height);
        world->setActiveCamera(camera);

        VfxSphereMesh *mesh;
        VfxBoxMesh *box;
        VfxKeyframeSequence *kfs;
        VfxKeyframeTimeline *kf_tl;

        /* Step */
        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));
        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
        kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 1, 0));
        kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 1 - 50, 0));
        kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 1, 0));
        kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 1 - 50, 0));
        kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 1, 0));
        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, animation);
        kf_tl->setTarget(mesh);
        kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_STEP);
        kf_tl->setDuration(2000);

        /* Linear */
        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));
        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
        kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 2, 0));
        kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 2 - 50, 0));
        kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 2, 0));
        kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 2 - 50, 0));
        kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 2, 0));
        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, animation);
        kf_tl->setTarget(mesh);
        kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_LINEAR);
        kf_tl->setDuration(2000);

        /* Spline */
        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));
        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
        kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 3, 0));
        kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 3 - 50, 0));
        kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 3, 0));
        kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 3 - 50, 0));
        kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 3, 0));
        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, animation);
        kf_tl->setTarget(mesh);
        kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        kf_tl->setKeyframeSequence(kfs);
				kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SPLINE);
        kf_tl->setDuration(2000);

        /* Slerp */
        VFX_OBJ_CREATE_EX(box, VfxBoxMesh, world, (40.0f));
        box->setTranslation(VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 4, 0));
        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, box, (4, VFX_TYPE_ID_QUAT));
        kfs->setKeyframe(0, 0,    &VfxQuaternionf(VfxVector3f(1, 0, 0), 0));
        kfs->setKeyframe(1, 667,  &VfxQuaternionf(VfxVector3f(0, 1, 0), 0));
        kfs->setKeyframe(2, 1333, &VfxQuaternionf(VfxVector3f(0, 0, 1), 0));
        kfs->setKeyframe(3, 2000, &VfxQuaternionf(VfxVector3f(1, 0, 0), 0));
        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, animation);
        kf_tl->setTarget(box);
        kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SLERP);
        kf_tl->setDuration(2000);

        /* Squad */
        VFX_OBJ_CREATE_EX(box, VfxBoxMesh, world, (40.0f));
        box->setTranslation(VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 5, 0));
        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, box, (4, VFX_TYPE_ID_QUAT));
        kfs->setKeyframe(0, 0,    &VfxQuaternionf(VfxVector3f(1, 0, 0), 0));
        kfs->setKeyframe(1, 667,  &VfxQuaternionf(VfxVector3f(0, 1, 0), 0));
        kfs->setKeyframe(2, 1333, &VfxQuaternionf(VfxVector3f(0, 0, 1), 0));
        kfs->setKeyframe(3, 2000, &VfxQuaternionf(VfxVector3f(1, 0, 0), 0));
        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, animation);
        kf_tl->setTarget(box);
        kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SQUAD);
        kf_tl->setDuration(2000);

        VfxU32 userData = 0x12345678;
        kf_tl->setCustomTimingFunc(testTimingFuncCallback, &userData, sizeof(userData));

        /* use control timeline */
        animation->setTimelineTime(t);
    }


    static VfxFloat testTimingFuncCallback(
        VfxFloat t,
        void *data,
        VfxU32 dataSize)
    {
        VFX_DEV_ASSERT(data != NULL && dataSize == sizeof(VfxU32));
        VFX_DEV_ASSERT(*(VfxU32 *)data == 0x12345678);
        return t;
    }
};


              
class AvkV3dTimelineChainC02 : public AvkV3dBaseScr
{
// Variable
public:
  VfxFrame *m_frame;

// Constructor / Destructor
public:
  AvkV3dTimelineChainC02() : 
      m_frame(NULL)
  {
  }

  
// Override
public:  
    virtual void startTest(VfxWString wstrCaseName,int item_idx)  
    {
        AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
        confirm(VFX_WSTR("Animation Set OK?"));

   

        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);


        VfxS32 w = (main_screen_size.width) / 6;
        VfxS32 h = main_screen_size.height / 5;

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

        /* create reference time */
        VfxFloatTimeline *t;
        VFX_OBJ_CREATE(t, VfxFloatTimeline, m_frame);
        t->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
        t->setTarget(m_frame);
        t->setDuration(1000);
        t->setFromValue(1.0f);
        t->setToValue(3.0f);
        t->setAutoReversed(VFX_TRUE);
        t->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);

        /* create animation */
        VfxAnimation *animation;
        VFX_OBJ_CREATE(animation, VfxAnimation, m_frame);

        VfxFrame *frame;
        VfxPointTimeline *kf_tl;

        VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
        frame->setSize(VfxSize(10, 10));
        frame->setPos(w * 1, h * 1);
        frame->setBgColor(VFX_COLOR_WHITE);
        VFX_OBJ_CREATE(kf_tl, VfxPointTimeline, animation);
        kf_tl->setTarget(frame);
        kf_tl->setFromValue(VfxPoint(w * 1, h * 1));
        kf_tl->setToValue(VfxPoint(w * 5, h * 1));
        kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        kf_tl->setDuration(2000);

        VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
        frame->setSize(VfxSize(10, 10));
        frame->setPos(w * 1, h * 2);
        frame->setBgColor(VFX_COLOR_WHITE);
        VFX_OBJ_CREATE(kf_tl, VfxPointTimeline, animation);
        kf_tl->setTarget(frame);
        kf_tl->setFromValue(VfxPoint(w * 1, h * 2));
        kf_tl->setToValue(VfxPoint(w * 3, h * 2));
        kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        kf_tl->setStartTime(0);
        kf_tl->setDuration(1000);

        VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
        frame->setSize(VfxSize(10, 10));
        frame->setPos(w * 3, h * 3);
        frame->setBgColor(VFX_COLOR_WHITE);
        VFX_OBJ_CREATE(kf_tl, VfxPointTimeline, animation);
        kf_tl->setTarget(frame);
        kf_tl->setFromValue(VfxPoint(w * 3, h * 3));
        kf_tl->setToValue(VfxPoint(w * 5, h * 3));
        kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        kf_tl->setStartTime(1000);
        kf_tl->setDuration(1000);

        animation->setTimelineTime(t, 0.5f, -0.5f);

        /* Start reference timeline */
        t->start();
    }
};


 
      
class AvkV3dTimelineChainC03 : public AvkV3dBaseScr
{
// Variable
public:
    VfxFrame *m_frame;

// Constructor / Destructor
public:
    AvkV3dTimelineChainC03() : 
    m_frame(NULL)
    {
    }


// Override
public:  
    virtual void startTest(VfxWString wstrCaseName,int item_idx)  
    {
        AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
        confirm(VFX_WSTR("Custom Interpolation + KeyFrame OK?"));
        
        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);
 
                

        VfxS32 w = main_screen_size.width / 6;
        VfxS32 h = main_screen_size.height / 6;

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

        /* Wrold */
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, m_frame);
        m_frame->setWorld(world);

        /* Camera */
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        camera->setScreen(
            0,
            0,
            (VfxFloat)main_screen_size.width,
            (VfxFloat)main_screen_size.height,
            (VfxFloat)-main_screen_size.height,
            (VfxFloat)main_screen_size.height);
        world->setActiveCamera(camera);

        VfxSphereMesh *mesh;
        VfxKeyframeSequence *kfs;
        VfxKeyframeTimeline *kf_tl;

        /* Step */
        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (20.0f));

        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (5, VFX_TYPE_ID_VEC3));
        kfs->setKeyframe(0, 0,    &VfxVector3f((VfxFloat)w * 1, (VfxFloat)h * 1, 0));
        kfs->setKeyframe(1, 500,  &VfxVector3f((VfxFloat)w * 2, (VfxFloat)h * 1 - 50, 0));
        kfs->setKeyframe(2, 1000, &VfxVector3f((VfxFloat)w * 3, (VfxFloat)h * 1, 0));
        kfs->setKeyframe(3, 1500, &VfxVector3f((VfxFloat)w * 4, (VfxFloat)h * 1 - 50, 0));
        kfs->setKeyframe(4, 2000, &VfxVector3f((VfxFloat)w * 5, (VfxFloat)h * 1, 0));

        VfxU32 userData = 0x12345678;

        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, mesh);
        kf_tl->setTarget(mesh);
        kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SPLINE);
        kf_tl->setDuration(2000);
        kf_tl->setAutoReversed(VFX_TRUE);
        kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        kf_tl->setCustomInterpolateFunc(testInterpolateFuncCallback, &userData, sizeof(userData));
        kf_tl->start();

    }
	static VfxTimelineInterpolationRetEnum testInterpolateFuncCallback(
        void *output, 
        const void *fromValue, 
        const void *toValue, 
        VfxTypeIdEnum typeId, 
        VfxFloat t,  
        void *data, 
        VfxU32 dataSize)
    {
        VFX_DEV_ASSERT(data != NULL && dataSize == sizeof(VfxU32));
        VFX_DEV_ASSERT(*(VfxU32 *)data == 0x12345678);
        
        return VFX_TIMELINE_INTERPOLATION_RET_DONE;
    }

};


class AvkV3dTimelineChainC04 : public AvkV3dBaseScr
{
// Variable
public:
   VfxFrame *m_frame;

// Constructor / Destructor
public:
   AvkV3dTimelineChainC04() : 
   m_frame(NULL)
   {
   }


// Override
public:  
   virtual void startTest(VfxWString wstrCaseName,int item_idx)  
   {
       AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
       confirm(VFX_WSTR("Pulse timeline time OK?"));

       
       vrt_size_struct main_screen_size;
       vrt_color_type_enum main_screen_color_format;
       vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);
                
                   
        VfxS32 w = (main_screen_size.width) / 6;
        VfxS32 h = main_screen_size.height / 5;

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

        /* create reference time */
        VfxFloatTimeline *t;
        VFX_OBJ_CREATE(t, VfxFloatTimeline, m_frame);
        t->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
        t->setTarget(m_frame);
        t->setDuration(1000);
        t->setFromValue(2.0f);
        t->setToValue(2.0f);
        t->setAutoReversed(VFX_TRUE);
        t->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);

        /* create animation */
        VfxAnimation *animation;
        VFX_OBJ_CREATE(animation, VfxAnimation, m_frame);

        VfxFrame *frame;
        VfxPointTimeline *kf_tl;

        VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
        frame->setSize(VfxSize(10, 10));
        frame->setPos(w * 1, h * 1);
        frame->setBgColor(VFX_COLOR_WHITE);
        VFX_OBJ_CREATE(kf_tl, VfxPointTimeline, animation);
        kf_tl->setTarget(frame);
        kf_tl->setFromValue(VfxPoint(w * 1, h * 1));
        kf_tl->setToValue(VfxPoint(w * 5, h * 1));
        kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        kf_tl->setDuration(2000);

        VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
        frame->setSize(VfxSize(10, 10));
        frame->setPos(w * 1, h * 2);
        frame->setBgColor(VFX_COLOR_WHITE);
        VFX_OBJ_CREATE(kf_tl, VfxPointTimeline, animation);
        kf_tl->setTarget(frame);
        kf_tl->setFromValue(VfxPoint(w * 1, h * 2));
        kf_tl->setToValue(VfxPoint(w * 3, h * 2));
        kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        kf_tl->setStartTime(0);
        kf_tl->setDuration(1000);

        VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
        frame->setSize(VfxSize(10, 10));
        frame->setPos(w * 3, h * 3);
        frame->setBgColor(VFX_COLOR_WHITE);
        VFX_OBJ_CREATE(kf_tl, VfxPointTimeline, animation);
        kf_tl->setTarget(frame);
        kf_tl->setFromValue(VfxPoint(w * 3, h * 3));
        kf_tl->setToValue(VfxPoint(w * 5, h * 3));
        kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        kf_tl->setStartTime(1000);
        kf_tl->setDuration(1000);

        animation->setTimelineTime(t);

        /* Start reference timeline */
        t->start();
   }
};

        
class AvkV3dTimelineChainC05 : public AvkV3dBaseScr
{
// Variable
public:
   VfxFrame *m_frame;

// Constructor / Destructor
public:
   AvkV3dTimelineChainC05() : 
   m_frame(NULL)
   {
   }


// Override
public:  
   virtual void startTest(VfxWString wstrCaseName,int item_idx)  
   {
       AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
       confirm(VFX_WSTR("Wrap Type OK?"));

       
       vrt_size_struct main_screen_size;
       vrt_color_type_enum main_screen_color_format;
       vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);



        VfxS32 w = (main_screen_size.width) / 7;
        VfxS32 h = main_screen_size.height / 5;

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

        /* create reference time */
        VfxFloatTimeline *t;
        VFX_OBJ_CREATE(t, VfxFloatTimeline, m_frame);
        t->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
        t->setTarget(m_frame);
        t->setDuration(2000);
        t->setFromValue(-2.0f);
        t->setToValue(3.0f);
        t->setAutoReversed(VFX_TRUE);
        t->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);

        /* create animation */
        VfxAnimation *animation;
        VFX_OBJ_CREATE(animation, VfxAnimation, m_frame);

        VfxFrame *frame;
        VfxPointTimeline *kf_tl;

        VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
        frame->setSize(VfxSize(10, 10));
        frame->setPos(w * 3, h * 1);
        frame->setBgColor(VFX_COLOR_WHITE);
        VFX_OBJ_CREATE(kf_tl, VfxPointTimeline, animation);
        kf_tl->setTarget(frame);
        kf_tl->setFromValue(VfxPoint(w * 3, h * 1));
        kf_tl->setToValue(VfxPoint(w * 4, h * 1));
        kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        kf_tl->setDuration(2000);
        kf_tl->setTimelineTime(t, 1.0f, 0.0f, VFX_TIMELINE_TIME_WRAP_TYPE_CLAMP);

        VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
        frame->setSize(VfxSize(10, 10));
        frame->setPos(w * 3, h * 2);
        frame->setBgColor(VFX_COLOR_WHITE);
        VFX_OBJ_CREATE(kf_tl, VfxPointTimeline, animation);
        kf_tl->setTarget(frame);
        kf_tl->setFromValue(VfxPoint(w * 3, h * 2));
        kf_tl->setToValue(VfxPoint(w * 4, h * 2));
        kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        kf_tl->setDuration(1000);
        kf_tl->setTimelineTime(t, 1.0f, 0.0f, VFX_TIMELINE_TIME_WRAP_TYPE_NONE);

        VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
        frame->setSize(VfxSize(10, 10));
        frame->setPos(w * 3, h * 3);
        frame->setBgColor(VFX_COLOR_WHITE);
        VFX_OBJ_CREATE(kf_tl, VfxPointTimeline, animation);
        kf_tl->setTarget(frame);
        kf_tl->setFromValue(VfxPoint(w * 3, h * 3));
        kf_tl->setToValue(VfxPoint(w * 4, h * 3));
        kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        kf_tl->setDuration(1000);
        kf_tl->setTimelineTime(t, 1.0f, 0.0f, VFX_TIMELINE_TIME_WRAP_TYPE_REPEAT);

        VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
        frame->setSize(VfxSize(10, 10));
        frame->setPos(w * 3, h * 4);        
        frame->setBgColor(VFX_COLOR_WHITE);
        VFX_OBJ_CREATE(kf_tl, VfxPointTimeline, animation);
        kf_tl->setTarget(frame);
        kf_tl->setFromValue(VfxPoint(w * 3, h * 4));
        kf_tl->setToValue(VfxPoint(w * 4, h * 4));
        kf_tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        kf_tl->setDuration(1000);
        kf_tl->setTimelineTime(t, 1.0f, 0.0f, VFX_TIMELINE_TIME_WRAP_TYPE_MIRROR);

        /* Start reference timeline */
        t->start();
   }
};

                        
class AvkV3dTimelineChainC06 : public AvkV3dBaseScr
{
// Variable
public:
   VfxFrame *m_frame;

// Constructor / Destructor
public:
   AvkV3dTimelineChainC06() : 
   m_frame(NULL)
   {
   }


// Override
public:  
   virtual void startTest(VfxWString wstrCaseName,int item_idx)  
   {
       AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
       confirm(VFX_WSTR("Multi-level timeline chain OK?"));

       
       vrt_size_struct main_screen_size;
       vrt_color_type_enum main_screen_color_format;
       vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);



                

        VfxS32 w = (main_screen_size.width) / 7;
        VfxS32 h = main_screen_size.height / 5;

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

        /* create reference time */
        VfxFloatTimeline *mainTl;
        VFX_OBJ_CREATE(mainTl, VfxFloatTimeline, m_frame);
        mainTl->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
        mainTl->setTarget(m_frame);
        mainTl->setDuration(2000);
        mainTl->setFromValue(0.0f);
        mainTl->setToValue(1.0f);
        mainTl->setAutoReversed(VFX_TRUE);
        mainTl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);

        /* create animation */
        VfxFloatTimeline *tl1;
        VFX_OBJ_CREATE(tl1, VfxFloatTimeline, m_frame);
        tl1->setTarget(m_frame);
        tl1->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
        tl1->setFromValue(0.0f);
        tl1->setToValue(1.0f);
        tl1->setTimelineTime(mainTl, 2.0f, -1.0f, VFX_TIMELINE_TIME_WRAP_TYPE_CLAMP);

        VfxFloatTimeline *tl2;
        VFX_OBJ_CREATE(tl2, VfxFloatTimeline, m_frame);
        tl2->setTarget(m_frame);
        tl2->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
        tl2->setFromValue(0.0f);
        tl2->setToValue(1.0f);
        tl2->setTimelineTime(mainTl, 2.0f, 0.0f, VFX_TIMELINE_TIME_WRAP_TYPE_CLAMP);

        VfxFrame *frame1a;
        VFX_OBJ_CREATE(frame1a, VfxFrame, m_frame);
        frame1a->setSize(VfxSize(10, 10));
        frame1a->setBgColor(VFX_COLOR_WHITE);

        VfxPointTimeline *tl1a;
        VFX_OBJ_CREATE(tl1a, VfxPointTimeline, m_frame);
        tl1a->setTarget(frame1a);
        tl1a->setFromValue(VfxPoint(w * 1, h * 1));
        tl1a->setToValue(VfxPoint(w * 6, h * 1));
        tl1a->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        tl1a->setTimelineTime(tl1);

        VfxFrame *frame1b;
        VFX_OBJ_CREATE(frame1b, VfxFrame, m_frame);
        frame1b->setSize(VfxSize(10, 10));
        frame1b->setBgColor(VFX_COLOR_WHITE);
        
        VfxPointTimeline *tl1b;
        VFX_OBJ_CREATE(tl1b, VfxPointTimeline, m_frame);
        tl1b->setTarget(frame1b);
        tl1b->setFromValue(VfxPoint(w * 1, h * 2));
        tl1b->setToValue(VfxPoint(w * 6, h * 2));
        tl1b->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        tl1b->setTimelineTime(tl2);

        /* Start reference timeline */
        mainTl->start();
   }
};






/***************************************************************************** 
 * Class VtstRtTimelineChainFromCurrent
 *****************************************************************************/

class AvkV3dTimelineChainFromCurrent : public AvkV3dBaseScr
{
// Variable
public:
    VfxFrame *m_frame;
    VfxFloatTimeline *m_mainTl;
    VfxU32 m_step;

// Constructor / Destructor
public:
    AvkV3dTimelineChainFromCurrent() : 
        m_frame(NULL),
        m_mainTl(NULL),
        m_step(0)
    {
    }

// Override
public:  
   virtual void startTest(VfxWString wstrCaseName,int item_idx)  
   {
       AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
       confirm(VFX_WSTR("Press key and from current OK?"));


        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

   
        VfxS32 w = main_screen_size.width / 6;
        VfxS32 h = main_screen_size.height / 6;

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setSize(VfxSize(main_screen_size.width, main_screen_size.height));

        /* create reference time */
        VFX_OBJ_CREATE(m_mainTl, VfxFloatTimeline, m_frame);
        m_mainTl->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
        m_mainTl->setTarget(m_frame);
        m_mainTl->setDuration(500);
        m_mainTl->setIsFromCurrent(VFX_TRUE);
        m_mainTl->setToValue(0.0f);

        VfxFrame *frame;
        VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
        frame->setSize(VfxSize(10, 10));
        frame->setPos(w * 1, h * 1);
        frame->setBgColor(VFX_COLOR_WHITE);
        
        VfxPointTimeline *tl;
        VFX_OBJ_CREATE(tl, VfxPointTimeline, m_frame);
        tl->setTarget(frame);
        tl->setFromValue(VfxPoint(w * 1, h * 1));
        tl->setToValue(VfxPoint(w * 5, h * 1));
        tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        tl->setTimelineTime(m_mainTl);

  
    }

protected:
    virtual VfxBool onPenInput(VfxPenEvent &event)
    {
        VfxBool ret = AvkV3dBaseScr::onPenInput(event);

        if(ret == VFX_FALSE)
        {
           
           if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
           {
              m_mainTl->setToValue(m_step % 2 == 0 ? 1.0f : 0.0f);
              m_mainTl->start();
   
              m_step++;            
           }                
        }               
        return ret;
     }
   
};






class AvkV3dSceneGraph : public AvkV3dBaseScr
{
// Variable
public:

    VfxWorld *m_world;
    VfxCamera *m_camera;
    VfxLight *m_light;
    VfxGroup *m_group;
    VfxSphereMesh *m_mesh1;
    VfxSphereMesh *m_mesh2;
    VfxSphereMesh *m_mesh3;
    VfxSphereMesh *m_mesh4;

    /* UI button */
    VcpButton *m_btnAddCamera;
    VcpButton *m_btnRemoveCamera;

    //VcpButton *m_btnAddLight;
    //VcpButton *m_btnRemoveLight;

    VcpButton *m_btnAddGroup;
    VcpButton *m_btnRemoveGroup;

    VcpButton *m_btnAddMesh1;
    VcpButton *m_btnRemoveMesh1;
    VcpButton *m_btnAddMesh2;
    VcpButton *m_btnRemoveMesh2;
    VcpButton *m_btnAddMesh3;
    VcpButton *m_btnRemoveMesh3;
    VcpButton *m_btnAddMesh4;
    VcpButton *m_btnRemoveMesh4;

    // Constructor / Destructor
public:
    AvkV3dSceneGraph()
    : m_world(NULL)
    , m_camera(NULL)
    , m_light(NULL)
    , m_mesh1(NULL)
    , m_mesh2(NULL)
    , m_group(NULL)
    , m_mesh3(NULL)
    , m_mesh4(NULL)
    , m_btnAddCamera(NULL)
    , m_btnRemoveCamera(NULL)
    //, m_btnAddLight(NULL)
    //, m_btnRemoveLight(NULL)
    , m_btnAddGroup(NULL)
    , m_btnRemoveGroup(NULL)
    , m_btnAddMesh1(NULL)
    , m_btnRemoveMesh1(NULL)
    , m_btnAddMesh2(NULL)
    , m_btnRemoveMesh2(NULL)
    , m_btnAddMesh3(NULL)
    , m_btnRemoveMesh3(NULL)
    , m_btnAddMesh4(NULL)
    , m_btnRemoveMesh4(NULL)
    {
    }


// Override
public:  
   virtual void startTest(VfxWString wstrCaseName,int item_idx)  
   {
       AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
       confirm(VFX_WSTR("Scene Graph OK?"));

        VfxS32 w = getSize().width / 3.5;
        VfxS32 h = getSize().height / 17;
        VfxS32 l = 0;
        VfxS32 t = h * 1;

        VFX_OBJ_CREATE(m_world, VfxWorld, this);
        setWorld(m_world);

        VFX_OBJ_CREATE(m_btnAddCamera, VcpButton, this);
        m_btnAddCamera->setRect(VfxRect(l, t+=h, w, h));
        m_btnAddCamera->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnAddCamera->setText(VFX_WSTR("+ Camera"));
        m_btnAddCamera->setTextFont(VFX_FONT_DESC_SMALL);
        m_btnAddCamera->m_signalClicked.connect(this, &AvkV3dSceneGraph::onAddCamera);

        VFX_OBJ_CREATE(m_btnRemoveCamera, VcpButton, this);
        m_btnRemoveCamera->setRect(VfxRect(l, t+=h, w, h));
        m_btnRemoveCamera->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnRemoveCamera->setText(VFX_WSTR("- Camera"));
        m_btnRemoveCamera->setTextFont(VFX_FONT_DESC_SMALL);
        m_btnRemoveCamera->setIsDisabled(VFX_TRUE);
        m_btnRemoveCamera->m_signalClicked.connect(this, &AvkV3dSceneGraph::onRemoveCamera);

        /*VFX_OBJ_CREATE(m_btnAddLight, VcpButton, this);
        m_btnAddLight->setRect(VfxRect(l, t+=h, w, h));
        m_btnAddLight->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnAddLight->setText(VFX_WSTR("+ Light"));
        m_btnAddLight->setTextFont(VFX_FONT_DESC_SMALL);        
        m_btnAddLight->m_signalClicked.connect(this, &AvkV3dSceneGraph::onAddLight);

        VFX_OBJ_CREATE(m_btnRemoveLight, VcpButton, this);
        m_btnRemoveLight->setRect(VfxRect(l, t+=h, w, h));
        m_btnRemoveLight->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnRemoveLight->setText(VFX_WSTR("- Light"));
        m_btnRemoveLight->setTextFont(VFX_FONT_DESC_SMALL);  
        m_btnRemoveLight->setIsDisabled(VFX_TRUE);
        m_btnRemoveLight->m_signalClicked.connect(this, &AvkV3dSceneGraph::onRemoveLight);*/

        VFX_OBJ_CREATE(m_btnAddGroup, VcpButton, this);
        m_btnAddGroup->setRect(VfxRect(l, t+=h, w, h));
        m_btnAddGroup->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnAddGroup->setText(VFX_WSTR("+ Group"));
        m_btnAddGroup->setTextFont(VFX_FONT_DESC_SMALL);  
        m_btnAddGroup->m_signalClicked.connect(this, &AvkV3dSceneGraph::onAddGroup);

        VFX_OBJ_CREATE(m_btnRemoveGroup, VcpButton, this);
        m_btnRemoveGroup->setRect(VfxRect(l, t+=h, w, h));
        m_btnRemoveGroup->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnRemoveGroup->setText(VFX_WSTR("- Group"));
        m_btnRemoveGroup->setTextFont(VFX_FONT_DESC_SMALL);
        m_btnRemoveGroup->setIsDisabled(VFX_TRUE);
        m_btnRemoveGroup->m_signalClicked.connect(this, &AvkV3dSceneGraph::onRemoveGroup);

        VFX_OBJ_CREATE(m_btnAddMesh1, VcpButton, this);
        m_btnAddMesh1->setRect(VfxRect(l, t+=h, w, h));
        m_btnAddMesh1->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnAddMesh1->setText(VFX_WSTR("+ Mesh1"));
        m_btnAddMesh1->setTextFont(VFX_FONT_DESC_SMALL);
        m_btnAddMesh1->m_signalClicked.connect(this, &AvkV3dSceneGraph::onAddMesh1);

        VFX_OBJ_CREATE(m_btnRemoveMesh1, VcpButton, this);
        m_btnRemoveMesh1->setRect(VfxRect(l, t+=h, w, h));
        m_btnRemoveMesh1->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnRemoveMesh1->setText(VFX_WSTR("- Mesh1"));
        m_btnRemoveMesh1->setTextFont(VFX_FONT_DESC_SMALL);
        m_btnRemoveMesh1->setIsDisabled(VFX_TRUE);
        m_btnRemoveMesh1->m_signalClicked.connect(this, &AvkV3dSceneGraph::onRemoveMesh1);

        VFX_OBJ_CREATE(m_btnAddMesh2, VcpButton, this);
        m_btnAddMesh2->setRect(VfxRect(l, t+=h, w, h));
        m_btnAddMesh2->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnAddMesh2->setText(VFX_WSTR("+ Mesh2"));
        m_btnAddMesh2->setTextFont(VFX_FONT_DESC_SMALL);
        m_btnAddMesh2->m_signalClicked.connect(this, &AvkV3dSceneGraph::onAddMesh2);

        VFX_OBJ_CREATE(m_btnRemoveMesh2, VcpButton, this);
        m_btnRemoveMesh2->setRect(VfxRect(l, t+=h, w, h));
        m_btnRemoveMesh2->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnRemoveMesh2->setText(VFX_WSTR("- Mesh2"));
        m_btnRemoveMesh2->setTextFont(VFX_FONT_DESC_SMALL);
        m_btnRemoveMesh2->setIsDisabled(VFX_TRUE);
        m_btnRemoveMesh2->m_signalClicked.connect(this, &AvkV3dSceneGraph::onRemoveMesh2);

        VFX_OBJ_CREATE(m_btnAddMesh3, VcpButton, this);
        m_btnAddMesh3->setRect(VfxRect(l, t+=h, w, h));
        m_btnAddMesh3->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnAddMesh3->setText(VFX_WSTR("+ Mesh3"));
        m_btnAddMesh3->setTextFont(VFX_FONT_DESC_SMALL);
        m_btnAddMesh3->setIsDisabled(VFX_TRUE);
        m_btnAddMesh3->m_signalClicked.connect(this, &AvkV3dSceneGraph::onAddMesh3);

        VFX_OBJ_CREATE(m_btnRemoveMesh3, VcpButton, this);
        m_btnRemoveMesh3->setRect(VfxRect(l, t+=h, w, h));
        m_btnRemoveMesh3->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnRemoveMesh3->setText(VFX_WSTR("- Mesh3"));
        m_btnRemoveMesh3->setTextFont(VFX_FONT_DESC_SMALL);
        m_btnRemoveMesh3->setIsDisabled(VFX_TRUE);
        m_btnRemoveMesh3->m_signalClicked.connect(this, &AvkV3dSceneGraph::onRemoveMesh3);

        VFX_OBJ_CREATE(m_btnAddMesh4, VcpButton, this);
        m_btnAddMesh4->setRect(VfxRect(l, t+=h, w, h));
        m_btnAddMesh4->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnAddMesh4->setText(VFX_WSTR("+ Mesh4"));
        m_btnAddMesh4->setTextFont(VFX_FONT_DESC_SMALL);
        m_btnAddMesh4->setIsDisabled(VFX_TRUE);
        m_btnAddMesh4->m_signalClicked.connect(this, &AvkV3dSceneGraph::onAddMesh4);

        VFX_OBJ_CREATE(m_btnRemoveMesh4, VcpButton, this);
        m_btnRemoveMesh4->setRect(VfxRect(l, t+=h, w, h));
        m_btnRemoveMesh4->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnRemoveMesh4->setText(VFX_WSTR("- Mesh4"));
        m_btnRemoveMesh4->setTextFont(VFX_FONT_DESC_SMALL);
        m_btnRemoveMesh4->setIsDisabled(VFX_TRUE);
        m_btnRemoveMesh4->m_signalClicked.connect(this, &AvkV3dSceneGraph::onRemoveMesh4);

    }
private:
    void onAddCamera(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_camera == NULL)
        {
            VFX_OBJ_CREATE(m_camera, VfxCamera, m_world);
            m_world->setActiveCamera(m_camera);
            m_camera->setPerspective(
                VRT_PI_2,
                (vrt_float)getSize().width / (vrt_float)getSize().height,
                1.0f, 1000.0f);
            m_camera->setLookAt(VrtVector3f(0, 2, 5), VrtVector3f(0, 2, 0), VrtVector3f(0, 1, 0));
            m_btnAddCamera->setIsDisabled(VFX_TRUE);
            m_btnRemoveCamera->setIsDisabled(VFX_FALSE);
        }
    }

    void onRemoveCamera(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_camera)
        {
            VFX_OBJ_CLOSE(m_camera);
            m_btnAddCamera->setIsDisabled(VFX_FALSE);
            m_btnRemoveCamera->setIsDisabled(VFX_TRUE);
        }
    }

    /*void onAddLight(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_light == NULL)
        {
            VFX_OBJ_CREATE(m_light, VfxLight, m_world);
            m_btnAddLight->setIsDisabled(VFX_TRUE);
            m_btnRemoveLight->setIsDisabled(VFX_FALSE);
            
        }
    }

    void onRemoveLight(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_light)
        {
            VFX_OBJ_CLOSE(m_light);
            m_btnAddLight->setIsDisabled(VFX_FALSE);
            m_btnRemoveLight->setIsDisabled(VFX_TRUE);
        }
    }*/

    void onAddGroup(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_group == NULL)
        {
            VFX_OBJ_CREATE(m_group, VfxGroup, m_world);
            m_group->setTranslation(0, 4, 0);
            m_btnAddGroup->setIsDisabled(VFX_TRUE);
            m_btnRemoveGroup->setIsDisabled(VFX_FALSE);
            m_btnAddMesh3->setIsDisabled(VFX_FALSE);
            m_btnRemoveMesh3->setIsDisabled(VFX_TRUE);
            m_btnAddMesh4->setIsDisabled(VFX_FALSE);
            m_btnRemoveMesh4->setIsDisabled(VFX_TRUE);
        }
    }

    void onRemoveGroup(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_group)
        {
            VFX_OBJ_CLOSE(m_group);
            m_btnAddGroup->setIsDisabled(VFX_FALSE);
            m_btnRemoveGroup->setIsDisabled(VFX_TRUE);
            m_btnAddMesh3->setIsDisabled(VFX_TRUE);
            m_btnRemoveMesh3->setIsDisabled(VFX_TRUE);
            m_btnAddMesh4->setIsDisabled(VFX_TRUE);
            m_btnRemoveMesh4->setIsDisabled(VFX_TRUE);
            m_mesh3 = NULL;
            m_mesh4 = NULL;
        }
    }

    void onAddMesh1(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_mesh1 == NULL)
        {
            VFX_OBJ_CREATE(m_mesh1, VfxSphereMesh, m_world);
            m_mesh1->setTranslation(2, 0, 0);
            m_btnAddMesh1->setIsDisabled(VFX_TRUE);
            m_btnRemoveMesh1->setIsDisabled(VFX_FALSE);            
        }
    }

    void onRemoveMesh1(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_mesh1)
        {
            VFX_OBJ_CLOSE(m_mesh1);
            m_btnAddMesh1->setIsDisabled(VFX_FALSE);
            m_btnRemoveMesh1->setIsDisabled(VFX_TRUE);               
        }
    }

    void onAddMesh2(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_mesh2 == NULL)
        {
            VFX_OBJ_CREATE(m_mesh2, VfxSphereMesh, m_world);
            m_mesh2->setTranslation(-2, 0, 0);
            m_btnAddMesh2->setIsDisabled(VFX_TRUE);
            m_btnRemoveMesh2->setIsDisabled(VFX_FALSE);     

        }
    }

    void onRemoveMesh2(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_mesh2)
        {
            VFX_OBJ_CLOSE(m_mesh2);
            m_btnAddMesh2->setIsDisabled(VFX_FALSE);
            m_btnRemoveMesh2->setIsDisabled(VFX_TRUE);  
        }
    }

    void onAddMesh3(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_group && m_mesh3 == NULL)
        {
            VFX_OBJ_CREATE(m_mesh3, VfxSphereMesh, m_group);
            m_mesh3->setTranslation(2, 0, 0);
            m_btnAddMesh3->setIsDisabled(VFX_TRUE);
            m_btnRemoveMesh3->setIsDisabled(VFX_FALSE);  
        }
    }

    void onRemoveMesh3(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_mesh3)
        {
            VFX_OBJ_CLOSE(m_mesh3);
            m_btnAddMesh3->setIsDisabled(VFX_FALSE);
            m_btnRemoveMesh3->setIsDisabled(VFX_TRUE);  
        }
    }

    void onAddMesh4(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_group && m_mesh4 == NULL)
        {
            VFX_OBJ_CREATE(m_mesh4, VfxSphereMesh, m_group);
            m_mesh4->setTranslation(-2, 0, 0);
            m_btnAddMesh4->setIsDisabled(VFX_TRUE);
            m_btnRemoveMesh4->setIsDisabled(VFX_FALSE);  
        }
    }

    void onRemoveMesh4(VfxObject* sender, VfxId id)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        if (button && m_mesh4)
        {
            VFX_OBJ_CLOSE(m_mesh4);
            m_btnAddMesh4->setIsDisabled(VFX_FALSE);
            m_btnRemoveMesh4->setIsDisabled(VFX_TRUE);              
        }
    }

};




class AvkV3dTransformable : public AvkV3dBaseScr
{
// Variable
public:

    VfxBoxMesh *m_mesh;

    // Constructor / Destructor
public:
    AvkV3dTransformable()
    : m_mesh(NULL)
    {
    }

// Override
public:  
   virtual void startTest(VfxWString wstrCaseName,int item_idx)  
   {
        AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
        confirm(VFX_WSTR("Transformable OK?"));
        
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);
    
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 5), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));
    
        VFX_OBJ_CREATE(m_mesh, VfxBoxMesh, world);
        m_mesh->setScale(0.5);
        m_mesh->setRotationX(0);
        m_mesh->setTranslation(-2, 0, 0);
    
        VfxS32 texWidth = 100;
        VfxTextFrame *text;
        VcpSlider *slider;
    
        VfxS32 t = getSize().height/16;
        VfxS32 b = getSize().height;
    
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setFont(VFX_FONT_DESC_SMALL);
        text->setString(VFX_WSTR("Scale"));
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(texWidth, t);
        slider->setLength(getSize().width - texWidth);
        slider->setMaxValue(2.0);
        slider->setMinValue(0.5);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &AvkV3dTransformable::onScaleChange);
    
        t += getSize().height/16;
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, getSize().height*2/16);
        text->setFont(VFX_FONT_DESC_SMALL);        
        text->setString(VFX_WSTR("Rotate"));
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(texWidth, getSize().height*2/16);
        slider->setLength(getSize().width - texWidth);
        slider->setMaxValue(VFX_PI * 2);
        slider->setMinValue(0);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &AvkV3dTransformable::onRotationChange);
    
        t += getSize().height/16;
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setFont(VFX_FONT_DESC_SMALL);        
        text->setString(VFX_WSTR("Translate"));
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(texWidth, t);
        slider->setLength(getSize().width - texWidth);
        slider->setMaxValue(2);
        slider->setMinValue(-2);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &AvkV3dTransformable::onTranslationChange);

    }

private:
    void onScaleChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        m_mesh->setScale(newval);
    }

    void onRotationChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        m_mesh->setRotationX(newval);
    }

    void onTranslationChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        m_mesh->setTranslation(newval, 0, 0);
    }
};




class AvkV3dNode : public AvkV3dBaseScr
{
// Variable
public:

    VfxBoxMesh *m_mesh;
    VcpButton *m_button;

    // Constructor / Destructor
public:
    AvkV3dNode()
    : m_mesh(NULL)
    {
    }

// Override
public:  
   virtual void startTest(VfxWString wstrCaseName,int item_idx)  
   {
          AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     

          confirm(VFX_WSTR("Node OK?"));

        
          VfxWorld *world;
          VFX_OBJ_CREATE(world, VfxWorld, this);
          setWorld(world);

          VfxCamera *camera;
          VFX_OBJ_CREATE(camera, VfxCamera, world);
          world->setActiveCamera(camera);
          camera->setPerspective(
              VRT_PI_2,
              (vrt_float)getSize().width / (vrt_float)getSize().height,
              1.0f, 1000.0f);
          camera->setLookAt(VrtVector3f(0, 0, 5), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

          VFX_OBJ_CREATE(m_mesh, VfxBoxMesh, world);
          m_mesh->setOpacity(0.5);

          VfxS32 l = 0;
          VfxS32 h = getSize().height / 16;
          VfxS32 t = 0;
          VfxS32 texWidth = 100;

          t += h;
          
          VFX_OBJ_CREATE(m_button, VcpButton, this);
          m_button->setPos(l, t);
          m_button->setSize(getSize().width / 3.5, getSize().height / 17);
          m_button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);

          m_button->setText(VFX_WSTR("set hidden"));
          m_button->setTextFont(VFX_FONT_DESC_SMALL);
          m_button->m_signalClicked.connect(this, &AvkV3dNode::onChangeVisible);

          t += h;
          VfxTextFrame *text;
          VFX_OBJ_CREATE(text, VfxTextFrame, this);
          text->setPos(0, t);
          text->setAutoResized(VFX_TRUE);
          text->setFont(VFX_FONT_DESC_SMALL);
          text->setString(VFX_WSTR("Opacity"));          
          VcpSlider *slider;
          VFX_OBJ_CREATE(slider, VcpSlider, this);
          slider->setPos(texWidth, t);
          slider->setLength(getSize().width - texWidth);
          slider->setMaxValue(1);          
          slider->setMinValue(0);
          slider->setCurrentValue(0.5);          
          slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
          slider->m_signalUserChangedValue.connect(this, &AvkV3dNode::onOpacityChange);

    }

private:
    void onChangeVisible(VfxObject* sender, VfxId id)
    {
        m_mesh->setVisible(!m_mesh->isVisible());
        if(m_mesh->isVisible())
            m_button->setText(VFX_WSTR("set hidden"));
        else
            m_button->setText(VFX_WSTR("set visible"));            
    }

    void onOpacityChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        m_mesh->setOpacity(newval);
    }
};





class AvkV3dGroup : public AvkV3dBaseScr
{
// Variable
public:
    VfxGroup *m_group[3];
    VfxBoxMesh *m_mesh[3];

    // Constructor / Destructor
public:
    AvkV3dGroup()
    {
    }

// Override
public:  
   virtual void startTest(VfxWString wstrCaseName,int item_idx)  
   {
        AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
        confirm(VFX_WSTR("Hierarchy Transform OK?"));

        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 8), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));


        VfxObject *parent = world;
        VfxS32 i;
        VfxMatrix4f pivot;
        pivot.translate(0.5f, 0, 0);
        for (i = 0; i < 3; ++i)
        {
            VFX_OBJ_CREATE(m_group[i], VfxGroup, parent);
            m_group[i]->setRotationZ(0);
            parent = m_group[i];
            if (i != 0)
            {
                m_group[i]->setTranslation(2, 0, 0);                
            }
            else
            {
                m_group[i]->setTranslation(-3, 0, 0);  
            }
            

            VFX_OBJ_CREATE(m_mesh[i], VfxBoxMesh, parent);
            m_mesh[i]->setScale(2.0f, 0.25f, 0.25f);
            m_mesh[i]->setPivot(pivot);
        }

        VfxS32 h = getSize().height / 16;
        VfxS32 t = 0;
        VfxS32 texWidth = 50;

        t += h;
        VfxTextFrame *text;
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setString(VFX_WSTR("Group1"));
        text->setFont(VFX_FONT_DESC_SMALL);
        text->setAutoResized(VFX_TRUE);
        texWidth = text->getSize().width;
        VcpSlider *slider;
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(texWidth, t);
        slider->setLength(getSize().width - texWidth);
        slider->setMaxValue(VFX_PI * 2);
        slider->setMinValue(0);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &AvkV3dGroup::onRotationChange1);

        t += h;
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setString(VFX_WSTR("Group2"));
        text->setAutoResized(VFX_TRUE);
        text->setFont(VFX_FONT_DESC_SMALL);        
        texWidth = text->getSize().width;
        VFX_OBJ_CREATE(slider, VcpSlider, this);        
        slider->setPos(texWidth, t);
        slider->setLength(getSize().width - texWidth);
        slider->setMaxValue(VFX_PI * 2);
        slider->setMinValue(0);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &AvkV3dGroup::onRotationChange2);

        t += h;
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setString(VFX_WSTR("Group3"));
        text->setFont(VFX_FONT_DESC_SMALL);
        text->setAutoResized(VFX_TRUE);        
        texWidth = text->getSize().width;
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(texWidth, t);
        slider->setLength(getSize().width - texWidth);
        slider->setMaxValue(VFX_PI * 2);
        slider->setMinValue(0);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &AvkV3dGroup::onRotationChange3);
    }

private:
    void onRotationChange1(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        m_group[0]->setRotationZ(newval);
    }

    void onRotationChange2(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        m_group[1]->setRotationZ(newval);
    }

    void onRotationChange3(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        m_group[2]->setRotationZ(newval);
    }

};



class AvkV3dWorld : public AvkV3dBaseScr
{
// Variable
public:

// Override
public:  
   virtual void startTest(VfxWString wstrCaseName,int item_idx)  
   {
        AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
        confirm(VFX_WSTR("3D World OK?"));
        VfxWChar fn[256];

        VfxFrame *frame;
        VFX_OBJ_CREATE(frame, VfxFrame, this);
        frame->setRect(getSize().width/4, getSize().height/4, getSize().width/2, getSize().height/2);

        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, frame);
        frame->setWorld(world);

        VfxImage2D *bg;

        kal_wstrcpy((WCHAR*)fn,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)fn,(WCHAR*)L"avk_v3d_uiengine\\test.ktx");


        VFX_OBJ_CREATE_EX(bg, VfxImage2D, world, (VFX_WSTR_DYNAMIC(fn)));
        world->setBackground(bg);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            1,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 3), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxSphereMesh *mesh;
        VFX_OBJ_CREATE(mesh, VfxSphereMesh, world);
    }

};





class AvkV3dCamera : public AvkV3dBaseScr
{
// Variable
public:
    VfxCamera *m_camera;
    // Constructor / Destructor
public:
    AvkV3dCamera()
    : m_camera(NULL)
    {
    }

// Override
public:  
   virtual void startTest(VfxWString wstrCaseName,int item_idx)  
   {
        AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
        confirm(VFX_WSTR("Camera Control OK?"));
        
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        VFX_OBJ_CREATE(m_camera, VfxCamera, world);
        world->setActiveCamera(m_camera);
        m_camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        m_camera->setLookAt(VrtVector3f(0, 0, 8), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));



        VfxSphereMesh *mesh;
        VFX_OBJ_CREATE(mesh, VfxSphereMesh, world);
        mesh->setTranslation(2, 0 ,0);
        VFX_OBJ_CREATE(mesh, VfxSphereMesh, world);
        mesh->setTranslation(-2, 0 ,0);
        VFX_OBJ_CREATE(mesh, VfxSphereMesh, world);
        mesh->setTranslation(0, 0 ,2);
        VFX_OBJ_CREATE(mesh, VfxSphereMesh, world);
        mesh->setTranslation(0, 0 ,-2);


        VfxS32 h = getSize().height / 16;
        VfxS32 t = 0;
        VfxS32 texWidth = 50;

        VfxTextFrame *text;
        VcpSlider *slider;

        t += h;
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setAutoResized(VFX_TRUE);
        text->setString(VFX_WSTR("TX"));
        text->setFont(VFX_FONT_DESC_SMALL);        
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(texWidth, t);
        slider->setLength(getSize().width - texWidth);
        slider->setMaxValue(5);
        slider->setMinValue(-5);
        slider->setCurrentValue(0);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &AvkV3dCamera::onTranslationXChange);

        t += h;
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setString(VFX_WSTR("TY"));
        text->setFont(VFX_FONT_DESC_SMALL);        
        text->setAutoResized(VFX_TRUE);        
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(texWidth, t);
        slider->setLength(getSize().width - texWidth);
        slider->setMaxValue(5);
        slider->setMinValue(-5);
        slider->setCurrentValue(0);        
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &AvkV3dCamera::onTranslationYChange);

        t += h;
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setString(VFX_WSTR("TZ"));
        text->setFont(VFX_FONT_DESC_SMALL);        
        text->setAutoResized(VFX_TRUE);        
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(texWidth, t);
        slider->setLength(getSize().width - texWidth);
        slider->setMaxValue(10);
        slider->setCurrentValue(0);        
        slider->setMinValue(0);
        slider->setCurrentValue(5);    
        VfxVector3f trans = m_camera->getTranslation();
        trans.z = 5;
        m_camera->setTranslation(trans);        
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &AvkV3dCamera::onTranslationZChange);

        t += h;
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setString(VFX_WSTR("RY"));
        text->setFont(VFX_FONT_DESC_SMALL);        
        text->setAutoResized(VFX_TRUE);        
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(texWidth, t);
        slider->setLength(getSize().width - texWidth);
        slider->setMaxValue(VFX_PI);     
        slider->setMinValue(-VFX_PI);
        slider->setCurrentValue(0);           
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &AvkV3dCamera::onRotationYChange);
    }
   
private:
    void onTranslationXChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        VfxVector3f trans = m_camera->getTranslation();
        trans.x = newval;
        m_camera->setTranslation(trans);
    }

    void onTranslationYChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        VfxVector3f trans = m_camera->getTranslation();
        trans.y = newval;
        m_camera->setTranslation(trans);
    }

    void onTranslationZChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        VfxVector3f trans = m_camera->getTranslation();
        trans.z = newval;
        m_camera->setTranslation(trans);
    }

    void onRotationYChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        m_camera->setRotationY(newval);
    }
};




class AvkV3dViewport : public AvkV3dBaseScr
{
// Variable
public:
    VfxFrame *m_frame;
    // Constructor / Destructor
public:
    AvkV3dViewport()
    : m_frame(NULL)
    {
    }

// Override
public:  
   virtual void startTest(VfxWString wstrCaseName,int item_idx)  
   {
       AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     

        confirm(VFX_WSTR("3D in 2D Frame (Viewport) OK?"));
         VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setRect(100, 100, 100, 100);
        m_frame->setBgColor(VFX_COLOR_RED);
        m_frame->sendToBack();

        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, m_frame);
        m_frame->setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            1,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 3), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxSphereMesh *mesh;
        VFX_OBJ_CREATE(mesh, VfxSphereMesh, world);
    }

protected:
    virtual VfxBool onPenInput(VfxPenEvent &event)
    {
        VfxBool ret = AvkV3dBaseScr::onPenInput(event);

        if(ret == VFX_FALSE)
        {
            switch (event.type)
            {
            case VFX_PEN_EVENT_TYPE_DOWN:
                m_frame->setPos(event.downPos);
                break;
            }
        }      
        // do nothing
        return ret;
    }


};



class AvkV3dFrameTexture : public AvkV3dBaseScr
{
// Variable
public:
    VcpButton *m_buttontl;
    VcpButton *m_buttonhide;


    // Constructor / Destructor
public:
    AvkV3dFrameTexture()
    {
    }

// Override
public:  
   virtual void startTest(VfxWString wstrCaseName,int item_idx)  
   {
        AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
        confirm(VFX_WSTR("Frame Cache OK?"));
        
        VfxFrame *frame_3d;
        VFX_OBJ_CREATE(frame_3d, VfxFrame, this);
        frame_3d->setSize(getSize());

        // referenced texture frame is created after the 3d frame
        VfxFrame *frame;
        VFX_OBJ_CREATE(m_textureFrame, VfxFrame, this);
        frame = m_textureFrame;

        VfxS32 w = getSize().width / 3.5;
         VfxS32 h = getSize().height / 17;
         VfxS32 l = 0;
         VfxS32 t = h * 1;
         

        // texture frame it is
        frame->setSize(w, h*5);
        frame->setAnchor(1,0);
        frame->setPos(getSize().width,0);
        frame->setHints(VFX_FRAME_HINTS_TEXTURE);

        VcpButton *button;
        VFX_OBJ_CREATE(button, VcpButton, frame);
        button->setRect(VfxRect(l, 0, w, h));
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->setText(VFX_WSTR("Button 1"));
        button->setTextFont(VFX_FONT_DESC_SMALL);


        VFX_OBJ_CREATE(button, VcpButton, frame);
        button->setRect(VfxRect(l, t, w, h));     
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->setText(VFX_WSTR("Button 2"));
        button->setTextFont(VFX_FONT_DESC_SMALL);

        VFX_OBJ_CREATE(m_buttontl, VcpButton, frame);
        m_buttontl->setRect(VfxRect(l, t+=h, w, h));
        m_buttontl->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_buttontl->setText(VFX_WSTR("Stop TL"));
        m_buttontl->setTextFont(VFX_FONT_DESC_SMALL);
        m_buttontl->m_signalClicked.connect(this, &AvkV3dFrameTexture::onTestTl);
 

        VFX_OBJ_CREATE(m_buttonhide, VcpButton, frame);
        m_buttonhide->setRect(VfxRect(l, t+=h, w, h));
        m_buttonhide->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_buttonhide->setText(VFX_WSTR("set Hidden"));
        m_buttonhide->setTextFont(VFX_FONT_DESC_SMALL);        
        m_buttonhide->m_signalClicked.connect(this, &AvkV3dFrameTexture::onTestHidden);

        VFX_OBJ_CREATE(m_text, VfxTextFrame, frame);
        m_text->setRect(VfxRect(l, t+=h, w, h));
        m_text->setAutoResized(VFX_TRUE);
        m_text->setString(VFX_WSTR("0"));

        VFX_OBJ_CREATE(m_timer, VfxTimer, button);
        m_time = 0;
        m_timer->setDuration(1000);
        m_timer->m_signalTick.connect(this, &AvkV3dFrameTexture::onTimerTick);
        m_timer->start();

        VfxWorld *world;
        VFX_OBJ_CREATE(m_world, VfxWorld, this);
        world = m_world;
        frame_3d->setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 1, 2), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxBoxMesh *mesh;
        VFX_OBJ_CREATE(mesh, VfxBoxMesh, world);

        VfxKeyframeSequence *kfs;
        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (4, VFX_TYPE_ID_QUAT));
        kfs->setKeyframe(0, 0 * 10,    &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));
        kfs->setKeyframe(1, 667 * 10,  &VfxQuaternionf(VfxVector3f(0, vfxSin(2 * VFX_PI / 3), 0), vfxCos(2 * VFX_PI / 3)));
        kfs->setKeyframe(2, 1333 * 10, &VfxQuaternionf(VfxVector3f(0, vfxSin(4 * VFX_PI / 3), 0), vfxCos(4 * VFX_PI / 3)));
        kfs->setKeyframe(3, 2000 * 10, &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));

        VfxKeyframeTimeline *qtl;
        VFX_OBJ_CREATE(m_tl, VfxKeyframeTimeline, mesh);
        qtl = m_tl;
        qtl->setTarget(mesh);
        qtl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
        qtl->setKeyframeSequence(kfs);
        qtl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SLERP);
        qtl->setDuration(2000 * 10);
        qtl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        qtl->start();

        VfxMaterial *mat;
        VFX_OBJ_CREATE(mat, VfxMaterial, mesh);
        mesh->setMaterial(0, mat);

        VfxPass *pass;
        VFX_OBJ_CREATE(pass, VfxPass, mat);
        mat->setPass(0, pass);

        static const vrt_char fShader[] =
        "precision mediump float;           \n"
        "varying vec4 vColor;               \n"
        "varying vec2 vTexCoord;            \n"
        "uniform sampler2D frameTex;        \n"
        "void main()                        \n"
        "{                                  \n"
        "   gl_FragColor = /* vColor * */ texture2D(frameTex, vTexCoord);  \n"
        "}                          \n";

        VfxShaderProgram *program;
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (NULL, fShader));
        pass->setShaderProgram(program);

        VfxShaderUniforms *uniforms;
        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        VfxShaderVariable *var = uniforms->addUniformVariable(VFX_STR("frameTex"), VFX_TYPE_ID_SAMPLER, 1);
        pass->addShaderUniforms(uniforms);

        VfxTextureFrame *texture;
        VFX_OBJ_CREATE_EX(texture, VfxTextureFrame, var, (frame));
        var->setValue(texture);

        // use FPE to watch texture frame dirty to update the 3D frame
        frame_3d->setPropertyEffectCallback(m_textureFrame,
                          fpeCallback,
                          NULL,
                          0,
                          VRT_FPE_TRIGGER_TYPE_CONTENT_DIRTY);        
    }

private:
    void onTestHidden(VfxObject* sender, VfxId Id)
    {
        if (m_textureFrame->getHints() == VFX_FRAME_HINTS_TEXTURE)
        {
            m_textureFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);
            m_buttonhide->setText(VFX_WSTR("set visible"));
        }
        else
        {
            m_textureFrame->setHints(VFX_FRAME_HINTS_TEXTURE);
            m_buttonhide->setText(VFX_WSTR("set hidden"));            
        }
    }

    void onTestTl(VfxObject* sender, VfxId Id)
    {
        if (m_tl->getIsEnabled())
        {
            m_tl->stop();
            m_buttontl->setText(VFX_WSTR("Start TL"));
        }
        else
        {
            m_tl->start();
            m_buttontl->setText(VFX_WSTR("Stop TL"));
        }
    }

    void onTimerTick(VfxTimer *source)
    {
        VfxWString str;
        str.format("%d", m_time);
        m_text->setString(str);
        m_time++;
    }

    static vrt_render_dirty_type_enum fpeCallback(vrt_frame_visual_property_struct *target_frame,
                                                     const vrt_frame_visual_property_struct *watch_frame,
                                                     void *user_data,
                                                     vrt_u32 user_data_size)
    {
        return VRT_RENDER_DIRTY_TYPE_CONTENT_DIRTY;
    }

    VfxWorld *m_world;
    VfxFrame *m_textureFrame;
    VfxKeyframeTimeline *m_tl;
    VfxTextFrame *m_text;
    VfxU32 m_time;
    VfxTimer *m_timer;
};





class AvkV3dTextureTransform : public AvkV3dBaseScr
{
// Variable
public:

    // Constructor / Destructor
public:
    AvkV3dTextureTransform()
    {
    }


  // Override
public:  
     virtual void startTest(VfxWString wstrCaseName,int item_idx)  
     {
         AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
        confirm(VFX_WSTR("Texture Transform OK?"));
          VfxWChar vs[256];
        VfxWChar fs[256];

        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 70), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxMesh *mesh;
        VFX_OBJ_CREATE(mesh, VfxMesh, world);

        kal_wstrcpy((WCHAR*)vs,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)vs,(WCHAR*)L"avk_v3d_uiengine\\vtst_teapot001.msh");

        VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(vs));
        mesh->setRotationX(-VFX_PI / 3);

        VfxMaterial *mat;
        VFX_OBJ_CREATE(mat, VfxMaterial, mesh);
        mesh->setMaterial(0, mat);

        VfxPass *pass;
        VFX_OBJ_CREATE(pass, VfxPass, mat);
        mat->setPass(0, pass);


        VfxShaderProgram *program;


        kal_wstrcpy((WCHAR*)vs,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)vs,(WCHAR*)L"avk_v3d_uiengine\\tex_ani.vs");


        kal_wstrcpy((WCHAR*)fs,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)fs,(WCHAR*)L"avk_v3d_uiengine\\tex_ani.fs");
     
        VFX_OBJ_CREATE_EX(
            program, VfxShaderProgram, pass,
            (VFX_WSTR_DYNAMIC(vs), VFX_WSTR_DYNAMIC(fs)));
        pass->setShaderProgram(program);

        VfxShaderUniforms *uniforms;
        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);

        VfxShaderVariable *var;
        var = uniforms->addUniformVariable(VFX_STR("tex"), VFX_TYPE_ID_SAMPLER, 1);

        VfxTexture2D *texture;


        kal_wstrcpy((WCHAR*)vs,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)vs,(WCHAR*)L"avk_v3d_uiengine\\fieldstone-texture.jpg");
        

      
        VFX_OBJ_CREATE_EX(texture, VfxTexture2D, var, (VFX_WSTR_DYNAMIC(vs)));
        texture->setWrapping(VFX_TEXTURE_WRAP_REPEAT, VFX_TEXTURE_WRAP_REPEAT);
        var->setValue(texture);

        var = uniforms->addUniformVariable(VFX_STR("uTextureMatrix"), VFX_TYPE_ID_MAT4, 1);
        var->bindValue(texture, VFX_BINDING_TRANSFORM);


        VfxVector3fTimeline *tl;
        VFX_OBJ_CREATE(tl, VfxVector3fTimeline, texture);
        tl->setTarget(texture);
        tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        tl->setFromValue(VfxVector3f(0, 0, 0));
        tl->setToValue(VfxVector3f(1, 0, 0));
        tl->setDuration(2000);
        tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        tl->start();
    }

};







class AvkV3dProjectiveTexture : public AvkV3dBaseScr
{
// Variable
public:

    // Constructor / Destructor
public:
    AvkV3dProjectiveTexture()
    {
    }

    
    
  // Override
public:  
     virtual void startTest(VfxWString wstrCaseName,int item_idx)  
     {
         AvkV3dBaseScr::startTest(wstrCaseName, item_idx);    

        confirm(VFX_WSTR("Projective Texture OK?"));
       VfxWChar fn[256];

        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 60), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxLight *light;
        VFX_OBJ_CREATE(light, VfxLight, world);
        light->setTranslation(0, 50, 0);
        light->setRotationX(-VFX_PI / 2);

        VfxMesh *mesh;
        VFX_OBJ_CREATE(mesh, VfxMesh, world);

        kal_wstrcpy((WCHAR*)fn,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)fn,(WCHAR*)L"avk_v3d_uiengine\\vtst_teapot001.msh");
        
        VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(fn));
        mesh->setRotationX(-VFX_PI / 3);

        VfxKeyframeSequence *kfs;
        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (4, VFX_TYPE_ID_QUAT));
        kfs->setKeyframe(0, 0,    &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));
        kfs->setKeyframe(1, 6667,  &VfxQuaternionf(VfxVector3f(vfxSin(2 * VFX_PI / 3), 0, 0), vfxCos(2 * VFX_PI / 3)));
        kfs->setKeyframe(2, 13333, &VfxQuaternionf(VfxVector3f(vfxSin(4 * VFX_PI / 3), 0, 0), vfxCos(4 * VFX_PI / 3)));
        kfs->setKeyframe(3, 20000, &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));

        VfxKeyframeTimeline *qtl;
        VFX_OBJ_CREATE(qtl, VfxKeyframeTimeline, mesh);
        qtl->setTarget(mesh);
        qtl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
        qtl->setKeyframeSequence(kfs);
        qtl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SLERP);
        qtl->setDuration(20000);
        qtl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        qtl->start();


        VfxMaterial *mat;
        VFX_OBJ_CREATE(mat, VfxMaterial, mesh);
        mesh->setMaterial(0, mat);

        VfxPass *pass;
        VFX_OBJ_CREATE(pass, VfxPass, mat);
        mat->setPass(0, pass);

        static const vrt_char vShader[] =
        "attribute vec4 v3d_Position;     \n"
        "attribute vec3 v3d_Normal;       \n"
        "varying vec4 vColor;             \n"
        "varying vec4 vTexCoord;          \n"
        "uniform vec4 v3d_PositionScale;  \n"
        "uniform vec4 v3d_PositionBias;   \n"
        "uniform mat4 v3d_MVPMatrix;      \n"
        "uniform mat4 v3d_ModelMatrix;    \n"
        "uniform mat4 v3d_ViewMatrix;     \n"
        "uniform mat3 v3d_NormalMatrix;   \n"
        "uniform mat4 u_LightViewMatrix;  \n"
        "uniform mat4 u_LightProjectMatrix;\n"
        "void main()                      \n"
        "{                                \n"
        "   vec4 pos = v3d_Position * v3d_PositionScale + v3d_PositionBias; \n"
        "   gl_Position = v3d_MVPMatrix * pos; \n"
        "   vTexCoord = u_LightProjectMatrix * v3d_ViewMatrix * v3d_ModelMatrix * pos; \n"
        "   vColor.rgb = vec3(dot(v3d_NormalMatrix * v3d_Normal, vec3(0.0, 0.0, 1.0))); \n"
        "   vColor.a = 1.0;               \n"
        "}                                \n";

        static const vrt_char fShader[] =
        "precision mediump float;           \n"
        "varying vec4 vColor;               \n"
        "varying vec4 vTexCoord;            \n"
        "uniform sampler2D u_ProjTex;       \n"
        "void main()                        \n"
        "{                                  \n"
        "   gl_FragColor = vColor * texture2DProj(u_ProjTex, vTexCoord);  \n"
        "}                                  \n";

        VfxShaderProgram *program;
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (vShader, fShader));
        pass->setShaderProgram(program);

        VfxShaderUniforms *uniforms;
        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);

        VfxShaderVariable *var;
        var = uniforms->addUniformVariable(VFX_STR("u_LightViewMatrix"), VFX_TYPE_ID_MAT4, 1);
        var->bindValue(light, VFX_BINDING_INVERSE_WORLD_TRANSFORM);

        var = uniforms->addUniformVariable(VFX_STR("u_LightProjectMatrix"), VFX_TYPE_ID_MAT4, 1);
        VfxMatrix4f proj;
        proj.setPerspective(VFX_PI / 4.0f, 1.0f, 1.0f, 1000.0f);
        VfxMatrix4f bias;
        bias.setScale(0.5f);
        bias.translate(0.5f, 0.5f, 0.5f);
        bias *= proj;
        var->setValue(bias);

        var = uniforms->addUniformVariable(VFX_STR("u_ProjTex"), VFX_TYPE_ID_SAMPLER, 1);

        VfxTexture2D *texture;

        kal_wstrcpy((WCHAR*)fn,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)fn,(WCHAR*)L"avk_v3d_uiengine\\test.ktx");


        VFX_OBJ_CREATE_EX(texture, VfxTexture2D, var, (VFX_WSTR_DYNAMIC(fn)));
        var->setValue(texture);
    }

};




class AvkV3dEnvironmentMap : public AvkV3dBaseScr
{
// Variable
public:

    // Constructor / Destructor
public:
    AvkV3dEnvironmentMap()
    {
    }

  // Override
public:  
     virtual void startTest(VfxWString wstrCaseName,int item_idx)  
     {
         AvkV3dBaseScr::startTest(wstrCaseName, item_idx);    

        confirm(VFX_WSTR("Environment Map OK?"));
         VfxWChar vs[256];
                VfxWChar fs[256];

        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, -60, 0), VrtVector3f(0, 0, 0), VrtVector3f(0, 0, 1));
        //camera->setLookAt(VrtVector3f(0, 0, 60), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxLight *light;
        VFX_OBJ_CREATE(light, VfxLight, world);
        light->setTranslation(0, 50, 0);
        light->setRotationX(-VFX_PI / 2);

        VfxMesh *mesh;
        VFX_OBJ_CREATE(mesh, VfxMesh, world);

        

        kal_wstrcpy((WCHAR*)vs,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)vs,(WCHAR*)L"avk_v3d_uiengine\\vtst_teapot001.msh");

        VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(vs));
        //VfxSphereMesh *mesh;
        //VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (30));
        mesh->setRotationX(-VFX_PI / 3);

        VfxKeyframeSequence *kfs;
        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (4, VFX_TYPE_ID_QUAT));
        kfs->setKeyframe(0, 0,    &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));
        kfs->setKeyframe(1, 6667,  &VfxQuaternionf(VfxVector3f(vfxSin(2 * VFX_PI / 3), 0, 0), vfxCos(2 * VFX_PI / 3)));
        kfs->setKeyframe(2, 13333, &VfxQuaternionf(VfxVector3f(vfxSin(4 * VFX_PI / 3), 0, 0), vfxCos(4 * VFX_PI / 3)));
        kfs->setKeyframe(3, 20000, &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));

        VfxKeyframeTimeline *qtl;
        VFX_OBJ_CREATE(qtl, VfxKeyframeTimeline, mesh);
        qtl->setTarget(mesh);
        qtl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
        qtl->setKeyframeSequence(kfs);
        qtl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SLERP);
        qtl->setDuration(20000);
        qtl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        qtl->start();


        VfxMaterial *mat;
        VFX_OBJ_CREATE(mat, VfxMaterial, mesh);
        mesh->setMaterial(0, mat);

        VfxPass *pass;
        VFX_OBJ_CREATE(pass, VfxPass, mat);
        mat->setPass(0, pass);


        VfxShaderProgram *program;

        

        kal_wstrcpy((WCHAR*)vs,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)vs,(WCHAR*)L"avk_v3d_uiengine\\reflection.vs");

        kal_wstrcpy((WCHAR*)fs,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)fs,(WCHAR*)L"avk_v3d_uiengine\\reflection.fs");

    
        VFX_OBJ_CREATE_EX(
            program, VfxShaderProgram, pass, 
            (VFX_WSTR_DYNAMIC(vs), VFX_WSTR_DYNAMIC(fs)));
        pass->setShaderProgram(program);

        VfxShaderUniforms *uniforms;
        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);

        VfxShaderVariable *var;
        var = uniforms->addUniformVariable(VFX_STR("u_CubeTex"), VFX_TYPE_ID_SAMPLER, 1);

        VfxTextureCube *texture;



        kal_wstrcpy((WCHAR*)vs,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)vs,(WCHAR*)L"avk_v3d_uiengine\\cube.ktx");




       
        VFX_OBJ_CREATE_EX(texture, VfxTextureCube, var, (VFX_WSTR_DYNAMIC(vs)));
        var->setValue(texture);
    }

};




class AvkV3dParticleSystem : public VfxProceduralMesh
{
    virtual vrt_u32 getVertexArrayCount() const
    {
        return 3;
    }

    virtual vrt_u32 getVertexCount() const
    {
        const vrt_u32 m_vertexCount = 1000;
        return m_vertexCount;
    }

    virtual vrt_u32 getComponentCount(vrt_u32 i) const
    {
        static const vrt_u32 m_componentCount[] = {1, 3, 3};
        return m_componentCount[i];
    }

    virtual vrt_type_id_enum getComponentDataType(vrt_u32 i) const
    {
        static const vrt_type_id_enum m_componentDataType[] =
        {
            VRT_TYPE_ID_FLOAT,
            VRT_TYPE_ID_FLOAT,
            VRT_TYPE_ID_FLOAT
        };
        return m_componentDataType[i];
    }

    virtual const vrt_char *getAttributeName(vrt_u32 i) const
    {
        const vrt_char *m_attributeName[] =
        {
            "a_lifetime",
            "a_startPosition",
            "a_endPosition"
        };
        return m_attributeName[i];
    }

    virtual vrt_bool isNormalized(vrt_u32 i) const
    {
        return VRT_FALSE;
    }

    virtual const vrt_float *getScaleVector(vrt_u32 i) const
    {
        static const vrt_float m_scale[] = {1.0f, 1.0f, 1.0f, 1.0f};
        return m_scale;
    }

    virtual const vrt_float *getBiasVector(vrt_u32 i) const
    {
        static const vrt_float m_bias[] = {0.0f, 0.0f, 0.0f, 0.0f};
        return m_bias;
    }

    /* index buffer */
    virtual vrt_u32 getIndexBufferCount() const
    {
        return 1;
    }

    virtual VrtPrimitiveType getPrimitiveType(vrt_u32 i) const
    {
        return VRT_PRIMITIVE_POINTS;
    }

    virtual vrt_u32 getIndexCount(vrt_u32 i) const
    {
        return getVertexCount();
    }

    virtual vrt_type_id_enum getIndexDataType(vrt_u32 i) const
    {
        return VRT_TYPE_ID_UNKNOWN;
    }

    virtual void initVertexArrays(void **va_buffers) const
    {
        float *lifeTime = (float *)va_buffers[0];
        float *startPos = (float *)va_buffers[1];
        float *endPos = (float *)va_buffers[2];

        vrt_u32 i;
        for ( i = 0; i < getVertexCount(); i++ )
        {
            // Lifetime of particle
            lifeTime[i] = ( (float)(rand() % 10000) / 10000.0f );

            // End position of particle
            endPos[i * 3 + 0] = ( (float)(rand() % 10000) / 5000.0f ) - 1.0f;
            endPos[i * 3 + 1] = ( (float)(rand() % 10000) / 5000.0f ) - 1.0f;
            endPos[i * 3 + 2] = ( (float)(rand() % 10000) / 5000.0f ) - 1.0f;

            // Start position of particle
            startPos[i * 3 + 0] = ( (float)(rand() % 10000) / 40000.0f ) - 0.125f;
            startPos[i * 3 + 1] = ( (float)(rand() % 10000) / 40000.0f ) - 0.125f;
            startPos[i * 3 + 2] = ( (float)(rand() % 10000) / 40000.0f ) - 0.125f;

        }
    }

    virtual void initIndexBuffers(void **data) const
    {
    }

};



class AvkV3dProceduralMesh : public AvkV3dBaseScr
{
// Variable
public:

    // Constructor / Destructor
public:
    AvkV3dProceduralMesh()
    {
    }

 // Override
public:  
     virtual void startTest(VfxWString wstrCaseName,int item_idx)  
     {
         AvkV3dBaseScr::startTest(wstrCaseName, item_idx);    

        confirm(VFX_WSTR("Procedural Mesh OK?"));
         VfxWChar vs[256];
        VfxWChar fs[256];


        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 1), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        AvkV3dParticleSystem *ps;
        VFX_OBJ_CREATE(ps, AvkV3dParticleSystem, world);

        VfxMaterial *mat;
        VFX_OBJ_CREATE(mat, VfxMaterial, ps);
        ps->setMaterial(0, mat);

        VfxPass *pass;
        VFX_OBJ_CREATE(pass, VfxPass, mat);
        mat->setPass(0, pass);

        VfxShaderProgram *program;
        
        kal_wstrcpy((WCHAR*)vs,(WCHAR*)AVK_TEST_FILE_PATH);
          kal_wstrcat((WCHAR*)vs,(WCHAR*)L"avk_v3d_uiengine\\particle.vs");

        kal_wstrcpy((WCHAR*)fs,(WCHAR*)AVK_TEST_FILE_PATH);
          kal_wstrcat((WCHAR*)fs,(WCHAR*)L"avk_v3d_uiengine\\particle.fs");
          

        VFX_OBJ_CREATE_EX(
            program,
            VfxShaderProgram,
            pass,
            (VFX_WSTR_DYNAMIC(vs),
             VFX_WSTR_DYNAMIC(fs)));
        pass->setShaderProgram(program);

        VfxShaderUniforms *uniforms;
        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);

        /* u_time */
        VfxShaderVariable *var;
        var = uniforms->addUniformVariable(VFX_STR("u_time"), VFX_TYPE_ID_FLOAT, 1);
        VfxFloatTimeline *tl;
        VFX_OBJ_CREATE(tl, VfxFloatTimeline, var);
        tl->setTarget(var);
        tl->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_FLOAT);
        tl->setFromValue(0.0f);
        tl->setToValue(1.0f);
        tl->setDuration(1000);
        tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        tl->start();

        /* u_color */
        var = uniforms->addUniformVariable(VFX_STR("u_color"), VFX_TYPE_ID_VEC4, 1);
        var->setValue(0.75f, 0.75f, 0.5f, 0.5f);

        /* s_texture */
        var = uniforms->addUniformVariable(VFX_STR("s_texture"), VFX_TYPE_ID_SAMPLER, 1);
        VfxTexture2D *texture;

        kal_wstrcpy((WCHAR*)vs,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)vs,(WCHAR*)L"avk_v3d_uiengine\\smoke.png");

        VFX_OBJ_CREATE_EX(texture, VfxTexture2D, var, (VFX_WSTR_DYNAMIC(vs)));
        var->setValue(texture);

        VfxCompositingMode *cm;
        VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
        cm->setDepthTestEnable(VFX_FALSE);

        pass->setCompositingMode(cm);

        VfxBlender *blender;
        VFX_OBJ_CREATE(blender, VfxBlender, cm);
        blender->setBlendFunc(VFX_BLEND_FACTOR_SRC_ALPHA, VFX_BLEND_FACTOR_ONE, VFX_BLEND_FACTOR_ONE, VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA);
        cm->setBlender(blender);
    }
};



class AvkV3dProceduralSkinnedMesh : public VfxProceduralSkinnedMesh
{
    static const VfxS32 u_count = 10;
    static const VfxS32 v_count = 20;

    virtual vrt_u32 getVertexArrayCount() const
    {
        return 4;
    }

    virtual vrt_u32 getVertexCount() const
    {
        const vrt_s32 numSlices = v_count;
        const vrt_s32 numParallels = u_count;
        const vrt_s32 numVertices = ( numParallels + 1 ) * ( numSlices + 1 );
        return numVertices;
    }

    virtual vrt_u32 getComponentCount(vrt_u32 i) const
    {
        static const vrt_u32 m_componentCount[] = {3, 3, 4, 4};
        return m_componentCount[i];
    }

    virtual vrt_type_id_enum getComponentDataType(vrt_u32 i) const
    {
        static const vrt_type_id_enum m_componentDataType[] =
        {
            VRT_TYPE_ID_FLOAT,
            VRT_TYPE_ID_FLOAT,
            VRT_TYPE_ID_FLOAT,
            VRT_TYPE_ID_U16
        };
        return m_componentDataType[i];
    }

    virtual const vrt_char *getAttributeName(vrt_u32 i) const
    {
        const vrt_char *m_attributeName[] =
        {
            "v3d_Position",
            "v3d_Normal",
            "v3d_BoneWeights",
            "v3d_BoneIndices"
        };
        return m_attributeName[i];
    }

    virtual vrt_bool isNormalized(vrt_u32 i) const
    {
        return VRT_FALSE;
    }

    virtual const vrt_float *getScaleVector(vrt_u32 i) const
    {
        static const vrt_float m_scale[] = {1.0f, 1.0f, 1.0f, 1.0f};
        return m_scale;
    }

    virtual const vrt_float *getBiasVector(vrt_u32 i) const
    {
        static const vrt_float m_bias[] = {0.0f, 0.0f, 0.0f, 0.0f};
        return m_bias;
    }

    /* index buffer */
    virtual vrt_u32 getIndexBufferCount() const
    {
        return 1;
    }

    virtual VrtPrimitiveType getPrimitiveType(vrt_u32 i) const
    {
        return VRT_PRIMITIVE_TRIANGLES;
    }

    virtual vrt_u32 getIndexCount(vrt_u32 i) const
    {
        const vrt_s32 numSlices = v_count;
        const vrt_s32 numParallels = u_count;
        const vrt_s32 numIndices = numParallels * numSlices * 6;
        return numIndices;
    }

    virtual vrt_type_id_enum getIndexDataType(vrt_u32 i) const
    {
        return VRT_TYPE_ID_U16;
    }

    virtual void initVertexArrays(void **va_buffers) const
    {
        VfxVector3f *pos = (VfxVector3f *)va_buffers[0];
        VfxVector3f *normal = (VfxVector3f *)va_buffers[1];
        VfxVector4f *weights = (VfxVector4f *)va_buffers[2];
        VfxVector4us *indices = (VfxVector4us *)va_buffers[3];

        const VfxS32 numSlices = v_count;
        const VfxS32 numParallels = u_count;
        const VfxFloat angleStep = -(2.0f * VFX_PI) / ((VfxFloat) numSlices);

        const VfxFloat radius = 0.5f;
        const VfxFloat hight = 4.0f;

        VfxS32 i, j;
        for ( i = 0; i < numParallels + 1; i++ )
        {
            for ( j = 0; j < numSlices + 1; j++ )
            {
                int vertex = ( i * (numSlices + 1) + j );

                normal[vertex].x = vfxSin ( angleStep * (VfxFloat)j );
                normal[vertex].z = vfxCos ( angleStep * (VfxFloat)j );
                normal[vertex].y = 0;

                pos[vertex].x = radius * normal[vertex].x;
                pos[vertex].z = radius * normal[vertex].z;
                pos[vertex].y = hight / numParallels * i;

                indices[vertex].x = 0;
                indices[vertex].y = 1;
                indices[vertex].z = 2;
                indices[vertex].w = 0;

                weights[vertex].x = 1.0f - float(i) / numParallels;
                weights[vertex].y = float(i) / numParallels;
                weights[vertex].z = 0;
                weights[vertex].w = 0;
            }
        }
    }

    virtual void initIndexBuffers(void **data) const
    {
        VfxU16 *indexBuf = (VfxU16 *)data[0];

        const VfxS32 numSlices = v_count;
        const VfxS32 numParallels = u_count;
        VfxS32 i, j;
        for ( i = 0; i < numParallels ; i++ )
        {
            for ( j = 0; j < numSlices; j++ )
            {
                *indexBuf++  = i * ( numSlices + 1 ) + j;
                *indexBuf++ = ( i + 1 ) * ( numSlices + 1 ) + j;
                *indexBuf++ = ( i + 1 ) * ( numSlices + 1 ) + ( j + 1 );

                *indexBuf++ = i * ( numSlices + 1 ) + j;
                *indexBuf++ = ( i + 1 ) * ( numSlices + 1 ) + ( j + 1 );
                *indexBuf++ = i * ( numSlices + 1 ) + ( j + 1 );
            }
        }
    }

};


class AvkV3dSkinnedMesh : public AvkV3dBaseScr
{
 // Override
public:  
     virtual void startTest(VfxWString wstrCaseName,int item_idx)  
     {
         AvkV3dBaseScr::startTest(wstrCaseName, item_idx);    

        confirm(VFX_WSTR("Skinned Mesh OK?"));
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 5), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxGroup *character;
        VFX_OBJ_CREATE(character, VfxGroup, world);
        character->setTranslation(0, -2, 0);

        /* create skeleton */
        VfxGroup *root;
        VFX_OBJ_CREATE(root, VfxGroup, character);
        VfxBone *bone_0;
        VFX_OBJ_CREATE(bone_0, VfxBone, root);
        bone_0->setTranslation(0, 0, 0);
        VfxBone *bone_1;
        VFX_OBJ_CREATE(bone_1, VfxBone, bone_0);
        bone_1->setTranslation(0, 2, 0);
        VfxBone *bone_2;
        VFX_OBJ_CREATE(bone_2, VfxBone, bone_1);
        bone_2->setTranslation(0, 2, 0);
        VfxSphereMesh *widget;
        VFX_OBJ_CREATE_EX(widget, VfxSphereMesh, bone_2, (0.5f));

        /* create skinned mesh */
        AvkV3dProceduralSkinnedMesh *mesh;
        VFX_OBJ_CREATE(mesh, AvkV3dProceduralSkinnedMesh, character);
        mesh->setSkeleton(bone_0);
        mesh->setTranslation(2, 0, 0);

        /* setup skeleton animation */
        VfxQuaternionfTimeline *qtl;
        VFX_OBJ_CREATE(qtl, VfxQuaternionfTimeline, bone_1);
        qtl->setTarget(bone_1);
        qtl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
        qtl->setFromValue(VfxQuaternionf(0,0,0,1));
        qtl->setToValue(VfxQuaternionf(0,0,vfxSin(VFX_PI / 4),vfxCos(VFX_PI / 4)));
        qtl->setDuration(2000);
        qtl->setAutoReversed(VFX_TRUE);
        qtl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        qtl->start();
    }

};





class AvkV3dAutoDepthBuffer: public AvkV3dBaseScr
{
// Variable
public:
    // Constructor / Destructor
    VfxFrame *m_frame;
public:
    AvkV3dAutoDepthBuffer()
    : m_frame(NULL)
    {
    }

 // Override
public:  
     virtual void startTest(VfxWString wstrCaseName,int item_idx)  
     {
         AvkV3dBaseScr::startTest(wstrCaseName, item_idx);    

        confirm(VFX_WSTR("Auto Depth Buffer OK?"));
         VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setRect(100, 100, 200, 200);
        m_frame->setBgColor(VFX_COLOR_YELLOW);        
        m_frame->sendToBack();
        m_frame->setOpacity(0.5f);

        VfxFrame *frame;
        VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
        frame->setRect(0, 0, 100, 100);
        frame->setBgColor(VFX_COLOR_RED);

        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, frame);
        frame->setWorld(world);

        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            1,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 3), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxSphereMesh *mesh;
        VFX_OBJ_CREATE(mesh, VfxSphereMesh, world);
    }

protected:
    virtual VfxBool onPenInput(VfxPenEvent &event)
    {
        VfxBool ret = AvkV3dBaseScr::onPenInput(event);
        if(ret==VFX_FALSE)
        {
            switch (event.type)
            {
            case VFX_PEN_EVENT_TYPE_DOWN:
                m_frame->setPos(event.downPos);
                break;
            }
        }

        // do nothing
        return ret;
    }
};


class BlueDraw : public VfxOwnerDraw
{
protected:
    
    virtual void onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect)
    {
        // Set the viewport
        glViewport( dstRect.origin.x, dstRect.origin.y, dstRect.size.width, dstRect.size.height );

        // Clear the color buffer
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
        glClear ( GL_COLOR_BUFFER_BIT );        
    }
};

class AvkV3dDisableColorKey : public AvkV3dBaseScr
{
// Variable
public:
    VfxFrame *m_frame;
    VcpButton *m_button;    

 // Override
public:  
     virtual void startTest(VfxWString wstrCaseName,int item_idx)  
     {
         AvkV3dBaseScr::startTest(wstrCaseName, item_idx);    

        confirm(VFX_WSTR("Disable Color Key OK?"));
         setBgColor(VFX_COLOR_WHITE);
        
        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setCacheMode(VFX_CACHE_MODE_FORCE);
        m_frame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_COLOR_KEY);
        m_frame->setHints(VFX_FRAME_HINTS_DISABLE_COLOR_KEY);
        m_frame->setBgColor(VFX_COLOR_YELLOW);
        m_frame->setRect(
            getSize().width/4,
            getSize().height/4,
            getSize().width/2,
            getSize().height/2);

        VfxFrame *frame;
        VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
        BlueDraw *ownerDraw;
        VFX_OBJ_CREATE(ownerDraw, BlueDraw, this);
        frame->setOwnerDraw(ownerDraw);
        frame->setRect(
            m_frame->getSize().width/4,
            m_frame->getSize().height/4,
            m_frame->getSize().width/2,
            m_frame->getSize().height/2);

        VFX_OBJ_CREATE(m_button, VcpButton, this);
        m_button->setAnchor(1,0);
        m_button->setPos(getSize().width, 0);
        m_button->setSize(getSize().width / 2.5, getSize().height / 17);
        m_button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_button->setText(VFX_WSTR("Enable ColorKey"));
        m_button->setTextFont(VFX_FONT_DESC_SMALL);
        m_button->m_signalClicked.connect(this, &AvkV3dDisableColorKey::onSwitchColorKey);
    }
private:
    void onSwitchColorKey(VfxObject* sender, VfxId Id)
    {
        VfxFrameHintsEnum hints = m_frame->getHints();              
        ((int &)hints) ^= VFX_FRAME_HINTS_DISABLE_COLOR_KEY;
        m_frame->setHints(hints);
        if(m_frame->getHints() == VFX_FRAME_HINTS_DISABLE_COLOR_KEY)
            m_button->setText(VFX_WSTR("Enable ColorKey"));
        else
            m_button->setText(VFX_WSTR("Disable ColorKey"));
    }

};



class AvkV3dRenderState : public AvkV3dBaseScr
{
// Variable
public:
    VfxBoxMesh *m_mesh;
    VfxPass *m_pass;

    VfxPolygonMode *m_pm;
    VfxWindingMode m_winding;
    VfxCullingMode m_culling;

    VfxCompositingMode *m_cm;
    VfxDepthFunc m_depthFunc;
    VfxU32 m_colorMask;

    VfxBlendEquation m_colorEquation;
    VfxBlendEquation m_alphaEquation;
    VfxBlendFactor m_srcColorFactor;
    VfxBlendFactor m_dstColorFactor;
    VfxBlendFactor m_srcAlphaFactor;
    VfxBlendFactor m_dstAlphaFactor;
    
    VfxBlender *m_blender;
    VfxStencil *m_stencil;

    VcpButton *m_btnWinding;
    VcpButton *m_btnCulling;
    
    VcpSwitch *m_btnDepthTest;
    VcpSwitch *m_btnDepthWrite;
    VcpButton *m_btnDepthFunc;
    VcpButton *m_btnColorMask;
    //VcpSwitch *m_btnStencil;
    VcpSwitch *m_btnBlender;

    VcpButton *m_btnColorEq;
    VcpButton *m_btnAlphaEq;
    VcpButton *m_btnSrcColorFactor;
    VcpButton *m_btnDstColorFactor;
    VcpButton *m_btnSrcAlphaFactor;
    VcpButton *m_btnDstAlphaFactor;

    // Constructor / Destructor
public:
    AvkV3dRenderState()
    : m_mesh(NULL)
    , m_pass(NULL)
    , m_pm(NULL)
    , m_winding(VFX_WINDING_CCW)
    , m_culling(VFX_CULLING_BACK)
    , m_cm(NULL)
    , m_depthFunc(VFX_DEPTH_FUNC_LESS)
    , m_colorMask(NULL)
    , m_colorEquation(VFX_BLEND_EQUATION_ADD)
    , m_alphaEquation(VFX_BLEND_EQUATION_ADD)
    , m_srcColorFactor(VFX_BLEND_FACTOR_SRC_ALPHA)
    , m_dstColorFactor(VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA)
    , m_srcAlphaFactor(VFX_BLEND_FACTOR_ONE)
    , m_dstAlphaFactor(VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA)
    , m_blender(NULL)
    , m_stencil(NULL)
    , m_btnWinding(NULL)
    , m_btnCulling(NULL)
    , m_btnDepthTest(NULL)
    , m_btnDepthWrite(NULL)
    , m_btnDepthFunc(NULL)
    , m_btnColorMask(NULL)
    //, m_btnStencil(NULL)
    , m_btnBlender(NULL)
    , m_btnColorEq(NULL)
    , m_btnAlphaEq(NULL)
    , m_btnSrcColorFactor(NULL)
    , m_btnDstColorFactor(NULL)
    , m_btnSrcAlphaFactor(NULL)
    , m_btnDstAlphaFactor(NULL)
    {
    }

 // Override
public:  
     virtual void startTest(VfxWString wstrCaseName,int item_idx)  
     {
         AvkV3dBaseScr::startTest(wstrCaseName, item_idx);    

        confirm(VFX_WSTR("Render State OK?"));

        // world
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        // camera
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 5), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        // mesh
        VFX_OBJ_CREATE_EX(m_mesh, VfxBoxMesh, world, (2.0f));
        m_mesh->setTranslation(0.5f, 0, 0);

        VfxSphereMesh *mesh;
        VFX_OBJ_CREATE(mesh, VfxSphereMesh, world);
        mesh->setTranslation(-0.5f, 0, 0);

        // material
        VfxMaterial *material;
        VFX_OBJ_CREATE(material, VfxMaterial, m_mesh);
        m_mesh->setMaterial(0, material);
        m_mesh->setRotationY(0);
        m_mesh->setOpacity(1);

        // pass
        VFX_OBJ_CREATE(m_pass, VfxPass, material);
        material->setPass(0, m_pass);

        VfxS32 w = getSize().width / 3.5;
        VfxS32 h = getSize().height / 17;
        VfxS32 l = 0;
        VfxS32 t = 0;
        VfxS32 indent = 0;

        // UI control
        VcpSwitch *sw;
        VfxTextFrame *text;
        VcpSlider *slider;

        // Polygon Mode
        t+=h;
        VFX_OBJ_CREATE(sw, VcpSwitch, this);
        sw->setPos(l, t);
        sw->m_signalSwitchChanged.connect(this, &AvkV3dRenderState::onSwitchPolygonMode);
        sw->setChecked(VFX_FALSE);
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(l + sw->getSize().width, t);
        text->setString(VFX_WSTR("PM"));
        text->setFont(VFX_FONT_DESC_SMALL);

        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(getSize().width / 2, t);
        slider->setLength(getSize().width/2);
        slider->setMaxValue(VFX_PI);
        slider->setMinValue(-VFX_PI);
        slider->setCurrentValue(0);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &AvkV3dRenderState::onRotationYChange);

        t+=h;
        VFX_OBJ_CREATE(m_btnWinding, VcpButton, this);
        m_btnWinding->setIsDisabled(VFX_TRUE);
        m_btnWinding->setRect(l+indent, t, w, h);
        m_btnWinding->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnWinding->setText(VFX_WSTR("CCW"));
        m_btnWinding->setTextFont(VFX_FONT_DESC_SMALL);
        m_btnWinding->m_signalClicked.connect(this, &AvkV3dRenderState::onWindingChanged);

        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setPos(getSize().width / 2, t);
        slider->setLength(getSize().width/2);
        slider->setMaxValue(1);
        slider->setMinValue(0);
        slider->setCurrentValue(1);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &AvkV3dRenderState::onOpacityChange);

        t+=h;
        VFX_OBJ_CREATE(m_btnCulling, VcpButton, this);
        m_btnCulling->setIsDisabled(VFX_TRUE);
        m_btnCulling->setRect(l+indent, t, w, h);
        m_btnCulling->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnCulling->setText(VFX_WSTR("BACK"));
        m_btnCulling->setTextFont(VFX_FONT_DESC_SMALL);        
        m_btnCulling->m_signalClicked.connect(this, &AvkV3dRenderState::onCullingChanged);

        // Compositing Mode
        t+=h;
        VFX_OBJ_CREATE(sw, VcpSwitch, this);
        sw->setPos(l, t);
        sw->m_signalSwitchChanged.connect(this, &AvkV3dRenderState::onSwitchCompositingMode);
        sw->setChecked(VFX_FALSE);
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(l + sw->getSize().width, t);
        text->setString(VFX_WSTR("CM"));
        text->setFont(VFX_FONT_DESC_SMALL);  

        // Depth Test
        t+=h;
        VFX_OBJ_CREATE(m_btnDepthTest, VcpSwitch, this);
        m_btnDepthTest->setIsDisabled(VFX_TRUE);
        m_btnDepthTest->setPos(l+indent, t);
        m_btnDepthTest->m_signalSwitchChanged.connect(this, &AvkV3dRenderState::onSwitchDepthTest);
        m_btnDepthTest->setChecked(VFX_FALSE);        
        m_btnDepthTest->setIsDisabled(VFX_TRUE);
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(l+indent + m_btnDepthTest->getSize().width, t);
        text->setString(VFX_WSTR("DT"));
        text->setFont(VFX_FONT_DESC_SMALL);  

        // Depth Func
        t+=h;
        VFX_OBJ_CREATE(m_btnDepthFunc, VcpButton, this);
        m_btnDepthFunc->setIsDisabled(VFX_TRUE);
        m_btnDepthFunc->setRect(l+indent, t, w, h);
        m_btnDepthFunc->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnDepthFunc->setTextFont(VFX_FONT_DESC_SMALL);          
        m_btnDepthFunc->setText(VFX_WSTR("LESS"));
        m_btnDepthFunc->m_signalClicked.connect(this, &AvkV3dRenderState::onDepthFuncChanged);


        // Depth Write
          t+=h;
          VFX_OBJ_CREATE(m_btnDepthWrite, VcpSwitch, this);
          m_btnDepthWrite->setIsDisabled(VFX_TRUE);
          m_btnDepthWrite->setPos(l+indent, t);
          m_btnDepthWrite->m_signalSwitchChanged.connect(this, &AvkV3dRenderState::onSwitchDepthWrite);
          m_btnDepthWrite->setChecked(VFX_FALSE);
          m_btnDepthWrite->setIsDisabled(VFX_TRUE);
          VFX_OBJ_CREATE(text, VfxTextFrame, this);
          text->setPos(l+indent + m_btnDepthWrite->getSize().width, t);
          text->setString(VFX_WSTR("DW"));
          text->setFont(VFX_FONT_DESC_SMALL);  

        // Color Mask
        t+=h;
        VFX_OBJ_CREATE(m_btnColorMask, VcpButton, this);
        m_btnColorMask->setIsDisabled(VFX_TRUE);
        m_btnColorMask->setRect(l+indent, t, w, h);
        m_btnColorMask->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnColorMask->setText(VFX_WSTR("RGBA"));
        m_btnColorMask->setTextFont(VFX_FONT_DESC_SMALL);  
        m_btnColorMask->m_signalClicked.connect(this, &AvkV3dRenderState::onColorMaskChanged);

        // Blender Mode
        t+=h;
        VFX_OBJ_CREATE(m_btnBlender, VcpSwitch, this);
        m_btnBlender->setIsDisabled(VFX_TRUE);
        m_btnBlender->setPos(l+indent, t);
        m_btnBlender->m_signalSwitchChanged.connect(this, &AvkV3dRenderState::onSwitchBlender);
        m_btnBlender->setChecked(VFX_FALSE);
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(l+indent + m_btnBlender->getSize().width, t);
        text->setString(VFX_WSTR("AB"));
        text->setFont(VFX_FONT_DESC_SMALL);  

        t+=h;
        VFX_OBJ_CREATE(m_btnColorEq, VcpButton, this);
        m_btnColorEq->setIsDisabled(VFX_TRUE);
        m_btnColorEq->setRect(l+2*indent, t, w, h);
        m_btnColorEq->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnColorEq->setText(VFX_WSTR("ADD"));
        m_btnColorEq->setTextFont(VFX_FONT_DESC_SMALL);  
        m_btnColorEq->m_signalClicked.connect(this, &AvkV3dRenderState::onBlendEquationChanged);

        t+=h;
        VFX_OBJ_CREATE(m_btnAlphaEq, VcpButton, this);
        m_btnAlphaEq->setIsDisabled(VFX_TRUE);
        m_btnAlphaEq->setRect(l+2*indent, t, w, h);
        m_btnAlphaEq->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnAlphaEq->setText(VFX_WSTR("ADD"));
        m_btnAlphaEq->setTextFont(VFX_FONT_DESC_SMALL);  
        m_btnAlphaEq->m_signalClicked.connect(this, &AvkV3dRenderState::onBlendEquationChanged);

        t+=h;
        VFX_OBJ_CREATE(m_btnSrcColorFactor, VcpButton, this);
        m_btnSrcColorFactor->setIsDisabled(VFX_TRUE);
        m_btnSrcColorFactor->setRect(l+2*indent, t, w, h);
        m_btnSrcColorFactor->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnSrcColorFactor->setText(VFX_WSTR("As"));
        m_btnSrcColorFactor->setTextFont(VFX_FONT_DESC_SMALL);  
        m_btnSrcColorFactor->m_signalClicked.connect(this, &AvkV3dRenderState::onBlendFuncChanged);

        t+=h;
        VFX_OBJ_CREATE(m_btnDstColorFactor, VcpButton, this);
        m_btnDstColorFactor->setIsDisabled(VFX_TRUE);
        m_btnDstColorFactor->setRect(l+2*indent, t, w, h);
        m_btnDstColorFactor->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnDstColorFactor->setText(VFX_WSTR("1 - As"));
        m_btnDstColorFactor->setTextFont(VFX_FONT_DESC_SMALL); 
        m_btnDstColorFactor->m_signalClicked.connect(this, &AvkV3dRenderState::onBlendFuncChanged);

        t+=h;
        VFX_OBJ_CREATE(m_btnSrcAlphaFactor, VcpButton, this);
        m_btnSrcAlphaFactor->setIsDisabled(VFX_TRUE);
        m_btnSrcAlphaFactor->setRect(l+indent, t, w, h);
        m_btnSrcAlphaFactor->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnSrcAlphaFactor->setText(VFX_WSTR("1"));
        m_btnSrcAlphaFactor->setTextFont(VFX_FONT_DESC_SMALL);
        m_btnSrcAlphaFactor->m_signalClicked.connect(this, &AvkV3dRenderState::onBlendFuncChanged);

        t+=h;
        VFX_OBJ_CREATE(m_btnDstAlphaFactor, VcpButton, this);
        m_btnDstAlphaFactor->setIsDisabled(VFX_TRUE);
        m_btnDstAlphaFactor->setRect(l+indent, t, w, h);
        m_btnDstAlphaFactor->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_btnDstAlphaFactor->setText(VFX_WSTR("1 - As"));
        m_btnDstAlphaFactor->setTextFont(VFX_FONT_DESC_SMALL);
        m_btnDstAlphaFactor->m_signalClicked.connect(this, &AvkV3dRenderState::onBlendFuncChanged);
    }

private:
    
    void onSwitchPolygonMode(VcpSwitch *sw, VfxBool isChecked)
    {
        if (m_pm)
        {
            VFX_OBJ_CLOSE(m_pm);
            m_pass->setPolygonMode(NULL);
            m_btnWinding->setIsDisabled(VFX_TRUE);
            m_btnCulling->setIsDisabled(VFX_TRUE);
        }
        else
        {
            VFX_OBJ_CREATE(m_pm, VfxPolygonMode, m_pass);
            m_pass->setPolygonMode(m_pm);
            m_winding = VFX_WINDING_CCW;
            m_btnWinding->setIsDisabled(VFX_FALSE);
            m_btnWinding->setText(VFX_WSTR("CCW"));
            m_culling = VFX_CULLING_BACK;
            m_btnCulling->setIsDisabled(VFX_FALSE);
            m_btnCulling->setText(VFX_WSTR("BACK"));
        }
    }

    void onWindingChanged(VfxObject* sender, VfxId id)
    {
        if (m_pm)
        {
            m_winding = (VfxWindingMode)((m_winding + 1) % VFX_WINDING_END_OF_ENUM);
            m_pm->setWinding(m_winding);
            switch(m_winding)
            {
            case VFX_WINDING_CCW:
                m_btnWinding->setText(VFX_WSTR("CCW"));
                break;
            case VFX_WINDING_CW:
                m_btnWinding->setText(VFX_WSTR("CW"));
                break;
            default:
                VFX_DEV_ASSERT(0);
            }
        }
    }

    void onCullingChanged(VfxObject* sender, VfxId id)
    {
        if (m_pm)
        {
            m_culling = (VfxCullingMode)((m_culling + 1) % VFX_CULLING_END_OF_ENUM);
            m_pm->setCulling(m_culling);
            switch(m_culling)
            {
            case VFX_CULLING_NONE:
                m_btnCulling->setText(VFX_WSTR("NONE"));
                break;
            case VFX_CULLING_FRONT:
                m_btnCulling->setText(VFX_WSTR("FRONT"));
                break;
            case VFX_CULLING_BACK:
                m_btnCulling->setText(VFX_WSTR("BACK"));
                break;

            default:
                VFX_DEV_ASSERT(0);
            }
        }
    }

    void onSwitchCompositingMode(VcpSwitch *sw, VfxBool isChecked)
    {
        if (m_cm)
        {
            m_btnDepthTest->setChecked(VFX_FALSE);
            m_btnDepthWrite->setChecked(VFX_FALSE);            
            m_btnDepthTest->setIsDisabled(VFX_TRUE);
            m_btnDepthWrite->setIsDisabled(VFX_TRUE);
            m_btnDepthFunc->setIsDisabled(VFX_TRUE);
            m_btnColorMask->setIsDisabled(VFX_TRUE);
            //m_btnStencil->setIsDisabled(VFX_TRUE);
            m_btnBlender->setIsDisabled(VFX_TRUE);
            m_btnBlender->setChecked(VFX_FALSE);


            m_btnColorEq->setIsDisabled(VFX_TRUE);
            m_btnAlphaEq->setIsDisabled(VFX_TRUE);
            m_btnSrcColorFactor->setIsDisabled(VFX_TRUE);
            m_btnDstColorFactor->setIsDisabled(VFX_TRUE);
            m_btnSrcAlphaFactor->setIsDisabled(VFX_TRUE);
            m_btnDstAlphaFactor->setIsDisabled(VFX_TRUE);

            VFX_OBJ_CLOSE(m_blender);
            VFX_OBJ_CLOSE(m_stencil);
            VFX_OBJ_CLOSE(m_cm);
            m_pass->setCompositingMode(NULL);
        }
        else
        {
            VFX_OBJ_CREATE(m_cm, VfxCompositingMode, m_pass);
            m_pass->setCompositingMode(m_cm);
            m_btnDepthTest->setIsDisabled(VFX_FALSE);
            m_btnDepthWrite->setIsDisabled(VFX_FALSE);
            m_btnDepthFunc->setIsDisabled(VFX_FALSE);
            m_btnColorMask->setIsDisabled(VFX_FALSE);
            //m_btnStencil->setIsDisabled(VFX_FALSE);
            m_btnBlender->setIsDisabled(VFX_FALSE);

            m_depthFunc = VFX_DEPTH_FUNC_LESS;
            m_btnDepthTest->setChecked(VFX_TRUE);
            m_btnDepthWrite->setChecked(VFX_TRUE);
            m_colorMask = 0;
            m_btnBlender->setChecked(VFX_FALSE);
        }
    }

    void onSwitchDepthTest(VcpSwitch *sw, VfxBool isChecked)
    {
        if (m_cm)
        {
            m_cm->setDepthTestEnable(!m_cm->isDepthTestEnabled());
        }
    }

    void onSwitchDepthWrite(VcpSwitch *sw, VfxBool isChecked)
    {
        if (m_cm)
        {
            m_cm->setDepthWriteEnable(!m_cm->isDepthWriteEnabled());
        }
    }

    void onDepthFuncChanged(VfxObject* sender, VfxId id)
    {
        if (m_cm)
        {
            m_depthFunc = (VfxDepthFunc)((m_depthFunc + 1) % VFX_DEPTH_FUNC_END_OF_ENUM);
            m_cm->setDepthFunc(m_depthFunc);
            switch(m_depthFunc)
            {
            case VFX_DEPTH_FUNC_NEVER:
                m_btnDepthFunc->setText(VFX_WSTR("NONE"));
                break;
            case VFX_DEPTH_FUNC_ALWAYS:
                m_btnDepthFunc->setText(VFX_WSTR("ALWAYS"));
                break;
            case VFX_DEPTH_FUNC_EQUAL:
                m_btnDepthFunc->setText(VFX_WSTR("EQUAL"));
                break;
            case VFX_DEPTH_FUNC_LESS:
                m_btnDepthFunc->setText(VFX_WSTR("LESS"));
                break;
            case VFX_DEPTH_FUNC_GREATER:
                m_btnDepthFunc->setText(VFX_WSTR("GREATER"));
                break;
            case VFX_DEPTH_FUNC_GEQUAL:
                m_btnDepthFunc->setText(VFX_WSTR("GEQUAL"));
                break;
            case VFX_DEPTH_FUNC_LEQUAL:
                m_btnDepthFunc->setText(VFX_WSTR("LEQUAL"));
                break;
            case VFX_DEPTH_FUNC_NOTEQUAL:
                m_btnDepthFunc->setText(VFX_WSTR("NOTEQUAL"));
                break;
            default:
                VFX_DEV_ASSERT(0);
            }
        }
    }

    void onColorMaskChanged(VfxObject* sender, VfxId id)
    {
        if (m_cm)
        {
            m_colorMask = (m_colorMask + 1) % 4;
            switch(m_colorMask)
            {
            case 0:
                m_cm->setColorWriteMask(0xFFFFFFFF);
                m_btnColorMask->setText(VFX_WSTR("ARGB"));
                break;
            case 1:
                m_cm->setColorWriteMask(0x00FF0000);
                m_btnColorMask->setText(VFX_WSTR("R"));
                break;
            case 2:
                m_cm->setColorWriteMask(0x0000FF00);
                m_btnColorMask->setText(VFX_WSTR("G"));
                break;
            case 3:
                m_cm->setColorWriteMask(0x000000FF);
                m_btnColorMask->setText(VFX_WSTR("B"));
                break;            
            default:
                VFX_DEV_ASSERT(0);
            }
        }
    }

    void onSwitchBlender(VcpSwitch *sw, VfxBool isChecked)
    {
        if (m_cm)
        {
            if (m_blender)
            {
                VFX_OBJ_CLOSE(m_blender);
                m_cm->setBlender(NULL);

                m_btnColorEq->setIsDisabled(VFX_TRUE);
                m_btnAlphaEq->setIsDisabled(VFX_TRUE);
                m_btnSrcColorFactor->setIsDisabled(VFX_TRUE);
                m_btnDstColorFactor->setIsDisabled(VFX_TRUE);
                m_btnSrcAlphaFactor->setIsDisabled(VFX_TRUE);
                m_btnDstAlphaFactor->setIsDisabled(VFX_TRUE);
            }
            else
            {
                VFX_OBJ_CREATE(m_blender, VfxBlender, m_cm);
                m_cm->setBlender(m_blender);

                m_btnColorEq->setIsDisabled(VFX_FALSE);
                m_btnAlphaEq->setIsDisabled(VFX_FALSE);
                m_btnSrcColorFactor->setIsDisabled(VFX_FALSE);
                m_btnDstColorFactor->setIsDisabled(VFX_FALSE);
                m_btnSrcAlphaFactor->setIsDisabled(VFX_FALSE);
                m_btnDstAlphaFactor->setIsDisabled(VFX_FALSE);

                m_colorEquation = VFX_BLEND_EQUATION_ADD;
                m_alphaEquation = VFX_BLEND_EQUATION_ADD;
                m_srcColorFactor = VFX_BLEND_FACTOR_SRC_ALPHA;
                m_dstColorFactor = VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
                m_srcAlphaFactor = VFX_BLEND_FACTOR_ONE;
                m_dstAlphaFactor = VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
            }
        }
    }

    void onBlendEquationChanged(VfxObject* sender, VfxId id)
    {
        if (m_blender)
        {
            VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);
            VfxBlendEquation *eq = NULL;
            if (sender == m_btnColorEq)
            {
                m_colorEquation = (VfxBlendEquation)((m_colorEquation + 1) % VFX_BLEND_EQUATION_END_OF_ENUM);
                eq = &m_colorEquation;
            }
            else
            {
                m_alphaEquation = (VfxBlendEquation)((m_alphaEquation + 1) % VFX_BLEND_EQUATION_END_OF_ENUM);
                eq = &m_alphaEquation;
            }

            switch (*eq)
            {
            case VFX_BLEND_EQUATION_ADD:
                button->setText(VFX_WSTR("ADD"));
                break;
            case VFX_BLEND_EQUATION_SUBTRACT:
                button->setText(VFX_WSTR("SUB"));
                break;
            case VFX_BLEND_EQUATION_REVERSE_SUBTRACT:
                button->setText(VFX_WSTR("REV_SUB"));
                break;
            default:
                VFX_DEV_ASSERT(0);
            }
            
            m_blender->setBlendEquation(m_colorEquation, m_alphaEquation);
        }
    }

    void onBlendFuncChanged(VfxObject* sender, VfxId id)
    {
        if (m_blender)
        {
            VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);
            VfxBlendFactor *factor = NULL;
            if (sender == m_btnSrcColorFactor)
            {
                m_srcColorFactor = (VfxBlendFactor)((m_srcColorFactor + 1) % VFX_BLEND_FACTOR_END_OF_ENUM);                
                factor = &m_srcColorFactor;
            }
            else if (sender == m_btnDstColorFactor)
            {
                m_dstColorFactor = (VfxBlendFactor)((m_dstColorFactor + 1) % VFX_BLEND_FACTOR_SRC_ALPHA_SATURATE);                
                factor = &m_dstColorFactor;
            }
            else if (sender == m_btnSrcAlphaFactor)
            {
                m_srcAlphaFactor = (VfxBlendFactor)((m_srcAlphaFactor + 1) % VFX_BLEND_FACTOR_SRC_ALPHA_SATURATE);                
                factor = &m_srcAlphaFactor;
            }
            else
            {
                m_dstAlphaFactor = (VfxBlendFactor)((m_dstAlphaFactor + 1) % VFX_BLEND_FACTOR_SRC_ALPHA_SATURATE);                
                factor = &m_dstAlphaFactor;
            }

            switch (*factor)
            {
            case VFX_BLEND_FACTOR_ZERO:
                button->setText(VFX_WSTR("0"));
                break;
            case VFX_BLEND_FACTOR_ONE:
                button->setText(VFX_WSTR("1"));
                break;
            case VFX_BLEND_FACTOR_SRC_COLOR:
                button->setText(VFX_WSTR("Cs"));
                break;
            case VFX_BLEND_FACTOR_ONE_MINUS_SRC_COLOR:
                button->setText(VFX_WSTR("1 - Cs"));
                break;
            case VFX_BLEND_FACTOR_DST_COLOR:
                button->setText(VFX_WSTR("Ds"));
                break;
            case VFX_BLEND_FACTOR_ONE_MINUS_DST_COLOR:
                button->setText(VFX_WSTR("1 - Ds"));
                break;
            case VFX_BLEND_FACTOR_SRC_ALPHA:
                button->setText(VFX_WSTR("As"));
                break;
            case VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA:
                button->setText(VFX_WSTR("1 - As"));
                break;
            case VFX_BLEND_FACTOR_DST_ALPHA:
                button->setText(VFX_WSTR("Ad"));
                break;
            case VFX_BLEND_FACTOR_ONE_MINUS_DST_ALPHA:
                button->setText(VFX_WSTR("1 - Ad"));
                break;
            case VFX_BLEND_FACTOR_CONSTANT_COLOR:
                button->setText(VFX_WSTR("C"));
                break;
            case VFX_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR:
                button->setText(VFX_WSTR("1 - C"));
                break;
            case VFX_BLEND_FACTOR_CONSTANT_ALPHA:
                button->setText(VFX_WSTR("A"));
                break;
            case VFX_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA:
                button->setText(VFX_WSTR("1 - A"));
                break;
            case VFX_BLEND_FACTOR_SRC_ALPHA_SATURATE:
                button->setText(VFX_WSTR("As_sat"));
                break; 
            default:
                VFX_DEV_ASSERT(0);
            }
            
            m_blender->setBlendFunc(m_srcColorFactor, m_dstColorFactor, m_srcAlphaFactor, m_dstAlphaFactor);
        }
    }

    void onRotationYChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        m_mesh->setRotationY(newval);
    }

    void onOpacityChange(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        m_mesh->setOpacity(newval);
    }
};




class AvkV3dMultiPass : public AvkV3dBaseScr
{
// Variable
public:
    VfxLight *m_light;
    // Constructor / Destructor
public:
    AvkV3dMultiPass()
    : m_light(NULL)
    {
    }
// Override
public:  
   virtual void startTest(VfxWString wstrCaseName,int item_idx)  
   {
       AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     

        confirm(VFX_WSTR("Multi Pass OK?"));
          // world
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        // camera
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 6), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxSphereMesh *mesh;
        VfxMaterial *material;
        VfxPass *pass;
        VfxShaderProgram *program;
        VfxShaderUniforms *uniforms;
        VfxShaderVariable *var;
        VfxCompositingMode *cm;
        VfxBlender *blender;

        VfxGroup *group;
        VFX_OBJ_CREATE(group, VfxGroup, world);
        VfxKeyframeSequence *kfs;
        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, group, (5, VFX_TYPE_ID_VEC3));
        kfs->setKeyframe(0, 0,    &VfxVector3f(-2, -2, 3));
        kfs->setKeyframe(1, 500,  &VfxVector3f(-2, 2, 3));
        kfs->setKeyframe(2, 1000, &VfxVector3f(2, 2, 3));
        kfs->setKeyframe(3, 1500, &VfxVector3f(2, -2, 3));
        kfs->setKeyframe(4, 2000, &VfxVector3f(-2, -2, 3));
        VfxKeyframeTimeline *kf_tl;
        VFX_OBJ_CREATE(kf_tl, VfxKeyframeTimeline, group);
        kf_tl->setTarget(group);
        kf_tl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        kf_tl->setKeyframeSequence(kfs);
        kf_tl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SPLINE);
        kf_tl->setDuration(2000);
        kf_tl->setAutoReversed(VFX_TRUE);
        kf_tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        kf_tl->start();

        // light
        VFX_OBJ_CREATE(m_light, VfxLight, group);
        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, group, (0.1f));
        

        // multi-pass (2 pass)
        VFX_OBJ_CREATE_EX(material, VfxMaterial, world, (2));

        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(0, pass);

        VfxWChar vs[256];
        VfxWChar fs[256];

        
        

        kal_wstrcpy((WCHAR*)vs,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)vs,(WCHAR*)L"avk_v3d_uiengine\\phong.vs");

      

        kal_wstrcpy((WCHAR*)fs,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)fs,(WCHAR*)L"avk_v3d_uiengine\\phong.fs");


        VFX_OBJ_CREATE_EX(
            program, VfxShaderProgram, pass,
            (VFX_WSTR_DYNAMIC(vs), VFX_WSTR_DYNAMIC(fs)));
        pass->setShaderProgram(program);

        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, material);
        pass->addShaderUniforms(uniforms);
        uniforms->addUniformVariable(VFX_STR("u_LightPos"), VFX_TYPE_ID_VEC3, 1)->bindValue(m_light, VFX_BINDING_CAMERA_SPACE_POSITION);
        uniforms->addUniformVariable(VFX_STR("u_LightColor"), VFX_TYPE_ID_VEC4, 1)->bindValue(m_light, VFX_BINDING_LIGHT_COLOR);
        uniforms->addUniformVariable(VFX_STR("u_LightIntensity"), VFX_TYPE_ID_FLOAT, 1)->bindValue(m_light, VFX_BINDING_LIGHT_INTENSITY);


        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(1, pass);


        kal_wstrcpy((WCHAR*)vs,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)vs,(WCHAR*)L"avk_v3d_uiengine\\planar_shadow.vs");

      

        kal_wstrcpy((WCHAR*)fs,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)fs,(WCHAR*)L"avk_v3d_uiengine\\planar_shadow.fs");


        VFX_OBJ_CREATE_EX(
            program, VfxShaderProgram, pass,
            (VFX_WSTR_DYNAMIC(vs), VFX_WSTR_DYNAMIC(fs)));
        pass->setShaderProgram(program);

        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, material);
        pass->addShaderUniforms(uniforms);
        var = uniforms->addUniformVariable(VFX_STR("u_LightPos"), VFX_TYPE_ID_VEC3, 1);
        var->bindValue(m_light, VFX_BINDING_WORLD_SPACE_POSITION);

        VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
        pass->setCompositingMode(cm);

        VFX_OBJ_CREATE(blender, VfxBlender, cm);
        cm->setBlender(blender);

        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (0.5f));
        mesh->setTranslation(-1, 1, 0.5f);
        mesh->setMaterial(0, material);

        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (0.5f));
        mesh->setTranslation(1, 1, 0.5f);
        mesh->setMaterial(0, material);

        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (0.5f));
        mesh->setTranslation(-1, -1, 0.5f);
        mesh->setMaterial(0, material);

        VFX_OBJ_CREATE_EX(mesh, VfxSphereMesh, world, (0.5f));
        mesh->setTranslation(1, -1, 0.5f);
        mesh->setMaterial(0, material);
    }
};




class AvkV3dRenderTarget : public AvkV3dBaseScr
{
// Variable
public:
    // Constructor / Destructor
public:
    AvkV3dRenderTarget()
    {
    }

// Override
public:  
   virtual void startTest(VfxWString wstrCaseName,int item_idx)  
   {
       AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     

        confirm(VFX_WSTR("Render Target OK?"));
           // world
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        // camera
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 3), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxBoxMesh *mesh;
        VfxMaterial *material;
        VfxPass *pass;
        VfxRenderTarget *rt;
        VfxImage2D *rb;
        VfxTexture *tex;
        VfxShaderProgram *program;
        VfxShaderUniforms *uniforms;

        // draw in render target
        VFX_OBJ_CREATE_EX(mesh, VfxBoxMesh, world, (2.0f));

        VfxKeyframeSequence *kfs;
        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (4, VFX_TYPE_ID_QUAT));
        kfs->setKeyframe(0, 0,    &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));
        kfs->setKeyframe(1, 6667,  &VfxQuaternionf(VfxVector3f(0, vfxSin(2 * VFX_PI / 3), 0), vfxCos(2 * VFX_PI / 3)));
        kfs->setKeyframe(2, 13333, &VfxQuaternionf(VfxVector3f(0, vfxSin(4 * VFX_PI / 3), 0), vfxCos(4 * VFX_PI / 3)));
        kfs->setKeyframe(3, 20000, &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));

        VfxKeyframeTimeline *qtl;
        VFX_OBJ_CREATE(qtl, VfxKeyframeTimeline, mesh);
        qtl->setTarget(mesh);
        qtl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
        qtl->setKeyframeSequence(kfs);
        qtl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SLERP);
        qtl->setDuration(20000);
        qtl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        qtl->start();

        VFX_OBJ_CREATE_EX(material, VfxMaterial, mesh, (2));
        mesh->setMaterial(0, material);

        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(0, pass);

        VFX_OBJ_CREATE(rt, VfxRenderTarget, pass);
        pass->setRenderTarget(rt);

        VFX_OBJ_CREATE_EX(rb, VfxImage2D, rt, (getSize().width / 4, getSize().height / 4, VRT_COLOR_TYPE_RGB565));
        rt->attachColorBuffer(rb);
        rt->enableClearColor(VFX_TRUE);
        rt->setClearColor(VFX_COLOR_GREY);

        // use render target as texture
        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(1, pass);

        VFX_OBJ_CREATE_EX(tex, VfxTexture2D, pass, (rb));

        static const vrt_char fs[] =
        "precision mediump float;           \n"
        "varying vec2 vTexCoord;            \n"
        "uniform sampler2D u_RenderTexture; \n"
        "void main()                        \n"
        "{                                  \n"
        "   gl_FragColor = texture2D(u_RenderTexture, vTexCoord); \n"
        "}                                  \n";
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (NULL, fs));
        pass->setShaderProgram(program);

        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);
        VfxShaderVariable *var = uniforms->addUniformVariable(VFX_STR("u_RenderTexture"), VFX_TYPE_ID_SAMPLER, 1);
        var->setValue(tex);
    }
};


/*
class AvkV3dPostProcessing : public AvkV3dBaseScr
{
// Variable
public:
    // Constructor / Destructor
public:
    AvkV3dPostProcessing()
    {
    }

    
// Override
public:  
   virtual void startTest(VfxWString wstrCaseName,int item_idx)  
   {
       AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     

        confirm(VFX_WSTR("Post Processing OK?"));
        
           // world
        VfxWorld *world;
        VFX_OBJ_CREATE(world, VfxWorld, this);
        setWorld(world);

        // camera
        VfxCamera *camera;
        VFX_OBJ_CREATE(camera, VfxCamera, world);
        world->setActiveCamera(camera);
        camera->setPerspective(
            VRT_PI_2,
            (vrt_float)getSize().width / (vrt_float)getSize().height,
            1.0f, 1000.0f);
        camera->setLookAt(VrtVector3f(0, 0, 60), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));

        VfxMesh *mesh;
        VFX_OBJ_CREATE(mesh, VfxMesh, world);

        VfxWChar fn[256];

        kal_wstrcpy((WCHAR*)fn,(WCHAR*)AVK_TEST_FILE_PATH);
           kal_wstrcat((WCHAR*)fn,(WCHAR*)L"avk_v3d_uiengine\\vtst_teapot000.msh");


        VfxAssetLoader::loadMesh(mesh, VFX_WSTR_DYNAMIC(fn));

        VfxKeyframeSequence *kfs;
        VFX_OBJ_CREATE_EX(kfs, VfxKeyframeSequence, mesh, (4, VFX_TYPE_ID_QUAT, VFX_INTERPOLATE_FUNC_ID_SLERP));
        kfs->setKeyframe(0, 0,    &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));
        kfs->setKeyframe(1, 6667,  &VfxQuaternionf(VfxVector3f(0, vfxSin(2 * VFX_PI / 3), 0), vfxCos(2 * VFX_PI / 3)));
        kfs->setKeyframe(2, 13333, &VfxQuaternionf(VfxVector3f(0, vfxSin(4 * VFX_PI / 3), 0), vfxCos(4 * VFX_PI / 3)));
        kfs->setKeyframe(3, 20000, &VfxQuaternionf(VfxVector3f(0, 0, 0), 1));

        VfxKeyframeTimeline *qtl;
        VFX_OBJ_CREATE(qtl, VfxKeyframeTimeline, mesh);
        qtl->setTarget(mesh);
        qtl->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
        qtl->setKeyframeSequence(kfs);
        qtl->setKeyframeInterpolation(VFX_INTERPOLATE_FUNC_ID_SLERP);
        qtl->setDuration(20000);
        qtl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        qtl->start();

        VfxMaterial *material;
        VFX_OBJ_CREATE_EX(material, VfxMaterial, mesh, (5));
        mesh->setMaterial(0, material);

        VfxPass *pass;
        VfxShaderProgram *program;
        VfxShaderUniforms *uniforms;
        VfxImage2D *image;
        VFX_OBJ_CREATE_EX(image, VfxImage2D, material, (getSize().width / 2, getSize().height / 2, VRT_COLOR_TYPE_RGB565));

        VfxImage2D *image2;
        VFX_OBJ_CREATE_EX(image2, VfxImage2D, material, (getSize().width / 2, getSize().height / 2, VRT_COLOR_TYPE_RGB565));


        VfxTexture2D *tex;
//        VFX_OBJ_CREATE_EX(tex, VfxTexture2D, material, (image));

        // Pass 1: Model Pass
        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(0, pass);

        // Pass 2: Create Glow Map
        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(1, pass);

        VfxRenderTarget *rt1;
        VFX_OBJ_CREATE_EX(rt1, VfxRenderTarget, pass, (image));
        rt1->setClearColor(0xFF000000);
        rt1->enableClearColor(VFX_TRUE);
        pass->setRenderTarget(rt1);

        // Pass 3: Horizontal Blur
        VFX_OBJ_CREATE_EX(pass, VfxPass, material, (VFX_PASS_GEOMETRY_VIEWPORT));
        material->setPass(2, pass);

        VfxRenderTarget *rt2;
        VFX_OBJ_CREATE_EX(rt2, VfxRenderTarget, pass, (image2));
        pass->setRenderTarget(rt2);

        static const vrt_char h_gaussian_blur[] =  
        "precision mediump float;                     \n"
        "varying vec2 vTexCoord;                      \n"
        "uniform sampler2D glow_map;                  \n"
        "uniform ivec2 v3d_BaseTexSize;               \n"
        "void main()                                  \n"
        "{                                            \n"
        "   float blurSize = 1.0 / 100.0;   \n"
        "   gl_FragColor = texture2D(glow_map, vec2(vTexCoord.x - 4.0*blurSize, vTexCoord.y)) * 0.05;  \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x - 3.0*blurSize, vTexCoord.y)) * 0.09; \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x - 2.0*blurSize, vTexCoord.y)) * 0.12; \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x - blurSize, vTexCoord.y)) * 0.15;     \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x, vTexCoord.y)) * 0.16;                \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x + blurSize, vTexCoord.y)) * 0.15;     \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x + 2.0*blurSize, vTexCoord.y)) * 0.12; \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x + 3.0*blurSize, vTexCoord.y)) * 0.09; \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x + 4.0*blurSize, vTexCoord.y)) * 0.05; \n"
        "}                                            \n";

        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (NULL, h_gaussian_blur));
        pass->setShaderProgram(program);

        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);

        VFX_OBJ_CREATE_EX(tex, VfxTexture2D, uniforms, (image));
        uniforms->addUniformVariable(VFX_STR("glow_map"), VFX_TYPE_ID_SAMPLER, 1)->setValue(tex);

        // Pass 4: Vertical Blur
        VFX_OBJ_CREATE_EX(pass, VfxPass, material, (VFX_PASS_GEOMETRY_VIEWPORT));
        material->setPass(3, pass);
        pass->setRenderTarget(rt1);

        static const vrt_char v_gaussian_blur[] =  
        "precision mediump float;                     \n"
        "varying vec2 vTexCoord;                      \n"
        "uniform sampler2D glow_map;                  \n"
        "uniform ivec2 v3d_BaseTexSize;               \n"
        "void main()                                  \n"
        "{                                            \n"
        "   float blurSize = 1.0 / 100.0;   \n"
        "   gl_FragColor = texture2D(glow_map, vec2(vTexCoord.x, vTexCoord.y - 4.0*blurSize)) * 0.05;  \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x, vTexCoord.y - 3.0*blurSize)) * 0.09; \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x, vTexCoord.y - 2.0*blurSize)) * 0.12; \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x, vTexCoord.y - blurSize)) * 0.15;     \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x, vTexCoord.y)) * 0.16;                \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x, vTexCoord.y + blurSize)) * 0.15;     \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x, vTexCoord.y + 2.0*blurSize)) * 0.12; \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x, vTexCoord.y + 3.0*blurSize)) * 0.09; \n"
        "   gl_FragColor += texture2D(glow_map, vec2(vTexCoord.x, vTexCoord.y + 4.0*blurSize)) * 0.05; \n"
        "}     \n";

        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (NULL, v_gaussian_blur));
        pass->setShaderProgram(program);

        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);

        VFX_OBJ_CREATE_EX(tex, VfxTexture2D, uniforms, (image2));
        uniforms->addUniformVariable(VFX_STR("glow_map"), VFX_TYPE_ID_SAMPLER, 1)->setValue(tex);


        // Pass 5: Add glow
        VFX_OBJ_CREATE_EX(pass, VfxPass, material, (VFX_PASS_GEOMETRY_VIEWPORT));
        material->setPass(4, pass);

        static const vrt_char glow_shader[] =  
        "precision mediump float;                     \n"
        "varying vec2 vTexCoord;                      \n"
        "uniform sampler2D glow_map;                  \n"
        "void main()                                  \n"
        "{                                            \n"
        "   gl_FragColor = texture2D(glow_map, vTexCoord);  \n"
        "}     \n";

        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (NULL, glow_shader));
        pass->setShaderProgram(program);

        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);

        VFX_OBJ_CREATE_EX(tex, VfxTexture2D, uniforms, (image));
        uniforms->addUniformVariable(VFX_STR("glow_map"), VFX_TYPE_ID_SAMPLER, 1)->setValue(tex);

        VfxCompositingMode *cm;
        VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
        pass->setCompositingMode(cm);
        cm->setDepthTestEnable(VFX_FALSE);
        cm->setDepthWriteEnable(VFX_FALSE);

        VfxBlender *blender;
        VFX_OBJ_CREATE(blender, VfxBlender, cm);
        cm->setBlender(blender);
        blender->setBlendFunc(VFX_BLEND_FACTOR_ONE, VFX_BLEND_FACTOR_ONE, VFX_BLEND_FACTOR_ZERO, VFX_BLEND_FACTOR_ONE);

        
    }
};

*/





class AvkV3dFrameMaterialE04 : public AvkV3dBaseScr
{
// Variable
public:
    // Constructor / Destructor
    VfxFrame *m_frame;
public:
    AvkV3dFrameMaterialE04()
    : m_frame(NULL)
    {
    }

// Override
public:  
   virtual void startTest(VfxWString wstrCaseName,int item_idx)  
   {
       AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
       confirm(VFX_WSTR("Viewport Rendering OK?"));


        VfxWChar fs[256];
        VfxS32 w = getSize().width;
        VfxS32 h = getSize().height;

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setRect(w/4, h/4, w/2, h/2);
        m_frame->sendToBack();

        VfxFloatTimeline *tl;
        VFX_OBJ_CREATE(tl, VfxFloatTimeline, m_frame);
        tl->setTarget(m_frame);
        tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FPE_USER_0);
        tl->setDurationTime(2000);
        tl->setAutoReversed(VFX_TRUE);
        tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        tl->setFromValue(0.0f);
        tl->setToValue(1.0f);
        tl->start();
        VFX_OBJ_CREATE(tl, VfxFloatTimeline, m_frame);
        tl->setTarget(m_frame);
        tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Z);
        tl->setDurationTime(2000);
        tl->setAutoReversed(VFX_TRUE);
        tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        tl->setFromValue(0.0f);
        tl->setToValue(1.0f);
        tl->start();

        w /= 2;
        h /= 2;
        VfxFrame *frame;
        VFX_OBJ_CREATE(frame, VfxFrame, m_frame);
        frame->setRect(0, 0, w, h);

        h /= 4;
        VcpButton *button;
        VFX_OBJ_CREATE(button, VcpButton, frame);
        button->setRect(0, 0, w, h);
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->setText(VFX_WSTR("Button 1"));

        VFX_OBJ_CREATE(button, VcpButton, frame);
        button->setRect(0, h, w, h);
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->setText(VFX_WSTR("Button 2"));

        VFX_OBJ_CREATE(button, VcpButton, frame);
        button->setRect(0, h*2, w, h);
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->setText(VFX_WSTR("Button 3"));

        VFX_OBJ_CREATE(button, VcpButton, frame);
        button->setRect(0, h*3, w, h);
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->setText(VFX_WSTR("Button 4"));

        VfxMaterial *material;
        VfxPass *pass;
        VfxShaderProgram *program;
        VfxShaderUniforms *uniforms;
        VfxImage2D *image;
        VfxRenderTarget *rt;
        VfxTexture2D *tex;

        // Material (2 pass rendering)
        VFX_OBJ_CREATE_EX(material, VfxMaterial, m_frame, (2));
        m_frame->setMaterial(material);

        // Pass
        VFX_OBJ_CREATE_EX(pass, VfxPass, material, (VFX_PASS_GEOMETRY_VIEWPORT));
        material->setPass(0, pass);

        // Shader Program                
        kal_wstrcpy((WCHAR*)fs,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)fs,(WCHAR*)L"avk_v3d_uiengine\\gaussian_blur_h.fs");
        

        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR_NULL, VFX_WSTR_DYNAMIC(fs)));
        pass->setShaderProgram(program);

        // Render Buffer
        VFX_OBJ_CREATE_EX(image, VfxImage2D, pass, (getSize().width/2, getSize().height/2, VRT_COLOR_TYPE_RGB565));

        // Render Target
        VFX_OBJ_CREATE_EX(rt, VfxRenderTarget, pass, (image));
        rt->enableClearColor(VFX_TRUE);
        pass->setRenderTarget(rt);

        // Pass2
        VFX_OBJ_CREATE(pass, VfxPass, material);

        // Shader Program
        kal_wstrcpy((WCHAR*)fs,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)fs,(WCHAR*)L"avk_v3d_uiengine\\gaussian_blur_v.fs");
        

        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR_NULL, VFX_WSTR_DYNAMIC(fs)));
        pass->setShaderProgram(program);
        
        // Shader Uniforms
        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);

        // Texture    
        VFX_OBJ_CREATE_EX(tex, VfxTexture2D, uniforms, (image));
        uniforms->addUniformVariable(VFX_STR("baseTex"), VFX_TYPE_ID_SAMPLER, 1)->setValue(tex);

        material->setPass(1, pass);
   }
};



            
class AvkV3dFrameMaterialE05 : public AvkV3dBaseScr
{
// Variable
public:
    // Constructor / Destructor
    VfxFrame *m_frame;
public:
    AvkV3dFrameMaterialE05()
    : m_frame(NULL)
    {
    }

// Override
public:  
   virtual void startTest(VfxWString wstrCaseName,int item_idx)  
   {
       AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
       confirm(VFX_WSTR("Globe Effect OK?"));
       setBgColor(VFX_COLOR_BLACK);

        VfxWChar vs[256];
        VfxWChar fs[256];
        VfxS32 w = getSize().width;
        VfxS32 h = getSize().height;

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setRect(0, 0, w, h);
        m_frame->setBgColor(VFX_COLOR_WHITE);
        m_frame->sendToBack();

        VfxMaterial *material;
        VfxPass *pass;
        VfxShaderProgram *program;

        // Material
        VFX_OBJ_CREATE(material, VfxMaterial, m_frame);
        m_frame->setMaterial(material);

        // Pass
        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(0, pass);


        kal_wstrcpy((WCHAR*)vs,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)vs,(WCHAR*)L"avk_v3d_uiengine\\globe.vert");
         

        kal_wstrcpy((WCHAR*)fs,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)fs,(WCHAR*)L"avk_v3d_uiengine\\globe.frag");
         

        
        VFX_OBJ_CREATE_EX(
            program, VfxShaderProgram, pass,
            (VFX_WSTR_DYNAMIC(vs), VFX_WSTR_DYNAMIC(fs)));
        pass->setShaderProgram(program);


        VfxShaderUniforms *uniforms;
        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);

        VfxShaderVariable *var;

        VfxMatrix4f proj;
        proj.setPerspective(0.6f, (VfxFloat)w / (VfxFloat)h, 0.1f, 10.0f );
        var = uniforms->addUniformVariable(VFX_STR("u_invProjection"), VFX_TYPE_ID_MAT4, 1);
        var->setValue(inverse(proj));

        VfxVector3f earthCentre( 0, -0.25f, -5 );
        var = uniforms->addUniformVariable(VFX_STR("u_centre"), VFX_TYPE_ID_VEC3, 1);
        var->setValue((void *)&earthCentre);

        var = uniforms->addUniformVariable(VFX_STR("u_centre_sqr"), VFX_TYPE_ID_FLOAT, 1);
        var->setValue(dot(earthCentre, earthCentre));

        var = uniforms->addUniformVariable(VFX_STR("u_lightAngle"), VFX_TYPE_ID_FLOAT, 1);
        VfxFloatTimeline *tl;
        VFX_OBJ_CREATE(tl, VfxFloatTimeline, var);
        tl->setTarget(var);
        tl->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_FLOAT);
        tl->setDurationTime(10000);
        tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        tl->setFromValue(0.0f);
        tl->setToValue(VFX_PI * 2);
        tl->start();



        var = uniforms->addUniformVariable(VFX_STR("u_rot"), VFX_TYPE_ID_FLOAT, 1);
        VFX_OBJ_CREATE(tl, VfxFloatTimeline, var);
        tl->setTarget(var);
        tl->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_FLOAT);
        tl->setDurationTime(10000);
        tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        tl->setFromValue(0.0f);
        tl->setToValue(1.0f);
        tl->start();

        VfxImage2D *img;
        VfxTexture2D *tex;


        kal_wstrcpy((WCHAR*)vs,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)vs,(WCHAR*)L"avk_v3d_uiengine\\day.jpg");
         

        var = uniforms->addUniformVariable(VFX_STR("u_texture"), VFX_TYPE_ID_SAMPLER, 1);        
        VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (VFX_WSTR_DYNAMIC(vs)));
        VFX_OBJ_CREATE_EX(tex, VfxTexture2D, var, (img));
        tex->setWrapping(VFX_TEXTURE_WRAP_REPEAT, VFX_TEXTURE_WRAP_REPEAT);
        var->setValue(tex);


        
        kal_wstrcpy((WCHAR*)vs,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)vs,(WCHAR*)L"avk_v3d_uiengine\\night.jpg");                

        var = uniforms->addUniformVariable(VFX_STR("u_night"), VFX_TYPE_ID_SAMPLER, 1);         
        VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (VFX_WSTR_DYNAMIC(vs)));
        VFX_OBJ_CREATE_EX(tex, VfxTexture2D, var, (img));
        tex->setWrapping(VFX_TEXTURE_WRAP_REPEAT, VFX_TEXTURE_WRAP_REPEAT);
        var->setValue(tex);

        kal_wstrcpy((WCHAR*)vs,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)vs,(WCHAR*)L"avk_v3d_uiengine\\gloss.jpg");          
        var = uniforms->addUniformVariable(VFX_STR("u_gloss"), VFX_TYPE_ID_SAMPLER, 1);
        VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (VFX_WSTR_DYNAMIC(vs)));
        VFX_OBJ_CREATE_EX(tex, VfxTexture2D, var, (img));
        tex->setWrapping(VFX_TEXTURE_WRAP_REPEAT, VFX_TEXTURE_WRAP_REPEAT);
        var->setValue(tex);
    }
};

class AvkV3dFrameMaterialE06 : public AvkV3dBaseScr
{
// Variable
public:
  // Constructor / Destructor
  VfxFrame *m_frame;
public:
  AvkV3dFrameMaterialE06()
  : m_frame(NULL)
  {
  }

// Override
public:  
     virtual void startTest(VfxWString wstrCaseName,int item_idx)  
     {
         AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
         confirm(VFX_WSTR("Tessellation OK?"));

          VfxWChar vs[256];
          VfxWChar fs[256];
          VfxS32 w = getSize().width;
          VfxS32 h = getSize().height;

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        m_frame->setRect(0, 0, w, h);
        m_frame->setBgColor(VFX_COLOR_WHITE);
        m_frame->sendToBack();

        h /= 4;
        VcpButton *button;
        VFX_OBJ_CREATE(button, VcpButton, m_frame);
        button->setRect(0, 0, w, h);
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->setText(VFX_WSTR("Button 1"));

        VFX_OBJ_CREATE(button, VcpButton, m_frame);
        button->setRect(0, h, w, h);
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->setText(VFX_WSTR("Button 2"));

        VFX_OBJ_CREATE(button, VcpButton, m_frame);
        button->setRect(0, h*2, w, h);
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->setText(VFX_WSTR("Button 3"));

        VFX_OBJ_CREATE(button, VcpButton, m_frame);
        button->setRect(0, h*3, w, h);
        button->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        button->setText(VFX_WSTR("Button 4"));

        VfxMaterial *material;
        VfxPass *pass;
        VfxShaderProgram *program;

        // Material
        VFX_OBJ_CREATE(material, VfxMaterial, m_frame);
        m_frame->setMaterial(material);
        m_frame->setHints(VFX_FRAME_HINTS_DEPTH_TEST);

        // Pass
        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(0, pass);
        pass->setTessellationLevel(20, 20);

        // Shader Program
        
        kal_wstrcpy((WCHAR*)vs,(WCHAR*)AVK_TEST_FILE_PATH);
         kal_wstrcat((WCHAR*)vs,(WCHAR*)L"avk_v3d_uiengine\\pagecurl.vs");
      kal_wstrcpy((WCHAR*)fs,(WCHAR*)AVK_TEST_FILE_PATH);
         kal_wstrcat((WCHAR*)fs,(WCHAR*)L"avk_v3d_uiengine\\pagecurl.fs");       
        VFX_OBJ_CREATE_EX(
            program, VfxShaderProgram, pass,
            (VFX_WSTR_DYNAMIC(vs), VFX_WSTR_DYNAMIC(fs)));
        pass->setShaderProgram(program);

        VfxCompositingMode *cm;
        VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
        pass->setCompositingMode(cm);
        cm->setDepthTestEnable(VFX_TRUE);
        cm->setDepthWriteEnable(VFX_TRUE);

        VfxShaderUniforms *uniforms;
        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);

        VfxShaderVariable *var;
        VcpSlider *slider;
        h = getSize().height / 15;
        VfxS32 t = h;



        var = uniforms->addUniformVariable(VFX_STR("A"), VFX_TYPE_ID_FLOAT, 1);
        var->setValue(-m_frame->getSize().height / 4.0f);


        VfxTextFrame *text;
        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setString(VFX_WSTR("A    "));
        text->setFont(VFX_FONT_DESC_SMALL);  
        
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setAttachProperty(0x10000001, &var, sizeof(VfxShaderVariable *));
        slider->setPos(getSize().width / 5, t);
        slider->setLength(getSize().width * 4/5);
        slider->setMaxValue(m_frame->getSize().height * 4.0f);
        slider->setMinValue(-m_frame->getSize().height * 4.0f);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &AvkV3dFrameMaterialE06::onAChanged);



        

        t += h;
        var = uniforms->addUniformVariable(VFX_STR("theta"), VFX_TYPE_ID_FLOAT, 1);
        var->setValue(1.0f);

        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setString(VFX_WSTR("theta"));
        text->setFont(VFX_FONT_DESC_SMALL); 
        
        VFX_OBJ_CREATE(slider, VcpSlider, this);                
        slider->setAttachProperty(0x10000002, &var, sizeof(VfxShaderVariable *));
        slider->setPos(getSize().width / 5, t);
        slider->setLength(getSize().width * 4/5);
        slider->setMaxValue(VFX_PI / 2.0f);
        slider->setMinValue(0.0f);
        slider->setCurrentValue(1);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &AvkV3dFrameMaterialE06::onThetaChanged);

        t += h;
        var = uniforms->addUniformVariable(VFX_STR("rho"), VFX_TYPE_ID_FLOAT, 1);
        var->setValue(0.0f);

        VFX_OBJ_CREATE(text, VfxTextFrame, this);
        text->setPos(0, t);
        text->setString(VFX_WSTR("rho  "));
        text->setFont(VFX_FONT_DESC_SMALL); 
        
        VFX_OBJ_CREATE(slider, VcpSlider, this);
        slider->setAttachProperty(0x10000003, &var, sizeof(VfxShaderVariable *));
        slider->setPos(getSize().width / 5, t);
        slider->setLength(getSize().width * 4/5);
        slider->setMaxValue(VFX_PI / 2.0f);
        slider->setMinValue(0.0f);
        slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_CONTINUOUS);
        slider->m_signalUserChangedValue.connect(this, &AvkV3dFrameMaterialE06::onRhoChanged);
     }
private:
    void onAChanged(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        VcpSlider *slider = VFX_OBJ_DYNAMIC_CAST(sender->getParent(), VcpSlider);
        VfxShaderVariable *var = *(VfxShaderVariable **)slider->getAttachProperty(0x10000001, sizeof(VfxShaderVariable *));
        var->setValue(newval);
    }

    void onThetaChanged(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        VcpSlider *slider = VFX_OBJ_DYNAMIC_CAST(sender->getParent(), VcpSlider);
        VfxShaderVariable *var = *(VfxShaderVariable **)slider->getAttachProperty(0x10000002, sizeof(VfxShaderVariable *));
        var->setValue(newval);
    }

    void onRhoChanged(VfxObject *sender, VfxFloat oldval, VfxFloat newval)
    {
        VcpSlider *slider = VFX_OBJ_DYNAMIC_CAST(sender->getParent(), VcpSlider);
        VfxShaderVariable *var = *(VfxShaderVariable **)slider->getAttachProperty(0x10000003, sizeof(VfxShaderVariable *));
        var->setValue(newval);
    }
};




class AvkV3dBuiltinUniforms : public AvkV3dBaseScr
{
// Variable
public:
    VfxFrame *m_frame;
    
    // Constructor / Destructor
public:
    AvkV3dBuiltinUniforms()
    : m_frame(NULL)
    {
    }

// Override
public:  
     virtual void startTest(VfxWString wstrCaseName,int item_idx)  
     {
         AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
         confirm(VFX_WSTR("Builtin Uniforms OK?"));

        VfxWChar vs[256];
        VfxWChar fs[256];  
       

      // test draw in screen space
        VfxFrame *frame;
        VFX_OBJ_CREATE(frame, VfxFrame, this);
        m_frame = frame;
        frame->setAnchor(0.5f, 0.5f);
        frame->setPos(100, 100);
        frame->setSize(140, 140);
        frame->setBgColor(VFX_COLOR_RED);            

        VfxFloatTimeline *tl;
        VFX_OBJ_CREATE(tl, VfxFloatTimeline, frame);
        tl->setTarget(frame);
        tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Z);
        tl->setDurationTime(2000);
        tl->setAutoReversed(VFX_TRUE);
        tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        tl->setFromValue(0.0f);
        tl->setToValue(1.0f);
        tl->start();

        VfxMaterial *mtl;
        VFX_OBJ_CREATE(mtl, VfxMaterial, frame);
        frame->setMaterial(mtl);

        VfxPass *pass;
        VFX_OBJ_CREATE(pass, VfxPass, mtl);
        mtl->setPass(0, pass);

        kal_wstrcpy((WCHAR*)vs,(WCHAR*)AVK_TEST_FILE_PATH);
         kal_wstrcat((WCHAR*)vs,(WCHAR*)L"avk_v3d_uiengine\\frame.vs");
         kal_wstrcpy((WCHAR*)fs,(WCHAR*)AVK_TEST_FILE_PATH);
         kal_wstrcat((WCHAR*)fs,(WCHAR*)L"avk_v3d_uiengine\\frame.fs");

        VfxShaderProgram *program;
        VFX_OBJ_CREATE_EX(
            program,
            VfxShaderProgram,
            pass,
            (VFX_WSTR_DYNAMIC(vs),
             VFX_WSTR_DYNAMIC(fs)));

        pass->setShaderProgram(program);
   
    
        // test draw in temp buffer space
        VfxFrame *parent;
        VFX_OBJ_CREATE(parent, VfxFrame, this);
        parent->setBgColor(VFX_COLOR_RED);
        parent->setOpacity(0.5f);
        parent->setRect(0, 200, 200, 200);

        VFX_OBJ_CREATE(frame, VfxFrame, parent);
        frame->setAnchor(0.5f, 0.5f);
        frame->setPos(100, 100);
        frame->setSize(140, 140);
        frame->setBgColor(VFX_COLOR_YELLOW);

        VFX_OBJ_CREATE(tl, VfxFloatTimeline, frame);
        tl->setTarget(frame);
        tl->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Z);
        tl->setDurationTime(2000);
        tl->setAutoReversed(VFX_TRUE);
        tl->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
        tl->setFromValue(0.0f);
        tl->setToValue(1.0f);
        tl->start();

        VFX_OBJ_CREATE(mtl, VfxMaterial, frame);
        frame->setMaterial(mtl);

        VFX_OBJ_CREATE(pass, VfxPass, mtl);
        mtl->setPass(0, pass);

        VFX_OBJ_CREATE_EX(
            program,
            VfxShaderProgram,
            pass,
            (VFX_WSTR_DYNAMIC(vs),
             VFX_WSTR_DYNAMIC(fs)));
        
        pass->setShaderProgram(program);
    }

protected:
    virtual VfxBool onPenInput(VfxPenEvent &event)
    {
        VfxBool ret = AvkV3dBaseScr::onPenInput(event);

        if(ret == VFX_FALSE)
        {
            switch (event.type)
            {
            case VFX_PEN_EVENT_TYPE_DOWN:
                m_frame->setPos(event.downPos);
                break;
            }
        }
        
        
        // do nothing
        return ret;
    }
};




class AvkV3dColorFrameMaterial : public AvkV3dBaseScr
{
// Variable
public:
    VfxFrame *m_frame;
    
    // Constructor / Destructor
public:
    AvkV3dColorFrameMaterial()
    : m_frame(NULL)
    {
    }

    // Override
public:  
     virtual void startTest(VfxWString wstrCaseName,int item_idx)  
     {
         AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
         confirm(VFX_WSTR("Color frame material OK?"));

        VfxWChar fs[256];
        VfxFrame *frame;
        VFX_OBJ_CREATE(frame, VfxFrame, this);
        m_frame = frame;
        frame->setPos(getSize().width / 4 , getSize().height / 4);
        frame->setSize(getSize().width / 2 , getSize().height / 2);
        frame->setBgColor(VRT_COLOR_RED);

        VfxMaterial *mtl;
        VFX_OBJ_CREATE(mtl, VfxMaterial, frame);
        frame->setMaterial(mtl);

        VfxPass *pass;
        VFX_OBJ_CREATE(pass, VfxPass, mtl);
        mtl->setPass(0, pass);

        kal_wstrcpy((WCHAR*)fs,(WCHAR*)AVK_TEST_FILE_PATH);
        kal_wstrcat((WCHAR*)fs,(WCHAR*)L"avk_v3d_uiengine\\color_frame.fs");


        VfxShaderProgram *program;
        VFX_OBJ_CREATE_EX(
            program,
            VfxShaderProgram,
            pass,
            (VFX_WSTR_NULL,
             VFX_WSTR_DYNAMIC(fs)));

        pass->setShaderProgram(program);
    }
};




typedef struct
{
   // Handle to a program object
   GLuint programObject;

} UserData;

///
// Create a shader object, load the shader source, and
// compile the shader.
//
GLuint AvkV3dloadShader ( GLenum type, const char *shaderSrc )
{
   GLuint shader;
   GLint compiled;
   
   // Create the shader object
   shader = glCreateShader ( type );

   if ( shader == 0 )
   	return 0;

   // Load the shader source
   glShaderSource ( shader, 1, &shaderSrc, NULL );
   
   // Compile the shader
   glCompileShader ( shader );

   // Check the compile status
   glGetShaderiv ( shader, GL_COMPILE_STATUS, &compiled );

   if ( !compiled ) 
   {
      glDeleteShader ( shader );
      return 0;
   }

   return shader;

}


class MyGLESOwenerDraw : public VfxOwnerDraw
{
public:
    MyGLESOwenerDraw()
    {
        m_data.programObject = 0;
    }

protected:
    
    virtual vrt_bool isUsingGLAPI() const { return VFX_TRUE; }
        
    virtual void onInitResource()
    {
        UserData *userData = &m_data;
        const char vShaderStr[] =  
        "attribute vec4 vPosition;    \n"
        "attribute vec4 aColor;       \n"
        "varying vec4 vColor;       \n"
        "void main()                  \n"
        "{                            \n"
        "   vColor = aColor;  \n"
        "   gl_Position = vPosition;  \n"
        "}                            \n";

        const char fShaderStr[] =  
        "precision mediump float;\n"\
        "varying vec4 vColor;       \n"
        "void main()                                  \n"
        "{                                            \n"
        "  gl_FragColor = vColor;                     \n"
        "}                                            \n";

        GLuint vertexShader;
        GLuint fragmentShader;
        GLuint programObject;
        GLint linked;

        // Load the vertex/fragment shaders
        vertexShader = AvkV3dloadShader ( GL_VERTEX_SHADER, vShaderStr );
        fragmentShader = AvkV3dloadShader ( GL_FRAGMENT_SHADER, fShaderStr );

        // Create the program object
        programObject = glCreateProgram ( );

        VFX_DEV_ASSERT(programObject);

        glAttachShader ( programObject, vertexShader );
        glAttachShader ( programObject, fragmentShader );

        // Bind vPosition to attribute 0   
        glBindAttribLocation ( programObject, 0, "vPosition" );

        glBindAttribLocation ( programObject, 1, "vColor" );

        // Link the program
        glLinkProgram ( programObject );

        // Check the link status
        glGetProgramiv ( programObject, GL_LINK_STATUS, &linked );

        if ( !linked ) 
        {
            glDeleteProgram ( programObject );
            VFX_DEV_ASSERT(0);
        }

        // Store the program object
        userData->programObject = programObject;

        glClearColor ( 0.0f, 0.0f, 0.0f, 0.0f );
    }

    virtual void onDeinitResource()
    {
        UserData *userData = &m_data;
        if (userData->programObject)
        {
            glDeleteProgram(userData->programObject);
            userData->programObject = 0;
        }
    }

    virtual void onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect)
    {
        UserData *userData = &m_data;
        GLfloat vVertices[] = {  0.0f,  0.5f, 0.0f, 
                               -0.5f, -0.5f, 0.0f,
                                1.0f, 0.5f, 0.0f,
                                0.5f, -0.5f, 0.0f};

        GLubyte vColors[] = { 255, 255, 255, 255,
                               255, 0, 0, 255,
                               0, 0, 255, 255,
                               255, 255, 0, 255};

        // Set the viewport
        glViewport ( 0, 0, dstRect.size.width, dstRect.size.height );

        // Clear the color buffer
        glClear ( GL_COLOR_BUFFER_BIT );
 
        // Use the program object
        glUseProgram ( userData->programObject );

        // Load the vertex data
        glVertexAttribPointer ( 0, 3, GL_FLOAT, GL_FALSE, 0, vVertices );
        glEnableVertexAttribArray ( 0 );

        glVertexAttribPointer ( 1, 4, GL_UNSIGNED_BYTE, GL_TRUE, 0, vColors );
        glEnableVertexAttribArray ( 1 );

        glVertexAttrib4f ( 1, 0.0, 1.0, 0.0, 1.0 );
        glDrawArrays ( GL_TRIANGLE_STRIP, 0, 4 );

    }

    UserData m_data;
};

class AvkV3dOwnerDraw : public AvkV3dBaseScr
{
// Variable
public:
    
// Constructor / Destructor
public:
    AvkV3dOwnerDraw()
    {
    }

    // Override
public:  
     virtual void startTest(VfxWString wstrCaseName,int item_idx)  
     {
         AvkV3dBaseScr::startTest(wstrCaseName, item_idx);     
        confirm(VFX_WSTR("3D Owner Draw OK?"));

        MyGLESOwenerDraw *ownerDraw;
        VFX_OBJ_CREATE(ownerDraw, MyGLESOwenerDraw, this);
        setOwnerDraw(ownerDraw);
    }
};



AVK_V3D_CREATE_SCRN(A01, 'A01', "V3D_ENGINE_A01", AvkV3d3DPick)
//AVK_V3D_CREATE_SCRN(A02, 'A02', "V3D_ENGINE_A02", AvkV3d3DMesh)
AVK_V3D_CREATE_SCRN(B01, 'B01', "V3D_ENGINE_B01", AvkV3d3DAnimationB01)
AVK_V3D_CREATE_SCRN(B02, 'B02', "V3D_ENGINE_B02", AvkV3d3DAnimationB02)
AVK_V3D_CREATE_SCRN(B03, 'B03', "V3D_ENGINE_B03", AvkV3d3DAnimationB03)
AVK_V3D_CREATE_SCRN(B04, 'B04', "V3D_ENGINE_B04", AvkV3d3DAnimationB04)
AVK_V3D_CREATE_SCRN(B05, 'B05', "V3D_ENGINE_B05", AvkV3d3DAnimationB05)
AVK_V3D_CREATE_SCRN(B06, 'B06', "V3D_ENGINE_B06", AvkV3d3DAnimationB06)
AVK_V3D_CREATE_SCRN(B07, 'B07', "V3D_ENGINE_B07", AvkV3d3DAnimationB07)
AVK_V3D_CREATE_SCRN(B08, 'B08', "V3D_ENGINE_B08", AvkV3d3DAnimationB08)
AVK_V3D_CREATE_SCRN(B09, 'B09', "V3D_ENGINE_B09", AvkV3d3DAutoAnimateB09)
AVK_V3D_CREATE_SCRN(B10, 'B10', "V3D_ENGINE_B10", AvkV3d3DAutoAnimateB10)
AVK_V3D_CREATE_SCRN(B11, 'B11', "V3D_ENGINE_B11", AvkV3d3DAutoAnimateB11)
AVK_V3D_CREATE_SCRN(C01, 'C01', "V3D_ENGINE_C01", AvkV3dTimelineChainC01)
AVK_V3D_CREATE_SCRN(C02, 'C02', "V3D_ENGINE_C02", AvkV3dTimelineChainC02)
AVK_V3D_CREATE_SCRN(C03, 'C03', "V3D_ENGINE_C03", AvkV3dTimelineChainC03)
AVK_V3D_CREATE_SCRN(C04, 'C04', "V3D_ENGINE_C04", AvkV3dTimelineChainC04)
AVK_V3D_CREATE_SCRN(C05, 'C05', "V3D_ENGINE_C05", AvkV3dTimelineChainC05)
AVK_V3D_CREATE_SCRN(C06, 'C06', "V3D_ENGINE_C06", AvkV3dTimelineChainC06)
AVK_V3D_CREATE_SCRN(C07, 'C07', "V3D_ENGINE_C07", AvkV3dTimelineChainFromCurrent)
AVK_V3D_CREATE_SCRN(D01, 'D01', "V3D_ENGINE_D01", AvkV3dSceneGraph)
AVK_V3D_CREATE_SCRN(D02, 'D02', "V3D_ENGINE_D02", AvkV3dTransformable)
AVK_V3D_CREATE_SCRN(D03, 'D03', "V3D_ENGINE_D03", AvkV3dNode)
AVK_V3D_CREATE_SCRN(D04, 'D04', "V3D_ENGINE_D04", AvkV3dGroup)
AVK_V3D_CREATE_SCRN(D05, 'D05', "V3D_ENGINE_D05", AvkV3dWorld)
AVK_V3D_CREATE_SCRN(D06, 'D06', "V3D_ENGINE_D06", AvkV3dCamera)
AVK_V3D_CREATE_SCRN(D07, 'D07', "V3D_ENGINE_D07", AvkV3dViewport)
AVK_V3D_CREATE_SCRN(D08, 'D08', "V3D_ENGINE_D08", AvkV3dFrameTexture)
AVK_V3D_CREATE_SCRN(D09, 'D09', "V3D_ENGINE_D09", AvkV3dTextureTransform)
//AVK_V3D_CREATE_SCRN(D10, 'D10', "V3D_ENGINE_D10", AvkV3dProjectiveTexture)
AVK_V3D_CREATE_SCRN(D11, 'D11', "V3D_ENGINE_D11", AvkV3dEnvironmentMap)
AVK_V3D_CREATE_SCRN(D12, 'D12', "V3D_ENGINE_D12", AvkV3dProceduralMesh)
AVK_V3D_CREATE_SCRN(D13, 'D13', "V3D_ENGINE_D13", AvkV3dSkinnedMesh)
AVK_V3D_CREATE_SCRN(D14, 'D14', "V3D_ENGINE_D14", AvkV3dAutoDepthBuffer)
AVK_V3D_CREATE_SCRN(D15, 'D15', "V3D_ENGINE_D15", AvkV3dDisableColorKey)
//AVK_V3D_CREATE_SCRN(E01, 'E01', "V3D_ENGINE_E01", AvkV3dRenderState)
AVK_V3D_CREATE_SCRN(E02, 'E02', "V3D_ENGINE_E02", AvkV3dMultiPass)
AVK_V3D_CREATE_SCRN(E03, 'E03', "V3D_ENGINE_E03", AvkV3dRenderTarget)
AVK_V3D_CREATE_SCRN(E04, 'E04', "V3D_ENGINE_E04", AvkV3dFrameMaterialE04)
//AVK_V3D_CREATE_SCRN(E05, 'E05', "V3D_ENGINE_E05", AvkV3dFrameMaterialE05)
AVK_V3D_CREATE_SCRN(E06, 'E06', "V3D_ENGINE_E06", AvkV3dFrameMaterialE06)
AVK_V3D_CREATE_SCRN(E07, 'E07', "V3D_ENGINE_E07", AvkV3dBuiltinUniforms)
AVK_V3D_CREATE_SCRN(E08, 'E08', "V3D_ENGINE_E08", AvkV3dColorFrameMaterial)
AVK_V3D_CREATE_SCRN(F01, 'F01', "V3D_ENGINE_F01", AvkV3dOwnerDraw)



  

    
    


    
      
    
    
















#endif

#endif /* __MAUI_SDK_TEST__ */








