/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 * avk_pluto_string.cpp
 *
 * Project:
 * --------
 *  MAUI 
 *
 * Description:
 * ------------
 *  This file implement the function to test pluto string
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/****************************************************************************
 * Include
 ****************************************************************************/
extern "C"
{
#include "Unicodexdcl.h"    
#include "app_str.h"
}


/*****************************************************************************
 * Local Function                                                              
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  AVK_PLUTO_STR_UT
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_PLUTO_STR_UT, AVK_PLUTO_STR)
{
	mmi_frm_string_ut(0);
    AVK_LOG_FUN(mmi_frm_string_ut, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  AVK_PLUTO_STR_ASC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_PLUTO_STR_ASC, AVK_PLUTO_STR)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	CHAR ASC[] = "abcdef";
	CHAR UCS[7 * 2] = {0};
	CHAR UCSN[7 * 2] = {0};
	int i = 0;
	int len = 5;
	wchar_t WCS[7] = {0};
	wchar_t WCSN[7] = {0};
	wchar_t temp_WCS[] = L"abcdef";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((CHAR *)UCS, (CHAR *)ASC);
    for(i = 0; i < 7; i++)
	{
	    ASSERT(UCS[i + i] == ASC[i]);
	    ASSERT(UCS[i + i + 1] == 0x00);
	}
    AVK_LOG_FUN(mmi_asc_to_ucs2, AVK_PASS);

    mmi_asc_n_to_ucs2((CHAR *)UCSN, (CHAR *)ASC, len);
    for(i = 0; i < len; i++)
	{
	    ASSERT(UCSN[i + i] == ASC[i]);
	    ASSERT(UCSN[i + i + 1] == 0x00);
	}
    AVK_LOG_FUN(mmi_asc_n_to_ucs2, AVK_PASS);

    mmi_asc_to_wcs((WCHAR *)WCS, (CHAR *)ASC);
	for(i = 0; i < 7; i++)
	{
		ASSERT(WCS[i] == temp_WCS[i]);
	}
    AVK_LOG_FUN(mmi_asc_to_wcs, AVK_PASS);
    
	mmi_asc_n_to_wcs((WCHAR *)WCSN, ASC, len);
	for(i = 0; i < len; i++)
	{
		ASSERT(WCSN[i] == temp_WCS[i]);
	}
    AVK_LOG_FUN(mmi_asc_n_to_wcs, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  AVK_PLUTO_STR_UCS2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_PLUTO_STR_UCS2, AVK_PLUTO_STR)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR ASC[] = "abcd";
	CHAR UCS[5 * 2] = {0};
	CHAR UCS_eq[] = {0x61, 0x00, 0x62, 0x00, 0x63, 0x00, 0x64, 0x00, 0x00, 0x00};/* abcd */
	CHAR UCS_lg[] = {0x61, 0x00, 0x62, 0x00, 0x66, 0x00, 0x64, 0x00, 0x00, 0x00};/* abfd */
	CHAR UCS_cpy[5 * 2] = {0};
	CHAR UCS_ncpy[5 * 2] ={0};
	CHAR UCS_cat[] = {0x64, 0x00, 0x00, 0x00};/* d */
	CHAR UCS_ncat1[] = {0x61, 0x00, 0x62, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};/* ab */
	CHAR UCSncat2[] = {0x63, 0x00, 0x64, 0x00, 0x00, 0x00};/* cd */
	CHAR UCS2ASC[10] = {0};
	CHAR UCSN2ASC[10] = {0};
	CHAR ASCN[] = "abc";
	U32 size = 3;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_asc_to_ucs2((CHAR *)UCS, (CHAR *)ASC);
	ASSERT(4 == mmi_ucs2strlen((const CHAR *)UCS));
	AVK_LOG_FUN(mmi_ucs2strlen, AVK_PASS);
    
	ASSERT(0 == mmi_ucs2cmp((const CHAR *)UCS, (const CHAR *)UCS_eq));
	ASSERT(mmi_ucs2cmp((const CHAR *)UCS, (const CHAR *)UCS_lg) < 0);
    AVK_LOG_FUN(mmi_ucs2cmp, AVK_PASS);

	ASSERT(0 == mmi_ucs2ncmp((const CHAR *)UCS, (const CHAR *)UCS_eq, size));
    ASSERT(mmi_ucs2ncmp((const CHAR *)UCS, (const CHAR *)UCS_lg, size) < 0);
	AVK_LOG_FUN(mmi_ucs2ncmp, AVK_PASS);

	mmi_ucs2cpy((CHAR *)UCS_cpy, (const CHAR *)UCS);
    ASSERT(0 == mmi_ucs2cmp((const CHAR *)UCS_cpy, (const CHAR *)UCS));
    AVK_LOG_FUN(mmi_ucs2cpy, AVK_PASS);

    mmi_ucs2ncpy((CHAR *)UCS_ncpy, (const CHAR *)UCS, size);/* UCS_ncpy[] = "abc" */
	ASSERT(0 == mmi_ucs2ncmp((const CHAR *)UCS, (const CHAR *)UCS_ncpy, size));
	AVK_LOG_FUN(mmi_ucs2ncpy, AVK_PASS);

	mmi_ucs2cat((CHAR *)UCS_ncpy, (const char *)UCS_cat); /* UCS_ncpy[] = "abcd" */
    ASSERT(0 == mmi_ucs2cmp((const CHAR *)UCS, (const CHAR *)UCS_ncpy));
	AVK_LOG_FUN(mmi_ucs2cat, AVK_PASS);

	mmi_ucs2ncat((CHAR *)UCS_ncat1, (const char *)UCSncat2, 2); /* UCS_ncat1[] ="abcd" */
    ASSERT(0 == mmi_ucs2cmp((const CHAR *)UCS, (const CHAR *)UCS_ncat1));
	AVK_LOG_FUN(mmi_ucs2ncat, AVK_PASS);

    mmi_ucs2_to_asc((CHAR *)UCS2ASC, (CHAR *)UCS);
	ASSERT(0 == strcmp((const char *)UCS2ASC, (const char *)ASC));
	AVK_LOG_FUN(mmi_ucs2_to_asc, AVK_PASS);

	mmi_ucs2_n_to_asc((CHAR *)UCSN2ASC, (CHAR *)UCS, size * 2);
	ASSERT(0 == strcmp((const char *)UCSN2ASC, (const char *)ASCN));
	AVK_LOG_FUN(mmi_ucs2_n_to_asc, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  AVK_PLUTO_STR_WCS
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_PLUTO_STR_WCS, AVK_PLUTO_STR)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wchar_t WCS[] = L"abcdef";
	wchar_t WCS_eq[] = L"abcdef";
	wchar_t WCS_lg[] = L"abcgef";
	wchar_t WCS_copy[10] = {0};
	wchar_t WCS_ncopy[10] = {0};
	wchar_t WCS_cat[] = L"ef";
	wchar_t WCS_ncat[] = L"abcdefef";
	CHAR WCS2ASC[] = "abcdef";
	CHAR WCS2ASCL[10] = {0};
	CHAR WCS2NASC[] = "abcd";
	CHAR WCSN2ASCL[10] = {0};
	S32 len = 0;
	U32 count = 4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = mmi_wcslen((const WCHAR *)WCS);
	ASSERT(6 == len);
	AVK_LOG_FUN(mmi_wcslen, AVK_PASS);

	ASSERT(0 == mmi_wcscmp((const WCHAR *)WCS, (const WCHAR *)WCS_eq));
	ASSERT(mmi_wcscmp((const WCHAR *)WCS_lg, (const WCHAR *)WCS) > 0);
	AVK_LOG_FUN(mmi_wcscmp, AVK_PASS);

	ASSERT(0 == mmi_wcsncmp((const WCHAR *)WCS, (const WCHAR *)WCS_eq, count));
	ASSERT( mmi_wcsncmp((const WCHAR *)WCS_lg, (const WCHAR *)WCS, count) > 0);
	AVK_LOG_FUN(mmi_wcsncmp, AVK_PASS);
    
    mmi_wcscpy((WCHAR *)WCS_copy, (const WCHAR *)WCS); /* WCS_copy[] = "abcdef" */
	ASSERT(0 == mmi_wcscmp((const WCHAR *)WCS_copy, (const WCHAR *)WCS));
	AVK_LOG_FUN(mmi_wcscpy, AVK_PASS);

	mmi_wcsncpy((WCHAR *)WCS_ncopy, (WCHAR *)WCS, count); /* WCS_ncopy[] = "abcd" */
	ASSERT(0 == mmi_wcsncmp((const WCHAR *)WCS_ncopy, (const WCHAR *)WCS, count));
	AVK_LOG_FUN(mmi_wcsncpy, AVK_PASS);

	mmi_wcscat((WCHAR *)WCS_ncopy, (const WCHAR *)WCS_cat); /* WCS_ncopy[] = "abcdef" */
	ASSERT(0 == mmi_wcscmp((const WCHAR *)WCS, (const WCHAR *)WCS_ncopy));
	AVK_LOG_FUN(mmi_wcscat, AVK_PASS);
   
    mmi_wcsncat((WCHAR *)WCS_ncopy, (const WCHAR *)WCS_cat, 2); /* WCS_ncopy[] = "abcdefef" */
	ASSERT(0 == mmi_wcscmp((const WCHAR *)WCS_ncat, (const WCHAR *)WCS_ncopy));
    AVK_LOG_FUN(mmi_wcsncat, AVK_PASS);

    mmi_wcs_to_asc((CHAR *)WCS2ASCL, (WCHAR *)WCS);
    ASSERT(0 == strcmp((const char *)WCS2ASCL, (const char *)WCS2ASC));
    AVK_LOG_FUN(mmi_wcs_to_asc, AVK_PASS);

    mmi_wcs_n_to_asc((CHAR *)WCSN2ASCL, (WCHAR *)WCS, count * 2);
	ASSERT(0 == strcmp((const char *)WCSN2ASCL, (const char *)WCS2NASC));
	AVK_LOG_FUN(mmi_wcs_n_to_asc, AVK_PASS);
}


