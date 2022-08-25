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
 *  BarcodeReaderOP01Prots.h.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Barcode Reader OP01 Prots.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_BARCODEREADER_OP01_PROT_H
#define MMI_BARCODEREADER_OP01_PROT_H

extern void mmi_barcodereader_init_op01_app(void);

extern void mmi_barcodereader_highlight_app(void);
extern void mmi_barcodereader_hilight_bookmark_open(void);
extern void mmi_barcodereader_hilight_bookmark_rename(void);
extern void mmi_barcodereader_hilight_bookmark_delete(void);
extern void mmi_barcodereader_hilight_bookmark_delall(void);
extern void mmi_barcodereader_hilight_bookmark_done(void);
extern void mmi_barcodereader_hilight_bookmark_methord(void);

#ifdef  __MMI_BARCODEREADER_LOW_LEVEL
    extern void mmi_barcodereader_hilight_bookmark_open(void);
    extern void mmi_barcodereader_hilight_bookmark_rename(void);
    extern void mmi_barcodereader_hilight_bookmark_delete(void);
    extern void mmi_barcodereader_hilight_bookmark_delall(void);
    extern void mmi_barcodereader_hilight_bookmark_done(void);
    extern void mmi_barcodereader_hilight_bookmark_methord(void);
#else
    extern void mmi_barcodereader_hilight_edit_by_sms(void);
    extern void mmi_barcodereader_hilight_save(void);
    extern void mmi_barcodereader_hilight_preview(void);
    extern void mmi_barcodereader_hilight_save_to_phonebook(void);
    extern void mmi_barcodereader_hilight_edit_by_mms(void);
    extern void mmi_barcodereader_hilight_send_by_email(void);
    extern void mmi_barcodereader_hilight_open_url(void);
    extern void mmi_barcodereader_hilight_save_url(void);
    extern void mmi_barcodereader_hilight_to_commend(void);
    extern void mmi_barcodereader_hilight_order(void);
    extern void mmi_barcodereader_hilight_make_call(void);
    extern void mmi_barcodereader_hilight_enter_from_filelist_to_app_preview(void);
    extern void mmi_barcodereader_hilight_enter_open_position(void);
#endif

#endif /* MMI_BARCODEREADER_OP01_PROT_H */ 

