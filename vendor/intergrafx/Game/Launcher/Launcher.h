#ifdef __cplusplus
extern "C" {
#endif
/**
File: Launcher.h
Author: Arvin luo
Creat date: 2011.1.4
*/


#ifndef _Launcher_H_
#define _Launcher_H_

#include "IGComDef.h" 
#include "IGMemoryPool.h"
#include "IGMathUtil.h"

#include "IGBackground.h"
#include "IGRenderer.h"
#include "IGTexture.h"

#include "IGGame.h"
#include "IGSprite.h"

#include "IG_Launcher_FactorDef.h"

#include "IG_LA_Utils.h"

#if _IG_TF_
#include "IG_TF.h"
#endif
#if _IG_DA_
#include "IG_DA.h"
#endif
#if _IG_FT_
#include "IG_FT.h"
#endif
#if _IG_BA_
#include "IG_BA.h"
#endif

// --------------------------------------------------------------------------------------
// Funciton declarations
// --------------------------------------------------------------------------------------
void IG_LA_onInit(void* dispBuff,int dispWidth,int dispHeight,int maskRed,int maskGreen,int maskBlue,int isTopDown);
void IG_LA_onUpdate(IGU32 uFrameInterval, unsigned uNumSysEvents, IGSysEvent *pSE);
void IG_LA_onEnd(void);
void IG_LA_deleteResourse(void);
void IG_LA_keyPressed(IGU32);
void IG_LA_keyReleased(IGU32);
void IG_LA_pointerPressed(IGU32,IGU32);
void IG_LA_pointerReleased(IGU32,IGU32);
void IG_LA_pointerDragged(IGU32,IGU32);
void IG_LA_drawImage(IGTexture *img,int x,int y);
void IG_LA_drawImageClip(IGTexture *img,int x,int y,int x1,int y1,int x2,int y2);
/**
	画退出时的确认提示
*/
void IG_LA_drawExitConfirm(igbool isPressedL,igbool isPressedR);
igbool IG_LA_isOnTouch(IGU32 x,IGU32 y,IGU32 x1,IGU32 y1,IGU32 x2,IGU32 y2);
IGTexture *IG_LA_init2DTexture(const char* charTex,const char* texName);

void copyArray(int array1[],int array2[]);



void IG_LA_OnPhoneCall_onInit(void* dispBuff,int dispWidth,int dispHeight,int maskRed,int maskGreen,int maskBlue,int isTopDown);
void IG_LA_OnPhoneCall_onUpdate(IGU32 uFrameInterval, unsigned uNumSysEvents, IGSysEvent *pSE);
void IG_LA_OnPhoneCall_onEnd(void);

#endif

#ifdef __cplusplus
}
#endif
