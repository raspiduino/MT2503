extern "C"
{
#include "DateTimeGprot.h"
}

void avk_pluto_font_001(void);
void avk_pluto_font_002(void);
void avk_pluto_font_003(void);
void avk_pluto_font_004(void);
void avk_pluto_font_005(void);
void avk_pluto_font_006(void);
void avk_pluto_font_007(void);
void avk_pluto_font_008(void);
void avk_pluto_font_009(void);
void avk_pluto_font_010(void);
void avk_pluto_font_011(void);
void avk_pluto_font_012(void);
void avk_pluto_font_013(void);
void avk_pluto_font_014(void);
void avk_pluto_font_015(void);
void avk_pluto_font_016(void);
void avk_pluto_font_017(void);
void avk_pluto_font_018(void);
void avk_pluto_font_019(void);
void avk_pluto_font_020(void);
void avk_pluto_font_021(void);
void avk_pluto_font_022(void);
void avk_pluto_font_023(void);
void avk_pluto_font_024(void);

AVK_ADD_ITEM(AVK_PLUTO_FONT_AUTO,L"Auto case",AVK_PLUTO_FONT);
AVK_ADD_ITEM(AVK_PLUTO_FONT_MANU,L"Manual case",AVK_PLUTO_FONT);


AVK_MANUAL_CASE(AVK_PLUTO_FONT_CASE1,AVK_PLUTO_FONT_MANU)
{
    AVK_MANU_SHOW_TIPS(L"If you see values for each variabe then pass",avk_pluto_font_001);
}

AVK_MANUAL_CASE(AVK_PLUTO_FONT_CASE2,AVK_PLUTO_FONT_MANU)
{
    AVK_MANU_SHOW_TIPS(L"If set font = get font then pass",avk_pluto_font_002);
}

AVK_MANUAL_CASE(AVK_PLUTO_FONT_CASE3,AVK_PLUTO_FONT_MANU)
{
    AVK_MANU_SHOW_TIPS(L"If you see values for each variabe then pass",avk_pluto_font_003);
}

AVK_MANUAL_CASE(AVK_PLUTO_FONT_CASE4,AVK_PLUTO_FONT_MANU)
{
    AVK_MANU_SHOW_TIPS(L"If you see values for each variabe then pass",avk_pluto_font_004);
}

AVK_MANUAL_CASE(AVK_PLUTO_FONT_CASE5,AVK_PLUTO_FONT_MANU)
{
    AVK_MANU_SHOW_TIPS(L"If you see values for each variabe then pass",avk_pluto_font_005);
}

AVK_MANUAL_CASE(AVK_PLUTO_FONT_CASE6,AVK_PLUTO_FONT_MANU)
{
    AVK_MANU_SHOW_TIPS(L"If you see values for each variabe then pass",avk_pluto_font_006);
}

AVK_MANUAL_CASE(AVK_PLUTO_FONT_CASE7,AVK_PLUTO_FONT_MANU)
{
    AVK_MANU_SHOW_TIPS(L"If you see values for each variabe then pass",avk_pluto_font_007);
}

AVK_MANUAL_CASE(AVK_PLUTO_FONT_CASE8,AVK_PLUTO_FONT_MANU)
{
    AVK_MANU_SHOW_TIPS(L"If you see values for each variabe then pass",avk_pluto_font_008);
}
AVK_MANUAL_CASE(AVK_PLUTO_FONT_CASE9,AVK_PLUTO_FONT_MANU)
{
    AVK_MANU_SHOW_TIPS(L"Language selected should be On and others Off the PASS",avk_pluto_font_009);
}

AVK_MANUAL_CASE(AVK_PLUTO_FONT_CASE10,AVK_PLUTO_FONT_MANU)
{
    AVK_MANU_SHOW_TIPS(L"Country code of language should be correct, pass",avk_pluto_font_010);
}

AVK_MANUAL_CASE(AVK_PLUTO_FONT_CASE11,AVK_PLUTO_FONT_MANU)
{
    AVK_MANU_SHOW_TIPS(L"If you see values for each variabe then pass",avk_pluto_font_011);
}

AVK_MANUAL_CASE(AVK_PLUTO_FONT_CASE12,AVK_PLUTO_FONT_MANU)
{
    AVK_MANU_SHOW_TIPS(L"If you see values for each variabe then pass",avk_pluto_font_012);
}

AVK_MANUAL_CASE(AVK_PLUTO_FONT_CASE13,AVK_PLUTO_FONT_MANU)
{
    AVK_MANU_SHOW_TIPS(L"Color coding is in RGB, so components of color of test string should be shown correctly then pass.",avk_pluto_font_013);
}

AVK_MANUAL_CASE(AVK_PLUTO_FONT_CASE14,AVK_PLUTO_FONT_MANU)
{
    AVK_MANU_SHOW_TIPS(L"String should be shown in borders.",avk_pluto_font_014);
}

AVK_MANUAL_CASE(AVK_PLUTO_FONT_CASE15,AVK_PLUTO_FONT_MANU)
{
    AVK_MANU_SHOW_TIPS(L"1st string normal, 2nd string upto 7 character, 3rd string in borders and 4th string upto 7 and in border then pass.",avk_pluto_font_015);
}

AVK_MANUAL_CASE(AVK_PLUTO_FONT_CASE16,AVK_PLUTO_FONT_MANU)
{
    AVK_MANU_SHOW_TIPS(L"String should be shown till 7 character after that dots(бн) should be there the pass",avk_pluto_font_016);
}

