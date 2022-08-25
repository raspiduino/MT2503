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
*  FMRadioSrc.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   FM Radio main program
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
*==============================================================================
*******************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_FM_RADIO__
#include "wgui_touch_screen.h"
#include "BTMMISCOPathGprots.h"
#include "gui_typedef.h"

#include "aud_defs.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_include.h"
#include "Device.h"
#include "kal_non_specific_general_types.h"
#include "gui_data_types.h"
#include "gui_virtual_keyboard_language_type.h"
#include "wgui_inline_edit.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "Unicodexdcl.h"
#include "kal_release.h"
#include "string.h"
#include "DebugInitDef_Int.h"
#include "nvram_common_defs.h"
#include "mmi_rp_app_fmrdo_def.h"
#include "mmi_frm_nvram_gprot.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "AlertScreen.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "custom_mmi_default_value.h"
#include "fs_func.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "mmi_res_range_def.h"
#include "mmi_frm_history_gprot.h"
#include "gdi_const.h"
#include "wgui.h"
#include "gui_effect_oem.h"
#include "gui.h"
#include "wgui_categories_list.h"
#include "wgui_categories.h"
#include "ImeGprot.h"
#include "CommonScreensResDef.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "mmi_rp_file_type_def.h"
#include "FileMgrType.h"
#include "gui_touch_feedback.h"
#include "FMRadioDef.h"
#include "FMRadioType.h"
#include "FMRadioProt.h"
#include "FMRadioMainScreen.h"
#include "GpiosrvGprot.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "gui_virtual_keyboard.h"
#endif
#ifdef __DM_LAWMO_SUPPORT__
#include "Dmuigprot.h"
#endif
#include "AlarmGprot.h"

#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
#include "ScrLockerGprot.h"
#include "mmi_rp_app_scr_locker_def.h"
#endif

#ifdef __MMI_FM_RADIO_ANIMATION__
#ifdef __RF_DESENSE_TEST__
#include "rf_desense_test.h"
#endif /*__RF_DESENSE_TEST__*/
#endif /*__MMI_FM_RADIO_ANIMATION__*/

#if defined(__MMI_FM_RADIO_RECORD__)
#include "FileMgrSrvGProt.h"
#include "dcl.h"

#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif

#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 
#include "MMIDataType.h"

#ifdef __MMI_BACKGROUND_CALL__
#include "UcmSrvGprot.h"
#endif 

#include "UcmGProt.h"
#include "IdleGprot.h"
#include "menucuigprot.h"
#include "inlinecuigprot.h"
#include "fseditorcuigprot.h"

#ifdef __MMI_FILE_MANAGER__
#include "filemgrcuigprot.h"
#endif 

#include "mmi_rp_srv_prof_def.h"
#include "ShutdownSrvGprot.h"
#ifdef __MMI_NCENTER_SUPPORT__
#include "vsrv_ncenter.h"
#endif

#ifdef __MMI_FM_VIA_A2DP__
#include "av_bt.h"
#include "BTMMIA2DPScr.h"
#endif

#ifdef __MMI_BT_FM_VIA_SCO__
#include "BthScoPathSrvGProt.h"
#endif

#ifdef __MMI_AVRCP_SUPPORT__
#include "BtcmSrvGprot.h"
#include "BTMMIAVRCPGProt.h"
#endif /* __MMI_AVRCP_SUPPORT__ */

#ifdef __MMI_MAINLCD_96X64__
#include "VolumeHandler.h"
#include "mmi_rp_app_profiles_def.h"
#endif


#ifdef __MMI_VUI_LAUNCHER_KEY__
void* g_fmrdo_srv_userdata;
void(*g_fmrdo_srv_preempted_cb)(const void*, U32);
void(*g_fmrdo_srv_search_cb)(const void*, U16);
#endif /* __MMI_VUI_LAUNCHER_KEY__ */

#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
extern void mmi_fmrdo_redraw_main_volume_key(void);
#endif
extern U16 g_fmrdo_entry_from_search_one;
#ifdef __MMI_NCENTER_SUPPORT__
	extern void mmi_fmrdo_ncenter_add_fm(void);
    extern void mmi_fmrdo_ncenter_update_channel(void);
	extern void mmi_fmrdo_ncenter_clear_fm(void);	
    extern vsrv_ngroup_handle ncenter_fmrdo_ghandle;
    extern vsrv_notification_handle ncenter_fmrdo_nhandle;
#endif


static mmi_ret mmi_fmrdo_main_option_menu_cui_proc(cui_menu_event_struct *menu_evt);
static mmi_ret mmi_fmrdo_channel_option_menu_cui_proc(cui_menu_event_struct *menu_evt);
static mmi_ret mmi_fmrdo_entry_channel_edit_inline_cui_proc(mmi_event_struct *evt);
static mmi_ret mmi_fmrdo_manual_input_inline_cui_proc(mmi_event_struct *evt);
#ifndef __MMI_FM_PLUTO_SLIM__
static mmi_ret mmi_fmrdo_entry_settings_inline_cui_proc(mmi_event_struct *evt);
#endif
#if defined(__MMI_FM_RADIO_RECORD__)
static mmi_ret mmi_fmrdo_entry_edit_filename_editor_cui_proc(mmi_event_struct *evt);
static mmi_ret mmi_fmrdo_send_record_req_no_card_cnf_callback(mmi_event_struct *mmi_evt);
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
MMI_BOOL mmi_fmrdo_entry_save(void);
#else
static MMI_BOOL mmi_fmrdo_entry_save(void);
#endif

#endif
#ifdef __MMI_FM_RADIO_RDS__
static mmi_ret mmi_fmrdo_rds_entry_setting_inline_cui_proc(mmi_event_struct *evt);
extern void mmi_fmrdo_rds_set_tp_and_af_setting(MMI_BOOL tp_status , MMI_BOOL af_status);
#endif

static void mmi_fmrdo_channel_option_LSK(mmi_menu_id highlight_item);

#ifdef __MMI_AVRCP_SUPPORT__
U8 mmi_fmrdo_bt_avrcp_cmd_hdlr(U8 command, mmi_avrcp_key_events key_events);
static void mmi_fmrdo_press_button_canceled(void);
#endif


typedef enum
{
    FMRDO_MENU_CUI_MAIN_OPTION,
    FMRDO_MENU_CUI_CHANNEL_LIST_OPTION,
    FMRDO_MENU_CUI_TOTAL
} mmi_fmrdo_menu_cui_user_data_enum;

typedef enum
{
    FMRDO_INLINE_CUI_CHANNEL_EDIT,
    FMRDO_INLINE_CUI_MANUAL_EDIT,
    FMRDO_INLINE_CUI_SETTING,
    FMRDO_INLINE_CUI_SETTING_RDS,
    FMRDO_INLINE_CUI_TOTAL
} mmi_fmrdo_inline_cui_user_data_enum;

static const cui_inline_item_softkey_struct mmi_fmrdo_inline_cui_softkey = 
{
    {
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},       /*MMI_LEFT_SOFTKEY*/
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},       /*MMI_RIGHT_SOFTKEY*/
        {0, CUI_INLINE_SOFTKEY_DEFAULT_VALUE}        /*MMI_CENTER_SOFTKEY*/
    }
};
#ifndef __MMI_FM_RADIO_RDS__
#ifndef __MMI_FM_PLUTO_SLIM__
static const cui_inline_item_softkey_struct mmi_fmrdo_inline_cui_softkey_save = 
{
    {
        {STR_GLOBAL_SAVE, 0},                        /*MMI_LEFT_SOFTKEY*/
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},       /*MMI_RIGHT_SOFTKEY*/
        {0, CUI_INLINE_SOFTKEY_DEFAULT_VALUE}        /*MMI_CENTER_SOFTKEY*/
    }
};
#endif
#endif

#ifdef __MMI_FM_RADIO_RDS__
static S32 g_selected_rds_status;
static S32 g_selected_af_status;
static S32 g_selected_tp_status;
S32 g_setting_rds_status;
S32 g_setting_af_status;
S32 g_setting_tp_status;

static mmi_id g_setting_inline_cui_id;
//static MMI_BOOL g_rds_settings_changed;
MMI_BOOL g_temp_rds_freq_switch_off;
MMI_BOOL g_temp_rds_off;
//static U16 g_inline_count;
UI_character_type rds_text_str[MMI_FMRDO_RDS_PS_NAME_SIZE + MMI_FMRDO_RDS_RT_SIZE + 2];     /* used for showing channel_name or freq in idle screen or subLCD */
extern UI_character_type rds_str_idle;
#endif/*__MMI_FM_RADIO_RDS__*/
mmi_fmrdo_struct g_fmrdo;   /* all memeber variables are zero initial */

static U16 channel_list_highlighted_item_index;
static UI_character_type channel_name_str[MAX_NAME_INPUT_LEN + 10];     /* used for showing channel_name or freq in idle screen or subLCD */
#ifndef __MMI_FM_PLUTO_SLIM__
#if !(defined(__MMI_VUI_HOMESCREEN_FM_RADIO__) || defined(__MMI_VUI_LAUNCHER_KEY__))
static S32 selected_background_play;
#endif 
static S32 selected_skin_index;
#endif /*__MMI_FM_PLUTO_SLIM__*/
static UI_character_type name_inline_editor_buffer[MAX_NAME_INPUT_LEN];
static UI_character_type freq_inline_editor_buffer[MAX_MANUAL_INPUT_LEN];

#if defined(__MMI_FM_RADIO_LOUD_SPEAK__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)
static S32 selected_speaker_status;
#endif /* defined(__MMI_FM_RADIO_LOUD_SPEAK__) */ 

#if defined(__MMI_FM_RADIO_RECORD__)
#ifndef __MMI_FM_PLUTO_SLIM__
static MMI_BOOL g_setting_has_storage_item;
static S32 selected_record_quality;
static S32 selected_record_storage;
#endif
static UI_character_type fmrdo_editor_buff[(SRV_FMGR_PATH_MAX_LEN + 2)];
static mmi_id fmrdo_record_menu_cui_id;
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

#if defined(__MMI_FM_RADIO_MONO__)
static S32 selected_channel_mono;
#endif /* defined(__MMI_FM_RADIO_MONO__) */ 

#ifdef __MMI_VUI_HOMESCREEN_FM_RADIO__
extern void(*mmi_fmrdo_preempted_cb_fptr)(void*, U32);
extern void* mmi_fmrdo_widget_userdata;
#endif

#ifdef __MMI_MAINLCD_96X64__
S32 g_volume_handler;
static void mmi_fmrdo_change_volume(void);
static void mmi_fmrdo_exit_change_volume(void);
static void mmi_fmrdo_set_common_volume(void);
#endif

#ifdef __MMI_FM_VIA_A2DP__
extern mmi_fmrdo_a2dp_struct a2dp_info;	
extern MMI_BOOL fm_a2dp_connected;
#endif

extern wgui_inline_item wgui_inline_items[];        /* defined in wgui_inline_edit.c */
extern const mmi_fmrdo_skin_struct g_fmrdo_skins[]; /* defined in resource_fmradio_skins.c */
#ifdef __MMI_FTE_SUPPORT__
extern U8 g_vol_displayed;
#endif

extern void kal_wsprintf(unsigned short *outstr, char *fmt, ...);
extern void kal_get_time(kal_uint32 *ticks_ptr);
void mdi_fmr_set_output_path(U8 path);

#ifdef __TC01__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif/*__TC01__*/
#ifdef __MMI_FTE_SUPPORT__
MMI_BOOL g_fmrdo_search_freq_changed = MMI_FALSE;
#endif
#if defined(__MMI_FM_RADIO_RECORD__) && defined(__MMI_FTE_SUPPORT__)
extern U8 animate_count;
#endif

#ifdef __MTK_TARGET__
extern kal_bool FMR_IsChipValid(void);  /* this function is definedin in l1audio */
#endif
S32 g_fmrdo_menu_item_index;


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_skip_highlight_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_skip_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo_menu_item_index >= 0 && index >= g_fmrdo_menu_item_index)
    {
        index++;
    }
    ExecuteCurrHiliteHandler(index);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_check_chip_or_hide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  n_items         [IN]        Number of string IDs
 *  string_ids      [IN]        String ID's
 *  icon_ids        [IN]        Icon ID's
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_fmrdo_check_chip_or_hide(U16 n_items, U16 *string_ids, U16 *icon_ids)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    if (!FMR_IsChipValid())
    {
        /* hide FM Radio application menu item */
        S16 i, j;

        for (i = n_items - 1; i >= 0; i--)
        {
            if (string_ids[i] == STR_ID_FMRDO_TITLE)    /* look for FM Radio application string id */
            {
                break;
            }
        }
        g_fmrdo_menu_item_index = i;
        if (i >= 0) /* found FM Radio application string id */
        {
            n_items--;
            for (j = i; j < n_items; j++)   /* move rest application string & image ids up */
            {
                string_ids[j] = string_ids[j + 1];
                icon_ids[j] = icon_ids[j + 1];
            }
        }
    }
    else
#endif
    {
        g_fmrdo_menu_item_index = -1;
    }
    return n_items;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_power_on_main_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  turn_on     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_power_on_main_screen(MMI_BOOL turn_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    if (g_fmrdo.in_main_screen)
#endif
    {
        mmi_fmrdo_power_on_check(turn_on);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_is_power_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_fmrdo_is_power_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_IS_FM_POWER_ON,(g_fmrdo.is_ready && g_fmrdo.is_power_on));
    return (g_fmrdo.is_ready && g_fmrdo.is_power_on);
}

mmi_ret mmi_fmrdo_is_power_on_callback_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(event->evt_id)
    {
        case EVT_ID_SRV_PROF_IS_PLAYING:
        {
            if(g_fmrdo.is_ready && g_fmrdo.is_power_on)
            {
                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        }
    }
    return MMI_RET_OK;       
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_get_channel_name_or_freq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  UI_string_type
 *****************************************************************************/
UI_string_type mmi_fmrdo_get_channel_name_or_freq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type str = channel_name_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.state == FMRDO_STATE_SEARCH_ALL || g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)
    {
        mmi_ucs2cpy((CHAR *) str, (CHAR *)GetString(STR_GLOBAL_SEARCHING));
    }
    else
    {
        if (g_fmrdo.channel_index >= 0)
        {
        #ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
            if (mmi_ucs2strlen((CHAR *) g_fmrdo.channel_list.name[g_fmrdo.channel_index]) > 0)
            {
                kal_wsprintf(
                    str,
                    "%d. %w",
                    g_fmrdo.channel_index + 1,
                    g_fmrdo.channel_list.name[g_fmrdo.channel_index]);
            }
            else
         #endif
            {
                kal_wsprintf(
                    str,
                    "%d. FM %d.%d",
                    g_fmrdo.channel_index + 1,
                    g_fmrdo.frequency / 10,
                    g_fmrdo.frequency % 10);
            }
        }
        else
        {
            kal_wsprintf(str, "FM %d.%d", g_fmrdo.frequency / 10, g_fmrdo.frequency % 10);
        }
    }
    return str;
}

#ifdef __MMI_FM_RADIO_RDS__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_get_channel_name_or_freq
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  UI_string_type
 *****************************************************************************/
UI_string_type mmi_fmrdo_rds_get_rds_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type str = rds_text_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str[0] = 0;
    if(!g_fmrdo.is_power_on || g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)   
    {
        MMI_ASSERT(g_fmrdo.is_power_on);
    }
    if (mmi_ucs2cmp((CHAR *)g_fmrdo.rds.prog_name, (CHAR *)"") != 0 && mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") != 0)
    {
        kal_wsprintf(str, "%w. %w", g_fmrdo.rds.prog_name, g_fmrdo.rds.radio_text);
    }
    else if (mmi_ucs2cmp((CHAR *)g_fmrdo.rds.prog_name, (CHAR *)"") != 0 && mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") == 0)
    {
         kal_wsprintf(str, "%w", g_fmrdo.rds.prog_name);
    }
    else if(mmi_ucs2cmp((CHAR *)g_fmrdo.rds.prog_name, (CHAR *)"") == 0 && mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") != 0)
    {
         kal_wsprintf(str, "%w",g_fmrdo.rds.radio_text);
    }
    else
    {
        if (g_fmrdo.state == FMRDO_STATE_SEARCH_ALL || g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)
        {
            mmi_ucs2cpy((CHAR *) str, (CHAR *)GetString(STR_GLOBAL_SEARCHING));
        }
        else
        {
           if (g_fmrdo.channel_index >= 0)
           {
            #ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
                if (mmi_ucs2strlen((CHAR *) g_fmrdo.channel_list.name[g_fmrdo.channel_index]) > 0)
                {
                    kal_wsprintf(
                            str,
                            "%d. %w",
                            g_fmrdo.channel_index + 1,
                            g_fmrdo.channel_list.name[g_fmrdo.channel_index]);
                }
                else
            #endif
                {
                    kal_wsprintf(
                            str,
                            "%d. FM %d.%d",
                            g_fmrdo.channel_index + 1,
                            g_fmrdo.frequency / 10,
                            g_fmrdo.frequency % 10);
                }
            }
            else
            {
                kal_wsprintf(str, "FM %d.%d", g_fmrdo.frequency / 10, g_fmrdo.frequency % 10);
            }
        }
    }
    return str;
}
#endif/*__MMI_FM_RADIO_RDS__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_preset_list_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  signal_band     [IN/OUT]     Pointer to first channel in sub band
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_preset_list_done(U8 *signal_band)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clear channel list */
    memset(g_fmrdo.channel_list.freq, 0, FM_RADIO_CHANNEL_NUM * 2);
    for (i = 0; i < FM_RADIO_CHANNEL_NUM; i++)
    {
        g_fmrdo.channel_list.name[i][0] = 0;
    }

    /* set channel list */
    for (i = j = 0; i < FM_BANDWIDTH; i++)
    {
        if (FM_SIG_MARK(signal_band[i]))
        {
        #ifdef __MMI_VUI_HOMESCREEN_FM_RADIO__
            UI_character_type name[10];
            U16 freq = i + MIN_FM_FREQUENCY;

            kal_wsprintf(name, "FM %d.%d", freq / 10, freq % 10);
            mmi_fmrdo_set_channel(
                j++,
                (U16) (i + MIN_FM_FREQUENCY),
                (UI_string_type) name);
        #else /* __MMI_VUI_HOMESCREEN_FM_RADIO__ */ 
            mmi_fmrdo_set_channel(
                j++,
                (U16) (i + MIN_FM_FREQUENCY),
                (UI_string_type) GetString(STR_ID_FMRDO_NEW_CHANNEL));
        #endif /* __MMI_VUI_HOMESCREEN_FM_RADIO__ */
            if (j >= FM_RADIO_CHANNEL_NUM)
            {
                break;  /* this line should never be reached if the searching algorithm is correct!! */
            }
        }
    }

    /* write channel list from nvram */
    WriteRecordSlim(NVRAM_EF_FM_RADIO_LID, 1, (void*)&g_fmrdo.channel_list, NVRAM_EF_FM_RADIO_SIZE);

    /* rematch channel index */
    g_fmrdo.channel_index = mmi_fmrdo_match_channel_list(g_fmrdo.frequency);
    g_fmrdo.state = FMRDO_STATE_READY;
#ifdef __MMI_FM_VIA_A2DP__
#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
	if (!g_fmrdo.loud_speaker_on)
	{
#endif
		if(mmi_a2dp_is_output_to_bt() && !fm_a2dp_connected)
		{
            g_fmrdo.state = FMRDO_STATE_BT_CONNECTING;
            srv_a2dp_open_source(mmi_a2dp_get_bt_headset(), MMI_TRUE);
//			av_bt_open_ex((srv_bt_cm_bt_addr *)mmi_a2dp_get_bt_headset(),a2dp_info.sample_rate,a2dp_info.is_stereo,
//								mmi_fmrdo_bt_open_callback,KAL_TRUE);
		}
#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
	}
#endif
#endif
    mmi_idle_update_service_area();

#ifdef __MMI_VUI_HOMESCREEN_FM_RADIO__
    if (mmi_fmrdo_preempted_cb_fptr)
    {
        mmi_fmrdo_preempted_cb_fptr(mmi_fmrdo_widget_userdata, 0);
    }
#endif /* __MMI_VUI_HOMESCREEN_FM_RADIO__ */


    mmi_popup_display_simple_ext(STR_GLOBAL_DONE,
                                 MMI_EVENT_SUCCESS,
                                 GRP_ID_FMRDO, 
                                 NULL);

    if(mmi_frm_scrn_is_present(GRP_ID_FMRDO, SCR_ID_FMRDO_SEARCHING, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_FMRDO, SCR_ID_FMRDO_SEARCHING);
    }
}

#ifndef __MMI_FM_PLUTO_SLIM__

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_start_twinkle_frequency
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_start_twinkle_frequency(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmrdo.twinkle_frequency_count = 0;
    StartTimer(FMRDO_TWINKLE_FREQUENCY_TIMER, TWINKLE_FREQUENCY_ON_TIME, mmi_fmrdo_twinkle_frequency_timer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_stop_twinkle_frequency
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_shown        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_stop_twinkle_frequency(MMI_BOOL is_shown)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(FMRDO_TWINKLE_FREQUENCY_TIMER);
    if (is_shown && g_fmrdo.twinkle_frequency_count % 2 == 0)
    {
        mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_long_press_number_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_long_press_number_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 key_code, key_type;
    U16 channel_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.state != FMRDO_STATE_SEARCH_ONE)
    {
        /* get key number */
        GetkeyInfo((U16*) & key_code, (U16*) & key_type);
        channel_index = key_code - KEY_1;

        /* set channel */
        mmi_fmrdo_set_channel(channel_index, g_fmrdo.frequency, (UI_string_type) GetString(STR_ID_FMRDO_NEW_CHANNEL));

        /* write channel list from nvram */
        WriteRecordSlim(NVRAM_EF_FM_RADIO_LID, 1, (void*)&g_fmrdo.channel_list, NVRAM_EF_FM_RADIO_SIZE);

        g_fmrdo.channel_index = channel_index;

        /* update channel name */
        mmi_fmrdo_redraw_main_channel_name(0);

        /* start twinkle frequency */
        mmi_fmrdo_start_twinkle_frequency();
    }
    g_fmrdo.is_long_press_number_key = MMI_TRUE;
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_number_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_number_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 key_code, key_type;
    U16 freq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FM_RADIO_RECORD__) && defined(__MMI_FTE_SUPPORT__)
    if(animate_count)
    {
        return;
    }
#endif /*defined(__MMI_FM_RADIO_RECORD__) && defined(__MMI_FTE_SUPPORT__)*/

    if (g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)
    {
        mmi_fmrdo_search_frequency_stop();
    }

    if (!g_fmrdo.is_long_press_number_key)
    {
        /* stop previous twinkle frequency if necessary */
		#ifndef __MMI_FM_PLUTO_SLIM__
        mmi_fmrdo_stop_twinkle_frequency(MMI_FALSE);
		#endif
    #ifdef __MMI_FTE_SUPPORT__
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        if(g_vol_displayed)
        {
            mmi_fmrdo_reset_volume_bar();
        } 
    #endif
    #endif /* __MMI_FTE_SUPPORT__ */

        GetkeyInfo((U16*) & key_code, (U16*) & key_type);
        freq = g_fmrdo.channel_list.freq[key_code - KEY_1];
        if (freq != 0)
        {
            mmi_fmrdo_goto_channel((U16) (key_code - KEY_1));
        }
    }
    g_fmrdo.is_long_press_number_key = MMI_FALSE;
}

#ifndef __MMI_FM_PLUTO_SLIM__

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_twinkle_frequency_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_twinkle_frequency_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.twinkle_frequency_count % 2 == 0)   /* twinkle off */
    {
        mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, MMI_FALSE);
        if (g_fmrdo.twinkle_frequency_count < TWINKLE_FREQUENCY_COUNT)
        {
            g_fmrdo.twinkle_frequency_count++;
            StartTimer(FMRDO_TWINKLE_FREQUENCY_TIMER, TWINKLE_FREQUENCY_OFF_TIME, mmi_fmrdo_twinkle_frequency_timer);
        }
    }
    else    /* twinkle on */
    {
        mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, MMI_TRUE);
        if (g_fmrdo.twinkle_frequency_count < TWINKLE_FREQUENCY_COUNT)
        {
            g_fmrdo.twinkle_frequency_count++;
            StartTimer(FMRDO_TWINKLE_FREQUENCY_TIMER, TWINKLE_FREQUENCY_ON_TIME, mmi_fmrdo_twinkle_frequency_timer);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_go_to_next_step
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_go_to_next_step(void (*f)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* update display */
    if (g_fmrdo.in_main_screen)
    {
    #ifdef __MMI_FM_RADIO_RDS__
        if(mmi_fmrdo_rds_is_on())
        {
            mmi_fmrdo_rds_clear();
        }
    #endif/*__MMI_FM_RADIO_RDS__*/
        mmi_fmrdo_redraw_main_frequency(g_fmrdo.step_freq, MMI_TRUE);
        mmi_fmrdo_redraw_main_channel_tuner(g_fmrdo.step_freq);
    }

    if (g_fmrdo.normal_repeat_step_count == 0 && g_fmrdo.is_power_on)
    {
        mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);    /* mute in the begining of step down */
    }

    if (g_fmrdo.normal_repeat_step_count < NORMAL_REAPEAT_STEP_COUNT)
    {
        g_fmrdo.normal_repeat_step_count++;
        StartTimer(FMRDO_REPEAT_STEP_TIMER, NORMAL_REAPEAT_STEP_PERIOD, f);
    }
    else
    {
        StartTimer(FMRDO_REPEAT_STEP_TIMER, FAST_REAPEAT_STEP_PERIOD, f);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_step_down_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_step_down_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.step_freq > MIN_FM_FREQUENCY)
    {
        g_fmrdo.step_freq--;
    }
    else
    {
        g_fmrdo.step_freq = MAX_FM_FREQUENCY;
    }
    mmi_fmrdo_go_to_next_step(mmi_fmrdo_step_down_timer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_step_up_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_step_up_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.step_freq < MAX_FM_FREQUENCY)
    {
        g_fmrdo.step_freq++;
    }
    else
    {
        g_fmrdo.step_freq = MIN_FM_FREQUENCY;
    }

    mmi_fmrdo_go_to_next_step(mmi_fmrdo_step_up_timer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_is_stepping_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_fmrdo_is_stepping_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_fmrdo.is_ready && g_fmrdo.selected_button == FMRDO_BUTTON_STEP_UP && g_fmrdo.is_button_down);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_is_stepping_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_fmrdo_is_stepping_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_fmrdo.is_ready && g_fmrdo.selected_button == FMRDO_BUTTON_STEP_DOWN && g_fmrdo.is_button_down);
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_get_freq_from_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input_str       [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 mmi_fmrdo_get_freq_from_str(UI_string_type input_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq = 0;
    MMI_BOOL fraction = MMI_FALSE;
    MMI_BOOL skip = MMI_FALSE;
    MMI_BOOL one_digit_dicimal = MMI_TRUE;
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; input_str[i] != 0; i++)
    {
        if (input_str[i] == L'.')
        {
            if ((input_str[i + 1] != 0) && (input_str[i + 2] != 0))
            {
                one_digit_dicimal = MMI_FALSE;
            }
            fraction = MMI_TRUE;
        }
        else if (!skip)
        {
            freq = freq * 10 + input_str[i] - L'0';
            if (fraction)
            {
                skip = MMI_TRUE;
            }
        }
    }

    if (freq != 0 && !skip)
    {
        freq *= 10;
    }

    if (!one_digit_dicimal)
    {
        freq = 0xffff;  /* Only allow one digit after the '.' */
    }

    return freq;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_set_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  channel_index       [IN]        
 *  freq                [IN]        
 *  name                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_set_channel(S16 channel_index, U16 freq, UI_string_type name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_fmrdo.channel_index == channel_index) && (g_fmrdo.channel_list.freq[g_fmrdo.channel_index] != freq))
    {
        g_fmrdo.channel_index = -1;
    }

    if ((g_fmrdo.channel_index == -1) && (freq == g_fmrdo.frequency))
    {
        g_fmrdo.channel_index = channel_index;
    }

    mmi_ucs2ncpy((CHAR *) g_fmrdo.channel_list.name[channel_index], (CHAR *) name, MAX_NAME_INPUT_LEN - 1);

    g_fmrdo.channel_list.freq[channel_index] = freq;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_get_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_fmrdo_get_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_fmrdo.is_ready)
    {
        ReadValueSlim(NVRAM_FMRDO_VOLUME, &g_fmrdo.volume, DS_BYTE);
    }

    return g_fmrdo.volume;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_set_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_set_volume(U8 volume)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmrdo.volume = volume;
    WriteValueSlim(NVRAM_FMRDO_VOLUME, &g_fmrdo.volume, DS_BYTE);

    if (g_fmrdo.is_ready && g_fmrdo.is_power_on && g_fmrdo.state != FMRDO_STATE_SEARCH_ONE &&
        g_fmrdo.state != FMRDO_STATE_SEARCH_ALL)
    {
		#ifdef __MMI_MAINLCD_96X64__
			mdi_audio_set_volume(AUD_VOLUME_FMR, MDI_AUD_VOL_MUTE(volume));
		#else
        mdi_audio_set_volume(AUD_VOLUME_FMR, volume);
		#endif
    }
}

#ifndef __MMI_FM_PLUTO_SLIM__

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_write_settings_to_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_write_settings_to_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !(defined(__MMI_VUI_HOMESCREEN_FM_RADIO__) || defined(__MMI_VUI_LAUNCHER_KEY__))
    WriteValueSlim(NVRAM_FMRDO_BACKGROUND_PLAY, &g_fmrdo.is_background_play, DS_BYTE);
#endif 
    WriteValueSlim(NVRAM_FMRDO_SKIN, &g_fmrdo.skin_index, DS_BYTE);
