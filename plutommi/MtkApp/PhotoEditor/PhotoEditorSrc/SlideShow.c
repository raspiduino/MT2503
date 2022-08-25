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
 *  SlideShow.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Slide Show Applcation Source of PhotoEditor
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_include.h"
#ifdef __MMI_SLIDESHOW__

#include "nvram_data_items.h"
#include "SettingDefs.h"        /* ST_NOTIFYDURATION define */
#include "SettingProfile.h"     /* SUCCESS_TONE define */
#include "CommonScreens.h"      /* DisplayPopup() */
#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"  /* DRM support */
#endif /* __DRM_SUPPORT__ */ 
#include "FileManagerDef.h"
#include "FileManagerGProt.h"   /* file path */
#include "FileMgr.h"
#include "FileMgrStruct.h"
#include "FileMgrSrvGProt.h"
#include "Conversions.h"        /* short file name conversion */
#include "PhoneSetupGprots.h"   /* encoding type */
#include "lcd_if.h"
#include "MainMenuDef.h"
#include "lcd_sw_rnd.h"
#include "med_api.h"    /* media task camera module */
#include "mdi_datatype.h"
#include "mdi_camera.h"

#ifdef __MMI_VIDEO_PLAY_SUPPORT__
#include "mdi_video.h"  /* video */
#ifdef __MMI_SUBLCD__
#include "VdoPlyResDef.h" /* for drawing sublcd icon */
#endif
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

#include "SlideShowResDef.h"
#include "filemgrsrvgprot.h"
#include "SlideShowMem.h" /*caution : please put mdi_video.h before slideshowmem.h, for we may use some macro*/
#include "SlideShowGProt.h"
#include "SlideShow.h"
#ifdef GDI_USING_2D_ENGINE_V3
#include "gdi_2d_engine.h"
#endif

#include "MMI_features_camera.h"
#include "CameraResDef.h"      /* for camrea error string */
#include "mdi_audio.h"
#include "MessagesExDcl.h"
#include "AudioPlayerProt.h"
#include "MediaAppGProt.h"

#include "gpioInc.h"    /* LED related */

#ifdef __MMI_TVOUT__
#include "mdi_tv.h"     /* mdi tvout */
#include "WallpaperDefs.h"      /* some header for phonsetup.h */
#include "PhoneSetup.h" /* tvout display style */
#endif /* __MMI_TVOUT__ */
#include <ctype.h>

#include "gui_font_size.h"

#include "mdi_include.h"
#include "USBDeviceGprot.h"

/* cui prot */
#include "FilemgrCuiGprot.h"
#include "menucuigprot.h"
#include "inlinecuigprot.h"

#include "ScreenRotationGprot.h"
#include "mmi_rp_app_slideshow_def.h"
#include "ProfilesSrvGprot.h"

/***************************************************************************** 
* Define
*****************************************************************************/
typedef enum
{
    MMI_SLIDESHOW_POPUP_QUIT_ACTION_NONE = 0,
        MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP,
        
        MMI_SLIDESHOW_CONFIRM_SAVE_SETTING,
        MMI_SLIDESHOW_POPUP_QUIT_ACTION_ALL
}mmi_slideshow_popup_quit_action_enum;

typedef enum
{
    MMI_SLIDESHOW_FMGR_SELECT_FOLDER,
    MMI_SLIDESHOW_FMGR_SELECT_BGM_FILE,

    MMI_SLIDESHOW_FMGR_SELECT_ALL
} mmi_slideshow_fmgr_select_enum;

/***************************************************************************** 
* Global Variable
*****************************************************************************/

extern BOOL r2lMMIFlag;

/***************************************************************************** 
* Global Function
*****************************************************************************/
extern pBOOL mmi_usb_is_in_mass_storage_mode(void);
extern void mmi_usb_app_unavailable_popup(U16 stringId);
extern pBOOL mmi_usb_check_path_exported(S8 *path);


/*****************************************************************************
* Local Vairable                                                           
*****************************************************************************/

static slidshow_cntx_struct g_slidshow_cntx;


static S32 resume_index;
static S32 lcd_width = 0;
static S32 lcd_height = 0;
static S32 mmi_slideshow_horizon_button_bar_width = 0;
static S32 mmi_slideshow_normal_button_bar_height = 0;

PU8 g_slidshow_layer1_buffer;
PU8 g_slidshow_layer2_buffer;
#ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
PU8 g_slidshow_layer3_buffer;
#endif

#ifdef __MMI_TOUCH_SCREEN__
static slidshow_touch_screen_context_struct g_slidshow_touch_screen_cntx;
#endif 

S32 g_slidshow_option_bgm_hilight_index;
U8 g_slidshow_option_bgm_select_file_hilight_index;

/*****************************************************************************
* Local Function                                                           
*****************************************************************************/
/* app related */
void mmi_slidshow_hilight_app(void);
void mmi_slidshow_hilight_play(void);
void mmi_slideshow_entry_app(void);
static void mmi_slideshow_entry_app_internal(void);
static void mmi_slideshow_popup_display(MMI_ID parent_id, UI_string_type string_content, S32 type, void* user_data, 
                                        mmi_frm_screen_rotate_enum rotation);
static void mmi_slidshow_entry_select_folder(void);
MMI_BOOL mmi_slidshow_fmgr_select_result_callback(void *filepath);

static void mmi_slidshow_entry_option_screen(void);
static void mmi_slidshow_entry_play_screen(void);

static void mmi_slidshow_entry_image_display_screen(void);
static void mmi_slidshow_exit_image_display_screen(void);
static mmi_ret mmi_slideshow_end_key_proc(mmi_event_struct *evt);

static void mmi_slidshow_right_arrow_press(void);
static void mmi_slidshow_right_arrow_release(void);
static void mmi_slidshow_left_arrow_press(void);
static void mmi_slidshow_left_arrow_release(void);

static void mmi_slidshow_main_draw_osd(void);
static void mmi_slidshow_draw_softkey(U16 lsk_img, U16 rsk_img, BOOL is_clear_bg);

static void mmi_slidshow_lsk_press(void);
static void mmi_slidshow_show_press_release_softkey(void);
static void mmi_slidshow_lsk_release(void);
static void mmi_slidshow_rsk_press(void);
static void mmi_slidshow_rsk_release(void);

void mmi_slidshow_hilight_resume(void);
static void mmi_slidshow_entry_resume_screen(void);

void mmi_slidshow_hilight_setting(void);
static void mmi_slidshow_entry_setting_screen(void);
static void mmi_slidshow_exit_setting_screen(void);


void mmi_slidshow_setting_inline_done_hdlr(void);
static void mmi_slidshow_setting_screen_confirm_save(void);
static void mmi_slidshow_setting_save_confirm_no(void);

static void mmi_slidshow_entry_select_audio(void);
void mmi_slidshow_fmgr_select_audio_result_callback(void *filepath);
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
static void mmi_slidshow_entry_video_screen(void);
static void mmi_slidshow_exit_video_screen(void);
static void mmi_slidshow_play_finish_callback(MDI_RESULT result);
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
static void mmi_slidshow_reset_osd_fade(BOOL sleep);
static void mmi_slidshow_osd_fade_cyclic(void);
static void mmi_slidshow_osd_show_up(void);

static void mmi_slidshow_entry_next_file(void);
static void mmi_slidshow_apply_index_change(void);


#ifdef __MMI_SLIDSHOW_WIPE_ENABLE__
static void mmi_slidshow_effect_wipe_cyclic(void);
#endif
static void mmi_slidshow_effect_split_cyclic(void);
static void mmi_slidshow_effect_fade_in_cyclic(void);
static void mmi_slidshow_image_effect_finished(void);
static void mmi_slidshow_slice_time_out(void);

void mmi_slidshow_anim_finish_callback(GDI_RESULT result);

void mmi_slidshow_option_hilight_hdlr(S32 index);

void mmi_slidshow_hilight_entry_select(void);

void mmi_slidshow_highlight_audio_file_play(void);
void mmi_slidshow_entry_audio_file_play(void);

static void mmi_slidshow_draw_arrow_key_osd(void);
static void mmi_slidshow_right_arrow_icon_key_press(void);
static void mmi_slidshow_right_arrow_icon_key_release(void);
static void mmi_slidshow_left_arrow_icon_key_press(void);
static void mmi_slidshow_left_arrow_icon_key_release(void);

static void mmi_slidshow_vol_up(void);
static void mmi_slidshow_vol_down(void);
static void mmi_slidshow_set_keys(void);
static U8 mmi_slidshow_deleteScr_callback(void* ptr);
static void mmi_slidshow_turn_off_bl_hdlr(void);
static void mmi_slidshow_auto_next(void);

void mmi_slidshow_load_setting(void);
void mmi_slidshow_store_setting(void);

#ifdef __MMI_TVOUT__
void mmi_slidshow_draw_img_2_tv(PS8 p_filename, U16 img_id,S32 img_w, S32 img_h, BOOL anim, BOOL reset_tvout);
void mmi_slidshow_anim_blt_after_callback(GDI_RESULT result);
#endif

/* touch screen */
#ifdef __MMI_TOUCH_SCREEN__
void mmi_slidshow_pen_down_hdlr(mmi_pen_point_struct pos);
void mmi_slidshow_pen_up_hdlr(mmi_pen_point_struct pos);
void mmi_slidshow_pen_move_hdlr(mmi_pen_point_struct pos);
#endif /* __MMI_TOUCH_SCREEN__ */ 

/* draw sublcd for preventing updating sublcd while video playing on main lcd */
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
#ifdef __MMI_SUBLCD__
void mmi_slidshow_entry_sublcd_screen(void);
void mmi_slidshow_exit_sublcd_screen(void);
void mmi_slidshow_draw_sublcd_icon(void);
#endif /* __MMI_SUBLCD__ */
#endif /* __MMI_VIDEO_PLAYER */

#ifdef __DRM_SUPPORT__
static void mmi_slidshow_drm_timeup_callback(S32 result, S32 id);
#endif /* __DRM_SUPPORT__ */

BOOL mmi_slidshow_alloc_app_asm(void);
void mmi_slidshow_free_app_asm(void);
U8 mmi_slidshow_del_scr_callback();
extern void mmi_slidshow_stop_callback(void);

void mmi_slidshow_store_data(void);
void mmi_slidshow_load_data(void);
static void mmi_slidshow_exit_hdlr(void);

static void mmi_slideshow_entry_app_screen_from_other_app(void);
static void mmi_slideshow_ready_to_play(FMGR_FILTER* filter);

static void mmi_slideshow_before_enter_play_screen(void);
static void mmi_slideshow_init_fmgr_filter(FMGR_FILTER* filter, mmi_slideshow_browse_type_enum type);
static S32 slidshow_create_filelist(MMI_BOOL is_sort);
static void slidshow_free_filelist(void);

static S32 mmi_slideshow_file_sort_callback(SRV_FMGR_FILELIST_HANDLE fl_hdl, S32 result, S32 progress, S32 total);
static void mmi_slideshow_enter_sorting_screen(void);
static void mmi_slideshow_exit_sorting_screen(void);
static void mmi_slideshow_cancel_sorting_screen(void);
static void mmi_slideshow_delete_all_screen(void);

#ifdef __BT_SPK_VOL_CONTROL__
static MMI_BOOL mmi_slideshow_hfp_volume_callback(U8 volume, MMI_BOOL is_mute);
#endif
static void mmi_slideshow_get_stored_file_path(PS8 path, S32 id);
static void mmi_slideshow_save_stored_file_path(PS8 path, S32 id);
static void mmi_slideshow_entry_file_option(void);
static mmi_ret mmi_slideshow_bgm_option_menu_group_proc(mmi_event_struct *evt);
static MMI_BOOL mmi_slideshow_is_folder_used(srv_fmgr_notification_adv_action_event_struct *fmgr_act);

/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_init_app
 * DESCRIPTION
 *  init slide show applcation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_slidshow_cntx.text_color = *current_MMI_theme->title_text_color;
    g_slidshow_cntx.text_border_color = *current_MMI_theme->title_text_border_color;
    g_slidshow_cntx.audio_volume = SLIDSHOW_INIT_AUDIO_VOL;
    g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_CLOSE;
    g_slidshow_cntx.error_code = SLIDESHOW_ERR_NO_ERROR;
    g_slidshow_cntx.fmgr_service_id = 0;

    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_SLIDESHOW,
        STR_ID_SLIDSHOW_APP,
        IMG_ID_SLIDSHOW_APP,
        mmi_slidshow_stop_callback);
    g_slidshow_cntx.app_mem_bufer = NULL;
    g_slidshow_cntx.audio_file_path = NULL;
    g_slidshow_cntx.tmp_file_path = NULL;
    g_slidshow_layer1_buffer = NULL;
    g_slidshow_layer2_buffer = NULL;
#ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
    g_slidshow_layer3_buffer = NULL;
#endif

    g_slidshow_cntx.fl_hdl = 0;
    g_slidshow_cntx.fl_idx = 0;
    g_slidshow_cntx.is_from_other_app = MMI_FALSE;

    g_slidshow_cntx.is_sort_finished = MMI_FALSE;
    g_slidshow_cntx.is_in_background_call= MMI_FALSE;
    g_slidshow_cntx.is_video_drm_prohibit = MMI_FALSE;

    g_slidshow_cntx.curr_play_time = 0;
}


static mmi_ret mmi_slideshow_filelist_refresh_proc(mmi_event_struct *param)
{
    srv_fmgr_filelist_refresh_result_event_struct *evt = (srv_fmgr_filelist_refresh_result_event_struct*) param;
    
    switch(param->evt_id) 
    {
        case EVT_ID_SRV_FMGR_FILELIST_REFRESH_RESULT:
            {
                S32 file_count;

                if (evt->result >= 0)
                {
                    g_slidshow_cntx.is_sort_finished = MMI_TRUE;
                    
                    if (g_slidshow_cntx.is_stop_play == MMI_TRUE)
                    {
                        return 0;
                    }
                    
                    file_count = srv_fmgr_filelist_count(evt->handle);
                    if (file_count > 0)
                    {
                        mmi_slidshow_entry_play_screen();
                        mmi_frm_scrn_close(g_slidshow_cntx.cur_gid, SCR_ID_SLIDSHOW_SORTING);
                    }
                    else
                    {
                        mmi_slideshow_popup_display(
                            g_slidshow_cntx.cur_gid,
                            (UI_string_type) GetString(STR_GLOBAL_EMPTY),
                            MMI_EVENT_FAILURE,
                            (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP,
                            MMI_FRM_SCREEN_ROTATE_0);
                    }
                }
                else
                {
                    mmi_slideshow_popup_display(
                        g_slidshow_cntx.cur_gid,
                        (UI_string_type) GetString(FMGR_FS_MEDIA_CHANGED_TEXT),
                        MMI_EVENT_FAILURE,
                        (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP,
                        MMI_FRM_SCREEN_ROTATE_0);
                }
            }
            break;
    }

    return MMI_RET_OK;
}


static S32 slidshow_create_filelist(MMI_BOOL is_sort)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    U16 sort_type;
    S32 result;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_slidshow_cntx.fl_hdl != 0) /*has created*/
    {
        return MMI_TRUE;
    }

    if (g_slidshow_cntx.is_from_other_app)
    {
        mmi_slideshow_init_fmgr_filter(&filter, g_slidshow_cntx.browse_type);
    }
    else
    {
        mmi_slideshow_init_fmgr_filter(&filter, MMI_SLIDESHOW_BROWSE_TYPE_ALL);
    }

    /*recover the original folder*/
    mmi_slideshow_get_stored_file_path((PS8)g_slidshow_cntx.media_obj_file_path, NVRAM_EF_SLIDE_SHOW_PATH_LID);

    srv_fmgr_path_remove_filename((WCHAR*)g_slidshow_cntx.media_obj_file_path);
    
    if (!is_sort)
    {
        sort_type = FS_NO_SORT;
    }
    else
    {
        if (g_slidshow_cntx.is_from_other_app)
        {
            sort_type = g_slidshow_cntx.sort_type;
        }
        else
        {
            switch (g_slidshow_cntx.setting.file_sort_type)
            {
            case MMI_SLIDSHOW_FILE_SORT_BY_NONE:
                sort_type = FS_NO_SORT;
                break;
                
            case MMI_SLIDSHOW_FILE_SORT_BY_NAME:
                sort_type = FS_SORT_NAME;
                break;
                
            case MMI_SLIDSHOW_FILE_SORT_BY_TYPE:
                sort_type = FS_SORT_TYPE;
                break;
                
            case MMI_SLIDSHOW_FILE_SORT_BY_TIME:
                sort_type = FS_SORT_TIME;
                break;
                
            case MMI_SLIDSHOW_FILE_SORT_BY_SIZE:
                sort_type = FS_SORT_SIZE;
                break;
                
            default:
                sort_type = 0;
            }
        }
    }
    
    result = srv_fmgr_folder_filelist_create((WCHAR*)g_slidshow_cntx.media_obj_file_path, &filter, sort_type, 
        g_slidshow_cntx.fmgr_list_buffer, SRV_FMGR_FOLDER_FILELIST_MEM_SIZE, &g_slidshow_cntx.fl_hdl);
    srv_fmgr_filelist_refresh(g_slidshow_cntx.fl_hdl, NULL, 0, 0, mmi_slideshow_filelist_refresh_proc, NULL);
    return result;
}

static void slidshow_free_filelist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_slidshow_cntx.fl_hdl)
    {
        srv_fmgr_filelist_destroy(g_slidshow_cntx.fl_hdl);
        g_slidshow_cntx.fl_hdl = 0;

        /*if you free the filelist , it means you can not continue to play it.*/
        g_slidshow_cntx.is_edited = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_hilight_app
 * DESCRIPTION
 *  init slide show applcation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_hilight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_slideshow_entry_app, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    redraw_softkey(MMI_CENTER_SOFTKEY);
    SetCenterSoftkeyFunction(mmi_slideshow_entry_app, KEY_EVENT_UP);
}


static void mmi_slideshow_fmgr_res_handle(cui_folder_selector_result_event_struct *folder_select)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_path[SRV_FMGR_PATH_MAX_LEN + 1];
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (folder_select->result > 0)
    {
        cui_folder_selector_get_selected_filepath(
            folder_select->sender_id,
            NULL,
            (WCHAR *) temp_path,
            SRV_FMGR_PATH_BUFFER_SIZE);
        
        
        result = mmi_slidshow_fmgr_select_result_callback(temp_path);
        if (result == MMI_TRUE)
        {
            cui_folder_selector_close(folder_select->sender_id);
        }
    }
    else if (folder_select->result == 0)
    {
        mmi_frm_group_close(g_slidshow_cntx.cur_gid);
    }
    else
    {
        mmi_slideshow_popup_display(g_slidshow_cntx.cur_gid,
            (U16*)GetString(srv_fmgr_fs_error_get_string(folder_select->result)),
            MMI_EVENT_FAILURE,
            (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP,
                MMI_FRM_SCREEN_ROTATE_0);
    }
}

static mmi_ret mmi_slideshow_app_group_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
    case EVT_ID_GROUP_FIRST_ENTRY:
    case EVT_ID_GROUP_ACTIVE:
    case EVT_ID_GROUP_INACTIVE:
        break;
        
    case EVT_ID_GROUP_DEINIT:
        mmi_slidshow_del_scr_callback();
        g_slidshow_cntx.cur_gid = 0;
        break; 
        
    case EVT_ID_POPUP_QUIT:
        {
            mmi_alert_result_evt_struct *alert = (mmi_alert_result_evt_struct*)evt;
            
            if (alert->user_tag == (void *)MMI_SLIDESHOW_CONFIRM_SAVE_SETTING)
            {
                switch(alert->result)
                {
                case MMI_ALERT_CNFM_YES:
                    mmi_slidshow_setting_inline_done_hdlr();
                    break;
                    
                case MMI_ALERT_CNFM_NO:
                    mmi_slidshow_setting_save_confirm_no();
                    break;
                }
            }
            else if(alert->user_tag == (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP)
            {
                mmi_slidshow_exit_hdlr();
            }
        }
        break;

    case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
        {
            srv_fmgr_notification_adv_action_event_struct *fmgr_act 
                = (srv_fmgr_notification_adv_action_event_struct*)evt;
            
            if(fmgr_act->state == SRV_FMGR_NOTIFICATION_STATE_QUERY)
            {
                if ((fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_MOVE) || /*MMI_FMGR_NOTIFY_PRE_DELETE, MMI_FMGR_NOTIFY_PRE_MOVE */
                    (fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_DELETE) || 
                    (fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_RENAME) || 
                    (fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_DELETE_ALL))
                {
                    if (mmi_slideshow_is_folder_used(fmgr_act))
                    {
                        return MMI_RET_ERR;
                    }
                }
            }
            break;
        }

    case EVT_ID_CUI_FOLDER_SELECTOR_BEFORE_ERROR_HANDLE:
        g_slidshow_cntx.is_meet_folder_selector_error = MMI_TRUE;
        break;

    case EVT_ID_CUI_FOLDER_SELECTOR_RESULT:
        {
            cui_folder_selector_result_event_struct *file_result = (cui_folder_selector_result_event_struct*)evt;

            if (file_result->result > 0)
            {
                if (cui_folder_selector_get_userdata(file_result->sender_id) == MMI_SLIDESHOW_FMGR_SELECT_FOLDER)
                {
                    mmi_slideshow_fmgr_res_handle((cui_folder_selector_result_event_struct *)evt);
                }
            }
            else if (file_result->result == 0)
            {
                mmi_slidshow_exit_hdlr();
            }
            else
            {
                mmi_slidshow_exit_hdlr();
            }
        }
        break;
    }
    
    return MMI_RET_OK;
}


static void mmi_slideshow_popup_display(MMI_ID parent_id, UI_string_type string_content, S32 type, void* user_data, mmi_frm_screen_rotate_enum rotation)
{
    mmi_popup_property_struct property;
   
    mmi_popup_property_init(&property);

    property.user_tag = user_data;
    property.parent_id = parent_id;
    property.rotation = rotation;

    mmi_popup_display(string_content, type, &property);
}


static void mmi_slideshow_confirm_display(MMI_ID parent_id, WCHAR* string_content, S32 type, void* user_data, mmi_frm_screen_rotate_enum rotation)
{
    mmi_confirm_property_struct property;
    
    mmi_confirm_property_init(&property, CNFM_TYPE_YESNO);
    
    property.callback = (mmi_proc_func)mmi_slideshow_app_group_proc;
    property.f_enter_history = 0;
    property.user_tag = (void*)user_data;
    property.parent_id = parent_id;
    
    mmi_confirm_display(string_content, MMI_EVENT_QUERY, &property);
}

static void mmi_slideshow_entry_app_internal(void)
{
    MMI_BOOL entry_ret;

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((PS8) L"root"))
        {
            mmi_event_notify_enum event_type;
            MMI_STR_ID string_id;
            
            string_id = mmi_usb_get_error_info(MMI_USB_ERR_IS_UNAVAILABLE, &event_type);
            mmi_slideshow_popup_display(
                g_slidshow_cntx.cur_gid,
                (WCHAR*)GetString(string_id),
                event_type,
                (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_NONE,
                MMI_FRM_SCREEN_ROTATE_0);
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */
    
    if (g_slidshow_cntx.app_mem_bufer == NULL)
    {
        if (!mmi_slidshow_alloc_app_asm())
        {
            mmi_frm_appmem_prompt_to_release_mem(
                STR_ID_SLIDSHOW_APP,
                IMG_ID_SLIDSHOW_APP,
                MMI_SSHOW_POOL_SIZE + SRV_FMGR_FOLDER_FILELIST_MEM_SIZE,
                mmi_slideshow_entry_app);
            return;
        }
    }
    
    /*we should unset the video stop resume flag to avild the case video stop, and back to idle, the flag not unset*/
    g_slidshow_cntx.is_stop_resume = MMI_FALSE;
    
    /* load setting from NVRAM */
    mmi_slidshow_load_setting();
    
    /* we use this screen to do some check, and allocate application memory only */
    entry_ret = mmi_frm_scrn_enter (g_slidshow_cntx.cur_gid, SCR_ID_SLIDSHOW_APP, NULL, mmi_slideshow_entry_app_internal, 0);
    
    mmi_slidshow_entry_select_folder();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_select_folder
 * DESCRIPTION
 *  entry slide show image folder selection path
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slideshow_entry_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(g_slidshow_cntx.cur_gid))
    {
        mmi_frm_group_close(g_slidshow_cntx.cur_gid);
        g_slidshow_cntx.cur_gid = 0;
    }

    g_slidshow_cntx.cur_gid = mmi_frm_group_create (GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_slideshow_app_group_proc, NULL);
    MMI_ASSERT (g_slidshow_cntx.cur_gid);
    
    mmi_frm_group_enter(g_slidshow_cntx.cur_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_slideshow_entry_app_internal();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_select_folder
 * DESCRIPTION
 *  entry slide show image folder selection path
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_entry_select_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    g_slidshow_cntx.is_meet_folder_selector_error = MMI_FALSE;
    g_slidshow_cntx.fmgr_service_id = cui_folder_selector_create(g_slidshow_cntx.cur_gid, (WCHAR*)L"root", CUI_FOLDER_SELECTOR_STYLE_READ, CUI_FOLDER_SELECTOR_OPT_FIXED_PATH_ON);
    
    if (g_slidshow_cntx.fmgr_service_id > 0)
    {
        cui_file_selector_set_userdata(g_slidshow_cntx.fmgr_service_id, MMI_SLIDESHOW_FMGR_SELECT_FOLDER);
        cui_folder_selector_run(g_slidshow_cntx.fmgr_service_id);
    }
    else
    {
        mmi_slideshow_popup_display(
            g_slidshow_cntx.cur_gid,
            (UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE),
            MMI_EVENT_FAILURE,
            (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_NONE,
            MMI_FRM_SCREEN_ROTATE_0);
        return;
    }

    if (!g_slidshow_cntx.is_meet_folder_selector_error)
    {
        mmi_slideshow_popup_display(
            g_slidshow_cntx.cur_gid,
            (UI_string_type) GetString(STR_ID_SLIDSHOW_NOTIFY_SELECT_FOLDER),
            MMI_EVENT_INFO,
            (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_NONE,
            MMI_FRM_SCREEN_ROTATE_0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_fmgr_select_result_callback
 * DESCRIPTION
 *  select folder result callback function
 * PARAMETERS
 *  filepath        [?]         
 *  filename(?)     [IN]        Filename(not used here)
 *  is_shot(?)      [IN]        Is it short naming
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_slidshow_fmgr_select_result_callback(void *filepath)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    S32 file_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.is_edited = FALSE;
    g_slidshow_cntx.fmgr_service_id = 0;
    if (filepath == NULL)
    {
        /* cencel file selection - delete up to one level before file selection */
        mmi_slidshow_exit_hdlr();
        cui_folder_selector_close(g_slidshow_cntx.fmgr_service_id);

        return MMI_TRUE;
    }
    else
    {
        FMGR_FILTER_INIT(&filter);
        FMGR_FILTER_SET_IMAGE(&filter);
    #ifndef __MMI_SLIDSHOW_M3D_SUPPORT__        
        FMGR_FILTER_CLEAR(&filter,FMGR_TYPE_M3D);
    #endif
    #ifdef __MMI_VIDEO_PLAY_SUPPORT__
        FMGR_FILTER_SET_VIDEO(&filter);
    #endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
    #ifdef __DRM_V02__
        FMGR_FILTER_SET(&filter,FMGR_TYPE_ODF);
    #endif /* __DRM_V02__ */

        FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_ANM);
        FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_EMS);
        FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_SDP);
        FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_RAM);

        file_count = srv_fmgr_fs_path_is_not_empty(filepath, &filter);
        if (file_count)
        {
            /*when we use the path in play screen, we will first remove the last dir, but fmgr return the folder name
            so we append some string to the folder path to form the filepath , although the file name is useless*/
            mmi_wcscpy((WCHAR*)g_slidshow_cntx.media_obj_file_path, (WCHAR*)filepath);
            mmi_wcscat((WCHAR*)g_slidshow_cntx.media_obj_file_path, (WCHAR*)L"*.*");
            mmi_slideshow_save_stored_file_path((PS8)g_slidshow_cntx.media_obj_file_path, NVRAM_EF_SLIDE_SHOW_PATH_LID);
            mmi_slidshow_entry_option_screen();
            /* FMGR_Revise */
            cui_folder_selector_close(g_slidshow_cntx.fmgr_service_id);
        }
        else
        {
            mmi_slideshow_popup_display(
                g_slidshow_cntx.cur_gid,
                (UI_string_type) GetString(STR_GLOBAL_EMPTY),
                MMI_EVENT_FAILURE,
                (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP,
                MMI_FRM_SCREEN_ROTATE_0);
            return MMI_FALSE;
        }

        return MMI_TRUE;
    }
}


static void mmi_slideshow_init_option_menu(mmi_event_struct *evt)
{
    cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
    
    cui_menu_enable_center_softkey(menu_evt->sender_id, 0, IMG_GLOBAL_COMMON_CSK);

    if (g_slidshow_cntx.is_hilite_change)
    {
        cui_menu_set_currlist_highlighted_id(menu_evt->sender_id, MENU_ID_SLIDSHOW_PLAY);
        g_slidshow_cntx.is_hilite_change = MMI_FALSE;
    }

    if (g_slidshow_cntx.is_edited)
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_SLIDSHOW_RESUME, MMI_FALSE);

        cui_menu_set_item_image(menu_evt->sender_id, MENU_ID_SLIDSHOW_RESUME, IMG_GLOBAL_L1);
        cui_menu_set_item_image(menu_evt->sender_id, MENU_ID_SLIDSHOW_PLAY, IMG_GLOBAL_L2);
        cui_menu_set_item_image(menu_evt->sender_id, MENU_ID_SLIDSHOW_SETTING, IMG_GLOBAL_L3);
    }
    else
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_SLIDSHOW_RESUME, MMI_TRUE);

        cui_menu_set_item_image(menu_evt->sender_id, MENU_ID_SLIDSHOW_PLAY, IMG_GLOBAL_L1);
        cui_menu_set_item_image(menu_evt->sender_id, MENU_ID_SLIDSHOW_SETTING, IMG_GLOBAL_L2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_option_screen
 * DESCRIPTION
 *  entry slide show option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_slideshow_option_menu_group_proc(mmi_event_struct *evt)
{   
    switch (evt->evt_id)
    {
        /*********************** General Group Function Start ***************************************/
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            
            if (menu_evt->parent_menu_id == MENU_ID_SLIDSHOW_OPTION_EDIT)
            {
                mmi_slideshow_init_option_menu(evt);
            }
        }
        break;
        
    case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
    case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            
            if (menu_evt->parent_menu_id == MENU_ID_SLIDSHOW_OPTION_EDIT)
            {
                switch(menu_evt->highlighted_menu_id)
                {
                case MENU_ID_SLIDSHOW_RESUME:
                    mmi_slidshow_entry_resume_screen();
                    break;
                    
                case MENU_ID_SLIDSHOW_PLAY:
                    mmi_slideshow_before_enter_play_screen();
                    break;
                    
                case MENU_ID_SLIDSHOW_SETTING:
                    mmi_slidshow_entry_setting_screen();
                    break;
                }
            }
        }
        break;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            
            mmi_frm_group_close(g_slidshow_cntx.cur_gid);
            break;
        }
        break;
        /*********************** General Group Function End ***************************************/        
    }

    return MMI_RET_OK;
}


