/* vapp_3d_game.cpp

   IG 3D Game startup functions

   [Last Modified] 2012-02-06 - Remove FrameSync update to driver level

*/
#include "mmi_features.h"

#ifdef __MMI_3D_GAME_INTERGRAFX__

#ifdef __cplusplus
extern "C"
{
#endif

#include "ig3d_adaptation56.h"
#include "mmi_rp_vapp_3dgame_def.h"
#include "Gui_effect_oem.h"
#include "MMI_features.h"

#include <math.h>
#include <GLES2/gl2.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include "gpu_memory_if.h"
#include "cache_sw.h"

/*IG engine header*/
#include "IGV5Memory.h"
#include "IGV5Renderer.h"
#include "IGV5Game.h"

/// Enable 4xFSAA on real-target
#ifdef __MTK_TARGET__
#define EGL_ENABLE_MSAA
#endif

extern char g_iMuteState;
extern char g_MTKVolKeyMuteState;

typedef struct
{
   EGLDisplay   sEGLDisplay;
   EGLContext   sEGLContext;
   EGLSurface   sEGLSurface;
   unsigned int width;
   unsigned int height;
   EGLNativeWindowType nativeWindow;
} IG_RENDER_INFO_STRUCT_T;

/////////////////////////////////////////////////////////
extern IGV5Event sEventList[128];
extern unsigned uNumEvents;
extern int g_IG_TouchNum;


extern void igvideo_play_done_callback(MDI_RESULT result, void *user_data);
extern void IGV5Game_Resume();
extern void IGV5Game_Suspend();

extern char g_iSoundVol; 
extern char g_iMuteState; 
extern char g_MTKVolKeyMuteState;


/*global flag to determine the status of the 3D game*/
int g_ig_isHomeKey = 0;
int g_ig_isSuspend = 0;
int g_ig_isFirstEnter = 0;

#if defined(__MMI_MAINLCD_480X800__)
   #define IG_C_BUFFER_SIZE  4*1024*1024   /// 1.5MB cache
   #define IG_NC_BUFFER_SIZE 10*1024*1024  /// 5.5MB non-cache
#else
   #define IG_C_BUFFER_SIZE  3*1024*1024   /// 1.5MB cache
   #define IG_NC_BUFFER_SIZE 9*1024*1024   /// 5.5MB non-cache
#endif

void *ig_engine_nc_buffer = NULL;
void *ig_engine_c_buffer = NULL;

KAL_ADM_ID ig_game_adm_id;
KAL_ADM_ID ig_game_nc_adm_id;

static IG_RENDER_INFO_STRUCT_T     ig_RenderInfo;

/*************************************************************/
void ig_memory_allocator_init(void)
{
    ig_engine_c_buffer = mmi_frm_asm_alloc_r(g_IGAppID, IG_C_BUFFER_SIZE);
    if (ig_engine_c_buffer == NULL)
    {
        MMI_ASSERT(0);
    }

    ig_engine_nc_buffer = mmi_frm_asm_alloc_nc_r(g_IGAppID, IG_NC_BUFFER_SIZE);
    if (ig_engine_nc_buffer == NULL)
    {
        MMI_ASSERT(0);
    }

    ig_game_adm_id = kal_adm_create(ig_engine_c_buffer, IG_C_BUFFER_SIZE, NULL, KAL_FALSE);
    ig_game_nc_adm_id = kal_adm_create(ig_engine_nc_buffer, IG_NC_BUFFER_SIZE, NULL, KAL_FALSE);
}


void *ig_memory_malloc(unsigned int size, MEM_CACHED_TYPE_ENUM m_type, int alignmnt)
{
   void *buffer = NULL;
   
   if (CACHEABLE_MEM == m_type)
   {
       buffer = kal_adm_alloc(ig_game_adm_id, size);
	   if (buffer == NULL)
	   {
           MMI_ASSERT(0);
	   }
   }      
   else
   {
       buffer = kal_adm_alloc(ig_game_nc_adm_id, size);
	    if (buffer == NULL)
	   {
           MMI_ASSERT(0);
	   }
   }

   return buffer;    
}


void *ig_memory_realloc(void *ptr, unsigned int size, MEM_CACHED_TYPE_ENUM m_type)
{
   void *buffer = NULL;
   
   if (CACHEABLE_MEM == m_type)
   {
       buffer = kal_adm_realloc(ig_game_adm_id, ptr, size);
   }      
   else
   {
       buffer = kal_adm_realloc(ig_game_nc_adm_id, ptr, size);  
   }     
   
   if (buffer == NULL)
   {      
      MMI_ASSERT(0);
   }

   return buffer;
}

void ig_memory_free(void *address, MEM_CACHED_TYPE_ENUM m_type)
{
   if (CACHEABLE_MEM == m_type)
   {
       kal_adm_free(ig_game_adm_id, address);
   }      
   else
   {
       kal_adm_free(ig_game_nc_adm_id, address);  
   }        
}

#pragma arm section code

static IGV5RC sEngineRC;
static IGV5InitInfoVer0101 sInitInfo;
static unsigned uLastTime, uTempTime;

extern int g_ig_is_video_open;
extern int g_ig_is_video_play ;
extern int g_VideoStop;

void igv5_timer_callback(void)
{
   float finterval;

   if (g_iExited || g_ig_isHomeKey)
   {
      return;
   }

   if (g_ig_isSuspend)
   {
        ig_start_timer(1000, igv5_timer_callback);
        return;
   }

    // If we stop video playback somewhere else, it's time to make a true stop here
   if (g_VideoStop)
   {
      igvideo_play_done_callback(MDI_RES_VDOPLY_SUCCEED, 0);
      g_VideoStop=0;
   }
   else
   {
       if (g_ig_is_video_play == TRUE) 
       {
          goto _L2;
       }
   }

   uTempTime = IGV5Time_Get();

   finterval = (uTempTime - uLastTime > 2000) ? 0.05f : (float)(uTempTime - uLastTime) * 0.001f;

   glViewport(0,0,ig_RenderInfo.width,ig_RenderInfo.height);


   IGV5Game_Update(&sEngineRC, finterval, uNumEvents, sEventList);

   uNumEvents = 0;

   //IGV5Font_DrawNum(&sEngineRC, 50, 50, g_IG_TouchNum, 0xffffffff);

   uLastTime = uTempTime;

   IGV5Renderer_Present(&sEngineRC); /// swapBuffer

   if (g_iExited ==1)
   {
      GoBackHistory();
      g_iExited = 0;
      return;
   }


_L2:
   /// CY: if video playback is in progress, only trigger timer to detect video stop around 20FPS
   if (g_ig_is_video_play == TRUE) 
   {
      ig_start_timer(50, igv5_timer_callback);
   }
   else
   {
      ig_start_timer(1, igv5_timer_callback);  /// otherwise, rendering applicaiton as soon as possible
   }
}

static int g_isEngineStarted = IGV5_FALSE;

void IGV5Engine_OnStartup(int width, int height)
{
    EGLConfig *aEGLConfigs = NULL;
    EGLConfig aEGLConfig;
    EGLint cEGLConfigs = 0;
	
    int i;
    int red_size = 5;
    int green_size = 6;
    int blue_size = 5;
    int alpha_size = 0;
   
    int depth_size = 16;
    int stencil_size = 0;
   
#ifdef EGL_ENABLE_MSAA
    int sample_buffers = 1;
    int samples = 4;
#else
    int sample_buffers = 0;
    int samples = 0;
#endif

    EGLint aEGLAttributes[] = {
      EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
      EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
      EGL_SAMPLE_BUFFERS, sample_buffers,
      EGL_SAMPLES, samples,
      EGL_RED_SIZE, red_size,
      EGL_GREEN_SIZE, green_size,
      EGL_BLUE_SIZE, blue_size,
      EGL_ALPHA_SIZE, alpha_size,
      EGL_DEPTH_SIZE, depth_size,
      EGL_STENCIL_SIZE, stencil_size,
      EGL_NONE
   };

   EGLint aEGLContextAttributes[] = {
      EGL_CONTEXT_CLIENT_VERSION, 2,
      EGL_NONE
   };
   
   fbdev_window *nativeWindow = NULL;
   
   ig_memory_allocator_init();
   glHookAllocatorFunctions(ig_memory_malloc, ig_memory_realloc, ig_memory_free);

   nativeWindow = (EGLNativeWindowType)ig_memory_malloc(sizeof(fbdev_window), CACHEABLE_MEM, 0);

   nativeWindow->width           = width;
   nativeWindow->height          = height;
   nativeWindow->bytes_per_pixel = 2;
   nativeWindow->address         = NULL;   
   ig_RenderInfo.nativeWindow    = nativeWindow;
   
   ig_RenderInfo.sEGLDisplay = EGL_CHECK(eglGetDisplay((EGLNativeDisplayType)1));

   EGL_CHECK(eglInitialize(ig_RenderInfo.sEGLDisplay, NULL, NULL));

   EGL_CHECK( eglChooseConfig(ig_RenderInfo.sEGLDisplay, aEGLAttributes, NULL, 0, &cEGLConfigs) );

   if (cEGLConfigs <= 0)
   {
       ASSERT(0);
   }

   aEGLConfigs = (EGLConfig *)ig_memory_malloc(sizeof(EGLConfig) * cEGLConfigs, CACHEABLE_MEM, 0);

   EGL_CHECK(eglChooseConfig(ig_RenderInfo.sEGLDisplay, aEGLAttributes, aEGLConfigs, cEGLConfigs, &cEGLConfigs));

    for (i = 0; i < cEGLConfigs; i++)
    {
        EGLint iEGLSurfaceType = 0;
        EGLint iEGLSampleBuffers = 0;
        EGLint iEGLSample = 0;
        EGLint iEGLRed = 0;
        EGLint iEGLGreen = 0;
        EGLint iEGLBlue = 0;
        EGLint iEGLAlpha = 0;
        EGLint iEGLDepth = 0;
        EGLint iEGLStencil = 0;
        EGL_CHECK( eglGetConfigAttrib((EGLDisplay)ig_RenderInfo.sEGLDisplay, aEGLConfigs[i], EGL_SURFACE_TYPE, &iEGLSurfaceType) );
        EGL_CHECK( eglGetConfigAttrib((EGLDisplay)ig_RenderInfo.sEGLDisplay, aEGLConfigs[i], EGL_SAMPLE_BUFFERS, &iEGLSampleBuffers) );
        EGL_CHECK( eglGetConfigAttrib((EGLDisplay)ig_RenderInfo.sEGLDisplay, aEGLConfigs[i], EGL_SAMPLES, &iEGLSample) );
        EGL_CHECK( eglGetConfigAttrib((EGLDisplay)ig_RenderInfo.sEGLDisplay, aEGLConfigs[i], EGL_RED_SIZE, &iEGLRed) );
        EGL_CHECK( eglGetConfigAttrib((EGLDisplay)ig_RenderInfo.sEGLDisplay, aEGLConfigs[i], EGL_GREEN_SIZE, &iEGLGreen) );
        EGL_CHECK( eglGetConfigAttrib((EGLDisplay)ig_RenderInfo.sEGLDisplay, aEGLConfigs[i], EGL_BLUE_SIZE, &iEGLBlue) );
        EGL_CHECK( eglGetConfigAttrib((EGLDisplay)ig_RenderInfo.sEGLDisplay, aEGLConfigs[i], EGL_ALPHA_SIZE, &iEGLAlpha) );
        EGL_CHECK( eglGetConfigAttrib((EGLDisplay)ig_RenderInfo.sEGLDisplay, aEGLConfigs[i], EGL_DEPTH_SIZE, &iEGLDepth) );
        EGL_CHECK( eglGetConfigAttrib((EGLDisplay)ig_RenderInfo.sEGLDisplay, aEGLConfigs[i], EGL_STENCIL_SIZE, &iEGLStencil) );


        if (!(iEGLSurfaceType & EGL_WINDOW_BIT)) { continue; }
#ifdef EGL_ENABLE_MSAA
        if (iEGLSampleBuffers != sample_buffers) { continue; }
        if (iEGLSample != samples) { continue; }
#endif
       // only 16-bits desktop can create 16-bits surface
       if (iEGLRed != red_size) { continue; }
       if (iEGLGreen != green_size) { continue; }
       if (iEGLBlue != blue_size) { continue; }

       break;
   }

   if(i >= cEGLConfigs)
   {
       i = 0;
   }
   aEGLConfig = aEGLConfigs[i];

   ig_memory_free(aEGLConfigs, CACHEABLE_MEM);

   if (cEGLConfigs == 0)
   {
        ASSERT(0);
   }

   ig_RenderInfo.width  = width;
   ig_RenderInfo.height = height;

   ig_RenderInfo.sEGLSurface = EGL_CHECK(eglCreateWindowSurface(ig_RenderInfo.sEGLDisplay, aEGLConfig, (EGLNativeWindowType)ig_RenderInfo.nativeWindow, NULL));

   if (ig_RenderInfo.sEGLSurface == EGL_NO_SURFACE)
   {
       ASSERT(0);
   }

   ig_RenderInfo.sEGLContext = EGL_CHECK(eglCreateContext(ig_RenderInfo.sEGLDisplay, aEGLConfig, EGL_NO_CONTEXT, aEGLContextAttributes));

   if (ig_RenderInfo.sEGLContext == EGL_NO_CONTEXT)
   {
      ASSERT(0);
   }

   EGL_CHECK(eglMakeCurrent(ig_RenderInfo.sEGLDisplay, ig_RenderInfo.sEGLSurface, ig_RenderInfo.sEGLSurface, ig_RenderInfo.sEGLContext));
   EGL_CHECK( eglEnableFrameSynchronization(ig_RenderInfo.sEGLDisplay, ig_RenderInfo.sEGLSurface));

   /// initialize IG engine
   /* Initialize timer */
   IGV5Time_Init();
   uLastTime = IGV5Time_Get();

   /* initialzie engine, call application startup function to override settings */
   sInitInfo.m_EGL.m_uWidth  = ig_RenderInfo.width;
   sInitInfo.m_EGL.m_uHeight = ig_RenderInfo.height;
   sInitInfo.m_EGL.m_bUseDepthBuffer = IGV5_TRUE;
   sInitInfo.m_EGL.m_bUseStencilBuffer = IGV5_FALSE;
   sInitInfo.m_pPoolPtr = ig_engine_mem_buffer;
   sInitInfo.uSize = IG_3D_GAME_POOL_SIZE;

   if (IGV5Game_Startup(&sInitInfo))
   {
      MMI_ASSERT(0);
   }

   sInitInfo.m_EGL.m_uFlags    = IGV5_EGLINIT_USE_DISPLAY | IGV5_EGLINIT_USE_SURFACE | IGV5_EGLINIT_USE_CONTEXT;
   sInitInfo.m_EGL.sEGLContext = ig_RenderInfo.sEGLContext;
   sInitInfo.m_EGL.sEGLDisplay = ig_RenderInfo.sEGLDisplay;
   sInitInfo.m_EGL.sEGLSurface = ig_RenderInfo.sEGLSurface;

   if (IGV5Engine_Init(&sEngineRC, sizeof(IGV5InitInfoVer0101), &sInitInfo) != IGV5ERR_NONE)
   {
      MMI_ASSERT(0);
   }

   if (IGV5Game_LoadContent(&sEngineRC)!= IGV5ERR_NONE)
   {
      MMI_ASSERT(0);
   }

   g_isEngineStarted = IGV5_TRUE;
}


static void IGP_OnGameResume(void)
{
    g_iExited = 0;

    // determine if it's on phone call status
    #ifdef __MMI_BACKGROUND_CALL__
        if (srv_ucm_is_background_call())
            g_uIsOnPhoneCall = 1;
        else
            g_uIsOnPhoneCall = 0;
    #endif

    gdi_layer_get_active(&g_IGNativeWindow);  // get active layer's handle
    gdi_layer_get_buffer_ptr(&g_pIGFrameBuffer);   // get frame buffer pointer

    /* reset clip */
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    /* enable multilayer */
    gdi_layer_multi_layer_enable();

    /* suspend background play */
    //mdi_audio_suspend_background_play();


    /* set audio volumn */
   // mdi_audio_set_mute(MDI_VOLUME_MEDIA, MMI_FALSE);
    
	if (g_iSoundVol>6) 
		g_iSoundVol = 6;
	if (g_iSoundVol<1) 
		g_iSoundVol = 0;
	
	mdi_audio_set_volume(MDI_VOLUME_MEDIA, g_iSoundVol);

	if (g_iMuteState || g_MTKVolKeyMuteState)
	{
		mdi_audio_set_mute(MDI_VOLUME_MEDIA, MMI_TRUE);
	}
	else
	{
		mdi_audio_set_mute(MDI_VOLUME_MEDIA, MMI_FALSE);
	}

    /*
      g_iSoundVol = 4;
      IGSound_SetVol(g_iSoundVol);
	*/
    
    if (!g_ig_isFirstEnter)
    {
	    IGV5Game_Resume();
    }
	
	/* stop MMI sleep */
    //TurnOnBacklight((gpio_backlight_time_enum) 0);

#ifdef __MMI_SUBLCD__
    /* draw game icon on sublcd */
    ForceSubLCDScreen(mmi_ig_draw_sublcd_icon);
#endif /* __MMI_SUBLCD__ */

    /* disalbe align timer, this will let timer more accurate */
    UI_disable_alignment_timers();

    ig_set_current_time();

    // register pen & keypad function
    IGSystem_RegisterTouchHandlers();
}

static void IGP_OnGameActivated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /// PU8 gui_buffer;
    IGPlatformConfig PC;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* suspend background play */
	//Wallace@IG fix>>>
    mdi_audio_suspend_background_play();
    IGP_OnGameResume();
    //Wallace@IG fix<<<

	if (!ig_engine_mem_buffer)
    {
       ig_engine_mem_buffer = mmi_frm_asm_alloc_r(g_IGAppID, IG_3D_GAME_POOL_SIZE);
       MMI_ASSERT(ig_engine_mem_buffer);  /// impossible
    }

    IGDisplay_GetWindowSize((S32 *) &PC.m_uScrWidth, (S32 *) &PC.m_uScrHeight);

    PC.m_pFrameBuffer = g_pIGFrameBuffer;
    PC.m_pMemoryBuf = ig_engine_mem_buffer;
    PC.m_bTopdown = 1;
    PC.m_uMemSize = IG_3D_GAME_POOL_SIZE;

    IGV5Engine_OnStartup(PC.m_uScrWidth,PC.m_uScrHeight);

    //CY: draw one frame for screen switch effect (SSE)
    /// IGSystem_ForceUpdate();
    ig_start_timer(1, igv5_timer_callback);
}

