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
 * VoiceDial.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for Voice Dialing.
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
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"
#ifndef _MMI_VRSDDIAL_C
#define _MMI_VRSDDIAL_C

#if defined(__MMI_VRSD__) && defined(__MMI_VRSD_DIAL__)

/*  Include: MMI header file */
#include "CommonScreens.h"
#include "nvram_user_defs.h"
#include "MessagesExDcl.h"

/* Med */
#include "med_global.h"
#include "med_struct.h"
#include "med_api.h"
#include "med_main.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"

#include "VRSDResDef.h"
#include "VRSD.h"
#include "VRSDDial.h"

#include "PhonebookGProt.h"
#include "SettingProfileEnum.h"
#include "PhonebookResDef.h"
#include "PhbSrvGprot.h"

#include "SettingDefs.h"        /* For FDN on Message */
#include "SettingsGdcl.h"
#include "MainMenuDef.h"

#include "SSCStringHandle.h"
#include "USBDeviceGprot.h"
//#include "SimDetectionGprot.h"

#include "UCMGProt.h"
#include "BtcmSrvGprot.h"

/* 
 * Typedef 
 */
typedef enum
{
    MMI_VRSD_DIAL_MENU_ALL,
    MMI_VRSD_DIAL_MENU_ADD_ONLY,
    MMI_VRSD_DIAL_MENU_CHANGE_DEL
} vrsddial_menu_type_enum;

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif
extern pBOOL mmi_bootup_is_sim_valid(void);

/* 
 * Global Function
 */
#ifdef __GEMINI__
extern smu_sim_status_enum check_sim_status(kal_uint8 simInterface);
#else
extern smu_sim_status_enum check_sim_status(void);
#endif

typedef struct vrsd_dial_list
{	
	U16 		*p_name;
	U8			**p_str;
	U16 		*p_icon;
	U16         *p_index;
	U32			total;
	U16 		highlight;
	U16         cur_store_index;
	MMI_BOOL	allocated;
}vrsd_dial_list;

/* 
 * Local Variable
 */
static vrsd_dial_list g_vrsd_dial_list;
static U16 g_vrsddial_store_index;

/* 
 * Local Function
 */
static void mmi_vrsddial_highlight_option_add(void); 
static void mmi_vrsddial_highlight_option_change(void);
static void mmi_vrsddial_highlight_option_del(void);
static void mmi_vrsddial_entry_list(void);
static void mmi_vrsddial_exit_list(void);

static void mmi_vrsddial_list_highlight_hdlr(S32 index);
static void mmi_vrsddial_entry_tag_option(void);
static void mmi_vrsddial_list_playback_tag(void);
static void mmi_vrsddial_del_tag_confirm(void);
static void mmi_vrsddial_del_tag(void); 

static MMI_BOOL mmi_vrsddial_alloc_dial_list(void);
static void mmi_vrsddial_free_dail_list(void);
static void mmi_vrsddial_delete_all_tag_in_sim_no(void);
static pBOOL mmi_vrsddial_get_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);

/* 
 * Global Variable
 */
/* 
 * Global Function
 */

#define MMI_VRSD_DIAL_INIT


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_init
 * DESCRIPTION
 *  This function initialize Voice Dial application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsddial_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_vrsd_register_rcg_callback(MMI_VRSD_APP_DIAL, mmi_vrsddial_rcg_callback);

    mmi_vrsddial_init_highlight_handler();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_init_highlight_handler
 * DESCRIPTION
 *  This function initialize Voice Dial application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsddial_init_highlight_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetHiliteHandler(MENU_ID_VRSD_DIAL, mmi_vrsddial_highlight_app);
   
    SetHiliteHandler(MENU_ID_VRSD_DIAL_MAIN_ADD, mmi_vrsddial_highlight_option_add);
    SetHiliteHandler(MENU_ID_VRSD_DIAL_MAIN_CHANGE, mmi_vrsddial_highlight_option_change);
    SetHiliteHandler(MENU_ID_VRSD_DIAL_MAIN_DELETE, mmi_vrsddial_highlight_option_del);
}

