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
 *  mtvsmseditor.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  mtvsmscommon.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/************************************
 * Header Files Include
 **************************************************************/

#include "MMI_include.h"
#ifdef __ATV_SMS_SUPPORT__

#include "mtvsmsiprot.h"
#include "alertscreen.h"
#include "commonscreens.h"
#include "UcmSrvGprot.h"
#include "mmi_rp_app_sms_def.h"
#include "PhbSrvGprot.h"
#include "PhoneBookResDef.h"
#include "smsal_l4c_enum.h"
#include "Wgui_draw_manager_int.h"
#include "Wgui_fixed_menus.h"
#include "Custom_events_notify.h"

/**************************************************************
 * Const Defination
 **************************************************************/
#define MMI_MTV_SMS_TRACE_CONFIRM_CNTX  MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_CONFIRM_CNTX, confirm_cntx.str_id, confirm_cntx.scrn_id, confirm_cntx.lsk_func, confirm_cntx.rsk_func)
typedef enum
{   
    MTV_SMS_RELATED_SCRS_START = 0,
    MTV_SMS_SMS_SCRS = MTV_SMS_RELATED_SCRS_START,
    MTV_SMS_PHB_SCRS,
    MTV_SMS_PHB_GROUP,
    MTV_SMS_INPUTMETHOD_SCRS,
    MTV_SMS_ROOT,
    
    /* Please add you scrn id enum above*/
    MTV_SMS_RELATED_SCRS_DUMMY,
    MTV_SMS_RELATED_SCRS_TOTAL
} mmi_mtv_sms_scrn_related_enum;

/**************************************************************
 * Struct Defination
 **************************************************************/
typedef struct
{
    MMI_ID scrn_id;
    MMI_ID str_id;
    FuncPtr lsk_func;
    FuncPtr rsk_func;
} mmi_mtv_sms_confirm_data_struct;

typedef struct
{
    MMI_ID scr_id;
    U16 caption_id;
    U16 lsk_string; 
    U16 rsk_string; 
    U16 processing_str_id;
    U16 processing_img_id;
    v_func_v lsk_func; 
    v_func_v rsk_func;
} mmi_mtv_sms_procesing_cntx_struct;

/**************************************************************
 * Global Variables Declaration
 **************************************************************/
extern const U16 gIndexIconsImageList[];

/**************************************************************
 * Static Variables Defination
 **************************************************************/
static mmi_mtv_sms_procesing_cntx_struct process_cntx;
static mmi_mtv_sms_confirm_data_struct confirm_cntx;
static U16 scrn_ragnes[MTV_SMS_RELATED_SCRS_TOTAL][2] = {
                                                            {SCR_ID_MTV_SMS_MAIN_MENU, MMI_RP_APP_MTV_SMS_SCR_MAX}, /* sms scrns*/
                                                            {SCR_ID_MATV_SMS_PHB_LIST, SCR_ID_MATV_SMS_PHB_LIST},      /* PHB screen*/
                                                            {GRP_ID_PHB_MATV_GROUP, GRP_ID_PHB_MATV_GROUP},   /* PHB group*/ 
                                                            {GRP_ID_ROOT, GRP_ID_ROOT},
                                                            {1, 0},     /* Input method */
                                                            
                                                            /* Please add you scrn id range above, smaller one first*/
                                                            {1, 0} /* Dummy */
                                                        };



/**************************************************************
 * Static Function
 **************************************************************/
