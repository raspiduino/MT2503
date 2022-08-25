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
* Filename:
* ---------
*  MediaPlayerMain.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Media Player main program
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "MMI_features.h"
//#include "MMI_include.h"

#ifdef __MMI_MEDIA_PLAYER__

#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_video.h"
#ifdef MOTION_SENSOR_SUPPORT
#include "SensorSrvGport.h"
#endif

#include "gpiosrvGprot.h"
#include "USBSrvGprot.h"

#include "mmi_rp_srv_prof_def.h"

/*DRM related*/
#include "DRM_gprot.h"

#ifdef __MMI_A2DP_SUPPORT__
#include "av_bt.h"
#endif /* __MMI_A2DP_SUPPORT__ */

#include "MediaPlayerProt.h"
#include "MediaPlayerGprot.h"
#include "MediaPlayerPlaylist.h"
//#include "MediaPlayerResDef.h"

//#include "CommonScreens.h" /*gIndexIconsImageList[]*/

#ifdef __MMI_AVRCP_SUPPORT__
//#include "BtcmSrvGprot.h"
#include "BTMMIAVRCPGProt.h"
#endif /*__MMI_AVRCP_SUPPORT__*/

#include "IdleGProt.h"
//#include "SimCtrlSrvGprot.h"
#include "ShutdownSrvGProt.h" /* for shut down boradcast, EVT_ID_SRV_SHUTDOWN_DEINIT*/
#include "ModeSwitchSrvGprot.h"

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h" /*check mass storage mode*/
#endif 

#ifdef __MMI_IMAGE_VIEWER__
#include "ImageViewerGprot.h"   /*for snapshot*/
#endif /*__MMI_IMAGE_VIEWER__*/

#if defined(__MMI_WLAN_FEATURES__)
//#include "NetworkSetupDefs.h"
#endif  /* __MMI_WLAN_FEATURES__ */

#include "UcmSrvGprot.h"

#ifdef __DM_LAWMO_SUPPORT__
#include "Dmuigprot.h"
#endif

#include "FilemgrCuiGprot.h"
#include "FileMgrSrvGProt.h"
#include "menucuigprot.h"
#include "FSEditorCuiGprot.h"

#include "GlobalResDef.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "MediaPlayerEnumDef.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_media_app_trc.h"
#include "kal_trace.h"
#include "MMI_features_mediaplayer.h"
#include "SoundEffect.h"
#include "kal_public_api.h"
#include "mmi_frm_nvram_gprot.h"
#include "custom_mmi_default_value.h"
#include "ProfilesSrvGprot.h"
#include "gui_data_types.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "string.h"
#include "mmi_res_range_def.h"
#include "MediaAppWidgetDef.h"
#include "mmi_frm_input_gprot.h"
#include "device.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalConstants.h"
#include "mmi_frm_gestures_gprot.h"
#include "mmiapi_dm_struct.h"
#include "mmi_rp_app_medply_def.h"
#include "Unicodexdcl.h"
#include "fs_type.h"
#include "drm_def.h"
#include "fs_errcode.h"
#include "drm_errcode.h"
#include "gui_effect_oem.h"
#include "mmi_frm_app_launcher_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "gui.h"
#include "app_mem.h"
#include "NetSetSrvGprot.h"
#include "NetSetAppGprot.h"
#include "InlineCuiGprot.h"
#include "fs_func.h"
#include "wgui_touch_screen.h"
#include "CommonScreensResDef.h"
#include "wgui.h"
#include "SimCtrlSrvGprot.h"
#include "ScrLockerGprot.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "gui_touch_feedback.h"
#endif

#ifdef __MMI_NCENTER_SUPPORT__
#include "vsrv_ncenter.h"
#endif

/* main control object */
medply_struct g_medply;
MMI_ID g_gid_medply = GRP_ID_INVALID;

#ifdef __MTK_TARGET__
__align(4)
#endif /*__MTK_TARGET__*/
U8 g_medply_audio_cache[MEDPLY_BUILD_CACHE_SIZE];

/* allocate static memory for When Cube is enable*/
#if defined(__MMI_VUI_3D_CUBE_APP_MEDIA_PLAYER__) || defined(__MMI_VUI_SHELL_MEDIA_PLAYER__)
    U8 g_medply_mem_pool[MMI_MEDPLY_MEM_POOL_SIZE];
#endif

#ifdef __MMI_TOUCH_SCREEN__
#define MMI_MEDPLY_HIGH_RATE_SAMPLING_PROGRESS_BAR_PERFORMANCE
#endif

/* check memory leak */
static U32 total_asm_memory = 0;

#define CONTROLLER_CODE

static void mmi_medply_update_state(void);

#ifdef __MMI_NCENTER_SUPPORT__
void mmi_medply_ncenter_add_app_item(void);
static void mmi_medply_ncenter_callback_handler(vsrv_notification_handle nhandle, vsrv_nintent intent, void* userData, U32 userDataSize);
void mmi_medply_ncenter_clear_app_item(void);
#endif
static void mmi_medply_scrlocker_key_callback_hdlr(mmi_frm_key_evt_struct* evt);

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_is_button_disabled
 * DESCRIPTION
 *  
 * PARAMETERS
 *  button  [IN]    button set to check
 * RETURNS
 *  MMI_BOOL    
 *****************************************************************************/
MMI_BOOL mmi_medply_is_button_disabled(mmi_medply_disabled_button_enum button)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_IS_BUTTON_DISABLED, button, g_medply.state,g_medply.selected_button);
    
    switch(button)
    {
        /* play(pause) | stop | prev | next */
        case MMI_MEDPLY_DISABLED_CONTROL_BUTTONS:
        {
            if(mmi_medply_is_single_player_activated())
            {
            #ifdef __MMI_MEDIA_PLAYER_INTRO_PLAY__
                if(g_single.intro_play)
                {
                    return MMI_TRUE;   
                }
            #endif
                return MMI_FALSE;
            }
            
            if(g_medply.selected_button == MEDPLY_MAIN_DISABLED)
            {
                return MMI_TRUE;
            }
            return MMI_FALSE;
        }
        case MMI_MEDPLY_DISABLED_PREV_NEXT:
        {
        #ifndef __MMI_MEDIA_PLAYER_FTE__
            if(mmi_medply_is_single_player_activated())
            {
                /*only interested in audio/stream play states*/
                switch(g_single.state)
                {
                #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                    case SINGLE_STATE_AUDIO_PLAY:
                    {
                        break;
                    }
                #endif                        
                #ifdef __MMI_MEDIA_PLAYER_STREAM__
                    case SINGLE_STATE_STREAM_PLAY:
                    {
                        break;
                    }
                #endif
		#ifdef __MMI_MEDIA_PLAYER_VIDEO__
                    case SINGLE_STATE_VIDEO_PLAY:
                    {
                        break;
                    }
                #endif 
                    default:
                    {
                        return MMI_FALSE;
                    }
                }

                switch(g_single.media_type)
                {
                #ifdef __MMI_MEDIA_PLAYER_STREAM__
                    /* check for live streaming*/
                    case MEDPLY_TYPE_STREAM_RTSP:
                    case MEDPLY_TYPE_STREAM_RAM:
                    case MEDPLY_TYPE_STREAM_SDP:
                    {
                        if(!g_single.seekable)
                        {
                            return MMI_TRUE;
                        }
                        return MMI_FALSE;
                    }
                #endif
                #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                    case MEDPLY_TYPE_AUDIO:
                    {
                        if(!g_single.is_audio_seekable)
                        {
                            return MMI_TRUE;
                        }
                        return MMI_FALSE;
                    }
                #endif
		#ifdef __MMI_MEDIA_PLAYER_VIDEO__
                    case MEDPLY_TYPE_VIDEO:
                    {
                        if(!g_single.seekable)
                        {
                            return MMI_TRUE;
                        }
                        return MMI_FALSE;
                    }
                #endif
                    default:
                    {
                        return MMI_FALSE;
                    }
                }

            }
        #endif
            return MMI_FALSE;
        }

        /* play key*/
        case MMI_MEDPLY_DISABLED_PLAY:
        {
            if(mmi_medply_is_single_player_activated())
            {
                switch(g_single.state)
                {
                #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                    case SINGLE_STATE_VIDEO_PAUSE_SEEKING:
                    case SINGLE_STATE_VIDEO_PLAY_SEEKING:
                    {
                        break;
                    }
                #endif                        
                #ifdef __MMI_VIDEO_PDL__
                    case SINGLE_STATE_PDL_VIDEO_PAUSE_SEEKING:
                    case SINGLE_STATE_PDL_VIDEO_PLAY_SEEKING:
                    {
                        break;
                    }
                #endif
                default: 
                    return MMI_FALSE;
                }
            }
            else
            {
                switch(g_medply.state)
                {
                #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                    case MEDPLY_STATE_VIDEO_PAUSE_SEEKING:
                    case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
                    {
                        break;
                    }
                #endif                        
                default: 
                    return MMI_FALSE;
                }
            }
            return MMI_TRUE;
        }

        /* pause key*/
        case MMI_MEDPLY_DISABLED_PAUSE:
        {
        #ifndef __MMI_MEDIA_PLAYER_FTE__
            if(mmi_medply_is_single_player_activated())
            {
                /*only interested in audio/stream play states*/
                switch(g_single.state)
                {
                #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                    case SINGLE_STATE_AUDIO_PLAY:
                    {
                        break;
                    }
                #endif                        
                #ifdef __MMI_MEDIA_PLAYER_STREAM__
                    case SINGLE_STATE_STREAM_PLAY:
                    {
                        break;
                    }
                #endif
                    default:
                    {
                        return MMI_FALSE;
                    }
                }

                switch(g_single.media_type)
                {
                #ifdef __MMI_MEDIA_PLAYER_STREAM__
                    /* check for live streaming*/
                    case MEDPLY_TYPE_STREAM_RTSP:
                    case MEDPLY_TYPE_STREAM_RAM:
                    case MEDPLY_TYPE_STREAM_SDP:
                    {
                        if(!g_single.seekable)
                        {
                            return MMI_TRUE;
                        }
                        return MMI_FALSE;
                    }
                #endif
                #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                    case MEDPLY_TYPE_AUDIO:
                    {
                        if(!g_single.is_audio_seekable)
                        {
                            return MMI_TRUE;
                        }
                        return MMI_FALSE;
                    }
                #endif
                    default:
                    {
                        return MMI_FALSE;
                    }
                }

            }

            /*only interested in audio/stream play states*/
            switch(g_medply.state)
            {
            #ifdef __MMI_MEDIA_PLAYER_STREAM__
                case MEDPLY_STATE_STREAM_PLAY:
                case MEDPLY_STATE_STREAM_AUDIO_PLAY:
                case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
                {
                    break;
                }
            #endif
            #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                case MEDPLY_STATE_AUDIO_PLAY:
                case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
                {
                    break;
                }
            #endif
                default:
                {
                    return MMI_FALSE;
                }
            }            

            switch(g_medply.media_type)
            {
            #ifdef __MMI_MEDIA_PLAYER_STREAM__
                /* check for live streaming*/
                case MEDPLY_TYPE_STREAM:
                {
                    if(!g_medply.seekable)
                    {
                        return MMI_TRUE;
                    }
                    return MMI_FALSE;
                }
            #endif
            #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                case MEDPLY_TYPE_AUDIO:
                {
                    if(!g_medply.is_audio_seekable)
                    {
                        return MMI_TRUE;
                    }
                    return MMI_FALSE;
                }
            #endif
                default:
                {
                    return MMI_FALSE;
                }
            }
        #else
            return MMI_FALSE;
        #endif
        }

        /* snapshot */
        case MMI_MEDPLY_DISABLED_SNAPSHOT:
        {
            if(mmi_medply_is_single_player_activated())
            {
            #ifdef __MMI_MEDIA_PLAYER_INTRO_PLAY__
                if(g_single.intro_play)
                {
                    return MMI_TRUE;   
                }
            #endif
                return MMI_TRUE;
            }
            
            switch(g_medply.state)
            {
            #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                case MEDPLY_STATE_AUDIO_READY:
                case MEDPLY_STATE_AUDIO_PLAY:
                case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
                case MEDPLY_STATE_AUDIO_BT_CONNECTING:
                {
                    return MMI_TRUE;
                }
            #endif
            
            #ifdef __MMI_MEDIA_PLAYER_VIDEO__            
                case MEDPLY_STATE_VIDEO_PLAY:
                case MEDPLY_STATE_VIDEO_READY:
                {
                    if(g_medply.track == MDI_VIDEO_TRACK_A_ONLY || mdi_video_ply_is_drm_file())
                    {
                        return MMI_TRUE;
                    }
                    return MMI_FALSE;
                }
            #endif
            
            #ifdef __MMI_MEDIA_PLAYER_STREAM__
                case MEDPLY_STATE_STREAM_PLAY:
                {
                    if(g_medply.track == MDI_VIDEO_TRACK_A_ONLY || mdi_video_stream_is_drm_streaming())
                    {
                        return MMI_TRUE;
                    }
                    
                    return MMI_FALSE;
                }
            #endif

                default:
                {
                    return MMI_TRUE;
                }
            }
        }

        /* full screen */
        case MMI_MEDPLY_DISABLED_ZOOM:
        {
            if(mmi_medply_is_single_player_activated())
            {
                switch(g_single.state)
                {
                    case SINGLE_STATE_IDLE:
                    case SINGLE_STATE_WAIT_NEXT:
                    /*audio*/
                #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                    case SINGLE_STATE_AUDIO_PAUSE_PROGRESSING:
                    case SINGLE_STATE_AUDIO_PLAY_PROGRESSING:
                    case SINGLE_STATE_AUDIO_WAIT_ACTIVATE:
                    case SINGLE_STATE_AUDIO_PLAY_WAIT_ACTIVATE:
                    case SINGLE_STATE_AUDIO_IN_HISTORY:
                #endif

                    /*video*/
                #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                    case SINGLE_STATE_VIDEO_PAUSE_PROGRESSING:
                    case SINGLE_STATE_VIDEO_PLAY_PROGRESSING:
                    case SINGLE_STATE_VIDEO_IN_HISTORY:
                #endif

                    /*stream*/
                #ifdef __MMI_MEDIA_PLAYER_STREAM__
                    case SINGLE_STATE_STREAM_PLAY_PROGRESSING:
                    case SINGLE_STATE_STREAM_IN_HISTORY:
                #endif

                    /*PDL*/
                #ifdef __MMI_VIDEO_PDL__
                    case SINGLE_STATE_PDL_VIDEO_PAUSE_PROGRESSING:
                    case SINGLE_STATE_PDL_VIDEO_PLAY_PROGRESSING:
                    case SINGLE_STATE_PDL_VIDEO_IN_HISTORY:
                #endif

                #ifdef __MMI_AUDIO_PDL__
                    case SINGLE_STATE_PDL_AUDIO_IN_HISTORY:
                #endif
                    {
                        return MMI_TRUE;
                    }
                    default:
                    {
                    #ifdef __MMI_MEDIA_PLAYER_INTRO_PLAY__
                        if(g_single.intro_play)
                        {
                            return MMI_TRUE;   
                        }
                        else
                    #endif
                        return MMI_FALSE;
                    }    
                }
            }
            else
            {

                switch(g_medply.state)
                {
                    case MEDPLY_STATE_IDLE:
                    case MEDPLY_STATE_WAIT_NEXT_SUSPNEDED:
                    case MEDPLY_STATE_SNAPSHOT:
                    /*audio*/
                #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                    case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:
                    case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
                    case MEDPLY_STATE_AUDIO_WAIT_ACTIVATE:
                    case MEDPLY_STATE_AUDIO_PLAY_WAIT_ACTIVATE:
                    case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING_WAIT_ACTIVATE:
                    case MEDPLY_STATE_AUDIO_INTERRUPTED_WAIT_ACTIVATE:
                    case MEDPLY_STATE_AUDIO_INTERRUPTED:
                #endif
                    /*video*/
                #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                    case MEDPLY_STATE_VIDEO_IDLE_PROGRESSING:
                    case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
                    case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:
                    case MEDPLY_STATE_PURE_AUDIO_READY:
                    case MEDPLY_STATE_PURE_AUDIO_PLAY:
                    case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
                    case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
                    case MEDPLY_STATE_VIDEO_INTERRUPTED:
                #endif
                    /*stream*/
                #ifdef __MMI_MEDIA_PLAYER_STREAM__
                    case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:
                    case MEDPLY_STATE_STREAM_AUDIO_PLAY:
                    case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
                    case MEDPLY_STATE_STREAM_INTERRUPTED:
                #endif
                    {
                        return MMI_TRUE;
                    }

                    default:
                    {
                        return MMI_FALSE;
                    }
                }
            }
        }

        /* progress bar */
        case MMI_MEDPLY_DISABLED_PROGRESS_BAR:
        {
            if(mmi_medply_is_single_player_activated())
            {
                if(g_single.seekable)
                {
                    switch(g_single.state)
                    {
                        case SINGLE_STATE_IDLE:
                #ifdef __MMI_MEDIA_PLAYER_STREAM__
                        case SINGLE_STATE_STREAM_INITED:
                        case SINGLE_STATE_STREAM_IN_HISTORY:
                #endif
                        {
                            return MMI_TRUE;
                        }

                        default:
                        {
                            return MMI_FALSE;
                        }
                    }
                }
                else
                {
                    return MMI_TRUE;
                }
            }
            else
            {
                if(g_medply.seekable)
                {
                    switch(g_medply.state)
                    {
                #ifdef __MMI_MEDIA_PLAYER_STREAM__
                        case MEDPLY_STATE_STREAM_IDLE:
                        case MEDPLY_STATE_STREAM_INITED:
                        {
                            return MMI_TRUE;
                        }
                #endif
                        default:
                        {
                            return MMI_FALSE;
                        }
                    }
                }
                else
                {
                    return MMI_TRUE;
                }
            }
        }

        case MMI_MEDPLY_DISABLED_VOL_INC:
        {
            U8 volume;

            if(mmi_medply_is_single_player_activated())
            {
                volume = g_single.volume;
            }
            else
            {
                volume = g_medply.volume;
            }

            if(volume == MDI_AUD_VOL_EX_MUTE_MAX)
            {
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        }

        case MMI_MEDPLY_DISABLED_VOL_DEC:
        {
            U8 volume;

            if(mmi_medply_is_single_player_activated())
            {
                volume = g_single.volume;
            }
            else
            {
                volume = g_medply.volume;
            }

            if(volume == MDI_AUD_VOL_EX_MUTE_MIN)
            {
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        }

        #ifdef __MMI_VIDEO_3D_ANAGLYPH__
	    case MMI_MEDPLY_DISABLED_PLAY_MODE:
		if(mmi_medply_is_single_player_activated())
		{
		    switch(g_single.state)
                    {      
                        case SINGLE_STATE_VIDEO_READY:
                        case SINGLE_STATE_VIDEO_PLAY_SEEKING:
                        case SINGLE_STATE_VIDEO_PAUSE_SEEKING:
                        case SINGLE_STATE_VIDEO_PLAY:
                        case SINGLE_STATE_VIDEO_BT_CONNECTING: 
                        case SINGLE_STATE_VIDEO_PAUSE_PROGRESSING:
                        case SINGLE_STATE_VIDEO_PLAY_PROGRESSING:  
		            if(g_single.has_3d_mode)
		            {
			            return MMI_FALSE;
		            }
                            break;
                        default:
                            break;
                    }
		}
		else 
                {
                    switch(g_medply.state)
                    {
                        case MEDPLY_STATE_VIDEO_READY:
                        case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
                        case MEDPLY_STATE_VIDEO_PAUSE_SEEKING:
                        case MEDPLY_STATE_VIDEO_PLAY:
                        case MEDPLY_STATE_VIDEO_BT_CONNECTING:
                        case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
                        case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:
                            if(g_medply.has_3d_mode)
		            {
                                return MMI_FALSE;
		            }
                            break;
               default:
                    break;
            }
        }      			
		break;
#endif

        default:
        {
            MMI_ASSERT(0);
        }
    }
		return MMI_TRUE;
}

#define MMI_MEDPLY_MMI_MDI_VIDEO_ADPTION
/*MMI-MDI adapt function, only using in media player & single player.*/
#ifdef __MMI_MEDIA_PLAYER_VIDEO__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_adption_video_seek_and_get_frame
 * DESCRIPTION
 *  this is callback handler for framework event braodcast
 * PARAMETERS
 *  mmi_event_struct*  [IN] event info
 * RETURNS
 * mmi_ret
 *****************************************************************************/
MDI_RESULT mmi_medply_adption_video_seek_and_get_frame(U64 time, 
                                   gdi_handle player_layer_handle
                                   #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                                   , gdi_handle subtitle_layer_handle
                                   #endif
                                   )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_seek_struct seek;
    MDI_RESULT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mdi_video_ply_get_default_seek_setting(&seek);
    seek.time = time;
    seek.blocking = MMI_TRUE;
    seek.get_frame = MMI_TRUE;
    seek.frame.player_layer_handle = player_layer_handle;  
    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    seek.frame.subtitle_layer_handle = subtitle_layer_handle;
    #else
    seek.frame.subtitle_layer_handle = GDI_NULL_HANDLE;
    #endif
    
    ret = mdi_video_ply_seek_ex(&seek);
    if (ret == MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED)
    {
        ret = MDI_RES_VDOPLY_SUCCEED;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_adption_video_non_block_seek_and_get_frame
 * DESCRIPTION
 *  this is callback handler for framework event braodcast
 * PARAMETERS
 *  mmi_event_struct*  [IN] event info
 * RETURNS
 * mmi_ret
 *****************************************************************************/
MDI_RESULT mmi_medply_adption_video_non_block_seek_and_get_frame(
            U64 time,
            gdi_handle player_layer_handle,
            #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
            gdi_handle subtitle_layer_handle,
            #endif
            mdi_seek_result_callback seek_result_callback,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_seek_struct seek;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mdi_video_ply_get_default_seek_setting(&seek);
    seek.time = time;
    seek.blocking = MMI_FALSE;
    seek.seek_result_callback = seek_result_callback;
    seek.user_data = user_data;

    seek.get_frame = MMI_TRUE;
    seek.frame.player_layer_handle = player_layer_handle;
    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    seek.frame.subtitle_layer_handle = subtitle_layer_handle;
    #else
    seek.frame.subtitle_layer_handle = GDI_NULL_HANDLE;
    #endif
    
    return mdi_video_ply_seek_ex(&seek);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_adption_video_get_frame
 * DESCRIPTION
 *  get seek frame.
 * PARAMETERS
 *  time : [IN]Seek time stamp.
 *  player_layer_handle : [IN]Get frame on this layer.
 * RETURN VALUES
 *  MDI_RES_VDOPLY_SUCCEED : Succeed to seek.
 *****************************************************************************/
MDI_RESULT mmi_medply_adption_video_get_frame(gdi_handle player_layer_handle
                                         #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                                         ,gdi_handle subtitle_layer_handle
                                         #endif
                                          )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_get_frame_struct frame;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mdi_video_ply_get_default_get_frame_setting(&frame);
    frame.player_layer_handle = player_layer_handle;
    
    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    frame.subtitle_layer_handle = subtitle_layer_handle;
    #endif
    
    return mdi_video_ply_get_frame_ex(&frame);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_adption_video_play
 * DESCRIPTION
 *  this is callback handler for framework event braodcast
 * PARAMETERS
 *  mmi_event_struct*  [IN] event info
 * RETURNS
 * mmi_ret
 *****************************************************************************/
MDI_RESULT mmi_medply_adption_video_play(
            gdi_handle player_layer_handle,
            U32 blt_layer_flag,
            U32 play_layer_flag,
            #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
            gdi_handle subtitle_layer_handle,
            U32 subtitle_layer_flag,
            #endif
            U16 repeat_count,
            BOOL is_visual_update,
            BOOL is_play_audio,
            U8 audio_path,
            U16 rotate,
            S16 play_speed,
            mdi_play_finish_callback play_finish_callback,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_play_struct play;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mdi_video_ply_get_default_play_setting(&play);
    
    play.player_layer_handle = player_layer_handle;
    play.blt_layer_flag = blt_layer_flag;
    play.play_layer_flag = play_layer_flag;
    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    play.subtitle_layer_handle = subtitle_layer_handle;
    play.subtitle_layer_flag = subtitle_layer_flag;
    #else
    play.subtitle_layer_handle = GDI_NULL_HANDLE;
    play.subtitle_layer_flag = 0;
    #endif
    play.repeat_count = repeat_count;
    play.is_visual_update = is_visual_update;
    play.is_play_audio = is_play_audio;
    play.audio_path = audio_path;
    play.rotate = rotate;
    play.play_speed = play_speed;
    play.play_finish_callback = play_finish_callback;
    play.user_data = user_data;
    
    return mdi_video_ply_play_ex(&play);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_adption_video_update_layer_resume
 * DESCRIPTION
 *  this is callback handler for framework event braodcast
 * PARAMETERS
 *  mmi_event_struct*  [IN] event info
 * RETURNS
 * mmi_ret
 *****************************************************************************/
MDI_RESULT mmi_medply_adption_video_update_layer_resume(
            gdi_handle player_layer_handle,
            U32 blt_layer_flag,
            U32 play_layer_flag,
            #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
            gdi_handle subtitle_layer_handle,
            U32 subtitle_layer_flag,
            #endif
            BOOL is_visual_update,
            U16 rotate) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_update_layer_resume_struct resume;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mdi_video_ply_get_default_resume_setting(&resume);
    resume.player_layer_handle = player_layer_handle;
    resume.play_layer_flag = play_layer_flag;
    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    resume.subtitle_layer_handle = subtitle_layer_handle;
    resume.subtitle_layer_flag = subtitle_layer_flag;
    #else
    resume.subtitle_layer_handle = GDI_NULL_HANDLE;
    resume.subtitle_layer_flag = 0;
    #endif
    resume.rotate = rotate;
    resume.blt_layer_flag = blt_layer_flag;
    resume.is_visual_update = is_visual_update;

    return mdi_video_ply_update_layer_resume_ex(&resume);
    
}
#endif


#if defined(__MMI_VUI_SHELL_MEDIA_PLAYER__)

void mmi_medply_refresh_shell_screen(void)
{
    
    if (mmi_idle_is_active())
    {
        mmi_id dummy_gid = 0; 
        dummy_gid = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, NULL, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        mmi_frm_display_dummy_screen();
        mmi_frm_group_close(dummy_gid);
    }
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_broadcast_event_callback_hdlr
 * DESCRIPTION
 *  this is callback handler for framework event braodcast
 * PARAMETERS
 *  mmi_event_struct*  [IN] event info
 * RETURNS
 * mmi_ret
 *****************************************************************************/
mmi_ret mmi_medply_broadcast_event_callback_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(event->evt_id)
    {
        case EVT_ID_MEDPLY_UPDATE_MAIN:
        {
            mmi_medply_update_state();
            return MMI_RET_OK;
        }

        case EVT_ID_SRV_SHUTDOWN_DEINIT:
        {
            mmi_medply_terminate_app();
            if(g_medply.is_setting_init)
            {
            /* always update settings NVRAM LID when target shut down */
            mmi_medply_settings_write_value_ext(MMI_MEDPLY_SETTINGS_TYPE_ALL, NULL, MMI_TRUE);
            /*Flash back nvram */
            WriteValue(NVRAM_MEDIA_PLAYER_MUTE, &g_medply.mute, DS_BYTE, &error);
            WriteValue(NVRAM_MEDIA_PLAYER_VOLUME, &g_medply.volume, DS_BYTE, &error);
        #ifdef __MMI_MEDIA_PLAYER_SNAPSHOT__
            WriteValue(NVRAM_MEDPLY_SNAPSHOT_SEQ_NO, &g_medply.filename_seq_no, DS_SHORT, &error);
        #endif
            }
            return MMI_RET_OK;
        }

        case EVT_ID_GPIO_CLAM_OPEN_CLOSE_QUERY_TONE:
        {
            if(!mmi_medply_is_play_activated())
            {
                return MMI_RET_OK;
            }

            return MMI_RET_ERR;
        }
        
        case EVT_ID_GPIO_LCD_SLEEP_IN:
        {
            mmi_medply_main_screen_lcd_sleep_in_handler();
            return MMI_RET_OK;
        }

        case EVT_ID_GPIO_LCD_SLEEP_OUT:
        {
            mmi_medply_main_screen_lcd_sleep_out_handler();
            return MMI_RET_OK;
        }

        case EVT_ID_GPIO_AFTER_LCD_SLEEP_IN:
        {
            return MMI_RET_OK;
        }

        case EVT_ID_SRV_PROF_PROFILE_SWITCHED:
        {
        #ifdef __MMI_PROF_MUTE_APP_ON_SILENT_MODE__
            if(srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE) > 0 || srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) > 0 )
            {
                mmi_medply_set_mute_callback();
            }
        #endif
            return MMI_RET_OK;
        }

        case EVT_ID_SRV_PROF_IS_PLAYING:
        {
            switch(g_medply.state)
            {
            #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                case MEDPLY_STATE_AUDIO_PLAY:
                case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
            #endif

            #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                case MEDPLY_STATE_VIDEO_PLAY:
                case MEDPLY_STATE_PURE_AUDIO_PLAY:
                case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
            #endif

            #ifdef __MMI_MEDIA_PLAYER_STREAM__
                case MEDPLY_STATE_STREAM_PLAY:
                case MEDPLY_STATE_STREAM_AUDIO_PLAY:
                case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
            #endif
                {
                    return !MMI_RET_OK;
                }

                default:
                    return MMI_RET_OK;
            }

        }

    #ifdef __MMI_USB_SUPPORT__
        case EVT_ID_USB_ENTER_MS_MODE:
        {
            mmi_medply_stop_playing();
            return MMI_RET_OK;
        }
        case EVT_ID_USB_EXIT_MS_MODE:
        {
                
#if defined(__MMI_VUI_SHELL_MEDIA_PLAYER__)
            StartTimer(MEDPLY_STATUS_ICON_TIMER, 20, mmi_medply_refresh_shell_screen);
#endif
            return MMI_RET_OK;
        }
    #endif

        #ifdef __MMI_SCREEN_LOCK_ANY_TIME__
        case EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING:
        	if(mmi_medply_is_single_player_activated())
          {
        	    switch(g_single.state)
              {
                  #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                  case SINGLE_STATE_VIDEO_OPENING:
                  case SINGLE_STATE_VIDEO_PLAY:
                  case SINGLE_STATE_VIDEO_PLAY_SEEKING:
                  case SINGLE_STATE_VIDEO_BT_CONNECTING:
                  #endif
                  
                  #ifdef __MMI_MEDIA_PLAYER_STREAM__
                  case SINGLE_STATE_STREAM_CONNECTING:
                  case SINGLE_STATE_STREAM_BUFFERING:
                  case SINGLE_STATE_STREAM_PLAY_PROGRESSING:
                  case SINGLE_STATE_STREAM_BT_CONNECTING:
                  case SINGLE_STATE_STREAM_PLAY:
                  #endif
                  
                  #ifdef __MMI_VIDEO_PDL__
                  case SINGLE_STATE_PDL_VIDEO_OPENING:
                  case SINGLE_STATE_PDL_VIDEO_PLAY:
                  case SINGLE_STATE_PDL_VIDEO_PLAY_BUFFERING:
                  case SINGLE_STATE_PDL_VIDEO_PLAY_PROGRESSING:
                  case SINGLE_STATE_PDL_VIDEO_PLAY_SEEKING:
                  case SINGLE_STATE_PDL_VIDEO_BT_CONNECTING:
                  #endif
                  {
                      mmi_scr_locker_pre_lock_evt_struct* lock_event = (mmi_scr_locker_pre_lock_evt_struct*)event;
                      if(lock_event->lock_mode == MMI_SCR_LOCKER_LOCK_MODE_POWER_KEY)
                      {
              	          return MMI_RET_OK;
                      }
                      else
                      {
                          return MMI_RET_ERR;
                      }
                  }
                  default:
          	          return MMI_RET_OK; 
          	  }         
          }
          else
          {
              switch(g_medply.state)
              {
              	  #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                  case MEDPLY_STATE_VIDEO_OPENING:
                  case MEDPLY_STATE_VIDEO_PLAY:
                  case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:
                  case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
                  case MEDPLY_STATE_VIDEO_BT_CONNECTING:
                  #endif
                  	
                   #ifdef __MMI_MEDIA_PLAYER_STREAM__
                  case MEDPLY_STATE_STREAM_CONNECTING:
                  case MEDPLY_STATE_STREAM_BUFFERING:
                  case MEDPLY_STATE_STREAM_PLAY:
                  case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:
                  case MEDPLY_STATE_STREAM_BT_CONNECTING:
                  #endif
                  {
                      mmi_scr_locker_pre_lock_evt_struct* lock_event = (mmi_scr_locker_pre_lock_evt_struct*)event;
                      if(lock_event->lock_mode == MMI_SCR_LOCKER_LOCK_MODE_POWER_KEY)
                      {
              	          return MMI_RET_OK;
                      }
                      else
                      {
                          return MMI_RET_ERR;
                      }
                  }
                  default:
          	          return MMI_RET_OK; 
          	  }             
          }
        #endif

        default:
        {
            return MMI_RET_OK;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_is_play_activated
 * DESCRIPTION
 *  check if mediaplayer is currently playing or prepare to play
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_is_play_activated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_IS_PLAY_ACTIVATED,g_medply.state);
    
    switch(g_medply.state)
    {
        case MEDPLY_STATE_IDLE:
        case MEDPLY_STATE_WAIT_NEXT_SUSPNEDED:
        case MEDPLY_STATE_AUDIO_READY:
        case MEDPLY_STATE_AUDIO_INTERRUPTED:
        case MEDPLY_STATE_AUDIO_INTERRUPTED_WAIT_ACTIVATE:
        case MEDPLY_STATE_AUDIO_WAIT_ACTIVATE:

        case MEDPLY_STATE_VIDEO_IDLE:
        case MEDPLY_STATE_VIDEO_READY:
        case MEDPLY_STATE_VIDEO_INTERRUPTED:
        case MEDPLY_STATE_STREAM_IDLE:
        case MEDPLY_STATE_STREAM_INITED:
        case MEDPLY_STATE_STREAM_CONNECTED:
        case MEDPLY_STATE_STREAM_INTERRUPTED:
        {
            return MMI_FALSE;
        }

        case MEDPLY_STATE_PURE_AUDIO_READY:
        {
            if(g_medply.continue_to_play)
            {
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        }

        default:
        {
            return MMI_TRUE;
        }        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_if_show_idle_string
 * DESCRIPTION
 *  check if mediaplayer is currently playing so idle screen can be shown
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_if_show_idle_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_IF_SHOW_IDLE_STRING,g_medply.state);
    
    switch(g_medply.state)
    {
        case MEDPLY_STATE_AUDIO_PLAY:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
        case MEDPLY_STATE_VIDEO_PLAY:
        case MEDPLY_STATE_PURE_AUDIO_PLAY:
        case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
        case MEDPLY_STATE_STREAM_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
        {
            return MMI_TRUE;
        }

        default:
        {
            return MMI_FALSE;
        }        
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_get_idle_string
 * DESCRIPTION
 *  for idle screen to get string to show
 * PARAMETERS
 *  void
 * RETURNS
 *  UI_string_type
 *****************************************************************************/
UI_string_type mmi_medply_get_idle_string(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    return (UI_string_type) g_medply.idle_string;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_set_continue_flag
 * DESCRIPTION
 *  set/reset continue flag
 * PARAMETERS
 *  MMI_BOOL    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_set_continue_flag(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_SET_CONTINUE_FLAG,flag);
    
    g_medply.continue_to_play = flag;
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_set_self_stop_flag
 * DESCRIPTION
 *  set/reset self stop flag
 * PARAMETERS
 *  MMI_BOOL    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_set_self_stop_flag(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_SET_STOP_FLAG,flag);
    g_medply.self_stop = flag;
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_set_pop_up_flag
 * DESCRIPTION
 *  set pop up flag; this flag shall be called right before pop up so that
 *  exit main screen will skip processing and reset this flag
 *  so that only pop up which will affect states need to set this flag, most
 *  audio state pop up need not to set.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_set_pop_up_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_SET_POPUP_FLAG,g_medply.in_main_screen);
    if(g_medply.in_main_screen)
    {
        g_medply.pop_up = MMI_TRUE;
    }
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_wait_next_time_out
 * DESCRIPTION
 *  handle wait next time out, play next media file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_wait_next_time_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bg_suspend = MMI_FALSE;
    S32 order = -1;
    U8 empty = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_WAIT_NEXT_TIME_OUT,g_medply.state,MMI_FALSE);

#if !defined( __RF_DESENSE_TEST__) && !defined(__CS_STREAMING_CONCURRENT_SUPPORT__)
    bg_suspend = mdi_audio_is_background_play_suspended();
#endif
    order = mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_MEDPLY);
    empty = mdi_audio_get_background_callback_register_app_num();

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_TRC_MEDPLY_FOUR_VALS,bg_suspend,order,empty,-1);

    /*check if someone calls suspend background play during wait next time*/
    if (bg_suspend || (order != 0 && empty != 0))
    {
        if(g_medply.state == MEDPLY_STATE_WAIT_NEXT)
        {
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT_SUSPNEDED);
        }
        return;
    }

    /* in case entery main screen and time out happened at the same time, so that
       this will be executed two times*/
    if(g_medply.state == MEDPLY_STATE_WAIT_NEXT)
    {
        mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_stop_wait_next_timer
 * DESCRIPTION
 *  stop wait next timer and reset wait_next_with_pop_up flag to flase
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_stop_wait_next_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(MEDPLY_WAIT_NEXT_TIMER);
    g_medply.wait_next_with_pop_up = MMI_FALSE;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_pop_up_start_wait_next_timer
 * DESCRIPTION
 *  for display callback with pop up ext, when pop up is forced to exit inestead of
 *  time out exit, this callback will be triggered
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_pop_up_start_wait_next_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_medply.wait_next_with_pop_up)
    {
        StartTimer(MEDPLY_WAIT_NEXT_TIMER, 1100, mmi_medply_wait_next_time_out);
        g_medply.wait_next_with_pop_up = MMI_FALSE;
    }

}
    
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_pop_up_wait_next_callback
 * DESCRIPTION
 *  for pop up duration is not static since 09A, so wait next with pop up need to 
 *  start wait next timer right after pop up exit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_pop_up_wait_next_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

    mmi_medply_pop_up_start_wait_next_timer();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_wait_next_time_out
 * DESCRIPTION
 *  show/hide media player status icon
 * PARAMETERS
 *  MMI_BOOL    [IN]    show: MMI_TRUE, hide: MMI_FALSE
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_show_hide_staus_icon(MMI_BOOL show_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_SHOW_HIDE_ICON,show_icon);

    if(show_icon)
    {
        wgui_status_icon_bar_set_icon_display(STATUS_ICON_MEDPLY);
    }
    else
    {
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_MEDPLY);
    }

    if(!g_medply.fullscreen)
    {
        StartTimer(MEDPLY_STATUS_ICON_TIMER,100,wgui_status_icon_bar_update);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_update_staus_icon
 * DESCRIPTION
 *  show/hide media player status icon
 * PARAMETERS
 *  MMI_BOOL    [IN]    show: MMI_TRUE, hide: MMI_FALSE
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_update_staus_icon()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_UPDATE_ICON,g_medply.state);

    switch(g_medply.state)
    {
        case MEDPLY_STATE_AUDIO_PLAY:
        case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:

        case MEDPLY_STATE_VIDEO_PLAY:
        case MEDPLY_STATE_PURE_AUDIO_PLAY:
        case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:

        case MEDPLY_STATE_STREAM_AUDIO_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
        case MEDPLY_STATE_STREAM_PLAY:
        {
            mmi_medply_show_hide_staus_icon(MMI_TRUE);
            break;
        }

        default:
        {
            mmi_medply_show_hide_staus_icon(MMI_FALSE);
            break;
        }

    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_update_current_time
 * DESCRIPTION
 *  update current time continuously while in play states
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_update_current_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 current_time = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(g_medply.state)
    {
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        case MEDPLY_STATE_AUDIO_PLAY:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
        case MEDPLY_STATE_AUDIO_PLAY_WAIT_ACTIVATE:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING_WAIT_ACTIVATE:
        {
            mdi_result result = MDI_AUDIO_SUCCESS;
            result = mdi_audio_get_progress_time((U32*)&current_time);
            if(result != MDI_AUDIO_SUCCESS)
            {
                return;
            }
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
        case MEDPLY_STATE_VIDEO_PLAY:
        {
            mdi_video_ply_get_cur_play_time(&current_time);
            break;
        }
        case MEDPLY_STATE_PURE_AUDIO_PLAY:
        case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
        {
            mdi_result result = MDI_AUDIO_SUCCESS;
            result = mdi_audio_get_progress_time((U32*)&current_time);
            if(result != MDI_AUDIO_SUCCESS)
            {
                return;
            }
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

    #ifdef __MMI_MEDIA_PLAYER_STREAM__
        case MEDPLY_STATE_STREAM_AUDIO_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
        case MEDPLY_STATE_STREAM_PLAY:
        {
            mdi_video_stream_get_cur_play_time(&current_time);
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_STREAM__*/

        case MEDPLY_STATE_SNAPSHOT:
        {
            break;
        }

        default:
        {
            return;
        }
    }

    g_medply.current_time = current_time;

    if(g_medply.current_time > g_medply.duration)
    {
        g_medply.duration = g_medply.current_time;
    }

    StartTimer(MEDPLY_UPDATE_TIME_TIMER, 250, mmi_medply_update_current_time);

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_UPDATE_TIME,g_medply.state,g_medply.current_time, MMI_FALSE);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_get_build_cache_process
 * DESCRIPTION
 *  for querying cached duration
 *  return MMI_FALSE if no need to build cache
 * PARAMETERS
 *  cached_dur [OUT]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_get_build_cache_process(U64 *cached_dur)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 duration = 0;
    MMI_BOOL result = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

#ifdef __MTK_TARGET__
#ifdef __MMI_MEDIA_PLAYER_AUDIO__
    if(mmi_medply_is_single_player_activated())
    {
        if(g_single.need_to_build_cache)
        {
            U32 a_duration = 0 ;

            mmi_medply_single_build_cache_update_dur_hdlr();

            if(g_single.audio_build_cache_process >= 100)
            {
                duration = g_single.duration;
            }
            else
            {
                if(!mdi_audio_build_cache_get_cache_duration(&a_duration))
                {
                    a_duration = 0;
                }

                if(a_duration > g_single.current_time)
                {
                    if(a_duration > g_single.audio_cached_duration)
                    {
                        g_single.audio_cached_duration = a_duration;
                    }
                }
                else
                {
                    if(g_single.current_time > g_single.audio_cached_duration)
                    {
                        g_single.audio_cached_duration = (U32)g_single.current_time;
                    }
                }

                duration = (U64)g_single.audio_cached_duration;
            }
            result = MMI_TRUE;
        }
    }
    else
    {
        if(g_medply.need_to_build_cache)
        {
            U32 a_duration = 0 ;

            mmi_medply_build_cache_update_dur_hdlr();

            if(g_medply.audio_build_cache_process >= 100)
            {
                duration = g_medply.duration;
            }
            else
            {
                if(!mdi_audio_build_cache_get_cache_duration(&a_duration))
                {
                    a_duration = 0 ;
                }

                if(a_duration > g_medply.current_time)
                {
                    if(a_duration > g_medply.audio_cached_duration)
                    {
                        g_medply.audio_cached_duration = a_duration;
                    }
                }
                else
                {
                    if(g_medply.current_time > g_medply.audio_cached_duration)
                    {
                        g_medply.audio_cached_duration = (U32)g_medply.current_time;
                    }
                }

                duration = (U64)g_medply.audio_cached_duration;
            }
            result = MMI_TRUE;
        }
    }
#endif
#endif /*__MTK_TARGET__*/

#ifdef __MMI_VIDEO_PDL__
    if(mmi_medply_is_single_player_activated())
    {
        if(g_single.media_type == MEDPLY_TYPE_PDL_VIDEO)
        {
            duration = g_single.pdl_video_max_play_time;
            result = MMI_TRUE;
        }
    }
#endif

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_BUILD_CACHE_PROCESS, duration, result);
    *cached_dur = duration;

    return result;
    
}

#ifdef __MMI_MEDIA_PLAYER_AUDIO__

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_initialize_cache
 * DESCRIPTION
 *  initialize the cache
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_initialize_cache()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset( g_medply_audio_cache, 0, MEDPLY_BUILD_CACHE_SIZE ); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_refresh_cache
 * DESCRIPTION
 *  initialize cache and reset some values
 *  this function shall be called every time goes to another song
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_refresh_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_REFRESH_CACHE);

    /*refresh the build cache values and initialize cache*/
    mdi_audio_close_build_cache();
    g_medply.audio_build_cache_process = 0 ;
    g_medply.audio_cached_duration = 0 ;
    mdi_audio_reset_build_cache_variables();
    mmi_medply_initialize_cache();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_enter_audio_states
 * DESCRIPTION
 *  enter audio state and redraw main screen
 * PARAMETERS
 *  entered_audio_state     [IN]    entered audio state
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_enter_audio_states(mmi_medply_state_enum entered_audio_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_AUD_STATE,g_medply.state,entered_audio_state,g_medply.continue_to_play);

    switch(g_medply.affected_button_down)
    {
        case MMI_MEDPLY_RGN_ID_ZOOM:
        {
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_ZOOM,
                    MMI_MEDPLY_RGN_STATUS_UP);
            mmi_medply_main_screen_blt();
            break;
        }

        case MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY:
        case MMI_MEDPLY_RGN_ID_ACTIVATE:
        {
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY,
                    MMI_MEDPLY_RGN_STATUS_UP);
            mmi_medply_main_screen_blt();
            break;        
        }

        default:
        {
            break;
        }
    }

    g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_NULL;

    g_medply.prev_state = g_medply.state;
    g_medply.state = entered_audio_state;

    switch (entered_audio_state)
    {
        case MEDPLY_STATE_AUDIO_READY:
        {

        #ifdef __BT_SPK_VOL_CONTROL__
            if(!g_medply.in_main_screen)
            {
                mdi_audio_bt_clear_volume_sync_callback(APP_MEDPLY);
            }
        #endif

            if(g_medply.continue_to_play)
            {
                mmi_medply_set_continue_flag(MMI_FALSE);
                mmi_medply_audio_play();
            }
            else
            {
                StopTimer(MEDPLY_UPDATE_TIME_TIMER);
                mmi_medply_change_status(MMI_TRUE);
            }
            break;
        }
        
        case MEDPLY_STATE_AUDIO_BT_CONNECTING:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);
            mmi_medply_change_status(MMI_TRUE);
            break;
        }

        case MEDPLY_STATE_AUDIO_PLAY:
        {
            StartTimer(MEDPLY_UPDATE_TIME_TIMER, 250, mmi_medply_update_current_time);
            mmi_medply_change_status(MMI_TRUE);
        #ifdef __BT_SPK_VOL_CONTROL__
            mdi_audio_bt_register_volume_sync_callback(APP_MEDPLY,MDI_AUD_VOL_LEVEL_EXTEND_MUTE,mmi_medply_handfree_volume_sync_callback);
        #endif
            // enable later: mmi_medply_plst_increase_played_counter();
            break;
        }

        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
        {
            StartTimer(MEDPLY_UPDATE_TIME_TIMER, 250, mmi_medply_update_current_time);
            mmi_medply_change_status(MMI_TRUE);
            break;
        }

        case MEDPLY_STATE_AUDIO_INTERRUPTED:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);
            mmi_medply_change_status(MMI_TRUE);

        #ifdef __BT_SPK_VOL_CONTROL__
            if(!g_medply.in_main_screen)
            {
                mdi_audio_bt_clear_volume_sync_callback(APP_MEDPLY);
            }
        #endif

            break;
        }

        case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);
            mmi_medply_change_status(MMI_TRUE);
            break;
        }

        case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);
            mmi_medply_change_status(MMI_TRUE);
            break;
        }

    }

    mmi_medply_update_staus_icon();

    mmi_idle_update_service_area();
}
#endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

#ifdef __MMI_MEDIA_PLAYER_VIDEO__

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_video_enter_pure_audio_ready_check
 * DESCRIPTION
 *  since entering video ready state might pop up fail to play or other error cases
 *  this is not allowed while exit screen, so utilize timer and this api to delay
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_video_enter_pure_audio_ready_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if(g_medply.in_main_screen)
    {
        /*if entering main screen before time out, shall ignore this hdlr*/
        return;
    }

    if(!mdi_audio_is_idle() || mdi_audio_is_speech_mode() || mdi_audio_is_background_play_suspended())
    {
        mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_INTERRUPTED);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_video_enter_pure_audio_ready_state
 * DESCRIPTION
 *  since entering video ready state might pop up fail to play or other error cases
 *  this is not allowed while exit screen, so utilize timer and this api to delay
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_video_enter_pure_audio_ready_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_VDO_TIMEOUT,g_medply.state,g_medply.in_main_screen);
    if(g_medply.in_main_screen)
    {
        /*if entering main screen before time out, shall ignore this hdlr*/
        return;
    }

    if(!mdi_audio_is_idle() || mdi_audio_is_speech_mode() || mdi_audio_is_background_play_suspended())
    {
        mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_INTERRUPTED);
    }
    else
    {
        mmi_medply_set_continue_flag(MMI_FALSE);
        /* After all state transition need to update status icon and service area */
        mmi_medply_update_staus_icon();
        mmi_idle_update_service_area();
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_enter_video_states
 * DESCRIPTION
 *  enter video state and redraw main screen
 * PARAMETERS
 *  entered_video_state     [IN]    entered video state
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_enter_video_states(mmi_medply_state_enum entered_video_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_VDO_STATE,g_medply.state,entered_video_state,g_medply.continue_to_play);

    switch(g_medply.affected_button_down)
    {
        case MMI_MEDPLY_RGN_ID_ZOOM:
        {
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_ZOOM,
                    MMI_MEDPLY_RGN_STATUS_UP);
            mmi_medply_main_screen_blt();
            break;
        }

        case MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY:
        case MMI_MEDPLY_RGN_ID_ACTIVATE:
        {
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY,
                    MMI_MEDPLY_RGN_STATUS_UP);
            mmi_medply_main_screen_blt();
            break;        
        }

        #ifdef __MMI_VIDEO_3D_ANAGLYPH__
        case MMI_MEDPLY_RGN_ID_MODE:
        {
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_MODE,
                    MMI_MEDPLY_RGN_STATUS_UP);
            mmi_medply_main_screen_blt();

        #ifdef __MMI_TOUCH_SCREEN__
            g_medply.pen_on_object = MMI_MEDPLY_RGN_ID_NULL;
        #endif
            break;        
        }
        #endif

        default:
        {
            break;
        }
    }


    g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_NULL;

    g_medply.prev_state = g_medply.state;
    g_medply.state = entered_video_state;

    switch (entered_video_state)
    {
        case MEDPLY_STATE_VIDEO_IDLE:
        case MEDPLY_STATE_VIDEO_IDLE_PROGRESSING:
        case MEDPLY_STATE_VIDEO_IDLE_BT_CONNECTING:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);
            mmi_medply_change_status(MMI_TRUE);
            break;
        }

        case MEDPLY_STATE_VIDEO_OPENING:
        {            
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);
            mmi_medply_change_status(MMI_TRUE);
            break;
        }

        case MEDPLY_STATE_VIDEO_READY:
        {
            if(g_medply.continue_to_play)
            {
                mmi_medply_set_continue_flag(MMI_FALSE);
                mmi_medply_video_play();
            }
            else
            {   
                StopTimer(MEDPLY_UPDATE_TIME_TIMER);
                mmi_medply_change_status(MMI_TRUE);
            }
            
            break;
        }

        case MEDPLY_STATE_PURE_AUDIO_READY:
        {

        #ifdef __BT_SPK_VOL_CONTROL__
            if(!g_medply.in_main_screen)
            {
                mdi_audio_bt_clear_volume_sync_callback(APP_MEDPLY);
            }
        #endif

            if(g_medply.continue_to_play)
            {
                mmi_medply_set_continue_flag(MMI_FALSE);
                mmi_medply_video_play();
            }
            else
            {
                StopTimer(MEDPLY_UPDATE_TIME_TIMER);
                mmi_medply_change_status(MMI_FALSE);
            }
            break;
        }

        case MEDPLY_STATE_VIDEO_PLAY:
        {
            StartTimer(MEDPLY_UPDATE_TIME_TIMER, 250, mmi_medply_update_current_time);
            mmi_medply_change_status(MMI_TRUE);
            // enable later: mmi_medply_plst_increase_played_counter();
            break;
        }

        case MEDPLY_STATE_PURE_AUDIO_PLAY:
        {
            StartTimer(MEDPLY_UPDATE_TIME_TIMER, 250, mmi_medply_update_current_time);
            mmi_medply_change_status(MMI_TRUE);

        #ifdef __BT_SPK_VOL_CONTROL__
            mdi_audio_bt_register_volume_sync_callback(APP_MEDPLY,MDI_AUD_VOL_LEVEL_EXTEND_MUTE,mmi_medply_handfree_volume_sync_callback);
        #endif
            // enable later: mmi_medply_plst_increase_played_counter();
            break;
        }

        case MEDPLY_STATE_VIDEO_BT_CONNECTING:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);
            mmi_medply_change_status(MMI_TRUE);  
            break;
        }

        case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);
            mmi_medply_change_status(MMI_TRUE);
            break;
        }

        case MEDPLY_STATE_VIDEO_PAUSE_SEEKING:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);            
            mmi_medply_change_status(MMI_TRUE);
            break;
        }

        case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);
            mmi_medply_change_status(MMI_TRUE);
            break;
        }

        case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);
            mmi_medply_change_status(MMI_TRUE);
            break;
        }

        case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);
            mmi_medply_change_status(MMI_TRUE);
            break;
        }

        case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);
            mmi_medply_change_status(MMI_TRUE);            
            break;
        }

        case MEDPLY_STATE_VIDEO_INTERRUPTED:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);
            mmi_medply_change_status(MMI_TRUE);

        #ifdef __BT_SPK_VOL_CONTROL__
            if(!g_medply.in_main_screen)
            {
                mdi_audio_bt_clear_volume_sync_callback(APP_MEDPLY);
            }
        #endif

            break;
        }
        
    }

    mmi_medply_update_staus_icon();

    mmi_idle_update_service_area();
}

#endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

#ifdef __MMI_MEDIA_PLAYER_STREAM__

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_enter_stream_states
 * DESCRIPTION
 *  enter stream state and redraw main screen
 * PARAMETERS
 *  entered_stream_state     [IN]    entered stream state
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_enter_stream_states(mmi_medply_state_enum entered_stream_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_STREAM_STATE,g_medply.state,entered_stream_state,g_medply.continue_to_play);

    switch(g_medply.affected_button_down)
    {
        case MMI_MEDPLY_RGN_ID_ZOOM:
        {
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_ZOOM,
                    MMI_MEDPLY_RGN_STATUS_UP);
            mmi_medply_main_screen_blt();
            break;
        }

        case MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY:
        case MMI_MEDPLY_RGN_ID_ACTIVATE:
        {
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY,
                    MMI_MEDPLY_RGN_STATUS_UP);
            mmi_medply_main_screen_blt();
            break;        
        }

        default:
        {
            break;
        }
    }

    g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_NULL;

    g_medply.prev_state = g_medply.state;
    g_medply.state = entered_stream_state;

    if(g_medply.prev_state == MEDPLY_STATE_STREAM_BUFFERING)
    {
        StopTimer(MEDPLY_STREAM_BUFFER_TIMER);
    }

    switch (entered_stream_state)
    {
        case MEDPLY_STATE_STREAM_IDLE:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);
            mmi_medply_change_status(MMI_TRUE);
            break;
        }

        case MEDPLY_STATE_STREAM_INITED:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);
            g_medply.seekable = MMI_FALSE;
            mmi_medply_main_screen_draw_duration();
            mmi_medply_main_screen_blt();

            mmi_medply_change_status(MMI_TRUE);
            break;
        }

        case MEDPLY_STATE_STREAM_CONNECTING:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);
            mmi_medply_change_status(MMI_TRUE);
            break;
        }

        case MEDPLY_STATE_STREAM_CONNECTED:
        {

        #ifdef __BT_SPK_VOL_CONTROL__
            if(!g_medply.in_main_screen)
            {
                mdi_audio_bt_clear_volume_sync_callback(APP_MEDPLY);
            }
        #endif

            if(g_medply.continue_to_play)
            {
                mmi_medply_set_continue_flag(MMI_FALSE);
                mmi_medply_change_status(MMI_FALSE);
                mmi_medply_stream_buffer();
            }
            else
            {   
                StopTimer(MEDPLY_UPDATE_TIME_TIMER);
                mmi_medply_change_status(MMI_TRUE);
            }
            
            break;
        }

        case MEDPLY_STATE_STREAM_BT_CONNECTING:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);
            mmi_medply_change_status(MMI_TRUE);
            break;
        }   

        case MEDPLY_STATE_STREAM_BUFFERING:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);
            mmi_medply_change_status(MMI_TRUE);
            break;
        }

        case MEDPLY_STATE_STREAM_PLAY:
        {
            StartTimer(MEDPLY_UPDATE_TIME_TIMER, 250, mmi_medply_update_current_time);
            mmi_medply_change_status(MMI_TRUE);
            break;
        }

        case MEDPLY_STATE_STREAM_AUDIO_PLAY:
        {
            StartTimer(MEDPLY_UPDATE_TIME_TIMER, 250, mmi_medply_update_current_time);
            mmi_medply_change_status(MMI_FALSE);

        #ifdef __BT_SPK_VOL_CONTROL__
            mdi_audio_bt_register_volume_sync_callback(APP_MEDPLY,MDI_AUD_VOL_LEVEL_EXTEND_MUTE,mmi_medply_handfree_volume_sync_callback);
        #endif

            break;
        }

        case MEDPLY_STATE_STREAM_INTERRUPTED:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);
            mmi_medply_change_status(MMI_TRUE);

        #ifdef __BT_SPK_VOL_CONTROL__
            if(!g_medply.in_main_screen)
            {
                mdi_audio_bt_clear_volume_sync_callback(APP_MEDPLY);
            }
        #endif

            break;
        }
    }

    mmi_medply_update_staus_icon();

    mmi_idle_update_service_area();
}

#endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_release_media_based_key
 * DESCRIPTION
 *  when media changed, we have to reset media_based key from down to up
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_release_media_based_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

#if  defined(__MMI_MEDIA_PLAYER_FTE__)

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_RELEASE_MEDIA_BASED,g_medply.media_based_button_down);

    if(g_medply.media_based_button_down != MMI_MEDPLY_RGN_ID_NULL)
    {
        switch(g_medply.media_based_button_down)
        {

        #ifdef __MMI_MEDIA_PLAYER_FTE__
            case MMI_MEDPLY_RGN_ID_USER_RATING:
            {
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_USER_RATING,
                    MMI_MEDPLY_RGN_STATUS_UP);
                break;
            }
        #endif

            default:
            {
                break;
            }
        }
    }

    g_medply.media_based_button_down = MMI_MEDPLY_RGN_ID_NULL;
    
#endif

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_enter_core_states
 * DESCRIPTION
 *  enter core state. if entering idle state, then check whether need to go 
 *  to next state of that media type or not.
 * PARAMETERS
 *  entered_audio_state     [IN]    entered core state
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_enter_core_states(mmi_medply_state_enum entered_core_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_CORE_STATE,g_medply.state,entered_core_state,g_medply.continue_to_play);

    switch(g_medply.affected_button_down)
    {
        case MMI_MEDPLY_RGN_ID_ZOOM:
        {
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_ZOOM,
                    MMI_MEDPLY_RGN_STATUS_UP);
            mmi_medply_main_screen_blt();

        #ifdef __MMI_TOUCH_SCREEN__
            g_medply.pen_on_object = MMI_MEDPLY_RGN_ID_NULL;
        #endif
            break;
        }

        case MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY:
        {
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY,
                    MMI_MEDPLY_RGN_STATUS_UP);
            mmi_medply_main_screen_blt();

        #ifdef __MMI_TOUCH_SCREEN__
            g_medply.pen_on_object = MMI_MEDPLY_RGN_ID_NULL;
        #endif
            break;        
        }

        #ifdef __MMI_VIDEO_3D_ANAGLYPH__
        case MMI_MEDPLY_RGN_ID_MODE:
        {
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_MODE,
                    MMI_MEDPLY_RGN_STATUS_UP);
            mmi_medply_main_screen_blt();

        #ifdef __MMI_TOUCH_SCREEN__
            g_medply.pen_on_object = MMI_MEDPLY_RGN_ID_NULL;
        #endif
            break;        
        }
        #endif

        default:
        {
            break;
        }
    }

    g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_NULL;

    g_medply.prev_state = g_medply.state;
    g_medply.state = entered_core_state;


#ifdef __MMI_MEDIA_PLAYER_STREAM__    
    if(g_medply.prev_state == MEDPLY_STATE_STREAM_BUFFERING)
    {
        StopTimer(MEDPLY_STREAM_BUFFER_TIMER);
    }
#endif

    switch (entered_core_state)
    {   
        /*before enter wait next state, next song shall be picked already
          enter wait next will not do the pick next job*/
        case MEDPLY_STATE_WAIT_NEXT:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);

            mmi_medply_clear_play_seconds();

        #ifdef __BT_SPK_VOL_CONTROL__
            if(!g_medply.in_main_screen)
            {
                mdi_audio_bt_clear_volume_sync_callback(APP_MEDPLY);
            }
        #endif

            if(!g_medply.wait_next_with_pop_up)
            {
                StartTimer(MEDPLY_WAIT_NEXT_TIMER, 700, mmi_medply_wait_next_time_out);
            }

            mmi_medply_release_media_based_key();
            mmi_medply_change_status(MMI_TRUE);

            break;
        }

        case MEDPLY_STATE_IDLE:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);

        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            g_medply.DRM_consumed = MMI_FALSE;
        #endif

            mmi_medply_release_media_based_key();

        #ifdef __MMI_A2DP_SUPPORT__
        #ifdef __MMI_MEDIA_PLAYER_VIDEO__
            g_medply.bt_connect_fail = MMI_FALSE;
        #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/
            g_medply.inquiry_paused = MMI_FALSE;
        #endif /*__MMI_A2DP_SUPPORT__*/

            mmi_medply_clear_play_seconds();

        #ifdef __BT_SPK_VOL_CONTROL__
            if(!g_medply.in_main_screen)
            {
                mdi_audio_bt_clear_volume_sync_callback(APP_MEDPLY);
            }
        #endif

            switch (g_medply.media_type)
            {
            #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                case MEDPLY_TYPE_AUDIO:
                {
                    mmi_medply_util_fill_idle_display_str();
                    mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
                    break;
                }
            #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

            #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                case MEDPLY_TYPE_VIDEO:
                {
                    mmi_medply_util_fill_idle_display_str();                    
                    if(g_medply.in_main_screen)
                    {
                        if(g_medply.continue_to_play)
                        {
                            mmi_medply_video_open();
                        }
                        else
                        {
                            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
                            mmi_medply_change_status(MMI_TRUE);
                        }
                    }
                    else
                    {
                        mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_READY);
                    }
                    break;
                }
            #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

            #ifdef __MMI_MEDIA_PLAYER_STREAM__
                case MEDPLY_TYPE_STREAM:
                {
                    mmi_medply_util_fill_idle_display_str();                    
                    if(g_medply.continue_to_play)
                    {
                        mmi_medply_set_continue_flag(MMI_FALSE);
                        if(mmi_medply_stream_init())
                        {
                            mmi_medply_stream_connect();
                        }
                    }
                    else
                    {
                        mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
                        mmi_medply_change_status(MMI_TRUE);
                    }
                    break;
                }
            #endif /*__MMI_MEDIA_PLAYER_STREAM__*/

                case MEDPLY_TYPE_NONE:
                {
                    mmi_medply_set_continue_flag(MMI_FALSE);

                    if(g_medply.fullscreen)
                    {
                        mmi_medply_clear_play_seconds();
                        mmi_medply_main_screen_set_full_screen(MMI_FALSE);
                        if(g_medply.media_type != MEDPLY_TYPE_AUDIO)
                        {
                            mmi_medply_main_screen_clear_video_layer();
                        }

                        g_medply.fullscreen = MMI_FALSE;

                        /*register key hdlr*/
                        mmi_medply_register_key_hdlrs(MMI_MEDPLY_SCREEN_NORMAL);
                    }

                    mmi_medply_change_status(MMI_TRUE);
                    break;
                }

                default:
                {
                    MMI_ASSERT(0);
                    break;
                }
            }
            
            break;
        }

        case MEDPLY_STATE_WAIT_NEXT_SUSPNEDED:
        case MEDPLY_STATE_SNAPSHOT:
        {
            mmi_medply_change_status(MMI_TRUE);
            break;
        }
    }

    mmi_medply_update_staus_icon();

    mmi_idle_update_service_area();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_clear_play_seconds
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_clear_play_seconds(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_CLEAR_TIME);

    g_medply.current_time = 0;
    g_medply.old_play_time = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_set_curret_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  U64    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_set_curret_time(U64 time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_SET_TIME, time);

    g_medply.current_time = time;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_stop_button_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_stop_button_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_STOP_DOWN,g_medply.selected_button,MMI_FALSE);
    
    if(g_medply.selected_button == MEDPLY_MAIN_DISABLED)
    {
        return;
    }
    g_medply.selected_button = MEDPLY_MAIN_STOP;
    g_medply.selected_button_down = MMI_TRUE;

    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_STOP,
        MMI_MEDPLY_RGN_STATUS_DOWN);
    mmi_medply_main_screen_blt();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_stop_button_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_stop_button_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_STOP_UP,g_medply.selected_button,g_medply.selected_button_down,g_medply.state, MMI_FALSE);
    
    if(g_medply.selected_button != MEDPLY_MAIN_STOP || g_medply.selected_button_down != MMI_TRUE)
    {
        return;
    }

    g_medply.selected_button_down = MMI_FALSE;

    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_STOP,
        MMI_MEDPLY_RGN_STATUS_UP);
    mmi_medply_main_screen_blt();

    switch(g_medply.state)
    {
        case MEDPLY_STATE_WAIT_NEXT_SUSPNEDED:
        case MEDPLY_STATE_WAIT_NEXT:
        {
            mmi_medply_stop_wait_next_timer();
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);    
            break;
        }
        
    /*----audio----*/        
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        case MEDPLY_STATE_AUDIO_READY:
        {
            MMI_ASSERT(g_medply.media_type == MEDPLY_TYPE_AUDIO);
            mmi_medply_clear_play_seconds();

        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
           g_medply.DRM_consumed = MMI_FALSE;
        #endif

        #ifdef __MMI_A2DP_SUPPORT__
            /*in case bt inquirying and avcrp sent stop cmd, thus inquiry stop shall not resume*/
            g_medply.inquiry_paused = MMI_FALSE;
        #endif
    
            if(!g_medply.in_media_player)
            {
                /*since audio is stopped, clear background hdlr here*/ 
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }
            mmi_medply_main_screen_reset();
            mmi_medply_main_screen_blt();

            if(g_medply.widget_callback != NULL)
            {
                g_medply.widget_callback(g_medply.widget_callback_userdata,MMI_WIDTET_PLAYER_RESET_TIME_CALLBACK,NULL);
            }
            break;
        }

        case MEDPLY_STATE_AUDIO_PLAY:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
        {
            MMI_ASSERT(g_medply.media_type == MEDPLY_TYPE_AUDIO);
            mmi_medply_audio_stop();
            break;
        }

        case MEDPLY_STATE_AUDIO_BT_CONNECTING:
        {
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            
        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            g_medply.DRM_consumed = MMI_FALSE;
        #endif
            
            /* audio is stopped, clear background hdlr here*/
            if(!g_medply.in_media_player)
            {
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }
        
            mmi_medply_set_continue_flag(MMI_FALSE);            
            mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
            break;
        }

        case MEDPLY_STATE_AUDIO_INTERRUPTED:
        {
        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            g_medply.DRM_consumed = MMI_FALSE;
        #endif
            mmi_medply_clear_play_seconds();
            mmi_medply_set_continue_flag(MMI_FALSE);
            break;
        }

    #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

    /*----video----*/
    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
        case MEDPLY_STATE_VIDEO_IDLE:
        {
            /*reset time and show first frame*/
            mmi_medply_clear_play_seconds(); 

        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            g_medply.DRM_consumed = MMI_FALSE;
        #endif

        #ifdef __MMI_A2DP_SUPPORT__
            g_medply.bt_connect_fail = MMI_FALSE;        
            /*in case bt inquirying and avcrp sent stop cmd, thus inquiry stop shall not resume*/
            g_medply.inquiry_paused = MMI_FALSE;
        #endif

            mmi_medply_main_screen_draw_duration();
            mmi_medply_main_screen_blt();

            if(g_medply.widget_callback != NULL)
            {
                g_medply.widget_callback(g_medply.widget_callback_userdata,MMI_WIDTET_PLAYER_RESET_TIME_CALLBACK,NULL);
            }

            break;
        }

        case MEDPLY_STATE_VIDEO_OPENING:
        {

            mdi_video_ply_stop_non_block_seek();
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();

        #ifdef __DRM_SUPPORT__
            g_medply.DRM_consumed = MMI_FALSE;
        #endif

        #ifdef __MMI_A2DP_SUPPORT__
            g_medply.bt_connect_fail = MMI_FALSE;        
            /*in case bt inquirying and avcrp sent stop cmd, thus inquiry stop shall not resume*/
            g_medply.inquiry_paused = MMI_FALSE;

            /*for video idle bt connecting case, it is possible that when opening, bt is connected*/
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_set_continue_flag(MMI_FALSE);

            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
            
            break;
        }

        case MEDPLY_STATE_VIDEO_READY:
        {
            MDI_RESULT result;
            mmi_medply_video_play_para_struct video_layer_info;

            /*reset time and show first frame*/
            mmi_medply_clear_play_seconds(); 

        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            g_medply.DRM_consumed = MMI_FALSE;
        #endif

        #ifdef __MMI_A2DP_SUPPORT__
            g_medply.bt_connect_fail = MMI_FALSE;        
            /*in case bt inquirying and avcrp sent stop cmd, thus inquiry stop shall not resume*/
            g_medply.inquiry_paused = MMI_FALSE;

            /*for video idle bt connecting case, it is possible that when opening, bt is connected*/
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            video_layer_info.video_height = g_medply.height;
            video_layer_info.video_width = g_medply.width;
            mmi_medply_main_screen_get_video_parameter(&video_layer_info);


            result = mmi_medply_adption_video_seek_and_get_frame(
                        g_medply.current_time,
                        video_layer_info.layer_hdl
                        #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                        ,video_layer_info.layer_subtitle_hdl
                        #endif
                        );
                        
            if(result < 0)
            {
                mmi_medply_set_pop_up_flag();
                mmi_medply_display_popup(result,MMI_TRUE);
                mmi_medply_play_completed(MMI_TRUE,MMI_FALSE);
                return;
            }
            else
            {
                mmi_medply_main_screen_reset();
                mmi_medply_main_screen_blt();
            }

            if(g_medply.widget_callback != NULL)
            {
                g_medply.widget_callback(g_medply.widget_callback_userdata,MMI_WIDTET_PLAYER_RESET_TIME_CALLBACK,NULL);
            }
            
            break;    
        }

        case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
        case MEDPLY_STATE_VIDEO_PAUSE_SEEKING:
        {
            MDI_RESULT result;
            mmi_medply_video_play_para_struct video_layer_info;

            /*reset time and show first frame*/
            mmi_medply_clear_play_seconds(); 

        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            g_medply.DRM_consumed = MMI_FALSE;
        #endif

        #ifdef __MMI_A2DP_SUPPORT__
            g_medply.bt_connect_fail = MMI_FALSE;
        #endif

            mdi_video_ply_stop_non_block_seek();

            video_layer_info.video_height = g_medply.height;
            video_layer_info.video_width = g_medply.width;
            mmi_medply_main_screen_get_video_parameter(&video_layer_info);


            result = mmi_medply_adption_video_seek_and_get_frame(
                        g_medply.current_time,
                        video_layer_info.layer_hdl
                        #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                        ,video_layer_info.layer_subtitle_hdl
                        #endif
                        );
                        
            if(result < 0)
            {
                mmi_medply_set_pop_up_flag();
                mmi_medply_display_popup(result,MMI_TRUE);
                mmi_medply_play_completed(MMI_TRUE,MMI_FALSE);
                return;
            }
            else
            {
                mmi_medply_main_screen_blt();
                mmi_medply_set_continue_flag(MMI_FALSE);
                mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_READY);
            }            
            break;
        }
    
        case MEDPLY_STATE_VIDEO_PLAY:
        {
            mmi_medply_video_stop();
            break;
        }

        case MEDPLY_STATE_VIDEO_INTERRUPTED:
        {
        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            g_medply.DRM_consumed = MMI_FALSE;
        #endif

        #ifdef __MMI_A2DP_SUPPORT__
            g_medply.bt_connect_fail = MMI_FALSE;
        #endif

            mmi_medply_set_continue_flag(MMI_FALSE);
            if(g_medply.in_main_screen)
            {
                mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
            }
            else
            {
                mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_READY);
            }
            break;
        }

        case MEDPLY_STATE_VIDEO_BT_CONNECTING:
        {
            MDI_RESULT result;
            mmi_medply_video_play_para_struct video_layer_info;

        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            g_medply.DRM_consumed = MMI_FALSE;
        #endif

        #ifdef __MMI_A2DP_SUPPORT__
            g_medply.bt_connect_fail = MMI_FALSE;
        #endif

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            video_layer_info.video_height = g_medply.height;
            video_layer_info.video_width = g_medply.width;
            mmi_medply_main_screen_get_video_parameter(&video_layer_info);


            result = mmi_medply_adption_video_seek_and_get_frame(
                        g_medply.current_time,
                        video_layer_info.layer_hdl
                        #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                        ,video_layer_info.layer_subtitle_hdl
                        #endif
                        );
        
            if(result < 0)
            {
                mmi_medply_set_pop_up_flag();
                mmi_medply_display_popup(result,MMI_TRUE);
                mmi_medply_play_completed(MMI_TRUE, MMI_FALSE);

                return;
            }
            else
            {
                mmi_medply_main_screen_blt();
                mmi_medply_set_continue_flag(MMI_FALSE);
                mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_READY);
            }
            break;
        }

        case MEDPLY_STATE_VIDEO_IDLE_BT_CONNECTING:
        {
        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            g_medply.DRM_consumed = MMI_FALSE;
        #endif

        #ifdef __MMI_A2DP_SUPPORT__
            g_medply.bt_connect_fail = MMI_FALSE;
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
            break;
        }

        /*AVRCP cmd*/
        case MEDPLY_STATE_PURE_AUDIO_READY:
        {
        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            g_medply.DRM_consumed = MMI_FALSE;
        #endif

        #ifdef __MMI_A2DP_SUPPORT__
            g_medply.bt_connect_fail = MMI_FALSE;
            /*in case bt inquirying and avcrp sent stop cmd, thus inquiry stop shall not resume*/
            g_medply.inquiry_paused = MMI_FALSE;
        #endif

            mmi_medply_clear_play_seconds();
            mmi_medply_main_screen_reset();
            mmi_medply_main_screen_blt();

            if(g_medply.widget_callback != NULL)
            {
                g_medply.widget_callback(g_medply.widget_callback_userdata,MMI_WIDTET_PLAYER_RESET_TIME_CALLBACK,NULL);
            }

            break;
        }

        /*AVRCP cmd*/
        case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
        {
        #ifdef __MMI_A2DP_SUPPORT__
            g_medply.bt_connect_fail = MMI_FALSE;
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            g_medply.DRM_consumed = MMI_FALSE;
        #endif

            /* audio is stopped, clear background hdlr here*/
            if(!g_medply.in_media_player)
            {
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }

            mmi_medply_set_continue_flag(MMI_FALSE);            
            mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_READY);
                        
            break;
        }

        /*AVRCP cmd*/
        case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
        case MEDPLY_STATE_PURE_AUDIO_PLAY:
        {
            mmi_medply_set_self_stop_flag(MMI_TRUE);
            
            /*stop file*/
            mdi_audio_stop_file();

            mmi_medply_set_self_stop_flag(MMI_FALSE);

        #ifdef __MMI_A2DP_SUPPORT__
            g_medply.bt_connect_fail = MMI_FALSE;
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
        
        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            g_medply.DRM_consumed = MMI_FALSE;
        #endif
        
            /* audio is stopped, clear background hdlr here*/
            if(!g_medply.in_media_player)
            {
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }

            mmi_medply_clear_play_seconds();

            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_READY);

            /* restore to normal speed when stop play */
        #ifdef __MMI_AUDIO_TIME_STRETCH__
            mmi_medply_settings_close_speed();
        #endif 

            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

    #ifdef __MMI_MEDIA_PLAYER_STREAM__
        case MEDPLY_STATE_STREAM_CONNECTING:
        {
            mdi_video_stream_disconnect();
            if(!g_medply.in_media_player)
            {
                mmi_medply_stream_deinit();
                mdi_audio_clear_interrupt_callback();
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }
            else
            {
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);
            }
            break;
        }

        case MEDPLY_STATE_STREAM_INTERRUPTED:
        {
            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            g_medply.DRM_consumed = MMI_FALSE;
        #endif
            mmi_medply_clear_play_seconds();
            mmi_medply_main_screen_reset();
            mmi_medply_main_screen_blt();
            break;
        }

        case MEDPLY_STATE_STREAM_CONNECTED:
        {
            mdi_video_stream_disconnect();
            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);

        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            g_medply.DRM_consumed = MMI_FALSE;
        #endif
            mmi_medply_clear_play_seconds();
            mmi_medply_main_screen_reset();
            mmi_medply_main_screen_blt();

            if(g_medply.widget_callback != NULL)
            {
                g_medply.widget_callback(g_medply.widget_callback_userdata,MMI_WIDTET_PLAYER_RESET_TIME_CALLBACK,NULL);
            }
            break;
        }

        case MEDPLY_STATE_STREAM_IDLE:
        case MEDPLY_STATE_STREAM_INITED:
        {
        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            g_medply.DRM_consumed = MMI_FALSE;
        #endif
            mmi_medply_clear_play_seconds();
            mmi_medply_main_screen_reset();
            mmi_medply_main_screen_blt();

            if(g_medply.widget_callback != NULL)
            {
                g_medply.widget_callback(g_medply.widget_callback_userdata,MMI_WIDTET_PLAYER_RESET_TIME_CALLBACK,NULL);
            }
            break;
        }

        case MEDPLY_STATE_STREAM_BUFFERING:         
        {
            StopTimer(MEDPLY_STREAM_BUFFER_TIMER);
            mdi_video_stream_stop_buffering();
        #ifdef __MMI_A2DP_SUPPORT__            
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            /*while not in main screen, disconnect*/
            mdi_video_stream_disconnect();

            if(!g_medply.in_media_player)
            {
                mmi_medply_stream_deinit();
                mdi_audio_clear_interrupt_callback();
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }
            else
            {
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);
            }

            break;
        }

        case MEDPLY_STATE_STREAM_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
        {
            mmi_medply_stream_stop();
            break;
        }

        case MEDPLY_STATE_STREAM_BT_CONNECTING:
        {
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            mdi_video_stream_disconnect();
            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);

            /* audio is stopped, clear background hdlr here*/
            if(!g_medply.in_media_player)
            {
                mmi_medply_stream_deinit();
                mdi_audio_clear_interrupt_callback();
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }
            break;
        }
            
    #endif /*__MMI_MEDIA_PLAYER_STREAM__*/

    
    }

    ClearKeyEvents();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_play_button_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_play_button_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_PLAY_DOWN,g_medply.selected_button, MMI_FALSE);

    if(g_medply.selected_button == MEDPLY_MAIN_DISABLED || mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_PAUSE) || mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_PLAY))
    {
        return;
    }

    g_medply.selected_button = MEDPLY_MAIN_PLAY;
    g_medply.selected_button_down = MMI_TRUE;

    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_PLAY_PAUSE,
        MMI_MEDPLY_RGN_STATUS_DOWN);
    mmi_medply_main_screen_blt();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_play_button_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_play_button_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_PLAY_UP,g_medply.selected_button,g_medply.selected_button_down,g_medply.state, MMI_FALSE);
    
    if (g_medply.selected_button != MEDPLY_MAIN_PLAY || g_medply.selected_button_down != MMI_TRUE)
    {
        return;
    }

    g_medply.selected_button_down = MMI_FALSE;

    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_PLAY_PAUSE,
        MMI_MEDPLY_RGN_STATUS_UP);

    if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_PAUSE) || mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_PLAY))
    {
        mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_PLAY_PAUSE,
            MMI_MEDPLY_RGN_STATUS_DISABLE);

        mmi_medply_main_screen_blt();

        return;
    }

    mmi_medply_main_screen_blt();

    /*this is for cases that user plug out memory card, so the previous fill data will fill unknown data
      then user plug in again and press play, if not fill again, idle will show wrong information*/
    mmi_medply_util_fill_idle_display_str();

    switch (g_medply.state)
    {
        case MEDPLY_STATE_IDLE:
        {
            if (g_medply.media_type == MEDPLY_TYPE_STREAM)
            {
            #ifdef __MMI_MEDIA_PLAYER_STREAM__
                if(mmi_medply_stream_init())
                {
                    mmi_medply_stream_connect();
                }
            #endif
            }
            else if(g_medply.media_type == MEDPLY_TYPE_VIDEO)
            {
            #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                mmi_medply_set_continue_flag(MMI_TRUE);
                if(g_medply.in_main_screen)
                {
                    mmi_medply_video_open();
                }
                else
                {
                    mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_READY);
                }
            #endif
            }
            else if(g_medply.media_type == MEDPLY_TYPE_AUDIO)
            {
            #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                mmi_medply_set_continue_flag(MMI_TRUE);
                mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
            #endif
            }
            break;
        }

        case MEDPLY_STATE_WAIT_NEXT:
        case MEDPLY_STATE_WAIT_NEXT_SUSPNEDED:
        {
            mmi_medply_set_continue_flag(MMI_TRUE);
            break;
        }

    /*----audio----*/
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        /*handle audio media type*/
        case MEDPLY_STATE_AUDIO_INTERRUPTED:
        case MEDPLY_STATE_AUDIO_READY:
        {
            MMI_ASSERT(g_medply.media_type == MEDPLY_TYPE_AUDIO);
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_audio_play();
            break;
        }

    #ifdef __MMI_MEDIA_PLAYER_FTE__
        case MEDPLY_STATE_AUDIO_PLAY:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
        {
            MMI_ASSERT(g_medply.media_type == MEDPLY_TYPE_AUDIO);

            if(!g_medply.is_audio_seekable)
            {
                mmi_medply_audio_stop();
            }
            else
            {
                mmi_medply_audio_pause();
            }
            break;            
        }
    #else
        case MEDPLY_STATE_AUDIO_PLAY:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
        {
            MMI_ASSERT(g_medply.media_type == MEDPLY_TYPE_AUDIO);
            mmi_medply_audio_pause();
            break;
        }
    #endif

    /* FTE project needs to handle stop actions for following states*/
    #ifdef __MMI_MEDIA_PLAYER_FTE__
        case MEDPLY_STATE_AUDIO_BT_CONNECTING:
        {
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            
        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            g_medply.DRM_consumed = MMI_FALSE;
        #endif
            
            /* audio is stopped, clear background hdlr here*/
            if(!g_medply.in_media_player)
            {
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }

            mmi_medply_set_continue_flag(MMI_FALSE);            
            mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
            break;
        }
    #endif

    #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

    /*----video----*/
    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
        case MEDPLY_STATE_VIDEO_IDLE:
        {
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_video_open();
            break;
        }

        case MEDPLY_STATE_VIDEO_INTERRUPTED:
        {
            MMI_ASSERT(g_medply.media_type == MEDPLY_TYPE_VIDEO);
            mmi_medply_set_continue_flag(MMI_TRUE);
            if(!g_medply.in_main_screen)
            {
                mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_READY);
            }
            else
            {
                mmi_medply_video_open();
            }

            break;
        }

        case MEDPLY_STATE_VIDEO_READY:
        case MEDPLY_STATE_PURE_AUDIO_READY:/*AVRCP cmd*/
        {
            MMI_ASSERT(g_medply.media_type == MEDPLY_TYPE_VIDEO);
            mmi_medply_video_play();
            break;
        }

        case MEDPLY_STATE_VIDEO_PLAY:
        case MEDPLY_STATE_PURE_AUDIO_PLAY:/*AVRCP cmd*/
        case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:/*AVRCP cmd*/
        {
            MMI_ASSERT(g_medply.media_type == MEDPLY_TYPE_VIDEO);
        #ifdef __MMI_A2DP_SUPPORT__
            g_medply.bt_connect_fail = MMI_FALSE;
        #endif
            mmi_medply_video_pause();
            break;
        }

    /* FTE project needs to handle stop actions for following states*/
    #ifdef __MMI_MEDIA_PLAYER_FTE__
        case MEDPLY_STATE_VIDEO_OPENING:
        {
            mdi_video_ply_stop_non_block_seek();
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();

        #ifdef __DRM_SUPPORT__
            g_medply.DRM_consumed = MMI_FALSE;
        #endif

        #ifdef __MMI_A2DP_SUPPORT__
            g_medply.bt_connect_fail = MMI_FALSE;        
            /*in case bt inquirying and avcrp sent stop cmd, thus inquiry stop shall not resume*/
            g_medply.inquiry_paused = MMI_FALSE;

            /*for video idle bt connecting case, it is possible that when opening, bt is connected*/
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_set_continue_flag(MMI_FALSE);

            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
            
            break;
        }

        case MEDPLY_STATE_VIDEO_BT_CONNECTING:
        {
            MDI_RESULT result;
            mmi_medply_video_play_para_struct video_layer_info;

        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            g_medply.DRM_consumed = MMI_FALSE;
        #endif

        #ifdef __MMI_A2DP_SUPPORT__
            g_medply.bt_connect_fail = MMI_FALSE;
        #endif

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            video_layer_info.video_height = g_medply.height;
            video_layer_info.video_width = g_medply.width;
            mmi_medply_main_screen_get_video_parameter(&video_layer_info);

            result = mmi_medply_adption_video_seek_and_get_frame(
                        g_medply.current_time,
                        video_layer_info.layer_hdl
                        #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                        ,video_layer_info.layer_subtitle_hdl
                        #endif
                        );
        
            if(result < 0)
            {
                mmi_medply_set_pop_up_flag();
                mmi_medply_display_popup(result,MMI_TRUE);
                mmi_medply_play_completed(MMI_TRUE, MMI_FALSE);

                return;
            }
            else
            {
                mmi_medply_main_screen_blt();
                mmi_medply_set_continue_flag(MMI_FALSE);
                mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_READY);
            }
            break;
        }

        case MEDPLY_STATE_VIDEO_IDLE_BT_CONNECTING:
        {
        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            g_medply.DRM_consumed = MMI_FALSE;
        #endif

        #ifdef __MMI_A2DP_SUPPORT__
            g_medply.bt_connect_fail = MMI_FALSE;
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
            break;
        }

        case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
        {
        #ifdef __MMI_A2DP_SUPPORT__
            g_medply.bt_connect_fail = MMI_FALSE;
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

        #if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            g_medply.DRM_consumed = MMI_FALSE;
        #endif

            /* audio is stopped, clear background hdlr here*/
            if(!g_medply.in_media_player)
            {
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }

            mmi_medply_set_continue_flag(MMI_FALSE);            
            mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_READY);
                        
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_FTE__*/

    #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

    /*----stream----*/
    #ifdef __MMI_MEDIA_PLAYER_STREAM__
        case MEDPLY_STATE_STREAM_INTERRUPTED:
        case MEDPLY_STATE_STREAM_IDLE:
        {
            MMI_BOOL result;

            MMI_ASSERT(g_medply.media_type == MEDPLY_TYPE_STREAM);

            result = mmi_medply_stream_init();
            if(result)
            {
                mmi_medply_stream_connect();
            }

            break;
        }
        
        case MEDPLY_STATE_STREAM_INITED:
        {
            MMI_ASSERT(g_medply.media_type == MEDPLY_TYPE_STREAM);
            mmi_medply_stream_connect();
            break;
        }

        case MEDPLY_STATE_STREAM_CONNECTED:
        {
            MMI_ASSERT(g_medply.media_type == MEDPLY_TYPE_STREAM);
            mmi_medply_stream_buffer();
            break;
        }

        case MEDPLY_STATE_STREAM_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
        {
            MMI_ASSERT(g_medply.media_type == MEDPLY_TYPE_STREAM);
            mmi_medply_stream_pause();
            break;
        }

    /* FTE project needs to handle stop actions for following states*/
    #ifdef __MMI_MEDIA_PLAYER_FTE__
        case MEDPLY_STATE_STREAM_CONNECTING:
        {
            mdi_video_stream_disconnect();
            if(!g_medply.in_media_player)
            {
                mmi_medply_stream_deinit();
                mdi_audio_clear_interrupt_callback();
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }
            else
            {
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);
            }
            break;
        }

        case MEDPLY_STATE_STREAM_BUFFERING:         
        {
            StopTimer(MEDPLY_STREAM_BUFFER_TIMER);
            mdi_video_stream_stop_buffering();
        #ifdef __MMI_A2DP_SUPPORT__            
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            if(g_medply.in_main_screen)
            {
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_CONNECTED);
            }
            else
            {
                /*while not in main screen, disconnect*/
                mdi_video_stream_disconnect();

                if(!g_medply.in_media_player)
                {
                    mmi_medply_stream_deinit();
                    mdi_audio_clear_interrupt_callback();
                    mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
                    mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
                }
                else
                {
                    mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);
                }
            }
            break;
        }

        case MEDPLY_STATE_STREAM_BT_CONNECTING:
        {
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            if(g_medply.in_main_screen)
            {
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_CONNECTED);
            }
            else
            {
                mdi_video_stream_disconnect();
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);
            }

            /* audio is stopped, clear background hdlr here*/
            if(!g_medply.in_media_player)
            {
                mmi_medply_stream_deinit();
                mdi_audio_clear_interrupt_callback();
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_FTE__*/
    
    #endif /*__MMI_MEDIA_PLAYER_STREAM__*/

        default:
        {
            break;
        }

    }

    ClearKeyEvents();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_prev_button_down
 * DESCRIPTION
 *  handle event previous button down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_prev_button_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_PREV_DOWN,g_medply.selected_button, MMI_FALSE);

    if(g_medply.selected_button == MEDPLY_MAIN_DISABLED)
    {
        return;
    }
    g_medply.selected_button = MEDPLY_MAIN_PREV;
    g_medply.selected_button_down = MMI_TRUE;

    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_PREV,
        MMI_MEDPLY_RGN_STATUS_DOWN);
    mmi_medply_main_screen_blt();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_prev_button_up
 * DESCRIPTION
 *  handle event previous button up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_prev_button_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 apply_result = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_PREV_UP,g_medply.selected_button,g_medply.selected_button_down,g_medply.state, MMI_FALSE);

    if(g_medply.selected_button != MEDPLY_MAIN_PREV || g_medply.selected_button_down != MMI_TRUE)
    {
        return;
    }

    g_medply.selected_button_down = MMI_FALSE;

    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_PREV,
        MMI_MEDPLY_RGN_STATUS_UP);
    mmi_medply_main_screen_blt();

    switch(g_medply.state)
    {
    /*----core----*/
        case MEDPLY_STATE_WAIT_NEXT_SUSPNEDED:
        case MEDPLY_STATE_WAIT_NEXT:
        {
            mmi_medply_stop_wait_next_timer();
            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }   
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
            break;
        }

        case MEDPLY_STATE_IDLE:
        {
            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }            
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);            
            break;
        }

    /*----audio----*/
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__    
        case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:
        {
            if(g_medply.need_to_build_cache)
            {
                mdi_audio_stop_build_cache();                
            }
            mmi_medply_main_screen_duration_seek_done();            
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
            break;
        }

        case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
        {
            if(g_medply.need_to_build_cache)
            {
                mdi_audio_stop_build_cache();
            }
            mmi_medply_main_screen_duration_seek_done();
            mmi_medply_audio_play();
            break;
        }

        case MEDPLY_STATE_AUDIO_INTERRUPTED:
        case MEDPLY_STATE_AUDIO_READY:
        {
            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }  

            /*since next media will not be played automatically, clear bg hdlr here*/
            if(!g_medply.in_media_player)
            {
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }

            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_AUDIO_BT_CONNECTING:
        {

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
            break;
        }


        case MEDPLY_STATE_AUDIO_PLAY:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
        {
            mmi_medply_set_self_stop_flag(MMI_TRUE);

            mdi_audio_stop_file();

            mmi_medply_set_self_stop_flag(MMI_FALSE);

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
            break;
        }

    #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

    /*----video----*/
    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
        case MEDPLY_STATE_VIDEO_IDLE:
        {
            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);            
            break;
        }

        case MEDPLY_STATE_VIDEO_IDLE_PROGRESSING:
        {
            mmi_medply_main_screen_duration_seek_done();
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
            break;
        }

        case MEDPLY_STATE_VIDEO_IDLE_BT_CONNECTING:
        {
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);            
            break;
        }

        case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
        {
            MDI_RESULT result;
            mmi_medply_video_play_para_struct video_layer_info;

            mmi_medply_main_screen_duration_seek_done();

            video_layer_info.video_height = g_medply.height;
            video_layer_info.video_width = g_medply.width;
            mmi_medply_main_screen_get_video_parameter(&video_layer_info);

            result = mmi_medply_adption_video_non_block_seek_and_get_frame(
                    g_medply.current_time,
                    video_layer_info.layer_hdl,
                    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                    video_layer_info.layer_subtitle_hdl,
                    #endif
                    mmi_medply_video_seek_callback_hdlr,
                    0);

            if (result < 0)
            {
                mmi_medply_video_close();
                mdi_audio_clear_interrupt_callback();
                mmi_medply_set_pop_up_flag();
                mmi_medply_display_popup(result,MMI_TRUE);

                if(mmi_medply_plst_do_pick() < 0)
                {
                    /*when pick fail, call it again to reset the list*/
                    mmi_medply_plst_do_pick();
                }

                apply_result = mmi_medply_plst_apply_picked_file();
                if(apply_result<0)
                {
                    mmi_medply_stop_playing();
                    mmi_medply_plst_display_popup(apply_result,NULL);
                    return;
                }

                mmi_medply_set_continue_flag(MMI_FALSE);
                g_medply.wait_next_with_pop_up = MMI_TRUE;
                mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
                return;
            }

            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_PAUSE_SEEKING);
            
            break;
        }

        case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:
        {
            MDI_RESULT result;
            mmi_medply_video_play_para_struct video_layer_info;

            mmi_medply_main_screen_duration_seek_done();

            video_layer_info.video_height = g_medply.height;
            video_layer_info.video_width = g_medply.width;
            mmi_medply_main_screen_get_video_parameter(&video_layer_info);

            result = mmi_medply_adption_video_non_block_seek_and_get_frame(
                    g_medply.current_time,
                    video_layer_info.layer_hdl,
                    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                    video_layer_info.layer_subtitle_hdl,
                    #endif
                    mmi_medply_video_seek_callback_hdlr,
                    0);

            if (result < 0)
            {
                mmi_medply_video_close();
                mdi_audio_clear_interrupt_callback();
                mmi_medply_set_pop_up_flag();
                mmi_medply_display_popup(result,MMI_TRUE);

                if(mmi_medply_plst_do_pick() < 0)
                {
                    /*when pick fail, call it again to reset the list*/
                    mmi_medply_plst_do_pick();
                    mmi_medply_set_continue_flag(MMI_FALSE);
                }
                else
                {
                    mmi_medply_set_continue_flag(MMI_TRUE);
                }

                apply_result = mmi_medply_plst_apply_picked_file();
                if(apply_result<0)
                {
                    mmi_medply_stop_playing();
                    mmi_medply_plst_display_popup(apply_result,NULL);
                    return;
                }
                g_medply.wait_next_with_pop_up = MMI_TRUE;
                mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);

                return;
            }

            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_PLAY_SEEKING);
            
            break;
        }

        case MEDPLY_STATE_VIDEO_INTERRUPTED:
        {
            /*shall not happen, since interrupted shall not accept avrcp and 
              shall be opening after enter screen */
            break;
        }        

        case MEDPLY_STATE_VIDEO_OPENING:
        {
            /*close video*/
            mdi_video_ply_stop_non_block_seek();
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_main_screen_clear_video_layer();

        #ifdef __MMI_A2DP_SUPPORT__
            /*for video idle bt connecting case, it is possible that when opening, bt is connected*/
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }

            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);            
            break;
        }

        case MEDPLY_STATE_VIDEO_READY:          
        {
            /*close video*/
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();

        #ifdef __MMI_A2DP_SUPPORT__
            /*for video idle bt connecting case, it is possible that when opening, bt is connected*/
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }

            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_VIDEO_BT_CONNECTING:
        {
            /*close video*/
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
            break;
        }

        case MEDPLY_STATE_VIDEO_PAUSE_SEEKING:
        {
            mdi_video_ply_stop_non_block_seek();
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();

            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }

            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_VIDEO_PLAY:
        {
            /*stop video*/
            mdi_video_ply_stop();
            /*close video*/
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif


            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);            
            break;
        }

        case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
        {
            mdi_video_ply_stop_non_block_seek();
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();

            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);           
            break;
        }


        /*AVRCP cmd*/
        case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
        {

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);            
            break;
        }

        /*AVRCP cmd*/
        case MEDPLY_STATE_PURE_AUDIO_READY:
        {
            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }

            /*since next media will not be played automatically, clear bg hdlr here*/
            mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
        
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        /*AVRCP cmd*/
        case MEDPLY_STATE_PURE_AUDIO_PLAY:
        case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:            
        {
            mmi_medply_set_self_stop_flag(MMI_TRUE);

            mdi_audio_stop_file();

            mmi_medply_set_self_stop_flag(MMI_FALSE);

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);            
            break;
        }

    #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

    /*----stream----*/
    #ifdef __MMI_MEDIA_PLAYER_STREAM__

        case MEDPLY_STATE_STREAM_INTERRUPTED:
        case MEDPLY_STATE_STREAM_IDLE:
        {
            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }

            /* stream is stopped, clear background hdlr here*/
            if(!g_medply.in_media_player)
            {
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }
            
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }
    
        case MEDPLY_STATE_STREAM_INITED:
        {
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();

            /*set to stream idle in case picked file fail and then stop playing will do all the 
              disconnect/deinit process again, this will assert in med since it has been deinited*/
            g_medply.state = MEDPLY_STATE_STREAM_IDLE;

            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }

            /* stream is stopped, clear background hdlr here*/
            if(!g_medply.in_media_player)
            {
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }
            
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:
        {
            mmi_medply_main_screen_duration_seek_done();
            mmi_medply_stream_buffer();
            break;
        }
    
        case MEDPLY_STATE_STREAM_CONNECTING:
        {
            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();

            g_medply.state = MEDPLY_STATE_STREAM_IDLE;

            mdi_audio_clear_interrupt_callback();

            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
            break;
        }

        case MEDPLY_STATE_STREAM_CONNECTED:
        {
            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();

            g_medply.state = MEDPLY_STATE_STREAM_IDLE;

            mdi_audio_clear_interrupt_callback();

            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }

            /* stream is stopped, clear background hdlr here*/
            if(!g_medply.in_media_player)
            {
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }
            
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_STREAM_BUFFERING:
        {
            StopTimer(MEDPLY_STREAM_BUFFER_TIMER);
            mdi_video_stream_stop_buffering();
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();

            g_medply.state = MEDPLY_STATE_STREAM_IDLE;

            mdi_audio_clear_interrupt_callback();

            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
            break;
        }

        case MEDPLY_STATE_STREAM_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
        {
            mdi_video_stream_stop();
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif


            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();

            g_medply.state = MEDPLY_STATE_STREAM_IDLE;

            mdi_audio_clear_interrupt_callback();

            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
            break;
        }

        case MEDPLY_STATE_STREAM_BT_CONNECTING:
        {
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();

            g_medply.state = MEDPLY_STATE_STREAM_IDLE;

            mdi_audio_clear_interrupt_callback();

            mmi_medply_plst_pick_prev();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);            
            break;
        }
    
    #endif /*__MMI_MEDIA_PLAYER_STREAM__*/


        default:
        {
            break;
        }

    }

    /*can not clear key events since AVRCP blcocked by FW case after AVRCP longpressed will call key up 
      not key canceled, if we clear key events here, the FW key stack will have some problem*/
    /*ClearKeyEvents();*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_next_button_down
 * DESCRIPTION
 *  handle event next button down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_next_button_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_NEXT_DOWN,g_medply.selected_button, MMI_FALSE);

    if(g_medply.selected_button == MEDPLY_MAIN_DISABLED)
    {
        return;
    }
    g_medply.selected_button = MEDPLY_MAIN_NEXT;
    g_medply.selected_button_down = MMI_TRUE;

    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_NEXT,
        MMI_MEDPLY_RGN_STATUS_DOWN);
    mmi_medply_main_screen_blt();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_next_button_up
 * DESCRIPTION
 *  handle event next button up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_next_button_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 apply_result = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_NEXT_UP,g_medply.selected_button,g_medply.selected_button_down,g_medply.state, MMI_FALSE);

    if(g_medply.selected_button != MEDPLY_MAIN_NEXT || g_medply.selected_button_down != MMI_TRUE)
    {
        return;
    }

    g_medply.selected_button_down = MMI_FALSE;

    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_NEXT,
        MMI_MEDPLY_RGN_STATUS_UP);
    mmi_medply_main_screen_blt();

    switch(g_medply.state)
    {
    /*----core----*/
        case MEDPLY_STATE_WAIT_NEXT_SUSPNEDED:
        case MEDPLY_STATE_WAIT_NEXT:
        {
            mmi_medply_stop_wait_next_timer();
            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
            break;
        }

        case MEDPLY_STATE_IDLE:
        {
            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);            
            break;
        }

    /*----audio----*/
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__    
        case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:
        {
            if(g_medply.need_to_build_cache)
            {
                mdi_audio_stop_build_cache();
            }
            mmi_medply_main_screen_duration_seek_done();
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
            break;
        }

        case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
        {
            if(g_medply.need_to_build_cache)
            {
                mdi_audio_stop_build_cache();
            }
            mmi_medply_main_screen_duration_seek_done();            
            mmi_medply_audio_play();
            break;
        }

        case MEDPLY_STATE_AUDIO_INTERRUPTED:
        case MEDPLY_STATE_AUDIO_READY:           
        {
            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }

            /*since next media will not be played automatically, clear bg hdlr here*/
            if(!g_medply.in_media_player)
            {
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }


            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);

            break;
        }

        case MEDPLY_STATE_AUDIO_BT_CONNECTING:
        {

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
            break;
        }

        case MEDPLY_STATE_AUDIO_PLAY:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:       
        {
            mmi_medply_set_self_stop_flag(MMI_TRUE);

            mdi_audio_stop_file();

            mmi_medply_set_self_stop_flag(MMI_FALSE);

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
         
            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
            break;
        }

    #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

    /*----video----*/
    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
        case MEDPLY_STATE_VIDEO_IDLE:
        {
            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);            
            break;
        }

        case MEDPLY_STATE_VIDEO_IDLE_BT_CONNECTING:
        {
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);            
            break;
        }

        case MEDPLY_STATE_VIDEO_IDLE_PROGRESSING:
        {
            mmi_medply_main_screen_duration_seek_done();
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
            break;
        }

        case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
        {
            MDI_RESULT result;
            mmi_medply_video_play_para_struct video_layer_info;

            mmi_medply_main_screen_duration_seek_done();

            video_layer_info.video_height = g_medply.height;
            video_layer_info.video_width = g_medply.width;
            mmi_medply_main_screen_get_video_parameter(&video_layer_info);

            result = mmi_medply_adption_video_non_block_seek_and_get_frame(
                    g_medply.current_time,
                    video_layer_info.layer_hdl,
                    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                    video_layer_info.layer_subtitle_hdl,
                    #endif
                    mmi_medply_video_seek_callback_hdlr,
                    0);

            if (result < 0)
            {
                mmi_medply_video_close();
                mdi_audio_clear_interrupt_callback();
                mmi_medply_set_pop_up_flag();
                mmi_medply_display_popup(result,MMI_TRUE);

                if(mmi_medply_plst_do_pick() < 0)
                {
                    /*when pick fail, call it again to reset the list*/
                    mmi_medply_plst_do_pick();
                }

                apply_result = mmi_medply_plst_apply_picked_file();
                if(apply_result<0)
                {
                    mmi_medply_stop_playing();
                    mmi_medply_plst_display_popup(apply_result,NULL);
                    return;
                }

                mmi_medply_set_continue_flag(MMI_FALSE);
                g_medply.wait_next_with_pop_up = MMI_TRUE;
                mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
     
                return;
            }

            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_PAUSE_SEEKING);
            
            break;
        }

        case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:
        {
            MDI_RESULT result;
            mmi_medply_video_play_para_struct video_layer_info;

            mmi_medply_main_screen_duration_seek_done();

            video_layer_info.video_height = g_medply.height;
            video_layer_info.video_width = g_medply.width;
            mmi_medply_main_screen_get_video_parameter(&video_layer_info);

            result = mmi_medply_adption_video_non_block_seek_and_get_frame(
                    g_medply.current_time,
                    video_layer_info.layer_hdl,
                    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                    video_layer_info.layer_subtitle_hdl,
                    #endif
                    mmi_medply_video_seek_callback_hdlr,
                    0);

            if (result < 0)
            {
                mmi_medply_video_close();
                mdi_audio_clear_interrupt_callback();
                mmi_medply_set_pop_up_flag();
                mmi_medply_display_popup(result,MMI_TRUE);

                if(mmi_medply_plst_do_pick() < 0)
                {
                    /*when pick fail, call it again to reset the list*/
                    mmi_medply_plst_do_pick();
                    
                    mmi_medply_set_continue_flag(MMI_FALSE);
                }
                else
                {
                    mmi_medply_set_continue_flag(MMI_TRUE);
                }

                apply_result = mmi_medply_plst_apply_picked_file();
                if(apply_result<0)
                {
                    mmi_medply_stop_playing();
                    mmi_medply_plst_display_popup(apply_result,NULL);
                    return;
                }

                g_medply.wait_next_with_pop_up = MMI_TRUE; 
                mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);

                return;
            }

            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_PLAY_SEEKING);
            
            break;
        }

        case MEDPLY_STATE_VIDEO_INTERRUPTED:
        {
            /*shall not happen, since interrupted shall not accept avrcp and 
              shall be opening after enter screen*/
            break;
        }        

        case MEDPLY_STATE_VIDEO_OPENING:
        {
            /*close video*/
            mdi_video_ply_stop_non_block_seek();
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_main_screen_clear_video_layer();

        #ifdef __MMI_A2DP_SUPPORT__
            /*for video idle bt connecting case, it is possible that when opening, bt is connected*/
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }

            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);            
            
            break;
        }
        
        case MEDPLY_STATE_VIDEO_READY:
        {
            /*close video*/
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();

        #ifdef __MMI_A2DP_SUPPORT__
            /*for video idle bt connecting case, it is possible that when opening, bt is connected*/
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }

            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            
            break;
        }

        case MEDPLY_STATE_VIDEO_BT_CONNECTING:
        {
            /*close video*/
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }

            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);

            break;
        }

        case MEDPLY_STATE_VIDEO_PAUSE_SEEKING:
        {
            mdi_video_ply_stop_non_block_seek();
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();

            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }

            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);

            break;
        }

        case MEDPLY_STATE_VIDEO_PLAY:
        {
            /*stop video*/
            mdi_video_ply_stop();
            /*close video*/
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
         
         
            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }

            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
            break;
        }

        case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
        {
            mdi_video_ply_stop_non_block_seek();
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();

            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }

            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);           
            break;
        }

        /*AVRCP cmd*/
        case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
        {

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }

            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);            
            break;
        }

        /*AVRCP cmd*/
        case MEDPLY_STATE_PURE_AUDIO_READY:
        {
            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }

            /*since next media will not be played automatically, clear bg hdlr here*/
            mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
        
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);

            break;
        }

         /*AVRCP cmd*/
        case MEDPLY_STATE_PURE_AUDIO_PLAY:
        case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:            
        {
            mmi_medply_set_self_stop_flag(MMI_TRUE);

            mdi_audio_stop_file();

            mmi_medply_set_self_stop_flag(MMI_FALSE);

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }

            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);            
            break;
        }

    #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

    /*----stream----*/
    #ifdef __MMI_MEDIA_PLAYER_STREAM__

        case MEDPLY_STATE_STREAM_INTERRUPTED:
        case MEDPLY_STATE_STREAM_IDLE:
        {
            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }

            /* stream is stopped, clear background hdlr here*/
            if(!g_medply.in_media_player)
            {
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }
            
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_STREAM_INITED:
        {
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();

            g_medply.state = MEDPLY_STATE_STREAM_IDLE;

            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }

            /* stream is stopped, clear background hdlr here*/
            if(!g_medply.in_media_player)
            {
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }
            
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);

            break;
        }

        case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:
        {
            mmi_medply_main_screen_duration_seek_done();            
            mmi_medply_stream_buffer();
            break;
        }

        case MEDPLY_STATE_STREAM_CONNECTING:
        {
            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();

            g_medply.state = MEDPLY_STATE_STREAM_IDLE;

            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }

            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);            
            break;
        }

        case MEDPLY_STATE_STREAM_CONNECTED:
        {
            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();

            g_medply.state = MEDPLY_STATE_STREAM_IDLE;

            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
 
            /* stream is stopped, clear background hdlr here*/
            if(!g_medply.in_media_player)
            {
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
            }

            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
            break;
        }

        case MEDPLY_STATE_STREAM_BUFFERING:         
        {
            StopTimer(MEDPLY_STREAM_BUFFER_TIMER);
            mdi_video_stream_stop_buffering();
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();

            g_medply.state = MEDPLY_STATE_STREAM_IDLE;

            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
            break;
        }

        case MEDPLY_STATE_STREAM_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
        {
            mdi_video_stream_stop();
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif


            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();

            g_medply.state = MEDPLY_STATE_STREAM_IDLE;

            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
            
            break;
        }

        case MEDPLY_STATE_STREAM_BT_CONNECTING:
        {
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            mdi_video_stream_disconnect();
            mmi_medply_stream_deinit();
            mdi_audio_clear_interrupt_callback();

            g_medply.state = MEDPLY_STATE_STREAM_IDLE;

            mmi_medply_plst_pick_next();
            apply_result = mmi_medply_plst_apply_picked_file();
            if(apply_result<0)
            {
                mmi_medply_stop_playing();
                mmi_medply_plst_display_popup(apply_result,NULL);
                return;
            }
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);            
            break;
        }            
    
    #endif /*__MMI_MEDIA_PLAYER_STREAM__*/    
        default:
        {
            break;
        }
            
    }

    /*can not clear key events since AVRCP blcocked by FW case after AVRCP longpressed will call key up 
      not key canceled, if we clear key events here, the FW key stack will have some problem*/    
    /*ClearKeyEvents();*/

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_fast_forward
 * DESCRIPTION
 *  fast forward
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_fast_forward(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_FAST_FORWARD,g_medply.seekable,g_medply.state, MMI_FALSE);

    if(!g_medply.seekable || g_medply.state == MEDPLY_STATE_WAIT_NEXT || g_medply.state == MEDPLY_STATE_WAIT_NEXT_SUSPNEDED)
    {
        return;
    }

    if (!(g_medply.selected_button == MEDPLY_MAIN_NEXT && g_medply.selected_button_down == MMI_TRUE ))
    {
        return;
    }

    switch(g_medply.state)
    {
    /*----audio----*/
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        case MEDPLY_STATE_AUDIO_READY:
        {
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_FAST_FORWARD_AUDIO,g_medply.need_to_build_cache,g_medply.audio_build_cache_process, MMI_FALSE);
            mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING);

            if (g_medply.need_to_build_cache && g_medply.audio_build_cache_process< 100)
            {
                /*send message to med_v to start process*/
                mdi_audio_start_build_cache(g_medply.filefullpath,
                                            g_medply_audio_cache,
                                            MEDPLY_BUILD_CACHE_SIZE,
                                            NULL,//g_medply.audio_cache_file_buf_p,
                                            0,//MEDPLY_BUILD_CACHE_FILE_BUF_SIZE,
                                            NULL,//g_medply.audio_cache_proc_buf_p,
                                            0,//MEDPLY_BUILD_CACHE_PROC_BUF_SIZE,
                                            mmi_medply_build_cache_fail_callback_hdlr,
                                            &g_medply.audio_build_cache_process);

            }
            mmi_medply_main_screen_duration_seek_next();
            break;
        }

        case MEDPLY_STATE_AUDIO_PLAY:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
        {
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_FAST_FORWARD_AUDIO,g_medply.need_to_build_cache,g_medply.audio_build_cache_process,MMI_FALSE);
            mmi_medply_audio_seek_stop();
            mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_PLAY_PROGRESSING);

            if (g_medply.need_to_build_cache && g_medply.audio_build_cache_process< 100)
            {
                /*send message to med_v to start process*/
                mdi_audio_start_build_cache(g_medply.filefullpath,
                                            g_medply_audio_cache,
                                            MEDPLY_BUILD_CACHE_SIZE,
                                            NULL,//g_medply.audio_cache_file_buf_p,
                                            0,//MEDPLY_BUILD_CACHE_FILE_BUF_SIZE,
                                            NULL,//g_medply.audio_cache_proc_buf_p,
                                            0,//MEDPLY_BUILD_CACHE_PROC_BUF_SIZE,
                                            mmi_medply_build_cache_fail_callback_hdlr,
                                            &g_medply.audio_build_cache_process);

            }
            mmi_medply_main_screen_duration_seek_next();

            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

    /*----video----*/
    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
        case MEDPLY_STATE_VIDEO_IDLE:
        {
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE_PROGRESSING);
            mmi_medply_main_screen_duration_seek_next();
            break;
        }

        case MEDPLY_STATE_VIDEO_READY:
        {

        #ifdef __MMI_A2DP_SUPPORT__
            /*for video idle bt connecting case, it is possible that when opening, bt is connected*/
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING);
            mmi_medply_main_screen_duration_seek_next();
            break;
        }

        case MEDPLY_STATE_VIDEO_PLAY:
        {
            mdi_video_ply_stop();
        
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_PLAY_PROGRESSING);
            mmi_medply_main_screen_duration_seek_next();
            break;
        }

        case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
        {
            mdi_video_ply_stop_non_block_seek();
            mmi_medply_main_screen_duration_seek_next();
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_PLAY_PROGRESSING);

            break;
        }

        case MEDPLY_STATE_VIDEO_PAUSE_SEEKING:
        {
            mdi_video_ply_stop_non_block_seek();
            mmi_medply_main_screen_duration_seek_next();
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING);

            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

    /*----stream----*/
    #ifdef __MMI_MEDIA_PLAYER_STREAM__    
        case MEDPLY_STATE_STREAM_CONNECTED:
        {
            mmi_medply_main_screen_duration_seek_next();
            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_PLAY_PROGRESSING);
            break;
        }

        case MEDPLY_STATE_STREAM_PLAY:
        {
            mdi_video_stream_stop();
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif


            mmi_medply_main_screen_duration_seek_next();
            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_PLAY_PROGRESSING);
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_STREAM__*/

        default:
        {
            break;
        }
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_rewind
 * DESCRIPTION
 *  rewind
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_rewind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_REWIND,g_medply.seekable,g_medply.state, MMI_FALSE);

    if(!g_medply.seekable || g_medply.state == MEDPLY_STATE_WAIT_NEXT || g_medply.state == MEDPLY_STATE_WAIT_NEXT_SUSPNEDED)
    {
        return;
    }

    if (!(g_medply.selected_button == MEDPLY_MAIN_PREV && g_medply.selected_button_down == MMI_TRUE ))
    {
        return;
    }

    switch(g_medply.state)
    {
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        case MEDPLY_STATE_AUDIO_READY:
        {
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_REWIND_AUDIO,g_medply.need_to_build_cache,g_medply.audio_build_cache_process, MMI_FALSE);
            mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING);

            if (g_medply.need_to_build_cache && g_medply.audio_build_cache_process< 100)
            {
                /*send message to med_v to start process*/
                mdi_audio_start_build_cache(g_medply.filefullpath,
                                            g_medply_audio_cache,
                                            MEDPLY_BUILD_CACHE_SIZE,
                                            NULL,//g_medply.audio_cache_file_buf_p,
                                            0,//MEDPLY_BUILD_CACHE_FILE_BUF_SIZE,
                                            NULL,//g_medply.audio_cache_proc_buf_p,
                                            0,//MEDPLY_BUILD_CACHE_PROC_BUF_SIZE,
                                            mmi_medply_build_cache_fail_callback_hdlr,
                                            &g_medply.audio_build_cache_process);
            }
            mmi_medply_main_screen_duration_seek_prev();
            break;
        }

        case MEDPLY_STATE_AUDIO_PLAY:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
        {
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_REWIND_AUDIO,g_medply.need_to_build_cache,g_medply.audio_build_cache_process, MMI_FALSE);
            mmi_medply_audio_seek_stop();
            mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_PLAY_PROGRESSING);
            
            if (g_medply.need_to_build_cache && g_medply.audio_build_cache_process< 100)
            {
                /*send message to med_v to start process*/
                mdi_audio_start_build_cache(g_medply.filefullpath,
                                            g_medply_audio_cache,
                                            MEDPLY_BUILD_CACHE_SIZE,
                                            NULL,//g_medply.audio_cache_file_buf_p,
                                            0,//MEDPLY_BUILD_CACHE_FILE_BUF_SIZE,
                                            NULL,//g_medply.audio_cache_proc_buf_p,
                                            0,//MEDPLY_BUILD_CACHE_PROC_BUF_SIZE,
                                            mmi_medply_build_cache_fail_callback_hdlr,
                                            &g_medply.audio_build_cache_process);
            }
            mmi_medply_main_screen_duration_seek_prev();
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
        case MEDPLY_STATE_VIDEO_IDLE:
        {
            mmi_medply_main_screen_duration_seek_prev();
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE_PROGRESSING);
            break;
        }
    
        case MEDPLY_STATE_VIDEO_READY:
        {

        #ifdef __MMI_A2DP_SUPPORT__
            /*for video idle bt connecting case, it is possible that when opening, bt is connected*/
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_main_screen_duration_seek_prev();
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING);
            break;
        }

        case MEDPLY_STATE_VIDEO_PLAY:
        {
            mdi_video_ply_stop();
        
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif


            mmi_medply_main_screen_duration_seek_prev();
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_PLAY_PROGRESSING);
            break;
        }

        case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
        {
            mdi_video_ply_stop_non_block_seek();
            mmi_medply_main_screen_duration_seek_prev();
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_PLAY_PROGRESSING);

            break;
        }

        case MEDPLY_STATE_VIDEO_PAUSE_SEEKING:
        {
            mdi_video_ply_stop_non_block_seek();
            mmi_medply_main_screen_duration_seek_prev();
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING);

            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

    /*----stream----*/
    #ifdef __MMI_MEDIA_PLAYER_STREAM__
        case MEDPLY_STATE_STREAM_CONNECTED:
        {
            mmi_medply_main_screen_duration_seek_prev();
            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_PLAY_PROGRESSING);
            break;
        }

        case MEDPLY_STATE_STREAM_PLAY:
        {
            mdi_video_stream_stop();
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif


            mmi_medply_main_screen_duration_seek_prev();
            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_PLAY_PROGRESSING);
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_STREAM__*/

        default:
        {
            break;
        }
    }


}

#ifdef __MMI_MEDIA_PLAYER_FTE__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_FTE_inc_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_FTE_inc_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_INC_VOL,g_medply.volume,g_medply.mute, MMI_FALSE);
    
    if (g_medply.volume < MDI_AUD_VOL_EX_MUTE_MAX)
    {
        g_medply.volume ++ ;

        if(g_medply.state != MEDPLY_STATE_IDLE)
        {
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX_MUTE(g_medply.volume));
        }

        if(g_medply.mute)
        {
            g_medply.mute = MMI_FALSE;

            mmi_medply_main_screen_update_mute();

            if(!g_medply.in_main_screen)
            {
                WriteValue(NVRAM_MEDIA_PLAYER_MUTE, &g_medply.mute, DS_BYTE, &error);
            }
        }

        if(!g_medply.in_main_screen)
        {
            WriteValue(NVRAM_MEDIA_PLAYER_VOLUME, &g_medply.volume, DS_BYTE, &error);
        }
    }

    if(!g_medply.fullscreen)
    {
        mmi_medply_main_screen_update_vol();
        mmi_medply_main_screen_blt();
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_FTE_inc_volume_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_FTE_inc_volume_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_INC_VOL_DOWN, MMI_FALSE);

    mmi_medply_press_FTE_inc_volume();

    StartTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER, 300, mmi_medply_press_FTE_inc_volume_down);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_FTE_inc_volume_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_FTE_inc_volume_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_INC_VOL_UP, MMI_FALSE);

    StopTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_FTE_inc_volume_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_FTE_inc_volume_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_FTE_INC_VOL_KEY, MMI_FALSE);

    if(mmi_medply_main_screen_show_volme_tuning())
    {
        #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
        if(!g_medply.has_subtitle)
        #endif
        {
            mmi_medply_register_key_hdlrs(MMI_MEDPLY_SCREEN_VOLUME);
        }
        mmi_medply_press_FTE_inc_volume_down();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_FTE_dec_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_press_FTE_dec_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_INC_VOL,g_medply.volume,g_medply.mute, MMI_FALSE);

    if (g_medply.volume > MDI_AUD_VOL_EX_MUTE_MIN)
    {
        g_medply.volume-- ;
  
        if(g_medply.state != MEDPLY_STATE_IDLE)
        {
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX_MUTE(g_medply.volume));
        }

        if((!g_medply.mute) && (MDI_AUD_VOL_EX_MUTE_MIN == g_medply.volume))
        {
            g_medply.mute = MMI_TRUE;

            mmi_medply_main_screen_update_mute();
 
            if(!g_medply.in_main_screen)
            {
                WriteValue(NVRAM_MEDIA_PLAYER_MUTE, &g_medply.mute, DS_BYTE, &error);
            }
        }

        if(!g_medply.in_main_screen)
        {
            WriteValue(NVRAM_MEDIA_PLAYER_VOLUME, &g_medply.volume, DS_BYTE, &error);
        }
    }    

    if(!g_medply.fullscreen)
    {
        mmi_medply_main_screen_update_vol();
        mmi_medply_main_screen_blt();
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_FTE_dec_volume_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_FTE_dec_volume_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_DEC_VOL_DOWN, MMI_FALSE);

    mmi_medply_press_FTE_dec_volume();

    StartTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER, 300, mmi_medply_press_FTE_dec_volume_down);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_FTE_dec_volume_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_FTE_dec_volume_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_DEC_VOL_UP, MMI_FALSE);

    StopTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_FTE_dec_volume_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_FTE_dec_volume_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_FTE_DEC_VOL_KEY, MMI_FALSE);

    if(mmi_medply_main_screen_show_volme_tuning())
    {
        #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
        if(!g_medply.has_subtitle)
        #endif
        {
            mmi_medply_register_key_hdlrs(MMI_MEDPLY_SCREEN_VOLUME);
        }
        mmi_medply_press_FTE_dec_volume_down();
    }

}

#else

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_inc_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_press_inc_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_INC_VOL,g_medply.volume,g_medply.mute, MMI_FALSE);
    
    if (g_medply.volume < MDI_AUD_VOL_EX_MUTE_MAX)
    {
        g_medply.volume ++ ;

        if(g_medply.state != MEDPLY_STATE_IDLE)
        {
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX_MUTE(g_medply.volume));
        }

        if(g_medply.mute)
        {
            g_medply.mute = MMI_FALSE;
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_SPEAK,MMI_MEDPLY_RGN_STATUS_UP);
            if(!g_medply.in_main_screen)
            {
                WriteValue(NVRAM_MEDIA_PLAYER_MUTE, &g_medply.mute, DS_BYTE, &error);
            }
        }

        mmi_medply_main_screen_draw_volume(g_medply.volume);
        if(!g_medply.fullscreen)
        {
            mmi_medply_main_screen_blt();
        }
        if(!g_medply.in_main_screen)
        {
            WriteValue(NVRAM_MEDIA_PLAYER_VOLUME, &g_medply.volume, DS_BYTE, &error);
        }
    }
    else
    {
        mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_INC,
                MMI_MEDPLY_RGN_STATUS_DISABLE);
        if(!g_medply.fullscreen)
        {
            mmi_medply_main_screen_blt();
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_inc_volume_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_inc_volume_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_INC_VOL_DOWN, MMI_FALSE);

    if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_VOL_INC))
    {
        mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_INC,MMI_MEDPLY_RGN_STATUS_DISABLE);
        if(!g_medply.fullscreen)
        {
            mmi_medply_main_screen_blt();
        }
        return;
    }

    if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_VOL_DEC))
    {
        mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_DEC,
            MMI_MEDPLY_RGN_STATUS_UP);
    }

    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_INC,
        MMI_MEDPLY_RGN_STATUS_DOWN);

    if(!g_medply.fullscreen)
    {
        mmi_medply_main_screen_blt();
    }

    mmi_medply_press_inc_volume();

    StartTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER, 300, mmi_medply_press_inc_volume_down);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_inc_volume_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_inc_volume_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_INC_VOL_UP, MMI_FALSE);

    if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_VOL_INC))
    {
        mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_INC,
                MMI_MEDPLY_RGN_STATUS_DISABLE);
    }
    else
    {
        mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_INC,
            MMI_MEDPLY_RGN_STATUS_UP);
    }

    if(!g_medply.fullscreen)
    {
        mmi_medply_main_screen_blt();
    }

    StopTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_dec_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_press_dec_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_DEC_VOL,g_medply.volume,g_medply.mute, MMI_FALSE);
    if (g_medply.volume > MDI_AUD_VOL_EX_MUTE_MIN)
    {
        g_medply.volume-- ;
  
        if(g_medply.state != MEDPLY_STATE_IDLE)
        {
            mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX_MUTE(g_medply.volume));
        }

        if(g_medply.mute)
        {
            g_medply.mute = MMI_FALSE;
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_SPEAK,MMI_MEDPLY_RGN_STATUS_UP);
            if(!g_medply.in_main_screen)
            {
                WriteValue(NVRAM_MEDIA_PLAYER_MUTE, &g_medply.mute, DS_BYTE, &error);
            }
        }
#if defined (__MMI_FTE_SUPPORT__)
	if (g_medply.volume == 0)
	{
		/* make sure enter mute mode when volume is 0 */
            g_medply.mute = MMI_TRUE;
            mdi_audio_set_mute(VOL_TYPE_MEDIA,g_medply.mute);
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_SPEAK,MMI_MEDPLY_RGN_STATUS_UP);
            if(!g_medply.in_main_screen)
            {
                WriteValue(NVRAM_MEDIA_PLAYER_MUTE, &g_medply.mute, DS_BYTE, &error);
            }
	}
#endif



        mmi_medply_main_screen_draw_volume(g_medply.volume);

        if(!g_medply.fullscreen)
        {        
            mmi_medply_main_screen_blt();
        }
        if(!g_medply.in_main_screen)
        {
            WriteValue(NVRAM_MEDIA_PLAYER_VOLUME, &g_medply.volume, DS_BYTE, &error);
        }
    }    
    else
    {
        mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_DEC,
                MMI_MEDPLY_RGN_STATUS_DISABLE);
        if(!g_medply.fullscreen)
        {
            mmi_medply_main_screen_blt();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_dec_volume_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_dec_volume_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_DEC_VOL_DOWN, MMI_FALSE);

    if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_VOL_DEC))
    {
        mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_DEC,MMI_MEDPLY_RGN_STATUS_DISABLE);
        if(!g_medply.fullscreen)
        {
            mmi_medply_main_screen_blt();
        }
        return;
    }

    if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_VOL_INC))
    {
        mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_INC,
            MMI_MEDPLY_RGN_STATUS_UP);
    }

    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_DEC,
        MMI_MEDPLY_RGN_STATUS_DOWN);

    if(!g_medply.fullscreen)
    {
        mmi_medply_main_screen_blt();
    }

    mmi_medply_press_dec_volume();

    StartTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER, 300, mmi_medply_press_dec_volume_down);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_dec_volume_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_dec_volume_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_DEC_VOL_UP, MMI_FALSE);

    if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_VOL_DEC))
    {
        mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_DEC,
            MMI_MEDPLY_RGN_STATUS_DISABLE);
    }
    else
    {
        mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_DEC,
            MMI_MEDPLY_RGN_STATUS_UP);
    }

    if(!g_medply.fullscreen)
    {
        mmi_medply_main_screen_blt();
    }

    StopTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER);

}
#endif /* __MMI_MEDIA_PLAYER_FTE__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_inc_volume
 * DESCRIPTION
 *  for external use
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_inc_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_MEDIA_PLAYER_FTE__
        mmi_medply_press_FTE_inc_volume();
    #else 
        mmi_medply_press_inc_volume();
    #endif 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_dec_volume
 * DESCRIPTION
 *  for external use
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_dec_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_MEDIA_PLAYER_FTE__
        mmi_medply_press_FTE_dec_volume();
    #else 
        mmi_medply_press_dec_volume();
    #endif 
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_lsk_down
 * DESCRIPTION
 *  only takes care of the draw button part
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_lsk_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_LSK_DOWN, MMI_FALSE);

    g_medply.unaffected_button_down = MMI_MEDPLY_RGN_ID_LKEY;

    mmi_medply_main_screen_draw_lkey_down();
    mmi_medply_main_screen_blt();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_lsk_up
 * DESCRIPTION
 *  only takes care of the draw button part
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_lsk_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_LSK_UP, MMI_FALSE);

    mmi_medply_main_screen_draw_lkey_up();
    mmi_medply_main_screen_blt();

    if(g_medply.unaffected_button_down != MMI_MEDPLY_RGN_ID_LKEY)
    {
        return;
    }

    g_medply.unaffected_button_down = MMI_MEDPLY_RGN_ID_NULL;
    mmi_medply_entry_main_menu_option();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_rsk_down
 * DESCRIPTION
 *  only takes care of the draw button part
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_rsk_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_RSK_DOWN, MMI_FALSE);

    g_medply.unaffected_button_down = MMI_MEDPLY_RGN_ID_RKEY;

    mmi_medply_main_screen_draw_rkey_down();
    mmi_medply_main_screen_blt();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_rsk_up
 * DESCRIPTION
 *  only takes care of the draw button part
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_rsk_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_RSK_UP, MMI_FALSE);

    mmi_medply_main_screen_draw_rkey_up();
    mmi_medply_main_screen_blt();

    if(g_medply.unaffected_button_down != MMI_MEDPLY_RGN_ID_RKEY)
    {
        return;
    }

    g_medply.unaffected_button_down = MMI_MEDPLY_RGN_ID_NULL;
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_toggle_mute
 * DESCRIPTION
 *  handle mute / un-mute
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_toggle_mute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_TOGGLE_MUTE,g_medply.mute, MMI_FALSE);
    
    if(g_medply.mute)
    {
        g_medply.mute = MMI_FALSE;
        mdi_audio_set_volume(VOL_TYPE_MEDIA,MDI_AUD_VOL_EX_MUTE(g_medply.volume));
    }
    else
    {
        g_medply.mute = MMI_TRUE;
    }

    mdi_audio_set_mute(VOL_TYPE_MEDIA,g_medply.mute);
    
    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_SPEAK,MMI_MEDPLY_RGN_STATUS_UP);
    mmi_medply_main_screen_blt();

    if(!g_medply.in_main_screen)
    {
        WriteValue(NVRAM_MEDIA_PLAYER_MUTE, &g_medply.mute, DS_BYTE, &error);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_mute_down
 * DESCRIPTION
 *  handle press mute key down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_mute_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_MUTE_DOWN, MMI_FALSE);
    g_medply.unaffected_button_down = MMI_MEDPLY_RGN_ID_VOLUME_SPEAK;
    
    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_SPEAK,
        MMI_MEDPLY_RGN_STATUS_DOWN);
    mmi_medply_main_screen_blt();
 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_mute_up
 * DESCRIPTION
 *  handle press muet key up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_mute_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_MUTE_UP, MMI_FALSE);

    if( g_medply.unaffected_button_down != MMI_MEDPLY_RGN_ID_VOLUME_SPEAK)
    {
        return;
    }

    g_medply.unaffected_button_down = MMI_MEDPLY_RGN_ID_NULL;

    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_SPEAK,
            MMI_MEDPLY_RGN_STATUS_UP);
    mmi_medply_main_screen_blt();

    /* Only toggle mute when the volume level is not min (0) */
    if (g_medply.volume != MDI_AUD_VOL_EX_MUTE_MIN)
    {
        mmi_medply_toggle_mute();
    }

    ClearKeyEvents();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_dummy_key_hdlr
 * DESCRIPTION
 *  dummy key hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_dummy_key_hdlr()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    /*dummy*/
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_toggle_full_screen
 * DESCRIPTION
 *  handle switch in/out full screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_toggle_full_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_TOGGLE_FULL,g_medply.fullscreen,g_medply.state);

    if(!g_medply.fullscreen)
    {
        /*toggle to fullscreen*/

        g_medply.fullscreen = MMI_TRUE;

        /*register key hdlr*/
        mmi_medply_register_key_hdlrs(MMI_MEDPLY_SCREEN_FULL);

        switch(g_medply.state)
        {
            case MEDPLY_STATE_WAIT_NEXT:
            {
                mmi_medply_main_screen_set_full_screen(MMI_TRUE);
                mmi_medply_main_screen_blt();
                StopTimer(MEDPLY_UPDATE_TIME_TIMER);
                mmi_medply_set_continue_flag(MMI_TRUE);
                mmi_medply_stop_wait_next_timer();
                mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
                break;
            }

        #ifdef __MMI_MEDIA_PLAYER_AUDIO__
            case MEDPLY_STATE_AUDIO_READY:
            {
                mmi_medply_main_screen_set_full_screen(MMI_TRUE);
                mmi_medply_main_screen_redraw();
                mmi_medply_main_screen_blt();
                mmi_medply_audio_play();
                break;
            }
            case MEDPLY_STATE_AUDIO_PLAY:
            case MEDPLY_STATE_AUDIO_BT_CONNECTING:
            case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
            {
                mmi_medply_main_screen_set_full_screen(MMI_TRUE);
                mmi_medply_main_screen_redraw();
                mmi_medply_main_screen_blt();
                break;
            }
        #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/
        
        #ifdef __MMI_MEDIA_PLAYER_VIDEO__
            case MEDPLY_STATE_VIDEO_IDLE:
            {
                mmi_medply_main_screen_set_full_screen(MMI_TRUE);
                mmi_medply_main_screen_clear_video_layer();
                mmi_medply_main_screen_redraw();
                mmi_medply_main_screen_blt();

                mmi_medply_set_continue_flag(MMI_TRUE);
                mmi_medply_video_open();
                break;
            }

            case MEDPLY_STATE_VIDEO_IDLE_BT_CONNECTING:
            {
                mmi_medply_main_screen_set_full_screen(MMI_TRUE);
                mmi_medply_main_screen_clear_video_layer();
                mmi_medply_main_screen_redraw();
                mmi_medply_main_screen_blt();
                break;
            }

            case MEDPLY_STATE_VIDEO_OPENING:
            {
                mdi_video_ply_stop_non_block_seek();
                mmi_medply_video_close();

                mmi_medply_main_screen_set_full_screen(MMI_TRUE);
                mmi_medply_main_screen_redraw();
                mmi_medply_main_screen_blt();

                mmi_medply_set_continue_flag(MMI_TRUE);
                mdi_audio_clear_interrupt_callback();
                mmi_medply_video_open();

                break;
            }

            case MEDPLY_STATE_VIDEO_READY:
            {
                mmi_medply_video_play_para_struct video_layer_info;
                //MDI_RESULT result;

                mmi_medply_main_screen_set_full_screen(MMI_TRUE);

                video_layer_info.video_height = g_medply.height;
                video_layer_info.video_width = g_medply.width;
                mmi_medply_main_screen_get_video_parameter(&video_layer_info);
                
                mmi_medply_adption_video_get_frame(
                            video_layer_info.layer_hdl
                      #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                            ,video_layer_info.layer_subtitle_hdl
                      #endif
                            );

                mmi_medply_video_play();

                break;
            }

            case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
            case MEDPLY_STATE_VIDEO_PAUSE_SEEKING:
            {
                MDI_RESULT result;
                mmi_medply_video_play_para_struct video_layer_info;
                
                /*switch to full screen*/
                mdi_video_ply_stop_non_block_seek();
                mmi_medply_main_screen_set_full_screen(MMI_TRUE);
                mmi_medply_main_screen_clear_video_layer();
                mmi_medply_main_screen_redraw();
                mmi_medply_main_screen_blt();

                video_layer_info.video_height = g_medply.height;
                video_layer_info.video_width = g_medply.width;
                mmi_medply_main_screen_get_video_parameter(&video_layer_info);

                result = mmi_medply_adption_video_non_block_seek_and_get_frame(
                          g_medply.current_time, 
                          video_layer_info.layer_hdl,
                          #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                          video_layer_info.layer_subtitle_hdl,
                          #endif
                          mmi_medply_video_seek_callback_hdlr,
                          0); 

                if (result < 0)
                {
                    S32 apply_result = 0 ;

                    mmi_medply_video_close();
                    mdi_audio_clear_interrupt_callback();

                    mmi_medply_set_pop_up_flag();
                    mmi_medply_display_popup(result,MMI_TRUE);

                    if(mmi_medply_plst_do_pick() < 0)
                    {
                        /*when pick fail, call it again to reset the list*/
                        mmi_medply_plst_do_pick();
                    }

                    apply_result = mmi_medply_plst_apply_picked_file();
                    if(apply_result<0)
                    {
                        mmi_medply_stop_playing();
                        mmi_medply_plst_display_popup(apply_result,NULL);
                        return;
                    }
                    mmi_medply_set_continue_flag(MMI_TRUE);
                    g_medply.wait_next_with_pop_up = MMI_TRUE;
                    mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
         
                    return;
                }
                mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_PLAY_SEEKING);
                break;
            }

            case MEDPLY_STATE_VIDEO_PLAY:
            {
                MDI_RESULT result;
                mmi_medply_video_play_para_struct video_layer_info;
                    
                result = mdi_video_ply_update_layer_pause();

                if (result < 0)
                {
                    S32 apply_result = 0 ;

                    mmi_medply_video_close();
                    mdi_audio_clear_interrupt_callback();

                    mmi_medply_set_pop_up_flag();
                    mmi_medply_display_popup(result,MMI_TRUE);

                    if(mmi_medply_plst_do_pick() < 0)
                    {
                        /*when pick fail, call it again to reset the list*/
                        mmi_medply_plst_do_pick();
                    }

                    apply_result = mmi_medply_plst_apply_picked_file();
                    if(apply_result<0)
                    {
                        mmi_medply_stop_playing();
                        mmi_medply_plst_display_popup(apply_result,NULL);
                        return;
                    }
                    mmi_medply_set_continue_flag(MMI_TRUE);
                    g_medply.wait_next_with_pop_up = MMI_TRUE;
                    mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
         
                    return;
                }

                mmi_medply_main_screen_set_full_screen(MMI_TRUE);
                mmi_medply_main_screen_clear_video_layer();
                mmi_medply_main_screen_blt();

                video_layer_info.video_height = g_medply.height;
                video_layer_info.video_width = g_medply.width;
                mmi_medply_main_screen_get_video_parameter(&video_layer_info);

                result = mmi_medply_adption_video_update_layer_resume(
                            video_layer_info.layer_hdl, 
                            video_layer_info.layer_blt_flag, 
                            video_layer_info.layer_play_flag, 
                            #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                            video_layer_info.layer_subtitle_hdl,
                            video_layer_info.layer_subtitle_flag,
                            #endif
                            MMI_TRUE, 
                            video_layer_info.layer_lcd_rotate
                            );

                if (result < 0)
                {
                    S32 apply_result = 0 ;

                    mmi_medply_video_close();
                    mdi_audio_clear_interrupt_callback();

                    mmi_medply_set_pop_up_flag();
                    mmi_medply_display_popup(result,MMI_TRUE);

                    if(mmi_medply_plst_do_pick() < 0)
                    {
                        /*when pick fail, call it again to reset the list*/
                        mmi_medply_plst_do_pick();
                    }

                    apply_result = mmi_medply_plst_apply_picked_file();
                    if(apply_result<0)
                    {
                        mmi_medply_stop_playing();
                        mmi_medply_plst_display_popup(apply_result,NULL);
                        return;
                    }
                    mmi_medply_set_continue_flag(MMI_TRUE);
                    g_medply.wait_next_with_pop_up = MMI_TRUE;
                    mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
         
                    return;
                }

                break;
            }

            case MEDPLY_STATE_VIDEO_BT_CONNECTING:
            {
                mmi_medply_video_play_para_struct video_layer_info;
                //MDI_RESULT result;

            #ifdef __MMI_A2DP_SUPPORT__
                mmi_medply_bt_stop(MMI_FALSE);
            #endif

                mmi_medply_main_screen_set_full_screen(MMI_TRUE);

                video_layer_info.video_height = g_medply.height;
                video_layer_info.video_width = g_medply.width;
                mmi_medply_main_screen_get_video_parameter(&video_layer_info);

                mmi_medply_adption_video_get_frame(
                        video_layer_info.layer_hdl
                  #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                        ,video_layer_info.layer_subtitle_hdl
                  #endif
                        );
                    
                mmi_medply_video_play();
                
                break;
            }
        #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

        #ifdef __MMI_MEDIA_PLAYER_STREAM__
            case MEDPLY_STATE_STREAM_IDLE:
            {
                if(mmi_medply_stream_init())
                {
                    mmi_medply_main_screen_set_full_screen(MMI_TRUE);
                    mmi_medply_main_screen_clear_video_layer();
                    mmi_medply_main_screen_redraw();
                    mmi_medply_main_screen_blt();
                    if(!mmi_medply_stream_connect())
                    {
                        return;
                    }
                }
                break;
            }

            case MEDPLY_STATE_STREAM_INITED:
            {
                mmi_medply_main_screen_set_full_screen(MMI_TRUE);
                mmi_medply_main_screen_clear_video_layer();
                mmi_medply_main_screen_redraw();
                mmi_medply_main_screen_blt();
                if(!mmi_medply_stream_connect())
                {
                    return;
                }
                break;
            }

            case MEDPLY_STATE_STREAM_CONNECTING:
            {
                mmi_medply_main_screen_set_full_screen(MMI_TRUE);
                mmi_medply_main_screen_clear_video_layer();
                mmi_medply_main_screen_redraw();
                mmi_medply_main_screen_blt();
                break;
            }

            case MEDPLY_STATE_STREAM_BUFFERING:                
            {
                mmi_medply_main_screen_set_full_screen(MMI_TRUE);
                mmi_medply_main_screen_clear_video_layer();
                mmi_medply_main_screen_redraw();
                mmi_medply_main_screen_blt();
                break;
            }

            case MEDPLY_STATE_STREAM_CONNECTED:
            {
                mmi_medply_main_screen_set_full_screen(MMI_TRUE);
                mmi_medply_stream_buffer();
                break;
            }

            case MEDPLY_STATE_STREAM_PLAY:
            {
                mmi_medply_video_play_para_struct video_layer_info;
                    
                mdi_video_stream_pause();
                mmi_medply_main_screen_set_full_screen(MMI_TRUE);
                mmi_medply_main_screen_clear_video_layer();
                mmi_medply_main_screen_blt();

                video_layer_info.video_height = g_medply.height;
                video_layer_info.video_width = g_medply.width;
                mmi_medply_main_screen_get_video_parameter(&video_layer_info);

                mdi_video_stream_resume(
                    video_layer_info.layer_hdl, 
                    video_layer_info.layer_blt_flag, 
                    video_layer_info.layer_play_flag, 
                    MMI_TRUE, 
                    MDI_DEVICE_SPEAKER2, 
                    video_layer_info.layer_lcd_rotate
                    );

                mmi_medply_change_status(MMI_TRUE);
                break;
            }

            case MEDPLY_STATE_STREAM_BT_CONNECTING:
            {
                mmi_medply_main_screen_set_full_screen(MMI_TRUE);
                mmi_medply_main_screen_clear_video_layer();
                mmi_medply_main_screen_redraw();
                mmi_medply_main_screen_blt();
                break;
            }

        #endif /*__MMI_MEDIA_PLAYER_STREAM__*/
            default :
            {
                return;
            }
        
        }

    }
    else
    {
        /*toggle to normal screen*/

        g_medply.fullscreen = MMI_FALSE;

        /*register key hdlr*/
        mmi_medply_register_key_hdlrs(MMI_MEDPLY_SCREEN_NORMAL);

        switch(g_medply.state)
        {
            case MEDPLY_STATE_WAIT_NEXT:
            {
                mmi_medply_main_screen_set_full_screen(MMI_FALSE);
                mmi_medply_main_screen_redraw();
                mmi_medply_main_screen_blt();
                break;
            }

        #ifdef __MMI_MEDIA_PLAYER_AUDIO__
            case MEDPLY_STATE_AUDIO_PLAY:
            case MEDPLY_STATE_AUDIO_BT_CONNECTING:
            case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
            {
                mmi_medply_main_screen_set_full_screen(MMI_FALSE);
                mmi_medply_main_screen_redraw();
                mmi_medply_main_screen_blt();
                break;
            }
        #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

        #ifdef __MMI_MEDIA_PLAYER_VIDEO__

            case MEDPLY_STATE_VIDEO_IDLE_BT_CONNECTING:
            {
                mmi_medply_main_screen_set_full_screen(MMI_FALSE);
                mmi_medply_main_screen_clear_video_layer();
                mmi_medply_main_screen_blt();
                break;
            }

            case MEDPLY_STATE_VIDEO_OPENING:
            {
                mdi_video_ply_stop_non_block_seek();
                mmi_medply_video_close();

                mmi_medply_main_screen_set_full_screen(MMI_FALSE);
                mmi_medply_main_screen_clear_video_layer();
                mmi_medply_main_screen_redraw();
                mmi_medply_main_screen_blt();

                mmi_medply_set_continue_flag(MMI_TRUE);
                mdi_audio_clear_interrupt_callback();
                mmi_medply_video_open();

                break;
            }

            case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
            case MEDPLY_STATE_VIDEO_PAUSE_SEEKING:
            {
                MDI_RESULT result;
                mmi_medply_video_play_para_struct video_layer_info;

                /*switch to full screen*/
                mdi_video_ply_stop_non_block_seek();
                mmi_medply_main_screen_set_full_screen(MMI_FALSE);
                mmi_medply_main_screen_clear_video_layer();
                mmi_medply_main_screen_redraw();
                mmi_medply_main_screen_blt();

                video_layer_info.video_height = g_medply.height;
                video_layer_info.video_width = g_medply.width;
                mmi_medply_main_screen_get_video_parameter(&video_layer_info);

                result = mmi_medply_adption_video_non_block_seek_and_get_frame(
                        g_medply.current_time,
                        video_layer_info.layer_hdl,
                        #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                        video_layer_info.layer_subtitle_hdl,
                        #endif
                        mmi_medply_video_seek_callback_hdlr,
                        0);

                if (result < 0)
                {
                    S32 apply_result = 0 ;

                    mmi_medply_video_close();
                    mdi_audio_clear_interrupt_callback();

                    mmi_medply_set_pop_up_flag();
                    mmi_medply_display_popup(result,MMI_TRUE);

                    if(mmi_medply_plst_do_pick() < 0)
                    {
                        /*when pick fail, call it again to reset the list*/
                        mmi_medply_plst_do_pick();
                    }

                    apply_result = mmi_medply_plst_apply_picked_file();
                    if(apply_result<0)
                    {
                        mmi_medply_stop_playing();
                        mmi_medply_plst_display_popup(apply_result,NULL);
                        return;
                    }
                    mmi_medply_set_continue_flag(MMI_TRUE);
                    g_medply.wait_next_with_pop_up = MMI_TRUE;
                    mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
         
                    return;
                }

                mmi_medply_enter_video_states(g_medply.state);
                break;
            }

            case MEDPLY_STATE_VIDEO_PLAY:
            {
                MDI_RESULT result;
                mmi_medply_video_play_para_struct video_layer_info;

                result = mdi_video_ply_update_layer_pause();

                if (result < 0)
                {
                    S32 apply_result = 0 ;

                    mmi_medply_video_close();
                    mdi_audio_clear_interrupt_callback();

                    mmi_medply_set_pop_up_flag();
                    mmi_medply_display_popup(result,MMI_TRUE);

                    if(mmi_medply_plst_do_pick() < 0)
                    {
                        /*when pick fail, call it again to reset the list*/
                        mmi_medply_plst_do_pick();
                    }

                    apply_result = mmi_medply_plst_apply_picked_file();
                    if(apply_result<0)
                    {
                        mmi_medply_stop_playing();
                        mmi_medply_plst_display_popup(apply_result,NULL);
                        return;
                    }
                    mmi_medply_set_continue_flag(MMI_TRUE);
                    g_medply.wait_next_with_pop_up = MMI_TRUE;
                    mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
         
                    return;
                }

                mmi_medply_main_screen_set_full_screen(MMI_FALSE);
                mmi_medply_main_screen_clear_video_layer();
                mmi_medply_main_screen_blt();

                video_layer_info.video_height = g_medply.height;
                video_layer_info.video_width = g_medply.width;
                mmi_medply_main_screen_get_video_parameter(&video_layer_info);

                result = mmi_medply_adption_video_update_layer_resume(
                            video_layer_info.layer_hdl, 
                            video_layer_info.layer_blt_flag, 
                            video_layer_info.layer_play_flag, 
                            #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                            video_layer_info.layer_subtitle_hdl,
                            video_layer_info.layer_subtitle_flag,
                            #endif
                            MMI_TRUE, 
                            video_layer_info.layer_lcd_rotate
                            );

                if (result < 0)
                {
                    S32 apply_result = 0 ;

                    mmi_medply_video_close();
                    mdi_audio_clear_interrupt_callback();

                    mmi_medply_set_pop_up_flag();
                    mmi_medply_display_popup(result,MMI_TRUE);

                    if(mmi_medply_plst_do_pick() < 0)
                    {
                        /*when pick fail, call it again to reset the list*/
                        mmi_medply_plst_do_pick();
                    }

                    apply_result = mmi_medply_plst_apply_picked_file();
                    if(apply_result<0)
                    {
                        mmi_medply_stop_playing();
                        mmi_medply_plst_display_popup(apply_result,NULL);
                        return;
                    }
                    mmi_medply_set_continue_flag(MMI_TRUE);
                    g_medply.wait_next_with_pop_up = MMI_TRUE;
                    mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
         
                    return;
                }

                break;
            }

            case MEDPLY_STATE_VIDEO_BT_CONNECTING:
            {
                mmi_medply_video_play_para_struct video_layer_info;
                MDI_RESULT result;

            #ifdef __MMI_A2DP_SUPPORT__
                mmi_medply_bt_stop(MMI_FALSE);
            #endif

                mmi_medply_main_screen_set_full_screen(MMI_FALSE);

                video_layer_info.video_height = g_medply.height;
                video_layer_info.video_width = g_medply.width;
                mmi_medply_main_screen_get_video_parameter(&video_layer_info);

                result = mmi_medply_adption_video_non_block_seek_and_get_frame(
                          g_medply.current_time, 
                          video_layer_info.layer_hdl,
                          #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                          video_layer_info.layer_subtitle_hdl,
                          #endif
                          mmi_medply_video_seek_callback_hdlr,
                          0); 

                if (result < 0)
                {
                    S32 apply_result = 0 ;

                    mmi_medply_video_close();
                    mdi_audio_clear_interrupt_callback();

                    mmi_medply_set_pop_up_flag();
                    mmi_medply_display_popup(result,MMI_TRUE);

                    if(mmi_medply_plst_do_pick() < 0)
                    {
                        /*when pick fail, call it again to reset the list*/
                        mmi_medply_plst_do_pick();
                    }

                    apply_result = mmi_medply_plst_apply_picked_file();
                    if(apply_result<0)
                    {
                        mmi_medply_stop_playing();
                        mmi_medply_plst_display_popup(apply_result,NULL);
                        return;
                    }
                    mmi_medply_set_continue_flag(MMI_TRUE);
                    g_medply.wait_next_with_pop_up = MMI_TRUE;
                    mmi_medply_enter_core_states(MEDPLY_STATE_WAIT_NEXT);
         
                    return;
                }

                mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_PLAY_SEEKING);
                break;
            }
        #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/ 

        #ifdef __MMI_MEDIA_PLAYER_STREAM__
            case MEDPLY_STATE_STREAM_INITED:
            case MEDPLY_STATE_STREAM_CONNECTING:
            case MEDPLY_STATE_STREAM_BUFFERING:
            case MEDPLY_STATE_STREAM_BT_CONNECTING:
            {
                mmi_medply_main_screen_set_full_screen(MMI_FALSE);
                mmi_medply_main_screen_clear_video_layer();
                mmi_medply_main_screen_redraw();
                mmi_medply_main_screen_blt();
                break;
            }

            case MEDPLY_STATE_STREAM_PLAY:
            {
                mmi_medply_video_play_para_struct video_layer_info;

                mdi_video_stream_pause();
                mmi_medply_main_screen_set_full_screen(MMI_FALSE);
                mmi_medply_main_screen_clear_video_layer();
                mmi_medply_main_screen_blt();

                video_layer_info.video_height = g_medply.height;
                video_layer_info.video_width = g_medply.width;
                mmi_medply_main_screen_get_video_parameter(&video_layer_info);

                mdi_video_stream_resume(
                    video_layer_info.layer_hdl, 
                    video_layer_info.layer_blt_flag, 
                    video_layer_info.layer_play_flag, 
                    MMI_TRUE, 
                    MDI_DEVICE_SPEAKER2, 
                    video_layer_info.layer_lcd_rotate
                    );
                break;
            }

        #endif /*__MMI_MEDIA_PLAYER_STREAM__*/

            default:
            {
                MMI_ASSERT(0);
            }
        }
    }

    ClearKeyEvents();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_full_screen_down
 * DESCRIPTION
 *  handle press full sceen key down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_full_screen_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_FULL_DOWN,g_medply.state);

    g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_ZOOM;
    
    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_ZOOM,
        MMI_MEDPLY_RGN_STATUS_DOWN);
    mmi_medply_main_screen_blt();
 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_full_screen_up
 * DESCRIPTION
 *  handle press full sceen key up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_full_screen_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_FULL_UP);

    /*in case the flag is reset for state change, always redraw key up*/
    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_ZOOM,
            MMI_MEDPLY_RGN_STATUS_UP);
    mmi_medply_main_screen_blt();

    if( g_medply.affected_button_down != MMI_MEDPLY_RGN_ID_ZOOM)
    {
        return;
    }

    g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_NULL;

    mmi_medply_toggle_full_screen();

}


#ifdef __MMI_VIDEO_3D_ANAGLYPH__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_toggle_play_mode
 * DESCRIPTION
 *  handle switch in/out full screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_toggle_play_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(g_medply.state)
        {
    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
            case MEDPLY_STATE_VIDEO_IDLE:
            {
                break;
            }

            case MEDPLY_STATE_VIDEO_IDLE_BT_CONNECTING:
            {
                break;
            }

            case MEDPLY_STATE_VIDEO_OPENING:
            {
                mdi_video_ply_stop_non_block_seek();
                mmi_medply_video_close();
		mdi_audio_clear_interrupt_callback();
                mmi_medply_video_open();
                break;
            }

            case MEDPLY_STATE_VIDEO_READY:
            {
                mmi_medply_video_close();
                mdi_audio_clear_interrupt_callback();
                mmi_medply_video_open();
                break;
            }

            case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
			{
                mdi_video_ply_stop_non_block_seek();
                mmi_medply_video_close();
                mmi_medply_set_continue_flag(MMI_TRUE);
                mdi_audio_clear_interrupt_callback();
                mmi_medply_video_open();
                break;
            }
			
            case MEDPLY_STATE_VIDEO_PAUSE_SEEKING:
            {
                mdi_video_ply_stop_non_block_seek();
                mmi_medply_video_close();
                mmi_medply_set_continue_flag(MMI_FALSE);
                mdi_audio_clear_interrupt_callback();
                mmi_medply_video_open();
                break;
            }

            case MEDPLY_STATE_VIDEO_PLAY:
            {
				mdi_video_ply_stop();

                #ifdef __MMI_A2DP_SUPPORT__
                    g_medply.bt_connect_fail = MMI_FALSE;
                    mmi_medply_bt_stop(MMI_FALSE);
                #endif
                
				mmi_medply_video_close();
                mmi_medply_set_continue_flag(MMI_TRUE);
                mdi_audio_clear_interrupt_callback();
                mmi_medply_video_open();
                break;
            }

            case MEDPLY_STATE_VIDEO_BT_CONNECTING:
            {   
                mmi_medply_video_close();
                mmi_medply_set_continue_flag(MMI_TRUE);
                mdi_audio_clear_interrupt_callback();
                mmi_medply_video_open();
                break;
            }
        #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/
		    default:
		        break;
		}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_play_mode_down
 * DESCRIPTION
 *  handle press full sceen key down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_play_mode_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_3D_MODE_DOWN,g_medply.state);

    if(g_medply.has_3d_mode)
    {
        g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_MODE;
    
		mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_MODE,
		    MMI_MEDPLY_RGN_STATUS_DOWN);
		mmi_medply_main_screen_blt();
    }
 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_play_mode_up
 * DESCRIPTION
 *  handle press full sceen key up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_play_mode_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 play_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_3D_MODE_UP);

    /*in case the flag is reset for state change, always redraw key up*/

    if( g_medply.affected_button_down != MMI_MEDPLY_RGN_ID_MODE)
    {
        return;
    }

    if(!g_medply.has_2d_mode)
    {
        mmi_medply_display_popup_with_sg((U16)STR_ID_MEDPLY_3D_ONLY, MMI_EVENT_FAILURE);
        return;
    }

    g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_NULL;

    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_PLAY_MODE, &play_mode);

    mmi_medply_settings_toggle_play_mode();
	
    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_MODE,
            MMI_MEDPLY_RGN_STATUS_UP);
    mmi_medply_main_screen_blt();

    mmi_medply_toggle_play_mode();

}
#endif



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_full_screen_key_down_hdlr
 * DESCRIPTION
 *  handle full screen key down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_full_screen_key_down_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_ZOOM))
    {
        return;
    }

        mmi_medply_press_full_screen_down();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_full_screen_key_up_hdlr
 * DESCRIPTION
 *  handle full screen key up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_full_screen_key_up_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_ZOOM))
    {
        mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_ZOOM,
            MMI_MEDPLY_RGN_STATUS_DISABLE);
        mmi_medply_main_screen_blt();

        return;
    }

        mmi_medply_press_full_screen_up();


}

#if defined(__MMI_MEDIA_PLAYER_SNAPSHOT__) 
#ifdef __MMI_MEDIA_PLAYER_SNAPSHOT__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_snapshot_down
 * DESCRIPTION
 *  snapshot key down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_snapshot_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_SNAPSHOT_DOWN,g_medply.state,g_medply.enable_snapshot);

    if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_SNAPSHOT) || g_medply.enable_snapshot == MMI_FALSE)
    {
        return;
    }

    switch(g_medply.state)
    {
    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
        case MEDPLY_STATE_VIDEO_READY:
        case MEDPLY_STATE_VIDEO_PLAY:
        {
            if( mdi_video_ply_is_drm_file() )
            {
                return;
            }
            break;
        }
    #endif

    #ifdef __MMI_MEDIA_PLAYER_STREAM__
        case MEDPLY_STATE_STREAM_PLAY:
        {
            if( mdi_video_stream_is_drm_streaming() )
            {
                return;
            }
            break;
        }
    #endif

        default:
        {
            return;
        }
    }

    g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY;

    mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY,
            MMI_MEDPLY_RGN_STATUS_DOWN);
    mmi_medply_main_screen_blt();
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_snapshot_up
 * DESCRIPTION
 *  snapshot key up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_snapshot_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_SNAPSHOT_UP);

    if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_SNAPSHOT))
    {
        mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY,
            MMI_MEDPLY_RGN_STATUS_DISABLE);
        g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_NULL;
    }
    else
    {
        mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY,
                MMI_MEDPLY_RGN_STATUS_UP);
    }
    mmi_medply_main_screen_blt();

    if(g_medply.affected_button_down != MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY)
    {
        return;
    }

    g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_NULL;

    /* take snapshot */
    mmi_medply_take_snapshot();

    ClearKeyEvents();

}
#endif /* __MMI_MEDIA_PLAYER_SNAPSHOT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_snapshot_activate_down
 * DESCRIPTION
 *  press snapshot / activate key down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_snapshot_activate_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    {
    #ifdef __MMI_MEDIA_PLAYER_SNAPSHOT__
        mmi_medply_press_snapshot_down();
    #endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_snapshot_activate_up
 * DESCRIPTION
 *  snapshot key up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_snapshot_activate_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    {
    #ifdef __MMI_MEDIA_PLAYER_SNAPSHOT__
        mmi_medply_press_snapshot_up();
    #endif
    }

}

#endif /*defined(__MMI_MEDIA_PLAYER_SNAPSHOT__)*/

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_press_button_canceled
 * DESCRIPTION
 *  to cancel key down action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_press_button_canceled()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_regn_id_enum button_rgn_id = MMI_MEDPLY_RGN_ID_NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_AVRCP_CANCELED,g_medply.selected_button,g_medply.selected_button_down);

    if(g_medply.selected_button == MEDPLY_MAIN_DISABLED || g_medply.selected_button_down == MMI_FALSE)
    {
        return;
    }

    switch(g_medply.selected_button)
    {
        case MEDPLY_MAIN_PLAY:
        case MEDPLY_MAIN_PAUSE:
        {
            button_rgn_id = MMI_MEDPLY_RGN_ID_PLAY_PAUSE;
            break;
        }
        case MEDPLY_MAIN_NEXT:
        {
            button_rgn_id = MMI_MEDPLY_RGN_ID_NEXT;
            break;
        }
        case MEDPLY_MAIN_PREV:
        {
            button_rgn_id = MMI_MEDPLY_RGN_ID_PREV;
            break;
        }
        case MEDPLY_MAIN_STOP:
        {
            button_rgn_id = MMI_MEDPLY_RGN_ID_STOP;
            break;
        }
    }

    g_medply.selected_button_down = MMI_FALSE ;

    mmi_medply_main_screen_set_and_draw_button(button_rgn_id,
            MMI_MEDPLY_RGN_STATUS_UP);

    mmi_medply_main_screen_blt();

}

#ifdef __MMI_MEDIA_PLAYER_FTE__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_register_key_rating
 * DESCRIPTION
 *  register key hdlrs for raing main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_register_key_rating(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    /*clear key events*/
    ClearInputEventHandler(MMI_DEVICE_KEY);

    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_medply_press_FTE_inc_volume_key, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_press_FTE_dec_volume_key, KEY_VOL_DOWN, KEY_EVENT_DOWN);

    SetKeyHandler(mmi_medply_main_screen_close_popup_setting, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_main_screen_close_popup_setting, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_main_screen_close_popup_setting, KEY_ENTER, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_main_screen_close_popup_setting, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_main_screen_close_popup_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_main_screen_close_popup_setting, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_main_screen_close_popup_setting, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_register_key_volume
 * DESCRIPTION
 *  register key hdlrs for volume setting main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_register_key_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    /*clear key events*/
    ClearInputEventHandler(MMI_DEVICE_KEY);

    /* register volume inc, dec handlers */
    SetKeyHandler(mmi_medply_press_FTE_inc_volume_down, KEY_VOL_UP, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_medply_press_FTE_inc_volume_up, KEY_VOL_UP, KEY_EVENT_UP);
	SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_VOL_UP, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_medply_press_FTE_dec_volume_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_medply_press_FTE_dec_volume_up, KEY_VOL_DOWN, KEY_EVENT_UP);
	SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_VOL_DOWN, KEY_EVENT_REPEAT);

    SetKeyHandler(mmi_medply_main_screen_close_popup_setting, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_main_screen_close_popup_setting, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_main_screen_close_popup_setting, KEY_ENTER, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_main_screen_close_popup_setting, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_main_screen_close_popup_setting, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_main_screen_close_popup_setting, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_main_screen_close_popup_setting, KEY_DOWN_ARROW, KEY_EVENT_DOWN);

}

#endif /*__MMI_MEDIA_PLAYER_FTE__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_register_key_full
 * DESCRIPTION
 *  register key hdlrs for full screen main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_register_key_full(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    ClearInputEventHandler(MMI_DEVICE_KEY);

    /*toggle full screen*/
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_1, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_3, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_4, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_5, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_6, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_7, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_8, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_9, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_0, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_POUND, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_ENTER, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_CLEAR, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_STAR, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_CAMERA, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_toggle_full_screen, KEY_SEND, KEY_EVENT_DOWN); 

    /* register volume inc, dec handlers */
#ifdef __MMI_MEDIA_PLAYER_FTE__
    SetKeyHandler(mmi_medply_press_FTE_inc_volume_down, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_press_FTE_inc_volume_up, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_VOL_UP, KEY_EVENT_REPEAT);    
    SetKeyHandler(mmi_medply_press_FTE_dec_volume_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_press_FTE_dec_volume_up, KEY_VOL_DOWN, KEY_EVENT_UP);
    SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
#else
    SetKeyHandler(mmi_medply_press_inc_volume_down, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_press_inc_volume_up, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_VOL_UP, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_medply_press_dec_volume_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_press_dec_volume_up, KEY_VOL_DOWN, KEY_EVENT_UP);
    SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
#endif

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_register_key_normal
 * DESCRIPTION
 *  register key hdlrs for normal main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_register_key_normal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    ClearInputEventHandler(MMI_DEVICE_KEY);

#if defined(__MMI_BACKGROUND_CALL__) && !defined(__RF_DESENSE_TEST__) && !defined(__CS_STREAMING_CONCURRENT_SUPPORT__)
    if(srv_ucm_is_background_call())
    {
        /* register LSK, RSK hanlders */
        SetKeyHandler(mmi_medply_press_rsk_up, KEY_RSK, KEY_EVENT_UP);
        SetKeyHandler(mmi_medply_press_rsk_down, KEY_RSK, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_RSK, KEY_EVENT_REPEAT);
        return;
    }
#endif


    /* register LSK, RSK hanlders */
    SetKeyHandler(mmi_medply_press_lsk_up, KEY_LSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_medply_press_rsk_up, KEY_RSK, KEY_EVENT_UP);
    SetKeyHandler(mmi_medply_press_lsk_down, KEY_LSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_press_rsk_down, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_LSK, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_RSK, KEY_EVENT_REPEAT);

    /* register play / pause, stop, prev, next button handlers */
    SetKeyHandler(mmi_medply_press_prev_button_up, KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(mmi_medply_press_next_button_up, KEY_RIGHT_ARROW, KEY_EVENT_UP);
#if (defined(__MMI_FTE_SUPPORT_SLIM__) || (defined(__MMI_FTE_SUPPORT__))) && !defined(__MMI_MEDIA_PLAYER_FTE__)
   SetKeyHandler(mmi_medply_press_play_button_down, KEY_ENTER, KEY_EVENT_DOWN);
   SetKeyHandler(mmi_medply_press_play_button_up, KEY_ENTER, KEY_EVENT_UP);
   SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_ENTER, KEY_EVENT_REPEAT);
#else
   SetKeyHandler(mmi_medply_press_play_button_up, KEY_UP_ARROW, KEY_EVENT_UP);
   SetKeyHandler(mmi_medply_press_play_button_down, KEY_UP_ARROW, KEY_EVENT_DOWN);
   SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_UP_ARROW, KEY_EVENT_REPEAT);
#endif

#if defined(__MMI_MEDIA_PLAYER_FTE__) && !defined(MMI_MEDPLY_FTE_STOP_SUPPORT_ICON)
    SetKeyHandler(mmi_medply_press_play_button_up, KEY_DOWN_ARROW, KEY_EVENT_UP);
#else
    #if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_MEDIA_PLAYER_FTE__) && defined(__MMI_MAINLCD_320X240__)
    SetKeyHandler(mmi_medply_press_stop_button_up, KEY_UP_ARROW, KEY_EVENT_UP);
    #else
    SetKeyHandler(mmi_medply_press_stop_button_up, KEY_DOWN_ARROW, KEY_EVENT_UP);    
    #endif
#endif

    SetKeyHandler(mmi_medply_press_prev_button_down, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_press_next_button_down, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);


#if defined(__MMI_MEDIA_PLAYER_FTE__) && !defined(MMI_MEDPLY_FTE_STOP_SUPPORT_ICON)
    SetKeyHandler(mmi_medply_press_play_button_down, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
#else
    #if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_MEDIA_PLAYER_FTE__) && defined(__MMI_MAINLCD_320X240__)
    SetKeyHandler(mmi_medply_press_stop_button_down, KEY_UP_ARROW, KEY_EVENT_DOWN);
    #else
    SetKeyHandler(mmi_medply_press_stop_button_down, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    #endif
#endif

    SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_LEFT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_RIGHT_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);

    /*register next / prev button long press handlers*/
    SetKeyHandler(mmi_medply_rewind, KEY_LEFT_ARROW, KEY_EVENT_LONG_PRESS);
    SetKeyHandler(mmi_medply_fast_forward, KEY_RIGHT_ARROW, KEY_EVENT_LONG_PRESS);

    /* register volume inc, dec handlers */
#ifdef __MMI_MEDIA_PLAYER_FTE__
    SetKeyHandler(mmi_medply_press_FTE_inc_volume_key, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_press_FTE_inc_volume_up, KEY_VOL_UP, KEY_EVENT_UP);
    SetKeyHandler(mmi_medply_press_FTE_dec_volume_key, KEY_VOL_DOWN, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_press_FTE_dec_volume_up, KEY_VOL_DOWN, KEY_EVENT_UP);
#else
    SetKeyHandler(mmi_medply_press_inc_volume_down, KEY_VOL_UP, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_medply_press_inc_volume_up, KEY_VOL_UP, KEY_EVENT_UP);
	SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_VOL_UP, KEY_EVENT_REPEAT);
    SetKeyHandler(mmi_medply_press_dec_volume_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);
	SetKeyHandler(mmi_medply_press_dec_volume_up, KEY_VOL_DOWN, KEY_EVENT_UP);
	SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_VOL_DOWN, KEY_EVENT_REPEAT);
#endif

#ifdef __MMI_MEDIA_PLAYER_SNAPSHOT__
    /* register camera key handler*/
    if (!mmi_frm_kbd_is_key_supported(KEY_CAMERA))
    {
        SetKeyHandler(mmi_medply_press_snapshot_down, KEY_0, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_medply_press_snapshot_up, KEY_0, KEY_EVENT_UP);
        SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_0, KEY_EVENT_REPEAT);
    }
    else
    {
        SetKeyHandler(mmi_medply_press_snapshot_down, KEY_CAMERA, KEY_EVENT_DOWN);
        SetKeyHandler(mmi_medply_press_snapshot_up, KEY_CAMERA, KEY_EVENT_UP);
        SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_CAMERA, KEY_EVENT_REPEAT);
    }
#endif

#ifdef __MMI_MEDIA_PLAYER_FTE__
    SetKeyHandler(mmi_medply_full_screen_key_down_hdlr, KEY_ENTER, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_full_screen_key_up_hdlr, KEY_ENTER, KEY_EVENT_UP);
    SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_ENTER, KEY_EVENT_REPEAT);
#elif defined(__MMI_FTE_SUPPORT__)
   #if defined(__MMI_MAINLCD_320X240__)
   SetKeyHandler(mmi_medply_full_screen_key_up_hdlr, KEY_DOWN_ARROW, KEY_EVENT_UP);
   SetKeyHandler(mmi_medply_full_screen_key_down_hdlr, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
   SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
   #else
   SetKeyHandler(mmi_medply_full_screen_key_up_hdlr, KEY_UP_ARROW, KEY_EVENT_UP);
   SetKeyHandler(mmi_medply_full_screen_key_down_hdlr, KEY_UP_ARROW, KEY_EVENT_DOWN);
   SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_UP_ARROW, KEY_EVENT_REPEAT);
   #endif
#else
    SetKeyHandler(mmi_medply_full_screen_key_down_hdlr, KEY_STAR, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_full_screen_key_up_hdlr, KEY_STAR, KEY_EVENT_UP);
    SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_STAR, KEY_EVENT_REPEAT);
#endif

    /* register mute/un-mute */
#ifndef __MMI_MEDIA_PLAYER_FTE__
    SetKeyHandler(mmi_medply_press_mute_down, KEY_POUND, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_medply_press_mute_up, KEY_POUND, KEY_EVENT_UP);
    SetKeyHandler(mmi_medply_dummy_key_hdlr, KEY_POUND, KEY_EVENT_REPEAT);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_back_to_normal_screen
 * DESCRIPTION
 *  handle back to normal screen from other screen (rating/volume/kuro)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_back_to_normal_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    StopTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER);

#ifdef __MMI_TOUCH_SCREEN__
    g_medply.pen_on_object = MMI_MEDPLY_RGN_ID_NULL;
    g_single.pen_on_object = MMI_MEDPLY_RGN_ID_NULL;
#endif

    if(!g_medply.fullscreen)
    {
        mmi_medply_register_key_hdlrs(MMI_MEDPLY_SCREEN_NORMAL);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_register_key_hdlrs
 * DESCRIPTION
 *  register key hdlrs for different main screen cases
 * PARAMETERS
 *  screen_status   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_register_key_hdlrs(mmi_medply_main_screen_status_enum screen_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL single_player = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    single_player = mmi_medply_is_single_player_activated();
    
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_RSG_KEY_HDLR,screen_status);

    if(single_player)
    {
       mmi_medply_single_register_key_hdlrs(screen_status);
       return;
    }

    switch(screen_status)
    {
        case MMI_MEDPLY_SCREEN_NORMAL:
        {
            mmi_medply_register_key_normal();
            break;
        }

        case MMI_MEDPLY_SCREEN_FULL:
        {
            mmi_medply_register_key_full();
            break;
        }

    #ifdef __MMI_MEDIA_PLAYER_FTE__
        case MMI_MEDPLY_SCREEN_VOLUME:
        {
            mmi_medply_register_key_volume();
            break;
        }

        case MMI_MEDPLY_SCREEN_RATING:
        {
            mmi_medply_register_key_rating();
            break;
        }
    #endif /* __MMI_MEDIA_PLAYER_FTE__ */

        default:
        {
            ASSERT(0);
        }

    }

#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) && defined(__MMI_MEDIA_PLAYER_FTE__)
    if(screen_status == MMI_MEDPLY_SCREEN_NORMAL)
    {
        mmi_frm_gesture_rect_struct rect;

        if (mmi_medply_check_gesture_valid(&rect))
        {
            mmi_frm_gesture_listen_event_ex(MMI_FRM_GESTURE_LEFT, mmi_medply_main_screen_gesture_hdl, &rect);
            mmi_frm_gesture_listen_event_ex(MMI_FRM_GESTURE_RIGHT, mmi_medply_main_screen_gesture_hdl, &rect);
        }    
    }
    else
    {
        mmi_frm_gesture_stop_listen_event();
    }
#endif

}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_clear_pen_down
 * DESCRIPTION
 *  to clear all pen down states
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_clear_pen_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 

    switch (g_medply.pen_on_object)
    {
        case MMI_MEDPLY_RGN_ID_LKEY:
        {
            mmi_medply_main_screen_draw_lkey_up();
            break;
        }
            
        case MMI_MEDPLY_RGN_ID_RKEY:
        {
            mmi_medply_main_screen_draw_rkey_up();
            break;
        }

        case MMI_MEDPLY_RGN_ID_DURATION_BAR:
        {
            mmi_medply_main_screen_duration_pen_up(0);

            switch(g_medply.state)
            {
            #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
                case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:
                {
                    /*for progressing case, set both continue flag to false for easy and clear handle style*/
                    if(g_medply.need_to_build_cache)
                    {
                        mdi_audio_stop_build_cache();
                    }
                    if(g_medply.state == MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING)
                    {
                        mmi_medply_set_continue_flag(MMI_FALSE);
                    }
                    else
                    {
                        mmi_medply_set_continue_flag(MMI_TRUE);
                    }
                    mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
                    break;
                }
            #endif
            #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
                case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:            
                {
                    if(g_medply.state == MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING)
                    {
                        mmi_medply_set_continue_flag(MMI_FALSE);
                    }
                    else
                    {
                        mmi_medply_set_continue_flag(MMI_TRUE);
                    }
                    mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_READY);
                    break;
                }
                case MEDPLY_STATE_VIDEO_IDLE_PROGRESSING:
                {
                    mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
                    break;
                }
            #endif
            #ifdef __MMI_MEDIA_PLAYER_STREAM__
                case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:
                {
                    mmi_medply_set_continue_flag(MMI_TRUE);
                    mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_CONNECTED);
                    break;
                }
            #endif
                default:
                {
                    break;
                }
            }
            break;
        }
            
    	case MMI_MEDPLY_RGN_ID_NEXT:
        {
            switch(g_medply.state)
            {
            #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
                case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:
                {
                    mmi_medply_main_screen_duration_seek_done();
                    /*for progressing case, set both continue flag to false for easy and clear handle style*/
                    if(g_medply.need_to_build_cache)
                    {
                        mdi_audio_stop_build_cache();
                    }
                    if(g_medply.state == MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING)
                    {
                        mmi_medply_set_continue_flag(MMI_FALSE);
                    }
                    else
                    {
                        mmi_medply_set_continue_flag(MMI_TRUE);
                    }
                    mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
                    break;
                }
            #endif
            #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
                case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:            
                {
                    mmi_medply_main_screen_duration_seek_done();
                    if(g_medply.state == MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING)
                    {
                        mmi_medply_set_continue_flag(MMI_FALSE);
                    }
                    else
                    {
                        mmi_medply_set_continue_flag(MMI_TRUE);
                    }
                    mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_READY);
                    break;
                }
                case MEDPLY_STATE_VIDEO_IDLE_PROGRESSING:
                {
                    mmi_medply_main_screen_duration_seek_done();
                    mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
                    break;
                }
            #endif
            #ifdef __MMI_MEDIA_PLAYER_STREAM__
                case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:
                {
                    mmi_medply_main_screen_duration_seek_done();
                    mmi_medply_set_continue_flag(MMI_TRUE);
                    mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_CONNECTED);
                    break;
                }
            #endif
                default:
                {
                    break;
                }
            }

            if(g_medply.selected_button == MEDPLY_MAIN_DISABLED)
            {
                return;
            }
            
            g_medply.selected_button_down = MMI_FALSE;
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_NEXT,
                    MMI_MEDPLY_RGN_STATUS_UP);
			break;
        }

	case MMI_MEDPLY_RGN_ID_PREV:
        {
            switch(g_medply.state)
            {
            #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
                case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:
                {
                    mmi_medply_main_screen_duration_seek_done();
                    /*for progressing case, set both continue flag to false for easy and clear handle style*/
                    if(g_medply.need_to_build_cache)
                    {
                        mdi_audio_stop_build_cache();
                    }
                    if(g_medply.state == MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING)
                    {
                        mmi_medply_set_continue_flag(MMI_FALSE);
                    }
                    else
                    {
                        mmi_medply_set_continue_flag(MMI_TRUE);
                    }          
                    mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
                    break;
                }
            #endif
            #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
                case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:            
                {
                    mmi_medply_main_screen_duration_seek_done();
                    if(g_medply.state == MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING)
                    {
                        mmi_medply_set_continue_flag(MMI_FALSE);
                    }
                    else
                    {
                        mmi_medply_set_continue_flag(MMI_TRUE);
                    }   
                    mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_READY);
                    break;
                }
                case MEDPLY_STATE_VIDEO_IDLE_PROGRESSING:
                {
                    mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
                    break;
                }
            #endif
            #ifdef __MMI_MEDIA_PLAYER_STREAM__
                case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:
                {
                    mmi_medply_main_screen_duration_seek_done();
                    mmi_medply_set_continue_flag(MMI_TRUE);
                    mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_CONNECTED);
                    break;
                }
            #endif
                default:
                {
                    break;
                }
            }

            if(g_medply.selected_button == MEDPLY_MAIN_DISABLED)
            {
                return;
            }

            g_medply.selected_button_down = MMI_FALSE;
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_PREV,
                    MMI_MEDPLY_RGN_STATUS_UP);
			break;
        }

    #ifndef __MMI_MEDIA_PLAYER_FTE__
    	case MMI_MEDPLY_RGN_ID_STOP:
        {
            if(g_medply.selected_button == MEDPLY_MAIN_DISABLED)
            {
                return;
            }

            g_medply.selected_button_down = MMI_FALSE;
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_STOP,
                    MMI_MEDPLY_RGN_STATUS_UP);
			break;
        }
    #endif

	case MMI_MEDPLY_RGN_ID_PLAY_PAUSE:
        {
            if(g_medply.selected_button == MEDPLY_MAIN_DISABLED)
            {
                return;
            }

            g_medply.selected_button_down = MMI_FALSE;
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_PLAY_PAUSE,
                    MMI_MEDPLY_RGN_STATUS_UP);
			break;
        }

        case MMI_MEDPLY_RGN_ID_REPEAT:
        {
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_REPEAT,
                    MMI_MEDPLY_RGN_STATUS_UP);
            break;
        }

        case MMI_MEDPLY_RGN_ID_SHUFFLE:
        {
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_SHUFFLE,
                    MMI_MEDPLY_RGN_STATUS_UP);
            break;
        }

    #ifdef __MMI_MEDIA_PLAYER_FTE__
        case MMI_MEDPLY_RGN_ID_VOLUME_BAR:
        {
            break;
        }
    #else
        case MMI_MEDPLY_RGN_ID_VOLUME_INC:
        {
            StopTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER);
            mmi_medply_press_inc_volume_up();
            break;
        }
            
        case MMI_MEDPLY_RGN_ID_VOLUME_DEC:
        {
            StopTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER);
            mmi_medply_press_dec_volume_up();
            break;
        }
    #endif

        case MMI_MEDPLY_RGN_ID_VOLUME_SPEAK:
        {
            g_medply.unaffected_button_down = MMI_MEDPLY_RGN_ID_NULL;
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_SPEAK,
                    MMI_MEDPLY_RGN_STATUS_UP);
            break;
        }

    #if defined(__MMI_MEDIA_PLAYER_SNAPSHOT__) 
        case MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY:
        {
            if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_SNAPSHOT))
            {
                return;
            }

            g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_NULL;
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY,
                    MMI_MEDPLY_RGN_STATUS_UP);
            break;
        }
    #endif /*defined(__MMI_MEDIA_PLAYER_SNAPSHOT__) */

        case MMI_MEDPLY_RGN_ID_ZOOM:
        {
            if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_ZOOM))
            {
                return;
            }

            g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_NULL;
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_ZOOM,
                    MMI_MEDPLY_RGN_STATUS_UP);
            break;
        }

    #ifdef __MMI_MEDIA_PLAYER_FTE__
        case MMI_MEDPLY_RGN_ID_USER_RATING:
        {
            g_medply.media_based_button_down = MMI_MEDPLY_RGN_ID_NULL;
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_USER_RATING,
                MMI_MEDPLY_RGN_STATUS_UP);
            break;
        }
    #endif

        default:
        {
            break;
        }
    }

    StopTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER);
    StopTimer(MEDPLY_TOUCH_LONG_PRESS_TIMER);

    g_medply.pen_on_object = MMI_MEDPLY_RGN_ID_NULL;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_touch_progress_hdlr
 * DESCRIPTION
 *  touch ff/rw hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_touch_progress_hdlr(S16 cor_x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_TOUCH_PROGRESS_HDLR,g_medply.seekable,g_medply.state,cor_x, MMI_FALSE);

    if(!g_medply.seekable || g_medply.state == MEDPLY_STATE_WAIT_NEXT || g_medply.state == MEDPLY_STATE_WAIT_NEXT_SUSPNEDED)
    {
        g_medply.pen_on_object = MMI_MEDPLY_RGN_ID_NULL;
        return;
    }

    switch(g_medply.state)
    {
    /*----audio----*/
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        case MEDPLY_STATE_AUDIO_READY:
        {
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_TOUCH_PROGRESS_AUDIO,g_medply.need_to_build_cache,g_medply.audio_build_cache_process, MMI_FALSE);

            mmi_medply_main_screen_duration_pen_down(cor_x);

            mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING);

            if (g_medply.need_to_build_cache && g_medply.audio_build_cache_process< 100)
            {
                /*send message to med_v to start process*/
                mdi_audio_start_build_cache(g_medply.filefullpath,
                                            g_medply_audio_cache,
                                            MEDPLY_BUILD_CACHE_SIZE,
                                            NULL,//g_medply.audio_cache_file_buf_p,
                                            0,//MEDPLY_BUILD_CACHE_FILE_BUF_SIZE,
                                            NULL,//g_medply.audio_cache_proc_buf_p,
                                            0,//MEDPLY_BUILD_CACHE_PROC_BUF_SIZE,
                                            mmi_medply_build_cache_fail_callback_hdlr,
                                            &g_medply.audio_build_cache_process);
            }
            break;
        }

        case MEDPLY_STATE_AUDIO_PLAY:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
        {
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_TOUCH_PROGRESS_AUDIO,g_medply.need_to_build_cache,g_medply.audio_build_cache_process, MMI_FALSE);

            mmi_medply_main_screen_duration_pen_down(cor_x);

            mmi_medply_audio_seek_stop();
            mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_PLAY_PROGRESSING);
            
            if (g_medply.need_to_build_cache && g_medply.audio_build_cache_process< 100)
            {
                /*send message to med_v to start process*/
                mdi_audio_start_build_cache(g_medply.filefullpath,
                                            g_medply_audio_cache,
                                            MEDPLY_BUILD_CACHE_SIZE,
                                            NULL,//g_medply.audio_cache_file_buf_p,
                                            0,//MEDPLY_BUILD_CACHE_FILE_BUF_SIZE,
                                            NULL,//g_medply.audio_cache_proc_buf_p,
                                            0,//MEDPLY_BUILD_CACHE_PROC_BUF_SIZE,
                                            mmi_medply_build_cache_fail_callback_hdlr,
                                            &g_medply.audio_build_cache_process);
            }
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

    /*----video----*/
    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
        case MEDPLY_STATE_VIDEO_IDLE:
        {
            mmi_medply_main_screen_duration_pen_down(cor_x);            
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE_PROGRESSING);
            break;
        }
    
        case MEDPLY_STATE_VIDEO_READY:
        {
            mmi_medply_main_screen_duration_pen_down(cor_x);            
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING);
            //mmi_medply_main_screen_duration_pen_down(cor_x); 
            break;
        }

        case MEDPLY_STATE_VIDEO_PLAY:
        {
            mmi_medply_main_screen_duration_pen_down(cor_x);

            mdi_video_ply_stop();
        
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
        
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_PLAY_PROGRESSING);
            break;
        }

        case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
        {
            mmi_medply_main_screen_duration_pen_down(cor_x);
            mdi_video_ply_stop_non_block_seek();
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_PLAY_PROGRESSING);

            break;
        }

        case MEDPLY_STATE_VIDEO_PAUSE_SEEKING:
        {
            mmi_medply_main_screen_duration_pen_down(cor_x);
            mdi_video_ply_stop_non_block_seek();
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING);

            break;
        }

    #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

    /*----stream----*/
    #ifdef __MMI_MEDIA_PLAYER_STREAM__    
        case MEDPLY_STATE_STREAM_CONNECTED:
        {
            mmi_medply_main_screen_duration_pen_down(cor_x);            
            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_PLAY_PROGRESSING);
            break;
        }

        case MEDPLY_STATE_STREAM_PLAY:
        {
            mmi_medply_main_screen_duration_pen_down(cor_x);

            mdi_video_stream_stop();
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif


            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_PLAY_PROGRESSING);
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_STREAM__*/

         default:
         {
            break;
         }
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_touch_progress_pen_up
 * DESCRIPTION
 *  handle progress pen up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_touch_progress_pen_up(S16 cor_x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_TOUCH_PROGRESS_UP,g_medply.state, MMI_FALSE);

    switch(g_medply.state)
    {
    /*----audio----*/
#ifdef __MMI_MEDIA_PLAYER_AUDIO__    
        case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:
        {
            if(g_medply.need_to_build_cache)
            {
                mdi_audio_stop_build_cache();
            }
            mmi_medply_main_screen_duration_pen_up(cor_x);
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
            break;
        }

        case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
        {
            if(g_medply.need_to_build_cache)
            {
                mdi_audio_stop_build_cache();
            }
            mmi_medply_main_screen_duration_pen_up(cor_x);            
            mmi_medply_audio_play();
            break;
        }

#endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

    /*----video----*/
#ifdef __MMI_MEDIA_PLAYER_VIDEO__
        case MEDPLY_STATE_VIDEO_IDLE_PROGRESSING:
        {
            mmi_medply_main_screen_duration_pen_up(cor_x);
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
            break;
        }

        case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
        {
            MDI_RESULT result;
            mmi_medply_video_play_para_struct video_layer_info;

            mmi_medply_main_screen_duration_pen_up(cor_x);

            video_layer_info.video_height = g_medply.height;
            video_layer_info.video_width = g_medply.width;
            mmi_medply_main_screen_get_video_parameter(&video_layer_info);

            result = mmi_medply_adption_video_non_block_seek_and_get_frame(
                    g_medply.current_time,
                    video_layer_info.layer_hdl,
                    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                    video_layer_info.layer_subtitle_hdl,
                    #endif
                    mmi_medply_video_seek_callback_hdlr,
                    0);

            if (result < 0)
            {
                mmi_medply_video_close();
                mdi_audio_clear_interrupt_callback();
                mmi_medply_set_pop_up_flag();
                mmi_medply_display_popup(result,MMI_TRUE);
                mmi_medply_play_completed(MMI_TRUE,MMI_FALSE);

                return;
            }

            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_PAUSE_SEEKING);
            
            break;
        }

        case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:
        {
            MDI_RESULT result;
            mmi_medply_video_play_para_struct video_layer_info;

            mmi_medply_main_screen_duration_pen_up(cor_x);

            video_layer_info.video_height = g_medply.height;
            video_layer_info.video_width = g_medply.width;
            mmi_medply_main_screen_get_video_parameter(&video_layer_info);

            result = mmi_medply_adption_video_non_block_seek_and_get_frame(
                    g_medply.current_time,
                    video_layer_info.layer_hdl,
                    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
                    video_layer_info.layer_subtitle_hdl,
                    #endif
                    mmi_medply_video_seek_callback_hdlr,
                    0);

            if (result < 0)
            {
                mmi_medply_video_close();
                mdi_audio_clear_interrupt_callback();
                mmi_medply_set_pop_up_flag();
                mmi_medply_display_popup(result,MMI_TRUE);
                mmi_medply_play_completed(MMI_TRUE,MMI_TRUE);

                return;
            }

            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_PLAY_SEEKING);
            
            break;
        }

#endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

    /*----stream----*/
#ifdef __MMI_MEDIA_PLAYER_STREAM__

        case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:
        {
            mmi_medply_main_screen_duration_pen_up(cor_x);            
            mmi_medply_stream_buffer();
            break;
        }

#endif /*__MMI_MEDIA_PLAYER_STREAM__*/
        default:
        {
            break;
        }

    }

}

#ifdef __MMI_MEDIA_PLAYER_FTE__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_touch_rating_hdlr
 * DESCRIPTION
 *  touch rating hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_touch_rating_hdlr(S16 cor_x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_medply_main_screen_update_rating(cor_x);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_touch_rating_pen_up
 * DESCRIPTION
 *  handle progress pen up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_touch_rating_pen_up(S16 cor_x)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  new_rating;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_rating = mmi_medply_main_screen_update_rating(cor_x);

    mmi_medply_plst_store_rating(new_rating);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_touch_longpressed
 * DESCRIPTION
 *  handle touch long pressed timer time out
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_touch_longpressed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(g_medply.selected_button)
    {
        case MEDPLY_MAIN_PREV:
        {
            mmi_medply_rewind();
            break;
        }

        case MEDPLY_MAIN_NEXT:
        {
            mmi_medply_fast_forward();
            break;
        }

        default:
        {
            break;
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 pen_object = mmi_medply_main_screen_get_pt_rgn(pos);
    S32 icon_id;
    wgui_status_icon_bar_pen_enum evt_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_TOUCH_PEN_DOWN, pen_object, MMI_FALSE);

    if(g_medply.fullscreen)
    {
        gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
        mmi_medply_toggle_full_screen();
        return;
    }

#ifdef __MMI_MEDIA_PLAYER_FTE__
    kal_get_time((kal_uint32*)&g_medply.pen_event_dur);
#endif

#if defined(__MMI_BACKGROUND_CALL__) && !defined(__RF_DESENSE_TEST__) && !defined(__CS_STREAMING_CONCURRENT_SUPPORT__)
    if(srv_ucm_is_background_call())
    {
        switch (pen_object)
        {
            case MMI_MEDPLY_RGN_ID_RKEY:
            {
                break;
            }

            default:
            {
                pen_object = MMI_MEDPLY_RGN_ID_NULL;
            }
        }
    }
#endif

    if (MMI_MEDPLY_RGN_ID_NULL != pen_object)
    {
        gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
    }

    switch (pen_object)
    {
        case MMI_MEDPLY_RGN_ID_LKEY:
        {
            ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
            break;
        }

        case MMI_MEDPLY_RGN_ID_RKEY:
        {
            ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
            break;
        }

        case MMI_MEDPLY_RGN_ID_DURATION_BAR:
        {
            mmi_medply_touch_progress_hdlr(pos.x);
            break;
        }

        case MMI_MEDPLY_RGN_ID_PREV:
        {
            mmi_medply_press_prev_button_down();

            if(g_medply.selected_button == MEDPLY_MAIN_PREV && g_medply.selected_button_down == MMI_TRUE)
            {
                StartTimer(MEDPLY_TOUCH_LONG_PRESS_TIMER, MEDPLY_PEN_LONGPRESSED_MS, mmi_medply_touch_longpressed);
            }

            break;
        }

        case MMI_MEDPLY_RGN_ID_NEXT:
        {
            mmi_medply_press_next_button_down();

            if(g_medply.selected_button == MEDPLY_MAIN_NEXT && g_medply.selected_button_down == MMI_TRUE)
            {
                StartTimer(MEDPLY_TOUCH_LONG_PRESS_TIMER, MEDPLY_PEN_LONGPRESSED_MS, mmi_medply_touch_longpressed);
            }
            break;
        }

        case MMI_MEDPLY_RGN_ID_STOP:
        {
            mmi_medply_press_stop_button_down();
            break;
        }

        case MMI_MEDPLY_RGN_ID_PLAY_PAUSE:
        {
            mmi_medply_press_play_button_down();
            break;
        }

        case MMI_MEDPLY_RGN_ID_REPEAT:
        {
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_REPEAT,
                MMI_MEDPLY_RGN_STATUS_DOWN);
            mmi_medply_main_screen_blt();
            break;
        }

        case MMI_MEDPLY_RGN_ID_SHUFFLE:
        {
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_SHUFFLE,
                MMI_MEDPLY_RGN_STATUS_DOWN);
            mmi_medply_main_screen_blt();            
            break;
        }

    #ifdef __MMI_MEDIA_PLAYER_FTE__
        case MMI_MEDPLY_RGN_ID_VOLUME_BAR:
        {
            g_medply.volume = mmi_medply_main_screen_update_touch_volume(pos.x, 1);

            if(g_medply.state != MEDPLY_STATE_IDLE)
            {
                mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX_MUTE(g_medply.volume));
            }

            if(!g_medply.mute && (MDI_AUD_VOL_EX_MUTE_MIN == g_medply.volume))
            {
                g_medply.mute = MMI_TRUE;
                mmi_medply_main_screen_update_mute();
            }
            else if(g_medply.mute && (MDI_AUD_VOL_EX_MUTE_MIN != g_medply.volume))
            {
                g_medply.mute = MMI_FALSE;
                mmi_medply_main_screen_update_mute();
            }
            mmi_medply_main_screen_blt();
            break;
        }
    #else
        case MMI_MEDPLY_RGN_ID_VOLUME_INC:
        {
            StopTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER);
            mmi_medply_press_inc_volume_down();
            break;
        }

        case MMI_MEDPLY_RGN_ID_VOLUME_DEC:
        {
            StopTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER);
            mmi_medply_press_dec_volume_down();
            break;
        }
    #endif

        case MMI_MEDPLY_RGN_ID_VOLUME_SPEAK:
        {
            mmi_medply_press_mute_down();
            break;
        }

    #if defined(__MMI_MEDIA_PLAYER_SNAPSHOT__) 
        case MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY:
        {
            mmi_medply_press_snapshot_activate_down();
            break;
        }
    #endif


        case MMI_MEDPLY_RGN_ID_ZOOM:
        {
            mmi_medply_full_screen_key_down_hdlr();
            break;
        }

    #ifdef __MMI_MEDIA_PLAYER_FTE__
        case MMI_MEDPLY_RGN_ID_USER_RATING:
        {
            g_medply.media_based_button_down = MMI_MEDPLY_RGN_ID_USER_RATING;

            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_USER_RATING,
                MMI_MEDPLY_RGN_STATUS_DOWN);

            mmi_medply_main_screen_blt();

            break;
        }
        case MMI_MEDPLY_RGN_ID_MODIFY_RATING:
        {
             mmi_medply_touch_rating_hdlr(pos.x);
            break;
        }

        case MMI_MEDPLY_RGN_ID_POPUP:
        {
            break;
        }
    #endif

    #ifdef __MMI_VIDEO_3D_ANAGLYPH__
	    case MMI_MEDPLY_RGN_ID_MODE:
			mmi_medply_press_play_mode_down();
			break;
    #endif
        default:
        {
            if(g_medply.fullscreen)
            {
                mmi_medply_toggle_full_screen();
            }
        #ifdef __MMI_MEDIA_PLAYER_FTE__
            else
            {
                mmi_medply_main_screen_close_popup_setting();
            }
        #endif
        #ifdef __MMI_TOUCH_SCREEN__
            if(!g_medply.fullscreen)
            {
                wgui_status_icon_bar_translate_pen_event(
                    MMI_PEN_EVENT_DOWN,
                    pos.x,
                    pos.y,
                    &icon_id,
                    &evt_type);
            }
        #endif 
            g_medply.pen_on_object = MMI_MEDPLY_RGN_ID_NULL;

            return;
        }
    }

    g_medply.pen_on_object = pen_object;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 pen_object = mmi_medply_main_screen_get_pt_rgn(pos);
    S32 icon_id;
    wgui_status_icon_bar_pen_enum evt_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_TOUCH_PEN_UP, g_medply.pen_on_object, pen_object, MMI_FALSE);

    switch (g_medply.pen_on_object)
    {
        case MMI_MEDPLY_RGN_ID_LKEY:
        {
            if(g_medply.pen_on_object == pen_object)
            {
                ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_UP);
            }
            else
            {
                g_medply.unaffected_button_down = MMI_MEDPLY_RGN_ID_NULL;
                mmi_medply_main_screen_draw_lkey_up();
                mmi_medply_main_screen_blt();
            }

            break;
        }

        case MMI_MEDPLY_RGN_ID_RKEY:
        {
            if(g_medply.pen_on_object == pen_object)
            {
                ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_UP);
            }
            else
            {
                g_medply.unaffected_button_down = MMI_MEDPLY_RGN_ID_NULL;
                mmi_medply_main_screen_draw_rkey_up();
                mmi_medply_main_screen_blt();
            }

            break;
        }

        case MMI_MEDPLY_RGN_ID_DURATION_BAR:
        {
            mmi_medply_touch_progress_pen_up(pos.x);
            break;
        }

        case MMI_MEDPLY_RGN_ID_NEXT:
        {
            StopTimer(MEDPLY_TOUCH_LONG_PRESS_TIMER);

            switch(g_medply.state)
            {
                case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:
                case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
                case MEDPLY_STATE_VIDEO_IDLE_PROGRESSING:
                case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
                case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:
                case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:
                {
                    mmi_medply_press_next_button_up();
                    return;
                }
            }

            if(g_medply.selected_button == MEDPLY_MAIN_DISABLED)
            {
                return;
            }

            if(g_medply.pen_on_object == pen_object)
            {
                mmi_medply_press_next_button_up();
            }
            else
            {
                g_medply.selected_button_down = MMI_FALSE;
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_NEXT,
                        MMI_MEDPLY_RGN_STATUS_UP);
                mmi_medply_main_screen_blt();
            }
            break;
        }

        case MMI_MEDPLY_RGN_ID_PREV:
        {
            StopTimer(MEDPLY_TOUCH_LONG_PRESS_TIMER);

            switch(g_medply.state)
            {
                case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:
                case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
                case MEDPLY_STATE_VIDEO_IDLE_PROGRESSING:
                case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
                case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:
                case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:
                {
                    mmi_medply_press_prev_button_up();
                    return;
                }
            }

            if(g_medply.selected_button == MEDPLY_MAIN_DISABLED)
            {
                return;
            }

            if(g_medply.pen_on_object == pen_object)
            {
                mmi_medply_press_prev_button_up();
            }
            else
            {                
                g_medply.selected_button_down = MMI_FALSE;
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_PREV,
                        MMI_MEDPLY_RGN_STATUS_UP);
                mmi_medply_main_screen_blt();
            }
            break;
        }

        case MMI_MEDPLY_RGN_ID_STOP:
        {
            if(g_medply.selected_button == MEDPLY_MAIN_DISABLED)
            {
                return;
            }

            if(g_medply.pen_on_object == pen_object)
            {
                mmi_medply_press_stop_button_up();
            }
            else
            {
                g_medply.selected_button_down = MMI_FALSE;
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_STOP,
                        MMI_MEDPLY_RGN_STATUS_UP);
                mmi_medply_main_screen_blt();
            }
            break;
        }

        case MMI_MEDPLY_RGN_ID_PLAY_PAUSE:
        {
            if(g_medply.selected_button == MEDPLY_MAIN_DISABLED || mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_PAUSE) || mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_PLAY))
            {
                return;
            }

            if(g_medply.pen_on_object == pen_object)
            {
                mmi_medply_press_play_button_up();
            }
            else
            {
                g_medply.selected_button_down = MMI_FALSE;
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_PLAY_PAUSE,
                        MMI_MEDPLY_RGN_STATUS_UP);
                mmi_medply_main_screen_blt();
            }
            break;
        }

        case MMI_MEDPLY_RGN_ID_REPEAT:
        {
            if(g_medply.pen_on_object == pen_object)
            {
                mmi_medply_settings_toggle_repeat();
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_REPEAT,
                    MMI_MEDPLY_RGN_STATUS_UP);
                mmi_medply_main_screen_blt();                
            }
            else
            {
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_REPEAT,
                        MMI_MEDPLY_RGN_STATUS_UP);
                mmi_medply_main_screen_blt();
            }
            break;
        }

        case MMI_MEDPLY_RGN_ID_SHUFFLE:
        {
            if(g_medply.pen_on_object == pen_object)
            {
                mmi_medply_settings_toggle_shuffle();
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_SHUFFLE,
                    MMI_MEDPLY_RGN_STATUS_UP);
                mmi_medply_main_screen_blt();                
            }
            else
            {
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_SHUFFLE,
                        MMI_MEDPLY_RGN_STATUS_UP);
                mmi_medply_main_screen_blt();
            }
            break;
        }

    #ifdef __MMI_MEDIA_PLAYER_FTE__
        case MMI_MEDPLY_RGN_ID_VOLUME_BAR:
        {
            g_medply.volume = mmi_medply_main_screen_update_touch_volume(pos.x, 0);

            if(!g_medply.mute && (MDI_AUD_VOL_EX_MUTE_MIN == g_medply.volume))
            {
                g_medply.mute = MMI_TRUE;
                mmi_medply_main_screen_update_mute();
            }
            else if(g_medply.mute && (MDI_AUD_VOL_EX_MUTE_MIN != g_medply.volume))
            {
                g_medply.mute = MMI_FALSE;
                mmi_medply_main_screen_update_mute();
            }
            
            mmi_medply_main_screen_blt();

            if(g_medply.state != MEDPLY_STATE_IDLE)
            {
                mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX_MUTE(g_medply.volume));
            }

            break;
        }
    #else
        case MMI_MEDPLY_RGN_ID_VOLUME_INC:
        {
            /* In case region of UP is not same, timer must be stopped */
            //if(g_medply.pen_on_object == pen_object)
            {
                StopTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER);
                mmi_medply_press_inc_volume_up();
            }

            break;
        }

        case MMI_MEDPLY_RGN_ID_VOLUME_DEC:
        {
            /* In case region of UP is not same, timer must be stopped */
            //if(g_medply.pen_on_object == pen_object)
            {
                StopTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER);
                mmi_medply_press_dec_volume_up();
            }
            break;
        }
    #endif

        case MMI_MEDPLY_RGN_ID_VOLUME_SPEAK:
        {
            if (g_medply.pen_on_object == pen_object)
            {
                mmi_medply_press_mute_up();
            }
            else
            {
                g_medply.unaffected_button_down = MMI_MEDPLY_RGN_ID_NULL;
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_SPEAK,
                        MMI_MEDPLY_RGN_STATUS_UP);
                mmi_medply_main_screen_blt();
            }

            break;
        }

    #if defined(__MMI_MEDIA_PLAYER_SNAPSHOT__) 
        case MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY:
        {
            if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_SNAPSHOT))
            {
                return;
            }

            if(g_medply.pen_on_object == pen_object)
            {
                mmi_medply_press_snapshot_activate_up();
            }
            else
            {
                g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_NULL;


                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY,
                        MMI_MEDPLY_RGN_STATUS_UP);
                mmi_medply_main_screen_blt();
            }            

            break;
        }
    #endif /*defined(__MMI_MEDIA_PLAYER_SNAPSHOT__) */

        case MMI_MEDPLY_RGN_ID_ZOOM:
        {
            if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_ZOOM))
            {
                return;
            }
            
            if(g_medply.pen_on_object == pen_object)
            {
                mmi_medply_full_screen_key_up_hdlr();
            }
            else
            {
                g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_NULL;
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_ZOOM,
                        MMI_MEDPLY_RGN_STATUS_UP);
                mmi_medply_main_screen_blt();
            }

            break;
        }

    #ifdef __MMI_MEDIA_PLAYER_FTE__
        case MMI_MEDPLY_RGN_ID_USER_RATING:
        {
            if(g_medply.pen_on_object == pen_object)
            {
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_USER_RATING,
                    MMI_MEDPLY_RGN_STATUS_UP);
                mmi_medply_main_screen_blt();

                if(g_medply.media_based_button_down == MMI_MEDPLY_RGN_ID_USER_RATING)
                {
                    if(mmi_medply_main_screen_show_user_rating())
                    {
                        mmi_medply_register_key_hdlrs(MMI_MEDPLY_SCREEN_RATING);
                    }
                }

                g_medply.media_based_button_down = MMI_MEDPLY_RGN_ID_NULL;
            }
            else
            {
                g_medply.media_based_button_down = MMI_MEDPLY_RGN_ID_NULL;
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_USER_RATING,
                    MMI_MEDPLY_RGN_STATUS_UP);

                mmi_medply_main_screen_blt();
            }

            break;
        }

        case MMI_MEDPLY_RGN_ID_MODIFY_RATING:
        {
            mmi_medply_touch_rating_pen_up(pos.x);
            break;
        }
    #endif

    #ifdef __MMI_VIDEO_3D_ANAGLYPH__
	    case MMI_MEDPLY_RGN_ID_MODE:
			mmi_medply_press_play_mode_up();
			break;
    #endif

        default:
        {
            if(g_medply.fullscreen)
            {
                mmi_medply_toggle_full_screen();
            }
            else
            {
                wgui_status_icon_bar_translate_pen_event(
                    MMI_PEN_EVENT_UP,
                    pos.x,
                    pos.y,
                    &icon_id,
                    &evt_type);
            }
            break;
        }
    }

        g_medply.pen_on_object = MMI_MEDPLY_RGN_ID_NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 pen_object = mmi_medply_main_screen_get_pt_rgn(pos);
    S32 icon_id;
    wgui_status_icon_bar_pen_enum evt_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_TOUCH_PEN_MOVE, g_medply.pen_on_object, pen_object, MMI_FALSE);

/* since gesture will make touch event detection becomes so much more frequently, need to drop some events*/
#ifdef __MMI_MEDIA_PLAYER_FTE__
{
    U32 event_dur;

    kal_get_time((kal_uint32*)&event_dur);
    if(event_dur - g_medply.pen_event_dur < MEDPLY_FTE_PEN_MOVE_MIN_TICKS)
    {
        return;
    }
    g_medply.pen_event_dur = event_dur;
}
#endif

    switch (g_medply.pen_on_object)
    {
        case MMI_MEDPLY_RGN_ID_LKEY:
        {
            if (g_medply.pen_on_object == pen_object)
            {
                mmi_medply_press_lsk_down();
            }
            else
            {
                g_medply.unaffected_button_down = MMI_MEDPLY_RGN_ID_NULL;
                mmi_medply_main_screen_draw_lkey_up();
                mmi_medply_main_screen_blt();
            }
            break;
        }
            
        case MMI_MEDPLY_RGN_ID_RKEY:
        {
            if (g_medply.pen_on_object == pen_object)
            {
                mmi_medply_press_rsk_down();
            }
            else
            {
                g_medply.unaffected_button_down = MMI_MEDPLY_RGN_ID_NULL;
                mmi_medply_main_screen_draw_rkey_up();
                mmi_medply_main_screen_blt();
            }
            break;
        }

        case MMI_MEDPLY_RGN_ID_DURATION_BAR:
        {
            mmi_medply_main_screen_duration_pen_move(pos.x);
            break;
        }
            
	case MMI_MEDPLY_RGN_ID_NEXT:
        {
            switch(g_medply.state)
            {
                case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:
                case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
                case MEDPLY_STATE_VIDEO_IDLE_PROGRESSING:
                case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
                case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:
                case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:
                {
                    if (g_medply.pen_on_object != pen_object)
                    {
                        mmi_medply_press_next_button_up();
                    }
                    return;
                }
            }
            if(g_medply.selected_button == MEDPLY_MAIN_DISABLED)
            {
                return;
            }
            
            if (g_medply.pen_on_object == pen_object)
            {
                if(g_medply.selected_button_down)
                {
                    return;
                }

                mmi_medply_press_next_button_down();
                if(g_medply.selected_button == MEDPLY_MAIN_NEXT && g_medply.selected_button_down == MMI_TRUE)
                {
                    StartTimer(MEDPLY_TOUCH_LONG_PRESS_TIMER, MEDPLY_PEN_LONGPRESSED_MS, mmi_medply_touch_longpressed);
                }
            }
            else
            {
                StopTimer(MEDPLY_TOUCH_LONG_PRESS_TIMER);
                g_medply.selected_button_down = MMI_FALSE;
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_NEXT,
                        MMI_MEDPLY_RGN_STATUS_UP);
                mmi_medply_main_screen_blt();
            }
			break;
        }

	case MMI_MEDPLY_RGN_ID_PREV:
        {
            switch(g_medply.state)
            {
                case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:
                case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
                case MEDPLY_STATE_VIDEO_IDLE_PROGRESSING:
                case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
                case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:
                case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:
                {
                    if (g_medply.pen_on_object != pen_object)
                    {
                        mmi_medply_press_prev_button_up();
                    }
                    return;
                }
            }
            if(g_medply.selected_button == MEDPLY_MAIN_DISABLED)
            {
                return;
            }

            if (g_medply.pen_on_object == pen_object)
            {
                if(g_medply.selected_button_down)
                {
                    return;
                }

                mmi_medply_press_prev_button_down();

                if(g_medply.selected_button == MEDPLY_MAIN_PREV && g_medply.selected_button_down == MMI_TRUE)
                {
                    StartTimer(MEDPLY_TOUCH_LONG_PRESS_TIMER, MEDPLY_PEN_LONGPRESSED_MS, mmi_medply_touch_longpressed);
                }

            }
            else
            {
                StopTimer(MEDPLY_TOUCH_LONG_PRESS_TIMER);
                g_medply.selected_button_down = MMI_FALSE;
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_PREV,
                        MMI_MEDPLY_RGN_STATUS_UP);
                mmi_medply_main_screen_blt();
            }
			break;
        }

        case MMI_MEDPLY_RGN_ID_STOP:
        {
            if(g_medply.selected_button == MEDPLY_MAIN_DISABLED)
            {
                return;
            }

            if (g_medply.pen_on_object == pen_object)
            {
                mmi_medply_press_stop_button_down();
            }
            else
            {
                g_medply.selected_button_down = MMI_FALSE;
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_STOP,
                        MMI_MEDPLY_RGN_STATUS_UP);
                mmi_medply_main_screen_blt();
            }
			break;
        }

	case MMI_MEDPLY_RGN_ID_PLAY_PAUSE:
        {
            if(g_medply.selected_button == MEDPLY_MAIN_DISABLED || mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_PAUSE) || mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_PLAY))
            {
                return;
            }

            if (g_medply.pen_on_object == pen_object)
            {
                mmi_medply_press_play_button_down();
            }else
            {
                g_medply.selected_button_down = MMI_FALSE;
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_PLAY_PAUSE,
                        MMI_MEDPLY_RGN_STATUS_UP);
                mmi_medply_main_screen_blt();
            }
			break;
        }

        case MMI_MEDPLY_RGN_ID_REPEAT:
        {
            if (g_medply.pen_on_object == pen_object)
            {
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_REPEAT,
                        MMI_MEDPLY_RGN_STATUS_DOWN);
                mmi_medply_main_screen_blt();
            }
            else
            {
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_REPEAT,
                        MMI_MEDPLY_RGN_STATUS_UP);
                mmi_medply_main_screen_blt();
            }
            break;
        }

        case MMI_MEDPLY_RGN_ID_SHUFFLE:
        {
            if (g_medply.pen_on_object == pen_object)
            {
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_SHUFFLE,
                        MMI_MEDPLY_RGN_STATUS_DOWN);
                mmi_medply_main_screen_blt();

            }
            else
            {
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_SHUFFLE,
                        MMI_MEDPLY_RGN_STATUS_UP);
                mmi_medply_main_screen_blt();
            }
            break;
        }

    #ifdef __MMI_MEDIA_PLAYER_FTE__
        case MMI_MEDPLY_RGN_ID_VOLUME_BAR:
        {
            g_medply.volume = mmi_medply_main_screen_update_touch_volume(pos.x, 1);

            if(!g_medply.mute && (MDI_AUD_VOL_EX_MUTE_MIN == g_medply.volume))
            {
                g_medply.mute = MMI_TRUE;
                mmi_medply_main_screen_update_mute();
            }
            else if(g_medply.mute && (MDI_AUD_VOL_EX_MUTE_MIN != g_medply.volume))
            {
                g_medply.mute = MMI_FALSE;
                mmi_medply_main_screen_update_mute();
            }

            mmi_medply_main_screen_blt();

            if(g_medply.state != MEDPLY_STATE_IDLE)
            {
                mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX_MUTE(g_medply.volume));
            }

            break;
        }
    #else
        case MMI_MEDPLY_RGN_ID_VOLUME_INC:
        {
            if (g_medply.pen_on_object == pen_object)
            {
                StopTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER);
                mmi_medply_press_inc_volume_down();
            }
            else
            {
                StopTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER);
                mmi_medply_press_inc_volume_up();
            }
            break;
        }
            
        case MMI_MEDPLY_RGN_ID_VOLUME_DEC:
        {
            if (g_medply.pen_on_object == pen_object)
            {
                StopTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER);
                mmi_medply_press_dec_volume_down();
            }
            else
            {
                StopTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER);            
                mmi_medply_press_dec_volume_up();
            }
            break;
        }
    #endif

        case MMI_MEDPLY_RGN_ID_VOLUME_SPEAK:
        {
            if (g_medply.pen_on_object == pen_object)
            {
                mmi_medply_press_mute_down();
            }
            else
            {
                g_medply.unaffected_button_down = MMI_MEDPLY_RGN_ID_NULL;
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_SPEAK,
                        MMI_MEDPLY_RGN_STATUS_UP);
                mmi_medply_main_screen_blt();
            }
            break;
        }

    #if defined(__MMI_MEDIA_PLAYER_SNAPSHOT__) 
        case MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY:
        {
            if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_SNAPSHOT))
            {
                return;
            }

            if(g_medply.pen_on_object == pen_object)
            {
                mmi_medply_press_snapshot_activate_down();
            }
            else
            {
                g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_NULL;


                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY,
                        MMI_MEDPLY_RGN_STATUS_UP);
                mmi_medply_main_screen_blt();
            }            
            break;
        }
    #endif /*defined(__MMI_MEDIA_PLAYER_SNAPSHOT__) */

        case MMI_MEDPLY_RGN_ID_ZOOM:
        {
            if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_ZOOM))
            {
                return;
            }

            if(g_medply.pen_on_object == pen_object)
            {
                mmi_medply_press_full_screen_down();
            }
            else
            {
                g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_NULL;
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_ZOOM,
                        MMI_MEDPLY_RGN_STATUS_UP);
                mmi_medply_main_screen_blt();
            }
            break;
        }

    #ifdef __MMI_MEDIA_PLAYER_FTE__
        case MMI_MEDPLY_RGN_ID_USER_RATING:
        {
            if(g_medply.pen_on_object == pen_object)
            {            
                g_medply.media_based_button_down = MMI_MEDPLY_RGN_ID_USER_RATING;
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_USER_RATING,
                    MMI_MEDPLY_RGN_STATUS_DOWN);

                mmi_medply_main_screen_blt();
            }
            else
            {
                g_medply.media_based_button_down = MMI_MEDPLY_RGN_ID_NULL;
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_USER_RATING,
                    MMI_MEDPLY_RGN_STATUS_UP);

                mmi_medply_main_screen_blt();
            }
            break;
        }

        case MMI_MEDPLY_RGN_ID_MODIFY_RATING:
        {
            mmi_medply_main_screen_update_rating(pos.x);
            break;
        }
    #endif

    #ifdef __MMI_VIDEO_3D_ANAGLYPH__
	case MMI_MEDPLY_RGN_ID_MODE:
        {
            if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_PLAY_MODE))
            {
                return;
            }

            if (g_medply.pen_on_object == pen_object)
            {
                mmi_medply_press_play_mode_down();
            }
            else
            {
                g_medply.selected_button_down = MMI_FALSE;
                g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_NULL;
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_MODE,
                    MMI_MEDPLY_RGN_STATUS_UP);

                mmi_medply_main_screen_blt();
            }
			break;
        }
    #endif

        default:
        {
            if(!g_medply.fullscreen)
            {
                wgui_status_icon_bar_translate_pen_event(
                    MMI_PEN_EVENT_MOVE,
                    pos.x,
                    pos.y,
                    &icon_id,
                    &evt_type);
            }
            
            break;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_pen_abort_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_pen_abort_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 icon_id;
    wgui_status_icon_bar_pen_enum evt_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_TOUCH_PEN_ABORT,g_medply.pen_on_object, MMI_FALSE);

    StopTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER);

    switch (g_medply.pen_on_object)
    {
        case MMI_MEDPLY_RGN_ID_LKEY:
        {
            g_medply.unaffected_button_down = MMI_MEDPLY_RGN_ID_NULL;
            mmi_medply_main_screen_draw_lkey_up();
            mmi_medply_main_screen_blt();
            break;
        }
            
        case MMI_MEDPLY_RGN_ID_RKEY:
        {
            g_medply.unaffected_button_down = MMI_MEDPLY_RGN_ID_NULL;
            mmi_medply_main_screen_draw_rkey_up();
            mmi_medply_main_screen_blt();
            break;
        }

        case MMI_MEDPLY_RGN_ID_DURATION_BAR:
        {
            mmi_medply_main_screen_duration_pen_up(pos.x);
            switch(g_medply.state)
            {
            #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
                case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:
                {
                    /*for progressing case, set both continue flag to false for easy and clear handle style*/
                    if(g_medply.need_to_build_cache)
                    {
                        mdi_audio_stop_build_cache();
                    }
                    mmi_medply_set_continue_flag(MMI_FALSE);            
                    mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
                    break;
                }
            #endif
            #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
                case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:            
                {
                    mmi_medply_set_continue_flag(MMI_FALSE);
                    mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_READY);
                    break;
                }
                case MEDPLY_STATE_VIDEO_IDLE_PROGRESSING:
                {
                    mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
                    break;
                }
            #endif
            #ifdef __MMI_MEDIA_PLAYER_STREAM__
                case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:
                {
                    mmi_medply_set_continue_flag(MMI_FALSE);
                    mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_CONNECTED);
                    break;
                }
            #endif
                default:
                {
                    break;
                }
            }
            break;
        }
            
    	case MMI_MEDPLY_RGN_ID_NEXT:
        {
            switch(g_medply.state)
            {
            #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
                case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:
                {
                    mmi_medply_main_screen_duration_seek_done();
                    /*for progressing case, set both continue flag to false for easy and clear handle style*/
                    if(g_medply.need_to_build_cache)
                    {
                        mdi_audio_stop_build_cache();
                    }
                    mmi_medply_set_continue_flag(MMI_FALSE);            
                    mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
                    break;
                }
            #endif
            #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
                case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:            
                {
                    mmi_medply_main_screen_duration_seek_done();
                    mmi_medply_set_continue_flag(MMI_FALSE);
                    mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_READY);
                    break;
                }
                case MEDPLY_STATE_VIDEO_IDLE_PROGRESSING:
                {
                    mmi_medply_main_screen_duration_seek_done();
                    mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
                    break;
                }
            #endif
            #ifdef __MMI_MEDIA_PLAYER_STREAM__
                case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:
                {
                    mmi_medply_main_screen_duration_seek_done();
                    mmi_medply_set_continue_flag(MMI_FALSE);
                    mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_CONNECTED);
                    break;
                }
            #endif
                default:
                {
                    break;
                }
            }

            if(g_medply.selected_button == MEDPLY_MAIN_DISABLED)
            {
                return;
            }
            
            g_medply.selected_button_down = MMI_FALSE;
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_NEXT,
                    MMI_MEDPLY_RGN_STATUS_UP);
            mmi_medply_main_screen_blt();
			break;
        }

	case MMI_MEDPLY_RGN_ID_PREV:
        {
            switch(g_medply.state)
            {
            #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
                case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:
                {
                    mmi_medply_main_screen_duration_seek_done();
                    /*for progressing case, set both continue flag to false for easy and clear handle style*/
                    if(g_medply.need_to_build_cache)
                    {
                        mdi_audio_stop_build_cache();
                    }
                    mmi_medply_set_continue_flag(MMI_FALSE);            
                    mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
                    break;
                }
            #endif
            #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
                case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:            
                {
                    mmi_medply_main_screen_duration_seek_done();
                    mmi_medply_set_continue_flag(MMI_FALSE);
                    mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_READY);
                    break;
                }
                case MEDPLY_STATE_VIDEO_IDLE_PROGRESSING:
                {
                    mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
                    break;
                }
            #endif
            #ifdef __MMI_MEDIA_PLAYER_STREAM__
                case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:
                {
                    mmi_medply_main_screen_duration_seek_done();
                    mmi_medply_set_continue_flag(MMI_FALSE);
                    mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_CONNECTED);
                    break;
                }
            #endif
                default:
                {
                    break;
                }
            }

            if(g_medply.selected_button == MEDPLY_MAIN_DISABLED)
            {
                return;
            }

            g_medply.selected_button_down = MMI_FALSE;
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_PREV,
                    MMI_MEDPLY_RGN_STATUS_UP);
            mmi_medply_main_screen_blt();
			break;
        }

    #ifndef __MMI_MEDIA_PLAYER_FTE__
    	case MMI_MEDPLY_RGN_ID_STOP:
        {
            if(g_medply.selected_button == MEDPLY_MAIN_DISABLED)
            {
                return;
            }

            g_medply.selected_button_down = MMI_FALSE;
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_STOP,
                    MMI_MEDPLY_RGN_STATUS_UP);
            mmi_medply_main_screen_blt();
			break;
        }
    #endif

	case MMI_MEDPLY_RGN_ID_PLAY_PAUSE:
        {
            if(g_medply.selected_button == MEDPLY_MAIN_DISABLED)
            {
                return;
            }

            g_medply.selected_button_down = MMI_FALSE;
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_PLAY_PAUSE,
                    MMI_MEDPLY_RGN_STATUS_UP);
            mmi_medply_main_screen_blt();
			break;
        }

        case MMI_MEDPLY_RGN_ID_REPEAT:
        {
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_REPEAT,
                    MMI_MEDPLY_RGN_STATUS_UP);
            mmi_medply_main_screen_blt();
            break;
        }

        case MMI_MEDPLY_RGN_ID_SHUFFLE:
        {
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_SHUFFLE,
                    MMI_MEDPLY_RGN_STATUS_UP);
            mmi_medply_main_screen_blt();
            break;
        }

    #ifdef __MMI_MEDIA_PLAYER_FTE__
        case MMI_MEDPLY_RGN_ID_VOLUME_BAR:
        {
            g_medply.volume = mmi_medply_main_screen_update_touch_volume(pos.x, 0);

            if(g_medply.state != MEDPLY_STATE_IDLE)
            {
                mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX_MUTE(g_medply.volume));
            }

            break;
        }
    #else
        case MMI_MEDPLY_RGN_ID_VOLUME_INC:
        {
            StopTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER);
            mmi_medply_press_inc_volume_up();
            break;
        }
            
        case MMI_MEDPLY_RGN_ID_VOLUME_DEC:
        {
            StopTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER);
            mmi_medply_press_dec_volume_up();
            break;
        }
    #endif

        case MMI_MEDPLY_RGN_ID_VOLUME_SPEAK:
        {
            g_medply.unaffected_button_down = MMI_MEDPLY_RGN_ID_NULL;
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_SPEAK,
                    MMI_MEDPLY_RGN_STATUS_UP);
            mmi_medply_main_screen_blt();
            break;
        }

    #if defined(__MMI_MEDIA_PLAYER_SNAPSHOT__)
        case MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY:
        {
            if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_SNAPSHOT))
            {
                return;
            }

            g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_NULL;
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY,
                    MMI_MEDPLY_RGN_STATUS_UP);
            mmi_medply_main_screen_blt();
            break;
        }
    #endif /*defined(__MMI_MEDIA_PLAYER_SNAPSHOT__)*/

        case MMI_MEDPLY_RGN_ID_ZOOM:
        {
            if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_ZOOM))
            {
                return;
            }

            g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_NULL;
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_ZOOM,
                    MMI_MEDPLY_RGN_STATUS_UP);
            mmi_medply_main_screen_blt();
            break;
        }

    #ifdef __MMI_MEDIA_PLAYER_FTE__
        case MMI_MEDPLY_RGN_ID_USER_RATING:
        {
            g_medply.media_based_button_down = MMI_MEDPLY_RGN_ID_NULL;
            mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_USER_RATING,
                MMI_MEDPLY_RGN_STATUS_UP);
            mmi_medply_main_screen_blt();

            break;
        }
    #endif

        default:
        {
            if(!g_medply.fullscreen)
            {
                wgui_status_icon_bar_translate_pen_event(
                    MMI_PEN_EVENT_ABORT,
                    pos.x,
                    pos.y,
                    &icon_id,
                    &evt_type);
            }
            break;
        }
    }

    StopTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER);
    StopTimer(MEDPLY_TOUCH_LONG_PRESS_TIMER);

    g_medply.pen_on_object = MMI_MEDPLY_RGN_ID_NULL;
    g_medply.selected_button_down = MMI_FALSE;
    g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_NULL;
    g_medply.unaffected_button_down = MMI_MEDPLY_RGN_ID_NULL;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_pen_long_tab_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_pen_long_tap_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 pen_object = mmi_medply_main_screen_get_pt_rgn(pos);
    S32 icon_id;
    wgui_status_icon_bar_pen_enum evt_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_TOUCH_PEN_LONG_TAB,g_medply.pen_on_object, MMI_FALSE);

    if ((MMI_MEDPLY_RGN_ID_NEXT == g_medply.pen_on_object) ||
        (MMI_MEDPLY_RGN_ID_PREV == g_medply.pen_on_object))
    {
        gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_HOLD);
    }

    switch (g_medply.pen_on_object)
    {
        case MMI_MEDPLY_RGN_ID_NEXT:
        {
            if(g_medply.pen_on_object == pen_object)
            {
                StopTimer(MEDPLY_TOUCH_LONG_PRESS_TIMER);
                mmi_medply_fast_forward();
            }
            break;
        }

        case MMI_MEDPLY_RGN_ID_PREV:
        {
            if(g_medply.pen_on_object == pen_object)
            {
                StopTimer(MEDPLY_TOUCH_LONG_PRESS_TIMER);
                mmi_medply_rewind();
            }
            break;
        }

        default:
        {
            if(!g_medply.fullscreen)
            {
                wgui_status_icon_bar_translate_pen_event(
                    MMI_PEN_EVENT_LONG_TAP,
                    pos.x,
                    pos.y,
                    &icon_id,
                    &evt_type);
            }
            break;
        }
    }
    

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_pen_repeat_hdlr
 * DESCRIPTION
 *  add a dummy repeat hdlr to avoid keep receiving pen down event
 * PARAMETERS
 *  pos     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_pen_repeat_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return;
}

#endif /*__MMI_TOUCH_SCREEN__*/

#ifdef __MMI_AVRCP_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bt_avrcp_cmd_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  command         [IN]        
 *  key_press       [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_medply_bt_avrcp_cmd_hdlr(U8 command, mmi_avrcp_key_events key_events)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = MMI_AVRCP_CR_ACCEPT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_AVRCP_CMD,g_medply.state,command,key_events);

#ifdef __USB_IN_NORMAL_MODE__
    /* check is in mass storage mode */
    if (srv_usb_is_in_mass_storage_mode())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MASS_STORAGE_MODE);
        /* phone drive is exported, cant use this app, popup message in key up */
        if(key_events == MMI_AVRCP_KEY_UP)
        {
            MMI_STR_ID string_id = 0;
            mmi_event_notify_enum event_type = MMI_EVENT_DEFAULT;
            string_id = mmi_usb_get_error_info(SRV_USB_ERROR_UNAVAILABLE, &event_type);
            mmi_medply_display_popup_with_sg((U16)string_id, event_type);
        }
        result = MMI_AVRCP_CR_REJECT;
        goto avrcp_finish;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

#ifdef __DM_LAWMO_SUPPORT__
    if(mmi_dmui_get_status(MMI_DMUI_MO_TYPE_LAWMO_LOCK) == MMI_DMUI_STATUS_LAWMO_LOCK_PARTIALLYLOCK || mmi_dmui_get_status(MMI_DMUI_MO_TYPE_LAWMO_LOCK) == MMI_DMUI_STATUS_LAWMO_LOCK_ON_LOCKING)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_LAWMO_LOCK);
        result = MMI_AVRCP_CR_REJECT;
        goto avrcp_finish;
    }
#endif

    switch(g_medply.state)
    {
        case MEDPLY_STATE_IDLE:
        case MEDPLY_STATE_AUDIO_INTERRUPTED:
        case MEDPLY_STATE_VIDEO_INTERRUPTED:
        case MEDPLY_STATE_STREAM_INTERRUPTED:
        {
            /*do not accept AVRCP command when interrupted*/
            result = MMI_AVRCP_CR_REJECT;
            goto avrcp_finish;
        }

        default:
        {
            MMI_BOOL bg_suspend = MMI_FALSE;
            S32 order = -1;
            U8 empty = 0;

            MMI_BOOL bg_play;

            bg_suspend = mdi_audio_is_background_play_suspended();
            order = mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_MEDPLY);
            empty = mdi_audio_get_background_callback_register_app_num();

            mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_BG_PLAY,(void*)&bg_play);

            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_TRC_MEDPLY_FOUR_VALS,bg_suspend,order,empty,bg_play);

            if (bg_suspend || (order != 0 && empty != 0))
            {
                result = MMI_AVRCP_CR_REJECT;
                goto avrcp_finish;
            }
            else if(!g_medply.in_media_player && !bg_play)
            {
                result = MMI_AVRCP_CR_REJECT;
                goto avrcp_finish;
            }
            else if(g_medply.fullscreen)
            {
                switch (command)
                {
                    case MMI_AVRCP_POP_PLAY:
                    case MMI_AVRCP_POP_STOP:
                    case MMI_AVRCP_POP_PAUSE:
                    case MMI_AVRCP_POP_FORWARD:
                    case MMI_AVRCP_POP_BACKWARD:
                    case MMI_AVRCP_POP_FAST_FORWARD:
                    case MMI_AVRCP_POP_REWIND:
                    {
                        result = MMI_AVRCP_CR_REJECT;
                        mmi_medply_toggle_full_screen();
                        goto avrcp_finish;
                    }
                    default :
                        break;
                }
                break;
            }
            else
            {
                break;
            }
        }
    }

    if (key_events == MMI_AVRCP_KEY_CANCELED)
    {
        switch (command)
        {
            case MMI_AVRCP_POP_PLAY:
            case MMI_AVRCP_POP_STOP:
            case MMI_AVRCP_POP_PAUSE:
            case MMI_AVRCP_POP_FORWARD:
            case MMI_AVRCP_POP_BACKWARD:
            case MMI_AVRCP_POP_FAST_FORWARD:
            case MMI_AVRCP_POP_REWIND:
                mmi_medply_press_button_canceled();
                break;
            default :
                break;
        }
        /*the return value do not mean anything in key canceled event*/
        result = MMI_AVRCP_CR_REJECT;
        goto avrcp_finish;
    }

    switch (command)
    {
        case MMI_AVRCP_POP_PLAY:
        {
            if (key_events == MMI_AVRCP_KEY_UP)
            {
                mmi_medply_background_prepare();
                mmi_medply_press_play_button_up();
            }
            else if(key_events == MMI_AVRCP_KEY_DOWN)
            {
                mmi_medply_press_play_button_down();
            }
            break;
        }

        case MMI_AVRCP_POP_STOP:
        {
            if (key_events == MMI_AVRCP_KEY_UP)
            {
                mmi_medply_press_stop_button_up();
            }
            else if(key_events == MMI_AVRCP_KEY_DOWN)
            {
                mmi_medply_press_stop_button_down();
            }
            break;
        }

        case MMI_AVRCP_POP_PAUSE:
        {
            if (key_events == MMI_AVRCP_KEY_UP)
            {
                mmi_medply_background_prepare();
                mmi_medply_press_play_button_up();
            }
            else if(key_events == MMI_AVRCP_KEY_DOWN)
            {
                mmi_medply_press_play_button_down();
            }
            break;
        }

        case MMI_AVRCP_POP_FORWARD:
        case MMI_AVRCP_POP_FAST_FORWARD:

            if (key_events == MMI_AVRCP_KEY_UP)
            {
                mmi_medply_press_next_button_up();
            }
            else if (key_events == MMI_AVRCP_KEY_DOWN)
            {
                mmi_medply_press_next_button_down();
            }            
            else if(key_events == MMI_AVRCP_KEY_LONGPRESS)
            {
                if(GetActiveScreenId() == SCR_ID_MEDPLY_MAIN_SCREEN )
                {
                    mmi_medply_fast_forward();
                }
                else
                {
                    result = MMI_AVRCP_CR_REJECT;
                }
            }
            else
            {
                result = MMI_AVRCP_CR_REJECT;
            }
            break;

        case MMI_AVRCP_POP_BACKWARD:
        case MMI_AVRCP_POP_REWIND:
            if (key_events == MMI_AVRCP_KEY_UP)
            {
                mmi_medply_press_prev_button_up();
            }
            else if(key_events == MMI_AVRCP_KEY_DOWN)
            {
                mmi_medply_press_prev_button_down();
            }
            else if(key_events == MMI_AVRCP_KEY_LONGPRESS)
            {
                if(GetActiveScreenId() == SCR_ID_MEDPLY_MAIN_SCREEN )
                {
                    mmi_medply_rewind();
                }
                else
                {
                    result = MMI_AVRCP_CR_REJECT;
                }
            }
            else
            {
                result = MMI_AVRCP_CR_REJECT;
            }
            break;

        default:
            result = MMI_AVRCP_CR_NOT_IMPLEMENT;
            break;
    }


avrcp_finish:
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_AVRCP_RETURN,result);
    return result;

    
}
#endif /* __MMI_AVRCP_SUPPORT__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_clear_key_down
 * DESCRIPTION
 *  to clear all key down states
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_clear_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_medply.affected_button_down != MMI_MEDPLY_RGN_ID_NULL)
    {
        switch(g_medply.affected_button_down)
        {
            case MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY:
            {
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_SNAPSHOT_ACTKEY,
                    MMI_MEDPLY_RGN_STATUS_UP);
                break;
            }

            case MMI_MEDPLY_RGN_ID_ZOOM:
            {
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_ZOOM,
                    MMI_MEDPLY_RGN_STATUS_UP);
                break;
            }

            default:
            {
                break;
            }
        }
        g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_NULL;
    }

    if(g_medply.unaffected_button_down != MMI_MEDPLY_RGN_ID_NULL)
    {
        switch(g_medply.unaffected_button_down)
        {
            case MMI_MEDPLY_RGN_ID_LKEY:
            {
                mmi_medply_main_screen_draw_lkey_up();
                break;
            }

            case MMI_MEDPLY_RGN_ID_RKEY:
            {
                mmi_medply_main_screen_draw_rkey_up();
                break;
            }

            case MMI_MEDPLY_RGN_ID_VOLUME_SPEAK:
            {
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_VOLUME_SPEAK,
                    MMI_MEDPLY_RGN_STATUS_UP);
                break;
            }

            default:
            {
                break;
            }
        }

        g_medply.unaffected_button_down = MMI_MEDPLY_RGN_ID_NULL;
    }

    mmi_medply_release_media_based_key();

    if(g_medply.selected_button_down)
    {
        switch(g_medply.selected_button)
        {
            case MEDPLY_MAIN_PLAY:
            {
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_PLAY_PAUSE,
                    MMI_MEDPLY_RGN_STATUS_UP);   
                break;
            }

        #ifndef __MMI_MEDIA_PLAYER_FTE__
            case MEDPLY_MAIN_STOP:
            {
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_STOP,
                    MMI_MEDPLY_RGN_STATUS_UP);
                break;
            }
        #endif

            case MEDPLY_MAIN_PREV:
            {
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_PREV,
                    MMI_MEDPLY_RGN_STATUS_UP);
                break;
            }

            case MEDPLY_MAIN_NEXT:
            {
                mmi_medply_main_screen_set_and_draw_button(MMI_MEDPLY_RGN_ID_NEXT,
                    MMI_MEDPLY_RGN_STATUS_UP);
                break;
            }

            default:
            {
                break;
            }
        }

        g_medply.selected_button_down = MMI_FALSE;
    }

}

#ifdef MOTION_SENSOR_SUPPORT
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
        #ifndef __MMI_MEDIA_PLAYER_FTE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif //0
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_motion_tilt_hdlr
 * DESCRIPTION
 *  tilt motin handler
 * PARAMETERS
 *  dirsct  [IN]
 *  action  [IN]
 *  detail  [IN]
 *  user data [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_motion_tilt_hdlr(srv_sensor_type_enum sensor_type, 
               void *sensor_data, void *user_data)
/*
(mdi_motion_angle_enum direction,
 mdi_motion_action_enum action,
  mdi_motion_tilt_detail_struct *detail,
  void *user_data)*/
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL switch_by_motion ;
    srv_sensor_motion_direct_struct *p_direct;
    srv_sensor_motion_direct_enum direction;
    srv_sensor_motion_action_enum action;
    U32 curr_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*MAUI_03010605*/
    kal_get_time((kal_uint32*)&curr_time);
    if(curr_time - g_medply.motion_reg_time < MMI_MEDPLY_MOTION_AVAILABLE_TIME)
    {
        return;
    }

    p_direct = (srv_sensor_motion_direct_struct *)sensor_data;
    direction = p_direct->direct;
    action = p_direct->action;

    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_MOTIONSENSOR, (void*)&switch_by_motion);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_MOTION_TILT, direction, p_direct->action, switch_by_motion, g_medply.fullscreen);

    if(mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_ZOOM) || !switch_by_motion || action == SRV_SENSOR_MOTION_ACTION_NULL)
    {
        return;
    }


    switch(direction)
    {
        case SRV_SENSOR_MOTION_ANGLE_GX180:
        {
            /*horizontal*/
            if(!g_medply.fullscreen)
            {
                mmi_medply_clear_key_down();
            #ifdef __MMI_TOUCH_SCREEN__
                mmi_medply_clear_pen_down();
            #endif
                mmi_medply_toggle_full_screen();
            }
            break;
        }

        case SRV_SENSOR_MOTION_ANGLE_GY180:
        {
            /*vertical*/
            if(g_medply.fullscreen)
            {
                mmi_medply_toggle_full_screen();
            }
            break;
        }

        default:
        {
            break;
        }
    }


}
#endif /*MOTION_SENSOR_SUPPORT*/

#define WIDGET_PLAYER
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_widget_is_plst_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_widget_is_plst_ready()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_WIDGET_IS_PLST_READY, g_medply.state != MEDPLY_STATE_IDLE);

    return (g_medply.state != MEDPLY_STATE_IDLE) ? MMI_TRUE : MMI_FALSE;
}


MMI_BOOL mmi_medply_widget_is_audio_file()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    filetypes_group_type_enum   file_grp;
    filetypes_file_type_enum    file_type;
    WCHAR *ext_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    ext_ptr = srv_fmgr_path_get_extension_ptr((WCHAR*)g_medply.filefullpath);
    file_type = (filetypes_file_type_enum)srv_fmgr_types_find_type_by_extension_str((WCHAR*)ext_ptr);
    file_grp = srv_fmgr_types_find_group_by_type(file_type);

    if (file_grp == FMGR_GROUP_VIDEO 
#ifdef __MMI_VIDEO_STREAM__
        || file_grp == FMGR_GROUP_STREAM)
#else
        )
#endif
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }  
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_widget_transform_current_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_medply_widget_state_enum
 *****************************************************************************/
mmi_medply_widget_state_enum mmi_medply_widget_transform_current_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(g_medply.state)
    {
        case MEDPLY_STATE_IDLE:
        case MEDPLY_STATE_WAIT_NEXT_SUSPNEDED:
        case MEDPLY_STATE_AUDIO_INTERRUPTED:
        case MEDPLY_STATE_VIDEO_INTERRUPTED:
        case MEDPLY_STATE_STREAM_IDLE:
        case MEDPLY_STATE_STREAM_INITED:
        case MEDPLY_STATE_STREAM_INTERRUPTED:	
        {
            return MEDPLY_WIDGET_STATE_IDLE;
        }

        case MEDPLY_STATE_WAIT_NEXT:
        case MEDPLY_STATE_AUDIO_READY:
        case MEDPLY_STATE_PURE_AUDIO_READY:
        case MEDPLY_STATE_STREAM_CONNECTED:
        {
            if(g_medply.continue_to_play)
            {
                return MEDPLY_WIDGET_STATE_PROCESSING;
            }
            else
            {
                return MEDPLY_WIDGET_STATE_IDLE;
            }
        }

        case MEDPLY_STATE_AUDIO_PLAY:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
        case MEDPLY_STATE_PURE_AUDIO_PLAY:
        case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
        {

            return MEDPLY_WIDGET_STATE_PLAY;
        }

        case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:
        case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
        case MEDPLY_STATE_AUDIO_BT_CONNECTING:
        case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
        case MEDPLY_STATE_STREAM_CONNECTING:
        case MEDPLY_STATE_STREAM_BUFFERING:
        case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:
        case MEDPLY_STATE_STREAM_BT_CONNECTING:
        {
            return MEDPLY_WIDGET_STATE_PROCESSING;
        }
        
        default:
        {
            return MEDPLY_WIDGET_STATE_IDLE;
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_widget_get_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_widget_get_value(mmi_widget_player_get_value_enum enum_value, void* data_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(enum_value)
    {
        case MMI_WIDGET_PLAYER_TOTAL_DURATION:
        {
            U64* total_dur;
            total_dur = (U64*)data_value;
            *total_dur = g_medply.duration;
            break;
        }

        case MMI_WIDGET_PLAYER_FILENAME:
        {
            U8** filename_p ;
            CHAR* dot = NULL;
            UI_character_type filename[MEDPLY_MAX_FILE_LEN];
            /* try to cut off filename as title. */
            mmi_medply_util_extract_filename(filename, g_medply.filefullpath);
            /* cut off extended name. */
            dot = mmi_ucs2rchr((const CHAR*)filename, (U16)L'.');
            if (dot != NULL)	/* all supported media file should has an extended name! */
            {
                *(dot + 1) = 0;
                *dot = 0;
            }

            filename_p = (U8**) data_value;
            mmi_ucs2cpy((CHAR*)filename_p , (CHAR*)filename);
   
            break;
        }

        case MMI_WIDGET_PLAYER_CUR_TIME:
        {
            U64* cur_time;
            cur_time = (U64*)data_value;
            *cur_time = g_medply.current_time;
            break;
        }

        case MMI_WIDGET_PLAYER_CUR_STATE:
        {
            U8* state;
            state = (U8*) data_value;
            *state = (U8)mmi_medply_widget_transform_current_state();
            break;
        }

        case MMI_WIDGET_PLAYER_IS_PAUSE_DISABLED:
        {
            MMI_BOOL* is_disabled;
            is_disabled = (MMI_BOOL*) data_value;
            *is_disabled = (mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_PAUSE) || mmi_medply_is_button_disabled(MMI_MEDPLY_DISABLED_PLAY)) ? MMI_TRUE : MMI_FALSE;
            break;
        }

        case MMI_WIDGET_PLAYER_FULLPATH:
        {
            UI_string_type* fullpath;
            fullpath = (UI_string_type*)data_value;
           // *fullpath = g_medply.filefullpath;

             mmi_ucs2cpy((CHAR*)fullpath , (CHAR*)g_medply.filefullpath);
            break;
        }

        case MMI_WIDGET_PLAYER_VOL:
        {
            U8* vol;
            vol = (U8*)data_value;
            *vol = g_medply.volume;
            break;
        }

        default:
        {
            ASSERT(0);
        }

    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_WIDGET_GET_VALUE, enum_value, *((U8*)data_value));

    return MMI_TRUE;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_widget_set_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_widget_set_value(mmi_widget_player_get_value_enum enum_value, void* data_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(enum_value)
    {
        case MMI_WIDGET_PLAYER_VOL:
        {
            g_medply.volume = *((U8*)data_value);

            if(g_medply.volume > MDI_AUD_VOL_EX_MUTE_MAX)
            {
                g_medply.volume = MDI_AUD_VOL_EX_MUTE_MAX;
            }   

            if(mmi_medply_is_play_activated())
            {
                mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX_MUTE(g_medply.volume));
            }

        #ifdef __MMI_MEDIA_PLAYER_FTE__
            if(!g_medply.mute &&  (MDI_AUD_VOL_EX_MUTE_MIN == g_medply.volume))
            {
                g_medply.mute = MMI_TRUE;
            }
            else if(g_medply.mute && (MDI_AUD_VOL_EX_MUTE_MIN != g_medply.volume))
            {
                g_medply.mute = MMI_FALSE;
            }
        #else
            if(g_medply.mute)
            {
                g_medply.mute = MMI_FALSE;
            }
        #endif /*__MMI_MEDIA_PLAYER_FTE__*/

            break;
        }

        default:
        {
            break;
        }
    }

    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_widget_button_action
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_widget_player_button_enum [IN]
 *  mmi_widget_player_key_event_enum    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_widget_button_action(mmi_widget_player_button_enum button, mmi_widget_player_key_event_enum key_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!mmi_medply_widget_is_plst_ready())
    {
        return;
    }

    if(key_event == MMI_WIDGET_PLAYER_KEY_CANCELED)
    {
        mmi_medply_press_button_canceled();
        return;
    }

    switch(button)
    {
        case MMI_WIDGET_PLAYER_PLAY_PAUSE:
        {
            if(key_event == MMI_WIDGET_PLAYER_KEY_DOWN)
            {
                mmi_medply_press_play_button_down();
            }
            else if(key_event == MMI_WIDGET_PLAYER_KEY_UP)
            {
        #if defined(__MMI_BACKGROUND_CALL__) && !defined(__RF_DESENSE_TEST__) && !defined(__CS_STREAMING_CONCURRENT_SUPPORT__)
            if(srv_ucm_is_background_call())
            {
                mmi_medply_display_popup_with_sg(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL, MMI_EVENT_FAILURE);
                break;
            }
        #endif 
                mmi_medply_background_prepare();
                mmi_medply_press_play_button_up();            
            }
            break;
        }

        case MMI_WIDGET_PLAYER_NEXT:
        {
            if(key_event == MMI_WIDGET_PLAYER_KEY_DOWN)
            {
                mmi_medply_press_next_button_down();
            }
            else if(key_event == MMI_WIDGET_PLAYER_KEY_UP)
            {
                mmi_medply_press_next_button_up();
            }
            break;
        }

        case MMI_WIDGET_PLAYER_PREV:
        {
            if(key_event == MMI_WIDGET_PLAYER_KEY_DOWN)
            {
                mmi_medply_press_prev_button_down();
            }
            else if(key_event == MMI_WIDGET_PLAYER_KEY_UP)
            {
                mmi_medply_press_prev_button_up();
            }
            break;
        }

        case MMI_WIDGET_PLAYER_STOP:
        {
            if(key_event == MMI_WIDGET_PLAYER_KEY_DOWN)
            {
                mmi_medply_press_stop_button_down();
            }
            else if(key_event == MMI_WIDGET_PLAYER_KEY_UP)
            {
                mmi_medply_press_stop_button_up();
            }
            break;
        }

    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_widget_register_callbacks
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL    
 *****************************************************************************/
void mmi_medply_widget_register_callbacks(void* userdata, void (*callback)(void*, mmi_widget_player_callback_enum, void*))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_medply.widget_callback = callback;
    g_medply.widget_callback_userdata = userdata;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_widget_set_and_apply_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  S32                     [In]    index to be applied
 *  MMI_ID_TYPE*            [OUT]   error string id for popup
 *  mmi_event_notify_enum   [OUT]   error event type for popup
 * RETURNS
 *  MMI_BOOL    set and apply index ressult
 *****************************************************************************/
MMI_BOOL mmi_medply_widget_set_and_apply_index(S32 index, MMI_ID_TYPE* str_id, mmi_event_notify_enum *event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_medply_plst_set_pick_index(index);
    if (ret < 0)
    {
        mmi_medply_plst_get_error_string(ret, str_id, event_type);
        return MMI_FALSE;
    }
    ret = mmi_medply_plst_apply_picked_file();
    if (ret < 0)
    {
        mmi_medply_plst_get_error_string(ret, str_id, event_type);
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_widget_apply_picked_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MMI_ID_TYPE*            [OUT]   error string id for popup
 *  mmi_event_notify_enum   [OUT]   error event type for popup
 * RETURNS
 *  MMI_BOOL    result of apply index 
 *****************************************************************************/
MMI_BOOL mmi_medply_widget_apply_picked_file(MMI_ID_TYPE* str_id, mmi_event_notify_enum *event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_medply_plst_apply_picked_file();
    if (ret < 0)
    {
        mmi_medply_plst_get_error_string(ret, str_id, event_type);
        return MMI_FALSE;
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_is_play_continue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 *  
 * RETURNS
 *  MMI_BOOL    will the next song in playlist will be played or not.
 *****************************************************************************/
MMI_BOOL mmi_medply_is_play_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_medply.continue_to_play;

}


#ifdef __DRM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_drm_valide_right
 * DESCRIPTION
 *  This function is to validate if DRM right still exists
 * PARAMETERS
 *  U16 filename    [IN]    file to be checked
 * RETURNS
 *  CHAR  0: not drm file, 1: drm with rights, 2: drm without rights
 *****************************************************************************/
U8 mmi_medply_drm_valide_right(U16* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    U8 result = 0 ;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if((handle = DRM_open_file((U16*)filename, FS_READ_ONLY, DRM_PERMISSION_PLAY)) >= FS_NO_ERROR)
    {
        if (DRM_get_object_method(handle, NULL) == DRM_METHOD_NONE)
        {
            result = 0;
        }
        else if(DRM_validate_permission(handle, NULL, DRM_PERMISSION_PLAY))
        {   
            result = 1;
        }
        else
        {
            result = 2;
        }
        DRM_close_file(handle);
    }
    else if (handle == DRM_RESULT_NO_PERMISSION)
    {
        result = 2;
    }
    else   /* file open error, but not DRM related problem */
    {
        result = 2;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_CTL_VALIDATE_DRM,result,handle);

    return result;
}

#endif /*__DRM_SUPPORT__*/

#ifdef __DM_LAWMO_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_lawmo_lock_callback
 * DESCRIPTION
 *  This is the callback handler for the MO type of LAWMO lock.
 * PARAMETERS
 *  app_id      : [IN]      App ID
 *  cmd         : [IN]      Command
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_medply_lawmo_lock_callback_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_dm_lawmo_lock_ind_evt_struct* lawmo_lock_ind = (srv_dm_lawmo_lock_ind_evt_struct*)evt;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_LAWMO_LOCK_CALLBACK,__LINE__,lawmo_lock_ind->cmd,g_medply.in_media_player);
    switch (lawmo_lock_ind->cmd)
        {
            case SRV_DM_LAWMO_LOCK_CMD_LOCK:
            {    
                if(!g_medply.in_media_player)
                {
                    mmi_medply_stop_playing();
                }
                (lawmo_lock_ind->cb)(MMI_TRUE, "mediaplay");                
                break;
            }
            
            case SRV_DM_LAWMO_LOCK_CMD_UNLOCK:
            {
                (lawmo_lock_ind->cb)(MMI_TRUE, "mediaplay");   
                break;
            }

            default:
                break;
        }
    return MMI_RET_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_delete_history_hdlr
 * DESCRIPTION
 *  delete history handler of media player main screen
 * PARAMETERS
 *  in_param        [in]
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_medply_delete_history_hdlr(void *in_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bg_play;
    MMI_BOOL clear_other_bg = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_DELETE_HISTORY,g_medply.state,g_medply.continue_to_play, MMI_FALSE);

    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_BG_PLAY,(void*)&bg_play);

#ifdef __DM_LAWMO_SUPPORT__
    if(mmi_dmui_get_status(MMI_DMUI_MO_TYPE_LAWMO_LOCK) == MMI_DMUI_STATUS_LAWMO_LOCK_PARTIALLYLOCK || mmi_dmui_get_status(MMI_DMUI_MO_TYPE_LAWMO_LOCK) == MMI_DMUI_STATUS_LAWMO_LOCK_ON_LOCKING)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_LAWMO_LOCK);
        mmi_medply_stop_playing();
        mmi_medply_set_continue_flag(MMI_FALSE);
        mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
    }
    else
#endif
    if(!bg_play)
    {
        StopTimer(MEDPLY_UPDATE_TIME_TIMER);
    
        switch(g_medply.state)
        {
        #ifdef __MMI_MEDIA_PLAYER_AUDIO__        
            case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:
            case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
            {
                if(g_medply.need_to_build_cache)
                {
                    mdi_audio_stop_build_cache();
                }
            #ifdef __MMI_A2DP_SUPPORT__
                mmi_medply_bt_stop(MMI_FALSE);
            #endif
                break;
            }

            case MEDPLY_STATE_AUDIO_PLAY:
            {
                /*stop file*/
                mmi_medply_set_self_stop_flag(MMI_TRUE);

                mdi_audio_stop_file();

                mmi_medply_set_self_stop_flag(MMI_FALSE);
            #ifdef __MMI_A2DP_SUPPORT__
                mmi_medply_bt_stop(MMI_FALSE);
            #endif
                break;
            }

            case MEDPLY_STATE_AUDIO_BT_CONNECTING:
            {
            #ifdef __MMI_A2DP_SUPPORT__
                mmi_medply_bt_stop(MMI_FALSE);
            #endif
                break;
            }

            case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
            {
                mmi_medply_set_self_stop_flag(MMI_TRUE);

                mdi_audio_stop_file();

                mmi_medply_set_self_stop_flag(MMI_FALSE);

            #ifdef __MMI_A2DP_SUPPORT__
                mmi_medply_bt_stop(MMI_FALSE);
            #endif
                break;
            }

            case MEDPLY_STATE_AUDIO_WAIT_ACTIVATE:
            {
                break;
            }

            case MEDPLY_STATE_AUDIO_PLAY_WAIT_ACTIVATE:
            case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING_WAIT_ACTIVATE:
            {
                /*stop file*/
                mmi_medply_set_self_stop_flag(MMI_TRUE);

                mdi_audio_stop_file();

                mmi_medply_set_self_stop_flag(MMI_FALSE);

            #ifdef __MMI_A2DP_SUPPORT__
                mmi_medply_bt_stop(MMI_FALSE);
            #endif
                break;
            }

            case MEDPLY_STATE_AUDIO_BT_CONNECTING_WAIT_ACTIVATE:
            {
            #ifdef __MMI_A2DP_SUPPORT__
                mmi_medply_bt_stop(MMI_FALSE);
            #endif
                break;
            }
        #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

        #ifdef __MMI_MEDIA_PLAYER_VIDEO__
            case MEDPLY_STATE_VIDEO_OPENING:
            {
                mdi_video_ply_stop_non_block_seek();
                mmi_medply_video_close();
                mdi_audio_clear_interrupt_callback();
                break;
            }

            case MEDPLY_STATE_VIDEO_READY:
            {                
                mmi_medply_video_close();
                mdi_audio_clear_interrupt_callback();
                break;
            }

            case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
            case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:
            {
                mmi_medply_video_close();
                mdi_audio_clear_interrupt_callback();
                break;
            }

            case MEDPLY_STATE_VIDEO_PAUSE_SEEKING:
            case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
            {            
                mdi_video_ply_stop_non_block_seek();
                mmi_medply_video_close();
                mdi_audio_clear_interrupt_callback();
                break;
            }
            
            case MEDPLY_STATE_VIDEO_PLAY:
            {
                mdi_video_ply_stop();
                mmi_medply_video_close();
                mdi_audio_clear_interrupt_callback();
            #ifdef __MMI_A2DP_SUPPORT__
                mmi_medply_bt_stop(MMI_FALSE);
            #endif
                break;
            }

            case MEDPLY_STATE_VIDEO_BT_CONNECTING:
            {
                mmi_medply_video_close();
                mdi_audio_clear_interrupt_callback();
            #ifdef __MMI_A2DP_SUPPORT__
                mmi_medply_bt_stop(MMI_FALSE);
            #endif
                break;
            }

            case MEDPLY_STATE_PURE_AUDIO_PLAY:
            case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
            {
                mmi_medply_set_self_stop_flag(MMI_TRUE);

                mdi_audio_stop_file();

                mmi_medply_set_self_stop_flag(MMI_FALSE);

            #ifdef __MMI_A2DP_SUPPORT__
                mmi_medply_bt_stop(MMI_FALSE);
            #endif
                break;
            }

        #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

        #ifdef __MMI_MEDIA_PLAYER_STREAM__
            case MEDPLY_STATE_STREAM_INITED:
            {
                mmi_medply_stream_deinit();
                mdi_audio_clear_interrupt_callback();
                break;
            }

            case MEDPLY_STATE_STREAM_CONNECTING:
            case MEDPLY_STATE_STREAM_CONNECTED: 
            {
                mdi_video_stream_disconnect();
                mmi_medply_stream_deinit();
                mdi_audio_clear_interrupt_callback();
                break;
            }

            case MEDPLY_STATE_STREAM_BT_CONNECTING:
            {
                mdi_video_stream_disconnect();
                mmi_medply_stream_deinit();
            #ifdef __MMI_A2DP_SUPPORT__
                mmi_medply_bt_stop(MMI_FALSE);
            #endif
                mdi_audio_clear_interrupt_callback();
                break;
            }

            case MEDPLY_STATE_STREAM_BUFFERING:
            {
                StopTimer(MEDPLY_STREAM_BUFFER_TIMER);
                mdi_video_stream_stop_buffering();
                mdi_video_stream_disconnect();                
                mmi_medply_stream_deinit();
            #ifdef __MMI_A2DP_SUPPORT__
                mmi_medply_bt_stop(MMI_FALSE);
            #endif
                mdi_audio_clear_interrupt_callback();
                break;
            }

            case MEDPLY_STATE_STREAM_PLAY:
            {
                mdi_video_stream_stop();
                mdi_video_stream_disconnect();
                mmi_medply_stream_deinit();
            #ifdef __MMI_A2DP_SUPPORT__
                mmi_medply_bt_stop(MMI_FALSE);
            #endif
                mdi_audio_clear_interrupt_callback();
                break;
            }

            case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:
            {
                mdi_video_stream_disconnect();
                mmi_medply_stream_deinit();
            #ifdef __MMI_A2DP_SUPPORT__
                mmi_medply_bt_stop(MMI_FALSE);
            #endif
                mdi_audio_clear_interrupt_callback();
                break;
            }

            case MEDPLY_STATE_STREAM_AUDIO_PLAY:
            case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:
            {
                mdi_video_stream_stop();
                mdi_video_stream_disconnect();
                mmi_medply_stream_deinit();
            #ifdef __MMI_A2DP_SUPPORT__
                mmi_medply_bt_stop(MMI_FALSE);
            #endif
                mdi_audio_clear_interrupt_callback();
                break;
            }
        #endif /*__MMI_MEDIA_PLAYER_STREAM__*/
        }

        mmi_medply_set_continue_flag(MMI_FALSE);
        mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);

        switch (g_medply.media_type)
        {
        #ifdef __MMI_MEDIA_PLAYER_AUDIO__
            case MEDPLY_TYPE_AUDIO:
            {
                mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
                break;
            }
        #endif
        #ifdef __MMI_MEDIA_PLAYER_VIDEO__
            case MEDPLY_TYPE_VIDEO:
            {
                if(g_medply.in_main_screen)
                {
                    mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
                }
                else
                {
                    mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_READY);
                }
                break;
            }
        #endif

        #ifdef __MMI_MEDIA_PLAYER_STREAM__
            case MEDPLY_TYPE_STREAM:
            {
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
                break;
            }
        #endif /*__MMI_MEDIA_PLAYER_STREAM__*/

            case MEDPLY_TYPE_NONE:
            {
                mmi_medply_enter_core_states(MEDPLY_STATE_IDLE);
                break;
            }
        }

        if(g_medply.fullscreen)
        {
            mmi_medply_main_screen_set_full_screen(MMI_FALSE);
        }

    }
    else
    {
        switch(g_medply.state)
        {
            case MEDPLY_STATE_IDLE:
            {
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
                break;
            }

            case MEDPLY_STATE_WAIT_NEXT_SUSPNEDED:
            case MEDPLY_STATE_WAIT_NEXT:
            {
                clear_other_bg = MMI_TRUE;
                break;
            }

            
            /*----audio----*/
        #ifdef __MMI_MEDIA_PLAYER_AUDIO__
            case MEDPLY_STATE_AUDIO_PLAY:
            case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:            
            case MEDPLY_STATE_AUDIO_BT_CONNECTING:
            
            {
                clear_other_bg = MMI_TRUE;
                break;
            }

            case MEDPLY_STATE_AUDIO_READY:
            case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:
            case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
            {
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
                break;
            }

            case MEDPLY_STATE_AUDIO_INTERRUPTED:
            {
                if(g_medply.continue_to_play)
                {
                    clear_other_bg = MMI_TRUE;                
                }
                else
                {
                    mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
                }
                break;
            }
        #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

        /*----video----*/
        #ifdef __MMI_MEDIA_PLAYER_VIDEO__

            case MEDPLY_STATE_VIDEO_OPENING:
            case MEDPLY_STATE_VIDEO_INTERRUPTED:            
            {
               /*while opening, use continue flag to make sure if we will be playing immediately or not*/
               if(g_medply.continue_to_play)
               {
                   clear_other_bg = MMI_TRUE;
               }
               else
               {
                   mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
               }
               break;
            }

            case MEDPLY_STATE_VIDEO_PLAY:
            case MEDPLY_STATE_VIDEO_BT_CONNECTING:            
            case MEDPLY_STATE_PURE_AUDIO_PLAY:
            case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
            case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
            {
                clear_other_bg = MMI_TRUE;
                break;
            }

            case MEDPLY_STATE_VIDEO_IDLE:
            case MEDPLY_STATE_VIDEO_IDLE_PROGRESSING:
            case MEDPLY_STATE_VIDEO_READY:
            case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
            case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:
            case MEDPLY_STATE_VIDEO_PLAY_SEEKING:
            case MEDPLY_STATE_VIDEO_PAUSE_SEEKING:
            {
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
                break;
            }
            case MEDPLY_STATE_PURE_AUDIO_READY:
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
                mmi_medply_set_continue_flag(MMI_FALSE);
                break;

        #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

        #ifdef __MMI_MEDIA_PLAYER_STREAM__

            case MEDPLY_STATE_STREAM_INITED:
            {
                mmi_medply_stream_deinit();
                mdi_audio_clear_interrupt_callback();
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
                break;
            }

            case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:
            {
                mdi_video_stream_disconnect();
                mmi_medply_stream_deinit();
                mdi_audio_clear_interrupt_callback();
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
                break;
            }
            case MEDPLY_STATE_STREAM_CONNECTED:
            {
                /*while leave media player, disconnect stream*/
                mdi_video_stream_disconnect();
                mmi_medply_stream_deinit();
                mdi_audio_clear_interrupt_callback();
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
                break;
            }
            case MEDPLY_STATE_STREAM_CONNECTING:
            case MEDPLY_STATE_STREAM_BUFFERING:
            case MEDPLY_STATE_STREAM_PLAY:
            case MEDPLY_STATE_STREAM_AUDIO_PLAY:
            case MEDPLY_STATE_STREAM_BT_CONNECTING:
            case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:            
            {
                clear_other_bg = MMI_TRUE;
                break;
            }

            case MEDPLY_STATE_STREAM_INTERRUPTED:
            {
                /*while opening, use continue flag to make sure if we will be playing immediately or not*/
                if(g_medply.continue_to_play)
                {
                    clear_other_bg = MMI_TRUE;
                }
                else
                {
                    mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
                }
                break;
            }
        
        #endif /*__MMI_MEDIA_PLAYER_STREAM__*/
        
            default:
            {
                break;
            }
        }
    }
    if (clear_other_bg)
    {
        mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MEDPLY, (mdi_bg_callback)mmi_medply_background_callback_hdlr, NULL);
        mdi_audio_clear_other_background_handler(MDI_BACKGROUND_APP_MEDPLY);
    }
    g_medply.in_media_player = MMI_FALSE;

    #ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    mmi_medply_settings_subtitle_iso_shutdown();
    #endif

    mmi_medply_main_screen_delete(NULL);

    return MMI_FALSE;

}


#ifdef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_delete_fte_history_hdlr
 * DESCRIPTION
 *  delete history handler of media player main screen
 * PARAMETERS
 *  in_param        [in]
 * RETURNS
 *  U8
 *****************************************************************************/
static mmi_ret mmi_medply_delete_fte_history_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:
        mmi_medply_delete_history_hdlr(param);
        break;
    default:
        break;
    }
    return MMI_RET_OK;    
}
#else

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_delete_history_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_medply_delete_history_proc(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:
        mmi_medply_delete_history_hdlr(NULL);
        break;
    default:
        break;
    }
    return MMI_RET_OK;    
}


#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_update_state
 * DESCRIPTION
 *  update state for update main
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_update_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!g_medply.in_main_screen)
    {
        return;
    }

    switch (g_medply.state)
    {
        case MEDPLY_STATE_IDLE:
        {
            mdi_audio_stop_all();
            mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MEDPLY, (mdi_bg_callback)mmi_medply_background_callback_hdlr, NULL);

            /*if total number is zero, then no need to go to next state*/
            if(mmi_medply_plst_curr_get_total()<=0)
            {
                g_medply.media_type = MEDPLY_TYPE_NONE;
            }
            else
            {
                switch(g_medply.media_type)
                {
                    case MEDPLY_TYPE_AUDIO:
                    {
                    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
                        mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
                    #endif
                        break;
                    }

                    case MEDPLY_TYPE_VIDEO:
                    {
                    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
                        /*open video file when entering main screen*/
                        if(g_medply.continue_to_play)
                        {
                            MMI_BOOL result;
                            result = mmi_medply_video_open();
                            if(!result)
                            {
                                return;
                            }
                        }
                        else
                        {
                            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
                        }
                    #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/
                        break;
                    }

                    case MEDPLY_TYPE_STREAM:
                    {
                    #ifdef __MMI_MEDIA_PLAYER_STREAM__
                        MMI_BOOL result;

                        if(g_medply.continue_to_play)
                        {
                            mmi_medply_set_continue_flag(MMI_FALSE);
                            result = mmi_medply_stream_init();
                            if(result)
                            {
                                result = mmi_medply_stream_connect();
                            }

                            if(!result)
                            {
                                return;
                            }
                        }
                        else
                        {
                            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
                            mmi_medply_change_status(MMI_TRUE);
                        }
                    #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/
                        break;
                    }
                }

            }
            break;
        }

        case MEDPLY_STATE_WAIT_NEXT:
        {
            mdi_audio_stop_all();
            mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MEDPLY, (mdi_bg_callback)mmi_medply_background_callback_hdlr, NULL);
            StopTimer(MEDPLY_WAIT_NEXT_TIMER);
            StartTimer(MEDPLY_WAIT_NEXT_TIMER, 700, mmi_medply_wait_next_time_out);
            break;
        }

        case MEDPLY_STATE_WAIT_NEXT_SUSPNEDED:
        {
            mdi_audio_stop_all();
            mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MEDPLY, (mdi_bg_callback)mmi_medply_background_callback_hdlr, NULL);            

            break;
        }

    /*----audio----*/
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        case MEDPLY_STATE_AUDIO_READY:
        {
            mdi_audio_stop_all();
            mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MEDPLY, (mdi_bg_callback)mmi_medply_background_callback_hdlr, NULL);

            if(g_medply.continue_to_play)
            {
                mmi_medply_set_continue_flag(MMI_FALSE);
                mmi_medply_audio_play();
            }
            else
            {
                mmi_medply_change_status(MMI_TRUE);
            }

            break;

        }

        case MEDPLY_STATE_AUDIO_INTERRUPTED:
        {
            mdi_audio_stop_all();
            mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MEDPLY, (mdi_bg_callback)mmi_medply_background_callback_hdlr, NULL);

            mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
            break;

        }
        
        case MEDPLY_STATE_AUDIO_PLAY:
        case MEDPLY_STATE_AUDIO_BT_CONNECTING:
        case MEDPLY_STATE_AUDIO_PLAY_BT_CONNECTING:
        {
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

    /*----video----*/
    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
        case MEDPLY_STATE_PURE_AUDIO_READY:
        {
            mdi_audio_stop_all();
            mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MEDPLY, (mdi_bg_callback)mmi_medply_background_callback_hdlr, NULL);                            

            /*to handle cases that enter main screen before exit screen enter pure audio time out
              ex: Modis tool*/
            if(!g_medply.continue_to_play)
            {
                mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
            }
            else
            {
                MMI_BOOL result;
                result = mmi_medply_video_open();
                if(!result)
                {
                    return;
                }
            }
            break;
        }

        case MEDPLY_STATE_PURE_AUDIO_PLAY:
        case MEDPLY_STATE_PURE_AUDIO_PLAY_BT_CONNECTING:
        {
            MMI_BOOL result;

            mmi_medply_set_self_stop_flag(MMI_TRUE);

            mdi_audio_stop_file();

            mmi_medply_set_self_stop_flag(MMI_FALSE);

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif            

            /* restore to normal speed when stop play */
        #ifdef __MMI_AUDIO_TIME_STRETCH__
            mmi_medply_settings_close_speed();
        #endif

            mmi_medply_set_continue_flag(MMI_TRUE);

            result = mmi_medply_video_open();
            if(!result)
            {
                return;
            }
            break;
        }

        case MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING:
        {
            mmi_medply_set_continue_flag(MMI_TRUE);
            mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE_BT_CONNECTING);
            break;
        }

        case MEDPLY_STATE_VIDEO_INTERRUPTED:
        {
            
            mdi_audio_stop_all();
            mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MEDPLY, (mdi_bg_callback)mmi_medply_background_callback_hdlr, NULL);                            
            
            if(g_medply.continue_to_play)
            {
                MMI_BOOL result;

                /*if background suspended, it means some application still wishes to hold the audio resource
                  ex: background call end but have not release speech*/
                if(mdi_audio_is_background_play_suspended())
                {
                    break;
                }

                result = mmi_medply_video_open();
                if(!result)
                {
                    return;
                }
            }
            else
            {
                mmi_medply_enter_video_states(MEDPLY_STATE_VIDEO_IDLE);
            }
                
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

    #ifdef __MMI_MEDIA_PLAYER_STREAM__
        case MEDPLY_STATE_STREAM_IDLE:
        {
            MMI_BOOL result;

            mdi_audio_stop_all();
            mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MEDPLY, (mdi_bg_callback)mmi_medply_background_callback_hdlr, NULL);            

            if(g_medply.continue_to_play)
            {
                mmi_medply_set_continue_flag(MMI_FALSE);
                result = mmi_medply_stream_init();
                if(result)
                {
                    result = mmi_medply_stream_connect();
                }

                if(!result)
                {
                    return;
                }
            }
            else
            {
                mmi_medply_change_status(MMI_TRUE);
            }

            break;
        }

        case MEDPLY_STATE_STREAM_INITED:
        {
            mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MEDPLY, (mdi_bg_callback)mmi_medply_background_callback_hdlr, NULL);
            break;
        }

        case MEDPLY_STATE_STREAM_CONNECTING:
        case MEDPLY_STATE_STREAM_CONNECTED:
        case MEDPLY_STATE_STREAM_BT_CONNECTING:            
        {
            mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MEDPLY, (mdi_bg_callback)mmi_medply_background_callback_hdlr, NULL);            
            break;
        }

        case MEDPLY_STATE_STREAM_BUFFERING:
        {
            mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MEDPLY, (mdi_bg_callback)mmi_medply_background_callback_hdlr, NULL);                        
            mdi_video_stream_stop_buffering();
            mmi_medply_stream_buffer();
            break;
        }

        case MEDPLY_STATE_STREAM_AUDIO_PLAY:
        case MEDPLY_STATE_STREAM_AUDIO_PLAY_BT_CONNECTING:            
        {
            mdi_video_stream_stop();
        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif
            mmi_medply_stream_buffer();
            break;
        }
 
        case MEDPLY_STATE_STREAM_INTERRUPTED:
        {
            MMI_BOOL result;

            mdi_audio_stop_all();

            mdi_audio_set_background_handler(MDI_BACKGROUND_APP_MEDPLY, (mdi_bg_callback)mmi_medply_background_callback_hdlr, NULL);                            

            /*if background suspended, it means some application still wishes to hold the audio resource
              ex: background call end but have not release speech*/
            if(mdi_audio_is_background_play_suspended())
            {
                result = mmi_medply_stream_init();
                if(result)
                {
                    if(g_medply.continue_to_play)
                    {
                        mmi_medply_set_continue_flag(MMI_FALSE);
                        result = mmi_medply_stream_connect();
                    }
                }
                if(!result)
                {
                    return;
                }
            }

            break;
        }

    #endif /*__MMI_MEDIA_PLAYER_STREAM__*/

        default:
            MMI_ASSERT(0);
            break;            
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_update_main
 * DESCRIPTION
 *  while entry main screen, state transition and redraw main screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_update_main(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) && defined(__MMI_MEDIA_PLAYER_FTE__)  
    mmi_frm_gesture_rect_struct rect;
#endif 

#ifdef MOTION_SENSOR_SUPPORT
    srv_sensor_motion_direct_cfg_struct sensitive;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_UPDATE_MAIN,g_medply.state,g_medply.media_type, MMI_FALSE);

    mmi_medply_main_screen_redraw();
    mmi_medply_main_screen_blt();

    /* run SSE */
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    gui_screen_switch_effect_run();    
#endif

#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_register_volume_sync_callback(APP_MEDPLY,MDI_AUD_VOL_LEVEL_EXTEND_MUTE,mmi_medply_handfree_volume_sync_callback);
#endif

    /* register delete screen hdlr, prvent return without registering*/
#ifndef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_MAIN_SCREEN, SCR_ID_MEDPLY_MAIN_SCREEN, mmi_medply_delete_history_proc);
#else
    mmi_frm_scrn_set_leave_proc(g_gid_medply, 
                                SCR_ID_MEDPLY_MAIN_SCREEN, 
                                mmi_medply_delete_fte_history_hdlr);    
#endif

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
#endif


#ifdef MOTION_SENSOR_SUPPORT
    /*MAUI_03010605*/
    kal_get_time((kal_uint32*)&g_medply.motion_reg_time);

    sensitive.angle_threshold = 30;
    g_medply.tilt_handle = srv_sensor_start_listen(SRV_SENSOR_MOTION_DIRECT, &sensitive, mmi_medply_motion_tilt_hdlr,NULL);
#endif

    ClearKeyEvents();
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) && defined(__MMI_MEDIA_PLAYER_FTE__)
    if (mmi_medply_check_gesture_valid(&rect))
    {
        mmi_frm_gesture_listen_event_ex(MMI_FRM_GESTURE_LEFT, mmi_medply_main_screen_gesture_hdl, &rect);
        mmi_frm_gesture_listen_event_ex(MMI_FRM_GESTURE_RIGHT, mmi_medply_main_screen_gesture_hdl, &rect);
    }    
#endif

#if defined(__MMI_BACKGROUND_CALL__) && !defined(__RF_DESENSE_TEST__) && !defined(__CS_STREAMING_CONCURRENT_SUPPORT__)
    if(srv_ucm_is_background_call())
    {
        /*register key hdlr*/
    mmi_medply_register_key_hdlrs(MMI_MEDPLY_SCREEN_NORMAL);

        /* register pen hdlr*/
    #ifdef __MMI_TOUCH_SCREEN__
        mmi_pen_register_down_handler(mmi_medply_pen_down_hdlr);
        mmi_pen_register_up_handler(mmi_medply_pen_up_hdlr);
        mmi_pen_register_move_handler(mmi_medply_pen_move_hdlr);
        mmi_pen_register_abort_handler(mmi_medply_pen_abort_hdlr);
        mmi_pen_register_long_tap_handler(mmi_medply_pen_long_tap_hdlr);
        mmi_pen_register_repeat_handler(mmi_medply_pen_repeat_hdlr);
    #endif /* __MMI_TOUCH_SCREEN__ */ 
        return;
    }
#endif

    MMI_ASSERT(g_medply.fullscreen != MMI_TRUE);
    /*register key hdlr*/
    mmi_medply_register_key_hdlrs(MMI_MEDPLY_SCREEN_NORMAL);

    /* register pen hdlr*/
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_register_down_handler(mmi_medply_pen_down_hdlr);
    mmi_pen_register_up_handler(mmi_medply_pen_up_hdlr);
    mmi_pen_register_move_handler(mmi_medply_pen_move_hdlr);
    mmi_pen_register_abort_handler(mmi_medply_pen_abort_hdlr);
    mmi_pen_register_long_tap_handler(mmi_medply_pen_long_tap_hdlr);
    mmi_pen_register_repeat_handler(mmi_medply_pen_repeat_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    /* post event to do the update state process */
    if(!mmi_is_redrawing_bk_screens())
    {
        mmi_event_struct evt;
        MMI_FRM_INIT_EVENT(&evt,EVT_ID_MEDPLY_UPDATE_MAIN);
        MMI_FRM_POST_EVENT(&evt,mmi_medply_broadcast_event_callback_hdlr,NULL);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_exit_main
 * DESCRIPTION
 *  exit function of media player main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_exit_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_EXIT_MAIN,g_medply.state,g_medply.pop_up, MMI_FALSE);

    /*make sure med_v opened file are all closed since they use screen based mem*/
#ifdef __MMI_MEDIA_PLAYER_AUDIO__
    if(g_medply.media_type == MEDPLY_TYPE_AUDIO)
    {
        mdi_audio_close_build_cache();
    }
#endif

    /* in main screen flag must be set before state change or is_button_disabled will judge wrong*/
    g_medply.in_main_screen = MMI_FALSE;
    g_medply.selected_button_down = MMI_FALSE;
    g_medply.affected_button_down = MMI_MEDPLY_RGN_ID_NULL;
    g_medply.unaffected_button_down = MMI_MEDPLY_RGN_ID_NULL;

    StopTimer(MEDPLY_TOUCH_AUTO_RUN_TIMER);

#ifdef MOTION_SENSOR_SUPPORT
/*    if(g_medply.shake_handle >= 0)
    {
        mdi_motion_stop_listen_shake(g_medply.shake_handle);
        g_medply.shake_handle = -1 ;
    }
*/

    if(g_medply.tilt_handle >= 0)
    {
        srv_sensor_stop_listen(g_medply.tilt_handle);
        g_medply.tilt_handle = -1 ;
    }
#endif

    if(g_medply.pop_up)
    {
        if(g_medply.fullscreen)
        {
            mmi_medply_main_screen_set_full_screen(MMI_FALSE);
            mmi_medply_main_screen_clear_video_layer();
            g_medply.fullscreen = MMI_FALSE;
        }

    #ifdef MMI_MEDPLY_HIGH_RATE_SAMPLING_PROGRESS_BAR_PERFORMANCE
        mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_1,MMI_PEN_SAMPLING_PERIOD_2);
    #endif

        mmi_medply_main_screen_unprepare();

    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
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
    #endif

    #ifdef  __MMI_TOUCH_SCREEN__
        ClearInputEventHandler(MMI_DEVICE_PEN);
    #endif

    #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
        mmi_frm_gesture_stop_listen_event();
    #endif

        g_medply.pop_up = MMI_FALSE;
        return;
    }


    switch(g_medply.state)
    {
    
    case MEDPLY_STATE_WAIT_NEXT: 
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
    if(g_medply.media_type == MEDPLY_TYPE_VIDEO)
    {
        mmi_medply_set_continue_flag(MMI_FALSE);
    }
    #endif
    break;
    
    /*----audio----*/
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        case MEDPLY_STATE_AUDIO_PLAY_PROGRESSING:
        case MEDPLY_STATE_AUDIO_PAUSE_PROGRESSING:
        {

            /*for progressing case, set both continue flag to false for easy and clear handle style*/
            if(g_medply.need_to_build_cache)
            {
                mdi_audio_stop_build_cache();
            }
            mmi_medply_set_continue_flag(MMI_FALSE);            
            mmi_medply_enter_audio_states(MEDPLY_STATE_AUDIO_READY);
            break;
        }

        case MEDPLY_STATE_AUDIO_INTERRUPTED:
        {
            break;
        }
    
    #endif /*__MMI_MEDIA_PLAYER_AUDIO__*/

    /*----video----*/
    #ifdef __MMI_MEDIA_PLAYER_VIDEO__
        case MEDPLY_STATE_VIDEO_IDLE:
        case MEDPLY_STATE_VIDEO_IDLE_PROGRESSING:
        {
            mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_READY);
            break;
        }

        case MEDPLY_STATE_VIDEO_OPENING:
        {
            /*close video*/
            mdi_video_ply_stop_non_block_seek();
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();
            gui_start_timer(10, mmi_medply_video_enter_pure_audio_ready_state);

            /*switch state first in case before time out, entering main screen again*/
            g_medply.state = MEDPLY_STATE_PURE_AUDIO_READY;
            break;
        }

        case MEDPLY_STATE_VIDEO_READY:            
        {
            if(!g_medply.seekable)
            {
                g_medply.current_time = 0;
            }

            /*close video*/
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_READY);
            break;
        }

        case MEDPLY_STATE_VIDEO_PLAY:
        {
            StopTimer(MEDPLY_UPDATE_TIME_TIMER);            
            mdi_video_ply_stop();

            if(g_medply.seekable)
            {
                /* set current time to lastest */
                mdi_video_ply_get_cur_play_time(&g_medply.current_time);
            }
            else
            {
                g_medply.current_time = 0;
            }

            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();

        #ifdef __MMI_A2DP_SUPPORT__
            mmi_medply_bt_stop(MMI_FALSE);
        #endif

            mmi_medply_set_continue_flag(MMI_TRUE);
            gui_start_timer(10, mmi_medply_video_enter_pure_audio_ready_check);

            /*switch state first in case before time out, entering main screen again*/
            g_medply.state = MEDPLY_STATE_PURE_AUDIO_READY;
            break;
        }

        case MEDPLY_STATE_VIDEO_PAUSE_PROGRESSING:
        case MEDPLY_STATE_VIDEO_PLAY_PROGRESSING:            
        {
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_set_continue_flag(MMI_FALSE);
            mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_READY);
            break;
        }

        case MEDPLY_STATE_VIDEO_PAUSE_SEEKING:
        case MEDPLY_STATE_VIDEO_PLAY_SEEKING:            
        {
            mdi_video_ply_stop_non_block_seek();
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();
            if(g_medply.state == MEDPLY_STATE_VIDEO_PAUSE_SEEKING)
            {
                mmi_medply_set_continue_flag(MMI_FALSE);
            }
            else
            {
                mmi_medply_set_continue_flag(MMI_TRUE);
            }
            gui_start_timer(10, mmi_medply_video_enter_pure_audio_ready_state);

            /*switch state first in case before time out, entering main screen again*/
            g_medply.state = MEDPLY_STATE_PURE_AUDIO_READY;
            break;
        }

        case MEDPLY_STATE_VIDEO_BT_CONNECTING:
        {
            mmi_medply_video_close();
            mdi_audio_clear_interrupt_callback();
            mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING);
            break;
        }

        case MEDPLY_STATE_VIDEO_IDLE_BT_CONNECTING:
        {
            mmi_medply_enter_video_states(MEDPLY_STATE_PURE_AUDIO_BT_CONNECTING);
            break;
        }

        case MEDPLY_STATE_VIDEO_INTERRUPTED:
        {
            break;
        }

    #endif /*__MMI_MEDIA_PLAYER_VIDEO__*/

    #ifdef __MMI_MEDIA_PLAYER_STREAM__

        case MEDPLY_STATE_STREAM_PLAY:
        {
            if(g_medply.track != MDI_VIDEO_TRACK_V_ONLY)
            {
                mdi_video_stream_stop_visual_update();
                mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_AUDIO_PLAY);
            }
            else
            {
                mdi_video_stream_stop();
            #ifdef __MMI_A2DP_SUPPORT__
                mmi_medply_bt_stop(MMI_FALSE);
            #endif                
                mdi_video_stream_disconnect();

                if(!g_medply.in_media_player)
                {
                    mmi_medply_stream_deinit();
                    mdi_audio_clear_interrupt_callback();
                    mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
                    mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
                }
                else
                {
                    mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);
                }
            }
            break;
        }

        case MEDPLY_STATE_STREAM_PLAY_PROGRESSING:
        {
            mmi_medply_set_continue_flag(MMI_FALSE);
            mdi_video_stream_disconnect();
            mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);
            break;
        }

        case MEDPLY_STATE_STREAM_BUFFERING:
        {
            if(g_medply.track != MDI_VIDEO_TRACK_V_ONLY)
            {            
                mdi_video_stream_stop_buffering();
                mmi_medply_stream_buffer();
            }
            else
            {
                mdi_video_stream_stop_buffering();
            #ifdef __MMI_A2DP_SUPPORT__
                mmi_medply_bt_stop(MMI_FALSE);
            #endif                
                mdi_video_stream_disconnect();

                if(!g_medply.in_media_player)
                {
                    mmi_medply_stream_deinit();
                    mdi_audio_clear_interrupt_callback();
                    mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_IDLE);
                    mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
                }
                else
                {
                    mmi_medply_enter_stream_states(MEDPLY_STATE_STREAM_INITED);
                }
            }
            break;
        }
    #endif /*__MMI_MEDIA_PLAYER_STREAM__*/
    }

    if(g_medply.fullscreen)
    {
        mmi_medply_main_screen_set_full_screen(MMI_FALSE);
        mmi_medply_main_screen_clear_video_layer();
        g_medply.fullscreen = MMI_FALSE;
    }


    /* Don't write to NVRAM directly when exit media player, just update to cache */
    SetFlashAllNVRAMCatchData(MMI_TRUE);  /* don't save MMI cache content in NVRAM */
    WriteValue(NVRAM_MEDIA_PLAYER_MUTE, &g_medply.mute, DS_BYTE, &error);
    WriteValue(NVRAM_MEDIA_PLAYER_VOLUME, &g_medply.volume, DS_BYTE, &error);
#ifdef __MMI_MEDIA_PLAYER_SNAPSHOT__
    WriteValue(NVRAM_MEDPLY_SNAPSHOT_SEQ_NO, &g_medply.filename_seq_no, DS_SHORT, &error);
#endif
    SetFlashAllNVRAMCatchData(MMI_FALSE);  /* don't save MMI cache content in NVRAM */


#ifdef __MMI_MEDIA_PLAYER_FTE__
    mmi_medply_plst_store_rating_flush();
#endif

    #ifdef MMI_MEDPLY_HIGH_RATE_SAMPLING_PROGRESS_BAR_PERFORMANCE
    mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_1,MMI_PEN_SAMPLING_PERIOD_2);
    #endif
    mmi_medply_main_screen_unprepare();
#if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
    mmi_frm_gesture_stop_listen_event();
#endif

#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
#endif


#ifdef __MMI_MEDIA_PLAYER_AUDIO__    
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
#endif

#ifdef  __MMI_TOUCH_SCREEN__
    ClearInputEventHandler(MMI_DEVICE_PEN);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_entry_main
 * DESCRIPTION
 *  entery function of media player main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_ENTRY_MAIN, MMI_FALSE);
    
#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        MMI_STR_ID string_id = 0;
        mmi_event_notify_enum event_type = MMI_EVENT_DEFAULT;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MASS_STORAGE_MODE);
        string_id = mmi_usb_get_error_info(SRV_USB_ERROR_UNAVAILABLE, &event_type);
        mmi_medply_display_popup_with_sg((U16)string_id, event_type);
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

#if defined(__MMI_BACKGROUND_CALL__) && !defined(__RF_DESENSE_TEST__) && !defined(__CS_STREAMING_CONCURRENT_SUPPORT__)
    if(srv_ucm_is_background_call())
    {
        PU8 gui_buffer = NULL;

#ifndef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
        gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_MAIN_SCREEN, SCR_ID_MEDPLY_MAIN_SCREEN);
#else
        gui_buffer = mmi_frm_scrn_get_gui_buf(g_gid_medply, SCR_ID_MEDPLY_MAIN_SCREEN);
#endif /* __MMI_MEDIA_PLAYER_PLST_DB_STYLE__ */
        if(gui_buffer == NULL)
        {
            mmi_medply_display_popup_with_sg(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL, MMI_EVENT_FAILURE);
            return;
        }
    }
#endif

#ifdef __DM_LAWMO_SUPPORT__
    if(mmi_dmui_get_status(MMI_DMUI_MO_TYPE_LAWMO_LOCK) == MMI_DMUI_STATUS_LAWMO_LOCK_PARTIALLYLOCK || mmi_dmui_get_status(MMI_DMUI_MO_TYPE_LAWMO_LOCK) == MMI_DMUI_STATUS_LAWMO_LOCK_ON_LOCKING)
    {
        PU8 gui_buffer = NULL;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_CTL_LAWMO_LOCK);
#ifndef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
        gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_MAIN_SCREEN, SCR_ID_MEDPLY_MAIN_SCREEN);
#else
        gui_buffer = mmi_frm_scrn_get_gui_buf(g_gid_medply, SCR_ID_MEDPLY_MAIN_SCREEN);
#endif /* __MMI_MEDIA_PLAYER_PLST_DB_STYLE__ */
        if(gui_buffer == NULL)
        {
            return;
        }
    }
#endif

#ifndef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
    mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_MAIN_SCREEN, mmi_medply_event_proc, (void*)GRP_ID_MEDPLY_MAIN_LIST); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_MAIN_SCREEN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_MAIN_SCREEN, SCR_ID_MEDPLY_MAIN_SCREEN, mmi_medply_exit_main, 
                                   mmi_medply_entry_main, MMI_FRM_UNKNOW_SCRN);
    

#else
    entry_ret = mmi_frm_scrn_enter(g_gid_medply, SCR_ID_MEDPLY_MAIN_SCREEN, mmi_medply_exit_main, 
                                   mmi_medply_entry_main, MMI_FRM_UNKNOW_SCRN);
#endif /* __MMI_MEDIA_PLAYER_PLST_DB_STYLE__ */

    if (!entry_ret)
    {
        return;
    }

#ifdef __MMI_MEDIA_PLAYER_AUDIO__
    //bql: no need to allocate for build cache buffer.
    g_medply.audio_cache_file_buf_p = NULL;
    g_medply.audio_cache_proc_buf_p = NULL;

    //g_medply.audio_cache_file_buf_p = mmi_frm_scrmem_alloc(MEDPLY_BUILD_CACHE_FILE_BUF_SIZE);
    //g_medply.audio_cache_proc_buf_p = mmi_frm_scrmem_alloc(MEDPLY_BUILD_CACHE_PROC_BUF_SIZE);
#endif

//#ifndef __MMI_MAINLCD_240X400__
    entry_full_screen();
//#endif

#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    gui_screen_switch_effect_setup(0, 0, 0);    
#endif

    #ifdef MMI_MEDPLY_HIGH_RATE_SAMPLING_PROGRESS_BAR_PERFORMANCE
    mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_2,MMI_PEN_SAMPLING_PERIOD_2);
    #endif
    
    mmi_medply_main_screen_prepare();

    /* check state! only idle re-apply pick! */
    if (g_medply.state == MEDPLY_STATE_IDLE)
    {
        mmi_medply_plst_apply_picked_file();
        mmi_medply_util_fill_idle_display_str();
    }

    g_medply.in_main_screen = MMI_TRUE;
    g_medply.in_media_player = MMI_TRUE;

    mmi_medply_update_main();

}

#ifdef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_fte_player_option_cui_proc
 * DESCRIPTION
 *  Screen group callback process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_medply_fte_player_option_cui_proc(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            if (mmi_medply_plst_curr_is_valid())
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MAIN_SCREEN_OPT_CURRENT_LIST, MMI_FALSE);
            }
            else
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_MAIN_SCREEN_OPT_CURRENT_LIST, MMI_TRUE);
            }

            cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_MEDPLY_SETTINGS, MMI_FALSE);

            break;
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_MEDPLY_FTE_MAIN_SCREEN_OPT_CURRENT_LIST:
                    mmi_medply_listui_entry_curr_plst_list();
                    break;
                case MENU_ID_MEDPLY_FTE_MAIN_SCREEN_OPT_MAIN_MENU:
                    mmi_frm_group_close(GRP_ID_MEDPLY_FTE_SUB_MENU);
                    break;
                case MENU_ID_MEDPLY_SETTINGS:
                    mmi_medply_settings_entry_main();
                    break;

                default:
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            /* Close CUI */
            cui_menu_close(menu_evt->sender_id);
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_entry_main_menu_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_entry_main_menu_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Use menu cui to display manin menu */
    menu_gid = cui_menu_create(GRP_ID_MEDPLY_FTE_SUB_MENU, 
                               CUI_MENU_SRC_TYPE_RESOURCE,
                               CUI_MENU_TYPE_OPTION,
                               MENU_ID_MEDPLY_FTE_MAIN_SCREEN_OPTION,
                               MMI_FALSE,
                               (void*)MEDPLY_MENU_CUI_PLAYER_SCREEN_OPT);
    cui_menu_run(menu_gid);
}
#endif /*__MMI_MEDIA_PLAYER_PLST_DB_STYLE__*/
#ifndef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
static void mmi_medply_app_entry(mmi_medply_main_entry_enum entry);
#else
static void mmi_medply_app_entry(void);
#endif
static void mmi_medply_entry_mscr(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_app_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_RET mmi_medply_app_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (evt->evt_id)
	{
	    case EVT_ID_APP_POST_UNHIDE:
	    case EVT_ID_APP_ENTER:
	    {
                /* Register Screen lock key events when entry app */
                mmi_scr_locker_set_locked_key_callback(mmi_medply_scrlocker_key_callback_hdlr);
                if(g_medply.from_mte == MMI_FALSE)
                {
	            #ifndef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
                    mmi_medply_app_entry(MMI_MEDPLY_ENTRY_MAINMENU);
                #else
                    mmi_medply_app_entry();
                #endif
                }
                else
                {
	            mmi_medply_entry_mscr();
                }
		break;
	     }

	    case EVT_ID_APP_NO_CHILD:
	    {
		if (g_medply.adm_id_p != NULL)
		{
		    mmi_frm_app_set_hidden(APP_MEDPLY, MMI_TRUE, 0);
		    return MMI_APP_NO_CHILD_HANDLED_BY_APP;
		}
		break;
	    }
	    case EVT_ID_APP_CLOSE_REQ:
	    {
	        if (g_medply.adm_id_p != NULL)
		{
		    MMI_ID id = mmi_frm_scrn_get_neighbor_id(APP_MEDPLY, 0, MMI_FRM_NODE_AT_BEGINNING_FLAG);
		    mmi_frm_group_close(id);

		    return MMI_APP_CLOSE_ANSWER_HIDE;
		}
		break;
	    }


	    case EVT_ID_APP_FORCE_CLOSE:
	    {
		mmi_medply_setting_deinit_hdlr();
                mmi_medply_plst_module_deinit();
                mmi_medply_stop_playing();
                mmi_medply_asm_delete();
		break;
	    }
             default:
		break;
	}
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_read_settings
 * DESCRIPTION
 *  read settings from nvram while init application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_app_pre_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_app_is_hidden(APP_MEDPLY) == MMI_FALSE)
    {
        if (mmi_frm_app_is_launched(APP_MEDPLY) == MMI_FALSE)
        {
            g_medply.from_mte = MMI_FALSE;
            mmi_frm_app_launch(APP_MEDPLY, 0, 0, mmi_medply_app_proc, NULL, 0);
        }
        else
        {
            mmi_frm_app_set_active(APP_MEDPLY, 0);
        }
    }
    else
    {
        mmi_frm_app_set_hidden(APP_MEDPLY, MMI_FALSE, 0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_app_entry_mscr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern void mmi_medply_app_entry_mscr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_app_is_hidden(APP_MEDPLY) == MMI_FALSE)
    {
        g_medply.from_mte = MMI_TRUE;
        mmi_frm_app_launch(APP_MEDPLY, 0, 0, mmi_medply_app_proc, NULL, 0);
    }
    else
    {
	mmi_frm_app_set_hidden(APP_MEDPLY, MMI_FALSE, 0);
    }
}


#ifdef __MMI_NCENTER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_entry_main_menu_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_ncenter_add_app_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vsrv_ngroup_handle ghandle;
    vsrv_notification_handle nhandle;

    mmi_image_src_struct nc_icon;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If the ASM is freed then no need to add app item in NCenter */
    if (g_medply.mem_pool_p != NULL)
    {
        ghandle = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, APP_MEDPLY);
        nhandle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_ONGOING, ghandle, 0);
        g_medply.ncenter_ghandle = ghandle;
        g_medply.ncenter_nhandle = nhandle;	                        

        vsrv_ncenter_set_ngroup_title_id(ghandle, (S32)STR_ID_MEDPLY_APP_TITLE);

        nc_icon.type = MMI_IMAGE_SRC_TYPE_RES_ID;
        nc_icon.data.res_id = IMG_ID_MEDPLY_ICON;
        vsrv_ncenter_set_notification_icon(nhandle, nc_icon);

        mmi_medply_util_fill_idle_display_str();
        vsrv_ncenter_set_notification_maintext_str(nhandle, g_medply.idle_string);

        vsrv_ncenter_set_notification_questiontext_id(nhandle, (S32)STR_ID_MEDPLY_NCENTER_CLOSE_NOTIFY);

        vsrv_ncenter_set_notification_intent_callback(nhandle, mmi_medply_ncenter_callback_handler, NULL, 0);

        vsrv_ncenter_notify_notification(nhandle); 
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_entry_main_menu_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_ncenter_callback_handler(vsrv_notification_handle nhandle, vsrv_nintent intent, void* userData, U32 userDataSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (intent.type == VSRV_NINTENT_TYPE_LAUNCH)
    {
        if (!mmi_frm_group_is_present(g_gid_medply))
        {
            mmi_medply_app_pre_entry();
        }
     }
     else if (intent.type == VSRV_NINTENT_TYPE_TERMINATE)
     {
        g_medply.media_type = MEDPLY_TYPE_NONE;
        mmi_medply_stop_playing();
        if (g_gid_medply != GRP_ID_INVALID)
        {
        #ifndef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__
            mmi_frm_group_close(GRP_ID_MEDPLY);
        #else
            mmi_frm_group_close(GRP_ID_MEDPLY_FTE);
        #endif
        }
        mmi_medply_plst_module_deinit();

        mmi_medply_asm_delete();
    #ifdef __MMI_NCENTER_SUPPORT__
        mmi_medply_ncenter_clear_app_item();
    #endif
     }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_entry_main_menu_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_ncenter_update_media(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_medply.ncenter_ghandle == NULL)
    {
        return;
    }
    
    mmi_medply_util_fill_idle_display_str();
    vsrv_ncenter_set_notification_maintext_str(g_medply.ncenter_nhandle, g_medply.idle_string);
    vsrv_ncenter_notify_notification(g_medply.ncenter_nhandle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_entry_main_menu_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_ncenter_clear_app_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_medply.ncenter_ghandle == NULL)
    {
        return;
    }
    vsrv_ncenter_close_notification(g_medply.ncenter_nhandle);
    vsrv_ncenter_close_ngroup(g_medply.ncenter_ghandle);
    g_medply.ncenter_ghandle = NULL;
}
#endif


#define MAIN_LIST_AND_APP_INIT
void mmi_medply_app_pre_entry(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_read_settings
 * DESCRIPTION
 *  read settings from nvram while init application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_read_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /*volume*/
    ReadValue(NVRAM_MEDIA_PLAYER_VOLUME, &g_medply.volume, DS_BYTE, &error);
    if(g_medply.volume > MDI_AUD_VOL_EX_MUTE_MAX)
    {
        g_medply.volume = MDI_AUD_VOL_EX_7 ;
    }


    /*mute*/
    ReadValue(NVRAM_MEDIA_PLAYER_MUTE, &g_medply.mute, DS_BYTE, &error);
    if(g_medply.mute == 0xff)
    {
        g_medply.mute = MMI_FALSE;
    }
    if((!g_medply.mute) && (MDI_AUD_VOL_EX_MUTE_MIN == g_medply.volume))
    {
        g_medply.mute = MMI_TRUE;
    }

    /*snap shot number*/
#ifdef __MMI_MEDIA_PLAYER_SNAPSHOT__
    ReadValue(NVRAM_MEDPLY_SNAPSHOT_SEQ_NO, &g_medply.filename_seq_no, DS_SHORT, &error);
#endif

    /*settings*/
    mmi_medply_init_settings();

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_ENTRY_READ_SETTINGS,g_medply.volume,g_medply.mute);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_asm_delete
 * DESCRIPTION
 *  delete asm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_asm_delete(void)
{
	U32 asm_total_left_size = 0;
    /* delete adm */
    if (g_medply.adm_id_p != NULL)
    {
    	asm_total_left_size = kal_adm_get_total_left_size(g_medply.adm_id_p);
        if (asm_total_left_size != total_asm_memory)
	    {
	        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MAIN_ASM_DELETE,total_asm_memory, asm_total_left_size);
	    }
        
        kal_adm_delete(g_medply.adm_id_p);
        g_medply.adm_id_p = NULL;
    }


    if(g_medply.medply_adm_id_p != NULL)
    {
        kal_adm_delete(g_medply.medply_adm_id_p);
        g_medply.medply_adm_id_p = NULL;
    }

    /* free asm */
#if defined(__MMI_VUI_3D_CUBE_APP_MEDIA_PLAYER__) || defined(__MMI_VUI_SHELL_MEDIA_PLAYER__)
    g_medply.mem_pool_p = NULL;
#else
    if (g_medply.mem_pool_p != NULL)
    {
        mmi_frm_asm_free_r(APP_MEDPLY, g_medply.mem_pool_p);
        g_medply.mem_pool_p = NULL;
    }
#endif /* defined(__MMI_VUI_3D_CUBE_APP_MEDIA_PLAYER__) || defined(__MMI_VUI_SHELL_MEDIA_PLAYER__) */
/* Remove the media player item from NCenter as media player is not running in background */
#ifdef __MMI_NCENTER_SUPPORT__
    mmi_medply_ncenter_clear_app_item();
#endif
    /* clear screen locker key handler callback when leave media player */
    mmi_scr_locker_clear_locked_key_callback();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_app_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_app_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 bg_play = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_APP_EXIT);
    /* always update settings NVRAM LID when media player exit */
    mmi_medply_settings_write_value_ext(MMI_MEDPLY_SETTINGS_TYPE_ALL, NULL, MMI_TRUE);

/* check the value of setting item "background play".
   release all memory and delete ASM if its value is OFF. */
    if (!mmi_medply_settings_read_value(
        MMI_MEDPLY_SETTINGS_BG_PLAY, 
        &bg_play))
    {
        bg_play = 0;
    }

    if (!bg_play)
    {
        // TODO: need release all ASM memory here.
        g_medply.media_type = MEDPLY_TYPE_NONE;
        mmi_medply_stop_playing();
        mmi_medply_plst_module_deinit();

        mmi_medply_asm_delete();
        return;
    }
#ifdef __MMI_NCENTER_SUPPORT__
    /* If the ASM is freed then no need to add app item in NCenter or */
    if (g_medply.mem_pool_p != NULL)
    {
        /* If Current list is not valid (card removed) then no point in adding app in NCenter */
        if (mmi_medply_plst_curr_is_valid() == MMI_TRUE)
        {
            mmi_medply_ncenter_add_app_item();
        }
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_asm_stop_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_asm_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_ASM_STOP_CALLBACK);

    if (g_gid_medply != GRP_ID_INVALID)
    {
        mmi_frm_group_close(g_gid_medply);
    }
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    mmi_medply_setting_deinit_hdlr();
    mmi_medply_plst_module_deinit();
    mmi_medply_stop_playing();

    mmi_medply_asm_delete();
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_MEDPLY, KAL_TRUE);
#ifdef __MMI_NCENTER_SUPPORT__
    mmi_medply_ncenter_clear_app_item();
#endif
}

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
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_check_if_need_hide_OP_link
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_check_if_no_network_link(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL need_hide = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_TELEPHONY_SUPPORT__)
    if (srv_mode_switch_is_network_service_available() == MMI_FALSE)
    {
        need_hide = MMI_TRUE;
    }
    else
#endif  /* __FLIGHT_MODE_SUPPORT__ */
    {
    #if (MMI_MAX_SIM_NUM == 1)
        if (!srv_sim_ctrl_is_available(MMI_SIM1))
        {
            need_hide = MMI_TRUE;
        }
    #else   /* __MMI_DUAL_SIM_MASTER__ */
        if (srv_sim_ctrl_is_available(MMI_SIM1))
        {
            if (srv_sim_ctrl_is_available(MMI_SIM2))
            {
                need_hide = MMI_FALSE;
            }
            else
            {
            	/* only sim 1 is exist. */
                if (srv_mode_switch_get_network_mode(MMI_SIM2) == SRV_MODE_SWITCH_ON)
                {
                    need_hide = MMI_TRUE;
                }
                else
                {
                    need_hide = MMI_FALSE;
                }
            }
        }
        else if (srv_sim_ctrl_is_available(MMI_SIM2))
        {
            /* only sim 2 exist. */
            if (srv_mode_switch_get_network_mode(MMI_SIM1) == SRV_MODE_SWITCH_ON)
            {
                need_hide = MMI_TRUE;
            }
            else
            {
                /* no need hide. */
                need_hide = MMI_FALSE;
            }
        }
        else
        {
            /* no sim card, always hide. */
            need_hide = MMI_TRUE;
        }
    #endif  /* __MMI_DUAL_SIM_MASTER__ */
    
    #if defined(__MMI_WLAN_FEATURES__)
        if (need_hide)
        {
            if (P_GSM_ONLY == mmi_netset_get_active_preferred_mode())
            {
                need_hide = MMI_TRUE;
            }
            else
            {
                need_hide = MMI_FALSE;
            }
        }    
    #endif
    }
    return need_hide;
}


#ifndef __MMI_MEDIA_PLAYER_PLST_DB_STYLE__

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_main_menu_option_config
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_main_menu_option_config(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_MAIN_SCREEN_OPTION_CURRENT_LIST, MMI_TRUE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_MAIN_SCREEN_OPTION_DETAILS, MMI_TRUE);

    if (mmi_medply_plst_curr_is_valid())
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_MAIN_SCREEN_OPTION_CURRENT_LIST, MMI_FALSE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_MAIN_SCREEN_OPTION_DETAILS, MMI_FALSE);
    }

    if (mmi_medply_plst_curr_is_empty())
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_MAIN_SCREEN_OPTION_DETAILS, MMI_TRUE);
    }
    
    cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_MEDPLY_SETTINGS, MMI_FALSE);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_entry_main_menu_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_entry_main_menu_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_gid = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_ENTRY_MAIN_MENU_OPTION);
    mmi_frm_group_create(GRP_ID_MEDPLY_MAIN_SCREEN, GRP_ID_MEDPLY_MAIN_SCREEN_OPTION, mmi_medply_event_proc, (void*)GRP_ID_MEDPLY_MAIN_SCREEN_OPTION); 

    mmi_frm_group_enter(GRP_ID_MEDPLY_MAIN_SCREEN_OPTION, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_gid = cui_menu_create(
                            GRP_ID_MEDPLY_MAIN_SCREEN_OPTION,
                            CUI_MENU_SRC_TYPE_RESOURCE,
                            CUI_MENU_TYPE_OPTION,
                            MENU_ID_MEDPLY_MAIN_SCREEN_OPTION,
                            MMI_FALSE, NULL);
    if (cui_gid > GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)));
        cui_menu_run(cui_gid);
    }
    else
    {   
        mmi_medply_display_popup_with_sg(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
    }

}

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
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_app_prepare
 * DESCRIPTION
 *  mediaplay initialization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_app_prepare(mmi_medply_main_entry_enum entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    void* adm_p_plst = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_APP_PRE_ENTRY);

#if defined(__USB_IN_NORMAL_MODE__)
    if (srv_usb_is_in_mass_storage_mode())
    {
        MMI_STR_ID string_id = 0;
        mmi_event_notify_enum event_type = MMI_EVENT_DEFAULT;
        string_id = mmi_usb_get_error_info(SRV_USB_ERROR_UNAVAILABLE, &event_type);
        mmi_medply_display_popup_with_sg((U16)string_id, event_type);
        mmi_frm_app_close(APP_MEDPLY);
        return -1;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 

    g_gid_medply = GRP_ID_MEDPLY;
    if (!mmi_frm_group_is_present(g_gid_medply))
    {
        mmi_frm_group_create(APP_MEDPLY, g_gid_medply, mmi_medply_event_proc, (void *)g_gid_medply);
        mmi_frm_group_enter(g_gid_medply, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
    /* set App-based ASM. */
    if (g_medply.mem_pool_p == NULL)
    {
	g_medply.mem_pool_p = mmi_frm_asm_alloc_r(APP_MEDPLY, MMI_MEDPLY_MEM_POOL_SIZE);
	MMI_ASSERT(g_medply.mem_pool_p);
    }
    
    if(g_medply.medply_adm_id_p == NULL)
    {
        g_medply.medply_adm_id_p = kal_adm_create(g_medply.mem_pool_p, MMI_MEDPLY_MEM_POOL_SIZE, NULL, KAL_FALSE);
        MMI_ASSERT(g_medply.medply_adm_id_p != NULL);
        adm_p_plst = kal_adm_alloc(g_medply.medply_adm_id_p,MEDPLY_PLST_APP_MEM_SIZE);
        MMI_ASSERT(adm_p_plst != NULL);
    }

    if (g_medply.adm_id_p == NULL)
    {
        g_medply.adm_id_p = kal_adm_create(adm_p_plst, MEDPLY_PLST_APP_MEM_SIZE, NULL, KAL_FALSE);
        MMI_ASSERT(g_medply.adm_id_p != NULL);
        /*check memory leak*/
        total_asm_memory = kal_adm_get_total_left_size(g_medply.adm_id_p);
        /* do initialization in this function, like module init or ASM allocate. */
        ret = mmi_medply_plst_module_init();
        if (ret < 0)
        {
        #if defined(__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
            if (ret == MEDPLY_PLST_ERR_SQLITE_CORRUPT ||
                ret == MEDPLY_PLST_ERR_SQLITE_FORMAT)
            {
                mmi_medply_plst_module_corrupt_scr();
                mmi_frm_group_close(GRP_ID_MEDPLY_PLST_COMMON_WAIT_SCREEN);
            }
            else
            {
                mmi_medply_plst_popup_simple(ret);
                mmi_frm_group_close(GRP_ID_MEDPLY_PLST_COMMON_WAIT_SCREEN);
                mmi_medply_asm_delete();
            }

        #else
            {
                mmi_medply_plst_popup_simple(ret);
                mmi_medply_asm_delete();
            }
        #endif /*__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__*/

            return -1;
        }
        else
        {
            /* try ro load last playlist status. */
            mmi_medply_plst_load_last();
        }
    }

#ifdef __MMI_NCENTER_SUPPORT__
    mmi_medply_ncenter_clear_app_item();
#endif


    if (g_medply.state == MEDPLY_STATE_IDLE)
    {
        mmi_medply_plst_apply_picked_file();
        mmi_medply_util_fill_idle_display_str();

        switch(g_medply.media_type)
        {
            case MEDPLY_TYPE_AUDIO:
            {
                g_medply.state = MEDPLY_STATE_AUDIO_READY;
                break;
            }

            case MEDPLY_TYPE_VIDEO:
            {
                g_medply.state = MEDPLY_STATE_PURE_AUDIO_READY;
                break;
            }

            case MEDPLY_TYPE_STREAM:
            {
                g_medply.state = MEDPLY_STATE_STREAM_IDLE;
                break;
            }

            default:
            {
                break;
            }
        }
    }	
    return ret;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_main_list_delete_history_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void*   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_app_unprepare(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_app_exit();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_app_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_app_entry(mmi_medply_main_entry_enum entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = mmi_medply_app_prepare(entry);
    if (result < 0)
    {
        return;
    }

    g_gid_medply = GRP_ID_MEDPLY;
    if (!mmi_frm_group_is_present(g_gid_medply))
    {
        mmi_frm_group_create(APP_MEDPLY, g_gid_medply, mmi_medply_event_proc, (void *)g_gid_medply);
        mmi_frm_group_enter(g_gid_medply, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    switch (entry)
    {
        case MMI_MEDPLY_ENTRY_MAINSCRN:
        {
            mmi_medply_entry_main();
            break;
        }
        case MMI_MEDPLY_ENTRY_LISTMGR:
        {
            mmi_medply_plst_entry_listmgr();
            break;
        }
        case MMI_MEDPLY_ENTRY_MAINMENU:
        default:
        {
            mmi_medply_entry_main_menu();
            break;
        }
            
    }

//#if defined(__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
    /* delete initialize notify screen in database style. */
    //DeleteScreenIfPresent(SCR_ID_MEDPLY_PLST_COMMON_WAIT_SCREEN);
//#endif /*__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__*/

    }
        
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_app_entry_mscr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void mmi_medply_entry_mscr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_app_entry(MMI_MEDPLY_ENTRY_MAINSCRN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_app_entry_listmgr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern void mmi_medply_app_entry_listmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_app_entry(MMI_MEDPLY_ENTRY_LISTMGR);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_mainmenu_config
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void*   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_mainmenu_config(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_medply.reset_menu)
    {
        cui_menu_set_currlist_highlighted_id(menu_evt->sender_id, MENU_ID_MEDPLY_MAIN_MENU_NOW_PLAYING);
        g_medply.reset_menu = MMI_FALSE;
    }
    
    if (mmi_medply_check_if_no_network_link())
    {
#if defined(__MMI_MEDIA_PLAYER_STREAM__)
#if defined(__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_MAIN_MENU_BOOKMARK, MMI_TRUE);
#elif defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__)
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_BOOKMARK_MENU, MMI_TRUE);
#endif
#endif  /* __MMI_MEDIA_PLAYER_STREAM__ */



    //@TODO: need to check if can remove the following

        
    }
    else
    {
#if defined(__MMI_MEDIA_PLAYER_STREAM__)
#if defined(__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_MAIN_MENU_BOOKMARK, MMI_FALSE);
#elif defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__)
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_BOOKMARK_MENU, MMI_FALSE);
#endif
#endif  /* __MMI_MEDIA_PLAYER_STREAM__ */



    //@TODO: need to check if can remove the following
    
    }

#if defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__)
    #if defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__)
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_MAIN_MENU_ALL_AUDIO, MMI_FALSE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_MAIN_MENU_ALL_VIDEO, MMI_FALSE);
    #else
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_MAIN_MENU_ALL_AUDIO, MMI_TRUE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_MAIN_MENU_ALL_VIDEO, MMI_TRUE);
    #endif /* __MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__ */
#endif /* __MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__ */

    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS );
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_event_proc
 * DESCRIPTION
 *  Screen group callback process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_medply_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(evt->evt_id)
    {
/*************************MediaPlayer Internal event***************************/
        case EVT_ID_MEDPLY_RESET_MAINMENU:
        {
            g_medply.reset_menu = MMI_TRUE;
            break;
        }
        case EVT_ID_MEDPLY_POPUP_ALL_FILE_FAIL:
        {
            mmi_medply_display_popup_for_all_file_fail();
            break;
        }
            
/*************************Screen Group event***************************/
        case EVT_ID_GROUP_DEINIT: // framework de-init the group
        {
            if (evt->user_data == (void *)g_gid_medply)
            {
                mmi_medply_app_unprepare();
            }
            break;
        }
        case EVT_ID_SCRN_INACTIVE:
            break;

/*************************Menu CUI event***************************/
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;

            if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_MAIN_LIST)
            {
                mmi_medply_mainmenu_config(menu_evt);
            }
        
            else if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_MAIN_SCREEN_OPTION)
            {
                mmi_medply_main_menu_option_config(menu_evt);
            }
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;

            if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_MAIN_LIST)
            {
                switch(menu_evt->highlighted_menu_id)
                {
                
                    case MENU_ID_MEDPLY_MAIN_MENU_NOW_PLAYING:
                        mmi_medply_entry_main();
                        break;
                #if defined(__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
                    case MENU_ID_MEDPLY_MAIN_MENU_ALL_MEDIA:
                        mmi_medply_plstui_allmedia_entry();
                        break;
                #endif /*__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__*/
                    case MENU_ID_MEDPLY_MAIN_MENU_MY_PLAYLIST:
                        mmi_medply_plst_entry_listmgr();
                        break;
                #if defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__)
                    case MENU_ID_MEDPLY_MAIN_MENU_ALL_AUDIO:
                        mmi_medply_plst_entry_all_audio();
                        break;
                    case MENU_ID_MEDPLY_MAIN_MENU_ALL_VIDEO:
                        mmi_medply_plst_entry_all_video();
                        break;
                #endif /* __MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__ */
                #if defined(__MMI_MEDIA_PLAYER_STREAM__)
                #if defined(__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
                    case MENU_ID_MEDPLY_MAIN_MENU_BOOKMARK:
                        mmi_medply_plst_entry_bookmark();
                        break;
                #elif defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__)
                    case MENU_ID_MEDPLY_BOOKMARK_MENU:
                        mmi_medply_plst_entry_bookmark();
                        break;
                #endif /*__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__*/
                #endif  /* __MMI_MEDIA_PLAYER_STREAM__ */
                    default:
                        break;
                }
            }
            else if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_MAIN_SCREEN_OPTION)
            {
                switch(menu_evt->highlighted_menu_id)
                {
                    case MENU_ID_MEDPLY_MAIN_SCREEN_OPTION_CURRENT_LIST:
                        mmi_medply_plst_entry_now_playing();
                        //cui_menu_close(menu_evt->sender_id);
                        break;
                #if defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__)
                    case MENU_ID_MEDPLY_OPTION_GO_TO_LIB:
                        mmi_medply_plst_gobacktomain();
                        cui_menu_close(menu_evt->sender_id);
                        break;
                #endif /*__MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__*/    
                    case MENU_ID_MEDPLY_SETTINGS:
                        mmi_medply_settings_entry_main();
                        break;
                    case MENU_ID_MEDPLY_MAIN_SCREEN_OPTION_DETAILS:
                        mmi_medply_plst_entry_details();
                        break;
                    #if defined(__MMI_MEDIA_PLAYER_VDOREC__)
                    case MENU_ID_MEDPLY_MAIN_SCREEN_OPTION_VDOREC:
                        mmi_medply_entry_video_recoder();
                        break;
                    #endif
                    default:
                        break;
                }
            }
            break;
        }
        case EVT_ID_CUI_MENU_LIST_EXIT:
        {

            break;
        }
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;

            cui_menu_close(menu_evt->sender_id);
                break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_entry_main_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_entry_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_gid = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_MAIN_LIST, mmi_medply_event_proc, (void*)GRP_ID_MEDPLY_MAIN_LIST); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_MAIN_LIST, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_gid = cui_menu_create(
                            GRP_ID_MEDPLY_MAIN_LIST,
                            CUI_MENU_SRC_TYPE_RESOURCE,
                            CUI_MENU_TYPE_APPMAIN,
                            MENU_ID_MEDPLY_MAIN_LIST,
                            MMI_FALSE, NULL);
    if (cui_gid > GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)));
        cui_menu_run(cui_gid);
    }
    else
    {   
        mmi_medply_display_popup_with_sg(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
    }
#if defined(__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
    mmi_frm_group_close(GRP_ID_MEDPLY_PLST_COMMON_WAIT_SCREEN);
#endif
    
}
#else /* __MMI_MEDIA_PLAYER_PLST_DB_STYLE__ */

extern void mmi_medply_entry_main_menu_scr(void);
static mmi_ret mmi_medply_fte_proc(mmi_event_struct *evt);
static mmi_ret mmi_medply_fte_sub_menu_proc(mmi_event_struct *evt);
static MMI_BOOL mmi_medply_app_prepare(mmi_medply_main_entry_enum entry);


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_app_pre_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_medply_app_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_APP_PRE_ENTRY);
    ret = mmi_medply_app_prepare(MMI_MEDPLY_ENTRY_MAINMENU);
    if(MMI_FALSE == ret)
    {
        return;
    }
    
    mmi_medply_entry_main_menu();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_app_entry_mscr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void mmi_medply_entry_mscr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    MMI_ID gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_medply_app_prepare(MMI_MEDPLY_ENTRY_MAINMENU);
    if(ret == MMI_FALSE)
    {
        return;
    }
    
    g_gid_medply = GRP_ID_MEDPLY_FTE_SUB_MENU;
    gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_MEDPLY_FTE_SUB_MENU, mmi_medply_fte_sub_menu_proc, NULL);
    if(GRP_ID_INVALID == gid)
    {
        return;
    }
    
    gid = mmi_frm_group_enter(GRP_ID_MEDPLY_FTE_SUB_MENU, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if(GRP_ID_INVALID == gid)
    {
        return;
    }
    
    mmi_medply_entry_main();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_app_entry_listmgr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern void mmi_medply_app_entry_listmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*dummy function*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_app_prepare
 * DESCRIPTION
 *  mediaplay initialization
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_medply_app_prepare(mmi_medply_main_entry_enum entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    void* adm_p_plst = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_APP_PRE_ENTRY);

#if defined(__USB_IN_NORMAL_MODE__)
    if (srv_usb_is_in_mass_storage_mode())
    {
        MMI_STR_ID string_id = 0;
        mmi_event_notify_enum event_type = MMI_EVENT_DEFAULT;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_MASS_STORAGE_MODE);
        string_id = mmi_usb_get_error_info(SRV_USB_ERROR_UNAVAILABLE, &event_type);
        mmi_medply_display_popup_with_sg((U16)string_id, event_type);
        mmi_frm_app_close(APP_MEDPLY);
        mmi_medply_shell_clear_play_callback();
        return MMI_FALSE;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 

    /* set App-based ASM. */
#if defined(__MMI_VUI_3D_CUBE_APP_MEDIA_PLAYER__) || defined(__MMI_VUI_SHELL_MEDIA_PLAYER__)
    g_medply.mem_pool_p = g_medply_mem_pool;
#else /* defined(__MMI_VUI_3D_CUBE_APP_MEDIA_PLAYER__) || defined(__MMI_VUI_SHELL_MEDIA_PLAYER__) */
    if (g_medply.mem_pool_p == NULL)
    {
	g_medply.mem_pool_p = mmi_frm_asm_alloc_r(APP_MEDPLY, MMI_MEDPLY_MEM_POOL_SIZE);
    }
#endif /* defined(__MMI_VUI_3D_CUBE_APP_MEDIA_PLAYER__) || defined(__MMI_VUI_SHELL_MEDIA_PLAYER__) */    
    MMI_ASSERT(g_medply.mem_pool_p != NULL);

        if(g_medply.medply_adm_id_p == NULL)
        {
            g_medply.medply_adm_id_p = kal_adm_create(g_medply.mem_pool_p, MMI_MEDPLY_MEM_POOL_SIZE, NULL, KAL_FALSE);
            MMI_ASSERT(g_medply.medply_adm_id_p != NULL);
            /*adm_p_plst = kal_adm_alloc(g_medply.medply_adm_id_p,MEDPLY_PLST_APP_MEM_SIZE);*/
            adm_p_plst = kal_adm_alloc(g_medply.medply_adm_id_p,MEPDLY_PLST_COMMON_APP_MEM_SIZE);
            MMI_ASSERT(adm_p_plst != NULL);
        }

        if (g_medply.adm_id_p == NULL)
        {
            /*g_medply.adm_id_p = kal_adm_create(adm_p_plst, MEDPLY_PLST_APP_MEM_SIZE, NULL, KAL_FALSE);*/
            g_medply.adm_id_p = kal_adm_create(adm_p_plst, MEPDLY_PLST_COMMON_APP_MEM_SIZE, NULL, KAL_FALSE);
            MMI_ASSERT(g_medply.adm_id_p != NULL);
            /*check memory leak*/
            total_asm_memory = kal_adm_get_total_left_size(g_medply.adm_id_p);
	        /* do initialization in this function, like module init or ASM allocate. */
            ret = mmi_medply_plst_module_init();
            if (ret >= 0)
            {
                /* try ro load last playlist status. */
                mmi_medply_plst_load_last();
            }
        }

        
       #ifdef __MMI_NCENTER_SUPPORT__
           mmi_medply_ncenter_clear_app_item();
       #endif
        /* move from mmi_medply_app_entry() */
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_APP_ENTRY);
        return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_entry_main_menu
 * DESCRIPTION
 *  Entry media player screen group
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_entry_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gid_medply = GRP_ID_MEDPLY_FTE;
    mmi_frm_group_create(APP_MEDPLY, g_gid_medply, mmi_medply_fte_proc, NULL);
    mmi_frm_group_enter(GRP_ID_MEDPLY_FTE, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    /* Clear main menu cui group id to invalid and set after created */
    mmi_medply_listui_set_main_menu_cui_grp_id(GRP_ID_INVALID);

    if (!mmi_medply_listui_allow_entry_main_menu())
    {
        mmi_medply_listui_library_open_fail(0);
        return;
    }

    mmi_medply_entry_main_menu_scr();   
}


/*for Media player FTE stye entry main menu */
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_entry_main_menu_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_entry_main_menu_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Use menu cui to display manin menu */
    menu_gid = cui_menu_create(GRP_ID_MEDPLY_FTE, 
                               CUI_MENU_SRC_TYPE_RESOURCE,
                               CUI_MENU_TYPE_FROM_RESOURCE,
                               MENU_ID_MEDPLY_FTE_MAIN_LIST,
                               MMI_TRUE,
                               (void*)MEDPLY_MENU_CUI_MAIN_MENU);
    if (menu_gid > GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(menu_gid, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)));
        cui_menu_run(menu_gid);
    }
    else
    {   
        mmi_medply_display_popup_with_sg(STR_GLOBAL_NOT_AVAILABLE, MMI_EVENT_FAILURE);
    }

    /* keep main menu CUI group id */
    mmi_medply_listui_set_main_menu_cui_grp_id(menu_gid);

    /* Set state when enter application */
    if (g_medply.state == MEDPLY_STATE_IDLE)
    {
        mmi_medply_plst_apply_picked_file();
        mmi_medply_util_fill_idle_display_str();

        switch(g_medply.media_type)
        {
            case MEDPLY_TYPE_AUDIO:
            {
                g_medply.state = MEDPLY_STATE_AUDIO_READY;
                break;
            }

            case MEDPLY_TYPE_VIDEO:
            {
                g_medply.state = MEDPLY_STATE_PURE_AUDIO_READY;
                break;
            }

            case MEDPLY_TYPE_STREAM:
            {
                g_medply.state = MEDPLY_STATE_STREAM_IDLE;
                break;
            }

            default:
            {
                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_fte_main_menu_cui_proc
 * DESCRIPTION
 *  Screen group callback process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_medply_fte_main_menu_cui_proc(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            /* Back to main menu in main group  */
            g_gid_medply = GRP_ID_MEDPLY_FTE;

            /* Use number as menu icon */
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

            /* Hide unnecessary menu for shell */
            if(mmi_medply_shell_is_registered())
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_NOW_PLAYING, MMI_TRUE);
            #if defined(__MMI_MEDIA_PLAYER_STREAM__) || defined (__MMI_MEDIA_PLAYER_VIDEO__)
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_ALL_VIDEO_LIST, MMI_TRUE);
            #endif
            //Astro
            #ifdef MMI_MEDPLY_FTE_SUPPORT_INPUT_URL
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_INPUT_URL, MMI_TRUE);
            #endif
                //cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_REFRESH_LIB, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_SETTINGS, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_RESET_LIB, MMI_TRUE);
            }
            else
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_NOW_PLAYING, MMI_FALSE);
            #if defined(__MMI_MEDIA_PLAYER_STREAM__) || defined (__MMI_MEDIA_PLAYER_VIDEO__)
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_ALL_VIDEO_LIST, MMI_FALSE);
            #endif
            //Astro
            #ifdef MMI_MEDPLY_FTE_SUPPORT_INPUT_URL
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_INPUT_URL, MMI_FALSE);
            #endif
                //cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_REFRESH_LIB, MMI_FALSE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_SETTINGS, MMI_FALSE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_FTE_RESET_LIB, MMI_FALSE);

            }
            mmi_medply_listui_reg_motion();
            break;

        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            /* Enter menu subgroup */
            g_gid_medply = GRP_ID_MEDPLY_FTE_SUB_MENU;

            /* Enter submenu screen group */
            mmi_frm_group_create(GRP_ID_MEDPLY_FTE, GRP_ID_MEDPLY_FTE_SUB_MENU, mmi_medply_fte_sub_menu_proc, NULL);
            mmi_frm_group_enter(GRP_ID_MEDPLY_FTE_SUB_MENU, MMI_FRM_NODE_SMART_CLOSE_FLAG);

            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_MEDPLY_FTE_NOW_PLAYING:
                    mmi_medply_entry_main();
                    break;
                case MENU_ID_MEDPLY_FTE_ALL_AUDIO_LIST:
                    mmi_medply_listui_entry_all_song_list();
                    break;
                case MENU_ID_MEDPLY_FTE_ARTIST_LIST:
                    mmi_medply_listui_entry_artist_list();
                    break;
                case MENU_ID_MEDPLY_FTE_ALBUM_LIST:
                    mmi_medply_listui_entry_album_list();
                    break;
                case MENU_ID_MEDPLY_FTE_GENRE_LIST:
                    mmi_medply_listui_entry_genre_list();
                    break;
                case MENU_ID_MEDPLY_FTE_PLAYLIST_LIST:
                    mmi_medply_listui_entry_plst_list();
                    break;
            #if defined(__MMI_MEDIA_PLAYER_STREAM__) || defined (__MMI_MEDIA_PLAYER_VIDEO__)
                case MENU_ID_MEDPLY_FTE_ALL_VIDEO_LIST:
                    mmi_medply_listui_entry_all_video_list();
                    break;
            #endif /* __MMI_MEDIA_PLAYER_VIDEO__ */
            //Astro
            #ifdef MMI_MEDPLY_FTE_SUPPORT_INPUT_URL
                case MENU_ID_MEDPLY_FTE_INPUT_URL:
                    mmi_medply_listui_entry_input_url();
                    break;
            #endif
                case MENU_ID_MEDPLY_FTE_REFRESH_LIB:
                    mmi_medply_listui_entry_refresh_lib();
                    break;
                case MENU_ID_MEDPLY_FTE_SETTINGS:
                    mmi_medply_settings_entry_main();
                    break;
                case MENU_ID_MEDPLY_FTE_RESET_LIB:
                    mmi_medply_listui_reset_lib_req();
                    break;
                default:
                    break;
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

        case EVT_ID_CUI_MENU_LIST_DEINIT:
            mmi_medply_listui_dereg_motion();
            /* Delete all setting screen, seems no need to call this if the parent group of setting is GRP_ID_MEDPLY_FTE*/
            mmi_medply_del_all_app_screen();

            mmi_meply_plst_reset_all();
            mmi_medply_app_exit();

            /* Close all media player screen and CUI in the group */
            mmi_frm_group_close(GRP_ID_MEDPLY_FTE);
            
            /* Set group id to invalid */
            mmi_medply_listui_set_main_menu_cui_grp_id(GRP_ID_INVALID);

            /* No need to close menu CUI here due to we already call mmi_frm_group_close() */

            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_fte_proc
 * DESCRIPTION
 *  Screen group callback process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_medply_fte_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;
    S32 menu_level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check if menu cui's event */
    if(cui_menu_is_menu_event(evt->evt_id))
    {
        menu_evt = (cui_menu_event_struct*)evt;

        menu_level = (S32)menu_evt->app_data;
        switch (menu_level)
        {
            case MEDPLY_MENU_CUI_MAIN_MENU:
                return mmi_medply_fte_main_menu_cui_proc(menu_evt);

            default:
                break;
        }

        return MMI_RET_OK;
    }

    /* Screen group event */
    switch(evt->evt_id)
    {
    case EVT_ID_GROUP_DEINIT:
        /*mmi_medply_listui_dereg_motion();*/
        mmi_medply_shell_clear_play_callback();
        mmi_medply_listui_set_goback_inendkey(MMI_FALSE);
        break;
    case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        mmi_medply_listui_dereg_motion();
        mmi_medply_listui_set_goback_inendkey(MMI_TRUE);
        break;
    default:
        break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_fte_sub_menu_proc
 * DESCRIPTION
 *  Screen group callback process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_medply_fte_sub_menu_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;
    S32 menu_level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check if menu cui's event */
    if(cui_menu_is_menu_event(evt->evt_id))
    {
        menu_evt = (cui_menu_event_struct*)evt;

        menu_level = (S32)menu_evt->app_data;
        switch (menu_level)
        {
            case MEDPLY_MENU_CUI_PLAYER_SCREEN_OPT:
                return mmi_medply_fte_player_option_cui_proc(menu_evt);

            case MEDPLY_MENU_CUI_FILE_LIST_OPT:
                return mmi_medply_listui_song_list_option_cui_proc(menu_evt);

            case MEDPLY_MENU_CUI_TYPE_LIST_OPT:
                return mmi_medply_listui_type_list_option_cui_proc(menu_evt);

            case MEDPLY_MENU_CUI_PLST_LIST_OPT:
                return mmi_medply_listui_plst_list_option_cui_proc(menu_evt);

            case MEDPLY_MENU_CUI_MULTISEL_LIST_OPTION:
                return mmi_medply_listui_multisel_option_cui_proc(menu_evt);

            case MEDPLY_MENU_CUI_MULTIADD_LIST_OPTION:
                return mmi_medply_listui_multiadd_option_cui_proc(menu_evt);

        #ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
            case MEDPLY_MENU_CUI_FILE_LIST_SEARCH_OPT:
                return mmi_medply_listui_song_list_search_option_cui_proc(menu_evt);

            case MEDPLY_MENU_CUI_TYPE_LIST_SEARCH_OPT:
                return mmi_medply_listui_type_list_search_option_cui_proc(menu_evt);
        #endif

            default:
                break;
        }

        return MMI_RET_OK;
    }

    /* Editor CUI Event */
    if(evt->evt_id >= EVT_ID_CUI_FSEDITOR_SUBMMIT && evt->evt_id <= EVT_ID_CUI_FSEDITOR_MAX)
    {
        return mmi_medply_listui_editor_cui_proc(evt);
    }

    /* Inline CUI Event */
#ifdef __MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__
    if(evt->evt_id >= EVT_ID_CUI_INLINE_SUBMIT && evt->evt_id <= EVT_ID_CUI_INLINE_MAX)
    {
        return mmi_medply_listui_inline_cui_proc(evt);
    }
#endif
    /* Screen group event */
    switch(evt->evt_id)
    {
    case EVT_ID_GROUP_DEINIT:
        break;
    case EVT_ID_SCRN_INACTIVE:
        break;
#if defined(__MMI_FILE_MANAGER__)
    case EVT_ID_CUI_FILE_SELECTOR_RESULT:
    {
        mmi_medlpy_listui_fmgr_res_handle((cui_file_selector_result_event_struct*) evt);
        break;
    }
#endif
    default:
        break;
    }
    return MMI_RET_OK;
}


void (*g_medply_shell_play_callback)(void);
void mmi_medply_shell_set_play_callback(void (*callback)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_medply_shell_play_callback = callback;
}

void mmi_medply_shell_clear_play_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_medply_shell_play_callback = NULL;
}

MMI_BOOL mmi_medply_shell_is_registered(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_medply_shell_play_callback != NULL) ? MMI_TRUE : MMI_FALSE;
}

void mmi_medply_shell_play_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void (*shell_play_callback_temp)(void);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_medply_shell_play_callback != NULL)
    {
        shell_play_callback_temp = g_medply_shell_play_callback;
        shell_play_callback_temp();
        mmi_frm_group_close(GRP_ID_MEDPLY_FTE);
    }
}

#endif /*__MMI_MEDIA_PLAYER_PLST_DB_STYLE__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_INIT_APP);

    /*register app mem*/
    applib_mem_ap_register(
        APPLIB_MEM_AP_ID_MEDPLY, 
        STR_ID_MEDPLY_APP_TITLE, 
        IMG_ID_MEDPLY_ICON,
        mmi_medply_asm_stop_callback);

    /*load image viewer setting for snap shot directory*/
#ifdef __MMI_IMAGE_VIEWER__
    mmi_imgview_load_setting();
#endif

    /*load media player settings*/
    mmi_medply_read_settings();

    g_medply.mem_pool_p = NULL;
    g_medply.adm_id_p = NULL;

    g_medply.medply_adm_id_p = NULL;

    /* init playlist module's highlight handler. */
    mmi_medply_plst_hilite_hdlr_init();

    /*context init*/
    g_medply.current_time = 0;
#if defined (__DRM_SUPPORT__) || defined (__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__)
    g_medply.DRM_consumed = MMI_FALSE;
#endif

    g_medply.selected_button = MEDPLY_MAIN_PLAY;

#ifdef __MMI_MEDIA_PLAYER_SNAPSHOT__
    g_medply.enable_snapshot = MMI_TRUE;
#endif

#if defined(__MMI_MEDIA_PLAYER_A2DP_BLOCK_SPECTRUM__) 
    g_medply.A2DP_blocked = MMI_FALSE;
#endif

#ifdef MOTION_SENSOR_SUPPORT
    //g_medply.shake_handle = -1;
    g_medply.tilt_handle = -1;
#endif

    g_medply.fs_error_pop_up = MMI_TRUE;    /* For the first time show popup */

#ifdef __MMI_MEDIA_PLAYER_AUDIO__
    mmi_medply_initialize_cache();
    /*reset medv build cache variables*/
    mdi_audio_reset_build_cache_variables();
#endif


    /*BT callback init*/
#ifdef __MMI_A2DP_SUPPORT__
    av_bt_set_default_callback(mmi_medply_bt_open_callback);
#endif

#ifdef __MMI_AVRCP_SUPPORT__
    mmi_bt_avrcp_set_cmd_hdlr(mmi_medply_bt_avrcp_cmd_hdlr);
#endif 

    /*single player init*/
    mmi_medply_init_single_app();

    /*main screen init*/
    mmi_medply_main_screen_init();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_terminate_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_terminate_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_stop_playing();


}

#define HIGHLIGHT_HANDLER
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_highlight_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_highlight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_medply_app_pre_entry, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#ifndef __MMI_WGUI_DISABLE_CSK__
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
    SetCenterSoftkeyFunction(mmi_medply_app_pre_entry, KEY_EVENT_UP);
}

//can removed the following hightlight handler for multiple and db style
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_highlight_my_playlists
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_highlight_player_option_playlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetLeftSoftkeyFunction(mmi_medply_plst_entry_now_playing, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
    SetCenterSoftkeyFunction(mmi_medply_plst_entry_now_playing, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_highlight_player_option_details
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_highlight_player_option_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_medply_plst_entry_details, KEY_EVENT_UP);
#ifndef __MMI_WGUI_DISABLE_CSK__
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
    SetCenterSoftkeyFunction(mmi_medply_plst_entry_details, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_list_item_selected_callback();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_scrlocker_callback_key_hdlr
 * DESCRIPTION
 *  This is the callback handler from screen locker for key events when Screen is locked
 * PARAMETERS
 *  evt      : [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_scrlocker_key_callback_hdlr(mmi_frm_key_evt_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_medply_is_play_activated())
    {
        if (evt->key_type == KEY_EVENT_DOWN)
        {
            switch(evt->key_code)
            {
            case KEY_VOL_DOWN:
    #ifdef __MMI_MEDIA_PLAYER_FTE__
                mmi_medply_press_FTE_dec_volume_down();
    #else
                mmi_medply_press_dec_volume_down();
    #endif
                break;

            case KEY_VOL_UP:
    #ifdef __MMI_MEDIA_PLAYER_FTE__
                mmi_medply_press_FTE_inc_volume_down();
    #else
                mmi_medply_press_inc_volume_down();
    #endif
                break;

            default:
                break;
            }
        }
        else if (evt->key_type == KEY_EVENT_UP)
        {
            switch(evt->key_code)
            {
            case KEY_VOL_DOWN:
    #ifdef __MMI_MEDIA_PLAYER_FTE__
                mmi_medply_press_FTE_dec_volume_up();
    #else
                mmi_medply_press_dec_volume_up();
    #endif
                break;

            case KEY_VOL_UP:
    #ifdef __MMI_MEDIA_PLAYER_FTE__
                mmi_medply_press_FTE_inc_volume_up();
    #else
                mmi_medply_press_inc_volume_up();
    #endif
                break;

            default:
                break;
            }
        }
        else
        {
            /* do nothing */
        }
    }
}


#endif /* __MMI_MEDIA_PLAYER__ */

  
