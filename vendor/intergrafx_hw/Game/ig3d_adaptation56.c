/*-------------------------------------------------

   ig3d_adaptation56.c

   2011-09-01  First release

-------------------------------------------------*/
#include "ig3d_adaptation56.h"
#include "IGV5Game.h"

#ifdef __MMI_3D_GAME_INTERGRAFX__

#ifdef __cplusplus
extern "C"
{
#endif

//**************************************** External or Global variables

extern unsigned g_uIGTotalMemUsed;
extern unsigned g_IGNumSceneTriangles;
extern unsigned g_IGNumTriRasterized;
extern unsigned g_IGNumScnenMeshes;

extern unsigned g_IGRender2DTime;
extern unsigned g_IGRender3DTime;
extern unsigned g_IGRasterizeTime;


U32 g_uFrameInterval = 0;
void *ig_engine_mem_buffer = NULL;
gdi_handle g_IGNativeWindow;
PU8 g_pIGFrameBuffer = NULL;

MMI_ID g_IGAppID = 0;

U32 g_uIsOnPhoneCall = 0;

//**************************************** Static

static void *ig_video_mem_pool = NULL;

//////////////////////////////////////////// EVENT

IGV5Event sEventList[128];
unsigned uNumEvents = 0;

void IGV5Game_PostEvent(unsigned short uType, unsigned short uEvtID, unsigned uEvtTime, unsigned uData1, unsigned uData2)
{
	sEventList[uNumEvents].m_uType = uType;
	sEventList[uNumEvents].m_uEvtID = uEvtID;
	sEventList[uNumEvents].m_uEvtTime = uEvtTime;
	sEventList[uNumEvents].m_uData1 = uData1;
	sEventList[uNumEvents].m_uData2 = uData2;

	++uNumEvents;
}


static UI_character_type FrameText[10];
static kal_uint32  g_StartTime;

int g_ig_is_video_open = FALSE;
int g_ig_is_video_play = FALSE;

// pen handlers
static void ig_mmi_pen_move_hdlr (mmi_pen_point_struct pos, int i)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_TOUCH + i*3, IGV5Time_Get(),pos.x, pos.y);
}

static void ig_mmi_pen_down_hdlr (mmi_pen_point_struct pos, int i)
{
        // check if we are inside video playback, them we just stop video playback and resume execution
        if (g_ig_is_video_play == TRUE) {
              IGVideo_Stop();	      
            //start game
    	      //ig_start_timer(1, ig_timer_callback); 
              return;
        }

	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_BEGINTOUCH + i*3, IGV5Time_Get(), pos.x, pos.y);
		
}

static void ig_mmi_pen_up_hdlr (mmi_pen_point_struct pos, int i)
{ 
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_ENDTOUCH + i*3, IGV5Time_Get(),pos.x, pos.y);
}

//key handler
//#ifndef IG_NO_KEY_HANDLER

char g_iSoundVol = 4;  // default sound volume is 4
char g_iMuteState = 0;   // default not in mute state
char g_MTKVolKeyMuteState = 0;   // default not in mute state

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
	if(!g_iMuteState)
	{
	    if (g_iSoundVol < 7) 
	    {
		    ++g_iSoundVol;
	    }
        IGSound_SetVol(g_iSoundVol);
    }
}

static void ig_key_vol_down_pressed_handler(void)
{
	if(!g_iMuteState)
	{
	    if (g_iSoundVol)
		{
		    --g_iSoundVol;
		}
        IGSound_SetVol(g_iSoundVol);
	}
}


static void ig_key_left_down_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYDOWN, IGV5Time_Get(), IGV5KEY_LEFT, 0);
}

static void ig_key_right_down_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYDOWN, IGV5Time_Get(), IGV5KEY_RIGHT, 0);
}

static void ig_key_lsk_down_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYDOWN, IGV5Time_Get(), IGV5KEY_LSK, 0);
}

static void ig_key_rsk_down_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYDOWN, IGV5Time_Get(), IGV5KEY_RSK, 0);
}

static void ig_key_back_down_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYDOWN, IGV5Time_Get(), IGV5KEY_RSK, 0);
}
void I1(void);

static void ig_key_csk_down_handler(void)
{
	// check if we are inside video playback, them we just stop video playback and resume execution
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYDOWN, IGV5Time_Get(), IGV5KEY_CSK, 0);
}


static void ig_key_up_down_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYDOWN, IGV5Time_Get(), IGV5KEY_UP, 0);
}

static void ig_key_down_down_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYDOWN, IGV5Time_Get(), IGV5KEY_DOWN, 0);
}

static void ig_key_left_up_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYUP, IGV5Time_Get(), IGV5KEY_LEFT, 0);
}

