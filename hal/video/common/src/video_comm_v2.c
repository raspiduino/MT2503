/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************

 *
 * Filename:
 * ---------
 *    video_comm_v2.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This Module defines video common part API for video driver
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_comm.h"
#include "drv_features_video.h"
#ifdef __VE_VIDEO_ARCHI_V2__
#include "med_status.h"

/* The following files are newly added for RHR. */
// #include "kal_non_specific_general_types.h"
// #include "kal_release.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "video_comm_v2.h"
#include "vcodec_v2_trc.h"

#ifdef __VE_DCM_WITH_COMPRESSION__
#include "dcmgr.h"
#endif

/*********************************************************
*
* Timing information functions
*
*********************************************************/

/* Get current time function. (32K resolution)
 * @param None
 * @return None
 */
kal_uint32 video_get_current_time(void)
{
    return drv_get_current_time();
}


/* Get duration time. (32K resolution)
 * @param previous_time. The previous time get from 32K ticks
 * @param current_time. The current time get from 32K ticks
 * @return time difference. (calculate limit)
 */
kal_uint32 video_get_duration_tick(kal_uint32 previous_time, kal_uint32 current_time)
{
    return drv_get_duration_tick(previous_time, current_time);
}


/* Get duration time. (ms)
 * @param previous_time. The previous time get from 32K ticks
 * @return time difference from previous to current time. (calculate limit, and translate to ms)
 */
kal_uint32 video_get_duration_ms(kal_uint32 previous_time)
{
    return drv_get_duration_ms(previous_time);
}

/*********************************************************
*
* Error status information functions
*
*********************************************************/

MED_STATUS VIDEO_GetLastError(void)
{
    // to do: check error type
    ASSERT(0);
    return MED_STAT_NO_ERROR;
}


typedef struct
{

    kal_mutexid arMutex[_VIDEO_MUTEX_NUMBER];
    VIDEO_MUTEX_USER_T  arUser[_VIDEO_MUTEX_NUMBER];
    kal_bool    afgOccupied[_VIDEO_MUTEX_NUMBER];
} VIDEO_MUTEX_CTRL_T;

typedef struct
{
    kal_timerid arTimer[_VIDEO_TIMER_NUMBER];
    VIDEO_TIMER_USER_T  arUser[_VIDEO_TIMER_NUMBER];
    kal_bool    afgOccupied[_VIDEO_TIMER_NUMBER];
} VIDEO_TIMER_CTRL_T;

typedef struct
{
    kal_eventgrpid arEVG[_VIDEO_EVG_NUMBER];
    VIDEO_EVENT_GROUP_USER_T  arUser[_VIDEO_EVG_NUMBER];
    kal_bool    afgOccupied[_VIDEO_EVG_NUMBER];
} VIDEO_EVG_CTRL_T;

typedef struct
{
    kal_mutexid rMyMutex;
    VIDEO_MUTEX_CTRL_T rMutexCtrl;
    VIDEO_TIMER_CTRL_T rTimerCtrl;
    VIDEO_EVG_CTRL_T rEventGroupCtrl;
} VIDEO_RESOURCE_CTRL_T;

static VIDEO_RESOURCE_CTRL_T rResCtrl;

static kal_uint32 GetFreeIndex(kal_bool* pfgOccupied, kal_uint32 u4ArraySize)
{
    kal_int32 i = u4ArraySize - 1;

    if (0 == u4ArraySize)
    {
        ASSERT(0);
    }

    do{
        if (KAL_FALSE == *(pfgOccupied + i))
        {
            return i;
        }
    }while(--i >= 0);

    // all entries should be found in the array
    ASSERT(0);

    return 0; // Should not go here...
}

static kal_mutexid _VideoGetMutexInternal(VIDEO_MUTEX_USER_T eUserID)
{
    VIDEO_MUTEX_CTRL_T* prCtrl = &rResCtrl.rMutexCtrl;
    kal_mutexid rRet = NULL;
    kal_uint32 u4FreeIndex = 0;

    u4FreeIndex = GetFreeIndex(prCtrl->afgOccupied, _VIDEO_MUTEX_NUMBER);
    prCtrl->afgOccupied[u4FreeIndex] = KAL_TRUE;
    prCtrl->arUser[u4FreeIndex] = eUserID;
    rRet = prCtrl->arMutex[u4FreeIndex];

    return rRet;
}


