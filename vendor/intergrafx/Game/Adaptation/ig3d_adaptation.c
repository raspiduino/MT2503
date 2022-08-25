/*-------------------------------------------------

   ig3d_adaptation.c - the following codes are join efforts of MediaTek, Inc. and InterGrafx Inc (IG). 
   
   adaptation codes are first provided from MediaTek in 2006 and then joinly modified by MediaTek, Inc. and InterGrafx Inc.

2010-06-15  Minor fix: comment out screen refresh in video playback end function to prevent flick (CY)
2010-06-02  Wallace: Add IGVideo_PlayCG().
2010-06-02  Fix CG playback issue by using correct memory free function mmi_frm_asm_free_anonymous() (Stanley)
2010-05-31  Fix a sound bug in IGSound_SetMute(). We can not really get off mute status if g_iSoundVol is still 0 (CY)
2010-05-27  Stop video play when exit screen (CY)
2010-05-25  Add IGSystem_StopVideo() (CY)
2010-05-16  Add IGSound_SetMute() (CY)
2010-05-02  Add keyboard handler for both platforms, remove depricated key handler functions (CY)

-------------------------------------------------*/
#include "ig3d_adaptation.h"
#include "IGExtDef.h"
#include "IGGame.h"
//wallace add>>>
#include "IG_Launcher_FactorDef.h"
//wallace add<<<

//if IG Games are enabled
#ifdef __MMI_3D_GAME_INTERGRAFX__

#ifdef __cplusplus
extern "C"
{
#endif

//**************************************** External or Global variables

//The following global variables are used by IGV3 engine for statistically use only
extern unsigned g_uIGTotalMemUsed;
extern unsigned g_IGNumSceneTriangles;
extern unsigned g_IGNumTriRasterized;
extern unsigned g_IGNumScnenMeshes;

extern unsigned g_IGRender2DTime;
extern unsigned g_IGRender3DTime;
extern unsigned g_IGRasterizeTime;
extern unsigned g_IGRenderUITime;

//The following variable is used to indicate how many milliseconds used for render a frame for 3D application
U32 g_uFrameInterval = 0;
//The following pointer is initialized in vapp_3d_game (Cosmos) or media_app.c (Pluto) to provide memory for 3D application
void *ig_engine_mem_buffer = NULL;
//The following pointer points to a GDI surface for 3D application
gdi_handle g_IGNativeWindow;
//The following pointer points to a framebuffer provided by system to allow 3D application to draw directly on the buffer
PU8 g_pIGFrameBuffer = NULL;
//The following ID is used by 3D application to identify itself when it needs to request memory or playback multimedia objects
//Cosmos and Pluto use different app id
MMI_ID g_IGAppID = 0;
//The following variable indicates if at this time is on phone call. 
U32 g_uIsOnPhoneCall = 0;

//**************************************** Static

//This pointer is intialized when video playback is requested by 3D application. It resets to NULL after playback finished.
static void *ig_video_mem_pool = NULL;
//This GDI handle is used during video playback process and reset after playback finished
static gdi_handle play_wnd_layer_handle = GDI_NULL_HANDLE;

// event queue for 3D applications. The maximum number of accumulated events is 128.
static IGSysEvent EvtQueue[128];
static unsigned uNumEvents = 0;

// Use to display numbers on screen
static UI_character_type FrameText[10];
static kal_uint32 g_StartTime;

//The following variable indicate some video file or in-ROM video stream is opened, but not necessary in playback
static int g_mms_is_video_open = FALSE;
//The following variable indicate video playback is in progress and surely g_mms_is_video_open == TRUE!
static int g_mms_is_video_play = FALSE;

/////////////////////////////////////////////
//
// pen or keyboard handlers
//
//
static void ig_mmi_pen_move_hdlr (mmi_pen_point_struct pos)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_TOUCH1_MOVE;
		EvtQueue[uNumEvents].m_uData1 = pos.x;			//x
		EvtQueue[uNumEvents].m_uData2 = pos.y;	//y
		++uNumEvents;
	}	
}

static void ig_mmi_pen_down_hdlr (mmi_pen_point_struct pos)
{
        // check if we are inside video playback, them we just stop video playback and resume execution
        if (g_mms_is_video_play == TRUE) {
              IGVideo_Stop();	      
              //start game
    	        //ig_start_timer(1, ig_timer_callback); //CY: it cause problem to start timer in key/touch callback!
              return;
        }

	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_TOUCH1_DOWN;
		EvtQueue[uNumEvents].m_uData1 = pos.x;			//x
		EvtQueue[uNumEvents].m_uData2 = pos.y;	//y
		++uNumEvents;
	}	
}

static void ig_mmi_pen_up_hdlr (mmi_pen_point_struct pos)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_TOUCH1_UP;
		EvtQueue[uNumEvents].m_uData1 = pos.x;			//x
		EvtQueue[uNumEvents].m_uData2 = pos.y;	//y
		++uNumEvents;
	}	
}

//key handler
//#ifndef IG_NO_KEY_HANDLER  //CY: remove this define. Both Cosmos and Pluto are supported

char g_iSoundVol = 4;  // default sound volume is 4
char g_iMuteState = 0;   // default not in mute state

static void ig_key_vol_up_released_handler(void)
{
	//CY do nothing since volume is adjusted when user press immediately
}

static void ig_key_vol_down_released_handler(void)
{
	//CY do nothing since volume is adjusted when user press immediately
}

static void ig_key_vol_up_pressed_handler(void)
{
	if (g_iSoundVol < 7) {
		++g_iSoundVol;
		
	}
        IGSound_SetVol(g_iSoundVol);
}

static void ig_key_vol_down_pressed_handler(void)
{
	if (g_iSoundVol) {
		--g_iSoundVol;
		
	}
   	IGSound_SetVol(g_iSoundVol);
}


static void ig_key_left_down_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_LEFT_ARROW;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_DOWN;			
		++uNumEvents;
	}	
}

static void ig_key_right_down_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_RIGHT_ARROW;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_DOWN;			
		++uNumEvents;
	}	
}

static void ig_key_lsk_down_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_LSK;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_DOWN;			
		++uNumEvents;
	}	
}

static void ig_key_rsk_down_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_RSK;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_DOWN;			
		++uNumEvents;
	}	
}

void I1(void);

