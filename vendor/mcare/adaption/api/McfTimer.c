/***************************************************
* McrTimer.c
* timer interface implement, base on stack timer on MTK
* by arlo,2010.09.19
* Tencent
****************************************************/
#ifdef __MCAREV31__
#ifndef _TENCENT_MCARE_ADP_
#define _TENCENT_MCARE_ADP_
#endif

#include "MAdpConfig.h"
#include "McfPlatform.h"

#include "McfTime.h"
#include "McfTimer.h"

MVOID *McfInitBaseTimer(MVOID);
MVOID McfStartBaseTimer(MVOID * pBaseTimer, MUINT init_time);
MVOID McfStopBaseTimer(MVOID * pBaseTimer);
MVOID MCR_HandleDelayedWork(MVOID);

/* Timer */

#define _MCF_PRECISE_TIMER_ 

//===========================================================================
#ifdef _MCF_PRECISE_TIMER_
/*arlo,basicly implemented according to stack timer*/
//#define _MCF_TIMER_DEBUG_

#define MCF_MAX_TIMERS 	(30)

typedef void (*ExpireFuncPtr)(void *arg);
typedef struct _McfTimer
{
	int id;
	unsigned int state;
	unsigned int interval;
	unsigned int deadtime;
	ExpireFuncPtr expireFunc;
	void *arg;
	struct _McfTimer *next;
}McfTimer;

typedef enum
{
	MCF_TIMER_INACTIVATE,
	MCF_TIMER_ACTIVATE,
	MCF_TIMER_SUSPEND //not used now...reserved
}EMcfTimerState;


#ifdef _MCF_TIMER_DEBUG_
static MINT actTmCount;
#endif

typedef struct _McfTimerCntx
{
	MVOID *pBaseTimer;
	McfTimer         timers[MCF_MAX_TIMERS];
	McfTimer         *actTimer;//activate timer list
	MBOOL           isProcessingTimeout;
}McfTimerCntx;

static McfTimerCntx gMcfTimerCntx;

#define __BaseTimer   (gMcfTimerCntx.pBaseTimer)
MVOID __StartBaseTimer(MUINT init_time) 	
{
    if(__BaseTimer)
    {
        McfStartBaseTimer(__BaseTimer, init_time);
    }
}
MVOID __StopBaseTimer(MVOID)
{
    if(__BaseTimer)
    {
        McfStopBaseTimer(__BaseTimer);
    }
}

#define __TimerList             ((McfTimer*)&(gMcfTimerCntx.timers))
#define __TimerListEnd          (__TimerList+MCF_MAX_TIMERS) //invalid timer
#define __TimerNext(timer)	    (((McfTimer*)timer)+1)
#define __ActTimerList          (gMcfTimerCntx.actTimer)

#define __GetCurrentTimeMs(time)	time = McfTime_GetSysTimeMs()

#define __IsTimerValid(timer)   ((timer) && (timer) >=__TimerList && (timer) < __TimerListEnd)
#define __AllocTimer()     __LookupTimer(0,MCF_TIMER_INACTIVATE)

#define __IsProcessingTimeout()     (gMcfTimerCntx.isProcessingTimeout)
#define __SetProcessingTimeout(val)   (gMcfTimerCntx.isProcessingTimeout=(val)) 



static McfTimer *__LookupTimer(MINT id,MUINT state)
{
	McfTimer *timer=MNULL;

	timer = __TimerList;
	while(timer && timer <__TimerListEnd)
	{
		if(timer->id == id && timer->state == state)
		{
			break;
		}

		timer = __TimerNext(timer);
	}

	if(timer == __TimerListEnd)
	{//fix bug..invalid timer..arlo
	    timer = MNULL;
	}

	return timer;
}