/* static mmi_ret mmi_mtv_sms_confirm_display_hdlr(mmi_event_struct *evt); */
static mmi_event_notify_enum  mmi_mtv_sms_event_transfer(mmi_mtv_event_notify_enum event_id);
static void mmi_mtv_sms_entry_processing_screen(void);
static void mmi_mtv_sms_read_msg_rsp(srv_sms_callback_struct *callback_data);
static EMSTATUS MTVCopyTextDataToEditInternal(EMSData *dest, EMSData*src);

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_common_screen_exit
 * DESCRIPTION
 *  check when matv sms screens exit. If full screen covers stop mtv 
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_mtv_sms_common_screen_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID scr_entry;
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scr_entry = GetActiveScreenId();
    if (mmi_ime_is_editor_common_scr(scr_entry))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_COMMON_EXIT, scr_entry);
        return;
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_COMMON_EXIT, scr_entry);
        for (i = 0; i < MTV_SMS_RELATED_SCRS_TOTAL; ++i)
        {
            kal_prompt_trace(MOD_MMI, "scrn_range %d %d",scrn_ragnes[i][0],  scrn_ragnes[i][1]);
            if ((scr_entry >= scrn_ragnes[i][0]) && (scr_entry <= scrn_ragnes[i][1]))
            {
                kal_prompt_trace(MOD_MMI, "scrn_range loop break");
                break;
            }
        }
        if (MTV_SMS_RELATED_SCRS_TOTAL <= i)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_COMMON_EXIT_STOP_VEDIO);
            wgui_cat_matv_stop_video();
            wgui_cat_matv_reset_video_info();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_is_send_enable
 * DESCRIPTION
 *  check is sms send available? 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE    if sms send available
 *  MMI_FALSE   if sms send not availale
 *****************************************************************************/
