#include "McfPlatform.h"

#include "MAdpConfig.h"
#include "MAdpCfgRomData.h"

#ifdef WIN32
#define __align(x) 
#endif

//step 1:include source data
#if MCR_REGION_OVERSEA == __CFG_NO__
#if MCR_USE_ROM_LOADEDLAYER == __CFG_TMZ__
 #if defined(__TENCENTMCAREV31_ONLY_QQ2010__)
   #include "loadedlayer_tmz_QQ2010.c"
 #elif defined(__TENCENTMCAREV31_QQ2010_SINGLE_INST__)
   #include "loadedlayer_tmz_SINGLE_INST.c"
 #else
   #include "loadedlayer_tmz.c"
 #endif
#elif MCR_USE_ROM_LOADEDLAYER == __CFG_TMC__
 #if defined(__TENCENTMCAREV31_ONLY_QQ2010__)
   #include "loadedlayer_tmc_QQ2010.c"
 #elif defined(__TENCENTMCAREV31_QQ2010_SINGLE_INST__)
   #include "loadedlayer_tmc_SINGLE_INST.c"
 #else
   #include "loadedlayer_tmc.c"
 #endif
#endif

#if MCR_USE_ROM_QQB == __CFG_TMZ__
#include "qqb_tmz.c"
#elif MCR_USE_ROM_QQB == __CFG_TMC__
#include "qqb_tmc.c"
#endif

#if MCR_USE_ROM_QQ == __CFG_TMZ__
#include "qq_tmz.c"
#elif MCR_USE_ROM_QQ == __CFG_TMC__
#include "qq_tmc.c"
#endif

#else/*MCR_REGION_OVERSEA*/

#if MCR_USE_ROM_QQB == __CFG_TMZ__
#include "qqb_en_tmz.c"
#elif MCR_USE_ROM_QQB == __CFG_TMC__
#include "qqb_en_tmc.c"
#endif

#if MCR_USE_ROM_QQ == __CFG_TMZ__
#include "qq_en_tmz.c"
#elif MCR_USE_ROM_QQ == __CFG_TMC__
#include "qq_en_tmc.c"
#endif

#endif

//step 2:config rom app,resturct,appid-type-data-size-version,arlo
const SRomAppCfg gRomAppCfg[]=
{
#if MCR_REGION_OVERSEA == __CFG_NO__
 #if MCR_USE_ROM_LOADEDLAYER == __CFG_TMZ__
    {MCR_KERN_LAYER_APPID,ECONTENTTYPE_TMZ,(MBYTE*)loadedlayer_tmz,size_loadedlayer_tmz,ver_loadedlayer_tmz},
 #elif MCR_USE_ROM_LOADEDLAYER == __CFG_TMC__
    {MCR_KERN_LAYER_APPID,ECONTENTTYPE_TMC,(MBYTE*)loadedlayer_tmc,size_loadedlayer_tmc,ver_loadedlayer_tmc},
 #endif
#endif
#if MCR_USE_ROM_QQB == __CFG_TMZ__
    {10020000,ECONTENTTYPE_TMZ,(MBYTE*)qqb_tmz,size_qqb_tmz,ver_qqb_tmz},
#elif MCR_USE_ROM_QQB == __CFG_TMC__
    {10020000,ECONTENTTYPE_TMC,(MBYTE*)qqb_tmc,size_qqb_tmc,ver_qqb_tmc},
#endif 

#if MCR_USE_ROM_QQ == __CFG_TMZ__
    {10010000,ECONTENTTYPE_TMZ,(MBYTE*)qq_tmz,size_qq_tmz,ver_qq_tmz},
#elif MCR_USE_ROM_QQ == __CFG_TMC__
    {10010000,ECONTENTTYPE_TMC,(MBYTE*)qq_tmc,size_qq_tmc,ver_qq_tmc},
#endif
    {0,0,MNULL,0,MNULL}
};

const MUINT mCfgRomAppCnt = (sizeof(gRomAppCfg)/sizeof(SRomAppCfg)-1);

//other resource
#include "MAdpResData.c"



//////////////////////////////////////////////////////////////////////////
#if MCR_REGION_OVERSEA == __CFG_YES__
const SDefaultAppInfo gDefaultAppCfg[]  =
{
    {//QQ Browser
        APP_TYPE_NORMAL,
        10020000,
        {L"QQ Browser"},
        ""   
    },
/*
    {//Yahoo
        APP_TYPE_LINK,
        12260000,
        {L"Yahoo"},//
        "http://www.yahoo.com/"
    },
    
    {//Facebook
        APP_TYPE_LINK,
        12270000,
        {L"Facebook"},//
        "http://www.facebook.com/"
    },
    
    {//MSN
        APP_TYPE_LINK,
        12280000,
        {L"MSN"},//
        "http://www.msn.com/"
    },
*/
    
    {//Google
        APP_TYPE_LINK,
        12300000,
        {L"Google"},//
        "http://www.google.com/"
    },
	
	{//Twitter
        APP_TYPE_LINK,
        12290000,
        {L"Twitter"},//
        "http://www.twitter.com/"
    }

};

const MUINT mCfgDefAppCnt = (sizeof(gDefaultAppCfg)/sizeof(SDefaultAppInfo));
#else
const SDefaultAppInfo gDefaultAppCfg[]  =
{
    {0,0,L"",""}
};
const MUINT mCfgDefAppCnt = 0;

#endif
