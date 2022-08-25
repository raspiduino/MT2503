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

#include "mmi_features.h"

#ifdef __MMI_3D_GAME_INTERGRAFX__

#include "IGExtDef.h"
#include "IGGame.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include "MMIDataType.h"
#include "mmi_frm_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "GlobalResDef.h"
#include "GpioSrvGprot.h"	/* for srv_backlight_turn_on() */
#include "mdi_video.h"
#include "wgui_categories_popup.h"
#include "gpiosrvgprot.h"
#include "app_str.h"
#include "FileMgrSrvGProt.h"
#include "UcmSrvGprot.h"

//**************************************** Local define
	
#if defined(__MMI_MAINLCD_480X800__)
    #define IG_3D_GAME_POOL_SIZE   (8*1024*1024)
#else
    #define IG_3D_GAME_POOL_SIZE   (6*1024*1024)
#endif

//#define IG_NO_KEY_HANDLER

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

extern void IG1();
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
//void IGTrace(char *fmt, ...);

void IGDisplay_GetWindowSize(S32 *puw, S32 *puh);

void IGSystem_RegisterTouchHandlers(void);
void IGSystem_UnRegisterTouchHandlers(void);
void IGSystem_ForceUpdate(void);
void IGSystem_StopVideo(void);

unsigned IGMath_Random(void);

#ifdef __cplusplus
}
#endif



#endif