#if defined(__MMI_FM_RADIO_MONO__)
    WriteValueSlim(NVRAM_FMRDO_CHANNEL_MONO, &g_fmrdo.mono, DS_BYTE);
#endif 
#if defined(__MMI_FM_RADIO_RECORD__)
    WriteValueSlim(NVRAM_FMRDO_RECORD_QUALITY, &g_fmrdo.rec.quality, DS_BYTE);
    WriteValueSlim(NVRAM_FMRDO_RECORD_STORAGE, &g_fmrdo.rec.drive, DS_BYTE);
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
    WriteValueSlim(NVRAM_FMRDO_SPEAKER_STATUS, &g_fmrdo.loud_speaker_on, DS_BYTE);
#endif 
#ifdef __MMI_FM_RADIO_RDS__
    WriteValueSlim(NVRAM_FMRDO_RDS_SETTING, &g_fmrdo.rds.rds_setting.is_rds_on, DS_BYTE);
    WriteValueSlim(NVRAM_FMRDO_RDS_TP_SETTING, &g_fmrdo.rds.rds_setting.is_tp_on, DS_BYTE);
    WriteValueSlim(NVRAM_FMRDO_RDS_AF_SETTING, &g_fmrdo.rds.rds_setting.is_af_on, DS_BYTE);
#endif/*__MMI_FM_RADIO_RDS__*/

}

#endif /*__MMI_FM_PLUTO_SLIM__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_inc_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_inc_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.mute)
    {
        g_fmrdo.mute = 0;
        WriteValueSlim(NVRAM_FMRDO_MUTE, &g_fmrdo.mute, DS_BYTE);
    }
    if (g_fmrdo.volume < MAX_VOL_LEVEL - 1)
    {
        mmi_fmrdo_set_volume(++g_fmrdo.volume);
    #ifndef __MMI_FTE_SUPPORT__
        if (g_fmrdo.in_main_screen)
        {
            mmi_fmrdo_redraw_main_volume();
        #ifdef __MMI_TOUCH_SCREEN__
            if (g_fmrdo.volume == MAX_VOL_LEVEL - 1)
            {
                mmi_fmrdo_redraw_main_volum_icon(1);
            }
            else if (g_fmrdo.volume == 0)
            {
                mmi_fmrdo_redraw_main_volum_icon(0);
            }
        #endif /* __MMI_TOUCH_SCREEN__ */ 
        }
    #endif /* __MMI_FTE_SUPPORT__ */
    }
    else
    {
        mmi_fmrdo_set_volume(g_fmrdo.volume);   
    }
#ifdef __MMI_FTE_SUPPORT__
    if (g_fmrdo.in_main_screen)
    {
        #ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
            mmi_fmrdo_redraw_main_volume_key();
        #else
        mmi_fmrdo_redraw_main_volume();
        #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    }
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_dec_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_dec_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.volume == 0)
    {
        g_fmrdo.mute = 1;
        WriteValueSlim(NVRAM_FMRDO_MUTE, &g_fmrdo.mute, DS_BYTE);
        mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
        g_fmrdo.prev_volume = 0;
    }
    else if (g_fmrdo.volume == 1)
    {
        g_fmrdo.volume -= 1;
		g_fmrdo.mute = 1;
        WriteValueSlim(NVRAM_FMRDO_MUTE, &g_fmrdo.mute, DS_BYTE);
		mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
        g_fmrdo.prev_volume = 0;
	}
    else if (g_fmrdo.volume > 1)
    {
        g_fmrdo.mute = 0;
        mmi_fmrdo_set_volume(--g_fmrdo.volume);
    }
#ifdef __MMI_FTE_SUPPORT__
   if (g_fmrdo.in_main_screen)
    {
        #ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
            mmi_fmrdo_redraw_main_volume_key();
        #else
        mmi_fmrdo_redraw_main_volume();
        #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    }
#else 
        if (g_fmrdo.in_main_screen)
        {
            mmi_fmrdo_redraw_main_volume();
        #ifdef __MMI_TOUCH_SCREEN__
            if (g_fmrdo.mute)
            {
                mmi_fmrdo_redraw_main_volum_icon(0);
            }
            else if (g_fmrdo.volume == MAX_VOL_LEVEL - 2)
            {
                mmi_fmrdo_redraw_main_volum_icon(1);
            }
        #endif /* __MMI_TOUCH_SCREEN__ */ 
        }
    #endif 
    }


#if (defined(__MMI_TOUCH_SCREEN__) && (!defined(__MMI_SLIM_IMG_RES__)))
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_volume_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_volume_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_redraw_main_push_down_button(1, MMI_FALSE);
    mmi_fmrdo_inc_volume();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_volume_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_volume_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_redraw_main_push_down_button(0, MMI_FALSE);
    mmi_fmrdo_dec_volume();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_volume_up
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_volume_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_redraw_main_push_down_button(1, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_volume_down
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_volume_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_redraw_main_push_down_button(0, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_repeat_volume_down
 * DESCRIPTION
 *  Repeat handler for volume down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_repeat_volume_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down)
    {
        mmi_fmrdo_redraw_main_push_down_button(0, MMI_TRUE);
        mmi_fmrdo_dec_volume();
        g_fmrdo.is_button_down = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_repeat_volume_up
 * DESCRIPTION
 *  Repeat handler for volume inc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_repeat_volume_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down)
    {
        mmi_fmrdo_redraw_main_push_down_button(1, MMI_TRUE);
        mmi_fmrdo_inc_volume();
        g_fmrdo.is_button_down = MMI_TRUE;
    }
}

#endif
#endif /* (defined(__MMI_TOUCH_SCREEN__) && (!defined(__MMI_SLIM_IMG_RES__)) */ 

#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_hfp_volume_callback
 * DESCRIPTION
 *  callback function of HFP volume, not support mute
 * PARAMETERS
 *  volume      [IN]        Volume want to set to FM by HFP
 *  is_mute     [IN]        FM not support mute
 * RETURNS
 *  MMI_TRUE    Set volume to FM & redraw OK
 *  MMI_FALSE   FM not handle the action
 *****************************************************************************/
MMI_BOOL mmi_fmrdo_hfp_volume_callback(U8 volume, MMI_BOOL is_mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MAINLCD_96X64__
    if (volume < MAX_VOL_LEVEL && is_mute == MMI_FALSE)
    {
        if ((g_fmrdo.in_main_screen == MMI_TRUE || g_fmrdo.is_power_on == MMI_TRUE) &&
            g_fmrdo.state != FMRDO_STATE_SEARCH_ALL && g_fmrdo.state != FMRDO_STATE_SEARCH_ONE)
        {
            g_fmrdo.volume = volume;
		if (g_fmrdo.volume == 0)
    	{
        	g_fmrdo.mute = 1;
        	WriteValueSlim(NVRAM_FMRDO_MUTE, &g_fmrdo.mute, DS_BYTE);
        	mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
        	g_fmrdo.prev_volume = 0;
    	}
		else
		{
            if (g_fmrdo.mute)
            {
                g_fmrdo.mute = 0;
                WriteValueSlim(NVRAM_FMRDO_MUTE, &g_fmrdo.mute, DS_BYTE);
            }
            mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_FALSE);
            g_fmrdo.mute = MMI_FALSE;
            mmi_fmrdo_set_volume(volume);
		}
            if (g_fmrdo.in_main_screen)
            {
            // TODO: added latest
 #ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
         mmi_fmrdo_redraw_main_volume_key();
 #else
                mmi_fmrdo_redraw_main_volume();
 #endif
                if(!g_fmrdo.is_button_down)
                {
            #ifdef __MMI_TOUCH_SCREEN__
                mmi_fmrdo_redraw_main_volum_icon(0);
                mmi_fmrdo_redraw_main_volum_icon(1);
            #endif /* __MMI_TOUCH_SCREEN__ */ 
                }
            }
            return MMI_TRUE;
        }
#else
	if (volume <= MAX_VOL_LEVEL)
	{
	  	if ((g_fmrdo.in_main_screen == MMI_TRUE || g_fmrdo.is_power_on == MMI_TRUE) &&
            g_fmrdo.state != FMRDO_STATE_SEARCH_ALL && g_fmrdo.state != FMRDO_STATE_SEARCH_ONE)
        {
            g_fmrdo.volume = volume;			//In case of BW MDI_AUD_VOL_LEVEL_NORMAL_MUTE is supported
						if (is_mute)
		    		{
		    				g_fmrdo.volume = 0;
			          g_fmrdo.mute = 1;
			        	WriteValueSlim(NVRAM_FMRDO_MUTE, &g_fmrdo.mute, DS_BYTE);
			        	g_fmrdo.prev_volume = 0;
		    		}
		    		else
		    		{
			          g_fmrdo.mute = 0;
			        	WriteValueSlim(NVRAM_FMRDO_MUTE, &g_fmrdo.mute, DS_BYTE);
		    		}
		    		mmi_fmrdo_set_volume(g_fmrdo.volume);
        		return MMI_TRUE;
    	}
#endif
        else if (g_fmrdo.state == FMRDO_STATE_SEARCH_ALL || g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}
#endif /* __BT_SPK_VOL_CONTROL__ */ 
#ifdef __DM_LAWMO_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_lawmo_lock_notify_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
//ry:LAWMO
mmi_ret mmi_fmrdo_lawmo_lock_notify_hdlr(mmi_event_struct *evt )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dm_lawmo_lock_ind_evt_struct *lawmo_lock_ind = (srv_dm_lawmo_lock_ind_evt_struct*)evt;
    
    switch (lawmo_lock_ind->cmd)
    {
    case MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK:
    #ifdef __MTK_TARGET__
        if (FMR_IsChipValid())
    #endif
        {
            mmi_fmrdo_power_on_check(MMI_FALSE);
        }
        (*lawmo_lock_ind->cb)(MMI_TRUE, "FMRadio");
        break;
    
    case MMI_DMUI_CMD_LAWMO_UNLOCK:
        (*lawmo_lock_ind->cb)(MMI_TRUE, "FMRadio");
        break;
    
    default:
        break;
    }
    return MMI_RET_OK;
}

//void mmi_fmrdo_phone_lock_hdlr(mmi_dmui_app_id_enum app_id,mmi_dmui_cmd_enum cmd)
//{
//    if(app_id == MMI_DMUI_APP_ID_FMRDO)
//    {
//        if(cmd == MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK)
//        {
//            mmi_fmrdo_power_on_check(MMI_FALSE);
//            mmi_dmui_lawmo_report(MMI_DMUI_APP_ID_FMRDO,MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK,MMI_DMUI_RESULT_SUCCESS);
//        }
//        else if(cmd == MMI_DMUI_CMD_LAWMO_UNLOCK)
//        {
//            mmi_dmui_lawmo_report(MMI_DMUI_APP_ID_FMRDO,MMI_DMUI_CMD_LAWMO_UNLOCK,MMI_DMUI_RESULT_SUCCESS);
//            return;
//        }
//    }
//}
#endif/*__DM_LAWMO_SUPPORT__*/


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_a2dp_connect_callback_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__MMI_A2DP_SUPPORT__) && defined(__BT_SPEAKER_SUPPORT__)
void mmi_fmrdo_a2dp_connect_callback_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_frm_group_get_state(GRP_ID_FMRDO) != MMI_SCENARIO_STATE_NONE)
    {
        mmi_frm_group_close(GRP_ID_FMRDO);
    }        
}
#endif /*defined(__MMI_A2DP_SUPPORT__) && (__BT_SPEAKER_SUPPORT__)*/


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_earphone_check_invalid_and_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_fmrdo_earphone_check_invalid_and_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
    if (!srv_earphone_is_plug_in())
    {
        mmi_popup_display_simple_ext(STR_ID_FMRDO_PLEASE_PLUG_IN_EARPHONE,
                                 MMI_EVENT_INFO,
                                 GRP_ID_FMRDO, 
                                 NULL);
        return MMI_TRUE;
    }
#endif /* __MMI_FM_RADIO_BIND_EARPHONE__ */
    return MMI_FALSE;
}

#ifdef __MMI_FILE_MANAGER__ 
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_earphone_check_invalid_and_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_fmgr_error_popup(S32 fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple_ext(
                srv_fmgr_fs_error_get_string(fs_error),
                (mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(fs_error),
                GRP_ID_FMRDO,
                NULL);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_init_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    if (FMR_IsChipValid())
    {
//    #ifdef __DM_LAWMO_SUPPORT__
//        mmi_dmui_lawmo_register_notify(MMI_DMUI_APP_ID_FMRDO,MMI_DMUI_MO_TYPE_LAWMO_LOCK,(mmi_dmui_lawmo_cb)mmi_fmrdo_phone_lock_hdlr);
//    #endif /* __DM_LAWMO_SUPPORT__ */
    #ifdef __TC01__
/* under construction !*/
    #endif/*__TC01__*/
    }
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_init_nvram
 * DESCRIPTION
 *  Read channel list and FM settings from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_init_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* read channel list from nvram */
    ReadRecordSlim(NVRAM_EF_FM_RADIO_LID, 1, (void*)&g_fmrdo.channel_list, NVRAM_EF_FM_RADIO_SIZE);

    if (g_fmrdo.channel_list.name[0][0] == 0xFFFF)
    {
        memset(&g_fmrdo.channel_list, 0, sizeof(mmi_fmrdo_channel_list_struct));
    }
    ReadValueSlim(NVRAM_FMRDO_MUTE, &g_fmrdo.mute, DS_BYTE);
    if (g_fmrdo.mute != 1)
    {
        g_fmrdo.mute = 0;
    }

    /* read settings from nvram */
#if !(defined(__MMI_VUI_HOMESCREEN_FM_RADIO__) || defined(__MMI_VUI_LAUNCHER_KEY__))
    ReadValueSlim(NVRAM_FMRDO_BACKGROUND_PLAY, &g_fmrdo.is_background_play, DS_BYTE);
#else 
    g_fmrdo.is_background_play = 1;
#endif 
#if (defined(__MMI_FM_SLIM_SKIN__) || defined(__MMI_FTE_SUPPORT__))
    g_fmrdo.skin_index = 0; /* only 1 skin in silm skin version */
#else 
    ReadValueSlim(NVRAM_FMRDO_SKIN, &g_fmrdo.skin_index, DS_BYTE);
#endif /* #ifdef __MMI_FM_SLIM_SKIN__ */
    ReadValueSlim(NVRAM_FMRDO_VOLUME, &g_fmrdo.volume, DS_BYTE);
#ifdef __MMI_FTE_SUPPORT__
    g_fmrdo.prev_volume = g_fmrdo.volume;
#endif

#if defined(__MMI_FM_RADIO_MONO__)
    ReadValueSlim(NVRAM_FMRDO_CHANNEL_MONO, &g_fmrdo.mono, DS_BYTE);
    if (g_fmrdo.mono != 0 && g_fmrdo.mono != 1)
    {
        g_fmrdo.mono = 0;
        WriteValueSlim(NVRAM_FMRDO_CHANNEL_MONO, &g_fmrdo.mono, DS_BYTE);
    }
#endif /* defined(__MMI_FM_RADIO_MONO__) */ 
#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
    ReadValueSlim(NVRAM_FMRDO_SPEAKER_STATUS, &g_fmrdo.loud_speaker_on, DS_BYTE);
    if (g_fmrdo.loud_speaker_on != 0 && g_fmrdo.loud_speaker_on != 1)
    {
        g_fmrdo.loud_speaker_on = 0;
        WriteValueSlim(NVRAM_FMRDO_SPEAKER_STATUS, &g_fmrdo.loud_speaker_on, DS_BYTE);
    }
#endif /* defined(__MMI_FM_RADIO_LOUD_SPEAK__) */ 
#if defined(__MMI_FM_RADIO_RECORD__)
    ReadValueSlim(NVRAM_FMRDO_RECORD_QUALITY, &g_fmrdo.rec.quality, DS_BYTE);
    ReadValueSlim(NVRAM_FMRDO_RECORD_STORAGE, &g_fmrdo.rec.drive, DS_BYTE);
    if (g_fmrdo.rec.quality >= NO_OF_QUALITY)
    {
        g_fmrdo.rec.quality = FM_QUALITY_LOW;
    }
    /* Restore to default drive if hardware not exists */

    if (FS_GetDevStatus(g_fmrdo.rec.drive, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        g_fmrdo.rec.drive = (U8) SRV_FMGR_PUBLIC_DRV;
    }

#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 
#ifdef __MMI_FM_RADIO_RDS__
#ifndef __MMI_FM_PLUTO_SLIM__
    ReadValueSlim(NVRAM_FMRDO_RDS_SETTING, (U8*)&g_fmrdo.rds.rds_setting.is_rds_on, DS_BYTE);
    ReadValueSlim(NVRAM_FMRDO_RDS_AF_SETTING, (U8*)&g_fmrdo.rds.rds_setting.is_af_on, DS_BYTE);
    ReadValueSlim(NVRAM_FMRDO_RDS_TP_SETTING, (U8*)&g_fmrdo.rds.rds_setting.is_tp_on, DS_BYTE);
    if(g_fmrdo.rds.rds_setting.is_rds_on >= FMRDO_RDS_SETTING_STATE_NUM)
    {
        g_fmrdo.rds.rds_setting.is_rds_on = (MMI_BOOL)FMRDO_RDS_SETTING_STATE_ON;
    }
    if(g_fmrdo.rds.rds_setting.is_af_on >= FMRDO_RDS_SETTING_STATE_NUM)
    {
        g_fmrdo.rds.rds_setting.is_af_on = (MMI_BOOL)FMRDO_RDS_SETTING_STATE_ON;
    }
    if(g_fmrdo.rds.rds_setting.is_tp_on >= FMRDO_RDS_SETTING_STATE_NUM)
    {
        g_fmrdo.rds.rds_setting.is_tp_on = (MMI_BOOL)FMRDO_RDS_SETTING_STATE_OFF;
    }
    g_fmrdo.rds.status_mask = g_fmrdo.rds.status_mask & RESET_ALL;
    g_fmrdo.rds.prog_name[0] = 0;
    g_fmrdo.rds.prog_name[0] = 0;
#else
	g_fmrdo.rds.rds_setting.is_rds_on = (MMI_BOOL)FMRDO_RDS_SETTING_STATE_ON;
	g_fmrdo.rds.rds_setting.is_af_on = (MMI_BOOL)FMRDO_RDS_SETTING_STATE_ON;
	g_fmrdo.rds.rds_setting.is_tp_on = (MMI_BOOL)FMRDO_RDS_SETTING_STATE_ON;
#endif
#endif/*__MMI_FM_RADIO_RDS__*/

    ReadValueSlim(NVRAM_FMRDO_LAST_CHANNEL, &g_fmrdo.frequency, DS_SHORT);
    /* default frequency value */
    if (g_fmrdo.frequency > MAX_FM_FREQUENCY || g_fmrdo.frequency < MIN_FM_FREQUENCY)
    {
        g_fmrdo.frequency = DEFAULT_FREQUENCY;
    }

    /* reset channel index */
    g_fmrdo.channel_index = mmi_fmrdo_match_channel_list(g_fmrdo.frequency);

    /* search & power states */
    g_fmrdo.is_search_on = MMI_FALSE;
    g_fmrdo.is_power_on = MMI_FALSE;

    /* mdi_audio_set_background_handler(MDI_BACKGROUND_APP_FMR, (mdi_bg_callback) mmi_fmrdo_continued); */

    g_fmrdo.is_ready = MMI_TRUE;
#ifdef __MMI_VUI_HOMESCREEN_FM_RADIO__
    mmi_fmrdo_set_preempted_callback(NULL, NULL);
#endif 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_main_scrn_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_fmrdo_main_scrn_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_MAINLCD_96X64__
		mmi_frm_key_evt_struct *p_key = (mmi_frm_key_evt_struct*)param;
	#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_SCRN_ACTIVE:
        mmi_fmrdo_entry_main();
        break;
    case EVT_ID_SCRN_INACTIVE:
        mmi_fmrdo_exit_main();
        break;

    case EVT_ID_SCRN_DEINIT:
        mmi_fmrdo_exit_root(param);
        break;
	case EVT_ID_SRV_SHUTDOWN_DEINIT:
		  mmi_fmrdo_exit_root(param);
        break;	

#ifdef __MMI_MAINLCD_96X64__
	case EVT_ID_WGUI_LSK_CLICK:
		mmi_fmrdo_LSK_up_hdlr();
		break;

	case EVT_ID_WGUI_RSK_CLICK:
		mmi_fmrdo_RSK_up_hdlr();
		break;
		
	case EVT_ID_ON_KEY: 		 
		
		if(p_key->key_type == KEY_EVENT_DOWN)
		{
			if(p_key->key_code == KEY_LEFT_ARROW)
			{
				mmi_fmrdo_press_step_down_button();
			}
			else if(p_key->key_code == KEY_RIGHT_ARROW)
			{
				mmi_fmrdo_press_step_up_button();
			}
		}	
		else if(p_key->key_type == KEY_EVENT_UP)
		{
			if(p_key->key_code == KEY_LEFT_ARROW)
			{
				mmi_fmrdo_release_step_down_button();
			}
			else if(p_key->key_code == KEY_RIGHT_ARROW)
			{
				mmi_fmrdo_release_step_up_button();
			}
			mmi_fmrdo_show_main(STR_GLOBAL_OPTIONS, STR_GLOBAL_BACK, g_fmrdo.skin_index);
		}	
		break;
#endif

    default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_main_scrn_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_fmrdo_channel_scrn_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
    case EVT_ID_SCRN_ACTIVE:
        mmi_fmrdo_entry_channel_list(param);
        break;
        
    case EVT_ID_WGUI_LSK_CLICK:
        mmi_fmrdo_entry_channel_option();
        return MMI_RET_KEY_HANDLED;
        
    case EVT_ID_WGUI_CSK_CLICK:
        mmi_fmrdo_channel_list_CSK();
        return MMI_RET_KEY_HANDLED;

    case EVT_ID_SCRN_HIGHLIGHT_CHANGE:
        {
            cat_evt_struct *evt = (cat_evt_struct *)param;
            channel_list_highlighted_item_index = (U16)evt->item_index;
            return MMI_RET_CHANGED;
        }
     
    case EVT_ID_WGUI_RSK_CLICK:
    default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_search_scrn_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_fmrdo_search_scrn_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (param->evt_id)
    {
    case EVT_ID_SCRN_ACTIVE:
        mmi_fmrdo_entry_searching();
        break;
        
    case EVT_ID_WGUI_RSK_CLICK:
        mmi_fmrdo_search_all_channels_stop();
        return MMI_RET_KEY_HANDLED;
        
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
mmi_ret mmi_fmrdo_app_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;
    mmi_group_event_struct *group_evt;
    U32 menu_level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check if menu cui's event */
    if(cui_menu_is_menu_event(evt->evt_id))
    {
        menu_evt = (cui_menu_event_struct*)evt;

        menu_level = (U32)menu_evt->app_data;
        switch (menu_level)
        {
            case FMRDO_MENU_CUI_MAIN_OPTION:
                return mmi_fmrdo_main_option_menu_cui_proc(menu_evt);

            case FMRDO_MENU_CUI_CHANNEL_LIST_OPTION:
                return mmi_fmrdo_channel_option_menu_cui_proc(menu_evt);

            default:
                break;
        }

        return MMI_RET_OK;
    }

    /* Check if inline cui's event */
    if(evt->evt_id >= EVT_ID_CUI_INLINE_SUBMIT && evt->evt_id < EVT_ID_CUI_INLINE_MAX)
    {
        group_evt = (mmi_group_event_struct*)evt;
        menu_level = cui_inline_get_parent_data(group_evt->sender_id);

        switch (menu_level)
        {
            case FMRDO_INLINE_CUI_CHANNEL_EDIT:
                return mmi_fmrdo_entry_channel_edit_inline_cui_proc(evt);

            case FMRDO_INLINE_CUI_MANUAL_EDIT:
                return mmi_fmrdo_manual_input_inline_cui_proc(evt);
#ifndef __MMI_FM_PLUTO_SLIM__
            case FMRDO_INLINE_CUI_SETTING:
                return mmi_fmrdo_entry_settings_inline_cui_proc(evt);
#endif

        #ifdef __MMI_FM_RADIO_RDS__
            case FMRDO_INLINE_CUI_SETTING_RDS:
                return mmi_fmrdo_rds_entry_setting_inline_cui_proc(evt);

        #endif /*__MMI_FM_RADIO_RDS__*/

            default:
                break;
        }
    }

#if defined(__MMI_FM_RADIO_RECORD__)
    /* Filename editor CUI Event */
    if(evt->evt_id == EVT_ID_CUI_FILENAME_EDITOR_RESULT)
    {
        return mmi_fmrdo_entry_edit_filename_editor_cui_proc(evt);
    }
#endif

    /* Screen group event */
    switch(evt->evt_id)
    {
    case EVT_ID_GROUP_DEINIT: // framework de-init the group
        break;
    case EVT_ID_SCRN_INACTIVE:
        break;

#if defined(__MMI_FM_RADIO_RECORD__)
    /* Folder browser CUI*/
    case EVT_ID_CUI_FOLDER_BROWSER_ON_QUIT:
        group_evt = (mmi_group_event_struct*)evt;

        cui_folder_browser_close(group_evt->sender_id);
        break;
#endif /*__MMI_FM_RADIO_RECORD__*/

    default:
        break;
    }
    return MMI_RET_OK;
}

#if (defined(__MMI_BT_DIALER_SUPPORT__) || defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__))
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_bt_music_disconnect_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fmrdo_bt_music_disconnect_callback(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result)
    {
        mmi_fmrdo_run_app();
    }
}
#endif /* __MMI_BT_DIALER_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_run_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_run_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__) || defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__))
        if (mmi_bt_music_check_connection())
        {
            mmi_bt_music_disconnect(mmi_fmrdo_bt_music_disconnect_callback);
            //return;
        }
#endif  
    
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);
    
    if(!g_fmrdo.is_power_on)
    {
        mdi_audio_suspend_background_play();
    }
    if (!g_fmrdo.is_ready)
    {
        mmi_fmrdo_init_nvram();
    }

#ifdef __BT_SPK_VOL_CONTROL__
#ifndef __MMI_MAINLCD_96X64__
    mdi_audio_bt_register_volume_sync_callback(APP_FMRDO, MDI_AUD_VOL_LEVEL_NORMAL/*7 level volume*/, mmi_fmrdo_hfp_volume_callback);
#else
    mdi_audio_bt_register_volume_sync_callback(APP_FMRDO, MDI_AUD_VOL_LEVEL_NORMAL_MUTE/*7 level + 0 mute volume*/, mmi_fmrdo_hfp_volume_callback);
#endif    
#endif /* __BT_SPK_VOL_CONTROL__ */ 

#ifdef __MMI_FM_VIA_A2DP__
	mdi_fmr_get_audio_info((mdi_fmr_audio_info_struct *)&a2dp_info);
#endif /*__MMI_FM_VIA_A2DP__*/

#ifdef __MMI_AVRCP_SUPPORT__
	mmi_fmrdo_avrcp_set_cmd_hdlr();
#endif 

    mmi_frm_group_create_ex(GRP_ID_ROOT, 
                            GRP_ID_FMRDO,
                            mmi_fmrdo_app_proc,
                            NULL,
                            MMI_FRM_NODE_SMART_CLOSE_FLAG);

    /* power on */
#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
    if (srv_earphone_is_plug_in())
#endif 
#ifdef __MMI_BACKGROUND_CALL__
    if (!srv_ucm_is_background_call())
#endif 
    {
        mmi_fmrdo_search_all_channels_stop();
        mmi_fmrdo_power_on_check(MMI_TRUE);
        mdi_audio_set_background_handler(MDI_BACKGROUND_APP_FMR, (mdi_bg_callback) mmi_fmrdo_continued, NULL);
    }
    mmi_frm_scrn_create(GRP_ID_FMRDO, SCR_ID_FMRDO_MAIN, mmi_fmrdo_main_scrn_proc, NULL);

#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif /* __MMI_BACKGROUND_CALL__ */ 
    mmi_fmrdo_earphone_check_invalid_and_popup();

}

#if defined(__MMI_APP_MANAGER_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrado_launch
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID mmi_fmrado_launch(void* param, U32 param_size)
{
    mmi_fmrdo_run_app();
    return GRP_ID_FMRDO;
}
#endif /* __MMI_APP_MANAGER_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_highlight_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_highlight_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
    ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

    SetLeftSoftkeyFunction(mmi_fmrdo_run_app, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_fmrdo_run_app, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_match_channel_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  frequency       [IN]        
 * RETURNS
 *  S16
 *****************************************************************************/
S16 mmi_fmrdo_match_channel_list(U16 frequency)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* try matching current frequency first */
    if (g_fmrdo.channel_index >= 0 && g_fmrdo.channel_list.freq[g_fmrdo.channel_index] == frequency)
    {
        return g_fmrdo.channel_index;
    }

    for (i = 0; i < FM_RADIO_CHANNEL_NUM; i++)
    {
        if (g_fmrdo.channel_list.freq[i] == frequency)
        {
            return i;
        }
    }

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_step_down_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_step_down_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down
         #if defined(__MMI_FM_RADIO_RECORD__) && defined(__MMI_FTE_SUPPORT__)
            || animate_count
         #endif /*defined(__MMI_FM_RADIO_RECORD__) && defined(__MMI_FTE_SUPPORT__)*/
        )
    {
    #ifndef __RF_DESENSE_TEST__
        return;
    #endif
    }

    g_fmrdo.selected_button = FMRDO_BUTTON_STEP_DOWN;
    g_fmrdo.is_button_down = MMI_TRUE;
    g_fmrdo.normal_repeat_step_count = 0;
#ifndef __MMI_MAINLCD_96X64__
    mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
#endif
    mmi_fmrdo_search_frequency_stop();
#ifdef __MMI_FTE_SUPPORT__
    g_fmrdo_search_freq_changed = MMI_FALSE;
