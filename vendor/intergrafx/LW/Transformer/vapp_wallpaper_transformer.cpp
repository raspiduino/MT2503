/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_wallpaper_transformer.cpp
 *
 * Project:
 * --------
 *  Intergrafx
 *
 * Description:
 * ------------
 *  Home screen transformer wallpaper class
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_TRANSFORMER__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vapp_wallpaper_transformer.h"
#include "HomeScreen/vadp_v2p_hs.h"
#include "mmi_rp_app_venus_wallpaper_transformer_def.h"

/* RHR start */
#include "vfx_cpp_base.h"   
#include "vfx_object.h"    
#include "vfx_sys_memory.h"    
#include "vapp_wallpaper.h"  
#include "vfx_class_info.h"   
#include "vfx_datatype.h"   
#include "vfx_primitive_frame.h"  
#include "vapp_hs_def.h"    
#include "vfx_basic_type.h"    
#include "vrt_datatype.h"  
#include "vfx_animation.h"   
#include "vrt_canvas.h"    
#include "vfx_input_event.h"  
#include "vfx_frame.h"     
#include "vfx_image_src.h"
/* RHR end */

#include "IGExtDef.h"
#include "IGGame.h"
#include "V3Retained.h"
#include "WP4-A-GameApp.h"

#if defined(__COSMOS_MMI__)
#include "vapp_wallpaper_setting_method_gprot.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#include "WPSSProtos.h"
#include <setjmp.h>
#include "gdi_primitive.h"

#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Home screen UI componet: transformer wallpaper
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("Transformer Wallpaper", VappWallpaperTransformer, VappWallpaper);

VappWallpaperTransformer::VappWallpaperTransformer()
{
	m_imgBg = NULL;
	m_draw = NULL;
	m_timeline = NULL;
	m_isSerialized = VFX_FALSE;
	m_isRestored = VFX_FALSE;
}

void VappWallpaperTransformer::onInit()
{
    VappWallpaper::onInit();
    this->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
}

void VappWallpaperTransformer::onDeinit()
{
    VappWallpaper::onDeinit();
}

mmi_ret VappWallpaperTransformer::mmi_ig_lw_transformer_proc(mmi_frm_asm_evt_struct * evt)
{
	switch (evt->evt_id)
	{
	case EVT_ID_DELETE_DANGLE_GROUP_REQ:
		return MMI_RET_ERR;
	case EVT_ID_ASM_FREE_REQ:         /*volunteer free*/        
    case EVT_ID_ASM_FORCE_FREE:       /*force free*/
	case EVT_ID_ASM_FREE_REQ_NO_WAIT: /* volunteer free*/
		{
			//MMI_ASSERT(0);
			VappWallpaperTransformer *pThis = (VappWallpaperTransformer*)VfxObject::handleToObject(evt->user_data);
			if(pThis)
			{
			    pThis->restoreWallpaperSetting();
			}
		}
		return MMI_FRM_ASM_FREED;
	default:
		break;
	}
	return MMI_RET_OK;
}

void VappWallpaperTransformer::onCreateView()
{
    if (m_isRestored)
    {
		return;
    }

	IGV3Config PC;
	
	PC.m_uScrWidth = 320;
	PC.m_uScrHeight = 480;
	PC.m_pFrameBuffer = NULL;
	PC.m_pMemBuffer = NULL;
	PC.m_MemSize = 0;

	VFX_OBJ_CREATE(m_imgBg, VfxImageFrame, this);
    m_imgBg->setIsOpaque(VFX_TRUE);
    m_imgBg->setSize(this->getSize());
	m_imgBg->setAutoAnimate(VFX_TRUE);
	PC.m_uScrWidth = this->getSize().width;
	PC.m_uScrHeight = this->getSize().height;

	mmi_frm_group_create(GRP_ID_ROOT, APP_VENUS_WALLPAPER_INTERGRAFX, (mmi_proc_func)VappWallpaperTransformer::mmi_ig_lw_transformer_proc, getObjHandle());
	mmi_frm_asm_property_struct property;
	if (mmi_frm_asm_get_property(APP_VENUS_WALLPAPER_INTERGRAFX, &property))
	{
        property.f_prepare_w_reserve = 0;
		property.f_hide_in_oom = 0;
		mmi_frm_asm_set_property(APP_VENUS_WALLPAPER_INTERGRAFX, &property);
	}

    VfxId appId = getExternalMemorySource();
    if (appId)
    {
        if(PC.m_uScrWidth == 480 && PC.m_uScrHeight == 800)//WVGA check
        {
            g_lw_memPool = mmi_frm_asm_alloc_r(appId, 6*1024*1024);
        }
        else
        {
            g_lw_memPool = mmi_frm_asm_alloc_r(appId, 4*1024*1024);
        }
    }

	WP4_A_PrepareConfig(&PC);

	if (g_lw_memPool == NULL)
	{
	    restoreWallpaperSetting();
	}

    VFX_OBJ_CREATE(m_draw, VappTransformerFilter, this);
    m_imgBg->setFilter(m_draw);

	m_draw->m_imgSize.width = this->getSize().width;
	m_draw->m_imgSize.height = this->getSize().height;

    // start filter timeline
    VFX_OBJ_CREATE(m_timeline, VfxFloatTimeline, this);
    m_timeline->setFromValue(0.0f);
    m_timeline->setToValue(1.0f);
    m_timeline->setDurationTime(2000);
    m_timeline->setAutoReversed(VFX_FALSE);
    m_timeline->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    m_timeline->setTarget(m_imgBg);
    m_timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
    m_timeline->start();

    if (g_lw_memPool != NULL)
    {
        WP4_A_OnStartup();
    }

	m_draw->GetElapsedTime();
}

