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
 *   init.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the HW initialization.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include "kal_release.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include "kal_trace.h"
#include "reg_base.h"
#include "config_hw.h"
#include "emi_hw.h"
#include "pll.h"
#include "init.h"
#include "intrCtrl.h"
#include "isrentry.h"
#include "custom_config.h"
#include "stack_buff_pool.h"
#include "fat_fs.h"
#include "drv_comm.h"
#include "bmt.h"
#include "dcl.h"
#include "wdt_hw.h"
#include "wdt_sw.h"
#include "drvpdn.h"
#include <stdio.h>
#include <string.h>
#include <rt_misc.h>   /* for __rt_lib_init() */
#include <stdlib.h>
#include "br_header_block.h"
#include "cache_sw.h"
#include "page.h"
#include "l1_interface.h"
#include "bl_features.h"
#include "bl_common.h"
#include "kbd_table.h"   
#include "system_trc.h"
#include "init_trc_api.h"
#include "ex_public.h"
#include "br_time_stamp.h"
#include "maui_time_stamp_util.h"
#include "dcmgr.h"
#include "cache_sw_int.h"


#ifdef __MULTI_BOOT__
#include "syscomp_config.h"
#include "multiboot_config.h"
#endif   /* __MULTI_BOOT__ */

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
#include "cp15.h"
#endif   /* __ARM9_MMU__ || __ARM11_MMU__ */

#if defined(__SMART_PHONE_MODEM__)
#include "ccci.h"
#endif /* __SMART_PHONE_MODEM__ */

#if defined(__DSP_FCORE4__)
#include "mdci.h"
#include "SST_dmdsp_ex.h"
#include "dmdsp_init.h"
#endif /* __DSP_FCORE4__ */
#if defined(__FOTA_DM__)
#include "fue_err.h"
#include "custom_fota.h"
#include "custom_img_config.h"
#include "fue.h"
#include "SSF_fue_support.h"
#endif /* __FOTA_DM__ */


#if !defined(__UBL__) && !defined(__FUE__)
#ifdef __CENTRALIZED_SLEEP_MANAGER__
#include "ostd_public.h"
extern void USC_Start(void);
extern void RM_Init(void);
#endif /* __CENTRALIZED_SLEEP_MANAGER__ */
#endif

#if (defined(MT6236) || defined(MT6236B) || defined(MT6256) || defined(MT6276) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268T) || defined(MT6268H) || defined(MT6255))
#if !(defined(__OLD_PDN_ARCH__) && defined(__OLD_PDN_DEFINE__))
#include "mm_power_ctrl.h"
#endif
#endif

/*******************************************************************************
 * Define pragma
 *******************************************************************************/

#ifdef __ADS__
#if (!defined(MT6208) && !defined(MT6205B))
#pragma import __use_realtime_division
#endif   /* !MT6208 && MT6205B */
#else   /* __ADS__ */
#pragma import __use_realtime_division
#endif   /* __ADS__ */



#if defined(KAL_ON_NUCLEUS) && defined(NU_DEBUG)
#define RTOS_DEBUG
#endif    /* KAL_ON_NUCLEUS && NU_DEBUG */

#if defined(KAL_ON_THREADX) && !defined(TX_DISABLE_ERROR_CHECKING)
#define RTOS_DEBUG
#endif    /* KAL_ON_THREADX && !TX_DISABLE_ERROR_CHECKING */

#if defined(KAL_ON_OSCAR)
#define RTOS_DEBUG
#endif  /* KAL_ON_OSCAR */





/*******************************************************************************
 * Define global data
 *******************************************************************************/

//static kal_uint32 init_ev_timestamp = 0;
static kal_uint16 _boot_mode = 0 /* NORMAL Mode */;
static kal_bool _IsBootForUSBAT = KAL_FALSE;
kal_uint32 init_duration;
DCL_HANDLE init_dcl_handle;
static kal_uint32 g_l_sw_misc_l = 0;    

#if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))

#else /* !(__BL_ENABLE || _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__ || __EMMC_BOOTING__) */

/* put bootloader shared information in INTSRAM_DATA_PREINIT if there is no SYSRAM */
/* TODO: define a symbol representing SYSRAM exsistance */
#if defined(MT6251) || defined(MT6252) || defined(MT6252H) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#if !((defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)) && defined(_NAND_FLASH_BOOTING_))
#pragma arm section rodata="PREINIT_INTSRAM_RODATA",rwdata="PREINIT_INTSRAM_RW", zidata="PREINIT_INTSRAM_ZI"
#else   /* !((defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)) && defined(_NAND_FLASH_BOOTING_)) */
#pragma arm section rodata="PRIMARY_RODATA",rwdata="PRIMARY_RW", zidata="SECONDARY_EXTSRAM_ZI"
#endif  /* !((defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)) && defined(_NAND_FLASH_BOOTING_)) */
#endif
BL_Info_Wrapper_st g_pass_info;
#if defined(MT6251) || defined(MT6252) || defined(MT6252H) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#pragma arm section rodata,rwdata, zidata
#endif

#endif /* !(__BL_ENABLE || _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__ || __EMMC_BOOTING__) */


#ifdef __MTK_TARGET__
#pragma arm section zidata = "EMIINITZI"
#endif /* __MTK_TARGET__ */
ECO_VERSION eco_version; /* only used in PLL setup */
#ifdef __MTK_TARGET__
#pragma arm section zidata
#endif /* __MTK_TARGET__ */

#if defined(MT6238) || defined(MT6239)
#ifdef __MTK_TARGET__
#pragma arm section zidata = "INTSRAM_ZI"
#endif /* __MTK_TARGET__ */
ECO_VERSION mt6238_version;     /*     ENG_E1 or ENG_E2. */
#ifdef __MTK_TARGET__
#pragma arm section zidata
#endif /* __MTK_TARGET__ */
#endif    // MT6238

#if defined(MT6235) || defined(MT6235B)
#pragma arm section rwdata="INTSRAM_RW", zidata="INTSRAM_ZI"
ECO_VERSION     mt6235_version;
#pragma arm section rwdata, zidata
#endif /* MT6235 MT6235B */

#if defined(MT6268T) || defined(MT6268H)
static kal_uint32 fpga1_vcode, fpga2_vcode;
#endif   /* MT6268T || MT6268H */


/* [BB porting] make sure if BL will enable, if not, check the address is correct
 * Need to use a segment of internal RAM to generate randum number seed.
 * We pick up address 0x40002000 since it won't be modified by other
 * program such as bootloader.
 */
#if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__)) 
#if defined(MT6238) || defined(MT6235) || defined(MT6239) || defined(MT6235B) || defined(MT6236)  || defined(MT6236B)
static const kal_uint32 RAND_GEN_START_ADDR = 0x4000A000;
#elif defined(MT6268A) || defined(MT6268)
static const kal_uint32 RAND_GEN_START_ADDR = 0x9200A000;
#elif defined(MT6270A)
static const kal_uint32 RAND_GEN_START_ADDR = 0x9000A000;
#elif defined(MT6516) && defined(__APPLICATION_PROCESSOR__)
static const kal_uint32 RAND_GEN_START_ADDR = 0x4000A000;
#elif defined(MT6256)
static const kal_uint32 RAND_GEN_START_ADDR = 0x9100A000;
#elif defined(MT6276) || defined(MT6573)
static const kal_uint32 RAND_GEN_START_ADDR = 0xC800A000;
#elif defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
static const kal_uint32 RAND_GEN_START_ADDR = 0x70009000;
#else
static const kal_uint32 RAND_GEN_START_ADDR = 0x40002000;
#endif
#endif /* !(__BL_ENABLE__ || _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__ || __EMMC_BOOTING__) */

/* g_bl_maui_paired_ver is defined for USB DL 2.0 and will be used by MAUI build process only */
#if defined(MT6270A)
#pragma arm section rodata = "LEADING_PART"
#endif /* 6270A */
const kal_uint32 g_bl_maui_paired_ver = BL_MAUI_PAIRED_VER;
#if defined(MT6270A)
#pragma arm section rodata
#endif /* 6270A */


/*******************************************************************************
 * Declare import data
 *******************************************************************************/
extern kal_uint32 WATCHDOG_BASE;
extern kal_uint32 WATCHDOG_RESTART_CMD;
extern boot_mode_type system_boot_mode;
extern kal_uint32 SYS_Stack_Pool[];

#if defined(__DSP_BOOT_SEC__)
extern kal_bool sync_status;
#endif  /* __DSP_BOOT_SEC__ */

extern kal_uint32 rand_num_seed;    /* generate 1st phase random seed */


/*******************************************************************************
 * Declare function prototype 
 *******************************************************************************/
static void systemInitialization(void);
static void HWDInitialization(void);
static void systemInitializeResource(void);
void SST_InvokEngine(kal_int32, kal_int32);
static void INT_GetBootConfig(void);


/*******************************************************************************
 * Declare import function prototype 
 *******************************************************************************/
#ifdef __SV5_ENABLED__
extern kal_uint32 DummyReference(void);
#endif

#if defined(DEBUG_SWLA)
extern kal_uint32 SLA_Enable(void);
#endif
extern kal_uint32 SLA_Init(void);

#if defined(__ZIMAGE_SUPPORT__)
extern int ZImageDecompress(void);
#endif

