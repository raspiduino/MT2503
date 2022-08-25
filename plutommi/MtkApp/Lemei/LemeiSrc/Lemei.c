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
 * Lemei.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_OP02_LEMEI__
#include "mmi_rp_app_lemei_def.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "CommonScreens.h"
#include "menucuigprot.h"
#include "FileMgrGProt.h"
#include "FileMgrSrvGProt.h"
#include "FileMgrCuiGprot.h"
#include "UcAppGProt.h"
#include "CameraCuiGprot.h"
#include "VdoRecCuiGprot.h"
#include "SoundRecorderProt.h"
#include "wgui_categories_op.h"

#ifdef __MMI_VIDEO_RECORDER__
#ifdef __MMI_CAMCORDER__
#include "mmi_features_camcorder.h"
#include "gdi_include.h"
#include "CamcorderGprot.h"
#else  /* __MMI_CAMCORDER__ */ 
#include "VdoRecGprot.h"
#endif /* __MMI_CAMCORDER__ */
#endif /* __MMI_VIDEO_RECORDER__ */

//#include "simDetectionGprot.h"
#include "NwUsabSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "NetSetAppProt.h"
#include "wgui_categories_util.h"
#include "FileMgrType.h"

#define LEMEI_MAX_PATH_LEN			(SRV_FMGR_PATH_MAX_LEN + 1)
#define LEMEI_MEDIA_FILE_SIZE_LIMIT  290*1024
#define MMI_LEMEI_GET_SIZE(x)                  (sizeof(x) / sizeof(x[0]))

typedef enum
{
    MEDIA_TYPE_IMAGE = 0,
    MEDIA_TYPE_VIDEO,
    MEDIA_TYPE_AUDIO
}lemei_media_type_enum;

const static S8 *g_op02_lemei_proprietary_sim[] =
{
    "46001",    /* China Unicom */
};

static MMI_BOOL g_fileNeedSent = MMI_FALSE;
static WCHAR* g_filePath = NULL;

static mmi_ret mmi_lemei_main_proc(mmi_event_struct *evt);
static void mmi_lemei_entry_option(void);
static void mmi_lemei_set_file_mgr_filter_for_image(FMGR_FILTER* filter);
static void mmi_lemei_set_file_mgr_filter_for_video(FMGR_FILTER* filter);
static void mmi_lemei_set_file_mgr_filter_for_audio(FMGR_FILTER* filter);
static void mmi_lemei_select_fmgr_object(lemei_media_type_enum mediaType);
static void mmi_lemei_send_msg(char *content_source);
static void mmi_lemei_enter_camera(void);
static void mmi_lemei_enter_video_recorder(void);
static void mmi_lemei_enter_audio_recorder(void);
static mmi_ret mmi_lemei_multimedia_app_proc(mmi_event_struct *evt);
MMI_ID mmi_lemei_enter_temp_screen_group(MMI_ID parent_id, mmi_proc_func proc, void *user_data);
void mmi_lemei_enter_audio_recorder_callback(MMI_BOOL result, S8 *file_path);
static mmi_ret mmi_lemei_cui_fmgr_proc(mmi_event_struct *evt);
static void mmi_lemei_init_folder(const UI_string_type FolderName);
extern void mmi_sndrec_entry_record_from_lamei(
        U16 *file_path,
        U32 size_limit,
        U32 time_limit,
        void (*app_callback_func) (BOOL result, U16 *filepath));