void VappWallpaperTransformer::onReleaseView()
{
    if (m_isSerialized)
    {
		return;
    }

	if (g_lw_memPool != NULL)
    {
        VfxId appId = getExternalMemorySource();
	    WP4_A_OnShutdown(appId);
    }

    m_imgBg->setFilter(NULL);
    VFX_OBJ_CLOSE(m_timeline);
    VFX_OBJ_CLOSE(m_draw);
    VFX_OBJ_CLOSE(m_imgBg);
}

void VappWallpaperTransformer::onSerializeView()
{
    if(!m_isSerialized)
    {
        onReleaseView();
		m_isSerialized = VFX_TRUE;
		m_isRestored = VFX_FALSE;
    }
}

void VappWallpaperTransformer::onRestoreView()
{
    if(!m_isRestored)
    {
        onCreateView();
		m_isRestored = VFX_TRUE;
		m_isSerialized = VFX_FALSE;
    }

	if(isSuspended())
	{
		onSuspend();
	}
}

MMI_IMG_ID VappWallpaperTransformer::getThumbnail()
{
    return IMG_ID_VAPP_WALLPAPER_TRANSFORMER_THUMBNAIL;
}

void VappWallpaperTransformer::getName(VfxWString &wallpaperName)
{
    wallpaperName = VFX_WSTR_RES(STR_ID_WALLPAPER_VUI_LIVE_IG_TRANSFORMER);
    return;
}


void VappWallpaperTransformer::onSuspend()
{
	if (m_timeline != NULL)
		m_timeline->stop();

	if (m_draw != NULL)
		m_draw->m_isSuspend = VFX_TRUE;
}

void VappWallpaperTransformer::onResume()
{
	if (m_timeline != NULL)
		m_timeline->start();

 	if (m_draw != NULL)
	   m_draw->m_isSuspend = VFX_FALSE;
}

VfxBool VappWallpaperTransformer::onPenInput(VfxPenEvent &event)
{
	V3Retained *rr = V3Retained_GetInstance();

	if (g_lw_memPool == NULL)
		return VFX_TRUE;

	if (rr->m_Scene == NULL)
		return VFX_TRUE;

	switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        {
			WP4_A_PostEvent(IGFK_TOUCH1_DOWN, 0L, event.downPos.x, event.downPos.y);
            return VFX_TRUE;
        }
		case VFX_PEN_EVENT_TYPE_MOVE :
        {
			WP4_A_PostEvent(IGFK_TOUCH1_MOVE, 0L, event.pos.x, event.pos.y);
            return VFX_TRUE;
        }
		case VFX_PEN_EVENT_TYPE_UP :
        {
			WP4_A_PostEvent(IGFK_TOUCH1_UP, 0L, event.pos.x, event.pos.y);
            return VFX_TRUE;
        }
    }
    return VFX_TRUE;
}

void VappWallpaperTransformer::onDesktopBoundsChanged(
        const VfxU32 totalPage,
        VfxFrame *source,
        const VfxRect &oldBounds)
{

}

void VappWallpaperTransformer::restoreWallpaperSetting(void)
{
#if defined(__COSMOS_MMI__)
	m_imgBg->setFilter(NULL);

    // restore wallpaper back to default
    VappWallpaperSettingInterface *wallpaperInterface = VFX_OBJ_GET_INSTANCE(VappWallpaperSettingInterface);
    const VappWallpaperType source = (VappWallpaperType)getSource();
    wallpaperInterface->restoreWallpaper(source);
#else
    PhnsetWallpaperBadFileCallBack(0);
#endif
}

/*****************************************************************************
 * Class VappTransformerFilter
 *****************************************************************************/
VappTransformerFilter::VappTransformerFilter() : m_isSuspend(VFX_FALSE)
{
}

void VappTransformerFilter::onInit()
{
    VfxFrameFilter::onInit();
    
    // IG only supports RGB565 now
    setColorFormat(VRT_COLOR_TYPE_RGB565);
}

void VappTransformerFilter::onDeinit()
{
	VfxFrameFilter::onDeinit();
}

VfxFrameFilter::BufferModeEnum VappTransformerFilter::onGetBufferMode() const
{
#if defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24)
    return VfxFrameFilter::BUFFER_MODE_OUT_OF_PLACE;
#else
    return VfxFrameFilter::BUFFER_MODE_IN_PLACE;
#endif
}

U32 VappTransformerFilter::GetElapsedTime()
{
	m_time.setCurrentTime();
	WP4_A_SetLocalTime(m_time.getHour(), m_time.getMinute(), m_time.getSecond());

    kal_uint32 tick;
	U32 cur_ms, dt;

    kal_get_time(&tick);
	cur_ms = kal_ticks_to_milli_secs(tick);
	dt = WP4_A_GetElapsedTime(cur_ms);

    if (m_isSuspend)
    {
        dt = 0;
    }
    return dt;
}

VfxBool VappTransformerFilter::onProcess(VfxU8 *outBuf, VfxImageBuffer &inBuf, VfxFloat timing)
{
    if (g_lw_memPool != NULL)
    {
        U32 dt = GetElapsedTime();
        WP4_A_OnUpdate(outBuf, dt);
    }
    return VFX_TRUE;
}
#endif /*__MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_TRANSFORMER__*/