AVK_MANUAL_CASE(AVK_PLUTO_FONT_CASE17,AVK_PLUTO_FONT_MANU)
{
    AVK_MANU_SHOW_TIPS(L"String shown should of RGB defined and bordered.",avk_pluto_font_017);
}

AVK_CASE(AVK_PLUTO_FONT_CASE18,AVK_PLUTO_FONT_AUTO)
{
    avk_pluto_font_018();
}

AVK_MANUAL_CASE(AVK_PLUTO_FONT_CASE19,AVK_PLUTO_FONT_MANU)
{
    AVK_MANU_SHOW_TIPS(L"Character A will be shown then pass",avk_pluto_font_019);
}

AVK_MANUAL_CASE(AVK_PLUTO_FONT_CASE20,AVK_PLUTO_FONT_MANU)
{
    AVK_MANU_SHOW_TIPS(L"if l2rmmi = false then pass",avk_pluto_font_020);
}

AVK_MANUAL_CASE(AVK_PLUTO_FONT_CASE21,AVK_PLUTO_FONT_MANU)
{
    AVK_MANU_SHOW_TIPS(L"If test string is shown like in bold characters and starting with starting position and till the length f string shown",avk_pluto_font_021);
}

AVK_MANUAL_CASE(AVK_PLUTO_FONT_CASE22,AVK_PLUTO_FONT_MANU)
{
    AVK_MANU_SHOW_TIPS(L"If date shown then pass",avk_pluto_font_022);
}

AVK_CASE(AVK_PLUTO_FONT_CASE23,AVK_PLUTO_FONT_AUTO)
{
    avk_pluto_font_023();
}

AVK_CASE(AVK_PLUTO_FONT_CASE24,AVK_PLUTO_FONT_AUTO)
{
    avk_pluto_font_024();
}


WCHAR* g_avk_pluto_font_buff = NULL;