static void mmi_slidshow_entry_option_screen(void)
{
    MMI_ID  cui_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(g_slidshow_cntx.cur_gid, SCR_ID_SLIDSHOW_OPTION, mmi_slideshow_option_menu_group_proc, (void*)NULL); 
    
    mmi_frm_group_enter(SCR_ID_SLIDSHOW_OPTION, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    cui_gid = cui_menu_create(
        SCR_ID_SLIDSHOW_OPTION, 
        CUI_MENU_SRC_TYPE_RESOURCE, 
        CUI_MENU_TYPE_APPMAIN,
        MENU_ID_SLIDSHOW_OPTION_EDIT, 
        MMI_TRUE, 
        NULL);
    cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_SLIDSHOW_APP)));
    cui_menu_run(cui_gid);
    g_slidshow_cntx.is_bgm_play = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_hilight_play
 * DESCRIPTION
 *  hilight "play" menuitem hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_hilight_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetLeftSoftkeyFunction(mmi_slideshow_before_enter_play_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_play_screen
 * DESCRIPTION
 *  entry slide show play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_entry_play_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_fileinfo_struct file_info;
    S32 file_count;
    WCHAR file_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.osd_opacity = 255;
    g_slidshow_cntx.is_video_file = FALSE;
    g_slidshow_cntx.curr_play_time = 0;

    g_slidshow_cntx.h_animate = GDI_NULL_HANDLE;
    g_slidshow_cntx.is_valid_bgm = FALSE;    
    g_slidshow_cntx.is_animation = FALSE;
    g_slidshow_cntx.is_diff_anim = FALSE;
    g_slidshow_cntx.error_code = SLIDESHOW_ERR_NO_ERROR;
    g_slidshow_cntx.is_from_next = FALSE;
    g_slidshow_cntx.idx2shift = 0;
    g_slidshow_cntx.is_finished = FALSE;

    g_slidshow_cntx.is_stop_resume = MMI_FALSE;

    if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
    {
        lcd_width = UI_device_height;
        lcd_height = UI_device_width;
    }
    else
    {
        lcd_width = UI_device_width;
        lcd_height = UI_device_height;
    }

    file_count = srv_fmgr_filelist_count(g_slidshow_cntx.fl_hdl);
    if(file_count > 0)
    {
        S32 info_reuslt = 0;

        if (g_slidshow_cntx.is_from_other_app)
        {
            g_slidshow_cntx.fl_idx = g_slidshow_cntx.file_index_from_others;
            info_reuslt = srv_fmgr_filelist_get_fileinfo(g_slidshow_cntx.fl_hdl, g_slidshow_cntx.fl_idx, &file_info);
            srv_fmgr_filelist_get_filename(g_slidshow_cntx.fl_hdl, g_slidshow_cntx.fl_idx, file_name, SRV_FMGR_PATH_BUFFER_SIZE);
        }
        else
        {
            g_slidshow_cntx.fl_idx = 0;
            info_reuslt = srv_fmgr_filelist_get_fileinfo(g_slidshow_cntx.fl_hdl, 0, &file_info);
            srv_fmgr_filelist_get_filename(g_slidshow_cntx.fl_hdl, 0, file_name, SRV_FMGR_PATH_BUFFER_SIZE);
        }
        
        if (srv_fmgr_filelist_is_dirty(g_slidshow_cntx.fl_hdl))
        {
            mmi_slideshow_popup_display(
                g_slidshow_cntx.cur_gid,
                (UI_string_type) GetString(STR_ID_SLIDSHOW_NOTIFY_SELECT_FOLDER),
                MMI_EVENT_FAILURE,
                (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP,
                MMI_FRM_SCREEN_ROTATE_0);
            return;
        }

        /* append the name to path, and write it back */
        mmi_slideshow_get_stored_file_path((PS8)g_slidshow_cntx.media_obj_file_path, NVRAM_EF_SLIDE_SHOW_PATH_LID);
        srv_fmgr_path_remove_filename((WCHAR*)g_slidshow_cntx.media_obj_file_path);
        
        if (mmi_wcslen((WCHAR*)g_slidshow_cntx.media_obj_file_path) + mmi_wcslen((WCHAR*)file_name) >= SRV_FMGR_PATH_MAX_LEN)
        {
            mmi_slideshow_popup_display(
                g_slidshow_cntx.cur_gid,
                (UI_string_type) GetString(STR_ID_SLIDSHOW_PATH_TOO_DEEP),
                MMI_EVENT_FAILURE,
                (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP,
                MMI_FRM_SCREEN_ROTATE_0);
            return;
        }

        mmi_wcscat((WCHAR*)g_slidshow_cntx.media_obj_file_path, (WCHAR*)file_name);
#ifndef __MMI_SHOW_FILE_EXT__
        mmi_wcscat((WCHAR*)g_slidshow_cntx.media_obj_file_path, (WCHAR*)file_info.file_ext);
#endif
        mmi_slideshow_save_stored_file_path((PS8)g_slidshow_cntx.media_obj_file_path, NVRAM_EF_SLIDE_SHOW_PATH_LID);
    }
    else if (srv_fmgr_filelist_is_dirty(g_slidshow_cntx.fl_hdl))/*need resort*/
    {
        mmi_slideshow_popup_display(
            g_slidshow_cntx.cur_gid,
            (UI_string_type) GetString(FMGR_FS_MEDIA_CHANGED_TEXT),
            MMI_EVENT_FAILURE,
            (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP,
                MMI_FRM_SCREEN_ROTATE_0);
        return;
    }

	g_slidshow_cntx.is_prev_file_image = MMI_FALSE;
	
    if (file_count > 0)
    {
        filetypes_group_type_enum image_type;

        g_slidshow_cntx.is_bgmusic_selected = FALSE;
        g_slidshow_cntx.is_edited = FALSE;

        /*load the audio for slideshow*/
        if (!g_slidshow_cntx.audio_file_path)
        {
            MMI_ASSERT(0);
        }
        mmi_slideshow_get_stored_file_path((PS8)g_slidshow_cntx.audio_file_path, NVRAM_EF_SLIDE_SHOW_AUDIO_LID);
    
        image_type = srv_fmgr_types_find_group_by_filename_str((WCHAR*)g_slidshow_cntx.media_obj_file_path);

    #ifdef __MMI_VIDEO_PLAY_SUPPORT__
        if (image_type == FMGR_GROUP_VIDEO)
        {
            g_slidshow_cntx.is_video_file = TRUE;
            g_slidshow_cntx.play_time = g_slidshow_cntx.vdo_total_duration = 0;
            g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_CLOSE;
            mmi_slidshow_entry_video_screen();
			g_slidshow_cntx.is_prev_file_image = MMI_FALSE;
        }
        else
    #endif /* __MMI_VIDEO_PLAY_SUPPORT__ */        
        {
            mmi_slidshow_entry_image_display_screen();  /* archive/ invalid odf */
			g_slidshow_cntx.is_prev_file_image = MMI_TRUE;
        }
    }
    else
    {
        mmi_slideshow_popup_display(
            g_slidshow_cntx.cur_gid,
            (UI_string_type) GetString(STR_GLOBAL_EMPTY),
            MMI_EVENT_FAILURE,
            (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP,
                MMI_FRM_SCREEN_ROTATE_0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_hilight_resume
 * DESCRIPTION
 *  hilight "play" menuitem hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_hilight_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetLeftSoftkeyFunction(mmi_slidshow_entry_resume_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_resume_screen
 * DESCRIPTION
 *  entry slide show resume play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_entry_resume_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_multiple_close(
        g_slidshow_cntx.cur_gid,
        mmi_frm_scrn_get_active_id(),
        MMI_FALSE,
        0,
        SCR_ID_SLIDSHOW_OPTION,
        MMI_FALSE);

    g_slidshow_cntx.is_edited = FALSE;       /* auto resume */

    /*load the audio for slideshow*/
    if (!g_slidshow_cntx.audio_file_path)
    {
        MMI_ASSERT(0);
    }
    mmi_slideshow_get_stored_file_path((PS8)g_slidshow_cntx.audio_file_path, NVRAM_EF_SLIDE_SHOW_AUDIO_LID);

	g_slidshow_cntx.is_prev_file_image = MMI_FALSE;

#ifdef __MMI_VIDEO_PLAY_SUPPORT__
    if (g_slidshow_cntx.is_video_file == TRUE)
    {
        mmi_slidshow_entry_video_screen();
		g_slidshow_cntx.is_prev_file_image = MMI_FALSE;
    }
    else
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */    
    {
        mmi_slidshow_entry_image_display_screen();
		g_slidshow_cntx.is_prev_file_image = MMI_TRUE;
    }
}


static mmi_ret mmi_slideshow_end_key_proc(mmi_event_struct *evt)
{
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
    if (evt->evt_id == EVT_ID_PRE_KEY)
    {
		if (key_evt->key_code == KEY_END && key_evt->key_type == KEY_EVENT_DOWN)
		{
			gui_cancel_timer(mmi_slidshow_osd_fade_cyclic);
			mmi_slidshow_reset_osd_fade(FALSE);
			
			if (mdi_audio_is_background_play_suspended())
			{
				mdi_audio_resume_background_play();
			}
            return MMI_RET_OK;
        }
    }
    return MMI_RET_OK;          
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_image_display_screen
 * DESCRIPTION
 *  enter play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_entry_image_display_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    U8 *gui_buffer;
    PU8 p_src_buf;
    PU8 p_dest_buf;
    gdi_rect_struct dest_clip;
    U8 audio_type;
    U32 audio_len;
    U8 *audio_data = NULL;
    FS_HANDLE fs_handle;
    U16 id_err_str = 0;
    PS8 p_err_str;
    U32 file_size;
    U16 image_type = 0;
#ifdef __DRM_SUPPORT__
    slideshow_drm_type_enum drm_type = SLIDESHOW_DRM_FREE_TO_DISP;
#endif
    S32 n_audio_result;
    MMI_BOOL entry_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.result = 0;

    entry_ret = mmi_frm_scrn_enter (
        g_slidshow_cntx.cur_gid, 
        SCR_ID_SLIDSHOW_PLAY, 
        mmi_slidshow_exit_image_display_screen, 
        mmi_slidshow_entry_image_display_screen, 0);
    if (!entry_ret)
    {
        return;
    }
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);

    /*BT control phone sound*/
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_register_volume_sync_callback(APP_SLIDESHOW, MDI_AUD_VOL_LEVEL_NORMAL, mmi_slideshow_hfp_volume_callback);
#endif /* __BT_SPK_VOL_CONTROL__ */

    if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW )
    {
        lcd_width = UI_device_height;
        lcd_height = UI_device_width;
    }
    else
    {
        lcd_width = UI_device_width;
        lcd_height = UI_device_height;
    }

    gui_buffer = mmi_frm_scrn_get_gui_buf(g_slidshow_cntx.cur_gid, SCR_ID_SLIDSHOW_PLAY);

    entry_full_screen();
    gdi_layer_reset_clip();

    if (gui_buffer == NULL)
    {
        g_slidshow_cntx.error_code = SLIDESHOW_ERR_NO_ERROR;
    }
    
    g_slidshow_cntx.is_left_arrow_pressed = FALSE;
    g_slidshow_cntx.is_right_arrow_pressed = FALSE;
    g_slidshow_cntx.is_lsk_pressed = FALSE;
    g_slidshow_cntx.is_rsk_pressed = FALSE;
    
    TurnOnBacklight(0);                     /* stop MMI sleep */
    if ((g_slidshow_cntx.is_bgm_set && g_slidshow_cntx.is_bgm_play) || (!g_slidshow_cntx.is_valid_bgm && g_slidshow_cntx.is_sound_effect_selected))
    {
        mdi_audio_suspend_background_play();
    }

    /*add this to avoid receive key function from other app screen*/
    ClearKeyEvents();
    
	mmi_frm_scrn_set_key_proc(g_slidshow_cntx.cur_gid, SCR_ID_SLIDSHOW_PLAY, mmi_slideshow_end_key_proc);
    //g_slidshow_cntx.end_key_hdlr = GetKeyHandler(KEY_END, KEY_EVENT_DOWN);
    //SetKeyHandler(mmi_slidshow_end_key_press, KEY_END, KEY_EVENT_DOWN);
 
    SetKeyHandler(mmi_slidshow_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_slidshow_rsk_release, KEY_RSK, KEY_EVENT_UP);
    
    if ( g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL && !g_slidshow_cntx.error_code)
    {
        /* because LSK didn't show up, so do not set LSK here */
        SetKeyHandler(mmi_slidshow_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_slidshow_lsk_release, KEY_LSK, KEY_EVENT_UP);
    }

    mmi_slidshow_set_keys();
    
    gdi_image_clear_work_buffer();
#ifdef __MMI_TVOUT__
   if (mdi_tvout_is_enable())
   {
       /* if is fullscreen, we shall set to owner APP Owner draw, to avoid GDI's update */
       mdi_tvout_set_owner(MDI_TV_OWNER_APP);
   }
#endif /* __MMI_TVOUT__ */
   /***************************************************************************** 
   * Layers
   *****************************************************************************/
    gdi_layer_multi_layer_enable();

    /* base layer */
    gdi_layer_get_active(&g_slidshow_cntx.base_layer_handle);

	/*if 24 bit layer use base layer to draw MMI OSD 
	  use layer2_buffer as the background layer */
#if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
	/* create background layer,
	   use layer2_buffer as the background layer
	*/
    g_slidshow_cntx.bg_layer_buf_ptr = g_slidshow_layer2_buffer;
	gdi_layer_create_using_outside_memory(
        0,
        0,
		lcd_width,
        lcd_height,
        &g_slidshow_cntx.bg_layer_handle,
        (PU8) g_slidshow_cntx.bg_layer_buf_ptr,
        (S32) SLIDESHOW_FRAME_BUFFER_SIZE_24_BIT);
        MMI_ASSERT(g_slidshow_cntx.bg_layer_handle);

	gdi_layer_push_and_set_active(g_slidshow_cntx.bg_layer_handle);

	/*caution : this is very hard to understand. on 24 bit layer, we use app memory to
	create layer, and when we exit the layer, we will release it. but if the effect is fade in or fade out,
	we really need the buffer data, so even we release it, we also use the data,
	except */
	if (!g_slidshow_cntx.is_prev_file_image || CheckIsBackHistory())
	{
		gdi_layer_clear_background(GDI_COLOR_BLACK);
	}
	gdi_layer_pop_and_restore_active();

	/* use base layer to draw MMI OSD */
	gdi_layer_push_and_set_active(g_slidshow_cntx.base_layer_handle);
	gdi_layer_get_buffer_ptr(&g_slidshow_cntx.base_layer_buf_ptr);
	gdi_layer_pop_and_restore_active();
#endif

    if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
    {
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);
        gdi_layer_resize(lcd_width, lcd_height);
        gdi_lcd_set_rotate_by_layer(TRUE);      
    }
    
    if (!g_slidshow_cntx.is_image_type)
    {
        gdi_layer_clear_background(GDI_COLOR_BLACK);
    }
    
    /* disable the source key of base layer for blue pictures*/
    gdi_layer_get_source_key(&g_slidshow_cntx.s7y_enable,&g_slidshow_cntx.old_source_key);
    if (g_slidshow_cntx.s7y_enable)
    {
        gdi_layer_set_source_key(FALSE, GDI_COLOR_BLACK); 
    }

    /* osd layer use base layer buffer*/
#if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
    g_slidshow_cntx.osd_layer_buf_ptr = (PU8) g_slidshow_cntx.base_layer_buf_ptr;
#else
    g_slidshow_cntx.osd_layer_buf_ptr = (PU8) g_slidshow_layer2_buffer;
#endif

    if(g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW) // should see after the rotate
    {
        S32 img_width;
        S32 img_height;
        U8 sk_gap = 2, img_spacing = 3;

        mmi_slideshow_horizon_button_bar_width = 0;
        
        gdi_image_get_dimension_id(IMG_ID_SLIDESHOW_SK_PAUSE_UP, &img_width, &img_height);
        if (mmi_slideshow_horizon_button_bar_width < img_width)
        {
            mmi_slideshow_horizon_button_bar_width = img_width;
        }

        gdi_image_get_dimension_id(IMG_ID_SLIDESHOW_SK_BACK_UP, &img_width, &img_height);
        if (mmi_slideshow_horizon_button_bar_width < img_width)
        {
            mmi_slideshow_horizon_button_bar_width = img_width;
        }
        
        gdi_image_get_dimension_id(IMG_ID_SLIDSHOW_LEFT_ARROW, &img_width, &image_height);
        if (mmi_slideshow_horizon_button_bar_width < 2 * img_width + sk_gap + img_spacing)
        {
            mmi_slideshow_horizon_button_bar_width = 2 * img_width + sk_gap + img_spacing;
        }
  
        mmi_slideshow_horizon_button_bar_width += MMI_UI_SOFTKEY_GAP;    
        
    gdi_layer_create_using_outside_memory(
        0,
        0,
            mmi_slideshow_horizon_button_bar_width,
        lcd_height,
        &g_slidshow_cntx.osd_layer_handle,
        (PU8) g_slidshow_cntx.osd_layer_buf_ptr,
        (S32) SLIDSHOW_FRAME_BUFFER_SIZE);
        MMI_ASSERT(g_slidshow_cntx.osd_layer_handle);
        
    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
        gdi_layer_set_position(lcd_width - mmi_slideshow_horizon_button_bar_width, 0);
    }
    else
    {
        S32 img_width;
        S32 img_height;
        U8 sk_gap = 2;

        mmi_slideshow_normal_button_bar_height = 0;

        gdi_image_get_dimension_id(IMG_ID_SLIDESHOW_SK_PAUSE_UP, &img_width, &img_height);
        if (mmi_slideshow_normal_button_bar_height < img_height)
        {
            mmi_slideshow_normal_button_bar_height = img_height;
        }
        
        gdi_image_get_dimension_id(IMG_ID_SLIDESHOW_SK_BACK_UP, &img_width, &img_height);
        if (mmi_slideshow_normal_button_bar_height < img_height)
        {
            mmi_slideshow_normal_button_bar_height = img_height;
        }

        gdi_image_get_dimension_id(IMG_ID_SLIDSHOW_LEFT_ARROW, &img_width, &img_height);
        if (mmi_slideshow_normal_button_bar_height < img_height)
        {
            mmi_slideshow_normal_button_bar_height = img_height;
        }
    
        mmi_slideshow_normal_button_bar_height += sk_gap;
    
        gdi_layer_create_using_outside_memory(
            0,
            0,
            lcd_width,
            mmi_slideshow_normal_button_bar_height,
            &g_slidshow_cntx.osd_layer_handle,
            (PU8) g_slidshow_cntx.osd_layer_buf_ptr,
            (S32) SLIDSHOW_FRAME_BUFFER_SIZE);
        MMI_ASSERT(g_slidshow_cntx.osd_layer_handle);
        gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
        gdi_layer_set_position(0, lcd_height - mmi_slideshow_normal_button_bar_height);
    }

    gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
    g_slidshow_cntx.play_layer_buf_ptr = (PU8) g_slidshow_layer1_buffer;

#if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
    gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_24,
        0,
        0,
        lcd_width,
        lcd_height,
        &g_slidshow_cntx.play_layer_handle,
        (PU8) g_slidshow_cntx.play_layer_buf_ptr,
        (S32) SLIDESHOW_FRAME_BUFFER_SIZE_24_BIT);
#else
    gdi_layer_create_using_outside_memory(
        0,
        0,
        lcd_width,
        lcd_height,
        &g_slidshow_cntx.play_layer_handle,
        (PU8) g_slidshow_cntx.play_layer_buf_ptr,
        (S32) SLIDSHOW_FRAME_BUFFER_SIZE);
#endif

    gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
    gdi_layer_clear_background(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
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
#endif    

#if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
    gdi_layer_set_blt_layer(
        g_slidshow_cntx.bg_layer_handle,
        g_slidshow_cntx.osd_layer_handle,
        0,
        0);
#else
    gdi_layer_set_blt_layer(
        g_slidshow_cntx.base_layer_handle,
        g_slidshow_cntx.osd_layer_handle,
        0,
        0);
#endif

    mmi_slidshow_main_draw_osd();
    
    gui_cancel_timer(mmi_slidshow_osd_fade_cyclic);
    if (g_slidshow_cntx.is_typeofplay_set == SLIDSHOW_MANUAL)
    {
        mmi_slidshow_reset_osd_fade(FALSE);
    }
    
    if ((g_slidshow_cntx.is_effect_set != SLIDSHOW_EFFECT_SPLIT) || (gui_buffer != NULL))
    {
    #if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
        gdi_layer_set_blt_layer(
            g_slidshow_cntx.bg_layer_handle,
            g_slidshow_cntx.play_layer_handle,
            g_slidshow_cntx.osd_layer_handle,
            0);
    #else
        gdi_layer_set_blt_layer(
            g_slidshow_cntx.base_layer_handle,
            g_slidshow_cntx.play_layer_handle,
            g_slidshow_cntx.osd_layer_handle,
            0);
    #endif
    }

    /****************************************************************/
    /*Draw image/ play bgm                                          */
    /****************************************************************/
    g_slidshow_cntx.effect_finish = TRUE;

    /* play bgm sound */
    if ((g_slidshow_cntx.is_bgm_set) && (g_slidshow_cntx.is_bgm_play) && (!g_slidshow_cntx.is_edited))
    {   
#if defined(__MMI_BACKGROUND_CALL__)
        /*if call in background, not play the sound*/
        if (!srv_ucm_is_background_call())
        {
        #ifdef __GAIN_TABLE_SUPPORT__
            mdi_audio_set_audio_type(MDI_AUDIO_TYPE_RING);
        #endif

        n_audio_result = mdi_audio_play_file_portion_with_vol_path(
                            (PU16) g_slidshow_cntx.audio_file_path, 
                            g_slidshow_cntx.curr_play_time,
                            0,
                            DEVICE_AUDIO_PLAY_INFINITE, 
                            NULL, 
                            NULL, 
                            g_slidshow_cntx.audio_volume, 
                            MDI_DEVICE_SPEAKER2);

        if (n_audio_result != MDI_AUDIO_SUCCESS)
        {
            g_slidshow_cntx.is_valid_bgm = FALSE;
        }
        else
        {
            g_slidshow_cntx.is_valid_bgm = TRUE;
        }
        g_slidshow_cntx.is_bgm_play = FALSE;
    }
#else
        #ifdef __GAIN_TABLE_SUPPORT__
            mdi_audio_set_audio_type(MDI_AUDIO_TYPE_RING);
        #endif

        n_audio_result = mdi_audio_play_file_portion_with_vol_path(
                            (PU16) g_slidshow_cntx.audio_file_path, 
                            g_slidshow_cntx.curr_play_time,
                            0,
                            DEVICE_AUDIO_PLAY_INFINITE, 
                            NULL, 
                            NULL, 
                            g_slidshow_cntx.audio_volume, 
                            MDI_DEVICE_SPEAKER2);

        if (n_audio_result != MDI_AUDIO_SUCCESS)
        {
            g_slidshow_cntx.is_valid_bgm = FALSE;
        }
        else
        {
            g_slidshow_cntx.is_valid_bgm = TRUE;
        }
        g_slidshow_cntx.is_bgm_play = FALSE;
#endif
    }

    mmi_slideshow_get_stored_file_path((PS8)g_slidshow_cntx.tmp_file_path, NVRAM_EF_SLIDE_SHOW_PATH_LID);

#ifdef __DRM_SUPPORT__

    /*--------------------------------------------------------------*/
    /* new drm                                                      */
    /* check is archive or not. */

    fs_handle = DRM_open_file((PU16)g_slidshow_cntx.tmp_file_path, FS_READ_ONLY, DRM_PERMISSION_DISPLAY);
    if (fs_handle >= FS_NO_ERROR)
    {
    #ifdef __DRM_V02__
        if (DRM_is_archive(fs_handle, NULL))
        {
            drm_type = SLIDESHOW_DRM_ARCHIVE;
            g_slidshow_cntx.result = -1;
        }
        else 
    #endif /* __DRM_V02__ */            
        {
            if (!DRM_validate_permission(fs_handle, NULL, DRM_PERMISSION_DISPLAY))
            {
                /* no permission, will display key icon.*/
                drm_type = SLIDESHOW_DRM_PROHIBIT;
                g_slidshow_cntx.result = -1;
            }
        }
        DRM_close_file(fs_handle);
    }
    else if (fs_handle == DRM_RESULT_NO_PERMISSION)
    {
        drm_type = SLIDESHOW_DRM_PROHIBIT;
        g_slidshow_cntx.result = -1;
    }  

    /* end new drm                                                  */
    /*--------------------------------------------------------------*/
#endif /* __DRM_SUPPORT__ */

    fs_handle = FS_Open((U16*)g_slidshow_cntx.tmp_file_path, FS_READ_ONLY);
    if (fs_handle >= FS_NO_ERROR)
    {
        FS_GetFileSize(fs_handle, (kal_uint32*) & file_size);
        FS_Close(fs_handle);
    }
    else if (fs_handle < FS_ERROR_RESERVED)
    {
        U16 string_id = STR_GLOBAL_ERROR;
        S32 event_type = MMI_EVENT_FAILURE;

       g_slidshow_cntx.is_image_type = FALSE;
       string_id = srv_fmgr_fs_error_get_string_and_popup_type(fs_handle, &event_type);
       mmi_slideshow_popup_display(
           g_slidshow_cntx.cur_gid, 
           (UI_string_type) GetString(string_id),
           MMI_EVENT_FAILURE,
           (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP,
                MMI_FRM_SCREEN_ROTATE_0);

       return;
    }
#if !defined( __DRM_SUPPORT__ )           
    else
    {       
        MMI_ASSERT(0);  /* fs_handle == FS_ERROR_RESERVED, shouldn't be here. */
    }
#endif

    /* check file size limit and image size limit */
    if (g_slidshow_cntx.result >= 0 && g_slidshow_cntx.error_code == SLIDESHOW_ERR_NO_ERROR)
    {
        /* image size & animation check*/
        if (!mmi_fmgr_util_file_limit_check(FMGR_LIMIT_IMAGE_VIEWER, (PS8) g_slidshow_cntx.tmp_file_path, &p_err_str))
        {
            g_slidshow_cntx.is_image_type = FALSE;
            g_slidshow_cntx.result = -1;
            /* result < 0 */
        #ifdef __MMI_TVOUT__
            mmi_slidshow_draw_img_2_tv(NULL, 0, 0, 0, FALSE, TRUE);   /* draw a black block */
        #endif /* __MMI_TVOUT__ */
            g_slidshow_cntx.error_code = SLIDESHOW_ERR_OTHER;
        #ifdef __MMI_SCREEN_ROTATE__            
            if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
            {
                mmi_slideshow_popup_display(
                    g_slidshow_cntx.cur_gid,
                    (UI_string_type) p_err_str,
                    MMI_EVENT_FAILURE,
                    (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_NONE,
                    MMI_FRM_SCREEN_ROTATE_270);
            }
            else
        #endif                
            {
                mmi_slideshow_popup_display(
                    g_slidshow_cntx.cur_gid,
                    (UI_string_type) p_err_str,
                    MMI_EVENT_FAILURE,
                    (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_NONE,
                    MMI_FRM_SCREEN_ROTATE_0);
            }
            return;
        }
        else
        {
            g_slidshow_cntx.result = gdi_image_get_dimension_file((PS8) g_slidshow_cntx.tmp_file_path, &image_width, &image_height);
            if ((image_width <= 0) || (image_height <= 0) || g_slidshow_cntx.result < GDI_SUCCEED )
            {
                if (g_slidshow_cntx.result == GDI_IMAGE_ERR_IMAGE_TOO_LARGE)    /*MAUI_00547076*/
                {
                    id_err_str = STR_ID_SLIDESHOW_FILE_TOO_LARGE_NO_DISPLAY;
                }
                else
                {
                    id_err_str = STR_GLOBAL_UNSUPPORTED_FORMAT;
                }
                g_slidshow_cntx.result = -1;                                    /*MAUI_00547076*/
            }
            image_type = gdi_image_get_type_from_file((PS8)g_slidshow_cntx.tmp_file_path);

            switch (image_type)
            {
            #ifdef __MMI_SLIDSHOW_M3D_SUPPORT__                   
                case GDI_IMAGE_TYPE_M3D_FILE: 
            #endif                
                case GDI_IMAGE_TYPE_GIF_FILE:
                case GDI_IMAGE_TYPE_SVG_FILE:
                    g_slidshow_cntx.is_animation = TRUE;
                    break;
                default:
                    break;
            }
        }
    }

    if (g_slidshow_cntx.result >= 0)
    {
        gdi_image_get_dimension_file((PS8) g_slidshow_cntx.tmp_file_path, &image_width, &image_height);
        if ((image_width > lcd_width) || (image_height > lcd_height))
        {
            gdi_image_util_fit_bbox(
                lcd_width,
                lcd_height,
                image_width,
                image_height,
                &g_slidshow_cntx.resized_image_offset_x,
                &g_slidshow_cntx.resized_image_offset_y,
                &g_slidshow_cntx.resized_image_width,
                &g_slidshow_cntx.resized_image_height);

            if (g_slidshow_cntx.resized_image_width == 0)
            {
                g_slidshow_cntx.resized_image_width = 1;
                g_slidshow_cntx.resized_image_offset_x--;
            }

            if (g_slidshow_cntx.resized_image_height == 0)
            {
                g_slidshow_cntx.resized_image_height = 1;
                g_slidshow_cntx.resized_image_offset_y--;
            }
        }
        else
        {
            g_slidshow_cntx.resized_image_offset_x = (lcd_width - image_width) >> 1;
            g_slidshow_cntx.resized_image_offset_y = (lcd_height - image_height) >> 1;
            g_slidshow_cntx.resized_image_width = image_width;
            g_slidshow_cntx.resized_image_height = image_height;
        }
        
        gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
        if (gui_buffer != NULL && g_slidshow_cntx.error_code)
        {
            gdi_layer_clear(GDI_COLOR_BLACK);
        }
        else
        {
            gdi_push_and_set_alpha_blending_source_layer(g_slidshow_cntx.play_layer_handle);
            g_slidshow_cntx.result = gdi_image_draw_resized_file(
                                        g_slidshow_cntx.resized_image_offset_x,
                                        g_slidshow_cntx.resized_image_offset_y,
                                        g_slidshow_cntx.resized_image_width,
                                        g_slidshow_cntx.resized_image_height,
                                        (PS8)g_slidshow_cntx.tmp_file_path);
            gdi_pop_and_restore_alpha_blending_source_layer();
        }
        gdi_layer_pop_and_restore_active();
        
        if (g_slidshow_cntx.result < 0)
        {
            gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();
        #if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
            gdi_layer_push_and_set_active(g_slidshow_cntx.bg_layer_handle);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();
        #else
            gdi_layer_push_and_set_active(g_slidshow_cntx.base_layer_handle);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();
        #endif
            if(g_slidshow_cntx.result == GDI_IMAGE_ERR_DECODE_TIME_OUT)
            {
                id_err_str = STR_ID_FMGR_SYSTEM_BUSY_TO_DECODE;
            }
            else
            {
                id_err_str = STR_GLOBAL_INVALID_FORMAT;
            }
        }
        else
        {
        #ifdef __DRM_SUPPORT__
            /* all ok, consume DRM right */
            if(DRM_get_object_method(0, (PU16)g_slidshow_cntx.tmp_file_path) != DRM_METHOD_NONE)
            {
                fs_handle = DRM_open_file((PU16) g_slidshow_cntx.tmp_file_path, FS_READ_ONLY, DRM_PERMISSION_DISPLAY);
                if (fs_handle >= FS_NO_ERROR)
                {                      
                    g_slidshow_cntx.id_DRM = 0;
                    if (gui_buffer == NULL)
                    {
                        g_slidshow_cntx.id_DRM = 
                            DRM_consume_rights(fs_handle, DRM_PERMISSION_DISPLAY, mmi_slidshow_drm_timeup_callback);
                    }
                    else
                    {
                        /* back from interrupt, only timed right will be consume */
                        g_slidshow_cntx.id_DRM = 
                            DRM_consume_timed_rights(fs_handle, DRM_PERMISSION_DISPLAY, mmi_slidshow_drm_timeup_callback);
                    }
                }
                else
                {
                    ASSERT(0);      /* should not enter here */
                }
                DRM_close_file(fs_handle);
            }
        #endif /* __DRM_SUPPORT__ */
        }            
    }
#ifdef __MMI_TVOUT__
    if(g_slidshow_cntx.result >= 0 && !g_slidshow_cntx.error_code)
    {
        mmi_slidshow_draw_img_2_tv((PS8)g_slidshow_cntx.tmp_file_path, 0, image_width, image_height, FALSE, TRUE);
    }
#endif /* __MMI_TVOUT__ */     

    g_slidshow_cntx.is_image_type = FALSE;
    
    if ((gui_buffer == NULL) && (g_slidshow_cntx.result >= 0))
    {
        /* play sound effect                                */
        /* BGM > SOUND, no sound effect while playing BGM   */
        if ((!g_slidshow_cntx.is_bgm_set && g_slidshow_cntx.is_sound_effect_selected) || (g_slidshow_cntx.is_sound_effect_selected && !g_slidshow_cntx.is_valid_bgm))
        {
            switch (g_slidshow_cntx.is_sound_effect_selected)
            {
                case SLIDSHOW_AUDIO1:
                    audio_data = get_audio((U16) (AUD_ID_SLIDSHOW_1), &audio_type, &audio_len);
                    break;
                case SLIDSHOW_AUDIO2:
                    audio_data = get_audio((U16) (AUD_ID_SLIDSHOW_2), &audio_type, &audio_len);
                    break;
                case SLIDSHOW_AUDIO3:
                    audio_data = get_audio((U16) (AUD_ID_SLIDSHOW_3), &audio_type, &audio_len);
                    break;
                default:
                    MMI_ASSERT(0);
            }
            if (audio_data != NULL)
            {
                mdi_audio_play_string_with_vol_path(
                    (void*)audio_data,
                    (U32) audio_len,
                    MDI_FORMAT_WAV,
                    DEVICE_AUDIO_PLAY_ONCE,
                    NULL,
                    NULL,
                    g_slidshow_cntx.audio_volume,
                    MDI_DEVICE_SPEAKER2);
            }
        }
        g_slidshow_cntx.is_diff_anim = FALSE;
        g_slidshow_cntx.effect_finish = FALSE;
        switch (g_slidshow_cntx.is_effect_set)
        {
        #ifdef __MMI_SLIDSHOW_WIPE_ENABLE__            
            case SLIDSHOW_EFFECT_WIPE:
                g_slidshow_cntx.effect_value = -lcd_height;
                gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
                gdi_layer_set_position(0, g_slidshow_cntx.effect_value);                
                gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
                gdi_layer_pop_and_restore_active();
                mmi_slidshow_effect_wipe_cyclic();
                break;
        #endif /* __MMI_SLIDSHOW_WIPE_ENABLE__ */

            case SLIDSHOW_EFFECT_SPLIT:
            #if 1
                gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
                gdi_layer_get_buffer_ptr(&p_src_buf);
                gdi_layer_pop_and_restore_active();
            #endif
                g_slidshow_cntx.extra_layer_var = TRUE;
                
            #if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
                gdi_layer_create_cf(GDI_COLOR_FORMAT_24, 0, 0, lcd_width / 2, lcd_height, &g_slidshow_cntx.extra_layer_1);
                gdi_layer_create_cf(GDI_COLOR_FORMAT_24, lcd_width / 2, 0, lcd_width / 2, lcd_height, &g_slidshow_cntx.extra_layer_2);
                gdi_layer_push_and_set_active(g_slidshow_cntx.extra_layer_1);
                gdi_layer_get_buffer_ptr(&p_dest_buf);
                dest_clip.x1 = 0;
                dest_clip.y1 = 0;
                dest_clip.x2 = (lcd_width >> 1) -1;
                dest_clip.y2 = lcd_height - 1;
                gdi_2d_memory_blt(
                    p_src_buf,
                    lcd_width,
                    0,
                    0,
                    lcd_width,
                    lcd_height,
                    p_dest_buf,
                    lcd_width >> 1,
                    0,
                    0,
                    dest_clip,
                    MAIN_MEDIA_LAYER_BITS_PER_PIXEL);
                gdi_layer_pop_and_restore_active();
                gdi_layer_push_and_set_active(g_slidshow_cntx.extra_layer_2);
                gdi_layer_get_buffer_ptr(&p_dest_buf);
                
                gdi_2d_memory_blt(
                    p_src_buf,
                    lcd_width,
                    lcd_width >> 1,                 /* the offset x,y of copy pointer*/
                    0,
                    lcd_width >> 1,                 /* the width/height to be copied */
                    lcd_height,
                    p_dest_buf,
                    lcd_width >> 1,
                    0,                              /* the offset on the dest buffer */
                    0,
                    dest_clip,
                    MAIN_MEDIA_LAYER_BITS_PER_PIXEL);
                
                gdi_layer_pop_and_restore_active();

                gdi_layer_set_blt_layer(
                    g_slidshow_cntx.bg_layer_handle,
                    g_slidshow_cntx.extra_layer_1,
                    g_slidshow_cntx.extra_layer_2,
                    g_slidshow_cntx.osd_layer_handle);
            #else
                gdi_layer_create(0, 0, lcd_width / 2, lcd_height, &g_slidshow_cntx.extra_layer_1);
                gdi_layer_create(lcd_width / 2, 0, lcd_width / 2, lcd_height, &g_slidshow_cntx.extra_layer_2);
                gdi_layer_push_and_set_active(g_slidshow_cntx.extra_layer_1);
                gdi_layer_get_buffer_ptr(&p_dest_buf);
                dest_clip.x1 = 0;
                dest_clip.y1 = 0;
                dest_clip.x2 = (lcd_width >> 1) -1;
                dest_clip.y2 = lcd_height - 1;
                gdi_2d_memory_blt(
                    p_src_buf,
                    lcd_width,
                    0,
                    0,
                    lcd_width,
                    lcd_height,
                    p_dest_buf,
                    lcd_width >> 1,
                    0,
                    0,
                    dest_clip,
                    GDI_MAINLCD_BIT_PER_PIXEL);
                gdi_layer_pop_and_restore_active();
                gdi_layer_push_and_set_active(g_slidshow_cntx.extra_layer_2);
                gdi_layer_get_buffer_ptr(&p_dest_buf);

                gdi_2d_memory_blt(
                    p_src_buf,
                    lcd_width,
                    lcd_width >> 1,                 /* the offset x,y of copy pointer*/
                    0,
                    lcd_width >> 1,                 /* the width/height to be copied */
                    lcd_height,
                    p_dest_buf,
                    lcd_width >> 1,
                    0,                              /* the offset on the dest buffer */
                    0,
                    dest_clip,
                    GDI_MAINLCD_BIT_PER_PIXEL);

                gdi_layer_pop_and_restore_active();
                gdi_layer_set_blt_layer(
                    g_slidshow_cntx.base_layer_handle,
                    g_slidshow_cntx.extra_layer_1,
                    g_slidshow_cntx.extra_layer_2,
                    g_slidshow_cntx.osd_layer_handle);
            #endif

                g_slidshow_cntx.effect_value = -lcd_width;
                mmi_slidshow_effect_split_cyclic();
                break;

            case SLIDSHOW_EFFECT_FADE_IN:
                g_slidshow_cntx.effect_value = 0;
                mmi_slidshow_effect_fade_in_cyclic();
                break;

            default:
                gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
                mmi_slidshow_image_effect_finished();
                break;
                
        }
        
    #ifdef SLIDSHOW_POWER_SAVING
        if (g_slidshow_cntx.is_edited)
        {
            gui_start_timer(SLIDSHOW_POW_SAVE_DELAY, mmi_slidshow_turn_off_bl_hdlr);
        }
    #endif
    
    }
    else   /* gui buffer != NULL || result < 0 */
    {
        /* error handling */
    #ifdef __DRM_SUPPORT__
        if(SLIDESHOW_DRM_FREE_TO_DISP != drm_type)
        {
            /* draw the key icon. */
        #if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
            gdi_layer_set_blt_layer(
                g_slidshow_cntx.bg_layer_handle,
                g_slidshow_cntx.play_layer_handle,
                g_slidshow_cntx.osd_layer_handle,
                0);
        #else
            gdi_layer_set_blt_layer(
                g_slidshow_cntx.base_layer_handle,
                g_slidshow_cntx.play_layer_handle,
                g_slidshow_cntx.osd_layer_handle,
                0);
        #endif

            /* draw archive icon if it is archive */
            gdi_image_get_dimension_id(IMG_ID_FMGR_DRM_LOCKED, &image_width, &image_height);
            gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
            gdi_image_draw_id((lcd_width - image_width)>>1, (lcd_height - image_height) >> 1, IMG_ID_FMGR_DRM_LOCKED);
            gdi_layer_pop_and_restore_active();
            gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
        #ifdef __MMI_TVOUT__
            mmi_slidshow_draw_img_2_tv(NULL, IMG_ID_FMGR_DRM_LOCKED, image_width, image_height, FALSE, TRUE);
        #endif /* __MMI_TVOUT__ */       
            if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) && (!g_slidshow_cntx.is_edited))
            {
                gui_start_timer(g_slidshow_cntx.speed_value, mmi_slidshow_auto_next);
            }
            
        #ifdef __MMI_TOUCH_SCREEN__
            wgui_register_pen_down_handler(mmi_slidshow_pen_down_hdlr);
            wgui_register_pen_up_handler(mmi_slidshow_pen_up_hdlr);
            wgui_register_pen_move_handler(mmi_slidshow_pen_move_hdlr);
        #endif /* __MMI_TOUCH_SCREEN__ */
        
            return;
        }
    #endif /* __DRM_SUPPORT__ */
    
        if (gui_buffer == NULL)
        { 
            /* result < 0 */
        #ifdef __MMI_TVOUT__
            mmi_slidshow_draw_img_2_tv(NULL, 0, 0, 0, FALSE, TRUE);   /* draw a black block */
        #endif /* __MMI_TVOUT__ */
            gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();
        #if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
            gdi_layer_push_and_set_active(g_slidshow_cntx.bg_layer_handle);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();
        #else
            gdi_layer_push_and_set_active(g_slidshow_cntx.base_layer_handle);
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_pop_and_restore_active();
        #endif
            //gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
            g_slidshow_cntx.error_code = SLIDESHOW_ERR_OTHER;
        #ifdef __MMI_SCREEN_ROTATE__            
            if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
            {
                mmi_slideshow_popup_display(
                    g_slidshow_cntx.cur_gid,
                    (UI_string_type) GetString(id_err_str),
                    MMI_EVENT_FAILURE,
                    (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_NONE,
                    MMI_FRM_SCREEN_ROTATE_270);
            }
            else
        #endif                
            {
                mmi_slideshow_popup_display(
                    g_slidshow_cntx.cur_gid,
                    (UI_string_type) GetString(id_err_str),
                    MMI_EVENT_FAILURE,
                    (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_NONE,
                    MMI_FRM_SCREEN_ROTATE_0);
            }
            return;
        }
        else
        {
            /* restore from interrupt */
            /* add animation handling */
            gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
            if(g_slidshow_cntx.error_code)
            {
                if(g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL && !g_slidshow_cntx.is_edited)
                {
                    if (g_slidshow_cntx.is_from_next)
                    {
                        /*enlarge the timer for user to look the previous one*/
                        gui_start_timer(SLIDSHOW_FAST_SPEED, mmi_slidshow_left_arrow_release);
                        g_slidshow_cntx.is_from_next = FALSE;
                    }
                    else
                    {
                        /*enlarge the timer for user to look the previous one*/
                        gui_start_timer(SLIDSHOW_FAST_SPEED, mmi_slidshow_auto_next);
                    }
                }
            #ifdef __MMI_TVOUT__
                mmi_slidshow_draw_img_2_tv(NULL, 0, 0, 0, FALSE, TRUE); /* clean TVOUT screen */
            #endif /* __MMI_TVOUT__ */
            }
            else
            {
                mmi_slidshow_image_effect_finished();
            }
        #ifdef SLIDSHOW_POWER_SAVING
            if (g_slidshow_cntx.is_edited)
            {
                gui_start_timer(SLIDSHOW_POW_SAVE_DELAY, mmi_slidshow_turn_off_bl_hdlr);
            }
        #endif /* #ifdef SLIDSHOW_POWER_SAVING */
        }
    }

    if (g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL)
    {
        if (!g_slidshow_cntx.is_image_type)
        {
            //gui_start_timer(SLIDSHOW_OSD_FADE_OUT_TIME, mmi_slidshow_osd_fade_cyclic);
            mmi_slidshow_osd_fade_cyclic();
        }
        else if(g_slidshow_cntx.osd_opacity <= 255 && g_slidshow_cntx.osd_opacity > 0)
        {
            gui_cancel_timer(mmi_slidshow_osd_fade_cyclic);
            mmi_slidshow_osd_fade_cyclic();
        }
    }
    
#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_pen_down_handler(mmi_slidshow_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_slidshow_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_slidshow_pen_move_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_exit_image_display_screen
 * DESCRIPTION
 *  exit play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_exit_image_display_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_clear_volume_sync_callback(APP_SLIDESHOW);
#endif /* __BT_SPK_VOL_CONTROL__ */

#ifdef __DRM_SUPPORT__
    if (g_slidshow_cntx.id_DRM)
    {
        DRM_stop_consume(g_slidshow_cntx.id_DRM);
        g_slidshow_cntx.id_DRM = 0;
    }
#endif /* __DRM_SUPPORT__ */

#ifdef SLIDSHOW_POWER_SAVING
    gui_cancel_timer(mmi_slidshow_turn_off_bl_hdlr);    
#endif

    gui_cancel_timer(mmi_slidshow_osd_fade_cyclic);
    if (!(g_slidshow_cntx.is_image_type || g_slidshow_cntx.is_video_type))
    {
        if (g_slidshow_cntx.is_bgm_set == BACKGROUND_MUSIC_ON)
        {
            mdi_audio_get_progress_time(&g_slidshow_cntx.curr_play_time);
            mdi_audio_stop_file();
            
            g_slidshow_cntx.is_bgm_play = TRUE;
        }
        else
        {
            if ((g_slidshow_cntx.is_bgm_set == BACKGROUND_MUSIC_ON) && g_slidshow_cntx.is_edited)
            {
                g_slidshow_cntx.is_bgm_play = TRUE;
            }
        }
    }

    if(!g_slidshow_cntx.error_code && ((g_slidshow_cntx.is_bgm_play && g_slidshow_cntx.is_bgm_set) || (!g_slidshow_cntx.is_valid_bgm && g_slidshow_cntx.is_sound_effect_selected)))
    {   
        /* error popup don't resume */
        mdi_audio_resume_background_play();
    }

    switch (g_slidshow_cntx.is_effect_set)
    {
    #ifdef __MMI_SLIDSHOW_WIPE_ENABLE__        
        case SLIDSHOW_EFFECT_WIPE:
            gui_cancel_timer(mmi_slidshow_effect_wipe_cyclic);
            break;
    #endif /* __MMI_SLIDSHOW_WIPE_ENABLE__ */            
        case SLIDSHOW_EFFECT_SPLIT:
            gui_cancel_timer(mmi_slidshow_effect_split_cyclic);
            break;
        case SLIDSHOW_EFFECT_FADE_IN:
            gui_cancel_timer(mmi_slidshow_effect_fade_in_cyclic);
            break;
        default:
            break;
    }
    /* stop animation if needed */
    if (g_slidshow_cntx.h_animate != GDI_NULL_HANDLE)
    {
        gdi_anim_stop(g_slidshow_cntx.h_animate);
        g_slidshow_cntx.h_animate = GDI_NULL_HANDLE;
    }

    gui_cancel_timer(mmi_slidshow_auto_next);
    gui_cancel_timer(mmi_slidshow_right_arrow_release);
    gui_cancel_timer(mmi_slidshow_slice_time_out);
    gui_cancel_timer(mmi_slidshow_left_arrow_release);
    gui_cancel_timer(mmi_slidshow_apply_index_change);

    /* let MMI can sleep */
    TurnOffBacklight();

#if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
    gdi_layer_push_and_set_active(g_slidshow_cntx.base_layer_handle);
    gdi_layer_set_rotate(GDI_LCD_LAYER_ROTATE_0);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

    gdi_layer_push_and_set_active(g_slidshow_cntx.bg_layer_handle);
    if (g_slidshow_cntx.error_code)
    {
        gdi_layer_flatten(
            g_slidshow_cntx.play_layer_handle,
            g_slidshow_cntx.osd_layer_handle,
            GDI_NULL_HANDLE,
            GDI_NULL_HANDLE);
    }
    else
    {
        gdi_layer_flatten(g_slidshow_cntx.play_layer_handle, GDI_NULL_HANDLE, GDI_NULL_HANDLE, GDI_NULL_HANDLE);
    }
    gdi_layer_pop_and_restore_active();

#else
#if defined(LCM_ROTATE_SUPPORT)
    if (g_slidshow_cntx.error_code)
    {
        gdi_layer_flatten_to_base(
            g_slidshow_cntx.play_layer_handle,
            g_slidshow_cntx.osd_layer_handle,
            GDI_NULL_HANDLE,
            GDI_NULL_HANDLE);
    }
    else
    {
        gdi_layer_flatten_to_base(g_slidshow_cntx.play_layer_handle, GDI_NULL_HANDLE, GDI_NULL_HANDLE, GDI_NULL_HANDLE);
    }    
#else
    if (g_slidshow_cntx.error_code)
    {
        gdi_layer_flatten_to_base(
            g_slidshow_cntx.play_layer_handle,
            g_slidshow_cntx.osd_layer_handle,
            GDI_NULL_HANDLE,
            GDI_NULL_HANDLE);
    }
    else
    {
        gdi_layer_flatten_to_base(g_slidshow_cntx.play_layer_handle, GDI_NULL_HANDLE, GDI_NULL_HANDLE, GDI_NULL_HANDLE);
    }
#endif
#endif

    /* free layers */
    if (g_slidshow_cntx.osd_layer_buf_ptr != NULL)
    {
        gdi_layer_free(g_slidshow_cntx.osd_layer_handle);
        g_slidshow_cntx.osd_layer_buf_ptr = NULL;
        g_slidshow_cntx.osd_layer_handle = GDI_NULL_HANDLE;

    }
    
    if (g_slidshow_cntx.play_layer_buf_ptr != NULL)
    {
        gdi_layer_free(g_slidshow_cntx.play_layer_handle);
        g_slidshow_cntx.play_layer_buf_ptr = NULL;
        g_slidshow_cntx.play_layer_handle = GDI_NULL_HANDLE;
    }
    
    if (g_slidshow_cntx.extra_layer_var == TRUE)
    {
        g_slidshow_cntx.extra_layer_var = FALSE;
        gdi_layer_free(g_slidshow_cntx.extra_layer_1);
        gdi_layer_free(g_slidshow_cntx.extra_layer_2);
    }

    if ((g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW) && (!g_slidshow_cntx.is_image_type))
    {
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);
        gdi_layer_resize(UI_device_width, UI_device_height);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_lcd_set_rotate_by_layer(FALSE);
    }

#if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
    if (g_slidshow_cntx.bg_layer_buf_ptr != NULL)
    {
        gdi_layer_free(g_slidshow_cntx.bg_layer_handle);
        g_slidshow_cntx.bg_layer_buf_ptr = NULL;
        g_slidshow_cntx.bg_layer_handle = GDI_NULL_HANDLE;
    }
#endif

        /* restore TV out mode */
#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable() && g_slidshow_cntx.h_animate_tv != GDI_NULL_HANDLE)
    {
        gdi_anim_stop(g_slidshow_cntx.h_animate_tv);
        g_slidshow_cntx.h_animate_tv = GDI_NULL_HANDLE;
    }
    
    if ((mdi_tvout_is_enable()) && (!g_slidshow_cntx.is_image_type))
    {
        /* restore back to GDI */
        mdi_tvout_set_owner(MDI_TV_OWNER_GDI);

        /* restore back to start mode1 */
        mdi_tvout_set_mode(
            MDI_TV_MODE_LCD_SCR,
            0,  /* layer_width */
            0); /* layer_height */
    }
#endif /* __MMI_TVOUT__ */
    
    /* restore baselayer sourcekey */
    if (g_slidshow_cntx.s7y_enable)
    {
        gdi_layer_set_source_key(g_slidshow_cntx.s7y_enable, g_slidshow_cntx.old_source_key);
    }
    g_slidshow_cntx.effect_finish = TRUE;

    gdi_layer_set_blt_layer(g_slidshow_cntx.base_layer_handle, 0, 0, 0);
    gdi_layer_multi_layer_disable();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_right_arrow_press
 * DESCRIPTION
 *  right arrow key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_right_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_slidshow_cntx.osd_opacity)
    {
        mmi_slidshow_osd_show_up();
        return;
    }

    mmi_slidshow_reset_osd_fade(TRUE);
    mmi_slidshow_right_arrow_icon_key_press();
}


void mmi_slidshow_auto_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_slidshow_right_arrow_release);
    gui_cancel_timer(mmi_slidshow_apply_index_change);
    
    /*if with key pressed, will not switch image*/
    if (g_slidshow_cntx.is_lsk_pressed || g_slidshow_cntx.is_rsk_pressed ||
        g_slidshow_cntx.is_left_arrow_pressed || g_slidshow_cntx.is_right_arrow_pressed)
    {
        gui_start_timer(g_slidshow_cntx.speed_value, mmi_slidshow_auto_next);
        return;
    }

    g_slidshow_cntx.idx2shift = 1;
    mmi_slidshow_apply_index_change();
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_right_arrow_release
 * DESCRIPTION
 *  right arrow key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_right_arrow_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_slidshow_cntx.is_right_arrow_pressed)
    {
        return;
    }

    if (!g_slidshow_cntx.osd_opacity)
    {
        mmi_slidshow_right_arrow_icon_key_release();
        mmi_slidshow_osd_show_up();
        return;
    }

    gui_cancel_timer(mmi_slidshow_auto_next);
    gui_cancel_timer(mmi_slidshow_apply_index_change);
    mmi_slidshow_right_arrow_icon_key_release();
    g_slidshow_cntx.idx2shift++;
    gui_start_timer(SLIDSHOW_KEY_PRESS_DELAY, mmi_slidshow_apply_index_change);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_apply_index_change
 * DESCRIPTION
 *  apply the file index change to file system.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_apply_index_change(void){
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_fileinfo_struct file_info;
    S32 index = 0;
    S32 file_count;
    S32 count;
    S32 info_result;
    WCHAR file_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_slidshow_cntx.effect_finish)
    {
        gui_cancel_timer(mmi_slidshow_apply_index_change);
        gui_start_timer(SLIDSHOW_ANIM_NEXT_IMG_DELAY, mmi_slidshow_apply_index_change);
        return;
    }    
    
    g_slidshow_cntx.is_diff_anim = TRUE;
    g_slidshow_cntx.is_video_file = FALSE;
    g_slidshow_cntx.is_edited = FALSE;
    g_slidshow_cntx.is_from_next = FALSE;
    
    if (g_slidshow_cntx.is_bgmusic_selected)
    {
        g_slidshow_cntx.is_bgmusic_selected = FALSE;
        index = resume_index;
    }
    ASSERT(g_slidshow_cntx.fl_hdl);
    index = g_slidshow_cntx.fl_idx;
    file_count = srv_fmgr_filelist_count(g_slidshow_cntx.fl_hdl);

    if (file_count == 0)
    {
        mmi_slideshow_popup_display(
            g_slidshow_cntx.cur_gid,
            (UI_string_type) GetString(STR_GLOBAL_EMPTY),
            MMI_EVENT_FAILURE,
            (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP,
            MMI_FRM_SCREEN_ROTATE_0);
        return;
    }
    else if (srv_fmgr_filelist_is_dirty(g_slidshow_cntx.fl_hdl))
    {
        mmi_slideshow_popup_display(
            g_slidshow_cntx.cur_gid,
            (UI_string_type) GetString(FMGR_FS_MEDIA_CHANGED_TEXT),
            MMI_EVENT_FAILURE,
            (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP,
            MMI_FRM_SCREEN_ROTATE_0);
        return;
    }

    /* move index */
    index += g_slidshow_cntx.idx2shift;
    while(index < 0)
    {
        index += file_count;
    }
    count = index;          /* if count > file_count && auto_once => stop playback. */

    index %= file_count;
    g_slidshow_cntx.fl_idx = index;

    g_slidshow_cntx.idx2shift = 0;
    
    info_result = srv_fmgr_filelist_get_fileinfo(g_slidshow_cntx.fl_hdl, index, &file_info);
    srv_fmgr_filelist_get_filename(g_slidshow_cntx.fl_hdl, index, file_name, SRV_FMGR_PATH_BUFFER_SIZE);
    if (srv_fmgr_filelist_is_dirty(g_slidshow_cntx.fl_hdl))
    {
        mmi_slideshow_popup_display(
            g_slidshow_cntx.cur_gid,
            (UI_string_type) GetString(FMGR_FS_MEDIA_CHANGED_TEXT),
            MMI_EVENT_FAILURE,
            (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP,
            MMI_FRM_SCREEN_ROTATE_0);
        return;
    }

    resume_index = index;
    if (g_slidshow_cntx.is_random_effect == TRUE)
    {
        g_slidshow_cntx.is_effect_set = (g_slidshow_cntx.is_effect_set + 1) % (SLIDSHOW_EFFECT_TOTAL - 1);
    }

    /* append the name to path */
    mmi_slideshow_get_stored_file_path((PS8)g_slidshow_cntx.media_obj_file_path, NVRAM_EF_SLIDE_SHOW_PATH_LID);
    srv_fmgr_path_remove_filename((WCHAR*)g_slidshow_cntx.media_obj_file_path);
    
    if (mmi_wcslen((WCHAR*)g_slidshow_cntx.media_obj_file_path) + mmi_wcslen((WCHAR*)file_name) >= SRV_FMGR_PATH_MAX_LEN)
    {
        mmi_slideshow_popup_display(
            g_slidshow_cntx.cur_gid,
            (UI_string_type) GetString(FMGR_FS_MEDIA_CHANGED_TEXT),
            MMI_EVENT_FAILURE,
            (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP,
            MMI_FRM_SCREEN_ROTATE_0);
        return;
    }

    mmi_wcscat((WCHAR*)g_slidshow_cntx.media_obj_file_path, (WCHAR*)file_name);
#ifndef __MMI_SHOW_FILE_EXT__
    mmi_wcscat((WCHAR*)g_slidshow_cntx.media_obj_file_path, (WCHAR*)file_info.file_ext);
#endif
    
    mmi_slideshow_save_stored_file_path((PS8)g_slidshow_cntx.media_obj_file_path, NVRAM_EF_SLIDE_SHOW_PATH_LID);

    if ((count == file_count) && (g_slidshow_cntx.is_typeofplay_set == SLIDSHOW_AUTO_ONCE))
    {
        g_slidshow_cntx.is_finished = TRUE;
        gui_cancel_timer(mmi_slidshow_osd_fade_cyclic);
        mmi_slidshow_reset_osd_fade(FALSE);
        mmi_frm_scrn_close(g_slidshow_cntx.cur_gid, SCR_ID_SLIDSHOW_PLAY);
    }
    else
    {
        mmi_slidshow_entry_next_file();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_left_arrow_press
 * DESCRIPTION
 *  left arrow key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_left_arrow_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_slidshow_cntx.osd_opacity)
    {
        mmi_slidshow_osd_show_up();
        return;
    }

    mmi_slidshow_reset_osd_fade(TRUE);
    mmi_slidshow_left_arrow_icon_key_press();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_left_arrow_release
 * DESCRIPTION
 *  left arrow key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_left_arrow_release(void)
{
    if (!g_slidshow_cntx.is_left_arrow_pressed)
    {
        return;
    }

    if (!g_slidshow_cntx.osd_opacity)
    {
        mmi_slidshow_left_arrow_icon_key_release();
        mmi_slidshow_osd_show_up();
        return;
    }

    gui_cancel_timer(mmi_slidshow_auto_next);
    gui_cancel_timer(mmi_slidshow_apply_index_change);
    mmi_slidshow_left_arrow_icon_key_release();
    g_slidshow_cntx.idx2shift--;
    gui_start_timer(SLIDSHOW_KEY_PRESS_DELAY, mmi_slidshow_apply_index_change);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_main_draw_osd
 * DESCRIPTION
 *  draws softkeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_main_draw_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 lsk_img, rsk_img;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_opacity(TRUE, (U8) g_slidshow_cntx.osd_opacity);

    /******* draw softkey ********/
    rsk_img = IMG_ID_SLIDESHOW_SK_BACK_UP;
    
    if ((g_slidshow_cntx.is_typeofplay_set == SLIDSHOW_MANUAL) && (g_slidshow_cntx.is_video_file != MMI_TRUE))
    {
        lsk_img = 0;
    }
    else if (g_slidshow_cntx.is_edited)
    {
        lsk_img = IMG_ID_SLIDESHOW_SK_RESUME_UP;
    }
    else
    {
        lsk_img = IMG_ID_SLIDESHOW_SK_PAUSE_UP;
    }
    
    if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW && g_slidshow_cntx.is_video_file == MMI_TRUE)
    {
    #ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
        if (!g_slidshow_cntx.is_in_background_call && !g_slidshow_cntx.is_video_drm_prohibit)
        {
        gdi_layer_set_active(g_slidshow_cntx.osd_layer_handle_of_idp_rotate);
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            mmi_slidshow_draw_softkey(lsk_img, rsk_img, TRUE);
        mmi_slidshow_draw_arrow_key_osd();
        gdi_layer_set_active(g_slidshow_cntx.osd_layer_handle);
        mdi_util_rotate_osd_for_hw_rotator(g_slidshow_cntx.osd_layer_handle_of_idp_rotate, g_slidshow_cntx.osd_layer_handle);

        }
        else
        {
            mmi_slidshow_draw_softkey(lsk_img, rsk_img, TRUE);
            mmi_slidshow_draw_arrow_key_osd();
        }
    #else
        mmi_slidshow_draw_softkey(lsk_img, rsk_img, TRUE);
        mmi_slidshow_draw_arrow_key_osd();
    #endif
    }
    else
    {
        mmi_slidshow_draw_softkey(lsk_img, rsk_img, TRUE);
        mmi_slidshow_draw_arrow_key_osd();
    }

    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_draw_softkey
 * DESCRIPTION
 *  lsk press hdlr
 * PARAMETERS
 *  lsk_str         [IN]        Lsk string
 *  rsk_str         [IN]        Rsk string
 *  is_clear_bg     [IN]        Clear background flag
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_draw_softkey(U16 lsk_img, U16 rsk_img, BOOL is_clear_bg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sk_gap = 2;
    S32 img_width, img_height;
    S32 img_offset_x, img_offset_y;
    S32 layer_offset_x, layer_offset_y;
    S32 offset_x = 0;
    S32 offset_y = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_clip();
    gdi_layer_push_text_clip();
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    /*if use vector font, the string will drawed by image*/
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    /*currently , pause/resume/back is same size, so use one*/
    gdi_image_get_dimension_id(IMG_ID_SLIDESHOW_SK_PAUSE_UP, &img_width, &img_height);

    if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
    {
        offset_x = lcd_width - img_width - sk_gap;
        offset_y = lcd_height - img_height - sk_gap;        

        /*if in video file and use idp rotate, the data should be fixed*/
        if (g_slidshow_cntx.is_video_file)
        {
        #ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
            if (!g_slidshow_cntx.is_in_background_call && !g_slidshow_cntx.is_video_drm_prohibit)
            {
                offset_x = lcd_height - img_width - sk_gap;
                offset_y = lcd_width - img_height - sk_gap;
            }      
        #endif
        }   
    }
    else
    {   
        offset_x = sk_gap;
        offset_y = lcd_height - img_height - sk_gap;
    }

#ifdef __MMI_TOUCH_SCREEN__
    g_slidshow_touch_screen_cntx.lsk.pos_x = offset_x;
    g_slidshow_touch_screen_cntx.lsk.pos_y = offset_y;
    g_slidshow_touch_screen_cntx.lsk.width = img_width + 1;
    g_slidshow_touch_screen_cntx.lsk.height = img_height + 1;
#endif

    if (g_slidshow_cntx.is_lsk_pressed)
    {
        lsk_img++;
    }
    
    /*get image coordinate*/
    img_offset_x = offset_x - layer_offset_x;
    img_offset_y = offset_y - layer_offset_y;

    /*if in video file and use idp rotate, the data should be fixed*/
    if (g_slidshow_cntx.is_video_file && g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
    {
    #ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
        if (!g_slidshow_cntx.is_in_background_call && !g_slidshow_cntx.is_video_drm_prohibit)
        {
            img_offset_x = offset_x - (lcd_height - mmi_slideshow_horizon_button_bar_width);
            img_offset_y = offset_y;
        }
    #endif
    }
    gdi_image_draw_id(img_offset_x, img_offset_y, lsk_img);


    /*draw rsk*/
    if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
    {
        offset_x = lcd_width - img_width - sk_gap;
        offset_y = sk_gap;        

        /*if in video file and use idp rotate, the data should be fixed*/
        if (g_slidshow_cntx.is_video_file)
        {
        #ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
            if (!g_slidshow_cntx.is_in_background_call && !g_slidshow_cntx.is_video_drm_prohibit)
            {
                offset_x = lcd_height - img_width - sk_gap;
                offset_y = sk_gap;
            }
        #endif
        }
    }
    else
    {   
        offset_x = lcd_width - img_width - sk_gap;
        offset_y = lcd_height - img_height - sk_gap;
    }
   
#ifdef __MMI_TOUCH_SCREEN__
    g_slidshow_touch_screen_cntx.rsk.pos_x = offset_x;
    g_slidshow_touch_screen_cntx.rsk.pos_y = offset_y;
    g_slidshow_touch_screen_cntx.rsk.width = img_width + 1;
    g_slidshow_touch_screen_cntx.rsk.height = img_height + 1;
#endif

    if (g_slidshow_cntx.is_rsk_pressed)
    {
        rsk_img++;
    }
    
    img_offset_x = offset_x - layer_offset_x;
    img_offset_y = offset_y - layer_offset_y;

    /*if in video file and use idp rotate, the data should be fixed*/
    if (g_slidshow_cntx.is_video_file && g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
    {
    #ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
        if (!g_slidshow_cntx.is_in_background_call && !g_slidshow_cntx.is_video_drm_prohibit)
        {
            img_offset_x = offset_x - (lcd_height - mmi_slideshow_horizon_button_bar_width);
            img_offset_y = offset_y;
        }      
    #endif
    } 
    gdi_image_draw_id(img_offset_x, img_offset_y, rsk_img);

    gdi_layer_pop_clip();
    gdi_layer_pop_text_clip();

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_lsk_press
 * DESCRIPTION
 *  lsk press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_lsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_slidshow_cntx.osd_opacity)
    {
        mmi_slidshow_osd_show_up();
        return;
    }
    if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) || (g_slidshow_cntx.is_video_file))
    {
        mmi_slidshow_reset_osd_fade(TRUE);
    }
    g_slidshow_cntx.is_lsk_pressed = TRUE;
    mmi_slidshow_show_press_release_softkey();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_show_press_release_softkey
 * DESCRIPTION
 *  draw and show softkey based on different screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_show_press_release_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
    if (gdi_layer_is_double(g_slidshow_cntx.osd_layer_handle))
    {
        gdi_layer_toggle_double();
    }
    gdi_layer_pop_and_restore_active();    
    mmi_slidshow_main_draw_osd();    

    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_lsk_release
 * DESCRIPTION
 *  lsk release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_lsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VIDEO_PLAY_SUPPORT__    
    MDI_RESULT ret;
    U64 ms_current_play_time;
    U32 flg_blt, flg_play;
#endif    
    S8 audio_buffer[SRV_FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_slidshow_cntx.is_lsk_pressed)
    {
        return;
    }
    g_slidshow_cntx.is_lsk_pressed = FALSE;

    if (!g_slidshow_cntx.osd_opacity)
    {
        mmi_slidshow_main_draw_osd();
        mmi_slidshow_osd_show_up();
        return;
    }
    
#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call() && g_slidshow_cntx.is_video_file)
    {
        mmi_slideshow_popup_display(
            g_slidshow_cntx.cur_gid,
            (UI_string_type) GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL),
            MMI_EVENT_FAILURE,
            (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_NONE,
            MMI_FRM_SCREEN_ROTATE_0);
        return;
    }
#endif

    if (g_slidshow_cntx.is_edited == TRUE)
    {
    #ifdef SLIDSHOW_POWER_SAVING
        gui_cancel_timer(mmi_slidshow_turn_off_bl_hdlr);
    #endif
        /* resume playing. */
        g_slidshow_cntx.is_edited = FALSE;
    #ifdef __MMI_VIDEO_PLAY_SUPPORT__        
        if (g_slidshow_cntx.is_video_file)
        {
            /* resume video */
            if (g_slidshow_cntx.is_vdo_opened && SLIDSHOW_VIDEO_PAUSE == g_slidshow_cntx.v_state)
            {
            #ifdef SLIDSHOW_POWER_SAVING
                TurnOnBacklight(0);
            #endif

                if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
                {
                #ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
                    mdi_video_set_hw_rotator(GDI_LAYER_ROTATE_90);
                #endif
                }

                mdi_audio_set_volume(VOL_TYPE_MEDIA, g_slidshow_cntx.audio_volume);
                /* check for situations that the video has finished but it still in pause state. */
                mdi_video_ply_get_cur_play_time(&ms_current_play_time);
                if ((ms_current_play_time == g_slidshow_cntx.play_time) && (ms_current_play_time < g_slidshow_cntx.vdo_total_duration))
                {   
                #ifdef __DRM_SUPPORT__
                    /* don't consume drm right when resume video */
                    mdi_video_ply_drm_disable_consume_count();
                #endif /* __DRM_SUPPORT__ */
                
                #ifdef GDI_USING_LAYER_BACKGROUND
                    flg_blt = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
                    flg_play = GDI_LAYER_ENABLE_LAYER_0;
                #else  /* GDI_USING_LAYER_BACKGROUND */
                    flg_blt = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
                    flg_play = GDI_LAYER_ENABLE_LAYER_1;
                #endif /* GDI_USING_LAYER_BACKGROUND */
                    g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_PLAYING;

                    g_slidshow_cntx.is_video_play_finished = MMI_FALSE;
                    g_slidshow_cntx.is_stop_resume = MMI_FALSE;

                    if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
                    {
                    #ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
                        ret = mdi_video_ply_play(
                            g_slidshow_cntx.play_layer_handle,
                            flg_blt,
                            flg_play,
                            1,                              /* repeat count */
                            TRUE,                           /* update to LCM or not */
                            TRUE,                           /* play aud */
                            MDI_DEVICE_SPEAKER2,            /* speaker & earphone */
                            0,                              /* rotate */
                            100,                            /* 1x play speed */
                            mmi_slidshow_play_finish_callback);    /* hook callback */
                    #else
                    ret = mdi_video_ply_play(
                            g_slidshow_cntx.play_layer_handle,
                            flg_blt,
                            flg_play,
                            1,                              /* repeat count */
                            TRUE,                           /* update to LCM or not */
                            TRUE,                           /* play aud */
                            MDI_DEVICE_SPEAKER2,            /* speaker & earphone */
                            (U16)(g_slidshow_cntx.is_horz_view_set ? MDI_VIDEO_LCD_ROTATE_270 : MDI_VIDEO_LCD_ROTATE_0),       /* rotate */
                            100,                            /* 1x play speed */
                            mmi_slidshow_play_finish_callback);    /* hook callback */
                    #endif
                    }
                    else
                    {
                        ret = mdi_video_ply_play(
                            g_slidshow_cntx.play_layer_handle,
                            flg_blt,
                            flg_play,
                            1,                              /* repeat count */
                            TRUE,                           /* update to LCM or not */
                            TRUE,                           /* play aud */
                            MDI_DEVICE_SPEAKER2,            /* speaker & earphone */
                            (U16)(g_slidshow_cntx.is_horz_view_set ? MDI_VIDEO_LCD_ROTATE_270 : MDI_VIDEO_LCD_ROTATE_0),       /* rotate */
                            100,                            /* 1x play speed */
                            mmi_slidshow_play_finish_callback);    /* hook callback */
                    }
                }
                else
                {
                    /* video has already finished. */
                    g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_STOP;
                    gui_start_timer(SLIDSHOW_KEY_PRESS_DELAY, mmi_slidshow_auto_next);
                }
            }
            else
            {
                /* video stopped (error/finished). resume play next slide. */
                gui_start_timer(SLIDSHOW_KEY_PRESS_DELAY, mmi_slidshow_auto_next);
            }
        }
        else
    #endif /* __MMI_VIDEO_PLAY_SUPPORT__  */
        {
        	  S32 n_audio_result;
        	
            /* resume image */
            gui_start_timer(g_slidshow_cntx.speed_value, mmi_slidshow_auto_next);
            if (g_slidshow_cntx.is_bgm_set == BACKGROUND_MUSIC_ON)
            {
                mmi_slideshow_get_stored_file_path((PS8)audio_buffer, NVRAM_EF_SLIDE_SHOW_AUDIO_LID);
            #if 0
/* under construction !*/
/* under construction !*/
            #endif
            #if 0
            #ifdef __GAIN_TABLE_SUPPORT__
/* under construction !*/
            #endif
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
                mdi_audio_resume(NULL, NULL);
                if (n_audio_result != MDI_AUDIO_SUCCESS)
                {
                    g_slidshow_cntx.is_valid_bgm = FALSE;
                }
                else
                {
                    g_slidshow_cntx.is_valid_bgm = TRUE;
                }
                g_slidshow_cntx.is_bgm_play = FALSE;
            }
        }
    }
    else if (g_slidshow_cntx.is_video_file || !(g_slidshow_cntx.is_animation && g_slidshow_cntx.h_animate == 0))
    {
        /*if video play finished, and */
        if (g_slidshow_cntx.is_video_play_finished)
        {
            g_slidshow_cntx.is_stop_resume = MMI_TRUE;
        }

        /* Pause */
        g_slidshow_cntx.is_edited = TRUE;
        gui_cancel_timer(mmi_slidshow_auto_next);
        gui_cancel_timer(mmi_slidshow_apply_index_change);
        g_slidshow_cntx.idx2shift = 0;          /* timer may up, so reset the shift index */
    #ifdef __MMI_VIDEO_PLAY_SUPPORT__        
        if (g_slidshow_cntx.is_video_file && g_slidshow_cntx.is_vdo_opened )
        {
            /* pause video */
            if (g_slidshow_cntx.v_state == SLIDSHOW_VIDEO_PLAYING)
            {
                mdi_video_ply_stop();
                
                mdi_video_ply_get_cur_play_time(&g_slidshow_cntx.play_time);
                g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_PAUSE;
            }
        }
        else
    #endif /* __MMI_VIDEO_PLAYER */
        {
            /* playing images, pause background music. */
            if (g_slidshow_cntx.is_bgm_set == BACKGROUND_MUSIC_ON)
            {
            #if 0
/* under construction !*/
            #endif
                mdi_audio_pause(NULL, NULL);
                mdi_audio_get_progress_time(&g_slidshow_cntx.curr_play_time);

                g_slidshow_cntx.is_bgm_play = TRUE;
            }
        }

    #ifdef SLIDSHOW_POWER_SAVING
        gui_start_timer(SLIDSHOW_POW_SAVE_DELAY, mmi_slidshow_turn_off_bl_hdlr);
    #endif
    
    }
    mmi_slidshow_show_press_release_softkey();

/*    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_rsk_press
 * DESCRIPTION
 *  rsk press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_rsk_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_slidshow_cntx.osd_opacity)
    {
        mmi_slidshow_osd_show_up();
        return;
    }
    if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) || (g_slidshow_cntx.is_video_file))
    {
        mmi_slidshow_reset_osd_fade(TRUE);
    }
    g_slidshow_cntx.is_rsk_pressed = TRUE;
    mmi_slidshow_show_press_release_softkey();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_rsk_release
 * DESCRIPTION
 *  rsk release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_rsk_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_slidshow_cntx.is_rsk_pressed)
    {
        return;
    }
    g_slidshow_cntx.is_rsk_pressed = FALSE;
    if (!g_slidshow_cntx.osd_opacity)
    {
        mmi_slidshow_main_draw_osd();
        mmi_slidshow_osd_show_up();
        return;
    }
    else
    {
        mmi_slidshow_main_draw_osd();
        gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
    }

    gui_cancel_timer(mmi_slidshow_osd_fade_cyclic);
    
    if ((g_slidshow_cntx.is_bgm_set) && (!g_slidshow_cntx.is_edited))
    {
        mdi_audio_get_progress_time(&g_slidshow_cntx.curr_play_time);
        mdi_audio_stop_file();
    }
    /* enter pause state */
    g_slidshow_cntx.is_edited = TRUE;
    g_slidshow_cntx.is_hilite_change = MMI_TRUE;;
    if (g_slidshow_cntx.v_state == SLIDSHOW_VIDEO_PAUSE)
    {
        g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_STOP;
    }   
    gui_cancel_timer(mmi_slidshow_apply_index_change);
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_hilight_setting
 * DESCRIPTION
 *  highlight setting game
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_hilight_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetLeftSoftkeyFunction(mmi_slidshow_entry_setting_screen, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_setting_screen
 * DESCRIPTION
 *  entry point for slide show setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
typedef enum
{
    MMI_SLIDESHOW_SETTING_TYPE_CAPTION = 0,
    MMI_SLIDESHOW_SETTING_SPEED_CAPTION,
    MMI_SLIDESHOW_SETTING_EFFECT_CAPTION,
    MMI_SLIDESHOW_SETTING_BGM_CAPTION,
#ifndef __MMI_SLIDESHOW_DISABLE_HORIZONTAL_DISPLAY__
    MMI_SLIDESHOW_SETTING_HORIZONTAL_DISPLAY_CAPTION,
#endif
    MMI_SLIDESHOW_SETTING_SOUND_CAPTION,
    MMI_SLIDESHOW_SETTING_SORT_BY_CAPTION,
    
    MMI_SLIDESHOW_SETTING_TYPE_SELECTOR,
    MMI_SLIDESHOW_SETTING_SPEED_SELECTOR,
    MMI_SLIDESHOW_SETTING_EFFECT_SELECTOR,
    MMI_SLIDESHOW_SETTING_BGM_SELECTOR,
#ifndef __MMI_SLIDESHOW_DISABLE_HORIZONTAL_DISPLAY__
    MMI_SLIDESHOW_SETTING_HORIZONTAL_DISPLAY_SELECTOR,
#endif
    MMI_SLIDESHOW_SETTING_SOUND_SELECTOR,
    MMI_SLIDESHOW_SETTING_SORT_BY_SELECTOR,

    MMI_SLIDESHOW_SETTING_COUNT
} mmi_slideshow_setting_enum;

/**********************************  Type Start  *********************************/
static const cui_inline_item_caption_struct mmi_slideshow_setting_type_caption = 
{
    STR_ID_SLIDSHOW_TYPE_OF_PLAY
};

static const U16 mmi_slideshow_setting_type_str[] =
{
    STR_ID_SLIDSHOW_AUTO_ONCE,
        STR_ID_SLIDSHOW_AUTO_REPEAT,
        STR_GLOBAL_MANUAL
};

static const cui_inline_item_select_struct mmi_slideshow_setting_type_selector = 
{
    3, 0, (U16 *)&mmi_slideshow_setting_type_str[0]
};
/**********************************  Type End  *********************************/

/**********************************  Speed Start  *********************************/
static const cui_inline_item_caption_struct mmi_slideshow_setting_speed_caption = 
{
    STR_ID_SLIDSHOW_SPEED
};
static const U16 mmi_slideshow_setting_speed_str[] =
{
#ifdef __MMI_SLIDESHOW_SPECIFIC_SPEED__
    STR_ID_SLIDSHOW_SPEED_10S,
    STR_ID_SLIDSHOW_SPEED_5S,
    STR_ID_SLIDSHOW_SPEED_1S,
#else
    STR_ID_SLIDSHOW_LOW,
    STR_ID_SLIDSHOW_MEDIUM,
    STR_ID_SLIDSHOW_FAST,
#endif
    0
};
static const cui_inline_item_select_struct mmi_slideshow_setting_speed_selector = 
{
    3, 0, (U16 *)&mmi_slideshow_setting_speed_str[0]
};
/**********************************  Speed End  *********************************/

/**********************************  Effect Start  *********************************/
static const cui_inline_item_caption_struct mmi_slideshow_setting_effect_caption = 
{
    STR_ID_SLIDSHOW_EFFECT
};
static const U16 mmi_slideshow_setting_effect_str[] =
{
    STR_ID_SLIDSHOW_NORMAL,
    STR_ID_SLIDSHOW_FADE_IN,
#ifdef __MMI_SLIDSHOW_WIPE_ENABLE__
    STR_ID_SLIDSHOW_SPLIT,
    STR_ID_SLIDSHOW_WIPE
#else
    STR_ID_SLIDSHOW_SPLIT,
#endif
};
static const cui_inline_item_select_struct mmi_slideshow_setting_effect_selector = 
{
#ifdef __MMI_SLIDSHOW_WIPE_ENABLE__
    4,
#else
    3, 
#endif
    0, (U16 *)&mmi_slideshow_setting_effect_str[0]
};
/**********************************  Effect End  *********************************/

/**********************************  BGM Start  *********************************/
static const cui_inline_item_caption_struct mmi_slideshow_setting_bgm_caption = 
{
    STR_ID_SLIDSHOW_BGM
};
static const U16 mmi_slideshow_setting_bgm_str[] =
{
    STR_GLOBAL_OFF,
    STR_ID_SLIDSHOW_SELECT_BGM
};
static const cui_inline_item_select_struct mmi_slideshow_setting_bgm_selector = 
{
    2, 0, (U16 *)&mmi_slideshow_setting_bgm_str[0]
};
/**********************************  BGM End  *********************************/

/**********************************  Horizontal DIsplay Start  *********************************/
#ifndef __MMI_SLIDESHOW_DISABLE_HORIZONTAL_DISPLAY__
static const cui_inline_item_caption_struct mmi_slideshow_setting_horizontal_display_caption = 
{
    STR_ID_SLIDSHOW_HORIZONTAL_DISPLAY
};
static const U16 mmi_slideshow_setting_horizontal_display_str[] =
{
    STR_GLOBAL_OFF,
    STR_GLOBAL_ON
};
static const cui_inline_item_select_struct mmi_slideshow_setting_horizontal_display_selector = 
{
    2, 0, (U16 *)&mmi_slideshow_setting_horizontal_display_str[0]
};
#endif
/**********************************  Horizontal DIsplay End  *********************************/

/**********************************  Sound Start  *********************************/
static const cui_inline_item_caption_struct mmi_slideshow_setting_sound_caption = 
{
    STR_ID_SLIDSHOW_SOUND_EFFECT
};
static const U16 mmi_slideshow_setting_sound_str[] =
{
    STR_GLOBAL_OFF,
    STR_ID_SLIDSHOW_AUD1,
    STR_ID_SLIDSHOW_AUD2,
    STR_ID_SLIDSHOW_AUD3
};
static const cui_inline_item_select_struct mmi_slideshow_setting_sound_selector = 
{
    3, 0, (U16 *)&mmi_slideshow_setting_sound_str[0]
};
/**********************************  Sound End  *********************************/

/**********************************  Sort By Start  *********************************/
static const cui_inline_item_caption_struct mmi_slideshow_setting_sort_by_caption = 
{
    STR_GLOBAL_SORT_BY
};
static const U16 mmi_slideshow_setting_sort_by_str[] =
{
    STR_GLOBAL_NONE,
    STR_FMGR_SORT_BY_NAME,
    STR_FMGR_SORT_BY_TYPE,
    STR_FMGR_SORT_BY_TIME,
    STR_FMGR_SORT_BY_SIZE
};
static const cui_inline_item_select_struct mmi_slideshow_setting_sort_by_selector = 
{
    5, 0, (U16 *)&mmi_slideshow_setting_sort_by_str[0]
};
/**********************************  Sort By End  *********************************/

static const cui_inline_set_item_struct mmi_slideshow_setting_inline_item[] = 
{
    {CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_TYPE_CAPTION,	                CUI_INLINE_ITEM_TYPE_CAPTION,   
        IMG_GLOBAL_L1 + MMI_SLIDESHOW_SETTING_TYPE_CAPTION,  (void*)&mmi_slideshow_setting_type_caption},
    {CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_TYPE_SELECTOR,	                CUI_INLINE_ITEM_TYPE_SELECT,    
        0,                                                  (void*)&mmi_slideshow_setting_type_selector},
    {CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_SPEED_CAPTION,	                CUI_INLINE_ITEM_TYPE_CAPTION,   
        IMG_GLOBAL_L1 + MMI_SLIDESHOW_SETTING_SPEED_CAPTION,  (void*)&mmi_slideshow_setting_speed_caption},
    {CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_SPEED_SELECTOR,	            CUI_INLINE_ITEM_TYPE_SELECT,    
        0,                                                  (void*)&mmi_slideshow_setting_speed_selector},
    {CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_EFFECT_CAPTION,	            CUI_INLINE_ITEM_TYPE_CAPTION,   
        IMG_GLOBAL_L1 + MMI_SLIDESHOW_SETTING_EFFECT_CAPTION,  (void*)&mmi_slideshow_setting_effect_caption},
    {CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_EFFECT_SELECTOR,	            CUI_INLINE_ITEM_TYPE_SELECT,    
        0,                                                  (void*)&mmi_slideshow_setting_effect_selector},
    {CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_BGM_CAPTION,	                CUI_INLINE_ITEM_TYPE_CAPTION,   
        IMG_GLOBAL_L1 + MMI_SLIDESHOW_SETTING_BGM_CAPTION,  (void*)&mmi_slideshow_setting_bgm_caption},
    {CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_BGM_SELECTOR,	                CUI_INLINE_ITEM_TYPE_SELECT,   
        0,                                                  (void*)&mmi_slideshow_setting_bgm_selector},
#ifndef __MMI_SLIDESHOW_DISABLE_HORIZONTAL_DISPLAY__
    {CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_HORIZONTAL_DISPLAY_CAPTION,	CUI_INLINE_ITEM_TYPE_CAPTION,    
        IMG_GLOBAL_L1 + MMI_SLIDESHOW_SETTING_HORIZONTAL_DISPLAY_CAPTION,  (void*)&mmi_slideshow_setting_horizontal_display_caption},
    {CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_HORIZONTAL_DISPLAY_SELECTOR,	CUI_INLINE_ITEM_TYPE_SELECT,   
        0,                                                  (void*)&mmi_slideshow_setting_horizontal_display_selector},
#endif
    {CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_SOUND_CAPTION,	                CUI_INLINE_ITEM_TYPE_CAPTION,    
        IMG_GLOBAL_L1 + MMI_SLIDESHOW_SETTING_SOUND_CAPTION,  (void*)&mmi_slideshow_setting_sound_caption},
    {CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_SOUND_SELECTOR,	            CUI_INLINE_ITEM_TYPE_SELECT,   
        0,                                                  (void*)&mmi_slideshow_setting_sound_selector},
    {CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_SORT_BY_CAPTION,	            CUI_INLINE_ITEM_TYPE_CAPTION,    
        IMG_GLOBAL_L1 + MMI_SLIDESHOW_SETTING_SORT_BY_CAPTION, (void*)&mmi_slideshow_setting_sort_by_caption},
    {CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_SORT_BY_SELECTOR,	            CUI_INLINE_ITEM_TYPE_SELECT,   
        0,                                                  (void*)&mmi_slideshow_setting_sort_by_selector}
};

static const cui_inline_struct mmi_slideshow_setting_inline_cntx = 
{
    MMI_SLIDESHOW_SETTING_COUNT,
    STR_GLOBAL_SETTINGS,
    0,
    CUI_INLINE_SCREEN_LOOP, 
    NULL, 
    mmi_slideshow_setting_inline_item 
};


static void mmi_slideshow_setting_init_inline_item_value(MMI_ID inline_id)
{
    slidshow_nvram_data_struct *p_setting = &g_slidshow_cntx.setting;

    if (g_slidshow_cntx.is_from_other_app)
    {
        cui_inline_delete_item(inline_id, CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_SORT_BY_CAPTION);
        cui_inline_delete_item(inline_id, CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_SORT_BY_SELECTOR);
    }

    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_TYPE_SELECTOR, 
        (void *)(p_setting->type_of_play));
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_SPEED_SELECTOR, 
        (void *)(p_setting->speed));
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_EFFECT_SELECTOR, 
        (void *)(p_setting->effect));
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_BGM_SELECTOR, 
        (void *)(p_setting->bgm));
#ifndef __MMI_SLIDESHOW_DISABLE_HORIZONTAL_DISPLAY__
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_HORIZONTAL_DISPLAY_SELECTOR, 
        (void *)(p_setting->horz));
#endif
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_SOUND_SELECTOR, 
        (void *)(p_setting->sound_effect));
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_SORT_BY_SELECTOR, 
        (void *)(p_setting->file_sort_type));
}

static void mmi_slideshow_setting_change_item_content(cui_event_inline_notify_struct *notify)
{
    slidshow_nvram_data_struct *p_setting = &g_slidshow_cntx.setting;

    switch(notify->item_id - CUI_INLINE_ITEM_ID_BASE)
    {
    case MMI_SLIDESHOW_SETTING_TYPE_SELECTOR:
        p_setting->type_of_play = notify->param;
        break;

    case MMI_SLIDESHOW_SETTING_SPEED_SELECTOR:
        p_setting->speed = notify->param;
        break;

    case MMI_SLIDESHOW_SETTING_EFFECT_SELECTOR:
        p_setting->effect = notify->param;
        break;

    case MMI_SLIDESHOW_SETTING_BGM_SELECTOR:
        p_setting->bgm = notify->param;
        if (notify->param == SLIDSHOW_BGM_SELECT)
        {
            cui_inline_set_softkey_text(notify->sender_id, (U16)notify->item_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_OPTIONS);
            SetLeftSoftkeyFunction(mmi_slideshow_entry_file_option, KEY_EVENT_UP);
            if (mmi_frm_kbd_is_key_supported(KEY_CSK))
            {
                cui_inline_set_softkey_icon(notify->sender_id, (U16)notify->item_id, MMI_CENTER_SOFTKEY, IMG_GLOBAL_COMMON_CSK);
                if (mmi_ucs2strlen(g_slidshow_cntx.audio_file_path) != 0)
                {
                    SetCenterSoftkeyFunction(mmi_slidshow_entry_audio_file_play, KEY_EVENT_UP);
                }
                else
                {
                    SetCenterSoftkeyFunction(mmi_slidshow_entry_select_audio, KEY_EVENT_UP);
                }
            }
        }
        else
        {
            cui_inline_set_softkey_text(notify->sender_id, (U16)notify->item_id, MMI_LEFT_SOFTKEY, 0);
            if (mmi_frm_kbd_is_key_supported(KEY_CSK))
            {
                cui_inline_set_softkey_icon(notify->sender_id, (U16)notify->item_id, MMI_CENTER_SOFTKEY, 0);
                SetCenterSoftkeyFunction(UI_dummy_function, KEY_EVENT_UP);
                SetKeyHandler(UI_dummy_function, KEY_ENTER, KEY_EVENT_UP);
            }
        }
        break;

#ifndef __MMI_SLIDESHOW_DISABLE_HORIZONTAL_DISPLAY__
    case MMI_SLIDESHOW_SETTING_HORIZONTAL_DISPLAY_SELECTOR:
        p_setting->horz = notify->param;
        break;
#endif

    case MMI_SLIDESHOW_SETTING_SOUND_SELECTOR:
        p_setting->sound_effect = notify->param;
        break;

    case MMI_SLIDESHOW_SETTING_SORT_BY_SELECTOR:
        p_setting->file_sort_type = notify->param;
        break;
    }
}


static void mmi_slideshow_check_bgm_item(mmi_event_struct *evt)
{
    FS_HANDLE h_file;
    PS8 buf_filename;
    cui_event_inline_notify_struct *notify = (cui_event_inline_notify_struct *)evt;
#if !defined( __MMI_SHOW_DAF_FILE_EXT__)    
    PS8 ext_name;
#endif /* defined( __MMI_SHOW_DAF_FILE_EXT__) */
    slidshow_nvram_data_struct *p_setting = &g_slidshow_cntx.setting;
    static const cui_inline_item_select_struct mmi_slideshow_setting_bgm_selector = 
    {
        2, 0, (U16 *)&mmi_slideshow_setting_bgm_str[0]
    };

    if (g_slidshow_cntx.cat57_done_flag)
    {
          cui_inline_set_screen_attributes(notify->sender_id, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_SCREEN_CHANGED);
    }

    if (g_slidshow_cntx.setting.bgm)
    {
        /* to save code size, we use layer buffer in slideshow to store file path
        if this line is asserted, we have to allocate a global static array for buf_filename */
        ASSERT((SRV_FMGR_PATH_MAX_LEN+1) <= SLIDESHOW_FRAME_BUFFER_SIZE);
        ASSERT(g_slidshow_layer1_buffer != NULL);
        buf_filename = (PS8) g_slidshow_layer1_buffer;        
        
        g_slidshow_cntx.is_bgmusic_selected = TRUE;
        
        /* check if the file exists */
        h_file = FS_Open((U16 *) g_slidshow_cntx.audio_file_path, FS_READ_ONLY);
        if (h_file >= FS_NO_ERROR )
        {
            FS_Close(h_file);
            /* handle short filename */
            
                mmi_wcscpy(
                    (WCHAR*)buf_filename,
                    (WCHAR*)(g_slidshow_cntx.audio_file_path + srv_fmgr_path_get_filename_pos((WCHAR*)g_slidshow_cntx.audio_file_path) * 2));
            
#if !defined(__MMI_SHOW_FILE_EXT__) 
            if (srv_fmgr_path_get_extension_ptr((WCHAR*)buf_filename)!= NULL)
            {
                srv_fmgr_path_hide_extension((WCHAR*)buf_filename);
            }
#elif !defined( __MMI_SHOW_DAF_FILE_EXT__)
            if(srv_fmgr_types_find_type_by_filename_str((WCHAR*)buf_filename) == FMGR_TYPE_DAF || 
                srv_fmgr_types_find_type_by_filename_str((WCHAR*)buf_filename) == FMGR_TYPE_MP2)
            {
                ext_name = (PS8)srv_fmgr_path_get_extension_ptr((WCHAR*)buf_filename);
                ext_name -= 2;  /* '.' */
                *ext_name = *(ext_name+1) =  '\0';
            }
#endif
            
        }
        else
        {
            mmi_wcscpy(
                (WCHAR*)buf_filename,
                (WCHAR*)GetString((U16) (STR_ID_SLIDSHOW_SELECT_BGM)));
            p_setting->bgm = 0;
            /* clean audio_file_path */
            g_slidshow_cntx.audio_file_path[0] = g_slidshow_cntx.audio_file_path[1] = 0;
        }

        if (mmi_wcslen((WCHAR*)g_slidshow_cntx.audio_file_path) != 0)
        {
            g_slidshow_cntx.bgm_str[0] = (WCHAR*)GetString(STR_GLOBAL_OFF);
            g_slidshow_cntx.bgm_str[1] = (WCHAR*)buf_filename;
            cui_inline_set_item_select(notify->sender_id, CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_BGM_SELECTOR, 2, 
                (void*)&g_slidshow_cntx.bgm_str[0], 1);
        }
        else
        {
            g_slidshow_cntx.bgm_str[0] = (WCHAR*)GetString(STR_GLOBAL_OFF);
            g_slidshow_cntx.bgm_str[1] = (WCHAR*)GetString(STR_ID_SLIDSHOW_SELECT_BGM);

            cui_inline_set_item_select(notify->sender_id, CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_BGM_SELECTOR, 2, 
                (void*)&g_slidshow_cntx.bgm_str[0], 1);
        }
    }
}


static mmi_ret mmi_slideshow_setting_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    /**********************Inline CUI event*************************/
    case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *notify = (cui_event_inline_notify_struct *)evt;
            if (notify->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED)
            {
                mmi_slideshow_setting_change_item_content(notify);
            }
        }
        break;
        
    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        mmi_slideshow_check_bgm_item(evt);
        break;
        
    case EVT_ID_CUI_INLINE_SET_KEY:
        break;
        
    case EVT_ID_CUI_INLINE_CSK_PRESS:
    case EVT_ID_CUI_INLINE_SUBMIT:
        {
            cui_event_inline_set_key_struct *inline_evt = (cui_event_inline_set_key_struct *)evt;
            
            mmi_slidshow_setting_screen_confirm_save();
        }
        break;
        
    case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_set_key_struct *inline_evt = (cui_event_inline_set_key_struct *)evt;
            
            cui_inline_close(inline_evt->sender_id);
        }
        break;
    
    case EVT_ID_POPUP_QUIT:
        break;
    }

    return MMI_RET_OK;
}


