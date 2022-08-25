// Copyright: Copyright (c) 2004 InterGrafx, Inc. All Rights Reserved.
//   Updated Sep 08, 2010 CY

#ifdef __cplusplus
extern "C" {
#endif

// --------------------------------------------------------------------------------------
// Headers
// --------------------------------------------------------------------------------------

#include "Launcher.h"

// --------------------------------------------------------------------------------------
// Global variables
// --------------------------------------------------------------------------------------
static int Launcher_Width,Launcher_Height;
static void *Launcher_dispBuff;

static int Launcher_IsTopDown; 
static IGMemoryPool  gs_mem;
static IGErr		err;
static IGRenderer  *gs_render;

static IGTexture *texStart,*texExit,*texButton,*texButton1,*texButton2,*texButton3,*texBG,*texBosha,
*texBG2,*texCh1,*texCh2,*texCh3,*texGame[4],*texTitle[4] ,*texST02,*texCh4,*texCh5;

static int scrW = 0;   //width of the screen
static int scrH = 0;   //height of the screen
static int anchorX = 0;//coordinate of anchor
static int anchorY = 0;//coordinate of anchor

static const long Launcher_KEY_COLOR_2D = 0x00ff00ff;

static IGPoint *texPoint;
static IGRect *texRect;

typedef enum{
	Launcher,
	IG_TF,
	IG_DA,
	IG_Flower,
	IG_Brick,
	IG_OnPhoneCall
}IG_LA_STATUS;

static IG_LA_STATUS status = Launcher;

igcolor Launcher_GlobalMaskR;
igcolor Launcher_GlobalMaskG;
igcolor Launcher_GlobalMaskB;

extern unsigned char const IG_BrickGameStart[];
extern unsigned char const IG_DanceGameStart[];
extern unsigned char const IG_FlowerGameStart[];
extern unsigned char const IG_TankGameStart[];
extern unsigned char const IG_Button[];
extern unsigned char const IG_Button1[];
extern unsigned char const IG_Button2[];
extern unsigned char const IG_Button3[];
extern unsigned char const IG_Start[];
extern unsigned char const IG_Exit[];
extern unsigned char const IG_TF_Title[];
extern unsigned char const IG_DA_Title[];
extern unsigned char const IG_Flower_Title[];
extern unsigned char const IG_Brick_Title[];
extern unsigned char const IG_background[];
extern unsigned char const IG_LA_backgroung_02[];
extern unsigned char const IG_LA_ch_01[];
extern unsigned char const IG_LA_ch_02[];
extern unsigned char const IG_LA_ch_03[];
extern unsigned char const IG_LA_bosha[];
extern unsigned char const IG_LA_ST_02[];
extern unsigned char const IG_LA_ch_04[];
extern unsigned char const IG_LA_ch_05[];

#if _240_320_ && _EN_
static int const LAUNCHER_START_OFFX = -60;
static int const LAUNCHER_START_OFFY = 131;
static int const LAUNCHER_EXIT_OFFX = 60;
static int const LAUNCHER_EXIT_OFFY = 131;

static int const LAUNCHER_CENTRE_OFFX = 0;
static int const LAUNCHER_RIGHT_OFFX = 180;
static int const LAUNCHER_LEFT_OFFX = -40;
static int const LAUNCHER_GAMELOGO_OFFY = 0;

static int const LAUNCHER_TITLE_OFFX = 0;
static int const LAUNCHER_TITLE_OFFY = -120;

static int const LAUNCHER_GAMELOGO_WIDTH = 160;
static int const LAUNCHER_GAMELOGO_HEIGHT = 200;
static int const LAUNCHER_SIDE_WIDHT = 20;

static int const LAUNCHER_GAME_INTERVALX = 20;

static int const IG_LA_OPC_EXIT_OFFY = 40;
static int const IG_LA_OPC_TEXT_OFFY = -30;

#if _IG_TF_ && _IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220,-320,-140};
static int Launcher_Position_bak[] = {40,220,-320,-140};
#elif _IG_TF_ && _IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40,220,-140};
static int Launcher_Position_bak[] = {40,220,-140};
#elif _IG_TF_ && _IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220,-140};
static int Launcher_Position_bak[] = {40,220,-140};
#elif _IG_TF_ && !_IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220,-140};
static int Launcher_Position_bak[] = {40,220,-140};
#elif !_IG_TF_ && _IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220,-140};
static int Launcher_Position_bak[] = {40,220,-140};
#elif !_IG_TF_ && !_IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif !_IG_TF_ && _IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif !_IG_TF_ && _IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif _IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif _IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif _IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif _IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40};
static int Launcher_Position_bak[] = {40};
#elif !_IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40};
static int Launcher_Position_bak[] = {40};
#elif !_IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40};
static int Launcher_Position_bak[] = {40};
#elif !_IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40};
static int Launcher_Position_bak[] = {40};
#endif

static int const LAUNCHER_BG2_OFFX = 0;
static int const LAUNCHER_BG2_OFFY = 0;
static int const LAUNCHER_CH1_OFFX = 0;
static int const LAUNCHER_CH1_OFFY = -50;
static int const Launcher_BUTTON_OFFX = 55;
static int const Launcher_BUTTON_OFFY = 50;
static int const Launcher_WORD_OFFX = 55;
static int const Launcher_WORD_OFFY = 50;

#elif _240_320_ && _CHS_
static int const LAUNCHER_START_OFFX = -60;
static int const LAUNCHER_START_OFFY = 131;
static int const LAUNCHER_EXIT_OFFX = 60;
static int const LAUNCHER_EXIT_OFFY = 131;

static int const LAUNCHER_CENTRE_OFFX = 0;
static int const LAUNCHER_RIGHT_OFFX = 180;
static int const LAUNCHER_LEFT_OFFX = -40;
static int const LAUNCHER_GAMELOGO_OFFY = 0;

static int const LAUNCHER_TITLE_OFFX = 0;
static int const LAUNCHER_TITLE_OFFY = -122;

static int const LAUNCHER_GAMELOGO_WIDTH = 160;
static int const LAUNCHER_GAMELOGO_HEIGHT = 200;
static int const LAUNCHER_SIDE_WIDHT = 20;

static int const LAUNCHER_GAME_INTERVALX = 20;

static int const IG_LA_OPC_EXIT_OFFY = 40;
static int const IG_LA_OPC_TEXT_OFFY = -30;

#if _IG_TF_ && _IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220,-320,-140};
static int Launcher_Position_bak[] = {40,220,-320,-140};
#elif _IG_TF_ && _IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40,220,-140};
static int Launcher_Position_bak[] = {40,220,-140};
#elif _IG_TF_ && _IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220,-140};
static int Launcher_Position_bak[] = {40,220,-140};
#elif _IG_TF_ && !_IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220,-140};
static int Launcher_Position_bak[] = {40,220,-140};
#elif !_IG_TF_ && _IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220,-140};
static int Launcher_Position_bak[] = {40,220,-140};
#elif !_IG_TF_ && !_IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif !_IG_TF_ && _IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif !_IG_TF_ && _IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif _IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif _IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif _IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif _IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40};
static int Launcher_Position_bak[] = {40};
#elif !_IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40};
static int Launcher_Position_bak[] = {40};
#elif !_IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40};
static int Launcher_Position_bak[] = {40};
#elif !_IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40};
static int Launcher_Position_bak[] = {40};
#endif

static int const LAUNCHER_BG2_OFFX = 0;
static int const LAUNCHER_BG2_OFFY = 0;
static int const LAUNCHER_CH1_OFFX = 0;
static int const LAUNCHER_CH1_OFFY = -50;
static int const Launcher_BUTTON_OFFX = 55;
static int const Launcher_BUTTON_OFFY = 50;
static int const Launcher_WORD_OFFX = 55;
static int const Launcher_WORD_OFFY = 50;

#elif _320_480_ && _EN_
static int const LAUNCHER_START_OFFX = -80;
static int const LAUNCHER_START_OFFY = 200;
static int const LAUNCHER_EXIT_OFFX = 80;
static int const LAUNCHER_EXIT_OFFY = 200;

static int const LAUNCHER_CENTRE_OFFX = 0;
static int const LAUNCHER_RIGHT_OFFX = 180;
static int const LAUNCHER_LEFT_OFFX = -80;
static int const LAUNCHER_GAMELOGO_OFFY = -30;

static int const LAUNCHER_TITLE_OFFX = 0;
static int const LAUNCHER_TITLE_OFFY = -155;

static int const LAUNCHER_GAMELOGO_WIDTH = 160;
static int const LAUNCHER_GAMELOGO_HEIGHT = 200;
static int const LAUNCHER_SIDE_WIDHT = 60;

static int const LAUNCHER_GAME_INTERVALX = 20;

static int const IG_LA_OPC_EXIT_OFFY = 50;
static int const IG_LA_OPC_TEXT_OFFY = -20;

#if _IG_TF_ && _IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,260,-280,-100};
static int Launcher_Position_bak[] = {80,260,-280,-100};
#elif _IG_TF_ && _IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80,260,-100};
static int Launcher_Position_bak[] = {80,260,-100};
#elif _IG_TF_ && _IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,260,-100};
static int Launcher_Position_bak[] = {80,260,-100};
#elif _IG_TF_ && !_IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,260,-100};
static int Launcher_Position_bak[] = {80,260,-100};
#elif !_IG_TF_ && _IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,260,-100};
static int Launcher_Position_bak[] = {80,260,-100};
#elif !_IG_TF_ && !_IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,260};
static int Launcher_Position_bak[] = {80,260};
#elif !_IG_TF_ && _IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,260};
static int Launcher_Position_bak[] = {80,260};
#elif !_IG_TF_ && _IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80,260};
static int Launcher_Position_bak[] = {80,260};
#elif _IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,260};
static int Launcher_Position_bak[] = {80,260};
#elif _IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80,260};
static int Launcher_Position_bak[] = {80,260};
#elif _IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80,260};
static int Launcher_Position_bak[] = {80,260};
#elif _IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80};
static int Launcher_Position_bak[] = {80};
#elif !_IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80};
static int Launcher_Position_bak[] = {80};
#elif !_IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80};
static int Launcher_Position_bak[] = {80};
#elif !_IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80};
static int Launcher_Position_bak[] = {80};
#endif

static int const LAUNCHER_BG2_OFFX = 0;
static int const LAUNCHER_BG2_OFFY = -30;
static int const LAUNCHER_CH1_OFFX = 0;
static int const LAUNCHER_CH1_OFFY = -80;
static int const Launcher_BUTTON_OFFX = 70;
static int const Launcher_BUTTON_OFFY = 20;
static int const Launcher_WORD_OFFX = 70;
static int const Launcher_WORD_OFFY = 20;

#elif _320_480_ && _CHS_
static int const LAUNCHER_START_OFFX = -80;
static int const LAUNCHER_START_OFFY = 200;
static int const LAUNCHER_EXIT_OFFX = 80;
static int const LAUNCHER_EXIT_OFFY = 200;

static int const LAUNCHER_CENTRE_OFFX = 0;
static int const LAUNCHER_RIGHT_OFFX = 180;
static int const LAUNCHER_LEFT_OFFX = -80;
static int const LAUNCHER_GAMELOGO_OFFY = -30;

static int const LAUNCHER_TITLE_OFFX = 0;
static int const LAUNCHER_TITLE_OFFY = -155;

static int const LAUNCHER_GAMELOGO_WIDTH = 160;
static int const LAUNCHER_GAMELOGO_HEIGHT = 200;
static int const LAUNCHER_SIDE_WIDHT = 60;

static int const LAUNCHER_GAME_INTERVALX = 20;

static int const IG_LA_OPC_EXIT_OFFY = 50;
static int const IG_LA_OPC_TEXT_OFFY = -20;

#if _IG_TF_ && _IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,260,-280,-100};
static int Launcher_Position_bak[] = {80,260,-280,-100};
#elif _IG_TF_ && _IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80,260,-100};
static int Launcher_Position_bak[] = {80,260,-100};
#elif _IG_TF_ && _IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,260,-100};
static int Launcher_Position_bak[] = {80,260,-100};
#elif _IG_TF_ && !_IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,260,-100};
static int Launcher_Position_bak[] = {80,260,-100};
#elif !_IG_TF_ && _IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,260,-100};
static int Launcher_Position_bak[] = {80,260,-100};
#elif !_IG_TF_ && !_IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,260};
static int Launcher_Position_bak[] = {80,260};
#elif !_IG_TF_ && _IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,260};
static int Launcher_Position_bak[] = {80,260};
#elif !_IG_TF_ && _IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80,260};
static int Launcher_Position_bak[] = {80,260};
#elif _IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,260};
static int Launcher_Position_bak[] = {80,260};
#elif _IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80,260};
static int Launcher_Position_bak[] = {80,260};
#elif _IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80,260};
static int Launcher_Position_bak[] = {80,260};
#elif _IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80};
static int Launcher_Position_bak[] = {80};
#elif !_IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80};
static int Launcher_Position_bak[] = {80};
#elif !_IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80};
static int Launcher_Position_bak[] = {80};
#elif !_IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80};
static int Launcher_Position_bak[] = {80};
#endif

static int const LAUNCHER_BG2_OFFX = 0;
static int const LAUNCHER_BG2_OFFY = -30;
static int const LAUNCHER_CH1_OFFX = 0;
static int const LAUNCHER_CH1_OFFY = -80;
static int const Launcher_BUTTON_OFFX = 70;
static int const Launcher_BUTTON_OFFY = 20;
static int const Launcher_WORD_OFFX = 70;
static int const Launcher_WORD_OFFY = 20;

#elif _240_400_ && _EN_
static int const LAUNCHER_START_OFFX = -60;
static int const LAUNCHER_START_OFFY = 160;
static int const LAUNCHER_EXIT_OFFX = 60;
static int const LAUNCHER_EXIT_OFFY = 160;

static int const LAUNCHER_CENTRE_OFFX = 0;
static int const LAUNCHER_RIGHT_OFFX = 180;
static int const LAUNCHER_LEFT_OFFX = -40;
static int const LAUNCHER_GAMELOGO_OFFY = 0;

static int const LAUNCHER_TITLE_OFFX = 0;
static int const LAUNCHER_TITLE_OFFY = -118;

static int const LAUNCHER_GAMELOGO_WIDTH = 160;
static int const LAUNCHER_GAMELOGO_HEIGHT = 200;
static int const LAUNCHER_SIDE_WIDHT = 20;

static int const LAUNCHER_GAME_INTERVALX = 20;

static int const IG_LA_OPC_EXIT_OFFY = 40;
static int const IG_LA_OPC_TEXT_OFFY = -30;

#if _IG_TF_ && _IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220,-320,-140};
static int Launcher_Position_bak[] = {40,220,-320,-140};
#elif _IG_TF_ && _IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40,220,-140};
static int Launcher_Position_bak[] = {40,220,-140};
#elif _IG_TF_ && _IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220,-140};
static int Launcher_Position_bak[] = {40,220,-140};
#elif _IG_TF_ && !_IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220,-140};
static int Launcher_Position_bak[] = {40,220,-140};
#elif !_IG_TF_ && _IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220,-140};
static int Launcher_Position_bak[] = {40,220,-140};
#elif !_IG_TF_ && !_IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif !_IG_TF_ && _IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif !_IG_TF_ && _IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif _IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif _IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif _IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif _IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40};
static int Launcher_Position_bak[] = {40};
#elif !_IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40};
static int Launcher_Position_bak[] = {40};
#elif !_IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40};
static int Launcher_Position_bak[] = {40};
#elif !_IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40};
static int Launcher_Position_bak[] = {40};
#endif


static int const LAUNCHER_BG2_OFFX = 0;
static int const LAUNCHER_BG2_OFFY = 0;
static int const LAUNCHER_CH1_OFFX = 0;
static int const LAUNCHER_CH1_OFFY = -50;
static int const Launcher_BUTTON_OFFX = 55;
static int const Launcher_BUTTON_OFFY = 50;
static int const Launcher_WORD_OFFX = 55;
static int const Launcher_WORD_OFFY = 50;

#elif _240_400_ && _CHS_
static int const LAUNCHER_START_OFFX = -60;
static int const LAUNCHER_START_OFFY = 160;
static int const LAUNCHER_EXIT_OFFX = 60;
static int const LAUNCHER_EXIT_OFFY = 160;

static int const LAUNCHER_CENTRE_OFFX = 0;
static int const LAUNCHER_RIGHT_OFFX = 180;
static int const LAUNCHER_LEFT_OFFX = -40;
static int const LAUNCHER_GAMELOGO_OFFY = 0;

static int const LAUNCHER_TITLE_OFFX = 0;
static int const LAUNCHER_TITLE_OFFY = -120;

static int const LAUNCHER_GAMELOGO_WIDTH = 160;
static int const LAUNCHER_GAMELOGO_HEIGHT = 200;
static int const LAUNCHER_SIDE_WIDHT = 20;

static int const LAUNCHER_GAME_INTERVALX = 20;

static int const IG_LA_OPC_EXIT_OFFY = 40;
static int const IG_LA_OPC_TEXT_OFFY = -30;

#if _IG_TF_ && _IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220,-320,-140};
static int Launcher_Position_bak[] = {40,220,-320,-140};
#elif _IG_TF_ && _IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40,220,-140};
static int Launcher_Position_bak[] = {40,220,-140};
#elif _IG_TF_ && _IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220,-140};
static int Launcher_Position_bak[] = {40,220,-140};
#elif _IG_TF_ && !_IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220,-140};
static int Launcher_Position_bak[] = {40,220,-140};
#elif !_IG_TF_ && _IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220,-140};
static int Launcher_Position_bak[] = {40,220,-140};
#elif !_IG_TF_ && !_IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif !_IG_TF_ && _IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif !_IG_TF_ && _IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif _IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif _IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif _IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40,220};
static int Launcher_Position_bak[] = {40,220};
#elif _IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40};
static int Launcher_Position_bak[] = {40};
#elif !_IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40};
static int Launcher_Position_bak[] = {40};
#elif !_IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {40};
static int Launcher_Position_bak[] = {40};
#elif !_IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {40};
static int Launcher_Position_bak[] = {40};
#endif


static int const LAUNCHER_BG2_OFFX = 0;
static int const LAUNCHER_BG2_OFFY = 0;
static int const LAUNCHER_CH1_OFFX = 0;
static int const LAUNCHER_CH1_OFFY = -50;
static int const Launcher_BUTTON_OFFX = 55;
static int const Launcher_BUTTON_OFFY = 50;
static int const Launcher_WORD_OFFX = 55;
static int const Launcher_WORD_OFFY = 50;

#elif _480_800_ && _EN_
static int const LAUNCHER_START_OFFX = -140;
static int const LAUNCHER_START_OFFY = 363;
static int const LAUNCHER_EXIT_OFFX = 140;
static int const LAUNCHER_EXIT_OFFY = 363;

static int const LAUNCHER_CENTRE_OFFX = 0;
static int const LAUNCHER_RIGHT_OFFX = 360;
static int const LAUNCHER_LEFT_OFFX = -80;
static int const LAUNCHER_GAMELOGO_OFFY = 0;

static int const LAUNCHER_TITLE_OFFX = 0;
static int const LAUNCHER_TITLE_OFFY = -316;

static int const LAUNCHER_GAMELOGO_WIDTH = 320;
static int const LAUNCHER_GAMELOGO_HEIGHT = 535;
static int const LAUNCHER_SIDE_WIDHT = 40;

static int const LAUNCHER_GAME_INTERVALX = 40;

static int const IG_LA_OPC_EXIT_OFFY = 70;
static int const IG_LA_OPC_TEXT_OFFY = -50;

#if _IG_TF_ && _IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,440,-640,-280};
static int Launcher_Position_bak[] = {80,440,-640,-280};
#elif _IG_TF_ && _IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80,440,-280};
static int Launcher_Position_bak[] = {80,440,-280};
#elif _IG_TF_ && _IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,440,-280};
static int Launcher_Position_bak[] = {80,440,-280};
#elif _IG_TF_ && !_IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,440,-280};
static int Launcher_Position_bak[] = {80,440,-280};
#elif !_IG_TF_ && _IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,440,-280};
static int Launcher_Position_bak[] = {80,440,-280};
#elif !_IG_TF_ && !_IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,440};
static int Launcher_Position_bak[] = {80,440};
#elif !_IG_TF_ && _IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,440};
static int Launcher_Position_bak[] = {80,440};
#elif !_IG_TF_ && _IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80,440};
static int Launcher_Position_bak[] = {80,440};
#elif _IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,440};
static int Launcher_Position_bak[] = {80,440};
#elif _IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80,440};
static int Launcher_Position_bak[] = {80,440};
#elif _IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80,440};
static int Launcher_Position_bak[] = {80,440};
#elif _IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80};
static int Launcher_Position_bak[] = {80};
#elif !_IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80};
static int Launcher_Position_bak[] = {80};
#elif !_IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80};
static int Launcher_Position_bak[] = {80};
#elif !_IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80};
static int Launcher_Position_bak[] = {80};
#endif

static int const LAUNCHER_BG2_OFFX = 0;
static int const LAUNCHER_BG2_OFFY = 0;
static int const LAUNCHER_CH1_OFFX = 0;
static int const LAUNCHER_CH1_OFFY = -50;
static int const Launcher_BUTTON_OFFX = 100;
static int const Launcher_BUTTON_OFFY = 50;
static int const Launcher_WORD_OFFX = 100;
static int const Launcher_WORD_OFFY = 50;

#elif _480_800_ && _CHS_
static int const LAUNCHER_START_OFFX = -140;
static int const LAUNCHER_START_OFFY = 363;
static int const LAUNCHER_EXIT_OFFX = 140;
static int const LAUNCHER_EXIT_OFFY = 363;

static int const LAUNCHER_CENTRE_OFFX = 0;
static int const LAUNCHER_RIGHT_OFFX = 360;
static int const LAUNCHER_LEFT_OFFX = -80;
static int const LAUNCHER_GAMELOGO_OFFY = 0;

static int const LAUNCHER_TITLE_OFFX = 0;
static int const LAUNCHER_TITLE_OFFY = -316;

static int const LAUNCHER_GAMELOGO_WIDTH = 320;
static int const LAUNCHER_GAMELOGO_HEIGHT = 535;
static int const LAUNCHER_SIDE_WIDHT = 40;

static int const LAUNCHER_GAME_INTERVALX = 40;

static int const IG_LA_OPC_EXIT_OFFY = 70;
static int const IG_LA_OPC_TEXT_OFFY = -50;

#if _IG_TF_ && _IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,440,-640,-280};
static int Launcher_Position_bak[] = {80,440,-640,-280};
#elif _IG_TF_ && _IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80,440,-280};
static int Launcher_Position_bak[] = {80,440,-280};
#elif _IG_TF_ && _IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,440,-280};
static int Launcher_Position_bak[] = {80,440,-280};
#elif _IG_TF_ && !_IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,440,-280};
static int Launcher_Position_bak[] = {80,440,-280};
#elif !_IG_TF_ && _IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,440,-280};
static int Launcher_Position_bak[] = {80,440,-280};
#elif !_IG_TF_ && !_IG_DA_ && _IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,440};
static int Launcher_Position_bak[] = {80,440};
#elif !_IG_TF_ && _IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,440};
static int Launcher_Position_bak[] = {80,440};
#elif !_IG_TF_ && _IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80,440};
static int Launcher_Position_bak[] = {80,440};
#elif _IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80,440};
static int Launcher_Position_bak[] = {80,440};
#elif _IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80,440};
static int Launcher_Position_bak[] = {80,440};
#elif _IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80,440};
static int Launcher_Position_bak[] = {80,440};
#elif _IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80};
static int Launcher_Position_bak[] = {80};
#elif !_IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80};
static int Launcher_Position_bak[] = {80};
#elif !_IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_
static int Launcher_Position[] = {80};
static int Launcher_Position_bak[] = {80};
#elif !_IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_
static int Launcher_Position[] = {80};
static int Launcher_Position_bak[] = {80};
#endif

static int const LAUNCHER_BG2_OFFX = 0;
static int const LAUNCHER_BG2_OFFY = 0;
static int const LAUNCHER_CH1_OFFX = 0;
static int const LAUNCHER_CH1_OFFY = -50;
static int const Launcher_BUTTON_OFFX = 100;
static int const Launcher_BUTTON_OFFY = 50;
static int const Launcher_WORD_OFFX = 100;
static int const Launcher_WORD_OFFY = 50;

#endif

#if _480_800_
#if _IS_MTK_EMU_

static int const IG_LA_MOVE_SPEED = 36;

#else
static int const IG_LA_MOVE_SPEED = 3;

#endif
#else
#if _IS_MTK_EMU_

static int const IG_LA_MOVE_SPEED = 12;

#else
static int const IG_LA_MOVE_SPEED = 1;

#endif
#endif
static int LAUNCHER_GAME_COUNT = _IG_TF_ + _IG_DA_ + _IG_FT_ + _IG_BA_;

#if _IG_TF_ && _IG_DA_ && _IG_FT_ && _IG_BA_
static int const LAUNCHER_SELECT_GAME[] = {0,1,2,3};
#elif _IG_TF_ && _IG_DA_ && _IG_FT_ && !_IG_BA_
static int const LAUNCHER_SELECT_GAME[] = {0,1,2};
#elif _IG_TF_ && _IG_DA_ && !_IG_FT_ && _IG_BA_
static int const LAUNCHER_SELECT_GAME[] = {0,1,3};
#elif _IG_TF_ && !_IG_DA_ && _IG_FT_ && _IG_BA_
static int const LAUNCHER_SELECT_GAME[] = {0,2,3};
#elif !_IG_TF_ && _IG_DA_ && _IG_FT_ && _IG_BA_
static int const LAUNCHER_SELECT_GAME[] = {1,2,3};
#elif !_IG_TF_ && !_IG_DA_ && _IG_FT_ && _IG_BA_
static int const LAUNCHER_SELECT_GAME[] = {2,3};
#elif !_IG_TF_ && _IG_DA_ && !_IG_FT_ && _IG_BA_
static int const LAUNCHER_SELECT_GAME[] = {1,3};
#elif !_IG_TF_ && _IG_DA_ && _IG_FT_ && !_IG_BA_
static int const LAUNCHER_SELECT_GAME[] = {1,2};
#elif _IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_
static int const LAUNCHER_SELECT_GAME[] = {0,3};
#elif _IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_
static int const LAUNCHER_SELECT_GAME[] = {0,2};
#elif _IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_
static int const LAUNCHER_SELECT_GAME[] = {0,1};
#elif _IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_
static int const LAUNCHER_SELECT_GAME[] = {0};
#elif !_IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_
static int const LAUNCHER_SELECT_GAME[] = {1};
#elif !_IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_
static int const LAUNCHER_SELECT_GAME[] = {2};
#elif !_IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_
static int const LAUNCHER_SELECT_GAME[] = {3};
#endif

static int Launcher_Select_Index = 0;

static int Launcher_Move_Speed = 0;

static int Launcher_iDelta = 0;

static igbool isPressedStart = IGBOOL_FALSE;
static igbool isPressedExit = IGBOOL_FALSE;

static igbool isInStatus = IGBOOL_TRUE;  

static igbool isPressedL = IGBOOL_FALSE; 

static igbool isPressedR = IGBOOL_FALSE;  

static igbool isConfirmExit = IGBOOL_FALSE;  

static igbool igST02 = IGBOOL_TRUE;  

static IGU32 gs_time = 0 ;

static igbool isPressedButton = IGBOOL_FALSE;

extern IGU32 g_uIsOnPhoneCall;
//////////////////////////////////////////////////////// IGGame Framework Callback //////////////////////////////////////////

#if !_IS_MTK_EMU_
static char s_engineMemBuf[8*1024*1024]; 
static const long Launcher_mem_size = 8*1024*1024; 
#else
static void *s_engineMemBuf;
static IGU32 Launcher_mem_size;
#endif

int IGGame_OnStartup(IGPlatformConfig *pPC)
{	
#if _IS_MTK_EMU_    
	IG_FS_HANDLE handle;
	int ret;
	byte readbuf[10];
#endif

	Launcher_Width = pPC->m_uScrWidth;
	Launcher_Height = pPC->m_uScrHeight;
	Launcher_dispBuff = pPC->m_pFrameBuffer;
#if _IS_MTK_EMU_
	s_engineMemBuf = pPC->m_pMemoryBuf;
	Launcher_mem_size = pPC->m_uMemSize;
#endif

	/////////////Arvin start///////////////////
	#if _IS_MTK_EMU_
		Launcher_GlobalMaskR = MASK_565_RED;
		Launcher_GlobalMaskG = MASK_565_GREEN;
		Launcher_GlobalMaskB = MASK_565_BLUE;
		Launcher_IsTopDown = 1;		
	#else
		Launcher_GlobalMaskR = MASK_555_RED;
		Launcher_GlobalMaskG = MASK_555_GREEN;
		Launcher_GlobalMaskB = MASK_555_BLUE;
		Launcher_IsTopDown = 0;
	#endif
	/////////////Arvin end/////////////////////

	// One-time initialization of the Engine's internal memory pool.
	IGMemoryPool_initialize(&gs_mem, (unsigned char*)s_engineMemBuf, Launcher_mem_size, &err);

	if(g_uIsOnPhoneCall != 0){
		gs_time = 0;
		isPressedButton = IGBOOL_FALSE;
		status = IG_OnPhoneCall;
		IG_LA_OnPhoneCall_onInit(pPC->m_pFrameBuffer, pPC->m_uScrWidth, 
				pPC->m_uScrHeight, Launcher_GlobalMaskR, Launcher_GlobalMaskG, Launcher_GlobalMaskB, Launcher_IsTopDown);
	}else{
		#if _IS_MTK_EMU_
			handle = FS_Open((kal_uint16*)L"Z:\\@ig_save\\", FS_READ_ONLY | FS_OPEN_DIR);  //開啟目?看看成不成功
			if (handle >= FS_NO_ERROR)
			{
				FS_Close(handle);   // 成功，後面就可以去讀?資料檔
			}
			else
			{
				ret = FS_CreateDir((kal_uint16*)L"Z:\\@ig_save\\");  //不成功，自己建一?目?！
				if (ret < 0)
				{
					return KAL_FALSE;
				}        
			}


			handle = IG_LA_OpenForRead((IGCHAR *) L"Z:\\@ig_save\\launcher.ini");
			if(handle > 0){
				IG_LA_ReadFromFile(handle,readbuf,2);
				IGFS_Close(handle);
			}else{
				IG_LA_WriteInt(readbuf,0,0);
				IG_LA_ResetLauncherStatus();
			}

			if(IG_LA_ReadInt(readbuf,0) != 1 && IG_LA_ReadInt(readbuf,0) != 2 && IG_LA_ReadInt(readbuf,0) != 3 && IG_LA_ReadInt(readbuf,0) != 4){
				status = Launcher;
				Launcher_Select_Index = 0;
				Launcher_Move_Speed = 0;
				Launcher_iDelta = 0;
				isPressedStart = IGBOOL_FALSE;
				isPressedExit = IGBOOL_FALSE;
				isInStatus = IGBOOL_TRUE;  
				isPressedL = IGBOOL_FALSE; 
				isPressedR = IGBOOL_FALSE; 
				isConfirmExit = IGBOOL_FALSE; 
				igST02 = IGBOOL_TRUE;  
		#if !(!_IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_)
				copyArray(Launcher_Position,Launcher_Position_bak);
		#endif
				IG_LA_onInit(pPC->m_pFrameBuffer, pPC->m_uScrWidth, 
				pPC->m_uScrHeight, Launcher_GlobalMaskR, Launcher_GlobalMaskG, Launcher_GlobalMaskB, Launcher_IsTopDown);
			}
		#if _IG_TF_
			else if(IG_LA_ReadInt(readbuf,0) == 1){
				status = IG_TF;
				IG_TF_Tank_onInit((void*)s_engineMemBuf, Launcher_mem_size,Launcher_dispBuff, Launcher_Width, Launcher_Height,
					Launcher_GlobalMaskR, Launcher_GlobalMaskG, Launcher_GlobalMaskB, Launcher_IsTopDown,&gs_mem);
			}
		#endif
		#if _IG_DA_
			else if(IG_LA_ReadInt(readbuf,0) == 2){
				status = IG_DA;
				IG_DA_onInit((void*)s_engineMemBuf, Launcher_mem_size,Launcher_dispBuff, Launcher_Width, Launcher_Height,
					Launcher_GlobalMaskR, Launcher_GlobalMaskG, Launcher_GlobalMaskB, Launcher_IsTopDown,&gs_mem);
			}
		#endif
		#if _IG_FT_
			else if(IG_LA_ReadInt(readbuf,0) == 3){
				status = IG_Flower;
				FLOWERTOWER_onInit((void*)s_engineMemBuf, Launcher_mem_size,Launcher_dispBuff, Launcher_Width, Launcher_Height,
					Launcher_GlobalMaskR, Launcher_GlobalMaskG, Launcher_GlobalMaskB, Launcher_IsTopDown,&gs_mem);
			}
		#endif
		#if _IG_BA_
			else if(IG_LA_ReadInt(readbuf,0) == 4){
				status = IG_Brick;
				BALLSTICK_onInit((void*)s_engineMemBuf, Launcher_mem_size,Launcher_dispBuff, Launcher_Width, Launcher_Height,
					Launcher_GlobalMaskR, Launcher_GlobalMaskG, Launcher_GlobalMaskB, Launcher_IsTopDown,&gs_mem);
			}
		#endif
		#else
				status = Launcher;
				Launcher_Select_Index = 0;
				Launcher_Move_Speed = 0;
				Launcher_iDelta = 0;
				isPressedStart = IGBOOL_FALSE;
				isPressedExit = IGBOOL_FALSE;
				isInStatus = IGBOOL_TRUE;  
				isPressedL = IGBOOL_FALSE; 
				isPressedR = IGBOOL_FALSE; 
				isConfirmExit = IGBOOL_FALSE;
				igST02 = IGBOOL_TRUE; 
		#if !(!_IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_)
				copyArray(Launcher_Position,Launcher_Position_bak);
		#endif
				IG_LA_onInit(pPC->m_pFrameBuffer, pPC->m_uScrWidth, 
				pPC->m_uScrHeight, Launcher_GlobalMaskR, Launcher_GlobalMaskG, Launcher_GlobalMaskB, Launcher_IsTopDown);
		#endif
	}
	return 0;
}	

int IGGame_OnUpdate(IGU32 uFrameInterval, unsigned uNumSysEvents, IGSysEvent *pSE)
{
	switch(status){
		case IG_OnPhoneCall:
			IG_LA_OnPhoneCall_onUpdate(uFrameInterval, uNumSysEvents, pSE);
			break;
		case Launcher:
			IG_LA_onUpdate(uFrameInterval, uNumSysEvents, pSE);
			break;
#if _IG_TF_
		case IG_TF:
			IG_TF_Tank_onUpdate(uFrameInterval, uNumSysEvents, pSE);
			break;
#endif
#if _IG_DA_
		case IG_DA:
			IG_DA_onUpdate(uFrameInterval, uNumSysEvents, pSE);
			break;
#endif
#if _IG_FT_
		case IG_Flower:
			FLOWERTOWER_onUpdate(uFrameInterval, uNumSysEvents, pSE);
			break;
#endif
#if _IG_BA_
		case IG_Brick:
			 BALLSTICK_onUpdate(uFrameInterval, uNumSysEvents, pSE);
			break;
#endif
		default:
			break;
	}
	return 0;
}

void IGGame_OnShutdown(void)
{
	switch(status){
		case IG_OnPhoneCall:
			IG_LA_OnPhoneCall_onEnd();
			break;
		case Launcher:
			IG_LA_onEnd();
			break;
#if _IG_TF_
		case IG_TF:
			IG_TF_Tank_onEnd();
			break;
#endif
#if _IG_DA_
		case IG_DA:
			IG_DA_onEnd();
			break;
#endif
#if _IG_FT_
		case IG_Flower:
			FLOWERTOWER_onEnd();
			break;
#endif
#if _IG_BA_
		case IG_Brick:
			BALLSTICK_onEnd();
			break;
#endif
		default:
			break;
	}	
}


////init of Launcher
void IG_LA_onInit(void* dispBuff,int dispWidth,int dispHeight,int maskRed,int maskGreen,int maskBlue,int isTopDown)
{
	#if _IS_MTK_EMU_
	   scrW = dispWidth;
	   scrH = dispHeight;
	#elif _240_320_
	   scrW = 240;
	   scrH = 320;
	#elif _320_480_
	   scrW = 320;
	   scrH = 480;
	#elif   _240_400_
	   scrW = 240;
	   scrH = 400;
	#elif   _480_800_
	   scrW = 480;
	   scrH = 800;
	#endif

	anchorX = scrW>>1;
	anchorY = scrH>>1;

	//init 2D
	if(IGMemoryPool_available(&gs_mem,&err) >= (sizeof(IGPoint) + sizeof(IGRect))){
		texPoint  = ( IGPoint *)IGMemoryPool_allocate(&gs_mem,sizeof(IGPoint),&err);
		texRect = ( IGRect *)IGMemoryPool_allocate(&gs_mem,sizeof(IGRect),&err);
	}

	texST02 = IG_LA_init2DTexture(IG_LA_ST_02,"IG_LA_ST_02.png");

	texStart = IG_LA_init2DTexture(IG_Start,"IG_Start.png");

	texExit = IG_LA_init2DTexture(IG_Exit,"IG_Exit.png");

	texCh3 = IG_LA_init2DTexture(IG_LA_ch_03,"IG_LA_ch_03.png");

	texCh2 = IG_LA_init2DTexture(IG_LA_ch_02,"IG_LA_ch_02.png");
	
	texTitle[0] = IG_LA_init2DTexture(IG_TF_Title,"IG_TF_Title.png");

	texTitle[2] = IG_LA_init2DTexture(IG_Flower_Title,"IG_Flower_Title.png");

	texTitle[3] = IG_LA_init2DTexture(IG_Brick_Title,"IG_Brick_Title.png");

	texTitle[1] = IG_LA_init2DTexture(IG_DA_Title,"IG_DA_Title.png");

	texCh1 = IG_LA_init2DTexture(IG_LA_ch_01,"IG_LA_ch_01.png");

	texBosha = IG_LA_init2DTexture(IG_LA_bosha,"IG_LA_bosha.png");

	texBG2 = IG_LA_init2DTexture(IG_LA_backgroung_02,"IG_LA_backgroung_02.png");

	texButton3 = IG_LA_init2DTexture(IG_Button3,"IG_Button3.png");

	texButton2 = IG_LA_init2DTexture(IG_Button2,"IG_Button2.png");

	texButton1 = IG_LA_init2DTexture(IG_Button1,"IG_Button1.png");

	texButton = IG_LA_init2DTexture(IG_Button,"IG_Button.png");

	texGame[3] = IG_LA_init2DTexture(IG_BrickGameStart,"IG_BrickGameStart.png");

	texGame[0] = IG_LA_init2DTexture(IG_TankGameStart,"IG_TankGameStart.png");
		
	texGame[1] = IG_LA_init2DTexture(IG_DanceGameStart,"IG_DanceGameStart.png");	

	texBG = IG_LA_init2DTexture(IG_background,"IG_background.png");

	texGame[2] = IG_LA_init2DTexture(IG_FlowerGameStart,"IG_FlowerGameStart.png");	


	// Allocate a new renderer.
	gs_render = IGRenderer_new(&gs_mem, &err);

    IGRenderer_setTarget(
	   &gs_mem, 
	   gs_render,
	   (igcolor*)dispBuff,
	   dispWidth,
	   dispHeight,
	   (igbool)isTopDown,
	   IGBOOL_TRUE,//z-buffer
	   (igbool)0,
	   (igcolor)maskRed,
	   (igcolor)maskGreen,
	   (igcolor)maskBlue,
	   &err);

	return;
}



////IG_LA_onUpdate///////////
void IG_LA_onUpdate(IGU32 uFrameInterval, unsigned uNumSysEvents, IGSysEvent *pSE)
{
#if (!_IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_) || (!_IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_) || (!_IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_) || (_IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_) 
#else
#if !(!_IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_)
	int i;
#endif
#endif

	IG_LA_drawImage(texBG,0,0);
#if !(!_IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_)
	if(!isPressedStart){
		IG_LA_drawImage(texButton1,anchorX + LAUNCHER_START_OFFX - (texButton1->m_width>>1),anchorY + LAUNCHER_START_OFFY - (texButton1->m_height>>1));
	}else{
		IG_LA_drawImage(texButton,anchorX + LAUNCHER_START_OFFX - (texButton->m_width>>1),anchorY + LAUNCHER_START_OFFY - (texButton->m_height>>1));
	}
	IG_LA_drawImage(texStart,anchorX + LAUNCHER_START_OFFX - (texStart->m_width>>1),anchorY + LAUNCHER_START_OFFY-3 - (texStart->m_height>>1));

	if(!isPressedExit){
		IG_LA_drawImage(texButton1,anchorX + LAUNCHER_EXIT_OFFX - (texButton1->m_width>>1),anchorY + LAUNCHER_EXIT_OFFY - (texButton1->m_height>>1));
	}else{
		IG_LA_drawImage(texButton,anchorX + LAUNCHER_EXIT_OFFX - (texButton->m_width>>1),anchorY + LAUNCHER_EXIT_OFFY - (texButton->m_height>>1));
	}
	IG_LA_drawImage(texExit,anchorX + LAUNCHER_EXIT_OFFX - (texExit->m_width>>1),anchorY + LAUNCHER_EXIT_OFFY -3- (texExit->m_height>>1));
#else
	if(!isPressedExit){
		IG_LA_drawImage(texButton1,anchorX - (texButton->m_width>>1),anchorY - (texButton->m_height>>1));
	}else{
		IG_LA_drawImage(texButton,anchorX  - (texButton1->m_width>>1),anchorY - (texButton1->m_height>>1));
	}
	IG_LA_drawImage(texExit,anchorX - (texExit->m_width>>1),anchorY - (texExit->m_height>>1));
#endif

#if (!_IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_) || (!_IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_) || (!_IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_) || (_IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_) 
	IG_LA_drawImage(texGame[LAUNCHER_SELECT_GAME[0]],anchorX + LAUNCHER_CENTRE_OFFX - (texGame[LAUNCHER_SELECT_GAME[0]]->m_width>>1),
			anchorY + LAUNCHER_GAMELOGO_OFFY - (texGame[LAUNCHER_SELECT_GAME[0]]->m_height>>1));
	IG_LA_drawImage(texTitle[LAUNCHER_SELECT_GAME[0]],anchorX-(texTitle[LAUNCHER_SELECT_GAME[0]]->m_width>>1) + LAUNCHER_TITLE_OFFX,
			anchorY-(texTitle[LAUNCHER_SELECT_GAME[0]]->m_height>>1) + LAUNCHER_TITLE_OFFY);
#else
	#if !(!_IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_)
		for(i = 0 ; i < LAUNCHER_GAME_COUNT ; i++){
			Launcher_Position[i] = Launcher_Position[i] + Launcher_Move_Speed;
		}
	#endif
	#if (!_IG_TF_ && !_IG_DA_ && _IG_FT_ && _IG_BA_) || (!_IG_TF_ && _IG_DA_ && !_IG_FT_ && _IG_BA_) || (_IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_) || (!_IG_TF_ && _IG_DA_ && _IG_FT_ && !_IG_BA_) || (_IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_) || (_IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_) 
		for(i = 0 ; i < LAUNCHER_GAME_COUNT;i++){
			if(Launcher_Position[i] >= (LAUNCHER_GAME_INTERVALX+LAUNCHER_GAMELOGO_WIDTH)*LAUNCHER_GAME_COUNT){
				Launcher_Position[i] = Launcher_Position[i] - (LAUNCHER_GAME_INTERVALX+LAUNCHER_GAMELOGO_WIDTH)*LAUNCHER_GAME_COUNT;
			}else if(Launcher_Position[i] < 0){
				Launcher_Position[i] = Launcher_Position[i] + (LAUNCHER_GAME_INTERVALX+LAUNCHER_GAMELOGO_WIDTH)*LAUNCHER_GAME_COUNT;
			}
		}
	#else
		#if !(!_IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_)
			for(i = 0 ; i < LAUNCHER_GAME_COUNT;i++){
				if(Launcher_Position[i] >= scrW){
					Launcher_Position[i] = Launcher_Position[i] - ((LAUNCHER_GAME_INTERVALX+LAUNCHER_GAMELOGO_WIDTH)*LAUNCHER_GAME_COUNT);
				}else if(Launcher_Position[i] < (scrW-(LAUNCHER_GAME_INTERVALX+LAUNCHER_GAMELOGO_WIDTH)*LAUNCHER_GAME_COUNT)){
					Launcher_Position[i] = Launcher_Position[i] + ((LAUNCHER_GAME_INTERVALX+LAUNCHER_GAMELOGO_WIDTH)*LAUNCHER_GAME_COUNT);
				}
			}
		#endif
	#endif

	#if !(!_IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_)
		if(isInStatus){
			IG_LA_drawImage(texGame[LAUNCHER_SELECT_GAME[Launcher_Select_Index]],anchorX + LAUNCHER_CENTRE_OFFX - (texGame[0]->m_width>>1),
				anchorY + LAUNCHER_GAMELOGO_OFFY - (texGame[0]->m_height>>1));

			IG_LA_drawImageClip(texGame[LAUNCHER_SELECT_GAME[(Launcher_Select_Index+1 + LAUNCHER_GAME_COUNT)%LAUNCHER_GAME_COUNT]],anchorX + LAUNCHER_RIGHT_OFFX - (texGame[0]->m_width>>1),
				anchorY + LAUNCHER_GAMELOGO_OFFY - (texGame[0]->m_height>>1),0,0,LAUNCHER_SIDE_WIDHT - 1,LAUNCHER_GAMELOGO_HEIGHT - 1);

			IG_LA_drawImageClip(texGame[LAUNCHER_SELECT_GAME[(Launcher_Select_Index-1+LAUNCHER_GAME_COUNT)%LAUNCHER_GAME_COUNT]],anchorX + LAUNCHER_LEFT_OFFX - (texGame[0]->m_width>>1),
				anchorY + LAUNCHER_GAMELOGO_OFFY - (texGame[0]->m_height>>1),LAUNCHER_GAMELOGO_WIDTH - LAUNCHER_SIDE_WIDHT,0,LAUNCHER_GAMELOGO_WIDTH - 1,LAUNCHER_GAMELOGO_HEIGHT - 1);

			IG_LA_drawImage(texTitle[LAUNCHER_SELECT_GAME[Launcher_Select_Index%LAUNCHER_GAME_COUNT]],anchorX-(texTitle[0]->m_width>>1) + LAUNCHER_TITLE_OFFX,
				anchorY-(texTitle[0]->m_height>>1) + LAUNCHER_TITLE_OFFY);
		}else{
			for(i = 0 ; i < LAUNCHER_GAME_COUNT ; i++){
		#if (!_IG_TF_ && !_IG_DA_ && _IG_FT_ && _IG_BA_) || (!_IG_TF_ && _IG_DA_ && !_IG_FT_ && _IG_BA_) || (_IG_TF_ && !_IG_DA_ && !_IG_FT_ && _IG_BA_) || (!_IG_TF_ && _IG_DA_ && _IG_FT_ && !_IG_BA_) || (_IG_TF_ && !_IG_DA_ && _IG_FT_ && !_IG_BA_) || (_IG_TF_ && _IG_DA_ && !_IG_FT_ && !_IG_BA_) 
					if(Launcher_Position[i] >= 0 && Launcher_Position[i] <= (int)((anchorX<<1) - texGame[i]->m_width)){
						IG_LA_drawImage(texGame[LAUNCHER_SELECT_GAME[i]],Launcher_Position[i],anchorY + LAUNCHER_GAMELOGO_OFFY - (texGame[0]->m_height>>1));
					}
					if(Launcher_Position[i] > (int)((anchorX<<1) - texGame[i]->m_width) && Launcher_Position[i] < (int)(anchorX<<1)){
						IG_LA_drawImageClip(texGame[LAUNCHER_SELECT_GAME[i]],Launcher_Position[i],anchorY + LAUNCHER_GAMELOGO_OFFY - (texGame[0]->m_height>>1),
							0,0,(anchorX<<1)-Launcher_Position[i]-1,LAUNCHER_GAMELOGO_HEIGHT - 1);
					}
					if((Launcher_Position[i] - (LAUNCHER_GAME_INTERVALX+LAUNCHER_GAMELOGO_WIDTH)*LAUNCHER_GAME_COUNT) >= -(int)texGame[i]->m_width){
						IG_LA_drawImageClip(texGame[LAUNCHER_SELECT_GAME[i]],anchorX + LAUNCHER_LEFT_OFFX - (texGame[i]->m_width>>1),anchorY + LAUNCHER_GAMELOGO_OFFY - (texGame[0]->m_height>>1)
							,-(Launcher_Position[i] - (LAUNCHER_GAME_INTERVALX+LAUNCHER_GAMELOGO_WIDTH)*LAUNCHER_GAME_COUNT),0,LAUNCHER_GAMELOGO_WIDTH - 1,LAUNCHER_GAMELOGO_HEIGHT - 1);
					}
		#else
					if(Launcher_Position[i] >= 0 && Launcher_Position[i] <= (int)((anchorX<<1) - texGame[i]->m_width)){
						IG_LA_drawImage(texGame[LAUNCHER_SELECT_GAME[i]],Launcher_Position[i],anchorY + LAUNCHER_GAMELOGO_OFFY - (texGame[0]->m_height>>1));
					}else if(Launcher_Position[i] > (int)((anchorX<<1) - texGame[i]->m_width) && Launcher_Position[i] < (int)(anchorX<<1)){
						IG_LA_drawImageClip(texGame[LAUNCHER_SELECT_GAME[i]],Launcher_Position[i],anchorY + LAUNCHER_GAMELOGO_OFFY - (texGame[0]->m_height>>1),
							0,0,(anchorX<<1)-Launcher_Position[i]-1,LAUNCHER_GAMELOGO_HEIGHT - 1);
					}else if((Launcher_Position[i] > -(int)texGame[i]->m_width) && Launcher_Position[i] < 0){
						IG_LA_drawImageClip(texGame[LAUNCHER_SELECT_GAME[i]],anchorX + LAUNCHER_LEFT_OFFX - (texGame[i]->m_width>>1),anchorY + LAUNCHER_GAMELOGO_OFFY - (texGame[0]->m_height>>1)
							,-Launcher_Position[i],0,LAUNCHER_GAMELOGO_WIDTH - 1,LAUNCHER_GAMELOGO_HEIGHT - 1);
					}
		#endif
		}

	}
	#endif

	#if !(!_IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_)
		if(Launcher_Position[Launcher_Select_Index] == anchorX + LAUNCHER_CENTRE_OFFX - (texGame[0]->m_width>>1)){
			isInStatus = IGBOOL_TRUE;
			Launcher_Move_Speed = 0;
		}
	#endif

#endif

	if(isConfirmExit){
		IG_LA_drawExitConfirm(isPressedL,isPressedR);
	}


	//key and touch screen
	while (uNumSysEvents--) 
	{
		if(pSE->m_uData1 == IGFK_KEY_DOWN){
			IG_LA_keyPressed(pSE->m_uEventID);
		}else if(pSE->m_uData1 == IGFK_KEY_UP){
			IG_LA_keyReleased(pSE->m_uEventID);
		}else if(pSE->m_uEventID == IGFK_TOUCH1_DOWN){
			IG_LA_pointerPressed(pSE->m_uData1,pSE->m_uData2);
		}else if(pSE->m_uEventID == IGFK_TOUCH1_UP){
			IG_LA_pointerReleased(pSE->m_uData1,pSE->m_uData2);
		}else if(pSE->m_uEventID == IGFK_TOUCH1_MOVE){
			IG_LA_pointerDragged(pSE->m_uData1,pSE->m_uData2);
		}
		pSE++;
	}
	return;
}
////IG_LA_onEnd//////
void IG_LA_onEnd(void){
	IGTexture_destroy(&gs_mem,texGame[2],&err);
	IGTexture_destroy(&gs_mem,texBG,&err);
	IGTexture_destroy(&gs_mem,texGame[1],&err);
	IGTexture_destroy(&gs_mem,texGame[0],&err);
	IGTexture_destroy(&gs_mem,texGame[3],&err);
	IGTexture_destroy(&gs_mem,texButton,&err);
	IGTexture_destroy(&gs_mem,texButton1,&err);
	IGTexture_destroy(&gs_mem,texButton2,&err);
	IGTexture_destroy(&gs_mem,texButton3,&err);
	IGTexture_destroy(&gs_mem,texBG2,&err);
	IGTexture_destroy(&gs_mem,texBosha,&err);
	IGTexture_destroy(&gs_mem,texCh1,&err);
	IGTexture_destroy(&gs_mem,texTitle[1],&err);
	IGTexture_destroy(&gs_mem,texTitle[3],&err);
	IGTexture_destroy(&gs_mem,texTitle[2],&err);
	IGTexture_destroy(&gs_mem,texTitle[0],&err);
	IGTexture_destroy(&gs_mem,texCh2,&err);
	IGTexture_destroy(&gs_mem,texCh3,&err);
	IGTexture_destroy(&gs_mem,texExit,&err);
	IGTexture_destroy(&gs_mem,texStart,&err);
	IGTexture_destroy(&gs_mem,texST02,&err);
	IGMemoryPool_free(&gs_mem,(void *)texPoint,&err);
	IGMemoryPool_free(&gs_mem,(void *)texRect,&err);

	// Release renderer memory.
	IGRenderer_destroy(&gs_mem, gs_render, &err);

	IGMemoryPool_reset(&gs_mem,&err);

	// Release the memory the application allocated for the memory pool.
	IGMemoryPool_finalize(&gs_mem, &err);

	return;
}
////IG_LA_deleteResourse///////
void IG_LA_deleteResourse(void){
	IGTexture_destroy(&gs_mem,texGame[2],&err);
	IGTexture_destroy(&gs_mem,texBG,&err);
	IGTexture_destroy(&gs_mem,texGame[1],&err);
	IGTexture_destroy(&gs_mem,texGame[0],&err);
	IGTexture_destroy(&gs_mem,texGame[3],&err);
	IGTexture_destroy(&gs_mem,texButton,&err);
	IGTexture_destroy(&gs_mem,texButton1,&err);
	IGTexture_destroy(&gs_mem,texButton2,&err);
	IGTexture_destroy(&gs_mem,texButton3,&err);
	IGTexture_destroy(&gs_mem,texBG2,&err);
	IGTexture_destroy(&gs_mem,texBosha,&err);
	IGTexture_destroy(&gs_mem,texCh1,&err);
	IGTexture_destroy(&gs_mem,texTitle[1],&err);
	IGTexture_destroy(&gs_mem,texTitle[3],&err);
	IGTexture_destroy(&gs_mem,texTitle[2],&err);
	IGTexture_destroy(&gs_mem,texTitle[0],&err);
	IGTexture_destroy(&gs_mem,texCh2,&err);
	IGTexture_destroy(&gs_mem,texCh3,&err);
	IGTexture_destroy(&gs_mem,texExit,&err);
	IGTexture_destroy(&gs_mem,texStart,&err);
	IGTexture_destroy(&gs_mem,texST02,&err);
	IGMemoryPool_free(&gs_mem,(void *)texPoint,&err);
	IGMemoryPool_free(&gs_mem,(void *)texRect,&err);

	// Release renderer memory.
	IGRenderer_destroy(&gs_mem, gs_render, &err);

	
	IGMemoryPool_reset(&gs_mem,&err);


	return;
}
//////////////////////////key pressed function////////////////////////////
/**
press key
*/
void IG_LA_keyPressed(IGU32 m_uEventID){
	if(!isConfirmExit){
		switch(m_uEventID){
			//case IGFK_UP_ARROW:
			//case IGFK_2:
			//	break;		
			//case IGFK_DOWN_ARROW:
			//case IGFK_8:
			//	break;
			//case IGFK_5:
			//case IGFK_CSK:
			case IGFK_SEND:
			case IGFK_LSK:
				isPressedStart = IGBOOL_TRUE;
				isPressedExit = IGBOOL_FALSE;
				isInStatus = IGBOOL_TRUE;
				break;
			case IGFK_END:
			case IGFK_RSK:
				isPressedExit = IGBOOL_TRUE;
				isPressedStart = IGBOOL_FALSE;
				isInStatus = IGBOOL_TRUE;
				break;
#if !(!_IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_)
			case IGFK_LEFT_ARROW:
			case IGFK_4:
				if(isInStatus){
					isInStatus = IGBOOL_FALSE;
					Launcher_Select_Index = (Launcher_Select_Index + 1 ) % LAUNCHER_GAME_COUNT;				
					Launcher_Move_Speed = -IG_LA_MOVE_SPEED;
				}
				break;
			case IGFK_RIGHT_ARROW:
			case IGFK_6:
				if(isInStatus){
					isInStatus = IGBOOL_FALSE;
					Launcher_Select_Index = (Launcher_Select_Index - 1 + LAUNCHER_GAME_COUNT) % LAUNCHER_GAME_COUNT;
					Launcher_Move_Speed = IG_LA_MOVE_SPEED;
				}
				break;
#endif
			//case IGFK_1:
			//	break;
			//case IGFK_3:
			//	break;
			//case IGFK_7:
			//	break;
			//case IGFK_9:
			//	break;
			//case IGFK_0:
			//	break;
			//case IGFK_LSK:
			//	break;
			//case IGFK_RSK:
			//	break;
			//case IGFK_STAR:
			//	break;
			//case IGFK_POUND:
			//	break;
			//case IGFK_CLEAR:
			//	break;
			default:
				break;
		} 
	}else{
		switch(m_uEventID){
			//case IGFK_UP_ARROW:
			//case IGFK_2:
			//	break;		
			//case IGFK_DOWN_ARROW:
			//case IGFK_8:
			//	break;
			case IGFK_5:
			case IGFK_CSK:
				if(!igST02){
					isPressedL = IGBOOL_TRUE;
					isPressedR = IGBOOL_FALSE;
				}else{
					isPressedR = IGBOOL_TRUE;
					isPressedL = IGBOOL_FALSE;
				}
				break;
			case IGFK_SEND:
			case IGFK_LSK:
				isPressedL = IGBOOL_TRUE;
				isPressedR = IGBOOL_FALSE;
				break;
			case IGFK_END:
			case IGFK_RSK:
				isPressedR = IGBOOL_TRUE;
				isPressedL = IGBOOL_FALSE;
				break;
			case IGFK_LEFT_ARROW:
			case IGFK_4:
				igST02 = IGBOOL_FALSE;
				break;
			case IGFK_RIGHT_ARROW:
			case IGFK_6:
				igST02 = IGBOOL_TRUE;
				break;
			//case IGFK_1:
			//	break;
			//case IGFK_3:
			//	break;
			//case IGFK_7:
			//	break;
			//case IGFK_9:
			//	break;
			//case IGFK_0:
			//	break;
			//case IGFK_LSK:
			//	break;
			//case IGFK_RSK:
			//	break;
			//case IGFK_STAR:
			//	break;
			//case IGFK_POUND:
			//	break;
			//case IGFK_CLEAR:
			//	break;
			default:
				break;
		} 
	}
}

/**
release key
*/
void IG_LA_keyReleased(IGU32 m_uEventID){
#if _IS_MTK_EMU_
#if !(!_IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_)
	byte writenbuf[10];
#endif
#endif
	isPressedR = IGBOOL_FALSE;
	isPressedL = IGBOOL_FALSE;
	isPressedExit = IGBOOL_FALSE;
	isPressedStart = IGBOOL_FALSE;
	if(!isConfirmExit){
		switch(m_uEventID){
			//case IGFK_UP_ARROW:
			//case IGFK_2:
			//	break;		
			//case IGFK_DOWN_ARROW:
			//case IGFK_8:
			//	break;
			//case IGFK_5:
			//case IGFK_CSK:
			case IGFK_SEND:
			case IGFK_LSK:
#if !(!_IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_)
				switch(LAUNCHER_SELECT_GAME[Launcher_Select_Index]){
#if _IG_TF_
					case 0:	
						status = IG_TF;
						IG_LA_deleteResourse();
#if _IS_MTK_EMU_
					IG_LA_WriteInt(writenbuf,1,0);
					IG_LA_WriteOrCreatFileAndWrite((IGCHAR *) L"Z:\\@ig_save\\launcher.ini",writenbuf,2);
#endif
						IG_TF_Tank_onInit((void*)s_engineMemBuf, Launcher_mem_size,Launcher_dispBuff, Launcher_Width, Launcher_Height,
							Launcher_GlobalMaskR, Launcher_GlobalMaskG, Launcher_GlobalMaskB, Launcher_IsTopDown,&gs_mem);
						break;
#endif
#if _IG_DA_
					case 1:
						status = IG_DA;
						IG_LA_deleteResourse();
#if _IS_MTK_EMU_
					IG_LA_WriteInt(writenbuf,2,0);
					IG_LA_WriteOrCreatFileAndWrite((IGCHAR *) L"Z:\\@ig_save\\launcher.ini",writenbuf,2);
#endif
						IG_DA_onInit((void*)s_engineMemBuf, Launcher_mem_size,Launcher_dispBuff,  Launcher_Width, Launcher_Height,
			    			Launcher_GlobalMaskR, Launcher_GlobalMaskG, Launcher_GlobalMaskB, Launcher_IsTopDown,&gs_mem);
						break;
#endif
#if _IG_FT_	
					case 2:
						status = IG_Flower;
						IG_LA_deleteResourse();
#if _IS_MTK_EMU_
					IG_LA_WriteInt(writenbuf,3,0);
					IG_LA_WriteOrCreatFileAndWrite((IGCHAR *) L"Z:\\@ig_save\\launcher.ini",writenbuf,2);
#endif
						FLOWERTOWER_onInit((void*)s_engineMemBuf, Launcher_mem_size, Launcher_dispBuff, Launcher_Width, Launcher_Height,
			    			Launcher_GlobalMaskR, Launcher_GlobalMaskG, Launcher_GlobalMaskB, Launcher_IsTopDown,&gs_mem);
						break;
#endif
#if _IG_BA_
					case 3:
						status = IG_Brick;
						IG_LA_deleteResourse();
#if _IS_MTK_EMU_
					IG_LA_WriteInt(writenbuf,4,0);
					IG_LA_WriteOrCreatFileAndWrite((IGCHAR *) L"Z:\\@ig_save\\launcher.ini",writenbuf,2);
#endif
						BALLSTICK_onInit((void*)s_engineMemBuf, Launcher_mem_size,Launcher_dispBuff,  Launcher_Width, Launcher_Height,
							Launcher_GlobalMaskR, Launcher_GlobalMaskG, Launcher_GlobalMaskB, Launcher_IsTopDown,&gs_mem);
						break;
#endif
					default:
						break;
				}
#endif
				break;
			case IGFK_END:
			case IGFK_RSK:
				isConfirmExit = IGBOOL_TRUE;
				break;
			//case IGFK_LEFT_ARROW:
			//case IGFK_4:
			//	break;
			//case IGFK_RIGHT_ARROW:
			//case IGFK_6:
			//	break;
			//case IGFK_1:
			//	break;
			//case IGFK_3:
			//	break;
			//case IGFK_7:
			//	break;
			//case IGFK_9:
			//	break;
			//case IGFK_0:
			//	break;
			//case IGFK_LSK:
			//	break;
			//case IGFK_RSK:
			//	break;
			//case IGFK_STAR:
			//	break;
			//case IGFK_POUND:
			//	break;
			//case IGFK_CLEAR:
			//	break;
			default:
				break;
		} 
	}else{
		switch(m_uEventID){
			//case IGFK_UP_ARROW:
			//case IGFK_2:
			//	break;		
			//case IGFK_DOWN_ARROW:
			//case IGFK_8:
			//	break;
			case IGFK_5:
			case IGFK_CSK:
				if(!igST02){
#if _IS_MTK_EMU_
					IG_LA_ResetLauncherStatus();
					IGSystem_Exit();
#endif
				}else{
					isPressedR = IGBOOL_FALSE;
					isConfirmExit = IGBOOL_FALSE;
				}
				break;
			//case IGFK_LEFT_ARROW:
			//case IGFK_4:
			//	break;
			//case IGFK_RIGHT_ARROW:
			//case IGFK_6:
			//	break;
			//case IGFK_1:
			//	break;
			//case IGFK_3:
			//	break;
			//case IGFK_7:
			//	break;
			//case IGFK_9:
			//	break;
			//case IGFK_0:
			//	break;
			//case IGFK_LSK:
			//	break;
			//case IGFK_RSK:
			//	break;
			//case IGFK_STAR:
			//	break;
			//case IGFK_POUND:
			//	break;
			//case IGFK_CLEAR:
			//	break;
			default:
				break;
		} 
	}
}




/////////////////////////touch screen function///////////////////////////

/**
on touch
*/
	static int iLastX = 0;
void IG_LA_pointerPressed(IGU32 m_uData1,IGU32 m_uData2){
	iLastX = m_uData1;
	if(!isConfirmExit){
		if(IG_LA_isOnTouch(m_uData1,m_uData2,anchorX + LAUNCHER_START_OFFX - (texButton->m_width>>1),
			anchorY + LAUNCHER_START_OFFY - (texButton->m_height>>1),
			anchorX + LAUNCHER_START_OFFX + (texButton->m_width>>1),
			anchorY + LAUNCHER_START_OFFY + (texButton->m_height>>1))){
			isPressedStart = IGBOOL_TRUE;
			isPressedExit =  IGBOOL_FALSE;
			isInStatus = IGBOOL_TRUE;
		}
#if !(!_IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_)
			else if(IG_LA_isOnTouch(m_uData1,m_uData2,anchorX + LAUNCHER_EXIT_OFFX - (texButton->m_width>>1),
			anchorY + LAUNCHER_EXIT_OFFY - (texButton->m_height>>1),
			anchorX + LAUNCHER_EXIT_OFFX + (texButton->m_width>>1),
			anchorY + LAUNCHER_EXIT_OFFY + (texButton->m_height>>1))){
#else
			else if(IG_LA_isOnTouch(m_uData1,m_uData2,anchorX  - (texButton->m_width>>1),
			anchorY  - (texButton->m_height>>1),
			anchorX + (texButton->m_width>>1),
			anchorY + (texButton->m_height>>1))){
#endif
			isPressedExit = IGBOOL_TRUE;
			isPressedStart = IGBOOL_FALSE;
			isInStatus = IGBOOL_TRUE;
		}
	}else{
		if(IG_LA_isOnTouch(m_uData1,m_uData2,anchorX - Launcher_BUTTON_OFFX - (texButton->m_width>>1),
			anchorY + Launcher_BUTTON_OFFY - (texButton->m_height>>1),
			anchorX - Launcher_BUTTON_OFFX + (texButton->m_width>>1),
			anchorY + Launcher_BUTTON_OFFY + (texButton->m_height>>1))){
				igST02 = IGBOOL_FALSE;
				isPressedR = IGBOOL_FALSE;
				isPressedL = IGBOOL_TRUE;
				isInStatus = IGBOOL_TRUE;
		}else if(IG_LA_isOnTouch(m_uData1,m_uData2,anchorX + Launcher_BUTTON_OFFX - (texButton->m_width>>1),
			anchorY + Launcher_BUTTON_OFFY - (texButton->m_height>>1),
			anchorX + Launcher_BUTTON_OFFX + (texButton->m_width>>1),
			anchorY + Launcher_BUTTON_OFFY + (texButton->m_height>>1))){
				igST02 = IGBOOL_TRUE;
				isPressedR = IGBOOL_TRUE;
				isPressedL = IGBOOL_FALSE;
				isInStatus = IGBOOL_TRUE;
		}
	}
}

/**
release touch
*/
void IG_LA_pointerReleased(IGU32 m_uData1,IGU32 m_uData2){
#if _IS_MTK_EMU_
#if !(!_IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_)
	byte writenbuf[10];
#endif
#endif
	if(!isConfirmExit){
		if(isPressedStart && IG_LA_isOnTouch(m_uData1,m_uData2,anchorX + LAUNCHER_START_OFFX - (texButton->m_width>>1),
			anchorY + LAUNCHER_START_OFFY - (texButton->m_height>>1),
			anchorX + LAUNCHER_START_OFFX + (texButton->m_width>>1),
			anchorY + LAUNCHER_START_OFFY + (texButton->m_height>>1))){
#if !(!_IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_)
			switch(LAUNCHER_SELECT_GAME[Launcher_Select_Index]){
#if _IG_TF_
				case 0:
					status = IG_TF;
					IG_LA_deleteResourse();
#if _IS_MTK_EMU_
					IG_LA_WriteInt(writenbuf,1,0);
					IG_LA_WriteOrCreatFileAndWrite((IGCHAR *) L"Z:\\@ig_save\\launcher.ini",writenbuf,2);
#endif
					IG_TF_Tank_onInit((void*)s_engineMemBuf, Launcher_mem_size, Launcher_dispBuff, Launcher_Width, Launcher_Height,
						Launcher_GlobalMaskR, Launcher_GlobalMaskG, Launcher_GlobalMaskB, Launcher_IsTopDown,&gs_mem);
					break;
#endif
#if _IG_DA_
				case 1:
					status = IG_DA;
					IG_LA_deleteResourse();
#if _IS_MTK_EMU_
					IG_LA_WriteInt(writenbuf,2,0);
					IG_LA_WriteOrCreatFileAndWrite((IGCHAR *) L"Z:\\@ig_save\\launcher.ini",writenbuf,2);
#endif
					IG_DA_onInit((void*)s_engineMemBuf, Launcher_mem_size,Launcher_dispBuff,  Launcher_Width, Launcher_Height,
			    		Launcher_GlobalMaskR, Launcher_GlobalMaskG, Launcher_GlobalMaskB, Launcher_IsTopDown,&gs_mem);
					break;
#endif
#if _IG_FT_
				case 2:
					status = IG_Flower;
					IG_LA_deleteResourse();
#if _IS_MTK_EMU_
					IG_LA_WriteInt(writenbuf,3,0);
					IG_LA_WriteOrCreatFileAndWrite((IGCHAR *) L"Z:\\@ig_save\\launcher.ini",writenbuf,2);
#endif
					FLOWERTOWER_onInit((void*)s_engineMemBuf, Launcher_mem_size, Launcher_dispBuff, Launcher_Width, Launcher_Height,
			    		Launcher_GlobalMaskR, Launcher_GlobalMaskG, Launcher_GlobalMaskB, Launcher_IsTopDown,&gs_mem);
					break;
#endif
#if _IG_BA_
				case 3:
					status = IG_Brick;
					IG_LA_deleteResourse();
#if _IS_MTK_EMU_
					IG_LA_WriteInt(writenbuf,4,0);
					IG_LA_WriteOrCreatFileAndWrite((IGCHAR *) L"Z:\\@ig_save\\launcher.ini",writenbuf,2);
#endif
					BALLSTICK_onInit((void*)s_engineMemBuf, Launcher_mem_size,Launcher_dispBuff,  Launcher_Width, Launcher_Height,
						Launcher_GlobalMaskR, Launcher_GlobalMaskG, Launcher_GlobalMaskB, Launcher_IsTopDown,&gs_mem);
					break;
#endif
				default:
					break;
			}
#endif
		}
#if !(!_IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_)
			else if(isPressedExit && IG_LA_isOnTouch(m_uData1,m_uData2,anchorX + LAUNCHER_EXIT_OFFX - (texButton->m_width>>1),
			anchorY + LAUNCHER_EXIT_OFFY - (texButton->m_height>>1),
			anchorX + LAUNCHER_EXIT_OFFX + (texButton->m_width>>1),
			anchorY + LAUNCHER_EXIT_OFFY + (texButton->m_height>>1))){
#else
			else if(IG_LA_isOnTouch(m_uData1,m_uData2,anchorX  - (texButton->m_width>>1),
			anchorY  - (texButton->m_height>>1),
			anchorX + (texButton->m_width>>1),
			anchorY + (texButton->m_height>>1))){
#endif
				isConfirmExit = IGBOOL_TRUE;
		}
		isPressedStart = IGBOOL_FALSE;
		isPressedExit = IGBOOL_FALSE;
	}else{
		if(isPressedL && IG_LA_isOnTouch(m_uData1,m_uData2,anchorX - Launcher_BUTTON_OFFX - (texButton->m_width>>1),
			anchorY + Launcher_BUTTON_OFFY - (texButton->m_height>>1),
			anchorX - Launcher_BUTTON_OFFX + (texButton->m_width>>1),
			anchorY + Launcher_BUTTON_OFFY + (texButton->m_height>>1))){
#if _IS_MTK_EMU_
		IG_LA_ResetLauncherStatus();
		IGSystem_Exit();
#endif		
		}else if(isPressedR && IG_LA_isOnTouch(m_uData1,m_uData2,anchorX + Launcher_BUTTON_OFFX - (texButton->m_width>>1),
			anchorY + Launcher_BUTTON_OFFY - (texButton->m_height>>1),
			anchorX + Launcher_BUTTON_OFFX + (texButton->m_width>>1),
			anchorY + Launcher_BUTTON_OFFY + (texButton->m_height>>1))){
			isConfirmExit = IGBOOL_FALSE;
		}
		isPressedL = IGBOOL_FALSE; 
		isPressedR = IGBOOL_FALSE; 
	}
}


/**
dragg pointer
*/

void IG_LA_pointerDragged(IGU32 m_uData1,IGU32 m_uData2){
#if !(!_IG_TF_ && !_IG_DA_ && !_IG_FT_ && !_IG_BA_)
	if(!isConfirmExit){
		if(m_uData2 > anchorY + LAUNCHER_GAMELOGO_OFFY - (texGame[0]->m_height>>1) && 
			m_uData2 < anchorY + LAUNCHER_GAMELOGO_OFFY + (texGame[0]->m_height>>1)){
			Launcher_iDelta = m_uData1 - iLastX;
			iLastX = m_uData1;
			if(Launcher_iDelta > 0){
				if(isInStatus){
					Launcher_Select_Index = (Launcher_Select_Index - 1 + LAUNCHER_GAME_COUNT) % LAUNCHER_GAME_COUNT;
					Launcher_Move_Speed = IG_LA_MOVE_SPEED;
				}
			}else if(Launcher_iDelta < 0){
				if(isInStatus){
					Launcher_Select_Index = (Launcher_Select_Index + 1 ) % LAUNCHER_GAME_COUNT;				
					Launcher_Move_Speed = -IG_LA_MOVE_SPEED;
				}
			}
			Launcher_iDelta = 0;
			isInStatus = IGBOOL_FALSE;
		}
	}
#endif
}

//////////////////////////utility///////////////////////

/**
draw image function
*/
void IG_LA_drawImage(IGTexture *img,int x,int y){
	texRect->x1 = 0;
	texRect->y1 = 0;
	texRect->x2 = img->m_width - 1;
	texRect->y2 = img->m_height - 1;

	texPoint->x = x;
	texPoint->y = y;

	IGSprite_draw(&gs_mem,gs_render,texPoint,img,texRect,&err);
}

/**
draw cliped image
*/
void IG_LA_drawImageClip(IGTexture *img,int x,int y,int x1,int y1,int x2,int y2){
	texRect->x1 = x1;
	texRect->y1 = y1;
	texRect->x2 = x2;
	texRect->y2 = y2;

	texPoint->x = x;
	texPoint->y = y;
	IGSprite_draw(&gs_mem,gs_render,texPoint,img,texRect,&err);
}


void IG_LA_drawExitConfirm(igbool isPressedL,igbool isPressedR){

	IG_LA_drawImage(texBosha,0,0);


	IG_LA_drawImage(texBG2,anchorX + LAUNCHER_BG2_OFFX - (texBG2->m_width>>1),anchorY + LAUNCHER_BG2_OFFY - (texBG2->m_height>>1));
	

	IG_LA_drawImage(texCh1,anchorX + LAUNCHER_CH1_OFFX - (texCh1->m_width>>1),anchorY + LAUNCHER_CH1_OFFY - (texCh1->m_height>>1));


	if(!isPressedL){
		IG_LA_drawImage(texButton2,anchorX - Launcher_BUTTON_OFFX - (texButton2->m_width>>1),anchorY + Launcher_BUTTON_OFFY - (texButton2->m_height>>1));
	}else{
		IG_LA_drawImage(texButton3,anchorX - Launcher_BUTTON_OFFX - (texButton2->m_width>>1),anchorY + Launcher_BUTTON_OFFY - (texButton2->m_height>>1));
	}
	if(!isPressedR){
		IG_LA_drawImage(texButton2,anchorX + Launcher_BUTTON_OFFX - (texButton2->m_width>>1),anchorY + Launcher_BUTTON_OFFY - (texButton2->m_height>>1));
	}else{
		IG_LA_drawImage(texButton3,anchorX + Launcher_BUTTON_OFFX - (texButton2->m_width>>1),anchorY + Launcher_BUTTON_OFFY - (texButton2->m_height>>1));
	}

	if(!igST02){
		IG_LA_drawImage(texST02,anchorX - Launcher_BUTTON_OFFX - (texButton2->m_width>>1),anchorY + Launcher_BUTTON_OFFY - (texButton2->m_height>>1));
	}else{
		IG_LA_drawImage(texST02,anchorX + Launcher_BUTTON_OFFX - (texButton2->m_width>>1),anchorY + Launcher_BUTTON_OFFY - (texButton2->m_height>>1));
	}


	IG_LA_drawImage(texCh2,anchorX - Launcher_WORD_OFFX - (texCh2->m_width>>1),anchorY + Launcher_WORD_OFFY - (texCh2->m_height>>1));
	IG_LA_drawImage(texCh3,anchorX + Launcher_WORD_OFFX - (texCh2->m_width>>1),anchorY + Launcher_WORD_OFFY - (texCh2->m_height>>1));
}

///////////////////////touch screen function///////////////////////////

/**
on touch
*/
igbool IG_LA_isOnTouch(IGU32 x,IGU32 y,IGU32 x1,IGU32 y1,IGU32 x2,IGU32 y2){
	if(x >= x1 && x <= x2 && y >= y1 && y<= y2){
		return IGBOOL_TRUE;
	}
	return IGBOOL_FALSE;
}

IGTexture *IG_LA_init2DTexture(const char* charTex,const char* texName){

	IGTexture* tmpTex = IGTexture_newFromByteArray(&gs_mem, charTex, texName, 
			Launcher_GlobalMaskR, Launcher_GlobalMaskG, Launcher_GlobalMaskB, &err);
	// Set the key color.
	IGTexture_setKeyColor(&gs_mem, tmpTex, IGTexture_getDeviceColor(&gs_mem, tmpTex, Launcher_KEY_COLOR_2D, &err), &err); 
	// Enable key color.
	IGTexture_setKeyColorEnabled(&gs_mem, tmpTex, IGBOOL_TRUE, &err);
	
	return tmpTex;
}


void copyArray(int array1[],int array2[]){
	int i;
	for(i = 0 ; i < LAUNCHER_GAME_COUNT ; i++){
		array1[i] = array2[i];
	}
}


#ifdef __cplusplus
}
#endif





///////////////////////////////////////////////g_uIsOnPhoneCall/////////////////////////////////////////

void IG_LA_OnPhoneCall_onInit(void* dispBuff,int dispWidth,int dispHeight,int maskRed,int maskGreen,int maskBlue,int isTopDown)
{
	#if _IS_MTK_EMU_
	   scrW = dispWidth;
	   scrH = dispHeight;
	#elif _240_320_
	   scrW = 240;
	   scrH = 320;
	#elif _320_480_
	   scrW = 320;
	   scrH = 480;
	#elif   _240_400_
	   scrW = 240;
	   scrH = 400;
	#elif   _480_800_
	   scrW = 480;
	   scrH = 800;
	#endif

	anchorX = scrW>>1;
	anchorY = scrH>>1;

	//init 2D
	if(IGMemoryPool_available(&gs_mem,&err) >= (sizeof(IGPoint) + sizeof(IGRect))){
		texPoint  = ( IGPoint *)IGMemoryPool_allocate(&gs_mem,sizeof(IGPoint),&err);
		texRect = ( IGRect *)IGMemoryPool_allocate(&gs_mem,sizeof(IGRect),&err);
	}

	texExit = IG_LA_init2DTexture(IG_LA_ch_02,"IG_LA_ch_02.png");

	texCh4 = IG_LA_init2DTexture(IG_LA_ch_04,"IG_LA_ch_04.png");

	texButton1 = IG_LA_init2DTexture(IG_Button1,"IG_Button1.png");

	texButton = IG_LA_init2DTexture(IG_Button,"IG_Button.png");

	texCh5 = IG_LA_init2DTexture(IG_LA_ch_05,"IG_LA_ch_05.png");

	// Allocate a new renderer.
	gs_render = IGRenderer_new(&gs_mem, &err);

    IGRenderer_setTarget(
	   &gs_mem, 
	   gs_render,
	   (igcolor*)dispBuff,
	   dispWidth,
	   dispHeight,
	   (igbool)isTopDown,
	   IGBOOL_TRUE,//z-buffer
	   (igbool)0,
	   (igcolor)maskRed,
	   (igcolor)maskGreen,
	   (igcolor)maskBlue,
	   &err);

	return;
}

void IG_LA_OnPhoneCall_onUpdate(IGU32 uFrameInterval, unsigned uNumSysEvents, IGSysEvent *pSE){

	gs_time += uFrameInterval;

	IG_LA_drawImage(texCh5,0,0);
	IG_LA_drawImage(texCh4,anchorX - (texCh4->m_width >> 1),anchorY + IG_LA_OPC_TEXT_OFFY - (texCh4 ->m_height >> 1));
	if(!isPressedButton){
		IG_LA_drawImage(texButton1,anchorX - (texButton1->m_width >> 1),anchorY + IG_LA_OPC_EXIT_OFFY - (texButton1 ->m_height >> 1));
	}else{
		IG_LA_drawImage(texButton,anchorX - (texButton->m_width >> 1),anchorY + IG_LA_OPC_EXIT_OFFY - (texButton ->m_height >> 1));
	}
		IG_LA_drawImage(texExit,anchorX - (texExit->m_width >> 1),anchorY + IG_LA_OPC_EXIT_OFFY - (texExit ->m_height >> 1));

	if(gs_time >= 15000){
#if _IS_MTK_EMU_
		IGSystem_Exit();
#endif
	}

	//key and touch screen
	while (uNumSysEvents--) 
	{
		if(pSE->m_uData1 == IGFK_KEY_DOWN){
			switch(pSE->m_uEventID){
				case IGFK_5:
				case IGFK_CSK:
					isPressedButton = IGBOOL_TRUE;
				break;
			}
		}else if(pSE->m_uData1 == IGFK_KEY_UP){
			isPressedButton = IGBOOL_FALSE;
			switch(pSE->m_uEventID){
				case IGFK_5:
				case IGFK_CSK:
#if _IS_MTK_EMU_
					IGSystem_Exit();
#endif
				break;
			}
		}else if(pSE->m_uEventID == IGFK_TOUCH1_DOWN){
			if(IG_LA_isOnTouch(pSE->m_uData1,pSE->m_uData2,anchorX  - (texButton->m_width>>1),
				anchorY  + IG_LA_OPC_EXIT_OFFY - (texButton->m_height>>1),anchorX  + (texButton->m_width>>1),
				anchorY  + IG_LA_OPC_EXIT_OFFY + (texButton->m_height>>1))){
				isPressedButton = IGBOOL_TRUE;
			}
		}else if(pSE->m_uEventID == IGFK_TOUCH1_UP){
			isPressedButton = IGBOOL_FALSE;
			if(IG_LA_isOnTouch(pSE->m_uData1,pSE->m_uData2,anchorX  - (texButton->m_width>>1),
				anchorY + IG_LA_OPC_EXIT_OFFY - (texButton->m_height>>1),anchorX  + (texButton->m_width>>1),
				anchorY + IG_LA_OPC_EXIT_OFFY + (texButton->m_height>>1))){
#if _IS_MTK_EMU_
					IGSystem_Exit();
#endif
			}
		}

		pSE++;
	}
	return;
}


void IG_LA_OnPhoneCall_onEnd(void){
	IGTexture_destroy(&gs_mem,texCh5,&err);
	IGTexture_destroy(&gs_mem,texButton,&err);
	IGTexture_destroy(&gs_mem,texButton1,&err);
	IGTexture_destroy(&gs_mem,texCh4,&err);
	IGTexture_destroy(&gs_mem,texExit,&err);	

	IGMemoryPool_free(&gs_mem,(void *)texPoint,&err);
	IGMemoryPool_free(&gs_mem,(void *)texRect,&err);

	// Release renderer memory.
	IGRenderer_destroy(&gs_mem, gs_render, &err);

	IGMemoryPool_reset(&gs_mem,&err);

	// Release the memory the application allocated for the memory pool.
	IGMemoryPool_finalize(&gs_mem, &err);

	return;
}















//////////////////////////////////////////////g_uIsOnPhoneCall///////////////////////////////////////////////
