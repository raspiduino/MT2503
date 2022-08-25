/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   IMEResT9.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This is header file for T9 IME Resource for Multiple Bin.
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
 
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _IME_Res_T9_H_
#define _IME_Res_T9_H_

#include "t9cgen.h"



#ifdef __MMI_T9_ENGLISH__ 
#include "l0109b00.h"       
#include "l0109b01.h"
#include "l0109b02.h"
#endif


/*Array for T9 IME LDB*/
const sIMELDBDetails mtk_gIMELDBArray[]=
{                              


#ifdef __MMI_T9_ENGLISH__
{
    T9PIDEnglish,
    2,
    5319,
    {
        l0109b00,
        l0109b01,
        l0109b02
    }
},
#endif                             
                              

                            
      /* for checking end */
{
		(0xff),
		0,
		0,
		{
		    0
		}
}

};
#endif/*IME_RES_T9*/
