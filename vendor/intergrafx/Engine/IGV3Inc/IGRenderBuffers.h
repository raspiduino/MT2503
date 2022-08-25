/*--------------------------------------------------------------------*\
|   Copyright (c)2004 InterGrafx, Inc. All rights reserved.
|   Last update: 2011-05-12 George Li
\*--------------------------------------------------------------------*/
#ifndef IG_RENDER_BUFFERS_H
#define IG_RENDER_BUFFERS_H

#include "IGTexture.h"

#ifdef __cplusplus
extern "C"
{
#endif

typedef struct 
{
    iguint32        m_width;
    iguint32        m_height;
    iguint32        m_size;
    igcolor*        m_framebuffer;
    igreal*         m_depthbuffer;
    igbool          m_invertY;
    igbool          m_isZBuffered;
    IGColorFormat   m_colorFormat;
	igbool          m_dir;
	igcolor*        m_auxBuffer;  //CY: This is not used at this time
	iguint32        scaleX;
	iguint32        scaleY; 
	IGRect          renderRect; 


}   IGRenderBuffers;

typedef struct {

    iguint32    m_uShaderID;

} IGV3Shader;

#ifdef __cplusplus
}
#endif

#endif//IG_RENDER_BUFFERS_H