void mmi_lemei_entry_main_screen()
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_scrn_enter(GRP_ID_LEMEI, SCR_ID_LEMEI_MAIN, NULL, mmi_lemei_entry_main_screen, MMI_FRM_UNKNOW_SCRN) == MMI_FALSE)
    {
        return;
    }

    if (g_fileNeedSent)
    {
        g_fileNeedSent = MMI_FALSE;
        if(g_filePath)
        {
            mmi_lemei_send_msg((S8*)g_filePath);
            OslMfree(g_filePath);
            g_filePath = NULL;
            return;
        }
    }

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    wgui_cat9002_op02_set_button1_hdlr(mmi_lemei_enter_audio_recorder);
    wgui_cat9002_op02_set_button2_hdlr(mmi_lemei_enter_camera);
    wgui_cat9002_op02_set_button3_hdlr(mmi_lemei_enter_video_recorder);

    wgui_cat9002_op02_show(get_string(STR_ID_LEMEI_MENUITEM),
                             get_image(GetRootTitleIcon(MAIN_MENU_LEMEI_MENUID)),
                             get_string(STR_GLOBAL_OPTIONS),
                             get_image(IMG_GLOBAL_OPTIONS),
                             get_string(STR_GLOBAL_BACK),
                             get_image(IMG_GLOBAL_BACK));

    SetKeyHandler(mmi_lemei_enter_audio_recorder, KEY_1, KEY_EVENT_UP);
    SetKeyHandler(mmi_lemei_enter_camera, KEY_2, KEY_EVENT_UP);
    SetKeyHandler(mmi_lemei_enter_video_recorder, KEY_3, KEY_EVENT_UP);

    SetLeftSoftkeyFunction(mmi_lemei_entry_option,KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
}

void mmi_lemei_entry_option()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_cui_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_cui_id = cui_menu_create(GRP_ID_LEMEI,
                                    CUI_MENU_SRC_TYPE_RESOURCE,
                                    CUI_MENU_TYPE_OPTION,
                                    MENUID_LEMEI_OPTIONS_MENU,
                                    MMI_TRUE,
                                    NULL);                                 
    cui_menu_run(menu_cui_id);
}

MMI_BOOL mmi_lemei_is_proprietary_sim(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR hplmn[SRV_MAX_PLMN_LEN + 1];
    S32 n_sim, size;
    S32 i;
    MMI_BOOL ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* If the SIM's IMSI is not ready, e.g., no SIM inserted, don't enable
       the Homescreen. */
    ret = srv_sim_ctrl_get_home_plmn(sim, hplmn, SRV_MAX_PLMN_LEN + 1);

    if (!ret)
    {
        return MMI_FALSE;
    }

    /* Check the MCC/MNC is the proprietary one. */
    n_sim = MMI_LEMEI_GET_SIZE(g_op02_lemei_proprietary_sim);

    for (i = 0; i < n_sim; i++)
    {
        size = strlen(g_op02_lemei_proprietary_sim[i]);
        
        if (!memcmp(hplmn, g_op02_lemei_proprietary_sim[i], size))
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


void entry_lemei_app()
{
    mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_LEMEI, mmi_lemei_main_proc, NULL);
    
    mmi_frm_group_enter(GRP_ID_LEMEI, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_lemei_entry_main_screen();
}


void mmi_lemei_uc_send_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_uc_entry_write_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&data, 0x00, sizeof(mmi_uc_entry_write_struct));

    data.msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
    mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);
}

void EntryLemeiMain()
{
    if (MMI_FALSE == srv_nw_usab_is_any_network_available())
    {
        mmi_popup_display_simple(
                (WCHAR *)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), 
                MMI_EVENT_FAILURE, 
                GRP_ID_ROOT, 
                NULL);
        return;
    }
    else
    {
        if(mmi_lemei_is_proprietary_sim(MMI_SIM1))
        {
            entry_lemei_app();
        }
        #ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        else
        {
            mmi_lemei_uc_send_mms();
        }
    }

}