static void mmi_slidshow_entry_setting_screen(void)
{
    MMI_ID inline_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.cat57_done_flag = FALSE;
    mmi_frm_group_create(g_slidshow_cntx.cur_gid, SCR_ID_SLIDSHOW_SETTING, mmi_slideshow_setting_group_proc, (void*)NULL); 
    mmi_frm_group_enter(SCR_ID_SLIDSHOW_SETTING, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    g_slidshow_cntx.setting_gid = inline_id = cui_inline_create(SCR_ID_SLIDSHOW_SETTING, &mmi_slideshow_setting_inline_cntx);
    mmi_slideshow_setting_init_inline_item_value(inline_id);
    cui_inline_set_title_icon(inline_id, GetRootTitleIcon(MENU_ID_SLIDSHOW_APP));
    cui_inline_run(inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_exit_setting_screen
 * DESCRIPTION
 *  exit slide show setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_exit_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GenericExitInlineScreen(SCR_ID_SLIDSHOW_SETTING, mmi_slidshow_entry_setting_screen);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_setting_screen_confirm_save
 * DESCRIPTION
 *  popup confirm for slideshow setting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_setting_screen_confirm_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_slideshow_confirm_display(
        g_slidshow_cntx.cur_gid,
        (UI_string_type)get_string(STR_GLOBAL_SAVE_ASK),
        CNFM_TYPE_YESNO,
        (void*) MMI_SLIDESHOW_CONFIRM_SAVE_SETTING,
        MMI_FRM_SCREEN_ROTATE_0);

    SetLeftSoftkeyFunction(mmi_slidshow_setting_inline_done_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_slidshow_setting_save_confirm_no, KEY_EVENT_UP);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_GoBackHistory2
 * DESCRIPTION
 *  popup confirm for slideshow setting screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_setting_save_confirm_no(void)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_slidshow_cntx.cat57_done_flag)
    {
        if (!g_slidshow_cntx.audio_file_path)
        {
            MMI_ASSERT(0);
        }
        mmi_slideshow_get_stored_file_path((PS8)g_slidshow_cntx.audio_file_path, NVRAM_EF_SLIDE_SHOW_AUDIO_LID);
    }
    mmi_slidshow_load_setting();

    mmi_frm_group_close(SCR_ID_SLIDSHOW_SETTING);
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_setting_inline_done_hdlr
 * DESCRIPTION
 *  done hdlr for slide show setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_setting_inline_done_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    slidshow_nvram_data_struct *p_setting = &g_slidshow_cntx.setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* type of play */
    cui_inline_get_value(g_slidshow_cntx.setting_gid, CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_TYPE_SELECTOR, 
        &p_setting->type_of_play);
    cui_inline_get_value(g_slidshow_cntx.setting_gid, CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_SPEED_SELECTOR, 
        &p_setting->speed);
    cui_inline_get_value(g_slidshow_cntx.setting_gid, CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_EFFECT_SELECTOR, 
        &p_setting->effect);
    cui_inline_get_value(g_slidshow_cntx.setting_gid, CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_BGM_SELECTOR, 
        &p_setting->bgm);
#ifndef __MMI_SLIDESHOW_DISABLE_HORIZONTAL_DISPLAY__
    cui_inline_get_value(g_slidshow_cntx.setting_gid, CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_HORIZONTAL_DISPLAY_SELECTOR, 
        &p_setting->horz);
#endif
    cui_inline_get_value(g_slidshow_cntx.setting_gid, CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_SOUND_SELECTOR, 
        &p_setting->sound_effect);
    cui_inline_get_value(g_slidshow_cntx.setting_gid, CUI_INLINE_ITEM_ID_BASE + MMI_SLIDESHOW_SETTING_SORT_BY_SELECTOR, 
        &p_setting->file_sort_type);
    /* speed */

    g_slidshow_cntx.is_typeofplay_set = p_setting->type_of_play;
    g_slidshow_cntx.is_speed_set = p_setting->speed;

    switch (g_slidshow_cntx.is_speed_set)
    {
        case SLIDSHOW_LOW:
            g_slidshow_cntx.speed_value = SLIDSHOW_LOW_SPEED;
            break;

        case SLIDSHOW_MEDIUM:
            g_slidshow_cntx.speed_value = SLIDSHOW_MEDIUM_SPEED;
            break;

        case SLIDSHOW_FAST:
            g_slidshow_cntx.speed_value = SLIDSHOW_FAST_SPEED;
            break;

        default:
            g_slidshow_cntx.speed_value = SLIDSHOW_MEDIUM_SPEED;
            break;
    }

    /* Effect */

    g_slidshow_cntx.is_effect_set = p_setting->effect;

    if (g_slidshow_cntx.is_effect_set == SLIDSHOW_EFFECT_RANDOM)
    {
        g_slidshow_cntx.is_random_effect = TRUE;
    }
    else
    {
        g_slidshow_cntx.is_random_effect = FALSE;
    }

    /* BGM */
    if (!g_slidshow_cntx.audio_file_path)
    {
        MMI_ASSERT(0);
    }
    g_slidshow_cntx.is_bgm_set = p_setting->bgm;
    if (g_slidshow_cntx.is_bgm_set)
    {
        if (mmi_wcslen((WCHAR*)g_slidshow_cntx.audio_file_path) == 0)
        {
            g_slidshow_cntx.is_bgm_set = p_setting->bgm = 0;
        }
        else
        {
            mmi_slideshow_save_stored_file_path((PS8)g_slidshow_cntx.audio_file_path, NVRAM_EF_SLIDE_SHOW_AUDIO_LID);
        }
    }
    else
    {
        memset(g_slidshow_cntx.audio_file_path, 0,SRV_FMGR_PATH_BUFFER_SIZE);
    }


    /* horz display */

    g_slidshow_cntx.is_horz_view_set = p_setting->horz;

    /* Sound Effect */
    g_slidshow_cntx.is_sound_effect_selected = p_setting->sound_effect;

    /* store setting to nvram */
    mmi_slidshow_store_setting();

    mmi_slideshow_popup_display(
        g_slidshow_cntx.cur_gid,
        (UI_string_type) GetString(STR_GLOBAL_SAVED),
        MMI_EVENT_SUCCESS,
        (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_NONE,
            MMI_FRM_SCREEN_ROTATE_0);
    g_slidshow_cntx.is_edited = FALSE;
    g_slidshow_cntx.is_hilite_change = MMI_TRUE;
    mmi_frm_group_close(SCR_ID_SLIDSHOW_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_load_setting
 * DESCRIPTION
 *  load setting from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    slidshow_nvram_data_struct *p_setting = &g_slidshow_cntx.setting;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* load data from nvram */
    mmi_slidshow_load_data();

    g_slidshow_cntx.is_typeofplay_set = p_setting->type_of_play;

    g_slidshow_cntx.is_speed_set = p_setting->speed;

    switch (g_slidshow_cntx.is_speed_set)
    {
        case SLIDSHOW_LOW:
            g_slidshow_cntx.speed_value = SLIDSHOW_LOW_SPEED;
            break;

        case SLIDSHOW_MEDIUM:
            g_slidshow_cntx.speed_value = SLIDSHOW_MEDIUM_SPEED;
            break;

        case SLIDSHOW_FAST:
            g_slidshow_cntx.speed_value = SLIDSHOW_FAST_SPEED;
            break;

        default:
            g_slidshow_cntx.speed_value = SLIDSHOW_MEDIUM_SPEED;
            break;
    }

    g_slidshow_cntx.is_effect_set = p_setting->effect;

    if (g_slidshow_cntx.is_effect_set == SLIDSHOW_EFFECT_RANDOM)
    {
        g_slidshow_cntx.is_random_effect = TRUE;
    }

    g_slidshow_cntx.is_bgm_set = p_setting->bgm;

    if (!g_slidshow_cntx.audio_file_path)
    {
        MMI_ASSERT(0);
    }
    if (g_slidshow_cntx.is_bgm_set)
    {
        mmi_slideshow_get_stored_file_path((PS8)g_slidshow_cntx.audio_file_path, NVRAM_EF_SLIDE_SHOW_AUDIO_LID);
    }
    else
    {
        g_slidshow_cntx.audio_file_path[0] = g_slidshow_cntx.audio_file_path[1] = '\0';
    }

    g_slidshow_cntx.is_horz_view_set = p_setting->horz;

    g_slidshow_cntx.is_sound_effect_selected = p_setting->sound_effect;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_store_setting
 * DESCRIPTION
 *  store setting to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_store_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_slidshow_store_data();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_select_audio
 * DESCRIPTION
 *  entry select audio from file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_entry_select_audio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET_AUDIO(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    #ifdef __DRM_V02__
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
    #endif /* __DRM_V02__ */

    if (!mmi_frm_group_is_present(SCR_ID_SLIDSHOW_BGM_FILE_OPTION))
    {
        mmi_frm_group_create(g_slidshow_cntx.cur_gid, SCR_ID_SLIDSHOW_BGM_FILE_OPTION, mmi_slideshow_bgm_option_menu_group_proc, (void*)NULL); 
    
        mmi_frm_group_enter(SCR_ID_SLIDSHOW_BGM_FILE_OPTION, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    g_slidshow_cntx.fmgr_service_id_of_select_audio = cui_file_selector_create(SCR_ID_SLIDSHOW_BGM_FILE_OPTION, (WCHAR*)L"root", &filter, CUI_FILE_SELECTOR_STYLE_FILE_ONLY, 
        CUI_FILE_SELECTOR_OPT_DRM_CHECK_SET_ON | CUI_FOLDER_SELECTOR_OPT_FIXED_PATH_ON);
    
    if (g_slidshow_cntx.fmgr_service_id_of_select_audio > 0)
    {
        cui_file_selector_set_userdata(g_slidshow_cntx.fmgr_service_id_of_select_audio, MMI_SLIDESHOW_FMGR_SELECT_BGM_FILE);
        cui_file_selector_run(g_slidshow_cntx.fmgr_service_id_of_select_audio);
    }
    else
    {
        mmi_slideshow_popup_display(
            g_slidshow_cntx.cur_gid,
            (UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE),
            MMI_EVENT_FAILURE,
            (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_NONE,
            MMI_FRM_SCREEN_ROTATE_0);
    }

    ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_fmgr_select_audio_result_callback
 * DESCRIPTION
 *  select folder result callback function
 * PARAMETERS
 *  filepath        [?]         
 *  filename(?)     [IN]        Filename(not used here)
 *  is_shot(?)      [IN]        Is it short naming
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_fmgr_select_audio_result_callback(void *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filepath == NULL)
    {
        mmi_slidshow_exit_hdlr();
        g_slidshow_cntx.fmgr_service_id_of_select_audio = 0;
        return;
    }
    else
    {
        if (!g_slidshow_cntx.audio_file_path)
        {
            MMI_ASSERT(0);
        }
        mmi_wcscpy((WCHAR*)g_slidshow_cntx.audio_file_path, (WCHAR*) filepath);
        g_slidshow_cntx.setting.bgm = TRUE;
        mmi_slideshow_popup_display(
            g_slidshow_cntx.cur_gid,
            (UI_string_type) GetString(STR_GLOBAL_DONE),
            MMI_EVENT_SUCCESS,
            (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_NONE,
            MMI_FRM_SCREEN_ROTATE_0);
        g_slidshow_cntx.cat57_done_flag = TRUE;
        g_slidshow_cntx.fmgr_service_id_of_select_audio = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_video_screen
 * DESCRIPTION
 *  enter video play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
static void mmi_slidshow_entry_video_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    S32 resized_width;
    S32 resized_height;
    S32 resized_offset_x;
    S32 resized_offset_y;
    PU8 buf_ptr;
    U16 rotate;
    FS_HANDLE fs_handle;
    MDI_RESULT ret = 0;
    mdi_video_info_struct vid_info;
    U32 flg_blt, flg_play;
    MMI_BOOL entry_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* entry new screen */

#ifdef __MMI_BT_SUPPORT__
    if (mmi_bt_is_receiving())
    {
        mmi_slideshow_popup_display(
            g_slidshow_cntx.cur_gid, 
            (UI_string_type) GetString(STR_ID_SLIDSHOW_BT_IS_WORKING), 
            MMI_EVENT_FAILURE, 
            (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP,
                MMI_FRM_SCREEN_ROTATE_0);
        return;
    }
#endif

    entry_ret = mmi_frm_scrn_enter (
        g_slidshow_cntx.cur_gid, 
        SCR_ID_SLIDSHOW_PLAY, 
        mmi_slidshow_exit_video_screen, 
        mmi_slidshow_entry_video_screen, 0);
    if (!entry_ret)
    {
        return;
    }

     mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);

#ifdef __MMI_BT_SUPPORT__
    mmi_bt_disable_receiving();   /* disable BT back ground receive. remember to resume when exit this screen */
#endif

    /* get file name from NVRAM */
    mmi_slideshow_get_stored_file_path((PS8)g_slidshow_cntx.tmp_file_path, NVRAM_EF_SLIDE_SHOW_PATH_LID);

    gui_buffer = mmi_frm_scrn_get_gui_buf(g_slidshow_cntx.cur_gid, SCR_ID_SLIDSHOW_PLAY);

    if (gui_buffer == NULL)
    {
        g_slidshow_cntx.error_code = SLIDESHOW_ERR_NO_ERROR;
    }

#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call())
    {
        g_slidshow_cntx.is_in_background_call = MMI_TRUE;
    }
    else
    {
        g_slidshow_cntx.is_in_background_call = MMI_FALSE;
    }
#endif

    g_slidshow_cntx.is_video_drm_prohibit = MMI_FALSE;
#ifdef __DRM_SUPPORT__
    ret = mdi_video_ply_open_clip_file((PS8)g_slidshow_cntx.tmp_file_path, &vid_info);
    if (ret == MDI_RES_VDOPLY_ERR_DRM_PROHIBITED)
    {
        g_slidshow_cntx.is_vdo_opened = FALSE;      /* redraw osd only, don't need to open vdo */
        g_slidshow_cntx.is_video_drm_prohibit = MMI_TRUE;
        ret = 0;
        mdi_video_ply_close_clip_file(); 
    }
    else
    {
        ret = 0;
        mdi_video_ply_close_clip_file();
    }
#endif

    /*BT control phone sound*/
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_register_volume_sync_callback(APP_SLIDESHOW, MDI_AUD_VOL_LEVEL_NORMAL, mmi_slideshow_hfp_volume_callback);
#endif /* __BT_SPK_VOL_CONTROL__ */
    
    if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW )
    {
#ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
        if (!g_slidshow_cntx.is_in_background_call && !g_slidshow_cntx.is_video_drm_prohibit)
        {
            lcd_width = UI_device_width;
            lcd_height = UI_device_height;
        }
        else
        {
            lcd_width = UI_device_height;
            lcd_height = UI_device_width;
        }
#else
        lcd_width = UI_device_height;
        lcd_height = UI_device_width;
#endif
    }
    else
    {
        lcd_width = UI_device_width;
        lcd_height = UI_device_height;
    }

#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        mdi_tvout_set_owner(MDI_TV_OWNER_APP);
            /* start mode - full screen preview update */
        mdi_tvout_set_mode(MDI_TV_MODE_MULTIMEDIA_FULL_SCR, 0, 0);
    }
#endif /* __MMI_TVOUT__ */

    g_slidshow_cntx.is_left_arrow_pressed = FALSE;
    g_slidshow_cntx.is_right_arrow_pressed = FALSE;
    g_slidshow_cntx.is_lsk_pressed = FALSE;
    g_slidshow_cntx.is_rsk_pressed = FALSE;
    
    /* entry full screen app */
    entry_full_screen();

    gdi_layer_reset_clip();

    /* stop bg music */
    mdi_audio_suspend_background_play();

    /* stop MMI sleep */
    TurnOnBacklight(0);

    /* force all playing keypad tone off */
    srv_profiles_stop_tone(SRV_PROF_TONE_KEYPAD);

    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    /*add this to avoid receive key function from other app screen*/
    ClearKeyEvents();
    
    /* register key hdlr */
    if (!g_slidshow_cntx.error_code)
    {
        /* don't show lsk if it's back from error and video is failed */
        SetKeyHandler(mmi_slidshow_lsk_press, KEY_LSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_slidshow_lsk_release, KEY_LSK, KEY_EVENT_UP);
    }

    SetKeyHandler(mmi_slidshow_rsk_press, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_slidshow_rsk_release, KEY_RSK, KEY_EVENT_UP);
    
    /* set keys */
    mmi_slidshow_set_keys();

    /* get end key hdlr and hook ours */
	mmi_frm_scrn_set_key_proc(g_slidshow_cntx.cur_gid, SCR_ID_SLIDSHOW_PLAY, mmi_slideshow_end_key_proc);

    //g_slidshow_cntx.end_key_hdlr = GetKeyHandler(KEY_END, KEY_EVENT_DOWN);
    //SetKeyHandler(mmi_slidshow_end_key_press, KEY_END, KEY_EVENT_DOWN);

    g_slidshow_cntx.effect_finish = TRUE;
   /*----------------------------------------------------------------*/
   /* Layers                                                         */
   /*----------------------------------------------------------------*/
    gdi_layer_multi_layer_enable();
    gdi_layer_get_base_handle(&g_slidshow_cntx.base_layer_handle);
    if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
    {
#ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
        if (!g_slidshow_cntx.is_in_background_call && !g_slidshow_cntx.is_video_drm_prohibit)
        {
        rotate = GDI_LAYER_ROTATE_0;
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);
        gdi_lcd_set_rotate_by_layer(TRUE);
        }
        else
        {
            rotate = GDI_LAYER_ROTATE_270;
            gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);
            gdi_layer_resize(lcd_width, lcd_height);
            gdi_lcd_set_rotate_by_layer(TRUE);
        }
#else
        rotate = GDI_LAYER_ROTATE_270;
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);
        gdi_layer_resize(lcd_width, lcd_height);
        gdi_lcd_set_rotate_by_layer(TRUE);
#endif
    }
    else
    {
        rotate = GDI_LAYER_ROTATE_0;
    }
    gdi_layer_clear(GDI_COLOR_BLACK);
    
#ifdef GDI_USING_LAYER_BACKGROUND
    gdi_layer_set_background(GDI_COLOR_BLACK);
#endif

    /*if play video, do not play and will popup to notify user*/
    if (!mmi_is_redrawing_bk_screens() && !g_slidshow_cntx.error_code && 
        (!g_slidshow_cntx.is_in_background_call && !g_slidshow_cntx.is_video_drm_prohibit))        /* not small screen */
    {
    #ifdef __DRM_SUPPORT__
        if (gui_buffer != NULL)
        {
            mdi_video_ply_drm_disable_consume_count();  /* do not consume rights if back from interrupt */
        }
    #endif /* __DRM_SUPPORT__ */
    
        /* open video file */
        ret = mdi_video_ply_open_clip_file((PS8)g_slidshow_cntx.tmp_file_path, &vid_info);
        if (ret >= 0)
        {
            g_slidshow_cntx.is_vdo_opened = TRUE;
            g_slidshow_cntx.vdo_total_duration = vid_info.total_time_duration;
            if (g_slidshow_cntx.v_state != SLIDSHOW_VIDEO_PAUSE)
            {
                g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_STOP;
            }
        }
        else
        {
            /* check if it's invalid format or a file not found */
            fs_handle = FS_Open((U16*) g_slidshow_cntx.tmp_file_path, FS_READ_ONLY);
            if (fs_handle < 0 )
            {
                g_slidshow_cntx.osd_layer_buf_ptr = NULL;
                g_slidshow_cntx.osd_layer_handle = 0;
                g_slidshow_cntx.is_video_type = FALSE;
                mmi_slideshow_popup_display(
                    g_slidshow_cntx.cur_gid, 
                    (UI_string_type) GetString(FMGR_FS_FILE_NOT_FOUND_TEXT),
                    MMI_EVENT_FAILURE,
                    (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP,
                MMI_FRM_SCREEN_ROTATE_0);
                return;
            }
            FS_Close(fs_handle);
            g_slidshow_cntx.is_vdo_opened= FALSE;
            g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_CLOSE;
   
        #ifdef __DRM_SUPPORT__         /* valid after 07A*/
            if (ret == MDI_RES_VDOPLY_ERR_DRM_PROHIBITED)              
            {
                g_slidshow_cntx.is_vdo_opened = FALSE;      /* redraw osd only, don't need to open vdo */
                g_slidshow_cntx.play_layer_buf_ptr = NULL;
                g_slidshow_cntx.error_code = SLIDESHOW_ERR_PROHIBIT;
            }
        #endif /* __DRM_SUPPORT__ */   /* valid after 07A*/
        }

        /* create preview layer */
        if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
        {
        #ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
            gdi_image_util_fit_bbox(
                lcd_height,
                lcd_width,
                vid_info.width,
                vid_info.height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);
        #else
        gdi_image_util_fit_bbox(
            lcd_width,
            lcd_height,
            vid_info.width,
            vid_info.height,
            &resized_offset_x,
            &resized_offset_y,
            &resized_width,
            &resized_height);
        #endif
        }
        else
        {
            gdi_image_util_fit_bbox(
                lcd_width,
                lcd_height,
                vid_info.width,
                vid_info.height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);
        }
        
        /*in 6253, h w should be even*/
        if (resized_width & 0x01)
        {
            resized_width++;
        }
        if (resized_height & 0x01)
        {
            resized_height++;
        }
        
        buf_ptr = (PU8) mmi_frm_scrmem_alloc_framebuffer( (resized_width*resized_height*GDI_MAINLCD_BIT_PER_PIXEL)>>3 );
        if (buf_ptr!=NULL)
        {
            g_slidshow_cntx.play_layer_buf_ptr=buf_ptr;
        }
        ASSERT(buf_ptr != NULL);

        if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
        {
        #ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
            #ifdef __MDI_VIDEO_HW_ROTATOR_BY_LCD__
                gdi_layer_create_using_outside_memory(
                    resized_offset_x,
                    resized_offset_y,
                    resized_width,
                    resized_height,
                    &g_slidshow_cntx.play_layer_handle,
                    (PU8) buf_ptr,
                    (S32) ((resized_width*resized_height*GDI_MAINLCD_BIT_PER_PIXEL)>>3) );
                gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
                gdi_layer_set_rotate(GDI_LCD_LAYER_ROTATE_90);
                gdi_layer_pop_and_restore_active();
            #else
                gdi_layer_create_using_outside_memory(
                    resized_offset_y,
                    resized_offset_x,
                    resized_height,
                    resized_width,
                    &g_slidshow_cntx.play_layer_handle,
                    (PU8) buf_ptr,
                    (S32) ((resized_width*resized_height*GDI_MAINLCD_BIT_PER_PIXEL)>>3) );
            #endif
        #else
            gdi_layer_create_using_outside_memory(
                resized_offset_x,
                resized_offset_y,
                resized_width,
                resized_height,
                &g_slidshow_cntx.play_layer_handle,
                (PU8) buf_ptr,
                (S32) ((resized_width*resized_height*GDI_MAINLCD_BIT_PER_PIXEL)>>3) );
        #endif
        }
        else
        {
            gdi_layer_create_using_outside_memory(
                resized_offset_x,
                resized_offset_y,
                resized_width,
                resized_height,
                &g_slidshow_cntx.play_layer_handle,
                (PU8) buf_ptr,
                (S32) ((resized_width*resized_height*GDI_MAINLCD_BIT_PER_PIXEL)>>3) );
        }
    #ifdef GDI_USING_LAYER_BACKGROUND
        gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
        gdi_layer_set_background(GDI_COLOR_BLACK);
        gdi_layer_clear_background(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    #endif
    }
    else
    {
        g_slidshow_cntx.is_vdo_opened = FALSE;      /* redraw osd only, don't need to open vdo */
        g_slidshow_cntx.play_layer_buf_ptr = NULL;

        if (g_slidshow_cntx.is_in_background_call || g_slidshow_cntx.is_video_drm_prohibit) /*should malloc layer for hint display*/
        {
            buf_ptr = (PU8) mmi_frm_scrmem_alloc_framebuffer( (lcd_height*lcd_width*GDI_MAINLCD_BIT_PER_PIXEL)>>3 );
            MMI_ASSERT(buf_ptr);
                if (buf_ptr!=NULL)
                {
                    g_slidshow_cntx.play_layer_buf_ptr=buf_ptr;
                }
                gdi_layer_create_using_outside_memory(
                    0,
                    0,
                    lcd_width,
                    lcd_height,
                    &g_slidshow_cntx.play_layer_handle,
                    (PU8) buf_ptr,
                    (S32) ((lcd_width*lcd_height*GDI_MAINLCD_BIT_PER_PIXEL)>>3) );
                gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
                gdi_layer_clear_background(GDI_COLOR_BLACK);
                gdi_layer_pop_and_restore_active();
        }
    }
    /*----------------------------------------------------------------*/
    /* allocate osd layer                                             */
    /*----------------------------------------------------------------*/
    /* use double buffer for osd layer */
    g_slidshow_cntx.osd_layer_buf_ptr = g_slidshow_layer1_buffer;

    if(g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW) // should see after the rotate
    {
        S32 img_width;
        S32 img_height;
        U8 sk_gap = 2, img_spacing = 3;
        
        mmi_slideshow_horizon_button_bar_width = 0;
        
        gdi_image_get_dimension_id(IMG_ID_SLIDESHOW_SK_PAUSE_UP, &img_width, &img_height);
        if (mmi_slideshow_horizon_button_bar_width < img_width)
        {
            mmi_slideshow_horizon_button_bar_width = img_width;
        }
        
        gdi_image_get_dimension_id(IMG_ID_SLIDESHOW_SK_BACK_UP, &img_width, &img_height);
        if (mmi_slideshow_horizon_button_bar_width < img_width)
        {
            mmi_slideshow_horizon_button_bar_width = img_width;
        }
        
        gdi_image_get_dimension_id(IMG_ID_SLIDSHOW_LEFT_ARROW, &img_width, &img_height);
        if (mmi_slideshow_horizon_button_bar_width < 2 * img_width + sk_gap + img_spacing)
        {
            mmi_slideshow_horizon_button_bar_width = 2 * img_width + sk_gap + img_spacing;
        }
        
        mmi_slideshow_horizon_button_bar_width += MMI_UI_SOFTKEY_GAP;                 

#ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
        if (!g_slidshow_cntx.is_in_background_call && !g_slidshow_cntx.is_video_drm_prohibit)
        {
        gdi_layer_create_cf_double_using_outside_memory(
            GDI_LCD->cf,
            0,
            0,
            lcd_width,
            mmi_slideshow_horizon_button_bar_width,
            &g_slidshow_cntx.osd_layer_handle, 
            g_slidshow_layer1_buffer, 
            SLIDESHOW_FRAME_BUFFER_SIZE, 
            g_slidshow_layer2_buffer, 
            SLIDESHOW_FRAME_BUFFER_SIZE);
        gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
        gdi_layer_set_position(0, lcd_height - mmi_slideshow_horizon_button_bar_width);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);

        g_slidshow_cntx.osd_layer_buf_ptr_of_idp_rotate = g_slidshow_layer3_buffer;
        gdi_layer_create_using_outside_memory(
            0,
            0,
            mmi_slideshow_horizon_button_bar_width,
            lcd_width,
            &g_slidshow_cntx.osd_layer_handle_of_idp_rotate,
            (PU8) g_slidshow_cntx.osd_layer_buf_ptr_of_idp_rotate,
            (S32) SLIDSHOW_FRAME_BUFFER_SIZE);

        gdi_layer_set_active(g_slidshow_cntx.osd_layer_handle_of_idp_rotate);
        //gdi_layer_set_position(lcd_height - mmi_slideshow_horizon_button_bar_width, 0);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        g_slidshow_cntx.is_drawing_video_use_idp = MMI_TRUE;
        gdi_layer_pop_and_restore_active();
        }
        else
        {
            gdi_layer_create_cf_double_using_outside_memory(
                GDI_LCD->cf,
                0,
                0,
                mmi_slideshow_horizon_button_bar_width,
                lcd_height,
                &g_slidshow_cntx.osd_layer_handle, 
                g_slidshow_layer1_buffer, 
                SLIDESHOW_FRAME_BUFFER_SIZE, 
                g_slidshow_layer2_buffer, 
                SLIDESHOW_FRAME_BUFFER_SIZE);

            gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
            gdi_layer_set_position(lcd_width - mmi_slideshow_horizon_button_bar_width, 0);
            gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
            gdi_layer_clear(GDI_COLOR_TRANSPARENT);
            gdi_layer_pop_and_restore_active();
        }
#else
    gdi_layer_create_cf_double_using_outside_memory(
        GDI_LCD->cf,
        0,
        0,
            mmi_slideshow_horizon_button_bar_width,
        lcd_height,
        &g_slidshow_cntx.osd_layer_handle, 
        g_slidshow_layer1_buffer, 
        SLIDESHOW_FRAME_BUFFER_SIZE, 
        g_slidshow_layer2_buffer, 
        SLIDESHOW_FRAME_BUFFER_SIZE);

    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
        gdi_layer_set_position(lcd_width - mmi_slideshow_horizon_button_bar_width, 0);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
#endif
    }
    else
    {
        S32 img_width;
        S32 img_height;
        U8 sk_gap = 2;

        mmi_slideshow_normal_button_bar_height = 0;
        
        gdi_image_get_dimension_id(IMG_ID_SLIDESHOW_SK_PAUSE_UP, &img_width, &img_height);
        if (mmi_slideshow_normal_button_bar_height < img_height)
        {
            mmi_slideshow_normal_button_bar_height = img_height;
        }
        
        gdi_image_get_dimension_id(IMG_ID_SLIDESHOW_SK_BACK_UP, &img_width, &img_height);
        if (mmi_slideshow_normal_button_bar_height < img_height)
        {
            mmi_slideshow_normal_button_bar_height = img_height;
        }
        
        gdi_image_get_dimension_id(IMG_ID_SLIDSHOW_LEFT_ARROW, &img_width, &img_height);
        if (mmi_slideshow_normal_button_bar_height < img_height)
        {
            mmi_slideshow_normal_button_bar_height = img_height;
        }
        
        mmi_slideshow_normal_button_bar_height += sk_gap;
        
        gdi_layer_create_cf_double_using_outside_memory(
            GDI_LCD->cf,
            0,
            0,
            lcd_width,
            mmi_slideshow_normal_button_bar_height,
            &g_slidshow_cntx.osd_layer_handle, 
            g_slidshow_layer1_buffer, 
            SLIDESHOW_FRAME_BUFFER_SIZE, 
            g_slidshow_layer2_buffer, 
            SLIDESHOW_FRAME_BUFFER_SIZE);

        gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
        gdi_layer_set_position(0, lcd_height - mmi_slideshow_normal_button_bar_height);
        gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        gdi_layer_pop_and_restore_active();
    }

    if (!mmi_is_redrawing_bk_screens() && !g_slidshow_cntx.error_code)
    {
    #ifdef GDI_USING_LAYER_BACKGROUND        
        gdi_layer_set_blt_layer(
            g_slidshow_cntx.play_layer_handle, 
            g_slidshow_cntx.osd_layer_handle,
            0,
            0);    
    #else
        gdi_layer_set_blt_layer(
            g_slidshow_cntx.base_layer_handle, 
            g_slidshow_cntx.play_layer_handle, 
            g_slidshow_cntx.osd_layer_handle, 
            0);
    #endif /* GDI_USING_LAYER_BACKGROUND */
    }
    else
    {
        gdi_layer_set_blt_layer(
            g_slidshow_cntx.base_layer_handle, 
            g_slidshow_cntx.osd_layer_handle, 
            0,
            0);    
    }

    /************************************************/
    /* play video                                   */
    /************************************************/
#ifdef __MMI_SUBLCD__
    if (!mmi_is_redrawing_bk_screens() && !g_slidshow_cntx.error_code)
    {
        if (!g_slidshow_cntx.is_sub_display)
        {
            ForceSubLCDScreen(mmi_slidshow_entry_sublcd_screen);
        }
    }
#endif /* __MMI_SUBLCD__ */

    if ( g_slidshow_cntx.v_state == SLIDSHOW_VIDEO_STOP && !g_slidshow_cntx.error_code && 
        (!g_slidshow_cntx.is_in_background_call && !g_slidshow_cntx.is_video_drm_prohibit))
    {
        if (g_slidshow_cntx.is_stop_resume)
        {
            /*manual mode, stop video, popup and then back, should not play*/
        }
        else
        {
            g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_PLAYING;
        }
    }
    /* draw both OSD buffer first. */
    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
    mmi_slidshow_main_draw_osd();       
    gdi_layer_toggle_double();
    mmi_slidshow_main_draw_osd();    
    gdi_layer_pop_and_restore_active();

    if (g_slidshow_cntx.is_vdo_opened && 
        (g_slidshow_cntx.v_state == SLIDSHOW_VIDEO_PLAYING || g_slidshow_cntx.v_state == SLIDSHOW_VIDEO_PAUSE) && 
        (!g_slidshow_cntx.is_in_background_call && !g_slidshow_cntx.is_video_drm_prohibit))
    {
        if (g_slidshow_cntx.is_in_background_call)
        {
            /*show some hint*/
        }
        else
        {
        if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
        {
        #ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
            mdi_video_set_hw_rotator(GDI_LAYER_ROTATE_90);
        #endif
        }
    
        /* Get first frame and start to play */
        if (g_slidshow_cntx.play_time)
        {
            ret = mdi_video_ply_seek_and_get_frame(g_slidshow_cntx.play_time, g_slidshow_cntx.play_layer_handle);
        }
        else
        {
            ret = mdi_video_ply_seek_and_get_frame(0, g_slidshow_cntx.play_layer_handle);
        }

        if (ret >= 0)
        {
            gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
            if (g_slidshow_cntx.v_state == SLIDSHOW_VIDEO_PLAYING)
            {
            #ifdef GDI_USING_LAYER_BACKGROUND
                flg_blt = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
                flg_play = GDI_LAYER_ENABLE_LAYER_0;
            #else  /* GDI_USING_LAYER_BACKGROUND */
                flg_blt = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2;
                flg_play = GDI_LAYER_ENABLE_LAYER_1;
            #endif /* GDI_USING_LAYER_BACKGROUND */
                mdi_audio_set_volume(VOL_TYPE_MEDIA, g_slidshow_cntx.audio_volume);
            
                g_slidshow_cntx.is_video_play_finished = MMI_FALSE;
                g_slidshow_cntx.is_stop_resume = MMI_FALSE;

                ret = mdi_video_ply_play(
                        g_slidshow_cntx.play_layer_handle,
                        flg_blt,
                        flg_play,
                        1,                              /* repeat count */
                        TRUE,                           /* update to LCM or not */
                        TRUE,                           /* play aud */
                        MDI_DEVICE_SPEAKER2,            /* speaker & earphone */
                        rotate,
                        100,                            /* 1x play speed */
                        mmi_slidshow_play_finish_callback);    /* hook callback */
                if(ret < 0)
                {
                    g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_STOP;
                    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
                    gdi_layer_toggle_double();
                    mmi_slidshow_main_draw_osd();                    
                    gdi_layer_pop_and_restore_active();
                    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);                    
                }
                else
                {
                    g_slidshow_cntx.is_stop_resume = MMI_FALSE;
                }
            }
        }
    }
    }
    else if (g_slidshow_cntx.is_stop_resume && (!g_slidshow_cntx.is_in_background_call && !g_slidshow_cntx.is_video_drm_prohibit))
    {
        if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
        {
        #ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
            mdi_video_set_hw_rotator(GDI_LAYER_ROTATE_90);
        #endif
        }
        
        /* Get first frame and start to play */
        mdi_video_ply_seek_and_get_frame(0, g_slidshow_cntx.play_layer_handle);

    }
    else if(g_slidshow_cntx.is_in_background_call)
    {
        /*draw some hint*/
        mdi_util_show_not_available_in_call_hint(g_slidshow_cntx.play_layer_handle, 0, 0, lcd_width, lcd_height);
        gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
    }

    if ((!g_slidshow_cntx.is_vdo_opened || ret < 0) && !g_slidshow_cntx.error_code && 
        !mmi_is_redrawing_bk_screens() && (!g_slidshow_cntx.is_in_background_call && !g_slidshow_cntx.is_video_drm_prohibit))
    {
        /* something wrong, clear play layer */
        gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
        gdi_layer_clear_background(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }

    if (!mmi_is_redrawing_bk_screens())
    {
        if (!g_slidshow_cntx.is_video_type)
        {
            gui_start_timer(SLIDSHOW_OSD_FADE_OUT_TIME, mmi_slidshow_osd_fade_cyclic);
        }
        else if(g_slidshow_cntx.osd_opacity <= 255 && g_slidshow_cntx.osd_opacity > 0)
        {
            gui_cancel_timer(mmi_slidshow_osd_fade_cyclic);
            mmi_slidshow_osd_fade_cyclic();
        }
    }
    else
    {
        gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
        return;
    }

    if (g_slidshow_cntx.is_in_background_call)
    {
        /*do nothing*/
    }
#ifdef __DRM_SUPPORT__
    else if (g_slidshow_cntx.error_code == SLIDESHOW_ERR_PROHIBIT || g_slidshow_cntx.is_video_drm_prohibit)
    {
        if (g_slidshow_cntx.play_layer_handle)
        {
            gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
        gdi_image_get_dimension_id(IMG_ID_FMGR_DRM_LOCKED, &resized_width, &resized_height);
        gdi_image_draw_id( (lcd_width - resized_width)>>1, (lcd_height - resized_height)>>1, IMG_ID_FMGR_DRM_LOCKED);
    #ifdef __MMI_TVOUT__        
        if (mdi_tvout_is_enable())
        {
            mdi_tvout_set_owner(MDI_TV_OWNER_APP);
        }
        mmi_slidshow_draw_img_2_tv(NULL, IMG_ID_FMGR_DRM_LOCKED,resized_width,resized_height, FALSE, TRUE);
    #endif 
        gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
        if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) && (!g_slidshow_cntx.is_edited))
        {
            gui_start_timer(g_slidshow_cntx.speed_value, mmi_slidshow_auto_next);
        }
            gdi_layer_pop_and_restore_active();
        }

#ifdef SLIDSHOW_POWER_SAVING
        if (g_slidshow_cntx.is_edited)
        {
            gui_start_timer(SLIDSHOW_POW_SAVE_DELAY, mmi_slidshow_turn_off_bl_hdlr);
        }
#endif

    }
#endif
    else if ((ret < 0) || (!g_slidshow_cntx.is_vdo_opened && (!g_slidshow_cntx.is_in_background_call && !g_slidshow_cntx.is_video_drm_prohibit)))
    {
    #ifdef __MMI_TVOUT__
        /* restore TV out mode */
        if (mdi_tvout_is_enable() && !g_slidshow_cntx.error_code)
        {
            mdi_tvout_set_owner(MDI_TV_OWNER_GDI);              /* restore back to GDI */
            mdi_tvout_set_mode(
                MDI_TV_MODE_LCD_SCR,
                0,  /* layer_width */
                0); /* layer_height */                          /* restore back to start mode1 */
        }
    #endif /* __MMI_TVOUT__ */ 

        if (gui_buffer == NULL)
        {
            gdi_layer_clear(GDI_COLOR_BLACK);
            gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);       
            g_slidshow_cntx.error_code = SLIDESHOW_ERR_OTHER;
        #ifdef __MMI_SCREEN_ROTATE__            
            if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
            {
                mmi_slideshow_popup_display(
                    g_slidshow_cntx.cur_gid,
                    (UI_string_type) GetString(STR_GLOBAL_INVALID_FORMAT),
                    MMI_EVENT_FAILURE,
                    (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_NONE,
                    MMI_FRM_SCREEN_ROTATE_270);
                return;
            }
            else
        #endif                
            {
                mmi_slideshow_popup_display(
                    g_slidshow_cntx.cur_gid,
                    (UI_string_type) GetString(STR_GLOBAL_INVALID_FORMAT),
                    MMI_EVENT_FAILURE,
                    (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_NONE,
                    MMI_FRM_SCREEN_ROTATE_0);
                return;
            }
        }
        else
        {
            gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
            if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) && (!g_slidshow_cntx.is_edited))
            {
                /*enlarge the timer for user to look the previous one*/
                gui_start_timer(SLIDSHOW_FAST_SPEED, mmi_slidshow_auto_next);
            }
        }
        
        TurnOffBacklight();
        
    }
    g_slidshow_cntx.is_video_type = FALSE;

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_pen_down_handler(mmi_slidshow_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_slidshow_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_slidshow_pen_move_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_exit_video_screen
 * DESCRIPTION
 *  exit video play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_exit_video_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(LCM_ROTATE_SUPPORT)
    BOOL flat_play_layer = g_slidshow_cntx.is_vdo_opened;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_SUPPORT__
    mmi_bt_enable_receiving();   /* enable BT back ground receive. remember to resume when exit this screen */
#endif

#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_clear_volume_sync_callback(APP_SLIDESHOW);
#endif /* __BT_SPK_VOL_CONTROL__ */
    
    gui_cancel_timer(mmi_slidshow_osd_fade_cyclic);
    gui_cancel_timer(mmi_slidshow_auto_next);
    gui_cancel_timer(mmi_slidshow_right_arrow_release);
    gui_cancel_timer(mmi_slidshow_left_arrow_release);
    gui_cancel_timer(mmi_slidshow_apply_index_change);

#ifdef SLIDSHOW_POWER_SAVING
    gui_cancel_timer(mmi_slidshow_turn_off_bl_hdlr);    
#endif

    g_slidshow_cntx.is_bgm_play = TRUE;
        /* stop video playing */
    if (g_slidshow_cntx.play_layer_buf_ptr != NULL && 
        (!g_slidshow_cntx.is_in_background_call && !g_slidshow_cntx.is_video_drm_prohibit))
    {
        mdi_video_ply_stop();
        if (g_slidshow_cntx.is_video_play_finished)
        {
            g_slidshow_cntx.play_time = 0;
        }
        else
        {
            mdi_video_ply_get_cur_play_time(&g_slidshow_cntx.play_time);
        }
        
        if (g_slidshow_cntx.v_state != SLIDSHOW_VIDEO_PAUSE)
        {
            g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_STOP;
        }
        
        if (g_slidshow_cntx.is_vdo_opened)
        {
            mdi_video_ply_close_clip_file();
            if (g_slidshow_cntx.v_state != SLIDSHOW_VIDEO_PAUSE)            
            {
                g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_CLOSE;
            }
            g_slidshow_cntx.is_vdo_opened = FALSE;
        }
 
#if defined(LCM_ROTATE_SUPPORT)
        if (g_slidshow_cntx.error_code)
        {
            gdi_layer_flatten_previous_to_base();
        }
        else if (flat_play_layer)
        {
            gdi_layer_flatten_to_base(g_slidshow_cntx.play_layer_handle, GDI_NULL_HANDLE, GDI_NULL_HANDLE, GDI_NULL_HANDLE);
        }
#else
        if (g_slidshow_cntx.error_code)
        {
            gdi_layer_flatten_previous_to_base();
        }
#endif
    }

    /* free layer */

    if ( g_slidshow_cntx.osd_layer_handle != 0)
    {
        g_slidshow_cntx.osd_layer_buf_ptr = NULL;
        gdi_layer_free(g_slidshow_cntx.osd_layer_handle);
        g_slidshow_cntx.osd_layer_handle = GDI_NULL_HANDLE;
    }
    if (g_slidshow_cntx.play_layer_buf_ptr != NULL)
    {
        gdi_layer_free(g_slidshow_cntx.play_layer_handle);
        mmi_frm_scrmem_free((void*)g_slidshow_cntx.play_layer_buf_ptr);
        g_slidshow_cntx.play_layer_buf_ptr = NULL;
        g_slidshow_cntx.play_layer_handle= GDI_NULL_HANDLE;
    }
    
    if ((g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW) && (!g_slidshow_cntx.is_video_type))
    {
        gdi_layer_set_active(g_slidshow_cntx.base_layer_handle);
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);
        gdi_layer_resize(UI_device_width, UI_device_height);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_lcd_set_rotate_by_layer(FALSE);
    }

    if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
    {
#ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
        g_slidshow_cntx.is_drawing_video_use_idp = MMI_FALSE;
        if (g_slidshow_cntx.osd_layer_handle_of_idp_rotate != 0)
        {
            g_slidshow_cntx.osd_layer_buf_ptr_of_idp_rotate = NULL;
            gdi_layer_free(g_slidshow_cntx.osd_layer_handle_of_idp_rotate);
            g_slidshow_cntx.osd_layer_handle_of_idp_rotate = 0;
        }
#endif
    }

    gdi_layer_set_blt_layer(g_slidshow_cntx.base_layer_handle, 0, 0, 0);

    TurnOffBacklight();

    /* resume background audio */
    mdi_audio_resume_background_play();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* disenable multi-layer */
    gdi_layer_multi_layer_disable();

#ifdef GDI_USING_LAYER_BACKGROUND
    gdi_layer_set_background(GDI_COLOR_WHITE);
#endif

#ifdef __MMI_SUBLCD__
    if (g_slidshow_cntx.is_sub_display)
    {
        GoBackSubLCDHistory();
        g_slidshow_cntx.is_sub_display = FALSE;
    }
#endif /* __MMI_SUBLCD__ */ 

    /* restore TV out mode */
#ifdef __MMI_TVOUT__
    if (mdi_tvout_is_enable())
    {
        if (SCR_ID_SLIDSHOW_PLAY != GetActiveScreenId())
        {
            /* restore back to GDI */
            mdi_tvout_set_owner(MDI_TV_OWNER_GDI);
            /* restore back to start mode1 */
            mdi_tvout_set_mode(MDI_TV_MODE_LCD_SCR,0,0);
        }
        else
        {
            /* change mode to clear layer */
            mdi_tvout_set_mode(MDI_TV_MODE_OWNER_DRAW, 16, 16);
        }
    }
#endif /* __MMI_TVOUT__ */


}

#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */ 

#ifdef __MMI_VIDEO_PLAY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_play_finish_callback
 * DESCRIPTION
 *  Play finish callback function
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_play_finish_callback(MDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.is_video_play_finished = MMI_TRUE;

    if (result >= 0)
    {
        /* success play finished */
        if (g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL)
        {
            gui_start_timer(g_slidshow_cntx.speed_value, mmi_slidshow_auto_next);
        }
        else
        {
            mdi_video_ply_seek_and_get_frame(0, g_slidshow_cntx.play_layer_handle);
            
            /*in manual mode, if the video stopped, when popup and return, should not replay again*/
            g_slidshow_cntx.is_stop_resume = MMI_TRUE;
        }
        /* in MANUAL mode, change state to video playback finished. unset LSK  from pause */
    }
    else
    {
        if (result == MDI_RES_VDOPLY_ERR_DRM_DURATION_USED)
        {
        #ifdef __MMI_SCREEN_ROTATE__            
            if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
            {
                mmi_slideshow_popup_display(
                    g_slidshow_cntx.cur_gid,
                    (UI_string_type) GetString(STR_GLOBAL_DRM_PROHIBITED),
                    MMI_EVENT_FAILURE,
                    (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_NONE,
                    MMI_FRM_SCREEN_ROTATE_270);
            }
            else
        #endif                
            {
                mmi_slideshow_popup_display(
                    g_slidshow_cntx.cur_gid,
                    (UI_string_type) GetString(STR_GLOBAL_DRM_PROHIBITED),
                    MMI_EVENT_FAILURE,
                    (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_NONE,
                    MMI_FRM_SCREEN_ROTATE_0);
            }
            g_slidshow_cntx.error_code = SLIDESHOW_ERR_OTHER; 
        }
        else
        {
            U16 string_id = STR_GLOBAL_ERROR;
            mmi_event_notify_enum event_type = MMI_EVENT_FAILURE;

            string_id = mdi_util_get_mdi_error_info(result, &event_type);
        #ifdef __MMI_SCREEN_ROTATE__            
            if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
            {
                mmi_slideshow_popup_display(
                    g_slidshow_cntx.cur_gid,
                    (UI_string_type) GetString(string_id),
                    MMI_EVENT_FAILURE,
                    (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_NONE,
                    MMI_FRM_SCREEN_ROTATE_270);
            }
            else
        #endif                
            {
                mmi_slideshow_popup_display(
                    g_slidshow_cntx.cur_gid,
                    (UI_string_type) GetString(string_id),
                    MMI_EVENT_FAILURE,
                    (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_NONE,
                    MMI_FRM_SCREEN_ROTATE_0);
            }
            g_slidshow_cntx.error_code = SLIDESHOW_ERR_OTHER; 
        }
    }

    g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_STOP;
    g_slidshow_cntx.play_time = 0;
    if (!g_slidshow_cntx.error_code && g_slidshow_cntx.is_typeofplay_set == SLIDSHOW_MANUAL)
    {
        mdi_video_ply_seek_and_get_frame(0, g_slidshow_cntx.play_layer_handle);
        gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
        gdi_layer_toggle_double();
        mmi_slidshow_main_draw_osd();
        gdi_layer_pop_and_restore_active();
        gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);    
    }
}
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_reset_osd_fade
 * DESCRIPTION
 *  fade slidshow osd
 * PARAMETERS
 *  sleep       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_reset_osd_fade(BOOL sleep)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_slidshow_cntx.osd_opacity != 255)
    {
        g_slidshow_cntx.osd_opacity = 255;

        gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
        gdi_layer_set_opacity(TRUE, (U8) g_slidshow_cntx.osd_opacity);
        gdi_layer_pop_and_restore_active();
    }

    if (sleep)
    {
        /* start fade out timer */
        gui_start_timer(SLIDSHOW_OSD_FADE_OUT_TIME, mmi_slidshow_osd_fade_cyclic);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_osd_fade_cyclic
 * DESCRIPTION
 *  fade slidshow osd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_osd_fade_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_slidshow_cntx.osd_layer_handle == GDI_NULL_HANDLE)
    {
        gui_cancel_timer(mmi_slidshow_osd_fade_cyclic);
        return;
    }

    /* reset osd fade out timer */
    if (g_slidshow_cntx.osd_opacity > SLIDSHOW_OSD_FADE_OUT_VALUE)
    {
        g_slidshow_cntx.osd_opacity -= SLIDSHOW_OSD_FADE_OUT_VALUE;
        gui_start_timer(100, mmi_slidshow_osd_fade_cyclic);
    }
    else
    {
        g_slidshow_cntx.osd_opacity = 0;
    }

    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
    gdi_layer_set_opacity(TRUE, (U8) g_slidshow_cntx.osd_opacity);
    gdi_layer_pop_and_restore_active();
    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_osd_show_up
 * DESCRIPTION
 *  fade slidshow osd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_osd_show_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* register key hdlr */
    if (g_slidshow_cntx.osd_layer_handle == GDI_NULL_HANDLE)
    {
        return;
    }

    //SetKeyHandler(mmi_slidshow_end_key_press, KEY_END, KEY_EVENT_DOWN);
    mmi_slidshow_reset_osd_fade(TRUE);

    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_next_file
 * DESCRIPTION
 *  entry next file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_entry_next_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 buf_filename[SRV_FMGR_PATH_BUFFER_SIZE];
    srv_fmgr_fileinfo_struct file_info;
    S32 info_result;
    FMGR_FILTER ftype;
    filetypes_group_type_enum image_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_slidshow_cntx.fl_hdl);
    info_result = srv_fmgr_filelist_get_fileinfo(g_slidshow_cntx.fl_hdl, g_slidshow_cntx.fl_idx, &file_info);
    if (srv_fmgr_filelist_is_dirty(g_slidshow_cntx.fl_hdl))
    {
        mmi_slideshow_popup_display(
            g_slidshow_cntx.cur_gid,
            (UI_string_type) GetString(FMGR_FS_MEDIA_CHANGED_TEXT),
            MMI_EVENT_FAILURE,
            (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP,
            MMI_FRM_SCREEN_ROTATE_0);
        return;
    }
 
    g_slidshow_cntx.error_code = SLIDESHOW_ERR_NO_ERROR;  /* becuz file index is changed. */
    g_slidshow_cntx.idx2shift = 0;

    srv_fmgr_filelist_get_filename(g_slidshow_cntx.fl_hdl, g_slidshow_cntx.fl_idx, (WCHAR*)buf_filename, SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
    
    image_type = srv_fmgr_types_find_group_by_filename_str((WCHAR*)buf_filename);

    /*each time to play file, should unset the video file flag*/
    g_slidshow_cntx.is_stop_resume = MMI_FALSE;

#ifdef __MMI_VIDEO_PLAY_SUPPORT__    
    if (image_type == FMGR_GROUP_VIDEO)
    {
        g_slidshow_cntx.is_video_file = TRUE;
        g_slidshow_cntx.is_video_type = TRUE;
        g_slidshow_cntx.is_animation = FALSE;
        g_slidshow_cntx.h_animate = GDI_NULL_HANDLE;

        mmi_frm_scrn_enter (g_slidshow_cntx.cur_gid, SCR_ID_SLIDSHOW_DUMMY, NULL, mmi_slidshow_entry_next_file, MMI_FRM_FG_ONLY_SCRN);
        mmi_frm_scrn_close(g_slidshow_cntx.cur_gid, SCR_ID_SLIDSHOW_PLAY);
        
        gui_cancel_timer(mmi_slidshow_auto_next);
        gui_cancel_timer(mmi_slidshow_right_arrow_release);
        g_slidshow_cntx.play_time = 0;
        g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_CLOSE;
        mmi_slidshow_entry_video_screen();
		g_slidshow_cntx.is_prev_file_image = MMI_FALSE;
    }
    else
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */    
    {
        g_slidshow_cntx.is_video_file = FALSE;
        g_slidshow_cntx.is_image_type = TRUE;
        g_slidshow_cntx.is_animation = FALSE;
        g_slidshow_cntx.h_animate = GDI_NULL_HANDLE;

        mmi_frm_scrn_enter (g_slidshow_cntx.cur_gid, SCR_ID_SLIDSHOW_DUMMY, NULL, mmi_slidshow_entry_next_file, MMI_FRM_FG_ONLY_SCRN);
        mmi_frm_scrn_close(g_slidshow_cntx.cur_gid, SCR_ID_SLIDSHOW_PLAY);

        mmi_slidshow_entry_image_display_screen();

		g_slidshow_cntx.is_prev_file_image = MMI_TRUE;
    }
}


#ifdef __MMI_SLIDSHOW_WIPE_ENABLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_effect_wipe_cyclic
 * DESCRIPTION
 *  wipe image cyclic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_effect_wipe_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 i = 5;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_slidshow_cntx.effect_value < 0)
    {
        gui_start_timer(100, mmi_slidshow_effect_wipe_cyclic);
    }
    else
    {
        mmi_slidshow_image_effect_finished();    /* final effect has been drawed. */
    }
    

    for (; i && (g_slidshow_cntx.effect_value <= 0); i--)
    {  
        gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);        
        gdi_layer_set_position(0, g_slidshow_cntx.effect_value);
        gdi_layer_pop_and_restore_active();
        gdi_layer_blt_previous(0, 0, lcd_width - 1, g_slidshow_cntx.effect_value + lcd_height - 1);
        g_slidshow_cntx.effect_value += SLIDSHOW_EFFECT_SHIFT_VALUE;
    }
    /* boundary condition correction for 176x220,128x128 screens */
    if (g_slidshow_cntx.effect_value >0 && 
        g_slidshow_cntx.effect_value < SLIDSHOW_EFFECT_SHIFT_VALUE)
    {
        gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
        gdi_layer_set_position(0, 0);
        gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
        gdi_layer_pop_and_restore_active();        
    }
}
#endif /* __MMI_SLIDSHOW_WIPE_ENABLE__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_effect_split_cyclic
 * DESCRIPTION
 *  split image cyclic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_effect_split_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 i = 5;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_slidshow_cntx.effect_value < 0)
    {
        gui_start_timer(100, mmi_slidshow_effect_split_cyclic);
    }
    else
    {
        mmi_slidshow_image_effect_finished();
    }

    for (; i && (g_slidshow_cntx.effect_value <= 0); i--)
    {
        gdi_layer_push_and_set_active(g_slidshow_cntx.extra_layer_1);
        gdi_layer_set_position(g_slidshow_cntx.effect_value, 0);
        gdi_layer_pop_and_restore_active();
        gdi_layer_push_and_set_active(g_slidshow_cntx.extra_layer_2);
        gdi_layer_set_position(-g_slidshow_cntx.effect_value + lcd_width / 2, 0);
        gdi_layer_pop_and_restore_active();
        gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
        g_slidshow_cntx.effect_value += SLIDSHOW_EFFECT_SHIFT_VALUE;
    }
    
    if (g_slidshow_cntx.effect_value >0 && 
        g_slidshow_cntx.effect_value < SLIDSHOW_EFFECT_SHIFT_VALUE)
    {
        g_slidshow_cntx.effect_value = 0;
        gdi_layer_push_and_set_active(g_slidshow_cntx.extra_layer_1);
        gdi_layer_set_position(g_slidshow_cntx.effect_value, 0);
        gdi_layer_pop_and_restore_active();
        gdi_layer_push_and_set_active(g_slidshow_cntx.extra_layer_2);
        gdi_layer_set_position(-g_slidshow_cntx.effect_value + lcd_width / 2, 0);
        gdi_layer_pop_and_restore_active();
        gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_effect_fade_in_cyclic
 * DESCRIPTION
 *  fade in image cyclic
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_effect_fade_in_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 i = 5;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_slidshow_cntx.effect_value < 255)
    {
        gui_start_timer(100, mmi_slidshow_effect_fade_in_cyclic);
    }
    else
    {
        g_slidshow_cntx.effect_value = 255;
        mmi_slidshow_image_effect_finished();
    }
    gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
    for (; i && (g_slidshow_cntx.effect_value <= 255); i--)
    {
        gdi_layer_set_opacity(TRUE, (U8) g_slidshow_cntx.effect_value);
        gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
        g_slidshow_cntx.effect_value += SLIDSHOW_OSD_FADE_IN_VALUE / 2;
    }
    gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_effect_finish
 * DESCRIPTION
 *  draw animation, start timer after image effect finishes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_image_effect_finished(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 p_filename = NULL;
    gdi_result ret_anim;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.effect_finish = TRUE;
    if(g_slidshow_cntx.is_diff_anim)
    {
        return;
    }
    if ( g_slidshow_cntx.is_animation && g_slidshow_cntx.result != -1)
    {
        /* animation image, start to play animation */
        if(g_slidshow_cntx.h_animate != GDI_NULL_HANDLE)
        {
            return;                                         /* if an animation is already started, do nothing. */
        }
        /* save tvout bandwidth */
        gdi_layer_set_blt_layer(g_slidshow_cntx.play_layer_handle, g_slidshow_cntx.osd_layer_handle,0,0);
        p_filename = (PS8) gui_malloc(SRV_FMGR_PATH_BUFFER_SIZE);
        ASSERT(p_filename != NULL);

        mmi_slideshow_get_stored_file_path((PS8)p_filename, NVRAM_EF_SLIDE_SHOW_PATH_LID);

        gdi_anim_set_last_frame_callback(mmi_slidshow_anim_finish_callback);
    #ifdef __MMI_TVOUT__
        if (mdi_tvout_is_enable())
        {
            gdi_anim_set_draw_after_callback(mmi_slidshow_anim_blt_after_callback);
        }
    #endif /* __MMI_TVOUT__ */
    
        if (!g_slidshow_cntx.is_diff_anim)
        {
            gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
            ret_anim = gdi_anim_draw_file_resized(
                 g_slidshow_cntx.resized_image_offset_x,
                 g_slidshow_cntx.resized_image_offset_y,
                 g_slidshow_cntx.resized_image_width,
                 g_slidshow_cntx.resized_image_height,
                 (PS8) p_filename,
                 (&g_slidshow_cntx.h_animate));
            gdi_layer_pop_and_restore_active();
            if (ret_anim < GDI_SUCCEED)
            {         
                g_slidshow_cntx.result = -1;
            }
        } /* if (g_slidshow_cntx.is_diffanim) */
        gui_free(p_filename);    
    }
    
    if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) && (!g_slidshow_cntx.is_edited))
    {
        g_slidshow_cntx.time_4_next_img= FALSE;
        if(g_slidshow_cntx.is_animation && g_slidshow_cntx.result != -1)
        {
            gui_cancel_timer(mmi_slidshow_slice_time_out);
            gui_start_timer(g_slidshow_cntx.speed_value, mmi_slidshow_slice_time_out);
        }
        else
        {
            gui_cancel_timer(mmi_slidshow_auto_next);
            gui_start_timer(g_slidshow_cntx.speed_value, mmi_slidshow_auto_next);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_anim_finish_callback
 * DESCRIPTION
 *  start timer for next image if animation finished playing.
 * PARAMETERS
 *  result
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_slidshow_anim_finish_callback(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(result == GDI_SUCCEED)
    {
        if(g_slidshow_cntx.time_4_next_img)
        {
            if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) && (!g_slidshow_cntx.is_edited))
            {
                /*stop animation and start timer.*/
        #ifdef __MMI_TVOUT__
                if (mdi_tvout_is_enable())
                {
                    gdi_anim_stop(g_slidshow_cntx.h_animate_tv);
                    g_slidshow_cntx.h_animate_tv = GDI_NULL_HANDLE;
                }
        #endif
                if(g_slidshow_cntx.h_animate != GDI_NULL_HANDLE)
                {
                    gdi_anim_stop(g_slidshow_cntx.h_animate);
                    g_slidshow_cntx.h_animate = GDI_NULL_HANDLE;
                }
                gui_cancel_timer(mmi_slidshow_auto_next);
                gui_start_timer(SLIDSHOW_ANIM_NEXT_IMG_DELAY, mmi_slidshow_auto_next);
            }
        }
    }
    else
    {
        if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) && (!g_slidshow_cntx.is_edited))
        {            
            /* this is still image, callback will only be invoked once */
            gui_cancel_timer(mmi_slidshow_slice_time_out);
            gui_cancel_timer(mmi_slidshow_auto_next);
            gui_start_timer(g_slidshow_cntx.speed_value,mmi_slidshow_auto_next);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_slice_time_out
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_slice_time_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.time_4_next_img = TRUE;
}


