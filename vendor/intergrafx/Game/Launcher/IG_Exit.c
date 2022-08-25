// Copyright (c) 2004 InterGrafx, Inc. All Rights Reserved.

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

#include "IG_Launcher_FactorDef.h"

#if _240_320_ && _CHS_
#include "IG_ExitQVGACHS.h"

#elif _240_320_ && _EN_
#include "IG_ExitQVGAEN.h"

#elif _240_400_ && _CHS_
#include "IG_ExitWQVGACHS.h"

#elif _240_400_ && _EN_
#include "IG_ExitWQVGAEN.h"

#elif _320_480_ && _CHS_
#include "IG_ExitHVGACHS.h"

#elif _320_480_ && _EN_
#include "IG_ExitHVGAEN.h"

#elif _480_800_ && _CHS_
#include "IG_ExitWVGACHS.h"

#elif _480_800_ && _EN_
#include "IG_ExitWVGAEN.h"

#endif


#ifdef __cplusplus
}
#endif
