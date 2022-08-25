#ifndef __IGEXTDEF_H
#define __IGEXTDEF_H

#ifdef __cplusplus
extern "C"
{
#endif

////////////////////////////////// Platform Build Options

//#define IGP_WIN32
//#define IGP_MODIS
#define IGP_TARGET

#if defined(IGP_MODIS) || defined(IGP_TARGET)
// This is for MediaTek platform build. It's either MoDIS simulator or target device
#define IGP_MTK

#include "MMI_Features.h"

#endif

////////////////////////////////// IG Engine Custom Build Options

#define IG_COMPRESSING
#define IG_USEMEMPOOL
#define IG_RTOS
#define IG_NO_FUNCTION_PTR
#define IG_SAFE_MODE
#define IG_PNG

////////////////////////////////// IG Build Configuration

// IG_TARGET remove all debug information and error checking code. It's for final build only
#define IG_TARGET
// IG_RELEASE only produce minimum error information (error code)
#define IG_RELEASE
// IG_DEBUG produce most informative debug message
//#define IG_DEBUG

////////////////////////////////// Platform independent definitions

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

//////////////////////////////////////// MTK related stuff

#if defined(IGP_MODIS) || defined(IGP_TARGET)
// This is for MediaTek platform build. It's either MoDIS simulator or target device
#define IGP_MTK
#include "GSMTKUtil.h"
#endif

#if defined(IGP_WIN32)

#include <windows.h>
#include <tchar.h>
#include <stdlib.h>

typedef unsigned IGU32;
typedef BYTE IGU8;
typedef int IGI32;
typedef int S32;
typedef void *IGMediaHandle;
typedef FILE *IG_FS_HANDLE;
typedef char IGCHAR;

typedef struct {
	TCHAR ftName[32];
} stFontAttribute;

#elif defined(IGP_MTK)

typedef U32 IGU32;
typedef U8 IGU8;
typedef int IGI32;
typedef mdi_handle IGMediaHandle;
/* file APIs */
typedef FS_HANDLE IG_FS_HANDLE;
typedef WCHAR IGCHAR;

#else

typedef unsigned IGU32;
typedef unsigned char IGU8;
typedef int IGI32;

#endif

typedef struct {

	IGU32 m_uScrWidth;			// screen width
	IGU32 m_uScrHeight;			// screen height
	IGU8 *m_pFrameBuffer;		// frame buffer pointer
	void *m_pMemoryBuf;			// memory buffer
	IGU32 m_uMemSize;			// buffer size
	IGI32 m_bTopdown;			// is screen raster order top down? 1 for yes, 0 for buttom up like Windows BMP

} IGPlatformConfig;

typedef struct {

	IGU32 m_uEventID;
	IGU32 m_uTime;
	IGU32 m_uData1;
	IGU32 m_uData2;

} IGSysEvent;

// Debug trace (printf in debug console)
#if defined(IGP_WIN32)
void IGTrace(IGCHAR *fmt, ... );
#elif  defined(IGP_MTK)
void IGTrace(char *fmt, ... );
#endif

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