static void mmi_slideshow_init_bgm_option_menu(cui_menu_event_struct *menu_evt)
{
    cui_menu_enable_center_softkey(menu_evt->sender_id, 0, IMG_GLOBAL_COMMON_CSK);

    if (mmi_ucs2strlen(g_slidshow_cntx.audio_file_path) != 0)
    {
        cui_menu_set_item_image(menu_evt->sender_id, MENU_ID_SLIDSHOW_BGM_AUDIO_FILE_PLAY, IMG_GLOBAL_L1);
        cui_menu_set_item_image(menu_evt->sender_id, MENU_ID_SLIDSHOW_BGM_AUDIO_FILE_SELECT, IMG_GLOBAL_L2);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_SLIDSHOW_BGM_AUDIO_FILE_PLAY, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_image(menu_evt->sender_id, MENU_ID_SLIDSHOW_BGM_AUDIO_FILE_SELECT, IMG_GLOBAL_L1);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_SLIDSHOW_BGM_AUDIO_FILE_PLAY, MMI_TRUE);
    }
}


static mmi_ret mmi_slideshow_bgm_option_menu_group_proc(mmi_event_struct *evt)
{   
    switch (evt->evt_id)
    {
        /*********************** General Group Function Start ***************************************/
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            
            if (menu_evt->parent_menu_id == MENU_ID_SLIDSHOW_BGM_FILE_OPTION)
            {
                mmi_slideshow_init_bgm_option_menu((cui_menu_event_struct *)evt);
            }
        }
        break;
        
    case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
    case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            
            if (menu_evt->parent_menu_id == MENU_ID_SLIDSHOW_BGM_FILE_OPTION)
            {
                switch(menu_evt->highlighted_menu_id)
                {
                case MENU_ID_SLIDSHOW_BGM_AUDIO_FILE_PLAY:
                    mmi_slidshow_entry_audio_file_play();
                    break;
                    
                case MENU_ID_SLIDSHOW_BGM_AUDIO_FILE_SELECT:
                    mmi_slidshow_entry_select_audio();
                    break;
                }
            }
            break;
        }
        break;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            
            mmi_frm_group_close(menu_evt->sender_id);
            break;
        }
        break;
        /*********************** General Group Function End ***************************************/
        
    case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        {
            cui_file_selector_result_event_struct *file_result = (cui_file_selector_result_event_struct*)evt;
            
            if (file_result->result > 0) //== MMI_SLIDESHOW_FMGR_SELECT_BGM_FILE)
            {
                if (cui_file_selector_get_userdata(file_result->sender_id) == MMI_SLIDESHOW_FMGR_SELECT_BGM_FILE)
                {
                    U16 file_path[SRV_FMGR_PATH_MAX_LEN + 1];
                    srv_fmgr_fileinfo_struct file_info;
                    
                    cui_file_selector_get_selected_filepath(file_result->sender_id, &file_info, file_path, SRV_FMGR_PATH_BUFFER_SIZE);
                    mmi_slidshow_fmgr_select_audio_result_callback(file_path);
                    cui_file_selector_close(file_result->sender_id);
                }
            }
            else if (file_result->result == 0)
            {
                mmi_frm_group_close(SCR_ID_SLIDSHOW_BGM_FILE_OPTION);
            }
            else
            {
                mmi_slideshow_popup_display(
                    g_slidshow_cntx.cur_gid,
                    (WCHAR*)GetString(srv_fmgr_fs_error_get_string(file_result->result)),
                    MMI_EVENT_FAILURE,
                    (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP,
                    MMI_FRM_SCREEN_ROTATE_0);
            }
        }
        break;
    }

    return MMI_RET_OK;
}


