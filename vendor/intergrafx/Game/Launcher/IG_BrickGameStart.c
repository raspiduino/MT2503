// Copyright (c) 2004 InterGrafx, Inc. All Rights Reserved.

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

#include "IG_Launcher_FactorDef.h"

#if _240_320_ && _CHS_
#include "IG_BrickGameStartQVGACHS.h"

#elif _240_320_ && _EN_
#include "IG_BrickGameStartQVGAEN.h"

#elif _240_400_ && _CHS_
#include "IG_BrickGameStartWQVGACHS.h"

#elif _240_400_ && _EN_
#include "IG_BrickGameStartWQVGAEN.h"

#elif _320_480_ && _CHS_
#include "IG_BrickGameStartHVGACHS.h"

#elif _320_480_ && _EN_
#include "IG_BrickGameStartHVGAEN.h"

#elif _480_800_ && _CHS_
#include "IG_BrickGameStartWVGACHS.h"

#elif _480_800_ && _EN_
#include "IG_BrickGameStartWVGAEN.h"

#endif


#ifdef __cplusplus
}
#endif
