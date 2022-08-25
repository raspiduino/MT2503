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

/*****************************************************************************
 *
 * Filename:
 * ---------               
 *    auxmain.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the AUX task
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __L1_STANDALONE__

#include    "kal_release.h"/*kal_sleep_task*/

#include    "aux_custom.h"
#include    "accessory_sw.h"

#ifdef TV_OUT_SUPPORT  
#include 	 "tv_out.h"
extern kal_bool aux_tvout_on;
#endif

//if CLAM/SLIDE support, add the global varials here.
#if (defined(__PHONE_CLAMSHELL__) || defined(__PHONE_SLIDE__))
//kal_bool clam_state = LEVEL_HIGH;
//extern const unsigned char CLAMDET_EINT_NO;
#endif //(defined(__PHONE_CLAMSHELL__) || defined(__PHONE_SLIDE__))

/************************************************************
	UART_SWITH & TVOUT_SWITCH pin support
*************************************************************/
void aux_uart_switch(kal_bool enable)
{
	//if USB_UART_SWITCH and EARPHONE_USB_UART_SWITCH pins are defined, add the related code here.
	
}
void aux_enable_HS_TV(kal_bool enable)
{
	#ifdef TV_OUT_SUPPORT
	//if TV_OUT_SWITCH pin is defined, add the related code here.
	
	#endif //TV_OUT_SUPPORT    
}

/************************************************************
	clam/slide
*************************************************************/
//if CLAM/SLIDE support, add L_Clam_State() and CLAM_EINT_HISR() here.
#if (defined(__PHONE_CLAMSHELL__) || defined(__PHONE_SLIDE__))

#endif //(defined(__PHONE_CLAMSHELL__) || defined(__PHONE_SLIDE__))

/************************************************************
	aux custom initialize, will be called in the beginning of aux_task_main()
*************************************************************/
void aux_custom_init(void)
{
	aux_uart_switch(KAL_TRUE);  //uart mode
	
	#ifdef TV_OUT_SUPPORT
	aux_enable_HS_TV(KAL_TRUE);  //turn off TV
	#endif //#ifdef TV_OUT_SUPPORT
	
	//if CLAM/SLIDE support, add the initialization code here.
	
}

/************************************************************
	customization functions
*************************************************************/
void aux_custom_plug_in (void)
{
	#ifdef TV_OUT_SUPPORT
	aux_enable_HS_TV(KAL_TRUE);
	#endif //#ifdef TV_OUT_SUPPORT
}

void aux_custom_plug_out (void)
{
	aux_uart_switch(KAL_TRUE);  //uart mode
	
	#ifdef TV_OUT_SUPPORT
	if (aux_tvout_on == KAL_TRUE) //disable TV-OUT	
	{
		enable_tv_output(KAL_FALSE);
		deinit_tv();
	}
	aux_tvout_on = KAL_FALSE;
	#endif //TV_OUT_SUPPORT
}

void aux_custom_uart_func(kal_bool enable)
{
	aux_uart_switch(enable);
}

void aux_custom_HSTV_func(kal_bool enable)
{
	#ifdef TV_OUT_SUPPORT
	aux_enable_HS_TV(enable);
	#endif //TV_OUT_SUPPORT 
}

const aux_func_struct aux_custom_func = 
{
	aux_custom_plug_in,
	aux_custom_plug_out,
	aux_custom_uart_func,
	aux_custom_HSTV_func
};

const aux_func_struct *aux_GetFunc(void)
{
   return (&aux_custom_func);  
} 

#endif /*__L1_STANDALONE__*/
