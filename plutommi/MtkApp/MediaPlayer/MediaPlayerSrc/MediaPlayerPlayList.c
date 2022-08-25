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
*  MediaPlayerPlayList.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   Media player play list module
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "MMI_features.h"
////#include "MMI_include.h"
#include "FileMgrSrvGProt.h"

#if (defined(__MMI_MEDIA_PLAYER__) && defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__) && !defined(__MMI_MEDIA_PLAYER_PLST_DB_STYLE__))

    #include "MediaPlayerEnumDef.h"
    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "wgui_inline_edit.h"
    #include "GlobalResDef.h"
    #include "kal_public_api.h"
    #include "nvram_common_defs.h"
    #include "mmi_frm_nvram_gprot.h"
    #include "custom_mmi_default_value.h"
    #include "Unicodexdcl.h"
    #include "string.h"
    #include "AlertScreen.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "CustDataRes.h"
    #include "mmi_frm_events_gprot.h"
    #include "mmi_frm_input_gprot.h"
    #include "GlobalConstants.h"
    #include "DebugInitDef_Int.h"
    #include "fs_type.h"
    #include "fs_func.h"
    #include "fs_errcode.h"
    #include "MMI_media_app_trc.h"
    #include "mmi_media_app_trc.h"
    #include "kal_trace.h"
    #include "mmi_frm_timer_gprot.h"
    #include "mmi_rp_file_type_def.h"
    #include "CommonScreensResDef.h"
    #include "mmi_frm_mem_gprot.h"
    #include "wgui_categories_util.h"
    #include "TimerEvents.h"
#ifdef __MMI_KURO_SUPPORT__
    #include "kurotypedef.h"
    #include "kuroapi.h"
    #include "kurodatatype.h"
#endif
    #include "gui_typedef.h"
    #include "mmi_rp_app_filemanager_def.h"
    #include "wgui_categories_list.h"
    #include "wgui_categories.h"
    #include "wgui_fixed_menus.h"
    #include "gui_fixed_menus.h"
    #include "wgui_categories_popup.h"
    #include "custom_events_notify.h"
    #include "app_mem.h"
    #include "common_nvram_editor_data_item.h"
    #include "stdio.h"
    #include "l4c_nw_cmd.h"
    #include "browser_api.h"
    #include "SoundEffect.h"
    #include "mdi_video.h"
    #include "meta_tag_api.h"
    #include "l1audio.h"
    #include "ImeGprot.h"
    #include "drm_def.h"
    #include "mmi_rp_srv_filemanager_def.h"
    #include "NotificationGprot.h"

#define MEDPLY_DEBUG
#include "med_api.h"
#include "stdlib.h"
////#include "time.h"
////#include "app_str.h"
#include "gui_data_types.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "Conversions.h"
////#include "CommonScreens.h"
////#include "Fmt_struct.h"
////#include "FileMgr.h"
#include "FileMgrType.h"
////#include "FileMgrGProt.h"
////#include "FilemgrResDef.h"
#include "usbsrvgprot.h"
/* cui prot */
#include "FilemgrCuiGprot.h"
#include "menucuigprot.h"
#include "fseditorcuigprot.h"
#include "inlinecuigprot.h"

#include "Drm_gprot.h"
#include "gpiosrvgprot.h"//#include "GeneralDeviceGprot.h"

#ifdef __MMI_RMGR__
#include "RightsMgrGprot.h"
#endif

#ifdef __OTG_ENABLE__
////#include "usb_host_ms_if.h"
#endif 
#include "wgui_touch_screen.h"

#include "mmi_rp_app_medply_def.h"
//#include "MediaPlayerResDef.h"
#include "MediaPlayerProt.h"
#include "MediaPlayerGProt.h"
////#include "MediaPlayerSettings.h"
#include "MediaPlayerPlayList.h"

#ifdef __MMI_BACKGROUND_CALL__
#include "UcmSrvGprot.h"
#include "UCMGProt.h"
#endif

////#include "wapadp.h"

const mmi_medply_support_format_struct support_format_table[] = 
{
    /* format, type, build cache, image id, extended name */
    {MEDPLY_FORMAT_NONE, L"\0"},
#ifdef DAF_DECODE    
    {MEDPLY_FORMAT_DAF, L"MP3"},
#ifdef MUSICAM_DECODE
    {MEDPLY_FORMAT_MUSICAN, L"MP2"},
#endif
#endif /* DAF_DECODE */ 
#ifdef __RM_DEC_SUPPORT__
    {MEDPLY_FORMAT_RA, L"RA"},
#endif /* __RM_DEC_SUPPORT__ */ 
    {MEDPLY_FORMAT_AMR, L"AMR"},
#ifdef AAC_DECODE
    {MEDPLY_FORMAT_AAC, L"AAC"},
#endif
#ifdef AMRWB_DECODE
    {MEDPLY_FORMAT_AWB, L"AWB"},
#endif
#ifdef BSAC_DECODE
/* under construction !*/
#endif
#ifdef __DRM_V02__
    {MEDPLY_FORMAT_ODF, L"ODF"},
#endif
    {MEDPLY_FORMAT_WAV, L"WAV"},
    {MEDPLY_FORMAT_MID, L"MID"},
    {MEDPLY_FORMAT_MIDI, L"MIDI"},
    {MEDPLY_FORMAT_IMY, L"IMY"},
#ifdef AIFF_DECODE
    {MEDPLY_FORMAT_AIFF, L"AIFF"},
    {MEDPLY_FORMAT_AIF, L"AIF"},
    {MEDPLY_FORMAT_AIFC, L"AIFC"},
#endif
#ifdef AU_DECODE
    {MEDPLY_FORMAT_AU, L"AU"},
#endif
#ifdef SND_DECODE
    {MEDPLY_FORMAT_SND, L"SND"},
#endif
#ifdef YAMAHA_MA3
    {MEDPLY_FORMAT_MMF, L"MMF"},
#endif
#ifdef WMA_DECODE
    {MEDPLY_FORMAT_WMA, L"WMA"},
#endif
#ifdef M4A_DECODE
    {MEDPLY_FORMAT_M4A, L"M4A"},
#endif
#if (!defined(MP4_DECODE) && defined(__MMI_PURE_AUDIO__)) 
    {MEDPLY_FORMAT_3GPA, L"3GP"},
    {MEDPLY_FORMAT_MP4A, L"MP4"},
    {MEDPLY_FORMAT_3G2A, L"3G2"},
#endif
#ifdef __MMI_PURE_AUDIO__
    {MEDPLY_FORMAT_3GA, L"3GA"},
#endif
#ifdef __APE_DECODE__
    {MEDPLY_FORMAT_APE,  L"APE"},
#endif
#if defined(__VORBIS_DECODE__) && !defined(__VORBIS_DECODE_SLIM__)
    {MEDPLY_FORMAT_OGG, L"OGG"},
#endif
#if defined(__FLAC_DECODE__ )
    {MEDPLY_FORMAT_FLAC, L"FLAC"},
#endif

/*video*/
#ifdef MP4_DECODE
    {MEDPLY_FORMAT_3GP, L"3GP"},
    {MEDPLY_FORMAT_MP4, L"MP4"},
    {MEDPLY_FORMAT_MPG, L"MPG"},
    {MEDPLY_FORMAT_3G2, L"3G2"},
#endif
#ifdef __RM_DEC_SUPPORT__
    {MEDPLY_FORMAT_RV, L"RV"},
    {MEDPLY_FORMAT_RM, L"RM"},
    {MEDPLY_FORMAT_RMVB, L"RMVB"},
#endif  /* __RM_DEC_SUPPORT__ */ 
#ifdef MJPG_DECODE
    {MEDPLY_FORMAT_AVI, L"AVI"},
#endif
#ifdef __FLV_FILE_FORMAT_SUPPORT__
    {MEDPLY_FORMAT_FLV, L"FLV"},
    {MEDPLY_FORMAT_F4V, L"F4V"},
#endif
#ifdef __MKV_FILE_FORMAT_SUPPORT__
    {MEDPLY_FORMAT_MKV, L"MKV"},
    {MEDPLY_FORMAT_WEBM, L"WEBM"},
#ifdef __VIDEO_3D_SIDE_BY_SIDE__
    {MEDPLY_FORMAT_MK3D, L"MK3D"},
#endif
#endif
#ifdef __MOT_SUPPORT__
    {MEDPLY_FORMAT_MOT, L"MOT"},
#endif
#ifdef __KMV_SUPPORT__
    {MEDPLY_FORMAT_KMV, L"KMV"},
    {MEDPLY_FORMAT_QKMV, L"QKMV"},
#endif
#ifdef __MMI_VIDEO_STREAM__
    {MEDPLY_FORMAT_RTSP, L"RTSP"},
    {MEDPLY_FORMAT_SDP, L"SDP"},
    {MEDPLY_FORMAT_RAM, L"RAM"},
#endif
#ifdef __MMI_KURO_SUPPORT__
    {KURO_FORMAT_KUR, L"kur"},
#endif
    {MEDPLY_FORMAT_TOTAL, L"\0"}
};


const mmi_medply_fileinfo_struct media_file_info_table[] = 
{
    /* format, type, build cache, image id, extended name */
    {MEDPLY_FORMAT_NONE, MEDPLY_TYPE_NONE, 0, IMG_ID_MEDPLY_FILE_UNKNOWN_ICON, L"\0"},
/* audio */
    {MEDPLY_FORMAT_DAF, MEDPLY_TYPE_AUDIO, 1, IMG_ID_MEDPLY_FILE_AUD_ICON, L"MP3"},
    {MEDPLY_FORMAT_MUSICAN, MEDPLY_TYPE_AUDIO, 1, IMG_ID_MEDPLY_FILE_AUD_ICON, L"MP2"},
    {MEDPLY_FORMAT_RA, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"RA"},
    {MEDPLY_FORMAT_AMR, MEDPLY_TYPE_AUDIO, 1, IMG_ID_MEDPLY_FILE_AUD_ICON, L"AMR"},
    {MEDPLY_FORMAT_AAC, MEDPLY_TYPE_AUDIO, 1, IMG_ID_MEDPLY_FILE_AUD_ICON, L"AAC"},
    {MEDPLY_FORMAT_AWB, MEDPLY_TYPE_AUDIO, 1, IMG_ID_MEDPLY_FILE_AUD_ICON, L"AWB"},
    {MEDPLY_FORMAT_BSAC, MEDPLY_TYPE_AUDIO, 1, IMG_ID_MEDPLY_FILE_AUD_ICON, L"BSAC"},
    {MEDPLY_FORMAT_ODF, MEDPLY_TYPE_AUDIO, 1, 
#ifdef __DRM_V02__
    IMG_ID_MEDPLY_FILE_AUD_ICON,
#else
    IMG_ID_MEDPLY_FILE_UNKNOWN_ICON,
#endif
    L"ODF"},
    {MEDPLY_FORMAT_WAV, MEDPLY_TYPE_AUDIO, 1, IMG_ID_MEDPLY_FILE_AUD_ICON, L"WAV"},
    {MEDPLY_FORMAT_MID, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"MID"},
    {MEDPLY_FORMAT_MIDI, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"MIDI"},
    {MEDPLY_FORMAT_IMY, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"IMY"},
    {MEDPLY_FORMAT_AIFF, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"AIFF"},
    {MEDPLY_FORMAT_AIF, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"AIF"},
    {MEDPLY_FORMAT_AIFC, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"AIFC"},
    {MEDPLY_FORMAT_AU, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"AU"},
    {MEDPLY_FORMAT_SND, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"SND"},
    {MEDPLY_FORMAT_MMF, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"MMF"},
    {MEDPLY_FORMAT_WMA, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"WMA"},
    {MEDPLY_FORMAT_M4A, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"M4A"},
    {MEDPLY_FORMAT_3GPA, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"3GP"},
    {MEDPLY_FORMAT_MP4A, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"MP4"},
    {MEDPLY_FORMAT_3G2A, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"3G2"},
    {MEDPLY_FORMAT_3GA, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"3GA"},
    {MEDPLY_FORMAT_APE, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"APE"},
    {MEDPLY_FORMAT_OGG, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"OGG"},
    {MEDPLY_FORMAT_FLAC, MEDPLY_TYPE_AUDIO, 0, IMG_ID_MEDPLY_FILE_AUD_ICON, L"FLAC"},
/* video */
    {MEDPLY_FORMAT_3GP, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"3GP"},
    {MEDPLY_FORMAT_MP4, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"MP4"},
    {MEDPLY_FORMAT_MPG, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"MPG"},
    {MEDPLY_FORMAT_3G2, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"3G2"},
    {MEDPLY_FORMAT_RV, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"RV"},
    {MEDPLY_FORMAT_RM, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"RM"},
    {MEDPLY_FORMAT_RMVB, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"RMVB"},
    {MEDPLY_FORMAT_AVI, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"AVI"},
    {MEDPLY_FORMAT_FLV, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"FLV"},
    {MEDPLY_FORMAT_F4V, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"F4V"},
    {MEDPLY_FORMAT_MKV, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"MKV"},
    {MEDPLY_FORMAT_WEBM, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"WEBM"},
    {MEDPLY_FORMAT_MK3D, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"MK3D"},
    {MEDPLY_FORMAT_MOT, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"MOT"},
    {MEDPLY_FORMAT_KMV, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"KMV"},
    {MEDPLY_FORMAT_QKMV, MEDPLY_TYPE_VIDEO, 0, IMG_ID_MEDPLY_FILE_VIDEO_ICON, L"QKMV"},
/* streaming */
    {MEDPLY_FORMAT_RTSP, MEDPLY_TYPE_STREAM, 0, IMG_ID_MEDPLY_FILE_STREAM_ICON, L"RTSP"},
    {MEDPLY_FORMAT_SDP, MEDPLY_TYPE_STREAM, 0, IMG_ID_MEDPLY_FILE_STREAM_ICON, L"SDP"},
    {MEDPLY_FORMAT_RAM, MEDPLY_TYPE_STREAM, 0, IMG_ID_MEDPLY_FILE_STREAM_ICON, L"RAM"},
#ifdef __MMI_KURO_SUPPORT__
    {KURO_FORMAT_KUR, MEDPLY_TYPE_AUDIO, 1, IMG_ID_MEDPLY_FILE_AUD_ICON, L"kur"},
#endif
    {MEDPLY_FORMAT_TOTAL, MEDPLY_TYPE_NONE, 0, IMG_ID_MEDPLY_FILE_UNKNOWN_ICON, L"\0"}
};

extern U8 PhnsetGetDefEncodingType(void);
extern MMI_BOOL mdi_audio_is_file_seekable(void *file_name);
//extern pBOOL mmi_bootup_get_active_flight_mode(void);

extern wgui_inline_item wgui_inline_items[];        /* wgui_inline_edit.c */

mmi_medply_plst_cntx_struct* plst_cntx_p = NULL;
static MMI_ID   g_gid_browser_list = 0; 
/* playlist state*/
MMI_BOOL browser_now_playing;
static MMI_BOOL addto_now_playing;
static MMI_BOOL browser_all_audio;
static MMI_BOOL browser_all_video;
static MMI_BOOL from_main_scr;
/* list mode */
static MMI_BOOL in_browser_mode;
static MMI_BOOL in_add_to_mode;
/* list forward */
static U16     playlist_fwd_option_menu_id;
/* entry point of storage change */
FuncPtr storage_change_entry = NULL;
/* added for eservice issue - 02017632 */
static U16 file_unplayed_counter = 0;
static MMI_BOOL is_file_played = MMI_TRUE;
static MMI_BOOL all_file_issue = MMI_TRUE;
extern MMI_ID g_gid_medply;

#ifndef __MMI_MEDIA_PLAYER_PLST_MULTIPLE_AUDIO_VIDEO_SPLIT__
#define MMI_MEDPLY_PLST_VIDEO_INTEGRATED
#endif

/* Inline cui struct */
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_filename = 
{
    STR_GLOBAL_FILENAME
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_title = 
{
    STR_ID_MEDPLY_PLST_DETAILS_TITLE
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_artist = 
{
    STR_ID_MEDPLY_PLST_DETAILS_ARTIST
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_album = 
{
    STR_ID_MEDPLY_PLST_DETAILS_ALBUM
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_author = 
{
    STR_ID_MEDPLY_PLST_DETAILS_AUTHOR
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_genre = 
{
    STR_ID_MEDPLY_PLST_DETAILS_GENRE
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_copyrights = 
{
    STR_ID_MEDPLY_PLST_DETAILS_COPYRIGHTS
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_description = 
{
    STR_ID_MEDPLY_PLST_DETAILS_DESCRIPTION
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_year = 
{
    STR_ID_MEDPLY_PLST_DETAILS_YEAR
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_tracknum = 
{
    STR_ID_MEDPLY_PLST_DETAILS_TRACK_NUM
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_duration = 
{
    STR_ID_MEDPLY_PLST_DETAILS_DURATION
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_size = 
{
    STR_ID_MEDPLY_PLST_DETAILS_SIZE
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_quality = 
{
    STR_ID_MEDPLY_PLST_DETAILS_QUALITY
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_channel = 
{
    STR_ID_MEDPLY_PLST_DETAILS_CHANNEL
};
static const cui_inline_item_caption_struct mmi_medply_plst_inline_caption_local = 
{
    STR_ID_MEDPLY_PLST_DETAILS_LOCAL
};


static const cui_inline_set_item_struct mmi_medply_plst_inline_item[] = 
{
    {FILENAME_TYPE_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION, 0,      (void*)&mmi_medply_plst_inline_caption_filename},
    {FILENAME_TYPE_ITEM,        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, NULL},
    {TILTE_TYPE_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION, 0,      (void*)&mmi_medply_plst_inline_caption_title},
    {TILTE_TYPE_ITEM,           CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, NULL},
    {ARTIST_TYPE_CAPTION,       CUI_INLINE_ITEM_TYPE_CAPTION, 0,      (void*)&mmi_medply_plst_inline_caption_artist},
    {ARTIST_TYPE_ITEM,          CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, NULL},
    {ALBUM_TYPE_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION, 0,      (void*)&mmi_medply_plst_inline_caption_album},
    {ALBUM_TYPE_ITEM,           CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, NULL},
    {AUTHOR_TYPE_CAPTION,       CUI_INLINE_ITEM_TYPE_CAPTION, 0,      (void*)&mmi_medply_plst_inline_caption_author},
    {AUTHOR_TYPE_ITEM,          CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, NULL},
    {GENRE_TYPE_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION, 0,      (void*)&mmi_medply_plst_inline_caption_genre},
    {GENRE_TYPE_ITEM,           CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, NULL},
    {COPYRIGHTS_TYPE_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION, 0,      (void*)&mmi_medply_plst_inline_caption_copyrights},
    {COPYRIGHTS_TYPE_ITEM,      CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, NULL},
    {DESCRIPTION_TYPE_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION, 0,      (void*)&mmi_medply_plst_inline_caption_description},
    {DESCRIPTION_TYPE_ITEM,     CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, NULL},
    {YEAR_TYPE_CAPTION,         CUI_INLINE_ITEM_TYPE_CAPTION, 0,      (void*)&mmi_medply_plst_inline_caption_year},
    {YEAR_TYPE_ITEM,            CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, NULL},
    {TACKNUM_TYPE_CAPTION,      CUI_INLINE_ITEM_TYPE_CAPTION, 0,      (void*)&mmi_medply_plst_inline_caption_tracknum},
    {TACKNUM_TYPE_ITEM,         CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, NULL},
    {DURATION_TYPE_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION, 0,      (void*)&mmi_medply_plst_inline_caption_duration},
    {DURATION_TYPE_ITEM,        CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, NULL},
    {SIZE_TYPE_CAPTION,         CUI_INLINE_ITEM_TYPE_CAPTION, 0,      (void*)&mmi_medply_plst_inline_caption_size},
    {SIZE_TYPE_ITEM,            CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, NULL},
    {QUALITY_TYPE_CAPTION,      CUI_INLINE_ITEM_TYPE_CAPTION, 0,      (void*)&mmi_medply_plst_inline_caption_quality},
    {QUALITY_TYPE_ITEM,         CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, NULL},
    {CHANNELNUM_TYPE_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION, 0,      (void*)&mmi_medply_plst_inline_caption_channel},
    {CHANNELNUM_TYPE_ITEM,      CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, NULL},
    {LOCAL_TYPE_CAPTION,        CUI_INLINE_ITEM_TYPE_CAPTION, 0,      (void*)&mmi_medply_plst_inline_caption_local},
    {LOCAL_TYPE_ITEM,           CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, NULL},
};


static cui_inline_item_softkey_struct mmi_medply_plst_inline_softkey = 
{
    {
        {0, 0},                     /*MMI_LEFT_SOFTKEY*/
        {STR_GLOBAL_BACK, 0},       /*MMI_RIGHT_SOFTKEY*/
        {0, 0}                      /*MMI_CENTER_SOFTKEY*/
    }
};


static const cui_inline_struct mmi_medply_plst_inline_screen = 
{
    MEDPLY_PLST_INLINE_ITEM_NUM,
    STR_GLOBAL_DETAILS,
    0,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE, 
    &mmi_medply_plst_inline_softkey, 
    mmi_medply_plst_inline_item 
};


#define ASM_MEM_STATUS_TRC(line)            MEDPLY_DEBUG3("<MEDPLY>[PLST] ASM memory left = [%d].\n can get max size = [%d], line = [%d]. \n", kal_adm_get_total_left_size(g_medply.adm_id_p), kal_adm_get_max_alloc_size(g_medply.adm_id_p), line)
#define MEM_TRC_ALLOCATE(addr, size, line)  MEDPLY_DEBUG3("<MEDPLY>[PLST] ASM allocate: addr = [%X], size = [%d], line = [%d].\n", addr, size, line)
#define MEM_TRC_FREE(addr, line)            MEDPLY_DEBUG2("<MEDPLY>[PLST] ASM free: addr = [%X], line = [%d].\n", addr, line)

#define META_ERROR(x)       (x*(-1) + (-220))

#define TIME_STAMP       MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_GET_CURRENT_TIME,mmi_medply_get_current_time())
static U32 mmi_medply_get_current_time(void)
{
    kal_uint32 ticks = 0;
    kal_uint32 time = 0;
    kal_get_time(&ticks);
    time = kal_ticks_to_milli_secs(ticks);
    return time;
}

#ifdef __MMI_MEDIA_PLAYER_STREAM__
static void     mmi_medply_predefined_url_lsk_hdlr(void);
static void     mmi_medply_history_sync_file(void);
#endif

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void     mmi_medply_plst_listmgr_tap_callback(mmi_tap_type_enum tap_type,S32 index);
static void     mmi_medply_plst_tap_callback(mmi_tap_type_enum tap_type,S32 index);
#endif
#ifdef __MMI_MEDIA_PLAYER_STREAM__
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void     mmi_medply_bookmark_tap_callback(mmi_tap_type_enum tap_type,S32 index);
#endif
#endif
#ifdef __MMI_KURO_SUPPORT__
static void     mmi_medply_kuro_plst_option_activate(void);
#endif
#ifdef __MMI_MEDIA_PLAYER_STREAM__
static void     mmi_medply_bookmark_input_url(void);
static void     mmi_medply_bookmark_entry_history_url(void);
static void     mmi_medply_bookmark_entry_predefined_url(void);
static void     mmi_medply_bookmark_history_option_initiate_play(void);
static void     mmi_medply_bookmark_entry_remove_confirm(void);
static void     mmi_medply_bookmark_entry_remove_all_confirm(void);
#endif

static S32      mmi_medply_plst_all_media_list_init(MMI_BOOL reset_f);

static void     mmi_medply_plst_listmgr_option_config(cui_menu_event_struct *menu_evt);
static void     mmi_medply_plst_listmgr_select_storage(void);
static void     mmi_medlpy_plst_listmgr_fmgr_storage_select_hdlr(cui_storage_selector_result_event_struct* evt);
static MMI_BOOL mmi_medply_plst_listmgr_rename_part3(U8 action, S32 result, mmi_id editor_id);
static void     mmi_medply_plst_listmgr_rename_part2(void);
static void     mmi_medply_plst_listmgr_rename_part1(void);
static void     mmi_medply_plst_listmgr_create_part1(void);
static void     mmi_medply_plst_listmgr_create_part2(void);
static void     mmi_medply_plst_listmgr_delete_part1(void);
static void     mmi_medply_plst_listmgr_deleteall_part1(void);
static void     mmi_medply_plst_listmgr_settings(void);
static void     mmi_medply_plst_listmgr_open(void);
static void     mmi_medply_plst_listmgr_delete_all_rsp_hdlr(srv_fmgr_async_done_event_struct *info);
static void     mmi_medply_plst_listmgr_get_path(UI_string_type path);
static pBOOL    mmi_medply_plst_listmgr_get_item(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);

static void     mmi_medply_plst_option_config(cui_menu_event_struct *menu_evt);
static void     mmi_medply_plst_option_remove(MMI_BOOL delete_f);
static void     mmi_medply_plst_option_moveup(void);
static void     mmi_medply_plst_option_movedown(void);
static void     mmi_medply_plst_option_add_part1(void);
static void     mmi_medply_plst_option_add_to_part1(void);
static void     mmi_medply_plst_option_initiate_play(void);
static void     mmi_medply_plst_option_settings(void);
static void     mmi_medply_plst_option_update(void);
static void     mmi_medply_plst_option_send(cui_menu_event_struct *menu_evt);
static void     mmi_medply_plst_option_use(cui_menu_event_struct *menu_evt);

static U8       mmi_medply_plst_details_preview_delete_hdlr(void* in_param);
static void     mmi_medply_plst_details_set_value(MMI_ID inline_id);
static S32      mmi_medply_plst_details_prepare_data(void);
static void     mmi_medply_plst_details_unprepare_data(void);

static void     mmi_medply_plst_gobackhistory(void);
static MMI_BOOL mmi_medply_plst_is_scrn_present(MMI_ID parent_id,MMI_ID scrn_id);
static U16      mmi_medply_util_is_target_support_format(const UI_string_type ext);
static MMI_BOOL mmi_medply_util_check_free_space(CHAR drv_letter, U32 req_size);
//static S32      mmi_medply_util_create_file_dir(UI_string_type filepath);
//static U8       mmi_medply_plst_util_drv_letter(void);
//static void     mmi_medply_plst_util_get_drv_status(void);
static void     mmi_medply_plst_entry_details_internal(void);
static void     mmi_medply_plst_post_popup(S32 error_code);
static void     mmi_medply_plst_post_event_to_main(mmi_medply_event_enum event_id, void *user_data);
static void     mmi_medply_plst_clear_context_variables(void);
//static void     mmi_medply_plst_entry_generate_layer(void);
//static void     mmi_medply_plst_generate_start(void);
//static mmi_ret  mmi_medply_plst_deleteupto(U16 scrn_id);
static void     mmi_medply_plst_fwd_select(U16 current_menu_item_id);
static void     mmi_medlpy_plst_fmgr_file_selector_handle(cui_file_selector_result_event_struct *file_select);
static S32      mmi_medply_plst_get_path(UI_string_type fullfilename, S32 index);
static void     mmi_medply_plst_generate_sort_index(mmi_medply_plst_index_node_struct* index, U32 total);
static void     mmi_medply_plst_storage_change(MMI_ID parent_id);
static MMI_BOOL mmi_medply_plst_check_path_is_parent(const WCHAR* parent_path, const WCHAR *check_path);

#define __FUNCTION_BODY
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_save_last_path
 * DESCRIPTION
 *  save last play path
 * PARAMETERS
 *  path		[IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_plst_save_last_path(UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (0 > WriteRecord(NVRAM_EF_MEDPLY_LAST_PLAYLIST_PATH_LID, 1, (void*)path, NVRAM_EF_MEDPLY_LIST_PLAYLIST_PATH_SIZE, &error))
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_last_path
 * DESCRIPTION
 *  get last play path
 * PARAMETERS
 *  path        [OUT]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_medply_plst_get_last_path(UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    if (ReadRecord(NVRAM_EF_MEDPLY_LAST_PLAYLIST_PATH_LID, 1, (void*)path, NVRAM_EF_MEDPLY_LIST_PLAYLIST_PATH_SIZE, &error) < 0)
    {     
        return MMI_FALSE;
    }
    return MMI_TRUE;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_save_last_index
 * DESCRIPTION
 *  save the last play music index in playlist
 * PARAMETERS
 *  index		[IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_save_last_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 last_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < 0)
    {
        last_index = 0xFFFF;
    }
    else
    {
        last_index = (U16)index;
    }
    WriteValue(NVRAM_MEDPLY_LAST_PLAYLIST_INDEX, &last_index, DS_SHORT, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_last_index
 * DESCRIPTION
 *  get the last play music index in playlist
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_plst_get_last_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U16 index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    ReadValue(NVRAM_MEDPLY_LAST_PLAYLIST_INDEX, &index, DS_SHORT, &error);
    if (index == 0xFFFF)
    {     
        return -1;
    }
    return index;    
}


#define __UI_CNTX
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_ui_init_cntx
 * DESCRIPTION
 *  play list context init
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_ui_init_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_dynamic_list_data_struct* ui = &(plst_cntx_p->list_ui);
    mmi_medply_plst_struct* list = plst_cntx_p->browser_list_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (browser_now_playing)
    {
        list = &(plst_cntx_p->current_list);
    }
    ui->total = list->total;
    mmi_ucs2ncpy((CHAR*)ui->temp_buffer, (CHAR*)list->title, (MEDPLY_MAX_FILE_LEN - 1));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_ui_reset_cntx
 * DESCRIPTION
 *  reset list ui struct.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_ui_reset_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    memset(&(plst_cntx_p->list_ui), 0, sizeof(mmi_medply_dynamic_list_data_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_ui_highlight_hdlr
 * DESCRIPTION
 *  ui highlight index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_ui_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    plst_cntx_p->list_ui.highlight = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_ui_get_current_highlight
 * DESCRIPTION
 *  ui get current highlight
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_plst_ui_get_current_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    return plst_cntx_p->list_ui.highlight;
}


#define __SEARCH_CUI_INT
typedef struct
{
    LOCAL_PARA_HDR
    mmi_medply_cui_search_context_struct *context;
} mmi_medply_cui_search_req_struct;

#define mmi_medply_cui_search_continue_req(context) \
    mmi_medply_cui_search_continue_req_ext(context, __LINE__)
#define mmi_medply_cui_search_start_timer(timerid, delay, funcPtr, arg) \
        mmi_medply_cui_search_start_timer_ext(timerid, delay, funcPtr, arg, __LINE__)

#ifdef __PERFORMANCE_TEST_GEN__
static kal_uint32 search_total_tick = 0;
static kal_uint32 search_start_tick = 0;
static kal_uint32 search_end_tick = 0;


#define PTG_TOTAL_START() search_total_tick = 0; search_start_tick = 0; search_end_tick = 0;
#define PTG_START() kal_get_time(&search_start_tick);
#define PTG_END() if(search_start_tick>0) {kal_get_time(&search_end_tick); search_total_tick += search_end_tick-search_start_tick;search_start_tick = 0;}
#define PTG_TOTAL_REPORT() MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_MEDPLY_PLST_PTG_TOTAL_REPORT, kal_ticks_to_milli_secs(search_total_tick), __LINE__);
#else

#define PTGB_TOTAL_START()  
#define PTGB_START()  
#define PTGB_END()  
#define PTGB_TOTAL_REPORT()  

#endif
static void mmi_medply_cui_search_int(void* cntxt);
static void mmi_medply_cui_search_unprepare(mmi_id search_cui_gid);


static void mmi_medply_cui_search_start_timer_ext(U16 timerid, U32 delay, oslTimerFuncPtr funcPtr, void * arg,  U16 line_number)
{

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_MEDPLY_CUI_SEARCH_START_TIMER_EXT, timerid, delay, line_number);
    StartTimerEx(timerid, delay, funcPtr, arg);
}


 /*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_search_send_msg
 * DESCRIPTION
 *  player list service send msg function 
 * PARAMETERS
 *  buffer      [IN]    buffer for sqlite database usage
 *  length      [IN]    length of buffer
 *  en_update   [IN]    enable update picture to database
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_cui_search_send_msg(module_type src, module_type dst, U32 msg_id, void *local_param_ptr)
{
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
#endif
     msg_send5(src, dst, MMI_MMI_SAP, (msg_type)msg_id, (local_para_struct*)local_param_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_search_int_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_medply_cui_search_int_proc(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_cui_search_context_struct *context = ((mmi_medply_cui_search_req_struct*)msg)->context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_MEDPLY_CUI_SEARCH_INT_PROC, (void *)context, __LINE__);
    mmi_medply_cui_search_int((void *)context);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_search_continue_req_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_medply_cui_search_continue_req_ext(void *context, U16 line_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_cui_search_req_struct *req_param_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_param_ptr = (mmi_medply_cui_search_req_struct*) construct_local_para(sizeof(mmi_medply_cui_search_req_struct), TD_CTRL);
    req_param_ptr->context = context;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_MEDPLY_CUI_SEARCH_CONTINUE_REQ_EXT, (void *)context, line_number);
    mmi_medply_cui_search_send_msg(MOD_MMI, MOD_MMI, MSG_ID_MMI_LIST_SEARCH_CUI_SEARCH_INT_REQ, req_param_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_search_screen_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_cui_search_screen_entry(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_cui_search_context_struct *context;
    mmi_confirm_property_struct property;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    context = (mmi_medply_cui_search_context_struct *)mmi_frm_group_get_user_data(parent_id);
    if (context->no_cancel)
    {
        mmi_confirm_property_init(&property, CNFM_TYPE_CANCEL);
    }
    else
    {
        mmi_confirm_property_init(&property, CNFM_TYPE_USER_DEFINE);
    }
    mmi_confirm_property_init(&property, CNFM_TYPE_CANCEL);
    property.parent_id = parent_id;
    property.user_tag = context;
    property.f_enter_history = 1;
    property.f_auto_dismiss = 0;
    property.f_auto_map_empty_softkey = 0;
    context->search.waiting_scr_gid = 
        mmi_confirm_display((WCHAR*)GetString(STR_GLOBAL_PLEASE_WAIT), MMI_EVENT_PROGRESS, &property);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_search_get_drv_letter
 * DESCRIPTION
 *  return removable driver number.
 *  check phone memory, memory card, SIM+ and OTG.
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_medply_cui_search_get_drv_letter(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_cui_search_context_struct *context;
    CHAR drive; 
    U8 count = 0;
#if defined(__OTG_ENABLE__) || defined(__SIM_PLUS__)
    U8 i = 0;
#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    context = (mmi_medply_cui_search_context_struct *)mmi_frm_group_get_user_data(cui_id);
    MMI_ASSERT(context->search.search_cui_gid == cui_id);
    if (((drive = FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_V_REMOVABLE)) >= 'A') && (drive <= 'Z'))
    {
        context->search.drv_list[count].drv_letter = drive;
        count++;
    }
    
    if (((drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
    {
        context->search.drv_list[count].drv_letter = drive;
        count++;
    }

#ifdef __OTG_ENABLE__
    for (i = 0; i < 4; i++)
    {
        if (((drive = FS_GetDrive(FS_DRIVE_V_EXTERNAL, i + 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
        {
            context->search.drv_list[count].drv_letter = drive;
            count++;
        }
    }
    
#endif /* __OTG_ENABLE__ */ 

#ifdef __SIM_PLUS__
    for (i = 0; i < USB_HOST_MS_SUPPORT_LUN; i++)
    {
        if (((drive = FS_GetDrive(FS_DRIVE_V_SIMPLUS, i + 1, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
        {
            context->search.drv_list[count].drv_letter = drive;
            count++;
        }
    }
#endif

#ifdef __MSDC2_SD_MMC__
    if (((drive = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 2, FS_NO_ALT_DRIVE)) >= 'A') && (drive <= 'Z'))
    {
        context->search.drv_list[count].drv_letter = drive;
        count++;
    }    
#endif

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_search_get_drv_status
 * DESCRIPTION
 *  update driver's status.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_cui_search_get_drv_status(mmi_id cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_cui_search_context_struct *context;
    U8 i = 0;
    FS_DiskInfo disk_info;
    UI_character_type drv_path[10];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    context = (mmi_medply_cui_search_context_struct *)mmi_frm_group_get_user_data(cui_id);
    MMI_ASSERT(context->search.search_cui_gid == cui_id);
    for (i = 0; i < MMI_MEDPLY_DRV_TOTAL; i++)
    {
        if (FS_GetDevStatus(context->search.drv_list[i].drv_letter, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
        {
            context->search.drv_list[i].is_active = MMI_TRUE;
            kal_wsprintf(drv_path, "%c:\\", context->search.drv_list[i].drv_letter);
            FS_GetDiskInfo(drv_path, &disk_info, FS_DI_BASIC_INFO);  
        }
        else
        {
            context->search.drv_list[i].is_active = MMI_FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_search_send_evt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_cui_search_send_evt(MMI_ID cui_id,mmi_medply_event_enum evt_id, void* userdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_cui_search_context_struct *context;
    mmi_medply_cui_search_close_event_struct evt_close;
    mmi_medply_cui_search_finish_event_struct evt_finish;
    mmi_medply_cui_search_cancel_event_struct evt_cancel;
    mmi_medply_cui_search_error_event_struct evt_error;
    mmi_medply_cui_search_append_event_struct evt_append;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    context = (mmi_medply_cui_search_context_struct *)mmi_frm_group_get_user_data(cui_id);
    if (context == NULL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        return MMI_RET_OK;
    }
    switch (evt_id)
    {
        case EVT_ID_MEDPLY_CUI_SEARCH_CLOSE:
        {
            MMI_FRM_INIT_GROUP_EVENT(&evt_close, evt_id, cui_id);  
            evt_close.user_data = userdata;
            evt_close.search_cui_gid = context->search.search_cui_gid;
            return mmi_frm_group_send_to_parent(cui_id, (mmi_group_event_struct*) &evt_close);
        }
        case EVT_ID_MEDPLY_CUI_SEARCH_FINISH:
        {
            MMI_FRM_INIT_GROUP_EVENT(&evt_finish, evt_id, cui_id);  
            evt_finish.user_data = userdata;
            evt_finish.search_cui_gid = context->search.search_cui_gid;
            return mmi_frm_group_send_to_parent(cui_id, (mmi_group_event_struct*) &evt_finish);
        }
        case EVT_ID_MEDPLY_CUI_SEARCH_CANCEL:
        {
            MMI_FRM_INIT_GROUP_EVENT(&evt_cancel, evt_id, cui_id);  
            evt_cancel.user_data = userdata;
            evt_cancel.search_cui_gid = context->search.search_cui_gid;
            return mmi_frm_group_send_to_parent(cui_id, (mmi_group_event_struct*) &evt_cancel);
        }
        case EVT_ID_MEDPLY_CUI_SEARCH_ERROR:
        {
            MMI_FRM_INIT_GROUP_EVENT(&evt_error, evt_id, cui_id);  
            evt_error.user_data = userdata;
            evt_error.search_cui_gid = context->search.search_cui_gid;
            evt_error.error_code = context->search.last_error_code;
            return mmi_frm_group_send_to_parent(cui_id, (mmi_group_event_struct*) &evt_error);
        }
        case EVT_ID_MEDPLY_CUI_SEARCH_APPEND:
        {
            MMI_FRM_INIT_GROUP_EVENT(&evt_append, evt_id, cui_id);  
            evt_append.user_data = userdata;
            evt_append.search_cui_gid = context->search.search_cui_gid;
            evt_append.filepath = context->search.file_path;
            return mmi_frm_group_send_to_parent(cui_id, (mmi_group_event_struct*) &evt_append);
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }
    return MMI_RET_OK;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_generator_set_drv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_cui_search_int_set_drv(MMI_ID cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_cui_search_context_struct *context = (mmi_medply_cui_search_context_struct *)mmi_frm_group_get_user_data(cui_id);
    MMI_BOOL got_next = MMI_FALSE;
    U8 index = context->search.drv_idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (context == NULL)
    {
        mmi_frm_group_close(cui_id);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_GENEREATE_SEARCH_ERROR, -1, __LINE__);
        return;
    }
    if (context->search.drv_idx< MMI_MEDPLY_DRV_TOTAL)
    {
        while (index < MMI_MEDPLY_DRV_TOTAL)
        {
            if (context->search.drv_list[index].is_active)
            {
                kal_wsprintf(context->search.path_cache, "%c:\\", context->search.drv_list[index].drv_letter);
                index++;
                context->search.drv_idx = index;
                context->search.phase = MEDPLY_CUI_SEARCH_PHASE_SEARCH_FIRST;
                got_next = MMI_TRUE;
                break;
            }
            else
            {
                index++;
            }
        }

        if (!got_next)
        {
            context->search.phase = MEDPLY_CUI_SEARCH_PHASE_FINISH;
        }
    }
    else
    {
        context->search.phase = MEDPLY_CUI_SEARCH_PHASE_FINISH;
    }
    
    mmi_medply_cui_search_int((void*)context);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_search_int_search
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_cui_search_int_search(MMI_ID cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_cui_search_context_struct *context = (mmi_medply_cui_search_context_struct *)mmi_frm_group_get_user_data(cui_id);
    FS_DOSDirEntry file_info;
    FS_HANDLE ret = FS_NO_ERROR;
    U8 run_slice = 0;
    UI_character_type buf_file_name[MEDPLY_CUI_SEARCH_FILE_LEN];
    UI_character_type file_ext[MEDPLY_CUI_SEARCH_EXT_LEN];
    MMI_BOOL is_shortname = MMI_FALSE;

#ifdef __DRM_V02__
    UI_character_type odf_path[MEDPLY_CUI_SEARCH_PATH_LEN];
    UI_character_type ext_in_odf[MEDPLY_CUI_SEARCH_EXT_LEN];
    PU8 ext_name_p = NULL; 
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (context == NULL)
    {
        mmi_frm_group_close(cui_id);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_GENEREATE_SEARCH_ERROR, -1, __LINE__);
        return;
    }
    mmi_ucs2ncpy((CHAR*)context->search.file_path, (CHAR*)context->search.path_cache, (MEDPLY_CUI_SEARCH_PATH_LEN - 1));
    mmi_ucs2ncat((CHAR*)context->search.file_path, (CHAR*)L"*.*", (MEDPLY_CUI_SEARCH_PATH_LEN - 1));
        
    if (context->search.phase == MEDPLY_CUI_SEARCH_PHASE_SEARCH_FIRST)
    {
        ret = FS_FindFirstN(
                (PU16)context->search.file_path,
                NULL,
                0,
                FS_ATTR_DIR,    /* only search media files in this phase. */
                0,
                FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                &file_info,
                (PU16)buf_file_name,
                (MEDPLY_CUI_SEARCH_FILE_LEN) * ENCODING_LENGTH,
                0,
                FS_FIND_DEFAULT);
        
        if (ret >= 0)
        {
            context->search.search_handle = ret;
            context->search.phase = MEDPLY_CUI_SEARCH_PHASE_SEARCH_NEXT;
            
            /* begin to cache sub-folder infomation. */
            if (context->search.stack_index < MEDPLY_CUI_SEARCH_MAX_DEPTH_DIRECTORY)
            {
                context->search.stack[context->search.stack_index].level = context->search.stack_index;
                context->search.stack[context->search.stack_index].total_sub_folder = 0;
                context->search.stack[context->search.stack_index].index = 0;
                context->search.stack[context->search.stack_index].fs_index = 0;    /* it is invalid when this value is 0 or 1. */
            }
            else
            {
                /* max level, do not save. */
                MMI_ASSERT(context->search.stack_index < MEDPLY_CUI_SEARCH_MAX_DEPTH_DIRECTORY);
            }
        }
        else
        {
            if (context->search.stack_index == 0)
            {
                if (ret == FS_NO_MORE_FILES)
                {
                    context->search.phase = MEDPLY_CUI_SEARCH_PHASE_BACKWARDS;
                    mmi_medply_cui_search_continue_req((void*)context);
                    //mmi_medply_cui_search_start_timer(context->run_timer, 20, mmi_medply_cui_search_int, (void*)context);
                }
                else
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_GENEREATE_SEARCH_ERROR, ret, __LINE__);
                    context->search.last_error_code = ret;
                    context->search.phase = MEDPLY_CUI_SEARCH_PHASE_ERR_HDLR;
                    mmi_medply_cui_search_int((void*)context);
                }
            }
            else
            {
                context->search.phase = MEDPLY_CUI_SEARCH_PHASE_BACKWARDS;
                mmi_medply_cui_search_continue_req((void*)context);
                //mmi_medply_cui_search_start_timer(context->run_timer, 20, mmi_medply_cui_search_int, (void*)context);
            }
            return;
        }
    }
    else if (context->search.phase == MEDPLY_CUI_SEARCH_PHASE_SEARCH_NEXT)
    {
        ret = FS_FindNextN(
                        context->search.search_handle,
                        NULL,
                        0,
                        FS_ATTR_DIR,
                        &file_info,
                        (PU16)buf_file_name,
                        (MEDPLY_CUI_SEARCH_FILE_LEN) * ENCODING_LENGTH,
                        FS_FIND_DEFAULT);
        if (ret < 0)
        {
            FS_FindClose(context->search.search_handle);
            context->search.search_handle = -1;
            if (ret == FS_NO_MORE_FILES)
            {
                if (!context->search.stack[context->search.stack_index].total_sub_folder)
                {
                    context->search.phase = MEDPLY_CUI_SEARCH_PHASE_BACKWARDS;
                    mmi_medply_cui_search_continue_req((void*)context);
                    //mmi_medply_cui_search_start_timer(context->run_timer, 20, mmi_medply_cui_search_int, (void*)context);
                }
                else
                {
                    if (context->search.stack_index < MEDPLY_CUI_SEARCH_MAX_DEPTH_DIRECTORY)
                    {
                        context->search.phase = MEDPLY_CUI_SEARCH_PHASE_FORWARDS;
                        mmi_medply_cui_search_continue_req((void*)context);
                        //mmi_medply_cui_search_start_timer(context->run_timer, 20, mmi_medply_cui_search_int, (void*)context);
                    }
                    else
                    {
                        context->search.phase = MEDPLY_CUI_SEARCH_PHASE_BACKWARDS;
                        mmi_medply_cui_search_continue_req((void*)context);
                        //mmi_medply_cui_search_start_timer(context->run_timer, 20, mmi_medply_cui_search_int, (void*)context);
                    }
                }
            }
            else
            {
                if (context->search.stack_index == 0)
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_GENEREATE_SEARCH_ERROR, ret, __LINE__);
                    context->search.last_error_code = ret;
                    context->search.phase = MEDPLY_CUI_SEARCH_PHASE_ERR_HDLR;
                    mmi_medply_cui_search_int((void*)context);
                }
                else
                {
                    context->search.phase = MEDPLY_CUI_SEARCH_PHASE_BACKWARDS;
                    mmi_medply_cui_search_continue_req((void*)context);
                    //mmi_medply_cui_search_start_timer(context->run_timer, 20, mmi_medply_cui_search_int, (void*)context);
                }
            }
            return;
        }
    }
    else
    {
        /* these codes should never be run. */
        MMI_ASSERT(context->search.phase == MEDPLY_CUI_SEARCH_PHASE_SEARCH_NEXT ||
                   context->search.phase == MEDPLY_CUI_SEARCH_PHASE_SEARCH_FIRST);
    }
    
    do
    {
        if ((file_info.Attributes & (FS_ATTR_DIR | FS_ATTR_VOLUME | FS_ATTR_HIDDEN | FS_ATTR_SYSTEM)) == 0)
        {
            if (FS_SFN_MATCH == file_info.NTReserved)
            {
                is_shortname = MMI_TRUE;
            }
            if (is_shortname)
            {
                U8 j = 0;
                for (j = 0; j < 3; j++)
                {
                    if (file_info.Extension[j] == ' ')
                    {
                        break;    
                    }
                    file_ext[j] = (UI_character_type) file_info.Extension[j];
                }
                file_ext[j] = 0;
            }
            else
            {
                CHAR* ext = mmi_ucs2rchr((CHAR*)buf_file_name, (U16)L'.');
                if (ext != NULL)
                {
                    ext += 2;
                    mmi_ucs2ncpy((CHAR*)file_ext, (CHAR*)ext, (MEDPLY_CUI_SEARCH_EXT_LEN - 1));
                }
                else
                {
                    ext = NULL;
                    file_ext[0] = 0;
                }
            }
            
#ifdef __DRM_V02__
            if (!mmi_ucs2nicmp((CHAR*)file_ext, (CHAR*)L"odf", (U32)mmi_ucs2strlen((CHAR*)file_ext)))
            {
                mmi_ucs2ncpy((CHAR*)odf_path, (CHAR*)context->search.path_cache, (MEDPLY_CUI_SEARCH_PATH_LEN - 1));
                mmi_ucs2ncat((CHAR*)odf_path, (CHAR*)buf_file_name, (MEDPLY_CUI_SEARCH_PATH_LEN - 1));
                
                if (!DRM_is_archive(0, (PU16)odf_path))
                {
                    ext_name_p = (PU8)DRM_get_content_ext(0, (PU16)odf_path);
                    if (ext_name_p != NULL)
                    {
                        mmi_asc_n_to_ucs2((CHAR*)ext_in_odf, (CHAR*)ext_name_p, strlen((char *)ext_name_p));
                    }
                    else
                    {
                        file_ext[0] = 0;
                    }
                }
                else
                {
                    context->search.phase = MEDPLY_CUI_SEARCH_PHASE_SEARCH_ODF;
                    mmi_medply_cui_search_continue_req((void*)context);
                    //mmi_medply_cui_search_start_timer(context->run_timer, 20, mmi_medply_cui_search_int, (void*)context);
                    return;
                }
            }
            else
#endif  /* __DRM_V02__ */
            {
                if (mmi_ucs2strlen((CHAR*)context->search.path_cache) + 
                    mmi_ucs2strlen((CHAR*)buf_file_name) <= (MEDPLY_CUI_SEARCH_PATH_LEN - 1))
                {
                    mmi_ret ret;
                    MMI_BOOL is_skip = MMI_FALSE;
                    filetypes_group_type_enum   file_grp;
                    filetypes_file_type_enum    file_type;
                    
                    mmi_ucs2ncpy((CHAR*)context->search.file_path, (CHAR*)context->search.path_cache, (MEDPLY_CUI_SEARCH_PATH_LEN - 1));
                    mmi_ucs2ncat((CHAR*)context->search.file_path, (CHAR*)buf_file_name, (MEDPLY_CUI_SEARCH_FILE_LEN - 1));
                    switch (context->run_filter)
                    {
                        case MEDPLY_CUI_SEARCH_FILTER_ALL_MEDIA:
                        {
                            is_skip = MMI_FALSE;
                            break;
                        }
                        case MEDPLY_CUI_SEARCH_FILTER_AUDIO:
                        {
                            file_type = (filetypes_file_type_enum)srv_fmgr_types_find_type_by_filepath((WCHAR*)context->search.file_path);
                            file_grp = srv_fmgr_types_find_group_by_type(file_type);
                            if (file_grp != FMGR_GROUP_AUDIO)
                            {
                                is_skip = MMI_TRUE;
                            }
                            break;
                        }
                        case MEDPLY_CUI_SEARCH_FILTER_VIDEO:
                        {
                            file_type = (filetypes_file_type_enum)srv_fmgr_types_find_type_by_filepath((WCHAR*)context->search.file_path);
                            file_grp = srv_fmgr_types_find_group_by_type(file_type);
                            if (file_grp != FMGR_GROUP_VIDEO 
                        #ifdef __MMI_MEDIA_PLAYER_STREAM__
                                && file_grp != FMGR_GROUP_STREAM)
                        #else
                                )
                        #endif
                            {
                                is_skip = MMI_TRUE;
                            }
                            break;
                        }
                        default:
                            MMI_ASSERT(0);
                        
                    }

                    if (!is_skip)
                    {
                        ret = mmi_medply_cui_search_send_evt(context->search.search_cui_gid, EVT_ID_MEDPLY_CUI_SEARCH_APPEND, NULL);
                        if (ret != MMI_RET_OK)
                        {
                            FS_FindClose(context->search.search_handle);
                            context->search.search_handle = -1;
                            context->search.last_error_code = ret;
                            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_GENEREATE_SEARCH_ERROR, context->search.last_error_code, __LINE__);
                            context->search.phase = MEDPLY_CUI_SEARCH_PHASE_ERR_HDLR;
                            mmi_medply_cui_search_int((void*)context);
                            return;
                        }
                    }
                }
                else
                {
                    /* too long path, skip it! */
                }
                
                /* skip to ask other messages. */
                if ((++run_slice) == MEDPLY_CUI_SEARCH_MAX_PICK_PER_SLICE)    
                {
                    mmi_medply_cui_search_continue_req((void*)context);
                    return;
                }
            }
        }
        else if (file_info.Attributes & FS_ATTR_DIR)
        {
            /* skip "dot" and "dot dot". */
            if (mmi_ucs2strlen((CHAR*)buf_file_name) < 3)
            {
                if (mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)L".") &&
                    mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)L".."))
                {
                    context->search.stack[context->search.stack_index].total_sub_folder++;
                }
            }
            else
            {
                context->search.stack[context->search.stack_index].total_sub_folder++;
            }
        }
        
        ret = FS_FindNextN(
                        context->search.search_handle,
                        NULL,
                        0,
                        FS_ATTR_DIR,
                        &file_info,
                        (PU16)buf_file_name,
                        (MEDPLY_CUI_SEARCH_FILE_LEN) * ENCODING_LENGTH,
                        FS_FIND_DEFAULT);
    } while (ret == FS_NO_ERROR);
    FS_FindClose(context->search.search_handle);
    context->search.search_handle = -1;
    if (context->search.stack_index < MEDPLY_CUI_SEARCH_MAX_DEPTH_DIRECTORY)
    {
        context->search.phase = MEDPLY_CUI_SEARCH_PHASE_FORWARDS;
    }
    else
    {
        context->search.phase = MEDPLY_CUI_SEARCH_PHASE_BACKWARDS;
    }
    mmi_medply_cui_search_continue_req((void*)context);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_search_int_search_odf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_cui_search_int_search_odf(MMI_ID cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_cui_search_context_struct *context = (mmi_medply_cui_search_context_struct *)mmi_frm_group_get_user_data(cui_id);

#ifdef __DRM_V02__
    drm_file_info_struct drm_file_info; /* for a short variable name. */
    FS_HANDLE multi_part_handle;
    UI_character_type content_name[MEDPLY_CUI_SEARCH_FILE_LEN];
    UI_character_type temp_buffer[MEDPLY_CUI_SEARCH_PATH_LEN];
    UI_character_type file_ext[MEDPLY_CUI_SEARCH_EXT_LEN];
    S32 ret = MEDPLY_PLST_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (context == NULL)
    {
        mmi_frm_group_close(cui_id);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_GENEREATE_SEARCH_ERROR, -1, __LINE__);
        return;
    }
    context->search.DRM_find_cntx = DRM_get_find_cntx();
    multi_part_handle = DRM_find_firstN(
                                context->search.DRM_find_cntx,
                                (PU16)context->search.path_cache, 
                                0, 
                                0,
                                &drm_file_info,
                                content_name,
                                ((MEDPLY_CUI_SEARCH_FILE_LEN - 1)) * ENCODING_LENGTH,
                                0);
    if (multi_part_handle < FS_NO_ERROR)
    {
        /* because this memory will be free in DRM_find_firstN when DRM_find_firstN fail. */
        context->search.DRM_find_cntx = NULL;
        context->search.last_error_code = multi_part_handle;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_GENERATE_ODF, context->search.last_error_code, mmi_medply_get_current_time(), __LINE__);
        context->search.phase = MEDPLY_CUI_SEARCH_PHASE_ERR_HDLR;
        mmi_medply_cui_search_int((void*)context);
        return;
    }
    else
    {
        do
        {
            mmi_medply_util_extract_ext(content_name, file_ext);

            
            if (mmi_ucs2strlen((CHAR*)context->search.path_cache) + mmi_ucs2strlen((CHAR*)content_name) + 1 <= (MEDPLY_CUI_SEARCH_PATH_LEN - 1))
            {
                mmi_ret ret;
                MMI_BOOL is_skip = MMI_FALSE;
                filetypes_group_type_enum   file_grp;
                filetypes_file_type_enum    file_type;
                
                mmi_ucs2ncpy((CHAR*)context->search.file_path, (CHAR*)context->search.path_cache, (MEDPLY_CUI_SEARCH_PATH_LEN - 1));
                mmi_ucs2ncat((CHAR*)context->search.file_path, (CHAR*)L"\\", (MEDPLY_CUI_SEARCH_PATH_LEN - 1));
                mmi_ucs2ncat((CHAR*)context->search.file_path, (CHAR*)content_name, (MEDPLY_CUI_SEARCH_PATH_LEN - 1));
                switch (context->run_filter)
                {
                    case MEDPLY_CUI_SEARCH_FILTER_ALL_MEDIA:
                    {
                        break;
                    }
                    case MEDPLY_CUI_SEARCH_FILTER_AUDIO:
                    {
                        file_type = (filetypes_file_type_enum)srv_fmgr_types_find_type_by_filepath((WCHAR*)context->search.file_path);
                        file_grp = srv_fmgr_types_find_group_by_type(file_type);
                        if (file_grp != FMGR_GROUP_AUDIO)
                        {
                            is_skip = MMI_TRUE;
                        }
                        break;
                    }
                    case MEDPLY_CUI_SEARCH_FILTER_VIDEO:
                    {
                        file_type = (filetypes_file_type_enum)srv_fmgr_types_find_type_by_filepath((WCHAR*)context->search.file_path);
                        file_grp = srv_fmgr_types_find_group_by_type(file_type);
                        //MAUI_02316276
                        if (file_grp != FMGR_GROUP_VIDEO 
                        #ifdef __MMI_MEDIA_PLAYER_STREAM__
                            && file_grp != FMGR_GROUP_STREAM)
                        #else
                            )
                        #endif
                        {
                            is_skip = MMI_TRUE;
                        }
                        break;
                    }
                    default:
                        MMI_ASSERT(0);
                    
                }
                
                if (!is_skip)
                {
                    ret = mmi_medply_cui_search_send_evt(context->search.search_cui_gid, EVT_ID_MEDPLY_CUI_SEARCH_APPEND, NULL);
                    if (ret != MMI_RET_OK)
                    {
                        DRM_find_close(context->search.DRM_find_cntx, multi_part_handle);
                        context->search.DRM_find_cntx = NULL;
                        context->search.last_error_code = ret;
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_GENEREATE_SEARCH_ERROR, context->search.last_error_code, __LINE__);
                        context->search.phase = MEDPLY_CUI_SEARCH_PHASE_ERR_HDLR;
                        mmi_medply_cui_search_int((void*)context);
                        return;
                    }
                }
            }
            else
            {
                /* skip for path too deep !*/
            }
        } while (FS_NO_ERROR == DRM_find_nextN(
                                context->search.DRM_find_cntx,
                                multi_part_handle, 
                                &drm_file_info,
                                content_name,
                                ((MEDPLY_CUI_SEARCH_FILE_LEN - 1)) * ENCODING_LENGTH,
                                1));
    }

    if (context->search.DRM_find_cntx)
    {
        DRM_find_close(context->search.DRM_find_cntx, multi_part_handle);
        context->search.DRM_find_cntx = NULL;
    }

    context->search.phase = MEDPLY_CUI_SEARCH_PHASE_BACKWARDS;
    mmi_medply_cui_search_continue_req((void*)context);
    //mmi_medply_cui_search_start_timer(context->run_timer, 20, mmi_medply_cui_search_int, (void*)context);

#else
    context->search.last_error_code = MEDPLY_CUI_SEARCH_ERR_UNKNOW;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_GENERATE_ODF, context->search.last_error_code, mmi_medply_get_current_time(), __LINE__);
    context->search.phase = MEDPLY_CUI_SEARCH_PHASE_ERR_HDLR;
    mmi_medply_cui_search_int((void*)context);
#endif /*__DRM_V02__*/
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_search_int_forwards
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_cui_search_int_forwards(MMI_ID cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_cui_search_context_struct *context = (mmi_medply_cui_search_context_struct *)mmi_frm_group_get_user_data(cui_id);
    FS_HANDLE file_handle;
    S32 return_value = 0;
    FS_DOSDirEntry file_info;
    UI_character_type buf_file_name[MEDPLY_CUI_SEARCH_FILE_LEN + 2];
    /* for MAUI_01749831 add two word to monitor the range*/

    UI_character_type temp_path[MEDPLY_CUI_SEARCH_PATH_LEN];
    U16 counter = 0;
    U32 path_length = 0;
    U32 sub_folder_length = 0;
    U32 total_length = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (context == NULL)
    {
        mmi_frm_group_close(cui_id);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_GENEREATE_SEARCH_ERROR, -1, __LINE__);
        return;
    }
    MMI_ASSERT(context->search.stack_index < MEDPLY_CUI_SEARCH_MAX_DEPTH_DIRECTORY);
    if (!context->search.stack[context->search.stack_index].total_sub_folder)
    {
        /* no sub-folder, go backwards. */
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_GENERATE_LIST_FORWARD_GOBACK);
        context->search.phase = MEDPLY_CUI_SEARCH_PHASE_BACKWARDS;
        mmi_medply_cui_search_continue_req((void*)context);
        //mmi_medply_cui_search_start_timer(context->run_timer, 20, mmi_medply_cui_search_int, (void*)context);
        return;
    }
    else if (context->search.stack[context->search.stack_index].total_sub_folder == 
                                context->search.stack[context->search.stack_index].index)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_GENERATE_LIST_FORWARD_PASS_ALL_SUB_GOBACK);
        context->search.phase = MEDPLY_CUI_SEARCH_PHASE_BACKWARDS;
        mmi_medply_cui_search_continue_req((void*)context);
        //mmi_medply_cui_search_start_timer(context->run_timer, 20, mmi_medply_cui_search_int, (void*)context);
        return;
    }
    else    /* need forwards. */
    {
        mmi_ucs2ncpy((CHAR*)temp_path, (CHAR*)context->search.path_cache, (MEDPLY_CUI_SEARCH_PATH_LEN - 1));
        mmi_ucs2ncat((CHAR*)temp_path, (CHAR*)L"*.*", (MEDPLY_CUI_SEARCH_PATH_LEN - 1));
        buf_file_name[MEDPLY_CUI_SEARCH_FILE_LEN] = 0xFF;
        /* for MAUI_01749831 add two word to monitor the range*/
        file_handle = FS_FindFirstN(
                        (PU16)temp_path,
                        NULL,
                        0,
                        0,
                        0,
                        FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                        &file_info,
                        (PU16)buf_file_name,
                        (MEDPLY_CUI_SEARCH_FILE_LEN) * ENCODING_LENGTH,
                        context->search.stack[context->search.stack_index].fs_index,
                        FS_FIND_DEFAULT);
        ASSERT(buf_file_name[MEDPLY_CUI_SEARCH_FILE_LEN] == 0xFF);
        /* for MAUI_01749831 add two word to monitor the range*/
        if (file_handle >= 0)
        {
            do
            {
                counter++;
                /* test if pass the filter */
                if (file_info.Attributes & FS_ATTR_DIR)
                {
                    FS_FindClose(file_handle);

                    /* check path length. */
                    
                    path_length = mmi_ucs2strlen((CHAR*)context->search.path_cache);
                    sub_folder_length = mmi_ucs2strlen((CHAR*)buf_file_name);
                    total_length = 0;

                    total_length = path_length + sub_folder_length;
                    total_length++;	/*add length of "\"*/
                    if (total_length > (MEDPLY_CUI_SEARCH_PATH_LEN - 1)) 
                    {
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_GENERATE_LIST_FORWARD_PATH_LONG);
                        context->search.stack[context->search.stack_index].fs_index += counter;
                        context->search.stack[context->search.stack_index].index++;
                    }
                    else 
                    {
                        if ((context->search.stack_index + 1) < MEDPLY_CUI_SEARCH_MAX_DEPTH_DIRECTORY)
                        {
                            /* compose next level path. */
                            mmi_ucs2ncat((CHAR*)context->search.path_cache, (CHAR*)buf_file_name, (MEDPLY_CUI_SEARCH_PATH_LEN - 1));
                            mmi_ucs2ncat((CHAR*)context->search.path_cache, (CHAR*)L"\\", (MEDPLY_CUI_SEARCH_PATH_LEN - 1));

                            /* save level node info. */
                            context->search.stack[context->search.stack_index].fs_index += counter;
                            context->search.stack[context->search.stack_index].index++;
                            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_GENERATE_LIST_FORWARD_TO_NEXT,context->search.stack[context->search.stack_index].total_sub_folder, context->search.stack[context->search.stack_index].index, context->search.stack_index);                           
                            /* entry next level. */
                            context->search.stack_index++;
                            context->search.phase = MEDPLY_CUI_SEARCH_PHASE_SEARCH_FIRST;
                            
                            mmi_medply_cui_search_continue_req((void*)context);
                            //mmi_medply_cui_search_start_timer(context->run_timer, 20, mmi_medply_cui_search_int, (void*)context);
                            return;
                        }
                        else /* get max depth. */
                        {
                            /* to get next file, even have a sub-directory. */
                            context->search.phase = MEDPLY_CUI_SEARCH_PHASE_SEARCH_NEXT;
                            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_GENERATE_LIST_FORWARD_MAX_DEPTH);
                            mmi_medply_cui_search_continue_req((void*)context);
                            //mmi_medply_cui_search_start_timer(context->run_timer, 20, mmi_medply_cui_search_int, (void*)context);
                            return;
                        }
                    }
                }
                
                return_value = FS_FindNextN(
                                file_handle,
                                NULL,
                                0,
                                0,
                                &file_info,
                                (PU16)buf_file_name,
                                (MEDPLY_CUI_SEARCH_FILE_LEN) * ENCODING_LENGTH,
                                FS_FIND_DEFAULT);
                
            } while (return_value == FS_NO_ERROR);
            FS_FindClose(file_handle);
            /* no more sub-folder, backwards. */
            context->search.phase = MEDPLY_CUI_SEARCH_PHASE_BACKWARDS;
            mmi_medply_cui_search_continue_req((void*)context);
            //mmi_medply_cui_search_start_timer(context->run_timer, 20, mmi_medply_cui_search_int, (void*)context);
            return;
        }
        else
        {
            if (context->search.stack_index == 0)
            {
                if (file_handle == FS_NO_MORE_FILES)
                {
                    context->search.phase = MEDPLY_CUI_SEARCH_PHASE_BACKWARDS;
                    mmi_medply_cui_search_continue_req((void*)context);
                    //mmi_medply_cui_search_start_timer(context->run_timer, 20, mmi_medply_cui_search_int, (void*)context);
                }
                else
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_GENERATE_LIST_FORWARD_FINDFIRST_ERROR,file_handle);
                    context->search.last_error_code = file_handle;
                    context->search.phase = MEDPLY_CUI_SEARCH_PHASE_ERR_HDLR;
                    mmi_medply_cui_search_int((void*)context);
                }
            }
            else
            {
                context->search.phase = MEDPLY_CUI_SEARCH_PHASE_BACKWARDS;
                mmi_medply_cui_search_continue_req((void*)context);
                //mmi_medply_cui_search_start_timer(context->run_timer, 20, mmi_medply_cui_search_int, (void*)context);
            }
            return;
        }
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_search_int_backwards
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_cui_search_int_backwards(MMI_ID cui_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_cui_search_context_struct *context = (mmi_medply_cui_search_context_struct *)mmi_frm_group_get_user_data(cui_id);
    CHAR* last_backlash = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (context == NULL)
    {
        mmi_frm_group_close(cui_id);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_GENEREATE_SEARCH_ERROR, -1, __LINE__);
        return;
    }
    if (context->search.stack_index > 0)
    {   MMI_ASSERT(context->search.stack_index < MEDPLY_CUI_SEARCH_MAX_DEPTH_DIRECTORY);
        memset(&(context->search.stack[context->search.stack_index]), 0, 
                    sizeof(mmi_medply_plst_stack_node_struct));
        /* update path cache. */
        last_backlash = mmi_ucs2rchr((CHAR*)context->search.path_cache, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);
        *(last_backlash + 1) = 0;
        *last_backlash = 0;
        
        if (context->search.phase == MEDPLY_CUI_SEARCH_PHASE_BACKWARDS)
        {
            last_backlash = mmi_ucs2rchr((CHAR*)context->search.path_cache, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);
            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            
        }
        mmi_ucs2ncat((CHAR*)context->search.path_cache, (CHAR*)L"\\", (MEDPLY_CUI_SEARCH_PATH_LEN - 1));
        context->search.stack_index--;

        context->search.phase = MEDPLY_CUI_SEARCH_PHASE_FORWARDS;
        mmi_medply_cui_search_continue_req((void*)context);
        //mmi_medply_cui_search_start_timer(context->run_timer, 20, mmi_medply_cui_search_int, (void*)context);
    }
    else
    {
        if (context->run_type == MEDPLY_CUI_SEARCH_TYPE_UPDATE_FOLDER)
        {
            context->search.phase = MEDPLY_CUI_SEARCH_PHASE_FINISH;
            mmi_medply_cui_search_continue_req((void*)context);
            //mmi_medply_cui_search_start_timer(context->run_timer, 20, mmi_medply_cui_search_int, (void*)context);
        }
        else if (context->run_type == MEDPLY_CUI_SEARCH_TYPE_UPDATE_ALL_DRV)
        {
            context->search.phase = MEDPLY_CUI_SEARCH_PHASE_SET_DRV;
            mmi_medply_cui_search_continue_req((void*)context);
            //mmi_medply_cui_search_start_timer(context->run_timer, 20, mmi_medply_cui_search_int, (void*)context);
        }
        else
        {
            MMI_ASSERT(context->run_type < MEDPLY_CUI_SEARCH_TYPE_TOTAL);
        }
    }
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_search_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_cui_search_int(void* cntxt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_cui_search_context_struct *context = (mmi_medply_cui_search_context_struct *)cntxt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (context == NULL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        return;
    }
    
    if (mmi_frm_group_get_active_id() != context->search.waiting_scr_gid)
    {
        /* Sleep if the waitting screen has been in history. */
        mmi_medply_cui_search_start_timer(context->run_timer, 500, mmi_medply_cui_search_int, (void*)context);
        return;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_GENERATE_INTERNAL,context->search.phase, mmi_medply_get_current_time());
    
    switch (context->search.phase)
    {
        case MEDPLY_CUI_SEARCH_PHASE_SET_DRV:
            MMI_ASSERT(context->run_type == MEDPLY_CUI_SEARCH_TYPE_UPDATE_ALL_DRV);
            mmi_medply_cui_search_int_set_drv(context->search.search_cui_gid);
            return;
        case MEDPLY_CUI_SEARCH_PHASE_SEARCH_FIRST:
            mmi_medply_cui_search_int_search(context->search.search_cui_gid);
            return;
        case MEDPLY_CUI_SEARCH_PHASE_SEARCH_NEXT:
            mmi_medply_cui_search_int_search(context->search.search_cui_gid);
            return;
        case MEDPLY_CUI_SEARCH_PHASE_FORWARDS:
            mmi_medply_cui_search_int_forwards(context->search.search_cui_gid);
            return;
        case MEDPLY_CUI_SEARCH_PHASE_BACKWARDS:
            mmi_medply_cui_search_int_backwards(context->search.search_cui_gid);
            return;
        case MEDPLY_CUI_SEARCH_PHASE_SEARCH_ODF:
            mmi_medply_cui_search_int_search_odf(context->search.search_cui_gid);
            return;
        case MEDPLY_CUI_SEARCH_PHASE_END:
            return;

            
        case MEDPLY_CUI_SEARCH_PHASE_FINISH:
            mmi_medply_cui_search_send_evt(context->search.search_cui_gid, EVT_ID_MEDPLY_CUI_SEARCH_FINISH, NULL);
            return;
        case MEDPLY_CUI_SEARCH_PHASE_ERR_HDLR:
            mmi_medply_cui_search_send_evt(context->search.search_cui_gid, EVT_ID_MEDPLY_CUI_SEARCH_ERROR, NULL);
            return;
        case MEDPLY_CUI_SEARCH_PHASE_CANCEL:
            mmi_medply_cui_search_send_evt(context->search.search_cui_gid, EVT_ID_MEDPLY_CUI_SEARCH_CANCEL, NULL);
            return;        

            
        default: 
            MMI_ASSERT(context->search.phase <= MEDPLY_CUI_SEARCH_PHASE_END);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_search_start
 * DESCRIPTION
 *  start search.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_cui_search_start(mmi_id search_cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_cui_search_context_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    context = (mmi_medply_cui_search_context_struct *)mmi_frm_group_get_user_data(search_cui_gid);

    mmi_medply_cui_search_screen_entry(search_cui_gid);

    switch (context->run_type)
    {
        case MEDPLY_CUI_SEARCH_TYPE_UPDATE_FOLDER:
        {
            MMI_ASSERT(mmi_ucs2strlen((CHAR*)context->search.path_cache));
            
            if (context->is_multi_part_odf)
            {
                context->search.phase = MEDPLY_CUI_SEARCH_PHASE_SEARCH_ODF;
            }
            else
            {
                context->search.phase = MEDPLY_CUI_SEARCH_PHASE_SEARCH_FIRST;
            }
            break;
        }
        case MEDPLY_CUI_SEARCH_TYPE_UPDATE_ALL_DRV:
        {
            mmi_medply_cui_search_get_drv_letter(search_cui_gid);
            mmi_medply_cui_search_get_drv_status(search_cui_gid);
            context->search.phase = MEDPLY_CUI_SEARCH_PHASE_SET_DRV;
            break;
        }
        default:
            MMI_ASSERT(0);
            break;
    }
    
    mmi_medply_cui_search_continue_req((void*)context);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_generator_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_cui_search_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        /*************************Group event***************************/
        case EVT_ID_GROUP_DEINIT:
        {
            mmi_medply_cui_search_context_struct *context = (mmi_medply_cui_search_context_struct *)evt->user_data;
            if (context)
            {
                mmi_medply_cui_search_unprepare(context->search.search_cui_gid);
            }
            break;
        }

        /*************************Alert CUI event***************************/
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *confirm = (mmi_alert_result_evt_struct *)evt;
        
            switch (confirm->result)
            {
                case MMI_POPUP_INTERRUPT_EXIT:
                case MMI_ALERT_NORMAL_EXIT:
                {
                    break;
                }
                case MMI_ALERT_CNFM_OK:  
                case MMI_ALERT_CNFM_YES:         
                {
                    break;
                }
                case MMI_ALERT_CNFM_NO:         
                case MMI_ALERT_CNFM_CANCEL:      
                {
                    mmi_medply_cui_search_context_struct *context = confirm->user_tag;

                    mmi_medply_cui_search_send_evt(context->search.search_cui_gid, EVT_ID_MEDPLY_CUI_SEARCH_CANCEL, NULL);
                    mmi_alert_dismiss(confirm->alert_id);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        default:
        break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_search_prepare
 * DESCRIPTION
 *  Reset cui variable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_cui_search_prepare(mmi_id parent_id, S32 run_timer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_cui_search_context_struct *context = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    context = OslMalloc(sizeof(mmi_medply_cui_search_context_struct));
    if (NULL == context)
    {
        return MEDPLY_CUI_SEARCH_ERR_NO_MEMORY;
    }
    memset(context, 0, sizeof(mmi_medply_cui_search_context_struct));
    
    context->run_timer = run_timer;
    context->run_type = MEDPLY_CUI_SEARCH_TYPE_UPDATE_DEFAULT;
    context->run_filter = MEDPLY_CUI_SEARCH_FILTER_DEFAULT;
    context->search.search_cui_gid = 
        mmi_frm_group_create(parent_id, GRP_ID_AUTO_GEN, mmi_medply_cui_search_proc, context);
    SetProtocolEventHandler(mmi_medply_cui_search_int_proc, MSG_ID_MMI_LIST_SEARCH_CUI_SEARCH_INT_REQ);
    return context->search.search_cui_gid;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_search_unprepare
 * DESCRIPTION
 *  Reset cui variable
 * PARAMETERS
 *  search_cui_gid
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_cui_search_unprepare(mmi_id search_cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_cui_search_context_struct *context = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(MSG_ID_MMI_LIST_SEARCH_CUI_SEARCH_INT_REQ);
    context = (mmi_medply_cui_search_context_struct *)mmi_frm_group_get_user_data(search_cui_gid);

    if (context)
    {
        StopTimer(context->run_timer);
        if (context->search.search_handle > 0)
        {
            FS_FindClose(context->search.search_handle);
        }
        memset(context, 0, sizeof(mmi_medply_cui_search_context_struct));
        OslMfree(context);
    }
    
    mmi_frm_group_close(search_cui_gid);

}

#define __SEARCH_CUI_EXT

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_gen_create
 * DESCRIPTION
 *  Creat search cui.
 * PARAMETERS
 *  parent_gid  :  [IN]  parent id.
 * RETURNS
 *  mmi_id.
 *****************************************************************************/
mmi_id mmi_medply_cui_search_create(mmi_id parent_id, S32 run_timer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result = mmi_medply_cui_search_prepare(parent_id, run_timer);
    if (result < MEDPLY_CUI_SEARCH_ERR_NO_ERROR)
    {
        return GRP_ID_INVALID;
    }
    else
    {
        return result;
    }


}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_generator_run
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_cui_search_run(mmi_id search_cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_cui_search_context_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_enter(search_cui_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    context = (mmi_medply_cui_search_context_struct *)mmi_frm_group_get_user_data(search_cui_gid);
    MMI_ASSERT(context->search.search_cui_gid == search_cui_gid);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_SEARCH_RUN_MODE,context->run_type ,search_cui_gid ,mmi_medply_get_current_time(), __LINE__);
    if (MEDPLY_CUI_SEARCH_TYPE_UPDATE_ALL_DRV == context->run_type)
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_REFRESH_BEGIN,mmi_medply_get_current_time());
    mmi_medply_cui_search_start(search_cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_search_close
 * DESCRIPTION
 *  Close function for search cui.
 * PARAMETERS
 *  search_cui_gid   :  [IN]  search group id.
 * RETURNS
 *  None.
 *****************************************************************************/
void mmi_medply_cui_search_close(mmi_id search_cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_cui_search_context_struct *context;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    context = (mmi_medply_cui_search_context_struct *)mmi_frm_group_get_user_data(search_cui_gid);
    if (context)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_SEARCH_CLOSE_MODE,context->run_type ,search_cui_gid ,mmi_medply_get_current_time(), __LINE__);
        if (MEDPLY_CUI_SEARCH_TYPE_UPDATE_ALL_DRV == context->run_type)
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_REFRESH_END,mmi_medply_get_current_time());
    }
    mmi_frm_group_close(search_cui_gid);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_search_set_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  None.
 *****************************************************************************/
void mmi_medply_cui_search_set_path(mmi_id search_cui_gid, WCHAR* folder_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_cui_search_context_struct *context = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    context = (mmi_medply_cui_search_context_struct *)mmi_frm_group_get_user_data(search_cui_gid);
    if (folder_path)
    {
        mmi_ucs2ncpy((CHAR*)context->search.path_cache, (CHAR*)folder_path, (MEDPLY_CUI_SEARCH_PATH_LEN - 1));
    }
    else
    {
        context->search.path_cache[0] = '\0';
        context->search.path_cache[1] = '\0';
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_search_set_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  None.
 *****************************************************************************/
void mmi_medply_cui_search_set_mode(mmi_id search_cui_gid, mmi_medply_cui_search_type run_type, mmi_medply_cui_search_filter run_filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_cui_search_context_struct *context = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    context = (mmi_medply_cui_search_context_struct *)mmi_frm_group_get_user_data(search_cui_gid);
    if (run_type < MEDPLY_CUI_SEARCH_TYPE_TOTAL)
    {
        context->run_type = run_type;
    }
    else
    {
        context->run_type = MEDPLY_CUI_SEARCH_TYPE_UPDATE_DEFAULT;
    }

    if (run_filter < MEDPLY_CUI_SEARCH_FILTER_TOTAL)
    {
        context->run_filter= run_filter;
    }
    else
    {
        context->run_filter = MEDPLY_CUI_SEARCH_FILTER_DEFAULT;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_cui_search_set_multi_part_odf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  None.
 *****************************************************************************/
void mmi_medply_cui_search_set_multi_part_odf(mmi_id search_cui_gid, MMI_BOOL is_multi_part_odf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_cui_search_context_struct *context = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    context = (mmi_medply_cui_search_context_struct *)mmi_frm_group_get_user_data(search_cui_gid);
    if (is_multi_part_odf)
    {
        context->is_multi_part_odf = 1;
    }
    else
    {
        context->is_multi_part_odf = 0;
    }

}


/********************************* search cui *************************************/

#define __GENERATER
typedef S32 (*CompFuncPtr)(const void *, const void *);

/*****************************************************************************
 * FUNCTION
 *  __swap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_swap(CHAR *a, CHAR *b, U32 width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR tmp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (a != b)
    {
        while (width--) 
        {
            tmp = *a;
            *a++ = *b;
            *b++ = tmp;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  __comp
 * DESCRIPTION
 *  compare to index
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_comp(const void* a, const void* b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((*(mmi_medply_plst_index_node_struct*)a).index - (*(mmi_medply_plst_index_node_struct*)b).index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_qsort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_qsort(void *sort_base, U32 number, U32 data_width, CompFuncPtr compare_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *low_item_ptr, *hight_item_ptr, *low_ptr, *high_ptr, *middle_ptr;
    CHAR *low_stack[30], *high_stack[30];
    S32 stack_ptr = 0;
    U32 buffer_size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(2 > number || 0 == data_width) 
    {
        return;
    }

    high_ptr = (CHAR *) sort_base + data_width * (number - 1);
    low_ptr = sort_base;

recursion:
    buffer_size = (high_ptr - low_ptr) / data_width + 1;
    middle_ptr = low_ptr + (buffer_size / 2) * data_width;
    mmi_medply_swap(middle_ptr, low_ptr, data_width);
    hight_item_ptr = data_width + high_ptr;
    low_item_ptr = low_ptr;

    do
    {
        do 
        { 
            low_item_ptr += data_width; 
        } while (low_item_ptr <= high_ptr && compare_func(low_item_ptr, low_ptr) <= 0);
        
        do 
        { 
            hight_item_ptr -= data_width; 
        } while (hight_item_ptr > low_ptr && compare_func(hight_item_ptr, low_ptr) >= 0);
        
        if (low_item_ptr > hight_item_ptr) 
        {
            break;
        }
        mmi_medply_swap(low_item_ptr, hight_item_ptr, data_width);
    }while(1);

    mmi_medply_swap(low_ptr, hight_item_ptr, data_width);

    if (high_ptr - low_item_ptr > hight_item_ptr - low_ptr - 1) 
    {
        if (low_item_ptr < high_ptr) 
        {
            high_stack[stack_ptr] = high_ptr;
            low_stack[stack_ptr] = low_item_ptr;
            ++stack_ptr;
        }
        if (low_ptr + data_width < hight_item_ptr) 
        {
            high_ptr = hight_item_ptr - data_width;
            goto recursion;
        }
    }
    else
    {
        if (hight_item_ptr > low_ptr + data_width) 
        {
            high_stack[stack_ptr] = hight_item_ptr - data_width;
            low_stack[stack_ptr] = low_ptr;
            ++stack_ptr;
        }
        if (high_ptr > low_item_ptr) 
        {
            low_ptr = low_item_ptr;
            goto recursion;
        }
    }

    --stack_ptr;
    if (stack_ptr >= 0) 
    {
        high_ptr = high_stack[stack_ptr];
        low_ptr = low_stack[stack_ptr];
        goto recursion;
    }
    else
    {
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_generate_sort_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index  [?]
 *  total  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_generate_sort_index(
            mmi_medply_plst_index_node_struct* index, U32 total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_GENERATE_SORT_BEGIN,mmi_medply_get_current_time());
    mmi_medply_qsort(index, total, sizeof(mmi_medply_plst_index_node_struct), mmi_medply_comp);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_GENERATE_SORT_END,mmi_medply_get_current_time());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_generate_append_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path       [IN]
 *  is_short   [IN]
 *  write_back_file_immediately   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_medply_plst_generate_append_internal(UI_string_type path, MMI_BOOL is_short, MMI_BOOL write_back_file_immediately)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 write_size = 0;
    U32 insert_offset = 0;
    U32 next_block = 0;
    U32 used_size = 0;
    S32 ret = 0;
    U16 i = 0;
    
    mmi_medply_plst_index_node_struct new_node;
    mmi_medply_plst_block_node_struct block;
    CHAR path_buff[MEDPLY_MAX_PATH_SIZE];
    mmi_medply_plst_struct* list = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    memset(path_buff, 0, MEDPLY_MAX_PATH_SIZE);
    if (in_add_to_mode)
    {
        if (addto_now_playing)
        {
            list = &(plst_cntx_p->current_list);
        }
        else
        {
            list = plst_cntx_p->backup_list_p;
        }
    }
    else
    {
        if (browser_now_playing)
        {
            list = &(plst_cntx_p->current_list);
        }
        else
        {
            list = plst_cntx_p->browser_list_p;
        }
    }
    /* make new node data. */
    memset(&new_node, 0, sizeof(mmi_medply_plst_index_node_struct));
    new_node.offset = list->header.footer_pattern_offset;
    new_node.index = list->total;
    
    if (is_short)
    {
        new_node.is_active = 2;
    }
    else
    {
        new_node.is_active = 1;
    }

    mmi_ucs2ncpy((CHAR*)path_buff, (CHAR*)path, (MEDPLY_MAX_PATH_LEN - 1));

    
    used_size = mmi_ucs2strlen((CHAR*)path_buff);
    used_size *= ENCODING_LENGTH;	/* turn to byte. ???ENCODING_LENGTH bql*/
    new_node.used_block = used_size / MMI_MEDPLY_BLOCK_DATA_SIZE;

    if (used_size % MMI_MEDPLY_BLOCK_DATA_SIZE > 0)
    {
        new_node.used_block++;
    }
    MMI_ASSERT(new_node.used_block <= MMI_MEDPLY_MAX_BLOCK_NUM);
    if (list->header.empty_node.used_block >= new_node.used_block)
    {
        mmi_medply_plst_index_node_struct target_node;
        /* backup relative variables. */
        memcpy(&target_node, &(list->header.index[list->total]), sizeof(mmi_medply_plst_index_node_struct));

        if (!list->header.empty_node.offset)
        {
            /* something wrong about link of empty nodes. */
            return MEDPLY_PLST_ERR_LIST_DAMAGED;
        }
        
        list->header.index[list->total].index = list->total;
        list->header.index[list->total].is_active = new_node.is_active;
        list->header.index[list->total].used_block = new_node.used_block;
        list->header.index[list->total].offset = list->header.empty_node.offset;
        /* check empty nodes will be used. */
        insert_offset = list->header.empty_node.offset;
        next_block = insert_offset;
        for (i = 0; i < new_node.used_block; i++)
        {
            /* seek to blcok. */
            ret = FS_Seek(list->fs_hdlr, next_block, FS_FILE_BEGIN);
            if (ret < FS_NO_ERROR)
            {
                break;
            }
            insert_offset = next_block;
            /* read block to get next ptr. */
            ret = FS_Read(list->fs_hdlr, &block, sizeof(mmi_medply_plst_block_node_struct), &write_size);
            if (ret < FS_NO_ERROR)
            {
                break;
            }
            else if (write_size != sizeof(mmi_medply_plst_block_node_struct))
            {
                ret = MEDPLY_PLST_ERR_READ_FAILED;
                break;
            }
            /* check block. */
            if (block.pattern_begin != MEDPLY_PLAYLIST_BLOCK_PATTERN_1 ||
                block.pattern_end != MEDPLY_PLAYLIST_BLOCK_PATTERN_2)
            {
                ret = MEDPLY_PLST_ERR_LIST_DAMAGED;
                break;
            }
            
            next_block = block.next_ptr;
            if (!next_block && (i < new_node.used_block - 1))
            {
                ret = MEDPLY_PLST_ERR_LIST_DAMAGED;
                break;
            }
        }

        if (ret < FS_NO_ERROR)
        {
            /* check link of empty nodes failed. */
            return ret;
        }

        /* write to file. */
        insert_offset = list->header.empty_node.offset;
        next_block = insert_offset;
        for (i = 0; i < new_node.used_block; i++)
        {           
            /* seek to block. */
            ret = FS_Seek(list->fs_hdlr, next_block, FS_FILE_BEGIN);
            if (ret < FS_NO_ERROR)
            {
                break;
            }
            insert_offset = next_block;
            /* read block to get next ptr. */
            ret = FS_Read(list->fs_hdlr, &block, sizeof(mmi_medply_plst_block_node_struct), &write_size);
            if (ret < FS_NO_ERROR)
            {
                break;
            }
            else if (write_size != sizeof(mmi_medply_plst_block_node_struct))
            {
                ret = MEDPLY_PLST_ERR_READ_FAILED;
                break;
            }
            /* check block. */
            if (block.pattern_begin != MEDPLY_PLAYLIST_BLOCK_PATTERN_1 ||
                block.pattern_end != MEDPLY_PLAYLIST_BLOCK_PATTERN_2)
            {
                ret = MEDPLY_PLST_ERR_LIST_DAMAGED;
                break;
            }
            
            next_block = block.next_ptr;
            if (!next_block && (i < new_node.used_block - 1))
            {
                MMI_ASSERT(next_block != 0);
            }
            /* make new block data. */
            memcpy(&(block.data), &(path_buff[i * MMI_MEDPLY_BLOCK_DATA_SIZE]), MMI_MEDPLY_BLOCK_DATA_SIZE);

            /* seek back to the begin of current block. */
            ret = FS_Seek(list->fs_hdlr, insert_offset, FS_FILE_BEGIN);
            if (ret < FS_NO_ERROR)
            {
                break;
            }

            /* set next_ptr of tail node as NULL. */
            if (i == new_node.used_block - 1)
            {
                block.next_ptr = 0;
            }
            
            /* write new block data. */   
            ret = FS_Write(list->fs_hdlr, &block, 
                            sizeof(mmi_medply_plst_block_node_struct), &write_size);
            if (ret < FS_NO_ERROR)
            {
                break;
            }
            if (write_size != sizeof(mmi_medply_plst_block_node_struct))
            {
                ret = MEDPLY_PLST_ERR_WRITE_FAILED;
                break;
            }
        }

        if (ret < FS_NO_ERROR)
        {
            if (i > 0)
            {
                /* 
                **  some blocks have been wrote to file.
                **  because the file size has not changed.
                **  only reset index node.
                */
                memcpy(&(list->header.index[list->total]), &target_node, sizeof(mmi_medply_plst_index_node_struct));
            }
        }
        else
        {
            /* append successfully. */
            list->total++;
            list->header.total_slot++;
            list->header.empty_node.offset = next_block;
            list->header.empty_node.used_block -= new_node.used_block;
            
            if (!next_block)
            {
                list->header.empty_node.used_block = 0;
            }
            if (write_back_file_immediately)
            {
                ret = mmi_medply_plst_write_back_to_file(list);
            }

            plst_cntx_p->generate_cntx.appended++;
            plst_cntx_p->generate_cntx.list_total++;
            MMI_ASSERT(plst_cntx_p->generate_cntx.list_total <= MMI_MEDPLY_GENERATE_LIMIT);
        }
                
        return ret;
    }
    else
    {
        MMI_BOOL have_enough_space = MMI_FALSE;
        U32 require_size = new_node.used_block * sizeof(mmi_medply_plst_block_node_struct);
        CHAR drv_letter = (CHAR)list->path[0];
        
        have_enough_space = mmi_medply_util_check_free_space((CHAR)drv_letter, require_size);
        if (have_enough_space)
        {
            mmi_medply_plst_index_node_struct target_node;
            /* backup relative variables. */
            memcpy(&target_node, &(list->header.index[list->total]), sizeof(mmi_medply_plst_index_node_struct));

            list->header.index[list->total].index = list->total;
            list->header.index[list->total].is_active = new_node.is_active;
            list->header.index[list->total].used_block = new_node.used_block;
            list->header.index[list->total].offset = list->header.footer_pattern_offset;
            /*
            **  write map back->write new node->read new map->sort->write back new map
            **  more file system operation in order to avoid make memory flagment.
            */
            do 
            {   
                insert_offset = list->header.footer_pattern_offset;
                /* write new path. */ 
                ret = FS_Seek(list->fs_hdlr, insert_offset, FS_FILE_BEGIN);
                if (ret < FS_NO_ERROR)
                {
                    break;
                }
                
                for (i = 0; i < new_node.used_block; i++)
                {      
                    mmi_medply_plst_block_node_struct block;
                    block.pattern_begin = MEDPLY_PLAYLIST_BLOCK_PATTERN_1;
                    block.pattern_end = MEDPLY_PLAYLIST_BLOCK_PATTERN_2;
                    
                    insert_offset += sizeof(mmi_medply_plst_block_node_struct);
                    if (i + 1 == new_node.used_block)
                    {
                        block.next_ptr = 0;
                    }
                    else
                    {
                        block.next_ptr = insert_offset;
                    }
                    memcpy(&(block.data), &(path_buff[i * MMI_MEDPLY_BLOCK_DATA_SIZE]), MMI_MEDPLY_BLOCK_DATA_SIZE);
                    
                    /* write new path. */   
                    ret = FS_Write(list->fs_hdlr, &block, 
                                    sizeof(mmi_medply_plst_block_node_struct), &write_size);
                    if (ret < FS_NO_ERROR)
                    {
                        break;
                    }
                    if (write_size != sizeof(mmi_medply_plst_block_node_struct))
                    {
                        ret = MEDPLY_PLST_ERR_WRITE_FAILED;
                        break;
                    }
                }

                if (ret < FS_NO_ERROR)
                {
                    if (i > 0)
                    {
                        /* 
                        **  some blocks have been wrote to file.
                        **  because the file size has been changed.
                        **  overwrite index area from new node first block.
                        */
                        memcpy(&(list->header.index[list->total]), &target_node, sizeof(mmi_medply_plst_index_node_struct));

                        ret = mmi_medply_plst_write_back_to_file(list);
                    }
                }
                else
                {
                    /* update index area offset. */
                    list->header.footer_pattern_offset += new_node.used_block * sizeof(mmi_medply_plst_block_node_struct);
                    list->header.total_slot++;
                    list->total++;
                    if (write_back_file_immediately)
                    {
                        ret = mmi_medply_plst_write_back_to_file(list);
                        if (browser_now_playing)
                        {
                            if (list->pick_index < 0)
                            {
                                if (mmi_medply_plst_do_pick() >= 0)
                                {
                                    mmi_medply_plst_apply_picked_file();
                                }
                            }
                        }
                    }
                    plst_cntx_p->generate_cntx.appended++;
                    plst_cntx_p->generate_cntx.list_total++;
                    MMI_ASSERT(plst_cntx_p->generate_cntx.list_total <= MMI_MEDPLY_GENERATE_LIMIT);
                }
            } while (0);

            return ret;
        }
        else
        {
            return MEDPLY_PLST_ERR_NO_SPACE;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_generate_append_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_medply_plst_generate_append_hdlr(UI_string_type path, MMI_BOOL is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = FS_NO_ERROR;
    U16 file_format = MEDPLY_FORMAT_NONE;
    UI_character_type file_ext[MEDPLY_MAX_EXT_LEN];
    mmi_medply_plst_generate_struct* gen_p = &(plst_cntx_p->generate_cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (gen_p->list_total < MMI_MEDPLY_GENERATE_LIMIT)
    {
        mmi_medply_util_extract_ext(path, file_ext);
        file_format = mmi_medply_util_is_target_support_format(file_ext);
        if (file_format < MEDPLY_FORMAT_TOTAL && file_format != MEDPLY_FORMAT_NONE)
        {
            ret = mmi_medply_plst_generate_append_internal((UI_string_type) path, MMI_FALSE, MMI_FALSE);
        }
    }
    else
    {
        ret = MEDPLY_PLST_ERR_LIST_FULL;
    }
    
    return ret;

}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_generate_finish_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_plst_generate_finish_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plst_generate_struct* this = &(plst_cntx_p->generate_cntx);
    mmi_medply_plst_struct* list = plst_cntx_p->browser_list_p;
    S32 ret = FS_NO_ERROR;

    MMI_BOOL is_empty = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if (browser_now_playing)
    {
        list = &(plst_cntx_p->current_list);
    }

    if (this->appended)
    {
        mmi_medply_plst_generate_sort_index(list->header.index, list->header.total_slot);
        MMI_ASSERT(list->header.pattern == MEDPLY_PLAYLIST_FOOTER_PATTERN);
        ret = mmi_medply_plst_write_back_to_file(list);
        if (browser_now_playing)
        {
            if (list->pick_index < 0)
            {
                if (mmi_medply_plst_do_pick() >= 0)
                {
                    mmi_medply_plst_apply_picked_file();
                }
            }
        }
    }
    else
    {
        is_empty = MMI_TRUE;
    }



    if (ret < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GENERRATE_ERROR_HANDLE,ret);
        mmi_medply_plst_popup_simple(ret);
        mmi_frm_group_close(GRP_ID_MEDPLY_LIST_ADD);
    }
    else
    {         
        if (is_empty)
        {
            mmi_medply_plst_popup_simple_with_string(get_string(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE);
        }
        else
        {
	/* removed for new UE */
#if 0
/* under construction !*/
#endif
            mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_LIST_BROWSER, SCR_ID_MEDPLY_LIST_BROWSER);
            mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_LIST_BROWSER_CURR, SCR_ID_MEDPLY_LIST_BROWSER);
            mmi_frm_group_close(GRP_ID_MEDPLY_LIST_ADD);
        }
    }
    memset(&plst_cntx_p->generate_cntx, 0, sizeof(mmi_medply_plst_generate_struct));
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_generate_error_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_generate_error_hdlr(S32 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plst_generate_struct* this = &(plst_cntx_p->generate_cntx);
    mmi_medply_plst_struct* list = plst_cntx_p->browser_list_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (browser_now_playing)
    {
        list = &(plst_cntx_p->current_list);
    }
    
    if (this->appended)
    {
        mmi_medply_plst_generate_sort_index(list->header.index, list->header.total_slot);
        MMI_ASSERT(list->header.pattern == MEDPLY_PLAYLIST_FOOTER_PATTERN);
        mmi_medply_plst_write_back_to_file(list);
        mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_LIST_BROWSER, SCR_ID_MEDPLY_LIST_BROWSER);
        mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_LIST_BROWSER_CURR, SCR_ID_MEDPLY_LIST_BROWSER);
    }

    if (error_code != 0)
    {
        mmi_medply_plst_popup_simple(error_code);
    }
    
    if (browser_now_playing)
    {
        if (list->pick_index < 0)
        {
            if (mmi_medply_plst_do_pick() >= 0)
            {
                mmi_medply_plst_apply_picked_file();
            }
        }
    }
    memset(&plst_cntx_p->generate_cntx, 0, sizeof(mmi_medply_plst_generate_struct));
    mmi_frm_group_close(GRP_ID_MEDPLY_LIST_ADD);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_generate_cancel_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_generate_cancel_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plst_generate_struct* this = &(plst_cntx_p->generate_cntx);
    mmi_medply_plst_struct* list = plst_cntx_p->browser_list_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (browser_now_playing)
    {
        list = &(plst_cntx_p->current_list);
    }
    
    if (this->appended)
    {
        mmi_medply_plst_generate_sort_index(list->header.index, list->header.total_slot);
        MMI_ASSERT(list->header.pattern == MEDPLY_PLAYLIST_FOOTER_PATTERN);
        mmi_medply_plst_write_back_to_file(list);
        mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_LIST_BROWSER, SCR_ID_MEDPLY_LIST_BROWSER);
        mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_LIST_BROWSER_CURR, SCR_ID_MEDPLY_LIST_BROWSER);
        if (browser_now_playing)
        {
            if (list->pick_index < 0)
            {
                if (mmi_medply_plst_do_pick() >= 0)
                {
                    mmi_medply_plst_apply_picked_file();
                }
            }
        }
    }
    memset(&plst_cntx_p->generate_cntx, 0, sizeof(mmi_medply_plst_generate_struct));
    mmi_frm_group_close(GRP_ID_MEDPLY_LIST_ADD);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_generate_from_folder
 * DESCRIPTION
 *  start generate list from folder.
 * PARAMETERS
 *  path                [IN]
 *  is_multi_part_odf   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_generate_from_folder(UI_string_type path, MMI_BOOL is_multi_part_odf)
{
    static mmi_ret mmi_medply_plst_proc(mmi_event_struct *evt);
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_LIST_GEN, mmi_medply_plst_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_LIST_GEN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_gid = mmi_medply_cui_search_create(GRP_ID_MEDPLY_LIST_GEN, MEDPLY_GENERATE_TIMER);

    if (cui_gid > GRP_ID_INVALID)
    {
        if (browser_all_video)
        {
            /* only all video uses video filter */
            mmi_medply_cui_search_set_mode(cui_gid, MEDPLY_CUI_SEARCH_TYPE_UPDATE_FOLDER, MEDPLY_CUI_SEARCH_FILTER_VIDEO);
        }
        
#ifdef MMI_MEDPLY_PLST_VIDEO_INTEGRATED
        else if (browser_all_audio)
        {
            /* others use audio filter */
            mmi_medply_cui_search_set_mode(cui_gid, MEDPLY_CUI_SEARCH_TYPE_UPDATE_FOLDER, MEDPLY_CUI_SEARCH_FILTER_AUDIO);
        }
        else
        {
            /* others use audio filter */
            mmi_medply_cui_search_set_mode(cui_gid, MEDPLY_CUI_SEARCH_TYPE_UPDATE_FOLDER, MEDPLY_CUI_SEARCH_FILTER_ALL_MEDIA);
        }
#else
        else
        {
            /* others use audio filter */
            mmi_medply_cui_search_set_mode(cui_gid, MEDPLY_CUI_SEARCH_TYPE_UPDATE_FOLDER, MEDPLY_CUI_SEARCH_FILTER_AUDIO);
        }
#endif/* MMI_MEDPLY_PLST_VIDEO_FILTER */

        mmi_medply_cui_search_set_multi_part_odf(cui_gid, is_multi_part_odf);
        mmi_medply_cui_search_set_path(cui_gid, (WCHAR *) path);
        mmi_medply_cui_search_run(cui_gid);
    }
    else
    {   
        mmi_medply_plst_popup_simple_with_string( (U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
    }
}

#define __PLAYLIST

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_cui_hdlr_search
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_plst_cui_hdlr_search(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_MEDPLY_CUI_SEARCH_CLOSE:
        {
            mmi_medply_cui_search_close_event_struct *close = 
                (mmi_medply_cui_search_close_event_struct *)evt;
            mmi_medply_plst_generate_cancel_hdlr();
            mmi_medply_cui_search_close(close->sender_id);
            break;
        }
        case EVT_ID_MEDPLY_CUI_SEARCH_FINISH:
        {
            mmi_medply_cui_search_finish_event_struct *finish = 
                (mmi_medply_cui_search_finish_event_struct *)evt;
            mmi_medply_plst_generate_finish_hdlr();
            mmi_medply_cui_search_close(finish->sender_id);
            break;
        }
        case EVT_ID_MEDPLY_CUI_SEARCH_ERROR:
        {
            mmi_medply_cui_search_error_event_struct *error = 
                (mmi_medply_cui_search_error_event_struct *)evt;
            mmi_medply_plst_generate_error_hdlr(error->error_code);
            mmi_medply_cui_search_close(error->sender_id);
            break;
        }
        case EVT_ID_MEDPLY_CUI_SEARCH_CANCEL:
        {
            mmi_medply_cui_search_cancel_event_struct *cancel = 
                (mmi_medply_cui_search_cancel_event_struct *)evt;
            mmi_medply_plst_generate_cancel_hdlr();
            mmi_medply_cui_search_close(cancel->sender_id);
            break;
        }
        case EVT_ID_MEDPLY_CUI_SEARCH_APPEND: 
        {
            S32 ret = FS_NO_ERROR;
            
            mmi_medply_cui_search_append_event_struct *append = 
                (mmi_medply_cui_search_append_event_struct *)evt;
            ret = mmi_medply_plst_generate_append_hdlr(append->filepath, MMI_FALSE);
            if (ret < FS_NO_ERROR)
            {
                return ret;
            }
            else
            {
                return MMI_RET_OK;
            }
            //break;
        }
        default:
            break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_cui_hdlr_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_plst_cui_hdlr_menu(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_ENTRY_SELECT, menu_evt->parent_menu_id, menu_evt->highlighted_menu_id, plst_cntx_p->list_ui.highlight, __LINE__);
            /*
            cui_menu_enable_center_softkey(menu_evt->sender_id, 0, IMG_GLOBAL_COMMON_CSK);
            cui_menu_set_currlist_left_softkey(menu_evt->sender_id, (WCHAR*)GetString(STR_GLOBAL_OK));
            */
            if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_LISTMGR_OPTION_MENU)
            {
                mmi_medply_plst_listmgr_option_config(menu_evt);
                break;
            }
            else if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_PLST_OPTION_MENU)
            {
                mmi_medply_plst_option_config(menu_evt);
                break;
            }
        #ifdef __MMI_MEDIA_PLAYER_STREAM__
            else if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_BOOKMARK_MENU)
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
                break;
            }
        #endif    
            
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_ENTRY_SELECT, menu_evt->parent_menu_id, menu_evt->highlighted_menu_id, plst_cntx_p->list_ui.highlight, __LINE__);
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
            break;
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            
            if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_LISTMGR_OPTION_MENU)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_ENTRY_SELECT, menu_evt->parent_menu_id, menu_evt->highlighted_menu_id, plst_cntx_p->list_ui.highlight, __LINE__);
                switch(menu_evt->highlighted_menu_id)
                {
                    case MENU_ID_MEDPLY_LISTMGR_OPTION_LOAD:
                        mmi_medply_plst_listmgr_open();
                        break;
                    case MENU_ID_MEDPLY_LISTMGR_OPTION_NEW:
                        mmi_medply_plst_listmgr_create_part1();
                        break;
                    case MENU_ID_MEDPLY_LISTMGR_OPTION_DELETE:
                        mmi_medply_plst_listmgr_delete_part1();
                        break;
                    case MENU_ID_MEDPLY_LISTMGR_OPTION_DELETEALL:
                        mmi_medply_plst_listmgr_deleteall_part1();
                        break;
                    case MENU_ID_MEDPLY_LISTMGR_OPTION_RENAME:
                        mmi_medply_plst_listmgr_rename_part1();
                        break;
                #if !defined(__MMI_KURO_SUPPORT__)
                    case MENU_ID_MEDPLY_LISTMGR_OPTION_STORAGE:
                        mmi_medply_plst_listmgr_select_storage();
                        break;
                #endif        
                    case MENU_ID_MEDPLY_LISTMGR_OPTION_SETTINGS:
                        mmi_medply_plst_listmgr_settings();
                        break;
                        
                }
            }
            else if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_PLST_OPTION_MENU)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_ENTRY_SELECT, menu_evt->parent_menu_id, menu_evt->highlighted_menu_id, plst_cntx_p->list_ui.highlight, __LINE__);
                switch(menu_evt->highlighted_menu_id)
                {
                    case MENU_ID_MEDPLY_PLST_OPTION_REFRESH:
                        mmi_medply_plst_option_update();
                        break;
                    case MENU_ID_MEDPLY_PLST_OPTION_PLAY:
                        mmi_medply_plst_option_initiate_play();
                        break;
                #ifdef __MMI_KURO_SUPPORT__
                    case MENU_ID_MEDPLY_PLST_OPTION_ACTIVATE:
                        mmi_medply_kuro_plst_option_activate();
                        break;
                #endif
                    case MENU_ID_MEDPLY_PLST_OPTION_DETAILS:
                        mmi_medply_plst_entry_details_internal();
                        break;
                    case MENU_ID_MEDPLY_PLST_OPTION_MOVEUP:
                        mmi_medply_plst_option_moveup();
                        break;
                    case MENU_ID_MEDPLY_PLST_OPTION_MOVEDOWN:
                        mmi_medply_plst_option_movedown();
                        break;
                    case MENU_ID_MEDPLY_PLST_OPTION_ADD:
                        mmi_medply_plst_option_add_part1();
                        break;
                    case MENU_ID_MEDPLY_PLST_OPTION_ADD_TO_PLAYLIST:
                        mmi_medply_plst_option_add_to_part1();
                        break;
                    case MENU_ID_MEDPLY_PLST_OPTION_REMOVE:
                        mmi_medply_plst_option_remove(MMI_FALSE);
                        break;
                    case MENU_ID_MEDPLY_PLST_OPTION_DELETE:
                        mmi_medply_plst_option_remove(MMI_TRUE);
                        break;
                    case MENU_ID_MEDPLY_PLST_OPTION_SEND:
                        mmi_medply_plst_option_send(menu_evt);
                        break;
                    case MENU_ID_MEDPLY_PLST_OPTION_USE:
                        mmi_medply_plst_option_use(menu_evt);
                        break;
                    case MENU_ID_MEDPLY_PLST_OPTION_SETTINGS:
                        mmi_medply_plst_option_settings();
                        break;
                }
            }
            else if (menu_evt->parent_menu_id == playlist_fwd_option_menu_id)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_ENTRY_SELECT, menu_evt->parent_menu_id, menu_evt->highlighted_menu_id, plst_cntx_p->list_ui.highlight, __LINE__);
                mmi_medply_plst_fwd_select((U16)menu_evt->highlighted_menu_id);
                break;
            }
        #ifdef __MMI_MEDIA_PLAYER_STREAM__
            else if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_BOOKMARK_MENU)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_ENTRY_SELECT, menu_evt->parent_menu_id, menu_evt->highlighted_menu_id, plst_cntx_p->list_ui.highlight, __LINE__);
                switch(menu_evt->highlighted_menu_id)
                {
                    case MENU_ID_MEDPLY_BOOKMARK_PREDEFINEDURL:
                        mmi_medply_bookmark_entry_predefined_url();
                        break;
                    case MENU_ID_MEDPLY_BOOKMARK_MENU_INPUT:
                        mmi_medply_bookmark_input_url();
                        break;
                    case MENU_ID_MEDPLY_BOOKMARK_MENU_HISTORY:
                        mmi_medply_bookmark_entry_history_url();
                        break;
                }
            }
            else if (menu_evt->parent_menu_id == MENU_ID_MEDPLY_BOOKMARK_OPTION_MENU)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_ENTRY_SELECT, menu_evt->parent_menu_id, menu_evt->highlighted_menu_id, plst_cntx_p->list_ui.highlight, __LINE__);
                switch(menu_evt->highlighted_menu_id)
                {
                    case MENU_ID_MEDPLY_BOOKMARK_OPTION_PLAY:
                        mmi_medply_bookmark_history_option_initiate_play();
                        break;
                    case MENU_ID_MEDPLY_BOOKMARK_OPTION_REMOVE:
                        mmi_medply_bookmark_entry_remove_confirm();
                        break;
                    case MENU_ID_MEDPLY_BOOKMARK_OPTION_CLEAR:
                        mmi_medply_bookmark_entry_remove_all_confirm();
                        break;
                }
            }
        #endif /*__MMI_MEDIA_PLAYER_STREAM__*/
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_WANING,evt->evt_id ,menu_evt->parent_menu_id,menu_evt->highlighted_menu_id, __LINE__);
            break;
        
        }
        case EVT_ID_CUI_MENU_LIST_EXIT:
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_MENU_CUI_CLOSE,menu_evt->sender_id ,__LINE__);
            cui_menu_close(menu_evt->sender_id);
            break;
        }
    }    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_cui_hdlr_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_plst_cui_hdlr_editor(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
/**********************Fs editor CUI event*************************/
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        {
            cui_fseditor_evt_struct *editor_evt = (cui_fseditor_evt_struct *)evt;
        
            
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_EDITOR_CUI_SUBMIT,editor_evt->sender_id ,__LINE__);
            cui_fseditor_get_text(editor_evt->sender_id, &plst_cntx_p->editor.editor_buffer[0], plst_cntx_p->editor.limit);
            plst_cntx_p->editor.done_func();
            cui_fseditor_close(editor_evt->sender_id);
            break;
        }
        case EVT_ID_CUI_FSEDITOR_ABORT:
        {
            cui_fseditor_evt_struct *editor_evt = (cui_fseditor_evt_struct *)evt;
            
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_EDITOR_CUI_ABORT,editor_evt->sender_id ,__LINE__);
            cui_fseditor_close(editor_evt->sender_id);
            break;
        }
/**********************File name editor CUI event*************************/
        case EVT_ID_CUI_FILENAME_EDITOR_RESULT:
        {
            cui_filename_editor_result_event_struct *editor_ret = (cui_filename_editor_result_event_struct *) evt;
            
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_EDITOR_CUI_RESULT,editor_ret->sender_id ,editor_ret->result, __LINE__);

            if (editor_ret->result != 0)/*user complete*/
            {
                U8 action = 0;
                MMI_BOOL close_editor = MMI_TRUE;
                
                action = (U8)cui_filename_editor_get_parent_data(editor_ret->sender_id);
                switch (action)
                {
                    case MMI_MEDPLY_EDITOR_RENAME:
                    {
                        //@TODO: revise to common usage of rename a file
                        close_editor = mmi_medply_plst_listmgr_rename_part3(action, editor_ret->result, editor_ret->sender_id);
                        if (close_editor)
                        {
                            cui_filename_editor_close(editor_ret->sender_id);
                        }
                        break;
                    }
                    default:
                    {
                        if (editor_ret->result > 0)
                        {
                            plst_cntx_p->editor.done_func();
                            cui_filename_editor_close(editor_ret->sender_id);
                        }
                        else if (editor_ret->result == 0)/*user cancel*/
                        {
                            cui_filename_editor_close(editor_ret->sender_id);
                        }
                        else/*editor_ret->result < 0 error happens*/
                        {
                            mmi_medply_plst_popup_simple_with_string(get_string(srv_fmgr_fs_error_get_string(editor_ret->result)), (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(editor_ret->result));
                        }
                        break;
                    }
                }
            }
            else// if (editor_ret->result == 0)/*user cancel*/
            {
                cui_filename_editor_close(editor_ret->sender_id);
            }
            break;
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_cui_hdlr_inline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_plst_cui_hdlr_inline(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_NOTIFY:
        {
            break;
        }
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        {
            cui_event_inline_common_struct *inline_evt = (cui_event_inline_common_struct *)evt;
            S32 ret = 0;
            
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_ACTIVE,inline_evt->sender_id ,__LINE__);
            ret = mmi_medply_plst_details_prepare_data();
            /* use screen based memory,  should always get the memory*/
            if (ret < 0)
            {
                mmi_medply_plst_post_popup(ret);
                cui_inline_close(inline_evt->sender_id);
            }
            else
            {
                mmi_medply_plst_details_set_value(inline_evt->sender_id);
            }
            break;
        }
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_INACTIVE:
        {
            mmi_medply_plst_details_unprepare_data();
        }
        case EVT_ID_CUI_INLINE_SUBMIT:
        {
            break;
        }
        
        case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_abort_struct *inline_evt = (cui_event_inline_abort_struct*)evt;
            
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_INLINE_CUI_ABORT,inline_evt->sender_id ,__LINE__);
            cui_inline_close(inline_evt->sender_id);
            mmi_medply_plst_details_preview_delete_hdlr(NULL);
            break;
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_cui_hdlr_fmgr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_plst_cui_hdlr_fmgr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        {
            cui_file_selector_result_event_struct *sel_evt = (cui_file_selector_result_event_struct*)evt;
            
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_SELECTOR_CUI_RESULT,sel_evt->sender_id ,sel_evt->result, __LINE__);
            mmi_medlpy_plst_fmgr_file_selector_handle(sel_evt);
            break;
        }
        /* sent from File Manager CUI, indicate the storage selected by users  */
        case EVT_ID_CUI_STORAGE_SELECTOR_RESULT:
        {
            cui_storage_selector_result_event_struct *sel_evt = (cui_storage_selector_result_event_struct*)evt;

            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_SELECTOR_CUI_RESULT,sel_evt->sender_id ,sel_evt->result, __LINE__);
            mmi_medlpy_plst_listmgr_fmgr_storage_select_hdlr(sel_evt);
            break;
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_cui_hdlr_alert
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_plst_cui_hdlr_alert(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            mmi_alert_result_evt_struct *confirm = (mmi_alert_result_evt_struct *)evt;
        
            switch (confirm->result)
            {
                case MMI_ALERT_CNFM_OK:  
                case MMI_ALERT_CNFM_YES:         
                {
                    switch ((S32)confirm->user_tag)
                    {
                        default:
                        {
                            ((FuncPtr)confirm->user_tag)();
                            break;
                        }
                    }
                    break;
                }
                default:
                    storage_change_entry = NULL;
                    break;
            }
            break;
        }
    }    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_plst_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
/*************************Search CUI event***************************/
        case EVT_ID_MEDPLY_CUI_SEARCH_CLOSE:
        case EVT_ID_MEDPLY_CUI_SEARCH_FINISH:
        case EVT_ID_MEDPLY_CUI_SEARCH_ERROR:
        case EVT_ID_MEDPLY_CUI_SEARCH_CANCEL:
        case EVT_ID_MEDPLY_CUI_SEARCH_APPEND: 
            return mmi_medply_plst_cui_hdlr_search(evt);
/*************************Menu CUI event***************************/
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_LIST_EXIT:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            return mmi_medply_plst_cui_hdlr_menu(evt);

/**********************Editor CUI event*************************/
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
        case EVT_ID_CUI_FSEDITOR_ABORT:
        case EVT_ID_CUI_FILENAME_EDITOR_RESULT:
            return mmi_medply_plst_cui_hdlr_editor(evt);
            
/**********************Inline CUI event*************************/
        case EVT_ID_CUI_INLINE_NOTIFY:
        case EVT_ID_CUI_INLINE_SUBMIT:
        case EVT_ID_CUI_INLINE_ABORT:
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        case EVT_ID_CUI_INLINE_MAIN_SCREEN_INACTIVE:
            
            return mmi_medply_plst_cui_hdlr_inline(evt);
            
/**********************File selector CUI event*************************/
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        case EVT_ID_CUI_STORAGE_SELECTOR_RESULT:
            return mmi_medply_plst_cui_hdlr_fmgr(evt);
            
/**********************Alert CUI event*************************/
        case EVT_ID_ALERT_QUIT:
            return mmi_medply_plst_cui_hdlr_alert(evt);
            
/**********************FS event*************************/
        case EVT_ID_SRV_FMGR_ASYNC_DONE:
        {
            srv_fmgr_async_done_event_struct *fs_evt = (srv_fmgr_async_done_event_struct*)evt;
            mmi_medply_plst_listmgr_delete_all_rsp_hdlr(fs_evt);
            break;
        }
        
        
        default:
            break;
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_path_internal
 * DESCRIPTION
 *  get path intelnal
 * PARAMETERS
 *  in_list         [IN]
 *  out_path        [OUT]
 *  in_index        [IN]
 * RETURNS
 *  U8
 *****************************************************************************/ 
static S32 mmi_medply_plst_get_path_internal(mmi_medply_plst_struct* in_list, UI_string_type out_path, S32 in_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 read_size = 0;   
    mmi_medply_plst_block_node_struct block;
    UI_character_type path_buffer[MEDPLY_MAX_PATH_LEN];
    FS_HANDLE fd = FS_NO_ERROR;
    U8 i = 0;
    S32 ret = FS_NO_ERROR;
    U32 current_block_offset = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(in_list->fs_hdlr >= FS_NO_ERROR);
    fd = in_list->fs_hdlr;
    MMI_ASSERT(in_index < MMI_MEDPLY_MAX_PLAYLIST_ITEM);
    memset(path_buffer, 0, sizeof(UI_character_type) * MEDPLY_MAX_PATH_LEN);
    current_block_offset = in_list->header.index[in_index].offset;
    MMI_ASSERT(in_list->header.index[in_index].used_block <= MMI_MEDPLY_MAX_BLOCK_NUM);
    for (i = 0; i < in_list->header.index[in_index].used_block; i++)
    {
        ret = FS_Seek(fd, current_block_offset, FS_FILE_BEGIN);
        if (ret < FS_NO_ERROR)
        {
            break;
        }
        ret = FS_Read(fd, &block, sizeof(mmi_medply_plst_block_node_struct), &read_size);

        if (ret < FS_NO_ERROR)
        {
            break;
        }
        else if (read_size != sizeof(mmi_medply_plst_block_node_struct))
        {
            ret = MEDPLY_PLST_ERR_READ_FAILED;
            break;
        }
        else if (block.pattern_begin != MEDPLY_PLAYLIST_BLOCK_PATTERN_1 ||
                block.pattern_end != MEDPLY_PLAYLIST_BLOCK_PATTERN_2)
        {
            ret = MEDPLY_PLST_ERR_LIST_DAMAGED;
            break;
        }
        memcpy(&path_buffer[i * (MMI_MEDPLY_BLOCK_DATA_SIZE / 2)], &block.data, MMI_MEDPLY_BLOCK_DATA_SIZE);
        if (block.next_ptr == 0)
        {
            break;
        }
        else
        {
            current_block_offset = block.next_ptr;
        }
    }
    if (ret < FS_NO_ERROR)
    {
        return ret;
    }
    
    mmi_ucs2ncpy((CHAR*)out_path, (CHAR*)path_buffer, (MEDPLY_MAX_PATH_LEN - 1));

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_write_back_to_file
 * DESCRIPTION
 *  write playlist to file
 * PARAMETERS
 *  list		[IN]
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_medply_plst_write_back_to_file(mmi_medply_plst_struct* list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = FS_NO_ERROR;
    U32 writed_size = 0;
    U32 to_write_size = 0;
    U32 seek_offset = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    do 
    {
        ret = FS_Seek(list->fs_hdlr, 0, FS_FILE_BEGIN);
        if (ret < FS_NO_ERROR)
        {
            break;
        }

        to_write_size = sizeof(mmi_medply_plst_header_struct);
        ret = FS_Write(list->fs_hdlr, &(list->header), to_write_size, &writed_size);
        if (ret < FS_NO_ERROR)
        {
            break;
        }
        if (to_write_size != writed_size)
        {
            ret = MEDPLY_PLST_ERR_WRITE_FAILED;
            break;
        }

        seek_offset = list->header.footer_pattern_offset;
        ret = FS_Seek(list->fs_hdlr, seek_offset, FS_FILE_BEGIN);
        if (ret < FS_NO_ERROR)
        {
            break;
        }
    } while (0);

    FS_Commit(list->fs_hdlr);/* This function is used to flush all buffers associated to a file*/
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_option_config
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_option_config(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
#ifdef __MMI_KURO_SUPPORT__
    UI_character_type filename[MEDPLY_MAX_FILE_LEN];
    UI_character_type ext[MEDPLY_MAX_EXT_LEN];
#endif
    mmi_medply_dynamic_list_data_struct* ui = &(plst_cntx_p->list_ui);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* unhide all. */
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_MOVEUP, MMI_FALSE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_MOVEDOWN, MMI_FALSE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_ADD, MMI_FALSE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_PLAY, MMI_FALSE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_DETAILS, MMI_FALSE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_REMOVE, MMI_FALSE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_DELETE, MMI_FALSE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_SEND, MMI_FALSE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_USE, MMI_FALSE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_REFRESH, MMI_FALSE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_ADD_TO_PLAYLIST, MMI_FALSE);
    
    /* hide settings */
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_SETTINGS, MMI_TRUE);


    /* handle all tracks error cases */
    ret = mmi_medply_plst_get_path(path, ui->highlight);
    if (ret < 0 && (browser_all_audio == MMI_TRUE || browser_all_video == MMI_TRUE))
    {
        /* hide all except refresh */
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_MOVEUP, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_MOVEDOWN, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_ADD, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_PLAY, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_DETAILS, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_REMOVE, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_DELETE, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_SEND, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_USE, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_ADD_TO_PLAYLIST, MMI_TRUE);

        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_REFRESH, MMI_FALSE);
        return;
    }

    if (browser_all_audio || browser_all_video)
    {
        /* all media */
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_ADD, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_REMOVE, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_MOVEUP, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_MOVEDOWN, MMI_TRUE);
    #ifdef MMI_MEDPLY_PLST_VIDEO_INTEGRATED
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_ADD_TO_PLAYLIST, MMI_FALSE);
    #else
        if (browser_all_video)
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_ADD_TO_PLAYLIST, MMI_TRUE);
        }
    #endif /* MMI_MEDPLY_PLST_VIDEO_INTEGRATED */
    }
    else
    {
        /* common list */
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_REFRESH, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_ADD_TO_PLAYLIST, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_DELETE, MMI_TRUE);
    }

#ifdef __MMI_KURO_SUPPORT__
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_ACTIVATE, MMI_TRUE);
#endif
    if (ui->total == 0)
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_MOVEUP, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_MOVEDOWN, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_PLAY, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_DETAILS, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_REMOVE, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_SEND, MMI_TRUE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_USE, MMI_TRUE);

        if (!plst_cntx_p->list_loaded && browser_now_playing)
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_ADD, MMI_TRUE);
        }
    }
    else
    {
        if (ui->total == 1)
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_MOVEUP, MMI_TRUE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_MOVEDOWN, MMI_TRUE);
        }
            
        if (ui->total > 0)
        {
#ifdef __MMI_KURO_SUPPORT__
            KURO_ACTIVE_STATUS state = 0;
#endif
            ret = mmi_medply_plst_get_path(path, ui->highlight);
            if (ret < 0)
            {
                /* get highlight item's path failed. popup and return. */
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
                return;
            }
#ifdef __MMI_KURO_SUPPORT__
            mmi_medply_util_extract_filename(filename, path);
            mmi_medply_util_extract_ext(filename, ext);

            if (!mmi_ucs2icmp((CHAR*)ext, (CHAR*)L"kur"))
            {
                S32 result;
                result = KURO_GetActiveStatus( path, &state);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_KURO_ACTIVATE, ret, state);
                if (result == KURO_OK)
                {
                    if (state !=  KURO_ACTIVATED)
                    {
                        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_ACTIVATE, MMI_FALSE);
                    }
                }
            }
#endif
        }
        
        if (0 < srv_fmgr_types_get_send_option_menu(FMGR_TYPE_ALL, (WCHAR *) path))
            
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_SEND, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_SEND, MMI_TRUE);
        }
        
        if (0 < srv_fmgr_types_get_use_option_menu(FMGR_TYPE_ALL, (WCHAR *) path))
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_USE, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_USE, MMI_TRUE);
        }
    }

    
    cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_SEND, MMI_TRUE);
    cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_MEDPLY_PLST_OPTION_USE, MMI_TRUE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_entry_playlist_option
 * DESCRIPTION
 *  entry playlist option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_entry_playlist_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    mmi_medply_dynamic_list_data_struct* ui = &(plst_cntx_p->list_ui);
    MMI_ID cui_gid = GRP_ID_INVALID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ui->total > 0)
    {
        result = mmi_medply_plst_get_path(path, ui->highlight);
        if (result < 0 && browser_all_audio == MMI_FALSE && browser_all_video == MMI_FALSE)
        {
            /* get highlight item's path failed. popup and return. */
            mmi_medply_plst_popup_simple(result);
            return;
        }
    }

    mmi_frm_group_create(g_gid_browser_list, GRP_ID_MEDPLY_LIST_BROWSER_OPT,
                        mmi_medply_plst_proc, (void*)NULL); 

    mmi_frm_group_enter(GRP_ID_MEDPLY_LIST_BROWSER_OPT, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_gid = cui_menu_create(
                        GRP_ID_MEDPLY_LIST_BROWSER_OPT,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_OPTION,
                        MENU_ID_MEDPLY_PLST_OPTION_MENU,
                        MMI_TRUE, NULL);
    if (cui_gid > GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)));
        cui_menu_run(cui_gid);
    }
    else
    {   
        mmi_medply_plst_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_exit_playlist
 * DESCRIPTION
 *  exist playlist
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_exit_playlist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_medply.in_list_screen = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_del_list_browser_callback
 * DESCRIPTION
 *  resotre when press end key 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_plst_del_list_browser_callback(mmi_event_struct* param)
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
        {
            /* only delete browser list memory in GRP_ID_MEDPLY_LIST_BROWSER*/
            /* If plst module is already deinited then no need to free memory here */
            if (g_gid_browser_list == GRP_ID_MEDPLY_LIST_BROWSER && g_medply.adm_id_p != NULL)
            {
                g_medply.in_list_screen = MMI_FALSE;
                in_browser_mode = MMI_FALSE;
                browser_all_audio = MMI_FALSE;
                browser_all_video = MMI_FALSE;
                from_main_scr = MMI_FALSE; // change feature MAUI_02610488
                g_gid_browser_list = 0;
                
                /* close opening play list. */
                if (!browser_now_playing)
                {
                    mmi_medply_plst_write_back_to_file(plst_cntx_p->browser_list_p);
                    FS_Close(plst_cntx_p->browser_list_p->fs_hdlr);
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->browser_list_p->fs_hdlr ,__LINE__);
                    plst_cntx_p->browser_list_p->fs_hdlr = FS_ERROR_RESERVED;
                }
                else
                {
                    browser_now_playing = MMI_FALSE;
                    mmi_medply_plst_write_back_to_file(&(plst_cntx_p->current_list));
                }
                if (plst_cntx_p->browser_list_p)
                {
                    kal_adm_free(g_medply.adm_id_p, plst_cntx_p->browser_list_p);
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE, plst_cntx_p->browser_list_p, __LINE__);
                    plst_cntx_p->browser_list_p = NULL;
                }
            }
            else
            {
                if (mmi_frm_group_is_present(GRP_ID_MEDPLY_LIST_BROWSER))
                {
                    U8 *guiBuffer = NULL;
                    // current list highlight issue, which modified by MAUI_02629535
                    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_LIST_BROWSER, SCR_ID_MEDPLY_LIST_BROWSER);
                    if (guiBuffer != NULL)
                    {
                        list_menu_category_history *hist = (list_menu_category_history*) guiBuffer;
                        hist->highlighted_item = plst_cntx_p->list_ui.highlight;
                    }
                    g_gid_browser_list = GRP_ID_MEDPLY_LIST_BROWSER;
                }
                else
                {
                    /* If playlist module is already deinited no need for clsoe playlist */
                    if (g_medply.adm_id_p != NULL)
                    {
                        g_medply.in_list_screen = MMI_FALSE;
                        in_browser_mode = MMI_FALSE;
                        browser_all_audio = MMI_FALSE;
                        browser_all_video = MMI_FALSE;
                        g_gid_browser_list = 0;

                        /* close opening play list. */
                        if (!browser_now_playing)
                        {
                            mmi_medply_plst_write_back_to_file(plst_cntx_p->browser_list_p);
                            FS_Close(plst_cntx_p->browser_list_p->fs_hdlr);
                            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->browser_list_p->fs_hdlr ,__LINE__);
                            plst_cntx_p->browser_list_p->fs_hdlr = FS_ERROR_RESERVED;
                        }
                        else
                        {
                            browser_now_playing = MMI_FALSE;
                            mmi_medply_plst_write_back_to_file(&(plst_cntx_p->current_list));
                        }
                        if (plst_cntx_p->browser_list_p)
                        {
                            kal_adm_free(g_medply.adm_id_p, plst_cntx_p->browser_list_p);
                            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE, plst_cntx_p->browser_list_p, __LINE__);
                            plst_cntx_p->browser_list_p = NULL;
                        }
                    }
                }
            }
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;

}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_list
 * DESCRIPTION
 *  get list item
 * PARAMETERS
 *  cached_num      [IN/OUT]
 *  start_index     [IN]
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_plst_get_list(U16 *cached_num, U16 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;
    S32 ret = MEDPLY_PLST_NO_ERROR;
    CHAR* filename_ptr = NULL;
    UI_character_type path_buff[MEDPLY_MAX_PATH_LEN];
    UI_character_type filename[MEDPLY_MAX_FILE_LEN];
    
    mmi_medply_plst_struct* list = plst_cntx_p->browser_list_p;
    mmi_medply_dynamic_list_data_struct* ui = &(plst_cntx_p->list_ui);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (browser_now_playing)
    {
        list = &(plst_cntx_p->current_list);
    }
    memset(path_buff, 0, sizeof(UI_character_type) * MEDPLY_MAX_PATH_LEN);
    while (count < MMI_MEDPLY_LIST_BUFF_SIZE && start_index < list->total)
    {
        if (!list->header.index[start_index].is_active)
        {
            /*
            **  current node is an empty node. 
            **  this case should not happen.
            **  pass this node.
            */
            start_index++;
            continue;
        }

        ret = mmi_medply_plst_get_path_internal(list, path_buff, start_index);
        
        if (ret < 0)
        {
            break;
        }
        
        if (list->header.index[start_index].is_active > 1)
        {
            /* set cache data. */
            ui->cache[count].is_short = 1;
        }
        else
        {
            /* set cache data. */
            ui->cache[count].is_short = 0;
        }

        if (path_buff[0] == 0)
        {
            ret = MEDPLY_PLST_ERR_LIST_DAMAGED;
            break;
        }

        filename_ptr = mmi_ucs2rchr((CHAR*)path_buff, (U16)(L'\\'));
        if (filename_ptr == NULL)
        {
            filename[0] = 0;
            ret = MEDPLY_PLST_ERR_LIST_DAMAGED;
            break;
        }
        else
        {
            mmi_ucs2ncpy((CHAR*)filename, (CHAR*)(filename_ptr + 2), (MEDPLY_MAX_FILE_LEN - 1));
        }      

        mmi_medply_util_split_filename_ext(filename, ui->cache[count].filename, ui->cache[count].ext);
        #ifdef __MMI_KURO_SUPPORT__
        if (!mmi_ucs2nicmp((CHAR*) ui->cache[count].ext, (CHAR*) L"KUR", (MEDPLY_MAX_EXT_LEN- 1)))
        {
            KURO_ACTIVE_STATUS is_activate;
            S32 result;
            
            mmi_medply_plst_get_path(path_buff, start_index);
            result = KURO_GetActiveStatus(path_buff, &is_activate);  

            if (result == KURO_OK)
            {
                ui->cache[count].is_activate = is_activate;
            }
            else
            {
                ui->cache[count].is_activate = 0XFF;
            }
        }
        #endif         
        start_index++;
        count++;
    }
    if (ret < MEDPLY_PLST_NO_ERROR)
    {
        return ret;
    }
    else
    {
        *cached_num = count;
        return count;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_load_cache_ext
 * DESCRIPTION
 *  get list cache
 * PARAMETERS
 *  item_index      [IN]
 *  item_info       [IN/OUT]
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_plst_load_cache_ext(U16 item_index , mmi_medply_dynamic_list_item_info_struct* item_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = MEDPLY_PLST_NO_ERROR;
    CHAR* filename_ptr = NULL;
    UI_character_type path_buff[MEDPLY_MAX_PATH_LEN];
    UI_character_type filename[MEDPLY_MAX_FILE_LEN];
    
    mmi_medply_plst_struct* list = plst_cntx_p->browser_list_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (browser_now_playing)
    {
        list = &(plst_cntx_p->current_list);
    }
    memset(path_buff, 0, sizeof(UI_character_type) * MEDPLY_MAX_PATH_LEN);
    if (item_index < list->total)
    {
        ret = mmi_medply_plst_get_path_internal(list, path_buff, item_index);
        
        if (ret < 0)
        {
            return ret;
        }
        
        if (list->header.index[item_index].is_active > 1)
        {
            /* set cache data. */
            item_info->is_short = 1;
        }
        else
        {
            /* set cache data. */
            item_info->is_short = 0;
        }

        if (path_buff[0] == 0)
        {
            ret = MEDPLY_PLST_ERR_LIST_DAMAGED;
            return ret;
        }

        filename_ptr = mmi_ucs2rchr((CHAR*)path_buff, (U16)(L'\\'));
        if (filename_ptr == NULL)
        {
            filename[0] = 0;
            ret = MEDPLY_PLST_ERR_LIST_DAMAGED;
            return ret;
        }
        else
        {
            mmi_ucs2ncpy((CHAR*)filename, (CHAR*)(filename_ptr + 2), (MEDPLY_MAX_FILE_LEN - 1));
        }      


        mmi_medply_util_split_filename_ext(filename, item_info->filename, item_info->ext);
    #ifdef __MMI_KURO_SUPPORT__
        if (!mmi_ucs2nicmp((CHAR*) item_info->ext, (CHAR*) L"KUR", (MEDPLY_MAX_EXT_LEN- 1)))
        {
            KURO_ACTIVE_STATUS is_activate;
            S32 result;
            
            mmi_medply_plst_get_path(path_buff, item_index);
            result = KURO_GetActiveStatus(path_buff, &is_activate);  

            if (result == KURO_OK)
            {
                item_info->is_activate = is_activate;
            }
            else
            {
                item_info->is_activate = 0XFF;
            }
        }
    #endif
        item_info->is_used = MMI_TRUE;
    }
    if (ret < MEDPLY_PLST_NO_ERROR)
    {
        return ret;
    }
   
    return ret;

}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_item
 * DESCRIPTION
 *  get list item
 * PARAMETERS
 *  item_idx        [IN]
 *  str_buff        [OUT]
 *  img_buff_p      [OUT]
 *  str_img_mask    [?]     useless
 * RETURNS
 *  pBOOL
 *****************************************************************************/
static pBOOL mmi_medply_plst_get_item(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_dynamic_list_item_info_struct item_info;
    S32 result;
    U16 file_format = 0;
    mmi_medply_dynamic_list_data_struct* ui = &(plst_cntx_p->list_ui);
    U8 i = 0;
    MMI_BOOL trancate= MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(item_idx < ui->total);    

    for (i = 0; i < MMI_MEDPLY_LIST_BUFF_SIZE; i ++)
    {
        if (item_idx == ui->cache[i].index_in_list && ui->cache[i].is_used != 0)
        {
            memset(&item_info, 0, sizeof(mmi_medply_dynamic_list_item_info_struct));

            memcpy(&item_info, &(ui->cache[i]), sizeof(mmi_medply_dynamic_list_item_info_struct));   
           /* yaling for MAUI_01872142 */
            if (item_info.is_short)
            {
              mmi_chset_mixed_text_to_ucs2_str(
                  (U8*)str_buff,
                  MAX_SUBMENU_CHARACTERS,
                  (U8*)item_info.filename,
                  (mmi_chset_enum)PhnsetGetDefEncodingType());
            }
            else
            {
            #ifdef __MMI_SHOW_FILE_EXT__
                if (mmi_ucs2strlen((CHAR*)item_info.filename) > MAX_SUBMENU_CHARACTERS - MEDPLY_MAX_EXT_LEN)
            #else
                if (mmi_ucs2strlen((CHAR*)item_info.filename) > MAX_SUBMENU_CHARACTERS)
            #endif
                {
                    trancate = MMI_TRUE;
                }
                else
                {
                    trancate = MMI_FALSE;
                }
                mmi_ucs2ncpy((CHAR*)str_buff, (CHAR*)item_info.filename, MAX_SUBMENU_CHARACTERS);
            }

            if (trancate)
            {
                mmi_ucs2ncpy((CHAR*)((WCHAR*)str_buff + MAX_SUBMENU_CHARACTERS - 3), (CHAR*)L"...", 3);
            }
            else
            {
            #ifdef __MMI_SHOW_FILE_EXT__
                #if !defined(__MMI_SHOW_DAF_FILE_EXT__)
                if (mmi_ucs2nicmp((CHAR*)item_info.ext, (CHAR*)L"MP3", (MEDPLY_MAX_EXT_LEN - 1)) && 
                    mmi_ucs2nicmp((CHAR*)item_info.ext, (CHAR*)L"MP2", (MEDPLY_MAX_EXT_LEN - 1)))
                #endif
                {
                    if (item_info.ext[0] != (U16)L'.')
                    {
                        mmi_ucs2ncat((CHAR*)str_buff, (CHAR*)L".", MAX_SUBMENU_CHARACTERS);   
                    }
                    mmi_ucs2ncat((CHAR*)str_buff, (CHAR*)item_info.ext, MAX_SUBMENU_CHARACTERS);
                }
            #endif
            }
            
            file_format = mmi_medply_util_is_target_support_format(item_info.ext);
        #ifdef __MMI_KURO_SUPPORT__
            if (!mmi_ucs2nicmp((CHAR*) item_info.ext, (CHAR*) L"KUR", (MEDPLY_MAX_EXT_LEN- 1)))
            {
                
                switch (item_info.is_activate)
                {
                    case KURO_ACTIVATED:
                       *img_buff_p = (PU8) GetImage(IMG_ID_MEDPLY_KURO_SONG_ACTIVATE);
                       break;
        
                    case KURO_NOT_ACTIVATED:
                       *img_buff_p = (PU8) GetImage(IMG_ID_MEDPLY_KURO_SONG_UNACTIVATE);
                        break;
               
                    default:
                        *img_buff_p = (PU8) GetImage(IMG_ID_MEDPLY_KURO_SONG_UNKNOWN_STATUS);
                        break;
                }
            
                return MMI_TRUE;
            }
            *img_buff_p = (PU8)GetImage(mmi_medply_util_get_file_icon(file_format));
        #else
            *img_buff_p = (PU8)GetImage(mmi_medply_util_get_file_icon(file_format));
        #endif
            return MMI_TRUE;
        }
    }
    
    memset(&item_info, 0, sizeof(mmi_medply_dynamic_list_item_info_struct));
    item_info.index_in_list = item_idx;

    result = mmi_medply_plst_load_cache_ext(item_idx, &item_info);

    if (result < FS_NO_ERROR)
    {
        mmi_ucs2ncpy((CHAR*) str_buff, (CHAR*) GetString(STR_GLOBAL_LOADING), MAX_SUBMENU_CHARACTERS);
        *img_buff_p = NULL;
        return MMI_TRUE;
    }
    else
    {
        file_format = mmi_medply_util_is_target_support_format(item_info.ext);
    #ifdef __MMI_KURO_SUPPORT__
        if (!mmi_ucs2nicmp((CHAR*) item_info.ext, (CHAR*) L"KUR", (MEDPLY_MAX_EXT_LEN- 1)))
        {
            switch (item_info.is_activate)
            {
                case KURO_ACTIVATED:
                   *img_buff_p = (PU8) GetImage(IMG_ID_MEDPLY_KURO_SONG_ACTIVATE);
                   break;

                case KURO_NOT_ACTIVATED:
                   *img_buff_p = (PU8) GetImage(IMG_ID_MEDPLY_KURO_SONG_UNACTIVATE);
                    break;

                default:
                    *img_buff_p = (PU8) GetImage(IMG_ID_MEDPLY_KURO_SONG_UNKNOWN_STATUS);
                    break;
            } 
        }
        else
        {
            *img_buff_p = (PU8)GetImage(mmi_medply_util_get_file_icon(file_format));
        }
    #else
        *img_buff_p = (PU8)GetImage(mmi_medply_util_get_file_icon(file_format));
    #endif        
  
        /* TODO: get item info successful, need add it to cache. */
        /* update cache. */
        for (i = 0; i < MMI_MEDPLY_LIST_BUFF_SIZE; i++)
        {
            if (ui->cache[i].index_in_list == 0 &&
                ui->cache[i].is_used == 0)
            {
                /* get an empty cache item. */
                break;
            }
        }

        if (i < MMI_MEDPLY_LIST_BUFF_SIZE)
        {
            /* cache is not full. just need update tail. */
            memcpy(&(ui->cache[i]), &item_info, sizeof(mmi_medply_dynamic_list_item_info_struct));
            ui->tail = i;
        }
        else
        {
            /* cache is full, need replace the oldest one. */
            memcpy(&(ui->cache[ui->head]), &item_info, sizeof(mmi_medply_dynamic_list_item_info_struct));
            if (ui->head == MMI_MEDPLY_LIST_BUFF_SIZE - 1)
            {
                ui->head = 0;
            }
            else
            {
                ui->head++;
            }
            if (ui->tail == MMI_MEDPLY_LIST_BUFF_SIZE - 1)
            {
                ui->tail = 0;
            }
            else
            {
                ui->tail++;
            }
        }
    }
    
        if (item_info.is_short)
        {
          mmi_chset_mixed_text_to_ucs2_str(
              (U8*)str_buff,
              MAX_SUBMENU_CHARACTERS,
              (U8*)item_info.filename,
              (mmi_chset_enum)PhnsetGetDefEncodingType());
        }
        else
        {
        #ifdef __MMI_SHOW_FILE_EXT__
            if (mmi_ucs2strlen((CHAR*)item_info.filename) > MAX_SUBMENU_CHARACTERS - MEDPLY_MAX_EXT_LEN)
        #else
            if (mmi_ucs2strlen((CHAR*)item_info.filename) > MAX_SUBMENU_CHARACTERS)
        #endif
            {
                trancate = MMI_TRUE;
            }
            else
            {
                trancate = MMI_FALSE;
            }

            mmi_ucs2ncpy((CHAR*)str_buff, (CHAR*)item_info.filename, (MAX_SUBMENU_CHARACTERS));
        }
        if (trancate)
        {
            mmi_ucs2ncpy((CHAR*)((WCHAR*)str_buff + MAX_SUBMENU_CHARACTERS - 3), (CHAR*)L"...", 3);
        }
        else
        {
        #ifdef __MMI_SHOW_FILE_EXT__
            #if !defined(__MMI_SHOW_DAF_FILE_EXT__)
            if (mmi_ucs2nicmp((CHAR*)item_info.ext, (CHAR*)L"MP3", (MEDPLY_MAX_EXT_LEN - 1)) && 
                mmi_ucs2nicmp((CHAR*)item_info.ext, (CHAR*)L"MP2", (MEDPLY_MAX_EXT_LEN - 1)))
            #endif
            {
                if (item_info.ext[0] != (U16)L'.')
                {
                    mmi_ucs2ncat((CHAR*)str_buff, (CHAR*)L".", MAX_SUBMENU_CHARACTERS);
                }
                mmi_ucs2ncat((CHAR*)str_buff, (CHAR*)item_info.ext, MAX_SUBMENU_CHARACTERS);
            }
        #endif 
        }
    return MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_storage_change_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_medply_plst_storage_change_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 storage = SRV_FMGR_PUBLIC_DRV;
    SRV_FMGR_DRVLIST_HANDLE drv_list;
    S16 error = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drv_list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY);
    storage = srv_fmgr_drivelist_get_drv_letter(drv_list, 0);
    srv_fmgr_drivelist_destroy(drv_list);
    
#ifdef __MMI_KURO_SUPPORT__
    mmi_medply_settings_write_value(MMI_MEDPLY_SETTINGS_DEFAULT_STORAGE, &(storage));
#else
    plst_cntx_p->default_storage = storage;
    WriteValue(NVRAM_MEDPLY_PREFER_LIST, &(plst_cntx_p->default_storage), DS_BYTE, &error);
#endif

    /* enter storage check point again */
    if (storage_change_entry)
    {
        storage_change_entry();
        storage_change_entry = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_storage_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_medply_plst_storage_change(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  total_drv_num;
    SRV_FMGR_DRVLIST_HANDLE drv_list;
    S32 i;
    U8 drv;
    U8 *storage_str_p[SRV_FMGR_DRV_TOTAL];
    U8 storage;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_KURO_SUPPORT__
    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_DEFAULT_STORAGE, &storage);
#else
    storage = plst_cntx_p->default_storage;
#endif

    drv_list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY);
    total_drv_num = (U8)srv_fmgr_drivelist_count(drv_list); 
    for(i = 0; i < total_drv_num; i++)
    {
        drv = srv_fmgr_drivelist_get_drv_letter(drv_list, i);
        storage_str_p[i] = (U8*)get_string(srv_fmgr_drv_get_string(drv));
    }
    srv_fmgr_drivelist_destroy(drv_list);

    if (total_drv_num == 0)
    {
        /* no storage is avaible right now, need to plug memory card */
        mmi_medply_plst_popup_simple_with_string((WCHAR *)get_string(STR_ID_MEDPLY_PLST_INSERT_CARD), MMI_EVENT_INFO);
        storage_change_entry = NULL;
    }
    else if (total_drv_num == 1)
    {
        UI_character_type str[MEDPLY_MAX_FILE_LEN];
        U16 storage_id = srv_fmgr_drv_get_string(storage);

        mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_LIST_STORAGE_CHANGE, mmi_medply_plst_proc, (void*)NULL); 
        mmi_frm_group_enter(GRP_ID_MEDPLY_LIST_STORAGE_CHANGE, MMI_FRM_NODE_SMART_CLOSE_FLAG);

        mmi_ucs2cpy((CHAR *) str, (CHAR *) GetString(storage_id));
        mmi_ucs2cat((CHAR *) str, (CHAR *) L" ");
        mmi_ucs2cat((CHAR *) str, (CHAR *) GetString(STR_ID_MEDPLY_PLST_CARD_REMOVED_AND_USE));// GetString(STR_ID_MEDPLY_PLST_CARD_REMOVED_AND_USE));
        mmi_ucs2cat((CHAR *) str, (CHAR *) L" ");
        mmi_ucs2cat((CHAR *) str, (CHAR *) storage_str_p[0]);
        /* ? will be shown by popup not application */
        //mmi_ucs2cat((CHAR *) str, (CHAR *) GetString(STR_ID_FMGR_QUESTION_MARK));

        /* only phone storage is avaible */
        mmi_medply_plst_confirm_simple(
            GRP_ID_MEDPLY_LIST_STORAGE_CHANGE,
            (WCHAR *)str,
            mmi_medply_plst_storage_change_LSK,
            CNFM_TYPE_YESNO,
            MMI_FALSE,
            MMI_EVENT_QUERY);     
    }
    else
    {
        /* more than 2 storage is avaible */
        mmi_medply_plst_listmgr_select_storage();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_storage_check
 * DESCRIPTION
 *  check if current storage is ok
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_FALSE:  current storage is not availble
 *  MMI_TRUE:   current storage is OK
 *****************************************************************************/
MMI_BOOL mmi_medply_plst_storage_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 storage;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_KURO_SUPPORT__
    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_DEFAULT_STORAGE, &storage);
#else
    storage = plst_cntx_p->default_storage;
#endif
    if (FS_GetDevStatus(storage, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        mmi_medply_plst_storage_change(g_gid_medply);
        return MMI_FALSE;
    }

    return MMI_TRUE;

}
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_entry_playlist_internal
 * DESCRIPTION
 *  entry playlist 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_entry_playlist_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_dynamic_list_data_struct* list_ui = &(plst_cntx_p->list_ui);
    S32 highlighted_item = 0;
    U8 *guiBuffer = NULL;
    mmi_medply_plst_struct* list = NULL;
#ifdef __MMI_KURO_SUPPORT__
    S32 result;
#endif
    MMI_BOOL entry_ret;
   
   /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (browser_now_playing)
    {
        list = &(plst_cntx_p->current_list);
    }
    else
    {
        list = plst_cntx_p->browser_list_p;
    }


    if (mmi_frm_group_is_present(GRP_ID_MEDPLY_MAIN_SCREEN))
    {
        g_gid_browser_list = GRP_ID_MEDPLY_LIST_BROWSER_CURR;
        mmi_frm_group_create(GRP_ID_MEDPLY_MAIN_SCREEN, g_gid_browser_list, mmi_medply_plst_proc, (void*)NULL); 
    }
    else
    {
        g_gid_browser_list = GRP_ID_MEDPLY_LIST_BROWSER;
        mmi_frm_group_create(g_gid_medply, g_gid_browser_list, mmi_medply_plst_proc, (void*)NULL); 
    }
    
    mmi_frm_group_enter(g_gid_browser_list, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    entry_ret = mmi_frm_scrn_enter(g_gid_browser_list, SCR_ID_MEDPLY_LIST_BROWSER, mmi_medply_plst_exit_playlist, mmi_medply_plst_entry_playlist_internal, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }    
    
    /*if the playlist updated, gui buffer will set null*/
    if (NULL == mmi_frm_scrn_get_gui_buf(g_gid_browser_list, SCR_ID_MEDPLY_LIST_BROWSER))
    {
        mmi_medply_plst_ui_reset_cntx();
        mmi_medply_plst_ui_init_cntx();
    }
    else
    {
        mmi_medply_plst_reload_list();
    }


    mmi_frm_scrn_set_leave_proc(g_gid_browser_list, SCR_ID_MEDPLY_LIST_BROWSER, mmi_medply_plst_del_list_browser_callback);
    g_medply.in_list_screen = MMI_TRUE;
    in_browser_mode = MMI_TRUE;

    if (!plst_cntx_p->list_loaded && browser_now_playing)
    {
        mmi_frm_group_close(g_gid_browser_list);
        return;
    }

    if (!mmi_medply_plst_curr_is_valid() && browser_now_playing)
    {

    #ifndef __MMI_WGUI_DISABLE_CSK__
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    #endif
        ShowCategory52Screen(
            STR_ID_MEDPLY_PLST_TITLE,
            GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            0,
            NULL,
            NULL,
            NULL,
            1,
            0,
            NULL);
       
        SetCenterSoftkeyFunction(mmi_medply_plst_option_add_part1, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_medply_plst_entry_playlist_option, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_medply_plst_gobackhistory, KEY_EVENT_UP);
    }
    else if (list_ui->total == 0)
    {
        U16 string_id;
        U8 *title_p;

    #ifndef __MMI_WGUI_DISABLE_CSK__
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    #endif
    
        if (browser_all_audio)
        {
            string_id = STR_GLOBAL_REFRESH;
            title_p = (U8 *)GetString(STR_ID_MEDPLY_ALL_AUDIO);
        }
        else if (browser_all_video)
        {
            string_id = STR_GLOBAL_REFRESH;
            title_p = (U8 *)GetString(STR_ID_MEDPLY_ALL_VIDEO);
        }
        else
        {
            string_id = STR_GLOBAL_ADD;
            title_p = (U8 *)list->title;
        }
        ShowCategory353Screen(
            (PU8)title_p,
            GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
            string_id,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            0,
            NULL,
            NULL,
            NULL,
            1,
            0,
            NULL);
        if (browser_all_audio || browser_all_video)
        {
            SetCenterSoftkeyFunction(mmi_medply_plst_option_update, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(mmi_medply_plst_option_update, KEY_EVENT_UP);
        }
        else
        {
            SetCenterSoftkeyFunction(mmi_medply_plst_option_add_part1, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(mmi_medply_plst_option_add_part1, KEY_EVENT_UP);
        }
        SetRightSoftkeyFunction(mmi_medply_plst_gobackhistory, KEY_EVENT_UP);
        
    }
    else
    {       
        UI_character_type *title;   
        
        /*
        **  3 cases:
        **      1. now playing list screen and enter from player screen.
        **          need set highlight on playing item. 
        **      2. back from main screen, should change hilite to current
        **          playing item (according to MAUI_02610488)
        **      3. common list browser screen and enter from list manager. 
        **          do not care highlight, always set to begin.
        */
        guiBuffer = mmi_frm_scrn_get_gui_buf(g_gid_browser_list, SCR_ID_MEDPLY_LIST_BROWSER);
        if (guiBuffer != NULL)
        {
            list_menu_category_history *hist = (list_menu_category_history*) guiBuffer;
            /* case 2. */
            if (from_main_scr)
            {
                highlighted_item = mmi_medply_plst_curr_get_curr_index();
                if (highlighted_item >= 0)
                {
                    hist->highlighted_item = highlighted_item;
                }
                else
                {
                    highlighted_item = hist->highlighted_item;
                }
                    from_main_scr = MMI_FALSE;
            }
			else
            {
                highlighted_item = hist->highlighted_item;
            }
        }
        else
        {
            /* case 1. */
            if (browser_now_playing && mmi_medply_plst_is_scrn_present(GRP_ID_MEDPLY_MAIN_SCREEN, SCR_ID_MEDPLY_MAIN_SCREEN))
            {
                highlighted_item = mmi_medply_plst_curr_get_curr_index();
                if (highlighted_item < 0)
                {
                    highlighted_item = 0;
                }
            }
            else    /* case 3. */
            {
                highlighted_item = 0;
            }
                    from_main_scr = MMI_FALSE;
        }
        plst_cntx_p->list_ui.highlight = highlighted_item;
        
        if (browser_now_playing && plst_cntx_p->browser_list_p)
        {
            memcpy(plst_cntx_p->browser_list_p, &(plst_cntx_p->current_list), sizeof(mmi_medply_plst_struct));
        }

        /* register highligh handler */
        RegisterHighlightHandler(mmi_medply_plst_ui_highlight_hdlr);
    #ifndef __MMI_WGUI_DISABLE_CSK__
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    #endif
        if (browser_all_audio)
        {
            title = (UI_character_type *)GetString(STR_ID_MEDPLY_ALL_AUDIO);
        }
        else if (browser_all_video)
        {
            title = (UI_character_type *)GetString(STR_ID_MEDPLY_ALL_VIDEO);
        }
        else
        {
            title = (UI_character_type *)list->title;
        }
        ShowCategory183Screen(
            title, 
            get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)),    
            get_string(STR_GLOBAL_OPTIONS),
            get_image(IMG_GLOBAL_OPTIONS),              
            get_string(STR_GLOBAL_BACK),
            get_image(IMG_GLOBAL_BACK), 
            list_ui->total,
            mmi_medply_plst_get_item,
            NULL,
            highlighted_item,
            MMI_FALSE,
            NULL,
            guiBuffer);
        
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_medply_plst_tap_callback);
#endif
       
        SetCenterSoftkeyFunction(mmi_medply_plst_option_initiate_play, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_medply_plst_entry_playlist_option, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_medply_plst_gobackhistory, KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_reload_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_reload_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 total = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    plst_cntx_p->list_ui.cache_end_index = 0;
    plst_cntx_p->list_ui.cache_start_index = 0;
    kal_mem_set(&plst_cntx_p->list_ui.cache[0], 0 , MMI_MEDPLY_LIST_BUFF_SIZE * sizeof(mmi_medply_dynamic_list_item_info_struct));
    plst_cntx_p->list_ui.head = 0;
    plst_cntx_p->list_ui.tail = 0;
    if (browser_now_playing)
    {
        plst_cntx_p->list_ui.total = plst_cntx_p->current_list.total;
        mmi_medply_plst_get_list(&total, 0);
    }
    else
    {
        plst_cntx_p->list_ui.total = plst_cntx_p->browser_list_p->total;
        mmi_medply_plst_get_list(&total, 0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_exchange_bitset
 * DESCRIPTION
 *  change bitset of playlist
 * PARAMETERS
 *  old_index       [IN]
 *  new_index       [IN]
 *  bitset          [IN/OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_exchange_bitset(U16 old_index, U16 new_index, PU8 bitset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL old_set = MMI_FALSE;
    MMI_BOOL new_set = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    
    if (IsBitSetOn(old_index, bitset))
    {
        ClrBitSet(old_index, bitset);
        old_set = MMI_TRUE;
    }

    if (IsBitSetOn(new_index, bitset))
    {
        ClrBitSet(new_index, bitset);
        new_set = MMI_TRUE;
    }

    if (old_set)
    {
        SetBitSet(new_index, bitset);
    }

    if (new_set)
    {
        SetBitSet(old_index, bitset);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_sort_bitset
 * DESCRIPTION
 *  sort bitset 
 * PARAMETERS
 *  idx         [IN]
 *  total       [IN]
 *  bitset      [IN/OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_sort_bitset(U16 idx, U16 total, PU8 bitset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 move_times = (total - 1 - idx);
    U16 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    for (i = 0; i < move_times; i++)
    {
        mmi_medply_plst_exchange_bitset((idx + i), (idx + i + 1), bitset);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_sort_index
 * DESCRIPTION
 *  sortindex 
 * PARAMETERS
 * list     [IN][OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_sort_index(mmi_medply_plst_struct* list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    U16 empty = 0;
    U16 used = list->header.total_slot;
    U16 total = list->header.total_slot + 1;
    mmi_medply_plst_index_node_struct* index = list->header.index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < total; i++)
    {
        if (index[i].index != i)
        {
            if (index[i].index == MMI_MEDPLY_MAX_PLAYLIST_ITEM)
            {
                index[i].index = used + empty;
                empty++;
            }
            else
            {
                index[i].index = i;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_is_all_tracks_playing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
//MAUI_02628471
static MMI_BOOL mmi_medply_plst_is_all_tracks_playing(void)
{
#if defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (!plst_cntx_p || !plst_cntx_p->list_loaded)
    {
        return MMI_FALSE;
    }
    
#ifdef __MMI_KURO_SUPPORT__
    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_DEFAULT_STORAGE, &plst_cntx_p->default_storage);
#endif
    kal_wsprintf(
        path, 
        "%c:\\%w\\%w%w",
        plst_cntx_p->default_storage, 
        MMI_MEDPLY_DEFAULT_FOLDER,
        MMI_MEDPLY_ALL_AUDIO_LIST,
        MMI_MEDPLY_DEFAULT_LIST_EXT);
    if (!mmi_ucs2icmp((CHAR*)path, (CHAR*)plst_cntx_p->current_list.path))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ALL_AUDIO_IS_PLAYING,__LINE__);
        return MMI_TRUE;
    }
    
    kal_wsprintf(
        path, 
        "%c:\\%w\\%w%w",
        plst_cntx_p->default_storage, 
        MMI_MEDPLY_DEFAULT_FOLDER,
        MMI_MEDPLY_ALL_VIDEO_LIST,
        MMI_MEDPLY_DEFAULT_LIST_EXT);
    if (!mmi_ucs2icmp((CHAR*)path, (CHAR*)plst_cntx_p->current_list.path))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ALL_VIDEO_IS_PLAYING,__LINE__);
        return MMI_TRUE;
    }

    return MMI_FALSE;
#else

    return MMI_FALSE;
#endif /* __MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_all_tracks_list_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_plst_all_tracks_list_delete(void)
{
#if defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    S32 ret = 0;
    S32 fs_ret = FS_NO_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_DELTETE_LIST_BEGIN);
    /* count the current index in cache. */
    mmi_medply_plst_listmgr_get_path(path);

    if (browser_now_playing)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_DELTETE_NOW_PLAYING);
        /*need set media type to NONE, to avoid states not change to IDLE.*/
        g_medply.media_type = MEDPLY_TYPE_NONE;
        mmi_medply_stop_playing();
        FS_Commit(plst_cntx_p->current_list.fs_hdlr);
        fs_ret = FS_Close(plst_cntx_p->current_list.fs_hdlr);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE, plst_cntx_p->current_list.fs_hdlr,__LINE__);
        if (fs_ret < FS_NO_ERROR)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_DELTETE_ERROR_CODE, fs_ret);
            return fs_ret;
        }
    }
    else
    {
        FS_Close(plst_cntx_p->browser_list_p->fs_hdlr);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->browser_list_p->fs_hdlr ,__LINE__);
    }

    
    ret = FS_Delete((PU16)path);
    /* error handling. */
    if (ret < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_DELTETE_ERROR_CODE, ret);
        if (browser_now_playing)
        {
            /* try to reopen. */
            S32 hdlr = FS_NO_ERROR;

            hdlr = FS_Open(plst_cntx_p->current_list.path, FS_READ_WRITE);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_OPEN,hdlr,__LINE__);
            if (hdlr < 0)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_DELTETE_ERROR_CODE, hdlr);
                /* clear list data and player variables. */
                plst_cntx_p->list_loaded = MMI_FALSE;
                browser_now_playing = MMI_FALSE;
                memset(&(plst_cntx_p->current_list), 0, sizeof(mmi_medply_plst_struct));
            }
            else
            {
                plst_cntx_p->current_list.fs_hdlr = hdlr;
            }
        }
        return fs_ret;
    }
    else
    {
        /* no error, popup successful. */
        if (browser_now_playing)
        {
            plst_cntx_p->list_loaded = MMI_FALSE;
            browser_now_playing = MMI_FALSE;
            memset(&(plst_cntx_p->current_list), 0, sizeof(mmi_medply_plst_struct));
            mmi_medply_plst_clear_context_variables();
        }
        return 0;
    }
#else

    return 0;
#endif /* __MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_option_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_option_update(void)
{
#if defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    mmi_medply_plst_struct* list_p = NULL;
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    MMI_ID cui_gid = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (browser_now_playing)
    {
        list_p = &(plst_cntx_p->current_list);
    }
    else
    {
        list_p = plst_cntx_p->browser_list_p;
    }

    if (list_p->total > 0)
    {
        ret = mmi_medply_plst_all_tracks_list_delete();
        if (ret < 0)
        {
            mmi_medply_plst_popup_simple(ret);
            mmi_medply_plst_gobacktomain();
            return;
        }
        else
        {
            ret = mmi_medply_plst_all_media_list_init(MMI_FALSE);
            if(ret < 0)
            {
                mmi_medply_plst_popup_simple(ret);
                mmi_medply_plst_gobacktomain();
                return;
            }
            else
            {
                mmi_medply_plst_listmgr_get_path(path);
                ret = mmi_medply_plst_open(path);
                if (ret < 0)
                {
                    mmi_medply_plst_popup_simple(ret);
                    mmi_medply_plst_gobacktomain();
                    return;
                }
            }
        }
    }
    else
    {
        MMI_ASSERT(list_p->total == 0);
    }
    
    ret = FS_Seek(list_p->fs_hdlr, list_p->header.footer_pattern_offset, FS_FILE_BEGIN);
    FS_Truncate(list_p->fs_hdlr);

    mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_LIST_GEN, mmi_medply_plst_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_LIST_GEN, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_gid = mmi_medply_cui_search_create(GRP_ID_MEDPLY_LIST_GEN, MEDPLY_GENERATE_TIMER);

    if (cui_gid > GRP_ID_INVALID)
    {
        memset(&plst_cntx_p->generate_cntx, 0, sizeof(mmi_medply_plst_generate_struct));
        plst_cntx_p->generate_cntx.run_type = MEDPLY_CUI_SEARCH_TYPE_UPDATE_ALL_DRV;
        
        if (browser_all_video)
        {
            /* only all video uses video filter */
            mmi_medply_cui_search_set_mode(cui_gid, MEDPLY_CUI_SEARCH_TYPE_UPDATE_ALL_DRV, MEDPLY_CUI_SEARCH_FILTER_VIDEO);
        }
        else
        {
            /* others use audio filter */
            mmi_medply_cui_search_set_mode(cui_gid, MEDPLY_CUI_SEARCH_TYPE_UPDATE_ALL_DRV, MEDPLY_CUI_SEARCH_FILTER_AUDIO);
        }
        mmi_medply_cui_search_run(cui_gid);
    }
    else
    {   
        mmi_medply_plst_popup_simple_with_string( (U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_option_settings
 * DESCRIPTION
 *  option settings
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_option_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_settings_entry_main();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_option_initiate_play
 * DESCRIPTION
 *  init play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_option_initiate_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    mmi_medply_dynamic_list_data_struct* ui = &(plst_cntx_p->list_ui);
    S32 result = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_PLAY, plst_cntx_p->default_storage, plst_cntx_p->list_loaded, plst_cntx_p->current_list.fs_hdlr, plst_cntx_p->browser_list_p, browser_now_playing, __LINE__);

#if defined(__MMI_BACKGROUND_CALL__) && !defined(__RF_DESENSE_TEST__) && !defined(__CS_STREAMING_CONCURRENT_SUPPORT__)
    if(srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        mmi_medply_plst_gobacktomain();
        return;
    }
#endif
    if (!in_browser_mode)
    {
        return;
    }    

    result = mmi_medply_plst_get_path(path, ui->highlight);
    if (result < 0)
    {
        /* get highlight item's path failed. popup and return. */
        mmi_medply_plst_popup_simple(result);
        return;
    }
   
    if (mmi_frm_group_is_present(GRP_ID_MEDPLY_LIST_BROWSER))
    {
        from_main_scr = MMI_TRUE; // change feature MAUI_02610488
    }

   
    if (plst_cntx_p->list_loaded)
    {
        if (!browser_now_playing)
        {
            /* close nowplaying list. */
            mmi_medply_plst_write_back_to_file(&(plst_cntx_p->current_list));
            FS_Close(plst_cntx_p->current_list.fs_hdlr);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->current_list.fs_hdlr ,__LINE__);
            memset(&(plst_cntx_p->current_list), 0, sizeof(mmi_medply_plst_struct));
            /* copy all info about now browsering list to "current_list". (reload)*/
            memcpy(&(plst_cntx_p->current_list), plst_cntx_p->browser_list_p, sizeof(mmi_medply_plst_struct));
            mmi_medply_plst_save_last_path(plst_cntx_p->current_list.path);/*WriteRecord  NVRAM_EF_MEDPLY_LAST_PLAYLIST_PATH_LID*/
            browser_now_playing = MMI_TRUE;
        }
        
        /* initiate play. */
        {
            mmi_medply_plst_set_start(plst_cntx_p->list_ui.highlight);
            mmi_medply_plst_set_pick_index(plst_cntx_p->list_ui.highlight);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_PLAY_PICK_INDEX,plst_cntx_p->list_ui.highlight ,__LINE__);

            /* enter player screen. */
            if (!mmi_medply_plst_is_scrn_present(GRP_ID_MEDPLY_MAIN_SCREEN, SCR_ID_MEDPLY_MAIN_SCREEN))
            {
                /* initiate play from list manager's list browser. */
                mmi_medply_play_from_play_list();
            }
            else
            {
                /* initiate play from now playling list. */
                mmi_frm_scrn_close(GRP_ID_MEDPLY_MAIN_SCREEN, SCR_ID_MEDPLY_MAIN_SCREEN);
                mmi_medply_play_from_play_list();
                mmi_frm_group_close(g_gid_browser_list);/* for MAUI_01879425 change delete screen before play */
            }
        }
    }
    else
    {
        /* init "current_list". */
        memset(&(plst_cntx_p->current_list), 0, sizeof(mmi_medply_plst_struct));
        /* copy all info about now browsering list to "current_list". */
        memcpy(&(plst_cntx_p->current_list), plst_cntx_p->browser_list_p, sizeof(mmi_medply_plst_struct));
        mmi_medply_plst_save_last_path(plst_cntx_p->current_list.path);
        /* set nowplaying flag. */
        browser_now_playing = MMI_TRUE;
        plst_cntx_p->list_loaded = MMI_TRUE;
        /* initiate play. */
        {
            mmi_medply_plst_set_start(plst_cntx_p->list_ui.highlight);
            mmi_medply_plst_set_pick_index(plst_cntx_p->list_ui.highlight);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_PLAY_PICK_INDEX,plst_cntx_p->list_ui.highlight ,__LINE__);

            /* enter player screen. */
            if (!mmi_medply_plst_is_scrn_present(GRP_ID_MEDPLY_MAIN_SCREEN, SCR_ID_MEDPLY_MAIN_SCREEN))
            {
                /* initiate play from list manager's list browser. */
                mmi_medply_play_from_play_list();
            }
            else
            {
                /* initiate play from now playling list. */
                mmi_frm_scrn_close(GRP_ID_MEDPLY_MAIN_SCREEN, SCR_ID_MEDPLY_MAIN_SCREEN);
                mmi_medply_play_from_play_list();
                mmi_frm_group_close(g_gid_browser_list);/* for MAUI_01879425 change delete screen before play */
            }
        }
    }
    /* reset highlight in main list screen. */
    mmi_medply_plst_post_event_to_main(EVT_ID_MEDPLY_RESET_MAINMENU, NULL);
}


#ifdef __MMI_KURO_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_kuro_plst_option_activate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_kuro_plst_option_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;   
    S32 hilite = 0;
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    mmi_medply_dynamic_list_data_struct* ui = &(plst_cntx_p->list_ui);
    mmi_medply_plst_struct* list = plst_cntx_p->browser_list_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_medply_plst_get_path(path, ui->highlight);
    if (ret < 0)
    {
        /* get highlight item's path failed. popup and return. */
        mmi_medply_plst_popup_simple(ret);
        return;
    }

    if (browser_now_playing)
    {        
        list = &(plst_cntx_p->current_list);
    }

    if (plst_cntx_p->list_ui.highlight >= MMI_MEDPLY_MAX_PLAYLIST_ITEM)
    {
        return;
    }
    else
    {
        hilite = plst_cntx_p->list_ui.highlight;
    }

    plst_cntx_p->activate_from_list = TRUE;
    
    if (browser_now_playing)
    {        
        if (list->pick_index == hilite)	
        {
            g_medply.activate_type = MEDPLY_ACTIVATE_CURRENT_MEDIA; 
            mmi_medply_kuro_activate_confirm();
            return;
        }
    }

    g_medply.activate_type = MEDPLY_ACTIVATE_FROM_LIST;
    
    mmi_medply_kuro_activate_confirm();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_kuro_get_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_medply_plst_get_kurofile_path(UI_string_type filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    ret = mmi_medply_plst_get_path(filepath, mmi_medply_plst_ui_get_current_highlight());

    if (ret < 0)
    {
        mmi_medply_plst_popup_simple(ret);
    }
    return ret ;
}
#endif





/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_option_remove_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_option_remove_int(MMI_BOOL delete_f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plst_struct* list = plst_cntx_p->browser_list_p;
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    mmi_medply_plst_block_node_struct block;
    U32 backup_offset = 0;
    U32 current_offset = 0;
    U32 fs_size = 0;
    S32 ret = FS_NO_ERROR;
    U8 i = 0;
    MMI_BOOL remove_playing = MMI_FALSE;
    S32 hilite = 0;
    S32 next_pick_idx = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (browser_now_playing)
    {        
        list = &(plst_cntx_p->current_list);
    }
    
    if (plst_cntx_p->list_ui.highlight >= MMI_MEDPLY_MAX_PLAYLIST_ITEM)
    {
        return;
    }
    else
    {
        hilite = plst_cntx_p->list_ui.highlight;
    }
    
    if (browser_now_playing)
    {        
        if (list->pick_index == hilite)  /* remove now playing file. */
        {
            /* stop now playing. */
            g_medply.media_type = MEDPLY_TYPE_NONE;
            mmi_medply_stop_playing();
            remove_playing = MMI_TRUE;
        }
        else 
        {
            next_pick_idx = list->pick_index;
            if (list->pick_index == list->total - 1) /*current highlighted last one, need decrease one with change of total.*/
            {
                next_pick_idx--;
            }
            else if (list->pick_index > hilite)  /* the removed item behind playing item, pick index need decrease.*/
            {
                next_pick_idx--;
            }
        }
        
        if (delete_f)
        {
            ret = mmi_medply_plst_get_path_internal(list, path, hilite);
            
            if (ret >= FS_NO_ERROR)
            {
                if (path[0] == '\0')
                {
                    /* if the path is empty , skip to remove the block only */
                }
                else
                {
                    ret = FS_Delete((WCHAR*)path);
                    if (ret < FS_NO_ERROR)
                    {
                        mmi_medply_plst_popup_simple(ret);
                        return;
                    }
                }
            }
        }

        if (IsBitSetOn(hilite, list->bitset)) /* if the removed item had played, need clear its bitset, and decrease.*/ 
        {
            list->pick_count--;
            /* clear bitset. */
            ClrBitSet(hilite, list->bitset);
        }
        
        /* re-sort bitset. */
        mmi_medply_plst_sort_bitset(hilite, list->header.total_slot, list->bitset);
    }
    else
    {
        if (delete_f)
        {
            ret = mmi_medply_plst_get_path_internal(list, path, hilite);
            
            if (ret >= FS_NO_ERROR)
            {
                if (path[0] == '\0')
                {
                    /* if the path is empty , skip to remove the block only */
                }
                else
                {
                    ret = FS_Delete((PU16)path);
                    if (ret < 0)
                    {
                        mmi_medply_plst_popup_simple(ret);
                        return;
                    }
                }
            }
        }
    }

    
    /* reset empty node in header. */
    backup_offset = list->header.empty_node.offset;
    list->header.empty_node.offset = list->header.index[hilite].offset;
    list->header.empty_node.used_block += list->header.index[hilite].used_block;
    
    /* reset node in header. */
    current_offset = list->header.index[hilite].offset;
    list->header.index[hilite].is_active = 0;
    list->header.index[hilite].index = MMI_MEDPLY_MAX_PLAYLIST_ITEM;
    list->header.index[hilite].offset = 0;
    
    do
    {
        /* seek to tail block. */
        for (i = 0; i < list->header.index[hilite].used_block; i++)
        {
            /* move file pointer to the x block which used by removing item. */
            ret = FS_Seek(list->fs_hdlr, current_offset, FS_FILE_BEGIN);
            if (ret < FS_NO_ERROR)
            {
                break;
            }
            /* read block. */
            ret = FS_Read(list->fs_hdlr, &block, sizeof(mmi_medply_plst_block_node_struct), &fs_size);
            if (ret < FS_NO_ERROR)
            {
                break;
            }
            /* check fs read result. */
            if (fs_size != sizeof(mmi_medply_plst_block_node_struct))
            {
                ret = MEDPLY_PLST_ERR_READ_FAILED;
                break;
            }
            /* check guard pattern. */
            if (block.pattern_begin != MEDPLY_PLAYLIST_BLOCK_PATTERN_1 ||
                block.pattern_end != MEDPLY_PLAYLIST_BLOCK_PATTERN_2)
            {
                ret = MEDPLY_PLST_ERR_LIST_DAMAGED;
                break;
            }

            if (block.next_ptr == 0)
            {
                /* got tail block. */
                ret = 0;
                break;
            }
            else
            {
                current_offset = block.next_ptr;
            }
        }

        if (ret < FS_NO_ERROR)
        {
            /* error in seeking tail block. */
            break;
        }
        else
        {
            /* link all blocks of removing item to empty node link list. */
            block.next_ptr = backup_offset;
            memset(&(block.data), 0, sizeof(U8) * MMI_MEDPLY_BLOCK_DATA_SIZE);
            ret = FS_Seek(list->fs_hdlr, current_offset, FS_FILE_BEGIN);
            ret = FS_Write(list->fs_hdlr, &block, sizeof(mmi_medply_plst_block_node_struct), &fs_size);
            if (ret < FS_NO_ERROR)
            {
              /* error in re-writing tail block. */
              break;
            }
            if (fs_size != sizeof(mmi_medply_plst_block_node_struct))
            {
              ret = MEDPLY_PLST_ERR_WRITE_FAILED;
              break;
            }
        }

    } while (0);

    /* update relative variables. */
    list->header.total_slot--;
    list->total--;
    plst_cntx_p->list_ui.total--;

    /* re-sort header node list. */
    mmi_medply_plst_generate_sort_index(list->header.index, list->header.total_slot + 1);
    MMI_ASSERT(list->header.pattern == MEDPLY_PLAYLIST_FOOTER_PATTERN);

    /* re-sort index of header nodes. */
    mmi_medply_plst_sort_index(list);

    /* write back to playlist file. */
    ret = mmi_medply_plst_write_back_to_file(list);

    
    if (browser_now_playing)
    {
        if (remove_playing && !mmi_medply_plst_curr_is_empty())
        {
            mmi_medply_plst_set_pick_index(next_pick_idx);
            mmi_medply_plst_apply_picked_file();
        }
        else if (mmi_medply_plst_curr_is_empty())
        {
            mmi_medply_plst_clear_context_variables();
        }
        else
        {
            list->pick_index = next_pick_idx;
        }
    }
	/* removed for new UE */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_option_delete_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_option_delete_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_plst_option_remove_int(MMI_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_option_remove_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_option_remove_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_plst_option_remove_int(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_option_remove
 * DESCRIPTION
 *  option remove
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_option_remove(MMI_BOOL delete_f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plst_struct* list = plst_cntx_p->browser_list_p;
    UI_character_type str[MEDPLY_MAX_PATH_LEN];
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    CHAR* filename_ptr = NULL;
    S32 hilite = 0;
    mmi_str_id str_id;
    FuncPtr confirm_LSK;
    MMI_BOOL confirm_no_icon;
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (delete_f)
    {
        str_id = STR_GLOBAL_DELETE;
        confirm_LSK = mmi_medply_plst_option_delete_LSK;
        confirm_no_icon = MMI_TRUE;
    }
    else
    {
        str_id = STR_GLOBAL_REMOVE;
        confirm_LSK = mmi_medply_plst_option_remove_LSK;
        confirm_no_icon = MMI_FALSE;
    }

    if (browser_now_playing)
    {        
        list = &(plst_cntx_p->current_list);
    }
    
    if (plst_cntx_p->list_ui.highlight >= MMI_MEDPLY_MAX_PLAYLIST_ITEM)
    {
        return;
    }
    else
    {
        hilite = plst_cntx_p->list_ui.highlight;
    }

    ret = mmi_medply_plst_get_path_internal(list, path, hilite);
    if (ret >= FS_NO_ERROR)
    {
        if (path[0] == '\0')
        {
            mmi_medply_plst_popup_simple_with_string(get_string(STR_ID_MEDPLY_PLST_NOTIFY_READ_FAILED), MMI_EVENT_FAILURE);
            return;
        }
        
        filename_ptr = mmi_ucs2rchr((CHAR*)path, (U16)(L'\\'));
        if (filename_ptr == NULL)
        {
            mmi_medply_plst_popup_simple_with_string(get_string(STR_ID_MEDPLY_PLST_NOTIFY_READ_FAILED), MMI_EVENT_FAILURE);
            return;
        }
        else
        {
            CHAR* ext_p = NULL;
            
            filename_ptr += 2;
            ext_p = mmi_ucs2rchr((CHAR*)filename_ptr, (U16)L'.');
            MMI_ASSERT(ext_p != NULL);
            *(ext_p + 1) = 0;
            *ext_p = 0;
        }      

    }
    else
    {
        mmi_medply_plst_popup_simple(ret);
        return;
    }
    
    memset(str, 0, sizeof(str));
    mmi_ucs2ncpy((CHAR*)str, (CHAR*) get_string(str_id), MEDPLY_MAX_PATH_LEN);
    mmi_ucs2ncat((CHAR*)str, (CHAR*) L"\n", MEDPLY_MAX_PATH_LEN);
    mmi_ucs2ncat((CHAR*)str, (CHAR*)filename_ptr, MEDPLY_MAX_PATH_LEN);
    
    mmi_medply_plst_confirm_simple(
        g_gid_browser_list,
        (WCHAR *)str,
        confirm_LSK,
        CNFM_TYPE_YESNO,
        confirm_no_icon,
        MMI_EVENT_QUERY);     
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_option_moveup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_option_moveup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plst_struct* list = plst_cntx_p->browser_list_p;
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (browser_now_playing)
    {
        list = &(plst_cntx_p->current_list);
    }
    MMI_ASSERT(list->total <= MMI_MEDPLY_MAX_PLAYLIST_ITEM);
    if (plst_cntx_p->list_ui.highlight == 0)
    {
        U16 i = 0;
        if (browser_now_playing)
        {
            if (list->header.index[0].index == list->pick_index)
            {
                /* set pick index. */
                list->pick_index = (list->total - 1);
                /* set first index to last one. */
                list->header.index[0].index = list->total - 1;
                /* set other's index. */
                for (i = 1; i < list->total; i++)
                {
                    /* exchange bitset. */
                    mmi_medply_plst_exchange_bitset(
                            list->header.index[i].index,
                            (U16)(list->header.index[i].index - 1),
                            list->bitset);
                    /* set index. */
                    list->header.index[i].index--; 
                }
                /* set highlight. */
                plst_cntx_p->list_ui.highlight = (list->total - 1);
            }
            else
            {
                MMI_BOOL set = MMI_FALSE;
                /* set first index to last one. */
                list->header.index[0].index = list->total - 1;
                /* set other's index. */                
                for (i = 1; i < list->total; i++)
                {                   
                    if (list->header.index[i].index == list->pick_index && !set)
                    {
                        /* set pick index. */
                        list->pick_index--;
                        set = MMI_TRUE;
                    }
                    /* exchange bitset. */
                    MMI_ASSERT(i < MMI_MEDPLY_MAX_PLAYLIST_ITEM);
                    mmi_medply_plst_exchange_bitset(
                            list->header.index[i].index,
                            (U16)(list->header.index[i].index - 1),
                            list->bitset);
                    /* set index. */
                    list->header.index[i].index--; 
                }
                /* set highlight. */
                plst_cntx_p->list_ui.highlight = (list->total - 1);
            }

            mmi_medply_plst_save_last_index(list->pick_index);
        }
        else
        {
            list->header.index[0].index = list->total - 1;
            for (i = 1; i < list->total; i++)
            {
                list->header.index[i].index--; 
            }
            /* set highlight. */
            plst_cntx_p->list_ui.highlight = (list->total - 1);
        }
    }
    else
    {
        if (browser_now_playing)
        {
            if (list->pick_index == list->header.index[plst_cntx_p->list_ui.highlight].index)
            {
                list->pick_index--;
            }
            else if (list->pick_index == list->header.index[plst_cntx_p->list_ui.highlight - 1].index)
            {
                list->pick_index++;
            }
           
            mmi_medply_plst_exchange_bitset(
                        list->header.index[plst_cntx_p->list_ui.highlight].index,
                        list->header.index[plst_cntx_p->list_ui.highlight - 1].index,
                        list->bitset);
            list->header.index[plst_cntx_p->list_ui.highlight].index--;
            list->header.index[plst_cntx_p->list_ui.highlight - 1].index++;
            plst_cntx_p->list_ui.highlight--;
            mmi_medply_plst_save_last_index(list->pick_index);
        }
        else
        {
            list->header.index[plst_cntx_p->list_ui.highlight].index--;
            list->header.index[plst_cntx_p->list_ui.highlight - 1].index++;
            plst_cntx_p->list_ui.highlight--;
        }
    }
    mmi_medply_plst_generate_sort_index(list->header.index, list->total);
    MMI_ASSERT(list->header.pattern == MEDPLY_PLAYLIST_FOOTER_PATTERN);
    guiBuffer = mmi_frm_scrn_get_gui_buf(g_gid_browser_list, SCR_ID_MEDPLY_LIST_BROWSER);
    if (guiBuffer != NULL)
    {
        list_menu_category_history *hist = (list_menu_category_history*) guiBuffer;
        hist->highlighted_item = plst_cntx_p->list_ui.highlight;
    }
    mmi_frm_group_close(GRP_ID_MEDPLY_LIST_BROWSER_OPT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_option_movedown
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_option_movedown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plst_struct* list = plst_cntx_p->browser_list_p;
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (browser_now_playing)
    {
        list = &(plst_cntx_p->current_list);
    }
    if (plst_cntx_p->list_ui.highlight == (list->total - 1))
    {
        U16 i = 0;
        if (browser_now_playing)
        {
            if (list->header.index[plst_cntx_p->list_ui.highlight].index == list->pick_index)
            {
                list->pick_index = 0;
                list->header.index[plst_cntx_p->list_ui.highlight].index = 0;
                for (i = 0; i < (list->total - 1); i++)
                {
                    mmi_medply_plst_exchange_bitset(
                            list->header.index[i].index,
                            (U16)(list->header.index[i].index + 1),
                            list->bitset);
                    list->header.index[i].index++;
                }
                plst_cntx_p->list_ui.highlight = 0;
            }
            else
            {
                MMI_BOOL set = MMI_FALSE;
                list->header.index[plst_cntx_p->list_ui.highlight].index = 0;
                for (i = 0; i < (list->total - 1); i++)
                {
                    if (list->header.index[i].index == list->pick_index && !set)
                    {
                        list->pick_index++;
                        set = MMI_TRUE;
                    }
                    mmi_medply_plst_exchange_bitset(
                            list->header.index[i].index,
                            (U16)(list->header.index[i].index + 1),
                            list->bitset);
                    list->header.index[i].index++;
                }
                plst_cntx_p->list_ui.highlight = 0;
            }
            mmi_medply_plst_save_last_index(list->pick_index);
        }
        else
        {
            list->header.index[plst_cntx_p->list_ui.highlight].index = 0;
            for (i = 0; i < (list->total - 1); i++)
            {
                list->header.index[i].index++;
            }
            plst_cntx_p->list_ui.highlight = 0;
        }
    }
    else
    {
        if (browser_now_playing)
        {
            if (list->pick_index == list->header.index[plst_cntx_p->list_ui.highlight].index)
            {
                list->pick_index++;
            }
            else if (list->pick_index == list->header.index[plst_cntx_p->list_ui.highlight + 1].index)
            {
                list->pick_index--;
            }

            mmi_medply_plst_exchange_bitset(
                        list->header.index[plst_cntx_p->list_ui.highlight].index,
                        list->header.index[plst_cntx_p->list_ui.highlight + 1].index,
                        list->bitset);
            list->header.index[plst_cntx_p->list_ui.highlight].index++;
            list->header.index[plst_cntx_p->list_ui.highlight + 1].index--;
            plst_cntx_p->list_ui.highlight++;
            mmi_medply_plst_save_last_index(list->pick_index);
        }
        else
        {
            list->header.index[plst_cntx_p->list_ui.highlight].index++;
            list->header.index[plst_cntx_p->list_ui.highlight + 1].index--;
            plst_cntx_p->list_ui.highlight++;
        }
    }
    mmi_medply_plst_generate_sort_index(list->header.index, list->total);
    MMI_ASSERT(list->header.pattern == MEDPLY_PLAYLIST_FOOTER_PATTERN); 
    guiBuffer = mmi_frm_scrn_get_gui_buf(g_gid_browser_list, SCR_ID_MEDPLY_LIST_BROWSER);
    if (guiBuffer != NULL)
    {
        list_menu_category_history *hist = (list_menu_category_history*) guiBuffer;
        hist->highlighted_item = plst_cntx_p->list_ui.highlight;
    }
    mmi_frm_group_close(GRP_ID_MEDPLY_LIST_BROWSER_OPT);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_del_addto_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_plst_del_addto_callback(mmi_event_struct* param)
{
#if defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            if (NULL == plst_cntx_p)
            {
                break;
            }
            in_add_to_mode = MMI_FALSE;

            /* close opening play list. */
            if (!addto_now_playing)
            {
                if (plst_cntx_p->backup_list_p)
                {
                    mmi_medply_plst_write_back_to_file(plst_cntx_p->backup_list_p);
                    FS_Close(plst_cntx_p->backup_list_p->fs_hdlr);
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->backup_list_p->fs_hdlr ,__LINE__);
                    plst_cntx_p->backup_list_p->fs_hdlr = FS_ERROR_RESERVED;
                }

            }
            else
            {
                addto_now_playing = MMI_FALSE;
                mmi_medply_plst_write_back_to_file(&(plst_cntx_p->current_list));
            }
            
            if (plst_cntx_p->backup_list_p)
            {
                kal_adm_free(g_medply.adm_id_p, plst_cntx_p->backup_list_p);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE, plst_cntx_p->backup_list_p, __LINE__);
                plst_cntx_p->backup_list_p = NULL;
            }
            
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
#else

    return MMI_RET_OK;
#endif /* __MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__ */        
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_option_add_to_exit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_option_add_to_exit(void)
{
#if defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.flags |= UI_LIST_MENU_LOOP;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_option_add_to_part2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/ 
static void mmi_medply_plst_option_add_to_part2(void)
{
#if defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    mmi_medply_dynamic_list_data_struct* ui = &(plst_cntx_p->list_ui);  
    U16 total = 0;
    S32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!plst_cntx_p->list_ui.highlight)  
    {
        mmi_medply_plst_listmgr_create_part1();
    }
    else
    {        
        mmi_medply_plst_listmgr_get_path(path);
        ret = mmi_medply_plst_open(path);
        if (ret < FS_NO_ERROR)
        {
            mmi_medply_plst_popup_simple(ret);
        }
        else
        {
            if (addto_now_playing)
            {
                total = plst_cntx_p->current_list.total;
            }
            else
            {
                total = plst_cntx_p->backup_list_p->total;
            }
            
            if (total >= MMI_MEDPLY_GENERATE_LIMIT)
            {
                /* do not delete add to screen , if only the list is full */
                mmi_medply_plst_popup_simple_with_string(get_string(STR_ID_MEDPLY_PLST_NOTIFY_LIST_FULL), MMI_EVENT_FAILURE);
                FS_Close(plst_cntx_p->backup_list_p->fs_hdlr);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->backup_list_p->fs_hdlr ,__LINE__);
                plst_cntx_p->backup_list_p->fs_hdlr = FS_ERROR_RESERVED;
                return;
            }
            else
            {
                memset(&(plst_cntx_p->generate_cntx), 0, sizeof(mmi_medply_plst_generate_struct));
                ret = mmi_medply_plst_generate_append_internal(ui->temp_buffer, MMI_FALSE, MMI_TRUE);
                if (ret >= FS_NO_ERROR)
                {
	/* removed for new UE */
#if 0
/* under construction !*/
#endif
                    mmi_frm_group_close(GRP_ID_MEDPLY_LIST_ADD_TO);
                }
                else
                {
                    mmi_medply_plst_popup_simple(ret);
                    mmi_frm_group_close(GRP_ID_MEDPLY_LIST_ADD_TO);
                }
                if (addto_now_playing)
                {
                    if (plst_cntx_p->current_list.pick_index < 0)
                    {
                        if (mmi_medply_plst_do_pick() >= 0)
                        {
                            mmi_medply_plst_apply_picked_file();
                        }
                    }
                }
            }
        }
        mmi_frm_group_close(GRP_ID_MEDPLY_LIST_ADD_TO);
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_option_add_to_part1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_option_add_to_part1(void)
{
#if defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_dynamic_list_data_struct* ui = &(plst_cntx_p->list_ui);  
    UI_character_type temp_buffer[MEDPLY_MAX_PATH_LEN];
    PU8 gui_buffer = NULL;
    S32 result;
    MMI_BOOL entry_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0   
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
    result = mmi_medply_plst_get_path(temp_buffer, ui->highlight);
    if (result < 0)
    {
        /* get highlight item's path failed. popup and return. */
        mmi_medply_plst_popup_simple(result);
        return;
    }
    
    mmi_medply_plst_ui_reset_cntx();
    ui->total = mmi_medply_plst_listmgr_list_all();

    mmi_ucs2ncpy((CHAR *)ui->temp_buffer, (CHAR *)temp_buffer, MEDPLY_MAX_PATH_LEN);
    
    mmi_frm_group_create(g_gid_browser_list, GRP_ID_MEDPLY_LIST_ADD_TO, mmi_medply_plst_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_LIST_ADD_TO, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    entry_ret = mmi_frm_scrn_enter(
        GRP_ID_MEDPLY_LIST_ADD_TO, 
        SCR_ID_MEDPLY_LIST_ADD_TO, 
        mmi_medply_plst_option_add_to_exit, 
        mmi_medply_plst_option_add_to_part1, 
        MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }    
    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_LIST_ADD_TO, SCR_ID_MEDPLY_LIST_ADD_TO, mmi_medply_plst_del_addto_callback);
    in_add_to_mode = MMI_TRUE;
    
    if (NULL == plst_cntx_p->backup_list_p)
    {   /*for kuro call*/
        plst_cntx_p->backup_list_p = (mmi_medply_plst_struct*)kal_adm_alloc(g_medply.adm_id_p, sizeof(mmi_medply_plst_struct));/*bql*/
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ASM_ALLOCATE, plst_cntx_p->backup_list_p, sizeof(mmi_medply_plst_struct), __LINE__);
        MMI_ASSERT(plst_cntx_p->backup_list_p != NULL);
    }

    gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_LIST_ADD_TO, SCR_ID_MEDPLY_LIST_ADD_TO);

    RegisterHighlightHandler(mmi_medply_plst_ui_highlight_hdlr);

#ifndef __MMI_WGUI_DISABLE_CSK__
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
    //wgui_list_menu_enable_access_by_shortcut();
    ShowCategory185Screen(        
        STR_ID_MEDPLY_PLST_ADD_TO, 
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),    
        STR_GLOBAL_SELECT,
        IMG_GLOBAL_OK,              
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK, 
        ui->total + 1,
        mmi_medply_plst_listmgr_get_item,
        NULL,
        ui->highlight,
        MMI_FALSE,
        NULL,
        gui_buffer);
    
    //MMI_fixed_list_menu.flags &= ~UI_LIST_MENU_LOOP; // MAUI_03168782
    SetCenterSoftkeyFunction(mmi_medply_plst_option_add_to_part2, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_medply_plst_option_add_to_part2, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP); 

#endif    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_option_add_part2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_option_add_part2(UI_string_type fullPath, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 total = 0;
    S32 ret = 0;
    MMI_BOOL is_multi_part_odf = MMI_FALSE;
    CHAR* last_backlash = NULL;
#ifdef __DRM_V02__
    CHAR* ext = NULL;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fullPath == NULL)
    {
        mmi_frm_group_close(GRP_ID_MEDPLY_LIST_ADD);
        return;
    }
 
    if (browser_now_playing)
    {
        total = plst_cntx_p->current_list.total;
    }
    else
    {
        total = plst_cntx_p->browser_list_p->total;
    }

    if (total >= MMI_MEDPLY_GENERATE_LIMIT)
    {
        mmi_medply_plst_popup_simple_with_string(get_string(STR_ID_MEDPLY_PLST_NOTIFY_LIST_FULL), MMI_EVENT_FAILURE);
        mmi_frm_group_close(GRP_ID_MEDPLY_LIST_ADD);
        return;
    }

#ifdef __DRM_V02__
    if (NULL != (ext = mmi_ucs2rchr((CHAR*)fullPath, (U16)L'.')))
    {
        if (!mmi_ucs2nicmp((CHAR*)ext, 
            (CHAR*)L".odf", (U32)mmi_ucs2strlen((CHAR*)ext)))
        {
            if (DRM_is_archive(0, (PU16)fullPath))
            {
                is_multi_part_odf = MMI_TRUE;
            }
            else 
            {
                is_multi_part_odf = MMI_FALSE;
            }             
        }
    }
    else
    {
        is_multi_part_odf = MMI_FALSE;
    }
#else
    is_multi_part_odf = MMI_FALSE;
#endif  /* __DRM_V02__ */   

    /* the last character will be '\\' if the path got from filemgr is a folder. */
    last_backlash = mmi_ucs2rchr((CHAR*)fullPath, (U16)L'\\');

    if (2 > mmi_ucs2strlen((CHAR*)last_backlash) || is_multi_part_odf)
    {
        /* 
        ** the backlash is the last character of this path. 
        ** so this is a folder path.
        */

        /* need suspend background playing when do this about now playing list? */
        mmi_medply_plst_generate_from_folder(fullPath, is_multi_part_odf);

    }
    else
    {
        /* it is a file. append to playlist directly. */
        memset(&(plst_cntx_p->generate_cntx), 0, sizeof(mmi_medply_plst_generate_struct));
        ret = mmi_medply_plst_generate_append_internal(fullPath, (MMI_BOOL)is_short, MMI_TRUE);
        if (ret >= FS_NO_ERROR)
        {
	/* removed for new UE */
#if 0
/* under construction !*/
#endif
            mmi_medply_plst_clear_gui_buffer(g_gid_browser_list, SCR_ID_MEDPLY_LIST_BROWSER);
            mmi_frm_group_close(GRP_ID_MEDPLY_LIST_ADD);
        }
        else
        {
            mmi_medply_plst_popup_simple(ret);
            mmi_frm_group_close(GRP_ID_MEDPLY_LIST_ADD);
        }
        if (browser_now_playing)
        {
            if (plst_cntx_p->current_list.pick_index < 0)
            {
                if (mmi_medply_plst_do_pick() >= 0)
                {
                    mmi_medply_plst_apply_picked_file();
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_option_add_part1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_option_add_part1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    S32 ret = 0;
    mmi_medply_plst_struct* list_p = NULL;
    MMI_ID cui_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (browser_now_playing)
    {
        list_p = &(plst_cntx_p->current_list);
    }
    else
    {
        list_p = plst_cntx_p->browser_list_p;
    }

    if (list_p->total >= MMI_MEDPLY_GENERATE_LIMIT)
    {
        mmi_medply_plst_popup_simple_with_string(get_string(STR_ID_MEDPLY_PLST_NOTIFY_LIST_FULL), MMI_EVENT_FAILURE);
        return;
    }


    plst_cntx_p->generate_cntx.appended = 0;
    plst_cntx_p->generate_cntx.list_total= list_p->total;
    plst_cntx_p->generate_cntx.run_type= MMI_MEDPLY_GENERATE_ADD;
    
    if (ret < 0)
    {
        mmi_medply_plst_popup_simple(ret);        
    }
    else
    {
        /* call file manager API to select media file or folder.*/  
        FMGR_FILTER_INIT(&filter);
        FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
        
#ifdef MMI_MEDPLY_PLST_VIDEO_INTEGRATED
        FMGR_FILTER_SET_VIDEO(&filter);
    #ifdef __MMI_VIDEO_STREAM__
        FMGR_FILTER_SET_STREAM(&filter);
    #endif
        FMGR_FILTER_SET_AUDIO(&filter);
#else
        if (browser_all_video)
        {
            FMGR_FILTER_SET_VIDEO(&filter);
        #ifdef __MMI_VIDEO_STREAM__
            FMGR_FILTER_SET_STREAM(&filter);
        #endif
        }
        else
        {
            FMGR_FILTER_SET_AUDIO(&filter);
        }
#endif/* MMI_MEDPLY_PLST_VIDEO_FILTER */
    #ifdef __VM_CODEC_SUPPORT__
        FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_VM);
    #endif
    #if defined(__VORBIS_DECODE__) && defined(__VORBIS_DECODE_SLIM__)
        FMGR_FILTER_CLEAR(&filter, FMGR_TYPE_OGG);
    #endif
    #ifdef __DRM_V02__
        FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
    #endif
        mmi_frm_group_create(g_gid_browser_list, GRP_ID_MEDPLY_LIST_ADD, mmi_medply_plst_proc, (void*)NULL); 
        mmi_frm_group_enter(GRP_ID_MEDPLY_LIST_ADD, MMI_FRM_NODE_SMART_CLOSE_FLAG);

        cui_gid = cui_file_selector_create(
                                        GRP_ID_MEDPLY_LIST_ADD,
                                        (WCHAR*) L"root",
                                        &filter,
                                        CUI_FILE_SELECTOR_STYLE_FILE_AND_PATH,
                                        CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FILE | CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON);
        
        if (cui_gid > GRP_ID_INVALID)
        {
            cui_file_selector_set_title(cui_gid, 0, GetRootTitleIcon(MENU_ID_MEDPLY_MAIN));
            cui_file_selector_run(cui_gid);
            
            ret = FS_Seek(list_p->fs_hdlr, list_p->header.footer_pattern_offset, FS_FILE_BEGIN);
            FS_Truncate(list_p->fs_hdlr);
        }
        else
        {   
            mmi_medply_plst_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),MMI_EVENT_FAILURE);
        }

    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medlpy_plst_fmgr_file_selector_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medlpy_plst_fmgr_file_selector_handle(cui_file_selector_result_event_struct *file_select)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_path[MEDPLY_MAX_PATH_LEN + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_select->result > 0)
    {
        cui_file_selector_get_selected_filepath(
                                file_select->sender_id,
                                NULL,
                                (WCHAR *) temp_path,
                                (MEDPLY_MAX_PATH_LEN) * ENCODING_LENGTH);
        
        mmi_medply_plst_option_add_part2(temp_path, MMI_FALSE);
    }
    else if (file_select->result == 0)
    {
        cui_file_selector_close(file_select->sender_id);
    }
    else
    {
        mmi_medply_plst_popup_simple_with_string((U16*)GetString(srv_fmgr_fs_error_get_string(file_select->result)),
                                 (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(file_select->result));
        cui_file_selector_close(file_select->sender_id);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_now_playing_list_drv
 * DESCRIPTION
 *  get current playlist driver.
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 mmi_medply_plst_get_now_playing_list_drv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_medply_plst_curr_is_valid())
    {
        return (U8)(plst_cntx_p->current_list.path[0]);
    }
    else
    {
        return (U8)SRV_FMGR_PUBLIC_DRV;
    }    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_curr_get_path
 * DESCRIPTION
 *  retrieve file path and name from play list file
 * PARAMETERS
 *  out_path            [IN]        
 *  index               [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
static S32 mmi_medply_plst_curr_get_path(UI_string_type out_path, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_medply_plst_curr_is_valid())
    {
        return MEDPLY_PLST_ERR_NO_FILE_LOADED;
    }
    else if (mmi_medply_plst_curr_is_empty())
    {
        return MEDPLY_PLST_ERR_EMPTY_LIST;
    }
    else if (index < 0)
    {
        return MEDPLY_PLST_ERR_INVALID_PARA;
    }
    
    return mmi_medply_plst_get_path_internal(&(plst_cntx_p->current_list), out_path, index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_browser_get_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fullfilename        [OUT]
 *  index               [IN]
 * RETURNS
 *  U8
 *****************************************************************************/ 
static S32 mmi_medply_plst_browser_get_path(UI_string_type fullfilename, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plst_struct* list = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (browser_now_playing)
    {
        list = &(plst_cntx_p->current_list);

        if (!mmi_medply_plst_curr_is_valid())
        {
            return MEDPLY_PLST_ERR_NO_FILE_LOADED;
        }
    }
    else
    {
        list = plst_cntx_p->browser_list_p;
    }
    

    if (list->total == 0)
    {
        return MEDPLY_PLST_ERR_EMPTY_LIST;
    }
    else if (index < 0)
    {
        return MEDPLY_PLST_ERR_INVALID_PARA;
    }
    
    return mmi_medply_plst_get_path_internal(list, fullfilename, index);
}

#define __FORWARD
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_option_send
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_option_send(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 menu_id = 0;
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    mmi_medply_dynamic_list_data_struct* ui = &(plst_cntx_p->list_ui);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_medply_plst_get_path(path, ui->highlight) < 0)
    {
        cui_menu_close(menu_evt->sender_id);
        return;
    }
    menu_id = srv_fmgr_types_get_send_option_menu(FMGR_TYPE_ALL, (WCHAR *) path);
    
    if (menu_id > 0)
    {
        playlist_fwd_option_menu_id = menu_id;
        cui_menu_set_new_list_parent_id(menu_evt->sender_id, playlist_fwd_option_menu_id);
    }
    else
    {
        cui_menu_close(menu_evt->sender_id);
    }

}
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_option_send
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_option_use(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 menu_id = 0;
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    mmi_medply_dynamic_list_data_struct* ui = &(plst_cntx_p->list_ui);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_medply_plst_get_path(path, ui->highlight) < 0)
    {
        cui_menu_close(menu_evt->sender_id);
        return;
    }
    menu_id = srv_fmgr_types_get_use_option_menu(FMGR_TYPE_ALL, (WCHAR *) path);
    
    if (menu_id > 0)
    {
        playlist_fwd_option_menu_id = menu_id;
        cui_menu_set_new_list_parent_id(menu_evt->sender_id, playlist_fwd_option_menu_id);
    }
    else
    {
        cui_menu_close(menu_evt->sender_id);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_fwd_select
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_fwd_select(U16 current_menu_item_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = FS_NO_ERROR;	
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    mmi_medply_dynamic_list_data_struct* ui = &(plst_cntx_p->list_ui);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((ret = mmi_medply_plst_get_path(path, ui->highlight))< 0)
    {
        mmi_medply_plst_popup_simple(ret);
        return;
    }
    /* check file exist before execute forward action. */
    ret = FS_Open(path, FS_READ_ONLY);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_OPEN,ret ,__LINE__);
    if (ret < 0)
    {
        mmi_medply_plst_popup_simple(ret);
        return ;
    }
    else
    {
        FS_Close(ret);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,ret ,__LINE__);
    }

    srv_fmgr_types_launch_option((WCHAR *)path, current_menu_item_id);
    
}


#define __LISTMGR
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_list_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_medply_plst_listmgr_list_all(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type search_name[MEDPLY_MAX_FILE_LEN];
    FS_DOSDirEntry file_info;
    FS_HANDLE file_handle = -1;
    S32 return_value = FS_NO_ERROR;
    U16 file_count = 0;
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    FS_Pattern_Struct list_file[1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
#ifdef __MMI_KURO_SUPPORT__
    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_DEFAULT_STORAGE, &plst_cntx_p->default_storage);
#endif
    kal_wsprintf(path, "%c:\\", (CHAR)plst_cntx_p->default_storage);
    mmi_ucs2ncat((CHAR*)path, (CHAR*)MMI_MEDPLY_DEFAULT_FOLDER, (MEDPLY_MAX_PATH_LEN - 1));

    return_value = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_OPEN,return_value ,__LINE__);
    if (return_value < FS_NO_ERROR) /* no default folder in this driver. empty! */
    {
        S32 ret = FS_NO_ERROR;
        
        ret = FS_CreateDir(path);
        if (ret < FS_NO_ERROR)
        {
            /* Do not care error. */
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDIA_PLST_CREATE_DEFAULT_FOLDER_ERROR, ret);
        }
        else
        {
            FS_SetAttributes(path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
        }
        return 0;
    }
    else
    {
        FS_Close(return_value);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,return_value ,__LINE__);
    }
    
    mmi_ucs2ncat((CHAR*)path, (CHAR*)L"\\", (MEDPLY_MAX_PATH_LEN - 1));
    mmi_ucs2ncat((CHAR*)path, (CHAR*)L"*.*", (MEDPLY_MAX_PATH_LEN - 1));

    mmi_ucs2ncpy((CHAR*)list_file[0].Pattern, (CHAR*)L"*", 8);
    mmi_ucs2ncat((CHAR*)list_file[0].Pattern, (CHAR*)MMI_MEDPLY_DEFAULT_LIST_EXT, 8);

    file_handle = FS_FindFirstN(
                (PU16)path,
                list_file,
                1,
                FS_ATTR_DIR,
                0,
                FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                &file_info,
                (PU16)search_name,
                (MEDPLY_MAX_FILE_LEN) * ENCODING_LENGTH,
                0,
                FS_FIND_DEFAULT);
    
    if (file_handle >= FS_NO_ERROR)
    {
        do
        {
            if (!(file_info.Attributes & (FS_ATTR_DIR | FS_ATTR_HIDDEN | FS_ATTR_VOLUME)))
            {
                file_count++;             
            }
            
            return_value = FS_FindNextN(
                                file_handle,
                                list_file,
                                1,
                                FS_ATTR_DIR,
                                &file_info,
                                (PU16)search_name,
                                (MEDPLY_MAX_FILE_LEN) * ENCODING_LENGTH,
                                FS_FIND_DEFAULT);
        } while (return_value == FS_NO_ERROR);

        FS_FindClose(file_handle);
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_ALL_ERROR, file_handle);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_ALL_FILE_COUNT, file_count);
    return file_count;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_listmgr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_dynamic_list_data_struct* ui = &(plst_cntx_p->list_ui);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_plst_ui_reset_cntx();
    ui->total = mmi_medply_plst_listmgr_list_all();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_load_cache_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_plst_listmgr_load_cache_internal(U16 *cached_num, U16 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type search_name[MEDPLY_MAX_FILE_LEN];
    UI_character_type ext[MEDPLY_MAX_EXT_LEN];
    FS_DOSDirEntry file_info;
    FS_HANDLE file_handle = FS_NO_ERROR;
    MMI_BOOL is_short = MMI_FALSE;
    S32 return_value = FS_NO_ERROR;
    U16 cache_index = 0;
    U8 file_type = 0;
    CHAR* ext_p = NULL;
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    mmi_medply_dynamic_list_data_struct* ui = &(plst_cntx_p->list_ui);
    FS_Pattern_Struct list_file[1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
#ifdef __MMI_KURO_SUPPORT__
    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_DEFAULT_STORAGE, &plst_cntx_p->default_storage);
#endif
    kal_wsprintf(path, "%c:\\", (CHAR)plst_cntx_p->default_storage);
    mmi_ucs2ncat((CHAR*)path, (CHAR*)MMI_MEDPLY_DEFAULT_FOLDER, (MEDPLY_MAX_PATH_LEN - 1));
    mmi_ucs2ncat((CHAR*)path, (CHAR*)L"\\", (MEDPLY_MAX_PATH_LEN - 1));
    mmi_ucs2ncat((CHAR*)path, (CHAR*)L"*.*", (MEDPLY_MAX_PATH_LEN - 1));

    mmi_ucs2ncpy((CHAR*)list_file[0].Pattern, (CHAR*)L"*", 8);
    mmi_ucs2ncat((CHAR*)list_file[0].Pattern, (CHAR*)MMI_MEDPLY_DEFAULT_LIST_EXT, 8);
    file_handle = FS_FindFirstN(
                (PU16)path,
                list_file,
                1,
                0,
                0,
                FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME | FS_ATTR_DIR,
                &file_info,
                (PU16)search_name,
                (MEDPLY_MAX_FILE_LEN) * ENCODING_LENGTH,
                start_index,
                FS_FIND_DEFAULT);
    

    if (file_handle >= FS_NO_ERROR)
    {
        do
        {
            if (!(file_info.Attributes & (FS_ATTR_DIR | FS_ATTR_HIDDEN | FS_ATTR_VOLUME)))
            {
                /* check extend name. filter invalid. */
                ext_p = mmi_ucs2rchr((CHAR*)search_name, (U16)L'.');

                if (ext_p == NULL)
                {
                    file_type = 0;
                }
                else
                {
                    if (!mmi_ucs2nicmp((CHAR*)ext_p, (CHAR*)MMI_MEDPLY_DEFAULT_LIST_EXT, 4))
                    {
                        file_type = MMI_MEDPLY_PLST_MDP;
                    }
                    else
                    {
                        file_type = 0;
                    }
                }
                
                if (file_type)
                {  
                    ext_p = NULL;
                    /* still have entry to fill in the catch */
                    if (cache_index < MMI_MEDPLY_LIST_BUFF_SIZE)
                    {
                        is_short = MMI_FALSE;
                        /* get extend name. */
                        if (FS_SFN_MATCH == file_info.NTReserved)
                        {
                            U8 j = 0;
                            ext[0] = L'.';
                            for (j = 1; j < 4; j++)
                            {
                                ext[j] = (UI_character_type) file_info.Extension[j - 1];
                            }
                            ext[j] = 0;
                            is_short = MMI_TRUE;
                        }
                        else
                        {
                            ext_p = mmi_ucs2rchr((CHAR*)search_name, (U16)L'.');
                            MMI_ASSERT(ext_p != NULL);
                            mmi_ucs2ncpy((CHAR*)ext, (CHAR*)ext_p, (MEDPLY_MAX_EXT_LEN - 1));
                        }
                        /* cut off extend name. */
                        ext_p = mmi_ucs2rchr((CHAR*)search_name, (U16)L'.');
                        MMI_ASSERT(ext_p != NULL);
                        *(ext_p + 1) = 0;
                        *ext_p = 0;
                        
                        /* save cache. */
                        if (cache_index < MMI_MEDPLY_LIST_BUFF_SIZE)
                        {
                            mmi_ucs2ncpy(
                                (CHAR*)ui->cache[cache_index].ext,
                                (CHAR*)ext,
                                (MEDPLY_MAX_EXT_LEN - 1));

                            if (is_short)
                            {
                                mmi_chset_mixed_text_to_ucs2_str(
                                    (U8*)ui->cache[cache_index].filename,
                                    ((MEDPLY_MAX_FILE_LEN - 1)) * ENCODING_LENGTH,
                                    (U8*)search_name,
                                    (mmi_chset_enum)PhnsetGetDefEncodingType());
                            }
                            else
                            {
                                mmi_ucs2ncpy((CHAR*)ui->cache[cache_index].filename, 
                                       (CHAR*)search_name, (MEDPLY_MAX_FILE_LEN - 1));
                            }
                            ui->cache[cache_index].file_type = file_type;
                            ui->cache[cache_index].is_short = is_short;

                            cache_index++;
                        }
                    }
                }
            }

            if (cache_index == MMI_MEDPLY_LIST_BUFF_SIZE)
            {
                *cached_num = cache_index;
                FS_FindClose(file_handle);
                return 0;
            }
            
            return_value = FS_FindNextN(
                                file_handle,
                                list_file,
                                1,
                                FS_ATTR_DIR,
                                &file_info,
                                (PU16)search_name,
                                (MEDPLY_MAX_FILE_LEN) * ENCODING_LENGTH,
                                FS_FIND_DEFAULT);
        } while (return_value == FS_NO_ERROR);

        if (return_value < FS_NO_ERROR && return_value != FS_NO_MORE_FILES)
        {
            mmi_ucs2cpy((CHAR*) ui->cache[cache_index].filename, (CHAR*)GetString(STR_GLOBAL_LOADING));
            cache_index ++;
        }
        FS_FindClose(file_handle);
        *cached_num = cache_index;
		
        if (return_value == FS_NO_MORE_FILES)
        {
            return 0;
        }
        return  return_value;
    }
    else
    {
        if (file_handle != FS_NO_MORE_FILES)
        {
            mmi_ucs2cpy((CHAR*) ui->cache[cache_index].filename, (CHAR*)GetString(STR_GLOBAL_LOADING));
            cache_index = 1;
        }
        *cached_num = cache_index;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LISTMANAGER_LIST_CACHE,file_handle);
        return  file_handle;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_load_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_medply_plst_listmgr_load_cache(U16 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U16 cache_index = 0;
    S32 ret;
    mmi_medply_dynamic_list_data_struct* ui = &(plst_cntx_p->list_ui);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (start_index >= ui->total)
    {
        start_index = ui->total - 1;
    }
    
    /* init some value */
    ui->cache_start_index = start_index;

    for (i = 0; i < MMI_MEDPLY_LIST_BUFF_SIZE; i++)
    {
        ui->cache[i].filename[0] = 0;
        ui->cache[i].ext[0] = 0;
        ui->cache[i].file_type = 0;
        ui->cache[i].is_short = 0;
    }

    ret = mmi_medply_plst_listmgr_load_cache_internal(&cache_index,  ui->cache_start_index);
    ui->cache_start_index = start_index;
    ui->cache_end_index = start_index + cache_index;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_LIST_LOAD_CACHE, cache_index, ui->cache_start_index, ui->cache_end_index);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_get_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static pBOOL mmi_medply_plst_listmgr_get_item(S32 item_idx, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 load_index;
    S32 ret = 0;
    mmi_medply_dynamic_list_data_struct* ui = &(plst_cntx_p->list_ui);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_add_to_mode)
    {
        /* in add to scenario, the first list item will always be "create list"*/
        if (item_idx <= 0)
        {
            *img_buff_p = (PU8) GetImage(IMG_ID_MEDPLY_FILE_PLAYLIST_CREATE_ICON);
            mmi_ucs2ncpy((CHAR*) str_buff, (CHAR*)GetString(STR_ID_MEDPLY_LISTMGR_OPT_NEW),MAX_SUBMENU_CHARACTERS - 1);
            return MMI_TRUE;
        }
        else
        {
            item_idx--;
        }
    }

    if (item_idx >= ui->total)
    {
        str_buff = NULL;
        *img_buff_p = NULL;
        return MMI_TRUE;
    }

    if ((item_idx < ui->cache_start_index) ||
        (item_idx >= ui->cache_end_index))
    {
        /* desired entry in the middle of cache */
        load_index = item_idx - (MMI_MEDPLY_LIST_BUFF_SIZE / 2);

        if (load_index < 0)
        {
            load_index = 0;
        }

        ret = mmi_medply_plst_listmgr_load_cache((U16)load_index);        
    }

    memset(str_buff, 0, sizeof(MAX_SUB_MENU_SIZE));


    if (ret < 0)
    {
        mmi_ucs2ncpy((CHAR*) str_buff, (CHAR*)GetString(STR_GLOBAL_LOADING),MAX_SUBMENU_CHARACTERS - 1);
    }
    else
    {
        MMI_ASSERT((item_idx - ui->cache_start_index) < MMI_MEDPLY_LIST_BUFF_SIZE && (item_idx - ui->cache_start_index) >= 0);
        mmi_ucs2ncpy((CHAR*)str_buff, (CHAR*)ui->cache[item_idx - ui->cache_start_index].filename, MAX_SUBMENU_CHARACTERS - 1);
        str_buff[mmi_ucs2strlen((CHAR*)str_buff)] = 0;
    }
    *img_buff_p = (PU8) GetImage(IMG_ID_MEDPLY_FILE_PLAYLIST_ICON);

    return MMI_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_option_config
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_listmgr_option_config(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_dynamic_list_data_struct* ui = &(plst_cntx_p->list_ui);
    
    /* always hide all optional items. */
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_LISTMGR_OPTION_LOAD, MMI_TRUE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_LISTMGR_OPTION_DELETE, MMI_TRUE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_LISTMGR_OPTION_DELETEALL, MMI_TRUE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_LISTMGR_OPTION_RENAME, MMI_TRUE);
    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_LISTMGR_OPTION_SETTINGS, MMI_TRUE);
    
    if (ui->total > 0)
    {
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_LISTMGR_OPTION_LOAD, MMI_FALSE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_LISTMGR_OPTION_DELETE, MMI_FALSE);
        cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_LISTMGR_OPTION_RENAME, MMI_FALSE);
    
        if (ui->total > 1)
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MEDPLY_LISTMGR_OPTION_DELETEALL, MMI_FALSE);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_entry_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_listmgr_entry_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_KURO_SUPPORT__
    S32 result;
#endif
    MMI_ID cui_gid = GRP_ID_INVALID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0   
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    mmi_frm_group_create(GRP_ID_MEDPLY_LIST_MGR, GRP_ID_MEDPLY_LIST_MGR_OPT, mmi_medply_plst_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_LIST_MGR_OPT, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_gid = cui_menu_create( GRP_ID_MEDPLY_LIST_MGR_OPT,
                                CUI_MENU_SRC_TYPE_RESOURCE,
                                CUI_MENU_TYPE_OPTION,
                                MENU_ID_MEDPLY_LISTMGR_OPTION_MENU,
                                MMI_FALSE, NULL);
    if (cui_gid > GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)));
        cui_menu_run(cui_gid);
    }
    else
    {   
        mmi_medply_plst_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),MMI_EVENT_FAILURE);
    }

}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_get_filename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_medply_plst_listmgr_get_filename(UI_string_type filename, S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_dynamic_list_item_info_struct item_info;
    S32 load_index;
    S32 current = 0;
    mmi_medply_dynamic_list_data_struct* list_ui = &(plst_cntx_p->list_ui);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item_index >= list_ui->total || item_index < 0)
    {
        return MMI_FALSE;
    }

    if ((item_index < list_ui->cache_start_index) ||
        (item_index >= list_ui->cache_end_index))
    {
        /* desired entry in the middle of cache */
        load_index = item_index - (MMI_MEDPLY_LIST_BUFF_SIZE / 2);

        if (load_index < 0)
        {
            load_index = 0;
        }

        mmi_medply_plst_listmgr_load_cache((U16)load_index); 
    }
    current = item_index - list_ui->cache_start_index;
    MMI_ASSERT(current < MMI_MEDPLY_LIST_BUFF_SIZE && current >= 0);
    memcpy(&item_info, &(list_ui->cache[current]), 
            sizeof(mmi_medply_dynamic_list_item_info_struct));
    
    mmi_ucs2ncpy((CHAR*)filename, (CHAR*)item_info.filename, (MEDPLY_MAX_FILE_LEN - 1));
  
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_get_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_listmgr_get_path(UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = (U16)plst_cntx_p->list_ui.highlight;
    S32 load_index = 0;
    U16 cache_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_LISTMGR_GET_PATH, index, __LINE__);
    //MAUI_02597091
#ifdef __MMI_KURO_SUPPORT__
    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_DEFAULT_STORAGE, &plst_cntx_p->default_storage);
#endif
    if (browser_all_audio && !in_add_to_mode)
    {
        kal_wsprintf(
            path, 
            "%c:\\%w\\%w%w",
            plst_cntx_p->default_storage, 
            MMI_MEDPLY_DEFAULT_FOLDER,
            MMI_MEDPLY_ALL_AUDIO_LIST,
            MMI_MEDPLY_DEFAULT_LIST_EXT);
    }
    else if (browser_all_video && !in_add_to_mode)
    {
        kal_wsprintf(
            path, 
            "%c:\\%w\\%w%w",
            plst_cntx_p->default_storage, 
            MMI_MEDPLY_DEFAULT_FOLDER,
            MMI_MEDPLY_ALL_VIDEO_LIST,
            MMI_MEDPLY_DEFAULT_LIST_EXT);
    }
    else
    {
        if (in_add_to_mode)
        {
            if (index > 0)
            {
                index--;
            }
            else
            {
                index = 0;
            }
        }
        
        if (index < plst_cntx_p->list_ui.cache_start_index ||
            index >= plst_cntx_p->list_ui.cache_end_index)
        {
            /* desired entry in the middle of cache */
            load_index = index - (MMI_MEDPLY_LIST_BUFF_SIZE / 2);
    
            if (load_index < 0)
            {
                load_index = 0;
            }
    
            mmi_medply_plst_listmgr_load_cache((U16)load_index); 
        }
        cache_index = (U16)(index - plst_cntx_p->list_ui.cache_start_index);
        kal_wsprintf(path, "%c:\\", (CHAR)plst_cntx_p->default_storage);
        mmi_ucs2ncat((CHAR*)path, (CHAR*)MMI_MEDPLY_DEFAULT_FOLDER, (MEDPLY_MAX_PATH_LEN - 1));
        mmi_ucs2ncat((CHAR*)path, (CHAR*)"\\", (MEDPLY_MAX_PATH_LEN - 1));
        mmi_ucs2ncat((CHAR*)path, (CHAR*)plst_cntx_p->list_ui.cache[cache_index].filename, (MEDPLY_MAX_PATH_LEN - 1));
        mmi_ucs2ncat((CHAR*)path, (CHAR*)plst_cntx_p->list_ui.cache[cache_index].ext, (MEDPLY_MAX_PATH_LEN - 1));
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medlpy_plst_listmgr_fmgr_storage_select_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  driver_letter		[IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medlpy_plst_listmgr_fmgr_storage_select_hdlr(cui_storage_selector_result_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error = 0;
    U8 storage = SRV_FMGR_PUBLIC_DRV;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->result > 0) /* user selects a storage */
    {
        if (evt->result != plst_cntx_p->default_storage)
        {
            storage = (U8)evt->result;
        #ifdef __MMI_KURO_SUPPORT__
            mmi_medply_settings_write_value(MMI_MEDPLY_SETTINGS_DEFAULT_STORAGE, &(storage));
        #else
            plst_cntx_p->default_storage = storage;
            WriteValue(NVRAM_MEDPLY_PREFER_LIST, &(plst_cntx_p->default_storage), DS_BYTE, &error);
        #endif
            mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_MGR);
        }
        /* enter storage check point again */
        if (storage_change_entry)
        {
            storage_change_entry();
            storage_change_entry = NULL;
        }
/*bql: apply new UE design to avoid success popup */
#if 1
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
#else
/* under construction !*/
#endif
        /* close File Manger CUI */
        cui_storage_selector_close(evt->sender_id);
    }
    else /* user cancels or error happens */
    {
        /* close File Manger CUI */
        cui_storage_selector_close(evt->sender_id);
        storage_change_entry = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_select_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_listmgr_select_storage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_MEDPLY_LIST_MGR))
    {
        mmi_frm_group_create(GRP_ID_MEDPLY_LIST_MGR, GRP_ID_MEDPLY_LIST_SELECT_STORAGE, mmi_medply_plst_proc, (void*)NULL); 
    }
    else
    {
        mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_LIST_SELECT_STORAGE, mmi_medply_plst_proc, (void*)NULL); 
    }
    mmi_frm_group_enter(GRP_ID_MEDPLY_LIST_SELECT_STORAGE, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_gid = cui_storage_selector_create(GRP_ID_MEDPLY_LIST_SELECT_STORAGE, plst_cntx_p->default_storage, CUI_STORAGE_SELECTOR_DRV_TYPE_ACCESIBLE);

    if (cui_gid > GRP_ID_INVALID)
    {
        cui_storage_selector_set_title(cui_gid, 0, GetRootTitleIcon(MENU_ID_MEDPLY_MAIN));
        cui_storage_selector_run(cui_gid);
    }
    else
    {   
        mmi_medply_plst_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),MMI_EVENT_FAILURE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_listmgr_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_settings_entry_main();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_delete_part2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_listmgr_delete_part2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    S32 ret = 0;
    S32 fs_ret = FS_NO_ERROR;
    MMI_BOOL delete_now_playing = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_DELTETE_LIST_BEGIN);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_LISTMGR_DELETE, plst_cntx_p->list_loaded, plst_cntx_p->current_list.fs_hdlr, plst_cntx_p->browser_list_p, browser_now_playing, __LINE__);
    /* count the current index in cache. */
    mmi_medply_plst_listmgr_get_path(path);

    if (plst_cntx_p->list_loaded)
    {
        if (!mmi_ucs2icmp((CHAR*)plst_cntx_p->current_list.path, (CHAR*)path))
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_DELTETE_NOW_PLAYING);
            delete_now_playing = MMI_TRUE;
        }
    }

    if (delete_now_playing)
    {
        /*need set media type to NONE, to avoid states not change to IDLE.*/
        g_medply.media_type = MEDPLY_TYPE_NONE;
        mmi_medply_stop_playing();
        FS_Commit(plst_cntx_p->current_list.fs_hdlr);
        fs_ret = FS_Close(plst_cntx_p->current_list.fs_hdlr);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->current_list.fs_hdlr ,__LINE__);
        plst_cntx_p->current_list.fs_hdlr = FS_ERROR_RESERVED;

        if (fs_ret < FS_NO_ERROR)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_DELTETE_ERROR_CODE, fs_ret);
            mmi_medply_plst_popup_simple_with_string(get_string(srv_fmgr_fs_error_get_string(fs_ret)), (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(fs_ret));
            return;
        }
    }

    ret = FS_Delete((PU16)path);
    /* error handling. */
    if (ret < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_DELTETE_ERROR_CODE, ret);
        if (delete_now_playing)
        {
            /* try to reopen. */
            S32 hdlr = FS_NO_ERROR;

            hdlr = FS_Open(plst_cntx_p->current_list.path, FS_READ_WRITE);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_OPEN,hdlr ,__LINE__);
            if (hdlr < 0)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_DELTETE_ERROR_CODE, hdlr);
                /* clear list data and player variables. */
                plst_cntx_p->list_loaded = MMI_FALSE;
                memset(&(plst_cntx_p->current_list), 0, sizeof(mmi_medply_plst_struct));

                mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_MGR);
            }
            else
            {
                plst_cntx_p->current_list.fs_hdlr = hdlr;
            }
        }
        
        mmi_medply_plst_popup_simple_with_string(get_string(srv_fmgr_fs_error_get_string(fs_ret)), (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(fs_ret));
    }
    else
    {
        /* no error, popup successful. */
        if (delete_now_playing)
        {
            plst_cntx_p->list_loaded = MMI_FALSE;
            memset(&(plst_cntx_p->current_list), 0, sizeof(mmi_medply_plst_struct));
            mmi_medply_plst_clear_context_variables();
        }
	/* removed for new UE */
#if 0
/* under construction !*/
#endif
        mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_MGR);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_delete_part1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_listmgr_delete_part1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 str[MEDPLY_MAX_ERROR_STRING_LEN];
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    CHAR* filename = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_DELETE_LISTMAG_PRE_BEGIN);
    mmi_medply_plst_listmgr_get_path(path);

    memset(str, 0, sizeof(str));

    mmi_ucs2ncpy((CHAR*)str, (CHAR*) get_string(STR_GLOBAL_DELETE), MEDPLY_MAX_ERROR_STRING_LEN);
    /* ? will be shown by popup not application */
    //mmi_ucs2ncat((CHAR*)str, (CHAR*)GetString(STR_ID_FMGR_QUESTION_MARK), MEDPLY_MAX_ERROR_STRING_LEN);
    mmi_ucs2ncat((CHAR*)str, (CHAR*) L"\n", MEDPLY_MAX_ERROR_STRING_LEN);
    
    filename = mmi_ucs2rchr((CHAR*)path, (U16)L'\\');
    
    if (filename == NULL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_DELETE_LISTMAG_NAME_EMPRY);
        return;
    }
    filename += 2;

    mmi_ucs2ncat((CHAR*)str, (CHAR*)filename, MEDPLY_MAX_ERROR_STRING_LEN);
#if !defined(__MMI_MEDPLY_M3U_SUPPORT__)
{
    CHAR* ext = mmi_ucs2rchr((CHAR*)str, (U16)L'.');
    
    if (ext == NULL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_DELETE_LISTMAG_EXT_NAME_EMPRY);
        return;
    }
    *(ext + 1) = 0;
    *ext = 0;
}
#endif

    mmi_medply_plst_confirm_simple(GRP_ID_MEDPLY_LIST_MGR,
        (WCHAR *)str,
        mmi_medply_plst_listmgr_delete_part2,
        CNFM_TYPE_YESNO,
        MMI_TRUE,
        MMI_EVENT_QUERY);     

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_delete_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_listmgr_delete_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    plst_cntx_p->list_ui.cancel_deleteall = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_delete_wait_entry_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_listmgr_delete_wait_entry_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    MMI_BOOL entry_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_DELETE_WAIT_SCREEN, NULL, mmi_medply_plst_listmgr_delete_wait_entry_scr, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }    
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_DELETE_WAIT_SCREEN);

    ShowCategory66Screen(
        STR_ID_MEDPLY_APP_TITLE,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        (PU8)GetString(STR_GLOBAL_DELETING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        guiBuffer);	
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS); 
    SetRightSoftkeyFunction( mmi_medply_plst_listmgr_delete_cancel, KEY_EVENT_UP);
    SetKeyHandler(mmi_medply_plst_listmgr_delete_cancel, KEY_END, KEY_EVENT_DOWN); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_delete_all_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_listmgr_delete_all_rsp_hdlr(srv_fmgr_async_done_event_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_async_done_event_struct   *msg = info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_medply_plst_is_scrn_present(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_MGR))/* cut buy other app interrupt  */
    {
        mmi_frm_scrn_close(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_DELETE_WAIT_SCREEN);
        srv_backlight_turn_off();
        mdi_audio_resume_background_play();
        return;
    }

    /* add delete list count check*/
    if (msg->result == FS_NO_ERROR)
    {
        if(plst_cntx_p->list_ui.total > 0)
        {
            plst_cntx_p->list_ui.total--;
  
            if (!plst_cntx_p->list_ui.cancel_deleteall)
            {
                S32 fs_ret = FS_NO_ERROR;
                UI_character_type path[MEDPLY_MAX_PATH_LEN];
                UI_character_type search_name[MEDPLY_MAX_FILE_LEN];
                FS_DOSDirEntry file_info;
                FS_Pattern_Struct list_file[1];  

               /* find next playlist to delete all */
                kal_wsprintf((kal_wchar*)path, "%c:\\", (CHAR)plst_cntx_p->default_storage);
                mmi_ucs2cat((CHAR*)path, (CHAR*)MMI_MEDPLY_DEFAULT_FOLDER);
				mmi_ucs2cat((CHAR*) path, (CHAR*) L"\\*.*");

                mmi_ucs2ncpy((CHAR*)list_file[0].Pattern, (CHAR*)L"*", 8);
                mmi_ucs2ncat((CHAR*)list_file[0].Pattern, (CHAR*)MMI_MEDPLY_DEFAULT_LIST_EXT, 8);
                
                fs_ret = FS_FindFirstN(
                        (PU16)path,
                        list_file,
                        1,
                        FS_ATTR_DIR,
                        0,
                        FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                        &file_info,
                        (PU16)search_name,
                        (MEDPLY_MAX_FILE_LEN) * ENCODING_LENGTH,
                        plst_cntx_p->list_ui.total - 1,
                        FS_FIND_DEFAULT);
                
                if (fs_ret >= FS_NO_ERROR)
                {
                    CHAR* ext_p;
                     
                    FS_FindClose(fs_ret);                    
                    ext_p = mmi_ucs2rchr((CHAR*)path, (U16)'\\');
                    if (ext_p == NULL)
                    {
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
                        return;
                    }
                    else
                    {
                        *(ext_p + 1) = 0;
                        *(ext_p) = 0;
                    }
                    mmi_ucs2cat((CHAR*) path, (CHAR*) L"\\");
                    mmi_ucs2cat((CHAR*)path, (CHAR*)search_name);
                    srv_fmgr_async_delete((WCHAR *) path, 0, mmi_medply_plst_proc, NULL);
                    return; 
                }
                else if (fs_ret != FS_NO_MORE_FILES)
                {
                    srv_backlight_turn_off();
                    mdi_audio_resume_background_play();
                    mmi_medply_plst_popup_simple(fs_ret); 
                    mmi_frm_scrn_close(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_DELETE_WAIT_SCREEN);
                    return ;
                }
            }
            else
            {
                mmi_medply_plst_popup_simple_with_string(get_string(STR_ID_MEDPLY_PLST_CANCELED), MMI_EVENT_SUCCESS);
                plst_cntx_p->list_ui.cancel_deleteall = MMI_FALSE;
                srv_backlight_turn_off();
                mdi_audio_resume_background_play();
                mmi_frm_scrn_close(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_DELETE_WAIT_SCREEN);
                return ;                
            }
        } 
    }

    srv_backlight_turn_off();
    mdi_audio_resume_background_play();
    if (msg->result >= FS_NO_ERROR) /* currently all deleted */
    {
        /* success */
	/* removed for new UE */
#if 0
/* under construction !*/
#endif
    }
    else
    {
        mmi_medply_plst_popup_simple(msg->result);
    }
    /* operation done, close waiting screen */
    mmi_frm_scrn_close(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_DELETE_WAIT_SCREEN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_deleteall_part2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_listmgr_deleteall_part2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret = FS_NO_ERROR;
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    UI_character_type search_name[MEDPLY_MAX_FILE_LEN];
    FS_DOSDirEntry file_info;
    FS_Pattern_Struct list_file[1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_LISTMGR_DELETE_ALL, plst_cntx_p->list_loaded, plst_cntx_p->current_list.fs_hdlr, plst_cntx_p->browser_list_p, browser_now_playing, __LINE__);
#ifdef __MMI_KURO_SUPPORT__
    KURO_DownloadCommand(0, DOWNLOAD_STOP_ALL);    
#endif
    //MAUI_02628471
    if (plst_cntx_p->list_loaded && 
        plst_cntx_p->default_storage == mmi_medply_plst_get_now_playing_list_drv() 
#if defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__)
        &&!mmi_medply_plst_is_all_tracks_playing()
#endif /* __MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__ */
        )
    {
        plst_cntx_p->list_loaded  = MMI_FALSE; 

        FS_Commit(plst_cntx_p->current_list.fs_hdlr);
        fs_ret = FS_Close(plst_cntx_p->current_list.fs_hdlr);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->current_list.fs_hdlr ,__LINE__);
        memset(&(plst_cntx_p->current_list), 0, sizeof(mmi_medply_plst_struct));
        /*need set media type to NONE, to avoid states not change to IDLE.*/
        g_medply.media_type = MEDPLY_TYPE_NONE;     
        mmi_medply_stop_playing();
        
        /* clear player data. for play failed case. */
        mmi_medply_clear_play_seconds();
        mmi_medply_plst_clear_context_variables();
        
        if (fs_ret < FS_NO_ERROR)
        {
            mmi_medply_plst_popup_simple_with_string(get_string(STR_GLOBAL_DELETED), MMI_EVENT_SUCCESS);
            return;
        }
    }
    kal_wsprintf((kal_wchar*)path, "%c:\\", (CHAR)plst_cntx_p->default_storage);
    mmi_ucs2cat((CHAR*)path, (CHAR*)MMI_MEDPLY_DEFAULT_FOLDER);
    mmi_ucs2cat((CHAR*) path, (CHAR*) L"\\*.*");

    mdi_audio_suspend_background_play();
    mmi_ucs2ncpy((CHAR*)list_file[0].Pattern, (CHAR*)L"*", 8);
    mmi_ucs2ncat((CHAR*)list_file[0].Pattern, (CHAR*)MMI_MEDPLY_DEFAULT_LIST_EXT, 8);
    
    fs_ret = FS_FindFirstN(
            (PU16)path,
            list_file,
            1,
            FS_ATTR_DIR,
            0,
            FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
            &file_info,
            (PU16)search_name,
            (MEDPLY_MAX_FILE_LEN) * ENCODING_LENGTH,
            plst_cntx_p->list_ui.total - 1,
            FS_FIND_DEFAULT);
    
    if (fs_ret >= FS_NO_ERROR)
    {
        CHAR* ext_p;
        ext_p = mmi_ucs2rchr((CHAR*)path, (U16)'\\');
        if (ext_p == NULL)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
            return;
        }
        else
        {
            *(ext_p + 1) = 0;
            *(ext_p) = 0;
        }
        mmi_ucs2cat((CHAR*) path, (CHAR*) L"\\");
        mmi_ucs2cat((CHAR*) path, (CHAR*) L"\\");
        mmi_ucs2cat((CHAR*)path, (CHAR*)search_name);
        FS_FindClose(fs_ret);
    }
    else
    {
        mmi_medply_plst_popup_simple(fs_ret);  
        mmi_frm_scrn_close(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_DELETE_WAIT_SCREEN);
    }
    
    /* count playlist count and delete one bye one */
    srv_fmgr_async_delete((WCHAR *) path, 0, mmi_medply_plst_proc, NULL);
    ClearInputEventHandler(MMI_DEVICE_ALL);
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
    mmi_medply_plst_listmgr_delete_wait_entry_scr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_deleteall_part1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_listmgr_deleteall_part1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type str[MEDPLY_MAX_PATH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR*) str, (CHAR*) GetString(STR_GLOBAL_DELETE_ALL));
    /* ? will be shown by popup not application */
    //mmi_ucs2cat((CHAR*) str, (CHAR*) GetString(STR_ID_FMGR_QUESTION_MARK));

    mmi_medply_plst_confirm_simple(GRP_ID_MEDPLY_LIST_MGR,
        (WCHAR *)str,
        mmi_medply_plst_listmgr_deleteall_part2,
        CNFM_TYPE_YESNO,
        MMI_TRUE,
        MMI_EVENT_QUERY);     

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_rename_part3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL mmi_medply_plst_listmgr_rename_part3(U8 action, S32 result, mmi_id editor_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 error_str;
    MMI_BOOL close_editor;
    UI_character_type new_path[MEDPLY_MAX_PATH_LEN];
    UI_character_type old_path[MEDPLY_MAX_PATH_LEN];
    UI_character_type filename_without_ext[MEDPLY_MAX_PATH_LEN];
    S32 fs_ret;
    MMI_BOOL rename_now_playing = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2ncpy((CHAR*)filename_without_ext, (CHAR*)plst_cntx_p->editor.editor_buffer, MEDPLY_MAX_INPUT_FILE_LEN - 1);
    mmi_medply_plst_listmgr_get_path(old_path);
    if (plst_cntx_p->list_loaded)
    {
        if (!mmi_ucs2icmp((CHAR*)plst_cntx_p->current_list.path, (CHAR*)old_path))
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_RENAME_NOW_PLAYING_PLST);
            rename_now_playing = MMI_TRUE;
        }
    }
    do {
        error_str = 0;
        close_editor = MMI_FALSE;

        /* if file exist due to name not changed, it is success */
        if (result == FS_FILE_EXISTS)
        {
        /* Check the original name */
        cui_filename_editor_get_fullpath(editor_id, (WCHAR*)new_path, MEDPLY_MAX_PATH_SIZE);
        if (!mmi_wcscmp((WCHAR*)new_path, (WCHAR*)old_path))
        {
            close_editor = MMI_TRUE;
            break;
        }
        }
        else if (result < 0)
        {
            error_str = srv_fmgr_fs_error_get_string(result);
            break;
        }
        else
        {
            cui_filename_editor_get_fullpath(editor_id, (WCHAR*)new_path, MEDPLY_MAX_PATH_SIZE);
        }

        if (rename_now_playing)
        {
            S32 ret = FS_NO_ERROR;
            
            FS_Commit(plst_cntx_p->current_list.fs_hdlr);
            ret = FS_Close(plst_cntx_p->current_list.fs_hdlr);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->current_list.fs_hdlr ,__LINE__);
            plst_cntx_p->current_list.fs_hdlr = FS_ERROR_RESERVED;
        
            if (ret < FS_NO_ERROR)
            {
                error_str = srv_fmgr_fs_error_get_string(ret);
                break;
            }
        }
        /* Rename */
        fs_ret = srv_fmgr_fs_rename((WCHAR *)old_path, (WCHAR *)new_path);

        if (fs_ret == 0)
        {
            /* success */
            if (rename_now_playing)
            {
                S32 ret = FS_NO_ERROR;
                ret = FS_Open(new_path, FS_READ_WRITE);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_OPEN,ret ,__LINE__);
                //MMI_ASSERT(!(ret < FS_NO_ERROR));
                if(ret < FS_NO_ERROR)
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_RENAME_PLST_ERROR, ret);
                    /* clear list data and player variables. */
                    plst_cntx_p->list_loaded = MMI_FALSE;
                    memset(&(plst_cntx_p->current_list), 0, sizeof(mmi_medply_plst_struct));
                    mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_MGR);
                    error_str = srv_fmgr_fs_error_get_string(fs_ret);
                    close_editor = MMI_TRUE;
                    break;
                }
                mmi_ucs2ncpy((CHAR*)plst_cntx_p->current_list.path, (CHAR*)new_path, (MEDPLY_MAX_PATH_LEN - 1));
                plst_cntx_p->current_list.fs_hdlr = ret;
        
                /* update title. */
                mmi_ucs2ncpy((CHAR*)plst_cntx_p->current_list.title, 
                        (CHAR*)filename_without_ext, MEDPLY_MAX_INPUT_FILE_LEN - 1);
                mmi_medply_plst_save_last_path(plst_cntx_p->current_list.path);
            }
            close_editor = MMI_TRUE;
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_RENAME_PLST_ERROR, fs_ret);
            if (rename_now_playing)
            {
                S32 ret = FS_NO_ERROR;
                ret = FS_Open(plst_cntx_p->current_list.path, FS_READ_WRITE);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_OPEN,ret ,__LINE__);
                if (ret < FS_NO_ERROR)
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_RENAME_PLST_ERROR, ret);
                    /* clear list data and player variables. */
                    plst_cntx_p->list_loaded = MMI_FALSE;
                    memset(&(plst_cntx_p->current_list), 0, sizeof(mmi_medply_plst_struct));
                    mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_MGR);
                }
                else
                {
                    plst_cntx_p->current_list.fs_hdlr = ret;
                }
            }
            /* Fail */
            error_str = srv_fmgr_fs_error_get_string(fs_ret);

            if (fs_ret == FS_ACCESS_DENIED)
            {
                /* Input any name doesn't help, quit editor */
                close_editor = MMI_TRUE;
            }
            break;
        }
    } while(0);

    if (error_str)
    {
        mmi_medply_plst_popup_simple_with_string((WCHAR*)get_string(error_str), MMI_EVENT_FAILURE);
    }

    return close_editor;

}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_rename_part2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_listmgr_rename_part2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret = FS_NO_ERROR;
    CHAR* filename = NULL;
    CHAR* ptr = NULL;
    MMI_BOOL rename_now_playing = MMI_FALSE;
    S32 error_string_id = 0;
    U16 *error_string_p = NULL;
    S32 error_event = 0;
    UI_string_type filename_without_ext = (UI_string_type)applib_mem_screen_alloc_framebuffer(MEDPLY_MAX_INPUT_FILE_LEN*2); 
    UI_string_type old_path = (UI_string_type)applib_mem_screen_alloc_framebuffer(MEDPLY_MAX_PATH_LEN*2);
    UI_string_type new_path = (UI_string_type)applib_mem_screen_alloc_framebuffer(MEDPLY_MAX_PATH_LEN*2); 
    UI_string_type temp_path = (UI_string_type)applib_mem_screen_alloc_framebuffer(MEDPLY_MAX_PATH_LEN*2); 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_RENAME_PLST);
    MMI_ASSERT(filename_without_ext && old_path && new_path && temp_path);

    do{
        mmi_ucs2ncpy((CHAR*)filename_without_ext, (CHAR*)plst_cntx_p->editor.editor_buffer, MEDPLY_MAX_INPUT_FILE_LEN - 1);
        mmi_medply_plst_listmgr_get_path(old_path);
        
        if (plst_cntx_p->list_loaded)
        {
            if (!mmi_ucs2icmp((CHAR*)plst_cntx_p->current_list.path, (CHAR*)old_path))
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_RENAME_NOW_PLAYING_PLST);
                rename_now_playing = MMI_TRUE;
            }
        }
        
        mmi_ucs2ncpy((CHAR*)new_path, (CHAR*)old_path, (MEDPLY_MAX_PATH_LEN - 1));
        
        filename = mmi_ucs2rchr((CHAR*)new_path, (U16)'\\');
        
        if (filename == NULL)
        {
            break;
        }
        filename += 2;
        
        mmi_ucs2ncpy((CHAR*)filename, (CHAR*)filename_without_ext, (MEDPLY_MAX_PATH_LEN - 1));
        mmi_ucs2ncat((CHAR*)filename, (CHAR*)MMI_MEDPLY_DEFAULT_LIST_EXT, (MEDPLY_MAX_PATH_LEN - 1));
        /* check file whether is exist. */
        
        if (mmi_ucs2nicmp((CHAR*)new_path, (CHAR*)old_path, (MEDPLY_MAX_PATH_LEN)))
        {   /*not the same file name*/
            if (FS_GetAttributes(new_path) >= 0)
            {   
                if (mmi_ucs2nicmp((CHAR*)new_path, (CHAR*)old_path, (MEDPLY_MAX_PATH_LEN - 1)))
                {
                    error_string_id = MEDPLY_PLST_ERR_FILE_EXISTS;
                    break;
                }
            }
        }
        else
        {   /*the same file name, maybe F/f*/
            if (!mmi_ucs2ncmp((CHAR*)new_path, (CHAR*)old_path, (MEDPLY_MAX_PATH_LEN - 1)))
            {   /*the same file F=F*/
                break;
            }
        }
        
        if (rename_now_playing)
        {
            S32 ret = FS_NO_ERROR;
            
            FS_Commit(plst_cntx_p->current_list.fs_hdlr);
            ret = FS_Close(plst_cntx_p->current_list.fs_hdlr);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->current_list.fs_hdlr ,__LINE__);
            plst_cntx_p->current_list.fs_hdlr = FS_ERROR_RESERVED;
        
            if (ret < FS_NO_ERROR)
            {
                error_string_p = (U16*)get_string(srv_fmgr_fs_error_get_string(ret));
                error_event = srv_fmgr_fs_error_get_popup_type(fs_ret);
                break;
            }
        }
        /* rename. */
        mmi_ucs2ncpy((CHAR*)temp_path, (CHAR*)old_path, MEDPLY_MAX_PATH_LEN);
        ptr = (CHAR*)&temp_path[0];
        *(ptr + mmi_ucs2strlen((CHAR *)old_path)*2 - 1) = 0;
        *(ptr + mmi_ucs2strlen((CHAR *)old_path)*2 - 2) = 0;
        fs_ret = FS_Rename(old_path, temp_path);
        if (fs_ret >= FS_NO_ERROR)
        {
            fs_ret = FS_Rename(temp_path, new_path);
        }
        if (fs_ret < FS_NO_ERROR)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_RENAME_PLST_ERROR, fs_ret);
            if (rename_now_playing)
            {
                S32 ret = FS_NO_ERROR;
                ret = FS_Open(plst_cntx_p->current_list.path, FS_READ_WRITE);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_OPEN,ret ,__LINE__);
                if (ret < FS_NO_ERROR)
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_RENAME_PLST_ERROR, ret);
                    /* clear list data and player variables. */
                    plst_cntx_p->list_loaded = MMI_FALSE;
                    memset(&(plst_cntx_p->current_list), 0, sizeof(mmi_medply_plst_struct));
                    mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_MGR);
                }
                else
                {
                    plst_cntx_p->current_list.fs_hdlr = ret;
                }
            }
            error_string_p = (U16*)get_string(srv_fmgr_fs_error_get_string(fs_ret));
            error_event = srv_fmgr_fs_error_get_popup_type(fs_ret);
            break;
        }
        else
        {
            if (rename_now_playing)
            {
                S32 ret = FS_NO_ERROR;
                mmi_ucs2ncpy((CHAR*)plst_cntx_p->current_list.path, (CHAR*)new_path, (MEDPLY_MAX_PATH_LEN - 1));
                ret = FS_Open(new_path, FS_READ_WRITE);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_OPEN,ret ,__LINE__);
                MMI_ASSERT(!(ret < FS_NO_ERROR));
                
                plst_cntx_p->current_list.fs_hdlr = ret;
        
                /* update title. */
                mmi_ucs2ncpy((CHAR*)plst_cntx_p->current_list.title, 
                        (CHAR*)filename_without_ext, MEDPLY_MAX_INPUT_FILE_LEN - 1);
                mmi_medply_plst_save_last_path(plst_cntx_p->current_list.path);
            }
        }
    }while(0);
    applib_mem_screen_free(filename_without_ext);
    applib_mem_screen_free(old_path);
    applib_mem_screen_free(new_path);
    applib_mem_screen_free(temp_path);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE,filename_without_ext, __LINE__);
    if (error_string_id)
    {
        mmi_medply_plst_popup_simple(error_string_id);
    }
    else if (error_string_p)
    {
        mmi_medply_plst_popup_simple_with_string(error_string_p, (mmi_event_notify_enum)error_event);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_rename_part1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_listmgr_rename_part1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type filename[MEDPLY_MAX_FILE_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_medply_plst_listmgr_get_filename(filename, plst_cntx_p->list_ui.highlight))
    {
        plst_cntx_p->editor.editor_type = MMI_MEDPLY_EDITOR_RENAME;
        plst_cntx_p->editor.editor_buffer[0] = 0;
        plst_cntx_p->editor.editor_title_id = STR_GLOBAL_RENAME;
        plst_cntx_p->editor.done_func = mmi_medply_plst_listmgr_rename_part2;
        plst_cntx_p->editor.limit = MEDPLY_MAX_INPUT_FILE_LEN;
        plst_cntx_p->editor.parent_id = GRP_ID_MEDPLY_LIST_MGR;
        mmi_ucs2ncpy((CHAR*)plst_cntx_p->editor.editor_buffer, (CHAR*)filename, MMI_MEDPLY_MAX_EDITOR_LEN);
        mmi_medply_entry_editor();
        return;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_header_integrality_check
 * DESCRIPTION
 *  check header's integrality
 * PARAMETERS
 *  this        [IN]
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_plst_header_integrality_check(mmi_medply_plst_struct* this)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __INTEGRALITY_FULL_FILE__
    U32 read_size = 0;   
    mmi_medply_plst_block_node_struct block;
    U8 j = 0;
    U32 current_block_offset = 0;
#endif /* __INTEGRALITY_FULL_FILE__ */    
    U16 i = 0;
    S32 ret = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(this->fs_hdlr >= FS_NO_ERROR);

    for (i = 0; i < this->total; i++)
    {
        if (this->header.index[i].used_block > MMI_MEDPLY_MAX_BLOCK_NUM)
        {
            ret = MEDPLY_PLST_ERR_LIST_DAMAGED;
            break;
        }
    #ifdef __INTEGRALITY_FULL_FILE__    
        else
        {
            current_block_offset = this->header.index[i].offset;
            for (j = 0; j < this->header.index[i].used_block; j++)
            {
                ret = FS_Seek(this->fs_hdlr, current_block_offset, FS_FILE_BEGIN);
                if (ret < FS_NO_ERROR)
                {
                    break;
                }
                ret = FS_Read(this->fs_hdlr, &block, sizeof(mmi_medply_plst_block_node_struct), &read_size);

                if (ret < FS_NO_ERROR)
                {
                    break;
                }
                else if (read_size != sizeof(mmi_medply_plst_block_node_struct))
                {
                    ret = MEDPLY_PLST_ERR_READ_FAILED;
                    break;
                }
                else if (block.pattern_begin != MEDPLY_PLAYLIST_BLOCK_PATTERN_1 ||
                        block.pattern_end != MEDPLY_PLAYLIST_BLOCK_PATTERN_2)
                {
                    ret = MEDPLY_PLST_ERR_LIST_DAMAGED;
                    break;
                }
                if (block.next_ptr == NULL)
                {
                    break;
                }
                else
                {
                    current_block_offset = block.next_ptr;
                }
            }
        }
    #endif  /*__INTEGRALITY_FULL_FILE__*/    
    }

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_list_open_playlist
 * DESCRIPTION
 *  open a list file. 
 * PARAMETERS
 *  file_path
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_plst_open_internal(UI_string_type file_path, mmi_medply_plst_struct* this)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = FS_NO_ERROR;
    U32 read_size = 0;
    U32 empty_size = 0;
    CHAR* filename = NULL;
    CHAR* dot = NULL;
    U32 file_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* open playlist file. */
    mmi_ucs2ncpy((CHAR*)this->path, (CHAR*)file_path, (MEDPLY_MAX_PATH_LEN - 1));

    do
    {
        ret = FS_Open(this->path, FS_READ_WRITE);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_OPEN,ret ,__LINE__);
        if (ret < FS_NO_ERROR)
        {
            break;
        }
        filename = mmi_ucs2rchr((CHAR*)file_path, (U16)L'\\');
        if (filename == NULL)
        {
            ret = MEDPLY_PLST_ERR_INVALID_PARA;
            break;
        }
        filename += 2;
        mmi_ucs2ncpy((CHAR*)this->title, (CHAR*)filename, (MEDPLY_MAX_FILE_LEN - 1));

        dot = mmi_ucs2rchr((CHAR*)this->title, (U16)L'.');
        if (dot == NULL)
        {
            ret = MEDPLY_PLST_ERR_INVALID_PARA;
            break;
        }
        *(dot + 1) = 0;
        *dot = 0;
        
        /* set variables. */
        this->fs_hdlr = ret;
        this->pick_index = 0;
        this->pick_count = 0;
        this->total = 0;
                

        ret = FS_Read(this->fs_hdlr, &(this->header),  sizeof(mmi_medply_plst_header_struct), &read_size);

        if (ret < FS_NO_ERROR)
        {
            FS_Close(this->fs_hdlr);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,this->fs_hdlr ,__LINE__);
            this->fs_hdlr = FS_ERROR_RESERVED;
            break;
        }
        else if (read_size != sizeof(mmi_medply_plst_header_struct))
        {
            FS_Close(this->fs_hdlr);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,this->fs_hdlr ,__LINE__);
            this->fs_hdlr = FS_ERROR_RESERVED;
            ret = MEDPLY_PLST_ERR_NOT_PLST;
            break;
        }
        /* check type id and version. */
        if (strncmp((CHAR*)(this->header.type_id), MEDPLY_PLAYLIST_TYPE_ID, 4))
        {
            ret = MEDPLY_PLST_ERR_NOT_PLST;
            break;
        }

        if (strncmp((CHAR*)(this->header.version), MEDPLY_PLAYLIST_VERSION, 2))
        {
            ret = MEDPLY_PLST_ERR_WRONG_VER;
            break;
        }

        ret = FS_GetFileSize(this->fs_hdlr, &file_size);

        if (ret < FS_NO_ERROR)
        {
            ret = MEDPLY_PLST_ERR_NOT_PLST;
            break;
        }

        if (this->header.footer_pattern_offset != file_size) 
        {
            ret = MEDPLY_PLST_ERR_NOT_PLST;
            break;
        }

        if ((this->header.footer_pattern_offset - 
                sizeof(mmi_medply_plst_header_struct)) % 
             sizeof(mmi_medply_plst_block_node_struct) != 0)
        {
            ret = MEDPLY_PLST_ERR_NOT_PLST;
            break;        
        }

        if (this->header.pattern != MEDPLY_PLAYLIST_FOOTER_PATTERN)
        {
            ret = MEDPLY_PLST_ERR_NOT_PLST;
            break;
        }        
        
    /* pass file type verification. */
        this->total = this->header.total_slot;
        ret = FS_Seek(this->fs_hdlr, MEDPLY_PLAYLIST_DATA_OFFSET, FS_FILE_BEGIN);
        
        if (ret < FS_NO_ERROR)
        {
            ret = MEDPLY_PLST_ERR_OPEN_FAILED;
            break;
        }
        
        if (this->total)
        {
            mmi_medply_plst_generate_sort_index(this->header.index, this->total);
            MMI_ASSERT(this->header.pattern == MEDPLY_PLAYLIST_FOOTER_PATTERN);
            empty_size = sizeof(mmi_medply_plst_index_node_struct) * (MMI_MEDPLY_MAX_PLAYLIST_ITEM - this->header.total_slot);
            MMI_ASSERT(this->total <= MMI_MEDPLY_MAX_PLAYLIST_ITEM);
            memset(&(this->header.index[this->total]), 0, empty_size);
            MMI_ASSERT(this->header.pattern == MEDPLY_PLAYLIST_FOOTER_PATTERN);
        }
    } while (0);

    if (ret < FS_NO_ERROR)
    {   
        FS_Close(this->fs_hdlr);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,this->fs_hdlr ,__LINE__);
        this->fs_hdlr = FS_ERROR_RESERVED;
    }
    else
    {
        ret = mmi_medply_plst_header_integrality_check(this);
        if (ret < FS_NO_ERROR)
        {   
            FS_Close(this->fs_hdlr);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,this->fs_hdlr ,__LINE__);
            this->fs_hdlr = FS_ERROR_RESERVED;
        }    
    }
        
    return ret;       
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_open
 * DESCRIPTION
 *  open a list file. 
 * PARAMETERS
 *  file_path
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_medply_plst_open(UI_string_type file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = FS_NO_ERROR;
    mmi_medply_plst_struct **list_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_add_to_mode)
    {
        list_p = &plst_cntx_p->backup_list_p;

    }
    else
    {
        list_p = &plst_cntx_p->browser_list_p;
    }
    
    if (NULL == *list_p)
    {   /*for kuro call*/
        *list_p = (mmi_medply_plst_struct*)kal_adm_alloc(g_medply.adm_id_p, sizeof(mmi_medply_plst_struct));/*bql*/
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ASM_ALLOCATE, *list_p, sizeof(mmi_medply_plst_struct), __LINE__);
        MMI_ASSERT(*list_p != NULL);
    }

    memset(*list_p, 0, sizeof(mmi_medply_plst_struct));

    /* check whether is the loading playlist. */
    if (plst_cntx_p->list_loaded)
    {
        if (!mmi_ucs2icmp((CHAR*)file_path, (CHAR*)plst_cntx_p->current_list.path))
        {
            if (in_add_to_mode)
            {
                addto_now_playing = MMI_TRUE;
            }
            else
            {
                browser_now_playing = MMI_TRUE;
            }
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_OPEN_IS_PLAYING, browser_now_playing , __LINE__);
            return FS_NO_ERROR;
        }
    }
    if (in_add_to_mode)
    {
        addto_now_playing = MMI_FALSE;
    }
    else
    {
        browser_now_playing = MMI_FALSE;
    }
    
    ret = mmi_medply_plst_open_internal(file_path, *list_p);
    if (ret < 0)
    {    /*for kuro call*/
        kal_adm_free(g_medply.adm_id_p, *list_p);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE, *list_p, __LINE__);
        *list_p = NULL;
    }
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_OPEN, ret, __LINE__);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_listmgr_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == plst_cntx_p->browser_list_p)
    {
        plst_cntx_p->browser_list_p = (mmi_medply_plst_struct*)kal_adm_alloc(g_medply.adm_id_p, sizeof(mmi_medply_plst_struct));/*bql*/
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ASM_ALLOCATE, plst_cntx_p->browser_list_p, sizeof(mmi_medply_plst_struct), __LINE__);
        MMI_ASSERT(plst_cntx_p->browser_list_p != NULL);
    }

    mmi_medply_plst_listmgr_get_path(path);
    ret = mmi_medply_plst_open(path);
    if (ret < FS_NO_ERROR)
    {
        if (browser_all_audio || browser_all_video)
        {
            //MAUI_02628684
            ret = mmi_medply_plst_all_media_list_init(MMI_TRUE);
            if (ret >= FS_NO_ERROR)
            {
                ret = mmi_medply_plst_open(path);
            }
            
            if (ret >= FS_NO_ERROR)
            {
                mmi_medply_plst_struct* list = NULL;
                
                if (browser_now_playing)
                {
                    list = &(plst_cntx_p->current_list);
                }
                else
                {
                    list = plst_cntx_p->browser_list_p;
                }
                
                if (list->total == 0)
                {
                    U16 string_id;
                    U8 *title_p;
                
                    if (browser_all_audio)
                    {
                        string_id = STR_GLOBAL_REFRESH;
                        title_p = (U8 *)GetString(STR_ID_MEDPLY_ALL_AUDIO);
                    }
                    else if (browser_all_video)
                    {
                        string_id = STR_GLOBAL_REFRESH;
                        title_p = (U8 *)GetString(STR_ID_MEDPLY_ALL_VIDEO);
                    }
                    else
                    {
                        string_id = STR_GLOBAL_ADD;
                        title_p = (U8 *)GetString(STR_ID_MEDPLY_PLST_TITLE);
                    }

                    mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_LIST_BROWSER, mmi_medply_plst_proc, (void*)NULL); 
                    mmi_frm_group_enter(GRP_ID_MEDPLY_LIST_BROWSER, MMI_FRM_NODE_SMART_CLOSE_FLAG);
                    mmi_frm_scrn_enter(GRP_ID_MEDPLY_LIST_BROWSER, SCR_ID_MEDPLY_LIST_BROWSER, mmi_medply_plst_exit_playlist, mmi_medply_plst_entry_playlist_internal, MMI_FRM_UNKNOW_SCRN);
                    mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_LIST_BROWSER, SCR_ID_MEDPLY_LIST_BROWSER, mmi_medply_plst_del_list_browser_callback);
                    ShowCategory353Screen(
                        (PU8)title_p,
                        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
                        string_id,
                        IMG_GLOBAL_OPTIONS,
                        STR_GLOBAL_BACK,
                        IMG_GLOBAL_BACK,
                        0,
                        NULL,
                        NULL,
                        NULL,
                        1,
                        0,
                        NULL);
                    
                    mmi_medply_plst_option_update();
                }
                else
                {
                    mmi_medply_plst_entry_playlist_internal();
                }
            }
            else
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_LISTMGR_OPEN, ret, __LINE__);
                mmi_medply_plst_popup_simple(ret);
            }
        }
        else
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_LISTMGR_OPEN, ret, __LINE__);
            mmi_medply_plst_popup_simple(ret);
        }
    }
    else
    {
        mmi_medply_plst_struct* list = NULL;
        
        if (browser_all_audio || browser_all_video)
        {
            /* set attribute as hiden if all media*/
            FS_SetAttributes(path, FS_GetAttributes(path) | FS_ATTR_HIDDEN);
            if (browser_now_playing)
            {
                list = &(plst_cntx_p->current_list);
            }
            else
            {
                list = plst_cntx_p->browser_list_p;
            }
            
            if (list->total == 0)
            {
                U16 string_id;
                U8 *title_p;
                
                if (browser_all_audio)
                {
                    string_id = STR_GLOBAL_REFRESH;
                    title_p = (U8 *)GetString(STR_ID_MEDPLY_ALL_AUDIO);
                }
                else if (browser_all_video)
                {
                    string_id = STR_GLOBAL_REFRESH;
                    title_p = (U8 *)GetString(STR_ID_MEDPLY_ALL_VIDEO);
                }
                else
                {
                    string_id = STR_GLOBAL_ADD;
                    title_p = (U8 *)GetString(STR_ID_MEDPLY_PLST_TITLE);
                }
                
                mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_LIST_BROWSER, mmi_medply_plst_proc, (void*)NULL); 
                mmi_frm_group_enter(GRP_ID_MEDPLY_LIST_BROWSER, MMI_FRM_NODE_SMART_CLOSE_FLAG);
                mmi_frm_scrn_enter(GRP_ID_MEDPLY_LIST_BROWSER, SCR_ID_MEDPLY_LIST_BROWSER, mmi_medply_plst_exit_playlist, mmi_medply_plst_entry_playlist_internal, MMI_FRM_UNKNOW_SCRN);
                mmi_frm_scrn_set_leave_proc(GRP_ID_MEDPLY_LIST_BROWSER, SCR_ID_MEDPLY_LIST_BROWSER, mmi_medply_plst_del_list_browser_callback);
                ShowCategory353Screen(
                    (PU8)title_p,
                    GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
                    string_id,
                    IMG_GLOBAL_OPTIONS,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    0,
                    NULL,
                    NULL,
                    NULL,
                    1,
                    0,
                    NULL);
                
                mmi_medply_plst_option_update();
            }
            else
            {
                mmi_medply_plst_entry_playlist_internal();
            }
        }
        else
        {
            mmi_medply_plst_entry_playlist_internal();
        }
    }

    if (ret < FS_NO_ERROR)
    {
        browser_all_audio = MMI_FALSE;
        browser_all_video = MMI_FALSE;
    }

    if (ret < FS_NO_ERROR && plst_cntx_p->browser_list_p)
    {
        kal_adm_free(g_medply.adm_id_p, plst_cntx_p->browser_list_p);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE, plst_cntx_p->browser_list_p, __LINE__);
        plst_cntx_p->browser_list_p = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_create_part3
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_medply_plst_listmgr_create_part3(UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = MEDPLY_PLST_NO_ERROR;
    U32 write_size = 0;

    mmi_medply_plst_header_struct* header_p = NULL;
    FS_HANDLE fs_hdlr = FS_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    header_p = kal_adm_alloc(g_medply.adm_id_p, sizeof(mmi_medply_plst_header_struct));
    if (header_p == NULL)
    {
        /* to avoid sanity test fail ~~*/
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ASM_ALLOCATE,header_p, sizeof(mmi_medply_plst_header_struct), __LINE__);
        return MEDPLY_PLST_ERR_NO_MEMORY;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ASM_ALLOCATE,header_p, sizeof(mmi_medply_plst_header_struct), __LINE__);
    memset(header_p, 0, sizeof(mmi_medply_plst_header_struct));

    /* create new playlist. */
    do
    {
        ret = FS_Open(path, FS_CREATE_ALWAYS | FS_READ_WRITE);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_OPEN,ret ,__LINE__);
        if (ret < FS_NO_ERROR)
        {
            break;
        }
        else
        {
            if ((browser_all_audio || browser_all_video) & !in_add_to_mode)
            {
                /* set attribute as hiden if all media*/
                FS_SetAttributes(path, FS_GetAttributes(path) | FS_ATTR_HIDDEN);
            }

        }

        fs_hdlr = ret;
        /* write header. */
        header_p->footer_pattern_offset = MEDPLY_PLAYLIST_DATA_OFFSET;
        strncpy((CHAR*)header_p->type_id, MEDPLY_PLAYLIST_TYPE_ID, 4);
        strncpy((CHAR*)header_p->version, MEDPLY_PLAYLIST_VERSION, 2);
        header_p->pattern = MEDPLY_PLAYLIST_FOOTER_PATTERN;
        ret = FS_Write(fs_hdlr, header_p,
                       sizeof(mmi_medply_plst_header_struct), 
                       &write_size);

        kal_adm_free(g_medply.adm_id_p, header_p);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE,header_p, __LINE__);
        header_p = NULL;
        
        if (ret < FS_NO_ERROR)
        {
            break;
        }
        else if (write_size != sizeof(mmi_medply_plst_header_struct))
        {
            ret = MEDPLY_PLST_ERR_CREATE_FAILED;
            break;
        }
    } while (0);

    if (header_p != NULL)
    {   /*FS_Open failed need free header bql*/
        kal_adm_free(g_medply.adm_id_p, header_p);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE,header_p, __LINE__);
        header_p = NULL;
    }
    
    FS_Commit(fs_hdlr);
    FS_Close(fs_hdlr);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,fs_hdlr ,__LINE__);
    if (ret < FS_NO_ERROR)
    {
        FS_Delete(path);
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_create_part2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv_letter      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_listmgr_create_part2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type path[MEDPLY_MAX_PATH_LEN];
    S32 ret = 0;



    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
#ifdef __MMI_KURO_SUPPORT__
    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_DEFAULT_STORAGE, &plst_cntx_p->default_storage);
#endif
    kal_wsprintf(path, "%c:\\", plst_cntx_p->default_storage);
    /* check whether has enough space. */
    {
        FS_DiskInfo disk_info;
        U64 disk_free_space;
        S32 fs_ret;

        fs_ret = FS_GetDiskInfo((kal_uint16*)path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

        if (fs_ret >= 0)
        {        
            disk_free_space = (U64)(disk_info.FreeClusters * 
                              disk_info.SectorsPerCluster * 
                              disk_info.BytesPerSector);
            if (disk_free_space < 9 * 1024)    
            {
                /* popup "Not enough space." */
                mmi_medply_plst_popup_simple(MEDPLY_PLST_ERR_NO_SPACE);
                return;
            }
        }
    }
    mmi_ucs2ncat((CHAR*)path, (CHAR*)MMI_MEDPLY_DEFAULT_FOLDER, (MEDPLY_MAX_PATH_LEN - 1));

    /* check default playlist folder. */
    ret  = FS_GetAttributes(path);
    if (ret >= 0 && !(ret & FS_ATTR_DIR))
    {
        FS_Delete(path);
    }
    ret = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_OPEN,ret ,__LINE__);
    if (ret < 0)
    {
        ret = FS_CreateDir(path);
        if (ret < 0)
        {
            mmi_medply_plst_popup_simple(ret);
            return;
        }
        else
        {
            ret = 0;
            FS_SetAttributes(path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
        }
    }
    else
    {
        FS_Close(ret);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,ret ,__LINE__);
        ret = 0;
    }
    /* compose playlist full path. */
    mmi_ucs2ncat((CHAR*)path, (CHAR*)L"\\", (MEDPLY_MAX_PATH_LEN - 1));
    mmi_ucs2ncat((CHAR*)path, (CHAR*)plst_cntx_p->editor.editor_buffer, (MEDPLY_MAX_PATH_LEN - 1));
    mmi_ucs2ncat((CHAR*)path, (CHAR*)MMI_MEDPLY_DEFAULT_LIST_EXT, (MEDPLY_MAX_PATH_LEN - 1));
    
    /* check file, pop up if exist. */
    if (FS_GetAttributes(path) > 0)
    {
        mmi_medply_plst_popup_simple(MEDPLY_PLST_ERR_FILE_EXISTS);
    }
    else
    {
        ret = mmi_medply_plst_listmgr_create_part3(path);
        
        if (ret < 0)
        {
            /* all error caught in create will popup "create plauylist failed" */
            mmi_medply_plst_popup_simple(MEDPLY_PLST_ERR_CREATE_FAILED);
        }
        else
        {
            if (in_add_to_mode)
            {
                mmi_medply_dynamic_list_data_struct* ui = &(plst_cntx_p->list_ui);  
                
                /* add the file to the latest created list */
                ret = mmi_medply_plst_open(path);
                if (ret >= FS_NO_ERROR)
                {
                    memset(&(plst_cntx_p->generate_cntx), 0, sizeof(mmi_medply_plst_generate_struct));
                    ret = mmi_medply_plst_generate_append_internal(ui->temp_buffer, MMI_FALSE, MMI_TRUE);
                }
                if (ret < FS_NO_ERROR)
                {
                    mmi_medply_plst_popup_simple(ret);
                }
                else
                {
	/* removed for new UE */
#if 0
/* under construction !*/
#endif
                }
                mmi_frm_group_close(GRP_ID_MEDPLY_LIST_ADD_TO);
            }
            else
            {
                /* open the latest created list for friendly usage */
	/* removed for new UE */
#if 0
/* under construction !*/
#endif
                ret = mmi_medply_plst_open(path);
                if (ret >= FS_NO_ERROR)
                {
                    mmi_frm_node_struct new_screen_struct;
                    mmi_frm_node_struct new_group_struct;

                    mmi_frm_node_info_init(&new_group_struct);
                    new_group_struct.id = GRP_ID_MEDPLY_LIST_BROWSER;
                    new_group_struct.entry_proc = (mmi_proc_func)mmi_medply_plst_proc;
                    mmi_frm_group_insert(g_gid_medply, GRP_ID_MEDPLY_LIST_MGR, &new_group_struct , MMI_FRM_NODE_AFTER_FLAG);
                    mmi_frm_group_set_attribute(GRP_ID_MEDPLY_LIST_BROWSER, MMI_FRM_NODE_SMART_CLOSE_FLAG);
                    
                    
                    mmi_frm_node_info_init(&new_screen_struct);
                    new_screen_struct.id = SCR_ID_MEDPLY_LIST_BROWSER;
                    new_screen_struct.entry_proc = (mmi_proc_func)mmi_medply_plst_entry_playlist_internal;
                    mmi_frm_scrn_insert(GRP_ID_MEDPLY_LIST_BROWSER, GRP_ID_MEDPLY_LIST_BROWSER, &new_screen_struct, MMI_FRM_NODE_AT_BEGINNING_FLAG);
                }
                else
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
                }
            }
            /* need clear highlight index saved in gui buffer. */
            mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_MGR);    
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_create_part1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_listmgr_create_part1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    plst_cntx_p->editor.editor_type = MMI_MEDPLY_EDITOR_NEW;
    plst_cntx_p->editor.editor_buffer[0] = 0;
    plst_cntx_p->editor.editor_title_id = STR_ID_MEDPLY_PLST_NEW;
    plst_cntx_p->editor.done_func = mmi_medply_plst_listmgr_create_part2;
    plst_cntx_p->editor.limit = MEDPLY_MAX_INPUT_FILE_LEN;
    if (in_add_to_mode)
    {
        plst_cntx_p->editor.parent_id = GRP_ID_MEDPLY_LIST_ADD_TO;
    }
    else
    {
        plst_cntx_p->editor.parent_id = GRP_ID_MEDPLY_LIST_MGR;
    }
    mmi_medply_entry_editor();
}

#define __BOOKMARK
#ifdef __MMI_MEDIA_PLAYER_STREAM__
static S32      mmi_medply_util_create_file_dir(UI_string_type filepath);
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bookmark_history_option_initiate_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_bookmark_history_option_initiate_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_medply_history_url_struct url;
    S16 error;
    S32 hilite_item = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_BACKGROUND_CALL__) && !defined(__RF_DESENSE_TEST__) && !defined(__CS_STREAMING_CONCURRENT_SUPPORT__)
    if(srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif
    hilite_item = mmi_medply_plst_ui_get_current_highlight();
    if (hilite_item < NVRAM_EF_MEDPLY_HISTORY_URL_TOTAL && hilite_item >= 0)
    {
        ReadRecord(
                NVRAM_EF_MEDPLY_HISTORY_URL_LID, 
                (hilite_item + 1),    /* id start from 1 */ 
                (void*)&url, 
                NVRAM_EF_MEDPLY_HISTORY_URL_SIZE, 
                &error);

        if (mmi_ucs2ncmp((CHAR*)L"Z:", (CHAR*)url.url, 2) == 0)
        {
            /* sdp url. */
        #ifdef __MMI_MEDIA_PLAYER_STREAM__  
            mmi_medply_single_play_stream_from_sdp_file_with_title((UI_string_type)url.url,MMI_FALSE, (UI_string_type) url.name);
        #endif 
            /* delete: editor option, editor */
            mmi_frm_group_close(GRP_ID_MEDPLY_LIST_EDITOR);
            return;
        }
        else
        {
            /* rtsp url */
        #ifdef __MMI_MEDIA_PLAYER_STREAM__
            mmi_medply_single_play_stream_from_rtsp_link_with_title((UI_string_type)url.url, (UI_string_type) url.name);
        #endif
            /* delete: editor option, editor */
            mmi_frm_group_close(GRP_ID_MEDPLY_LIST_EDITOR);
            return;
        }
    }
    else 
    {
        /* invalid url. */
        mmi_medply_plst_popup_simple_with_string(get_string(STR_GLOBAL_INVALID_URL), MMI_EVENT_ERROR);
    } 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bookmark_history_option_remove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_bookmark_history_option_remove(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_medply_history_url_struct url;
    S16 error;
    S32 i;
    S32 hilite_item = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hilite_item = mmi_medply_plst_ui_get_current_highlight();
    if (hilite_item == (NVRAM_EF_MEDPLY_HISTORY_URL_TOTAL - 1))
    {
        /* last element, just remove it by reset all valeu to zero */
        memset((void*)&url, 0, sizeof(nvram_ef_medply_history_url_struct));

        WriteRecord(
            NVRAM_EF_MEDPLY_HISTORY_URL_LID, 
            hilite_item + 1,    /* id start from 1 */ 
            (void*)&url, 
            NVRAM_EF_MEDPLY_HISTORY_URL_SIZE, 
            &error);
    }
    else
    {   
        /* not last element, move next upward and clean next one */
        for (i = hilite_item; i < NVRAM_EF_MEDPLY_HISTORY_URL_TOTAL - 1; i++)
        {
            /* read next */
            ReadRecord(
                NVRAM_EF_MEDPLY_HISTORY_URL_LID, 
                (i + 1) + 1,    /* id start from 1 */ 
                (void*)&url, 
                NVRAM_EF_MEDPLY_HISTORY_URL_SIZE, 
                &error);

            /* write this */
            WriteRecord(
                NVRAM_EF_MEDPLY_HISTORY_URL_LID, 
                (i) + 1,    /* id start from 1 */ 
                (void*)&url, 
                NVRAM_EF_MEDPLY_HISTORY_URL_SIZE, 
                &error);
        }

        /* clean last */
        memset((void*)&url, 0, sizeof(nvram_ef_medply_history_url_struct));

        WriteRecord(
            NVRAM_EF_MEDPLY_HISTORY_URL_LID, 
            (NVRAM_EF_MEDPLY_HISTORY_URL_TOTAL - 1) + 1,    /* id start from 1 */ 
            (void*)&url, 
            NVRAM_EF_MEDPLY_HISTORY_URL_SIZE, 
            &error);        
    }
/*bql: apply new UE design to avoid success popup */
#if 1
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
#else
/* under construction !*/
#endif
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bookmark_history_option_clear
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_bookmark_history_option_clear(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_medply_history_url_struct url;
    S16 error;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset((void*)&url, 0, sizeof(nvram_ef_medply_history_url_struct));
    /* not last element, move next upward and clean next one */
    for (i = 0; i < NVRAM_EF_MEDPLY_HISTORY_URL_TOTAL; i++)
    {
        /* write this */
        WriteRecord(
            NVRAM_EF_MEDPLY_HISTORY_URL_LID, 
            (i) + 1,    /* id start from 1 */ 
            (void*)&url, 
            NVRAM_EF_MEDPLY_HISTORY_URL_SIZE, 
            &error);
    }
/*bql: apply new UE design to avoid success popup */
#if 1
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
#else
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bookmark_entry_remove_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_bookmark_entry_remove_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ? will be shown by popup not application */
    mmi_medply_plst_confirm_simple(GRP_ID_MEDPLY_LIST_BOOKMARK,
        (WCHAR *)get_string(STR_GLOBAL_REMOVE),
        mmi_medply_bookmark_history_option_remove,
        CNFM_TYPE_YESNO,
        MMI_FALSE,
        MMI_EVENT_QUERY);     
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bookmark_entry_remove_all_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_bookmark_entry_remove_all_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ? will be shown by popup not application */
    mmi_medply_plst_confirm_simple(GRP_ID_MEDPLY_LIST_BOOKMARK,
        (WCHAR *)get_string(STR_GLOBAL_REMOVE),
        mmi_medply_bookmark_history_option_clear,
        CNFM_TYPE_YESNO,
        MMI_FALSE,
        MMI_EVENT_QUERY);     
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_history_sync_sdp_file
 * DESCRIPTION
 *  sync sdp file in z:\@VideoStream folder, remove unused files
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_history_sync_sdp_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define MEDPLY_HISTORY_BUF_LEN   (50)   /* Z:\@VideoStream\xx.sdp */
        
    FS_DOSDirEntry file_info;
    CHAR buf_filename[(MEDPLY_HISTORY_BUF_LEN+1) * ENCODING_LENGTH];
    CHAR buf_filepath[(MEDPLY_HISTORY_BUF_LEN+1) * ENCODING_LENGTH]; 
    FS_HANDLE file_handle;
    nvram_ef_medply_history_url_struct history;
    S16 error;
    CHAR* filename_p;
    MMI_BOOL is_in_history;
    S32 fs_ret;
    S32 i;
    CHAR filter[(MEDPLY_HISTORY_BUF_LEN+1) * ENCODING_LENGTH];
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    mmi_ucs2cpy((CHAR*)filter, (CHAR*)L"Z:\\@VideoStream\\*.*");

    file_handle = FS_FindFirst(
                    (U16*)filter, 
                    0, 
                    0, 
                    &file_info, 
                    (U16*)buf_filename, 
                    sizeof(buf_filename));
    

    if (file_handle  > 0)
    {
        /* extrac files in Z:\@VideoStream one by one, and check if it is in hitroy */
        do
        {
            is_in_history = MMI_FALSE;
            
            for (i = 0; i < NVRAM_EF_MEDPLY_HISTORY_URL_TOTAL; i++)
            {
                ReadRecord(
                        NVRAM_EF_MEDPLY_HISTORY_URL_LID, 
                        i+1,    /* id start from 1 */ 
                        (void*)&history, 
                        NVRAM_EF_MEDPLY_HISTORY_URL_SIZE, 
                        &error);
  
                /* check if it a sdp file, not rtsp url */
                if (mmi_ucs2ncmp((CHAR*)L"Z:", (CHAR*)history.url, 2) == 0)
                {
                    filename_p = (CHAR*)srv_fmgr_path_get_filename_ptr((WCHAR*)((CHAR*)history.url));
                    if (mmi_ucs2cmp(buf_filename, filename_p) == 0)
                    {
                        /* this file is in history */
                        is_in_history = MMI_TRUE;
                        break;
                    }
                }
            } 

            if (!is_in_history)
            {
                /* delete file */
                mmi_ucs2cpy(buf_filepath, (CHAR*)L"Z:\\@VideoStream\\");
                mmi_ucs2cat(buf_filepath, buf_filename);
                FS_Delete((U16*)buf_filepath);
            }

            fs_ret = FS_FindNext(
                        file_handle, 
                        &file_info,
                        (PU16)buf_filename,
                        sizeof(buf_filename));
            
        }while (fs_ret == FS_NO_ERROR);

        FS_FindClose(file_handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_history_sync_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_history_sync_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define MEDPLY_SDP_FNAME_BUFFER_LEN   (50)   /* Z:\@VideoStream\xx.sdp */
        
    CHAR buf_filepath[(MEDPLY_SDP_FNAME_BUFFER_LEN+1) * ENCODING_LENGTH]; 
    S32 filecount;
    S32 i;
    S32 index;
    S16 error;
    S32 url_len;
    nvram_ef_medply_history_url_struct history_url;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    mmi_ucs2cpy((CHAR*)buf_filepath, (CHAR*)L"Z:\\@VideoStream\\*.*");

    filecount = FS_Count((U16*)buf_filepath, FS_FILE_TYPE, NULL, 0);
    /* get sdp file cound in history */
    index = 0;
    for (i = 0 ; i < NVRAM_EF_MEDPLY_HISTORY_URL_TOTAL; i++)
    {
        ReadRecord(
            NVRAM_EF_MEDPLY_HISTORY_URL_LID, 
            i+1,    /* id start from 1 */ 
            (void*)&history_url, 
            NVRAM_EF_MEDPLY_HISTORY_URL_SIZE, 
            &error);

        url_len = mmi_ucs2strlen((CHAR*)history_url.url);
        if (url_len == 0)
        {
            /* empty url */
            break;
        }
        if (mmi_ucs2ncmp((CHAR*)L"Z:", (CHAR*)history_url.url, 2) == 0)
        {
            index ++;
        }
    }
    
    if (index != filecount)
    {
        mmi_medply_history_sync_sdp_file();
    }
}


 
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_history_insert_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  url_p       [IN]         url buffer in unicode
 *  name_p      [IN]        name buffer in unicode 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_history_insert_url(CHAR* url_p, CHAR* name_p, MMI_BOOL is_single)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #define MEDPLY_SDP_READ_BUFFER  30
    S32 history_count;
    S32 i;
    S16 error;
    S32 exist_index;
    S32 url_len;
    nvram_ef_medply_history_url_struct* history_url = NULL;
    nvram_ef_medply_history_url_struct* move_url = NULL;
    U8 history_sdp_file_buf[MEDPLY_SDP_READ_BUFFER];
    U8 sdp_file_buf[MEDPLY_SDP_READ_BUFFER];
    FS_HANDLE history_sdp_h;
    FS_HANDLE sdp_h;
    FS_HANDLE fs_h;    
    U32 history_sdp_read;    
    U32 sdp_read;
    U32 sdp_write;
    MMI_BOOL is_same_file;
    CHAR ansii_str[50];
    CHAR usc2_str[50]; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(url_p != NULL);
    MMI_ASSERT(name_p != NULL);  
    
    media_get_ext_buffer(MOD_MMI, (void **)&history_url, sizeof(nvram_ef_medply_history_url_struct));
    media_get_ext_buffer(MOD_MMI, (void **)&move_url, sizeof(nvram_ef_medply_history_url_struct));
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_ALLOCATE, history_url, sizeof(nvram_ef_medply_history_url_struct), __LINE__);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_ALLOCATE, move_url, sizeof(nvram_ef_medply_history_url_struct), __LINE__);
    if (!history_url || !move_url)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        return;
    }

    history_count = 0;
    exist_index = -1;

    for (i = 0; i < NVRAM_EF_MEDPLY_HISTORY_URL_TOTAL; i++)
    {
        ReadRecord(NVRAM_EF_MEDPLY_HISTORY_URL_LID,
            i+1,    /* id start from 1 */ 
            (void*)history_url, 
            NVRAM_EF_MEDPLY_HISTORY_URL_SIZE, 
            &error);

            url_len = mmi_ucs2strlen((CHAR*)history_url->url);

            if (url_len == 0)
            {
                /* empty entry */
                break;
            }
            
        if ((is_single&&(g_single.media_type == MEDPLY_TYPE_STREAM_RTSP || g_single.media_type == MEDPLY_TYPE_STREAM_RAM )) ||
            (!is_single&&(g_medply.media_format == MEDPLY_FORMAT_RAM)))
        {
            
            /* compare two url */
            if (mmi_ucs2cmp((CHAR*)url_p, (CHAR*)history_url->url) == 0)
            {
                if (i == 0)
                {
                    if (history_url)
                    {
                        media_free_ext_buffer(MOD_MMI, (void**)&history_url);
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE,history_url, __LINE__);
                        history_url = NULL;
                    }
                    if (move_url)
                    {
                        media_free_ext_buffer(MOD_MMI, (void**)&move_url);
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE,move_url, __LINE__);
                        move_url = NULL;
                    }
                    /* already is first one */
                    return;
                }
                
                /* hit. already in history */
                exist_index = i;
                break;
            }
        }
        else if ((is_single&&(g_single.media_type == MEDPLY_TYPE_STREAM_SDP)) ||
                (!is_single&&(g_medply.media_format != MEDPLY_FORMAT_RAM)))
        {
            /* "Z:\\@VideoStream\\" */
            if (mmi_ucs2ncmp((CHAR*)L"Z:", (CHAR*)history_url->url, 2) == 0)
            {
                /* this entry's url is Z:, it is a cached SDP file */
                /* compare two sdp file */
                history_sdp_h = FS_Open((U16*)history_url->url, FS_READ_ONLY);
                sdp_h = FS_Open((U16*)url_p, FS_READ_ONLY);                

                is_same_file = MMI_TRUE;
                while (1)
                {   /*compare the two sdp file, bql*/
                    FS_Read(history_sdp_h, history_sdp_file_buf, MEDPLY_SDP_READ_BUFFER, &history_sdp_read);
                    FS_Read(sdp_h, sdp_file_buf, MEDPLY_SDP_READ_BUFFER, &sdp_read);

                    if (sdp_read != history_sdp_read)
                    {
                        /* read size not match, different file */      
                        is_same_file = MMI_FALSE;
                        break;
                    }

                    if (memcmp((void*)sdp_file_buf, (void*)history_sdp_file_buf, sdp_read) != 0)
                    {
                        /* content not match, different file */
                        is_same_file = MMI_FALSE;
                        break;
                    }

                    if (sdp_read < MEDPLY_SDP_READ_BUFFER)
                    {
                        break;
                    }
					memset((void*)history_sdp_file_buf, 0, sizeof(history_sdp_file_buf));
					memset((void*)sdp_file_buf, 0, sizeof(sdp_file_buf));
					
                }

                if (sdp_h  > 0)
                {
                    FS_Close(sdp_h);
                }

                if (history_sdp_h  > 0)
                {
                    FS_Close(history_sdp_h);
                }

                /* same sdp file */
                if (is_same_file)
                {
                    if (i == 0)
                    {
                        if (history_url)
                        {
                            media_free_ext_buffer(MOD_MMI, (void**)&history_url);
                            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE,history_url, __LINE__);
                            history_url = NULL;
                        }
                        if (move_url)
                        {
                           
                           media_free_ext_buffer(MOD_MMI, (void**)&move_url);
                           MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE,move_url, __LINE__);
                            move_url = NULL;
                        }
                        /* already is first one */
                        return;
                    }
                    
                    /* hit. already in history */
                    exist_index = i;
                    break;
                }
                
            }

        }
        history_count ++;
    }


    if (exist_index != -1)
    {
        /* already in history, move it to first and move others down */
        
        for (i = exist_index - 1; i >= 0 ; i--)
        {
            /* read this */
            ReadRecord(
                NVRAM_EF_MEDPLY_HISTORY_URL_LID, 
                i+1,    /* id start from 1 */ 
                (void*)move_url, 
                NVRAM_EF_MEDPLY_HISTORY_URL_SIZE, 
                &error);

            /* write to next */
            WriteRecord(
                NVRAM_EF_MEDPLY_HISTORY_URL_LID, 
                i+1+1,    /* id start from 1 */ /* +1 for next */
                (void*)move_url, 
                NVRAM_EF_MEDPLY_HISTORY_URL_SIZE, 
                &error);
        }
        
        /* insert this to 1st */
        WriteRecord(
            NVRAM_EF_MEDPLY_HISTORY_URL_LID, 
            1,    /* id start from 1 */
            (void*)history_url, 
            NVRAM_EF_MEDPLY_HISTORY_URL_SIZE, 
            &error);        

        if (history_url)
        {
            media_free_ext_buffer(MOD_MMI, (void**)&history_url);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE,history_url, __LINE__);
            history_url = NULL;
        }
        if (move_url)
        {
            media_free_ext_buffer(MOD_MMI, (void**)&move_url);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE,move_url, __LINE__);
            move_url = NULL;
        }
        return;
    }
    else
    {
     /* newly added */
        
        if (history_count == NVRAM_EF_MEDPLY_HISTORY_URL_TOTAL)
        {
            /* avoid overflow */
            history_count--;
        }

        for (i = history_count - 1; i >= 0 ; i--)
        {
            /* read this */
            ReadRecord(
                NVRAM_EF_MEDPLY_HISTORY_URL_LID, 
                i+1,    /* id start from 1 */ 
                (void*)move_url, 
                NVRAM_EF_MEDPLY_HISTORY_URL_SIZE, 
                &error);

            /* write to next */
            WriteRecord(
                NVRAM_EF_MEDPLY_HISTORY_URL_LID, 
                i+1+1,    /* id start from 1 */ /* +1 for next */
                (void*)move_url, 
                NVRAM_EF_MEDPLY_HISTORY_URL_SIZE, 
                &error);
        }

        if ((is_single&&(g_single.media_type == MEDPLY_TYPE_STREAM_RTSP || g_single.media_type == MEDPLY_TYPE_STREAM_RAM )) ||
            (!is_single&&(g_medply.media_format == MEDPLY_FORMAT_RAM)))
        {
            /* insert this to 1st */
            memset((void*)history_url, 0, sizeof(nvram_ef_medply_history_url_struct));
            mmi_ucs2ncpy((CHAR*)history_url->url , url_p, MEDPLY_MAX_HISTORY_URL_LEN);
            mmi_ucs2ncpy((CHAR*)history_url->name , name_p, MEDPLY_MAX_HISTORY_NAME_LEN);     
        
            WriteRecord(
                NVRAM_EF_MEDPLY_HISTORY_URL_LID, 
                1,    /* id start from 1 */
                (void*)history_url, 
                NVRAM_EF_MEDPLY_HISTORY_URL_SIZE, 
                &error);  
        }
        /* copy file to Z: */
        else if ((is_single&&(g_single.media_type == MEDPLY_TYPE_STREAM_SDP)) ||
                (!is_single&&(g_medply.media_format != MEDPLY_FORMAT_RAM)))
        {
            UI_character_type temppath[MEDPLY_MAX_PATH_LEN];
            FS_HANDLE  fs_handler;
            U32 length;

            mmi_ucs2cpy((CHAR*)temppath, (CHAR*)L"Z:\\@VideoStream");
            fs_handler = FS_Open((U16*)temppath, FS_READ_ONLY);
            if (fs_handler < FS_NO_ERROR)
            {
                mmi_ucs2cat((CHAR*) temppath, (CHAR*) L"\\");
                mmi_medply_util_create_file_dir(temppath);
            }
            else
            {
                FS_Close(fs_handler);
            }
            i = 0;
                /* use a loop to find an empty file name */
            while(1)
            {
                    sprintf((CHAR*)ansii_str, "Z:\\@VideoStream\\%d.sdp", i);/*bql*/
                /* we will store the sdp as Z:\1.sdp ... etc */
                mmi_asc_to_ucs2(usc2_str, ansii_str);
                fs_h = FS_Open((U16*)usc2_str, FS_READ_ONLY);  

                if (fs_h < 0)
                {
                    /* file not exist */
                    break;
                }
                else
                {
                    FS_Close(fs_h);
                }
                i++;
            }
            
            /*original sdp*/
            sdp_h = FS_Open((U16*)url_p, FS_READ_ONLY);               
            /*history sdp*/
            history_sdp_h = FS_Open((U16*)usc2_str, FS_CREATE);

            /* copy from original sdp file to history */
            while(1)
            {   /*read 30 bybe each time only. bql*/
                FS_Read(sdp_h, sdp_file_buf, MEDPLY_SDP_READ_BUFFER, &sdp_read);
                FS_Write(history_sdp_h, sdp_file_buf, sdp_read, &sdp_write);

                if (sdp_read < MEDPLY_SDP_READ_BUFFER)
                {
                    /* read end */
                    break;
                }
				memset((void*)sdp_file_buf, 0, sizeof(sdp_file_buf));

            }
            
            FS_Close(sdp_h);
            FS_Close(history_sdp_h);

            /* insert this to 1st */
            memset((void*)history_url, 0, sizeof(nvram_ef_medply_history_url_struct));
            mmi_ucs2ncpy((CHAR*)history_url->url , usc2_str, MEDPLY_MAX_HISTORY_URL_LEN);
            /*check the gived name , if ok use gived name as history_url.name, esle use i, bql*/
            length = mmi_ucs2strlen((CHAR*) name_p);

            if (length)
            {
                mmi_ucs2ncpy((CHAR*)history_url->name , name_p, MEDPLY_MAX_HISTORY_NAME_LEN);     
            }
            else
            {
                temppath[0] = 0;
                kal_wsprintf((kal_wchar*)temppath,"\\%d.sdp",i);
                mmi_ucs2ncpy((CHAR*)history_url->name , (CHAR*)temppath, MEDPLY_MAX_HISTORY_NAME_LEN);
            }
            WriteRecord(
                NVRAM_EF_MEDPLY_HISTORY_URL_LID, 
                1,    /* id start from 1 */
                (void*)history_url, 
                NVRAM_EF_MEDPLY_HISTORY_URL_SIZE, 
                &error);             

            if (history_url)
            {
               
               media_free_ext_buffer(MOD_MMI, (void**)&history_url);
               MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE,history_url, __LINE__);
                history_url = NULL;
            }
            if (move_url)
            {
                media_free_ext_buffer(MOD_MMI, (void**)&move_url);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE,move_url, __LINE__);
                move_url = NULL;
            }
            mmi_medply_history_sync_file();
        }
    }
    if (history_url)
    {
        media_free_ext_buffer(MOD_MMI, (void**)&history_url);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE,history_url, __LINE__);
        history_url = NULL;
    }
    if (move_url)
    {
        media_free_ext_buffer(MOD_MMI, (void**)&move_url);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE,move_url, __LINE__);
        move_url = NULL;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_entry_bookmark
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_entry_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_gid = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_LIST_BOOKMARK, mmi_medply_plst_proc, (void*)NULL); 

    mmi_frm_group_enter(GRP_ID_MEDPLY_LIST_BOOKMARK, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_gid = cui_menu_create(
                        GRP_ID_MEDPLY_LIST_BOOKMARK,
                    	CUI_MENU_SRC_TYPE_RESOURCE,
                    	CUI_MENU_TYPE_APPSUB,
                    	MENU_ID_MEDPLY_BOOKMARK_MENU,
                    	MMI_FALSE, NULL);
    if (cui_gid > GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)));
        cui_menu_run(cui_gid);
    }
    else
    {   
        mmi_medply_plst_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),MMI_EVENT_FAILURE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bookmark_append_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_bookmark_append_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_ucs2nicmp((CHAR*)plst_cntx_p->editor.editor_buffer, (CHAR*)L"RTSP://", 7))
    {
        /* rtsp url. */
        /* TODO: call play rtsp API here, and entry player screen*/
    #ifdef __MMI_MEDIA_PLAYER_STREAM__
        mmi_medply_single_play_stream_from_rtsp_link(plst_cntx_p->editor.editor_buffer);
    #endif
        /* delete: editor option, editor */
        mmi_frm_group_close(GRP_ID_MEDPLY_LIST_EDITOR);
        return;
    }
    else if (!mmi_ucs2nicmp((CHAR*)plst_cntx_p->editor.editor_buffer, (CHAR*)L"HTTP://", 7))
    {
        CHAR* ext = NULL;

        if (ext)
        {
            if (!mmi_ucs2nicmp((CHAR*)ext, (CHAR*)L".SDP", 4))
            {
                /* sdp url */
                /* TODO: call play sdp API here, and entry player screen*/
            #ifdef __MMI_MEDIA_PLAYER_STREAM__ 
                mmi_medply_single_play_stream_from_sdp_file(plst_cntx_p->editor.editor_buffer,MMI_FALSE);
            #endif
                /* delete: editor option, editor */
                mmi_frm_group_close(GRP_ID_MEDPLY_LIST_EDITOR);
                return;
            }
        }
    }

    /* invalid url. */
    mmi_medply_plst_popup_simple_with_string(get_string(STR_GLOBAL_INVALID_URL), MMI_EVENT_ERROR);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bookmark_input_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_bookmark_input_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    plst_cntx_p->editor.editor_type = MMI_MEDPLY_EDITOR_EDIT_URL;
    plst_cntx_p->editor.editor_buffer[0] = 0;
    plst_cntx_p->editor.editor_title_id = STR_ID_MEDPLY_PLST_INPUT_URL;
    plst_cntx_p->editor.done_func = mmi_medply_bookmark_append_url;
    plst_cntx_p->editor.limit = MMI_MEDPLY_MAX_URL_LEN;
    kal_wsprintf(plst_cntx_p->editor.editor_buffer, "rtsp://");
    plst_cntx_p->editor.parent_id = GRP_ID_MEDPLY_LIST_BOOKMARK;
    mmi_medply_entry_editor();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bookmark_entry_history_option
 * DESCRIPTION
 *  entry history option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_bookmark_entry_history_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_gid = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(GRP_ID_MEDPLY_LIST_BOOKMARK, GRP_ID_MEDPLY_LIST_HISTORY_URL_OPT, mmi_medply_plst_proc, (void*)NULL); 

    mmi_frm_group_enter(GRP_ID_MEDPLY_LIST_HISTORY_URL_OPT, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_gid = cui_menu_create(
                            GRP_ID_MEDPLY_LIST_HISTORY_URL_OPT,
                        	CUI_MENU_SRC_TYPE_RESOURCE,
                        	CUI_MENU_TYPE_OPTION,
                        	MENU_ID_MEDPLY_BOOKMARK_OPTION_MENU,
                        	MMI_FALSE, NULL);
    if (cui_gid > GRP_ID_INVALID)
    {
        cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(GetRootTitleIcon(MENU_ID_MEDPLY_MAIN)));
        cui_menu_run(cui_gid);
    }
    else
    {   
        mmi_medply_plst_popup_simple_with_string( (U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bookmark_entry_history_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_bookmark_entry_history_url(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 index;
    S16 error;
    S32 url_len;
    S32 name_len;
    U16 item_icons[NVRAM_EF_MEDPLY_HISTORY_URL_TOTAL]; 
    U8 *gui_buffer;    
    nvram_ef_medply_history_url_struct history_url;
    MMI_BOOL entry_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_LIST_BOOKMARK, SCR_ID_MEDPLY_LIST_HISTORY_URL, NULL, mmi_medply_bookmark_entry_history_url, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }    
    
    mmi_medply_history_sync_sdp_file();
    gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_LIST_BOOKMARK, SCR_ID_MEDPLY_LIST_HISTORY_URL);

    index = 0;
    for (i = 0 ; i < NVRAM_EF_MEDPLY_HISTORY_URL_TOTAL; i++)
    {
        ReadRecord(
            NVRAM_EF_MEDPLY_HISTORY_URL_LID, 
            i+1,    /* id start from 1 */ 
            (void*)&history_url, 
            NVRAM_EF_MEDPLY_HISTORY_URL_SIZE, 
            &error);

        url_len = mmi_ucs2strlen((CHAR*)history_url.url);
        name_len = mmi_ucs2strlen((CHAR*)history_url.name);
        if (url_len == 0)
        {
            /* empty url */
            break;
        }
        
        if (name_len == 0)
        {
            /* dont have name, show url link */
            
            /* have name, show name */
            memset(subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
            
            if (url_len > MAX_SUBMENU_CHARACTERS-1)
            {
                /* researve 3 char for "..." and 1 char for null terminate */
                mmi_ucs2ncpy((CHAR*)subMenuDataPtrs[i], (CHAR*)history_url.url, MAX_SUBMENU_CHARACTERS-4);        
                mmi_ucs2cat((CHAR*)subMenuDataPtrs[i], (CHAR*)L"...");
            }
            else
            {
                /* 1 char for null terminate */                
                mmi_ucs2ncpy((CHAR*)subMenuDataPtrs[i], (CHAR*)history_url.url, MAX_SUBMENU_CHARACTERS-1);  
            }
        }
        else
        {
            /* have name, show name */
            
            memset(subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);

            if (name_len > MAX_SUBMENU_CHARACTERS-1)
            {
                /* researve 3 char for "..." and 1 char for null terminate */
                mmi_ucs2ncpy((CHAR*)subMenuDataPtrs[i], (CHAR*)history_url.name, MAX_SUBMENU_CHARACTERS-4);        
                mmi_ucs2cat((CHAR*)subMenuDataPtrs[i], (CHAR*)L"...");
            }
            else
            {
                /* 1 char for null terminate */
                mmi_ucs2ncpy((CHAR*)subMenuDataPtrs[i], (CHAR*)history_url.name, MAX_SUBMENU_CHARACTERS-1);  
            }
        }

        index ++;
    }

    if (index == 0)
    {
        /* if no history - popup */
        mmi_medply_plst_popup_simple_with_string(get_string(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE);
        mmi_frm_scrn_close(GRP_ID_MEDPLY_LIST_BOOKMARK, SCR_ID_MEDPLY_LIST_HISTORY_URL);
        return;
    }

    for (i = 0; i < index; i++)
    {
        item_icons[i] = (U16)(IMG_GLOBAL_L1 + i);
    }

    RegisterHighlightHandler(mmi_medply_plst_ui_highlight_hdlr);

    
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    ShowCategory53Screen(
        STR_ID_MEDPLY_HISTORY,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        index,
        subMenuDataPtrs,
        item_icons,
        NULL,
        0,
        0,
        gui_buffer);
    
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_medply_bookmark_tap_callback);
#endif

    
    SetCenterSoftkeyFunction(mmi_medply_bookmark_history_option_initiate_play, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_medply_bookmark_entry_history_option, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_medply_plst_gobackhistory, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bookmark_entry_predefined_url
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_bookmark_entry_predefined_url(void)
{
#ifdef __MMI_MEDIA_PLAYER_STREAM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 index;
    S16 error;
    S32 url_len;
    S32 server_name_len;
    U16 item_icons[16]; 
    U8 *gui_buffer;    
    #ifdef __MMI_MEDIA_PLAYER_STREAM__
    U8 *predef_p = NULL;
    nvram_ef_medply_video_predefined_url_struct *predef_url_list[NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_COUNT];
    #endif
    MMI_BOOL entry_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    media_get_ext_buffer(MOD_MMI, (void **)&predef_p, NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_SIZE);

    for (i = 0 ; i < NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_COUNT; i++)
    {
        predef_url_list[i] = (nvram_ef_medply_video_predefined_url_struct *)(predef_p + (sizeof(nvram_ef_medply_video_predefined_url_struct)) * i);
    }
    
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_LIST_BOOKMARK, SCR_ID_MEDPLY_LIST_HISTORY_DEF_URL, NULL, mmi_medply_bookmark_entry_predefined_url, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }    
    gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_LIST_BOOKMARK, SCR_ID_MEDPLY_LIST_HISTORY_DEF_URL);

    ReadRecord(
        NVRAM_EF_MEDPLY_PREDEFINED_URL_LID, 
        1,  /* id start from 1 */ 
        (void*)predef_url_list[0], 
        NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_SIZE, 
        &error);

    index = 0;
    for (i = 0 ; i < NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_COUNT; i++)
    {
        url_len = mmi_ucs2strlen((CHAR*)predef_url_list[i]->url);
        server_name_len = mmi_ucs2strlen((CHAR*)predef_url_list[i]->name);
        
        if (url_len == 0 || server_name_len == 0)
        {
            break;
        }

        memset(subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);
        /* copy char - 1 to keep null terminate */
        mmi_ucs2ncpy((CHAR*)subMenuDataPtrs[i], (CHAR*)predef_url_list[i]->name, MAX_SUBMENU_CHARACTERS-1);
        index++;
            
    }
    if (predef_p)
    {
        media_free_ext_buffer(MOD_MMI, (void**)&predef_p);
    }
    if (index == 0)
    {
        /* 
         * this may happend when customer didnt config nvram for predefined url,
         * but turn on display predefined compile option
         */
        ASSERT(0);
    }

    for (i = 0; i < index; i++)
    {
        item_icons[i] = (U16)(IMG_GLOBAL_L1 + i);
    }

    RegisterHighlightHandler(mmi_medply_plst_ui_highlight_hdlr);

    
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    wgui_list_menu_enable_access_by_shortcut();
    ShowCategory53Screen(
        STR_ID_MEDPLY_PLST_PREDEFINEDURL,
        GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        index,
        subMenuDataPtrs,
        item_icons,
        NULL,
        0,
        0,
        gui_buffer);
    
    SetCenterSoftkeyFunction(mmi_medply_predefined_url_lsk_hdlr, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_medply_predefined_url_lsk_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_medply_plst_gobackhistory, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_predefined_url_lsk_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_predefined_url_lsk_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ef_medply_video_predefined_url_struct predef_url_list[NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_COUNT];    
    S16 error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if is in flight mode, do not connect to WAP browser */
    
    if (srv_mode_switch_is_network_service_available() == MMI_FALSE)
    {
        mmi_medply_plst_popup_simple_with_string(get_string(STR_ID_MEDPLY_PLST_NOTIFY_FLIGHT_MODE), MMI_EVENT_ERROR);  
        return;
    }
    
    ReadRecord(
        NVRAM_EF_MEDPLY_PREDEFINED_URL_LID, 
        1,    /* id start from 1 */ 
        (void*)&predef_url_list, 
        NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_SIZE, 
        &error);
    
#ifdef BROWSER_SUPPORT
    wap_start_browser(WAP_BROWSER_GOTO_URL, (PU8)predef_url_list[plst_cntx_p->list_ui.highlight].url);
#endif

}
#endif


#define __EXTERN_INTERFACE
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_module_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
S32 mmi_medply_plst_module_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_KURO_SUPPORT__
    U8 drv_letter;
    S16 err;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /*bql*/
    if(NULL == plst_cntx_p)    
    {   
        plst_cntx_p = (mmi_medply_plst_cntx_struct*)kal_adm_alloc(g_medply.adm_id_p, sizeof(mmi_medply_plst_cntx_struct));
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ASM_ALLOCATE, plst_cntx_p, sizeof(mmi_medply_plst_cntx_struct), __LINE__);
        if (plst_cntx_p == NULL)
        {
            return MEDPLY_PLST_ERR_NO_MEMORY;
        }
    }
    memset(plst_cntx_p, 0, sizeof(mmi_medply_plst_cntx_struct));
#ifdef __MMI_KURO_SUPPORT__
    mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_DEFAULT_STORAGE, &plst_cntx_p->default_storage);
#else
    ReadValue(NVRAM_MEDPLY_PREFER_LIST, &drv_letter, DS_BYTE, &err);
    if (FS_GetDevStatus(drv_letter, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        plst_cntx_p->default_storage = (U8)SRV_FMGR_PUBLIC_DRV;
    }
    else
    {
        plst_cntx_p->default_storage = drv_letter;
    }
 #endif

    plst_cntx_p->browser_list_p = NULL;
    plst_cntx_p->editor.editor_type = 0;

    memset(&(plst_cntx_p->list_ui), 0, sizeof(mmi_medply_dynamic_list_data_struct));
    memset(&(plst_cntx_p->current_list), 0, sizeof(mmi_medply_plst_struct));

    file_unplayed_counter = 0;
    is_file_played = MMI_TRUE;
    all_file_issue = MMI_TRUE;
    browser_all_audio = MMI_FALSE;
    browser_all_video = MMI_FALSE;
    in_add_to_mode = MMI_FALSE;
    from_main_scr = MMI_FALSE; // change feature MAUI_02610488
    storage_change_entry = NULL;
    mmi_medply_plst_all_media_list_init(MMI_FALSE);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_module_deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_medply_plst_module_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (NULL == plst_cntx_p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        return;
    }

    /* check current list state. */
    if (plst_cntx_p->list_loaded)
    {
        /*need set media type to NONE, to avoid states not change to IDLE.*/
        g_medply.media_type = MEDPLY_TYPE_NONE;
        mmi_medply_stop_playing();
        FS_Close(plst_cntx_p->current_list.fs_hdlr);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->current_list.fs_hdlr ,__LINE__);
        memset(&(plst_cntx_p->current_list), 0, sizeof(mmi_medply_plst_struct));
        mmi_medply_plst_clear_context_variables();
    }

    
    if (plst_cntx_p->browser_list_p)
    {
        /* Close the file handle of browse list if there is a browse list open */
        if (plst_cntx_p->browser_list_p->fs_hdlr > FS_NO_ERROR)
        {
            FS_Close(plst_cntx_p->browser_list_p->fs_hdlr);
        }
        kal_adm_free(g_medply.adm_id_p, plst_cntx_p->browser_list_p);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE, plst_cntx_p->browser_list_p, __LINE__);
        plst_cntx_p->browser_list_p = NULL;
    }

    if (plst_cntx_p)
    { 
        kal_adm_free(g_medply.adm_id_p, plst_cntx_p); 
        plst_cntx_p = NULL;
    }
    
    browser_all_audio = MMI_FALSE;
    browser_all_video = MMI_FALSE;
    in_add_to_mode = MMI_FALSE;
    /*memset(plst_cntx_p, 0, sizeof(mmi_medply_plst_cntx_struct));*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_increase_played_counter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_medply_plst_increase_played_counter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_reset_played_counter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_medply_plst_reset_played_counter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_load_last
 * DESCRIPTION
 *  
 * PARAMETERS      
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_medply_plst_load_last(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type last_path[MEDPLY_MAX_PATH_LEN];
    S32 ret = MEDPLY_PLST_NO_ERROR;
    S32 last_pick_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_plst_clear_context_variables();
    
    memset(&(plst_cntx_p->current_list), 0, sizeof(mmi_medply_plst_struct));
    plst_cntx_p->list_loaded = MMI_FALSE;
    
    if (mmi_medply_plst_get_last_path(last_path))
    {
        if (last_path[0] != 0 &&
            FS_GetAttributes(last_path) >= FS_NO_ERROR)
        {
            ret = mmi_medply_plst_open_internal(last_path, &(plst_cntx_p->current_list));
                
            if (ret >= 0)
            {
                plst_cntx_p->list_loaded = MMI_TRUE;
                last_pick_index = mmi_medply_plst_get_last_index();
                if (plst_cntx_p->current_list.total == 0)
                {
                    last_pick_index = -1;
                }
                else if (last_pick_index >= plst_cntx_p->current_list.total)
                {
                    last_pick_index = 0;
                }
                
                mmi_medply_plst_set_start(last_pick_index);
                mmi_medply_plst_set_pick_index(last_pick_index);
                
                if (0 > mmi_medply_plst_apply_picked_file())
                {
                    plst_cntx_p->list_loaded = MMI_FALSE;
                }
            }
        }

        if (plst_cntx_p->list_loaded == MMI_FALSE)
        {
            FS_Close(plst_cntx_p->current_list.fs_hdlr);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->current_list.fs_hdlr ,__LINE__);
            memset(&(plst_cntx_p->current_list), 0, sizeof(mmi_medply_plst_struct));
            plst_cntx_p->list_loaded = MMI_FALSE;
            mmi_medply_plst_clear_context_variables();
        }
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_entry_now_playing
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_entry_now_playing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (NULL == plst_cntx_p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        return;
    }
    browser_now_playing = MMI_TRUE;
    
    ret = mmi_ucs2nicmp((CHAR *) MMI_MEDPLY_ALL_AUDIO_LIST, (CHAR *) plst_cntx_p->current_list.title, MEDPLY_MAX_FILE_LEN);
    if (ret == 0)
    {
        browser_all_audio = MMI_TRUE;
    }
    else
    {
        ret = mmi_ucs2nicmp((CHAR *) MMI_MEDPLY_ALL_VIDEO_LIST, (CHAR *) plst_cntx_p->current_list.title, MEDPLY_MAX_FILE_LEN);
        if (ret == 0)
        {
            browser_all_video = MMI_TRUE;
        }
    }
        
    if (!plst_cntx_p->list_loaded)
    {
        memset(&(plst_cntx_p->current_list), 0, sizeof(mmi_medply_plst_struct));
        mmi_medply_plst_entry_playlist_internal();
    }
    else
    {
        mmi_medply_plst_entry_playlist_internal();
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_entry_listmgr
 * DESCRIPTION
 *  entry function of list manager screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_entry_listmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PU8 gui_buffer = NULL;
    mmi_medply_dynamic_list_data_struct* ui = &(plst_cntx_p->list_ui);
#ifdef __MMI_KURO_SUPPORT__
    S32 result;
#endif
    MMI_BOOL entry_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_medply_plst_storage_check())
    {
        storage_change_entry = mmi_medply_plst_entry_listmgr;
        return;
    }
    
    mmi_medply_plst_ui_reset_cntx();
    ui->total = mmi_medply_plst_listmgr_list_all();
    
    mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_LIST_MGR, mmi_medply_plst_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_LIST_MGR, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    entry_ret = mmi_frm_scrn_enter(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_MGR, NULL, mmi_medply_plst_entry_listmgr, MMI_FRM_UNKNOW_SCRN);
        
    if (!entry_ret)
    {
        return;
    }    
        
    if (!ui->total)
    {
        mmi_str_id str_id;
#ifdef MMI_MEDPLY_PLST_VIDEO_INTEGRATED
        str_id = STR_ID_MEDPLY_MY_PLAYLIST;
#else
        str_id = STR_ID_MEDPLY_MUSIC_PLAYLIST;
#endif

    #ifndef __MMI_WGUI_DISABLE_CSK__
        EnableCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
    #endif
        ShowCategory52Screen(
            str_id,
            GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            0,
            NULL,
            NULL,
            NULL,
            1,
            0,
            NULL);
        ClearKeyEvents();

    #ifdef __MMI_KURO_SUPPORT__
        SetCenterSoftkeyFunction(mmi_medply_plst_listmgr_create_part1, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_medply_plst_listmgr_create_part1, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_medply_plst_gobackhistory, KEY_EVENT_UP);
    #else
        
        SetCenterSoftkeyFunction(mmi_medply_plst_listmgr_entry_option, KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_medply_plst_listmgr_entry_option, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_medply_plst_gobackhistory, KEY_EVENT_UP);
    #endif
    }
    else
    {
        mmi_str_id str_id;
#ifdef MMI_MEDPLY_PLST_VIDEO_INTEGRATED
        str_id = STR_ID_MEDPLY_MY_PLAYLIST;
#else
        str_id = STR_ID_MEDPLY_MUSIC_PLAYLIST;
#endif
        gui_buffer = mmi_frm_scrn_get_gui_buf(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_MGR);
        
        RegisterHighlightHandler(mmi_medply_plst_ui_highlight_hdlr);
            
    #ifndef __MMI_WGUI_DISABLE_CSK__
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    #endif
        ShowCategory185Screen(
            str_id,
            GetRootTitleIcon(MENU_ID_MEDPLY_MAIN),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,			/* lsk */
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,    /* rsk */
            ui->total, 
            mmi_medply_plst_listmgr_get_item, 
            NULL, 
            ui->highlight,
            MMI_FALSE,
            NULL,
            gui_buffer);  
        ClearKeyEvents();

        SetCenterSoftkeyFunction(mmi_medply_plst_listmgr_open, KEY_EVENT_UP);
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_medply_plst_listmgr_tap_callback);
#endif
        SetLeftSoftkeyFunction(mmi_medply_plst_listmgr_entry_option, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_medply_plst_gobackhistory, KEY_EVENT_UP);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_entry_all_audio
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_entry_all_audio(void)
{
#if defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_medply_plst_storage_check())
    {
        storage_change_entry = mmi_medply_plst_entry_all_audio;
        return;
    }

    browser_all_audio = MMI_TRUE;
    g_gid_browser_list = GRP_ID_MEDPLY_LIST_BROWSER;
    mmi_medply_plst_listmgr_open();
#endif /* __MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__ */
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_entry_all_video
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_entry_all_video(void)
{
#if defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_medply_plst_storage_check())
    {
        storage_change_entry = mmi_medply_plst_entry_all_video;
        return;
    }

    browser_all_video = MMI_TRUE;
    g_gid_browser_list = GRP_ID_MEDPLY_LIST_BROWSER;
    mmi_medply_plst_listmgr_open();
#endif /* __MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_all_media_list_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  reset_f:        MMI_TRUE - always clean the all media list and re-create
 *                  MMI_FALSE - create the all media list if not exist
 * RETURNS
 *  
 *****************************************************************************/
static S32 mmi_medply_plst_all_media_list_init(MMI_BOOL reset_f)
{
#if defined(__MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = FS_NO_ERROR;
    UI_character_type path[MEDPLY_MAX_PATH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    kal_wsprintf(path, "%c:\\%w",plst_cntx_p->default_storage, MMI_MEDPLY_DEFAULT_FOLDER);
    /* check default playlist folder. */
    ret  = FS_GetAttributes(path);
    if (ret >= 0 && !(ret & FS_ATTR_DIR))
    {
        FS_Delete(path);
    }

    ret = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);
    kal_wsprintf(path, "%c:\\%w\\",plst_cntx_p->default_storage, MMI_MEDPLY_DEFAULT_FOLDER);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_OPEN,ret ,__LINE__);
    if (ret < FS_NO_ERROR)
    {
        ret = FS_CreateDir(path);
        if (ret < FS_NO_ERROR)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ALL_TRACKS_INIT, ret, __LINE__);
            return ret;
        }
        else
        {
            ret = FS_NO_ERROR;
            FS_SetAttributes(path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
        }
    }
    else
    {
        FS_Close(ret);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,ret ,__LINE__);
        ret = FS_NO_ERROR;
    }

    /* should not be browsered at the same scenario */
    MMI_ASSERT(!(browser_all_audio && browser_all_video)); 
    
    if (browser_all_audio || (!browser_all_audio && !browser_all_video))
    {
        kal_wsprintf(
            path, 
            "%c:\\%w\\%w%w",
            plst_cntx_p->default_storage, 
            MMI_MEDPLY_DEFAULT_FOLDER,
            MMI_MEDPLY_ALL_AUDIO_LIST,
            MMI_MEDPLY_DEFAULT_LIST_EXT);
        ret = FS_GetAttributes(path);
        if (ret < FS_NO_ERROR)
        {
            ret = mmi_medply_plst_listmgr_create_part3(path);
            FS_SetAttributes(path, FS_GetAttributes(path) | FS_ATTR_HIDDEN);
        }
        else
        {
            if (reset_f)
            {
                ret = FS_Delete(path);
                if (ret >= FS_NO_ERROR)
                {
                    ret = mmi_medply_plst_listmgr_create_part3(path);
                }

                if (ret < FS_NO_ERROR)
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ALL_TRACKS_INIT, ret, __LINE__);
                    return ret;
                }
            }
            else
            {
                FS_SetAttributes(path, (U8)(ret | FS_ATTR_HIDDEN));
            }
        }
    }
    if (ret < FS_NO_ERROR)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ALL_TRACKS_INIT, ret, __LINE__);
        return ret;
    }
    
    if (browser_all_video || (!browser_all_audio && !browser_all_video))
    {
        kal_wsprintf(
            path, 
            "%c:\\%w\\%w%w",
            plst_cntx_p->default_storage, 
            MMI_MEDPLY_DEFAULT_FOLDER,
            MMI_MEDPLY_ALL_VIDEO_LIST,
            MMI_MEDPLY_DEFAULT_LIST_EXT);
        ret = FS_GetAttributes(path);
        if (ret < FS_NO_ERROR)
        {
            ret = mmi_medply_plst_listmgr_create_part3(path);
            FS_SetAttributes(path, FS_GetAttributes(path) | FS_ATTR_HIDDEN);
        }
        else
        {
            if (reset_f)
            {
                ret = FS_Delete(path);
                if (ret >= FS_NO_ERROR)
                {
                    ret = mmi_medply_plst_listmgr_create_part3(path);
                }
                
                if (ret < FS_NO_ERROR)
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ALL_TRACKS_INIT, ret, __LINE__);
                    return ret;
                }
            }
            else
            {
                FS_SetAttributes(path, (U8)(ret | FS_ATTR_HIDDEN));
            }
        }
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ALL_TRACKS_INIT, ret, __LINE__);
    return ret;
#else

    return 0;
#endif /* __MMI_MEDIA_PLAYER_PLST_MULTIPLE_ALL_TRACKS__ */
    
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_curr_get_total
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
S32 mmi_medply_plst_curr_get_total(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	if (NULL == plst_cntx_p)
	{
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
		return 0;
	}
    if (mmi_medply_plst_curr_is_empty())
    {
        return 0;
    }
    else
    {
        return plst_cntx_p->current_list.total;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_ui_reset_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
S32 mmi_medply_plst_curr_get_curr_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (NULL == plst_cntx_p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        return -1;
    }
    if (mmi_medply_plst_curr_is_empty())
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        return -1;
    }
    else
    {
        return plst_cntx_p->current_list.pick_index;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_curr_is_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_plst_curr_is_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (NULL == plst_cntx_p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        return MMI_FALSE;
    }
    if (0 > FS_GetAttributes((PU16)plst_cntx_p->current_list.path))
    {
        plst_cntx_p->list_loaded = MMI_FALSE;
    }

    return plst_cntx_p->list_loaded;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_curr_is_empty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_medply_plst_curr_is_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(NULL == plst_cntx_p)
	{
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
		return MMI_TRUE;
	}
    if (plst_cntx_p->current_list.total > 0)
    {
        ret = MMI_FALSE;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_path
 * DESCRIPTION
 *  retrieve file path and name from play list file
 * PARAMETERS
 *  fullfilename        [IN]        
 *  index               [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_plst_get_path(UI_string_type fullfilename, S32 index)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (NULL == plst_cntx_p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        return 0;
    }
    if (in_browser_mode)
    {
        if (!browser_now_playing)
        {
            /* run in background. */
            return mmi_medply_plst_browser_get_path(fullfilename, index);
        }
        else
        {
            /* run in foreground. */
            return mmi_medply_plst_curr_get_path(fullfilename, index);
        }
    }
    else
    {
        if (plst_cntx_p->list_loaded)
        {
            /* run in background. */
            return mmi_medply_plst_curr_get_path(fullfilename, index);
        }
        else
        {
            return mmi_medply_plst_browser_get_path(fullfilename, index);
        }
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_notify_file_not_available
 * DESCRIPTION
 *  If the file is not available, 
 *  should call this API to avoid popup infinit when repeat mode ON.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_notify_file_not_available(mmi_medply_fail_play_enum type)
{
    /* added for eservice issue - 02017632 */
    
    /* file will not played and popup error, when this func is called */
    is_file_played = MMI_FALSE;
    
    /* increase unplayed counter */
    file_unplayed_counter++;
    
    if (MEDPLY_FAIL_PLAY_TYPE_FILE_ISSUE != type)
    {
        all_file_issue = MMI_FALSE;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_NOTIFY_FILE_NOT_AVAILABLE, file_unplayed_counter, type, all_file_issue);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_apply_picked_file
 * DESCRIPTION
 *  apply pick index to get full filename and title
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
S32 mmi_medply_plst_apply_picked_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __DRM_SUPPORT__
    U8 result;
#endif
    UI_character_type wchar_filename[MEDPLY_MAX_FILE_LEN];
    UI_character_type ext[MEDPLY_MAX_EXT_LEN];
    S32 ret = 0;
    U16 file_format = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == plst_cntx_p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        return -1;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_APPLY_PICKED_FILE, plst_cntx_p->current_list.pick_index, plst_cntx_p->current_list.fs_hdlr);

#if defined(__MMI_MEDIA_PLAYER_AUDIO__)
    g_medply.is_audio_seekable = MMI_TRUE;
#endif

#ifdef __MMI_VIDEO_SUBTITLE_SUPPORT__
    mmi_medply_settings_subtitle_iso_shutdown();
#endif

#if defined(__MMI_AUDIO_VOCAL_REMOVAL__)
    g_medply.vocal_removal = MMI_SETTINGS_VOCAL_REMOVAL_OFF;
#endif
#if defined(__MMI_AUDIO_PITCH_SHIFTING__)
    g_medply.pitch = MMI_SETTINGS_PITCH_SHIFTING_0;
#endif

    if (mmi_medply_plst_curr_is_empty())
    {
        mmi_medply_plst_clear_context_variables();
        return MEDPLY_PLST_ERR_EMPTY_LIST;
    }
    else if(g_medply.selected_button == MEDPLY_MAIN_DISABLED)
    {
        g_medply.selected_button = MEDPLY_MAIN_PLAY;  
    }

    ret = mmi_medply_plst_curr_get_path(g_medply.filefullpath, plst_cntx_p->current_list.pick_index);
    if (ret < 0)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_APPLY_FAILED, ret);

        /* reset current list context. */
        FS_Close(plst_cntx_p->current_list.fs_hdlr);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->current_list.fs_hdlr ,__LINE__);
        kal_mem_set(&(plst_cntx_p->current_list), 0, sizeof(mmi_medply_plst_struct));
        plst_cntx_p->list_loaded = MMI_FALSE;
        /* reset relative variables in media player context. */
        mmi_medply_clear_play_seconds();
        g_medply.media_format = MEDPLY_FORMAT_NONE;
        g_medply.media_type = MEDPLY_TYPE_NONE;

        g_medply.seekable = MMI_FALSE;
        g_medply.need_to_build_cache = MMI_FALSE;

        g_medply.duration = 0;

    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        g_medply.audio_build_cache_process = 0 ;
        g_medply.audio_cached_duration = 0 ;
        /*refresh cache file*/
        mmi_medply_refresh_cache();
    #endif
    #if defined(__MMI_MEDIA_PLAYER_VIDEO__) && defined(__MMI_A2DP_SUPPORT__)
        g_medply.bt_connect_fail = MMI_FALSE;
    #endif

    #ifdef __MMI_AUDIO_VOCAL_REMOVAL__
        g_medply.vocal_removal_enabled = MMI_FALSE;
    #endif
        g_medply.filefullpath[0] = 0;
 
        g_medply.selected_button = MEDPLY_MAIN_DISABLED;
        mmi_medply_main_screen_set_file_path(NULL, MMI_TRUE);
        return ret;
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_APPLY_SUCSESS,plst_cntx_p->current_list.pick_index ,__LINE__);
        mmi_medply_util_extract_filename(wchar_filename, g_medply.filefullpath);
        mmi_medply_util_split_filename_ext(wchar_filename, g_medply.title, ext);

        file_format = mmi_medply_util_is_target_support_format(ext);

        /* do more check with file path and media format. */
        if (file_format == MEDPLY_FORMAT_NONE || file_format >= MEDPLY_FORMAT_TOTAL)
        {
            /* media table error. */
            ret = MEDPLY_PLST_ERR_UNSUPPORT_FORMAT;
            MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_MEDPLY_PLST_APPLY_FAILED, ret);
            if (!mmi_frm_group_is_present(GRP_ID_MEDPLY_LIST_GEN))
            {
                mmi_medply_plst_write_back_to_file(&(plst_cntx_p->current_list));
                FS_Close(plst_cntx_p->current_list.fs_hdlr);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->current_list.fs_hdlr ,__LINE__);
                kal_mem_set(&(plst_cntx_p->current_list), 0, sizeof(mmi_medply_plst_struct));
                /* reset current list context. */
                plst_cntx_p->list_loaded = MMI_FALSE;
            }
            mmi_medply_plst_save_last_index(-1);
            /* reset relative variables in media player context. */
            mmi_medply_clear_play_seconds();
            g_medply.media_format = MEDPLY_FORMAT_NONE;
            g_medply.media_type = MEDPLY_TYPE_NONE;
            g_medply.seekable = MMI_FALSE;
            g_medply.need_to_build_cache = MMI_FALSE;

            g_medply.duration = 0;

        #if defined(__MMI_MEDIA_PLAYER_VIDEO__) && defined(__MMI_A2DP_SUPPORT__)
            g_medply.bt_connect_fail = MMI_FALSE;
    	#endif        

        #ifdef __MMI_AUDIO_VOCAL_REMOVAL__
            g_medply.vocal_removal_enabled = MMI_FALSE;
        #endif
            g_medply.filefullpath[0] = 0;
        #ifdef __MMI_MEDIA_PLAYER_AUDIO__
            g_medply.audio_build_cache_process = 0;
            g_medply.audio_cached_duration = 0 ;
            /*refresh cache file*/
            mmi_medply_refresh_cache();
        #endif
            g_medply.selected_button = MEDPLY_MAIN_DISABLED;
            mmi_medply_main_screen_set_file_path(NULL, MMI_TRUE);
            
            return ret;
        }

        g_medply.media_format = (mmi_medply_media_format_enum)media_file_info_table[file_format].file_format;
        g_medply.media_type = (mmi_medply_media_type_enum)media_file_info_table[file_format].file_type;
        g_medply.need_to_build_cache = (media_file_info_table[file_format].need_build_cache > 0 ? MMI_TRUE : MMI_FALSE);
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        g_medply.audio_build_cache_process = 0 ;
        g_medply.audio_cached_duration = 0 ;
        /*refresh cache file*/
        mmi_medply_refresh_cache();
    #endif
        g_medply.seekable = MMI_TRUE;
        g_medply.build_cache_failed = MMI_FALSE;


    #if defined(__MMI_MEDIA_PLAYER_STREAM__) || defined(__MMI_MEDIA_PLAYER_VIDEO__)    
        g_medply.track = MDI_VIDEO_TRACK_NONE;
    #endif

    #ifdef __MMI_KURO_SUPPORT__
        mmi_medply_kuro_get_informaion();
    #endif
        g_medply.duration = 0; 
        if (g_medply.media_type == MEDPLY_TYPE_AUDIO)
        {
            if (mdi_audio_get_duration(g_medply.filefullpath, (U32*)(&g_medply.duration)) != MDI_AUDIO_SUCCESS)
            {
                g_medply.duration = 0; 
            }
        }
        else if(g_medply.media_type == MEDPLY_TYPE_VIDEO)
        {
            if (mdi_audio_get_mp4_duration(g_medply.filefullpath, (U32*)(&g_medply.duration)) != MDI_AUDIO_SUCCESS)
            {
                g_medply.duration = 0;
            }
        }
        else
        {
            g_medply.duration = 0;
        }

        if (g_medply.duration == 0)
        {
            g_medply.seekable = MMI_FALSE;
        }
        else
        {
            g_medply.seekable = MMI_TRUE;
        }

    #ifdef __DRM_SUPPORT__
        result = mmi_medply_drm_valide_right((PU16)g_medply.filefullpath);
        if(result ==2)
        {
            g_medply.seekable = MMI_FALSE;
        }
        g_medply.DRM_consumed = MMI_FALSE;
    #endif

    #if defined(__MMI_MEDIA_PLAYER_AUDIO__)
        if(g_medply.media_type == MEDPLY_TYPE_AUDIO)
        {
            MMI_BOOL audio_seekable = MMI_TRUE;
            audio_seekable = mdi_audio_is_file_seekable(g_medply.filefullpath);
            if(!audio_seekable)
            {
                g_medply.is_audio_seekable = MMI_FALSE;
                g_medply.seekable = MMI_FALSE;
            }
        }
    #endif

        g_medply.progress_speed = mmi_medply_determine_progress_speed(g_medply.duration); 
        mmi_medply_plst_save_last_index(plst_cntx_p->current_list.pick_index);
        mmi_medply_clear_play_seconds();
    #ifdef __MMI_MEDIA_PLAYER_AUDIO__
        /*refresh cache file*/
        mmi_medply_refresh_cache();
    #endif
        mmi_medply_main_screen_set_file_path(NULL,MMI_TRUE);
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_do_pick
 * DESCRIPTION
 *  pick a song from play list
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_medply_plst_do_pick(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_medply_plst_struct* list = &(plst_cntx_p->current_list);

    U32 seek_count = 0;
    U8 repeat_mode = 0;
    U8 random_mode = 0;
    S32 result = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == plst_cntx_p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        return -1;
    }
    if (mmi_medply_plst_curr_is_empty())
    {
        return -1;
    }

    MMI_ASSERT(mmi_medply_settings_read_value(
		MMI_MEDPLY_SETTINGS_REPEAT, 
		&repeat_mode));

    /* added for eservice issue - 02017632 */
    if (MMI_FALSE == is_file_played)
    {
        if ((MMI_MEDPLY_REPEAT_ALL == repeat_mode &&
            file_unplayed_counter >= list->total) ||
            repeat_mode == MMI_MEDPLY_REPEAT_ONE)
		{
			/* should stop when unplayed file match total number in repeat all mode */
			result = -1;
			file_unplayed_counter = 0;
			is_file_played = MMI_TRUE;
            if (all_file_issue)
            {
                /* only all file issue should popup to notify user*/
                mmi_medply_plst_post_event_to_main(EVT_ID_MEDPLY_POPUP_ALL_FILE_FAIL, NULL);
            }
            else
            {
                all_file_issue = MMI_TRUE;
            }
            return result;
        }
		else
		{
			is_file_played = MMI_TRUE;
		}
	}
    else
    {
        /* last play file is available should reset unplayed counter */
        file_unplayed_counter = 0;
        all_file_issue = MMI_TRUE;
    }
    


    if (repeat_mode == MMI_MEDPLY_REPEAT_ONE)
    {
        result = list->pick_index;
    }
    else
    {
        MMI_ASSERT(mmi_medply_settings_read_value(
                  MMI_MEDPLY_SETTINGS_SHUFFULE, 
                  &random_mode));
        
        if (random_mode)
        {
            if (list->pick_count >= list->total)
            {
                /* reached end of list. */
                mmi_medply_plst_set_start(-1);	/* reset all context. */
				
                if (repeat_mode == MMI_MEDPLY_REPEAT_OFF)
                {
					mmi_medply_plst_set_pick_index(0);
                    result = -1;	/* stop! */
                    file_unplayed_counter = 0;
                    is_file_played = MMI_TRUE;
                    all_file_issue = MMI_TRUE;
                }
                else if (repeat_mode == MMI_MEDPLY_REPEAT_ALL)
                {
                    /* need find an empty slot. */
                    i = (list->pick_index + (rand() % list->total) + 1) % list->total;
            
                    while (1)
                    {
                        i = (i + 1) % list->total;
        
                        if (IsBitSetOn(i, list->bitset))
                        {
                            MMI_ASSERT(seek_count < list->total);
                            seek_count++;
                        }
                        else
                        {
                            break;
                        }
                    }
					mmi_medply_plst_set_pick_index(i);                    
                    result = i;
                }
                else
                {
                    MMI_ASSERT(repeat_mode != MMI_MEDPLY_REPEAT_ONE);
                }
            }
            else
            {
                /* need find an empty slot. */
                i = (list->pick_index + (rand() % list->total) + 1) % list->total;
            
                while (1)
                {
                    i = (i + 1) % list->total;
        
                    if (IsBitSetOn(i, list->bitset))
                    {
                        MMI_ASSERT(seek_count < list->total);
                        seek_count++;
                    }
                    else
                    {
                        break;
                    }
                }
                mmi_medply_plst_set_pick_index(i);
                result = i;/* begin from first one. */ 
            }
        }
        else
        {
            /* "pick_count" is useless when random = OFF. */
            if (list->pick_index == list->total - 1)
            {
                /* reached end of list. */
                mmi_medply_plst_set_start(-1);/* reset all context. */
                mmi_medply_plst_set_pick_index(0);
				if (repeat_mode == MMI_MEDPLY_REPEAT_OFF)
                {
                    result = -1;	/* stop! */
                    file_unplayed_counter = 0;
                    is_file_played = MMI_TRUE;
                    all_file_issue = MMI_TRUE;
                }
                else if (repeat_mode == MMI_MEDPLY_REPEAT_ALL)
                {
                    result = 0;	/* begin from first one. */ 
                }
                else
                {
                    MMI_ASSERT(repeat_mode != MMI_MEDPLY_REPEAT_ONE);
                }
            }
            else
            {
				list->pick_index++;
                mmi_medply_plst_set_pick_index(list->pick_index);
                result = list->pick_index;
            }
        }        
    }

    return result;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_pick_next
 * DESCRIPTION
 *  pick the next song from play list
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_medply_plst_pick_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    mmi_medply_plst_struct* list = &(plst_cntx_p->current_list);

    U32 seek_count = 0;
    U8 random_mode = 0;
    S32 result = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == plst_cntx_p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        return -1;
    }
    /* added for eservice issue - 02017632 */
    /* reset played couter and flag if user press next/pre */
    is_file_played = MMI_TRUE;
    all_file_issue = MMI_TRUE;
    file_unplayed_counter = 0;
        
    if (mmi_medply_plst_curr_is_empty())
    {
        return -1;
    }

    MMI_ASSERT(mmi_medply_settings_read_value(
              MMI_MEDPLY_SETTINGS_SHUFFULE, 
              &random_mode));

    if (random_mode)
    {
        if (list->pick_count >= list->total)
        {
            /* reached end of list. */
            mmi_medply_plst_set_start(-1);/* reset all context. */
        }        
        
        /* need find an empty slot. */
        i = (list->pick_index + (rand() % list->total) + 1) % list->total;
        
        while (1)
        {
            i = (i + 1) % list->total;
        
            if (IsBitSetOn(i, list->bitset))
            {
                MMI_ASSERT(seek_count < list->total);
                seek_count++;
            }
            else
            {
                break;
            }
        }
        mmi_medply_plst_set_pick_index(i);
        result = i;	/* begin from first one. */ 
        
    }
    else
    {
        /* "pick_count" is useless when random = OFF. */
        if (list->pick_index == list->total - 1)
        {
            /* reached end of list. */
            mmi_medply_plst_set_start(-1);	/* reset all context. */
        }
        
        list->pick_index++;
		mmi_medply_plst_set_pick_index(list->pick_index);
        result = list->pick_index;
    }        
    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_pick_prev
 * DESCRIPTION
 *  pick the previous song from play list
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_medply_plst_pick_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    mmi_medply_plst_struct* list = &(plst_cntx_p->current_list);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == plst_cntx_p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
		return -1;
    }
    /* added for eservice issue - 02017632 */
    /* reset played couter and flag if user press next/pre */
    is_file_played = MMI_TRUE;
    all_file_issue = MMI_TRUE;
    file_unplayed_counter = 0;
    
    if (list->total == 0)
    {
        return -1;
    }
    if (list->pick_index == 0)
    {
        index = list->total - 1;
    }
    else
    {
        index = list->pick_index - 1;
    }
    mmi_medply_plst_set_start(index);
    mmi_medply_plst_set_pick_index(index);
    return list->pick_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_set_pick_index
 * DESCRIPTION
 *  seek play list index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_medply_plst_set_pick_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plst_struct* list = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == plst_cntx_p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        return 0;
    }
    list = &(plst_cntx_p->current_list);
    list->pick_index = index;
    if (!IsBitSetOn(index, list->bitset))
    {
        SetBitSet(index, list->bitset);
        list->pick_count++;
    }
    /* alway return no error */
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_set_start
 * DESCRIPTION
 *  seek play list index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_set_start(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_plst_struct* list = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == plst_cntx_p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        return;
    }
    list = &(plst_cntx_p->current_list);
    memset(list->bitset, 0, MMI_MEDPLY_MAX_BITSET_SIZE);
    list->pick_index = index;
    list->pick_count = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_set_start
 * DESCRIPTION
 *  seek play list index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_medply_plst_get_current_details(mmi_medply_details_for_display_struct* details_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    PU8 meta_parser_buffer = NULL;
    U32 meta_parser_hdlr = 0;
    U8 meta_parser_ret = 0;
    U8 meta_return_value = 0;
    
    meta_tag_music_info_struct* music_info_p = NULL;
    meta_tag_sync_lyc_info_struct* lrc_info_p = NULL;
    meta_tag_img_info_struct* image_info_p = NULL;
    U8* artwork_buffer = details_data->artwork.buffer;
    U32 artwork_size = details_data->artwork.buffer_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    if (g_medply.adm_id_p == NULL || g_medply.mem_pool_p == NULL)
    {
        return MEDPLY_PLST_ERR_NO_MEMORY;
    }

    memset(details_data, 0, sizeof(mmi_medply_details_for_display_struct));
    
    meta_parser_buffer = kal_adm_alloc(g_medply.adm_id_p, META_TAG_PARSE_MIN_SIZE);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ALLOCATE_SCR_MEM, meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, __LINE__);
    if (meta_parser_buffer == NULL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS, __LINE__);
        ret = MEDPLY_PLST_ERR_NO_MEMORY;
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ASM_ALLOCATE,meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, __LINE__);
        
        meta_parser_ret = meta_parser_create(meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, &meta_parser_hdlr);

        if (meta_parser_ret > 0 && meta_parser_ret < META_TAG_ERR_TOTAL)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS_ERROR, meta_parser_hdlr, __LINE__);
            ret = META_ERROR(meta_parser_ret);
        }
        else
        {
            meta_return_value = meta_parse_file(meta_parser_hdlr, (kal_uint16*)g_medply.filefullpath);

            if (meta_return_value != 0)
            {
                CHAR* dot = NULL;
                UI_character_type filename[MEDPLY_MAX_FILE_LEN];
                CHAR* filename_ptr = NULL;
                
                filename_ptr = mmi_ucs2rchr((CHAR*)g_medply.filefullpath, (U16)(L'\\'));
                if (filename_ptr == NULL)
                {
                    filename[0] = 0;
                }
                else
                {
                    if (mmi_medply_plst_curr_title_is_short())
                    {
                        mmi_chset_mixed_text_to_ucs2_str(
                          (U8*)filename,
                          ((MEDPLY_MAX_FILE_LEN - 1)) * ENCODING_LENGTH,
                          (U8*)(filename_ptr + 2),
                          (mmi_chset_enum)PhnsetGetDefEncodingType());
                    }
                    else
                    {
                        mmi_ucs2ncpy((CHAR*)filename, (CHAR*)(filename_ptr + 2), (MEDPLY_MAX_FILE_LEN - 1));
                    }
                }
                /* cut off extended name. */
                dot = mmi_ucs2rchr((CHAR*)filename, (U16)L'.');
                if (dot != NULL)	/* all supported media file should has an extended name! */
                {
                    *(dot + 1) = 0;
                    *dot = 0;
                }
                mmi_ucs2ncpy((CHAR*)details_data->title, (CHAR*)filename, MMI_MEDPLY_MAX_TITLE_LEN);	
              
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS_ERROR, meta_return_value, __LINE__);
                ret = META_ERROR(meta_return_value);
            }
            else
            {
                meta_return_value = meta_get_music_info(meta_parser_hdlr, &music_info_p);
                ret = meta_return_value;
                if (META_TAG_ERR_NONE == meta_return_value)
                {
                    if (music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_size > 0 && 
                      (music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_size >> 1) <= META_TAG_FRAME_MAX_LEN)
                    {
                        mmi_ucs2ncpy((CHAR*)details_data->artist, 
                               (CHAR*)music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data,
                               MMI_MEDPLY_MAX_ARTISRT_LEN - 1);
                        details_data->artist[(music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_size >> 1)] = 0;
                    }

                    if (music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data_size > 0 && 
                      (music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data_size >> 1) <= META_TAG_FRAME_MAX_LEN)
                    {
                        mmi_ucs2ncpy((CHAR*)details_data->album, 
                               (CHAR*)music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data,
                               MMI_MEDPLY_MAX_ALBUM_LEN - 1);
                        details_data->album[(music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data_size >> 1)] = 0;
                    }
                
                    if (music_info_p->txt_frame[META_TAG_FRAME_TITLE].data_size > 0 && 
                      (music_info_p->txt_frame[META_TAG_FRAME_TITLE].data_size >> 1) <= META_TAG_FRAME_MAX_LEN)
                    {
                        mmi_ucs2ncpy((CHAR*)details_data->title, 
                               (CHAR*)music_info_p->txt_frame[META_TAG_FRAME_TITLE].data,
                               MMI_MEDPLY_MAX_TITLE_LEN - 1);
                        details_data->title[(music_info_p->txt_frame[META_TAG_FRAME_TITLE].data_size >> 1)] = 0;
                    }
                }
                if (mmi_ucs2strlen((CHAR*) details_data->title) <= 0)
                {
                    CHAR* dot = NULL;
                    UI_character_type filename[MEDPLY_MAX_FILE_LEN];
                    /* try to cut off filename as title. */
                    mmi_medply_util_extract_filename(filename, g_medply.filefullpath);
                    /* cut off extended name. */
                    dot = mmi_ucs2rchr((CHAR*)filename, (U16)L'.');
                    if (dot != NULL)	/* all supported media file should has an extended name! */
                    {
                        *(dot + 1) = 0;
                        *dot = 0;
                    }
                    mmi_ucs2ncpy((CHAR*)details_data->title, (CHAR*)filename, MMI_MEDPLY_MAX_TITLE_LEN);	
                }
            
                meta_return_value = meta_get_attach_cover_info(meta_parser_hdlr, &image_info_p);
                if (META_TAG_ERR_NONE == meta_return_value)
                {
                    details_data->artwork.mime_type = image_info_p->mime_type;
                    details_data->artwork.size = image_info_p->data_size;

                    if (artwork_buffer != NULL && image_info_p->data_size > 0 && image_info_p->mime_type < META_TAG_IMG_TOTAL)
                    {
                        if (artwork_size < image_info_p->data_size || artwork_size == 0)
                        {
                            details_data->artwork.size = 0;
                            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS_ERROR,image_info_p->data_size,__LINE__);
                        }
                        else
                        {
                            meta_return_value = meta_get_attach_cover_data(
                                meta_parser_hdlr,
                                (kal_uint8*)artwork_buffer,
                                artwork_size);
                            if (meta_return_value > 0 && meta_return_value < META_TAG_ERR_TOTAL)
                            {
                                details_data->artwork.size = 0;
                                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS_ERROR,image_info_p->data_size,__LINE__);
                            }
                        }
                    }
                    else
                    {
                        details_data->artwork.size = 0;
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS_ERROR,image_info_p->data_size,__LINE__);
                    }
                }
                meta_return_value = meta_get_sync_lyrics_info(meta_parser_hdlr, &lrc_info_p);
                if (META_TAG_ERR_NONE == meta_return_value)
                {
                    details_data->lyrics.lrc_type = lrc_info_p->lyc_type;
                    details_data->lyrics.size = lrc_info_p->data_size;
                }
            }
            meta_parser_release(meta_parser_hdlr);
        }
        kal_adm_free(g_medply.adm_id_p, meta_parser_buffer);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE,meta_parser_buffer, __LINE__);
        meta_parser_buffer = NULL;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_set_start
 * DESCRIPTION
 *  seek play list index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_medply_plst_get_current_artwork(void* buffer, U32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    PU8 meta_parser_buffer = NULL;
    U32 meta_parser_hdlr = 0;
    U8 meta_parser_ret = 0;
    U8 meta_return_value = 0;
    meta_tag_img_info_struct* image_info_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    meta_parser_buffer = kal_adm_alloc(g_medply.adm_id_p, META_TAG_PARSE_MIN_SIZE);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ALLOCATE_SCR_MEM, meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, __LINE__);
    if (meta_parser_buffer == NULL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS, __LINE__);
        ret = MEDPLY_PLST_ERR_NO_MEMORY;;
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ASM_ALLOCATE, meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, __LINE__);
        
        meta_parser_ret = meta_parser_create(meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, &meta_parser_hdlr);

        if (meta_parser_ret > 0 && meta_parser_ret < META_TAG_ERR_TOTAL)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS_ERROR,meta_parser_hdlr,__LINE__);
            ret = META_ERROR(meta_parser_ret);
        }
        else
        {
            meta_return_value = meta_parse_file(meta_parser_hdlr, (kal_uint16*)g_medply.filefullpath);

            if (meta_return_value > 0 && meta_return_value < META_TAG_ERR_TOTAL)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS_ERROR, meta_return_value,__LINE__);
                ret = META_ERROR(meta_return_value);
            }
            else
            {
                meta_get_attach_cover_info(meta_parser_hdlr, &image_info_p);

                if (buffer_size < image_info_p->data_size || buffer_size == 0)
                {
                    ret = MEDPLY_PLST_ERR_NO_MEMORY;
                }
                else
                {
                    meta_return_value = meta_get_attach_cover_data(
                    meta_parser_hdlr, (kal_uint8*)buffer, buffer_size);
                    if (meta_return_value > 0 && meta_return_value < META_TAG_ERR_TOTAL)
                    {
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS_ERROR,meta_return_value,__LINE__);
                        ret = META_ERROR(meta_return_value);
                    }
                }
            }
            meta_parser_release(meta_parser_hdlr);
        }
        kal_adm_free(g_medply.adm_id_p, meta_parser_buffer);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE,meta_parser_buffer, __LINE__);
        meta_parser_buffer = NULL;
    }
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_set_start
 * DESCRIPTION
 *  seek play list index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 mmi_medply_plst_get_current_lyrics(void* buffer, U32 buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    PU8 meta_parser_buffer = NULL;
    U32 meta_parser_hdlr = 0;
    U8 meta_parser_ret = 0;
    U8 meta_return_value = 0;
    meta_tag_sync_lyc_info_struct* lrc_info_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    meta_parser_buffer = kal_adm_alloc(g_medply.adm_id_p, META_TAG_PARSE_MIN_SIZE);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ALLOCATE_SCR_MEM, meta_parser_buffer,META_TAG_PARSE_MIN_SIZE, __LINE__);
    if (meta_parser_buffer == NULL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS, __LINE__);
        ret = MEDPLY_PLST_ERR_NO_MEMORY;;
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ASM_ALLOCATE,meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, __LINE__);
        
        meta_parser_ret = meta_parser_create(meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, &meta_parser_hdlr);

        if (meta_parser_ret > 0 && meta_parser_ret < META_TAG_ERR_TOTAL)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS_ERROR,meta_parser_hdlr,__LINE__);
            ret = META_ERROR(meta_parser_ret);
        }
        else
        {
            meta_return_value = meta_parse_file(meta_parser_hdlr, (kal_uint16*)g_medply.filefullpath);

            if (meta_return_value > 0 && meta_return_value < META_TAG_ERR_TOTAL)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS_ERROR,meta_return_value,__LINE__);
                ret = META_ERROR(meta_return_value);
            }
            else
            {
                meta_get_sync_lyrics_info(meta_parser_hdlr, &lrc_info_p);

                if (buffer_size < lrc_info_p->data_size)
                {
                    ret = MEDPLY_PLST_ERR_NO_MEMORY;
                }
                else
                {
                    meta_return_value = meta_get_sync_lyrics_data(
                                  meta_parser_hdlr, (kal_uint8*)buffer, buffer_size);
                    if (meta_return_value > 0 && meta_return_value < META_TAG_ERR_TOTAL)
                    {
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS_ERROR,meta_return_value,__LINE__);
                        ret = META_ERROR(meta_return_value);
                    }
                }
            }
            meta_parser_release(meta_parser_hdlr);
        }
        kal_adm_free(g_medply.adm_id_p, meta_parser_buffer);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE,meta_parser_buffer, __LINE__);
        meta_parser_buffer = NULL;
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_curr_title_is_short
 * DESCRIPTION
 *  seek play list index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_medply_plst_curr_title_is_short(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == plst_cntx_p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        return MMI_FALSE;
    }


    if (2 == plst_cntx_p->current_list.header.index[plst_cntx_p->current_list.pick_index].is_active)
    {
        return MMI_TRUE;
    }
    else if (1 == plst_cntx_p->current_list.header.index[plst_cntx_p->current_list.pick_index].is_active)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_FALSE;
    }

}

#define __FTE_TAP


#ifdef __MMI_MEDIA_PLAYER_STREAM__
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_bookmark_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_bookmark_tap_callback(mmi_tap_type_enum tap_type,S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
    {
        return;
    }

    mmi_medply_bookmark_history_option_initiate_play();
    
    return;
}
#endif
#endif

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_listmgr_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_listmgr_tap_callback(mmi_tap_type_enum tap_type,S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
    {
        return;
    }

    mmi_medply_plst_listmgr_open();
    
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_tap_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_tap_callback(mmi_tap_type_enum tap_type,S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM)
    {
        return;
    }

    mmi_medply_plst_option_initiate_play();
    
    return;
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_hilite_hdlr_init
 * DESCRIPTION
 *  menu item hilitet handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_hilite_hdlr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}


#define __EDITOR_CODE

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_editor_close_function
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_editor_close_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_multiple_close(g_gid_medply, mmi_frm_scrn_get_active_id(),
                                 MMI_FALSE, 2, 0, 0);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_entry_editor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_entry_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 title_id = 0;
    U32 input_type = 0;
    S32 limit = 0;
    MMI_ID parent_id = GRP_ID_INVALID;
    MMI_ID cui_gid = GRP_ID_INVALID;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_ENTRY_EDITOR,plst_cntx_p->editor.editor_type, plst_cntx_p->editor.limit);

    input_type = IMM_INPUT_TYPE_URL;
    limit = plst_cntx_p->editor.limit;
    title_id = plst_cntx_p->editor.editor_title_id;
    parent_id = plst_cntx_p->editor.parent_id;

    if (parent_id != GRP_ID_INVALID)
    {
        mmi_frm_group_create(parent_id, GRP_ID_MEDPLY_LIST_EDITOR, mmi_medply_plst_proc, (void*)NULL); 
    }
    else
    {
        mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_LIST_EDITOR, mmi_medply_plst_proc, (void*)NULL); 
    }
    mmi_frm_group_enter(GRP_ID_MEDPLY_LIST_EDITOR, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    switch (plst_cntx_p->editor.editor_type)
    {
        case MMI_MEDPLY_EDITOR_NEW:
        case MMI_MEDPLY_EDITOR_RENAME:
        {
            WCHAR path[MEDPLY_MAX_PATH_LEN];
            WCHAR ext[MEDPLY_MAX_EXT_LEN];
            kal_wsprintf(path, "%c:\\%w\\", (CHAR)plst_cntx_p->default_storage, MMI_MEDPLY_DEFAULT_FOLDER);
            kal_wsprintf(ext, "%w", MMI_MEDPLY_DEFAULT_LIST_EXT_NO_DOT);
            limit = SRV_FMGR_PATH_MAX_LEN - mmi_ucs2strlen((CHAR *)path) - mmi_ucs2strlen((CHAR *)ext) - 2; /* 2: dot + truncate*/
                
            cui_gid = cui_filename_editor_create(GRP_ID_MEDPLY_LIST_EDITOR, 
                plst_cntx_p->editor.editor_buffer, 
                sizeof(plst_cntx_p->editor.editor_buffer), 
                limit, path, ext);
            if (cui_gid != GRP_ID_INVALID)
            {
                cui_filename_editor_set_parent_data(cui_gid, plst_cntx_p->editor.editor_type);
                cui_filename_editor_set_title(cui_gid, title_id, GetRootTitleIcon(MENU_ID_MEDPLY_MAIN));
                cui_filename_editor_run(cui_gid);
            }
            else
            {   
                mmi_medply_plst_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE),MMI_EVENT_FAILURE);
            }
            break;
        }
        case MMI_MEDPLY_EDITOR_EDIT_URL:
        {
            cui_gid = cui_fseditor_create(GRP_ID_MEDPLY_LIST_EDITOR);
            if (cui_gid != GRP_ID_INVALID)
            {
                cui_fseditor_set_text(cui_gid,
                    plst_cntx_p->editor.editor_buffer,
                    sizeof(plst_cntx_p->editor.editor_buffer),
                    limit);
                cui_fseditor_set_title(cui_gid,title_id,GetRootTitleIcon(MENU_ID_MEDPLY_MAIN));
                cui_fseditor_set_input_method(cui_gid,input_type,NULL,0);
                cui_fseditor_run(cui_gid);
            }
            else
            {   
                mmi_medply_plst_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
            }
            break;
        }
        default:
            break;
            
    }
}

#define __DETAILS


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_details_set_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_details_set_value(MMI_ID inline_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_icons[MEDPLY_PLST_INLINE_ITEM_NUM];
    U16 item_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/***********************************set string******************************************/
    /* filename. */           
    if (plst_cntx_p->details_cntx.preview_data_p->filename[0] != 0)
    {
        cui_inline_set_value(inline_id, FILENAME_TYPE_ITEM, plst_cntx_p->details_cntx.preview_data_p->filename);
        cui_inline_set_item_attributes(inline_id, FILENAME_TYPE_ITEM, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
#if defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_FTE_SUPPORT_SLIM__)
        item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
        item_icons[item_count++] = 0;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_FILENAME;
        item_icons[item_count++] = 0;
#endif
    }
    else
    {
        cui_inline_delete_item(inline_id,  FILENAME_TYPE_CAPTION);
        cui_inline_delete_item(inline_id,  FILENAME_TYPE_ITEM);
    }
    /* title. */
    if (plst_cntx_p->details_cntx.preview_data_p->title[0] != 0)
    {
        cui_inline_set_value(inline_id, TILTE_TYPE_ITEM, plst_cntx_p->details_cntx.preview_data_p->title);
        cui_inline_set_item_attributes(inline_id, TILTE_TYPE_ITEM, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
#if defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_FTE_SUPPORT_SLIM__)
        item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
        item_icons[item_count++] = 0;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_TITLE;
        item_icons[item_count++] = 0;
#endif
    }
    else
    {
        cui_inline_delete_item(inline_id,  TILTE_TYPE_CAPTION);
        cui_inline_delete_item(inline_id,  TILTE_TYPE_ITEM);
    }
    /* artist. */
    if (plst_cntx_p->details_cntx.preview_data_p->artist[0] != 0)
    {
        cui_inline_set_value(inline_id, ARTIST_TYPE_ITEM, plst_cntx_p->details_cntx.preview_data_p->artist);
        cui_inline_set_item_attributes(inline_id, ARTIST_TYPE_ITEM, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
#if defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_FTE_SUPPORT_SLIM__)
        item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
        item_icons[item_count++] = 0;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_ARTIST;
        item_icons[item_count++] = 0;
#endif
    }
    else
    {
        cui_inline_delete_item(inline_id,  ARTIST_TYPE_CAPTION);
        cui_inline_delete_item(inline_id,  ARTIST_TYPE_ITEM);
    }
    /* album. */
    if (plst_cntx_p->details_cntx.preview_data_p->album[0] != 0)
    {
        cui_inline_set_value(inline_id, ALBUM_TYPE_ITEM, plst_cntx_p->details_cntx.preview_data_p->album);
        cui_inline_set_item_attributes(inline_id, ALBUM_TYPE_ITEM, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
#if defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_FTE_SUPPORT_SLIM__)
        item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
        item_icons[item_count++] = 0;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_ALBUM;
        item_icons[item_count++] = 0;
#endif
    }
    else
    {
        cui_inline_delete_item(inline_id,  ALBUM_TYPE_CAPTION);
        cui_inline_delete_item(inline_id,  ALBUM_TYPE_ITEM);
    }
    /* author. */
    if (plst_cntx_p->details_cntx.preview_data_p->author[0] != 0)
    {
        cui_inline_set_value(inline_id, AUTHOR_TYPE_ITEM, plst_cntx_p->details_cntx.preview_data_p->author);
        cui_inline_set_item_attributes(inline_id, AUTHOR_TYPE_ITEM, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
#if defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_FTE_SUPPORT_SLIM__)
        item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
        item_icons[item_count++] = 0;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_AUTHOR;
        item_icons[item_count++] = 0;
#endif
    }
    else
    {
        cui_inline_delete_item(inline_id,  AUTHOR_TYPE_CAPTION);
        cui_inline_delete_item(inline_id,  AUTHOR_TYPE_ITEM);
    }
    /* genre */
    if (plst_cntx_p->details_cntx.preview_data_p->genre[0] != 0)
    {
        cui_inline_set_value(inline_id, GENRE_TYPE_ITEM, plst_cntx_p->details_cntx.preview_data_p->genre);
        cui_inline_set_item_attributes(inline_id, GENRE_TYPE_ITEM, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
#if defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_FTE_SUPPORT_SLIM__)
        item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
        item_icons[item_count++] = 0;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_GENRE;
        item_icons[item_count++] = 0;
#endif
    }
    else
    {
        cui_inline_delete_item(inline_id,  GENRE_TYPE_CAPTION);
        cui_inline_delete_item(inline_id,  GENRE_TYPE_ITEM);
    }

    /* copyrights. */
    if (plst_cntx_p->details_cntx.preview_data_p->copyrights[0] != 0)
    {
        cui_inline_set_value(inline_id, COPYRIGHTS_TYPE_ITEM, plst_cntx_p->details_cntx.preview_data_p->copyrights);
        cui_inline_set_item_attributes(inline_id, COPYRIGHTS_TYPE_ITEM, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
#if defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_FTE_SUPPORT_SLIM__)
        item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
        item_icons[item_count++] = 0;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_COPYRIGHTS;
        item_icons[item_count++] = 0;
#endif
    }
    else
    {
        cui_inline_delete_item(inline_id,  COPYRIGHTS_TYPE_CAPTION);
        cui_inline_delete_item(inline_id,  COPYRIGHTS_TYPE_ITEM);
    }
    /* description. */
    if (plst_cntx_p->details_cntx.preview_data_p->description[0] != 0)
    {
        cui_inline_set_value(inline_id, DESCRIPTION_TYPE_ITEM, plst_cntx_p->details_cntx.preview_data_p->description);
        cui_inline_set_item_attributes(inline_id, DESCRIPTION_TYPE_ITEM, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
#if defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_FTE_SUPPORT_SLIM__)
        item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
        item_icons[item_count++] = 0;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_DESCRIPTION;
        item_icons[item_count++] = 0;
#endif
    }
    else
    {
        cui_inline_delete_item(inline_id,  DESCRIPTION_TYPE_CAPTION);
        cui_inline_delete_item(inline_id,  DESCRIPTION_TYPE_ITEM);
    }

    /* year. */
    if (plst_cntx_p->details_cntx.preview_data_p->year[0] != 0)
    {
        cui_inline_set_value(inline_id, YEAR_TYPE_ITEM, plst_cntx_p->details_cntx.preview_data_p->year);
        cui_inline_set_item_attributes(inline_id, YEAR_TYPE_ITEM, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
#if defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_FTE_SUPPORT_SLIM__)
        item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
        item_icons[item_count++] = 0;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_YEAR;
        item_icons[item_count++] = 0;
#endif
    }
    else
    {
        cui_inline_delete_item(inline_id,  YEAR_TYPE_CAPTION);
        cui_inline_delete_item(inline_id,  YEAR_TYPE_ITEM);
    }
    /* track number. */
    if (plst_cntx_p->details_cntx.preview_data_p->track_num[0] != 0)
    {
        cui_inline_set_value(inline_id, TACKNUM_TYPE_ITEM, plst_cntx_p->details_cntx.preview_data_p->track_num);
        cui_inline_set_item_attributes(inline_id, TACKNUM_TYPE_ITEM, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
#if defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_FTE_SUPPORT_SLIM__)
        item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
        item_icons[item_count++] = 0;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_TRACK_NUM;
        item_icons[item_count++] = 0;
#endif
    }
    else
    {
        cui_inline_delete_item(inline_id,  TACKNUM_TYPE_CAPTION);
        cui_inline_delete_item(inline_id,  TACKNUM_TYPE_ITEM);
    }
    /* duration */
    if (plst_cntx_p->details_cntx.preview_data_p->duration[0] != 0)
    {
        cui_inline_set_value(inline_id, DURATION_TYPE_ITEM, plst_cntx_p->details_cntx.preview_data_p->duration);
        cui_inline_set_item_attributes(inline_id, DURATION_TYPE_ITEM, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
#if defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_FTE_SUPPORT_SLIM__)
        item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
        item_icons[item_count++] = 0;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_DURATION;
        item_icons[item_count++] = 0;
#endif
    }
    else
    {
        cui_inline_delete_item(inline_id,  DURATION_TYPE_CAPTION);
        cui_inline_delete_item(inline_id,  DURATION_TYPE_ITEM);
    }
    /* size */
    if (plst_cntx_p->details_cntx.preview_data_p->size[0] != 0)
    {
        cui_inline_set_value(inline_id, SIZE_TYPE_ITEM, plst_cntx_p->details_cntx.preview_data_p->size);
        cui_inline_set_item_attributes(inline_id, SIZE_TYPE_ITEM, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
#if defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_FTE_SUPPORT_SLIM__)
        item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
        item_icons[item_count++] = 0;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_SIZE;
        item_icons[item_count++] = 0;
#endif
    }
    else
    {
        cui_inline_delete_item(inline_id,  SIZE_TYPE_CAPTION);
        cui_inline_delete_item(inline_id,  SIZE_TYPE_ITEM);
    }
    /* quality */
    if (plst_cntx_p->details_cntx.preview_data_p->quality[0] != 0)
    {
        cui_inline_set_value(inline_id, QUALITY_TYPE_ITEM, plst_cntx_p->details_cntx.preview_data_p->quality);
        cui_inline_set_item_attributes(inline_id, QUALITY_TYPE_ITEM, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
#if defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_FTE_SUPPORT_SLIM__)
        item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
        item_icons[item_count++] = 0;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_QUALITY;
        item_icons[item_count++] = 0;
#endif
    }
    else
    {
        cui_inline_delete_item(inline_id,  QUALITY_TYPE_CAPTION);
        cui_inline_delete_item(inline_id,  QUALITY_TYPE_ITEM);
    }
    /* channel */
    if (plst_cntx_p->details_cntx.preview_data_p->channel_num[0] != 0)
    {
        cui_inline_set_value(inline_id, CHANNELNUM_TYPE_ITEM, plst_cntx_p->details_cntx.preview_data_p->channel_num);
        cui_inline_set_item_attributes(inline_id, CHANNELNUM_TYPE_ITEM, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
#if defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_FTE_SUPPORT_SLIM__)
        item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
        item_icons[item_count++] = 0;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_CHANNEL;
        item_icons[item_count++] = 0;
#endif
    }
    else
    {
        cui_inline_delete_item(inline_id,  CHANNELNUM_TYPE_CAPTION);
        cui_inline_delete_item(inline_id,  CHANNELNUM_TYPE_ITEM);
    }
    /* local. */
    if (plst_cntx_p->details_cntx.preview_data_p->local[0] != 0)
    {
        cui_inline_set_value(inline_id, LOCAL_TYPE_ITEM, plst_cntx_p->details_cntx.preview_data_p->local);
        cui_inline_set_item_attributes(inline_id, LOCAL_TYPE_ITEM, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW);
#if defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_FTE_SUPPORT_SLIM__)
        item_icons[item_count++] = IMG_GLOBAL_L1 + (item_count)/2;
        item_icons[item_count++] = 0;
#else
        item_icons[item_count++] = IMG_ID_MEDPLY_PLST_DETAILS_LOCAL;
        item_icons[item_count++] = 0;
#endif
    }
    else
    {
        cui_inline_delete_item(inline_id,  LOCAL_TYPE_CAPTION);
        cui_inline_delete_item(inline_id,  LOCAL_TYPE_ITEM);
    }
    /***********************************set icon******************************************/
    cui_inline_set_icon_list(inline_id, &item_icons[0]);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_details_preview_delete_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_param       [?]        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 mmi_medply_plst_details_preview_delete_hdlr(void* in_param)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plst_cntx_p->details_cntx.preview_data_p)
    {
        kal_adm_free(g_medply.adm_id_p, plst_cntx_p->details_cntx.preview_data_p);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE,plst_cntx_p->details_cntx.preview_data_p, __LINE__);
        plst_cntx_p->details_cntx.preview_data_p = NULL;
   }

    memset(&(plst_cntx_p->details_cntx), 0, sizeof(mmi_medply_details_struct));
    
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_details_fill_common_info
 * DESCRIPTION
 *  get common info from file system, filemgr and MDI.
 * PARAMETERS
 *  media_path	
 * RETURNS
 *  S32		should handle this value if return error!!! 
 *****************************************************************************/
static S32 mmi_medply_plst_details_fill_common_info(UI_string_type in_media_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* filename_p = NULL;
    S32 ret = 0;
    FS_HANDLE handle = -1;
    U32 duration = 0;
    U32 file_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* get file size. */
    handle = DRM_open_file((PU16)in_media_path, FS_READ_ONLY, DRM_PERMISSION_PLAY);
    
    if (handle < 0)
    {
        ret = handle;
    }
    else
    {
        DRM_file_size(handle, &file_size);
        DRM_close_file(handle);

        /* fill "size". */
        if (file_size >= 1024*1024)
        {
            file_size = file_size/1024 ;
            kal_wsprintf((kal_wchar*)plst_cntx_p->details_cntx.preview_data_p->size, "%d.%dM", file_size / 1024, (file_size % 1024) / 103);
        }
        else if (file_size >= 1024)
        {
            kal_wsprintf((kal_wchar*)plst_cntx_p->details_cntx.preview_data_p->size, "%d.%dK", file_size / 1024, (file_size % 1024) / 103);
        }
        else
        {
            kal_wsprintf((kal_wchar*)plst_cntx_p->details_cntx.preview_data_p->size, "%dB", file_size);
        }

        /* fill "local". */
        srv_fmgr_drv_get_name((U8)((CHAR)(in_media_path[0])), (WCHAR*)((CHAR*)plst_cntx_p->details_cntx.preview_data_p->local), (MEDPLY_MAX_FILE_LEN - 1));

        /* fill "filename". */
        filename_p = mmi_ucs2rchr((CHAR*)in_media_path, (U16)L'\\');

        if (filename_p != NULL)
        {
            filename_p += 2;

            mmi_ucs2ncpy((CHAR*)plst_cntx_p->details_cntx.preview_data_p->filename, (CHAR*)filename_p, MEDPLY_MAX_FILE_LEN - 1);
            srv_fmgr_path_hide_extension((WCHAR*)((CHAR*)plst_cntx_p->details_cntx.preview_data_p->filename));
        }

        /* fill "duration" if it is empty. */
        if (plst_cntx_p->details_cntx.preview_data_p->duration[0] == 0)
        {
            mdi_audio_get_duration(in_media_path, &duration);
            if (duration)
            {
                duration += 500;
                duration /= 1000;
                if (duration < 3600)
                {
                    U16 min = duration / 60;
                    U16 sec = duration % 60;
                    
                    kal_wsprintf((kal_wchar*)plst_cntx_p->details_cntx.preview_data_p->duration, "%02d:%02d", min, sec);
                }
                else
                {
                    U16 hour = duration / 3600;
                    U16 min = (duration - hour * 3600) / 60;
                    U16 sec = (duration - hour * 3600) % 60;
                    
                    kal_wsprintf((kal_wchar*)plst_cntx_p->details_cntx.preview_data_p->duration, "%d:%02d:%02d", hour, min, sec);
                }
            }
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_details_fill_audio_info
 * DESCRIPTION
 *  get audio info from meta parser.
 * PARAMETERS
 *  media_path
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_plst_details_fill_audio_info(UI_string_type in_media_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    PU8 meta_parser_buffer = NULL;
    U32 meta_parser_hdlr = 0;
    U8 meta_parser_ret = 0;
    U8 meta_return_value = 0;

    meta_tag_audio_info_struct* audio_info_p = NULL;
    MMI_BOOL audio_info_ready = MMI_FALSE;
    MMI_BOOL parser_ready = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* get audio info from meta parser. */
    meta_parser_buffer = (PU8)kal_adm_alloc(g_medply.adm_id_p, META_TAG_PARSE_MIN_SIZE);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ALLOCATE_SCR_MEM, meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, __LINE__);
    if (meta_parser_buffer == NULL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS, __LINE__);
        ret = MEDPLY_PLST_ERR_NO_MEMORY;
    }
    else
    {
       MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ASM_ALLOCATE,meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, __LINE__);

        /* create meta parser. */
        meta_parser_ret = meta_parser_create(meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, &meta_parser_hdlr);
        if (meta_parser_ret > 0 && meta_parser_ret < META_TAG_ERR_TOTAL)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS_ERROR,meta_parser_hdlr,__LINE__);
            ret = META_ERROR(meta_parser_ret);
        }
        else
        {
            parser_ready = MMI_TRUE;
            meta_return_value = meta_parse_file(meta_parser_hdlr, (kal_uint16*)in_media_path);
            if (meta_return_value != 0)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS_ERROR,meta_return_value,__LINE__);
                ret = META_ERROR(meta_return_value);
            }
            else
            {
                meta_return_value = meta_get_audio_info(meta_parser_hdlr, &audio_info_p);
                if (meta_return_value != 0)
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS_ERROR,meta_return_value,__LINE__);
                    ret = META_ERROR(meta_return_value);
                }
                else
                {
                    audio_info_ready = MMI_TRUE;
                }
            }
        }

        if (audio_info_ready)
        {
            if (audio_info_p->channel_number != 0)
            {
                if (audio_info_p->channel_number == 1)
                {
                    mmi_ucs2ncpy((CHAR*)plst_cntx_p->details_cntx.preview_data_p->channel_num, (CHAR*)GetString(STR_ID_MEDPLY_PLST_DETAILS_MONO), 20);
                }
                else
                {
                    mmi_ucs2ncpy((CHAR*)plst_cntx_p->details_cntx.preview_data_p->channel_num, (CHAR*)GetString(STR_ID_MEDPLY_PLST_DETAILS_STEREO), 20);
                }
            }
            
            if (audio_info_p->bits_rate > 0 || audio_info_p->sample_rate > 0)
            {
                UI_character_type temp[30];
                U16 bitrate_fraction_1, bitrate_fraction_2, bitrate_fraction_3;
                U16 samplerate_fraction_1, samplerate_fraction_2, samplerate_fraction_3;
            
                if (audio_info_p->bits_rate > 0)
                {
                    bitrate_fraction_1 = audio_info_p->bits_rate / 100;
                    bitrate_fraction_1 = bitrate_fraction_1 - (bitrate_fraction_1 / 10) * 10;
                    bitrate_fraction_2 = audio_info_p->bits_rate / 10;
                    bitrate_fraction_2 = bitrate_fraction_2 - (bitrate_fraction_2 / 10) * 10;
                    bitrate_fraction_3 = audio_info_p->bits_rate - (audio_info_p->bits_rate / 10) * 10 ;
                    if (bitrate_fraction_3)
                    {
                        kal_wsprintf((kal_wchar*)plst_cntx_p->details_cntx.preview_data_p->quality, "%d.%d%d%dkbps", audio_info_p->bits_rate / 1000, bitrate_fraction_1, bitrate_fraction_2, bitrate_fraction_3);
                    }
                    else if (bitrate_fraction_2)
                    {
                        kal_wsprintf((kal_wchar*)plst_cntx_p->details_cntx.preview_data_p->quality, "%d.%d%dkbps", audio_info_p->bits_rate / 1000, bitrate_fraction_1, bitrate_fraction_2);
                    }
                    else if (bitrate_fraction_1)
                    {
                        kal_wsprintf((kal_wchar*)plst_cntx_p->details_cntx.preview_data_p->quality, "%d.%dkbps", audio_info_p->bits_rate / 1000, bitrate_fraction_1);
                    }
                    else
                    {
                        kal_wsprintf((kal_wchar*)plst_cntx_p->details_cntx.preview_data_p->quality, "%dkbps", audio_info_p->bits_rate / 1000);
                    }
                    
                    if (audio_info_p->sample_rate > 0)
                    {
                        mmi_ucs2ncat((CHAR*)plst_cntx_p->details_cntx.preview_data_p->quality, (CHAR*)L" / ", 25);
                    }
                }
                
                if (audio_info_p->sample_rate > 0)
                {
                    samplerate_fraction_1 = audio_info_p->sample_rate / 100;
                    samplerate_fraction_1 = samplerate_fraction_1 - (samplerate_fraction_1 / 10) * 10;
                    samplerate_fraction_2 = audio_info_p->sample_rate / 10;
                    samplerate_fraction_2 = samplerate_fraction_2 - (samplerate_fraction_2 / 10) * 10;
                    samplerate_fraction_3 = audio_info_p->sample_rate - (audio_info_p->sample_rate / 10) * 10 ;

                    if (samplerate_fraction_3)
                    {
                        kal_wsprintf((kal_wchar*) temp, "%d.%d%d%dkHz", audio_info_p->sample_rate / 1000, samplerate_fraction_1, samplerate_fraction_2, samplerate_fraction_3);
                    }
                    else if (samplerate_fraction_2)
                    {
                        kal_wsprintf((kal_wchar*) temp, "%d.%d%dkHz", audio_info_p->sample_rate / 1000, samplerate_fraction_1, samplerate_fraction_2);
                    }
                    else if (samplerate_fraction_1)
                    {
                        kal_wsprintf((kal_wchar*) temp, "%d.%dkHz", audio_info_p->sample_rate / 1000, samplerate_fraction_1);
                    }
                    else
                    {
                        kal_wsprintf((kal_wchar*) temp, "%dkHz", audio_info_p->sample_rate / 1000);
                    }
                    mmi_ucs2ncat((CHAR*)plst_cntx_p->details_cntx.preview_data_p->quality, (CHAR*)temp, 25);
                }
            }

            if (audio_info_p->duration)
            {
                if (audio_info_p->duration < 3600)
                {
                    U16 min = audio_info_p->duration / 60;
                    U16 sec = audio_info_p->duration % 60;
                    
                    kal_wsprintf((kal_wchar*)plst_cntx_p->details_cntx.preview_data_p->duration, "%02d:%02d", min, sec);
                }
                else
                {
                    U16 hour = audio_info_p->duration / 3600;
                    U16 min = (audio_info_p->duration - hour * 3600) / 60;
                    U16 sec = (audio_info_p->duration - hour * 3600) % 60;
                    
                    kal_wsprintf((kal_wchar*)plst_cntx_p->details_cntx.preview_data_p->duration, "%d:%02d:%02d", hour, min, sec);
                }
            }
        }

        if (parser_ready)
        {
            meta_parser_release(meta_parser_hdlr);
        }
        kal_adm_free(g_medply.adm_id_p, meta_parser_buffer);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE,meta_parser_buffer, __LINE__);
        meta_parser_buffer = NULL;
    }

    return ret;
}

/*****************************************************************************
* FUNCTION
*  mmi_medply_util_string_convert
* DESCRIPTION	
*  convert string which got from meta parser.
* PARAMETERS
*  in_string       [IN]
*  in_string_size  [IN]
*  out_string      [OUT]
*  out_buff_size   [IN]
* RETURNS
*  S32
*****************************************************************************/
static S32 mmi_medply_util_string_convert(CHAR* in_string, S32 in_string_size, CHAR* out_string, S32 out_buff_size, U8 meta_encoding)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 out_string_len = 0;
    CHAR meta_data_buff[MEDPLY_MAX_PATH_SIZE];
    mmi_chset_enum encoding_type = MMI_CHSET_UCS2;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_set(meta_data_buff, 0, sizeof(meta_data_buff));
	
    kal_mem_cpy(meta_data_buff, in_string, in_string_size);
	
    if (meta_encoding != META_TAG_TEXT_ENCODING_UCS2)
    {
        encoding_type = mmi_chset_guess(
			meta_data_buff,
			in_string_size,
			CHSET_BASE,
			CHSET_GUESS_ALL);
		
       	out_string_len = mmi_chset_convert(
			encoding_type,
			MMI_CHSET_UCS2,
			(char*)meta_data_buff,
			(char*)out_string,
			out_buff_size);
		
        return out_string_len;
    }
    else
    {
        mmi_ucs2ncpy(out_string, meta_data_buff, (in_string_size>>1));
        return in_string_size;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_details_unprepare_data
 * DESCRIPTION
 *  free adm memory
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
static void mmi_medply_plst_details_unprepare_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (plst_cntx_p->details_cntx.preview_data_p)
    {
        kal_adm_free(g_medply.adm_id_p, plst_cntx_p->details_cntx.preview_data_p);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE,plst_cntx_p->details_cntx.preview_data_p, __LINE__);
        plst_cntx_p->details_cntx.preview_data_p = NULL;
    }

}
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_details_prepare_data
 * DESCRIPTION
 *  get data from meta parser/database.
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_plst_details_prepare_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    PU8 meta_parser_buffer = NULL;
    U32 meta_parser_hdlr = 0;
    U8 meta_parser_ret = 0;
    U8 meta_return_value = 0;
    meta_tag_music_info_struct* music_info_p = NULL;

    MMI_BOOL memory_ready = MMI_FALSE;
    MMI_BOOL parser_ready = MMI_FALSE;
    MMI_BOOL preview_buffer_ready = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* allocate memory for details data. */
    plst_cntx_p->details_cntx.preview_data_p = kal_adm_alloc(g_medply.adm_id_p, sizeof(mmi_medply_details_preview_struct));
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ALLOCATE_SCR_MEM, plst_cntx_p->details_cntx.preview_data_p, sizeof(mmi_medply_details_preview_struct), __LINE__);

    if (plst_cntx_p->details_cntx.preview_data_p == NULL)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS,__LINE__);
        ret = MEDPLY_PLST_ERR_NO_MEMORY;
    }
    else
    {
        preview_buffer_ready = MMI_TRUE;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ASM_ALLOCATE,plst_cntx_p->details_cntx.preview_data_p, sizeof(mmi_medply_details_preview_struct), __LINE__);
        memset(plst_cntx_p->details_cntx.preview_data_p, 0, sizeof(mmi_medply_details_preview_struct));

        meta_parser_buffer = kal_adm_alloc(g_medply.adm_id_p, META_TAG_PARSE_MIN_SIZE);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ALLOCATE_SCR_MEM, meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, __LINE__);

        if (meta_parser_buffer == NULL)
        {
            /* get memory failed! */
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS,__LINE__);
            ret = MEDPLY_PLST_ERR_NO_MEMORY;
        }
        else
        {
            memory_ready = MMI_TRUE;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ASM_ALLOCATE,meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, __LINE__);

            meta_parser_ret = meta_parser_create(meta_parser_buffer, META_TAG_PARSE_MIN_SIZE, &meta_parser_hdlr);

            if (meta_parser_ret > 0 && meta_parser_ret < META_TAG_ERR_TOTAL)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS_ERROR,meta_parser_hdlr,__LINE__);
                ret = META_ERROR(meta_parser_ret);
            }
            else
            {
                meta_return_value = meta_parse_file(meta_parser_hdlr, (kal_uint16*)plst_cntx_p->details_cntx.media_path);

                if (meta_return_value != 0)
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS_ERROR,meta_return_value,__LINE__);
                    ret = META_ERROR(meta_return_value);
                    meta_parser_release(meta_parser_hdlr);
                }
                else
                {
                    meta_return_value = meta_get_music_info(meta_parser_hdlr, &music_info_p);

                    if (meta_return_value != 0)
                    {
                        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_LIST_GET_CURRENT_DETAILS_ERROR,meta_return_value,__LINE__);
                        ret = META_ERROR(meta_return_value);
                        meta_parser_release(meta_parser_hdlr);
                    }
                    else
                    {
                        parser_ready = MMI_TRUE;
                    }
                }
            }
        }

        if (parser_ready)
        {
            /* get data from meta context. */
            if (music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_size > 0)
            {
				mmi_medply_util_string_convert(
					(CHAR*)music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data,
					music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_size,
					(CHAR*)plst_cntx_p->details_cntx.preview_data_p->artist,
					(S32)(MMI_MEDPLY_MAX_ARTISRT_LEN * ENCODING_LENGTH),
					music_info_p->txt_frame[META_TAG_FRAME_ARTIST].data_encoding);
            }

            if (music_info_p->txt_frame[META_TAG_FRAME_AUTHOR].data_size > 0)
            {
				mmi_medply_util_string_convert(
					(CHAR*)music_info_p->txt_frame[META_TAG_FRAME_AUTHOR].data,
					music_info_p->txt_frame[META_TAG_FRAME_AUTHOR].data_size,
					(CHAR*)plst_cntx_p->details_cntx.preview_data_p->author,
					(S32)(MMI_MEDPLY_MAX_AUTHOR_LEN * ENCODING_LENGTH),
                    music_info_p->txt_frame[META_TAG_FRAME_AUTHOR].data_encoding);
            }

            if (music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data_size > 0)
            {
				mmi_medply_util_string_convert(
					(CHAR*)music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data,
					music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data_size,
					(CHAR*)plst_cntx_p->details_cntx.preview_data_p->album,
					(S32)(MMI_MEDPLY_MAX_ALBUM_LEN * ENCODING_LENGTH),
					music_info_p->txt_frame[META_TAG_FRAME_ALBUM].data_encoding);
            }
            
            if (music_info_p->txt_frame[META_TAG_FRAME_TITLE].data_size > 0)
            {
				mmi_medply_util_string_convert(
					(CHAR*)music_info_p->txt_frame[META_TAG_FRAME_TITLE].data,
					music_info_p->txt_frame[META_TAG_FRAME_TITLE].data_size,
					(CHAR*)plst_cntx_p->details_cntx.preview_data_p->title,
					(S32)(MMI_MEDPLY_MAX_TITLE_LEN * ENCODING_LENGTH),
					music_info_p->txt_frame[META_TAG_FRAME_TITLE].data_encoding);
            }
            else
            {
                CHAR* dot = NULL;
                UI_character_type filename[MEDPLY_MAX_FILE_LEN];

                /* try to cut off filename as title. */
                mmi_medply_util_extract_filename(filename, plst_cntx_p->details_cntx.media_path);
                
                /* cut off extended name. */
                dot = mmi_ucs2rchr((CHAR*)filename, (U16)L'.');
                if (dot != NULL)	/* all supported media file should has an extended name! */
                {
                    *(dot + 1) = 0;
                    *dot = 0;
                }
                mmi_ucs2ncpy((CHAR*) plst_cntx_p->details_cntx.preview_data_p->title, (CHAR*) filename,MEDPLY_MAX_FILE_LEN - 1);
            }
            
            if (music_info_p->txt_frame[META_TAG_FRAME_COPYRIGHT].data_size > 0)
            {
				mmi_medply_util_string_convert(
					(CHAR*)music_info_p->txt_frame[META_TAG_FRAME_COPYRIGHT].data,
					music_info_p->txt_frame[META_TAG_FRAME_COPYRIGHT].data_size,
					(CHAR*)plst_cntx_p->details_cntx.preview_data_p->copyrights,
					(S32)(MMI_MEDPLY_MAX_COPYRIGHTS_LEN * ENCODING_LENGTH),
					music_info_p->txt_frame[META_TAG_FRAME_COPYRIGHT].data_encoding);
            }

            if (music_info_p->txt_frame[META_TAG_FRAME_GENRE].data_size > 0)
            {
				mmi_medply_util_string_convert(
					(CHAR*)music_info_p->txt_frame[META_TAG_FRAME_GENRE].data,
					music_info_p->txt_frame[META_TAG_FRAME_GENRE].data_size,
					(CHAR*)plst_cntx_p->details_cntx.preview_data_p->genre,
					(S32)(MMI_MEDPLY_MAX_GENRE_LEN * ENCODING_LENGTH),
					music_info_p->txt_frame[META_TAG_FRAME_GENRE].data_encoding);
            }
            
            if (music_info_p->txt_frame[META_TAG_FRAME_DESCRIPTION].data_size > 0)
            {
				mmi_medply_util_string_convert(
					(CHAR*)music_info_p->txt_frame[META_TAG_FRAME_DESCRIPTION].data,
					music_info_p->txt_frame[META_TAG_FRAME_DESCRIPTION].data_size,
					(CHAR*)plst_cntx_p->details_cntx.preview_data_p->description,
					(S32)(MMI_MEDPLY_MAX_DESCRIPTION_LEN * ENCODING_LENGTH),
					music_info_p->txt_frame[META_TAG_FRAME_DESCRIPTION].data_encoding);
            }
            if (music_info_p->year <= 9999 && music_info_p->year >= 0)
            {      
                kal_wsprintf((kal_wchar*)plst_cntx_p->details_cntx.preview_data_p->year, "%d", music_info_p->year);
            }
            else
            {
                plst_cntx_p->details_cntx.preview_data_p->year[0] = 0;
            }

            if (music_info_p->track_number > 0 && music_info_p->track_number <= 9999)
            {
                kal_wsprintf((kal_wchar*)plst_cntx_p->details_cntx.preview_data_p->track_num, "%d", music_info_p->track_number);
            }
            else
            {
                plst_cntx_p->details_cntx.preview_data_p->track_num[0] = 0;
            }
            meta_parser_release(meta_parser_hdlr);
        }
        else
        {
            CHAR* dot = NULL;
            UI_character_type filename[MEDPLY_MAX_FILE_LEN];

            /* try to cut off filename as title. */
            mmi_medply_util_extract_filename(filename, plst_cntx_p->details_cntx.media_path);
            /* cut off extended name. */
            dot = mmi_ucs2rchr((CHAR*)filename, (U16)L'.');
            if (dot != NULL)	/* all supported media file should has an extended name! */
            {
                *(dot + 1) = 0;
                *dot = 0;
            }
            mmi_ucs2ncpy((CHAR*) plst_cntx_p->details_cntx.preview_data_p->title, (CHAR*) filename,MEDPLY_MAX_FILE_LEN - 1);
        }

        /* fill audio info. */
        ret = mmi_medply_plst_details_fill_audio_info(plst_cntx_p->details_cntx.media_path);
        if (ret != MEDPLY_PLST_ERR_NO_MEMORY)
        {    
            /* ignore all error except no memory here. */
            ret = 0;
        }
        if (ret == 0)
        {
            ret = mmi_medply_plst_details_fill_common_info(plst_cntx_p->details_cntx.media_path);
        }
                
        if (memory_ready)
        {
            kal_adm_free(g_medply.adm_id_p, meta_parser_buffer);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE,meta_parser_buffer, __LINE__);
            meta_parser_buffer = NULL;
        }
    }

    if (ret < 0 && preview_buffer_ready)
    {
        kal_adm_free(g_medply.adm_id_p, plst_cntx_p->details_cntx.preview_data_p);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE,plst_cntx_p->details_cntx.preview_data_p, __LINE__);
        plst_cntx_p->details_cntx.preview_data_p = NULL;
        plst_cntx_p->details_cntx.preview_data_p = NULL;
    }
    
    return ret;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_entry_details_internal
 * DESCRIPTION
 *  details screen enter for list option.
 *	display the highlighted file's details.
 *  and just print log and display pop up if this string is an invalid path.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_entry_details_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_medply_plst_get_path(plst_cntx_p->details_cntx.media_path, mmi_medply_plst_ui_get_current_highlight());

    if (ret < 0)
    {
        mmi_medply_plst_popup_simple(ret);
        return;
    }
    else    
    {
        MMI_ID cui_gid = GRP_ID_INVALID;
        
        mmi_frm_group_create(g_gid_browser_list, GRP_ID_MEDPLY_LIST_DETAILS, mmi_medply_plst_proc, (void*)NULL); 
        mmi_frm_group_enter(GRP_ID_MEDPLY_LIST_DETAILS, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        cui_gid = cui_inline_create(GRP_ID_MEDPLY_LIST_DETAILS, &mmi_medply_plst_inline_screen);
        if (cui_gid > GRP_ID_INVALID)
        {
            cui_inline_set_title_icon(cui_gid, GetRootTitleIcon(MENU_ID_MEDPLY_MAIN));
            cui_inline_run(cui_gid);
        }
        else
        {   
            mmi_medply_plst_popup_simple_with_string((U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_entry_details
 * DESCRIPTION
 *  details screen enter for main screen.
 *  just display the current playing/loading file's details.
 *  this function will get current file's path from "g_medply.filefullpath".
 *  and just print log and display pop up if this string is an invalid path.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_entry_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID cui_gid = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2ncpy((CHAR*)plst_cntx_p->details_cntx.media_path, (CHAR*)g_medply.filefullpath, (MEDPLY_MAX_PATH_LEN - 1));

    mmi_frm_group_create(g_gid_medply, GRP_ID_MEDPLY_LIST_DETAILS, mmi_medply_plst_proc, (void*)NULL); 
    mmi_frm_group_enter(GRP_ID_MEDPLY_LIST_DETAILS, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    cui_gid = cui_inline_create(GRP_ID_MEDPLY_LIST_DETAILS, &mmi_medply_plst_inline_screen);
    if (cui_gid > GRP_ID_INVALID)
    {
        cui_inline_set_title_icon(cui_gid, GetRootTitleIcon(MENU_ID_MEDPLY_MAIN));
        cui_inline_run(cui_gid);
    }
    else
    {   
        mmi_medply_plst_popup_simple_with_string( (U16*)get_string(STR_GLOBAL_NOT_AVAILABLE), MMI_EVENT_FAILURE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_clear_context_variables
 * DESCRIPTION
 *  clear context 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_clear_context_variables(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_medply.duration = 0;
    g_medply.filefullpath[0] = 0;
    g_medply.idle_string[0] = 0;
    g_medply.media_format = MEDPLY_FORMAT_NONE;
    g_medply.media_type = MEDPLY_TYPE_NONE;
    g_medply.seekable = MMI_FALSE;
    g_medply.need_to_build_cache = MMI_FALSE;
    g_medply.title[0] = 0;
    g_medply.current_time = 0;
    g_medply.old_play_time = 0;
    g_medply.selected_button = MEDPLY_MAIN_DISABLED;
}

#define __EVENT_HANDLER
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_msdc_plug_in_hdlr
 * DESCRIPTION
 *  plug in 
 * PARAMETERS
 *  drv_num     [IN]
 *  drv_list    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_msdc_plug_in_hdlr(U8 drv_num, PU8 drv_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_MSDC_PLUG_IN, drv_num, *drv_list );
    if (NULL == plst_cntx_p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        return;
    }
    if (mmi_frm_group_is_present(GRP_ID_MEDPLY_LIST_STORAGE_CHANGE))
    {
        mmi_frm_group_close(GRP_ID_MEDPLY_LIST_STORAGE_CHANGE);
    }
    for (i = 0; i < drv_num; i++)
    {
        if (drv_list[i] == (U8)g_medply.filefullpath[0])	
        {
            mmi_medply_plst_apply_picked_file();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_msdc_plug_out_hdlr
 * DESCRIPTION
 *  plug out hdlr 
 * PARAMETERS
 *  drv_num     [IN]
 *  drv_list    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_msdc_plug_out_hdlr(U8 drv_num, PU8 drv_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 preview_file_drv_letter;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_MSDC_PLUG_OUT, drv_num, *drv_list);
    if (mmi_frm_group_is_present(GRP_ID_MEDPLY_LIST_STORAGE_CHANGE))
    {
        mmi_frm_group_close(GRP_ID_MEDPLY_LIST_STORAGE_CHANGE);
    }

#ifdef __MMI_KURO_SUPPORT__
    if (plst_cntx_p)
    {
        mmi_medply_settings_read_value(MMI_MEDPLY_SETTINGS_DEFAULT_STORAGE, &plst_cntx_p->default_storage);
    }
#endif
    for (i = 0; i < drv_num; i++)
    {
        if (drv_list[i] == (U8)g_medply.filefullpath[0])	
        {
            /* The now playing file has been removed. 
            ** Media player should reset some flag in order to insure the correct of main screen. */
            g_medply.seekable = MMI_FALSE;
            g_medply.need_to_build_cache = MMI_FALSE;
            g_medply.current_time = 0;
            g_medply.old_play_time = 0;
            g_medply.duration = 0;
        }
    }
    if (plst_cntx_p)
    {
    for (i = 0; i < drv_num; i++)
    {
        if (drv_list[i] == plst_cntx_p->default_storage)
        {
         #ifdef __MMI_KURO_SUPPORT__
            mmi_frm_group_close(GRP_ID_MEDPLY_KURO_LIST_KURO_SONG_LIST);
            mmi_frm_group_close(GRP_ID_MEDPLY_KURO_LIST_PRESER_SONG);
         #endif
            mmi_frm_group_close(GRP_ID_MEDPLY_LIST_ADD);
            mmi_frm_group_close(GRP_ID_MEDPLY_LIST_GEN);
            mmi_frm_group_close(GRP_ID_MEDPLY_LIST_MGR);
            mmi_frm_group_close(g_gid_browser_list);
            mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_MGR);
        }

        /* stop playing if current playlist in removed driver. */
        if (drv_list[i] == (U8)plst_cntx_p->current_list.path[0])
        {
            /*need set media type to NONE, to avoid states not change to IDLE.*/
            g_medply.media_type = MEDPLY_TYPE_NONE;
            mmi_medply_stop_playing();
            mmi_medply_plst_clear_context_variables();
            
            /* close file handle and reset list context. */
            FS_Close(plst_cntx_p->current_list.fs_hdlr);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->current_list.fs_hdlr ,__LINE__);
            memset(&(plst_cntx_p->current_list), 0, sizeof(mmi_medply_plst_struct));

            /* reset flag. */
            plst_cntx_p->list_loaded = MMI_FALSE;
            /* If the current list is no longer being played remove the item from NCenter */
        #ifdef __MMI_NCENTER_SUPPORT__
            mmi_medply_ncenter_clear_app_item();
        #endif
            mmi_frm_group_close(GRP_ID_MEDPLY_SETTINGS_MAIN);
        }
        /* go back to correct screen if the browsering list in removed driver. */
        if (plst_cntx_p->browser_list_p && drv_list[i] == (U8)plst_cntx_p->browser_list_p->path[0])
        {
            /*if browsing list running generate.*/
            if (mmi_frm_group_is_present(GRP_ID_MEDPLY_LIST_ADD))
            {
                mmi_frm_group_close(GRP_ID_MEDPLY_LIST_ADD);
                mmi_frm_group_close(GRP_ID_MEDPLY_LIST_GEN);
            }

            if (mmi_medply_plst_is_scrn_present(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_MGR))
            {
                mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_MGR);
            }

            /* close file handle and reset list context. */
            FS_Close(plst_cntx_p->browser_list_p->fs_hdlr);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->browser_list_p->fs_hdlr ,__LINE__);
            memset(plst_cntx_p->browser_list_p, 0, sizeof(mmi_medply_plst_struct));

            mmi_frm_group_close(g_gid_browser_list);
            }
        }
    }
    else
    {
        /*dummy*/
    }

    preview_file_drv_letter = mmi_medply_setting_get_preview_file_drv_letter();
    for (i = 0; i < drv_num; i++)
    {
        if (drv_list[i] == preview_file_drv_letter)
        {
            mmi_medply_setting_deinit_hdlr();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_usb_plug_in_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_usb_plug_in_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_USB_PLUG_IN);
    if (NULL == plst_cntx_p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        return;
    }
    
    /* USB plugin during generate. */
    if (mmi_frm_group_is_present(GRP_ID_MEDPLY_LIST_GEN))
    {
        mmi_frm_group_close(g_gid_browser_list);
        mmi_frm_group_close(GRP_ID_MEDPLY_LIST_ADD);
        mmi_frm_group_close(GRP_ID_MEDPLY_LIST_GEN);
    }

    if (plst_cntx_p->list_loaded)
    {
        /*
        **  need write list back if list loading when usb plug-in.
        */
        if (in_browser_mode)
        {
            if (browser_now_playing)
            {
                mmi_medply_plst_write_back_to_file(&(plst_cntx_p->current_list));
                FS_Close(plst_cntx_p->current_list.fs_hdlr);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->current_list.fs_hdlr ,__LINE__);
                plst_cntx_p->current_list.fs_hdlr = FS_ERROR_RESERVED;
            }
            else
            {
                //MAUI_02439145
                if (plst_cntx_p->browser_list_p)
                {
                    mmi_medply_plst_write_back_to_file(plst_cntx_p->browser_list_p);
                    FS_Close(plst_cntx_p->browser_list_p->fs_hdlr);
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->browser_list_p->fs_hdlr ,__LINE__);
                    plst_cntx_p->browser_list_p->fs_hdlr = FS_ERROR_RESERVED;
                }
                else
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
                }
            }
        }
        else
        {
            mmi_medply_plst_write_back_to_file(&(plst_cntx_p->current_list));
            FS_Close(plst_cntx_p->current_list.fs_hdlr);  
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->current_list.fs_hdlr ,__LINE__);
            plst_cntx_p->current_list.fs_hdlr = FS_ERROR_RESERVED;
        }
    }
    else
    {
        if (in_browser_mode)
        {
            //MAUI_02439145
            if (plst_cntx_p->browser_list_p)
            {
                mmi_medply_plst_write_back_to_file(plst_cntx_p->browser_list_p);
                FS_Close(plst_cntx_p->browser_list_p->fs_hdlr);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->browser_list_p->fs_hdlr ,__LINE__);
                plst_cntx_p->browser_list_p->fs_hdlr = FS_ERROR_RESERVED;
            }
            else
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
            }
        }
    }
        
#ifdef __MMI_KURO_SUPPORT__
    KURO_DownloadCommand(0, DOWNLOAD_STOP_ALL);
    StopTimer(MEDPLY_KURO_UPDATE_DOWNLOAD_MANAGER_TIMER);
#endif
    /*
    **delete all screens.
    **deinit playlist module.
    **free ASM memory.
    */
    mmi_frm_group_close(g_gid_medply);
    mmi_medply_setting_deinit_hdlr();
    mmi_medply_plst_module_deinit();

    mmi_medply_asm_delete();
    mmi_medply_plst_clear_context_variables();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_usb_plug_out_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_usb_plug_out_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_USB_PLUG_OUT);
    if (NULL == plst_cntx_p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        return;    
    }
    if (!plst_cntx_p->browser_list_p)/*used as temp buffer*/
    {
        plst_cntx_p->browser_list_p = (mmi_medply_plst_struct*)kal_adm_alloc(g_medply.adm_id_p, sizeof(mmi_medply_plst_struct));/*bql*/
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ASM_ALLOCATE, plst_cntx_p->browser_list_p, sizeof(mmi_medply_plst_struct), __LINE__);
    }

    if (plst_cntx_p->list_loaded)
    {
        S32 ret = 0;
        ret = mmi_medply_plst_open_internal(plst_cntx_p->current_list.path, plst_cntx_p->browser_list_p);/*why used editor_buffer??bql*/

        if (ret < 0)
        {
            /* playlist file damaged, replaced or etc... */
            plst_cntx_p->list_loaded = MMI_FALSE;
            
            /* clear screen. */
            mmi_medply_clear_play_seconds();/*why not use mmi_medply_plst_clear_context_variables??bql*/
            g_medply.seekable = MMI_FALSE;
            g_medply.need_to_build_cache = MMI_FALSE;
            g_medply.title[0] = 0;
            g_medply.filefullpath[0] = 0;
            
            mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
        }
        else
        {
            /* reset fs handler in current list cntx with new handler. */
            plst_cntx_p->current_list.fs_hdlr = plst_cntx_p->browser_list_p->fs_hdlr;
            /* check whether is the same file. */
            ret = memcmp(&(plst_cntx_p->current_list.header), &(plst_cntx_p->browser_list_p->header), sizeof(mmi_medply_plst_header_struct));

            if (ret != 0)
            {
                /* playlist file damaged, replaced or etc... */
                plst_cntx_p->list_loaded = MMI_FALSE;
                
                /* clear screen. */
                mmi_medply_clear_play_seconds();
                g_medply.seekable = MMI_FALSE;
                g_medply.need_to_build_cache = MMI_FALSE;
                g_medply.title[0] = 0;
                g_medply.filefullpath[0] = 0;
                
                mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_MEDPLY);
                FS_Close(plst_cntx_p->current_list.fs_hdlr);
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->current_list.fs_hdlr ,__LINE__);
                memset(&(plst_cntx_p->current_list), 0, sizeof(mmi_medply_plst_struct));
                memset(plst_cntx_p->browser_list_p, 0, sizeof(mmi_medply_plst_struct));
            }
            else
            {
                /* reopen is OK! */
                memset(plst_cntx_p->browser_list_p, 0, sizeof(mmi_medply_plst_struct));
                plst_cntx_p->browser_list_p = NULL;
            }
        }
    }
    if (plst_cntx_p->browser_list_p)
    {
        kal_adm_free(g_medply.adm_id_p, plst_cntx_p->browser_list_p);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_ASM_FREE, plst_cntx_p->browser_list_p, __LINE__);
        plst_cntx_p->browser_list_p = NULL;
    }
        
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_pre_format_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_pre_format_hdlr(CHAR drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_PRE_FORMAT, drv);
    if ((U8)drv == (U8)g_medply.filefullpath[0])
    {
        /*need set media type to NONE, to avoid states not change to IDLE.*/
        g_medply.media_type = MEDPLY_TYPE_NONE;
        mmi_medply_stop_playing();
    }
    
    if (NULL == plst_cntx_p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        return;
    }
    
    if ((U8)drv == mmi_medply_plst_get_now_playing_list_drv())
    {
        /*need set media type to NONE, to avoid states not change to IDLE.*/
        g_medply.media_type = MEDPLY_TYPE_NONE;
        mmi_medply_stop_playing();
        StopTimer(MEDPLY_WAIT_NEXT_TIMER);
        mmi_medply_refresh_cache();
        /*  
        **  format driver only initiate by file manager.
        **  audio player is running in background.
        */
        /*in background play plst_cntx_p should not be NULL, bql*/
        FS_Close(plst_cntx_p->current_list.fs_hdlr);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->current_list.fs_hdlr ,__LINE__);
        memset(&(plst_cntx_p->current_list), 0, sizeof(mmi_medply_plst_struct));
        plst_cntx_p->list_loaded = MMI_FALSE;
        
        mmi_medply_plst_ui_reset_cntx();
    #ifdef __MMI_KURO_SUPPORT__
        KURO_DownloadCommand(0, DOWNLOAD_STOP_ALL);
        StopTimer(MEDPLY_KURO_UPDATE_DOWNLOAD_MANAGER_TIMER);
    #endif
        mmi_medply_plst_module_deinit();
        mmi_medply_asm_delete();
        mmi_medply_plst_clear_context_variables();

    } 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_msdc_entry_unmount
 * DESCRIPTION
 *  update driver's status.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_msdc_entry_unmount(CHAR drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_MSDC_ENTRY_UNMOUNT, drv);
    /* stop playing if current playlist in removed driver. */
    if (NULL == plst_cntx_p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        return;
    }
    if (drv == (U8)plst_cntx_p->current_list.path[0])
    {
        /*need set media type to NONE, to avoid states not change to IDLE.*/
        g_medply.media_type = MEDPLY_TYPE_NONE;
        mmi_medply_stop_playing();
        mmi_medply_plst_clear_context_variables();
  
        /* close file handle and reset list context. */
        FS_Close(plst_cntx_p->current_list.fs_hdlr);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE,plst_cntx_p->current_list.fs_hdlr ,__LINE__);
        memset(&(plst_cntx_p->current_list), 0, sizeof(mmi_medply_plst_struct));
   
        /* reset flag. */
        plst_cntx_p->list_loaded = MMI_FALSE;
     #ifdef __MMI_KURO_SUPPORT__
         KURO_DownloadCommand(0, DOWNLOAD_STOP_ALL);
         StopTimer(MEDPLY_KURO_UPDATE_DOWNLOAD_MANAGER_TIMER);
     #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_msdc_exist_unmount
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv			[IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_msdc_exist_unmount(CHAR drv)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_check_path_is_parent
 * DESCRIPTION
 *  check if @parent_path is parent of @check_path
 * PARAMETERS
 *  parent_path          [IN]    
 *  check_path           [IN]
 * RETURNS
 *  TRUE:   if @parent_path is parent of same as @check_path.
 *  FALSE:  otherwise.
 *****************************************************************************/
static MMI_BOOL mmi_medply_plst_check_path_is_parent(const WCHAR* parent_path, const WCHAR *check_path)
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

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_check_file_is_playing
 * DESCRIPTION
 *  check before delete remove and delete all.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_medply_check_file_is_playing(CHAR *path, MMI_BOOL is_folder,MMI_BOOL is_short, MMI_BOOL is_delete_all, const FMGR_FILTER *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 fmgr_path_length = (U32)mmi_ucs2strlen(path);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_medply.state != MEDPLY_STATE_IDLE             && 
       g_medply.state != MEDPLY_STATE_AUDIO_READY      &&
       g_medply.state != MEDPLY_STATE_VIDEO_IDLE       &&
       g_medply.state != MEDPLY_STATE_PURE_AUDIO_READY &&
       g_medply.state != MEDPLY_STATE_STREAM_IDLE      &&
       g_medply.state < MEDPLY_STATE_TOTAL)
    {
        if(is_folder)
        {
            if(mmi_medply_plst_check_path_is_parent((WCHAR*)path, (WCHAR*)g_medply.filefullpath) == MMI_TRUE)
            {
                if(is_delete_all)
                {
                    while(g_medply.filefullpath[fmgr_path_length] != 0 &&
                          g_medply.filefullpath[fmgr_path_length] != L'\\')
                    {
                        fmgr_path_length ++;
                    }
                    if (g_medply.filefullpath[fmgr_path_length] == 0)
                    {
                        CHAR* ext_ptr = mmi_ucs2rchr((CHAR*)g_medply.filefullpath, (U16)L'.');
                        if (ext_ptr != NULL)
                        {
                            ext_ptr += 2;
                        }
                        else
                        {
                            return MMI_TRUE;
                        }
                       
                        if (!mmi_ucs2icmp((CHAR*)ext_ptr, (CHAR*)L"imy"))
                        {
                            if (FMGR_FILTER_IS_SET(filter, FMGR_TYPE_IMY))
                            {
                                return MMI_TRUE;
                            }
                        }
                        else if (!mmi_ucs2icmp((CHAR*)ext_ptr, (CHAR*)L"wav"))
                        {
                            if (FMGR_FILTER_IS_SET(filter, FMGR_TYPE_WAV))
                            {
                                return MMI_TRUE;
                            }
                        }
                        else if (!mmi_ucs2icmp((CHAR*)ext_ptr, (CHAR*)L"amr"))
                        {
                            if (FMGR_FILTER_IS_SET(filter, FMGR_TYPE_AMR))
                            {
                                return MMI_TRUE;
                            }
                        }
                        else if (!mmi_ucs2icmp((CHAR*)ext_ptr, (CHAR*)L"awb"))
                        {
                            if (FMGR_FILTER_IS_SET(filter, FMGR_TYPE_AWB))
                            {
                                return MMI_TRUE;
                            }
                        }
                        else if (FMGR_FILTER_IS_SET_AUDIO((FMGR_FILTER *)filter))
                        {
                            return MMI_TRUE;
                        }
                        return MMI_FALSE;
                    }                       
                }
                else if(*(U16*)(path+ fmgr_path_length * 2 - 2) == L'\\' || 
                        *(U16*)(path+ fmgr_path_length * 2) == 0)
                {
                    return MMI_TRUE;
                }
            }                       
        }
        else
        {
            if(mmi_ucs2nicmp(path, (CHAR *)g_medply.filefullpath, fmgr_path_length) == 0)
                return MMI_TRUE;
        }
    }
    return MMI_FALSE;

}


#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_notify_default_storage_change_pre_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_storage_letter   [IN]
 * RETURNS
 *  MMI_BOOL 
 *****************************************************************************/
MMI_BOOL mmi_medply_plst_notify_default_storage_change_pre_check(CHAR new_storage_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_notify_default_storage_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_storage_letter   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_notify_default_storage_change(CHAR new_storage_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_KURO_SUPPORT__
    S16 error = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_LIST_DEFAULT_STORAGE_CHANGE_NOTIFY);
    if (plst_cntx_p)
    {
        plst_cntx_p->default_storage = (U8)new_storage_letter;
    }

    #ifdef __MMI_KURO_SUPPORT__
        mmi_medply_settings_write_value(MMI_MEDPLY_SETTINGS_DEFAULT_STORAGE, &new_storage_letter);
    #else
        WriteValue(NVRAM_MEDPLY_PREFER_LIST, &new_storage_letter, DS_BYTE, &error);
    #endif

    if (mmi_frm_scrn_get_active_id() == SCR_ID_MEDPLY_LIST_MGR)
    {   /*used for redraw listmgr scr, because the storage has been changed!bql*/
        mmi_frm_display_dummy_screen_ex(GRP_ID_MEDPLY_LIST_MGR, GLOBAL_SCR_DUMMY);
        mmi_frm_scrn_close(GRP_ID_MEDPLY_LIST_MGR, GLOBAL_SCR_DUMMY);
    }
    else if (mmi_medply_plst_is_scrn_present(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_MGR))
    {
        mmi_medply_plst_clear_gui_buffer(GRP_ID_MEDPLY_LIST_MGR, SCR_ID_MEDPLY_LIST_MGR);
    }
}
#endif/* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_notify_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_medply_plst_notify_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body */
    /*----------------------------------------------------------------*/

    switch(event->evt_id)
    {
#ifdef __MMI_USB_SUPPORT__
        case EVT_ID_USB_ENTER_MS_MODE:
        {
            mmi_medply_plst_usb_plug_in_hdlr();
            break;
        }
        case EVT_ID_USB_EXIT_MS_MODE:
        {
            mmi_medply_plst_usb_plug_out_hdlr();
            break;
        }
#endif /*__MMI_USB_SPLIT_SUPPORT__*/
#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
        case EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE:
        {
            srv_fmgr_notification_set_def_storage_event_struct *fmgr_storage
                = (srv_fmgr_notification_set_def_storage_event_struct*)event;
            
            if(fmgr_storage->state == SRV_FMGR_NOTIFICATION_STATE_QUERY) /* MMI_FMGR_NOTIFY_SET_STORAGE_PRE_CHK */
            {
                return mmi_medply_plst_notify_default_storage_change_pre_check((CHAR)fmgr_storage->drv_letter);
            }
            else if(fmgr_storage->state == SRV_FMGR_NOTIFICATION_STATE_AFTER) /* MMI_FMGR_NOTIFY_SET_STORAGE */
            {
                mmi_medply_plst_notify_default_storage_change((CHAR)fmgr_storage->drv_letter);
            }
            break;
        }

#endif /* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */

        case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT: 
        {
            srv_fmgr_notification_format_event_struct *fmgr_format
                = (srv_fmgr_notification_format_event_struct*)event;
            
            if(fmgr_format->state == SRV_FMGR_NOTIFICATION_STATE_BEFORE) /* MMI_FMGR_NOTIFY_DRV_PRE_FORMAT */
            {
                mmi_medply_plst_pre_format_hdlr((CHAR)fmgr_format->drv_letter);
            }
            break;
        }


        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT: /* MMI_FMGR_NOTIFY_DRV_POST_UNMOUNT */
        {
            srv_fmgr_notification_dev_plug_event_struct *fmgr_plug
                = (srv_fmgr_notification_dev_plug_event_struct*)event;

            mmi_medply_plst_msdc_plug_out_hdlr(fmgr_plug->count, fmgr_plug->drv_letters);
            break;
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN: /*MMI_FMGR_NOTIFY_DRV_POST_MOUNT*/
        {
            srv_fmgr_notification_dev_plug_event_struct *fmgr_plug
                = (srv_fmgr_notification_dev_plug_event_struct*)event;

            mmi_medply_plst_msdc_plug_in_hdlr(fmgr_plug->count, fmgr_plug->drv_letters);
            break;
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT:
        {
            srv_fmgr_notification_dev_soft_mount_event_struct *fmgr_mount
                = (srv_fmgr_notification_dev_soft_mount_event_struct*)event;
            
            if(fmgr_mount->mount == MMI_FALSE) /*MMI_FMGR_NOTIFY_ENTRY_UNMOUNT*/
            {
                mmi_medply_plst_msdc_entry_unmount((CHAR)fmgr_mount->drv_letter);
            }
            else /*MMI_FMGR_NOTIFY_EXIT_UNMOUNT*/
            {
                mmi_medply_plst_msdc_exist_unmount((CHAR)fmgr_mount->drv_letter);
            }
            break;

        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
        {
            srv_fmgr_notification_adv_action_event_struct *fmgr_act 
                = (srv_fmgr_notification_adv_action_event_struct*)event;
            
            if(fmgr_act->state == SRV_FMGR_NOTIFICATION_STATE_QUERY)
            {
                if ((fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_MOVE) || /*MMI_FMGR_NOTIFY_PRE_DELETE, MMI_FMGR_NOTIFY_PRE_MOVE */
                    (fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_DELETE) ||
                    (fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_RENAME))
                {
                    if(mmi_medply_check_file_is_playing((CHAR*)fmgr_act->src_filepath, (MMI_BOOL)(fmgr_act->src_fileinfo.attribute & FS_ATTR_DIR), MMI_FALSE, MMI_FALSE, fmgr_act->filter))
                    {
                        return MMI_RET_ERR;
                    }
                }
                else if(fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_DELETE_ALL) /* MMI_FMGR_NOTIFY_PRE_DEL_ALL */
                {
                    if (!FMGR_FILTER_IS_SET_AUDIO((FMGR_FILTER *)fmgr_act->filter))
                    {
                        /* avoid: delete all image files. need not check*/
                        return MMI_RET_OK;
                    }
                    if(mmi_medply_check_file_is_playing((CHAR*)fmgr_act->src_filepath, (MMI_BOOL)(fmgr_act->src_fileinfo.attribute & FS_ATTR_DIR),MMI_FALSE, MMI_TRUE, fmgr_act->filter))
                    {
                        return MMI_RET_ERR;
                    }
                }
            }
            break;
        }
        
        default:
            break;
    }

    return MMI_RET_OK;
}


#define __UTIL_FUNCTION

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_get_menu_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
FuncPtr mmi_medply_util_get_menu_handler(U16 menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr old_hdlr, new_hdlr; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    new_hdlr = mmi_frm_get_hilite_hdlr(menu_id);
    if(new_hdlr)
    {
        old_hdlr = get_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
        new_hdlr();
        new_hdlr = get_softkey_function(KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
        set_softkey_function(old_hdlr, KEY_EVENT_UP, MMI_LEFT_SOFTKEY);
        if(new_hdlr == old_hdlr)
            new_hdlr = NULL;
    }
    return new_hdlr;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_generic_exit_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_generic_exit_screen(MMI_ID parent_id, U16 scrnID, mmi_proc_func entryFuncPtr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_node_struct node_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_node_info_init(&node_info);
    node_info.id = (MMI_ID)scrnID;
    node_info.entry_proc = entryFuncPtr;
    mmi_frm_scrn_insert(parent_id, 
        mmi_frm_scrn_get_active_id(), 
        &node_info, 
        MMI_FRM_NODE_BEFORE_FLAG);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_is_scrn_present
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_medply_plst_is_scrn_present(MMI_ID parent_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_frm_scrn_is_present(parent_id, scrn_id, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_gobacktomain
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_gobacktomain(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_group_is_present(GRP_ID_MEDPLY_MAIN_LIST))
    {
        mmi_medply_app_pre_entry();
    }

    /* main screen */
    mmi_frm_group_close(GRP_ID_MEDPLY_MAIN_SCREEN);
    /* settings */
    mmi_frm_group_close(GRP_ID_MEDPLY_SETTINGS_MAIN);
    /* list */
    mmi_frm_group_close(GRP_ID_MEDPLY_LIST_BROWSER);
    mmi_frm_group_close(GRP_ID_MEDPLY_LIST_BROWSER_CURR);
    mmi_frm_group_close(GRP_ID_MEDPLY_LIST_MGR);
    mmi_frm_group_close(GRP_ID_MEDPLY_LIST_GEN);
    mmi_frm_group_close(GRP_ID_MEDPLY_LIST_BOOKMARK);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_gobackhistory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_gobackhistory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_check_free_space
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv_letter   [IN]
 *  req_size     [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_medply_util_check_free_space(CHAR drv_letter, U32 req_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DiskInfo disk_info;
    U32 disk_free_space;
    S32 fs_ret;
    UI_character_type path[10];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_wsprintf(path, "%c:\\", drv_letter);    
    fs_ret = FS_GetDiskInfo((kal_uint16*)path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    if (fs_ret < 0)
    {
        return MMI_FALSE;
    }
    else
    {        
        disk_free_space = disk_info.FreeClusters * 
                          disk_info.SectorsPerCluster * 
                          disk_info.BytesPerSector;
        if (disk_free_space < req_size + disk_info.BytesPerSector)    /* more a sector free space to keep file system other operation normal. */
        {
            return MMI_FALSE;
        }
        else
        {
            return MMI_TRUE;
        }
    }
}




/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_clear_gui_buffer
 * DESCRIPTION
 *  clear appointed screen's gui buffer. this screen should be in history.
 * PARAMETERS
 *  scr_id		[IN]
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_medply_plst_clear_gui_buffer(U16 parent_id, U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    mmi_frm_scrn_clean_gui_buf(parent_id, (mmi_id)scr_id);
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_util_clear_gui_buffer
 * DESCRIPTION
 *  clear appointed screen's gui buffer. this screen should be in history.
 * PARAMETERS
 *  scr_id		[IN]
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_medply_plst_util_clear_gui_buffer(U16 scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    mmi_frm_scrn_clean_gui_buf(g_gid_medply, (mmi_id)scr_id);
    
}


#define __OUT_API
#ifdef __MMI_MEDIA_PLAYER_STREAM__
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_create_file_dir
 * DESCRIPTION
 *  create file directory-resursivly
 * PARAMETERS
 *  filepath        [IN]        Filepath to be created
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_medply_util_create_file_dir(UI_string_type filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type buf_createpath[MEDPLY_MAX_PATH_LEN];
    S32 fs_ret;
    S32 str_len;
    S32 cmp_ret;
    S32 i;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_ret = 0;

    file_handle = FS_Open(filepath, FS_OPEN_DIR | FS_READ_ONLY);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_OPEN,file_handle ,__LINE__);
    /* path already exist */
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_FS_CLOSE, file_handle,__LINE__);
        fs_ret = FS_GetAttributes(filepath);
        
        if (fs_ret & FS_ATTR_DIR)
        {
            /* folder already exist */
            return FS_NO_ERROR;   
        }
    }
    else if (file_handle != FS_FILE_NOT_FOUND &&
    	     file_handle != FS_PATH_NOT_FOUND)
    {
        return file_handle;
    }		
    		

    /* create directory if it is not there */
    str_len = mmi_ucs2strlen((CHAR*)filepath);

    /* skip drive. "C:\" */
    for (i = 3; i < str_len; i++)
    {
        cmp_ret = mmi_ucs2ncmp((CHAR*)&filepath[i], (CHAR*) L"\\", 1);
        if (cmp_ret == 0)
        {
            /* create dir */
            mmi_ucs2ncpy((CHAR*)buf_createpath, (CHAR*)filepath, i);
            buf_createpath[i] = 0;
            fs_ret = FS_CreateDir(buf_createpath);
            if (fs_ret < 0)
            {
                return fs_ret;
            }
        }
    }

    return fs_ret;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_is_target_support_format
 * DESCRIPTION
 *  check a file whether be supported.
 * PARAMETERS
 *  ext        [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
static U16 mmi_medply_util_is_target_support_format(const UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    S32 ext_len = 0;
    CHAR* dot = NULL;
    UI_character_type file_ext[MEDPLY_MAX_EXT_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ext == NULL || 0 == (ext_len = mmi_ucs2strlen((CHAR*)ext)))
    {
        return MEDPLY_FORMAT_NONE;
    }
    /* skip ".". */
    dot = mmi_ucs2rchr((CHAR*)ext, (U16)L'.');
    if (dot)
    {
        dot += 2;
    }
    else
    {
        dot = (CHAR*)ext;
    }
    mmi_ucs2ncpy((CHAR*)file_ext, (CHAR*)dot, MEDPLY_MAX_EXT_LEN - 1);
    ext_len = mmi_ucs2strlen((CHAR*)dot);
    for (i = 0; i < sizeof(support_format_table)/sizeof(support_format_table[0]); i++)
    {
        if (ext_len == mmi_ucs2strlen((CHAR*)support_format_table[i].ext_name))
        {
            if (!mmi_ucs2icmp((CHAR*)file_ext, (CHAR*)support_format_table[i].ext_name))
            {   
                return support_format_table[i].file_format;
            }
        }
    }

    return MEDPLY_FORMAT_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_is_support_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ext        [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_medply_util_is_support_format(const UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    S32 ext_len = 0;
    UI_character_type file_ext[MEDPLY_MAX_EXT_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ext == NULL || 0 == (ext_len = mmi_ucs2strlen((CHAR*)ext)))
    {
        return MEDPLY_FORMAT_NONE;
    }
    /* skip ".". */
    {
        CHAR* dot = mmi_ucs2rchr((CHAR*)ext, (U16)L'.');
        if (dot)
        {
            dot += 2;
        }
        else
        {
            dot = (CHAR*)ext;
        }
        mmi_ucs2ncpy((CHAR*)file_ext, (CHAR*)dot, (MEDPLY_MAX_EXT_LEN - 1));
        ext_len = mmi_ucs2strlen((CHAR*)dot);
    }
    
    for (i = 0; i < MEDPLY_FORMAT_TOTAL; i++)
    {
        if (ext_len == mmi_ucs2strlen((CHAR*)media_file_info_table[i].ext_name))
        {
            if (!mmi_ucs2icmp((CHAR*)file_ext, (CHAR*)media_file_info_table[i].ext_name))
            {   
                return media_file_info_table[i].file_format;
            }
        }
    }

    return MEDPLY_FORMAT_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_get_file_icon
 * DESCRIPTION
 *  extract filename icon
 * PARAMETERS
 *  file_format        [IN]        
 * RETURNS
 *  return icon id
 *****************************************************************************/
U16 mmi_medply_util_get_file_icon(U16 file_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_format < MEDPLY_FORMAT_TOTAL && file_format != MEDPLY_FORMAT_NONE)
    {
        return media_file_info_table[file_format].image_id;
    }
    else
    {
        return IMG_ID_MEDPLY_FILE_UNKNOWN_ICON;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_extract_ext
 * DESCRIPTION
 *  extract filename extension
 * PARAMETERS
 *  filename        [IN]        
 *  ext             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_util_extract_ext(const UI_string_type filename, UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* ext_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename == NULL)
    {
        *ext = 0;
    }
    else
    {
        ext_ptr = mmi_ucs2rchr((CHAR*)filename, (U16)L'.');

        if (ext_ptr == NULL)
        {
            *ext = 0;
        }
        else
        {
            ext_ptr += 2;
            mmi_ucs2ncpy((CHAR*)ext, (CHAR*)ext_ptr, (MEDPLY_MAX_EXT_LEN - 1));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_split_filename_ext
 * DESCRIPTION
 *  split filename into two parts: name and extension
 * PARAMETERS
 *  filename                    [IN]        
 *  filename_without_ext        [IN]        
 *  ext                         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_util_split_filename_ext(const UI_string_type filename, UI_string_type filename_without_ext, UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* dot = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename == NULL)
    {
        *filename_without_ext = 0;
        *ext = 0;
    }
    else
    {
        mmi_ucs2ncpy((CHAR*)filename_without_ext, (CHAR*)filename, (MEDPLY_MAX_FILE_LEN - 1));
        dot = mmi_ucs2rchr((CHAR*)filename_without_ext, (U16)L'.');
        if (dot == NULL)
        {
            *ext = 0;
        }
        else
        {
            mmi_ucs2ncpy((CHAR*)ext, (CHAR*)(dot + 2), (MEDPLY_MAX_EXT_LEN - 1));
            *(dot + 1) = 0;
            *dot = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_extract_filename
 * DESCRIPTION
 *  extract filename
 * PARAMETERS
 *  out_file            [IN]        
 *  in_path             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_util_extract_filename(UI_string_type out_filename, const UI_string_type in_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* filename_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_path == NULL)
    {
        *out_filename = 0;
    }
    else
    {
		filename_ptr = mmi_ucs2rchr((CHAR*)in_path, (U16)(L'\\'));
        if (filename_ptr == NULL)
	    {
	        *out_filename = 0;
	    }
	    else
	    {
	        /* use SRV_FMGR_PATH_MAX_FILE_NAME_LEN to avoid short name problem */
            /*
	    	fd = FS_FindFirst(in_path, 0, 0, &file_info, filename, MEDPLY_MAX_FILE_LEN * ENCODING_LENGTH);

			if (fd < 0)
	        {
				mmi_ucs2ncpy((CHAR*)out_filename, (CHAR*)(filename_ptr + 2), MEDPLY_MAX_FILE_LEN - 1);
	        }
	        else
	        {
		        is_short = (file_info.NTReserved == FS_SFN_MATCH) ? MMI_TRUE : MMI_FALSE;
		        if (is_short)
		        {
			        mmi_chset_mixed_text_to_ucs2_str(
			            (U8*)out_filename,
			            (MEDPLY_MAX_FILE_LEN - 1) * ENCODING_LENGTH,
			            (U8*)(filename_ptr + 2),
			            (mmi_chset_enum)PhnsetGetDefEncodingType());
		        }
		        else
		        {
		        	mmi_ucs2ncpy((CHAR*)out_filename, (CHAR*)(filename_ptr + 2), MEDPLY_MAX_FILE_LEN - 1);
		    	}
		        FS_FindClose(fd);
	        }
	        */
			mmi_ucs2ncpy((CHAR*)out_filename, (CHAR*)(filename_ptr + 2), MEDPLY_MAX_FILE_LEN - 1);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_util_fill_idle_display_str
 * DESCRIPTION
 *  fill in the string shown in idle screen while playing
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_util_fill_idle_display_str(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_medply_details_for_display_struct   meta_info;
    S32 result;
    U32 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_medply.idle_string[0]  = 0;
    
    meta_info.album[0]       = 0;
    meta_info.artist[0]      = 0;
    meta_info.title[0]       = 0;
    meta_info.user_rating    = 0;
    meta_info.artwork.mime_type  = META_TAG_IMG_TOTAL;
    meta_info.artwork.size   = 0;
    meta_info.lyrics.size    = 0;
    meta_info.artwork.buffer = 0;

    result = mmi_medply_plst_get_current_details(&meta_info);

    if (result >= MEDPLY_PLST_NO_ERROR)
    {
        length = mmi_ucs2strlen((CHAR*)meta_info.artist);

        if (length != 0)
        {
            mmi_ucs2ncpy((CHAR*)g_medply.idle_string, (CHAR*)meta_info.artist, (MMI_MEDPLY_MAX_ARTISRT_LEN + MMI_MEDPLY_MAX_TITLE_LEN));
        }
        else
        {
            UI_character_type artist[MMI_MEDPLY_MAX_ARTISRT_LEN + 1];
            mmi_ucs2ncpy((CHAR*)artist, (CHAR*)GetString(STR_ID_MEDPLY_PLST_UNKNOWN_ARTIST), MMI_MEDPLY_MAX_ARTISRT_LEN);
            length = mmi_ucs2strlen((CHAR*)artist);
            mmi_ucs2ncpy((CHAR*)g_medply.idle_string, (CHAR*)artist, (MMI_MEDPLY_MAX_ARTISRT_LEN + MMI_MEDPLY_MAX_TITLE_LEN));
        }

        mmi_ucs2ncat((CHAR*)g_medply.idle_string, (CHAR*)L" - ", (MMI_MEDPLY_MAX_ARTISRT_LEN + MMI_MEDPLY_MAX_TITLE_LEN));

        length = mmi_ucs2strlen((CHAR*)meta_info.title);

        if (length != 0)
        {
            mmi_ucs2ncat((CHAR*)g_medply.idle_string, (CHAR*)meta_info.title, length);
        }
        else
        {
            CHAR* dot = NULL;
            UI_character_type filename[MEDPLY_MAX_FILE_LEN];
            /* try to cut off filename as title. */
            mmi_medply_util_extract_filename(filename, g_medply.filefullpath);
            /* cut off extended name. */
            dot = mmi_ucs2rchr((CHAR*)filename, (U16)L'.');
            if (dot != NULL)	/* all supported media file should has an extended name! */
            {
                *(dot + 1) = 0;
                *dot = 0;
            }
            mmi_ucs2ncat((CHAR*)g_medply.idle_string, (CHAR*)filename, MMI_MEDPLY_MAX_TITLE_LEN);
        }
    }
    else
    {
    	CHAR* dot = NULL;
    	UI_character_type filename[MEDPLY_MAX_FILE_LEN];
    	/* try to cut off filename as title. */
        mmi_medply_util_extract_filename(filename, g_medply.filefullpath);
		/* cut off extended name. */
        dot = mmi_ucs2rchr((CHAR*)filename, (U16)L'.');
        if (dot != NULL)	/* all supported media file should has an extended name! */
        {
        	*(dot + 1) = 0;
        	*dot = 0;
        }
		length = mmi_ucs2strlen((CHAR*)filename);

        g_medply.idle_string[0] = 0;
        mmi_ucs2ncpy((CHAR*)g_medply.idle_string, (CHAR*)GetString(STR_ID_MEDPLY_PLST_UNKNOWN_ARTIST), (MMI_MEDPLY_MAX_ARTISRT_LEN + MMI_MEDPLY_MAX_TITLE_LEN));
        mmi_ucs2ncat((CHAR*)g_medply.idle_string, (CHAR*)L" - ", (MMI_MEDPLY_MAX_ARTISRT_LEN + MMI_MEDPLY_MAX_TITLE_LEN));
        mmi_ucs2ncat((CHAR*)g_medply.idle_string, (CHAR*)filename, length);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_determine_progress_speed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  duration [IN]    duration of current media file
 * RETURNS
 *  U32     progress speed in ms
 *****************************************************************************/
U32 mmi_medply_determine_progress_speed(U64 duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 progress_speed = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (duration == 0)
    { 
        return 0;
    }
    else if (duration <= 300000) /*less than 5 mins*/
    {
        progress_speed = 1000;
    }
    else if (duration <= 600000) /*5 to 10 mins*/
    {
        progress_speed = 2000;
    }
    else
    {
        progress_speed = 4000;
    }
        
#if 0 //defined(MT6223P) || defined(MT6223)
/* under construction !*/
#endif

    return progress_speed;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_encoding_type_change_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_encoding_type_change_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_medply.adm_id_p != NULL && g_medply.mem_pool_p != NULL)
    {
        mmi_medply_util_fill_idle_display_str();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_shuffle_change_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_value       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_shuffle_change_callback(U8 new_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 current_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == plst_cntx_p)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_MEDPLY_PLST_ERROR_HAPPEN, __LINE__);
        return;
    }
    
    if (plst_cntx_p->list_loaded)
	{
		current_index = plst_cntx_p->current_list.pick_index;
		if (new_value == 0)
		{
			mmi_medply_plst_set_start(-1);
			mmi_medply_plst_set_pick_index(current_index);
			plst_cntx_p->current_list.pick_count = current_index + 1;
		}
		else if (new_value == 1)
		{	
			mmi_medply_plst_set_start(-1);
			mmi_medply_plst_set_pick_index(current_index);
		}
		else
		{
			MMI_ASSERT(new_value != 0 && new_value != 1);
		}
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_get_error_string_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_medply_plst_get_error_string(S32 error_code, MMI_ID_TYPE *string_id, mmi_event_notify_enum *event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *string_id = 0;
    *event_id = MMI_EVENT_FAILURE;
    
    if (error_code > MEDPLY_PLST_ERR_INVALID_PARA)
    {
        /* handle file system error code. */
        *string_id = srv_fmgr_fs_error_get_string(error_code);

        /* handle special case. */
        switch (error_code)
        {
            case FS_NO_MORE_FILES:
                *string_id = STR_GLOBAL_EMPTY;
                *event_id = MMI_EVENT_FAILURE;
                break;
            default:
                break;
        }

        /* get image id and tone id */
        switch (*string_id)
        {
            case STR_GLOBAL_EMPTY:
                *event_id = MMI_EVENT_FAILURE;
                break;
            case STR_GLOBAL_DRM_PROHIBITED:
                *event_id = MMI_EVENT_ERROR;
                break;
            default:
                *event_id = MMI_EVENT_ERROR;
                break;        
        }
    }
#ifdef __DRM_SUPPORT__    
    else if (error_code < FS_MINIMUM_ERROR_CODE)  /* The max of File System error code */
    {
        *string_id = mmi_rmgr_get_err_string(error_code);
        *event_id = MMI_EVENT_ERROR;
    }
#endif
    else
    {
        switch (error_code)
        {
            /* warning */
            case MEDPLY_PLST_ERR_NO_SPACE:
            case MEDPLY_PLST_ERR_FILE_EXISTS:
                *event_id = MMI_EVENT_ERROR;
                break;
            default:
                *event_id = MMI_EVENT_FAILURE;
                break;        
        }
        /* get string id. */
        switch (error_code)
        {
            case MEDPLY_PLST_ERR_DB_ERROR:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_DB_ERROR;
                break;
            case MEDPLY_PLST_ERR_WRITE_FAILED:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_WRITE_FAILED;
                break;
            case MEDPLY_PLST_ERR_READ_FAILED:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_READ_FAILED;
                break;
            case MEDPLY_PLST_ERR_FILE_EXISTS:
                *string_id = STR_GLOBAL_FILE_ALREADY_EXISTS;
                *event_id = MMI_EVENT_ERROR;
                break;
            case MEDPLY_PLST_ERR_LIST_FULL:  
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_LIST_FULL;
                break;
            case MEDPLY_PLST_ERR_NOT_PLST:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_INVALID;
                break;
            case MEDPLY_PLST_ERR_WRONG_VER:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_WRONG_VERSION;
                *event_id = MMI_EVENT_ERROR;
                break;
            case MEDPLY_PLST_ERR_INVALID_PARA:
                *string_id = FMGR_FS_PARAM_ERROR_TEXT;
                break;
            case MEDPLY_PLST_ERR_INVALID_FILENAME:
                *string_id = STR_GLOBAL_INVALID_FILENAME;
                *event_id = MMI_EVENT_ERROR;
                break;
            case MEDPLY_PLST_ERR_EMPTY_FILENAME:
                *string_id = STR_GLOBAL_PLEASE_INPUT_THE_FILENAME;
                *event_id = MMI_EVENT_ERROR;
                break;
            case MEDPLY_PLST_ERR_CREATE_FAILED:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_CREATE_FAILED;
                break;
            case MEDPLY_PLST_ERR_NO_SPACE:
                *string_id = STR_GLOBAL_NOT_ENOUGH_MEMORY;
                break;
            case MEDPLY_PLST_ERR_NO_MEMORY:
                *string_id = STR_GLOBAL_INSUFFICIENT_MEMORY;
                break;
            case MEDPLY_PLST_ERR_LIST_DAMAGED:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_DAMAGED;
                break;
            case MEDPLY_PLST_ERR_OPEN_FAILED:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_OPEN_FAILED;
                break;
            case MEDPLY_PLST_ERR_MEAT_PARSER:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_PARSE_FILE_FAILED;
                break;
            case MEDPLY_PLST_ERR_ITEM_EXISTS:
                *string_id = STR_GLOBAL_FILE_ALREADY_EXISTS;
                *event_id = MMI_EVENT_ERROR;
                break;

            case MEDPLY_PLST_ERR_NO_FILE_LOADED:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_INVALID_CURRENT_PLST;
                break;
            case MEDPLY_PLST_ERR_UNSUPPORT_FORMAT:
                *string_id = STR_GLOBAL_UNSUPPORTED_FORMAT;
                break;

            case MEDPLY_PLST_ERR_EMPTY_LIST:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_EMPTY_LIST;
                break;
            default:
                *string_id = STR_ID_MEDPLY_PLST_NOTIFY_UNKNOWN_ERROR;
                break;        
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_confirm(MMI_ID parent_id, WCHAR* string, mmi_medply_playlist_alert_enum alert_type, mmi_confirm_type_enum type, MMI_BOOL no_csk_icon,  mmi_event_notify_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct property;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&property, type);
    property.parent_id = parent_id;
    property.user_tag = (void*)alert_type;
    if (no_csk_icon)
    {
        property.f_auto_map_empty_softkey = 0;
    }
    mmi_confirm_display(string, event_type, &property);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_confirm_simple
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_confirm_simple(MMI_ID parent_id, WCHAR* string, FuncPtr confirm_done, mmi_confirm_type_enum type, MMI_BOOL no_csk_icon,  mmi_event_notify_enum event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct property;
    WCHAR display_str[MAX_SUBMENU_CHARACTERS+1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If more than MAX_SUBMENU_CHARACTERS add ... This is done to make consistent with file manager */
    if (mmi_wcslen(string) >= MAX_SUBMENU_CHARACTERS)
    {
        mmi_wcsncpy(display_str, string, MAX_SUBMENU_CHARACTERS - 4);
        mmi_wcscat(display_str, (WCHAR*)L"...");
    }
    else
    {
        mmi_wcsncpy(display_str, string, MAX_SUBMENU_CHARACTERS);
    }

    mmi_confirm_property_init(&property, type);
    property.parent_id = parent_id;
    property.user_tag = (void*)confirm_done;
    if (no_csk_icon)
    {
        property.f_auto_map_empty_softkey = 0;
    }
	/* ? will be shown by popup not application */
	property.f_auto_question_mark = MMI_TRUE;
    mmi_confirm_display(display_str, event_type, &property);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_popup_with_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_popup_with_string(MMI_ID parent_gid, WCHAR* string, mmi_event_notify_enum event_id, mmi_proc_func callback, void* user_tag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID grp_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(parent_gid))
    {
        grp_id = parent_gid;
    }
    else
    {
        grp_id = GRP_ID_ROOT;
    }

    
    if (callback)
    {
        mmi_popup_property_struct arg;   
        
        mmi_popup_property_init(&arg);              
        arg.callback = callback;       
        arg.user_tag = (void*)user_tag;          
        arg.parent_id = grp_id;   
        
        mmi_popup_display(                          
            string,                                
            event_id,                                   
            &arg);                                      
    }
    else
    {
        mmi_popup_display_simple(                   
            string,                                
            event_id,                                   
            grp_id,                                 
            user_tag);
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_popup(MMI_ID parent_gid, S32 error_code, mmi_proc_func callback, void* user_tag, MMI_BOOL is_nmgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id = 0;
    mmi_event_notify_enum event_id = MMI_EVENT_FAILURE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_MEDPLY_PLST_DISPLAY_POPUP, error_code);
    mmi_medply_plst_get_error_string(error_code, (MMI_ID_TYPE *)&string_id, &event_id);

    if (!is_nmgr)
    {
        mmi_medply_plst_popup_with_string(
            parent_gid, 
            (WCHAR *)get_string(string_id), 
            event_id, 
            callback, 
            user_tag);
    }
    else
    {
        //@TODO: recheck the scenario
        mmi_frm_nmgr_popup(
            MMI_SCENARIO_ID_DEFAULT, 
            event_id, 
            (WCHAR *)get_string(string_id));
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_popup_simple_with_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_popup_simple_with_string_ex(WCHAR* string, mmi_event_notify_enum event_id, U16 line)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_MEDPLY_PLST_POPUP_SIMPLE_WITH_STRING_EX, string, event_id, line);
    mmi_medply_plst_popup_with_string(g_gid_medply, string, event_id, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_popup_simple
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_popup_simple_ex(S32 error_code, U16 line)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_MEDPLY_PLST_POPUP_SIMPLE_EX, error_code, line);
    mmi_medply_plst_popup(g_gid_medply, error_code, NULL, NULL, MMI_FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_post_popup_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_medply_plst_post_popup_internal(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_medply_plst_popup_simple((S32)event->user_data);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_post_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_medply_plst_post_popup(S32 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, 0);
    mmi_frm_post_event(&evt, mmi_medply_plst_post_popup_internal, (void*)error_code);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_display_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error_code   [IN]
 *  callback     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_medply_plst_display_popup(S32 error_code, FuncPtr callback)
{

    mmi_medply_plst_popup(
        g_gid_medply, 
        error_code, 
        (mmi_proc_func)callback,
        NULL, 
        MMI_FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_medply_plst_post_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_medply_plst_post_event_to_main(mmi_medply_event_enum event_id, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, event_id);
    MMI_FRM_POST_EVENT(&evt, mmi_medply_event_proc, user_data);
}

#endif  /* __MMI_MEDIA_PLAYER__ */
