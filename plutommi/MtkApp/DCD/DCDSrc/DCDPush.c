/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
/*******************************************************************************
* Filename:
* ---------
*  DCDPush.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   DCD get push(sl) 
*
* Author:
* -------
 * -------
*
*==============================================================================
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
*******************************************************************************/
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_OP01_DCD__
#include "app_buff_alloc.h"
#include "app_mine.h"
#include "DCDProt.h"
#include "MMIDataType.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "fs_func.h"
#include "kal_general_types.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
#define	 APPLICATION_ID_HDR		"X-WAP-Application-ID"
#define  DCD_APPLICATION_ID		"application/x-oma-dcd:dcd.ua"
#define  DCD_BASE_URL           "http://dcd.monternet.com:80"
   
static int dcd_is_dcd_app_id(const S8 * header, const S8 *dcd);
static int mmi_dcd_toupper(int c);

extern const S8* mmi_da_get_header(S32 session_id, U32* header_len);


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_receive_da_file
 * DESCRIPTION
 *  receive the push message file
 * PARAMETERS
 *  session_id              [IN]        
 *  mime_type               [IN]        The mime type of file
 *  mime_subtype            [IN]        The sub mime type of file
 *  action                  [IN]        
 *  filepath                [IN]        Of file
 *  url                     [IN]        
 *  mime_type_string        [IN]        The originaly mime type string get from server
  * RETURNS
 *   void
 *****************************************************************************/
void mmi_dcd_receive_da_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        PU16 filepath,
        PS8 url,
        PS8 mime_type_string)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 	const S8 *  header;
	U32			header_len;
	int			is_dcd_app;
	S8		*	sl_url = NULL;
	S8		*	sl_action = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_ENTRY_PUSH_HANDLER);

	header = mmi_da_get_header(session_id, &header_len);
    if (header == NULL)
        return;

    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_PUSH_HEADER);

	is_dcd_app = dcd_is_dcd_app_id(header, DCD_APPLICATION_ID);
    MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_PUSH_IS_DCD, is_dcd_app);
    
    if (!is_dcd_app)
	{
        return;
    }
    
    if ( mime_subtype == MIME_SUBTYPE_SL )
    {
        mmi_dcd_get_attr_from_sl(filepath, &sl_url, &sl_action);
    }
    else if ( mime_subtype == MIME_SUBTYPE_SLC )
    {
        mmi_dcd_get_attr_from_slc(filepath, &sl_url, &sl_action);
    }

    if (sl_url)
    {
        MMI_TRACE(MMI_CONN_TRC_G8_DCD, MMI_DCD_PUSH_URL);
        /* need not reassamble the url, vendor will do it */
        mmi_dcd_push_to_sync(sl_url);
    }

    FS_Delete((WCHAR *)filepath);

	if (sl_url)
		free_ctrl_buffer(sl_url);
	if (sl_action)
		free_ctrl_buffer(sl_action);
}


/*****************************************************************************
 * FUNCTION
 *  dcd_is_dcd_app_id
 * DESCRIPTION
 *  compare application id with dcd specific application id
 * PARAMETERS
 *  header      [IN]        Sl protocol header
 *  dcd         [IN]        Dcd specific application id
 * RETURNS
 *   0 : FALSE
 *   1 : YES
 *****************************************************************************/
static int dcd_is_dcd_app_id(const S8 * header, const S8 *dcd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	const S8 * p1, * p2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( (header == NULL) || (dcd == NULL))
		return 0;

	p1 = header;
	while ( *p1 != 0 )
	{
		while ( (*p1 != 0) && (*p1 == ' '))
			p1++;
		p2 = p1; 
		while ( *p2 != '\0')
		{
			if ( *p2 == ':' || *p2 == ' ')
				break;
			p2++;
		}
		if ( mmi_dcd_strnicmp(p1, APPLICATION_ID_HDR, p2-p1) == 0 )
		{
			p1 = p2;
			while ( *p1 == ' ')
				p1++;
			if ( *p1 == ':' )
				p1++;
			while ( *p1 == ' ')
				p1++;

			p2 = p1;
			while ( *p2 != 0 )
			{
				if ( *p2 == '\r' || *p2 == '\n')
					break;
				p2 ++;
			}
			if ( mmi_dcd_strnicmp(p1, dcd, p2-p1) == 0 )
				return 1;
		}

		p1 = p2;
		while( (*p1 != 0)  &&  (*p1 != '\r') && (*p1 != '\n'))
		{
			p1++;
		}

		if ( *p1 == '\r' || *p1 == '\n')
		{
			while ( *p1 == '\r' || *p1 == '\n' )
				p1 ++;
		}
	}

	return 0;
}


/***************************************************************************************
    the following code is for string handle 
 ***************************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_toupper
 * DESCRIPTION
 *  convert a char to upper 
 * PARAMETERS
 *  c       [IN]        A char
 * RETURNS
 *  upper char
 *****************************************************************************/
static int mmi_dcd_toupper(int c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( c >= 'a' && c <= 'z' )
		c = c - 'a' + 'A';
	return c;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_stricmp
 * DESCRIPTION
 *  compare two strings
 * PARAMETERS
 *  s1      [IN]        String
 *  s2      [IN]        String
 * RETURNS
 *  0     : same
 *  Non 0 : different
 *****************************************************************************/
int mmi_dcd_stricmp(const char *s1, const char *s2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while (*s1 != '\0' && mmi_dcd_toupper(*s1) == mmi_dcd_toupper(*s2))
	{
		s1++;
		s2++;
	}
	
	return mmi_dcd_toupper(*(unsigned char *) s1) - mmi_dcd_toupper(*(unsigned char *) s2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dcd_strnicmp
 * DESCRIPTION
 *  compare two strings with specific length
 * PARAMETERS
 *  s1      [IN]        String
 *  s2      [IN]        String
 *  n       [IN]        Specific length
 * RETURNS
 *  0     : same
 *  Non 0 : different
 *****************************************************************************/
int mmi_dcd_strnicmp(const char *s1, const char *s2, unsigned int n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (n == 0)
		return 0;
	if (s1 == NULL || s2 == NULL)
		return 1;
	
	while (n-- != 0 && mmi_dcd_toupper(*s1) == mmi_dcd_toupper(*s2))
	{
		if (n == 0 || *s1 == '\0' || *s2 == '\0')
			break;
		s1++;
		s2++;
	}
	
	return mmi_dcd_toupper(*(unsigned char *) s1) - mmi_dcd_toupper(*(unsigned char *) s2);
}

#endif /* __MMI_OP01_DCD__*/

