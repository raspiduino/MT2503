///////////////////////////////////////////////////////////////
//
//  INTERGARFX ADAPTATION CODE 
//
//    2011-04-12 First version. (Charles Shih-I Yeh)
//    
//    The origin of this code is adapted from MediaTek's IG adaptation code due back to 2006.
//    Since then a lot modification and improvement for new 3D game requirement.
//
//-------------------------------------------------------------
#ifndef __IG3D_ADAPTATION56__H
#define __IG3D_ADAPTATION56__H
#include "mmi_features.h"

#ifdef __MMI_3D_GAME_INTERGRAFX__

#include "IGV5Def.h"
#include "IGV5Game.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "mmi_include.h"
#include "Fat_fs.h"     /* File System, must after "GlobalConstants.h" */
#include "lcd_sw_rnd.h" /* lcd */
#include "lcd_if.h"     /* lcd */
#include "mdi_datatype.h"       /* mdi datatype */
#include "mdi_audio.h"  /* audio lib */
#include "gui_video.h"
#include "kal_release.h"        /* kal */
#include "mmi_frm_gprot.h"
#include "MMIDataType.h"
#include "mmi_frm_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "gpioInc.h"	/* for TurnOnBacklight() */
#include "mdi_video.h"
#include "wgui_categories_popup.h"
#include "gpiosrvgprot.h"
#include "app_str.h"
#include "FileMgrSrvGProt.h"
#include "UcmSrvGprot.h"


//**************************************** Local define
	
#if defined(__MMI_MAINLCD_480X800__)
    #define IG_3D_GAME_POOL_SIZE   (3*1024*1024)  //8MB,  too large will alloc fail
#else
    #define IG_3D_GAME_POOL_SIZE   (3*1024*1024)
#endif

//#define IG_NO_KEY_HANDLER

////////////////////////////////// Platform independent definitions

typedef U32 IGU32;
typedef U8 IGU8;
typedef int IGI32;
typedef mdi_handle IGMediaHandle;
/* file APIs */
typedef FS_HANDLE IG_FS_HANDLE;
typedef WCHAR IGCHAR;

#define MASK_555_RED     0x7C00
#define MASK_555_GREEN   0x03E0
#define MASK_555_BLUE    0x001F

#define MASK_565_RED     0xF800
#define MASK_565_GREEN   0x07E0
#define MASK_565_BLUE    0x001F

// This event indicate use's finger touch screen. Win32 version simulate this as mouse left button done.
// On a multi-touch screen, it means the first touch on screen
// m_uData1 -> x coordinate
// m_uData2 -> y coordinate
#define IGFK_TOUCH1_DOWN 0x00010001

// This event indicate use's finger lift from screen. Win32 version simulate this as mouse left button up.
// On a multi-touch screen, it means the first touch release on screen
// m_uData1 -> x coordinate
// m_uData2 -> y coordinate
#define IGFK_TOUCH1_UP 0x00010002

// This event indicate use's finger lift from screen. Win32 version simulate this as mouse left button up.
// On a multi-touch screen, it means the first touch release on screen
// m_uData1 -> x coordinate
// m_uData2 -> y coordinate
#define IGFK_TOUCH1_MOVE 0x00010003

// This event indicate user press keypad button
// m_uData1 -> key code
#define IGFK_KEY_DOWN 0x00010004

// This event indicate user release keypad button
// m_uData1 -> key code
#define IGFK_KEY_UP 0x00010005

// The following are key definitions 

/* mmi key code */
typedef enum
{
/*
 * The key code sequency cannot be changed.
 */
    IGFK_0 = 0,
    IGFK_1,
    IGFK_2,
    IGFK_3,
    IGFK_4,
    IGFK_5,
    IGFK_6,
    IGFK_7,
    IGFK_8,
    IGFK_9,
    IGFK_LSK,
    IGFK_RSK,
    IGFK_CSK,   
    IGFK_UP_ARROW,
    IGFK_DOWN_ARROW,
    IGFK_LEFT_ARROW,
    IGFK_RIGHT_ARROW,
    IGFK_SEND,
    IGFK_END,
    IGFK_CLEAR,
    IGFK_STAR,
    IGFK_POUND,
    IGFK_VOL_UP,
    IGFK_VOL_DOWN,
    IGFK_CAMERA,
    IGFK_QUICK_ACS = IGFK_CAMERA,  
    IGFK_ENTER,
    IGFK_WAP = IGFK_ENTER,
    IGFK_IP = IGFK_ENTER,   
    IGFK_EXTRA_1,
    IGFK_EXTRA_2,
    IGFK_PLAY_STOP,
    IGFK_FWD,
    IGFK_BACK,
    IGFK_POWER,
    IGFK_EXTRA_A,
    IGFK_EXTRA_B,
    IGFK_INVALID = 0xFE
} IGFK_KeyCodeEnum;

#define MASK_565_RED     0xF800
#define MASK_565_GREEN   0x07E0
#define MASK_565_BLUE    0x001F

typedef struct {

	IGU32 m_uEventID;
	IGU32 m_uTime;
	IGU32 m_uData1;
	IGU32 m_uData2;

} IGSysEvent;