static mmi_ret mmi_lemei_main_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Menu cui revise */
    cui_menu_event_struct *menu_event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_event = (cui_menu_event_struct*)evt;
    switch(evt->evt_id)
    {
        /* for menu cui */
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            switch (menu_event->parent_menu_id)
            {
                case MENUID_LEMEI_OPTIONS_MENU:
                {

                    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                    #endif
                    break;
                }
                default:
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_HILITE:
            switch (menu_event->highlighted_menu_id)
            {
                case MENU_ID_LEMEI_OPTIONS_LOCAL_PICTURE:
                case MENU_ID_LEMEI_OPTIONS_LOCAL_VIDEO:
                case MENU_ID_LEMEI_OPTIONS_LOCAL_AUDIO:

                    //cui_menu_change_center_softkey_content(menu_event->sender_id, 0, 0);
                    //cui_menu_change_left_softkey_string(menu_event->sender_id, 0);
                    break;

                default:
                    cui_menu_change_center_softkey_content(
                        menu_event->sender_id, 
                        0, 
                        (UI_image_type)GetImage(IMG_GLOBAL_COMMON_CSK));
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
            switch (menu_event->highlighted_menu_id)
            {
                case MENU_ID_LEMEI_OPTIONS_LOCAL_PICTURE:
                    mmi_lemei_select_fmgr_object(MEDIA_TYPE_IMAGE);

                    break;

                case MENU_ID_LEMEI_OPTIONS_LOCAL_VIDEO:
                    mmi_lemei_select_fmgr_object(MEDIA_TYPE_VIDEO);
                    break;
                    
                case MENU_ID_LEMEI_OPTIONS_LOCAL_AUDIO:
                    mmi_lemei_select_fmgr_object(MEDIA_TYPE_AUDIO);
                    break;
                    
                default:
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_event->sender_id);
            break;

        case EVT_ID_GROUP_DEINIT:
            if(g_filePath)
            {
                OslMfree(g_filePath);
                g_filePath = NULL;
            }
            g_fileNeedSent = MMI_FALSE;
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_my_favorite_init_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  FolderName      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_lemei_init_folder(const UI_string_type FolderName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    UI_character_type FolderPath[30];
    S8 drv[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(drv, "%c:\\", (S8) SRV_FMGR_PUBLIC_DRV);
    mmi_asc_to_ucs2((S8*) FolderPath, drv);
    mmi_ucs2cat((S8*) FolderPath, (const S8*)FolderName);

    file_handle = FS_Open(FolderPath, FS_OPEN_DIR | FS_READ_ONLY);

    if (file_handle < 0)
    {
    	  if (FS_CreateDir(FolderPath) < 0)
    		{
    			return;
        }
    }
    else
    {
        FS_Close(file_handle);
    }
    return;
}

static void mmi_lemei_select_fmgr_object(lemei_media_type_enum mediaType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    mmi_id fs_gid;
    mmi_id temp_gid = 0;
    U16 file_path[SRV_FMGR_PATH_MAX_LEN];
    U32 option_flag = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(file_path, 0, sizeof(file_path));
    //FMGR_FILTER_INIT(&filter);
    switch(mediaType)
    {
        case MEDIA_TYPE_IMAGE:
            mmi_lemei_set_file_mgr_filter_for_image(&filter);
            kal_wsprintf(file_path, "%c:\\%w", SRV_FMGR_PUBLIC_DRV, FMGR_DEFAULT_FOLDER_IMAGES);
            mmi_lemei_init_folder(FMGR_DEFAULT_FOLDER_IMAGES);
            break;
        case MEDIA_TYPE_VIDEO:
            mmi_lemei_set_file_mgr_filter_for_video(&filter);
            kal_wsprintf(file_path, "%c:\\%w", SRV_FMGR_PUBLIC_DRV, FMGR_DEFAULT_FOLDER_VIDEO);
            mmi_lemei_init_folder(FMGR_DEFAULT_FOLDER_VIDEO);
            break;
        case MEDIA_TYPE_AUDIO:
            mmi_lemei_set_file_mgr_filter_for_audio(&filter);
            kal_wsprintf(file_path, "%c:\\%w", SRV_FMGR_PUBLIC_DRV, FMGR_DEFAULT_FOLDER_AUDIO);
            mmi_lemei_init_folder(FMGR_DEFAULT_FOLDER_AUDIO);
            break;
        default:
            break;
    }
    
    temp_gid = mmi_lemei_enter_temp_screen_group(
              GRP_ID_LEMEI,
              mmi_lemei_cui_fmgr_proc, 
              NULL);

    option_flag = CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FILE |
                  CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON;
    fs_gid = cui_file_selector_create(temp_gid,
                                        (WCHAR*)file_path,
                                        &filter,
                                        CUI_FILE_SELECTOR_STYLE_FILE_ONLY,
                                        option_flag);

    if (fs_gid > 0)
    {
        /*cui_file_selector_set_title(g_listui_cntx_p->list_info.child_id, 0, IMG_ID_MEDPLY_ICON);*/    
        cui_file_selector_set_userdata(fs_gid, 0);        
        cui_file_selector_run(fs_gid);
    }
    else
    {   
        mmi_popup_display_simple((WCHAR*)get_string(STR_GLOBAL_NOT_AVAILABLE),
                                 MMI_EVENT_FAILURE,
                                 GRP_ID_LEMEI,
                                 NULL);
    }
}

static void mmi_lemei_set_file_mgr_filter_for_image(FMGR_FILTER* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);
    
    FMGR_FILTER_SET(filter, FMGR_TYPE_BMP);
    FMGR_FILTER_SET(filter, FMGR_TYPE_GIF);
    FMGR_FILTER_SET(filter, FMGR_TYPE_WBM);
    FMGR_FILTER_SET(filter, FMGR_TYPE_WBMP);
#ifdef GDI_USING_PNG
    FMGR_FILTER_SET(filter, FMGR_TYPE_PNG);
#endif 
#ifdef JPG_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(filter, FMGR_TYPE_JPEG);
#endif

    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}

static void mmi_lemei_set_file_mgr_filter_for_audio(FMGR_FILTER* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);
    
    FMGR_FILTER_SET(filter, FMGR_TYPE_IMY);
    FMGR_FILTER_SET(filter, FMGR_TYPE_MID);
    FMGR_FILTER_SET(filter, FMGR_TYPE_MIDI);
    FMGR_FILTER_SET(filter, FMGR_TYPE_WAV);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AMR);
    // FMGR_FILTER_SET(filter, FMGR_TYPE_VM);   /* cannot get duration */
#ifdef AAC_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_AAC);
#endif 
#ifdef DAF_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_DAF);
#endif 
    
#ifdef  __RM_DEC_SUPPORT__
   FMGR_FILTER_SET(filter, FMGR_TYPE_RA); 
#endif
#ifdef AMRWB_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_AWB);
#endif 
#ifndef __CPU_ARM7TDMI__ /* MT6205B */
    FMGR_FILTER_SET(filter, FMGR_TYPE_AIF);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AIFF);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AIFC);
    FMGR_FILTER_SET(filter, FMGR_TYPE_AU);
    FMGR_FILTER_SET(filter, FMGR_TYPE_SND);
