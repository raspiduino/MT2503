/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *    PictBridgeSettings.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    This file is intended for PictBridge appliction.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_PICT_BRIDGE_SUPPORT__

#ifdef __MMI_PICT_BRIDGE_CROPPING__
#define __MMI_PICT_BRIDGE_CROPPING_CAT88__
#endif

#include "inlinecuigprot.h"

#include "PictBridgeDef.h"
#include "PictBridgeProt.h"
#include "PictBridgeStruct.h"
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "mmi_rp_srv_pict_bridge_def.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "Pictcuigprot.h"
#include "PictBridgeResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "nvram_common_defs.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "mmi_frm_nvram_gprot.h"
/* auto add by kw_check end */
#define MMI_PICTBRIDGE_GET_LAYOUT_INDEX mmi_pict_get_match_pos( \
                                            g_pict_bridge_xml.paper_sizes, \
                                            g_pict_bridge_setting.paper_size)

/*
 * Global Variable
 */
extern pict_bridge_context_struct g_pict_bridge_context;
extern pict_bridge_xml_struct g_pict_bridge_xml;
extern mmi_id g_pict_gid;

/*
 * Local Variable
 */
pict_bridge_setting_struct g_pict_bridge_setting;


#define PICT_CAPTION_1       	   CUI_INLINE_ITEM_ID_BASE+0
#define PICT_CAPTION_2       	   CUI_INLINE_ITEM_ID_BASE+2
#define PICT_CAPTION_3       	   CUI_INLINE_ITEM_ID_BASE+4
#define PICT_CAPTION_4       	   CUI_INLINE_ITEM_ID_BASE+6
#define PICT_CAPTION_5       	   CUI_INLINE_ITEM_ID_BASE+8
#define PICT_CAPTION_6       	   CUI_INLINE_ITEM_ID_BASE+10
#define PICT_CAPTION_7       	   CUI_INLINE_ITEM_ID_BASE+12
#define PICT_CAPTION_8       	   CUI_INLINE_ITEM_ID_BASE+14

#define PICT_SELECT_1       	   CUI_INLINE_ITEM_ID_BASE+1
#define PICT_SELECT_2       	   CUI_INLINE_ITEM_ID_BASE+3
#define PICT_SELECT_3       	   CUI_INLINE_ITEM_ID_BASE+5
#define PICT_SELECT_4       	   CUI_INLINE_ITEM_ID_BASE+7
#define PICT_SELECT_5       	   CUI_INLINE_ITEM_ID_BASE+9
#define PICT_SELECT_6       	   CUI_INLINE_ITEM_ID_BASE+11
#define PICT_SELECT_7       	   CUI_INLINE_ITEM_ID_BASE+13
#define PICT_SELECT_8       	   CUI_INLINE_ITEM_ID_BASE+15

static const cui_inline_item_caption_struct pict_setting_caption1 =
{
    STR_ID_PICT_PAPER_SIZE
};

static const cui_inline_item_caption_struct pict_setting_caption2 =
{
    STR_ID_PICT_COPIES
};

static const cui_inline_item_caption_struct pict_setting_caption3 =
{
    STR_ID_PICT_PAGE_FORMAT
};

static const cui_inline_item_caption_struct pict_setting_caption4 =
{
    STR_ID_PICT_LAYOUT
};

static const cui_inline_item_caption_struct pict_setting_caption5 =
{
    STR_ID_PICT_BORDER
};

static const cui_inline_item_caption_struct pict_setting_caption6 =
{
    STR_ID_PICT_DATE_PRINT
};

static const cui_inline_item_caption_struct pict_setting_caption7 =
{
    STR_ID_PICT_FILENAME_PRINT
};

static const cui_inline_item_caption_struct pict_setting_caption8 =
{
    STR_ID_PICT_CROPPING
};


static const cui_inline_set_item_struct pict_setting_items[] = 
{
    {PICT_CAPTION_1, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (void*)&pict_setting_caption1},
	{PICT_SELECT_1, CUI_INLINE_ITEM_TYPE_SELECT, 0, NULL},
	{PICT_CAPTION_2, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (void*)&pict_setting_caption2},
	{PICT_SELECT_2, CUI_INLINE_ITEM_TYPE_SELECT, 0, NULL},
	{PICT_CAPTION_3, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, (void*)&pict_setting_caption3},
	{PICT_SELECT_3, CUI_INLINE_ITEM_TYPE_SELECT, 0, NULL},
	{PICT_CAPTION_4, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L4, (void*)&pict_setting_caption4},
	{PICT_SELECT_4, CUI_INLINE_ITEM_TYPE_SELECT, 0, NULL},
	{PICT_CAPTION_5, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L5, (void*)&pict_setting_caption5},
	{PICT_SELECT_5, CUI_INLINE_ITEM_TYPE_SELECT, 0, NULL},
	{PICT_CAPTION_6, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L6, (void*)&pict_setting_caption6},
	{PICT_SELECT_6, CUI_INLINE_ITEM_TYPE_SELECT, 0, NULL},
	{PICT_CAPTION_7, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L7, (void*)&pict_setting_caption7},
	{PICT_SELECT_7, CUI_INLINE_ITEM_TYPE_SELECT, 0, NULL},
#ifdef __MMI_PICT_BRIDGE_CROPPING__
	{PICT_CAPTION_8, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L8, (void*)&pict_setting_caption8},
	{PICT_SELECT_8, CUI_INLINE_ITEM_TYPE_SELECT, 0, NULL},
#endif
};

static const cui_inline_struct pict_setting_screen = 
{
    sizeof(pict_setting_items)/sizeof(cui_inline_set_item_struct),
	STR_ID_PICT_SETTINGS,
    0,
	CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
	0,
	(void*)&pict_setting_items
};

#ifdef __MMI_PICT_BRIDGE_CROPPING__

#define PICT_CROPPING_CAP1       	   CUI_INLINE_ITEM_ID_BASE+0
#define PICT_CROPPING_CAP2       	   CUI_INLINE_ITEM_ID_BASE+2
#define PICT_CROPPING_CAP3       	   CUI_INLINE_ITEM_ID_BASE+4
#define PICT_CROPPING_CAP4       	   CUI_INLINE_ITEM_ID_BASE+6

