// Copyright (c) 2004 InterGrafx, Inc. All Rights Reserved.

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

#include "IG_Launcher_FactorDef.h"

#if _240_320_ && _CHS_
#include "IG_LA_boshaQVGACHS.h"

#elif _240_320_ && _EN_
#include "IG_LA_boshaQVGAEN.h"

#elif _240_400_ && _CHS_
#include "IG_LA_boshaWQVGACHS.h"

#elif _240_400_ && _EN_
#include "IG_LA_boshaWQVGAEN.h"

#elif _320_480_ && _CHS_
#include "IG_LA_boshaHVGACHS.h"

#elif _320_480_ && _EN_
#include "IG_LA_boshaHVGAEN.h"

#elif _480_800_ && _CHS_
#include "IG_LA_boshaWVGACHS.h"

#elif _480_800_ && _EN_
#include "IG_LA_boshaWVGAEN.h"

#endif


#ifdef __cplusplus
}
#endif
