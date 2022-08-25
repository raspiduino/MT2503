/*--------------------------------------------------------------------*\
|   Copyright (c)2004 InterGrafx, Inc. All rights reserved.
\*--------------------------------------------------------------------*/
#ifndef IG_MATRIX_I_H
#define IG_MATRIX_I_H

#include "IGComDef.h"
//#include "IGMemoryPool.h"

#ifdef __cplusplus
extern "C"
{
#endif

void    IGMatrix_unit               ( igreal            oMat[ 12 ] );

void    IGMatrix_copy               ( igreal            oMat[ 12 ],
                                      const igreal      pMat[ 12 ] );

void    IGMatrix_fromAngleAxis      ( igreal            oMat[ 12 ], 
                                      const igreal      iAngleAxis[ 4 ] );

void    IGMatrix_fromQuaternion     ( igreal            oMat[ 12 ], 
                                      const igreal      iQuat[ 4 ] );

void    IGMatrix_fromScale          ( igreal            oMat[ 12 ], 
                                      const igreal      iScale[ 4 ] );

void    IGMatrix_fromTranslation    ( igreal            oMat[ 12 ], 
                                      const igreal      iVec[ 3 ] );

void    IGMatrix_fromVectors        ( igreal            oMat[ 12 ], 
                                      const igreal      iLookVec[ 3 ], 
                                      const igreal      iUpVec[ 3 ], 
                                      const igreal      iRightVec[ 3 ] );

void    IGMatrix_multiply           ( igreal            oMat[ 12 ], 
                                      const igreal      iMat1[ 12 ], 
                                      const igreal      iMat2[ 12 ] );

void    IGMatrix_invert             ( igreal            oMat[ 12 ], 
                                      const igreal      pMat[ 12 ] );

void    IGMatrix_removeScale        ( igreal            oMat[ 12 ], 
                                      const igreal      pMat[ 12 ] );

void    IGMatrix_transformPoint     ( igreal            pPosOut[ 3 ],
                                      const igreal      pMat[ 12 ], 
                                      const igreal      pPosIn[ 3 ] );

void    IGMatrix_transformVector    ( igreal            oMat[ 3 ], 
                                      const igreal      pMat[ 12 ], 
                                      const igreal      iVec[ 3 ] );

void    IGMatrix_transpose        ( igreal            oMat[ 12 ], 
                                      const igreal      pMat[ 12 ] );

#ifdef __cplusplus
}
#endif

#endif//IG_MATRIX_I_H