extern void DCMGR_init_phase2(void);

#if defined(__TINY_SYS__)
extern void CSD_AP_Stack_error(void);
#endif

#if defined(__DCM_WITH_COMPRESSION__) || defined(__DYNAMIC_CODE_MANAGER__)
extern void DCMGR_Init(void);
#endif

extern int mainp(void);
extern void Drv_Init_Phase1(void);
extern void Drv_Init_Phase2(void);
extern void kal_initialize_mem(void);
extern void kal_profile_init(void);
extern void fatal_error_handler(kal_int32, kal_int32);
extern void NFI_Reset(void);
extern kal_char *release_dsp_fw(void);
extern kal_char *release_dsp_ptch(void);
extern kal_char *release_verno(void);
extern kal_char *release_branch(void);
extern kal_char *release_hw_ver(void);

#ifdef __SECURE_DATA_STORAGE__
extern kal_int32 SDS_Init(void);
#endif

#if defined(__BOOT_CERT__)
extern kal_uint32 srd_dl_ctrl_check(void);
extern kal_uint32 srd_dl_ctrl_pre_check(void);
#endif

#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)
extern void  MMICheckDiskDisplay(void);
#endif

#ifdef IDMA_DOWNLOAD
extern void idma_load(void);
#endif /* IDMA_DOWNLOAD */

#ifdef MTK_SLEEP_ENABLE
extern void L1SM_Init( void );
#endif

#ifndef L1_NOT_PRESENT
extern void L1D_SetInitMode( kal_int16 mode );
#ifdef __HW_DIVIDER__
extern void HW_Divider_Initialization(void);
#endif  /* __HW_DIVIDER__ */
#endif /* !L1_NOT_PRESENT */

#if !defined(__MAUI_BASIC__)
extern void Initialize_FDD_tables(void);
extern int Check_NORFlash_Formatted(void);
#endif

#ifdef __USB_ENABLE__
extern void isrCTIRQ1_USBPowerOn(void);
#endif /*__USB_ENABLE__*/

#if ( defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__) && !defined(__L1_STANDALONE__)  && !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI))
extern void InitializeResourceVariables(void);
#endif /* __MTK_TARGET__ */

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
extern kal_bool NFB_SecondaryImageLoaded;
extern void NFB_LoadingSecondaryMAUI(void);
extern void NFB_FOTA_Prepare_Bootup(void);
extern void NFB_InitThirdROM(void);

#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */


#if defined(__NEW_OS_TICK__) && !defined(__MEUT__)
extern void RTOS_EnableOSTick(void);
#endif /* __NEW_OS_TICK__ && !__MEUT__ */


#if defined(__NUCLEUS_VERSION_2__)
extern void TCCT_Schedule(VOID);
extern void **TCCT_Dispatch_LISR(INT, VOID *);
extern void TCCT_Dispatch_Nested_LISR(INT);
extern void **(*ESAL_GE_ISR_OS_Entry)(INT, VOID *);
extern void (*ESAL_GE_ISR_OS_Nested_Entry)(INT);
extern void (*ESAL_GE_STK_Unsol_Switch_OS_Entry)(VOID);
#endif /*__NUCLEUS_VERSION_2__*/


#if defined(__TST_MODULE__)
extern kal_bool tst_inject_string_callback_register(kal_uint32 id, TST_String_Inject_CB func);
#endif /* __TST_MODULE__ */
extern void ex_handle_inject_string(kal_uint32 index, kal_uint8 *pData);

extern void PreInit_Seriport(void);
#if defined(__KAL_RECORD_BOOTUP_LOG__) || defined(__KEYPAD_DEBUG_TRACE__)
extern void INT_InitBootupTrace(void);
#endif /* __KAL_RECORD_BOOTUP_LOG__ || __KEYPAD_DEBUG_TRACE__ */

extern void EMI_reg_dump_init(void);
extern kal_bool gdb_init(void);
extern kal_int8 custom_setAdvEMI(void);
extern DCL_BOOL pmu_long_press_reset_sw_workaround_query(void);
/*__FUE__ compile option is used for FOTA firmware update engine */
/*add this  compile option  to avoid compiling other function*/
#ifndef __FUE__
/*
 * NoteXXX:
 *    Please DO NOT place your code in the execution region EMIINITCODE.
 *    Code in this region is used for EMI/PLL initialization, and will be
 *    OVERWRITTEN after INT_InitRegions.
 */
/* [BB porting] Make sure the flow to set EMI&SFI and the placement of the code */
#ifdef __MTK_TARGET__
#pragma arm section code = "EMIINITCODE"
#endif /* __MTK_TARGET__ */
/*************************************************************************
* FUNCTION
*  INT_SetEMIPLL
*
* DESCRIPTION
*  This function dedicates for PLL setting.
*
* CALLS
*  Non
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void INT_SetEMIPLL(void)
{
    custom_setEMI();
    custom_setSFI();   /* Dot: __SERIAL_FLASH_EN__ is checked in custom\custom_SFI.c */

    INT_SetPLL(PLL_MODE_MAUI);
#if defined(MT6253) || defined(MT6236) || defined(MT6236B) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    custom_setAdvSFI();    /* Dot: __SERIAL_FLASH_EN__ is checked in custom\custom_SFI.c */
    custom_setAdvEMI();
#endif
}


#ifdef __MTK_TARGET__
#pragma arm section code
#endif /* __MTK_TARGET__ */


