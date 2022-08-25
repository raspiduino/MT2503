#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
#include <memory.h>
#include <windows.h>
#include <time.h>
#else
#include "mmi_frm_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "med_utility.h"
#endif

#include "m3d_adaption.h"
#include "M3DGameDef.h"

#ifdef __cplusplus
extern "C" {
#endif

//for .NET
static void *m3d_handle = NULL;
static int  m3d_adaption_appid = -1;
static int  m3d_adaption_pageX = 0;

M3D_AdaptionClock LW_AdaptionClock;

//record loading time
void m3d_adaption_before_startup(void)
{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	LW_AdaptionClock.m_Tick_Before_Startup = (float) timeGetTime();
#else
	{
    kal_uint32 tick;

    kal_get_time(&tick);
	LW_AdaptionClock.m_Tick_Before_Startup = (float) kal_ticks_to_milli_secs(tick);
	}
#endif
	LW_AdaptionClock.m_Tick_Before_PVR = 0.0f;
	LW_AdaptionClock.m_Tick_After_PVR = 0.0f;
	LW_AdaptionClock.m_Tick_Before_Load1 = 0.0f;
	LW_AdaptionClock.m_Tick_After_Load1 = 0.0f;
	LW_AdaptionClock.m_Tick_Before_Load2 = 0.0f;
	LW_AdaptionClock.m_Tick_After_Load2 = 0.0f;
}

void m3d_adaption_before_pvr(void)
{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	LW_AdaptionClock.m_Tick_Before_PVR = (float) timeGetTime();
#else
	{
    kal_uint32 tick;

    kal_get_time(&tick);
	LW_AdaptionClock.m_Tick_Before_PVR = (float) kal_ticks_to_milli_secs(tick);
	}
#endif
}

void m3d_adaption_after_pvr(void)
{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	LW_AdaptionClock.m_Tick_After_PVR = (float) timeGetTime();
#else
	{
    kal_uint32 tick;

    kal_get_time(&tick);
	LW_AdaptionClock.m_Tick_After_PVR = (float) kal_ticks_to_milli_secs(tick);
	}
#endif
}

int  m3d_adaption_get_pvr_time(void)
{
	return (int) (LW_AdaptionClock.m_Tick_After_PVR - LW_AdaptionClock.m_Tick_Before_PVR);
}

void m3d_adaption_before_load1(void)
{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	LW_AdaptionClock.m_Tick_Before_Load1 = (float) timeGetTime();
#else
	{
    kal_uint32 tick;

    kal_get_time(&tick);
	LW_AdaptionClock.m_Tick_Before_Load1 = (float) kal_ticks_to_milli_secs(tick);
	}
#endif
}

void m3d_adaption_after_load1(void)
{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	LW_AdaptionClock.m_Tick_After_Load1 = (float) timeGetTime();
#else
	{
    kal_uint32 tick;

    kal_get_time(&tick);
	LW_AdaptionClock.m_Tick_After_Load1 = (float) kal_ticks_to_milli_secs(tick);
	}
#endif
}

void m3d_adaption_before_load2(void)
{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	LW_AdaptionClock.m_Tick_Before_Load2 = (float) timeGetTime();
#else
	{
    kal_uint32 tick;

    kal_get_time(&tick);
	LW_AdaptionClock.m_Tick_Before_Load2 = (float) kal_ticks_to_milli_secs(tick);
	}
#endif
}

void m3d_adaption_after_load2(void)
{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	LW_AdaptionClock.m_Tick_After_Load2 = (float) timeGetTime();
#else
	{
    kal_uint32 tick;

    kal_get_time(&tick);
	LW_AdaptionClock.m_Tick_After_Load2 = (float) kal_ticks_to_milli_secs(tick);
	}
#endif
}

int  m3d_adaption_get_load1_time(void)
{
	return (int) (LW_AdaptionClock.m_Tick_After_Load1 - LW_AdaptionClock.m_Tick_Before_Startup);
}

int  m3d_adaption_get_load2_time(void)
{
	return (int) (LW_AdaptionClock.m_Tick_After_Load2 - LW_AdaptionClock.m_Tick_Before_Load2);
}

void m3d_adaption_set_appid(int _id)
{
	m3d_adaption_appid = _id;
}

void m3d_adaption_reset_appid(void)
{
	m3d_adaption_appid = -1;
}

void m3d_adaption_set_pageX(int _px)
{
	m3d_adaption_pageX = _px;
}

int m3d_adaption_get_pageX(void)
{
	return m3d_adaption_pageX;
}

void m3d_adaption_init(M3D_Adaption *_this, void *_pConfig)
{
	M3DConfig *PC = (M3DConfig *)_pConfig;

	memset(_this, 0, sizeof(M3D_Adaption));

#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	srand( (unsigned)time( NULL ) );
	_this->m_CurrentTick = (float) timeGetTime();
#else
	{
    kal_uint32 tick;

    kal_get_time(&tick);
	_this->m_CurrentTick = (float) kal_ticks_to_milli_secs(tick);
	srand( (unsigned int)tick );
	}
#endif

	_this->m_Handle = (void *) PC->m_Handle;
	m3d_handle = (void *) PC->m_Handle; 
}

void *m3d_get_handle(void)
{
	return m3d_handle;
}

long m3d_adaption_get_memsize(int _width, int _height)
{
    return 2*1024*1024;
}

void m3d_set_local_time(int _iHour, int _iMinute, int _iSecond)
{
	LW_AdaptionClock.m_Hour = _iHour;
	LW_AdaptionClock.m_Minute = _iMinute;
	LW_AdaptionClock.m_Second = _iSecond;
}

int  m3d_adaption_rand(void)
{
	return rand();
}

void m3d_time_resume(M3D_Adaption *_this)
{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	_this->m_CurrentTick = (float) timeGetTime();
#else
	{
    kal_uint32 tick;

    kal_get_time(&tick);
	_this->m_CurrentTick = (float) kal_ticks_to_milli_secs(tick);
	}
#endif
}

float m3d_time_get_elapsed(M3D_Adaption *_this)
{
	float diff = 0.0f;
	float last = _this->m_CurrentTick;

#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	_this->m_CurrentTick = (float) timeGetTime();
#else
	{
    kal_uint32 tick;

    kal_get_time(&tick);
	_this->m_CurrentTick = (float) kal_ticks_to_milli_secs(tick);
	}
#endif

	diff = _this->m_CurrentTick - last;
	
	if (diff> 500.0f)
		diff = 33.3f;
		
	return diff;
}

float m3d_time_get(M3D_Adaption *_this)
{
	float _time = 0.0f;

#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	_time = (float) timeGetTime();
#else
	{
    kal_uint32 tick;

    kal_get_time(&tick);
	_time = (float) kal_ticks_to_milli_secs(tick);
	}
#endif
	return _time;
}

float m3d_time_set(M3D_Adaption *_this, float _iCurrent_tick)
{
	float diff = 0.0f;

	if (_this->m_CurrentTick != 0)
		diff = _iCurrent_tick - _this->m_CurrentTick;

	_this->m_CurrentTick = _iCurrent_tick;

	return diff;
}

//static unsigned char igv4_mem[2*1024*1024];

void *m3d_alloc_engine_memory(M3D_Adaption *_this, long _size)
{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	if (_this->m_EngineMemory != NULL)
		m3d_free_engine_memory(_this);

	_this->m_EngineMemory = malloc(_size);
	if (_this->m_EngineMemory != NULL)
		_this->m_EngineMemorySize = _size;
	else
		_this->m_EngineMemorySize = 0;

#else
#if defined(__COSMOS_MMI__)
    if (m3d_adaption_appid != -1)
    {
	    //_this->m_EngineMemory = (void *) igv4_mem;
	    _this->m_EngineMemory = mmi_frm_asm_alloc_r(m3d_adaption_appid, _size);
	    if (NULL == _this->m_EngineMemory)
	    {
		    MMI_ASSERT(0);
	    }
		else
		{
			memset(_this->m_EngineMemory, 0, 2*1024*1024);
		}
    }
    else
    {
	    MMI_ASSERT(0);
    }
#else
    _this->m_EngineMemory = med_alloc_asm_mem_cacheable(0, _size);
    if (NULL == _this->m_EngineMemory)
    {
	    MMI_ASSERT(0);
    }
#endif
#endif

	return _this->m_EngineMemory;
}

void m3d_free_engine_memory(M3D_Adaption *_this)
{
#if defined(WIN32) && !defined(_MODIS_ON_VC9_)
	free(_this->m_EngineMemory);
#else
#if defined(__COSMOS_MMI__)
    if (m3d_adaption_appid != -1)
    {
	    mmi_frm_asm_free_r(m3d_adaption_appid, _this->m_EngineMemory);
    }
    else
    {
	    MMI_ASSERT(0);
    }
#else
    med_free_asm_mem(0, (void **)&_this->m_EngineMemory);
#endif
#endif

	m3d_adaption_appid = -1;
	_this->m_EngineMemory = NULL;
}

void m3d_time_update_FPS(M3D_Adaption *_this, FrameStatics *_pPF)
{
	/* update FPS timing info */
	long uNow;
	static long uLastTime = 0;
	static long uFrmCnt = 0;

	/* check if called first time */
	if (uLastTime == 0) {
		_pPF->m_uFrames = 0;
		uLastTime = (long) m3d_time_get(_this);
	}

	// increase count of frames		
	++(_pPF->m_uFrames);

	// Get the app's time, in seconds. Skip rendering if no time elapsed
	uNow = (long) m3d_time_get(_this);
	uFrmCnt++;

	// Update the scene stats once per second
	if (uNow - uLastTime >= 5000) {
		_pPF->m_fFPS = (float) (uFrmCnt) / (float)(uNow - uLastTime) * 1000.0f;
		uLastTime = uNow;
		uFrmCnt = 0;
		printf("<IGV5Time_UpdateFPS> FPS = %7.3f\n", _pPF->m_fFPS );
	} 

}

#ifdef __cplusplus
}
#endif
