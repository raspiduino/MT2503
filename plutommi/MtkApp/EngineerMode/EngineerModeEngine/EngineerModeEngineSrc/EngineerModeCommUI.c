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
 *  EngineerModeCommUI.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is for engineer mode common UI.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#include "MMI_features.h"
#include "EngineerModeUtil.h"

#ifdef __MMI_ENGINEER_MODE__

/***************************************************************************** 
* Include 
*****************************************************************************/
#if defined(COSMOS_EM_INTERNAL_DCM)
#include "dcmgr.h"
#elif defined (PLUTO_EM_INTERNAL_DCM)
#include "MMI_ap_dcm_config.h"  
#endif /* COSMOS_EM_INTERNAL_DCM */
    
#if defined(PLUTO_EM_INTERNAL_DCM)
#pragma arm section rodata = "DYNAMIC_CODE_EM_RODATA" , code = "DYNAMIC_CODE_EM_ROCODE"
#elif defined(COSMOS_EM_INTERNAL_DCM)
#pragma arm section rodata = "DYNAMIC_CODE_COSMOS_EM_RODATA" , code = "DYNAMIC_CODE_COSMOS_EM_ROCODE"
#endif /* PLUTO_EM_INTERNAL_DCM */ 


#include "mmi_rp_app_engineermode1_def.h"
#include "mdi_audio.h"
#include "fseditorcuigprot.h"
#include "wgui_inline_edit.h"
#include "wgui_categories_util.h"
#include "wgui_categories_text_viewer.h"
#include "GlobalResDef.h"
#include "wgui_categories_popup.h"

#include "EngineerModeGProt.h"
#include "EngineerModeResDef.h"
#include "EngineerModeAppResDef.h"
#include "EngineerModeCommMem.h"
#include "EngineerModeCommUI.h"
#include "EngineerModeAudio.h"
#include "EngineerModeDevice.h"
#include "EngineerModeMisc.h"
#include "EngineerModeBT.h"
#include "EngineerModeUtil.h"

/***************************************************************************** 
* Defines 
*****************************************************************************/
#define MMI_EM_NUM_EDIT_LEN             (16)
#define MMI_EM_INVALID_GROUP_ID         (0)
#define MMI_EM_NUM_EDIT_BUF_SIZE_NUM    (20)
#define MMI_EM_NUM_EDIT_POPUP_BUF_LEN   (50)

/***************************************************************************** 
* Struct 
*****************************************************************************/
typedef struct
{
    mmi_em_num_editor_struct out_data;
    MMI_ID editor_id;
    MMI_ID editor_gid;
} mmi_em_num_edit_cntx_struct;


/***************************************************************************** 
 * Static Function 
 *****************************************************************************/
static mmi_em_text_viewer_struct* g_mmi_em_text_viewer_cntx;
static mmi_em_num_edit_cntx_struct *g_mmi_em_num_edit_cntx;

/* text viewer */
static void mmi_em_free_text_viewer_cntx(void);
static MMI_BOOL mmi_em_text_viewer_stop_hdlr(void);
static void mmi_em_show_text_viewer_scrn(void);

/* num editer */
static void mmi_em_show_num_edit_popup(void);
static MMI_BOOL mmi_em_show_num_editor_stop_hdlr(void);
static void mmi_em_comm_editor_scrn_enter(MMI_ID parent_gid, WCHAR* input_buf, U32 input_type);
static MMI_RET mmi_em_comm_edit_scrn_proc(mmi_event_struct *evt);

extern MMI_ID g_em_root_group_id = 0;
static mmi_ret mmi_em_root_group_proc(mmi_event_struct *param);
extern void mmi_em_main_menu_release_mem(void);
extern S32 mmi_em_mainmenu_list_exit_handler(cui_menu_event_struct *em_menu_event);
extern U16 mmi_get_event_based_image(mmi_event_notify_enum event_id);

