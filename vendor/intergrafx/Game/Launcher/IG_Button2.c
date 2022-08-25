// Copyright (c) 2004 InterGrafx, Inc. All Rights Reserved.

#ifdef __cplusplus
extern "C" {
#endif
#if 0
/* under construction !*/
#endif

#include "IG_Launcher_FactorDef.h"

#if _240_320_ && _CHS_
#include "IG_Button2QVGACHS.h"

#elif _240_320_ && _EN_
#include "IG_Button2QVGAEN.h"

#elif _240_400_ && _CHS_
#include "IG_Button2WQVGACHS.h"

#elif _240_400_ && _EN_
#include "IG_Button2WQVGAEN.h"

#elif _320_480_ && _CHS_
#include "IG_Button2HVGACHS.h"

#elif _320_480_ && _EN_
#include "IG_Button2HVGAEN.h"

#elif _480_800_ && _CHS_
#include "IG_Button2WVGACHS.h"

#elif _480_800_ && _EN_
#include "IG_Button2WVGAEN.h"

#endif


#ifdef __cplusplus
}
#endif