#endif
#ifndef __MMI_FM_PLUTO_SLIM__
    g_fmrdo.step_freq = g_fmrdo.frequency;
    StartTimer(FMRDO_REPEAT_STEP_TIMER, NORMAL_REAPEAT_STEP_PERIOD, mmi_fmrdo_step_down_timer);
    /* stop previous twinkle frequency if necessary */
    mmi_fmrdo_stop_twinkle_frequency(MMI_TRUE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_step_down_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_step_down_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq;
    MMI_BOOL is_freq_changed = (g_fmrdo.normal_repeat_step_count != 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_STEP_DOWN)
    {
        StopTimer(FMRDO_REPEAT_STEP_TIMER);

        g_fmrdo.is_button_down = MMI_FALSE;
#ifndef __MMI_MAINLCD_96X64__
        mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
#endif
#ifdef __MMI_FTE_SUPPORT__
        if(g_fmrdo.state != FMRDO_STATE_SEARCH_ONE && !g_fmrdo_search_freq_changed)
        {
#endif /*__MMI_FTE_SUPPORT__*/
        if (is_freq_changed)
        {
            freq = g_fmrdo.step_freq;   /* frequency is changed so we don't need to decrease it again */
        }
        else
        {
            /* frequency is not changed during button press down so we need to decrease it */
            if (g_fmrdo.frequency > MIN_FM_FREQUENCY)
            {
                freq = g_fmrdo.frequency - 1;
            }
            else
            {
                freq = MAX_FM_FREQUENCY;
            }
        }
#ifdef __MMI_FM_RADIO_RDS__
        if(mmi_fmrdo_rds_is_on())
        {
    
            mmi_fmrdo_rds_clear();
        }
#endif /*__MMI_FM_RADIO_RDS__*/
#ifdef __MMI_FTE_SUPPORT__
        }
        else 
        {
            freq = g_fmrdo.frequency;
        }
		g_fmrdo_search_freq_changed = MMI_FALSE;
#endif /*__MMI_FTE_SUPPORT__*/
    #if ((!defined(__MMI_FTE_SUPPORT__)) && (!defined(__MMI_SLIM_IMG_RES__)))
        if (g_fmrdo.is_power_on && g_fmrdo.is_search_on)
        {
            mmi_fmrdo_search_all_channels_stop();
        #ifdef __FM_RADIO_HW_SEARCH__
#ifndef __MMI_FM_PLUTO_SLIM__
            mmi_fmrdo_start_twinkle_searching();
#endif
            mmi_fmrdo_entry_hw_searching_screen();
            if (is_freq_changed)
	        {
	            mmi_fmrdo_hw_search_frequency_start(freq, MMI_FALSE);
			}
			else
			{
            mmi_fmrdo_hw_search_frequency_start(g_fmrdo.frequency, MMI_FALSE);
			}
			mmi_fmrdo_update_center_key_status();
        #else /* FM_RADIO_HW_SEARCH */ 
            mmi_fmrdo_redraw_main_channel_name((UI_string_type) GetString(STR_GLOBAL_SEARCHING));     /* show searching text */
        #ifdef __MMI_FM_RADIO_ANIMATION__
        #ifdef __RF_DESENSE_TEST__  /*Added by Akhil*/
            if(rf_desense_get_curr_mode() != RF_DESENSE_MODE_FM_NO_ANIMATION)
        #endif /*__RF_DESENSE_TEST__*/
            {
                mmi_fmrdo_animation_stop();
            }
        #endif /*__MMI_FM_RADIO_ANIMATION__*/ 
           if (is_freq_changed)
	        {
	            mmi_fmrdo_search_frequency_start(freq, MMI_FALSE);
			}
			else
			{
				mmi_fmrdo_search_frequency_start(g_fmrdo.frequency, MMI_FALSE);
			} /* do search in non-blocking mode */
        #endif /* __FM_RADIO_HW_SEARCH__ */ 
        }
        else
    #endif /* ((!defined(__MMI_FTE_SUPPORT__)) && (!defined(__MMI_SLIM_IMG_RES__))) */
        {
        #ifdef __MMI_FTE_SUPPORT__
            if(g_fmrdo.state != FMRDO_STATE_SEARCH_ONE && !g_fmrdo_entry_from_search_one)
        #endif /* __MMI_FTE_SUPPORT__ */
            {
                mmi_fmrdo_set_frequency(freq);
            }
        }
        if(g_fmrdo.normal_repeat_step_count)
	    {
	    	if (g_fmrdo.mute)
			{
			    mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
			}
			else
			{
			   	mmi_fmrdo_set_volume(g_fmrdo.volume);
		}
		}
        g_fmrdo.normal_repeat_step_count = 0;
        g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
	g_fmrdo_entry_from_search_one = MMI_FALSE;
    }
}

#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_long_press_step_down_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_long_press_step_down_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq;
    MMI_BOOL is_freq_changed = (g_fmrdo.normal_repeat_step_count != 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_fmrdo.is_power_on)
    {
        return;
    }
    if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_STEP_DOWN)
    {
        if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_STEP_DOWN))
        {
            StopTimer(FMRDO_REPEAT_STEP_TIMER);
            mmi_fmrdo_redraw_main_push_button(
                g_fmrdo.selected_button,
                g_fmrdo.is_button_down);
            if (is_freq_changed)
            {
                freq = g_fmrdo.step_freq;   /* frequency is changed so we don't need to decrease it again */
            }
            else
            {
                /* frequency is not changed during button press down so we need to decrease it */
                if (g_fmrdo.frequency > MIN_FM_FREQUENCY)
                {
                    freq = g_fmrdo.frequency - 1;
                }
                else
                {
                    freq = MAX_FM_FREQUENCY;
                }
            }
        #ifdef __FM_RADIO_HW_SEARCH__
            if (is_freq_changed)
	        {
            mmi_fmrdo_hw_search_frequency_start(freq, MMI_FALSE);
			}
			else
			{
				mmi_fmrdo_hw_search_frequency_start(g_fmrdo.frequency, MMI_FALSE);
			}
        #else 
            mmi_fmrdo_redraw_main_channel_name((UI_string_type) GetString(STR_GLOBAL_SEARCHING));
			if (is_freq_changed)
			{
            mmi_fmrdo_search_frequency_start(freq, MMI_FALSE);
			}
			else
			{
				mmi_fmrdo_search_frequency_start(g_fmrdo.frequency, MMI_FALSE);
			}            
        #endif 
        }
    }
}
#endif /* __MMI_FTE_SUPPORT__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_step_up_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_step_up_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down 
        #if defined(__MMI_FM_RADIO_RECORD__) && defined(__MMI_FTE_SUPPORT__)
            || animate_count
         #endif /*defined(__MMI_FM_RADIO_RECORD__) && defined(__MMI_FTE_SUPPORT__)*/
       )
    {
    #ifndef __RF_DESENSE_TEST__
        return;
    #endif
    }
    g_fmrdo.selected_button = FMRDO_BUTTON_STEP_UP;
    g_fmrdo.is_button_down = MMI_TRUE;
    g_fmrdo.normal_repeat_step_count = 0;
#ifndef __MMI_MAINLCD_96X64__
    mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
#endif
    mmi_fmrdo_search_frequency_stop();
#ifdef __MMI_FTE_SUPPORT__
    g_fmrdo_search_freq_changed = MMI_FALSE;
#endif
#ifndef __MMI_FM_PLUTO_SLIM__
    g_fmrdo.step_freq = g_fmrdo.frequency;
    StartTimer(FMRDO_REPEAT_STEP_TIMER, NORMAL_REAPEAT_STEP_PERIOD, mmi_fmrdo_step_up_timer);

    /* stop previous twinkle frequency if necessary */
    mmi_fmrdo_stop_twinkle_frequency(MMI_TRUE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_step_up_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_step_up_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq;
    MMI_BOOL is_freq_changed = (g_fmrdo.normal_repeat_step_count != 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_STEP_UP)
    {
        StopTimer(FMRDO_REPEAT_STEP_TIMER);

        g_fmrdo.is_button_down = MMI_FALSE;
#ifndef __MMI_MAINLCD_96X64__
        mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
#endif
    #ifdef __MMI_FTE_SUPPORT__
        if((g_fmrdo.state != FMRDO_STATE_SEARCH_ONE) && !g_fmrdo_search_freq_changed)
        {
    #endif /* __MMI_FTE_SUPPORT__ */
        if (is_freq_changed)
        {
            freq = g_fmrdo.step_freq;   /* frequency is changed so we don't need to increase it again */
        }
        else
        {
            /* frequency is not changed during button press down so we need to increase it */
            if (g_fmrdo.frequency < MAX_FM_FREQUENCY)
            {
                freq = g_fmrdo.frequency + 1;
            }
            else
            {
                freq = MIN_FM_FREQUENCY;
            }
        }
    #ifdef __MMI_FM_RADIO_RDS__
	    if(mmi_fmrdo_rds_is_on())
	    {
    		mmi_fmrdo_rds_clear();
	    }
    #endif/*__MMI_FM_RADIO_RDS__*/
			
    #ifdef __MMI_FTE_SUPPORT__
        }
        else 
        {
            freq = g_fmrdo.frequency;
        }
        g_fmrdo_search_freq_changed = MMI_FALSE;
    #endif /* __MMI_FTE_SUPPORT__ */

    #if ((!defined(__MMI_FTE_SUPPORT__)) && (!defined(__MMI_SLIM_IMG_RES__)))
        if (g_fmrdo.is_power_on && g_fmrdo.is_search_on)
        {
            mmi_fmrdo_search_all_channels_stop();
        #ifdef __FM_RADIO_HW_SEARCH__
#ifndef __MMI_FM_PLUTO_SLIM__
            mmi_fmrdo_start_twinkle_searching();
#endif
            mmi_fmrdo_entry_hw_searching_screen();
            if (is_freq_changed)
	        {
	            mmi_fmrdo_hw_search_frequency_start(freq, MMI_TRUE);
			}
			else
			{
            mmi_fmrdo_hw_search_frequency_start(g_fmrdo.frequency, MMI_TRUE);
			}
		mmi_fmrdo_update_center_key_status();
        #else /* FM_RADIO_HW_SEARCH */ 
            mmi_fmrdo_redraw_main_channel_name((UI_string_type) GetString(STR_GLOBAL_SEARCHING));     /* show searching text */
        #ifdef __MMI_FM_RADIO_ANIMATION__
        #ifdef __RF_DESENSE_TEST__  /*Added by Akhil*/
          if(rf_desense_get_curr_mode() != RF_DESENSE_MODE_FM_NO_ANIMATION)
        #endif /*__RF_DESENSE_TEST__*/
            {
                mmi_fmrdo_animation_stop();
            }
        #endif 
            if (is_freq_changed)
			{
				mmi_fmrdo_search_frequency_start(freq, MMI_TRUE);
			}
			else
			{
				mmi_fmrdo_search_frequency_start(g_fmrdo.frequency, MMI_TRUE);
			}      /* do search in non-blocking mode */
        #endif /* __FM_RADIO_HW_SEARCH__ */ 
        }
        else
    #endif /* ((!defined(__MMI_FTE_SUPPORT__)) && (!defined(__MMI_SLIM_IMG_RES__))) */
        {
        #ifdef __MMI_FTE_SUPPORT__
            if(g_fmrdo.state != FMRDO_STATE_SEARCH_ONE && !g_fmrdo_entry_from_search_one)
        #endif
            {
                mmi_fmrdo_set_frequency(freq);
            }
        }
	    if(g_fmrdo.normal_repeat_step_count)
		{
			if (g_fmrdo.mute)
		    {
		        mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
		    }
		    else
		    {
				mmi_fmrdo_set_volume(g_fmrdo.volume);
		}
		}
	g_fmrdo_entry_from_search_one = MMI_FALSE;
        g_fmrdo.normal_repeat_step_count = 0;
        g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
    }
}

#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_long_press_step_up_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_long_press_step_up_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq;
    MMI_BOOL is_freq_changed = (g_fmrdo.normal_repeat_step_count != 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_fmrdo.is_power_on)
    {
        return;
    }
    if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_STEP_UP)
    {
        if (!mmi_fmrdo_need_disable_button(FMRDO_BUTTON_STEP_UP))
        {
            StopTimer(FMRDO_REPEAT_STEP_TIMER);
            mmi_fmrdo_redraw_main_push_button(
                g_fmrdo.selected_button,
                g_fmrdo.is_button_down);
            if (is_freq_changed)
            {
                freq = g_fmrdo.step_freq;   /* frequency is changed so we don't need to decrease it again */
            }
            else
            {
                /* frequency is not changed during button press down so we need to decrease it */
                if (g_fmrdo.frequency < MAX_FM_FREQUENCY)
                {
                    freq = g_fmrdo.frequency + 1;
                }
                else
                {
                    freq = MIN_FM_FREQUENCY;
                }
            }
        #ifdef __FM_RADIO_HW_SEARCH__
            if (is_freq_changed)
	        {
            mmi_fmrdo_hw_search_frequency_start(freq, MMI_TRUE);
			}
			else
			{
				mmi_fmrdo_hw_search_frequency_start(g_fmrdo.frequency, MMI_TRUE);
			}
        #else 
            mmi_fmrdo_redraw_main_channel_name((UI_string_type) GetString(STR_GLOBAL_SEARCHING));
            if (is_freq_changed)
			{
            mmi_fmrdo_search_frequency_start(freq, MMI_TRUE);
			}
			else
			{
				mmi_fmrdo_search_frequency_start(g_fmrdo.frequency, MMI_TRUE);
			}   
        #endif 
        }
	}
}
#endif /* __MMI_FTE_SUPPORT__ */ 


#if (defined(__MMI_SLIM_IMG_RES__) && !defined(__MMI_FTE_SUPPORT__))
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_search_down_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_search_down_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down)
    {
        return;
    }
    if (!g_fmrdo.is_power_on)
    {
        return;
    }

    g_fmrdo.selected_button = FMRDO_BUTTON_SEARCH_DOWN;
    g_fmrdo.is_button_down = MMI_TRUE;
    g_fmrdo.normal_repeat_step_count = 0;
#ifndef __MMI_MAINLCD_96X64__
    mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
#endif
    mmi_fmrdo_search_frequency_stop();
    g_fmrdo.step_freq = g_fmrdo.frequency;
#ifndef __MMI_FM_PLUTO_SLIM__
    /* stop previous twinkle frequency if necessary */
    mmi_fmrdo_stop_twinkle_frequency(MMI_TRUE);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_search_up_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_search_up_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down)
    {
        return;
    }
    if (!g_fmrdo.is_power_on)
    {
        return;
    }
	g_fmrdo.selected_button = FMRDO_BUTTON_SEARCH_UP;
	g_fmrdo.is_button_down = MMI_TRUE;	
    g_fmrdo.normal_repeat_step_count = 0;
#ifndef __MMI_MAINLCD_96X64__
    mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
#endif
    mmi_fmrdo_search_frequency_stop();
    g_fmrdo.step_freq = g_fmrdo.frequency;
#ifndef __MMI_FM_PLUTO_SLIM__
    /* stop previous twinkle frequency if necessary */
    mmi_fmrdo_stop_twinkle_frequency(MMI_TRUE);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_search_down_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_search_down_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq;
    MMI_BOOL is_freq_changed = (g_fmrdo.normal_repeat_step_count != 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_SEARCH_DOWN)
    {
        StopTimer(FMRDO_REPEAT_STEP_TIMER);
        g_fmrdo.is_button_down = MMI_FALSE;
#ifndef __MMI_MAINLCD_96X64__
        mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
#endif
        if (is_freq_changed)
        {
            freq = g_fmrdo.step_freq;   /* frequency is changed so we don't need to decrease it again */
        }
        else
        {
            /* frequency is not changed during button press down so we need to decrease it */
            if (g_fmrdo.frequency > MIN_FM_FREQUENCY)
            {
                freq = g_fmrdo.frequency - 1;
            }
            else
            {
                freq = MAX_FM_FREQUENCY;
            }
        }
        if (g_fmrdo.is_power_on)
        {
        	mmi_fmrdo_search_all_channels_stop();
        #ifdef __FM_RADIO_HW_SEARCH__
		#ifndef __MMI_FM_PLUTO_SLIM__
            mmi_fmrdo_start_twinkle_searching();
		#endif
            mmi_fmrdo_entry_hw_searching_screen();
            if (is_freq_changed)
	        {
	            mmi_fmrdo_hw_search_frequency_start(freq, MMI_FALSE);
			}
			else
			{
            mmi_fmrdo_hw_search_frequency_start(g_fmrdo.frequency, MMI_FALSE);
			}
        #else /* FM_RADIO_HW_SEARCH */ 
            mmi_fmrdo_redraw_main_channel_name((UI_string_type) GetString(STR_GLOBAL_SEARCHING));     /* show searching text */
            if (is_freq_changed)
			{
				mmi_fmrdo_search_frequency_start(freq, MMI_FALSE);
			}
			else
			{
				mmi_fmrdo_search_frequency_start(g_fmrdo.frequency, MMI_FALSE);
			}    /* do search in non-blocking mode */
        #endif /* __FM_RADIO_HW_SEARCH__ */ 
        }
        else
        {
            mmi_fmrdo_set_frequency(freq);
        }
        g_fmrdo.normal_repeat_step_count = 0;
        g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_search_up_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_search_up_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq;
    MMI_BOOL is_freq_changed = (g_fmrdo.normal_repeat_step_count != 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_SEARCH_UP)
    {
        StopTimer(FMRDO_REPEAT_STEP_TIMER);

        g_fmrdo.is_button_down = MMI_FALSE;
#ifndef __MMI_MAINLCD_96X64__
        mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
#endif
        if (is_freq_changed)
        {
            freq = g_fmrdo.step_freq;   /* frequency is changed so we don't need to increase it again */
        }
        else
        {
            /* frequency is not changed during button press down so we need to increase it */
            if (g_fmrdo.frequency < MAX_FM_FREQUENCY)
            {
                freq = g_fmrdo.frequency + 1;
            }
            else
            {
                freq = MIN_FM_FREQUENCY;
            }
        }
        if (g_fmrdo.is_power_on)
        {
            mmi_fmrdo_search_all_channels_stop();
        #ifdef __FM_RADIO_HW_SEARCH__
        #ifndef __MMI_FM_PLUTO_SLIM__
            mmi_fmrdo_start_twinkle_searching();
        #endif
            mmi_fmrdo_entry_hw_searching_screen();
			if (is_freq_changed)
	        {
	            mmi_fmrdo_hw_search_frequency_start(freq, MMI_TRUE);
			}
			else
			{
            mmi_fmrdo_hw_search_frequency_start(g_fmrdo.frequency, MMI_TRUE);
			}
        #else /* FM_RADIO_HW_SEARCH */ 
            mmi_fmrdo_redraw_main_channel_name((UI_string_type) GetString(STR_GLOBAL_SEARCHING));     /* show searching text */
			if (is_freq_changed)
	        {
	            mmi_fmrdo_search_frequency_start(freq, MMI_TRUE);
			}
			else
			{
				mmi_fmrdo_search_frequency_start(g_fmrdo.frequency, MMI_TRUE);
			}
               /* do search in non-blocking mode */
        #endif /* __FM_RADIO_HW_SEARCH__ */ 
        }
        else
        {
            mmi_fmrdo_set_frequency(freq);
        }
        g_fmrdo.normal_repeat_step_count = 0;
        g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
    }
}

#else /* __MMI_SLIM_IMG_RES__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_search_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_search_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_SUPPORT__
    if (g_fmrdo.is_button_down || !g_fmrdo.is_power_on)
    {
        return;
    }

    g_fmrdo.selected_button = FMRDO_BUTTON_SEARCH;
    g_fmrdo.is_button_down = MMI_TRUE;

    mmi_fmrdo_redraw_main_toggle_button(g_fmrdo.selected_button, g_fmrdo.is_button_down, g_fmrdo.is_search_on, MMI_TRUE);
#endif /* __MMI_FTE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_search_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_search_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FTE_SUPPORT__
    if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_SEARCH && g_fmrdo.is_power_on)
    {
        g_fmrdo.is_button_down = MMI_FALSE;
        g_fmrdo.is_search_on = !g_fmrdo.is_search_on;

        mmi_fmrdo_redraw_main_toggle_button(
                        g_fmrdo.selected_button,
                        g_fmrdo.is_button_down,
                        g_fmrdo.is_search_on,
                        MMI_TRUE);

        mmi_fmrdo_search_frequency_stop();
        /* stop if it's searching */
    #ifdef __MMI_FM_RADIO_ANIMATION__
    #ifdef __RF_DESENSE_TEST__  /*Added by Akhil*/
        if(rf_desense_get_curr_mode() != RF_DESENSE_MODE_FM_NO_ANIMATION)
    #endif /*__RF_DESENSE_TEST__*/
        {
            if (g_fmrdo.is_ready && mmi_fmrdo_get_animation_handle() == GDI_ERROR_HANDLE)
            {
                mmi_fmrdo_animation_start();
            }
        }
    #endif /* __MMI_FM_RADIO_ANIMATION__ */ 

        g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
    }
#endif /* __MMI_FTE_SUPPORT__ */
}
#endif /* __MMI_SLIM_IMG_RES__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_power_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_power_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down 
#ifdef __MMI_FTE_SUPPORT__ 
#ifdef __MMI_FM_RADIO_RECORD__
        || animate_count
#endif/*__MMI_FTE_SUPPORT__*/
#endif/*__MMI_FM_RADIO_RECORD__*/
        )
    {
        return;
    }
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif /* __MMI_BACKGROUND_CALL__ */ 

    //if (mmi_fmrdo_earphone_check_invalid_and_popup())
    //{
    //    return;
    //}
    
    g_fmrdo.selected_button = FMRDO_BUTTON_POWER;
    g_fmrdo.is_button_down = MMI_TRUE;
#ifndef __MMI_MAINLCD_96X64__
    mmi_fmrdo_redraw_main_toggle_button(g_fmrdo.selected_button, g_fmrdo.is_button_down, g_fmrdo.is_power_on, MMI_TRUE);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_power_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_power_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_POWER)
{
    g_fmrdo.is_button_down = MMI_FALSE;

#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
    if (!srv_earphone_is_plug_in())
    {
    #ifndef __MMI_MAINLCD_96X64__
        mmi_fmrdo_redraw_main_toggle_button(g_fmrdo.selected_button, g_fmrdo.is_button_down, g_fmrdo.is_power_on, MMI_TRUE);
    #ifndef __MMI_SLIM_IMG_RES__
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT 
        if (g_fmrdo.is_power_on)
        {
            mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_SEARCH, MMI_FALSE, g_fmrdo.is_search_on, MMI_TRUE);
        }
        else
        {
            mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_SEARCH, MMI_FALSE, MMI_FALSE, MMI_TRUE);
        }
    #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
    #endif /* __MMI_SLIM_IMG_RES__ */  
	#endif
        g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
        
        mmi_popup_display_simple_ext(STR_ID_FMRDO_PLEASE_PLUG_IN_EARPHONE,
                                 MMI_EVENT_INFO,
                                 GRP_ID_FMRDO, 
                                 NULL);
        return ;
    }
#endif /* __MMI_FM_RADIO_BIND_EARPHONE__ */

    /* stop if it's searching */
    mmi_fmrdo_search_frequency_stop();

    /* power off if it's on */
    mmi_fmrdo_power_on_check((MMI_BOOL) ! g_fmrdo.is_power_on);
	#ifndef __MMI_MAINLCD_96X64__
	if(g_fmrdo.in_main_screen)
	{
    mmi_fmrdo_redraw_main_toggle_button(g_fmrdo.selected_button, g_fmrdo.is_button_down, g_fmrdo.is_power_on, MMI_TRUE);
#ifndef __MMI_SLIM_IMG_RES__
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT 

    if (g_fmrdo.is_power_on)
    {
         mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_SEARCH, MMI_FALSE, g_fmrdo.is_search_on, MMI_TRUE);
    }
    else
    {
        mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_SEARCH, MMI_FALSE, MMI_FALSE, MMI_TRUE);
    }
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
#endif /* __MMI_SLIM_IMG_RES__ */
	}
	#endif
#if 0
#ifdef __MMI_FM_RADIO_RDS__
/* under construction !*/
#endif/*__MMI_FM_RADIO_RDS__*/
#endif
    g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_exit_root
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param_p     [IN]     
 * RETURNS
 *  U8
 *****************************************************************************/
mmi_ret mmi_fmrdo_exit_root(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_fmrdo.is_background_play)
    {
        mmi_fmrdo_power_on_check(MMI_FALSE);
    }
    else if (g_fmrdo.is_power_on)
    {
        // TODO: MAUI_03144423
        mmi_fmrdo_search_all_channels_stop();
        if (mdi_audio_set_background_handler(MDI_BACKGROUND_APP_FMR, (mdi_bg_callback) mmi_fmrdo_continued, NULL) != MDI_AUDIO_ERROR)
        {
            mdi_audio_clear_other_background_handler(MDI_BACKGROUND_APP_FMR);
        }
    }		
    /* Keep frequency after exit FM radio */
    WriteValueSlim(NVRAM_FMRDO_LAST_CHANNEL, &g_fmrdo.frequency, DS_SHORT);
#ifdef __BT_SPK_VOL_CONTROL__
    if (!g_fmrdo.is_background_play || g_fmrdo.is_power_on == MMI_FALSE)
    {
        mdi_audio_bt_clear_volume_sync_callback(APP_FMRDO);
    }
#endif /* __BT_SPK_VOL_CONTROL__ */ 
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
#ifdef __MMI_NCENTER_SUPPORT__
	if(mmi_fmrdo_is_power_on())
	{	
		mmi_fmrdo_ncenter_add_fm();
	}
#endif
#ifdef __MMI_FM_VIA_A2DP__
	  mmi_fmrdo_a2dp_connect_stop_animation();
#endif
#ifdef __MMI_AVRCP_SUPPORT__
		mmi_fmrdo_avrcp_clear_cmd_hdlr();
#endif
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_main_register_keys
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_fmrdo_pen_down_hdlr(mmi_pen_point_struct pos);
extern void mmi_fmrdo_pen_up_hdlr(mmi_pen_point_struct pos);
extern void mmi_fmrdo_pen_move_hdlr(mmi_pen_point_struct pos);
extern void mmi_fmrdo_pen_repeat_hdlr(mmi_pen_point_struct pos);
#ifdef __MMI_FTE_SUPPORT__
extern void mmi_fmrdo_pen_long_tap_hdlr(mmi_pen_point_struct pos);
#endif 
#endif /* __MMI_TOUCH_SCREEN__ */ 


#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__

void mmi_fmrdo_update_down_arrow_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_fmrdo.is_button_down)
    {
        return;
    }
    g_fmrdo.selected_button = FMRDO_BUTTON_MEMO_DOWN;
    g_fmrdo.is_button_down = MMI_FALSE;

    mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);

    mmi_fmrdo_dec_volume();
}

void mmi_fmrdo_update_up_arrow_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_fmrdo.is_button_down)
    {
        return;
    }
    g_fmrdo.selected_button = FMRDO_BUTTON_MEMO_UP;
    g_fmrdo.is_button_down = MMI_FALSE;

    mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);

    mmi_fmrdo_inc_volume();
}


void mmi_fmrdo_pre_release_memo_down_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!g_fmrdo.is_button_down)
    {
        return;
    }
    
    mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
    mmi_fmrdo_search_frequency_stop();

    StartTimer(FMRDO_DISPLAY_BUTTON_TMER, 200, mmi_fmrdo_release_memo_down_button);
}


void mmi_fmrdo_pre_release_memo_up_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_fmrdo.is_button_down)
    {
        return;
    }

    mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
    mmi_fmrdo_search_frequency_stop();

    StartTimer(FMRDO_DISPLAY_BUTTON_TMER, 200, mmi_fmrdo_release_memo_up_button);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_switch_loudspeaker
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_switch_loudspeaker(void)
{
#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)

	/* Turn off then turn on to switch output path */
	if (g_fmrdo.is_power_on)
	{
	    g_fmrdo.loud_speaker_on = !g_fmrdo.loud_speaker_on;
		if (g_fmrdo.loud_speaker_on)
		{
	#ifdef __MMI_BT_FM_VIA_SCO__
			srv_btsco_disable_sco_connection(SRV_BT_SCO_INT_FMRADIO);
	#endif
	#ifdef	__MMI_FM_VIA_A2DP__
            srv_a2dp_pause_stream();
	#endif
			mdi_fmr_set_output_path(MDI_DEVICE_SPEAKER_BOTH);
		}
		else
		{
    #ifdef __MMI_BT_FM_VIA_SCO__
			srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_FMRADIO);
	#endif
    #ifdef __MMI_FM_VIA_A2DP__
        if(mmi_a2dp_is_output_to_bt() && !fm_a2dp_connected)
        {
            mmi_fmrdo_change_state_a2dp_connect();
            srv_a2dp_open_source(mmi_a2dp_get_bt_headset(), MMI_TRUE);
//			av_bt_open_ex((srv_bt_cm_bt_addr *)mmi_a2dp_get_bt_headset(),a2dp_info.sample_rate,a2dp_info.is_stereo,
//					mmi_fmrdo_bt_open_callback,KAL_TRUE);
        }
       #endif
            mdi_fmr_set_output_path(MDI_DEVICE_SPEAKER2);
        }
    }
#endif /* defined(__MMI_FM_RADIO_LOUD_SPEAK__) */ 
#endif/*#ifdef __MMI_FM_RADIO_BIND_EARPHONE__*/
}

#endif /* __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__ */