kal_mutexid _VideoGetMutex(VIDEO_MUTEX_USER_T eUserID)
{
    kal_mutexid rMutex = rResCtrl.rMyMutex;
    kal_mutexid rRet = NULL;

    kal_take_mutex(rMutex);
    rRet = _VideoGetMutexInternal(eUserID);
    kal_give_mutex(rMutex);

    return rRet;
}
void _VideoFreeMutex(VIDEO_MUTEX_USER_T eUserID, kal_mutexid rMutexID)
{
    kal_int32 i;
    VIDEO_MUTEX_CTRL_T* prCtrl = &rResCtrl.rMutexCtrl;
    kal_mutexid rMutex = rResCtrl.rMyMutex;

    kal_take_mutex(rMutex);
    i = _VIDEO_MUTEX_NUMBER - 1;
    do{
        if (prCtrl->arMutex[i] == rMutexID)
        {
            if (KAL_FALSE == prCtrl->afgOccupied[i])
            {
                ASSERT(0);
            }
            kal_take_mutex(rMutexID);
            kal_give_mutex(rMutexID);
            prCtrl->afgOccupied[i] = KAL_FALSE;
            prCtrl->arUser[i] = MUTEX_USER_NONE;
            break;
        }
    }while(--i >= 0);
    kal_give_mutex(rMutex);
}

static void _VideoInitMutex(void)
{
    kal_uint32 i;
    VIDEO_MUTEX_CTRL_T* prCtrl = &rResCtrl.rMutexCtrl;
    kal_char au1Name[8] = "_VM_";
    kal_char u1Digit0 = (kal_char)'0';

    kal_mem_set((void*)prCtrl, 0, sizeof(*prCtrl));
    i = _VIDEO_MUTEX_NUMBER;
    do{
        au1Name[3] = u1Digit0++;
        prCtrl->arMutex[_VIDEO_MUTEX_NUMBER - i] = kal_create_mutex(au1Name);
    }while(--i != 0);
}

kal_eventgrpid _VideoGetEventGroup(VIDEO_EVENT_GROUP_USER_T eUserID)
{
    kal_mutexid rMutex = rResCtrl.rMyMutex;
    kal_uint32 u4FreeIndex = 0;
    VIDEO_EVG_CTRL_T* prCtrl = &rResCtrl.rEventGroupCtrl;
    kal_eventgrpid rRet = NULL;

    kal_take_mutex(rMutex);
    u4FreeIndex = GetFreeIndex(prCtrl->afgOccupied, _VIDEO_EVG_NUMBER);
    prCtrl->afgOccupied[u4FreeIndex] = KAL_TRUE;
    prCtrl->arUser[u4FreeIndex] = eUserID;
    rRet = prCtrl->arEVG[u4FreeIndex];
    kal_set_eg_events(rRet, 0, KAL_AND);
    kal_give_mutex(rMutex);

    return rRet;
}
void _VideoFreeEventGroup(VIDEO_EVENT_GROUP_USER_T eUserID, kal_eventgrpid rEVGID)
{
    kal_int32 i;
    VIDEO_EVG_CTRL_T* prCtrl = &rResCtrl.rEventGroupCtrl;
    kal_mutexid rMutex = rResCtrl.rMyMutex;

    kal_take_mutex(rMutex);
    i = _VIDEO_EVG_NUMBER - 1;
    do{
        if (prCtrl->arEVG[i] == rEVGID)
        {
            if (KAL_FALSE == prCtrl->afgOccupied[i])
            {
                ASSERT(0);
            }
            prCtrl->afgOccupied[i] = KAL_FALSE;
            prCtrl->arUser[i] = EVG_USER_NONE;
            break;
        }
    }while(--i >= 0);
    kal_give_mutex(rMutex);
}

static void _VideoInitEventGroup(void)
{
    kal_uint32 i;
    VIDEO_EVG_CTRL_T* prCtrl = &rResCtrl.rEventGroupCtrl;
    kal_char au1Name[8] = "_VE_";
    kal_char u1Digit0 = (kal_char)'0';

    kal_mem_set((void*)prCtrl, 0, sizeof(*prCtrl));
    i = _VIDEO_EVG_NUMBER;
    do{
        au1Name[3] = u1Digit0++;
        prCtrl->arEVG[_VIDEO_EVG_NUMBER - i] = kal_create_event_group(au1Name);
    }while(--i != 0);
}

