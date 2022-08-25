#ifndef __M3D_ADAPTION_H__
#define __M3D_ADAPTION_H__

#include "IGV5Memory.h"
#include "IGV5Renderer.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _m3d_adaption
{
	float m_CurrentTick;
	void *m_EngineMemory;
	long m_EngineMemorySize;
	void *m_Handle;
} M3D_Adaption;

typedef struct _m3d_adaption_clock
{
	int m_Hour;
	int m_Minute;
	int m_Second;
	float m_Tick_Before_Startup;
	float m_Tick_Before_PVR;
	float m_Tick_After_PVR;
	float m_Tick_Before_Load1;
	float m_Tick_After_Load1;
	float m_Tick_Before_Load2;
	float m_Tick_After_Load2;
} M3D_AdaptionClock;

extern M3D_AdaptionClock LW_AdaptionClock;

//record loading time
extern void m3d_adaption_before_startup(void);
extern void m3d_adaption_before_pvr(void);
extern void m3d_adaption_after_pvr(void);
extern void m3d_adaption_before_load1(void);
extern void m3d_adaption_after_load1(void);
extern void m3d_adaption_before_load2(void);
extern void m3d_adaption_after_load2(void);
extern int  m3d_adaption_get_pvr_time(void);
extern int  m3d_adaption_get_load1_time(void);
extern int  m3d_adaption_get_load2_time(void);

extern void m3d_adaption_set_appid(int _id);
extern void m3d_adaption_reset_appid(void);
extern void m3d_adaption_set_pageX(int _px);
extern int  m3d_adaption_get_pageX(void);

extern void m3d_adaption_init(M3D_Adaption *_this, void *_pConfig);
extern long m3d_adaption_get_memsize(int _width, int _height);
extern void *m3d_get_handle(void);

extern void m3d_set_local_time(int _iHour, int _iMinute, int _iSecond);
extern void m3d_time_resume(M3D_Adaption *_this);
extern float m3d_time_get_elapsed(M3D_Adaption *_this);
extern float m3d_time_get(M3D_Adaption *_this);
extern float m3d_time_set(M3D_Adaption *_this, float _iCurrent_tick);
extern void m3d_time_update_FPS(M3D_Adaption *_this, FrameStatics *_pPF);

extern void *m3d_alloc_engine_memory(M3D_Adaption *_this, long _size);
extern void m3d_free_engine_memory(M3D_Adaption *_this);
extern int  m3d_adaption_rand(void);

#ifdef __cplusplus
}
#endif

#endif //__M3D_ADAPTION_H__
