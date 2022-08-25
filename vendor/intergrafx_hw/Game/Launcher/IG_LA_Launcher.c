
#include "IGV5Game.h"
#include "IGV5Shader.h"
#include "IGV5Matrix.h"
#include "IGV5Texture.h"
#include "IGV5Renderer.h"
#include "IGV5Camera.h"
#include "IGV5LoadPODModel.h"
#include "IG_LA_Function.h"
#include "IG_LA_TK.h"
#include "IG_LA_CW.h"
#include "IG_LA_DA5.h"
#include "IG_LA_JE.h"
#include "IG_LA_Var.h"
#include "IG_LA_Define.h"
#include "IG_LA_Resource.h"
#include "IG_LA_LA.h"


void IG_LA_InitTexureData()
{
#if _240_320_&&_CHS_

    IG_LA_Real_BackGround.Sx=0.7f;
    IG_LA_Real_BackGround.Sy=0.7f;
    IG_LA_Real_BackGround.LA_High=(int)(800*IG_LA_Real_BackGround.Sy);
    IG_LA_Real_BackGround.LA_Width=(int)(400*IG_LA_Real_BackGround.Sx);
    IG_LA_Real_BackGround.x=0;
    IG_LA_Real_BackGround.y=0;
    IG_LA_Real_BackGround.Lx=IG_LA_Real_BackGround.x+IG_LA_Real_BackGround.LA_Width;
    IG_LA_Real_BackGround.Ly=IG_LA_Real_BackGround.y+IG_LA_Real_BackGround.LA_High;


    IG_LA_Real_Button1.LA_position=IG_LA_Model_Button1;
    IG_LA_Real_Button1.Sx=0.5f;
    IG_LA_Real_Button1.Sy=0.5f;
    IG_LA_Real_Button1.LA_High=(int)((IG_LA_Model_Button1.m_iBottom-IG_LA_Model_Button1.m_iTop)*IG_LA_Real_Button1.Sy);
    IG_LA_Real_Button1.LA_Width=(int)((IG_LA_Model_Button1.m_iRight-IG_LA_Model_Button1.m_iLeft)*IG_LA_Real_Button1.Sx);
    IG_LA_Real_Button1.x=58;
    IG_LA_Real_Button1.y=215;
    IG_LA_Real_Button1.Lx=IG_LA_Real_Button1.x+IG_LA_Real_Button1.LA_Width;
    IG_LA_Real_Button1.Ly=IG_LA_Real_Button1.y+IG_LA_Real_Button1.LA_High;


    IG_LA_Real_Button1_Enter.LA_position=IG_LA_Model_Button1_Enter;
    IG_LA_Real_Button1_Enter.Sx=0.5f;
    IG_LA_Real_Button1_Enter.Sy=0.5f;
    IG_LA_Real_Button1_Enter.LA_High=(int)((IG_LA_Model_Button1_Enter.m_iBottom-IG_LA_Model_Button1_Enter.m_iTop)*IG_LA_Real_Button1_Enter.Sy);
    IG_LA_Real_Button1_Enter.LA_Width=(int)((IG_LA_Model_Button1_Enter.m_iRight-IG_LA_Model_Button1_Enter.m_iLeft)*IG_LA_Real_Button1_Enter.Sx);
    IG_LA_Real_Button1_Enter.x=58;
    IG_LA_Real_Button1_Enter.y=215;
    IG_LA_Real_Button1_Enter.Lx=IG_LA_Real_Button1_Enter.x+IG_LA_Real_Button1_Enter.LA_Width;
    IG_LA_Real_Button1_Enter.Ly=IG_LA_Real_Button1_Enter.y+IG_LA_Real_Button1_Enter.LA_High;


    IG_LA_Real_ExitButton.LA_position=IG_LA_Model_ExitButton;
    IG_LA_Real_ExitButton.Sx=0.5f;
    IG_LA_Real_ExitButton.Sy=0.5f;
    IG_LA_Real_ExitButton.LA_High=(int)((IG_LA_Model_ExitButton.m_iBottom-IG_LA_Model_ExitButton.m_iTop)*IG_LA_Real_ExitButton.Sy);
    IG_LA_Real_ExitButton.LA_Width=(int)((IG_LA_Model_ExitButton.m_iRight-IG_LA_Model_ExitButton.m_iLeft)*IG_LA_Real_ExitButton.Sx);
    IG_LA_Real_ExitButton.x=80;
    IG_LA_Real_ExitButton.y=270;
    IG_LA_Real_ExitButton.Lx=IG_LA_Real_ExitButton.x+IG_LA_Real_ExitButton.LA_Width;
    IG_LA_Real_ExitButton.Ly=IG_LA_Real_ExitButton.y+IG_LA_Real_ExitButton.LA_High;


    IG_LA_Real_ExitButton_Enter.LA_position=IG_LA_Model_ExitButton_Enter;
    IG_LA_Real_ExitButton_Enter.Sx=0.5f;
    IG_LA_Real_ExitButton_Enter.Sy=0.5f;
    IG_LA_Real_ExitButton_Enter.LA_High=(int)((IG_LA_Model_ExitButton_Enter.m_iBottom-IG_LA_Model_ExitButton_Enter.m_iTop)*IG_LA_Real_ExitButton_Enter.Sy);
    IG_LA_Real_ExitButton_Enter.LA_Width=(int)((IG_LA_Model_ExitButton_Enter.m_iRight-IG_LA_Model_ExitButton_Enter.m_iLeft)*IG_LA_Real_ExitButton_Enter.Sx);
    IG_LA_Real_ExitButton_Enter.x=80;
    IG_LA_Real_ExitButton_Enter.y=270;
    IG_LA_Real_ExitButton_Enter.Lx=IG_LA_Real_ExitButton_Enter.x+IG_LA_Real_ExitButton_Enter.LA_Width;
    IG_LA_Real_ExitButton_Enter.Ly=IG_LA_Real_ExitButton_Enter.y+IG_LA_Real_ExitButton_Enter.LA_High;


    IG_LA_Real_Game_Logo.LA_position=IG_LA_Model_Game_Logo;
    IG_LA_Real_Game_Logo.Sx=0.5f;
    IG_LA_Real_Game_Logo.Sy=0.5f;
    IG_LA_Real_Game_Logo.LA_High=(int)((IG_LA_Model_Game_Logo.m_iBottom-IG_LA_Model_Game_Logo.m_iTop)*IG_LA_Real_Game_Logo.Sy);
    IG_LA_Real_Game_Logo.LA_Width=(int)((IG_LA_Model_Game_Logo.m_iRight-IG_LA_Model_Game_Logo.m_iLeft)*IG_LA_Real_Game_Logo.Sx);
    IG_LA_Real_Game_Logo.x=130;
    IG_LA_Real_Game_Logo.y=48;
    IG_LA_Real_Game_Logo.Lx=IG_LA_Real_Game_Logo.x+IG_LA_Real_Game_Logo.LA_Width;
    IG_LA_Real_Game_Logo.Ly=IG_LA_Real_Game_Logo.y+IG_LA_Real_Game_Logo.LA_High;


    IG_LA_Real_LeftButton.LA_position=IG_LA_Model_LeftButton;
    IG_LA_Real_LeftButton.Sx=0.5f;
    IG_LA_Real_LeftButton.Sy=0.5f;
    IG_LA_Real_LeftButton.LA_High=(int)((IG_LA_Model_LeftButton.m_iBottom-IG_LA_Model_LeftButton.m_iTop)*IG_LA_Real_LeftButton.Sy);
    IG_LA_Real_LeftButton.LA_Width=(int)((IG_LA_Model_LeftButton.m_iRight-IG_LA_Model_LeftButton.m_iLeft)*IG_LA_Real_LeftButton.Sx);
    IG_LA_Real_LeftButton.x=0;
    IG_LA_Real_LeftButton.y=210;
    IG_LA_Real_LeftButton.Lx=IG_LA_Real_LeftButton.x+IG_LA_Real_LeftButton.LA_Width;
    IG_LA_Real_LeftButton.Ly=IG_LA_Real_LeftButton.y+IG_LA_Real_LeftButton.LA_High;


    IG_LA_Real_LeftButton_Enter.LA_position=IG_LA_Model_LeftButton_Enter;
    IG_LA_Real_LeftButton_Enter.Sx=0.5f;
    IG_LA_Real_LeftButton_Enter.Sy=0.5f;
    IG_LA_Real_LeftButton_Enter.LA_High=(int)((IG_LA_Model_LeftButton_Enter.m_iBottom-IG_LA_Model_LeftButton_Enter.m_iTop)*IG_LA_Real_LeftButton_Enter.Sy);
    IG_LA_Real_LeftButton_Enter.LA_Width=(int)((IG_LA_Model_LeftButton_Enter.m_iRight-IG_LA_Model_LeftButton_Enter.m_iLeft)*IG_LA_Real_LeftButton_Enter.Sx);
    IG_LA_Real_LeftButton_Enter.x=0;
    IG_LA_Real_LeftButton_Enter.y=210;
    IG_LA_Real_LeftButton_Enter.Lx=IG_LA_Real_LeftButton_Enter.x+IG_LA_Real_LeftButton_Enter.LA_Width;
    IG_LA_Real_LeftButton_Enter.Ly=IG_LA_Real_LeftButton_Enter.y+IG_LA_Real_LeftButton_Enter.LA_High;


    IG_LA_Real_RightButton.LA_position=IG_LA_Model_RightButton;	
    IG_LA_Real_RightButton.Sx=0.5f;
    IG_LA_Real_RightButton.Sy=0.5f;
    IG_LA_Real_RightButton.LA_High=(int)((IG_LA_Model_RightButton.m_iBottom-IG_LA_Model_RightButton.m_iTop)*IG_LA_Real_RightButton.Sy);
    IG_LA_Real_RightButton.LA_Width=(int)((IG_LA_Model_RightButton.m_iRight-IG_LA_Model_RightButton.m_iLeft)*IG_LA_Real_RightButton.Sx);
    IG_LA_Real_RightButton.x=190;
    IG_LA_Real_RightButton.y=210;
    IG_LA_Real_RightButton.Lx=IG_LA_Real_RightButton.x+IG_LA_Real_RightButton.LA_Width;
    IG_LA_Real_RightButton.Ly=IG_LA_Real_RightButton.y+IG_LA_Real_RightButton.LA_High;


    IG_LA_Real_RightButton_Enter.LA_position=IG_LA_Model_RightButton_Enter;
    IG_LA_Real_RightButton_Enter.Sx=0.5f;
    IG_LA_Real_RightButton_Enter.Sy=0.5f;
    IG_LA_Real_RightButton_Enter.LA_High=(int)((IG_LA_Model_RightButton_Enter.m_iBottom-IG_LA_Model_RightButton_Enter.m_iTop)*IG_LA_Real_RightButton_Enter.Sy);
    IG_LA_Real_RightButton_Enter.LA_Width=(int)((IG_LA_Model_RightButton_Enter.m_iRight-IG_LA_Model_RightButton_Enter.m_iLeft)*IG_LA_Real_RightButton_Enter.Sx);
    IG_LA_Real_RightButton_Enter.x=190;
    IG_LA_Real_RightButton_Enter.y=210;
    IG_LA_Real_RightButton_Enter.Lx=IG_LA_Real_RightButton_Enter.x+IG_LA_Real_RightButton_Enter.LA_Width;
    IG_LA_Real_RightButton_Enter.Ly=IG_LA_Real_RightButton_Enter.y+IG_LA_Real_RightButton_Enter.LA_High;


    IG_LA_Real_Company_Logo.LA_position=IG_LA_Model_Company_Logo;
    IG_LA_Real_Company_Logo.Sx=0.5f;
    IG_LA_Real_Company_Logo.Sy=0.5f;
    IG_LA_Real_Company_Logo.LA_High=(int)((IG_LA_Model_Company_Logo.m_iBottom-IG_LA_Model_Company_Logo.m_iTop)*IG_LA_Real_Company_Logo.Sy);
    IG_LA_Real_Company_Logo.LA_Width=(int)((IG_LA_Model_Company_Logo.m_iRight-IG_LA_Model_Company_Logo.m_iLeft)*IG_LA_Real_Company_Logo.Sx);
    IG_LA_Real_Company_Logo.x=11;
    IG_LA_Real_Company_Logo.y=0;
    IG_LA_Real_Company_Logo.Lx=IG_LA_Real_Company_Logo.x+IG_LA_Real_Company_Logo.LA_Width;
    IG_LA_Real_Company_Logo.Ly=IG_LA_Real_Company_Logo.y+IG_LA_Real_Company_Logo.LA_High;


    IG_LA_Real_JE_Logo.LA_position=IG_LA_Model_JE_Logo;
    IG_LA_Real_JE_Logo.Sx=0.5f;
    IG_LA_Real_JE_Logo.Sy=0.5f;
    IG_LA_Real_JE_Logo.LA_High=(int)((IG_LA_Model_JE_Logo.m_iBottom-IG_LA_Model_JE_Logo.m_iTop)*IG_LA_Real_JE_Logo.Sy);
    IG_LA_Real_JE_Logo.LA_Width=(int)((IG_LA_Model_JE_Logo.m_iRight-IG_LA_Model_JE_Logo.m_iLeft)*IG_LA_Real_JE_Logo.Sx);
    IG_LA_Real_JE_Logo.x=55;
    IG_LA_Real_JE_Logo.y=80;
    IG_LA_Real_JE_Logo.Lx=IG_LA_Real_JE_Logo.x+IG_LA_Real_JE_Logo.LA_Width;
    IG_LA_Real_JE_Logo.Ly=IG_LA_Real_JE_Logo.y+IG_LA_Real_JE_Logo.LA_High;


    IG_LA_Real_CW_Logo.LA_position=IG_LA_Model_CW_Logo;
    IG_LA_Real_CW_Logo.Sx=0.5f;
    IG_LA_Real_CW_Logo.Sy=0.5f;
    IG_LA_Real_CW_Logo.LA_High=(int)((IG_LA_Model_CW_Logo.m_iBottom-IG_LA_Model_CW_Logo.m_iTop)*IG_LA_Real_CW_Logo.Sy);
    IG_LA_Real_CW_Logo.LA_Width=(int)((IG_LA_Model_CW_Logo.m_iRight-IG_LA_Model_CW_Logo.m_iLeft)*IG_LA_Real_CW_Logo.Sx);
    IG_LA_Real_CW_Logo.x=55;
    IG_LA_Real_CW_Logo.y=80;
    IG_LA_Real_CW_Logo.Lx=IG_LA_Real_CW_Logo.x+IG_LA_Real_CW_Logo.LA_Width;
    IG_LA_Real_CW_Logo.Ly=IG_LA_Real_CW_Logo.y+IG_LA_Real_CW_Logo.LA_High;


    IG_LA_Real_DA_Logo.LA_position=IG_LA_Model_DA_Logo;
    IG_LA_Real_DA_Logo.Sx=0.5f;
    IG_LA_Real_DA_Logo.Sy=0.5f;
    IG_LA_Real_DA_Logo.LA_High=(int)((IG_LA_Model_DA_Logo.m_iBottom-IG_LA_Model_DA_Logo.m_iTop)*IG_LA_Real_DA_Logo.Sy);
    IG_LA_Real_DA_Logo.LA_Width=(int)((IG_LA_Model_DA_Logo.m_iRight-IG_LA_Model_DA_Logo.m_iLeft)*IG_LA_Real_DA_Logo.Sx);
    IG_LA_Real_DA_Logo.x=55;
    IG_LA_Real_DA_Logo.y=80;
    IG_LA_Real_DA_Logo.Lx=IG_LA_Real_DA_Logo.x+IG_LA_Real_DA_Logo.LA_Width;
    IG_LA_Real_DA_Logo.Ly=IG_LA_Real_DA_Logo.y+IG_LA_Real_DA_Logo.LA_High;


    IG_LA_Real_TK_Logo.LA_position=IG_LA_Model_TK_Logo;
    IG_LA_Real_TK_Logo.Sx=0.5f;
    IG_LA_Real_TK_Logo.Sy=0.5f;
    IG_LA_Real_TK_Logo.LA_High=(int)((IG_LA_Model_TK_Logo.m_iBottom-IG_LA_Model_TK_Logo.m_iTop)*IG_LA_Real_TK_Logo.Sy);
    IG_LA_Real_TK_Logo.LA_Width=(int)((IG_LA_Model_TK_Logo.m_iRight-IG_LA_Model_TK_Logo.m_iLeft)*IG_LA_Real_TK_Logo.Sx);
    IG_LA_Real_TK_Logo.x=55;
    IG_LA_Real_TK_Logo.y=80;
    IG_LA_Real_TK_Logo.Lx=IG_LA_Real_TK_Logo.x+IG_LA_Real_TK_Logo.LA_Width;
    IG_LA_Real_TK_Logo.Ly=IG_LA_Real_TK_Logo.y+IG_LA_Real_TK_Logo.LA_High;


    IG_LA_Real_DA_Word.LA_position=IG_LA_Model_DA_Word_CHS;
    IG_LA_Real_DA_Word.Sx=0.5f;
    IG_LA_Real_DA_Word.Sy=0.5f;
    IG_LA_Real_DA_Word.LA_High=(int)((IG_LA_Model_DA_Word_CHS.m_iBottom-IG_LA_Model_DA_Word_CHS.m_iTop)*IG_LA_Real_DA_Word.Sy);
    IG_LA_Real_DA_Word.LA_Width=(int)((IG_LA_Model_DA_Word_CHS.m_iRight-IG_LA_Model_DA_Word_CHS.m_iLeft)*IG_LA_Real_DA_Word.Sx);
    IG_LA_Real_DA_Word.x=60;
    IG_LA_Real_DA_Word.y=230;
    IG_LA_Real_DA_Word.Lx=IG_LA_Real_DA_Word.x+IG_LA_Real_DA_Word.LA_Width;
    IG_LA_Real_DA_Word.Ly=IG_LA_Real_DA_Word.y+IG_LA_Real_DA_Word.LA_High;


    IG_LA_Real_CW_Word.LA_position=IG_LA_Model_CW_Word_CHS;
    IG_LA_Real_CW_Word.Sx=0.5f;
    IG_LA_Real_CW_Word.Sy=0.5f;
    IG_LA_Real_CW_Word.LA_High=(int)((IG_LA_Model_CW_Word_CHS.m_iBottom-IG_LA_Model_CW_Word_CHS.m_iTop)*IG_LA_Real_CW_Word.Sy);
    IG_LA_Real_CW_Word.LA_Width=(int)((IG_LA_Model_CW_Word_CHS.m_iRight-IG_LA_Model_CW_Word_CHS.m_iLeft)*IG_LA_Real_CW_Word.Sx);
    IG_LA_Real_CW_Word.x=60;
    IG_LA_Real_CW_Word.y=230;
    IG_LA_Real_CW_Word.Lx=IG_LA_Real_CW_Word.x+IG_LA_Real_CW_Word.LA_Width;
    IG_LA_Real_CW_Word.Ly=IG_LA_Real_CW_Word.y+IG_LA_Real_CW_Word.LA_High;


    IG_LA_Real_JE_Word.LA_position=IG_LA_Model_JE_Word_CHS;
    IG_LA_Real_JE_Word.Sx=0.5f;
    IG_LA_Real_JE_Word.Sy=0.5f;
    IG_LA_Real_JE_Word.LA_High=(int)((IG_LA_Model_JE_Word_CHS.m_iBottom-IG_LA_Model_JE_Word_CHS.m_iTop)*IG_LA_Real_JE_Word.Sy);
    IG_LA_Real_JE_Word.LA_Width=(int)((IG_LA_Model_JE_Word_CHS.m_iRight-IG_LA_Model_JE_Word_CHS.m_iLeft)*IG_LA_Real_JE_Word.Sx);
    IG_LA_Real_JE_Word.x=60;
    IG_LA_Real_JE_Word.y=230;
    IG_LA_Real_JE_Word.Lx=IG_LA_Real_JE_Word.x+IG_LA_Real_JE_Word.LA_Width;
    IG_LA_Real_JE_Word.Ly=IG_LA_Real_JE_Word.y+IG_LA_Real_JE_Word.LA_High;


    IG_LA_Real_TK_Word.LA_position=IG_LA_Model_TK_Word_CHS;
    IG_LA_Real_TK_Word.Sx=0.5f;
    IG_LA_Real_TK_Word.Sy=0.5f;
    IG_LA_Real_TK_Word.LA_High=(int)((IG_LA_Model_TK_Word_CHS.m_iBottom-IG_LA_Model_TK_Word_CHS.m_iTop)*IG_LA_Real_TK_Word.Sy);
    IG_LA_Real_TK_Word.LA_Width=(int)((IG_LA_Model_TK_Word_CHS.m_iRight-IG_LA_Model_TK_Word_CHS.m_iLeft)*IG_LA_Real_TK_Word.Sx);
    IG_LA_Real_TK_Word.x=60;
    IG_LA_Real_TK_Word.y=230;
    IG_LA_Real_TK_Word.Lx=IG_LA_Real_TK_Word.x+IG_LA_Real_TK_Word.LA_Width;
    IG_LA_Real_TK_Word.Ly=IG_LA_Real_TK_Word.y+IG_LA_Real_TK_Word.LA_High;


    IG_LA_Real_Exit_Word.LA_position=IG_LA_Model_Exit_Word_CHS;
    IG_LA_Real_Exit_Word.Sx=0.5f;
    IG_LA_Real_Exit_Word.Sy=0.5f;
    IG_LA_Real_Exit_Word.LA_High=(int)((IG_LA_Model_Exit_Word_CHS.m_iBottom-IG_LA_Model_Exit_Word_CHS.m_iTop)*IG_LA_Real_Exit_Word.Sy);
    IG_LA_Real_Exit_Word.LA_Width=(int)((IG_LA_Model_Exit_Word_CHS.m_iRight-IG_LA_Model_Exit_Word_CHS.m_iLeft)*IG_LA_Real_Exit_Word.Sx);
    IG_LA_Real_Exit_Word.x=60;
    IG_LA_Real_Exit_Word.y=280;
    IG_LA_Real_Exit_Word.Lx=IG_LA_Real_Exit_Word.x+IG_LA_Real_Exit_Word.LA_Width;
    IG_LA_Real_Exit_Word.Ly=IG_LA_Real_Exit_Word.y+IG_LA_Real_Exit_Word.LA_High;

    IG_LA_Real_Warning_Word.LA_position=IG_LA_Model_Warning_Word_CHS;
    IG_LA_Real_Warning_Word.Sx=0.5f;
    IG_LA_Real_Warning_Word.Sy=0.5f;
    IG_LA_Real_Warning_Word.LA_High=(int)((IG_LA_Model_Warning_Word_CHS.m_iBottom-IG_LA_Model_Warning_Word_CHS.m_iTop)*IG_LA_Real_Exit_Word.Sy);
    IG_LA_Real_Warning_Word.LA_Width=(int)((IG_LA_Model_Warning_Word_CHS.m_iRight-IG_LA_Model_Warning_Word_CHS.m_iLeft)*IG_LA_Real_Exit_Word.Sx);
    IG_LA_Real_Warning_Word.x=60;
    IG_LA_Real_Warning_Word.y=130;
    IG_LA_Real_Warning_Word.Lx=IG_LA_Real_Warning_Word.x+IG_LA_Real_Warning_Word.LA_Width;
    IG_LA_Real_Warning_Word.Ly=IG_LA_Real_Warning_Word.y+IG_LA_Real_Warning_Word.LA_High;


	
#elif _240_320_&&_EN_
    
    IG_LA_English_Flag=1;

    IG_LA_Real_BackGround.Sx=0.7f;
    IG_LA_Real_BackGround.Sy=0.7f;
    IG_LA_Real_BackGround.LA_High=(int)(800*IG_LA_Real_BackGround.Sy);
    IG_LA_Real_BackGround.LA_Width=(int)(400*IG_LA_Real_BackGround.Sx);
    IG_LA_Real_BackGround.x=0;
    IG_LA_Real_BackGround.y=0;
    IG_LA_Real_BackGround.Lx=IG_LA_Real_BackGround.x+IG_LA_Real_BackGround.LA_Width;
    IG_LA_Real_BackGround.Ly=IG_LA_Real_BackGround.y+IG_LA_Real_BackGround.LA_High;

    IG_LA_Real_Button1.LA_position=IG_LA_Model_Button1;
    IG_LA_Real_Button1.Sx=0.5f;
    IG_LA_Real_Button1.Sy=0.5f;
    IG_LA_Real_Button1.LA_High=(int)((IG_LA_Model_Button1.m_iBottom-IG_LA_Model_Button1.m_iTop)*IG_LA_Real_Button1.Sy);
    IG_LA_Real_Button1.LA_Width=(int)((IG_LA_Model_Button1.m_iRight-IG_LA_Model_Button1.m_iLeft)*IG_LA_Real_Button1.Sx);
    IG_LA_Real_Button1.x=58;
    IG_LA_Real_Button1.y=215;
    IG_LA_Real_Button1.Lx=IG_LA_Real_Button1.x+IG_LA_Real_Button1.LA_Width;
    IG_LA_Real_Button1.Ly=IG_LA_Real_Button1.y+IG_LA_Real_Button1.LA_High;

    IG_LA_Real_Button1_Enter.LA_position=IG_LA_Model_Button1_Enter;
    IG_LA_Real_Button1_Enter.Sx=0.5f;
    IG_LA_Real_Button1_Enter.Sy=0.5f;
    IG_LA_Real_Button1_Enter.LA_High=(int)((IG_LA_Model_Button1_Enter.m_iBottom-IG_LA_Model_Button1_Enter.m_iTop)*IG_LA_Real_Button1_Enter.Sy);
    IG_LA_Real_Button1_Enter.LA_Width=(int)((IG_LA_Model_Button1_Enter.m_iRight-IG_LA_Model_Button1_Enter.m_iLeft)*IG_LA_Real_Button1_Enter.Sx);
    IG_LA_Real_Button1_Enter.x=58;
    IG_LA_Real_Button1_Enter.y=215;
    IG_LA_Real_Button1_Enter.Lx=IG_LA_Real_Button1_Enter.x+IG_LA_Real_Button1_Enter.LA_Width;
    IG_LA_Real_Button1_Enter.Ly=IG_LA_Real_Button1_Enter.y+IG_LA_Real_Button1_Enter.LA_High;


    IG_LA_Real_ExitButton.LA_position=IG_LA_Model_ExitButton;
    IG_LA_Real_ExitButton.Sx=0.5f;
    IG_LA_Real_ExitButton.Sy=0.5f;
    IG_LA_Real_ExitButton.LA_High=(int)((IG_LA_Model_ExitButton.m_iBottom-IG_LA_Model_ExitButton.m_iTop)*IG_LA_Real_ExitButton.Sy);
    IG_LA_Real_ExitButton.LA_Width=(int)((IG_LA_Model_ExitButton.m_iRight-IG_LA_Model_ExitButton.m_iLeft)*IG_LA_Real_ExitButton.Sx);
    IG_LA_Real_ExitButton.x=80;
    IG_LA_Real_ExitButton.y=270;
    IG_LA_Real_ExitButton.Lx=IG_LA_Real_ExitButton.x+IG_LA_Real_ExitButton.LA_Width;
    IG_LA_Real_ExitButton.Ly=IG_LA_Real_ExitButton.y+IG_LA_Real_ExitButton.LA_High;


    IG_LA_Real_ExitButton_Enter.LA_position=IG_LA_Model_ExitButton_Enter;
    IG_LA_Real_ExitButton_Enter.Sx=0.5f;
    IG_LA_Real_ExitButton_Enter.Sy=0.5f;
    IG_LA_Real_ExitButton_Enter.LA_High=(int)((IG_LA_Model_ExitButton_Enter.m_iBottom-IG_LA_Model_ExitButton_Enter.m_iTop)*IG_LA_Real_ExitButton_Enter.Sy);
    IG_LA_Real_ExitButton_Enter.LA_Width=(int)((IG_LA_Model_ExitButton_Enter.m_iRight-IG_LA_Model_ExitButton_Enter.m_iLeft)*IG_LA_Real_ExitButton_Enter.Sx);
    IG_LA_Real_ExitButton_Enter.x=80;
    IG_LA_Real_ExitButton_Enter.y=270;
    IG_LA_Real_ExitButton_Enter.Lx=IG_LA_Real_ExitButton_Enter.x+IG_LA_Real_ExitButton_Enter.LA_Width;
    IG_LA_Real_ExitButton_Enter.Ly=IG_LA_Real_ExitButton_Enter.y+IG_LA_Real_ExitButton_Enter.LA_High;



    IG_LA_Real_Game_Logo.LA_position=IG_LA_Model_Game_Logo;
    IG_LA_Real_Game_Logo.Sx=0.5f;
    IG_LA_Real_Game_Logo.Sy=0.5f;
    IG_LA_Real_Game_Logo.LA_High=(int)((IG_LA_Model_Game_Logo.m_iBottom-IG_LA_Model_Game_Logo.m_iTop)*IG_LA_Real_Game_Logo.Sy);
    IG_LA_Real_Game_Logo.LA_Width=(int)((IG_LA_Model_Game_Logo.m_iRight-IG_LA_Model_Game_Logo.m_iLeft)*IG_LA_Real_Game_Logo.Sx);
    IG_LA_Real_Game_Logo.x=130;
    IG_LA_Real_Game_Logo.y=48;
    IG_LA_Real_Game_Logo.Lx=IG_LA_Real_Game_Logo.x+IG_LA_Real_Game_Logo.LA_Width;
    IG_LA_Real_Game_Logo.Ly=IG_LA_Real_Game_Logo.y+IG_LA_Real_Game_Logo.LA_High;


    IG_LA_Real_LeftButton.LA_position=IG_LA_Model_LeftButton;
    IG_LA_Real_LeftButton.Sx=0.5f;
    IG_LA_Real_LeftButton.Sy=0.5f;
    IG_LA_Real_LeftButton.LA_High=(int)((IG_LA_Model_LeftButton.m_iBottom-IG_LA_Model_LeftButton.m_iTop)*IG_LA_Real_LeftButton.Sy);
    IG_LA_Real_LeftButton.LA_Width=(int)((IG_LA_Model_LeftButton.m_iRight-IG_LA_Model_LeftButton.m_iLeft)*IG_LA_Real_LeftButton.Sx);
    IG_LA_Real_LeftButton.x=0;
    IG_LA_Real_LeftButton.y=210;
    IG_LA_Real_LeftButton.Lx=IG_LA_Real_LeftButton.x+IG_LA_Real_LeftButton.LA_Width;
    IG_LA_Real_LeftButton.Ly=IG_LA_Real_LeftButton.y+IG_LA_Real_LeftButton.LA_High;


    IG_LA_Real_LeftButton_Enter.LA_position=IG_LA_Model_LeftButton_Enter;
    IG_LA_Real_LeftButton_Enter.Sx=0.5f;
    IG_LA_Real_LeftButton_Enter.Sy=0.5f;
    IG_LA_Real_LeftButton_Enter.LA_High=(int)((IG_LA_Model_LeftButton_Enter.m_iBottom-IG_LA_Model_LeftButton_Enter.m_iTop)*IG_LA_Real_LeftButton_Enter.Sy);
    IG_LA_Real_LeftButton_Enter.LA_Width=(int)((IG_LA_Model_LeftButton_Enter.m_iRight-IG_LA_Model_LeftButton_Enter.m_iLeft)*IG_LA_Real_LeftButton_Enter.Sx);
    IG_LA_Real_LeftButton_Enter.x=0;
    IG_LA_Real_LeftButton_Enter.y=210;
    IG_LA_Real_LeftButton_Enter.Lx=IG_LA_Real_LeftButton_Enter.x+IG_LA_Real_LeftButton_Enter.LA_Width;
    IG_LA_Real_LeftButton_Enter.Ly=IG_LA_Real_LeftButton_Enter.y+IG_LA_Real_LeftButton_Enter.LA_High;


    IG_LA_Real_RightButton.LA_position=IG_LA_Model_RightButton;
    IG_LA_Real_RightButton.Sx=0.5f;
    IG_LA_Real_RightButton.Sy=0.5f;
    IG_LA_Real_RightButton.LA_High=(int)((IG_LA_Model_RightButton.m_iBottom-IG_LA_Model_RightButton.m_iTop)*IG_LA_Real_RightButton.Sy);
    IG_LA_Real_RightButton.LA_Width=(int)((IG_LA_Model_RightButton.m_iRight-IG_LA_Model_RightButton.m_iLeft)*IG_LA_Real_RightButton.Sx);
    IG_LA_Real_RightButton.x=190;
    IG_LA_Real_RightButton.y=210;
    IG_LA_Real_RightButton.Lx=IG_LA_Real_RightButton.x+IG_LA_Real_RightButton.LA_Width;
    IG_LA_Real_RightButton.Ly=IG_LA_Real_RightButton.y+IG_LA_Real_RightButton.LA_High;


    IG_LA_Real_RightButton_Enter.LA_position=IG_LA_Model_RightButton_Enter;
    IG_LA_Real_RightButton_Enter.Sx=0.5f;
    IG_LA_Real_RightButton_Enter.Sy=0.5f;
    IG_LA_Real_RightButton_Enter.LA_High=(int)((IG_LA_Model_RightButton_Enter.m_iBottom-IG_LA_Model_RightButton_Enter.m_iTop)*IG_LA_Real_RightButton_Enter.Sy);
    IG_LA_Real_RightButton_Enter.LA_Width=(int)((IG_LA_Model_RightButton_Enter.m_iRight-IG_LA_Model_RightButton_Enter.m_iLeft)*IG_LA_Real_RightButton_Enter.Sx);
    IG_LA_Real_RightButton_Enter.x=190;
    IG_LA_Real_RightButton_Enter.y=210;
    IG_LA_Real_RightButton_Enter.Lx=IG_LA_Real_RightButton_Enter.x+IG_LA_Real_RightButton_Enter.LA_Width;
    IG_LA_Real_RightButton_Enter.Ly=IG_LA_Real_RightButton_Enter.y+IG_LA_Real_RightButton_Enter.LA_High;


    IG_LA_Real_Company_Logo.LA_position=IG_LA_Model_Company_Logo;
    IG_LA_Real_Company_Logo.Sx=0.5f;
    IG_LA_Real_Company_Logo.Sy=0.5f;
    IG_LA_Real_Company_Logo.LA_High=(int)((IG_LA_Model_Company_Logo.m_iBottom-IG_LA_Model_Company_Logo.m_iTop)*IG_LA_Real_Company_Logo.Sy);
    IG_LA_Real_Company_Logo.LA_Width=(int)((IG_LA_Model_Company_Logo.m_iRight-IG_LA_Model_Company_Logo.m_iLeft)*IG_LA_Real_Company_Logo.Sx);
    IG_LA_Real_Company_Logo.x=11;
    IG_LA_Real_Company_Logo.y=0;
    IG_LA_Real_Company_Logo.Lx=IG_LA_Real_Company_Logo.x+IG_LA_Real_Company_Logo.LA_Width;
    IG_LA_Real_Company_Logo.Ly=IG_LA_Real_Company_Logo.y+IG_LA_Real_Company_Logo.LA_High;


    IG_LA_Real_JE_Logo.LA_position=IG_LA_Model_JE_Logo;
    IG_LA_Real_JE_Logo.Sx=0.5f;
    IG_LA_Real_JE_Logo.Sy=0.5f;
    IG_LA_Real_JE_Logo.LA_High=(int)((IG_LA_Model_JE_Logo.m_iBottom-IG_LA_Model_JE_Logo.m_iTop)*IG_LA_Real_JE_Logo.Sy);
    IG_LA_Real_JE_Logo.LA_Width=(int)((IG_LA_Model_JE_Logo.m_iRight-IG_LA_Model_JE_Logo.m_iLeft)*IG_LA_Real_JE_Logo.Sx);
    IG_LA_Real_JE_Logo.x=55;
    IG_LA_Real_JE_Logo.y=80;
    IG_LA_Real_JE_Logo.Lx=IG_LA_Real_JE_Logo.x+IG_LA_Real_JE_Logo.LA_Width;
    IG_LA_Real_JE_Logo.Ly=IG_LA_Real_JE_Logo.y+IG_LA_Real_JE_Logo.LA_High;


    IG_LA_Real_CW_Logo.LA_position=IG_LA_Model_CW_Logo;
    IG_LA_Real_CW_Logo.Sx=0.5f;
    IG_LA_Real_CW_Logo.Sy=0.5f;
    IG_LA_Real_CW_Logo.LA_High=(int)((IG_LA_Model_CW_Logo.m_iBottom-IG_LA_Model_CW_Logo.m_iTop)*IG_LA_Real_CW_Logo.Sy);
    IG_LA_Real_CW_Logo.LA_Width=(int)((IG_LA_Model_CW_Logo.m_iRight-IG_LA_Model_CW_Logo.m_iLeft)*IG_LA_Real_CW_Logo.Sx);
    IG_LA_Real_CW_Logo.x=55;
    IG_LA_Real_CW_Logo.y=80;
    IG_LA_Real_CW_Logo.Lx=IG_LA_Real_CW_Logo.x+IG_LA_Real_CW_Logo.LA_Width;
    IG_LA_Real_CW_Logo.Ly=IG_LA_Real_CW_Logo.y+IG_LA_Real_CW_Logo.LA_High;


    IG_LA_Real_DA_Logo.LA_position=IG_LA_Model_DA_Logo;
    IG_LA_Real_DA_Logo.Sx=0.5f;
    IG_LA_Real_DA_Logo.Sy=0.5f;
    IG_LA_Real_DA_Logo.LA_High=(int)((IG_LA_Model_DA_Logo.m_iBottom-IG_LA_Model_DA_Logo.m_iTop)*IG_LA_Real_DA_Logo.Sy);
    IG_LA_Real_DA_Logo.LA_Width=(int)((IG_LA_Model_DA_Logo.m_iRight-IG_LA_Model_DA_Logo.m_iLeft)*IG_LA_Real_DA_Logo.Sx);
    IG_LA_Real_DA_Logo.x=55;
    IG_LA_Real_DA_Logo.y=80;
    IG_LA_Real_DA_Logo.Lx=IG_LA_Real_DA_Logo.x+IG_LA_Real_DA_Logo.LA_Width;
    IG_LA_Real_DA_Logo.Ly=IG_LA_Real_DA_Logo.y+IG_LA_Real_DA_Logo.LA_High;


    IG_LA_Real_TK_Logo.LA_position=IG_LA_Model_TK_Logo;
    IG_LA_Real_TK_Logo.Sx=0.5f;
    IG_LA_Real_TK_Logo.Sy=0.5f;
    IG_LA_Real_TK_Logo.LA_High=(int)((IG_LA_Model_TK_Logo.m_iBottom-IG_LA_Model_TK_Logo.m_iTop)*IG_LA_Real_TK_Logo.Sy);
    IG_LA_Real_TK_Logo.LA_Width=(int)((IG_LA_Model_TK_Logo.m_iRight-IG_LA_Model_TK_Logo.m_iLeft)*IG_LA_Real_TK_Logo.Sx);
    IG_LA_Real_TK_Logo.x=55;
    IG_LA_Real_TK_Logo.y=80;
    IG_LA_Real_TK_Logo.Lx=IG_LA_Real_TK_Logo.x+IG_LA_Real_TK_Logo.LA_Width;
    IG_LA_Real_TK_Logo.Ly=IG_LA_Real_TK_Logo.y+IG_LA_Real_TK_Logo.LA_High;


    IG_LA_Real_DA_Word.LA_position=IG_LA_Model_DA_Word_ENG;
    IG_LA_Real_DA_Word.Sx=0.5f;
    IG_LA_Real_DA_Word.Sy=0.5f;
    IG_LA_Real_DA_Word.LA_High=(int)((IG_LA_Model_DA_Word_ENG.m_iBottom-IG_LA_Model_DA_Word_ENG.m_iTop)*IG_LA_Real_DA_Word.Sy);
    IG_LA_Real_DA_Word.LA_Width=(int)((IG_LA_Model_DA_Word_ENG.m_iRight-IG_LA_Model_DA_Word_ENG.m_iLeft)*IG_LA_Real_DA_Word.Sx);
    IG_LA_Real_DA_Word.x=60;
    IG_LA_Real_DA_Word.y=230;
    IG_LA_Real_DA_Word.Lx=IG_LA_Real_DA_Word.x+IG_LA_Real_DA_Word.LA_Width;
    IG_LA_Real_DA_Word.Ly=IG_LA_Real_DA_Word.y+IG_LA_Real_DA_Word.LA_High;


    IG_LA_Real_CW_Word.LA_position=IG_LA_Model_CW_Word_ENG;
    IG_LA_Real_CW_Word.Sx=0.5f;
    IG_LA_Real_CW_Word.Sy=0.5f;
    IG_LA_Real_CW_Word.LA_High=(int)((IG_LA_Model_CW_Word_ENG.m_iBottom-IG_LA_Model_CW_Word_ENG.m_iTop)*IG_LA_Real_CW_Word.Sy);
    IG_LA_Real_CW_Word.LA_Width=(int)((IG_LA_Model_CW_Word_ENG.m_iRight-IG_LA_Model_CW_Word_ENG.m_iLeft)*IG_LA_Real_CW_Word.Sx);
    IG_LA_Real_CW_Word.x=60;
    IG_LA_Real_CW_Word.y=230;
    IG_LA_Real_CW_Word.Lx=IG_LA_Real_CW_Word.x+IG_LA_Real_CW_Word.LA_Width;
    IG_LA_Real_CW_Word.Ly=IG_LA_Real_CW_Word.y+IG_LA_Real_CW_Word.LA_High;


    IG_LA_Real_JE_Word.LA_position=IG_LA_Model_JE_Word_ENG;
    IG_LA_Real_JE_Word.Sx=0.5f;
    IG_LA_Real_JE_Word.Sy=0.5f;
    IG_LA_Real_JE_Word.LA_High=(int)((IG_LA_Model_JE_Word_ENG.m_iBottom-IG_LA_Model_JE_Word_ENG.m_iTop)*IG_LA_Real_JE_Word.Sy);
    IG_LA_Real_JE_Word.LA_Width=(int)((IG_LA_Model_JE_Word_ENG.m_iRight-IG_LA_Model_JE_Word_ENG.m_iLeft)*IG_LA_Real_JE_Word.Sx);
    IG_LA_Real_JE_Word.x=60;
    IG_LA_Real_JE_Word.y=230;
	IG_LA_Real_JE_Word.Lx=IG_LA_Real_JE_Word.x+IG_LA_Real_JE_Word.LA_Width;
    IG_LA_Real_JE_Word.Ly=IG_LA_Real_JE_Word.y+IG_LA_Real_JE_Word.LA_High;


    IG_LA_Real_TK_Word.LA_position=IG_LA_Model_TK_Word_ENG;
    IG_LA_Real_TK_Word.Sx=0.5f;
    IG_LA_Real_TK_Word.Sy=0.5f;
    IG_LA_Real_TK_Word.LA_High=(int)((IG_LA_Model_TK_Word_ENG.m_iBottom-IG_LA_Model_TK_Word_ENG.m_iTop)*IG_LA_Real_TK_Word.Sy);
    IG_LA_Real_TK_Word.LA_Width=(int)((IG_LA_Model_TK_Word_ENG.m_iRight-IG_LA_Model_TK_Word_ENG.m_iLeft)*IG_LA_Real_TK_Word.Sx);
    IG_LA_Real_TK_Word.x=60;
    IG_LA_Real_TK_Word.y=230;
    IG_LA_Real_TK_Word.Lx=IG_LA_Real_TK_Word.x+IG_LA_Real_TK_Word.LA_Width;
    IG_LA_Real_TK_Word.Ly=IG_LA_Real_TK_Word.y+IG_LA_Real_TK_Word.LA_High;


    IG_LA_Real_Exit_Word.LA_position=IG_LA_Model_Exit_Word_ENG;
    IG_LA_Real_Exit_Word.Sx=0.5f;
    IG_LA_Real_Exit_Word.Sy=0.5f;
    IG_LA_Real_Exit_Word.LA_High=(int)((IG_LA_Model_Exit_Word_ENG.m_iBottom-IG_LA_Model_Exit_Word_ENG.m_iTop)*IG_LA_Real_Exit_Word.Sy);
    IG_LA_Real_Exit_Word.LA_Width=(int)((IG_LA_Model_Exit_Word_ENG.m_iRight-IG_LA_Model_Exit_Word_ENG.m_iLeft)*IG_LA_Real_Exit_Word.Sx);
    IG_LA_Real_Exit_Word.x=60;
    IG_LA_Real_Exit_Word.y=280;
    IG_LA_Real_Exit_Word.Lx=IG_LA_Real_Exit_Word.x+IG_LA_Real_Exit_Word.LA_Width;
    IG_LA_Real_Exit_Word.Ly=IG_LA_Real_Exit_Word.y+IG_LA_Real_Exit_Word.LA_High;

    IG_LA_Real_Warning_Word.LA_position=IG_LA_Model_Warning_Word_ENG;
    IG_LA_Real_Warning_Word.Sx=0.5f;
    IG_LA_Real_Warning_Word.Sy=0.5f;
    IG_LA_Real_Warning_Word.LA_High=(int)((IG_LA_Model_Warning_Word_CHS.m_iBottom-IG_LA_Model_Warning_Word_CHS.m_iTop)*IG_LA_Real_Exit_Word.Sy);
    IG_LA_Real_Warning_Word.LA_Width=(int)((IG_LA_Model_Warning_Word_CHS.m_iRight-IG_LA_Model_Warning_Word_CHS.m_iLeft)*IG_LA_Real_Exit_Word.Sx);
    IG_LA_Real_Warning_Word.x=60;
    IG_LA_Real_Warning_Word.y=130;
    IG_LA_Real_Warning_Word.Lx=IG_LA_Real_Warning_Word.x+IG_LA_Real_Warning_Word.LA_Width;
    IG_LA_Real_Warning_Word.Ly=IG_LA_Real_Warning_Word.y+IG_LA_Real_Warning_Word.LA_High;


#elif _320_480_&&_CHS_

    IG_LA_Real_BackGround.Sx=0.7f;
    IG_LA_Real_BackGround.Sy=0.7f;
    IG_LA_Real_BackGround.LA_High=(int)(800*IG_LA_Real_BackGround.Sy);
    IG_LA_Real_BackGround.LA_Width=(int)(400*IG_LA_Real_BackGround.Sx);
    IG_LA_Real_BackGround.x=0;
    IG_LA_Real_BackGround.y=0;
    IG_LA_Real_BackGround.Lx=IG_LA_Real_BackGround.x+IG_LA_Real_BackGround.LA_Width;
    IG_LA_Real_BackGround.Ly=IG_LA_Real_BackGround.y+IG_LA_Real_BackGround.LA_High;


    IG_LA_Real_Button1.LA_position=IG_LA_Model_Button1;
    IG_LA_Real_Button1.Sx=0.7f;
    IG_LA_Real_Button1.Sy=0.7f;
    IG_LA_Real_Button1.LA_High=(int)((IG_LA_Model_Button1.m_iBottom-IG_LA_Model_Button1.m_iTop)*IG_LA_Real_Button1.Sy);
    IG_LA_Real_Button1.LA_Width=(int)((IG_LA_Model_Button1.m_iRight-IG_LA_Model_Button1.m_iLeft)*IG_LA_Real_Button1.Sx);
    IG_LA_Real_Button1.x=73;
    IG_LA_Real_Button1.y=334;
    IG_LA_Real_Button1.Lx=IG_LA_Real_Button1.x+IG_LA_Real_Button1.LA_Width;
    IG_LA_Real_Button1.Ly=IG_LA_Real_Button1.y+IG_LA_Real_Button1.LA_High;


    IG_LA_Real_Button1_Enter.LA_position=IG_LA_Model_Button1_Enter;
    IG_LA_Real_Button1_Enter.Sx=0.7f;
    IG_LA_Real_Button1_Enter.Sy=0.7f;
    IG_LA_Real_Button1_Enter.LA_High=(int)((IG_LA_Model_Button1_Enter.m_iBottom-IG_LA_Model_Button1_Enter.m_iTop)*IG_LA_Real_Button1_Enter.Sy);
    IG_LA_Real_Button1_Enter.LA_Width=(int)((IG_LA_Model_Button1_Enter.m_iRight-IG_LA_Model_Button1_Enter.m_iLeft)*IG_LA_Real_Button1_Enter.Sx);
    IG_LA_Real_Button1_Enter.x=73;
    IG_LA_Real_Button1_Enter.y=334;
    IG_LA_Real_Button1_Enter.Lx=IG_LA_Real_Button1_Enter.x+IG_LA_Real_Button1_Enter.LA_Width;
    IG_LA_Real_Button1_Enter.Ly=IG_LA_Real_Button1_Enter.y+IG_LA_Real_Button1_Enter.LA_High;


    IG_LA_Real_ExitButton.LA_position=IG_LA_Model_ExitButton;
    IG_LA_Real_ExitButton.Sx=0.7f;
    IG_LA_Real_ExitButton.Sy=0.7f;
    IG_LA_Real_ExitButton.LA_High=(int)((IG_LA_Model_ExitButton.m_iBottom-IG_LA_Model_ExitButton.m_iTop)*IG_LA_Real_ExitButton.Sy);
    IG_LA_Real_ExitButton.LA_Width=(int)((IG_LA_Model_ExitButton.m_iRight-IG_LA_Model_ExitButton.m_iLeft)*IG_LA_Real_ExitButton.Sx);
    IG_LA_Real_ExitButton.x=106;
    IG_LA_Real_ExitButton.y=412;
    IG_LA_Real_ExitButton.Lx=IG_LA_Real_ExitButton.x+IG_LA_Real_ExitButton.LA_Width;
    IG_LA_Real_ExitButton.Ly=IG_LA_Real_ExitButton.y+IG_LA_Real_ExitButton.LA_High;


    IG_LA_Real_ExitButton_Enter.LA_position=IG_LA_Model_ExitButton_Enter;
    IG_LA_Real_ExitButton_Enter.Sx=0.7f;
    IG_LA_Real_ExitButton_Enter.Sy=0.7f;
    IG_LA_Real_ExitButton_Enter.LA_High=(int)((IG_LA_Model_ExitButton_Enter.m_iBottom-IG_LA_Model_ExitButton_Enter.m_iTop)*IG_LA_Real_ExitButton_Enter.Sy);
    IG_LA_Real_ExitButton_Enter.LA_Width=(int)((IG_LA_Model_ExitButton_Enter.m_iRight-IG_LA_Model_ExitButton_Enter.m_iLeft)*IG_LA_Real_ExitButton_Enter.Sx);
    IG_LA_Real_ExitButton_Enter.x=106;
    IG_LA_Real_ExitButton_Enter.y=412;
    IG_LA_Real_ExitButton_Enter.Lx=IG_LA_Real_ExitButton_Enter.x+IG_LA_Real_ExitButton_Enter.LA_Width;
    IG_LA_Real_ExitButton_Enter.Ly=IG_LA_Real_ExitButton_Enter.y+IG_LA_Real_ExitButton_Enter.LA_High;


    IG_LA_Real_Game_Logo.LA_position=IG_LA_Model_Game_Logo;
    IG_LA_Real_Game_Logo.Sx=0.7f;
    IG_LA_Real_Game_Logo.Sy=0.7f;
    IG_LA_Real_Game_Logo.LA_High=(int)((IG_LA_Model_Game_Logo.m_iBottom-IG_LA_Model_Game_Logo.m_iTop)*IG_LA_Real_Game_Logo.Sy);
    IG_LA_Real_Game_Logo.LA_Width=(int)((IG_LA_Model_Game_Logo.m_iRight-IG_LA_Model_Game_Logo.m_iLeft)*IG_LA_Real_Game_Logo.Sx);
    IG_LA_Real_Game_Logo.x=173;
    IG_LA_Real_Game_Logo.y=95;
    IG_LA_Real_Game_Logo.Lx=IG_LA_Real_Game_Logo.x+IG_LA_Real_Game_Logo.LA_Width;
    IG_LA_Real_Game_Logo.Ly=IG_LA_Real_Game_Logo.y+IG_LA_Real_Game_Logo.LA_High;


    IG_LA_Real_LeftButton.LA_position=IG_LA_Model_LeftButton;
    IG_LA_Real_LeftButton.Sx=0.7f;
    IG_LA_Real_LeftButton.Sy=0.7f;
    IG_LA_Real_LeftButton.LA_High=(int)((IG_LA_Model_LeftButton.m_iBottom-IG_LA_Model_LeftButton.m_iTop)*IG_LA_Real_LeftButton.Sy);
	IG_LA_Real_LeftButton.LA_Width=(int)((IG_LA_Model_LeftButton.m_iRight-IG_LA_Model_LeftButton.m_iLeft)*IG_LA_Real_LeftButton.Sx);
	IG_LA_Real_LeftButton.x=0;
	IG_LA_Real_LeftButton.y=324;
	IG_LA_Real_LeftButton.Lx=IG_LA_Real_LeftButton.x+IG_LA_Real_LeftButton.LA_Width;
	IG_LA_Real_LeftButton.Ly=IG_LA_Real_LeftButton.y+IG_LA_Real_LeftButton.LA_High;


	IG_LA_Real_LeftButton_Enter.LA_position=IG_LA_Model_LeftButton_Enter;
	IG_LA_Real_LeftButton_Enter.Sx=0.7f;
	IG_LA_Real_LeftButton_Enter.Sy=0.7f;
	IG_LA_Real_LeftButton_Enter.LA_High=(int)((IG_LA_Model_LeftButton_Enter.m_iBottom-IG_LA_Model_LeftButton_Enter.m_iTop)*IG_LA_Real_LeftButton_Enter.Sy);
	IG_LA_Real_LeftButton_Enter.LA_Width=(int)((IG_LA_Model_LeftButton_Enter.m_iRight-IG_LA_Model_LeftButton_Enter.m_iLeft)*IG_LA_Real_LeftButton_Enter.Sx);
	IG_LA_Real_LeftButton_Enter.x=0;
	IG_LA_Real_LeftButton_Enter.y=324;
	IG_LA_Real_LeftButton_Enter.Lx=IG_LA_Real_LeftButton_Enter.x+IG_LA_Real_LeftButton_Enter.LA_Width;
	IG_LA_Real_LeftButton_Enter.Ly=IG_LA_Real_LeftButton_Enter.y+IG_LA_Real_LeftButton_Enter.LA_High;


    IG_LA_Real_RightButton.LA_position=IG_LA_Model_RightButton;	
    IG_LA_Real_RightButton.Sx=0.7f;
    IG_LA_Real_RightButton.Sy=0.7f;
    IG_LA_Real_RightButton.LA_High=(int)((IG_LA_Model_RightButton.m_iBottom-IG_LA_Model_RightButton.m_iTop)*IG_LA_Real_RightButton.Sy);
    IG_LA_Real_RightButton.LA_Width=(int)((IG_LA_Model_RightButton.m_iRight-IG_LA_Model_RightButton.m_iLeft)*IG_LA_Real_RightButton.Sx);
    IG_LA_Real_RightButton.x=250;
    IG_LA_Real_RightButton.y=324;
    IG_LA_Real_RightButton.Lx=IG_LA_Real_RightButton.x+IG_LA_Real_RightButton.LA_Width;
    IG_LA_Real_RightButton.Ly=IG_LA_Real_RightButton.y+IG_LA_Real_RightButton.LA_High;

    IG_LA_Real_RightButton_Enter.LA_position=IG_LA_Model_RightButton_Enter;
    IG_LA_Real_RightButton_Enter.Sx=0.7f;
    IG_LA_Real_RightButton_Enter.Sy=0.7f;
    IG_LA_Real_RightButton_Enter.LA_High=(int)((IG_LA_Model_RightButton_Enter.m_iBottom-IG_LA_Model_RightButton_Enter.m_iTop)*IG_LA_Real_RightButton_Enter.Sy);
    IG_LA_Real_RightButton_Enter.LA_Width=(int)((IG_LA_Model_RightButton_Enter.m_iRight-IG_LA_Model_RightButton_Enter.m_iLeft)*IG_LA_Real_RightButton_Enter.Sx);
    IG_LA_Real_RightButton_Enter.x=250;
    IG_LA_Real_RightButton_Enter.y=324;
	IG_LA_Real_RightButton_Enter.Lx=IG_LA_Real_RightButton_Enter.x+IG_LA_Real_RightButton_Enter.LA_Width;
    IG_LA_Real_RightButton_Enter.Ly=IG_LA_Real_RightButton_Enter.y+IG_LA_Real_RightButton_Enter.LA_High;


    IG_LA_Real_Company_Logo.LA_position=IG_LA_Model_Company_Logo;
    IG_LA_Real_Company_Logo.Sx=0.7f;
    IG_LA_Real_Company_Logo.Sy=0.7f;
    IG_LA_Real_Company_Logo.LA_High=(int)((IG_LA_Model_Company_Logo.m_iBottom-IG_LA_Model_Company_Logo.m_iTop)*IG_LA_Real_Company_Logo.Sy);
    IG_LA_Real_Company_Logo.LA_Width=(int)((IG_LA_Model_Company_Logo.m_iRight-IG_LA_Model_Company_Logo.m_iLeft)*IG_LA_Real_Company_Logo.Sx);
    IG_LA_Real_Company_Logo.x=15;
    IG_LA_Real_Company_Logo.y=20;
    IG_LA_Real_Company_Logo.Lx=IG_LA_Real_Company_Logo.x+IG_LA_Real_Company_Logo.LA_Width;
    IG_LA_Real_Company_Logo.Ly=IG_LA_Real_Company_Logo.y+IG_LA_Real_Company_Logo.LA_High;


    IG_LA_Real_JE_Logo.LA_position=IG_LA_Model_JE_Logo;
    IG_LA_Real_JE_Logo.Sx=0.7f;
    IG_LA_Real_JE_Logo.Sy=0.7f;
    IG_LA_Real_JE_Logo.LA_High=(int)((IG_LA_Model_JE_Logo.m_iBottom-IG_LA_Model_JE_Logo.m_iTop)*IG_LA_Real_JE_Logo.Sy);
    IG_LA_Real_JE_Logo.LA_Width=(int)((IG_LA_Model_JE_Logo.m_iRight-IG_LA_Model_JE_Logo.m_iLeft)*IG_LA_Real_JE_Logo.Sx);
    IG_LA_Real_JE_Logo.x=74;
    IG_LA_Real_JE_Logo.y=150;
    IG_LA_Real_JE_Logo.Lx=IG_LA_Real_JE_Logo.x+IG_LA_Real_JE_Logo.LA_Width;
    IG_LA_Real_JE_Logo.Ly=IG_LA_Real_JE_Logo.y+IG_LA_Real_JE_Logo.LA_High;


    IG_LA_Real_CW_Logo.LA_position=IG_LA_Model_CW_Logo;
    IG_LA_Real_CW_Logo.Sx=0.7f;
    IG_LA_Real_CW_Logo.Sy=0.7f;
    IG_LA_Real_CW_Logo.LA_High=(int)((IG_LA_Model_CW_Logo.m_iBottom-IG_LA_Model_CW_Logo.m_iTop)*IG_LA_Real_CW_Logo.Sy);
    IG_LA_Real_CW_Logo.LA_Width=(int)((IG_LA_Model_CW_Logo.m_iRight-IG_LA_Model_CW_Logo.m_iLeft)*IG_LA_Real_CW_Logo.Sx);
    IG_LA_Real_CW_Logo.x=74;
    IG_LA_Real_CW_Logo.y=150;
    IG_LA_Real_CW_Logo.Lx=IG_LA_Real_CW_Logo.x+IG_LA_Real_CW_Logo.LA_Width;
    IG_LA_Real_CW_Logo.Ly=IG_LA_Real_CW_Logo.y+IG_LA_Real_CW_Logo.LA_High;


    IG_LA_Real_DA_Logo.LA_position=IG_LA_Model_DA_Logo;
    IG_LA_Real_DA_Logo.Sx=0.7f;
    IG_LA_Real_DA_Logo.Sy=0.7f;
    IG_LA_Real_DA_Logo.LA_High=(int)((IG_LA_Model_DA_Logo.m_iBottom-IG_LA_Model_DA_Logo.m_iTop)*IG_LA_Real_DA_Logo.Sy);
    IG_LA_Real_DA_Logo.LA_Width=(int)((IG_LA_Model_DA_Logo.m_iRight-IG_LA_Model_DA_Logo.m_iLeft)*IG_LA_Real_DA_Logo.Sx);
    IG_LA_Real_DA_Logo.x=74;
    IG_LA_Real_DA_Logo.y=150;
	IG_LA_Real_DA_Logo.Lx=IG_LA_Real_DA_Logo.x+IG_LA_Real_DA_Logo.LA_Width;
    IG_LA_Real_DA_Logo.Ly=IG_LA_Real_DA_Logo.y+IG_LA_Real_DA_Logo.LA_High;


    IG_LA_Real_TK_Logo.LA_position=IG_LA_Model_TK_Logo;
    IG_LA_Real_TK_Logo.Sx=0.7f;
    IG_LA_Real_TK_Logo.Sy=0.7f;
    IG_LA_Real_TK_Logo.LA_High=(int)((IG_LA_Model_TK_Logo.m_iBottom-IG_LA_Model_TK_Logo.m_iTop)*IG_LA_Real_TK_Logo.Sy);
    IG_LA_Real_TK_Logo.LA_Width=(int)((IG_LA_Model_TK_Logo.m_iRight-IG_LA_Model_TK_Logo.m_iLeft)*IG_LA_Real_TK_Logo.Sx);
    IG_LA_Real_TK_Logo.x=74;
    IG_LA_Real_TK_Logo.y=150;
    IG_LA_Real_TK_Logo.Lx=IG_LA_Real_TK_Logo.x+IG_LA_Real_TK_Logo.LA_Width;
    IG_LA_Real_TK_Logo.Ly=IG_LA_Real_TK_Logo.y+IG_LA_Real_TK_Logo.LA_High;


    IG_LA_Real_DA_Word.LA_position=IG_LA_Model_DA_Word_CHS;
    IG_LA_Real_DA_Word.Sx=0.7f;
    IG_LA_Real_DA_Word.Sy=0.7f;
    IG_LA_Real_DA_Word.LA_High=(int)((IG_LA_Model_DA_Word_CHS.m_iBottom-IG_LA_Model_DA_Word_CHS.m_iTop)*IG_LA_Real_DA_Word.Sy);
    IG_LA_Real_DA_Word.LA_Width=(int)((IG_LA_Model_DA_Word_CHS.m_iRight-IG_LA_Model_DA_Word_CHS.m_iLeft)*IG_LA_Real_DA_Word.Sx);
    IG_LA_Real_DA_Word.x=75;
    IG_LA_Real_DA_Word.y=350;
    IG_LA_Real_DA_Word.Lx=IG_LA_Real_DA_Word.x+IG_LA_Real_DA_Word.LA_Width;
    IG_LA_Real_DA_Word.Ly=IG_LA_Real_DA_Word.y+IG_LA_Real_DA_Word.LA_High;


    IG_LA_Real_CW_Word.LA_position=IG_LA_Model_CW_Word_CHS;
    IG_LA_Real_CW_Word.Sx=0.7f;
    IG_LA_Real_CW_Word.Sy=0.7f;
    IG_LA_Real_CW_Word.LA_High=(int)((IG_LA_Model_CW_Word_CHS.m_iBottom-IG_LA_Model_CW_Word_CHS.m_iTop)*IG_LA_Real_CW_Word.Sy);
    IG_LA_Real_CW_Word.LA_Width=(int)((IG_LA_Model_CW_Word_CHS.m_iRight-IG_LA_Model_CW_Word_CHS.m_iLeft)*IG_LA_Real_CW_Word.Sx);
    IG_LA_Real_CW_Word.x=75;
    IG_LA_Real_CW_Word.y=350;
    IG_LA_Real_CW_Word.Lx=IG_LA_Real_CW_Word.x+IG_LA_Real_CW_Word.LA_Width;
    IG_LA_Real_CW_Word.Ly=IG_LA_Real_CW_Word.y+IG_LA_Real_CW_Word.LA_High;


    IG_LA_Real_JE_Word.LA_position=IG_LA_Model_JE_Word_CHS;
    IG_LA_Real_JE_Word.Sx=0.7f;
    IG_LA_Real_JE_Word.Sy=0.7f;
    IG_LA_Real_JE_Word.LA_High=(int)((IG_LA_Model_JE_Word_CHS.m_iBottom-IG_LA_Model_JE_Word_CHS.m_iTop)*IG_LA_Real_JE_Word.Sy);
    IG_LA_Real_JE_Word.LA_Width=(int)((IG_LA_Model_JE_Word_CHS.m_iRight-IG_LA_Model_JE_Word_CHS.m_iLeft)*IG_LA_Real_JE_Word.Sx);
    IG_LA_Real_JE_Word.x=75;
    IG_LA_Real_JE_Word.y=350;
    IG_LA_Real_JE_Word.Lx=IG_LA_Real_JE_Word.x+IG_LA_Real_JE_Word.LA_Width;
    IG_LA_Real_JE_Word.Ly=IG_LA_Real_JE_Word.y+IG_LA_Real_JE_Word.LA_High;


    IG_LA_Real_TK_Word.LA_position=IG_LA_Model_TK_Word_CHS;
    IG_LA_Real_TK_Word.Sx=0.7f;
    IG_LA_Real_TK_Word.Sy=0.7f;
    IG_LA_Real_TK_Word.LA_High=(int)((IG_LA_Model_TK_Word_CHS.m_iBottom-IG_LA_Model_TK_Word_CHS.m_iTop)*IG_LA_Real_TK_Word.Sy);
    IG_LA_Real_TK_Word.LA_Width=(int)((IG_LA_Model_TK_Word_CHS.m_iRight-IG_LA_Model_TK_Word_CHS.m_iLeft)*IG_LA_Real_TK_Word.Sx);
    IG_LA_Real_TK_Word.x=75;
    IG_LA_Real_TK_Word.y=350;
    IG_LA_Real_TK_Word.Lx=IG_LA_Real_TK_Word.x+IG_LA_Real_TK_Word.LA_Width;
    IG_LA_Real_TK_Word.Ly=IG_LA_Real_TK_Word.y+IG_LA_Real_TK_Word.LA_High;


    IG_LA_Real_Exit_Word.LA_position=IG_LA_Model_Exit_Word_CHS;
    IG_LA_Real_Exit_Word.Sx=0.7f;
    IG_LA_Real_Exit_Word.Sy=0.7f;
    IG_LA_Real_Exit_Word.LA_High=(int)((IG_LA_Model_Exit_Word_CHS.m_iBottom-IG_LA_Model_Exit_Word_CHS.m_iTop)*IG_LA_Real_Exit_Word.Sy);
    IG_LA_Real_Exit_Word.LA_Width=(int)((IG_LA_Model_Exit_Word_CHS.m_iRight-IG_LA_Model_Exit_Word_CHS.m_iLeft)*IG_LA_Real_Exit_Word.Sx);
    IG_LA_Real_Exit_Word.x=78;
    IG_LA_Real_Exit_Word.y=425;
    IG_LA_Real_Exit_Word.Lx=IG_LA_Real_Exit_Word.x+IG_LA_Real_Exit_Word.LA_Width;
    IG_LA_Real_Exit_Word.Ly=IG_LA_Real_Exit_Word.y+IG_LA_Real_Exit_Word.LA_High;

    IG_LA_Real_Warning_Word.LA_position=IG_LA_Model_Warning_Word_CHS;
    IG_LA_Real_Warning_Word.Sx=0.7f;
    IG_LA_Real_Warning_Word.Sy=0.7f;
    IG_LA_Real_Warning_Word.LA_High=(int)((IG_LA_Model_Warning_Word_CHS.m_iBottom-IG_LA_Model_Warning_Word_CHS.m_iTop)*IG_LA_Real_Exit_Word.Sy);
    IG_LA_Real_Warning_Word.LA_Width=(int)((IG_LA_Model_Warning_Word_CHS.m_iRight-IG_LA_Model_Warning_Word_CHS.m_iLeft)*IG_LA_Real_Exit_Word.Sx);
    IG_LA_Real_Warning_Word.x=75;
    IG_LA_Real_Warning_Word.y=200;
    IG_LA_Real_Warning_Word.Lx=IG_LA_Real_Warning_Word.x+IG_LA_Real_Warning_Word.LA_Width;
    IG_LA_Real_Warning_Word.Ly=IG_LA_Real_Warning_Word.y+IG_LA_Real_Warning_Word.LA_High;

#elif _320_480_&&_EN_
	
    IG_LA_English_Flag=1;
	
    IG_LA_Real_BackGround.Sx=0.7f;
    IG_LA_Real_BackGround.Sy=0.7f;
    IG_LA_Real_BackGround.LA_High=(int)(800*IG_LA_Real_BackGround.Sy);
    IG_LA_Real_BackGround.LA_Width=(int)(400*IG_LA_Real_BackGround.Sx);
    IG_LA_Real_BackGround.x=0;
    IG_LA_Real_BackGround.y=0;
    IG_LA_Real_BackGround.Lx=IG_LA_Real_BackGround.x+IG_LA_Real_BackGround.LA_Width;
    IG_LA_Real_BackGround.Ly=IG_LA_Real_BackGround.y+IG_LA_Real_BackGround.LA_High;

    IG_LA_Real_Button1.LA_position=IG_LA_Model_Button1;
    IG_LA_Real_Button1.Sx=0.7f;
    IG_LA_Real_Button1.Sy=0.7f;
    IG_LA_Real_Button1.LA_High=(int)((IG_LA_Model_Button1.m_iBottom-IG_LA_Model_Button1.m_iTop)*IG_LA_Real_Button1.Sy);
    IG_LA_Real_Button1.LA_Width=(int)((IG_LA_Model_Button1.m_iRight-IG_LA_Model_Button1.m_iLeft)*IG_LA_Real_Button1.Sx);
    IG_LA_Real_Button1.x=73;
    IG_LA_Real_Button1.y=334;
    IG_LA_Real_Button1.Lx=IG_LA_Real_Button1.x+IG_LA_Real_Button1.LA_Width;
    IG_LA_Real_Button1.Ly=IG_LA_Real_Button1.y+IG_LA_Real_Button1.LA_High;

    IG_LA_Real_Button1_Enter.LA_position=IG_LA_Model_Button1_Enter;
    IG_LA_Real_Button1_Enter.Sx=0.7f;
    IG_LA_Real_Button1_Enter.Sy=0.7f;
    IG_LA_Real_Button1_Enter.LA_High=(int)((IG_LA_Model_Button1_Enter.m_iBottom-IG_LA_Model_Button1_Enter.m_iTop)*IG_LA_Real_Button1_Enter.Sy);
    IG_LA_Real_Button1_Enter.LA_Width=(int)((IG_LA_Model_Button1_Enter.m_iRight-IG_LA_Model_Button1_Enter.m_iLeft)*IG_LA_Real_Button1_Enter.Sx);
    IG_LA_Real_Button1_Enter.x=73;
    IG_LA_Real_Button1_Enter.y=334;
    IG_LA_Real_Button1_Enter.Lx=IG_LA_Real_Button1_Enter.x+IG_LA_Real_Button1_Enter.LA_Width;
    IG_LA_Real_Button1_Enter.Ly=IG_LA_Real_Button1_Enter.y+IG_LA_Real_Button1_Enter.LA_High;


    IG_LA_Real_ExitButton.LA_position=IG_LA_Model_ExitButton;
    IG_LA_Real_ExitButton.Sx=0.7f;
    IG_LA_Real_ExitButton.Sy=0.7f;
    IG_LA_Real_ExitButton.LA_High=(int)((IG_LA_Model_ExitButton.m_iBottom-IG_LA_Model_ExitButton.m_iTop)*IG_LA_Real_ExitButton.Sy);
    IG_LA_Real_ExitButton.LA_Width=(int)((IG_LA_Model_ExitButton.m_iRight-IG_LA_Model_ExitButton.m_iLeft)*IG_LA_Real_ExitButton.Sx);
    IG_LA_Real_ExitButton.x=106;
    IG_LA_Real_ExitButton.y=412;
    IG_LA_Real_ExitButton.Lx=IG_LA_Real_ExitButton.x+IG_LA_Real_ExitButton.LA_Width;
    IG_LA_Real_ExitButton.Ly=IG_LA_Real_ExitButton.y+IG_LA_Real_ExitButton.LA_High;


    IG_LA_Real_ExitButton_Enter.LA_position=IG_LA_Model_ExitButton_Enter;
    IG_LA_Real_ExitButton_Enter.Sx=0.7f;
    IG_LA_Real_ExitButton_Enter.Sy=0.7f;
    IG_LA_Real_ExitButton_Enter.LA_High=(int)((IG_LA_Model_ExitButton_Enter.m_iBottom-IG_LA_Model_ExitButton_Enter.m_iTop)*IG_LA_Real_ExitButton_Enter.Sy);
    IG_LA_Real_ExitButton_Enter.LA_Width=(int)((IG_LA_Model_ExitButton_Enter.m_iRight-IG_LA_Model_ExitButton_Enter.m_iLeft)*IG_LA_Real_ExitButton_Enter.Sx);
    IG_LA_Real_ExitButton_Enter.x=106;
    IG_LA_Real_ExitButton_Enter.y=412;
    IG_LA_Real_ExitButton_Enter.Lx=IG_LA_Real_ExitButton_Enter.x+IG_LA_Real_ExitButton_Enter.LA_Width;
    IG_LA_Real_ExitButton_Enter.Ly=IG_LA_Real_ExitButton_Enter.y+IG_LA_Real_ExitButton_Enter.LA_High;



    IG_LA_Real_Game_Logo.LA_position=IG_LA_Model_Game_Logo;
    IG_LA_Real_Game_Logo.Sx=0.7f;
    IG_LA_Real_Game_Logo.Sy=0.7f;
    IG_LA_Real_Game_Logo.LA_High=(int)((IG_LA_Model_Game_Logo.m_iBottom-IG_LA_Model_Game_Logo.m_iTop)*IG_LA_Real_Game_Logo.Sy);
    IG_LA_Real_Game_Logo.LA_Width=(int)((IG_LA_Model_Game_Logo.m_iRight-IG_LA_Model_Game_Logo.m_iLeft)*IG_LA_Real_Game_Logo.Sx);
    IG_LA_Real_Game_Logo.x=173;
    IG_LA_Real_Game_Logo.y=95;
    IG_LA_Real_Game_Logo.Lx=IG_LA_Real_Game_Logo.x+IG_LA_Real_Game_Logo.LA_Width;
    IG_LA_Real_Game_Logo.Ly=IG_LA_Real_Game_Logo.y+IG_LA_Real_Game_Logo.LA_High;


    IG_LA_Real_LeftButton.LA_position=IG_LA_Model_LeftButton;
    IG_LA_Real_LeftButton.Sx=0.7f;
    IG_LA_Real_LeftButton.Sy=0.7f;
    IG_LA_Real_LeftButton.LA_High=(int)((IG_LA_Model_LeftButton.m_iBottom-IG_LA_Model_LeftButton.m_iTop)*IG_LA_Real_LeftButton.Sy);
    IG_LA_Real_LeftButton.LA_Width=(int)((IG_LA_Model_LeftButton.m_iRight-IG_LA_Model_LeftButton.m_iLeft)*IG_LA_Real_LeftButton.Sx);
    IG_LA_Real_LeftButton.x=0;
    IG_LA_Real_LeftButton.y=324;
    IG_LA_Real_LeftButton.Lx=IG_LA_Real_LeftButton.x+IG_LA_Real_LeftButton.LA_Width;
    IG_LA_Real_LeftButton.Ly=IG_LA_Real_LeftButton.y+IG_LA_Real_LeftButton.LA_High;


    IG_LA_Real_LeftButton_Enter.LA_position=IG_LA_Model_LeftButton_Enter;
    IG_LA_Real_LeftButton_Enter.Sx=0.7f;
    IG_LA_Real_LeftButton_Enter.Sy=0.7f;
    IG_LA_Real_LeftButton_Enter.LA_High=(int)((IG_LA_Model_LeftButton_Enter.m_iBottom-IG_LA_Model_LeftButton_Enter.m_iTop)*IG_LA_Real_LeftButton_Enter.Sy);
    IG_LA_Real_LeftButton_Enter.LA_Width=(int)((IG_LA_Model_LeftButton_Enter.m_iRight-IG_LA_Model_LeftButton_Enter.m_iLeft)*IG_LA_Real_LeftButton_Enter.Sx);
    IG_LA_Real_LeftButton_Enter.x=0;
    IG_LA_Real_LeftButton_Enter.y=324;
    IG_LA_Real_LeftButton_Enter.Lx=IG_LA_Real_LeftButton_Enter.x+IG_LA_Real_LeftButton_Enter.LA_Width;
    IG_LA_Real_LeftButton_Enter.Ly=IG_LA_Real_LeftButton_Enter.y+IG_LA_Real_LeftButton_Enter.LA_High;


    IG_LA_Real_RightButton.LA_position=IG_LA_Model_RightButton;
    IG_LA_Real_RightButton.Sx=0.7f;
    IG_LA_Real_RightButton.Sy=0.7f;
    IG_LA_Real_RightButton.LA_High=(int)((IG_LA_Model_RightButton.m_iBottom-IG_LA_Model_RightButton.m_iTop)*IG_LA_Real_RightButton.Sy);
    IG_LA_Real_RightButton.LA_Width=(int)((IG_LA_Model_RightButton.m_iRight-IG_LA_Model_RightButton.m_iLeft)*IG_LA_Real_RightButton.Sx);
    IG_LA_Real_RightButton.x=250;
    IG_LA_Real_RightButton.y=324;
    IG_LA_Real_RightButton.Lx=IG_LA_Real_RightButton.x+IG_LA_Real_RightButton.LA_Width;
    IG_LA_Real_RightButton.Ly=IG_LA_Real_RightButton.y+IG_LA_Real_RightButton.LA_High;


    IG_LA_Real_RightButton_Enter.LA_position=IG_LA_Model_RightButton_Enter;
    IG_LA_Real_RightButton_Enter.Sx=0.7f;
    IG_LA_Real_RightButton_Enter.Sy=0.7f;
    IG_LA_Real_RightButton_Enter.LA_High=(int)((IG_LA_Model_RightButton_Enter.m_iBottom-IG_LA_Model_RightButton_Enter.m_iTop)*IG_LA_Real_RightButton_Enter.Sy);
    IG_LA_Real_RightButton_Enter.LA_Width=(int)((IG_LA_Model_RightButton_Enter.m_iRight-IG_LA_Model_RightButton_Enter.m_iLeft)*IG_LA_Real_RightButton_Enter.Sx);
    IG_LA_Real_RightButton_Enter.x=250;
    IG_LA_Real_RightButton_Enter.y=324;
    IG_LA_Real_RightButton_Enter.Lx=IG_LA_Real_RightButton_Enter.x+IG_LA_Real_RightButton_Enter.LA_Width;
    IG_LA_Real_RightButton_Enter.Ly=IG_LA_Real_RightButton_Enter.y+IG_LA_Real_RightButton_Enter.LA_High;


    IG_LA_Real_Company_Logo.LA_position=IG_LA_Model_Company_Logo;
    IG_LA_Real_Company_Logo.Sx=0.7f;
    IG_LA_Real_Company_Logo.Sy=0.7f;
    IG_LA_Real_Company_Logo.LA_High=(int)((IG_LA_Model_Company_Logo.m_iBottom-IG_LA_Model_Company_Logo.m_iTop)*IG_LA_Real_Company_Logo.Sy);
    IG_LA_Real_Company_Logo.LA_Width=(int)((IG_LA_Model_Company_Logo.m_iRight-IG_LA_Model_Company_Logo.m_iLeft)*IG_LA_Real_Company_Logo.Sx);
    IG_LA_Real_Company_Logo.x=15;
    IG_LA_Real_Company_Logo.y=20;
    IG_LA_Real_Company_Logo.Lx=IG_LA_Real_Company_Logo.x+IG_LA_Real_Company_Logo.LA_Width;
    IG_LA_Real_Company_Logo.Ly=IG_LA_Real_Company_Logo.y+IG_LA_Real_Company_Logo.LA_High;


    IG_LA_Real_JE_Logo.LA_position=IG_LA_Model_JE_Logo;
    IG_LA_Real_JE_Logo.Sx=0.7f;
    IG_LA_Real_JE_Logo.Sy=0.7f;
    IG_LA_Real_JE_Logo.LA_High=(int)((IG_LA_Model_JE_Logo.m_iBottom-IG_LA_Model_JE_Logo.m_iTop)*IG_LA_Real_JE_Logo.Sy);
    IG_LA_Real_JE_Logo.LA_Width=(int)((IG_LA_Model_JE_Logo.m_iRight-IG_LA_Model_JE_Logo.m_iLeft)*IG_LA_Real_JE_Logo.Sx);
    IG_LA_Real_JE_Logo.x=74;
    IG_LA_Real_JE_Logo.y=150;
    IG_LA_Real_JE_Logo.Lx=IG_LA_Real_JE_Logo.x+IG_LA_Real_JE_Logo.LA_Width;
    IG_LA_Real_JE_Logo.Ly=IG_LA_Real_JE_Logo.y+IG_LA_Real_JE_Logo.LA_High;


    IG_LA_Real_CW_Logo.LA_position=IG_LA_Model_CW_Logo;
    IG_LA_Real_CW_Logo.Sx=0.7f;
    IG_LA_Real_CW_Logo.Sy=0.7f;
    IG_LA_Real_CW_Logo.LA_High=(int)((IG_LA_Model_CW_Logo.m_iBottom-IG_LA_Model_CW_Logo.m_iTop)*IG_LA_Real_CW_Logo.Sy);
    IG_LA_Real_CW_Logo.LA_Width=(int)((IG_LA_Model_CW_Logo.m_iRight-IG_LA_Model_CW_Logo.m_iLeft)*IG_LA_Real_CW_Logo.Sx);
    IG_LA_Real_CW_Logo.x=74;
    IG_LA_Real_CW_Logo.y=150;
    IG_LA_Real_CW_Logo.Lx=IG_LA_Real_CW_Logo.x+IG_LA_Real_CW_Logo.LA_Width;
    IG_LA_Real_CW_Logo.Ly=IG_LA_Real_CW_Logo.y+IG_LA_Real_CW_Logo.LA_High;


    IG_LA_Real_DA_Logo.LA_position=IG_LA_Model_DA_Logo;
    IG_LA_Real_DA_Logo.Sx=0.7f;
    IG_LA_Real_DA_Logo.Sy=0.7f;
    IG_LA_Real_DA_Logo.LA_High=(int)((IG_LA_Model_DA_Logo.m_iBottom-IG_LA_Model_DA_Logo.m_iTop)*IG_LA_Real_DA_Logo.Sy);
    IG_LA_Real_DA_Logo.LA_Width=(int)((IG_LA_Model_DA_Logo.m_iRight-IG_LA_Model_DA_Logo.m_iLeft)*IG_LA_Real_DA_Logo.Sx);
    IG_LA_Real_DA_Logo.x=74;
    IG_LA_Real_DA_Logo.y=150;
    IG_LA_Real_DA_Logo.Lx=IG_LA_Real_DA_Logo.x+IG_LA_Real_DA_Logo.LA_Width;
    IG_LA_Real_DA_Logo.Ly=IG_LA_Real_DA_Logo.y+IG_LA_Real_DA_Logo.LA_High;


    IG_LA_Real_TK_Logo.LA_position=IG_LA_Model_TK_Logo;
    IG_LA_Real_TK_Logo.Sx=0.7f;
    IG_LA_Real_TK_Logo.Sy=0.7f;
    IG_LA_Real_TK_Logo.LA_High=(int)((IG_LA_Model_TK_Logo.m_iBottom-IG_LA_Model_TK_Logo.m_iTop)*IG_LA_Real_TK_Logo.Sy);
    IG_LA_Real_TK_Logo.LA_Width=(int)((IG_LA_Model_TK_Logo.m_iRight-IG_LA_Model_TK_Logo.m_iLeft)*IG_LA_Real_TK_Logo.Sx);
    IG_LA_Real_TK_Logo.x=74;
    IG_LA_Real_TK_Logo.y=150;
    IG_LA_Real_TK_Logo.Lx=IG_LA_Real_TK_Logo.x+IG_LA_Real_TK_Logo.LA_Width;
    IG_LA_Real_TK_Logo.Ly=IG_LA_Real_TK_Logo.y+IG_LA_Real_TK_Logo.LA_High;


    IG_LA_Real_DA_Word.LA_position=IG_LA_Model_DA_Word_ENG;
    IG_LA_Real_DA_Word.Sx=0.7f;
    IG_LA_Real_DA_Word.Sy=0.7f;
    IG_LA_Real_DA_Word.LA_High=(int)((IG_LA_Model_DA_Word_ENG.m_iBottom-IG_LA_Model_DA_Word_ENG.m_iTop)*IG_LA_Real_DA_Word.Sy);
    IG_LA_Real_DA_Word.LA_Width=(int)((IG_LA_Model_DA_Word_ENG.m_iRight-IG_LA_Model_DA_Word_ENG.m_iLeft)*IG_LA_Real_DA_Word.Sx);
    IG_LA_Real_DA_Word.x=75;
    IG_LA_Real_DA_Word.y=350;
    IG_LA_Real_DA_Word.Lx=IG_LA_Real_DA_Word.x+IG_LA_Real_DA_Word.LA_Width;
    IG_LA_Real_DA_Word.Ly=IG_LA_Real_DA_Word.y+IG_LA_Real_DA_Word.LA_High;


    IG_LA_Real_CW_Word.LA_position=IG_LA_Model_CW_Word_ENG;
    IG_LA_Real_CW_Word.Sx=0.7f;
    IG_LA_Real_CW_Word.Sy=0.7f;
    IG_LA_Real_CW_Word.LA_High=(int)((IG_LA_Model_CW_Word_ENG.m_iBottom-IG_LA_Model_CW_Word_ENG.m_iTop)*IG_LA_Real_CW_Word.Sy);
    IG_LA_Real_CW_Word.LA_Width=(int)((IG_LA_Model_CW_Word_ENG.m_iRight-IG_LA_Model_CW_Word_ENG.m_iLeft)*IG_LA_Real_CW_Word.Sx);
    IG_LA_Real_CW_Word.x=75;
    IG_LA_Real_CW_Word.y=350;
    IG_LA_Real_CW_Word.Lx=IG_LA_Real_CW_Word.x+IG_LA_Real_CW_Word.LA_Width;
    IG_LA_Real_CW_Word.Ly=IG_LA_Real_CW_Word.y+IG_LA_Real_CW_Word.LA_High;


    IG_LA_Real_JE_Word.LA_position=IG_LA_Model_JE_Word_ENG;
    IG_LA_Real_JE_Word.Sx=0.7f;
    IG_LA_Real_JE_Word.Sy=0.7f;
    IG_LA_Real_JE_Word.LA_High=(int)((IG_LA_Model_JE_Word_ENG.m_iBottom-IG_LA_Model_JE_Word_ENG.m_iTop)*IG_LA_Real_JE_Word.Sy);
    IG_LA_Real_JE_Word.LA_Width=(int)((IG_LA_Model_JE_Word_ENG.m_iRight-IG_LA_Model_JE_Word_ENG.m_iLeft)*IG_LA_Real_JE_Word.Sx);
    IG_LA_Real_JE_Word.x=75;
    IG_LA_Real_JE_Word.y=350;
    IG_LA_Real_JE_Word.Lx=IG_LA_Real_JE_Word.x+IG_LA_Real_JE_Word.LA_Width;
    IG_LA_Real_JE_Word.Ly=IG_LA_Real_JE_Word.y+IG_LA_Real_JE_Word.LA_High;


    IG_LA_Real_TK_Word.LA_position=IG_LA_Model_TK_Word_ENG;
    IG_LA_Real_TK_Word.Sx=0.7f;
    IG_LA_Real_TK_Word.Sy=0.7f;
    IG_LA_Real_TK_Word.LA_High=(int)((IG_LA_Model_TK_Word_ENG.m_iBottom-IG_LA_Model_TK_Word_ENG.m_iTop)*IG_LA_Real_TK_Word.Sy);
    IG_LA_Real_TK_Word.LA_Width=(int)((IG_LA_Model_TK_Word_ENG.m_iRight-IG_LA_Model_TK_Word_ENG.m_iLeft)*IG_LA_Real_TK_Word.Sx);
    IG_LA_Real_TK_Word.x=75;
    IG_LA_Real_TK_Word.y=350;
    IG_LA_Real_TK_Word.Lx=IG_LA_Real_TK_Word.x+IG_LA_Real_TK_Word.LA_Width;
    IG_LA_Real_TK_Word.Ly=IG_LA_Real_TK_Word.y+IG_LA_Real_TK_Word.LA_High;


    IG_LA_Real_Exit_Word.LA_position=IG_LA_Model_Exit_Word_ENG;
    IG_LA_Real_Exit_Word.Sx=0.7f;
    IG_LA_Real_Exit_Word.Sy=0.7f;
    IG_LA_Real_Exit_Word.LA_High=(int)((IG_LA_Model_Exit_Word_ENG.m_iBottom-IG_LA_Model_Exit_Word_ENG.m_iTop)*IG_LA_Real_Exit_Word.Sy);
    IG_LA_Real_Exit_Word.LA_Width=(int)((IG_LA_Model_Exit_Word_ENG.m_iRight-IG_LA_Model_Exit_Word_ENG.m_iLeft)*IG_LA_Real_Exit_Word.Sx);
    IG_LA_Real_Exit_Word.x=78;
    IG_LA_Real_Exit_Word.y=425;
    IG_LA_Real_Exit_Word.Lx=IG_LA_Real_Exit_Word.x+IG_LA_Real_Exit_Word.LA_Width;
    IG_LA_Real_Exit_Word.Ly=IG_LA_Real_Exit_Word.y+IG_LA_Real_Exit_Word.LA_High;

    IG_LA_Real_Warning_Word.LA_position=IG_LA_Model_Warning_Word_ENG;
    IG_LA_Real_Warning_Word.Sx=0.7f;
    IG_LA_Real_Warning_Word.Sy=0.7f;
    IG_LA_Real_Warning_Word.LA_High=(int)((IG_LA_Model_Warning_Word_CHS.m_iBottom-IG_LA_Model_Warning_Word_CHS.m_iTop)*IG_LA_Real_Exit_Word.Sy);
    IG_LA_Real_Warning_Word.LA_Width=(int)((IG_LA_Model_Warning_Word_CHS.m_iRight-IG_LA_Model_Warning_Word_CHS.m_iLeft)*IG_LA_Real_Exit_Word.Sx);
    IG_LA_Real_Warning_Word.x=75;
    IG_LA_Real_Warning_Word.y=200;
    IG_LA_Real_Warning_Word.Lx=IG_LA_Real_Warning_Word.x+IG_LA_Real_Warning_Word.LA_Width;
    IG_LA_Real_Warning_Word.Ly=IG_LA_Real_Warning_Word.y+IG_LA_Real_Warning_Word.LA_High;

#elif _240_400_&&_CHS_
    IG_LA_Real_BackGround.Sx=0.7f;
    IG_LA_Real_BackGround.Sy=0.7f;
    IG_LA_Real_BackGround.LA_High=(int)(800*IG_LA_Real_BackGround.Sy);
    IG_LA_Real_BackGround.LA_Width=(int)(400*IG_LA_Real_BackGround.Sx);
    IG_LA_Real_BackGround.x=0;
    IG_LA_Real_BackGround.y=0;
    IG_LA_Real_BackGround.Lx=IG_LA_Real_BackGround.x+IG_LA_Real_BackGround.LA_Width;
    IG_LA_Real_BackGround.Ly=IG_LA_Real_BackGround.y+IG_LA_Real_BackGround.LA_High;


    IG_LA_Real_Button1.LA_position=IG_LA_Model_Button1;
    IG_LA_Real_Button1.Sx=0.5f;
    IG_LA_Real_Button1.Sy=0.5f;
    IG_LA_Real_Button1.LA_High=(int)((IG_LA_Model_Button1.m_iBottom-IG_LA_Model_Button1.m_iTop)*IG_LA_Real_Button1.Sy);
    IG_LA_Real_Button1.LA_Width=(int)((IG_LA_Model_Button1.m_iRight-IG_LA_Model_Button1.m_iLeft)*IG_LA_Real_Button1.Sx);
    IG_LA_Real_Button1.x=58;
    IG_LA_Real_Button1.y=274;
    IG_LA_Real_Button1.Lx=IG_LA_Real_Button1.x+IG_LA_Real_Button1.LA_Width;
    IG_LA_Real_Button1.Ly=IG_LA_Real_Button1.y+IG_LA_Real_Button1.LA_High;


    IG_LA_Real_Button1_Enter.LA_position=IG_LA_Model_Button1_Enter;
    IG_LA_Real_Button1_Enter.Sx=0.5f;
    IG_LA_Real_Button1_Enter.Sy=0.5f;
    IG_LA_Real_Button1_Enter.LA_High=(int)((IG_LA_Model_Button1_Enter.m_iBottom-IG_LA_Model_Button1_Enter.m_iTop)*IG_LA_Real_Button1_Enter.Sy);
    IG_LA_Real_Button1_Enter.LA_Width=(int)((IG_LA_Model_Button1_Enter.m_iRight-IG_LA_Model_Button1_Enter.m_iLeft)*IG_LA_Real_Button1_Enter.Sx);
    IG_LA_Real_Button1_Enter.x=58;
    IG_LA_Real_Button1_Enter.y=274;
    IG_LA_Real_Button1_Enter.Lx=IG_LA_Real_Button1_Enter.x+IG_LA_Real_Button1_Enter.LA_Width;
    IG_LA_Real_Button1_Enter.Ly=IG_LA_Real_Button1_Enter.y+IG_LA_Real_Button1_Enter.LA_High;


    IG_LA_Real_ExitButton.LA_position=IG_LA_Model_ExitButton;
    IG_LA_Real_ExitButton.Sx=0.5f;
    IG_LA_Real_ExitButton.Sy=0.5f;
    IG_LA_Real_ExitButton.LA_High=(int)((IG_LA_Model_ExitButton.m_iBottom-IG_LA_Model_ExitButton.m_iTop)*IG_LA_Real_ExitButton.Sy);
    IG_LA_Real_ExitButton.LA_Width=(int)((IG_LA_Model_ExitButton.m_iRight-IG_LA_Model_ExitButton.m_iLeft)*IG_LA_Real_ExitButton.Sx);
    IG_LA_Real_ExitButton.x=80;
    IG_LA_Real_ExitButton.y=338;
    IG_LA_Real_ExitButton.Lx=IG_LA_Real_ExitButton.x+IG_LA_Real_ExitButton.LA_Width;
    IG_LA_Real_ExitButton.Ly=IG_LA_Real_ExitButton.y+IG_LA_Real_ExitButton.LA_High;


    IG_LA_Real_ExitButton_Enter.LA_position=IG_LA_Model_ExitButton_Enter;
    IG_LA_Real_ExitButton_Enter.Sx=0.5f;
    IG_LA_Real_ExitButton_Enter.Sy=0.5f;
    IG_LA_Real_ExitButton_Enter.LA_High=(int)((IG_LA_Model_ExitButton_Enter.m_iBottom-IG_LA_Model_ExitButton_Enter.m_iTop)*IG_LA_Real_ExitButton_Enter.Sy);
    IG_LA_Real_ExitButton_Enter.LA_Width=(int)((IG_LA_Model_ExitButton_Enter.m_iRight-IG_LA_Model_ExitButton_Enter.m_iLeft)*IG_LA_Real_ExitButton_Enter.Sx);
    IG_LA_Real_ExitButton_Enter.x=80;
    IG_LA_Real_ExitButton_Enter.y=338;
    IG_LA_Real_ExitButton_Enter.Lx=IG_LA_Real_ExitButton_Enter.x+IG_LA_Real_ExitButton_Enter.LA_Width;
    IG_LA_Real_ExitButton_Enter.Ly=IG_LA_Real_ExitButton_Enter.y+IG_LA_Real_ExitButton_Enter.LA_High;


    IG_LA_Real_Game_Logo.LA_position=IG_LA_Model_Game_Logo;
    IG_LA_Real_Game_Logo.Sx=0.5f;
    IG_LA_Real_Game_Logo.Sy=0.5f;
    IG_LA_Real_Game_Logo.LA_High=(int)((IG_LA_Model_Game_Logo.m_iBottom-IG_LA_Model_Game_Logo.m_iTop)*IG_LA_Real_Game_Logo.Sy);
    IG_LA_Real_Game_Logo.LA_Width=(int)((IG_LA_Model_Game_Logo.m_iRight-IG_LA_Model_Game_Logo.m_iLeft)*IG_LA_Real_Game_Logo.Sx);
    IG_LA_Real_Game_Logo.x=130;
    IG_LA_Real_Game_Logo.y=80;
    IG_LA_Real_Game_Logo.Lx=IG_LA_Real_Game_Logo.x+IG_LA_Real_Game_Logo.LA_Width;
    IG_LA_Real_Game_Logo.Ly=IG_LA_Real_Game_Logo.y+IG_LA_Real_Game_Logo.LA_High;


    IG_LA_Real_LeftButton.LA_position=IG_LA_Model_LeftButton;
    IG_LA_Real_LeftButton.Sx=0.5f;
    IG_LA_Real_LeftButton.Sy=0.5f;
    IG_LA_Real_LeftButton.LA_High=(int)((IG_LA_Model_LeftButton.m_iBottom-IG_LA_Model_LeftButton.m_iTop)*IG_LA_Real_LeftButton.Sy);
    IG_LA_Real_LeftButton.LA_Width=(int)((IG_LA_Model_LeftButton.m_iRight-IG_LA_Model_LeftButton.m_iLeft)*IG_LA_Real_LeftButton.Sx);
    IG_LA_Real_LeftButton.x=0;
    IG_LA_Real_LeftButton.y=270;
    IG_LA_Real_LeftButton.Lx=IG_LA_Real_LeftButton.x+IG_LA_Real_LeftButton.LA_Width;
    IG_LA_Real_LeftButton.Ly=IG_LA_Real_LeftButton.y+IG_LA_Real_LeftButton.LA_High;


    IG_LA_Real_LeftButton_Enter.LA_position=IG_LA_Model_LeftButton_Enter;
    IG_LA_Real_LeftButton_Enter.Sx=0.5f;
    IG_LA_Real_LeftButton_Enter.Sy=0.5f;
    IG_LA_Real_LeftButton_Enter.LA_High=(int)((IG_LA_Model_LeftButton_Enter.m_iBottom-IG_LA_Model_LeftButton_Enter.m_iTop)*IG_LA_Real_LeftButton_Enter.Sy);
    IG_LA_Real_LeftButton_Enter.LA_Width=(int)((IG_LA_Model_LeftButton_Enter.m_iRight-IG_LA_Model_LeftButton_Enter.m_iLeft)*IG_LA_Real_LeftButton_Enter.Sx);
    IG_LA_Real_LeftButton_Enter.x=0;
    IG_LA_Real_LeftButton_Enter.y=270;
    IG_LA_Real_LeftButton_Enter.Lx=IG_LA_Real_LeftButton_Enter.x+IG_LA_Real_LeftButton_Enter.LA_Width;
    IG_LA_Real_LeftButton_Enter.Ly=IG_LA_Real_LeftButton_Enter.y+IG_LA_Real_LeftButton_Enter.LA_High;


    IG_LA_Real_RightButton.LA_position=IG_LA_Model_RightButton;    
    IG_LA_Real_RightButton.Sx=0.5f;
    IG_LA_Real_RightButton.Sy=0.5f;
    IG_LA_Real_RightButton.LA_High=(int)((IG_LA_Model_RightButton.m_iBottom-IG_LA_Model_RightButton.m_iTop)*IG_LA_Real_RightButton.Sy);
    IG_LA_Real_RightButton.LA_Width=(int)((IG_LA_Model_RightButton.m_iRight-IG_LA_Model_RightButton.m_iLeft)*IG_LA_Real_RightButton.Sx);
    IG_LA_Real_RightButton.x=190;
    IG_LA_Real_RightButton.y=270;
    IG_LA_Real_RightButton.Lx=IG_LA_Real_RightButton.x+IG_LA_Real_RightButton.LA_Width;
    IG_LA_Real_RightButton.Ly=IG_LA_Real_RightButton.y+IG_LA_Real_RightButton.LA_High;


    IG_LA_Real_RightButton_Enter.LA_position=IG_LA_Model_RightButton_Enter;
    IG_LA_Real_RightButton_Enter.Sx=0.5f;
    IG_LA_Real_RightButton_Enter.Sy=0.5f;
    IG_LA_Real_RightButton_Enter.LA_High=(int)((IG_LA_Model_RightButton_Enter.m_iBottom-IG_LA_Model_RightButton_Enter.m_iTop)*IG_LA_Real_RightButton_Enter.Sy);
    IG_LA_Real_RightButton_Enter.LA_Width=(int)((IG_LA_Model_RightButton_Enter.m_iRight-IG_LA_Model_RightButton_Enter.m_iLeft)*IG_LA_Real_RightButton_Enter.Sx);
    IG_LA_Real_RightButton_Enter.x=190;
    IG_LA_Real_RightButton_Enter.y=270;
    IG_LA_Real_RightButton_Enter.Lx=IG_LA_Real_RightButton_Enter.x+IG_LA_Real_RightButton_Enter.LA_Width;
    IG_LA_Real_RightButton_Enter.Ly=IG_LA_Real_RightButton_Enter.y+IG_LA_Real_RightButton_Enter.LA_High;


    IG_LA_Real_Company_Logo.LA_position=IG_LA_Model_Company_Logo;
    IG_LA_Real_Company_Logo.Sx=0.5f;
    IG_LA_Real_Company_Logo.Sy=0.5f;
    IG_LA_Real_Company_Logo.LA_High=(int)((IG_LA_Model_Company_Logo.m_iBottom-IG_LA_Model_Company_Logo.m_iTop)*IG_LA_Real_Company_Logo.Sy);
    IG_LA_Real_Company_Logo.LA_Width=(int)((IG_LA_Model_Company_Logo.m_iRight-IG_LA_Model_Company_Logo.m_iLeft)*IG_LA_Real_Company_Logo.Sx);
    IG_LA_Real_Company_Logo.x=11;
    IG_LA_Real_Company_Logo.y=23;
    IG_LA_Real_Company_Logo.Lx=IG_LA_Real_Company_Logo.x+IG_LA_Real_Company_Logo.LA_Width;
    IG_LA_Real_Company_Logo.Ly=IG_LA_Real_Company_Logo.y+IG_LA_Real_Company_Logo.LA_High;


    IG_LA_Real_JE_Logo.LA_position=IG_LA_Model_JE_Logo;
    IG_LA_Real_JE_Logo.Sx=0.5f;
    IG_LA_Real_JE_Logo.Sy=0.5f;
    IG_LA_Real_JE_Logo.LA_High=(int)((IG_LA_Model_JE_Logo.m_iBottom-IG_LA_Model_JE_Logo.m_iTop)*IG_LA_Real_JE_Logo.Sy);
    IG_LA_Real_JE_Logo.LA_Width=(int)((IG_LA_Model_JE_Logo.m_iRight-IG_LA_Model_JE_Logo.m_iLeft)*IG_LA_Real_JE_Logo.Sx);
    IG_LA_Real_JE_Logo.x=56;
    IG_LA_Real_JE_Logo.y=134;
    IG_LA_Real_JE_Logo.Lx=IG_LA_Real_JE_Logo.x+IG_LA_Real_JE_Logo.LA_Width;
    IG_LA_Real_JE_Logo.Ly=IG_LA_Real_JE_Logo.y+IG_LA_Real_JE_Logo.LA_High;


    IG_LA_Real_CW_Logo.LA_position=IG_LA_Model_CW_Logo;
    IG_LA_Real_CW_Logo.Sx=0.5f;
    IG_LA_Real_CW_Logo.Sy=0.5f;
    IG_LA_Real_CW_Logo.LA_High=(int)((IG_LA_Model_CW_Logo.m_iBottom-IG_LA_Model_CW_Logo.m_iTop)*IG_LA_Real_CW_Logo.Sy);
    IG_LA_Real_CW_Logo.LA_Width=(int)((IG_LA_Model_CW_Logo.m_iRight-IG_LA_Model_CW_Logo.m_iLeft)*IG_LA_Real_CW_Logo.Sx);
    IG_LA_Real_CW_Logo.x=56;
    IG_LA_Real_CW_Logo.y=134;
    IG_LA_Real_CW_Logo.Lx=IG_LA_Real_CW_Logo.x+IG_LA_Real_CW_Logo.LA_Width;
    IG_LA_Real_CW_Logo.Ly=IG_LA_Real_CW_Logo.y+IG_LA_Real_CW_Logo.LA_High;


    IG_LA_Real_DA_Logo.LA_position=IG_LA_Model_DA_Logo;
    IG_LA_Real_DA_Logo.Sx=0.5f;
    IG_LA_Real_DA_Logo.Sy=0.5f;
    IG_LA_Real_DA_Logo.LA_High=(int)((IG_LA_Model_DA_Logo.m_iBottom-IG_LA_Model_DA_Logo.m_iTop)*IG_LA_Real_DA_Logo.Sy);
    IG_LA_Real_DA_Logo.LA_Width=(int)((IG_LA_Model_DA_Logo.m_iRight-IG_LA_Model_DA_Logo.m_iLeft)*IG_LA_Real_DA_Logo.Sx);
    IG_LA_Real_DA_Logo.x=56;
    IG_LA_Real_DA_Logo.y=134;
    IG_LA_Real_DA_Logo.Lx=IG_LA_Real_DA_Logo.x+IG_LA_Real_DA_Logo.LA_Width;
    IG_LA_Real_DA_Logo.Ly=IG_LA_Real_DA_Logo.y+IG_LA_Real_DA_Logo.LA_High;


    IG_LA_Real_TK_Logo.LA_position=IG_LA_Model_TK_Logo;
    IG_LA_Real_TK_Logo.Sx=0.5f;
    IG_LA_Real_TK_Logo.Sy=0.5f;
    IG_LA_Real_TK_Logo.LA_High=(int)((IG_LA_Model_TK_Logo.m_iBottom-IG_LA_Model_TK_Logo.m_iTop)*IG_LA_Real_TK_Logo.Sy);
    IG_LA_Real_TK_Logo.LA_Width=(int)((IG_LA_Model_TK_Logo.m_iRight-IG_LA_Model_TK_Logo.m_iLeft)*IG_LA_Real_TK_Logo.Sx);
    IG_LA_Real_TK_Logo.x=56;
    IG_LA_Real_TK_Logo.y=134;
    IG_LA_Real_TK_Logo.Lx=IG_LA_Real_TK_Logo.x+IG_LA_Real_TK_Logo.LA_Width;
    IG_LA_Real_TK_Logo.Ly=IG_LA_Real_TK_Logo.y+IG_LA_Real_TK_Logo.LA_High;


    IG_LA_Real_DA_Word.LA_position=IG_LA_Model_DA_Word_CHS;
    IG_LA_Real_DA_Word.Sx=0.5f;
    IG_LA_Real_DA_Word.Sy=0.5f;
    IG_LA_Real_DA_Word.LA_High=(int)((IG_LA_Model_DA_Word_CHS.m_iBottom-IG_LA_Model_DA_Word_CHS.m_iTop)*IG_LA_Real_DA_Word.Sy);
    IG_LA_Real_DA_Word.LA_Width=(int)((IG_LA_Model_DA_Word_CHS.m_iRight-IG_LA_Model_DA_Word_CHS.m_iLeft)*IG_LA_Real_DA_Word.Sx);
    IG_LA_Real_DA_Word.x=60;
    IG_LA_Real_DA_Word.y=286;
    IG_LA_Real_DA_Word.Lx=IG_LA_Real_DA_Word.x+IG_LA_Real_DA_Word.LA_Width;
    IG_LA_Real_DA_Word.Ly=IG_LA_Real_DA_Word.y+IG_LA_Real_DA_Word.LA_High;


    IG_LA_Real_CW_Word.LA_position=IG_LA_Model_CW_Word_CHS;
    IG_LA_Real_CW_Word.Sx=0.5f;
    IG_LA_Real_CW_Word.Sy=0.5f;
    IG_LA_Real_CW_Word.LA_High=(int)((IG_LA_Model_CW_Word_CHS.m_iBottom-IG_LA_Model_CW_Word_CHS.m_iTop)*IG_LA_Real_CW_Word.Sy);
    IG_LA_Real_CW_Word.LA_Width=(int)((IG_LA_Model_CW_Word_CHS.m_iRight-IG_LA_Model_CW_Word_CHS.m_iLeft)*IG_LA_Real_CW_Word.Sx);
    IG_LA_Real_CW_Word.x=60;
    IG_LA_Real_CW_Word.y=286;
    IG_LA_Real_CW_Word.Lx=IG_LA_Real_CW_Word.x+IG_LA_Real_CW_Word.LA_Width;
    IG_LA_Real_CW_Word.Ly=IG_LA_Real_CW_Word.y+IG_LA_Real_CW_Word.LA_High;


    IG_LA_Real_JE_Word.LA_position=IG_LA_Model_JE_Word_CHS;
    IG_LA_Real_JE_Word.Sx=0.5f;
    IG_LA_Real_JE_Word.Sy=0.5f;
    IG_LA_Real_JE_Word.LA_High=(int)((IG_LA_Model_JE_Word_CHS.m_iBottom-IG_LA_Model_JE_Word_CHS.m_iTop)*IG_LA_Real_JE_Word.Sy);
    IG_LA_Real_JE_Word.LA_Width=(int)((IG_LA_Model_JE_Word_CHS.m_iRight-IG_LA_Model_JE_Word_CHS.m_iLeft)*IG_LA_Real_JE_Word.Sx);
    IG_LA_Real_JE_Word.x=60;
    IG_LA_Real_JE_Word.y=286;
    IG_LA_Real_JE_Word.Lx=IG_LA_Real_JE_Word.x+IG_LA_Real_JE_Word.LA_Width;
    IG_LA_Real_JE_Word.Ly=IG_LA_Real_JE_Word.y+IG_LA_Real_JE_Word.LA_High;


    IG_LA_Real_TK_Word.LA_position=IG_LA_Model_TK_Word_CHS;
    IG_LA_Real_TK_Word.Sx=0.5f;
    IG_LA_Real_TK_Word.Sy=0.5f;
    IG_LA_Real_TK_Word.LA_High=(int)((IG_LA_Model_TK_Word_CHS.m_iBottom-IG_LA_Model_TK_Word_CHS.m_iTop)*IG_LA_Real_TK_Word.Sy);
    IG_LA_Real_TK_Word.LA_Width=(int)((IG_LA_Model_TK_Word_CHS.m_iRight-IG_LA_Model_TK_Word_CHS.m_iLeft)*IG_LA_Real_TK_Word.Sx);
    IG_LA_Real_TK_Word.x=60;
    IG_LA_Real_TK_Word.y=286;
    IG_LA_Real_TK_Word.Lx=IG_LA_Real_TK_Word.x+IG_LA_Real_TK_Word.LA_Width;
    IG_LA_Real_TK_Word.Ly=IG_LA_Real_TK_Word.y+IG_LA_Real_TK_Word.LA_High;


    IG_LA_Real_Exit_Word.LA_position=IG_LA_Model_Exit_Word_CHS;
    IG_LA_Real_Exit_Word.Sx=0.5f;
    IG_LA_Real_Exit_Word.Sy=0.5f;
    IG_LA_Real_Exit_Word.LA_High=(int)((IG_LA_Model_Exit_Word_CHS.m_iBottom-IG_LA_Model_Exit_Word_CHS.m_iTop)*IG_LA_Real_Exit_Word.Sy);
    IG_LA_Real_Exit_Word.LA_Width=(int)((IG_LA_Model_Exit_Word_CHS.m_iRight-IG_LA_Model_Exit_Word_CHS.m_iLeft)*IG_LA_Real_Exit_Word.Sx);
    IG_LA_Real_Exit_Word.x=60;
    IG_LA_Real_Exit_Word.y=348;
    IG_LA_Real_Exit_Word.Lx=IG_LA_Real_Exit_Word.x+IG_LA_Real_Exit_Word.LA_Width;
    IG_LA_Real_Exit_Word.Ly=IG_LA_Real_Exit_Word.y+IG_LA_Real_Exit_Word.LA_High;

    IG_LA_Real_Warning_Word.LA_position=IG_LA_Model_Warning_Word_CHS;
    IG_LA_Real_Warning_Word.Sx=0.5f;
    IG_LA_Real_Warning_Word.Sy=0.5f;
    IG_LA_Real_Warning_Word.LA_High=(int)((IG_LA_Model_Warning_Word_CHS.m_iBottom-IG_LA_Model_Warning_Word_CHS.m_iTop)*IG_LA_Real_Exit_Word.Sy);
    IG_LA_Real_Warning_Word.LA_Width=(int)((IG_LA_Model_Warning_Word_CHS.m_iRight-IG_LA_Model_Warning_Word_CHS.m_iLeft)*IG_LA_Real_Exit_Word.Sx);
    IG_LA_Real_Warning_Word.x=60;
    IG_LA_Real_Warning_Word.y=186;
    IG_LA_Real_Warning_Word.Lx=IG_LA_Real_Warning_Word.x+IG_LA_Real_Warning_Word.LA_Width;
    IG_LA_Real_Warning_Word.Ly=IG_LA_Real_Warning_Word.y+IG_LA_Real_Warning_Word.LA_High;


#elif _240_400_&&_EN_

    IG_LA_English_Flag=1;

    IG_LA_Real_BackGround.Sx=0.7f;
    IG_LA_Real_BackGround.Sy=0.7f;
    IG_LA_Real_BackGround.LA_High=(int)(800*IG_LA_Real_BackGround.Sy);
    IG_LA_Real_BackGround.LA_Width=(int)(400*IG_LA_Real_BackGround.Sx);
    IG_LA_Real_BackGround.x=0;
    IG_LA_Real_BackGround.y=0;
    IG_LA_Real_BackGround.Lx=IG_LA_Real_BackGround.x+IG_LA_Real_BackGround.LA_Width;
    IG_LA_Real_BackGround.Ly=IG_LA_Real_BackGround.y+IG_LA_Real_BackGround.LA_High;

    IG_LA_Real_Button1.LA_position=IG_LA_Model_Button1;
    IG_LA_Real_Button1.Sx=0.5f;
    IG_LA_Real_Button1.Sy=0.5f;
    IG_LA_Real_Button1.LA_High=(int)((IG_LA_Model_Button1.m_iBottom-IG_LA_Model_Button1.m_iTop)*IG_LA_Real_Button1.Sy);
    IG_LA_Real_Button1.LA_Width=(int)((IG_LA_Model_Button1.m_iRight-IG_LA_Model_Button1.m_iLeft)*IG_LA_Real_Button1.Sx);
    IG_LA_Real_Button1.x=58;
    IG_LA_Real_Button1.y=274;
    IG_LA_Real_Button1.Lx=IG_LA_Real_Button1.x+IG_LA_Real_Button1.LA_Width;
    IG_LA_Real_Button1.Ly=IG_LA_Real_Button1.y+IG_LA_Real_Button1.LA_High;

    IG_LA_Real_Button1_Enter.LA_position=IG_LA_Model_Button1_Enter;
    IG_LA_Real_Button1_Enter.Sx=0.5f;
    IG_LA_Real_Button1_Enter.Sy=0.5f;
    IG_LA_Real_Button1_Enter.LA_High=(int)((IG_LA_Model_Button1_Enter.m_iBottom-IG_LA_Model_Button1_Enter.m_iTop)*IG_LA_Real_Button1_Enter.Sy);
    IG_LA_Real_Button1_Enter.LA_Width=(int)((IG_LA_Model_Button1_Enter.m_iRight-IG_LA_Model_Button1_Enter.m_iLeft)*IG_LA_Real_Button1_Enter.Sx);
    IG_LA_Real_Button1_Enter.x=58;
    IG_LA_Real_Button1_Enter.y=274;
    IG_LA_Real_Button1_Enter.Lx=IG_LA_Real_Button1_Enter.x+IG_LA_Real_Button1_Enter.LA_Width;
    IG_LA_Real_Button1_Enter.Ly=IG_LA_Real_Button1_Enter.y+IG_LA_Real_Button1_Enter.LA_High;


    IG_LA_Real_ExitButton.LA_position=IG_LA_Model_ExitButton;
    IG_LA_Real_ExitButton.Sx=0.5f;
    IG_LA_Real_ExitButton.Sy=0.5f;
    IG_LA_Real_ExitButton.LA_High=(int)((IG_LA_Model_ExitButton.m_iBottom-IG_LA_Model_ExitButton.m_iTop)*IG_LA_Real_ExitButton.Sy);
    IG_LA_Real_ExitButton.LA_Width=(int)((IG_LA_Model_ExitButton.m_iRight-IG_LA_Model_ExitButton.m_iLeft)*IG_LA_Real_ExitButton.Sx);
    IG_LA_Real_ExitButton.x=80;
    IG_LA_Real_ExitButton.y=338;
    IG_LA_Real_ExitButton.Lx=IG_LA_Real_ExitButton.x+IG_LA_Real_ExitButton.LA_Width;
    IG_LA_Real_ExitButton.Ly=IG_LA_Real_ExitButton.y+IG_LA_Real_ExitButton.LA_High;


    IG_LA_Real_ExitButton_Enter.LA_position=IG_LA_Model_ExitButton_Enter;
    IG_LA_Real_ExitButton_Enter.Sx=0.5f;
    IG_LA_Real_ExitButton_Enter.Sy=0.5f;
    IG_LA_Real_ExitButton_Enter.LA_High=(int)((IG_LA_Model_ExitButton_Enter.m_iBottom-IG_LA_Model_ExitButton_Enter.m_iTop)*IG_LA_Real_ExitButton_Enter.Sy);
    IG_LA_Real_ExitButton_Enter.LA_Width=(int)((IG_LA_Model_ExitButton_Enter.m_iRight-IG_LA_Model_ExitButton_Enter.m_iLeft)*IG_LA_Real_ExitButton_Enter.Sx);
    IG_LA_Real_ExitButton_Enter.x=80;
    IG_LA_Real_ExitButton_Enter.y=338;
    IG_LA_Real_ExitButton_Enter.Lx=IG_LA_Real_ExitButton_Enter.x+IG_LA_Real_ExitButton_Enter.LA_Width;
    IG_LA_Real_ExitButton_Enter.Ly=IG_LA_Real_ExitButton_Enter.y+IG_LA_Real_ExitButton_Enter.LA_High;



    IG_LA_Real_Game_Logo.LA_position=IG_LA_Model_Game_Logo;
    IG_LA_Real_Game_Logo.Sx=0.5f;
    IG_LA_Real_Game_Logo.Sy=0.5f;
    IG_LA_Real_Game_Logo.LA_High=(int)((IG_LA_Model_Game_Logo.m_iBottom-IG_LA_Model_Game_Logo.m_iTop)*IG_LA_Real_Game_Logo.Sy);
    IG_LA_Real_Game_Logo.LA_Width=(int)((IG_LA_Model_Game_Logo.m_iRight-IG_LA_Model_Game_Logo.m_iLeft)*IG_LA_Real_Game_Logo.Sx);
    IG_LA_Real_Game_Logo.x=130;
    IG_LA_Real_Game_Logo.y=80;
    IG_LA_Real_Game_Logo.Lx=IG_LA_Real_Game_Logo.x+IG_LA_Real_Game_Logo.LA_Width;
    IG_LA_Real_Game_Logo.Ly=IG_LA_Real_Game_Logo.y+IG_LA_Real_Game_Logo.LA_High;


    IG_LA_Real_LeftButton.LA_position=IG_LA_Model_LeftButton;
    IG_LA_Real_LeftButton.Sx=0.5f;
    IG_LA_Real_LeftButton.Sy=0.5f;
    IG_LA_Real_LeftButton.LA_High=(int)((IG_LA_Model_LeftButton.m_iBottom-IG_LA_Model_LeftButton.m_iTop)*IG_LA_Real_LeftButton.Sy);
    IG_LA_Real_LeftButton.LA_Width=(int)((IG_LA_Model_LeftButton.m_iRight-IG_LA_Model_LeftButton.m_iLeft)*IG_LA_Real_LeftButton.Sx);
    IG_LA_Real_LeftButton.x=0;
    IG_LA_Real_LeftButton.y=270;
    IG_LA_Real_LeftButton.Lx=IG_LA_Real_LeftButton.x+IG_LA_Real_LeftButton.LA_Width;
    IG_LA_Real_LeftButton.Ly=IG_LA_Real_LeftButton.y+IG_LA_Real_LeftButton.LA_High;


    IG_LA_Real_LeftButton_Enter.LA_position=IG_LA_Model_LeftButton_Enter;
    IG_LA_Real_LeftButton_Enter.Sx=0.5f;
    IG_LA_Real_LeftButton_Enter.Sy=0.5f;
    IG_LA_Real_LeftButton_Enter.LA_High=(int)((IG_LA_Model_LeftButton_Enter.m_iBottom-IG_LA_Model_LeftButton_Enter.m_iTop)*IG_LA_Real_LeftButton_Enter.Sy);
    IG_LA_Real_LeftButton_Enter.LA_Width=(int)((IG_LA_Model_LeftButton_Enter.m_iRight-IG_LA_Model_LeftButton_Enter.m_iLeft)*IG_LA_Real_LeftButton_Enter.Sx);
    IG_LA_Real_LeftButton_Enter.x=0;
    IG_LA_Real_LeftButton_Enter.y=270;
    IG_LA_Real_LeftButton_Enter.Lx=IG_LA_Real_LeftButton_Enter.x+IG_LA_Real_LeftButton_Enter.LA_Width;
    IG_LA_Real_LeftButton_Enter.Ly=IG_LA_Real_LeftButton_Enter.y+IG_LA_Real_LeftButton_Enter.LA_High;


    IG_LA_Real_RightButton.LA_position=IG_LA_Model_RightButton;
    IG_LA_Real_RightButton.Sx=0.5f;
    IG_LA_Real_RightButton.Sy=0.5f;
    IG_LA_Real_RightButton.LA_High=(int)((IG_LA_Model_RightButton.m_iBottom-IG_LA_Model_RightButton.m_iTop)*IG_LA_Real_RightButton.Sy);
    IG_LA_Real_RightButton.LA_Width=(int)((IG_LA_Model_RightButton.m_iRight-IG_LA_Model_RightButton.m_iLeft)*IG_LA_Real_RightButton.Sx);
    IG_LA_Real_RightButton.x=190;
    IG_LA_Real_RightButton.y=270;
    IG_LA_Real_RightButton.Lx=IG_LA_Real_RightButton.x+IG_LA_Real_RightButton.LA_Width;
    IG_LA_Real_RightButton.Ly=IG_LA_Real_RightButton.y+IG_LA_Real_RightButton.LA_High;


    IG_LA_Real_RightButton_Enter.LA_position=IG_LA_Model_RightButton_Enter;
    IG_LA_Real_RightButton_Enter.Sx=0.5f;
    IG_LA_Real_RightButton_Enter.Sy=0.5f;
    IG_LA_Real_RightButton_Enter.LA_High=(int)((IG_LA_Model_RightButton_Enter.m_iBottom-IG_LA_Model_RightButton_Enter.m_iTop)*IG_LA_Real_RightButton_Enter.Sy);
    IG_LA_Real_RightButton_Enter.LA_Width=(int)((IG_LA_Model_RightButton_Enter.m_iRight-IG_LA_Model_RightButton_Enter.m_iLeft)*IG_LA_Real_RightButton_Enter.Sx);
    IG_LA_Real_RightButton_Enter.x=190;
    IG_LA_Real_RightButton_Enter.y=270;
    IG_LA_Real_RightButton_Enter.Lx=IG_LA_Real_RightButton_Enter.x+IG_LA_Real_RightButton_Enter.LA_Width;
    IG_LA_Real_RightButton_Enter.Ly=IG_LA_Real_RightButton_Enter.y+IG_LA_Real_RightButton_Enter.LA_High;


    IG_LA_Real_Company_Logo.LA_position=IG_LA_Model_Company_Logo;
    IG_LA_Real_Company_Logo.Sx=0.5f;
    IG_LA_Real_Company_Logo.Sy=0.5f;
    IG_LA_Real_Company_Logo.LA_High=(int)((IG_LA_Model_Company_Logo.m_iBottom-IG_LA_Model_Company_Logo.m_iTop)*IG_LA_Real_Company_Logo.Sy);
    IG_LA_Real_Company_Logo.LA_Width=(int)((IG_LA_Model_Company_Logo.m_iRight-IG_LA_Model_Company_Logo.m_iLeft)*IG_LA_Real_Company_Logo.Sx);
    IG_LA_Real_Company_Logo.x=11;
    IG_LA_Real_Company_Logo.y=24;
    IG_LA_Real_Company_Logo.Lx=IG_LA_Real_Company_Logo.x+IG_LA_Real_Company_Logo.LA_Width;
    IG_LA_Real_Company_Logo.Ly=IG_LA_Real_Company_Logo.y+IG_LA_Real_Company_Logo.LA_High;


    IG_LA_Real_JE_Logo.LA_position=IG_LA_Model_JE_Logo;
    IG_LA_Real_JE_Logo.Sx=0.5f;
    IG_LA_Real_JE_Logo.Sy=0.5f;
    IG_LA_Real_JE_Logo.LA_High=(int)((IG_LA_Model_JE_Logo.m_iBottom-IG_LA_Model_JE_Logo.m_iTop)*IG_LA_Real_JE_Logo.Sy);
    IG_LA_Real_JE_Logo.LA_Width=(int)((IG_LA_Model_JE_Logo.m_iRight-IG_LA_Model_JE_Logo.m_iLeft)*IG_LA_Real_JE_Logo.Sx);
    IG_LA_Real_JE_Logo.x=56;
    IG_LA_Real_JE_Logo.y=134;
    IG_LA_Real_JE_Logo.Lx=IG_LA_Real_JE_Logo.x+IG_LA_Real_JE_Logo.LA_Width;
    IG_LA_Real_JE_Logo.Ly=IG_LA_Real_JE_Logo.y+IG_LA_Real_JE_Logo.LA_High;


    IG_LA_Real_CW_Logo.LA_position=IG_LA_Model_CW_Logo;
    IG_LA_Real_CW_Logo.Sx=0.5f;
    IG_LA_Real_CW_Logo.Sy=0.5f;
    IG_LA_Real_CW_Logo.LA_High=(int)((IG_LA_Model_CW_Logo.m_iBottom-IG_LA_Model_CW_Logo.m_iTop)*IG_LA_Real_CW_Logo.Sy);
    IG_LA_Real_CW_Logo.LA_Width=(int)((IG_LA_Model_CW_Logo.m_iRight-IG_LA_Model_CW_Logo.m_iLeft)*IG_LA_Real_CW_Logo.Sx);
    IG_LA_Real_CW_Logo.x=56;
    IG_LA_Real_CW_Logo.y=134;
    IG_LA_Real_CW_Logo.Lx=IG_LA_Real_CW_Logo.x+IG_LA_Real_CW_Logo.LA_Width;
    IG_LA_Real_CW_Logo.Ly=IG_LA_Real_CW_Logo.y+IG_LA_Real_CW_Logo.LA_High;


    IG_LA_Real_DA_Logo.LA_position=IG_LA_Model_DA_Logo;
    IG_LA_Real_DA_Logo.Sx=0.5f;
    IG_LA_Real_DA_Logo.Sy=0.5f;
    IG_LA_Real_DA_Logo.LA_High=(int)((IG_LA_Model_DA_Logo.m_iBottom-IG_LA_Model_DA_Logo.m_iTop)*IG_LA_Real_DA_Logo.Sy);
    IG_LA_Real_DA_Logo.LA_Width=(int)((IG_LA_Model_DA_Logo.m_iRight-IG_LA_Model_DA_Logo.m_iLeft)*IG_LA_Real_DA_Logo.Sx);
    IG_LA_Real_DA_Logo.x=56;
    IG_LA_Real_DA_Logo.y=134;
    IG_LA_Real_DA_Logo.Lx=IG_LA_Real_DA_Logo.x+IG_LA_Real_DA_Logo.LA_Width;
    IG_LA_Real_DA_Logo.Ly=IG_LA_Real_DA_Logo.y+IG_LA_Real_DA_Logo.LA_High;


    IG_LA_Real_TK_Logo.LA_position=IG_LA_Model_TK_Logo;
    IG_LA_Real_TK_Logo.Sx=0.5f;
    IG_LA_Real_TK_Logo.Sy=0.5f;
    IG_LA_Real_TK_Logo.LA_High=(int)((IG_LA_Model_TK_Logo.m_iBottom-IG_LA_Model_TK_Logo.m_iTop)*IG_LA_Real_TK_Logo.Sy);
    IG_LA_Real_TK_Logo.LA_Width=(int)((IG_LA_Model_TK_Logo.m_iRight-IG_LA_Model_TK_Logo.m_iLeft)*IG_LA_Real_TK_Logo.Sx);
    IG_LA_Real_TK_Logo.x=56;
    IG_LA_Real_TK_Logo.y=134;
    IG_LA_Real_TK_Logo.Lx=IG_LA_Real_TK_Logo.x+IG_LA_Real_TK_Logo.LA_Width;
    IG_LA_Real_TK_Logo.Ly=IG_LA_Real_TK_Logo.y+IG_LA_Real_TK_Logo.LA_High;


    IG_LA_Real_DA_Word.LA_position=IG_LA_Model_DA_Word_ENG;
    IG_LA_Real_DA_Word.Sx=0.5f;
    IG_LA_Real_DA_Word.Sy=0.5f;
    IG_LA_Real_DA_Word.LA_High=(int)((IG_LA_Model_DA_Word_ENG.m_iBottom-IG_LA_Model_DA_Word_ENG.m_iTop)*IG_LA_Real_DA_Word.Sy);
    IG_LA_Real_DA_Word.LA_Width=(int)((IG_LA_Model_DA_Word_ENG.m_iRight-IG_LA_Model_DA_Word_ENG.m_iLeft)*IG_LA_Real_DA_Word.Sx);
    IG_LA_Real_DA_Word.x=60;
    IG_LA_Real_DA_Word.y=286;
    IG_LA_Real_DA_Word.Lx=IG_LA_Real_DA_Word.x+IG_LA_Real_DA_Word.LA_Width;
    IG_LA_Real_DA_Word.Ly=IG_LA_Real_DA_Word.y+IG_LA_Real_DA_Word.LA_High;


    IG_LA_Real_CW_Word.LA_position=IG_LA_Model_CW_Word_ENG;
    IG_LA_Real_CW_Word.Sx=0.5f;
    IG_LA_Real_CW_Word.Sy=0.5f;
    IG_LA_Real_CW_Word.LA_High=(int)((IG_LA_Model_CW_Word_ENG.m_iBottom-IG_LA_Model_CW_Word_ENG.m_iTop)*IG_LA_Real_CW_Word.Sy);
    IG_LA_Real_CW_Word.LA_Width=(int)((IG_LA_Model_CW_Word_ENG.m_iRight-IG_LA_Model_CW_Word_ENG.m_iLeft)*IG_LA_Real_CW_Word.Sx);
    IG_LA_Real_CW_Word.x=60;
    IG_LA_Real_CW_Word.y=286;
    IG_LA_Real_CW_Word.Lx=IG_LA_Real_CW_Word.x+IG_LA_Real_CW_Word.LA_Width;
    IG_LA_Real_CW_Word.Ly=IG_LA_Real_CW_Word.y+IG_LA_Real_CW_Word.LA_High;


    IG_LA_Real_JE_Word.LA_position=IG_LA_Model_JE_Word_ENG;
    IG_LA_Real_JE_Word.Sx=0.5f;
    IG_LA_Real_JE_Word.Sy=0.5f;
    IG_LA_Real_JE_Word.LA_High=(int)((IG_LA_Model_JE_Word_ENG.m_iBottom-IG_LA_Model_JE_Word_ENG.m_iTop)*IG_LA_Real_JE_Word.Sy);
    IG_LA_Real_JE_Word.LA_Width=(int)((IG_LA_Model_JE_Word_ENG.m_iRight-IG_LA_Model_JE_Word_ENG.m_iLeft)*IG_LA_Real_JE_Word.Sx);
    IG_LA_Real_JE_Word.x=60;
    IG_LA_Real_JE_Word.y=286;
    IG_LA_Real_JE_Word.Lx=IG_LA_Real_JE_Word.x+IG_LA_Real_JE_Word.LA_Width;
    IG_LA_Real_JE_Word.Ly=IG_LA_Real_JE_Word.y+IG_LA_Real_JE_Word.LA_High;


    IG_LA_Real_TK_Word.LA_position=IG_LA_Model_TK_Word_ENG;
    IG_LA_Real_TK_Word.Sx=0.5f;
    IG_LA_Real_TK_Word.Sy=0.5f;
    IG_LA_Real_TK_Word.LA_High=(int)((IG_LA_Model_TK_Word_ENG.m_iBottom-IG_LA_Model_TK_Word_ENG.m_iTop)*IG_LA_Real_TK_Word.Sy);
    IG_LA_Real_TK_Word.LA_Width=(int)((IG_LA_Model_TK_Word_ENG.m_iRight-IG_LA_Model_TK_Word_ENG.m_iLeft)*IG_LA_Real_TK_Word.Sx);
    IG_LA_Real_TK_Word.x=60;
    IG_LA_Real_TK_Word.y=286;
    IG_LA_Real_TK_Word.Lx=IG_LA_Real_TK_Word.x+IG_LA_Real_TK_Word.LA_Width;
    IG_LA_Real_TK_Word.Ly=IG_LA_Real_TK_Word.y+IG_LA_Real_TK_Word.LA_High;


    IG_LA_Real_Exit_Word.LA_position=IG_LA_Model_Exit_Word_ENG;
    IG_LA_Real_Exit_Word.Sx=0.5f;
    IG_LA_Real_Exit_Word.Sy=0.5f;
    IG_LA_Real_Exit_Word.LA_High=(int)((IG_LA_Model_Exit_Word_ENG.m_iBottom-IG_LA_Model_Exit_Word_ENG.m_iTop)*IG_LA_Real_Exit_Word.Sy);
    IG_LA_Real_Exit_Word.LA_Width=(int)((IG_LA_Model_Exit_Word_ENG.m_iRight-IG_LA_Model_Exit_Word_ENG.m_iLeft)*IG_LA_Real_Exit_Word.Sx);
    IG_LA_Real_Exit_Word.x=60;
    IG_LA_Real_Exit_Word.y=348;
    IG_LA_Real_Exit_Word.Lx=IG_LA_Real_Exit_Word.x+IG_LA_Real_Exit_Word.LA_Width;
    IG_LA_Real_Exit_Word.Ly=IG_LA_Real_Exit_Word.y+IG_LA_Real_Exit_Word.LA_High;

    IG_LA_Real_Warning_Word.LA_position=IG_LA_Model_Warning_Word_ENG;
    IG_LA_Real_Warning_Word.Sx=0.5f;
    IG_LA_Real_Warning_Word.Sy=0.5f;
    IG_LA_Real_Warning_Word.LA_High=(int)((IG_LA_Model_Warning_Word_CHS.m_iBottom-IG_LA_Model_Warning_Word_CHS.m_iTop)*IG_LA_Real_Exit_Word.Sy);
    IG_LA_Real_Warning_Word.LA_Width=(int)((IG_LA_Model_Warning_Word_CHS.m_iRight-IG_LA_Model_Warning_Word_CHS.m_iLeft)*IG_LA_Real_Exit_Word.Sx);
    IG_LA_Real_Warning_Word.x=60;
    IG_LA_Real_Warning_Word.y=186;
    IG_LA_Real_Warning_Word.Lx=IG_LA_Real_Warning_Word.x+IG_LA_Real_Warning_Word.LA_Width;
    IG_LA_Real_Warning_Word.Ly=IG_LA_Real_Warning_Word.y+IG_LA_Real_Warning_Word.LA_High;

#elif _480_800_&&_CHS_
    IG_LA_Real_BackGround.Sx=1;
    IG_LA_Real_BackGround.Sy=1;
    IG_LA_Real_BackGround.LA_High=(int)(800*IG_LA_Real_BackGround.Sy);
    IG_LA_Real_BackGround.LA_Width=(int)(400*IG_LA_Real_BackGround.Sx);
    IG_LA_Real_BackGround.x=0;
    IG_LA_Real_BackGround.y=0;
    IG_LA_Real_BackGround.Lx=IG_LA_Real_BackGround.x+IG_LA_Real_BackGround.LA_Width;
    IG_LA_Real_BackGround.Ly=IG_LA_Real_BackGround.y+IG_LA_Real_BackGround.LA_High;


    IG_LA_Real_Button1.LA_position=IG_LA_Model_Button1;
    IG_LA_Real_Button1.Sx=1;
    IG_LA_Real_Button1.Sy=1;
    IG_LA_Real_Button1.LA_High=(int)((IG_LA_Model_Button1.m_iBottom-IG_LA_Model_Button1.m_iTop)*IG_LA_Real_Button1.Sy);
    IG_LA_Real_Button1.LA_Width=(int)((IG_LA_Model_Button1.m_iRight-IG_LA_Model_Button1.m_iLeft)*IG_LA_Real_Button1.Sx);
    IG_LA_Real_Button1.x=116;
    IG_LA_Real_Button1.y=551;
    IG_LA_Real_Button1.Lx=IG_LA_Real_Button1.x+IG_LA_Real_Button1.LA_Width;
    IG_LA_Real_Button1.Ly=IG_LA_Real_Button1.y+IG_LA_Real_Button1.LA_High;

    
    IG_LA_Real_Button1_Enter.LA_position=IG_LA_Model_Button1_Enter;
    IG_LA_Real_Button1_Enter.Sx=1;
    IG_LA_Real_Button1_Enter.Sy=1;
    IG_LA_Real_Button1_Enter.LA_High=(int)((IG_LA_Model_Button1_Enter.m_iBottom-IG_LA_Model_Button1_Enter.m_iTop)*IG_LA_Real_Button1_Enter.Sy);
    IG_LA_Real_Button1_Enter.LA_Width=(int)((IG_LA_Model_Button1_Enter.m_iRight-IG_LA_Model_Button1_Enter.m_iLeft)*IG_LA_Real_Button1_Enter.Sx);
    IG_LA_Real_Button1_Enter.x=116;
    IG_LA_Real_Button1_Enter.y=551;
    IG_LA_Real_Button1_Enter.Lx=IG_LA_Real_Button1_Enter.x+IG_LA_Real_Button1_Enter.LA_Width;
    IG_LA_Real_Button1_Enter.Ly=IG_LA_Real_Button1_Enter.y+IG_LA_Real_Button1_Enter.LA_High;


    IG_LA_Real_ExitButton.LA_position=IG_LA_Model_ExitButton;
    IG_LA_Real_ExitButton.Sx=1;
    IG_LA_Real_ExitButton.Sy=1;
    IG_LA_Real_ExitButton.LA_High=(int)((IG_LA_Model_ExitButton.m_iBottom-IG_LA_Model_ExitButton.m_iTop)*IG_LA_Real_ExitButton.Sy);
    IG_LA_Real_ExitButton.LA_Width=(int)((IG_LA_Model_ExitButton.m_iRight-IG_LA_Model_ExitButton.m_iLeft)*IG_LA_Real_ExitButton.Sx);
    IG_LA_Real_ExitButton.x=160;
    IG_LA_Real_ExitButton.y=692;
    IG_LA_Real_ExitButton.Lx=IG_LA_Real_ExitButton.x+IG_LA_Real_ExitButton.LA_Width;
    IG_LA_Real_ExitButton.Ly=IG_LA_Real_ExitButton.y+IG_LA_Real_ExitButton.LA_High;


    IG_LA_Real_ExitButton_Enter.LA_position=IG_LA_Model_ExitButton_Enter;
    IG_LA_Real_ExitButton_Enter.Sx=1;
    IG_LA_Real_ExitButton_Enter.Sy=1;
    IG_LA_Real_ExitButton_Enter.LA_High=(int)((IG_LA_Model_ExitButton_Enter.m_iBottom-IG_LA_Model_ExitButton_Enter.m_iTop)*IG_LA_Real_ExitButton_Enter.Sy);
    IG_LA_Real_ExitButton_Enter.LA_Width=(int)((IG_LA_Model_ExitButton_Enter.m_iRight-IG_LA_Model_ExitButton_Enter.m_iLeft)*IG_LA_Real_ExitButton_Enter.Sx);
    IG_LA_Real_ExitButton_Enter.x=160;
    IG_LA_Real_ExitButton_Enter.y=692;
    IG_LA_Real_ExitButton_Enter.Lx=IG_LA_Real_ExitButton_Enter.x+IG_LA_Real_ExitButton_Enter.LA_Width;
    IG_LA_Real_ExitButton_Enter.Ly=IG_LA_Real_ExitButton_Enter.y+IG_LA_Real_ExitButton_Enter.LA_High;


    IG_LA_Real_Game_Logo.LA_position=IG_LA_Model_Game_Logo;
    IG_LA_Real_Game_Logo.Sx=1;
    IG_LA_Real_Game_Logo.Sy=1;
    IG_LA_Real_Game_Logo.LA_High=(int)((IG_LA_Model_Game_Logo.m_iBottom-IG_LA_Model_Game_Logo.m_iTop)*IG_LA_Real_Game_Logo.Sy);
    IG_LA_Real_Game_Logo.LA_Width=(int)((IG_LA_Model_Game_Logo.m_iRight-IG_LA_Model_Game_Logo.m_iLeft)*IG_LA_Real_Game_Logo.Sx);
    IG_LA_Real_Game_Logo.x=264;
    IG_LA_Real_Game_Logo.y=180;
    IG_LA_Real_Game_Logo.Lx=IG_LA_Real_Game_Logo.x+IG_LA_Real_Game_Logo.LA_Width;
    IG_LA_Real_Game_Logo.Ly=IG_LA_Real_Game_Logo.y+IG_LA_Real_Game_Logo.LA_High;


    IG_LA_Real_LeftButton.LA_position=IG_LA_Model_LeftButton;
    IG_LA_Real_LeftButton.Sx=1;
    IG_LA_Real_LeftButton.Sy=1;
    IG_LA_Real_LeftButton.LA_High=(int)((IG_LA_Model_LeftButton.m_iBottom-IG_LA_Model_LeftButton.m_iTop)*IG_LA_Real_LeftButton.Sy);
    IG_LA_Real_LeftButton.LA_Width=(int)((IG_LA_Model_LeftButton.m_iRight-IG_LA_Model_LeftButton.m_iLeft)*IG_LA_Real_LeftButton.Sx);
    IG_LA_Real_LeftButton.x=0;
    IG_LA_Real_LeftButton.y=541;
    IG_LA_Real_LeftButton.Lx=IG_LA_Real_LeftButton.x+IG_LA_Real_LeftButton.LA_Width;
    IG_LA_Real_LeftButton.Ly=IG_LA_Real_LeftButton.y+IG_LA_Real_LeftButton.LA_High;


    IG_LA_Real_LeftButton_Enter.LA_position=IG_LA_Model_LeftButton_Enter;
    IG_LA_Real_LeftButton_Enter.Sx=1;
    IG_LA_Real_LeftButton_Enter.Sy=1;
    IG_LA_Real_LeftButton_Enter.LA_High=(int)((IG_LA_Model_LeftButton_Enter.m_iBottom-IG_LA_Model_LeftButton_Enter.m_iTop)*IG_LA_Real_LeftButton_Enter.Sy);
    IG_LA_Real_LeftButton_Enter.LA_Width=(int)((IG_LA_Model_LeftButton_Enter.m_iRight-IG_LA_Model_LeftButton_Enter.m_iLeft)*IG_LA_Real_LeftButton_Enter.Sx);
    IG_LA_Real_LeftButton_Enter.x=0;
    IG_LA_Real_LeftButton_Enter.y=541;
    IG_LA_Real_LeftButton_Enter.Lx=IG_LA_Real_LeftButton_Enter.x+IG_LA_Real_LeftButton_Enter.LA_Width;
    IG_LA_Real_LeftButton_Enter.Ly=IG_LA_Real_LeftButton_Enter.y+IG_LA_Real_LeftButton_Enter.LA_High;


    IG_LA_Real_RightButton.LA_position=IG_LA_Model_RightButton;    
    IG_LA_Real_RightButton.Sx=1;
    IG_LA_Real_RightButton.Sy=1;
    IG_LA_Real_RightButton.LA_High=(int)((IG_LA_Model_RightButton.m_iBottom-IG_LA_Model_RightButton.m_iTop)*IG_LA_Real_RightButton.Sy);
    IG_LA_Real_RightButton.LA_Width=(int)((IG_LA_Model_RightButton.m_iRight-IG_LA_Model_RightButton.m_iLeft)*IG_LA_Real_RightButton.Sx);
    IG_LA_Real_RightButton.x=380;
    IG_LA_Real_RightButton.y=541;
    IG_LA_Real_RightButton.Lx=IG_LA_Real_RightButton.x+IG_LA_Real_RightButton.LA_Width;
    IG_LA_Real_RightButton.Ly=IG_LA_Real_RightButton.y+IG_LA_Real_RightButton.LA_High;


    IG_LA_Real_RightButton_Enter.LA_position=IG_LA_Model_RightButton_Enter;
    IG_LA_Real_RightButton_Enter.Sx=1;
    IG_LA_Real_RightButton_Enter.Sy=1;
    IG_LA_Real_RightButton_Enter.LA_High=(int)((IG_LA_Model_RightButton_Enter.m_iBottom-IG_LA_Model_RightButton_Enter.m_iTop)*IG_LA_Real_RightButton_Enter.Sy);
    IG_LA_Real_RightButton_Enter.LA_Width=(int)((IG_LA_Model_RightButton_Enter.m_iRight-IG_LA_Model_RightButton_Enter.m_iLeft)*IG_LA_Real_RightButton_Enter.Sx);
    IG_LA_Real_RightButton_Enter.x=380;
    IG_LA_Real_RightButton_Enter.y=541;
    IG_LA_Real_RightButton_Enter.Lx=IG_LA_Real_RightButton_Enter.x+IG_LA_Real_RightButton_Enter.LA_Width;
    IG_LA_Real_RightButton_Enter.Ly=IG_LA_Real_RightButton_Enter.y+IG_LA_Real_RightButton_Enter.LA_High;

    
    IG_LA_Real_Company_Logo.LA_position=IG_LA_Model_Company_Logo;
    IG_LA_Real_Company_Logo.Sx=1;
    IG_LA_Real_Company_Logo.Sy=1;
    IG_LA_Real_Company_Logo.LA_High=(int)((IG_LA_Model_Company_Logo.m_iBottom-IG_LA_Model_Company_Logo.m_iTop)*IG_LA_Real_Company_Logo.Sy);
    IG_LA_Real_Company_Logo.LA_Width=(int)((IG_LA_Model_Company_Logo.m_iRight-IG_LA_Model_Company_Logo.m_iLeft)*IG_LA_Real_Company_Logo.Sx);
    IG_LA_Real_Company_Logo.x=27;
    IG_LA_Real_Company_Logo.y=72;
    IG_LA_Real_Company_Logo.Lx=IG_LA_Real_Company_Logo.x+IG_LA_Real_Company_Logo.LA_Width;
    IG_LA_Real_Company_Logo.Ly=IG_LA_Real_Company_Logo.y+IG_LA_Real_Company_Logo.LA_High;

    
    IG_LA_Real_JE_Logo.LA_position=IG_LA_Model_JE_Logo;
    IG_LA_Real_JE_Logo.Sx=1;
    IG_LA_Real_JE_Logo.Sy=1;
    IG_LA_Real_JE_Logo.LA_High=(int)((IG_LA_Model_JE_Logo.m_iBottom-IG_LA_Model_JE_Logo.m_iTop)*IG_LA_Real_JE_Logo.Sy);
    IG_LA_Real_JE_Logo.LA_Width=(int)((IG_LA_Model_JE_Logo.m_iRight-IG_LA_Model_JE_Logo.m_iLeft)*IG_LA_Real_JE_Logo.Sx);
    IG_LA_Real_JE_Logo.x=112;
    IG_LA_Real_JE_Logo.y=271;
    IG_LA_Real_JE_Logo.Lx=IG_LA_Real_JE_Logo.x+IG_LA_Real_JE_Logo.LA_Width;
    IG_LA_Real_JE_Logo.Ly=IG_LA_Real_JE_Logo.y+IG_LA_Real_JE_Logo.LA_High;


    IG_LA_Real_CW_Logo.LA_position=IG_LA_Model_CW_Logo;
    IG_LA_Real_CW_Logo.Sx=1;
    IG_LA_Real_CW_Logo.Sy=1;
    IG_LA_Real_CW_Logo.LA_High=(int)((IG_LA_Model_CW_Logo.m_iBottom-IG_LA_Model_CW_Logo.m_iTop)*IG_LA_Real_CW_Logo.Sy);
    IG_LA_Real_CW_Logo.LA_Width=(int)((IG_LA_Model_CW_Logo.m_iRight-IG_LA_Model_CW_Logo.m_iLeft)*IG_LA_Real_CW_Logo.Sx);
    IG_LA_Real_CW_Logo.x=112;
    IG_LA_Real_CW_Logo.y=271;
    IG_LA_Real_CW_Logo.Lx=IG_LA_Real_CW_Logo.x+IG_LA_Real_CW_Logo.LA_Width;
    IG_LA_Real_CW_Logo.Ly=IG_LA_Real_CW_Logo.y+IG_LA_Real_CW_Logo.LA_High;


    IG_LA_Real_DA_Logo.LA_position=IG_LA_Model_DA_Logo;
    IG_LA_Real_DA_Logo.Sx=1;
    IG_LA_Real_DA_Logo.Sy=1;
    IG_LA_Real_DA_Logo.LA_High=(int)((IG_LA_Model_DA_Logo.m_iBottom-IG_LA_Model_DA_Logo.m_iTop)*IG_LA_Real_DA_Logo.Sy);
    IG_LA_Real_DA_Logo.LA_Width=(int)((IG_LA_Model_DA_Logo.m_iRight-IG_LA_Model_DA_Logo.m_iLeft)*IG_LA_Real_DA_Logo.Sx);
    IG_LA_Real_DA_Logo.x=112;
    IG_LA_Real_DA_Logo.y=271;
    IG_LA_Real_DA_Logo.Lx=IG_LA_Real_DA_Logo.x+IG_LA_Real_DA_Logo.LA_Width;
    IG_LA_Real_DA_Logo.Ly=IG_LA_Real_DA_Logo.y+IG_LA_Real_DA_Logo.LA_High;


    IG_LA_Real_TK_Logo.LA_position=IG_LA_Model_TK_Logo;
    IG_LA_Real_TK_Logo.Sx=1;
    IG_LA_Real_TK_Logo.Sy=1;
    IG_LA_Real_TK_Logo.LA_High=(int)((IG_LA_Model_TK_Logo.m_iBottom-IG_LA_Model_TK_Logo.m_iTop)*IG_LA_Real_TK_Logo.Sy);
    IG_LA_Real_TK_Logo.LA_Width=(int)((IG_LA_Model_TK_Logo.m_iRight-IG_LA_Model_TK_Logo.m_iLeft)*IG_LA_Real_TK_Logo.Sx);
    IG_LA_Real_TK_Logo.x=112;
    IG_LA_Real_TK_Logo.y=271;
    IG_LA_Real_TK_Logo.Lx=IG_LA_Real_TK_Logo.x+IG_LA_Real_TK_Logo.LA_Width;
    IG_LA_Real_TK_Logo.Ly=IG_LA_Real_TK_Logo.y+IG_LA_Real_TK_Logo.LA_High;


    IG_LA_Real_DA_Word.LA_position=IG_LA_Model_DA_Word_CHS;
    IG_LA_Real_DA_Word.Sx=1;
    IG_LA_Real_DA_Word.Sy=1;
    IG_LA_Real_DA_Word.LA_High=(int)((IG_LA_Model_DA_Word_CHS.m_iBottom-IG_LA_Model_DA_Word_CHS.m_iTop)*IG_LA_Real_DA_Word.Sy);
    IG_LA_Real_DA_Word.LA_Width=(int)((IG_LA_Model_DA_Word_CHS.m_iRight-IG_LA_Model_DA_Word_CHS.m_iLeft)*IG_LA_Real_DA_Word.Sx);
    IG_LA_Real_DA_Word.x=120;
    IG_LA_Real_DA_Word.y=581;
    IG_LA_Real_DA_Word.Lx=IG_LA_Real_DA_Word.x+IG_LA_Real_DA_Word.LA_Width;
    IG_LA_Real_DA_Word.Ly=IG_LA_Real_DA_Word.y+IG_LA_Real_DA_Word.LA_High;


    IG_LA_Real_CW_Word.LA_position=IG_LA_Model_CW_Word_CHS;
    IG_LA_Real_CW_Word.Sx=1;
    IG_LA_Real_CW_Word.Sy=1;
    IG_LA_Real_CW_Word.LA_High=(int)((IG_LA_Model_CW_Word_CHS.m_iBottom-IG_LA_Model_CW_Word_CHS.m_iTop)*IG_LA_Real_CW_Word.Sy);
    IG_LA_Real_CW_Word.LA_Width=(int)((IG_LA_Model_CW_Word_CHS.m_iRight-IG_LA_Model_CW_Word_CHS.m_iLeft)*IG_LA_Real_CW_Word.Sx);
    IG_LA_Real_CW_Word.x=120;
    IG_LA_Real_CW_Word.y=581;
    IG_LA_Real_CW_Word.Lx=IG_LA_Real_CW_Word.x+IG_LA_Real_CW_Word.LA_Width;
    IG_LA_Real_CW_Word.Ly=IG_LA_Real_CW_Word.y+IG_LA_Real_CW_Word.LA_High;


    IG_LA_Real_JE_Word.LA_position=IG_LA_Model_JE_Word_CHS;
    IG_LA_Real_JE_Word.Sx=1;
    IG_LA_Real_JE_Word.Sy=1;
    IG_LA_Real_JE_Word.LA_High=(int)((IG_LA_Model_JE_Word_CHS.m_iBottom-IG_LA_Model_JE_Word_CHS.m_iTop)*IG_LA_Real_JE_Word.Sy);
    IG_LA_Real_JE_Word.LA_Width=(int)((IG_LA_Model_JE_Word_CHS.m_iRight-IG_LA_Model_JE_Word_CHS.m_iLeft)*IG_LA_Real_JE_Word.Sx);
    IG_LA_Real_JE_Word.x=120;
    IG_LA_Real_JE_Word.y=581;
    IG_LA_Real_JE_Word.Lx=IG_LA_Real_JE_Word.x+IG_LA_Real_JE_Word.LA_Width;
    IG_LA_Real_JE_Word.Ly=IG_LA_Real_JE_Word.y+IG_LA_Real_JE_Word.LA_High;


    IG_LA_Real_TK_Word.LA_position=IG_LA_Model_TK_Word_CHS;
    IG_LA_Real_TK_Word.Sx=1;
    IG_LA_Real_TK_Word.Sy=1;
    IG_LA_Real_TK_Word.LA_High=(int)((IG_LA_Model_TK_Word_CHS.m_iBottom-IG_LA_Model_TK_Word_CHS.m_iTop)*IG_LA_Real_TK_Word.Sy);
    IG_LA_Real_TK_Word.LA_Width=(int)((IG_LA_Model_TK_Word_CHS.m_iRight-IG_LA_Model_TK_Word_CHS.m_iLeft)*IG_LA_Real_TK_Word.Sx);
    IG_LA_Real_TK_Word.x=120;
    IG_LA_Real_TK_Word.y=581;
    IG_LA_Real_TK_Word.Lx=IG_LA_Real_TK_Word.x+IG_LA_Real_TK_Word.LA_Width;
    IG_LA_Real_TK_Word.Ly=IG_LA_Real_TK_Word.y+IG_LA_Real_TK_Word.LA_High;


    IG_LA_Real_Exit_Word.LA_position=IG_LA_Model_Exit_Word_CHS;
    IG_LA_Real_Exit_Word.Sx=1;
    IG_LA_Real_Exit_Word.Sy=1;
    IG_LA_Real_Exit_Word.LA_High=(int)((IG_LA_Model_Exit_Word_CHS.m_iBottom-IG_LA_Model_Exit_Word_CHS.m_iTop)*IG_LA_Real_Exit_Word.Sy);
    IG_LA_Real_Exit_Word.LA_Width=(int)((IG_LA_Model_Exit_Word_CHS.m_iRight-IG_LA_Model_Exit_Word_CHS.m_iLeft)*IG_LA_Real_Exit_Word.Sx);
    IG_LA_Real_Exit_Word.x=125;
    IG_LA_Real_Exit_Word.y=710;
    IG_LA_Real_Exit_Word.Lx=IG_LA_Real_Exit_Word.x+IG_LA_Real_Exit_Word.LA_Width;
    IG_LA_Real_Exit_Word.Ly=IG_LA_Real_Exit_Word.y+IG_LA_Real_Exit_Word.LA_High;

    IG_LA_Real_Warning_Word.LA_position=IG_LA_Model_Warning_Word_CHS;
    IG_LA_Real_Warning_Word.Sx=1;
    IG_LA_Real_Warning_Word.Sy=1;
    IG_LA_Real_Warning_Word.LA_High=(int)((IG_LA_Model_Warning_Word_CHS.m_iBottom-IG_LA_Model_Warning_Word_CHS.m_iTop)*IG_LA_Real_Exit_Word.Sy);
    IG_LA_Real_Warning_Word.LA_Width=(int)((IG_LA_Model_Warning_Word_CHS.m_iRight-IG_LA_Model_Warning_Word_CHS.m_iLeft)*IG_LA_Real_Exit_Word.Sx);
    IG_LA_Real_Warning_Word.x=120;
    IG_LA_Real_Warning_Word.y=381;
    IG_LA_Real_Warning_Word.Lx=IG_LA_Real_Warning_Word.x+IG_LA_Real_Warning_Word.LA_Width;
    IG_LA_Real_Warning_Word.Ly=IG_LA_Real_Warning_Word.y+IG_LA_Real_Warning_Word.LA_High;


#elif _480_800_&&_EN_

    IG_LA_English_Flag=1;

    IG_LA_Real_BackGround.Sx=1;
    IG_LA_Real_BackGround.Sy=1;
    IG_LA_Real_BackGround.LA_High=(int)(800*IG_LA_Real_BackGround.Sy);
    IG_LA_Real_BackGround.LA_Width=(int)(400*IG_LA_Real_BackGround.Sx);
    IG_LA_Real_BackGround.x=0;
    IG_LA_Real_BackGround.y=0;
    IG_LA_Real_BackGround.Lx=IG_LA_Real_BackGround.x+IG_LA_Real_BackGround.LA_Width;
    IG_LA_Real_BackGround.Ly=IG_LA_Real_BackGround.y+IG_LA_Real_BackGround.LA_High;

    IG_LA_Real_Button1.LA_position=IG_LA_Model_Button1;
    IG_LA_Real_Button1.Sx=1;
    IG_LA_Real_Button1.Sy=1;
    IG_LA_Real_Button1.LA_High=(int)((IG_LA_Model_Button1.m_iBottom-IG_LA_Model_Button1.m_iTop)*IG_LA_Real_Button1.Sy);
    IG_LA_Real_Button1.LA_Width=(int)((IG_LA_Model_Button1.m_iRight-IG_LA_Model_Button1.m_iLeft)*IG_LA_Real_Button1.Sx);
    IG_LA_Real_Button1.x=116;
    IG_LA_Real_Button1.y=551;
    IG_LA_Real_Button1.Lx=IG_LA_Real_Button1.x+IG_LA_Real_Button1.LA_Width;
    IG_LA_Real_Button1.Ly=IG_LA_Real_Button1.y+IG_LA_Real_Button1.LA_High;

    IG_LA_Real_Button1_Enter.LA_position=IG_LA_Model_Button1_Enter;
    IG_LA_Real_Button1_Enter.Sx=1;
    IG_LA_Real_Button1_Enter.Sy=1;
    IG_LA_Real_Button1_Enter.LA_High=(int)((IG_LA_Model_Button1_Enter.m_iBottom-IG_LA_Model_Button1_Enter.m_iTop)*IG_LA_Real_Button1_Enter.Sy);
    IG_LA_Real_Button1_Enter.LA_Width=(int)((IG_LA_Model_Button1_Enter.m_iRight-IG_LA_Model_Button1_Enter.m_iLeft)*IG_LA_Real_Button1_Enter.Sx);
    IG_LA_Real_Button1_Enter.x=116;
    IG_LA_Real_Button1_Enter.y=551;
    IG_LA_Real_Button1_Enter.Lx=IG_LA_Real_Button1_Enter.x+IG_LA_Real_Button1_Enter.LA_Width;
    IG_LA_Real_Button1_Enter.Ly=IG_LA_Real_Button1_Enter.y+IG_LA_Real_Button1_Enter.LA_High;


    IG_LA_Real_ExitButton.LA_position=IG_LA_Model_ExitButton;
    IG_LA_Real_ExitButton.Sx=1;
    IG_LA_Real_ExitButton.Sy=1;
    IG_LA_Real_ExitButton.LA_High=(int)((IG_LA_Model_ExitButton.m_iBottom-IG_LA_Model_ExitButton.m_iTop)*IG_LA_Real_ExitButton.Sy);
    IG_LA_Real_ExitButton.LA_Width=(int)((IG_LA_Model_ExitButton.m_iRight-IG_LA_Model_ExitButton.m_iLeft)*IG_LA_Real_ExitButton.Sx);
    IG_LA_Real_ExitButton.x=160;
    IG_LA_Real_ExitButton.y=692;
    IG_LA_Real_ExitButton.Lx=IG_LA_Real_ExitButton.x+IG_LA_Real_ExitButton.LA_Width;
    IG_LA_Real_ExitButton.Ly=IG_LA_Real_ExitButton.y+IG_LA_Real_ExitButton.LA_High;

    IG_LA_Real_ExitButton_Enter.LA_position=IG_LA_Model_ExitButton_Enter;
    IG_LA_Real_ExitButton_Enter.Sx=1;
    IG_LA_Real_ExitButton_Enter.Sy=1;
    IG_LA_Real_ExitButton_Enter.LA_High=(int)((IG_LA_Model_ExitButton_Enter.m_iBottom-IG_LA_Model_ExitButton_Enter.m_iTop)*IG_LA_Real_ExitButton_Enter.Sy);
    IG_LA_Real_ExitButton_Enter.LA_Width=(int)((IG_LA_Model_ExitButton_Enter.m_iRight-IG_LA_Model_ExitButton_Enter.m_iLeft)*IG_LA_Real_ExitButton_Enter.Sx);
    IG_LA_Real_ExitButton_Enter.x=160;
    IG_LA_Real_ExitButton_Enter.y=692;
    IG_LA_Real_ExitButton_Enter.Lx=IG_LA_Real_ExitButton_Enter.x+IG_LA_Real_ExitButton_Enter.LA_Width;
    IG_LA_Real_ExitButton_Enter.Ly=IG_LA_Real_ExitButton_Enter.y+IG_LA_Real_ExitButton_Enter.LA_High;

    IG_LA_Real_Game_Logo.LA_position=IG_LA_Model_Game_Logo;
    IG_LA_Real_Game_Logo.Sx=1;
    IG_LA_Real_Game_Logo.Sy=1;
    IG_LA_Real_Game_Logo.LA_High=(int)((IG_LA_Model_Game_Logo.m_iBottom-IG_LA_Model_Game_Logo.m_iTop)*IG_LA_Real_Game_Logo.Sy);
    IG_LA_Real_Game_Logo.LA_Width=(int)((IG_LA_Model_Game_Logo.m_iRight-IG_LA_Model_Game_Logo.m_iLeft)*IG_LA_Real_Game_Logo.Sx);
    IG_LA_Real_Game_Logo.x=264;
    IG_LA_Real_Game_Logo.y=180;
    IG_LA_Real_Game_Logo.Lx=IG_LA_Real_Game_Logo.x+IG_LA_Real_Game_Logo.LA_Width;
    IG_LA_Real_Game_Logo.Ly=IG_LA_Real_Game_Logo.y+IG_LA_Real_Game_Logo.LA_High;

    IG_LA_Real_LeftButton.LA_position=IG_LA_Model_LeftButton;
    IG_LA_Real_LeftButton.Sx=1;
    IG_LA_Real_LeftButton.Sy=1;
    IG_LA_Real_LeftButton.LA_High=(int)((IG_LA_Model_LeftButton.m_iBottom-IG_LA_Model_LeftButton.m_iTop)*IG_LA_Real_LeftButton.Sy);
    IG_LA_Real_LeftButton.LA_Width=(int)((IG_LA_Model_LeftButton.m_iRight-IG_LA_Model_LeftButton.m_iLeft)*IG_LA_Real_LeftButton.Sx);
    IG_LA_Real_LeftButton.x=0;
    IG_LA_Real_LeftButton.y=541;
    IG_LA_Real_LeftButton.Lx=IG_LA_Real_LeftButton.x+IG_LA_Real_LeftButton.LA_Width;
    IG_LA_Real_LeftButton.Ly=IG_LA_Real_LeftButton.y+IG_LA_Real_LeftButton.LA_High;


    IG_LA_Real_LeftButton_Enter.LA_position=IG_LA_Model_LeftButton_Enter;
    IG_LA_Real_LeftButton_Enter.Sx=1;
    IG_LA_Real_LeftButton_Enter.Sy=1;
    IG_LA_Real_LeftButton_Enter.LA_High=(int)((IG_LA_Model_LeftButton_Enter.m_iBottom-IG_LA_Model_LeftButton_Enter.m_iTop)*IG_LA_Real_LeftButton_Enter.Sy);
    IG_LA_Real_LeftButton_Enter.LA_Width=(int)((IG_LA_Model_LeftButton_Enter.m_iRight-IG_LA_Model_LeftButton_Enter.m_iLeft)*IG_LA_Real_LeftButton_Enter.Sx);
    IG_LA_Real_LeftButton_Enter.x=0;
    IG_LA_Real_LeftButton_Enter.y=541;
    IG_LA_Real_LeftButton_Enter.Lx=IG_LA_Real_LeftButton_Enter.x+IG_LA_Real_LeftButton_Enter.LA_Width;
    IG_LA_Real_LeftButton_Enter.Ly=IG_LA_Real_LeftButton_Enter.y+IG_LA_Real_LeftButton_Enter.LA_High;


    IG_LA_Real_RightButton.LA_position=IG_LA_Model_RightButton;
    IG_LA_Real_RightButton.Sx=1;
    IG_LA_Real_RightButton.Sy=1;
    IG_LA_Real_RightButton.LA_High=(int)((IG_LA_Model_RightButton.m_iBottom-IG_LA_Model_RightButton.m_iTop)*IG_LA_Real_RightButton.Sy);
    IG_LA_Real_RightButton.LA_Width=(int)((IG_LA_Model_RightButton.m_iRight-IG_LA_Model_RightButton.m_iLeft)*IG_LA_Real_RightButton.Sx);
    IG_LA_Real_RightButton.x=380;
    IG_LA_Real_RightButton.y=541;
    IG_LA_Real_RightButton.Lx=IG_LA_Real_RightButton.x+IG_LA_Real_RightButton.LA_Width;
    IG_LA_Real_RightButton.Ly=IG_LA_Real_RightButton.y+IG_LA_Real_RightButton.LA_High;


    IG_LA_Real_RightButton_Enter.LA_position=IG_LA_Model_RightButton_Enter;
    IG_LA_Real_RightButton_Enter.Sx=1;
    IG_LA_Real_RightButton_Enter.Sy=1;
    IG_LA_Real_RightButton_Enter.LA_High=(int)((IG_LA_Model_RightButton_Enter.m_iBottom-IG_LA_Model_RightButton_Enter.m_iTop)*IG_LA_Real_RightButton_Enter.Sy);
    IG_LA_Real_RightButton_Enter.LA_Width=(int)((IG_LA_Model_RightButton_Enter.m_iRight-IG_LA_Model_RightButton_Enter.m_iLeft)*IG_LA_Real_RightButton_Enter.Sx);
    IG_LA_Real_RightButton_Enter.x=380;
    IG_LA_Real_RightButton_Enter.y=541;
    IG_LA_Real_RightButton_Enter.Lx=IG_LA_Real_RightButton_Enter.x+IG_LA_Real_RightButton_Enter.LA_Width;
    IG_LA_Real_RightButton_Enter.Ly=IG_LA_Real_RightButton_Enter.y+IG_LA_Real_RightButton_Enter.LA_High;


    IG_LA_Real_Company_Logo.LA_position=IG_LA_Model_Company_Logo;
    IG_LA_Real_Company_Logo.Sx=1;
    IG_LA_Real_Company_Logo.Sy=1;
    IG_LA_Real_Company_Logo.LA_High=(int)((IG_LA_Model_Company_Logo.m_iBottom-IG_LA_Model_Company_Logo.m_iTop)*IG_LA_Real_Company_Logo.Sy);
    IG_LA_Real_Company_Logo.LA_Width=(int)((IG_LA_Model_Company_Logo.m_iRight-IG_LA_Model_Company_Logo.m_iLeft)*IG_LA_Real_Company_Logo.Sx);
    IG_LA_Real_Company_Logo.x=27;
    IG_LA_Real_Company_Logo.y=72;
    IG_LA_Real_Company_Logo.Lx=IG_LA_Real_Company_Logo.x+IG_LA_Real_Company_Logo.LA_Width;
    IG_LA_Real_Company_Logo.Ly=IG_LA_Real_Company_Logo.y+IG_LA_Real_Company_Logo.LA_High;


    IG_LA_Real_JE_Logo.LA_position=IG_LA_Model_JE_Logo;
    IG_LA_Real_JE_Logo.Sx=1;
    IG_LA_Real_JE_Logo.Sy=1;
    IG_LA_Real_JE_Logo.LA_High=(int)((IG_LA_Model_JE_Logo.m_iBottom-IG_LA_Model_JE_Logo.m_iTop)*IG_LA_Real_JE_Logo.Sy);
    IG_LA_Real_JE_Logo.LA_Width=(int)((IG_LA_Model_JE_Logo.m_iRight-IG_LA_Model_JE_Logo.m_iLeft)*IG_LA_Real_JE_Logo.Sx);
    IG_LA_Real_JE_Logo.x=112;
    IG_LA_Real_JE_Logo.y=271;
    IG_LA_Real_JE_Logo.Lx=IG_LA_Real_JE_Logo.x+IG_LA_Real_JE_Logo.LA_Width;
    IG_LA_Real_JE_Logo.Ly=IG_LA_Real_JE_Logo.y+IG_LA_Real_JE_Logo.LA_High;


    IG_LA_Real_CW_Logo.LA_position=IG_LA_Model_CW_Logo;
    IG_LA_Real_CW_Logo.Sx=1;
    IG_LA_Real_CW_Logo.Sy=1;
    IG_LA_Real_CW_Logo.LA_High=(int)((IG_LA_Model_CW_Logo.m_iBottom-IG_LA_Model_CW_Logo.m_iTop)*IG_LA_Real_CW_Logo.Sy);
    IG_LA_Real_CW_Logo.LA_Width=(int)((IG_LA_Model_CW_Logo.m_iRight-IG_LA_Model_CW_Logo.m_iLeft)*IG_LA_Real_CW_Logo.Sx);
    IG_LA_Real_CW_Logo.x=112;
    IG_LA_Real_CW_Logo.y=271;
    IG_LA_Real_CW_Logo.Lx=IG_LA_Real_CW_Logo.x+IG_LA_Real_CW_Logo.LA_Width;
    IG_LA_Real_CW_Logo.Ly=IG_LA_Real_CW_Logo.y+IG_LA_Real_CW_Logo.LA_High;


    IG_LA_Real_DA_Logo.LA_position=IG_LA_Model_DA_Logo;
    IG_LA_Real_DA_Logo.Sx=1;
    IG_LA_Real_DA_Logo.Sy=1;
    IG_LA_Real_DA_Logo.LA_High=(int)((IG_LA_Model_DA_Logo.m_iBottom-IG_LA_Model_DA_Logo.m_iTop)*IG_LA_Real_DA_Logo.Sy);
    IG_LA_Real_DA_Logo.LA_Width=(int)((IG_LA_Model_DA_Logo.m_iRight-IG_LA_Model_DA_Logo.m_iLeft)*IG_LA_Real_DA_Logo.Sx);
    IG_LA_Real_DA_Logo.x=112;
    IG_LA_Real_DA_Logo.y=271;
    IG_LA_Real_DA_Logo.Lx=IG_LA_Real_DA_Logo.x+IG_LA_Real_DA_Logo.LA_Width;
    IG_LA_Real_DA_Logo.Ly=IG_LA_Real_DA_Logo.y+IG_LA_Real_DA_Logo.LA_High;


    IG_LA_Real_TK_Logo.LA_position=IG_LA_Model_TK_Logo;
    IG_LA_Real_TK_Logo.Sx=1;
    IG_LA_Real_TK_Logo.Sy=1;
    IG_LA_Real_TK_Logo.LA_High=(int)((IG_LA_Model_TK_Logo.m_iBottom-IG_LA_Model_TK_Logo.m_iTop)*IG_LA_Real_TK_Logo.Sy);
    IG_LA_Real_TK_Logo.LA_Width=(int)((IG_LA_Model_TK_Logo.m_iRight-IG_LA_Model_TK_Logo.m_iLeft)*IG_LA_Real_TK_Logo.Sx);
    IG_LA_Real_TK_Logo.x=112;
    IG_LA_Real_TK_Logo.y=271;
    IG_LA_Real_TK_Logo.Lx=IG_LA_Real_TK_Logo.x+IG_LA_Real_TK_Logo.LA_Width;
    IG_LA_Real_TK_Logo.Ly=IG_LA_Real_TK_Logo.y+IG_LA_Real_TK_Logo.LA_High;


    IG_LA_Real_DA_Word.LA_position=IG_LA_Model_DA_Word_ENG;
    IG_LA_Real_DA_Word.Sx=1;
    IG_LA_Real_DA_Word.Sy=1;
    IG_LA_Real_DA_Word.LA_High=(int)((IG_LA_Model_DA_Word_ENG.m_iBottom-IG_LA_Model_DA_Word_ENG.m_iTop)*IG_LA_Real_DA_Word.Sy);
    IG_LA_Real_DA_Word.LA_Width=(int)((IG_LA_Model_DA_Word_ENG.m_iRight-IG_LA_Model_DA_Word_ENG.m_iLeft)*IG_LA_Real_DA_Word.Sx);
    IG_LA_Real_DA_Word.x=120;
    IG_LA_Real_DA_Word.y=581;
    IG_LA_Real_DA_Word.Lx=IG_LA_Real_DA_Word.x+IG_LA_Real_DA_Word.LA_Width;
    IG_LA_Real_DA_Word.Ly=IG_LA_Real_DA_Word.y+IG_LA_Real_DA_Word.LA_High;


    IG_LA_Real_CW_Word.LA_position=IG_LA_Model_CW_Word_ENG;
    IG_LA_Real_CW_Word.Sx=1;
    IG_LA_Real_CW_Word.Sy=1;
    IG_LA_Real_CW_Word.LA_High=(int)((IG_LA_Model_CW_Word_ENG.m_iBottom-IG_LA_Model_CW_Word_ENG.m_iTop)*IG_LA_Real_CW_Word.Sy);
    IG_LA_Real_CW_Word.LA_Width=(int)((IG_LA_Model_CW_Word_ENG.m_iRight-IG_LA_Model_CW_Word_ENG.m_iLeft)*IG_LA_Real_CW_Word.Sx);
    IG_LA_Real_CW_Word.x=120;
    IG_LA_Real_CW_Word.y=581;
    IG_LA_Real_CW_Word.Lx=IG_LA_Real_CW_Word.x+IG_LA_Real_CW_Word.LA_Width;
    IG_LA_Real_CW_Word.Ly=IG_LA_Real_CW_Word.y+IG_LA_Real_CW_Word.LA_High;


    IG_LA_Real_JE_Word.LA_position=IG_LA_Model_JE_Word_ENG;
    IG_LA_Real_JE_Word.Sx=1;
    IG_LA_Real_JE_Word.Sy=1;
    IG_LA_Real_JE_Word.LA_High=(int)((IG_LA_Model_JE_Word_ENG.m_iBottom-IG_LA_Model_JE_Word_ENG.m_iTop)*IG_LA_Real_JE_Word.Sy);
    IG_LA_Real_JE_Word.LA_Width=(int)((IG_LA_Model_JE_Word_ENG.m_iRight-IG_LA_Model_JE_Word_ENG.m_iLeft)*IG_LA_Real_JE_Word.Sx);
    IG_LA_Real_JE_Word.x=120;
    IG_LA_Real_JE_Word.y=581;
    IG_LA_Real_JE_Word.Lx=IG_LA_Real_JE_Word.x+IG_LA_Real_JE_Word.LA_Width;
    IG_LA_Real_JE_Word.Ly=IG_LA_Real_JE_Word.y+IG_LA_Real_JE_Word.LA_High;


    IG_LA_Real_TK_Word.LA_position=IG_LA_Model_TK_Word_ENG;
    IG_LA_Real_TK_Word.Sx=1;
    IG_LA_Real_TK_Word.Sy=1;
    IG_LA_Real_TK_Word.LA_High=(int)((IG_LA_Model_TK_Word_ENG.m_iBottom-IG_LA_Model_TK_Word_ENG.m_iTop)*IG_LA_Real_TK_Word.Sy);
    IG_LA_Real_TK_Word.LA_Width=(int)((IG_LA_Model_TK_Word_ENG.m_iRight-IG_LA_Model_TK_Word_ENG.m_iLeft)*IG_LA_Real_TK_Word.Sx);
    IG_LA_Real_TK_Word.x=120;
    IG_LA_Real_TK_Word.y=581;
    IG_LA_Real_TK_Word.Lx=IG_LA_Real_TK_Word.x+IG_LA_Real_TK_Word.LA_Width;
    IG_LA_Real_TK_Word.Ly=IG_LA_Real_TK_Word.y+IG_LA_Real_TK_Word.LA_High;


    IG_LA_Real_Exit_Word.LA_position=IG_LA_Model_Exit_Word_ENG;
    IG_LA_Real_Exit_Word.Sx=1;
    IG_LA_Real_Exit_Word.Sy=1;
    IG_LA_Real_Exit_Word.LA_High=(int)((IG_LA_Model_Exit_Word_ENG.m_iBottom-IG_LA_Model_Exit_Word_ENG.m_iTop)*IG_LA_Real_Exit_Word.Sy);
    IG_LA_Real_Exit_Word.LA_Width=(int)((IG_LA_Model_Exit_Word_ENG.m_iRight-IG_LA_Model_Exit_Word_ENG.m_iLeft)*IG_LA_Real_Exit_Word.Sx);
    IG_LA_Real_Exit_Word.x=125;
    IG_LA_Real_Exit_Word.y=710;
    IG_LA_Real_Exit_Word.Lx=IG_LA_Real_Exit_Word.x+IG_LA_Real_Exit_Word.LA_Width;
    IG_LA_Real_Exit_Word.Ly=IG_LA_Real_Exit_Word.y+IG_LA_Real_Exit_Word.LA_High;

    IG_LA_Real_Warning_Word.LA_position=IG_LA_Model_Warning_Word_ENG;
    IG_LA_Real_Warning_Word.Sx=1;
    IG_LA_Real_Warning_Word.Sy=1;
    IG_LA_Real_Warning_Word.LA_High=(int)((IG_LA_Model_Warning_Word_CHS.m_iBottom-IG_LA_Model_Warning_Word_CHS.m_iTop)*IG_LA_Real_Exit_Word.Sy);
    IG_LA_Real_Warning_Word.LA_Width=(int)((IG_LA_Model_Warning_Word_CHS.m_iRight-IG_LA_Model_Warning_Word_CHS.m_iLeft)*IG_LA_Real_Exit_Word.Sx);
    IG_LA_Real_Warning_Word.x=120;
    IG_LA_Real_Warning_Word.y=365;
    IG_LA_Real_Warning_Word.Lx=IG_LA_Real_Warning_Word.x+IG_LA_Real_Warning_Word.LA_Width;
    IG_LA_Real_Warning_Word.Ly=IG_LA_Real_Warning_Word.y+IG_LA_Real_Warning_Word.LA_High;

#endif
}