typedef struct {

	IGU32 m_uScrWidth;			// screen width
	IGU32 m_uScrHeight;			// screen height
	IGU8 *m_pFrameBuffer;		// frame buffer pointer
	void *m_pMemoryBuf;			// memory buffer
	IGU32 m_uMemSize;			// buffer size
	IGI32 m_bTopdown;			// is screen raster order top down? 1 for yes, 0 for buttom up like Windows BMP

} IGPlatformConfig;

void ig_register_pen_move(mmi_pen_hdlr kk);
void ig_register_pen_down(mmi_pen_hdlr kk);
void ig_register_pen_up(mmi_pen_hdlr kk);

void ig_start_timer(S32 count, void (*callback) (void));
void ig_cancel_timer(void (*callback) (void));


void ig_itoa(S32 value, WCHAR *string, S32 radix);

extern gdi_handle ig_native_window;
extern unsigned char *ig_engine_mem_pool;
extern PU8 ig_framebuf_ptr;
extern U32 g_uFrameInterval ;

//-------------------------------------------------------------
// PUBLIC AVAILABLE FUNCTION
//-------------------------------------------------------------
unsigned IGTimerGetTime(void);

//**************************************** External or Global variables

extern unsigned g_uIGTotalMemUsed;
extern unsigned g_IGNumSceneTriangles;
extern unsigned g_IGNumTriRasterized;
extern unsigned g_IGNumScnenMeshes;

extern unsigned g_IGRender2DTime;
extern unsigned g_IGRender3DTime;
extern unsigned g_IGRasterizeTime;
extern unsigned g_IGRenderUITime;

extern gdi_handle g_IGNativeWindow;
extern PU8 g_pIGFrameBuffer;

extern MMI_ID g_IGAppID;

extern U32 g_uFrameInterval;

extern void *ig_engine_mem_buffer;

extern U32 g_uIsOnPhoneCall;

extern int g_iExited;

extern char g_iSoundVol;

extern void IG1(void);
extern void ig_timer_callback(void);

//**************************************** Adaptation functions

void ig_start_timer(S32 count, void (*callback) (void));
void ig_cancel_timer(void (*callback) (void));
void ig_set_current_time(void);
void ig_itoa(S32 value, WCHAR *string, S32 radix);
void IGText_DrawText(IGCHAR *string, S32 x, S32 y, stFontAttribute *FontSize, U8 r, U8 g, U8 b);
void ig_draw_text(const WCHAR *string, S32 x, S32 y, stFontAttribute *FontSize, U8 r, U8 g, U8 b);
void IGDrawNum(S32 x, S32 y, S32 value);
void IGText_DrawBorderText(IGCHAR *string,S32 x,S32 y,  stFontAttribute *FontSize, U8 r,U8 g,U8 b,U8 rb,U8 gb,U8 bb);


void IGDisplay_GetWindowSize(S32 *puw, S32 *puh);

void IGSystem_RegisterTouchHandlers(void);
void IGSystem_UnRegisterTouchHandlers(void);
void IGSystem_ForceUpdate(void);
void IGSystem_StopVideo(void);

// Sound
void IGSound_SetVol(unsigned char vol);
void IGSound_SetMute(unsigned char ismute);

IGMediaHandle IGSound_OpenWav(void *audio_data, unsigned len, unsigned char repeats);
IGMediaHandle IGSound_OpenMIDI(void *audio_data, unsigned len, unsigned char repeats);


void IGSound_PlayMIDI(IGMediaHandle hsound);
void IGSound_PlayWav(IGMediaHandle hsound);

void IGSound_CloseWav(IGMediaHandle hsound);
void IGSound_CloseMIDI(IGMediaHandle hsound);

void IGSound_StopWav(IGMediaHandle hsound);
void IGSound_StopMIDI(IGMediaHandle hsound);


// Video

IGMediaHandle IGVideo_Play(void *video_data, unsigned len);
IGMediaHandle IGVideo_PlayFromFile(void *);
void IGVideo_Stop(void);
int IGVideo_IsPlaying(void);


// Platform-independent file access
// File
IG_FS_HANDLE IGFS_Open(IGCHAR *FileName, IGU32 Flags);
int IGFS_Close(IG_FS_HANDLE File);
int IGFS_Read(IG_FS_HANDLE File, void *DataPtr, IGU32 Length, IGU32 *Read);
int IGFS_Write(IG_FS_HANDLE File, void *DataPtr, IGU32 Length, IGU32 *Written);
int IGFS_Seek(IG_FS_HANDLE File, int Offset, int Whence);
int IGFS_GetFilePosition(IG_FS_HANDLE File, IGU32 *Position);

// Date & time
void IGDateTime_Get(unsigned *pDay, unsigned *pHour, unsigned *pMin, unsigned *pSec);

// Text
void IGText_DrawText(IGCHAR *string, S32 x, S32 y, stFontAttribute *FontSize, IGU8 r, IGU8 g, IGU8 b);
void IGText_DrawBorderText(IGCHAR *string, S32 x, S32 y, stFontAttribute *FontSize, IGU8 r, IGU8 g, IGU8 b, IGU8 rb, IGU8 gb, IGU8 bb);

// Random number
unsigned IGMath_Random(void);

// Vibration
void IGVibratorOn(int count);
void IGVibratorOff(void);

// System
void IGSystem_Exit(void);

#ifdef __cplusplus
}
#endif
#endif
#endif