#define PICT_CROPPING_SEL1       	   CUI_INLINE_ITEM_ID_BASE+1
#define PICT_CROPPING_SEL2       	   CUI_INLINE_ITEM_ID_BASE+3
#define PICT_CROPPING_SEL3       	   CUI_INLINE_ITEM_ID_BASE+5
#define PICT_CROPPING_SEL4       	   CUI_INLINE_ITEM_ID_BASE+7

static const cui_inline_item_caption_struct pict_cropping_caption1 =
{
    STR_ID_PICT_X_COORDINATE
};
static const cui_inline_item_caption_struct pict_cropping_caption2 =
{
    STR_ID_PICT_Y_COORDINATE
};
static const cui_inline_item_caption_struct pict_cropping_caption3 =
{
    STR_ID_PICT_X_ARIX
};
static const cui_inline_item_caption_struct pict_cropping_caption4 =
{
    STR_ID_PICT_Y_ARIX
};

static const cui_inline_set_item_struct pict_cropping_items[] = 
{
    {PICT_CROPPING_CAP1, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (void*)&pict_cropping_caption1},
	{PICT_CROPPING_SEL1, CUI_INLINE_ITEM_TYPE_USER_DEFINED_SELECT, 0, NULL},
	{PICT_CROPPING_CAP2, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (void*)&pict_cropping_caption2},
	{PICT_CROPPING_SEL2, CUI_INLINE_ITEM_TYPE_USER_DEFINED_SELECT, 0, NULL},
	{PICT_CROPPING_CAP3, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, (void*)&pict_cropping_caption3},
	{PICT_CROPPING_SEL3, CUI_INLINE_ITEM_TYPE_USER_DEFINED_SELECT , 0, NULL},
	{PICT_CROPPING_CAP4, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L4, (void*)&pict_cropping_caption4},
	{PICT_CROPPING_SEL4, CUI_INLINE_ITEM_TYPE_USER_DEFINED_SELECT, 0, NULL},
};

static const cui_inline_struct pict_cropping_screen = 
{
    sizeof(pict_cropping_items)/sizeof(cui_inline_set_item_struct),
    STR_ID_PICT_CROPPING,
    0,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
    0,
    (void*)&pict_cropping_items
};

#endif

