#ifndef IGV5_PARTICLESHADER_H
#define IGV5_PARTICLESHADER_H

#include <GLES2/gl2.h>
#include "IGV5Def.h"

#ifdef __cplusplus
extern "C"{
#endif

//---------------------------------------------------------------------------------------------------------------
extern int g_uParticleVertShaderID;
extern int g_uParticleFragShaderID;
extern GLuint g_uParticleShaderProgram;
extern int g_ParticleShaderCreated;

//---------------------------------------------------------------------------------------------------------------
typedef struct _ParticleShaderAttribute
{
    GLint LifeSpanLoc;    
    GLint SizeLoc;
    GLint EndRotLoc;
    GLint StartPositionLoc;
    GLint StartVelocityLoc;
    GLint AccelerationLoc;    
}ParticleShaderAttribute;
extern ParticleShaderAttribute g_PSAttribute;

//---------------------------------------------------------------------------------------------------------------
typedef struct _ParticleShaderUniform
{
    GLint AgeLoc;
    GLint UseGravityLoc;
    GLint GravityLoc;
    GLint EndSizeScaleLoc;
    GLint MvpMatrixLoc;
    GLint StartColorLoc;
    GLint EndColorLoc;
    GLint StartAlphaLoc;
    GLint EndAlphaLoc;
    GLint DiffuseTexLoc;
    GLint AlphaTexLoc;
}ParticleShaderUniform;
extern ParticleShaderUniform g_PSUniform;

//---------------------------------------------------------------------------------------------------------------
IGV5Err IGV5ParticleShader_ShaderInit(void);
IGV5Err IGV5ParticleShader_ShaderRelease(void);


#ifdef __cplusplus
}
#endif
#endif// IGV5_PARTICLESHADER_H

