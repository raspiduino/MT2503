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
 *  ImgViewerSkin.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Skin definition of Imageviewer App.
 *
 * Author:
 * -------
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
 ****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "wgui.h"
#include "ImgviewCui.h"
#include "ImgviewerConfig.h"

#ifdef __MMI_IVF_OSD__
#ifndef __MMI_FTE_SUPPORT__
const iv_icon_t iv_skin_0[IV_ICON_COUNT] =
{
#if ( (LCD_WIDTH == 128) && (LCD_HEIGHT == 128) || (LCD_WIDTH == 128) && (LCD_HEIGHT == 160) )
#ifdef __MMI_IVF_OSD_PANEL__

    {0, 0, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {0, 0, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    {0, 0, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    {0, 0, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* DUMMY VALUE, NOT READY */
    {  6, LCD_HEIGHT-20, KEY_LSK},    /* left softkey */
    {102, LCD_HEIGHT-20, KEY_RSK},  /* right softkey */ 

#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
#ifdef __MMI_IVF_OSD_PANEL__

    {134, LCD_HEIGHT-44, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    { 93, LCD_HEIGHT-44, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    { 52, LCD_HEIGHT-44, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    { 11, LCD_HEIGHT-44, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* SK: DUMMY VALUE, NOT READY */
    {  6, LCD_HEIGHT-24, KEY_LSK},    /* left softkey */
    {150, LCD_HEIGHT-24, KEY_RSK},  /* right softkey */ 

#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) || (LCD_WIDTH == 240) && (LCD_HEIGHT == 400) )
#ifdef __MMI_IVF_OSD_PANEL__

    {183, LCD_HEIGHT-51, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {127, LCD_HEIGHT-51, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    { 71, LCD_HEIGHT-51, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    { 15, LCD_HEIGHT-51, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* SK: DUMMY VALUE, NOT READY */
    {  6, LCD_HEIGHT-16, KEY_LSK},    /* left softkey */
    {203, LCD_HEIGHT-16, KEY_RSK},  /* right softkey */ 
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 240) )
	#ifdef __MMI_IVF_OSD_PANEL__

	    {183, LCD_HEIGHT-51, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
	    {127, LCD_HEIGHT-51, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
	    { 71, LCD_HEIGHT-51, CUI_IV_KEY_CWR},    /* clockwise rotate */         
	    { 15, LCD_HEIGHT-51, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
	#endif /* __MMI_IVF_OSD_PANEL__ */
	    /* SK: DUMMY VALUE, NOT READY */
	    {  6, LCD_HEIGHT-16, KEY_LSK},    /* left softkey */
	    {203, LCD_HEIGHT-16, KEY_RSK},  /* right softkey */ 

#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
#ifdef __MMI_IVF_OSD_PANEL__

    {236, 185, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {171, 185, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    {106, 185, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    { 41, 185, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* DUMMY VALUE, NOT READY */
    {  8, LCD_HEIGHT-16, KEY_LSK},    /* left softkey */
    {281, LCD_HEIGHT-16, KEY_RSK},  /* right softkey */ 

#elif (( (LCD_WIDTH == 320) && (LCD_HEIGHT == 480) ) || ( (LCD_WIDTH == 360) && (LCD_HEIGHT == 640) )  || ( (LCD_WIDTH == 480) && (LCD_HEIGHT == 800) ))
#ifdef __MMI_IVF_OSD_PANEL__

    {245, LCD_HEIGHT-55, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {179, LCD_HEIGHT-55, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    { 86, LCD_HEIGHT-55, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    { 19, LCD_HEIGHT-55, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* DUMMY VALUE, NOT READY */
    {  6, LCD_HEIGHT-16, KEY_LSK},    /* left softkey */
    {275, LCD_HEIGHT-16, KEY_RSK},  /* right softkey */ 

#elif ( (LCD_WIDTH == 96) && (LCD_HEIGHT == 64) )
#ifdef __MMI_IVF_OSD_PANEL__

    {0, 0, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {0, 0, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    {0, 0, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    {0, 0, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* SK: DUMMY VALUE, NOT READY */
    { 6, LCD_HEIGHT-20, KEY_LSK},    /* left softkey */
    {70, LCD_HEIGHT-20, KEY_RSK},  /* right softkey */ 
    
#else
#error "[Image viewer]Please add new layout configuration according to new LCD resolution"
#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
};

const iv_icon_t iv_skin_270[IV_ICON_COUNT] =
{
#if ( (LCD_WIDTH == 128) && (LCD_HEIGHT == 128) || (LCD_WIDTH == 128) && (LCD_HEIGHT == 160) )
#ifdef __MMI_IVF_OSD_PANEL__

    {0, 0, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {0, 0, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    {0, 0, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    {0, 0, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* DUMMY VALUE, NOT READY */
    {  6, LCD_HEIGHT-20, KEY_LSK},    /* left softkey */
    {102, LCD_HEIGHT-20, KEY_RSK},  /* right softkey */ 

#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
#ifdef __MMI_IVF_OSD_PANEL__

    {156, 148, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {115, 148, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    { 74, 148, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    { 33, 148, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* SK: DUMMY VALUE, NOT READY */
    {  0, 0, KEY_LSK},    /* left softkey */
    {150, 0, KEY_RSK},  /* right softkey */ 

#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
#ifdef __MMI_IVF_OSD_PANEL__

    {225, 206, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {169, 206, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    {113, 206, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    { 57, 206, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* SK: DUMMY VALUE, NOT READY */
    {  0, 0, KEY_LSK},    /* left softkey */
    {203, 0, KEY_RSK},  /* right softkey */ 

#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 400) )
#ifdef __MMI_IVF_OSD_PANEL__

    {284, 210, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {214, 210, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    {144, 210, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    { 73, 210, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* SK: DUMMY VALUE, NOT READY */
    {  0, 0, KEY_LSK},    /* left softkey */
    {203, 0, KEY_RSK},  /* right softkey */ 

#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 240) )
	#ifdef __MMI_IVF_OSD_PANEL__

	    {225, 206, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
	    {169, 206, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
	    {113, 206, CUI_IV_KEY_CWR},    /* clockwise rotate */         
	    { 57, 206, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
	#endif /* __MMI_IVF_OSD_PANEL__ */
	    /* SK: DUMMY VALUE, NOT READY */
	    {  0, 0, KEY_LSK},    /* left softkey */
	    {203, 0, KEY_RSK},  /* right softkey */ 
#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
#ifdef __MMI_IVF_OSD_PANEL__

    {178, 289,CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {122, 289,CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    { 66, 289,CUI_IV_KEY_CWR},    /* clockwise rotate */         
    { 10, 289,CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* DUMMY VALUE, NOT READY */
    {  0, 0, KEY_LSK},    /* left softkey */
    {220, 0, KEY_RSK},  /* right softkey */ 

#elif (( (LCD_WIDTH == 320) && (LCD_HEIGHT == 480) ) || ( (LCD_WIDTH == 360) && (LCD_HEIGHT == 640) )  || ( (LCD_WIDTH == 480) && (LCD_HEIGHT == 800) ))
#ifdef __MMI_IVF_OSD_PANEL__

    {245, LCD_WIDTH-28, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {179, LCD_WIDTH-28, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    { 86, LCD_WIDTH-28, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    { 19, LCD_WIDTH-28, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* DUMMY VALUE, NOT READY */
    {  0, 0, KEY_LSK},    /* left softkey */
    {LCD_HEIGHT-28, 0, KEY_RSK},  /* right softkey */ 

#elif ( (LCD_WIDTH == 96) && (LCD_HEIGHT == 64) )
#ifdef __MMI_IVF_OSD_PANEL__

    {0, 0, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {0, 0, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    {0, 0, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    {0, 0, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* SK: DUMMY VALUE, NOT READY */
    { 6, LCD_HEIGHT-20, KEY_LSK},    /* left softkey */
    {70, LCD_HEIGHT-20, KEY_RSK},  /* right softkey */ 
    
#else
#error "[Image viewer]Please add new layout configuration according to new LCD resolution"
#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
};

#else /* __FTE_SUPPORT__ */

const iv_icon_t iv_skin_0[IV_ICON_COUNT] =
{
#if ( (LCD_WIDTH == 128) && (LCD_HEIGHT == 128) || (LCD_WIDTH == 128) && (LCD_HEIGHT == 160) )
#ifdef __MMI_IVF_OSD_PANEL__

    {0, LCD_HEIGHT-10-MMI_SOFTKEY_HEIGHT, 23, 10, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {0, LCD_HEIGHT-10-MMI_SOFTKEY_HEIGHT, 23, 10, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    {0, LCD_HEIGHT-10-MMI_SOFTKEY_HEIGHT, 23, 10, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    {0, LCD_HEIGHT-10-MMI_SOFTKEY_HEIGHT, 23, 10, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* DUMMY VALUE, NOT READY */
    {  6, LCD_HEIGHT-20, 40, 20, KEY_LSK},    /* left softkey */
    {102, LCD_HEIGHT-20, 40, 20, KEY_RSK},  /* right softkey */ 

#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
#ifdef __MMI_IVF_OSD_PANEL__

    {134, LCD_HEIGHT-15-MMI_SOFTKEY_HEIGHT, 31, 15, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    { 93, LCD_HEIGHT-15-MMI_SOFTKEY_HEIGHT, 31, 15, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    { 52, LCD_HEIGHT-15-MMI_SOFTKEY_HEIGHT, 31, 15, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    { 11, LCD_HEIGHT-15-MMI_SOFTKEY_HEIGHT, 31, 15, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* SK: DUMMY VALUE, NOT READY */
    {  6, LCD_HEIGHT-24, 40, 20, KEY_LSK},    /* left softkey */
    {150, LCD_HEIGHT-24, 40, 20, KEY_RSK},  /* right softkey */ 

#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
#ifdef __MMI_IVF_OSD_PANEL__

    {182, LCD_HEIGHT-31-MMI_SOFTKEY_HEIGHT, 58, 31, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {121, LCD_HEIGHT-31-MMI_SOFTKEY_HEIGHT, 59, 31, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    { 60, LCD_HEIGHT-31-MMI_SOFTKEY_HEIGHT, 59, 31, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    {  0, LCD_HEIGHT-31-MMI_SOFTKEY_HEIGHT, 58, 31, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* SK: DUMMY VALUE, NOT READY */
    {  6, LCD_HEIGHT-16, 40, 20, KEY_LSK},    /* left softkey */
    {203, LCD_HEIGHT-16, 40, 20, KEY_RSK},  /* right softkey */ 

#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 400) )
#ifdef __MMI_IVF_OSD_PANEL__

    {182, LCD_HEIGHT-31-MMI_SOFTKEY_HEIGHT, 58, 31, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {121, LCD_HEIGHT-31-MMI_SOFTKEY_HEIGHT, 59, 31, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    { 60, LCD_HEIGHT-31-MMI_SOFTKEY_HEIGHT, 59, 31, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    {  0, LCD_HEIGHT-31-MMI_SOFTKEY_HEIGHT, 58, 31, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* SK: DUMMY VALUE, NOT READY */
    {  6, LCD_HEIGHT-16, 40, 20, KEY_LSK},    /* left softkey */
    {203, LCD_HEIGHT-16, 40, 20, KEY_RSK},  /* right softkey */ 
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 240) )
	#ifdef __MMI_IVF_OSD_PANEL__

	    {182, LCD_HEIGHT-31-MMI_SOFTKEY_HEIGHT, 58, 31, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
	    {121, LCD_HEIGHT-31-MMI_SOFTKEY_HEIGHT, 59, 31, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
	    { 60, LCD_HEIGHT-31-MMI_SOFTKEY_HEIGHT, 59, 31, CUI_IV_KEY_CWR},    /* clockwise rotate */         
	    {  0, LCD_HEIGHT-31-MMI_SOFTKEY_HEIGHT, 58, 31, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
	#endif /* __MMI_IVF_OSD_PANEL__ */
	    /* SK: DUMMY VALUE, NOT READY */
	    {  6, LCD_HEIGHT-16, 40, 20, KEY_LSK},    /* left softkey */
	    {203, LCD_HEIGHT-16, 40, 20, KEY_RSK},  /* right softkey */ 

#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
#ifdef __MMI_IVF_OSD_PANEL__

    {242, LCD_HEIGHT-40-MMI_SOFTKEY_HEIGHT, 78, 40, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {161, LCD_HEIGHT-40-MMI_SOFTKEY_HEIGHT, 79, 40, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    { 80, LCD_HEIGHT-40-MMI_SOFTKEY_HEIGHT, 79, 40, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    {  0, LCD_HEIGHT-40-MMI_SOFTKEY_HEIGHT, 78, 40, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* DUMMY VALUE, NOT READY */
    {  8, LCD_HEIGHT-16, 40, 20, KEY_LSK},    /* left softkey */
    {281, LCD_HEIGHT-16, 40, 20, KEY_RSK},  /* right softkey */ 

#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 480) )
#ifdef __MMI_IVF_OSD_PANEL__

    {242, LCD_HEIGHT-47-MMI_SOFTKEY_HEIGHT, 78, 47, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {161, LCD_HEIGHT-47-MMI_SOFTKEY_HEIGHT, 79, 47, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    { 80, LCD_HEIGHT-47-MMI_SOFTKEY_HEIGHT, 79, 47, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    {  0, LCD_HEIGHT-47-MMI_SOFTKEY_HEIGHT, 78, 47, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* DUMMY VALUE, NOT READY */
    {  8, LCD_HEIGHT-16, 40, 20, KEY_LSK},    /* left softkey */
    {281, LCD_HEIGHT-16, 40, 20, KEY_RSK},  /* right softkey */ 

#elif (( (LCD_WIDTH == 360) && (LCD_HEIGHT == 640) )  || ( (LCD_WIDTH == 480) && (LCD_HEIGHT == 800) ))
#ifdef __MMI_IVF_OSD_PANEL__

    {245, LCD_HEIGHT-21-MMI_SOFTKEY_HEIGHT, 43, 21, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {179, LCD_HEIGHT-21-MMI_SOFTKEY_HEIGHT, 43, 21, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    { 86, LCD_HEIGHT-21-MMI_SOFTKEY_HEIGHT, 43, 21, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    { 19, LCD_HEIGHT-21-MMI_SOFTKEY_HEIGHT, 43, 21, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* DUMMY VALUE, NOT READY */
    {  6, LCD_HEIGHT-16, 40, 20, KEY_LSK},    /* left softkey */
    {275, LCD_HEIGHT-16, 40, 20, KEY_RSK},  /* right softkey */ 

#elif ( (LCD_WIDTH == 96) && (LCD_HEIGHT == 64) )
#ifdef __MMI_IVF_OSD_PANEL__
	
		{134, LCD_HEIGHT-15-MMI_SOFTKEY_HEIGHT, 31, 15, CUI_IV_KEY_ZOOMIN},   /* zoom in */ 			   
		{ 93, LCD_HEIGHT-15-MMI_SOFTKEY_HEIGHT, 31, 15, CUI_IV_KEY_ZOOMOUT},   /* zoom out */			   
		{ 52, LCD_HEIGHT-15-MMI_SOFTKEY_HEIGHT, 31, 15, CUI_IV_KEY_CWR},	/* clockwise rotate */		   
		{ 11, LCD_HEIGHT-15-MMI_SOFTKEY_HEIGHT, 31, 15, CUI_IV_KEY_CCWR},	  /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
		/* SK: DUMMY VALUE, NOT READY */
		{  6, LCD_HEIGHT-24, 40, 20, KEY_LSK},	  /* left softkey */
		{70, LCD_HEIGHT-24, 40, 20, KEY_RSK},	/* right softkey */ 


#else
#error "[Image viewer]Please add new layout configuration according to new LCD resolution"
#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
};

const iv_icon_t iv_skin_270[IV_ICON_COUNT] =
{
#if ( (LCD_WIDTH == 128) && (LCD_HEIGHT == 128) || (LCD_WIDTH == 128) && (LCD_HEIGHT == 160) )
#ifdef __MMI_IVF_OSD_PANEL__

    {0, 0, 23, 10, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {0, 0, 23, 10, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    {0, 0, 23, 10, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    {0, 0, 23, 10, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* DUMMY VALUE, NOT READY */
    {  6, LCD_HEIGHT-20, 40, 20, KEY_LSK},    /* left softkey */
    {102, LCD_HEIGHT-20, 40, 20, KEY_RSK},  /* right softkey */ 

#elif ( (LCD_WIDTH == 176) && (LCD_HEIGHT == 220) )
#ifdef __MMI_IVF_OSD_PANEL__

    {156, 148, 31, 15, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {115, 148, 31, 15, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    { 74, 148, 31, 15, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    { 33, 148, 31, 15, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* SK: DUMMY VALUE, NOT READY */
    {  0, 0, 40, 20, KEY_LSK},    /* left softkey */
    {150, 0, 40, 20, KEY_RSK},  /* right softkey */ 

#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 320) )
#ifdef __MMI_IVF_OSD_PANEL__

    {222, 203, 59, 31, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {161, 203, 59, 31, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    {100, 203, 59, 31, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    { 39, 203, 59, 31, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* SK: DUMMY VALUE, NOT READY */
    {  0, 0, 40, 20, KEY_LSK},    /* left softkey */
    {203, 0, 40, 20, KEY_RSK},  /* right softkey */ 

#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 400) )
#ifdef __MMI_IVF_OSD_PANEL__

    {262, 205, 59, 31, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {201, 205, 59, 31, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    {140, 205, 59, 31, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    { 79, 205, 59, 31, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* SK: DUMMY VALUE, NOT READY */
    {  0, 0, 40, 20, KEY_LSK},    /* left softkey */
    {203, 0, 40, 20, KEY_RSK},  /* right softkey */ 
#elif ( (LCD_WIDTH == 240) && (LCD_HEIGHT == 240) )
	#ifdef __MMI_IVF_OSD_PANEL__

	    {222, 203, 59, 31, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
	    {161, 203, 59, 31, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
	    {100, 203, 59, 31, CUI_IV_KEY_CWR},    /* clockwise rotate */         
	    { 39, 203, 59, 31, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
	#endif /* __MMI_IVF_OSD_PANEL__ */
	    /* SK: DUMMY VALUE, NOT READY */
	    {  0, 0, 40, 20, KEY_LSK},    /* left softkey */
	    {203, 0, 40, 20, KEY_RSK},  /* right softkey */ 


#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 240) )
#ifdef __MMI_IVF_OSD_PANEL__

    {182, 274, 58, 40, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {121, 274, 59, 40, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    { 60, 274, 59, 40, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    {  0, 274, 58, 40, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* DUMMY VALUE, NOT READY */
    {  0, 0, 40, 20, KEY_LSK},    /* left softkey */
    {220, 0, 40, 20, KEY_RSK},  /* right softkey */ 

#elif ( (LCD_WIDTH == 320) && (LCD_HEIGHT == 480) )
#ifdef __MMI_IVF_OSD_PANEL__

    {322, 266, 79, 47, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {241, 266, 79, 47, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    {160, 266, 79, 47, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    { 79, 266, 79, 47, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* DUMMY VALUE, NOT READY */
    {  0, 0, 40, 20, KEY_LSK},    /* left softkey */
    {220, 0, 40, 20, KEY_RSK},  /* right softkey */ 

#elif ( ( (LCD_WIDTH == 360) && (LCD_HEIGHT == 640) )  || ( (LCD_WIDTH == 480) && (LCD_HEIGHT == 800) ))
#ifdef __MMI_IVF_OSD_PANEL__

    {245, LCD_WIDTH-28, 43, 21, CUI_IV_KEY_ZOOMIN},   /* zoom in */                
    {179, LCD_WIDTH-28, 43, 21, CUI_IV_KEY_ZOOMOUT},   /* zoom out */              
    { 86, LCD_WIDTH-28, 43, 21, CUI_IV_KEY_CWR},    /* clockwise rotate */         
    { 19, LCD_WIDTH-28, 43, 21, CUI_IV_KEY_CCWR},     /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
    /* DUMMY VALUE, NOT READY */
    {  0, 0, 40, 20, KEY_LSK},    /* left softkey */
    {LCD_HEIGHT-28, 0, 40, 20, KEY_RSK},  /* right softkey */ 

#elif ( (LCD_WIDTH == 96) && (LCD_HEIGHT == 64) )
#ifdef __MMI_IVF_OSD_PANEL__
		
			{134, LCD_HEIGHT-15-MMI_SOFTKEY_HEIGHT, 31, 15, CUI_IV_KEY_ZOOMIN},   /* zoom in */ 			   
			{ 93, LCD_HEIGHT-15-MMI_SOFTKEY_HEIGHT, 31, 15, CUI_IV_KEY_ZOOMOUT},   /* zoom out */			   
			{ 52, LCD_HEIGHT-15-MMI_SOFTKEY_HEIGHT, 31, 15, CUI_IV_KEY_CWR},	/* clockwise rotate */		   
			{ 11, LCD_HEIGHT-15-MMI_SOFTKEY_HEIGHT, 31, 15, CUI_IV_KEY_CCWR},	  /* counterclockwise rotate */
#endif /* __MMI_IVF_OSD_PANEL__ */
			/* SK: DUMMY VALUE, NOT READY */
			{  6, LCD_HEIGHT-24, 40, 20, KEY_LSK},	  /* left softkey */
			{70, LCD_HEIGHT-24, 40, 20, KEY_RSK},	/* right softkey */ 


#else
#error "[Image viewer]Please add new layout configuration according to new LCD resolution"
#endif /* (LCD_WIDTH == XXX && LCD_HEIGHT == xxx) */
};
#endif /* __FTE_SUPPORT__ */


const iv_panel_t iv_panel_0 = 
{
    IV_PANEL_H,     /* Panel height */ 
    sizeof(iv_skin_0) / sizeof(iv_icon_t),
    iv_skin_0
};

const iv_panel_t iv_panel_270 = 
{
    IV_PANEL_ICON_BAR_H,     /* Panel height */ 
    sizeof(iv_skin_270) / sizeof(iv_icon_t),
    iv_skin_270
};
#endif /*__MMI_IVF_OSD__*/