static void ig_key_csk_down_handler(void)
{
	// check if we are inside video playback, them we just stop video playback and resume execution

	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_CSK;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_DOWN;			
		++uNumEvents;
	}	
}


static void ig_key_up_down_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_UP_ARROW;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_DOWN;			
		++uNumEvents;
	}	
}

static void ig_key_down_down_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_DOWN_ARROW;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_DOWN;			
		++uNumEvents;
	}	
}

static void ig_key_left_up_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_LEFT_ARROW;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_UP;			
		++uNumEvents;
	}	
}

static void ig_key_right_up_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_RIGHT_ARROW;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_UP;			
		++uNumEvents;
	}	
}

static void ig_key_up_up_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_UP_ARROW;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_UP;			
		++uNumEvents;
	}	
}

static void ig_key_down_up_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_DOWN_ARROW;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_UP;			
		++uNumEvents;
	}	
}

static void ig_key_lsk_up_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_LSK;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_UP;			
		++uNumEvents;
	}	
}

static void ig_key_rsk_up_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_RSK;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_UP;			
		++uNumEvents;
	}	
}

static void ig_key_csk_up_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_CSK;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_UP;			
		++uNumEvents;
	}	
}

static void ig_key_0_up_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_0;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_UP;			
		++uNumEvents;
	}	
}

static void ig_key_0_down_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_0;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_DOWN;			
		++uNumEvents;
	}	
}

static void ig_key_1_up_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_1;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_UP;			
		++uNumEvents;
	}	
}

static void ig_key_1_down_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_1;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_DOWN;			
		++uNumEvents;
	}	
}

static void ig_key_2_up_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_2;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_UP;			
		++uNumEvents;
	}	
}

static void ig_key_2_down_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_2;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_DOWN;			
		++uNumEvents;
	}	
}

static void ig_key_3_up_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_3;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_UP;			
		++uNumEvents;
	}	
}

static void ig_key_3_down_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_3;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_DOWN;			
		++uNumEvents;
	}	
}

static void ig_key_4_up_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_4;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_UP;			
		++uNumEvents;
	}	
}

static void ig_key_4_down_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_4;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_DOWN;			
		++uNumEvents;
	}	
}

static void ig_key_5_up_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_5;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_UP;			
		++uNumEvents;
	}	
}

static void ig_key_5_down_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_5;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_DOWN;			
		++uNumEvents;
	}	
}

static void ig_key_6_up_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_6;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_UP;			
		++uNumEvents;
	}	
}

static void ig_key_6_down_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_6;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_DOWN;			
		++uNumEvents;
	}	
}

static void ig_key_7_up_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_7;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_UP;			
		++uNumEvents;
	}	
}

static void ig_key_7_down_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_7;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_DOWN;			
		++uNumEvents;
	}	
}

static void ig_key_8_up_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_8;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_UP;			
		++uNumEvents;
	}	
}

static void ig_key_8_down_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_8;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_DOWN;			
		++uNumEvents;
	}	
}

static void ig_key_9_up_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_9;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_UP;			
		++uNumEvents;
	}	
}

static void ig_key_9_down_handler(void)
{
	if (uNumEvents < 128)
	{
		EvtQueue[uNumEvents].m_uEventID = IGFK_9;
		EvtQueue[uNumEvents].m_uData1 = IGFK_KEY_DOWN;			
		++uNumEvents;
	}	
}

//#endif


//************************************* Adaptation functions

/* timer */

/*****************************************************************************
 * FUNCTION
 *  ig_start_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  count           [IN]        
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ig_start_timer(S32 count, void (*callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_start_timer(count, callback);

    /* sleep 2 tick ~ 10 ms */
    /* 
       this is use to solve a issue that MMI will use all the MIPS, 
       so some of the lower priority task dont have chance to execute (ex: FMT)
    */
    kal_sleep_task(2);
}


/*****************************************************************************
 * FUNCTION
 *  ig_cancel_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ig_cancel_timer(void (*callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(callback);
}

void ig_set_current_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 tick;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&tick);
    g_StartTime = kal_ticks_to_milli_secs(tick);
}

unsigned IGTimerGetTime(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 tick;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&tick);
	return kal_ticks_to_milli_secs(tick);
}

unsigned IGTimerGetInterval(void)
{
	unsigned dt;

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 tick;
	U32 cur_ms;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&tick);
	cur_ms = kal_ticks_to_milli_secs(tick);
    dt = cur_ms - g_StartTime;

	// so we can get next duration
	g_StartTime = cur_ms;

	return dt;
}


/* string & font */

void ig_itoa(S32 value, WCHAR *string, S32 radix)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_itoa(value, (UI_string_type) string, radix);
}

void IGText_DrawText(IGCHAR *string, S32 x, S32 y, stFontAttribute *FontSize, U8 r, U8 g, U8 b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(FontSize);
    offset_x = x;
    if (r2lMMIFlag)
    {
        offset_x += gui_get_string_width((UI_string_type)string);
    }
    gui_move_text_cursor(offset_x, y);
    gui_set_text_color(gui_color(r, g, b));
    //gui_set_text_border_color(gui_color(255, 255, 255));
    //gdi_layer_push_and_set_active(native_window);
    gui_print_bordered_text((UI_string_type) string);
    //gdi_layer_pop_and_restore_active();
}