/*************************************************************************
* FUNCTION
*  Application_Initialize
*
* DESCRIPTION
*   This function implements project protocol stack, hardware depedent
* initialization
*
* CALLS
*  Initialize()
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if defined(KAL_ON_NUCLEUS)
#if defined(__NUCLEUS_VERSION_2__)
void Application_Initialize(NU_MEMORY_POOL *system_memory, NU_MEMORY_POOL *uncached_memory)
#else
void Application_Initialize (void *first_available_memory)
#endif /* __NUCLEUS_VERSION_2__ */
#elif defined(KAL_ON_THREADX)
void tx_application_define(void *first_unused_memory)
#endif
{
    TS_END(TSID_INIT_ASM);


    TS_BEGIN(TSID_INIT_APPINIT);
    TS_BEGIN(TSID_INIT_CLIB1);
    print_bootup_trace(SST_INIT_APPINIT_START);

    print_bootup_trace(SST_INIT_CLIB1_ENTER);
    clib_basic_init();
   
    print_bootup_trace(SST_INIT_CLIB1_EXIT);
    TS_END(TSID_INIT_CLIB1);

#ifdef __SV5_ENABLED__
    /* Toggle */
    DummyReference();
#endif

    /* Set WDT base for nuclcues usage */
    WATCHDOG_BASE = WDT_RESTART;
    WATCHDOG_RESTART_CMD = WDT_RESTART_KEY; 

#if defined(__SMART_PHONE_MODEM__)
    /* For smart phone project, do the handshake with AP processor */
    TS_BEGIN(TSID_INIT_CCCIHS1);
    print_bootup_trace(SST_INIT_CCCIHS1_ENTER);
    ccci_init_handshake_phase1();
    print_bootup_trace(SST_INIT_CCCIHS1_EXIT);
    TS_END(TSID_INIT_CCCIHS1);
#endif /* __SMART_PHONE_MODEM__ */

#if defined(__DSP_FCORE4__)
   /* For project with Fcore DSP, handshake with DSP */
   TS_BEGIN(TSID_INIT_MDCIHS1);
   print_bootup_trace(SST_INIT_MDCIHS1_ENTER);
   mdci_init_handshake_phase1();
   print_bootup_trace(SST_INIT_MDCIHS1_EXIT);
   TS_END(TSID_INIT_MDCIHS1);
#endif  /* __DSP_FCORE4__ */

   /* 
    * NoteXXX: Not all HW modules are avaiable in the Co-SIM envrionment.
    *          Need to bypass 32K calibration in Co-SIM (via __COSIM_BYPASS_DRV__).
    */
#if !defined(__COSIM_BYPASS_DRV__)
   /* no need to calibrate 32KHz clock if bootloader had done it */
#if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))
#if !defined(MT6270A)  //MT6270A does not have TDMA
   /* 32K clock calibration */
   HW_TDMA_Start();
   HW_wait_32k_start();
#endif //!MT6270A
#endif  /* !(__BL_ENABLE__ || _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__ || __EMMC_BOOTING__) */
#endif    /* !__COSIM_BYPASS_DRV__ */

   /* Multi-Boot */
#ifdef __MULTI_BOOT__

   INT_GetBootConfig();
    
#ifndef L1_NOT_PRESENT
    /* Set mode for L1 usage */
   TS_BEGIN(TSID_INIT_L1DINITMODE);
   print_bootup_trace_enter(SST_INIT_L1DINITMODE);
   L1D_SetInitMode(_boot_mode);
   print_bootup_trace_exit(SST_INIT_L1DINITMODE);
   TS_END(TSID_INIT_L1DINITMODE);
#endif /* L1_NOT_PRESENT */

#endif /* __MULTI_BOOT__ */

    /* Initialize system specific module */
    TS_BEGIN(TSID_INIT_SYSTEMINIT);
    print_bootup_trace_enter(SST_INIT_SYSTEMINIT);
    systemInitialization();
    print_bootup_trace_exit(SST_INIT_SYSTEMINIT);
    TS_END(TSID_INIT_SYSTEMINIT);

    /* 
    * NoteXXX: Not all HW modules are avaiable in the Co-SIM envrionment.
    *          Need to bypass hardware initialization in Co-SIM (via __COSIM_BYPASS_DRV__).
    *          But watchdog is still needed to be disabled.
    */

#if !defined(__COSIM_BYPASS_DRV__)
    TS_BEGIN(TSID_INIT_HW_INIT);
    HWDInitialization(); 
    TS_END(TSID_INIT_HW_INIT);
#else    /* !__COSIM_BYPASS_DRV__ */
 
#ifdef __CENTRALIZED_SLEEP_MANAGER__
    /* Initialize micro second counter and OS timer */
    TS_BEGIN(TSID_INIT_OSTD);
    print_bootup_trace_enter(SST_INIT_OSTD);
    USC_Start();
    RM_Init(); 
    OSTD_Init(); // before OSTD_Init() and before 2G and 3G SMM's init() function
    OSTD_SetFrmDur(4615);
    OSTD_EnOST(KAL_TRUE);
    print_bootup_trace_exit(SST_INIT_OSTD);
    TS_END(TSID_INIT_OSTD);
#endif /*__CENTRALIZED_SLEEP_MANAGER__*/

#endif    /* !__COSIM_BYPASS_DRV__ */
     
#if defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__)
#if defined(__FOTA_DM__) && (defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__))
    TS_BEGIN(TSID_INIT_PREFOTA);
    print_bootup_trace_enter(SST_INIT_PREFOTA);
    NFB_FOTA_Prepare_Bootup();
    print_bootup_trace_exit(SST_INIT_PREFOTA);
    TS_END(TSID_INIT_PREFOTA);
#endif /* __FOTA_DM__ && (_NAND_FLASH_BOOTING_ || __EMMC_BOOTING__) */
#if defined(__NFB_THIRD_ROM_SUPPORT__)
    print_bootup_trace_enter(SST_INIT_THIRDROM);
    NFB_InitThirdROM();
    print_bootup_trace_exit(SST_INIT_THIRDROM);
#endif /* __NFB_THIRD_ROM_SUPPORT__ */    
    TS_BEGIN(TSID_INIT_LOADSECMAUI);
    print_bootup_trace_enter(SST_INIT_LOADSECMAUI);
    NFB_LoadingSecondaryMAUI();   
    print_bootup_trace_exit(SST_INIT_LOADSECMAUI);
    TS_END(TSID_INIT_LOADSECMAUI);
   
    /* Initialize demand paging */
    TS_BEGIN(TSID_INIT_DEMP);
    print_bootup_trace_enter(SST_INIT_DEMP);
    demp_init();
    print_bootup_trace_exit(SST_INIT_DEMP);
    TS_END(TSID_INIT_DEMP);
#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */

#if defined(__BOOT_CERT__)
   srd_dl_ctrl_pre_check();
#endif


    /* 
    * NoteXXX: Not all HW modules are avaiable in the Co-SIM envrionment.
    *          Need to bypass DRV INIT in Co-SIM (via __COSIM_BYPASS_DRV__).
    */
#if !defined(__COSIM_BYPASS_DRV__)
    TS_BEGIN(TSID_INIT_DRV2_START);
    print_bootup_trace(SST_INIT_DRV2_START);
    Drv_Init_Phase2();
    print_bootup_trace(SST_INIT_DRV2_OK);   
    TS_END(TSID_INIT_DRV2_START);  

#if (defined(MT6236) || defined(MT6236B) || defined(MT6256) || defined(MT6276) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268T) || defined(MT6268H)) || defined(MT6255)
#if !(defined(__OLD_PDN_ARCH__) && defined(__OLD_PDN_DEFINE__))
   mm_disable_power(MMPWRMGR_GMC);
#endif    
#endif    
   
#endif    /* !__COSIM_BYPASS_DRV__ */

    /* Resource initialization */
    TS_BEGIN(TSID_INIT_RESINIT);
    print_bootup_trace_enter(SST_INIT_RESINIT);

#if defined(__BOOT_CERT__)
    srd_dl_ctrl_check();
#endif

    systemInitializeResource();
    print_bootup_trace_exit(SST_INIT_RESINIT);
    TS_END(TSID_INIT_RESINIT);

    TS_BEGIN(TSID_INIT_CLIB2);
    print_bootup_trace_enter(SST_INIT_CLIB2);
    clib_init();
    print_bootup_trace_exit(SST_INIT_CLIB2);
    TS_END(TSID_INIT_CLIB2);
   
    /*The following init must be done before mainp() for KTEST need scheduling work*/
#if defined(__NUCLEUS_VERSION_2__)
    /* Set nucleus plus 2.1 scheduling, LISR & Nested LISR function ptr,
      we can change the function ptr when we need. */
    ESAL_GE_STK_Unsol_Switch_OS_Entry = TCCT_Schedule;
    ESAL_GE_ISR_OS_Entry = TCCT_Dispatch_LISR;
    ESAL_GE_ISR_OS_Nested_Entry = TCCT_Dispatch_Nested_LISR;
#endif /* __NUCLEUS_VERSION_2__ */

#if defined(__SV5_ENABLED__) && defined(__SECURE_RO_ENABLE__)
    CBRUtl_InitService();
#endif

#ifdef __SECURE_DATA_STORAGE__
    SDS_Init();
#endif


    /* MAUI protocol stack entry routine */
    TS_BEGIN(TSID_INIT_MAINP);
    mainp();   
    print_trace(SST_INIT_APPINIT_OK);
    TS_END(TSID_INIT_MAINP);

    //init_ev_timestamp = kal_get_systicks();

#if defined(DEBUG_SWLA)
    SLA_Enable();    
#endif
    SLA_Init();

#ifdef __MULTI_BOOT__
#ifdef __PRODUCTION_RELEASE__
    /* Disable watchdog for META boot */
    if ( system_boot_mode==FACTORY_BOOT ) {
        WDT_CTRL_ENABLE_T wdt_data;
        DCL_HANDLE init_dcl_wdt_handle;
        
        wdt_data.fgEnable=KAL_FALSE;
        init_dcl_wdt_handle=DclWDT_Open(DCL_WDT,0);	
	    DclWDT_Control(init_dcl_wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T*)&wdt_data);
	    DclWDT_Close(init_dcl_wdt_handle);	
	}
#elif defined(MT6261) || defined(MT2501) || defined(MT2502)
    /* Disable watchdog for META boot */
    if (system_boot_mode==FACTORY_BOOT && pmu_long_press_reset_sw_workaround_query() == DCL_TRUE)
    {
        WDT_CTRL_ENABLE_T wdt_data;
        DCL_HANDLE init_dcl_wdt_handle;
        
        wdt_data.fgEnable=KAL_FALSE;
        init_dcl_wdt_handle=DclWDT_Open(DCL_WDT,0);	
        DclWDT_Control(init_dcl_wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T*)&wdt_data);
        DclWDT_Close(init_dcl_wdt_handle);	
    }
#endif /* __PRODUCTION_RELEASE__ */
#endif  /* __MULTI_BOOT__ */
     
    /* Set watchdog timeout to 4 sec */
    /* 1 tick = 15.6 ms, 255 ticks ~= 4 sec */
    WDT_SetValue(255);

#if defined(__DSP_FCORE4__) && defined(MT6270A)
    print_bootup_trace_enter(SST_INIT_DMDSP1);
    dmdsp_init(); /* moved to bootarm.s */
    print_bootup_trace_exit(SST_INIT_DMDSP1);
#endif  /* __DSP_FCORE4__ */


#if defined(__SMART_PHONE_MODEM__)
    /* handshake to tell AP processor MD boot-up successfully */
    TS_BEGIN(TSID_INIT_CCCIHS2);
   print_bootup_trace_enter(SST_INIT_CCCIHS2);
   ccci_init_handshake_phase2(_boot_mode);
   print_bootup_trace_exit(SST_INIT_CCCIHS2);
   TS_END(TSID_INIT_CCCIHS2);
#endif /* __SMART_PHONE_MODEM__ */


#if defined(__DSP_FCORE4__)
   TS_BEGIN(TSID_INIT_MDCIHS2);
   print_bootup_trace_enter(SST_INIT_MDCIHS2);
   mdci_init_handshake_phase2(0);
   print_bootup_trace_exit(SST_INIT_MDCIHS2);
   TS_END(TSID_INIT_MDCIHS2);
   TS_BEGIN(TSID_INIT_DMDSP2);
   print_bootup_trace_enter(SST_INIT_DMDSP2);
   dmdsp_ex_init();
   print_bootup_trace_exit(SST_INIT_DMDSP2);
   TS_END(TSID_INIT_DMDSP2);
#endif  /* __DSP_FCORE4__ */

#if defined(__CPU_USAGE_ON_CATCHER__)
   kal_profile_enable();
#endif /* __CPU_USAGE_ON_CATCHER__ */

   TS_END(TSID_INIT_APPINIT);

#if !defined(_NAND_FLASH_BOOTING_)
   // ready to display 1st screen for NOR booting 
   TS_END(TSID_INIT_READY_TO_DISPLAY);