/*****************************************************************************
* FUNCTION
*  avk_pluto_font_001
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/

void avk_pluto_font_001(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret = MMI_FALSE;
	stFontAttribute avk_small_font = {0, 0, 0, SMALL_FONT, 0, 0};
	S8 str_a[10];
	S8 str_temp[5];
//	U8 arrCount=0;
	U32 test_character = 'A';
	S32 pwidth,pheight,pDwidth,Ascent,Descent;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	screen_ret = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_font_001, MMI_FRM_FULL_SCRN);
	if(screen_ret == MMI_FALSE)
	{
	return;    
	}
	g_avk_pluto_font_buff = (U16*) AVK_MALLOC(1024);

	AVK_LOG_MANUAL(SetFont(avk_small_font,0));
	AVK_LOG_MANUAL(mmi_fe_get_char_info(test_character,&pwidth,&pDwidth,&pheight,&Ascent,& Descent));
	
	mmi_wcscpy(g_avk_pluto_font_buff, (WCHAR *)L"character info of 'A'");
	mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nHeight of A = ");
	sprintf((PS8)str_temp,(PS8)"%d",pheight);
	mmi_asc_to_ucs2(str_a,str_temp);
	mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
	mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nWidth of A = ");
	sprintf((PS8)str_temp,(PS8)"%d",pwidth);
	mmi_asc_to_ucs2(str_a,str_temp);
	mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
	mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nDwidth of A = ");
	sprintf((PS8)str_temp,(PS8)"%d",pDwidth);
	mmi_asc_to_ucs2(str_a,str_temp);
	mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
	mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nAsscent of A = ");
	sprintf((PS8)str_temp,(PS8)"%d",Ascent);
	mmi_asc_to_ucs2(str_a,str_temp);
	mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
	mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nDescent of A = ");
	sprintf((PS8)str_temp,(PS8)"%d",Descent);
	mmi_asc_to_ucs2(str_a,str_temp);
	mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
		  
	ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8) g_avk_pluto_font_buff,
        mmi_wcslen(g_avk_pluto_font_buff),
        NULL);
		
	AVK_SET_PASSKEY(NULL);
	AVK_SET_FAILKEY(NULL);
	AVK_FREE(g_avk_pluto_font_buff);
	
}

/*****************************************************************************
* FUNCTION
*  avk_pluto_font_002
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/

void avk_pluto_font_002(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret = MMI_FALSE;
	stFontAttribute avk_small_font = {0, 0, 0, SMALL_FONT, 0, 0};
	stFontAttribute temp_font = {0, 1, 2, 5, 0, 0};
	S8 str_a[30];
	S8 str_temp[15];
	U8 arrCount = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//memset(arrCount,0,sizeof(U8));
	screen_ret = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_font_002, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
    return;    
    }
    
	g_avk_pluto_font_buff = (U16*) AVK_MALLOC(1024);

    AVK_LOG_MANUAL(SetFont(avk_small_font,0));
    AVK_LOG_NORMAL(GetFont(&temp_font,&arrCount));
    mmi_wcscpy(g_avk_pluto_font_buff, (WCHAR *)L"SET FONT = 0 0 0 0 0 0\n");
    mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"GET FONT = ");
    sprintf((PS8)str_temp,(PS8)"%d %d %d %d %d %d",temp_font.bold,temp_font.color,temp_font.italic,temp_font.oblique,temp_font.size,temp_font.smallCaps);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_ucs2cat((CHAR *)g_avk_pluto_font_buff,(CHAR *) str_a);
	ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8) g_avk_pluto_font_buff,
        mmi_wcslen(g_avk_pluto_font_buff),
        NULL);
		
		AVK_SET_PASSKEY(NULL);
        AVK_SET_FAILKEY(NULL);
	AVK_FREE(g_avk_pluto_font_buff);
	
}


/*****************************************************************************
* FUNCTION
*  avk_pluto_font_003
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/

void avk_pluto_font_003(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret = MMI_FALSE;
	stFontAttribute avk_small_font = {0, 0, 0, SMALL_FONT, 0, 0};
	U32 test_character = 'A';
	S32 pWidth;
	S32 pHeight;
	S8 str_a[6];
	S8 str_temp[3];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	screen_ret = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_font_003, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
    return;    
    }
    
	g_avk_pluto_font_buff = (U16*) AVK_MALLOC(1024);
    SetFont(avk_small_font,0);
    AVK_LOG_NORMAL(Get_CharWidthHeight(test_character,&pWidth,&pHeight));
    mmi_wcscpy(g_avk_pluto_font_buff, (WCHAR *)L"Width of A = ");
    sprintf((PS8)str_temp,(PS8)"%d",pWidth);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *) str_a);
    mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\n Height of A = ");
    sprintf((PS8)str_temp,(PS8)"%d",pHeight);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *) str_a);

    ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8) g_avk_pluto_font_buff,
        mmi_wcslen(g_avk_pluto_font_buff),
        NULL);

    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
    AVK_FREE(g_avk_pluto_font_buff);
	
}


/*****************************************************************************
* FUNCTION
*  avk_pluto_font_004
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/


void avk_pluto_font_004(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret = MMI_FALSE;
	stFontAttribute avk_small_font = {0, 0, 0, SMALL_FONT, 0, 0};
	U32 test_character = 'A';
	S32 pCharWidth;
	S32 pCharHeight;
	S32 pBoxXoffset;
	S32 pBoxYoffset;
	S32 pBoxWidth;
	S32 pBoxHeight;
	S8 str_a[6];
	S8 str_temp[3];
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	screen_ret = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_font_004, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
    return;    
    }
	g_avk_pluto_font_buff = (U16*) AVK_MALLOC(1024);

	SetFont(avk_small_font,0);
	AVK_LOG_NORMAL(Get_CharBoundingBox(test_character,&pCharWidth,&pCharHeight,&pBoxXoffset,&pBoxYoffset,&pBoxWidth,&pBoxHeight));
	mmi_wcscpy(g_avk_pluto_font_buff, (WCHAR *)L"BOUNDING BOX \nChar Width of A = ");
	sprintf((PS8)str_temp,(PS8)"%d",pCharWidth);
	mmi_asc_to_ucs2(str_a,str_temp);
	mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
	mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nChar Height of A = ");
	sprintf((PS8)str_temp,(PS8)"%d",pCharHeight);
	mmi_asc_to_ucs2(str_a,str_temp);
	mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
	mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nX BOX Offset of A = ");
	sprintf((PS8)str_temp,(PS8)"%d",pBoxXoffset);
    mmi_asc_to_ucs2(str_a,str_temp);
	mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
	mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\n BOX Height of A = ");
	sprintf((PS8)str_temp,(PS8)"%d",pBoxYoffset);
    mmi_asc_to_ucs2(str_a,str_temp);
	mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
	mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nBOX Width of A = ");
	sprintf((PS8)str_temp,(PS8)"%d",pBoxWidth);
    mmi_asc_to_ucs2(str_a,str_temp);
	mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
	mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\n BOX Height of A = ");
	sprintf((PS8)str_temp,(PS8)"%d",pBoxHeight);
    mmi_asc_to_ucs2(str_a,str_temp);
	mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);

 	ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8) g_avk_pluto_font_buff,
        mmi_wcslen(g_avk_pluto_font_buff),
        NULL);
	
	

	AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
	AVK_FREE(g_avk_pluto_font_buff);
	
}


/*****************************************************************************
* FUNCTION
*  avk_pluto_font_005
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/

void avk_pluto_font_005(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret = MMI_FALSE;
	stFontAttribute avk_small_font = {0, 0, 0, SMALL_FONT, 0, 0};
	U8 *test_character = (U8 *)"Test String";
	S8 str_a[6];
	S8 str_temp[3];
	S32 no_of_char = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	screen_ret = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_font_005, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
    return;    
    }
	g_avk_pluto_font_buff = (U16*) AVK_MALLOC(1024);
    SetFont(avk_small_font,0);

    mmi_wcscpy(g_avk_pluto_font_buff, (WCHAR *)L"No. of character in Test String for width 100 = ");
    AVK_LOG_MANUAL(no_of_char = Get_CharNumInWidth_internal(test_character,100,1,4));
    sprintf((PS8)str_temp,(PS8)"%d",no_of_char);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
    mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nNo. of character in Test String for width 200 = ");
    no_of_char = Get_CharNumInWidth_internal(test_character,200,1,4);
    sprintf((PS8)str_temp,(PS8)"%d",no_of_char);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);

    ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8) g_avk_pluto_font_buff,
        mmi_wcslen(g_avk_pluto_font_buff),
        NULL);



    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
    AVK_FREE(g_avk_pluto_font_buff);
	
}

/*****************************************************************************
* FUNCTION
*  avk_pluto_font_006
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/

void avk_pluto_font_006(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret = MMI_FALSE;
	stFontAttribute avk_small_font = {0, 0, 0, SMALL_FONT, 0, 0};
	S32 asscent = 0;
	S32 descent = 0;
	S8 str_a[6];
	S8 str_temp[3];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	screen_ret = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_font_006, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
    return;    
    }
	g_avk_pluto_font_buff = (U16*) AVK_MALLOC(1024);
    SetFont(avk_small_font,0);
    AVK_LOG_MANUAL(asscent = Get_CharAscent());
    mmi_wcscpy(g_avk_pluto_font_buff, (WCHAR *)L"Asscent = ");
    sprintf((PS8)str_temp,(PS8)"%d",asscent);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
    AVK_LOG_MANUAL(descent = Get_CharDescent());
    mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\n Descent = ");
    sprintf((PS8)str_temp,(PS8)"%d",descent);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
    AVK_LOG_MANUAL(asscent = Get_CharDisplayAscentOfAllType());
    mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\n Ascent of all type = ");
    sprintf((PS8)str_temp,(PS8)"%d",asscent);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
    AVK_LOG_MANUAL(descent = Get_CharDisplayDescentOfAllType());
    mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\n Descent of all type = ");
    sprintf((PS8)str_temp,(PS8)"%d",descent);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);

    ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8) g_avk_pluto_font_buff,
        mmi_wcslen(g_avk_pluto_font_buff),
        NULL);


    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
    AVK_FREE(g_avk_pluto_font_buff);
	
}

/*****************************************************************************
* FUNCTION
*  avk_pluto_font_007
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/

void avk_pluto_font_007(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret = MMI_FALSE;
	S32 max_height = 0;
	S8 str_a[10];
	S8 str_temp[5];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	screen_ret = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_font_007, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
    return;    
    }
    
	g_avk_pluto_font_buff = (U16*) AVK_MALLOC(1024);
    AVK_LOG_MANUAL(max_height = Get_CharHeightOfAllLang(MEDIUM_FONT));
    mmi_wcscpy(g_avk_pluto_font_buff, (WCHAR *)L"Max height(SMALL FONT)= ");
    sprintf((PS8)str_temp,(PS8)"%d",max_height);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
    AVK_LOG_MANUAL(max_height = Get_CharDisplayHeightofAllType());
    mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\n Max height (SET FONT)= ");
    sprintf((PS8)str_temp,(PS8)"%d",max_height);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
    AVK_LOG_MANUAL(max_height =Get_CharHeightOfAllLang(LARGE_FONT));
    mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nMax height(LARGE FONT)= ");
    sprintf((PS8)str_temp,(PS8)"%d",max_height);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
    AVK_LOG_MANUAL(max_height = Get_CharDisplayHeightOfAllLangAndType(LARGE_FONT));
    mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\n Max height (LARGE FONT)= ");
    sprintf((PS8)str_temp,(PS8)"%d",max_height);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);

    ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8) g_avk_pluto_font_buff,
        mmi_wcslen(g_avk_pluto_font_buff),
        NULL);

    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
    AVK_FREE(g_avk_pluto_font_buff);	
}





/*****************************************************************************
* FUNCTION
*  avk_pluto_font_008
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/

void avk_pluto_font_008(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret = MMI_FALSE;
	stFontAttribute avk_small_font = {0, 0, 0, SMALL_FONT, 0, 0};
	S32 pwidth;
	S32 pheight;
	S8 str_a[10];
	S8 str_temp[5];
	U8 *test_character = (U8 *)"Test String";
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	screen_ret = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_font_008, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
    return;    
    }
    
	g_avk_pluto_font_buff = (U16*) AVK_MALLOC(1024);
    SetFont(avk_small_font,0);
    AVK_LOG_NORMAL(Get_StringWidthHeight(test_character, &pwidth,&pheight));
    mmi_wcscpy(g_avk_pluto_font_buff, (WCHAR *)L"Height of Test String = ");
    sprintf((PS8)str_temp,(PS8)"%d",pheight);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
    memset(str_a,0,sizeof(str_a));
    mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nWidth of Test String = ");
    sprintf((PS8)str_temp,(PS8)"%d",pwidth);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);

    ShowCategory78Screen(
    0,
    0,
    AVK_STR_PASS,
    0,
    AVK_STR_FAIL,
    0,
    NULL,
    (PU8) g_avk_pluto_font_buff,
    mmi_wcslen(g_avk_pluto_font_buff),
    NULL);


    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
    AVK_FREE(g_avk_pluto_font_buff);
}

/*****************************************************************************
* FUNCTION
*  avk_pluto_font_009
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/

void avk_pluto_font_009(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	stFontAttribute avk_small_font = {0, 0, 0, SMALL_FONT, 0, 0};
	MMI_BOOL screen_ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	screen_ret = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_font_009, MMI_FRM_FULL_SCRN);
	
    if(screen_ret == MMI_FALSE)
    {
    return;    
    }
	g_avk_pluto_font_buff = (U16*) AVK_MALLOC(1024);
	SetFont(avk_small_font,0);
	if(AVK_LOG_MANUAL(IsChineseSet()))
		mmi_wcscpy(g_avk_pluto_font_buff, (WCHAR *)L"Chinese = On ");
	else
		mmi_wcscpy(g_avk_pluto_font_buff, (WCHAR *)L"Chinese = Off ");

    if(AVK_LOG_MANUAL(IsEnglishSet()))
   		mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nEnglish = On");
	else
		mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nEnglish = Off");

    if(AVK_LOG_MANUAL(IsTrChineseSet()))
   		mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nTrChinese = On");
	else
		mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nTrChinese = Off");

    if(AVK_LOG_MANUAL(IsSmChineseSet()))
   		mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nSmChinese = On");
	else
		mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nSmChinese= Off");
	
 	ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8) g_avk_pluto_font_buff,
        mmi_wcslen(g_avk_pluto_font_buff),
        NULL);
	
	AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
	AVK_FREE(g_avk_pluto_font_buff);

}

/*****************************************************************************
* FUNCTION
*  avk_pluto_font_010
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/

void avk_pluto_font_010(void)
{

#ifdef __MMI_VECTOR_FONT_SUPPORT__

	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret = MMI_FALSE;
	stFontAttribute avk_small_font = {0, 0, 0, SMALL_FONT, 0, 0};
	S8 str_a[14];
	S8 *str_temp;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	screen_ret = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_font_010, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
    return;    
    }
    
    str_temp =(S8*) AVK_MALLOC(7 * sizeof(S8));
    g_avk_pluto_font_buff = (U16*) AVK_MALLOC(1024);
    SetFont(avk_small_font,0);
    strcpy(str_temp,(CHAR*)AVK_LOG_MANUAL(Get_Current_Lang_CountryCode()));
    mmi_wcscpy(g_avk_pluto_font_buff, (WCHAR *)L"Country Code of Current Language set = ");
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);

    ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8) g_avk_pluto_font_buff,
        mmi_wcslen(g_avk_pluto_font_buff),
        NULL);



    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
    AVK_FREE(g_avk_pluto_font_buff);
    AVK_FREE(str_temp);
#else
	AVK_LOG_FUN_UNSUPPORTED(Get_Current_Lang_CountryCode);
#endif		
			
	
}

/*****************************************************************************
* FUNCTION
*  avk_pluto_font_011
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/

void avk_pluto_font_011(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret = MMI_FALSE;
	stFontAttribute avk_small_font = {0, 0, 0, SMALL_FONT, 0, 0};
	S32 pwidth;
	S32 pheight;
	S8 str_a[10];
	S8 str_temp[5];
	U8 *test_character = (U8 *)"Test String";
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	screen_ret = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_font_011, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
    return;    
    }
    g_avk_pluto_font_buff = (U16*) AVK_MALLOC(1024);
    SetFont(avk_small_font,0);
    AVK_LOG_NORMAL(Get_StringWidthHeight_multitap(test_character,1,&pwidth,&pheight));
    mmi_wcscpy(g_avk_pluto_font_buff, (WCHAR *)L"Height of Test String = ");
    sprintf((PS8)str_temp,(PS8)"%d",pheight);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
    memset(str_a,0,sizeof(str_a));
    mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nWidth of \"Test String\" (gap b/w characters =1) = ");
    sprintf((PS8)str_temp,(PS8)"%d",pwidth);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);

    ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8) g_avk_pluto_font_buff,
        mmi_wcslen(g_avk_pluto_font_buff),
        NULL);



    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
    AVK_FREE(g_avk_pluto_font_buff);
		
	
}

/*****************************************************************************
* FUNCTION
*  avk_pluto_font_012
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/

void avk_pluto_font_012(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret = MMI_FALSE;
	stFontAttribute avk_small_font = {0, 0, 0, SMALL_FONT, 0, 0};
	S32 pwidth;
	S32 pheight;
	S8 str_a[10];
	S8 str_temp[5];
	U8 *test_character = (U8 *)"Test String";
	S32 max_width = 200;
	U8 checkLineBreak = 1,checkCompleteWord = 1;
	U32 no_of_character = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	screen_ret = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_font_012, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
    return;    
    }
    g_avk_pluto_font_buff = (U16*) AVK_MALLOC(1024);
    SetFont(avk_small_font,0);
    AVK_LOG_MANUAL(no_of_character = Get_StringWidthHeight_variant(test_character,2,11,&pwidth,&pheight,max_width,checkLineBreak,checkCompleteWord));
    mmi_wcscpy(g_avk_pluto_font_buff, (WCHAR *)L"Height of Test String = ");
    sprintf((PS8)str_temp,(PS8)"%d",pheight);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
    memset(str_a,0,sizeof(str_a));
    mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nWidth of Test String = ");
    sprintf((PS8)str_temp,(PS8)"%d",pwidth);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
    mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nNo. of characters to be displayed in Max width 200 = ");
    sprintf((PS8)str_temp,(PS8)"%d",no_of_character);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);

    ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8) g_avk_pluto_font_buff,
        mmi_wcslen(g_avk_pluto_font_buff),
        NULL);



    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
    AVK_FREE(g_avk_pluto_font_buff);	
}

/*****************************************************************************
* FUNCTION
*  avk_pluto_font_013
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/

void avk_pluto_font_013(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret = MMI_FALSE;
	stFontAttribute avk_small_font = {0, 0, 0, SMALL_FONT, 0, 0};
	mmi_fe_color result_color;
	mmi_fe_color set_color;
	S8 str_a[10];
	S8 str_temp[5];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	screen_ret = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_font_013, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
        return;    
    }
    set_color.a = 2;
    set_color.r = 0;
    set_color.g = 255;
    set_color.b = 0;
    g_avk_pluto_font_buff = (U16*) AVK_MALLOC(1024);
    SetFont(avk_small_font,0);
    AVK_LOG_NORMAL(mmi_fe_set_text_color(set_color));
    AVK_LOG_NORMAL(result_color = mmi_fe_get_text_color());
    mmi_wcscpy(g_avk_pluto_font_buff, (WCHAR *)L"\nAlpha= ");
    sprintf((PS8)str_temp,(PS8)"%d",result_color.a);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
    mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nRed= ");
    sprintf((PS8)str_temp,(PS8)"%d",result_color.r);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
    mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nGreen= ");
    sprintf((PS8)str_temp,(PS8)"%d",result_color.g);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
    mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nBlue= ");
    sprintf((PS8)str_temp,(PS8)"%d",result_color.b);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);		 

    ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8) g_avk_pluto_font_buff,
        mmi_wcslen(g_avk_pluto_font_buff),
        NULL);
    AVK_LOG_NORMAL(mmi_fe_set_text_color(set_color));
    AVK_LOG_MANUAL(mmi_fe_show_string_ext(0, LCD_HEIGHT/6, (PU8) (WCHAR *)L"Color of the string with r g b scale is = "));


    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
    AVK_FREE(g_avk_pluto_font_buff);		
	
}

/*****************************************************************************
* FUNCTION
*  avk_pluto_font_014
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/

void avk_pluto_font_014(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret = MMI_FALSE;
	stFontAttribute avk_small_font = {0, 0, 0, SMALL_FONT, 255, 2};
	U8* test_character =(PU8)L"Test String";
	S32 y_cordinate = LCD_HEIGHT/6;
	U8 str_direction = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	screen_ret = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_font_014, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
    return;    
    }
	g_avk_pluto_font_buff = (U16*) AVK_MALLOC(512);
	SetFont(avk_small_font,0);
	mmi_wcscpy(g_avk_pluto_font_buff, (WCHAR *)L"Show_str_bordered_baseline");
	mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\n\nShow_str_bordered_n_baseline (n=7)");
	mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\n\nShow_str_bordered_by_dir");

 	ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8) g_avk_pluto_font_buff,
        mmi_wcslen(g_avk_pluto_font_buff),
        NULL);

	y_cordinate += 30;
	AVK_LOG_MANUAL(mmi_fe_show_string_bordered_baseline(0,y_cordinate,test_character,20,0));
	y_cordinate += 30;
	y_cordinate += 60;
	AVK_LOG_MANUAL(mmi_fe_show_string_bordered_n_baseline(0,y_cordinate,test_character,7,20));
	y_cordinate += 30;
	y_cordinate += 30;
	
	AVK_LOG_MANUAL(str_direction = mmi_fe_get_string_direction(test_character,11));
	AVK_LOG_MANUAL(mmi_fe_show_string_bordered_by_direction(0,y_cordinate,test_character,str_direction));
	y_cordinate += 30;	

	AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
	AVK_FREE(g_avk_pluto_font_buff);
}


/*****************************************************************************
* FUNCTION
*  avk_pluto_font_015
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/

void avk_pluto_font_015(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret = MMI_FALSE;
	stFontAttribute avk_small_font = {0, 0, 0, SMALL_FONT, 0, 0};
	U16 *test_character = (WCHAR *)L"Test String";
	S32 y_cordinate = LCD_HEIGHT/6;
	//mmi_fe_color set_color;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    screen_ret = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_font_015, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
    return;    
    }
	SetFont(avk_small_font,0);
	 
 	ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        NULL,
        0,
        NULL);
        
//	set_color.a = 2;
//	set_color.r = 0;
//	set_color.g = 255;
//	set_color.b = 0;
	AVK_LOG_MANUAL(mmi_fe_show_string_ext(0,y_cordinate,(PU8)(WCHAR *)L"Show_str_baseline"));
	y_cordinate += 30;
	AVK_LOG_MANUAL(mmi_fe_show_string_baseline(0,y_cordinate,(PU8)test_character,20,0));
	y_cordinate += 30;
	AVK_LOG_MANUAL(mmi_fe_show_string_ext(0,y_cordinate,(PU8)(WCHAR *)L"Show_str_n_baseline\n(n=7)"));
	y_cordinate += 30;
	AVK_LOG_MANUAL(mmi_fe_show_string_n_baseline(0,y_cordinate,(PU8)test_character,7,20));
	y_cordinate += 30;
	AVK_LOG_MANUAL(mmi_fe_show_string_ext(0,y_cordinate,(PU8)(WCHAR *)L"Show_str_bordered"));
	y_cordinate += 30;
	AVK_LOG_MANUAL(mmi_fe_show_string_bordered(0,y_cordinate,(PU8)test_character));
	y_cordinate += 30;
	AVK_LOG_MANUAL(mmi_fe_show_string_ext(0,y_cordinate,(PU8)(WCHAR *)L"Show_str_n_bordered\n(n = 7)"));
	y_cordinate += 30;
	AVK_LOG_MANUAL(mmi_fe_show_string_bordered_n(0,y_cordinate,(PU8)test_character,7));
	y_cordinate += 30;	

	AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
}


/*****************************************************************************
* FUNCTION
*  avk_pluto_font_016
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/

void avk_pluto_font_016(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret = MMI_FALSE;
//	stFontAttribute avk_small_font = {0, 0, 0, SMALL_FONT, 0, 0};
	U8 *test_character = (PU8)(WCHAR *)L"Test String";
	U8 *truncated_symbol=(PU8)(WCHAR *)L"...";
    mmi_fe_ellipsis_type ellipsis_type = MMI_FE_ELLIPSIS_TAIL;
    S32 text_width, text_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	screen_ret = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_font_016, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
    return;    
    }

	ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        NULL,
        0,
        NULL);
    gui_measure_string((UI_string_type)test_character, &text_width, &text_height);
	AVK_LOG_MANUAL(mmi_fe_show_ellipsis_text(0,LCD_HEIGHT/6,text_width - 10,test_character,truncated_symbol,MMI_TRUE,ellipsis_type));

	AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
}


/*****************************************************************************
* FUNCTION
*  avk_pluto_font_017
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/

void avk_pluto_font_017(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret = MMI_FALSE;
	stFontAttribute avk_small_font = {0, 0, 0, SMALL_FONT, 0, 0};
//	U16 *test_character = (WCHAR *)L"Test String";
	mmi_fe_color result_color;
	mmi_fe_color set_color;
	S8 str_a[10];
	S8 str_temp[5];


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	screen_ret = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_font_017, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
    return;    
    }
    set_color.a = 2;
    set_color.r = 0;
    set_color.g = 255;
    set_color.b = 0;
    g_avk_pluto_font_buff = (U16*) AVK_MALLOC(1024);
    SetFont(avk_small_font,0);
    AVK_LOG_NORMAL(mmi_fe_set_text_color(set_color));
    AVK_LOG_NORMAL(result_color = mmi_fe_get_text_color());
    mmi_wcscpy(g_avk_pluto_font_buff, (WCHAR *)L"\nAlpha= ");
    sprintf((PS8)str_temp,(PS8)"%d",result_color.a);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
    mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nRed= ");
    sprintf((PS8)str_temp,(PS8)"%d",result_color.r);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
    mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nGreen= ");
    sprintf((PS8)str_temp,(PS8)"%d",result_color.g);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
    mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nBlue= ");
    sprintf((PS8)str_temp,(PS8)"%d",result_color.b);
    mmi_asc_to_ucs2(str_a,str_temp);
    mmi_wcscat(g_avk_pluto_font_buff,(WCHAR *)str_a);
		
	ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8) g_avk_pluto_font_buff,
        mmi_wcslen(g_avk_pluto_font_buff),
        NULL);
        
    set_color.a = 2;
    set_color.r = 0;
    set_color.g = 255;
    set_color.b = 0;

    AVK_LOG_NORMAL(mmi_fe_set_text_border_color(set_color));
    AVK_LOG_NORMAL(mmi_fe_set_text_color(set_color));
    AVK_LOG_MANUAL(mmi_fe_show_string_bordered(0,LCD_HEIGHT/6,(PU8)(WCHAR *)L"Show_str_bordered_baseline"));

    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
    AVK_FREE(g_avk_pluto_font_buff);
}

/*****************************************************************************
* FUNCTION
*  avk_pluto_font_018
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/

void avk_pluto_font_018(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 *test_character = (PU8)(WCHAR *)L"Test String";
	stFontAttribute avk_small_font = {0, 0, 0, SMALL_FONT, 0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	AVK_LOG_EX(mmi_fe_check_string(avk_small_font,test_character,11));	
}

/*****************************************************************************
* FUNCTION
*  avk_pluto_font_019
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/

void avk_pluto_font_019(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret = MMI_FALSE;
	stFontAttribute avk_small_font = {0, 0, 0, SMALL_FONT, 0, 0};
	U16 test_character ='A';
	mmi_fe_color set_color;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	screen_ret = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_font_019, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
    return;    
    }	

	g_avk_pluto_font_buff = (U16*) AVK_MALLOC(256);
	SetFont(avk_small_font,0);
    mmi_wcscpy(g_avk_pluto_font_buff, (WCHAR *)L"mmi_fe_show_char_with_bounding_box(width=10 height=10)");

    ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8) g_avk_pluto_font_buff,
        mmi_wcslen(g_avk_pluto_font_buff),
        NULL);
        
    set_color.a = 2;
    set_color.r = 0;
    set_color.g = 0;
    set_color.b = 0;
    AVK_LOG_NORMAL(mmi_fe_set_text_color(set_color));
    AVK_LOG_NORMAL(mmi_fe_show_char_with_bounding_box(0,LCD_HEIGHT/6+80,10,10,test_character,MMI_FE_ALIGN_CENTER,avk_small_font));

    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
    AVK_FREE(g_avk_pluto_font_buff);	
}

/*****************************************************************************
* FUNCTION
*  avk_pluto_font_020
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/

void avk_pluto_font_020(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret = MMI_FALSE;
//	stFontAttribute avk_small_font = {0, 0, 0, SMALL_FONT, 0, 0};
	MMI_BOOL result = MMI_FALSE,result_1 = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	screen_ret = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_font_020, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
        return;    
    }
    
	g_avk_pluto_font_buff = (U16*) AVK_MALLOC(1024);
	AVK_LOG_MANUAL(result = (MMI_BOOL)IsL2RMMIStyle());
	AVK_LOG_MANUAL(result_1=mmi_fe_is_r2l_state());
	
    mmi_wcscpy(g_avk_pluto_font_buff, (WCHAR *)L"IsL2RMMIStyle = ");
    if(result)
        mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"TRUE");
    else
        mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"FALSE ");
        mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\nmmi_fe_is_r2l_state = ");
    if(result_1)
        mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"TRUE");
    else
        mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"FALSE ");
	ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
         (PU8) g_avk_pluto_font_buff,
        mmi_wcslen(g_avk_pluto_font_buff),
        NULL);		
	
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
    AVK_FREE(g_avk_pluto_font_buff);	
}


/*****************************************************************************
* FUNCTION
*  avk_pluto_font_021
* DESCRIPTION
* 
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/

void avk_pluto_font_021(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL screen_ret = MMI_FALSE;
	stFontAttribute avk_small_font = {0, 0, 0, SMALL_FONT, 0, 0};
	U8*test_character =(PU8)(WCHAR *)L"Test String";
	mmi_fe_show_one_cluster_param_struct test_param;
	mmi_fe_color set_color;
	U32 len_cluster = 0;
	S8 str_a[10];
	S8 str_temp[5];
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                    						   */
    /*----------------------------------------------------------------*/
	screen_ret = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_font_021, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
        return;    
    }
	//memset(test_param,0,sizeof(mmi_fe_show_one_cluster_param_struct_p));
