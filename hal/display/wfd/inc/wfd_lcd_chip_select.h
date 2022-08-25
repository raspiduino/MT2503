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
 *    drv_features_chip_selsect.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is merged for all driver features.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 03 07 2014 edwardyc.lin
 * removed!
 * 	.
 *
 * 01 21 2014 edwardyc.lin
 * removed!
 *
 * 11 12 2012 joey.pan
 * removed!
 * Fix MT6260 LCD build error.
 *
 * 03 20 2012 xiaoyong.ye
 * removed!
 * MT6250 display driver check in.
 *
 * 10 27 2011 dong.guo
 * removed!
 * MT6255 DDv2 check in .
 *
 * 09 13 2011 dong.guo
 * removed!
 * .
 *
 * 07 26 2011 zifeng.qiu
 * removed!
 *   DDv2 On Modis Check In.
 *
 * 03 08 2011 bin.han
 * removed!
 * .
 *
 * 01 26 2011 matthew.chen
 * removed!
 * Fix MT6256 daily build error
 *
 * 01 07 2011 sophie.chen
 * removed!
 * .
 *
 * 12 30 2010 chelun.tsai
 * removed!
 * remove MT6253D.
 *
 * 12 23 2010 chelun.tsai
 * removed!
 * DDv2.
 *
 * 11 23 2010 sophie.chen
 * removed!
 * .
 *
 * 11 15 2010 sophie.chen
 * removed!
 * .
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClaseCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#ifndef __WFD_LCD_CHIP_SELECT_H__
#define __WFD_LCD_CHIP_SELECT_H__

#if defined(__MTK_TARGET__)

#if defined(MT6268) || defined(MT6268T) || defined(MT6268H) || defined(MT6268A)
   #include "wfd\inc\hw_6268\wfd_lcd_6268.h"
   /*Above is MT6268T*/
#elif defined(MT6235) || defined(MT6235B)
   #include "wfd\inc\hw_6235\wfd_lcd_6235.h"
   /*Above is MT6235*/   
#elif defined(MT6236) || defined(MT6236B)
   #include "wfd\inc\hw_6236\wfd_lcd_6236.h"
   /*Above is MT6236*/   
#elif defined(TK6516)
   //#include "wfd\inc\hw_tk6516\wfd_lcd_tk6516.h"
   /*Above is TK6516*/
#elif defined(MT6516)
   //#include "wfd\inc\hw_6516\wfd_lcd_6516.h"
   /*Above is MT6516*/
#elif defined(MT6253)
   #include "wfd\inc\hw_6253\wfd_lcd_6253.h"
   /* Above is MT6253T */
#elif defined(MT6252) || defined(MT6252H) || defined(MT6253E) || defined(MT6253L)
   #include "wfd\inc\hw_6252\wfd_lcd_6252.h"
   /* Above is MT6252 */
#elif defined(MT6270A)
   //#include "wfd_lcd_6270A.h"
   /* Above is MT6270A */
#elif defined(MT6276)
   #include "wfd\inc\hw_6276\wfd_lcd_6276.h"
   /* Above is MT6276 and MT6256 */
#elif defined(MT6256)
   #include "wfd\inc\hw_6256\wfd_lcd_6256.h"
   /* Above is MT6256*/
#elif defined(MT6255)
   #include "wfd\inc\hw_6255\wfd_lcd_6255.h"
   /* Above is MT6255*/
#elif defined(MT6250)
   #include "wfd\inc\hw_6250\wfd_lcd_6250.h"
   /* Above is MT6250*/
#elif defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   #include "wfd\inc\hw_6260\wfd_lcd_6260.h"
   /* Above is MT6260, MT6261, MT2501, MT2502*/
#else
   #error "The chip type is non-supported"
#endif   /*End of all chips*/

/*For Modis*/
#else    /*#if defined(__MTK_TARGET__)*/

   #include "wfd\inc\modis_lcd\wfd_lcd_modis.h"

#endif   /*#if defined(__MTK_TARGET__)*/

#endif   /*End __WFD_LCD_CHIP_SELECT_H__*/