static MVOID __ResetBaseTimer(MVOID)
{//reschedule the timer to run
	MINT remain = 0x7fffffff;
	MUINT current;
	McfTimer *timer;

	//__AdjustTimerList();
	if(__IsProcessingTimeout()==MFALSE)
	{
		__StopBaseTimer();//@1
		timer = __ActTimerList;
		if(timer)
		{
			__GetCurrentTimeMs(current);//@2
			remain = timer->deadtime - current;//@3
			if(remain <0)
			{//expire immediatelly...
				remain = 0;
			}
		}
		if(remain != 0x7fffffff )
		{
			__StartBaseTimer(remain);
		}
	}
}
static MVOID __PutActTimerList(McfTimer *timer)
{//put timer into act-timer-list,sort by deadtime
	McfTimer *tm,*prev;

	if(timer ==MNULL || timer->state != MCF_TIMER_ACTIVATE)
	{
		return ;
	}
	if(__ActTimerList==MNULL )
	{
		__ActTimerList = timer;
	}
	else if( timer->deadtime < __ActTimerList->deadtime)
	{//head
		timer->next = __ActTimerList;
		__ActTimerList = timer;
	}
	else
	{
		prev = __ActTimerList;
		tm = __ActTimerList->next;
		while(tm)
		{
			if(timer->deadtime < tm->deadtime)
			{
				break;
			}
			prev = tm;
			tm=tm->next;
		}
		timer->next = tm;
		prev->next =timer;

	}
}

static MVOID __RemActTimerList(McfTimer *timer)
{//remove timer from act-timer-list
	McfTimer *tm,*prev;

	if(timer ==MNULL || timer->state != MCF_TIMER_ACTIVATE || __ActTimerList==MNULL)
	{
		return ;
	}

	if(__ActTimerList==timer)
	{//head
		__ActTimerList = __ActTimerList->next;
	}
	else
	{
		prev = __ActTimerList;
		tm = __ActTimerList->next;
		while(tm)
		{
			if(tm ==timer)
			{
				prev->next = tm->next;
				break;
			}
			prev = tm;
			tm=tm->next;
		}
	}
}

McfTimer * McfActivateTimer(MUINT interval,ExpireFuncPtr expireFunc,MVOID *arg)
{
	McfTimer *timer = MNULL;
	if(interval ==0)
	{
		interval = 50;
	}
	//if(interval >0)
	{
		MUINT current;
		timer = __AllocTimer();
		if(timer)
		{
			timer->state = MCF_TIMER_ACTIVATE;
			__GetCurrentTimeMs(current);
			timer->deadtime = interval + current;
			timer->interval = interval;
			timer->expireFunc = expireFunc;
			timer->arg = arg;
			timer->next = MNULL;
			__PutActTimerList(timer);//put the timer into act-timer-list
			__ResetBaseTimer();
#ifdef _MCF_TIMER_DEBUG_
			//trace and log here will cause delay..
			actTmCount++;
			MCR_DEBUG_PORTING_TIMER(ALOG_INFO, "[McfActivateTimer]actTmCount[%d]current:%u,interval:%u,supposed:%u",actTmCount,current,timer->interval,timer->deadtime);
#endif
		}
		else
		{
#ifdef _MCF_TIMER_DEBUG_
			//trace and log here will cause delay..
			actTmCount++;
			MCR_DEBUG_PORTING_TIMER(ALOG_INFO, "[McfActivateTimer]actTmCount[%d]Fail!!!",actTmCount);
#endif
		}
	}
	/*else
	{//interval is 0
	if(expireFunc)
	{
	expireFunc(arg);
	}
	}*/

	return timer;
}

MVOID McfInactivateTimer(McfTimer *timer)
{
	if( __IsTimerValid(timer) && timer->state == MCF_TIMER_ACTIVATE)
	{
		__RemActTimerList(timer);//remove the timer from act-timer-list
		timer->interval = (~0);
		timer->deadtime = (~0);
		timer->id = 0;
		timer->state = MCF_TIMER_INACTIVATE;
		timer->next = MNULL;
		timer->expireFunc = MNULL;
		timer->arg = MNULL;
		__ResetBaseTimer();
#ifdef _MCF_TIMER_DEBUG_
		//trace and log here will cause delay..
		actTmCount--;
		MCR_DEBUG_PORTING_TIMER(ALOG_INFO, "[McfInactivateTimer]actTmCount[%d]",actTmCount);
#endif
	}
}

