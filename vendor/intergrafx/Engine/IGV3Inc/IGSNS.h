/**
@file IGSNS.h 
@brief 

@par Last updated:2011/01/18


@par Copyright (c) 2011 InterGrafx, Inc. All rights reserved.
InterGrafx CONFIDENTIAL AND PROPRIETARY
@par
This source is the sole property of InterGrafx Inc. Reproduction or
Utilization of this source in whole or in part is forbidden without
The written consent of InterGrafx Inc.

@par History:


@par Description:
.
*/

#ifndef __IGSNS_H
#define __IGSNS_H

#include "IGMemoryPool.h"


#ifdef __cplusplus
extern "C"
{
#endif

typedef enum {

	ISC_LOGIN = 1,				// Login request
	ISC_UPLOAD_ACHIEVEMENT,		// Upload achievement (for example, game score is one of the achievement)
	ISC_UPDATE_LEADERBOARD,		// actively sync most recently friend status
	ISC_UPDATE_FRIENDLIST,		// actively sync friend list
	ISC_UPLOAD_HINT,			// upload hint code for in-game 
	ISC_WATCH_AD,
	ISC_UPLOAD_VOTE

} IGSNSCmdIdx;

/* server response events */
typedef struct {
	unsigned uTicketID;
	unsigned uUserID;
	unsigned uEventID;
	unsigned uData;
	void *pDataPtr; 
} IGSNS_Event;

/**
Initialization of IGSNS client API.
@param pErr
Stores error code raised by this function. If initializatin process successed, retunrn IGERR_NONE.
@return
void
*/
IGErr IGSNS_Startup(IGPlatformConfig *pPC);

/**
Shutdown and release any resources occupied by IGSNS client API.
@return
void
*/
void IGSNS_Shutdown(void);

// Server has some new updated information 
#define IGSNSEVT_UPDATE 0x00007001  

// Connection is broken
#define IGSNSEVT_LINEBREAK 0x00007002 

/**
of IGSNS client API.
@param uTimeInterval
time intreval between IGSNS_Update() call.
@param upNumEvents
Number of events coming from server
@param upServerEvents
Server events passed by IGSNS server
@return
void
*/

IGErr IGSNS_Update(unsigned uTimeInterval, unsigned *upNumEvents, IGSNS_Event *upServerEvents);

#ifdef __cplusplus
}
#endif



#endif