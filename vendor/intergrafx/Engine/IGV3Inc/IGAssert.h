/**
@file IGAssert.h 
@brief 

@par Last updated:


@par Copyright (c) 2005-2011 InterGrafx, Inc. All rights reserved.
InterGrafx CONFIDENTIAL AND PROPRIETARY
@par
This source is the sole property of InterGrafx Inc. Reproduction or
Utilization of this source in whole or in part is forbidden without
The written consent of InterGrafx Inc.

@par History:


@par Description:
more description here.
*/
#ifndef IG_ASSERT_H
#define IG_ASSERT_H

#ifdef __cplusplus
extern "C"
{
#endif // __cpluasplus


//----------------------------------------------------------------------------

#if defined(IG_DEBUG) && defined(IGP_WIN32)
// Win32 development
#	include <assert.h>
#	define igAssert(x)				assert( x )
#else
#	define igAssert(x)
#endif

//CY: no one use it
//#if defined(_DEBUG) && defined(WIN32)
//#	define igAssertMsg(x, msg)		assert( x && msg )
//#else
//#	define igAssertMsg(x, msg)
//#endif

//CY: No one use it
//#if defined(_DEBUG) && defined(WIN32)
//#	define igAlert(msg)				assert( false && msg )
//#else
//#	define igAlert(msg)
//#endif


#ifdef __cplusplus
}
#endif // __cpluasplus

#endif // IG_ASSERT_H