#endif

   TS_END(TSID_INIT_TOTAL);

   // dump time stamp from UART 
   TS_DumpTimeStamps();

   DCMGR_init_phase2();
   
#if defined(__TINY_SYS__)
   CSD_AP_Stack_error();
#endif
}


/*************************************************************************
* FUNCTION
*  systemInitialization
*
* DESCRIPTION
*   This function implements the system specific initialization, including
*   interrupt central controller, FDD and KAL.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void systemInitialization(void)
{
   /* initialize the interrupt controller */
   initINTR();
   
   IRQ_LISR_Init();
   
#if !(defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)) || defined(__NANDFDM_MULTI_INSTANCE__)
   Initialize_FDD_tables();
#endif /* !(_NAND_FLASH_BOOTING_ || __EMMC_BOOTING__) || __NANDFDM_MULTI_INSTANCE__ */

   /* Register display handler */
   kal_register_print_string_function((kal_print_string_func_ptr)stack_print);

   /* Register stack fatal error handler */
   kal_register_fatal_error_handler((kal_error_func_ptr)fatal_error_handler);
    
   kal_initialize_mem();
   
   /* Initializing the Buffer Pool Information */
   stack_init_buff_pool_info();
   
   /* Create buffer pools */
   stack_resources_init();   

   /* Initialize KAL resources */
   kal_initialize();
   
   /* Initialize KAL CPU usage profiling */
   kal_profile_init();
}


/*************************************************************************
* FUNCTION
*  HWDInitialization
*
* DESCRIPTION
*   This function implements hardware dependent initialization and
*   management
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
static void HWDInitialization(void)
{
    
    PW_CTRL_IS_USB_BOOT CtrlVal;
    DCL_HANDLE handle;

#ifdef __CENTRALIZED_SLEEP_MANAGER__
    print_bootup_trace_enter(SST_INIT_USC);
    USC_Start();
    print_bootup_trace_exit(SST_INIT_USC);
#endif /*__CENTRALIZED_SLEEP_MANAGER__*/

    
#if (defined(MT6236) || defined(MT6236B) || defined(MT6256) || defined(MT6276) || defined(MT6268) || defined(MT6268A) || defined(MT6268B) || defined(MT6268T) || defined(MT6268H)) || defined(MT6255)
#if !(defined(__OLD_PDN_ARCH__) && defined(__OLD_PDN_DEFINE__))
   mm_enable_power(MMPWRMGR_GMC);
#endif    
#endif    
#ifdef MT6208 /* only MT6208 need to do this */
   /* Baseband power up control, 32khz oscillator power down mode */
   {
      kal_uint32 delay=1000000;

      REG_WRITE(RTC_base, 0x4316);
      while (delay>0) {  /* delay for settling 32KHz */
         delay--;
      }
   }
#endif /* MT6208 */

#ifdef __CENTRALIZED_SLEEP_MANAGER__
   print_bootup_trace_enter(SST_INIT_OSTD);
   //USC_Start();
   RM_Init(); // before OSTD_Init() and before 2G and 3G SMM's init() function
   OSTD_Init();
   print_bootup_trace_exit(SST_INIT_OSTD);
#endif /*__CENTRALIZED_SLEEP_MANAGER__*/

#ifdef MTK_SLEEP_ENABLE
   /* Added by Anthony Chin 03/18/2002. For sleep mode management. */
   print_bootup_trace_enter(SST_INIT_L1SM);
   L1SM_Init();
   print_bootup_trace_exit(SST_INIT_L1SM);
#ifdef __MTK_UL1_FDD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* MTK_SLEEP_ENABLE */

#ifdef __CENTRALIZED_SLEEP_MANAGER__
   print_bootup_trace_enter(SST_INIT_OSTD);
   OSTD_SetFrmDur(4615);
   OSTD_EnOST(KAL_TRUE);
   print_bootup_trace_exit(SST_INIT_OSTD);
#endif /*__CENTRALIZED_SLEEP_MANAGER__*/

#ifndef L1_NOT_PRESENT
#ifdef __HW_DIVIDER__
   /* Power on Divider.(PDN_CON2) */
   print_bootup_trace_enter(SST_INIT_HWDIVIDER);
   HW_Divider_Initialization();
   print_bootup_trace_exit(SST_INIT_HWDIVIDER);
#endif /* __HW_DIVIDER__ */
#endif    /* L1_NOT_PRESENT */

#ifdef IDMA_DOWNLOAD
   /* Load DSP via iDMA. */
   print_bootup_trace_enter(SST_INIT_IDMALOAD);
   REG_WRITE(DPRAM_CPU_base, 0);
   idma_load();
   print_bootup_trace_exit(SST_INIT_IDMALOAD);
#endif /* IDMA_DOWNLOAD */
   
   print_bootup_trace_enter(SST_INIT_NFIRESET);   
   NFI_Reset();
   print_bootup_trace_exit(SST_INIT_NFIRESET);
   
   print_bootup_trace(SST_INIT_DRV1_START);
   Drv_Init_Phase1();
   print_bootup_trace(SST_INIT_DRV1_OK);
   
#if defined(__ZIMAGE_SUPPORT__)
/* To be revised - START */
   MPU_Unprotect_One_Region(Zimage_Section);
/* To be revised - END */
   print_bootup_trace_enter(SST_INIT_ZIMAGE);
   ZImageDecompress();
   print_bootup_trace_exit(SST_INIT_ZIMAGE);
#endif /* __ZIMAGE_SUPPORT__ */

/* To be revised - START */
#if defined(__BOOT_ZIMAGE_SUPPORT__)
   MPU_protect_One_Region(Boot_Zimage_Section,PRIV_RO_USER_RO);
#endif
#if defined(__ZIMAGE_SUPPORT__)
	MPU_protect_One_Region(Zimage_Section,PRIV_RO_USER_RO);
#endif 
/* To be revised - END */

#if defined(__DCM_WITH_COMPRESSION__) || defined(__DYNAMIC_CODE_MANAGER__)
/* To be revised - START */
#if !defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
    MPU_Unprotect_One_Region(DCM_Section);
#endif
/* To be revised - END */
    DCMGR_Init();
#endif

#if defined(TK6516) || (defined(MT6516) && !defined(__APPLICATION_PROCESSOR__))
#ifndef __SMART_PHONE_MODEM__
    // disable AP side watch dog timer 
    *((volatile UINT16P)0xF0003000) = 0x2220;
#endif
#endif

#ifdef __USB_ENABLE__

   handle = DclPMU_Open(DCL_PMU,FLAGS_NONE);
   DclPW_Control(handle, PW_CMD_IS_USB_BOOT, (DCL_CTRL_DATA_T *)&CtrlVal);

   if (CtrlVal.val) 
   {
#ifndef __NVRAM_IN_USB_MS__

#if !defined(MT6208)
      *(volatile kal_uint16 *)(TDMA_base+0x14) = 0x1000;
#endif /* !MT6208 */

#if !defined(MT6270A)
      IRQUnmask(IRQ_CTIRQ1_CODE);
      *(volatile kal_uint16 *)(TDMA_base+0x150) = *(volatile kal_uint16 *)(TDMA_base+0x150) | 0x0002;
      IRQ_Register_LISR(IRQ_CTIRQ1_CODE, isrCTIRQ1_USBPowerOn,"CTIRQ1");
#endif //!MT6270A

#endif /* !__NVRAM_IN_USB_MS__ */

#if defined(__NEW_OS_TICK__) && !defined(__MEUT__)
    RTOS_EnableOSTick();
#endif /* __NEW_OS_TICK__ */
   }
   
#endif /*__USB_ENABLE__*/

#ifdef L1_NOT_PRESENT

#if ( defined(MT6516) && defined(__APPLICATION_PROCESSOR__) ) || defined(MT6270A)
   // Do Nothing
#elif defined(MT6516) && !defined(__APPLICATION_PROCESSOR__)
   *(volatile kal_uint16 *)(TDMA_base+0x14)  = 0x1000;
   IRQUnmask(IRQ_CTIRQ1_CODE);
   *(volatile kal_uint16 *)(TDMA_base+0x150) = *(volatile kal_uint16 *)(TDMA_base+0x150) | 0x0002;
#elif defined(MT6208)
   IRQUnmask(IRQ_CTIRQ1_CODE);
   *(volatile kal_uint16 *)(TDMA_base+0x150) = *(volatile kal_uint16 *)(TDMA_base+0x150) | 0x0002;
#else
   *(volatile kal_uint16 *)(TDMA_base+0x14)  = 0x1000;
   IRQUnmask(IRQ_CTIRQ1_CODE);
   *(volatile kal_uint16 *)(TDMA_base+0x150) = *(volatile kal_uint16 *)(TDMA_base+0x150) | 0x0002;
#endif /* MT6516 && __APPLICATION_PROCESSOR__ */
   
#endif /* L1_NOT_PRESENT */

}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

/*************************************************************************
* FUNCTION
*  INT_GetBootConfig
*
* DESCRIPTION
*   This function is used to get boot configuration
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if defined(__MULTI_BOOT__)
static void INT_GetBootConfig(void)
{
    _boot_mode = 0x1 & *(volatile kal_uint16 *)BOOT_CONFIG_ADDR;
    g_l_sw_misc_l =  *(volatile kal_uint16 *)BOOT_CONFIG_ADDR;
    
    if (0x4 & *(volatile kal_uint16 *)BOOT_CONFIG_ADDR)
    {
        _IsBootForUSBAT = KAL_TRUE;
    }

    /* enable memory dump in meta mode */
    if (INT_BootMode() == MTK_FACTORY_MODE)
    {
        ex_set_memorydump_flag();
    }
}
#endif /* __MULTI_BOOT__ */

