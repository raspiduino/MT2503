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
 *   gpio_def.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides definition for GPIO mode, direction, pull-up/pull down 
 *   enable, data inversion value.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _GPIO_DEF_H
#define _GPIO_DEF_H

#ifndef NULL
#define NULL           0
#endif


#define MODE_0		0x0
#define MODE_1		0x1
#define MODE_2		0x2
#define MODE_3		0x3
#define MODE_4		0x4
#define MODE_5		0x5
#define MODE_6		0x6
#define MODE_7		0x7
#define MODE_8		0x8
#define MODE_9		0x9
#define MODE_A		0xA
#define MODE_B		0xB
#define MODE_C		0xC
#define MODE_D		0xD
#define MODE_E		0xE
#define MODE_F		0xF

#define MODE_NC		0

#define	DIR_NULL		  1
#define	DIR_INPUT		  0
#define	DIR_OUTPUT		1

#define PULL_NULL       1
#define	PULL_DISABLE	0
#define	PULL_ENABLE		1

#define	INV_NULL	    0
#define	INV_DISABLE	  0
#define	INV_ENABLE		1

#define GPIO_CLK0 0
#define GPIO_CLK1 1
#define GPIO_CLK2 2
#define GPIO_CLK3 3
#define GPIO_CLK4 4
#define GPIO_CLK5 5
#define GPIO_CLK6 6
#define GPIO_CLK7 7
#define GPIO_CLK8 8
#define GPIO_CLK9 9
#define GPIO_CLK10 10
#define GPIO_CLK11 11

#define DCT_none_clk 0



#define GPIO_PORTNULL_MODE  0
#define GPO_PORTNULL_MODE  0
#define GPIO_PORTNULL_DIR   0
#define GPIO_PORTNULL_PULL  0
#define GPIO_PORTNULL_INV   0
#define GPIO_PORTNULL_OUTPUT_LEVEL  0
#define GPO_PORTNULL_OUTPUT_LEVEL  0
#define GPIO_PORTNULL_PULL_SEL  0
#define GPIO_PORTNULL_R0    0
#define GPIO_PORTNULL_R1    0
#define GPIO_PORTNULL_PUPD  0
#define GPIO_PORTNULL_DOUT  0
#define GPIO_PORTNULL_OE    0



#define MODE0_GPIONULL     0
#define MODE1_GPIONULL     0
#define MODE2_GPIONULL     0
#define MODE3_GPIONULL     0
#define MODE4_GPIONULL     0
#define MODE5_GPIONULL     0
#define MODE6_GPIONULL     0
#define MODE7_GPIONULL     0
#define MODE8_GPIONULL     0
#define MODE9_GPIONULL     0
#define MODE10_GPIONULL    0
#define MODE11_GPIONULL    0



#define DIR_OUT_GPIONULL   0
#define DIR_IN_GPIONULL   0




#define  GPIO_PORTNULL_ADIE_MODE     0
#define  GPIO_PORTNULL_ADIE_DIR      0
#define  GPIO_PORTNULL_ADIE_OUTPUT_LEVEL     0








#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#endif /* _GPIO_DEF_H */
