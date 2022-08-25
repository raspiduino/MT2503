/* vim:set sts=4 ts=4 noexpandtab: */
/*
 * This confidential and proprietary software may be used only as
 * authorised by a licensing agreement from ARM Limited
 * (C) COPYRIGHT 2009 ARM Limited
 * ALL RIGHTS RESERVED
 * The entire notice above must be reproduced on all authorised
 * copies and copies may only be made to the extent permitted
 * by a licensing agreement from ARM Limited.
 */

#ifndef __IGV5SHADER_H
#define __IGV5SHADER_H


#include <GLES2/gl2.h>

#include "IGV5Def.h"

#ifdef __cplusplus
extern "C" {
#endif

IGV5Err IGV5Shader_Create(GLuint *pShader, char *sShaderString, GLint iShaderType);
IGV5Err IGV5Shader_CreateWithBinary(GLuint *pShader, const void* shaderBinary, GLsizei binaryLength, GLenum binaryformat, GLint iShaderType);

IGV5Err IGV5Shader_CreateProgram(GLuint* pProgramObject,
								GLuint VertexShader,
								 GLuint FragmentShader,
								 char**  pszAttribs,
								int i32NumAttribs,
								char * pReturnError);
IGV5Err IGV5Shader_CreateFromMemEx( GLuint* pObject, char* pszShaderCode, GLenum Type, char* * aszDefineArray, GLuint uiDefArraySize);
IGV5Err IGV5Shader_CreateFromFileEx(GLuint* pObject, char* pszSrcFile, GLenum Type, char** aszDefineArray, GLuint uiDefArraySize);

struct IGV5ModelType;

typedef struct IGV5ShaderPluginType {

	GLuint m_uProgramID, m_uVertexShaderID, m_uFragmentShaderID;

	GLuint m_uNumLocs;
	GLuint m_uLocs[32];

	IGV5Err (*m_fnCreate)(struct IGV5ShaderPluginType *pSP, unsigned uNumDefines, char **ppDefines);
	void (*m_fnRelease)(struct IGV5ShaderPluginType *pSP);
	void (*m_fnSetLights)(struct IGV5ShaderPluginType *pSP, unsigned uNum, unsigned *pType, Vec4 *pLightColors, Vec3 *pLightDirs);

} IGV5ShaderPlugin;


#ifdef __cplusplus
}
#endif

#endif /* __IGV5SHADER_H */