/*****************************************************************************
 * FUNCTION
 *  AVK_PLUTO_STR_OTHER
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
AVK_CASE(AVK_PLUTO_STR_OTHER, AVK_PLUTO_STR)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	CHAR UCSUPR[] = {0x41, 0x00, 0x42, 0x00, 0x43, 0x00, 0x44, 0x00, 0x00, 0x00};/* ABCDEF */
	CHAR UCSLWR[] = {0x61, 0x00, 0x62, 0x00, 0x63, 0x00, 0x64, 0x00, 0x00, 0x00};/* abcdef */
	CHAR UCS[] = {0x61, 0x00, 0x62, 0x00, 0x63, 0x00, 0x64, 0x00, 0x00, 0x00};/* abcdef */
    wchar_t WCSUPR[] = L"ABCDEF";
	wchar_t WCSLWR[] = L"abcdef";
	wchar_t WCS[] = L"abcdef";
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2upr((CHAR *)UCSLWR);/* UCSLWR[] = "ABCDEF" */
	ASSERT(0 == mmi_ucs2cmp((const CHAR *)UCSLWR, (const CHAR *)UCSUPR));
	AVK_LOG_FUN(mmi_ucs2upr, AVK_PASS);

    mmi_ucs2lwr((CHAR *)UCSLWR);/* UCSLWR[] = "abcdef" */
	ASSERT(0 == mmi_ucs2cmp((const CHAR *)UCSLWR, (const CHAR *)UCS));
	AVK_LOG_FUN(mmi_ucs2lwr, AVK_PASS);

    ASSERT(0 == mmi_ucs2icmp((const CHAR *)UCSUPR, (const CHAR *)UCSLWR));
	AVK_LOG_FUN(mmi_ucs2icmp, AVK_PASS);

    mmi_wcsupr((WCHAR *)WCSLWR); /* WCSLWR[] = "ABCDEF" */
	ASSERT(0 == mmi_wcscmp((const WCHAR *)WCSLWR, (const WCHAR *)WCSUPR));
	AVK_LOG_FUN(mmi_wcsupr, AVK_PASS);

	mmi_wcslwr((WCHAR *)WCSLWR); /* WCSLWR[] = "abcdef" */
	ASSERT(0 == mmi_wcscmp((const WCHAR *)WCSLWR, (const WCHAR *)WCS));
	AVK_LOG_FUN(mmi_wcslwr, AVK_PASS);

    ASSERT(0 == mmi_wcsicmp((const WCHAR *)WCSUPR, (const WCHAR *)WCSLWR));
	AVK_LOG_FUN(mmi_wcsicmp, AVK_PASS);
}