static void ig_key_right_up_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYUP, IGV5Time_Get(), IGV5KEY_RIGHT, 0);
}

static void ig_key_up_up_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYUP, IGV5Time_Get(), IGV5KEY_UP, 0);
}

static void ig_key_down_up_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYUP, IGV5Time_Get(), IGV5KEY_DOWN, 0);
}

static void ig_key_lsk_up_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYUP, IGV5Time_Get(), IGV5KEY_LSK, 0);
}

static void ig_key_rsk_up_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYUP, IGV5Time_Get(), IGV5KEY_RSK, 0);
}

//wallace add
static void ig_key_back_up_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYUP, IGV5Time_Get(), IGV5KEY_RSK, 0);
}

static void ig_key_csk_up_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYUP, IGV5Time_Get(), IGV5KEY_CSK, 0);
}

static void ig_key_0_up_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYUP, IGV5Time_Get(), IGV5KEY_0, 0);
}

static void ig_key_0_down_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYDOWN, IGV5Time_Get(), IGV5KEY_0, 0);
}

static void ig_key_1_up_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYUP, IGV5Time_Get(), IGV5KEY_1, 0);
}

static void ig_key_1_down_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYDOWN, IGV5Time_Get(), IGV5KEY_1, 0);
}

static void ig_key_2_up_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYUP, IGV5Time_Get(), IGV5KEY_2, 0);
}

static void ig_key_2_down_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYDOWN, IGV5Time_Get(), IGV5KEY_2, 0);
}

static void ig_key_3_up_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYUP, IGV5Time_Get(), IGV5KEY_3, 0);
}

static void ig_key_3_down_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYDOWN, IGV5Time_Get(), IGV5KEY_3, 0);	
}

static void ig_key_4_up_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYUP, IGV5Time_Get(), IGV5KEY_4, 0);
}

static void ig_key_4_down_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYDOWN, IGV5Time_Get(), IGV5KEY_4, 0);	
}

static void ig_key_5_up_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYUP, IGV5Time_Get(), IGV5KEY_5, 0);
}

static void ig_key_5_down_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYDOWN, IGV5Time_Get(), IGV5KEY_5, 0);
}

static void ig_key_6_up_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYUP, IGV5Time_Get(), IGV5KEY_6, 0);
}

static void ig_key_6_down_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYDOWN, IGV5Time_Get(), IGV5KEY_6, 0);
}

static void ig_key_7_up_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYUP, IGV5Time_Get(), IGV5KEY_7, 0);
}

static void ig_key_7_down_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYDOWN, IGV5Time_Get(), IGV5KEY_7, 0);
}

static void ig_key_8_up_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYUP, IGV5Time_Get(), IGV5KEY_8, 0);
}

static void ig_key_8_down_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYDOWN, IGV5Time_Get(), IGV5KEY_8, 0);
}

static void ig_key_9_up_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYUP, IGV5Time_Get(), IGV5KEY_9, 0);
}