void IGV5Engine_OnShutdown(void)
{
	if (g_isEngineStarted == IGV5_TRUE) 
	{
		ig_memory_free(ig_RenderInfo.nativeWindow, CACHEABLE_MEM);   

		IGV5Game_Unload(&sEngineRC);
		IGV5Engine_Shutdown(&sEngineRC);
		
		kal_adm_delete(ig_game_nc_adm_id);
		kal_adm_delete(ig_game_adm_id);

		if (ig_engine_nc_buffer) 
		{
			mmi_frm_asm_free_r(g_IGAppID, ig_engine_nc_buffer);
			ig_engine_nc_buffer = NULL;
		}

		if (ig_engine_c_buffer)
        {
			mmi_frm_asm_free_r(g_IGAppID, ig_engine_c_buffer);
			ig_engine_c_buffer = NULL;
		}

		g_isEngineStarted = IGV5_FALSE;
	}
}


static void IGP_OnGameSuspend(void)
{
    //when game suspend (ex: small screen pop-up), we need to flatten the last frame content to main base layer
    gdi_handle base_layer;
	gdi_handle last_blt_layer[4];
    gdi_layer_get_blt_layer(&last_blt_layer[0], &last_blt_layer[1], &last_blt_layer[2], &last_blt_layer[3]);

	gdi_layer_get_base_handle(&base_layer);
    gdi_layer_push_and_set_active(base_layer);
    gdi_layer_flatten(last_blt_layer[0], last_blt_layer[1], last_blt_layer[2], last_blt_layer[3]);
    gdi_layer_pop_and_restore_active();

    // stop video if video playback is ongoing
    IGSystem_StopVideo();

    IGSystem_UnRegisterTouchHandlers();

    ig_cancel_timer(igv5_timer_callback);

    /* restore timer to default accuracy */
    UI_enable_alignment_timers();

    /* disable faster key handling */
    mmi_frm_set_key_handle_in_high_frequency(MMI_FALSE);

    /* re-enable the keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* stop all playing audio */
    mdi_audio_stop_string();

    /* resume background play */
    //mdi_audio_resume_background_play();

	 IGV5Game_Suspend();

#ifdef __MMI_SUBLCD__
    /* resume sublcd */
    GoBackSubLCDHistory();
#endif /* __MMI_SUBLCD__ */

    /* let MMI can sleep */
    //TurnOffBacklight();
}

