#ifndef IGV5_PARTICLESYSTEM_H
#define IGV5_PARTICLESYSTEM_H

#include "IGV5Def.h"
#include "IGV5ParticleEmitter.h"
#include "IGV5Camera.h"

#ifdef __cplusplus
extern "C"{
#endif

//---------------------------------------------------------------------------------------------------------------
IGV5Err IGV5ParticleSystem_Init();
IGV5Err IGV5ParticleSystem_Shutdown();

IGV5Err IGV5ParticleSystem_AddEmitter();
IGV5Err IGV5ParticleSystem_RemoveEmitter(IGV5ParticleEmitter* p);
//IGV5Err IGV5ParticleSystem_RemoveAllEmitter();

void IGV5ParticleSystem_EmitParticles(IGV5ParticleEmitter* p, float fDelataTime, IGV5Camera *pCam, IGV5Matrix *pWorld);

void IGV5ParticleSystem_PreRenderParticle(void);
void IGV5ParticleSystem_RenderParticles(IGV5ParticleEmitter* p, IGV5Camera *pCam, IGV5Matrix *pWorld);
void IGV5ParticleSystem_PostRenderParticle(void);

#ifdef __cplusplus
}
#endif
#endif// IGV5_PARTICLESYSTEM_H