static void ig_key_9_down_handler(void)
{
	IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_KEYDOWN, IGV5Time_Get(), IGV5KEY_9, 0);
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
	{
		mdi_audio_set_mute(MDI_VOLUME_MEDIA, MMI_TRUE);
	}
	else
	{
		if(!g_MTKVolKeyMuteState)
		{
			mdi_audio_set_mute(MDI_VOLUME_MEDIA, MMI_FALSE);
		}
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
	if (vol<1) vol = 0;

	if (vol==0)
	{
        mdi_audio_set_mute(MDI_VOLUME_MEDIA, MMI_TRUE);
	    g_MTKVolKeyMuteState = 1;
	}
    else
	{
	    if (!g_iMuteState)
		{
      	    mdi_audio_set_mute(MDI_VOLUME_MEDIA, MMI_FALSE);
       	    mdi_audio_set_volume(MDI_VOLUME_MEDIA, vol);
			g_MTKVolKeyMuteState = 0;
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
    //mdi_result res;

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

int g_IG_TouchNum = 0;

static mmi_ret mmi_app_touch_proc(mmi_event_struct *evt)
{
		unsigned i, j;
    mmi_multi_touch_event_struct *touch_evt = (mmi_multi_touch_event_struct *)evt;
    if (touch_evt->evt_id == EVT_ID_ON_TOUCH)
    {
    	  g_IG_TouchNum = touch_evt->touch_num;
    	  for(i=0;i<touch_evt->touch_num ;i++) { // for single touch
			switch(touch_evt->touch_data[i].event) 
			{
				case MMI_PEN_EVENT_DOWN:
					IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_MULTITOUCH_BEGIN, IGV5Time_Get(), touch_evt->touch_data[i].id, touch_evt->touch_data[i].currpos.pos.x | (touch_evt->touch_data[i].currpos.pos.y << 16));
					if (touch_evt->touch_data[i].id == 0)
						ig_mmi_pen_down_hdlr(touch_evt->touch_data[i].currpos.pos, touch_evt->touch_data[i].id);
					for(j=0;j<touch_evt->touch_data[i].merge_num;j++)
						IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_MULTITOUCH_MOVE, IGV5Time_Get(), touch_evt->touch_data[i].id, touch_evt->touch_data[i].merge_points[j].pos.x | (touch_evt->touch_data[i].merge_points[j].pos.y << 16));
					return MMI_RET_OK;
				case MMI_PEN_EVENT_UP:
					for(j=0;j<touch_evt->touch_data[i].merge_num;j++)
						IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_MULTITOUCH_MOVE, IGV5Time_Get(), touch_evt->touch_data[i].id, touch_evt->touch_data[i].merge_points[j].pos.x | (touch_evt->touch_data[i].merge_points[j].pos.y << 16));
					IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_MULTITOUCH_END, IGV5Time_Get(), touch_evt->touch_data[i].id, touch_evt->touch_data[i].currpos.pos.x | (touch_evt->touch_data[i].currpos.pos.y << 16));
					if (touch_evt->touch_data[i].id == 0)
						ig_mmi_pen_up_hdlr(touch_evt->touch_data[i].currpos.pos, touch_evt->touch_data[i].id);
					return MMI_RET_OK;
				case MMI_PEN_EVENT_MOVE:
					IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_MULTITOUCH_MOVE, IGV5Time_Get(), touch_evt->touch_data[i].id, touch_evt->touch_data[i].currpos.pos.x | (touch_evt->touch_data[i].currpos.pos.y << 16));
					if (touch_evt->touch_data[i].id == 0)
						ig_mmi_pen_move_hdlr(touch_evt->touch_data[i].currpos.pos, touch_evt->touch_data[i].id);
					for(j=0;j<touch_evt->touch_data[i].merge_num;j++)
						IGV5Game_PostEvent(IGV5ET_INPUT, IGV5EID_MULTITOUCH_MOVE, IGV5Time_Get(), touch_evt->touch_data[i].id, touch_evt->touch_data[i].merge_points[j].pos.x | (touch_evt->touch_data[i].merge_points[j].pos.y << 16));
					return MMI_RET_OK;	          			 	    		
			}
		}

    }
    return MMI_RET_OK;
}


/////////////////////////////////////////////////////////////

