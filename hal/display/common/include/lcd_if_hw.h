/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001-2007
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
 * lcd_if.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for LCD interface driver.
 *
 * Author:
 * -------
 * -------
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 01 21 2014 edwardyc.lin
 * removed!
 *
 * 01 21 2014 edwardyc.lin
 * removed!
 *
 * 11 12 2012 joey.pan
 * removed!
 * Fix MT6260 LCD build error.
 *
 * 03 22 2012 xiaoyong.ye
 * removed!
 * Fix build error.
 *
 * 10 27 2011 dong.guo
 * removed!
 * MT6255 DDv2 check in .
 *
 * 07 28 2011 bin.han
 * removed!
 * .
 *
 * 07 27 2011 tianshu.qiu
 * removed!
 * .
 *
 * 03 30 2011 chelun.tsai
 * removed!
 * lcd_if_hw.h move to HAL.
 *
 * 03 08 2011 bin.han
 * removed!
 * .MT6256 LCD driver code first check in
 *
 * 02 10 2011 chelun.tsai
 * removed!
 * modify drv_features.h include.
 *
 * 01 07 2011 sophie.chen
 * removed!
 * .
 *
 * 12 23 2010 tianshu.qiu
 * removed!
 * .
 *
 * 12 17 2010 chelun.tsai
 * removed!
 * solve RHR check in error.
 *
 * 11 23 2010 chelun.tsai
 * removed!
 * .
 *
 * 11 17 2010 tristan.su
 * removed!
 * Remove MT6253D chip option.
 *
 * 11 09 2010 tristan.su
 * removed!
 * MT6252 lcd driver check in.
 *
 * 10 18 2010 tristan.su
 * removed!
 * .
 *
 * 09 13 2010 sophie.chen
 * removed!
 * .
 *
 * 09 13 2010 sophie.chen
 * removed!
 * .
 *
 * 09 10 2010 tristan.su
 * removed!
 * .
 *
 * 08 16 2010 tristan.su
 * removed!
 * .
 *
 * 07 26 2010 jing.li
 * removed!
 * MoDIS 2008
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * MT6268 check in
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 * 
 *
 *
 *
 *******************************************************************************/
#ifndef __LCD_IF_HW_H__
#define __LCD_IF_HW_H__

#ifdef FPGA
#include "lcd_feature.h" 
#include "typedefs.h"
#include "drv_features_display.h"
#include "drv_sw_features_display.h"
#else //ON_FPGA
//RHR #include "kal_release.h"
//RHR #include "drv_features.h"
#include "kal_general_types.h"
#endif //ON_FPGA
#include "reg_base.h"
#include "mm_power_ctrl.h" //mainly for avoid LCM build error (direct RDN access)

   #if (defined(MT6219))
      #include "lcd_if_6219_series_hw.h"      
   #elif (defined(MT6217)||defined(MT6223)||defined(MT6223P))   
      #include "lcd_if_6217_series_hw.h"            
   #elif (defined(MT6225)||defined(MT6226)||defined(MT6226M)||defined(MT6227)||defined(MT6227D)||defined(MT6226D))   
     #include "lcd_if_6225_series_hw.h"                  
   #elif (defined(MT6228)||defined(MT6229)||defined(MT6230)||defined(MT6268T)||defined(MT6268H))   
     #include "lcd_if_6228_series_hw.h"                        
   #elif (defined(MT6238)||defined(MT6239)||defined(MT6270A))   
     #include "lcd_if_6238_series_hw.h"
   #elif (defined(MT6268A)||defined(MT6268))   
     #include "lcd_if_6268_series_hw.h"
   #elif (defined(MT6235)||defined(MT6235B))   
     #include "lcd_if_6235_series_hw.h"                               
   #elif (defined(MT6253T)||defined(MT6253)) 
     #include "lcd_if_6253_series_hw.h"                              
   #elif (defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H)) 
     #include "lcd_if_6252_series_hw.h"
   #elif (defined(MT6236) || defined(MT6236B))
     #include "lcd_if_6236_series_hw.h" 
   #elif (defined(MT6276))
     #include "lcd_if_6276_series_hw.h"
   #elif (defined(MT6256))
     #include "lcd_if_6256_series_hw.h"
   #elif (defined(MT6255))
     #include "lcd_if_6255_series_hw.h"
   #elif defined(MT6251)
     #include "lcd_if_6251_series_hw.h"
   #elif defined(MT6250)
     #include "lcd_if_6250_series_hw.h"
   #elif defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
     #include "lcd_if_6260_series_hw.h"
   #elif (defined(TK6516)||defined(MT6516)||defined(MT6573))
     #include "lcd_if_windows_series_hw.h"                                   
   #else
      #error not support chip
   #endif

extern volatile kal_uint32 lcd_hw_trigger_para[LCD_CMD_QUEUE_LENGTH];//RHR
   
#ifdef TV_OUT_SUPPORT
extern volatile kal_uint32 lcd_cmq_para[LCD_CMD_QUEUE_LENGTH];//RHR
#endif
                                                                                        
#endif //__LCD_IF_HW_H__