MMI_ID mmi_em_enter_root_group(void)
{
    if (g_em_root_group_id)
    {
        return g_em_root_group_id;
    }

    g_em_root_group_id = mmi_frm_group_create_ex(
                             GRP_ID_ROOT, 
                             GRP_ID_EM_ROOT, 
                             mmi_em_root_group_proc,
                             NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    return g_em_root_group_id;
}

mmi_ret mmi_em_close_root_group(void)
{
    mmi_ret ret;
    
    if (g_em_root_group_id == 0)
    {
        //MMI_ASSERT(!"No em group to close");
        return MMI_RET_OK;
    }
    ret = mmi_frm_group_close(g_em_root_group_id);
    g_em_root_group_id = 0;

    return ret;
}

MMI_ID mmi_em_get_root_group(void)
{
    return g_em_root_group_id;
}

static mmi_ret mmi_em_root_group_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;
    cui_menu_event_struct *menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct*)param;
    
    switch (menu_evt->evt_id)   
    {
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        mmi_em_mainmenu_entry_handler(param);
        break;
        
    case EVT_ID_CUI_MENU_ITEM_SELECT:
        mmi_em_mainmenu_select_handler(param);
        break;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_close(menu_evt->sender_id);
        break;
        
    case EVT_ID_CUI_MENU_LIST_EXIT:
        mmi_em_mainmenu_list_exit_handler(menu_evt);
        break;

    case EVT_ID_GROUP_DEINIT:
        mmi_em_main_menu_release_mem();
        g_em_root_group_id = 0;
        mdi_audio_resume_background_play();
        MMI_EM_DCM_POST_UNLOAD();
        break;

    default:
        break;
    }
    
    return ret;
}


void mmi_em_show_text_viewer(mmi_em_text_viewer_struct* data)
{
    U32 len;
    
    if (data == NULL || data->text == NULL)
        return;

    MMI_EM_REG_STOP_FUNC(mmi_em_text_viewer_stop_hdlr);
    g_mmi_em_text_viewer_cntx = (mmi_em_text_viewer_struct*)MMI_EM_MALLOC(sizeof(mmi_em_text_viewer_struct));

    len = mmi_wcslen(data->text);
    g_mmi_em_text_viewer_cntx->text =  (WCHAR*)MMI_EM_MALLOC((len + 1) * ENCODING_LENGTH);
    mmi_wcscpy((WCHAR *)g_mmi_em_text_viewer_cntx->text, data->text);

    g_mmi_em_text_viewer_cntx->user_data = data->user_data;

    if(data->title_id)
        g_mmi_em_text_viewer_cntx->title_id = data->title_id;
    else
        g_mmi_em_text_viewer_cntx->title_id = STR_GLOBAL_VIEW;

    g_mmi_em_text_viewer_cntx->parent_gid = mmi_frm_group_create_ex(mmi_em_get_root_group(),
                                                GRP_ID_AUTO_GEN, 
                                                NULL, NULL,
                                                MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_em_show_text_viewer_scrn();
}

static mmi_ret mmi_em_show_text_viewer_scrn_proc(mmi_event_struct* evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            U32 len;
            mmi_frm_scrn_active_evt_struct *active_evt = (mmi_frm_scrn_active_evt_struct *)evt;
            
            len = (mmi_wcslen(g_mmi_em_text_viewer_cntx->text) + 1) * 2;
            ShowCategory78Screen(g_mmi_em_text_viewer_cntx->title_id, 0,
                     NULL, NULL,
                     STR_GLOBAL_BACK,
                     IMG_GLOBAL_BACK,
                     NULL,
                     (U8*)g_mmi_em_text_viewer_cntx->text,
                     (S32)len, active_evt->gui_buffer);
            
            break;
        }
        
        case EVT_ID_SCRN_DEINIT:
        {
            mmi_em_free_text_viewer_cntx();
            MMI_EM_UNREG_STOP_FUNC(mmi_em_text_viewer_stop_hdlr);
            break;
        }
        
        default:
            break;
    }
    
    return MMI_RET_OK;

}

static void mmi_em_show_text_viewer_scrn(void)
{
    mmi_frm_scrn_create(
        g_mmi_em_text_viewer_cntx->parent_gid,
        SCR_ID_EM_CMN_SCRN,
        mmi_em_show_text_viewer_scrn_proc,
        NULL);
}

static MMI_BOOL mmi_em_text_viewer_stop_hdlr(void)
{ 
    /* close me */
    mmi_frm_group_close(g_mmi_em_text_viewer_cntx->parent_gid);
    mmi_em_free_text_viewer_cntx();
    return MMI_TRUE;
}