#ifdef __MMI_VECTOR_FONT_SUPPORT__
	AVK_LOG_NORMAL(mmi_fe_set_antialias(MMI_TRUE));
#else
    AVK_LOG_FUN_UNSUPPORTED(mmi_fe_set_antialias);
#endif /*__MMI_VECTOR_FONT_SUPPORT__*/

	g_avk_pluto_font_buff = (U16*) AVK_MALLOC(512);
	SetFont(avk_small_font,0);
	mmi_wcscpy(g_avk_pluto_font_buff, (WCHAR *)L"mmi_fe_show_single_cluster(start pos= 2 len =6 string =Test String)");
	mmi_wcscat(g_avk_pluto_font_buff, (WCHAR *)L"\n\n[Get_StringLength_InCluster] length = ");
	test_param.baseline = 10;
	test_param.bordered = 1;
	test_param.langid =1;
	test_param.len = mmi_wcslen((WCHAR *)test_character);
	test_param.string = (PU8) test_character;
	test_param.subarray_len = 6;
	test_param.subarray_start = 2;
	test_param.x =0;
	test_param.y = LCD_HEIGHT/6 + 90;

	ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8) g_avk_pluto_font_buff,
        mmi_wcslen(g_avk_pluto_font_buff),
        NULL);
    
    set_color.a = 2;
    set_color.r = 0;
    set_color.g = 0;
    set_color.b = 0;
    AVK_LOG_NORMAL(mmi_fe_set_text_color(set_color));
    AVK_LOG_NORMAL(mmi_fe_show_single_cluster(&test_param));
    AVK_LOG_MANUAL(len_cluster = Get_StringLength_InCluster(test_character,7,5));
    sprintf((PS8)str_temp,(PS8)"%d",len_cluster);
    mmi_asc_to_ucs2(str_a,str_temp);
    AVK_LOG_MANUAL(mmi_fe_show_string_ext(0,LCD_HEIGHT/6+180,(U8*)str_a));
    AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
    AVK_FREE(g_avk_pluto_font_buff);
    
