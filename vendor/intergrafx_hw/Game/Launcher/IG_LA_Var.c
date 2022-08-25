/**********************
*IG_Game_Var.c
*2011.10.31
*by vincent
*****************************/

#include "IG_LA_FactorDef.h"
#include "IGV5Game.h"
#include "IGV5Model.h"
#include "IG_LA_Struct.h"

#if _240_320_

int IG_Launcher_Width=240;
int IG_Launcher_High=320;

#elif _320_480_

int IG_Launcher_Width=320;
int IG_Launcher_High=480;

#elif _240_400_

int IG_Launcher_Width=240;
int IG_Launcher_High=400;

#elif _480_800_

int IG_Launcher_Width=480;
int IG_Launcher_High=800;

#endif

IGV5Rect IG_LA_Model_Button1={2,2,249,95};
IGV5Rect IG_LA_Model_Button1_Enter={2,96,249,189};
IGV5Rect IG_LA_Model_ExitButton={253,2,412,86};
IGV5Rect IG_LA_Model_ExitButton_Enter={253,87,412,171};
IGV5Rect IG_LA_Model_Game_Logo={253,175,413,236};
IGV5Rect IG_LA_Model_LeftButton={4,283,103,395};
IGV5Rect IG_LA_Model_LeftButton_Enter={104,283,203,395};
IGV5Rect IG_LA_Model_RightButton={204,283,303,395};
IGV5Rect IG_LA_Model_RightButton_Enter={304,283,403,395};
IGV5Rect IG_LA_Model_Company_Logo={4,398,435,506};
IGV5Rect IG_LA_Model_JE_Logo={0,512,255,767};
IGV5Rect IG_LA_Model_CW_Logo={256,512,511,767};
IGV5Rect IG_LA_Model_DA_Logo={0,768,255,1023};
IGV5Rect IG_LA_Model_TK_Logo={256,768,511,1023};
//CHS
IGV5Rect IG_LA_Model_DA_Word_CHS={0,0,233,44};
IGV5Rect IG_LA_Model_CW_Word_CHS={0,45,233,89};
IGV5Rect IG_LA_Model_JE_Word_CHS={0,90,233,134};
IGV5Rect IG_LA_Model_TK_Word_CHS={0,135,233,179};
IGV5Rect IG_LA_Model_Exit_Word_CHS={0,180,233,224};
IGV5Rect IG_LA_Model_Warning_Word_CHS={0,225,233,255};
//ENG
IGV5Rect IG_LA_Model_DA_Word_ENG={0,0,233,44};
IGV5Rect IG_LA_Model_CW_Word_ENG={0,45,233,89};
IGV5Rect IG_LA_Model_JE_Word_ENG={0,90,233,134};
IGV5Rect IG_LA_Model_TK_Word_ENG={0,135,233,179};
IGV5Rect IG_LA_Model_Exit_Word_ENG={0,180,233,224};
IGV5Rect IG_LA_Model_Warning_Word_ENG={2,191,234,262};
//LA×´Ì¬±êÖ¾Î»
char IG_LA_Status=0;
//Í¼Æ¬
IGV5Texture IG_LA_Word,IG_LA_Word_A,IG_LA_Some,IG_LA_Some_A,IG_LA_Background,IG_LA_Background_A;
//ÐéÄâ³ß´ç
IG_LA_Struct_Rect IG_LA_Real_Button1,IG_LA_Real_Button1_Enter,IG_LA_Real_ExitButton,IG_LA_Real_ExitButton_Enter;
IG_LA_Struct_Rect IG_LA_Real_Game_Logo,IG_LA_Real_LeftButton,IG_LA_Real_LeftButton_Enter,IG_LA_Real_RightButton,IG_LA_Real_RightButton_Enter;
IG_LA_Struct_Rect IG_LA_Disp_LeftButton,IG_LA_Disp_RightButton,IG_LA_Disp_Button1,IG_LA_Disp_ExitButton;
IG_LA_Struct_Rect IG_LA_Real_Company_Logo,IG_LA_Real_JE_Logo,IG_LA_Real_CW_Logo,IG_LA_Real_DA_Logo,IG_LA_Real_TK_Logo;
IG_LA_Struct_Rect IG_LA_Real_DA_Word,IG_LA_Real_CW_Word,IG_LA_Real_JE_Word,IG_LA_Real_TK_Word,IG_LA_Real_Exit_Word;
IG_LA_Struct_Rect IG_LA_Real_BackGround;
IG_LA_Struct_Rect IG_LA_Disp_Game_Logo,IG_LA_Disp_Game_Logo_M,IG_LA_Disp_Game_Word;
IG_LA_Struct_Rect IG_LA_Real_Warning_Word;
char IG_DA_Left_Flag,IG_DA_Right_Flag;
float IG_LA_Logo_MoveTime[2];
char IG_LA_LA_UI_Stats;
char IG_LA_UnloadFlag=0;
char IG_LA_LA_Stats=0;
char IG_LA_LA_NUM=0;
char IG_LA_Warning_Flag=0;
char IG_LA_English_Flag=0;
float IG_LA_Warning_Time=0;






