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
 *    lcd_at_cmd.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for the AT-command of LCD driver.
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#if defined(LQT_SUPPORT)

#ifndef _LCD_LQT_H
#define _LCD_LQT_H

typedef enum{
	LCD_AT_RELEASE_MODE=0,
	LCD_AT_LQT_MODE
} LCD_AT_mode;

typedef enum{
	Gamma=0,
	Flicker,
	Release,
	TEARING,
	LCM_REG_READ,
	LCM_RAM_READ,
	LCM_REG_WRITE
} LCD_LQT_mode;


#endif/*_LCD_LQT_H*/
#endif/*LQT_SUPPORT*/