kal_timerid _VideoGetTimer(VIDEO_TIMER_USER_T eUserID)
{
    kal_mutexid rMutex = rResCtrl.rMyMutex;
    kal_uint32 u4FreeIndex = 0;
    VIDEO_TIMER_CTRL_T* prCtrl = &rResCtrl.rTimerCtrl;
    kal_timerid rRet = NULL;

    kal_take_mutex(rMutex);
    u4FreeIndex = GetFreeIndex(prCtrl->afgOccupied, _VIDEO_TIMER_NUMBER);
    prCtrl->afgOccupied[u4FreeIndex] = KAL_TRUE;
    prCtrl->arUser[u4FreeIndex] = eUserID;
    rRet = prCtrl->arTimer[u4FreeIndex];
    kal_cancel_timer(rRet);
    kal_give_mutex(rMutex);

    return rRet;
}
void _VideoFreeTimer(VIDEO_TIMER_USER_T eUserID, kal_timerid rTimerID)
{
    kal_int32 i;
    VIDEO_TIMER_CTRL_T* prCtrl = &rResCtrl.rTimerCtrl;
    kal_mutexid rMutex = rResCtrl.rMyMutex;

    kal_take_mutex(rMutex);
    i = _VIDEO_TIMER_NUMBER - 1;
    do{
        if (prCtrl->arTimer[i] == rTimerID)
        {
            if (KAL_FALSE == prCtrl->afgOccupied[i])
            {
                ASSERT(0);
            }
            prCtrl->afgOccupied[i] = KAL_FALSE;
            prCtrl->arUser[i] = TIMER_USER_NONE;
            break;
        }
    }while(--i >= 0);
    kal_give_mutex(rMutex);
}

static void _VideoInitTimer(void)
{
    kal_uint32 i;
    VIDEO_TIMER_CTRL_T* prCtrl = &rResCtrl.rTimerCtrl;
    kal_char au1Name[8] = "_VT_";
    kal_char u1Digit0 = (kal_char)'0';

    kal_mem_set((void*)prCtrl, 0, sizeof(*prCtrl));
    i = _VIDEO_TIMER_NUMBER;
    do{
        au1Name[3] = u1Digit0++;
        prCtrl->arTimer[_VIDEO_TIMER_NUMBER - i] = kal_create_timer(au1Name);
    }while(--i != 0);
}

#ifdef __VE_DCM_WITH_COMPRESSION__
static kal_mutexid rDCMMutexID;
static kal_uint32 u4DCMLoadedUser;

static void VideoDCMInit()
{
    rDCMMutexID = _VideoGetMutexInternal(MUTEX_USER_DCM); // never free during system running
}

void VideoDCMCheck(kal_uint32 u4DCMUser)
{
    if(u4DCMLoadedUser != u4DCMUser)
    {
        ASSERT(0);
    }
}


void VideoDCMLoad(kal_uint32 u4DCMUser)
{
    kal_uint32* pu4DCMBuf = NULL;
    kal_uint32 u4DCMSize = 0;

    kal_take_mutex(rDCMMutexID);
    if(u4DCMLoadedUser != 0)
    {
        ASSERT(0);
    }

    u4DCMLoadedUser = u4DCMUser;
    /* Load DCM with compression */
    kal_trace(TRACE_FUNC, TRC_VIDEO_DCM_LOAD, u4DCMUser);
    DCM_Load(u4DCMUser, &pu4DCMBuf, &u4DCMSize);

#ifdef __VE_MM_DCM_SUPPORT__
    DCM_Load(DYNAMIC_CODE_COMPRESS_VECOM, &pu4DCMBuf, &u4DCMSize);
#endif

    kal_give_mutex(rDCMMutexID);
}

void VideoDCMUnLoad(kal_uint32 u4DCMUser)
{
    kal_take_mutex(rDCMMutexID);
    if((u4DCMLoadedUser != u4DCMUser) || (rDCMMutexID==NULL))
    {
        ASSERT(0);
    }
    kal_trace(TRACE_FUNC, TRC_VIDEO_DCM_UNLOAD, u4DCMUser);
    DCM_Unload(u4DCMUser);
#ifdef __VE_MM_DCM_SUPPORT__
    DCM_Unload(DYNAMIC_CODE_COMPRESS_VECOM);
#endif
    u4DCMLoadedUser = 0;
    kal_give_mutex(rDCMMutexID);
}
#endif


void VideoInitSource(void)
{
    _VideoInitMutex();
    _VideoInitEventGroup();
    _VideoInitTimer();

    rResCtrl.rMyMutex = _VideoGetMutexInternal(MUTEX_USER_CTRL);

#ifdef __VE_DCM_WITH_COMPRESSION__
    VideoDCMInit();
#endif
}

#endif /* __VE_VIDEO_ARCHI_V2__*/