static void mmi_em_free_text_viewer_cntx(void)
{
    MMI_EM_FREE((WCHAR *)g_mmi_em_text_viewer_cntx->text);
    MMI_EM_FREE(g_mmi_em_text_viewer_cntx);
    g_mmi_em_text_viewer_cntx = NULL;
}

void mmi_em_show_num_editor(mmi_em_num_editor_struct *data)
{
    MMI_ID parent_gid;
    WCHAR input_buf[MMI_EM_NUM_EDIT_BUF_SIZE_NUM];


    if (data == NULL || data->notify == NULL)
        return;
    
    MMI_EM_REG_STOP_FUNC(mmi_em_show_num_editor_stop_hdlr);
    
    g_mmi_em_num_edit_cntx = (mmi_em_num_edit_cntx_struct*)MMI_EM_MALLOC(sizeof(mmi_em_num_edit_cntx_struct));
    
    memcpy((void*)&g_mmi_em_num_edit_cntx->out_data, (const void*)data, sizeof(mmi_em_num_editor_struct));
    
    if(data->parent_gid == MMI_EM_INVALID_GROUP_ID)
    {
        parent_gid = mmi_em_get_root_group();
    }
    else
    {
        parent_gid = data->parent_gid;
    }

    if (data->title_id)
    {
        g_mmi_em_num_edit_cntx->out_data.title_id = data->title_id;
    }
    else
    {
        g_mmi_em_num_edit_cntx->out_data.title_id = STR_GLOBAL_EDIT;
    }
        
    g_mmi_em_num_edit_cntx->out_data.min = data->min;
    
    if (data->max == 0)
    {
        g_mmi_em_num_edit_cntx->out_data.max = MMI_EM_NUM_VALUE_MAX_THRESHOLD;
    }
    else
    {
        g_mmi_em_num_edit_cntx->out_data.max = data->max;
    }
        
    if (data->value != MMI_EM_NUM_VALUE_INVALID)
    {
        g_mmi_em_num_edit_cntx->out_data.value = data->value;
    }
    
    kal_wsprintf(input_buf, "%d", g_mmi_em_num_edit_cntx->out_data.value);
    
    if (0 == data->input_type)
    {
        data->input_type = IMM_INPUT_TYPE_SIGNED_NUMERIC;
        g_mmi_em_num_edit_cntx->out_data.input_type = IMM_INPUT_TYPE_SIGNED_NUMERIC;
    }

    g_mmi_em_num_edit_cntx->editor_gid = mmi_frm_group_create_ex(parent_gid,
                                             GRP_ID_AUTO_GEN, 
                                             mmi_em_comm_edit_scrn_proc, NULL,
                                             MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_em_comm_editor_scrn_enter(g_mmi_em_num_edit_cntx->editor_gid, input_buf, data->input_type);
}

static MMI_BOOL mmi_em_show_num_editor_stop_hdlr(void)
{
    cui_fseditor_close(g_mmi_em_num_edit_cntx->editor_id);
    MMI_EM_FREE(g_mmi_em_num_edit_cntx);
    g_mmi_em_num_edit_cntx = NULL;
    return MMI_TRUE;
}

static void mmi_em_comm_editor_scrn_enter(MMI_ID parent_gid, WCHAR* input_buf, U32 input_type)
{
    g_mmi_em_num_edit_cntx->editor_id = cui_fseditor_create(parent_gid);
    
    if (g_mmi_em_num_edit_cntx->out_data.title_str[0] == 0)
    {
        cui_fseditor_set_title(
            g_mmi_em_num_edit_cntx->editor_id,
            g_mmi_em_num_edit_cntx->out_data.title_id, NULL);
    }
    else
    {
        cui_fseditor_set_title_string(
            g_mmi_em_num_edit_cntx->editor_id,
            g_mmi_em_num_edit_cntx->out_data.title_str);
    }
    
    cui_fseditor_set_text(g_mmi_em_num_edit_cntx->editor_id, input_buf, MMI_EM_NUM_EDIT_BUF_SIZE_NUM, MMI_EM_NUM_EDIT_LEN);
    
    cui_fseditor_set_input_method(g_mmi_em_num_edit_cntx->editor_id, input_type, NULL, 0);        
    
    cui_fseditor_run(g_mmi_em_num_edit_cntx->editor_id);
}

static MMI_RET mmi_em_comm_edit_scrn_proc(mmi_event_struct *evt)
{
    U32 num = 0;
    CHAR buf[MMI_EM_NUM_EDIT_POPUP_BUF_LEN * 2];
    WCHAR input_buf[MMI_EM_NUM_EDIT_BUF_SIZE_NUM];

    
    switch(evt->evt_id)
    {
    case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        cui_fseditor_get_text(g_mmi_em_num_edit_cntx->editor_id, input_buf, MMI_EM_NUM_EDIT_BUF_SIZE_NUM);
        
        if (IMM_INPUT_TYPE_SIGNED_NUMERIC != g_mmi_em_num_edit_cntx->out_data.input_type)
        {
            g_mmi_em_num_edit_cntx->out_data.user_data = input_buf;
            (*g_mmi_em_num_edit_cntx->out_data.notify)(MMI_TRUE, num, g_mmi_em_num_edit_cntx->editor_gid, g_mmi_em_num_edit_cntx->out_data.user_data);
            mmi_em_show_num_editor_stop_hdlr();
            break;
        }
                
        if (mmi_wcslen((const WCHAR * )input_buf))
        {
            mmi_wcs_to_asc(buf, input_buf);
            num = atoi((S8*)buf);

            if ((num >= g_mmi_em_num_edit_cntx->out_data.min)||(num <= g_mmi_em_num_edit_cntx->out_data.max))
            {
                (*g_mmi_em_num_edit_cntx->out_data.notify)(MMI_TRUE, num, g_mmi_em_num_edit_cntx->editor_gid, g_mmi_em_num_edit_cntx->out_data.user_data);
                mmi_em_show_num_editor_stop_hdlr();
                break;
            }
        }
        
        mmi_em_show_num_edit_popup();
        mmi_em_show_num_editor_stop_hdlr();
        break;

    case EVT_ID_CUI_FSEDITOR_ABORT:
        mmi_em_show_num_editor_stop_hdlr();
        MMI_EM_UNREG_STOP_FUNC(mmi_em_show_num_editor_stop_hdlr);
        break;
        
    default:
        break;
    }
    return MMI_RET_OK;
}

static void mmi_em_show_num_edit_popup(void)
{
    U16 show_str[MMI_EM_NUM_EDIT_POPUP_BUF_LEN];
    

    if (MMI_EM_NUM_VALUE_MAX_THRESHOLD == g_mmi_em_num_edit_cntx->out_data.max)
    {
        kal_wsprintf(show_str, "Please input the right parameter");
    }
    else
    {
        kal_wsprintf(show_str, "%d and %d", g_mmi_em_num_edit_cntx->out_data.min, g_mmi_em_num_edit_cntx->out_data.max);
    }
    
    mmi_popup_display_simple(show_str, 
            MMI_EVENT_WARNING, 
            g_mmi_em_num_edit_cntx->editor_gid, 
            NULL);
}

/**********************************************************
 * show category66 screen
 **********************************************************/
mmi_em_progress_cntx_struct * g_em_category66_cntx;

static void mmi_em_free_show_category66_scrn_cntx(void)
{
    MMI_EM_FREE(g_em_category66_cntx);
    g_em_category66_cntx = NULL;
}

static MMI_BOOL mmi_em_show_category66_scrn_stop_hdlr(void)
{ 
    /* close me */
    mmi_frm_scrn_close(g_em_category66_cntx->group_id, g_em_category66_cntx->scrn_id);
    mmi_em_free_show_category66_scrn_cntx();
    return MMI_TRUE;
}

static void mmi_em_show_category66_scrn_check_param(mmi_em_progress_cntx_struct* cntx)
{
    if (NULL == cntx)
    {
        return;
    }
    
    cntx->group_id = cntx->group_id ? cntx->group_id : mmi_em_get_root_group();
    cntx->scrn_id = cntx->scrn_id ? cntx->scrn_id : SCR_ID_EM_CMN_SCRN;
    cntx->title_id = cntx->title_id ? cntx->title_id : STR_ID_EM_APP_NAME;
    cntx->message_icon = cntx->message_icon ? cntx->message_icon : mmi_get_event_based_image(MMI_EVENT_PROGRESS);
}

static mmi_ret mmi_em_show_category66_scrn_proc(mmi_event_struct* evt)
{
    mmi_em_progress_cntx_struct *scrn_cntx = (mmi_em_progress_cntx_struct *)evt->user_data;
    
    
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_frm_scrn_active_evt_struct *active_evt = (mmi_frm_scrn_active_evt_struct *)evt;
            
            if (scrn_cntx->enter_func)
            {
                (scrn_cntx->enter_func)();
            }
            
            ShowCategory66Screen(
                scrn_cntx->title_id,
                0,
                scrn_cntx->left_softkey,
                scrn_cntx->left_softkey_icon,
                scrn_cntx->right_softkey,
                scrn_cntx->right_softkey_icon,
                scrn_cntx->message,
                scrn_cntx->message_icon,
                active_evt->gui_buffer);
            break;
        }
        
        case EVT_ID_SCRN_DEINIT:
        {
            if (scrn_cntx->exit_func)
            {
                (scrn_cntx->exit_func)();
            }
            
            mmi_em_free_show_category66_scrn_cntx();
            MMI_EM_UNREG_STOP_FUNC(mmi_em_show_category66_scrn_stop_hdlr);
            break;
        }
        
        case EVT_ID_WGUI_LSK_CLICK:
        {
            if (scrn_cntx->lsk_func)
            {
                (scrn_cntx->lsk_func)();
                return MMI_RET_KEY_HANDLED;
            }
            break;
        }
        
        case EVT_ID_WGUI_RSK_CLICK:
        {
            if (scrn_cntx->rsk_func)
            {
               (scrn_cntx->rsk_func)();
               return MMI_RET_KEY_HANDLED;
            }
            break;
        }
        
        case EVT_ID_ON_KEY:
        {
            mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
            
            if (key_evt->key_type == KEY_EVENT_UP || key_evt->key_type == KEY_EVENT_DOWN)
            {
            #ifdef __COSMOS_MMI_PACKAGE__
                if (key_evt->key_code == KEY_HOME)
            #else
                 if (key_evt->key_code == KEY_END)
            #endif        
                 {
                     if (scrn_cntx->esk_func)
                     {
                         (scrn_cntx->esk_func)();
                         return MMI_RET_KEY_HANDLED;
                     }
                 }
            }
            break;
        }
        
        
        default:
            break;
    }
    
    return MMI_RET_OK;
}

