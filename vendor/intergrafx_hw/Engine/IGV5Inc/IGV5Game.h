/** 
 *
 *	@file		IGV5Game.h 
 *
 *  @brief		header file for main game routine, put your ES game or application code here
 *
 *	@author		Charles Shih-I Yeh
 *
*/


#ifndef __IGV5GAME_H
#define __IGV5GAME_H

#include "IGV5RuntimeContext.h"
#include "IGV5Font.h"
#include "IGV5Camera.h"

#if defined(IGV5_WIN)
#include "win32_runtime.h"
#elif defined(IGV5_ANDROID)
#include "android_runtime.h"
#elif defined(IGV5_LINUX)
#include "linux_runtime.h"
#elif defined (IGV5_MTK_PHONE)
#include "6256_runtime.h"
#else
#error Platform is not supported!
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*! @def	event category is input event */
#define IGV5ET_INPUT 0x00000002

/*! @def	key pressed */
#define IGV5EID_KEYDOWN 0x00000001

/*! @def	key released */
#define IGV5EID_KEYUP 0x00000002

/*! @def	finger touch on screen */
#define IGV5EID_BEGINTOUCH 0x00000010
#define IGV5EID_BEGINTOUCH1 IGV5EID_BEGINTOUCH
#define IGV5EID_BEGINTOUCH2 0x0000013
#define IGV5EID_BEGINTOUCH3 0x0000016
#define IGV5EID_BEGINTOUCH4 0x0000019
#define IGV5EID_BEGINTOUCH5 0x000001c

/*! @def	finger move on screen */
#define IGV5EID_TOUCH 0x00000011
#define IGV5EID_TOUCH1 IGV5EID_TOUCH
#define IGV5EID_TOUCH2 0x00000014
#define IGV5EID_TOUCH3 0x00000017
#define IGV5EID_TOUCH4 0x0000001a
#define IGV5EID_TOUCH5 0x0000001d

/*! @def	finger left off screen */
#define IGV5EID_ENDTOUCH 0x00000012
#define IGV5EID_ENDTOUCH1 IGV5EID_ENDTOUCH
#define IGV5EID_ENDTOUCH2 0x00000015
#define IGV5EID_ENDTOUCH3 0x00000018
#define IGV5EID_ENDTOUCH4 0x0000001b
#define IGV5EID_ENDTOUCH5 0x0000001e

#define IGV5EID_MULTITOUCH_BEGIN 0x00000020
#define IGV5EID_MULTITOUCH_MOVE 0x00000021
#define IGV5EID_MULTITOUCH_END 0x00000022

/*! @def	keypad '0' */
#define IGV5KEY_0 '0'
/*! @def	keypad '1' */
#define IGV5KEY_1 '1'
/*! @def	keypad '2' */
#define IGV5KEY_2 '2'
/*! @def	keypad '3' */
#define IGV5KEY_3 '3'
/*! @def	keypad '4' */
#define IGV5KEY_4 '4'
/*! @def	keypad '5' */
#define IGV5KEY_5 '5'
/*! @def	keypad '6' */
#define IGV5KEY_6 '6'
/*! @def	keypad '7' */
#define IGV5KEY_7 '7'
/*! @def	keypad '8' */
#define IGV5KEY_8 '8'
/*! @def	keypad '9' */
#define IGV5KEY_9 '9'
/*! @def	left soft key */
#define IGV5KEY_LSK 'L'
/*! @def	right soft key */
#define IGV5KEY_RSK 'R'
/*! @def	center soft key */
#define IGV5KEY_CSK 'C'
/*! @def	up key */
#define IGV5KEY_UP  100
/*! @def	down key */
#define IGV5KEY_DOWN  101
/*! @def	left key */
#define IGV5KEY_LEFT  102
/*! @def	right key */
#define IGV5KEY_RIGHT  103

/*! @def	event category is 6256 Live Wallpaper */
#define IGV5ET_LIVEWALLPAPER 0x00000007

/*! @def	Live Wallpaper of 6256's boundary changed */
#define IGV5EID_LWBOUNDSCHANGED  0x00004001

/*! @typedef	event data structure */
typedef struct {

	UINT16 m_uType;			/*!< event category */
	UINT16 m_uEvtID;		/*!< event ID */
	DWORD m_uEvtTime;		/*!< event time stamp in 32bit ticks */
	DWORD m_uData1;			/*!< first data field associated with event, can also be a 32 bit pointer to other object */
	DWORD m_uData2;			/*!< second data field associated with event, can also be a 32 bit pointer to other object */

} IGV5Event;

/*! @fn		IGV5Game_Startup
 @param		pOverride		pointer to initialization structure
 @retun		IGV5ERR_NONE if no error
 @brief		application programmers use this callback function to initialize their game

			This funciton is called by engine to do application initialization. However do not initialize any engine related objec here since the engine is not start up yet.
*/
IGV5Err IGV5Game_Startup(IGV5InitInfoVer0101 *pOverride);

/*! @fn		IGV5Game_LoadContent
 @param		pThisRC		pointer to rendering context of this application
 @retun		IGV5ERR_NONE if no error
 @brief		application programmers use this callback function to load resource of their game

			This funciton is called by engine to load engine-related objects like 3D model, animations, effects, etc. Everything initialized here need to be destroyed in IGV5Game_Unload().
*/
IGV5Err IGV5Game_LoadContent(IGV5RC *pThisRC);

/*! @fn		IGV5Game_Update
 @param		pThisRC		pointer to rendering context of this application
 @param		fFrameTime  interval (in second) 
 @param		uNumEvents	number of events passed from engine since last time IGV5Game_Update() called
 @param		pEvts		array of events
 @brief		application programmers use this callback function to update their game

			This funciton is called by engine to load engine-related objects like 3D model, animations, effects, etc. Everything initialized here need to be destroyed in IGV5Game_Unload().
*/
void IGV5Game_Update(IGV5RC *pThisRC, float fFrameTime, unsigned uNumEvents, IGV5Event *pEvts);

/*! @fn		IGV5Game_Unload
 @param		pThisRC		pointer to rendering context of this application
 @brief		application programmers use this callback function to release resource of their game

			This funciton is called by engine to release engine-related objects like 3D model, animations, effects, etc. Everything initialized in IGV5Game_LoadContent() need to be destroyed here.
*/
void IGV5Game_Unload(IGV5RC *pThisRC);

/*! @fn		IGV5Game_Shutdown
 @brief		application programmers use this callback function to release content initialized in IGV5Game_Startup()

			This funciton is called by engine to release application global objects. Everything initialized in IGV5Game_Startup() need to be destroyed here.
*/
void IGV5Game_Shutdown(void);

/*! @fn		IGV5Game_PostEvent
 @brief		application programmers use this function to signal itself so it can process the event later in next IGV5Game_Update()

			This funciton is use to post message to application itself and process that message in next IGV5Game_Update() call.
*/
void IGV5Game_PostEvent(unsigned short uType, unsigned short uEvtID, unsigned uEvtTime, unsigned uData1, unsigned uData2);

#ifdef __cplusplus
}
#endif

#endif