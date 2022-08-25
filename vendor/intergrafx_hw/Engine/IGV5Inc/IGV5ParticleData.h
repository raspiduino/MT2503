#ifndef IGV5_PARTICLE_H
#define IGV5_PARTICLE_H

#include "IGV5Def.h"

#ifdef __cplusplus
extern "C"{
#endif

//---------------------------------------------------------------------------------------------------------------
typedef struct _IGV5ParticleData
{    
    float m_fLifeSpan;
    float m_fSize;
    float m_fEndRot;
    Vec3 m_vStartPosition;
    Vec3 m_vVelocity;
    Vec3 m_vAcceleration;    
}IGV5ParticleData;

//---------------------------------------------------------------------------------------------------------------
void IGV5Particle_SetInitialValue(IGV5ParticleData* p);




#ifdef __cplusplus
}
#endif
#endif// IGV5_PARTICLE_H