void IG_LA_PointerPressed(int x,int y)
{

    if(x > IG_LA_Real_LeftButton.x && x < IG_LA_Real_LeftButton.Lx && y > IG_LA_Real_LeftButton.y && y < IG_LA_Real_LeftButton.Ly)//×ó
    {
        IG_LA_Disp_LeftButton=IG_LA_Real_LeftButton_Enter;
    }
    else if( x > IG_LA_Real_RightButton.x && x< IG_LA_Real_RightButton.Lx && y > IG_LA_Real_RightButton.y&& y < IG_LA_Real_RightButton.Ly)//ÓÒ
    {
        IG_LA_Disp_RightButton=IG_LA_Real_RightButton_Enter;
    }
    else if( x > IG_LA_Real_ExitButton.x && x< IG_LA_Real_ExitButton.Lx && y > IG_LA_Real_ExitButton.y&& y < IG_LA_Real_ExitButton.Ly)//EXIT
    {
        IG_LA_Disp_ExitButton=IG_LA_Real_ExitButton_Enter;
    }
    else if( x > IG_LA_Real_Button1.x && x< IG_LA_Real_Button1.Lx && y > IG_LA_Real_Button1.y&& y < IG_LA_Real_Button1.Ly)//button1
    {
        IG_LA_Disp_Button1=IG_LA_Real_Button1_Enter;
    }

}
void IG_LA_DA5_Left_Operation()
{
#if _IG_TK_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_TK_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_TK_Logo.x+5000*IG_LA_Logo_MoveTime[1];
    IG_LA_LA_UI_Stats=IG_LA_H_TK;
    IG_LA_Disp_Game_Word=IG_LA_Real_TK_Word;
#elif _IG_JE_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_JE_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_JE_Logo.x+5000*IG_LA_Logo_MoveTime[1];
    IG_LA_LA_UI_Stats=IG_LA_H_JE;
    IG_LA_Disp_Game_Word=IG_LA_Real_JE_Word;
#elif _IG_CW_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_CW_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_CW_Logo.x+5000*IG_LA_Logo_MoveTime[1];
    IG_LA_LA_UI_Stats=IG_LA_H_CW;
    IG_LA_Disp_Game_Word=IG_LA_Real_CW_Word;
#endif

}
void IG_LA_TK_Left_Operation()
{
#if _IG_JE_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_JE_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_JE_Logo.x+5000*IG_LA_Logo_MoveTime[1];
    IG_LA_LA_UI_Stats=IG_LA_H_JE;
    IG_LA_Disp_Game_Word=IG_LA_Real_JE_Word;
#elif _IG_CW_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_CW_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_CW_Logo.x+5000*IG_LA_Logo_MoveTime[1];
    IG_LA_LA_UI_Stats=IG_LA_H_CW;
    IG_LA_Disp_Game_Word=IG_LA_Real_CW_Word;
#elif _IG_DA5_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_DA_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_DA_Logo.x+5000*IG_LA_Logo_MoveTime[1];
    IG_LA_LA_UI_Stats=IG_LA_H_DA5;
    IG_LA_Disp_Game_Word=IG_LA_Real_DA_Word;

#endif

}
void IG_LA_JE_Left_Operation()
{
#if _IG_CW_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_CW_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_CW_Logo.x+5000*IG_LA_Logo_MoveTime[1];
    IG_LA_LA_UI_Stats=IG_LA_H_CW;
    IG_LA_Disp_Game_Word=IG_LA_Real_CW_Word;
#elif _IG_DA5_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_DA_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_DA_Logo.x+5000*IG_LA_Logo_MoveTime[1];
    IG_LA_LA_UI_Stats=IG_LA_H_DA5;
    IG_LA_Disp_Game_Word=IG_LA_Real_DA_Word;
#elif _IG_TK_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_TK_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_TK_Logo.x+5000*IG_LA_Logo_MoveTime[1];
    IG_LA_LA_UI_Stats=IG_LA_H_TK;
    IG_LA_Disp_Game_Word=IG_LA_Real_TK_Word;
#endif

}
void IG_LA_CW_Left_Operation()
{
#if _IG_DA5_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_DA_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_DA_Logo.x+5000*IG_LA_Logo_MoveTime[1];
    IG_LA_LA_UI_Stats=IG_LA_H_DA5;
    IG_LA_Disp_Game_Word=IG_LA_Real_DA_Word;
#elif _IG_TK_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_TK_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_TK_Logo.x+5000*IG_LA_Logo_MoveTime[1];
    IG_LA_LA_UI_Stats=IG_LA_H_TK;
    IG_LA_Disp_Game_Word=IG_LA_Real_TK_Word;
#elif _IG_JE_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_JE_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_JE_Logo.x+5000*IG_LA_Logo_MoveTime[1];
    IG_LA_LA_UI_Stats=IG_LA_H_JE;
    IG_LA_Disp_Game_Word=IG_LA_Real_JE_Word;
#endif

}

