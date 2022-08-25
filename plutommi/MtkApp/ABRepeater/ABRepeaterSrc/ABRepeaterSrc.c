/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************/

/*******************************************************************************
* Filename:
* ---------
*  ABRepeaterSrc.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   AB Repeater main program
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_AB_REPEATER__
#include "CommonScreens.h"
#include "ProtocolEvents.h"
//#include "HardwareEvents.h"
#include "Thrdosinterface.h"
#include "OSThreadInterfaceGprot.h"
#include "CallmanagementIdDef.h"

#include "MainMenuDef.h"
#include "FunAndGamesDefs.h"
#include "CustomCfg.h"


#include "ProfileGprots.h"
#include "SettingProfile.h"

#ifdef __MMI_PROFILE_EXTMELODY_SUPPORT__
#include "FileMgr.h"
#include "ProfileMgrGProt.h"
#endif /* __MMI_PROFILE_EXTMELODY_SUPPORT__ */ 


#include "mdi_datatype.h"
#include "mdi_audio.h"

#include "FileManagerGProt.h"
#include "FileManagerDef.h"
#include "FileMgr.h"
#include "FileMgrGprot.h"

#include "ABRepeaterResDef.h"
#include "ABRepeaterDef.h"
#include "ABRepeaterType.h"
#include "ABRepeaterProt.h"
#include "ABRepeaterMainScreen.h"
#include "DataMgr.h"
#ifdef __DRM_SUPPORT__
#ifdef __MTK_TARGET__
#include "Drm_gprot.h"
#endif /* __MTK_TARGET__ */ 
#endif /* __DRM_SUPPORT__ */ 
#include "Conversions.h"

#include "USBDeviceGprot.h"
#include "gpioInc.h"    /* TurnOnBacklight */

#ifdef __OTG_ENABLE__
#include "usb_host_ms_if.h"
#endif 

#include "UCMSrvGProt.h"
#include "PhoneSetupGprots.h"

abrepeat_struct g_abrepeat;

#define MAX_FWD_REW_DIV_VAL 16
U16 g_mmi_abrepeat_option_highlighted_item;


/* manish variables */
S32 g_mmi_abrepeat_Back_Stop = FALSE;
S32 g_mmi_abrepeat_Option_lsk_stop = FALSE;
U8 g_abrepeat_repeat_always_finish = 0;
extern U16 g_mmi_abrepeat_Callback;


static mmi_data_record_store_type g_abrepeat_ab_record_store;
U8 g_mmi_abrepeat_setting_storage = 0;

ab_data_struct g_mmi_abrepeat_abplay_data[MAX_AB_POINT];
BOOL g_mmi_abrepeat_record_exist[MAX_AB_POINT];
BOOL g_mmi_abrepeat_start_progress = FALSE;
BOOL g_mmi_abrepeat_end_progress = FALSE;
BOOL g_mmi_abrepeat_first_time_entry = TRUE;
extern const abrepeat_skin_struct g_abrepeat_skins[NO_OF_AB_SKIN];
BOOL g_mmi_abrepeat_section_deleted = FALSE;    /* for checking the release of button after deletion */
signed char g_mmi_abrepeat_draw_refer_state[MAX_AB_POINT] = 
{
    AB_SECTION_DISABLED, AB_SECTION_DISABLED,
        AB_SECTION_DISABLED, AB_SECTION_DISABLED,
        AB_SECTION_DISABLED, AB_SECTION_DISABLED,
        AB_SECTION_DISABLED, AB_SECTION_DISABLED,
        AB_SECTION_DISABLED, AB_SECTION_DISABLED
};

MMI_BOOL go_back_from_popup = MMI_FALSE;

#ifdef SIMULATOR_TESTING
BOOL inscreen_first_time = TRUE;
extern U32 offset;
#endif /* SIMULATOR_TESTING */ 

#ifdef __MTK_TARGET__
#define CACHE_HEADER_SIZE sizeof(cache_header_struct)

typedef struct
{
    kal_uint32 self_checksum;
    kal_uint32 audio_checksum;
    kal_uint32 audio_file_size;
    kal_uint32 duration;
} cache_header_struct;

static U32 build_cache_progress;
static FS_HANDLE fd_idx;
static MMI_BOOL audio_checksum_done = MMI_FALSE;

static void *g_abrepeat_app_mem_pool = NULL;
static KAL_ADM_ID g_abrepeat_adm_id = NULL;

static U8 *file_buf_p = NULL;
static U8 *proc_buf_p = NULL;

#if defined(__MTK_TARGET__)
__align(4) 
#endif
static U8 cache[ABR_CACHE_SIZE];

extern kal_bool aud_util_build_cache_start( kal_wchar *filename, 
                                           void* cache_p, kal_int32 cache_size, 
                                           void *file_buf, kal_int32 file_buf_size, 
                                           void *proc_buf, kal_int32 proc_buf_size );
extern void aud_util_build_cache_stop( void );
extern kal_bool aud_util_build_cache_process( kal_uint32 *progress_p );
extern kal_uint32 aud_util_build_cache_get_duration( void );
extern kal_uint32 med_crc_calculate(kal_uint8 const *data, kal_uint32 length);
#endif /* __MTK_TARGET__ */

#define __PROTOTYPES
static U8 mmi_abrepeat_util_count_optional_drv(void);
static void mmi_abrepeat_app_pre_entry(void);
static void mmi_abrepeat_entry_select_storage(void);
static void mmi_abrepeat_get_drive_callback(S8 drv_letter);
static void mmi_abrepeat_entry_fmgr_list(void);
static void mmi_abrepeat_fmgr_list_exit_function(void);
static void mmi_abrepeat_fmgr_list_entry_function(void);
static void mmi_abrepeat_apply_select_file(void);



