/* vapp_3d_game.cpp

	IG 3D Game startup functions

	[Last Modified] 2011-05-24 - remove TurnOn/OffBacklight to resolve an issue not being able to enter autolock

*/

#include "mmi_features.h"

#ifdef __MMI_3D_GAME_INTERGRAFX__

#ifdef __cplusplus
extern "C"
{
#endif

#include "ig3d_adaptation.h"
#include "mmi_rp_vapp_3dgame_def.h"

/////////////////////////////////////////////////////////////

#ifdef __MTK_TARGET__
extern kal_uint32 INT_SwitchStackToRun(
                    void *stack_start,
                    kal_uint32 stack_size,
                    kal_func_ptr func,
                    kal_uint32 argc,
                    ...);
extern void kal_check_stack(void);
static unsigned char sNewStack[10*1024];
#endif /* __MTK_TARGET__ */ 



static void IGP_OnGameActivated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //PU8 gui_buffer;
    IGPlatformConfig PC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    
    g_iExited = 0;
    
    // determine if it's on phone call status
    #ifdef __MMI_BACKGROUND_CALL__
				if (srv_ucm_is_background_call())
             g_uIsOnPhoneCall = 1;
        else
        	   g_uIsOnPhoneCall = 0;
    #endif
    
    if (!ig_engine_mem_buffer) {
    	 ig_engine_mem_buffer = mmi_frm_asm_alloc_r(g_IGAppID, IG_3D_GAME_POOL_SIZE); 
    	  MMI_ASSERT(ig_engine_mem_buffer);  //impossible
    }

    gdi_layer_get_active(&g_IGNativeWindow);  // get active layer's handle
    gdi_layer_get_buffer_ptr(&g_pIGFrameBuffer);   // get frame buffer pointer 

    /* reset clip */
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    /* enable multilayer */
    gdi_layer_multi_layer_enable();

    /* suspend background play */
    mdi_audio_suspend_background_play();

    /* set audio volumn */
    mdi_audio_set_mute(MDI_VOLUME_MEDIA, MMI_FALSE);
    
    g_iSoundVol = 4;
    IGSound_SetVol(g_iSoundVol);

    /* stop MMI sleep */
    //srv_backlight_turn_on((gpio_backlight_time_enum) 0);

#ifdef __MMI_SUBLCD__
    /* draw game icon on sublcd */
    ForceSubLCDScreen(mmi_ig_draw_sublcd_icon);
#endif /* __MMI_SUBLCD__ */ 

    /* disalbe align timer, this will let timer more accurate */
    UI_disable_alignment_timers();

    ig_set_current_time();
    
    
    
    // register pen & keypad function
	IGSystem_RegisterTouchHandlers();

    IGDisplay_GetWindowSize((S32 *) &PC.m_uScrWidth, (S32 *) &PC.m_uScrHeight);

    PC.m_pFrameBuffer = g_pIGFrameBuffer;
    PC.m_pMemoryBuf = ig_engine_mem_buffer;
    PC.m_bTopdown = 1;
    PC.m_uMemSize = IG_3D_GAME_POOL_SIZE;
    
		#if defined(__MTK_TARGET__)
		
			// call IGGame_Update function
	    INT_SwitchStackToRun(
	        sNewStack,
	        1024 * 10,
	        (kal_func_ptr)IGGame_OnStartup,
	        1,
	        (void *)&PC);
	        
	  #else
	  
    IGGame_OnStartup(&PC);
	  
	  #endif    
    
    //CY: draw one frame for screen switch effect (SSE)
		IGSystem_ForceUpdate();

    ig_start_timer(1, ig_timer_callback);    
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
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop game */
    // stop video if video playback is ongoing
    IGSystem_StopVideo();
    
    IGGame_OnShutdown();

    /* Free Memory */
    if (ig_engine_mem_buffer!=NULL)
    {
		mmi_frm_asm_free_r(VAPP_3DGAME, ig_engine_mem_buffer);
		ig_engine_mem_buffer = NULL;
    }
    
    ig_cancel_timer(ig_timer_callback);

    /* restore timer to default accuracy */
    UI_enable_alignment_timers();

    /* disable faster key handling */
    mmi_frm_set_key_handle_in_high_frequency(MMI_FALSE);

    /* re-enable the keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* stop all playing audio */
    mdi_audio_stop_string();

    /* resume background play */
    mdi_audio_resume_background_play();

#ifdef __MMI_SUBLCD__
    /* resume sublcd */
    GoBackSubLCDHistory();
#endif /* __MMI_SUBLCD__ */ 

    /* let MMI can sleep */
    //srv_backlight_turn_off();
}

extern void IG1(void);
extern void IG2(void);

////////////////////////////////////////////////////////////////////////

static void mmi_exit_ig_scrn(void)
{
	//IG implement to free all resource and memory
	IGP_OnGameDeactivated();
}

static void mmi_entry_ig_scrn(void)
{
    if (mmi_frm_scrn_enter(g_IGAppID, SCR_ID_IG_MAIN, (FuncPtr)mmi_exit_ig_scrn,(FuncPtr)mmi_entry_ig_scrn, MMI_FRM_FULL_SCRN))
    {
        /* set game CABC mode to moving mode to save backlight energy */
    #if defined(__MMI_CABC__)
        mmi_frm_set_cabc_mode(MMI_FRM_CABC_MODE_MOVING);
    #endif     
        IGP_OnGameActivated();                       
    }
}

mmi_ret mmi_ig_group_proc(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
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
        // user cancel it, memory did not free to IG, close group
        mmi_frm_group_close(g_IGAppID);
        break;
    case EVT_ID_ASM_PREPARED:
		//prepare success, enter group           
        break;
	case EVT_ID_ASM_POST_PREPARED:
		if (ig_engine_mem_buffer == NULL)
		{
			ig_engine_mem_buffer = mmi_frm_asm_alloc_r(g_IGAppID, IG_3D_GAME_POOL_SIZE);
			if (ig_engine_mem_buffer == NULL)
			{
				MMI_ASSERT(0);
			}
		}
		mmi_entry_ig_scrn();
		break;
    }
    return MMI_RET_OK;
}

#ifdef __cplusplus
}
#endif

extern "C" MMI_ID vapp_3d_game_launch(mmi_app_launch_param_struct* param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_IGAppID =  VAPP_3DGAME;

	mmi_frm_group_create(GRP_ID_ROOT,g_IGAppID, mmi_ig_group_proc, NULL);
	mmi_frm_group_enter(g_IGAppID, MMI_FRM_NODE_SMART_CLOSE_FLAG);
	mmi_frm_asm_prepare(VAPP_3DGAME, 0, (mmi_proc_func)mmi_ig_prepare_proc, NULL, MMI_FRM_ASM_F_NONE); 
    
    return MMI_RET_OK;
}
#endif