void IG_LA_CW_Right_Operation()
{

#if _IG_JE_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_JE_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_JE_Logo.x-5000*IG_LA_Logo_MoveTime[0];
    IG_LA_LA_UI_Stats=IG_LA_H_JE;
    IG_LA_Disp_Game_Word=IG_LA_Real_JE_Word;
#elif _IG_TK_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_TK_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_TK_Logo.x-5000*IG_LA_Logo_MoveTime[0];
    IG_LA_LA_UI_Stats=IG_LA_H_TK;
    IG_LA_Disp_Game_Word=IG_LA_Real_TK_Word;
#elif _IG_DA5_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_DA_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_DA_Logo.x-5000*IG_LA_Logo_MoveTime[0];
    IG_LA_LA_UI_Stats=IG_LA_H_DA5;
    IG_LA_Disp_Game_Word=IG_LA_Real_DA_Word;
#endif

}
void IG_LA_JE_Right_Operation()
{
#if _IG_TK_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_TK_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_TK_Logo.x-5000*IG_LA_Logo_MoveTime[0];
    IG_LA_LA_UI_Stats=IG_LA_H_TK;
    IG_LA_Disp_Game_Word=IG_LA_Real_TK_Word;
#elif _IG_DA5_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_DA_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_DA_Logo.x-5000*IG_LA_Logo_MoveTime[0];
    IG_LA_LA_UI_Stats=IG_LA_H_DA5;
    IG_LA_Disp_Game_Word=IG_LA_Real_DA_Word;
#elif _IG_CW_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_CW_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_CW_Logo.x-5000*IG_LA_Logo_MoveTime[0];
    IG_LA_LA_UI_Stats=IG_LA_H_CW;
    IG_LA_Disp_Game_Word=IG_LA_Real_CW_Word;
#endif

}
void IG_LA_TK_Right_Operation()
{
#if _IG_DA5_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_DA_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_DA_Logo.x-5000*IG_LA_Logo_MoveTime[0];
    IG_LA_LA_UI_Stats=IG_LA_H_DA5;
    IG_LA_Disp_Game_Word=IG_LA_Real_DA_Word;
#elif _IG_CW_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_CW_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_CW_Logo.x-5000*IG_LA_Logo_MoveTime[0];
    IG_LA_LA_UI_Stats=IG_LA_H_CW;
    IG_LA_Disp_Game_Word=IG_LA_Real_CW_Word;
#elif _IG_JE_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_JE_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_JE_Logo.x-5000*IG_LA_Logo_MoveTime[0];
    IG_LA_LA_UI_Stats=IG_LA_H_JE;
    IG_LA_Disp_Game_Word=IG_LA_Real_JE_Word;

#endif

}
void IG_LA_DA5_Right_Operation()
{

#if _IG_CW_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_CW_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_CW_Logo.x-5000*IG_LA_Logo_MoveTime[0];
    IG_LA_LA_UI_Stats=IG_LA_H_CW;
    IG_LA_Disp_Game_Word=IG_LA_Real_CW_Word;
#elif _IG_JE_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_JE_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_JE_Logo.x-5000*IG_LA_Logo_MoveTime[0];
    IG_LA_LA_UI_Stats=IG_LA_H_JE;
    IG_LA_Disp_Game_Word=IG_LA_Real_JE_Word;
#elif _IG_TK_
    IG_LA_Disp_Game_Logo_M=IG_LA_Real_TK_Logo;
    IG_LA_Disp_Game_Logo_M.x=IG_LA_Real_TK_Logo.x-5000*IG_LA_Logo_MoveTime[0];
    IG_LA_LA_UI_Stats=IG_LA_H_TK;
    IG_LA_Disp_Game_Word=IG_LA_Real_TK_Word;
#endif

}
void IG_LA_LA_Suspend()
{
    IG_LA_Disp_LeftButton=IG_LA_Real_LeftButton;
    IG_LA_Disp_RightButton=IG_LA_Real_RightButton;
    IG_LA_Disp_Button1=IG_LA_Real_Button1;
    IG_LA_Disp_ExitButton=IG_LA_Real_ExitButton;
}
void IG_LA_PointerReleased(IGV5RC *pThisRC,int x,int y)
{
//#ifdef IGV5_MTK_PHONE
    //unsigned char writenbuf[10];
//#endif
    if(x>IG_LA_Real_LeftButton.x && x<IG_LA_Real_LeftButton.Lx&&y>IG_LA_Real_LeftButton.y&&y<IG_LA_Real_LeftButton.Ly)//×ó
    {
        IG_LA_Disp_LeftButton=IG_LA_Real_LeftButton;
        IG_DA_Right_Flag=0;
        IG_DA_Left_Flag=1;
        IG_LA_Disp_Game_Logo=IG_LA_Disp_Game_Logo_M;
        IG_LA_Logo_MoveTime[1]=0.2f;
        if(IG_LA_LA_UI_Stats==IG_LA_H_DA5)
        {

            IG_LA_DA5_Left_Operation();
        }else if(IG_LA_LA_UI_Stats==IG_LA_H_TK)
        {
            IG_LA_TK_Left_Operation();
        }else if(IG_LA_LA_UI_Stats==IG_LA_H_JE)
        {
            IG_LA_JE_Left_Operation();
        }else if(IG_LA_LA_UI_Stats==IG_LA_H_CW)
        {
            IG_LA_CW_Left_Operation();
        }
    }
    else if( x > IG_LA_Real_RightButton.x && x< IG_LA_Real_RightButton.Lx && y > IG_LA_Real_RightButton.y&& y < IG_LA_Real_RightButton.Ly)//ÓÒ
    {
        IG_LA_Disp_RightButton=IG_LA_Real_RightButton;
        IG_DA_Right_Flag=1;
        IG_DA_Left_Flag=0;
        IG_LA_Disp_Game_Logo=IG_LA_Disp_Game_Logo_M;
        IG_LA_Logo_MoveTime[0]=0.2f;
        if(IG_LA_LA_UI_Stats==IG_LA_H_DA5)
        {
            IG_LA_DA5_Right_Operation();
        }else if(IG_LA_LA_UI_Stats==IG_LA_H_CW)
        {            
            IG_LA_CW_Right_Operation();
        }else if(IG_LA_LA_UI_Stats==IG_LA_H_JE)
        {
            IG_LA_JE_Right_Operation();
        }else if(IG_LA_LA_UI_Stats==IG_LA_H_TK)
        {
            IG_LA_TK_Right_Operation();
        }
    }
    else if( x > IG_LA_Real_ExitButton.x && x< IG_LA_Real_ExitButton.Lx && y > IG_LA_Real_ExitButton.y&& y < IG_LA_Real_ExitButton.Ly)//EXIT
    {
        IG_LA_UnloadFlag=1;
        IG_LA_Disp_ExitButton=IG_LA_Real_ExitButton;
        IG_LA_Launcher_Unload();
#ifdef IGV5_MTK_PHONE
        IGSystem_Exit();
#endif
    }
    else if( x > IG_LA_Real_Button1.x && x< IG_LA_Real_Button1.Lx && y > IG_LA_Real_Button1.y&& y < IG_LA_Real_Button1.Ly)//button1
    {
        IG_LA_Disp_Button1=IG_LA_Real_Button1;
        if(IG_LA_LA_UI_Stats==IG_LA_H_DA5)
        {

            IG_LA_LA_Stats=IG_LA_H_DA5;
        }else if(IG_LA_LA_UI_Stats==IG_LA_H_CW)
        {        

            IG_LA_LA_Stats=IG_LA_H_CW;
        }else if(IG_LA_LA_UI_Stats==IG_LA_H_JE)
        {
            IG_LA_LA_Stats=IG_LA_H_JE;
        }else if(IG_LA_LA_UI_Stats==IG_LA_H_TK)
        {

            IG_LA_LA_Stats=IG_LA_H_TK;

        }
    }
}
void IG_LA_Touch(int x,int y)
{
    if((x>IG_LA_Real_LeftButton.x && x<IG_LA_Real_LeftButton.Lx&&y>IG_LA_Real_LeftButton.y&&y<IG_LA_Real_LeftButton.Ly))//×ó
    {
            IG_LA_Disp_LeftButton=IG_LA_Real_LeftButton_Enter;
    }else
    {
            IG_LA_Disp_LeftButton=IG_LA_Real_LeftButton;
    }
    if(( x > IG_LA_Real_RightButton.x && x< IG_LA_Real_RightButton.Lx && y > IG_LA_Real_RightButton.y&& y < IG_LA_Real_RightButton.Ly))//ÓÒ
    {
            IG_LA_Disp_RightButton=IG_LA_Real_RightButton_Enter;
    }else
    {
            IG_LA_Disp_RightButton=IG_LA_Real_RightButton;
    }
    if(( x > IG_LA_Real_ExitButton.x && x< IG_LA_Real_ExitButton.Lx && y > IG_LA_Real_ExitButton.y&& y < IG_LA_Real_ExitButton.Ly))//EXIT
    {
        IG_LA_Disp_ExitButton=IG_LA_Real_ExitButton_Enter;
    }else
    {
        IG_LA_Disp_ExitButton=IG_LA_Real_ExitButton;
    }
    if(( x > IG_LA_Real_Button1.x && x< IG_LA_Real_Button1.Lx && y > IG_LA_Real_Button1.y&& y < IG_LA_Real_Button1.Ly))//button1
    {
        IG_LA_Disp_Button1=IG_LA_Real_Button1_Enter;
    }else
    {        
        IG_LA_Disp_Button1=IG_LA_Real_Button1;
    }

}