#endif /* __CPU_ARM7TDMI__ *//* MT6205B */ 
#if defined(M4A_DECODE)
    FMGR_FILTER_SET(filter, FMGR_TYPE_M4A);
#endif 
#if defined(EXT_AUDIO_CHIP) || defined(MMF_DECODE)
    FMGR_FILTER_SET(filter, FMGR_TYPE_MMF);
#endif 
#ifdef WMA_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_WMA);
#endif 
#ifdef MUSICAM_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_MP2);
#endif 

#if !defined (MP4_DECODE) && defined(__MMI_PURE_AUDIO__)
    FMGR_FILTER_SET(filter, FMGR_TYPE_3GP);
    FMGR_FILTER_SET(filter, FMGR_TYPE_MP4);
    FMGR_FILTER_SET(filter, FMGR_TYPE_3G2);
#endif
#ifdef __APE_DECODE__
	    FMGR_FILTER_SET(filter, FMGR_TYPE_APE);
#endif

    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}

static void mmi_lemei_set_file_mgr_filter_for_video(FMGR_FILTER* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(filter);
    FMGR_FILTER_SET(filter, FMGR_TYPE_MPG);
#ifdef MP4_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_3GP);
    FMGR_FILTER_SET(filter, FMGR_TYPE_MP4);
    FMGR_FILTER_SET(filter, FMGR_TYPE_3G2);
#endif 
    
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}

static void mmi_lemei_send_msg(char *content_source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //char sub[]="12345";
    mmi_uc_entry_write_struct data;
    memset(&data, 0x00, sizeof(mmi_uc_entry_write_struct));
    data.file_path = (kal_uint8*) content_source;
    data.msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
    data.info_type = MMI_UC_INFO_TYPE_LEMEI_MMS;
    data.subject = (kal_uint8 *)get_string(STR_ID_LEMEI_SUBJECT);
	mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &data);
    return;
}

