// Copyright (c) 2004 InterGrafx, Inc. All Rights Reserved.

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

#include "IG_Launcher_FactorDef.h"

#if _240_320_ && _CHS_
#include "IG_StartQVGACHS.h"

#elif _240_320_ && _EN_
#include "IG_StartQVGAEN.h"

#elif _240_400_ && _CHS_
#include "IG_StartWQVGACHS.h"

#elif _240_400_ && _EN_
#include "IG_StartWQVGAEN.h"

#elif _320_480_ && _CHS_
#include "IG_StartHVGACHS.h"

#elif _320_480_ && _EN_
#include "IG_StartHVGAEN.h"

#elif _480_800_ && _CHS_
#include "IG_StartWVGACHS.h"

#elif _480_800_ && _EN_
#include "IG_StartWVGAEN.h"

#endif


#ifdef __cplusplus
}
#endif