static void mmi_slideshow_entry_file_option(void)
{
    MMI_ID  cui_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(g_slidshow_cntx.cur_gid, SCR_ID_SLIDSHOW_BGM_FILE_OPTION, mmi_slideshow_bgm_option_menu_group_proc, (void*)NULL); 
    
    mmi_frm_group_enter(SCR_ID_SLIDSHOW_BGM_FILE_OPTION, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    cui_gid = cui_menu_create(
        SCR_ID_SLIDSHOW_BGM_FILE_OPTION, 
        CUI_MENU_SRC_TYPE_RESOURCE, 
        CUI_MENU_TYPE_APPMAIN,
        MENU_ID_SLIDSHOW_BGM_FILE_OPTION, 
        MMI_FALSE, 
        NULL);
    cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_SLIDSHOW_APP)));
    cui_menu_set_default_title_string(cui_gid, (WCHAR*)GetString(STR_GLOBAL_OPTIONS));
    cui_menu_run(cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_hilight_entry_select
 * DESCRIPTION
 *  highlighter for select audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_hilight_entry_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_slidshow_entry_select_audio, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_slidshow_entry_select_audio, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    redraw_softkey(MMI_CENTER_SOFTKEY);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_highlight_audio_file_play
 * DESCRIPTION
 *  highligher to play audio file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_highlight_audio_file_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);

    SetLeftSoftkeyFunction(mmi_slidshow_entry_audio_file_play, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_audio_file_play
 * DESCRIPTION
 *  Play Audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_entry_audio_file_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_slidshow_cntx.audio_file_path)
    {
        MMI_ASSERT(0);
    }
