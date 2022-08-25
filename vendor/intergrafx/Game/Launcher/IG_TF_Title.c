// Copyright (c) 2004 InterGrafx, Inc. All Rights Reserved.

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

#include "IG_Launcher_FactorDef.h"

#if _240_320_ && _CHS_
#include "IG_TF_TitleQVGACHS.h"

#elif _240_320_ && _EN_
#include "IG_TF_TitleQVGAEN.h"

#elif _240_400_ && _CHS_
#include "IG_TF_TitleWQVGACHS.h"

#elif _240_400_ && _EN_
#include "IG_TF_TitleWQVGAEN.h"

#elif _320_480_ && _CHS_
#include "IG_TF_TitleHVGACHS.h"

#elif _320_480_ && _EN_
#include "IG_TF_TitleHVGAEN.h"

#elif _480_800_ && _CHS_
#include "IG_TF_TitleWVGACHS.h"

#elif _480_800_ && _EN_
#include "IG_TF_TitleWVGAEN.h"

#endif


#ifdef __cplusplus
}
#endif
