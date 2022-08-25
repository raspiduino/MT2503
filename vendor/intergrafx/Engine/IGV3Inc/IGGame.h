#ifndef __IGGAME_H
#define __IGGAME_H

#include "IGExtDef.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
* Called when platform startup the application
* * @param pPC
*   Pointer to the IGPlatformConfig provided by IGGame Framework
* @return
*   0 means application successfully initialize the application, otherwize returns application dependent error code
* @see IGGame_OnShutdown
*/
extern int IGGame_OnStartup(IGPlatformConfig *pPC);

/**
* Called when platform wants application to render & update itself
* * @param uFrameInterval
*   Time interval (integer, millisecond) between previous frame and this frame. 
* * @param uNumSysEvents
*   Number of system fired events captured by IGGame Framework since previous frame.
* * @param pSE
*   Pointer to the IGSysEvent structure provided by IGGame Framework
* @return
*   0 means application successfully update and render irslef, otherwize returns application dependent error code, 
*   IGGame Framework will then call IGGame_OnShutdown to terminate the application
* @see IGGame_OnShutdown
*/
extern int IGGame_OnUpdate(IGU32 uFrameInterval, unsigned uNumSysEvents, IGSysEvent *pSE);
 

/**
* Called when platform wants application to ternimate
* @see IGGame_OnShutdown
*/
extern void IGGame_OnShutdown(void);

#ifdef __cplusplus
}
#endif

#endif