#if defined(__MMI_BACKGROUND_CALL__)
    if (!srv_ucm_is_background_call())
    {
    mmi_media_app_play_audio(g_slidshow_cntx.audio_file_path, NULL, GetRootTitleIcon(MENU_ID_SLIDSHOW_APP));
    }
    else
    {
        mmi_slideshow_popup_display(
            g_slidshow_cntx.cur_gid,
            (UI_string_type) GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL),
            MMI_EVENT_FAILURE,
            (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_NONE,
            MMI_FRM_SCREEN_ROTATE_0);
    }
#else
    mmi_media_app_play_audio(g_slidshow_cntx.audio_file_path, NULL, GetRootTitleIcon(MENU_ID_SLIDSHOW_APP));
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_aud_is_playing
 * DESCRIPTION
 *  return status about wheatehr BGM is playing in slidshow or not
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE if slideshow will play (or is playing BGM while playing)
 *****************************************************************************/
BOOL mmi_slidshow_aud_is_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    return (g_slidshow_cntx.is_bgm_set && g_slidshow_cntx.is_valid_bgm || (SLIDSHOW_VIDEO_PLAYING == g_slidshow_cntx.v_state));
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_draw_arrow_key_osd
 * DESCRIPTION
 *  draws softkeys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_draw_arrow_key_osd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset_x;
    S32 offset_y;
    S32 image_width;
    S32 image_height;
    S32 spacing = 3;
    U8 arrow_gap = 2;
    S32 layer_offset_x, layer_offset_y;
    S32 img_offset_x, img_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw icon */
    gdi_image_get_dimension_id(IMG_ID_SLIDSHOW_LEFT_ARROW, &image_width, &image_height);
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
    {
        offset_x = lcd_width - arrow_gap - spacing - image_width * 2;
        offset_y = (lcd_height - image_height) >> 1;

        /*if in video file and use idp rotate, the data should be fixed*/
        if (g_slidshow_cntx.is_video_file)
        {
        #ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
            if (!g_slidshow_cntx.is_in_background_call && !g_slidshow_cntx.is_video_drm_prohibit)
        {
                offset_x = lcd_height - arrow_gap - spacing - image_width * 2;
            offset_y = (lcd_width - image_height) >> 1;
        }
        #endif
        }
    }
    else
    {
        offset_x = (lcd_width - image_width * 2 - spacing) >> 1;
        offset_y = lcd_height - image_height - arrow_gap;
    }

