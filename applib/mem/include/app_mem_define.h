#ifdef APP_MEM_HEADER_FILE
//must include header file here.
#include "App_mem.h"
#include "Med_mem.h"
#ifndef __MMI_SUPPORT_ASMV2__
#ifdef __MMI_BROWSER_2__
#include "BrowserConfig.h"
#endif
#endif
#endif //APP_MEM_HEADER_FILE


#ifndef APP_MEM_DEFINE
#define APP_MEM_DEFINE
//must add define here if have, or it may lead to redefine error. 
#define APP_EXAMPLE_SIZE 500
#define APP_EXAMPLE2_SIZE 1200
#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif
#define APP_MMSVIEWER_UMMS_SIZE APPLIB_MEM_CONC2_AP_POOL_SIZE(APPMEM_MMS_VIEWER_POOL_SIZE, APPMEM_UMMS_ASM_POOL_SIZE)
#define APP_MMSVIEWER_UMMS_SERVICE_SIZE APPLIB_MEM_CONC3_AP_POOL_SIZE(APPMEM_MMS_VIEWER_POOL_SIZE, APPMEM_UMMS_ASM_POOL_SIZE, APPMEM_MMS_SERVICE_POOL_SIZE)
#define APP_MMSVIEWER_SIZE APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_MMS_VIEWER_POOL_SIZE)
#define APP_MMSSERVICE_SIZE APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPMEM_MMS_SERVICE_POOL_SIZE)

#define APP_MMS_SIZE max(max(max(APP_MMSVIEWER_UMMS_SIZE, APP_MMSVIEWER_UMMS_SERVICE_SIZE), APP_MMSVIEWER_SIZE),APP_MMSSERVICE_SIZE) + MED_EXT_MEM_PLUTO_SIZE

#endif //APP_MEM_DEFINE


#ifdef APP_MEM_CONFIG
//example 1: config screen_base, app_use and med memory 
MEM_CONFIG_APP_ONLY(app_example,500)
MEM_CONFIG_MED_EXT(app_example, 500)
MEM_CONFIG_SCREEN_BASE(app_example, 500)

//example 2: config total usage size, which include screen_base, app_use and med memory, all in one.
MEM_CONFIG_APP_TOTAL(app_example2, 1200)
MEM_CONFIG_APP_TOTAL(MMS_APP, APP_MMS_SIZE)

#ifndef __MMI_SUPPORT_ASMV2__
#ifdef __MMI_BROWSER_2__
MEM_CONFIG_APP_TOTAL(APP_BROWSER, BROWSER_POOL_SIZE + 220000 + 20000)
/* 220000 for Menu CUI and 20000 for Image viewer CUI */
#endif
#endif

#endif //APP_MEM_CONFIG