/*****************************************************************************
 * FUNCTION
 *  ig_draw_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string          [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  FontSize        [IN]         
 *  r               [IN]        
 *  g               [IN]        
 *  b               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ig_draw_text(const WCHAR *string, S32 x, S32 y, stFontAttribute *FontSize, U8 r, U8 g, U8 b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(FontSize);
    offset_x = x;
    if (r2lMMIFlag)
    {
        offset_x += gui_get_string_width((UI_string_type)string);
    }
    gui_move_text_cursor(offset_x, y);
    gui_set_text_color(gui_color(r, g, b));
    gui_set_text_border_color(gui_color(255, 255, 255));
    gdi_layer_push_and_set_active(g_IGNativeWindow);
    gui_print_bordered_text((UI_string_type) string);
    gdi_layer_pop_and_restore_active();
}

void IGDrawNum(S32 x, S32 y, S32 value)
{
	stFontAttribute sfa;

	memset(&sfa,0,sizeof(sfa));

	ig_itoa(value, FrameText, 10);
	ig_draw_text(FrameText, x, y, &sfa, 255, 0, 0);  
}

/*****************************************************************************
 * FUNCTION
 *  IGText_DrawBorderText
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string          [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  FontSize        [IN]  
 *  r               [IN]        
 *  g               [IN]        
 *  b               [IN]        
 *  rb              [IN]        
 *  gb              [IN]        
 *  bb              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IGText_DrawBorderText(
        IGCHAR *string,
        S32 x,
        S32 y,
        stFontAttribute *FontSize,
        U8 r,
        U8 g,
        U8 b,
        U8 rb,
        U8 gb,
        U8 bb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(FontSize);
    offset_x = x;
    if (r2lMMIFlag)
    {
        offset_x += gui_get_string_width((UI_string_type)string);
    }
    gui_move_text_cursor(offset_x, y);
    gui_set_text_color(gui_color(r, g, b));
    gui_set_text_border_color(gui_color(rb, gb, bb));
    gdi_layer_push_and_set_active(g_IGNativeWindow);
    gui_print_bordered_text((UI_string_type) string);
    gdi_layer_pop_and_restore_active();
}


void IGTrace(char *fmt, ...)
{    
}

/* register touch handler */


/*****************************************************************************
 * FUNCTION
 *  ig_register_pen_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  kk      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void ig_register_pen_move(mmi_pen_hdlr kk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined TOUCH_PANEL_SUPPORT
    mmi_pen_register_move_handler(kk);
#endif 
}

void ig_register_pen_down(mmi_pen_hdlr kk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined TOUCH_PANEL_SUPPORT
    mmi_pen_register_down_handler(kk);
#endif 
}

void ig_register_pen_up(mmi_pen_hdlr kk)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined TOUCH_PANEL_SUPPORT
    mmi_pen_register_up_handler(kk);
#endif 
}

/* sound & audio */

void IGSound_SetMute(unsigned char ismute)
{
	g_iMuteState = ismute;
	if (g_iMuteState)
		mdi_audio_set_mute(MDI_VOLUME_MEDIA, MMI_TRUE);
		else {
			//first check if we can really set off mute state. if g_iSoundVol is 0 then we 
			//should keep mute status
			if (g_iSoundVol)
				mdi_audio_set_mute(MDI_VOLUME_MEDIA, MMI_FALSE);
		}
		
}

void IGSound_SetVol(unsigned char vol)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vol>6) vol = 6;

    if (vol==0)
        mdi_audio_set_mute(MDI_VOLUME_MEDIA, MMI_TRUE);
    else {

	if (!g_iMuteState) {
        	mdi_audio_set_mute(MDI_VOLUME_MEDIA, MMI_FALSE);
        	mdi_audio_set_volume(MDI_VOLUME_MEDIA, vol);
	}
    }

    
}

/*****************************************************************************
 * FUNCTION
 *  IGMediaHandle IGSound_OpenMIDI
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_data      [IN]         
 *  len             [IN]        
 *  repeats         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
IGMediaHandle IGSound_OpenMIDI(void *audio_data, unsigned len, unsigned char repeats)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mdi_audio_mma_open_string(0, (void *)audio_data, len, MDI_FORMAT_SMF, repeats, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  IGSound_OpenWav
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_data      [IN]         
 *  len             [IN]        
 *  repeats         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
IGMediaHandle IGSound_OpenWav(void *audio_data, unsigned len, unsigned char repeats)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mdi_audio_mma_open_string(0, (void *)audio_data, len, MDI_FORMAT_WAV, repeats, NULL, NULL);
}

IGMediaHandle IGSound_OpenMp4(void *audio_data, unsigned len, unsigned char repeats)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mdi_audio_mma_open_string(0, (void *)audio_data, len, MDI_FORMAT_MP4, repeats, NULL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  IGSound_StopMIDI
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hsound      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IGSound_StopMIDI(IGMediaHandle hsound)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(hsound)
    {
        mdi_audio_mma_stop(hsound);
    }
}


/*****************************************************************************
 * FUNCTION
 *  IGSound_StopWav
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hsound      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IGSound_StopWav(IGMediaHandle hsound)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(hsound)
    {
        mdi_audio_mma_stop(hsound);
    }
}

/*****************************************************************************
 * FUNCTION
 *  IGSound_CloseMIDI
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hsound      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IGSound_CloseMIDI(IGMediaHandle hsound)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hsound)
    {
        mdi_audio_mma_close(hsound);
    }
}


/*****************************************************************************
 * FUNCTION
 *  IGSound_CloseWav
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hsound      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IGSound_CloseWav(IGMediaHandle hsound)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mdi_result res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hsound)
    {
        mdi_audio_mma_close(hsound);
    }
}

/*****************************************************************************
 * FUNCTION
 *  IGSound_PlayWav
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hsound          [IN]        
 *  SoundFlag       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IGSound_PlayWav(IGMediaHandle hsound)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hsound)
    {
        mdi_audio_mma_stop(hsound);
        mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);
        
        mdi_audio_mma_play(hsound);  /*After W11.03*/
    }
}


/*****************************************************************************
 * FUNCTION
 *  IGSound_PlayMIDI
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hsound          [IN]        
 *  SoundFlag       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IGSound_PlayMIDI(IGMediaHandle hsound)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hsound)
    {
        mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);
       
        mdi_audio_mma_stop(hsound);
        mdi_audio_mma_play(hsound); /*After W11.03*/
    }
}

/* Date & time */

/*****************************************************************************
 * FUNCTION
 *  ig_get_seed_from_system_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/

void IGDateTime_Get(unsigned *pDay, unsigned *pHour, unsigned *pMin, unsigned *pSec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME tt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetDateTime(&tt);
    *pDay = tt.nDay;
    *pHour = tt.nHour;
    *pMin = tt.nMin;
    *pSec = tt.nSec;
}

/* Math & misc. */

/*****************************************************************************
 * FUNCTION
 *  ig_get_seed_from_system_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
unsigned IGMath_Random(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 seed = 0;
    MYTIME tt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetDateTime(&tt);
    seed = seed | tt.nDay;
    seed = seed << 24;
    seed = seed | tt.nHour;
    seed = seed << 16;
    seed = seed | tt.nMin;
    seed = seed << 8;
    seed = seed | tt.nSec;

    return seed;
}


/****************************************************************************
*  VIBRATOR FUNCTION      
*****************************************************************************/
/*****************************************************************************

 * FUNCTION
 *  IGVibratorOn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 *  count       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void IGVibratorOn(int count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_vibrator_on();
    gui_start_timer(count, IGVibratorOff);

}

/*****************************************************************************
 * FUNCTION
 *  IGVibratorOff
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void IGVibratorOff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_vibrator_off();
}

/* File system */

