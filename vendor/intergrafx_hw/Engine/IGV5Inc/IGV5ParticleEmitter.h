#ifndef IGV5_PARTICLEEMITTER_H
#define IGV5_PARTICLEEMITTER_H

#include "IGV5Def.h"
#include "IGV5Texture.h"
#include "IGV5Matrix.h"
#include "IGV5ParticleData.h"

#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------------------------------------------
typedef struct tIGV5ParticleEmitterAttrib
{
    char m_cName[32];
    int m_bEnabled;
    int m_bLoop;

    Vec3 m_vPosition;
    float m_fEmitterRadius;

    int m_bUseGravity;
    Vec3 m_vGravity;

    int m_iMinEmission;
    int m_iMaxEmission;

    float m_fMinLifeSpan;
    float m_fMaxLifeSpan;

    float m_fMinSize;
    float m_fMaxSize;
    float m_fEndSizeScale;

    Vec3 m_vMinVelocity;
    Vec3 m_vMaxVelocity;

    Vec3 m_vMinAcceleration;
    Vec3 m_vMaxAcceleration;

    float m_fMaxRot;
    float m_fMinRot;

    Vec3 m_vStartColor;
    Vec3 m_vEndColor;

    float m_fStartAlpha;
    float m_fEndAlpha;

    float m_fTimeStepScale;
}IGV5ParticleEmitterAttrib;

//---------------------------------------------------------------------------------------------------------------
typedef struct _IGV5ParticleEmitter
{
    IGV5ParticleEmitterAttrib m_pAttrib;
    // 
    IGV5Texture *m_pDiffuseTex;
    IGV5Texture *m_pAlphaTex;
    IGV5ParticleData *m_pParticles;
    IGV5Matrix m_mMVP;
    // for emission
    int m_iCurrentEmission;
    float m_fAge;    
}IGV5ParticleEmitter;

//---------------------------------------------------------------------------------------------------------------
IGV5Err IGV5ParticleEmitter_Create(IGV5ParticleEmitter *pEmitter, IGV5ParticleEmitterAttrib *pAttrib);//todo:create with property
void IGV5ParticleEmitter_Emit(IGV5ParticleEmitter* p, float fDeltaTime);
IGV5Err IGV5ParticleEmitter_Release(IGV5ParticleEmitter* p);

//---------------------------------------------------------------------------------------------------------------
void IGV5ParticleEmitter_SetInitialValue(IGV5ParticleEmitter* pEmitter, IGV5ParticleEmitterAttrib *pAttrib);
void IGV5ParticleEmitter_SetDiffuseTex(IGV5ParticleEmitter* p, IGV5Texture* pTex);
void IGV5ParticleEmitter_SetAlphaTex(IGV5ParticleEmitter* p, IGV5Texture* pTex);
void IGV5ParticleEmitter_GenParticles(IGV5ParticleEmitter* p);

//---------------------------------------------------------------------------------------------------------------
float IGV5ParticleEmitter_RandomFloatArrtib(float fMin, float fMax);
int IGV5ParticleEmitter_RandomIntArrtib(int fMin, int fMax);
Vec3 IGV5ParticleEmitter_RandomVec3Arrtib(Vec3 fMin, Vec3 fMax);


#ifdef __cplusplus
}
#endif
#endif//IGV5_PARTICLEEMITTER_H