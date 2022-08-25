/*--------------------------------------------------------------------*\
|   Copyright (c)2004 InterGrafx, Inc. All rights reserved.
\*--------------------------------------------------------------------*/
#ifndef IG_VECTOR_H
#define IG_VECTOR_H

#include "IGComDef.h"


#ifdef __cplusplus
extern "C"
{
#endif

/*--------------------------------------------------------------------*\
|   IGVector private interface
\*--------------------------------------------------------------------*/
void    IGVector_copy               ( igreal        pVecOut[ 3 ],
                                      const igreal  pVecIn[ 3 ] );

void    IGVector_setZero            ( igreal        oVec[ 3 ] );

void    IGVector_negate             ( igreal        oVec[ 3 ], 
                                      const igreal  iVec[ 3 ]  );

void    IGVector_add                ( igreal        oVec[ 3 ], 
                                      const igreal  iVec1[ 3 ], 
                                      const igreal  iVec2[ 3 ] );

#define __IGVector_subtract( oVec, iVec1, iVec2 ) \
{ \
	oVec[ 0 ] = iVec1[ 0 ] - iVec2[ 0 ]; \
	oVec[ 1 ] = iVec1[ 1 ] - iVec2[ 1 ]; \
	oVec[ 2 ] = iVec1[ 2 ] - iVec2[ 2 ]; \
}

void    IGVector_subtract           ( igreal        oVec[ 3 ], 
                                      const igreal  iVec1[ 3 ], 
                                      const igreal  iVec2[ 3 ] );

igreal  IGVector_dot                ( const igreal  iVec1[ 3 ], 
                                      const igreal  iVec2[ 3 ] );

void    IGVector_cross              ( igreal        oVec[ 3 ], 
                                      const igreal  iVec1[ 3 ], 
                                      const igreal  iVec2[ 3 ] );

void    IGVector_normalize          ( igreal        oVec[ 3 ],
                                      const igreal  iVec[ 3 ] );

void    IGVector_normalizeBegin     ( igreal        oVec[ 3 ], 
                                      const igreal  iVec[ 3 ] );

void    IGVector_normalizeEnd       ( igreal        oVec[ 3 ], 
                                      const igreal  iVec[ 3 ] );

void    IGVector_interpolate        ( igreal        oVec[ 3 ], 
                                      const igreal  iVec1[ 3 ], 
                                      const igreal  iVec2[ 3 ], 
                                      const igreal  iWeight );

igreal  IGVector_magnitude          ( const igreal  iVec[ 3 ] );


igbool  IGVector_equal              (const igreal iVec[3],const igreal iVec1[3]); 


void   IGVector_multiply           (igreal iVec[3],igreal  scale);  

void	IGVector_reflect(igreal out[3], igreal in[3], igreal normal[3]);

igreal IGVector_length(igreal v[3]);
igreal IGVector_lengthSquare(igreal v[3]);

#ifdef __cplusplus
}
#endif

#endif //IG_VECTOR_H