#ifdef __MMI_VECTOR_FONT_SUPPORT__
	mmi_fe_set_antialias(MMI_FALSE);
#endif 	/*__MMI_VECTOR_FONT_SUPPORT__*/
	
}
U32 mmi_notes_app_get_time_1(void)
{
    applib_time_struct t;

    applib_dt_get_rtc_time(&t);
    return (U32) applib_dt_sec_local_to_utc(applib_dt_mytime_2_utc_sec(&t, KAL_FALSE));
}
void avk_pluto_font_022(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                              						   */
    /*----------------------------------------------------------------*/
	
	MYTIME calender_time, calender_time_temp;
	FLOAT timezone;
	S8 arr[100] = {'\0'};
	U32 cmp_time;
	MMI_BOOL screen_ret;
	/*----------------------------------------------------------------*/
    /* Code Body                                                    						   */
    /*----------------------------------------------------------------*/
	screen_ret = mmi_frm_scrn_enter(AVK_MAIN_GRP_ID, AVK_SCR_ID_1, NULL, avk_pluto_font_022, MMI_FRM_FULL_SCRN);
    if(screen_ret == MMI_FALSE)
    {
    return;    
    }
	cmp_time  = mmi_notes_app_get_time_1();


	timezone = mmi_dt_get_tz();
	
	mmi_dt_utc_sec_2_mytime(cmp_time, &calender_time_temp, MMI_TRUE);
    mmi_dt_utc_to_rtc(timezone, calender_time_temp, calender_time);
    date_string(&calender_time, (UI_string_type)arr, DT_IDLE_SCREEN_ENGLISH_ONLY);
	g_avk_pluto_font_buff = (U16*) AVK_MALLOC(512);
	mmi_wcscpy(g_avk_pluto_font_buff, (WCHAR *)L"DATE :");
	mmi_wcscat(g_avk_pluto_font_buff,(WCHAR*) arr);

	AVK_LOG_NORMAL(mmi_fe_enable_date_char_display());
	ShowCategory78Screen(
        0,
        0,
        AVK_STR_PASS,
        0,
        AVK_STR_FAIL,
        0,
        NULL,
        (PU8) g_avk_pluto_font_buff,
        mmi_wcslen(g_avk_pluto_font_buff),
        NULL);

	AVK_LOG_NORMAL(mmi_fe_disable_date_char_display());
	AVK_SET_PASSKEY(NULL);
    AVK_SET_FAILKEY(NULL);
	AVK_FREE(g_avk_pluto_font_buff);
	
}




void avk_pluto_font_023(void)
{
//	U8 result1,result3;

	AVK_LOG_EX(LARGE_FONT == mmi_fe_pixel_to_size(22));
	AVK_LOG_EX(SMALL_FONT == mmi_fe_pixel_to_size(12));
}


void avk_pluto_font_024(void)
{
//    S32 return_value;
    mmi_fe_get_string_info_param_struct query;
    U8 m_direction;
    
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = (U8*)"test";
    query.n = 0;
    query.w = 0;
    query.targetWidth = 10;
    query.enableTruncated = MMI_TRUE;
    query.checkCompleteWord = 0;
    query.checklinebreak = 1;
	
    AVK_LOG_EX(0 == mmi_fe_get_string_widthheight_ext(&query, &m_direction, NULL, NULL));
}