void mmi_em_progress_sftkey_null_hdlr(void)
{
}

void mmi_em_show_progress_scrn(mmi_em_progress_cntx_struct* cntx)
{
    U32 cntx_size = sizeof(mmi_em_progress_cntx_struct);
    
    
    MMI_EM_REG_STOP_FUNC(mmi_em_show_category66_scrn_stop_hdlr);
    g_em_category66_cntx = (mmi_em_progress_cntx_struct *)MMI_EM_MALLOC(cntx_size);
    
    memcpy((void *)g_em_category66_cntx, (const void *)cntx, cntx_size);
    
    if (cntx->message)
    {
        mmi_wcscpy((WCHAR *)g_em_category66_cntx->message_data, (const WCHAR *)cntx->message);
        g_em_category66_cntx->message = (U8 *)g_em_category66_cntx->message_data;
    }
    mmi_em_show_category66_scrn_check_param(g_em_category66_cntx);
    
    mmi_frm_scrn_create(g_em_category66_cntx->group_id,
        g_em_category66_cntx->scrn_id,
        mmi_em_show_category66_scrn_proc,
        (void*)g_em_category66_cntx);
}

void mmi_em_close_progress_scrn(void)
{
    mmi_frm_scrn_close(
        g_em_category66_cntx->group_id,
        g_em_category66_cntx->scrn_id);
}

#if (defined(COSMOS_EM_INTERNAL_DCM) || defined(PLUTO_EM_INTERNAL_DCM))
#pragma arm section rodata , code
#endif /* COSMOS_EM_INTERNAL_DCM || PLUTO_EM_INTERNAL_DCM */ 

#endif /*__MMI_ENGINEER_MODE__*/