/*************************************************************************
* FUNCTION
*    INT_DebugInit
*
* DESCRIPTION
*    This function is used to do debugging suite related initialization.
*
* PARAMETERS
*
*
* RETURNS
*
* IMPLEMENTATION FLAVORS
*
*************************************************************************/
void INT_DebugInit(void)
{
    /* must register HAL serial port for UART/USB EARLY usage */
    /* (e.g. bootup trace, all time memory dump)              */
    PreInit_Seriport();
#if defined(__KAL_RECORD_BOOTUP_LOG__) || defined(__KEYPAD_DEBUG_TRACE__)
    INT_InitBootupTrace();
#endif     /* __KAL_RECORD_BOOTUP_LOG__ || __KEYPAD_DEBUG_TRACE__ */

    EMI_reg_dump_init();
    
    gdb_init();

#if defined(__FORCE_MEMORY_DUMP__)
    ex_set_memorydump_flag();
#endif /* __FORCE_MEMORY_DUMP__ */

#if defined(__TST_MODULE__)
    /* register inject command handler of exception handler */
    tst_inject_string_callback_register(MOD_SST_COMMON, (TST_String_Inject_CB)ex_handle_inject_string);
#endif /* __TST_MODULE__ */
}

/*************************************************************************
* FUNCTION
*   INT_Get_PowerOn_Type
*
* DESCRIPTION
*   This function used to return the power on reason 
*   
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
PW_CTRL_POWER_ON_REASON INT_Get_PowerOn_Type(void)
{
    PW_CTRL_GET_POWERON_REASON CtrlVal;
    DCL_HANDLE handle;
    
    
    handle=DclPW_Open(DCL_PW, FLAGS_NONE);
    DclPW_Control(handle,PW_CMD_GET_POWERON_REASON,(DCL_CTRL_DATA_T *)&CtrlVal);
    DclPW_Close(handle);
    
    return CtrlVal.powerOnReason;
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif


/*************************************************************************
* FUNCTION
*   systemInitializeResource
*
* DESCRIPTION
*   This function aims resource initialization, including audio, image, 
*   font etc.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif 
void systemInitializeResource(void)
{
    
    DCL_HANDLE handle;
    PW_CTRL_GET_POWERON_REASON poweron_type;
    
    poweron_type.powerOnReason = INT_Get_PowerOn_Type();
    
    
#if ( defined(__MTK_TARGET__) && !defined(__MAUI_BASIC__) && !defined(__L1_STANDALONE__)  && !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)) 

   InitializeResourceVariables();
   
#endif       


#if !(defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__))

#if ( defined(__USB_ENABLE__) && !defined(__MAUI_BASIC__) )

   if ( ((poweron_type.powerOnReason != CHRPWRON) && (poweron_type.powerOnReason != PWRKEYPWRON) && (poweron_type.powerOnReason != USBPWRON)) || 
        ((poweron_type.powerOnReason == PWRKEYPWRON) && (Check_NORFlash_Formatted() == 1)) )
        
#elif ( defined(__MAUI_BASIC__) || defined(_SIMULATION))

   if ( (poweron_type.powerOnReason != CHRPWRON) && (poweron_type.powerOnReason != USBPWRON) )
   
#else

   if ( ((poweron_type.powerOnReason != CHRPWRON) && (poweron_type.powerOnReason != PWRKEYPWRON)) || 
        ((poweron_type.powerOnReason == PWRKEYPWRON) && (Check_NORFlash_Formatted() == 1)) )
        
#endif


    {
        handle = DclPW_Open(DCL_PW,FLAGS_NONE);
        DclPW_Control(handle, PW_CMD_POWERON, NULL);
        DclPW_Close(handle);
    }


#if !defined(__L1_STANDALONE__) && !defined(EMPTY_MMI)

#ifdef __MULTI_BOOT__

   if ( (poweron_type.powerOnReason == PWRKEYPWRON) && (Check_NORFlash_Formatted()==1 || MTK_FACTORY_MODE==INT_BootMode()) )
   
#else

   if ( (poweron_type.powerOnReason == PWRKEYPWRON) && (Check_NORFlash_Formatted() == 1) )
   
#endif   /*__MULTI_BOOT__*/

      MMICheckDiskDisplay();
      
#endif

#endif /* !(_NAND_FLASH_BOOTING_ || __EMMC_BOOTING__) */

   srand(rand_num_seed);
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif


/*************************************************************************
* FUNCTION
*  INT_SetChipReg
*
* DESCRIPTION
*   This function sets registers on the chip at system initial stage.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void INT_SetChipReg()
{
#if defined(MT6218B)

   if (INT_ecoVersion() <= EN) 
   {
      /* Changing the output driving capability on both digital and analog die to solve the bug at BBRX comb filter */

      *(ACIF_CON1) = 0x0600;

      *(AC_ODS_CON) = 0x0004;
   }

#elif defined(MT6219)   /* MT6218B */

   if (INT_ecoVersion() <= BV) 
   {
      /* Changing the output driving capability on both digital and analog die to solve the bug at BBRX comb filter */

      *(ACIF_CON1) = 0x0600;

      *(AC_ODS_CON) = 0x0004;
   }

#elif defined(MT6217)   /* MT6218B */

    /* change DSP ROM rm value */

    *((volatile kal_uint32 *)0x80000800) = 0x1505;

    *((volatile kal_uint32 *)0x80000804) = 0x1717;

    *((volatile kal_uint32 *)0x80000808) = 0x1517;
    
#elif defined(MT6228_S00)   /* MT6218B */    

    /*
     * To fix the bug of RX/TX, apply the setting for reworked MT6228.
     */

    *(volatile kal_uint32 *)0x80010068 |= 0x00008a80;

#elif defined(MT6229_S00)   /* MT6218B */

    /*
     * To fix the hardware bug of IRDMA, 
     * set the IRWIN register such that IRDMA does not always have the first priority.
     */
    *(volatile kal_uint32 *)0x80000500 = 0;

#elif defined(MT6226M)

   if ((*HW_CODE == 0x6219) && ((*HW_VER & 0xff00) == 0x8b00))

      *ACIF_CON0 |= 0x0001;
      
#elif defined(MT6223)    || defined(MT6223P)

   *ACIF_CON0 = 0x1;
   
#elif defined(MT6268T) || defined(MT6268H)

   *(volatile kal_uint32 *)0x80000700 = 0xEEEEEEEE;
   *(volatile kal_uint32 *)0x80000704 = 0xEEEEEEEE;
   *(volatile kal_uint32 *)0x80000708 = 0xEEEEEEEE;
   *(volatile kal_uint32 *)0x8000070C = 0xEEEEEEEE;
   *(volatile kal_uint32 *)0x80000710 = 0xEEEEEEEE;
   *(volatile kal_uint32 *)0x80000714 = 0xEEEEEEEE;
   *(volatile kal_uint32 *)0x80500000 = 0xF;

#elif defined(MT6236) || defined(MT6236B)

   /* set GMC MPU register to protect part of DTCM from GMC's corruption */
   /* DTCM 0 ~ 74KB is not accessible for GMC, 74KB ~ 172KB is accessible for GMC */
   *GMC_MPU_CON |= 0x004A;

   *MCUSYS_DELSEL0 &= ~0x003FC000;
   *MCUSYS_DELSEL0 |= 0x002A8000;
       
   /* set MUCSYS_DELSEL for E2 DCache bug */
   if(INT_ecoVersion() == ECO_E2) {
       *MCUSYS_DELSEL0 &= ~0x3FC00000;
       *MCUSYS_DELSEL0 |= 0x3FC00000; // D-caceh delsel = 3
   }

#elif defined(MT6276)
    
    *(volatile kal_uint32 *)(SEJ_base + 0x0000) |= 0x00001000;

#endif  /* MT6218B */
}

