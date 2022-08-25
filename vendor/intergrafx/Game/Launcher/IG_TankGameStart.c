// Copyright (c) 2004 InterGrafx, Inc. All Rights Reserved.

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

#include "IG_Launcher_FactorDef.h"

#if _240_320_ && _CHS_
#include "IG_TankGameStartQVGACHS.h"

#elif _240_320_ && _EN_
#include "IG_TankGameStartQVGAEN.h"

#elif _240_400_ && _CHS_
#include "IG_TankGameStartWQVGACHS.h"

#elif _240_400_ && _EN_
#include "IG_TankGameStartWQVGAEN.h"

#elif _320_480_ && _CHS_
#include "IG_TankGameStartHVGACHS.h"

#elif _320_480_ && _EN_
#include "IG_TankGameStartHVGAEN.h"

#elif _480_800_ && _CHS_
#include "IG_TankGameStartWVGACHS.h"

#elif _480_800_ && _EN_
#include "IG_TankGameStartWVGAEN.h"

#endif


#ifdef __cplusplus
}
#endif