#define MMI_VRSD_DIAL_LIST
/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_alloc_dial_list
 * DESCRIPTION
 *  mmi_vrsddial_alloc_dial_list
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_vrsddial_alloc_dial_list(void)
{
    vrsd_tag_struct tag_list[MMI_VRSD_MAX_TAG];
	U16 *p_name;
	U8 **p_str;
	U16 *p_icon;
	U16	*p_index;
	U32 i;
	U32 size;
	U16 str_id;
	U16 appref_id;
	S16 pError;
	S32 ret;
	MMI_BOOL result;
    U32  name_size;

    name_size = 2 + ((MMI_PHB_NAME_LENGTH >= MMI_PHB_NUMBER_LENGTH? MMI_PHB_NAME_LENGTH : MMI_PHB_NUMBER_LENGTH ));

	g_vrsd_dial_list.allocated = MMI_FALSE;
    size = g_vrsd_dial_list.total;
	p_name = (U16 *)mmi_frm_scrmem_alloc_framebuffer(sizeof(U16) * size * name_size);	
	if (p_name == NULL)
	{
		return MMI_FALSE;
	}
	memset((S8 *)p_name, 0, sizeof(U16) * size * name_size);
	
	p_str = (U8 **)mmi_frm_scrmem_alloc_framebuffer(sizeof(U8 *) * size);	
	if (p_str == NULL)
	{
		mmi_frm_scrmem_free(p_name);
		return MMI_FALSE;
	}
	memset((S8 *)p_str, 0, sizeof(U8 *) * size);
	
	p_icon = (U16 *)mmi_frm_scrmem_alloc_framebuffer(sizeof(U16) * size);
	if (p_icon == NULL)
	{
		mmi_frm_scrmem_free(p_name);
		mmi_frm_scrmem_free(p_str);
		return MMI_FALSE;
	}
	memset((S8 *)p_icon, 0, sizeof(U16) * size);

	p_index = (U16 *)mmi_frm_scrmem_alloc_framebuffer(sizeof(U16) * size);
	if (p_index == NULL)
	{
		mmi_frm_scrmem_free(p_name);
		mmi_frm_scrmem_free(p_str);
		mmi_frm_scrmem_free(p_icon);
		return MMI_FALSE;
	}
	memset((S8 *)p_index, 0, sizeof(U16) * size);
	

	g_vrsd_dial_list.allocated = MMI_TRUE;
	g_vrsd_dial_list.p_name = p_name;	
	g_vrsd_dial_list.p_icon = p_icon;	
	g_vrsd_dial_list.p_str  = p_str;
	g_vrsd_dial_list.p_index = p_index;
	
	for (i = 0; i < size; i++)
	{
		g_vrsd_dial_list.p_str[i] = (U8 *)(p_name + i * name_size);		
	}
	
	ret = srv_phb_oplib_build_contact_list(NULL, p_index, MMI_PHB_ENTRIES);
	if (ret <= 0 || ret > MMI_PHB_ENTRIES)
	{
		mmi_vrsddial_free_dail_list();
		return MMI_FALSE;
	}

	if (ret <= size)
	{
		g_vrsd_dial_list.total = size = ret;
	}
	
  /* Read Voice Tag List */
    ReadRecord(NVRAM_EF_VRSD_TAG_LID, 1, (void*)tag_list, MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct), &pError);
    
	for (i = 0; i < size; i++)
	{
		result = srv_phb_get_name(p_index[i], (U16 *)p_str[i], MMI_PHB_NAME_LENGTH);	
		if (p_str[i][0] == 0 &&  p_str[i][1] == 0)
		{
		    result = srv_phb_get_number(p_index[i], (U16 *)p_str[i], MMI_PHB_NUMBER_LENGTH);
		}
		if (mmi_vrsd_util_get_tag_id_in_list(MMI_VRSD_APP_DIAL, p_index[i], tag_list) != 0xFFFF)
		{
		 	p_icon[i] = IMG_ID_VRSD_APP; 
		}
		else
		{
           p_icon[i] = IMG_ID_VRSD_SHORTCUT; 
		}
	}
	return MMI_TRUE;

}
/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_free_dail_list
 * DESCRIPTION
 *  mmi_vrsddial_free_dail_list
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_vrsddial_free_dail_list(void)
{
	
	if (g_vrsd_dial_list.allocated)
	{
		mmi_frm_scrmem_free(g_vrsd_dial_list.p_icon);
		mmi_frm_scrmem_free(g_vrsd_dial_list.p_name);
		mmi_frm_scrmem_free(g_vrsd_dial_list.p_str);
		mmi_frm_scrmem_free(g_vrsd_dial_list.p_index);
		g_vrsd_dial_list.p_icon = NULL;
		g_vrsd_dial_list.p_name = NULL;
		g_vrsd_dial_list.p_str = NULL;
		g_vrsd_dial_list.p_index = NULL;
		g_vrsd_dial_list.allocated = MMI_FALSE;		
	}

}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_highlight_app
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_highlight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_vrsddial_entry_list, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsddial_entry_list, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_channel_list_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 *  
 *****************************************************************************/
