/*!*****************************************************************************

 @File         IGV5Particle.h 

 @Title        IGV5Particle

 @Version      

 @brief			header file for particle set and particle manager

******************************************************************************/

#ifndef __IGV5PARTICLE_H
#define __IGV5PARTICLE_H

#include "IGV5Shader.h"
#include "IGV5Texture.h"
#include "IGV5Renderer.h"
#include "IGV5Matrix.h"
#include "IGV5Memory.h"
#include "IGV5Camera.h"

/*! @def	This particle stream is completed */
#define IGV5EID_ENDLIFE 0x0000001

#define PARTICLE_SIZE   7

typedef struct {
	float m_fLifeTime;
	Vec3 m_fStartPos;
	Vec3 m_fEndPos;
} IGV5ParticleVertex;

typedef struct IGV5ParticleSetType {

   /* Texture handles */
   IGV5Texture *m_pParticleTex;
   IGV5Texture *m_pAlphaTex;

   /* Particle vertex data */
   float *particleData;
   unsigned m_uMaxNumParticles;

   float m_fParticleScale;

   float m_fLifeTime;

   float m_fStartColor[4], m_fEndColor[4];

   Vec3 m_vCenter;

   IGV5Matrix m_mMVP;

   // Current time
   float time;

   int m_bActive;

   int (*m_fnParticleCallback)(struct IGV5ParticleSetType *pS, unsigned uParticleEvtID, unsigned uData1);

} IGV5ParticleSet;

IGV5Err IGV5ParticleSet_Create(IGV5ParticleSet *pS, IGV5Texture *pTex, IGV5Texture *pAlphaTex, unsigned uMaxParticles, float fParticleScale, float fLifeTime);
void IGV5ParticleSet_Update (IGV5ParticleSet *pS, float deltaTime, IGV5Camera *pCam, IGV5Matrix *pWorld );
void IGV5ParticleSet_Draw (IGV5ParticleSet *pS);
void IGV5ParticleSet_Trigger(IGV5ParticleSet *pS);
void IGV5ParticleSet_Release (IGV5ParticleSet *pS);
IGV5Err IGV5ParticleSet_GetBuffer(IGV5ParticleSet *pS, IGV5ParticleVertex **ppVB, unsigned *uNumVertices);

#endif