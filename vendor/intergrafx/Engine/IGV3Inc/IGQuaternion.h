/*--------------------------------------------------------------------*\
|   Copyright (c)2004 InterGrafx, Inc. All rights reserved.
\*--------------------------------------------------------------------*/
#ifndef IG_QUATERNION_I_H
#define IG_QUATERNION_I_H

#include "IGComDef.h"
#include "IGMemoryPool.h"

#ifdef __cplusplus
extern "C"
{
#endif

void    IGQuaternion_i_copy             ( IGMemoryPool* pMemPool, 
                                          const igreal* iQuat, 
                                          igreal*       oQuat, 
                                          IGErr*        pErr );

void    IGQuaternion_i_divide           ( IGMemoryPool* pMemPool, 
                                          const igreal* iQuat1, 
                                          const igreal* iQuat2, 
                                          igreal*       oQuat, 
                                          IGErr*        pErr );

igreal  IGQuaternion_i_dot              ( IGMemoryPool* pMemPool, 
                                          const igreal* iQuat1, 
                                          const igreal* iQuat2, 
                                          IGErr*        pErr );

void    IGQuaternion_fromAngleAxis      ( igreal*       oQuat, 
                                          const igreal* iAnAx );

void    IGQuaternion_i_inverse          ( IGMemoryPool* pMemPool, 
                                          const igreal* iQuat, 
                                          igreal*       oQuat, 
                                          IGErr*        pErr );

igreal  IGQuaternion_i_magnitude        ( IGMemoryPool* pMemPool, 
                                          const igreal* iQuat, 
                                          IGErr*        pErr );

void    IGQuaternion_i_multiply         ( IGMemoryPool* pMemPool, 
                                          const igreal* iQuat1, 
                                          const igreal* iQuat2, 
                                          igreal*       oQuat, 
                                          IGErr*        pErr );

void    IGQuaternion_i_normalize        ( IGMemoryPool* pMemPool, 
                                          const igreal* iQuat, 
                                          igreal*       oQuat, 
                                          IGErr*        pErr );

void    IGQuaternion_i_power            ( IGMemoryPool* pMemPool, 
                                          const igreal* iQuat, 
                                          igreal        iPow, 
                                          igreal*       oQuat, 
                                          IGErr*        pErr );

void    IGQuaternion_i_slerp            ( IGMemoryPool* pMemPool, 
                                          const igreal* iQuat1, 
                                          const igreal* iQuat2, 
                                          igreal        iWeight, 
                                          igreal*       oQuat, 
                                          IGErr*        pErr );

void    IGQuaternion_i_toAngleAxis      ( IGMemoryPool* pMemPool, 
                                          const igreal* iQuat, 
                                          igreal*       oAnAx, 
                                          IGErr*        pErr );

#ifdef __cplusplus
}
#endif

#endif//IG_QUATERNION_I_H