/*****************************************************************************
 * FUNCTION
 *  ig_FS_Open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  FileName        [IN]        
 *  Flags           [IN] FS_READ_ONLY -> read only, FS_CREATE | FS_WRITE -> create and write 
 * RETURNS
 *  
 *****************************************************************************/
IG_FS_HANDLE IGFS_Open(IGCHAR *FileName, IGU32 Flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FS_Open(FileName, Flags);
}


/*****************************************************************************
 * FUNCTION
 *  ig_FS_Close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  File        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int IGFS_Close(IG_FS_HANDLE File)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FS_Close(File);
}


/*****************************************************************************
 * FUNCTION
 *  ig_FS_Read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  File        [IN]        
 *  DataPtr     [?]         
 *  Length      [IN]        
 *  Read        [?]         
 * RETURNS
 *  
 *****************************************************************************/
int IGFS_Read(IG_FS_HANDLE File, void *DataPtr, IGU32 Length, IGU32 *Read)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FS_Read(File, DataPtr, Length, Read);
}


/*****************************************************************************
 * FUNCTION
 *  ig_FS_Write
 * DESCRIPTION
 *  
 * PARAMETERS
 *  File        [IN]        
 *  DataPtr     [?]         
 *  Length      [IN]        
 *  Written     [?]         
 * RETURNS
 *  
 *****************************************************************************/
int IGFS_Write(IG_FS_HANDLE File, void *DataPtr, IGU32 Length, IGU32 *Written)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FS_Write(File, DataPtr, Length, Written);
}


/*****************************************************************************
 * FUNCTION
 *  ig_FS_Seek
 * DESCRIPTION
 *  
 * PARAMETERS
 *  File        [IN]        
 *  Offset      [IN]        
 *  Whence      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
int IGFS_Seek(IG_FS_HANDLE File, int Offset, int Whence)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FS_Seek(File, Offset, Whence);
}


/*****************************************************************************
 * FUNCTION
 *  ig_FS_GetFilePosition
 * DESCRIPTION
 *  
 * PARAMETERS
 *  File            [IN]        
 *  Position        [?]         
 * RETURNS
 *  
 *****************************************************************************/
int IGFS_GetFilePosition(IG_FS_HANDLE File,IGU32  *Position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FS_GetFilePosition(File, Position);
}

/////////////////////////////////////////////////////////////

void IGDisplay_GetWindowSize(S32 *puw, S32 *puh)
{
    gdi_layer_push_and_set_active(g_IGNativeWindow);
    gdi_layer_get_dimension(puw, (S32 *)puh);
    gdi_layer_pop_and_restore_active();
}


/////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////