void mmi_fmrdo_main_register_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 number_keys[] = {KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9};
    const mmi_fmrdo_skin_struct *skin_p = &g_fmrdo_skins[g_fmrdo.skin_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MAINLCD_96X64__
#else /*__MMI_MAINLCD_96X64__*/
#ifndef __MMI_FTE_SUPPORT__
#ifdef __MMI_SLIM_IMG_RES__
    void (*button_press_hdlr[]) (void) =
    {
        MMI_dummy_function,                     /* FMRDO_BUTTON_NONE */
        mmi_fmrdo_press_power_button,           /* FMRDO_BUTTON_POWER */
        mmi_fmrdo_press_search_up_button,       /* FMRDO_BUTTON_SEARCH_UP */
        mmi_fmrdo_press_search_down_button,     /* FMRDO_BUTTON_SEARCH_DOWN */
        mmi_fmrdo_press_step_up_button,         /* FMRDO_BUTTON_STEP_UP */
        mmi_fmrdo_press_step_down_button        /* FMRDO_BUTTON_STEP_DOWN */
    };
    void (*button_release_hdlr[]) (void) =
    {
        MMI_dummy_function,                     /* FMRDO_BUTTON_NONE */
        mmi_fmrdo_release_power_button,         /* FMRDO_BUTTON_POWER */
        mmi_fmrdo_release_search_up_button,     /* FMRDO_BUTTON_SEARCH_UP */
        mmi_fmrdo_release_search_down_button,   /* FMRDO_BUTTON_SEARCH_DOWN */
        mmi_fmrdo_release_step_up_button,       /* FMRDO_BUTTON_STEP_UP */
        mmi_fmrdo_release_step_down_button      /* FMRDO_BUTTON_STEP_DOWN */
    };
#else /* __MMI_SLIM_IMG_RES__ */
    void (*button_press_hdlr[]) (void) =
    {
        MMI_dummy_function,                     /* FMRDO_BUTTON_NONE */
            mmi_fmrdo_press_power_button,       /* FMRDO_BUTTON_POWER */
            mmi_fmrdo_press_search_button,      /* FMRDO_BUTTON_SEARCH */
            mmi_fmrdo_press_step_up_button,     /* FMRDO_BUTTON_STEP_UP */
            mmi_fmrdo_press_step_down_button    /* FMRDO_BUTTON_STEP_DOWN */
    };
    void (*button_release_hdlr[]) (void) =
    {
        MMI_dummy_function,                     /* FMRDO_BUTTON_NONE */
            mmi_fmrdo_release_power_button,     /* FMRDO_BUTTON_POWER */
            mmi_fmrdo_release_search_button,    /* FMRDO_BUTTON_SEARCH */
            mmi_fmrdo_release_step_up_button,   /* FMRDO_BUTTON_STEP_UP */
            mmi_fmrdo_release_step_down_button  /* FMRDO_BUTTON_STEP_DOWN */
    };
#endif /*__MMI_SLIM_IMG_RES__*/
#else /* __MMI_FTE_SUPPORT__ */
    void (*button_press_hdlr[]) (void) =
    {
        MMI_dummy_function,                     /* FMRDO_BUTTON_NONE */
            mmi_fmrdo_press_power_button,       /* FMRDO_BUTTON_POWER */
            mmi_fmrdo_press_step_up_button,     /* FMRDO_BUTTON_STEP_UP */
        #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
            mmi_fmrdo_press_step_down_button    /* FMRDO_BUTTON_STEP_DOWN */
        #else
            mmi_fmrdo_press_step_down_button,    /* FMRDO_BUTTON_STEP_DOWN */
            mmi_fmrdo_press_memo_up_button,
            mmi_fmrdo_press_memo_down_button
        #endif
    };
    void (*button_release_hdlr[]) (void) =
    {
        MMI_dummy_function,                     /* FMRDO_BUTTON_NONE */
            mmi_fmrdo_release_power_button,     /* FMRDO_BUTTON_POWER */
            mmi_fmrdo_release_step_up_button,   /* FMRDO_BUTTON_STEP_UP */
        #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
            mmi_fmrdo_release_step_down_button  /* FMRDO_BUTTON_STEP_DOWN */
        #else
            mmi_fmrdo_release_step_down_button,  /* FMRDO_BUTTON_STEP_DOWN */
            mmi_fmrdo_release_memo_up_button,
            mmi_fmrdo_release_memo_down_button
        #endif
    };
    void (*button_long_press_hdlr[]) (void) =
    {
        MMI_dummy_function,                     /* FMRDO_BUTTON_NONE */
            MMI_dummy_function,     /* FMRDO_BUTTON_POWER */
            mmi_fmrdo_long_press_step_up_button,   /* FMRDO_BUTTON_STEP_UP */
            mmi_fmrdo_long_press_step_down_button,  /* FMRDO_BUTTON_STEP_DOWN */
			MMI_dummy_function, /*FMRDO_BUTTON_MEMO_DOWN*/
			MMI_dummy_function /*FMRDO_BUTTON_MEMO_UP*/
    };

    SetKeyLongpressHandler(button_long_press_hdlr[skin_p->left_key_mapping], KEY_LEFT_ARROW);
    SetKeyLongpressHandler(button_long_press_hdlr[skin_p->right_key_mapping], KEY_RIGHT_ARROW);
    SetKeyLongpressHandler(button_long_press_hdlr[skin_p->up_key_mapping], KEY_UP_ARROW);
    SetKeyLongpressHandler(button_long_press_hdlr[skin_p->down_key_mapping], KEY_DOWN_ARROW);
#endif /* __MMI_FTE_SUPPORT__ */
    /* associate button press, release handlers with skin settings and register arrow key handlers */
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    SetKeyUpHandler(button_release_hdlr[skin_p->left_key_mapping], KEY_LEFT_ARROW);
    SetKeyUpHandler(button_release_hdlr[skin_p->right_key_mapping], KEY_RIGHT_ARROW);
    SetKeyUpHandler(button_release_hdlr[skin_p->up_key_mapping], KEY_UP_ARROW);
    SetKeyUpHandler(button_release_hdlr[skin_p->down_key_mapping], KEY_DOWN_ARROW);
    
    SetKeyDownHandler(button_press_hdlr[skin_p->left_key_mapping], KEY_LEFT_ARROW);
    SetKeyDownHandler(button_press_hdlr[skin_p->right_key_mapping], KEY_RIGHT_ARROW);
    SetKeyDownHandler(button_press_hdlr[skin_p->up_key_mapping], KEY_UP_ARROW);
    SetKeyDownHandler(button_press_hdlr[skin_p->down_key_mapping], KEY_DOWN_ARROW);
#else
    SetKeyUpHandler(button_release_hdlr[skin_p->center_key_mapping], KEY_CSK);
    SetKeyUpHandler(button_release_hdlr[skin_p->left_key_mapping], KEY_LEFT_ARROW);
    SetKeyUpHandler(button_release_hdlr[skin_p->right_key_mapping], KEY_RIGHT_ARROW);
    SetKeyUpHandler(button_release_hdlr[skin_p->up_key_mapping], KEY_UP_ARROW);
    SetKeyUpHandler(button_release_hdlr[skin_p->down_key_mapping], KEY_DOWN_ARROW);
    
    SetKeyDownHandler(button_press_hdlr[skin_p->center_key_mapping], KEY_CSK);
    SetKeyDownHandler(button_press_hdlr[skin_p->left_key_mapping], KEY_LEFT_ARROW);
    SetKeyDownHandler(button_press_hdlr[skin_p->right_key_mapping], KEY_RIGHT_ARROW);
    SetKeyDownHandler(button_press_hdlr[skin_p->up_key_mapping], KEY_UP_ARROW);
    SetKeyDownHandler(button_press_hdlr[skin_p->down_key_mapping], KEY_DOWN_ARROW);    

    SetKeyDownHandler(mmi_fmrdo_inc_volume, KEY_VOL_UP);
    SetKeyDownHandler(mmi_fmrdo_dec_volume, KEY_VOL_DOWN);
    
    SetKeyRepeatHandler(mmi_fmrdo_inc_volume, KEY_VOL_UP);
    SetKeyRepeatHandler(mmi_fmrdo_dec_volume, KEY_VOL_DOWN);

    SetKeyDownHandler(mmi_fmrdo_inc_volume, KEY_POUND);
    SetKeyDownHandler(mmi_fmrdo_dec_volume, KEY_STAR);
    SetKeyRepeatHandler(mmi_fmrdo_inc_volume, KEY_POUND);
    SetKeyRepeatHandler(mmi_fmrdo_dec_volume, KEY_STAR);
#endif

#ifdef __MMI_SLIM_IMG_RES__
    SetKeyUpHandler(button_release_hdlr[FMRDO_BUTTON_POWER], KEY_ENTER);
    SetKeyDownHandler(button_press_hdlr[FMRDO_BUTTON_POWER], KEY_ENTER);
#endif /* __MMI_SLIM_IMG_RES__ */
    SetKeyRepeatHandler(MMI_dummy_function, KEY_UP_ARROW);
    SetKeyRepeatHandler(MMI_dummy_function, KEY_RIGHT_ARROW);
    SetKeyRepeatHandler(MMI_dummy_function, KEY_LEFT_ARROW);
    SetKeyRepeatHandler(MMI_dummy_function, KEY_DOWN_ARROW);

    /* register number key handlers */
    SetGroupKeyHandler(mmi_fmrdo_release_number_key, number_keys, 9, KEY_EVENT_UP);
	#ifndef __MMI_FM_PLUTO_SLIM__
    SetGroupKeyHandler(mmi_fmrdo_long_press_number_key, number_keys, 9, KEY_LONG_PRESS);
    #endif
    /* register LSK, RSK hanlders */
    SetKeyUpHandler(mmi_fmrdo_LSK_up_hdlr, KEY_LSK);
    SetKeyUpHandler(mmi_fmrdo_RSK_up_hdlr, KEY_RSK);
    SetKeyRepeatHandler(MMI_dummy_function, KEY_LSK);
    SetKeyRepeatHandler(MMI_dummy_function, KEY_RSK);

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__

    SetKeyDownHandler(button_press_hdlr[skin_p->left_key_mapping], KEY_UP_ARROW);
    SetKeyDownHandler(button_press_hdlr[skin_p->right_key_mapping], KEY_DOWN_ARROW);

    SetKeyUpHandler(mmi_fmrdo_pre_release_memo_down_button, KEY_UP_ARROW);
    SetKeyUpHandler(mmi_fmrdo_pre_release_memo_up_button, KEY_DOWN_ARROW);

    SetKeyLongpressHandler(mmi_fmrdo_update_up_arrow_handler, KEY_UP_ARROW);
    SetKeyLongpressHandler(mmi_fmrdo_update_down_arrow_handler, KEY_DOWN_ARROW);

    SetKeyRepeatHandler(mmi_fmrdo_inc_volume, KEY_UP_ARROW);
    SetKeyRepeatHandler(mmi_fmrdo_dec_volume, KEY_DOWN_ARROW);   

    SetKeyLongpressHandler(mmi_idle_display, KEY_RSK);

#endif /*__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__ */

#if (defined(__MMI_TOUCH_SCREEN__) && (!defined(__MMI_SLIM_IMG_RES__)))
    /* register volume inc, dec handlers */
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    SetKeyDownHandler(mmi_fmrdo_press_volume_up, KEY_VOL_UP);
    SetKeyDownHandler(mmi_fmrdo_press_volume_down, KEY_VOL_DOWN);
    SetKeyUpHandler(mmi_fmrdo_release_volume_up, KEY_VOL_UP);
    SetKeyUpHandler(mmi_fmrdo_release_volume_down, KEY_VOL_DOWN);
    SetKeyRepeatHandler(mmi_fmrdo_repeat_volume_up, KEY_VOL_UP);
    SetKeyRepeatHandler(mmi_fmrdo_repeat_volume_down, KEY_VOL_DOWN);
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
#else /* __MMI_TOUCH_SCREEN__ */ 
    SetKeyDownHandler(mmi_fmrdo_inc_volume, KEY_VOL_UP);
    SetKeyDownHandler(mmi_fmrdo_dec_volume, KEY_VOL_DOWN);
#ifdef __MMI_SLIM_IMG_RES__
    SetKeyDownHandler(mmi_fmrdo_inc_volume, KEY_POUND);
    SetKeyDownHandler(mmi_fmrdo_dec_volume, KEY_STAR);
#endif /* __MMI_SLIM_IMG_RES__ */
#endif /* __MMI_TOUCH_SCREEN__ */ 
    /* MTK Leo add 20050301, add touch screen support for FM Radio */
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_register_down_handler(mmi_fmrdo_pen_down_hdlr);
    mmi_pen_register_up_handler(mmi_fmrdo_pen_up_hdlr);
    mmi_pen_register_move_handler(mmi_fmrdo_pen_move_hdlr);
    mmi_pen_register_repeat_handler(mmi_fmrdo_pen_repeat_hdlr);
#ifdef __MMI_FTE_SUPPORT__
    mmi_pen_register_long_tap_handler(mmi_fmrdo_pen_long_tap_hdlr);
    SetKeyDownHandler(mmi_fmrdo_redraw_main_LSK_down, KEY_LSK);
    SetKeyDownHandler(mmi_fmrdo_redraw_main_RSK_down, KEY_RSK);
#endif 
#endif /* __MMI_TOUCH_SCREEN__ */ 
    /* MTK Leo end */

    /* register FM record key handler */
#if (defined(__MMI_FM_RADIO_RECORD__) && (!defined(__MMI_SLIM_IMG_RES__))) /*ry: OK is power in SLIM proj*/
// TODO: remove for key only
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    SetKeyUpHandler(mmi_fmrdo_release_record_button, KEY_ENTER);
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
#endif 
#endif /*__MMI_MAINLCD_96X64__*/

}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    entry_full_screen();
    if(!g_fmrdo.is_power_on && mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_FMR)< 0 )
    {
        mdi_audio_suspend_background_play();
    }
    if (g_fmrdo.is_power_on == MMI_TRUE)
    {
        if (g_fmrdo.mute)
        {
		#ifdef __BT_SPK_VOL_CONTROL__
			mdi_audio_set_volume_to_bt(g_fmrdo.volume);
		#endif
            mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
        }
        else
        {
            mmi_fmrdo_set_volume(g_fmrdo.volume);
        }
	#ifdef __MMI_NCENTER_SUPPORT__
	    if(ncenter_fmrdo_nhandle || ncenter_fmrdo_ghandle)
	    {
		mmi_fmrdo_ncenter_clear_fm();
	    }
	#endif
    }

    /* setup SSE */
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    gui_screen_switch_effect_setup(0, 0, 0);
#endif 

    g_fmrdo.in_main_screen = MMI_TRUE;
#ifdef __MMI_AVRCP_SUPPORT__
		mmi_fmrdo_avrcp_set_cmd_hdlr();
#endif
    /* button state */
    g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
    g_fmrdo.is_button_down = MMI_FALSE;
    g_fmrdo.normal_repeat_step_count = 0;
    g_fmrdo.is_long_press_number_key = MMI_FALSE;
    g_fmrdo.twinkle_frequency_count = 0;

    /* draw main screen */
    mmi_fmrdo_show_main(STR_GLOBAL_OPTIONS, STR_GLOBAL_BACK, g_fmrdo.skin_index);

    /* run SSE */
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    gui_screen_switch_effect_run();
#endif 

    /* Register all key handler */
    mmi_fmrdo_main_register_keys();

#ifdef __MMI_FTE_SUPPORT__
 #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__  
/* under construction !*/
 #endif /* __MMI_TOUCH_FEEDBACK_SUPPORT__  */
#endif
    mmi_fmrdo_update_center_key_status();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_exit_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_exit_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmrdo.in_main_screen = MMI_FALSE;

    /* stop timer and update frequency if we don't release step up/down button yet */
    StopTimer(FMRDO_REPEAT_STEP_TIMER);
    StopTimer(FMRDO_TWINKLE_FREQUENCY_TIMER);
#if defined(__MMI_FM_RADIO_RECORD__)
#ifdef __MMI_FTE_SUPPORT__
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    gui_cancel_timer(mmi_fmrdo_update_record_bar);
#endif 
#endif 
#endif 
    if (g_fmrdo.normal_repeat_step_count != 0)
    {
        mmi_fmrdo_set_frequency(g_fmrdo.step_freq);
    }

#ifdef __MMI_FTE_SUPPORT__
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    mmi_fmrdo_reset_volume_bar();
	g_vol_displayed= 0;
    StopTimer(FMRDO_VOLUME_DISPLAY_TMER);
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */
#endif 
#ifndef __MMI_FM_PLUTO_SLIM__
    /* stop previous twinkle frequency if necessary */
    mmi_fmrdo_stop_twinkle_frequency(MMI_FALSE);
#endif
#ifdef __FM_RADIO_HW_SEARCH__
    /* stop hw searching twinkle */
#ifndef __MMI_FM_PLUTO_SLIM__
    gui_cancel_timer(mmi_fmrdo_twinkle_searching_timer);
#endif
#endif /* __FM_RADIO_HW_SEARCH__ */ 
    /* stop if it's searching */
    mmi_fmrdo_search_frequency_stop();
	g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
    g_fmrdo.is_button_down = MMI_FALSE;
    g_fmrdo.normal_repeat_step_count = 0;
    g_fmrdo.is_long_press_number_key = MMI_FALSE;
    g_fmrdo.twinkle_frequency_count = 0;
#if defined(__MMI_FM_RADIO_RECORD__)
    /* Abort due to exit screen */
    g_fmrdo.rec.user_abort = MMI_FALSE;
    mmi_fmrdo_stop_record_on_exit();
    mmi_fmrdo_util_stop_duration();
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

    mdi_audio_resume_background_play();
    #ifdef __MMI_FTE_SUPPORT__
    #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
    #endif /*__MMI_TOUCH_FEEDBACK_SUPPORT__*/
    #endif
#ifdef __MMI_AVRCP_SUPPORT__
	mmi_fmrdo_avrcp_clear_cmd_hdlr();
#endif

}

#ifdef __MMI_MAINLCD_96X64__

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_exit_change_volume
 * DESCRIPTION
 *  Exit handler for change volume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_exit_change_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SCR_KEY_TONE_VOLUME == mmi_frm_scrn_get_active_id())
    {
        mmi_frm_scrn_close_active_id();
    }
    mmi_fmrdo_set_volume(g_fmrdo.volume);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_set_common_volume
 * DESCRIPTION
 *  Common function to save volume level
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_set_common_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 volume_level = g_fmrdo.volume;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_volume_handler <= MAX_VOL_LEVEL)
    {
        volume_level = g_fmrdo.volume;
        g_fmrdo.volume = g_volume_handler;
		if(g_fmrdo.volume > 0)
		{
			if (g_fmrdo.mute)
			{
				g_fmrdo.mute = 0;
				WriteValueSlim(NVRAM_FMRDO_MUTE, &g_fmrdo.mute, DS_BYTE);
			}
			mmi_fmrdo_set_volume(g_fmrdo.volume);
		}
		else
		{
			g_fmrdo.mute = 1;
			WriteValueSlim(NVRAM_FMRDO_MUTE, &g_fmrdo.mute, DS_BYTE);
			mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
			g_fmrdo.prev_volume = 0;
		}
    }
    if(g_fmrdo.volume != volume_level)
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_FMRDO, NULL);
		if(SCR_KEY_TONE_VOLUME == mmi_frm_scrn_get_active_id())
    	{
        	mmi_frm_scrn_close_active_id();
    	}
    }
	else
	{
		GoBackHistory();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_change_volume
 * DESCRIPTION
 *  Display volume handler screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_change_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetVolumeKeyHandlerFunctions(
            NULL,
            NULL,
            NULL,
            NULL,
            STR_GLOBAL_VOLUME,
            &g_volume_handler,
            STR_GLOBAL_OK,
            STR_GLOBAL_BACK,
        	mmi_fmrdo_set_common_volume, 
            mmi_fmrdo_exit_change_volume,
            0,
            mmi_fmrdo_exit_change_volume,
            1,
            VOLUMEHANDLER_FM_RADIO);
    EntryScrSetKeyPadVolumeLevel(); 
    #ifdef __MMI_FIVE_WAY_NAVIGATION_KEYS__     
		wgui_set_center_softkey_handler(mmi_fmrdo_set_common_volume); 
    #endif 
    mmi_fmrdo_set_volume((U8)g_volume_handler);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_change_volume
 * DESCRIPTION
 *  Entry function for changing volume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_change_volume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_volume_handler = g_fmrdo.volume;
    mmi_fmrdo_change_volume();
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_main_option_menu_cui_proc
 * DESCRIPTION
 *  Screen group callback process
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_fmrdo_main_option_menu_cui_proc(cui_menu_event_struct *menu_evt)
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
            /* Use number as menu icon */
		#ifndef __MMI_FM_PLUTO_SLIM__
            #if (defined(__MMI_VUI_HOMESCREEN_FM_RADIO__) || defined(__MMI_VUI_LAUNCHER_KEY__)) && !(!defined(__MMI_FM_SLIM_SKIN__) && !defined(__MMI_FTE_SUPPORT__)) && \
                !(defined(__MMI_FM_RADIO_LOUD_SPEAK__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)) && \
                !defined(__MMI_FM_RADIO_RECORD__) && !defined(__MMI_FM_RADIO_MONO__) && !defined(__MMI_FM_RADIO_RDS__)
    
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_FMRDO_SETTINGS, MMI_TRUE);
            #endif
		#endif
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

        #ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__        
        #ifdef __MMI_FM_VIA_A2DP__
        #ifdef __MMI_FM_RADIO_RECORD__
			if(!mdi_audio_is_resource_available(MDI_AUDIO_RECORD_FM_RADIO , NULL))
			{
				 cui_menu_set_item_disabled(
	        					menu_evt->sender_id,
	        					MENU_ID_FMRDO_RECORD,
	       						MMI_TRUE);
			}
        #endif
        #endif /*__MMI_FM_VIA_A2DP__*/
        #endif /* __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__ */
        
