#include "mmi_features.h"
#include "vmsys.h"
#include "vmswitch.h"

#if defined (__MMI_MRE_APP_WOCHACHA__)

#ifdef WIN32 

#define __align(x)
const __align(4) VMUINT8 mre_app_wochacha_vxp[] = {0x00};

#else

#if defined (__MMI_MAINLCD_240X320__)
#include "mre_app_wochacha_240X320_vxp.h"
#endif

#if defined (__MMI_MAINLCD_240X400__)
#include "mre_app_wochacha_240X400_vxp.h"
#endif

#if defined (__MMI_MAINLCD_320X480__)
#include "mre_app_wochacha_320X480_vxp.h"
#endif

#if defined (__MMI_MAINLCD_480X800__)
#include "mre_app_wochacha_480X800_vxp.h"
#endif

#endif /* WIN32 */

#endif /* __MMI_MRE_APP_WOCHACHA__ */

