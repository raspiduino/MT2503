#ifndef __IG_LAUNCHER__VAR__H
#define __IG_LAUNCHER__VAR__H

#include "IGV5Texture.h"
#include "IG_LA_Struct.h"


extern int IG_Launcher_Width;
extern int IG_Launcher_High;
extern char IG_LA_Status;

extern IGV5Texture IG_LA_Word,IG_LA_Word_A,IG_LA_Some,IG_LA_Some_A,IG_LA_Background,IG_LA_Background_A;

extern IGV5Rect IG_LA_Model_Button1;
extern IGV5Rect IG_LA_Model_Button1_Enter;
extern IGV5Rect IG_LA_Model_ExitButton;
extern IGV5Rect IG_LA_Model_ExitButton_Enter;
extern IGV5Rect IG_LA_Model_Game_Logo;
extern IGV5Rect IG_LA_Model_LeftButton;
extern IGV5Rect IG_LA_Model_LeftButton_Enter;
extern IGV5Rect IG_LA_Model_RightButton;
extern IGV5Rect IG_LA_Model_RightButton_Enter;
extern IGV5Rect IG_LA_Model_Company_Logo;
extern IGV5Rect IG_LA_Model_JE_Logo;
extern IGV5Rect IG_LA_Model_CW_Logo;
extern IGV5Rect IG_LA_Model_DA_Logo;
extern IGV5Rect IG_LA_Model_TK_Logo;
//CHS
extern IGV5Rect IG_LA_Model_DA_Word_CHS;
extern IGV5Rect IG_LA_Model_CW_Word_CHS;
extern IGV5Rect IG_LA_Model_JE_Word_CHS;
extern IGV5Rect IG_LA_Model_TK_Word_CHS;
extern IGV5Rect IG_LA_Model_Exit_Word_CHS;
extern IGV5Rect IG_LA_Model_Warning_Word_CHS;
//ENG
extern IGV5Rect IG_LA_Model_DA_Word_ENG;
extern IGV5Rect IG_LA_Model_CW_Word_ENG;
extern IGV5Rect IG_LA_Model_JE_Word_ENG;
extern IGV5Rect IG_LA_Model_TK_Word_ENG;
extern IGV5Rect IG_LA_Model_Exit_Word_ENG;
extern IGV5Rect IG_LA_Model_Warning_Word_ENG;

extern IG_LA_Struct_Rect IG_LA_Real_Button1,IG_LA_Real_Button1_Enter,IG_LA_Real_ExitButton,IG_LA_Real_ExitButton_Enter;
extern IG_LA_Struct_Rect IG_LA_Real_Game_Logo,IG_LA_Real_LeftButton,IG_LA_Real_LeftButton_Enter,IG_LA_Real_RightButton,IG_LA_Real_RightButton_Enter;
extern IG_LA_Struct_Rect IG_LA_Real_Company_Logo,IG_LA_Real_JE_Logo,IG_LA_Real_CW_Logo,IG_LA_Real_DA_Logo,IG_LA_Real_TK_Logo;
extern IG_LA_Struct_Rect IG_LA_Real_DA_Word,IG_LA_Real_CW_Word,IG_LA_Real_JE_Word,IG_LA_Real_TK_Word,IG_LA_Real_Exit_Word;
extern IG_LA_Struct_Rect IG_LA_Real_BackGround;
extern IG_LA_Struct_Rect IG_LA_Disp_LeftButton,IG_LA_Disp_RightButton,IG_LA_Disp_Button1,IG_LA_Disp_ExitButton;
extern IG_LA_Struct_Rect IG_LA_Disp_Game_Logo,IG_LA_Disp_Game_Logo_M,IG_LA_Disp_Game_Word;
extern IG_LA_Struct_Rect IG_LA_Real_Warning_Word;
extern char IG_DA_Left_Flag,IG_DA_Right_Flag;
extern float IG_LA_Logo_MoveTime[2];
extern char IG_LA_LA_UI_Stats;
extern char IG_LA_UnloadFlag;
extern char IG_LA_LA_Stats;
extern char IG_LA_LA_NUM;
extern char IG_LA_Warning_Flag;
extern char IG_LA_English_Flag;
extern float IG_LA_Warning_Time;






#endif