#ifdef __MMI_MAINLCD_96X64__
			if(mmi_fmrdo_is_power_on())
			{
				cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_FMRDO_POWER_ON, MMI_TRUE);
			}
			else 
			{
				cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_FMRDO_POWER_OFF , MMI_TRUE);
			}
		#endif
        #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_FMRDO_CHANNEL_LIST , MMI_TRUE);
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_FMRDO_MANUAL_INPUT , MMI_TRUE);
			if(mmi_fmrdo_is_power_on())
			{
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_FMRDO_PLAY , MMI_TRUE);
			}
			else 
			{
			    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_FMRDO_STOP, MMI_TRUE);  
			}        
        #if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
            if (srv_earphone_is_plug_in() && g_fmrdo.is_power_on)
            {
                if (g_fmrdo.loud_speaker_on)
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_FMRDO_LOUD_SPEAKER_ON , MMI_TRUE);
                }
                else
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_FMRDO_LOUD_SPEAKER_OFF , MMI_TRUE);
                }
            }
            else
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_FMRDO_LOUD_SPEAKER_ON , MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_FMRDO_LOUD_SPEAKER_OFF , MMI_TRUE);
            }
        #endif
        #endif /*__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__*/           
            break;

        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:

            switch(menu_evt->highlighted_menu_id)
            {
            #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
            case MENU_ID_FMRDO_PLAY:
                if (mmi_fmrdo_earphone_check_invalid_and_popup())
                {
                    return;
                }   
                mmi_fmrdo_power_on_check(MMI_TRUE);
				cui_inline_close(menu_evt->sender_id);
                break;
            case MENU_ID_FMRDO_STOP:
                mmi_fmrdo_power_on_check(MMI_FALSE);
				cui_inline_close(menu_evt->sender_id);
                break;
            #if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
            case MENU_ID_FMRDO_LOUD_SPEAKER_ON:
            case MENU_ID_FMRDO_LOUD_SPEAKER_OFF:
                mmi_fmrdo_switch_loudspeaker();
                cui_inline_close(menu_evt->sender_id);
                break; 
            #endif
            #endif /* __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__ */
            
            #ifdef __MMI_MAINLCD_96X64__
            case MENU_ID_FMRDO_POWER_ON:
                mmi_fmrdo_power_on_check(MMI_TRUE);
				cui_inline_close(menu_evt->sender_id);
                break;
			case MENU_ID_FMRDO_POWER_OFF:
                mmi_fmrdo_power_on_check(MMI_FALSE);
				cui_inline_close(menu_evt->sender_id);
                break;	
			case MENU_ID_FMRDO_VOLUME:
	            mmi_fmrdo_entry_change_volume();
    	        break;
			#endif
            #ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
            case MENU_ID_FMRDO_CHANNEL_LIST:
                mmi_frm_scrn_create(GRP_ID_FMRDO, SCR_ID_FMRDO_CHANNEL_LIST, mmi_fmrdo_channel_scrn_proc, NULL);
                break;
            case MENU_ID_FMRDO_MANUAL_INPUT:
                mmi_fmrdo_entry_manual_input();
                break;
            #endif
            case MENU_ID_FMRDO_PRESET_AUTO_SEARCH:
                mmi_fmrdo_entry_preset_list_confirm();
                break;
			#ifndef __MMI_FM_PLUTO_SLIM__
            case MENU_ID_FMRDO_SETTINGS:
                mmi_fmrdo_entry_settings();
                break;
			#endif
        #ifdef __MMI_FM_RADIO_RECORD__
            case MENU_ID_FMRDO_RECORD:
                mmi_fmrdo_release_record_button();
                break;
            case MENU_ID_FMRDO_FILE_LIST:
                mmi_fmrdo_entry_record_list();
                break;
        #endif /*__MMI_FM_RADIO_RECORD__*/
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
 *  mmi_fmrdo_entry_main_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_main_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Use menu cui to display manin menu */    
    menu_gid = cui_menu_create(GRP_ID_FMRDO, 
                               CUI_MENU_SRC_TYPE_RESOURCE,
                               CUI_MENU_TYPE_OPTION,
                               MENU_ID_FMRDO_MAIN_OPTION,
                               MMI_FALSE,
                               (void*)FMRDO_MENU_CUI_MAIN_OPTION);
    cui_menu_set_default_title_by_id(menu_gid, STR_GLOBAL_OPTIONS, GetRootTitleIcon(MENU_ID_FMRDO_MAIN));
    cui_menu_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_channel_list_item_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        Channel index
 *  str_buff            [IN]        Channel name
 *  img_buff_p          [OUT]       Image
 *  str_img_mask        [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
S32 mmi_fmrdo_channel_list_item_ext(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
   	S32 index;
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	

	for (index = 0; index< data_size; index++)
	{
		mmi_fmrdo_channel_list_item(start_index, menu_data[index].item_list[0], &menu_data[index].image_list[0], 0);
		start_index++;
	}
	return data_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_channel_list_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index          [IN]        Channel index
 *  str_buff            [IN]        Channel name
 *  img_buff_p          [OUT]       Image
 *  str_img_mask        [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_fmrdo_channel_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* show frequency text */
    U16 freq = g_fmrdo.channel_list.freq[item_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (freq == 0)
    {
        mmi_ucs2cpy((CHAR *) str_buff, GetString(STR_GLOBAL_EMPTY_LIST));
    }
    else
    {
        kal_wsprintf(str_buff, "FM %d.%d", freq / 10, freq % 10);
    }

    /* show order icon */
	wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NUMBER);
    *img_buff_p = (PU8)wgui_get_list_menu_icon(item_index,IMG_GLOBAL_L1);
	wgui_restore_list_menu_slim_style();

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_channel_list_item_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  item_index      [IN]        Channel index
 *  hint_array      [OUT]       Hint string
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_fmrdo_channel_list_item_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq = g_fmrdo.channel_list.freq[item_index];
    UI_string_type name = g_fmrdo.channel_list.name[item_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (freq == 0 || mmi_ucs2strlen((CHAR *)name) == 0)
    {
        return 0;
    }
    mmi_ucs2ncpy((CHAR *) hint_array[0], (CHAR *) name, MAX_NAME_INPUT_LEN - 1);

    return 1;
}

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_tap_callback_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_tap_callback_func(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_empty_channel;
    mmi_menu_id highlight_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM) 
    {
        /* only change highlight.  do nothing in tap callback function */
        return;
    }

    /* LSK is Options, and has intuitive command. */
    is_empty_channel= (g_fmrdo.channel_list.freq[index] == 0);

    highlight_item = (is_empty_channel ? MENU_ID_FMRDO_CHANNEL_OPT_EDIT : MENU_ID_FMRDO_CHANNEL_OPT_PLAY);
    mmi_fmrdo_channel_option_LSK(highlight_item);

}
#endif/*__MMI_FTE_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_channel_list_CSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_channel_list_CSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_empty_channel;
    mmi_menu_id highlight_item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_empty_channel= (g_fmrdo.channel_list.freq[channel_list_highlighted_item_index] == 0);
    highlight_item = (is_empty_channel ? MENU_ID_FMRDO_CHANNEL_OPT_EDIT : MENU_ID_FMRDO_CHANNEL_OPT_PLAY);
    mmi_fmrdo_channel_option_LSK(highlight_item);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_channel_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_channel_list(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mmi_frm_scrn_active_evt_struct * evt = (mmi_frm_scrn_active_evt_struct *)param;
    S32 highlighted_item;
#ifdef __MMI_BASIC_UI_STYLE__
    S32 error_flag;
#endif /* __MMI_BASIC_UI_STYLE__ */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if (g_fmrdo.channel_index >= 0)
    {
        highlighted_item = g_fmrdo.channel_index;
    }
    else
    {
        highlighted_item = 0;
    }

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

#ifdef __MMI_BASIC_UI_STYLE__
wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NUMBER);
    wgui_cat1032_show(
        (WCHAR*)GetString(STR_ID_FMRDO_CHANNEL_LIST),
        (U8*)GetImage(GetRootTitleIcon(MENU_ID_FMRDO_MAIN)),
        (WCHAR*)GetString(STR_GLOBAL_OPTIONS),
        (U8*)GetImage(IMG_GLOBAL_OPTIONS),
        (WCHAR*)GetString(STR_GLOBAL_BACK),
        (U8*)GetImage(IMG_GLOBAL_BACK),
        FM_RADIO_CHANNEL_NUM,
        mmi_fmrdo_channel_list_item_ext,
        mmi_fmrdo_channel_list_item_hint,
        highlighted_item,
        0,
        IMG_GLOBAL_L1,
        0,
        (U8*)evt->gui_buffer,
        &error_flag);
wgui_restore_list_menu_slim_style();
#else
    ShowCategory184Screen(
        STR_ID_FMRDO_CHANNEL_LIST,
        GetRootTitleIcon(MENU_ID_FMRDO_MAIN),   /* title text and icon */
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,                     /* LSK text and icon */
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,                        /* RSK text and icon */
        FM_RADIO_CHANNEL_NUM,
        mmi_fmrdo_channel_list_item,
        mmi_fmrdo_channel_list_item_hint,
        highlighted_item,
        (U8*)evt->gui_buffer);
#endif

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    /* Register for intuitive commands */
    wgui_register_tap_callback(mmi_fmrdo_tap_callback_func);
#endif /* __MMI_FTE_SUPPORT__ */

}


static const cui_inline_item_text_edit_struct mmi_fmrdo_manual_input_inline_freq_edit =
{
    0,  /* string id */
    0,    /*default text string id*/
    MAX_MANUAL_INPUT_LEN,    /* string count */
    IMM_INPUT_TYPE_DECIMAL_NUMERIC, /* input type */
    0,    /* input extended type */
    NULL   /* required input mode */
};

static const cui_inline_set_item_struct mmi_fmrdo_manual_input_inline_item[] = 
{
    {CUI_INLINE_ITEM_ID_BASE,   CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0,  (void*)&mmi_fmrdo_manual_input_inline_freq_edit}
};

static const cui_inline_struct mmi_fmrdo_manual_input_inline_cui = 
{
    1,
    STR_ID_FMRDO_MANUAL_INPUT,
    0,
    0, 
    &mmi_fmrdo_inline_cui_softkey, 
    mmi_fmrdo_manual_input_inline_item 
};


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_channel_edit_inline_cui_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_fmrdo_manual_input_inline_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_abort_struct *inline_abort_event;
    cui_event_inline_submit_struct *inline_submit_event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_ABORT:
        {
            inline_abort_event = (cui_event_inline_abort_struct*)evt;
            cui_inline_close(inline_abort_event->sender_id);
            break;
        }
        case EVT_ID_CUI_INLINE_SUBMIT:
        { 
            inline_submit_event = (cui_event_inline_submit_struct*)evt;

            cui_inline_get_value(inline_submit_event->sender_id, CUI_INLINE_ITEM_ID_BASE, (void *)freq_inline_editor_buffer/*manual_input_buffer*/);
            if(mmi_fmrdo_manual_input_LSK())
            {
                cui_inline_close(inline_submit_event->sender_id);
            }
            break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_manual_input
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_manual_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID inline_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(freq_inline_editor_buffer/*manual_input_buffer*/, "%d.%d", g_fmrdo.frequency / 10, g_fmrdo.frequency % 10);

    inline_id = cui_inline_create(GRP_ID_FMRDO, &mmi_fmrdo_manual_input_inline_cui);
    cui_inline_set_parent_data(inline_id, FMRDO_INLINE_CUI_MANUAL_EDIT);

    cui_inline_set_title_icon(inline_id, GetRootTitleIcon(MENU_ID_FMRDO_MAIN));
    cui_inline_set_value(inline_id, CUI_INLINE_ITEM_ID_BASE, (void *)freq_inline_editor_buffer/*manual_input_buffer*/);

    cui_inline_run(inline_id);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_manual_input_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_fmrdo_manual_input_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* calculate frequency number */
    U16 freq = mmi_fmrdo_get_freq_from_str(freq_inline_editor_buffer/*manual_input_buffer*/);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check frequency input */
    if (freq == 0xffff) /* invalid decimal digit */
    {
        mmi_popup_display_simple_ext(STR_ID_FMRDO_VALID_FM_DECIMAL,
                                 MMI_EVENT_FAILURE,
                                 GRP_ID_FMRDO,
                                 NULL);
        return MMI_FALSE;
    }
    else if (freq < MIN_FM_FREQUENCY || freq > MAX_FM_FREQUENCY)        /* warning invalid frequency */
    {
        mmi_popup_display_simple_ext(STR_ID_FMRDO_VALID_FM_BANDWIDTH,
                                 MMI_EVENT_FAILURE,
                                 GRP_ID_FMRDO,
                                 NULL);
        return MMI_FALSE;
    }
    else
    {
        mmi_fmrdo_set_frequency(freq);
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_preset_list_confirm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static mmi_ret mmi_fmrdo_entry_preset_list_confirm_callback(mmi_event_struct *mmi_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct*)mmi_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch(evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_fmrdo_preset_list_confirm_LSK();
                break;
            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;
            default:
                break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_preset_list_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_preset_list_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_arg;
	MMI_STR_ID title = STR_ID_FMRDO_PRESET_LIST;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);

    confirm_arg.parent_id = GRP_ID_FMRDO;
    confirm_arg.callback = mmi_fmrdo_entry_preset_list_confirm_callback;
#ifdef __MMI_MAINLCD_96X64__
	title = STR_ID_FMRDO_AUTO_SEARCH;
#endif
    mmi_confirm_display_ext(title,
                            MMI_EVENT_QUERY,
                            &confirm_arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_preset_list_confirm_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_preset_list_confirm_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
    if (srv_earphone_is_plug_in() && !g_fmrdo.is_power_on)
#else /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
    if (!g_fmrdo.is_power_on)
#endif /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
    {
        mmi_fmrdo_power_on_before_preset_auto_search();
    }

    if (g_fmrdo.is_power_on)    /* if audio is block, power won't be turned on */
    {
        mmi_frm_scrn_create(GRP_ID_FMRDO, SCR_ID_FMRDO_SEARCHING, mmi_fmrdo_search_scrn_proc, NULL);

    /* start search all channels */
    #ifdef __FM_RADIO_HW_SEARCH__
        mmi_fmrdo_hw_search_all_channels_start(mmi_fmrdo_preset_list_done);
    #else 
        mmi_fmrdo_search_all_channels_start(mmi_fmrdo_preset_list_done);
    #endif 
		mmi_fmrdo_update_center_key_status();
    }
    else
    {
    #ifdef __MMI_BACKGROUND_CALL__
        if (srv_ucm_is_background_call())
        {
            mmi_ucm_app_entry_error_message();
        }
        else
    #endif /* __MMI_BACKGROUND_CALL__ */ 
        {
        #ifdef __MMI_FM_RADIO_BIND_EARPHONE__
            mmi_popup_display_simple_ext(STR_ID_FMRDO_PLEASE_PLUG_IN_EARPHONE,
                                     MMI_EVENT_INFO,
                                     GRP_ID_FMRDO, 
                                     NULL);
        #else /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
            mmi_popup_display_simple_ext(STR_ID_FMRDO_POWER_ON_FIRST,
                                     MMI_EVENT_FAILURE,
                                     GRP_ID_FMRDO, 
                                     NULL);
        #endif /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
        }
    }
}

#ifndef __MMI_FM_PLUTO_SLIM__
#if( !(defined(__MMI_VUI_HOMESCREEN_FM_RADIO__) || defined(__MMI_VUI_LAUNCHER_KEY__))||(defined(__MMI_FM_RADIO_LOUD_SPEAK__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)))
static const U16 mmi_fmrdo_setting_inline_on_off_select_text[] =
{
    STR_GLOBAL_OFF, 
    STR_GLOBAL_ON
};

static const cui_inline_item_select_struct mmi_fmrdo_setting_inline_on_off_select = 
{
    2, 0, (U16 *)mmi_fmrdo_setting_inline_on_off_select_text
};
#endif

#if !(defined(__MMI_VUI_HOMESCREEN_FM_RADIO__) || defined(__MMI_VUI_LAUNCHER_KEY__))
static const cui_inline_item_caption_struct mmi_fmrdo_setting_inline_background_caption = 
{
    STR_ID_FMRDO_BACKGROUND_PLAY
};
#endif

#if (!defined(__MMI_FM_SLIM_SKIN__) && !defined(__MMI_FTE_SUPPORT__))
static const cui_inline_item_caption_struct mmi_fmrdo_setting_inline_skin_caption = 
{
    STR_ID_FMRDO_SKIN
};

static const U16 mmi_fmrdo_setting_inline_skin_select_text[] =
{
    STR_ID_FMRDO_SKIN_1,
    STR_ID_FMRDO_SKIN_2,
    STR_ID_FMRDO_SKIN_3
};

static const cui_inline_item_select_struct mmi_fmrdo_setting_inline_skin_select = 
{
    3, 0, (U16 *)mmi_fmrdo_setting_inline_skin_select_text
};
#endif

#if defined(__MMI_FM_RADIO_LOUD_SPEAK__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)
static const cui_inline_item_caption_struct mmi_fmrdo_setting_inline_speaker_caption = 
{
    STR_ID_FMRDO_LOUD_SPEAKER
};
#endif

#if defined(__MMI_FM_RADIO_RECORD__)

static const cui_inline_item_caption_struct mmi_fmrdo_setting_inline_rec_quality_caption = 
{
    STR_ID_FMRDO_RECORD_QUALITY
};

static const U16 mmi_fmrdo_setting_inline_rec_quality_select_text[] =
{
    STR_GLOBAL_LOW,
    STR_GLOBAL_HIGH
};

static const cui_inline_item_select_struct mmi_fmrdo_setting_inline_rec_quality_select = 
{
    NO_OF_QUALITY, 0, (U16 *)mmi_fmrdo_setting_inline_rec_quality_select_text
};

static const cui_inline_item_caption_struct mmi_fmrdo_setting_inline_rec_storage_caption = 
{
    STR_ID_FMRDO_RECORD_STORAGE
};
#endif /*__MMI_FM_RADIO_RECORD__*/

#if defined(__MMI_FM_RADIO_MONO__)
static const cui_inline_item_caption_struct mmi_fmrdo_setting_inline_mono_caption = 
{
    STR_ID_FMRDO_CHANNEL_EFFECT
};

static const U16 mmi_fmrdo_setting_inline_mono_select_text[] =
{
    STR_ID_FMRDO_CHANNEL_STEREO,
    STR_ID_FMRDO_CHANNEL_MONO
};

static const cui_inline_item_select_struct mmi_fmrdo_setting_inline_mono_select = 
{
    2, 0, (U16 *)mmi_fmrdo_setting_inline_mono_select_text
};
#endif

#ifdef __MMI_FM_RADIO_RDS__
static const cui_inline_item_display_only_struct mmi_fmrdo_setting_inline_rds_display = 
{
    STR_ID_FMRDO_RDS_SETTING,
    STR_ID_FMRDO_RDS_SETTING
};
#endif

typedef enum
{
    FMRDO_SETTING_INLINE_BEGIN = CUI_INLINE_ITEM_ID_BASE - 1,
#if !(defined(__MMI_VUI_HOMESCREEN_FM_RADIO__) || defined(__MMI_VUI_LAUNCHER_KEY__))
    FMRDO_SETTING_INLINE_BACKGROUND_CAPTION,
    FMRDO_SETTING_INLINE_BACKGROUND_SELECTOR,
#endif
#if (!defined(__MMI_FM_SLIM_SKIN__) && !defined(__MMI_FTE_SUPPORT__))
    FMRDO_SETTING_INLINE_SKIN_CAPTION,
    FMRDO_SETTING_INLINE_SKIN_SELECTOR,
#endif
#if defined(__MMI_FM_RADIO_LOUD_SPEAK__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)
    FMRDO_SETTING_INLINE_SPEAKER_CAPTION,
    FMRDO_SETTING_INLINE_SPEAKER_SELECTOR,
#endif
#if defined(__MMI_FM_RADIO_RECORD__)
    FMRDO_SETTING_INLINE_REC_QUALITY_CAPTION,
    FMRDO_SETTING_INLINE_REC_QUALITY_SELECTOR,

    FMRDO_SETTING_INLINE_REC_STORAGE_CAPTION,
    FMRDO_SETTING_INLINE_REC_STORAGE_SELECTOR,

#endif /*__MMI_FM_RADIO_RECORD__*/
#if defined(__MMI_FM_RADIO_MONO__)
    FMRDO_SETTING_INLINE_MONO_CAPTION,
    FMRDO_SETTING_INLINE_MONO_SELECTOR,
#endif
#ifdef __MMI_FM_RADIO_RDS__
    FMRDO_SETTING_INLINE_RDS_DISPLAY,
#endif
    FMRDO_SETTING_INLINE_TOTAL
}FMRDO_SETTING_INLINE_ENUM;

typedef enum
{
    FMRDO_SETTING_INLINE_IMAGE = IMG_GLOBAL_LSTART,
#if !(defined(__MMI_VUI_HOMESCREEN_FM_RADIO__) || defined(__MMI_VUI_LAUNCHER_KEY__))
    FMRDO_SETTING_INLINE_BACKGROUND_IMAGE,
#endif
#if (!defined(__MMI_FM_SLIM_SKIN__) && !defined(__MMI_FTE_SUPPORT__))
    FMRDO_SETTING_INLINE_SKIN_IMAGE,
#endif
#if defined(__MMI_FM_RADIO_LOUD_SPEAK__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)
    FMRDO_SETTING_INLINE_SPEAKER_IMAGE,
#endif
#if defined(__MMI_FM_RADIO_RECORD__)
    FMRDO_SETTING_INLINE_REC_QUALITY_IMAGE,
    FMRDO_SETTING_INLINE_REC_STORAGE_IMAGE,
#endif /*__MMI_FM_RADIO_RECORD__*/
#if defined(__MMI_FM_RADIO_MONO__)
    FMRDO_SETTING_INLINE_MONO_IMAGE,
#endif
#ifdef __MMI_FM_RADIO_RDS__
    FMRDO_SETTING_INLINE_RDS_IMAGE,
#endif
    FMRDO_SETTING_INLINE_IMAGE_TOTAL
}FMRDO_SETTING_INLINE_IMAGE_ENUM;

static const cui_inline_set_item_struct mmi_fmrdo_setting_inline_item[] = 
{
#if !(defined(__MMI_VUI_HOMESCREEN_FM_RADIO__) || defined(__MMI_VUI_LAUNCHER_KEY__))
    {FMRDO_SETTING_INLINE_BACKGROUND_CAPTION,   CUI_INLINE_ITEM_TYPE_CAPTION,   FMRDO_SETTING_INLINE_BACKGROUND_IMAGE,  (void*)&mmi_fmrdo_setting_inline_background_caption},
    {FMRDO_SETTING_INLINE_BACKGROUND_SELECTOR,  CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_fmrdo_setting_inline_on_off_select},
#endif
#if (!defined(__MMI_FM_SLIM_SKIN__) && !defined(__MMI_FTE_SUPPORT__))
    {FMRDO_SETTING_INLINE_SKIN_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION,   FMRDO_SETTING_INLINE_SKIN_IMAGE,  (void*)&mmi_fmrdo_setting_inline_skin_caption},
    {FMRDO_SETTING_INLINE_SKIN_SELECTOR,    CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_fmrdo_setting_inline_skin_select},
#endif
#if defined(__MMI_FM_RADIO_LOUD_SPEAK__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)
    {FMRDO_SETTING_INLINE_SPEAKER_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION,   FMRDO_SETTING_INLINE_SPEAKER_IMAGE,  (void*)&mmi_fmrdo_setting_inline_speaker_caption},
    {FMRDO_SETTING_INLINE_SPEAKER_SELECTOR, CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_fmrdo_setting_inline_on_off_select},
#endif
#if defined(__MMI_FM_RADIO_RECORD__)
    {FMRDO_SETTING_INLINE_REC_QUALITY_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION,  FMRDO_SETTING_INLINE_REC_QUALITY_IMAGE,  (void*)&mmi_fmrdo_setting_inline_rec_quality_caption},
    {FMRDO_SETTING_INLINE_REC_QUALITY_SELECTOR, CUI_INLINE_ITEM_TYPE_SELECT,        0,  (void*)&mmi_fmrdo_setting_inline_rec_quality_select},
    {FMRDO_SETTING_INLINE_REC_STORAGE_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION,  FMRDO_SETTING_INLINE_REC_STORAGE_IMAGE,  (void*)&mmi_fmrdo_setting_inline_rec_storage_caption},
    {FMRDO_SETTING_INLINE_REC_STORAGE_SELECTOR, CUI_INLINE_ITEM_TYPE_SELECT,        0,  NULL},
#endif /*__MMI_FM_RADIO_RECORD__*/
#if defined(__MMI_FM_RADIO_MONO__)
    {FMRDO_SETTING_INLINE_MONO_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION,  FMRDO_SETTING_INLINE_MONO_IMAGE,  (void*)&mmi_fmrdo_setting_inline_mono_caption},
    {FMRDO_SETTING_INLINE_MONO_SELECTOR,    CUI_INLINE_ITEM_TYPE_SELECT,        0,  (void*)&mmi_fmrdo_setting_inline_mono_select},
#endif
#ifdef __MMI_FM_RADIO_RDS__
    {FMRDO_SETTING_INLINE_RDS_DISPLAY,  CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,  FMRDO_SETTING_INLINE_RDS_IMAGE,  (void*)&mmi_fmrdo_setting_inline_rds_display},
#endif
    {0, 0, 0, 0},
};

static const cui_inline_struct mmi_fmrdo_setting_inline_cui = 
{
    (FMRDO_SETTING_INLINE_TOTAL - FMRDO_SETTING_INLINE_BEGIN - 1),
    STR_GLOBAL_SETTINGS,
    0,
#ifdef __MMI_FM_RADIO_RDS__
    0,
    &mmi_fmrdo_inline_cui_softkey, 
#else
    CUI_INLINE_SCREEN_DISABLE_DONE, /* Use OK, BACK sytle for setting without RDS */
    &mmi_fmrdo_inline_cui_softkey_save,
#endif    
    mmi_fmrdo_setting_inline_item 
};


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_settings_inline_cui_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_fmrdo_entry_settings_inline_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_abort_struct *inline_abort_event;
    cui_event_inline_submit_struct *inline_submit_event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_ABORT:
        {
            inline_abort_event = (cui_event_inline_abort_struct*)evt;
            cui_inline_close(inline_abort_event->sender_id);
            break;
        }
        case EVT_ID_CUI_INLINE_CSK_PRESS: /* CSK mapping to RSK in disable done style */
        case EVT_ID_CUI_INLINE_SUBMIT:
        { 
            inline_submit_event = (cui_event_inline_submit_struct*)evt;

            /*Get values */
        #if !(defined(__MMI_VUI_HOMESCREEN_FM_RADIO__) || defined(__MMI_VUI_LAUNCHER_KEY__))
            cui_inline_get_value(inline_submit_event->sender_id, FMRDO_SETTING_INLINE_BACKGROUND_SELECTOR, (void *)&selected_background_play);
        #endif
        #if (!defined(__MMI_FM_SLIM_SKIN__) && !defined(__MMI_FTE_SUPPORT__))
            cui_inline_get_value(inline_submit_event->sender_id, FMRDO_SETTING_INLINE_SKIN_SELECTOR, (void *)&selected_skin_index);
        #endif
        #if defined(__MMI_FM_RADIO_LOUD_SPEAK__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)
            cui_inline_get_value(inline_submit_event->sender_id, FMRDO_SETTING_INLINE_SPEAKER_SELECTOR, (void *)&selected_speaker_status);
        #endif
        #if defined(__MMI_FM_RADIO_RECORD__)
            cui_inline_get_value(inline_submit_event->sender_id, FMRDO_SETTING_INLINE_REC_QUALITY_SELECTOR, (void *)&selected_record_quality);
            cui_inline_get_value(inline_submit_event->sender_id, FMRDO_SETTING_INLINE_REC_STORAGE_SELECTOR, (void *)&selected_record_storage);
        #endif /*__MMI_FM_RADIO_RECORD__*/
        #if defined(__MMI_FM_RADIO_MONO__)
            cui_inline_get_value(inline_submit_event->sender_id, FMRDO_SETTING_INLINE_MONO_SELECTOR, (void *)&selected_channel_mono);
        #endif

            /* Save settings */
        #ifdef __MMI_FM_RADIO_RDS__
            mmi_fmrdo_save_setting_confirm();
        #else
            if(mmi_fmrdo_settings_LSK())
            {
                cui_inline_close(inline_submit_event->sender_id);
            }
        #endif

            break;
        }

        case EVT_ID_CUI_INLINE_NOTIFY: /* This event has several sub event. */
        {
            break;
        }

        case EVT_ID_CUI_INLINE_SET_KEY:
        {
        #ifdef __MMI_FM_RADIO_RDS__
            cui_event_inline_set_key_struct *key_evt = (cui_event_inline_set_key_struct*)evt;
            if(key_evt->item_id == FMRDO_SETTING_INLINE_RDS_DISPLAY)
            {
                wgui_inline_set_lsk_function(mmi_fmrdo_rds_setting_prepare_inline_data);
                SetCenterSoftkeyFunction(mmi_fmrdo_rds_setting_prepare_inline_data, KEY_EVENT_UP);
            }
        #endif /*__MMI_FM_RADIO_RDS__*/
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID inline_id;
#if defined(__MMI_FM_RADIO_RECORD__)
    U8  total_drv_num;
    SRV_FMGR_DRVLIST_HANDLE drv_list;
    S32 i;
    U8 drv;
    U8 *storage_str_p[SRV_FMGR_DRV_TOTAL];    
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Init variables */
#ifdef __MMI_FM_RADIO_RDS__
    g_setting_rds_status = g_fmrdo.rds.rds_setting.is_rds_on;
    g_setting_af_status =  g_fmrdo.rds.rds_setting.is_af_on;
    g_setting_tp_status =  g_fmrdo.rds.rds_setting.is_tp_on;
    //g_rds_settings_changed = MMI_FALSE;
#endif 
#if !(defined(__MMI_VUI_HOMESCREEN_FM_RADIO__) || defined(__MMI_VUI_LAUNCHER_KEY__))
    selected_background_play = g_fmrdo.is_background_play;
#endif 
    selected_skin_index = g_fmrdo.skin_index;
#if defined(__MMI_FM_RADIO_MONO__)
    selected_channel_mono = g_fmrdo.mono;
#endif 
#if defined(__MMI_FM_RADIO_LOUD_SPEAK__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)
    selected_speaker_status = g_fmrdo.loud_speaker_on;
#endif 
#if defined(__MMI_FM_RADIO_RECORD__)
    selected_record_quality = g_fmrdo.rec.quality;
#endif /* defined(__MMI_FM_RADIO_RECORD__) */


    /* Init cui */
    inline_id = cui_inline_create(GRP_ID_FMRDO, &mmi_fmrdo_setting_inline_cui);
    cui_inline_set_parent_data(inline_id, FMRDO_INLINE_CUI_SETTING);

    cui_inline_set_title_icon(inline_id, GetRootTitleIcon(MENU_ID_FMRDO_MAIN));

    /* Set initial values */
#if !(defined(__MMI_VUI_HOMESCREEN_FM_RADIO__) || defined(__MMI_VUI_LAUNCHER_KEY__))
    cui_inline_set_value(inline_id, FMRDO_SETTING_INLINE_BACKGROUND_SELECTOR, (void *)selected_background_play);
#endif
#if (!defined(__MMI_FM_SLIM_SKIN__) && !defined(__MMI_FTE_SUPPORT__))
    cui_inline_set_value(inline_id, FMRDO_SETTING_INLINE_SKIN_SELECTOR, (void *)selected_skin_index);
#endif
#if defined(__MMI_FM_RADIO_LOUD_SPEAK__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)
    cui_inline_set_value(inline_id, FMRDO_SETTING_INLINE_SPEAKER_SELECTOR, (void *)selected_speaker_status);
#endif


#if defined(__MMI_FM_RADIO_RECORD__)
    cui_inline_set_value(inline_id, FMRDO_SETTING_INLINE_REC_QUALITY_SELECTOR, (void *)selected_record_quality);

    drv_list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
    selected_record_storage = srv_fmgr_drivelist_get_index_by_drv_letter(drv_list, g_fmrdo.rec.drive);

    total_drv_num = (U8)srv_fmgr_drivelist_count(drv_list); 
    for(i = 0; i < total_drv_num; i++)
    {
        drv = srv_fmgr_drivelist_get_drv_letter(drv_list, i);
        storage_str_p[i] = (U8*)get_string(srv_fmgr_drv_get_string(drv));
    }

    srv_fmgr_drivelist_destroy(drv_list);

    if (total_drv_num > 1)
    {
        cui_inline_set_item_select(inline_id,
                                   FMRDO_SETTING_INLINE_REC_STORAGE_SELECTOR, 
                                   total_drv_num, 
                                   (U8 **) storage_str_p,
                                   selected_record_storage);
        g_setting_has_storage_item = MMI_TRUE;
    }
    else
    {
        cui_inline_delete_item(inline_id,  FMRDO_SETTING_INLINE_REC_STORAGE_CAPTION);
        cui_inline_delete_item(inline_id,  FMRDO_SETTING_INLINE_REC_STORAGE_SELECTOR);
        g_setting_has_storage_item = MMI_FALSE;
    }

#endif /*__MMI_FM_RADIO_RECORD__*/

#if defined(__MMI_FM_RADIO_MONO__)
    cui_inline_set_value(inline_id, FMRDO_SETTING_INLINE_MONO_SELECTOR, (void *)selected_channel_mono);
#endif

#ifdef __MMI_FM_RADIO_RDS__
    cui_inline_set_softkey_icon(inline_id, FMRDO_SETTING_INLINE_RDS_DISPLAY, MMI_CENTER_SOFTKEY, IMG_GLOBAL_COMMON_CSK);
    cui_inline_set_softkey_text(inline_id, FMRDO_SETTING_INLINE_RDS_DISPLAY, MMI_LEFT_SOFTKEY, STR_GLOBAL_EDIT);

    /* Keep CUI ID to close in confirm screen */
    g_setting_inline_cui_id = inline_id;
#endif

    /* Run cui */
    cui_inline_run(inline_id);
}


#ifdef __MMI_FM_RADIO_RDS__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_save_setting_confirm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static mmi_ret mmi_fmrdo_save_setting_confirm_callback(mmi_event_struct *mmi_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct*)mmi_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch(evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_fmrdo_settings_LSK();
                break;
            case MMI_ALERT_CNFM_NO:
                mmi_fmrdo_main_setting_abort();
                break;
            default:
                break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_save_channel_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_save_setting_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_arg;
#if defined(__MMI_FM_RADIO_RECORD__)
    U8 driveletter;
    SRV_FMGR_DRVLIST_HANDLE drv_list;
    S32 temp_storage_index;
#endif 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FM_RADIO_RECORD__) 
    drv_list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
    driveletter = srv_fmgr_drivelist_get_drv_letter(drv_list, selected_record_storage);
    temp_storage_index = srv_fmgr_drivelist_get_index_by_drv_letter(drv_list, g_fmrdo.rec.drive);
    srv_fmgr_drivelist_destroy(drv_list);

    if ((temp_storage_index != selected_record_storage) && FS_GetDevStatus(driveletter, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_NO_MEMORY_CARD,
                                 MMI_EVENT_FAILURE,
                                 GRP_ID_FMRDO,
                                 NULL);
        return;
    }
#endif/*defined(__MMI_FM_RADIO_RECORD__) */
  
    mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);

    confirm_arg.parent_id = GRP_ID_FMRDO;
    confirm_arg.callback = mmi_fmrdo_save_setting_confirm_callback;

    mmi_confirm_display_ext(STR_GLOBAL_SAVE_ASK,
                            MMI_EVENT_QUERY,
                            &confirm_arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_main_setting_abort
 * DESCRIPTION
 *  Abort setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_main_setting_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_close(g_setting_inline_cui_id);
}
#endif/*__MMI_FM_RADIO_RDS__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_settings_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_fmrdo_settings_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#if defined(__MMI_FM_RADIO_RECORD__)
    U8 drv_letter;
    SRV_FMGR_DRVLIST_HANDLE drv_list;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FM_RADIO_RDS__
    cui_inline_close(g_setting_inline_cui_id);
#endif
#if defined(__MMI_FM_RADIO_RECORD__)
#if defined(__USB_IN_NORMAL_MODE__)
    /* Use original setting in USB mode because we hide the setting */
    if (srv_usb_is_in_mass_storage_mode())
    {
        drv_letter = g_fmrdo.rec.drive;
    }
    else
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 
    {
        /* for MAUI_03033923*/
        if (g_setting_has_storage_item)
        {
            drv_list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
            drv_letter = srv_fmgr_drivelist_get_drv_letter(drv_list, selected_record_storage);
            srv_fmgr_drivelist_destroy(drv_list);
            if (FS_GetDevStatus(drv_letter, FS_MOUNT_STATE_ENUM) < FS_NO_ERROR)
            {
                mmi_popup_display_simple_ext(STR_GLOBAL_NO_MEMORY_CARD,
                                 MMI_EVENT_FAILURE,
                                 GRP_ID_FMRDO,
                                 NULL);
                return MMI_FALSE;
            }
        }
        else
        {
            drv_letter = g_fmrdo.rec.drive;
        }
    }
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

#if !(defined(__MMI_VUI_HOMESCREEN_FM_RADIO__) || defined(__MMI_VUI_LAUNCHER_KEY__))
    g_fmrdo.is_background_play = selected_background_play;
#endif 
    g_fmrdo.skin_index = (unsigned char)selected_skin_index;
#if defined(__MMI_FM_RADIO_MONO__)
    g_fmrdo.mono = selected_channel_mono;
#endif 
#if defined(__MMI_FM_RADIO_RECORD__)
    g_fmrdo.rec.quality = selected_record_quality;
    g_fmrdo.rec.drive = drv_letter;
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 
#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
    if (g_fmrdo.loud_speaker_on != selected_speaker_status)
    {
        g_fmrdo.loud_speaker_on = selected_speaker_status;

        /* Turn off then turn on to switch output path */
        if (g_fmrdo.is_power_on)
        {
            if (g_fmrdo.loud_speaker_on)
            {
			#ifdef __MMI_BT_FM_VIA_SCO__
				srv_btsco_disable_sco_connection(SRV_BT_SCO_INT_FMRADIO);
			#endif
			#ifdef	__MMI_FM_VIA_A2DP__
				srv_a2dp_pause_stream();
			#endif
                mdi_fmr_set_output_path(MDI_DEVICE_SPEAKER_BOTH);
            }
            else
            {
            #ifdef __MMI_BT_FM_VIA_SCO__
            	srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_FMRADIO);
			#endif
            #ifdef __MMI_FM_VIA_A2DP__
            if(mmi_a2dp_is_output_to_bt() && !fm_a2dp_connected)
            {
                mmi_fmrdo_change_state_a2dp_connect();
                srv_a2dp_open_source(mmi_a2dp_get_bt_headset(), MMI_TRUE);
//                av_bt_open_ex((srv_bt_cm_bt_addr *)mmi_a2dp_get_bt_headset(),a2dp_info.sample_rate,a2dp_info.is_stereo,
//                        mmi_fmrdo_bt_open_callback,KAL_TRUE);
            }
            #endif
                mdi_fmr_set_output_path(MDI_DEVICE_SPEAKER2);
            }
         }
    }
#endif /* defined(__MMI_FM_RADIO_LOUD_SPEAK__) */ 
#endif/*#ifdef __MMI_FM_RADIO_BIND_EARPHONE__*/
#ifdef __MMI_FM_RADIO_RDS__
    if(g_fmrdo.rds.rds_setting.is_rds_on != (MMI_BOOL)g_setting_rds_status)
    {
        g_fmrdo.rds.rds_setting.is_rds_on = (MMI_BOOL)g_setting_rds_status;
        if(g_setting_rds_status == FMRDO_RDS_SETTING_STATE_OFF)
        {
            if(g_fmrdo.is_power_on && mmi_fmrdo_rds_is_on())
            {
                /*check if frequency switched due to traffic by checking flag bit if yes camm mmi_fmrdo_rds_revert_now() handled by MED*/
                mmi_fmrdo_rds_clear();
                mmi_fmrdo_rds_disable();
            }
        }
        else
        {
            if(g_fmrdo.is_power_on)
            {
                mmi_fmrdo_rds_clear();
                mmi_fmrdo_rds_enable((MMI_BOOL)g_setting_tp_status,(MMI_BOOL)g_setting_af_status);
            }
        }
    }
    else if(g_fmrdo.rds.rds_setting.is_tp_on!=g_setting_tp_status || g_fmrdo.rds.rds_setting.is_af_on != g_setting_af_status)
    {
        if(g_fmrdo.rds.rds_setting.is_rds_on == FMRDO_RDS_SETTING_STATE_ON)
        {
            if(g_fmrdo.is_power_on)
            {
                mmi_fmrdo_rds_set_tp_and_af_setting((MMI_BOOL)g_setting_tp_status, (MMI_BOOL)g_setting_af_status);
            }
        }
    }
    g_fmrdo.rds.rds_setting.is_af_on = (MMI_BOOL)g_setting_af_status;
    g_fmrdo.rds.rds_setting.is_tp_on = (MMI_BOOL)g_setting_tp_status;

#endif/*__MMI_FM_RADIO_RDS__*/

    mmi_fmrdo_write_settings_to_nvram();
#ifdef __MMI_FM_RADIO_MONO__
    mdi_fmr_set_channel((MMI_BOOL)g_fmrdo.mono);
#endif 
#ifdef __MMI_FM_RADIO_RDS__
    mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_FMRDO, NULL);
#endif
        return MMI_TRUE;
}

