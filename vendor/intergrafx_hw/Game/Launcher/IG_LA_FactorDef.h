/**
File: GameFactorDef.h
Author: Wallace Wang @Intergrafx
Creat date: 2010.10.27
*/

#ifndef   __IG_LA_FACTOR_DEF_H_
#define   __IG_LA_FACTOR_DEF_H_



#ifdef __cplusplus
extern "C" {
#endif



	// --------------------------------------------------------------------------------------
	// Factor def
	// --------------------------------------------------------------------------------------
#include "IGV5Def.h"
	//GAME DEFINE
#define _IS_CHEAT_ 0 //Cheat
#define _IS_DEBUG_ 0    //Debug mode


#define NEW_START_UP_MECHANISM  1 //started by launcher

	//SCREEN SIZE DEFINE

#ifdef __MMI_MAINLCD_240X320__
#define _240_320_ 1 //240 * 320
#else
#define _240_320_ 0
#endif
#ifdef __MMI_MAINLCD_240X400__
#define _240_400_ 1
#else
#define _240_400_ 0 //240 * 400
#endif
#ifdef __MMI_MAINLCD_320X480__
#define _320_480_ 1 //320 * 480
#else
#define _320_480_ 0
#endif
#ifdef __MMI_MAINLCD_480X800__
#define _480_800_ 1 //480 * 800
#else
#define _480_800_ 0
#endif

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

//select games which launched by launcher
#ifdef __MMI_3D_GAME_INTERGRAFX_TANKFANTASY__
#define _IG_TK_ 1 //Tank launched by launcher
#else
#define _IG_TK_ 0
#endif

#ifdef __MMI_3D_GAME_INTERGRAFX_DANCING__
#define _IG_DA5_ 1 //DancingAngle launched by launcher
#else
#define _IG_DA5_ 0
#endif

#ifdef __MMI_3D_GAME_INTERGRAFX_JUMPEMPEROR__
#define _IG_JE_ 1 
#else
#define _IG_JE_ 0
#endif

#ifdef __MMI_3D_GAME_INTERGRAFX_CUBEWORLD__
#define _IG_CW_ 1 //BALLSTICK launched by launcher
#else
#define _IG_CW_ 0
#endif

#define _LA_DEBUG_ 0

#ifdef __cplusplus
}
#endif

#endif
