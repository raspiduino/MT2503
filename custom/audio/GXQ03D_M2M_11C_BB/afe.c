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
 *
 * Filename:
 * ---------
 * afe.c
 *
 * Project:
 * --------
 *   MT6219
 *
 * Description:
 * ------------
 *   Audio Front End
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *******************************************************************************/
#include "afe_def.h"
#include "Dcl_gpio.h"
#include "dcl.h"
#include "Gpio_drv.h"

#ifdef __LINE_IN_SUPPORT__ 
#define LINEIN_BB_SWITCH_PIN GPIO_PORT_19
#endif

#ifdef __BT8123_SUPPORT__
#define __USING_CLASSD__
#define BT8123_CTRL_PIN GPIO_PORT_17
#define BT8123_MODE_PIN GPIO_PORT_16
#define BT8123_MUTE_PIN GPIO_PORT_19
#define AFE_DELAY (0x24)

void afeDelay(kal_uint8 delay_us) 
{
  kal_uint8 i=0;
  kal_uint32 delay;
  for(i=0;i<delay_us;i++)
    for (delay =0;delay <AFE_DELAY;delay++) {}
}

#endif

extern void GPO_WriteIO(char data,char port);

/*****************************************************************************
* FUNCTION
*  AFE_Initialize
* DESCRIPTION
*   This function is to set the initial value of AFE HW.
*****************************************************************************/
void AFE_Initialize( void )
{
}

/*****************************************************************************
* FUNCTION
*  AFE_SwitchExtAmplifier
* DESCRIPTION
*   This function is to turn on/off external amplifier.
*****************************************************************************/
void AFE_SwitchExtAmplifier( char sw_on )
{
#ifdef __BT8123_SUPPORT__
	DCL_HANDLE handle;
	static kal_bool on=KAL_FALSE;
	
    kal_prompt_trace(MOD_L1SP,"***** AFE_SwitchExtAmplifier %d,%d *****",on,sw_on);
    if(on == sw_on)
		return;
	
	if(sw_on)
	{
	    #ifdef __LINE_IN_SUPPORT__
		//Set linein or BB as PA's input source
		handle = DclGPIO_Open(DCL_GPIO,LINEIN_BB_SWITCH_PIN);
		if(aud_is_bt_box_linein_enable())
		    DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
	    else
		    DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
		DclGPIO_Close(handle);
		#endif
	    kal_sleep_task(10);//For de-pop?

		//Set ClassAB/ClassD
		handle = DclGPIO_Open(DCL_GPIO,BT8123_MODE_PIN);
        #ifdef __USING_CLASSD__
	    if(FMR_IsActive())
		    DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
	    else
		    DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
        #else/*__USING_CLASSD__*/
		DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
        #endif/*__USING_CLASSD__*/
		DclGPIO_Close(handle);

        //Mute fisrt
        handle = DclGPIO_Open(DCL_GPIO,BT8123_MUTE_PIN);
		DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
		afeDelay(2);
		DclGPIO_Close(handle);
        //EnablePA
		handle = DclGPIO_Open(DCL_GPIO,BT8123_CTRL_PIN);
		DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
		afeDelay(2);//Delay 1~12 us
		DclGPIO_Close(handle);
        //Unmute PA
		handle = DclGPIO_Open(DCL_GPIO,BT8123_MUTE_PIN);
		DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
		afeDelay(2);
		DclGPIO_Close(handle);
	}
	else
	{
	    //Mute fisrt
        handle = DclGPIO_Open(DCL_GPIO,BT8123_MUTE_PIN);
		DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
		afeDelay(2);
		DclGPIO_Close(handle);
		//disable PA
		handle = DclGPIO_Open(DCL_GPIO,BT8123_CTRL_PIN);
		DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
		DclGPIO_Close(handle);
		kal_sleep_task(1);
	}
    on = sw_on;	
#else /*__BT8123_SUPPORT__*/
    if( sw_on )
        GPO_WriteIO( 1, 1 );
    else
        GPO_WriteIO( 0, 1 );
#endif /*__BT8123_SUPPORT__*/
}