#endif /* __MMI_FM_PLUTO_SLIM__*/
#ifdef __MMI_FM_RADIO_RDS__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_rec_setting_prepare_inline_data
 * DESCRIPTION
 *  Prepare inline editor data item for record setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_rds_setting_prepare_inline_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if user change select */
    g_selected_rds_status = g_setting_rds_status;
    g_selected_af_status =  g_setting_af_status;
    g_selected_tp_status =  g_setting_tp_status;
    mmi_fmrdo_rds_entry_setting();
}


typedef enum
{
    FMRDO_SETTING_RDS_STATE_SELECT = CUI_INLINE_ITEM_ID_BASE,
    FMRDO_SETTING_RDS_AF_CAPTION,
    FMRDO_SETTING_RDS_AF_SELECT,
    FMRDO_SETTING_RDS_TP_CAPTION,
    FMRDO_SETTING_RDS_TP_SELECT,
    FMRDO_SETTING_RDS_TOTAL
}FMRDO_SETTING_RD;

static const U16 mmi_fmrdo_setting_rds_inline_on_off_select_text[] =
{
    STR_GLOBAL_OFF, 
    STR_GLOBAL_ON
};

static const cui_inline_item_select_struct mmi_fmrdo_setting_rds_inline_on_off_select = 
{
    2, 0, (U16 *)mmi_fmrdo_setting_rds_inline_on_off_select_text
};

static const cui_inline_item_caption_struct mmi_fmrdo_setting_rds_af_caption = 
{
    STR_ID_FMRDO_RDS_AF_SERVICE
};

static const cui_inline_item_caption_struct mmi_fmrdo_setting_rds_tp_caption = 
{
    STR_ID_FMRDO_RDS_TP_SERVICE
};

static const cui_inline_set_item_struct mmi_fmrdo_setting_rds_inline_item[] = 
{
    {FMRDO_SETTING_RDS_STATE_SELECT,    CUI_INLINE_ITEM_TYPE_SELECT,    IMG_GLOBAL_L1,  (void*)&mmi_fmrdo_setting_rds_inline_on_off_select},
    {FMRDO_SETTING_RDS_AF_CAPTION,      CUI_INLINE_ITEM_TYPE_CAPTION,   IMG_GLOBAL_L2,  (void*)&mmi_fmrdo_setting_rds_af_caption},
    {FMRDO_SETTING_RDS_AF_SELECT,       CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_fmrdo_setting_rds_inline_on_off_select},
    {FMRDO_SETTING_RDS_TP_CAPTION,      CUI_INLINE_ITEM_TYPE_CAPTION,   IMG_GLOBAL_L3,  (void*)&mmi_fmrdo_setting_rds_tp_caption},
    {FMRDO_SETTING_RDS_TP_SELECT,       CUI_INLINE_ITEM_TYPE_SELECT,    0,  (void*)&mmi_fmrdo_setting_rds_inline_on_off_select}
};

static const cui_inline_struct mmi_fmrdo_setting_rds_inline_cui = 
{
    5,
    STR_ID_FMRDO_RDS_SETTING,
    0,
    CUI_INLINE_SCREEN_DISABLE_DONE, 
    &mmi_fmrdo_inline_cui_softkey, 
    mmi_fmrdo_setting_rds_inline_item 
};

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_rds_entry_setting_inline_cui_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_fmrdo_rds_entry_setting_inline_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_abort_struct *inline_abort_event;
    cui_event_inline_submit_struct *inline_submit_event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_ABORT:
        {
            inline_abort_event = (cui_event_inline_abort_struct*)evt;

            cui_inline_close(inline_abort_event->sender_id);
            break;
        }
        case EVT_ID_CUI_INLINE_CSK_PRESS:
        case EVT_ID_CUI_INLINE_SUBMIT:
        { 
            inline_submit_event = (cui_event_inline_submit_struct*)evt;

            cui_inline_get_value(inline_submit_event->sender_id, FMRDO_SETTING_RDS_STATE_SELECT, (void *)&g_selected_rds_status);
            cui_inline_get_value(inline_submit_event->sender_id, FMRDO_SETTING_RDS_AF_SELECT, (void *)&g_selected_af_status);
            cui_inline_get_value(inline_submit_event->sender_id, FMRDO_SETTING_RDS_TP_SELECT, (void *)&g_selected_tp_status);

            mmi_fmrdo_rds_setting_done();

            cui_inline_close(inline_submit_event->sender_id);
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_entry_rec_setting
 * DESCRIPTION
 *  Enter record setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_rds_entry_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID inline_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    inline_id = cui_inline_create(GRP_ID_FMRDO, &mmi_fmrdo_setting_rds_inline_cui);
    cui_inline_set_parent_data(inline_id, FMRDO_INLINE_CUI_SETTING_RDS);

    cui_inline_set_title_icon(inline_id, GetRootTitleIcon(MENU_ID_FMRDO_MAIN));

    /* Set item value */
    cui_inline_set_value(inline_id, FMRDO_SETTING_RDS_STATE_SELECT, (void *)g_selected_rds_status);
    cui_inline_set_value(inline_id, FMRDO_SETTING_RDS_AF_SELECT, (void *)g_selected_af_status);
    cui_inline_set_value(inline_id, FMRDO_SETTING_RDS_TP_SELECT, (void *)g_selected_tp_status);

    cui_inline_run(inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmsr_rec_setting_done
 * DESCRIPTION
 *  Done record setting and go back.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_rds_setting_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_selected_rds_status == FMRDO_RDS_SETTING_STATE_OFF && (g_selected_af_status == FMRDO_RDS_SETTING_STATE_ON || g_selected_tp_status == FMRDO_RDS_SETTING_STATE_ON))
    {
         g_selected_rds_status = FMRDO_RDS_SETTING_STATE_OFF;
         g_selected_af_status = FMRDO_RDS_SETTING_STATE_OFF;
         g_selected_tp_status = FMRDO_RDS_SETTING_STATE_OFF;
    }
    g_setting_rds_status = g_selected_rds_status;
    g_setting_af_status =  g_selected_af_status;
    g_setting_tp_status =  g_selected_tp_status;
    //g_rds_settings_changed = MMI_TRUE;

    /* Change first level setting to Done */
    cui_inline_set_screen_attributes(g_setting_inline_cui_id, CUI_INLINE_SET_ATTRIBUTE,  CUI_INLINE_SCREEN_CHANGED);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_rds_clear
 * DESCRIPTION
 *  Done record setting and go back.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_rds_clear(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_ucs2cmp((CHAR *)g_fmrdo.rds.prog_name, (CHAR *)"") != 0)
    {
        g_fmrdo.rds.prog_name[0] = 0;
    }
    if(mmi_ucs2cmp((CHAR *)g_fmrdo.rds.radio_text, (CHAR *)"") != 0)
    {
        g_fmrdo.rds.radio_text[0] = 0;
    }
    g_fmrdo.rds.status_mask &= ~(RT_RECIEVE|PS_RECIEVE|TP_RECIEVE|AF_RECIEVE);
    
    /*update 4 bits of status_mask PS ,RT ,TP,AF*/	
    if (g_fmrdo.in_main_screen)
    {
        mmi_fmrdo_rds_redraw_main_text();
        mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_MAIN);
        mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_TP);
        mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_AF);
        //mmi_fmrdo_redraw_main_channel_name(0);
    }
	memset((void*)&rds_str_idle, 0, sizeof(rds_str_idle));
	#ifdef __MMI_NCENTER_SUPPORT__
		mmi_fmrdo_ncenter_update_channel();
	#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_rds_clear_before_entry_record
 * DESCRIPTION
 *  Clear TP and AF
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_rds_clear_before_entry_record(void)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmrdo.rds.status_mask &= ~(TP_RECIEVE|AF_RECIEVE);
    
    /*update 2 bits of status_mask TP,AF*/	
    if (g_fmrdo.in_main_screen)
    {
        //mmi_fmrdo_rds_redraw_main_text();
        //mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_MAIN);
        mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_TP);
        mmi_fmrdo_rds_redraw_main_ind(FMRDO_RDS_IND_AF);
    }
}