static U32 mmi_pict_get_match_pos(U32 c, S32 i);
static void mmi_pict_setting_save_prefer(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_settings_pre_paper_list
 * DESCRIPTION
 *  Preparation for inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_pict_settings_pre_paper_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 paper_count = 1;
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_pict_bridge_xml.paper_sizes == 0)
    {
        g_pict_bridge_setting.paper_list[0] = STR_GLOBAL_DEFAULT;
    }
    else
    {
        i = 0;
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_DEFAULT)
        {
            g_pict_bridge_setting.paper_list[i++] = STR_GLOBAL_DEFAULT;
        }
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_POSTCARD)
        {
            g_pict_bridge_setting.paper_list[i++] = STR_ID_PICT_PAPER_POSTCARD;
        }
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_4x6)
        {
            g_pict_bridge_setting.paper_list[i++] = STR_ID_PICT_PAPER_4x6;
        }
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_LETTER)
        {
            g_pict_bridge_setting.paper_list[i++] = STR_ID_PICT_PAPER_LETTER;
        }
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_A4)
        {
            g_pict_bridge_setting.paper_list[i++] = STR_ID_PICT_PAPER_A4;
        }
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_L)
        {
            g_pict_bridge_setting.paper_list[i++] = STR_ID_PICT_PAPER_L;
        }
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_2L)
        {
            g_pict_bridge_setting.paper_list[i++] = STR_ID_PICT_PAPER_2L;
        }
        paper_count = i;
    }

	return paper_count;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_settings_pre_copies_list
 * DESCRIPTION
 *  Preparation for inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_pict_settings_pre_copies_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 copies_count = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	/* number of copies */
    if (g_pict_bridge_setting.page_format == 0) /* standard */
    {
        g_pict_bridge_setting.copies_list[0] = STR_GLOBAL_1;
        g_pict_bridge_setting.copies_list[1] = STR_GLOBAL_2;
        g_pict_bridge_setting.copies_list[2] = STR_GLOBAL_3;
        g_pict_bridge_setting.copies_list[3] = STR_GLOBAL_4;
        g_pict_bridge_setting.copies_list[4] = STR_GLOBAL_5;
        g_pict_bridge_setting.copies_list[5] = STR_GLOBAL_6;
        g_pict_bridge_setting.copies_list[6] = STR_GLOBAL_7;
        g_pict_bridge_setting.copies_list[7] = STR_GLOBAL_8;
        g_pict_bridge_setting.copies_list[8] = STR_GLOBAL_9;
        g_pict_bridge_setting.copies_list[9] = STR_GLOBAL_10;
        copies_count = 10;
    }
    else
    {
        g_pict_bridge_setting.copies_list[0] = STR_GLOBAL_1;
        g_pict_bridge_setting.number_of_copies = 0;
    }

	return copies_count;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_settings_pre_format_list
 * DESCRIPTION
 *  Preparation for inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_pict_settings_pre_format_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 format_count = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	/* page format */
    g_pict_bridge_setting.format_list[0] = STR_ID_PICT_STANDARD;
    if (g_pict_bridge_context.printing_capability[7] == 0)
    {
        g_pict_bridge_setting.format_list[1] = STR_ID_PICT_MULTIPLE;
        g_pict_bridge_setting.format_list[2] = STR_ID_PICT_INDEX;
#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
        format_count = 3;
#else
        format_count = 2;
#endif
    }
    else
    {
        format_count = 1;
    }

	return format_count;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_settings_pre_layout_list
 * DESCRIPTION
 *  Preparation for inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_pict_settings_pre_layout_list_item(U8 item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 layout_count = 1;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */  
    /*----------------------------------------------------------------*/ 
	g_pict_bridge_setting.layout_list[0] = STR_GLOBAL_1;
	layout_count = 1;
	if (item & PICT_LAYOUT_2UP)
	{
		g_pict_bridge_setting.layout_list[1] = STR_GLOBAL_2;
		layout_count++;
		if (item & PICT_LAYOUT_4UP)
		{
			g_pict_bridge_setting.layout_list[2] = STR_GLOBAL_4;
			layout_count++;
#ifdef __MMI_PICT_BRIDGE_INDEX_PRINT__
			if ((g_pict_bridge_setting.page_format == 2) && (g_pict_bridge_xml.layouts[0] & PICT_LAYOUT_INDEX)) /* index */
			{
				g_pict_bridge_setting.layout_list[3] = STR_ID_PICT_INDEX_ALL;
				layout_count++;
			}
#endif /* __MMI_PICT_BRIDGE_INDEX_PRINT__ */
		}
	}

	return layout_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_settings_pre_layout_list
 * DESCRIPTION
 *  Preparation for inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_pict_settings_pre_layout_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 layout_count = 1;
	U8 cnt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	/* pages per sheet */
    if (g_pict_bridge_setting.page_format == 0) /* standard */
    {
        g_pict_bridge_setting.layout_list[0] = STR_GLOBAL_1;
        g_pict_bridge_setting.layout = 0;
		return layout_count;
    }
	
    do
    {
        cnt = 0;
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_DEFAULT)
        {
            if (cnt == g_pict_bridge_setting.paper_size)
            {
				layout_count = mmi_pict_settings_pre_layout_list_item(g_pict_bridge_xml.layouts[0]);
				break;
            }
            else
            {
                cnt ++;
            }
        }
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_POSTCARD)
        {
            if (cnt == g_pict_bridge_setting.paper_size)
            {
				layout_count = mmi_pict_settings_pre_layout_list_item(g_pict_bridge_xml.layouts[1]);
                break;
            }
            else
            {
                cnt ++;
            }
        }
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_4x6)
        {
            if (cnt == g_pict_bridge_setting.paper_size)
            {
				layout_count = mmi_pict_settings_pre_layout_list_item(g_pict_bridge_xml.layouts[2]);
                break;
            }
            else
            {
                cnt ++;
            }
        }
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_LETTER)
        {
            if (cnt == g_pict_bridge_setting.paper_size)
            {
				layout_count = mmi_pict_settings_pre_layout_list_item(g_pict_bridge_xml.layouts[3]);
                break;
            }
            else
            {
                cnt ++;
            }
        }
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_A4)
        {
            if (cnt == g_pict_bridge_setting.paper_size)
            {
				if (cnt == g_pict_bridge_setting.paper_size)
				{
					layout_count = mmi_pict_settings_pre_layout_list_item(g_pict_bridge_xml.layouts[4]);
					break;
				}                    
            }
            else
            {
                cnt ++;
            }
        }
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_L)
        {
            if (cnt == g_pict_bridge_setting.paper_size)
            {
				if (cnt == g_pict_bridge_setting.paper_size)
				{
					layout_count = mmi_pict_settings_pre_layout_list_item(g_pict_bridge_xml.layouts[5]);
					break;
				}                    
            }
            else
            {
                cnt ++;
            }
        }
        if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_2L)
        {
            if (cnt == g_pict_bridge_setting.paper_size)
            {
                if (cnt == g_pict_bridge_setting.paper_size)
				{
					layout_count = mmi_pict_settings_pre_layout_list_item(g_pict_bridge_xml.layouts[6]);
					break;
				}           
            }
            else
            {
                cnt ++;
            }
        }
    } while(0);

	return layout_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_settings_pre_border_list
 * DESCRIPTION
 *  Preparation for inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_pict_settings_pre_border_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 border_count = 1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	
    /* border */
    if (g_pict_bridge_setting.layout == 0 &&
        (PICT_LAYOUT_FULL & g_pict_bridge_xml.layouts[MMI_PICTBRIDGE_GET_LAYOUT_INDEX])) /* one page per sheet */
    {
        g_pict_bridge_setting.border_list[0] = STR_GLOBAL_ON;
    #ifdef __MMI_PICT_BRIDGE_COMPLIANCE_TEST__
        border_count = 1;
        do
        {
            cnt = 0;
            if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_DEFAULT)
            {
                if (cnt == g_pict_bridge_setting.paper_size)
                {
                    if (g_pict_bridge_xml.layouts[0] & PICT_LAYOUT_FULL)
                    {
                        g_pict_bridge_setting.border_list[1] = STR_GLOBAL_OFF;
                        border_count = 2;
                    }
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
            if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_POSTCARD)
            {
                if (cnt == g_pict_bridge_setting.paper_size)
                {
                    if (g_pict_bridge_xml.layouts[1] & PICT_LAYOUT_FULL)
                    {
                        g_pict_bridge_setting.border_list[1] = STR_GLOBAL_OFF;
                        border_count = 2;
                    }
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
            if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_4x6)
            {
                if (cnt == g_pict_bridge_setting.paper_size)
                {
                    if (g_pict_bridge_xml.layouts[2] & PICT_LAYOUT_FULL)
                    {
                        g_pict_bridge_setting.border_list[1] = STR_GLOBAL_OFF;
                        border_count = 2;
                    }
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
            if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_LETTER)
            {
                if (cnt == g_pict_bridge_setting.paper_size)
                {
                    if (g_pict_bridge_xml.layouts[3] & PICT_LAYOUT_FULL)
                    {
                        g_pict_bridge_setting.border_list[1] = STR_GLOBAL_OFF;
                        border_count = 2;
                    }
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
            if (g_pict_bridge_xml.paper_sizes & PICT_PAPER_A4)
            {
                if (cnt == g_pict_bridge_setting.paper_size)
                {
                    if (g_pict_bridge_xml.layouts[4] & PICT_LAYOUT_FULL)
                    {
                        g_pict_bridge_setting.border_list[1] = STR_GLOBAL_OFF;
                        border_count = 2;
                    }
                    break;
                }
                else
                {
                    cnt ++;
                }
            }
        } while(0);
    #else /* __MMI_PICT_BRIDGE_COMPLIANCE_TEST__ */
        g_pict_bridge_setting.border_list[1] = STR_GLOBAL_OFF;
        border_count = 2;
    #endif /* __MMI_PICT_BRIDGE_COMPLIANCE_TEST__ */
    }
    else
    {
        g_pict_bridge_setting.border_list[0] = STR_GLOBAL_ON;
        g_pict_bridge_setting.border = 0;
    }

	return border_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_settings_pre_date_list
 * DESCRIPTION
 *  Preparation for inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_pict_settings_pre_date_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 date_count = 1;
	U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	/* date print */
    if (g_pict_bridge_xml.date_prints == 0)
    {
        g_pict_bridge_setting.date_list[0] = STR_GLOBAL_DEFAULT;
    }
    else if (g_pict_bridge_setting.layout != 0) /* multiple page per sheet */
    {
        g_pict_bridge_setting.date_list[0] = STR_GLOBAL_DEFAULT;
        g_pict_bridge_setting.date_print = 0;
    }
    else
    {
        i = 0;
        if (g_pict_bridge_xml.date_prints & PICT_CAPABILITY_DEFAULT)
        {
            g_pict_bridge_setting.date_list[i++] = STR_GLOBAL_DEFAULT;
        }
        if (g_pict_bridge_xml.date_prints & PICT_CAPABILITY_OFF)
        {
            g_pict_bridge_setting.date_list[i++] = STR_GLOBAL_OFF;
        }
        if (g_pict_bridge_xml.date_prints & PICT_CAPABILITY_ON)
        {
            g_pict_bridge_setting.date_list[i++] = STR_GLOBAL_ON;
        }
        date_count = i;
    }

	return date_count;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_settings_pre_filename_list
 * DESCRIPTION
 *  Preparation for inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_pict_settings_pre_filename_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 filename_count = 1;
	U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	/* filename print */
    if (g_pict_bridge_xml.filename_prints == 0)
    {
        g_pict_bridge_setting.filename_list[0] = STR_GLOBAL_DEFAULT;
    }
    else if (g_pict_bridge_setting.layout != 0) /* multiple page per sheet */
    {
        g_pict_bridge_setting.filename_list[0] = STR_GLOBAL_DEFAULT;
        g_pict_bridge_setting.filename_print = 0;
    }
    else
    {
        i = 0;
        if (g_pict_bridge_xml.filename_prints & PICT_CAPABILITY_DEFAULT)
        {
            g_pict_bridge_setting.filename_list[i++] = STR_GLOBAL_DEFAULT;
        }
        if (g_pict_bridge_xml.filename_prints & PICT_CAPABILITY_OFF)
        {
            g_pict_bridge_setting.filename_list[i++] = STR_GLOBAL_OFF;
        }
        if (g_pict_bridge_xml.filename_prints & PICT_CAPABILITY_ON)
        {
            g_pict_bridge_setting.filename_list[i++] = STR_GLOBAL_ON;
        }
        filename_count = i;
    }

	return filename_count;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_settings_pre_cropping_list
 * DESCRIPTION
 *  Preparation for inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_pict_settings_pre_cropping_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 cropping_count = 1;
	U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	/* cropping */
    if (g_pict_bridge_xml.croppings == 0
#ifdef __MMI_FMGR_MULTI_SELECT_SUPPORT__
		||  g_pict_bridge_context.multi_file_select != 1
#endif
		)
    {
        g_pict_bridge_setting.cropping_list[0] = STR_GLOBAL_DEFAULT;
    }
    else
    {
        i = 0;
        if (g_pict_bridge_xml.croppings & PICT_CAPABILITY_DEFAULT)
        {
            g_pict_bridge_setting.cropping_list[i++] = STR_GLOBAL_DEFAULT;
        }
        if (g_pict_bridge_xml.croppings & PICT_CAPABILITY_OFF)
        {
            g_pict_bridge_setting.cropping_list[i++] = STR_GLOBAL_OFF;
        }
        if (g_pict_bridge_xml.croppings & PICT_CAPABILITY_ON)
        {
            g_pict_bridge_setting.cropping_list[i++] = STR_GLOBAL_ON;
        }
        cropping_count = i;
    }
	
	return cropping_count;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_set_settings_items
 * DESCRIPTION
 *  Entry function for print setting inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pict_set_settings_items_string(mmi_id gid, U16 item_id, S32 n_items, U16 *list, S32 highlight)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
	U8  i = 0;
    U8 *string_list[20] = {0}; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    for(i = 0; i < n_items; i++)
    {
        string_list[i] = (U8*)get_string(list[i]);  
    }
    cui_inline_set_item_select(gid, item_id, n_items, string_list, (U8)highlight);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_set_settings_items
 * DESCRIPTION
 *  Entry function for print setting inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pict_set_settings_items(mmi_id gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   	
    S32 n_items;
    pict_bridge_setting_struct *setting = &g_pict_bridge_setting;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(gid, PICT_SELECT_1, &setting->paper_size);
    cui_inline_get_value(gid, PICT_SELECT_2, &setting->number_of_copies);
    cui_inline_get_value(gid, PICT_SELECT_3, &setting->page_format);
    cui_inline_get_value(gid, PICT_SELECT_4, &setting->layout);
    cui_inline_get_value(gid, PICT_SELECT_5, &setting->border);
    cui_inline_get_value(gid, PICT_SELECT_6, &setting->date_print);
    cui_inline_get_value(gid, PICT_SELECT_7, &setting->filename_print);
    
#ifdef __MMI_PICT_BRIDGE_CROPPING__
    cui_inline_get_value(gid, PICT_SELECT_8, &setting->cropping);
#endif
	n_items = mmi_pict_settings_pre_paper_list();	
    mmi_pict_set_settings_items_string(gid, PICT_SELECT_1, n_items, setting->paper_list, setting->paper_size);

	n_items = mmi_pict_settings_pre_copies_list();	
    mmi_pict_set_settings_items_string(gid, PICT_SELECT_2, n_items, setting->copies_list, setting->number_of_copies);

	n_items = mmi_pict_settings_pre_format_list();	
    mmi_pict_set_settings_items_string(gid, PICT_SELECT_3, n_items, setting->format_list, setting->page_format);

	n_items = mmi_pict_settings_pre_layout_list();	
	mmi_pict_set_settings_items_string(gid, PICT_SELECT_4, n_items, setting->layout_list, setting->layout);

	n_items = mmi_pict_settings_pre_border_list();	
	mmi_pict_set_settings_items_string(gid, PICT_SELECT_5, n_items, setting->border_list, setting->border);

	n_items = mmi_pict_settings_pre_date_list();	
	mmi_pict_set_settings_items_string(gid, PICT_SELECT_6, n_items, setting->date_list, setting->date_print);

	n_items = mmi_pict_settings_pre_filename_list();	
	mmi_pict_set_settings_items_string(gid, PICT_SELECT_7, n_items, setting->filename_list, setting->filename_print);

#ifdef __MMI_PICT_BRIDGE_CROPPING__
	n_items = mmi_pict_settings_pre_cropping_list();	
    mmi_pict_set_settings_items_string(gid, PICT_SELECT_8, n_items, setting->cropping_list, setting->cropping);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_edit_print_settings_done
 * DESCRIPTION
 *  Completion function for inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_edit_print_settings_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PICT_BRIDGE_CROPPING__
    U8 check_value;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_pict_setting_save_prefer();

#ifdef __MMI_PICT_BRIDGE_CROPPING__
    check_value = (g_pict_bridge_xml.croppings & PICT_CAPABILITY_OFF) ? 2 : 1;

    if (g_pict_bridge_setting.cropping == check_value)
    {
        mmi_pict_get_file_dimension();

        g_pict_bridge_setting.x_coordinate = 0;
        g_pict_bridge_setting.y_coordinate = 0;
        g_pict_bridge_setting.x_arix = g_pict_bridge_context.image_width;
        g_pict_bridge_setting.y_arix = g_pict_bridge_context.image_height;
#ifdef __MMI_PICT_BRIDGE_CROPPING_CAT57__
        mmi_pict_entry_image_cropping();
#endif
#ifdef __MMI_PICT_BRIDGE_CROPPING_CAT88__
        mmi_pict_entry_image_cropping_phase1();
#endif
#if !defined(__MMI_PICT_BRIDGE_CROPPING_CAT57__) && !defined(__MMI_PICT_BRIDGE_CROPPING_CAT88__)
        MMI_ASSERT(0);
#endif
    }
    else
#endif /* __MMI_PICT_BRIDGE_CROPPING__ */
    {
        mmi_pict_entry_print_preview();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_setting_proc
 * DESCRIPTION
 *  screen group setting agent callback function
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_pict_get_setting_data(mmi_id gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	cui_inline_get_value(gid, PICT_SELECT_1, &g_pict_bridge_setting.paper_size);
    cui_inline_get_value(gid, PICT_SELECT_2, &g_pict_bridge_setting.number_of_copies);
    cui_inline_get_value(gid, PICT_SELECT_3, &g_pict_bridge_setting.page_format);
    cui_inline_get_value(gid, PICT_SELECT_4, &g_pict_bridge_setting.layout);
    cui_inline_get_value(gid, PICT_SELECT_5, &g_pict_bridge_setting.border);
    cui_inline_get_value(gid, PICT_SELECT_6, &g_pict_bridge_setting.date_print);
    cui_inline_get_value(gid, PICT_SELECT_7, &g_pict_bridge_setting.filename_print);

#ifdef __MMI_PICT_BRIDGE_CROPPING__
    cui_inline_get_value(gid, PICT_SELECT_8, &g_pict_bridge_setting.cropping);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_setting_proc
 * DESCRIPTION
 *  screen group setting agent callback function
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_pict_setting_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
	case EVT_ID_CUI_INLINE_SUBMIT :
	{
            cui_event_inline_submit_struct *submit_evt = (cui_event_inline_submit_struct*)evt;

	    mmi_pict_get_setting_data(submit_evt->sender_id);            
	    mmi_pict_edit_print_settings_done();
	    break;
	}

 	case EVT_ID_CUI_INLINE_CSK_PRESS:
	{
            cui_event_inline_csk_press_struct *csk_evt = (cui_event_inline_csk_press_struct*)evt;

	    mmi_pict_get_setting_data(csk_evt->sender_id);            
	    mmi_pict_edit_print_settings_done();
	    break;
	}

	case EVT_ID_CUI_INLINE_ABORT:
		{
			cui_event_inline_abort_struct *abort_evt = (cui_event_inline_abort_struct*)evt;
			cui_inline_close(abort_evt->sender_id);
            cui_pict_send_result_to_parent(CUI_PICT_RESULT_CANCEL);
			break;
		}
        
	case EVT_ID_CUI_INLINE_NOTIFY:
		{
			cui_event_inline_notify_struct *notify_evt = (cui_event_inline_notify_struct*)evt;			
            if (notify_evt->event_type == CUI_INLINE_NOTIFY_ITEM_CHANGED)
			{			
				switch (notify_evt->item_id)
				{
				case PICT_SELECT_1:                    
				case PICT_SELECT_3:                    
				case PICT_SELECT_4:                    
					mmi_pict_set_settings_items(notify_evt->sender_id);					
					break;

				default:
					break;
				}
			}					
		}
		break;
		
    default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_print_settings
 * DESCRIPTION
 *  Entry function for print setting inline editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_print_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
	mmi_id gid, inline_gid;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	gid = mmi_frm_group_create(g_pict_gid, GRP_ID_PICT_SETTING, mmi_pict_setting_proc, NULL);
    mmi_frm_group_enter(GRP_ID_PICT_SETTING, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	
	
	inline_gid = cui_inline_create(gid, &pict_setting_screen);
	cui_inline_set_title_icon(inline_gid, mmi_pict_return_title_icon());
    mmi_pict_set_settings_items(inline_gid);

	cui_inline_run(inline_gid);
}


#ifdef __MMI_PICT_BRIDGE_CROPPING__

#ifdef __MMI_PICT_BRIDGE_CROPPING_CAT57__
/*****************************************************************************
 * FUNCTION
 *  mmi_pict_x_coordinate_default
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*
 *****************************************************************************/
static U8* mmi_pict_x_coordinate_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    g_pict_bridge_setting.x_coordinate = 0;
    gui_itoa(g_pict_bridge_setting.x_coordinate, (UI_string_type) g_pict_bridge_setting.x_coordinate_display, 10);
    return g_pict_bridge_setting.x_coordinate_display;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_x_coordinate_decrease
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*
 *****************************************************************************/
static void mmi_pict_x_coordinate_decrease(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_setting.x_coordinate == 0)
    {
        g_pict_bridge_setting.x_coordinate = g_pict_bridge_context.image_width - 1;
    }
    else
    {
        g_pict_bridge_setting.x_coordinate--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_x_coordinate_increase
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*
 *****************************************************************************/
static void mmi_pict_x_coordinate_increase(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_setting.x_coordinate == g_pict_bridge_context.image_width - 1)
    {
        g_pict_bridge_setting.x_coordinate = 0;
    }
    else
    {
        g_pict_bridge_setting.x_coordinate++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_y_coordinate_default
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*
 *****************************************************************************/
static U8* mmi_pict_y_coordinate_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    g_pict_bridge_setting.y_coordinate = 0;
    gui_itoa(g_pict_bridge_setting.y_coordinate, (UI_string_type) g_pict_bridge_setting.y_coordinate_display, 10);
    return g_pict_bridge_setting.y_coordinate_display;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_y_coordinate_decrease
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*
 *****************************************************************************/
static void mmi_pict_y_coordinate_decrease(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_setting.y_coordinate == 0)
    {
        g_pict_bridge_setting.y_coordinate = g_pict_bridge_context.image_height - 1;
    }
    else
    {
        g_pict_bridge_setting.y_coordinate--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_y_coordinate_increase
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*
 *****************************************************************************/
static void mmi_pict_y_coordinate_increase(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_setting.y_coordinate == g_pict_bridge_context.image_height - 1)
    {
        g_pict_bridge_setting.y_coordinate = 0;
    }
    else
    {
        g_pict_bridge_setting.y_coordinate++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_x_arix_default
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*
 *****************************************************************************/
static U8* mmi_pict_x_arix_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_setting.x_coordinate + g_pict_bridge_setting.x_arix > g_pict_bridge_context.image_width)
    {
        g_pict_bridge_setting.x_arix = g_pict_bridge_context.image_width - g_pict_bridge_setting.x_coordinate;
    }
    gui_itoa(g_pict_bridge_setting.x_arix, (UI_string_type) g_pict_bridge_setting.x_arix_display, 10);
    return g_pict_bridge_setting.x_arix_display;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_x_arix_decrease
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*
 *****************************************************************************/
static void mmi_pict_x_arix_decrease(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_setting.x_arix > 1)
    {
        g_pict_bridge_setting.x_arix--;
    }
    else
    {
        g_pict_bridge_setting.x_arix = g_pict_bridge_context.image_width - g_pict_bridge_setting.x_coordinate;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_x_arix_increase
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*
 *****************************************************************************/
static void mmi_pict_x_arix_increase(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_setting.x_coordinate + g_pict_bridge_setting.x_arix < g_pict_bridge_context.image_width)
    {
        g_pict_bridge_setting.x_arix++;
    }
    else
    {
        g_pict_bridge_setting.x_arix = 1;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_y_arix_default
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*
 *****************************************************************************/
static U8* mmi_pict_y_arix_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_setting.y_coordinate + g_pict_bridge_setting.y_arix > g_pict_bridge_context.image_height)
    {
        g_pict_bridge_setting.y_arix = g_pict_bridge_context.image_height - g_pict_bridge_setting.y_coordinate;
    }
    gui_itoa(g_pict_bridge_setting.y_arix, (UI_string_type) g_pict_bridge_setting.y_arix_display, 10);
    return g_pict_bridge_setting.y_arix_display;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_y_arix_decrease
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*
 *****************************************************************************/
static void mmi_pict_y_arix_decrease(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_setting.y_arix > 1)
    {
        g_pict_bridge_setting.y_arix--;
    }
    else
    {
        g_pict_bridge_setting.y_arix = g_pict_bridge_context.image_height - g_pict_bridge_setting.y_coordinate;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_y_arix_increase
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*
 *****************************************************************************/
static void mmi_pict_y_arix_increase(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_pict_bridge_setting.y_coordinate + g_pict_bridge_setting.y_arix < g_pict_bridge_context.image_height)
    {
        g_pict_bridge_setting.y_arix++;
    }
    else
    {
        g_pict_bridge_setting.y_arix = 1;
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_cropping_proc
 * DESCRIPTION
 *  screen group setting agent callback function
 * PARAMETERS
 *  evt        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_pict_cropping_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
	case EVT_ID_CUI_INLINE_SUBMIT :
		{
			mmi_pict_entry_print_preview();		
		    break;
		}

	case EVT_ID_CUI_INLINE_ABORT:
		{
			cui_event_inline_abort_struct *abort_evt = (cui_event_inline_abort_struct*)evt;
			cui_inline_close(abort_evt->sender_id);
			break;
		}
	case EVT_ID_CUI_INLINE_NOTIFY:
		{
			cui_event_inline_notify_struct *notify_evt = (cui_event_inline_notify_struct*)evt;		
			if (notify_evt->event_type == CUI_INLINE_NOTIFY_USER_DEFINED_SELECT_SET_FOCUS)
			{			
				switch (notify_evt->item_id)
				{
				case PICT_CROPPING_SEL1:
					if (notify_evt->param == CUI_INLINE_USERDEFINEDSELECT_NEXT)
					{
						mmi_pict_x_coordinate_increase();
					}
					else if (notify_evt->param == CUI_INLINE_USERDEFINEDSELECT_PRE)
					{
						mmi_pict_x_coordinate_decrease();
					}
					cui_inline_redraw_screen(notify_evt->sender_id);
					return (mmi_ret)mmi_pict_x_coordinate_default();
					
                case PICT_CROPPING_SEL2:
                    if (notify_evt->param == CUI_INLINE_USERDEFINEDSELECT_NEXT)
                    {
                        mmi_pict_y_coordinate_increase();
                    }
                    else if (notify_evt->param == CUI_INLINE_USERDEFINEDSELECT_PRE)
                    {
                        mmi_pict_y_coordinate_decrease();
                    }
                    cui_inline_redraw_screen(notify_evt->sender_id);
                    return (mmi_ret)mmi_pict_y_coordinate_default();
					
                case PICT_CROPPING_SEL3:
                    if (notify_evt->param == CUI_INLINE_USERDEFINEDSELECT_NEXT)
                    {
                        mmi_pict_x_arix_increase();
                    }
                    else if (notify_evt->param == CUI_INLINE_USERDEFINEDSELECT_PRE)
                    {
                        mmi_pict_x_arix_decrease();
                    }
                    
                    return (mmi_ret)mmi_pict_x_arix_default();
                    
                case PICT_CROPPING_SEL4:				
                    if (notify_evt->param == CUI_INLINE_USERDEFINEDSELECT_NEXT)
                    {
                        mmi_pict_y_arix_increase();
                    }
                    else if (notify_evt->param == CUI_INLINE_USERDEFINEDSELECT_PRE)
                    {
                        mmi_pict_y_arix_decrease();
                    }
                    
                    return (mmi_ret)mmi_pict_y_arix_default();
                    
				default:
					break;
				}
			}					
		}
		break;
	
    default:
        break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_image_cropping
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_image_cropping(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id inline_gid, gid;		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gid = mmi_frm_group_create(GRP_ID_PICT_SETTING, GRP_ID_AUTO_GEN, mmi_pict_cropping_proc, NULL);
    mmi_frm_group_enter(gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

	inline_gid = cui_inline_create(gid, &pict_cropping_screen);
	cui_inline_set_title_icon(inline_gid, mmi_pict_return_title_icon());
	
	cui_inline_run(inline_gid);
}
#endif /* __MMI_PICT_BRIDGE_CROPPING_CAT57__ */


#ifdef __MMI_PICT_BRIDGE_CROPPING_CAT88__
/*****************************************************************************
 * FUNCTION
 *  mmi_pict_display_x_coordinate_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pict_display_x_coordinate_callback(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pict_bridge_setting.x_coordinate = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_display_y_coordinate_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pict_display_y_coordinate_callback(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pict_bridge_setting.y_coordinate = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_display_x_arix_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pict_display_x_arix_callback(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pict_bridge_setting.x_arix = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_display_y_arix_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pict_display_y_arix_callback(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_pict_bridge_setting.y_arix = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_image_cropping_phase1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_image_cropping_phase1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 lower_limit[2];
    S32 upper_limit[2];
    S32 *current_value[2];
    void (*cb_func[2]) (S32 value);
    U8 *str_list[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(GRP_ID_PICT_SETTING, SCR_ID_PICT_CROPPING_PHASE1, NULL, mmi_pict_entry_image_cropping_phase1, 0))
        return;

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();;
    SetParentHandler(0);

    lower_limit[0] = 0;
    upper_limit[0] = g_pict_bridge_context.image_width - 1;
    current_value[0] = &g_pict_bridge_setting.x_coordinate;
    cb_func[0] = mmi_pict_display_x_coordinate_callback;
    str_list[0] = (U8*) GetString(STR_ID_PICT_X_COORDINATE);

    lower_limit[1] = 0;
    upper_limit[1] = g_pict_bridge_context.image_height - 1;
    current_value[1] = &g_pict_bridge_setting.y_coordinate;
    cb_func[1] = mmi_pict_display_y_coordinate_callback;
    str_list[1] = (U8*) GetString(STR_ID_PICT_Y_COORDINATE);

    ShowCategory88Screen(
        STR_ID_PICT_CROPPING,
        mmi_pict_return_title_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        0,
        2,
        str_list,
        lower_limit,
        upper_limit,
        current_value,
        cb_func,
        guiBuffer);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    SetLeftSoftkeyFunction(mmi_pict_entry_image_cropping_phase2, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_pict_entry_image_cropping_phase2, KEY_EVENT_UP);
    SetRightSoftkeyFunction( mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pict_entry_image_cropping_phase2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_entry_image_cropping_phase2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 lower_limit[2];
    S32 upper_limit[2];
    S32 *current_value[2];
    void (*cb_func[2]) (S32 value);
    U8 *str_list[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(g_pict_gid, SCR_ID_PICT_CROPPING_PHASE2, NULL, mmi_pict_entry_image_cropping_phase2, 0))
        return;
    
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();;
    SetParentHandler(0);

    lower_limit[0] = 1;
    upper_limit[0] = g_pict_bridge_context.image_width - g_pict_bridge_setting.x_coordinate;
    g_pict_bridge_setting.x_arix = g_pict_bridge_context.image_width - g_pict_bridge_setting.x_coordinate;
    current_value[0] = &g_pict_bridge_setting.x_arix;
    cb_func[0] = mmi_pict_display_x_arix_callback;
    str_list[0] = (U8*) GetString(STR_ID_PICT_X_ARIX);

    lower_limit[1] = 1;
    upper_limit[1] = g_pict_bridge_context.image_height - g_pict_bridge_setting.y_coordinate;
    g_pict_bridge_setting.y_arix = g_pict_bridge_context.image_height - g_pict_bridge_setting.y_coordinate;
    current_value[1] = &g_pict_bridge_setting.y_arix;
    cb_func[1] = mmi_pict_display_y_arix_callback;
    str_list[1] = (U8*) GetString(STR_ID_PICT_Y_ARIX);

    ShowCategory88Screen(
        STR_ID_PICT_CROPPING,
        mmi_pict_return_title_icon(),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        0,
        2,
        str_list,
        lower_limit,
        upper_limit,
        current_value,
        cb_func,
        guiBuffer);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    SetLeftSoftkeyFunction(mmi_pict_entry_print_preview, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_pict_entry_print_preview, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif /* __MMI_PICT_BRIDGE_CROPPING_CAT88__ */

#endif /* __MMI_PICT_BRIDGE_CROPPING__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_get_index
 * DESCRIPTION
 * get index, from 0 
 * PARAMETERS
 * i
 * RETURNS
 *  index
 *****************************************************************************/
static U32 mmi_pict_get_index(U32 i)
{
    U32 ret = 0;

    while (i >>= 1)
        ret++;
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_get_match_index
 * DESCRIPTION
 * get index, from 0 
 * PARAMETERS
 * i
 * RETURNS
 *  index
 *****************************************************************************/
static S32 mmi_pict_get_match_index(U32 c, U32 v)
{
    S32 ret = 0;
    U32 test = 1;
    U32 n;

    if (!(c & v))
        return 0;

    for (n = 0; test < v && n < 32; n++)
    {
        if (test & c)
            ret++;
        test <<= 1;
    }
    
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_get_match_value
 * DESCRIPTION
 * get match value 
 * PARAMETERS
 * i
 * RETURNS
 *  value
 *****************************************************************************/
static U32 mmi_pict_get_match_value(U32 c, S32 i)
{
    U32 test_value = 1;
    S32 test_index = 0;
    U32 n;

    for (n = 0; n < 32; n++)
    {
        if (test_value & c)
        {
            if (test_index == i)
            {
                return test_value;
            }
            test_index++;
        }
        test_value <<= 1;
    }

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_get_match_pos
 * DESCRIPTION
 *  get index in @c of @i
 * PARAMETERS
 *  void
 * RETURNS
 *  position
 *****************************************************************************/
static U32 mmi_pict_get_match_pos(U32 c, S32 i)
{
    U32 test_value = 1;
    S32 test_index = 0;
    U32 n;

    for (n = 0; n < 32; n++)
    {
        if (test_value & c)
        {
            if (test_index == i)
            {
                return n;
            }
            test_index++;
        }
        test_value <<= 1;
    }

    return 0;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_pict_setting_save_as_prefer
 * DESCRIPTION
 *  save current setting as preference
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pict_setting_save_prefer(void)
{
    S16 error;
    pict_bridge_preference_nvram_struct* p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (pict_bridge_preference_nvram_struct*)OslMalloc(NVRAM_EF_PICTBRIDGE_SIZE);

    p->flag = 1;
        
    if (g_pict_bridge_context.printing_capability[1] == 0) /* 1 -> paper size */
    {
        p->paper_size = mmi_pict_get_match_value(
            g_pict_bridge_xml.paper_sizes,
            g_pict_bridge_setting.paper_size);        
    }
    else
    {
        p->paper_size = 0;
    }

    p->copies = g_pict_bridge_setting.number_of_copies;
    p->page_format = g_pict_bridge_setting.page_format;
    
    /* here we think if printer support layout, then  it must support paper size! */
    if (g_pict_bridge_context.printing_capability[7] == 0) /* 7 -> layouts */
    {
        p->layout = mmi_pict_get_match_value(
            g_pict_bridge_xml.layouts[mmi_pict_get_index(p->paper_size)],
            g_pict_bridge_setting.layout);
    }
    else
    {
        p->layout = 0;
    }
    
    if (g_pict_bridge_setting.border == 1)
    {
        p->border = PICT_LAYOUT_FULL;
    }
    else
    {
        p->border = 0;
    }
    
    if (g_pict_bridge_context.printing_capability[4] == 0) /* 4 ->dataPrints */
    {
        p->date_print = mmi_pict_get_match_value(
            g_pict_bridge_xml.date_prints,
            g_pict_bridge_setting.date_print);
    }
    else
    {
        p->date_print = 0;
    }

    if (g_pict_bridge_context.printing_capability[5] == 0) /* 5 -> filenamePrints */
    {
        p->filename_print = mmi_pict_get_match_value(
            g_pict_bridge_xml.filename_prints,
            g_pict_bridge_setting.filename_print);
    }
    else
    {
        p->filename_print = 0;
    }

    WriteRecord(NVRAM_EF_PICTBRIDGE_LID, 1, (void*)p, NVRAM_EF_PICTBRIDGE_SIZE, &error);

    OslMfree(p);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_set_preference
 * DESCRIPTION
 * import preferred print setting
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pict_set_preference(pict_bridge_preference_nvram_struct* p)
{
    if (p->paper_size)
    {
        g_pict_bridge_setting.paper_size = mmi_pict_get_match_index(
            g_pict_bridge_xml.paper_sizes,
            p->paper_size);
    }
    else
    {
        p->paper_size = 1; /* use to get layout */
    }

    /* always set @copies to 1 
    g_pict_bridge_setting.number_of_copies = p->copies; */
    g_pict_bridge_setting.page_format = p->page_format;
    
    if (p->layout)
    {
        g_pict_bridge_setting.layout = mmi_pict_get_match_index(
            g_pict_bridge_xml.layouts[mmi_pict_get_index(p->paper_size)],
            p->layout);
    }
    
    if (p->border == PICT_LAYOUT_FULL)
    {        
        g_pict_bridge_setting.border = 1;
    }

    if (p->date_print && g_pict_bridge_setting.layout == 0)
    {
        g_pict_bridge_setting.date_print =  mmi_pict_get_match_index(
            g_pict_bridge_xml.date_prints,
            p->date_print);        
    }

    if (p->filename_print && g_pict_bridge_setting.layout == 0)
    {
        g_pict_bridge_setting.filename_print =  mmi_pict_get_match_index(
            g_pict_bridge_xml.filename_prints,
            p->filename_print);        
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_pict_check_preference
 * DESCRIPTION
 * check preference validation in new printer 
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pict_check_preference(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    pict_bridge_preference_nvram_struct* p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (0) /* temp used to remove saving setting featuer */
    {

    p = (pict_bridge_preference_nvram_struct*)OslMalloc(NVRAM_EF_PICTBRIDGE_SIZE);
    ReadRecord(NVRAM_EF_PICTBRIDGE_LID, 1, (void*)p, NVRAM_EF_PICTBRIDGE_SIZE, &error);
    if (p->flag) /* if has save preference */
    {
        /* if preference is zero, then do not check */
        if ((p->paper_size && !(p->paper_size & g_pict_bridge_xml.paper_sizes)) ||
            (p->layout && !(p->layout & g_pict_bridge_xml.layouts[mmi_pict_get_index(p->paper_size)])) ||
            (p->border && !(p->border & g_pict_bridge_xml.layouts[mmi_pict_get_index(p->paper_size)])) ||
            (p->date_print && !(p->date_print & g_pict_bridge_xml.date_prints)) ||
            (p->filename_print &&!(p->filename_print &g_pict_bridge_xml.filename_prints)))
        {
            g_pict_bridge_setting.if_prefer_invalid = 1;
        }
        else
        {
            mmi_pict_set_preference(p);
        }
    }
    OslMfree(p);

    }
}

#endif /* __MMI_PICT_BRIDGE_SUPPORT__ */