/*****************************************************************************
 * FUNCTION
 *  IGP_OnGameDeactivated
 * DESCRIPTION
 *  exit game screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void IGP_OnGameDeactivated(void)
{	  
	/* stop game */
    IGV5Engine_OnShutdown();

	/* resume background play */
    mdi_audio_resume_background_play();
    /* Free Memory */
    if (ig_engine_mem_buffer!=NULL)
    {
        mmi_frm_asm_free_r(g_IGAppID, ig_engine_mem_buffer);
        ig_engine_mem_buffer = NULL;
    }
}



////////////////////////////////////////////////////////////////////////
static void mmi_exit_ig_scrn(void)
{
	IGP_OnGameSuspend();
    g_ig_isSuspend = 1;
}


static void mmi_ig_exit_group(void)
{
    IGP_OnGameDeactivated();
}


static void mmi_entry_ig_scrn(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   #ifdef __MMI_SCREEN_SWITCH_EFFECT__
      gui_screen_switch_effect_block(MMI_TRUE); //cancel SSE effect
   #endif
   mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);  //cancel anti-blinking of SSE

   if (mmi_frm_scrn_enter(g_IGAppID, SCR_ID_IG_MAIN, (FuncPtr)mmi_exit_ig_scrn,(FuncPtr)mmi_entry_ig_scrn, MMI_FRM_FULL_SCRN))
   {
      if (g_ig_isFirstEnter)
      {
          ig_engine_mem_buffer = mmi_frm_asm_alloc_r(g_IGAppID, IG_3D_GAME_POOL_SIZE);  //modify by stanley
          MMI_ASSERT(ig_engine_mem_buffer);  ///impossible
      
          IGP_OnGameActivated();
          g_ig_isFirstEnter = 0;
      }
      else
      {
          IGP_OnGameResume();
          EGL_CHECK(eglMakeCurrent(ig_RenderInfo.sEGLDisplay, ig_RenderInfo.sEGLSurface, ig_RenderInfo.sEGLSurface, ig_RenderInfo.sEGLContext));
          ig_start_timer(1, igv5_timer_callback);  //add by stanley
          g_ig_isSuspend = 0;
      }
   }
}


