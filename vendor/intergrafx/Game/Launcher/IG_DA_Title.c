// Copyright (c) 2004 InterGrafx, Inc. All Rights Reserved.

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

#include "IG_Launcher_FactorDef.h"

#if _240_320_ && _CHS_
#include "IG_DA_TitleQVGACHS.h"

#elif _240_320_ && _EN_
#include "IG_DA_TitleQVGAEN.h"

#elif _240_400_ && _CHS_
#include "IG_DA_TitleWQVGACHS.h"

#elif _240_400_ && _EN_
#include "IG_DA_TitleWQVGAEN.h"

#elif _320_480_ && _CHS_
#include "IG_DA_TitleHVGACHS.h"

#elif _320_480_ && _EN_
#include "IG_DA_TitleHVGAEN.h"

#elif _480_800_ && _CHS_
#include "IG_DA_TitleWVGACHS.h"

#elif _480_800_ && _EN_
#include "IG_DA_TitleWVGAEN.h"

#endif


#ifdef __cplusplus
}
#endif
