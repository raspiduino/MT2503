// Copyright (c) 2004 InterGrafx, Inc. All Rights Reserved.

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

#include "IG_Launcher_FactorDef.h"

#if _240_320_ && _CHS_
#include "IG_DanceGameStartQVGACHS.h"

#elif _240_320_ && _EN_
#include "IG_DanceGameStartQVGAEN.h"

#elif _240_400_ && _CHS_
#include "IG_DanceGameStartWQVGACHS.h"

#elif _240_400_ && _EN_
#include "IG_DanceGameStartWQVGAEN.h"

#elif _320_480_ && _CHS_
#include "IG_DanceGameStartHVGACHS.h"

#elif _320_480_ && _EN_
#include "IG_DanceGameStartHVGAEN.h"

#elif _480_800_ && _CHS_
#include "IG_DanceGameStartWVGACHS.h"

#elif _480_800_ && _EN_
#include "IG_DanceGameStartWVGAEN.h"

#endif


#ifdef __cplusplus
}
#endif