void IGSystem_RegisterTouchHandlers(void)
{
    ig_register_pen_move(ig_mmi_pen_move_hdlr);
    ig_register_pen_down(ig_mmi_pen_down_hdlr);
    ig_register_pen_up(ig_mmi_pen_up_hdlr);

	mmi_frm_set_key_handler(ig_key_vol_up_released_handler, KEY_VOL_UP, KEY_EVENT_UP);
	mmi_frm_set_key_handler(ig_key_vol_up_pressed_handler, KEY_VOL_UP, KEY_EVENT_DOWN);
	mmi_frm_set_key_handler(ig_key_vol_up_pressed_handler, KEY_VOL_UP, KEY_LONG_PRESS);
	mmi_frm_set_key_handler(ig_key_vol_up_pressed_handler, KEY_VOL_UP, KEY_REPEAT);

	mmi_frm_set_key_handler(ig_key_vol_down_released_handler, KEY_VOL_DOWN, KEY_EVENT_UP);
	mmi_frm_set_key_handler(ig_key_vol_down_pressed_handler, KEY_VOL_DOWN, KEY_EVENT_DOWN);
	mmi_frm_set_key_handler(ig_key_vol_down_pressed_handler, KEY_VOL_DOWN, KEY_LONG_PRESS);
	mmi_frm_set_key_handler(ig_key_vol_down_pressed_handler, KEY_VOL_DOWN, KEY_REPEAT);
  
    mmi_frm_set_key_handler(ig_key_left_down_handler, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    mmi_frm_set_key_handler(ig_key_right_down_handler, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    mmi_frm_set_key_handler(ig_key_up_down_handler, KEY_UP_ARROW, KEY_EVENT_DOWN);
    mmi_frm_set_key_handler(ig_key_down_down_handler, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    mmi_frm_set_key_handler(ig_key_lsk_down_handler, KEY_LSK, KEY_EVENT_DOWN);
    mmi_frm_set_key_handler(ig_key_rsk_down_handler, KEY_RSK, KEY_EVENT_DOWN);
    mmi_frm_set_key_handler(ig_key_csk_down_handler, KEY_CSK, KEY_EVENT_DOWN);
    
    mmi_frm_set_key_handler(ig_key_left_up_handler, KEY_LEFT_ARROW, KEY_EVENT_UP);
    mmi_frm_set_key_handler(ig_key_right_up_handler, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    mmi_frm_set_key_handler(ig_key_up_up_handler, KEY_UP_ARROW, KEY_EVENT_UP);
    mmi_frm_set_key_handler(ig_key_down_up_handler, KEY_DOWN_ARROW, KEY_EVENT_UP);
    mmi_frm_set_key_handler(ig_key_lsk_up_handler, KEY_LSK, KEY_EVENT_UP);
    mmi_frm_set_key_handler(ig_key_rsk_up_handler, KEY_RSK, KEY_EVENT_UP);
    mmi_frm_set_key_handler(ig_key_csk_up_handler, KEY_CSK, KEY_EVENT_UP);
    
    mmi_frm_set_key_handler(ig_key_0_down_handler, KEY_0, KEY_EVENT_DOWN);
    mmi_frm_set_key_handler(ig_key_1_down_handler, KEY_1, KEY_EVENT_DOWN);
    mmi_frm_set_key_handler(ig_key_2_down_handler, KEY_2, KEY_EVENT_DOWN);
    mmi_frm_set_key_handler(ig_key_3_down_handler, KEY_3, KEY_EVENT_DOWN);
    mmi_frm_set_key_handler(ig_key_4_down_handler, KEY_4, KEY_EVENT_DOWN);
    mmi_frm_set_key_handler(ig_key_5_down_handler, KEY_5, KEY_EVENT_DOWN);
    mmi_frm_set_key_handler(ig_key_6_down_handler, KEY_6, KEY_EVENT_DOWN);
    mmi_frm_set_key_handler(ig_key_7_down_handler, KEY_7, KEY_EVENT_DOWN);
    mmi_frm_set_key_handler(ig_key_8_down_handler, KEY_8, KEY_EVENT_DOWN);
    mmi_frm_set_key_handler(ig_key_9_down_handler, KEY_9, KEY_EVENT_DOWN);
    
    mmi_frm_set_key_handler(ig_key_0_up_handler, KEY_0, KEY_EVENT_UP);
    mmi_frm_set_key_handler(ig_key_1_up_handler, KEY_1, KEY_EVENT_UP);
    mmi_frm_set_key_handler(ig_key_2_up_handler, KEY_2, KEY_EVENT_UP);
    mmi_frm_set_key_handler(ig_key_3_up_handler, KEY_3, KEY_EVENT_UP);
    mmi_frm_set_key_handler(ig_key_4_up_handler, KEY_4, KEY_EVENT_UP);
    mmi_frm_set_key_handler(ig_key_5_up_handler, KEY_5, KEY_EVENT_UP);
    mmi_frm_set_key_handler(ig_key_6_up_handler, KEY_6, KEY_EVENT_UP);
    mmi_frm_set_key_handler(ig_key_7_up_handler, KEY_7, KEY_EVENT_UP);
    mmi_frm_set_key_handler(ig_key_8_up_handler, KEY_8, KEY_EVENT_UP);
    mmi_frm_set_key_handler(ig_key_9_up_handler, KEY_9, KEY_EVENT_UP);
}

void IGSystem_UnRegisterTouchHandlers(void)
{
	ig_register_pen_move(NULL);
    ig_register_pen_down(NULL);
    ig_register_pen_up(NULL);
	mmi_frm_clear_key_events();
	ClearAllKeyHandler();
}

//////////////////////////////////////////////////////////////////////////

static int g_VideoStop = 0;

static void video_play_done_callback(MDI_RESULT result, void *user_data);

void IGSystem_StopVideo(void)
{
	if (g_mms_is_video_play == TRUE) 
		video_play_done_callback(MDI_RES_VDOPLY_SUCCEED, 0);
	g_VideoStop=0;	
}

void ig_timer_callback(void)
{
	  //CY: if in some wiered cases, the timer was triggerred more than once and IGSystem_Exit()is called, we just return as empty timer 
	  //    callback to prevent MoDIS crash problem.
	  if (g_iExited)
			return;	
	
	  //calculate frame time
		g_uFrameInterval = IGTimerGetInterval();

		// reset UI rendering time
		g_IGRenderUITime = 0;
		
	  // If we stop video playback somewhere else, it's time to make a true stop here
		if (g_VideoStop) {
			video_play_done_callback(MDI_RES_VDOPLY_SUCCEED, 0);
			g_VideoStop=0;
		} else {
           if (g_mms_is_video_play == TRUE) 
                    goto _L2;
		}
		
		//Let 3D application to playback
		if (g_uFrameInterval > 2000)
			g_uFrameInterval = 100;
		
		IGGame_OnUpdate(g_uFrameInterval * 32768 / 4800, uNumEvents, EvtQueue);

		uNumEvents = 0;

		/* IGDrawNum(10,10,g_uFrameInterval);
		IGDrawNum(80,10,g_IGNumSceneTriangles);
		IGDrawNum(40,10,g_IGNumTriRasterized);

		IGDrawNum(10,30,g_IGRender2DTime);
		IGDrawNum(40,30,g_IGRender3DTime);
		IGDrawNum(80,30,g_IGRasterizeTime);
		IGDrawNum(110,30,g_IGRenderUITime); */

		gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);	

		//CY: avoid start a new timer to keep this callback running even after game exit
		if (g_iExited)
			return;

_L2:		
	  //CY: if video playback is in progress, only trigger timer to detect video stop around 20FPS
	  if (g_mms_is_video_play == TRUE) 
	  		ig_start_timer(50, ig_timer_callback);
	  else 
			 ig_start_timer(1, ig_timer_callback);  //otherwise, rendering applicaiton as soon as possible
}

//Force 3D applicaiton to render first frame on framebuffer to prevent flicker during SSE (Screen Switch Effect)
void IGSystem_ForceUpdate(void)
{
		g_uFrameInterval = IGTimerGetInterval();

		// reset UI rendering time
		g_IGRenderUITime = 0;
		
		if (g_VideoStop) {
			video_play_done_callback(MDI_RES_VDOPLY_SUCCEED, 0);
			g_VideoStop=0;
		} else {
           if (g_mms_is_video_play == TRUE) 
                    return;
		}
		
		IGGame_OnUpdate(g_uFrameInterval * 32768 / 4800, uNumEvents, EvtQueue);

		uNumEvents = 0;

		/* IGDrawNum(10,10,g_uFrameInterval);
		IGDrawNum(80,10,g_IGNumSceneTriangles);
		IGDrawNum(40,10,g_IGNumTriRasterized);

		IGDrawNum(10,30,g_IGRender2DTime);
		IGDrawNum(40,30,g_IGRender3DTime);
		IGDrawNum(80,30,g_IGRasterizeTime);
		IGDrawNum(110,30,g_IGRenderUITime); */

		gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);	

}


static void video_play_done_callback(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_ply_stop();
		mdi_video_ply_close_clip_file();
 
	  //mdi_audio_resume_background_play(); //CY20110613 - don't allow background music come back to life now!
    if (gdi_layer_is_multi_layer_enable() == MMI_TRUE)
    {
        gdi_layer_multi_layer_disable();
    }
    gdi_layer_set_blt_layer( 0 /*base_layer_handle*/, 0, 0, 0);
    //gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);  //CY20110615 - reduce flick after vdeo playback

    if (play_wnd_layer_handle != GDI_NULL_HANDLE)
    {
        gdi_layer_free(play_wnd_layer_handle);
		play_wnd_layer_handle = GDI_NULL_HANDLE;
    }

    mmi_frm_asm_free_anonymous(ig_video_mem_pool);
    ig_video_mem_pool = NULL;
    
    g_mms_is_video_play = FALSE;
    g_mms_is_video_open = FALSE;    

		
}

static void video_play_done_callback2(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_ply_stop();
		mdi_video_ply_close_clip_buffer();
 
	  //mdi_audio_resume_background_play(); //CY20110613 - don't allow background music come back to life now!
    if (gdi_layer_is_multi_layer_enable() == MMI_TRUE)
    {
        gdi_layer_multi_layer_disable();
    }
    gdi_layer_set_blt_layer( 0 /*base_layer_handle*/, 0, 0, 0);
    //gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1); //CY20110615 - reduce flick after vdeo playback

    if (play_wnd_layer_handle != GDI_NULL_HANDLE)
    {
        gdi_layer_free(play_wnd_layer_handle);
		play_wnd_layer_handle = GDI_NULL_HANDLE;
    }


    mmi_frm_asm_free_anonymous(ig_video_mem_pool);
    ig_video_mem_pool = NULL;
    
    g_mms_is_video_play = FALSE;
    g_mms_is_video_open = FALSE;    

    //start game
    //ig_start_timer(250, ig_timer_callback); 
}


extern void IG1();
extern void IG2();

static mdi_video_info_struct video_info;

//IG embedded game specific function
	//wallace add>>>

#ifndef __MMI_3D_GAME_INTERGRAFX_CG_FROM_FILE__

#if _IG_DA_ && _240_320_ && _EN_
	extern char _binary_IG_DA_EN_240x320_mp4_start[];
	extern char _binary_IG_DA_EN_240x320_mp4_end[];				 
#endif	

#if _IG_DA_ && _240_400_ && _EN_
	extern char _binary_IG_DA_EN_240x400_mp4_start[];
	extern char _binary_IG_DA_EN_240x400_mp4_end[];				 
#endif	

#if _IG_DA_ && _320_480_ && _EN_
	extern char _binary_IG_DA_EN_320x480_mp4_start[];
	extern char _binary_IG_DA_EN_320x480_mp4_end[];				 
#endif		

#if _IG_DA_ && _480_800_ && _EN_
	extern char _binary_IG_DA_EN_480x800_mp4_start[];
	extern char _binary_IG_DA_EN_480x800_mp4_end[];				 
#endif	

#if _IG_DA_ && _240_320_ && _CHS_
	extern char _binary_IG_DA_CH_240x320_mp4_start[];
	extern char _binary_IG_DA_CH_240x320_mp4_end[];				 
#endif	

#if _IG_DA_ && _240_400_ && _CHS_
	extern char _binary_IG_DA_CH_240x400_mp4_start[];
	extern char _binary_IG_DA_CH_240x400_mp4_end[];				 
#endif	

#if _IG_DA_ && _320_480_ && _CHS_
	extern char _binary_IG_DA_CH_320x480_mp4_start[];
	extern char _binary_IG_DA_CH_320x480_mp4_end[];				 
#endif		

#if _IG_DA_ && _480_800_ && _CHS_
	extern char _binary_IG_DA_CH_480x800_mp4_start[];
	extern char _binary_IG_DA_CH_480x800_mp4_end[];					 
#endif	

#if _IG_FT_ && _240_320_ && _EN_
	extern char _binary_IG_FT_EN_240x320_mp4_start[];
	extern char _binary_IG_FT_EN_240x320_mp4_end[];			 
#endif	

#if _IG_FT_ && _240_400_ && _EN_
	extern char _binary_IG_FT_EN_240x400_mp4_start[];
	extern char _binary_IG_FT_EN_240x400_mp4_end[];					 
#endif	

#if _IG_FT_ && _320_480_ && _EN_
	extern char _binary_IG_FT_EN_320x480_mp4_start[];
	extern char _binary_IG_FT_EN_320x480_mp4_end[];					 
#endif	

#if _IG_FT_ && _480_800_ && _EN_
	extern char _binary_IG_FT_EN_480x800_mp4_start[];
	extern char _binary_IG_FT_EN_480x800_mp4_end[];				 
#endif	

#if _IG_FT_ && _240_320_ && _CHS_
	extern char _binary_IG_FT_CH_240x320_mp4_start[];
	extern char _binary_IG_FT_CH_240x320_mp4_end[];			 
#endif	

#if _IG_FT_ && _240_400_ && _CHS_
	extern char _binary_IG_FT_CH_240x400_mp4_start[];
	extern char _binary_IG_FT_CH_240x400_mp4_end[];			 
#endif		

#if _IG_FT_ && _320_480_ && _CHS_
	extern char _binary_IG_FT_CH_320x480_mp4_start[];
	extern char _binary_IG_FT_CH_320x480_mp4_end[];	 
#endif	

#if _IG_FT_ && _480_800_ && _CHS_
	extern char _binary_IG_FT_CH_480x800_mp4_start[];
	extern char _binary_IG_FT_CH_480x800_mp4_end[];				 
#endif

#endif


	/**
	play CG from lib or mp4 file.
	*/
void IGVideo_PlayCG(int gameIdx)
{
#ifdef  __MMI_3D_GAME_INTERGRAFX_NO_CG__
    return;  //return without play any CG
#endif

		if(gameIdx <= 1){//Dancing angel

#ifdef __MMI_3D_GAME_INTERGRAFX_CG_FROM_FILE__

#if _IG_DA_ && _240_320_ && _EN_
			IGVideo_PlayFromFile((char *)L"IG_DA_EN_240x320.mp4");
#elif _IG_DA_ && _240_400_ && _EN_
			IGVideo_PlayFromFile((char *)L"IG_DA_EN_240x400.mp4");
#elif _IG_DA_ && _320_480_ && _EN_
			IGVideo_PlayFromFile((char *)L"IG_DA_EN_320x480.mp4");
#elif _IG_DA_ && _480_800_ && _EN_
			IGVideo_PlayFromFile((char *)L"IG_DA_EN_480x800.mp4");
#elif _IG_DA_ && _240_320_ && _CHS_
			IGVideo_PlayFromFile((char *)L"IG_DA_CH_240x320.mp4");
#elif _IG_DA_ && _240_400_ && _CHS_
			IGVideo_PlayFromFile((char *)L"IG_DA_CH_240x400.mp4");
#elif _IG_DA_ && _320_480_ && _CHS_
			IGVideo_PlayFromFile((char *)L"IG_DA_CH_320x480.mp4");
#elif _IG_DA_ && _480_800_ && _CHS_
			IGVideo_PlayFromFile((char *)L"IG_DA_CH_480x800.mp4");
#endif

#else

#if _IG_DA_ && _240_320_ && _EN_
			IGVideo_Play(_binary_IG_DA_EN_240x320_mp4_start, (int)_binary_IG_DA_EN_240x320_mp4_end - (int)_binary_IG_DA_EN_240x320_mp4_start);
#elif _IG_DA_ && _240_400_ && _EN_
			IGVideo_Play(_binary_IG_DA_EN_240x400_mp4_start, (int)_binary_IG_DA_EN_240x400_mp4_end - (int)_binary_IG_DA_EN_240x400_mp4_start);
#elif _IG_DA_ && _320_480_ && _EN_
			IGVideo_Play(_binary_IG_DA_EN_320x480_mp4_start, (int)_binary_IG_DA_EN_320x480_mp4_end - (int)_binary_IG_DA_EN_320x480_mp4_start);
#elif _IG_DA_ && _480_800_ && _EN_
			IGVideo_Play(_binary_IG_DA_EN_480x800_mp4_start, (int)_binary_IG_DA_EN_480x800_mp4_end - (int)_binary_IG_DA_EN_480x800_mp4_start);
#elif _IG_DA_ && _240_320_ && _CHS_
			IGVideo_Play(_binary_IG_DA_CH_240x320_mp4_start, (int)_binary_IG_DA_CH_240x320_mp4_end - (int)_binary_IG_DA_CH_240x320_mp4_start);
#elif _IG_DA_ && _240_400_ && _CHS_
			IGVideo_Play(_binary_IG_DA_CH_240x400_mp4_start, (int)_binary_IG_DA_CH_240x400_mp4_end - (int)_binary_IG_DA_CH_240x400_mp4_start);
#elif _IG_DA_ && _320_480_ && _CHS_
			IGVideo_Play(_binary_IG_DA_CH_320x480_mp4_start, (int)_binary_IG_DA_CH_320x480_mp4_end - (int)_binary_IG_DA_CH_320x480_mp4_start);
#elif _IG_DA_ && _480_800_ && _CHS_
			IGVideo_Play(_binary_IG_DA_CH_480x800_mp4_start, (int)_binary_IG_DA_CH_480x800_mp4_end - (int)_binary_IG_DA_CH_480x800_mp4_start);
#endif

#endif

		}
		else{//Flower tower

#ifdef __MMI_3D_GAME_INTERGRAFX_CG_FROM_FILE__
#if (_IG_FT_ && _320_480_ && _CHS_)
			IGVideo_PlayFromFile((char *)L"IG_FT_CH_320x480.mp4");
#endif
#if (_IG_FT_ && _320_480_ && _EN_)
			IGVideo_PlayFromFile((char *)L"IG_FT_EN_320x480.mp4");
#endif
#if (_IG_FT_ && _240_320_ && _CHS_)
			IGVideo_PlayFromFile((char *)L"IG_FT_CH_240x320.mp4");
#endif
#if (_IG_FT_ && _240_320_ && _EN_)
			IGVideo_PlayFromFile((char *)L"IG_FT_EN_240x320.mp4");
#endif
#if (_IG_FT_ && _240_400_ && _CHS_)
			IGVideo_PlayFromFile((char *)L"IG_FT_CH_240x400.mp4");
#endif
#if (_IG_FT_ && _240_400_ && _EN_)
			IGVideo_PlayFromFile((char *)L"IG_FT_EN_240x400.mp4");
#endif
#if (_IG_FT_ && _480_800_ && _CHS_)
			IGVideo_PlayFromFile((char *)L"IG_FT_CH_480x800.mp4");
#endif
#if (_IG_FT_ && _480_800_ && _EN_)
			IGVideo_PlayFromFile((char *)L"IG_FT_EN_480x800.mp4");
#endif

#else

#if _IG_FT_ && _240_320_ && _EN_
			IGVideo_Play(_binary_IG_FT_EN_240x320_mp4_start, (int)_binary_IG_FT_EN_240x320_mp4_end - (int)_binary_IG_FT_EN_240x320_mp4_start);
#elif _IG_FT_ && _240_400_ && _EN_
			IGVideo_Play(_binary_IG_FT_EN_240x400_mp4_start, (int)_binary_IG_FT_EN_240x400_mp4_end - (int)_binary_IG_FT_EN_240x400_mp4_start);
#elif _IG_FT_ && _320_480_ && _EN_
			IGVideo_Play(_binary_IG_FT_EN_320x480_mp4_start, (int)_binary_IG_FT_EN_320x480_mp4_end - (int)_binary_IG_FT_EN_320x480_mp4_start);
#elif _IG_FT_ && _480_800_ && _EN_
			IGVideo_Play(_binary_IG_FT_EN_480x800_mp4_start, (int)_binary_IG_FT_EN_480x800_mp4_end - (int)_binary_IG_FT_EN_480x800_mp4_start);
#elif _IG_FT_ && _240_320_ && _CHS_
			IGVideo_Play(_binary_IG_FT_CH_240x320_mp4_start, (int)_binary_IG_FT_CH_240x320_mp4_end - (int)_binary_IG_FT_CH_240x320_mp4_start);
#elif _IG_FT_ && _240_400_ && _CHS_
			IGVideo_Play(_binary_IG_FT_CH_240x400_mp4_start, (int)_binary_IG_FT_CH_240x400_mp4_end - (int)_binary_IG_FT_CH_240x400_mp4_start);
#elif _IG_FT_ && _320_480_ && _CHS_
			IGVideo_Play(_binary_IG_FT_CH_320x480_mp4_start, (int)_binary_IG_FT_CH_320x480_mp4_end - (int)_binary_IG_FT_CH_320x480_mp4_start);
#elif _IG_FT_ && _480_800_ && _CHS_
			IGVideo_Play(_binary_IG_FT_CH_480x800_mp4_start, (int)_binary_IG_FT_CH_480x800_mp4_end - (int)_binary_IG_FT_CH_480x800_mp4_start);
#endif

#endif
		}
	}
	//wallace add<<<


//Start play video in memory or ROM
IGMediaHandle IGVideo_Play(void *ptr, unsigned vsize)
{
	gdi_result gdi_ret = 1;
    //mdi_handle handle = 0;
    MDI_RESULT ret = 0;
    
		
	  S32 lcd_width;
	  S32 lcd_height;
	  
	  g_mms_is_video_open = g_mms_is_video_play = FALSE;

    memset(&video_info, 0, sizeof(video_info));
    ret = mdi_video_ply_open_clip_buffer(g_IGAppID, (U8 *)ptr, vsize, &video_info);
    
    if(ret!= MDI_RES_VDOPLY_SUCCEED)
	  {
		    return 0;
	  }


	  IGDisplay_GetWindowSize(&lcd_width, &lcd_height);
    ig_video_mem_pool = mmi_frm_asm_alloc_anonymous_nc(lcd_width * lcd_height * 2);

	  if (ig_video_mem_pool == NULL)
	  {
	      return 0;
	  }

    
	  gdi_ret = gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_16,
        0,
        0,
        lcd_width,
        lcd_height,
        &play_wnd_layer_handle,
        (U8 *)ig_video_mem_pool,
       lcd_width * lcd_height * 2);
        
    if (gdi_ret != GDI_SUCCEED)
    {
        MMI_ASSERT(0);
    }

    gdi_layer_push_and_set_active(play_wnd_layer_handle);
	gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
    gdi_layer_set_position(0, 0);
    gdi_layer_set_blt_layer(play_wnd_layer_handle, 0, 0, 0);
	mdi_video_ply_seek(0);

	ret = mdi_video_ply_play(
                    play_wnd_layer_handle,
                    GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2,
                           /* blt layer */
                    GDI_LAYER_ENABLE_LAYER_0,               /* play_layer_flag */
                    1,                                      /* repeat */
                    TRUE,                                   /* visual update */
                    TRUE,                                   /* play audio */
                    MDI_DEVICE_SPEAKER2,
                    MDI_VIDEO_LCD_ROTATE_0,                 /* rotate */
                    100,                                    /* 1x play speed */
                    video_play_done_callback2,
					0);
					
	if (ret != MDI_RES_VDOPLY_SUCCEED)
	{
	    return 0;
  	}

    g_mms_is_video_open = g_mms_is_video_play = TRUE;

	return 1;
}

//Start play video from T-Card or other drive

IGMediaHandle IGVideo_PlayFromFile(void *path)
{
    kal_int16 namebuf[64];

	gdi_result gdi_ret = 1;
    //mdi_handle handle = 0;
    MDI_RESULT ret = 0;
    
	  //gdi_handle play_wnd_layer_handle;
	  S32 lcd_width;
	  S32 lcd_height;

    // if some video is playing now, skip this one
    if ((g_mms_is_video_open == TRUE) &&  (g_mms_is_video_play == TRUE))
        return 0;
        
 
	  g_mms_is_video_open = g_mms_is_video_play = FALSE;

    namebuf[0] = SRV_FMGR_CARD_DRV;
    namebuf[1] = 0;

    app_ucs2_strcat((kal_int8 *)namebuf, (kal_int8 *)L":\\intergrafx\\");
    app_ucs2_strcat((kal_int8 *)namebuf, (char *)path);

    memset(&video_info, 0, sizeof(video_info));
    ret = mdi_video_ply_open_clip_file(g_IGAppID, (char *)namebuf, &video_info);

    
    if(ret!= MDI_RES_VDOPLY_SUCCEED)
	  {
		    return 0;
	  }
	  
  

	  IGDisplay_GetWindowSize(&lcd_width, &lcd_height);
    ig_video_mem_pool = mmi_frm_asm_alloc_anonymous_nc(lcd_width * lcd_height * 2);

	  if (ig_video_mem_pool == NULL)
	  {
	      return 0;
	  }

    
	  gdi_ret = gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_16,
        0,
        0,
        lcd_width,
        lcd_height,
        &play_wnd_layer_handle,
        (U8 *)ig_video_mem_pool,
       lcd_width * lcd_height * 2);
        
    if (gdi_ret  != GDI_SUCCEED)
    {
        MMI_ASSERT(0);
    }

    gdi_layer_push_and_set_active(play_wnd_layer_handle);
	gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
    gdi_layer_set_position(0, 0);
    gdi_layer_set_blt_layer(play_wnd_layer_handle, 0, 0, 0);
	mdi_video_ply_seek(0);

    ret = mdi_video_ply_play(
                    play_wnd_layer_handle,
                    GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2,
                           /* blt layer */
                    GDI_LAYER_ENABLE_LAYER_0,               /* play_layer_flag */
                    1,                                      /* repeat */
                    TRUE,                                   /* visual update */
                    TRUE,                                   /* play audio */
                    MDI_DEVICE_SPEAKER2,
                    MDI_VIDEO_LCD_ROTATE_0,                 /* rotate */
                    100,                                    /* 1x play speed */
                    video_play_done_callback,
					0);
					
	if (ret != MDI_RES_VDOPLY_SUCCEED)
	{
	    return 0;
  	}

    g_mms_is_video_open = g_mms_is_video_play = TRUE;

	return 1;
}

//CY: Please note if some video is opened but not yet played, this function return FALSE, so don't use this function to check
//    if a video file is opened or not. 
int IGVideo_IsPlaying(void)
{
	if ((g_mms_is_video_open == TRUE) &&  (g_mms_is_video_play == TRUE))
		return 1;
	else 
		return 0;
}

/////////////////////////////////////////////////////////////

void IGVideo_Stop(void)
{
	g_VideoStop=1;
	
  
}

/////////////////////////////////////////////////////////////

int g_iExited = 0;

void IGSystem_Exit(void)
{
	g_iExited = 1;
	GoBackHistory();
}

/////////////////////////////////////////////////////////////

void I1(void)
{
        gdi_layer_clear(GDI_COLOR_RED);
	gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);	
}

void I2(void)
{
        gdi_layer_clear(GDI_COLOR_GREEN);
	gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);	
}

void I3(void)
{
       gdi_layer_clear(GDI_COLOR_BLUE);
	gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);	
}


#ifdef __cplusplus
}
#endif


#endif
