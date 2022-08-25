// Copyright (c) 2004 InterGrafx, Inc. All Rights Reserved.

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

#include "IG_Launcher_FactorDef.h"

#if _240_320_ && _CHS_
#include "IG_FlowerGameStartQVGACHS.h"

#elif _240_320_ && _EN_
#include "IG_FlowerGameStartQVGAEN.h"

#elif _240_400_ && _CHS_
#include "IG_FlowerGameStartWQVGACHS.h"

#elif _240_400_ && _EN_
#include "IG_FlowerGameStartWQVGAEN.h"

#elif _320_480_ && _CHS_
#include "IG_FlowerGameStartHVGACHS.h"

#elif _320_480_ && _EN_
#include "IG_FlowerGameStartHVGAEN.h"

#elif _480_800_ && _CHS_
#include "IG_FlowerGameStartWVGACHS.h"

#elif _480_800_ && _EN_
#include "IG_FlowerGameStartWVGAEN.h"

#endif

#ifdef __cplusplus
}
#endif
