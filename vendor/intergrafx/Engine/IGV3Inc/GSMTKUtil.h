#ifndef __IGMTKUTIL_H
#define __IGMTKUTIL_H

#include "MMI_features.h"

#include "mmi_include.h"
#include "Fat_fs.h"     /* File System, must after "GlobalConstants.h" */
//#include "SettingDefs.h"        /* popup sound */
//#include "CommonScreens.h"      /* Popup */
#include "lcd_sw_rnd.h" /* lcd */
#include "lcd_if.h"     /* lcd */

#include "mdi_datatype.h"       /* mdi datatype */
#include "mdi_audio.h"  /* audio lib */
#include "gui_video.h"
#include "kal_release.h"        /* kal */

//#include "DevApp.h"
//#include "DevAppDef.h"
//#include "DevAppGProt.h"
//#include "GeneralDeviceGprot.h"
#include "mmi_frm_gprot.h"

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

#endif