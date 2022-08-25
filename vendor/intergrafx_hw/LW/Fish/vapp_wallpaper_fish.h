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
 *  vapp_wallpaper_fish.h
 *
 * Project:
 * --------
 *  Intergrafx
 *
 * Description:
 * ------------
 *  Home screen fish wallpaper class header file
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

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_FISH__

#ifndef __VAPP_WALLPAPER_FISH_H__
#define __VAPP_WALLPAPER_FISH_H__

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vapp_wallpaper.h"

/* RHR start */
#include "vfx_object.h"   
#include "vfx_class_info.h"
#include "vfx_datatype.h"   
#include "vfx_cpp_base.h"
#include "vapp_wallpaper_cfg.h"
#include "vfx_sys_memory.h"
#include "vfx_frame.h"    
#include "vfx_basic_type.h"
#include "vfx_input_event.h"
#include "vfx_primitive_frame.h"  
#include "vfx_animation.h"
#include "vfx_owner_draw.h"
#include "vrt_datatype.h"
#include "vfx_image_src.h"
/* RHR end */

class VappFishDraw;

/*****************************************************************************
 * Home screen UI componet: fish wallpaper class
 *****************************************************************************/
class VappWallpaperFish: public VappWallpaper
{
    VFX_DECLARE_CLASS(VappWallpaperFish);

    VAPP_WALLPAPER_CREATE(VappWallpaperFish);

// Constructor / Destructor
public:
    // Default constructor
    VappWallpaperFish();

// Override
public:
    // This function used to get image id of wallpaper thumbnail
    virtual MMI_IMG_ID getThumbnail();
    virtual void getName(VfxWString &wallpaperName);

// Override
protected:
        
    // Init wallpaper
    virtual void onInit();
        
    // Deinit
    virtual void onDeinit();
        
    // create wallpaper
    virtual void onCreateView();

    // release wallpaper
    virtual void onReleaseView();

    //serialize wallpaper
	virtual void onSerializeView();

    //restore wallpaper
	virtual void onRestoreView();

	// Is allow suspend wallpaper when desktop swipe
    virtual VfxBool onAllowSuspendOnSwipe() {return VFX_FALSE;}

    // callback for suspend and resume wallpaper
    virtual void onSuspend();
    virtual void onResume();
    virtual void onDesktopBoundsChanged(
        const VfxU32 totalPage,
        VfxFrame *source,
        const VfxRect &oldBounds
    );


//Override
protected:
    virtual VfxBool onPenInput(VfxPenEvent & event);

//Variable
public:
    // wallpaper background frame
    VfxImageFrame *m_imgBg;

private:
	VappFishDraw *m_draw;
	VfxBool     m_isSerialized;
	VfxBool     m_isRestored;

    VfxFloatTimeline *m_timeline;
	static mmi_ret mmi_ig_lw_fish_proc(mmi_frm_asm_evt_struct *evt);
};

/*****************************************************************************
 * Class FrameFilter
 *****************************************************************************/

class VappFishDraw : public VfxOwnerDraw
{
// Constructor
public:
	VfxSize	m_imgSize;
	VfxDateTime m_time;
	VfxBool m_suspend;
	VappFishDraw();

virtual void onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect);

// Overridable
protected:
	  virtual void onInit();
      virtual void onDeinit();
	  virtual void onInitResource();
	  virtual void onDeinitResource();
	  virtual vrt_bool isUsingGLAPI() const { return VFX_TRUE; }
	  virtual vrt_bool isUsingDepthStencil() const { return VFX_TRUE; }

};
#endif /* __VAPP_WALLPAPER_FISH_H__ */
#endif /* __MMI_VUI_HOMESCREEN_IG_LIVE_WALLPAPER_FISH__ */