#ifdef __MMI_TOUCH_SCREEN__
    g_slidshow_touch_screen_cntx.left_arrow.pos_x = offset_x;
    g_slidshow_touch_screen_cntx.left_arrow.pos_y = offset_y;
    g_slidshow_touch_screen_cntx.left_arrow.width = image_width;
    g_slidshow_touch_screen_cntx.left_arrow.height = image_height;
#endif

    img_offset_x = offset_x - layer_offset_x;
    img_offset_y = offset_y - layer_offset_y;

    /*if in video file and use idp rotate, the data should be fixed*/
    if (g_slidshow_cntx.is_video_file && g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
    {
#ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
        if (!g_slidshow_cntx.is_in_background_call && !g_slidshow_cntx.is_video_drm_prohibit)
        {
            img_offset_x = offset_x - (lcd_height - mmi_slideshow_horizon_button_bar_width);
            img_offset_y = offset_y - layer_offset_y;
        }
#endif
    }

    gdi_draw_solid_rect(img_offset_x,img_offset_y, img_offset_x + image_width, img_offset_y + image_height, GDI_COLOR_TRANSPARENT);
    if (g_slidshow_cntx.is_left_arrow_pressed)
    {
        gdi_image_draw_id(img_offset_x, img_offset_y, IMG_ID_SLIDSHOW_LEFT_ARROW_SEL);
    }
    else
    {
        gdi_image_draw_id(img_offset_x, img_offset_y, IMG_ID_SLIDSHOW_LEFT_ARROW);
    }

    /*right arrow*/
    offset_x += image_width + spacing;

#ifdef __MMI_TOUCH_SCREEN__
    g_slidshow_touch_screen_cntx.right_arrow.pos_x = offset_x;
    g_slidshow_touch_screen_cntx.right_arrow.pos_y = offset_y;
    g_slidshow_touch_screen_cntx.right_arrow.width = image_width;
    g_slidshow_touch_screen_cntx.right_arrow.height = image_height;
#endif

    img_offset_x = offset_x - layer_offset_x;
    img_offset_y = offset_y - layer_offset_y;

    /*if in video file and use idp rotate, the data should be fixed*/
    if (g_slidshow_cntx.is_video_file && g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
    {
    #ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
        if (!g_slidshow_cntx.is_in_background_call && !g_slidshow_cntx.is_video_drm_prohibit)
        {
            img_offset_x = offset_x - (lcd_height - mmi_slideshow_horizon_button_bar_width);
        }
    #endif
    }

    gdi_draw_solid_rect(img_offset_x,img_offset_y, img_offset_x + image_width, img_offset_y + image_height, GDI_COLOR_TRANSPARENT);
    if (g_slidshow_cntx.is_right_arrow_pressed)
    {
        gdi_image_draw_id(img_offset_x, img_offset_y, IMG_ID_SLIDSHOW_RIGHT_ARROW_SEL);
    }
    else
    {
        gdi_image_draw_id(img_offset_x, img_offset_y, IMG_ID_SLIDSHOW_RIGHT_ARROW);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_right_arrow_icon_key_press
 * DESCRIPTION
 *  right arrow key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_right_arrow_icon_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.is_right_arrow_pressed = TRUE;

    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
    if (gdi_layer_is_double(g_slidshow_cntx.osd_layer_handle))
    {
        gdi_layer_toggle_double();
        mmi_slidshow_main_draw_osd();        
    }
    else
    {
        mmi_slidshow_draw_arrow_key_osd();
    }
    gdi_layer_pop_and_restore_active();    

    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_right_arrow_icon_key_release
 * DESCRIPTION
 *  right arrow key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_right_arrow_icon_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.is_right_arrow_pressed = FALSE;
    
    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle); 
    if (gdi_layer_is_double(g_slidshow_cntx.osd_layer_handle))
    {
        gdi_layer_toggle_double();
        mmi_slidshow_main_draw_osd();   /* redraw softkey too for video */
    }
    else
    {
        mmi_slidshow_draw_arrow_key_osd();
    }
    gdi_layer_pop_and_restore_active();
    
    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_left_arrow_icon_key_press
 * DESCRIPTION
 *  left arrow key press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_left_arrow_icon_key_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.is_left_arrow_pressed = TRUE;
    
    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);
    if (gdi_layer_is_double(g_slidshow_cntx.osd_layer_handle))
    {
        gdi_layer_toggle_double();
        mmi_slidshow_main_draw_osd();        
    }
    else
    {
        mmi_slidshow_draw_arrow_key_osd();
    }

    gdi_layer_pop_and_restore_active();
    
    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_left_arrow_icon_key_release
 * DESCRIPTION
 *  left arrow key release
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_left_arrow_icon_key_release(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_slidshow_cntx.is_left_arrow_pressed = FALSE;
    
    gdi_layer_push_and_set_active(g_slidshow_cntx.osd_layer_handle);  
    if (gdi_layer_is_double(g_slidshow_cntx.osd_layer_handle))
    {
        gdi_layer_toggle_double();
        mmi_slidshow_main_draw_osd();
    }
    else
    {
        mmi_slidshow_draw_arrow_key_osd();
    }
    gdi_layer_pop_and_restore_active();

    gdi_layer_blt_previous(0, 0, lcd_width - 1, lcd_height - 1);
}

#ifdef __MMI_TVOUT__
/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_draw_img_2_tv
 * DESCRIPTION
 *  output the image to tv. display a black block if the filename and image id is null.
 *  if both image_id and file name is specified, will ignore the image id.
 * PARAMETERS
 * p_filename   [IN]    the file to be draw (with full path)
 * img_id       [IN]    Image id to be draw
 * img_w        [IN]    the width of image
 * img_h        [IN]    the height of image
 * anim         [IN]    is animation or not.
 * reset_tvout  [IN]    reset the mode of tvout or not. (reset mode will clean TV layer with black)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_draw_img_2_tv(PS8 p_filename, U16 img_id, S32 img_w, S32 img_h, BOOL anim, BOOL reset_tvout)
{   
    S32 tvout_resized_offset_x;
    S32 tvout_resized_offset_y;
    S32 tvout_resized_img_w;    /* the resized image w/h on TV */
    S32 tvout_resized_img_h;
    S32 tvout_max_width;        /* tvout max size */
    S32 tvout_max_height;
    S32 tvout_layer_w;          /* the actually tvout layer size (cuz we need to make layer pix %8 ==0 ) */
    S32 tvout_layer_h;
    GDI_HANDLE tvout_layer;

    S32 offset_x = 0;
    S32 offset_y = 0;
    
    if (mdi_tvout_is_enable())
    {
        if(p_filename != NULL)
        {
            tvout_resized_img_w = g_slidshow_cntx.resized_image_width;
            tvout_resized_img_h = g_slidshow_cntx.resized_image_height;
        }
        else if (img_id)
        {
            /* get best fit size for PAL/NTSC */
            mdi_tvout_get_owner_draw_best_size(&tvout_max_width, &tvout_max_height);           
            if ((tvout_max_width >= img_w) && (tvout_max_height >= img_h))
            {
                ASSERT(img_w > 0 && img_h > 0 );        /* image width/height must > 0 */
                tvout_resized_img_w = img_w;
                tvout_resized_img_h = img_h;
            }
            else
            {
                gdi_image_util_fit_bbox(
                    tvout_max_width,
                    tvout_max_height,
                    img_w,
                    img_h,
                    &tvout_resized_offset_x,
                    &tvout_resized_offset_y,
                    &tvout_resized_img_w,
                    &tvout_resized_img_h);
            }
        }
        else
        {
            tvout_resized_img_w = tvout_resized_img_h = 16;
        }


        tvout_layer_w = tvout_resized_img_w;
        tvout_layer_h = tvout_resized_img_h;
        /* tvout layer width || height  cannot be 1 */        
        if (tvout_layer_w <= 1) 
        {
            tvout_layer_w = 2;
        }
        if (tvout_layer_h <= 1) 
        {
            tvout_layer_h = 2;
        }

    #ifdef MDI_TVOUT_MT6228_SERIES
        if (tvout_layer_w % 8 != 0)
        {
            tvout_layer_w = ((tvout_layer_w +7) >> 3 ) << 3;
            offset_x = (tvout_layer_w - tvout_resized_img_w) >> 1;
        }
    #else
        if (tvout_layer_w % 2 != 0)
        {
            tvout_layer_w = ((tvout_layer_w + 1) >> 1 ) << 1;
            offset_x = (tvout_layer_w - tvout_resized_img_w) >> 1;
        }
    #endif /* MDI_TVOUT_MT6228_SERIES */
    if (reset_tvout)
    {
        /* set mode to owner draw */
        mdi_tvout_force_disable_vertical_filter();
        mdi_tvout_set_mode(
            MDI_TV_MODE_OWNER_DRAW,
            tvout_layer_w,    /* layer_width */
            tvout_layer_h);  /* layer_height */
    }
        g_slidshow_cntx.tv_layer_h = tvout_layer_h;
        g_slidshow_cntx.tv_layer_w = tvout_layer_w;

        tvout_layer = mdi_tvout_get_active_layer();

        gdi_lcd_set_active(GDI_LCD_TVOUT_HANDLE);
        gdi_layer_push_and_set_active(tvout_layer);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_reset_clip();
        gdi_layer_push_clip();
        gdi_layer_set_clip(
            offset_x,
            offset_y,
            tvout_resized_img_w + offset_x - 1,
            tvout_resized_img_h + offset_y - 1);
        gdi_push_and_set_alpha_blending_source_layer(tvout_layer);
        if (p_filename!= NULL)
        {
            if(anim)
            {
                gdi_image_draw_animation_resized_file(
                    offset_x,
                    offset_y,
                    tvout_resized_img_w,
                    tvout_resized_img_h,
                    (PS8) p_filename,
                    &g_slidshow_cntx.h_animate_tv);
            }
            else
            {
                gdi_image_draw_resized_file(
                    offset_x, 
                    offset_y, 
                    tvout_resized_img_w,
                    tvout_resized_img_h, 
                    p_filename);
            }
        }
        else if (img_id != 0)
        {
            gdi_image_draw_id(0, 0, img_id);
        }
        gdi_pop_and_restore_alpha_blending_source_layer();

        g_slidshow_cntx.tv_offset_x = offset_x;
        g_slidshow_cntx.tv_offset_y = offset_y;
        gdi_layer_pop_clip();
        gdi_layer_pop_and_restore_active();
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
        mdi_tvout_blt();

    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_anim_blt_after_callback
 * DESCRIPTION
 *  increase the volume of audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_anim_blt_after_callback(GDI_RESULT result)
{
    GDI_HANDLE tvout_layer;
    PU8 p_src,p_dest;
    gdi_rect_struct clip;

    if (result < GDI_SUCCEED)
    {
        return;
    }
    
    if (mdi_tvout_is_enable())
    {
        clip.x1 = g_slidshow_cntx.tv_offset_x;
        clip.y1 = g_slidshow_cntx.tv_offset_y;
        clip.x2 = g_slidshow_cntx.tv_layer_w - 1;
        clip.y2 = g_slidshow_cntx.tv_layer_h - 1;
        /* buffer should only need to be get once. */
        gdi_layer_push_and_set_active(g_slidshow_cntx.play_layer_handle);
        gdi_layer_get_buffer_ptr(&p_src);
        gdi_layer_pop_and_restore_active();
        
        tvout_layer = mdi_tvout_get_active_layer();
        gdi_lcd_set_active(GDI_LCD_TVOUT_HANDLE);
        gdi_layer_push_and_set_active(tvout_layer);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_get_buffer_ptr(&p_dest);


        gdi_2d_memory_blt(
            p_src,
            lcd_width,
            g_slidshow_cntx.resized_image_offset_x,
            g_slidshow_cntx.resized_image_offset_y,  /* the offset x,y of copy pointer*/
            g_slidshow_cntx.resized_image_width,
            g_slidshow_cntx.resized_image_height,   /* the width/height to be copied */
            p_dest,
            g_slidshow_cntx.tv_layer_w,        /* dest_pitch */
            clip.x1,                       /* the offset on the dest buffer */
            clip.y1,
            clip,
            GDI_MAINLCD_BIT_PER_PIXEL);
        gdi_layer_pop_and_restore_active();
        gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
        mdi_tvout_blt();
    }
}

#endif /* __MMI_TVOUT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_vol_up
 * DESCRIPTION
 *  increase the volume of audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static void mmi_slidshow_vol_up(void)
{
    if (mdi_audio_is_background_play_suspended())
    {
        if (g_slidshow_cntx.audio_volume < MAX_VOL_LEVEL - 1)
        {
            mdi_audio_set_volume(VOL_TYPE_MEDIA, ++g_slidshow_cntx.audio_volume);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_vol_down
 * DESCRIPTION
 *  increase the volume of audio
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
    
static void mmi_slidshow_vol_down(void)
{
    if (mdi_audio_is_background_play_suspended())
    {
        if (g_slidshow_cntx.audio_volume >0 )
        {
            mdi_audio_set_volume(VOL_TYPE_MEDIA, --g_slidshow_cntx.audio_volume);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_set_keys
 * DESCRIPTION
 *  set key handlers.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static void mmi_slidshow_set_keys(void)
{
    static U16 keys_to_set[] = 
                        {
                        KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0,
                        KEY_POUND, KEY_STAR, KEY_CLEAR};
    SetGroupKeyHandler(mmi_slidshow_osd_show_up, keys_to_set, 13, KEY_EVENT_UP);
    SetKeyHandler(mmi_slidshow_vol_up, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(mmi_slidshow_vol_down, KEY_VOL_DOWN, KEY_EVENT_UP);
    /* if LCD is Horizontal, down:next pic, up:previous pic */
    if (SLIDSHOW_HORIZONTAL_VIEW == g_slidshow_cntx.is_horz_view_set)
    {
        SetKeyHandler(mmi_slidshow_right_arrow_press, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_slidshow_right_arrow_release, KEY_DOWN_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_slidshow_left_arrow_press, KEY_UP_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_slidshow_left_arrow_release, KEY_UP_ARROW, KEY_EVENT_UP);
              
        SetKeyHandler(mmi_slidshow_osd_show_up, KEY_LEFT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_slidshow_osd_show_up, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    }
    else
    {
        SetKeyHandler(mmi_slidshow_right_arrow_press, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_slidshow_right_arrow_release, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_slidshow_left_arrow_press, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_slidshow_left_arrow_release, KEY_LEFT_ARROW, KEY_EVENT_UP);
        
        SetKeyHandler(mmi_slidshow_osd_show_up, KEY_UP_ARROW, KEY_EVENT_UP);
        SetKeyHandler(mmi_slidshow_osd_show_up, KEY_DOWN_ARROW, KEY_EVENT_UP);    
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_exit_display_screens
 * DESCRIPTION
 *  delete screens when the fmgr which slideshow was calling has been killed
 * PARAMETERS
 *  app_id      [IN] application ID
 * RETURNS
 *  void
 *****************************************************************************/

extern void mmi_slidshow_exit_display_screens(U8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 scrnid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (APP_SLIDESHOW != app_id)
    {
        for(scrnid= SCR_ID_SLIDSHOW_APP; scrnid < SCR_ID_SLIDSHOW_ALL; scrnid++)
        {
            mmi_frm_scrn_close(g_slidshow_cntx.cur_gid, scrnid);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_deleteScr_callback
 * DESCRIPTION
 *  delete screens when the fmgr which slideshow was calling has been killed
 * PARAMETERS
 *  ptr      [IN] not used.
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_slidshow_deleteScr_callback(void* ptr)
{
    g_slidshow_cntx.is_valid_bgm = FALSE;
    if (mdi_audio_is_background_play_suspended())
    {
        mdi_audio_resume_background_play();
    }
    return MMI_FALSE;
}


#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_drm_timeup_callback
 * DESCRIPTION
 *  handle the return value of DRM timeout.
 * PARAMETERS
 *  ptr      [IN] not used.
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_slidshow_drm_timeup_callback(S32 result, S32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result < 0 && g_slidshow_cntx.play_layer_handle != GDI_NULL_HANDLE)
    {
        mmi_slideshow_popup_display(
            g_slidshow_cntx.cur_gid,
            (UI_string_type) GetString(STR_GLOBAL_DRM_PROHIBITED),
            MMI_EVENT_FAILURE,
            (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_NONE,
            MMI_FRM_SCREEN_ROTATE_0);
        g_slidshow_cntx.error_code = SLIDESHOW_ERR_OTHER;
    }
}
#endif /* __DRM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_deleteScr_callback
 * DESCRIPTION
 *  delete screens when the fmgr which slideshow was calling has been killed
 * PARAMETERS
 *  ptr      [IN] not used.
 * RETURNS
 *  void
*****************************************************************************/
static void mmi_slidshow_turn_off_bl_hdlr(void)
{
    TurnOffBacklight();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_exit_hdlr
 * DESCRIPTION
 *  for back and select is null
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*****************************************************************************/
static void mmi_slidshow_exit_hdlr(void)
{
    mmi_frm_group_close(g_slidshow_cntx.cur_gid);
}


/***************************************************************************** 
*
* Touch Screen
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_pen_down_hdlr
 * DESCRIPTION
 *  pen down hdlr
 * PARAMETERS
 *  pos     [IN]        Pen down postion
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
void mmi_slidshow_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 tmp_x;
    S32 tmp_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_slidshow_cntx.osd_opacity)
    {
        mmi_slidshow_osd_show_up();
        return;
    }

    if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) || (g_slidshow_cntx.is_video_file))
    {
        mmi_slidshow_osd_show_up();
    }

    g_slidshow_cntx.is_pen_down = MMI_TRUE;

    if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
    {
        tmp_x = pos.x;
        tmp_y = pos.y;
        pos.x = tmp_y;
        pos.y = (UI_device_width - 1) - tmp_x;
    }
    /* LSK */
    if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.lsk))
    {
        /* draw clicked LSK */
        if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) || (g_slidshow_cntx.is_video_file))
        {
            if (g_slidshow_cntx.error_code)
            {
                g_slidshow_touch_screen_cntx.pen_event_on_object = SLIDSHOW_NONE;
            }
            else
            {
                mmi_slidshow_lsk_press();
                g_slidshow_touch_screen_cntx.pen_event_on_object = SLIDSHOW_LSK;
            }
        }
        return;
    }
    /* RSK */
    if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.rsk))
    {
        /* draw clicked RSK */
        mmi_slidshow_rsk_press();
        g_slidshow_touch_screen_cntx.pen_event_on_object = SLIDSHOW_RSK;
        return;
    }
    /* left arrow */
    if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.left_arrow))
    {
        mmi_slidshow_left_arrow_icon_key_press();
        g_slidshow_touch_screen_cntx.pen_event_on_object = SLIDSHOW_LEFT_ARROW;
        return;
    }
    /* right arrow */
    if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.right_arrow))
    {
        mmi_slidshow_right_arrow_icon_key_press();
        g_slidshow_touch_screen_cntx.pen_event_on_object = SLIDSHOW_RIGHT_ARROW;
        return;
    }
    
    /* no event */
    if ((g_slidshow_cntx.is_typeofplay_set != SLIDSHOW_MANUAL) || (g_slidshow_cntx.is_video_file))
    {
        mmi_slidshow_osd_show_up();
    }
    g_slidshow_touch_screen_cntx.pen_event_on_object = SLIDSHOW_NONE;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_pen_up_hdlr
 * DESCRIPTION
 *  pen down hdlr
 * PARAMETERS
 *  pos     [IN]        Pen up postion
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
void mmi_slidshow_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 tmp_x;
    S32 tmp_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_slidshow_cntx.is_pen_down)
    {
        return;
    }
    
    if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
    {
        tmp_x = pos.x;
        tmp_y = pos.y;
        pos.x = tmp_y;
        pos.y = (UI_device_width - 1) - tmp_x;
    }

    switch (g_slidshow_touch_screen_cntx.pen_event_on_object)
    {
        case SLIDSHOW_LSK:
            if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.lsk))
            {
                mmi_slidshow_lsk_release();
            }
            break;

        case SLIDSHOW_RSK:
            if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.rsk))
            {
                mmi_slidshow_rsk_release();
            }
            break;

        case SLIDSHOW_LEFT_ARROW:
            if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.left_arrow))
            {
                mmi_slidshow_left_arrow_release();
                //gui_start_timer(SLIDSHOW_KEY_PRESS_DELAY,mmi_slidshow_left_arrow_release);
            }
            else
            {
                mmi_slidshow_left_arrow_icon_key_release();
            }
            break;

        case SLIDSHOW_RIGHT_ARROW:
            if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.right_arrow))
            {
                mmi_slidshow_right_arrow_release();
                //gui_start_timer(SLIDSHOW_KEY_PRESS_DELAY,mmi_slidshow_right_arrow_release);
            }
             else
             {
                 mmi_slidshow_right_arrow_icon_key_release();
             }
            break;

        default:
            break;
    }

    g_slidshow_touch_screen_cntx.pen_event_on_object = SLIDSHOW_NONE;
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_pen_move_hdlr
 * DESCRIPTION
 *  pen down hdlr
 * PARAMETERS
 *  pos     [IN]        Pen move postion
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
void mmi_slidshow_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 key_pressed = 0;

    S32 tmp_x;
    S32 tmp_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_slidshow_cntx.is_pen_down)
    {
        return;
    }

    if (g_slidshow_cntx.is_horz_view_set == SLIDSHOW_HORIZONTAL_VIEW)
    {
        tmp_x = pos.x;
        tmp_y = pos.y;
        pos.x = tmp_y;
        pos.y = (UI_device_width - 1) - tmp_x;
    }

    switch (g_slidshow_touch_screen_cntx.pen_event_on_object)
    {
        case SLIDSHOW_LSK:
            if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.lsk) == MMI_TRUE)   /* within LSK */
            {
                key_pressed = 1;
            }
            else
            {
                key_pressed = 0;
            }
            if (key_pressed != g_slidshow_cntx.is_lsk_pressed)
            {
                g_slidshow_cntx.is_lsk_pressed = key_pressed;
                mmi_slidshow_show_press_release_softkey();
            }
            break;

        case SLIDSHOW_RSK:
            if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.rsk) == MMI_TRUE)   /* within RSK */
            {
                key_pressed = 1;
            }
            else
            {
                key_pressed = 0;
            }
            if (key_pressed != g_slidshow_cntx.is_rsk_pressed)
            {
                g_slidshow_cntx.is_rsk_pressed = key_pressed;
                mmi_slidshow_show_press_release_softkey();
            }
            break;

        case SLIDSHOW_RIGHT_ARROW:
            if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.right_arrow) == MMI_TRUE)   /* within RSK */
            {
                key_pressed = 1;
            }
            else
            {
                key_pressed = 0;
            }
            if (key_pressed != g_slidshow_cntx.is_right_arrow_pressed)
            {
                g_slidshow_cntx.is_right_arrow_pressed = key_pressed;
                if (g_slidshow_cntx.is_right_arrow_pressed)
                {
                    mmi_slidshow_right_arrow_icon_key_press();
                }
                else
                {
                    mmi_slidshow_right_arrow_icon_key_release();
                }
            }
            break;

        case SLIDSHOW_LEFT_ARROW:
            if (wgui_test_object_position(pos, g_slidshow_touch_screen_cntx.left_arrow) == MMI_TRUE)   /* within RSK */
            {
                key_pressed = 1;
            }
            else
            {
                key_pressed = 0;
            }
            if (key_pressed != g_slidshow_cntx.is_left_arrow_pressed)
            {
                g_slidshow_cntx.is_left_arrow_pressed = key_pressed;
                if (g_slidshow_cntx.is_left_arrow_pressed)
                {
                    mmi_slidshow_left_arrow_icon_key_press();
                }
                else
                {
                    mmi_slidshow_left_arrow_icon_key_release();;
                }
            }
            break;
    }
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_entry_sublcd_screen
 * DESCRIPTION
 *  handle our own sublcd screen while playing a video clip in order to 
 *  prevent driver assert caused by time update onstandard MMI sublcd screen
 *  (c.f. video player)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
