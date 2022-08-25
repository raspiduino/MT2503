/*--------------------------------------------------------------------*\
|   Copyright (c)2004 InterGrafx, Inc. All rights reserved.
\*--------------------------------------------------------------------*/
#ifndef IG_RASTERIZER_H
#define IG_RASTERIZER_H

#include "IGMesh.h"

#ifdef __cplusplus
extern "C"
{
#endif

//typedef struct IGRasterizer;

typedef struct 
{
    const IGMesh*   m_mesh;
	
	IGTexture*      m_texture;
    igreal          m_dudx;         // Change in u
    igreal          m_dvdx;         // Change in v
    int             m_scanHeight;    
    igreal          m_u;            // u at left end
    igreal          m_uStep;        // Change in u at left end
    igreal          m_v;            // v at left end
    igreal          m_vStep;        // Change in v at left end
    igint32         m_y;            // Current scanline
    igreal          m_xLeft;        // Left end
    igreal          m_xLeftStep;    // Change in left end
    igreal          m_xRight;       // Right end
    igreal          m_xRightStep;   // Change in right end
    igreal          m_zi;           // Inverse depth at left end
    igreal          m_ziStep;       // Change in inverse depth at left end

	IGTexture*      m_texture1;

    igreal          m_dudx1;
	igreal          m_dvdx1;

    igreal          m_u1;            // u at left end
    igreal          m_uStep1;        // Change in u at left end
    igreal          m_v1;            // v at left end
    igreal          m_vStep1;        // Change in v at left end

	int             m_botvert1;
    int             m_midvert1;
    int             m_topvert1;



	int             m_botvert;
    int             m_midvert;
    int             m_topvert;
    igbool          m_facesLeft;

    IGShadingMode   m_shading;
    IGBlendingMode  m_blending;
    igbool          m_textureOn;

    igcolor         m_color;
    igreal          m_transparency[ 3 ];
    igreal          m_opacity[ 3 ];

    igreal          m_dzidx;        // Change in inverse depth
    igreal          m_dlidx;        // Change in light intensity

    igreal          m_li[ 3 ];      // Light color and intensity
    igreal          m_liStep;       // Change in lighting at left end
	igreal          m_aux[ 3 ];
	igreal          m_p[ 3 ];

    
#if !defined(IG_NO_FUNCTION_PTR)    
    void ( *m_DrawTri ) ( IGMemoryPool*, IGRasterizer*, IGRenderBuffers* );
#else
    long m_drawTriIndex;
#endif
} IGRasterizer;

#ifdef __cplusplus
}
#endif

#endif//IG_RASTERIZER_I_H
