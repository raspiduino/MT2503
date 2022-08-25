// Copyright (c) 2004 InterGrafx, Inc. All Rights Reserved.

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

#include "IG_Launcher_FactorDef.h"

#if _240_320_ && _CHS_
#include "IG_ButtonQVGACHS.h"

#elif _240_320_ && _EN_
#include "IG_ButtonQVGAEN.h"

#elif _240_400_ && _CHS_
#include "IG_ButtonWQVGACHS.h"

#elif _240_400_ && _EN_
#include "IG_ButtonWQVGAEN.h"

#elif _320_480_ && _CHS_
#include "IG_ButtonHVGACHS.h"

#elif _320_480_ && _EN_
#include "IG_ButtonHVGAEN.h"

#elif _480_800_ && _CHS_
#include "IG_ButtonWVGACHS.h"

#elif _480_800_ && _EN_
#include "IG_ButtonWVGAEN.h"

#endif


#ifdef __cplusplus
}
#endif