/*************************************************************************
* FUNCTION
*  INT_Config
*
* DESCRIPTION
*   This function implements adjusting Memory Block 0 (EMI_CON0) Wait
*  State's setting
*
* CALLS
*  INT_Decrypt, INT_SetPLL, INT_SetChipReg
*
* PARAMETERS
*
* RETURNS
*  the seed value for random number
*
* GLOBALS AFFECTED
*
*************************************************************************/
void INT_Config(void)
{
#if defined(TK6516) || (defined(MT6516) && !defined(__APPLICATION_PROCESSOR__))
   /* Setup backdoor to channel 8 and lock it */
   *(volatile kal_uint16 *)0x811A0000 = 0x18;    
#endif /* TK6516 || MT6516 */

#if defined(__MULTI_BOOT__) && !defined(L1D_TEST_COSIM)
   /* Check BOOT_CONFIG_ADDR */
   if ( 0 != (0x1 & (*(volatile kal_uint16 *)BOOT_CONFIG_ADDR)) )
   {
      /* Enter FT_MODE, delay for waiting UART flush TX buffer */
   #if defined(MCU_26M)   
      kal_uint32 delay;      
      for (delay = 0; delay < 10000; delay++)
         ;   /* nop */         
   #elif defined(MCU_52M)   
      kal_uint32 delay;
      for (delay = 0; delay < 25000; delay++)
         ;   /* nop */
   #endif
   }
#endif   /* __MULTI_BOOT__ & !L1D_TEST_COSIM */


#ifdef MT6218B
   if (INT_ecoVersion() == BN)
      *(volatile kal_uint16 *)0x80000500 = 0x0001 ;
#endif   /* MT6218B */

#if defined(MT6226) || defined(MT6227) || defined(MT6226M)
   if (INT_ecoVersion() == ECO_E1)
      *(volatile kal_uint16 *)0x80500108 = 0x1000;
#endif /* MT6226 || MT6227 || MT6226M */


#if defined(_SIMULATION)

    /*
     * For co-sim load,
     * EMI on both bank 0 and bank 1 are assigned with 0x4102.
     * And Register 0x80010044 (EMI General Control Register) reserves the default value.
     */
#if (!defined(MT6205B) && !defined(MT6208))

    *EMI_CONA = 0x00004102;    
    *EMI_CONB = 0x00004102;  
    
#else /* !MT6205B && !MT6208 */

    *EMI_CON0 = 0x4102;
    *EMI_CON1 = 0x4102;
    
#endif /* !MT6205B && MT6208 */

   INT_SetPLL(PLL_MODE_MAUI);

#else /* _SIMULATION */

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__) || defined(__USB_DOWNLOAD__) || defined(__FOTA_ENABLE__) || defined(__BL_ENABLE__)
   /*
    * For NFB , UBL or FOTA case , bootloader/FUE already done the 
    * custom_setEMI() and INT_SetPLL()
    */

#else

   INT_SetEMIPLL();
   
#endif /* _NAND_FLASH_BOOTING_ || __USB_DOWNLOAD__ || __EMMC_BOOTING__ || _FOTA_ENABLE || BL_ENABLE */

#ifdef MT6225
   *(volatile kal_uint32 *)(0x80010078) = 0;
#endif /* MT6225 */

#endif /* _SIMULATION */

   /*
    *  Scan serial Flash blocks for leakage recovery
    */
#if (defined(MT6252) || defined(__SERIAL_FLASH_EN__)) && defined(__MTK_TARGET__)
#include "custom_MemoryDevice.h"
   {
      #if !defined(__NOR_FDM5__)
      extern void ScanSerialFlashBlocks(void);
      ScanSerialFlashBlocks();
      #else
      extern void ScanSerialFlashBlocks_FDM5(void);
      ScanSerialFlashBlocks_FDM5();
      #endif
   }
#endif // __SERIAL_FLASH_EN__ && __MTK_TARGET__

   INT_SetChipReg();
}

/*************************************************************************
* FUNCTION
*  INT_BootMode
*
* DESCRIPTION
*   This function implements to return boot mode. Remember the routine muse
* be called after Application_Initialize.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint16 INT_BootMode(void)
{
   return _boot_mode;
}

/*************************************************************************
* FUNCTION
*  INT_BootMETAMode
*
* DESCRIPTION
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_int32 INT_BootMetaMode(void)
{
    if((g_l_sw_misc_l & 0x11) == 0x11)
    {
        return 1;
    }
    else if((g_l_sw_misc_l & 0x11) == 0x01)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

/*************************************************************************
* FUNCTION
*  INT_InvokeSSTEngine
*
*************************************************************************/
#define _SST_FUNCTION_ENABLE_
void INT_InvokeSSTEngine(kal_int32 err_code, kal_int32 os_err_code)
{
    #ifdef _SST_FUNCTION_ENABLE_
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    return;
}

/*************************************************************************
* FUNCTION
*  INT_QueryPowerDownStatus
*
* DESCRIPTION
*  Used to read-back the 4 power down control registers.
*
* CALLS
*
* PARAMETERS
*  Pointer of type CONFIG_PDN_TYPE.
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
/* Phase out function, wait EM remove the code then we could remove it */
void INT_QueryPowerDownStatus(CONFIG_PDN_TYPE *PDN_ptr)
{
#if defined(TK6516)
   PDN_ptr->pdn_con1 = *(volatile kal_uint16 *)PDN_CON1;
   PDN_ptr->pdn_con2 = *(volatile kal_uint16 *)PDN_CON2;
   PDN_ptr->pdn_con4 = *(volatile kal_uint16 *)PDN_CON4;
#elif defined(MT6516) && !defined(__APPLICATION_PROCESSOR__)   /* TK6516 */
   PDN_ptr->pdn_con0 = *(volatile kal_uint32 *)PDN_CON0;
   PDN_ptr->pdn_con1 = *(volatile kal_uint32 *)PDN_CON1;
#else   /* TK6516 */
   PDN_ptr->pdn_con0 = *(volatile kal_uint16 *)PDN_CON0;
   PDN_ptr->pdn_con1 = *(volatile kal_uint16 *)PDN_CON1;
   PDN_ptr->pdn_con2 = *(volatile kal_uint16 *)PDN_CON2;
   PDN_ptr->pdn_con3 = *(volatile kal_uint16 *)PDN_CON3;
#endif /* TK6516 */
}

/*************************************************************************
* FUNCTION
*  INT_SetPowerDownStatus
*
* DESCRIPTION
*  Setting 4 power down control registers.
*
* CALLS
*
* PARAMETERS
*  Pointer of type CONFIG_PDN_TYPE.
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
/* Phase out function, wait EM remove the code then we could remove it */
void INT_SetPowerDownStatus(CONFIG_PDN_TYPE *PDN_ptr)
{
#if defined(TK6516)
   *(volatile kal_uint16 *)PDN_SET1 = PDN_ptr->pdn_con1;
   *(volatile kal_uint16 *)PDN_SET2 = PDN_ptr->pdn_con2;
   *(volatile kal_uint16 *)PDN_SET4 = PDN_ptr->pdn_con4;   

   *(volatile kal_uint16 *)PDN_CLR1 = ~(PDN_ptr->pdn_con1);
   *(volatile kal_uint16 *)PDN_CLR2 = ~(PDN_ptr->pdn_con2);
   *(volatile kal_uint16 *)PDN_CLR4 = ~(PDN_ptr->pdn_con4);   
#elif defined(MT6516) && !defined(__APPLICATION_PROCESSOR__)
   *(volatile kal_uint32 *)PDN_SET0 = PDN_ptr->pdn_con0;
   *(volatile kal_uint32 *)PDN_SET1 = PDN_ptr->pdn_con1;

   *(volatile kal_uint32 *)PDN_CLR0 = ~(PDN_ptr->pdn_con0);
   *(volatile kal_uint32 *)PDN_CLR1 = ~(PDN_ptr->pdn_con1);
#else /* TK6516  */
   *(volatile kal_uint16 *)PDN_SET0 = PDN_ptr->pdn_con0;
   *(volatile kal_uint16 *)PDN_SET1 = PDN_ptr->pdn_con1;
   *(volatile kal_uint16 *)PDN_SET2 = PDN_ptr->pdn_con2;
   *(volatile kal_uint16 *)PDN_SET3 = PDN_ptr->pdn_con3;   

   *(volatile kal_uint16 *)PDN_CLR0 = ~(PDN_ptr->pdn_con0);
   *(volatile kal_uint16 *)PDN_CLR1 = ~(PDN_ptr->pdn_con1);
   *(volatile kal_uint16 *)PDN_CLR2 = ~(PDN_ptr->pdn_con2);
   *(volatile kal_uint16 *)PDN_CLR3 = ~(PDN_ptr->pdn_con3);   
#endif /*defined(TK6516) */      
}

/*************************************************************************
* FUNCTION
*  release_bb_chip
*
* DESCRIPTION
*   This function returns the version number of the baseband chip
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_char* release_bb_chip(void)
{
   static kal_char str_return[]="MT6205B, E00";

#if defined(FPGA)
   strcpy(str_return, "FPGA");
#elif defined(MT6208)
   strcpy(str_return, "MT6208");
#elif defined(MT6205)
   strcpy(str_return, "MT6205");
#elif defined(TK6516)
   strcpy(str_return, "TK6516");
 #elif defined(MT6253E)
   strcpy(str_return, "MT6253E");
#elif defined(MT6253L)
   strcpy(str_return, "MT6253L");
#elif defined(MT6252)
   strcpy(str_return, "MT6252");
#elif defined(MT6252H)
   strcpy(str_return, "MT6252H");
#elif defined(MT6250)
   strcpy(str_return, "MT6250");
#elif defined(MT6260)
   strcpy(str_return, "MT6260");
#elif defined(MT6261)
   strcpy(str_return, "MT6261");
#elif defined(MT2501)
   strcpy(str_return, "MT2501");
#elif defined(MT2502)
   strcpy(str_return, "MT2502");
#elif defined(MT6516)
   strcpy(str_return, "MT6516");
#elif defined(MT6921)
   strcpy(str_return, "MT6921");
#elif defined(MT6922)
   strcpy(str_return, "MT6922");
#elif defined(MT6276)
   strcpy(str_return, "MT6276");
#else /* future chips will definitely apply this rule */
   kal_uint16 hw_code;
   kal_uint8 majrev; /* bit 8~11 of HW_VER register */
   kal_uint8 ffix; /* bit 0~3 of HW_VER register */
   kal_uint16 hw_version;
   kal_uint16 temp_num;

   hw_code = *HW_CODE;
   hw_version = *HW_VER;
   majrev = (hw_version >> 8) & 0x000f; /* get MAJREV from HW_VER */
   ffix = hw_version & 0x000f; /* get FFIX from HW_VER */

   /* convert the HW_CODE to natural representation*/
   temp_num = (hw_code & 0x000f);
   hw_code >>= 4;
   temp_num += (hw_code & 0x000f) * 10;
   hw_code >>= 4;
   temp_num += (hw_code & 0x000f) * 100;
   hw_code >>= 4;
   temp_num += (hw_code & 0x000f) * 1000;

   /* construct the string for the chips MTxxxxx, ECOx */
   if (majrev == 0x0a) /* directiver A, which often skip the directive */
   {
      sprintf(str_return, "MT%4d, E%02d", temp_num, ffix);
   }
   else if (majrev == 0x0b && temp_num == 6219)
   {
      /* special hanlding for MT6226M */
      sprintf(str_return, "MT6226M, E%02d", ffix);
   }
   else
   {
      sprintf(str_return, "MT%4d%1X, E%02d", temp_num, majrev, ffix);
   }
