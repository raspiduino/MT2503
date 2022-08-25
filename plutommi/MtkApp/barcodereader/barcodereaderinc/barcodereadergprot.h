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
 *  BarcodeReaderGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  QR Code Reader Applications v0.1
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#ifndef BARCODEREADER_GPROT_H
#define BARCODEREADER_GPROT_H

#ifdef __MMI_BARCODEREADER__
#include "mmi_features_barcodereader.h"
#ifdef __MMI_OP11_BARCODEREADER__
/* under construction !*/
#endif

/****************************************************************************
* For Screen-Based Memmory (for OSD and Hint)
*****************************************************************************/
#define BR_OSD_BUFFER_SIZE      ((GDI_LCD_WIDTH*GDI_LCD_HEIGHT*GDI_MAINLCD_BIT_PER_PIXEL)>>3)
#define BR_SCR_OSD_SIZE         (BR_OSD_BUFFER_SIZE*2)

#define BR_SCR_TOTAL_SIZE       (BR_SCR_OSD_SIZE)
/****************************************************************************
* For Application-Based Memmory (for Decoded String)
*****************************************************************************/
#define BR_VERSION_CHARACTER_NUMBER     (653)
#define BR_VERSION_ONE_SLOT_BUFFER_SIZE ((BR_VERSION_CHARACTER_NUMBER+1)*ENCODING_LENGTH)
#define BR_VERSION_NODE_COUNT           (16)
#define BR_TEXT_BUFFER_SIZE             (BR_VERSION_ONE_SLOT_BUFFER_SIZE * BR_VERSION_NODE_COUNT)

#define BR_APP_WORKING_BUFFER_SIZE      (BR_TEXT_BUFFER_SIZE*3)
#define BR_APP_TEXT_BUFFER_SIZE         (BR_TEXT_BUFFER_SIZE*3)


/****************************************************************************
* For MultiMeida APs SCR mem reduce revise, move hint buffer from SCR memory to AP memory
*****************************************************************************/
#define BR_HINT_BUFFER_SIZE     (29*ENCODING_LENGTH)
#define BR_SCR_HINT_SIZE        (BR_HINT_BUFFER_SIZE*2)


#ifdef __MMI_OP11_BARCODEREADER__
/* under construction !*/
#else 
#define BR_APP_TOTAL_SIZE           (BR_APP_WORKING_BUFFER_SIZE+BR_APP_TEXT_BUFFER_SIZE+BR_VERSION_ONE_SLOT_BUFFER_SIZE+BR_SCR_HINT_SIZE+1024)
#endif /* __MMI_BARCODEREADER__ */

/****************************************************************************
* Extern Global Variable                                                            
*****************************************************************************/

/****************************************************************************
* Extern Global Function                                                            
*****************************************************************************/
extern void mmi_barcodereader_init_app(void);
extern void mmi_barcodereader_entry_app_screen(void);
extern void mmi_barcodereader_exit_sublcd_screen(void);
extern void mmi_barcodereader_entry_sublcd_screen(void);
#ifdef __MMI_OP01_BARCODEREADER__
/* under construction !*/
#endif

#ifdef __MMI_OP11_BARCODEREADER__
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
#endif /* __MMI_OP11_BARCODEREADER__ */ 

#if defined(__MMI_OP00_BARCODEREADER__) && defined(__MMI_FMGR_SUPPORT_DEFAULT_STORAGE__)
extern BOOL mmi_barcodereader_notify_hdlr(U32 notify_flag, void* para);
#endif

#if defined(__MMI_OP01_BARCODEREADER__) && defined(__MMI_FMGR_SUPPORT_DEFAULT_STORAGE__)
/* under construction !*/
#endif

#endif /* __MMI_BARCODEREADER__ */ /* _BARCODEREADER_GPROT_H_ */
#endif /* BARCODEREADER_GPROT_H */ 