void IG_LA_Launcher_OnTouchKey(IGV5RC *pThisRC,float fFrameTime,unsigned uNumEvents, IGV5Event *pEventsArray)
{
    unsigned int i;
#ifdef IGV5_MTK_PHONE

unsigned char writenbuf[10];
#endif


    for(i=0;i<uNumEvents;i++) 
    {
        if (pEventsArray[i].m_uType == IGV5ET_INPUT)
        {

            if (pEventsArray[i].m_uEvtID == IGV5EID_KEYDOWN && pEventsArray[i].m_uData1 == IGV5KEY_LEFT) 
            {
                IG_LA_Disp_LeftButton=IG_LA_Real_LeftButton_Enter;
            }
			if (pEventsArray[i].m_uEvtID == IGV5EID_KEYDOWN && pEventsArray[i].m_uData1 == IGV5KEY_4) 
			{
				IG_LA_Disp_LeftButton=IG_LA_Real_LeftButton_Enter;
			}
            if (pEventsArray[i].m_uEvtID == IGV5EID_KEYDOWN && pEventsArray[i].m_uData1 == IGV5KEY_RIGHT) 
            {
                IG_LA_Disp_RightButton=IG_LA_Real_RightButton_Enter;
            }
			if (pEventsArray[i].m_uEvtID == IGV5EID_KEYDOWN && pEventsArray[i].m_uData1 == IGV5KEY_6) 
			{
				IG_LA_Disp_RightButton=IG_LA_Real_RightButton_Enter;
			}
            if (pEventsArray[i].m_uEvtID == IGV5EID_KEYDOWN && pEventsArray[i].m_uData1 == IGV5KEY_RSK) 
            {    
                IG_LA_Disp_ExitButton=IG_LA_Real_ExitButton_Enter;
            }
            if (pEventsArray[i].m_uEvtID == IGV5EID_KEYDOWN && pEventsArray[i].m_uData1 == IGV5KEY_CSK) 
            {    
                IG_LA_Disp_Button1=IG_LA_Real_Button1_Enter;
            }
			if (pEventsArray[i].m_uEvtID == IGV5EID_KEYDOWN && pEventsArray[i].m_uData1 == IGV5KEY_5) 
			{    
				IG_LA_Disp_Button1=IG_LA_Real_Button1_Enter;
			}
            if (pEventsArray[i].m_uEvtID == IGV5EID_KEYUP && pEventsArray[i].m_uData1 == IGV5KEY_LEFT) 
            {
                IG_LA_Disp_LeftButton=IG_LA_Real_LeftButton;
                IG_DA_Right_Flag=0;
                IG_DA_Left_Flag=1;
                IG_LA_Disp_Game_Logo=IG_LA_Disp_Game_Logo_M;
                IG_LA_Logo_MoveTime[1]=0.2f;
                if(IG_LA_LA_UI_Stats==IG_LA_H_DA5)
                {
                    IG_LA_DA5_Left_Operation();
                }else if(IG_LA_LA_UI_Stats==IG_LA_H_TK)
                {
                    IG_LA_TK_Left_Operation();
                }else if(IG_LA_LA_UI_Stats==IG_LA_H_JE)
                {
                    IG_LA_JE_Left_Operation();
                }else if(IG_LA_LA_UI_Stats==IG_LA_H_CW)
                {
                    IG_LA_CW_Left_Operation();
                }
            }
			if (pEventsArray[i].m_uEvtID == IGV5EID_KEYUP && pEventsArray[i].m_uData1 == IGV5KEY_4) 
			{
				IG_LA_Disp_LeftButton=IG_LA_Real_LeftButton;
				IG_DA_Right_Flag=0;
				IG_DA_Left_Flag=1;
				IG_LA_Disp_Game_Logo=IG_LA_Disp_Game_Logo_M;
				IG_LA_Logo_MoveTime[1]=0.2f;
				if(IG_LA_LA_UI_Stats==IG_LA_H_DA5)
				{
					IG_LA_DA5_Left_Operation();
				}else if(IG_LA_LA_UI_Stats==IG_LA_H_TK)
				{
					IG_LA_TK_Left_Operation();
				}else if(IG_LA_LA_UI_Stats==IG_LA_H_JE)
				{
					IG_LA_JE_Left_Operation();
				}else if(IG_LA_LA_UI_Stats==IG_LA_H_CW)
				{
					IG_LA_CW_Left_Operation();
				}
			}

            if (pEventsArray[i].m_uEvtID == IGV5EID_KEYUP && pEventsArray[i].m_uData1 == IGV5KEY_RIGHT) 
            {
                IG_LA_Disp_RightButton=IG_LA_Real_RightButton;
                IG_DA_Right_Flag=1;
                IG_DA_Left_Flag=0;
                IG_LA_Disp_Game_Logo=IG_LA_Disp_Game_Logo_M;
                IG_LA_Logo_MoveTime[0]=0.2f;
                if(IG_LA_LA_UI_Stats==IG_LA_H_DA5)
                {
                        IG_LA_DA5_Right_Operation();
                }else if(IG_LA_LA_UI_Stats==IG_LA_H_CW)
                {            
                        IG_LA_CW_Right_Operation();
                }else if(IG_LA_LA_UI_Stats==IG_LA_H_JE)
                {
                        IG_LA_JE_Right_Operation();

                }else if(IG_LA_LA_UI_Stats==IG_LA_H_TK)
                {
                        IG_LA_TK_Right_Operation();
                }
            }
			if (pEventsArray[i].m_uEvtID == IGV5EID_KEYUP && pEventsArray[i].m_uData1 == IGV5KEY_6) 
			{
				IG_LA_Disp_RightButton=IG_LA_Real_RightButton;
				IG_DA_Right_Flag=1;
				IG_DA_Left_Flag=0;
				IG_LA_Disp_Game_Logo=IG_LA_Disp_Game_Logo_M;
				IG_LA_Logo_MoveTime[0]=0.2f;
				if(IG_LA_LA_UI_Stats==IG_LA_H_DA5)
				{
					IG_LA_DA5_Right_Operation();
				}else if(IG_LA_LA_UI_Stats==IG_LA_H_CW)
				{            
					IG_LA_CW_Right_Operation();
				}else if(IG_LA_LA_UI_Stats==IG_LA_H_JE)
				{
					IG_LA_JE_Right_Operation();

				}else if(IG_LA_LA_UI_Stats==IG_LA_H_TK)
				{
					IG_LA_TK_Right_Operation();
				}
			}
            if (pEventsArray[i].m_uEvtID == IGV5EID_KEYUP && pEventsArray[i].m_uData1 == IGV5KEY_RSK) 
            {    
                IG_LA_Disp_ExitButton=IG_LA_Real_ExitButton;
                IG_LA_Launcher_Unload();
                IG_LA_UnloadFlag=1;
#ifdef IGV5_MTK_PHONE
                IGSystem_Exit();
#endif
            }
			if (pEventsArray[i].m_uEvtID == IGV5EID_KEYUP && pEventsArray[i].m_uData1 == IGV5KEY_5) 
			{    
				//IG_LA_Disp_ExitButton=IG_LA_Real_ExitButton_Enter;
				IG_LA_Disp_Button1=IG_LA_Real_Button1;
				if(IG_LA_LA_UI_Stats==IG_LA_H_DA5)
				{
					IG_LA_Launcher_Unload();
#ifdef IGV5_MTK_PHONE

					IG_LA_LA_WriteInt(writenbuf,2,0);
					IG_LA_LA_WriteOrCreatFileAndWrite((IGCHAR *) L"Z:\\@ig_save\\launcher.ini",writenbuf,2);
#endif
#if _IG_DA5_
#if !_LA_DEBUG_
					IG_LA_DA5_Init(pThisRC);
#endif
#endif
					IG_LA_Status=IG_LA_H_DA5;
				}else if(IG_LA_LA_UI_Stats==IG_LA_H_CW)
			   {        
				IG_LA_Launcher_Unload();
#ifdef IGV5_MTK_PHONE

				IG_LA_LA_WriteInt(writenbuf,4,0);
				IG_LA_LA_WriteOrCreatFileAndWrite((IGCHAR *) L"Z:\\@ig_save\\launcher.ini",writenbuf,2);
#endif    
#if _IG_CW_
#if !_LA_DEBUG_
				IG_LA_CW_Init(pThisRC);
#endif
#endif
				IG_LA_Status=IG_LA_H_CW;
			}else if(IG_LA_LA_UI_Stats==IG_LA_H_JE)
			{
				IG_LA_Launcher_Unload();
#ifdef IGV5_MTK_PHONE

				IG_LA_LA_WriteInt(writenbuf,3,0);
				IG_LA_LA_WriteOrCreatFileAndWrite((IGCHAR *) L"Z:\\@ig_save\\launcher.ini",writenbuf,2);
#endif    
#if _IG_JE_
#if !_LA_DEBUG_
				IG_LA_JE_Init(pThisRC);
#endif
#endif
				IG_LA_Status=IG_LA_H_JE;
			}else if(IG_LA_LA_UI_Stats==IG_LA_H_TK)
			{
				IG_LA_Launcher_Unload();
#ifdef IGV5_MTK_PHONE
				IG_LA_LA_WriteInt(writenbuf,1,0);
				IG_LA_LA_WriteOrCreatFileAndWrite((IGCHAR *) L"Z:\\@ig_save\\launcher.ini",writenbuf,2);
#endif    
#if _IG_TK_
#if !_LA_DEBUG_
				IG_LA_Tank_Init(pThisRC);
#endif
#endif
				IG_LA_Status=IG_LA_H_TK;
			}

			}else if (pEventsArray[i].m_uEvtID == IGV5EID_KEYUP && pEventsArray[i].m_uData1 == IGV5KEY_CSK) 
            {    
                //IG_LA_Disp_ExitButton=IG_LA_Real_ExitButton_Enter;
                IG_LA_Disp_Button1=IG_LA_Real_Button1;
                if(IG_LA_LA_UI_Stats==IG_LA_H_DA5)
                {
                    IG_LA_Launcher_Unload();
#ifdef IGV5_MTK_PHONE

                    IG_LA_LA_WriteInt(writenbuf,2,0);
                    IG_LA_LA_WriteOrCreatFileAndWrite((IGCHAR *) L"Z:\\@ig_save\\launcher.ini",writenbuf,2);
#endif
#if _IG_DA5_
#if !_LA_DEBUG_
                    IG_LA_DA5_Init(pThisRC);
#endif
#endif
                    IG_LA_Status=IG_LA_H_DA5;
                }else if(IG_LA_LA_UI_Stats==IG_LA_H_CW)
                {        
                    IG_LA_Launcher_Unload();
#ifdef IGV5_MTK_PHONE

                    IG_LA_LA_WriteInt(writenbuf,4,0);
                    IG_LA_LA_WriteOrCreatFileAndWrite((IGCHAR *) L"Z:\\@ig_save\\launcher.ini",writenbuf,2);
#endif    
#if _IG_CW_
#if !_LA_DEBUG_
                    IG_LA_CW_Init(pThisRC);
#endif
#endif
                    IG_LA_Status=IG_LA_H_CW;
                }else if(IG_LA_LA_UI_Stats==IG_LA_H_JE)
                {
                    IG_LA_Launcher_Unload();
#ifdef IGV5_MTK_PHONE

                    IG_LA_LA_WriteInt(writenbuf,3,0);
                    IG_LA_LA_WriteOrCreatFileAndWrite((IGCHAR *) L"Z:\\@ig_save\\launcher.ini",writenbuf,2);
#endif    
#if _IG_JE_
#if !_LA_DEBUG_
                    IG_LA_JE_Init(pThisRC);
#endif
#endif
                    IG_LA_Status=IG_LA_H_JE;
                }else if(IG_LA_LA_UI_Stats==IG_LA_H_TK)
                {
                    IG_LA_Launcher_Unload();
#ifdef IGV5_MTK_PHONE
                    IG_LA_LA_WriteInt(writenbuf,1,0);
                    IG_LA_LA_WriteOrCreatFileAndWrite((IGCHAR *) L"Z:\\@ig_save\\launcher.ini",writenbuf,2);
#endif    
#if _IG_TK_
#if !_LA_DEBUG_
                    IG_LA_Tank_Init(pThisRC);
#endif
#endif
                    IG_LA_Status=IG_LA_H_TK;
                }
            }
            if(pEventsArray[i].m_uEvtID ==IGV5EID_BEGINTOUCH)
            {
                IG_LA_PointerPressed(pEventsArray[i].m_uData1,pEventsArray[i].m_uData2);
            }
            if(pEventsArray[i].m_uEvtID==IGV5EID_ENDTOUCH)
            {
                IG_LA_PointerReleased(pThisRC,pEventsArray[i].m_uData1,pEventsArray[i].m_uData2);
            }
            if(pEventsArray[i].m_uEvtID==IGV5EID_TOUCH)
            {
                IG_LA_Touch(pEventsArray[i].m_uData1,pEventsArray[i].m_uData2);
            }
        }
    }

}
void IG_LA_Launcher_Init(IGV5RC *pThisRC)
{
    IGV5Texture_CreateDefault();
#if _CHS_
    IGV5Texture_LoadPVRFromMem(&IG_LA_Word, IG_LA_CHS_WordTexure, NULL, IGV5_TRUE, 0, NULL);
    IGV5Texture_LoadPVRFromMem(&IG_LA_Word_A, IG_LA_CHS_WordTexure_A, NULL, IGV5_TRUE, 0, NULL);
#else
    IGV5Texture_LoadPVRFromMem(&IG_LA_Word, IG_LA_ENG_WordTexure, NULL, IGV5_TRUE, 0, NULL);
    IGV5Texture_LoadPVRFromMem(&IG_LA_Word_A, IG_LA_ENG_WordTexure_A, NULL, IGV5_TRUE, 0, NULL);
#endif
    IGV5Texture_LoadPVRFromMem(&IG_LA_Some, IG_LA_SomeTexure, NULL, IGV5_TRUE, 0, NULL);
    IGV5Texture_LoadPVRFromMem(&IG_LA_Some_A, IG_LA_SomeTexure_A, NULL, IGV5_TRUE, 0, NULL);
    IGV5Texture_LoadPVRFromMem(&IG_LA_Background, IG_LA_BackgroundTexure, NULL, IGV5_TRUE, 0, NULL);
    IG_LA_InitTexureData();

#if !(!_IG_TK_ && !_IG_DA5_ && !_IG_CW_ && !_IG_JE_)
    IG_LA_Disp_LeftButton=IG_LA_Real_LeftButton;
    IG_LA_Disp_RightButton=IG_LA_Real_RightButton;
    IG_LA_Disp_Button1=IG_LA_Real_Button1;
#endif

    IG_LA_Disp_ExitButton=IG_LA_Real_ExitButton;
    IG_LA_Logo_MoveTime[0]=0.2f;
    IG_LA_Logo_MoveTime[1]=0.2f;
#if _IG_DA5_
    IG_LA_Disp_Game_Logo=IG_LA_Real_DA_Logo;
    IG_LA_Disp_Game_Logo_M=IG_LA_Disp_Game_Logo;
    IG_LA_Disp_Game_Word=IG_LA_Real_DA_Word;
    IG_LA_LA_UI_Stats=IG_LA_H_DA5;
#elif _IG_CW_
    IG_LA_Disp_Game_Logo=IG_LA_Real_CW_Logo;
    IG_LA_Disp_Game_Logo_M=IG_LA_Disp_Game_Logo;
    IG_LA_Disp_Game_Word=IG_LA_Real_CW_Word;
    IG_LA_LA_UI_Stats=IG_LA_H_CW;
#elif _IG_JE_
    IG_LA_Disp_Game_Logo=IG_LA_Real_JE_Logo;
    IG_LA_Disp_Game_Logo_M=IG_LA_Disp_Game_Logo;
    IG_LA_Disp_Game_Word=IG_LA_Real_JE_Word;
    IG_LA_LA_UI_Stats=IG_LA_H_JE;
#elif _IG_TK_
    IG_LA_Disp_Game_Logo=IG_LA_Real_TK_Logo;
    IG_LA_Disp_Game_Logo_M=IG_LA_Disp_Game_Logo;
    IG_LA_Disp_Game_Word=IG_LA_Real_TK_Word;
    IG_LA_LA_UI_Stats=IG_LA_H_TK;
#endif
//////////////////////////////////////////////////////////////
#ifdef IGV5_MTK_PHONE
	if(g_uIsOnPhoneCall==1)
	{
        IG_LA_Warning_Flag=1;
        IG_LA_Disp_Game_Logo=IG_LA_Real_DA_Logo;
        IG_LA_Disp_Game_Logo_M=IG_LA_Disp_Game_Logo;
        IG_LA_Disp_Game_Word=IG_LA_Real_Warning_Word;
        IG_LA_LA_UI_Stats=99;

	}
#endif
/////////////////////////////////////////////////////////////

    IG_DA_Left_Flag=0;
    IG_DA_Right_Flag=0;

    IGV5Font_Create(pThisRC->m_sEGLInfo.m_uWidth, pThisRC->m_sEGLInfo.m_uHeight);
    IGV5Font_AddString(pThisRC, 1,3720,"Animated Light Beam", 255,0,0,255);
    IGV5Renderer_SetAlphaTestCmpValue(0.0f);

}
void IG_LA_Launcher_Unload()
{
    IGV5Texture_Release(&IG_LA_Word);
    IGV5Texture_Release(&IG_LA_Word_A);
    IGV5Texture_Release(&IG_LA_Some);
    IGV5Texture_Release(&IG_LA_Some_A);
    IGV5Texture_Release(&IG_LA_Background);    
}
void IG_LA_Launcher_Update(IGV5RC *pThisRC, float fFrameTime,unsigned uNumEvents, IGV5Event *pEventsArray)
{
    int m;
	GL_CHECK(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
	IGV5Renderer_SetAlphaBlendMode(IGV5RS_ALPHA_COMPLEMENT);

    if(IG_LA_Warning_Flag==1)
	{
		IG_LA_Warning_Time+=fFrameTime;
		if(IG_LA_Warning_Time>=3)
		{
			IG_LA_Warning_Time=0;
			IG_LA_Launcher_Unload();
			IG_LA_UnloadFlag=1;
			IG_LA_Warning_Flag=0;
#ifdef IGV5_MTK_PHONE
			IGSystem_Exit();
#endif
		}
	}else
	{
        IGV5Texture_Draw(pThisRC,&IG_LA_Background,IG_LA_Real_BackGround.x,IG_LA_Real_BackGround.y,NULL, IG_LA_Real_BackGround.Sx,IG_LA_Real_BackGround.Sy,0xFFFFFFFF);
        IGV5Texture_Draw2(pThisRC,&IG_LA_Some,&IG_LA_Some_A,IG_LA_Real_Company_Logo.x,IG_LA_Real_Company_Logo.y,&IG_LA_Real_Company_Logo.LA_position, IG_LA_Real_Company_Logo.Sx,IG_LA_Real_Company_Logo.Sy,0xFFFFFFFF);
        IGV5Texture_Draw2(pThisRC,&IG_LA_Some,&IG_LA_Some_A,IG_LA_Real_Game_Logo.x,IG_LA_Real_Game_Logo.y,&IG_LA_Real_Game_Logo.LA_position, IG_LA_Real_Game_Logo.Sx,IG_LA_Real_Game_Logo.Sy,0xFFFFFFFF);
        IGV5Texture_Draw2(pThisRC,&IG_LA_Some,&IG_LA_Some_A,IG_LA_Disp_ExitButton.x,IG_LA_Disp_ExitButton.y,&IG_LA_Disp_ExitButton.LA_position, IG_LA_Disp_ExitButton.Sx,IG_LA_Disp_ExitButton.Sy,0xFFFFFFFF);
        IGV5Texture_Draw2(pThisRC,&IG_LA_Word,&IG_LA_Word_A,IG_LA_Real_Exit_Word.x,IG_LA_Real_Exit_Word.y,&IG_LA_Real_Exit_Word.LA_position, IG_LA_Real_Exit_Word.Sx,IG_LA_Real_Exit_Word.Sy,0xFFFFFFFF);
#if !(!_IG_TK_ && !_IG_DA5_ && !_IG_CW_ && !_IG_JE_)
        IGV5Texture_Draw2(pThisRC,&IG_LA_Some,&IG_LA_Some_A,IG_LA_Disp_Button1.x,IG_LA_Disp_Button1.y,&IG_LA_Disp_Button1.LA_position, IG_LA_Disp_Button1.Sx,IG_LA_Disp_Button1.Sy,0xFFFFFFFF);
        IGV5Texture_Draw2(pThisRC,&IG_LA_Some,&IG_LA_Some_A,IG_LA_Disp_LeftButton.x,IG_LA_Disp_LeftButton.y,&IG_LA_Disp_LeftButton.LA_position, IG_LA_Disp_LeftButton.Sx,IG_LA_Disp_LeftButton.Sy,0xFFFFFFFF);
        IGV5Texture_Draw2(pThisRC,&IG_LA_Some,&IG_LA_Some_A,IG_LA_Disp_RightButton.x,IG_LA_Disp_RightButton.y,&IG_LA_Disp_RightButton.LA_position, IG_LA_Disp_RightButton.Sx,IG_LA_Disp_RightButton.Sy,0xFFFFFFFF);

	}

	if(IG_LA_Warning_Flag==1&&IG_LA_English_Flag==1)
	{
		IGV5Texture_Draw2(pThisRC,&IG_LA_Some,&IG_LA_Some_A,IG_LA_Disp_Game_Word.x,IG_LA_Disp_Game_Word.y,&IG_LA_Disp_Game_Word.LA_position, IG_LA_Disp_Game_Word.Sx,IG_LA_Disp_Game_Word.Sy,0xFFFFFFFF);
	}else
	{
		IGV5Texture_Draw2(pThisRC,&IG_LA_Word,&IG_LA_Word_A,IG_LA_Disp_Game_Word.x,IG_LA_Disp_Game_Word.y,&IG_LA_Disp_Game_Word.LA_position, IG_LA_Disp_Game_Word.Sx,IG_LA_Disp_Game_Word.Sy,0xFFFFFFFF);
	}
    if(IG_LA_Warning_Flag!=1)
	{
        if(IG_DA_Right_Flag)
        {
#if ((_IG_TK_+_IG_DA5_+_IG_CW_+_IG_JE_)>=2)
            if(    IG_LA_Logo_MoveTime[0])
            {
                if(IG_LA_Logo_MoveTime[0]<fFrameTime)
                {
                    m=(int)(IG_LA_Logo_MoveTime[0]*5000);
                    IG_LA_Logo_MoveTime[0]=0;
                }else
                {
                    IG_LA_Logo_MoveTime[0]-=fFrameTime;
                    m=(int)(fFrameTime*5000);
                }
                    IG_LA_Disp_Game_Logo.x+=m;
                    IG_LA_Disp_Game_Logo_M.x+=m;
            }
#endif
		
            IGV5Texture_Draw2(pThisRC,&IG_LA_Some,&IG_LA_Some_A,IG_LA_Disp_Game_Logo.x,IG_LA_Disp_Game_Logo.y,&IG_LA_Disp_Game_Logo.LA_position, IG_LA_Disp_Game_Logo.Sx,IG_LA_Disp_Game_Logo.Sy,0xFFFFFFFF);
            IGV5Texture_Draw2(pThisRC,&IG_LA_Some,&IG_LA_Some_A,IG_LA_Disp_Game_Logo_M.x,IG_LA_Disp_Game_Logo_M.y,&IG_LA_Disp_Game_Logo_M.LA_position, IG_LA_Disp_Game_Logo_M.Sx,IG_LA_Disp_Game_Logo_M.Sy,0xFFFFFFFF);
	
        }else if(IG_DA_Left_Flag)
        {
#if ((_IG_TK_+_IG_DA5_+_IG_CW_+_IG_JE_)>=2)
            if(    IG_LA_Logo_MoveTime[1])
            {
                if(IG_LA_Logo_MoveTime[1]<fFrameTime)
                {
                    m=(int)(IG_LA_Logo_MoveTime[1]*5000);
                    IG_LA_Logo_MoveTime[1]=0;
                }else
                {
                    IG_LA_Logo_MoveTime[1]-=fFrameTime;
                    m=(int)(fFrameTime*5000);
                }
                IG_LA_Disp_Game_Logo.x-=m;
                IG_LA_Disp_Game_Logo_M.x-=m;
            }
#endif
            IGV5Texture_Draw2(pThisRC,&IG_LA_Some,&IG_LA_Some_A,IG_LA_Disp_Game_Logo.x,IG_LA_Disp_Game_Logo.y,&IG_LA_Disp_Game_Logo.LA_position, IG_LA_Disp_Game_Logo.Sx,IG_LA_Disp_Game_Logo.Sy,0xFFFFFFFF);
            IGV5Texture_Draw2(pThisRC,&IG_LA_Some,&IG_LA_Some_A,IG_LA_Disp_Game_Logo_M.x,IG_LA_Disp_Game_Logo_M.y,&IG_LA_Disp_Game_Logo_M.LA_position, IG_LA_Disp_Game_Logo_M.Sx,IG_LA_Disp_Game_Logo_M.Sy,0xFFFFFFFF);
        }else{
            IGV5Texture_Draw2(pThisRC,&IG_LA_Some,&IG_LA_Some_A,IG_LA_Disp_Game_Logo.x,IG_LA_Disp_Game_Logo.y,&IG_LA_Disp_Game_Logo.LA_position, IG_LA_Disp_Game_Logo.Sx,IG_LA_Disp_Game_Logo.Sy,0xFFFFFFFF);
        }
	}
#endif
    if(IG_LA_LA_Stats!=IG_LA_H_LAUNCHER)
    {
        IG_LA_LA_NUM++;
        if(IG_LA_LA_NUM>1)
        {
            IG_LA_LA_NUM=0;
            if(IG_LA_LA_Stats==IG_LA_H_TK)
            {
                IG_LA_Status=IG_LA_H_TK;
                IG_LA_Launcher_Unload();
                IG_LA_LA_Stats=IG_LA_H_LAUNCHER;
#if _IG_TK_
#if !_LA_DEBUG_
                IG_LA_Tank_Init(pThisRC);
#endif
#endif
            }else if(IG_LA_LA_Stats==IG_LA_H_DA5)
            {
                IG_LA_Status=IG_LA_H_DA5;
                IG_LA_Launcher_Unload();
                IG_LA_LA_Stats=IG_LA_H_LAUNCHER;
#if _IG_DA5_
#if !_LA_DEBUG_
                IG_LA_DA5_Init(pThisRC);
#endif
#endif
            }else if(IG_LA_LA_Stats==IG_LA_H_JE)
            {
                IG_LA_Status=IG_LA_H_JE;
                IG_LA_Launcher_Unload();
                IG_LA_LA_Stats=IG_LA_H_LAUNCHER;
#if _IG_JE_
#if !_LA_DEBUG_
                IG_LA_JE_Init(pThisRC);
#endif
#endif
            }else if(IG_LA_LA_Stats==IG_LA_H_CW)
            {
                IG_LA_Status=IG_LA_H_CW;
                IG_LA_Launcher_Unload();
                IG_LA_LA_Stats=IG_LA_H_LAUNCHER;
#if _IG_CW_
#if !_LA_DEBUG_
                IG_LA_CW_Init(pThisRC);
#endif
#endif
            }
        }

    }
	 if(IG_LA_Warning_Flag!=1)
	 {
         IG_LA_Launcher_OnTouchKey(pThisRC,fFrameTime,uNumEvents,pEventsArray);
	 }
}