#endif

   return str_return;
}

/*************************************************************************
* FUNCTION
*  INT_VersionNumbers
*
* DESCRIPTION
*   This function returns the version number of the followings
*   1. Chip version
*   2. DSP version
*   3. DSP patch version
*   4. MCU software version
*   5. Baseband board version
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void INT_VersionNumbers(version_struct * ptr_version)
{
   ptr_version->bb_chip = release_bb_chip();
#if !defined(__DSP_FCORE4__) 
   ptr_version->dsp_fw = release_dsp_fw();
   ptr_version->dsp_ptch = release_dsp_ptch();
#else
    // Note: use empty string temporarily, need to discuss how we should fill these fields in FCore case
   ptr_version->dsp_fw = " ";
   ptr_version->dsp_ptch = " ";
#endif //!__DSP_FCORE4__
   ptr_version->mcu_sw = release_verno();
   ptr_version->mcu_sw_branch = release_branch();
   ptr_version->bb_board = release_hw_ver();
   return;
}


/*************************************************************************
* FUNCTION
*  INT_CheckSystemDriveOnNAND()
*
* DESCRIPTION
*  Query the location of system drive, either NAND-flash or NOR-flash
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE: NFB or System Drive On NAND
*  KAL_FALSE: otherwise
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool INT_CheckSystemDriveOnNAND(void)
{
#if ( defined(__FS_SYSDRV_ON_NAND__) || defined( _NAND_FLASH_BOOTING_) )

   return KAL_TRUE;
   
#else

   return KAL_FALSE;

#endif /* __FS_SYSDRV_ON_NAND__ || _NAND_FLASH_BOOTING_ */
}

/*************************************************************************
* FUNCTION
*  INT_IsBootByCodeShadow()
*
* DESCRIPTION
*  Query if system boot via code shadow, 
*  On the other word, binary code copy to RAM before execution
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE: Nand Flash booting
*  KAL_FALSE: otherwise
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool INT_IsBootByCodeShadow(void)
{
#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)

   return KAL_TRUE;
   
#else

   return KAL_FALSE;

#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */
}

/*************************************************************************
* FUNCTION
*  INT_IsCodeShadowDone()
*
* DESCRIPTION
*  Query if binary code already ready via code shadow, 
*
* PARAMETERS
*
* RETURNS
*  KAL_TRUE: ! Nand Flash Booting , or Secondary Image loaded on NFB
*  KAL_FALSE: otherwise
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool INT_IsCodeShadowDone(void)
{
#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)

   return NFB_SecondaryImageLoaded;
   
#else

   return KAL_TRUE;

#endif /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */
}


/*************************************************************************
* FUNCTION
*  show_sysinit_msg
*
* DESCRIPTION
*  This function shows system intialization messages. It is called in the
*  entry point of the TST READER task.
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
kal_int32 show_sysinit_msg(void)
{
   kal_uint32 ret=0;
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(MT6268T) || defined(MT6268H)
   kal_char buff[40];
#endif

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
   /* display the page table usage for ARM9 MMU */

   ret = check_cptbl_pool();
   if (ret != 0) {
      system_print("WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!");
      system_print("PAGE TABLE config failure");
      sprintf(buff, "needs %d bytes for %cptbl pool", ret, 'c');
      system_print(buff);
      system_print("WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!");
   }

#if defined(__ARM9_MMU__)
   ret = check_fptbl_pool();
   if (ret != 0) {
      system_print("WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!");
      system_print("PAGE TABLE config failure");
      sprintf(buff, "needs %d bytes for %cptbl pool", ret, 'f');
      system_print(buff);
      system_print("WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!WARNING!!");
   }
#endif    /* __ARM9_MMU__ */

#endif    /* __ARM9_MMU__ || __ARM11_MMU__ */

#if defined(MT6268T) || defined(MT6268H)

   /* dispaly MT6268T FPGA version code */

   fpga1_vcode = *(volatile kal_uint32*)0xB00D0038;
   fpga2_vcode = *(volatile kal_uint32*)0xC002043C;

   sprintf(buff, "FPGA1 ver: 0x%X", fpga1_vcode);
   system_print(buff);

   sprintf(buff, "FPGA2 ver: 0x%X", fpga2_vcode);
   system_print(buff);

#endif  /* MT6268T || MT6268H */

   return ret;
}

#undef RTOS_DEBUG
/*************************************************************************
* FUNCTION
*  INT_SetCmdToSys
*
* DESCRIPTION
*  This function provide API for user to set necessary command to system
*
* PARAMETERS
*  none
*
* RETURNS
*  random seed
*
*************************************************************************/
void INT_SetCmdToSys(INIT_SYSCMD_CODE cmd_val)
{
#if !defined(__SMART_PHONE_MODEM__)
   DCL_HANDLE rtc_handler;
   RTC_CTRL_CONFIG_SPAR_T rtcSparReg;
   
   rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);  //open rtc handler
   rtcSparReg.SPARIndex = DCL_RTC_SPAR0;
   DclRTC_Control(rtc_handler, RTC_CMD_READ_SPAR, (DCL_CTRL_DATA_T *)& rtcSparReg);

   switch (cmd_val)
       {
           case ENTER_DL_AFTER_REBOOT:
   
               rtcSparReg.WriteValue = rtcSparReg.ReadValue | 0x1;
               break;
               
           case CLR_DL_FLAG:

               rtcSparReg.WriteValue = rtcSparReg.ReadValue & ~0x1;
               break;

           default:
               ASSERT(0);
               break;
   }
   
   DclRTC_Control(rtc_handler, RTC_CMD_WRITE_SPAR, (DCL_CTRL_DATA_T *)& rtcSparReg);
   DclRTC_Close(rtc_handler);  //close rtc handler
#endif /* __SMART_PHONE_MODEM__ */  

}



/*************************************************************************
* FUNCTION
*  INT_GetSysStaByCmd
*
* DESCRIPTION
*  This function provided for user to query the status of system
*
* PARAMETERS
*  none
*
* RETURNS
*  random seed
*
*************************************************************************/
kal_uint32 INT_GetSysStaByCmd(INIT_SYSCMD_CODE cmd_val, void *data_p)
{
    #if !defined(__SMART_PHONE_MODEM__)

    switch (cmd_val) {
        case CHK_USB_META_WO_BAT:
            
            if (g_l_sw_misc_l & (0x1 << 3)) {
                return KAL_TRUE;
            } else {
                return KAL_FALSE;
            }
            
        case CHK_FAST_META:

            #if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))            

            #else        
            if (BL_FAST_META_TRIGGERED & (g_pass_info.m_bl_maui_share_data.m_bl_bootup_flag)) {
                return KAL_TRUE;
            } else
            #endif    
            {
                return KAL_FALSE;
            }

        case SYS_CMD_BL_LOGO_DISPLAYED:

            #if defined(__FAST_LOGO__)    
                            
            if (BL_FAST_LOGO_DISPLAYED & (g_pass_info.m_bl_maui_share_data.m_bl_bootup_flag)) {
               return KAL_TRUE;
            } else
            #endif /* __FAST_LOGO__ */
            {
                return KAL_FALSE;
            }
                
        case SYS_CMD_GET_PWN_STA:
                        
            #if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))
                return KAL_FALSE;
            #else            
                return (g_pass_info.m_bl_maui_share_data.m_poweron_param);    
            #endif

        case SYS_CMD_GET_EMI_PARAM:
            
            #if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))
                return KAL_FALSE;
            #else            
                kal_mem_cpy(data_p,(void *)(g_pass_info.m_bl_maui_share_data.m_emi_param), sizeof(g_pass_info.m_bl_maui_share_data.m_emi_param));
                return KAL_TRUE;
            #endif

        case SYS_CMD_BL_BROM_CMD_MODE_DISABLED:
            
            #if defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__)
            if (BL_BROM_CMD_MODE_DISABLED & (g_pass_info.m_bl_maui_share_data.m_bl_bootup_flag)) {
                return KAL_TRUE;
            } else
            #endif
            {
                return KAL_FALSE;
            }
         
        default:
            ASSERT(0);
            break;
    }
    
    #endif /* __SMART_PHONE_MODEM__ */    
    
    ASSERT(0);
    return KAL_FALSE;
}