MMI_BOOL mmi_mtv_sms_is_send_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_sms_is_sms_valid());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_event_transfer
 * DESCRIPTION
 *  internal funtcion to map internal used notify type to mmi 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_event_notify_enum mmi_mtv_sms_event_transfer(mmi_mtv_event_notify_enum event_id)
{
    mmi_event_notify_enum notify_type = MMI_EVENT_INFO;
    switch(event_id)
    {
        case MMI_MTV_SMS_NOTIFY_INFO:
            notify_type = MMI_EVENT_INFO;
            break;
            
        case MMI_MTV_SMS_NOTIFY_OK:
            notify_type = MMI_EVENT_SUCCESS;
            break;
            
        case MMI_MTV_SMS_NOTIFY_FAILURE:
            notify_type = MMI_EVENT_FAILURE;
            break;
            
        case MMI_MTV_SMS_MESSAGE_SENT:
            notify_type =MMI_EVENT_MESSAGE_SENT;
            break;
        case MMI_MTV_SMS_LOADING:
            notify_type = MMI_EVENT_PROGRESS;
        
    }
    return notify_type;
}

 
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_display_popup
 * DESCRIPTION
 *  display basic popup
 * PARAMETERS
 *  string          [in] : string to display
 *  event_id        [in] : nofity type
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_sms_display_popup(MMI_ID string, mmi_mtv_event_notify_enum event_id)
 {
    mmi_event_notify_enum notify_id = mmi_mtv_sms_event_transfer(event_id);
    if (dm_is_fixed_layer_mode_enabled())
    {
        mmi_sms_matv_popup_show(get_string(string), notify_id, GRP_ID_ROOT, SCR_ID_MTV_SMS_POPUP_ID, mmi_mtv_sms_common_screen_exit);
    }
    else
    {   
        mmi_display_popup(get_string(string), notify_id);
    }
    g_mtv_sms_scrn_cntx.current_scrn = SCR_ID_MTV_SMS_POPUP_ID;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_POPUP, string, notify_id);
 }
 
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_confirm_generic
 * DESCRIPTION
 *  dispaly generic confirm
 * PARAMETERS
 *  id          [in] : string id to SHOW
 *  lskfunc      [in] : lsk function
 *  rskfunc     [in] : rsk function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_entry_confirm_generic(U16 scrn_id, U16 str_id, FuncPtr lskfunc, FuncPtr rskfunc)
{
    memset(&confirm_cntx, sizeof(confirm_cntx), 0);
    confirm_cntx.lsk_func = lskfunc;
    confirm_cntx.rsk_func = rskfunc;
    confirm_cntx.str_id = str_id;
    confirm_cntx.scrn_id = scrn_id;
    mmi_mtv_sms_entry_confirm();
    MMI_MTV_SMS_TRACE_CONFIRM_CNTX;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_set_confirm_generic
 * DESCRIPTION
 *  dispaly generic confrim screen
 * PARAMETERS
 *  id          [in] : string id to SHOW
 *  lskfunc      [in] : lsk function
 *  rskfunc     [in] : rsk function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_set_confirm_generic(U16 scrn_id, U16 str_id, FuncPtr lskfunc, FuncPtr rskfunc)
{
    memset(&confirm_cntx, sizeof(confirm_cntx), 0);
    confirm_cntx.lsk_func = lskfunc;
    confirm_cntx.rsk_func = rskfunc;
    confirm_cntx.str_id = str_id;
    confirm_cntx.scrn_id = scrn_id;
    MMI_MTV_SMS_TRACE_CONFIRM_CNTX;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_confirm
 * DESCRIPTION
 *  dispaly generic confirm screen
 * PARAMETERS
 *  id          [in] : string id to SHOW
 *  lskfunc      [in] : lsk function
 *  rskfunc     [in] : rsk function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_entry_confirm(void)
{
    
    EntryNewScreen(confirm_cntx.scrn_id, mmi_mtv_sms_common_screen_exit, NULL, NULL);
    wgui_cat_matv_init_video_info(
                    (U8 *)video_layer_buffer_ptr, 
                    MATV_VIDEO_LAYER_BUF_SIZE, 
                    (U8 *)util_layer_buffer_ptr, 
                    MATV_UTIL_LAYER_BUF_SIZE, 
                    mmi_mtv_sms_video_player_callback, 
                    mmi_mtv_sms_video_player_stop_callback);
    g_mtv_sms_scrn_cntx.current_scrn = confirm_cntx.scrn_id;
    wgui_cat9009_show(
        get_string(STR_GLOBAL_YES), 
        NULL, 
        get_string(STR_GLOBAL_NO), 
        NULL,
        get_string(confirm_cntx.str_id),
        IMG_GLOBAL_QUESTION, 
        NULL);
    SetLeftSoftkeyFunction(confirm_cntx.lsk_func, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(confirm_cntx.lsk_func, KEY_EVENT_UP);
    SetRightSoftkeyFunction(confirm_cntx.rsk_func, KEY_EVENT_UP);
    MMI_MTV_SMS_TRACE_CONFIRM_CNTX;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_confirm_no_csk
 * DESCRIPTION
 *  dispaly generic confirm screen
 * PARAMETERS
 *  id          [in] : string id to SHOW
 *  lskfunc      [in] : lsk function
 *  rskfunc     [in] : rsk function
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_entry_confirm_no_csk(void)
{
    
    EntryNewScreen(confirm_cntx.scrn_id, mmi_mtv_sms_common_screen_exit, NULL, NULL);
    wgui_cat_matv_init_video_info(
                    (U8 *)video_layer_buffer_ptr, 
                    MATV_VIDEO_LAYER_BUF_SIZE, 
                    (U8 *)util_layer_buffer_ptr, 
                    MATV_UTIL_LAYER_BUF_SIZE, 
                    mmi_mtv_sms_video_player_callback, 
                    mmi_mtv_sms_video_player_stop_callback);
    g_mtv_sms_scrn_cntx.current_scrn = confirm_cntx.scrn_id;
    wgui_cat9009_show(
        get_string(STR_GLOBAL_YES), 
        NULL, 
        get_string(STR_GLOBAL_NO), 
        NULL,
        get_string(confirm_cntx.str_id),
        IMG_GLOBAL_QUESTION, 
        NULL);
    SetLeftSoftkeyFunction(confirm_cntx.lsk_func, KEY_EVENT_UP);
    SetRightSoftkeyFunction(confirm_cntx.rsk_func, KEY_EVENT_UP);
    MMI_MTV_SMS_TRACE_CONFIRM_CNTX;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_scrn_close
 * DESCRIPTION
 *  close a scrn
 * PARAMETERS
 *  scrn_id         [in] : scrn to close
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_mtv_sms_scrn_close(MMI_ID scrn_id)
 {  
      mmi_delete_scrn_if_present(scrn_id);
      MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_SCRN_CLOSE, scrn_id);
 }


/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_scrn_back
 * DESCRIPTION
 *  go back a scrn
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_scrn_back(void)
{
   GoBackHistory();
}
 
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_scrn_replace
 * DESCRIPTION
 *  replace a scrn in history
 * PARAMETERS
 *  out_scrn_id        [in] : scrn to be removed
 *  in_scrn_id         [in] : scrn to be added
 *  in_srn_func        [in] : entry function for added scrn
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_mtv_sms_scrn_replace(U16 out_scrn_id, U16 in_scrn_id, FuncPtr in_src_func)
{
     return HistoryReplace(out_scrn_id, in_scrn_id, in_src_func);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_common_options
 * DESCRIPTION
 *  Entry common  Options Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mtv_sms_entry_common_options(MMI_ID scr_id, MMI_ID root_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];
    WCHAR* item_strings[MAX_SUB_MENUS];
    PU8 image_list[MAX_SUB_MENUS];
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(scr_id, mmi_mtv_sms_common_screen_exit, NULL, NULL);
    
    wgui_cat_matv_init_video_info(
                (U8 *)video_layer_buffer_ptr, 
                MATV_VIDEO_LAYER_BUF_SIZE, 
                (U8 *)util_layer_buffer_ptr, 
                MATV_UTIL_LAYER_BUF_SIZE, 
                mmi_mtv_sms_video_player_callback, 
                mmi_mtv_sms_video_player_stop_callback);

    
    g_mtv_sms_scrn_cntx.current_scrn = scr_id;

    guiBuffer = GetCurrGuiBuffer(scr_id);

    numItems = GetNumOfChild_Ext(root_id);
    GetSequenceStringIds_Ext(root_id, nStrItemList);
    
    for(i = 0; i < numItems; i++)
    {
        item_strings[i] = (WCHAR*)GetString(nStrItemList[i]);
    }

    
    for(i = 0; i < numItems; i++)
    {
        image_list[i] = (U8*)get_image(gIndexIconsImageList[i]);
    }
    SetParentHandler(root_id);
    wgui_list_menu_enable_access_by_shortcut();
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    wgui_cat1012_show(
        get_string(STR_GLOBAL_OPTIONS),
        get_image(0),
        get_string(STR_GLOBAL_SELECT),
        NULL,
        get_string(STR_GLOBAL_BACK),
        NULL,
        numItems,
        (WCHAR**)item_strings,
        (U16*)gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer,
        ExecuteCurrHiliteHandler,
        GoBackHistory);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_ENTRY_OPTION, root_id, scr_id, numItems);
}

/*****************************************************************************
 * FUNCTION
 *  MTVCopyEMSViewToEditBuffer
 * DESCRIPTION
 *  Copy EMS view buffer to edit buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 MTVCopyEMSViewToEditBuffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = EMS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_EMD_DATA_OBJECT_FIRST, g_mtv_sms_cntx.edit_ems_data->listHead);
    if(g_mtv_sms_cntx.edit_ems_data == NULL)
    {
        g_mtv_sms_cntx.edit_ems_data = (EMSData*)srv_sms_malloc_ems_data();
    }
    else
    {
        srv_sms_reset_ems_data((void*)g_mtv_sms_cntx.edit_ems_data);
    }
    MMI_ASSERT(g_mtv_sms_cntx.view_ems_data);
    if (g_mtv_sms_cntx.edit_ems_data != NULL)
    {
        result = MTVCopyTextDataToEditInternal(g_mtv_sms_cntx.edit_ems_data, g_mtv_sms_cntx.view_ems_data);

        if (result == EMS_OK)
        {
            EMSResetPortNum(g_mtv_sms_cntx.edit_ems_data);
            GoToEndPosition(g_mtv_sms_cntx.edit_ems_data);
        }
        else
        {
            srv_sms_reset_ems_data((void*)g_mtv_sms_cntx.edit_ems_data); /* because validFlag for edit buffer is 1, it is equivalent to force to realease */
        }
    }
    else
    {
        result = EMS_NULL_POINTER;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_EMS_COPY, result);
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  MTVCopyTextDataToEditInternal
 * DESCRIPTION
 *  copy string s from src ems  to dest ems
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
EMSTATUS MTVCopyTextDataToEditInternal(EMSData *dest, EMSData*src)
{
    EMSTATUS status = EMS_OK;
    MMI_ASSERT(dest);
    MMI_ASSERT(src);
    /* copy the ems data element */
    dest->dcs        = src->dcs;
    dest->ps_dcs     = src->ps_dcs;
    dest->isConcat   = src->isConcat;
    dest->udhi       = src->udhi;
    dest->textLength = 0;
    dest->NLTable = src->NLTable;
    
    if (src->textLength > 0)
    {
       status = AddString(dest, (U8*)src->textBuffer, mmi_ucs2strlen((const CHAR*)src->textBuffer), NULL);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_EMS_DATA_COPY_TO_EDIT,  dest->dcs, dest->ps_dcs, dest->isConcat, dest->udhi, dest->textLength, 
        dest->NLTable, mmi_ucs2strlen((const CHAR*)src->textBuffer), status);
    return status;
}

/*****************************************************************************
 * FUNCTION
 *  MTVReleaseEMSViewBuffer
 * DESCRIPTION
 *  Release EMS view buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MTVReleaseEMSViewBuffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_RELEASE_VIEW_EMS, g_mtv_sms_cntx.view_ems_data);
    if (g_mtv_sms_cntx.view_ems_data)
    {
        srv_sms_free_ems_data(g_mtv_sms_cntx.view_ems_data);
        g_mtv_sms_cntx.view_ems_data = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  MTVReleaseEMSEditBuffer
 * DESCRIPTION
 *  Release EMS edit buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void MTVReleaseEMSEditBuffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_RELEASE_EDIT_EMS, g_mtv_sms_cntx.edit_ems_data);
    if (g_mtv_sms_cntx.edit_ems_data)
    {
        srv_sms_free_ems_data(g_mtv_sms_cntx.edit_ems_data);
        g_mtv_sms_cntx.edit_ems_data = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  MtvGetEMSDataForEdit
 * DESCRIPTION
 *  Get EMS edit buffer
 * PARAMETERS
 *  p           [IN]        EMS data pointer
 *  force       [IN]        Force to clear
 * RETURNS
 *  EMS buffer for edit
 *****************************************************************************/
EMSData *MtvGetEMSDataForEdit(EMSData **p, U8 force)
{
    if (g_mtv_sms_cntx.edit_ems_data == NULL)
    {
        g_mtv_sms_cntx.edit_ems_data = srv_sms_malloc_ems_data();
    }
    
    if (force)
    {
        srv_sms_reset_ems_data((void*)g_mtv_sms_cntx.edit_ems_data);
    }

    if (p)
    {
        *p = g_mtv_sms_cntx.edit_ems_data;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_GET_EDIT_EMS, g_mtv_sms_cntx.edit_ems_data);
    return g_mtv_sms_cntx.edit_ems_data;
}

/*****************************************************************************
 * FUNCTION
 *  MtvGetEMSDataForView
 * DESCRIPTION
 *  Get EMS view buffer
 * PARAMETERS
 *  p           [IN]        EMS data pointer
 *  force       [IN]        Force to clear
 * RETURNS
 *  EMS buffer for display
 *****************************************************************************/
EMSData *MtvGetEMSDataForView(EMSData **p, U8 force)
{
    if (g_mtv_sms_cntx.view_ems_data == NULL)
    {
        g_mtv_sms_cntx.view_ems_data = srv_sms_malloc_ems_data();
    }

    if (force)
    {
        srv_sms_reset_ems_data((void*)g_mtv_sms_cntx.view_ems_data);
    }

    if (p)
    {
        *p = g_mtv_sms_cntx.view_ems_data;
    }
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_GET_VIEW_EMS, g_mtv_sms_cntx.view_ems_data);
    return g_mtv_sms_cntx.view_ems_data;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_pre_entry_processing_screen
 * DESCRIPTION
 *  set processing cntx and entry
 * PARAMETERS
 *  p           [IN]        EMS data pointer
 *  force       [IN]        Force to clear
 * RETURNS
 *  EMS buffer for display
 *****************************************************************************/
void mmi_mtv_sms_pre_entry_processing_screen(MMI_ID scr_id, U16 caption_id, U16 lsk_string, v_func_v lsk_func, U16 rsk_string, v_func_v rsk_func, U16 processing_str_id)
{
    memset(&process_cntx, sizeof(process_cntx), 0);
    process_cntx.scr_id = scr_id;
    process_cntx.caption_id = caption_id;
    process_cntx.lsk_string = lsk_string;
    process_cntx.lsk_func = lsk_func;
    process_cntx.rsk_string = rsk_string;
    process_cntx.rsk_func = rsk_func;
    process_cntx.processing_str_id = processing_str_id;
    mmi_mtv_sms_entry_processing_screen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mtv_sms_entry_processing_screen
 * DESCRIPTION
 *  entry a processing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mtv_sms_entry_processing_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr end_key_func;
    U16 process_image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(process_cntx.scr_id , mmi_mtv_sms_common_screen_exit, mmi_mtv_sms_entry_processing_screen, NULL);

    wgui_cat_matv_init_video_info(
                    (U8 *)video_layer_buffer_ptr, 
                    MATV_VIDEO_LAYER_BUF_SIZE, 
                    (U8 *)util_layer_buffer_ptr, 
                    MATV_UTIL_LAYER_BUF_SIZE, 
                    mmi_mtv_sms_video_player_callback, 
                    mmi_mtv_sms_video_player_stop_callback);

    g_mtv_sms_scrn_cntx.current_scrn = process_cntx.scr_id;

    if (process_cntx.processing_str_id == STR_ID_MTV_SMS_SENDING)
    {
        process_image_id = IMG_NEW_SMS_SEND;
    }
    else
    {
       process_image_id = mmi_get_event_based_image(MMI_EVENT_PROGRESS);
    }
    wgui_cat9009_show(
        get_string(process_cntx.lsk_string), 
        NULL, 
        get_string(process_cntx.rsk_string), 
        NULL,
        get_string(process_cntx.processing_str_id),
        process_image_id, 
        NULL);
    end_key_func = GetKeyHandler(KEY_END, KEY_EVENT_DOWN);

   if (!process_cntx.rsk_string)
   {
       ClearKeyHandler(KEY_END, KEY_EVENT_UP);
       ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
       ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
       ClearKeyHandler(KEY_END, KEY_REPEAT); 
       if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL))
       {
           SetKeyHandler(end_key_func, KEY_END, KEY_EVENT_DOWN);
       }
   }

   if (process_cntx.rsk_func!= NULL)
   {
       SetRightSoftkeyFunction(process_cntx.rsk_func, KEY_EVENT_UP);   
   }
   if (process_cntx.lsk_func!= NULL)
   {
       SetLeftSoftkeyFunction(process_cntx.lsk_func, KEY_EVENT_UP);
   }
    
}
 
 /*****************************************************************************
  * FUNCTION
  *  mmi_mtv_sms_get_address
  * DESCRIPTION
  *  get sms address
  * PARAMETERS      
  *  msg_id              [IN]        
  *  address             [OUT]    buffer for address     
  *  max_address_len     [IN]      
  * RETURNS
  *  void
  *****************************************************************************/
 MMI_BOOL mmi_mtv_sms_get_address(U16 msg_id, S8* address, U8 max_address_len)
 {
     MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_GET_ADDRESS, msg_id, address, max_address_len, 0xffff);
     if (srv_sms_get_msg_mti(msg_id) == SRV_SMS_MTI_STATUS_REPORT)
     {
        
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_GET_ADDRESS, msg_id, address, max_address_len, SRV_SMS_MTI_STATUS_REPORT);
        mmi_ucs2ncpy((S8*)address, (S8*) GetString(STR_GLOBAL_NOT_SUPPORTED), max_address_len);
         return MMI_TRUE;

     }
     else
     {
         U16 temp[(SRV_SMS_MAX_ADDR_LEN + 1)] = {0};
         U16 temp_name [(MMI_PHB_NAME_LENGTH + 1)] = {0};
          
         srv_sms_get_msg_address(msg_id, (S8*)temp);
 
         if ((temp[0] == '\0') && (temp[1] == '\0'))
         {
            return MMI_FALSE;
         }
         else
         {
            if (srv_phb_get_name_by_number((U16*)temp, (U16*)temp_name, MMI_PHB_NAME_LENGTH))
            {

                if(mmi_ucs2strlen((const CHAR *)temp_name))
                {
                    mmi_ucs2ncpy((CHAR*)address, (const CHAR*)temp_name, (max_address_len));
                }
                else
                {
                    mmi_ucs2ncpy((CHAR*) address, (const CHAR*)temp, (SRV_SMS_MAX_ADDR_LEN + 1));
                }
            }
            else
            {
                mmi_ucs2ncpy((CHAR*) address, (const CHAR*)temp, (SRV_SMS_MAX_ADDR_LEN + 1));
            }
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_GET_ADDRESS, msg_id, address, mmi_ucs2strlen((const CHAR *)address), 0x0f);
            return MMI_TRUE;
        }
    }
 }
 
 /*****************************************************************************
  * FUNCTION
  *  mmi_mtv_sms_read_msg
  * DESCRIPTION
  *  Read Message
  * PARAMETERS
  *  msg_id           [IN]    Msg Index
  *  change_status    [IN]      whether change unread/read status
  *  callback_func   [IN]    Callback Function
  * RETURNS
  *  void
  *****************************************************************************/
 void mmi_mtv_sms_read_msg(U16 msg_id, MMI_BOOL change_status, SmsMtvCBFuncPtr callback_func)
 {
     if (srv_sms_is_sms_ready() == MMI_FALSE)
     {
         mmi_mtv_sms_display_popup(
             (STR_ID_MTV_SMS_NOT_AVAIABLE),
             MMI_MTV_SMS_NOTIFY_FAILURE);
 
         if (callback_func != NULL)
         {
             callback_func(MTV_SMS_RESULT_ERROR, NULL);
         }
     }
     else
     {
         srv_sms_msg_data_struct *msg_data;
 
         msg_data = (srv_sms_msg_data_struct*)OslMalloc(sizeof(srv_sms_msg_data_struct));
 
         mmi_mtv_sms_pre_entry_processing_screen(
             SCR_ID_MTV_SMS_POPUP_READING,
             0, 
             0,
             NULL, 
             0,
             NULL, 
             STR_GLOBAL_LOADING);
 
         msg_data->para_flag = SRV_SMS_PARA_CONTENT_EMS;
 
         msg_data->content_ems = (EMSData*)MtvGetEMSDataForView(NULL, 1);
 
         if (!msg_data->content_ems)
         {
             mmi_mtv_sms_display_popup(
                 (STR_ID_MTV_SMS_NOT_AVAIABLE),
                 MMI_MTV_SMS_NOTIFY_FAILURE);
         
             if (callback_func != NULL)
             {
                 callback_func(MTV_SMS_RESULT_ERROR, NULL);
             }
         }
         else
         {
             srv_sms_read_msg(
                 msg_id,
                 change_status,
                 msg_data,
                 mmi_mtv_sms_read_msg_rsp,
                 (void*)callback_func);
             MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_MMI_MTV_SMS_READ_MSG, msg_id, change_status, callback_func);
         }
     }
 }

 /*****************************************************************************
  * FUNCTION
  *  mmi_mtv_sms_read_msg_rsp
  * DESCRIPTION
  *  Entry send screen
  * PARAMETERS
  *  data        [IN]    result data
  * RETURNS
  *  void
  *****************************************************************************/
 static void mmi_mtv_sms_read_msg_rsp(srv_sms_callback_struct* callback_data)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     srv_sms_read_msg_cb_struct *read_msg_cb_data;
     srv_sms_msg_data_struct *msg_data;
     SmsMtvCBFuncPtr callback_func;
     mmi_mtv_sms_result_enum action_result;
     mmi_mtv_sms_msg_status_enum msg_status = MMI_MTV_SMS_STATUS_UNSUPPORT;
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     read_msg_cb_data = (srv_sms_read_msg_cb_struct*)callback_data->action_data;
     callback_func = (SmsMtvCBFuncPtr)callback_data->user_data;
 
     msg_data = read_msg_cb_data->msg_data;
 
     if (callback_data->result == MMI_FALSE)
     {
         mmi_mtv_sms_display_popup(
             (STR_GLOBAL_UNFINISHED),
             MMI_MTV_SMS_NOTIFY_FAILURE);
         action_result = MTV_SMS_RESULT_ERROR;
     }
     else
     {
         if (msg_data->mti == SRV_SMS_MTI_STATUS_REPORT)
         {
             if (msg_data->tp_st == ST_COMP_MSG_RECV_BY_SME)
             {
                 msg_status = MMI_MTV_SMS_STATUS_DELIVERY_REPORT;
             }
             else
             {
                 msg_status = MMI_MTV_SMS_STATUS_PENDING_REPORT;
             }
         }
         else
         {
             srv_sms_status_enum srv_status = msg_data->status;
 
             if (srv_status & SRV_SMS_STATUS_UNSUPPORTED)
             {
                 msg_status = MMI_MTV_SMS_STATUS_UNSUPPORT;
             }
             else
             {
                 switch (srv_status)
                 {
                     case SRV_SMS_STATUS_UNREAD:
                         msg_status = MMI_MTV_SMS_STATUS_UNREAD;
                         break;
 
                     case SRV_SMS_STATUS_READ:
                         msg_status = MMI_MTV_SMS_STATUS_INBOX;
                         break;
 
                     case SRV_SMS_STATUS_SENT:
                         msg_status = MMI_MTV_SMS_STATUS_SENT;
                         break;
 
                     case SRV_SMS_STATUS_UNSENT:
                         msg_status = MMI_MTV_SMS_STATUS_UNSENT;
                         break;
 
                     case SRV_SMS_STATUS_DRAFT:
                         msg_status = MMI_MTV_SMS_STATUS_DRAFTS;
                         break;
 
                     default:
                         MMI_ASSERT(0);
                         break;
                 }
             }
         }
        action_result = MTV_SMS_RESULT_OK;
     }
 
     OslMfree(msg_data);
 
     if (callback_func != NULL)
     {
         callback_func(action_result, &msg_status);
     }
 }

 #endif /* _MMI_ATV_SMS_SUPPORT__ */
