/**
File: GameFactorDef.h
Author: Wallace Wang
Creat date: 2010.01.19
*/

#include "MMI_features.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef   __GAME_FACTOR_DEF_H_ 
#define   __GAME_FACTOR_DEF_H_ 
// --------------------------------------------------------------------------------------
// Factor def
// --------------------------------------------------------------------------------------

//GAME DEFINE
#define _IS_CHEATING_ 0 //Cheat 
#define _IS_DEBUG_ 0    //Debug mode
#define _IS_MTK_EMU_ 1  //For MTK emulator

#define NEW_START_UP_MECHANISM  1 //started by launcher

//SCREEN SIZE DEFINE

#ifdef __MMI_MAINLCD_240X320__
#define _240_320_ 1 //240 * 320
#else
#define _240_320_ 0
#endif

#ifdef __MMI_MAINLCD_320X480__
#define _320_480_ 1 //320 * 480
#else
#define _320_480_ 0
#endif

#ifdef __MMI_MAINLCD_240X400__
#define _240_400_ 1
#else
#define _240_400_ 0 //240 * 400
#endif

#ifdef __MMI_MAINLCD_480X800__
#define _480_800_ 1 //480 * 800
#else
#define _480_800_ 0
#endif

//LANGUAGE DEFINE
//LANGUAGE DEFINE
#if (defined(INTERGRAFX_ENGINE_EN_BASIC) || defined(INTERGRAFX_ENGINE_EN_VALUED) || defined(INTERGRAFX_ENGINE_EN_FULL))
#define _EN_ 1
#else
#define _EN_ 0   //English
#endif

#if (defined(INTERGRAFX_ENGINE_CH_BASIC) || defined(INTERGRAFX_ENGINE_CH_VALUED) || defined(INTERGRAFX_ENGINE_CH_FULL))
#define _CHS_ 1  //Simplified Chinese
#else
#define _CHS_ 0
#endif


//select games which launched by launcher
#ifdef __MMI_3D_GAME_INTERGRAFX_TANK__
#define _IG_TF_ 1 //Tank launched by launcher
#else
#define _IG_TF_ 0
#endif

#ifdef __MMI_3D_GAME_INTERGRAFX_DANCING__
#define _IG_DA_ 1 //DancingAngle launched by launcher
#else
#define _IG_DA_ 0
#endif

#ifdef __MMI_3D_GAME_INTERGRAFX_TOWER__
#define _IG_FT_ 1 //FlowerTower launched by launcher
#else
#define _IG_FT_ 0
#endif

#ifdef __MMI_3D_GAME_INTERGRAFX_PINBALL__
#define _IG_BA_ 1 //BALLSTICK launched by launcher
#else
#define _IG_BA_ 0
#endif

#endif


#ifdef __cplusplus
}
#endif