static pBOOL mmi_vrsddial_get_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2ncpy((S8*) str_buff, (S8*)g_vrsd_dial_list.p_str[item_index], MAX_SUBMENU_CHARACTERS);
    /* show order icon */
    *img_buff_p = (PU8) GetImage((U16) g_vrsd_dial_list.p_icon[item_index]);

    return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_entry_list
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_entry_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
	MMI_BOOL ret;
	S32 r;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_phb_check_ready(MMI_TRUE))
    {
    	return;
    }
    r = srv_phb_get_used_contact(PHB_STORAGE_MAX);
	if (r <= 0)
	{
		g_vrsd_dial_list.total = 0;
		mmi_display_popup(
			(UI_string_type)GetString(STR_GLOBAL_EMPTY),
			MMI_EVENT_FAILURE);	
		return;
	}
	else
	{
		g_vrsd_dial_list.total = (U16)r; 
	}
	
    EntryNewScreen(SCR_ID_VRSD_DIAL_EMPTY_LIST, mmi_vrsddial_exit_list, mmi_vrsddial_entry_list, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VRSD_DIAL_EMPTY_LIST);  

    ret = mmi_vrsddial_alloc_dial_list();
    if (!ret)
    {
		mmi_display_popup(
			(UI_string_type)GetString(STR_GLOBAL_ERROR),
			MMI_EVENT_FAILURE);	

		DeleteScreenIfPresent(SCR_ID_VRSD_DIAL_EMPTY_LIST);
		DeleteScreenIfPresent(SCR_ID_VRSD_DIAL_MAIN_MENU);
		return;
    }

    if (guiBuffer == NULL)
    {
        g_vrsd_dial_list.highlight = 0;
		
    }
    else
    {
    	if (g_vrsd_dial_list.highlight >= g_vrsd_dial_list.total)
    	{
    		g_vrsd_dial_list.highlight = 0;	
    	}
    }
	g_vrsd_dial_list.cur_store_index = g_vrsd_dial_list.p_index[g_vrsd_dial_list.highlight];

	
	RegisterHighlightHandler(mmi_vrsddial_list_highlight_hdlr);


    ShowCategory184Screen(
		STR_ID_VRSD_DIAL,
		MAIN_MENU_TITLE_MULTIMEDIA_ICON,
		STR_GLOBAL_OPTIONS,
		IMG_GLOBAL_OPTIONS,
		STR_GLOBAL_BACK,
		IMG_GLOBAL_BACK,
		g_vrsd_dial_list.total,
        mmi_vrsddial_get_list_item,
        NULL,
        g_vrsd_dial_list.highlight,
        guiBuffer);

	
    SetLeftSoftkeyFunction(mmi_vrsddial_entry_tag_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    SetKeyHandler(mmi_vrsddial_entry_tag_option, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_exit_list
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_exit_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(VRSD_DIAL_PLAYBACK_TIMER);
    mmi_vrsddial_free_dail_list();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_list_highlight_hdlr
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  index       [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_list_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsd_dial_list.highlight = (U16) index;
	g_vrsd_dial_list.cur_store_index = g_vrsd_dial_list.p_index[index];

    StopTimer(VRSD_DIAL_PLAYBACK_TIMER);
    StartTimer(VRSD_DIAL_PLAYBACK_TIMER, MMI_VRSD_PLAY_TAG_DELAY, mmi_vrsddial_list_playback_tag);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_list_playback_tag
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_list_playback_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tag_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tag_id = mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_DIAL, g_vrsd_dial_list.cur_store_index);
    if (tag_id != 0xffff)
    {
        mmi_vrsd_playback_req(tag_id, NULL);
    }
}


#define MMI_VRSD_DIAL_OPTION


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_highlight_option_add
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_highlight_option_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vrsddial_add_tag, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_highlight_option_change
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_highlight_option_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vrsddial_change_tag, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_highlight_option_del
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_highlight_option_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_vrsddial_del_tag_confirm, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_entry_tag_option
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_entry_tag_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nStrItemList[4];
    U16 nNumofItem;

    U32 HideItemId = -1;
    U32 maskingByte = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VRSD_DIAL_MAIN_MENU, NULL, mmi_vrsddial_entry_tag_option, NULL);
   
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VRSD_DIAL_MAIN_MENU);
    SetParentHandler(MENU_ID_VRSD_DIAL_MAIN_MENU);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* Register all highlight handler again, because RsetBit() may change the highlight handler when hide menu. */
    mmi_vrsddial_init_highlight_handler();

    /* Display Change and Delete. */
	 mmi_frm_unhide_menu_item(MENU_ID_VRSD_DIAL_MAIN_ADD);
    if (mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_DIAL, g_vrsd_dial_list.cur_store_index) != 0xffff)
    {
        mmi_frm_hide_menu_item(MENU_ID_VRSD_DIAL_MAIN_ADD);
    }

    nNumofItem = GetNumOfChild_Ext(MENU_ID_VRSD_DIAL_MAIN_MENU);
    GetSequenceStringIds_Ext(MENU_ID_VRSD_DIAL_MAIN_MENU, nStrItemList);
    
    if (mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_DIAL, g_vrsd_dial_list.cur_store_index) == 0xffff)
    {
        nNumofItem = 1; /* Display add only */
    }

    ShowCategory15Screen(
        STR_ID_VRSD_DIAL,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        LIST_MENU,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_add_tag
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_add_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_vrsd_cntx.vrtag_id = mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_NONE, 0xffff)) != 0xffff) /* Use 0xffff as parameter to get "empty tag id" */
    {
    	
        mmi_vrsd_train_init(MMI_VRSD_APP_DIAL, g_vrsd_dial_list.cur_store_index, mmi_vrsddial_train_result_callback);
    }
    else    /* No empty tag available */
    {
    	//failure
		mmi_display_popup(
			(UI_string_type)GetString(STR_ID_VRSD_NO_EMPTY_TAG),
			MMI_EVENT_FAILURE);
       
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_change_tag
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_change_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_vrsd_cntx.vrtag_id = mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_DIAL, g_vrsd_dial_list.cur_store_index)) != 0xffff)
    {
        mmi_vrsd_train_init(MMI_VRSD_APP_DIAL, g_vrsd_dial_list.cur_store_index, mmi_vrsddial_train_result_callback);
    }
    else
    {
    	//failure
		mmi_display_popup(
			(UI_string_type)GetString(STR_GLOBAL_EMPTY),
			MMI_EVENT_FAILURE);
      
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_train_result_callback
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  result      [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_train_result_callback(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MMI_VRSD_TRN_SUCCESS)
    {
    	//success
	mmi_display_popup(
			(UI_string_type)GetString(STR_GLOBAL_DONE),
			MMI_EVENT_SUCCESS);
       
    }
    else
    {
    	//failure
		mmi_display_popup(
			(UI_string_type)GetString(STR_GLOBAL_FAILURE),
			MMI_EVENT_FAILURE);
      
    }
    DeleteUptoScrID(SCR_ID_VRSD_DIAL_EMPTY_LIST); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_del_tag_confirm
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_del_tag_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_display_popup_confirm(
            (UI_string_type)GetString(STR_GLOBAL_YES),
            (PU8)GetImage(IMG_GLOBAL_YES),
            (UI_string_type)GetString(STR_GLOBAL_NO),
            (PU8)GetImage(IMG_GLOBAL_NO),
            (UI_string_type)GetString(STR_ID_VRSD_DELETE_TAG_QUESTION),
            MMI_EVENT_QUERY);


    SetLeftSoftkeyFunction(mmi_vrsddial_del_tag, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_del_tag
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_del_tag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tag_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((tag_id = mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_DIAL, g_vrsd_dial_list.cur_store_index)) != 0xffff)
    {
        mmi_vrsd_del_tag_req(tag_id);
    }
    else
    {
    	//failure
		mmi_display_popup(
			(UI_string_type)GetString(STR_GLOBAL_EMPTY),
			MMI_EVENT_FAILURE);
       
    }

    DeleteUptoScrID(SCR_ID_VRSD_DIAL_EMPTY_LIST); 
}

#define MMI_VRSD_DIAL_RCG
/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_rcg_callback
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  appref_id     [IN]            
 *  a(?)            [IN/OUT]        First variable, used as returns
 *  b(?)            [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_rcg_callback(U16 appref_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if phonebook is ready */
	if (!mmi_phb_check_ready(MMI_TRUE))
	{
		return;
	}
	
    /* check if sim valid */
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#else
    if (!(mmi_bootup_is_sim_valid()))
#endif
    {
		mmi_display_popup(
			(UI_string_type)GetString(STR_GLOBAL_INVALID),
			MMI_EVENT_FAILURE);
		return;
        
    }
    
    /* check tag mapping exists first. */
    if ((appref_id != 0xffff) && srv_phb_check_entry_exist(appref_id))
    {
        g_vrsddial_store_index = appref_id;
        /* playback */
        mmi_vrsd_playback_req(g_vrsd_cntx.vrtag_id, NULL);

        /* Entry Found Screen and dial out. */
        mmi_vrsddial_entry_rcg_found();
        return;
    }
    
    /* Phonebook entry not exists. Need to do more prompt here? */    
    mmi_vrsd_error_popup((U16) MED_RES_NO_MATCH);//failure 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_entry_rcg_found
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_entry_rcg_found(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S8 str_found[127 + 127 + 2];
	U16 str_len;
	U16 name_len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_VRSD_RCG_FOUND, mmi_vrsddial_exit_rcg_found, NULL, NULL);
    guiBuffer = GetCurrGuiBuffer(SCR_ID_VRSD_RCG_FOUND);

    mmi_ucs2cpy(str_found, GetString(STR_ID_VRSD_DIAL_FOUND));
	str_len = mmi_ucs2strlen(str_found);

	srv_phb_get_name(g_vrsddial_store_index, (U16 *)&str_found[str_len * 2], 127 - str_len);

    mmi_ucs2cat(str_found, (S8*) L"\n");
    mmi_ucs2cat(str_found, GetString(STR_ID_VRSD_DIAL_AUTO_DIAL));

    ShowCategory66Screen(
        STR_ID_VRSD_DIAL,
        MAIN_MENU_TITLE_MULTIMEDIA_ICON,
        STR_GLOBAL_DIAL,    /* LSK STR */
        0,                  /* LSK IMG */
        STR_GLOBAL_CANCEL,   /* RSK STR */
        0,                  /* RSK IMG */
        (U8*) str_found,    /* message string */
        IMG_GLOBAL_PROGRESS,                  /* icon id */
        guiBuffer);

    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_vrsddial_rcg_auto_dial, KEY_EVENT_UP);

    if (guiBuffer == NULL)
    {
        /* Automatically Dial out */
        StopTimer(VRSD_DIAL_AUTO_DIAL_TIMER);
        StartTimer(VRSD_DIAL_AUTO_DIAL_TIMER, MMI_VRSD_DIAL_OUT_TIME, mmi_vrsddial_rcg_auto_dial);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_exit_rcg_found
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_exit_rcg_found(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(VRSD_DIAL_AUTO_DIAL_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_rcg_auto_dial
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_rcg_auto_dial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_vrsddial_auto_dial(g_vrsddial_store_index);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_set_cur_store_index
 * DESCRIPTION
 *  mmi_vrsddial_set_cur_store_index
 * PARAMETERS
 *  index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsddial_set_cur_store_index(U16 index)
{
	g_vrsd_dial_list.cur_store_index = index;	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_train_delete_option_scr
 * DESCRIPTION
 *  delete train option related screen by ID
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsd_train_delete_option_scr(U16 scrID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 next_id, old_id = 0xFFFF;
	MMI_BOOL commscr_active = MMI_FALSE;
    BOOL gdi_freeze = gdi_lcd_get_freeze();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gdi_lcd_freeze(TRUE);
    
	if (GetActiveScreenId() == SCR_ID_VRSD_DIAL_MAIN_MENU
            ||  GetActiveScreenId() == SCR_ID_VRSD_DIAL_MAIN_MENU)
	{
		commscr_active = MMI_TRUE;
		EntryNewScreen(GLOBAL_SCR_DUMMY, NULL, NULL, NULL);
	}

    while(GetNextScrnIdOf(scrID, &next_id))
    {
        if (old_id == next_id)
        {
            scrID = next_id;

            if (!GetNextScrnIdOf(scrID, &next_id))
            {
                break;
            }
        }
        
        if (next_id == SCR_ID_VRSD_DIAL_MAIN_MENU
            ||  next_id == SCR_ID_VRSD_DIAL_MAIN_MENU)
        {
            DeleteScreenIfPresent(next_id);
        }
        else
        {
            break;
        }

        old_id = next_id;
    }

	if (commscr_active)
	{
		GoBackHistory();
	}

    gdi_lcd_freeze(gdi_freeze); /* Freeze lcd to avoid to blt temp screen in GoBackHistory() */

	/* 
	 * If GoBackHistory() was going to idle, we should blt, otherwise maybe no one
	 * will call blt function in the following process
	 */
	if (GetActiveScreenId() == IDLE_SCREEN_ID && commscr_active)
	{
		gdi_lcd_repaint_all(); 
	}

}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_phb_main_menu_pre_entry
 * DESCRIPTION
 *  mmi_vrsddial_phb_main_menu_pre_entry
 * PARAMETERS
 *  index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vrsddial_phb_main_menu_pre_entry(void)
{
	#ifndef __MTK_TARGET__
		PopupNoSupport();
		return;
	#endif /* __MTK_TARGET__ */ 
	
	#if defined(__USB_IN_NORMAL_MODE__)
		if (mmi_usb_is_in_mass_storage_mode())
		{
			mmi_usb_app_unavailable_popup(0);
			return;
		}
	#endif /* defined(__USB_IN_NORMAL_MODE__) */ 
	
	#if defined(__MMI_BACKGROUND_CALL__)
		if (srv_ucm_is_background_call())
		{
			mmi_ucm_entry_error_message();
			return;
		}
	#endif
	if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
	{
        	mmi_ucm_entry_error_message();
			return;	    
	}
	
	mmi_vrsddial_entry_tag_option();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_delete_all_tag_in_sim_no
 * DESCRIPTION
 *  not delete the tag
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL  TRUE if sim changed, FALSE if not
 *****************************************************************************/
void mmi_vrsddial_delete_all_tag_in_sim_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsd_cntx.vrtag_sync = 1;
    GoBackHistory();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_check_sim_change_not_at_idle
 * DESCRIPTION
 *  Check if SIM changed not at idle screen
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL  TRUE if sim changed, FALSE if not
 *****************************************************************************/
BOOL mmi_vrsddial_check_sim_change_not_at_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_vrsd_cntx.vrtag_sync == 0)
    {

    #ifdef __GEMINI__
        if (check_sim_status(0) == SMU_SIM_REPLACED || check_sim_status(1)== SMU_SIM_REPLACED)
    #else
        if (check_sim_status()== SMU_SIM_REPLACED)
    #endif
        {
            if (mmi_vrsd_get_total_tag_count(MMI_VRSD_APP_DIAL))
            {
                mmi_display_popup_confirm(
                    (UI_string_type)GetString(STR_GLOBAL_YES),
                    (PU8)GetImage(IMG_GLOBAL_YES),
                    (UI_string_type)GetString(STR_GLOBAL_NO),
                    (PU8)GetImage(IMG_GLOBAL_NO),
                    (UI_string_type)GetString(STR_ID_VRSD_DIAL_REFRESH_SIM),
                    MMI_EVENT_QUERY);                
                
                SetLeftSoftkeyFunction(mmi_vrsddial_delete_all_tag_in_sim_pre_req, KEY_EVENT_UP);
                SetRightSoftkeyFunction(mmi_vrsddial_delete_all_tag_in_sim_no, KEY_EVENT_UP);               
                return TRUE;
            }
            else 
            {
                g_vrsd_cntx.vrtag_sync = 1;
                return FALSE;
            }
        }
        else 
        {
            g_vrsd_cntx.vrtag_sync = 1;
        }
    }
    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_check_sim_change
 * DESCRIPTION
 *  Check if SIM changed when first time bootup and enter idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL  TRUE if sim changed, FALSE if not
 *****************************************************************************/
BOOL mmi_vrsddial_check_sim_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_vrsd_cntx.vrtag_sync == 0)
    {

    #ifdef __GEMINI__
        if (check_sim_status(0) == SMU_SIM_REPLACED || check_sim_status(1)== SMU_SIM_REPLACED)
    #else
        if (check_sim_status()== SMU_SIM_REPLACED)
    #endif
        {
            if (mmi_vrsd_get_total_tag_count(MMI_VRSD_APP_DIAL))
            {
                mmi_display_popup_confirm(
                    (UI_string_type)GetString(STR_GLOBAL_YES),
                    (PU8)GetImage(IMG_GLOBAL_YES),
                    (UI_string_type)GetString(STR_GLOBAL_NO),
                    (PU8)GetImage(IMG_GLOBAL_NO),
                    (UI_string_type)GetString(STR_ID_VRSD_DIAL_REFRESH_SIM),
                    MMI_EVENT_QUERY);                

                ClearAllKeyHandler();
                SetLeftSoftkeyFunction(mmi_vrsddial_delete_all_tag_in_sim_pre_req, KEY_EVENT_UP);
                SetRightSoftkeyFunction(mmi_vrsddial_delete_all_tag_in_sim_no, KEY_EVENT_UP);  
                SetKeyHandler(mmi_vrsddial_delete_all_tag_in_sim_no, KEY_END, KEY_EVENT_DOWN);              
                return TRUE;
            }
            else 
            {
                g_vrsd_cntx.vrtag_sync = 1;
                return FALSE;
            }
        }
        else 
        {
            g_vrsd_cntx.vrtag_sync = 1;
        }
    }
    return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_delete_all_tag_in_sim_pre_req
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_delete_all_tag_in_sim_pre_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vrsd_cntx.vrtag_sync = 1;
    mmi_vrsddial_delete_all_tag_req(0);   /* 0: SIM */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vrsddial_delete_all_tag_req
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  storage     [IN]            
 *  a(?)        [IN/OUT]        First variable, used as returns
 *  b(?)        [IN]            Second variable
 * RETURNS
 *  the description of return value, if any.(?)
 *****************************************************************************/
void mmi_vrsddial_delete_all_tag_req(U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    vrsd_tag_struct tag_list[MMI_VRSD_MAX_TAG];
    S16 pError;
    S32 result;
    BOOL error = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Retrieve data from NVRAM */
    ReadRecord(
        NVRAM_EF_VRSD_TAG_LID,
        MMI_VRSD_GROUP_ALL,
        (void*)tag_list,
        MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct),
        &pError);

    for (i = 0; i < MMI_VRSD_MAX_TAG; i++)
    {
        if (((tag_list[i].app_id == MMI_VRSD_APP_DIAL) && (tag_list[i].appref_id != 0xffff)) &&
            ((storage == 2) || (storage == 0 && tag_list[i].appref_id >= MMI_PHB_PHONE_ENTRIES)))
        {
            result = media_aud_vr_del_tag(MOD_MMI, MED_VR_ISD_MODE, MED_VR_NO_CARE_LANG, MMI_VRSD_GROUP_ALL, i);

            if (result != MED_RES_OK)
            {
                error = TRUE;
                continue;
            }

            tag_list[i].appref_id = 0xffff;
            tag_list[i].app_id = MMI_VRSD_APP_NONE;
        }
    }

    WriteRecord(
        NVRAM_EF_VRSD_TAG_LID,
        MMI_VRSD_GROUP_ALL,
        (void*)tag_list,
        MMI_VRSD_MAX_TAG * sizeof(vrsd_tag_struct),
        &pError);

    if (error)
    {
    	//failure
		mmi_display_popup(
			(UI_string_type)GetString(STR_GLOBAL_FAILURE),
			MMI_EVENT_FAILURE);
       
    }
    else
    {
    	//success
	    mmi_display_popup(
			(UI_string_type)GetString(STR_GLOBAL_DONE),
			MMI_EVENT_SUCCESS);
        
    }

    DeleteNScrId(SCR_ID_VRSD_DIAL_MAIN_MENU);   /* If not delete all from main menu, then delete Idle screen SIM refresh confirm */

}

/*****************************************************************************
 * FUNCTION
 *  mmi_vrsd_delete_contact_callback
 * DESCRIPTION
 *  mmi_vrsd_delete_contact_callback
 * PARAMETERS
 *  SelectedDate        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_vrsd_delete_contact_callback(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_evt_struct* evt = (srv_phb_op_evt_struct*)para;
	U16 tag_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ;
    if ((tag_id = mmi_vrsd_util_get_tag_id(MMI_VRSD_APP_DIAL, evt->store_index)) != 0xffff)
    {
        mmi_vrsd_del_tag_req(tag_id);
    }	
    return MMI_RET_OK;    
}


#if 1  // this functions should be delete if PHB is not using them
void mmi_vrsddial_highlight_main_delete(void)
{
}
void mmi_vrsddial_highlight_main_change(void)
{
}
void mmi_vrsddial_highlight_main_add(void)
{
}
void mmi_vrsddial_delete_tag_by_store_index(U16 store_index)
{
	
}

void mmi_vrsddial_entry_empty_list(void)
{
}

void mmi_vrsddial_main_menu_all_option(void)
{
}

void mmi_vrsddial_add_tag_from_list(void)
{
}

#endif

#endif /* defined(__MMI_VRSD__) && defined(__MMI_VRSD_DIAL__) */ /* #if defined(__MMI_VRSD__) && defined(__MMI_VRSD_DIAL__) */
#endif /* _MMI_VRSDDIAL_C */ /* #ifndef _MMI_VRSDDIAL_C */