void mmi_lemei_enter_camera()
{
    mmi_id camera_cui_gid = 0;
    mmi_id temp_gid = 0;

    temp_gid = mmi_lemei_enter_temp_screen_group(
              GRP_ID_LEMEI,
              mmi_lemei_multimedia_app_proc, 
              NULL);
    if(temp_gid > 0)
    {
        camera_cui_gid = cui_camera_create(temp_gid);

        if (camera_cui_gid > 0)
        {
            cui_camera_run_struct camera_struct;
            cui_camera_struct_init(&camera_struct);
        #if 0//def __MMI_CAMCORDER__
/* under construction !*/
        #endif
            cui_camera_run(camera_cui_gid, &camera_struct);
        }
    }
}


void mmi_lemei_enter_audio_recorder()
{
    U32 max_file_size = 290*1024;
    
    if (max_file_size > 0)
    {
        mmi_sndrec_entry_record_from_lamei(
            NULL,
            max_file_size,
            0,
            (void (*)(BOOL, U16*))mmi_lemei_enter_audio_recorder_callback);
    }
}

void mmi_lemei_enter_video_recorder()
{
    U32 max_file_size = 290;
    mmi_id temp_gid = 0;
    mmi_id vdorec_cui_gid = 0;
    if (max_file_size >= mmi_vdorec_get_min_external_request_size())        /* because video recorder can not record with accurate size, walk around */
    {
        if(cui_vdorec_check_and_display_popup())    
        {
            cui_vdorec_run_struct vdorec_struct;

            cui_vdorec_struct_init(&vdorec_struct);

            vdorec_struct.max_file_size = max_file_size;
            vdorec_struct.max_record_time = 0;
            #if defined(__MMI_CAMCORDER__)
            vdorec_struct.is_partial = 0;
            #endif

            temp_gid = mmi_lemei_enter_temp_screen_group(GRP_ID_LEMEI,
                                                          mmi_lemei_multimedia_app_proc, 
                                                          NULL);
            
            vdorec_cui_gid = cui_vdorec_create(temp_gid);
            cui_vdorec_run(vdorec_cui_gid, &vdorec_struct);
        }
    }
    /*
    else if (max_file_size > 0)
    {
        mmi_popup_display("", MMI_EVENT_FAILURE, NULL);
    }
    */
}