MVOID McfTimeoutDispatch(MVOID)
{
	McfTimer *timer;
	MUINT current;
	ExpireFuncPtr expireFunc;
	MVOID *arg;

	__SetProcessingTimeout(MTRUE);
	__StopBaseTimer();
	timer = __ActTimerList;
	while(timer)
	{
		__GetCurrentTimeMs(current);
		if(timer->state==MCF_TIMER_ACTIVATE && timer->deadtime <= current)
		{//dead time arrive finally
#ifdef _MCF_TIMER_DEBUG_
			//trace and log here will cause delay..
			MCR_DEBUG_PORTING_TIMER(ALOG_INFO, "[Timeout][McfBaseTimerExpireProcess]current:%u,supposed:%u,interval:%u,delta:%d",current,timer->deadtime,timer->interval,current-timer->deadtime);
#endif
			expireFunc= timer->expireFunc;
			arg = timer->arg;
			McfInactivateTimer(timer);
			if(expireFunc)
			{
				expireFunc(arg);
			}
			timer = __ActTimerList;//always fetch from act-timer-list head
			continue;
		}
		break;
	}
	__SetProcessingTimeout(MFALSE);
	__ResetBaseTimer();
	
    MCR_HandleDelayedWork();
}

MVOID McfInitTimer(MVOID)
{//adapt to MTK
	//stack_init_timer(__BaseTimer, "McfTimer",MOD_MMI);
	__BaseTimer = McfInitBaseTimer();
}

MVOID McfDeInitTimer(MVOID)
{
    if(__BaseTimer)
    {
        McfStopBaseTimer(__BaseTimer);
    }
    //__BaseTimer = MNULL;//DO NOT CLEAR
	__ActTimerList = MNULL;
	memset(__TimerList,0,sizeof(McfTimer)*MCF_MAX_TIMERS);
}

int IsMcfBaseTimer(void *basetimer)
{
	return ((void*)__BaseTimer ==basetimer);
}

MTmHandle McfTm_StartTimer( MVOID *pUser,MUINT interval,pfnTimerFuncPtr expireFunc)
{
	McfTimer *timer;

	timer = McfActivateTimer(interval, (ExpireFuncPtr)expireFunc, pUser);
	if(timer)
	{
		timer->id = (MINT)(timer - __TimerList);
	    return timer->id;
	}

	return -1;
}


MVOID McfTm_StopTimer(MTmHandle timerHd)
{
	McfTimer *timer =MNULL;//(McfTimer*)timerHd;
	
	if(timerHd< 0 && timerHd >= MCF_MAX_TIMERS)
	{
	    return ;
	}

	timer = __TimerList+ timerHd;//__LookupTimer(timerid,MCF_TIMER_ACTIVATE);

	if(timer && timer->state ==MCF_TIMER_ACTIVATE )
	{
		McfInactivateTimer( timer);
	}
}
MVOID McfTm_StopAllTimer(MVOID)
{
	__StopBaseTimer();
}

#else
MUSHORT __GetAvailTimer(MVOID)
{
	MINT i;
	for(i=MCARE_TIMER_BASE; i<=MCARE_TIMER_END;i++)
	{
		if(!IsMyTimerExist(i))
		{
			return i;
		}
	}
	return 0;
}

MTmHandle McfTm_StartTimer( MVOID *pUser,MUINT interval,pfnTimerFuncPtr expireFunc)
{
	MUSHORT timerId;

	timerId = __GetAvailTimer();
	if(timerId)
	{
		StartTimerEx( timerId, interval, (oslTimerFuncPtr) expireFunc, pUser);
	}
	return timerId;
}

MVOID McfTm_StopTimer(MTmHandle timerHd)
{
	StopTimer(timerHd);
}

MVOID McfInitTimer(MVOID)
{
#if (MCR_MTK_VER >= 1132)  //purple

    int timer_id = McfGetTimerBaseId();

    for(;timer_id <= McfGetTimerEndId();timer_id++)
    {
        McfTm_StopTimer(timer_id);
    }

#endif	
}

MVOID McfDeInitTimer(MVOID)
{
}

MVOID McfBaseTimerExpireProcess(MVOID *basetimer)
{
}

int IsMcfBaseTimer(void *basetimer)
{
	return 0;
}

MVOID McfTm_StopAllTimer(MVOID)
{

}
#endif

#endif