/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_is_record_valid
* DESCRIPTION
*  check whether is the data record is valid
* PARAMETERS
*  record      [?]     
* RETURNS
* BOOL
*****************************************************************************/
BOOL mmi_abrepeat_is_record_valid(ab_data_struct *record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (record->keyindex < MAX_AB_POINT && record->abstart < record->abend)
    {
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_build_cache_ptr
* DESCRIPTION
*  get the cache pointer
* PARAMETERS
*  void
* RETURNS
*  void*
*****************************************************************************/
void* mmi_abrepeat_build_cache_ptr(void)
{
    void *cache_p = NULL;
    
#ifdef __MTK_TARGET__
    if( build_cache_progress == 100 )
        cache_p = (void *)&cache[CACHE_HEADER_SIZE];
#endif /* __MTK_TARGET__ */
    
    return cache_p;
}

#ifdef __MTK_TARGET__

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_free_asm_resource
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_free_asm_resource(void)
{
    kal_status ret;
    
    if(g_abrepeat_adm_id != NULL)
    {
        kal_adm_free(g_abrepeat_adm_id, file_buf_p);
        file_buf_p = NULL;
        kal_adm_free(g_abrepeat_adm_id, proc_buf_p);
        proc_buf_p = NULL;
        
        ret = kal_adm_delete(g_abrepeat_adm_id);
        ASSERT(ret == KAL_SUCCESS);
        g_abrepeat_adm_id = NULL;
    }
    
    if(g_abrepeat_app_mem_pool)
    {
        applib_mem_ap_free(g_abrepeat_app_mem_pool);
        g_abrepeat_app_mem_pool = NULL;
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_app_asm_stop_cb
* DESCRIPTION
*  Function to close AB-Repeater application if asm stop is called
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_app_asm_stop_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    abrepeat_scr_id_enum del_scr_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_abrepeat_free_asm_resource();
    
    ASSERT(g_abrepeat_adm_id == NULL);
    ASSERT(g_abrepeat_app_mem_pool == NULL);
    
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_AB_REPEATER, KAL_TRUE);
    
    /* TOOD: see if DeleteBetweenScreen be used for efficiency */
    if (IsScreenPresent(SCR_ID_ABREPEAT_FMGR_LIST))
    {
        mmi_fmgr_close_option_screen();
    }
    for (del_scr_id = SCR_ID_ABREPEAT_BASE + 1;del_scr_id < NO_OF_SCR_ABREPEAT; del_scr_id++)
    {
        DeleteScreenIfPresent(del_scr_id);
    }
    mmi_fmgr_close_service(g_abrepeat.fmgr_instance_id);
}

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_app_mem_success_callback
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_app_mem_success_callback(void)
{
    g_abrepeat_app_mem_pool = 
        applib_mem_ap_alloc(APPLIB_MEM_AP_ID_AB_REPEATER, ABREPEAT_APP_ASM_BUF_SIZE);
    ASSERT(g_abrepeat_app_mem_pool != NULL);
    
    mmi_abrepeat_build_cache_start();
}  

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_build_cache_start
* DESCRIPTION
*  start the process of build cache
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_build_cache_start(void)
{
    if(g_abrepeat_app_mem_pool == NULL)
    {
        g_abrepeat_app_mem_pool = 
            applib_mem_ap_alloc(APPLIB_MEM_AP_ID_AB_REPEATER, ABREPEAT_APP_ASM_BUF_SIZE);
        
        if (g_abrepeat_app_mem_pool == NULL)
        {
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_AB_REPEATER,
                0,
                ABREPEAT_APP_ASM_BUF_SIZE,
                mmi_abrepeat_app_mem_success_callback);
            return;
        }
    }
    
    ASSERT(g_abrepeat_app_mem_pool != NULL);
    g_abrepeat_adm_id = kal_adm_create((void*)g_abrepeat_app_mem_pool, 
        ABREPEAT_APP_ASM_BUF_SIZE, NULL, KAL_FALSE);
    ASSERT(g_abrepeat_adm_id != NULL);
    proc_buf_p = (U8*)kal_adm_alloc(g_abrepeat_adm_id, ABR_PROC_BUF_SIZE);
    ASSERT(proc_buf_p != NULL);
    file_buf_p = (U8*)kal_adm_alloc(g_abrepeat_adm_id, ABR_FILE_BUF_SIZE);
    ASSERT(file_buf_p != NULL);

    
    if (aud_util_build_cache_start( g_abrepeat.filefullname, 
        (void *)&cache[CACHE_HEADER_SIZE], ABR_CACHE_SIZE-CACHE_HEADER_SIZE, 
        (void *)file_buf_p, ABR_FILE_BUF_SIZE, 
        (void *)proc_buf_p, ABR_PROC_BUF_SIZE ))
    {
        mmi_abrepeat_entry_build_cache();
    }
    else
    {
        mmi_abrepeat_free_asm_resource();
        mmi_display_popup(get_string(STR_ID_ABREPEAT_BUILD_CACHE_FAILED), MMI_EVENT_FAILURE);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_build_cache_process
* DESCRIPTION
*  build cache process
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_build_cache_process(void)
{
    U32 write_size;
    U32 prev_progress = build_cache_progress;
    S32 fs_result = FS_NO_ERROR;
    
    if((build_cache_progress == 100) || aud_util_build_cache_process( &build_cache_progress ))
    {
        if( build_cache_progress == 100 )
        {
            g_abrepeat.total_offset = aud_util_build_cache_get_duration();
            ((cache_header_struct*)&cache[0])->duration = g_abrepeat.total_offset;
            ((cache_header_struct*)&cache[0])->self_checksum = 
                med_crc_calculate( (kal_uint8 const *)&cache[CACHE_HEADER_SIZE], 
                ABR_CACHE_SIZE-CACHE_HEADER_SIZE );
            if( audio_checksum_done )
            {
                ((cache_header_struct*)&cache[0])->audio_checksum = g_abrepeat.audio_checksum;
                ((cache_header_struct*)&cache[0])->audio_file_size = g_abrepeat.audio_file_size;
            }
            aud_util_build_cache_stop();
            g_abrepeat.fwd_rew_units = (U32) (g_abrepeat.total_offset / MAX_FWD_REW_DIV_VAL);
            g_mmi_abrepeat_first_time_entry = TRUE;
            if( fd_idx >= 0 )
            {
                FS_Seek( fd_idx, 0, FS_FILE_BEGIN );
                fs_result = FS_Write( fd_idx, (void *)&cache[0], ABR_CACHE_SIZE, &write_size );
                FS_Close( fd_idx );
                
                fd_idx = -1;
            }
            /*when fs error popup*/
            if(fs_result != FS_NO_ERROR)
            {
                mmi_display_popup(
                    get_string(mmi_fmgr_util_get_fs_error_string(fs_result)), 
                    mmi_fmgr_util_get_fs_error_popup_type(fs_result));
            }
            else
            {
                if( prev_progress != build_cache_progress )
                    UpdateCategory402Value( build_cache_progress, NULL);
        
                mmi_abrepeat_entry_main();  /* call main setting screen */
            }

            DeleteScreenIfPresent( SCR_ID_AB_BUILD_CACHE );
        }
        else 
        {
            if( prev_progress != build_cache_progress )
                UpdateCategory402Value( build_cache_progress, NULL);
        
            gui_start_timer(20, mmi_abrepeat_build_cache_process);
        }
    }
    else
    {
        mmi_display_popup(get_string(mmi_abrepeat_err_str((S32) MDI_AUDIO_ERROR)), MMI_EVENT_FAILURE);
        DeleteScreenIfPresent( SCR_ID_AB_BUILD_CACHE );
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_entry_build_cache
* DESCRIPTION
*  enter the screen of build cache
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_entry_build_cache(void)
{
    EntryNewScreen(SCR_ID_AB_BUILD_CACHE, 
        mmi_abrepeat_exit_build_cache, 
        mmi_abrepeat_entry_build_cache, 
        NULL);
    
    TurnOnBacklight(0);     /* prevent backlight being turned off */
    mdi_audio_suspend_background_play();
    
    ShowCategory402Screen( 
        (U8*)GetString(STR_ID_ABREPEAT_BUILDING_CACHE), /* title string */
        GetRootTitleIcon(MENU_ID_ABREPEAT_APP_MENU_ITEM), /* title icon */
        (build_cache_progress == 100) ? STR_GLOBAL_DONE: 0, 0, /* LSK */
        (build_cache_progress == 100) ? STR_GLOBAL_BACK: STR_GLOBAL_CANCEL, 0, /* RSK */
        (U8*) g_abrepeat.title,
        build_cache_progress,
        NULL);
    
    /* register LSK & RSK UP handlers */
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetDelScrnIDCallbackHandler(SCR_ID_AB_BUILD_CACHE, 
        (HistoryDelCBPtr) mmi_abrepeat_exit_build_cache_root);
    
    gui_start_timer(20, mmi_abrepeat_build_cache_process);
}

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_exit_build_cache
* DESCRIPTION
*  exit the screen of build cache
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_exit_build_cache(void)
{
    gui_cancel_timer(mmi_abrepeat_build_cache_process);

    TurnOffBacklight();
    mdi_audio_resume_background_play();
}

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_exit_build_cache_root
* DESCRIPTION
*  exit the root of build_cache screen
* PARAMETERS
*  param_p     [IN]
* RETURNS
*  U8
*****************************************************************************/
U8 mmi_abrepeat_exit_build_cache_root(void *param_p)
{    
    aud_util_build_cache_stop();
    if( fd_idx >= 0 )
    {
        FS_Close( fd_idx );
    }

    mmi_abrepeat_free_asm_resource();
    
    return FALSE;
}
#endif /* __MTK_TARGET__ */

/*****************************************************************************
* FUNCTION
*  InitABRepeaterApp
* DESCRIPTION
*  Initialization function of AB Repeater Application
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void InitABRepeaterApp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_abrepeat_read_settings();

#ifdef __MTK_TARGET__
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_AB_REPEATER,
        STR_ID_ABREPEAT_TITLE, 
        IMG_ID_ABREPEAT_SUBMENU_ICON,
        mmi_abrepeat_app_asm_stop_cb);
#endif 
}


/*****************************************************************************
* FUNCTION
*  HighlightABRepeater
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void HighlightABRepeater(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);
    
    SetLeftSoftkeyFunction(mmi_abrepeat_app_pre_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    
    SetKeyHandler(mmi_abrepeat_app_pre_entry, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(GoBackHistory, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


static void mmi_abrepeat_app_pre_entry(void)
{
#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif
#ifdef __USB_IN_NORMAL_MODE__
        /* check is in mass storage mode */
        if (mmi_usb_is_in_mass_storage_mode())
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
#endif /* __USB_IN_NORMAL_MODE__ */ 
    g_abrepeat.drv_num = mmi_abrepeat_util_count_optional_drv();
    if (g_abrepeat.drv_num < 2 && g_abrepeat.storage != (U8)MMI_PUBLIC_DRV)
    {
        g_abrepeat.storage = (U8)MMI_PUBLIC_DRV;
    }

    g_abrepeat.fmgr_instance_id = 0;

    if (FS_NO_ERROR != FS_GetDevStatus(g_abrepeat.storage, FS_MOUNT_STATE_ENUM))
    {
        g_abrepeat.storage = 0;
        mmi_display_popupcallback(
            get_string(STR_ID_ABREPEAT_NOTIFY_STORAGE_NOT_READY),
            MMI_EVENT_FAILURE,
            mmi_abrepeat_entry_select_storage);
    }
    else
    {
        mmi_abrepeat_entry_fmgr_list();
    }   
}


static void mmi_abrepeat_entry_select_storage(void)
{
    EntryNewScreen(SCR_ID_ABREPEAT_SELECT_STORAGE, NULL, mmi_abrepeat_entry_select_storage, NULL);
    mmi_fmgr_sel_drv_and_enter(APP_ABREPEATER, mmi_abrepeat_get_drive_callback, g_abrepeat.storage);
    if (g_abrepeat.fmgr_instance_id != 0)
    {
        mmi_fmgr_close_option_screen();
    }
}

static void mmi_abrepeat_get_drive_callback(S8 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
	kal_wchar root_dir[25];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!drv_letter)
	{
	    DeleteScreenIfPresent(SCR_ID_ABREPEAT_SELECT_STORAGE);
        GoBackHistory();
        return;
	}
    
    if (g_abrepeat.storage != (U8)drv_letter)
    {
		/*
		**	Storage changed, Write new value to NVRAM and pop up successful information.
		**	Then need change the base path of file manager instance and reset highlight index.
		*/
		g_abrepeat.storage = (U8)drv_letter;
		
		WriteValue(NVRAM_ABREPEAT_STORAGE, &g_abrepeat.storage, DS_BYTE, &error);


        if (g_abrepeat.fmgr_instance_id != 0)
        {
            mmi_display_popup(get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
            DeleteScreenIfPresent(SCR_ID_ABREPEAT_SELECT_STORAGE);
            kal_wsprintf(root_dir, "%c:\\", (S8) drv_letter);
            mmi_ucs2cat((S8*)root_dir, (const S8*)(L"Audio\\"));
            
            mmi_fmgr_browse_change_filepath(APP_ABREPEATER, (S8*)root_dir);
        }
        else
        {
            mmi_display_popupcallback(
    			get_string(STR_GLOBAL_DONE),
    			MMI_EVENT_SUCCESS,
    			mmi_abrepeat_entry_fmgr_list);

            DeleteScreenIfPresent(SCR_ID_ABREPEAT_SELECT_STORAGE);
        }
	}
    else
    {
        if (IsScreenPresent(SCR_ID_ABREPEAT_FMGR_LIST))
        {
            mmi_display_popup(get_string(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS);
            DeleteScreenIfPresent(SCR_ID_ABREPEAT_SELECT_STORAGE);
        }
        else
        {
            mmi_display_popupcallback(
                get_string(STR_GLOBAL_DONE),
                MMI_EVENT_SUCCESS,
                mmi_abrepeat_entry_fmgr_list);
        }
    }
}

static void mmi_abrepeat_entry_fmgr_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    kal_wchar root_dir[25];
    mmi_fmgr_browse_setting_struct setting;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EntryNewScreen(SCR_ID_ABREPEAT_FMGR_LIST, NULL, mmi_abrepeat_entry_fmgr_list, NULL); 
    
    FMGR_FILTER_INIT(&filter);  /* set the filters */
    
    /* FMGR_FILTER_SET(&filter, FMGR_TYPE_WAV); */
    FMGR_FILTER_SET(&filter, FMGR_TYPE_AMR);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_DAF);
#ifdef __DRM_V02__
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
#endif /*__DRM_V02__*/
    
	if (FS_GetDevStatus(g_abrepeat.storage, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
		g_abrepeat.storage = (U8)MMI_PUBLIC_DRV;
		kal_wsprintf(root_dir, "%c:\\", (S8)MMI_PUBLIC_DRV);
		mmi_ucs2cat((PS8)root_dir, (const PS8)(L"Audio\\"));
    }
	else
	{
		kal_wsprintf(root_dir, "%c:\\", (S8)g_abrepeat.storage);
		mmi_ucs2cat((PS8)root_dir, (const PS8)(L"Audio\\"));
    }
    mmi_fmgr_browse_init_setting(&setting);
    setting.display_type = FMGR_DISPLAY_TYPE_BANNER_LIST;

    setting.option_menu_id = MENU_ID_ABREPEAT_FMGR_OPTION;
    setting.empty_opt_menu_id = MENU_ID_ABREPEAT_FMGR_OPTION_EMPTY;
    setting.entry_callback = mmi_abrepeat_fmgr_list_entry_function;
    setting.quit_callback = mmi_abrepeat_fmgr_list_exit_function;

    if (g_abrepeat.drv_num < 2)
    {
        setting.empty_opt_menu_id = 0;
    }
    
    g_abrepeat.fmgr_instance_id = 
        mmi_fmgr_browse_path(
            APP_ABREPEATER,
            FMGR_SELECT_ARCHIVE_WITH_SINGLE_OBJECT,
            filter,
            (S8*)root_dir,
            &setting);
}

static void mmi_abrepeat_fmgr_list_entry_function(void)
{

}

static void mmi_abrepeat_fmgr_list_exit_function(void)
{
    DeleteUptoScrID(SCR_ID_ABREPEAT_FMGR_LIST);
    DeleteScreenIfPresent(SCR_ID_ABREPEAT_FMGR_LIST);
    GoBackHistory();
}

void mmi_abrepeat_highlight_fmgr_option_select(void)
{
    SetLeftSoftkeyFunction(mmi_abrepeat_apply_select_file, KEY_EVENT_UP);
    SetKeyHandler(mmi_abrepeat_apply_select_file, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif

}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_hint_fmgr_option_storage
* DESCRIPTION
*  Function to show the current storage hint
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_hint_fmgr_option_storage(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_fmgr_get_drive_name((S8)g_abrepeat.storage, (S8*)hintData[index], (FMGR_MAX_DRIVE_NAME_LEN + 1) * ENCODING_LENGTH);
}

void mmi_abrepeat_highlight_fmgr_option_storage(void)
{
    SetLeftSoftkeyFunction(mmi_abrepeat_entry_select_storage, KEY_EVENT_UP);
    SetKeyHandler(mmi_abrepeat_entry_select_storage, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif  
}


static void mmi_abrepeat_apply_select_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    S32 aud_result;
    UI_character_type storagePath[FMGR_MAX_PATH_LEN + 1];
    UI_character_type absStoragePath[FMGR_MAX_PATH_LEN + 1];
    UI_string_type ptr;
#ifdef __MTK_TARGET__
    U32 read_size;
    U32 cache_checksum;
    void* buf;
    FS_HANDLE fd;
    kal_int32 fs_result;
#endif
    /* manish here */
    S32 len;
    UI_character_type ext[FMGR_MAX_EXT_LEN + 2];
    U8 i;
    UI_character_type tmpTitle[FMGR_MAX_FILE_LEN + 1];
    
    FMGR_FILE_INFO_STRUCT file_info;
    PS8                   filepath;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    filepath = mmi_fmgr_get_current_fileinfo(&file_info, NULL);
    ASSERT(filepath);
    g_abrepeat.is_short_name = file_info.is_short;
    mmi_ucs2cpy((PS8) g_abrepeat.filefullname, (const PS8)filepath);

    /* Extract the file name without extension for saving the ab points for this file */
    mmi_ucs2cpy((S8*) storagePath, (S8*) g_abrepeat.filefullname);
    /* manish to ensure abs file created ok for all files even with files 
    having dots inbetween */
    len = mmi_ucs2strlen((S8*) storagePath);
    ptr = &storagePath[len];
    for (;len > 0; ptr--,len--)
    {
        if (*ptr == L'.')
        {
            break;
        }
    }
    
    ASSERT(*ptr == L'.');
    
    mmi_ucs2cpy((S8*)ext, (S8*)ptr);
    
    mmi_ucs2cpy((S8*) ptr, (S8*) L".abr");
    
    g_abrepeat.cur_mode = AB_SETTING_MODE;
    g_abrepeat.is_init_scrolling_text = FALSE;
    g_abrepeat.is_replay_on = FALSE;
    
    /* Open the file for saving and retreiving the ab points */
    
#ifdef __MTK_TARGET__
#ifdef __DRM_V02__
    if(DRM_is_archive(NULL, (PU16)storagePath))
    {
        PS8 sepa = mmi_ucs2rchr((S8*)storagePath, (U16) L'\\');
        *sepa = (S8)'_';
    }
#endif /*__DRM_V02__*/
#endif /*__MTK_TARGET__*/

    mmi_ucs2cpy((S8*)absStoragePath, (S8*)storagePath);
    result = mmi_data_init_record_store(&g_abrepeat_ab_record_store, (S8*) absStoragePath, sizeof(ab_data_struct));
    
    mmi_ucs2cpy((PS8)tmpTitle, (PS8)mmi_fmgr_extract_file_name((PS8)g_abrepeat.filefullname)); 
    if(g_abrepeat.is_short_name)
    {
        mmi_chset_mixed_text_to_ucs2_str(
            (U8*) g_abrepeat.title,
            (FMGR_MAX_PATH_LEN + 1) * ENCODING_LENGTH,
            (U8*) tmpTitle,
            g_chset_text_encoding);
    }
    else
    {
        mmi_ucs2cpy((PS8)g_abrepeat.title, (PS8)tmpTitle);
    }
#if !defined(__MMI_SHOW_DAF_FILE_EXT__)   
    for (i = 0; i <= FMGR_MAX_EXT_LEN; i++)
    {
        if (ext[i] >= 97 && ext[i] <= 122)
        {
            ext[i] -= 32;
        }
    }
    
    if (mmi_ucs2cmp((PS8)ext, (PS8)L".MP3") == 0) 
    {
        mmi_abrepeat_hide_ext_name((PS8)g_abrepeat.title);
    }    
#endif /*!defined(__MMI_SHOW_DAF_FILE_EXT__) */
    
    /* calculate audio content checksum */
#ifdef __MTK_TARGET__
    audio_checksum_done = FALSE;
    build_cache_progress = 0;
#ifdef __DRM_SUPPORT__
    fs_result = fd = DRM_open_file( (PU16)g_abrepeat.filefullname, FS_READ_ONLY, DRM_PERMISSION_PLAY );
    if(fd >= 0)
    {
        if (!DRM_validate_permission(fd, NULL, DRM_PERMISSION_PLAY))
        {
            DRM_close_file(fd);
            mmi_display_popup(get_string( STR_GLOBAL_DRM_PROHIBITED ), MMI_EVENT_FAILURE);
            mmi_fmgr_close_option_screen();
            return;
        }
    }

#else
    fs_result = fd = FS_Open( g_abrepeat.filefullname, FS_READ_ONLY );
#endif
    if( fd >= 0 )
    {
        buf = get_ctrl_buffer( 1024 );
        read_size = 0;
#ifdef __DRM_SUPPORT__
        if( (fs_result = DRM_read_file( fd, buf, 1024, &read_size )) == FS_NO_ERROR && read_size != 0 )
#else
            if( (fs_result = FS_Read( fd, buf, 1024, &read_size )) == FS_NO_ERROR && read_size != 0 )
#endif
            {
                g_abrepeat.audio_checksum = med_crc_calculate( (kal_uint8 const *) buf, read_size );
                /*add audio file size for validation process */
#ifdef __DRM_SUPPORT__   
                if ((fs_result = DRM_file_size(fd, &g_abrepeat.audio_file_size)) == FS_NO_ERROR && g_abrepeat.audio_file_size != 0) 
#else 
                    if ((fs_result = FS_GetFileSize(fd, &g_abrepeat.audio_file_size)) == FS_NO_ERROR && g_abrepeat.audio_file_size != 0) 
#endif
                    {
                        audio_checksum_done = TRUE;
                    }
            }
            
#ifdef __DRM_SUPPORT__
            DRM_close_file( fd );
#else
            FS_Close( fd );
#endif
            free_ctrl_buffer( buf );
    }
    
    /* open idx file */
    if( audio_checksum_done )
    {
        mmi_ucs2cpy((S8*) ptr, (S8*) L".idr");
        if( (fd_idx = FS_Open( storagePath, FS_CREATE | FS_ATTR_HIDDEN )) >= 0 )
        {
            if( FS_Read( fd_idx, (void *)cache, ABR_CACHE_SIZE, &read_size ) == FS_NO_ERROR 
                && read_size == ABR_CACHE_SIZE )
            {
                if( g_abrepeat.audio_checksum == ((cache_header_struct*)&cache[0])->audio_checksum 
                    && g_abrepeat.audio_file_size == ((cache_header_struct*)&cache[0])->audio_file_size)
                {
                    cache_checksum = med_crc_calculate( (kal_uint8 const *)
                        &cache[CACHE_HEADER_SIZE], ABR_CACHE_SIZE-CACHE_HEADER_SIZE );
                    if( cache_checksum == ((cache_header_struct*)&cache[0])->self_checksum )
                    {
                        FS_Close( fd_idx );
                        g_abrepeat.total_offset = ((cache_header_struct*)&cache[0])->duration;
                        g_abrepeat.fwd_rew_units = (U32) (g_abrepeat.total_offset / MAX_FWD_REW_DIV_VAL);
                        g_mmi_abrepeat_first_time_entry = TRUE;
                        build_cache_progress = 100;
                        mmi_abrepeat_entry_main();  /* call main setting screen */
                        mmi_fmgr_close_option_screen();
                        return;
                    }
                }
            }
        }
        
        /*if need build cache, delete the abs file and reinit data*/
        FS_Delete((WCHAR*)absStoragePath);
        mmi_data_init_record_store(&g_abrepeat_ab_record_store, (S8*) absStoragePath, sizeof(ab_data_struct));
        
        mmi_abrepeat_build_cache_start();
        mmi_fmgr_close_option_screen();
    }
    else
#endif /* __MTK_TARGET__ */
    {
        aud_result = mdi_audio_get_duration( g_abrepeat.filefullname, &g_abrepeat.total_offset ); 
        g_abrepeat.fwd_rew_units = (U32) (g_abrepeat.total_offset/MAX_FWD_REW_DIV_VAL);
        if( aud_result == MDI_AUDIO_SUCCESS )
        {
            g_mmi_abrepeat_first_time_entry = TRUE;
            mmi_abrepeat_entry_main(); // call main setting screen 
            mmi_fmgr_close_option_screen();
        }
#ifdef __MTK_TARGET__
#ifdef __DRM_SUPPORT__
        else if( fs_result == DRM_RESULT_NO_PERMISSION )
        {
            mmi_display_popup(get_string( STR_GLOBAL_DRM_PROHIBITED ), MMI_EVENT_FAILURE);
            mmi_fmgr_close_option_screen();
        }
#endif /*__DRM_SUPPORT__*/
#endif /* __MTK_TARGET__ */
        else
        {
            mmi_display_popup(get_string(mmi_abrepeat_err_str((S32)aud_result)), MMI_EVENT_FAILURE);
            mmi_fmgr_close_option_screen();
        }
    }
}

#ifdef __BT_SPK_VOL_CONTROL__
static MMI_BOOL mmi_abrepeat_volume_sync_callback(U8 volume, MMI_BOOL is_mute)
{
    
    if (GetActiveScreenId() == SCR_ID_AB_MAIN)
    {
        if (volume < MAX_VOL_LEVEL)
        {
            g_abrepeat.volume = volume;
            mmi_abrepeat_redraw_main_volumebar();
            mmi_abrepeat_redraw_volumectrl(AB_VOLUMECTRL_INC, FALSE);
            mmi_abrepeat_redraw_volumectrl(AB_VOLUMECTRL_DEC, FALSE);
        }
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif  /* __BT_SPK_VOL_CONTROL__ */

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_entry_main
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!go_back_from_popup)
    {
    	mdi_audio_suspend_background_play();
        //TurnOnBacklight(0);
        mmi_phnset_disable_partial_ss();
	}
    else
    {
		go_back_from_popup = MMI_FALSE;
    }    

    EntryNewScreen(SCR_ID_AB_MAIN, mmi_abrepeat_exit_main, NULL, MMI_FULL_SCREEN);
    SetDelScrnIDCallbackHandler(SCR_ID_AB_MAIN, mmi_abrepeat_delete_history_hdlr);
    if (!mdi_audio_is_background_play_suspended())
    {
        mdi_audio_suspend_background_play();    
    }
    
    g_mmi_abrepeat_Back_Stop = FALSE;
    
    entry_full_screen();
    mmi_fmgr_close_option_screen();
    
    g_abrepeat.is_main_sel_btn_down = FALSE;
    g_abrepeat.is_absection_sel_btn_down = FALSE;
    
    /* clear events from the previous screen */
    ClearKeyEvents();

    /* manish here */
    if (g_mmi_abrepeat_Callback == PLAY_STOPPED)
    {
        g_mmi_abrepeat_first_time_entry = TRUE;
        g_abrepeat.state = AB_STATE_IDLE;
    }
    
    mmi_abrepeat_redraw_setting_play_screen();
    
    if (g_mmi_abrepeat_Callback == PLAY_COMPLETED)
    {
        g_mmi_abrepeat_Callback = NOTHING;
        mmi_abrepeat_play_completed();  /* return back to func on interrupt ending */
    }
    else if (g_mmi_abrepeat_Callback == PLAY_STOPPED)
    {
        g_mmi_abrepeat_Callback = NOTHING;
    }
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_register_volume_sync_callback(
        APP_ABREPEATER, 
        MDI_AUD_VOL_LEVEL_NORMAL, 
        mmi_abrepeat_volume_sync_callback);
#endif  /* __BT_SPK_VOL_CONTROL__ */
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_register_down_handler(mmi_abrepeat_pen_down_hdlr);
    mmi_pen_register_up_handler(mmi_abrepeat_pen_up_hdlr);
    mmi_pen_register_move_handler(mmi_abrepeat_pen_move_hdlr);
    mmi_pen_register_long_tap_handler(mmi_abrepeat_pen_long_tap_hdlr);
    mmi_pen_register_repeat_handler(mmi_abrepet_pen_repeat_hdlr);
    mmi_pen_register_abort_handler(mmi_abrepeat_pen_abort_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 
    
}

extern void mmi_abrepeat_draw_probar_to_zero(void);
/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_delete_history_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  in_param        [?]     
* RETURNS
*  U8
*****************************************************************************/
U8 mmi_abrepeat_delete_history_hdlr(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_abrepeat_do_stop_action();                  /* stop audio */
    StopTimer(ABREPEAT_PROGRESS_BAR_DRAW_TIMER);    /* stop the progrss bar redraw timer too */
    gui_cancel_timer(mmi_abrepeat_draw_probar_to_zero);

    mdi_audio_resume_background_play();
	TurnOffBacklight();
    mmi_phnset_enable_partial_ss();
    
    return FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_redraw_setting_play_screen
* DESCRIPTION
*  Redraws Play and Setting Screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_redraw_setting_play_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    ab_data_struct abrepeat_ab_data;
    U8 i;
    U16 key_index;
    S32 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_abrepeat_first_time_entry)
    {
        g_mmi_abrepeat_start_progress = FALSE;
        g_mmi_abrepeat_end_progress = FALSE;
        
        g_abrepeat.curr_play_section = -1;
        g_abrepeat.prgbar_cur_offset = 0;
        if (g_abrepeat.cur_mode == AB_SETTING_MODE)
        {
            g_abrepeat.replay_btn_state = AB_REPLAY_DISABLE;
        }
        else /*play mode*/
        {
            if (g_abrepeat.is_replay_on)
            {
                g_abrepeat.replay_btn_state = AB_REPLAY_ALWAYS;
            }
            else
            {
                g_abrepeat.replay_btn_state = AB_REPLAY_ONCE;
            }      
        }
        
#ifdef SIMULATOR_TESTING
        inscreen_first_time = TRUE;
        offset = 0;
#endif /* SIMULATOR_TESTING */ 
        memset(g_mmi_abrepeat_draw_refer_state, AB_SECTION_DISABLED, MAX_AB_POINT);
    }
    
    switch (g_abrepeat.state)
    {
    case AB_STATE_IDLE:
        g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_STOP;
        break;
    case AB_STATE_PLAY:
        g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_PLAY;
        break;
    case AB_STATE_PAUSED:
        g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_PAUSE;
        break;
    }
    
    if (g_mmi_abrepeat_first_time_entry)
    {
        memset(g_mmi_abrepeat_record_exist, FALSE, MAX_AB_POINT);
        /* CHECK IF ENTRY ALREADY EXISTS IN DATA MANAGER */
        for (i = 0; i < MAX_AB_POINT; i++)
        {
            result = mmi_data_get_record(&g_abrepeat_ab_record_store, i, &abrepeat_ab_data);
            if (result == 0 && mmi_abrepeat_is_record_valid(&abrepeat_ab_data))
            {
                key_index = abrepeat_ab_data.keyindex;
                if (g_mmi_abrepeat_record_exist[key_index])
                {
                    mmi_data_delete_record(&g_abrepeat_ab_record_store, i);     /* clean duplicated records */
                }
                else
                {
                    if (AB_SETTING_MODE == g_abrepeat.cur_mode)
                    {
                        g_mmi_abrepeat_draw_refer_state[key_index] = AB_SECTION_COMPLETE_SET;
                    }
                    else
                    {
                        g_mmi_abrepeat_draw_refer_state[key_index] = AB_SECTION_NON_PLAYING;
                    }
                    g_mmi_abrepeat_abplay_data[key_index].abstart = abrepeat_ab_data.abstart;
                    g_mmi_abrepeat_abplay_data[key_index].abend = abrepeat_ab_data.abend;
                    g_mmi_abrepeat_record_exist[key_index] = TRUE;
                }
            }
        }
    }
    mmi_abrepeat_show_mainscreen(STR_ID_ABREPEAT_TITLE, STR_GLOBAL_OPTIONS, STR_GLOBAL_BACK, g_abrepeat.skin);
    
    if (g_mmi_abrepeat_first_time_entry)
    {
        g_abrepeat.abkey_state = AB_SET_IDLE;
        g_abrepeat.curr_set_section  = -1;
    }
    
    g_mmi_abrepeat_first_time_entry = FALSE;
    
    if (AB_SETTING_MODE == g_abrepeat.cur_mode)
    {
        ClearInputEventHandler(MMI_DEVICE_KEY);
        mmi_abrepeat_setting_set_key_handlers();
    }
    else
    {
        /* Draw the once/always button grey */
        ClearInputEventHandler(MMI_DEVICE_KEY);
        mmi_abrepeat_play_set_key_handlers();
    }
    mmi_abrepeat_set_mainplay_section_key_handler();

    /* manish adding here because clearallkeyhandler() has been done */
    SetKeyHandler(mmi_abrepeat_mainscr_LSK_down_hldr, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_abrepeat_mainscr_RSK_down_hldr, KEY_RSK, KEY_EVENT_DOWN);
    
    // manish chaning here to convert SetRightSoftkeyFunction into SetKeyHandler*/
    /* MTK has also done so manish not merging */
    SetKeyHandler(mmi_abrepeat_mainscr_LSK_up_hldr, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_abrepeat_mainscr_RSK_up_hldr, KEY_RSK, KEY_EVENT_UP);
    
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_rsk_action
* DESCRIPTION
*  RSK Action of the AB Repeater main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_rsk_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_abrepeat_Back_Stop = TRUE;
    
    mmi_abrepeat_do_stop_action();  /* stop audio */

    mmi_fmgr_close_option_screen();
    GoBackHistory();
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_entry_option
* DESCRIPTION
*  LSK Option Action of the AB Repeater main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_entry_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 option_items;
    U16 option_icons[4];
    U8 *tempBuffer;
    U16 option_buffer[4];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* manish adding this for stopin audio when entering into option screen */
    g_mmi_abrepeat_Option_lsk_stop = TRUE;
    //mmi_abrepeat_do_stop_action();
    
    //manish adding following lines so that after interrupt control back on option screen
    EntryNewScreen(SCR_ID_ABREPEAT_OPTION, 0, mmi_abrepeat_entry_option, NULL);
    
    /* gui buffer */
    tempBuffer = GetCurrGuiBuffer(SCR_ID_ABREPEAT_OPTION);
    
    option_buffer[0] = STR_ID_ABREPEAT_SWITCH;
    option_icons[0] = IMG_GLOBAL_L1;    /* ask for new icon */
    
    option_items = 1;
    
    /* register highligh handler */
    RegisterHighlightHandler(mmi_abrepeat_option_highlight_hdlr);
    /* show category screen */
    ShowCategory15Screen(
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_ABREPEAT_APP_MENU_ITEM),    /* title text and icon */
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,                      /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                    /* RSK text and icon */
        option_items,
        option_buffer,
        option_icons,
        LIST_MENU,
        0,
        tempBuffer);
    
    /* register LSK, RSK hanlders */
    SetLeftSoftkeyFunction(mmi_abrepeat_option_lsk, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_abrepeat_option_back, KEY_EVENT_UP);
    
    // register left, right key handlers
    SetKeyHandler(mmi_abrepeat_option_back, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_option_highlight_hdlr
* DESCRIPTION
*  Sets the highlight index for the option menu items in Options of AB Repeater
* PARAMETERS
*  index       [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_option_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_abrepeat_option_highlighted_item = (U16) index;
    
    /* manish adding this for not draw in case of going to switching screen */
    g_mmi_abrepeat_Option_lsk_stop = FALSE;
}

/* manish adding this function */


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_option_back
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_option_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_abrepeat_first_time_entry = TRUE;
    g_abrepeat.state = AB_STATE_IDLE;
    GoBackHistory();
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_option_lsk
* DESCRIPTION
*  Handler of lsk press of Option screen of AB repeater
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_option_lsk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_abrepeat_option_highlighted_item)
    {
    case 0:
        {
            if (AB_SETTING_MODE == g_abrepeat.cur_mode)
            {
                g_abrepeat.cur_mode = AB_PLAY_MODE;
            }
            else
            {
                g_abrepeat.cur_mode = AB_SETTING_MODE;
            }
            /* enter to main screen again for switching in between play and setting screen */
            g_mmi_abrepeat_first_time_entry = TRUE;
            g_abrepeat.state = AB_STATE_IDLE;
            mdi_audio_stop_file();  /* stop the playing audio */
            GoBackToHistory(SCR_ID_AB_MAIN);
            
            break;
        }
    default:
        break;
        
    }
    
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_exit_main
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_exit_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (GetActiveScreenId() == POPUP_SCREENID)
    {
		go_back_from_popup = TRUE;
        mmi_abrepeat_exit_mainscreen();
        GenericExitScreen(SCR_ID_AB_MAIN, mmi_abrepeat_entry_main);
		return;
    }   
	mmi_abrepeat_do_stop_action();
    mmi_abrepeat_exit_mainscreen();
    mdi_audio_resume_background_play();
	TurnOffBacklight();
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_clear_volume_sync_callback(APP_ABREPEATER);
#endif  /* __BT_SPK_VOL_CONTROL__ */
    GenericExitScreen(SCR_ID_AB_MAIN, mmi_abrepeat_entry_main);
}

static void mmi_abrepeat_setting_press_digit_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);

    switch (Keytype)
    {
        case KEY_EVENT_UP:
            mmi_abrepeat_setting_press_digit_up_hdlr(Keycode);
            break;
        case KEY_EVENT_DOWN:
            mmi_abrepeat_setting_press_digit_down_hdlr(Keycode);
            break;
        case KEY_EVENT_LONG_PRESS:
            mmi_abrepeat_setting_long_press_digit_hdlr(Keycode);
            break;
        default:
            break;
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_setting_set_key_handlers
* DESCRIPTION
*  Sets the key handlers of the setting screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_setting_set_key_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ABSettingScreenDigits[MAX_AB_SETTING_SCREEN_DIGITS] = {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6,
        KEY_7, KEY_8, KEY_9, KEY_POUND
    };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetGroupKeyHandler(
        mmi_abrepeat_setting_press_digit_key_hdlr,
        ABSettingScreenDigits,
        MAX_AB_SETTING_SCREEN_DIGITS - 2,
        KEY_EVENT_UP);
    SetGroupKeyHandler(
        mmi_abrepeat_setting_press_digit_key_hdlr,
        ABSettingScreenDigits,
        MAX_AB_SETTING_SCREEN_DIGITS - 2,
        KEY_EVENT_DOWN);
    SetGroupKeyHandler(
        mmi_abrepeat_setting_press_digit_key_hdlr,
        ABSettingScreenDigits,
        MAX_AB_SETTING_SCREEN_DIGITS - 2,
        KEY_EVENT_LONG_PRESS);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_setting_press_digit_down_hdlr
* DESCRIPTION
*  Handles when Setting Screen Keys are Pressed
* PARAMETERS
*  keycode     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_setting_press_digit_down_hdlr(U16 keycode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keycode != KEY_POUND)   /* screen switching */
    {
        g_abrepeat.is_absection_sel_btn_down = TRUE;
        g_abrepeat.absection_sel_btn = keycode;
        mmi_abrepeat_redraw_absection_buttons(keycode);
    }
    else
    {
        mmi_abrepeat_redraw_mode_switch_button(TRUE);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_setting_press_digit_up_hdlr
* DESCRIPTION
*  Handles when Setting Screen Keys are Released
* PARAMETERS
*  keycode     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_setting_press_digit_up_hdlr(U16 keycode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ab_data_struct abrepeat_ab_data;
    
    U8 i;
    S32 result;
    S32 aud_result = MDI_AUDIO_SUCCESS;
    BOOL entryexists = FALSE;
    static U16 lastkeycode;
    U32 abs_end_offset;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* after deletion don't enter the normal setting operation ..Return from here.. */
    if (g_mmi_abrepeat_section_deleted == TRUE)
    {
        g_abrepeat.is_absection_sel_btn_down = FALSE;
        mmi_abrepeat_redraw_absection_buttons(keycode);
        
        g_mmi_abrepeat_section_deleted = FALSE;
        return;
    }
    
    if (keycode == KEY_POUND)
    {
        g_abrepeat.is_absection_sel_btn_down = FALSE;
        g_abrepeat.cur_mode = AB_PLAY_MODE;
        mmi_abrepeat_do_stop_action();  /* stop the playing audio */
        /* enter to main screen again for switching in between play and setting screen */
        g_mmi_abrepeat_first_time_entry = TRUE;
        /* mmi_abrepeat_entry_main(); */
        mmi_abrepeat_exit_mainscreen();
        mmi_abrepeat_redraw_setting_play_screen();
        return;
    }

    if (g_abrepeat.is_absection_sel_btn_down == FALSE)
    {
        return;
    }

    g_abrepeat.is_absection_sel_btn_down = FALSE;

    /* If audio file is not playing don't try to set the AB section start or end.. */
    if (g_abrepeat.state != AB_STATE_PLAY)
    {
        mmi_abrepeat_redraw_absection_buttons(keycode);
        return;
    }
    /* CHECK IF ENTRY ALREADY EXISTS IN DATA MANAGER */
    for (i = 0; i < MAX_AB_POINT; i++)
    {
        result = mmi_data_get_record(&g_abrepeat_ab_record_store, i, &abrepeat_ab_data);
        if (result == 0 && mmi_abrepeat_is_record_valid(&abrepeat_ab_data))
        {
            if (abrepeat_ab_data.keyindex == keycode)
            {
                entryexists = TRUE;
                break;
            }
        }
    }
    result = 0;
    /* If key is pressed first time and other key is not pressed single time earlier */
    if ((g_abrepeat.abkey_state == AB_SET_IDLE) && (g_abrepeat.curr_set_section  == -1))
    {
        if (!entryexists)
        {
            /* SAVE FIRST AB POINT IN TEMP variable */
#ifdef SIMULATOR_TESTING
            /* g_abrepeat.cur_setab_start_offset  = mmi_abrepeat_dummy_get_curr_offset(); */
#endif 
            aud_result = mdi_audio_get_progress_time(&g_abrepeat.cur_setab_start_offset );
            if (aud_result == MDI_AUDIO_SUCCESS)
            {
                g_abrepeat.abkey_state = AB_SET_PARTIAL;
                g_abrepeat.curr_set_section  = keycode;
                g_mmi_abrepeat_draw_refer_state[keycode] = AB_SECTION_FIRST_SET;
                g_mmi_abrepeat_start_progress = TRUE;
            }
        }
        else
        {
            g_mmi_abrepeat_draw_refer_state[keycode] = AB_SECTION_COMPLETE_SET;
        }
    }
    /* If same key is pressed second time */
    else if ((g_abrepeat.abkey_state == AB_SET_PARTIAL) && (g_abrepeat.curr_set_section  == keycode))
    {
        
#ifdef SIMULATOR_TESTING
        /* abs_end_offset = mmi_abrepeat_dummy_get_curr_offset(); */
#endif 
        
        /* Call the lower layer api to get the offset (start ab point) */
        aud_result = mdi_audio_get_progress_time(&abs_end_offset);
        if ((aud_result == MDI_AUDIO_SUCCESS) && (abs_end_offset > g_abrepeat.cur_setab_start_offset ))
        {
            for (i = 0; i < MAX_AB_POINT; i++)
            {
                result = mmi_data_get_record(&g_abrepeat_ab_record_store, i, &abrepeat_ab_data);
                if (result != 0 || !mmi_abrepeat_is_record_valid(&abrepeat_ab_data))
                {
                    break;
                }
            }
            /* SAVE SET OF AB POINT IN DATA MANAGER */
            abrepeat_ab_data.abstart = g_abrepeat.cur_setab_start_offset ;
            abrepeat_ab_data.abend = abs_end_offset;
            abrepeat_ab_data.keyindex = keycode;
            
            result = mmi_data_set_record(&g_abrepeat_ab_record_store, i, &abrepeat_ab_data, TRUE);
            
            if (result == 0)    /* Success */
            {
                g_abrepeat.abkey_state = AB_SET_IDLE;
                g_abrepeat.curr_set_section  = -1;
                g_mmi_abrepeat_draw_refer_state[keycode] = AB_SECTION_COMPLETE_SET;
                g_mmi_abrepeat_end_progress = TRUE;
                g_mmi_abrepeat_start_progress = FALSE;
            }
        }
    }
    /* If a key is pressed one time earlier but now other key is pressed first time */
    else    /* if ((g_abrepeat.curr_set_section  != keycode) && (abrepeat.abkey_state == AB_SET_PARTIAL) ) */
    {
        if (!entryexists)   /* only if pressed key doesn't have entry otherwise no treatment */
        {
            /* Call the lower layer api to get the offset (start ab point) */
            aud_result = mdi_audio_get_progress_time(&g_abrepeat.cur_setab_start_offset );
            if (aud_result == MDI_AUDIO_SUCCESS)
            {
                g_abrepeat.abkey_state = AB_SET_PARTIAL;
                g_abrepeat.curr_set_section = keycode;
                g_mmi_abrepeat_draw_refer_state[keycode] = AB_SECTION_FIRST_SET;
                /* Change the state of the key as last recording AB Section */
                g_mmi_abrepeat_draw_refer_state[lastkeycode] = AB_SECTION_DISABLED;
                mmi_abrepeat_redraw_absection_buttons(lastkeycode);
            }
        }
        else
        {
            g_mmi_abrepeat_draw_refer_state[keycode] = AB_SECTION_COMPLETE_SET;
            mmi_abrepeat_redraw_absection_buttons(keycode);
            return; /* return from here as no need to store the lastkeycode this time */
        }
    }
    lastkeycode = keycode;  /* for disabling the last absection in case its not completely set */
    mmi_abrepeat_redraw_absection_buttons(keycode);
    if (aud_result != MDI_AUDIO_SUCCESS && aud_result != MDI_AUDIO_FAIL)
    {
        mmi_display_popup(get_string(mmi_abrepeat_err_str((S32)aud_result)), MMI_EVENT_FAILURE);
    }
    else if(result < 0) /*file system error code*/
    {
        mmi_display_popup(
            get_string(mmi_fmgr_util_get_fs_error_string(result)),
            mmi_fmgr_util_get_fs_error_popup_type(result));

        if (g_abrepeat.state != AB_STATE_IDLE)
        {
            mmi_abrepeat_do_stop_action();  /* stop audio */
        }
    }
    else if (result > 0)/*data manager return error code*/
    {
        mmi_display_popup(get_string(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_setting_long_press_digit_hdlr
* DESCRIPTION
*  Handler and operation function  when AB section key is long prssed
* PARAMETERS
*  keycode     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_setting_long_press_digit_hdlr(U16 keycode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result, delresult;
    ab_data_struct abrepeat_ab_data;
    U8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_abrepeat.is_absection_sel_btn_down == MMI_FALSE)
    {
        return;
    }

    g_abrepeat.is_absection_sel_btn_down = MMI_FALSE;
    
    if (keycode != KEY_POUND)
    {
        for (i = 0; i < MAX_AB_POINT; i++)
        {
            result = mmi_data_get_record(&g_abrepeat_ab_record_store, i, &abrepeat_ab_data);
            if (result == 0 && mmi_abrepeat_is_record_valid(&abrepeat_ab_data))
            {
                if (abrepeat_ab_data.keyindex == keycode)
                {
                    /* Delete that keycode record from the data manager */
                    delresult = mmi_data_delete_record(&g_abrepeat_ab_record_store, i);
                    if (delresult == 0)
                    {
                        g_mmi_abrepeat_draw_refer_state[keycode] = AB_SECTION_DISABLED;
                        g_mmi_abrepeat_record_exist[keycode] = FALSE;
                        mmi_abrepeat_redraw_absection_buttons(keycode);
                        break;
                        /* Draw Disabled the AB button */
                    }
                }
            }
        }
        
        g_mmi_abrepeat_section_deleted = TRUE;
        
    }
}


static void mmi_abrepeat_play_press_digit_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 Keycode, Keytype;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetkeyInfo(&Keycode, &Keytype);

    switch (Keytype)
    {
        case KEY_EVENT_UP:
            mmi_abrepeat_play_press_digit_up_hdlr(Keycode);
            break;
        case KEY_EVENT_DOWN:
            mmi_abrepeat_play_press_digit_down_hdlr(Keycode);
            break;
        default:
            break;
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_play_set_key_handlers
* DESCRIPTION
*  Key handler setting function for Play Screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_play_set_key_handlers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ABPlayScreenDigits[MAX_AB_SETTING_SCREEN_DIGITS] = {KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6,
        KEY_7, KEY_8, KEY_9, KEY_STAR, KEY_POUND
    };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetGroupKeyHandler(
        mmi_abrepeat_play_press_digit_key_hdlr,
        ABPlayScreenDigits,
        MAX_AB_SETTING_SCREEN_DIGITS - 1,
        KEY_EVENT_UP);
    SetGroupKeyHandler(
        mmi_abrepeat_play_press_digit_key_hdlr,
        ABPlayScreenDigits,
        MAX_AB_SETTING_SCREEN_DIGITS - 1,
        KEY_EVENT_DOWN);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_play_press_digit_down_hdlr
* DESCRIPTION
*  Handler of key Pressed  on Play Screen
* PARAMETERS
*  keycode     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_play_press_digit_down_hdlr(U16 keycode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (keycode != KEY_POUND)
    {
        if (keycode != KEY_STAR)
        {
            g_abrepeat.is_absection_sel_btn_down = TRUE;
            g_abrepeat.absection_sel_btn = keycode;

            mmi_abrepeat_redraw_absection_buttons(keycode);
            if (g_mmi_abrepeat_record_exist[keycode] == TRUE)
            {
                mmi_abrepeat_redraw_main_button(ABREPEAT_MAIN_PLAY, TRUE);
            }            
        }
        else
        {
            g_abrepeat_repeat_always_finish = 1;
            mmi_abrepeat_redraw_once_always_button(TRUE);
        }
    }
    else
    {
        mmi_abrepeat_redraw_mode_switch_button(TRUE);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_play_press_digit_up_hdlr
* DESCRIPTION
*  Handler of key Release  on Play Screen
* PARAMETERS
*  keycode     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_play_press_digit_up_hdlr(U16 keycode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_abrepeat.is_main_sel_btn_down = FALSE;
    
    //ASSERT(g_abrepeat.replay_btn_state != AB_REPLAY_DISABLE);
    if (keycode == KEY_STAR)
    {
        g_abrepeat.is_absection_sel_btn_down = FALSE;
        if (g_abrepeat_repeat_always_finish)
        {
        if (g_abrepeat.replay_btn_state == AB_REPLAY_ONCE)
        {
            g_abrepeat.replay_btn_state = AB_REPLAY_ALWAYS;
            g_abrepeat.is_replay_on = TRUE;
        }
        else
        {
            g_abrepeat.replay_btn_state = AB_REPLAY_ONCE;
            g_abrepeat.is_replay_on = FALSE;
        }
        }
        mmi_abrepeat_redraw_once_always_button(FALSE);
        /* May be to put the code here to repeat on/off the playing audio */
        return;
    }
    if (keycode == KEY_POUND)
    {
        g_abrepeat.is_absection_sel_btn_down = FALSE;
        g_abrepeat.cur_mode = AB_SETTING_MODE;
        g_mmi_abrepeat_first_time_entry = TRUE;
        mmi_abrepeat_do_stop_action();  /* stop the playing audio */
        /* enter to main screen again for switching in between play and setting screen */
        /* mmi_abrepeat_entry_main(); */
        mmi_abrepeat_exit_mainscreen();
        mmi_abrepeat_redraw_setting_play_screen();
        return;
    }

    if (g_abrepeat.is_absection_sel_btn_down == FALSE)
    {
        return;
    }

    g_abrepeat.is_absection_sel_btn_down = FALSE;
    //ASSERT(keycode > MAX_AB_POINT);            

    if (g_mmi_abrepeat_record_exist[keycode] == TRUE)
    {
    /* Pass the g_mmi_abrepeat_abplay_data start and end to lower layer api 
        and set the play command */
        if (g_abrepeat.curr_play_section >= 0)
        {
            g_mmi_abrepeat_draw_refer_state[g_abrepeat.curr_play_section] = AB_SECTION_NON_PLAYING;
            mmi_abrepeat_redraw_absection_buttons(g_abrepeat.curr_play_section);
        }
        
        //Check for the AB_STATE_IDLE , if it is idle then give the play command
        //after giving the play command check for the result if result == TRUE then update the
        //buttons 
        if (g_abrepeat.state != AB_STATE_IDLE)
        {
            mmi_abrepeat_do_stop_action();  /* stop audio */
        }
        if (g_abrepeat.state == AB_STATE_IDLE)
        {
            g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_PLAY;
        #if defined(__MMI_BACKGROUND_CALL__)
            if (!srv_ucm_is_background_call())
        #endif
            {
                 mmi_abrepeat_redraw_main_buttons();
                 g_abrepeat.curr_play_section = keycode;
                 g_mmi_abrepeat_draw_refer_state[keycode] = AB_SECTION_PLAYING;
            }
            mmi_abrepeat_redraw_absection_buttons(keycode);
            mmi_abrepeat_do_play_action();
        }
    }
    else    /* record does not exist */
    {
        g_mmi_abrepeat_draw_refer_state[keycode] = AB_SECTION_DISABLED;
        mmi_abrepeat_redraw_absection_buttons(keycode);
    }
    /* Put the code for playing AB Points as well as display part */
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_set_mainplay_section_key_handler
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_set_mainplay_section_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const abrepeat_skin_struct *skinab_p;
    
    FuncPtr ab_button_press_hdlr[] = 
    {
        mmi_abrepeat_press_play_button_down,    /* ABREPEAT_MAIN_PLAY */
            mmi_abrepeat_press_rewind_button_down,  /* ABREPEAT_MAIN_PREV */
            mmi_abrepeat_press_forward_button_down, /* ABREPEAT_MAIN_NEXT */
            mmi_abrepeat_press_stop_button_down     /* ABREPEAT_MAIN_STOP */
    };
    FuncPtr ab_button_release_hdlr[] = 
    {
        mmi_abrepeat_press_play_button_up,      /* ABREPEAT_MAIN_PLAY */
            mmi_abrepeat_press_rewind_button_up,    /* ABREPEAT_MAIN_PREV */
            mmi_abrepeat_press_forward_button_up,   /* ABREPEAT_MAIN_NEXT */
            mmi_abrepeat_press_stop_button_up       /* ABREPEAT_MAIN_STOP */
    };
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* register play / pause, stop, prev, next button handlers */
    skinab_p = &g_abrepeat_skins[g_abrepeat.skin];
    
    SetKeyHandler(ab_button_release_hdlr[skinab_p->left_ab_key_mapping], KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(ab_button_release_hdlr[skinab_p->right_ab_key_mapping], KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(ab_button_release_hdlr[skinab_p->up_ab_key_mapping], KEY_UP_ARROW, KEY_EVENT_UP);
    SetKeyHandler(ab_button_release_hdlr[skinab_p->down_ab_key_mapping], KEY_DOWN_ARROW, KEY_EVENT_UP);
    SetKeyHandler(ab_button_press_hdlr[skinab_p->left_ab_key_mapping], KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(ab_button_press_hdlr[skinab_p->right_ab_key_mapping], KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(ab_button_press_hdlr[skinab_p->up_ab_key_mapping], KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(ab_button_press_hdlr[skinab_p->down_ab_key_mapping], KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    
    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_abrepeat_press_inc_volume_up, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(mmi_abrepeat_press_dec_volume_up, KEY_VOL_DOWN, KEY_EVENT_UP);
    SetKeyHandler(mmi_abrepeat_press_inc_volume_down, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_abrepeat_press_dec_volume_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_abrepeat_press_inc_volume_repeat, KEY_VOL_UP, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_abrepeat_press_dec_volume_repeat, KEY_VOL_DOWN, KEY_EVENT_REPEAT);

}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_stop_button_down
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_stop_button_down()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.main_selected_button == ABREPEAT_MAIN_DISABLED)
    {
        return;
    }
    
    /* change selected button & update state */
    g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_STOP;
    g_abrepeat.is_main_sel_btn_down = TRUE;
    
    mmi_abrepeat_redraw_main_button(g_abrepeat.main_selected_button, g_abrepeat.is_main_sel_btn_down);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_stop_button_up
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_stop_button_up()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.is_main_sel_btn_down && (g_abrepeat.main_selected_button == ABREPEAT_MAIN_STOP))
    {
        /* update selected button state */
        g_abrepeat.is_main_sel_btn_down = FALSE;
        
        if (g_abrepeat.state != AB_STATE_IDLE)
        {
            mmi_abrepeat_do_stop_action();  /* stop audio */
        }
        
        mmi_abrepeat_redraw_main_button(g_abrepeat.main_selected_button, g_abrepeat.is_main_sel_btn_down);
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_play_button_down
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_play_button_down()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.main_selected_button == ABREPEAT_MAIN_DISABLED)
    {
        return;
    }
    
    /* update selected button state */
    g_abrepeat.is_main_sel_btn_down = TRUE;
    
    if (g_abrepeat.state == AB_STATE_PLAY)
    {
        g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_PAUSE;     /* change selected button */
    }
    else if (g_abrepeat.state == AB_STATE_PAUSED)
    {
        g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_PLAY;      /* change selected button */
    }
    else    /* g_abrepeat.state == AB_STATE_IDLE */
    {
        g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_PLAY;      /* change selected button */
    }
    
    // update button display
    mmi_abrepeat_redraw_main_button(g_abrepeat.main_selected_button, g_abrepeat.is_main_sel_btn_down);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_play_button_up
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_play_button_up()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.is_main_sel_btn_down && ((g_abrepeat.main_selected_button == ABREPEAT_MAIN_PLAY) ||
        (g_abrepeat.main_selected_button == ABREPEAT_MAIN_PAUSE)))
    {
        /* update selected button state */
        g_abrepeat.is_main_sel_btn_down = FALSE;
        
        if (g_abrepeat.state == AB_STATE_PLAY)
        {
            mmi_abrepeat_do_pause_action(); /* do pause action */
        }
        else if (g_abrepeat.state == AB_STATE_PAUSED)
        {
            mmi_abrepeat_do_resume_action();    /* do resume action */
        }
        else    /* g_abrepeat.state == AB_STATE_IDLE */
        {
            mmi_abrepeat_do_play_action();  /* do play action */
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_rewind_button_down
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_rewind_button_down()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.main_selected_button == ABREPEAT_MAIN_DISABLED)
    {
        return;
    }
    
    /* change selected button & update state */
    g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_REWIND;
    g_abrepeat.is_main_sel_btn_down = TRUE;
    
    // update button display
    mmi_abrepeat_redraw_main_button(g_abrepeat.main_selected_button, g_abrepeat.is_main_sel_btn_down);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_rewind_button_up
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_rewind_button_up()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 aud_result = MDI_AUDIO_SUCCESS;
    S32 current_playing_offset; /* call the expected api to get the current offset */
    MMI_BOOL is_redraw_prgbar = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.is_main_sel_btn_down && (g_abrepeat.main_selected_button == ABREPEAT_MAIN_REWIND))
    {
        /* update selected button state */
        g_abrepeat.is_main_sel_btn_down = FALSE;
        if ((g_abrepeat.state == AB_STATE_PLAY) && (g_abrepeat.state != AB_STATE_PAUSED))
        {
            //when do rewind check the start of file  and in case of AB section play
            //check the start  of the AB section 
            aud_result = mdi_audio_get_progress_time((U32*) & current_playing_offset);

            if (aud_result == MDI_AUDIO_SUCCESS)
            {
                /* End */
                if(current_playing_offset > (S32)g_abrepeat.total_offset)
                {
                    current_playing_offset = g_abrepeat.total_offset ;
                }
                
                current_playing_offset -= g_abrepeat.fwd_rew_units;   /* imcrease the rewind units */

                /* Reached the starting */
                if (current_playing_offset < 0)
                {
                    current_playing_offset = 1;
                }

                if (current_playing_offset >= 0)
                {   
                    /* AB-Section is selected */
                    if (g_abrepeat.curr_play_section >= 0)
                    {
                        /* if we are about to behind A*/
                        if (current_playing_offset <
                            (S32) g_mmi_abrepeat_abplay_data[g_abrepeat.curr_play_section].abstart)
                        {
                            current_playing_offset = (S32) g_mmi_abrepeat_abplay_data[g_abrepeat.curr_play_section].abstart;
                        }
                    }
                    else
                    {
                        /* if while recording we are about to go behind A */
                        if (g_mmi_abrepeat_start_progress && (current_playing_offset < (S32) g_abrepeat.cur_setab_start_offset))
                        {
                            current_playing_offset = (S32) g_abrepeat.cur_setab_start_offset;
                        }
                    }

                    aud_result = mdi_audio_set_progress_time((U32) current_playing_offset);

                    if (aud_result == MDI_AUDIO_SUCCESS)
                    {
                        g_abrepeat.prgbar_cur_offset = current_playing_offset;
                        mmi_abrepeat_redraw_progress_bar();
                    }
                }
            }
            
        }
        
        // update main buttons
        mmi_abrepeat_redraw_main_button(g_abrepeat.main_selected_button, g_abrepeat.is_main_sel_btn_down);
        if(aud_result != MDI_AUDIO_SUCCESS)
        {
        	//mmi_abrepeat_do_stop_action();
        	//DisplayPopup((PU8) GetString(mmi_abrepeat_err_str(aud_result)), IMG_GLOBAL_WARNING, 0, 1000, (U8) WARNING_TONE);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_forward_button_down
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_forward_button_down()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.main_selected_button == ABREPEAT_MAIN_DISABLED)
    {
        return;
    }
    
    /* change selected button & update state */
    g_abrepeat.main_selected_button = (signed char)ABREPEAT_MAIN_FORWARD;
    g_abrepeat.is_main_sel_btn_down = TRUE;
    
    // update button display
    mmi_abrepeat_redraw_main_button(g_abrepeat.main_selected_button, g_abrepeat.is_main_sel_btn_down);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_forward_button_up
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_forward_button_up()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 aud_result = MDI_AUDIO_SUCCESS;
    U32 current_playing_offset; /* call the expected api to get the current offset */
    MMI_BOOL is_redraw_prgbar = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.is_main_sel_btn_down && (g_abrepeat.main_selected_button == ABREPEAT_MAIN_FORWARD))
    {
        /* update selected button state */
        g_abrepeat.is_main_sel_btn_down = FALSE;
        if ((g_abrepeat.state == AB_STATE_PLAY) && (g_abrepeat.state != AB_STATE_PAUSED))
        {
            //when do forwarding check the end of file (total offset ) and in case of AB section play
            //check the end of the AB section
            aud_result = mdi_audio_get_progress_time(&current_playing_offset);
            if (aud_result == MDI_AUDIO_SUCCESS)
            {
                current_playing_offset += g_abrepeat.fwd_rew_units;
                if (current_playing_offset < g_abrepeat.total_offset)
                {                    
                    if (g_abrepeat.curr_play_section >= 0)
                    {
                        if (current_playing_offset <
                            g_mmi_abrepeat_abplay_data[g_abrepeat.curr_play_section].abend)
                        {
                            aud_result = mdi_audio_set_progress_time(current_playing_offset);
                            is_redraw_prgbar = MMI_TRUE;
                        }
                    }
                    else
                    {
                        aud_result = mdi_audio_set_progress_time(current_playing_offset);
                        is_redraw_prgbar = MMI_TRUE;
                    }
                    if ((aud_result == MDI_AUDIO_SUCCESS) && is_redraw_prgbar)
                    {
                        g_abrepeat.prgbar_cur_offset = current_playing_offset;
                        mmi_abrepeat_redraw_progress_bar();
                    }
                    else if (aud_result == MDI_AUDIO_END_OF_FILE)
                    {
                        mmi_abrepeat_play_completed();
                    }
                }
            }
            
        }
        // update main buttons
        mmi_abrepeat_redraw_main_button(g_abrepeat.main_selected_button, g_abrepeat.is_main_sel_btn_down);
        if(aud_result != MDI_AUDIO_SUCCESS)
        {
        	//mmi_abrepeat_do_stop_action();
        	//mmi_display_popup(get_string(mmi_abrepeat_err_str(aud_result)), MMI_EVENT_FAILURE);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_dec_volume_repeat
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_dec_volume_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.volume > 0)
    {
        S16 error;
        
        mdi_audio_set_volume(VOL_TYPE_MEDIA, --g_abrepeat.volume);
        mmi_abrepeat_redraw_main_volumebar();
        WriteValue(NVRAM_ABREPEAT_VOLUME, &g_abrepeat.volume, DS_BYTE, &error);
    }

    mmi_abrepeat_redraw_volumectrl(AB_VOLUMECTRL_DEC, TRUE);
    mmi_abrepeat_redraw_volumectrl(AB_VOLUMECTRL_INC, FALSE);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_inc_volume_repeat
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_inc_volume_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.volume < MAX_VOL_LEVEL - 1)
    {
        S16 error;
        
        mdi_audio_set_volume(VOL_TYPE_MEDIA, ++g_abrepeat.volume);
        mmi_abrepeat_redraw_main_volumebar();
        WriteValue(NVRAM_ABREPEAT_VOLUME, &g_abrepeat.volume, DS_BYTE, &error);
    }
    mmi_abrepeat_redraw_volumectrl(AB_VOLUMECTRL_INC, TRUE);
    mmi_abrepeat_redraw_volumectrl(AB_VOLUMECTRL_DEC, FALSE);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_inc_volume_down
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_inc_volume_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_abrepeat_redraw_volumectrl(AB_VOLUMECTRL_INC, TRUE);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_dec_volume_down
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_dec_volume_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_abrepeat_redraw_volumectrl(AB_VOLUMECTRL_DEC, TRUE);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_inc_volume
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_inc_volume_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.volume < MAX_VOL_LEVEL - 1)
    {
        S16 error;
        
        mdi_audio_set_volume(VOL_TYPE_MEDIA, ++g_abrepeat.volume);
        mmi_abrepeat_redraw_main_volumebar();
        WriteValue(NVRAM_ABREPEAT_VOLUME, &g_abrepeat.volume, DS_BYTE, &error);
    }

    mmi_abrepeat_redraw_volumectrl(AB_VOLUMECTRL_INC, FALSE);
    mmi_abrepeat_redraw_volumectrl(AB_VOLUMECTRL_DEC, FALSE);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_press_dec_volume
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_press_dec_volume_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.volume > 0)
    {
        S16 error;
        
        mdi_audio_set_volume(VOL_TYPE_MEDIA, --g_abrepeat.volume);
        mmi_abrepeat_redraw_main_volumebar();
        WriteValue(NVRAM_ABREPEAT_VOLUME, &g_abrepeat.volume, DS_BYTE, &error);
    }
    mmi_abrepeat_redraw_volumectrl(AB_VOLUMECTRL_DEC, FALSE);
    mmi_abrepeat_redraw_volumectrl(AB_VOLUMECTRL_INC, FALSE);
}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_timer
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_timer()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_abrepeat.state == AB_STATE_PLAY)
    {
        /* call the progrss bar draw */
        if (GetActiveScreenId() == SCR_ID_AB_MAIN)
        {
            mdi_audio_get_progress_time(&g_abrepeat.prgbar_cur_offset);
            if (g_abrepeat.prgbar_cur_offset != 0)
            {
                mmi_abrepeat_redraw_progress_bar();
            }    
        }
        StartTimer(ABREPEAT_PROGRESS_BAR_DRAW_TIMER, ABREPEAT_PROGRESS_BAR_DRAW_TIMER_DELAY, mmi_abrepeat_timer);
    }

}


/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_read_settings
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_read_settings(void)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_ABREPEAT_VOLUME, &g_abrepeat.volume, DS_BYTE, &error);
    ReadValue(NVRAM_ABREPEAT_STORAGE, &g_abrepeat.storage, DS_BYTE, &error);
    if (g_abrepeat.volume == 0xFF || g_abrepeat.storage == 0xFF)
    {
        g_abrepeat.volume = 4;                              /* default value first time if NVRAM is formatted */
        g_abrepeat.storage = (U8)MMI_PUBLIC_DRV;  /* default storage */
        WriteValue(NVRAM_ABREPEAT_VOLUME, &g_abrepeat.volume, DS_BYTE, &error);
        WriteValue(NVRAM_ABREPEAT_STORAGE, &g_abrepeat.storage, DS_BYTE, &error);
    }
#else /* __MTK_TARGET__ */ 
    g_abrepeat.volume = 4;
    g_abrepeat.skin = 0;
    g_abrepeat.storage = (U8)MMI_PUBLIC_DRV;  /* default storage */
#endif /* __MTK_TARGET__ */ 
}

#if !defined(__MMI_SHOW_DAF_FILE_EXT__)  
/*****************************************************************************
* FUNCTION
*  mmi_abrepeat_hide_ext_name
* DESCRIPTION
*  hide extension file name
* PARAMETERS
*  file_name       [?]     
* RETURNS
*  void
*****************************************************************************/
void mmi_abrepeat_hide_ext_name(S8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* find ext name - by finding "." */
    S32 str_len;
    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_len = mmi_ucs2strlen(file_name);
    index = (str_len - 1) * ENCODING_LENGTH;
    
    while (index >= 0)
    {
        if (mmi_ucs2ncmp((PS8) & file_name[index], (PS8) L".", 1) == 0)
        {
            file_name[index] = '\0';
            file_name[index + 1] = '\0';
            break;
        }
        
        file_name[index] = '\0';
        file_name[index + 1] = '\0';
        index -= 2;
    }
}
#endif /*!defined(__MMI_SHOW_DAF_FILE_EXT__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_abrepeat_util_count_optional_drv
 * DESCRIPTION
 *  return optional driver number.
 *  check phone memory, memory card, SIM+ and OTG.
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_abrepeat_util_count_optional_drv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 drive; 
    U8 count = 0;
#if (defined(__OTG_ENABLE__) || defined(__SIM_PLUS__))
    U8 i = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
    {
        count++;
    }

    if (((drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
    {
        count++;
    }

    if (((drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
    {
        count++;
    }

#ifdef __OTG_ENABLE__
    for (i = 0; i < USB_HOST_MS_SUPPORT_LUN; i++)
    {
        if (((drive = FS_GetDrive(FS_DRIVE_V_EXTERNAL, i + 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
        {
            count++;
        }
    }
#endif /* __OTG_ENABLE__ */ 

#ifdef __SIM_PLUS__
    for (i = 0; i < 4; i++)
    {
        if (((drive = FS_GetDrive(FS_DRIVE_V_SIMPLUS, i + 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
        {
            count++;
        }
    }
#endif

#ifdef __MSDC2_SD_MMC__
    if (((drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 2, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
    {
        count++;
    }    
#endif

    return count;
}


void mmi_abrepeat_storage_plug_out_hdlr(void)
{
    if (FS_GetDevStatus(g_abrepeat.storage, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        /* impact ab repeater! */
        DeleteScreenIfPresent(SCR_ID_ABREPEAT_OPTION);
        DeleteScreenIfPresent(SCR_ID_AB_MAIN);
    }
}

void mmi_abrepeat_option_enabler(U16 menu_id, const FMGR_FILE_INFO_STRUCT* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (menu_id == MENU_ID_ABREPEAT_FMGR_OPTION ||
        menu_id == MENU_ID_ABREPEAT_FMGR_OPTION_EMPTY)
    {
        if (g_abrepeat.drv_num < 2)
        {
            mmi_frm_hide_menu_item(MENU_ID_ABREPEAT_FMGR_OPTION_STORAGE);
        }
    }
}

#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
MMI_BOOL mmi_abrepeat_change_default_storage_pre_check(S8 in_drv)
{
	return MMI_TRUE;
}

void mmi_abrepeat_change_default_storage(S8 in_drv)
{
	S16 error = 0;
	UI_character_type root_dir[25];
	if ((U8)in_drv != g_abrepeat.storage)
    {
    	g_abrepeat.storage = (U8)in_drv;
		WriteValue(NVRAM_ABREPEAT_STORAGE, &g_abrepeat.storage, DS_BYTE, &error);
        /* need close filemgr opt scr if this event happened in it. */
        if (g_abrepeat.fmgr_instance_id != 0)
	    {
	        mmi_fmgr_close_option_screen();
            kal_wsprintf(root_dir, "%c:\\", (S8)g_abrepeat.storage);
			mmi_ucs2cat((PS8)root_dir, (const PS8)(L"Audio\\"));
            mmi_fmgr_browse_change_filepath(APP_ABREPEATER, (PS8)root_dir);
	    }
    }
}
#endif	/* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */

#endif /* __MMI_AB_REPEATER__ */ 