/*************************************************************************
* FUNCTION
*  INT_BackupBLShareinfo
*
* DESCRIPTION
*  This function is used to backup bootloader / maui shared information 
*  passed from bootloader
*
* PARAMETERS
*  none
*
* RETURNS
*  random seed
*
*************************************************************************/
kal_int32 INT_BackupBLShareinfo(kal_uint32 backup_addr)
{
    kal_uint32 i=0;
    kal_uint32 cpsz = 0;
    
#ifdef __TIME_STAMP__
    kal_uint32 timestamp_addr = 0;
    kal_uint32 timestamp_size = 0;
#endif    

    TS_GetContext(&timestamp_addr, &timestamp_size);

#if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))    
    return KAL_TRUE;

#else /* !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__)) */

    cpsz = sizeof(BL_Info_Wrapper_st);
    for (i = 0; i < ((cpsz+3) >> 2); i++)
    {
      *((volatile unsigned long *)backup_addr + i )= *((volatile unsigned long *)BL_INFO_ADDR + i );
    }
#ifdef __TIME_STAMP__
    
    for (i = 0; i < ((timestamp_size+3) >> 2); i++)
    {
       *((volatile unsigned long *)backup_addr + ((cpsz+3) >> 2) + i ) =  *((volatile unsigned long *)timestamp_addr + i );
    }
    
#endif    
    return KAL_TRUE;

#endif /* !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__)) */

}



/*************************************************************************
* FUNCTION
*  INT_RetrieveBLShareinfo
*
* DESCRIPTION
*  This function is used to retrieved bootloader / maui shared information 
*  from backed up region for runtime use
*
* PARAMETERS
*  none
*
* RETURNS
*  random seed
*
*************************************************************************/
kal_int32 INT_RetrieveBLShareinfo(kal_uint32 backup_addr)
{
#ifdef __TIME_STAMP__
    kal_uint32 timestamp_addr = 0;
    kal_uint32 timestamp_size = 0;
    
    TS_GetContext(&timestamp_addr, &timestamp_size);
#endif
    
#if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))    
  
    return KAL_TRUE;   
     
#else /* !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__)) */
       
    kal_mem_cpy((char *)&g_pass_info, (char *)((BL_Info_Wrapper_st*)(backup_addr)), sizeof(g_pass_info) );

#ifdef __TIME_STAMP__
    
    kal_mem_cpy((char *)timestamp_addr, (char *)backup_addr + sizeof(BL_Info_Wrapper_st), timestamp_size);
#endif    
    return KAL_TRUE;
    
#endif /* !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__)) */

        
}


/*************************************************************************
* FUNCTION
*  INT_GetBLShareToken
*
* DESCRIPTION
*  This function is used to get the share token passed from bootloader
*
* PARAMETERS
*  none
*
* RETURNS
*  random seed
*
*************************************************************************/
kal_int32 INT_GetBLShareToken(kal_uint32 *token_size, kal_uint32 buff_addr, kal_uint32 buff_len)
{

#if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))    

    return KAL_TRUE;     
     
#else /* !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__)) */
     
    *token_size = sizeof(((BL_MAUI_ShareData *)0)->m_bl_token);
    
    if (*token_size > buff_len)
    {
        return KAL_FALSE;
    }
    else
    {
        kal_mem_cpy((char *)buff_addr, (char *)&g_pass_info.m_bl_maui_share_data.m_bl_token[0], *token_size );
    }
    
    return KAL_TRUE;
#endif /* !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__))  */

}

/*************************************************************************
* FUNCTION
*  INT_GetMetaModeSrc
*
* DESCRIPTION
*  Get Random Seed
*
* PARAMETERS
*  none
*
* RETURNS
*  random seed
*
*************************************************************************/
MODE_ENTRY_SRC INT_GetMetaModeSrc(void)
{
    MODE_ENTRY_SRC state = E_BROM;


#if defined(__TOOL_ACCESS_CTRL__)

#if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))

#else /* !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__)) */
    if ( g_pass_info.m_bl_maui_share_data.m_bl_bootup_flag & BL_INFO_SUSBDL_IN_BL_ENABLED)    //S-USBDL
    {
        return E_BLSUSB;

    }
    else if( g_pass_info.m_bl_maui_share_data.m_bl_bootup_flag & BL_INFO_USBDL_IN_BL_CONNECTED   ) //N_USBDL
    {
        return E_BLNUSB;
    }
#endif /* !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__)) */
#endif /* __TOOL_ACCESS_CTRL__ */
    return state;
    


}

/*************************************************************************
* FUNCTION
*  INT_GetRandomSeed
*
* DESCRIPTION
*  Get Random Seed -- maybed passed from bootloader or use memory region
*  to create
*
* PARAMETERS
*  none
*
* RETURNS
*  random seed
*
*************************************************************************/
kal_int32 INT_GetRandomSeed(void)
{
#if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))
   kal_uint32 i;
#endif

   kal_uint32 seed;

#ifdef __TIME_STAMP__

#if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))
#if !defined(MT6270A)  //MT6270A without TDMA
   HW_wait_32k_start();
#endif 
#endif
    
   TS_Init(TRUE);

   TS_BEGIN(TSID_INIT_TOTAL);
   TS_BEGIN(TSID_INIT_READY_TO_DISPLAY);
   TS_BEGIN(TSID_INIT_ASM);

#endif
   
#if defined(_SIMULATION)

    /* no need to generate a real random number seed in co-sim */

   seed = 0;

#else   /* _SIMULATION */
#if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))
   /* generate a random number via reading internal SRAM or 32K-clock calibration */
   for (seed = 0, i = 0; i < (1024 / 4); i++) {
      /* XOR memory data */
      seed = seed ^ *((kal_uint32 *)RAND_GEN_START_ADDR + i);
   }

     
#else /* !(__BL_ENABLE__ || _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__) */


   ASSERT(((BL_Info_Wrapper_st*)(BL_INFO_ADDR))->m_bl_maui_share_data.m_bl_magic_head == BL_INFO_V1);
   seed = ((BL_Info_Wrapper_st*)(BL_INFO_ADDR))->m_bl_maui_share_data.m_bl_random_seed;


#endif /* !(__BL_ENABLE__ || _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__) */

#endif  /* _SIMULATION */

   /*
    * NoteXXX: Seed cannot be store in the global variable rand_num_seed directly.
    *          This is because that RW-data will be initialized later.
    *          Just return the seed.
    */

   return seed;   
}


/*************************************************************************
* FUNCTION
*  INT_IsBootForUSBAT
*
* DESCRIPTION
*  This function is used to for user to query if USBAT is enabled 
*
* PARAMETERS
*  none
*
* RETURNS
*  0
*
*************************************************************************/
kal_bool INT_IsBootForUSBAT(void)
{
    return _IsBootForUSBAT;    
}

/*************************************************************************
* FUNCTION
*  INT_GetBootloaderFlag
*
* DESCRIPTION
*  Get the flags passed by Bootloader from internal structures
*
* PARAMETERS
*  none
*
* RETURNS
*  Flag for the bootup information
*
*************************************************************************/
kal_uint32 INT_GetBootloaderFlag(void)
{
    
#if defined(__SV5_ENABLED__) /* __SV5_ENABLED__ */

   return (g_pass_info.m_bl_maui_share_data.m_bl_bootup_flag);

#else /* __SV5_ENABLED__ */
    
#if !(defined(__BL_ENABLE__) || defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__))    
   
   return 0; /* Nothing passed by bootloader */
   
#else /* !(__BL_ENABLE__ || _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__ || __EMMC_BOOTING__) */

   return (g_pass_info.m_bl_maui_share_data.m_bl_bootup_flag);
   
#endif /* _NAND_FLASH_BOOTING_ */

#endif /* __SV5_ENABLED__ */

}


/*************************************************************************
* FUNCTION
*  INT_IsPowerLatchedByBL
*
* DESCRIPTION
*  Bootloader may latch the power in some special cases. If it did so, this flag will
*  be raised to notify MAUI init module
*
* PARAMETERS
*  none
*
* RETURNS
*  If the power is latched by Bootloader
*
*************************************************************************/
kal_bool INT_IsPowerLatchedByBL(void)
{
   return (INT_GetBootloaderFlag() & BL_INFO_POWER_LATCHED) ? KAL_TRUE : KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*  INT_IsFirstPowerOnFromBL
*
* DESCRIPTION
*  For power-on sequence, it is necessary to know if it's the first boot up    
*  If this information is retrived by Bootloader, this flag will be raised
*
* PARAMETERS
*  Module that giving the information
*
* RETURNS
*  If it's the first time of power-on awared by Bootloader
*
*************************************************************************/
kal_bool INT_IsFirstPowerOnFromBL(BL_FIRST_PWON_INFO_SRC module)
{
   //Currently booltoader only get this information from RTC module
   ASSERT(module == BL_INFO_FROM_RTC);

   return (INT_GetBootloaderFlag() & BL_INFO_FIRST_POWER_ON) ? KAL_TRUE : KAL_FALSE;
}

#endif /*__FUE__*/