MMI_ID mmi_lemei_enter_temp_screen_group(MMI_ID parent_id, mmi_proc_func proc, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID gid;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gid = mmi_frm_group_create(
              parent_id, 
              GRP_ID_AUTO_GEN, 
              proc, 
              user_data);

    return mmi_frm_group_enter(gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
}

static mmi_ret mmi_lemei_multimedia_app_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
    #if (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMERA__))
    #ifdef __MMI_VIDEO_RECORDER__
        case CUI_VDOREC_RECORD_EVENT_RESULT_SUCCESS:
            {
                //mmi_uc_enter_multimedia_app_callback(MMI_TRUE, (PS8) ((cui_vdorec_event_struct*) evt)->file_path);
                cui_vdorec_close(((cui_vdorec_event_struct*)evt)->sender_id);

                if(mmi_frm_group_get_active_id() == GRP_ID_LEMEI)
                {
                    mmi_lemei_send_msg((S8*)((cui_vdorec_event_struct*)evt)->file_path);

                }
                else
                {
                    g_fileNeedSent = MMI_TRUE;
                    if(!g_filePath)
                    {
                        g_filePath = (WCHAR*)OslMalloc(sizeof(WCHAR) * LEMEI_MAX_PATH_LEN);
                    }
                    mmi_wcscpy(g_filePath, (WCHAR*)((cui_vdorec_event_struct*)evt)->file_path);
                    if (mmi_wcslen(g_filePath) <= 0)
                    {
                        OslMfree(g_filePath);
                        g_filePath = NULL;
                    }
                }                
            }
            break;

        case CUI_VDOREC_RECORD_EVENT_RESULT_FAILED:
            {
                cui_vdorec_close(((cui_vdorec_event_struct*)evt)->sender_id);
            }
            break;

        case CUI_VDOREC_RECORD_EVENT_RESULT_CLOSE_ME:
            {
                cui_vdorec_close(((cui_vdorec_event_struct*)evt)->sender_id);
            }
            break;
    #endif /* __MMI_VIDEO_RECORDER__ */ 

    #ifdef __MMI_CAMERA__
        case CUI_CAMERA_EVENT_RESULT_SUCCESS:
            {
                mmi_lemei_send_msg((S8*)((cui_camera_event_struct*)evt)->file_path);
                //mmi_uc_enter_multimedia_app_callback(MMI_TRUE, (PS8) ((cui_camera_event_struct*) evt)->file_path);
                cui_camera_close(((cui_camera_event_struct*)evt)->sender_id);
            }
            break;

        case CUI_CAMERA_EVENT_RESULT_FAILED:
            {
                cui_camera_close(((cui_camera_event_struct*)evt)->sender_id);
            }
            break;

        case CUI_CAMERA_EVENT_RESULT_CLOSE_ME:
            {
                cui_camera_close(((cui_camera_event_struct*)evt)->sender_id);
            }
            break;
    #endif /* __MMI_CAMERA__ */ 
    #endif /* (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMERA__)) && !defined(__MMI_CAMCORDER__) */ 

        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_MEM_FREE_ASM:

        #ifdef __MMI_CAMERA__
            if (((cui_camera_event_struct*)evt)->sender_id != GRP_ID_INVALID)
            {
                cui_camera_close(((cui_camera_event_struct*)evt)->sender_id);
            }
        #endif
        #ifdef __MMI_VIDEO_RECORDER__    
            if (((cui_vdorec_event_struct*)evt)->sender_id != GRP_ID_INVALID)
            {
                cui_camera_close(((cui_camera_event_struct*)evt)->sender_id);
            }
        #endif

            break;
        default:
            break;
    }

    if (evt->evt_id == EVT_ID_MEM_FREE_ASM)
    {
        return MMI_MEM_FREED;
    }
    else
    {
        return MMI_RET_OK;   
    }
}

void mmi_lemei_enter_audio_recorder_callback(MMI_BOOL result, S8 *file_path)
{
    if(result)
    {
        mmi_lemei_send_msg(file_path);
    }
}

static mmi_ret mmi_lemei_cui_fmgr_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        {
            cui_file_selector_result_event_struct *sel_evt = (cui_file_selector_result_event_struct*)evt;
            srv_fmgr_fileinfo_struct file_info;
            U16 temp_path[LEMEI_MAX_PATH_LEN + 1];
    
            if (sel_evt->result > 0)
            {
                cui_file_selector_get_selected_filepath(
                                        sel_evt->sender_id,
                                        &file_info,
                                        (WCHAR *) temp_path,
                                        (SRV_FMGR_PATH_MAX_LEN+1) *ENCODING_LENGTH);

                if(((file_info.type == FMGR_TYPE_BMP)
                    ||(file_info.type == FMGR_TYPE_JPG)
                    ||(file_info.type == FMGR_TYPE_JPEG)
                    ||(file_info.type == FMGR_TYPE_GIF)
                    ||(file_info.type == FMGR_TYPE_PNG)
                    ||(file_info.type == FMGR_TYPE_WBMP)
                    ||(file_info.type == FMGR_TYPE_WBM))
                    ||(file_info.size <= LEMEI_MEDIA_FILE_SIZE_LIMIT))
                {
                    mmi_lemei_send_msg((S8*)temp_path);
                }
                else
                {
                    mmi_popup_display((WCHAR*)get_string(STR_ID_FILE_TOO_LARGE), MMI_EVENT_ERROR, NULL);
                }

                cui_file_selector_close(sel_evt->sender_id);

            }
            else if (sel_evt->result == 0)
            {
                cui_file_selector_close(sel_evt->sender_id);
            }
            else
            {
                cui_file_selector_close(sel_evt->sender_id);
            }

            break;
        }
        
        default:
            break;
    }
    
    return MMI_RET_OK;
}

#endif /*__MMI_OP02_LEMEI__*/

