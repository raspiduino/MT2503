/*****************************************************************************
*  Copyright Statement: 
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 * EngineerModeMMColor.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for engineer mode MM Color part for MT6260.
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
	 
#include "mmi_features.h"
#if defined(__MMI_ENGINEER_MODE__)

#include "drv_sw_features_color.h"
//#define __COLOR_HW_SUPPORTED__
#if defined(__COLOR_HW_SUPPORTED__)
#include "color_api.h" // for set color APIs
#include "MMIDataType.h"
#include "InlineCuiGprot.h" // for cui_inline_item_caption_struct
#include "mmi_rp_app_engineermode1_def.h"  
#include "EngineerModeUtil.h"
#include "GlobalResDef.h"
#include "EngineerModeCommMem.h"
#include "EngineerModeCommUI.h"



#define MMI_EM_DEV_MM_COLOR_BUF_LEN       8
#define MMI_EM_DEV_MM_COLOR_ITEM_COUNT   6

#define MMI_EM_CAPTION_SHARP    	  	(CUI_INLINE_ITEM_ID_BASE+0)
#define MMI_EM_CAPTION_CONTRAST     	(CUI_INLINE_ITEM_ID_BASE+1)
#define MMI_EM_CAPTION_SATURATION     	(CUI_INLINE_ITEM_ID_BASE+2)
#define MMI_EM_TEXT_EDIT_SHARP   	    (CUI_INLINE_ITEM_ID_BASE+3)
#define MMI_EM_TEXT_EDIT_CONTRAST   	(CUI_INLINE_ITEM_ID_BASE+4)
#define MMI_EM_TEXT_EDIT_SATURATION   	(CUI_INLINE_ITEM_ID_BASE+5)


static const cui_inline_item_caption_struct g_mmi_em_mm_color_sharp_cap = 
{
    STR_ID_EM_DEV_SHARP,
};

static const cui_inline_item_caption_struct g_mmi_em_mm_color_contrast_cap = 
{
    STR_ID_EM_DEV_CONTRAST,
};

static const cui_inline_item_caption_struct g_mmi_em_mm_color_saturation_cap = 
{
    STR_ID_EM_DEV_SATURATION,
};

static const cui_inline_item_text_edit_struct g_mmi_em_mm_color_edit =
{
    0, 0, MMI_EM_DEV_MM_COLOR_BUF_LEN + 1, IMM_INPUT_TYPE_NUMERIC, 0, NULL
};

static const cui_inline_set_item_struct g_mmi_em_mm_color_inline[] = 
{
    {MMI_EM_CAPTION_SHARP,      CUI_INLINE_ITEM_TYPE_CAPTION,    0,  (void*)&g_mmi_em_mm_color_sharp_cap},
    {MMI_EM_TEXT_EDIT_SHARP,        CUI_INLINE_ITEM_TYPE_TEXT_EDIT,  0,  (void*)&g_mmi_em_mm_color_edit},
    {MMI_EM_CAPTION_CONTRAST,   CUI_INLINE_ITEM_TYPE_CAPTION,    0,  (void*)&g_mmi_em_mm_color_contrast_cap},
    {MMI_EM_TEXT_EDIT_CONTRAST,        CUI_INLINE_ITEM_TYPE_TEXT_EDIT,  0,  (void*)&g_mmi_em_mm_color_edit},
    {MMI_EM_CAPTION_SATURATION, CUI_INLINE_ITEM_TYPE_CAPTION,    0,  (void*)&g_mmi_em_mm_color_saturation_cap},
    {MMI_EM_TEXT_EDIT_SATURATION,        CUI_INLINE_ITEM_TYPE_TEXT_EDIT,  0,  (void*)&g_mmi_em_mm_color_edit}
};

static const cui_inline_struct g_mmi_em_mm_color_inline_scrn = 
{
    MMI_EM_DEV_MM_COLOR_ITEM_COUNT,
    STR_ID_EM_DEV_MM_COLOR,
    0,
    CUI_INLINE_SCREEN_LOOP|CUI_INLINE_SCREEN_DISABLE_DONE,
    NULL,
    (const cui_inline_set_item_struct*)&g_mmi_em_mm_color_inline
};
typedef struct
{
    WCHAR sharp_buf[MMI_EM_DEV_MM_COLOR_BUF_LEN + 1];
    WCHAR contrast_buf[MMI_EM_DEV_MM_COLOR_BUF_LEN + 1];
    WCHAR saturation_buf[MMI_EM_DEV_MM_COLOR_BUF_LEN + 1];
} mmi_em_dev_mm_color_cntx_struct;

static mmi_em_dev_mm_color_cntx_struct *mmi_em_dev_mm_color_cntx_p = NULL;
static U32 g_mm_color_sharp = 0;
static U32 g_mm_color_contrast = 0;
static U32 g_mm_color_saturation = 0;

static void mmi_em_dev_enter_mm_color(void);
static MMI_RET mmi_em_dev_mm_color_proc(mmi_event_struct* evt);

MMI_EM_INIT_ASM(dev_mm_color, mmi_em_dev_mm_color_cntx_p, sizeof(mmi_em_dev_mm_color_cntx_struct))


void mmi_em_dev_mm_color_select_hdlr(void)
{	
    MMI_EM_ASM_INIT_FUNC(dev_mm_color);
    mmi_em_dev_enter_mm_color();
}

static void mmi_em_dev_enter_mm_color(void)
{
    MMI_ID gid;
    MMI_ID inline_id;
	
	
    gid = mmi_frm_group_create_ex(mmi_em_get_root_group(),
                  GRP_ID_AUTO_GEN, 
                  mmi_em_dev_mm_color_proc, NULL,
                  MMI_FRM_NODE_SMART_CLOSE_FLAG);

    inline_id = cui_inline_create(gid, &g_mmi_em_mm_color_inline_scrn);

    kal_wsprintf(mmi_em_dev_mm_color_cntx_p->sharp_buf, "%d", g_mm_color_sharp);
    kal_wsprintf(mmi_em_dev_mm_color_cntx_p->contrast_buf, "%d", g_mm_color_contrast);
    kal_wsprintf(mmi_em_dev_mm_color_cntx_p->saturation_buf, "%d", g_mm_color_saturation);
    cui_inline_set_value(inline_id, MMI_EM_TEXT_EDIT_SHARP, (void *) mmi_em_dev_mm_color_cntx_p->sharp_buf);
    cui_inline_set_value(inline_id, MMI_EM_TEXT_EDIT_CONTRAST, (void *) mmi_em_dev_mm_color_cntx_p->contrast_buf);
    cui_inline_set_value(inline_id, MMI_EM_TEXT_EDIT_SATURATION, (void *) mmi_em_dev_mm_color_cntx_p->saturation_buf);
    
    cui_inline_run(inline_id);
}

static MMI_RET mmi_em_dev_mm_color_proc(mmi_event_struct* evt)
{
    cui_event_inline_common_struct* inline_evt = (cui_event_inline_common_struct*) evt;
	MMI_ID parent_id;
	U32 value;
	
    parent_id = inline_evt->sender_id;

    switch (inline_evt->evt_id)
    {
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:			
	    cui_inline_get_value(parent_id, MMI_EM_TEXT_EDIT_SHARP, (void *)mmi_em_dev_mm_color_cntx_p->sharp_buf);
	    cui_inline_get_value(parent_id, MMI_EM_TEXT_EDIT_CONTRAST, (void *)mmi_em_dev_mm_color_cntx_p->contrast_buf);
	    cui_inline_get_value(parent_id, MMI_EM_TEXT_EDIT_SATURATION, (void *)mmi_em_dev_mm_color_cntx_p->saturation_buf);

		value = mmi_wcs_wtoi(mmi_em_dev_mm_color_cntx_p->sharp_buf);
		g_mm_color_sharp = value;
		colorSetCustomSharpnessTableIndex(value);
		value = mmi_wcs_wtoi(mmi_em_dev_mm_color_cntx_p->contrast_buf);
		g_mm_color_contrast = value;
		colorSetCustomContrastTableIndex(value);
		
		value = mmi_wcs_wtoi(mmi_em_dev_mm_color_cntx_p->saturation_buf);
		g_mm_color_saturation = value;
		colorSetCustomSaturationTableIndex(value);
		
	    cui_inline_close(parent_id);
	    MMI_EM_ASM_FREE_FUNC(dev_mm_color);
        break;

    case EVT_ID_CUI_INLINE_ABORT:
        cui_inline_close(parent_id);
        MMI_EM_ASM_FREE_FUNC(dev_mm_color);
        break;
    default:
        break;
    }

    return MMI_RET_OK;
}

#endif //__COLOR_HW_SUPPORTED__
#endif //__MMI_ENGINEER_MODE__

