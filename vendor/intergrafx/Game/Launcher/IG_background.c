// Copyright (c) 2004 InterGrafx, Inc. All Rights Reserved.

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

#include "IG_Launcher_FactorDef.h"

#if _240_320_ && _CHS_
#include "IG_backgroundQVGACHS.h"

#elif _240_320_ && _EN_
#include "IG_backgroundQVGAEN.h"

#elif _240_400_ && _CHS_
#include "IG_backgroundWQVGACHS.h"

#elif _240_400_ && _EN_
#include "IG_backgroundWQVGAEN.h"

#elif _320_480_ && _CHS_
#include "IG_backgroundHVGACHS.h"

#elif _320_480_ && _EN_
#include "IG_backgroundHVGAEN.h"

#elif _480_800_ && _CHS_
#include "IG_backgroundWVGACHS.h"

#elif _480_800_ && _EN_
#include "IG_backgroundWVGAEN.h"

#endif

#ifdef __cplusplus
}
#endif