#endif/*__MMI_FM_RADIO_RDS__*/


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
static mmi_ret mmi_fmrdo_channel_option_menu_cui_proc(cui_menu_event_struct *menu_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_empty_channel = (g_fmrdo.channel_list.freq[channel_list_highlighted_item_index] == 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            /* Use number as menu icon */
            cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);

            if(is_empty_channel)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_FMRDO_CHANNEL_OPT_PLAY, MMI_TRUE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_FMRDO_CHANNEL_OPT_DELETE, MMI_TRUE);
            }
            else
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_FMRDO_CHANNEL_OPT_PLAY, MMI_FALSE);
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_FMRDO_CHANNEL_OPT_DELETE, MMI_FALSE);
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_fmrdo_channel_option_LSK(menu_evt->highlighted_menu_id);
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
 *  mmi_fmrdo_entry_channel_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_channel_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Use menu cui to display manin menu */
    menu_gid = cui_menu_create(GRP_ID_FMRDO, 
                               CUI_MENU_SRC_TYPE_RESOURCE,
                               CUI_MENU_TYPE_OPTION,
                               MENU_ID_FMRDO_CHANNEL_OPTION,
                               MMI_FALSE,
                               (void*)FMRDO_MENU_CUI_CHANNEL_LIST_OPTION);
    cui_menu_set_default_title_by_id(menu_gid, STR_GLOBAL_OPTIONS, GetRootTitleIcon(MENU_ID_FMRDO_MAIN));
    cui_menu_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_channel_option_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_channel_option_LSK(mmi_menu_id highlight_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (highlight_item)
    {
        case MENU_ID_FMRDO_CHANNEL_OPT_PLAY:
            if (!g_fmrdo.is_power_on)
            {
            #ifdef __MMI_BACKGROUND_CALL__
                if (srv_ucm_is_background_call())
                {
                    mmi_ucm_app_entry_error_message();
                    return;
                }
            #endif /* __MMI_BACKGROUND_CALL__ */ 
                if (mmi_fmrdo_earphone_check_invalid_and_popup())
                {
                    return;
                }
                mmi_fmrdo_goto_channel(channel_list_highlighted_item_index);
                mmi_fmrdo_power_on_check(MMI_TRUE);
            }
            else
            {
                mmi_fmrdo_goto_channel(channel_list_highlighted_item_index);
            }

            if(mmi_frm_scrn_is_present(GRP_ID_FMRDO, SCR_ID_FMRDO_CHANNEL_LIST, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
            {
                mmi_frm_scrn_close(GRP_ID_FMRDO, SCR_ID_FMRDO_CHANNEL_LIST);
            }
            mmi_frm_scrn_close_active_id();
            break;
        case MENU_ID_FMRDO_CHANNEL_OPT_DELETE:
            mmi_fmrdo_entry_clear_channel_confirm();
            break;
        case MENU_ID_FMRDO_CHANNEL_OPT_EDIT:
            mmi_fmrdo_entry_channel_edit();
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_searching
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_searching(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Show searching screen */
    ShowCategory66Screen(
        STR_ID_FMRDO_PRESET_AUTO_SEARCH,
        GetRootTitleIcon(MENU_ID_FMRDO_MAIN),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) GetString(STR_GLOBAL_SEARCHING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_exit_searching
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_exit_searching(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.state != FMRDO_STATE_SEARCH_ALL)
    {
        mmi_frm_scrn_clear_attribute(GRP_ID_FMRDO, SCR_ID_FMRDO_SEARCHING, MMI_SCRN_ATTRIB_ADD_HISTORY);
    }
}


typedef enum
{
    FMRDO_CHANNEL_EDIT_CHANNEL_CAPTION = CUI_INLINE_ITEM_ID_BASE,
    FMRDO_CHANNEL_EDIT_CHANNEL_EDIT,
    FMRDO_CHANNEL_EDIT_FREQ_CAPTION,
    FMRDO_CHANNEL_EDIT_FREQ_EDIT,
    FMRDO_CHANNEL_EDIT_TOTAL
}FMRDO_CHANNEL_EDIT_ENUM;

static const cui_inline_item_caption_struct mmi_fmrdo_channel_edit_inline_channel_caption = 
{
    STR_ID_FMRDO_CHANNEL_NAME
};

static cui_inline_item_fullscreen_edit_struct mmi_fmrdo_channel_edit_inline_channel_edit =
{
    0,          /* string id */
    0,    /*default text string id*/
    STR_ID_FMRDO_CHANNEL_NAME,              /* title string id */
    0,         /* title icon id */
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL, /* input extended type */
    IMM_INPUT_TYPE_SENTENCE,         /* input type */
    MAX_NAME_INPUT_LEN,        /* string count */
    NULL
};

static const cui_inline_item_caption_struct mmi_fmrdo_channel_edit_inline_freq_caption = 
{
    STR_ID_FMRDO_FREQUENCY
};

static const cui_inline_item_text_edit_struct mmi_fmrdo_channel_edit_inline_freq_edit =
{
    0,  /* string id */
    0,    /*default text string id*/
    MAX_MANUAL_INPUT_LEN,    /* string count */
    IMM_INPUT_TYPE_DECIMAL_NUMERIC, /* input type */
    0,    /* input extended type */
    NULL   /* required input mode */
};

static const cui_inline_set_item_struct mmi_fmrdo_channel_edit_inline_item[] = 
{
    {FMRDO_CHANNEL_EDIT_CHANNEL_CAPTION,  CUI_INLINE_ITEM_TYPE_CAPTION,           IMG_GLOBAL_L1,  (void*)&mmi_fmrdo_channel_edit_inline_channel_caption},
    {FMRDO_CHANNEL_EDIT_CHANNEL_EDIT,     CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT,   0,  (void*)&mmi_fmrdo_channel_edit_inline_channel_edit},
    {FMRDO_CHANNEL_EDIT_FREQ_CAPTION,     CUI_INLINE_ITEM_TYPE_CAPTION,           IMG_GLOBAL_L2,  (void*)&mmi_fmrdo_channel_edit_inline_freq_caption},
    {FMRDO_CHANNEL_EDIT_FREQ_EDIT,        CUI_INLINE_ITEM_TYPE_TEXT_EDIT,         0,  (void*)&mmi_fmrdo_channel_edit_inline_freq_edit}
};

static const cui_inline_struct mmi_fmrdo_channel_edit_inline_cui = 
{
    4,
    STR_GLOBAL_EDIT,
    0,
    0, 
    &mmi_fmrdo_inline_cui_softkey, 
    mmi_fmrdo_channel_edit_inline_item 
};


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_channel_edit_inline_cui_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_fmrdo_entry_channel_edit_inline_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_event_inline_abort_struct *inline_abort_event;
    cui_event_inline_submit_struct *inline_submit_event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_CUI_INLINE_ABORT:
        {
            inline_abort_event = (cui_event_inline_abort_struct*)evt;
            cui_inline_close(inline_abort_event->sender_id);
            break;
        }
        case EVT_ID_CUI_INLINE_SUBMIT:
        { 
            inline_submit_event = (cui_event_inline_submit_struct*)evt;

            cui_inline_get_value(inline_submit_event->sender_id, FMRDO_CHANNEL_EDIT_CHANNEL_EDIT, (void *)name_inline_editor_buffer);
            cui_inline_get_value(inline_submit_event->sender_id, FMRDO_CHANNEL_EDIT_FREQ_EDIT, (void *)freq_inline_editor_buffer);
            if(mmi_fmrdo_channel_edit_LSK())
            {
                cui_inline_close(inline_submit_event->sender_id);
            }
            break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_channel_edit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_channel_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID inline_id;
    U16 freq = g_fmrdo.channel_list.freq[channel_list_highlighted_item_index];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2ncpy(
        (CHAR *) name_inline_editor_buffer,
        (CHAR *) g_fmrdo.channel_list.name[channel_list_highlighted_item_index],
        MAX_NAME_INPUT_LEN - 1);
    if (freq == 0)
    {
        freq_inline_editor_buffer[0] = 0;
    }
    else
    {
        kal_wsprintf(freq_inline_editor_buffer, "%d.%d", freq / 10, freq % 10);
    }

    mmi_fmrdo_channel_edit_inline_channel_edit.title_icon = GetRootTitleIcon(MENU_ID_FMRDO_MAIN);
    inline_id = cui_inline_create(GRP_ID_FMRDO, &mmi_fmrdo_channel_edit_inline_cui);
    cui_inline_set_parent_data(inline_id, FMRDO_INLINE_CUI_CHANNEL_EDIT);

    cui_inline_set_title_icon(inline_id, GetRootTitleIcon(MENU_ID_FMRDO_MAIN));
    /* Set channel name */
    cui_inline_set_value(inline_id, FMRDO_CHANNEL_EDIT_CHANNEL_EDIT, (void *)name_inline_editor_buffer);
    /* Set freq */
    cui_inline_set_value(inline_id, FMRDO_CHANNEL_EDIT_FREQ_EDIT, (void *)freq_inline_editor_buffer);

    cui_inline_run(inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_channel_edit_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_fmrdo_channel_edit_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* calculate frequency number */
    U16 freq = mmi_fmrdo_get_freq_from_str(freq_inline_editor_buffer);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check frequency input */
    if (freq_inline_editor_buffer[0] == 0)
    {
        mmi_popup_display_simple_ext(STR_ID_FMRDO_VALID_FM_BANDWIDTH,
                                 MMI_EVENT_FAILURE,
                                 GRP_ID_FMRDO,
                                 NULL);
        return MMI_FALSE;
    }
    else if (freq == 0xffff)    /* invalid decimal digit */
    {
        mmi_popup_display_simple_ext(STR_ID_FMRDO_VALID_FM_DECIMAL,
                                 MMI_EVENT_FAILURE,
                                 GRP_ID_FMRDO,
                                 NULL);
        return MMI_FALSE;
    }
    else if (freq < MIN_FM_FREQUENCY || freq > MAX_FM_FREQUENCY)        /* warning invalid frequency */
    {
        mmi_popup_display_simple_ext(STR_ID_FMRDO_VALID_FM_BANDWIDTH,
                                 MMI_EVENT_FAILURE,
                                 GRP_ID_FMRDO,
                                 NULL);
        return MMI_FALSE;
    }
    else
    {
        mmi_fmrdo_save_channel_LSK();
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_clear_channel_confirm_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static mmi_ret mmi_fmrdo_entry_clear_channel_confirm_callback(mmi_event_struct *mmi_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct*)mmi_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch(evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_fmrdo_clear_channel_LSK();
                break;
            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;
            default:
                break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_clear_channel_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_clear_channel_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);

    confirm_arg.parent_id = GRP_ID_FMRDO;
    confirm_arg.callback = mmi_fmrdo_entry_clear_channel_confirm_callback;
#ifndef __MMI_MAINLCD_96X64__
    confirm_arg.f_auto_map_empty_softkey = 0; /* Disable CSK for delete */
#else
	confirm_arg.f_auto_map_empty_softkey = MMI_TRUE; /* Enable CSK for delete in BW */
#endif
    mmi_confirm_display_ext(STR_GLOBAL_DELETE_ASK, MMI_EVENT_QUERY, &confirm_arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_clear_channel_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_clear_channel_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_set_channel(channel_list_highlighted_item_index, 0, L"");

    /* write channel list from nvram */
    WriteRecordSlim(NVRAM_EF_FM_RADIO_LID, 1, (void*)&g_fmrdo.channel_list, NVRAM_EF_FM_RADIO_SIZE);
    #ifdef __MMI_NCENTER_SUPPORT__
     	mmi_fmrdo_ncenter_update_channel();
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_save_channel_LSK
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_save_channel_LSK(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 freq = mmi_fmrdo_get_freq_from_str(freq_inline_editor_buffer);
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set channel */
    len = mmi_ucs2strlen((CHAR *)name_inline_editor_buffer);
    if (len != 0)
    {
        mmi_fmrdo_set_channel(channel_list_highlighted_item_index, freq, name_inline_editor_buffer);
    }
    else
    {
        mmi_fmrdo_set_channel(channel_list_highlighted_item_index, freq, (UI_string_type) GetString(STR_ID_FMRDO_NEW_CHANNEL));
    }

    /* write channel list from nvram */
    WriteRecordSlim(NVRAM_EF_FM_RADIO_LID, 1, (void*)&g_fmrdo.channel_list, NVRAM_EF_FM_RADIO_SIZE);
    #ifdef __MMI_NCENTER_SUPPORT__
     	mmi_fmrdo_ncenter_update_channel();
    #endif
}


#if defined(__MMI_FM_RADIO_RECORD__)
#define MMI_FMRADIO_REC


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_mc_rule_check
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_fmrdo_mc_rule_check(UI_string_type path, mmi_ret (*callback)(mmi_event_struct*))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_arg;
    SRV_FMGR_DRVLIST_HANDLE drvlist;
    S32 drv_num;
    S32 drv_type;
    S32 fs_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Follow memory card rule to check storage */
    if (!mmi_fmrdo_util_check_storage_folder(path, &fs_error, MMI_FALSE))
    {
        if(fs_error == FS_DRIVE_NOT_FOUND || fs_error == FS_MEDIA_CHANGED)
        {
            drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
            drv_num = srv_fmgr_drivelist_count(drvlist);
            drv_type = srv_fmgr_drv_get_type(g_fmrdo.rec.drive);
            srv_fmgr_drivelist_destroy(drvlist);


            /* No phone driver, must insert memory card */
            if((drv_num == 1) && (drv_type != SRV_FMGR_DRV_PHONE_TYPE))
            {
                mmi_popup_display_simple_ext(STR_GLOBAL_INSERT_MEMORY_CARD,
                                         MMI_EVENT_FAILURE,
                                         GRP_ID_FMRDO,
                                         NULL);
            }
            /* With phone and card drive, but memory card not inserted */
            else if((drv_num > 1) && (drv_type == SRV_FMGR_DRV_CARD_TYPE))
            {
                mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);
                confirm_arg.parent_id = GRP_ID_FMRDO;
                confirm_arg.callback = callback;

                mmi_confirm_display_ext(STR_GLOBAL_MC_REMOVED_USE_PHONE,
                                        MMI_EVENT_QUERY,
                                        &confirm_arg);
            }
            /* Has multiple drive (ex. OTG), memory card rule not define. So just popup error */
            else
            {
                mmi_fmrdo_fmgr_error_popup(fs_error);
            }

        }
        else
        {
            mmi_fmrdo_fmgr_error_popup(fs_error);
        }

        return MMI_FALSE;
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_record_button
 * DESCRIPTION
 *  Send out the FM radio record request when release record button
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_record_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    if(!mdi_audio_is_playing(MDI_AUDIO_PLAY_BT_MUSIC) && !mdi_audio_is_resource_available(MDI_AUDIO_RECORD_FM_RADIO , NULL))
    {
        mmi_popup_display_simple_ext(STR_ID_FMRDO_RECORD_FAILED,
                         MMI_EVENT_INFO,
                         GRP_ID_FMRDO, 
                         NULL);
        return;
    }    
#endif /* __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__ */

#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif /* __MMI_BACKGROUND_CALL__ */ 

    /* Check if in USB mode before enter setting */
#if defined(__USB_IN_NORMAL_MODE__)
    if (srv_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 
    /* Enter from option menu, go back to main screen and record */
    if (!g_fmrdo.in_main_screen)
    {
        ClearInputEventHandler(MMI_DEVICE_ALL);
        mmi_frm_scrn_close_active_id();
    }
    mmi_fmrdo_search_frequency_stop();
#ifdef __MMI_FTE_SUPPORT__
    if (mmi_fmrdo_earphone_check_invalid_and_popup())
    {
        return;
    }    

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    mmi_fmrdo_start_record_bar_animation();
#else 
    mmi_fmrdo_send_record_req();
#endif 
#else 
    mmi_fmrdo_send_record_req();
#endif 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_rsk_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_rsk_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_redraw_main_RSK_up();
    mmi_fmrdo_release_stop_button();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_stop_button
 * DESCRIPTION
 *  Stop FM radio record when release stop button
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_stop_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Abort by user */
    g_fmrdo.rec.user_abort = MMI_TRUE;
    mmi_fmrdo_stop_record();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_pause_button
 * DESCRIPTION
 *  Pause FM radio record when release pause button
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_pause_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_pause_record();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_resume_button
 * DESCRIPTION
 *  Resume FM radio record when release resuem button
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_resume_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_resume_record();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_send_record_req_no_card_cnf_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static mmi_ret mmi_fmrdo_send_record_req_no_card_cnf_callback(mmi_event_struct *mmi_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct*)mmi_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch(evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                /* Set storage to phone */
                g_fmrdo.rec.drive = SRV_FMGR_PUBLIC_DRV;
				#ifndef __MMI_FM_PLUTO_SLIM__
                mmi_fmrdo_write_settings_to_nvram();
				#endif

                /* Request record again */
                mmi_frm_scrn_close_active_id();
            #ifdef __MMI_FTE_SUPPORT__
            #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
                mmi_fmrdo_start_record_bar_animation();
            #else
                mmi_fmrdo_send_record_req();
            #endif
            #else 
                mmi_fmrdo_send_record_req();
            #endif /*__MMI_FTE_SUPPORT__*/
                break;

            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;
            default:
                break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_send_record_req
 * DESCRIPTION
 *  Turn on the FM radio in advace and send out the record request.
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_send_record_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type path[MAX_FM_PATH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_fmrdo.in_main_screen)
    {
        return;
    }

    if (g_fmrdo.is_power_on == MMI_FALSE)
    {
        if (mmi_fmrdo_earphone_check_invalid_and_popup())
        {
            return;
        }


        /* stop if it's searching */
        mmi_fmrdo_search_frequency_stop();
        mmi_fmrdo_power_on(MMI_TRUE);
        // TODO: added for fte2.0 key only, show grey button
		#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
                        mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_POWER, g_fmrdo.is_button_down, MMI_FALSE, MMI_TRUE);
		#else
			mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_POWER, g_fmrdo.is_button_down, g_fmrdo.is_power_on, MMI_TRUE);
		#endif

    }


    /* Follow memory card rule to check storage */
    mmi_fmrdo_util_get_storage_path(path, g_fmrdo.rec.drive);
    if(!mmi_fmrdo_mc_rule_check(path, mmi_fmrdo_send_record_req_no_card_cnf_callback))
    {
        return;
    }

    /* Get file path */
    if (!mmi_fmrdo_util_get_new_file(g_fmrdo.rec.fullName))
    {
        return;
    }

    g_fmrdo.rec.user_abort = MMI_FALSE;
#ifdef __MMI_FM_RADIO_RDS__
    if(mmi_fmrdo_rds_is_on())
    {
        mmi_fmrdo_rds_set_tp_and_af_setting(MMI_FALSE,MMI_FALSE);
        g_temp_rds_freq_switch_off = MMI_TRUE;
    }
#endif/*__MMI_FM_RADIO_RDS__*/
    mmi_fmrdo_start_record(g_fmrdo.rec.fullName, 0, g_fmrdo.rec.quality);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_main_record_screen
 * DESCRIPTION
 *  Entry record screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_main_record_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_FM_SKIN_SYN_TO_THEME__
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_REC, MMI_FALSE, MMI_TRUE, MMI_TRUE);
#endif 
#endif 
    mmi_fmrdo_change_main_SK_record();

    /* ClearKeyHandler(KEY_ENTER, KEY_EVENT_UP); */
    ClearInputEventHandler(MMI_DEVICE_KEY);

#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    SetKeyUpHandler(mmi_fmrdo_release_pause_button, KEY_LSK);
    SetKeyUpHandler(mmi_fmrdo_release_rsk_stop, KEY_RSK);

    SetKeyDownHandler(mmi_fmrdo_redraw_main_LSK_down, KEY_LSK);
    SetKeyDownHandler(mmi_fmrdo_redraw_main_RSK_down, KEY_RSK);

    SetKeyRepeatHandler(mmi_fmrdo_inc_volume, KEY_VOL_UP);
    SetKeyRepeatHandler(mmi_fmrdo_dec_volume, KEY_VOL_DOWN);

    SetKeyDownHandler(mmi_fmrdo_inc_volume, KEY_POUND);
    SetKeyDownHandler(mmi_fmrdo_dec_volume, KEY_STAR);
    SetKeyRepeatHandler(mmi_fmrdo_inc_volume, KEY_POUND);
    SetKeyRepeatHandler(mmi_fmrdo_dec_volume, KEY_STAR);
#endif

#ifndef __MMI_FTE_SUPPORT__
    SetKeyDownHandler(mmi_fmrdo_redraw_main_LSK_down, KEY_LSK);
    SetKeyDownHandler(mmi_fmrdo_redraw_main_RSK_down, KEY_RSK);

    SetKeyUpHandler(mmi_fmrdo_release_pause_button, KEY_LSK);
    SetKeyUpHandler(mmi_fmrdo_release_rsk_stop, KEY_RSK);
#ifndef __MMI_SLIM_IMG_RES__
    SetKeyUpHandler(mmi_fmrdo_release_pause_button, KEY_CSK);
#endif /* __MMI_SLIM_IMG_RES__ */
#endif 

#ifdef __MMI_SLIM_IMG_RES__
    mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_POWER, MMI_FALSE, g_fmrdo.is_power_on, MMI_TRUE);
    mmi_fmrdo_redraw_main_push_button(FMRDO_BUTTON_STEP_DOWN, MMI_FALSE);
    mmi_fmrdo_redraw_main_push_button(FMRDO_BUTTON_STEP_UP,MMI_FALSE);
#ifndef __MMI_FTE_SUPPORT__
    mmi_fmrdo_redraw_main_push_button(FMRDO_BUTTON_SEARCH_DOWN, MMI_FALSE);
    mmi_fmrdo_redraw_main_push_button(FMRDO_BUTTON_SEARCH_UP,MMI_FALSE);
#endif
#endif /* __MMI_SLIM_IMG_RES__ */   

    /* register volume inc, dec handlers */
    SetKeyDownHandler(mmi_fmrdo_inc_volume, KEY_VOL_UP);
    SetKeyDownHandler(mmi_fmrdo_dec_volume, KEY_VOL_DOWN);
#ifdef __MMI_SLIM_IMG_RES__
    SetKeyDownHandler(mmi_fmrdo_inc_volume, KEY_POUND);
    SetKeyDownHandler(mmi_fmrdo_dec_volume, KEY_STAR);
#endif /* __MMI_SLIM_IMG_RES__ */

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    SetKeyHandler(mmi_idle_display, KEY_RSK, KEY_LONG_PRESS);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_main_pause_screen
 * DESCRIPTION
 *  Entry pause screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_main_pause_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_REC_PAUSE, MMI_FALSE, MMI_TRUE, MMI_TRUE);
    mmi_fmrdo_change_main_SK_pause();
    #else
        mmi_fmrdo_redraw_main_LSK_up();
        mmi_fmrdo_redraw_main_rec_sign();
    #endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */

    /* ClearKeyHandler(KEY_ENTER, KEY_EVENT_UP); */
    ClearInputEventHandler(MMI_DEVICE_KEY);

#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    SetKeyUpHandler(mmi_fmrdo_release_resume_button, KEY_LSK);
    SetKeyUpHandler(mmi_fmrdo_release_rsk_stop, KEY_RSK);

    SetKeyDownHandler(mmi_fmrdo_redraw_main_LSK_down, KEY_LSK);
    SetKeyDownHandler(mmi_fmrdo_redraw_main_RSK_down, KEY_RSK);

    SetKeyRepeatHandler(mmi_fmrdo_inc_volume, KEY_VOL_UP);
    SetKeyRepeatHandler(mmi_fmrdo_dec_volume, KEY_VOL_DOWN);

    SetKeyDownHandler(mmi_fmrdo_inc_volume, KEY_POUND);
    SetKeyDownHandler(mmi_fmrdo_dec_volume, KEY_STAR);
    SetKeyRepeatHandler(mmi_fmrdo_inc_volume, KEY_POUND);
    SetKeyRepeatHandler(mmi_fmrdo_dec_volume, KEY_STAR);
#endif

#ifndef __MMI_FTE_SUPPORT__
    SetKeyDownHandler(mmi_fmrdo_redraw_main_LSK_down, KEY_LSK);
    SetKeyDownHandler(mmi_fmrdo_redraw_main_RSK_down, KEY_RSK);

    SetKeyUpHandler(mmi_fmrdo_release_resume_button, KEY_LSK);
    SetKeyUpHandler(mmi_fmrdo_release_stop_button, KEY_RSK);
#ifndef __MMI_SLIM_IMG_RES__
    SetKeyUpHandler(mmi_fmrdo_release_resume_button, KEY_CSK);
#endif /*__MMI_SLIM_IMG_RES__*/    
#endif 

    /* register volume inc, dec handlers */
    SetKeyDownHandler(mmi_fmrdo_inc_volume, KEY_VOL_UP);
    SetKeyDownHandler(mmi_fmrdo_dec_volume, KEY_VOL_DOWN);
#ifdef __MMI_SLIM_IMG_RES__
    SetKeyDownHandler(mmi_fmrdo_inc_volume, KEY_POUND);
    SetKeyDownHandler(mmi_fmrdo_dec_volume, KEY_STAR);
#endif /* __MMI_SLIM_IMG_RES__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_restore_main_screen
 * DESCRIPTION
 *  Restore to FM playing screen from record or pause screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_restore_main_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_util_stop_duration();

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    mmi_fmrdo_redraw_main_toggle_button(FMRDO_BUTTON_REC, MMI_FALSE, MMI_TRUE, MMI_FALSE);
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */

#ifndef __MMI_FTE_SUPPORT__
    mmi_fmrdo_redraw_main_time_duration(MMI_FALSE);
#endif 

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    mmi_fmrdo_redraw_main_rec_sign();
    mmi_fmrdo_redraw_main_time_duration(MMI_FALSE);
#endif

    mmi_fmrdo_restore_main_SK();

    mmi_fmrdo_main_register_keys();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_record_stopped_hdlr
 * DESCRIPTION
 *  Handler when stop FM record. Need to enter file name if it is not an append file.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_record_stopped_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_util_stop_duration();

    /* not abort by user, exit directly */
    if (!g_fmrdo.rec.user_abort)
    {
    #ifdef __MMI_FM_RADIO_RDS__
	    if(g_temp_rds_freq_switch_off)
	    {
	        if(g_fmrdo.is_power_on && g_fmrdo.rds.rds_setting.is_rds_on)
	        {
	            mmi_fmrdo_rds_set_tp_and_af_setting(g_fmrdo.rds.rds_setting.is_tp_on, g_fmrdo.rds.rds_setting.is_af_on);
	        }
	        g_temp_rds_freq_switch_off = MMI_FALSE;
	    }
	#endif/*__MMI_FM_RADIO_RDS__*/
        return;
    }

	mmi_fmrdo_entry_save();

#ifdef __MMI_FM_RADIO_RDS__
    if(g_temp_rds_freq_switch_off)
    {
        if(g_fmrdo.is_power_on && g_fmrdo.rds.rds_setting.is_rds_on)
        {
            mmi_fmrdo_rds_set_tp_and_af_setting(g_fmrdo.rds.rds_setting.is_tp_on, g_fmrdo.rds.rds_setting.is_af_on);
        }
        g_temp_rds_freq_switch_off = MMI_FALSE;
    }
#endif/*__MMI_FM_RADIO_RDS__*/
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
MMI_BOOL mmi_fmrdo_entry_save(void)
#else
static MMI_BOOL mmi_fmrdo_entry_save(void)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    result = FS_GetAttributes(g_fmrdo.rec.fullName);
	if (result < 0)
    {
        if (result == FS_MEDIA_CHANGED)
        {
            mmi_popup_display_simple_ext(STR_ID_FMRDO_NO_CARD,
                                     MMI_EVENT_FAILURE,
                                     GRP_ID_FMRDO, 
                                     NULL);
        }
        else
        {
            mmi_fmrdo_fmgr_error_popup(result);
			return MMI_FALSE;
        }
    }
    else
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_SAVED,
                                 MMI_EVENT_SUCCESS,
                                 GRP_ID_FMRDO, 
                                 NULL);
    }
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_edit_filename_editor_cui_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_fmrdo_entry_edit_filename_editor_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_filename_editor_result_event_struct *editor_evt = (cui_filename_editor_result_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* User input some data */
    if (editor_evt->result > 0)
    {
        /* The data already put in fmrdo_editor_buff[], no need to get */
        if(mmi_fmrdo_record_save_file())
        {
            cui_filename_editor_close(editor_evt->sender_id);
        }
    }
    /* User does not input data */
    else if (editor_evt->result == 0)
    {
        /* Handler when user Cancel input */
        mmi_fmrdo_entry_edit_abort_query();
        fmrdo_record_menu_cui_id = editor_evt->sender_id;
    }
    else
    {
        mmi_fmrdo_fmgr_error_popup(editor_evt->result);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_edit_filename
 * DESCRIPTION
 *  Entry edit file name screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_edit_filename(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id filename_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filename_gid = cui_filename_editor_create(GRP_ID_FMRDO,
                                              (WCHAR*)fmrdo_editor_buff,
                                              sizeof(fmrdo_editor_buff),
                                              (SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN),
                                              NULL,
                                              NULL);

    cui_filename_editor_set_title(filename_gid, STR_GLOBAL_FILENAME, GetRootTitleIcon(MENU_ID_FMRDO_MAIN));

    cui_filename_editor_run(filename_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_edit_abort_query_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static mmi_ret mmi_fmrdo_entry_edit_abort_query_callback(mmi_event_struct *mmi_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct*)mmi_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch(evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_fmrdo_abort_edit_file();
                break;
            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;
            default:
                break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_edit_abort_query
 * DESCRIPTION
 *  Abort reocrd confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_edit_abort_query(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_YESNO);

    confirm_arg.parent_id = GRP_ID_FMRDO;
    confirm_arg.callback = mmi_fmrdo_entry_edit_abort_query_callback;

    mmi_confirm_display_ext(STR_ID_FMRDO_CANCEL_ASK,
                            MMI_EVENT_QUERY,
                            &confirm_arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_abort_edit_file
 * DESCRIPTION
 *  Abort the record file if not enter file name.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_abort_edit_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = FS_Delete(g_fmrdo.rec.fullName);

    if ((result < 0) && (result != FS_FILE_NOT_FOUND && result != FS_PATH_NOT_FOUND))
    {
        mmi_fmrdo_fmgr_error_popup(result);
    }
   
	cui_filename_editor_close(fmrdo_record_menu_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_record_save_file
 * DESCRIPTION
 *  Save the recorded FM radio file according to the newly entered name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_fmrdo_record_save_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    UI_character_type fullname[SRV_FMGR_PATH_MAX_LEN + MAX_FM_PATH_LEN + 5];
    UI_character_type path[MAX_FM_PATH_LEN];
    WCHAR *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = srv_fmgr_path_skip_leading_space((WCHAR*)fmrdo_editor_buff);
    mmi_fmrdo_util_get_storage_path(path, g_fmrdo.rec.drive);
    kal_wsprintf(fullname, "%w%w", path, ptr);

    mmi_fmrdo_util_append_file_ext(fullname, g_fmrdo.rec.quality);

    result = FS_Rename(g_fmrdo.rec.fullName, fullname);

    if (result < 0)
    {
        if (result == FS_MEDIA_CHANGED)
        {
            mmi_popup_display_simple_ext(STR_ID_FMRDO_NO_CARD,
                                     MMI_EVENT_FAILURE,
                                     GRP_ID_FMRDO, 
                                     NULL);
        }
        else
        {
            mmi_fmrdo_fmgr_error_popup(result);
            return MMI_FALSE;
        }
    }
    else
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_SAVED,
                                 MMI_EVENT_SUCCESS,
                                 GRP_ID_FMRDO, 
                                 NULL);
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_record_list_cnf_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  S32
 *****************************************************************************/
static mmi_ret mmi_fmrdo_entry_record_list_cnf_callback(mmi_event_struct *mmi_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct*)mmi_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch(evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                /* Set storage to phone */
                g_fmrdo.rec.drive = SRV_FMGR_PUBLIC_DRV;
				#ifndef __MMI_FM_PLUTO_SLIM__
                mmi_fmrdo_write_settings_to_nvram();
				#endif
                /* Request record again */
                mmi_frm_scrn_close_active_id();
                mmi_fmrdo_entry_record_list();
                break;
            case MMI_ALERT_CNFM_NO:
                mmi_frm_scrn_close_active_id();
                break;
            default:
                break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_record_list
 * DESCRIPTION
 *  Entry file list in the folder.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_record_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type path[MAX_FM_PATH_LEN];
    FMGR_FILTER filter;
    mmi_id fs_browser_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if in USB mode before enter setting */
#if defined(__USB_IN_NORMAL_MODE__)
    if (srv_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        return;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 

    mmi_fmrdo_util_get_storage_path(path, g_fmrdo.rec.drive);
    if(!mmi_fmrdo_mc_rule_check(path, mmi_fmrdo_entry_record_list_cnf_callback))
    {
        return;
    }

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_WAV);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_AMR);
#if defined(AMRWB_ENCODE) && defined(AMRWB_DECODE)
    FMGR_FILTER_SET(&filter, FMGR_TYPE_AWB);
#endif
#ifdef __VORBIS_DECODE__
    FMGR_FILTER_SET(&filter, FMGR_TYPE_OGG);
#endif
    fs_browser_id = cui_folder_browser_create(GRP_ID_FMRDO,
                                              path,
                                              &filter,
                                              0,
                                              0,
                                              0);

    if(fs_browser_id != GRP_ID_INVALID)
    {
	cui_folder_browser_set_title(fs_browser_id, STR_ID_FMRDO_TITLE, GetRootTitleIcon(MENU_ID_FMRDO_MAIN));
        cui_folder_browser_run(fs_browser_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_record_error_hdlr
 * DESCRIPTION
 *  Handle the error case for FM radio record
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_record_error_hdlr(S32 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;
    mmi_event_notify_enum type_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mdi_util_get_mdi_error_info(cause, &type_id);
    switch (cause)
    {
        case MDI_AUDIO_FAIL:
        case MDI_AUDIO_ERROR:
            str_id = STR_ID_FMRDO_RECORD_FAILED;
            break;
        case MDI_AUDIO_BAD_FORMAT:
            str_id = STR_ID_FMRDO_BAD_FORMAT;
            break;
        case MDI_AUDIO_INVALID_FORMAT:
            str_id = STR_ID_FMRDO_INVALID_FORMAT;
            break;
        case MDI_AUDIO_BUSY:
            str_id = STR_ID_FMRDO_DEVICE_BUSY;
            break;
        case MDI_AUDIO_DISC_FULL:
        case MDI_AUDIO_NO_SPACE:
        case MDI_AUDIO_OPEN_FILE_FAIL:
            str_id = STR_GLOBAL_NOT_ENOUGH_MEMORY;
            break;
        case MDI_AUDIO_NO_DISC:
            str_id = STR_ID_FMRDO_NO_CARD;
            break;
        case MDI_AUDIO_WRITE_PROTECTION:
            str_id = STR_ID_FMRDO_WRITE_PROTECTION_ERROR;
            break;
        case MDI_AUDIO_HFP_SCO_CONNECTED:
            str_id = STR_ID_FMRDO_RECORD_IN_BT_SCO;
            break;
		case MDI_AUDIO_A2DP_CONNECTED:
			str_id = STR_ID_FMRDO_RECORD_IN_BT_SCO;
			break;
        case MDI_AUDIO_SUCCESS:
            str_id = STR_ID_FMRDOREC_SIZE_LIMIT;
            break;
        case MDI_AUDIO_END_OF_FILE:
        case MDI_AUDIO_TERMINATED:
        default:
            mmi_frm_scrn_close_active_id();
            break;
    }

    if (str_id != 0)
    {
        mmi_popup_display_simple_ext(str_id, type_id, GRP_ID_FMRDO, NULL);
    }
#ifdef __MMI_FM_RADIO_RDS__
    if(g_temp_rds_freq_switch_off)
    {
        if(g_fmrdo.is_power_on && g_fmrdo.rds.rds_setting.is_rds_on)
        {
            mmi_fmrdo_rds_set_tp_and_af_setting(g_fmrdo.rds.rds_setting.is_tp_on, g_fmrdo.rds.rds_setting.is_af_on);
        }
        g_temp_rds_freq_switch_off = MMI_FALSE;
    }
#endif/*__MMI_FM_RADIO_RDS__*/
}

#define MMI_FMRADIO_REC_UTIL


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_get_storage_path
 * DESCRIPTION
 *  Get the storage drive and path according to the record setting
 * PARAMETERS
 *  path            [OUT]        Storage path
 *  drv_letter      [IN]         Drive
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_util_get_storage_path(UI_string_type path, U8 drv_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf((kal_wchar*) path, "%c:\\%w", drv_letter, FMGR_DEFAULT_FOLDER_AUDIO);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_check_storage_folder
 * DESCRIPTION
 *  Check if the storage folder exists. if not, create it.
 * PARAMETERS
 *  path        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_fmrdo_util_check_storage_folder(UI_string_type path, S32 *fs_error, MMI_BOOL show_popup)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_handle = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);
    if (file_handle < 0)
    {
        result = FS_CreateDir(path);
        if (result < 0)
        {
            if(show_popup)
            {
                mmi_fmrdo_fmgr_error_popup(result);
            }
            *fs_error = result;
            return MMI_FALSE;
        }
    }
    else
    {
        FS_Close(file_handle);
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_append_file_ext
 * DESCRIPTION
 *  Append the file extension according to the setting.
 * PARAMETERS
 *  filename        [IN]        
 *  quality          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_util_append_file_ext(UI_string_type filename, U8 quality)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_audio_rec_param_struct rec_param;
    MDI_AUDIO_REC_QUALITY_ENUM mdi_quality;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (FM_QUALITY_LOW == quality)
    {
        mdi_quality = MDI_AUDIO_REC_QUALITY_LOW;
    }
    else
    {
        mdi_quality = MDI_AUDIO_REC_QUALITY_HIGH;
    }
    mdi_audio_get_record_param(MDI_AUDIO_REC_MODE_FMR, mdi_quality, &rec_param);
    mmi_ucs2ncat((CHAR *) filename, (CHAR *) rec_param.file_ext, MAX_FM_FILE_NAME_LEN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_remove_file_ext
 * DESCRIPTION
 *  Remove file extenstion for editing file name
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_util_remove_file_ext(UI_string_type filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = filename + mmi_ucs2strlen((CHAR *)filename);

    while (p > filename)
    {
        if (*p == L'.')
        {
            *p = 0;
            break;
        }
        p--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_check_file_exist
 * DESCRIPTION
 *  Check if file already exists.
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_fmrdo_util_check_file_exist(UI_string_type filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fd = FS_Open(filename, FS_READ_ONLY);
    if (fd >= 0)
    {
        FS_Close(fd);
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_increase_file_name
 * DESCRIPTION
 *  Change the file name by increase the number.
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_util_increase_file_name(UI_string_type filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type p;
    U16 file_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = filename + mmi_ucs2strlen((CHAR *)filename);
    while (p > filename)
    {
        if (*p == L'.')
        {
            file_count = (*(p - 2) - '0') * 10 + (*(p - 1) - '0');
            file_count++;
            *(p - 1) = file_count % 10 + '0';
            *(p - 2) = file_count / 10 + '0';
            break;
        }
        p--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_get_new_file
 * DESCRIPTION
 *  Get a new file name to record.
 * PARAMETERS
 *  fullname        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_fmrdo_util_get_new_file(UI_string_type fullname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type filename[MAX_FM_FILE_NAME_LEN];
    UI_character_type path[MAX_FM_PATH_LEN];
    S32 fs_error;
    RTC_CTRL_GET_TIME_T   rtc_time;
    DCL_HANDLE rtc_handler = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_util_get_storage_path(path, g_fmrdo.rec.drive);
    if (!mmi_fmrdo_util_check_storage_folder(path, &fs_error, MMI_TRUE))
    {
        return MMI_FALSE;
    }

    rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE); 
    DclRTC_Control(rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *)& rtc_time);
    DclRTC_Close(rtc_handler);
    kal_wsprintf(
        (kal_wchar*) filename,
        "%02d%02d%02d%02d00",
        rtc_time.u1Mon,
        rtc_time.u1Day,
        rtc_time.u1Hour,
        rtc_time.u1Min);
    
    kal_wsprintf((kal_wchar*) fullname, "%w%w", path, (const kal_wchar*)filename);

    mmi_fmrdo_util_append_file_ext(fullname, g_fmrdo.rec.quality);

    while (mmi_fmrdo_util_check_file_exist(fullname))
    {
        mmi_fmrdo_util_increase_file_name(fullname);
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_get_file_name
 * DESCRIPTION
 *  Get file name for editing.
 * PARAMETERS
 *  fullname        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
UI_string_type mmi_fmrdo_util_get_file_name(UI_string_type fullname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = fullname + mmi_ucs2strlen((CHAR *)fullname);

    while (p > fullname)
    {
        if (*p == L'\\')
        {
            return (p + 1);
        }
        p--;
    }
    return p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_init_duration
 * DESCRIPTION
 *  Init duration time for display.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_util_init_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmrdo.rec.duration = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_start_duration
 * DESCRIPTION
 *  Start to count the fduration time.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_util_start_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&g_fmrdo.rec.last_duration_ticks);

#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
    mmi_fmrdo_redraw_main_rec_sign();
#endif
    mmi_fmrdo_redraw_main_time_duration(MMI_TRUE);
    gui_start_timer(300, mmi_fmrdo_util_update_duration);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_update_duration
 * DESCRIPTION
 *  Update duration time in the record screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_util_update_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 current_time = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&current_time);

    g_fmrdo.rec.duration += current_time - g_fmrdo.rec.last_duration_ticks;
    g_fmrdo.rec.last_duration_ticks = current_time;

#ifdef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
        mmi_fmrdo_redraw_main_rec_sign();
#endif
    mmi_fmrdo_redraw_main_time_duration(MMI_TRUE);
    gui_start_timer(300, mmi_fmrdo_util_update_duration);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_util_stop_duration
 * DESCRIPTION
 *  Stop duration time.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_util_stop_duration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 current_time = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&current_time);

    g_fmrdo.rec.duration += current_time - g_fmrdo.rec.last_duration_ticks;

    gui_cancel_timer(mmi_fmrdo_util_update_duration);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_rec_msdc_plug_out_hdlr
 * DESCRIPTION
 *  Handle MSDC plugged out
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_rec_msdc_plug_out_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: Check if need to close editor cui here
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmgr_fmrdo_notify_hdlr
 * DESCRIPTION
 *  notify hdlr of storage change.
 * PARAMETERS
 *  notify_flag     [IN]        Notify flag
 *  para            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_fmgr_fmrdo_notify_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
    U8 drv;
    srv_fmgr_notification_set_def_storage_event_struct *fmgr_storage
                = (srv_fmgr_notification_set_def_storage_event_struct*)event;
#endif /* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event->evt_id)
    {
#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__

        case EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE:
            
            if(fmgr_storage->state == SRV_FMGR_NOTIFICATION_STATE_QUERY) /* MMI_FMGR_NOTIFY_SET_STORAGE_PRE_CHK */
            {
                /* check if allow set default storage */
                if (g_fmrdo.state == FMRDO_STATE_RECORD)
                {
                    return MMI_RET_ERR;
                }
                else
                {
                    return MMI_RET_OK;
                }
            }
            
            else if(fmgr_storage->state == SRV_FMGR_NOTIFICATION_STATE_AFTER)/*MMI_FMGR_NOTIFY_SET_STORAGE*/
            {
                /*case MMI_FMGR_NOTIFY_SET_STORAGE:*/
                drv = (U8)fmgr_storage->drv_letter;
                /* update setting */
                g_fmrdo.rec.drive = drv;
                WriteValueSlim(NVRAM_FMRDO_RECORD_STORAGE, &g_fmrdo.rec.drive, DS_BYTE);
                break;
            }
    #endif /* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */ 
        
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT: /*MMI_FMGR_NOTIFY_DRV_POST_UNMOUNT*/
            
            /* Exit the editor screen incase card is plugged out on it */
            if((mmi_frm_scrn_get_active_id() == MMI_FMRDO_RECORD_RENAME_ID) && (g_fmrdo.rec.drive == SRV_FMGR_CARD_DRV))
            {
                mmi_frm_close_to_root_screen(GRP_ID_FMRDO);
            }

        #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
            if (mmi_audply_is_single_play_activated() && (g_fmrdo.rec.drive == SRV_FMGR_CARD_DRV))
            {
                mmi_audply_exit_single_play();
            }
        #endif

            break;

        default:
            break;
    }
    return MMI_RET_OK;
}

#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_earphone_notify_hdlr
 * DESCRIPTION
 *  notify hdlr of earphone plugin/plugout.
 * PARAMETERS
 *  notify_flag     [IN]        Notify flag
 *  para            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_fmrdo_earphone_notify_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event->evt_id)
    {
        case EVT_ID_GPIO_EARPHONE_PLUG_IN:
               #if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)
            #ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
		        if(g_fmrdo.in_main_screen || mmi_frm_group_is_present(GRP_ID_FMRDO))
            #else
		        if(g_fmrdo.in_main_screen)
            #endif
				{
						#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
                        if(g_fmrdo.loud_speaker_on)
                        {
                            mdi_audio_set_audio_mode(AUD_MODE_NORMAL);
                        }
                        else
          				#endif
                        {
                            mdi_audio_set_audio_mode(AUD_MODE_HEADSET);
                        }
						mmi_fmrdo_power_on_main_screen(MMI_TRUE);		
				}
				#endif/*defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)*/
               break;

        case EVT_ID_GPIO_EARPHONE_PLUG_OUT:
                #if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)
                    mmi_fmrdo_power_on_check(MMI_FALSE);
				#endif/*defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)*/
                break;

        default:
            break;
    }
    return MMI_RET_OK;
}




/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_LSK_up_hdlr
 * DESCRIPTION
 *  Key up handler for LSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_LSK_up_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifndef __MMI_MAINLCD_96X64__
    if (!g_fmrdo.is_button_down)
    {
        /* sometimes LSK remains highlighted forever */
        mmi_fmrdo_redraw_main_LSK_up();
        return;
    }
    mmi_fmrdo_redraw_main_LSK_up();
    g_fmrdo.is_button_down = MMI_FALSE;
	#endif
    mmi_fmrdo_entry_main_option();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_RSK_up_hdlr
 * DESCRIPTION
 *  Key down handler for LSK
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_RSK_up_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_MAINLCD_96X64__
    if (!g_fmrdo.is_button_down)
    {
		mmi_fmrdo_redraw_main_RSK_up();
        return;
    }
    mmi_fmrdo_redraw_main_RSK_up();
    g_fmrdo.is_button_down = MMI_FALSE;
    mmi_frm_scrn_close_active_id();
#endif
}



#ifdef __FM_RADIO_HW_SEARCH__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_hw_searching_screen
 * DESCRIPTION
 *  Entry hardware searching screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_hw_searching_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_change_main_SK_hw_searching();

    /* ClearKeyHandler(KEY_ENTER, KEY_EVENT_UP); */
    ClearInputEventHandler(MMI_DEVICE_KEY);
    SetKeyDownHandler(mmi_fmrdo_redraw_main_LSK_down, KEY_LSK);
    SetKeyUpHandler(mmi_fmrdo_hw_stop_searching, KEY_LSK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_hw_stop_searching
 * DESCRIPTION
 *  stop hw searching
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_hw_stop_searching(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_fmrdo_redraw_main_LSK_up();
	mmi_fmrdo_search_frequency_stop();
    /* clear LSK hdlr to avoid send abort search msg again */
    ClearKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
    mmi_fmrdo_exit_hw_seaching_screen(g_fmrdo.frequency);
	g_fmrdo.is_button_down = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_exit_hw_seaching_screen
 * DESCRIPTION
 *  restore main screen key hdlr when hardware search done
 * PARAMETERS
 *  stop_freq       [IN]        Selected frequency
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_exit_hw_seaching_screen(U16 stop_freq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifndef __MMI_FM_PLUTO_SLIM__
    gui_cancel_timer(mmi_fmrdo_twinkle_searching_timer);
	#endif
    mmi_fmrdo_redraw_main_frequency(stop_freq, MMI_TRUE);
	g_fmrdo.is_button_down = MMI_FALSE;
    mmi_fmrdo_restore_main_SK();
    mmi_fmrdo_main_register_keys();
    g_fmrdo.normal_repeat_step_count = 0;
}

#ifndef __MMI_FM_PLUTO_SLIM__

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_start_twinkle_searching
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_start_twinkle_searching(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_fmrdo.twinkle_frequency_count = 0;
    mmi_fmrdo_redraw_main_twinkle_searching(MMI_TRUE);
    gui_start_timer(200, mmi_fmrdo_twinkle_searching_timer);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_twinkle_searching_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_twinkle_searching_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.twinkle_frequency_count % 2 == 0)   /* twinkle off */
    {
        mmi_fmrdo_redraw_main_twinkle_searching(MMI_FALSE);
        g_fmrdo.twinkle_frequency_count++;
        gui_start_timer(200, mmi_fmrdo_twinkle_searching_timer);
    }
    else    /* twinkle on */
    {
        mmi_fmrdo_redraw_main_twinkle_searching(MMI_TRUE);
        g_fmrdo.twinkle_frequency_count++;
        gui_start_timer(200, mmi_fmrdo_twinkle_searching_timer);
    }
}
#endif

#endif /* __FM_RADIO_HW_SEARCH__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_main_goto_previous_channel
 * DESCRIPTION
 *  From current frequency switch to the previous user defined channel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_main_goto_previous_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    S16 first_channel = -1;
    S16 last_channel = -1;
    S16 previous_channel;
    S16 channel_index = g_fmrdo.channel_index; /* current channel index */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.state == FMRDO_STATE_SEARCH_ALL || g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)
    {
        return;
    }
    for (i = 0; i < FM_RADIO_CHANNEL_NUM; i++)
        if (g_fmrdo.channel_list.freq[i] != 0)  /* find the first user defined channel */
        {
            first_channel = i;
            break;
        }
    for (i = FM_RADIO_CHANNEL_NUM - 1; i >= 0; i--)
        if (g_fmrdo.channel_list.freq[i] != 0)  /* find the last user defined channel */
        {
            last_channel = i;
            break;
        }
    if ((first_channel == last_channel) && last_channel < 0)    /* the channel list is empty! */
    {
        return;
    }
    if (channel_index == -1)    /* current channle is not an user defined channel */
    {
        if (first_channel >= 0)
        {
            mmi_fmrdo_goto_previous_closest_channel(g_fmrdo.frequency);
        }
        return;
    }
    else    /* the current channel is an user define channel */
    {
        if (first_channel == last_channel)  /* and just only one channel */
        {
            return;
        }
        else
        {
            for (i = channel_index - 1; i >= 0; i--)
                if (g_fmrdo.channel_list.freq[i] != 0)
                {
                    previous_channel = i;
                    mmi_fmrdo_goto_channel(previous_channel);   /* goto previous channel */
                    return;
                }
            for (i = FM_RADIO_CHANNEL_NUM - 1; i > channel_index; i--)
                if (g_fmrdo.channel_list.freq[i] != 0)
                {
                    previous_channel = i;
                    mmi_fmrdo_goto_channel(previous_channel);
                    return;
                }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_main_goto_next_channel
 * DESCRIPTION
 *  From current frequency switch to the next user defined channel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_main_goto_next_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;
    S16 first_channel = -1;
    S16 last_channel = -1;
    S16 next_channel;
    S16 channel_index = g_fmrdo.channel_index; /* current channel index */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.state == FMRDO_STATE_SEARCH_ALL || g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)
    {
        return;
    }

    for (i = 0; i < FM_RADIO_CHANNEL_NUM; i++)
    {
        if (g_fmrdo.channel_list.freq[i] != 0)  /* find the first user defined channel */
        {
            first_channel = i;
            break;
        }
    }
    for (i = FM_RADIO_CHANNEL_NUM - 1; i >= 0; i--)
    {
        if (g_fmrdo.channel_list.freq[i] != 0)  /* find the last user defined channel */
        {
            last_channel = i;
            break;
        }
    }
    if ((first_channel == last_channel) && (last_channel < 0))    /* the channel list is empty! */
    {
        return;
    }
    if (channel_index == -1)    /* current channle is not an user defined channel */
    {
        if (last_channel >= 0)
            mmi_fmrdo_goto_next_closest_channel(g_fmrdo.frequency);
        return;
    }
    else    /* the current channel is an user define channel */
    {
        if (first_channel == last_channel)  /* and just only one channel */
        {
            return;
        }
        else
        {
            for (i = channel_index + 1; i < FM_RADIO_CHANNEL_NUM; i++)
                if (g_fmrdo.channel_list.freq[i] != 0)
                {
                    next_channel = i;
                    mmi_fmrdo_goto_channel(next_channel);   /* goto next channel */
                    return;
                }
            for (i = 0; i < channel_index; i++)
                if (g_fmrdo.channel_list.freq[i] != 0)
                {
                    next_channel = i;
                    mmi_fmrdo_goto_channel(next_channel);
                    return;
                }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_get_channel_count
 * DESCRIPTION
 *  get current number of valid channels in FM Radio
 * PARAMETERS
 *  void
 * RETURNS
 *  is_ready
 *****************************************************************************/
S16 mmi_fmrdo_get_channel_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 channels = 0;
    S16 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < FM_RADIO_CHANNEL_NUM; count++)
    {
        if (g_fmrdo.channel_list.freq[count] != 0)
        {
            channels++;
        }
    }
    return channels;
}


#ifdef __MMI_VUI_HOMESCREEN_FM_RADIO__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_get_cur_channel_idx
 * DESCRIPTION
 *  Retrieve currently selected channel index
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_get_cur_channel_idx(S16 *channel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *channel = g_fmrdo.channel_index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_get_cur_state
 * DESCRIPTION
 *  Retrieve current FM Radio state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_get_cur_state(U8* state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *state = g_fmrdo.state;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_get_cur_channel_name
 * DESCRIPTION
 *  Retrieve selected FM Radio channel name
 * PARAMETERS
 *  channel_name       [IN]        Channel name
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_get_cur_channel_name(PU8* channel_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.channel_index >= 0 && g_fmrdo.channel_index < FM_RADIO_CHANNEL_NUM)
    {
    	*channel_name = (PU8)mmi_fmrdo_get_channel_name_or_freq();
    }
    else if (mmi_fmrdo_is_power_on() || g_fmrdo.channel_index < 0)
    {
        *channel_name = (PU8)mmi_fmrdo_get_channel_name_or_freq();
    }
    else
    {
        *channel_name = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_need_init
 * DESCRIPTION
 *  Check whether FM Radio is initialized
 * PARAMETERS
 *  void
 * RETURNS
 *  is_ready
 *****************************************************************************/
pBOOL mmi_fmrdo_need_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return !g_fmrdo.is_ready;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_plug_in_earphone_msg
 * DESCRIPTION
 *  Display earphone plug in popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_plug_in_earphone_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FM_RADIO_BIND_EARPHONE__)
    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_GENERAL, MMI_EVENT_INFO, (WCHAR *)get_string(STR_ID_FMRDO_PLEASE_PLUG_IN_EARPHONE));
#endif/*    #if defined(__MMI_FM_RADIO_BIND_EARPHONE__)*/
}
#endif /* __MMI_VUI_HOMESCREEN_FM_RADIO__ */ 

/*Add for FTE 2.0 FM widget*/
#ifdef __MMI_VUI_LAUNCHER_KEY__

MMI_BOOL mmi_fmrdo_srv_power_on_by_others(fmrdo_srv_app_enum app_id, MMI_BOOL is_on)
{    
    MMI_BOOL ret =  MMI_FALSE;
    
    if (app_id != APP_FTE_WIDGET)
    {
        return ret;
    }

    if (is_on)
    {
        //hfp?
        //background play?       
    #if defined(__MMI_FM_RADIO_BIND_EARPHONE__)
        if (!srv_earphone_is_plug_in())
        {
            mmi_frm_nmgr_popup(MMI_SCENARIO_ID_GENERAL, MMI_EVENT_INFO, (WCHAR *)get_string(STR_ID_FMRDO_PLEASE_PLUG_IN_EARPHONE));

            return ret;
        }
        else
        {
    #endif
    #ifdef __MMI_BACKGROUND_CALL__
        if (!srv_ucm_is_background_call())
	{	
    #endif
        if(!g_fmrdo.is_power_on)
        {
            if (!g_fmrdo.is_ready)
            {
                mmi_fmrdo_init_nvram();
            }
			//mdi_audio_suspend_background_play();
			mdi_audio_stop_all();
            /* Power on FM and if on main screen update it */
            mmi_fmrdo_power_on_check(MMI_TRUE);
            mdi_audio_set_background_handler(MDI_BACKGROUND_APP_FMR, (mdi_bg_callback) mmi_fmrdo_continued, NULL);
            mdi_audio_clear_other_background_handler(MDI_BACKGROUND_APP_FMR);
            ret = MMI_TRUE;
        }
    #ifdef __MMI_BACKGROUND_CALL__
	}
	else
	{
	    mmi_ucm_entry_error_message();
	}
    #endif
        
    #if defined(__MMI_FM_RADIO_BIND_EARPHONE__)
      }
    #endif
    }
    else
    {
        mdi_audio_clear_background_handler(MDI_BACKGROUND_APP_FMR);
        mmi_fmrdo_power_on_check(MMI_FALSE);
    }

    //@TODO: add log
    return ret;
}


MMI_BOOL mmi_fmrdo_srv_get_power_on_off_state(void)
{
    return (MMI_BOOL)mmi_fmrdo_is_power_on();
}
void mmi_fmrdo_srv_get_cur_frequency(U16 *frequency)
{
    
    
    if (g_fmrdo.is_ready != MMI_TRUE)
    {
        ReadValueSlim(NVRAM_FMRDO_LAST_CHANNEL, &g_fmrdo.frequency, DS_SHORT);

        /* default frequency value */
        if (g_fmrdo.frequency > MAX_FM_FREQUENCY || g_fmrdo.frequency < MIN_FM_FREQUENCY)
        {
            g_fmrdo.frequency = DEFAULT_FREQUENCY;
        }
    }
    
    *frequency = g_fmrdo.frequency;
    //TODO: add log
}
void mmi_fmrdo_srv_set_frequency(U16 frequency)
{
    mmi_fmrdo_set_frequency(frequency);
    //@TODO: add log
}

void mmi_fmrdo_srv_search_next(U16 freq, MMI_BOOL is_forwad)
{
#ifdef __FM_RADIO_HW_SEARCH__
    mmi_fmrdo_hw_search_frequency_start(freq, is_forwad);
#else 
    mmi_fmrdo_search_frequency_start(freq, is_forwad);
#endif
    //@TODO: add log
}
/************************************************
*
**************************************************/
void mmi_fmrdo_srv_stop_search(void)
{
    mmi_fmrdo_search_frequency_stop();
}


void mmi_fmrdo_srv_set_callback(const fmrdo_srv_callback_struct *callback_list)
{
    //if (NULL != callback_list->user_data)
    //{
        g_fmrdo_srv_userdata = callback_list->user_data;
    //}
    //if (NULL != callback_list->preemped_callback)
    //{
        g_fmrdo_srv_preempted_cb = callback_list->preemped_callback;
    //}
    //if (NULL != callback_list->search_callback)
    //{
        g_fmrdo_srv_search_cb = callback_list->search_callback;
    //}
    //@TODO: add log
}

#endif /* __MMI_VUI_LAUNCHER_KEY__ */



/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_init_ch_list_msg
 * DESCRIPTION
 *  Display initialize channel list message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_init_ch_list_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*mmi_popup_display_simple((WCHAR*) get_string(STR_ID_FMRDO_SET_CH_LIST),
                             MMI_EVENT_FAILURE,
                             GRP_ID_FMRDO, 
                             NULL);*/
	mmi_frm_nmgr_popup(MMI_SCENARIO_ID_GENERAL, MMI_EVENT_FAILURE, (WCHAR *)get_string(STR_ID_FMRDO_SET_CH_LIST));
}


#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_memo_up_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_memo_up_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down)
    {
        return;
    }

    g_fmrdo.selected_button = FMRDO_BUTTON_MEMO_UP;
    g_fmrdo.is_button_down = MMI_TRUE;

#ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);

    mmi_fmrdo_search_frequency_stop();
#endif
}


#if defined(__MMI_FM_RADIO_RECORD__)
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_record_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_record_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down)
    {
        return;
    }
#if defined(__MMI_FM_RADIO_BIND_EARPHONE__)
    if (!srv_earphone_is_plug_in())
    {
        return;  
    }    
#endif

    g_fmrdo.selected_button = FMRDO_BUTTON_REC;
    g_fmrdo.is_button_down = MMI_TRUE;

    mmi_fmrdo_redraw_main_toggle_button(
        g_fmrdo.selected_button,
        g_fmrdo.is_button_down,
        MMI_TRUE,
        MMI_TRUE);

}
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_record_available
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_fmrdo_record_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return MMI_FALSE;
    }
#endif /* __MMI_BACKGROUND_CALL__ */ 

    /* Check if in USB mode before enter setting */
#if defined(__USB_IN_NORMAL_MODE__)
    if (srv_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);
        return MMI_FALSE;
    }
#endif /* defined(__USB_IN_NORMAL_MODE__) */ 
    /* Enter from option menu, go back to main screen and record */
    if (!g_fmrdo.in_main_screen)
    {
        ClearInputEventHandler(MMI_DEVICE_ALL);
        mmi_frm_scrn_close_active_id();
    }
    if (mmi_fmrdo_earphone_check_invalid_and_popup())
    {
        return MMI_FALSE;
    }    
    return MMI_TRUE;
}

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_record_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_record_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down)
    {
        return;
    }
    g_fmrdo.selected_button = FMRDO_BUTTON_REC_STOP;
    g_fmrdo.is_button_down = MMI_TRUE;

    mmi_fmrdo_redraw_bar_toggle_button(
        g_fmrdo.selected_button, 
        g_fmrdo.is_button_down,
        MMI_TRUE,
        MMI_TRUE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_record_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_record_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_REC_STOP))
    {
        g_fmrdo.is_button_down = MMI_FALSE;
        mmi_fmrdo_redraw_bar_toggle_button(
            g_fmrdo.selected_button,
            g_fmrdo.is_button_down,
            MMI_TRUE,
            MMI_TRUE);
        g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
        mmi_fmrdo_release_stop_button();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_record_pause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_record_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down)
    {
        return;
    }
    g_fmrdo.selected_button = FMRDO_BUTTON_REC_PAUSE;
    g_fmrdo.is_button_down = MMI_TRUE;

    mmi_fmrdo_redraw_bar_toggle_button(
        g_fmrdo.selected_button, 
        g_fmrdo.is_button_down,
        (g_fmrdo.state == FMRDO_STATE_RECORD),
        MMI_TRUE);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_record_pause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_record_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_REC_PAUSE))
    {
        g_fmrdo.is_button_down = MMI_FALSE;
        mmi_fmrdo_redraw_bar_toggle_button(
            g_fmrdo.selected_button,
            g_fmrdo.is_button_down,
            (g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE),
            MMI_TRUE);
        g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
        if (g_fmrdo.state == FMRDO_STATE_RECORD)
        {
            mmi_fmrdo_pause_record();
        }
        else if (g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
        {
            mmi_fmrdo_resume_record();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_record(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type path[MAX_FM_PATH_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_REC))
    {
        g_fmrdo.is_button_down = MMI_FALSE;
        mmi_fmrdo_redraw_main_toggle_button(
            g_fmrdo.selected_button,
            g_fmrdo.is_button_down,
            MMI_TRUE,
            MMI_TRUE);
        g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
        mmi_fmrdo_search_frequency_stop();
        if (!mmi_fmrdo_record_available())
        {
            return;
        }
        /* Get the current storage path */
        mmi_fmrdo_util_get_storage_path(path, g_fmrdo.rec.drive);
        
        /* Check for memory card rules */
        if(!mmi_fmrdo_mc_rule_check(path, mmi_fmrdo_send_record_req_no_card_cnf_callback))
        {
            return;
        }
        mmi_fmrdo_start_record_bar_animation();
    }
}
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */

#endif 


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_memo_down_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_memo_down_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down)
    {
        return;
    }
    g_fmrdo.selected_button = FMRDO_BUTTON_MEMO_DOWN;
    g_fmrdo.is_button_down = MMI_TRUE;

#ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
    mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);

    mmi_fmrdo_search_frequency_stop();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_memo_up_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_memo_up_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_MEMO_UP)
    {
        if (!mmi_fmrdo_get_channel_count())
        {
            mmi_fmrdo_init_ch_list_msg();
			g_fmrdo.is_button_down = MMI_FALSE;
			g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
            return;
        }

        g_fmrdo.is_button_down = MMI_FALSE;

        mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
        mmi_fmrdo_main_goto_next_channel();

        g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_memo_down_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_memo_down_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_MEMO_DOWN)
    {
        if (!mmi_fmrdo_get_channel_count())
        {
            mmi_fmrdo_init_ch_list_msg();
			g_fmrdo.is_button_down = MMI_FALSE;
			g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
            return;
        }

        g_fmrdo.is_button_down = MMI_FALSE;

        mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
        mmi_fmrdo_main_goto_previous_channel();

        g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
    }
}

#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_toggle_mute
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_toggle_mute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_VOLUME)
    {
        g_fmrdo.is_button_down = MMI_FALSE;
        g_fmrdo.mute = !g_fmrdo.mute;
        WriteValueSlim(NVRAM_FMRDO_MUTE, &g_fmrdo.mute, DS_BYTE);
        if (g_fmrdo.mute)
        {
            g_fmrdo.prev_volume = g_fmrdo.volume;
            //mdi_fmr_mute(1);
            mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
        }
        else
        {
            //mdi_fmr_mute(0);
            mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_FALSE);
            mmi_fmrdo_set_volume(g_fmrdo.prev_volume);
        }
        mmi_fmrdo_redraw_main_volumebar(g_fmrdo.volume, MMI_TRUE);
        g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_toggle_mute
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_toggle_mute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_fmrdo.is_button_down)
    {
        return;
    }
    g_fmrdo.selected_button = FMRDO_BUTTON_VOLUME;
    g_fmrdo.is_button_down = MMI_TRUE;
    mmi_fmrdo_redraw_bar_toggle_button(
        g_fmrdo.selected_button,
        g_fmrdo.is_button_down,
        !g_fmrdo.mute,
        MMI_TRUE);
}
#endif /* MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT */

#endif /* __MMI_FTE_SUPPORT__ */

#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_scrlocker_event_notify_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_fmrdo_scrlocker_event_notify_handler(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event->evt_id == EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING)
    {
        if (g_fmrdo.state == FMRDO_STATE_RECORD || g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE )
        {
            return MMI_RET_ERR;
        }
    #if defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
        if (g_fmrdo.state == FMRDO_STATE_SEARCH_ALL || g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)
        {
            return MMI_RET_ERR;
        }
    #endif 
    }
    return MMI_RET_OK;
}
#endif /* #ifdef __MMI_SCREEN_LOCK_ANY_TIME__ */

#ifdef __TC01__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef __FM_RADIO_HW_SEARCH__
/* under construction !*/
            #else
/* under construction !*/
            #endif /* FM_RADIO_HW_SEARCH */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef __FM_RADIO_HW_SEARCH__
/* under construction !*/
            #else
/* under construction !*/
            #endif/*FM_RADIO_HW_SEARCH*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif/*__TC01__*/

#ifdef __MMI_FM_VIA_A2DP__

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_entry_a2dp_connecting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_entry_a2dp_connecting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Show searching screen */
	kal_prompt_trace(MOD_MMI_MEDIA_APP, "[mtk33271]mmi_fmrdo_entry_a2dp_connecting");
    ShowCategory66Screen(
        STR_GLOBAL_CONNECTING,
        GetRootTitleIcon(MENU_ID_FMRDO_MAIN),
        0,
        0,
        0,
        0,
        (U8*) GetString(STR_GLOBAL_CONNECTING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_a2dp_connect_stop_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_a2dp_connect_stop_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gui_cancel_timer(mmi_fmrdo_a2dp_connect_start_animation);
	kal_prompt_trace(MOD_MMI_MEDIA_APP, "a2dp_connect_stop_animation");
	if(mmi_frm_scrn_is_present(GRP_ID_FMRDO, SCR_ID_FMRDO_A2DP_CONNECTING, MMI_FRM_NODE_ALL_FLAG))
	{
		mmi_frm_scrn_close(GRP_ID_FMRDO, SCR_ID_FMRDO_A2DP_CONNECTING);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_a2dp_connecting_scrn_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_fmrdo_a2dp_connecting_scrn_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_prompt_trace(MOD_MMI_MEDIA_APP, "[mtk33271]mmi_fmrdo_entry_a2dp_connecting,case = %d",param->evt_id);

    switch (param->evt_id)
    {
    case EVT_ID_SCRN_ACTIVE:
        mmi_fmrdo_entry_a2dp_connecting();
        break;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    default:
        break;
      }
    return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*   mmi_fmrdo_a2dp_connect_start_animation
* DESCRIPTION
*   start osd animation
* PARAMETERS
*   void        
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_a2dp_connect_start_animation(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      						   */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_BT_START_OSD_ANI_IN);
	if(mmi_a2dp_is_output_to_bt() && !fm_a2dp_connected && (g_fmrdo.in_main_screen == MMI_TRUE))
	{
		mmi_frm_scrn_create(GRP_ID_FMRDO, SCR_ID_FMRDO_A2DP_CONNECTING, mmi_fmrdo_a2dp_connecting_scrn_proc, NULL);
	}
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_BT_START_OSD_ANI_OUT);
}

/*****************************************************************************
* FUNCTION
*   mmi_fmrdo_change_state_a2dp_connect
* DESCRIPTION
*   change state to BT Connecting
* PARAMETERS
*   void        
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_change_state_a2dp_connect(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      						   */
    /*----------------------------------------------------------------*/
	if(mmi_a2dp_is_output_to_bt() && !fm_a2dp_connected)
	{
		g_fmrdo.state = FMRDO_STATE_BT_CONNECTING;
	}
	if(!mmi_is_redrawing_bk_screens())
	{
		/* 
		MMI_FRM_INIT_EVENT(&evt,EVT_ID_FMRDO_A2DP_CONNECT);
		MMI_FRM_POST_EVENT(&evt,mmi_fmrdo_broadcast_event_callback_hdlr,NULL);
		*/
		gui_start_timer(200,mmi_fmrdo_a2dp_connect_start_animation);
	} 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_broadcast_event_callback_hdlr
 * DESCRIPTION
 *  this is callback handler for framework event braodcast
 * PARAMETERS
 *  mmi_event_struct*  [IN] event info
 * RETURNS
 * mmi_ret
 *****************************************************************************/
mmi_ret mmi_fmrdo_broadcast_event_callback_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(event->evt_id)
    {
        case EVT_ID_FMRDO_A2DP_CONNECT:
        {
            mmi_fmrdo_a2dp_connect_start_animation();
            return MMI_RET_OK;
        }
		default:
        {
            return MMI_RET_OK;
        }
    }
}

#endif /*__MMI_FM_VIA_A2DP__*/

#ifdef __MMI_AVRCP_SUPPORT__

#ifndef __MMI_FTE_SUPPORT__
 
/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_memo_up_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_avrcp_memo_up_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_fmrdo_search_frequency_stop();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_memo_down_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_press_avrcp_memo_down_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_fmrdo_search_frequency_stop();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_memo_up_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_avrcp_memo_up_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        if (!mmi_fmrdo_get_channel_count())
        {
            mmi_fmrdo_init_ch_list_msg();
            return;
        }
        mmi_fmrdo_main_goto_next_channel();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_release_memo_down_button
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_release_avrcp_memo_down_button(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_fmrdo_get_channel_count())
    {
        mmi_fmrdo_init_ch_list_msg();
        return;
    }
    mmi_fmrdo_main_goto_previous_channel();
}

#endif /*__MMI_FTE_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_avrcp_set_cmd_hdlr
 * DESCRIPTION
 *  to set avrcp handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_avrcp_set_cmd_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
	
		mmi_bt_avrcp_set_cmd_hdlr(mmi_fmrdo_bt_avrcp_cmd_hdlr);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_avrcp_clear_cmd_hdlr
 * DESCRIPTION
 *  to clear avrcp handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_avrcp_clear_cmd_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	if(!mmi_fmrdo_is_power_on() && !g_fmrdo.in_main_screen)
	{
		mmi_bt_avrcp_clear_cmd_hdlr(mmi_fmrdo_bt_avrcp_cmd_hdlr);
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_press_button_canceled
 * DESCRIPTION
 *  to cancel key down action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_fmrdo_press_button_canceled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_FMRDO_AVRCP_CANCELED,g_fmrdo.selected_button,g_fmrdo.is_button_down);

    if(g_fmrdo.selected_button == FMRDO_BUTTON_NONE || g_fmrdo.is_button_down == MMI_FALSE)
    {
        return;
    }
	
	g_fmrdo.is_button_down = MMI_FALSE;
	if(g_fmrdo.in_main_screen)
	{
		switch(g_fmrdo.selected_button)
		{
		#ifdef __MMI_FTE_SUPPORT__
	   		case FMRDO_BUTTON_MEMO_UP:
			case FMRDO_BUTTON_MEMO_DOWN:
			{
				mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
				break;
			}
		#endif /*__MMI_FTE_SUPPORT__*/
        #ifndef __MMI_MAINLCD_96X64__
			case FMRDO_BUTTON_POWER:
			{
				mmi_fmrdo_redraw_main_toggle_button(g_fmrdo.selected_button, g_fmrdo.is_button_down ,g_fmrdo.is_power_on ,MMI_TRUE);
				break;
			}
        #endif 
			default:
				break;
		}
	}
	g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_bt_avrcp_cmd_hdlr
 * DESCRIPTION
 *  callback function to handle avrcp commands from BT device
 * PARAMETERS
 *  command         [IN]        
 *  key_press       [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 mmi_fmrdo_bt_avrcp_cmd_hdlr(U8 command, mmi_avrcp_key_events key_events)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = MMI_AVRCP_CR_ACCEPT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_FMRDO_BT_AVRCP_CMD,g_fmrdo.state,command,key_events);
	if (g_fmrdo.state == FMRDO_STATE_RECORD || g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
	{
		result = MMI_AVRCP_CR_REJECT;
        goto avrcp_finish;
	}
	if (key_events == MMI_AVRCP_KEY_CANCELED)
    {
        switch (command)
        {
            case MMI_AVRCP_POP_PLAY:
            case MMI_AVRCP_POP_STOP:
            case MMI_AVRCP_POP_PAUSE:
			case MMI_AVRCP_POP_POWER:
            case MMI_AVRCP_POP_FORWARD:
            case MMI_AVRCP_POP_BACKWARD:
			case MMI_AVRCP_POP_CHANNEL_UP:
			case MMI_AVRCP_POP_CHANNEL_DOWN:
			
                mmi_fmrdo_press_button_canceled();
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
		case MMI_AVRCP_POP_PAUSE:
        {
            if (key_events == MMI_AVRCP_KEY_UP)
            {
                mmi_fmrdo_release_power_button();
            }
            else if(key_events == MMI_AVRCP_KEY_DOWN)
            {   
               	mmi_fmrdo_press_power_button(); 
            }
            break;
        }

        case MMI_AVRCP_POP_STOP:
        {
            if (key_events == MMI_AVRCP_KEY_UP)
            {  
				mmi_fmrdo_release_power_button();
            }
            else if(key_events == MMI_AVRCP_KEY_DOWN)
            {
				mmi_fmrdo_press_power_button();
            }
            break;
        }

        case MMI_AVRCP_POP_FORWARD:
		{
            if (key_events == MMI_AVRCP_KEY_UP)
            {
            #ifdef __MMI_FTE_SUPPORT__
                mmi_fmrdo_release_memo_up_button();
			#else
				mmi_fmrdo_release_avrcp_memo_up_button();
			#endif
            }
            else if (key_events == MMI_AVRCP_KEY_DOWN)
            {
            #ifdef __MMI_FTE_SUPPORT__
                mmi_fmrdo_press_memo_up_button();
			#else
				mmi_fmrdo_press_avrcp_memo_up_button();
			#endif
            }           
            else
            {
                result = MMI_AVRCP_CR_REJECT;
            }
            break;
        }
        case MMI_AVRCP_POP_BACKWARD:
		{
            if (key_events == MMI_AVRCP_KEY_UP)
            {
			#ifdef __MMI_FTE_SUPPORT__
                mmi_fmrdo_release_memo_down_button();
			#else
				mmi_fmrdo_release_avrcp_memo_down_button();
			#endif
            }
            else if(key_events == MMI_AVRCP_KEY_DOWN)
            {
            #ifdef __MMI_FTE_SUPPORT__
                mmi_fmrdo_press_memo_down_button();
			#else
				mmi_fmrdo_press_avrcp_memo_down_button();
			#endif
            }
            else
            {
                result = MMI_AVRCP_CR_REJECT;
            }
            break;
        }

        default:
            result = MMI_AVRCP_CR_NOT_IMPLEMENT;
            break;
    }


avrcp_finish:
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL, MMI_TRC_FMRDO_AVRCP_RETURN,result);
    return result;

    
}
#endif /* __MMI_AVRCP_SUPPORT__ */ 

#endif /* __MMI_FM_RADIO__ */ 