void IGSystem_RegisterTouchHandlers(void)
{
	  // register touch handler
	  mmi_frm_touch_set_mode(MMI_FRM_MULTI_TOUCH);
	  mmi_frm_touch_register_proc(mmi_app_touch_proc, 0);
	  
	  // register pen handler
    //ig_register_pen_move(ig_mmi_pen_move_hdlr);
    //ig_register_pen_down(ig_mmi_pen_down_hdlr);
   // ig_register_pen_up(ig_mmi_pen_up_hdlr);

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
	//wallace add
	mmi_frm_set_key_handler(ig_key_back_down_handler, KEY_BACK, KEY_EVENT_DOWN);
    
    mmi_frm_set_key_handler(ig_key_left_up_handler, KEY_LEFT_ARROW, KEY_EVENT_UP);
    mmi_frm_set_key_handler(ig_key_right_up_handler, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    mmi_frm_set_key_handler(ig_key_up_up_handler, KEY_UP_ARROW, KEY_EVENT_UP);
    mmi_frm_set_key_handler(ig_key_down_up_handler, KEY_DOWN_ARROW, KEY_EVENT_UP);
    mmi_frm_set_key_handler(ig_key_lsk_up_handler, KEY_LSK, KEY_EVENT_UP);
    mmi_frm_set_key_handler(ig_key_rsk_up_handler, KEY_RSK, KEY_EVENT_UP);
    mmi_frm_set_key_handler(ig_key_csk_up_handler, KEY_CSK, KEY_EVENT_UP);
	//wallace add
	mmi_frm_set_key_handler(ig_key_back_up_handler, KEY_BACK, KEY_EVENT_UP);
    
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
	//ig_register_pen_move(NULL);
  //  ig_register_pen_down(NULL);
  //  ig_register_pen_up(NULL);
  
	mmi_frm_touch_register_proc(NULL, 0);
	mmi_frm_touch_set_mode(MMI_FRM_SINGLE_TOUCH);
	mmi_frm_clear_key_events();
	ClearAllKeyHandler();
}

//////////////////////////////////////////////////////////////////////////

int g_VideoStop = 0;

void igvideo_play_done_callback(MDI_RESULT result, void *user_data);

void IGSystem_StopVideo(void)
{
	if (g_ig_is_video_play == TRUE) 
		igvideo_play_done_callback(MDI_RES_VDOPLY_SUCCEED, 0);
	g_VideoStop=0;	
}

void ig_timer_callback(void)
{
}

void IGSystem_ForceUpdate(void)
{

}


void igvideo_play_done_callback(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_video_ply_stop();
		mdi_video_ply_close_clip_file();
 
	  mdi_audio_resume_background_play();
    if (gdi_layer_is_multi_layer_enable() == MMI_TRUE)
    {
        gdi_layer_multi_layer_disable();
    }
    gdi_layer_set_blt_layer( 0 /*base_layer_handle*/, 0, 0, 0);
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    mmi_frm_asm_free_anonymous(ig_video_mem_pool);
    ig_video_mem_pool = NULL;
    
    g_ig_is_video_play = FALSE;
    g_ig_is_video_open = FALSE;    

    //start game
    //ig_start_timer(250, ig_timer_callback); 
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
 
	  mdi_audio_resume_background_play();
    if (gdi_layer_is_multi_layer_enable() == MMI_TRUE)
    {
        gdi_layer_multi_layer_disable();
    }
    gdi_layer_set_blt_layer( 0 /*base_layer_handle*/, 0, 0, 0);
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    mmi_frm_asm_free_anonymous(ig_video_mem_pool);
    ig_video_mem_pool = NULL;
    
    g_ig_is_video_play = FALSE;
    g_ig_is_video_open = FALSE;    

    //start game
    //ig_start_timer(250, ig_timer_callback); 
}


extern void IG1(void);
extern void IG2(void);

static mdi_video_info_struct video_info;

IGMediaHandle IGVideo_Play(void *ptr, unsigned vsize)
{
	gdi_result gdi_ret = 1;
    //mdi_handle handle = 0;
    MDI_RESULT ret = 0;
    
	  gdi_handle play_wnd_layer_handle;
	  S32 lcd_width;
	  S32 lcd_height;
	  
	  g_ig_is_video_open = g_ig_is_video_play = FALSE;

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
    g_ig_is_video_open = g_ig_is_video_play = TRUE;

	return 1;
}

IGMediaHandle IGVideo_PlayFromFile(void *path)
{
    kal_int16 namebuf[64];

	gdi_result gdi_ret = 1;
    //mdi_handle handle = 0;
    MDI_RESULT ret = 0;
    
	  gdi_handle play_wnd_layer_handle;
	  S32 lcd_width;
	  S32 lcd_height;

    // if some video is playing now, skip this one
    if ((g_ig_is_video_open == TRUE) &&  (g_ig_is_video_play == TRUE))
        return 0;
        
 
	  g_ig_is_video_open = g_ig_is_video_play = FALSE;

    namebuf[0] = SRV_FMGR_PUBLIC_DRV;
    namebuf[1] = 0;
    app_ucs2_strcat((kal_int8 *)namebuf, (kal_int8 *)L":\\Videos\\");
    app_ucs2_strcat((kal_int8 *)namebuf, (kal_int8 *)path);

    memset(&video_info, 0, sizeof(video_info));
    ret = mdi_video_ply_open_clip_file(g_IGAppID, (char *)namebuf, &video_info);

    
    if(ret!= MDI_RES_VDOPLY_SUCCEED)
	  {
	  	  MMI_ASSERT(0);
		    return 0;
	  }
	  
  

	  IGDisplay_GetWindowSize(&lcd_width, &lcd_height);
    ig_video_mem_pool = mmi_frm_asm_alloc_anonymous_nc(lcd_width * lcd_height * 2);

	  if (ig_video_mem_pool == NULL)
	  {
	  	  	  	  MMI_ASSERT(0);

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
                    GDI_LAYER_ENABLE_LAYER_0 ,               /* play_layer_flag */
                    1,                                      /* repeat */
                    TRUE,                                   /* visual update */
                    TRUE,                                   /* play audio */
                    MDI_DEVICE_SPEAKER2,
                    MDI_VIDEO_LCD_ROTATE_0,                 /* rotate */
                    100,                                    /* 1x play speed */
                    igvideo_play_done_callback,
					0);
					
	if (ret != MDI_RES_VDOPLY_SUCCEED)
	{
        MMI_ASSERT(0);
        return 0;
  	}

    g_ig_is_video_open = g_ig_is_video_play = TRUE;

	return 1;
}

int IGVideo_IsPlaying(void)
{
	if ((g_ig_is_video_open == TRUE) &&  (g_ig_is_video_play == TRUE))
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
	//GoBackHistory();  //CY: if we go back history here, memory pool and EGL might be shutdown while app is running
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