void mmi_slidshow_entry_sublcd_screen(void){
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    ShowCategory331Screen();
    SetSubLCDExitHandler(mmi_slidshow_exit_sublcd_screen);

    mmi_slidshow_draw_sublcd_icon();
    
    g_slidshow_cntx.is_sub_display = TRUE;
}
#endif /*__MMI_SUBLCD__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_exit_sublcd_screen
 * DESCRIPTION
 *  exit sub lcd screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
void mmi_slidshow_exit_sublcd_screen(void){
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode his_sublcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reference video player.                                      
     * some application may exit sub lcd first before exit main lcd.
     * so need to check if video is still playing on main lcd for this case.
     */

    if (SLIDSHOW_VIDEO_PLAYING == g_slidshow_cntx.v_state)
    {   
        mdi_video_ply_stop();
        mdi_video_ply_get_cur_play_time(&g_slidshow_cntx.play_time);
        
        g_slidshow_cntx.v_state = SLIDSHOW_VIDEO_STOP;
    }

    g_slidshow_cntx.is_sub_display = FALSE;

    his_sublcd.entryFuncPtr = mmi_slidshow_entry_sublcd_screen;
    AddSubLCDHistory(&his_sublcd);
}
#endif /*__MMI_SUBLCD__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_draw_sublcd_icon
 * DESCRIPTION
 *  draw a icon on sublcd.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
void mmi_slidshow_draw_sublcd_icon(void){
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n_img_width;
    S32 n_img_height;
    S32 n_lcd_width;
    S32 n_lcd_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);         /* active sub lcd before drawing    */
    gdi_lcd_get_dimension(&n_lcd_width, &n_lcd_height);

    gdi_layer_reset_clip();

    gdi_layer_clear_background(GDI_COLOR_WHITE);
    /* we use the same sublcd img from video player */
    gdi_image_get_dimension_id(IMG_ID_SLIDSHOW_SUBLCD_ICON, &n_img_width, &n_img_height);
    gdi_image_draw_id(
        (n_lcd_width - n_img_width) >> 1, 
        (n_lcd_height - n_img_height) >> 1, 
        IMG_ID_SLIDSHOW_SUBLCD_ICON);

    gdi_layer_blt_base_layer(0, 0, n_lcd_width - 1, n_lcd_height -1);
    
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);        /* done, return control to main lcd */
}
#endif /*__MMI_SUBLCD__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_alloc_app_asm
 * DESCRIPTION
 *  allocate memory from app asm's pool
 * PARAMETERS
 *  void
 * RETURNS
 *  BOOL        TRUE if memory is successfully allocated
 *****************************************************************************/
BOOL mmi_slidshow_alloc_app_asm(void)
{
    g_slidshow_cntx.app_mem_bufer = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_SLIDESHOW, MMI_SSHOW_POOL_SIZE + SRV_FMGR_FOLDER_FILELIST_MEM_SIZE);

    if (g_slidshow_cntx.app_mem_bufer)
    {
        g_slidshow_cntx.fmgr_list_buffer = (PU8)g_slidshow_cntx.app_mem_bufer;
        g_slidshow_cntx.audio_file_path = (PS8)g_slidshow_cntx.app_mem_bufer + SRV_FMGR_FOLDER_FILELIST_MEM_SIZE;
        g_slidshow_cntx.tmp_file_path = (PS8)g_slidshow_cntx.audio_file_path + SRV_FMGR_PATH_BUFFER_SIZE;
        
        g_slidshow_layer1_buffer = (PU8)g_slidshow_cntx.tmp_file_path + SRV_FMGR_PATH_BUFFER_SIZE;
#if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
        g_slidshow_layer2_buffer =  (PU8)g_slidshow_layer1_buffer + SLIDESHOW_FRAME_BUFFER_SIZE_24_BIT;
#else
        g_slidshow_layer2_buffer = (PU8)g_slidshow_layer1_buffer + SLIDESHOW_FRAME_BUFFER_SIZE;
#endif

#ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
    #if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
        g_slidshow_layer3_buffer = (PU8)g_slidshow_layer2_buffer + SLIDESHOW_FRAME_BUFFER_SIZE_24_BIT;
    #else
        g_slidshow_layer3_buffer = (PU8)g_slidshow_layer2_buffer + SLIDESHOW_FRAME_BUFFER_SIZE;
    #endif
#endif

        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_free_app_asm
 * DESCRIPTION
 *  free app based ASM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_free_app_asm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_slidshow_cntx.app_mem_bufer)
    {
        applib_mem_ap_free(g_slidshow_cntx.app_mem_bufer);
        
        g_slidshow_cntx.app_mem_bufer = NULL;
        g_slidshow_cntx.audio_file_path = NULL;
        g_slidshow_cntx.tmp_file_path = NULL;
        g_slidshow_layer1_buffer = NULL;
        g_slidshow_layer2_buffer = NULL;
#ifdef __MDI_VIDEO_HW_ROTATOR_SUPPORT__
        g_slidshow_layer3_buffer = NULL;
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_del_scr_callback
 * DESCRIPTION
 *  delete screen id callback handler of slideshow
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_slidshow_del_scr_callback()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_slidshow_free_app_asm();
    slidshow_free_filelist();
    g_slidshow_cntx.is_edited = FALSE;
    g_slidshow_cntx.is_from_other_app = MMI_FALSE;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_stop_callback
 * DESCRIPTION
 *  stop the program for app_based_memory
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_slidshow_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_slidshow_cntx.fmgr_service_id)
    {
        cui_folder_selector_close(g_slidshow_cntx.fmgr_service_id);
        g_slidshow_cntx.fmgr_service_id = 0;
    }
    if (g_slidshow_cntx.fmgr_service_id_of_select_audio)
    {
        cui_file_selector_close(g_slidshow_cntx.fmgr_service_id_of_select_audio);
        g_slidshow_cntx.fmgr_service_id_of_select_audio = 0;
    }

    mmi_frm_group_close(g_slidshow_cntx.cur_gid);
    /*delete audio ply screen*/
    mmi_media_app_delete_play_audio();

    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_SLIDESHOW, KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_load_data
 * DESCRIPTION
 *  load slideshow setting from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_load_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if setting is already loaded, avoid load again to save time */

    ReadRecord(
        NVRAM_EF_SLIDE_SHOW_SETTING_LID,
        1,
        (void*)&g_slidshow_cntx.setting,
        NVRAM_EF_SLIDE_SHOW_SETTING_SIZE,
        &error);

    /* first time init */
    if (g_slidshow_cntx.setting.type_of_play== 0xffffffff)
    {
        g_slidshow_cntx.setting.type_of_play = 0;
        g_slidshow_cntx.setting.speed = 1;
        g_slidshow_cntx.setting.effect = 0;
        g_slidshow_cntx.setting.bgm = 0;
        g_slidshow_cntx.setting.horz = 0;
        g_slidshow_cntx.setting.sound_effect = 0;

        mmi_slidshow_store_data();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_slidshow_store_data
 * DESCRIPTION
 *  load slide show setting from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_slidshow_store_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_SLIDE_SHOW_SETTING_LID,
        1,
        (void*)&g_slidshow_cntx.setting,
        NVRAM_EF_SLIDE_SHOW_SETTING_SIZE,
        &error);
}


void mmi_slideshow_entry_from_other_app(PS8 filepath, S32 fileindex, mmi_slideshow_browse_type_enum type, U16 sort_type)
{
    g_slidshow_cntx.is_from_other_app = MMI_TRUE;
    mmi_wcscpy((WCHAR*)g_slidshow_cntx.media_obj_file_path, (WCHAR*)filepath);
    g_slidshow_cntx.browse_type = type;
    g_slidshow_cntx.file_index_from_others = fileindex;
    g_slidshow_cntx.sort_type = sort_type;

    mmi_slideshow_init_fmgr_filter(&g_slidshow_cntx.filter, type);

    if (mmi_frm_group_is_present(g_slidshow_cntx.cur_gid))
    {
        mmi_frm_group_close(g_slidshow_cntx.cur_gid);
        g_slidshow_cntx.cur_gid = 0;
    }

    g_slidshow_cntx.cur_gid = mmi_frm_group_create (GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_slideshow_app_group_proc, NULL);
    MMI_ASSERT (g_slidshow_cntx.cur_gid);
    
    mmi_frm_group_enter(g_slidshow_cntx.cur_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_slideshow_entry_app_screen_from_other_app();
}

static void mmi_slideshow_entry_app_screen_from_other_app(void)
{
    MMI_BOOL entry_ret;

#ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (mmi_usb_check_path_exported((PS8) L"root"))
        {
            /* phone drive is exported, cant use this app */
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
            return;
        }
    }
#endif /* __USB_IN_NORMAL_MODE__ */
    
    if (g_slidshow_cntx.app_mem_bufer == NULL)
    {
        if (!mmi_slidshow_alloc_app_asm())
        {
            mmi_frm_appmem_prompt_to_release_mem(
                STR_ID_SLIDSHOW_APP,
                IMG_ID_SLIDSHOW_APP,
                MMI_SSHOW_POOL_SIZE + SRV_FMGR_FOLDER_FILELIST_MEM_SIZE,
                mmi_slideshow_entry_app_screen_from_other_app);
            return;
        }
    }
    
    /*to resolve bug MAUI_00294444*/
    if (IsScreenPresent(SCR_ID_SLIDSHOW_APP))
    {
        mmi_frm_scrn_close(g_slidshow_cntx.cur_gid, SCR_ID_SLIDSHOW_APP);
        if (g_slidshow_cntx.app_mem_bufer == NULL)
        {
            if (!mmi_slidshow_alloc_app_asm())
            {
                mmi_frm_appmem_prompt_to_release_mem(
                    STR_ID_SLIDSHOW_APP,
                    IMG_ID_SLIDSHOW_APP,
                    MMI_SSHOW_POOL_SIZE + SRV_FMGR_FOLDER_FILELIST_MEM_SIZE,
                    mmi_slideshow_entry_app_screen_from_other_app);
                return;
            }
        }
    }
    
    /* load setting from NVRAM */
    mmi_slidshow_load_setting();

    /* we use this screen to do some check, and allocate application memory only */
    entry_ret = mmi_frm_scrn_enter (g_slidshow_cntx.cur_gid, SCR_ID_SLIDSHOW_APP, NULL, mmi_slideshow_entry_app_screen_from_other_app, 0);
    if (!entry_ret)
    {
        return;
    }
    
    //SetDelScrnIDCallbackHandler(SCR_ID_SLIDSHOW_APP, mmi_slidshow_del_scr_callback);

    mmi_slideshow_ready_to_play(&g_slidshow_cntx.filter);
}


static void mmi_slideshow_ready_to_play(FMGR_FILTER* filter)
{
    MMI_BOOL is_empty;
    
    /*process the filepath, remove the file name*/
    srv_fmgr_path_remove_filename((WCHAR*) g_slidshow_cntx.media_obj_file_path);
    
    is_empty = srv_fmgr_fs_path_is_not_empty((WCHAR*)g_slidshow_cntx.media_obj_file_path, filter);
    if (!is_empty)
    {
        mmi_slideshow_popup_display(
            g_slidshow_cntx.cur_gid, 
            (UI_string_type) GetString(STR_GLOBAL_EMPTY),
            MMI_EVENT_FAILURE,
            (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP,
                MMI_FRM_SCREEN_ROTATE_0);
        return;
    }
    else
    {
        /*when we use the path in play screen, we will first remove the last dir, but fmgr return the folder name
        so we append some string to the folder path to form the filepath , although the file name is useless*/
        mmi_wcscat((WCHAR*)g_slidshow_cntx.media_obj_file_path, (WCHAR*)L"*.*");
        mmi_slideshow_save_stored_file_path((PS8)g_slidshow_cntx.media_obj_file_path, NVRAM_EF_SLIDE_SHOW_PATH_LID);
        mmi_slidshow_entry_option_screen();
    }
}


static void mmi_slideshow_before_enter_play_screen(void)
{
    S32 result;

    slidshow_free_filelist();
    result = slidshow_create_filelist(MMI_TRUE);

    /*if start to play, the hilite will be change*/
    g_slidshow_cntx.is_hilite_change = MMI_TRUE;

    if (result == FS_NO_ERROR)
    {
        mmi_slideshow_enter_sorting_screen();
    }
    else
    {
        mmi_slideshow_popup_display(
            g_slidshow_cntx.cur_gid,
            (UI_string_type)GetString(srv_fmgr_fs_error_get_string(result)),
            MMI_EVENT_FAILURE,
            (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_NONE,
            MMI_FRM_SCREEN_ROTATE_0);
    }
}
        

static void mmi_slideshow_init_fmgr_filter(FMGR_FILTER* filter, mmi_slideshow_browse_type_enum type)
        {
    
    /*init filter*/
    FMGR_FILTER_INIT(filter);
#ifdef __DRM_V02__
    FMGR_FILTER_SET(filter,FMGR_TYPE_ODF);
#endif /* __DRM_V02__ */
    
    if (type == MMI_SLIDESHOW_BROWSE_TYPE_IMAGE || type == MMI_SLIDESHOW_BROWSE_TYPE_ALL)
    {
        FMGR_FILTER_SET_IMAGE(filter);
#ifndef __MMI_SLIDSHOW_M3D_SUPPORT__        
        FMGR_FILTER_CLEAR(filter,FMGR_TYPE_M3D);
#endif
        FMGR_FILTER_CLEAR(filter, FMGR_TYPE_ANM);
        FMGR_FILTER_CLEAR(filter, FMGR_TYPE_EMS);
        }

    if (type == MMI_SLIDESHOW_BROWSE_TYPE_VIDEO  || type == MMI_SLIDESHOW_BROWSE_TYPE_ALL)
    {
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
        FMGR_FILTER_SET_VIDEO(filter);
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
        FMGR_FILTER_CLEAR(filter, FMGR_TYPE_SDP);
        FMGR_FILTER_CLEAR(filter, FMGR_TYPE_RAM);
    }
}


static S32 mmi_slideshow_file_sort_callback(SRV_FMGR_FILELIST_HANDLE fl_hdl, S32 result, S32 progress, S32 total)
{
    if (progress == total)
    {
        S32 file_count;
        
        g_slidshow_cntx.is_sort_finished = MMI_TRUE;
        
        if (g_slidshow_cntx.is_stop_play == MMI_TRUE)
        {
            return 0;
        }
        
        file_count = srv_fmgr_filelist_count(fl_hdl);
        if (file_count > 0)
        {
            mmi_slidshow_entry_play_screen();
            mmi_frm_scrn_close(g_slidshow_cntx.cur_gid, SCR_ID_SLIDSHOW_SORTING);
        }
        else
        {
            mmi_slideshow_popup_display(
                g_slidshow_cntx.cur_gid,
                (UI_string_type) GetString(STR_GLOBAL_EMPTY),
                MMI_EVENT_FAILURE,
                (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP,
                MMI_FRM_SCREEN_ROTATE_0);
        }
    }
    return 0;
}


static void mmi_slideshow_enter_sorting_screen(void)
{
    PU8 guiBuffer;
    S32 result;
    MMI_BOOL entry_ret;

    if (CheckIsBackHistory() && !g_slidshow_cntx.is_sort_finished)
    {
        result = slidshow_create_filelist(MMI_TRUE);
        if (result == FS_NO_ERROR)
        {
            ;
        }
        else
        {
            U16 string_id = STR_GLOBAL_ERROR;
            S32 event_type = MMI_EVENT_FAILURE;

            slidshow_free_filelist();
            string_id = srv_fmgr_fs_error_get_string_and_popup_type(result, &event_type);
            mmi_slideshow_popup_display(
                g_slidshow_cntx.cur_gid,
                (UI_string_type) GetString(string_id),
                MMI_EVENT_FAILURE,
                (void*)MMI_SLIDESHOW_POPUP_QUIT_ACTION_CLOSE_ROOT_GROUP,
                MMI_FRM_SCREEN_ROTATE_0);
            return;
        }
    }
    
    entry_ret = mmi_frm_scrn_enter (
        g_slidshow_cntx.cur_gid, 
        SCR_ID_SLIDSHOW_SORTING, 
        mmi_slideshow_exit_sorting_screen, 
        mmi_slideshow_enter_sorting_screen, 0);
    if (!entry_ret)
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_gui_buf(g_slidshow_cntx.cur_gid, SCR_ID_SLIDSHOW_SORTING);

    g_slidshow_cntx.is_sort_finished = MMI_FALSE;
    g_slidshow_cntx.is_stop_play = MMI_FALSE;
    
    ShowCategory165Screen(
        0, 
        0, 
        STR_GLOBAL_CANCEL, 
        0, 
        (UI_string_type) GetString(STR_GLOBAL_PLEASE_WAIT), 
        mmi_get_event_based_image(MMI_EVENT_PROGRESS), 
        guiBuffer);
    SetRightSoftkeyFunction(mmi_slideshow_cancel_sorting_screen, KEY_EVENT_UP);
}

    
static void mmi_slideshow_exit_sorting_screen(void)
{
    if (!g_slidshow_cntx.is_sort_finished)
    {
        slidshow_free_filelist();
        g_slidshow_cntx.is_stop_play = MMI_TRUE;
    }
}


static void mmi_slideshow_cancel_sorting_screen(void)
{
    slidshow_free_filelist();
    mmi_frm_scrn_close(g_slidshow_cntx.cur_gid, SCR_ID_SLIDSHOW_PLAY);
    mmi_frm_scrn_close_active_id();
}


static void mmi_slideshow_delete_all_screen(void)
{
    U16 scr_id;

    for (scr_id = SCR_ID_SLIDSHOW_APP; scr_id < SCR_ID_SLIDSHOW_ALL; scr_id++)
    {
        mmi_frm_scrn_close(g_slidshow_cntx.cur_gid, scr_id);
    }
}


#ifdef __BT_SPK_VOL_CONTROL__
static MMI_BOOL mmi_slideshow_hfp_volume_callback(U8 volume, MMI_BOOL is_mute)
{   
    //S16 error;
    
    if (volume < MAX_VOL_LEVEL && is_mute == MMI_FALSE)
    {
        g_slidshow_cntx.audio_volume = volume;
        mdi_audio_set_volume(VOL_TYPE_MEDIA, volume);
        return MMI_TRUE;
    }
    
    return MMI_FALSE;
}
#endif

static void mmi_slideshow_get_stored_file_path(PS8 path, S32 id)
{
    S16 error;
    
    ReadRecord(
        id,
        1,
        (void*)path,
        NVRAM_EF_SLIDE_SHOW_PATH_SIZE,
        &error);
	if ((*path == 0xff) || (*path == -1))
	{
		mmi_ucs2cpy((PS8)path, "");
		WriteRecord(
			id,
			1,
			(void*)path,
			NVRAM_EF_SLIDE_SHOW_PATH_SIZE,
			&error);
	}
}

static void mmi_slideshow_save_stored_file_path(PS8 path, S32 id)
{
    S16 error;

    WriteRecord(
        id,
        1,
        (void*)path,
        NVRAM_EF_SLIDE_SHOW_PATH_SIZE,
        &error);
}


static MMI_BOOL mmi_slideshow_is_parent(const WCHAR* parent_path, const WCHAR *check_path)
{
    if(parent_path == NULL || check_path == NULL)
        return MMI_FALSE;

    if(*parent_path == 0 || *check_path == 0)
        return MMI_FALSE;
    
    while(*parent_path != 0 && *check_path != 0)
    {
        if(*parent_path++ != *check_path++)
            return MMI_FALSE;
    }

    while(*parent_path == '\\')
        parent_path++;
    while(*check_path == '\\')
        check_path++;

    if(*parent_path != 0)
        return MMI_FALSE;

    if(*(check_path-1) == '\\' || *check_path == 0)
        return MMI_TRUE;

    return MMI_FALSE;
}

static MMI_BOOL mmi_slideshow_is_folder_used(srv_fmgr_notification_adv_action_event_struct *fmgr_act)
{
    WCHAR filepath[SRV_FMGR_PATH_MAX_LEN+1];

    if (g_slidshow_cntx.fl_hdl)
    {
        if (fmgr_act->src_fileinfo.type == FMGR_TYPE_FOLDER)
        {
            srv_fmgr_filelist_get_filepath(g_slidshow_cntx.fl_hdl, 0, filepath, sizeof(filepath));
            
            if (mmi_slideshow_is_parent(fmgr_act->src_filepath, (WCHAR *)filepath))
            {
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        }
    
        if (FMGR_FILTER_IS_SET_IMAGE((FMGR_FILTER *)fmgr_act->filter))
        {
            srv_fmgr_filelist_get_filepath(g_slidshow_cntx.fl_hdl, 0, filepath, sizeof(filepath));
            
            if (mmi_slideshow_is_parent(fmgr_act->src_filepath, (WCHAR *)filepath))
            {
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        }
    }
    
    return MMI_FALSE;
}


#endif /* __MMI_SLIDESHOW__ */ 