mmi_ret mmi_ig_group_proc(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
	case EVT_ID_GROUP_ENTER:
		{
			g_ig_isFirstEnter = 1;
		}
		break;
	case EVT_ID_GROUP_ACTIVE:
		{
			g_ig_isHomeKey = 0;
			g_ig_isSuspend = 0;
		}
		break;
	case EVT_ID_GROUP_INACTIVE:
		{
			g_ig_isSuspend = 1;
			g_ig_isFirstEnter = 0;
		}
		break;
	case EVT_ID_GROUP_FOCUSED:
		{
		}
		break;
	case EVT_ID_GROUP_DEFOCUSED:
		{
		}
		break;
	case EVT_ID_GROUP_GOBACK:
		{
			//g_ig_isHomeKey = 1; //when user press exit game
		}
		break;
	case EVT_ID_GROUP_GOBACK_IN_END_KEY:
		{
			//g_ig_isHomeKey = 1;  //press homekey
		}
		break;
	case EVT_ID_GROUP_EXIT:
		{
			g_ig_isHomeKey = 1; //when interrupt popup and press homekey to exit the popup group and ig group
			mmi_ig_exit_group();
		}
		break;
	case EVT_ID_GROUP_DEINIT:
		{
		    g_ig_isFirstEnter = 0;
		}
		break;
	case EVT_ID_ASM_FORCE_FREE:
		{
		    g_ig_isHomeKey = 1; //when OOM, exit app as home key pressed
		    mmi_ig_exit_group();
			g_ig_isFirstEnter = 1;  // next time when enter g_ig_isFirstEnter == 1
			mmi_frm_group_close(g_IGAppID); 
		}
		return MMI_FRM_ASM_FREED;
	default:
		break;
    }
    return MMI_RET_OK;
}


mmi_ret mmi_ig_prepare_proc(mmi_frm_asm_evt_struct *evt)
{
    switch(evt->evt_id)
    {
    case EVT_ID_ASM_CANCELED:
        // user cancel OOM, memory did not free to IG
        mmi_frm_group_close(g_IGAppID);
        break;
    case EVT_ID_ASM_PREPARED:
        // show screen
        g_ig_isFirstEnter = 1;
        mmi_entry_ig_scrn();
        break;
    case EVT_ID_ASM_POST_PREPARED:
        break;
    }
    return MMI_RET_OK;
}

#ifdef __cplusplus
}
#endif


/* This is the entry point for 3D Game icon */
extern "C" MMI_ID vapp_3d_game_launch(mmi_app_launch_param_struct* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_IGAppID =  VAPP_3DGAME;
    mmi_frm_group_create(GRP_ID_ROOT,g_IGAppID, mmi_ig_group_proc, NULL);
    mmi_frm_group_enter(g_IGAppID, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_frm_asm_prepare(g_IGAppID, 0, (mmi_proc_func)mmi_ig_prepare_proc, NULL, MMI_FRM_ASM_F_NONE);

    return MMI_RET_OK;
}
#endif
