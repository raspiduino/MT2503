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
 *  UcmKernel.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  UCM kernel source file
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "MMI_features.h"
#ifdef __MMI_UCM__

#include "CommonScreens.h"
#include "UCMGProt.h"
#include "UCMProt.h"
#include "UcmCoreProt.h"
#include "UcmSrvGProt.h"
#include "mmi_rp_app_ucm_def.h"
#include "mmi_rp_core_ucm_def.h"
#include "Gpiosrvgprot.h"
#include "ProfilesSrvGprot.h"
#include "mdi_datatype.h"
#include "mdi_audio.h" /* MMI_EVENT_SUCCESS. in which include custom_events_notify.h */
#include "CallSetSrvGprot.h"
#include "CallSetGprot.h"
#include "app_str.h" /* app_ucs2_itoa */
#ifdef __UM_SUPPORT__
#include "UMGProt.h" /* mmi_um_entry_main_message_menu_with_check */
#endif
#ifdef __MMI_VIDEO_TELEPHONY__
#include "FileMgrGProt.h"
#endif /* __MMI_VIDEO_TELEPHONY__ */
#if defined(__MMI_BT_SUPPORT__) && defined(__MMI_HFP_SUPPORT__)    
#include "conversions.h"  /* mmi_chset_utf8_to_ucs2_string */
#endif /* defined(__MMI_BT_SUPPORT__) && defined(__MMI_HFP_SUPPORT__) */
#ifdef __CTM_SUPPORT__
#include "CtmGProt.h" /* ctm */
#endif /* __CTM_SUPPORT__ */

#include "PhbCuiGprot.h"
#include "CalllogGprot.h"
//#ifdef __MMI_VIDEO_TELEPHONY__
#include "SmsAppGprot.h"
//#endif /* __MMI_VIDEO_TELEPHONY__ */
#include "SmsCuiGprot.h"
/*[UCM3.0] todo it's not good to use prot.h */
#include "PowerOnChargerProt.h" /* IS_LOW_BATTERY */  /* O */

#ifdef __MMI_BT_SUPPORT__
#include "BtcmSrvGprot.h"
#include "BTMMIScrGprots.h"  /* mmi_bt_connect_last_headset */
#endif /* __MMI_BT_SUPPORT__ */


#ifdef __MMI_BG_SOUND_EFFECT__
#include "BGSoundGProt.h"  /* mmi_bgsnd_util_stop_play_sound */
#include "mmi_rp_app_bgsound_def.h" /* MENU_ID_BGSND_CM_OPT_EFFECT */
#endif

#if defined(__MMI_VIDEO_PLAY_SUPPORT__)
#include "mdi_video.h"  /* mdi_video_ply_check_is_able_to_play */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */


#include "IdleGprot.h"
#ifdef __MMI_SOUND_RECORDER__
#include "SoundRecorderProt.h"
#endif

#ifdef __MMI_BG_SOUND_EFFECT__
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#endif
#endif /* __MMI_BG_SOUND_EFFECT__ */

#ifdef __MMI_VOIP__
#include "VoIPResDef.h"  /* IMG_ID_VOIP_CALL_EDITOR */
#endif

#ifdef __MMI_WLAN_FEATURES__
#include "NetworkSetupDefs.h" /* P_WLAN_ONLY */
#endif /* __MMI_WLAN_FEATURES__ */
#include "VolumeHandler.h" /* SetKeyPadVolUp */
#include "SatAppGprot.h"
#include "wgui_categories.h"

#ifdef __MMI_VIDEO_TELEPHONY__
#include "NwUsabSrvGprot.h"
#ifdef __DRM_SUPPORT__
#include "DRM_gprot.h"
#endif /* __DRM_SUPPORT__ */
#endif /* __DRM_SUPPORT__ */

#ifdef __MMI_VIDEO_TELEPHONY__
#include "UcmVtCallScrGProt.h"
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __DM_LAWMO_SUPPORT__
#include "DmSrvGprot.h"
#endif /* __DM_LAWMO_SUPPORT__ */

#include "Resource_audio.h"
#if defined(__MMI_UCM_REJECT_BY_SMS__) || defined(__MMI_VIDEO_TELEPHONY__)   
#include "SmsSrvGprot.h"
#endif /* __MMI_UCM_REJECT_BY_SMS__ || __MMI_VIDEO_TELEPHONY__ */
#include "NwInfoSrvGprot.h" /* srv_nw_info_get_protocol */
#ifdef __MMI_VIDEO_TELEPHONY__
#include "mmi_rp_app_callset_def.h"
#endif /* __MMI_VIDEO_TELEPHONY__ */

#include "Menucuigprot.h"
#if defined(__MMI_FILE_MANAGER__) && defined(__MMI_VIDEO_TELEPHONY__)
#include "FileMgrCuiGProt.h"
#endif /* __MMI_FILE_MANAGER__ */
#include "mmi_rp_menu_misc_def.h"
#include "MMIDataType.h"
#include "GlobalConstants.h"
#include "kal_general_types.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "wgui_categories_CM.h"
#include "custom_srv_prof_defs.h"
#include "custom_led_patterns.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "AlertScreen.h"
#include "mmi_frm_events_gprot.h"
#include "gui_data_types.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "mmi_res_range_def.h"
#include "mmi_frm_mem_gprot.h"
#include "PhbSrvGprot.h"
#include "custom_mmi_default_value.h"
#include "GlobalResDef.h"
#include "PhoneBookGprot.h"
#include "ps_public_enum.h"
#include "device.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "CustDataRes.h"
#include "custom_events_notify.h"
#include "kal_public_api.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_inputs.h"
#include "mmi_frm_gprot.h"
#include "CustMenuRes.h"
#include "wgui_categories_list.h"
#include "mmi_rp_app_uiframework_def.h"
#include "NetSetSrvGprot.h"
#include "NetSetAppGprot.h"
#include "wgui_categories_multimedia.h"
#include "mmi_rp_app_phonebook_def.h"
#include "mmi_rp_srv_phb_def.h"
#include "gui.h"
#include "wgui_touch_screen.h"
#include "wgui.h"
#include "wgui_categories_popup.h"
#include "wgui_fixed_menus.h"
#ifdef __MMI_VIDEO_TELEPHONY__
#include "UcmVtCallScrProt.h"
#endif /* __MMI_VIDEO_TELEPHONY__ */
#include "stdio.h"
#include "mmi_frm_nvram_gprot.h"
#include "FileMgrSrvGProt.h"
#include "mmi_rp_file_type_def.h"
#include "FileMgrType.h"
#include "fs_type.h"
#include "drm_def.h"
#include "fs_errcode.h"
#include "drm_errcode.h"
#include "gdi_const.h"
#include "gdi_include.h"
#ifdef MMS_SUPPORT
#include "mms_api.h"
#endif /* MMS_SUPPORT */
#include "CommonScreensResDef.h"
#include "SimCtrlSrvGprot.h"

#include "mmi_rp_app_mainmenu_def.h"

#ifdef __MMI_HFP_SUPPORT__ 
#include "BthfSrvGprot.h"
#endif /* __MMI_HFP_SUPPORT__ */

#if (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER)
#include "opera_api.h"  /* opera_brw_api_set_to_active_group */
#include "browser_api.h"
#endif /* (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER) */
#include "CharBatSrvGprot.h"

#if (MMI_MAX_SIM_NUM >= 2)
#include "SimSelCuiGprot.h"
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#include "SSCStringTable.h"
#include "MainMenuProt.h"
#ifdef __PXS_APP_ENABLE__
#include "SensorSrvGport.h"
#endif /* __PXS_APP_ENABLE__ */
#include "mmi_frm_utility_gprot.h"   /* For MMI_SIM_TOTAL & MMI_SIM_ALL */
#if defined(__AGPS_SUPPORT__) && defined(__SUPL_SUPPORT__)
#include "GPSMgrGProt.h"    /* mmi_gps_mgr_call_end() */
#endif /* defined(__AGPS_SUPPORT__) && defined(__SUPL_SUPPORT__) */
#include "SensorSrvGport.h"
#include "ScrLockerGprot.h"
#include "Vsrv_ncenter.h"
#include "Vapp_ncenter_gprot.h"
#include "DateTimeType.h"
#include "mmi_frm_app_launcher_gprot.h"
#include "mmi_frm_mem_gprot.h"
#ifdef __MMI_VUI_LAUNCHER_KEY__
#include "vapp_launcher_key_gprot.h"
#endif /* __MMI_VUI_LAUNCHER_KEY__ */
#ifdef __VOICE_CHANGER_SUPPORT__
#include "mmi_rp_app_callset_def.h"
#endif /* __VOICE_CHANGER_SUPPORT__ */

#ifdef __MMI_BT_CALL_SUPPORT__
#include "UcmBTSrvGprot.h"
#include "UcmGProtBT.h"
#endif /* __MMI_BT_CALL_SUPPORT__ */

#define MMI_UCM_DEFAULT_MOMT_IMAGE (IMG_PHB_DEFAULT)
/* [UCM3.0] it's not good , but no .h can include */
#ifdef __AOC_SUPPORT__

extern void reset_call_cost_UI(void);  /* O */
extern void show_call_cost_UI(PU8 symbol, PU8 value); /* O */
#endif 
#ifdef __MMI_BT_CALL_SUPPORT__
mmi_ucm_dial_from_bt_struct* g_dial_from_bt_para_p;
extern void mmi_ucm_end_and_accpet_confirm_bt(MMI_ID parent_id);
#endif /* __MMI_BT_CALL_SUPPORT__ */


/* ==================================================================================== */
/* =============Initialization========================================================= */
/* ==================================================================================== */

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_init_context
 * DESCRIPTION
 *  Initialize UCM app context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_init_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_ucm_p->call_misc.index_list, -1, (SRV_UCM_MAX_CALL * sizeof(srv_ucm_index_info_struct)));
    g_ucm_p->call_misc.is_dtmf = MMI_TRUE;
    g_ucm_p->call_misc.hilite_tab = -1;
    mmi_ucm_set_act_request_callback(mmi_ucm_act_callback);
#ifdef __GENERAL_TTS__
    mmi_ucm_set_tts_replay_query_callback(mmi_ucm_tts_replay_query_callback);
#endif /* __GENERAL_TTS__ */
}


/* ==================================================================================== */
/* =============Tone related=========================================================== */
/* ==================================================================================== */

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_incoming_tone
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_play_incoming_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_group;
    S32 incoming_call_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_CALL_SUPPORT__
    if (srv_ucm_bt_is_any_call())
    {
        mmi_ucm_play_waitingtone();
        return;
    }
#endif /* __MMI_BT_CALL_SUPPORT__ */
    /* just for print information */
    num_group = srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL);
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PLAY_INCOMING_TONE, g_ucm_p->call_misc.play_tone, num_group);
    
    incoming_call_count = srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL);
    if (incoming_call_count == 0)
    {
        return;
    }

    if (g_ucm_p->call_misc.play_tone == MMI_UCM_NONE)
    {
        if (g_ucm_p->call_misc.is_ringtone_suppress == MMI_TRUE)
        {
            return;
        }

        if (incoming_call_count == num_group)
        {
            g_ucm_p->call_misc.play_tone = MMI_UCM_RING_TONE;
            mmi_ucm_play_ringtone();
        }
        else
        {
            g_ucm_p->call_misc.play_tone = MMI_UCM_WAITING_TONE;
            mmi_ucm_play_waitingtone();
        }
    }
    else if (g_ucm_p->call_misc.play_tone == MMI_UCM_WAITING_TONE)
    {
        if (incoming_call_count == num_group)
        {
            g_ucm_p->call_misc.play_tone = MMI_UCM_RING_TONE;
            mmi_ucm_play_ringtone();
        }
		#ifndef __SLIM_UCM__
        else
        {
            /* do not replay waitingtone */
        }
		#endif
    }
	#ifndef __SLIM_UCM__
    else /* g_ucm_p->call_misc.play_tone == MMI_UCM_RING_TONE */
    {
        /* do not replay ringtone */
    }
    #endif

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_SET_TONE_FLAG_P2, g_ucm_p->call_misc.play_tone, 2);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_stop_incoming_tone
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_stop_incoming_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_STOP_INCOMING_TONE_P1, g_ucm_p->call_misc.play_tone);

    if (g_ucm_p->call_misc.play_tone == MMI_UCM_RING_TONE)
    {
        mmi_ucm_stop_ringtone();

    #ifdef __MMI_PHB_CALLER_VIDEO__
        g_ucm_p->call_misc.is_ring_after_vibra = MMI_FALSE;

        if ((srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) == srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL)) && 
            (g_ucm_p->full_mo_mt_display.res_type != SRV_UCM_RES_TYPE_IMAGE_ID) && (g_ucm_p->full_mo_mt_display.res_type != SRV_UCM_RES_TYPE_IMAGE_PATH))
        {
            StopCategory17Video();
        }
    #endif /* __MMI_PHB_CALLER_VIDEO__ */
    }
    else if ( g_ucm_p->call_misc.play_tone == MMI_UCM_WAITING_TONE)
    {
        /* waiting tone */
        mmi_ucm_stop_waitingtone();
    }

    g_ucm_p->call_misc.play_tone = MMI_UCM_NONE;
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_SET_TONE_FLAG_P2, g_ucm_p->call_misc.play_tone, 3);
    
}


/* because of EnableCategory17Audio in mmi_ucm_play_tone_after_vibration */
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_ring_tone
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_play_ringtone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_CALLER_VIDEO__
    MMI_BOOL is_video_sound = MMI_FALSE;
#endif /* __MMI_PHB_CALLER_VIDEO__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_CALL_SUPPORT__
    if (srv_ucm_bt_is_any_call())
    {
        return;
    }
#endif
#ifdef __MMI_PHB_CALLER_VIDEO__
    is_video_sound = mmi_ucm_is_caller_video_sound();
    if (wgui_cat017_is_media_played() == MMI_FALSE)
    {
        is_video_sound = MMI_FALSE;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PLAY_RINGTONE_P2, is_video_sound, g_ucm_p->full_mo_mt_display.mo_mt_display.alert_type);
#endif /* __MMI_PHB_CALLER_VIDEO__ */

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PLAY_RINGTONE_P2, 0, g_ucm_p->full_mo_mt_display.mo_mt_display.alert_type);

    switch (g_ucm_p->full_mo_mt_display.mo_mt_display.alert_type)
    {
    #ifdef __MMI_PHB_CALLER_VIDEO__
        case SRV_PROF_ALERT_TYPE_RING:
            if (is_video_sound == MMI_FALSE)
            {
                mmi_ucm_play_tone_with_text();
            }
            break;

        case SRV_PROF_ALERT_TYPE_VIB_AND_RING:
            srv_vibrator_on();
            if (is_video_sound == MMI_FALSE)
            {
                mmi_ucm_play_tone_with_text();
            }
            break;
    #else /* __MMI_PHB_CALLER_VIDEO__ */

        case SRV_PROF_ALERT_TYPE_RING:
            mmi_ucm_play_tone_with_text();
            break;

        case SRV_PROF_ALERT_TYPE_VIB_AND_RING:
            srv_vibrator_on();
            mmi_ucm_play_tone_with_text();
            break;    
    #endif /* __MMI_PHB_CALLER_VIDEO__ */
    
        case SRV_PROF_ALERT_TYPE_VIB_ONLY:
            srv_vibrator_on(); /* O */
            break;

        case SRV_PROF_ALERT_TYPE_VIB_THEN_RING:
            srv_vibrator_on(); /* O */
            StartTimer(CM_ALERT_NOTIFYDURATION_TIMER, MMI_UCM_VIB_THEN_RING_DURATION, mmi_ucm_play_tone_after_vibration);
            break;
        case SRV_PROF_ALERT_TYPE_SILENT:
        case SRV_PROF_ALERT_TYPE_INVALID:
            break;
        default: /* set default as MMI_RING */
            mmi_ucm_play_tone_with_text();
            break;
    }
    srv_led_pattern_start_caller_group(g_ucm_p->full_mo_mt_display.mo_mt_display.light_id); /* O */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_stop_ring_tone
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_stop_ringtone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_STOP_RINGTONE_P2, 0, g_ucm_p->full_mo_mt_display.mo_mt_display.alert_type);
    switch (g_ucm_p->full_mo_mt_display.mo_mt_display.alert_type)
    {
        case SRV_PROF_ALERT_TYPE_RING:
        {
            srv_prof_stop_tone(SRV_PROF_TONE_INCOMING_CALL);     
        }
        break;
            
        case SRV_PROF_ALERT_TYPE_VIB_ONLY:
        {
            srv_vibrator_off();
        }
        break;
            
        case SRV_PROF_ALERT_TYPE_VIB_AND_RING:
        {

            srv_prof_stop_tone(SRV_PROF_TONE_INCOMING_CALL);     
            srv_vibrator_off();
        }    
        break;
            
        case SRV_PROF_ALERT_TYPE_VIB_THEN_RING:
        {
            /* NSC Does not make the mobile go back into Silent Mode */
            StopTimer(CM_ALERT_NOTIFYDURATION_TIMER);
            srv_prof_stop_tone(SRV_PROF_TONE_INCOMING_CALL);     
            srv_vibrator_off();
        }
        break;
        
        case SRV_PROF_ALERT_TYPE_SILENT:
        case SRV_PROF_ALERT_TYPE_INVALID:
        {

        }
        break;

        default: /* set default as MMI_RING */
        {
            srv_prof_stop_tone(SRV_PROF_TONE_INCOMING_CALL);     
        }
        break;
    }

#ifdef __GENERAL_TTS__
    mmi_ucm_free_speechText();
#endif /* __GENERAL_TTS__ */

    srv_led_pattern_stop_caller_group(g_ucm_p->full_mo_mt_display.mo_mt_display.light_id); /* O */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_tone_after_vibration
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_play_tone_after_vibration(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_CALLER_VIDEO__
    MMI_BOOL is_video_sound = mmi_ucm_is_caller_video_sound();
#endif /* __MMI_PHB_CALLER_VIDEO__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(CM_ALERT_NOTIFYDURATION_TIMER);
    srv_vibrator_off(); /* O */

#ifdef __MMI_PHB_CALLER_VIDEO__
    if (is_video_sound)
    {
        if (SCR_ID_UCM_INCOMING == mmi_frm_scrn_get_active_id())
        {   
            /* category can play the video */
            if (MMI_TRUE == wgui_cat017_is_media_played())
            {
                /* turn on audio path */
                EnableCategory17Audio();
            }
            else /* category can not play the video, so play ring tone here */
            {
                mmi_ucm_play_tone_with_text();
            }
        }
        /* If user is in other screen, ex incoming_option screen, vibration timeout=> silence. when
           back to incoming screen, continue playing video sound */
        
        /* The flag will decide if the tone should be play immediate when enter incoming call scr */
        g_ucm_p->call_misc.is_ring_after_vibra = MMI_TRUE;
    }
    else
#endif /* __MMI_PHB_CALLER_VIDEO__ */
    {
        mmi_ucm_play_tone_with_text();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_suppress_incoming_tone
 * DESCRIPTION
 *  Suppress incoming tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_suppress_incoming_tone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_SUPPRESS_INCOMING_TONE_P1, g_ucm_p->full_mo_mt_display.mo_mt_display.alert_type);

    if(g_ucm_p->call_misc.is_ringtone_suppress == MMI_TRUE)
    {
        /* Already suppressed */
        return;
    }
    
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL,  NULL) != 1)
    {
        return;
    }

    g_ucm_p->call_misc.play_tone = MMI_UCM_NONE;
    g_ucm_p->call_misc.is_ringtone_suppress = MMI_TRUE;
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_SET_TONE_FLAG_P2, g_ucm_p->call_misc.play_tone, 1);
    
    switch (g_ucm_p->full_mo_mt_display.mo_mt_display.alert_type)
    {            
        case SRV_PROF_ALERT_TYPE_RING:
        case SRV_PROF_ALERT_TYPE_VIB_AND_RING:
            srv_prof_stop_tone(SRV_PROF_TONE_INCOMING_CALL);            
            srv_vibrator_off();
            break;

        case SRV_PROF_ALERT_TYPE_VIB_THEN_RING:
            StopTimer(CM_ALERT_NOTIFYDURATION_TIMER);
            srv_prof_stop_tone(SRV_PROF_TONE_INCOMING_CALL);
            srv_vibrator_off();
            break;

        case SRV_PROF_ALERT_TYPE_VIB_ONLY:
            srv_vibrator_off();
            break;
#ifndef __SLIM_UCM__

        case SRV_PROF_ALERT_TYPE_SILENT:
            break;
        case SRV_PROF_ALERT_TYPE_INVALID:
            break;
#endif
        default: /* set default as MMI_RING */
            srv_prof_stop_tone(SRV_PROF_TONE_INCOMING_CALL);     
            srv_vibrator_off();
            break;
    }

#ifdef __MMI_PHB_CALLER_VIDEO__
    /* Stop caller video sound */
    if ((srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) == srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE,NULL)) && 
        (g_ucm_p->full_mo_mt_display.res_type == SRV_UCM_RES_TYPE_VIDEO_ID || g_ucm_p->full_mo_mt_display.res_type == SRV_UCM_RES_TYPE_VIDEO_PATH) )
    {
        mdi_audio_set_mute(MDI_VOLUME_MEDIA, MMI_TRUE);
    }
#endif /* __MMI_PHB_CALLER_VIDEO__ */

    srv_led_pattern_stop_caller_group(g_ucm_p->full_mo_mt_display.mo_mt_display.light_id);
}


#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_delay_play_incoming_tone_hdlr
 * DESCRIPTION
 *  Dedlay play incoming tone handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_delay_play_incoming_tone_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_play_incoming_tone();
    StopTimer(TIMER_ID_UCM_DELAY_RING);
}
#endif /* __MMI_FTE_SUPPORT__ */


#ifdef __GENERAL_TTS__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_tts_replay_query_callback
 * DESCRIPTION
 *  TTS replay query callback
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_UCM_TTS_REPLAY_QUERY_NO if the tone is stopped; 
 *  otherwise, return MMI_UCM_TTS_REPLAY_QUERY_YES
 *****************************************************************************/
mmi_ucm_tts_replay_query_result_enum mmi_ucm_tts_replay_query_callback(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_UCM_NONE == g_ucm_p->call_misc.play_tone)
    {
        return MMI_UCM_TTS_REPLAY_QUERY_NO;
    }
    else
    {
        return MMI_UCM_TTS_REPLAY_QUERY_YES;
    }
}
#endif /* __GENERAL_TTS__ */


/* ==================================================================================== */
/* =============ind/act/cnf ind hdlr=================================================== */
/* ==================================================================================== */

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_handle_disconnecting_ind
 * DESCRIPTION
 *  Handler for disconnecting ind
 * PARAMETERS
 *  disconnecting_ind      [IN]            disconnecting ind structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_handle_disconnecting_ind(srv_ucm_disconnecting_ind_struct *disconnecting_ind)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    MMI_ID curr_act_sg_id = mmi_frm_group_get_active_id();
    
    srv_ucm_act_opcode_enum curr_act = srv_ucm_query_curr_action();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if remote disconnecting, does not display grey screen */
    if ((SRV_UCM_END_SINGLE_ACT != curr_act) &&
        (SRV_UCM_END_CONFERENCE_ACT != curr_act) 
         && (SRV_UCM_END_ALL_AND_ACCEPT_ACT != curr_act)
         && (SRV_UCM_END_ALL_ACTIVE_AND_ACCEPT_ACT != curr_act)
         && (SRV_UCM_END_ALL_AND_DIAL_ACT != curr_act) 
         && (SRV_UCM_END_ALL_ACT != curr_act) 
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__   
        && (SRV_UCM_END_ALL_ACTIVE_ACT != curr_act)
#endif
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
        && (SRV_UCM_END_ALL_HELD_ACT != curr_act) 
#endif
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE_AND_RETRIEVE__           
        && (SRV_UCM_END_ALL_ACTIVE_AND_RETRIEVE_ACT != curr_act)       
#endif
		)
    {
        return;
    }

    /* because some network has 40s period between disconnecting and rel ind for MO case, 
       if use grey screen, user will feel hang there */
    if((GRP_ID_UCM_MO != curr_act_sg_id) &&
       (GRP_ID_UCM_MT != curr_act_sg_id))
    {
        mmi_ucm_entry_disconnecting_screen();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_connect_ind
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_connect_ind(srv_ucm_connect_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) && defined(__MMI_VIDEO_TELEPHONY__)
    MMI_BOOL keep_vt_setting = MMI_FALSE;
#endif /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) && defined(__MMI_VIDEO_TELEPHONY__) */    

#ifdef __MMI_CH_QUICK_END__
    U16 quickEndDuration = srv_callset_auto_quick_end_get_time();
#endif /* __MMI_CH_QUICK_END__ */

#if !defined(__MMI_BACKGROUND_CALL__) || defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
    MMI_ID scrn_id;
#endif /* !defined(__MMI_BACKGROUND_CALL__) || defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_ucm_stop_inband_tone();

#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
    if (mmi_scr_locker_get_type() != MMI_SCR_LOCKER_TYPE_LAWMO)
    {
	    mmi_scr_locker_close();
    }
#endif /* __MMI_SCREEN_LOCK_ANY_TIME__ */

#ifdef __MMI_CH_QUICK_END__
    if (IsMyTimerExist(CM_AUTO_QUICK_END_TIMER) == MMI_FALSE &&
        quickEndDuration > 0 && 
        srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 &&
        srv_ucm_is_emergency_call() == MMI_FALSE)
        {    
            StartTimer(CM_AUTO_QUICK_END_TIMER, (quickEndDuration * 1000), mmi_ucm_auto_quick_end);
        }
#endif /* __MMI_CH_QUICK_END__ */

    /* Start CTR timer if it hasn't started yet */
#ifdef __MMI_CALLSET_CALLTIME_REMINDER__

    mmi_ucm_call_time_reminder_hdlr();
#endif

#ifdef __MMI_DUAL_MIC_SUPPORT__
    mdi_audio_set_dual_mic_nr(mmi_ucm_get_dual_mic_nr_status());
#endif /* __MMI_DUAL_MIC_SUPPORT__ */

#ifdef MOTION_SENSOR_SUPPORT
#if defined(__MMI_SOUND_RECORDER__) && defined(__MOTION_SENSOR_ADVANCED_GESTURE__)
    mmi_ucm_motion_double_tap_reg();
#endif /* defined(__MMI_SOUND_RECORDER__) && defined(__MOTION_SENSOR_ADVANCED_GESTURE__) */
#endif /* MOTION_SENSOR_SUPPORT */

    mmi_frm_group_close(GRP_ID_UCM_MO);
#if defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
    if (srv_ucm_query_app_exit() == MMI_TRUE)
    {
        /*Keep user's modification in preview mode - because if the vt preview screen is delete in DeleteUptoScrID, the vt del callback will reset mode to MMI_UCM_VT_INCALL_SCREEN_MODE_NONE */
    #ifdef __MMI_VIDEO_TELEPHONY__
        if (MMI_UCM_VT_INCALL_SCREEN_MODE_PREVIEW_ONLY == mmi_ucm_vt_get_incall_screen_mode())
        {
            keep_vt_setting = MMI_TRUE;                
        }
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        mmi_ucm_delete_up_to_sg_id(GRP_ID_UCM_MARKER, MMI_FALSE, MMI_TRUE);
    #ifdef __MMI_VIDEO_TELEPHONY__
        if (MMI_TRUE == keep_vt_setting && 
            (ind->uid_info.call_type & SRV_UCM_VIDEO_CALL_TYPE_ALL))
        {
            mmi_ucm_vt_set_incall_screen_mode(MMI_UCM_VT_INCALL_SCREEN_MODE_PREVIEW_ONLY);    
        }
    #endif /* __MMI_VIDEO_TELEPHONY__ */   
    }
#endif /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */

#ifdef __MMI_VIDEO_TELEPHONY__
    if ((ind->uid_info.call_type & SRV_UCM_VIDEO_CALL_TYPE_ALL) &&
        (MMI_UCM_VT_INCALL_SCREEN_MODE_NONE == mmi_ucm_vt_get_incall_screen_mode()))
    {
        if (MMI_UCM_VT_DIAL_MODE_STOP_CAMERA == mmi_ucm_vt_get_dial_mode())
        {
            mmi_ucm_vt_set_camera_status(MMI_FALSE);
        }
        else
        {
            mmi_ucm_vt_set_camera_status(MMI_TRUE);
        }        
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __MMI_BACKGROUND_CALL_WITH_NCENTER__
    if (mmi_frm_group_get_state(GRP_ID_UCM_MARKER) & MMI_SCENARIO_STATE_HIDE)
    {
        mmi_frm_group_unhide(GRP_ID_UCM_MARKER);
        mmi_frm_group_unhide(GRP_ID_UCM_INCALL);
    }
#endif /* __MMI_BACKGROUND_CALL_WITH_NCENTER__ */

    /* Get incall screen to active */
#if !defined(__MMI_BACKGROUND_CALL__) || defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
    if (mmi_frm_scrn_is_present(GRP_ID_UCM_INCALL, SCR_ID_UCM_IN_CALL, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG) &&
        srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, MMI_UCM_CALL_TYPE_FOR_SOLE_EXISTENCE, NULL) == 0 &&
        MMI_FALSE == srv_ucm_is_pending_action())
    {
        mmi_frm_set_active_group(GRP_ID_UCM_MARKER);
        mmi_frm_set_active_group(GRP_ID_UCM_INCALL);
        scrn_id = mmi_frm_scrn_get_neighbor_id(GRP_ID_UCM_INCALL, SCR_ID_INVALID, MMI_FRM_NODE_AT_LATEST_FLAG);
        mmi_frm_scrn_multiple_close(GRP_ID_UCM_INCALL, scrn_id, MMI_TRUE, 0, SCR_ID_UCM_IN_CALL, MMI_FALSE);   
        mmi_frm_group_close(GRP_ID_UCM_CONFIRM);
    }
#endif /* !defined(__MMI_BACKGROUND_CALL__) || defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */

    mmi_ucm_go_back_screen_check();

    /* switch VT<-> voice , don't want to delete other app */
#ifdef __MMI_VIDEO_TELEPHONY__
    mmi_ucm_vt_set_is_switch_action(MMI_FALSE);
    mmi_ucm_vt_set_switch_call_type(SRV_UCM_CALL_TYPE_END_OF_ENUM);
#endif /* __MMI_VIDEO_TELEPHONY__ */

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 1)
    {
    #ifdef __MMI_CONNECT_NOTICE__
        /* play connect notice according to user defined style */
        mmi_ucm_play_connect_notice_with_vib();
    #endif /* __MMI_CONNECT_NOTICE__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_notify_ind
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_notify_ind(srv_ucm_notify_ind_struct *notify_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct popup_property;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    
    mmi_popup_property_init(&popup_property);
    popup_property.duration = (U32)UI_POPUP_NOTIFYDURATION_TIME;
    popup_property.tone_id = (srv_prof_tone_enum) notify_ind->tone_id;
    popup_property.msg_icon = notify_ind->image_id;
    mmi_popup_display((WCHAR*)((UI_string_type) notify_ind->disp_msg), MMI_EVENT_INFO, &popup_property);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_handle_incoming_call_ind
 * DESCRIPTION
 *  Handler for incoming call ind
 * PARAMETERS
 *  incoming_ind      [IN]            incoming call ind structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_handle_incoming_call_ind(srv_ucm_incoming_call_ind_struct *incoming_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CM_WHITE_LIST__) || defined(__MMI_FTE_SUPPORT__)
    U8 ucs2Number[(SRV_UCM_MAX_NUM_URI_LEN + 1) * ENCODING_LENGTH];
#endif /* defined(__MMI_CM_WHITE_LIST__) || defined(__MMI_FTE_SUPPORT__) */

    srv_callset_answer_mode_enum ans_mode_status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_HANDLE_INCOMING_CALL_IND);

#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    mmi_frm_scrn_close(GRP_ID_UCM_MO_FAIL_POST_ACTION, SCR_ID_UCM_VT_FALLTO_VOICE_NOTIFY);
#endif /* defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__) */

#if defined(__MMI_CM_WHITE_LIST__) || defined(__MMI_FTE_SUPPORT__)
    memset(ucs2Number, 0, (SRV_UCM_MAX_NUM_URI_LEN + 1) * ENCODING_LENGTH);
    mmi_asc_to_ucs2((CHAR*)ucs2Number, (CHAR*)incoming_ind->remote_info.num_uri);
#endif /* defined(__MMI_CM_WHITE_LIST__) || defined(__MMI_FTE_SUPPORT__) */

#ifdef __MMI_FTE_SUPPORT__
    if (MMI_FALSE == srv_phb_check_number_exist((U16*)ucs2Number))
    {
        StartTimer(TIMER_ID_UCM_DELAY_RING, 2000, mmi_ucm_delay_play_incoming_tone_hdlr);
    }
#endif /* __MMI_FTE_SUPPORT__ */

#ifdef __PXS_APP_ENABLE__
    if (MMI_FALSE == g_ucm_p->pxs_turn_on)
    {
        srv_sensor_pxs_turn_on();
        g_ucm_p->pxs_turn_on = MMI_TRUE;
    }
#endif /* __PXS_APP_ENABLE__ */

#ifdef MOTION_SENSOR_SUPPORT
    mmi_ucm_motion_turnover_reg();
#endif /* MOTION_SENSOR_SUPPORT */

    memcpy(&g_ucm_p->full_mo_mt_display.mo_mt_display, &incoming_ind->display_info, sizeof(srv_ucm_display_info_struct));

/* Use line icon compile option */
#ifndef __MMI_UCM_SLIM__
    g_ucm_p->full_mo_mt_display.line_icon = incoming_ind->remote_info.line_icon;
#endif /* __MMI_UCM_SLIM__ */

#ifdef __MMI_UCM_NUMBER_TYPE__
    g_ucm_p->full_mo_mt_display.num_type_icon = incoming_ind->remote_info.num_type_icon;
#endif /* __MMI_UCM_NUMBER_TYPE__ */
    
    /* go back to incoming screen with updated information */
    mmi_ucm_enter_incoming_call();

#ifdef __BT_SPK_VOL_CONTROL__
    /* do not register vol control callback for csd/data call */
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_DATA_CSD, NULL) == 1) 
    {

        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_RING_IND_VOL_CONTROL_START);
        mdi_audio_bt_register_volume_sync_callback(APP_UCM, MDI_AUD_VOL_LEVEL_NORMAL_MUTE, mmi_ucm_volume_control_callback);

    }
#endif /* __BT_SPK_VOL_CONTROL__ */

    /* auto answer is only applicable to the first incoming call */
    ans_mode_status = srv_callset_answer_mode_get_status();

    if (((ans_mode_status & SRV_CALLSET_ANSWER_MODE_AUTO) && (srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) == 1)) ||
#ifdef __MMI_CM_WHITE_LIST__
    (srv_callset_whitelist_is_auto_answer_number((U8)mmi_ucs2strlen((CHAR*)ucs2Number), (WCHAR*)ucs2Number, NULL) == MMI_TRUE) ||
#endif /* __MMI_CM_WHITE_LIST__ */
    MMI_FALSE)
    {
        StartTimer(UCM_AUTO_ANSWER_TIMER, UI_POPUP_NOTIFYDURATION_TIME_2000, mmi_ucm_auto_answer_action);
    }

#ifdef __MMI_BG_SOUND_EFFECT__
    /* cancel bgs selection if necessary */
    if (mmi_frm_scrn_is_present(GRP_ID_UCM_PRE_MO, SCR_ID_UCM_BGS_EFFECT_SELECT, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_PRE_MO, SCR_ID_UCM_BGS_EFFECT_SELECT, (mmi_proc_func) NULL);
        mmi_ucm_exit_bgs_effect_select();
    }

    if (mmi_frm_scrn_is_present(GRP_ID_UCM_MT, SCR_ID_UCM_BGS_EFFECT_SELECT, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_MT, SCR_ID_UCM_BGS_EFFECT_SELECT, (mmi_proc_func) NULL);
        mmi_ucm_exit_bgs_effect_select();
    }
#endif /* __MMI_BG_SOUND_EFFECT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_handle_outgoing_call_ind
 * DESCRIPTION
 *  Handler for outgoing call ind
 * PARAMETERS
 *  outgoing_ind      [IN]            outgoing call ind structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_handle_outgoing_call_ind(srv_ucm_outgoing_call_ind_struct* outgoing_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    memcpy(&g_ucm_p->full_mo_mt_display.mo_mt_display, &outgoing_ind->display_info, sizeof(srv_ucm_display_info_struct));
/* Use line icon compile option */
#ifndef __MMI_UCM_SLIM__
    g_ucm_p->full_mo_mt_display.line_icon = outgoing_ind->remote_info.line_icon;
#endif /* __MMI_UCM_SLIM__ */
#ifdef __MMI_UCM_NUMBER_TYPE__
    g_ucm_p->full_mo_mt_display.num_type_icon = outgoing_ind->remote_info.num_type_icon;
#endif /* __MMI_UCM_NUMBER_TYPE__ */
    mmi_ucm_go_back_screen_check();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_alert_ind
 * DESCRIPTION
 *  Handler for alert ind
 * PARAMETERS
 *  alert_ind      [IN]            alert indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_alert_ind(srv_ucm_alert_ind_struct *alert_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alert_ind->local_gen == TRUE)
    {
        mmi_ucm_play_inband_tone();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_refresh_ind
 * DESCRIPTION
 *  Handler for refresh ind
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_refresh_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id scrn_id = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SCR_ID_UCM_IN_CALL != scrn_id && 
        SCR_ID_UCM_OUTGOING != scrn_id &&
        SCR_ID_UCM_INCOMING != scrn_id &&
    #ifdef __MMI_VIDEO_TELEPHONY__
        SCR_ID_UCM_VT_INCALL != scrn_id &&
    #endif /* __MMI_VIDEO_TELEPHONY__ */    
        MMI_TRUE)
    {
        return;    
    }
    
    /* Because all of these SGs do not use samrt close , we 
       can remove this Screen without considering if the SG 
       will be deleted in no screen case */
    /* re-display screen without change the SG position */   

    switch (scrn_id)
    {
        case SCR_ID_UCM_IN_CALL:
        {
            mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_INCALL, SCR_ID_UCM_IN_CALL, (mmi_proc_func) NULL);
            mmi_ucm_enter_in_call();
        }
        break;

        case SCR_ID_UCM_OUTGOING:
        {
            mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_MO, SCR_ID_UCM_OUTGOING, (mmi_proc_func) NULL);
            mmi_ucm_enter_outgoing_call();
        }
        break;       

        case SCR_ID_UCM_INCOMING:
        {
            mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_MT, SCR_ID_UCM_INCOMING, (mmi_proc_func) NULL);
            mmi_ucm_enter_incoming_call();
        }
        break;  
        
    #ifdef __MMI_VIDEO_TELEPHONY__
        case SCR_ID_UCM_VT_INCALL:
        {
            if (MMI_UCM_VT_INCALL_SCREEN_MODE_INCALL == mmi_ucm_vt_get_incall_screen_mode())
            {
                mmi_frm_scrn_close(GRP_ID_UCM_VT, scrn_id);   
                mmi_ucm_vt_enter_in_call();
            }
        }
        break;  
    #endif /* __MMI_VIDEO_TELEPHONY__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_release_ind
 * DESCRIPTION
 *  Handler for release ind
 * PARAMETERS
 *  ind      [IN]            release indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_release_ind(srv_ucm_release_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_answer_mode_enum ans_mode_status;
    
    mmi_ucm_call_end_struct *call_end_p = OslMalloc(sizeof(mmi_ucm_call_end_struct)); /* free mem when screen deinit */
#if (defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__) || defined (__MMI_VIDEO_TELEPHONY__) || defined(__MMI_UCM_MO_FAIL_POST_ACTION__)) 
    U8 ucs2_number[(SRV_UCM_MAX_NUM_URI_LEN + 1) * ENCODING_LENGTH];
#endif /* (defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__)||defined (__MMI_VIDEO_TELEPHONY__)||defined(__MMI_UCM_MO_FAIL_POST_ACTION__)) */
#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__    
    srv_phb_contact_data_struct *phb_data = NULL;
#endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */

    U16 *call_end_message = OslMalloc(sizeof(U16) * (SRV_UCM_MAX_ERR_MSG_LEN + 1)); /* free mem when screen deinit */
#ifdef __MMI_UCM_DISPLAY_NAME_ON_CALL_END__
    U8 newline[4] = { '\n', '\0', '\0', '\0' }; /* \n */
    U8 dots[6] = { '.', '\0', '.', '\0', '\0', '\0' }; /* .. */
#endif /* __MMI_UCM_DISPLAY_NAME_ON_CALL_END__ */
#ifdef __MMI_UCM_REJECT_BY_SMS__
    MMI_BOOL rej_by_sms = MMI_FALSE;
#endif /* __MMI_UCM_REJECT_BY_SMS__*/
#ifdef __MMI_BACKGROUND_CALL_WITH_NCENTER__
    srv_ucm_call_type_enum incall_type = (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_VOIP_CALL_TYPE | SRV_UCM_DATA_CALL_TYPE_ALL);
#endif /* __MMI_BACKGROUND_CALL_WITH_NCENTER__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_RELEASE_IND_CALL_INFO_P6, ind->uid_info.group_id, ind->uid_info.call_id, 
    ind->post_action.action, ind->post_action.is_ip_dial, ind->call_duration.nMin, ind->call_duration.nSec);    

    /* Stop inband tone and incoming tone */
    mmi_ucm_stop_inband_tone();
    mmi_ucm_stop_incoming_tone();
#ifdef __PXS_APP_ENABLE__
    if (MMI_TRUE == g_ucm_p->pxs_turn_on && srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
    {
        srv_sensor_pxs_turn_off();
        g_ucm_p->pxs_turn_on = MMI_FALSE;
        g_ucm_p->pxs_need_handle = MMI_FALSE;
    }
#endif /* __PXS_APP_ENABLE__ */

#ifdef MOTION_SENSOR_SUPPORT
    mmi_ucm_motion_turnover_dereg();
#if defined(__MMI_SOUND_RECORDER__) && defined(__MOTION_SENSOR_ADVANCED_GESTURE__)
    mmi_ucm_motion_double_tap_dereg();
#endif /* defined(__MMI_SOUND_RECORDER__) && defined(__MOTION_SENSOR_ADVANCED_GESTURE__) */
#endif /* MOTION_SENSOR_SUPPORT */

    g_ucm_p->call_misc.is_ringtone_suppress = MMI_FALSE;
    /* Stop auto answer timer */
    ans_mode_status = srv_callset_answer_mode_get_status();
  
    if (ans_mode_status & SRV_CALLSET_ANSWER_MODE_AUTO)
    {
        StopTimer(UCM_AUTO_ANSWER_TIMER);
    }

    /* switch VT<-> voice , don't want to delete other app */
#ifdef __MMI_VIDEO_TELEPHONY__
    if (ind->uid_info.call_type == mmi_ucm_vt_get_switch_call_type())
    {
        mmi_ucm_vt_set_is_switch_action(MMI_FALSE);
        mmi_ucm_vt_set_switch_call_type(SRV_UCM_CALL_TYPE_END_OF_ENUM);
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */    
#ifdef __MMI_CLAMSHELL__
    g_ucm_p->call_misc.trigger_by_clam_close = MMI_FALSE;
#endif /* __MMI_CLAMSHELL__ */
    /* get information for end popup */
    memcpy(&(call_end_p->call_duration), &(ind->call_duration), sizeof(MYTIME));
#if defined(__OP01__) && !defined(__OP01_FWPBW__)
    memcpy(&(call_end_p->start_time), &(ind->start_time), sizeof(MYTIME));
#endif /* defined(__OP01__) && !defined(__OP01_FWPBW__) */
    
#ifdef __MMI_UCM_DISPLAY_NAME_ON_CALL_END__
#if defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)
    if ((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0) &&
        (MMI_TRUE == ind->post_action.action) &&
        (MMI_TRUE == mmi_ucm_check_post_action_about_sim(ind->uid_info.call_type, ind->remote_info.num_uri)) &&
        (ind->uid_info.call_type & SRV_UCM_VIDEO_CALL_TYPE_ALL) &&
        (SRV_UCM_RESULT_VT_FALLBACK == ind->call_end_error_cause))
    {
        mmi_ucs2ncpy((CHAR*)call_end_message, (CHAR*)GetString(STR_ID_UCM_VT_FALL_TO_VOICE_END_CAUSE), MMI_UCM_END_TEXT_LEN);
    }
    else
#endif /* defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__) */
    {
        mmi_ucs2ncpy((CHAR*)call_end_message, (CHAR*) ind->call_end_msg, MMI_UCM_END_TEXT_LEN);
    }

    if ((MMI_UCM_END_TEXT_LEN - mmi_ucs2strlen((CHAR*)call_end_message)) >
        (mmi_ucs2strlen((CHAR*)newline) + mmi_ucs2strlen((CHAR*)dots) + MMI_UCM_END_NAME_LEN))
    {
        /* new line */
        mmi_ucs2ncat((CHAR*)call_end_message, (CHAR*)newline, mmi_ucs2strlen((CHAR*)newline));

        /* display name */
        mmi_ucs2ncat((CHAR*)call_end_message, 
        	(CHAR*)ind->remote_info.disp_name,
            MMI_UCM_END_NAME_LEN);

        /* Add dots symbol if name is too long*/
        if (mmi_ucs2strlen((CHAR*)ind->remote_info.disp_name) > MMI_UCM_END_NAME_LEN)
        {
            mmi_ucs2ncat((CHAR*)call_end_message, (CHAR*)dots, mmi_ucs2strlen((CHAR*)dots));
        }
    }     
#else /* __MMI_UCM_DISPLAY_NAME_ON_CALL_END__ */
#if defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)
    if ((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0) &&
        (MMI_TRUE == ind->post_action.action) &&
        (MMI_TRUE == mmi_ucm_check_post_action_about_sim(ind->uid_info.call_type, ind->remote_info.num_uri)) &&
        (ind->uid_info.call_type & SRV_UCM_VIDEO_CALL_TYPE_ALL) &&
        (SRV_UCM_RESULT_VT_FALLBACK == ind->call_end_error_cause))
    {
        mmi_ucs2ncpy((CHAR*)call_end_message, (CHAR*)GetString(STR_ID_UCM_VT_FALL_TO_VOICE_END_CAUSE), SRV_UCM_MAX_ERR_MSG_LEN);
    }
    else
#endif /* defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__) */
    {
        mmi_ucs2ncpy((CHAR*)call_end_message, (CHAR*) ind->call_end_msg, SRV_UCM_MAX_ERR_MSG_LEN);
    }
#endif /* __MMI_UCM_DISPLAY_NAME_ON_CALL_END__ */

    call_end_p->disp_msg = call_end_message;
    call_end_p->image_id = ind->call_end_image_id;
    call_end_p->tone_id = ind->call_end_tone_id;
    g_ucm_p->call_end_tone_id = ind->call_end_tone_id; /* for call end exit function, to stop tone*/

    mmi_ucm_tab_highlight();

    /* Because if output device switching from the loud speaker to the receiver during the tone playback 
       there will be a bo sound , beed to adjust seq */
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0)
    {
        if (mdi_audio_get_audio_mode() == AUD_MODE_LOUDSPK)
        {
            srv_speech_disable_hand_free();
        }
    }
#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))

    /* Do not disaply popup in fallto voice act case */
    if (SRV_UCM_VT_FALLTO_VOICE_ACT == srv_ucm_query_curr_action())
    {

    }
    else   
    {
#endif /* __OP01__ && __MMI_VIDEO_TELEPHONY__ */

        if (mmi_frm_scrn_is_present(GRP_ID_UCM_CALL_END, SCR_ID_UCM_CALL_END, MMI_FRM_NODE_ALL_FLAG))
        {
            mmi_frm_scrn_close(GRP_ID_UCM_CALL_END, SCR_ID_UCM_CALL_END);
        }

        mmi_ucm_sg_create(GRP_ID_ROOT, GRP_ID_UCM_CALL_END);

        call_end_p->call_end_type = MMI_UCM_CALL_END_TYPE_COMMON;
    #if defined(__MMI_VIDEO_TELEPHONY__) && (defined(__MMI_UCM_VT_ATUO_REDIAL_VOICE__) || defined(__OP01__))
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0 && 
            (ind->uid_info.call_type & SRV_UCM_VIDEO_CALL_TYPE_ALL) && 
            (MMI_TRUE == ind->post_action.action) &&
            (MMI_TRUE == mmi_ucm_check_post_action_about_sim(ind->uid_info.call_type, ind->remote_info.num_uri)))
        {
            if (MMI_UCM_VT_AUTO_REDIAL_MODE_ON == mmi_ucm_vt_get_auto_redial_mode())
            {
                call_end_p->call_end_type = MMI_UCM_CALL_END_TYPE_VT_AUTO_REDIAL_ON;
            }
            else if (MMI_UCM_VT_AUTO_REDIAL_MODE_OFF == mmi_ucm_vt_get_auto_redial_mode())
            {
                call_end_p->call_end_type = MMI_UCM_CALL_END_TYPE_VT_AUTO_REDIAL_OFF;
            }
            else
            {
                /* MMI_UCM_VT_AUTO_REDIAL_MODE_MANUAL , keep = MMI_UCM_CALL_END_TYPE_COMMON */
            }
        }
    #endif /* (__MMI_VIDEO_TELEPHONY__) && (defined(__MMI_UCM_VT_ATUO_REDIAL_VOICE__) || defined(__OP01__) */

        mmi_ucm_enter_call_end(call_end_p);
#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    }
#endif /* __OP01__ && __MMI_VIDEO_TELEPHONY__ */    
    /* Reject by SMS */
#ifdef __MMI_UCM_REJECT_BY_SMS__    
    if (g_ucm_p->rej_by_sms.uid_info.group_id == ind->uid_info.group_id &&
        g_ucm_p->rej_by_sms.uid_info.call_id == ind->uid_info.call_id &&
        g_ucm_p->rej_by_sms.uid_info.call_type == ind->uid_info.call_type)
    {
        /* This is the rejected call */
        rej_by_sms = MMI_TRUE;
    }
    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_RELEASE_IND_CALL_INFO_P2, rej_by_sms, g_ucm_p->rej_by_sms.is_confirmed); 

    if (rej_by_sms == MMI_TRUE && MMI_FALSE == g_ucm_p->rej_by_sms.is_confirmed)
    {

        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_RELEASE_IND_REJ_BY_SMS_ABORT);

        /* Abort sms template selection and remove confirm popup */
        if (GRP_ID_INVALID != g_ucm_p->cui_info.sms_template_cui)
        {
            cui_sms_template_close(g_ucm_p->cui_info.sms_template_cui);
        }
        if (SCR_ID_INVALID !=g_ucm_p->rej_by_sms.scrn_id)
        {
            mmi_alert_dismiss(g_ucm_p->rej_by_sms.scrn_id);
        }
    }
#endif /* __MMI_UCM_REJECT_BY_SMS__ */

#if (defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__) || defined (__MMI_VIDEO_TELEPHONY__) || defined(__MMI_UCM_MO_FAIL_POST_ACTION__)) 
    memset(ucs2_number, 0, (SRV_UCM_MAX_NUM_URI_LEN + 1) * ENCODING_LENGTH);																		
    mmi_asc_to_ucs2((CHAR*)ucs2_number, (CHAR*)&ind->remote_info.num_uri);
#endif /* (defined(__MMI_PHB_SAVE_CONTACT_NOTIFY__) || defined (__MMI_VIDEO_TELEPHONY__) || defined(__MMI_UCM_MO_FAIL_POST_ACTION__)) */
    /* Save contact notify */
#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
    if ((mmi_ucs2strlen((CHAR*)ucs2_number) != 0) &&
        (ind->uid_info.call_type & SRV_UCM_VOICE_CALL_TYPE_ALL) &&
        (ind->module_id != SRV_UCM_MODULE_ORIGIN_SAT) &&
        (mmi_phb_is_save_contact_notify_on() == MMI_TRUE) &&
        (mmi_phb_is_num_in_phb((U16*) ucs2_number) == MMI_FALSE) &&
        (srv_ucm_is_emergency_number(ind->uid_info.call_type , (U8 *)ind->remote_info.num_uri) == MMI_FALSE))
    {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_RELEASE_IND_NEW_NUMBER);
            phb_data = OslMalloc(sizeof(srv_phb_contact_data_struct));
            mmi_phb_unsaved_data_init(phb_data);  
            phb_data->number = (U16 *) ucs2_number;
            mmi_phb_add_data_to_unsaved_list(PHB_STORAGE_MAX, SRV_PHB_ENTRY_FIELD_NUMBER, phb_data);
            g_ucm_p->call_misc.is_new_number = MMI_TRUE;
            OslMfree(phb_data);
    }

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0 &&
        mmi_phb_is_save_contact_notify_on() == MMI_TRUE &&
        g_ucm_p->call_misc.is_new_number == MMI_TRUE &&
        mmi_phb_get_unsaved_data_num() != 0)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_RELEASE_IND_ADD_PHB_CONFIRM);
        mmi_phb_add_unsaved_data_confirm_to_history();
        g_ucm_p->call_misc.is_new_number = MMI_FALSE;
    }
#endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */
#ifdef __MMI_VIDEO_TELEPHONY__
    if (ind->uid_info.call_type & SRV_UCM_VIDEO_CALL_TYPE_ALL)
    {
        /* Decide if orig active VT end or MO/MT VT ends to adjst screen_mode. this value will decide if the setting should kept or init */
        /* ex. 1A VT + 1W VT, W-VT ends, should keep orig VT setting, but if 1A-VT end, shoud reset setting */
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) == 0)
        {
            if (MMI_UCM_VT_INCALL_SCREEN_MODE_INCALL == mmi_ucm_vt_get_incall_screen_mode())
            {
                mmi_ucm_vt_set_incall_screen_mode(MMI_UCM_VT_INCALL_SCREEN_MODE_NONE); 
            }
        }
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

    mmi_ucm_go_back_screen_check();
#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    /* should add this after  mmi_ucm_go_back_screen_check, because in that api, it will remove post action group */
    if (SRV_UCM_VT_FALLTO_VOICE_ACT == srv_ucm_query_curr_action())
    {
        if (mmi_frm_scrn_is_present(GRP_ID_UCM_MO_FAIL_POST_ACTION, SCR_ID_UCM_VT_FALLTO_VOICE_NOTIFY, MMI_FRM_NODE_ALL_FLAG))
        {
            mmi_frm_scrn_close(GRP_ID_UCM_MO_FAIL_POST_ACTION, SCR_ID_UCM_VT_FALLTO_VOICE_NOTIFY);
        }

        mmi_ucm_sg_create(GRP_ID_ROOT, GRP_ID_UCM_MO_FAIL_POST_ACTION);

        mmi_ucm_vt_enter_fallto_voice_notify();  
    }
#endif /* __OP01__ && __MMI_VIDEO_TELEPHONY__ */

#if defined(__MMI_VIDEO_TELEPHONY__) || defined (__MMI_UCM_MO_FAIL_POST_ACTION__)
    /* Handle VT post action */
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_RELEASE_IND_CALL_INFO_P2, srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL), ind->uid_info.call_type); 
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0 && 
        (MMI_TRUE == ind->post_action.action) &&
        (MMI_TRUE == mmi_ucm_check_post_action_about_sim(ind->uid_info.call_type, ind->remote_info.num_uri)))
    {
    #ifdef __MMI_VIDEO_TELEPHONY__
        if (ind->uid_info.call_type & SRV_UCM_VIDEO_CALL_TYPE_ALL)
        {  
            mmi_ucs2ncpy((CHAR*)g_ucm_p->vt_cntx.mo_info.dial_pad_buffer, (CHAR*)ucs2_number, SRV_UCM_MAX_NUM_URI_LEN);    

            /* reset guibuffer , beccasue g_vt_p->mo_info.dial_pad_buffer is changed and need update category16*/
            if (mmi_frm_scrn_is_present(GRP_ID_UCM_VT, SCR_ID_UCM_VT_DIALER, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
            {
                mmi_frm_scrn_clean_gui_buf(GRP_ID_UCM_VT, SCR_ID_UCM_VT_DIALER);
            }
			g_ucm_p->mo_info.is_ip_dial = ind->post_action.is_ip_dial;
			g_ucm_p->mo_info.phb_data = ind->post_action.phb_data;
        #if (defined(__OP01__) || defined(__MMI_UCM_VT_ATUO_REDIAL_VOICE__))
            if (MMI_UCM_VT_AUTO_REDIAL_MODE_ON == mmi_ucm_vt_get_auto_redial_mode())
            {
                /* Redial action will be tiggered when call end popup screen disappear */
            }
            else if ((MMI_UCM_VT_AUTO_REDIAL_MODE_OFF == mmi_ucm_vt_get_auto_redial_mode()) && 
                     (SRV_UCM_RESULT_VT_FALLBACK != ind->call_end_error_cause))
            {
                /* Do nothing , no auto redial or post action screen */    
            }
            else
        #endif /* (defined(__OP01__) || defined(__MMI_UCM_VT_ATUO_REDIAL_VOICE__)) */        
            {
                mmi_ucm_add_sg_to_root(mmi_frm_group_get_active_id(), GRP_ID_UCM_MO_FAIL_POST_ACTION, MMI_FRM_NODE_BEFORE_FLAG, NULL);    
                mmi_frm_group_set_attribute(GRP_ID_UCM_MO_FAIL_POST_ACTION, MMI_FRM_NODE_SMART_CLOSE_FLAG);
                mmi_ucm_vt_enter_mo_fail_post_action();
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_MO_FAIL_POST_ACTION_ADD_TO_HISTORY);
            }        
        }
        else
    #endif /* __MMI_VIDEO_TELEPHONY__ */   
    #ifdef __MMI_UCM_MO_FAIL_POST_ACTION__
        if (ind->uid_info.call_type & SRV_UCM_CALL_TYPE_NO_CSD)
        {
            mmi_ucs2ncpy((CHAR*)g_ucm_p->mo_info.dial_pad_buffer, (CHAR*)ucs2_number, SRV_UCM_MAX_NUM_URI_LEN);        
            g_ucm_p->mo_info.is_ip_dial = ind->post_action.is_ip_dial;
			g_ucm_p->mo_info.phb_data = ind->post_action.phb_data;
            g_ucm_p->mo_info.dial_type = ind->uid_info.call_type;
            
            mmi_ucm_add_sg_to_root(mmi_frm_group_get_active_id(), GRP_ID_UCM_MO_FAIL_POST_ACTION, MMI_FRM_NODE_BEFORE_FLAG, NULL);    
            mmi_frm_group_set_attribute(GRP_ID_UCM_MO_FAIL_POST_ACTION, MMI_FRM_NODE_SMART_CLOSE_FLAG);
            mmi_ucm_enter_mo_fail_post_action();
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_MO_FAIL_POST_ACTION_ADD_TO_HISTORY);
        }
        else
    #endif /* __MMI_UCM_MO_FAIL_POST_ACTION__ */
        {
            /* Do nothing */
        }
    }
#endif /* defined(__MMI_VIDEO_TELEPHONY__) || defined (__MMI_UCM_MO_FAIL_POST_ACTION__) */

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0)
    {
        if (srv_speech_is_phone_mute() == MMI_TRUE)
        {
        	srv_speech_unmute_phone();
        }
    #ifdef __MMI_VIDEO_TELEPHONY__
        if (ind->uid_info.call_type & SRV_UCM_VIDEO_CALL_TYPE_ALL)
        {
            mmi_ucm_vt_call_end_callback();
        }
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        g_ucm_p->call_misc.is_dtmf= MMI_TRUE;
        memset(&g_ucm_p->call_cost, 0, sizeof(mmi_ucm_call_cost_cntx_struct));
        
    #ifdef __MMI_CH_QUICK_END__
        StopTimer(CM_AUTO_QUICK_END_TIMER);
    #endif /* __MMI_CH_QUICK_END__ */

    #if defined(__AGPS_SUPPORT__) && defined(__SUPL_SUPPORT__)
        mmi_gps_mgr_call_end(); /*x*/
    #endif /* defined(__AGPS_SUPPORT__) && defined(__SUPL_SUPPORT__) */

    #ifdef __BT_SPK_VOL_CONTROL__
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_RELEASE_IND_VOL_CONTROL_STOP);
        mdi_audio_bt_clear_volume_sync_callback(APP_UCM); /* O */
    #endif /* __BT_SPK_VOL_CONTROL__ */

    #ifdef __MMI_DUAL_MIC_SUPPORT__
        mdi_audio_set_dual_mic_nr(MMI_FALSE);
    #endif /* __MMI_DUAL_MIC_SUPPORT__ */
    }

#ifdef __MMI_BT_CALL_SUPPORT__
    if (mmi_frm_group_is_present(GRP_ID_UCM_MO_SELECT))
    {
        mmi_frm_group_close(GRP_ID_UCM_MO_SELECT);
    }
#endif /* __MMI_BT_CALL_SUPPORT__ */

#ifdef __MMI_BG_SOUND_EFFECT__
    if ((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VOICE_CALL_TYPE_ALL, NULL) == 0) &&
		(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VOIP_CALL_TYPE, NULL) == 0))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_RELEASE_IND_END_BGS);
        mmi_bgsnd_util_delete_end_call_screen(); /* O */
    }
#endif /* __MMI_BG_SOUND_EFFECT__ */

#ifdef __MMI_NETWORK_CIPHER_SUPPORT__
    /* hide GSM cipher status icon when there is no GSM call */
#if (MMI_MAX_SIM_NUM <= 2)
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_SIM1_CALL_TYPE_ALL, NULL) == 0)
    {
        wgui_status_icon_bar_hide_icon(STATUS_ICON_NETWORK_CIPHER_GSM);
    }
#if (MMI_MAX_SIM_NUM == 2)
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_SIM2_CALL_TYPE_ALL, NULL) == 0)
    {
        wgui_status_icon_bar_hide_icon(STATUS_ICON_SLAVE_NETWORK_CIPHER_GSM);
    }
#endif /* (MMI_MAX_SIM_NUM == 2) */
#else /* (MMI_MAX_SIM_NUM <= 2) */
    /* For projects with 3/4 SIM cards, Cipher icon doesn't contain SIM ID */
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL,
        SRV_UCM_SIM1_CALL_TYPE_ALL | SRV_UCM_SIM2_CALL_TYPE_ALL | SRV_UCM_SIM3_CALL_TYPE_ALL| SRV_UCM_SIM4_CALL_TYPE_ALL,
        NULL) == 0)
    {
        wgui_status_icon_bar_hide_icon(STATUS_ICON_NETWORK_CIPHER_GSM);
    }
#endif /* (MMI_MAX_SIM_NUM <= 2) */
#endif /* __MMI_NETWORK_CIPHER_SUPPORT__ */

    /* stop the CTR time since there is no active/held voice call */
    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0 &&
        srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 0)
    {
        if(IsMyTimerExist(CM_CTR_TIMER) == MMI_TRUE)
        {
           StopTimer(CM_CTR_TIMER);
        }
    }

#ifdef  __MMI_FTE_SUPPORT__
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
    {
        if(IsMyTimerExist(TIMER_ID_UCM_DELAY_RING) == MMI_TRUE)
        {
           StopTimer(TIMER_ID_UCM_DELAY_RING);
        }
    }
#endif /* __MMI_FTE_SUPPORT__ */

#ifdef __OP01_FWPBW__
    mmi_ucm_fwp_call_process_event_hdlr(MMI_UCM_FWPCP_NOCALL_EVENT);
#endif /* __OP01_FWPBW__ */
#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
    g_ucm_p->call_misc.is_power_key_lcok = MMI_FALSE;
#endif /* __MMI_SCREEN_LOCK_ANY_TIME__ */

#ifdef __MMI_BACKGROUND_CALL_WITH_NCENTER__
    if (0 == srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, incall_type, NULL))
    {
        mmi_ucm_close_incall_notification();
    }
#endif /* __MMI_BACKGROUND_CALL_WITH_NCENTER__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_accept_act_rsp
 * DESCRIPTION
 *  Handler for accept action response. No success popup but screen will adjust.
 * PARAMETERS
 *  rsp      [IN]            Action structure
 *  act_type [IN]            single or compound action   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_accept_act_rsp(srv_ucm_act_rsp_struct *rsp, srv_ucm_act_type_enum act_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //srv_ucm_act_rsp_struct *rsp = (srv_ucm_act_rsp_struct*)act_struct;
#ifdef __MMI_CH_QUICK_END__
    U16 quickEndDuration = srv_callset_auto_quick_end_get_time();
#endif /* __MMI_CH_QUICK_END__ */
#if !defined(__MMI_BACKGROUND_CALL__) || defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
    MMI_ID scrn_id;
#endif /* !defined(__MMI_BACKGROUND_CALL__) || defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp->result_info.result == SRV_UCM_RESULT_OK)
    {
    #ifdef  __MMI_FTE_SUPPORT__
        if(IsMyTimerExist(TIMER_ID_UCM_DELAY_RING) == MMI_TRUE)
        {
           StopTimer(TIMER_ID_UCM_DELAY_RING);
        }
    #endif /* __MMI_FTE_SUPPORT__ */

        mmi_ucm_stop_incoming_tone();
	#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
        if (mmi_scr_locker_get_type() != MMI_SCR_LOCKER_TYPE_LAWMO)
        {
    	    mmi_scr_locker_close();
        }
	#endif /* __MMI_SCREEN_LOCK_ANY_TIME__ */
        g_ucm_p->call_misc.is_ringtone_suppress = MMI_FALSE;
    #if defined(__MMI_FTE_SUPPORT__) && !defined(__PXS_APP_ENABLE__)
        mmi_ucm_auto_lock_fsm_hdlr(MMI_UCM_AL_ACCEPT_EVENT);
    #endif /* defined(__MMI_FTE_SUPPORT__) && !defined(__PXS_APP_ENABLE__) */

    #ifdef __MMI_DUAL_MIC_SUPPORT__
        mdi_audio_set_dual_mic_nr(mmi_ucm_get_dual_mic_nr_status());
    #endif /* __MMI_DUAL_MIC_SUPPORT__ */

    #ifdef MOTION_SENSOR_SUPPORT
        mmi_ucm_motion_turnover_dereg();
    #if defined(__MMI_SOUND_RECORDER__) && defined(__MOTION_SENSOR_ADVANCED_GESTURE__)
        mmi_ucm_motion_double_tap_reg();
    #endif /* defined(__MMI_SOUND_RECORDER__) && defined(__MOTION_SENSOR_ADVANCED_GESTURE__) */
    #endif /* MOTION_SENSOR_SUPPORT */

        /*incoming --> actvie, therefore the accepted call must active currently*/    
    #ifdef __MMI_VIDEO_TELEPHONY__   
        if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) == 1)
        {
            if (MMI_UCM_VT_ANSWER_MODE_START_CAMERA == mmi_ucm_vt_get_answer_mode())
            {
                mmi_ucm_vt_set_camera_status(MMI_TRUE);
            }
            /* for stop and prompt cases  */
            else
            {
                mmi_ucm_vt_set_camera_status(MMI_FALSE);
            }
        }
    #endif /*__MMI_VIDEO_TELEPHONY__*/    

    #ifdef __MMI_CH_QUICK_END__
        if (IsMyTimerExist(CM_AUTO_QUICK_END_TIMER) == FALSE &&
            quickEndDuration > 0 && 
            srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 &&
            srv_ucm_is_emergency_call() == MMI_FALSE)
        {
            StartTimer(CM_AUTO_QUICK_END_TIMER, (quickEndDuration * 1000), mmi_ucm_auto_quick_end);
        }
    #endif /* __MMI_CH_QUICK_END__ */

        /* Start CTR timer if it hasn't started yet */
	#ifdef __MMI_CALLSET_CALLTIME_REMINDER__
        mmi_ucm_call_time_reminder_hdlr();
    #endif

        if (SRV_UCM_ACT_TYPE_SINGLE == act_type || SRV_UCM_ACT_TYPE_COMPOUND_SECOND == act_type)
        {
        #ifdef __MMI_BACKGROUND_CALL_WITH_NCENTER__
            if (mmi_frm_group_get_state(GRP_ID_UCM_MARKER) & MMI_SCENARIO_STATE_HIDE)
            {
                mmi_frm_group_unhide(GRP_ID_UCM_MARKER);
                mmi_frm_group_unhide(GRP_ID_UCM_INCALL);
            }
        #endif /* __MMI_BACKGROUND_CALL_WITH_NCENTER__ */

            /* Get incall screen to active */
        #if !defined(__MMI_BACKGROUND_CALL__) || defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
            if (mmi_frm_scrn_is_present(GRP_ID_UCM_INCALL, SCR_ID_UCM_IN_CALL, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG) &&
                srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, MMI_UCM_CALL_TYPE_FOR_SOLE_EXISTENCE, NULL) == 0)
            {
                mmi_frm_set_active_group(GRP_ID_UCM_MARKER);
                mmi_frm_set_active_group(GRP_ID_UCM_INCALL);
                scrn_id = mmi_frm_scrn_get_neighbor_id(GRP_ID_UCM_INCALL, SCR_ID_INVALID, MMI_FRM_NODE_AT_LATEST_FLAG);
                mmi_frm_scrn_multiple_close(GRP_ID_UCM_INCALL, scrn_id, MMI_TRUE, 0, SCR_ID_UCM_IN_CALL, MMI_FALSE);
                mmi_frm_group_close(GRP_ID_UCM_CONFIRM);                
            }
        #endif /* !defined(__MMI_BACKGROUND_CALL__) || defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */
        
            mmi_ucm_go_back_screen_check();
        }
        
    #ifdef __MMI_VIDEO_TELEPHONY__ 
        if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) == 1)
        {
            if (MMI_UCM_VT_ANSWER_MODE_PROMPT == mmi_ucm_vt_get_answer_mode())
            {
                srv_ucm_query_cnf_ind_struct cnf;

                memset(&cnf, 0, sizeof(srv_ucm_query_cnf_ind_struct));
                mmi_ucs2cpy((CHAR*)cnf.content, (CHAR*)GetString(STR_ID_UCM_VT_START_CAMERA_QUERY));
                g_ucm_p->cnf_scr.conf_ind_cb = mmi_ucm_vt_answer_mode_prompt_cb;

                mmi_ucm_query_cnf_ind(&cnf);
                StartTimer(VT_START_CAMERA_QUERY_TIMER, MMI_UCM_VT_START_CAMERA_QUERY_TIMEOUT, mmi_ucm_vt_start_camera_query_timeout);
            }
        }
    #endif /* __MMI_VIDEO_TELEPHONY__ */

    #ifdef __OP01_FWPBW__
        mmi_ucm_fwp_call_process_event_hdlr(MMI_UCM_FWPCP_ACCEPT_EVENT);
    #endif /* __OP01_FWPBW__ */
	#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
    	g_ucm_p->call_misc.is_power_key_lcok = MMI_FALSE;
	#endif /* __MMI_SCREEN_LOCK_ANY_TIME__ */

    }
    else
    {
        mmi_ucm_display_popup_when_call_exist((UI_string_type) rsp->result_info.error_msg, MMI_EVENT_FAILURE);

        /* go back to corresponding screen */
        mmi_ucm_go_back_screen_check();
    }
}

#ifdef __AOC_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_call_cost_ind
 * DESCRIPTION
 *  Handler for call cost indication
 * PARAMETERS
 *  ind      [IN]            call cost indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_call_cost_ind(srv_ucm_call_cost_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memcpy(&g_ucm_p->call_cost.uid_info, &ind->uid_info, sizeof(srv_ucm_id_info_struct));

#ifdef __MMI_VIDEO_TELEPHONY__
    /* Kept these value to g_ucm_p context for VT */
    if (ind->currency_symbol[0] == 0 && ind->currency_symbol[1] == 0)
    {
        g_ucm_p->call_cost.currency_symbol[0] = 0;
    }
    else
    {
        mmi_ucs2ncpy((CHAR*)g_ucm_p->call_cost.currency_symbol, (CHAR*)ind->currency_symbol, MMI_UCM_CALL_COST_UNIT_DIGITS);
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

    app_ucs2_itoa((S32) ind->total_cost_unit, (kal_int8*)g_ucm_p->call_cost.total_cost_unit , 10);

    /* go back to in-call screen with updated information */    
    if (mmi_frm_scrn_get_active_id() == SCR_ID_UCM_IN_CALL)
    {
        reset_call_cost_UI();
        show_call_cost_UI(ind->currency_symbol, (PU8) g_ucm_p->call_cost.total_cost_unit);
    }
}

#endif

#ifdef __MMI_CALLSET_AUTO_REDIAL__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_auto_redial_cancel_ind
 * DESCRIPTION
 *  Handler for auto redial cancel indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_auto_redial_cancel_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GRP_ID_UCM_AUTO_REDIAL == mmi_frm_group_get_active_id())
    {
        mmi_frm_group_close(GRP_ID_UCM_AUTO_REDIAL);
    }
    else
    {
        mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_AUTO_REDIAL, SCR_ID_UCM_AUTO_REDIAL, (mmi_proc_func) NULL);    
        mmi_frm_group_close(GRP_ID_UCM_AUTO_REDIAL);
		memset(&g_ucm_p->auto_redial, 0, sizeof(srv_ucm_auto_redial_ind_struct));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_auto_redial_ind
 * DESCRIPTION
 *  Handler for auto reduial indication
 * PARAMETERS
 *  ind      [IN]             auto reduial indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_auto_redial_ind(srv_ucm_auto_redial_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
    {
    	memcpy(&(g_ucm_p->auto_redial), ind, sizeof(srv_ucm_auto_redial_ind_struct));
	    if (GRP_ID_UCM_CALL_END == mmi_frm_group_get_active_id())
        {
            mmi_ucm_add_sg_to_root(GRP_ID_UCM_CALL_END, GRP_ID_UCM_AUTO_REDIAL, MMI_FRM_NODE_BEFORE_FLAG, NULL);
            mmi_ucm_enter_auto_redial();
            mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_AUTO_REDIAL, SCR_ID_UCM_AUTO_REDIAL, (mmi_proc_func) mmi_ucm_auto_redial_screen_delete_proc);    
        }
        else
        {   
            /* prevent 2 auto redail scrn is in history */
            mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_AUTO_REDIAL, SCR_ID_UCM_AUTO_REDIAL, (mmi_proc_func) NULL); 
            mmi_frm_group_close(GRP_ID_UCM_AUTO_REDIAL);

            mmi_ucm_sg_create(GRP_ID_ROOT, GRP_ID_UCM_AUTO_REDIAL);

            mmi_ucm_enter_auto_redial();
        }
    }
    else
    {	
    	if (ind->abort_hdlr)
        {
            ind->abort_hdlr();
        }
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_start_processing_ind
 * DESCRIPTION
 *  Handler for start processing indication
 * PARAMETERS
 *  start_processing_ind      [IN]            start processing indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_start_processing_ind(srv_ucm_start_processing_ind_struct *start_processing_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_set_processing_parameter_with_body_string_p(
        STR_ID_UCM_PROCESSING,
        (U8*)start_processing_ind->content,
        IMG_GLOBAL_PROGRESS,
        0,
        0,
        0,
        0,
        0,
        0);

    mmi_ucm_enter_processing_screen(mmi_frm_group_get_active_id());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_stop_processing_ind
 * DESCRIPTION
 *  Handler for stop processing indication
 * PARAMETERS
 *  stop_processing_ind      [IN]            stop processing indication structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_stop_processing_ind(srv_ucm_stop_processing_ind_struct *stop_processing_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct popup_property;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((CHAR*)stop_processing_ind->disp_msg) > 0)  /* release call will have release_ind to show call end popup */
    {
        mmi_popup_property_init(&popup_property);
        popup_property.duration = (U32)UI_POPUP_NOTIFYDURATION_TIME;
        popup_property.tone_id = (srv_prof_tone_enum) stop_processing_ind->tone_id;
        popup_property.msg_icon = stop_processing_ind->image_id;
        mmi_popup_display((WCHAR*)((UI_string_type) stop_processing_ind->disp_msg), MMI_EVENT_INFO, &popup_property);
    }    
    
    mmi_ucm_go_back_screen_check();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_query_cnf_ind
 * DESCRIPTION
 *  the g_ucm_p->cnf_scr.conf_ind_cb is alrady assigned or reset before mmi_ucm_query_cnf_ind is called
 * PARAMETERS
 *  act_struct      [IN]            Action structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_query_cnf_ind(srv_ucm_query_cnf_ind_struct *cnf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->cnf_scr.content != NULL)
    {
        OslMfree(g_ucm_p->cnf_scr.content);
        g_ucm_p->cnf_scr.content = NULL;
    }
    
    /* the g_ucm_p->cnf_scr.conf_ind_cb is alrady assigned or reset before mmi_ucm_display_cnf is called */
    g_ucm_p->cnf_scr.content = OslMalloc((mmi_ucs2strlen((CHAR*)cnf->content) + 1) * ENCODING_LENGTH);
    mmi_ucs2cpy((CHAR*)g_ucm_p->cnf_scr.content, (CHAR*)cnf->content);
    mmi_ucm_sg_create(GRP_ID_ROOT, GRP_ID_UCM_CONFIRM);
    mmi_ucm_enter_confirm();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_query_cancel_ind
 * DESCRIPTION
 *  Handler for query cancel indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_query_cancel_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_UCM_CONFIRM))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_CANCEL_CNF_PROCESS);

        /* delete confirm screen , delete cb here is to avoid cb will execute but srv will alreay free necessary information before send cancel ind */
        mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_CONFIRM, g_ucm_p->cnf_scr.scrn_id, (mmi_proc_func) NULL);   

        if (GRP_ID_UCM_CONFIRM != mmi_frm_group_get_active_id())
        {
            mmi_alert_dismiss(g_ucm_p->cnf_scr.scrn_id);
            g_ucm_p->cnf_scr.scrn_id = SCR_ID_INVALID;
        }
        
        if (g_ucm_p->cnf_scr.scrn_id == mmi_frm_scrn_get_active_id())
        {

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_CANCEL_CNF_GO_BACK_SCREEN);
            
            mmi_ucm_set_processing_parameter(
                STR_ID_UCM_PROCESSING,
                STR_ID_UCM_PROCESSING,
                mmi_get_event_based_image(MMI_EVENT_PROGRESS),
                0,
                0,
                0,
                0,
                0,
                0);
           
            mmi_ucm_enter_processing_screen(GRP_ID_UCM_CONFIRM);

            mmi_alert_dismiss(g_ucm_p->cnf_scr.scrn_id);
        
            g_ucm_p->cnf_scr.scrn_id = SCR_ID_INVALID;
            mmi_ucm_go_back_screen_check();
        }
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_CANCEL_CNF_IGNORE);
    }
}


/* ==================================================================================== */
/* =============UI: phb common UI / launch related===================================== */
/* ==================================================================================== */ 

#ifdef __MMI_UCM_DEFLECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_select_number_proc
 * DESCRIPTION
 *  This function is to handle the select number result sent from phb
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_select_number_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_phb_select_contact_result_struct* select_contact_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_PHB_SELECT_CONTACT:
        {
            /* 1. get selected number */
            select_contact_result = (cui_phb_select_contact_result_struct*)evt;

            if (MMI_UCM_PHB_SEL_FOR_DEFLECT == cui_phb_list_select_contact_get_user_data(g_ucm_p->cui_info.select_contact_cui_id))
            {
                memset(g_ucm_p->mo_info.dial_pad_buffer, 0x00, sizeof(g_ucm_p->mo_info.dial_pad_buffer));
                mmi_ucs2ncpy((CHAR*)g_ucm_p->mo_info.dial_pad_buffer, (CHAR*)select_contact_result->select_data, SRV_UCM_MAX_NUM_URI_LEN);
                
                /* 2. close phb cui */    
                cui_phb_list_select_contact_close(g_ucm_p->cui_info.select_contact_cui_id);
                g_ucm_p->cui_info.select_contact_cui_id = GRP_ID_INVALID;
                /* 3. execute deflect action, may trigger scrn .. */
                mmi_ucm_deflect();
            }
            else
            {
                MMI_ASSERT(0); /* currently, only MMI_UCM_PHB_SEL_FOR_DEFLECT case*/
            }

        }
        break;
        
        case EVT_ID_PHB_SELECT_CONTACT_CANCEL:
        {
            if (MMI_UCM_PHB_SEL_FOR_DEFLECT == cui_phb_list_select_contact_get_user_data(g_ucm_p->cui_info.select_contact_cui_id))
            {
                cui_phb_list_select_contact_close(g_ucm_p->cui_info.select_contact_cui_id);  
                g_ucm_p->cui_info.select_contact_cui_id = GRP_ID_INVALID;
            }
            else
            {
                MMI_ASSERT(0); /* currently, only MMI_UCM_PHB_SEL_FOR_DEFLECT case*/
            }           

        }
        break;
        
        default:
        {

        }
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_select_number_for_deflect
 * DESCRIPTION
 *  launch phb to select a number for deflect action
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_select_number_for_deflect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //mmi_frm_group_create (GRP_ID_ROOT, APP_UCM, mmi_ucm_select_number_proc, NULL);
    //mmi_frm_group_enter(APP_UCM, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    /* Caller should keep the CUI group id, because all operation about CUI depends on it */
    MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_UCM_MT));

    g_ucm_p->cui_info.select_contact_cui_id = cui_phb_list_select_contact_create(GRP_ID_UCM_MT);

    if (g_ucm_p->cui_info.select_contact_cui_id != GRP_ID_INVALID)
    {
        cui_phb_list_select_contact_set_field_filter(g_ucm_p->cui_info.select_contact_cui_id, SRV_PHB_ENTRY_FIELD_GSM_NUM);
        cui_phb_list_select_contact_set_user_data(g_ucm_p->cui_info.select_contact_cui_id, MMI_UCM_PHB_SEL_FOR_DEFLECT);
        cui_phb_list_select_contact_run(g_ucm_p->cui_info.select_contact_cui_id);
    }
    return;
}
#endif /* __MMI_UCM_DEFLECT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_launch_phb_app
 * DESCRIPTION
 *  launch phb application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_launch_phb_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_phb_launch(); /* will return mmi_id here, but currently, ucm does not use this return value */
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_act_notify_hdlr
 * DESCRIPTION
 *  This function is to handle phb save number CUI flow
 * PARAMETERS
 *  evt:     [IN] Event structure passed by callback manager
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_ucm_save_number_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* cui_phb_save_contact_result_struct* save_number_result; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_PHB_SAVE_CONTACT:
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
            /* save_number_result = (cui_phb_save_contact_result_struct*)evt; */
            cui_phb_save_contact_close(g_ucm_p->cui_info.save_number_cui_id);
            g_ucm_p->cui_info.save_number_cui_id = GRP_ID_INVALID;
        break;
        
        default:
        break;
    }
    
    return MMI_RET_OK;
}


#if defined (__MMI_VOIP__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_save_voip_num_to_phonebook
 * DESCRIPTION
 *  launch phb common UI to save voip number to phone book
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void  mmi_ucm_save_voip_num_to_phonebook(U16 *number, MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * If caller app not support Screen Group(SG), it has to entry new SG for using CUI, 
     * but no any screen based on it.
     * 
     * 1. Caller can use app id as SG id, or define SG id in app resource file
     * 2. The fourth params is user_data, caller can keep some data in it
    */
    /* mmi_frm_group_entry_ex(GRP_ID_ROOT, APP_UCM, mmi_ucm_save_number_proc, NULL, NULL); */


    /* Caller should keep the CUI group id, because all operation about CUI depends on it */
    g_ucm_p->cui_info.save_number_cui_id = cui_phb_save_contact_create(parent_id);

    if (g_ucm_p->cui_info.save_number_cui_id != GRP_ID_INVALID)
    {
        cui_phb_save_contact_set_voip(g_ucm_p->cui_info.save_number_cui_id, number);
        cui_phb_save_contact_run(g_ucm_p->cui_info.save_number_cui_id);
    }
}
#endif /* __MMI_VOIP__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_save_number_to_phonebook
 * DESCRIPTION
 *  launch phb common UI to save number to phone book
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void  mmi_ucm_save_number_to_phonebook(U16 *number, MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * If caller app not support Screen Group(SG), it has to entry new SG for using CUI, 
     * but no any screen based on it.
     * 
     * 1. Caller can use app id as SG id, or define SG id in app resource file
     * 2. The fourth params is user_data, caller can keep some data in it
    */

    /* Caller should keep the CUI group id, because all operation about CUI depends on it */
    g_ucm_p->cui_info.save_number_cui_id = cui_phb_save_contact_create(parent_id);

    if (g_ucm_p->cui_info.save_number_cui_id != GRP_ID_INVALID)
    {
        cui_phb_save_contact_set_number(g_ucm_p->cui_info.save_number_cui_id, number);
        cui_phb_save_contact_run(g_ucm_p->cui_info.save_number_cui_id);
    }
}


/* ==================================================================================== */
/* =============Screen flow============================================================ */
/* ==================================================================================== */
#ifdef __MMI_UCM_REJECT_BY_SMS__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_rej_by_sms_confirm_delete_proc
 * DESCRIPTION
 *  the proc when reject sms confirm popup is deleted
 * PARAMETERS
 *  in_param        [?]     
 * RETURNS
 *  U8
 *****************************************************************************/
mmi_ret mmi_ucm_entry_rej_by_sms_confirm_delete_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:            
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_REJ_BY_SMS_DELETE_CB);
            if (g_ucm_p->rej_by_sms.ucs2_msg_context != NULL)
            {
                OslMfree(g_ucm_p->rej_by_sms.ucs2_msg_context);
                g_ucm_p->rej_by_sms.ucs2_msg_context = NULL;
            }
            memset(&g_ucm_p->rej_by_sms, 0, sizeof(mmi_ucm_rej_by_sms_struct));
            g_ucm_p->rej_by_sms.scrn_id = SCR_ID_INVALID;
        }
        break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_sms_template_proc
 * DESCRIPTION
 *  This function is to handle the sms template result sent from sms
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_sms_template_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sms_template_evt_struct *temp_evt = (cui_sms_template_evt_struct*)evt;
    WCHAR* sms_template_content;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch (temp_evt->key_pressed)
    {
        case MMI_LEFT_SOFTKEY:
        case MMI_RIGHT_SOFTKEY:    
        {
            /* use default, LSK = select, RSK = back */
            sms_template_content = cui_sms_template_list_get_select_content(temp_evt->sender_id);    
            mmi_ucm_get_sms_template_callback(sms_template_content, temp_evt->key_pressed);
            cui_sms_template_close(temp_evt->sender_id);
            g_ucm_p->cui_info.sms_template_cui = GRP_ID_INVALID;
        }
        break;

        case MMI_CENTER_SOFTKEY:
        {

        }
        break;
    
        default:
        break;
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_sms_template
 * DESCRIPTION
 *  get sms template 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_get_sms_template(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* sms_message = NULL;
	srv_ucm_call_info_struct call_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_GET_SMS_TEMPLATE);

    g_ucm_p->rej_by_sms.is_confirmed = MMI_FALSE;
  
    g_ucm_p->cui_info.sms_template_cui = cui_sms_template_list_create(GRP_ID_UCM_MT, MMI_FALSE, CUI_SMS_TEMPLATE_NONE, MMI_FALSE);
    
    if (GRP_ID_INVALID == g_ucm_p->cui_info.sms_template_cui)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_GET_SMS_TEMPLATE_EMPTY);

        /* template is empty, use default sms*/
        sms_message = (U8*)GetString(STR_ID_UCM_REJ_BY_SMS_DEFAULT_MSG);

        if (g_ucm_p->rej_by_sms.ucs2_msg_context != NULL)
        {
            OslMfree(g_ucm_p->rej_by_sms.ucs2_msg_context);
            g_ucm_p->rej_by_sms.ucs2_msg_context = NULL;
        }
        
        g_ucm_p->rej_by_sms.ucs2_msg_context = OslMalloc((mmi_ucs2strlen((CHAR*)sms_message) + 1) * ENCODING_LENGTH);
        mmi_ucs2cpy((CHAR*)g_ucm_p->rej_by_sms.ucs2_msg_context, (CHAR*)sms_message);
        mmi_ucm_enter_rej_by_sms_confirm();
    }
    else
    {
        /* mmi_ucm_mt_sg_proc */
        cui_sms_template_list_run(g_ucm_p->cui_info.sms_template_cui);
    }

    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) != 1)
    {
        ASSERT(0);
    }
    srv_ucm_query_call_data(g_ucm_p->call_misc.index_list[0], &call_info);
    /* uid info */
	memcpy(&(g_ucm_p->rej_by_sms.uid_info), &(call_info.uid_info), sizeof(srv_ucm_id_info_struct));
}
#endif /* __MMI_UCM_REJECT_BY_SMS__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_exit_incoming_call
 * DESCRIPTION
 *  Exit function for incoming call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_exit_incoming_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef  __MMI_FTE_SUPPORT__
    StopTimer(UCM_FTE_AUTO_LOCK_TIMER_ID);
#endif /* __MMI_FTE_SUPPORT__ */

#ifdef __DRM_SUPPORT__
    mmi_ucm_drm_stop_consume();
#endif /* __DRM_SUPPORT__ */

	srv_backlight_turn_off();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_exit_outgoing_call
 * DESCRIPTION
 *  Exit function for outgoing call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_exit_outgoing_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef  __MMI_FTE_SUPPORT__
    StopTimer(UCM_FTE_AUTO_LOCK_TIMER_ID);
#endif /* __MMI_FTE_SUPPORT__ */
    
#ifdef __DRM_SUPPORT__
    mmi_ucm_drm_stop_consume();
#endif /* __DRM_SUPPORT__ */

#ifdef __MMI_BT_SUPPORT__
    mmi_ucm_reset_bt_notify();
#endif /* __MMI_BT_SUPPORT__ */

}


#ifdef __MMI_UCM_DEFLECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_deflect_from_icon
 * DESCRIPTION
 *  execute deflect action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_deflect_from_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_deflect();
}
#endif /* __MMI_UCM_DEFLECT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_in_call_ssc_parse
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_in_call_ssc_parse(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR stringIMEI[20];
    CHAR newstringIMEI[MAX_DIGITS_USSD * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_IN_CALL_SSC_PARSE_P1, 0);
    
    strcpy(stringIMEI, "*#06#");
    mmi_asc_to_ucs2(newstringIMEI, stringIMEI);
    
    if (mmi_ucs2cmp(newstringIMEI, (CHAR*)g_ucm_p->call_misc.disp_dtmf) == 0)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_IN_CALL_SSC_PARSE_P1, 1);
        mmi_ucm_delete_dtmf_editor_screen();
        SSCHandleIMEI();
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_pre_send_dtmf
 * DESCRIPTION
 *  Determine to send DTMF or not based on current state.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_pre_send_dtmf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keyCode = 0, keyType = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_PRE_SEND_DTMF, g_ucm_p->call_misc.is_dtmf);

    GetkeyInfo(&keyCode, &keyType);
    if (MMI_FALSE == wgui_inputs_dialer_is_dialer_keys(keyCode))
    {
        return;
    }

    /* For first spec digit keycode like '*' to disable highlight */
    mmi_frm_send_incomplete_key_event_to_new_screen(MMI_TRUE);
    
    mmi_ucm_pre_entry_dtmf_editor();

    mmi_ucm_dtmf_key_down(keyCode);
    
    wgui_inputs_dialer_display_char(keyCode);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_exit_dtmf_editor
 * DESCRIPTION
 *  Exit function of dtmf editor in call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_exit_dtmf_editor(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_ucm_p->call_misc.is_dtmf_start == MMI_TRUE)
    {
        srv_ucm_act_request(SRV_UCM_STOP_DTMF_ACT, NULL, NULL, NULL);
    }

    /* Prevent the mic is mute because of sending DTMF but not unmute later. */
    if (srv_speech_is_phone_mute() == MMI_FALSE)
    {
        srv_gpio_set_device_mute(SRV_GPIO_AUDDEV_MISROPHONE, MMI_FALSE);
    }
    g_ucm_p->call_misc.dtmf_editor_SG_id = GRP_ID_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_pre_entry_dtmf_editor
 * DESCRIPTION
 *  Pre-entry function of dtmf editor in call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_pre_entry_dtmf_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Avoid re-entry of DTMF editor */
    mmi_ucm_delete_dtmf_editor_screen();    
    mmi_ucm_close_cui(&g_ucm_p->cui_info.in_call_dialer_opt_cui_id);
    memset(g_ucm_p->call_misc.disp_dtmf, 0, sizeof(g_ucm_p->call_misc.disp_dtmf));
    
    mmi_ucm_enter_dtmf_editor();
}


/* high related to screen. so put in UI.c */
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_dtmf_key_down
 * DESCRIPTION
 *  Send DTMF sound to remote side.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_dtmf_key_down(U8 keyCode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_dtmf_struct check_act_req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_DTMF_KEY_DOWN);
    check_act_req.digit = keyCode;
    mmi_ucm_send_dtmf_action(SRV_UCM_START_DTMF_ACT, (void*)&check_act_req, keyCode);
}


/* high related to screen. so put in UI.c */
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_dtmf_key_up
 * DESCRIPTION
 *  Stop sending DTMF sound to remote side.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_dtmf_key_up(U8 keycode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_DTMF_KEY_UP);
    mmi_ucm_send_dtmf_action(SRV_UCM_STOP_DTMF_ACT, NULL, keycode);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_send_dtmf_action
 * DESCRIPTION
 *  Send DTMF related action
 * PARAMETERS
 *  act_op              [IN]        SRV_UCM_START_DTMF_ACT/SRV_UCM_STOP_DTMF_ACT
 *  check_act_req       [IN]        check action struct
 *  keycode             [IN]        keycode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_send_dtmf_action(srv_ucm_act_opcode_enum act_op, void *check_act_req, U8 keycode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_index = 0;
    srv_ucm_call_type_enum call_type = (srv_ucm_call_type_enum)0;
    srv_ucm_group_info_struct group_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if ((g_ucm_p->call_misc.is_dtmf == MMI_TRUE) &&
        (SRV_UCM_RESULT_OK == srv_ucm_query_act_permit(act_op, check_act_req)))
    {
        /* get current active call type */
        group_index = mmi_ucm_get_group_index_by_call_state_and_type(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_NO_CSD);

        if (group_index != -1)
        {
            srv_ucm_query_group_data(group_index, &group_info);
            call_type = group_info.call_type;
        }
        else
        {
            group_index = mmi_ucm_get_group_index_by_call_state_and_type(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_NO_CSD);

            if (group_index != -1)
            {
                srv_ucm_query_group_data(group_index, &group_info);
                call_type = group_info.call_type;
            }
        }

        if (call_type && (MMI_TRUE == srv_ucm_is_valid_dtmf_digit(call_type, keycode)))
        {
            if (SRV_UCM_START_DTMF_ACT == act_op)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_DTMF_KEY_DOWN_SEND_START, call_type);
                if (srv_speech_is_phone_mute() == MMI_FALSE)
                {
                    srv_gpio_set_device_mute(SRV_GPIO_AUDDEV_MISROPHONE, MMI_TRUE);
                }
            }
            else
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_DTMF_KEY_UP_SEND_STOP, call_type);
            }
            
            /* call start dtmf API */    
            srv_ucm_act_request(act_op, check_act_req, NULL, NULL);
        }

        if (srv_speech_is_phone_mute() == MMI_FALSE && SRV_UCM_STOP_DTMF_ACT == act_op)
        {
            srv_gpio_set_device_mute(SRV_GPIO_AUDDEV_MISROPHONE, MMI_FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_save_phonebook
 * DESCRIPTION
 *  Entry function of saving number to Phonebook
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_save_phonebook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id dialer_parent_gid = mmi_frm_group_get_active_id();
    dialer_parent_gid = mmi_frm_group_get_top_parent_group_id(dialer_parent_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((GRP_ID_UCM_MO != dialer_parent_gid) &&
        (GRP_ID_UCM_MT != dialer_parent_gid) &&
        (GRP_ID_UCM_INCALL != dialer_parent_gid))

    {
        MMI_ASSERT(0);
    }
    /* save dtmf digits to phonebook in call */
    if (mmi_frm_scrn_is_present(dialer_parent_gid, SCR_ID_UCM_DTMF_EDITOR, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_ucm_save_number_to_phonebook(g_ucm_p->call_misc.disp_dtmf, dialer_parent_gid);
    }
#if defined (__MMI_VOIP__)    
    /* save uri address to phonebook in call */
    else if (mmi_frm_scrn_is_present(dialer_parent_gid, SCR_ID_UCM_VOIP_DIALER, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {  
        mmi_ucm_save_voip_num_to_phonebook((U16*)g_ucm_p->mo_info.dial_pad_buffer, dialer_parent_gid);
    }
#endif /* __MMI_VOIP__ */
    else
    {   
        mmi_ucm_save_number_to_phonebook((U16*)g_ucm_p->mo_info.dial_pad_buffer, dialer_parent_gid);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_loud_speaker
 * DESCRIPTION
 *  Turn on and turn off loud speaker in call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_loud_speaker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str = 0;
#ifdef __MMI_UCM_RSK_MUTE__
    U16 icon = 0;
#endif /* __MMI_UCM_RSK_MUTE__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_get_audio_mode() == AUD_MODE_LOUDSPK) /* O */
    {
        str = STR_ID_UCM_HAND_FREE;
    #ifdef __MMI_UCM_RSK_MUTE__
        icon = IMG_ID_UCM_H_FREE;
    #endif /* __MMI_UCM_RSK_MUTE__ */
        srv_speech_disable_hand_free();
    }
    else
    {
        str = STR_ID_UCM_HAND_HELD;
    #ifdef __MMI_UCM_RSK_MUTE__
        icon = IMG_ID_UCM_H_HELD;
    #endif /* __MMI_UCM_RSK_MUTE__ */
        srv_speech_enable_hand_free();
    }

    if (MMI_TRUE == srv_ucm_is_outgoing_call())
    {
        ChangeLeftSoftkey(str, 0);
    }
    else
    {
    #ifdef __MMI_UCM_RSK_MUTE__
        ChangeCenterSoftkey(0, icon); /* set H-Free icon */
    #else /* __MMI_UCM_RSK_MUTE__ */
        ChangeRightSoftkey(str, 0);
    #endif /* __MMI_UCM_RSK_MUTE__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_loud_speaker_during_outgoing_call
 * DESCRIPTION
 *  Turn on and turn off loud speaker during outgoing call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_loud_speaker_during_outgoing_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (mdi_audio_get_audio_mode() == AUD_MODE_LOUDSPK) /* O */
    {
        srv_speech_disable_hand_free();
    }
    else 
    {
        srv_speech_enable_hand_free();
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_exit_in_call
 * DESCRIPTION
 *  Exit function of in call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_exit_in_call(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef  __MMI_FTE_SUPPORT__
    StopTimer(UCM_FTE_AUTO_LOCK_TIMER_ID);
#endif /* __MMI_FTE_SUPPORT__ */
    
#ifdef  __MMI_TOUCH_SCREEN__
    ResetCenterSoftkey();
#endif 

#ifdef __MMI_BT_SUPPORT__
    mmi_ucm_reset_bt_notify();
#endif /* __MMI_BT_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_highlight_in_call_item
 * DESCRIPTION
 *  Highlight index in the active call screen.
 * PARAMETERS
 *  index       [IN]        Current highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_highlight_in_call_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_index_info_struct index_info;
    srv_ucm_call_info_struct call_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->call_misc.hilite_index = index;
    mmi_ucm_set_hilight_index(g_ucm_p->call_misc.hilite_tab, g_ucm_p->call_misc.hilite_index);
    index_info.call_index =  g_ucm_p->call_misc.hilite_index;
    index_info.group_index = g_ucm_p->call_misc.hilite_tab;
    srv_ucm_query_call_data(index_info, &call_info);
    
    wgui_cat403_set_duration(&(call_info.start_time));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_tab_jump
 * DESCRIPTION
 *  Jump to tab based on index for Category403.
 * PARAMETERS
 *  index       [IN]        Current highlight tab
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_tab_jump(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_group_info_struct group_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->call_misc.hilite_tab = index;

    if (srv_ucm_query_group_data(g_ucm_p->call_misc.hilite_tab, &group_info) <= 0)
    {
        MMI_ASSERT(0);
    }
    
    while (group_info.call_type & MMI_UCM_CALL_TYPE_WO_INCALL_SCR)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_TAB_JUMP_SKIP);
        if (g_ucm_p->call_misc.hilite_tab == srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) - 1)
        {
            g_ucm_p->call_misc.hilite_tab = 0;
        }
        else
        {
            g_ucm_p->call_misc.hilite_tab++;
        }        
    }

    g_ucm_p->call_misc.hilite_index = 0;
    mmi_ucm_set_hilight_index(g_ucm_p->call_misc.hilite_tab, g_ucm_p->call_misc.hilite_index);
    mmi_ucm_enter_in_call();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_tab_prev
 * DESCRIPTION
 *  Move to previous tab for Category403.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_tab_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_group_info_struct group_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_misc.hilite_tab == 0)
    {
        g_ucm_p->call_misc.hilite_tab = srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) - 1;
    }
    else
    {
        g_ucm_p->call_misc.hilite_tab--;
    }
    
    srv_ucm_query_group_data(g_ucm_p->call_misc.hilite_tab, &group_info);
    
    while (group_info.call_type & MMI_UCM_CALL_TYPE_WO_INCALL_SCR)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_TAB_PREV_SKIP);
        if (g_ucm_p->call_misc.hilite_tab == 0)
        {
            g_ucm_p->call_misc.hilite_tab = srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) - 1;
        }
        else
        {
            g_ucm_p->call_misc.hilite_tab--;
        }
    }
    
    g_ucm_p->call_misc.hilite_index = 0;
    mmi_ucm_set_hilight_index(g_ucm_p->call_misc.hilite_tab, g_ucm_p->call_misc.hilite_index);
    mmi_ucm_enter_in_call();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_tab_next
 * DESCRIPTION
 *  Move to next tab for Category403.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_tab_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_group_info_struct group_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_misc.hilite_tab == srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) - 1)
    {
        g_ucm_p->call_misc.hilite_tab = 0;
    }
    else
    {
        g_ucm_p->call_misc.hilite_tab++;
    }

    srv_ucm_query_group_data(g_ucm_p->call_misc.hilite_tab, &group_info);
    while (group_info.call_type & MMI_UCM_CALL_TYPE_WO_INCALL_SCR)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_TAB_NEXT_SKIP);
        if (g_ucm_p->call_misc.hilite_tab == srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) - 1)
        {
            g_ucm_p->call_misc.hilite_tab = 0;
        }
        else
        {
            g_ucm_p->call_misc.hilite_tab++;
        }
    }
    g_ucm_p->call_misc.hilite_index = 0;
    mmi_ucm_set_hilight_index(g_ucm_p->call_misc.hilite_tab, g_ucm_p->call_misc.hilite_index);
    mmi_ucm_enter_in_call();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_tab_highlight
 * DESCRIPTION
 *  Adjust highlight tab for Category403.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_tab_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 group_id = 0;
    S32 init_tab_id = 0;
	srv_ucm_group_info_struct group_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    group_id = mmi_ucm_get_group_index_by_call_state_and_type(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_NO_CSD);        
    
    /* active call exists, highlight on active call */
    if (group_id != -1)
    {
        g_ucm_p->call_misc.hilite_tab = group_id;
        g_ucm_p->call_misc.hilite_index = 0;
    }
    /* no active call, highlight on original call */
    else
    {
        /* original call doesn't exist, highlight on last call */
        if (g_ucm_p->call_misc.hilite_tab > srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) - 1)
        {
            g_ucm_p->call_misc.hilite_tab = srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) - 1;
            g_ucm_p->call_misc.hilite_index = 0;
        }
    }

    /* ex. 1MT or 1 MO */
    if (g_ucm_p->call_misc.hilite_tab < 0)
    {
        mmi_ucm_set_hilight_index(g_ucm_p->call_misc.hilite_tab, g_ucm_p->call_misc.hilite_index);
        return;
    }
    
    init_tab_id = g_ucm_p->call_misc.hilite_tab;
	
	srv_ucm_query_group_data(g_ucm_p->call_misc.hilite_tab, &group_info);
	
    while (group_info.call_type & MMI_UCM_CALL_TYPE_WO_INCALL_SCR)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_TAB_HIGHLIGHT_SKIP);
        if (g_ucm_p->call_misc.hilite_tab == srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) - 1)
        {
            g_ucm_p->call_misc.hilite_tab = 0;
        }
        else
        {
            g_ucm_p->call_misc.hilite_tab++;
        }

        /* no call needs incall screen */
        if (init_tab_id == g_ucm_p->call_misc.hilite_tab)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_TAB_HIGHLIGHT_NO_CALL);
            break;
        }
    }
    mmi_ucm_set_hilight_index(g_ucm_p->call_misc.hilite_tab, g_ucm_p->call_misc.hilite_index);
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_TAB_HIGHLIGHT_CURRENT, g_ucm_p->call_misc.hilite_tab);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_highlight_multi_held_call_item
 * DESCRIPTION
 *  Highlight index in the mutliple held calls screen.
 * PARAMETERS
 *  index       [IN]        Current highlight index.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_highlight_multi_held_call_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->call_misc.hilite_multi_held_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_held_call_selected_for_swap
 * DESCRIPTION
 *  entry held call select screen for swap action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_held_call_selected_for_swap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_multiple_group_act_req_struct check_act_req_multiple;
    S32 group_index_array[SRV_UCM_MAX_GROUP];
    srv_ucm_group_info_struct group_info;
    srv_ucm_result_enum permit_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    /*get held call*/
    if (srv_ucm_query_group_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_NO_DATA_CSD, MMI_FALSE, group_index_array) <= g_ucm_p->call_misc.hilite_multi_held_index)
    {
        MMI_ASSERT(0);
    }

    MMI_ASSERT(g_ucm_p->call_misc.hilite_multi_held_index < SRV_UCM_MAX_GROUP);
    
    srv_ucm_query_group_data(group_index_array[g_ucm_p->call_misc.hilite_multi_held_index], &group_info);
    
    check_act_req_multiple.other_call_type = group_info.call_type;
    check_act_req_multiple.other_group = group_info.group_id;

    /*get active call*/
    srv_ucm_query_group_data(g_ucm_p->call_misc.hilite_tab, &group_info);
    check_act_req_multiple.active_call_type = group_info.call_type;
    check_act_req_multiple.active_group = group_info.group_id;

    permit_result = srv_ucm_query_act_permit(SRV_UCM_SWAP_ACT, &check_act_req_multiple);

    if (SRV_UCM_RESULT_OK == permit_result)
    {
        srv_ucm_act_request(SRV_UCM_SWAP_ACT, &check_act_req_multiple, NULL, mmi_ucm_act_callback);        
    }
    else
    {
        mmi_ucm_display_error_popup(permit_result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_held_call_selected_for_conf
 * DESCRIPTION
 *  entry held call select screen for conference action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_held_call_selected_for_conf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_multiple_group_act_req_struct check_act_req_multiple;
    S32 group_index_array[SRV_UCM_MAX_GROUP];
    srv_ucm_group_info_struct group_info;
    srv_ucm_result_enum permit_result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* get held call */
    if (srv_ucm_query_group_count(SRV_UCM_HOLD_STATE, SRV_UCM_VOIP_CALL_TYPE, MMI_TRUE, group_index_array) <= g_ucm_p->call_misc.hilite_multi_held_index)
    {
        MMI_ASSERT(0);
    }
    MMI_ASSERT(g_ucm_p->call_misc.hilite_multi_held_index < SRV_UCM_MAX_GROUP);
    srv_ucm_query_group_data(group_index_array[g_ucm_p->call_misc.hilite_multi_held_index], &group_info);
    
    check_act_req_multiple.other_call_type = group_info.call_type;
    check_act_req_multiple.other_group = group_info.group_id;

    /* get active call */
    srv_ucm_query_group_data(g_ucm_p->call_misc.hilite_tab, &group_info);
    check_act_req_multiple.active_call_type = group_info.call_type;
    check_act_req_multiple.active_group = group_info.group_id;

    permit_result = srv_ucm_query_act_permit(SRV_UCM_CONFERENCE_ACT, &check_act_req_multiple);

    if (SRV_UCM_RESULT_OK == permit_result)
    {
        srv_ucm_act_request(SRV_UCM_CONFERENCE_ACT, &check_act_req_multiple, NULL, mmi_ucm_act_callback);        
    }
    else
    {
        mmi_ucm_display_error_popup(permit_result);
    }
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_call_end_pen_down_handler
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  point   [IN]  pen event
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_ucm_call_end_pen_down_handler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_scrn_close_active_id();
    return MMI_TRUE;
}
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_exit_call_end
 * DESCRIPTION
 *  This just stops timer which was started in the entry function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_exit_call_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(UCM_NOTIFY_DURATION_TIMER);
    mmi_frm_end_scenario(MMI_SCENARIO_ID_DEFAULT);

    if (g_ucm_p->call_end_tone_id == TONE_BUSY_CALL_GSM)
    {
        srv_prof_stop_tone(SRV_PROF_TONE_GSM_BUSY);     
    }
    else if (g_ucm_p->call_end_tone_id > 0) 
    {
        srv_prof_stop_tone((srv_prof_tone_enum)g_ucm_p->call_end_tone_id);
    }
#ifdef __MMI_BT_CALL_SUPPORT__
    mmi_ucm_go_back_BT_call_screen_bt();
#endif /* __MMI_BT_CALL_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_call_end_timeout_handler
 * DESCRIPTION
 *  ucm call end timeout handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_call_end_timeout_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(UCM_NOTIFY_DURATION_TIMER);
    mmi_frm_group_close(GRP_ID_UCM_CALL_END);
#ifdef __MMI_BT_CALL_SUPPORT__
    mmi_ucm_go_back_BT_call_screen_bt();
#endif /* __MMI_BT_CALL_SUPPORT__ */
}


#ifdef __MMI_UCM_TRANSFER__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_transfer
 * DESCRIPTION
 *  Transfer function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_transfer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((CHAR*)g_ucm_p->mo_info.dial_pad_buffer) == 0)
    {
        mmi_popup_display_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, NULL);
        return;
    }
    mmi_ucm_set_number_info(g_ucm_p->mo_info.dial_pad_buffer);
    mmi_ucm_transfer_action();
}
#endif /* __MMI_UCM_TRANSFER__ */


#ifdef __MMI_UCM_DEFLECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_deflect
 * DESCRIPTION
 *  Deflect function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_deflect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((CHAR*)g_ucm_p->mo_info.dial_pad_buffer) == 0)
    {
        mmi_popup_display_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, NULL);
        return;
    }
    mmi_ucm_set_number_info(g_ucm_p->mo_info.dial_pad_buffer);
    mmi_ucm_deflect_action();
}
#endif /* __MMI_UCM_DEFLECT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_replace
 * DESCRIPTION
 *  Deflect function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_replace(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_replace_option(MMI_UCM_EXEC_IF_PERMIT_PASS);
    mmi_ucm_display_error_popup(option_check_result);
}


#ifdef __MMI_UCM_REDIAL_FROM_OTHER_SIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_redial_from_other_sim
 * DESCRIPTION
 *  Redial from other sim function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_redial_from_other_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_redial_from_other_sim_option(MMI_UCM_EXEC_IF_PERMIT_PASS);
    mmi_ucm_display_error_popup(option_check_result);
}
#endif /* __MMI_UCM_REDIAL_FROM_OTHER_SIM__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_confirm_screen_delete_proc
 * DESCRIPTION
 *  This function is a leave proc for confirm screen
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_confirm_screen_delete_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_CONFIRM_DELETE_CALLBACK);
            mmi_ucm_execute_confirm_hdlr(SRV_UCM_QUERY_CNF_ABORT);
        }
        break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_confirm_hdlr_yes
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_confirm_hdlr_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    mmi_ucm_execute_confirm_hdlr(SRV_UCM_QUERY_CNF_YES);
}
    

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_confirm_hdlr_no
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_confirm_hdlr_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    mmi_ucm_execute_confirm_hdlr(SRV_UCM_QUERY_CNF_NO);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_confirm_hdlr_sendkey
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_confirm_hdlr_sendkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_CONFIRM, g_ucm_p->cnf_scr.scrn_id, (mmi_proc_func) NULL);
    mmi_frm_group_close(GRP_ID_UCM_CONFIRM);
    mmi_ucm_execute_confirm_hdlr(SRV_UCM_QUERY_CNF_YES);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_confirm_hdlr_endkey
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_confirm_hdlr_endkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    mmi_ucm_end_key();
    mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_CONFIRM, g_ucm_p->cnf_scr.scrn_id, (mmi_proc_func) NULL);
    mmi_frm_group_close(GRP_ID_UCM_CONFIRM);
    mmi_ucm_execute_confirm_hdlr(SRV_UCM_QUERY_CNF_TOTAL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_execute_confirm_hdlr
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_execute_confirm_hdlr(srv_ucm_query_cnf_result_enum cnf_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    srv_ucm_query_cnf_struct query_cnf_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_EXECUTE_CONFIRM_HDLR, cnf_result, -1);
    query_cnf_result.result_info = cnf_result;

    if ((g_ucm_p->cnf_scr.conf_ind_cb != NULL) &&
        (query_cnf_result.result_info < SRV_UCM_QUERY_CNF_TOTAL))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_EXECUTE_CONFIRM_HDLR_EXECUTE);
        g_ucm_p->cnf_scr.conf_ind_cb(SRV_UCM_QUERY_CNF, &query_cnf_result);
    }

    g_ucm_p->cnf_scr.scrn_id = SCR_ID_INVALID;
    if (g_ucm_p->cnf_scr.content != NULL)
    {
        OslMfree(g_ucm_p->cnf_scr.content);
        g_ucm_p->cnf_scr.content = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_processing_screen_internal
 * DESCRIPTION
 *  General entry function of processing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_processing_screen(MMI_ID SG_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID inserted_SG_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_PROCESSING_SCRN_P1, SG_id);
#if defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
    if (!mmi_frm_group_is_present(GRP_ID_UCM_INT_MARKER))
    {
        mmi_ucm_sg_create(GRP_ID_ROOT, GRP_ID_UCM_INT_MARKER);
        /* need add processing scrn to active group, then user can see processing screen */
        inserted_SG_id = GRP_ID_UCM_INT_MARKER;    
    }
    else
#endif /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */
    if ((GRP_ID_UCM_CONFIRM == SG_id) || (GRP_ID_UCM_MT == SG_id) || 
        (GRP_ID_UCM_MO == SG_id) || (GRP_ID_UCM_INCALL == SG_id) ||
    #ifdef __MMI_VIDEO_TELEPHONY__
        (GRP_ID_UCM_VT == SG_id) ||
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        MMI_FALSE)
    {
        inserted_SG_id = SG_id;
    }
    else
    {
        if (mmi_frm_group_is_present(GRP_ID_UCM_CONFIRM))
        {
            inserted_SG_id = GRP_ID_UCM_CONFIRM;
        }
        else if (mmi_frm_group_is_present(GRP_ID_UCM_MT))
        {
            inserted_SG_id = GRP_ID_UCM_MT;
        }
        else if (mmi_frm_group_is_present(GRP_ID_UCM_MO))
        {
            inserted_SG_id = GRP_ID_UCM_MO;
        }
        else if (mmi_frm_group_is_present(GRP_ID_UCM_INCALL))
        {
            inserted_SG_id = GRP_ID_UCM_INCALL;
        }
    #ifdef __MMI_VIDEO_TELEPHONY__    
        else if (mmi_frm_group_is_present(GRP_ID_UCM_VT))
        {
            inserted_SG_id = GRP_ID_UCM_VT;
        }
    #endif /* __MMI_VIDEO_TELEPHONY__ */
        else
        {
            inserted_SG_id = GRP_ID_INVALID;
        }
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_PROCESSING_SCRN_NEW_P1, inserted_SG_id);
    }

    if (GRP_ID_INVALID != inserted_SG_id)
    {
        mmi_ucm_enter_processing_screen_internal(inserted_SG_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_pre_enter_processing_screen
 * DESCRIPTION
 *  Initial parameter and enter processing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_pre_enter_processing_screen(srv_ucm_act_opcode_enum act_op, MMI_ID SG_id)
{

    mmi_ucm_set_processing_parameter(
        mmi_ucm_get_title_string_by_action(act_op),
        STR_ID_UCM_PROCESSING,
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        0,
        0,
        0,
        0,
        0,
        mmi_ucm_end_all_processing_action);

    mmi_ucm_enter_processing_screen(SG_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_adjust_scrn_when_incall_exist
 * DESCRIPTION
 *  back to incall scrn in different cases when incall scrn already exists.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_adjust_scrn_when_incall_exist(srv_ucm_call_type_enum active_call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID scrn_id = SCR_ID_INVALID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
    if (mmi_frm_group_is_present(GRP_ID_UCM_INT_MARKER))
    {
        mmi_ucm_delete_up_to_sg_id(GRP_ID_UCM_INT_MARKER, MMI_TRUE, MMI_TRUE);
    #ifdef __MMI_VIDEO_TELEPHONY__
        if (active_call_type & SRV_UCM_VIDEO_CALL_TYPE_ALL)
        {
            mmi_ucm_vt_adjust_screen_when_call_end_callback();
        }
    #endif /* __MMI_VIDEO_TELEPHONY__ */
    }
    else
#endif /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */

#ifdef __MMI_VIDEO_TELEPHONY__
    if (active_call_type & SRV_UCM_VIDEO_CALL_TYPE_ALL)
    {
        mmi_ucm_delete_up_to_sg_id(GRP_ID_UCM_VT, MMI_FALSE, MMI_TRUE);
        scrn_id = mmi_frm_scrn_get_neighbor_id(GRP_ID_UCM_VT, SCR_ID_INVALID, MMI_FRM_NODE_AT_LATEST_FLAG);
        mmi_frm_scrn_multiple_close(GRP_ID_UCM_VT, scrn_id, MMI_TRUE, 0, SCR_ID_UCM_VT_INCALL, MMI_FALSE); 
    }
    else
#endif /* __MMI_VIDEO_TELEPHONY__ */
    {
        mmi_ucm_delete_up_to_sg_id(GRP_ID_UCM_INCALL, MMI_FALSE, MMI_TRUE);
        scrn_id = mmi_frm_scrn_get_neighbor_id(GRP_ID_UCM_INCALL, SCR_ID_INVALID, MMI_FRM_NODE_AT_LATEST_FLAG);
        mmi_frm_scrn_multiple_close(GRP_ID_UCM_INCALL, scrn_id, MMI_TRUE, 0, SCR_ID_UCM_IN_CALL, MMI_FALSE);         
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_group_id
 * DESCRIPTION
 *  only for the scrn which is only single existence in the whole tree.  
 * PARAMETERS
 *  MMI_ID: scrn ID
 * RETURNS
 *  MMI_ID: group ID
 *****************************************************************************/
MMI_ID mmi_ucm_get_group_id(MMI_ID check_scrn_id, mmi_node_present_flag flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_is_present(GRP_ID_UCM_CONFIRM, check_scrn_id, flag))
    {
        return GRP_ID_UCM_CONFIRM;
    }
    
    if (mmi_frm_scrn_is_present(GRP_ID_UCM_MT, check_scrn_id, flag))
    {
        return GRP_ID_UCM_MT;
    }

    if (mmi_frm_scrn_is_present(GRP_ID_UCM_MO, check_scrn_id, flag))
    {
        return GRP_ID_UCM_MO;
    }

#if defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
    if (mmi_frm_scrn_is_present(GRP_ID_UCM_INT_MARKER, check_scrn_id, flag))
    {
        return GRP_ID_UCM_INT_MARKER;
    }
#endif /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */

    if (mmi_frm_scrn_is_present(GRP_ID_UCM_INCALL, check_scrn_id, flag))
    {
        return GRP_ID_UCM_INCALL;
    }

#ifdef __MMI_VIDEO_TELEPHONY__
    if (mmi_frm_scrn_is_present(GRP_ID_UCM_VT, check_scrn_id, flag))
    {
        return GRP_ID_UCM_VT;
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

    return GRP_ID_INVALID;
}


#ifdef __MMI_VIDEO_TELEPHONY__

static MMI_RET mmi_ucm_vt_call_launch_proc(mmi_event_struct *evt)
{
	switch (evt->evt_id)
	{
		case EVT_ID_ASM_POST_PREPARED:
			mmi_ucm_vt_enter_in_call();
			mmi_frm_group_close(APP_VT_CALL);
		break;

		case EVT_ID_DELETE_DANGLE_GROUP_REQ:
			return MMI_RET_ERR;
	}
	return MMI_RET_OK;
}


static MMI_RET mmi_ucm_vt_dummy_screen_proc(mmi_event_struct *evt)
{
	if (evt->evt_id == EVT_ID_SCRN_ACTIVE)
	{
		mmi_frm_scrn_active_evt_struct *p = (mmi_frm_scrn_active_evt_struct *)evt;
		if (p->is_first_active == MMI_FALSE)
		{
			U32 mem_size = mmi_frm_app_get_base_mem_size(APP_VT_CALL) + mmi_frm_app_get_fg_mem_size(APP_VT_CALL);
			mmi_frm_scrn_clear_attribute(GRP_ID_UCM_VT, SCR_ID_DUMMY, MMI_SCRN_ATTRIB_ADD_HISTORY);
			mmi_frm_asm_prepare(APP_VT_CALL, mem_size, mmi_ucm_vt_call_launch_proc, NULL, MMI_FRM_ASM_F_FORCE_PREPARE);
		}
	}
	return MMI_RET_OK;
}


static MMI_RET mmi_ucm_vt_post_prepare_proc(mmi_event_struct *evt)
{
	if (mmi_frm_group_is_in_active_serial(GRP_ID_UCM_VT))
	{
		U32 mem_size = mmi_frm_app_get_base_mem_size(APP_VT_CALL) + mmi_frm_app_get_fg_mem_size(APP_VT_CALL);
		mmi_frm_asm_prepare(APP_VT_CALL, mem_size, mmi_ucm_vt_call_launch_proc, NULL, MMI_FRM_ASM_F_FORCE_PREPARE);
		mmi_frm_scrn_close(GRP_ID_UCM_VT, SCR_ID_DUMMY);
	}
	return MMI_RET_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_go_back_screen_check
 * DESCRIPTION
 *  Go back to screen based on current state.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_go_back_screen_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID sg_id = GRP_ID_INVALID;
    MMI_ID scrn_id = SCR_ID_INVALID;
    U16 curr_scr_id = mmi_frm_scrn_get_active_id();
    srv_ucm_call_type_enum incall_type = (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_VOIP_CALL_TYPE | SRV_UCM_DATA_CALL_TYPE_ALL | SRV_UCM_VIDEO_CALL_TYPE_ALL);
    srv_ucm_group_info_struct group_info;
    S32 group_index;
    srv_ucm_call_type_enum active_call_type = (srv_ucm_call_type_enum)0; /* Just for Video call type check. */   
#ifdef __MMI_VIDEO_TELEPHONY__  
    MMI_BOOL need_keep_setting = MMI_FALSE;
    mmi_ucm_vt_incall_screen_mode_enum kept_mode;
#endif /* __MMI_VIDEO_TELEPHONY__ */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* pending action exists, do not adjust history */
    if (MMI_FALSE == srv_ucm_is_pending_action())
    {
        if (srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) > 0)
        {
            mmi_ucm_tab_highlight();
            
            MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_UCM_MT));
            if (!mmi_frm_scrn_is_present(GRP_ID_UCM_MT, SCR_ID_UCM_INCOMING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
            {
                mmi_ucm_enter_incoming_call();
            }
            
            /* Want to show MT scrn, stop processing action here - only MT processing is possible */
            /* Put the deletion before mmi_ucm_delete_common_screens is because processing scrn will be deleted in mmi_ucm_delete_common_screens */
            if (SCR_ID_UCM_PROCESSING == mmi_frm_scrn_get_active_id())
            {
                mmi_frm_scrn_multiple_close(GRP_ID_UCM_MT, SCR_ID_UCM_PROCESSING, MMI_TRUE, 0, SCR_ID_UCM_INCOMING, MMI_FALSE);
            }

            mmi_frm_group_close(GRP_ID_UCM_MO); /* MO MT won't co-exist */  
            mmi_ucm_delete_common_screens();

        #ifndef __MMI_UCM_SLIM__
            /* Delete SCR_ID_UCM_INCOMING_OPTION , SCR_ID_UCM_IN_CALL_OPTION. ps. SCR_ID_UCM_OUTGOING_OPTION is deleted when close MO scrn in MO group */          
            mmi_ucm_close_cui(&g_ucm_p->cui_info.incoming_opt_cui_id);
        #endif /* __MMI_UCM_SLIM__ */
            mmi_ucm_close_cui(&g_ucm_p->cui_info.incall_opt_cui_id);
        }
        else if (srv_ucm_query_group_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) > 0)
        {
            mmi_ucm_tab_highlight();

            MMI_ASSERT(MMI_FALSE == mmi_frm_group_is_present(GRP_ID_UCM_PRE_MO));
            MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_UCM_MO));
            /* if outgoing call scrn is not in history and not current scrn */
            if (!mmi_frm_scrn_is_present(GRP_ID_UCM_MO, SCR_ID_UCM_OUTGOING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
            {
                mmi_ucm_enter_outgoing_call();
            }
            
            /* Want to show MT scrn, stop processing action here - only MO processing is possible */
            if (SCR_ID_UCM_PROCESSING == mmi_frm_scrn_get_active_id()) 
            {
                mmi_frm_scrn_multiple_close(GRP_ID_UCM_MO, SCR_ID_UCM_PROCESSING, MMI_TRUE, 0, SCR_ID_UCM_OUTGOING, MMI_FALSE);
            }            
            mmi_frm_group_close(GRP_ID_UCM_MT); /* MO MT won't co-exist */
            mmi_ucm_delete_common_screens(); /* not use close MO and re-create MO every time, ex. just call end popup, no need to refresh mo */           

        #ifndef __MMI_UCM_SLIM__
            mmi_ucm_close_cui(&g_ucm_p->cui_info.outgoing_opt_cui_id);
        #endif /* __MMI_UCM_SLIM__ */
        }
        else
        {
            mmi_ucm_tab_highlight(); /* no matter call exists or not, adjust tab highlight */
            
            if (srv_ucm_query_group_count(SRV_UCM_CALL_STATE_CONNECTED, incall_type, MMI_FALSE, NULL) > 0)
            {
                /* Just for Video call type check, because video can not be held, so only use active_state to query here */
                group_index = mmi_ucm_get_group_index_by_call_state_and_type(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL);
               
                if (group_index != -1)
                {
                    srv_ucm_query_group_data(group_index, &group_info);
                    active_call_type = group_info.call_type;
                }

            #ifdef __MMI_VIDEO_TELEPHONY__
                if (active_call_type & SRV_UCM_VIDEO_CALL_TYPE_ALL)
                {
                    kept_mode = mmi_ucm_vt_get_incall_screen_mode();
                    /* delete VT preview screens before entering VT incall screen*/                
                #if defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
                    if (mmi_ucm_check_if_sg_older(GRP_ID_UCM_VT, GRP_ID_UCM_INT_MARKER) && 
                #else /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)  */    
                    if (mmi_ucm_check_if_sg_older(GRP_ID_UCM_VT, GRP_ID_UCM_MARKER) &&
                #endif /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)  */    
                        MMI_UCM_VT_INCALL_SCREEN_MODE_INCALL != kept_mode)
                    {
                        /* keep the setting which is modified in preview mode. close group will trigger this setting changed */
                        
                        if (MMI_UCM_VT_INCALL_SCREEN_MODE_PREVIEW_ONLY == kept_mode)
                        {
                            need_keep_setting = MMI_TRUE;
                        }
                        mmi_frm_group_close(GRP_ID_UCM_VT);
                        /* keep the setting which is modified in preview mode*/
                        if (need_keep_setting)
                        {
                            mmi_ucm_vt_set_incall_screen_mode(kept_mode);
                        }
                    }

                    /* for non-background call only, because for bgcall, the case is already included in upper part 
                       it's for MED part rule - should entry new screen for each call, 
                       case: 1 VT +  1 MT VT, replace -> CM/VT_incall/MT, can not reuse orig VT_incall, need
                       to delete it first and entry again to trigger MED part to deinit and init 
                       here also add check "MMI_UCM_VT_INCALL_SCREEN_MODE_NONE"-> not delete scrn for MT end cases */                     
                #if !defined(__MMI_BACKGROUND_CALL__) || defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
                    if (kept_mode == MMI_UCM_VT_INCALL_SCREEN_MODE_NONE) 
                    {
                        mmi_frm_group_close(GRP_ID_UCM_VT);
                    }
                #endif /* !defined(__MMI_BACKGROUND_CALL__) || defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */
                
                    if (!mmi_frm_group_is_present(GRP_ID_UCM_VT))
                    {
                        /* mmi_ucm_vt_init_incall_setting(); */
                        /* Normal case: if other ap's screen is covered, not covre it, just add to history 
                           But VT screen cannot be inserted in history, will fatal. So always show VT screen.
                           If VT modify the limitation, can use below code again. */
                        
                        /*if (MMI_FALSE == mmi_ucm_is_ucm_sg(mmi_frm_group_get_active_id()))
                        {
                            mmi_ucm_add_incall_sg_scrn(active_call_type, mmi_frm_group_get_active_id(), MMI_FRM_NODE_BEFORE_FLAG);
                            g_ucm_p->vt_cntx.incall_screen.mode = MMI_UCM_VT_INCALL_SCREEN_MODE_INCALL;                            
                        }
                        else*/
                        {
							U32 mem_size = mmi_frm_app_get_base_mem_size(APP_VT_CALL) + mmi_frm_app_get_fg_mem_size(APP_VT_CALL);
                            mmi_ucm_sg_create(GRP_ID_ROOT, GRP_ID_UCM_VT);
							mmi_frm_group_create(GRP_ID_ROOT, APP_VT_CALL, mmi_ucm_vt_call_launch_proc, NULL);

							if (mmi_frm_asm_check_enough(APP_VT_CALL, mem_size) == MMI_FALSE)
							{
								mmi_event_struct evt;
								MMI_FRM_INIT_EVENT(&evt, 0);
								MMI_FRM_POST_EVENT(&evt, mmi_ucm_vt_post_prepare_proc, NULL);
								mmi_frm_scrn_create(GRP_ID_UCM_VT, SCR_ID_DUMMY, mmi_ucm_vt_dummy_screen_proc, NULL);
							}
							else
							{
								mmi_ucm_vt_enter_in_call();
								mmi_frm_group_close(APP_VT_CALL);
							}
						}
                    }
                    /* force to add processing screen to history when current screen is processing screen.
                       it is to prevent no popup case so that processing screen is not deleted */
                    else if ((curr_scr_id == SCR_ID_UCM_PROCESSING) || (curr_scr_id == SCR_ID_UCM_OUTGOING))
                    {
                        mmi_ucm_adjust_scrn_when_incall_exist(active_call_type);
                    }
                }
                else
            #endif /* __MMI_VIDEO_TELEPHONY__ */
                {
                /* When there is voice active/held call, should not enter the VT screen.
                   ex: If 1A video call + 1MT voice call, end the video call, and then accept the voice call, should
                   close the VT screen.
                   ex: If enter VT preview + 1MT voice call, accept the voice call, should close the VT preview when 
                   background call case. */
                #ifdef __MMI_VIDEO_TELEPHONY__
                #if defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
                    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) == 0)    
                    {                   
                        mmi_frm_group_close(GRP_ID_UCM_VT);
                    }
                #else /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */
                    if (MMI_UCM_VT_INCALL_SCREEN_MODE_NONE == mmi_ucm_vt_get_incall_screen_mode()) 
                    {
                        mmi_frm_group_close(GRP_ID_UCM_VT);
                    }
                #endif /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */
                #endif /* __MMI_VIDEO_TELEPHONY__ */
                    
                    /* if active scrn is SCR_ID_UCM_IN_CALL, need update scrn, should run the flow. so use MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG here */
                    if (!mmi_frm_scrn_is_present(GRP_ID_UCM_INCALL, SCR_ID_UCM_IN_CALL, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
                    {
                    #if defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
                        if (mmi_frm_group_is_present(GRP_ID_UCM_INT_MARKER)) /* means "first" MO or MT --> incall or none */
                        {
                            /*if bgcall, need to add incall above idle group and back to previous app scrn */
                            MMI_ASSERT(mmi_frm_group_is_present(GRP_ID_UCM_MARKER));
                            mmi_ucm_add_incall_sg_scrn(active_call_type, GRP_ID_UCM_MARKER, MMI_FRM_NODE_AFTER_FLAG);            
             
                            mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_INCALL, SCR_ID_UCM_IN_CALL, mmi_ucm_in_call_screen_delete_proc);

                            if (GRP_ID_UCM_CALL_END == mmi_frm_group_get_active_id())
                            {
                                mmi_ucm_delete_up_to_sg_id(GRP_ID_UCM_INT_MARKER, MMI_FALSE, MMI_FALSE);
                            }
                            else
                            {
                                mmi_ucm_delete_up_to_sg_id(GRP_ID_UCM_INT_MARKER, MMI_TRUE, MMI_TRUE);
                            #ifdef __MMI_VIDEO_TELEPHONY__
                                if (!(active_call_type & SRV_UCM_VIDEO_CALL_TYPE_ALL))
                                {
                                    mmi_ucm_vt_adjust_screen_when_call_end_callback();
                                }
                            #endif /* __MMI_VIDEO_TELEPHONY__ */
                            }
                        }
                        else
                    #endif /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */
                        /* for CSD case. ex. 1 CSD + 1 MT voice. End all and accept */
                        if (GRP_ID_UCM_CALL_END == mmi_frm_group_get_active_id())
                        {
                            mmi_ucm_delete_up_to_sg_id(GRP_ID_UCM_MARKER, MMI_FALSE, MMI_FALSE);
                            mmi_ucm_add_incall_sg_scrn(active_call_type, GRP_ID_UCM_CALL_END, MMI_FRM_NODE_BEFORE_FLAG);
                        }
                        else
                        {
                            mmi_ucm_sg_create(GRP_ID_ROOT, GRP_ID_UCM_INCALL);
                            
                            mmi_ucm_enter_in_call();
                            mmi_ucm_delete_up_to_sg_id(GRP_ID_UCM_MARKER, MMI_FALSE, MMI_FALSE);
                        }

                    }
                    /* force to add processing screen to history when current screen is processing screen.
                       it is to prevent no popup case so that processing screen is not deleted */
                    else if ((SCR_ID_UCM_PROCESSING == mmi_frm_scrn_get_active_id()) || (SCR_ID_UCM_OUTGOING == mmi_frm_scrn_get_active_id()))
                    {
                        mmi_ucm_adjust_scrn_when_incall_exist(active_call_type);
                    }
                #ifdef __MMI_BACKGROUND_CALL_WITH_NCENTER__
                    mmi_ucm_refresh_incall_notification();
                #endif /* __MMI_BACKGROUND_CALL_WITH_NCENTER__ */
                }

                mmi_frm_group_close(GRP_ID_UCM_MT);
                /*Handle the new screens ex. 1 held + 1 MT call is answered now*/
                mmi_ucm_delete_common_screens();

                mmi_ucm_close_cui(&g_ucm_p->cui_info.incall_opt_cui_id);

                mmi_frm_group_close(GRP_ID_UCM_MO);
                
                /* for vt incall already exists and not processing/ outgoing cases */
            #ifdef __MMI_VIDEO_TELEPHONY__            
                if (active_call_type & SRV_UCM_VIDEO_CALL_TYPE_ALL)
                {
                    mmi_ucm_close_cui(&g_ucm_p->cui_info.vtincall_opt_cui_id);
                }                
            #endif /* __MMI_VIDEO_TELEPHONY__ */

            #if defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
                mmi_frm_group_close(GRP_ID_UCM_INT_MARKER);
            #endif /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */
            }
            else
            {
            #ifdef __MMI_VIDEO_TELEPHONY__
                if (MMI_UCM_VT_INCALL_SCREEN_MODE_INCALL == mmi_ucm_vt_get_incall_screen_mode() ||
                    MMI_UCM_VT_INCALL_SCREEN_MODE_NONE == mmi_ucm_vt_get_incall_screen_mode())
                {
                    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) == 0)    
                    {                   
                        mmi_frm_group_close(GRP_ID_UCM_VT);
                    }        
                }
            #endif /* __MMI_VIDEO_TELEPHONY__ */  
                mmi_frm_group_close(GRP_ID_UCM_MO_FAIL_POST_ACTION);
                mmi_frm_group_close(GRP_ID_UCM_MT);
                mmi_frm_group_close(GRP_ID_UCM_PRE_MO);    
                mmi_frm_group_close(GRP_ID_UCM_MO);
                mmi_frm_group_close(GRP_ID_UCM_INCALL);
                mmi_frm_group_close(GRP_ID_UCM_MARKER);
            #ifdef __MMI_BT_CALL_SUPPORT__
                mmi_frm_group_close(GRP_ID_UCM_MO_SELECT);
            #endif /* __MMI_BT_CALL_SUPPORT__ */
            #if defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
                mmi_frm_group_close(GRP_ID_UCM_INT_MARKER);
            #endif /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */
                mmi_ucm_delete_common_screens();
            }
        }
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_GO_BACK_SCREEN_CHECK_PENDING_ACTION);

        mmi_ucm_tab_highlight();
        /* can not adjust screen when pending action = can not update hilite tab index. In order to use non-updated index,
           delete in call option screen here */
        mmi_ucm_close_cui(&g_ucm_p->cui_info.incall_opt_cui_id);

        /* for race condition, when user press end signle on MO, ucm app recv disconnecting ind, but at the same time
           recv connect ind from peer */
        if ((GRP_ID_UCM_MO == mmi_frm_group_get_active_id()) &&
            (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) == 0))
        {
            if (mmi_frm_scrn_is_present(GRP_ID_UCM_MO, SCR_ID_UCM_DISCONNECT_SCREEN, MMI_FRM_NODE_ALL_FLAG))
        	{
        	     mmi_frm_scrn_close(GRP_ID_UCM_MO, SCR_ID_UCM_DISCONNECT_SCREEN);
    	    }
    			 
            mmi_ucm_entry_disconnecting_screen();
        }

        /* Waiting call is allowed when pending actions exist */
        if (mmi_frm_scrn_is_present(GRP_ID_UCM_MT, SCR_ID_UCM_INCOMING, MMI_FRM_NODE_ALL_FLAG))
        {
            /* Waiting call is disconnected when pending actions exist */
            if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL)  == 0)
            {
                sg_id = mmi_ucm_get_group_id(SCR_ID_UCM_PROCESSING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG);
                /* Pending action is not end related process*/
                if (GRP_ID_INVALID != sg_id)
                {
                    /* Delete incoming call screen and go back to processing call screen */
                    if (SCR_ID_UCM_INCOMING == mmi_frm_scrn_get_active_id())
                    {
                        mmi_frm_group_close(GRP_ID_UCM_MT);
                    }
                    else /* both incoming screen and processing screen are in history */
                    {  
                        /* if processing screen is older than incoming call, delete to processing */
                        if (mmi_frm_node_query_sequence(GRP_ID_ROOT, sg_id, GRP_ID_UCM_MT) > 0)
                        {
                            mmi_ucm_delete_up_to_sg_id(sg_id, MMI_FALSE, MMI_TRUE);
                            scrn_id = mmi_frm_scrn_get_neighbor_id(sg_id, SCR_ID_INVALID, MMI_FRM_NODE_AT_LATEST_FLAG);
                            mmi_frm_scrn_multiple_close(sg_id, scrn_id, MMI_TRUE, 0, SCR_ID_UCM_PROCESSING, MMI_FALSE);
                        }
                    }
                }
                /* because use grey screen to be replace processing screen in end all process */
                else if (MMI_TRUE == mmi_ucm_is_any_disconnecting_call())
                {
                #ifdef __MMI_VIDEO_TELEPHONY__
                    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL)  > 0)
                    {
                        mmi_ucm_adjust_scrn_when_incall_exist(SRV_UCM_VIDEO_CALL_TYPE_ALL);
                    }
                    else
                #endif /* __MMI_VIDEO_TELEPHONY__ */
                    {
                        if (!mmi_frm_scrn_is_present(GRP_ID_UCM_INCALL, SCR_ID_UCM_IN_CALL, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
                        {
                            MMI_ASSERT(0);
                        }
                        /* incall_type: Just use call type is not video call is OK */
                        mmi_ucm_adjust_scrn_when_incall_exist(SRV_UCM_VOICE_CALL_TYPE_ALL);
                    }

                    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_GO_BACK_SCREEN_CHECK_PENDING_ACTION_DISCONNECTING);

                }
            }
        }
    }
}

#ifdef __MMI_CALLSET_AUTO_REDIAL__

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_auto_redial_abort
 * DESCRIPTION
 *  Auto redial abort function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_auto_redial_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_AUTO_REDIAL_ABORT);
    
    if (g_ucm_p->auto_redial.abort_hdlr)
    {
        g_ucm_p->auto_redial.abort_hdlr();
        memset(&g_ucm_p->auto_redial, 0, sizeof(srv_ucm_auto_redial_ind_struct));
    }
    mmi_frm_group_close(GRP_ID_UCM_AUTO_REDIAL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_auto_redial_screen_delete_proc
 * DESCRIPTION
 *  This function is a leave proc for auto redial screen
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_auto_redial_screen_delete_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_AUTI_REDIAL_DELETE_CALLBACK);
            
            if (g_ucm_p->auto_redial.abort_hdlr)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_AUTI_REDIAL_DELETE_CALLBACK_ABORT);
                g_ucm_p->auto_redial.abort_hdlr();
                g_ucm_p->auto_redial.abort_hdlr = NULL;      
            }
        }        
        break;
    }
    
    return MMI_RET_OK;
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_main_menu
 * DESCRIPTION
 *  Enter main menu from incall option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    goto_main_menu();
    mmi_ucm_close_cui(&g_ucm_p->cui_info.incall_opt_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_add_marker
 * DESCRIPTION
 *  Add call marker if necessary
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_add_marker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
    U16 idle_SG_id = mmi_idle_get_group_id();
#endif /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
    idle_SG_id = mmi_frm_get_root_app(idle_SG_id);

    /* create GRP_ID_UCM_MARKER if no GRP_ID_UCM_MARKER exists */
    if (MMI_FALSE == mmi_frm_group_is_present(GRP_ID_UCM_MARKER))
    {
        if ((GRP_ID_INVALID == idle_SG_id) || (MMI_FALSE == mmi_frm_group_is_present(idle_SG_id)))
        {
            mmi_ucm_sg_create(GRP_ID_ROOT, GRP_ID_UCM_MARKER);
        }
        else
        {
            /* insert usage: no mmi_frm_group_enter */
            mmi_ucm_add_sg_to_root(idle_SG_id, GRP_ID_UCM_MARKER, MMI_FRM_NODE_AFTER_FLAG, mmi_ucm_marker_sg_proc);
        }
    }

    mmi_ucm_sg_create(GRP_ID_ROOT, GRP_ID_UCM_INT_MARKER);

#else /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */
    mmi_ucm_sg_create(GRP_ID_ROOT, GRP_ID_UCM_MARKER);
#endif /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_call_type_select_delete_proc
 * DESCRIPTION
 *  This function is a leave proc for call type selection screen
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_call_type_select_delete_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:        
            mmi_ucm_call_type_select_delete_cb();
            break;
        case EVT_ID_SCRN_DEINIT:            
        default:
            break;
    }

    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_call_type_select_delete_cb
 * DESCRIPTION
 *  Call type selection screen delete callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_ucm_call_type_select_delete_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_exit_call_type_select(SRV_UCM_RESULT_CANCEL);
    return 0; /* Allowed to be deleted */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_exit_call_type_select
 * DESCRIPTION
 *  Call type selection screen exit function
 * PARAMETERS
 *  result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_exit_call_type_select(srv_ucm_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BT_CALL_SUPPORT__
    mmi_ucm_exec_dial_cb_by_result(result);
#endif /* __MMI_BT_CALL_SUPPORT__ */
    mmi_frm_group_close(GRP_ID_UCM_PRE_MO);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_cancel_call_type_select
 * DESCRIPTION
 *  Call type selection screen cancel function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_cancel_call_type_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_exit_call_type_select(SRV_UCM_RESULT_CANCEL);
}


#ifdef __MMI_BG_SOUND_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_exit_bgs_effect_select
 * DESCRIPTION
 *  Background sound effect selection screen exit function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_exit_bgs_effect_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bgsnd_common_mtmo_reset_state(MMI_FALSE);
    mmi_frm_scrn_close(GRP_ID_UCM_PRE_MO, SCR_ID_UCM_BGS_EFFECT_SELECT);
    mmi_frm_scrn_close(GRP_ID_UCM_MT, SCR_ID_UCM_BGS_EFFECT_SELECT);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_cancel_bgs_effect_select
 * DESCRIPTION
 *  Background sound effect selection screen cancel function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_cancel_bgs_effect_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_bgsnd_common_mtmo_reset_state(MMI_FALSE);
    mmi_ucm_exec_dial_cb_by_result(SRV_UCM_RESULT_CANCEL);    
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_bgs_effect_endkey_hdlr
 * DESCRIPTION
 *  Background sound effect selection screen endkey handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_bgs_effect_endkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_exit_bgs_effect_select();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_bgs_effect_highlight_hdlr
 * DESCRIPTION
 *  This function is the highlight handler of sound effect list during call
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_bgs_effect_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 check_result = mmi_bgsnd_common_mtmo_check_ext_file_format();  /* O */
    mmi_ucm_make_call_para_struct make_call_para;
    U8* ucs2_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (check_result == BGSND_AUDIO_SUCCESS)
    {
        mmi_bgsnd_common_mtmo_reset_state(MMI_TRUE);  /* O */

        /* Incoming call option */        
        if (srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_DATA_CSD, MMI_FALSE, NULL))
        {
            mmi_ucm_incoming_call_sendkey();
        }
        /* Outgoing call */
        else
        {      
            ucs2_num = OslMalloc((SRV_UCM_MAX_NUM_URI_LEN + 1) * ENCODING_LENGTH);
            mmi_asc_n_to_ucs2((CHAR*)ucs2_num, (CHAR*)g_ucm_p->mo_info.dial_num.num_uri, SRV_UCM_MAX_NUM_URI_LEN);
            make_call_para.ucs2_num_uri = (U16*)ucs2_num;
            
            mmi_ucm_init_call_para(&make_call_para);
    
            make_call_para.dial_type = g_ucm_p->mo_info.dial_type;  
            make_call_para.ucs2_num_uri = (U16*)ucs2_num;
            make_call_para.adv_para.is_ip_dial =  g_ucm_p->mo_info.is_ip_dial;
            make_call_para.adv_para.after_make_call_callback = g_ucm_p->mo_info.callback;
            make_call_para.adv_para.after_callback_user_data = g_ucm_p->mo_info.callback_para;
            make_call_para.adv_para.phb_data = g_ucm_p->mo_info.phb_data;
            make_call_para.adv_para.module_id = g_ucm_p->mo_info.module_id;

            g_ucm_p->call_misc.is_bgs_selected = MMI_TRUE;
            
            mmi_ucm_call_launch(0, &make_call_para);  

            OslMfree(ucs2_num);
        }
    }
#ifdef __USB_IN_NORMAL_MODE__
    else if (check_result == BGSND_USB_NOT_ALLOWED)
    {
        mmi_usb_app_unavailable_popup(0);   /* O */
    }
#endif /* __USB_IN_NORMAL_MODE__ */
    else
    {
        mmi_popup_display_ext(mmi_bgsnd_common_get_uniform_popup_string_id(check_result), MMI_EVENT_FAILURE, NULL);
    }
}
#endif /* __MMI_BG_SOUND_EFFECT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_processing_screen_delete_proc
 * DESCRIPTION
 *  This function is a leave proc for processing screen
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_processing_screen_delete_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        {
            if (srv_ucm_is_pending_action() == MMI_TRUE)
            {
                return MMI_RET_ERR;
            }
        }
        break;

        case EVT_ID_SCRN_DEINIT:
        {
            if (NULL != g_ucm_p->proc_scr.body_string_pointer)
            {
                OslMfree(g_ucm_p->proc_scr.body_string_pointer);
                g_ucm_p->proc_scr.body_string_pointer = NULL;
            }
        }
        break;   

    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_in_call_screen_delete_proc
 * DESCRIPTION
 *  This function is a leave proc for in call screen
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_in_call_screen_delete_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:  
        case EVT_ID_SCRN_DELETE_REQ:
        {
            if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0 ||
                srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0 )
            {
                return MMI_RET_ERR;  /* return MMI_RET_ERR means the scrn can't be deleted*/
            }
        }
        break;

        case EVT_ID_SCRN_DEINIT:
        {
            /* delete all cui triggered by outgoing call scrn - here: option menu */             
            mmi_ucm_close_cui(&g_ucm_p->cui_info.incall_opt_cui_id);
        }
        break;
        
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_outgoing_call_screen_delete_proc
 * DESCRIPTION
 *  This function is a leave proc for outgoing call screen
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_outgoing_call_screen_delete_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:  
        case EVT_ID_SCRN_DELETE_REQ:
        {
            if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
            {
                return MMI_RET_ERR;  /* return MMI_RET_ERR means the scrn can't be deleted*/
            }
        }
        break;
        
    #ifndef __MMI_UCM_SLIM__
        case EVT_ID_SCRN_DEINIT:
        {
            /* delete all cui triggered by outgoing call scrn - here: option menu */            
            mmi_ucm_close_cui(&g_ucm_p->cui_info.outgoing_opt_cui_id);
        }
        break;        
    #endif /* __MMI_UCM_SLIM__ */

    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incoming_call_screen_delete_proc
 * DESCRIPTION
 *  This function is a leave proc for incoming call screen
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_incoming_call_screen_delete_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:  
        case EVT_ID_SCRN_DELETE_REQ:
        {
            if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL)  > 0)
            {
                return MMI_RET_ERR;  /* return MMI_RET_ERR means the scrn can't be deleted*/
            }
        }
        break;

    #ifndef __MMI_UCM_SLIM__
        case EVT_ID_SCRN_DEINIT:
        {
            /* delete all cui triggered by outgoing call scrn - here: option menu */
            mmi_ucm_close_cui(&g_ucm_p->cui_info.incoming_opt_cui_id);
        }
        break;
    #endif /* __MMI_UCM_SLIM__ */

    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_handle_dial_rsp_fail
 * DESCRIPTION
 *  the handler for dial response fail cases
 * PARAMETERS
 *  result_info:          [IN]        dail result structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_handle_dial_rsp_fail(srv_ucm_result_info_struct result_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((CHAR*)result_info.error_msg) > 0)
    {
        /*dial related rsp. not apply mmi_ucm_display_popup_when_call_exist*/
        mmi_popup_display((WCHAR*)((UI_string_type) result_info.error_msg), MMI_EVENT_FAILURE, NULL);
        
    #ifdef __MMI_BG_SOUND_EFFECT__
        if ((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VOICE_CALL_TYPE_ALL, NULL) == 0)  &&
            (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VOIP_CALL_TYPE, NULL) == 0))
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_DIAL_ACT_RSP_FAIL_END_BGS);
            mmi_bgsnd_util_delete_end_call_screen();
        }
    #endif /* __MMI_BG_SOUND_EFFECT__ */
    }        

#ifdef __MMI_BT_CALL_SUPPORT__
    if (mmi_frm_group_is_present(GRP_ID_UCM_MO_SELECT))
    {
        mmi_frm_group_close(GRP_ID_UCM_MO_SELECT);
    }
#endif

    /* go back to corresponding screen */
    mmi_ucm_go_back_screen_check();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_act_callback
 * DESCRIPTION
 *  callback of action
 * PARAMETERS
 *  event:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_act_callback(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_act_result_evt_struct *act_result = (srv_ucm_act_result_evt_struct *) event;
    srv_ucm_act_rsp_struct *dial_rsp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ACT_CB_P1, act_result->act_op);
    /* the success or fail err popup is always displayed by UCM when receiving dial action notify. */
    /* To call app's dial callback here */
    switch(event->evt_id)
    {
        case EVT_ID_SRV_UCM_ACTION_RESULT:
        {
            switch (act_result->act_op)
            {
                case SRV_UCM_DIAL_ACT:
                case SRV_UCM_HOLD_AND_DIAL_ACT:
                case SRV_UCM_END_ALL_AND_DIAL_ACT:
                {
                    dial_rsp = (srv_ucm_act_rsp_struct*) act_result->act_result;
                    g_ucm_p->mo_info.callback_para = act_result->user_data;
                    mmi_ucm_exec_dial_cb_by_result(dial_rsp->result_info.result);

                #ifdef __PXS_APP_ENABLE__
                    if (MMI_TRUE == g_ucm_p->pxs_turn_on && srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
                    {
                        srv_sensor_pxs_turn_off();
                        g_ucm_p->pxs_turn_on = MMI_FALSE;
                        g_ucm_p->pxs_need_handle = MMI_FALSE;
                    }
                #endif /* __PXS_APP_ENABLE__ */

                #ifdef __OP01_FWPBW__
                    if (SRV_UCM_END_ALL_AND_DIAL_ACT == act_result->act_op &&
                        SRV_UCM_RESULT_OK != dial_rsp->result_info.result)
                    {
                        mmi_ucm_fwp_call_process_event_hdlr(MMI_UCM_FWPCP_LAUCH_DIALER_EVENT);
                    }
                #endif /* __OP01_FWPBW__ */
                }
                break;

                default:
                {
                }
                break;
            }
        }
        break;

        default:
        {
            MMI_ASSERT(0);
        }
        break;

    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_exec_dial_cb
 * DESCRIPTION
 *  Need to be removed!
 *  Execute dial callback
 * PARAMETERS
 *  dial_result_info:            [IN]      result info.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_exec_dial_cb(srv_ucm_result_info_struct *dial_result_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_after_make_call_cb_struct make_call_cb_para;
    /* [UCM3.0] */
    /*srv_ucm_result_enum error_cause; mmi_evt_ucm_after_make_call_struct evt */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* mmi_frm_send_event(&evt, g_ucm_p->mo_info.callback, g_ucm_p->mo_info.callback_para); */
	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_EXEC_DIAL_CB_P1, dial_result_info->result);

    if (g_ucm_p->mo_info.callback != NULL)
    {
        make_call_cb_para.result = dial_result_info->result;
        make_call_cb_para.user_data = g_ucm_p->mo_info.callback_para;
        g_ucm_p->mo_info.callback(&make_call_cb_para);
        g_ucm_p->mo_info.callback = NULL; /* Make sure the callback is called once */
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_exec_dial_cb_by_result
 * DESCRIPTION
 *  execute dial callback by given result
 * PARAMETERS 
 *  result            [IN]            dial result
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_exec_dial_cb_by_result(srv_ucm_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_after_make_call_cb_struct make_call_cb_para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_EXEC_DIAL_CB_BY_RESULT_P1, result);

    if (g_ucm_p->mo_info.callback != NULL)
    {
        make_call_cb_para.result = result;
        make_call_cb_para.user_data = g_ucm_p->mo_info.callback_para;
        g_ucm_p->mo_info.callback(&make_call_cb_para);
        g_ucm_p->mo_info.callback = NULL; /* Make sure the callback is called once */
    }

}


#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_incoming_call_answer_by_voice
 * DESCRIPTION
 *  answer video call by voice.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_incoming_call_answer_by_voice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_answer_by_voice_option(MMI_UCM_EXEC_IF_PERMIT_PASS); /* execute action if permit pass */

    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        /* if need to popup specific string for differnt result, use option_check_result */
        mmi_popup_display_ext(srv_ucm_query_error_message(SRV_UCM_RESULT_NOT_ALLOWED_TO_ACCEPT), MMI_EVENT_FAILURE, NULL);
    }
}
#endif /* #if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */


#ifdef __MMI_UCM_AUTO_ANSWER_NOTIFICATION__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_play_tone_callback
 * DESCRIPTION
 *  callback function after mdi finishs playing sound.
 * PARAMETERS
 *  result      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_play_tone_callback(mdi_result result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_AUTO_ANSWER_PLAY_TONE_CALLBACK, result);

    if ((srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 1) &&
        (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 1) &&
        (srv_ucm_is_pending_action() == MMI_FALSE))
    {
        mmi_ucm_incoming_call_sendkey();
    }
}
#endif /* __MMI_UCM_AUTO_ANSWER_NOTIFICATION__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_auto_answer_action
 * DESCRIPTION
 *  Handle SEND key in the incoming call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_auto_answer_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UCM_AUTO_ANSWER_NOTIFICATION__
    U8 audio_type;
    U32 audio_len;
    U8 *audio_data;
    mdi_result audio_result;
#endif /* __MMI_UCM_AUTO_ANSWER_NOTIFICATION__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_AUTO_ANSWER_ACTION); 

    if ((srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == 1) &&
        (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 1))
    {
    #ifdef __MMI_UCM_AUTO_ANSWER_NOTIFICATION__
        audio_data = get_audio(AUD_ID_UCM_AUTO_ANSWER, &audio_type, &audio_len);

        if (audio_data != NULL)
        {
            mmi_ucm_suppress_incoming_tone();
            audio_result = mdi_audio_play_string_with_vol_path(
                               (void*)audio_data,
                               audio_len,
                               audio_type,
                               DEVICE_AUDIO_PLAY_ONCE,
                               mmi_ucm_play_tone_callback,
                               NULL,
                               MDI_AUD_VOL_6,
                               MDI_DEVICE_SPEAKER_BOTH);

            if (audio_result != MDI_AUDIO_SUCCESS)
            {
                mmi_ucm_incoming_call_sendkey();
            }

            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_AUTO_ANSWER_ACTION_P1, audio_result); 
        }
    #else /* __MMI_UCM_AUTO_ANSWER_NOTIFICATION__ */
        mmi_ucm_incoming_call_sendkey();
    #endif /* __MMI_UCM_AUTO_ANSWER_NOTIFICATION__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_outgoing_call_endkey
 * DESCRIPTION
 *  Handle END key in the outgoing call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_outgoing_call_endkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_stop_inband_tone();
    
    option_check_result = mmi_ucm_single_call_option(SRV_UCM_END_SINGLE_ACT, SRV_UCM_OUTGOING_STATE, MMI_UCM_EXEC_IF_PERMIT_PASS);

    if (SRV_UCM_RESULT_UCM_BUSY == option_check_result)
    {
        if (SRV_UCM_RESULT_OK == mmi_ucm_simple_option(SRV_UCM_END_ALL_PROCESSING_ACT, MMI_UCM_EXEC_IF_PERMIT_PASS))
        {
            option_check_result = SRV_UCM_RESULT_OK;
        }
    }
    mmi_ucm_display_error_popup(option_check_result);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incoming_call_sendkey
 * DESCRIPTION
 *  Handle SEND key in the incoming call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_incoming_call_sendkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
#ifdef __MMI_BT_CALL_SUPPORT__
    MMI_ID active_group;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_CALL_SUPPORT__
    if ((srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_CONNECTED, NULL) > 0)
        && !mmi_ucm_get_hide_state_bt())
    {
        active_group = mmi_frm_group_get_active_id();
        mmi_ucm_end_and_accpet_confirm_bt(active_group);	
    }
    else
    {
#endif
	    option_check_result = mmi_ucm_answer_option(MMI_UCM_EXEC_IF_PERMIT_PASS); /* execute action if permit pass */

	    if (SRV_UCM_RESULT_OK != option_check_result)
	    {
	        /* if need to popup specific string for differnt result, use option_check_result */
	        mmi_ucm_display_error_popup(SRV_UCM_RESULT_NOT_ALLOWED_TO_ACCEPT);
	    }
#ifdef __MMI_BT_CALL_SUPPORT__
	}
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incoming_call_endkey
 * DESCRIPTION
 *  Handle END key in the incoming call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_incoming_call_endkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_single_call_option(SRV_UCM_END_SINGLE_ACT, SRV_UCM_INCOMING_STATE, MMI_UCM_EXEC_IF_PERMIT_PASS);
    mmi_ucm_display_error_popup(option_check_result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_in_call_sendkey
 * DESCRIPTION
 *  Handle SEND key in the active call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_in_call_sendkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hiliteTab = g_ucm_p->call_misc.hilite_tab;
    srv_ucm_group_info_struct group_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* get call state */
    srv_ucm_query_group_data(hiliteTab, &group_info);
    
    if (group_info.call_state == SRV_UCM_ACTIVE_STATE)
    {
        if (srv_ucm_query_group_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) == 1)
        {
            mmi_ucm_swap_action();
        }
        else if (mmi_ucm_single_group_option(SRV_UCM_HOLD_ACT, MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
        {
            mmi_ucm_hold_action();
        }
        else /* 3 held calls exist */
        {
            mmi_popup_display_ext(STR_ID_UCM_NOT_ALLOW_TO_HOLD, MMI_EVENT_FAILURE, NULL);
        }
    }
    else if (group_info.call_state == SRV_UCM_HOLD_STATE)
    {
        if (srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL)== SRV_UCM_MAX_ACTIVE_GROUP) /* active call exists */
        {
        	MMI_BOOL act_is_executed;
            if (mmi_ucm_multiple_group_option(SRV_UCM_SWAP_ACT, MMI_UCM_PERMIT_ONLY, &act_is_executed) == SRV_UCM_RESULT_OK) 
            {
                mmi_ucm_swap_action();
            }
            else
            {
                mmi_popup_display_ext(STR_ID_UCM_NOT_ALLOW_TO_SWAP, MMI_EVENT_FAILURE, NULL);
            }
        }
        else /* no active call exists */
        {
            mmi_ucm_retrieve_action();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_in_call_endkey
 * DESCRIPTION
 *  Handle END key in the active call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_in_call_endkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hiliteTab = g_ucm_p->call_misc.hilite_tab;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (srv_ucm_query_group_data(hiliteTab, NULL) == 1)
    {
        mmi_ucm_end_single_action();
    }
    else if (mmi_ucm_end_conference_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        mmi_ucm_end_conference_action();
    }
    else
    {
        mmi_idle_display();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_hold_action
 * DESCRIPTION
 *  execute hold single action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_hold_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    option_check_result = mmi_ucm_single_group_option(SRV_UCM_HOLD_ACT, MMI_UCM_EXEC_IF_PERMIT_PASS);
    mmi_ucm_display_error_popup(option_check_result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_retrieve_action
 * DESCRIPTION
 *  execute retrieve single call action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_retrieve_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_single_group_option(SRV_UCM_RETRIEVE_ACT, MMI_UCM_EXEC_IF_PERMIT_PASS);
    mmi_ucm_display_error_popup(option_check_result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_swap_action
 * DESCRIPTION
 *  execute swap action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_swap_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL act_is_executed;
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_multiple_group_option(SRV_UCM_SWAP_ACT, MMI_UCM_EXEC_IF_PERMIT_PASS, &act_is_executed);

	MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_SWAP_ACTION_P2, option_check_result, act_is_executed);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        mmi_ucm_display_error_popup(option_check_result);
    }
#ifndef __MMI_UCM_SLIM__
    /* Just for expanding, if the number of held call is more than 1, need to enter select screen.
       It is no need now */
    else if ((SRV_UCM_RESULT_OK == option_check_result) && (MMI_FALSE == act_is_executed))
    {
        /* means there are more than one call can be selected */
        mmi_ucm_enter_multi_held_call(SRV_UCM_SWAP_ACT);
    }
#endif /* __MMI_UCM_SLIM__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_conference_action
 * DESCRIPTION
 *  execute conference action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_conference_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL act_is_executed;
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_multiple_group_option(SRV_UCM_CONFERENCE_ACT, MMI_UCM_EXEC_IF_PERMIT_PASS, &act_is_executed);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        mmi_ucm_display_error_popup(option_check_result);
    }
#ifndef __MMI_UCM_SLIM__
    /* Just for expanding, if the number of held call is more than 1, need to enter select screen.
       It is no need now */
    else if ((SRV_UCM_RESULT_OK == option_check_result) && (MMI_FALSE == act_is_executed))
    {
        /* means there are more than one call can be selected */
        mmi_ucm_enter_multi_held_call(SRV_UCM_CONFERENCE_ACT);
    }
#endif /* __MMI_UCM_SLIM__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_split_action
 * DESCRIPTION
 *  execute split action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_split_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    option_check_result = mmi_ucm_single_call_option(SRV_UCM_SPLIT_ACT, SRV_UCM_CALL_STATE_CONNECTED, MMI_UCM_EXEC_IF_PERMIT_PASS);
    mmi_ucm_display_error_popup(option_check_result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_single_action
 * DESCRIPTION
 *  execute end single call action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_single_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_single_call_option(SRV_UCM_END_SINGLE_ACT, SRV_UCM_CALL_STATE_CONNECTED, MMI_UCM_EXEC_IF_PERMIT_PASS);
    mmi_ucm_display_error_popup(option_check_result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_conference_action
 * DESCRIPTION
 *  execute end conference action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_conference_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_end_conference_option(MMI_UCM_EXEC_IF_PERMIT_PASS);
    mmi_ucm_display_error_popup(option_check_result);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_all_action
 * DESCRIPTION
 *  Execute end all action is permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_end_all_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_simple_option(SRV_UCM_END_ALL_ACT, MMI_UCM_EXEC_IF_PERMIT_PASS);     
    mmi_ucm_display_error_popup(option_check_result); 
}

#ifndef __SLIM_UCM__
#ifndef __MMI_UCM_RSK_MUTE__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_mute_action
 * DESCRIPTION
 *  execute mute action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_mute_action(mmi_menu_id mute_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    option_check_result = mmi_ucm_mute_option(MMI_UCM_PERMIT_ONLY);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        mmi_ucm_display_error_popup(option_check_result);
    }    
    else
    {
        if (MENU_ID_UCM_INCALL_OPTION_MUTE_OFF == mute_menu_id)
        {
            srv_speech_unmute_phone();
        }
        else if (MENU_ID_UCM_INCALL_OPTION_MUTE_ON == mute_menu_id)
        {
            srv_speech_mute_phone();
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
}
#endif /* __MMI_UCM_RSK_MUTE__ */
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_sndrec_in_call_action
 * DESCRIPTION
 *  execute sound recorder action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SOUND_RECORDER__
void mmi_ucm_sndrec_in_call_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_sound_recorder_option(MMI_UCM_PERMIT_ONLY);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        mmi_ucm_display_error_popup(option_check_result);
    }
	else
	{
		mmi_sndrec_entry_in_call();
	}	
}
#endif /* __MMI_SOUND_RECORDER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_sms_template_action
 * DESCRIPTION
 *  execute get sms template action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_UCM_REJECT_BY_SMS__
void mmi_ucm_get_sms_template_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	option_check_result = mmi_ucm_rej_by_sms_option(MMI_UCM_PERMIT_ONLY);
	if (SRV_UCM_RESULT_OK == option_check_result)
	{
		mmi_ucm_get_sms_template();
	}
	else
	{
		mmi_ucm_display_error_popup(option_check_result);
	}
}
#endif /* __MMI_UCM_REJECT_BY_SMS__ */


#ifdef __MMI_UCM_DEFLECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_deflect_action
 * DESCRIPTION
 *  execute deflect action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_deflect_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_deflect_option(MMI_UCM_EXEC_IF_PERMIT_PASS); /* execute action if permit pass */
    mmi_ucm_display_error_popup(option_check_result);
}
#endif /* __MMI_UCM_DEFLECT__ */


#ifdef __MMI_UCM_TRANSFER__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_transfer_action
 * DESCRIPTION
 *  execute transfer action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_transfer_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_transfer_option(MMI_UCM_EXEC_IF_PERMIT_PASS); /* execute action if permit pass */
    mmi_ucm_display_error_popup(option_check_result);
}
#endif /* __MMI_UCM_TRANSFER__ */


#ifdef __MMI_UCM_ECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_exec_ECT_confirm_yes
 * DESCRIPTION
 *  exec action when user press ECT confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_exec_ECT_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_explict_call_transfer_action();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_explict_call_transfer_action
 * DESCRIPTION
 *  execute ECT action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_explict_call_transfer_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_transfer_option(MMI_UCM_EXEC_IF_PERMIT_PASS); /* execute action if permit pass */
    mmi_ucm_display_error_popup(option_check_result);
}
#endif /* __MMI_UCM_ECT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_phb_incall_action
 * DESCRIPTION
 *  Enter phonebook if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_phb_incall_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_enter_general_app_option(MMI_UCM_PERMIT_ONLY);
    
    if (SRV_UCM_RESULT_OK != option_check_result)
    {        
        mmi_ucm_display_error_popup(option_check_result);
    }   
	else
	{
		mmi_phb_launch();
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_clog_incall_action
 * DESCRIPTION
 *  Enter call log if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_clog_incall_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_enter_general_app_option(MMI_UCM_PERMIT_ONLY);
    
    if (SRV_UCM_RESULT_OK != option_check_result)
    {        
        mmi_ucm_display_error_popup(option_check_result);
    }   
	else
	{
		mmi_clog_launch();
	}
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_message_action
 * DESCRIPTION
 *  Enter message center if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_message_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_enter_general_app_option(MMI_UCM_PERMIT_ONLY);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {        
        mmi_ucm_display_error_popup(option_check_result);
    }   
	else
	{
	#ifdef __UM_SUPPORT__
		mmi_um_entry_main_message_menu_with_check();
        #else
                mmi_sms_entry_main_message_menu();
	#endif
	}
}


#if (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_browser_incall_action
 * DESCRIPTION
 *  Enter browser if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_browser_incall_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_browser_option(MMI_UCM_PERMIT_ONLY);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        mmi_ucm_display_error_popup(option_check_result);
    }
    else
    {
        if (!mmi_brw_scrn_is_present())
        {
            goto_mobile_suite_screen();
        }
        else
        {
            opera_brw_api_set_to_active_group();
        }
    }
}
#endif /* (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER) */


#ifndef __MMI_UCM_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_voice_call_from_incall_dialer_sim1_action
 * DESCRIPTION
 *  execute make sim1 voice call action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#if (MMI_MAX_SIM_NUM == 2)
void mmi_ucm_make_voice_call_from_incall_dialer_sim1_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE))
    {
		mmi_ucm_make_voice_call_from_incall_dialer_sim1();
	}
	else
	{
		mmi_ucm_display_error_popup(SRV_UCM_RESULT_ACTION_NOT_ALLOWED);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_voice_call_from_incall_dialer_sim1_action
 * DESCRIPTION
 *  execute make sim2 voice call action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_voice_call_from_incall_dialer_sim2_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE_SIM2))
    {
		mmi_ucm_make_voice_call_from_incall_dialer_sim2();
	}
	else
	{
		mmi_ucm_display_error_popup(SRV_UCM_RESULT_ACTION_NOT_ALLOWED);
	}

}
#endif /* (MMI_MAX_SIM_NUM == 2) */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_voice_dialer_screen_action
 * DESCRIPTION
 *  Enter voice dialer screen if service is available
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_voice_dialer_screen_action(void)
{	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE_ALL))
    {
		mmi_ucm_enter_voice_dialer_screen();
	}
	else
	{
		mmi_ucm_display_error_popup(SRV_UCM_RESULT_ACTION_NOT_ALLOWED);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_save_phonebook_action
 * DESCRIPTION
 *  Trigger save phonebook flow if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_save_phonebook_action(void)
{	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (SRV_UCM_RESULT_OK == mmi_ucm_enter_general_app_option(MMI_UCM_PERMIT_ONLY))
	{
		mmi_ucm_entry_save_phonebook();
	}
	else
	{
		mmi_ucm_display_error_popup(SRV_UCM_RESULT_ACTION_NOT_ALLOWED);
	}
}


#ifdef __MMI_VOIP__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_voip_dialer_screen_action
 * DESCRIPTION
 *  Enter voip dialer screen if service is available
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_voip_dialer_screen_action(void)
{	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == srv_ucm_is_call_srv_available(SRV_UCM_VOIP_CALL_TYPE))
    {
		mmi_ucm_enter_voip_dialer_screen();
	}
	else
	{
		mmi_ucm_display_error_popup(SRV_UCM_RESULT_ACTION_NOT_ALLOWED);
	}
}
#endif /* __MMI_VOIP__ */
#endif /* __MMI_UCM_SLIM__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_all_held_action
 * DESCRIPTION
 *  Execute end all held action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
void mmi_ucm_end_all_held_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_simple_option(SRV_UCM_END_ALL_HELD_ACT, MMI_UCM_EXEC_IF_PERMIT_PASS);
    mmi_ucm_display_error_popup(option_check_result);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_end_all_active_action
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__
void mmi_ucm_end_all_active_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* no active calls to drop */
    MMI_ASSERT(srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0);

    option_check_result = mmi_ucm_simple_option(SRV_UCM_END_ALL_ACTIVE_ACT, MMI_UCM_EXEC_IF_PERMIT_PASS);
    mmi_ucm_display_error_popup(option_check_result); 
}
#endif


#ifdef __MMI_BT_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incall_bt_set_audio_path_action
 * DESCRIPTION
 *  Execute set bluetooth audio path action in incall case if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_incall_bt_set_audio_path_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    option_check_result = mmi_ucm_swap_bt_audio_path_option(MMI_UCM_PERMIT_ONLY, SRV_UCM_CALL_STATE_CONNECTED);
    
    if (SRV_UCM_RESULT_OK == option_check_result)
    {
        mmi_ucm_bt_set_audio_path();
    }
    else
    {
        mmi_ucm_display_error_popup(option_check_result);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incoming_bt_set_audio_path_action
 * DESCRIPTION
 *  Execute set bluetooth audio path action in incoming call case if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_incoming_bt_set_audio_path_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    option_check_result = mmi_ucm_swap_bt_audio_path_option(MMI_UCM_PERMIT_ONLY, SRV_UCM_INCOMING_STATE);

    if (SRV_UCM_RESULT_OK == option_check_result)
    {
        mmi_ucm_bt_set_audio_path();
    }
    else
    {
        mmi_ucm_display_error_popup(option_check_result);
    }
}
#endif /* __MMI_BT_SUPPORT__ */


/* This API is only used in incoming call */
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_bgs_effect_select_action
 * DESCRIPTION
 *  enter background sound selection flow if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_BG_SOUND_EFFECT__
void mmi_ucm_entry_bgs_effect_select_action(mmi_id parent_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    option_check_result = mmi_ucm_bk_sound_incoming_option(MMI_UCM_PERMIT_ONLY);
        
    if (SRV_UCM_RESULT_OK == option_check_result)
    {
        mmi_ucm_enter_bgs_effect_select(parent_sg_id);
    }
    else
    {
        mmi_ucm_display_error_popup(option_check_result);
    }
}
#endif /* __MMI_BG_SOUND_EFFECT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_connect_action
 * DESCRIPTION
 *  execute ctm connection action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __CTM_SUPPORT__
void mmi_ctm_connect_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum permit_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    permit_result = mmi_ucm_ctm_option(MMI_UCM_PERMIT_ONLY);

    if (SRV_UCM_RESULT_OK == permit_result)
    {
    #ifndef __COSMOS_MMI_PACKAGE__
        mmi_ctm_connect();
    #endif /* __COSMOS_MMI_PACKAGE__ */
    }
    else
    {
        mmi_ucm_display_error_popup(permit_result);
    }   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ctm_setting_action
 * DESCRIPTION
 *  execute ctm setting action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ctm_setting_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum permit_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    permit_result = mmi_ucm_ctm_setting_option(MMI_UCM_PERMIT_ONLY);

    if (SRV_UCM_RESULT_OK == permit_result)
    {
    #ifndef __COSMOS_MMI_PACKAGE__
        mmi_callset_ctm_setting_launch();
    #endif /* __COSMOS_MMI_PACKAGE__ */
    }
    else
    {
        mmi_ucm_display_error_popup(permit_result);
    }   
}
#endif /* __CTM_SUPPORT__ */


#ifdef __MMI_DUAL_MIC_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_noice_reduction_action
 * DESCRIPTION
 *  execute noice reduction action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_noice_reduction_action()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result = SRV_UCM_RESULT_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    option_check_result = mmi_ucm_noice_reduction_option(MMI_UCM_PERMIT_ONLY);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        mmi_ucm_display_error_popup(option_check_result);
    }
    else
    {
        if (MMI_TRUE == mmi_ucm_get_dual_mic_nr_status())
        {
            mmi_ucm_set_dual_mic_nr_status(MMI_FALSE);
            mmi_popup_display_ext(STR_ID_UCM_DISABLED, MMI_EVENT_SUCCESS, NULL);
            
        }
        else if (MMI_FALSE == mmi_ucm_get_dual_mic_nr_status())
        {
            mmi_ucm_set_dual_mic_nr_status(MMI_TRUE);
            mmi_popup_display_ext(STR_ID_UCM_ENABLED, MMI_EVENT_SUCCESS, NULL);
        }
        else
        {
            MMI_ASSERT(0);
        }        
    }
}
#endif /* __MMI_DUAL_MIC_SUPPORT__ */


#ifdef __MMI_VIDEO_TELEPHONY__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_switch_to_video_call_confirm_no
 * DESCRIPTION
 *  Triggered when user select no on "swith to video call" confirm popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_switch_to_video_call_confirm_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_close_cui(&g_ucm_p->cui_info.incall_opt_cui_id);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_switch_to_video_call_confirm_yes
 * DESCRIPTION
 *  Triggered when user select Yes on "swith to video call" confirm popup
 *  will end call and dial to video call with the same number.
 *  the case only be triggered when there is only one active or held voice call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_switch_to_video_call_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_ucm_result_enum permit_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	permit_result =  mmi_ucm_switch_to_video_call_option(MMI_UCM_EXEC_IF_PERMIT_PASS);
	
	if (permit_result != SRV_UCM_RESULT_OK)
    {
		mmi_ucm_display_error_popup(permit_result);
		return;
	}
}
#endif /* __MMI_VIDEO_TELEPHONY__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_auto_quick_end
 * DESCRIPTION
 *  Your description
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_auto_quick_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
    {
        /* MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G5_CALL,"\n[mmi_ucm_auto_quick_end] No calls to drop\n"); */
        return;
    }
     
    else if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL)  > 0 || srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        /* MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G5_CALL,"\n[mmi_ucm_auto_quick_end] No action when there is MT or MO call\n"); */
        return;
    }
    else if (srv_ucm_is_pending_action() == MMI_TRUE)
    {
        /*MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G5_CALL,"\n[mmi_ucm_auto_quick_end] can't drop calls during pending actions\n");*/
        StartTimer(CM_AUTO_QUICK_END_TIMER, 1000, mmi_ucm_auto_quick_end);
        return;
    }
    else
    {
        mmi_ucm_end_all_action();
    }
}


#ifdef __MMI_UCM_REJECT_BY_SMS__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_sms_template_callback
 * DESCRIPTION
 *  Callback function for the result of template selection
 * PARAMETERS
 *  template      IN  template in UCS2
 *  result     IN  result of selection
 * RETURNS
 * 
 *****************************************************************************/
void mmi_ucm_get_sms_template_callback(WCHAR* sms_template, WGUI_SOFTKEY_ENUM key_pressed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_GET_SMS_CALLBACK, key_pressed);

    if (g_ucm_p->rej_by_sms.ucs2_msg_context != NULL)
    {
        OslMfree(g_ucm_p->rej_by_sms.ucs2_msg_context);
        g_ucm_p->rej_by_sms.ucs2_msg_context = NULL;
    }

    if (MMI_LEFT_SOFTKEY == key_pressed) /* Select */
    {
		g_ucm_p->rej_by_sms.ucs2_msg_context = OslMalloc((mmi_ucs2strlen((CHAR*)sms_template) + 1) * ENCODING_LENGTH);
        mmi_ucs2cpy((CHAR*)g_ucm_p->rej_by_sms.ucs2_msg_context, (CHAR*)sms_template);
        mmi_ucm_enter_rej_by_sms_confirm();
    }
    else /* back */
    {
        memset(&g_ucm_p->rej_by_sms, 0, sizeof(mmi_ucm_rej_by_sms_struct));   
    }
}
#endif /* __MMI_UCM_REJECT_BY_SMS__ */


/* ==================================================================================== */
/* =============Launch call related==================================================== */
/* ==================================================================================== */

#ifndef __MMI_UCM_SLIM__
#if defined(__MMI_VOIP__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_voip_call_from_incall_dialer
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_voip_call_from_incall_dialer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct make_call_para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_init_call_para(&make_call_para);

    make_call_para.dial_type = SRV_UCM_VOIP_CALL_TYPE;
    
    make_call_para.ucs2_num_uri = (U16*)g_ucm_p->mo_info.dial_pad_buffer;
    
    mmi_ucm_call_launch(0, &make_call_para);      
}
#endif /* __MMI_VOIP__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_voice_call_from_incall_dialer_for_sendkey
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_voice_call_from_incall_dialer_for_sendkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct sendkey_makecall_para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_MAKE_VOICE_CALL_FROM_INCALL_DIALER);

    if (mmi_ucs2strlen((CHAR*) g_ucm_p->mo_info.dial_pad_buffer) > 0)
    {
        mmi_ucm_init_call_para_for_sendkey(&sendkey_makecall_para);
        sendkey_makecall_para.ucs2_num_uri = (U16*)g_ucm_p->mo_info.dial_pad_buffer;
        mmi_ucm_call_launch(0, &sendkey_makecall_para);
    }
	else
    {
		mmi_ucm_display_error_popup(SRV_UCM_RESULT_EMPTY_NUMBER);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_voice_call_from_incall_dialer
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_voice_call_from_incall_dialer(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct make_call_para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_MAKE_VOICE_CALL_FROM_INCALL_DIALER_P1, call_type);

    mmi_ucm_init_call_para(&make_call_para);

    make_call_para.dial_type = call_type;
    
    make_call_para.ucs2_num_uri = (U16*)g_ucm_p->mo_info.dial_pad_buffer;
    
    mmi_ucm_call_launch(0, &make_call_para);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_voice_call_from_incall_dialer_icon
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_voice_call_from_incall_dialer_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_ucm_call_type_enum call_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    call_type = SRV_UCM_VOICE_CALL_TYPE_ALL;

    if (mmi_ucs2strlen((CHAR*) g_ucm_p->mo_info.dial_pad_buffer) > 0)
    {
        mmi_ucm_make_voice_call_from_incall_dialer(call_type);
    }
	else
    {
		mmi_ucm_display_error_popup(SRV_UCM_RESULT_EMPTY_NUMBER);
	}	
    return;
}


#ifdef __MMI_VIDEO_TELEPHONY__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_video_call_from_incall_dialer_icon
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_video_call_from_incall_dialer_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_ucs2strlen((CHAR*) g_ucm_p->mo_info.dial_pad_buffer) > 0)
    {
        mmi_ucm_make_voice_call_from_incall_dialer(mmi_ucm_vt_get_valid_video_call_type());
    }
	else
    {
		mmi_ucm_display_error_popup(SRV_UCM_RESULT_EMPTY_NUMBER);
	}	
    return;
}
#endif /* __MMI_VIDEO_TELEPHONY__ */


#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_voice_call_from_incall_dialer_sim1
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_voice_call_from_incall_dialer_sim1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((CHAR*)g_ucm_p->mo_info.dial_pad_buffer) > 0)
    {
        mmi_ucm_make_voice_call_from_incall_dialer(SRV_UCM_VOICE_CALL_TYPE);
    }
	else
    {
		mmi_ucm_display_error_popup(SRV_UCM_RESULT_EMPTY_NUMBER);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_voice_call_from_incall_dialer_sim2
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_voice_call_from_incall_dialer_sim2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((CHAR*)g_ucm_p->mo_info.dial_pad_buffer) > 0)
    {
		mmi_ucm_make_voice_call_from_incall_dialer(SRV_UCM_VOICE_CALL_TYPE_SIM2);
    }
	else
    {
		mmi_ucm_display_error_popup(SRV_UCM_RESULT_EMPTY_NUMBER);
	}	
}


#if (MMI_MAX_SIM_NUM >= 3)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_voice_call_from_incall_dialer_sim3
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_voice_call_from_incall_dialer_sim3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((CHAR*)g_ucm_p->mo_info.dial_pad_buffer) > 0)
    {
		mmi_ucm_make_voice_call_from_incall_dialer(SRV_UCM_VOICE_CALL_TYPE_SIM3);
    }
	else
    {
		mmi_ucm_display_error_popup(SRV_UCM_RESULT_EMPTY_NUMBER);
	}
}


#if (MMI_MAX_SIM_NUM >= 4)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_voice_call_from_incall_dialer_sim4
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_voice_call_from_incall_dialer_sim4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((CHAR*)g_ucm_p->mo_info.dial_pad_buffer) > 0)
    {
		mmi_ucm_make_voice_call_from_incall_dialer(SRV_UCM_VOICE_CALL_TYPE_SIM4);
    }
	else
    {
		mmi_ucm_display_error_popup(SRV_UCM_RESULT_EMPTY_NUMBER);
	}
}
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */

#endif /* __MMI_UCM_SLIM__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_voice_call_from_dtmf_editor_for_sendkey
 * DESCRIPTION
 *  make voice call when press send key in dtmf editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_voice_call_from_dtmf_editor_for_sendkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct sendkey_makecall_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((CHAR*)g_ucm_p->call_misc.disp_dtmf) > 0)
    {
    	//MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_MAKE_VOICE_CALL_FROM_DTMF_EDITOR_FOR_SENDKEY);
        mmi_ucm_init_call_para_for_sendkey(&sendkey_makecall_para);
        sendkey_makecall_para.ucs2_num_uri = (U16*)g_ucm_p->call_misc.disp_dtmf;
        mmi_ucm_call_launch(0, &sendkey_makecall_para);
    }
	else
    {
        mmi_ucm_display_error_popup(SRV_UCM_RESULT_EMPTY_NUMBER);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_voice_call_from_dtmf_editor_by_call_type
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_voice_call_from_dtmf_editor_by_call_type(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct make_call_para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_MAKE_VOICE_CALL_FROM_DTMF_EDITOR);
    mmi_ucm_init_call_para(&make_call_para);
    make_call_para.dial_type = call_type;
    make_call_para.ucs2_num_uri = (U16*)g_ucm_p->call_misc.disp_dtmf;
    mmi_ucm_call_launch(0, &make_call_para);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_voice_call_from_dtmf_editor
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_voice_call_from_dtmf_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct make_call_para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_MAKE_VOICE_CALL_FROM_DTMF_EDITOR);
    mmi_ucm_init_call_para(&make_call_para);
    make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_ALL;
    make_call_para.ucs2_num_uri = (U16*)g_ucm_p->call_misc.disp_dtmf;
    mmi_ucm_call_launch(0, &make_call_para);
}


#ifdef __MMI_VIDEO_TELEPHONY__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_video_call_from_dtmf_dialer_icon
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_video_call_from_dtmf_dialer_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_ucs2strlen((CHAR*)g_ucm_p->call_misc.disp_dtmf) > 0)
    {
        mmi_ucm_make_voice_call_from_dtmf_editor_by_call_type(mmi_ucm_vt_get_valid_video_call_type());
    }
	else
    {
		mmi_ucm_display_error_popup(SRV_UCM_RESULT_EMPTY_NUMBER);
	}	
    return;
}


#endif /* __MMI_VIDEO_TELEPHONY__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_voice_call_from_dtmf_editor_icon
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_voice_call_from_dtmf_editor_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((CHAR*)g_ucm_p->call_misc.disp_dtmf) > 0)
    {
        mmi_ucm_make_voice_call_from_dtmf_editor_by_call_type(SRV_UCM_CALL_TYPE_ALL);
    }
	else
    {
		mmi_ucm_display_error_popup(SRV_UCM_RESULT_EMPTY_NUMBER);
	}
}


#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_voice_call_from_dtmf_editor_sim1
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_voice_call_from_dtmf_editor_sim1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((CHAR*)g_ucm_p->call_misc.disp_dtmf) > 0)
    {
        mmi_ucm_make_voice_call_from_dtmf_editor_by_call_type(SRV_UCM_VOICE_CALL_TYPE);
    }
	else
    {
		mmi_ucm_display_error_popup(SRV_UCM_RESULT_EMPTY_NUMBER);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_voice_call_from_dtmf_editor_sim2
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_voice_call_from_dtmf_editor_sim2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((CHAR*)g_ucm_p->call_misc.disp_dtmf) > 0)
    {
        mmi_ucm_make_voice_call_from_dtmf_editor_by_call_type(SRV_UCM_VOICE_CALL_TYPE_SIM2);    
    }
	else
    {
		mmi_ucm_display_error_popup(SRV_UCM_RESULT_EMPTY_NUMBER);
	}
}


#if (MMI_MAX_SIM_NUM >= 3)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_voice_call_from_dtmf_editor_sim3
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_voice_call_from_dtmf_editor_sim3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (mmi_ucs2strlen((CHAR*)g_ucm_p->call_misc.disp_dtmf) > 0)
    {
        mmi_ucm_make_voice_call_from_dtmf_editor_by_call_type(SRV_UCM_VOICE_CALL_TYPE_SIM3);
    }
	else
    {
		mmi_ucm_display_error_popup(SRV_UCM_RESULT_EMPTY_NUMBER);
	}
}


#if (MMI_MAX_SIM_NUM >= 4)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_voice_call_from_dtmf_editor_sim4
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_voice_call_from_dtmf_editor_sim4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucs2strlen((CHAR*)g_ucm_p->call_misc.disp_dtmf) > 0)
    {
        mmi_ucm_make_voice_call_from_dtmf_editor_by_call_type(SRV_UCM_VOICE_CALL_TYPE_SIM4);
    }
	else
    {
		mmi_ucm_display_error_popup(SRV_UCM_RESULT_EMPTY_NUMBER);
	}
}
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_make_call_from_incall_dialer_option
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_make_call_from_incall_dialer_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_ucm_make_voice_call_from_dtmf_editor_by_call_type(SRV_UCM_CALL_TYPE_ALL);
    return;
}

/* ==================================================================================== */
/* =============Option menu hdlr======================================================= */
/* ==================================================================================== */
#ifndef __MMI_UCM_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_any_outgoing_call_opt_item_exist
 * DESCRIPTION
 *  Query if the outgoing call option has any item
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means outgoing call option has item
 *  MMI_FALSE means outgoing call option has't any item
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_any_outgoing_call_opt_item_exist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_outgoing_dialer_option() == SRV_UCM_RESULT_OK)
    {
        /* if the menu is not in outgoing call option. */
        if (GetChildMenuIDIndexByParentMenuID(MENU_ID_UCM_OUTGOING_OPTION, MENU_ID_UCM_OUTGOING_OPTION_DIALER) >= 0)
        {
            return MMI_TRUE;
        }
    } 

    if (mmi_ucm_loud_option(SRV_UCM_OUTGOING_STATE) == SRV_UCM_RESULT_OK)
    {
        if ((GetChildMenuIDIndexByParentMenuID(MENU_ID_UCM_OUTGOING_OPTION, MENU_ID_UCM_OUTGOING_OPTION_HAND_HELD) >= 0) ||
            (GetChildMenuIDIndexByParentMenuID(MENU_ID_UCM_OUTGOING_OPTION, MENU_ID_UCM_OUTGOING_OPTION_HAND_FREE) >= 0))   
        {
            return MMI_TRUE;
        }
    }

#ifdef __VOICE_CHANGER_SUPPORT__
    if (GetChildMenuIDIndexByParentMenuID(MENU_ID_UCM_OUTGOING_OPTION, MENU_ID_CALLSET_MAGIC_VOICE) >= 0)
    {
        return MMI_TRUE;
    }
#endif /* __VOICE_CHANGER_SUPPORT__ */

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_handle_outgoing_option
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_handle_outgoing_option(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_outgoing_dialer_option() == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_OUTGOING_OPTION_DIALER, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_OUTGOING_OPTION_DIALER, MMI_TRUE);
    }

    if (mmi_ucm_loud_option(SRV_UCM_OUTGOING_STATE) == SRV_UCM_RESULT_OK)
    {
        if (mdi_audio_get_audio_mode() == AUD_MODE_LOUDSPK)
        {
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_OUTGOING_OPTION_HAND_HELD, MMI_FALSE);
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_OUTGOING_OPTION_HAND_FREE, MMI_TRUE);
        }
        else
        {
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_OUTGOING_OPTION_HAND_HELD, MMI_TRUE);
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_OUTGOING_OPTION_HAND_FREE, MMI_FALSE);
        } 
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_OUTGOING_OPTION_HAND_HELD, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_OUTGOING_OPTION_HAND_FREE, MMI_TRUE);
    }  

#ifdef __VOICE_CHANGER_SUPPORT__
    cui_menu_set_item_hidden(owner_gid, MENU_ID_CALLSET_MAGIC_VOICE, MMI_FALSE);
#endif /* __VOICE_CHANGER_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_outgoing_call_opt_proc
 * DESCRIPTION
 *  The proc function of outgoing option
 *
 * PARAMETERS
 *  evt                     [IN]: event
 *  
 * RETURNS
 *  MMI_RET_OK: handle this event successfully
 *  Others: fail to handle this event
 *****************************************************************************/
mmi_ret mmi_ucm_outgoing_call_opt_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
    MMI_BOOL act_is_executed = MMI_FALSE;
    MMI_BOOL dialer_act_is_executed = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            /* 0 , non-leaf */
            if (MENU_ID_UCM_OUTGOING_OPTION == menu_evt->parent_menu_id) 
            {
                /* Decide if need to hide each menu items */
                mmi_ucm_handle_outgoing_option(menu_evt->sender_id);
             
            }
            else if (MENU_ID_UCM_IN_CALL_DIALER_OPTION == menu_evt->parent_menu_id) 
            {
                /* Decide if need to hide each menu items */
                mmi_ucm_handle_in_call_dialer_option(menu_evt->sender_id);
            }
        #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
            else if (MENU_ID_UCM_SIM_SELECT == menu_evt->parent_menu_id)
            {
                mmi_ucm_add_sim_name_for_sim_select(menu_evt->sender_id);
            }
        #endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
        }
        break;

        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
        }
        break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {            
            switch(menu_evt->highlighted_menu_id)
            {
                /* 1st , leaf */
                case MENU_ID_UCM_OUTGOING_OPTION_DIALER:
                {
                    mmi_ucm_pre_entry_dtmf_editor();
                    act_is_executed = MMI_TRUE;
                }
                break;
            
                /* 1st , leaf */
                case MENU_ID_UCM_OUTGOING_OPTION_HAND_HELD:
                case MENU_ID_UCM_OUTGOING_OPTION_HAND_FREE:
                {
                    mmi_ucm_set_loud_speaker_during_outgoing_call();
                    act_is_executed = MMI_TRUE;
                }
                break;
                
                /* 1st , leaf - in call dialer */
                case MENU_ID_UCM_IN_CALL_DIALER_OPTION_DIAL:
                {
                    mmi_ucm_make_call_from_incall_dialer_option();
                    dialer_act_is_executed = MMI_TRUE;
                }
                break;
            
                /* 1st , leaf - in call dialer */
                case MENU_ID_UCM_IN_CALL_DIALER_OPTION_SAVE:
                {
                    mmi_ucm_entry_save_phonebook();
                    dialer_act_is_executed = MMI_TRUE;
                }
                break;

            #if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
            #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_ID_UCM_FROM_SIM1:
                case MENU_ID_UCM_FROM_SIM2:
            #if (MMI_MAX_SIM_NUM >= 3)
                case MENU_ID_UCM_FROM_SIM3:
            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_ID_UCM_FROM_SIM4:
            #endif /* (MMI_MAX_SIM_NUM >= 4) */
            #endif /* (MMI_MAX_SIM_NUM >= 3) */
            #endif /* (MMI_MAX_SIM_NUM >= 2) */
                {
                    mmi_ucm_dial_call_from_sim_select(menu_evt->highlighted_menu_id);
                }
                break;
            #endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */

            #ifdef __VOICE_CHANGER_SUPPORT__
                case MENU_ID_CALLSET_MAGIC_VOICE:
                {
                    mmi_callset_magic_voice_launch();
                    act_is_executed = MMI_TRUE;                    
                }
                break;
            #endif /* __VOICE_CHANGER_SUPPORT__ */

                default:
                break;
            }

            /* close menu cui after user selects any leave item */
            if (act_is_executed)
            {
                mmi_ucm_close_cui(&g_ucm_p->cui_info.outgoing_opt_cui_id);
            }
            
            if (dialer_act_is_executed)
            { 
                mmi_ucm_close_cui(&g_ucm_p->cui_info.in_call_dialer_opt_cui_id);
            }            
        }
        break;
        
        /*CUI Menu close request event : send request to APP for closing the CUI menu instance */
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            if (menu_evt->sender_id ==  g_ucm_p->cui_info.outgoing_opt_cui_id)
            {
                g_ucm_p->cui_info.outgoing_opt_cui_id = GRP_ID_INVALID;
            }
            else if (menu_evt->sender_id ==  g_ucm_p->cui_info.in_call_dialer_opt_cui_id)
            {
                g_ucm_p->cui_info.in_call_dialer_opt_cui_id = GRP_ID_INVALID;
            }
            cui_menu_close(menu_evt->sender_id);
        }
        break;

        default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_outgoing_call_option
 * DESCRIPTION
 *  Shows the outgoing call option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_outgoing_call_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_ucm_outgoing_call_opt_proc */

    /* create menu cui */
    g_ucm_p->cui_info.outgoing_opt_cui_id = cui_menu_create_and_run(
                            GRP_ID_UCM_MO, 
                            CUI_MENU_SRC_TYPE_RESOURCE,
                            CUI_MENU_TYPE_OPTION, 
                            MENU_ID_UCM_OUTGOING_OPTION, 
                            MMI_FALSE, /* Use global resource */
                            NULL);
    
    //cui_menu_enable_cascading_option_menu(g_ucm_p->cui_info.outgoing_opt_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_outgoing_call_show_option
 * DESCRIPTION
 *  Check if outgoing call option can be displayed or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means outgoing call option should show;
 *  FALSE means outgoing call option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_outgoing_call_show_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (srv_ucm_is_emergency_call() == MMI_TRUE)
    {
        return MMI_FALSE;
    }

    return mmi_ucm_is_any_outgoing_call_opt_item_exist();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_any_incoming_call_opt_item_exist
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_any_incoming_call_opt_item_exist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_answer_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        /* if the menu is not in incoming call option. */
        if (GetChildMenuIDIndexByParentMenuID(MENU_ID_UCM_INCOMING_OPTION, MENU_ID_UCM_INCOMING_OPTION_ANSWER) >= 0)
        {
            return MMI_TRUE;
        }
    }
 
#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
    if (mmi_ucm_answer_by_voice_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        /* if the menu is not in incoming call option. */
        if (GetChildMenuIDIndexByParentMenuID(MENU_ID_UCM_INCOMING_OPTION, MENU_ID_UCM_INCOMING_OPTION_ANSWER_BY_VOICE) >= 0)
        {
            return MMI_TRUE;
        }
    }
#endif /* (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */
    if (mmi_ucm_incoming_dialer_option() == SRV_UCM_RESULT_OK)
    {
        if (GetChildMenuIDIndexByParentMenuID(MENU_ID_UCM_INCOMING_OPTION, MENU_ID_UCM_INCOMING_OPTION_DIALER) >= 0)
        {
            return MMI_TRUE;
        }
    } 
    
#ifdef __MMI_UCM_DEFLECT__
    if (mmi_ucm_deflect_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        if (GetChildMenuIDIndexByParentMenuID(MENU_ID_UCM_INCOMING_OPTION, MENU_ID_UCM_INCOMING_OPTION_DEFLECT) >= 0)
        {
            return MMI_TRUE;
        }
    } 
#endif /* __MMI_UCM_DEFLECT__ */    
    
    if (mmi_ucm_replace_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        if (GetChildMenuIDIndexByParentMenuID(MENU_ID_UCM_INCOMING_OPTION, MENU_ID_UCM_INCOMING_OPTION_REPLACE) >= 0)
        {
            return MMI_TRUE;
        }
    } 
    
#ifdef __MMI_UCM_REDIAL_FROM_OTHER_SIM__
    if (mmi_ucm_redial_from_other_sim_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        if (GetChildMenuIDIndexByParentMenuID(MENU_ID_UCM_INCOMING_OPTION, MENU_ID_UCM_INCOMING_OPTION_REDIAL_FROM_OTHER_SIM) >= 0)
        {
            return MMI_TRUE;
        }
    }        
#endif /* __MMI_UCM_REDIAL_FROM_OTHER_SIM__ */

#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__
    if (mmi_ucm_simple_option(SRV_UCM_END_ALL_ACTIVE_ACT, MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
#if !defined(__MMI_UCM_SLIM__)
        if (GetChildMenuIDIndexByParentMenuID(MENU_ID_UCM_INCOMING_OPTION, MENU_ID_UCM_INCOMING_OPTION_END_ALL_ACTIVE) >= 0)
        {
            return MMI_TRUE;
        }
#endif
    }      
#endif
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
    if (mmi_ucm_simple_option(SRV_UCM_END_ALL_HELD_ACT, MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
		#if !defined(__MMI_UCM_SLIM__)
        if (GetChildMenuIDIndexByParentMenuID(MENU_ID_UCM_INCOMING_OPTION, MENU_ID_UCM_INCOMING_OPTION_END_ALL_HELD) >= 0)
        {
            return MMI_TRUE;
        }
      #endif
    }
#endif

#ifdef __MMI_BG_SOUND_EFFECT__
    if (mmi_ucm_bk_sound_incoming_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        if (GetChildMenuIDIndexByParentMenuID(MENU_ID_UCM_INCOMING_OPTION, MENU_ID_UCM_INCOMING_OPTION_BACKGROUND_SOUND) >= 0)
        {
            return MMI_TRUE;
        }
    }
#endif /* __MMI_BG_SOUND_EFFECT__ */

#ifdef __VOICE_CHANGER_SUPPORT__
    if (GetChildMenuIDIndexByParentMenuID(MENU_ID_UCM_INCOMING_OPTION, MENU_ID_CALLSET_MAGIC_VOICE) >= 0)
    {
        return MMI_TRUE;
    }
#endif /* __VOICE_CHANGER_SUPPORT__ */

#ifdef __MMI_BT_SUPPORT__
    if (mmi_ucm_swap_bt_audio_path_option(MMI_UCM_PERMIT_ONLY, SRV_UCM_INCOMING_STATE) == SRV_UCM_RESULT_OK)
    {
        if (GetChildMenuIDIndexByParentMenuID(MENU_ID_UCM_INCOMING_OPTION, MENU_ID_UCM_INCOMING_OPTION_SWITCH_AUDIO_PATH) >= 0)
        {
            return MMI_TRUE;
        }
    }
#endif /* __MMI_BT_SUPPORT__ */

#ifdef __MMI_UCM_REJECT_BY_SMS__
    if (mmi_ucm_rej_by_sms_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        if (GetChildMenuIDIndexByParentMenuID(MENU_ID_UCM_INCOMING_OPTION, MENU_ID_UCM_INCOMING_OPTION_REJ_BY_SMS) >= 0)
        {
            return MMI_TRUE;
        }
    } 
#endif /* __MMI_UCM_REJECT_BY_SMS__ */
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_handle_incoming_option
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_handle_incoming_option(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_answer_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_ANSWER, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_ANSWER, MMI_TRUE);
    }

#if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))

    if (mmi_ucm_answer_by_voice_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_ANSWER_BY_VOICE, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_ANSWER_BY_VOICE, MMI_TRUE);
    }      
#endif /* defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */


    if (mmi_ucm_incoming_dialer_option() == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_DIALER, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_DIALER, MMI_TRUE);
    }   

#ifdef __MMI_UCM_DEFLECT__
    if (mmi_ucm_deflect_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_DEFLECT, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_DEFLECT, MMI_TRUE);
    }
#endif /* __MMI_UCM_DEFLECT__ */    

    if (mmi_ucm_replace_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_REPLACE, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_REPLACE, MMI_TRUE);
    }   
    
#ifdef __MMI_UCM_REDIAL_FROM_OTHER_SIM__
    if (mmi_ucm_redial_from_other_sim_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_REDIAL_FROM_OTHER_SIM, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_REDIAL_FROM_OTHER_SIM, MMI_TRUE);
    }         
#endif /* __MMI_UCM_REDIAL_FROM_OTHER_SIM__ */

#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__
    if (mmi_ucm_simple_option(SRV_UCM_END_ALL_ACTIVE_ACT, MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
#if !defined(__MMI_UCM_SLIM__)
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_END_ALL_ACTIVE, MMI_FALSE);
#endif
    }
    else
    {
#if !defined(__MMI_UCM_SLIM__)
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_END_ALL_ACTIVE, MMI_TRUE);
#endif
    }       
#endif

#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
    if (mmi_ucm_simple_option(SRV_UCM_END_ALL_HELD_ACT, MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
#if !defined(__MMI_UCM_SLIM__)
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_END_ALL_HELD, MMI_FALSE);
#endif
    }
    else
    {
#if !defined(__MMI_UCM_SLIM__)
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_END_ALL_HELD, MMI_TRUE);
#endif
    }
#endif

#ifdef __MMI_BG_SOUND_EFFECT__
    if (mmi_ucm_bk_sound_incoming_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_BACKGROUND_SOUND, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_BACKGROUND_SOUND, MMI_TRUE);
    }
#endif /* __MMI_BG_SOUND_EFFECT__ */

#ifdef __VOICE_CHANGER_SUPPORT__
    cui_menu_set_item_hidden(owner_gid, MENU_ID_CALLSET_MAGIC_VOICE, MMI_FALSE);
#endif /* __VOICE_CHANGER_SUPPORT__ */

#ifdef __MMI_BT_SUPPORT__
    if (mmi_ucm_swap_bt_audio_path_option(MMI_UCM_PERMIT_ONLY, SRV_UCM_INCOMING_STATE) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_SWITCH_AUDIO_PATH, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_SWITCH_AUDIO_PATH, MMI_TRUE);
    }
#endif /* __MMI_BT_SUPPORT__ */

#ifdef __MMI_UCM_REJECT_BY_SMS__
    if (mmi_ucm_rej_by_sms_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_REJ_BY_SMS, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCOMING_OPTION_REJ_BY_SMS, MMI_TRUE);
    }  
#endif /* __MMI_UCM_REJECT_BY_SMS__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incoming_call_opt_proc
 * DESCRIPTION
 *  The proc function of incoming call option
 *
 * PARAMETERS
 *  evt                     [IN]: event
 *  
 * RETURNS
 *  MMI_RET_OK: handle this event successfully
 *  Others: fail to handle this event
 *****************************************************************************/
mmi_ret mmi_ucm_incoming_call_opt_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL dialer_act_is_executed = MMI_FALSE;
#ifdef __VOICE_CHANGER_SUPPORT__
    MMI_BOOL act_is_executed = MMI_FALSE;
#endif    
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            /* 0 , non-leaf */
            if (MENU_ID_UCM_INCOMING_OPTION == menu_evt->parent_menu_id) 
            {
                /* Decide if need to hide each menu items */
                mmi_ucm_handle_incoming_option(menu_evt->sender_id);
            }
            else if (MENU_ID_UCM_IN_CALL_DIALER_OPTION == menu_evt->parent_menu_id)
            {
                /* Decide if need to hide each menu items */
                mmi_ucm_handle_in_call_dialer_option(menu_evt->sender_id);
            }
        #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
            else if (MENU_ID_UCM_SIM_SELECT == menu_evt->parent_menu_id)
            {
                mmi_ucm_add_sim_name_for_sim_select(menu_evt->sender_id);
            }
        #endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
        }
        break;

        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
        #ifdef __MMI_UCM_DEFLECT__
            if (MENU_ID_UCM_INCOMING_OPTION_DEFLECT == menu_evt->highlighted_menu_id)
            {
                if (mmi_is_redrawing_bk_screens() == TRUE)
                {
                    /* To prevent the dial_pad_buffer is reset incorrectly */
                    return MMI_RET_OK;
                }
                memset(g_ucm_p->mo_info.dial_pad_buffer, 0, sizeof(g_ucm_p->mo_info.dial_pad_buffer));
            }
        #endif /* __MMI_UCM_DEFLECT__ */
        }
        break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch(menu_evt->highlighted_menu_id)
            {
                /* 1st , leaf */
                case MENU_ID_UCM_INCOMING_OPTION_ANSWER:
                {
                    mmi_ucm_incoming_call_sendkey();
                }
                break;

            #if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
                case MENU_ID_UCM_INCOMING_OPTION_ANSWER_BY_VOICE:
                {
                    mmi_ucm_vt_incoming_call_answer_by_voice();
                }
                break;
            #endif /* (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */

                /* 1st , leaf */
                case MENU_ID_UCM_INCOMING_OPTION_DIALER:
                {
                    mmi_ucm_pre_entry_dtmf_editor();
                }
                break;

            #ifdef __MMI_UCM_DEFLECT__
                /* 1st , leaf */
                case MENU_ID_UCM_INCOMING_OPTION_DEFLECT:
                {
                    if (mmi_is_redrawing_bk_screens() == TRUE)
                    {
                        /* To prevent the dial_pad_buffer is reset incorrectly */
                        return MMI_RET_OK;
                    }
                    mmi_ucm_enter_deflect();
                }
                break;
            #endif /* __MMI_UCM_DEFLECT__ */    

                /* 1st , leaf */
                case MENU_ID_UCM_INCOMING_OPTION_REPLACE:
                {
                    mmi_ucm_replace();
                }
                break;

            #ifdef __MMI_UCM_REDIAL_FROM_OTHER_SIM__
                /* 1st , leaf */
                case MENU_ID_UCM_INCOMING_OPTION_REDIAL_FROM_OTHER_SIM:
                {
                    mmi_ucm_redial_from_other_sim();
                }
                break;
            #endif /* __MMI_UCM_REDIAL_FROM_OTHER_SIM__ */

                /* 1st , leaf */
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__
#if !defined(__MMI_UCM_SLIM__)
                case MENU_ID_UCM_INCOMING_OPTION_END_ALL_ACTIVE:
                {
                    mmi_ucm_end_all_active_action();
                }
                break;
#endif
#endif
                /* 1st , leaf */
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
#if !defined(__MMI_UCM_SLIM__)
                case MENU_ID_UCM_INCOMING_OPTION_END_ALL_HELD:
                {
                    mmi_ucm_end_all_held_action();
                }
                break;
#endif
#endif

            #ifdef __MMI_BG_SOUND_EFFECT__    
                /* 1st , leaf */
                case MENU_ID_UCM_INCOMING_OPTION_BACKGROUND_SOUND:
                {
                    mmi_ucm_entry_bgs_effect_select_action(GRP_ID_UCM_MT);
                }
                break;
            #endif /* __MMI_BG_SOUND_EFFECT__ */   

            #ifdef __VOICE_CHANGER_SUPPORT__
                case MENU_ID_CALLSET_MAGIC_VOICE:
                {
                    mmi_callset_magic_voice_launch();
                    act_is_executed = MMI_TRUE;                    
                }
                break;
            #endif /* __VOICE_CHANGER_SUPPORT__ */

            #ifdef __MMI_BT_SUPPORT__
                /* 1st , leaf */
                case MENU_ID_UCM_INCOMING_OPTION_SWITCH_AUDIO_PATH:
                {
                    mmi_ucm_incoming_bt_set_audio_path_action();
                }
                break;
            #endif /* __MMI_BT_SUPPORT__ */
                
            #ifdef __MMI_UCM_REJECT_BY_SMS__
                /* 1st , leaf */
                case MENU_ID_UCM_INCOMING_OPTION_REJ_BY_SMS:
                {
                    mmi_ucm_get_sms_template_action();
                }
                break;
            #endif /* __MMI_UCM_REJECT_BY_SMS__ */

                /* 1st , leaf - in call dialer */
                case MENU_ID_UCM_IN_CALL_DIALER_OPTION_DIAL:
                {
                    mmi_ucm_make_call_from_incall_dialer_option();
                    dialer_act_is_executed = MMI_TRUE;
                }
                break;

                /* 1st , leaf - in call dialer */
                case MENU_ID_UCM_IN_CALL_DIALER_OPTION_SAVE:
                {
                    mmi_ucm_entry_save_phonebook();
                    dialer_act_is_executed = MMI_TRUE;
                }
                break;

            #if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
            #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_ID_UCM_FROM_SIM1:
                case MENU_ID_UCM_FROM_SIM2:
            #if (MMI_MAX_SIM_NUM >= 3)
                case MENU_ID_UCM_FROM_SIM3:
            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_ID_UCM_FROM_SIM4:
            #endif /* (MMI_MAX_SIM_NUM >= 4) */
            #endif /* (MMI_MAX_SIM_NUM >= 3) */
            #endif /* (MMI_MAX_SIM_NUM >= 2) */
                {
                    mmi_ucm_dial_call_from_sim_select(menu_evt->highlighted_menu_id);
                }
                break;
            #endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */

                default:
                break;
            }

            /* Because the action event is triggered by post, therefore the cui will be closed before new screen is displayed
               , and anti-blink case can not cover hardware blt screen, caller video belongs to HW display, therefore the caller 
               video  will displayed between the short period , so we only let next screen to trigger closing meui CUI */
            /*
            if (act_is_executed && 
                GRP_ID_INVALID != g_ucm_p->cui_info.incoming_opt_cui_id)
            {
                cui_menu_close(menu_evt->sender_id);
                g_ucm_p->cui_info.incoming_opt_cui_id = GRP_ID_INVALID;
            } 
            */
            
            /* close menu cui after user selects any leave item */

        #ifdef __VOICE_CHANGER_SUPPORT__
            if (act_is_executed)
            {
                mmi_ucm_close_cui(&g_ucm_p->cui_info.incoming_opt_cui_id);
            }
        #endif

            if (dialer_act_is_executed) 
            {
                mmi_ucm_close_cui(&g_ucm_p->cui_info.in_call_dialer_opt_cui_id);
            }
        }
        break;

        /*CUI Menu close request event : send request to APP for closing the CUI menu instance */
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            if (menu_evt->sender_id == g_ucm_p->cui_info.incoming_opt_cui_id)
            {
                g_ucm_p->cui_info.incoming_opt_cui_id = GRP_ID_INVALID;
            }
            else if (menu_evt->sender_id == g_ucm_p->cui_info.in_call_dialer_opt_cui_id)
            {
                g_ucm_p->cui_info.in_call_dialer_opt_cui_id = GRP_ID_INVALID;
            }
            
            cui_menu_close(menu_evt->sender_id);
        }
        break;

        default:
        break;
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_incoming_call_option
 * DESCRIPTION
 *  Shows the incoming call option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_incoming_call_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* mmi_ucm_incoming_call_opt_proc */
    /* create menu cui */
    g_ucm_p->cui_info.incoming_opt_cui_id = cui_menu_create_and_run(
                            GRP_ID_UCM_MT, 
                            CUI_MENU_SRC_TYPE_RESOURCE, 
                            CUI_MENU_TYPE_OPTION, 
                            MENU_ID_UCM_INCOMING_OPTION, 
                            MMI_FALSE, /* Use global resource */
                            NULL);
    
    //cui_menu_enable_cascading_option_menu(g_ucm_p->cui_info.incoming_opt_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incoming_call_show_option
 * DESCRIPTION
 *  Check if incoming call option can be displayed or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means incoming call option should show;
 *  FALSE means incoming call option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_incoming_call_show_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (srv_ucm_is_emergency_call() == MMI_TRUE)
    {
        return MMI_FALSE;
    }

    return mmi_ucm_is_any_incoming_call_opt_item_exist();
}
#endif /* __MMI_UCM_SLIM__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_any_incall_opt_item_exist
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_any_incall_opt_item_exist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL execute_flag;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Operator has independent ucm.res file, the menu item in different ucm.res is different.
       If any of the items is not in all ucm.res, should use GetChildMenuIDIndexByParentMenuID()
       to check if the menu item is in incall option now. */
    if (mmi_ucm_single_group_option(SRV_UCM_HOLD_ACT, MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        return MMI_TRUE;
    }
    
    if (mmi_ucm_single_group_option(SRV_UCM_RETRIEVE_ACT, MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        return MMI_TRUE;
    }
   
    if (mmi_ucm_multiple_group_option(SRV_UCM_SWAP_ACT, MMI_UCM_PERMIT_ONLY, &execute_flag) == SRV_UCM_RESULT_OK)
    {
        return MMI_TRUE;
    }
    
    if (mmi_ucm_multiple_group_option(SRV_UCM_CONFERENCE_ACT, MMI_UCM_PERMIT_ONLY, &execute_flag) == SRV_UCM_RESULT_OK)
    {
        return MMI_TRUE;
    }
   
    if (mmi_ucm_single_call_option(SRV_UCM_SPLIT_ACT, SRV_UCM_CALL_STATE_CONNECTED, MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        return MMI_TRUE;
    }
    
    if (mmi_ucm_single_call_option(SRV_UCM_END_SINGLE_ACT, SRV_UCM_CALL_STATE_CONNECTED, MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        return MMI_TRUE;
    }

    if (mmi_ucm_end_conference_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        return MMI_TRUE;
    }  

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 1)
    {
        if (mmi_ucm_simple_option(SRV_UCM_END_ALL_ACT, MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
        {
            return MMI_TRUE;
        }
    }

#if defined(__MMI_UCM_TRANSFER__) || defined(__MMI_UCM_ECT__)
    if (mmi_ucm_transfer_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        return MMI_TRUE;
    }
#endif /* defined(__MMI_UCM_TRANSFER__) || defined(__MMI_UCM_ECT__) */

#ifndef __MMI_UCM_SLIM__
    if (mmi_ucm_new_call_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        return MMI_TRUE;
    }
#endif /* __MMI_UCM_SLIM__ */

#ifdef __MMI_BACKGROUND_CALL__
    if (mmi_ucm_enter_general_app_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        return MMI_TRUE;
    }
#else
    if (mmi_ucm_enter_general_app_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        return MMI_TRUE;
    }

#if (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER)
    if (mmi_ucm_browser_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
           /* if the menu is not in incall option. */
        if (GetChildMenuIDIndexByParentMenuID(MENU_ID_UCM_INCALL_OPTION, MENU_ID_UCM_INCALL_OPTION_BROWSER) >= 0)
        {
            return MMI_TRUE;
        }
    }   
#endif /* (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER) */
    
#endif /* __MMI_BACKGROUND_CALL__ */

#ifdef __VOICE_CHANGER_SUPPORT__
    if (GetChildMenuIDIndexByParentMenuID(MENU_ID_UCM_INCALL_OPTION, MENU_ID_CALLSET_MAGIC_VOICE) >= 0)
    {
        return MMI_TRUE;
    }
#endif /* __VOICE_CHANGER_SUPPORT__ */

#ifdef __MMI_VIDEO_TELEPHONY__
    if (mmi_ucm_switch_to_video_call_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
           /* if the menu is not in incall option. */
        if (GetChildMenuIDIndexByParentMenuID(MENU_ID_UCM_INCALL_OPTION, MENU_ID_UCM_INCALL_OPTION_SWITCH_TO_VIDEO_CALL) >= 0)
        {
            return MMI_TRUE;
        }
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __MMI_SOUND_RECORDER__
    if (mmi_ucm_sound_recorder_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        return MMI_TRUE;
    }
#endif /* __MMI_SOUND_RECORDER__ */

#ifdef __MMI_BG_SOUND_EFFECT__    
    if (mmi_ucm_bk_sound_in_call_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
           /* if the menu is not in incall option. */
        if (GetChildMenuIDIndexByParentMenuID(MENU_ID_UCM_INCALL_OPTION, MENU_ID_BGSND_CM_OPT_EFFECT) >= 0)
        {
            return MMI_TRUE;
        }
    }
#endif /* __MMI_BG_SOUND_EFFECT__ */

#ifndef __MMI_UCM_RSK_MUTE__
    if (mmi_ucm_mute_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        return MMI_TRUE;
    }
#endif /* __MMI_UCM_RSK_MUTE__ */

#ifndef __MMI_UCM_SLIM__
    if (mmi_ucm_dtmf_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
           /* if the menu is not in incall option. */
        if (GetChildMenuIDIndexByParentMenuID(MENU_ID_UCM_INCALL_OPTION, MENU_ID_UCM_INCALL_OPTION_DTMF) >= 0)
        {
            return MMI_TRUE;
        }
    }
#endif /* __MMI_UCM_SLIM__ */    

#ifdef __MMI_BT_SUPPORT__
    if (mmi_ucm_swap_bt_audio_path_option(MMI_UCM_PERMIT_ONLY, SRV_UCM_CALL_STATE_CONNECTED) == SRV_UCM_RESULT_OK)
    {
        return MMI_TRUE;
    }
#endif /* __MMI_BT_SUPPORT__ */    

#ifdef __CTM_SUPPORT__
    if (mmi_ucm_ctm_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        return MMI_TRUE;
    }

    if (mmi_ucm_ctm_setting_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        return MMI_TRUE;
    }
#endif /* __CTM_SUPPORT__ */

#ifndef __OP01_FWPBW__
    if (!(mmi_frm_kbd_is_key_supported(KEY_VOL_UP) || mmi_frm_kbd_is_key_supported(KEY_VOL_DOWN)))
    {
        return MMI_TRUE;
    }
#endif /* __OP01_FWPBW__ */

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_handle_incall_option
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_handle_incall_option(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL execute_flag;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_single_group_option(SRV_UCM_HOLD_ACT, MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_HOLD, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_HOLD, MMI_TRUE);
    }

    if (mmi_ucm_single_group_option(SRV_UCM_RETRIEVE_ACT, MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_RETRIEVE, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_RETRIEVE, MMI_TRUE);
    }

    if (mmi_ucm_multiple_group_option(SRV_UCM_SWAP_ACT, MMI_UCM_PERMIT_ONLY, &execute_flag) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_SWAP, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_SWAP, MMI_TRUE);
    }

    if (mmi_ucm_multiple_group_option(SRV_UCM_CONFERENCE_ACT, MMI_UCM_PERMIT_ONLY, &execute_flag) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_CONF, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_CONF, MMI_TRUE);
    }

    if (mmi_ucm_single_call_option(SRV_UCM_SPLIT_ACT, SRV_UCM_CALL_STATE_CONNECTED, MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_SPLIT, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_SPLIT, MMI_TRUE);
    }

    if (mmi_ucm_single_call_option(SRV_UCM_END_SINGLE_ACT, SRV_UCM_CALL_STATE_CONNECTED, MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_END_SINGLE, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_END_SINGLE, MMI_TRUE);
    }

    if (mmi_ucm_end_conference_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_END_CONF, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_END_CONF, MMI_TRUE);
    }

    if ((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 1) &&
        (mmi_ucm_simple_option(SRV_UCM_END_ALL_ACT, MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK))
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_END_ALL, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_END_ALL, MMI_TRUE);
    }

#if defined(__MMI_UCM_TRANSFER__) || defined(__MMI_UCM_ECT__)
    if (mmi_ucm_transfer_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_TRANSFER, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_TRANSFER, MMI_TRUE);
    }
#endif /* defined(__MMI_UCM_TRANSFER__) || defined(__MMI_UCM_ECT__) */

#ifndef __MMI_UCM_SLIM__
    if (mmi_ucm_new_call_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_NEW_CALL, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_NEW_CALL, MMI_TRUE);
    }
#endif /* __MMI_UCM_SLIM__ */

#if defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
    if (mmi_ucm_enter_general_app_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_HOMESCREEN, MMI_FALSE);        
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_BACKGROUND, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_HOMESCREEN, MMI_TRUE);        
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_BACKGROUND, MMI_TRUE);
    }
#else /* __MMI_BACKGROUND_CALL_WITH_NCENTER__ */

#ifdef __MMI_BACKGROUND_CALL__
    if (mmi_ucm_enter_general_app_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_MAIN_MENU, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_MAIN_MENU, MMI_TRUE);
    }
 
#else
    if (mmi_ucm_enter_general_app_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_PHONEBOOK, MMI_FALSE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_CALLLOG, MMI_FALSE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_SMS, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_PHONEBOOK, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_CALLLOG, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_SMS, MMI_TRUE);
    }
#if (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER)
    if (mmi_ucm_browser_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_BROWSER, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_BROWSER, MMI_TRUE);
    }
#endif /* (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER) */
    
#endif /* __MMI_BACKGROUND_CALL__ */
#endif /* __MMI_BACKGROUND_CALL_WITH_NCENTER__ */

#ifdef __VOICE_CHANGER_SUPPORT__
    cui_menu_set_item_hidden(owner_gid, MENU_ID_CALLSET_MAGIC_VOICE, MMI_FALSE);
#endif /* __VOICE_CHANGER_SUPPORT__ */

#ifdef __MMI_VIDEO_TELEPHONY__  
    if (mmi_ucm_switch_to_video_call_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_SWITCH_TO_VIDEO_CALL, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_SWITCH_TO_VIDEO_CALL, MMI_TRUE);
    }
#endif  /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __MMI_SOUND_RECORDER__
    if (mmi_ucm_sound_recorder_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_SOUND_RECORDER, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_SOUND_RECORDER, MMI_TRUE);
    }
#endif

#ifdef __MMI_BG_SOUND_EFFECT__ 
    if (mmi_ucm_bk_sound_in_call_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_BGSND_CM_OPT_EFFECT, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_BGSND_CM_OPT_EFFECT, MMI_TRUE);
    }
#endif /* __MMI_BG_SOUND_EFFECT__ */
#ifndef __MMI_UCM_RSK_MUTE__
#ifdef __SLIM_UCM__
    if (mmi_ucm_mute_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
		if(srv_speech_is_phone_mute())
		{/*Unmute*/
			cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_MUTE, MMI_TRUE);
			cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_UNMUTE, MMI_FALSE);
		}
		else
		{/*Mute*/
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_MUTE, MMI_FALSE);
			cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_UNMUTE, MMI_TRUE);
		}
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_MUTE, MMI_TRUE);
		cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_UNMUTE, MMI_TRUE);  
    }
#else
    if (mmi_ucm_mute_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_MUTE, MMI_FALSE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_MUTE_ON, MMI_FALSE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_MUTE_OFF, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_MUTE, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_MUTE_ON, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_MUTE_OFF, MMI_TRUE);        
    }
#endif
#endif /* __MMI_UCM_RSK_MUTE__ */

#ifndef __MMI_UCM_SLIM__
    if (mmi_ucm_dtmf_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_DTMF, MMI_FALSE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_DTMF_ON, MMI_FALSE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_DTMF_OFF, MMI_FALSE);        
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_DTMF, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_DTMF_ON, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_DTMF_OFF, MMI_TRUE);           
    }
#endif /* __MMI_UCM_SLIM__ */

#ifdef __MMI_BT_SUPPORT__
    if (mmi_ucm_swap_bt_audio_path_option(MMI_UCM_PERMIT_ONLY, SRV_UCM_CALL_STATE_CONNECTED) == SRV_UCM_RESULT_OK
	#ifdef __MMI_BT_CALL_SUPPORT__
			&& (!srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION))
	#endif // __MMI_BT_CALL_SUPPORT__
		)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_SWITCH_AUDIO_PATH, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_SWITCH_AUDIO_PATH, MMI_TRUE);
    }
#endif /* __MMI_BT_SUPPORT__ */

#ifdef __CTM_SUPPORT__
    if (mmi_ucm_ctm_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_CTM_CONNECT, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_CTM_CONNECT, MMI_TRUE);
    }

    if (mmi_ucm_ctm_setting_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_CTM_SETTING, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_CTM_SETTING, MMI_TRUE);
    }
#endif /* __CTM_SUPPORT__ */

#ifdef __MMI_DUAL_MIC_SUPPORT__
    if (mmi_ucm_noice_reduction_option(MMI_UCM_PERMIT_ONLY) != SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_ENABLE_NOICE_REDUCTION, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_DISABLE_NOICE_REDUCTION, MMI_TRUE);
    }
    else if (MMI_TRUE == mmi_ucm_get_dual_mic_nr_status())
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_ENABLE_NOICE_REDUCTION, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_DISABLE_NOICE_REDUCTION, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_ENABLE_NOICE_REDUCTION, MMI_FALSE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_DISABLE_NOICE_REDUCTION, MMI_TRUE);
    }
#endif /* __MMI_DUAL_MIC_SUPPORT__ */

#ifndef __OP01_FWPBW__
    if (mmi_frm_kbd_is_key_supported(KEY_VOL_UP) || mmi_frm_kbd_is_key_supported(KEY_VOL_DOWN))
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_SPEAKER_VOLUME, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_INCALL_OPTION_SPEAKER_VOLUME, MMI_FALSE);
    }
#endif /* __OP01_FWPBW__ */
}

#if (defined( __MMI_BT_CALL_SUPPORT__) && defined(__MMI_TELEPHONY_SUPPORT__))
static void mmi_ucm_call_select_sendkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dial_from_bt_para_p->menu_index == 0)
    {
        mmi_ucm_call_launch(0,g_make_call_para_bt);
    }
    else if (g_dial_from_bt_para_p->menu_index > 0 &&  g_dial_from_bt_para_p->menu_index <= SRV_UCM_BT_MAX_DEV)
    {
        memcpy(&g_dial_from_bt_para_p->make_call_from_bt.dev_addr, 
               &g_dial_from_bt_para_p->dev_addr[g_dial_from_bt_para_p->menu_index-1],
               sizeof(srv_bt_cm_bt_addr));
        g_ucm_p->mo_info.callback = NULL;
        mmi_ucm_call_launch_bt(&g_dial_from_bt_para_p->make_call_from_bt);
    }
}

static MMI_BOOL mmi_ucm_is_valid_num_bt(U16* ucs2_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 num_uri[SRV_UCM_BT_MAX_NUM_URI_LEN + 1];    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ucs2_num == NULL)
    {
        return MMI_FALSE;
    }
    memset(num_uri, 0, sizeof(num_uri));
    mmi_ucs2_to_asc((CHAR*)num_uri, (CHAR*)ucs2_num);
    if (num_uri[0] == '*' || num_uri[0] == '#')
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}

static void mmi_ucm_call_select_main_menu_entry(MMI_ID cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_dev_info_struct dev_info;
    S32 srv_hd_list[SRV_UCM_BT_MAX_DEV];
    U32 dev_count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dial_from_bt_para_p == NULL)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SELECT_POS, 101);
        g_dial_from_bt_para_p = OslMalloc(sizeof(mmi_ucm_dial_from_bt_struct));
        memset(g_dial_from_bt_para_p, 0, sizeof(mmi_ucm_dial_from_bt_struct));
    }

    mmi_ucm_init_bt_call_para(&g_dial_from_bt_para_p->make_call_from_bt, g_make_call_para_bt);

    if (srv_sim_ctrl_is_inserted(MMI_SIM1) && srv_mode_switch_is_network_service_available())
    {
        cui_menu_set_item_disabled(cui_gid, MENU_ID_UCM_FROM_LOCAL_CALL, MMI_FALSE);
    }
#if (MMI_MAX_SIM_NUM == 2)
    else if (srv_sim_ctrl_is_inserted(MMI_SIM2) && srv_mode_switch_is_network_service_available())
    {
        cui_menu_set_item_disabled(cui_gid, MENU_ID_UCM_FROM_LOCAL_CALL, MMI_FALSE);
    }
#endif /* MMI_MAX_SIM_NUM == 2 */
    else
    {
        cui_menu_set_item_disabled(cui_gid, MENU_ID_UCM_FROM_LOCAL_CALL, MMI_TRUE);
    }

    if (!srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION)
        || !mmi_ucm_is_valid_num_bt(g_make_call_para_bt->ucs2_num_uri))
    {
        cui_menu_set_item_hidden(cui_gid, MENU_ID_UCM_FROM_BT_CALL, MMI_FALSE);
        cui_menu_set_item_hidden(cui_gid, MENU_ID_UCM_FROM_BT_CALL2, MMI_FALSE);
        cui_menu_set_item_disabled(cui_gid, MENU_ID_UCM_FROM_BT_CALL, MMI_TRUE);
        cui_menu_set_item_disabled(cui_gid, MENU_ID_UCM_FROM_BT_CALL2, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_hidden(cui_gid, MENU_ID_UCM_FROM_BT_CALL, MMI_FALSE);

        dev_count = srv_ucm_bt_query_connected_dev_count(srv_hd_list);
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SELECT_MENU_POS_WITH_1P, 201, dev_count);
        MMI_ASSERT(SRV_UCM_BT_MAX_DEV >= dev_count);
        if (dev_count > 0)
        {
            if (srv_ucm_bt_query_connected_dev_info(srv_hd_list[0], &dev_info))
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SELECT_MENU_POS_WITH_1P, 202, srv_hd_list[0]);
                cui_menu_set_item_string(cui_gid, MENU_ID_UCM_FROM_BT_CALL, (WCHAR*)dev_info.dev_name);
                cui_menu_set_item_disabled(cui_gid, MENU_ID_UCM_FROM_BT_CALL, MMI_FALSE);
                memcpy(&g_dial_from_bt_para_p->dev_addr[0], &dev_info.dev_addr, sizeof(srv_bt_cm_bt_addr));
                memcpy(&g_dial_from_bt_para_p->make_call_from_bt.dev_addr, &dev_info.dev_addr, sizeof(srv_bt_cm_bt_addr));
            }
            if (dev_count > 1)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SELECT_MENU_POS_WITH_1P, 203, srv_hd_list[1]);
                if (srv_ucm_bt_query_connected_dev_info(srv_hd_list[1], &dev_info))
                {
                    cui_menu_set_item_hidden(cui_gid, MENU_ID_UCM_FROM_BT_CALL2, MMI_FALSE);
                    cui_menu_set_item_string(cui_gid, MENU_ID_UCM_FROM_BT_CALL2, (WCHAR*)dev_info.dev_name);
                    cui_menu_set_item_disabled(cui_gid, MENU_ID_UCM_FROM_BT_CALL2, MMI_FALSE);
                    memcpy(&g_dial_from_bt_para_p->dev_addr[dev_count-1], &dev_info.dev_addr, sizeof(srv_bt_cm_bt_addr));
                }
            }
            else
            {
                cui_menu_set_item_hidden(cui_gid, MENU_ID_UCM_FROM_BT_CALL2, MMI_TRUE);
            }
        }
    }
    SetKeyDownHandler(mmi_ucm_call_select_sendkey_hdlr, KEY_SEND);
}

mmi_ret mmi_ucm_call_select_menu_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_after_make_call_cb_struct make_call_cb_para;
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_ucm_call_select_main_menu_entry(menu_evt->sender_id);
            break;

        case EVT_ID_CUI_MENU_ITEM_HILITE:
            if (MENU_ID_UCM_FROM_LOCAL_CALL == menu_evt->highlighted_menu_id)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SELECT_POS, 102);
                g_dial_from_bt_para_p->menu_index = 0;
            }
            else if (MENU_ID_UCM_FROM_BT_CALL == menu_evt->highlighted_menu_id)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SELECT_POS, 103);
                g_dial_from_bt_para_p->menu_index = 1;
            }
            else if (MENU_ID_UCM_FROM_BT_CALL2 == menu_evt->highlighted_menu_id)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SELECT_POS, 104);
                g_dial_from_bt_para_p->menu_index = 2;
            }
            break;

        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_ITEM_TAP:
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        {
            switch(menu_evt->highlighted_menu_id)
            {   
                case MENU_ID_UCM_FROM_LOCAL_CALL:
                    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SELECT_POS, 301);
                    mmi_ucm_call_launch(0, g_make_call_para_bt);
                    break;

                case MENU_ID_UCM_FROM_BT_CALL:
                case MENU_ID_UCM_FROM_BT_CALL2:
                    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SELECT_POS, 302);
                    memcpy(&g_dial_from_bt_para_p->make_call_from_bt.dev_addr, 
                           &g_dial_from_bt_para_p->dev_addr[g_dial_from_bt_para_p->menu_index-1],
                           sizeof(srv_bt_cm_bt_addr));
                    g_ucm_p->mo_info.callback = NULL;
                    mmi_ucm_call_launch_bt(&g_dial_from_bt_para_p->make_call_from_bt);
                    break;

                default:
                    break;
            }
        }
            break;
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
        }
        break;
        case EVT_ID_CUI_MENU_LIST_DEINIT:

            if (g_make_call_para_bt->ucs2_num_uri != NULL)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SELECT_POS, 501);
                OslMfree(g_make_call_para_bt->ucs2_num_uri);
                g_make_call_para_bt->ucs2_num_uri = NULL;
            }
            if (g_make_call_para_bt->adv_para.phb_data != NULL)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SELECT_POS, 502);
                OslMfree(g_make_call_para_bt->adv_para.phb_data);
                g_make_call_para_bt->adv_para.phb_data = NULL;
            }
            if (g_make_call_para_bt != NULL)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SELECT_POS, 503);
                OslMfree(g_make_call_para_bt);
                g_make_call_para_bt = NULL;
            }
            if (g_dial_from_bt_para_p != NULL)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SELECT_POS, 504);
                OslMfree(g_dial_from_bt_para_p);
                g_dial_from_bt_para_p = NULL;
            }

            mmi_ucm_exec_dial_cb_by_result(SRV_UCM_RESULT_CANCEL);
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}
#endif /* __MMI_BT_CALL_SUPPORT__ && __MMI_TELEPHONY_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incall_opt_proc
 * DESCRIPTION
 *  The proc function of incall option
 *
 * PARAMETERS
 *  evt                     [IN]: event
 *  
 * RETURNS
 *  MMI_RET_OK: handle this event successfully
 *  Others: fail to handle this event
 *****************************************************************************/
mmi_ret mmi_ucm_incall_opt_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
    mmi_ret ret = MMI_RET_OK;
#ifndef __MMI_UCM_SLIM__
    U16 call_menu_id = 0;
    MMI_BOOL newcall_dialer_act_is_executed = MMI_FALSE;
#endif /* __MMI_UCM_SLIM__ */
    MMI_BOOL act_is_executed = MMI_FALSE;
    MMI_BOOL dialer_act_is_executed = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (menu_evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            switch(menu_evt->parent_menu_id)
            {   
                /* 0 , non-leaf */
                case MENU_ID_UCM_INCALL_OPTION:
                {
                    /* Decide if need to hide each menu items */
                    mmi_ucm_handle_incall_option(menu_evt->sender_id);

                #if !defined(__MMI_UCM_SLIM__)
                    /* for MENU_ID_UCM_INCALL_OPTION_NEW_CALL, because it could be a leaf or non-leaf */
                    if (GetNumOfChild_Ext(MENU_ID_UCM_INCALL_OPTION_NEW_CALL) == 1)
                    {
                        cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_UCM_INCALL_OPTION_NEW_CALL, MMI_FALSE);
                    }
                #endif /* __MMI_UCM_SLIM__ */
                #ifdef __MMI_BG_SOUND_EFFECT__
                    cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_BGSND_CM_OPT_EFFECT, MMI_FALSE);
                #endif /* __MMI_BG_SOUND_EFFECT__ */
                }
                break;

            #ifndef __MMI_UCM_RSK_MUTE__
#ifndef __SLIM_UCM__
                case MENU_ID_UCM_INCALL_OPTION_MUTE:
                {
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                    if(menu_evt->cui_menu_event_flags != CUI_MENU_LIST_FROM_HISTORY)
                    {
                        if (srv_speech_is_phone_mute() == TRUE)
                        {
                            cui_menu_set_radio_list_item(menu_evt->sender_id, MENU_ID_UCM_INCALL_OPTION_MUTE_ON);
                        }
                        else
                        {
                            cui_menu_set_radio_list_item(menu_evt->sender_id, MENU_ID_UCM_INCALL_OPTION_MUTE_OFF);
                        }
                    }
                }
                break;    
#endif  
            #endif /* __MMI_UCM_RSK_MUTE__ */        

            #ifndef __MMI_UCM_SLIM__
                case MENU_ID_UCM_INCALL_OPTION_DTMF:
                {
                    cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                    if(menu_evt->cui_menu_event_flags != CUI_MENU_LIST_FROM_HISTORY)
                    {
                        if (g_ucm_p->call_misc.is_dtmf == MMI_TRUE)
                        {
                            cui_menu_set_radio_list_item(menu_evt->sender_id, MENU_ID_UCM_INCALL_OPTION_DTMF_ON);
                        }
                        else
                        {
                            cui_menu_set_radio_list_item(menu_evt->sender_id, MENU_ID_UCM_INCALL_OPTION_DTMF_OFF);
                        }
                    }
                }
                break;
            #endif /* __MMI_UCM_SLIM__ */
                
                case MENU_ID_UCM_IN_CALL_DIALER_OPTION:
                {
                    /* Decide if need to hide each menu items */
                    mmi_ucm_handle_in_call_dialer_option(menu_evt->sender_id);
                }
                break;

            #ifndef __MMI_UCM_SLIM__
                case MENU_ID_UCM_NEW_CALL_OPTION:
                {
                    /* Decide if need to hide each menu items */
                    mmi_ucm_handle_new_call_dialer_option(menu_evt->sender_id);
                }
                break;
            #endif /* __MMI_UCM_SLIM__ */

            #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
                case MENU_ID_UCM_SIM_SELECT:
                {
                    mmi_ucm_add_sim_name_for_sim_select(menu_evt->sender_id);
                }
                break;
            #endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

                default:
                break;
            }  
        }
        break;
#ifndef __SLIM_UCM__

        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
        }
        break;
#endif
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            if (MENU_ID_UCM_INCALL_OPTION == menu_evt->parent_menu_id ||
            #ifndef __MMI_UCM_SLIM__
                MENU_ID_UCM_INCALL_OPTION_NEW_CALL == menu_evt->parent_menu_id ||
                MENU_ID_UCM_INCALL_OPTION_DTMF == menu_evt->parent_menu_id ||
            #endif /* __MMI_UCM_SLIM__ */    
            #ifndef __MMI_UCM_RSK_MUTE__
#ifdef __SLIM_UCM__
               // MENU_ID_UCM_INCALL_OPTION_MUTE == menu_evt->parent_menu_id ||
#else
                MENU_ID_UCM_INCALL_OPTION_MUTE == menu_evt->parent_menu_id ||
#endif
            #endif /* __MMI_UCM_RSK_MUTE__ */                
                MMI_FALSE)
            {
                act_is_executed = MMI_TRUE;
            }
            else if (MENU_ID_UCM_IN_CALL_DIALER_OPTION == menu_evt->parent_menu_id)
            {
                dialer_act_is_executed = MMI_TRUE;
            }
        #ifndef __MMI_UCM_SLIM__    
            else if (MENU_ID_UCM_NEW_CALL_OPTION == menu_evt->parent_menu_id)
            {
                newcall_dialer_act_is_executed = MMI_TRUE;
            }
        #endif /* __MMI_UCM_SLIM__ */

            switch(menu_evt->highlighted_menu_id)
            {
                /* 1st , leaf */
                case MENU_ID_UCM_INCALL_OPTION_HOLD:
                {
                    mmi_ucm_hold_action();
                }
                break;

                /* 1st , leaf */
                case MENU_ID_UCM_INCALL_OPTION_RETRIEVE:
                {
                    mmi_ucm_retrieve_action();
                }
                break;

                /* 1st , leaf */
                case MENU_ID_UCM_INCALL_OPTION_SWAP:
                {
                    mmi_ucm_swap_action();
                }
                break;

                /* 1st , leaf */
                case MENU_ID_UCM_INCALL_OPTION_CONF:
                {
                    mmi_ucm_conference_action();  
                }
                break;

                /* 1st , leaf */
                case MENU_ID_UCM_INCALL_OPTION_SPLIT:
                {
                    mmi_ucm_split_action();              
                }
                break;

                /* 1st , leaf */
                case MENU_ID_UCM_INCALL_OPTION_END_SINGLE:
                {
                    mmi_ucm_end_single_action();             
                }
                break;

                /* 1st , leaf */
                case MENU_ID_UCM_INCALL_OPTION_END_CONF:
                {
                    mmi_ucm_end_conference_action(); 
                }
                break;

                /* 1st , leaf */
                case MENU_ID_UCM_INCALL_OPTION_END_ALL:
                {
                    mmi_ucm_end_all_action();  
                }
                break;

            #if defined(__MMI_UCM_TRANSFER__) || defined(__MMI_UCM_ECT__)
                /* 1st , leaf */
                case MENU_ID_UCM_INCALL_OPTION_TRANSFER:
                {
                    mmi_ucm_incall_opt_transfer_act_hdlr();
                }
                break;
            #endif /* defined(__MMI_UCM_TRANSFER__) || defined(__MMI_UCM_ECT__) */
            
            #ifndef __MMI_UCM_SLIM__
                /* 1st , leaf or non-leaf */
                /* as being a leaf */
                case MENU_ID_UCM_INCALL_OPTION_NEW_CALL:
                {
                    memset(g_ucm_p->mo_info.dial_pad_buffer, 0, sizeof(g_ucm_p->mo_info.dial_pad_buffer));	
      
                    if (GetNumOfChild_Ext(MENU_ID_UCM_INCALL_OPTION_NEW_CALL) == 1)
                    {    
                        call_menu_id = GetSeqItemId_Ext(MENU_ID_UCM_INCALL_OPTION_NEW_CALL, 0);

                        switch (call_menu_id)
                        {
                            case MENU_ID_UCM_INCALL_OPTION_NEW_CALL_VOICE:
                            {
                                mmi_ucm_entry_voice_dialer_screen_action();
                            }
                            break;
                        #ifdef __MMI_VOIP__
                            case MENU_ID_UCM_INCALL_OPTION_NEW_CALL_VOIP:
                            {
                                mmi_ucm_entry_voip_dialer_screen_action();
                            }
                            break;
                        #endif /* __MMI_VOIP__ */
                            default: 
                            { 
                                MMI_ASSERT(0); 
                            } 
                        }
                    }
                    else
                    {                    
                        act_is_executed = MMI_FALSE;
                    }
                    /* menu CUI will display new call option menu if > 1, no need to handle here */
                    //cui_menu_close(menu_evt->sender_id);
                }
                break;     
                
                /* MENU_ID_UCM_INCALL_OPTION_NEW_CALL is a non leaf case */
                /* 2nd , leaf */
                case MENU_ID_UCM_INCALL_OPTION_NEW_CALL_VOICE:
                {
                    mmi_ucm_entry_voice_dialer_screen_action();
                }
                break;    
            #ifdef __MMI_VOIP__        
                /* 2nd , leaf */
                case MENU_ID_UCM_INCALL_OPTION_NEW_CALL_VOIP:
                {
                    mmi_ucm_entry_voip_dialer_screen_action();
                }
                break;        
            #endif /* __MMI_VOIP__ */
            #endif /* __MMI_UCM_SLIM__ */

            #if defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
                case MENU_ID_UCM_INCALL_OPTION_HOMESCREEN:
                {
                    mmi_ucm_go_homescreen_incall_action();
                }
                break;

                case MENU_ID_UCM_INCALL_OPTION_BACKGROUND:
                {
                    mmi_ucm_background_incall_action();
                }
                break;
            #else /* __MMI_BACKGROUND_CALL_WITH_NCENTER__ */

            #ifdef __MMI_BACKGROUND_CALL__
                /* 1st , leaf */
                case MENU_ID_UCM_INCALL_OPTION_MAIN_MENU:
                {
                    mmi_ucm_enter_main_menu();
                }
                break;      
            #else 
                /* 1st , leaf */
                case MENU_ID_UCM_INCALL_OPTION_PHONEBOOK:
                {
                    mmi_ucm_enter_phb_incall_action();
                }
                break;     

                case MENU_ID_UCM_INCALL_OPTION_CALLLOG:
                {
                    mmi_ucm_enter_clog_incall_action();
                }
                break; 
                
                /* 1st , leaf */
                case MENU_ID_UCM_INCALL_OPTION_SMS:
                {
                    mmi_ucm_enter_message_action();
                }
                break;  

            #if (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER)

                /* 1st , leaf */
                case MENU_ID_UCM_INCALL_OPTION_BROWSER:
                {
                    mmi_ucm_enter_browser_incall_action();
                }
                break;
            #endif /* (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER) */

            #endif /* __MMI_BACKGROUND_CALL__ */

            #endif /* __MMI_BACKGROUND_CALL_WITH_NCENTER__ */

            #ifdef __VOICE_CHANGER_SUPPORT__
                case MENU_ID_CALLSET_MAGIC_VOICE:
                {
                    mmi_callset_magic_voice_launch();
                    act_is_executed = MMI_TRUE;                    
                }
                break;
            #endif /* __VOICE_CHANGER_SUPPORT__ */

            #ifdef __MMI_VIDEO_TELEPHONY__  
                /* 1st , leaf */
                case MENU_ID_UCM_INCALL_OPTION_SWITCH_TO_VIDEO_CALL:
                {
                    mmi_ucm_highlight_incall_opt_switch_to_video_call_action();
                }
                break;     
            #endif /* __MMI_VIDEO_TELEPHONY__ */

            #ifdef __MMI_SOUND_RECORDER__
                /* 1st , leaf */
                case MENU_ID_UCM_INCALL_OPTION_SOUND_RECORDER:
                {
                    mmi_ucm_sndrec_in_call_action();
                }
                break;      
            #endif /* __MMI_SOUND_RECORDER__ */

            #ifdef __MMI_BG_SOUND_EFFECT__
                case MENU_ID_BGSND_CM_OPT_EFFECT:
                {
                    act_is_executed = MMI_FALSE;
                }
                break;
            #endif /* __MMI_BG_SOUND_EFFECT__ */

                /* 2nd , leaf , MENU_ID_UCM_INCALL_OPTION_MUTE. can handle it here because of using global menu id, */
            #ifndef __MMI_UCM_RSK_MUTE__
                case MENU_ID_UCM_INCALL_OPTION_MUTE:
                {                    
#ifdef __SLIM_UCM__                 
                    //act_is_executed = MMI_FALSE;
					srv_speech_mute_phone();
#else
                    act_is_executed = MMI_FALSE;
#endif
                }
                break;
#ifdef __SLIM_UCM__
				case MENU_ID_UCM_INCALL_OPTION_UNMUTE:
                {                    
                    //act_is_executed = MMI_FALSE;
					srv_speech_unmute_phone();
                }
                break;
#endif
#ifndef __SLIM_UCM__
                case MENU_ID_UCM_INCALL_OPTION_MUTE_OFF:
                case MENU_ID_UCM_INCALL_OPTION_MUTE_ON:    
                {
                    mmi_ucm_set_mute_action(menu_evt->highlighted_menu_id);
                }
                break;          
#endif        
            #endif /* __MMI_UCM_RSK_MUTE__ */        

            #ifndef __MMI_UCM_SLIM__
                case MENU_ID_UCM_INCALL_OPTION_DTMF:
                {                    
                    act_is_executed = MMI_FALSE;
                }
                break;

                /* 2nd , leaf , MENU_ID_UCM_INCALL_OPTION_DTMF. can handle it here because of using global menu id, */
                case MENU_ID_UCM_INCALL_OPTION_DTMF_ON:
                case MENU_ID_UCM_INCALL_OPTION_DTMF_OFF:
                {
                    mmi_ucm_set_dtmf_in_call(menu_evt->highlighted_menu_id);
                }
                break;
            #endif /* __MMI_UCM_SLIM__ */    

            #ifdef __MMI_BT_SUPPORT__
                /* 1st , leaf */
                case MENU_ID_UCM_INCALL_OPTION_SWITCH_AUDIO_PATH:
                {
                    mmi_ucm_incall_bt_set_audio_path_action();
                }
                break;
            #endif /* __MMI_BT_SUPPORT__ */

            #ifdef __CTM_SUPPORT__     
                /* 1st , leaf */
                case MENU_ID_UCM_INCALL_OPTION_CTM_CONNECT:
                {
                    mmi_ctm_connect_action();
                }
                break;   

                case MENU_ID_UCM_INCALL_OPTION_CTM_SETTING:
                {
                    mmi_ctm_setting_action();
                }
                break;   
            #endif /* __CTM_SUPPORT__ */

            #ifdef __MMI_DUAL_MIC_SUPPORT__
                case MENU_ID_UCM_INCALL_OPTION_ENABLE_NOICE_REDUCTION:
                case MENU_ID_UCM_INCALL_OPTION_DISABLE_NOICE_REDUCTION:
                {
                    mmi_ucm_noice_reduction_action();
                }
                break;      
            #endif /* __MMI_DUAL_MIC_SUPPORT__ */

            #ifndef __OP01_FWPBW__
                case MENU_ID_UCM_INCALL_OPTION_SPEAKER_VOLUME:
                {
                    mmi_ucm_set_volume_hdlr();
                }
                break;
            #endif /* __OP01_FWPBW__ */

                /* 1st , leaf - in call dialer */
                case MENU_ID_UCM_IN_CALL_DIALER_OPTION_DIAL:
                {
                    mmi_ucm_make_call_from_incall_dialer_option();
                }
                break;

                /* 1st , leaf - in call dialer */
                case MENU_ID_UCM_IN_CALL_DIALER_OPTION_SAVE:
                {
                    mmi_ucm_entry_save_phonebook();
                }
                break;

            #ifndef __MMI_UCM_SLIM__
                /* 1st , leaf - new call dialer opt*/
                case MENU_ID_UCM_NEW_CALL_OPTION_DIAL:
                {
                #ifdef __MMI_VOIP__    
                    if (mmi_frm_scrn_is_present(GRP_ID_UCM_INCALL, SCR_ID_UCM_VOIP_DIALER, MMI_FRM_NODE_ALL_FLAG))
                    {
                        mmi_ucm_make_voip_call_from_incall_dialer();
                    }
                    else
                #endif /* __MMI_VOIP__ */        
                    {
                        mmi_ucm_make_voice_call_from_incall_dialer_icon();
                    }
                }
                break;
                
            #if (MMI_MAX_SIM_NUM == 2)
                case MENU_ID_UCM_NEW_CALL_OPTION_DIAL_SIM1:
                {
                    mmi_ucm_make_voice_call_from_incall_dialer_sim1_action();
                }
                break;

                case MENU_ID_UCM_NEW_CALL_OPTION_DIAL_SIM2:
                {
                    mmi_ucm_make_voice_call_from_incall_dialer_sim2_action();
                }
                break;
            #endif /* (MMI_MAX_SIM_NUM == 2) */
                case MENU_ID_UCM_NEW_CALL_OPTION_SAVE:
                {
                    mmi_ucm_entry_save_phonebook_action();
                }
                break;
            #endif /* __MMI_UCM_SLIM__ */

            #if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
            #if (MMI_MAX_SIM_NUM >= 2)
                case MENU_ID_UCM_FROM_SIM1:
                case MENU_ID_UCM_FROM_SIM2:
            #if (MMI_MAX_SIM_NUM >= 3)
                case MENU_ID_UCM_FROM_SIM3:
            #if (MMI_MAX_SIM_NUM >= 4)
                case MENU_ID_UCM_FROM_SIM4:
            #endif /* (MMI_MAX_SIM_NUM >= 4) */
            #endif /* (MMI_MAX_SIM_NUM >= 3) */
            #endif /* (MMI_MAX_SIM_NUM >= 2) */
                {
                    mmi_ucm_dial_call_from_sim_select(menu_evt->highlighted_menu_id);
                }
                break;
            #endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */

                default:
                break;
            }

            /* close menu cui after user selects any leave item */
            if (act_is_executed)
            {
                mmi_ucm_close_cui(&g_ucm_p->cui_info.incall_opt_cui_id);
            }
            
            if (dialer_act_is_executed)
            {
                mmi_ucm_close_cui(&g_ucm_p->cui_info.in_call_dialer_opt_cui_id);
            }

        #ifndef __MMI_UCM_SLIM__
            if (newcall_dialer_act_is_executed)
            {
                mmi_ucm_close_cui(&g_ucm_p->cui_info.new_call_dialer_opt_cui_id);
            }
        #endif /* __MMI_UCM_SLIM__ */
        }
        break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            if (menu_evt->sender_id == g_ucm_p->cui_info.incall_opt_cui_id)
            {
                g_ucm_p->cui_info.incall_opt_cui_id = GRP_ID_INVALID;
            }
            else if (menu_evt->sender_id == g_ucm_p->cui_info.in_call_dialer_opt_cui_id)
            {
                g_ucm_p->cui_info.in_call_dialer_opt_cui_id = GRP_ID_INVALID;
            }
        #ifndef __MMI_UCM_SLIM__    
            else if (menu_evt->sender_id == g_ucm_p->cui_info.new_call_dialer_opt_cui_id)
            {
                g_ucm_p->cui_info.new_call_dialer_opt_cui_id = GRP_ID_INVALID;
            }
        #endif /* __MMI_UCM_SLIM__ */

            cui_menu_close(menu_evt->sender_id);
            return ret;
        }

        default:
        break;
    }

    /* mean option menu items which is provided by other applications */
    wgui_inputs_options_menu_handler(evt, GRP_ID_UCM_INCALL);

#if defined(__MMI_VOIP__) && !defined(__MMI_UCM_SLIM__)
    /* Because wgui_inputs_options_menu_handler api could unhide the menu which is already hidden before */
    if ((EVT_ID_CUI_MENU_LIST_ENTRY == menu_evt->evt_id) && (MENU_ID_UCM_NEW_CALL_OPTION == menu_evt->parent_menu_id))
    {
        if (MMI_FALSE == mmi_frm_scrn_is_present(GRP_ID_UCM_INCALL, SCR_ID_UCM_VOIP_DIALER, MMI_FRM_NODE_ALL_FLAG))
        {
            cui_menu_set_group_hidden(menu_evt->sender_id, MENU_GROUP_EDITOR, MMI_TRUE);
        }
    }
#endif /* defined(__MMI_VOIP__) && !defined(__MMI_UCM_SLIM__) */    
        
    ret = mmi_ucm_incall_opt_cb(evt);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incall_opt_cb
 * DESCRIPTION
 *  The callback function provided by other applications who provide their own menu items. 
 *  It is used to handle the menu cui event. currently MENU_ID_BGSND_CM_OPT_EFFECT only 
 *
 * PARAMETERS
 *  evt                     [IN]: Menu cui event
 *
 * RETURNS
 *  MMI_RET_OK: handle this event successfully
 *  Others: fail to handle this event
 *****************************************************************************/
mmi_ret mmi_ucm_incall_opt_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BG_SOUND_EFFECT__ 
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct *)evt;
#endif /* __MMI_BG_SOUND_EFFECT__ */

   /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BG_SOUND_EFFECT__       
    if (MENU_ID_BGSND_CM_OPT_EFFECT == menu_evt->highlighted_menu_id)
    {
        return mmi_bgsnd_incall_opt_proc(evt);
    }
#endif /* __MMI_BG_SOUND_EFFECT__ */

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_incall_option
 * DESCRIPTION
 *  Shows the incall option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_incall_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_ucm_incall_opt_proc */
    /* create menu cui */
    g_ucm_p->cui_info.incall_opt_cui_id = cui_menu_create_and_run(
                            GRP_ID_UCM_INCALL, 
                            CUI_MENU_SRC_TYPE_RESOURCE, 
                            CUI_MENU_TYPE_OPTION, 
                            MENU_ID_UCM_INCALL_OPTION, 
                            MMI_FALSE, /* Use global resource */
                            NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_in_call_show_option
 * DESCRIPTION
 *  Check if in call option can be displayed or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means in call option should show;
 *  FALSE means in call option should hide.
 *****************************************************************************/
MMI_BOOL mmi_ucm_in_call_show_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (srv_ucm_is_emergency_call() == MMI_TRUE)
    {
        return MMI_FALSE;
    }

    return mmi_ucm_is_any_incall_opt_item_exist();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_in_call_dialer_option
 * DESCRIPTION
 *  Enter incall dialer option scrn
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_in_call_dialer_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTER_INCALL_DIALER_OPT_P2, mmi_frm_group_get_active_id(), g_ucm_p->call_misc.dtmf_editor_SG_id);
    
    /* mmi_ucm_outgoing_call_opt_proc,  mmi_ucm_incoming_call_opt_proc, mmi_ucm_incall_opt_proc*/

    /* create menu cui */
    g_ucm_p->cui_info.in_call_dialer_opt_cui_id = cui_menu_create_and_run(
                            g_ucm_p->call_misc.dtmf_editor_SG_id, 
                            CUI_MENU_SRC_TYPE_RESOURCE, 
                            CUI_MENU_TYPE_OPTION, 
                            MENU_ID_UCM_IN_CALL_DIALER_OPTION, 
                            MMI_FALSE, /* Use global resource */
                            NULL);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_handle_in_call_dialer_option
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_handle_in_call_dialer_option(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Save to phonebook option */
    /* If __MMI_UCM_SLIM__ is enabled, incoming and outgoing call's dialer screen no lsk option, so 
       no need to judge if there is incoming or outgoing call, if dialer screen have option should 
       remove this compile option */
#ifndef __MMI_UCM_SLIM__    
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) ||
        srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL))
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_IN_CALL_DIALER_OPTION_SAVE, MMI_TRUE);
    }
    else
#endif /* __MMI_UCM_SLIM__ */
    if (SRV_UCM_RESULT_OK == mmi_ucm_enter_general_app_option(MMI_UCM_PERMIT_ONLY))
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_IN_CALL_DIALER_OPTION_SAVE, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_IN_CALL_DIALER_OPTION_SAVE, MMI_TRUE);
    }

#ifndef __MMI_UCM_PLUTO_BW__
    if (MMI_FALSE == mmi_ucm_if_number_exists())
    {
        cui_menu_set_item_disabled(owner_gid, MENU_ID_UCM_IN_CALL_DIALER_OPTION_DIAL, MMI_TRUE);
        cui_menu_set_item_disabled(owner_gid, MENU_ID_UCM_IN_CALL_DIALER_OPTION_SAVE, MMI_TRUE);
    }
    else
    {
        cui_menu_set_item_disabled(owner_gid, MENU_ID_UCM_IN_CALL_DIALER_OPTION_DIAL, MMI_FALSE);
        cui_menu_set_item_disabled(owner_gid, MENU_ID_UCM_IN_CALL_DIALER_OPTION_SAVE, MMI_FALSE);
    }
#endif /*__MMI_UCM_PLUTO_BW__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_dial_option_prepare_menu_item
 * DESCRIPTION
 *  Unhide menu items of dial option
 * PARAMETERS
 *  call_type
 * RETURNS
 *  call type count
 *****************************************************************************/
S32 mmi_ucm_dial_option_prepare_menu_item(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 call_type_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (call_type & SRV_UCM_VOICE_CALL_TYPE)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UCM_CALL_TYPE_VOICE);
        call_type_count++;
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UCM_CALL_TYPE_VOICE);
    }
#if (MMI_MAX_SIM_NUM >= 2)
    if (call_type & SRV_UCM_VOICE_CALL_TYPE_SIM2)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UCM_CALL_TYPE_VOICE_SIM2);
        call_type_count++;
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UCM_CALL_TYPE_VOICE_SIM2);
    }
#if (MMI_MAX_SIM_NUM >= 3)
    if (call_type & SRV_UCM_VOICE_CALL_TYPE_SIM3)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UCM_CALL_TYPE_VOICE_SIM3);
        call_type_count++;
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UCM_CALL_TYPE_VOICE_SIM3);
    }
#if (MMI_MAX_SIM_NUM >= 4)
    if (call_type & SRV_UCM_VOICE_CALL_TYPE_SIM4)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UCM_CALL_TYPE_VOICE_SIM4);
        call_type_count++;
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UCM_CALL_TYPE_VOICE_SIM4);
    }
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#else /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

#if (MMI_MAX_SIM_NUM == 1)
    if (call_type & SRV_UCM_VOICE_CALL_TYPE)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UCM_CALL_TYPE_VOICE);
        call_type_count++;
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UCM_CALL_TYPE_VOICE);
    }
#elif (MMI_MAX_SIM_NUM == 2)
    if (call_type & SRV_UCM_VOICE_CALL_TYPE)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UCM_CALL_TYPE_VOICE);
        call_type_count++;
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UCM_CALL_TYPE_VOICE);
    }
    if (call_type & SRV_UCM_VOICE_CALL_TYPE_SIM2)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UCM_CALL_TYPE_VOICE_SIM2);
        call_type_count++;
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UCM_CALL_TYPE_VOICE_SIM2);
    }
#elif (MMI_MAX_SIM_NUM >= 3)

    if (call_type & SRV_UCM_VOICE_CALL_TYPE_ALL)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UCM_CALL_TYPE_VOICE);

        if (call_type & SRV_UCM_VOICE_CALL_TYPE)
        {
            call_type_count++;
        }
        if (call_type & SRV_UCM_VOICE_CALL_TYPE_SIM2)
        {
            call_type_count++;
        }
        if (call_type & SRV_UCM_VOICE_CALL_TYPE_SIM3)
        {
            call_type_count++;
        }
    #if (MMI_MAX_SIM_NUM == 4)
        if (call_type & SRV_UCM_VOICE_CALL_TYPE_SIM4)
        {
            call_type_count++;
        }
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UCM_CALL_TYPE_VOICE);
    }
#endif /* MMI_MAX_SIM_NUM */
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

#ifdef __MMI_VOIP__
    if (call_type & SRV_UCM_VOIP_CALL_TYPE)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UCM_CALL_TYPE_VOIP);
        call_type_count++;
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UCM_CALL_TYPE_VOIP);
    }
#endif /* __MMI_VOIP__ */

#ifdef __MMI_VIDEO_TELEPHONY__
    if (call_type & SRV_UCM_VIDEO_CALL_TYPE_ALL)
    {
        mmi_frm_unhide_menu_item(MENU_ID_UCM_CALL_TYPE_VIDEO);
        call_type_count++;
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_UCM_CALL_TYPE_VIDEO);
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

    return call_type_count;
}


/* ==================================================================================== */
/* =============category ============================================================== */
/* ==================================================================================== */
mmi_ret mmi_ucm_dtmf_editor_key_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)(evt);
    U8 key_code = key_evt->key_code;
    U8 key_type = key_evt->key_type;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (key_evt->evt_id)
    {
        case EVT_ID_PRE_KEY:
        {
            if (wgui_inputs_dialer_is_dialer_keys(key_code) == MMI_TRUE)
            {
                if (key_type == KEY_EVENT_DOWN)
                {
                    mmi_ucm_dtmf_key_down(key_code);
                }
                else if (key_type == KEY_EVENT_UP)
                {
                    mmi_ucm_dtmf_key_up(key_code);
                }
                    
            }
            break;
        }
        case EVT_ID_POST_KEY:
        {
            if (wgui_inputs_dialer_is_dialer_keys(key_code) == MMI_TRUE)
            {
                if (key_type == KEY_EVENT_UP)
                {
                #ifdef __DM_LAWMO_SUPPORT__
                    if (srv_dm_lawmo_is_locked())
                    {
                        /* Do not display IMEI if locked*/
                    }
                    else
                #endif /* __DM_LAWMO_SUPPORT__ */
                    {
                        mmi_ucm_in_call_ssc_parse();    
                    }
                }
            }
            break;
        }
    }
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_dtmf_editor
 * DESCRIPTION
 *  enter dtmf editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_dtmf_editor(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id dialer_parent_gid = mmi_frm_group_get_active_id();
    dialer_parent_gid = mmi_frm_group_get_top_parent_group_id(dialer_parent_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((GRP_ID_UCM_MO == dialer_parent_gid) ||
        (GRP_ID_UCM_MT == dialer_parent_gid) ||
        (GRP_ID_UCM_INCALL == dialer_parent_gid))
    {
        mmi_frm_scrn_first_enter(
            dialer_parent_gid, SCR_ID_UCM_DTMF_EDITOR, 
            (FuncPtr)mmi_ucm_entry_dtmf_editor, 
            (void*)NULL);

    }
    else
    {
       /* because dtmf editor scrn is triggered by user touch key or select items, curr_active group must call scrn */
        MMI_ASSERT(0);  
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_dtmf_editor
 * DESCRIPTION
 *  Entry function of dtmf editor in call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_dtmf_editor(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 lsk = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_DTMF_EDITOR,
                    (FuncPtr)mmi_ucm_exit_dtmf_editor,
                    (FuncPtr)mmi_ucm_entry_dtmf_editor,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }

    mmi_frm_scrn_set_key_proc(GRP_ID_ROOT, SCR_ID_UCM_DTMF_EDITOR, mmi_ucm_dtmf_editor_key_proc);
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_DTMF_EDITOR);
    g_ucm_p->call_misc.dtmf_editor_SG_id = scr_info->group_id;
    
    guiBuffer = mmi_frm_scrn_get_gui_buf(scr_info->group_id, SCR_ID_UCM_DTMF_EDITOR);

#ifdef  __MMI_TOUCH_SCREEN__
#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)

#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
    mmi_ucm_set_dynamic_sim_kepad_hdlr();
#else /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */
#if (MMI_MAX_SIM_NUM == 2)
    if (MMI_TRUE == srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE))
    {
        SetDialingKeypadCallHandler(mmi_ucm_make_voice_call_from_dtmf_editor_sim1);
    }

    if (MMI_TRUE == srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE_SIM2))
    {
        SetDialingKeypadCall2Handler(mmi_ucm_make_voice_call_from_dtmf_editor_sim2);
    }
#else /* (MMI_MAX_SIM_NUM == 2) */
    if (MMI_TRUE == srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE_ALL))
    {
		SetDialingKeypadCallHandler(mmi_ucm_make_voice_call_from_dtmf_editor_icon);
	}    
    
#endif /* (MMI_MAX_SIM_NUM == 2) */
#endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */

#ifdef __MMI_VIDEO_TELEPHONY__ 
    if (MMI_TRUE == srv_ucm_is_call_srv_available(SRV_UCM_VIDEO_CALL_TYPE_ALL))
    {
        SetDialingKeypadVideoHandler(mmi_ucm_make_video_call_from_dtmf_dialer_icon);
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) ||
        srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) ||
    #ifdef __DM_LAWMO_SUPPORT__
        srv_dm_lawmo_is_locked() ||
    #endif /* __DM_LAWMO_SUPPORT__ */
        MMI_FALSE)
    {
        SetDialingKeypadPhonebookHandler(NULL);
    }
    else if (SRV_UCM_RESULT_OK == mmi_ucm_enter_general_app_option(MMI_UCM_PERMIT_ONLY))
    {
        SetDialingKeypadPhonebookHandler(mmi_ucm_launch_phb_app);
    }
    else
    {
        SetDialingKeypadPhonebookHandler(NULL);
    }
#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
#endif /* __MMI_TOUCH_SCREEN__ */

#ifdef __MMI_UCM_SLIM__
    if (GRP_ID_UCM_INCALL == scr_info->group_id)
#endif /* __MMI_UCM_SLIM__ */
    {
        lsk = STR_GLOBAL_OPTIONS;
    #if (MMI_MAX_SIM_NUM >= 2)
        EnableCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
    #else /* (MMI_MAX_SIM_NUM >= 2) */
        EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
    }

    ShowCategory16Screen(
        lsk,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*)g_ucm_p->call_misc.disp_dtmf,
        (MMI_UCM_DTMF_LEN + 1),
        guiBuffer);
    
    
    SetCategory16RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP); 

    if (srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) > 0)
    {
        SetKeyDownHandler(mmi_ucm_incoming_call_endkey, KEY_END);
    }
    else if (srv_ucm_query_group_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) > 0)
    {
        SetKeyDownHandler(mmi_ucm_outgoing_call_endkey, KEY_END);
    }
    else
    {
        SetKeyDownHandler(mmi_ucm_in_call_endkey, KEY_END);
    }
    
	mmi_ucm_handle_sendkeys_for_call(mmi_ucm_make_voice_call_from_dtmf_editor_for_sendkey,KEY_EVENT_DOWN);  

#ifdef __MMI_UCM_SLIM__
    if (GRP_ID_UCM_INCALL == scr_info->group_id)
#endif /* __MMI_UCM_SLIM__ */
    {
        SetLeftSoftkeyFunction(mmi_ucm_enter_in_call_dialer_option, KEY_EVENT_UP);
    #if (MMI_MAX_SIM_NUM >= 2)
        SetCenterSoftkeyFunction(mmi_ucm_enter_in_call_dialer_option, KEY_EVENT_UP);
    #else /* (MMI_MAX_SIM_NUM >= 2) */
        SetCenterSoftkeyFunction(mmi_ucm_make_voice_call_from_dtmf_editor_icon, KEY_EVENT_UP);
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
    }

    if (MMI_TRUE == mmi_ucm_is_any_disconnecting_call())
    {
        mmi_evt_mmi_ucm_disconnecting_call_exist_struct evt;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_UCM_DISCONNECTING);
        mmi_frm_post_event((mmi_event_struct *)&evt, mmi_ucm_post_event_hdlr, NULL);
    }
}


#if defined(__MMI_UCM_TRANSFER__) || defined(__MMI_UCM_ECT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incall_opt_transfer_act_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_incall_opt_transfer_act_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 hiliteTab = g_ucm_p->call_misc.hilite_tab;
	srv_ucm_group_info_struct group_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        /* To prevent the dial_pad_buffer is reset incorrectly */
        return;
    }

    srv_ucm_query_group_data(hiliteTab, &group_info);

    memset(g_ucm_p->mo_info.dial_pad_buffer, 0, sizeof(g_ucm_p->mo_info.dial_pad_buffer));

#ifdef __MMI_UCM_ECT__
    if (group_info.call_type & SRV_UCM_VOICE_CALL_TYPE_ALL)
    {
        mmi_ucm_enter_ECT_confirm();
    }
    else 
#endif /* __MMI_UCM_ECT__ */
#ifdef __MMI_UCM_TRANSFER__
    if (group_info.call_type == SRV_UCM_VOIP_CALL_TYPE)
    {
        mmi_ucm_enter_transfer();
    }
    else
#endif /* __MMI_UCM_TRANSFER__ */
    {
        MMI_ASSERT(0);
    }
    return;
}
#endif /* defined(__MMI_UCM_TRANSFER__) || defined(__MMI_UCM_ECT__) */


#ifdef __MMI_UCM_REJECT_BY_SMS__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_rej_by_sms
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_rej_by_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_single_call_act_req_struct mt_call_uid;   
    srv_ucm_id_info_struct call_uid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_REJ_BY_SMS);
    g_ucm_p->rej_by_sms.is_confirmed = MMI_TRUE;

    if (MMI_FALSE == mmi_ucm_get_call_id_by_call_state_and_type(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, &call_uid))
    {
        MMI_ASSERT(0);
    }

    mt_call_uid.action_uid.call_id = call_uid.call_id;
    mt_call_uid.action_uid.group_id = call_uid.group_id;
    mt_call_uid.action_uid.call_type = call_uid.call_type;

#if (MMI_MAX_SIM_NUM >= 2)
    if (call_uid.call_type & (SRV_UCM_VOICE_CALL_TYPE | SRV_UCM_VIDEO_CALL_TYPE))
    {
        srv_ucm_reject_by_sms(mt_call_uid, (CHAR*)g_ucm_p->rej_by_sms.ucs2_msg_context, MMI_SIM1);
    }
    else if (call_uid.call_type & (SRV_UCM_VOICE_CALL_TYPE_SIM2 | SRV_UCM_VIDEO_CALL_TYPE_SIM2))
    {
        srv_ucm_reject_by_sms(mt_call_uid, (CHAR*)g_ucm_p->rej_by_sms.ucs2_msg_context, MMI_SIM2);
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (call_uid.call_type == SRV_UCM_VOICE_CALL_TYPE_SIM3)
    {
        srv_ucm_reject_by_sms(mt_call_uid, (CHAR*)g_ucm_p->rej_by_sms.ucs2_msg_context, MMI_SIM3);
    }
#if (MMI_MAX_SIM_NUM == 4)
    else if (call_uid.call_type == SRV_UCM_VOICE_CALL_TYPE_SIM4)
    {
        srv_ucm_reject_by_sms(mt_call_uid, (CHAR*)g_ucm_p->rej_by_sms.ucs2_msg_context, MMI_SIM4);
    }
#endif /* (MMI_MAX_SIM_NUM == 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#else /* (MMI_MAX_SIM_NUM >= 2) */
    srv_ucm_reject_by_sms(mt_call_uid, (CHAR*)g_ucm_p->rej_by_sms.ucs2_msg_context, MMI_SIM1);
#endif /* (MMI_MAX_SIM_NUM >= 2) */

    if (g_ucm_p->rej_by_sms.ucs2_msg_context != NULL)
    {
        OslMfree(g_ucm_p->rej_by_sms.ucs2_msg_context);
        g_ucm_p->rej_by_sms.ucs2_msg_context = NULL;
    }
    memset(&g_ucm_p->rej_by_sms, 0, sizeof(mmi_ucm_rej_by_sms_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_rej_by_sms_confirm
 * DESCRIPTION
 *  enter reject by sms confirm scrn
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_rej_by_sms_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    U8* prefix = NULL;
    U8* message = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_REJ_BY_SMS_CONFIRM);
    mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE); 
	arg.softkey[0].str = (WCHAR *)((UI_string_type)GetString(STR_GLOBAL_YES));	
    arg.softkey[1].img = (PS8)GetImage(IMG_GLOBAL_COMMON_CSK);
    arg.softkey[2].str = (WCHAR *)((UI_string_type)GetString(STR_GLOBAL_NO));
  
    arg.user_tag = (void *)MMI_UCM_CNF_REJ_BY_SMS;
    arg.f_enter_history = MMI_TRUE;
    arg.parent_id = GRP_ID_UCM_MT;
    arg.callback = (mmi_proc_func)mmi_ucm_cnf_popup_cb;
    /* prepare string */
    prefix = (U8*)GetString(STR_ID_UCM_REJ_BY_SMS_CONFIRM);    
    message = OslMalloc((mmi_ucs2strlen((CHAR*)prefix) + mmi_ucs2strlen((CHAR*)g_ucm_p->rej_by_sms.ucs2_msg_context) + 2) * ENCODING_LENGTH);
    mmi_ucs2cpy((CHAR*)message, (CHAR*)prefix);
    mmi_ucs2cat((CHAR*)message, (CHAR*) L"\n");
    mmi_ucs2cat((CHAR*)message, (CHAR*)g_ucm_p->rej_by_sms.ucs2_msg_context);

    g_ucm_p->rej_by_sms.scrn_id = mmi_confirm_display((WCHAR *)message, MMI_EVENT_QUERY, &arg);
    mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_MT, g_ucm_p->rej_by_sms.scrn_id, (mmi_proc_func) mmi_ucm_entry_rej_by_sms_confirm_delete_proc);
        
    OslMfree(message);   
}

#endif /* __MMI_UCM_REJECT_BY_SMS__ */


#ifdef __MMI_UCM_ECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_ECT_confirm
 * DESCRIPTION
 *  enter reject by sms confirm scrn
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_ECT_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE); 
    arg.softkey[0].str = (WCHAR *)((UI_string_type)GetString(STR_GLOBAL_YES));  
    arg.softkey[1].img = (PS8)GetImage(IMG_GLOBAL_COMMON_CSK);
    arg.softkey[2].str = (WCHAR *)((UI_string_type)GetString(STR_GLOBAL_NO));

    arg.user_tag = (void *)MMI_UCM_CNF_ECT;
    arg.f_enter_history = MMI_TRUE;
    arg.parent_id = GRP_ID_UCM_INCALL;
    arg.callback = (mmi_proc_func)mmi_ucm_cnf_popup_cb;

    mmi_confirm_display((WCHAR *)((UI_string_type) GetString(STR_ID_UCM_ECT_CONFIRM_QUERY)), MMI_EVENT_QUERY, &arg);    

}
#endif /* __MMI_UCM_ECT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_if_number_exists
 * DESCRIPTION
 *  check if there is number for save phb
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_ucm_if_number_exists(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    if (mmi_frm_scrn_is_present(GRP_ID_UCM_MO, SCR_ID_UCM_DTMF_EDITOR, MMI_FRM_NODE_ALL_FLAG) || 
        mmi_frm_scrn_is_present(GRP_ID_UCM_MT, SCR_ID_UCM_DTMF_EDITOR, MMI_FRM_NODE_ALL_FLAG) ||
        mmi_frm_scrn_is_present(GRP_ID_UCM_INCALL, SCR_ID_UCM_DTMF_EDITOR, MMI_FRM_NODE_ALL_FLAG))
    {
        if (mmi_ucs2strlen((CHAR*)g_ucm_p->call_misc.disp_dtmf) > 0)
        {
        	return MMI_TRUE;
        }
    }
#if defined (__MMI_VOIP__)    
    /* save uri address to phonebook in call */
	else if (mmi_frm_scrn_is_present(GRP_ID_UCM_MO, SCR_ID_UCM_VOIP_DIALER, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG) || 
              mmi_frm_scrn_is_present(GRP_ID_UCM_MT, SCR_ID_UCM_VOIP_DIALER, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG) ||
              mmi_frm_scrn_is_present(GRP_ID_UCM_INCALL, SCR_ID_UCM_VOIP_DIALER, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
    {   
        if (mmi_ucs2strlen((CHAR*)g_ucm_p->mo_info.dial_pad_buffer) > 0)
        {
        	return MMI_TRUE;
        }
    }
#endif /* __MMI_VOIP__ */
    else
    {  
        if (mmi_ucs2strlen((CHAR*)g_ucm_p->mo_info.dial_pad_buffer) > 0)
        {
        	return MMI_TRUE;
        }
    }
	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_incoming_call
 * DESCRIPTION
 *  Enter incoming call scrn
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_incoming_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_scrn_is_present(GRP_ID_UCM_MT, SCR_ID_UCM_INCOMING, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_UCM_MT, SCR_ID_UCM_INCOMING); /* ensure no two incoming call screens in the history */
    }
    
    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_MT, SCR_ID_UCM_INCOMING, 
        (FuncPtr)mmi_ucm_entry_incoming_call, 
        (void*)NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_incoming_call
 * DESCRIPTION
 *  Shows the incoming call screen
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_incoming_call(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_caller_res_struct* res_info = NULL;
    srv_callset_answer_mode_enum ans_mode_status;
    
    U8* guiBuffer = NULL;
    U16* file_path = NULL;
    U16* display_name = NULL;
#if (MMI_MAX_SIM_NUM == 1) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    U16 notification_str_id = STR_ID_UCM_CALLING;
#else /* (MMI_MAX_SIM_NUM == 1) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */
    U16 notification_str_id = 0;
#endif /* (MMI_MAX_SIM_NUM == 1) */
    U16 line_icon = 0;    
#ifdef __MMI_UCM_NUMBER_TYPE__    
    U16 number_type_icon_array[1]; /* because only 1 incoming call */ 
    U16 num_type_icon = 0;
#endif /* __MMI_UCM_NUMBER_TYPE__ */
    U16 image_id = 0;
    U16 rsk_str = 0;
    U16 lsk_str = 0;
    MMI_BOOL is_play_now = MMI_FALSE;
    MMI_BOOL is_video_sound = MMI_FALSE;
    MMI_BOOL is_video_update = MMI_FALSE;
    wgui_cate_momt_res_type_enum cat_image_type = WGUI_CATE_MOMT_RES_TYPE_IMAGE_ID;
    srv_ucm_res_type_enum image_type = SRV_UCM_RES_TYPE_IMAGE_ID;
    srv_ucm_call_info_struct *call_info;
#if defined(__MMI_PHB_CALLER_VIDEO__) || defined(__MMI_UCM_RSK_SUPPRESS_RING__) || defined(__MMI_FTE_SUPPORT__)
    MMI_ALERT_TYPE alert_type;
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) || defined(__MMI_UCM_RSK_SUPPRESS_RING__) || defined(__MMI_FTE_SUPPORT__) */
#ifdef __MMI_MOTION_DIAL__
    PU8 audio_buf_p;
#endif /* __MMI_MOTION_DIAL__ */
#if defined (__MMI_FTE_SUPPORT__) && !defined(__MMI_MAINLCD_240X240__)
    wgui_catcall_fte_iconbar_item_struct FTE_iconbar_items[MMI_UCM_FTE_ICONBAR_MT_MAX_NUM];
    wgui_catcall_fte_iconbar_item_struct unlock_item;
#if defined(__OP01__) && (defined(__MMI_UCM_REJECT_BY_SMS__) || defined(__MMI_VIDEO_TELEPHONY__))
    S32 MT_icon_num = 2;
#endif /* defined(__OP01__) && (defined(__MMI_UCM_REJECT_BY_SMS__) || defined(__MMI_VIDEO_TELEPHONY__)) */
    S32 number_of_items;
#endif /* __MMI_FTE_SUPPORT__ */
#if defined(__MMI_UCM_RSK_SUPPRESS_RING__) || defined(__MMI_FTE_SUPPORT__)
    U8 volume_level;
#endif /* defined(__MMI_UCM_RSK_SUPPRESS_RING__) || defined(__MMI_FTE_SUPPORT__) */


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get incoming call info */
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) != 1)
    {
        if (mmi_frm_scrn_is_present(scr_info->group_id, SCR_ID_UCM_DISCONNECT_SCREEN, MMI_FRM_NODE_ALL_FLAG))
    	{
    	     mmi_frm_scrn_close(scr_info->group_id, SCR_ID_UCM_DISCONNECT_SCREEN);
	    }
			 
        mmi_ucm_entry_disconnecting_screen();
	    return;
    }

    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_INCOMING,
                    (FuncPtr)mmi_ucm_exit_incoming_call,
                    (FuncPtr)mmi_ucm_entry_incoming_call,
                    MMI_FRM_FULL_SCRN))
    {
        mmi_frm_scrn_set_leave_proc(scr_info->group_id, SCR_ID_UCM_INCOMING, (mmi_proc_func)mmi_ucm_incoming_call_screen_delete_proc);
        return;
    }

    res_info = OslMalloc(sizeof(srv_ucm_caller_res_struct));
    ans_mode_status = srv_callset_answer_mode_get_status();

    guiBuffer = mmi_frm_scrn_get_gui_buf(scr_info->group_id, SCR_ID_UCM_INCOMING);

    call_info = OslMalloc(sizeof(srv_ucm_call_info_struct));
    srv_ucm_query_call_data(g_ucm_p->call_misc.index_list[0], call_info);
    display_name = (U16*)call_info->remote_info.disp_name;

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (!mmi_ucm_one_sim_behavior_is_needed())
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
    {
    #if (MMI_MAX_SIM_NUM >= 2)
        if (call_info->uid_info.call_type == SRV_UCM_VOICE_CALL_TYPE)
        {
            notification_str_id = STR_ID_UCM_VOICE_INCOMING_SIM1;
        }
        else if(call_info->uid_info.call_type == SRV_UCM_VOICE_CALL_TYPE_SIM2)
        {
            notification_str_id = STR_ID_UCM_VOICE_INCOMING_SIM2;
        }
    #if (MMI_MAX_SIM_NUM >= 3)
        else if(call_info->uid_info.call_type == SRV_UCM_VOICE_CALL_TYPE_SIM3)
        {
            notification_str_id = STR_ID_UCM_VOICE_INCOMING_SIM3;
        }
    #if (MMI_MAX_SIM_NUM == 4)
        else if(call_info->uid_info.call_type == SRV_UCM_VOICE_CALL_TYPE_SIM4)
        {
            notification_str_id = STR_ID_UCM_VOICE_INCOMING_SIM4;
        }
    #endif  /* (MMI_MAX_SIM_NUM == 4) */
    #endif  /* (MMI_MAX_SIM_NUM >= 3) */
    #endif  /* (MMI_MAX_SIM_NUM >= 2) */
    }

#ifdef __MMI_VIDEO_TELEPHONY__
#if defined(__MMI_3G_SWITCH__)
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (mmi_ucm_one_sim_behavior_is_needed())
    {
        if (call_info->uid_info.call_type == SRV_UCM_VIDEO_CALL_TYPE ||
            call_info->uid_info.call_type == SRV_UCM_VIDEO_CALL_TYPE_SIM2)
        {
            notification_str_id = STR_ID_UCM_VIDEO_INCOMING;
        }
    }
#else /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
    if (call_info->uid_info.call_type == SRV_UCM_VIDEO_CALL_TYPE)
    {
        notification_str_id = STR_ID_UCM_VIDEO_INCOMING_SIM1;
    }
    else if (call_info->uid_info.call_type == SRV_UCM_VIDEO_CALL_TYPE_SIM2)
    {
        notification_str_id = STR_ID_UCM_VIDEO_INCOMING_SIM2;
    }
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
#else /* __MMI_3G_SWITCH__ */
    if (call_info->uid_info.call_type == SRV_UCM_VIDEO_CALL_TYPE)
    {
        notification_str_id = STR_ID_UCM_VIDEO_INCOMING;
    }
#endif /* __MMI_3G_SWITCH__ */
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __MMI_UCM_NUMBER_TYPE__
    if (g_ucm_p->full_mo_mt_display.num_type_icon)
    {
        num_type_icon = g_ucm_p->full_mo_mt_display.num_type_icon;
    }
#endif /* __MMI_UCM_NUMBER_TYPE__ */

#if defined(__MMI_PHB_CALLER_VIDEO__) || defined(__MMI_UCM_RSK_SUPPRESS_RING__) || defined(__MMI_FTE_SUPPORT__)
    alert_type = (MMI_ALERT_TYPE)g_ucm_p->full_mo_mt_display.mo_mt_display.alert_type;
#endif /* defined(__MMI_PHB_CALLER_VIDEO__) || defined(__MMI_UCM_RSK_SUPPRESS_RING__) || defined(__MMI_FTE_SUPPORT__) */

    /* image info */
    if (MMI_FALSE == srv_ucm_get_caller_res_info(call_info->uid_info, res_info))
    {
        MMI_ASSERT(0);
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_INCOMING_CALLER_INFO_2,
        call_info->uid_info.call_type,
        call_info->uid_info.group_id,        
        call_info->uid_info.call_id);
    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_INCOMING_CALLER_INFO_1,
        res_info->res_type,
        res_info->tone_id,        
        res_info->video_id,
        res_info->pic_id,
        res_info->is_video_sound);


    /* visual info */
    image_id = res_info->pic_id;

    /* Decide visual type */
    if (MMI_FALSE == mmi_ucm_decide_visual_type(res_info->res_type, &image_type))
    {
        MMI_ASSERT(0);
    }
#ifdef __MMI_PHB_CALLER_VIDEO__
    if (SRV_UCM_RES_TYPE_VIDEO_ID == image_type)
    {
        image_id = res_info->video_id;
    }

    /* keep value in global, because when stop tone, can not query from call table */ 
    g_ucm_p->full_mo_mt_display.res_type = image_type;
#endif /* __MMI_PHB_CALLER_VIDEO__ */

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_INCOMING_CALLER_INFO_4,
        image_type,
        image_id);
    
    switch (image_type)
    {
        case SRV_UCM_RES_TYPE_IMAGE_ID:
        {
            cat_image_type = WGUI_CATE_MOMT_RES_TYPE_IMAGE_ID;
        }
        break;

        case SRV_UCM_RES_TYPE_IMAGE_PATH:
        {
            cat_image_type = WGUI_CATE_MOMT_RES_TYPE_IMAGE_FILE;
            file_path = (U16*)res_info->pic_path;

            if (mmi_ucm_is_file_valid((U16*)file_path, image_type) == MMI_FALSE)
            {
                image_id = MMI_UCM_DEFAULT_MOMT_IMAGE;
                file_path = NULL;
            }
        #ifdef __DRM_SUPPORT__
            else
            {
                /* consume right of caller image */
                mmi_ucm_drm_start_consume((U16*)file_path, image_type);
            }
        #endif /* __DRM_SUPPORT__ */
        }
        break;

    #ifdef __MMI_PHB_CALLER_VIDEO__      
        case SRV_UCM_RES_TYPE_VIDEO_ID:
        {
            cat_image_type = WGUI_CATE_MOMT_RES_TYPE_VIDEO_ID;
        }
        break;        

        case SRV_UCM_RES_TYPE_VIDEO_PATH:
        {
            cat_image_type = WGUI_CATE_MOMT_RES_TYPE_VIDEO_FILE;
            file_path = (U16*)res_info->video_path;

            if ((mmi_ucm_is_file_valid((U16*)file_path, image_type) == MMI_FALSE)
        #if defined(__MMI_VIDEO_PLAY_SUPPORT__)
                || ((SRV_UCM_RES_TYPE_VIDEO_PATH == image_type) && (mdi_video_ply_check_is_able_to_play((CHAR*)file_path) != MDI_RES_VDOPLY_SUCCEED))
        #endif /*__MMI_VIDEO_PLAY_SUPPORT__*/    
                || MMI_FALSE)
            {
                image_id = MMI_UCM_DEFAULT_MOMT_IMAGE;
                file_path = NULL;
            }
        #ifdef __DRM_SUPPORT__
            else
            {
                /* consume right of caller image */
                mmi_ucm_drm_start_consume((U16*)file_path, image_type);
            }
        #endif /* __DRM_SUPPORT__ */
        }
        break;
    #endif /* __MMI_PHB_CALLER_VIDEO__ */
    
        default:
        {
            MMI_ASSERT(0);
        }
        break;
    }

#ifdef __MMI_PHB_CALLER_VIDEO__
    is_video_sound = res_info->is_video_sound;

#if defined (__MMI_CLAMSHELL__) && !defined (__MMI_SLIDE__)
    /* show sub before main LCD */
    if (srv_clam_is_close())
    {
    }
    else
#endif /* __MMI_CLAMSHELL__ */
    {
        is_video_update = MMI_TRUE;
    }

    if ((alert_type == SRV_PROF_ALERT_TYPE_RING) ||
        (alert_type == SRV_PROF_ALERT_TYPE_VIB_AND_RING) ||
        (alert_type == SRV_PROF_ALERT_TYPE_VIB_THEN_RING && g_ucm_p->call_misc.is_ring_after_vibra == MMI_TRUE))
    {
        is_play_now = MMI_TRUE;
    }

    if (mmi_ucm_get_group_index_by_call_state_and_type(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL) >= 0 ||
        mmi_ucm_get_group_index_by_call_state_and_type(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL) >= 0)
    {
        is_video_sound = MMI_FALSE;
        is_play_now = MMI_FALSE;
    }

    /* do not play video sound if speech is on / also consider mode setting */
    if (mdi_audio_is_speech_mode() == TRUE ||   /* O */
        alert_type == SRV_PROF_ALERT_TYPE_VIB_ONLY ||
        alert_type == SRV_PROF_ALERT_TYPE_INVALID ||
        alert_type == SRV_PROF_ALERT_TYPE_SILENT)
    {
        is_video_sound = MMI_FALSE;
    }

    if (g_ucm_p->call_misc.is_ringtone_suppress)
    {
        is_video_sound = MMI_FALSE;
        is_play_now = MMI_FALSE;
    }

    if (mmi_is_redrawing_bk_screens())
    {
        is_video_sound = MMI_FALSE;
        is_play_now = MMI_FALSE;
        is_video_update = MMI_FALSE;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_INCOMING_CALLER_INFO_3,
        image_id,
        cat_image_type,        
        is_video_update,
        is_video_sound,
        is_play_now);
#endif /* __MMI_PHB_CALLER_VIDEO__ */

#ifdef __MMI_UCM_SLIM__
    if (SRV_UCM_RESULT_OK == mmi_ucm_answer_option(MMI_UCM_PERMIT_ONLY))
    {
    #if defined(__MMI_MAINLCD_128X160__)
        lsk_str = STR_ID_UCM_ACCEPT;
    #else /* __MMI_MAINLCD_128X160__ */
        lsk_str = STR_ID_UCM_ANSWER;
    #endif /* __MMI_MAINLCD_128X160__ */
    }
    else if (SRV_UCM_RESULT_OK == mmi_ucm_replace_option(MMI_UCM_PERMIT_ONLY))
    {
        lsk_str = STR_GLOBAL_REPLACE;
    }
    else
    {
    #if defined(__MMI_MAINLCD_128X160__)
        lsk_str = STR_ID_UCM_ACCEPT;
    #else /* __MMI_MAINLCD_128X160__ */
        lsk_str = 0;
    #endif /* __MMI_MAINLCD_128X160__ */
    }
	
	#ifndef __MMI_MAINLCD_96X64__
    EnableCenterSoftkey(0, IMG_GLOBAL_DIAL_PAD_CSK);

	#else
	EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    #endif 

#else /* __MMI_UCM_SLIM__ */

    /* line icon *//* Use line icon compile option */
    if (g_ucm_p->full_mo_mt_display.line_icon)
    {
        line_icon = g_ucm_p->full_mo_mt_display.line_icon;
    }

    if (mmi_ucm_incoming_call_show_option())
    {
        lsk_str = STR_GLOBAL_OPTIONS;
        EnableCenterSoftkey(0, IMG_GLOBAL_OPTION_CSK);
    }
    else
    {
        lsk_str = STR_ID_UCM_ANSWER;
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    }
#endif /* __MMI_UCM_SLIM__ */

#if defined(__MMI_UCM_RSK_SUPPRESS_RING__) || defined(__MMI_FTE_SUPPORT__)
    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL, &volume_level);
    if (MDI_AUD_VOL_IS_MUTE_LEVEL(volume_level))
    {
        volume_level = volume_level & 0x0F;
    }
#endif /* defined(__MMI_UCM_RSK_SUPPRESS_RING__) || defined(__MMI_FTE_SUPPORT__) */

#ifdef __MMI_UCM_RSK_SUPPRESS_RING__
    if (g_ucm_p->call_misc.is_ringtone_suppress)
    {
        rsk_str = STR_ID_UCM_REJECT;
    }
    else if ((alert_type != SRV_PROF_ALERT_TYPE_SILENT) &&
             (alert_type != SRV_PROF_ALERT_TYPE_INVALID) &&
             (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL)))
    {
        if ((SRV_PROF_ALERT_TYPE_RING == alert_type) && (0 == volume_level))
        {
            rsk_str = STR_ID_UCM_REJECT;
        }
        else
        {
            rsk_str = STR_ID_UCM_SILENT;
        }
    }
    else
#endif /* __MMI_UCM_RSK_SUPPRESS_RING__ */
    {
        rsk_str = STR_ID_UCM_REJECT;
    }
#ifdef __MMI_TOUCH_SCREEN__
    wgui_catcall_set_button((UI_string_type) GetString(STR_ID_UCM_ANSWER), mmi_ucm_incoming_call_sendkey);
#endif /* __MMI_TOUCH_SCREEN__ */

#ifdef __MMI_MOTION_DIAL__
    media_get_ext_buffer(MOD_MMI, (void **)&audio_buf_p, mdi_audio_get_midi_size_limit());  /*x*/
#endif /* __MMI_MOTION_DIAL__ */

#ifdef __MMI_UCM_NUMBER_TYPE__
    number_type_icon_array[0] = num_type_icon; 
    wgui_catcall_set_number_type_icons(number_type_icon_array);
#endif /* __MMI_UCM_NUMBER_TYPE__ */

#if defined (__MMI_FTE_SUPPORT__) && !defined(__MMI_MAINLCD_240X240__)
#if defined(__PXS_APP_ENABLE__)
    memset(&unlock_item, 0, sizeof(wgui_catcall_fte_iconbar_item_struct));
#else /* __PXS_APP_ENABLE__ */
    mmi_ucm_FTE_fill_unlock_item(&unlock_item);
#endif /* __PXS_APP_ENABLE__ */

    /* handle incoming call case - prepare info for iconbar */
#ifdef __MMI_UCM_FTE_SLIM_ICONBAR_PRESENT__
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL))
    {
        if(call_info->uid_info.call_type & SRV_UCM_VIDEO_CALL_TYPE_ALL)
        {
            mmi_ucm_FTE_fill_iconbar_items(MMI_UCM_FTE_ICONBAR_INCOMING_CALL, FTE_iconbar_items, MMI_UCM_FTE_ICOMBAR_MT_VT_NUM);
            number_of_items = MMI_UCM_FTE_ICOMBAR_MT_VT_NUM;
        }
        else
        {   
            mmi_ucm_FTE_fill_iconbar_items(MMI_UCM_FTE_ICONBAR_INCOMING_CALL, FTE_iconbar_items, MMI_UCM_FTE_ICOMBAR_MT_NUM);
            number_of_items = MMI_UCM_FTE_ICOMBAR_MT_NUM;
        }
    }
    else /* handle waiting call case - prepare info for iconbar */
    {
        if(call_info->uid_info.call_type & SRV_UCM_VIDEO_CALL_TYPE_ALL)
        {
            mmi_ucm_FTE_fill_iconbar_items(MMI_UCM_FTE_ICONBAR_WAITING_CALL, FTE_iconbar_items, MMI_UCM_FTE_ICOMBAR_MT_VT_NUM);
            number_of_items = MMI_UCM_FTE_ICOMBAR_MT_VT_NUM;            
        }
        else
        {
            mmi_ucm_FTE_fill_iconbar_items(MMI_UCM_FTE_ICONBAR_WAITING_CALL, FTE_iconbar_items, MMI_UCM_FTE_ICOMBAR_MT_NUM);
            number_of_items = MMI_UCM_FTE_ICOMBAR_MT_NUM;            
        }
    }
#if defined(__PXS_APP_ENABLE__)
    wgui_catcall_fte_setup(number_of_items, FTE_iconbar_items, unlock_item, NULL);
#else /* __PXS_APP_ENABLE__ */
    wgui_catcall_fte_setup(number_of_items, FTE_iconbar_items, unlock_item, mmi_ucm_FTE_screen_touch_hdlr);
#endif /* __PXS_APP_ENABLE__ */
    

    /* decide if need to grey answer iconbar button */
    if (SRV_UCM_RESULT_OK != mmi_ucm_answer_option(MMI_UCM_PERMIT_ONLY))
    {
        wgui_catcall_fte_iconbar_enable_item(0, MMI_TRUE/* means disable */, get_string(STR_ID_UCM_ANSWER), get_image(IMG_ID_UCM_ANSWER));
    }
    /* decide if need to grey silence iconbar button */
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) &&
        ((MMI_TRUE ==g_ucm_p->call_misc.is_ringtone_suppress) || (alert_type == SRV_PROF_ALERT_TYPE_SILENT) || (alert_type == SRV_PROF_ALERT_TYPE_INVALID) ||
         ((SRV_PROF_ALERT_TYPE_RING == alert_type) && (0 == volume_level))))
    {
        wgui_catcall_fte_iconbar_enable_item(1, MMI_TRUE/* means disable */, get_string(STR_ID_UCM_SILENT), get_image(IMG_ID_UCM_SILENCE));
    }

    #ifdef __OP01__
    #ifdef __MMI_UCM_REJECT_BY_SMS__
    if (SRV_UCM_RESULT_OK != mmi_ucm_rej_by_sms_option(MMI_UCM_PERMIT_ONLY))
    {
        wgui_catcall_fte_iconbar_enable_item(MT_icon_num, MMI_TRUE/* means disable */, get_string(STR_ID_UCM_REJ_BY_SMS), get_image(IMG_ID_UCM_REJECT_BY_SMS_DISABLE));
    }
    MT_icon_num++;
    #endif /* __MMI_UCM_REJECT_BY_SMS__ */
    
    #ifdef __MMI_VIDEO_TELEPHONY__
    if (SRV_UCM_RESULT_OK != mmi_ucm_answer_by_voice_option(MMI_UCM_PERMIT_ONLY))
    {
        wgui_catcall_fte_iconbar_enable_item(MT_icon_num, MMI_TRUE/* means disable */, get_string(STR_ID_UCM_ANSWER_BY_VOICE), get_image(IMG_ID_UCM_ANSWER_BY_VOICE_DISABLE));
    }
    #endif /* __MMI_VIDEO_TELEPHONY__ */
    #endif /*__OP01__*/
#endif /*__MMI_UCM_FTE_SLIM_ICONBAR_PRESENT__*/
#ifndef __MMI_UCM_FTE_SLIM_ICONBAR_PRESENT__	
#if defined(__PXS_APP_ENABLE__)
		wgui_catcall_fte_setup(1, &unlock_item, unlock_item, NULL);
#else /* __PXS_APP_ENABLE__ */
		wgui_catcall_fte_setup(1, &unlock_item, unlock_item, mmi_ucm_FTE_screen_touch_hdlr);
#endif /* __PXS_APP_ENABLE__ */
#endif /*__MMI_UCM_FTE_SLIM_ICONBAR_PRESENT__*/
#if defined(__PXS_APP_ENABLE__) 
    wgui_catcall_fte_lock_screen(MMI_FALSE);
#else /* __PXS_APP_ENABLE__ */
    /* handle lock case */
    mmi_ucm_FTE_scrn_update_hdlr_by_lock_state(mmi_ucm_get_auto_lock_state());
#endif /* __PXS_APP_ENABLE__ */
#endif /* __MMI_FTE_SUPPORT__ */
    ShowCategory17Screen(
            0,   /* title_id */
            lsk_str,                   /* left_softkey */
            0,                   /* left_softkey_icon */
            rsk_str,    /* right_softkey */
            0,                   /* right_softkey_icon */
            notification_str_id,                   /* NotificationStringId */ 
            (U8*)display_name, /* NameOrNumber */
            NULL,                /* IP_Number */
            line_icon,             /* line icon */
            IMG_PHB_DEFAULT,     /*default_image_id */
            image_id,               /* resource_id */
            (CHAR*)file_path,             /* resource_filename */
            cat_image_type,          /* resource_type */
            0,                   /* repeat_count, video/swflash only, repeat_count, 0 = infinite */
            is_video_update,        /* is_visaul_update, video/swflash only, update to LCM or not */
            is_video_sound,      /* is_video_aud, video/swflash only, play video's audio */
            is_play_now,         /* is_play_aud_when_start */
            guiBuffer); 

	 
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_VOIP_CALL_TYPE), NULL) > 1)
    {
        /* group key */
        SetGroupKeyHandler(
            mmi_ucm_pre_send_dtmf,
            (U16*) PresentAllDialerKeys,
            TOTAL_DIALER_KEYS,
            KEY_EVENT_DOWN);
        
        mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_DTMF);

        SetKeyDownHandler(mmi_ucm_set_sidekey, KEY_VOL_UP);

        SetKeyDownHandler(mmi_ucm_set_sidekey, KEY_VOL_DOWN); 
        mmi_frm_scrn_set_key_proc(scr_info->group_id, SCR_ID_UCM_INCOMING,  mmi_ucm_during_call_dtmf_key_proc); 
    }
    else /* no other call */
    {        
        /* group key */
        if (ans_mode_status & SRV_CALLSET_ANSWER_MODE_ANYKEY)
        {
            SetGroupKeyHandler(
                mmi_ucm_incoming_call_sendkey, 
                (U16*) PresentAllKeys, 
                TOTAL_KEYS, 
                KEY_EVENT_DOWN);
        }
        else
        {
        #ifdef __MMI_SIDEKEY_SUPPRESS_RING__
            if (g_ucm_p->call_misc.is_ringtone_suppress == MMI_FALSE &&
                srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL))
            {
                SetKeyDownHandler(mmi_ucm_suppress_incoming_tone, KEY_VOL_DOWN);
                SetKeyUpHandler(mmi_ucm_set_key_after_suppress_ring, KEY_VOL_DOWN);
            }
        #else /* __MMI_SIDEKEY_SUPPRESS_RING__ */
           
            SetKeyDownHandler(mmi_ucm_set_sidekey, KEY_VOL_UP);
           
            SetKeyDownHandler(mmi_ucm_set_sidekey, KEY_VOL_DOWN);
        #endif /* __MMI_SIDEKEY_SUPPRESS_RING__ */ 

            /* side key */
        #ifdef __MMI_CLAMSHELL__
        #ifdef __MMI_SIDEKEY_SUPPRESS_RING__
            SetKeyLongpressHandler(mmi_ucm_incoming_call_endkey, KEY_VOL_DOWN);
        #else /* __MMI_SIDEKEY_SUPPRESS_RING__ */    
            SetKeyDownHandler(mmi_ucm_incoming_call_sendkey, KEY_VOL_UP);
            SetKeyDownHandler(mmi_ucm_incoming_call_endkey, KEY_VOL_DOWN);
        #endif /* __MMI_SIDEKEY_SUPPRESS_RING__ */    
        #endif /* __MMI_CLAMSHELL__ */
        }
    }

#ifdef __MMI_UCM_SLIM__
    if (SRV_UCM_RESULT_OK == mmi_ucm_answer_option(MMI_UCM_PERMIT_ONLY))
    {
        SetLeftSoftkeyFunction(mmi_ucm_incoming_call_sendkey, KEY_EVENT_UP);
    }
    else if (SRV_UCM_RESULT_OK == mmi_ucm_replace_option(MMI_UCM_PERMIT_ONLY))
    {
        SetLeftSoftkeyFunction(mmi_ucm_replace, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_ucm_incoming_call_sendkey, KEY_EVENT_UP);
    }

    // SetCenterSoftkeyFunction(mmi_ucm_pre_entry_dtmf_editor, KEY_EVENT_UP);
      SetCenterSoftkeyFunction(mmi_ucm_incoming_call_sendkey, KEY_EVENT_UP);
#else /* __MMI_UCM_SLIM__ */
    if (mmi_ucm_incoming_call_show_option())
    {
        SetLeftSoftkeyFunction(mmi_ucm_entry_incoming_call_option, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_ucm_entry_incoming_call_option, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_ucm_incoming_call_sendkey, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_ucm_incoming_call_sendkey, KEY_EVENT_UP);
    }
#endif /* __MMI_UCM_SLIM__ */

#ifdef __MMI_UCM_RSK_SUPPRESS_RING__
    if (rsk_str == STR_ID_UCM_SILENT)
    {
        SetRightSoftkeyFunction(mmi_ucm_suppress_incoming_tone, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(mmi_ucm_set_key_after_suppress_ring, KEY_EVENT_UP);
    }
    else if (rsk_str == STR_ID_UCM_REJECT)
#endif /* __MMI_UCM_RSK_SUPPRESS_RING__ */
    {
        SetRightSoftkeyFunction(mmi_ucm_incoming_call_endkey, KEY_EVENT_UP);
    }

   
    SetKeyDownHandler(mmi_ucm_incoming_call_sendkey, KEY_SEND);

    /* Let incoming call end key behavior will sync to general end key hdlr, but reject RSK and suppress keep in vmmi_ucm_incoming_call_endkey */
    SetKeyDownHandler(mmi_ucm_end_key, KEY_END);

#ifdef __MMI_MOTION_DIAL__
    media_free_ext_buffer(MOD_MMI, (void **)&audio_buf_p);
#endif /* __MMI_MOTION_DIAL__ */

    mmi_frm_scrn_set_leave_proc(scr_info->group_id, SCR_ID_UCM_INCOMING, (mmi_proc_func)mmi_ucm_incoming_call_screen_delete_proc);
    OslMfree(res_info);

    if (!mmi_is_redrawing_bk_screens())
    {
        ClearKeyEvents();
    #ifdef __PXS_APP_ENABLE__
        if (MMI_TRUE == g_ucm_p->pxs_need_handle)
        {
        }
        else
    #endif /* __PXS_APP_ENABLE__ */
    #ifdef __MMI_SCREEN_LOCK_ANY_TIME__
        if (MMI_FALSE == g_ucm_p->call_misc.keep_backlight_off)
    #endif /* __MMI_SCREEN_LOCK_ANY_TIME__ */
        {
            srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
        }

        if (srv_charbat_is_low_battery())
        {
            ChgrPlayLowBatTone();
        }

    #ifdef __MMI_FTE_SUPPORT__
        if (IsMyTimerExist(TIMER_ID_UCM_DELAY_RING) == MMI_FALSE)
    #endif /* __MMI_FTE_SUPPORT__ */
        {
            mmi_ucm_play_incoming_tone();
        }
    }

    OslMfree(call_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_outgoing_call
 * DESCRIPTION
 *  Enter the call type selection screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_outgoing_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    
    if (mmi_frm_scrn_is_present(GRP_ID_UCM_MO, SCR_ID_UCM_OUTGOING, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_UCM_MO, SCR_ID_UCM_OUTGOING); /* ensure no two incoming call screens in the history */
    }
    
    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_MO, SCR_ID_UCM_OUTGOING, 
        (FuncPtr)mmi_ucm_entry_outgoing_call,
        (void*)NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_outgoing_call
 * DESCRIPTION
 *  Shows the outgoing call screen
 *  This is invoked whenever the User requests for a outgoing call.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_outgoing_call(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_caller_res_struct* res_info = NULL;
    U8* guiBuffer = NULL;
    U16* file_path = NULL;
    U16* display_name = NULL;
    U16* ip_num = NULL;
    U16 calling_str_id = STR_ID_UCM_CALLING;
    U16 line_icon = 0;    
    U16 image_id = 0;
    U16 lsk_str = 0;
    MMI_BOOL is_video_update = MMI_FALSE;
    wgui_cate_momt_res_type_enum cat_image_type = WGUI_CATE_MOMT_RES_TYPE_IMAGE_ID;
    srv_ucm_call_info_struct call_info;
#if defined (__MMI_FTE_SUPPORT__) && !defined(__MMI_MAINLCD_240X240__)
    wgui_catcall_fte_iconbar_item_struct FTE_iconbar_items[MMI_UCM_FTE_ICOMBAR_MO_NUM];
    wgui_catcall_fte_iconbar_item_struct unlock_item;
    U16 icon_id;
    U16 label_id;
    U8 audio_mode;
#endif /* __MMI_FTE_SUPPORT__ */
    mmi_sim_enum sim_id = MMI_SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get outgoing call info */
    if (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) != 1)
    {
        if (mmi_frm_scrn_is_present(scr_info->group_id, SCR_ID_UCM_DISCONNECT_SCREEN, MMI_FRM_NODE_ALL_FLAG))
    	{
    	     mmi_frm_scrn_close(scr_info->group_id, SCR_ID_UCM_DISCONNECT_SCREEN);
	    }
			 
        mmi_ucm_entry_disconnecting_screen();
	    return;
    }

    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_OUTGOING,
                    (FuncPtr)mmi_ucm_exit_outgoing_call,
                    (FuncPtr)mmi_ucm_entry_outgoing_call,
                    MMI_FRM_FULL_SCRN))
    {
        mmi_frm_scrn_set_leave_proc(scr_info->group_id, SCR_ID_UCM_OUTGOING, (mmi_proc_func)mmi_ucm_outgoing_call_screen_delete_proc);
        return;
    }

#ifdef __MMI_BT_SUPPORT__
    mmi_ucm_set_bt_notify();
#endif /* __MMI_BT_SUPPORT__ */

    res_info = OslMalloc(sizeof(srv_ucm_caller_res_struct));

    if (!mmi_is_redrawing_bk_screens())
    {
        ClearKeyEvents();
    #ifdef __PXS_APP_ENABLE__
        if (MMI_TRUE == g_ucm_p->pxs_need_handle)
        {            
        }
        else
    #endif /* __PXS_APP_ENABLE__ */
    #ifdef __MMI_SCREEN_LOCK_ANY_TIME__
        if (MMI_FALSE == g_ucm_p->call_misc.keep_backlight_off)
    #endif /* __MMI_SCREEN_LOCK_ANY_TIME__ */
        {
            srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
        }
    }

    guiBuffer = mmi_frm_scrn_get_gui_buf(scr_info->group_id, SCR_ID_UCM_OUTGOING);

    srv_ucm_query_call_data(g_ucm_p->call_misc.index_list[0], &call_info);
    display_name = (U16*)call_info.remote_info.disp_name;

    /* calling string */
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (mmi_ucm_one_sim_behavior_is_needed())
    {
        sim_id = mmi_ucm_convert_call_type_to_sim(call_info.uid_info.call_type);
    }
    else
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
    {
    #if (MMI_MAX_SIM_NUM >= 2)
        if (call_info.uid_info.call_type & SRV_UCM_SIM1_CALL_TYPE_ALL)
        {
            calling_str_id = STR_ID_UCM_VOICE_CALLING_SIM1;
            sim_id = MMI_SIM1;
        }
        else if (call_info.uid_info.call_type & SRV_UCM_SIM2_CALL_TYPE_ALL)
        {
            calling_str_id = STR_ID_UCM_VOICE_CALLING_SIM2;
            sim_id = MMI_SIM2;
        }
    #if (MMI_MAX_SIM_NUM >= 3)
        else if (call_info.uid_info.call_type & SRV_UCM_SIM3_CALL_TYPE_ALL)
        {
            calling_str_id = STR_ID_UCM_VOICE_CALLING_SIM3;
            sim_id = MMI_SIM3;
        }
    #if (MMI_MAX_SIM_NUM == 4)
        else if (call_info.uid_info.call_type & SRV_UCM_SIM4_CALL_TYPE_ALL)
        {
            calling_str_id = STR_ID_UCM_VOICE_CALLING_SIM4;
            sim_id = MMI_SIM4;
        }
    #endif  /* (MMI_MAX_SIM_NUM == 4) */
    #endif  /* (MMI_MAX_SIM_NUM >= 3) */
    #endif  /* (MMI_MAX_SIM_NUM >= 2) */
    }

#ifdef __MMI_VOIP__
    if (call_info.uid_info.call_type == SRV_UCM_VOIP_CALL_TYPE)
    {
        calling_str_id = STR_ID_UCM_VOIP_CALLING;
    }
#endif /* __MMI_VOIP__ */
#ifdef __MMI_VIDEO_TELEPHONY__
#if defined(__MMI_3G_SWITCH__)
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (mmi_ucm_one_sim_behavior_is_needed())
    {
        if (call_info.uid_info.call_type == SRV_UCM_VIDEO_CALL_TYPE ||
            call_info.uid_info.call_type == SRV_UCM_VIDEO_CALL_TYPE_SIM2)
        {
            calling_str_id = STR_ID_UCM_VIDEO_CALLING;
        }
    }
#else /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
    if (call_info.uid_info.call_type == SRV_UCM_VIDEO_CALL_TYPE)
    {
        calling_str_id = STR_ID_UCM_VIDEO_CALLING_SIM1;
    }
    else if (call_info.uid_info.call_type == SRV_UCM_VIDEO_CALL_TYPE_SIM2)
    {
        calling_str_id = STR_ID_UCM_VIDEO_CALLING_SIM2;
    }
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
#else /* __MMI_3G_SWITCH__ */
    if (call_info.uid_info.call_type == SRV_UCM_VIDEO_CALL_TYPE)
    {
        calling_str_id = STR_ID_UCM_VIDEO_CALLING;
    }
#endif /* __MMI_3G_SWITCH__ */
#endif /* __MMI_VIDEO_TELEPHONY__ */

    if (MMI_TRUE == srv_ucm_is_emergency_number(call_info.uid_info.call_type, call_info.remote_info.num_uri))
    {
        calling_str_id = STR_ID_UCM_CALLING;
    }

    /* ip number */
    if (mmi_ucs2strlen((CHAR*)g_ucm_p->full_mo_mt_display.mo_mt_display.ip_num))
    {
        ip_num = g_ucm_p->full_mo_mt_display.mo_mt_display.ip_num;
    }

    /* image info */

#ifdef __MMI_PHB_CALLER_VIDEO__
    /* keep value in global, because when stop tone, can not query from call table */ 
    g_ucm_p->full_mo_mt_display.res_type = SRV_UCM_RES_TYPE_IMAGE_ID; /* keep the value not video res */
#endif /* __MMI_PHB_CALLER_VIDEO__ */

#ifdef __SAT__
    if (call_info.module_id == SRV_UCM_MODULE_ORIGIN_SAT &&
        mmi_sat_is_calling_icon_availabe(sim_id))
    {
        image_id = 0;
        file_path = (U16*)mmi_sat_get_calling_icon_path(sim_id);
        cat_image_type = WGUI_CATE_MOMT_RES_TYPE_IMAGE_FILE;
    }
    else
#endif /* __SAT__ */
    {
        if (MMI_FALSE == srv_ucm_get_caller_res_info(call_info.uid_info, res_info))
        {
            MMI_ASSERT(0);
        }

        image_id = res_info->pic_id;
        /*disallow to play caller video in outgoing call, to aviod the loud tone scaring user*/
        if (res_info->res_type & SRV_UCM_RES_TYPE_IMAGE_PATH)
        {
            cat_image_type = WGUI_CATE_MOMT_RES_TYPE_IMAGE_FILE;
            file_path = (U16*)res_info->pic_path;
        }
        else if(res_info->res_type & SRV_UCM_RES_TYPE_IMAGE_ID)
        {
            cat_image_type = WGUI_CATE_MOMT_RES_TYPE_IMAGE_ID;            
        }
        else
        {
            cat_image_type = WGUI_CATE_MOMT_RES_TYPE_IMAGE_ID;
        }
    }

    if (file_path != NULL)
    {
        if (mmi_ucm_is_file_valid((U16*)file_path, SRV_UCM_RES_TYPE_IMAGE_PATH) == MMI_FALSE)
        {
            image_id = MMI_UCM_DEFAULT_MOMT_IMAGE;
            file_path = NULL;
        }
    #ifdef __DRM_SUPPORT__
        else
        {
            /* consume right of caller image */
            mmi_ucm_drm_start_consume((U16*)file_path, SRV_UCM_RES_TYPE_IMAGE_PATH);
        }
    #endif /* __DRM_SUPPORT__ */
    }


#if defined (__MMI_CLAMSHELL__) && !defined (__MMI_SLIDE__)
    /* show sub before main LCD */
    if (!srv_clam_is_close())
    {
        /* show static sub LCD */
        is_video_update = MMI_TRUE;
    }
#endif /* __MMI_CLAMSHELL__ */

#ifdef __MMI_UCM_SLIM__
#ifndef __OP01_FWPBW__
    if (mmi_ucm_loud_option(SRV_UCM_OUTGOING_STATE) == SRV_UCM_RESULT_OK)
    {
        lsk_str = (mdi_audio_get_audio_mode() == AUD_MODE_LOUDSPK) ? (STR_ID_UCM_HAND_HELD) : (STR_ID_UCM_HAND_FREE);
    }
#endif /* __OP01_FWPBW__ */
#else /* __MMI_UCM_SLIM__ */
    /* line icon */ /* Use line icon compile option */
    if (g_ucm_p->full_mo_mt_display.line_icon)
    {
        line_icon = g_ucm_p->full_mo_mt_display.line_icon;
    }

#ifndef __OP01_FWPBW__
    if (mmi_ucm_outgoing_call_show_option())
    {
        lsk_str = STR_GLOBAL_OPTIONS;
    }
#endif /* __OP01_FWPBW__ */
#endif /* __MMI_UCM_SLIM__ */

#ifdef __MMI_UCM_SLIM__
	
#if defined(__MMI_BT_SUPPORT__)
		  if ((srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)) == MMI_TRUE)

	      {
	
			lsk_str = 0;
		  }
	
#endif
#endif

    if (SRV_UCM_RESULT_OK == mmi_ucm_outgoing_dialer_option())
    {
        #ifndef __MMI_MAINLCD_96X64__
        EnableCenterSoftkey(0, IMG_GLOBAL_DIAL_PAD_CSK);

	#else
	EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    #endif 
    }

#ifdef __MMI_TOUCH_SCREEN__
    wgui_catcall_set_button((UI_string_type) GetString(STR_GLOBAL_ABORT), mmi_ucm_outgoing_call_endkey);
#endif /* __MMI_TOUCH_SCREEN__ */

#if defined (__MMI_FTE_SUPPORT__) && !defined(__MMI_MAINLCD_240X240__)
#if defined(__PXS_APP_ENABLE__)
    memset(&unlock_item, 0, sizeof(wgui_catcall_fte_iconbar_item_struct));
#else /* __PXS_APP_ENABLE__ */
    mmi_ucm_FTE_fill_unlock_item(&unlock_item);
#endif /* __PXS_APP_ENABLE__ */
#ifdef __MMI_UCM_FTE_SLIM_ICONBAR_PRESENT__
    mmi_ucm_FTE_fill_iconbar_items(MMI_UCM_FTE_ICONBAR_OUTGOING_CALL, FTE_iconbar_items, MMI_UCM_FTE_ICOMBAR_MO_NUM);
#endif /*__MMI_UCM_FTE_SLIM_ICONBAR_PRESENT__*/
#if defined(__PXS_APP_ENABLE__)
    wgui_catcall_fte_setup(MMI_UCM_FTE_ICOMBAR_MO_NUM, FTE_iconbar_items, unlock_item, NULL);
#else /* __PXS_APP_ENABLE__ */
    wgui_catcall_fte_setup(MMI_UCM_FTE_ICOMBAR_MO_NUM, FTE_iconbar_items, unlock_item, mmi_ucm_FTE_screen_touch_hdlr);
#endif /* __PXS_APP_ENABLE__ */
    
    audio_mode = mdi_audio_get_audio_mode();
    label_id = (audio_mode == AUD_MODE_LOUDSPK) ? (STR_ID_UCM_HAND_HELD) : (STR_ID_UCM_HAND_FREE);
#ifdef __MMI_UCM_FTE_SLIM_ICONBAR_PRESENT__
    if (mmi_ucm_loud_option(SRV_UCM_OUTGOING_STATE) == SRV_UCM_RESULT_OK)
    {
        icon_id = (audio_mode == AUD_MODE_LOUDSPK) ? (IMG_ID_UCM_HAND_HELD) : (IMG_ID_UCM_HAND_FREE); /* to do - need to change to disable icon? */    
        wgui_catcall_fte_iconbar_enable_item(1, MMI_FALSE /* means enable */, get_string(label_id), get_image(icon_id));
    }
    else
    {
        icon_id = (audio_mode == AUD_MODE_LOUDSPK) ? (IMG_ID_UCM_HAND_HELD) : (IMG_ID_UCM_HAND_FREE); 
        wgui_catcall_fte_iconbar_enable_item(1, MMI_TRUE /* means disable */,get_string(label_id), get_image(icon_id));     
    }
#endif /*__MMI_UCM_FTE_SLIM_ICONBAR_PRESENT__*/
#if defined(__PXS_APP_ENABLE__)
    wgui_catcall_fte_lock_screen(MMI_FALSE);
#else /* __PXS_APP_ENABLE__ */
    /* handle lock case */
    mmi_ucm_FTE_scrn_update_hdlr_by_lock_state(mmi_ucm_get_auto_lock_state());
#endif /* __PXS_APP_ENABLE__ */
#endif /* __MMI_FTE_SUPPORT__ */
    ShowCategory17Screen(
            0,   /* title_id */ 
            lsk_str,        /* left_softkey */
            0,                   /* left_softkey_icon */
            STR_GLOBAL_ABORT,    /* right_softkey */
            0,                   /* right_softkey_icon */
            calling_str_id,                   /* NotificationStringId */ 
            (U8*)display_name, /* NameOrNumber */
            (U8*) ip_num,                /* IP_Number */
            line_icon,             /* line icon */
            IMG_PHB_DEFAULT,     /*default_image_id */
            image_id,               /* resource_id */
            (CHAR*)file_path,             /* resource_filename */
            cat_image_type,          /* resource_type */
            0,                   /* repeat_count, video/swflash only, repeat_count, 0 = infinite */
            is_video_update,        /* is_visaul_update, video/swflash only, update to LCM or not */
            MMI_FALSE,          /* is_video_aud, video/swflash only, play video's audio */
            MMI_FALSE,         /* is_play_aud_when_start */
            guiBuffer);


    if (SRV_UCM_RESULT_OK == mmi_ucm_outgoing_dialer_option())
    {
        /* group key */
        SetGroupKeyHandler(
            mmi_ucm_pre_send_dtmf,
            (U16*) PresentAllDialerKeys,
            TOTAL_DIALER_KEYS,
            KEY_EVENT_DOWN);

        mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_DTMF);
        SetCenterSoftkeyFunction(mmi_ucm_pre_entry_dtmf_editor, KEY_EVENT_UP);
    }

#ifdef __MMI_UCM_SLIM__
#ifndef __OP01_FWPBW__
    if (mmi_ucm_loud_option(SRV_UCM_OUTGOING_STATE) == SRV_UCM_RESULT_OK)
    {
        SetLeftSoftkeyFunction(mmi_ucm_set_loud_speaker, KEY_EVENT_UP);
    }
    mmi_frm_kbd_set_tone_state(MMI_KEY_LSK_TONE_DISABLE);
#endif /* __OP01_FWPBW__ */
#else /* __MMI_UCM_SLIM__ */
#ifndef __OP01_FWPBW__
    if (mmi_ucm_outgoing_call_show_option())
    {
        SetLeftSoftkeyFunction(mmi_ucm_entry_outgoing_call_option, KEY_EVENT_UP);
    }
#endif /* __OP01_FWPBW__ */
#endif /* __MMI_UCM_SLIM__ */

 
    SetKeyDownHandler(mmi_ucm_set_sidekey, KEY_VOL_UP);
    
     SetKeyDownHandler(mmi_ucm_set_sidekey, KEY_VOL_DOWN); 

    SetRightSoftkeyFunction(mmi_ucm_outgoing_call_endkey, KEY_EVENT_UP);
    SetKeyDownHandler(mmi_ucm_outgoing_call_endkey, KEY_END);

    mmi_frm_scrn_set_leave_proc(scr_info->group_id, SCR_ID_UCM_OUTGOING, (mmi_proc_func)mmi_ucm_outgoing_call_screen_delete_proc);
    mmi_frm_scrn_set_key_proc(scr_info->group_id, SCR_ID_UCM_OUTGOING, mmi_ucm_during_call_dtmf_key_proc); 
    OslMfree(res_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_gray_screen
 * DESCRIPTION
 *  display the gray screen in given SG
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_gray_screen(MMI_ID parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parent_id != mmi_frm_group_get_active_id())
    {
        return;
    }
    
    if (!mmi_frm_scrn_enter(
                    parent_id,
                    SCR_ID_UCM_GRAY_SCREEN,
                    (FuncPtr)NULL,
                    (FuncPtr)mmi_ucm_entry_gray_screen,
                    MMI_FRM_FG_ONLY_SCRN))
    {
        return;
    }
	mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
	ShowCategoryDummyScreen();
    /* wgui_cat9001_show(); */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_disconnecting_screen
 * DESCRIPTION
 *  Shows the disconnecting gray screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_disconnecting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    MMI_ID parent_id = mmi_frm_group_get_active_id();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (MMI_TRUE == mmi_ucm_is_ucm_sg(parent_id))
    {
    #ifndef __OP01_FWPBW__
        wgui_popup_disable_clear_background();
    #endif /* __OP01_FWPBW__ */

        if (!mmi_frm_scrn_enter(
                        parent_id,
                        SCR_ID_UCM_DISCONNECT_SCREEN,
                        (FuncPtr)NULL,
                        (FuncPtr)mmi_ucm_entry_disconnecting_screen,
                        MMI_FRM_FG_ONLY_SCRN))
        {
            return;
        }
	#ifdef __OP01_FWPBW__
		ShowCategory66Screen(
			STR_ID_UCM_PROCESSING,
			0,
			0,
			0,
			0,
			0,
			(U8*)GetString(STR_ID_UCM_PROCESSING),
			mmi_get_event_based_image(MMI_EVENT_PROGRESS),
			NULL);
	#else /* __OP01_FWPBW__ */
        wgui_cat9001_show();
	#endif /* __OP01_FWPBW__ */
        SetKeyDownHandler(mmi_ucm_end_all_processing_action, KEY_END);
    }
}


#ifdef __MMI_VIDEO_TELEPHONY__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_highlight_incall_opt_switch_to_video_call_action
 * DESCRIPTION
 *  Funtion is called when switch to video call item selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_highlight_incall_opt_switch_to_video_call_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum permit_result;
    mmi_confirm_property_struct arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    if ((permit_result =  mmi_ucm_switch_to_video_call_option(MMI_UCM_PERMIT_ONLY)) != SRV_UCM_RESULT_OK)
    {
	    mmi_ucm_display_error_popup(permit_result);
	    return;
	}

    /* Not dial VT call if out of 3G coverage */

    if (MMI_FALSE == mmi_ucm_vt_check_protocol_usable())
    {
        mmi_popup_display_ext(STR_ID_UCM_OUT_OF_3G_COVERAGE, MMI_EVENT_FAILURE, NULL);
        return;
    }

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.user_tag = (void *)MMI_UCM_CNF_VT_SWITCH_TO_VIDEO_CALL;
    arg.f_enter_history = MMI_FALSE;
    arg.callback = (mmi_proc_func)mmi_ucm_cnf_popup_cb;
    g_ucm_p->vt_cntx.switch_confirm_scrn = mmi_confirm_display((WCHAR *)((UI_string_type) GetString(STR_ID_UCM_SWITCH_TO_VIDEO_CALL_QUERY)), MMI_EVENT_QUERY, &arg);
    return;
}
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifndef __SLIM_UCM__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_mute
 * DESCRIPTION
 *  Turn on and turn off microphone in call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_mute(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(GetCurrHiliteID() < MAX_SUB_MENUS);

    if (srv_speech_is_phone_mute() == TRUE)
    {
        srv_speech_unmute_phone();
    #ifdef __MMI_UCM_RSK_MUTE__
        ChangeRightSoftkey(STR_GLOBAL_MUTE, 0);
    #else /* __MMI_UCM_RSK_MUTE__ */
        mmi_ucs2cpy((CHAR*) hintData[GetCurrHiliteID()], (CHAR*)GetString(STR_GLOBAL_OFF));
        Category52ChangeItemDescription(GetCurrHiliteID(), (U8*)GetString(STR_GLOBAL_OFF));
        ChangeLeftSoftkey(STR_GLOBAL_ON, IMG_GLOBAL_OK);
        RedrawCategoryFunction();
    #endif /* __MMI_UCM_RSK_MUTE__ */
    }
    else
    {
        srv_speech_mute_phone();
    #ifdef __MMI_UCM_RSK_MUTE__
        ChangeRightSoftkey(STR_ID_UCM_UNMUTE, 0);
    #else /* __MMI_UCM_RSK_MUTE__ */
        mmi_ucs2cpy((CHAR*)hintData[GetCurrHiliteID()], (CHAR*)GetString(STR_GLOBAL_ON));
        Category52ChangeItemDescription(GetCurrHiliteID(), (U8*)GetString(STR_GLOBAL_ON));
        ChangeLeftSoftkey(STR_GLOBAL_OFF, IMG_GLOBAL_OK);
        RedrawCategoryFunction();
    #endif /* __MMI_UCM_RSK_MUTE__ */
    }
}
#endif

#ifndef __MMI_UCM_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_dtmf_in_call
 * DESCRIPTION
 *  Temporarily turn on and turn off DTMF in call option.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_dtmf_in_call(mmi_menu_id mute_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(GetCurrHiliteID() < MAX_SUB_MENUS);

    if (MENU_ID_UCM_INCALL_OPTION_DTMF_ON == mute_menu_id)
    {
        g_ucm_p->call_misc.is_dtmf = MMI_TRUE;
    }
    else if (MENU_ID_UCM_INCALL_OPTION_DTMF_OFF == mute_menu_id)
    {
        g_ucm_p->call_misc.is_dtmf = MMI_FALSE;
    }
    else
    {
        MMI_ASSERT(0);
    }
    mmi_popup_display_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, NULL);
}
#endif /* __MMI_UCM_SLIM__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_incoming_call
 * DESCRIPTION
 *  Enter incoming call scrn
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ensure no two active call screens in the history */
    if (mmi_frm_scrn_is_present(GRP_ID_UCM_INCALL, SCR_ID_UCM_IN_CALL,MMI_FRM_NODE_ALL_FLAG))
    {    
        mmi_frm_scrn_close(GRP_ID_UCM_INCALL, SCR_ID_UCM_IN_CALL);
    }

        
    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_INCALL, SCR_ID_UCM_IN_CALL, 
        (FuncPtr)mmi_ucm_entry_in_call, 
        (void*)NULL);

    
}


/*****************************************************************************
 * FUNCTION
 * mmi_ucm_during_call_dtmf_key_proc
 * DESCRIPTION
 *  Entry function of handle key up during call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

mmi_ret mmi_ucm_during_call_dtmf_key_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_PRE_KEY)
    {
        if (wgui_inputs_dialer_is_dialer_keys(key_evt->key_code) == MMI_TRUE)
        {
            if (key_evt->key_type == KEY_EVENT_UP)
            {
                mmi_ucm_dtmf_key_up(key_evt->key_code);         
	            mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_DTMF);
            }
        }
    }
    return MMI_RET_OK;
}

#ifdef __MMI_UCM_PLUTO_BW__
void mmi_ucm_get_active_call_screen_components(wgui_cat9023_call_info_struct *cm_active_call_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
	S32 num_group;
    S32 group_index_array[SRV_UCM_MAX_GROUP];
    srv_ucm_group_info_struct group_info;
S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	cm_active_call_struct[0].call_flag = WGUI_CAT9023_NO_CALL;
	cm_active_call_struct[1].call_flag = WGUI_CAT9023_NO_CALL;

	if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
	{
		cm_active_call_struct[0].active_call_icon = IMG_ID_UCM_CALL_STATE_ACTIVE;
		cm_active_call_struct[0].call_flag = WGUI_CAT9023_ACTIVE_CALL;

		/* if the active call is a conference call, show string as "Conference" instead of name/number */
		if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 1)
		{
			cm_active_call_struct[0].active_caller = (PU8) get_string(STR_ID_UCM_CONFERENCE);
		}

	}
	
	if (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
	{
		cm_active_call_struct[1].held_call_icon = IMG_ID_UCM_CALL_STATE_HOLD;
		cm_active_call_struct[1].held_call_str = (PU8) get_string(STR_ID_UCM_HOLD);
		cm_active_call_struct[1].call_flag = WGUI_CAT9023_HELD_CALL;

		/* if the held call is a conference call, show string as "Conference" instead of name/number */
		if (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 1)
		{
			cm_active_call_struct[1].held_caller = (PU8) get_string(STR_ID_UCM_CONFERENCE);
		}
	}

}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_in_call
 * DESCRIPTION
 *  Entry function of in call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_in_call(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *call_icon = NULL;
    U8 *gui_buffer = NULL;
    U8* title = NULL;
    U16 rsk_str = 0, num_items = 0;
    U16 lsk_str = 0;
    S32 curr_hilite_tab = 0, i = 0;
    S32 num_group;
    srv_ucm_call_type_enum incall_type = (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_VOIP_CALL_TYPE | SRV_UCM_DATA_CALL_TYPE_ALL);
    srv_ucm_group_info_struct group_info;
    S32 group_index_array[SRV_UCM_MAX_GROUP];
    S32 call_index_array[SRV_UCM_MAX_CALL_IN_GROUP];
    srv_ucm_index_info_struct index;
    srv_ucm_call_info_struct *call_info = NULL;
    srv_ucm_call_info_struct *call_info_hold = NULL;
#ifdef __MMI_UCM_SINGLE_CALL_SCREEN_ENHANCE__
    srv_ucm_caller_res_struct* res_info = NULL;
    WGUI_CATCALL_CALLER_MEDIA_INFO *CallerMedia;
    srv_ucm_res_type_enum filtered_res_type = SRV_UCM_RES_TYPE_IMAGE_ID;
#endif /* __MMI_UCM_SINGLE_CALL_SCREEN_ENHANCE__ */
#if defined (__MMI_FTE_SUPPORT__) && !defined(__MMI_MAINLCD_240X240__)
    wgui_catcall_fte_iconbar_item_struct *FTE_iconbar_items = NULL;
    wgui_catcall_fte_iconbar_item_struct unlock_item;
    U16 icon_id;
    U16 label_id;
    MMI_BOOL execute_flag;
#endif /* __MMI_FTE_SUPPORT__ */
#ifdef __MMI_UCM_PLUTO_BW__
	wgui_cat9023_call_info_struct active_cm[2];
	active_cm[0].active_caller = NULL;
	active_cm[1].held_caller = NULL;
#endif /*__MMI_UCM_PLUTO_BW__*/
#ifdef __MMI_CATE_CM_TAB_BAR_SLIM__
    cm_tab_bar_item_type tab_bar_items[5];//as of now lets keep it 5
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, incall_type, MMI_FALSE, NULL) <= 0) && 
        (srv_ucm_query_group_count(SRV_UCM_HOLD_STATE, incall_type, MMI_FALSE, NULL) <= 0))
    {
        return;
    }

    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_IN_CALL,
                    (FuncPtr)mmi_ucm_exit_in_call,
                    (FuncPtr)mmi_ucm_entry_in_call,
                    MMI_FRM_FULL_SCRN))
    {
        mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_INCALL, SCR_ID_UCM_IN_CALL, (mmi_proc_func)mmi_ucm_in_call_screen_delete_proc);
        return;
    }
    
   
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_INCALL);

#ifdef __MMI_BT_SUPPORT__
    mmi_ucm_set_bt_notify();
#endif /* __MMI_BT_SUPPORT__ */

    /* for FW new design, need this api to inform framework that app wants to handle incomplete event - for long press */
    mmi_frm_send_incomplete_key_event_to_new_screen(MMI_TRUE);
    
    gui_buffer = mmi_frm_scrn_get_gui_buf(scr_info->group_id, SCR_ID_UCM_IN_CALL);

#ifndef __MMI_UCM_PLUTO_BW__
    /* number of group */
    num_group = srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, MMI_FALSE, group_index_array);
    
    MMI_ASSERT(num_group <= SRV_UCM_MAX_GROUP);
    /* icon and text of each tab */
    //MMI_ASSERT(num_group < UI_MAX_TAB_BAR_ITEMS);
    for (i = 0; i < num_group; i++)
    {
        /* get state and call type */
        if (srv_ucm_query_group_data(group_index_array[i], &group_info) <= 0)
        {
             MMI_ASSERT(0);
        }
        else
        {
#ifndef __MMI_CATE_CM_TAB_BAR_SLIM__
            if (group_info.call_state == SRV_UCM_ACTIVE_STATE)
            {
                MMI_tab_bar_items[i].icon = get_image(IMG_ID_UCM_CALL_STATE_ACTIVE);
            }
            else if (group_info.call_state == SRV_UCM_HOLD_STATE)
            {
                MMI_tab_bar_items[i].icon = get_image(IMG_ID_UCM_CALL_STATE_HOLD);            
            }
            else
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_INCALL_CALL_STATE);
            }

            MMI_tab_bar_items[i].text = NULL;        
            MMI_tab_bar_items[i].flags = 0; /* no blink */
#else
  if (group_info.call_state == SRV_UCM_ACTIVE_STATE)
            {
              tab_bar_items[i].icon = get_image(IMG_ID_UCM_CALL_STATE_ACTIVE);
            }
            else if (group_info.call_state == SRV_UCM_HOLD_STATE)
            {
                tab_bar_items[i].icon = get_image(IMG_ID_UCM_CALL_STATE_HOLD);            
            }
            else
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_INCALL_CALL_STATE);
            }

           tab_bar_items[i].text = NULL;        
            tab_bar_items[i].flags = 0; /* no blink */
#endif

        }
    }

    /* title of hilite tab */
    curr_hilite_tab = g_ucm_p->call_misc.hilite_tab;
#endif /*__MMI_UCM_PLUTO_BW__*/    
    
    if (srv_ucm_query_group_data(curr_hilite_tab, &group_info) <= 0)
    {
         MMI_ASSERT(0);
    }

    title = (U8*)GetString(mmi_ucm_get_call_type_string_id(group_info.call_type, group_info.call_state));
    
    num_items = mmi_ucm_get_call_index_list_by_group_index(curr_hilite_tab, call_index_array);

    call_info = OslMalloc(sizeof(srv_ucm_call_info_struct));

#if defined(__MMI_UCM_SINGLE_CALL_SCREEN_ENHANCE__) || !defined(__MMI_UCM_SLIM__)
    call_icon = OslMalloc(sizeof(U16) * SRV_UCM_MAX_CALL_IN_GROUP);
#endif /* defined(__MMI_UCM_SINGLE_CALL_SCREEN_ENHANCE__) || !defined(__MMI_UCM_SLIM__) */
    /* display name and icon of each items of current tab */        
    for (i = 0; i < num_items; i++)
    {
        U32 char_num = ((MAX_SUB_MENU_SIZE / ENCODING_LENGTH) < SRV_UCM_MAX_DISP_NAME_LEN)?
                        (MAX_SUB_MENU_SIZE / ENCODING_LENGTH): SRV_UCM_MAX_DISP_NAME_LEN;
                
        subMenuDataPtrs[i] = subMenuData[i];
        
        /*get remote info*/
        index.group_index = curr_hilite_tab;
        index.call_index = call_index_array[i];
        srv_ucm_query_call_data(index, call_info);

        mmi_ucs2ncpy(
            (CHAR*)subMenuDataPtrs[i],
            (CHAR*)call_info->remote_info.disp_name,
            char_num);
        
    #if defined(__MMI_UCM_SINGLE_CALL_SCREEN_ENHANCE__) || !defined(__MMI_UCM_SLIM__)
        call_icon[i] = call_info->remote_info.line_icon;

        if (call_icon[i] == 0)
        {
            call_icon[i] = IMG_ID_UCM_ACTIVE_CALL;
        }
    #endif /* defined(__MMI_UCM_SINGLE_CALL_SCREEN_ENHANCE__) || !defined(__MMI_UCM_SLIM__) */
    }

    if (mmi_ucm_in_call_show_option())
    {
        lsk_str = STR_GLOBAL_OPTIONS;
    }

#ifdef __MMI_UCM_RSK_MUTE__
    if (mmi_ucm_mute_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        if (srv_speech_is_phone_mute() == MMI_FALSE)
        {
            rsk_str = STR_GLOBAL_MUTE;
        }
        else
        {
            rsk_str = STR_ID_UCM_UNMUTE;
        }
    }
    if (mmi_ucm_loud_option(SRV_UCM_CALL_STATE_CONNECTED) == SRV_UCM_RESULT_OK) 
    {
        if (mdi_audio_get_audio_mode() == AUD_MODE_LOUDSPK)
        {
            EnableCenterSoftkey(0, IMG_ID_UCM_H_HELD); /* set H-Held icon */
        }
        else
        {
            EnableCenterSoftkey(0, IMG_ID_UCM_H_FREE); /* set H-Free icon */
        }
    }
#else /* __MMI_UCM_RSK_MUTE__ */
#if defined(__OP01_FWPBW__)
    if (!(mmi_frm_kbd_is_key_supported(KEY_VOL_UP) || mmi_frm_kbd_is_key_supported(KEY_VOL_DOWN)))
    {
        rsk_str = STR_ID_UCM_VOLUME;
    }
    else
    {    
        rsk_str = STR_ID_UCM_HANGUP;
    }
#else /* __OP01_FWPBW__ */
    if (mmi_ucm_loud_option(SRV_UCM_CALL_STATE_CONNECTED) == SRV_UCM_RESULT_OK) 
    {   
        /*x*/
        rsk_str = (mdi_audio_get_audio_mode() == AUD_MODE_LOUDSPK) ? (STR_ID_UCM_HAND_HELD) : (STR_ID_UCM_HAND_FREE);
    }
#endif /* __OP01_FWPBW__ */


#ifndef __MMI_MAINLCD_96X64__
		EnableCenterSoftkey(0, IMG_GLOBAL_DIAL_PAD_CSK);
	
	#else
		EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    #endif 

#endif /* __MMI_UCM_RSK_MUTE__ */ 

#if defined (__MMI_FTE_SUPPORT__) && !defined(__MMI_MAINLCD_240X240__)

#if defined(__PXS_APP_ENABLE__)
    memset(&unlock_item, 0, sizeof(wgui_catcall_fte_iconbar_item_struct));
#else /* __PXS_APP_ENABLE__ */
    mmi_ucm_FTE_fill_unlock_item(&unlock_item);
#endif /* __PXS_APP_ENABLE__ */

    /* handle in call case - prepare info for iconbar */
    FTE_iconbar_items = OslMalloc(sizeof(wgui_catcall_fte_iconbar_item_struct) * MMI_UCM_FTE_ICOMBAR_INCALL_NUM);
    memset(FTE_iconbar_items, 0x00, sizeof(wgui_catcall_fte_iconbar_item_struct) * MMI_UCM_FTE_ICOMBAR_INCALL_NUM);
#ifdef __MMI_UCM_FTE_SLIM_ICONBAR_PRESENT__
    mmi_ucm_FTE_fill_iconbar_items(MMI_UCM_FTE_ICONBAR_IN_CALL, FTE_iconbar_items, MMI_UCM_FTE_ICOMBAR_INCALL_NUM);
#endif /*__MMI_UCM_FTE_SLIM_ICONBAR_PRESENT__*/
#if defined(__PXS_APP_ENABLE__)
    wgui_catcall_fte_setup(MMI_UCM_FTE_ICOMBAR_INCALL_NUM, FTE_iconbar_items, unlock_item, NULL);
#else /* __PXS_APP_ENABLE__ */
    wgui_catcall_fte_setup(MMI_UCM_FTE_ICOMBAR_INCALL_NUM, FTE_iconbar_items, unlock_item, mmi_ucm_FTE_screen_touch_hdlr);
#endif /* __PXS_APP_ENABLE__ */
    OslMfree(FTE_iconbar_items);
#ifdef __MMI_UCM_FTE_SLIM_ICONBAR_PRESENT__
    if (4 == MMI_UCM_FTE_ICOMBAR_INCALL_NUM)
    {
        /* decide if to grey mute/unmute iconbar button */
        if (SRV_UCM_RESULT_OK != mmi_ucm_mute_option(MMI_UCM_PERMIT_ONLY))
        {
            label_id = (srv_speech_is_phone_mute() == MMI_FALSE) ? (STR_GLOBAL_MUTE) : (STR_ID_UCM_UNMUTE);
            icon_id = (srv_speech_is_phone_mute() == MMI_FALSE) ? (IMG_ID_UCM_MUTE) : (IMG_ID_UCM_UNMUTE);
            wgui_catcall_fte_iconbar_enable_item(0, MMI_TRUE /* means disable */, get_string(label_id), get_image(icon_id));     
        }

        if (1 == srv_ucm_query_group_data(g_ucm_p->call_misc.hilite_tab, &group_info))
        {
            if (srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, MMI_FALSE, NULL) > 1)
            {
                /* decide if to grey conf iconbar button */
                if (mmi_ucm_multiple_group_option(SRV_UCM_CONFERENCE_ACT, MMI_UCM_PERMIT_ONLY, &execute_flag) != SRV_UCM_RESULT_OK)
                {
                    wgui_catcall_fte_iconbar_enable_item(1, MMI_TRUE /* means disable */, get_string(STR_ID_UCM_CONFERENCE), get_image(IMG_ID_UCM_CONF));     
                }
            }
            else
            {
                /* decide if to grey hold/retrieve iconbar button */
                if (SRV_UCM_ACTIVE_STATE == group_info.call_state)
                {
                    if (mmi_ucm_single_group_option(SRV_UCM_HOLD_ACT, MMI_UCM_PERMIT_ONLY) != SRV_UCM_RESULT_OK)
                    {
                        wgui_catcall_fte_iconbar_enable_item(1, MMI_TRUE /* means disable */, get_string(STR_ID_UCM_HOLD), get_image(IMG_ID_UCM_HOLD));
                    }
                }
                else if (SRV_UCM_HOLD_STATE == group_info.call_state)
                {
                    if (mmi_ucm_single_group_option(SRV_UCM_RETRIEVE_ACT, MMI_UCM_PERMIT_ONLY) != SRV_UCM_RESULT_OK)
                    {
                        wgui_catcall_fte_iconbar_enable_item(1, MMI_TRUE /* means disable */, get_string(STR_ID_UCM_RETRIEVE), get_image(IMG_ID_UCM_RETRIEVE));
                    }
                }
            }
        }
    }
#endif /*__MMI_UCM_FTE_SLIM_ICONBAR_PRESENT__*/
#if defined(__PXS_APP_ENABLE__)
    wgui_catcall_fte_lock_screen(MMI_FALSE);
#else /* __PXS_APP_ENABLE__ */
    /* handle lock case */
    mmi_ucm_FTE_scrn_update_hdlr_by_lock_state(mmi_ucm_get_auto_lock_state());
#endif /* __PXS_APP_ENABLE__ */

#endif /* __MMI_FTE_SUPPORT__ */

#ifdef __MMI_UCM_SINGLE_CALL_SCREEN_ENHANCE__
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, g_ucm_p->call_misc.index_list) == 1)
    {
      	U16 stateIcon = 0;
        /* single call */
        MMI_ASSERT(g_ucm_p->call_misc.index_list[0].group_index == g_ucm_p->call_misc.hilite_tab);
        /* default image */
        
        if (MMI_FALSE == srv_ucm_query_call_data(g_ucm_p->call_misc.index_list[0], call_info))
        {
            MMI_ASSERT(0);
        }
        
        if (call_info->call_state == SRV_UCM_ACTIVE_STATE)
        {
            stateIcon = IMG_ID_UCM_DEFAULT_ACTIVE_STATE;
        }
        else if (call_info->call_state == SRV_UCM_HOLD_STATE)
        {
            stateIcon = IMG_ID_UCM_DEFAULT_HOLD_STATE;
        }
        else
        {
            ASSERT(0);	
        }

        res_info = OslMalloc(sizeof(srv_ucm_caller_res_struct));
        memset(res_info, 0x00, sizeof(srv_ucm_caller_res_struct));
        srv_ucm_get_caller_res_info(call_info->uid_info, res_info);

        /* Decide visual type */
        if (MMI_FALSE == mmi_ucm_decide_visual_type(res_info->res_type, &filtered_res_type))
        {
            /* call srv will guarantee at least image and tone */
            MMI_ASSERT(0);
        }
        
        CallerMedia = OslMalloc(sizeof(WGUI_CATCALL_CALLER_MEDIA_INFO));
        memset(CallerMedia, 0x00, sizeof(WGUI_CATCALL_CALLER_MEDIA_INFO));

        switch (filtered_res_type)
        {
            case SRV_UCM_RES_TYPE_IMAGE_ID:
            {
                if (res_info->pic_id != IMG_PHB_DEFAULT)
                {
                    CallerMedia->resource_type = WGUI_CATE_MOMT_RES_TYPE_IMAGE_ID;
                    CallerMedia->resource_id = res_info->pic_id;
                }
                else
                {
                    CallerMedia->resource_type = WGUI_CATE_MOMT_RES_TYPE_IMAGE_ID;
                    CallerMedia->resource_id = stateIcon;
                }
            }
            break;
        
            case SRV_UCM_RES_TYPE_IMAGE_PATH:
            {
                if (mmi_ucm_is_file_valid((U16*)res_info->pic_path, SRV_UCM_RES_TYPE_IMAGE_PATH) == MMI_TRUE)
                {
                    CallerMedia->resource_type = WGUI_CATE_MOMT_RES_TYPE_IMAGE_FILE;
                    CallerMedia->resource_filename = (CHAR*)res_info->pic_path;
                }
                else
                {
                    CallerMedia->resource_type = WGUI_CATE_MOMT_RES_TYPE_IMAGE_ID;
                    CallerMedia->resource_id = stateIcon;
                }
            }
            break;

            case SRV_UCM_RES_TYPE_VIDEO_ID:
            case SRV_UCM_RES_TYPE_VIDEO_PATH:
            {
                /* currently in call screen does'nt support these call types */
            }
            break;

            default:
            {
                MMI_ASSERT(0);
            }
            break;
        }

        wgui_catcall_set_button((UI_string_type) GetString(STR_ID_UCM_END_CALL), mmi_ucm_in_call_endkey);

        ShowCategory20Screen(
            lsk_str,
            0,
            rsk_str,
            0,
            title,
            subMenuDataPtrs[0],
            &call_info->start_time,
            call_icon[0],
            stateIcon,
            CallerMedia,
            MMI_FALSE,
            gui_buffer);
        
        OslMfree(res_info);
        OslMfree(CallerMedia);
    }
    else
#endif /* __MMI_UCM_SINGLE_CALL_SCREEN_ENHANCE__ */
    {
        /* get call state */
        index.group_index = curr_hilite_tab;
        index.call_index = g_ucm_p->call_misc.hilite_index;
        if (MMI_FALSE == srv_ucm_query_call_data(index, call_info))
        {
            MMI_ASSERT(0);
        }

#ifdef __MMI_UCM_PLUTO_BW__
		mmi_ucm_get_active_call_screen_components(active_cm);

		active_cm[0].active_call_duration = (MYTIME*) &call_info->start_time;

			/* number of group */
			num_group = srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, MMI_FALSE, group_index_array);
		    
			MMI_ASSERT(num_group <= SRV_UCM_MAX_GROUP);
			/* icon and text of each tab */
			MMI_ASSERT(num_group < UI_MAX_TAB_BAR_ITEMS);
			call_info_hold = OslMalloc(sizeof(srv_ucm_call_info_struct));
			for (i = 0; i < num_group; i++)
			{
				/* get state and call type */
				if (srv_ucm_query_group_data(group_index_array[i], &group_info) <= 0)
				{
					 MMI_ASSERT(0);
				}
				else
				{
					if (group_info.call_state == SRV_UCM_ACTIVE_STATE)
					{
								
						index.group_index = group_index_array[i];
						index.call_index = 0;
						srv_ucm_query_call_data(index, call_info);
					        active_cm[0].active_call_duration = (MYTIME*) &call_info->start_time;

						
						
						active_cm[0].active_caller = OslMalloc((SRV_UCM_MAX_DISP_NAME_LEN + 1) * 2);
						memcpy(active_cm[0].active_caller,(PU8) call_info->remote_info.disp_name, (SRV_UCM_MAX_DISP_NAME_LEN + 1) * 2);


					
					}
					else if (group_info.call_state == SRV_UCM_HOLD_STATE)
					{
						index.group_index = group_index_array[i];
						index.call_index = 0;
						srv_ucm_query_call_data(index, call_info_hold);
            
						
						active_cm[1].held_caller = OslMalloc((SRV_UCM_MAX_DISP_NAME_LEN + 1) * 2);
						memcpy(active_cm[1].held_caller,(PU8) call_info_hold->remote_info.disp_name, (SRV_UCM_MAX_DISP_NAME_LEN + 1) * 2);
						
					}
					else
					{
						MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_INCALL_CALL_STATE);
					}
				}
			}


		wgui_cat9023_show(lsk_str,rsk_str,(wgui_cat9023_call_info_struct*) &active_cm,gui_buffer);

		

		if(active_cm[0].active_caller)
		{
			OslMfree(active_cm[0].active_caller);
			active_cm[0].active_caller = NULL;
		}
		if(active_cm[1].held_caller)
		{
			OslMfree(active_cm[1].held_caller);
			active_cm[1].held_caller = NULL;
		}

#endif /*__MMI_UCM_PLUTO_BW__*/

        /* multiple calls */
#ifndef __MMI_UCM_PLUTO_BW__
#ifndef __MMI_CATE_CM_TAB_BAR_SLIM__
        ShowCategory403Screen(
            title,
            0,
            lsk_str,
            0,
            rsk_str,
            0,
            (S8)num_group,
            (S8)g_ucm_p->call_misc.hilite_tab,
            MMI_tab_bar_items,
            &call_info->start_time,
            0,
            subMenuDataPtrs,
            call_icon,
            num_items,
            (U16)g_ucm_p->call_misc.hilite_index,
            gui_buffer);

#else
        ShowCategory4031Screen(
            title,
            0,
            lsk_str,
            0,
            rsk_str,
            0,
            (S8)num_group,
            (S8)g_ucm_p->call_misc.hilite_tab,
            tab_bar_items,
            &call_info->start_time,
            0,
            subMenuDataPtrs,
            call_icon,
            num_items,
            (U16)g_ucm_p->call_misc.hilite_index,
            gui_buffer);
#endif

#endif /*__MMI_UCM_PLUTO_BW__*/
    #ifdef __MMI_TOUCH_SCREEN__
        wgui_register_list_item_selected_callback_all(UI_dummy_function);
        SetCategory403TabSelectCallback(mmi_ucm_tab_jump);
    #endif /* __MMI_TOUCH_SCREEN__ */

        if (num_group > 1)
        {
            /* in new framework key design, won't translate long press and repeat to several down, therefore need to register for long press and repeat here */
            SetKeyLongpressHandler(mmi_ucm_tab_prev, KEY_LEFT_ARROW); 
            SetKeyLongpressHandler(mmi_ucm_tab_prev, KEY_RIGHT_ARROW); 
            SetKeyRepeatHandler(mmi_ucm_tab_prev, KEY_LEFT_ARROW); 
            SetKeyRepeatHandler(mmi_ucm_tab_prev, KEY_RIGHT_ARROW); 
            SetKeyDownHandler(mmi_ucm_tab_prev, KEY_LEFT_ARROW);   /* move to previous tab */
            SetKeyDownHandler(mmi_ucm_tab_next, KEY_RIGHT_ARROW);  /* move to next tab */
        }

        RegisterHighlightHandler(mmi_ucm_highlight_in_call_item);

    }

    OslMfree(call_info);
    if(call_info_hold)
    {
      OslMfree(call_info_hold);
    }
	
#if defined(__MMI_UCM_SINGLE_CALL_SCREEN_ENHANCE__) || !defined(__MMI_UCM_SLIM__)
    OslMfree(call_icon);
#endif /* defined(__MMI_UCM_SINGLE_CALL_SCREEN_ENHANCE__) || !defined(__MMI_UCM_SLIM__) */

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    /* intuitive cmd */
    wgui_register_tap_callback(mmi_ucm_intuitive_cmd_cb);
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

    if (mmi_ucm_in_call_show_option())
    {
        SetLeftSoftkeyFunction(mmi_ucm_entry_incall_option, KEY_EVENT_UP);
    }

#ifdef __MMI_UCM_RSK_MUTE__
    if (mmi_ucm_mute_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        SetRightSoftkeyFunction(mmi_ucm_set_mute, KEY_EVENT_UP);
    }
    SetCenterSoftkeyFunction(mmi_ucm_set_loud_speaker, KEY_EVENT_UP);
#else /* __MMI_UCM_RSK_MUTE__ */
#if defined(__OP01_FWPBW__)
    if (!(mmi_frm_kbd_is_key_supported(KEY_VOL_UP) || mmi_frm_kbd_is_key_supported(KEY_VOL_DOWN)))
    {
        SetRightSoftkeyFunction(mmi_ucm_set_volume_hdlr, KEY_EVENT_UP);
    }
    else
    {
        SetRightSoftkeyFunction(mmi_ucm_in_call_endkey, KEY_EVENT_UP);
    }
#else /* __OP01_FWPBW__ */
    if (mmi_ucm_loud_option(SRV_UCM_CALL_STATE_CONNECTED) == SRV_UCM_RESULT_OK)
    {
        SetRightSoftkeyFunction(mmi_ucm_set_loud_speaker, KEY_EVENT_UP);
    }
    mmi_frm_kbd_set_tone_state(MMI_KEY_RSK_TONE_DISABLE);
#endif /* __OP01_FWPBW__ */
    SetCenterSoftkeyFunction(mmi_ucm_pre_entry_dtmf_editor, KEY_EVENT_UP);
#endif /* __MMI_UCM_RSK_MUTE__ */

    SetGroupKeyHandler(mmi_ucm_pre_send_dtmf, (U16*)PresentAllDialerKeys, TOTAL_DIALER_KEYS, KEY_EVENT_DOWN);
    mmi_frm_set_dial_key_tone_type(MMI_DIALER_KEY_TONE_DTMF);
    SetKeyDownHandler(mmi_ucm_in_call_sendkey, KEY_SEND);
    SetKeyDownHandler(mmi_ucm_in_call_endkey, KEY_END);

    /* must set KEY_EVENT_DOWN function to overwrite original side key handler of category 52 */
    if (MMI_FALSE == srv_ucm_query_group_data(curr_hilite_tab, &group_info))
    {
        MMI_ASSERT(0);
    }
    if ((group_info.call_type & SRV_UCM_DATA_CALL_TYPE_ALL) == 0)
    {
        SetKeyDownHandler(mmi_ucm_set_sidekey, KEY_VOL_UP);
        SetKeyDownHandler(mmi_ucm_set_sidekey, KEY_VOL_DOWN);
    }

    mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_INCALL, SCR_ID_UCM_IN_CALL, (mmi_proc_func) mmi_ucm_in_call_screen_delete_proc); 
    mmi_frm_scrn_set_key_proc(GRP_ID_UCM_INCALL, SCR_ID_UCM_IN_CALL, mmi_ucm_during_call_dtmf_key_proc); 

    if (!mmi_is_redrawing_bk_screens())
    {
        if (MMI_TRUE == mmi_ucm_is_any_disconnecting_call())
        {
            mmi_evt_mmi_ucm_disconnecting_call_exist_struct evt;
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_UCM_DISCONNECTING);
            mmi_frm_post_event((mmi_event_struct *)&evt, mmi_ucm_post_event_hdlr, NULL);
        }
    }

#ifdef __MMI_BACKGROUND_CALL_WITH_NCENTER__
    mmi_ucm_close_incall_notification();
#endif /* __MMI_BACKGROUND_CALL_WITH_NCENTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_multi_held_call
 * DESCRIPTION
 *  create function for entry multiple held call selection screen. use new screen mechanism which can bypass parameter
 * PARAMETERS
 *  act_op:          [IN]    act opcode
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_multi_held_call(srv_ucm_act_opcode_enum act_op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_INCALL, SCR_ID_UCM_MULTI_HELD_CALL, 
        (FuncPtr)mmi_ucm_entry_multi_held_call, 
        (void*)act_op);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_multi_held_call
 * DESCRIPTION
 *  Entry function of call option\Swap or Conference
 *  if more than one held calls can be selected.
 * PARAMETERS
 *   act_op:          [IN]    act opcode
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_multi_held_call(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    S32 i = 0, held_group = 0;
    S32 group_index_array[SRV_UCM_MAX_GROUP];
    S32 call_index_array[SRV_UCM_MAX_CALL_IN_GROUP];
    srv_ucm_act_opcode_enum act_op;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        return;
    }

    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_MULTI_HELD_CALL,
                    NULL,
                    (FuncPtr)mmi_ucm_entry_multi_held_call,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    
    act_op = (srv_ucm_act_opcode_enum)((U32)(scr_info->user_data));

    guiBuffer = mmi_frm_scrn_get_gui_buf(scr_info->group_id, SCR_ID_UCM_MULTI_HELD_CALL);

    memset(&g_ucm_p->call_misc.index_list, -1, (SRV_UCM_MAX_CALL * sizeof(srv_ucm_index_info_struct)));

    if (act_op == SRV_UCM_SWAP_ACT)
    {
        held_group = srv_ucm_query_group_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_NO_DATA_CSD, MMI_FALSE, group_index_array);
    }
    else if (act_op == SRV_UCM_CONFERENCE_ACT)
    {
        held_group = srv_ucm_query_group_count(SRV_UCM_HOLD_STATE, SRV_UCM_VOIP_CALL_TYPE, MMI_TRUE, group_index_array);
    }
    else
    {
        MMI_ASSERT(0);
    }
    
    MMI_ASSERT(held_group < MAX_SUB_MENUS);
    MMI_ASSERT(held_group < SRV_UCM_MAX_GROUP);
    
    for (i = 0; i < held_group; i++)
    {
        U32 char_num = ((MAX_SUB_MENU_SIZE / ENCODING_LENGTH) < SRV_UCM_MAX_DISP_NAME_LEN)?
                        (MAX_SUB_MENU_SIZE / ENCODING_LENGTH): SRV_UCM_MAX_DISP_NAME_LEN;

        srv_ucm_index_info_struct index;
        srv_ucm_call_info_struct call_info;
        
        subMenuDataPtrs[i] = subMenuData[i];
        memset(subMenuDataPtrs[i], 0, MAX_SUB_MENU_SIZE);

        /*get each tab's remote_info.disp_name*/        
        mmi_ucm_get_call_index_list_by_group_index(group_index_array[i], call_index_array);
        
        index.group_index = group_index_array[i];
        index.call_index = call_index_array[0];
        if (MMI_FALSE == srv_ucm_query_call_data(index, &call_info))
        {
            MMI_ASSERT(0);
        }
        
        mmi_ucs2ncpy(
            (CHAR*)subMenuDataPtrs[i],
            (CHAR*)call_info.remote_info.disp_name,
            char_num);
    } 
    
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    RegisterHighlightHandler(mmi_ucm_highlight_multi_held_call_item);
    ShowCategory6Screen(
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        held_group,
        subMenuDataPtrs,
        NULL,
        0,
        guiBuffer);

    if (act_op == SRV_UCM_SWAP_ACT)
    {
        SetLeftSoftkeyFunction(mmi_ucm_entry_held_call_selected_for_swap, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_ucm_entry_held_call_selected_for_swap, KEY_EVENT_UP);
    }
    else if (act_op == SRV_UCM_CONFERENCE_ACT)
    {
        SetLeftSoftkeyFunction(mmi_ucm_entry_held_call_selected_for_conf, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_ucm_entry_held_call_selected_for_conf, KEY_EVENT_UP);
    }
    else
    {
        MMI_ASSERT(0); 
    }
        
    SetKeyDownHandler(mmi_ucm_in_call_endkey, KEY_END);

	if (MMI_TRUE == mmi_ucm_is_any_disconnecting_call())
    {
        mmi_evt_mmi_ucm_disconnecting_call_exist_struct evt;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_UCM_DISCONNECTING);
        mmi_frm_post_event((mmi_event_struct *)&evt, mmi_ucm_post_event_hdlr, NULL);
    }	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_call_end_screen_delete_proc
 * DESCRIPTION
 *  This function is a leave proc for cal end screen
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_call_end_screen_delete_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_VIDEO_TELEPHONY__) && (defined(__MMI_UCM_VT_ATUO_REDIAL_VOICE__) || defined(__OP01__))    
    mmi_ucm_make_call_para_struct makecall_para;
#endif /* __MMI_VIDEO_TELEPHONY__ && (__MMI_UCM_VT_ATUO_REDIAL_VOICE__ || __OP01__) */ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:            
        {
            mmi_scenario_evt_struct *scenario_evt = (mmi_scenario_evt_struct*)evt;
            mmi_ucm_call_end_struct *call_end_p = (mmi_ucm_call_end_struct *)mmi_frm_scrn_get_user_data(scenario_evt->targ_group, scenario_evt->targ_scrn); 
        #if defined(__MMI_VIDEO_TELEPHONY__) && (defined(__MMI_UCM_VT_ATUO_REDIAL_VOICE__) || defined(__OP01__))         
            if (MMI_UCM_CALL_END_TYPE_VT_AUTO_REDIAL_ON == call_end_p->call_end_type)
            {
                /* Trigger auto redial voice */
                mmi_ucm_init_call_para(&makecall_para);
    		    makecall_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;
    		    makecall_para.ucs2_num_uri = (U16*)g_ucm_p->vt_cntx.mo_info.dial_pad_buffer;
    			makecall_para.adv_para.is_ip_dial = g_ucm_p->mo_info.is_ip_dial;
    			makecall_para.adv_para.phb_data = g_ucm_p->mo_info.phb_data;
    		    mmi_ucm_call_launch(0, &makecall_para);	
            }
        #endif /* __MMI_VIDEO_TELEPHONY__ && (__MMI_UCM_VT_ATUO_REDIAL_VOICE__ || __OP01__) */             
            /* free memory */
            OslMfree(call_end_p->disp_msg);
            OslMfree(call_end_p);

        #ifdef __OP01_FWPBW__
            if (SRV_UCM_END_ALL_AND_DIAL_ACT != srv_ucm_query_curr_action())
            {
                mmi_evt_mmi_ucm_disconnecting_call_exist_struct evt;
                MMI_FRM_INIT_EVENT(&evt, EVT_ID_UCM_FWPCP_LAUCH_DIALER);
                mmi_frm_post_event((mmi_event_struct *)&evt, mmi_ucm_post_event_hdlr, NULL);
            }
        #endif /* __OP01_FWPBW__ */
        }
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_call_end
 * DESCRIPTION
 *  Enter call end popup screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_call_end(mmi_ucm_call_end_struct *call_end_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_CALL_END, SCR_ID_UCM_CALL_END, 
        (FuncPtr)mmi_ucm_entry_call_end, 
        (void*)call_end_p);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_call_end
 * DESCRIPTION
 *  show call end popup
 * PARAMETERS
 *   call_end:          [IN]    call end info structure
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_call_end(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 MessageString[MMI_UCM_END_TEXT_LEN];
    U8 newline[4] = { '\n', '\0', '\0', '\0' }; /* \n */
    CHAR TimeString[32];
    S32 str_len = 0;
    U16 img_id = 0;
    U16 tone_id = 0;
    mmi_ucm_call_end_struct *call_end_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_CALL_END,
                    (FuncPtr)mmi_ucm_exit_call_end,
                    (FuncPtr)mmi_ucm_entry_call_end,
                    MMI_FRM_FG_ONLY_SCRN))
    {
        return;
    }
    

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_CALL_END);

    mmi_frm_start_scenario(MMI_SCENARIO_ID_DEFAULT);

    call_end_p = (mmi_ucm_call_end_struct*)mmi_frm_scrn_get_user_data(scr_info->group_id, SCR_ID_UCM_CALL_END);

    img_id = call_end_p->image_id;
    tone_id = call_end_p->tone_id;

    mmi_ucs2ncpy((CHAR*)MessageString, (CHAR*)call_end_p->disp_msg, MMI_UCM_END_TEXT_LEN);
    
    if (tone_id == TONE_BUSY_CALL_GSM)
    {
        srv_prof_play_tone_with_id(
        SRV_PROF_TONE_GSM_BUSY, 
        TONE_BUSY_CALL_GSM,
        SRV_PROF_RING_TYPE_REPEAT,
        NULL);

    }
    else if (tone_id != 0)
    {
        srv_prof_play_tone((srv_prof_tone_enum)tone_id, NULL);      
    }
    
    if ((call_end_p->call_duration.nDay + 
        call_end_p->call_duration.nHour +  
        call_end_p->call_duration.nMin + 
        call_end_p->call_duration.nSec) != 0)
    {
        duration_string(
            (UI_time*) & (call_end_p->call_duration),
            (UI_string_type) TimeString,
            DT_ACTIVE_CALL_SCREEN);

        str_len = mmi_ucs2strlen((CHAR*)MessageString);

        if ((MMI_UCM_END_TEXT_LEN - str_len) > mmi_ucs2strlen((CHAR*)newline))
        {
            mmi_ucs2ncat((CHAR*)MessageString, (CHAR*)newline, (MMI_UCM_END_TEXT_LEN - str_len));
        }
        str_len = mmi_ucs2strlen((CHAR*)MessageString);

        if ((MMI_UCM_END_TEXT_LEN - str_len) > mmi_ucs2strlen((CHAR*)TimeString))
        {
            mmi_ucs2ncat((CHAR*)MessageString, (CHAR*)TimeString, (MMI_UCM_END_TEXT_LEN - str_len));
        }
    }

#if defined(__OP01__) && !defined(__OP01_FWPBW__)
    if ((call_end_p->start_time.nDay +
         call_end_p->start_time.nHour +
         call_end_p->start_time.nMin +
         call_end_p->start_time.nSec) != 0)
    {
        time_string(
            (UI_time*) & (call_end_p->start_time),
            (UI_string_type) TimeString,
            DT_ACTIVE_CALL_SCREEN);

        str_len = mmi_ucs2strlen((CHAR*)MessageString);

        if ((MMI_UCM_END_TEXT_LEN - str_len) > mmi_ucs2strlen((CHAR*)newline))
        {
            mmi_ucs2ncat((CHAR*) MessageString, (CHAR*)newline, (MMI_UCM_END_TEXT_LEN - str_len));
        }
        str_len = mmi_ucs2strlen((CHAR*)MessageString);

        if ((MMI_UCM_END_TEXT_LEN - str_len) > mmi_ucs2strlen((CHAR*)TimeString))
        {
            mmi_ucs2ncat((CHAR*)MessageString, (CHAR*)TimeString, (MMI_UCM_END_TEXT_LEN - str_len));
        }
    }
#endif /* defined(__OP01__) && !defined(__OP01_FWPBW__) */

#ifdef __MMI_UCM_DISPLAY_NAME_ON_CALL_END__
    ShowCategory63Screen((U8*) MessageString, 0, NULL);
#else /* __MMI_UCM_DISPLAY_NAME_ON_CALL_END__ */
    ShowCategory63Screen((U8*) MessageString, img_id, NULL);
#endif /* __MMI_UCM_DISPLAY_NAME_ON_CALL_END__ */

#ifdef __PXS_APP_ENABLE__
    if (MMI_TRUE == g_ucm_p->pxs_need_handle)
    {
    }
    else
#endif /* __PXS_APP_ENABLE__ */
    {
        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    }

    SetGroupKeyHandler(mmi_frm_scrn_close_active_id, (PU16) PresentAllKeys, TOTAL_KEYS, KEY_EVENT_DOWN);
#ifdef __MMI_TOUCH_SCREEN__
    wgui_cat63_register_pen_down_handler(mmi_ucm_call_end_pen_down_handler);
#endif /* __MMI_TOUCH_SCREEN__ */
    /* need use leave proc to free memory */
    mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_CALL_END, SCR_ID_UCM_CALL_END, (mmi_proc_func) mmi_ucm_call_end_screen_delete_proc); 
    
    StartTimer(UCM_NOTIFY_DURATION_TIMER, MMI_UCM_NOTIFY_TIMEOUT, mmi_ucm_call_end_timeout_handler);
}


#ifndef __MMI_UCM_SLIM__
#if defined(__MMI_VOIP__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_voip_dialer_screen
 * DESCRIPTION
 *  enter voip dialer screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_voip_dialer_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_INCALL, SCR_ID_UCM_VOIP_DIALER, 
        (FuncPtr)mmi_ucm_entry_voip_dialer_screen, 
        (void*)NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_voip_dialer_screen
 * DESCRIPTION
 *  voip dialer screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_voip_dialer_screen(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_VOIP_DIALER,
                    NULL,
                    (FuncPtr)mmi_ucm_entry_voip_dialer_screen,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    
    guiBuffer = mmi_frm_scrn_get_gui_buf(scr_info->group_id, SCR_ID_UCM_VOIP_DIALER);

#if (!defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__))
    EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);
#endif /*!defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)) */ 

    mmi_imm_set_characters(MMI_TRUE, mmi_imm_get_allowed_voip_number_characters());

    ShowCategory404Screen(
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        IMG_ID_VOIP_CALL_EDITOR,
        (U8*)g_ucm_p->mo_info.dial_pad_buffer,
        SRV_UCM_MAX_NUM_URI_LEN,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_ucm_enter_dialer_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    
    SetKeyDownHandler(mmi_ucm_make_voip_call_from_incall_dialer, KEY_SEND);
    SetKeyDownHandler(mmi_ucm_in_call_endkey, KEY_END);

#if (!defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__))
    SetCenterSoftkeyFunction(mmi_ucm_make_voip_call_from_incall_dialer, KEY_EVENT_UP);
#endif /*  !defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)) */ 

	if (MMI_TRUE == mmi_ucm_is_any_disconnecting_call())
    {
        mmi_evt_mmi_ucm_disconnecting_call_exist_struct evt;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_UCM_DISCONNECTING);
        mmi_frm_post_event((mmi_event_struct *)&evt, mmi_ucm_post_event_hdlr, NULL);
    }
}
#endif /* __MMI_VOIP__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_voice_dialer_screen
 * DESCRIPTION
 *  enter voice dialer screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_voice_dialer_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_INCALL, SCR_ID_UCM_VOICE_DIALER, 
        (FuncPtr)mmi_ucm_entry_voice_dialer_screen, 
        (void*)NULL);

}



/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_voice_dialer_screen
 * DESCRIPTION
 *  voice dialer screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_voice_dialer_screen(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_VOICE_DIALER,
                    NULL,
                    (FuncPtr)mmi_ucm_entry_voice_dialer_screen,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_gui_buf(scr_info->group_id, SCR_ID_UCM_VOICE_DIALER);
    

#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)

#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
    mmi_ucm_set_dynamic_sim_kepad_hdlr();
#else /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */
#if (MMI_MAX_SIM_NUM == 2)
    if (MMI_TRUE == srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE))
    {
        SetDialingKeypadCallHandler(mmi_ucm_make_voice_call_from_incall_dialer_sim1);
    }

    if (MMI_TRUE == srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE_SIM2))
    {
        SetDialingKeypadCall2Handler(mmi_ucm_make_voice_call_from_incall_dialer_sim2);
    }
#else /* (MMI_MAX_SIM_NUM == 2) */
    if (MMI_TRUE == srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE_ALL))
    {
		SetDialingKeypadCallHandler(mmi_ucm_make_voice_call_from_incall_dialer_icon);
	}
    
#endif /* (MMI_MAX_SIM_NUM == 2) */
#endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */

#ifdef __MMI_VIDEO_TELEPHONY__
    if (MMI_TRUE == srv_ucm_is_call_srv_available(SRV_UCM_VIDEO_CALL_TYPE_ALL))
    {
        SetDialingKeypadVideoHandler(mmi_ucm_make_video_call_from_incall_dialer_icon);
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */
    if (SRV_UCM_RESULT_OK == mmi_ucm_enter_general_app_option(MMI_UCM_PERMIT_ONLY))
    {
        SetDialingKeypadPhonebookHandler(mmi_ucm_launch_phb_app);
    }
    else
    {
        SetDialingKeypadPhonebookHandler(NULL);
    }
#endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */ 
    EnableCenterSoftkey(0, IMG_CSK_DIAL_ICON);


    ShowCategory16Screen(
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*)g_ucm_p->mo_info.dial_pad_buffer,
        (MMI_UCM_DTMF_LEN + 1),
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_ucm_enter_dialer_option, KEY_EVENT_UP);
    SetCategory16RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP); 


    mmi_ucm_handle_sendkeys_for_call(mmi_ucm_make_voice_call_from_incall_dialer_for_sendkey,KEY_EVENT_DOWN);  

    SetKeyDownHandler(mmi_ucm_in_call_endkey, KEY_END);

	SetCenterSoftkeyFunction(mmi_ucm_make_voice_call_from_incall_dialer_icon, KEY_EVENT_UP);

	if (MMI_TRUE == mmi_ucm_is_any_disconnecting_call())
    {
        mmi_evt_mmi_ucm_disconnecting_call_exist_struct evt;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_UCM_DISCONNECTING);
        mmi_frm_post_event((mmi_event_struct *)&evt, mmi_ucm_post_event_hdlr, NULL);
    }	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_dialer_option
 * DESCRIPTION
 *  enter dialer option scrn during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_dialer_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* create menu cui */
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_DIALER_OPT);
    /* mmi_ucm_incall_opt_proc */
    g_ucm_p->cui_info.new_call_dialer_opt_cui_id = cui_menu_create_and_run(
                             GRP_ID_UCM_INCALL, 
                             CUI_MENU_SRC_TYPE_RESOURCE, 
                             CUI_MENU_TYPE_OPTION, 
                             MENU_ID_UCM_NEW_CALL_OPTION, 
                             MMI_FALSE, /* Use global resource */
                             NULL);
     
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_handle_new_call_dialer_option
 * DESCRIPTION
 *  Sample code
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_handle_new_call_dialer_option(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VOIP__
    if (mmi_frm_scrn_is_present(GRP_ID_UCM_INCALL, SCR_ID_UCM_VOIP_DIALER, MMI_FRM_NODE_ALL_FLAG))
    {
        cui_menu_set_group_hidden(owner_gid, MENU_GROUP_EDITOR, MMI_FALSE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_DIAL, MMI_FALSE);
    #if (MMI_MAX_SIM_NUM == 2)
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_DIAL_SIM1, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_DIAL_SIM2, MMI_TRUE);
    #endif /* (MMI_MAX_SIM_NUM == 2) */
    }
    else
#endif /* __MMI_VOIP__ */
    {
        cui_menu_set_group_hidden(owner_gid, MENU_GROUP_EDITOR, MMI_TRUE);
    #if (MMI_MAX_SIM_NUM == 2)
    #ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_DIAL, MMI_FALSE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_DIAL_SIM1, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_DIAL_SIM2, MMI_TRUE);
    #else /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_DIAL, MMI_TRUE);

        if (MMI_TRUE == srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE))
        {
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_DIAL_SIM1, MMI_FALSE);
        }
		else
		{
		    cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_DIAL_SIM1, MMI_TRUE);
		}

        if (MMI_TRUE == srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE_SIM2))
        {
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_DIAL_SIM2, MMI_FALSE);
        }
		else
		{
		    cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_DIAL_SIM2, MMI_TRUE);		
		}
    #endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
    #else /* (MMI_MAX_SIM_NUM == 2) */
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_DIAL, MMI_FALSE);
    #endif /* (MMI_MAX_SIM_NUM == 2) */
    }

    if (SRV_UCM_RESULT_OK == mmi_ucm_enter_general_app_option(MMI_UCM_PERMIT_ONLY))
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_SAVE, MMI_FALSE);
    }
	else
    {
		cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_SAVE, MMI_TRUE);
	}

#ifndef __MMI_UCM_PLUTO_BW__
    if (MMI_FALSE == mmi_ucm_if_number_exists())
    {
    #if (MMI_MAX_SIM_NUM == 2) && !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
        cui_menu_set_item_disabled(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_DIAL_SIM1, MMI_TRUE);    
        cui_menu_set_item_disabled(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_DIAL_SIM2, MMI_TRUE);
    #else /* (MMI_MAX_SIM_NUM == 2) && !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */
        cui_menu_set_item_disabled(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_DIAL, MMI_TRUE);
    #endif /* (MMI_MAX_SIM_NUM == 2) && !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */
        cui_menu_set_item_disabled(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_SAVE, MMI_TRUE);
    }
    else
    {
    #if (MMI_MAX_SIM_NUM == 2) && !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
        cui_menu_set_item_disabled(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_DIAL_SIM1, MMI_FALSE);    
        cui_menu_set_item_disabled(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_DIAL_SIM2, MMI_FALSE);
    #else /* (MMI_MAX_SIM_NUM == 2) && !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */
        cui_menu_set_item_disabled(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_DIAL, MMI_FALSE);
    #endif /* (MMI_MAX_SIM_NUM == 2) && !defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */
        cui_menu_set_item_disabled(owner_gid, MENU_ID_UCM_NEW_CALL_OPTION_SAVE, MMI_FALSE);
    }
#endif /*__MMI_UCM_PLUTO_BW__*/
}
#endif /* __MMI_UCM_SLIM__ */


#ifdef __MMI_UCM_TRANSFER__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_transfer
 * DESCRIPTION
 *  enter call transfer screen in call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_transfer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_INCALL, SCR_ID_UCM_TRANSFER, 
        (FuncPtr)mmi_ucm_entry_transfer, 
        (void*)NULL);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_transfer
 * DESCRIPTION
 *  Transfer screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_transfer(mmi_scrn_essential_struct* scr_info)
{
#ifdef __MMI_VOIP__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 *inputStr = NULL;
    srv_ucm_call_type_enum call_type = 0;
	srv_ucm_group_info_struct group_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_TRANSFER,
                    NULL,
                    (FuncPtr)mmi_ucm_entry_transfer,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_gui_buf(scr_info->group_id, SCR_ID_UCM_TRANSFER);
    inputStr = (U8*)mmi_frm_scrn_get_input_buf(scr_info->group_id, SCR_ID_UCM_TRANSFER);

	srv_ucm_query_group_data(g_ucm_p->call_misc.hilite_tab, &group_info);
    call_type = group_info.call_type;

    if (call_type == SRV_UCM_VOIP_CALL_TYPE)
    {
        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

        mmi_imm_set_characters(MMI_TRUE, mmi_imm_get_allowed_voip_number_characters());
        ShowCategory404Screen(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            IMG_ID_VOIP_CALL_EDITOR,
            (U8*)g_ucm_p->mo_info.dial_pad_buffer,
            SRV_UCM_MAX_NUM_URI_LEN,
            guiBuffer);
    }
    else
    {
        MMI_ASSERT(0);
    }
    
    SetLeftSoftkeyFunction(mmi_ucm_transfer, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

    SetCenterSoftkeyFunction(mmi_ucm_transfer, KEY_EVENT_UP);

    SetKeyDownHandler(mmi_ucm_transfer, KEY_SEND);
    SetKeyDownHandler(mmi_ucm_in_call_endkey, KEY_END);

	if (MMI_TRUE == mmi_ucm_is_any_disconnecting_call())
    {
        mmi_evt_mmi_ucm_disconnecting_call_exist_struct evt;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_UCM_DISCONNECTING);
        mmi_frm_post_event((mmi_event_struct *)&evt, mmi_ucm_post_event_hdlr, NULL);
    }	
#endif /* __MMI_VOIP__ */
}
#endif /* __MMI_UCM_TRANSFER__ */


#ifdef __MMI_UCM_DEFLECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_deflect
 * DESCRIPTION
 *  enter deflect scrn
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_deflect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_MT, SCR_ID_UCM_DEFLECT, 
        (FuncPtr)mmi_ucm_entry_deflect, 
        (void*)NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_call_deflect_delete_proc
 * DESCRIPTION
 *  This function is a leave proc for call deflect screen
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_call_deflect_delete_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:            
        {
            /* need to delete the phb CUI scrns triggered by deflect */
            if (GRP_ID_INVALID !=g_ucm_p->cui_info.select_contact_cui_id)
            {
                cui_phb_list_select_contact_close(g_ucm_p->cui_info.select_contact_cui_id);
                g_ucm_p->cui_info.select_contact_cui_id = GRP_ID_INVALID;
            }
        }
        break;
    }
    return MMI_RET_OK;
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_deflect
 * DESCRIPTION
 *  Deflect screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_deflect(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
#ifdef __MMI_VOIP__
    S32 index = 0;
    srv_ucm_call_type_enum call_type = (srv_ucm_call_type_enum)0;
    srv_ucm_group_info_struct group_info;
#endif /* __MMI_VOIP__ */  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_is_redrawing_bk_screens() == TRUE)
    {
        return;
    }

    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_DEFLECT,
                    NULL,
                    (FuncPtr)mmi_ucm_entry_deflect,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    
    guiBuffer = mmi_frm_scrn_get_gui_buf(scr_info->group_id, SCR_ID_UCM_DEFLECT);    

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
 
#ifdef __MMI_VOIP__      
    index = mmi_ucm_get_group_index_by_call_state_and_type(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL);
    MMI_ASSERT(index >= 0);
    
    srv_ucm_query_group_data(index, &group_info);    
  
    call_type = group_info.call_type;

    if (call_type == SRV_UCM_VOIP_CALL_TYPE)
    {
        ShowCategory404Screen(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            IMG_ID_VOIP_CALL_EDITOR,
            (U8*)g_ucm_p->mo_info.dial_pad_buffer,
            SRV_UCM_MAX_NUM_URI_LEN,
            guiBuffer);
    }
    else
#endif /* __MMI_VOIP__ */        
    {

    #if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)

    #if (MMI_MAX_SIM_NUM == 2)
    #if !(defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__))
        if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_SIM2_CALL_TYPE_ALL, NULL) > 0)
        {
            SetDialingKeypadCall2Handler(mmi_ucm_deflect_from_icon);
        }
        else
    #endif /* !(defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)) */
    #endif /* (MMI_MAX_SIM_NUM == 2) */
        {
            SetDialingKeypadCallHandler(mmi_ucm_deflect_from_icon);
        }

        if (SRV_UCM_RESULT_OK == mmi_ucm_enter_general_app_option(MMI_UCM_PERMIT_ONLY))
        {
            SetDialingKeypadPhonebookHandler(mmi_ucm_select_number_for_deflect);
        }
        else
        {
            SetDialingKeypadPhonebookHandler(NULL);
        }
    #endif /* defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__) */
                
        ShowCategory16Screen(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (U8*)g_ucm_p->mo_info.dial_pad_buffer,
            (MMI_UCM_DTMF_LEN + 1),
            guiBuffer);

    }
    
    SetLeftSoftkeyFunction(mmi_ucm_deflect, KEY_EVENT_UP);
    SetCategory16RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP); 
    SetCenterSoftkeyFunction(mmi_ucm_deflect, KEY_EVENT_UP);

    SetKeyDownHandler(mmi_ucm_deflect, KEY_SEND);
    SetKeyDownHandler(mmi_ucm_incoming_call_endkey, KEY_END);

    mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_MT, SCR_ID_UCM_DEFLECT, (mmi_proc_func) mmi_ucm_call_deflect_delete_proc);
	if (MMI_TRUE == mmi_ucm_is_any_disconnecting_call())
    {
        mmi_evt_mmi_ucm_disconnecting_call_exist_struct evt;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_UCM_DISCONNECTING);
        mmi_frm_post_event((mmi_event_struct *)&evt, mmi_ucm_post_event_hdlr, NULL);
    }
}
#endif /* __MMI_UCM_DEFLECT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_confirm
 * DESCRIPTION
 *  Enter query confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_CONFIRM);
    mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE); 
	arg.softkey[0].str = (WCHAR *)((UI_string_type)GetString(STR_GLOBAL_YES));	
    arg.softkey[1].img = (PS8)GetImage(IMG_GLOBAL_COMMON_CSK);
    arg.softkey[2].str = (WCHAR *)((UI_string_type)GetString(STR_GLOBAL_NO));
  
    arg.user_tag = (void *)MMI_UCM_CNF_QUERY_IND;
    arg.f_enter_history = MMI_TRUE;
    arg.parent_id = GRP_ID_UCM_CONFIRM;
    arg.callback = (mmi_proc_func)mmi_ucm_cnf_popup_cb;
    g_ucm_p->cnf_scr.scrn_id = mmi_confirm_display((WCHAR *) g_ucm_p->cnf_scr.content, MMI_EVENT_QUERY, &arg);
   
#ifdef __SENDKEY2_SUPPORT__
    SetKeyDownHandler(mmi_ucm_confirm_hdlr_sendkey, KEY_SEND2);
#endif /* __SENDKEY2_SUPPORT__ */
    mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_CONFIRM, g_ucm_p->cnf_scr.scrn_id, (mmi_proc_func) mmi_ucm_confirm_screen_delete_proc);    
    SetKeyDownHandler(mmi_ucm_confirm_hdlr_sendkey, KEY_SEND); 
    SetKeyDownHandler(mmi_ucm_confirm_hdlr_endkey, KEY_END);
#ifdef __PXS_APP_ENABLE__
    if (MMI_TRUE == g_ucm_p->pxs_need_handle)
    {        
    }
    else
#endif /* __PXS_APP_ENABLE__ */
    {
        srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_close_processing_scrn
 * DESCRIPTION
 *  close processing scrn
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_close_processing_scrn(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    mmi_frm_scrn_close(GRP_ID_UCM_CONFIRM, SCR_ID_UCM_PROCESSING);
    mmi_frm_scrn_close(GRP_ID_UCM_MT, SCR_ID_UCM_PROCESSING);
    mmi_frm_scrn_close(GRP_ID_UCM_MO, SCR_ID_UCM_PROCESSING);
#if defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
    mmi_frm_scrn_close(GRP_ID_UCM_INT_MARKER, SCR_ID_UCM_PROCESSING);
#endif /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */
    mmi_frm_scrn_close(GRP_ID_UCM_INCALL, SCR_ID_UCM_PROCESSING);
#ifdef __MMI_VIDEO_TELEPHONY__
    mmi_frm_scrn_close(GRP_ID_UCM_VT, SCR_ID_UCM_PROCESSING);
#endif /* __MMI_VIDEO_TELEPHONY__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_incoming_call
 * DESCRIPTION
 *  Enter incoming call scrn
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_processing_screen_internal(MMI_ID SG_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*  it is a limitation in FW to handle anti-blinking + hardware blt screen, 
        therefore need to add dummy screen here to prevent screen flash 
        ex. hold and accept, the MT screen disable blt because of caller video */
    if (SCR_ID_UCM_PROCESSING == mmi_frm_scrn_get_active_id())
    {
        mmi_frm_display_dummy_screen_ex(mmi_frm_group_get_active_id(), SCR_ID_UCM_DUMMY);
    }

    mmi_ucm_close_processing_scrn(); /* delete old processing screen if exists */
    
    mmi_frm_scrn_first_enter(
        SG_id, SCR_ID_UCM_PROCESSING, 
        (FuncPtr)mmi_ucm_entry_processing_screen_internal, 
        (void*)NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_processing_screen_internal
 * DESCRIPTION
 *  General entry function of processing screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_processing_screen_internal(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *body_string_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_PROCESSING,
                    NULL,
                    (FuncPtr)mmi_ucm_entry_processing_screen_internal,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_PROCESSING_SCREEN);
    
    if (g_ucm_p->proc_scr.body_string_pointer != NULL)
    {
        body_string_p = g_ucm_p->proc_scr.body_string_pointer;
    }
    else
    {
        body_string_p = (U8*) GetString(g_ucm_p->proc_scr.body_string);
    }
    
    ShowCategory66Screen(
        g_ucm_p->proc_scr.title_string,
        0,
        g_ucm_p->proc_scr.lsk_string,
        0,
        g_ucm_p->proc_scr.rsk_string,
        0,
        body_string_p,
        g_ucm_p->proc_scr.animation_image,
        NULL);
    
    SetLeftSoftkeyFunction(g_ucm_p->proc_scr.lsk_funcPtr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(g_ucm_p->proc_scr.rsk_funcPtr, KEY_EVENT_UP);

    SetKeyDownHandler(g_ucm_p->proc_scr.send_funcPtr, KEY_SEND);
    SetKeyDownHandler(g_ucm_p->proc_scr.end_funcPtr, KEY_END);
    mmi_frm_scrn_set_leave_proc(scr_info->group_id, SCR_ID_UCM_PROCESSING, (mmi_proc_func) mmi_ucm_processing_screen_delete_proc); 
    
}

#ifdef __MMI_CALLSET_AUTO_REDIAL__

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_auto_redial
 * DESCRIPTION
 *  Enter auto redial screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_auto_redial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_AUTO_REDIAL, SCR_ID_UCM_AUTO_REDIAL, 
        (FuncPtr)mmi_ucm_entry_auto_redial, 
        (void*)NULL);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_auto_redial
 * DESCRIPTION
 *  Auto redial entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_auto_redial(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_AUTO_REDIAL,
                    NULL,
                    (FuncPtr)mmi_ucm_entry_auto_redial,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_AUTO_REDIAL);

    //ShowCategory141Screen(0, 0, 0, 0, STR_GLOBAL_ABORT, 0, (U8*)g_ucm_p->auto_redial.display_msg, 0, NULL);
	ShowCategory74Screen(0,0,0,0,STR_GLOBAL_ABORT,0,(U8*)g_ucm_p->auto_redial.display_msg, SRV_UCM_MAX_AUTO_REDIAL_MSG_LEN, NULL);

    SetRightSoftkeyFunction(mmi_ucm_auto_redial_abort, KEY_EVENT_UP);
    SetKeyDownHandler(mmi_ucm_auto_redial_abort, KEY_END);

    mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_AUTO_REDIAL, SCR_ID_UCM_AUTO_REDIAL, (mmi_proc_func) mmi_ucm_auto_redial_screen_delete_proc);    
}

#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_call_type
 * DESCRIPTION
 *  enter call type selection screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_call_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_PRE_MO, SCR_ID_UCM_DIAL_CALL_TYPE_MENU, 
        (FuncPtr)mmi_ucm_entry_call_type, 
        (void*)NULL);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_call_type
 * DESCRIPTION
 *  Shows the call type selection screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_call_type(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U16 numItems = 0;
    U16 nStrItemList[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_DIAL_CALL_TYPE_MENU,
                    NULL,
                    (FuncPtr)mmi_ucm_entry_call_type,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_CALL_TYPE);

    guiBuffer = mmi_frm_scrn_get_gui_buf(scr_info->group_id, SCR_ID_UCM_DIAL_CALL_TYPE_MENU);

    numItems = GetNumOfChild_Ext(MENU_ID_UCM_CALL_TYPE);
    GetSequenceStringIds_Ext(MENU_ID_UCM_CALL_TYPE, nStrItemList);

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    mmi_ucm_get_call_type_string((U8 **)subMenuDataPtrs, nStrItemList, numItems);
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

    SetParentHandler(MENU_ID_UCM_CALL_TYPE);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    /* when choose a  number shortcut in the list menu, access the menu directly */
    wgui_list_menu_enable_access_by_shortcut();

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    ShowCategory53Screen(
        STR_GLOBAL_DIAL,
        GetRootTitleIcon(MAIN_MENU_CALL_LOG),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        (U8**) subMenuDataPtrs,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
#else /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
    ShowCategory52Screen(
        STR_GLOBAL_DIAL,
        GetRootTitleIcon(MAIN_MENU_CALL_LOG),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        numItems,
        nStrItemList,
        (U16*) gIndexIconsImageList,
        NULL,
        0,
        0,
        guiBuffer);
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

    mmi_frm_scrn_set_leave_proc(scr_info->group_id, SCR_ID_UCM_DIAL_CALL_TYPE_MENU, (mmi_proc_func)mmi_ucm_call_type_select_delete_proc);
    SetRightSoftkeyFunction(mmi_ucm_cancel_call_type_select, KEY_EVENT_UP);
	if (MMI_TRUE == mmi_ucm_is_any_disconnecting_call())
    {
        mmi_evt_mmi_ucm_disconnecting_call_exist_struct evt;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_UCM_DISCONNECTING);
        mmi_frm_post_event((mmi_event_struct *)&evt, mmi_ucm_post_event_hdlr, NULL);
    }
}


#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_call_type_string
 * DESCRIPTION
 *  Get the call type string, add SIM name if needed.
 * PARAMETERS
 *  string_list_ptr                 [OUT] string list pointer
 *  string_list                     [IN] string list
 *  num                             [IN] the number of the string list items
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_get_call_type_string(U8 **string_list_ptr, U16 *string_list, U16 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U8 index = 0;
    U8 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == string_list_ptr ||  NULL == string_list)
    {
        return;
    }

    for (i = 0; i < num; i++)
    {
        if (
        #if (MMI_MAX_SIM_NUM >= 2)
            STR_ID_UCM_SIM1_VOICE_CALL == string_list[i] ||
            STR_ID_UCM_SIM2_VOICE_CALL == string_list[i] ||
        #if (MMI_MAX_SIM_NUM >= 3)
            STR_ID_UCM_SIM3_VOICE_CALL == string_list[i] ||
        #if (MMI_MAX_SIM_NUM >= 4)
            STR_ID_UCM_SIM4_VOICE_CALL == string_list[i] ||
        #endif /* (MMI_MAX_SIM_NUM >= 4) */
        #endif /* (MMI_MAX_SIM_NUM >= 3) */
        #endif /* (MMI_MAX_SIM_NUM >= 2) */
            MMI_FALSE)
        {
            count++;
            index = i;
            string_list_ptr[i] = subMenuData[i];
            mmi_ucm_add_sim_name_for_call_type(string_list_ptr[i], string_list[i]);
        }
        else
        {
        	string_list_ptr[i] = subMenuData[i];
            mmi_ucs2cpy((CHAR *)string_list_ptr[i], (const CHAR *)GetString(string_list[i]));
        }
    }

    if (1 == count && mmi_ucm_one_sim_behavior_is_needed())
    {
        mmi_ucs2cpy((CHAR *)string_list_ptr[index], (const CHAR *)GetString(STR_ID_UCM_VOICE_CALL));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_add_sim_name_for_call_type
 * DESCRIPTION
 *  Add sim name in the tail of the call type string
 * PARAMETERS
 *  string_ptr                 [OUT] string pointer
 *  string_id                  [IN] string id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_add_sim_name_for_call_type(U8 *string_ptr, U16 string_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_sim_enum sim_id = MMI_SIM1;
    WCHAR *sim_name;
    U16 string_table[] = {
    #if (MMI_MAX_SIM_NUM >= 2)
        STR_ID_UCM_SIM1_VOICE_CALL,
        STR_ID_UCM_SIM2_VOICE_CALL,
    #if (MMI_MAX_SIM_NUM >= 3)
        STR_ID_UCM_SIM3_VOICE_CALL,
    #if (MMI_MAX_SIM_NUM >= 4)
        STR_ID_UCM_SIM4_VOICE_CALL,
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        if (string_id == string_table[i])
        {
            sim_id = MMI_SIM1 << i;
            break;
        }
    }

    sim_name = mmi_netset_get_sim_name(sim_id);
    if (sim_name)
    {
        kal_wsprintf((WCHAR *)string_ptr, "%w(%w)", GetString(string_id), sim_name);
    }
    else
    {
        mmi_ucs2cpy((CHAR *)string_ptr, (const CHAR *)GetString(string_id));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_add_sim_name_for_sim_select
 * DESCRIPTION
 *  Set menu item string with SIM name
 * PARAMETERS
 *  owner_gid       [IN]    Menu GID from cui_menu_create
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_add_sim_name_for_sim_select(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_sim_enum sim_id;
    WCHAR *sim_name;
	WCHAR menu_str[MAX_SUBMENU_CHARACTERS];
    U16 string_table[] = {
    #if (MMI_MAX_SIM_NUM >= 2)
        STR_ID_UCM_FROM_SIM1,
        STR_ID_UCM_FROM_SIM2,
    #if (MMI_MAX_SIM_NUM >= 3)
        STR_ID_UCM_FROM_SIM3,
    #if (MMI_MAX_SIM_NUM >= 4)
        STR_ID_UCM_FROM_SIM4,
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        sim_name = mmi_netset_get_sim_name(sim_id);
        if (sim_name)
        {
            kal_wsprintf(menu_str, "%w(%w)", GetString(string_table[i]), mmi_netset_get_sim_name(sim_id));
            cui_menu_set_item_string(owner_gid, MENU_ID_UCM_FROM_SIM1 + i, menu_str);
            //cui_menu_set_item_image(owner_gid, MENU_ID_UCM_FROM_SIM1 + i, 0);
        }
    }
}

#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */


#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
#ifdef __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_dynamic_sim_kepad_hdlr
 * DESCRIPTION
 *  Set Dialer keypad handler for dynamic sim
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_dynamic_sim_kepad_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U8 count = 0;
    MMI_BOOL ecc_call = MMI_FALSE;
    U8 index = 0;
    void (*handler1[])(void) = {
    #if (MMI_MAX_SIM_NUM >= 2)
        mmi_ucm_make_voice_call_from_dtmf_editor_sim1,
        mmi_ucm_make_voice_call_from_dtmf_editor_sim2,
    #if (MMI_MAX_SIM_NUM >= 3)
        mmi_ucm_make_voice_call_from_dtmf_editor_sim3,
    #if (MMI_MAX_SIM_NUM >= 4)
        mmi_ucm_make_voice_call_from_dtmf_editor_sim4,
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        };

#ifndef __MMI_UCM_SLIM__
    void (*handler2[])(void) = {
    #if (MMI_MAX_SIM_NUM >= 2)
        mmi_ucm_make_voice_call_from_incall_dialer_sim1,
        mmi_ucm_make_voice_call_from_incall_dialer_sim2,
    #if (MMI_MAX_SIM_NUM >= 3)
        mmi_ucm_make_voice_call_from_incall_dialer_sim3,
    #if (MMI_MAX_SIM_NUM >= 4)
        mmi_ucm_make_voice_call_from_incall_dialer_sim4,
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        };
#endif /* __MMI_UCM_SLIM__ */
    mmi_id scr_id = mmi_frm_scrn_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (0 == srv_sim_ctrl_get_num_of_inserted())
    {
        ecc_call = MMI_TRUE;
        SetDialingKeypadEmergencyFunckey(MMI_TRUE);
    }
    else
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */
    {
        for (i = 0; i < MMI_SIM_TOTAL; i++)
        {
            if (srv_ucm_is_call_srv_available(mmi_ucm_convert_index_to_voice_type((U8)i)))
            {
                count++;
                index = i;
            }
        }
    }

    if (SCR_ID_UCM_DTMF_EDITOR == scr_id)
    {
        if (MMI_TRUE == ecc_call || 0 == count)
        {
            SetDialingKeypadCallHandler(mmi_ucm_make_voice_call_from_dtmf_editor_icon);
        }
        else if (1 == count)
        {
            SetDialingKeypadCallHandler(handler1[index]);
        }
        else
        {
            SetDialingKeypadCallHandler(mmi_ucm_entry_sim_select);
        }
    }
#ifndef __MMI_UCM_SLIM__
    else if (SCR_ID_UCM_VOICE_DIALER == scr_id)
    {
        if (MMI_TRUE == ecc_call|| 0 == count)
        {
            SetDialingKeypadCallHandler(mmi_ucm_make_voice_call_from_incall_dialer_icon);
        }
        else if (1 == count)
        {
            SetDialingKeypadCallHandler(handler2[index]);
        }
        else
        {
            SetDialingKeypadCallHandler(mmi_ucm_entry_sim_select);
        }
    }
#endif /* __MMI_UCM_SLIM__ */
}
#endif /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_sim_select
 * DESCRIPTION
 *  Shows the sim selection screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_sim_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    mmi_id menu_id;
    mmi_id parent_gid = mmi_frm_group_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parent_gid = mmi_frm_group_get_top_parent_group_id(parent_gid);

    if (GRP_ID_UCM_MO == parent_gid ||
        GRP_ID_UCM_MT == parent_gid ||
        GRP_ID_UCM_INCALL == parent_gid)
    {
        menu_id = cui_menu_create(
                        parent_gid,
                        CUI_MENU_SRC_TYPE_RESOURCE,
                        CUI_MENU_TYPE_OPTION,
                        MENU_ID_UCM_SIM_SELECT,
                        MMI_FALSE,
                        NULL);

        cui_menu_set_default_title_string_by_id(menu_id, STR_ID_UCM_SIM_SELECT);

        for (i = 0; i < MMI_SIM_TOTAL; i++)
        {
            if (srv_ucm_is_call_srv_available(mmi_ucm_convert_index_to_voice_type((U8)i)))
            {
                cui_menu_set_item_hidden(menu_id, MENU_ID_UCM_FROM_SIM1 + i, MMI_FALSE);
            }
            else
            {
                cui_menu_set_item_hidden(menu_id, MENU_ID_UCM_FROM_SIM1 + i, MMI_TRUE);
            }
        }

        cui_menu_run(menu_id);
    }
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_dial_call_from_sim_select
 * DESCRIPTION
 *  Dial call when select one sim
 * PARAMETERS
 *  highlighted_menu_id       [IN]    highlighted menu item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_dial_call_from_sim_select(mmi_menu_id highlighted_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_call_type_enum call_type;
    mmi_id parent_gid = mmi_frm_group_get_active_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    parent_gid = mmi_frm_group_get_top_parent_group_id(parent_gid);
    call_type = mmi_ucm_convert_index_to_voice_type(highlighted_menu_id - MENU_ID_UCM_FROM_SIM1);

#ifndef __MMI_UCM_SLIM__
    if (GRP_ID_UCM_INCALL == parent_gid &&
        mmi_frm_scrn_is_present(GRP_ID_UCM_INCALL, SCR_ID_UCM_VOICE_DIALER, MMI_FRM_NODE_ALL_FLAG))
    {
        if (mmi_ucs2strlen((CHAR*)g_ucm_p->mo_info.dial_pad_buffer) > 0)
        {
            mmi_ucm_make_voice_call_from_incall_dialer(call_type);
        }
        else
        {
            mmi_ucm_display_error_popup(SRV_UCM_RESULT_EMPTY_NUMBER);
        }
    }
    else
#endif /* __MMI_UCM_SLIM__ */
    {
        if (mmi_ucs2strlen((CHAR*)g_ucm_p->call_misc.disp_dtmf) > 0)
        {
            mmi_ucm_make_voice_call_from_dtmf_editor_by_call_type(call_type);
        }
        else
        {
            mmi_ucm_display_error_popup(SRV_UCM_RESULT_EMPTY_NUMBER);
        }
    }
}
#endif /* defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_dial_option_make_call
 * DESCRIPTION
 *  Funtion is called when make call from dial option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_dial_option_make_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* num_ucs2 = NULL;
    mmi_ucm_make_call_para_struct make_call_para;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_PRE_MO, SCR_ID_UCM_DIAL_CALL_TYPE_MENU, (mmi_proc_func)NULL);
    
    num_ucs2 = OslMalloc((SRV_UCM_MAX_NUM_URI_LEN + 1)* ENCODING_LENGTH);
    memset(num_ucs2, 0, (SRV_UCM_MAX_NUM_URI_LEN + 1) * ENCODING_LENGTH);
    
    mmi_asc_n_to_ucs2((CHAR*)num_ucs2, (CHAR*)g_ucm_p->mo_info.dial_num.num_uri, SRV_UCM_MAX_NUM_URI_LEN);

    /* in this api, dial type must be single, so when trigger mmi_ucm_call_launch, must dial out or permit fail */
    mmi_ucm_init_call_para(&make_call_para);
    make_call_para.dial_type = g_ucm_p->mo_info.dial_type;  
    make_call_para.ucs2_num_uri = (U16*)num_ucs2;
    make_call_para.adv_para.is_ip_dial =  g_ucm_p->mo_info.is_ip_dial;
    make_call_para.adv_para.after_make_call_callback = g_ucm_p->mo_info.callback;
    make_call_para.adv_para.after_callback_user_data = g_ucm_p->mo_info.callback_para;
    make_call_para.adv_para.phb_data = g_ucm_p->mo_info.phb_data;
    make_call_para.adv_para.module_id = g_ucm_p->mo_info.module_id;
    mmi_ucm_call_launch(0, &make_call_para);

    OslMfree(num_ucs2);
    return;
}


 #if (MMI_MAX_SIM_NUM >= 3)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_dial_option_select_sim
 * DESCRIPTION
 *  Funtion to launch sim selector
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_dial_option_select_sim(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    MMI_ID sim_sel_gid;
    MMI_BOOL emergency = MMI_FALSE;
    mmi_sim_enum target_sim = MMI_SIM_NONE, highlight_sim = MMI_SIM_NONE, sim_id;
    srv_ucm_call_type_enum voice_call_type[] = {
        SRV_UCM_VOICE_CALL_TYPE,
        SRV_UCM_VOICE_CALL_TYPE_SIM2,
        SRV_UCM_VOICE_CALL_TYPE_SIM3,
        SRV_UCM_VOICE_CALL_TYPE_SIM4};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
    {
        if (g_ucm_p->mo_info.dial_type & voice_call_type[i])
        {
            target_sim |= sim_id;
        }

        if (g_ucm_p->mo_info.highlight_dial_type & voice_call_type[i])
        {
            highlight_sim = sim_id;
        }

        if (srv_ucm_is_emergency_number(voice_call_type[i] , (U8 *)g_ucm_p->mo_info.dial_num.num_uri) == MMI_TRUE)
        {
            /* If it is emergency number for any one of call types, set sim seletor emergency mode for all sims*/
            emergency = MMI_TRUE;
        }
    }

    sim_sel_gid = cui_sim_sel_create(GRP_ID_UCM_PRE_MO, target_sim, NULL);
    cui_sim_sel_set_highlight_sim(highlight_sim);
    cui_sim_sel_set_mode(emergency);
    cui_sim_sel_run(sim_sel_gid);
    return;
}
#endif /* (MMI_MAX_SIM_NUM >= 3) */

#ifdef __MMI_BG_SOUND_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_bgs_effect_select
 * DESCRIPTION
 *  enter bgs selection (list) scrn
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_bgs_effect_select(mmi_id parent_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTER_BGS_EFFECT_SELECT_P1, parent_sg_id);
    
    if ((parent_sg_id != GRP_ID_UCM_PRE_MO) && (parent_sg_id != GRP_ID_UCM_MT))
    {
        MMI_ASSERT(0);
    }
    
    mmi_frm_scrn_first_enter(
        parent_sg_id, SCR_ID_UCM_BGS_EFFECT_SELECT, 
        (FuncPtr)mmi_ucm_entry_bgs_effect_select, 
        (void*)NULL);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_bgs_effect_key_proc
 * DESCRIPTION
 *  key proc for end key in background sound effect selection screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_ucm_bgs_effect_key_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_PRE_KEY)
    {
    	  if (key_evt->key_code == KEY_END && key_evt->key_type == KEY_EVENT_DOWN)
    	 {
    	      mmi_ucm_bgs_effect_endkey_hdlr();
    	 }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_bgs_effect_select
 * DESCRIPTION
 *  Background sound effect selection screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_bgs_effect_select(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    S32 number_of_effect = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_BGS_EFFECT_SELECT,
                    NULL,
                    (FuncPtr)mmi_ucm_entry_bgs_effect_select,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    
    RegisterHighlightHandler(mmi_ucm_bgs_effect_highlight_hdlr);
    mmi_frm_scrn_set_key_proc(scr_info->group_id, SCR_ID_UCM_BGS_EFFECT_SELECT, mmi_ucm_bgs_effect_key_proc);


    gui_buffer = mmi_frm_scrn_get_gui_buf(scr_info->group_id, SCR_ID_UCM_BGS_EFFECT_SELECT);

    /* Fill effect list data */  /* O */ /* common UI */
    number_of_effect = (S32)mmi_bgsnd_common_mtmo_prepare_effect_list((CHAR**)subMenuDataPtrs, MAX_SUB_MENUS, MAX_SUB_MENU_SIZE);

    ShowCategory89Screen(
        STR_ID_UCM_BACKGROUND_SOUND,
        0,
        STR_GLOBAL_SELECT,
        0,
        STR_GLOBAL_BACK,
        0,
        number_of_effect,
        subMenuDataPtrs,
        NULL,
        0,
        (S32)mmi_bgsnd_common_get_mtmo_bgs_curr_effect(),
        gui_buffer);

    SetRightSoftkeyFunction(mmi_ucm_cancel_bgs_effect_select, KEY_EVENT_UP);
	if (MMI_TRUE == mmi_ucm_is_any_disconnecting_call())
    {
        mmi_evt_mmi_ucm_disconnecting_call_exist_struct evt;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_UCM_DISCONNECTING);
        mmi_frm_post_event((mmi_event_struct *)&evt, mmi_ucm_post_event_hdlr, NULL);
    }
}

#endif /*__MMI_BG_SOUND_EFFECT__*/


/* ==================================================================================== */
/* =============highlight ============================================================= */
/* ==================================================================================== */

#if (MMI_MAX_SIM_NUM >= 4)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_highlight_call_type_voice_sim4
 * DESCRIPTION
 *  Funtion is called when sim4 voice call is selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_highlight_call_type_voice_sim4(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->mo_info.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
    /* permit will be checked in call launch function */
    SetLeftSoftkeyFunction(mmi_ucm_dial_option_make_call, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_ucm_dial_option_make_call, KEY_EVENT_UP);
    SetKeyUpHandler(mmi_ucm_dial_option_make_call, KEY_SEND);
}
#endif /* (MMI_MAX_SIM_NUM >= 4) */


#if (MMI_MAX_SIM_NUM >= 3)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_highlight_call_type_voice_sim3
 * DESCRIPTION
 *  Funtion is called when sim3 voice call is selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_highlight_call_type_voice_sim3(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->mo_info.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
    /* permit will be checked in call launch function */
    SetLeftSoftkeyFunction(mmi_ucm_dial_option_make_call, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_ucm_dial_option_make_call, KEY_EVENT_UP);
    SetKeyUpHandler(mmi_ucm_dial_option_make_call, KEY_SEND);
}
#endif /* (MMI_MAX_SIM_NUM >= 3) */


#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_highlight_call_type_voice_sim2
 * DESCRIPTION
 *  Funtion is called when sim2 voice call is selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_highlight_call_type_voice_sim2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->mo_info.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
    /* permit will be checked in call launch function */
    SetLeftSoftkeyFunction(mmi_ucm_dial_option_make_call, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_ucm_dial_option_make_call, KEY_EVENT_UP);
    SetKeyUpHandler(mmi_ucm_dial_option_make_call, KEY_SEND);
}
#endif /* (MMI_MAX_SIM_NUM >= 2) */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_highlight_call_type_voice
 * DESCRIPTION
 *  Funtion is called when voice call is selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_highlight_call_type_voice(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM < 3) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    /* For single & dual sim card */
    g_ucm_p->mo_info.dial_type = SRV_UCM_VOICE_CALL_TYPE;
    SetLeftSoftkeyFunction(mmi_ucm_dial_option_make_call, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_ucm_dial_option_make_call, KEY_EVENT_UP);
    SetKeyUpHandler(mmi_ucm_dial_option_make_call, KEY_SEND);
#else /* (MMI_MAX_SIM_NUM < 3) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */
    /* For triple & quad sim card */
    if (g_ucm_p->mo_info.dial_type_count == 1)
    {
        /* The dial call type is g_ucm_p->mo_info.dial_type */
        SetLeftSoftkeyFunction(mmi_ucm_dial_option_make_call, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_ucm_dial_option_make_call, KEY_EVENT_UP);
        SetKeyUpHandler(mmi_ucm_dial_option_make_call, KEY_SEND);
    }
    else if (g_ucm_p->mo_info.dial_type_count > 1)
    {
        /* Display SIM selector according to g_ucm_p->mo_info.dial_type */
        SetLeftSoftkeyFunction(mmi_ucm_dial_option_select_sim, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_ucm_dial_option_select_sim, KEY_EVENT_UP);
        SetKeyUpHandler(mmi_ucm_dial_option_select_sim, KEY_SEND);
    }
#endif /* (MMI_MAX_SIM_NUM < 3) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_highlight_call_type_voip
 * DESCRIPTION
 *  Funtion is called when voip call is selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_highlight_call_type_voip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->mo_info.dial_type = SRV_UCM_VOIP_CALL_TYPE;
    /* permit will be checked in call launch function */
    SetLeftSoftkeyFunction(mmi_ucm_dial_option_make_call, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_ucm_dial_option_make_call, KEY_EVENT_UP);
    SetKeyUpHandler(mmi_ucm_dial_option_make_call, KEY_SEND);
    return;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_highlight_call_type_video
 * DESCRIPTION
 *  Funtion is called when video call is selected
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_highlight_call_type_video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->mo_info.dial_type = SRV_UCM_VIDEO_CALL_TYPE_ALL;
    /* permit will be checked in call launch function */
    SetLeftSoftkeyFunction(mmi_ucm_dial_option_make_call, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_ucm_dial_option_make_call, KEY_EVENT_UP);
    SetKeyUpHandler(mmi_ucm_dial_option_make_call, KEY_SEND);
    return;
}


#ifdef __MMI_BG_SOUND_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_bgs_effect_highlight_hdlr
 * DESCRIPTION
 *  This function is the highlight handler of sound effect list during call
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_bgs_effect_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BGS_EFFECT_HIGHLIGHT_HDLR, index);

    if (mmi_bgsnd_common_mtmo_set_highlight_index((U16)index) == MMI_FALSE)
    {
        MMI_ASSERT(0);
    }

    if (mmi_bgsnd_common_mtmo_check_ext_file_format() == BGSND_NO_EFFECT)
    {
    	ChangeCenterSoftkey(0, 0);
        ChangeLeftSoftkey(0, 0);
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);    
        SetKeyDownHandler(NULL, KEY_SEND);
        SetCenterSoftkeyFunction(NULL, KEY_EVENT_UP);
    }
    else
    {
    	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
        SetLeftSoftkeyFunction(mmi_ucm_bgs_effect_select, KEY_EVENT_UP);    
        SetKeyDownHandler(mmi_ucm_bgs_effect_select, KEY_SEND);
        SetCenterSoftkeyFunction(mmi_ucm_bgs_effect_select, KEY_EVENT_UP);
    }
}
#endif /* __MMI_BG_SOUND_EFFECT__ */


/* ==================================================================================== */
/* =============Misc ================================================================== */
/* ==================================================================================== */


#ifdef __MMI_UCM_MO_FAIL_POST_ACTION__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_setting_get_hilite_index
 * DESCRIPTION
 *  Get current highlight index
 * PARAMETERS
 *  nIndex      [IN]        Current highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_setting_get_hilite_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->post_action_info.curr_hilite_index= (U16)index;
}
#endif /* __MMI_UCM_MO_FAIL_POST_ACTION__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_any_disconnecting_call
 * DESCRIPTION
 *  This function is to check if there is any call in disconnecting state
 * PARAMETERS
 *  void        
 * RETURNS
 *  MMI_TRUE means disconnecting call exists.
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_any_disconnecting_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_ucm_query_disconnecting_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_check_if_sg_older
 * DESCRIPTION
 *  Check if the screen group is older than the base screen group in history
 * PARAMETERS
 *  U16 check_gid screen group to be checked
 *  U16 base_scr_gid base screen group
 * RETURNS
 *  True means the check_gid is older than the base screen group in history.
 *  False means the check_gid is newer, it is not in history, or base_scr group is not in history
 *****************************************************************************/
MMI_BOOL mmi_ucm_check_if_sg_older(MMI_ID check_gid, MMI_ID base_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_group_is_present(check_gid) || !mmi_frm_group_is_present(base_gid))
    {
        return MMI_FALSE;
    }

    if (mmi_frm_node_query_sequence(GRP_ID_ROOT, base_gid, check_gid) < 0)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_key_after_suppress_ring
 * DESCRIPTION
 *  Set key handlers after the incoming ring tone is suppressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_key_after_suppress_ring(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SIDEKEY_SUPPRESS_RING__
    SetKeyUpHandler(MMI_dummy_function, KEY_VOL_UP);
    SetKeyLongpressHandler(MMI_dummy_function, KEY_VOL_UP);
    SetKeyRepeatHandler(MMI_dummy_function, KEY_VOL_UP);
    SetKeyUpHandler(MMI_dummy_function, KEY_VOL_DOWN);
    SetKeyLongpressHandler(MMI_dummy_function, KEY_VOL_DOWN);
    SetKeyRepeatHandler(MMI_dummy_function, KEY_VOL_DOWN);
    
#ifdef __MMI_CLAMSHELL__
    SetKeyDownHandler(mmi_ucm_incoming_call_sendkey, KEY_VOL_UP);
    SetKeyDownHandler(mmi_ucm_incoming_call_endkey, KEY_VOL_DOWN);
#else /* __MMI_CLAMSHELL__ */
    SetKeyDownHandler(MMI_dummy_function, KEY_VOL_UP);
    SetKeyDownHandler(MMI_dummy_function, KEY_VOL_DOWN);
#endif /* __MMI_CLAMSHELL__ */
#ifdef  __MMI_FTE_SUPPORT__
    /* update scrn */                 
    if (MMI_TRUE ==g_ucm_p->call_misc.is_ringtone_suppress
		&& MMI_UCM_LOCK_STATE != mmi_ucm_get_auto_lock_state())
    {
        wgui_catcall_fte_iconbar_enable_item(1, MMI_TRUE/* means disable */, get_string(STR_ID_UCM_SILENT), get_image(IMG_ID_UCM_SILENCE));
    }  
#endif /* __MMI_FTE_SUPPORT__ */    
#endif /* __MMI_SIDEKEY_SUPPRESS_RING__ */ 

#ifdef __MMI_UCM_RSK_SUPPRESS_RING__
    ChangeRightSoftkey(STR_ID_UCM_REJECT, 0);
    SetRightSoftkeyFunction(MMI_dummy_function, KEY_EVENT_DOWN);

    SetRightSoftkeyFunction(mmi_ucm_incoming_call_endkey, KEY_EVENT_UP);
#endif /* __MMI_UCM_RSK_SUPPRESS_RING__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_volume_hdlr
 * DESCRIPTION
 *  Adjust vloume for UCM call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_volume_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetDefaultVolumeKeyHandlers();
    EntryScrSetKeyPadVolumeLevel();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_sidekey
 * DESCRIPTION
 *  Handle side key for UCM call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_sidekey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    SetDefaultVolumeKeyHandlers();
    SetKeyUpHandler(SetKeyPadVolUp, KEY_VOL_UP);  /* O */
    SetKeyLongpressHandler(SetKeyPadVolMaxLongPress, KEY_VOL_UP);
    SetKeyRepeatHandler(MMI_dummy_function, KEY_VOL_UP);
    SetKeyUpHandler(SetKeyPadVolDown, KEY_VOL_DOWN);  /* O */
    SetKeyLongpressHandler(SetKeyPadVolMinLongPress, KEY_VOL_DOWN);
    SetKeyRepeatHandler(MMI_dummy_function, KEY_VOL_UP);

#ifdef __MMI_SOUND_RECORDER__
if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_VOIP_CALL_TYPE), NULL) > 0)
{
    /* [UCM3.0] CTM support*/
#ifdef __CTM_SUPPORT__
    /*if (ctm_p->status == FALSE)*/
#endif /* __CTM_SUPPORT__ */
    {
      //  SetKeyLongpressHandler(mmi_sndrec_entry_in_call, KEY_VOL_UP);
    }
}
#endif /* __MMI_SOUND_RECORDER__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_sendkey_hdlr
 * DESCRIPTION
 *  set sendkey handler function 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_sendkey_hdlr(FuncPtr sendkey_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->call_misc.sendkey_hdlr = sendkey_hdlr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_sendkey_hdlr
 * DESCRIPTION
 *  get sendkey handler function 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
FuncPtr mmi_ucm_get_sendkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_ucm_p->call_misc.sendkey_hdlr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_exec_sendkey_hdlr
 * DESCRIPTION
 *  get sendkey handler function 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_exec_sendkey_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_misc.sendkey_hdlr != NULL)
    {
        g_ucm_p->call_misc.sendkey_hdlr();
    }
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_sendkeys_send_hdlr
 * DESCRIPTION
 *  execute sendkeys' handler 
 * PARAMETERS 
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_sendkeys_send_hdlr(void)
{
    if (NULL == mmi_ucm_get_sendkey_hdlr())
    {
        return;
    }
    g_ucm_p->call_misc.sendkeys_makecall_dial_type = SRV_UCM_VOICE_CALL_TYPE; 
    mmi_ucm_exec_sendkey_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_sendkeys_send1_hdlr
 * DESCRIPTION
 *  execute SIM1 sendkeys' handler
 * PARAMETERS 
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_sendkeys_send1_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == mmi_ucm_get_sendkey_hdlr())
    {
        return;
    }
#ifdef __SENDKEY2_SUPPORT__
    g_ucm_p->call_misc.sendkeys_makecall_dial_type = SRV_UCM_VOICE_CALL_TYPE; /* sim1 */       
#else /* __SENDKEY2_SUPPORT__ */
    g_ucm_p->call_misc.sendkeys_makecall_dial_type = SRV_UCM_VOICE_CALL_TYPE_ALL; 
#endif /* __SENDKEY2_SUPPORT__ */
    mmi_ucm_exec_sendkey_hdlr();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_sendkeys_send2_hdlr
 * DESCRIPTION
 *  execute SIM2 sendkeys' handler
 * PARAMETERS 
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __SENDKEY2_SUPPORT__
void mmi_ucm_sendkeys_send2_hdlr(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == mmi_ucm_get_sendkey_hdlr())
    {
        return;
    }

    g_ucm_p->call_misc.sendkeys_makecall_dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM2; /* sim2 */   
    mmi_ucm_exec_sendkey_hdlr();
}
#endif /* __SENDKEY2_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_display_error_popup
 * DESCRIPTION
 *  Display result popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_display_error_popup(srv_ucm_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_UCM_RESULT_OK != result)
    {
        string_id = srv_ucm_query_error_message(result);
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_DISPLAY_POPUP_P2, result, string_id);

        mmi_popup_display_ext(string_id, MMI_EVENT_FAILURE, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_delete_all_screen
 * DESCRIPTION
 *  delete all UCM screens in histroy
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_delete_all_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_DELETE_ALL_SCREEN);

    mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_INCALL, SCR_ID_UCM_IN_CALL, (mmi_proc_func) NULL);
    mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_MT, SCR_ID_UCM_INCOMING, (mmi_proc_func) NULL);
    mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_MO, SCR_ID_UCM_OUTGOING, (mmi_proc_func) NULL);

    mmi_frm_group_close(GRP_ID_UCM_PRE_MO);
    mmi_frm_group_close(GRP_ID_UCM_MO);
    mmi_frm_group_close(GRP_ID_UCM_MT);
    mmi_frm_group_close(GRP_ID_UCM_INCALL);
#ifdef __MMI_VIDEO_TELEPHONY__
    mmi_frm_group_close(GRP_ID_UCM_VT);
#endif /* __MMI_VIDEO_TELEPHONY__ */
#if defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
    mmi_frm_group_close(GRP_ID_UCM_INT_MARKER);
#endif /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */
    mmi_frm_group_close(GRP_ID_UCM_MARKER);
    mmi_frm_group_close(GRP_ID_UCM_CALL_END);
    mmi_frm_group_close(GRP_ID_UCM_AUTO_REDIAL);
    mmi_frm_group_close(GRP_ID_UCM_CONFIRM);
    mmi_ucm_delete_common_screens();     
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_processing_parameter
 * DESCRIPTION
 *  Set processing screen parameter.
 * PARAMETERS
 *  titleStr            [IN]        Title string
 *  bodyStr             [IN]        Body string
 *  animationImg        [IN]        Animation image
 *  lskStr              [IN]        LSK display string
 *  lskFunc             [IN]        LSK function pointer
 *  rskStr              [IN]        RSK display string
 *  rskFunc             [IN]        RSK function pointer
 *  sendFunc            [IN]        SEND key function pointer
 *  endFunc             [IN]        END key function pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_processing_parameter(
        U16 titleStr,
        U16 bodyStr,
        U16 animationImg,
        U16 lskStr,
        FuncPtr lskFunc,
        U16 rskStr,
        FuncPtr rskFunc,
        FuncPtr sendFunc,
        FuncPtr endFunc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->proc_scr.title_string = titleStr;
    g_ucm_p->proc_scr.body_string = bodyStr;
    g_ucm_p->proc_scr.body_string_pointer = NULL;
    g_ucm_p->proc_scr.animation_image = animationImg;
    g_ucm_p->proc_scr.lsk_string = lskStr;
    g_ucm_p->proc_scr.lsk_funcPtr = lskFunc;
    g_ucm_p->proc_scr.rsk_string = rskStr;
    g_ucm_p->proc_scr.rsk_funcPtr = rskFunc;
    g_ucm_p->proc_scr.send_funcPtr = sendFunc;
    g_ucm_p->proc_scr.end_funcPtr = endFunc;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_processing_parameter_with_body_string_pointer
 * DESCRIPTION
 *  Set processing screen parameter.
 * PARAMETERS
 *  titleStr            [IN]        Title string
 *  bodyStr             [IN]        Body string
 *  animationImg        [IN]        Animation image
 *  lskStr              [IN]        LSK display string
 *  lskFunc             [IN]        LSK function pointer
 *  rskStr              [IN]        RSK display string
 *  rskFunc             [IN]        RSK function pointer
 *  sendFunc            [IN]        SEND key function pointer
 *  endFunc             [IN]        END key function pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_processing_parameter_with_body_string_p(
        U16 titleStr,
        U8* bodyStrP,
        U16 animationImg,
        U16 lskStr,
        FuncPtr lskFunc,
        U16 rskStr,
        FuncPtr rskFunc,
        FuncPtr sendFunc,
        FuncPtr endFunc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 unicodeLen;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->proc_scr.title_string = titleStr;
    g_ucm_p->proc_scr.body_string = 0;
    if (NULL != g_ucm_p->proc_scr.body_string_pointer)
    {
        OslMfree(g_ucm_p->proc_scr.body_string_pointer);
    }
    g_ucm_p->proc_scr.body_string_pointer = OslMalloc((SRV_UCM_MAX_DISP_MSG_LEN + 1) * ENCODING_LENGTH);
    memset(g_ucm_p->proc_scr.body_string_pointer, 0, (SRV_UCM_MAX_DISP_MSG_LEN + 1) * ENCODING_LENGTH);
    unicodeLen = (SRV_UCM_MAX_DISP_MSG_LEN > mmi_ucs2strlen((CHAR*)bodyStrP)) ? (mmi_ucs2strlen((CHAR*)bodyStrP)) : (SRV_UCM_MAX_DISP_MSG_LEN);    
    if (unicodeLen > 0)
    {
        mmi_ucs2ncpy((CHAR*)g_ucm_p->proc_scr.body_string_pointer, (CHAR*)bodyStrP, unicodeLen);
    }
    g_ucm_p->proc_scr.animation_image = animationImg;
    g_ucm_p->proc_scr.lsk_string = lskStr;
    g_ucm_p->proc_scr.lsk_funcPtr = lskFunc;
    g_ucm_p->proc_scr.rsk_string = rskStr;
    g_ucm_p->proc_scr.rsk_funcPtr = rskFunc;
    g_ucm_p->proc_scr.send_funcPtr = sendFunc;
    g_ucm_p->proc_scr.end_funcPtr = endFunc;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_add_incall_sg_scrn
 * DESCRIPTION
 *  Add incall screen to history
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_add_incall_sg_scrn(srv_ucm_call_type_enum active_call_type, MMI_ID base_grp_id, mmi_scenario_node_flag flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Can remove it when all module apply SG mechanism */
    if (GRP_ID_INVALID == base_grp_id)
    {
        /* means the current active screen does not apply SG mechanism yet */
        base_grp_id = mmi_frm_scrn_get_active_id();
    }

#ifdef __MMI_VIDEO_TELEPHONY__    
    if (active_call_type & SRV_UCM_VIDEO_CALL_TYPE_ALL)
    {
        mmi_ucm_add_sg_to_root(base_grp_id, GRP_ID_UCM_VT, flag, mmi_ucm_vt_sg_proc);
        mmi_ucm_vt_enter_in_call();
    }
    else
#endif /* __MMI_VIDEO_TELEPHONY__ */
    {
        mmi_ucm_add_sg_to_root(base_grp_id, GRP_ID_UCM_INCALL, flag, mmi_ucm_incall_sg_proc);        
        mmi_ucm_enter_in_call();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_delete_common_screens
 * DESCRIPTION
 *  delete common screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_delete_common_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_delete_scrn_if_not_active(GRP_ID_UCM_CONFIRM, SCR_ID_UCM_PROCESSING);
    mmi_ucm_delete_scrn_if_not_active(GRP_ID_UCM_MT, SCR_ID_UCM_PROCESSING);
    mmi_ucm_delete_scrn_if_not_active(GRP_ID_UCM_MO, SCR_ID_UCM_PROCESSING);
#if defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
    mmi_ucm_delete_scrn_if_not_active(GRP_ID_UCM_INT_MARKER, SCR_ID_UCM_PROCESSING);
#endif /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */
    mmi_ucm_delete_scrn_if_not_active(GRP_ID_UCM_INCALL, SCR_ID_UCM_PROCESSING);
#ifdef __MMI_VIDEO_TELEPHONY__
    mmi_ucm_delete_scrn_if_not_active(GRP_ID_UCM_VT, SCR_ID_UCM_PROCESSING);
#endif /* __MMI_VIDEO_TELEPHONY__ */
    /* Delete MO SG */
    mmi_ucm_delete_scrn_if_not_active(GRP_ID_UCM_MO, SCR_ID_UCM_DTMF_EDITOR);
#ifdef __MMI_BG_SOUND_EFFECT__      
    mmi_ucm_delete_scrn_if_not_active(GRP_ID_UCM_PRE_MO, SCR_ID_UCM_BGS_EFFECT_SELECT);
#endif /* __MMI_BG_SOUND_EFFECT__ */    
    mmi_ucm_delete_scrn_if_not_active(GRP_ID_UCM_PRE_MO, SCR_ID_UCM_DIAL_CALL_TYPE_MENU);

    /* Delete MT SG */
    mmi_ucm_delete_scrn_if_not_active(GRP_ID_UCM_MT, SCR_ID_UCM_DTMF_EDITOR);
#ifdef __MMI_BG_SOUND_EFFECT__     
    mmi_ucm_delete_scrn_if_not_active(GRP_ID_UCM_MT, SCR_ID_UCM_BGS_EFFECT_SELECT);
#endif /* __MMI_BG_SOUND_EFFECT__ */

#ifdef __MMI_UCM_DEFLECT__
    /* also need to delete the phb CUI scrns triggered by deflect - mmi_ucm_call_deflect_delete_proc */
    mmi_ucm_delete_scrn_if_not_active(GRP_ID_UCM_MT, SCR_ID_UCM_DEFLECT);
#endif /* __MMI_UCM_DEFLECT__ */

    /* Delete INCALL SG */
    mmi_ucm_delete_scrn_if_not_active(GRP_ID_UCM_INCALL, SCR_ID_UCM_DTMF_EDITOR);
    mmi_ucm_close_cui(&g_ucm_p->cui_info.in_call_dialer_opt_cui_id);
#ifndef __MMI_UCM_SLIM__
    mmi_ucm_delete_scrn_if_not_active(GRP_ID_UCM_INCALL, SCR_ID_UCM_MULTI_HELD_CALL);
    mmi_ucm_delete_scrn_if_not_active(GRP_ID_UCM_INCALL, SCR_ID_UCM_VOICE_DIALER);
#endif /* __MMI_UCM_SLIM__ */
#ifdef __MMI_UCM_TRANSFER__
    mmi_ucm_delete_scrn_if_not_active(GRP_ID_UCM_INCALL, SCR_ID_UCM_TRANSFER);
#endif /* __MMI_UCM_TRANSFER__ */
#ifdef __MMI_VOIP__
    mmi_ucm_delete_scrn_if_not_active(GRP_ID_UCM_INCALL, SCR_ID_UCM_VOIP_DIALER);
#endif /* __MMI_VOIP__ */
#ifndef __MMI_UCM_SLIM__
    mmi_ucm_close_cui(&g_ucm_p->cui_info.new_call_dialer_opt_cui_id);
#endif /* __MMI_UCM_SLIM__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_delete_dtmf_editor_screen
 * DESCRIPTION
 *  delete dtmf editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_delete_dtmf_editor_screen(void)
{
    mmi_frm_scrn_close(GRP_ID_UCM_MO, SCR_ID_UCM_DTMF_EDITOR);
    mmi_frm_scrn_close(GRP_ID_UCM_MT, SCR_ID_UCM_DTMF_EDITOR);
    mmi_frm_scrn_close(GRP_ID_UCM_INCALL, SCR_ID_UCM_DTMF_EDITOR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_close_cui
 * DESCRIPTION
 *  close cui
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_close_cui(mmi_id *cui_id)
{
    if (GRP_ID_INVALID != *cui_id)
    {
        cui_menu_close(*cui_id);
        *cui_id = GRP_ID_INVALID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_bt_set_audio_path
 * DESCRIPTION
 *  BT set audio path function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_bt_set_audio_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BT_HP_SUPPORT__) || defined(__MMI_BT_SUPPORT__)
    if (srv_bt_cm_is_incall_aud_swap2bt() == MMI_TRUE) /* O */
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SET_AUDIO_PATH_TO_AG);
        /* Current voice path in BT, shall transfer to AG */
        mmi_bt_switch_voice_path_incall(MMI_FALSE);
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_BT_SET_AUDIO_PATH_TO_BT);
        /* Current voice path in AG, shall transfer to BT */
        mmi_bt_switch_voice_path_incall(MMI_TRUE);
    }
#endif /* defined(__MMI_BT_HP_SUPPORT__) || defined(__MMI_BT_SUPPORT__) */
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_display_popup_when_call_exist
 * DESCRIPTION
 *  display popup only when any call exists
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_display_popup_when_call_exist(UI_string_type string, mmi_event_notify_enum event_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        if (mmi_ucs2strlen((CHAR*)string) > 0)
        {
            mmi_popup_display((WCHAR*)(string), event_id, NULL);
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_title_string_by_action
 * DESCRIPTION
 *  get title string by given action
 * PARAMETERS
 *  act_op      [IN] action op code
 * RETURNS
 *  void
 *****************************************************************************/
U16 mmi_ucm_get_title_string_by_action(srv_ucm_act_opcode_enum act_op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (act_op)
    {
        case SRV_UCM_DIAL_ACT:
        {
            return STR_GLOBAL_DIAL;
        }
        
        case SRV_UCM_ACCEPT_ACT:
        {
            return STR_ID_UCM_ANSWER;
        }

    #if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
        case SRV_UCM_VT_FALLTO_VOICE_ACT:
        {
            return STR_ID_UCM_ANSWER_BY_VOICE;
        }
    #endif /* __OP01__ && __MMI_VIDEO_TELEPHONY__ */

        case SRV_UCM_HOLD_ACT:
        {
            return STR_ID_UCM_HOLD;
        }

        case SRV_UCM_RETRIEVE_ACT:
        {
            return STR_ID_UCM_RETRIEVE;
        }

        case SRV_UCM_SWAP_ACT:
        {
            return STR_ID_UCM_SWAP;
        }

        case SRV_UCM_CONFERENCE_ACT:
        {
            return STR_ID_UCM_CONFERENCE;
        }

        case SRV_UCM_SPLIT_ACT:
        {
            return STR_ID_UCM_SPLIT;
        }

    #ifdef __MMI_UCM_DEFLECT__    
        case SRV_UCM_DEFLECT_ACT:
        {   
            return STR_ID_UCM_DEFLECT;
        }
    #endif /* __MMI_UCM_DEFLECT__ */    

    #ifdef __MMI_UCM_TRANSFER__
        case SRV_UCM_TRANSFER_ACT:
        {
            return STR_ID_UCM_TRANSFER;
        }
    #endif /* __MMI_UCM_TRANSFER__ */

    #ifdef __MMI_UCM_ECT__
        case SRV_UCM_EXPLICIT_CALL_TRANSFER_ACT:            
        {
            return STR_ID_UCM_TRANSFER;
        }
    #endif /* __MMI_UCM_ECT__ */ 

        case SRV_UCM_END_SINGLE_ACT:
        {
            return STR_ID_UCM_END_SINGLE;
        }

        case SRV_UCM_END_CONFERENCE_ACT:
        {
            return STR_ID_UCM_END_CONFERENCE;
        }

        case SRV_UCM_END_ALL_ACT:
        {
            if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 1)
            {
                return STR_ID_UCM_END_ALL;
            }
            else
            {
                return STR_ID_UCM_END_CALL;
            }
        }
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__
        case SRV_UCM_END_ALL_ACTIVE_ACT:
        {
#if !defined(__MMI_UCM_SLIM__)
            if (srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) > 1)
            {
                return STR_ID_UCM_END_ALL_ACTIVE;
            }
            else
#endif
            {
                return STR_ID_UCM_END_CALL;
            }
        }
#endif

#if !defined(__MMI_UCM_SLIM__)
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
        case SRV_UCM_END_ALL_HELD_ACT:
        {
            return STR_ID_UCM_END_ALL_HELD;
        }
#endif
#endif
        case SRV_UCM_END_ALL_PROCESSING_ACT:
        {
            return STR_ID_UCM_PROCESSING;
        }

        default:
        {
            MMI_ASSERT(0);
        }
    }
    return STR_GLOBAL_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_call_type_string_id
 * DESCRIPTION
 *  get call type string id by call type
 * PARAMETERS
 *  void
 * RETURNS
 *  String id
 *****************************************************************************/
U16 mmi_ucm_get_call_type_string_id(srv_ucm_call_type_enum call_type, srv_ucm_call_state_enum call_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (mmi_ucm_one_sim_behavior_is_needed())
    {
        if (call_type == SRV_UCM_VOICE_CALL_TYPE ||
            call_type == SRV_UCM_VOICE_CALL_TYPE_SIM2 ||
            call_type == SRV_UCM_VOICE_CALL_TYPE_SIM3 ||
            call_type == SRV_UCM_VOICE_CALL_TYPE_SIM4)
        {
            if (call_state == SRV_UCM_ACTIVE_STATE)
            {
                str_id = STR_ID_UCM_VOICE_ACTIVE;
            }
            else if (call_state == SRV_UCM_HOLD_STATE)
            {
                str_id = STR_ID_UCM_VOICE_HOLD;
            }
            else
            {
                MMI_ASSERT(0);
            }
            return str_id;
        }
    }
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

    if (call_type == SRV_UCM_VOICE_CALL_TYPE)
    {
        if (call_state == SRV_UCM_ACTIVE_STATE)
        {
        #if (MMI_MAX_SIM_NUM >= 2)
            str_id = STR_ID_UCM_SIM1_VOICE_ACTIVE;
        #else /* (MMI_MAX_SIM_NUM >= 2) */
            str_id = STR_ID_UCM_VOICE_ACTIVE;
        #endif /* (MMI_MAX_SIM_NUM >= 2) */
        }
        else if (call_state == SRV_UCM_HOLD_STATE)
        {
        #if (MMI_MAX_SIM_NUM >= 2)
            str_id = STR_ID_UCM_SIM1_VOICE_HOLD;
        #else /* (MMI_MAX_SIM_NUM >= 2) */
            str_id = STR_ID_UCM_VOICE_HOLD;
        #endif /* (MMI_MAX_SIM_NUM >= 2) */
        }
        else
        {
            MMI_ASSERT(0); /* call state either active or hold */
        }
    }
#if (MMI_MAX_SIM_NUM >= 2)
    else if (call_type == SRV_UCM_VOICE_CALL_TYPE_SIM2)
    {
        if (call_state == SRV_UCM_ACTIVE_STATE)
        {
            str_id = STR_ID_UCM_SIM2_VOICE_ACTIVE;
        }
        else if (call_state == SRV_UCM_HOLD_STATE)
        {
            str_id = STR_ID_UCM_SIM2_VOICE_HOLD;
        }
        else
        {
            MMI_ASSERT(0); /* call state either active or hold */
        }
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (call_type == SRV_UCM_VOICE_CALL_TYPE_SIM3)
    {
        if (call_state == SRV_UCM_ACTIVE_STATE)
        {
            str_id = STR_ID_UCM_SIM3_VOICE_ACTIVE;
        }
        else if (call_state == SRV_UCM_HOLD_STATE)
        {
            str_id = STR_ID_UCM_SIM3_VOICE_HOLD;
        }
        else
        {
            MMI_ASSERT(0); /* call state either active or hold */
        }
    }
#if (MMI_MAX_SIM_NUM == 4)
    else if (call_type == SRV_UCM_VOICE_CALL_TYPE_SIM4)
    {
        if (call_state == SRV_UCM_ACTIVE_STATE)
        {
            str_id = STR_ID_UCM_SIM4_VOICE_ACTIVE;
        }
        else if (call_state == SRV_UCM_HOLD_STATE)
        {
            str_id = STR_ID_UCM_SIM4_VOICE_HOLD;
        }
        else
        {
            MMI_ASSERT(0); /* call state either active or hold */
        }
    }
#endif /* (MMI_MAX_SIM_NUM == 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#ifdef __MMI_VOIP__
    else if (call_type == SRV_UCM_VOIP_CALL_TYPE)
    {
        if (call_state == SRV_UCM_ACTIVE_STATE)
        {
            str_id = STR_ID_UCM_VOIP_ACTIVE;
        }
        else if (call_state == SRV_UCM_HOLD_STATE)
        {
            str_id = STR_ID_UCM_VOIP_HOLD;
        }
        else
        {
            MMI_ASSERT(0); /* call state either active or hold */
        }
    }
#endif /* __MMI_VOIP__ */
    else if (call_type & SRV_UCM_DATA_CALL_TYPE_ALL)
    {
        if (call_state == SRV_UCM_ACTIVE_STATE)
        {
            str_id = STR_ID_UCM_ACTIVE;
        }
        else
        {
            
            MMI_ASSERT(0); /* Data call state should be only active */
        }        
    }
    else
    {
        MMI_ASSERT(0);
    }

    return str_id;
}


#if defined(__MMI_UCM_MO_FAIL_POST_ACTION__) || defined(__MMI_VIDEO_TELEPHONY__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_get_redial_string
 * DESCRIPTION
 *  Get redial string by call type
 * PARAMETERS
 *  call_type         [IN] Redial call type
 * RETURNS
 *  Redial string
 *****************************************************************************/
CHAR *mmi_ucm_get_redial_string(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
    if (mmi_ucm_one_sim_behavior_is_needed())
    {
        if (call_type == SRV_UCM_VOICE_CALL_TYPE ||
            call_type == SRV_UCM_VOICE_CALL_TYPE_SIM2 ||
            call_type == SRV_UCM_VOICE_CALL_TYPE_SIM3 ||
            call_type == SRV_UCM_VOICE_CALL_TYPE_SIM4)
        {
            return GetString(STR_ID_UCM_REDIAL_VOICE_CALL);
        }
    #ifdef __MMI_VIDEO_TELEPHONY__
        else if (call_type == SRV_UCM_VIDEO_CALL_TYPE)
        {
            return GetString(STR_ID_UCM_VT_REDIAL_VIDEO_CALL);
        }
    #endif /* __MMI_VIDEO_TELEPHONY__ */
    }
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

    if (call_type == SRV_UCM_VOICE_CALL_TYPE)
    {
    #if (MMI_MAX_SIM_NUM >= 2)
        str_id = STR_ID_UCM_REDIAL_SIM1_VOICE_CALL;
    #else /* (MMI_MAX_SIM_NUM >= 2) */
        str_id = STR_ID_UCM_REDIAL_VOICE_CALL;
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
    }
#ifdef __MMI_VIDEO_TELEPHONY__
    else if (call_type == SRV_UCM_VIDEO_CALL_TYPE)
    {
    #if (MMI_MAX_SIM_NUM >= 2) && !defined(__MMI_3G_SWITCH__)
        str_id = STR_ID_UCM_VT_REDIAL_SIM1_VIDEO_CALL;
    #else /* (MMI_MAX_SIM_NUM >= 2) && !defined(__MMI_3G_SWITCH__) */
        str_id = STR_ID_UCM_VT_REDIAL_VIDEO_CALL;
    #endif /* (MMI_MAX_SIM_NUM >= 2) && !defined(__MMI_3G_SWITCH__) */
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */
#if (MMI_MAX_SIM_NUM >= 2)
    else if (call_type == SRV_UCM_VOICE_CALL_TYPE_SIM2)
    {
        str_id = STR_ID_UCM_REDIAL_SIM2_VOICE_CALL;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (call_type == SRV_UCM_VOICE_CALL_TYPE_SIM3)
    {
        str_id = STR_ID_UCM_REDIAL_SIM3_VOICE_CALL;
    }
#if (MMI_MAX_SIM_NUM == 4)
    else if (call_type == SRV_UCM_VOICE_CALL_TYPE_SIM4)
    {
        str_id = STR_ID_UCM_REDIAL_SIM4_VOICE_CALL;
    }
#endif /* (MMI_MAX_SIM_NUM == 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
    return GetString(str_id);
}
#endif /* defined(__MMI_UCM_MO_FAIL_POST_ACTION__) || defined(__MMI_VIDEO_TELEPHONY__) */


#ifdef __MMI_UCM_MO_FAIL_POST_ACTION__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_process_mo_fail_post_action
 * DESCRIPTION
 *  Process mo fail action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_process_mo_fail_post_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_ucm_make_call_para_struct makecall_para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_POST_ACTION_DIAL_PAD_BUF_P10, g_ucm_p->mo_info.dial_pad_buffer[0], 
        g_ucm_p->mo_info.dial_pad_buffer[1], g_ucm_p->mo_info.dial_pad_buffer[2], g_ucm_p->mo_info.dial_pad_buffer[3],
        g_ucm_p->mo_info.dial_pad_buffer[4],g_ucm_p->mo_info.dial_pad_buffer[5],g_ucm_p->mo_info.dial_pad_buffer[6],
        g_ucm_p->mo_info.dial_pad_buffer[7],g_ucm_p->mo_info.dial_pad_buffer[8],g_ucm_p->mo_info.dial_pad_buffer[9]);

    MMI_ASSERT(g_ucm_p->post_action_info.curr_hilite_index < MMI_UCM_MO_FAIL_ACTION_TOTAL_NUM);

    mmi_ucm_init_call_para(&makecall_para);

    switch (g_ucm_p->post_action_info.menu_list[g_ucm_p->post_action_info.curr_hilite_index])
    {
        case MMI_UCM_MO_FAIL_ACTION_REDIAL_VOICE_CALL:
        {
            makecall_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;
        }
        break;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_UCM_MO_FAIL_ACTION_REDIAL_VOICE_CALL_SIM2:
        {
            makecall_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
        }
        break;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_UCM_MO_FAIL_ACTION_REDIAL_VOICE_CALL_SIM3:
        {
            makecall_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
        }
        break;
    #if (MMI_MAX_SIM_NUM == 4)
        case MMI_UCM_MO_FAIL_ACTION_REDIAL_VOICE_CALL_SIM4:
        {
            makecall_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
        }
        break;
    #endif /*(MMI_MAX_SIM_NUM == 4)*/   
    #endif /*(MMI_MAX_SIM_NUM >= 3)*/   
    #endif /*(MMI_MAX_SIM_NUM >= 2)*/        
        default:
        {
            MMI_ASSERT(0);
        }
        break;        
    }

    makecall_para.ucs2_num_uri = (U16*)g_ucm_p->mo_info.dial_pad_buffer;
    makecall_para.adv_para.is_ip_dial = g_ucm_p->mo_info.is_ip_dial;
    makecall_para.adv_para.phb_data = g_ucm_p->mo_info.phb_data;
    mmi_ucm_call_launch(0, &makecall_para);

    mmi_frm_group_close(GRP_ID_UCM_MO_FAIL_POST_ACTION);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enter_mo_fail_post_action
 * DESCRIPTION
 *  Enter MO call fail post action screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enter_mo_fail_post_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_MO_FAIL_POST_ACTION, SCR_ID_UCM_MO_FAIL_POST_ACTION, 
        (FuncPtr)mmi_ucm_entry_mo_fail_post_action, 
        (void*)NULL);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_mo_fail_post_action
 * DESCRIPTION
 *  Entry post action screen after failed MO 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_entry_mo_fail_post_action(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 item_index = 0;
    U8 *listItemsIcons[MAX_SUB_MENUS];
    
    S32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_MO_FAIL_POST_ACTION,
                    NULL,
                    (FuncPtr)mmi_ucm_entry_mo_fail_post_action,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }

    memset(listItemsIcons, 0, sizeof(listItemsIcons));
    memset(subMenuDataPtrs, 0, sizeof(subMenuDataPtrs));
    memset(g_ucm_p->post_action_info.menu_list, 0, sizeof(g_ucm_p->post_action_info.menu_list));
    idx = 0;

#if (MMI_MAX_SIM_NUM >= 2)
    if ((g_ucm_p->mo_info.dial_type == SRV_UCM_VOICE_CALL_TYPE) &&
        (MMI_TRUE == srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE)))
    {
        g_ucm_p->post_action_info.menu_list[idx] = MMI_UCM_MO_FAIL_ACTION_REDIAL_VOICE_CALL;
        subMenuDataPtrs[idx++] = (PU8) mmi_ucm_get_redial_string(SRV_UCM_VOICE_CALL_TYPE);
    }
    if ((g_ucm_p->mo_info.dial_type == SRV_UCM_VOICE_CALL_TYPE_SIM2) &&
        (MMI_TRUE == srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE_SIM2)))
    {
        g_ucm_p->post_action_info.menu_list[idx] = MMI_UCM_MO_FAIL_ACTION_REDIAL_VOICE_CALL_SIM2;
        subMenuDataPtrs[idx++] = (PU8) mmi_ucm_get_redial_string(SRV_UCM_VOICE_CALL_TYPE_SIM2);
    }
#if (MMI_MAX_SIM_NUM >= 3)
    if ((g_ucm_p->mo_info.dial_type == SRV_UCM_VOICE_CALL_TYPE_SIM3) &&
        (MMI_TRUE == srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE_SIM3)))
    {
        g_ucm_p->post_action_info.menu_list[idx] = MMI_UCM_MO_FAIL_ACTION_REDIAL_VOICE_CALL_SIM3;
        subMenuDataPtrs[idx++] = (PU8) mmi_ucm_get_redial_string(SRV_UCM_VOICE_CALL_TYPE_SIM3);
    }
#if (MMI_MAX_SIM_NUM == 4)
    if ((g_ucm_p->mo_info.dial_type == SRV_UCM_VOICE_CALL_TYPE_SIM4) &&
        (MMI_TRUE == srv_ucm_is_call_srv_available(SRV_UCM_VOICE_CALL_TYPE_SIM4)))
    {
        g_ucm_p->post_action_info.menu_list[idx] = MMI_UCM_MO_FAIL_ACTION_REDIAL_VOICE_CALL_SIM4;
        subMenuDataPtrs[idx++] = (PU8) mmi_ucm_get_redial_string(SRV_UCM_VOICE_CALL_TYPE_SIM4);
    }
#endif /* (MMI_MAX_SIM_NUM == 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#else /* (MMI_MAX_SIM_NUM >= 2) */
    g_ucm_p->post_action_info.menu_list[idx] = MMI_UCM_MO_FAIL_ACTION_REDIAL_VOICE_CALL;
    subMenuDataPtrs[idx++] = (PU8) mmi_ucm_get_redial_string(SRV_UCM_VOICE_CALL_TYPE);
#endif /* (MMI_MAX_SIM_NUM >= 2) */

    for (item_index = 0; item_index < idx; item_index++)
    {
        listItemsIcons[item_index] = (U8*) GetImage(gIndexIconsImageList[item_index]);
    }
    
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    guiBuffer = mmi_frm_scrn_get_gui_buf(scr_info->group_id, SCR_ID_UCM_MO_FAIL_POST_ACTION);
    RegisterHighlightHandler(mmi_ucm_setting_get_hilite_index);

    ShowCategory32Screen(
        (U8*) GetString(STR_ID_UCM_FAIL_TO_MAKE_VOICE_CALL),
        (U8*) GetImage(GetRootTitleIcon(MAIN_MENU_CALL_LOG)),
        (U8*) GetString(STR_GLOBAL_OK),
        (U8*) GetImage(IMG_GLOBAL_OK),
        (U8*) GetString(STR_GLOBAL_BACK),
        (U8*) GetImage(IMG_GLOBAL_BACK),
        idx,
        (U8 **) subMenuDataPtrs,
        listItemsIcons,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_ucm_process_mo_fail_post_action, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_ucm_process_mo_fail_post_action, KEY_EVENT_UP);
}
#endif /* __MMI_UCM_MO_FAIL_POST_ACTION__ */


#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_volume_control_callback
 * DESCRIPTION
 *  Volume control from H-Free device
 * PARAMETERS
 *  volume      IN  volume want to set to FM by HFP
 *  is_mute     IN  CM doen't not support mute
 * RETURNS
 *  MMI_TRUE    Set volume to CM OK
 *  MMI_FALSE   Speech is off now
 *****************************************************************************/
MMI_BOOL mmi_ucm_volume_control_callback(U8 volume, MMI_BOOL is_mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VOLUME_CONTROL_CALLBACK, volume, is_mute);
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0) 
    {
        /* Adjust ring tone volume */
        mmi_vol_set_ring_vol(volume);
    }
    else
    {
        /* Adjust speech volume */
        mmi_vol_set_speech_vol(volume);
    }
    return MMI_TRUE;
}
#endif /* __BT_SPK_VOL_CONTROL__ */


#ifdef __MMI_BT_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_bt_notify
 * DESCRIPTION
 *  Register BT notify handler, when the bt status is changed, call will receive
 *  the notification.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_bt_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_ucm_p->bt_audio_id)
    {
        g_ucm_p->bt_audio_id = srv_bt_cm_set_notify((srv_bt_cm_notifier)mmi_ucm_incall_bt_set_audio_path_hdlr, SRV_BT_CM_EVENT_SCO_IND , NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_reset_bt_notify
 * DESCRIPTION
 *  Deregister BT notify handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_reset_bt_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bt_cm_reset_notify(g_ucm_p->bt_audio_id);
    g_ucm_p->bt_audio_id = 0;
}
#endif /* __MMI_BT_SUPPORT__ */


#ifdef  __MMI_FTE_SUPPORT__
#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_intuitive_cmd_cb
 * DESCRIPTION
 *  In FTE, it should support intuitive command. do nothing when user touch call in incall list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_intuitive_cmd_cb(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    return;  
}
#endif /* __MMI_TOUCH_SCREEN__ */

#ifdef __MMI_UCM_FTE_SLIM_ICONBAR_PRESENT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_FTE_fill_iconbar_items
 * DESCRIPTION
 *  decide whic iconbar should be displayed in each state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_FTE_fill_iconbar_items(mmi_ucm_FTE_iconbar_state_enum iconbar_state, wgui_catcall_fte_iconbar_item_struct *items, S32 number_of_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 audio_mode;
    S32 call_count;
    S32 group_count;
    srv_ucm_group_info_struct group_info;
#if defined(__OP01__) && (defined(__MMI_UCM_REJECT_BY_SMS__) || defined(__MMI_VIDEO_TELEPHONY__))
    S32 MT_icon_count = 2;
#endif /* defined(__OP01__) && (defined(__MMI_UCM_REJECT_BY_SMS__) || defined(__MMI_VIDEO_TELEPHONY__)) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch (iconbar_state)
    {  
        case MMI_UCM_FTE_ICONBAR_INCOMING_CALL:
        {
            /* Answer */    
            items[0].label = get_string(STR_ID_UCM_ANSWER);
            items[0].icon = get_image(IMG_ID_UCM_ANSWER); 
            items[0].up = get_image(IMG_ID_UCM_GREEN_BUTTON_UP);            
            items[0].down = get_image(IMG_ID_UCM_GREEN_BUTTON_DOWN);
            items[0].disable = get_image(IMG_ID_UCM_GREEN_BUTTON_DISABLE);
            items[0].handler = mmi_ucm_incoming_call_sendkey;

            /* Silence*/
            if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL))
            {
                items[1].label = get_string(STR_ID_UCM_SILENT);
                items[1].icon = get_image(IMG_ID_UCM_SILENCE); 
                items[1].up = get_image(IMG_ID_UCM_NORMAL_BUTTON_UP);            
                items[1].down = get_image(IMG_ID_UCM_NORMAL_BUTTON_DOWN);
                items[1].disable = get_image(IMG_ID_UCM_NORMAL_BUTTON_DISABLE);
                items[1].handler = mmi_ucm_FTE_suppress_incoming_tone_hdlr;
            }
            else
            {
                MMI_ASSERT(0);
            }
            /* only OP01 need to display "answer by voice" and "reject by sms" in iconbar */
        #ifdef __OP01__     
        #ifdef __MMI_UCM_REJECT_BY_SMS__
            /* Reject by SMS */
            items[MT_icon_count].label = get_string(STR_ID_UCM_REJ_BY_SMS);
            items[MT_icon_count].icon = get_image(IMG_ID_UCM_REJECT_BY_SMS); 
            items[MT_icon_count].up = get_image(IMG_ID_UCM_NORMAL_BUTTON_UP);            
            items[MT_icon_count].down = get_image(IMG_ID_UCM_NORMAL_BUTTON_DOWN);
            items[MT_icon_count].disable = get_image(IMG_ID_UCM_NORMAL_BUTTON_DISABLE);
            items[MT_icon_count].handler = mmi_ucm_get_sms_template_action;   
            MT_icon_count ++;
        #endif /* __OP01__ && __MMI_UCM_REJECT_BY_SMS__ */

        #ifdef __MMI_VIDEO_TELEPHONY__
            /* Answer by voice */    
            items[MT_icon_count].label = get_string(STR_ID_UCM_ANSWER_BY_VOICE);
            items[MT_icon_count].icon = get_image(IMG_ID_UCM_ANSWER_BY_VOICE); 
            items[MT_icon_count].up = get_image(IMG_ID_UCM_NORMAL_BUTTON_UP);            
            items[MT_icon_count].down = get_image(IMG_ID_UCM_NORMAL_BUTTON_DOWN);
            items[MT_icon_count].disable = get_image(IMG_ID_UCM_NORMAL_BUTTON_DISABLE);
            items[MT_icon_count].handler = mmi_ucm_vt_incoming_call_answer_by_voice;           
        #endif /* __MMI_VIDEO_TELEPHONY__ */
        #endif /* __OP01__ */
        }
        break;
        
        case MMI_UCM_FTE_ICONBAR_WAITING_CALL:
        {
            /* Answer */    
            items[0].label = get_string(STR_ID_UCM_ANSWER);
            items[0].icon = get_image(IMG_ID_UCM_ANSWER); 
            items[0].up = get_image(IMG_ID_UCM_GREEN_BUTTON_UP);            
            items[0].down = get_image(IMG_ID_UCM_GREEN_BUTTON_DOWN);
            items[0].disable = get_image(IMG_ID_UCM_GREEN_BUTTON_DISABLE);
            items[0].handler = mmi_ucm_incoming_call_sendkey;

            /* End active or end held */
#if !defined(__MMI_UCM_SLIM__)
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__
            if (mmi_ucm_simple_option(SRV_UCM_END_ALL_ACTIVE_ACT, MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
            {
                items[1].label = get_string(STR_ID_UCM_END_ALL_ACTIVE);
                items[1].icon = get_image(IMG_ID_UCM_END); 
                items[1].up = get_image(IMG_ID_UCM_RED_BUTTON_UP);            
                items[1].down = get_image(IMG_ID_UCM_RED_BUTTON_DOWN);
                items[1].disable = get_image(IMG_ID_UCM_RED_BUTTON_DISABLE);
                items[1].handler = mmi_ucm_end_all_active_action;
            }
            else 
#endif
#endif
#if !defined(__MMI_UCM_SLIM__)
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
				if (mmi_ucm_simple_option(SRV_UCM_END_ALL_HELD_ACT, MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
            {
                items[1].label = get_string(STR_ID_UCM_END_ALL_HELD);
                items[1].icon = get_image(IMG_ID_UCM_END); 
                items[1].up = get_image(IMG_ID_UCM_RED_BUTTON_UP);            
                items[1].down = get_image(IMG_ID_UCM_RED_BUTTON_DOWN);
                items[1].disable = get_image(IMG_ID_UCM_RED_BUTTON_DISABLE);
                items[1].handler = mmi_ucm_end_all_held_action;
            }
            else
#endif           
#endif
            {
                if (srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_NO_CSD,MMI_FALSE, NULL) > 0)
                {
#if !defined(__MMI_UCM_SLIM__)
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_ACTIVE__
                    items[1].label = get_string(STR_ID_UCM_END_ALL_ACTIVE);
                    items[1].icon = get_image(IMG_ID_UCM_END); 
                    items[1].up = get_image(IMG_ID_UCM_RED_BUTTON_UP);            
                    items[1].down = get_image(IMG_ID_UCM_RED_BUTTON_DOWN);
                    items[1].disable = get_image(IMG_ID_UCM_RED_BUTTON_DISABLE);
                    items[1].handler = mmi_ucm_end_all_active_action;
#endif
#endif
                }
                else
                {
#if !defined(__MMI_UCM_SLIM__)
#ifdef __MMI_UCM_COMPOUND_ACTION_END_ALL_HELD__
                    items[1].label = get_string(STR_ID_UCM_END_ALL_HELD);
                    items[1].icon = get_image(IMG_ID_UCM_END); 
                    items[1].up = get_image(IMG_ID_UCM_RED_BUTTON_UP);            
                    items[1].down = get_image(IMG_ID_UCM_RED_BUTTON_DOWN);
                    items[1].disable = get_image(IMG_ID_UCM_RED_BUTTON_DISABLE);
                    items[1].handler = mmi_ucm_end_all_held_action;
#endif
#endif
                }

            }

        #ifdef __OP01__
        #ifdef __MMI_UCM_REJECT_BY_SMS__
            /* Reject by SMS */
            items[MT_icon_count].label = get_string(STR_ID_UCM_REJ_BY_SMS);
            items[MT_icon_count].icon = get_image(IMG_ID_UCM_REJECT_BY_SMS); 
            items[MT_icon_count].up = get_image(IMG_ID_UCM_NORMAL_BUTTON_UP);            
            items[MT_icon_count].down = get_image(IMG_ID_UCM_NORMAL_BUTTON_DOWN);
            items[MT_icon_count].disable = get_image(IMG_ID_UCM_NORMAL_BUTTON_DISABLE);
            items[MT_icon_count].handler = mmi_ucm_get_sms_template_action;   
            MT_icon_count ++;
        #endif /* __OP01__ && __MMI_UCM_REJECT_BY_SMS__ */

        #ifdef __MMI_VIDEO_TELEPHONY__
            /* Answer by voice */    
            items[MT_icon_count].label = get_string(STR_ID_UCM_ANSWER_BY_VOICE);
            items[MT_icon_count].icon = get_image(IMG_ID_UCM_ANSWER_BY_VOICE); 
            items[MT_icon_count].up = get_image(IMG_ID_UCM_NORMAL_BUTTON_UP);            
            items[MT_icon_count].down = get_image(IMG_ID_UCM_NORMAL_BUTTON_DOWN);
            items[MT_icon_count].disable = get_image(IMG_ID_UCM_NORMAL_BUTTON_DISABLE);
            items[MT_icon_count].handler = mmi_ucm_vt_incoming_call_answer_by_voice;           
        #endif /* __MMI_VIDEO_TELEPHONY__ */
        #endif /* __OP01__ */
           
        }
        break;
        
        case MMI_UCM_FTE_ICONBAR_OUTGOING_CALL:
        {
            /* Dialler */    
            items[0].label = get_string(STR_ID_UCM_DIALER);
            items[0].icon = get_image(IMG_ID_UCM_DIALLER); 
            items[0].up = get_image(IMG_ID_UCM_NORMAL_BUTTON_UP);            
            items[0].down = get_image(IMG_ID_UCM_NORMAL_BUTTON_DOWN);
            items[0].disable = get_image(IMG_ID_UCM_NORMAL_BUTTON_DISABLE);
            items[0].handler = mmi_ucm_pre_entry_dtmf_editor;

            /* Hand held/free */
            audio_mode = mdi_audio_get_audio_mode();
            items[1].label = get_string((audio_mode == AUD_MODE_LOUDSPK) ? (STR_ID_UCM_HAND_HELD) : (STR_ID_UCM_HAND_FREE));
            items[1].icon = get_image((audio_mode == AUD_MODE_LOUDSPK) ? (IMG_ID_UCM_HAND_HELD) : (IMG_ID_UCM_HAND_FREE));
            items[1].up = get_image(IMG_ID_UCM_NORMAL_BUTTON_UP);            
            items[1].down = get_image(IMG_ID_UCM_NORMAL_BUTTON_DOWN);
            items[1].disable = get_image(IMG_ID_UCM_NORMAL_BUTTON_DISABLE);
            items[1].handler = mmi_ucm_FTE_set_loudsp_during_MO_hdlr;         
        }
        break;
        
        case MMI_UCM_FTE_ICONBAR_IN_CALL:
        {
            if (number_of_items == 2)
            {
                /* Dialler */    
                items[0].label = get_string(STR_ID_UCM_DIALER);
                items[0].icon = get_image(IMG_ID_UCM_DIALLER); 
                items[0].up = get_image(IMG_ID_UCM_NORMAL_BUTTON_UP);            
                items[0].down = get_image(IMG_ID_UCM_NORMAL_BUTTON_DOWN);
                items[0].disable = get_image(IMG_ID_UCM_NORMAL_BUTTON_DISABLE);
                items[0].handler = mmi_ucm_pre_entry_dtmf_editor;

                /* End call */                
                items[1].icon = get_image(IMG_ID_UCM_END); 
                items[1].up = get_image(IMG_ID_UCM_RED_BUTTON_UP);            
                items[1].down = get_image(IMG_ID_UCM_RED_BUTTON_DOWN);
                items[1].disable = get_image(IMG_ID_UCM_RED_BUTTON_DISABLE);

                if (srv_ucm_query_group_data(g_ucm_p->call_misc.hilite_tab, NULL) > 1) 
                {
                    items[1].label = get_string(STR_ID_UCM_END_CONFERENCE);
                    items[1].handler = mmi_ucm_end_conference_action;
                }
                else
                {
                    items[1].label = get_string(STR_ID_UCM_END_CALL);
                    items[1].handler = mmi_ucm_end_single_action;
                }                
            }
            else if (number_of_items == 4)
            {
                call_count = srv_ucm_query_group_data(g_ucm_p->call_misc.hilite_tab, &group_info);
                group_count = srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD,MMI_FALSE, NULL);
                MMI_ASSERT(call_count > 0);
                /* Mute/unmute */
                items[0].label = get_string((srv_speech_is_phone_mute() == MMI_FALSE) ? (STR_GLOBAL_MUTE) : (STR_ID_UCM_UNMUTE));
                items[0].icon = get_image((srv_speech_is_phone_mute() == MMI_FALSE) ? (IMG_ID_UCM_MUTE) : (IMG_ID_UCM_UNMUTE));
                items[0].up = get_image(IMG_ID_UCM_NORMAL_BUTTON_UP);            
                items[0].down = get_image(IMG_ID_UCM_NORMAL_BUTTON_DOWN);
                items[0].disable = get_image(IMG_ID_UCM_NORMAL_BUTTON_DISABLE);
                items[0].handler = mmi_ucm_FTE_set_mute_unmute_hdlr;  

                /* hold/retrieve, conference/split */
                items[1].up = get_image(IMG_ID_UCM_NORMAL_BUTTON_UP);            
                items[1].down = get_image(IMG_ID_UCM_NORMAL_BUTTON_DOWN);
                items[1].disable = get_image(IMG_ID_UCM_NORMAL_BUTTON_DISABLE);
                
                /* Hold/retrieve for single active/held call group */
                /* Split/conference for >1 call group */
                if (1 == group_count)
                {
                    if (call_count > 1)
                    {
                        items[1].label = get_string(STR_ID_UCM_SPLIT);
                        items[1].icon = get_image(IMG_ID_UCM_SPLIT);
                        items[1].handler = mmi_ucm_split_action;
                    }
                    else
                    {
                        items[1].label = get_string((group_info.call_state == SRV_UCM_ACTIVE_STATE) ? (STR_ID_UCM_HOLD) : (STR_ID_UCM_RETRIEVE));
                        items[1].icon = get_image((group_info.call_state == SRV_UCM_ACTIVE_STATE) ? (IMG_ID_UCM_HOLD) : (IMG_ID_UCM_RETRIEVE));

                        if (SRV_UCM_ACTIVE_STATE == group_info.call_state)
                        {
                            items[1].handler = mmi_ucm_hold_action;
                        }
                        else if (SRV_UCM_HOLD_STATE == group_info.call_state)
                        {
                            items[1].handler = mmi_ucm_retrieve_action;
                        }
                        else
                        {
                            MMI_ASSERT(0);
                        }
                    }
                }
                /* conf for single call in one group, split for conference call */
                else if (group_count > 1)
                {
                    if (call_count > 1) 
                    {
                        items[1].label = get_string(STR_ID_UCM_SPLIT);
                        items[1].icon = get_image(IMG_ID_UCM_SPLIT);
                        items[1].handler = mmi_ucm_split_action;
                    }
                    else
                    {
                        items[1].label = get_string(STR_ID_UCM_CONFERENCE);
                        items[1].icon = get_image(IMG_ID_UCM_CONF);
                        items[1].handler = mmi_ucm_conference_action;
                    }                 
                }
                else
                {
                    MMI_ASSERT(0);
                }
                

                
                /* Dialler */    
                items[2].label = get_string(STR_ID_UCM_DIALER);
                items[2].icon = get_image(IMG_ID_UCM_DIALLER); 
                items[2].up = get_image(IMG_ID_UCM_NORMAL_BUTTON_UP);            
                items[2].down = get_image(IMG_ID_UCM_NORMAL_BUTTON_DOWN);
                items[2].disable = get_image(IMG_ID_UCM_NORMAL_BUTTON_DISABLE);
                items[2].handler = mmi_ucm_pre_entry_dtmf_editor;

                /* End call */              
                items[3].icon = get_image(IMG_ID_UCM_END); 
                items[3].up = get_image(IMG_ID_UCM_RED_BUTTON_UP);            
                items[3].down = get_image(IMG_ID_UCM_RED_BUTTON_DOWN);
                items[3].disable = get_image(IMG_ID_UCM_RED_BUTTON_DISABLE);

                if (call_count > 1) 
                {
                    items[3].label = get_string(STR_ID_UCM_END_CONFERENCE);
                    items[3].handler = mmi_ucm_end_conference_action;
                }
                else
                {
                    items[3].label = get_string(STR_ID_UCM_END_CALL);
                    items[3].handler = mmi_ucm_end_single_action;
                }                
            }
            else
            {
                MMI_ASSERT(0);
            }
         
        }
        break;
        
        default:
        {
            MMI_ASSERT(0);
        }
        break;
    }
}
#endif /*__MMI_UCM_FTE_SLIM_ICONBAR_PRESENT__*/

#ifndef __PXS_APP_ENABLE__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_FTE_scrn_update_hdlr_by_lock_state
 * DESCRIPTION
 *  to draw lock/unlock scrn and start autolock timer in call screen (MT/MO/INCALL) by given lock state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_FTE_scrn_update_hdlr_by_lock_state(mmi_ucm_auto_lock_state_enum lock_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (MMI_UCM_LOCK_STATE == lock_state)
    {
        wgui_catcall_fte_lock_screen(MMI_TRUE);        
    }
    else if (MMI_UCM_UNLOCK_STATE == lock_state)
    {
        wgui_catcall_fte_lock_screen(MMI_FALSE);
    }
    else if (MMI_UCM_WTL_STATE == lock_state)
    {
        wgui_catcall_fte_lock_screen(MMI_FALSE);
        StartTimer(UCM_FTE_AUTO_LOCK_TIMER_ID, MMI_UCM_FTE_AUTO_LOCK_TIMEOUT, mmi_ucm_FTE_auto_lock_timeout_hdlr);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_FTE_fill_unlock_item
 * DESCRIPTION
 *  fill lock item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_FTE_fill_unlock_item(wgui_catcall_fte_iconbar_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    item->label = get_string(STR_ID_UCM_TOUCH_TO_UNLOCK);
    item->icon = NULL; 
    item->up = get_image(IMG_ID_UCM_LOCK_ICON_UP);            
    item->down = get_image(IMG_ID_UCM_LOCK_ICON_DOWN);
    item->disable = NULL;
    item->handler = mmi_ucm_FTE_unlock_hdlr;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_FTE_unlock_hdlr
 * DESCRIPTION
 *  unlock call related screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_FTE_unlock_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_UCM_RSK_SUPPRESS_RING__) || defined(__MMI_FTE_SUPPORT__)
		MMI_ALERT_TYPE alert_type;
		U8 volume_level;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_auto_lock_fsm_hdlr(MMI_UCM_AL_UNLOCK_EVENT);
	
#if defined(__MMI_UCM_RSK_SUPPRESS_RING__) || defined(__MMI_FTE_SUPPORT__)
		alert_type = (MMI_ALERT_TYPE)g_ucm_p->full_mo_mt_display.mo_mt_display.alert_type;
	
		srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL, &volume_level);
		if (MDI_AUD_VOL_IS_MUTE_LEVEL(volume_level))
		{
			volume_level = volume_level & 0x0F;
		}
#endif
	
					
    /* Because the call screen does not change (lock=just redraw some region), so need updated and start timer */
    if (MMI_TRUE == mmi_ucm_FTE_is_lock_mechanism_applied_screens())
    {
        if (MMI_UCM_UNLOCK_STATE == mmi_ucm_get_auto_lock_state())
        {
        #if defined(__MMI_UCM_RSK_SUPPRESS_RING__) || defined(__MMI_FTE_SUPPORT__)
				/* decide if need to grey silence iconbar button */
				if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) &&
								((MMI_TRUE ==g_ucm_p->call_misc.is_ringtone_suppress) || (alert_type == SRV_PROF_ALERT_TYPE_SILENT) || (alert_type == SRV_PROF_ALERT_TYPE_INVALID) ||
								 ((SRV_PROF_ALERT_TYPE_RING == alert_type) && (0 == volume_level))))
				{
								wgui_catcall_fte_iconbar_enable_item(1, MMI_TRUE/* means disable */, get_string(STR_ID_UCM_SILENT), get_image(IMG_ID_UCM_SILENCE));
				}
        #endif
	
            wgui_catcall_fte_lock_screen(MMI_FALSE);
        }
        else if (MMI_UCM_WTL_STATE == mmi_ucm_get_auto_lock_state())
        {
            wgui_catcall_fte_lock_screen(MMI_FALSE);
            StartTimer(UCM_FTE_AUTO_LOCK_TIMER_ID, MMI_UCM_FTE_AUTO_LOCK_TIMEOUT, mmi_ucm_FTE_auto_lock_timeout_hdlr);        
        }
    }        
    else
    {
        /* unlock hdlr is impossible to called when not in lock screen, and lock screen only applied on MT/MO/INCALL */
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_FTE_auto_lock_timeout_hdlr
 * DESCRIPTION
 *  lock call related screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_FTE_auto_lock_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == mmi_ucm_FTE_is_lock_mechanism_applied_screens())
    {
        mmi_ucm_auto_lock_fsm_hdlr(MMI_UCM_AL_WTL_TIMEOUT_EVENT);
        /* Because the call screen does not change (lock=just redraw some region), so need updated and start timer */
        if (MMI_UCM_LOCK_STATE == mmi_ucm_get_auto_lock_state())
        {
            wgui_catcall_fte_lock_screen(MMI_TRUE);
        }
        else 
        {
           MMI_ASSERT(0);
        }
    }
    else
    {
        /* because when exit MO/MT/INCALL screen, the timer should be disalbed, so it's impossible to have auto lock timoutout case */
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_FTE_screen_touch_hdlr
 * DESCRIPTION
 *  when the iconbar or SK button is pressend in call screen, this api will be called
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_FTE_screen_touch_hdlr(MMI_BOOL is_touched)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_FALSE == mmi_ucm_FTE_is_lock_mechanism_applied_screens())
    {   
        MMI_ASSERT(0);
    }
    
    if (is_touched)
    {
        StopTimer(UCM_FTE_AUTO_LOCK_TIMER_ID);
    }
    else
    {
        if (MMI_UCM_WTL_STATE == mmi_ucm_get_auto_lock_state())
        {
            StartTimer(UCM_FTE_AUTO_LOCK_TIMER_ID, MMI_UCM_FTE_AUTO_LOCK_TIMEOUT, mmi_ucm_FTE_auto_lock_timeout_hdlr);        
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_FTE_is_lock_mechanism_applied_screens
 * DESCRIPTION
 *  check if the current screen is applied lock mechanism.
 * PARAMETERS
 *  void
 * RETURNS
 *  return MMI_TRUE means the screen support lock mechanism
 *****************************************************************************/
MMI_BOOL mmi_ucm_FTE_is_lock_mechanism_applied_screens(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 current_scrnID = mmi_frm_scrn_get_active_id();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((SCR_ID_UCM_OUTGOING == current_scrnID) ||
        (SCR_ID_UCM_INCOMING == current_scrnID) ||
        (SCR_ID_UCM_IN_CALL == current_scrnID))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;      
}
#endif /* __PXS_APP_ENABLE__ */

#ifdef __MMI_UCM_FTE_SLIM_ICONBAR_PRESENT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_FTE_suppress_incoming_tone_hdlr
 * DESCRIPTION
 *  suppress incoming tone handler (trigger when user press silence iconbar)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_FTE_suppress_incoming_tone_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_suppress_incoming_tone();
    /* update scrn */
                        
    if (MMI_TRUE ==g_ucm_p->call_misc.is_ringtone_suppress
		&& MMI_UCM_LOCK_STATE != mmi_ucm_get_auto_lock_state())
    {
        wgui_catcall_fte_iconbar_enable_item(1, MMI_TRUE/* means disable */, get_string(STR_ID_UCM_SILENT), get_image(IMG_ID_UCM_SILENCE));
    }    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_FTE_set_loudsp_during_MO_hdlr
 * DESCRIPTION
 *  set loudspeaker during MO handler (trigger when user press hand-held/free iconbar)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_FTE_set_loudsp_during_MO_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 label_id;
    U16 icon_id;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mdi_audio_get_audio_mode() == AUD_MODE_LOUDSPK) /* O */
    {
        srv_speech_disable_hand_free();
        label_id = STR_ID_UCM_HAND_FREE;
        icon_id = IMG_ID_UCM_HAND_FREE;
    }
    else 
    {
        srv_speech_enable_hand_free();
        label_id = STR_ID_UCM_HAND_HELD;
        icon_id = IMG_ID_UCM_HAND_HELD;
    } 
    /* update scrn */   
    wgui_catcall_fte_iconbar_set_item(1, get_string(label_id), get_image(icon_id));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_FTE_set_mute_unmute_hdlr
 * DESCRIPTION
 *  set mute/unmute (trigger when user press mute/unmute iconbar)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_FTE_set_mute_unmute_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 label_id;
    U16 icon_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == srv_speech_is_phone_mute())
    {
        srv_speech_unmute_phone();
        label_id = STR_GLOBAL_MUTE;
        icon_id = IMG_ID_UCM_MUTE;
        
    }
    else
    {
        srv_speech_mute_phone();
        label_id = STR_ID_UCM_UNMUTE;
        icon_id = IMG_ID_UCM_UNMUTE;
    }
    /* update scrn */   
    wgui_catcall_fte_iconbar_set_item(0, get_string(label_id), get_image(icon_id));
}
#endif /*__MMI_UCM_FTE_SLIM_ICONBAR_PRESENT__*/
#endif /* __MMI_FTE_SUPPORT__ */

/* ==================================================================================== */
/* =============VT related============================================================= */
/* ==================================================================================== */

#ifdef __MMI_VIDEO_TELEPHONY__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_enter_phb_handler
 * DESCRIPTION
 *  Funtion is called when phb menu item selected, 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_enter_phb_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_phb_launch();    
    
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_enter_msg_center_handler
 * DESCRIPTION
 *  Funtion is called when message center menu item selected, 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_ucm_vt_enter_msg_center_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    	#ifdef __UM_SUPPORT__
    mmi_um_entry_main_message_menu_with_check();
        #else
                mmi_sms_entry_main_message_menu();
	#endif
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_switch_to_voice_call_handler
 * DESCRIPTION
 *  Funtion is called when swith to voice call menu item selected, popup a confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_switch_to_voice_call_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
	arg.user_tag = (void *)MMI_UCM_CNF_VT_SWITCH_TO_VOICE_CALL;
    arg.f_enter_history = MMI_FALSE;
	arg.callback = (mmi_proc_func)mmi_ucm_cnf_popup_cb;
	mmi_confirm_display((WCHAR *)((UI_string_type) GetString(STR_ID_UCM_VT_SWTICH_TO_VOICE_CALL_QUERY)), MMI_EVENT_QUERY, &arg);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_switch_to_voice_call_confirm_yes
 * DESCRIPTION
 *  Funtion is called when user selects yes on "swith to voice call" confirm popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_switch_to_voice_call_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_dial_act_req_struct check_act_req;
    srv_ucm_result_enum check_result;
    srv_ucm_call_info_struct call_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get current active video call type and call number */
    memset(&check_act_req, 0, sizeof(srv_ucm_dial_act_req_struct));

    if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, g_ucm_p->call_misc.index_list) == 1)
    {
        if (srv_ucm_query_call_data(g_ucm_p->call_misc.index_list[0], &call_info))
        {
            check_act_req.call_type = mmi_ucm_convert_video_to_voice(call_info.uid_info.call_type);
        }
    }

    /* Don't care get return F or T*/
    /*if T, date is in check_act_req.num_uri, if F, already memset before, the data here is empty*/
    mmi_ucm_vt_get_remote_num_uri(check_act_req.num_uri, SRV_UCM_MAX_NUM_URI_LEN);

    check_act_req.is_ip_dial = MMI_FALSE;
    check_act_req.module_id = SRV_UCM_MODULE_ORIGIN_COMMON;
    
    check_act_req.phb_data = NULL;
    if ((check_result = srv_ucm_query_act_permit(SRV_UCM_END_ALL_AND_DIAL_ACT, &check_act_req)) == SRV_UCM_RESULT_OK)
    {
	    mmi_ucm_vt_set_is_switch_action(MMI_TRUE);
        mmi_ucm_vt_set_switch_call_type(check_act_req.call_type);
        srv_ucm_act_request(SRV_UCM_END_ALL_AND_DIAL_ACT, &check_act_req, NULL, mmi_ucm_act_callback);
    }
    else
    {	
        mmi_ucm_display_error_popup(check_result);
    }	 
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_switch_to_voice_call_confirm_no
 * DESCRIPTION
 *  Funtion is called when user selects no on "swith to voice call" confirm popup
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_switch_to_voice_call_confirm_no(void)
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
 *  mmi_ucm_vt_handle_incall_option
 * DESCRIPTION
 *  Handle incall option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_handle_incall_option(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL)  > 0)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_MAKE_VIDEO_CALL, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_SETTING, MMI_TRUE);

    #if defined(__MMI_BT_SUPPORT__)
        if ((srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)) == MMI_FALSE)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_HANDLE_INCALL_OPTION_BT_NOT_CONNECT);
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_SWITCH_AUDIO_PATH, MMI_TRUE);
        }        
        else if (g_ucm_p->vt_cntx.incall_screen.is_speaker_on == FALSE)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_HANDLE_INCALL_OPTION_SPEECH_OFF);
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_SWITCH_AUDIO_PATH, MMI_TRUE);
        }
        else
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_HANDLE_INCALL_OPTION_UNHIDE_SWITCH_AUDIO_PATH);
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_SWITCH_AUDIO_PATH, MMI_FALSE);
        }
    #else /* defined(__MMI_BT_SUPPORT__) */
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_SWITCH_AUDIO_PATH, MMI_TRUE);
    #endif /* defined(__MMI_BT_SUPPORT__) */
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_MAKE_VIDEO_CALL, MMI_FALSE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_SETTING, MMI_FALSE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_SWITCH_AUDIO_PATH, MMI_TRUE);
        cui_menu_set_non_leaf_item(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_SETTING, MMI_FALSE);
    }

    
    if (mmi_ucm_vt_get_camera_status() == TRUE)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_START_CAMERA, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_STOP_CAMERA, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_START_CAMERA, MMI_FALSE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_STOP_CAMERA, MMI_TRUE);
    }

#ifdef DUAL_CAMERA_SUPPORT
    if (mmi_ucm_vt_get_main_camera_status()== TRUE)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_USE_MAIN_CAMERA, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_USE_SUB_CAMERA, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_USE_SUB_CAMERA, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_USE_MAIN_CAMERA, MMI_FALSE);    
    }
#endif /* DUAL_CAMERA_SUPPORT */
    /* can not modify mic/speacker status when in preview mode */
    if (MMI_UCM_VT_INCALL_SCREEN_MODE_PREVIEW_ONLY == mmi_ucm_vt_get_incall_screen_mode())
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_UNMUTE_MIC, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_MUTE_MIC, MMI_TRUE);
    }
    else if (mmi_ucm_vt_get_mic_status() == MMI_TRUE)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_UNMUTE_MIC, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_MUTE_MIC, MMI_FALSE);      
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_UNMUTE_MIC, MMI_FALSE);  
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_MUTE_MIC, MMI_TRUE);
    }

    /* can not modify mic/speacker status when in preview mode */
    if (MMI_UCM_VT_INCALL_SCREEN_MODE_PREVIEW_ONLY == mmi_ucm_vt_get_incall_screen_mode())
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_UNMUTE_SPEAKER, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_MUTE_SPEAKER, MMI_TRUE);
    }
    else if (mmi_ucm_vt_get_speaker_status() == MMI_TRUE)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_UNMUTE_SPEAKER, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_MUTE_SPEAKER, MMI_FALSE); 
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_UNMUTE_SPEAKER, MMI_FALSE); 
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_MUTE_SPEAKER, MMI_TRUE);
    }    

    if (mmi_ucm_vt_get_hide_small_pic_status() == MMI_TRUE)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_HIDE_SMALL_PIC, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_UNHIDE_SMALL_PIC, MMI_FALSE);     
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_HIDE_SMALL_PIC, MMI_FALSE); 
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_UNHIDE_SMALL_PIC, MMI_TRUE);    
    }
    
    if (MMI_VT_NIGHT_MODE_OFF == mmi_ucm_vt_get_night_mode_status())
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_TURN_OFF_NIGHT_MODE, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_TURN_ON_NIGHT_MODE, MMI_FALSE);       
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_TURN_OFF_NIGHT_MODE, MMI_FALSE); 
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_TURN_ON_NIGHT_MODE, MMI_TRUE);     
    }
#if (defined (__MMI_SOUND_RECORDER__) && defined (__MMI_VIDEO_TELEPHONY__))
    if (mmi_ucm_sound_recorder_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPTION_SOUND_RECORDER, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPTION_SOUND_RECORDER, MMI_TRUE);
    }
#endif /* __MMI_SOUND_RECORDER__ */

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) > 0)
    {
    #if defined(__MMI_FILE_MANAGER__)
    #ifdef __DM_LAWMO_SUPPORT__
        if (srv_dm_lawmo_is_locked())
        {
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_ALT_PIC, MMI_TRUE);
        }
        else
    #endif /* __DM_LAWMO_SUPPORT__ */
        {
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_ALT_PIC, MMI_FALSE);
        #ifdef __OP01__
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_ALT_PIC_OFF, MMI_FALSE);
        #endif /* __OP01__ */
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_ALT_PIC_DEFAULT, MMI_FALSE);
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_ALT_PIC_USER_DEFINE, MMI_FALSE);
        }
    #endif /* __MMI_FILE_MANAGER__ */

        if (mmi_ucm_enter_general_app_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
        {
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_PHONEBOOK, MMI_FALSE);
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_MESSAGE_CENTER, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_PHONEBOOK, MMI_TRUE);
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_MESSAGE_CENTER, MMI_TRUE);
        }

    #ifndef __MMI_BACKGROUND_CALL__
    #if (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER)
        if (mmi_ucm_browser_option(MMI_UCM_PERMIT_ONLY) == SRV_UCM_RESULT_OK)
        {
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_BROWSER, MMI_FALSE);
        }
        else
        {
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_BROWSER, MMI_TRUE);
        }
    #endif /* #if (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER) */
    #endif /* __MMI_BACKGROUND_CALL__ */

        if (MMI_TRUE == mmi_ucm_vt_get_remote_num_uri(NULL, 0))
        {
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_SWTICH_TO_VOICE_CALL, MMI_FALSE); 
        }
        else
        {
            cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_SWTICH_TO_VOICE_CALL, MMI_TRUE);    
        }
    }
    else
    {
    #ifdef __MMI_FILE_MANAGER__
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_ALT_PIC, MMI_TRUE);
    #endif /* __MMI_FILE_MANAGER__ */
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_MESSAGE_CENTER, MMI_TRUE);  
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_PHONEBOOK, MMI_TRUE);
    #ifndef __MMI_BACKGROUND_CALL__
    #if (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER)
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_BROWSER, MMI_TRUE);
    #endif /* #if (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER) */
    #endif /* __MMI_BACKGROUND_CALL__ */
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_SWTICH_TO_VOICE_CALL, MMI_TRUE);  
    }

#ifdef __MMI_DUAL_MIC_SUPPORT__
    if (MMI_UCM_VT_INCALL_SCREEN_MODE_PREVIEW_ONLY == mmi_ucm_vt_get_incall_screen_mode())
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_ENABLE_NOICE_REDUCTION, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_DISABLE_NOICE_REDUCTION, MMI_TRUE);
    }
    else if (MMI_TRUE == mmi_ucm_get_dual_mic_nr_status())
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_ENABLE_NOICE_REDUCTION, MMI_TRUE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_DISABLE_NOICE_REDUCTION, MMI_FALSE);
    }
    else
    {
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_ENABLE_NOICE_REDUCTION, MMI_FALSE);
        cui_menu_set_item_hidden(owner_gid, MENU_ID_UCM_VT_INCALL_OPT_DISABLE_NOICE_REDUCTION, MMI_TRUE);
    }
#endif /* __MMI_DUAL_MIC_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_incall_opt_proc
 * DESCRIPTION
 *  The proc function of vt option
 *
 * PARAMETERS
 *  evt                     [IN]: event
 *  
 * RETURNS
 *  MMI_RET_OK: handle this event successfully
 *  Others: fail to handle this event
 *****************************************************************************/
mmi_ret mmi_ucm_vt_incall_opt_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;
    mmi_ret ret;
    MMI_BOOL opt_act_is_executed = MMI_FALSE;
    MMI_BOOL setting_act_is_executed = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;
    ret = MMI_RET_OK;

    /*CUI Menu close request event : send request to APP for closing the CUI menu instance */
    if (EVT_ID_CUI_MENU_CLOSE_REQUEST == menu_evt->evt_id)
    {
        if (menu_evt->sender_id == g_ucm_p->cui_info.vtincall_setting_cui_id)
        {
            g_ucm_p->cui_info.vtincall_setting_cui_id = GRP_ID_INVALID;
        }
        else if (menu_evt->sender_id == g_ucm_p->cui_info.vtincall_opt_cui_id)
        {
            g_ucm_p->cui_info.vtincall_opt_cui_id = GRP_ID_INVALID;
        }
        cui_menu_close(menu_evt->sender_id);
        
        return ret;
    }

    if (EVT_ID_CUI_MENU_LIST_ENTRY == menu_evt->evt_id)
    {
        switch(menu_evt->parent_menu_id)
        {   
            /* 0 , non-leaf */
            case MENU_ID_UCM_VT_INCALL_OPT:
            {
                /* Decide if need to hide each menu items */
                mmi_ucm_vt_handle_incall_option(menu_evt->sender_id);
            }
            break;

            case MENU_ID_UCM_VT_INCALL_OPT_SETTING:
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS); 
                
            #if defined(__MMI_FILE_MANAGER__)
            #ifdef __DM_LAWMO_SUPPORT__
                if (srv_dm_lawmo_is_locked())
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_UCM_VT_SETTING_INCALL_IMAGE, MMI_TRUE);
                #ifdef __OP01__
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_UCM_VT_SETTING_INCALL_REMOTE_IMAGE, MMI_TRUE);                 
                #endif /* __OP01__ */
                }
                else
            #endif /* __DM_LAWMO_SUPPORT__ */
                {
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_UCM_VT_SETTING_INCALL_IMAGE, MMI_FALSE);
                    mmi_ucm_vt_hint_setting_incall_pic(menu_evt->sender_id, MMI_UCM_VT_INCALL_PIC_TYPE_LOCAL_USER);
                #ifdef __OP01__  
                    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_UCM_VT_SETTING_INCALL_REMOTE_IMAGE, MMI_FALSE);  
                    mmi_ucm_vt_hint_setting_incall_pic(menu_evt->sender_id, MMI_UCM_VT_INCALL_PIC_TYPE_REMOTE_USER);                   
                #endif /* __OP01__ */
                }
            #endif /* defined(__MMI_FILE_MANAGER__) */

                cui_menu_set_non_leaf_item(menu_evt->sender_id, MENU_ID_UCM_VT_SETTING_AUDIO_OPT, MMI_TRUE);
            }
            break;
            
            case MENU_ID_UCM_VT_INCALL_OPT_ADVANCE_VIDEO_QUALITY:
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                if(menu_evt->cui_menu_event_flags != CUI_MENU_LIST_FROM_HISTORY)
                {
                    cui_menu_set_radio_list_item(menu_evt->sender_id,mmi_ucm_vt_convert_video_quality_to_menuid(mmi_ucm_vt_get_video_quality_status()));
                }
            }
            break;            
 
            case MENU_ID_UCM_VT_SETTING_ANSWER_MODE:
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                if(menu_evt->cui_menu_event_flags != CUI_MENU_LIST_FROM_HISTORY)
                {
                    cui_menu_set_radio_list_item(menu_evt->sender_id, mmi_ucm_vt_convert_answer_mode_to_menuid(mmi_ucm_vt_get_answer_mode()));
                }
            }
            break;    

            case MENU_ID_UCM_VT_SETTING_DIAL_MODE:
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                if(menu_evt->cui_menu_event_flags != CUI_MENU_LIST_FROM_HISTORY)
                {
                    cui_menu_set_radio_list_item(menu_evt->sender_id, mmi_ucm_vt_convert_dial_mode_to_menuid(mmi_ucm_vt_get_dial_mode()));
                }
            }
            break;   


#if (defined(__OP01__) || defined(__MMI_UCM_VT_ATUO_REDIAL_VOICE__))
            case MENU_ID_UCM_VT_SETTING_AUTO_REDIAL_MODE:
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_RADIO_BUTTON_LIST);
                if(menu_evt->cui_menu_event_flags != CUI_MENU_LIST_FROM_HISTORY)
                {   
                    cui_menu_set_radio_list_item(menu_evt->sender_id, mmi_ucm_vt_convert_auto_redial_mode_to_menuid(mmi_ucm_vt_get_auto_redial_mode()));
                }
            }
            break;   
#endif /* (defined(__OP01__) || defined(__MMI_UCM_VT_ATUO_REDIAL_VOICE__)) */


            case MENU_ID_UCM_VT_SETTING_AUDIO_OPT:
            {
                mmi_menu_id root_ids[MMI_UCM_VT_AUDIO_OPTION_TOTAL_NUM] = {MMI_UCM_VT_AUDIO_OPTION_MIC_OFF, MMI_UCM_VT_AUDIO_OPTION_SPEAKER_OFF};
                cui_menu_set_currlist(menu_evt->sender_id, MMI_UCM_VT_AUDIO_OPTION_TOTAL_NUM, root_ids);                
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_CHECK_BOX_LIST);
                cui_menu_set_item_string(menu_evt->sender_id,
                    MMI_UCM_VT_AUDIO_OPTION_MIC_OFF, (UI_string_type)GetString(STR_ID_UCM_VT_MIC_OFF));
                cui_menu_set_item_string(menu_evt->sender_id,
                    MMI_UCM_VT_AUDIO_OPTION_SPEAKER_OFF, (UI_string_type)GetString(STR_ID_UCM_VT_SPEAKER_OFF));
                
                cui_menu_set_checkbox_state(menu_evt->sender_id, (U8*) g_ucm_p->vt_cntx.setting.audio_opt);
                
            }
            break;

        #if defined(__MMI_FILE_MANAGER__)
            case MENU_ID_UCM_VT_INCALL_OPT_ALT_PIC: 
            case MENU_ID_UCM_VT_SETTING_INCALL_IMAGE:
        #ifdef __OP01__
            case MENU_ID_UCM_VT_SETTING_INCALL_REMOTE_IMAGE:
        #endif /* __OP01__ */
            {
                cui_menu_set_currlist_flags(menu_evt->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);    
            }
            break;   
        #endif /* __MMI_FILE_MANAGER__ */ 
        }

        return ret; 
    }                  

    /* When user press done in checkbox screen */
    if ((EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id) && 
         (menu_evt->parent_menu_id == MENU_ID_UCM_VT_SETTING_AUDIO_OPT))
    {
        cui_menu_get_checkbox_state(menu_evt->sender_id, (U8*) g_ucm_p->vt_cntx.setting.audio_opt);
        mmi_ucm_vt_entry_audio_opt_confirm();

        return ret;
    }
 
    
    switch(menu_evt->highlighted_menu_id)
    {
        /* 1st , leaf */
        case MENU_ID_UCM_VT_INCALL_OPT_MAKE_VIDEO_CALL:
        {
            if (EVT_ID_CUI_MENU_ITEM_HILITE == menu_evt->evt_id)     
            {
                if (mmi_is_redrawing_bk_screens() == TRUE)
                {
                    return ret;
                }
                memset(g_ucm_p->vt_cntx.mo_info.dial_pad_buffer, 0, sizeof(g_ucm_p->vt_cntx.mo_info.dial_pad_buffer));
            }
            else if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_enter_dialer_screen();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break;

        /* 1st , leaf */
        case MENU_ID_UCM_VT_INCALL_OPT_START_CAMERA:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_incall_opt_start_camera();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break;

        /* 1st , leaf */
        case MENU_ID_UCM_VT_INCALL_OPT_STOP_CAMERA:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_incall_opt_stop_camera();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break;
        
 #ifdef DUAL_CAMERA_SUPPORT     
        /* 1st , leaf */
        case MENU_ID_UCM_VT_INCALL_OPT_USE_MAIN_CAMERA:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_incall_opt_use_main_camera();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break;
        
        /* 1st , leaf */
        case MENU_ID_UCM_VT_INCALL_OPT_USE_SUB_CAMERA:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_incall_opt_use_sub_camera();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break;        
#endif /*DUAL_CAMERA_SUPPORT*/

        /* 1st , leaf */
        case MENU_ID_UCM_VT_INCALL_OPT_TURN_ON_NIGHT_MODE:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_incall_opt_turn_on_night_mode();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break;      

        /* 1st , leaf */
        case MENU_ID_UCM_VT_INCALL_OPT_TURN_OFF_NIGHT_MODE:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_incall_opt_turn_off_night_mode();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break;   

        /* 1st , leaf */
        case MENU_ID_UCM_VT_INCALL_OPT_MUTE_MIC:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_incall_opt_mute_mic();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break;   

        /* 1st , leaf */
        case MENU_ID_UCM_VT_INCALL_OPT_UNMUTE_MIC:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_incall_opt_unmute_mic();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break;   

        /* 1st , leaf */
        case MENU_ID_UCM_VT_INCALL_OPT_MUTE_SPEAKER:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_incall_opt_mute_speaker();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break;          

        /* 1st , leaf */
        case MENU_ID_UCM_VT_INCALL_OPT_UNMUTE_SPEAKER:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_incall_opt_unmute_speaker();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break;    

        /* 1st , leaf */
        case MENU_ID_UCM_VT_INCALL_OPT_SWITCH_PIC:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_incall_opt_switch_pic();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break; 

        /* 1st , leaf */
        case MENU_ID_UCM_VT_INCALL_OPT_HIDE_SMALL_PIC:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_incall_opt_hide_small_pic();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break; 

        /* 1st , leaf */
        case MENU_ID_UCM_VT_INCALL_OPT_UNHIDE_SMALL_PIC:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_incall_opt_unhide_small_pic();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break;

    #if defined(__MMI_FILE_MANAGER__)
    #ifdef __OP01__
        /* 2nd , leaf , (1st: MENU_ID_UCM_VT_INCALL_OPT_ALT_PIC) */
        case MENU_ID_UCM_VT_INCALL_OPT_ALT_PIC_OFF:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_set_incall_pic_off(MMI_UCM_VT_INCALL_PIC_TYPE_LOCAL_USER);
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break;
    #endif /* __OP01__ */

        /* 2nd , leaf , (1st: MENU_ID_UCM_VT_INCALL_OPT_ALT_PIC) */
        case MENU_ID_UCM_VT_INCALL_OPT_ALT_PIC_DEFAULT:    
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_set_incall_pic_default(MMI_UCM_VT_INCALL_PIC_TYPE_LOCAL_USER);
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break;

        /* 2nd , leaf , (1st: MENU_ID_UCM_VT_INCALL_OPT_ALT_PIC) */
        case MENU_ID_UCM_VT_INCALL_OPT_ALT_PIC_USER_DEFINE:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_entry_file_mgr_to_select_incall_pic(MMI_UCM_VT_INCALL_PIC_TYPE_LOCAL_USER);
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break;         
    #endif /* __MMI_FILE_MANAGER__ */    
        /* 1st , leaf */
        case MENU_ID_UCM_VT_INCALL_OPT_SWITCH_AUDIO_PATH:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_bt_set_audio_path();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break; 


    #if (defined (__MMI_SOUND_RECORDER__) && defined (__MMI_VIDEO_TELEPHONY__))
        /* 1st , leaf */
        case MENU_ID_UCM_VT_INCALL_OPTION_SOUND_RECORDER:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_sndrec_in_call_action();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break;      
    #endif /* __MMI_SOUND_RECORDER__ */
            
        /* 1st , leaf */
        case MENU_ID_UCM_VT_INCALL_OPT_PHONEBOOK:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_enter_phb_handler();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break; 

        /* 1st , leaf */
        case MENU_ID_UCM_VT_INCALL_OPT_MESSAGE_CENTER:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_enter_msg_center_handler();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break;

    #ifndef __MMI_BACKGROUND_CALL__
    #if (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER)
        /* 1st , leaf */
        case MENU_ID_UCM_VT_INCALL_OPT_BROWSER:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_enter_browser_incall_action();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break; 
    #endif /* (defined(__OP01_3G__) || defined(__OP02__)) && defined(OPERA_BROWSER) */
    #endif /* __MMI_BACKGROUND_CALL__ */

        /* 1st , leaf */
        case MENU_ID_UCM_VT_INCALL_OPT_SWTICH_TO_VOICE_CALL:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_switch_to_voice_call_handler();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break; 

        /* 1st , non-leaf */
        case MENU_ID_UCM_VT_INCALL_OPT_ADVANCE_VIDEO_QUALITY:
        {
            /* Display hint */
            if (EVT_ID_CUI_MENU_ITEM_HILITE == menu_evt->evt_id)    
            {
                mmi_ucm_vt_hint_advance_video_quality(menu_evt->sender_id);
            }
        }
        break; 
        
        /* 2nd, leaf , 1st is MENU_ID_UCM_VT_INCALL_OPT_ADVANCE_VIDEO_QUALITY */
        /* because use global menu id, not use enum, therefore can handle it here, no need to check parent_menu_id */
        case MENU_ID_UCM_VT_VIDEO_QUALITY_SMOOTH:
        {
            if (EVT_ID_CUI_MENU_ITEM_HILITE == menu_evt->evt_id)    
            {
                g_ucm_p->vt_cntx.incall_screen.curr_hilite_index = 0;
            }
            else if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_video_quality_done();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break; 
        
        /* 2nd, leaf, 1st is MENU_ID_UCM_VT_INCALL_OPT_ADVANCE_VIDEO_QUALITY */
        case MENU_ID_UCM_VT_VIDEO_QUALITY_NORMAL:
        {
            if (EVT_ID_CUI_MENU_ITEM_HILITE == menu_evt->evt_id)    
            {
                g_ucm_p->vt_cntx.incall_screen.curr_hilite_index = 1;
            }
            else if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_video_quality_done();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break; 

        /* 2nd, leaf, 1st is MENU_ID_UCM_VT_INCALL_OPT_ADVANCE_VIDEO_QUALITY */
        case MENU_ID_UCM_VT_VIDEO_QUALITY_SHARP:
        {
            if (EVT_ID_CUI_MENU_ITEM_HILITE == menu_evt->evt_id)    
            {
                g_ucm_p->vt_cntx.incall_screen.curr_hilite_index = 2;
            }
            else if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_video_quality_done();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break; 

         /* 2nd , leaf */
        case MENU_ID_UCM_VT_INCALL_OPT_SETTING:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_enter_setting_handler();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break;        

        /*  -----settings menu cui (sub_app type) -- */
        /* 2nd, leaf , 1st is MENU_ID_UCM_VT_SETTING_ANSWER_MODE */
        case MENU_ID_UCM_VT_SETTING_ANSWER_MODE_PROMPT:
        {
            if (EVT_ID_CUI_MENU_ITEM_HILITE == menu_evt->evt_id)    
            {
                g_ucm_p->vt_cntx.setting.curr_hilite_index = 0;
            }
            else if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_handle_set_answer_mode();
                setting_act_is_executed = MMI_TRUE;
            }
        }
        break; 

        /* 2nd, leaf , 1st is MENU_ID_UCM_VT_SETTING_ANSWER_MODE */
        case MENU_ID_UCM_VT_SETTING_ANSWER_MODE_START_CAMERA:
        {
            if (EVT_ID_CUI_MENU_ITEM_HILITE == menu_evt->evt_id)    
            {
                g_ucm_p->vt_cntx.setting.curr_hilite_index = 1;
            }
            else if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_handle_set_answer_mode();
                setting_act_is_executed = MMI_TRUE;
            }
        }
        break; 
        
        /* 2nd, leaf , 1st is MENU_ID_UCM_VT_SETTING_ANSWER_MODE */
        case MENU_ID_UCM_VT_SETTING_ANSWER_MODE_STOP_CAMERA:
        {
            if (EVT_ID_CUI_MENU_ITEM_HILITE == menu_evt->evt_id)    
            {
                g_ucm_p->vt_cntx.setting.curr_hilite_index = 2;
            }
            else if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_handle_set_answer_mode();
                setting_act_is_executed = MMI_TRUE;
            }
        }
        break; 

        /* 2nd, leaf , 1st is MENU_ID_UCM_VT_SETTING_DIAL_MODE */
        case MENU_ID_UCM_VT_SETTING_DIAL_MODE_START_CAMERA:
        {
            if (EVT_ID_CUI_MENU_ITEM_HILITE == menu_evt->evt_id)    
            {
                g_ucm_p->vt_cntx.setting.curr_hilite_index = 0;
            }
            else if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_handle_set_dial_mode();
                setting_act_is_executed = MMI_TRUE;
            }
        }
        break; 

        /* 2nd, leaf , 1st is MENU_ID_UCM_VT_SETTING_DIAL_MODE */
        case MENU_ID_UCM_VT_SETTING_DIAL_MODE_STOP_CAMERA:
        {
            if (EVT_ID_CUI_MENU_ITEM_HILITE == menu_evt->evt_id)    
            {
                g_ucm_p->vt_cntx.setting.curr_hilite_index = 1;
            }
            else if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_handle_set_dial_mode();
                setting_act_is_executed = MMI_TRUE;
            }
        }
        break;       
        
#if (defined(__OP01__) || defined(__MMI_UCM_VT_ATUO_REDIAL_VOICE__))
        /* 2nd, leaf , 1st is MENU_ID_UCM_VT_SETTING_AUTO_REDIAL_MODE */
        case MENU_ID_UCM_VT_SETTING_AUTO_REDIAL_MODE_MANUAL:
        {
            if (EVT_ID_CUI_MENU_ITEM_HILITE == menu_evt->evt_id)    
            {
                g_ucm_p->vt_cntx.setting.curr_hilite_index = 0;
            }
            else if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_handle_set_auto_redial_mode();
                setting_act_is_executed = MMI_TRUE;
            }
        }
        break; 
        
        /* 2nd, leaf , 1st is MENU_ID_UCM_VT_SETTING_AUTO_REDIAL_MODE */
        case MENU_ID_UCM_VT_SETTING_AUTO_REDIAL_MODE_ON:
        {
            if (EVT_ID_CUI_MENU_ITEM_HILITE == menu_evt->evt_id)    
            {
                g_ucm_p->vt_cntx.setting.curr_hilite_index = 1;
            }
            else if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_handle_set_auto_redial_mode();
                setting_act_is_executed = MMI_TRUE;
            }
        }
        break; 

        /* 2nd, leaf , 1st is MENU_ID_UCM_VT_SETTING_AUTO_REDIAL_MODE */
        case MENU_ID_UCM_VT_SETTING_AUTO_REDIAL_MODE_OFF:
        {
            if (EVT_ID_CUI_MENU_ITEM_HILITE == menu_evt->evt_id)    
            {
                g_ucm_p->vt_cntx.setting.curr_hilite_index = 2;
            }
            else if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_handle_set_auto_redial_mode();
                setting_act_is_executed = MMI_TRUE;
            }
        }
        break;
#endif /* (defined(__OP01__) || defined(__MMI_UCM_VT_ATUO_REDIAL_VOICE__)) */

    #if defined(__MMI_FILE_MANAGER__)
    #ifdef __OP01__
        /* 2nd , leaf , (1st: MENU_ID_UCM_VT_SETTING_INCALL_IMAGE) */
        case MENU_ID_UCM_VT_SETTING_INCALL_IMAGE_OFF:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)
            {
                mmi_ucm_vt_set_incall_pic_off(MMI_UCM_VT_INCALL_PIC_TYPE_LOCAL_USER);
                setting_act_is_executed = MMI_TRUE;
            }
        }
        break;
    #endif /* __OP01__ */

        /* 2nd , leaf , (1st: MENU_ID_UCM_VT_SETTING_INCALL_IMAGE) */
        case MENU_ID_UCM_VT_SETTING_INCALL_IMAGE_DEFAULT:    
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_set_incall_pic_default(MMI_UCM_VT_INCALL_PIC_TYPE_LOCAL_USER);
                setting_act_is_executed = MMI_TRUE;
            }
        }
        break;

        /* 2nd , leaf , (1st: MENU_ID_UCM_VT_SETTING_INCALL_IMAGE) */
        case MENU_ID_UCM_VT_SETTING_INCALL_IMAGE_USER_DEFINE:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_entry_file_mgr_to_select_incall_pic(MMI_UCM_VT_INCALL_PIC_TYPE_LOCAL_USER);
                setting_act_is_executed = MMI_TRUE;
            }
        }
        break;

    #ifdef __OP01__
        /* 2nd , leaf , (1st: MENU_ID_UCM_VT_SETTING_INCALL_REMOTE_IMAGE) */
        case MENU_ID_UCM_VT_SETTING_INCALL_REMOTE_IMAGE_DEFAULT:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_set_incall_pic_default(MMI_UCM_VT_INCALL_PIC_TYPE_REMOTE_USER);
                setting_act_is_executed = MMI_TRUE;
            }
        }
        break;

        /* 2nd , leaf , (1st: MENU_ID_UCM_VT_SETTING_INCALL_REMOTE_IMAGE) */
        case MENU_ID_UCM_VT_SETTING_INCALL_REMOTE_IMAGE_USER_DEFINE:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)    
            {
                mmi_ucm_vt_entry_file_mgr_to_select_incall_pic(MMI_UCM_VT_INCALL_PIC_TYPE_REMOTE_USER);
                setting_act_is_executed = MMI_TRUE;
            }
        }
        break;
    #endif /* __OP01__ */
    #endif /* __MMI_FILE_MANAGER__ */
    
    #ifdef __MMI_DUAL_MIC_SUPPORT__
        case MENU_ID_UCM_VT_INCALL_OPT_ENABLE_NOICE_REDUCTION:
        case MENU_ID_UCM_VT_INCALL_OPT_DISABLE_NOICE_REDUCTION:
        {
            if (EVT_ID_CUI_MENU_ITEM_SELECT == menu_evt->evt_id)
            {
                mmi_ucm_noice_reduction_action();
                opt_act_is_executed = MMI_TRUE;
            }
        }
        break;      
    #endif /* __MMI_DUAL_MIC_SUPPORT__ */
        
    }
 
    /* close menu cui after user selects any leave item */
    if (opt_act_is_executed)
    {
        mmi_ucm_close_cui(&g_ucm_p->cui_info.vtincall_opt_cui_id);
    }

    if (setting_act_is_executed)
    {
        mmi_ucm_close_cui(&g_ucm_p->cui_info.vtincall_setting_cui_id);
    }
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_entry_incall_option
 * DESCRIPTION
 *  Shows the incall option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_entry_incall_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Only for engineering mode, it is a temp solution, need to review the flow.
       The video call screen is create by GRP_ID_EM_PROFILING_VTCS_LOOK_BACK in this case */
    if (!mmi_frm_group_is_present(GRP_ID_UCM_VT))
    {
        mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_UCM_VT, mmi_ucm_vt_sg_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    } 

    /* mmi_ucm_vt_incall_opt_proc */
    /* create menu cui */
    g_ucm_p->cui_info.vtincall_opt_cui_id = cui_menu_create(
                            GRP_ID_UCM_VT, 
                            CUI_MENU_SRC_TYPE_RESOURCE, 
                            CUI_MENU_TYPE_OPTION, 
                            MENU_ID_UCM_VT_INCALL_OPT, 
                            MMI_FALSE, /* Use global resource */
                            NULL);

#ifndef __COSMOS_MMI_PACKAGE__
    cui_menu_set_default_title_image_by_id(g_ucm_p->cui_info.vtincall_opt_cui_id, GetRootTitleIcon(MENU_ID_UCM_VT_MAIN));
#endif /* __COSMOS_MMI_PACKAGE__ */
    cui_menu_run(g_ucm_p->cui_info.vtincall_opt_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_enter_setting_handler
 * DESCRIPTION
 *  Enter vt call setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_enter_setting_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* mmi_ucm_vt_incall_opt_proc */
    /* create menu cui */
    g_ucm_p->cui_info.vtincall_setting_cui_id = cui_menu_create(
                            GRP_ID_UCM_VT, 
                            CUI_MENU_SRC_TYPE_RESOURCE, 
                            CUI_MENU_TYPE_APPSUB, 
                            MENU_ID_UCM_VT_INCALL_OPT_SETTING, 
                            MMI_FALSE, /* Use global resource */
                            NULL);
    
    cui_menu_set_default_left_softkey(g_ucm_p->cui_info.vtincall_setting_cui_id, get_string(STR_GLOBAL_SELECT));
#ifndef __COSMOS_MMI_PACKAGE__
    cui_menu_set_default_title_image_by_id(g_ucm_p->cui_info.vtincall_setting_cui_id, GetRootTitleIcon(MENU_ID_UCM_VT_MAIN));
#endif /* __COSMOS_MMI_PACKAGE__ */
    //cui_menu_enable_cascading_option_menu(g_ucm_p->cui_info.vtincall_opt_cui_id);
    
    cui_menu_run(g_ucm_p->cui_info.vtincall_setting_cui_id);    

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_enter_dialer_screen
 * DESCRIPTION
 *  Enter vt dialer screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_enter_dialer_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_VT, SCR_ID_UCM_VT_DIALER, 
        (FuncPtr)mmi_ucm_vt_entry_dialer_screen, 
        (void*)NULL);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_entry_dialer_screen
 * DESCRIPTION
 *  vt dialer screen entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_entry_dialer_screen(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    srv_ucm_call_type_enum call_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_VT_DIALER,
                    NULL,
                    (FuncPtr)mmi_ucm_vt_entry_dialer_screen,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }
    

    guiBuffer = mmi_frm_scrn_get_gui_buf(scr_info->group_id, SCR_ID_UCM_VT_DIALER);

    EnableCenterSoftkey(0, IMG_GLOBAL_CALL_CSK);
    call_type = mmi_ucm_vt_get_valid_video_call_type();

#ifdef  __MMI_TOUCH_SCREEN__
#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)
    SetDialingKeypadPhonebookHandler(mmi_ucm_launch_phb_app);

#ifdef __MMI_CAT_VIDEO_CALL__
    if (MMI_TRUE == srv_ucm_is_call_srv_available(SRV_UCM_VIDEO_CALL_TYPE_ALL))
    {
        SetDialingKeypadVideoHandler(mmi_ucm_vt_dialer_make_vt);
    }
#else /* __MMI_CAT_VIDEO_CALL__ */
    if ((SRV_UCM_VIDEO_CALL_TYPE & call_type) &&
         MMI_TRUE == srv_ucm_is_call_srv_available(SRV_UCM_VIDEO_CALL_TYPE))
    {
        SetDialingKeypadCallHandler(mmi_ucm_vt_dialer_make_vt_sim1);
    }
#if (MMI_MAX_SIM_NUM == 2)
    if ((SRV_UCM_VIDEO_CALL_TYPE_SIM2 & call_type) &&
         MMI_TRUE == srv_ucm_is_call_srv_available(SRV_UCM_VIDEO_CALL_TYPE_SIM2))
    {
        SetDialingKeypadCall2Handler(mmi_ucm_vt_dialer_make_vt_sim2);
    }
#endif /* (MMI_MAX_SIM_NUM == 2) */
#endif /* __MMI_CAT_VIDEO_CALL__ */
#endif/*__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__*/
#endif /* __MMI_TOUCH_SCREEN__ */

    ShowCategory16Screen(
        STR_GLOBAL_DIAL,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (U8*) g_ucm_p->vt_cntx.mo_info.dial_pad_buffer,
        (MMI_UCM_VT_DTMF_LEN + 1),
        guiBuffer);

    
    SetLeftSoftkeyFunction(mmi_ucm_vt_dialer_make_vt, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_ucm_vt_dialer_make_vt, KEY_EVENT_UP);
    SetCategory16RightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP); 

    SetKeyDownHandler(mmi_ucm_vt_dialer_make_vt, KEY_SEND);    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_dialer_make_vt
 * DESCRIPTION
 *  Dial video call from dialer screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_dialer_make_vt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_vt_dialer_make_vt_by_call_type(mmi_ucm_vt_get_valid_video_call_type());
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_dialer_make_vt_sim1
 * DESCRIPTION
 *  Dial SIM1 video call from dialer screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_dialer_make_vt_sim1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_vt_get_valid_video_call_type() & SRV_UCM_VIDEO_CALL_TYPE)
    {
        mmi_ucm_vt_dialer_make_vt_by_call_type(SRV_UCM_VIDEO_CALL_TYPE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_dialer_make_vt_sim2
 * DESCRIPTION
 *  Dial SIM2 video call from dialer screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_dialer_make_vt_sim2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_vt_get_valid_video_call_type() & SRV_UCM_VIDEO_CALL_TYPE_SIM2)
    {
        mmi_ucm_vt_dialer_make_vt_by_call_type(SRV_UCM_VIDEO_CALL_TYPE_SIM2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_dialer_make_vt_by_call_type
 * DESCRIPTION
 *  Dial video call by call type from dialer screen
 * PARAMETERS
 *  call_type      [IN]      Call type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_dialer_make_vt_by_call_type(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct make_call_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_init_call_para(&make_call_para);
    make_call_para.dial_type = call_type;
    make_call_para.ucs2_num_uri = (U16*)g_ucm_p->vt_cntx.mo_info.dial_pad_buffer;
    mmi_ucm_call_launch(0, &make_call_para);
	mmi_frm_scrn_close(GRP_ID_UCM_VT, SCR_ID_UCM_VT_DIALER);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_incall_opt_start_camera
 * DESCRIPTION
 *  turn on camera and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_incall_opt_start_camera(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif/*__MMI_BACKGROUND_CALL__*/
    mmi_ucm_vt_set_camera_status(MMI_TRUE);

    /* If the local image displays in small region, unhide small image */
    if (mmi_ucm_vt_get_pic_switch_status() == MMI_FALSE)
    {
        mmi_ucm_vt_set_hide_small_pic_status(MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_incall_opt_stop_camera
 * DESCRIPTION
 *  turn off camera and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_incall_opt_stop_camera(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif/* __MMI_BACKGROUND_CALL__ */
    mmi_ucm_vt_set_camera_status(MMI_FALSE);
}


#ifdef DUAL_CAMERA_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_incall_opt_use_main_camera
 * DESCRIPTION
 *  set using main camera and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_incall_opt_use_main_camera(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif/* __MMI_BACKGROUND_CALL__ */
    
    mmi_ucm_vt_set_main_camera_status(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_incall_opt_use_sub_camera
 * DESCRIPTION
 *  set using sub camera and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_incall_opt_use_sub_camera(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif/* __MMI_BACKGROUND_CALL__ */
    
    mmi_ucm_vt_set_main_camera_status(MMI_FALSE);
}
#endif /* DUAL_CAMERA_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_incall_opt_turn_on_night_mode
 * DESCRIPTION
 *  turn on night mode and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_incall_opt_turn_on_night_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_vt_set_night_mode_status(MMI_VT_NIGHT_MODE_ON);

    mmi_ucm_close_cui(&g_ucm_p->cui_info.vtincall_opt_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_incall_opt_turn_off_night_mode
 * DESCRIPTION
 *  turn off night mode and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_incall_opt_turn_off_night_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_vt_set_night_mode_status(MMI_VT_NIGHT_MODE_OFF);

    mmi_ucm_close_cui(&g_ucm_p->cui_info.vtincall_opt_cui_id);
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_incall_opt_mute_mic
 * DESCRIPTION
 *  mute mic and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_incall_opt_mute_mic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif/* __MMI_BACKGROUND_CALL__ */
    mmi_ucm_vt_set_mic_status(MMI_FALSE);
     
    mmi_ucm_close_cui(&g_ucm_p->cui_info.vtincall_opt_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_incall_opt_unmute_mic
 * DESCRIPTION
 *  unmute mic and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_incall_opt_unmute_mic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif/* __MMI_BACKGROUND_CALL__ */
    mmi_ucm_vt_set_mic_status(MMI_TRUE);

    mmi_ucm_close_cui(&g_ucm_p->cui_info.vtincall_opt_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_incall_opt_mute_speaker
 * DESCRIPTION
 *  mute speaker and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_incall_opt_mute_speaker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif/* __MMI_BACKGROUND_CALL__ */
    mmi_ucm_vt_set_speaker_status(MMI_FALSE);

    mmi_ucm_close_cui(&g_ucm_p->cui_info.vtincall_opt_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_incall_opt_unmute_speaker
 * DESCRIPTION
 *  unmute speaker and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_incall_opt_unmute_speaker(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif/* __MMI_BACKGROUND_CALL__ */
    mmi_ucm_vt_set_speaker_status(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_incall_opt_switch_pic
 * DESCRIPTION
 *  switch pic and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_incall_opt_switch_pic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_ucm_vt_get_pic_switch_status() == MMI_TRUE)
    {
        mmi_ucm_vt_set_pic_switch_status(MMI_FALSE);
    }
    else
    {
        mmi_ucm_vt_set_pic_switch_status(MMI_TRUE);
    }  
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_incall_opt_hide_small_pic
 * DESCRIPTION
 *  hide small picture and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_incall_opt_hide_small_pic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_vt_set_hide_small_pic_status(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_incall_opt_unhide_small_pic
 * DESCRIPTION
 *  Unhide small picture and go back to incall screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_incall_opt_unhide_small_pic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_vt_set_hide_small_pic_status(MMI_FALSE);
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_hint_advance_brightness
 * DESCRIPTION
 *  To construct hint popup for brightness setting
 *  
 * PARAMETERS
 *  index       [IN]        Of the current menu item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_hint_advance_brightness(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value[MAX_SUB_MENU_HINT_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* reinitialize the hint data */
    memset(hintData[index], 0, sizeof(hintData[index]));

    sprintf((char*)value, "%d", g_ucm_p->vt_cntx.incall_screen.ev);
    mmi_asc_to_ucs2((CHAR*)hintData[index], (CHAR*)value);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_hint_advance_video_quality
 * DESCRIPTION
 *  To construct hint popup for video quality
 *  
 * PARAMETERS
 *  sender_id       [IN]        current sender id
 * RETURNS
 *  void
 *****************************************************************************/ 
void mmi_ucm_vt_hint_advance_video_quality(MMI_ID sender_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* reinitialize the hint data */
    switch (g_ucm_p->vt_cntx.incall_screen.video_quality)
    {
        case MMI_VT_VIDEO_QUALITY_SMOOTH:
        {            
            cui_menu_set_item_hint(
                                    sender_id, 
                                    MENU_ID_UCM_VT_INCALL_OPT_ADVANCE_VIDEO_QUALITY, 
                                    (UI_string_type)GetString(STR_ID_UCM_VT_SMOOTH));
        }
        break;

        case MMI_VT_VIDEO_QUALITY_NORMAL:
        {
            cui_menu_set_item_hint(
                                    sender_id, 
                                    MENU_ID_UCM_VT_INCALL_OPT_ADVANCE_VIDEO_QUALITY, 
                                    (UI_string_type)GetString(STR_ID_UCM_VT_NORMAL));
        }
        break;        

        case MMI_VT_VIDEO_QUALITY_SHARP:
        {
            cui_menu_set_item_hint(
                                    sender_id, 
                                    MENU_ID_UCM_VT_INCALL_OPT_ADVANCE_VIDEO_QUALITY, 
                                    (UI_string_type)GetString(STR_ID_UCM_VT_SHARP));
        }
        break;        

        default:
        {
            MMI_ASSERT(0);
        }
        break;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_video_quality_done
 * DESCRIPTION
 *  Set video quality
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_video_quality_done(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_VIDEO_QUALITY_DONE, g_ucm_p->vt_cntx.incall_screen.curr_hilite_index);

    mmi_ucm_vt_set_video_quality_status((mmi_vt_video_quality_enum)g_ucm_p->vt_cntx.incall_screen.curr_hilite_index);
    
    mmi_popup_display_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, NULL);
    /* the menu CUI will be deleted by itself after user select one of items */
}

    
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_hint_setting_alt_incall_pic
 * DESCRIPTION
 *  To construct hint popup for incall image setting
 * NA
 *  
 * PARAMETERS
 *  index       [IN]        Of the current menu item
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_hint_setting_alt_incall_pic(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* reinitialize the hint data */
    memset(hintData[index], 0, sizeof(hintData[index]));
#ifdef __OP01__
    if (MMI_FALSE == g_ucm_p->vt_cntx.setting.incall_image_state[MMI_UCM_VT_INCALL_PIC_TYPE_LOCAL_USER])
    {
        mmi_ucs2ncpy((CHAR*)hintData[index], (CHAR*)GetString(STR_GLOBAL_OFF), (MAX_SUB_MENU_HINT_SIZE / ENCODING_LENGTH) - 1);
    }
    else
#endif /* __OP01__ */
    if (mmi_ucs2strlen((CHAR*)g_ucm_p->vt_cntx.setting.incall_image_file_path[MMI_UCM_VT_INCALL_PIC_TYPE_LOCAL_USER]) == 0)
    {
        mmi_ucs2ncpy((CHAR*)hintData[index], (CHAR*)GetString(STR_ID_UCM_VT_DEFAULT), (MAX_SUB_MENU_HINT_SIZE / ENCODING_LENGTH) - 1);
    }
    else
    {
        mmi_ucs2ncpy((CHAR*)hintData[index], 
                     (CHAR*)mmi_ucm_vt_get_file_name((U16*)g_ucm_p->vt_cntx.setting.incall_image_file_path[MMI_UCM_VT_INCALL_PIC_TYPE_LOCAL_USER]), 
                     (MAX_SUB_MENU_HINT_SIZE / ENCODING_LENGTH) - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_setting_get_hilite_index
 * DESCRIPTION
 *  Get current highlight index
 * PARAMETERS
 *  nIndex      [IN]        Current highlight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_setting_get_hilite_index(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->vt_cntx.setting.curr_hilite_index = (U16)index;
}


void mmi_ucm_vt_handle_set_answer_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, NULL);
    mmi_ucm_vt_set_answer_mode((mmi_ucm_vt_answer_mode_enum)(g_ucm_p->vt_cntx.setting.curr_hilite_index));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_handle_set_dial_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_handle_set_dial_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_popup_display_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, NULL);
    mmi_ucm_vt_set_dial_mode((mmi_ucm_vt_dial_mode_enum)(g_ucm_p->vt_cntx.setting.curr_hilite_index));

}


#if (defined(__OP01__) || defined(__MMI_UCM_VT_ATUO_REDIAL_VOICE__))
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_handle_set_auto_redial_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_handle_set_auto_redial_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_popup_display_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, NULL); 
    mmi_ucm_vt_set_auto_redial_mode(g_ucm_p->vt_cntx.setting.curr_hilite_index);
}
#endif /* (defined(__OP01__) || defined(__MMI_UCM_VT_ATUO_REDIAL_VOICE__)) */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_entry_audio_opt_confirm
 * DESCRIPTION
 *  Confirmation to save audio option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_entry_audio_opt_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
	arg.user_tag = (void *)MMI_UCM_CNF_VT_AUDIO_OPT;
    arg.f_enter_history = MMI_FALSE;
	arg.callback = (mmi_proc_func)mmi_ucm_cnf_popup_cb;
	mmi_confirm_display((WCHAR *)((UI_string_type) GetString(STR_GLOBAL_SAVE_ASK)), MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_audio_opt_confirm_yes
 * DESCRIPTION
 *  Confirm to save audio option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_audio_opt_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 errorCode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ucm_p->vt_cntx.setting.is_mic_off = (MMI_BOOL)(g_ucm_p->vt_cntx.setting.audio_opt[MMI_UCM_VT_AUDIO_OPTION_MIC_OFF]);
    g_ucm_p->vt_cntx.setting.is_speaker_off = (MMI_BOOL)(g_ucm_p->vt_cntx.setting.audio_opt[MMI_UCM_VT_AUDIO_OPTION_SPEAKER_OFF]);

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_AUDIO_OPT_CONFIRM_YES, g_ucm_p->vt_cntx.setting.is_mic_off, g_ucm_p->vt_cntx.setting.is_speaker_off);
    mmi_popup_display_ext(STR_GLOBAL_SAVED, MMI_EVENT_SUCCESS, NULL); 
    WriteValue(NVRAM_VT_AUDIO_OPT_MIC, &(g_ucm_p->vt_cntx.setting.is_mic_off), DS_BYTE, &errorCode);
    WriteValue(NVRAM_VT_AUDIO_OPT_SPEAKER, &(g_ucm_p->vt_cntx.setting.is_speaker_off), DS_BYTE, &errorCode);
    /* sync to incall_status for vtcs screen display */
    if (g_ucm_p->vt_cntx.setting.is_mic_off)
    {
        mmi_ucm_vt_set_mic_status(MMI_FALSE);
    }
    else
    {
        mmi_ucm_vt_set_mic_status(MMI_TRUE);
    }

    if (g_ucm_p->vt_cntx.setting.is_speaker_off)
    {
        mmi_ucm_vt_set_speaker_status(MMI_FALSE);
    }
    else
    {
        mmi_ucm_vt_set_speaker_status(MMI_TRUE);
    }

    mmi_ucm_close_cui(&g_ucm_p->cui_info.vtincall_setting_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_audio_opt_confirm_no
 * DESCRIPTION
 *  Cancel to save audio option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_audio_opt_confirm_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_AUDIO_OPT_CONFIRM_NO);
    mmi_ucm_close_cui(&g_ucm_p->cui_info.vtincall_setting_cui_id);
    g_ucm_p->vt_cntx.setting.audio_opt[MMI_UCM_VT_AUDIO_OPTION_MIC_OFF] = g_ucm_p->vt_cntx.setting.is_mic_off;
    g_ucm_p->vt_cntx.setting.audio_opt[MMI_UCM_VT_AUDIO_OPTION_SPEAKER_OFF] = g_ucm_p->vt_cntx.setting.is_speaker_off;
}


#if defined(__MMI_FILE_MANAGER__)
#ifdef __OP01__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_set_incall_pic_off
 * DESCRIPTION
 *  Set alt incall pic state to default
 * PARAMETERS
 *  pic_type       [IN] picture type, local or remote
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_set_incall_pic_off(mmi_ucm_vt_incall_pic_type_enum pic_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_SET_INCALL_PIC_OFF);

    mmi_ucm_vt_set_incall_pic(NULL, pic_type);

    if (MMI_UCM_VT_INCALL_PIC_TYPE_LOCAL_USER == pic_type)
    {
        mmi_ucm_vt_set_camera_status(MMI_TRUE);
    }

    /* go back to incall screen if during in-call */
    if (g_ucm_p->cui_info.vtincall_opt_cui_id == GRP_ID_INVALID)
    {
        mmi_popup_display_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, NULL);
    }
}
#endif /* __OP01__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_set_incall_pic_default
 * DESCRIPTION
 *  Set alt incall pic to default
 * PARAMETERS
 *  pic_type       [IN] picture type, local or remote
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_set_incall_pic_default(mmi_ucm_vt_incall_pic_type_enum pic_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR null_terminator[] = {0x00,0x00};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_SET_INCALL_PIC_DEFAULT);
    
    mmi_ucm_vt_set_incall_pic((U16*)null_terminator, pic_type);
    
    if (MMI_UCM_VT_INCALL_PIC_TYPE_LOCAL_USER == pic_type)
    {
        mmi_ucm_vt_set_camera_status(MMI_FALSE);
    }

    /* go back to incall screen if during in-call */
    if (g_ucm_p->cui_info.vtincall_opt_cui_id == GRP_ID_INVALID)
    {
        mmi_popup_display_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_entry_file_mgr_to_select_incall_pic
 * DESCRIPTION
 *  Function for users to select incall pic
 * PARAMETERS
 *  pic_type       [IN] picture type, local or remote
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_entry_file_mgr_to_select_incall_pic(mmi_ucm_vt_incall_pic_type_enum pic_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_ENTRY_FILE_MGR_TO_SELECTE_INCALL_PIC, pic_type);

    FMGR_FILTER_INIT(&filter);

    /* todo: set all supported filters here */
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_JPEG);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_BMP);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_GIF);    
    FMGR_FILTER_SET(&filter, FMGR_TYPE_PNG);

    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER_DOT);

    /* mmi_ucm_vt_sg_proc */
    g_ucm_p->cui_info.fmgr_selector_cui = cui_file_selector_create(GRP_ID_UCM_VT, 
                                      (WCHAR*) L"root", 
                                      &filter, 
                                      CUI_FILE_SELECTOR_STYLE_FILE_ONLY, 
                                      CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON);

    cui_file_selector_set_title(g_ucm_p->cui_info.fmgr_selector_cui, 0, GetRootTitleIcon(MENU_ID_UCM_VT_MAIN));

    cui_file_selector_set_ui_style(g_ucm_p->cui_info.fmgr_selector_cui, CUI_FMGR_UI_STYLE_BANNER_LIST);
    
    cui_file_selector_set_userdata(g_ucm_p->cui_info.fmgr_selector_cui, (U32)pic_type);
    
    if (g_ucm_p->cui_info.fmgr_selector_cui != GRP_ID_INVALID)
    {  
        cui_file_selector_run(g_ucm_p->cui_info.fmgr_selector_cui);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_fmgr_cui_proc
 * DESCRIPTION
 *  The proc function of fmgr cui
 * PARAMETERS
 *  evt                     [IN]: event
 * RETURNS
 *  MMI_RET_OK: handle this event successfully
 *  Others: fail to handle this event
 *****************************************************************************/
mmi_ret mmi_ucm_vt_fmgr_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_file_selector_result_event_struct *file_select;
    U16 img_temp_path[SRV_FMGR_PATH_MAX_LEN + 1];
    mmi_ucm_vt_incall_pic_viewer_struct *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_select = (cui_file_selector_result_event_struct *)evt;

    if (file_select->result > 0)
    {
        /* get selected path */
        memset(img_temp_path, 0, ENCODING_LENGTH * (SRV_FMGR_PATH_MAX_LEN + 1));

        cui_file_selector_get_selected_filepath(
            file_select->sender_id,
            NULL,
            (WCHAR *) img_temp_path,
            SRV_FMGR_PATH_MAX_LEN * ENCODING_LENGTH);

        if (mmi_ucm_vt_check_incall_pic_file_path(img_temp_path))
        {
            user_data = OslMalloc(sizeof(mmi_ucm_vt_incall_pic_viewer_struct));
            mmi_ucs2ncpy((CHAR *)user_data->image_file_path, (CHAR *)img_temp_path, NVRAM_EF_VT_SETTING_SIZE / ENCODING_LENGTH);
            user_data->pic_type = (mmi_ucm_vt_incall_pic_type_enum)cui_file_selector_get_userdata(file_select->sender_id);
            mmi_ucm_vt_enter_incall_pic_viewer(user_data);
        }
    }
    else if (file_select->result == 0)
    {
        cui_file_selector_close(file_select->sender_id);
    }
    else
    {
        cui_file_selector_close(file_select->sender_id);
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_check_incall_pic_file_path
 * DESCRIPTION
 *  Check the file path of incall picture is valid or not
 * PARAMETERS
 *  file_path             [IN]: file path
 * RETURNS
 *  Return MMI_TRUE if the input file path is vaild; otherwise, MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_ucm_vt_check_incall_pic_file_path(PU16 file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
#ifdef __DRM_SUPPORT__ 
    MMI_BOOL is_permitted = MMI_FALSE;
    FS_HANDLE fd = -1;
#endif /*__DRM_SUPPORT__*/
    CHAR* error_str_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        /* 1. check path exists or not*/
        if (NULL == file_path)
        {
            break;
        }

        /* 2. check DRM */
    #ifdef __DRM_SUPPORT__
        fd = DRM_open_file(file_path, FS_READ_ONLY, DRM_PERMISSION_NONE);
        if (fd >= FS_NO_ERROR)
        {
            if (DRM_get_object_method(fd, NULL) == DRM_METHOD_NONE)
            {
                is_permitted = MMI_TRUE;
            }
            DRM_close_file(fd);
        }
        else if (fd == DRM_RESULT_INVALID_FORMAT)
        {
            mmi_popup_display_ext(STR_GLOBAL_INVALID_FORMAT, MMI_EVENT_FAILURE, NULL);
            break;
        }
        else if (fd <= -1)   /* file open error, but not DRM related problem */
        {
            mmi_popup_display_ext(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE, NULL);
            break;
        }

        if (!is_permitted)
        {
            mmi_popup_display_ext(STR_GLOBAL_DRM_PROHIBITED, MMI_EVENT_FAILURE, NULL);
            break;
        }
    #endif /*__DRM_SUPPORT__*/

        /* 3. check invalid type */
        if (GDI_IMAGE_TYPE_INVALID == gdi_image_get_type_from_file((CHAR*)file_path))
        {
            mmi_popup_display_ext(STR_GLOBAL_INVALID_FORMAT, MMI_EVENT_FAILURE, NULL);
            break;
        }

        /* 4. file limitation check - limitation is defined in FileMgrServicehdlr.c */
        if (!mmi_fmgr_util_file_limit_check(FMGR_LIMIT_VT_IMG, (CHAR*)file_path, &error_str_ptr))
        {
            mmi_popup_display((WCHAR*)(error_str_ptr), MMI_EVENT_FAILURE, NULL);
            break;
        }

        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_CHECK_INCALL_PIC_FILE_PATH, MMI_TRUE);
        return MMI_TRUE;
    }while(0);

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_CHECK_INCALL_PIC_FILE_PATH, MMI_FALSE);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_enter_incall_pic_viewer
 * DESCRIPTION
 *  Enter incall picture viewer screen
 * PARAMETERS
 *  user_data             [IN]: user data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_enter_incall_pic_viewer(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ensure no two pic viewer screens in the history */
    if (mmi_frm_scrn_is_present(GRP_ID_UCM_VT, SCR_ID_UCM_VT_PIC_VIEWER, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_UCM_VT, SCR_ID_UCM_VT_PIC_VIEWER);
    }

    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_VT,
        SCR_ID_UCM_VT_PIC_VIEWER,
        (FuncPtr)mmi_ucm_vt_entry_incall_pic_viewer,
        user_data);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_entry_incall_pic_viewer
 * DESCRIPTION
 *  Incall picture viewer screen entry function
 * PARAMETERS
 *  scrn_data             [IN]: screen data
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_entry_incall_pic_viewer(mmi_scrn_essential_struct* scrn_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_vt_incall_pic_viewer_struct *user_data = (mmi_ucm_vt_incall_pic_viewer_struct *)scrn_data->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            scrn_data->group_id,
            scrn_data->scrn_id,
            NULL,
            (FuncPtr)mmi_ucm_vt_entry_incall_pic_viewer,
            MMI_FRM_FULL_SCRN))
    {
        mmi_frm_scrn_set_leave_proc(scrn_data->group_id, scrn_data->scrn_id, (mmi_proc_func)mmi_ucm_vt_incall_pic_viewer_proc);
        return;
    }

    mmi_frm_scrn_set_leave_proc(scrn_data->group_id, scrn_data->scrn_id, (mmi_proc_func)mmi_ucm_vt_incall_pic_viewer_proc);
    /* entry cat222 to decode and display a image from file */
    wgui_cat222_disable_err_msg_display();

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory222Screen(
        STR_GLOBAL_VIEW,
        GetRootTitleIcon(MENU_ID_UCM_VT_MAIN),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        GDI_COLOR_BLACK,
        (CHAR*) NULL,
        (CHAR*) user_data->image_file_path,
        FALSE,
        mmi_ucm_vt_incall_pic_viewer_callback,
        GDI_IMAGE_SRC_FROM_FILE);

    SetLeftSoftkeyFunction(mmi_ucm_vt_incall_pic_viewer_selected, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_ucm_vt_incall_pic_viewer_selected, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_incall_pic_viewer_proc
 * DESCRIPTION
 *  This function is a leave proc for video call picture viewer screen
 * PARAMETERS
 *  evt     [IN]    MMI event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_vt_incall_pic_viewer_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_evt_struct *scenario_evt = (mmi_scenario_evt_struct*)evt;
    mmi_ucm_vt_incall_pic_viewer_struct *user_data = (mmi_ucm_vt_incall_pic_viewer_struct *)mmi_frm_scrn_get_user_data(scenario_evt->targ_group, scenario_evt->targ_scrn); 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
            OslMfree(user_data);
            break;
        default:
            break;
    }    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_incall_pic_viewer_callback
 * DESCRIPTION
 *  Check the file path is valid or not
 * PARAMETERS
 *  Play callback for picture display 
 * PARAMETERS
 *  result    :    [IN] GDI error code
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_incall_pic_viewer_callback(S32 result)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result < 0)
    {
        DisableLeftSoftkey(STR_GLOBAL_OK, NULL);
        DisableRightSoftkey(STR_GLOBAL_BACK, NULL);
        mmi_popup_display_ext(STR_GLOBAL_UNSUPPORTED_FORMAT, MMI_EVENT_FAILURE, NULL);
        mmi_frm_scrn_close(GRP_ID_UCM_VT, SCR_ID_UCM_VT_PIC_VIEWER);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_incall_pic_viewer_selected
 * DESCRIPTION
 *  Save pic file path, set camera status and process the screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_incall_pic_viewer_selected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_ucm_vt_incall_pic_viewer_struct *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data = (mmi_ucm_vt_incall_pic_viewer_struct*) mmi_frm_scrn_get_user_data(GRP_ID_UCM_VT, SCR_ID_UCM_VT_PIC_VIEWER);
    MMI_ASSERT(user_data);
    mmi_ucm_vt_set_incall_pic(user_data->image_file_path, user_data->pic_type);

    if (MMI_UCM_VT_INCALL_PIC_TYPE_LOCAL_USER == user_data->pic_type)
    {
        mmi_ucm_vt_set_camera_status(MMI_FALSE);
    }

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) == 0)
    {
        mmi_popup_display_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, NULL);
    }
    else
    {
        if (mmi_frm_scrn_is_present(GRP_ID_UCM_VT, SCR_ID_UCM_VT_INCALL, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            mmi_frm_scrn_multiple_close(GRP_ID_UCM_VT, mmi_frm_scrn_get_active_id(), MMI_TRUE, 0, SCR_ID_UCM_VT_INCALL, MMI_FALSE);
        }
        else if (SCR_ID_UCM_VT_INCALL == mmi_frm_scrn_get_active_id())
        {
            /* Do nothing */
        }
        else
        {
            MMI_ASSERT(0);
        }
    }

    mmi_frm_scrn_close(GRP_ID_UCM_VT, SCR_ID_UCM_VT_PIC_VIEWER);
    
    cui_file_selector_close(g_ucm_p->cui_info.fmgr_selector_cui);
    g_ucm_p->cui_info.fmgr_selector_cui = GRP_ID_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_hint_setting_incall_pic
 * DESCRIPTION
 *  Set file path hint for setting video call picture menu item
 * PARAMETERS
 *  menu_gid       [IN]        menu cui group id
 *  pic_type       [UN]        pic type for video call
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_hint_setting_incall_pic(MMI_ID menu_gid, mmi_ucm_vt_incall_pic_type_enum pic_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id menu_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_UCM_VT_INCALL_PIC_TYPE_LOCAL_USER == pic_type)
    {
        menu_id = MENU_ID_UCM_VT_SETTING_INCALL_IMAGE;
    }
#ifdef __OP01__
    else if (MMI_UCM_VT_INCALL_PIC_TYPE_REMOTE_USER == pic_type)
    {
        menu_id = MENU_ID_UCM_VT_SETTING_INCALL_REMOTE_IMAGE;
    }
#endif /* __OP01__ */
    else
    {
        return;
    }

#ifdef __OP01__
    if (MMI_UCM_VT_INCALL_PIC_TYPE_LOCAL_USER == pic_type &&
        MMI_FALSE == g_ucm_p->vt_cntx.setting.incall_image_state[pic_type])
    {
        cui_menu_set_item_hint(
            menu_gid,
            menu_id,
            (UI_string_type)GetString(STR_GLOBAL_OFF));
    }
    else
#endif /* __OP01__ */
    {
        if (mmi_ucs2strlen((CHAR*)g_ucm_p->vt_cntx.setting.incall_image_file_path[pic_type]) == 0)
        {
            cui_menu_set_item_hint(
                menu_gid, 
                menu_id, 
                (UI_string_type)GetString(STR_ID_UCM_VT_DEFAULT));

        }
        else
        {
            cui_menu_set_item_hint(
                menu_gid, 
                menu_id, 
                (UI_string_type)mmi_ucm_vt_get_file_name((U16*)g_ucm_p->vt_cntx.setting.incall_image_file_path[pic_type]));   
        }
    }
}
#endif /* __MMI_FILE_MANAGER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_enter_mo_fail_post_action
 * DESCRIPTION
 *  Enter VT MO call fail post action screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_enter_mo_fail_post_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_MO_FAIL_POST_ACTION, SCR_ID_UCM_VT_MO_FAIL_POST_ACTION, 
        (FuncPtr)mmi_ucm_vt_entry_mo_fail_post_action, 
        (void*)NULL);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_entry_mo_fail_post_action
 * DESCRIPTION
 *  Entry post action screen after failed MO 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_entry_mo_fail_post_action(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer = NULL;
    U8 item_index = 0;
    U8 *listItemsIcons[MAX_SUB_MENUS];
    S32 idx;
	srv_ucm_dial_act_req_struct check_act_req;
	S32 unicodeLen = 0;
	srv_ucm_act_opcode_enum first_permit_act_op = SRV_UCM_NO_ACT;
    srv_ucm_result_enum first_permit_result = SRV_UCM_RESULT_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_VT_MO_FAIL_POST_ACTION,
                    NULL,
                    (FuncPtr)mmi_ucm_vt_entry_mo_fail_post_action,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }

    memset(listItemsIcons, 0, sizeof(listItemsIcons));
    memset(subMenuDataPtrs, 0, sizeof(subMenuDataPtrs));
    memset(g_ucm_p->vt_cntx.post_action_info.menu_list, 0, sizeof(g_ucm_p->vt_cntx.post_action_info.menu_list));
    idx = 0;
	memset(&check_act_req, 0, sizeof(srv_ucm_dial_act_req_struct));
    unicodeLen = (SRV_UCM_MAX_NUM_URI_LEN > mmi_ucs2strlen((CHAR*)g_ucm_p->vt_cntx.mo_info.dial_pad_buffer)) ? (mmi_ucs2strlen((CHAR*)g_ucm_p->vt_cntx.mo_info.dial_pad_buffer)) : (SRV_UCM_MAX_NUM_URI_LEN);    
    if (unicodeLen > 0)
    {
        mmi_ucs2ncpy((CHAR*)check_act_req.num_uri, (CHAR*)g_ucm_p->vt_cntx.mo_info.dial_pad_buffer, unicodeLen);
    }
    check_act_req.is_ip_dial = g_ucm_p->mo_info.is_ip_dial;
    check_act_req.phb_data = g_ucm_p->mo_info.phb_data;
    check_act_req.module_id = SRV_UCM_MODULE_ORIGIN_COMMON;	

#if (MMI_MAX_SIM_NUM >= 2)
    check_act_req.call_type = SRV_UCM_VOICE_CALL_TYPE;
    if (MMI_TRUE == mmi_ucm_pass_dial_permit(&check_act_req, &first_permit_act_op, &first_permit_result))
    {
        g_ucm_p->vt_cntx.post_action_info.menu_list[idx] = MMI_UCM_VT_MO_FAIL_ACTION_DIAL_VOICE_CALL;
        subMenuDataPtrs[idx++] = (PU8) mmi_ucm_get_redial_string(SRV_UCM_VOICE_CALL_TYPE);
    }
	
    check_act_req.call_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
    if (MMI_TRUE == mmi_ucm_pass_dial_permit(&check_act_req, &first_permit_act_op, &first_permit_result))
    {
        g_ucm_p->vt_cntx.post_action_info.menu_list[idx] = MMI_UCM_VT_MO_FAIL_ACTION_DIAL_VOICE_CALL_SIM2;
        subMenuDataPtrs[idx++] = (PU8) mmi_ucm_get_redial_string(SRV_UCM_VOICE_CALL_TYPE_SIM2);
    }
#if (MMI_MAX_SIM_NUM >= 3)
    check_act_req.call_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
    if (MMI_TRUE == mmi_ucm_pass_dial_permit(&check_act_req, &first_permit_act_op, &first_permit_result))
    {
        g_ucm_p->vt_cntx.post_action_info.menu_list[idx] = MMI_UCM_VT_MO_FAIL_ACTION_DIAL_VOICE_CALL_SIM3;
        subMenuDataPtrs[idx++] = (PU8) mmi_ucm_get_redial_string(SRV_UCM_VOICE_CALL_TYPE_SIM3);
    }
#if (MMI_MAX_SIM_NUM == 4)
    check_act_req.call_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
    if (MMI_TRUE == mmi_ucm_pass_dial_permit(&check_act_req, &first_permit_act_op, &first_permit_result))
    {
        g_ucm_p->vt_cntx.post_action_info.menu_list[idx] = MMI_UCM_VT_MO_FAIL_ACTION_DIAL_VOICE_CALL_SIM4;
        subMenuDataPtrs[idx++] = (PU8) mmi_ucm_get_redial_string(SRV_UCM_VOICE_CALL_TYPE_SIM4);
    }
#endif /* (MMI_MAX_SIM_NUM == 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
    g_ucm_p->vt_cntx.post_action_info.menu_list[idx] = MMI_UCM_VT_MO_FAIL_ACTION_REDIAL_VIDEO_CALL;
    subMenuDataPtrs[idx++] = (U8*) mmi_ucm_get_redial_string(SRV_UCM_VIDEO_CALL_TYPE);
#else /* (MMI_MAX_SIM_NUM >= 2) */
    check_act_req.call_type = SRV_UCM_VOICE_CALL_TYPE;
    if (MMI_TRUE == mmi_ucm_pass_dial_permit(&check_act_req, &first_permit_act_op, &first_permit_result))
    {
    	g_ucm_p->vt_cntx.post_action_info.menu_list[idx] = MMI_UCM_VT_MO_FAIL_ACTION_DIAL_VOICE_CALL;
    	subMenuDataPtrs[idx++] = (U8*) mmi_ucm_get_redial_string(SRV_UCM_VOICE_CALL_TYPE);
    }

    g_ucm_p->vt_cntx.post_action_info.menu_list[idx] = MMI_UCM_VT_MO_FAIL_ACTION_REDIAL_VIDEO_CALL;
    subMenuDataPtrs[idx++] = (U8*) mmi_ucm_get_redial_string(SRV_UCM_VIDEO_CALL_TYPE);
#endif /* (MMI_MAX_SIM_NUM >= 2) */

#ifdef MMS_SUPPORT
    g_ucm_p->vt_cntx.post_action_info.menu_list[idx] = MMI_UCM_VT_MO_FAIL_ACTION_SEND_MMS; 
    subMenuDataPtrs[idx++] = (U8*) GetString(STR_GLOBAL_SEND_MULTIMEDIA_MESSAGE);
#endif /* MMS_SUPPORT */

    g_ucm_p->vt_cntx.post_action_info.menu_list[idx] = MMI_UCM_VT_MO_FAIL_ACTION_SEND_SMS; 
    subMenuDataPtrs[idx++] = (U8*) GetString(STR_GLOBAL_SEND_TEXT_MESSAGE);


    for (item_index = 0; item_index < idx; item_index++)
    {
        listItemsIcons[item_index] = (U8*) GetImage(gIndexIconsImageList[item_index]);
    }

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_UCM_MO_FAIL_POST_ACTION, SCR_ID_UCM_VT_MO_FAIL_POST_ACTION);
    RegisterHighlightHandler(mmi_ucm_vt_setting_get_hilite_index);

    ShowCategory32Screen(
        (U8*) GetString(STR_ID_UCM_VT_FAIL_TO_MAKE_VIDEO_CALL),
        (U8*) GetImage(GetRootTitleIcon(MENU_ID_UCM_VT_MAIN)),
        (U8*) GetString(STR_GLOBAL_OK),
        (U8*) GetImage(IMG_GLOBAL_OK),
        (U8*) GetString(STR_GLOBAL_BACK),
        (U8*) GetImage(IMG_GLOBAL_BACK),
        idx,
        (U8 **) subMenuDataPtrs,
        listItemsIcons,
        0,
        0,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_ucm_vt_process_mo_fail_post_action, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_ucm_vt_process_mo_fail_post_action, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_process_mo_fail_post_action
 * DESCRIPTION
 *  Process mo fail action
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_process_mo_fail_post_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_ucm_make_call_para_struct makecall_para;
	mmi_sms_write_msg_para_struct *sendData;
    U8* number;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_POST_ACTION_DIAL_PAD_BUF_P10, g_ucm_p->vt_cntx.mo_info.dial_pad_buffer[0], 
        g_ucm_p->vt_cntx.mo_info.dial_pad_buffer[1], g_ucm_p->vt_cntx.mo_info.dial_pad_buffer[2], g_ucm_p->vt_cntx.mo_info.dial_pad_buffer[3],
        g_ucm_p->vt_cntx.mo_info.dial_pad_buffer[4],g_ucm_p->vt_cntx.mo_info.dial_pad_buffer[5],g_ucm_p->vt_cntx.mo_info.dial_pad_buffer[6],
        g_ucm_p->vt_cntx.mo_info.dial_pad_buffer[7],g_ucm_p->vt_cntx.mo_info.dial_pad_buffer[8],g_ucm_p->vt_cntx.mo_info.dial_pad_buffer[9]);

    MMI_ASSERT(g_ucm_p->vt_cntx.setting.curr_hilite_index < MMI_UCM_VT_MO_FAIL_ACTION_TOTAL_NUM);

    switch (g_ucm_p->vt_cntx.post_action_info.menu_list[g_ucm_p->vt_cntx.setting.curr_hilite_index])
    {
        case MMI_UCM_VT_MO_FAIL_ACTION_DIAL_VOICE_CALL:
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_UCM_VT_MO_FAIL_ACTION_DIAL_VOICE_CALL_SIM2:
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_UCM_VT_MO_FAIL_ACTION_DIAL_VOICE_CALL_SIM3:
    #if (MMI_MAX_SIM_NUM == 4)
        case MMI_UCM_VT_MO_FAIL_ACTION_DIAL_VOICE_CALL_SIM4:
    #endif /*(MMI_MAX_SIM_NUM == 4)*/
    #endif /*(MMI_MAX_SIM_NUM >= 3)*/
    #endif /*(MMI_MAX_SIM_NUM >= 2)*/        
        case MMI_UCM_VT_MO_FAIL_ACTION_REDIAL_VIDEO_CALL:
        {   
            mmi_ucm_init_call_para(&makecall_para);

            switch (g_ucm_p->vt_cntx.post_action_info.menu_list[g_ucm_p->vt_cntx.setting.curr_hilite_index])
            {
                case MMI_UCM_VT_MO_FAIL_ACTION_DIAL_VOICE_CALL:
                {
                    makecall_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;
                }
                break;
                
            #if (MMI_MAX_SIM_NUM >= 2)
                case MMI_UCM_VT_MO_FAIL_ACTION_DIAL_VOICE_CALL_SIM2:
                {
                    makecall_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
                }
                break;
                
            #if (MMI_MAX_SIM_NUM >= 3)
                case MMI_UCM_VT_MO_FAIL_ACTION_DIAL_VOICE_CALL_SIM3:
                {
                    makecall_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
                }
                break;
                
            #if (MMI_MAX_SIM_NUM == 4)
                case MMI_UCM_VT_MO_FAIL_ACTION_DIAL_VOICE_CALL_SIM4:
                {
                    makecall_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
                }
                break;
                
            #endif /*(MMI_MAX_SIM_NUM == 4)*/
            #endif /*(MMI_MAX_SIM_NUM >= 3)*/
            #endif /*(MMI_MAX_SIM_NUM >= 2)*/        
                case MMI_UCM_VT_MO_FAIL_ACTION_REDIAL_VIDEO_CALL:
                {
                    makecall_para.dial_type = SRV_UCM_VIDEO_CALL_TYPE_ALL;
                }
                break;
                
                default:
                {
                    MMI_ASSERT(0);
                }
                break; 
            }
        
            makecall_para.ucs2_num_uri = (U16*)g_ucm_p->vt_cntx.mo_info.dial_pad_buffer;
            makecall_para.adv_para.is_ip_dial = g_ucm_p->mo_info.is_ip_dial;
            makecall_para.adv_para.phb_data = g_ucm_p->mo_info.phb_data;
            mmi_ucm_call_launch(0, &makecall_para);
        }
        break;

    #ifdef MMS_SUPPORT
        case MMI_UCM_VT_MO_FAIL_ACTION_SEND_MMS:
        {
            mms_address_insert_hdlr((char*)g_ucm_p->vt_cntx.mo_info.dial_pad_buffer); 
        }
        break;
    #endif /* MMS_SUPPORT */

        case MMI_UCM_VT_MO_FAIL_ACTION_SEND_SMS:
        {
            if (mmi_ucs2strlen((CHAR*)g_ucm_p->vt_cntx.mo_info.dial_pad_buffer) > SRV_SMS_MAX_ADDR_LEN - 1)
            {
                mmi_popup_display_ext(STR_GLOBAL_INVALID_NUMBER, MMI_EVENT_FAILURE, NULL);
            	break;
            }  
            
            sendData = OslMalloc(sizeof(mmi_sms_write_msg_para_struct));
            number = OslMalloc(SRV_SMS_MAX_ADDR_LEN);

            memset(sendData, 0, sizeof(mmi_sms_write_msg_para_struct));
            memset(number, 0, SRV_SMS_MAX_ADDR_LEN);

            mmi_ucs2_n_to_asc((CHAR*)number, (CHAR*)g_ucm_p->vt_cntx.mo_info.dial_pad_buffer, (SRV_SMS_MAX_ADDR_LEN - 1) * ENCODING_LENGTH);

            sendData->flag = MMI_SMS_ENTRY_WRITE_REPLY;
            sendData->ascii_addr = number;
            mmi_sms_write_msg_lanch(0, sendData);
            
            OslMfree(number);
            OslMfree(sendData);
        }
        break;

        default:
        {
            MMI_ASSERT(0);
        }
        break;        
    }
    mmi_frm_group_close(GRP_ID_UCM_MO_FAIL_POST_ACTION);
    return;
}

#ifdef __OP01__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_fallto_voice_notify_timeout_handler
 * DESCRIPTION
 *  ucm call end timeout handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_fallto_voice_notify_timeout_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(UCM_VT_FALL_TO_VOICE_NOTIFY_TIMER_ID);
    mmi_frm_scrn_close(GRP_ID_UCM_MO_FAIL_POST_ACTION, SCR_ID_UCM_VT_FALLTO_VOICE_NOTIFY);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_enter_fallto_voice_notify
 * DESCRIPTION
 *  Enter auto redial screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_enter_fallto_voice_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_first_enter(
        GRP_ID_UCM_MO_FAIL_POST_ACTION, SCR_ID_UCM_VT_FALLTO_VOICE_NOTIFY, 
        (FuncPtr)mmi_ucm_vt_entry_fallto_voice_notify, 
        (void*)NULL);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_entry_auto_redial
 * DESCRIPTION
 *  Auto redial entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_entry_fallto_voice_notify(mmi_scrn_essential_struct* scr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!mmi_frm_scrn_enter(
                    scr_info->group_id,
                    SCR_ID_UCM_VT_FALLTO_VOICE_NOTIFY,
                    NULL,
                    (FuncPtr)mmi_ucm_vt_entry_fallto_voice_notify,
                    MMI_FRM_FULL_SCRN))
    {
        return;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENTRY_AUTO_REDIAL);

    ShowCategory141Screen(0, 0, 0, 0, 0, 0, (U8*)GetString(STR_ID_UCM_VT_FALL_TO_VOICE_NOTIFY), 0, NULL);

    StartTimer(UCM_VT_FALL_TO_VOICE_NOTIFY_TIMER_ID, 15000, mmi_ucm_vt_fallto_voice_notify_timeout_handler);
}
#endif /* __OP01__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_enter_in_call
 * DESCRIPTION
 *  Enter in call screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_enter_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Disallow user to enter VT app during call */
#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif/* __MMI_BACKGROUND_CALL__ */

    if (MMI_FALSE == mmi_ucm_vt_check_nw_usable())
    {
        mmi_popup_display_ext(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE, NULL);
        return;
    }

    if (MMI_FALSE == srv_ucm_is_call_srv_available(SRV_UCM_VIDEO_CALL_TYPE_ALL))
    {
        mmi_ucm_display_error_popup(SRV_UCM_RESULT_ACTION_NOT_ALLOWED);
        return;
    }

    /* Only when 1 video call or no call will */

    /* keep the modification in preview mode */
    if (MMI_UCM_VT_INCALL_SCREEN_MODE_NONE == g_ucm_p->vt_cntx.incall_screen.mode)
    {
        mmi_ucm_vt_init_incall_setting();
    }
    
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) > 0)
    {
        g_ucm_p->vt_cntx.incall_screen.mode = MMI_UCM_VT_INCALL_SCREEN_MODE_INCALL;
        mmi_ucm_vt_set_hand_free_status(MMI_TRUE);
    }
    else
    {
        g_ucm_p->vt_cntx.incall_screen.mode = MMI_UCM_VT_INCALL_SCREEN_MODE_PREVIEW_ONLY;

        if (g_ucm_p->vt_cntx.setting.dial_mode == MMI_UCM_VT_DIAL_MODE_STOP_CAMERA)
        {
            mmi_ucm_vt_set_camera_status(MMI_FALSE);
        }
        else
        {
            mmi_ucm_vt_set_camera_status(MMI_TRUE);
        }
    }
    /* if from call setting-> enter VT app */

    mmi_ucm_sg_create(GRP_ID_ROOT, GRP_ID_UCM_VT);

    if (mmi_frm_scrn_is_present(GRP_ID_UCM_VT, SCR_ID_UCM_VT_INCALL, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_UCM_VT, SCR_ID_UCM_VT_INCALL); /* ensure no two incoming call screens in the history */
    }
    
    mmi_frm_scrn_first_enter(
    GRP_ID_UCM_VT, SCR_ID_UCM_VT_INCALL, 
    (FuncPtr)mmi_vtcs_entry_call_scr, 
    (void*)NULL);

    //mmi_vtcs_entry_call_scr();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_start_camera_query_yes
 * DESCRIPTION
 *  Confirm to start camera
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_start_camera_query_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    StopTimer(VT_START_CAMERA_QUERY_TIMER);
    mmi_ucm_vt_set_camera_status(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_start_camera_query_no
 * DESCRIPTION
 *  Confirm to stop camera
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_start_camera_query_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*-------------------	---------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(VT_START_CAMERA_QUERY_TIMER);
    mmi_ucm_vt_set_camera_status(MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_start_camera_query_timeout
 * DESCRIPTION
 *  Start Camera query timeour hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_start_camera_query_timeout (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_vt_set_camera_status(MMI_FALSE);
    mmi_ucm_query_cancel_ind();
}    


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_bt_set_audio_path
 * DESCRIPTION
 *  BT set audio path function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_bt_set_audio_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BACKGROUND_CALL__)
    if (srv_ucm_is_background_call())
    {
        mmi_ucm_app_entry_error_message();
        return;
    }
#endif/* __MMI_BACKGROUND_CALL__ */

    mmi_ucm_bt_set_audio_path();

    return;
}   

/*****************************************************************************
 * FUNCTION
 *  mmi_vt_pre_entry_new_call_without_input
 * DESCRIPTION
 *  Pre-entry function of new call editor without any entered digit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_pre_entry_new_call_without_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Avoid re-entry of VT dialer */
    mmi_frm_scrn_close(GRP_ID_UCM_VT, SCR_ID_UCM_VT_DIALER);
    memset(g_ucm_p->vt_cntx.mo_info.dial_pad_buffer, 0, sizeof(g_ucm_p->vt_cntx.mo_info.dial_pad_buffer));

    mmi_ucm_sg_create(GRP_ID_ROOT, GRP_ID_UCM_VT);

    mmi_ucm_vt_enter_dialer_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_pre_entry_new_call
 * DESCRIPTION
 *  Pre entry function of new call editor
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_pre_entry_new_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 keyCode = 0, keyType = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_VT_PRE_ENTRY_NEW_CALL);

    GetkeyInfo(&keyCode, &keyType);
    
    /* For first spec digit keycode like '*' to disable highlight */
    mmi_frm_send_incomplete_key_event_to_new_screen(MMI_TRUE);

    if (MMI_FALSE == wgui_inputs_dialer_is_dialer_keys(keyCode))
    {
        return;
    }
    
    memset(g_ucm_p->vt_cntx.mo_info.dial_pad_buffer, 0, sizeof(g_ucm_p->vt_cntx.mo_info.dial_pad_buffer));

    mmi_ucm_sg_create(GRP_ID_ROOT, GRP_ID_UCM_VT);

    mmi_ucm_vt_enter_dialer_screen();

    wgui_inputs_dialer_display_char(keyCode);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_answer_mode_prompt_cb
 * DESCRIPTION
 *  confirm indication callback for answer mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_answer_mode_prompt_cb(srv_ucm_cnf_opcode_enum op_code, void *ptr)
{
    srv_ucm_query_cnf_struct *query_cnf = (srv_ucm_query_cnf_struct*) ptr;
    
    if (SRV_UCM_QUERY_CNF != op_code)
    {
        MMI_ASSERT(0);
    }
    
    if (SRV_UCM_QUERY_CNF_YES == query_cnf->result_info)
    {
        mmi_ucm_vt_start_camera_query_yes();
    }
    else if (SRV_UCM_QUERY_CNF_NO == query_cnf->result_info)
    {
        mmi_ucm_vt_start_camera_query_no();
        
    }
    else if (SRV_UCM_QUERY_CNF_ABORT== query_cnf->result_info)
    {
        mmi_ucm_vt_start_camera_query_no();
    }
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_call_end_callback
 * DESCRIPTION
 *  Handler for call end
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_call_end_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* can not use mmi_ucm_vt_set_speaker_status ..etc, because at this time, no video call exists */
    srv_gpio_set_device_mute(SRV_GPIO_AUDDEV_MISROPHONE, MMI_FALSE);     
    mdi_audio_set_mute(MDI_VOLUME_SPH, MMI_FALSE);
    g_ucm_p->vt_cntx.incall_screen.is_hand_free = MMI_FALSE;
    srv_speech_disable_hand_free();

    /* Decide if orig active VT end or MO/MT VT ends to adjst screen_mode. this value will decide if the setting should kept or init */
    /* ex. 1A VT + 1W VT, W-VT ends, should keep orig VT setting, but if 1A-VT end, shoud reset setting */
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) == 0)
    {
        if (MMI_UCM_VT_INCALL_SCREEN_MODE_INCALL == mmi_ucm_vt_get_incall_screen_mode())
        {
            mmi_ucm_vt_set_incall_screen_mode(MMI_UCM_VT_INCALL_SCREEN_MODE_NONE); 
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_adjust_screen_when_call_end_callback
 * DESCRIPTION
 *  adjust screen when call is ended
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_vt_adjust_screen_when_call_end_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_UCM_VT_INCALL_SCREEN_MODE_INCALL == mmi_ucm_vt_get_incall_screen_mode())
    {
        if (srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_VIDEO_CALL_TYPE_ALL, NULL) == 0)    
        {                   
            mmi_frm_group_close(GRP_ID_UCM_VT);
        }        
    }
    
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_convert_video_quality_to_menuid
 * DESCRIPTION
 *  convert video quality from enum value to menu id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_MENU_ID mmi_ucm_vt_convert_video_quality_to_menuid(mmi_vt_video_quality_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(status)
    {
        case MMI_VT_VIDEO_QUALITY_SMOOTH:
        {
            return MENU_ID_UCM_VT_VIDEO_QUALITY_SMOOTH;
        }

        case MMI_VT_VIDEO_QUALITY_NORMAL:
        {
            return MENU_ID_UCM_VT_VIDEO_QUALITY_NORMAL;
        }

        case MMI_VT_VIDEO_QUALITY_SHARP:
        {
            return MENU_ID_UCM_VT_VIDEO_QUALITY_SHARP;
        }

        default:
        {
            MMI_ASSERT(0);
            return 0;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_convert_answer_mode_to_menuid
 * DESCRIPTION
 *  convert answer mode from enum value to menu id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_MENU_ID mmi_ucm_vt_convert_answer_mode_to_menuid(mmi_ucm_vt_answer_mode_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(status)
    {
        case MMI_UCM_VT_ANSWER_MODE_PROMPT:
        {
            return MENU_ID_UCM_VT_SETTING_ANSWER_MODE_PROMPT;
        }

        case MMI_UCM_VT_ANSWER_MODE_START_CAMERA:
        {
            return MENU_ID_UCM_VT_SETTING_ANSWER_MODE_START_CAMERA;
        }

        case MMI_UCM_VT_ANSWER_MODE_STOP_CAMERA:
        {
            return MENU_ID_UCM_VT_SETTING_ANSWER_MODE_STOP_CAMERA;
        }

        default:
        {
            MMI_ASSERT(0);
            return 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_convert_dial_mode_to_menuid
 * DESCRIPTION
 *  convert dial mode from enum value to menu id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_MENU_ID mmi_ucm_vt_convert_dial_mode_to_menuid(mmi_ucm_vt_dial_mode_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(status)
    {
        case MMI_UCM_VT_DIAL_MODE_START_CAMERA:
        {
            return MENU_ID_UCM_VT_SETTING_DIAL_MODE_START_CAMERA;
        }

        case MMI_UCM_VT_DIAL_MODE_STOP_CAMERA:
        {
            return MENU_ID_UCM_VT_SETTING_DIAL_MODE_STOP_CAMERA;
        }

        default:
        {
            MMI_ASSERT(0);
            return 0;
        }
    }
}

#if (defined(__OP01__) || defined(__MMI_UCM_VT_ATUO_REDIAL_VOICE__))
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_convert_auto_redial_mode_to_menuid
 * DESCRIPTION
 *  convert dial mode from enum value to menu id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_MENU_ID mmi_ucm_vt_convert_auto_redial_mode_to_menuid(mmi_ucm_vt_dial_mode_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(status)
    {
        case MMI_UCM_VT_AUTO_REDIAL_MODE_MANUAL:
        {
            return MENU_ID_UCM_VT_SETTING_AUTO_REDIAL_MODE_MANUAL;
        }
        
        case MMI_UCM_VT_AUTO_REDIAL_MODE_ON:
        {
            return MENU_ID_UCM_VT_SETTING_AUTO_REDIAL_MODE_ON;
        }

        case MMI_UCM_VT_AUTO_REDIAL_MODE_OFF:
        {
            return MENU_ID_UCM_VT_SETTING_AUTO_REDIAL_MODE_OFF;
        }

        default:
        {
            MMI_ASSERT(0);
            return 0;
        }
    }
}
#endif /* (defined(__OP01__) || defined(__MMI_UCM_VT_ATUO_REDIAL_VOICE__)) */

#endif /* __MMI_VIDEO_TELEPHONY__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_ucm_sg
 * DESCRIPTION
 *  check if the given sg is ucm sg or not
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means the given sg is in ucm scope
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_ucm_sg(MMI_ID check_sg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((GRP_ID_UCM_PRE_MO == check_sg_id) ||
        (GRP_ID_UCM_MO == check_sg_id) ||
        (GRP_ID_UCM_MT == check_sg_id) ||
        (GRP_ID_UCM_INCALL == check_sg_id) ||
    #ifdef __MMI_VIDEO_TELEPHONY__    
        (GRP_ID_UCM_VT == check_sg_id) ||
    #endif /* __MMI_VIDEO_TELEPHONY__ */    
    #if defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
        (GRP_ID_UCM_INT_MARKER == check_sg_id) ||
    #endif /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */    
        (GRP_ID_UCM_MARKER == check_sg_id) ||
        (GRP_ID_UCM_CALL_END == check_sg_id) ||
        (GRP_ID_UCM_AUTO_REDIAL == check_sg_id) ||
        (GRP_ID_UCM_CONFIRM == check_sg_id) ||
        (GRP_ID_UCM_MO_FAIL_POST_ACTION == check_sg_id) ||
    #ifdef __MMI_URI_AGENT__    
        (GRP_ID_UCM_UHA == check_sg_id) ||
    #endif /* __MMI_URI_AGENT__ */
        MMI_FALSE)

    {
        return MMI_TRUE;
    }
    
    return MMI_FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_bk_call_key_proc
 * DESCRIPTION
 *  background call end key/volumn key handle
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_RET_OK to continue key routing, MMI_RET_STOP_KEY_HANDLE to stop
 *  key routing
 *****************************************************************************/
mmi_ret mmi_ucm_bk_call_key_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;
    U8 key_code = key_evt->key_code;
    U8 key_type = key_evt->key_type;
    FuncPtr func_ptr;
    MMI_ID curr_act_sg_id = mmi_frm_group_get_active_id();
    MMI_ID curr_scr_id = mmi_frm_scrn_get_active_id();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(key_evt->evt_id == EVT_ID_PRE_KEY_EVT_ROUTING);

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
    #ifdef __OP01_FWPBW__
        /* Poweroff key & Long press -> need to power off, must stop ring tone first, otherwise
           the power off tone will play wrong. */
        if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
        {
            if (key_code == KEY_POWER && key_type == KEY_LONG_PRESS)
            {
                mmi_ucm_stop_incoming_tone();
                StopTimer(UCM_AUTO_ANSWER_TIMER);
                return MMI_RET_OK;
            }
        }
    #endif /* __OP01_FWPBW__ */

        if (MMI_FALSE == mmi_ucm_is_ucm_sg(curr_act_sg_id))
        {
            if (key_code == KEY_END && key_type == KEY_EVENT_DOWN)
            {
        	#ifdef __MMI_BT_CALL_SUPPORT__
				if (srv_ucm_bt_query_call_count(SRV_UCM_BT_INCOMING_STATE,NULL) > 0)
				{
					return MMI_RET_OK;
				}
			#endif /* __MMI_BT_CALL_SUPPORT__ */
                mmi_ucm_end_key();
            #ifdef __MMI_CLAMSHELL__
                if(g_ucm_p->call_misc.trigger_by_clam_close)
                {
                    return MMI_RET_OK;
                }
                else    
            #endif /* __MMI_CLAMSHELL__ */        
                {
                    return MMI_RET_STOP_KEY_HANDLE;
                }
            }
        }
        else if (curr_scr_id == SCR_ID_UCM_IN_CALL ||
                 curr_scr_id == SCR_ID_UCM_INCOMING ||
                 curr_scr_id == SCR_ID_UCM_OUTGOING ||
             #ifdef __MMI_VIDEO_TELEPHONY__
                 curr_scr_id == SCR_ID_UCM_VT_INCALL ||
             #endif /* __MMI_VIDEO_TELEPHONY__ */
                 MMI_FALSE)
        {
           if(key_type == KEY_EVENT_DOWN) 		
		   {
		
             #ifdef  __MMI_FTE_SUPPORT__
              #ifndef __PXS_APP_ENABLE__
                         mmi_ucm_FTE_screen_touch_hdlr(MMI_FALSE);			
              #endif    
			 #endif    
			
		    }
            return MMI_RET_OK;
        }

        /* volume key common handler when call exist */
        if ((key_code == KEY_VOL_UP || key_code == KEY_VOL_DOWN) &&
             (key_type == KEY_EVENT_DOWN || key_type == KEY_LONG_PRESS || key_type == KEY_REPEAT))
        {
             SetDefaultVolumeKeyHandlers();
             func_ptr = mmi_frm_get_key_handler(key_code, key_type);
             if (func_ptr)
             {
                 (* func_ptr)();
             }
             return MMI_RET_STOP_KEY_HANDLE;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_pre_mo_sg_proc
 * DESCRIPTION
 *  This function is to handle the sg result sent from fw for pre_MO
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_pre_mo_sg_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 3)
    cui_sim_sel_result_event_struct* sim_sel_evt = NULL;
#endif /* (MMI_MAX_SIM_NUM >= 3) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    #if (MMI_MAX_SIM_NUM >= 3)
        /* SIM selector event */
        case EVT_ID_CUI_SIM_SEL_RESULT:
        {
            sim_sel_evt = (cui_sim_sel_result_event_struct*)evt;

            if (sim_sel_evt->result == CUI_SIM_SEL_OK)
            {
                switch (sim_sel_evt->sim_id)
                {
                    case MMI_SIM1:
                        g_ucm_p->mo_info.dial_type = SRV_UCM_VOICE_CALL_TYPE;
                        break;
                    case MMI_SIM2:
                        g_ucm_p->mo_info.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
                        break;
                    case MMI_SIM3:
                        g_ucm_p->mo_info.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
                        break;
                #if (MMI_MAX_SIM_NUM == 4)
                    case MMI_SIM4:
                        g_ucm_p->mo_info.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
                        break;
                #endif /* (MMI_MAX_SIM_NUM == 4) */
                }
                mmi_ucm_dial_option_make_call();
            }
            else if (sim_sel_evt->result == CUI_SIM_SEL_ABORT)
            {
                mmi_ucm_cancel_call_type_select();
            }

            cui_sim_sel_close(sim_sel_evt->sender_id);
        }
        break;
    #endif /* (MMI_MAX_SIM_NUM >= 3) */

        /* GRP related events */
        case EVT_ID_GROUP_DEINIT:
        {
            
        }
        break;
        
        case EVT_ID_GROUP_INACTIVE:
        {
           
        }
        break;

        default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_mo_sg_proc
 * DESCRIPTION
 *  This function is to handle the sg result sent from fw for MO
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_mo_sg_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        /* GRP related events */
        case EVT_ID_GROUP_DEINIT:
        {
            
        }
        break;
        
        case EVT_ID_GROUP_INACTIVE:
        {
            /* no need use this , call can be in active, an other app is over on it */
            /*
            if (!mmi_frm_scrn_get_count(GRP_ID_PHB_GROUP))
            {
                mmi_frm_group_close(GRP_ID_PHB_GROUP);
            }
            */
        }
        break;

    #if !defined(__MMI_UCM_SLIM__)
        /* Menu CUI related events */
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_LIST_EXIT:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            mmi_ucm_outgoing_call_opt_proc(evt);
        }
        break;
        case EVT_ID_PHB_SAVE_CONTACT:
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
        {
            mmi_ucm_save_number_proc(evt);
        }
        break;
    #endif /* __MMI_UCM_SLIM__ */

        default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_mt_sg_proc
 * DESCRIPTION
 *  This function is to handle the sg result sent from fw for MT
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_mt_sg_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        /* GRP related event */
        case EVT_ID_GROUP_DELETE_REQ:
        {
        }
        break;

        case EVT_ID_GROUP_DEINIT:
        {
            
        }
        break;
        
        case EVT_ID_GROUP_INACTIVE:
        {
            /* no need use this , call can be in active, an other app is over on it */
            /*
            if (!mmi_frm_scrn_get_count(GRP_ID_PHB_GROUP))
            {
                mmi_frm_group_close(GRP_ID_PHB_GROUP);
            }
            */
            
        }
        break;

    #if !defined(__MMI_UCM_SLIM__)
        /* Menu CUI related events */
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_LIST_EXIT:  
        case EVT_ID_CUI_MENU_ITEM_HILITE:    
        case EVT_ID_CUI_MENU_ITEM_SELECT:    
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            mmi_ucm_incoming_call_opt_proc(evt);
        }
        break;
        
        case EVT_ID_PHB_SAVE_CONTACT:
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
        {
            mmi_ucm_save_number_proc(evt);
        }           
        break;

    #ifdef __MMI_UCM_DEFLECT__
        /* Phb menu CUI event */
        case EVT_ID_PHB_SELECT_CONTACT:  /* triggered from deflect */
        case EVT_ID_PHB_SELECT_CONTACT_CANCEL: /* trigger from deflect */
        {
            mmi_ucm_select_number_proc(evt);
        }
        break;
    #endif /* __MMI_UCM_DEFLECT__ */

        
    #ifdef __MMI_UCM_REJECT_BY_SMS__
        /* SMS template related events */
        case EVT_ID_CUI_SMS_TEMPLATE_LIST: 
        {
            mmi_ucm_sms_template_proc(evt);
        }
        break;
    #endif /* __MMI_UCM_REJECT_BY_SMS__ */
    #endif /* __MMI_UCM_SLIM__ */
            
        default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_incall_sg_proc
 * DESCRIPTION
 *  This function is to handle the sg result sent from fw for incall
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_incall_sg_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        /* GRP related events */
#ifndef __SLIM_UCM__		
        case EVT_ID_GROUP_DELETE_REQ:
        {
        }
        break;

        case EVT_ID_GROUP_DEINIT:
        {

        }
        break;
        
        case EVT_ID_GROUP_INACTIVE:
        {
            
        }
        break;
#endif
        /* Menu CUI related events */
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_LIST_EXIT:  
        case EVT_ID_CUI_MENU_ITEM_HILITE:    
        case EVT_ID_CUI_MENU_ITEM_SELECT:    
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            mmi_ucm_incall_opt_proc(evt);
        }
        break;

        case EVT_ID_PHB_SAVE_CONTACT:
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
        {
            mmi_ucm_save_number_proc(evt);
        }           
        break;
        
        default:
        break;
    }
    return MMI_RET_OK;
}

#ifdef __MMI_VIDEO_TELEPHONY__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_vt_sg_proc
 * DESCRIPTION
 *  This function is to handle the sg result sent from fw for VT
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_vt_sg_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        /* GRP related events */
        case EVT_ID_GROUP_DEINIT:
        {
            
        }
        break;
        
        case EVT_ID_GROUP_INACTIVE:
        {
            
        }
        break;

        /* Menu CUI related events */
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        case EVT_ID_CUI_MENU_LIST_EXIT:
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            mmi_ucm_vt_incall_opt_proc(evt);
        }
        break;

    #if defined(__MMI_FILE_MANAGER__)
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        {
            mmi_ucm_vt_fmgr_cui_proc(evt);
        }
        break;
    #endif /* __MMI_FILE_MANAGER__ */

        default:
        break;
    }
    return MMI_RET_OK;
}
#endif /* __MMI_VIDEO_TELEPHONY__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_marker_sg_proc
 * DESCRIPTION
 *  This function is to handle the sg result sent from fw for call marker
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_marker_sg_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
        {
            if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) != srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CSD_CALL_TYPE_ALL, NULL))          
            {
                return MMI_RET_ERR;
            }
        }
        break;

        default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_int_marker_sg_proc
 * DESCRIPTION
 *  This function is to handle the sg result sent from fw for intermeidate call marker
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_int_marker_sg_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {

        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
        {
            if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
                srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
            {
                return MMI_RET_ERR;
            }
        }
        break;
        
        default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_sg_create
 * DESCRIPTION
 *  create SG based on given sg id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_ID mmi_ucm_sg_create(MMI_ID parent_id, MMI_ID group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID enter_return_id = GRP_ID_INVALID;
    mmi_proc_func proc = NULL;
    mmi_group_enter_flag flag = MMI_FRM_NODE_SMART_CLOSE_FLAG;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_FALSE == mmi_frm_group_is_present(group_id))
    {
        switch (group_id)
        {
            case GRP_ID_UCM_PRE_MO:
            {
                proc = mmi_ucm_pre_mo_sg_proc;
            }
            break;
        #ifdef __MMI_BT_CALL_SUPPORT__
            case GRP_ID_UCM_MO_SELECT:
            {
                proc = mmi_ucm_call_select_menu_proc;
            }
            break;
        #endif
            case GRP_ID_UCM_MO:
            {   
                mmi_ucm_add_marker();
                proc = mmi_ucm_mo_sg_proc;
                flag = MMI_FRM_NODE_NONE_FLAG;
            }
            break;

            case GRP_ID_UCM_MT:
            {    
                mmi_ucm_add_marker();
                proc = mmi_ucm_mt_sg_proc;
                flag = MMI_FRM_NODE_NONE_FLAG;
            }
            break;

            case GRP_ID_UCM_INCALL:
            {
                proc = mmi_ucm_incall_sg_proc;
                flag = MMI_FRM_NODE_NONE_FLAG;
            }
            break;

        #ifdef __MMI_VIDEO_TELEPHONY__
            case GRP_ID_UCM_VT:
            {
                proc = mmi_ucm_vt_sg_proc;
                flag = MMI_FRM_NODE_NONE_FLAG;
            }
            break;
            
            case GRP_ID_UCM_MO_FAIL_POST_ACTION:
            {
            }
            break;
        #endif /* __MMI_VIDEO_TELEPHONY__ */

            case GRP_ID_UCM_MARKER:
            {
                proc = mmi_ucm_marker_sg_proc;
                flag = MMI_FRM_NODE_NONE_FLAG;
            }
            break;

        #if defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__)
            case GRP_ID_UCM_INT_MARKER:
            {
                proc = mmi_ucm_int_marker_sg_proc;
                flag = MMI_FRM_NODE_NONE_FLAG;
            }
            break;
        #endif /* defined(__MMI_BACKGROUND_CALL__) && !defined(__MMI_BACKGROUND_CALL_WITH_NCENTER__) */

            case GRP_ID_UCM_CALL_END:
            case GRP_ID_UCM_AUTO_REDIAL:
            case GRP_ID_UCM_CONFIRM:
            {
            }
            break;

            default: 
            {
                //MMI_ASSERT(0); 
            } 
            break; 
        }

        enter_return_id = mmi_frm_group_create_ex(parent_id, group_id, proc, NULL, flag);
    }
    return enter_return_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_add_sg_to_root
 * DESCRIPTION
 *  add ucm screens to history
 * PARAMETERS
 *  base_grp_id            [IN]            base group ID 
 *  insert_grp_id          [IN]            insert group ID 
 *  flag            [IN]            insert insert_grp_id before/after base_grp_id 
 *  entry_proc            [IN]            entry proc for inserted group 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_add_sg_to_root(MMI_ID base_grp_id, MMI_ID insert_grp_id, mmi_scenario_node_flag flag, mmi_proc_func entry_proc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    mmi_frm_node_struct * new_node_info = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ADD_SG_TO_ROOT_P3, base_grp_id, insert_grp_id, flag);
    if (MMI_FALSE == mmi_frm_group_is_present(insert_grp_id))
    {
        /* insert usage: no mmi_frm_group_enter */
        mmi_frm_group_create(GRP_ID_ROOT, insert_grp_id, entry_proc, NULL); 
        new_node_info = OslMalloc(sizeof(mmi_frm_node_struct));
        new_node_info->id = insert_grp_id;
        new_node_info->entry_proc = entry_proc;
        new_node_info->user_data = NULL;
        mmi_frm_group_insert(GRP_ID_ROOT, base_grp_id, new_node_info, flag);
        
        OslMfree(new_node_info);
        new_node_info = NULL;
    }
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_delete_up_to_sg_id
 * DESCRIPTION
 *  Delete all the nodes in the root to specified sg ID
 * PARAMETERS
 *  sg_id            [IN]            Specify the Screen ID up to which one wants to delete the nodes
 *  inc_this_sg          [IN]            include sg_id or not 
 *  inc_active_sg            [IN]           include current active screen or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_delete_up_to_sg_id(MMI_ID sg_id, MMI_BOOL inc_this_sg, MMI_BOOL inc_active_sg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    S32 total_sg_num = 40;
    MMI_ID sg_table[40];
    S32 i, start_index = 0;
    
    mmi_evt_mmi_ucm_close_grp_query_struct evt;
    mmi_group_node_struct node_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_DELETE_UP_TO_P3, sg_id, inc_this_sg, inc_active_sg);
    memset(sg_table, GRP_ID_INVALID, sizeof(MMI_ID) * 40);
    if (MMI_FALSE == mmi_frm_group_is_present(sg_id))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_DELETE_UP_TO_P3, sg_id, -1, -1);
        return;
    }
    
    if (MMI_RET_OK ==mmi_frm_group_query_children_list(GRP_ID_ROOT, sg_table, &total_sg_num))
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_DELETE_UP_TO_P10, sg_table[0], sg_table[1], sg_table[2],
        sg_table[3], sg_table[4], sg_table[5], sg_table[6], sg_table[7],sg_table[8], total_sg_num);
        
        for (i = 0; i < total_sg_num ; i++)
        {
            if (sg_table[i] == sg_id)
            {
                if (inc_this_sg)
                {
                    start_index = i;
                }
                else
                {
                    start_index = i + 1;
                }
                break;                
            }
        }

        if (MMI_FALSE == inc_active_sg)
        {
            total_sg_num --;
        }

        
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_DELETE_UP_TO_P2, start_index, total_sg_num);

        for (i = start_index; i < total_sg_num; i++)
        {
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_UCM_CLOSE_GRP_QUERY);
            //memset(&node_info, 0, sizeof(mmi_group_node_struct));
            mmi_frm_group_get_info(sg_table[i], &node_info);
            
            if (!(node_info.proc) ||
                (MMI_RET_OK == MMI_FRM_SEND_EVENT(&evt, node_info.proc, node_info.user_data)))
            {
                mmi_frm_group_close(sg_table[i]);
            }
        }
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_DELETE_UP_TO_ERROR_P1, total_sg_num);
        MMI_ASSERT(0);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_delete_scrn_if_not_active
 * DESCRIPTION
 *  Delete screen if this screen is not active scrn
 * PARAMETERS
 *  group_id           [IN]            Specify the group ID of the screen which want to be  deleted
 *  delete_scrn_id            [IN]            Specify the Screen ID which want to be  deleted
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_delete_scrn_if_not_active(MMI_ID group_id, MMI_ID delete_scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (delete_scrn_id != mmi_frm_scrn_get_active_id())
    {
        mmi_frm_scrn_close(group_id, delete_scrn_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_cnf_popup_cb
 * DESCRIPTION
 *  confirm popup callback
 * PARAMETERS
 *  evt     [IN] Event structure passed by callback manager
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_ucm_cnf_popup_cb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    mmi_ucm_cnf_enum cnf_type = (mmi_ucm_cnf_enum)((U32)(evt->user_tag));
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (cnf_type)
        {
        #ifdef __MMI_VIDEO_TELEPHONY__		
            case MMI_UCM_CNF_VT_AUDIO_OPT:
            {
                if (MMI_ALERT_CNFM_YES == evt->result)
                {
                    mmi_ucm_vt_audio_opt_confirm_yes();
                    mmi_alert_dismiss(evt->alert_id);
                }
                else if (MMI_ALERT_CNFM_NO == evt->result || MMI_ALERT_CNFM_CANCEL == evt->result || MMI_POPUP_INTERRUPT_EXIT == evt->result)
                {
                    mmi_ucm_vt_audio_opt_confirm_no();
                    mmi_alert_dismiss(evt->alert_id);
                }
                else
                {
                    /* do nothing */
                }
            }
            break;

            case MMI_UCM_CNF_VT_SWITCH_TO_VOICE_CALL:
            {
                if (MMI_ALERT_CNFM_YES == evt->result)
                {
                    mmi_ucm_vt_switch_to_voice_call_confirm_yes();
                    mmi_alert_dismiss(evt->alert_id);
                }
                else if (MMI_ALERT_CNFM_NO == evt->result || MMI_ALERT_CNFM_CANCEL == evt->result || MMI_POPUP_INTERRUPT_EXIT == evt->result)
                {
                    mmi_ucm_vt_switch_to_voice_call_confirm_no();
                    mmi_alert_dismiss(evt->alert_id);
                }
                else
                {
                    /* do nothing */
                }
                
            }
            break;  
            
            case MMI_UCM_CNF_VT_SWITCH_TO_VIDEO_CALL:
            {
                if (MMI_ALERT_CNFM_YES == evt->result)
                {
                    mmi_ucm_switch_to_video_call_confirm_yes();
                    mmi_alert_dismiss(evt->alert_id);
                    g_ucm_p->vt_cntx.switch_confirm_scrn = 0;
                }
                else if (MMI_ALERT_CNFM_NO == evt->result || MMI_ALERT_CNFM_CANCEL == evt->result || MMI_POPUP_INTERRUPT_EXIT == evt->result)
                {
                    mmi_ucm_switch_to_video_call_confirm_no();
                    mmi_alert_dismiss(evt->alert_id);
                    g_ucm_p->vt_cntx.switch_confirm_scrn = 0;
                }
                else
                {
                    /* do nothing */
                }
            }
            break;  
        #endif /* __MMI_VIDEO_TELEPHONY__ */
    
        #ifdef __MMI_UCM_REJECT_BY_SMS__
            case MMI_UCM_CNF_REJ_BY_SMS:
            {
                if (MMI_ALERT_CNFM_1 == evt->result)
                {
                    mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_MT, evt->alert_id, (mmi_proc_func) NULL);
                    mmi_alert_dismiss(evt->alert_id);
                    mmi_ucm_rej_by_sms();
                }
                else if (MMI_ALERT_CNFM_2 == evt->result)
                {
                    mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_MT, evt->alert_id, (mmi_proc_func) NULL);
                    mmi_alert_dismiss(evt->alert_id);
                    mmi_ucm_rej_by_sms();
                }
                else if (MMI_ALERT_CNFM_3 == evt->result || MMI_ALERT_CNFM_CANCEL == evt->result)
                {
                    mmi_alert_dismiss(evt->alert_id);
                    //mmi_ucm_cancel_rej_by_sms();
                }
                else
                {
                   /* Do nothing*/
                }
            }
            break;  
        #endif /* __MMI_UCM_REJECT_BY_SMS__ */

        #ifdef __MMI_UCM_ECT__
            case MMI_UCM_CNF_ECT:
            {
                if (MMI_ALERT_CNFM_1 == evt->result)
                {
                    mmi_ucm_exec_ECT_confirm_yes();
                    mmi_alert_dismiss(evt->alert_id);
                }
                else if (MMI_ALERT_CNFM_2 == evt->result)
                {
                    mmi_ucm_exec_ECT_confirm_yes();    
                    mmi_alert_dismiss(evt->alert_id);
                }
                else if (MMI_ALERT_CNFM_3 == evt->result || MMI_ALERT_CNFM_CANCEL == evt->result)
                {
                    mmi_alert_dismiss(evt->alert_id);
                }
                else
                {
                    /* Do nothing*/
                }
            }
            break;   
        #endif /* __MMI_UCM_ECT__ */

            case MMI_UCM_CNF_QUERY_IND:
            {
                if (MMI_ALERT_INTERRUPT_EXIT == evt->result || MMI_ALERT_NORMAL_EXIT == evt->result)
                {
                    /* Do nothing*/
                }
                else
                {
                    mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_CONFIRM, g_ucm_p->cnf_scr.scrn_id, (mmi_proc_func) NULL);
                    mmi_alert_dismiss(evt->alert_id);

                    if (MMI_ALERT_CNFM_1 == evt->result)
                    {
                        mmi_ucm_confirm_hdlr_yes();
                    }
                    else if (MMI_ALERT_CNFM_2 == evt->result)
                    {
                        mmi_ucm_confirm_hdlr_yes();
                    }
                    else if (MMI_ALERT_CNFM_3 == evt->result || MMI_ALERT_CNFM_CANCEL == evt->result)
                    {
                        mmi_ucm_confirm_hdlr_no();
                    }
                }
            }
            break;      

            
        }
    }  
    return MMI_RET_OK;
}

#ifdef __SRV_NW_INFO_CIPHER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_update_cipher_icon
 * DESCRIPTION
 *  Handler for cipher status changed.
 *  Update cipher icon.
 * PARAMETERS
 *  evt     [IN] srv_nw_info_cipher_status_changed_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_ucm_update_cipher_icon(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_cipher_status_changed_evt_struct *cipher_evt;
    U32 call_type;
    S32 icon_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cipher_evt = (srv_nw_info_cipher_status_changed_evt_struct*)evt;

    call_type = 0;
    icon_id = STATUS_ICON_INVALID_ID;

    if (cipher_evt->sim == MMI_SIM1)
    {
        call_type = SRV_UCM_SIM1_CALL_TYPE_ALL;
        icon_id = STATUS_ICON_NETWORK_CIPHER_GSM;
    }
#if (MMI_MAX_SIM_NUM == 2)
    else if (cipher_evt->sim == MMI_SIM2)
    {
        call_type = SRV_UCM_SIM2_CALL_TYPE_ALL;
        icon_id = STATUS_ICON_SLAVE_NETWORK_CIPHER_GSM;
    }
#endif /* (MMI_MAX_SIM_NUM == 2) */
#if (MMI_MAX_SIM_NUM >= 3)
    else if (cipher_evt->sim == MMI_SIM2)
    {
        call_type = SRV_UCM_SIM2_CALL_TYPE_ALL;
        icon_id = STATUS_ICON_NETWORK_CIPHER_GSM;
    }
    else if (cipher_evt->sim == MMI_SIM3)
    {
        call_type = SRV_UCM_SIM3_CALL_TYPE_ALL;
        icon_id = STATUS_ICON_NETWORK_CIPHER_GSM;
    }
    else if (cipher_evt->sim == MMI_SIM4)
    {
        call_type = SRV_UCM_SIM4_CALL_TYPE_ALL;
        icon_id = STATUS_ICON_NETWORK_CIPHER_GSM;
    }
#endif /* (MMI_MAX_SIM_NUM == 3) */

    MMI_EXT_ASSERT(call_type != 0 && icon_id != STATUS_ICON_INVALID_ID, call_type, icon_id, 0);
        
    if (cipher_evt->status.is_supported_by_network &&
        cipher_evt->status.cs_connection_exists &&
        srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, (srv_ucm_call_type_enum)call_type, NULL) > 0 &&
        cipher_evt->status.cs_status == SRV_NW_INFO_CIPHER_STATUS_OFF)
    {
        wgui_status_icon_bar_set_icon_display(icon_id);
    }
    else
    {
        wgui_status_icon_bar_reset_icon_display(icon_id);
    }

    wgui_status_icon_bar_update();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_remove_cipher_icon
 * DESCRIPTION
 *  Handler cipher icon for sim control is not available. ex sim detection fails
 * PARAMETERS
 *  evt     [IN] srv_nw_info_cipher_status_changed_evt_struct*
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_ucm_remove_cipher_icon(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_unavailable_evt_struct *unavailable_evt;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    unavailable_evt = (srv_sim_ctrl_unavailable_evt_struct*)evt;
    if (unavailable_evt->sim == MMI_SIM1)
    {
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_NETWORK_CIPHER_GSM);
    }

#if (MMI_MAX_SIM_NUM == 2)
    else if (unavailable_evt->sim == MMI_SIM2)
    {
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SLAVE_NETWORK_CIPHER_GSM);
    }
#endif /* (MMI_MAX_SIM_NUM == 2) */

#if (MMI_MAX_SIM_NUM >= 3)
    else if ((unavailable_evt->sim == MMI_SIM2) || (unavailable_evt->sim == MMI_SIM3) || (unavailable_evt->sim == MMI_SIM4))
    {
        wgui_status_icon_bar_reset_icon_display(STATUS_ICON_SLAVE_NETWORK_CIPHER_GSM);
    }
#endif /* (MMI_MAX_SIM_NUM >= 3) */

    return MMI_RET_OK;   
}
#endif /* __SRV_NW_INFO_CIPHER_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_headset_key
 * DESCRIPTION
 *  Handle headset key after receiving GPIO detection. Mainly for GPIO.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_headset_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* release processing calls */
    if (srv_ucm_is_pending_action() == MMI_TRUE)
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_UCM_PROCESSING)
        {
            if (g_ucm_p->proc_scr.end_funcPtr)
            {
                g_ucm_p->proc_scr.end_funcPtr();
            }
        }
        else
        {
            /* ignore the key event */
        }
    }
    /* incoming call exists, headset key is to answer it */
    else if (srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) != 0)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_HEADSET_KEY_ANSWER); 
        mmi_ucm_incoming_call_sendkey();
    }
    /* outgoing call exists, headset key is to abort it */
    else if (srv_ucm_query_group_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) != 0)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_HEADSET_KEY_ABORT_OUTGOING_CALL); 
        mmi_ucm_outgoing_call_endkey();
    }
    /* in call, headset key is to release current highlight tab call */
    else if (srv_ucm_query_group_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) > 0
        #ifdef __MMI_BT_CALL_SUPPORT__
          &&  srv_ucm_bt_query_call_count(SRV_UCM_BT_INCOMING_STATE, NULL) == 0
        #endif /* __MMI_BT_CALL_SUPPORT__ */
        )
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_HEADSET_KEY_RESET_HIGHLIGHT_CALL); 
        mmi_ucm_in_call_endkey();
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#ifdef __MMI_CLAMSHELL__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_clam_open
 * DESCRIPTION
 *  Handle clam open after receiving GPIO detection. Mainly for GPIO.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_clam_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_answer_mode_enum ans_mode_status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* clam open accept call will only take effect when there is no pending action */
    if (MMI_FALSE == srv_ucm_is_pending_action())
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_CLAM_OPEN); 
        ans_mode_status = srv_callset_answer_mode_get_status();
        if ((ans_mode_status & SRV_CALLSET_ANSWER_MODE_CLAMSHELL) && (srv_ucm_query_group_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, MMI_FALSE, NULL) != 0))
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_CLAM_OPEN_ANSWER); 
            mmi_ucm_incoming_call_sendkey();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_clam_close
 * DESCRIPTION
 *  Handle clam close after receiving GPIO detection. Mainly for GPIO.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_clam_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum permit_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) && 
        !srv_earphone_is_plug_in())
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_APP_CLAM_CLOSE);
        g_ucm_p->call_misc.trigger_by_clam_close = MMI_TRUE;

        if (srv_ucm_is_pending_action() == MMI_TRUE)
        {
            permit_result = srv_ucm_query_act_permit(SRV_UCM_END_ALL_PROCESSING_ACT, NULL);
            
            if (SRV_UCM_RESULT_OK == permit_result)
            {
                srv_ucm_act_request(SRV_UCM_END_ALL_PROCESSING_ACT, NULL, NULL, mmi_ucm_clam_act_callback);
            }
            else
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_CLAM_CLOSE_P1, permit_result);
            }
        }
        else
        {
            mmi_ucm_end_all_action();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_clam_open_hdlr
 * DESCRIPTION
 *  Handler for clam open.
 * PARAMETERS
 *  evt     [IN] 
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_ucm_clam_open_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_clam_open();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_clam_close_hdlr
 * DESCRIPTION
 *  Handler for clam close.
 * PARAMETERS
 *  evt     [IN] 
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_ucm_clam_close_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_clam_close();

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_clam_act_callback
 * DESCRIPTION
 *  callback of action
 * PARAMETERS
 *  event:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_clam_act_callback(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ACT_CB_P2);
    MMI_ASSERT(srv_ucm_is_pending_action() == MMI_FALSE);

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL))
    {
        mmi_ucm_end_all_action();
    }
}

#endif /* __MMI_CLAMSHELL__ */


#ifdef __OP01_FWPBW__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_fwp_act_callback
 * DESCRIPTION
 *  callback of action
 * PARAMETERS
 *  event:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_ucm_fwp_act_callback(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(srv_ucm_is_pending_action() == MMI_FALSE);

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL))
    {
        mmi_ucm_end_all_action();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_fwp_end_all_call
 * DESCRIPTION
 *  End all calls
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_fwp_end_all_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum permit_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/              
    if (srv_ucm_is_pending_action() == MMI_TRUE)
    {
        permit_result = srv_ucm_query_act_permit(SRV_UCM_END_ALL_PROCESSING_ACT, NULL);
        
        if (SRV_UCM_RESULT_OK == permit_result)
        {
            srv_ucm_act_request(SRV_UCM_END_ALL_PROCESSING_ACT, NULL, NULL, mmi_ucm_fwp_act_callback);
        }
        else
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_FWP_END_ALL_CALL_P1, permit_result);
        }
    }
    else
    {
        mmi_ucm_end_all_action();
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_fwp_call_process_event_hdlr
 * DESCRIPTION
 *  a FWP call process mechanism. it will base on trigger event, transmitter status, 
 *  handfree status and  current existed calls situation to decide next state
 * PARAMETERS
 *  event:     [IN] trigger event
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_fwp_call_process_event_hdlr(mmi_ucm_fwp_call_process_event_enum event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL outgoing_only;
    MMI_BOOL incoming_only;
    MMI_BOOL connected_only;
    U8 audio_mode = mdi_audio_get_audio_mode();
    MMI_BOOL hold_on = srv_gpio_transmitter_is_hold_on();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL))
    {
        outgoing_only = (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL));
        incoming_only = (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL));
        connected_only = (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_CALL_TYPE_NO_CSD, NULL) == srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL));

        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_FWP_CALL_PROCESS_EVENT_HDLR, event, audio_mode, hold_on, incoming_only, outgoing_only, connected_only);

        switch(event)
        {
            case MMI_UCM_FWPCP_OUTGOING_EVENT:
                if (outgoing_only && !hold_on && AUD_MODE_NORMAL == audio_mode)
                {
                    srv_speech_enable_hand_free();
                }
                break;

            case MMI_UCM_FWPCP_ACCEPT_EVENT:
                if (connected_only && !hold_on && AUD_MODE_NORMAL == audio_mode)
                {
                    srv_speech_enable_hand_free();
                }
                break;

            case MMI_UCM_FWPCP_TRANSMITTER_HOLDON_EVENT:
                if (audio_mode == AUD_MODE_LOUDSPK)
                {
                    srv_speech_disable_hand_free();
                }

                if (incoming_only && AUD_MODE_HEADSET != audio_mode)
                {
                    mmi_ucm_incoming_call_sendkey();
                }
                break;

            case MMI_UCM_FWPCP_TRANSMITTER_PUTDOWN_EVENT:
                if (AUD_MODE_NORMAL == audio_mode)
                {
                    mmi_ucm_fwp_end_all_call();
                }
                break;

            case MMI_UCM_FWPCP_HANDFREE_KEY_EVENT:
                if (hold_on && AUD_MODE_LOUDSPK == audio_mode)
                {
                    srv_speech_disable_hand_free();
                }
                else if (hold_on && AUD_MODE_NORMAL == audio_mode)
                {
                    srv_speech_enable_hand_free();
                }
                else if (incoming_only && !hold_on && AUD_MODE_LOUDSPK == audio_mode)
                {
                    srv_speech_disable_hand_free();
                }
                else if (!incoming_only && !hold_on && AUD_MODE_LOUDSPK == audio_mode)
                {
                    mmi_ucm_fwp_end_all_call();
                }
                else if (incoming_only && !hold_on && AUD_MODE_NORMAL == audio_mode)
                {
                    srv_speech_enable_hand_free();
                    mmi_ucm_incoming_call_sendkey();
                }
                break;

            default:
                break;
        }
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_FWP_CALL_PROCESS_EVENT_HDLR, event, audio_mode, hold_on, 0, 0, 0);

        switch (event)
        {
            /* Set this in release indication, confirm if it is need to trigger dialer this time */
            case MMI_UCM_FWPCP_NOCALL_EVENT:
                if (hold_on)
                {
                    g_ucm_p->need_to_dialer = MMI_TRUE;
                }
                break;

            case MMI_UCM_FWPCP_LAUCH_DIALER_EVENT:
                if (hold_on && g_ucm_p->need_to_dialer)
                {
                    cui_dialer_close_if_present();
                    mmi_dialer_launch();
                }
                break;

            /* After set need_to_dialer to MMI_TRUE, if there is action about transmitter, set the flag to MMI_FALSE.
               It means it is no need to trigger dialer by call. Set it avoid to trigger dialer repeatedly. Dialer
               will handle itself in this time */
            case MMI_UCM_FWPCP_TRANSMITTER_HOLDON_EVENT:
            case MMI_UCM_FWPCP_TRANSMITTER_PUTDOWN_EVENT:
                g_ucm_p->need_to_dialer = MMI_FALSE;
                break;

            default:
                break;
        }
    }
}
#endif /* __OP01_FWPBW__ */


#ifdef MOTION_SENSOR_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_motion_turnover_reg
 * DESCRIPTION
 *  Register SRV_SENSOR_MOTION_TURNOVER handler for muting the incoming tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_motion_turnover_reg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_callset_flip_to_mute_call_get_mode() &&
        0 == g_ucm_p->call_misc.mute_handle &&
        srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        g_ucm_p->call_misc.mute_handle = srv_sensor_start_listen(SRV_SENSOR_MOTION_TURNOVER, NULL, mmi_ucm_motion_callback, NULL);
        srv_sensor_motion_enable_mode(g_ucm_p->call_misc.mute_handle, SRV_SENSOR_MOTION_ALWAYS_ON_MODE);
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_MOTION_TURNOVER_REG_P1, g_ucm_p->call_misc.mute_handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_motion_turnover_dereg
 * DESCRIPTION
 *  Deregister SRV_SENSOR_MOTION_TURNOVER handler for muting the incoming tone
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_motion_turnover_dereg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_misc.mute_handle &&
        (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) == 0 ||
         MMI_FALSE == srv_callset_flip_to_mute_call_get_mode()))
    {
        srv_sensor_stop_listen(g_ucm_p->call_misc.mute_handle);
        g_ucm_p->call_misc.mute_handle = 0;
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_MOTION_TURNOVER_DEREG);
    }
}


#if defined(__MMI_SOUND_RECORDER__) && defined(__MOTION_SENSOR_ADVANCED_GESTURE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_motion_double_tap_reg
 * DESCRIPTION
 *  Register SRV_SENSOR_MOTION_DOUBLE_TAP handler for Recording during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_motion_double_tap_reg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_callset_tap_tap_to_record_in_call_get_mode() &&
        0 == g_ucm_p->call_misc.sndrec_handle &&
        srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_NO_DATA_CSD, NULL) > 0)
    {
        g_ucm_p->call_misc.sndrec_handle = srv_sensor_start_listen(SRV_SENSOR_MOTION_DOUBLE_TAP, NULL, mmi_ucm_motion_callback, NULL);
        srv_sensor_motion_enable_mode(g_ucm_p->call_misc.sndrec_handle, SRV_SENSOR_MOTION_ALWAYS_ON_MODE);
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_MOTION_DOUBLE_TAP_REG_P1, g_ucm_p->call_misc.sndrec_handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_motion_double_tap_dereg
 * DESCRIPTION
 *  Deregister SRV_SENSOR_MOTION_DOUBLE_TAP handler for Recording during call
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_motion_double_tap_dereg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ucm_p->call_misc.sndrec_handle &&
        (MMI_FALSE == srv_callset_tap_tap_to_record_in_call_get_mode() ||
         srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_NO_DATA_CSD, NULL) == 0))
    {
        srv_sensor_stop_listen(g_ucm_p->call_misc.sndrec_handle);
        g_ucm_p->call_misc.sndrec_handle = 0;
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_MOTION_DOUBLE_TAP_DEREG);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_sndrec_handle_screen
 * DESCRIPTION
 *  Check if it is allowed to record in the input screen
 * PARAMETERS
 *  screen_id     [IN]  screen id
 * RETURNS
 *  SRV_UCM_RESULT_OK means it is allowed to record in the input screen
 *  else means that is not allowed.
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_sndrec_handle_screen(MMI_ID screen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SCR_ID_UCM_IN_CALL == screen_id ||
        SCR_ID_UCM_DTMF_EDITOR == screen_id ||
        SCR_ID_UCM_VOICE_DIALER == screen_id ||
        SCR_ID_UCM_VT_INCALL == screen_id ||
        SCR_ID_UCM_VT_DIALER == screen_id)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_sndrec_for_motion
 * DESCRIPTION
 *  execute sound recorder action if permit passes
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_sndrec_for_motion(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;
    srv_prof_play_req_struct play_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_query_sndrec_permit();

    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        mmi_ucm_display_error_popup(option_check_result);
    }
	else
	{
	    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
        /* Reuse waiting tone here. Just notify the user it is the time to record. */
        srv_prof_play_req_struct_init(&play_req, SRV_PROF_TONE_CALL_REMINDER);
        play_req.audio_id = TONE_WARNING2;
        play_req.play_style = SRV_PROF_RING_TYPE_ONCE;
        play_req.audio_type = SRV_PROF_AUDIO_DTMF;
        play_req.aud_path = MDI_DEVICE_SPEAKER2;
        srv_prof_play_tone_with_full_struct(&play_req);

		mmi_sndrec_entry_in_call();
	}
}
#endif /* defined(__MMI_SOUND_RECORDER__) && defined(__MOTION_SENSOR_ADVANCED_GESTURE__) */
#endif /* MOTION_SENSOR_SUPPORT */


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_is_lock_not_allowed_screen
 * DESCRIPTION
 *  This function is check if the input screen can be locked.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE means the screen cannot be locked;
 *  otherwise means can be locked.
 *****************************************************************************/
MMI_BOOL mmi_ucm_is_lock_not_allowed_screen(MMI_ID scr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SCR_ID_UCM_CALL_END == scr_id ||
        SCR_ID_UCM_PROCESSING == scr_id ||
        SCR_ID_UCM_AUTO_REDIAL == scr_id ||
        SCR_ID_UCM_SEND_DTMF == scr_id ||
        SCR_ID_UCM_DUMMY == scr_id ||
        SCR_ID_UCM_DISCONNECT_SCREEN == scr_id ||
        SCR_ID_UCM_GRAY_SCREEN == scr_id ||
        SCR_ID_UCM_VT_FALLTO_VOICE_NOTIFY == scr_id)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

#ifdef __MMI_BACKGROUND_CALL_WITH_NCENTER__
/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_go_homescreen_incall_action
 * DESCRIPTION
 *  Make the call to background and go homescreen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_go_homescreen_incall_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_enter_general_app_option(MMI_UCM_PERMIT_ONLY);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        mmi_ucm_display_error_popup(option_check_result);
    }
    else
    {
        MMI_ID pre_app_id = mmi_frm_get_previous_app_id(GRP_ID_UCM_MARKER);
        mmi_ucm_create_incall_notification();
    #ifdef __MMI_SCREEN_LOCK_CLASSIC__
        mmi_scr_locker_close();
    #endif /* __MMI_SCREEN_LOCK_CLASSIC__ */
        //mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_INCALL, SCR_ID_UCM_IN_CALL, (mmi_proc_func) NULL);
    #ifdef __MMI_VUI_LAUNCHER_KEY__
        vapp_launcher_key_on_before_idle_display();
    #endif /* __MMI_VUI_LAUNCHER_KEY__ */
        mmi_frm_close_to_idle_group_with_start_id(pre_app_id);
        mmi_frm_group_hide(GRP_ID_UCM_MARKER);
        mmi_frm_group_hide(GRP_ID_UCM_INCALL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_background_incall_action
 * DESCRIPTION
 *  Make the call to background
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_background_incall_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_result_enum option_check_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    option_check_result = mmi_ucm_enter_general_app_option(MMI_UCM_PERMIT_ONLY);

    if (SRV_UCM_RESULT_OK != option_check_result)
    {
        mmi_ucm_display_error_popup(option_check_result);
    }
    else
    {
        mmi_ucm_create_incall_notification();
        //mmi_frm_scrn_set_leave_proc(GRP_ID_UCM_INCALL, SCR_ID_UCM_IN_CALL, (mmi_proc_func) NULL);
        //mmi_frm_group_close(GRP_ID_UCM_MARKER);
        //mmi_frm_group_close(GRP_ID_UCM_INCALL);
    #ifdef __MMI_SCREEN_LOCK_CLASSIC__
        mmi_scr_locker_close();
    #endif /* __MMI_SCREEN_LOCK_CLASSIC__ */
        mmi_frm_group_hide(GRP_ID_UCM_MARKER);
        mmi_frm_group_hide(GRP_ID_UCM_INCALL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_create_incall_notification
 * DESCRIPTION
 *  Create a incall ongoing notificaiton.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_create_incall_notification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vsrv_ngroup_handle ghandle;
    vsrv_notification_handle nhandle;
    srv_ucm_call_type_enum incall_type = (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_VOIP_CALL_TYPE | SRV_UCM_DATA_CALL_TYPE_ALL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, incall_type, NULL) > 0)
    {
        ghandle = vsrv_ncenter_create_ngroup(VSRV_NGROUP_TYPE_SINGLE_TITLE, APP_UCM);
        nhandle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_ONGOING, ghandle, MMI_UCM_NOTIFICATION_ID);
        vsrv_ncenter_set_ngroup_title_id(ghandle, STR_ID_UCM_NCENTER_TITLE);
        mmi_ucm_set_notification_context(nhandle);
        vsrv_ncenter_notify_notification(nhandle);
        StartTimer(CM_UPDATE_NCENTER_TIMER, 1000, mmi_ucm_update_hdlr);
    }
    else
    {
        mmi_ucm_display_error_popup(SRV_UCM_RESULT_UNSPECIFIED_ERROR);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_set_notification_context
 * DESCRIPTION
 *  Set incall notification context
 * PARAMETERS
 *  nhandle            [IN]  Notification handler
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_set_notification_context(vsrv_notification_handle nhandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 call_count;
    S32 group_index_array[SRV_UCM_MAX_GROUP];
    srv_ucm_index_info_struct index;
    srv_ucm_call_info_struct call_info;
    srv_ucm_call_type_enum incall_type = (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_VOIP_CALL_TYPE | SRV_UCM_DATA_CALL_TYPE_ALL);
    mmi_image_src_struct icon;
    U16 state_string_id = 0;
    WCHAR *string_ptr;
    WCHAR *time_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    string_ptr = OslMalloc(MMI_UCM_MAXE_TITLE * ENCODING_LENGTH);
    time_ptr = OslMalloc(MMI_UCM_MAXE_TITLE * ENCODING_LENGTH);
    memset (string_ptr, 0, MMI_UCM_MAXE_TITLE * ENCODING_LENGTH);
    memset (time_ptr, 0, MMI_UCM_MAXE_TITLE * ENCODING_LENGTH);
    icon.type = MMI_IMAGE_SRC_TYPE_RES_ID;

    if (srv_ucm_query_group_count(SRV_UCM_ACTIVE_STATE, incall_type, MMI_FALSE, group_index_array) > 0)
    {
        state_string_id = STR_ID_UCM_NCENTER_MAINTEXT_ACTIVE;
        icon.data.res_id = IMG_ID_NCENTER_STATE_ACTIVE;
    }
    else if (srv_ucm_query_group_count(SRV_UCM_HOLD_STATE, incall_type, MMI_FALSE, group_index_array) > 0)
    {
        state_string_id = STR_ID_UCM_NCENTER_MAINTEXT_HELD;
        icon.data.res_id = IMG_ID_NCENTER_STATE_HELD;
    }
    else
    {
        MMI_ASSERT(0);
    }

    vsrv_ncenter_set_notification_icon(nhandle, icon);

    call_count = srv_ucm_query_group_data(group_index_array[0], NULL);
    index.group_index = group_index_array[0];
    index.call_index = 0;

    if (srv_ucm_query_call_data(index, &call_info))
    {
    #ifdef __MMI_CALLSET_CTD_CONFIGURABLE__
        if (MMI_TRUE == srv_callset_call_time_display_get_mode())
	#else
		if(MMI_TRUE)
	#endif
        {
            mmi_ucm_update_duration(&(call_info.start_time), time_ptr);
            kal_wsprintf((WCHAR *)string_ptr, "%w(%w)", GetString(state_string_id), time_ptr);
        }
        else
        {
            kal_wsprintf((WCHAR *)string_ptr, "%w", GetString(state_string_id));
        }

        vsrv_ncenter_set_notification_maintext_str(nhandle, string_ptr);

        if (call_count > 1)
        {
            vsrv_ncenter_set_notification_subtext_id(nhandle, STR_ID_UCM_NCENTER_SUBTEXT_CONFERENCE);
        }
        else
        {
            vsrv_ncenter_set_notification_subtext_str(nhandle, (WCHAR *)call_info.remote_info.disp_name);
        }
    }

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, incall_type, NULL) > 1)
    {
        kal_wsprintf((WCHAR *)string_ptr, "%w%w", GetString(STR_ID_UCM_END_ALL), GetString(STR_ID_UCM_QUESTION_MARK));
    }
    else
    {
        kal_wsprintf((WCHAR *)string_ptr, "%w%w", GetString(STR_ID_UCM_END_THIS_CALL_Q_MARK), GetString(STR_ID_UCM_QUESTION_MARK));
    }
    vsrv_ncenter_set_notification_questiontext_str(nhandle, string_ptr);

    vsrv_ncenter_set_notification_intent_callback(nhandle, mmi_ucm_intent_callback, NULL, 0);

    OslMfree(string_ptr);
    OslMfree(time_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_refresh_incall_notification
 * DESCRIPTION
 *  Refresh the incall ongoing notificaiton.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_refresh_incall_notification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vsrv_ngroup_handle ghandle;
    vsrv_notification_handle nhandle;
    srv_ucm_call_type_enum incall_type = (srv_ucm_call_type_enum)(SRV_UCM_VOICE_CALL_TYPE_ALL | SRV_UCM_VOIP_CALL_TYPE | SRV_UCM_DATA_CALL_TYPE_ALL);
    mmi_id parent_gid = mmi_frm_group_get_active_id();
    parent_gid = mmi_frm_group_get_top_parent_group_id(parent_gid);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, incall_type, NULL) > 0 &&
        parent_gid != GRP_ID_UCM_INCALL)
    {
        ghandle = vsrv_ncenter_query_ngroup(APP_UCM);
        if (ghandle)
        {
            nhandle = vsrv_ncenter_query_notification(ghandle, MMI_UCM_NOTIFICATION_ID);
            if (nhandle)
            {
                vsrv_ncenter_set_ngroup_title_id(ghandle, STR_ID_UCM_NCENTER_TITLE);
                mmi_ucm_set_notification_context(nhandle);
                vsrv_ncenter_notify_notification(nhandle);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_close_incall_notification
 * DESCRIPTION
 *  Close the incall ongoing notificaiton.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_close_incall_notification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vsrv_ngroup_handle ghandle;
    vsrv_notification_handle nhandle;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ghandle = vsrv_ncenter_query_ngroup(APP_UCM);
    if (ghandle)
    {
        nhandle = vsrv_ncenter_query_notification(ghandle, 1);
        if (nhandle)
        {
            vsrv_ncenter_close_notification(nhandle);
            vsrv_ncenter_close_ngroup(ghandle);
            StopTimer(CM_UPDATE_NCENTER_TIMER);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_intent_callback
 * DESCRIPTION
 *  Notification intent callback
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_intent_callback(vsrv_notification_handle nhandle, vsrv_nintent intent, void* userData, U32 userDataSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(intent.type == VSRV_NINTENT_TYPE_LAUNCH)
    {
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
        {
            //mmi_ucm_sg_create(GRP_ID_ROOT, GRP_ID_UCM_MARKER);
            //mmi_ucm_sg_create(GRP_ID_ROOT, GRP_ID_UCM_INCALL);
            //mmi_ucm_enter_in_call();
            mmi_frm_group_unhide(GRP_ID_UCM_MARKER);
            mmi_frm_group_unhide(GRP_ID_UCM_INCALL);
            mmi_ucm_close_incall_notification();
        }
    }
    else if(intent.type == VSRV_NINTENT_TYPE_TERMINATE)
    {
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 1)
        {
            mmi_ucm_end_all_action();
        }
        else
        {
            mmi_ucm_end_single_action();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_enable_ncenter
 * DESCRIPTION
 *  Enable the ncenter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_enable_ncenter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_ENABLE_NCENTER);

    if ((0 == srv_ucm_query_call_count((srv_ucm_call_state_enum)(SRV_UCM_OUTGOING_STATE | SRV_UCM_INCOMING_STATE), SRV_UCM_CALL_TYPE_ALL, NULL)) &&
        (0 == srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VIDEO_CALL_TYPE, NULL)))
    {
    #if defined(__MMI_TOUCH_SCREEN__)
        vapp_ncenter_enable_drag();
    #endif /* __MMI_TOUCH_SCREEN__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_disable_ncenter
 * DESCRIPTION
 *  Disable the ncenter
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_disable_ncenter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_UCM_DISABLE_NCENTER);

    if (srv_ucm_query_call_count((srv_ucm_call_state_enum)(SRV_UCM_OUTGOING_STATE | SRV_UCM_INCOMING_STATE), SRV_UCM_CALL_TYPE_ALL, NULL) ||
        srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VIDEO_CALL_TYPE, NULL))
    {
    #if defined(__MMI_TOUCH_SCREEN__)
        vapp_ncenter_disable_drag();
    #endif /* __MMI_TOUCH_SCREEN__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_update_hdlr
 * DESCRIPTION
 *  update the ncenter info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_update_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucm_refresh_incall_notification();
    StartTimer(CM_UPDATE_NCENTER_TIMER, 1000, mmi_ucm_update_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ucm_update_duration
 * DESCRIPTION
 *  update teh call time duration
 * PARAMETERS
 *  start_time            [IN] start time
 *  dur_string            [OUT] duration string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ucm_update_duration(MYTIME *start_time, WCHAR *dur_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME curr_time, duration;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset (&duration, 0, sizeof(MYTIME));
    DTGetRTCTime(&curr_time);

    if (start_time->nYear == 2030 &&
        curr_time.nYear < start_time->nYear)
    {
        curr_time.nYear = start_time->nYear;
        curr_time.nMonth = start_time->nMonth;
        curr_time.nDay = start_time->nDay + 1;
    }

    GetTimeDifference(&curr_time, start_time, &duration);
    duration_string(
        (UI_time*)(&duration),
        (UI_string_type) dur_string,
        DT_ACTIVE_CALL_SCREEN);
}

#endif /* __MMI_BACKGROUND_CALL_WITH_NCENTER__ */

#endif /* __MMI_UCM__ */
