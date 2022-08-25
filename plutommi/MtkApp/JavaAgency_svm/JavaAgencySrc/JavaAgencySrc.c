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
 * JavaSrc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to handle all scenario of Java Content Manager and 
 *   interaction betweens MMI and Java task.
 *
 * Author:
 * -------
 * -------
 *
*==============================================================================
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifdef __J2ME__

#include "MMI_features.h"
#include "MMI_include.h"

#include "StatusIconRes.h"

#include "drm_gprot.h"
#include "drm_def.h"

#include "RightsMgrGProt.h"             /* mmi_rmgr_populate_drm_info*/

#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
/* under construction !*/
#endif


//#include "MTPNP_AD_Master_common_def.h"
//#include "MTPNP_AD_master_if.h"         /* MTPNP_AD_Get_UsableSide*/

#include "jal.h"
#include "jam_msg_handler.h"
#include "j2me_trace.h"
#include "jvm_adaptor.h"
#include "j2me_custom.h"
#include "jam_internal.h"
#include "jma_interface.h"
#include "FunAndGamesResDef.h"
#include "jvm_internal.h"
#include "jam_msg_util.h"
#include "JavaAgencyDef.h"
#include "JavaAgencyProt.h"
#include "JavaAgencyGProt.h"

#include "CommonScreens.h"              /* gIndexIconsImageList*/
#include "SettingDefs.h"
#include "PhoneBookDef.h"               /* need IMG_PROCESSING_PHONEBOOK */
#include "SettingProfile.h"             /* EMPTY_LIST_TONE */
#include "cbm_api.h"                    /* cbm_register_app_id*/
#include "WapResDef.h"
#include "IdleHomescreenGProt.h"
#include "FileManagerDef.h"
#include "mmiapi_res.h"
#include "IdleGprot.h"
#ifdef __USB_IN_NORMAL_MODE__
#include "ConnectivityResDef.h" /* STR_ID_USB_MODE_EXPORTED_WARNING */
#endif
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif
#if( defined (__MMI_USB_SUPPORT__) && defined( __PLUTO_MMI_PACKAGE__ ))
#include "USBDeviceGprot.h"
#endif
#ifdef __DM_SCOMO_SUPPORT__
#include "Dmuigprot.h"
#endif

#ifdef __DM_LAWMO_SUPPORT__
#include "dmuigprot.h"
#endif

#ifdef __MMI_UCM__
#include "UCMGprot.h"
#endif 
#include "mmiapi_struct.h"

#ifdef __OP02__
#include "BrowserGprots.h"
#endif
#include "inlinecuigprot.h"         /* inline cui event type */
#include "Dataaccountcuigprot.h"    /* dtcnt cui event type */
#include "Cbmcuigprot.h"            /* always ask & bearer fallback cui event type */

#include "Filemgrsrvgprot.h" /* Fmgr service. */
#include "Filemgrcuigprot.h"
#include "Menucuigprot.h"

#ifdef SUPPORT_JSR_179
#if defined(__AGPS_SUPPORT__) && defined(__SUPL_SUPPORT__)
#include "supl2mmi_enums.h"
#include "supl2mmi_struct.h"
#endif

#include "GPSGProt.h"
#endif
#include "JavaAppFactorySrvProt.h"
#include "AppMgrSrvProt.h"
#include "CommonScreensResDef.h"
#include "mmi_rp_srv_filemanager_def.h"
#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_java_srv.h"
#include "mmi_rp_vapp_vol_dialog_def.h"
#endif
#include "fileMgrResdef.h"
#include "profilessrvgprot.h"
#include "profilessrv.h"
#include "gpiosrvgprot.h"
/************************************************************************/
/* Golbal Variable                                          */
/************************************************************************/

U8 g_mmi_java_aud_volume_level = 0xff;  /* 0~6 */
U8 g_mmi_java_is_vib_on = MMI_FALSE;        /* on-off */
#ifdef SUPPORT_JAVA_NET_ICON_SETTING
/* under construction !*/
#endif

U8 g_mmi_java_app_id = 0;
U8 g_mmi_java_install_app_id = 1;

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
U8 g_mmi_java_vk_permission = 0;    /* J2ME_Choice in JavaAgencyDef.h */
#endif

#if defined( SUPPORT_JSR_179 ) && defined(__AGPS_SUPPORT__)
U8 g_mmi_java_location_select = 0;
#endif

U8 g_mmi_java_bk_light = 0;
extern kal_bool g_jam_in_terminating;

MMI_BOOL get_setting_only = MMI_FALSE;
MMI_BOOL get_domain_setting = MMI_FALSE;
S8* gJavaPrintableStr;

java_context_struct g_java;
MMI_BOOL g_java_fmgr_skip_filter_none = MMI_TRUE;

extern kal_bool g_is_asm_allow_to_launch;
extern MMI_BOOL mmi_java_resume_pending_flag;

static FuncPtr g_mmi_java_restore_factory_call_back = NULL;
/*  notify state variables */
#ifdef __MMI_JAVA_INSTALL_DELETE_NOTIFIER__ 
MMI_BOOL g_mmi_java_post_notify_result = MMI_TRUE;
#endif

kal_char g_mmi_java_current_selected_mids_root[128];
kal_int32 g_mmi_java_current_selected_vm_id = -1;
extern S32 GetChildMenuIDIndexByParentMenuID(U16 parentMenuId, U16 childMenuId);
#define MAX_SEND_MENU_ITEM        (10)
S32 g_mmi_java_mids_package_menu_id;
S32 g_mmi_java_mids_package_execute_menu_id;
S32 g_mmi_java_mids_package_menu_index;
U16 *g_mmi_java_mids_package_file_path = NULL;
U16 g_mmi_java_mids_package_dir_path[SRV_FMGR_PATH_MAX_LEN +1] = {0};
U8 *g_mmi_java_mids_package_send_menu_item[MAX_SEND_MENU_ITEM];
S32 g_mmi_java_package_mode;
S32 g_mmi_java_total_send_item_number;
MMI_BOOL g_mmi_java_is_in_package;
U32 g_java_select_disk_screen = -1;
extern MMI_BOOL g_mmi_java_is_background_display;

#ifdef __DM_LAWMO_SUPPORT__
extern void  mmi_java_dmui_lawmo_callback_hdlr(
               mmi_dmui_app_id_enum app_id, 
               mmi_dmui_cmd_enum cmd);
extern kal_int8 mmi_dmui_is_phone_lock(void);

#endif  /* __DM_LAWMO_SUPPORT__ */

extern mmi_java_cmd_enum g_mmi_java_current_running_cmd;


extern void mmi_java_resend_timealarm_push_res(void);
extern kal_int32 g_jam_start_up_mode;
kal_bool g_resend_push = KAL_FALSE;
extern void jam_mids_getlist_exit_free(void);
static MMI_BOOL g_mmi_java_allow_stopped_popup_display = MMI_TRUE;
extern void mmi_fng_setting_java_done_hdlr(void);
extern mmi_id g_java_setting_inline;
extern mmi_id g_java_security_inline;
mmi_id g_java_opt_setting_inline;
mmi_id g_java_domain_inline;
mmi_id g_mmi_java_opt_menu_cui;
#define JAVA_SETTING_NETWORK_ACCESS_CAPTION              CUI_INLINE_ITEM_ID_BASE+0
#define JAVA_SETTING_NETWORK_ACCESS_SELECT                  CUI_INLINE_ITEM_ID_BASE+1
#define JAVA_SETTING_AUTO_INVOCATION_CAPTION           CUI_INLINE_ITEM_ID_BASE+2
#define JAVA_SETTING_AUTO_INVOCATION_SELECT               CUI_INLINE_ITEM_ID_BASE+3
#define JAVA_SETTING_MESSAGING_CAPTION                     CUI_INLINE_ITEM_ID_BASE+4
#define JAVA_SETTING_MESSAGING_SELECT                         CUI_INLINE_ITEM_ID_BASE+5
#define JAVA_SETTING_MULTIMEDIA_CAPTION         CUI_INLINE_ITEM_ID_BASE+6
#define JAVA_SETTING_MULTIMEDIA_SELECT            CUI_INLINE_ITEM_ID_BASE+7
#define JAVA_SETTING_FILE_READ_CAPTION                      CUI_INLINE_ITEM_ID_BASE+8
#define JAVA_SETTING_FILE_READ_SELECT                          CUI_INLINE_ITEM_ID_BASE+9
#define JAVA_SETTING_FILE_WRITE_CAPTION          CUI_INLINE_ITEM_ID_BASE+10
#define JAVA_SETTING_FILE_WRITE_SELECT                  CUI_INLINE_ITEM_ID_BASE+11
#define JAVA_SETTING_LOCAL_CONNECTIVITY_CAPTION        CUI_INLINE_ITEM_ID_BASE+12
#define JAVA_SETTING_LOCAL_CONNECTIVITY_SELECT                           CUI_INLINE_ITEM_ID_BASE+13
 #ifdef SUPPORT_JSR_179
#define JAVA_SETTING_LOVAL_LOCATION_ACCESS_CAPTION         CUI_INLINE_ITEM_ID_BASE+14
#define JAVA_SETTING_LOVAL_LOCATION_ACCESS_SELECT         CUI_INLINE_ITEM_ID_BASE+15
#endif

#if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
void mmi_java_save_as_file_evt_hdlr(mmi_event_struct * param);
void mmi_java_send_mids_package_req(void);
#endif
kal_bool g_mmi_java_is_no_network_usable = KAL_TRUE;

mmi_ret mmi_java_fmgr_jma_notify_hdlr(mmi_event_struct *param);
mmi_ret mmi_java_fmgr_java_notify_hdlr(mmi_event_struct *param);
mmi_ret mmi_java_fmgr_card_plug_out_hdlr(mmi_event_struct *param);
#ifdef __COSMOS_MMI_PACKAGE__
extern mmi_ret vapp_java_volume_event_hdlr(mmi_event_struct *evt);
#endif
#ifdef SUPPORT_JSR_179
void mmi_java_location_set_agps_req(void *MsgStruct);
#endif

/*****************************************************************************
 * FUNCTION
 *  InitJAVA
 * DESCRIPTION
 *  Invoked by InitFunAndGamesApp to init highlight/hint/protocol event handlers and
 *  Java MMI context for Java MMI/CM application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void InitJAVA(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_app_info_struct info;
    cbm_app_info_struct info_install;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_shutdown_all_ind, MSG_ID_MMI_JAVA_SHUTDOWN_ALL_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mid_stop_ind, MSG_ID_MMI_JAVA_MID_STOP_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mid_start_cnf, MSG_ID_MMI_JAVA_MID_START_CNF);

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_getinfo_cnf, MSG_ID_MMI_JAVA_MIDS_GETINFO_CNF);

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_set_setting_cnf, MSG_ID_MMI_JAVA_MIDS_SET_SETTING_CNF);

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_package_cnf, MSG_ID_MMI_JAVA_MIDS_PACKAGE_CNF);

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_set_mode_cnf, MSG_ID_MMI_JAVA_SET_MODE_CNF);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_tck_result_ind, MSG_ID_MMI_JAVA_TCK_RESULT_IND);

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_timealarm_push_ind, MSG_ID_MMI_JAVA_TIMEALARM_PUSH_IND);

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_java_abort_cnf, MSG_ID_MMI_JAVA_ABORT_CNF);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_delete_menu_abort_cnf, MSG_ID_MMI_JAVA_DELETE_MENU_ABORT_CNF);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_reset_rms_ind, MSG_ID_MMI_JAVA_INSTALL_RESET_RMS_IND);

    /* User Permission */
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_get_permission_ind, MSG_ID_MMI_JAVA_GET_PERMISSION_IND);

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_get_imsi_ind, MSG_ID_MMI_JAVA_GET_IMSI_IND);

    /* restore factory mode */
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_restore_factory_mode_cnf, MSG_ID_MMI_JAVA_RESTORE_FACTORY_MODE_CNF);

#if defined(J2ME_SUPPORT_PAUSE) || defined(J2ME_SUPPORT_BACKGROUND)
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_pause_ind, MSG_ID_MMI_JAVA_PAUSE_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_resume_ind, MSG_ID_MMI_JAVA_RESUME_IND);
#endif

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_terminate_ind, MSG_ID_MMI_JAVA_TERMINATE_IND);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_terminating_ind, MSG_ID_MMI_JAVA_TERMINATING_IND); //20110221

#if defined(J2ME_SUPPORT_BACKGROUND)
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_update_status_bar_ind, MSG_ID_MMI_JAVA_UPDATE_STATUS_BAR_IND);
#endif /* J2ME_SUPPORT_BACKGROUND */
#if defined(__MMI_BT_AUDIO_VIA_SCO__)
    SetProtocolEventHandler((PsFuncPtr) jma_media_player_connect_bt_via_sco, MSG_ID_MMI_JAVA_CONNECT_BT_VIA_SCO_REQ);
#endif    
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
#endif    
#ifdef OGDR_SECURITY_SETTING
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_set_default_domain_cnf,MSG_ID_MMI_JAVA_SET_DEFAULT_DOMAIN_CNF);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_get_default_domain_cnf,MSG_ID_MMI_JAVA_GET_DEFAULT_DOMAIN_CNF);
#endif
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_get_setting_cnf, MSG_ID_MMI_JAVA_MIDS_GET_SETTING_CNF);
    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mid_getlist_cnf, MSG_ID_MMI_JAVA_MID_GETLIST_CNF);

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_make_call_req, MSG_ID_MMI_JAVA_PR_MAKE_CALL_REQ);
    

        /*  java auto verifciation */
#ifdef __JAVA_MANAGER__
        SetProtocolEventHandler((PsFuncPtr) tst_mmi_java_cmd_req_handler, MSG_ID_TST_MMI_JAVA_CMD_REQ);
#endif
        SetProtocolEventHandler((PsFuncPtr) mmi_java_mids_getlist_detect_rsp_hdlr,MSG_ID_MMI_JAVA_MIDS_GETLIST_DETECT_RSP);

SetProtocolEventHandler((PsFuncPtr) mmi_java_network_detect_req_hdlr,MSG_ID_MMI_JAVA_NW_USABLE_REQ);

#ifdef SUPPORT_JSR_179
    SetProtocolEventHandler((PsFuncPtr) mmi_java_location_set_agps_req, MSG_ID_MMI_JAVA_SET_AGPS_REQ);
#endif

#ifdef __DM_LAWMO_SUPPORT__
    mmi_dmui_lawmo_register_notify(
                 MMI_DMUI_APP_ID_JAVA, 
                 MMI_DMUI_MO_TYPE_LAWMO_LOCK, 
                 mmi_java_dmui_lawmo_callback_hdlr);
#endif
    mmi_java_install_init();
    /* java network dtcnt init */
    mmi_java_nw_init(); 
    /* java network dtcnt register delete & modify event CB */
    mmi_java_nw_dtcnt_changes_reg_event(NULL);
#ifdef __SIM_HOT_SWAP_SUPPORT__    
    /* java network register sim detected event to response sim hot swap */
    mmi_java_nw_sim_detected_reg_event(NULL);
#endif
    
    g_java.total_java_app_mids = 0;
    g_java.total_java_app_mid = 0;

    g_java.mids_install_state = INSTALL_VALID_STATE;
    g_java.mids_update_state = UPDATE_VALID_STATE;
    g_java.mids_delete_state = DELETE_VALID_STATE;
    g_java.msg_ctrl = 0;
    mmi_java_load_setting();
    gJavaPrintableStr = (S8*)subMenuData;

    info.app_str_id = STR_SCR_JAVA_CAPTION;
    info.app_icon_id = IMG_MENU3108_JAVA;
    info.app_type = DTCNT_APPTYPE_JAVA;
    cbm_register_app_id_with_app_info(&info, &g_mmi_java_app_id);
    
    info_install.app_str_id = STR_JAVA_START_INSTALLING;
    info_install.app_icon_id = IMG_MENU3108_JAVA;
    info_install.app_type = DTCNT_APPTYPE_JAVA;
    cbm_register_app_id_with_app_info(&info_install, &g_mmi_java_install_app_id);

    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION, mmi_java_fmgr_jma_notify_hdlr, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT, mmi_java_fmgr_java_notify_hdlr, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, mmi_java_fmgr_card_plug_out_hdlr, NULL);
    #ifdef __COSMOS_MMI_PACKAGE__
    mmi_frm_cb_reg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE,(mmi_proc_func)vapp_java_volume_event_hdlr, NULL);
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_fmgr_jma_notify_hdlr
 * DESCRIPTION
 *  FMGR evt cb when file move/delete/delete_all happen
 * PARAMETERS
 *  param   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_java_fmgr_jma_notify_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_adv_action_event_struct *adv_action = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch(param->evt_id)
    {
    case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
        adv_action = (srv_fmgr_notification_adv_action_event_struct *) param;
        if (adv_action->state == SRV_FMGR_NOTIFICATION_ACTION_MOVE ||
            adv_action->state == SRV_FMGR_NOTIFICATION_ACTION_DELETE)
        {
            if(jma_audio_player_is_playing((kal_int8 *)adv_action->src_filepath,
                                            (kal_int8)(adv_action->src_fileinfo.attribute & FS_ATTR_DIR), 
                                            MMI_FALSE))
            {
                return MMI_RET_ERR;
            }
        }
        else if (adv_action->state == SRV_FMGR_NOTIFICATION_ACTION_DELETE_ALL)
        {
            /* avoid: delete all image files. need not check*/
            if (!srv_fmgr_types_filter_is_in_group(adv_action->filter, FMGR_GROUP_AUDIO))
            {
                return MMI_RET_OK;
            }
            if(jma_audio_player_is_playing((kal_int8 *)adv_action->src_filepath, 
                                            (kal_int8)(adv_action->src_fileinfo.attribute & FS_ATTR_DIR),
                                            MMI_TRUE))
            {
                return MMI_RET_ERR;
            }
        }
        break;
       }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_menu
 * DESCRIPTION
 *  Highlight handler routine for Java menu item in FunAndGames menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* void Highlight_JAVA_MENU(void) */
void mmi_java_highlight_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_java.mids_list_filter.filter_type = JAM_NONE_FILTER;
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(EntryScrJavaMenu,KEY_EVENT_UP);
    SetLeftSoftkeyFunction(EntryScrJavaMenu, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mids_get_list_req
 * DESCRIPTION
 *  Send message to java task, and get the MIDlet list back
 * PARAMETERS
 *  start_index     [IN]        The start point of the list
 *  extend_mode     [IN]        Send message and sync with java side, get list from pointer of pointer
 *  ptr             [OUT]       Pointer to the pointer of the list
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mids_get_list_req(
        int start_index, 
        MMI_BOOL extend_mode, 
        mmi_java_mids_getlist_cnf_struct **ptr, 
        jam_getlist_filter_struct *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_getlist_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_MIDS_GETLIST_REQ);

    msg = (mmi_java_mids_getlist_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mids_getlist_req_struct));
    msg->start_indx = start_index;
    msg->mids_list_count = -1;
    msg->extend_mode = extend_mode;
    msg->confirm_data_ptr = ptr;
    msg->filter = filter;

    mmi_java_send_message_from_active_mod( MOD_JAM, MMI_J2ME_SAP,
        MSG_ID_MMI_JAVA_MIDS_GETLIST_REQ, msg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_getlist_detect_rsp_hdlr
 * DESCRIPTION
 *  Detect jam is busy or not before get list(For MAUI_02135936).
 * PARAMETERS
 *
 * RETURNS
 * 
 *****************************************************************************/
void mmi_java_mids_getlist_detect_rsp_hdlr(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_java_resume_pending_flag)
        {
            mmi_java_resume_pending_flag = MMI_FALSE;
        }
    else 
        return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_getlist_detect_jam_busy
 * DESCRIPTION
 *  Detect jam is busy or not before get list(For MAUI_02135936).
 * PARAMETERS
 *
 * RETURNS
 * 
 *****************************************************************************/
void mmi_java_getlist_detect_jam_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_GETLIST_DETECT);
    mmi_java_send_message_from_active_mod( MOD_JAM, MMI_J2ME_SAP,
        MSG_ID_MMI_JAVA_MIDS_GETLIST_DETECT_REQ, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_fetch_mids_list
 * DESCRIPTION
 *  
 *  get the (item_index)th mids from java
 *  
 *  cache item_index ~ item_index+MMI_MAX_MENUITEMS_IN_CONTENT
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]        == null  => void If imeage_full= null  => void
 *  img_buff_p          [?]         
 *  str_img_mask        [IN]        
 *  image_buff_p: a pointer , will be assigned to the image icon of mids(?)
 *  needToSendGetListReq:  If (item_index)th mids in cache(?)
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL needToSendGetListReq = MMI_TRUE;
static S32 last_item_index = -1;
MMI_BOOL forceRefresh = MMI_FALSE;
kal_bool g_java_list_lock = KAL_FALSE;
MMI_BOOL mmi_java_fetch_mids_list(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(jam_mvm_is_shutdowning())
    {
        return KAL_FALSE;
    }
    if ((g_java.msg_ctrl & SEND_MID_GET_LIST_CTRL)||(g_java.msg_ctrl & SEND_MIDS_GET_LIST_CTRL))
    {
        return KAL_FALSE;
    }
    g_java.msg_ctrl |= SEND_MIDS_GET_LIST_CTRL;
    
    if(mmi_java_resume_pending_flag == MMI_TRUE)
    {
        last_item_index = item_index;
        mmi_java_getlist_detect_jam_busy();
        g_java.msg_ctrl &= (~SEND_MIDS_GET_LIST_CTRL);
        return MMI_FALSE;
    }
    if (g_java.mids_info_start > item_index || item_index >= g_java.mids_info_end ||forceRefresh)
    {
        needToSendGetListReq = MMI_TRUE;
    }
    else
    {
        needToSendGetListReq = MMI_FALSE;
    }
    if (needToSendGetListReq)
    {
        /* search the cache */
        int i;
        U32 event_group;
        mmi_java_mids_getlist_cnf_struct *ptr;
        S32 saved_item_index = item_index;
        mmi_java_send_mids_get_list_req(saved_item_index, MMI_TRUE, &ptr, &g_java.mids_list_filter);
        kal_retrieve_eg_events(g_java_event_group_2, JAVA_EG_GETLIST_1, KAL_OR_CONSUME, (kal_uint32*)&event_group, KAL_SUSPEND);
        for (i = 0; i < ptr->mids_list_count; i++)
        {
            g_java.mids_info[i] = ptr->pmids_list[i];
        }

        g_java.mids_info_start = ptr->start_indx;
        g_java.mids_info_end = ptr->start_indx + ptr->mids_list_count;
        g_java.total_java_app_mids = ptr->mids_count;

        free_local_para((local_para_struct*) ptr);
    }
    else
    {
        if (!(item_index < g_java.total_java_app_mids
              && g_java.mids_info_start <= item_index && item_index <= g_java.mids_info_end))
        {
            EXT_ASSERT(item_index,g_java.total_java_app_mids,g_java.mids_info_start,g_java.mids_info_end);
        }
    }

    if (g_java.total_java_app_mids == 0)
    {
        last_item_index = item_index;
        forceRefresh = MMI_FALSE;
        g_java.msg_ctrl &= (~SEND_MIDS_GET_LIST_CTRL);
        return MMI_TRUE;
    }

    EXT_ASSERT(g_java.mids_info_start <= item_index && item_index <= g_java.mids_info_end,
        g_java.total_java_app_mids,
        g_java.mids_info_start,
        g_java.mids_info_end);

    /* fetch the icon */
    if (img_buff_p)
    {
        kal_char* temp_storage_name = NULL;
        if (g_java.mids_info[item_index - g_java.mids_info_start].mids_icon != NULL)
        {
            (*img_buff_p) = (PU8) g_java.mids_info[item_index - g_java.mids_info_start].mids_icon;
        }
        else
        {
            if (g_java.mids_info[item_index - g_java.mids_info_start].mid_count == 1)
            {
                (*img_buff_p) = (PU8) GetImage(IMG_JAVA_STAR1);
            }
            else
            {
                (*img_buff_p) = (PU8) GetImage(IMG_JAVA_STAR2);
            }
        }
    }
    /* fetch the item name */

    if (str_buff)
    {
        mmi_ucs2ncpy(
            (S8*) str_buff,
            (const S8*)g_java.mids_info[item_index - g_java.mids_info_start].mids_name,
            MAX_SUBMENU_CHARACTERS);
    }
    last_item_index = item_index;
    forceRefresh = MMI_FALSE;
    g_java.msg_ctrl &= (~SEND_MIDS_GET_LIST_CTRL);
    return MMI_TRUE;
}

S32 mmi_java_guess_start_index(S32 item_index)
{    
    S32 start_index = 0;
    if(item_index >= g_java.mids_info_end)
    {
        start_index = item_index -MMI_MAX_MENUITEMS_IN_CONTENT-MMI_MAX_MENUITEMS_IN_CONTENT/2;
        if(start_index < 0)
            start_index = 0;
        forceRefresh = MMI_TRUE;
        return start_index;
    }
    if(item_index < g_java.mids_info_start)
    {
        start_index = item_index - MMI_MAX_MENUITEMS_IN_CONTENT/2;
        if(start_index < 0)
            start_index = 0;    
        forceRefresh = MMI_TRUE;
        return start_index;
    }
    return item_index;
}

MMI_BOOL mmi_java_get_list_data(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    S32 start_index = 0;
    start_index = mmi_java_guess_start_index(item_index);
    mmi_java_fetch_mids_list(start_index, str_buff, img_buff_p, str_img_mask);
    return MMI_TRUE;
}
S32 mmi_java_get_list_data_async(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    S32 index = 0;
    for(index = 0; index<data_size; index++)
    {
        mmi_java_get_list_data(start_index,menu_data[index].item_list[0], &menu_data[index].image_list[0],0);
        start_index++;
    }
    return data_size;
}

/*****************************************************************************
 * FUNCTION
 *  flushListCache
 * DESCRIPTION
 *  flush the list cacahe
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 
extern void gui_list_get_displayed_item_range(U32 *start_index, U32 *end_index);
void flushListCache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 start_index = -1;
    U32 end_index = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_list_get_displayed_item_range(&start_index,&end_index);
    if (g_java.mids_info_start <= start_index && start_index < g_java.mids_info_end 
        && g_java.mids_info_start <= end_index && end_index < g_java.mids_info_end )
    {
        return;
    }
    forceRefresh = MMI_TRUE;
    if (start_index >= 3)
    {
        start_index -= 3;
    }
    mmi_java_fetch_mids_list(start_index, NULL, NULL, NULL);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_menu_ask_terminate_cb
 * DESCRIPTION
 *  Callback function to handle
 *  Ask user if they want to terminate VM first before install MIDlet
 * PARAMETERS
 *  teminate    [IN]    user select yes/No
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_menu_ask_terminate_cb(MMI_BOOL terminate)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (terminate)
    {
        g_java.screen_after_terminate = TER_ENTRY_JAVA_MENU;
        jam_enter_terminate_mode(g_mmi_java_current_selected_vm_id);
        g_mmi_java_current_selected_vm_id = -1;
        mmi_java_entry_terminating(MMI_FALSE);
    }
}

#if defined(__MMI_JAVA_FMGR_HYPERLINK__)
/*****************************************************************************
 * FUNCTION
 *  mmi_java_get_hyperlink_sub_title
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S8* mmi_java_get_hyperlink_sub_title(S8* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 strlen;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_java.fmgr_hyperlink_sub_title;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_get_hyperlink_sub_title
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_prepare_hyperlink_sub_title(S8* path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 strlen;
    kal_int32 vm_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!jam_vm_task_ready()) 
    {
        mmi_ucs2ncpy(
            g_java.fmgr_hyperlink_sub_title, 
            GetString(STR_JAVA_QUESTIONARY), 
            2);        
        strlen = mmi_ucs2strlen(g_java.fmgr_hyperlink_sub_title);        
        mmi_ucs2ncat(
            g_java.fmgr_hyperlink_sub_title, 
            GetString(STR_JAVA_PROGRAM), 
            FMGR_SUB_TITLE_LENGTH - strlen);        
        return;
    }
    if (jam_is_busy())
    {
        strlen = mmi_ucs2strlen(GetString(STR_JAVA_VM_BUSY));
        memcpy(
            g_java.fmgr_hyperlink_sub_title, 
            GetString(STR_JAVA_VM_BUSY), 
            strlen*2);
    }
    else
    {
    /* Get the number of midlet suites */
    g_java.mids_list_filter.filter_type = JAM_DISK_FILTER;
    g_java.mids_list_filter.disk_name = (kal_int32)path[0];

    /* Phone */
    if ((kal_int32)path[0] == SRV_FMGR_PUBLIC_DRV)
    {
        g_java.mids_list_filter.filter_type |= JAM_DEFAULT_GAME_FILTER;
    }
    
    g_java.mids_info_end = g_java.mids_info_start = -1;
    needToSendGetListReq = MMI_TRUE;
    mmi_java_fetch_mids_list(0, (UI_string_type) NULL, (PU8*) NULL, 0);

    /* Use "application" or "applications" */
    kal_wsprintf((WCHAR*)g_java.fmgr_hyperlink_sub_title, "%d ", g_java.total_java_app_mids);
    strlen = mmi_ucs2strlen(g_java.fmgr_hyperlink_sub_title);

    if (g_java.total_java_app_mids == 0 || g_java.total_java_app_mids == 1)
    {
        mmi_ucs2ncat(
            g_java.fmgr_hyperlink_sub_title, 
            GetString(STR_JAVA_PROGRAM), 
            FMGR_SUB_TITLE_LENGTH - strlen);
    }
    else
    {
        mmi_ucs2ncat(
            g_java.fmgr_hyperlink_sub_title, 
            GetString(STR_JAVA_PROGRAMS), 
            FMGR_SUB_TITLE_LENGTH - strlen);
    } 
    if(!jam_mvm_is_vm_running(vm_id)&&!jam_mvm_is_vm_terminating(vm_id))
    {       
        jam_mids_getlist_exit_free();
    }
    }
}

/*****************************************************************************
 * FUNCTION
 *  EntryScrJavaMenu
 * DESCRIPTION
 *  Enter the Java menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_mids_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *filepath;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filepath = mmi_fmgr_get_current_fileinfo(NULL,NULL);
    ASSERT(filepath != NULL);

    g_java.mids_list_filter.filter_type = JAM_DISK_FILTER;
    g_java.mids_list_filter.disk_name = (kal_int32)filepath[0];

    /* Phone */
    if ((kal_int32)filepath[0] == SRV_FMGR_PUBLIC_DRV)
    {
        g_java.mids_list_filter.filter_type |= JAM_DEFAULT_GAME_FILTER;
    }
    g_java_fmgr_skip_filter_none = MMI_FALSE;
    EntryScrJavaMenu();
}
#endif

#ifdef __MMI_FTE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_java_mids_tap_callback_funtion
 * DESCRIPTION
 *  tap menuitem call back.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_mids_tap_callback_funtion(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 linkcount;
    kal_int32 vm_id = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM ||
        jam_mvm_is_shutdowning() ||
        jam_mvm_has_terminating_midlet_in_mids((kal_char *) g_mmi_java_current_selected_mids_root))
    {
        return;
    }
#ifndef __MMI_APP_MANAGER_SUPPORT__
#ifdef __MMI_MY_FAVORITE_JAVA_HYPERLINK__
    linkcount = mmi_my_favorite_javabox_waplink_count();
    if(index < linkcount ) /* Highlight hyperlink */
    {
        #if (defined(__MMI_JAVA_CATEGORY_SUPPORT__) && defined( __MMI_MY_FAVORITE_GPLUSGAME__))
        if(mmi_java_catagory_cur_list_type() == JAM_CATEGORY_OP01_GPLUS)
        {
            SetLeftSoftkeyFunction(mmi_my_favorite_open_gplusgame_wap_hdlr, KEY_EVENT_UP);
        }
        else
        {
            SetLeftSoftkeyFunction(mmi_my_favorite_open_java_wap_hdlr, KEY_EVENT_UP);
        }
        #else
        SetLeftSoftkeyFunction(mmi_my_favorite_open_java_wap_hdlr, KEY_EVENT_UP);
        #endif
        return;
    }

#endif /*__MMI_MY_FAVORITE_JAVA_HYPERLINK__*/
    vm_id = jam_mvm_get_vm_id((kal_char *) g_mmi_java_current_selected_mids_root,-1);
    if (jam_mvm_is_vm_running(vm_id))
    {
        g_mmi_java_current_selected_vm_id = vm_id;
        mmi_java_entry_opt();
    }
    else if(jam_mvm_is_vm_terminating(vm_id))
    {
        return;
    }
    else
    {
        g_mmi_java_current_selected_vm_id = -1;
        mmi_java_send_mid_getlist_req();
    }
#else
	mmi_java_send_mids_getinfo_req();
#endif
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_java_sg_proc
 * DESCRIPTION
 *  Java svreen group proc function
 * PARAMETERS
 *  events
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_java_sg_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct * g_evt  = (mmi_group_event_struct * )evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch(g_evt->evt_id)
       {
        /* fmgr cui event hdlr */
        case EVT_ID_CUI_FOLDER_SELECTOR_RESULT:
        case EVT_ID_CUI_FILE_SELECTOR_RESULT:
        {
            #if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
            mmi_java_save_as_file_evt_hdlr(evt);
            #endif
            break;
        }
       default:
            break;
       }
       return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_setting_and_security_sg_proc
 * DESCRIPTION
 *  Java setting and security screen group proc function
 * PARAMETERS
 *  events
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_java_setting_and_security_sg_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct * g_evt  = (mmi_group_event_struct * )evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch(evt->evt_id)
       {
       case EVT_ID_CUI_INLINE_ABORT:
            cui_inline_close(g_evt->sender_id);
            break;
       case EVT_ID_CUI_INLINE_SUBMIT:
       case EVT_ID_CUI_INLINE_CSK_PRESS:
        if(g_evt->sender_id == g_java_setting_inline)
        {
            mmi_java_nw_set_inline_sg_id(g_java_setting_inline);
            mmi_java_nw_inline_editor_cui_proc(evt);
        }    
        if(g_evt->sender_id == g_java_security_inline)
        {
            #ifdef OGDR_SECURITY_SETTING
            mmi_java_change_domain_status_done_hdlr();
            #endif
         }
        if(g_evt->sender_id == g_java_domain_inline)
        {
            mmi_java_update_mids_setting();
            cui_inline_close(g_java_domain_inline);
         }
            break;
        /* java nw setting */    
        case EVT_ID_CUI_INLINE_SET_KEY:
        case EVT_ID_CUI_INLINE_NOTIFY:
            if (g_evt->sender_id == g_java_setting_inline)
            {
                mmi_java_nw_set_inline_sg_id(g_java_setting_inline);
                mmi_java_nw_inline_editor_cui_proc(evt);
            }
            break;
        /* java nw dtcnt cui evt */
        case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
        case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
        case CUI_DTCNT_SELECT_EVENT_CLOSE:
        case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
        case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
            mmi_java_nw_dtcnt_cui_proc(evt);
            break;
        case MMI_EVENT_SUCCESS:
        case MMI_EVENT_FAILURE:
        case EVT_ID_POPUP_QUIT:
            cui_inline_close(g_evt->sender_id);
            break;
       default:
            break;
       }
       return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_busy_sg_proc
 * DESCRIPTION
 *  Java busy screen group proc function
 * PARAMETERS
 *  events
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_java_busy_sg_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct * g_evt  = (mmi_group_event_struct * )evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
       return MMI_RET_OK;
}

static mmi_ret  mmi_java_opt_menu_cui_entry_event_proc(mmi_event_struct* evt )
{    

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_java_opt_menu_cui_hilite_event_proc
* DESCRIPTION
*  
* PARAMETERS
*  mmi_event_struct      [IN]        
* RETURNS
*  return MMI_RET_OK
 *****************************************************************************/
static mmi_ret mmi_java_opt_menu_cui_hilite_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;
    switch(menu_evt->highlighted_menu_id)
        {
            case MENU_JAVA_APP_OPTION_NETWORK_SETTINGS: 
                mmi_java_highlight_opt_network_profile();
                return MMI_RET_OK;
          #ifndef   __MMI_APP_MANAGER_SUPPORT__
             case MENU_JAVA_APP_OPTION_SELECT:
                //SetCenterSoftkeyFunction(mmi_java_send_mid_getlist_req,KEY_EVENT_UP);
                mmi_java_highlight_opt_select();
                return MMI_RET_OK;
    
            case MENU_JAVA_APP_OPTION_LAUNCH:
                //SetCenterSoftkeyFunction(mmi_java_entry_mid_launch,KEY_EVENT_UP);
                mmi_java_highlight_opt_launch();
                return MMI_RET_OK;

            case MENU_JAVA_APP_OPTION_DELETE:
                mmi_java_highlight_opt_delete();
                return MMI_RET_OK;

           #endif     
            case MENU_JAVA_APP_OPTION_UPDATE:
                mmi_java_highlight_opt_update();
                 return MMI_RET_OK;
                 
            case MENU_JAVA_APP_OPTION_INFO:
                mmi_java_highlight_opt_info();
                return MMI_RET_OK;
                
            case MENU_JAVA_APP_OPTION_SETTING:
                mmi_java_highlight_opt_setting();
                return MMI_RET_OK;
                
#if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
            case MENU_JAVA_APP_OPTION_PACKAGE:
                mmi_java_highlight_opt_package();
                return MMI_RET_OK;
#endif 
            case MENU_JAVA_APP_OPTION_RESTORE:
                mmi_java_highlight_opt_restore();
                return MMI_RET_OK;              
            default:
                break;
        }
    
    return MMI_RET_OK;
}

static mmi_ret  mmi_java_opt_menu_cui_select_event_proc(mmi_event_struct * evt)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    menu_evt = (cui_menu_event_struct *)evt;
    switch (menu_evt->highlighted_menu_id)
        {
            #ifndef __MMI_APP_MANAGER_SUPPORT__
            case MENU_JAVA_APP_OPTION_SELECT:
            case MENU_JAVA_APP_OPTION_LAUNCH:
                mmi_java_send_mid_getlist_req();
                return MMI_RET_OK;
            case MENU_JAVA_APP_OPTION_DELETE:
                mmi_java_send_mids_delete_req();
                return MMI_RET_OK;
           #endif
            case MENU_JAVA_APP_OPTION_UPDATE:
                mmi_java_entry_mids_update();
                 return MMI_RET_OK;
                 
            case MENU_JAVA_APP_OPTION_INFO:
                mmi_java_send_mids_getinfo_req();
                return MMI_RET_OK;
                
            case MENU_JAVA_APP_OPTION_SETTING:
                mmi_java_save_opt_setting();
                return MMI_RET_OK;
             
#if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
            case MENU_JAVA_APP_OPTION_PACKAGE:
                mmi_java_send_mids_package_req();
                return MMI_RET_OK;
#endif 
    
            case MENU_JAVA_APP_OPTION_NETWORK_SETTINGS:
                mmi_java_nw_pre_entry_network_settings_screen();
                return MMI_RET_OK;
    
            case MENU_JAVA_APP_OPTION_RESTORE:
                mmi_java_entry_restore_default_confirm_screen();
                return MMI_RET_OK;              
            default:
                break;
        }
        return MMI_RET_ERR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_opt_sg_proc
 * DESCRIPTION
 *  Java option screen group proc function
 * PARAMETERS
 *  events
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
    mmi_ret mmi_java_opt_sg_proc(mmi_event_struct *evt)
    {
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/
        mmi_group_event_struct * g_evt  = (mmi_group_event_struct * )evt;
        cui_menu_event_struct *menu_evt;
        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        
        switch(evt->evt_id)
           {
           case MMI_EVENT_FAILURE:
           case MMI_EVENT_SUCCESS:
                mmi_frm_scrn_close(GRP_ID_JAVA_OPT, SCR_JAVA_APP_OPTION_SETTING);
                break;
            /* java nw inline cui evt */
            case EVT_ID_CUI_INLINE_SUBMIT:
            case EVT_ID_CUI_INLINE_CSK_PRESS:
                if(g_evt->sender_id == g_java_opt_setting_inline)
                {
                    mmi_java_update_mids_setting();
                    cui_inline_close(g_evt->sender_id);
                }
                else if (g_evt->sender_id == mmi_java_nw_get_inline_sg_id())
                {
                    mmi_java_nw_cui_proc(evt);
                }
                break;
            case EVT_ID_CUI_INLINE_ABORT:
                cui_inline_close(g_evt->sender_id);
                break;
            //case EVT_ID_CUI_INLINE_CSK_PRESS:
            case EVT_ID_CUI_INLINE_SET_KEY:
            case EVT_ID_CUI_INLINE_NOTIFY:
            /* java nw dtcnt cui evt */
            case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
            case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
            case CUI_DTCNT_SELECT_EVENT_CLOSE:
            case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
            case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
            if(g_evt->sender_id != g_java_opt_setting_inline)
            {
                mmi_java_nw_cui_proc(evt);
            }
                break;
                
           /* --------MENU CUI--------*/
          case EVT_ID_CUI_MENU_LIST_ENTRY:
                mmi_java_opt_menu_cui_entry_event_proc(evt);
                break;
                
            case EVT_ID_CUI_MENU_ITEM_HILITE:
                mmi_java_opt_menu_cui_hilite_event_proc(evt);
                break;

            case EVT_ID_CUI_MENU_ITEM_SELECT:
            case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
                mmi_java_opt_menu_cui_select_event_proc(evt);            
             break;
                
            case EVT_ID_CUI_MENU_CLOSE_REQUEST:
                menu_evt = (cui_menu_event_struct*)evt;
                cui_menu_close(menu_evt->sender_id);
                break;
            /* --------MENU CUI--------*/
           default:
                break;
           }
           return MMI_RET_OK;
    }


/* These functions is defined for other use */
#ifdef __MMI_VUI_SHELL_SHORTCUTS__
mmi_java_sel_mids_hdlr g_mmi_java_select_list_callback;
mmi_java_select_mids_info_struct g_mmi_java_select_mids_info;
void mmi_java_entry_list_screen_ext(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_list_screen
 * DESCRIPTION
 *  Enter the Java menu list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MAX_VM_INSTANCE_NUM == 1)
    if (jam_mvm_is_vm_running(0))
    {
        g_mmi_java_current_selected_vm_id = 0;
#if defined(J2ME_SUPPORT_PAUSE) || defined(J2ME_SUPPORT_BACKGROUND)        
        mmi_java_entry_resume_dialog(GRP_ID_ROOT);
#endif        
        return;
    }
    else if(jam_mvm_is_vm_terminating(0))
    {
        mmi_java_display_is_busy();
        return;
    }
#endif
    if (mmi_java_check_and_display_is_busy())
    {
        return;
    }
    mmi_frm_group_create_ex(
    GRP_ID_ROOT,
    APP_JAVA,
    mmi_java_sg_proc,
    NULL,
    MMI_FRM_NODE_SMART_CLOSE_FLAG);
    g_java.mids_list_filter.filter_type = JAM_NONE_FILTER;
    mmi_java_entry_list_screen_ext();
}

void mmi_java_select_mids_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_java_select_mids_info.mids_icon = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_icon;
    g_mmi_java_select_mids_info.mids_name = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_name;
    g_mmi_java_select_mids_info.storage_name = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].storage_name;
    (*g_mmi_java_select_list_callback)(&g_mmi_java_select_mids_info);
    mmi_frm_scrn_close_active_id();

}
void mmi_java_highlight_select_mids_index(S32 nIndex)
{
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/
        S32 index = 0;
        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_GET_JAVA_APP_MIDS_INDEX);
    
        g_java.mids_index = nIndex;
        g_java.mid_index = 0;
    
        if(mmi_wcslen((const U16 *)g_java.mids_info[g_java.mids_index - g_java.mids_info_start].storage_name) < 127)
        {       
            mmi_wcscpy((U16 *) g_mmi_java_current_selected_mids_root, (const U16 *)g_java.mids_info[g_java.mids_index - g_java.mids_info_start].storage_name);
        }
        else
        {                
            mmi_wcsncpy((U16 *) g_mmi_java_current_selected_mids_root, (const U16 *)g_java.mids_info[g_java.mids_index - g_java.mids_info_start].storage_name, 127);
        }  
    

        index = g_java.mids_index;

    #ifdef __MMI_JAVA_CATEGORY_SUPPORT__
        jam_set_category_op01_hilighlight_index( index, g_java.mids_list_filter.filter_type, g_java.mids_list_filter.category_type );
    #endif
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_java_select_mids_handler,KEY_EVENT_UP);
        SetLeftSoftkeyFunction(mmi_java_select_mids_handler, KEY_EVENT_UP);

        SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_list_screen_ext
 * DESCRIPTION
 *  Enter the Java menu list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_list_screen_ext(void)
{
#ifdef __PLUTO_MMI_PACKAGE__
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/
        U32 count = 0;
        U8 *guiBuffer = NULL;
        U32 linkcount = 0;
        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
            
        g_java.mids_info_end = g_java.mids_info_start = -1;
    
        /* get list at the very beginning */
        needToSendGetListReq = MMI_TRUE;
        
        mmi_java_fetch_mids_list(0, (UI_string_type) NULL, (PU8*) NULL, 0);
        count = g_java.total_java_app_mids;
        
        if (count == 0)
        {
            mmi_popup_property_struct arg;
            mmi_popup_property_init(&arg);
            arg.parent_id = APP_JAVA;
            mmi_popup_display_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, &arg);
    
            mmi_frm_group_close(APP_JAVA);
        }
        else
        {
            if (!mmi_frm_scrn_enter(
                APP_JAVA, 
                SCR_JAVA, 
                NULL, 
                mmi_java_entry_list_screen_ext, 
                MMI_FRM_FULL_SCRN))    
                {
                    return;
                }
    
            guiBuffer = mmi_frm_scrn_get_gui_buf(APP_JAVA, SCR_JAVA);
            RegisterHighlightHandler(mmi_java_highlight_select_mids_index);
    
            if (g_java.total_java_app_mids > JAVA_LIST_CACHE_COUNT)
            {
                ShowCategory185Screen(
                    STR_SCR_JAVA_CAPTION,
                    mmi_java_get_title_icon(),
                    STR_GLOBAL_OPTIONS,
                    IMG_GLOBAL_OPTIONS,
                    STR_GLOBAL_BACK,
                    IMG_GLOBAL_BACK,
                    count,
                    (GetItemFuncPtr) mmi_java_get_list_data,
                    NULL,
                    0,
                    MMI_TRUE,
                    flushListCache,
                    guiBuffer);
            }
            else
            {
                needToSendGetListReq = MMI_FALSE;
                    wgui_cat1032_show(
                    (WCHAR*) GetString(STR_SCR_JAVA_CAPTION),
                    (PU8) GetImage(mmi_java_get_title_icon()),
                    (WCHAR*) GetString(STR_GLOBAL_OPTIONS),
                    (PU8) GetImage(IMG_GLOBAL_OPTIONS),
                    (WCHAR*) GetString(STR_GLOBAL_BACK),
                    (PU8) GetImage(IMG_GLOBAL_BACK),
                    count,
                    (GetAsyncItemFuncPtr)mmi_java_get_list_data_async,
                    NULL,
                    linkcount,
                    0,    
                    IMG_GLOBAL_L1,
                    0,
                    guiBuffer,
                    NULL);
            }
           }
        #if 0
        #ifdef __MMI_FTE_SUPPORT__
/* under construction !*/
        #endif
        #endif
            ChangeLeftSoftkey(STR_GLOBAL_OK,0);
            SetLeftSoftkeyFunction(mmi_java_select_mids_handler, KEY_EVENT_UP);
            SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
            SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_UP);
            SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id,KEY_EVENT_UP);
             mmi_java_load_setting();
     #endif
    }


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_sel_list_screen
 * DESCRIPTION
 *  Interface for other to use
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_sel_list_screen(mmi_java_sel_mids_hdlr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jam_is_busy())
    {
        mmi_java_display_is_busy();
        return;
    }
    g_mmi_java_select_list_callback = callback;
    mmi_java_entry_list_screen();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_java_get_icon_from_storage_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_char* mmi_java_get_icon_from_storage_name(kal_char * storage_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 mids_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(storage_name!= NULL);
    needToSendGetListReq = MMI_TRUE;
    mids_id = jam_call_back_functions.jam_get_mids_id_from_storage_name(storage_name);
    g_java.mids_info_end = g_java.mids_info_start = -1;
    g_java.mids_list_filter.filter_type = JAM_NONE_FILTER;
    g_java.total_java_app_mids = mids_id;
    mmi_java_fetch_mids_list(mids_id - 1, (UI_string_type) NULL, (PU8*) NULL, 0);
    g_java.mids_index = mids_id - 1;
    g_java.mid_index = 0;
    return g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_icon;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_get_name_from_storage_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_wchar* mmi_java_get_name_from_storage_name(kal_char * storage_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 mids_id;
    kal_char * mids_storage_name;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(storage_name!= NULL);
    mids_storage_name = get_ctrl_buffer(app_ucs2_strlen((const kal_int8 *)storage_name)+1);
    app_ucs2_str_to_asc_str((kal_int8 *) mids_storage_name, (kal_int8 *) storage_name);
    needToSendGetListReq = MMI_TRUE;
    mids_id = jam_call_back_functions.jam_get_mids_id_from_storage_name(mids_storage_name);
    if(mids_id < 0)
        return NULL;
    g_java.mids_info_end = g_java.mids_info_start = -1;
    g_java.mids_list_filter.filter_type = JAM_NONE_FILTER;
    g_java.total_java_app_mids = mids_id;
    mmi_java_fetch_mids_list(mids_id - 1, (UI_string_type) NULL, (PU8*) NULL, 0);
    g_java.mids_index = mids_id - 1;
    g_java.mid_index = 0;
    free_ctrl_buffer(mids_storage_name);
    return g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_name;
}
#endif /* __MMI_VUI_SHELL_SHORTCUTS__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_terminate_screen
 * DESCRIPTION
 *  Callback function to handle
 *  Ask user if they want to terminate VM first before launch MIDlet
 * PARAMETERS
 *  teminate    [IN]    user select yes/No
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_terminate_screen(MMI_BOOL terminate)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(terminate)
    {
        jam_enter_terminate_mode(g_mmi_java_current_selected_vm_id);
        g_mmi_java_current_selected_vm_id = -1;
        mmi_java_entry_terminating(MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_launch_midlet
 * DESCRIPTION
 *  Launch a MIDlet.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_launch_midlet(kal_char*  storage_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 mids_id = -1;
    kal_int32 count = 0;
    kal_int32 vm_id = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jam_is_busy())
    {
        mmi_java_display_is_busy();
        return;
    }
    ASSERT(storage_name!= NULL);    
    app_ucs2_str_to_asc_str((kal_int8 *) (&g_mmi_java_current_selected_mids_root[0]), (kal_int8 *) storage_name);
    vm_id = jam_mvm_get_vm_id((kal_char *) g_mmi_java_current_selected_mids_root,-1);
    if (jam_mvm_is_vm_running(vm_id))
    {
        g_mmi_java_current_selected_vm_id = vm_id;
#if (MAX_VM_INSTANCE_NUM > 1)        
#if defined(J2ME_SUPPORT_PAUSE) || defined(J2ME_SUPPORT_BACKGROUND)
        mmi_java_entry_resume_dialog(GRP_ID_ROOT);
#endif        
#else
        mmi_java_entry_cb_terminate_dialog(mmi_java_entry_terminate_screen, (U16*)GetString(STR_JAVA_TERMINATE_JAVA_GAME),0);
#endif /*(MAX_VM_INSTANCE_NUM > 1)*/
        return;
    }
    else
    {      
        if (jam_mvm_is_shutdowning() ||
            jam_mvm_is_vm_terminating(vm_id)||
            jam_mvm_has_terminating_midlet_in_mids((kal_char *) g_mmi_java_current_selected_mids_root))
        {
            return ;
        }
    }
    needToSendGetListReq = MMI_TRUE;
    mids_id = jam_call_back_functions.jam_get_mids_id_from_storage_name((kal_char*)&g_mmi_java_current_selected_mids_root[0]);

    if (mmi_java_is_in_voice_call())
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL, MMI_EVENT_FAILURE, APP_JAVA, NULL);
        mmi_frm_scrn_close(GRP_ID_JAVA_TERMINATE_CB,SCR_JAVA_TERMINATE_DIALOG2);
        return;
    }

    g_java.mids_info_end = g_java.mids_info_start = -1;
    g_java.mids_list_filter.filter_type = JAM_NONE_FILTER;
    g_java.total_java_app_mids = mids_id;
    mmi_java_fetch_mids_list(mids_id - 1, (UI_string_type) NULL, (PU8*) NULL, 0);
    g_java.mids_index = mids_id - 1;
    g_java.mid_index = 0;
    count = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mid_count;
    if (count == 1 )
    {
        g_java.mid_info[0].mid_id =1;
    }
    mmi_java_send_mid_getlist_req();
}


mmi_ret mmi_java_app_java_screen_leave_proc(mmi_event_struct *evt)                                                                                                       
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
        mmi_java_try_to_shutdown_vm();                                                                                                                                                            
#ifdef J2ME_SHARE_MED_EXT_MEM
    if (!jam_mvm_is_vm_running(0)&&!jam_mvm_is_vm_terminating(0))
    {
        jam_mids_getlist_exit_free();
    }
#endif /*J2ME_SHARE_MED_EXT_MEM*/
        break;                                                                                                                                                                            
    }                                                                                                                                                                                     
    return MMI_RET_OK;                                                                                                                                                                    
}

void EntryScrJavaMenu_int(void);
/*****************************************************************************
 * FUNCTION
 *  EntryScrJavaMenu
 * DESCRIPTION
 *  Enter the Java menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrJavaMenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0;
    U8 *guiBuffer = NULL;
    U32 linkcount = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MAX_VM_INSTANCE_NUM == 1)
#if defined(J2ME_SUPPORT_PAUSE) || defined(J2ME_SUPPORT_BACKGROUND)
    if (jam_mvm_is_vm_running(0))
    {
        g_mmi_java_current_selected_vm_id = 0;
#if defined(J2ME_SUPPORT_PAUSE) || defined(J2ME_SUPPORT_BACKGROUND)        
        mmi_java_entry_resume_dialog(GRP_ID_ROOT);
#endif
        return;
    }
    else if(jam_mvm_is_vm_terminating(0))
    {
        mmi_java_display_is_busy();
        return;
    }
#endif
    if (mmi_java_check_and_display_is_busy())
    {
        g_java.mids_info_end = g_java.mids_info_start = -1;
        return;
    }
#else
    if (jam_is_busy())
    {
        mmi_java_display_is_busy();
        return;
    }
#endif /* (MAX_VM_INSTANCE_NUM == 1) */
    mmi_frm_group_create_ex(
    GRP_ID_ROOT,
    APP_JAVA,
    mmi_java_sg_proc,
    NULL,
    MMI_FRM_NODE_SMART_CLOSE_FLAG);
    EntryScrJavaMenu_int();
}


/*****************************************************************************
 * FUNCTION
 *  EntryScrJavaMenu_int
 * DESCRIPTION
 *  Enter the Java menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryScrJavaMenu_int(void)
{  
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0;
    U8 *guiBuffer = NULL;
    U32 linkcount = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(jam_is_busy())
    {
        mmi_frm_scrn_enter(APP_JAVA, SCR_JAVA, NULL, EntryScrJavaMenu_int, MMI_FRM_FULL_SCRN); 
        return;
    }
    g_java.mids_info_end = g_java.mids_info_start = -1;
    needToSendGetListReq = MMI_TRUE;
    mmi_java_fetch_mids_list(0, (UI_string_type) NULL, (PU8*) NULL, 0);

    count = g_java.total_java_app_mids;
#ifdef __MMI_MY_FAVORITE_JAVA_HYPERLINK__
    linkcount = mmi_my_favorite_javabox_waplink_count();
    count += linkcount;
    if (count == 0)
    {
        mmi_popup_property_struct arg;
        mmi_popup_property_init(&arg);
        mmi_popup_display_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, &arg);
        mmi_frm_group_close(APP_JAVA);
    }
    else if(mmi_java_resume_pending_flag)
    {
        mmi_java_display_is_busy();
    }
    else
    {
        guiBuffer = mmi_frm_scrn_get_gui_buf(APP_JAVA, SCR_JAVA);
        /* -------Update for Screen group ------------ */
        if (mmi_frm_scrn_enter(
            APP_JAVA, 
            SCR_JAVA, 
            NULL, 
            EntryScrJavaMenu_int, 
            MMI_FRM_FULL_SCRN))    
            {
        
        mmi_frm_scrn_set_leave_proc(APP_JAVA, SCR_JAVA, mmi_java_app_java_screen_leave_proc);
        RegisterHighlightHandler(mmi_my_favorite_javabox_highlight_hdlr);
        if (g_java.total_java_app_mids > JAVA_LIST_CACHE_COUNT)
        {
            #ifdef __MMI_MY_FAVORITE_JAVABOX__        
            ShowCategory185Screen(
                mmi_my_favorite_get_java_title_string(),
                mmi_java_get_title_icon(),
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                count,
                (GetItemFuncPtr) mmi_my_favorite_javabox_get_item_callback,
                NULL,
                linkcount,
                MMI_TRUE,
                flushListCache,
                guiBuffer);
            #else
            ShowCategory185Screen(
                STR_SCR_JAVA_CAPTION,
                mmi_java_get_title_icon(),
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                count,
                (GetItemFuncPtr) mmi_my_favorite_javabox_get_item_callback,
                NULL,
                linkcount,
                MMI_TRUE,
                flushListCache,
                guiBuffer);        
            #endif
        }
        else
        {
            needToSendGetListReq = MMI_FALSE;
            #ifdef __MMI_MY_FAVORITE_JAVABOX__            
            wgui_cat1032_show(
                (WCHAR*) GetString(mmi_my_favorite_get_java_title_string()),
                (PU8) GetImage(mmi_java_get_title_icon()),
                (WCHAR*) GetString(STR_GLOBAL_OPTIONS),
                (PU8) GetImage(IMG_GLOBAL_OPTIONS),
                (WCHAR*) GetString(STR_GLOBAL_BACK),
                (PU8) GetImage(IMG_GLOBAL_BACK),
                count,
                (GetAsyncItemFuncPtr)mmi_my_favorite_javabox_get_item_callback_async,
                NULL,
                linkcount,
                0,    
                IMG_GLOBAL_L1,
                0,
                guiBuffer,
                NULL);
            #else
            wgui_cat1032_show(
                (WCHAR*) GetString(STR_SCR_JAVA_CAPTION),
                (PU8) GetImage(mmi_java_get_title_icon()),
                (WCHAR*) GetString(STR_GLOBAL_OPTIONS),
                (PU8) GetImage(IMG_GLOBAL_OPTIONS),
                (WCHAR*) GetString(STR_GLOBAL_BACK),
                (PU8) GetImage(IMG_GLOBAL_BACK),
                count,
                (GetAsyncItemFuncPtr)mmi_my_favorite_javabox_get_item_callback_async,
                NULL,
                linkcount,
                0,    
                IMG_GLOBAL_L1,
                0,
                guiBuffer,
                NULL);          
            #endif
        }
        #ifdef __MMI_FTE_SUPPORT__
        wgui_register_tap_callback(mmi_java_mids_tap_callback_funtion);
        #endif
        SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(mmi_my_favorite_back_to_main, KEY_EVENT_UP);
    }
        }
#else /*__MMI_MY_FAVORITE_JAVA_HYPERLINK__*/
    linkcount = 0;
    count += linkcount;
    if (count == 0)
    {
        mmi_popup_property_struct arg;
        mmi_popup_property_init(&arg);
        mmi_popup_display_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, &arg);
        mmi_frm_group_close(APP_JAVA);
    }
    else if(mmi_java_resume_pending_flag)
    {
        mmi_java_display_is_busy();
    }
    else
    {
        guiBuffer = mmi_frm_scrn_get_gui_buf(APP_JAVA, SCR_JAVA);      
        /* -------Update for Screen group ------------ */
        if (mmi_frm_scrn_enter(
            APP_JAVA, 
            SCR_JAVA, 
            NULL, 
            EntryScrJavaMenu_int, 
            MMI_FRM_FULL_SCRN))    
            {
        /* ---------------------------------------- */
        RegisterHighlightHandler(mmi_java_highlight_get_mids_index);
        mmi_frm_scrn_set_leave_proc(APP_JAVA, SCR_JAVA, mmi_java_app_java_screen_leave_proc);

        if (g_java.total_java_app_mids > JAVA_LIST_CACHE_COUNT)
        {
            ShowCategory185Screen(
                STR_SCR_JAVA_CAPTION,
                mmi_java_get_title_icon(),
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                count,
                (GetItemFuncPtr) mmi_java_get_list_data,
                NULL,
                linkcount,
                MMI_TRUE,
                flushListCache,
                guiBuffer);
        }
        else
        {
            needToSendGetListReq = MMI_FALSE;
            wgui_cat1032_show(
                (WCHAR*) GetString(STR_SCR_JAVA_CAPTION),
                (PU8) GetImage(mmi_java_get_title_icon()),
                (WCHAR*) GetString(STR_GLOBAL_OPTIONS),
                (PU8) GetImage(IMG_GLOBAL_OPTIONS),
                (WCHAR*) GetString(STR_GLOBAL_BACK),
                (PU8) GetImage(IMG_GLOBAL_BACK),
                count,
                (GetAsyncItemFuncPtr)mmi_java_get_list_data_async,
                NULL,
                linkcount,
                0,    
                IMG_GLOBAL_L1,
                0,
                guiBuffer,
                NULL);
        }
       }
        #ifdef __MMI_FTE_SUPPORT__
        wgui_register_tap_callback(mmi_java_mids_tap_callback_funtion);
        #endif
        SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
        SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id,KEY_EVENT_UP);
    }
#endif/*ndef __MMI_MY_FAVORITE_JAVA_HYPERLINK__*/
    mmi_java_store_setting();
    mmi_java_load_setting();
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_get_mids_index
 * DESCRIPTION
 *  Set the handler of the highlight item
 * PARAMETERS
 *  nIndex      [IN]        The index of highlight item
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_get_mids_index(S32 nIndex) */
void mmi_java_highlight_get_mids_index(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_GET_JAVA_APP_MIDS_INDEX);

    g_java.mids_index = nIndex;
    g_java.mid_index = 0;

    if(mmi_wcslen((const U16 *)g_java.mids_info[g_java.mids_index - g_java.mids_info_start].storage_name) < 127)
    {       
        app_ucs2_str_to_asc_str((kal_int8 *) g_mmi_java_current_selected_mids_root, (kal_int8 *)g_java.mids_info[g_java.mids_index - g_java.mids_info_start].storage_name);
    }
    else
    {                
        app_ucs2_str_n_to_asc_str((kal_int8 *) g_mmi_java_current_selected_mids_root, (kal_int8 *)g_java.mids_info[g_java.mids_index - g_java.mids_info_start].storage_name, 127);
    }  

    #ifdef __MMI_MY_FAVORITE_JAVA_HYPERLINK__
    index = g_java.mids_index + mmi_my_favorite_javabox_waplink_count();
    #else
    index = g_java.mids_index;
    #endif
    #ifdef __MMI_JAVA_CATEGORY_SUPPORT__
    jam_set_category_op01_hilighlight_index( index, g_java.mids_list_filter.filter_type, g_java.mids_list_filter.category_type );
    #endif
    if (jam_mvm_is_shutdowning() ||
        jam_mvm_has_terminating_midlet_in_mids((kal_char *) g_mmi_java_current_selected_mids_root))
    {
        ChangeLeftSoftkey(0, 0);
        clear_softkey_handler(KEY_LSK);
        ChangeCenterSoftkey(0, 0);
        clear_softkey_handler(KEY_CSK);
    }
    else
    {
        kal_int32 vm_id = -1;
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        vm_id = jam_mvm_get_vm_id((kal_char *) g_mmi_java_current_selected_mids_root,-1);
        if (jam_mvm_is_vm_running(vm_id))
        {
            g_mmi_java_current_selected_vm_id = vm_id;
/* 20110223,SUPPORT_JAVA_SHARE_MED */
#if defined(J2ME_SUPPORT_PAUSE) || defined(J2ME_SUPPORT_BACKGROUND)
            SetCenterSoftkeyFunction(mmi_java_resume_dialog_execute_resume,KEY_EVENT_UP);
#endif
        }
        else
        {
            g_mmi_java_current_selected_vm_id = -1;
            SetCenterSoftkeyFunction(mmi_java_send_mid_getlist_req,KEY_EVENT_UP);
        }
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS,0);
        SetLeftSoftkeyFunction(mmi_java_entry_opt, KEY_EVENT_UP);
    }
#ifdef __MMI_MY_FAVORITE_JAVA_HYPERLINK__
    clear_softkey_handler(KEY_RIGHT_ARROW);
#else
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif
}


/*****************************************************************************
 * FUNCTION
  *  mmi_java_entry_opt_ext
 * DESCRIPTION
 *  Main Menu->FunAndGames->Java->Applications->Options Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void   mmi_java_entry_opt_ext(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 attrib;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_java_opt_menu_cui = cui_menu_create(
            GRP_ID_JAVA_OPT, 
            CUI_MENU_SRC_TYPE_RESOURCE,
            CUI_MENU_TYPE_OPTION,
            MENU_JAVA_APP_MIDS_OPTION,
            MMI_TRUE,
            NULL);
    attrib = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_attributes;
    #ifndef __MMI_APP_MANAGER_SUPPORT__
    if (g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mid_count == 1)
    {
            cui_menu_set_item_hidden(g_mmi_java_opt_menu_cui, MENU_JAVA_APP_OPTION_SELECT, MMI_TRUE);
            cui_menu_set_item_hidden(g_mmi_java_opt_menu_cui, MENU_JAVA_APP_OPTION_LAUNCH, MMI_FALSE);
    }
    else
    {
            cui_menu_set_item_hidden(g_mmi_java_opt_menu_cui, MENU_JAVA_APP_OPTION_LAUNCH, MMI_TRUE);
            cui_menu_set_item_hidden(g_mmi_java_opt_menu_cui, MENU_JAVA_APP_OPTION_SELECT, MMI_FALSE);
    }
    #endif
    if (attrib & IS_DEFAULT_GAME)
    {
            cui_menu_set_item_hidden(g_mmi_java_opt_menu_cui, MENU_JAVA_APP_OPTION_UPDATE, MMI_TRUE);
			#ifndef __MMI_APP_MANAGER_SUPPORT__
            cui_menu_set_item_hidden(g_mmi_java_opt_menu_cui, MENU_JAVA_APP_OPTION_DELETE, MMI_TRUE);
			#endif
    }
    else
    {
            cui_menu_set_item_hidden(g_mmi_java_opt_menu_cui, MENU_JAVA_APP_OPTION_UPDATE, MMI_FALSE);
			#ifndef __MMI_APP_MANAGER_SUPPORT__
            cui_menu_set_item_hidden(g_mmi_java_opt_menu_cui, MENU_JAVA_APP_OPTION_DELETE, MMI_FALSE);
			#endif
    }

    if (!(attrib & CAN_BE_UPDATE) || 
        !srv_mode_switch_is_network_service_available()||
        mmi_java_is_no_network_service())
    {
           cui_menu_set_item_hidden(g_mmi_java_opt_menu_cui, MENU_JAVA_APP_OPTION_UPDATE, MMI_TRUE);
    }
    else
    {
            cui_menu_set_item_hidden(g_mmi_java_opt_menu_cui, MENU_JAVA_APP_OPTION_UPDATE, MMI_FALSE);
    }
	#ifndef __MMI_APP_MANAGER_SUPPORT__
    if (!(attrib & CAN_BE_REMOVE))
    {
            cui_menu_set_item_hidden(g_mmi_java_opt_menu_cui, MENU_JAVA_APP_OPTION_DELETE, MMI_TRUE);
    }
    else
    {
            cui_menu_set_item_hidden(g_mmi_java_opt_menu_cui, MENU_JAVA_APP_OPTION_DELETE, MMI_FALSE);
    }
	#endif
    if (!(attrib & CAN_BE_SEND))
    {
            cui_menu_set_item_hidden(g_mmi_java_opt_menu_cui, MENU_JAVA_APP_OPTION_PACKAGE, MMI_TRUE);
    }
    else
    {
            cui_menu_set_item_hidden(g_mmi_java_opt_menu_cui, MENU_JAVA_APP_OPTION_PACKAGE, MMI_FALSE);
    }
    
    if (mmi_java_nw_is_need_hide()  || (attrib & IS_DEFAULT_GAME))
    {
            cui_menu_set_item_hidden(g_mmi_java_opt_menu_cui, MENU_JAVA_APP_OPTION_NETWORK_SETTINGS, MMI_TRUE);
    }
    else
    {
            cui_menu_set_item_hidden(g_mmi_java_opt_menu_cui, MENU_JAVA_APP_OPTION_NETWORK_SETTINGS, MMI_FALSE);
    }

#ifdef OGDR_SECURITY_SETTING
        cui_menu_set_item_hidden(g_mmi_java_opt_menu_cui, MENU_JAVA_APP_OPTION_RESTORE, MMI_FALSE);
#else
        cui_menu_set_item_hidden(g_mmi_java_opt_menu_cui, MENU_JAVA_APP_OPTION_RESTORE, MMI_TRUE);
#endif
    cui_menu_set_default_title_image_by_id(g_mmi_java_opt_menu_cui,mmi_java_get_title_icon());
    cui_menu_run(g_mmi_java_opt_menu_cui);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_opt
 * DESCRIPTION
 *  Main Menu->FunAndGames->Java->Applications->Options Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 vm_id = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MAX_VM_INSTANCE_NUM > 1)
#if defined(J2ME_SUPPORT_PAUSE) || defined(J2ME_SUPPORT_BACKGROUND)
    vm_id = jam_mvm_get_vm_id((kal_char *) g_mmi_java_current_selected_mids_root,-1);
    if (jam_mvm_is_vm_running(vm_id))
    {
        g_mmi_java_current_selected_vm_id = vm_id;
        mmi_java_entry_resume_dialog(GRP_ID_ROOT);
        return;
    }
#endif /*defined(J2ME_SUPPORT_PAUSE) || defined(J2ME_SUPPORT_BACKGROUND)*/
#endif /*(MAX_VM_INSTANCE_NUM > 1)*/
    mmi_frm_group_create_ex(
    APP_JAVA,
    GRP_ID_JAVA_OPT,
    mmi_java_opt_sg_proc,
    NULL,
    MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_java_entry_opt_ext();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_opt_select
 * DESCRIPTION
 *  Highlight handler routine for Select menu item in Application->Option menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_highlight_opt_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_java_send_mid_getlist_req, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_java_send_mid_getlist_req,KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_opt_launch
 * DESCRIPTION
 *  Highlight handler routine for Launch menu item in Application->Option menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_highlight_opt_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_java_send_mid_getlist_req, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_java_send_mid_getlist_req,KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_opt_update
 * DESCRIPTION
 *  Highlight handler routine for Update menu item in Application->Option menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_highlight_opt_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_java_entry_mids_update, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_java_entry_mids_update,KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_opt_setting
 * DESCRIPTION
 *  Highlight handler routine for Setting menu item in Application->Option menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_highlight_opt_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_java_save_opt_setting, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_java_save_opt_setting,KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_opt_info
 * DESCRIPTION
 *  Highlight handler routine for Information menu item in Application->Option menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_highlight_opt_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_java_send_mids_getinfo_req, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_java_send_mids_getinfo_req,KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_opt_delete
 * DESCRIPTION
 *  Highlight handler routine for Delete menu item in Application->Option menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_highlight_opt_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_java_send_mids_delete_req, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_java_send_mids_delete_req, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_opt_package
 * DESCRIPTION
 *  Highlight handler routine for package midlet message in Application->Option menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_highlight_opt_package(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_java_entry_send_screen_from_java, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_java_entry_send_screen_from_java,KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_opt_network_profile
 * DESCRIPTION
 *  Highlight handler routine for Network profile menu item in Application->Option menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_highlight_opt_network_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_HIGHLIGHT_OPT_NP);
    mmi_java_nw_local_settings_hilit_hdlr();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_opt_restore
 * DESCRIPTION
 *  Highlight handler routine for Restore menu item in Application->Option menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_highlight_opt_restore(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_HIGHLIGHT_OPT_RESTORE);
    
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_java_entry_restore_default_confirm_screen, KEY_EVENT_UP);
    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_java_entry_restore_default_confirm_screen, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_restore_default_confirm_screen
 * DESCRIPTION
 *  entry the restore confirm dialog and wait user's response.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_restore_default_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RESTORE_CONFIRM);    
    do {
        mmi_confirm_property_struct arg;
        mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);
        arg.softkey[0].str = (WCHAR *)((UI_string_type)get_string(STR_GLOBAL_YES));
        arg.softkey[2].str = (WCHAR *)((UI_string_type)get_string(STR_GLOBAL_NO));
        arg.callback = (mmi_proc_func)NULL;
        arg.parent_id = GRP_ID_JAVA_OPT;
        mmi_confirm_display_ext(STR_ID_FNG_SECURITY_JAVA_RESTORE_DEFAULT_CONFIRM, MMI_EVENT_QUERY, &arg);
        // TODO: please remove softkey register and move softkey hdlr below, then fill this callback to arg.callback above
    } while(0);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_java_send_mids_restore_req, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_java_send_mids_restore_req,KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mids_restore_cnf
 * DESCRIPTION
 *  This is the message "MSG_ID_MMI_JAVA_RESET_DOMAIN_SETTING_CNF" handler.
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_mids_restore_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_reset_domain_setting_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    msg = (mmi_java_mids_reset_domain_setting_cnf_struct*)MsgStruct;
    
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_RESTORE_CNF, msg->success);    

    if (!msg->success)
    {
        mmi_java_display_is_busy();
        return;
    }
    else
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_JAVA_OPT, NULL);
    }    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mids_restore_req

 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_RESET_DOMAIN_SETTING_REQ to MOD_J2ME to restore setting of
 *  MIDs and set protocol event handler of MSG_ID_MMI_JAVA_RESET_DOMAIN_SETTING_CNF
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mids_restore_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_reset_domain_setting_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_RESTORE_REQ, g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id);     

    ClearInputEventHandler(MMI_DEVICE_ALL);

    msg = (mmi_java_mids_reset_domain_setting_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mids_reset_domain_setting_req_struct));
    msg->mids_id = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id;

    SetProtocolEventHandler((PsFuncPtr) mmi_java_recv_mids_restore_cnf, MSG_ID_MMI_JAVA_RESET_DOMAIN_SETTING_CNF);

    mmi_java_send_message_from_active_mod( MOD_JAM, MMI_J2ME_SAP,
        MSG_ID_MMI_JAVA_RESET_DOMAIN_SETTING_REQ, msg);

}
#ifdef __JAVA_MANAGER__
/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_cmd_query_req
 * DESCRIPTION
 * Get some information of a mids by index or name, such as the mids index for the name and attribute.
 * However you only set mids_name or mids_idx, and can not be set at the same time.
 *  Send message to java task, and get the MIDlet list back
 * PARAMETERS
 *  mids_name         [IN]        The mids name want to get
 *  mids_index         [IN]        The mids index want to get
 *  extend_mode      [IN]        Send message and sync with java side, get some mids information  from pointer of pointer
 *  ptr             [OUT]       Pointer to the pointer of the list
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_cmd_query_req(const kal_wchar*  mids_name, const kal_int32  mids_idx, kal_bool extend_mode, java_mmi_cmd_query_rsp_struct **ptrRsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_cmd_query_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg = OslAllocDataPtr(mmi_java_cmd_query_req_struct);
    msg->mids_index = mids_idx;
    msg->mids_name = (kal_wchar*)mids_name;
    msg->extend_mode = extend_mode;
    msg->confirm_data_ptr = ptrRsp;

    mmi_frm_send_ilm(MOD_JAM,MSG_ID_MMI_JAVA_CMD_QUERY_REQ,(oslParaType *)msg,NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_cmd_query_cnf
 * DESCRIPTION
 *  This is the message "MSG_ID_MMI_JAVA_CMD_QUERY_CNF" handler.
 *  The structure of the message contains the list of MIDlet in MIDlet suite
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_cmd_query_rsp(ilm_struct * ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    java_mmi_cmd_query_rsp_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (java_mmi_cmd_query_rsp_struct*)ilm_ptr;

}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mid_getlist_req
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_MID_GETLIST_REQ to MOD_J2ME to get list of
 *  MID and set protocol event handler of MSG_ID_MMI_JAVA_MID_GETLIST_CNF
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mid_getlist_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mid_getlist_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_java_need_block_msg())
    {
        mmi_java_display_push_busy();
        return;
    }
    ClearInputEventHandler(MMI_DEVICE_ALL);
    /* sometime will quickly re-entry this function before
       java handle this message  */
    if ((g_java.msg_ctrl & SEND_MID_GET_LIST_CTRL)||(g_java.msg_ctrl & SEND_MIDS_GET_LIST_CTRL))
    {
        return;
    }
    else
    {
        g_java.msg_ctrl |= SEND_MID_GET_LIST_CTRL;
    }
#ifdef __COSMOS_MMI_PACKAGE__	
        mmi_frm_cb_reg_event(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, vapp_java_gpio_event_hdlr, NULL);  
#endif  
    mmi_frm_set_key_handler(NULL,KEY_END,KEY_EVENT_DOWN);
    mmi_frm_set_key_handler(NULL,KEY_END,KEY_EVENT_UP);
    
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_MID_GETLIST_REQ);

    msg = (mmi_java_mid_getlist_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mid_getlist_req_struct));
    msg->extend_mode = KAL_FALSE;
    msg->mids_id = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id;

    mmi_java_send_message_from_active_mod( MOD_JAM, MMI_J2ME_SAP,
        MSG_ID_MMI_JAVA_MID_GETLIST_REQ, msg);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mid_getlist_cnf
 * DESCRIPTION
 *  This is the message "MMI_JAVA_RECV_MID_GETLIST_CNF" handler.
 *  The structure of the message contains the list of MIDlet in MIDlet suite
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_mid_getlist_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mid_getlist_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_MID_GETLIST_CNF);

    g_java.msg_ctrl &= (~SEND_MID_GET_LIST_CTRL);

    
    if (mmi_java_need_block_msg())
    {
        mmi_java_display_push_busy();
        return;
    }

    msg = (mmi_java_mid_getlist_cnf_struct*) MsgStruct;
    if (msg->error_code == J2ME_NO_ERROR)
    {
        U32 i;

        g_java.total_java_app_mid = msg->mid_count;

        for (i = 0; i < g_java.total_java_app_mid; i++)
        {
            g_java.mid_info[i].mid_id = msg->pmid_list[i].mid_id;
            g_java.mid_info[i].mid_icon = (U8*) msg->pmid_list[i].mid_icon;
            g_java.mid_info[i].mid_name = (U8*) msg->pmid_list[i].mid_name;
        }

        if (g_java.total_java_app_mid == 0)
        {
            mmi_popup_property_struct arg;
            mmi_popup_property_init(&arg);
            mmi_popup_display_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, &arg);
            mmi_frm_group_close(GRP_ID_JAVA_OPT);
        }
        else if (g_java.total_java_app_mid == 1)
        {
            if(MMI_FALSE
                #ifdef __DM_LAWMO_SUPPORT__
                ||mmi_dmui_is_phone_lock()
                #ifdef __DM_MO_SUPPORT__
                || mmi_dmui_get_status(MMI_DMUI_MO_TYPE_LAWMO_LOCK ) == MMI_DMUI_STATUS_LAWMO_LOCK_ON_LOCKING
                #endif
                #endif
            )
            {
                mmi_popup_display_ext(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE, NULL);
            }
            else
            {
                mmi_java_entry_mid_launch();
            }
        }
        else
        {
            mmi_java_entry_opt_select();
        }
    }
    else
    {
        mmi_popup_property_struct arg;
        g_java.total_java_app_mid = 0;
        mmi_popup_property_init(&arg);
        mmi_popup_display_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, &arg);
        mmi_frm_group_close(GRP_ID_JAVA_OPT);
    }

}

kal_int32 mmi_java_get_mid_list_in_mids(S32 mids_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = 0;
    U32 event_group;
    mmi_java_mid_getlist_req_struct *msg = NULL;
    mmi_java_mid_getlist_cnf_struct *msg_cnf_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_java_need_block_msg())
    {
        mmi_java_display_push_busy();
        return KAL_FALSE;
    }

    if (mmi_java_check_and_display_is_busy())
    {
        return  KAL_FALSE;
    }

    /* sometime will quickly re-entry this function before
       java handle this message  */
    if (g_java.msg_ctrl & SEND_MID_GET_LIST_CTRL)
    {
        return KAL_FALSE;
    }
    else
    {
        g_java.msg_ctrl |= SEND_MID_GET_LIST_CTRL;
    }
    ClearInputEventHandler(MMI_DEVICE_ALL);
    
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_MID_GETLIST_REQ);

    msg = (mmi_java_mid_getlist_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mid_getlist_req_struct));
    msg->extend_mode = KAL_TRUE;
    msg->confirm_data_ptr = &msg_cnf_ptr;
    msg->mids_id = mids_idx;
    mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP,
        MSG_ID_MMI_JAVA_MID_GETLIST_REQ, msg);
    kal_retrieve_eg_events(g_java_event_group_2, JAVA_EG_GETLIST_2, KAL_OR_CONSUME, (kal_uint32*)&event_group, KAL_SUSPEND);
    g_java.msg_ctrl &= (~SEND_MID_GET_LIST_CTRL);
    g_java.total_java_app_mid = msg_cnf_ptr->mid_count;
    
    for (i = 0; i < g_java.total_java_app_mid; i++)
    {
        g_java.mid_info[i].mid_id = msg_cnf_ptr->pmid_list[i].mid_id;
        g_java.mid_info[i].mid_icon = (U8*) msg_cnf_ptr->pmid_list[i].mid_icon;
        g_java.mid_info[i].mid_name = (U8*) msg_cnf_ptr->pmid_list[i].mid_name;
    }
    if(msg_cnf_ptr)
    {
        free_local_para((local_para_struct*) msg_cnf_ptr);
    }
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_mid_launch
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_java_entry_mid_launch(void)
{
#if (MAX_VM_INSTANCE_NUM > 1)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[MAX_SUB_MENUS];
    kal_int32 vm_id = -1;
    kal_int32 len = 0;
    kal_char * storage_name = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#if defined(J2ME_SUPPORT_PAUSE) || defined(J2ME_SUPPORT_BACKGROUND)
    vm_id = jam_mvm_get_vm_id((kal_char *) g_mmi_java_current_selected_mids_root,(kal_int32)g_java.mid_info[g_java.mid_index].mid_id);
    if (jam_mvm_is_vm_running(vm_id))
    {
        g_mmi_java_current_selected_vm_id = vm_id;
        mmi_java_entry_resume_dialog(GRP_ID_ROOT);
        return;
    }
#endif/*defined(J2ME_SUPPORT_PAUSE) || defined(J2ME_SUPPORT_BACKGROUND)*/
#endif /*(MAX_VM_INSTANCE_NUM > 1)*/
    if(MMI_FALSE
    #ifdef __DM_LAWMO_SUPPORT__
        ||mmi_dmui_is_phone_lock()
    #ifdef __DM_MO_SUPPORT__
        || mmi_dmui_get_status(MMI_DMUI_MO_TYPE_LAWMO_LOCK ) == MMI_DMUI_STATUS_LAWMO_LOCK_ON_LOCKING
    #endif
    #endif
    )
    {
        mmi_popup_display_ext(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE, NULL);
    }
    else
    {
        mmi_java_send_mid_start_req();
    }
}

kal_bool install_launch_success = KAL_TRUE; 
/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_mid_launch_from_idle
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_java_entry_mid_launch_from_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_java.is_push)
    {
        g_java.is_push = MMI_FALSE;
        mmi_java_timealarm_push_callback(g_java.push_session_id,g_java.push_permission,g_java.push_execute);
    }
}

void mmi_java_dummy_entry(void)
{
}
extern long* g_jam_mvm_whole_heap_space;
mmi_ret mmi_java_dummy_entry_leave_proc(mmi_event_struct* evt)
{    
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_GOBACK:
            if(g_jam_mvm_whole_heap_space == NULL)
            {
                kal_trace(JAM_JAVAAGENCY_GROUP,MMI_JAVA_DUMMY_ENTRY_LEAVE_PROC, MMI_RET_ERR);
                return MMI_RET_ERR;
            }
        default:
            break;
    }
    kal_trace(JAM_JAVAAGENCY_GROUP,MMI_JAVA_DUMMY_ENTRY_LEAVE_PROC, MMI_RET_OK);    
    return MMI_RET_OK;   
}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mid_start_req
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_MID_START_REQ to MOD_J2ME to launch
 *  MIDlet and set protocol event handler of MSG_ID_MMI_JAVA_MID_START_CNF
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mid_start_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char* storagename = NULL;
    kal_wchar* mid_name = NULL;
    kal_int32 len = 0;
    mmi_java_mid_start_req_struct *msg;
#ifdef __COSMOS_MMI_PACKAGE__
    mmi_frm_asm_property_struct p;
#endif      
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* sometime will quickly re-entry this function before
       java handle this message  */
    if (g_java.msg_ctrl & SEND_MID_START_CTRL)
    {
         g_java_list_lock = KAL_FALSE;
        return;
    }
    else
    {
        g_java.msg_ctrl |= SEND_MID_START_CTRL;
    }
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_MID_START_REQ);
#ifdef __COSMOS_MMI_PACKAGE__	
    mmi_frm_cb_reg_event(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, vapp_java_gpio_event_hdlr, NULL);  
#endif     
    g_mmi_java_is_no_network_usable = mmi_java_is_no_network_service();
    msg = (mmi_java_mid_start_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mid_start_req_struct));
    msg->mids_id = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id;
    msg->mid_id = g_java.mid_info[g_java.mid_index].mid_id;
    len = strlen((const kal_char *) g_mmi_java_current_selected_mids_root);
    storagename = (kal_char*)get_ctrl_buffer(len+1);
    strcpy((kal_char *) storagename,(const kal_char *) (&g_mmi_java_current_selected_mids_root[0]));
    msg->storage_name = storagename;
    len = app_ucs2_strlen((const kal_int8 *) g_java.mid_info[g_java.mid_index].mid_name);
    mid_name = (kal_wchar*)get_ctrl_buffer((len+1)<<1);
    app_ucs2_strcpy((kal_int8 *)mid_name,(const kal_int8 *) g_java.mid_info[g_java.mid_index].mid_name);
    msg->mid_name = mid_name;
    msg->is_launch_as_bg_running = KAL_FALSE;
#ifdef __COSMOS_MMI_PACKAGE__
    if(!mmi_frm_group_is_present(APP_JAVA))
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,MMI_JAVA_ENTRY_DUMMY_SCREEN);
        mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            APP_JAVA,
            NULL,
            NULL,
            MMI_FRM_NODE_NONE_FLAG);

        mmi_frm_scrn_enter(APP_JAVA, SCR_JAVA_DUMMY,NULL, mmi_java_dummy_entry, MMI_FRM_FULL_SCRN);
        mmi_frm_scrn_set_leave_proc(APP_JAVA, SCR_JAVA_DUMMY, mmi_java_dummy_entry_leave_proc);
        ShowCategoryDummyScreen();
        mmi_frm_screen_rotate(mmi_frm_get_real_prev_screen_rotate());
        mmi_frm_asm_property_init(&p);
        p.f_prepare_w_reserve = 1;
        p.f_hide_in_oom = 1;
        mmi_frm_asm_set_property(APP_JAVA, &p);
    }
    vapp_java_close_venus_screen();
#endif
#ifdef J2ME_SLIM_SCREEN_MEMORY_SUPPORT

    if(mmi_frm_scrn_enter(
        GRP_ID_ROOT,
        SCR_JAVA_DUMMY,
        NULL,
        mmi_java_dummy_entry,
        MMI_FRM_FULL_SCRN))
        {
    #ifdef __PLUTO_MMI_PACKAGE__
        mmi_frm_set_key_handler(NULL,KEY_END,KEY_EVENT_DOWN);
        mmi_frm_set_key_handler(NULL,KEY_END,KEY_EVENT_UP);
    #endif            
        }
#endif /* J2ME_SLIM_SCREEN_MEMORY_SUPPORT */
    mmi_java_send_message_from_active_mod( MOD_JAM, MMI_J2ME_SAP,
        MSG_ID_MMI_JAVA_MID_START_REQ, msg);
    g_java_list_lock = KAL_FALSE;
    #ifdef __PLUTO_MMI_PACKAGE__
   // gui_lock_double_buffer();
    #endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_resend_mid_start_callback
 * DESCRIPTION
 *  This Funtion is used for resend mid start when free enough ASM memory.
 *  Currently only support GAMETYPE_JAVA_GAME
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_resend_mid_start_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_java_is_no_network_usable = KAL_TRUE;
    /* MAUI_02146731*/
    g_jam_allowed_sending_abort_from_idle = KAL_FALSE;
    if ( 0 == g_jam_start_up_mode )
    {
        g_resend_push = KAL_TRUE;
        mmi_java_resend_timealarm_push_res();
        g_resend_push = KAL_FALSE;
    }
    if( 1 == g_jam_start_up_mode )
    {
        mmi_java_get_mid_list_in_mids(g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id);
        g_mmi_java_is_no_network_usable = mmi_java_is_no_network_service();
        mmi_java_send_mid_start_req();
        #ifndef J2ME_SLIM_SCREEN_MEMORY_SUPPORT
        mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            GRP_ID_JAVA_APP,
            jam_sg_proc,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
        mmi_frm_display_dummy_screen_ex(GRP_ID_JAVA_APP, SCR_JAVA_DUMMY);
        #endif
}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_asm_cancel_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MsgStruct       [?]
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_java_asm_cancel_callback(mmi_frm_appmem_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!g_is_asm_allow_to_launch)
    {
        g_is_asm_allow_to_launch = KAL_TRUE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mid_start_cnf
 * DESCRIPTION
 *  This routines handles MMI_JAVA_MID_START_CNF from MOD_J2ME
 * PARAMETERS
 *  MsgStruct       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_mid_start_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_popup = MMI_FALSE;
    U16 error_str_id = 0;
    mmi_java_mid_start_cnf_struct *msg = NULL;   
    #ifdef __COSMOS_MMI_PACKAGE__
    S32 type = VJAVA_POPUP_FAILURE;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_MID_START_CNF);

    g_java.msg_ctrl &= (~SEND_MID_START_CTRL);
    #ifdef __PLUTO_MMI_PACKAGE__
    //gui_unlock_double_buffer();
    #endif
    msg = (mmi_java_mid_start_cnf_struct*) MsgStruct;
    if (msg->error_code == J2ME_NO_ERROR)
    {
        if(msg->is_launch_as_bg_running == KAL_FALSE)
        {
#ifdef __MTK_TARGET__
             mmi_java_send_l4_get_lai_req();
#endif /*__MTK_TARGET__*/
             jam_enter_screen(msg->vm_id);
             #ifdef __COSMOS_MMI_PACKAGE__
             vapp_java_close_venus_screen();
             #endif
        }
        memset(g_mmi_java_current_launching_app_name,0, MMI_APP_NAME_MAX_LEN);
    }
    else
    {
        if (msg->error_code == J2ME_INSUFFICIENT_MEMORY)
        {
      //added for 128+32
#ifdef __PLUTO_MMI_PACKAGE__      
#ifdef J2ME_SHARE_MED_EXT_MEM
            mmi_frm_appmem_prompt_to_release_mem(APPLIB_MEM_AP_ID_JAVA,NULL,UI_device_height*UI_device_width*2,mmi_java_resend_mid_start_callback);
            mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_JAVA,mmi_java_asm_cancel_callback);
#else
            #ifdef __OP02__
            mmi_frm_appmem_prompt_to_release_mem(APPLIB_MEM_AP_ID_JAVA,NULL,DEFAULTHEAPSIZE 
            #ifdef __MMI_BROWSER_2__
            + mmi_brw_get_asm_memory_pool_size()
            #endif
            , mmi_java_resend_mid_start_callback);
            mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_JAVA,mmi_java_asm_cancel_callback);
            #else
            mmi_frm_appmem_prompt_to_release_mem(APPLIB_MEM_AP_ID_JAVA,NULL,DEFAULTHEAPSIZE,mmi_java_resend_mid_start_callback);
            mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_JAVA,mmi_java_asm_cancel_callback);
            #endif

#endif
#endif
        }
        else if (msg->error_code == J2ME_INSUFFICIENT_MEMORY_WHOLE_POOL)
        {
#ifdef __PLUTO_MMI_PACKAGE__           
            mmi_frm_appmem_prompt_to_release_full_pool(APPLIB_MEM_AP_ID_JAVA,NULL,mmi_java_resend_mid_start_callback);
            mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_JAVA,mmi_java_asm_cancel_callback);
#endif         
        }        
        else if(msg->error_code == OVER_MAX_VM_NUM)
        {
            #ifdef __COSMOS_MMI_PACKAGE__
            #if (MAX_VM_INSTANCE_NUM > 1) /* 20110223,SUPPORT_JAVA_SHARE_MED */
            mmi_java_mvm_entry_java_task_mgr();
            #endif /* MVM_VM_INSTANCE_NUM > 1 */
            
            g_java.screen_after_terminate = TER_ENTRY_TASK_MANAGER;
            #else
            is_popup = MMI_TRUE;
            error_str_id = STR_JAVA_ERROR_OVERMAX_LAUNCH_NUM;
            #endif
        }
        else if (msg->error_code == J2ME_UNDEFINED_ERROR)
        {
            is_popup = MMI_TRUE;
            error_str_id = STR_GLOBAL_ERROR;
        }
        else if (msg->error_code == JAR_NOT_FOUND)
        {
            is_popup = MMI_TRUE;
            error_str_id = STR_JAVA_ERROR_CODE_JAR_NOT_FOUND;
        }        
        else if(msg->error_code == DISK_NOT_FOUND)
        {
            is_popup = MMI_TRUE;
            #ifdef __MMI_USB_SUPPORT__
            if(srv_usb_is_in_mass_storage_mode())
            {
                error_str_id = STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE;
            }
            else
            #endif /* __MMI_USB_SUPPORT__ */
            {
                error_str_id = STR_JAVA_ERROR_CODE_NO_CARD;
            }
        }        
        else if(msg->error_code == DRM_PROHIBIT)
        {
            is_popup = MMI_TRUE;
            error_str_id = STR_GLOBAL_DRM_PROHIBITED;
        }
        else if(msg->error_code == J2ME_VM_IS_BUSY)
        {
            is_popup = MMI_TRUE;
            #ifdef __COSMOS_MMI_PACKAGE__
            type = VJAVA_POPUP_WARNING;
            #endif            
            error_str_id = STR_JAVA_VM_BUSY;
        }
        else
        {
            is_popup = MMI_TRUE;
            error_str_id = STR_JAVA_LAUNCH_FAIL;
        }

        if(is_popup)
        {
#ifdef __PLUTO_MMI_PACKAGE__
            mmi_popup_display_simple_ext(error_str_id, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
#elif defined (__COSMOS_MMI_PACKAGE__)
            vapp_java_display_popup(error_str_id,
                type,
                (g_java.screen_after_terminate == TER_ENTRY_INSTALL_JAVA ? VAPP_JAVA_ENTRY_REINSTALL : VAPP_JAVA_ENTRY_NONE));
#endif
        }
    }
    mmi_frm_group_close(GRP_ID_JAVA_CONFIRM);
    mmi_frm_group_close(GRP_ID_JAVA_OPT);
#ifdef J2ME_SLIM_SCREEN_MEMORY_SUPPORT
    mmi_frm_scrn_close(GRP_ID_ROOT,SCR_JAVA_DUMMY);
#endif /* J2ME_SLIM_SCREEN_MEMORY_SUPPORT */
    #if (defined(__COSMOS_MMI_PACKAGE__) /*|| MAX_VM_INSTANCE_NUM == 1*/)
    mmi_frm_scrn_set_leave_proc(APP_JAVA, SCR_JAVA_DUMMY, NULL);
    mmi_frm_group_close(APP_JAVA);
    #endif
    #if (defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
    mmi_frm_scrn_close(GRP_ID_ROOT, SCR_JAVA_DUMMY);
    #endif
    /* MAUI_02146731*/
    g_jam_allowed_sending_abort_from_idle = MMI_TRUE;
    mmi_java_set_allow_push_install(MMI_TRUE);
#if defined(__COSMOS_MMI_PACKAGE__)
    mmi_frm_cb_dereg_event(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, vapp_java_gpio_event_hdlr, NULL);
#endif    
}

#ifdef __DM_LAWMO_SUPPORT__
void  mmi_java_dmui_lawmo_callback_hdlr(mmi_dmui_app_id_enum app_id, mmi_dmui_cmd_enum cmd)
{
    if (app_id == MMI_DMUI_APP_ID_JAVA)
    {
        switch (cmd)
        {
            case MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK:
            {
                mmi_java_is_allow_stopped_popup_display(MMI_FALSE);    
                if(jam_mvm_is_vm_running(0))
                {   
                    jam_enter_terminate_mode(g_mmi_java_current_selected_vm_id); 
                    g_mmi_java_current_selected_vm_id = -1;
                }                    
                else if(jam_mvm_is_teminate_mode(g_mmi_java_current_selected_vm_id))/* Java is not in running,in this scenario java just report status */
                    {
                mmi_dmui_lawmo_report(
                    MMI_DMUI_APP_ID_JAVA,
                    MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK,
                    MMI_DMUI_RESULT_SUCCESS);
                    }
                else /* Java is in foreground running,in this scenario java is stoped by DM with deleting screen */
                    {
                        jam_enter_terminate_mode(g_mmi_java_current_selected_vm_id);
                        g_mmi_java_current_selected_vm_id = -1;
                    }
                break;
            }

            case MMI_DMUI_CMD_LAWMO_UNLOCK:
            {
                mmi_dmui_lawmo_report(
                    MMI_DMUI_APP_ID_JAVA,
                    MMI_DMUI_CMD_LAWMO_UNLOCK,
                    MMI_DMUI_RESULT_SUCCESS);
                mmi_java_is_allow_stopped_popup_display(MMI_TRUE);
                break;
            }

            default:
                break;
        }
    }
}

#endif 


/*****************************************************************************
 * FUNCTION
 *  mmi_java_after_stop_ind_proc
 * DESCRIPTION
 *  This routines is the callback proc function of the popup in mmi_java_recv_mid_stop_ind
 *  
 * PARAMETERS
 *  event id
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_java_after_stop_ind_proc(mmi_event_struct * evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {  
        case EVT_ID_POPUP_QUIT:
        if (g_java.screen_after_terminate == TER_ENTRY_INSTALL_JAVA)
        {
            mmi_alert_result_evt_struct* retEvt= (mmi_alert_result_evt_struct*)evt;
            S32 vm_id = (S32)(retEvt->user_tag);
            if(g_mmi_java_install_terminate_vm_id == vm_id)
            {
                if(mmi_java_is_allow_to_popup_screen())
                {
                    g_mmi_java_install_terminate_vm_id = -1;
                    mmi_frm_scrn_set_leave_proc(GRP_ID_JAVA_TERMINATE_CB,SCR_JAVA_TERMINATE_DIALOG2,NULL);
                    if (mmi_frm_scrn_get_active_id() == SCR_JAVA_TERMINATE_DIALOG2)
                    {
                        mmi_frm_scrn_close_active_id();
                    }
                    else
                    {                    
                        mmi_frm_scrn_close(GRP_ID_JAVA_TERMINATE_CB, SCR_JAVA_TERMINATE_DIALOG2);
                    }
                    mmi_java_mids_install_internal();
                }
                else
                {
                    g_mmi_java_is_background_display = MMI_TRUE;

                    if(g_mmi_java_reinstall_state ==0)
                    {
                        mmi_java_report_status(g_mmi_java_current_running_cmd,J2ME_ABORT_FAIL,NULL,NULL,NULL);
                    }
                    else
                    {
                        mmi_java_send_delete_menu_abort_req();
                    }

                    if (mmi_frm_scrn_get_active_id() == SCR_JAVA_TERMINATE_DIALOG2)
                    {
                        mmi_frm_scrn_close_active_id();
                    }
                    else
                    {
                        mmi_frm_scrn_close(GRP_ID_JAVA_TERMINATE_CB,SCR_JAVA_TERMINATE_DIALOG2);
                    }
                    g_mmi_java_install_terminate_vm_id = -1;
                }
                g_java.screen_after_terminate = TER_ENTRY_NONE;
                
            }
        }
        else if (g_java.screen_after_terminate == TER_ENTRY_JAVA_MENU)
        {
            EntryScrJavaMenu();
        }
        else if (g_java.screen_after_terminate == TER_ENTRY_TASK_MANAGER)
        {
#if (MAX_VM_INSTANCE_NUM > 1) /* 20110223,SUPPORT_JAVA_SHARE_MED */
            mmi_java_mvm_entry_java_task_mgr();
#endif /* MAX_VM_INSTANCE_NUM > 1 */
        }
        else if (g_java.screen_after_terminate == TER_ENTRY_LAUNCH_AFTER_INSTALL)
        {
            #ifdef __MMI_JAVA_LAUNCH_AFTER_INSTALL__
            mmi_java_launch_after_install_confirm_yes_hdlr();
            #endif /*__MMI_JAVA_LAUNCH_AFTER_INSTALL__*/
        }
        else if (g_java.screen_after_terminate == TER_ENTRY_LAUNCH_WHEN_PUSH)
        {
            mmi_java_timealarm_push_confirm_yes_hdlr();
        }
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        else if (g_java.screen_after_terminate == TER_ENTRY_DELETE_MIDS)
        {
            mmi_java_send_mids_delete_req();
        }
        g_java.screen_after_terminate = TER_ENTRY_NONE;
        mmi_frm_group_close(GRP_ID_JAVA_TASK_SWITCH);
        break;
        default:
            break;
    }
    return MMI_RET_OK;
}

void mmi_java_recv_shutdown_all_ind(void *MsgStruct)
{
#ifdef __PLUTO_MMI_PACKAGE__
#if (MAX_VM_INSTANCE_NUM > 1)                
    if(mmi_frm_scrn_get_active_id() == SCR_JAVA_RUNTIME_LIST ||
        mmi_frm_scrn_get_active_id() == SCR_JAVA || 
        mmi_frm_scrn_get_active_id() == SCR_JAVA_CATEGORY_SCREEN
       )
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,MMI_JAVA_RECV_SHUTDOWN_ALL_IND);
        if(!mmi_frm_scrn_enter(
                mmi_frm_group_get_active_id(),
                SCR_JAVA_DUMMY,
                NULL,
                NULL,
                MMI_FRM_FULL_SCRN))
        {
            return;
        }
        mmi_frm_scrn_close_active_id();
    }
#endif 
#endif

}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mid_stop_ind
 * DESCRIPTION
 *  This routines handles the message "MSG_ID_MMI_JAVA_MID_STOP_IND"
 *  Indicates that java stop MIDlets.
 * PARAMETERS
 *  MsgStruct       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_mid_stop_ind(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_notify_enum popup_type = MMI_EVENT_FAILURE;
    U16 error_str = MMI_RP_APP_JAVA_STR_MAX;
    mmi_java_mid_stop_ind_struct *msg = NULL;
    mmi_popup_property_struct arg;
    MMI_BOOL is_popup_display = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_java_mid_stop_ind_struct*) MsgStruct;

    if( mmi_java_is_allow_to_popup_screen())
    {
        /* Display popup to notify why the midlet terminates */
        switch (msg->exit_code)
        {
            case J2ME_NO_ERROR:
            #if (MAX_VM_INSTANCE_NUM > 1)
                if (g_java.screen_after_terminate == TER_ENTRY_INSTALL_JAVA
                    && g_mmi_java_install_terminate_vm_id == msg->vm_id)
                {
                    error_str = STR_JAVA_STOPPED;
                    popup_type = MMI_EVENT_SUCCESS;
                }
            #else /* MAX_VM_INSTANCE_NUM == 1 */
                error_str = STR_JAVA_STOPPED;
                popup_type = MMI_EVENT_SUCCESS;
            #endif
            #ifdef __COSMOS_MMI_PACKAGE__
                if(g_java.screen_after_terminate == TER_ENTRY_TASK_MANAGER)
                {
                    if(jam_mvm_get_current_vm_id() == INVALIDE_VM_ID)
                    {
                        if(g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mid_count == 1)
                            srv_java_appfactory_launch(SRV_APP_FACTORY_APP_LAUNCH_TYPE,g_mmi_java_current_launching_app_name,NULL,0);
                        else
                            mmi_java_entry_mid_launch();
                    }
                    
                    g_java.screen_after_terminate = TER_ENTRY_NONE;
                }
            #endif
                break;         
            case JAR_NOT_FOUND:
                error_str = STR_JAVA_ERROR_CODE_JAR_NOT_FOUND;
                #ifdef __COSMOS_MMI_PACKAGE__
                type = VJAVA_POPUP_FAILURE;
                #endif
                break;
            case DISK_NOT_FOUND:
                error_str = STR_JAVA_ERROR_CODE_NO_CARD;
                break;
#ifdef __USB_IN_NORMAL_MODE__        
            case USB_IN_USE:
                error_str = STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE;
                break;
#endif        
            case DRM_PROHIBIT:
                error_str = STR_GLOBAL_DRM_PROHIBITED;
                break;
                
            case UNSUPPORT_MIDLET:
                error_str = STR_JAVA_ERROR_UNSUPPORT_MIDLET;
                break;
            case MEMORY_ALLACTION_FAILURE:
                error_str = STR_GLOBAL_NOT_ENOUGH_MEMORY;
                break;
            default: 
                error_str = STR_JAVA_STOPPED;
            /* Java application stop */
                break;
        }
        if(error_str != MMI_RP_APP_JAVA_STR_MAX)
        {
        #ifdef __PLUTO_MMI_PACKAGE__
            mmi_popup_property_init(&arg);
            arg.callback = mmi_java_after_stop_ind_proc;
            arg.user_tag = (void *)(msg->vm_id); // not for parent proc
            mmi_popup_display_ext(error_str, popup_type, &arg);
            is_popup_display = MMI_TRUE;
        #elif defined ( __COSMOS_MMI_PACKAGE__)
            vapp_java_display_popup(error_str, type, 
                ( (g_java.screen_after_terminate == TER_ENTRY_INSTALL_JAVA
                   && g_mmi_java_install_terminate_vm_id == msg->vm_id)
                ? VAPP_JAVA_ENTRY_REINSTALL : VAPP_JAVA_ENTRY_NONE));
            if(g_java.screen_after_terminate == TER_ENTRY_INSTALL_JAVA)
                g_java.screen_after_terminate = TER_ENTRY_NONE;
        #endif
        }
    }
    else
    {
        if (g_java.screen_after_terminate == TER_ENTRY_INSTALL_JAVA
            && g_mmi_java_install_terminate_vm_id == msg->vm_id)
        {
            if(g_mmi_java_reinstall_state ==0)
            {
                mmi_java_report_status(g_mmi_java_current_running_cmd,J2ME_ABORT_FAIL,NULL,NULL,NULL);
            }
            else
            {
                mmi_java_send_delete_menu_abort_req();
            }
            #ifdef __PLUTO_MMI_PACKAGE__
            mmi_frm_scrn_set_leave_proc(GRP_ID_JAVA_TERMINATE_CB,SCR_JAVA_TERMINATE_DIALOG2,NULL);
            mmi_frm_group_close(GRP_ID_JAVA_TERMINATE_CB);
            #endif
            #ifdef __COSMOS_MMI_PACKAGE__
            vapp_java_close_venus_screen();
            #endif
            g_java.screen_after_terminate = TER_ENTRY_NONE;
            g_mmi_java_install_terminate_vm_id = -1;
        }
        if(g_java.screen_after_terminate == TER_ENTRY_TASK_MANAGER)
        {
            #ifdef __COSMOS_MMI_PACKAGE__
            vapp_java_close_venus_screen();
            #endif
        }
        #ifdef __PLUTO_MMI_PACKAGE__
        if(!mmi_frm_scrn_enter(mmi_frm_group_get_active_id() , SCR_JAVA_DUMMY, NULL,NULL, MMI_FRM_FULL_SCRN))
        {
            return;
        }
        mmi_frm_scrn_close_active_id();
        mmi_frm_group_close(GRP_ID_JAVA_BUSY);
        #endif
    }

    if (!is_popup_display)
    {
        if (g_java.screen_after_terminate == TER_ENTRY_LAUNCH_WHEN_PUSH)
        {
            mmi_java_timealarm_push_confirm_yes_hdlr();
            g_java.screen_after_terminate = TER_ENTRY_NONE;
        }
    
#if (MAX_VM_INSTANCE_NUM > 1) 
#ifdef __PLUTO_MMI_PACKAGE__
        if(mmi_frm_scrn_get_active_id() == SCR_JAVA_RUNTIME_LIST ||
            mmi_frm_scrn_get_active_id() == SCR_JAVA || 
            mmi_frm_scrn_get_active_id() == SCR_JAVA_CATEGORY_SCREEN
           )
        {
            mmi_frm_scrn_enter(
                    mmi_frm_group_get_active_id(),
                    SCR_JAVA_DUMMY,
                    NULL,
                    NULL,
                    MMI_FRM_FULL_SCRN);
            mmi_frm_scrn_close_active_id();
            g_java.screen_after_terminate = TER_ENTRY_NONE;
        }
#endif
#endif        
    }


#ifdef __DM_LAWMO_SUPPORT__
    /* report result to DM here */
    mmi_java_is_allow_stopped_popup_display(MMI_TRUE);
    mmi_dmui_lawmo_report(
               MMI_DMUI_APP_ID_JAVA,
                MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK,
                MMI_DMUI_RESULT_SUCCESS);        
#endif  
    g_jam_in_terminating = KAL_FALSE;
    mmi_java_store_setting();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mids_getinfo_req
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_MIDS_GETINFO_REQ to MOD_JAM to get info of
 *  MIDS and set protocol event handler of MSG_ID_MMI_JAVA_MIDS_GETINFO_CNF
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mids_getinfo_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_getinfo_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    if (mmi_java_check_and_display_is_busy())
    {
        return;
    }

    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_MIDS_GETINFO_REQ);

    msg = (mmi_java_mids_getinfo_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mids_getinfo_req_struct));
    msg->mids_id = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id;

    mmi_java_send_message_from_active_mod( MOD_JAM, MMI_J2ME_SAP,
        MSG_ID_MMI_JAVA_MIDS_GETINFO_REQ, msg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mids_getinfo_cnf
 * DESCRIPTION
 *  This routines handles MMI_JAVA_MIDS_GETINFO_CNF from MOD_J2ME to display
 *  specific information about assigned MIDS
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
mmi_java_mids_getinfo_cnf_struct* mids_getinfo_cnf_msg = NULL;

void mmi_java_recv_mids_getinfo_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_MIDS_GETINFO_CNF);

    if (mids_getinfo_cnf_msg )
    {
        if (mids_getinfo_cnf_msg->mids_info.mids_filename)
        {
            free_ctrl_buffer(mids_getinfo_cnf_msg->mids_info.mids_filename);
        }
        free_local_para((local_para_struct *)mids_getinfo_cnf_msg);
        mids_getinfo_cnf_msg = NULL;
    }

    mids_getinfo_cnf_msg = (mmi_java_mids_getinfo_cnf_struct *)MsgStruct;
    #ifdef __PLUTO_MMI_PACKAGE__
    hold_local_para((local_para_struct *)MsgStruct);
    mmi_java_entry_opt_info();
    #else
    srv_java_appfactory_get_mids_info_cnf(NULL);
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_transform_mids_info
 * DESCRIPTION
 *  This rountain parse the information in the MIDlet which send by message
 *  "MMI_JAVA_RECV_MIDS_GETINFO_CNF". We parse the MIDlet and layout the
 *  the information on screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_transform_mids_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dest_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mids_getinfo_cnf_msg->error_code == J2ME_NO_ERROR)
    {
        gJavaPrintableStr = (S8*)subMenuData;
        kal_mem_set(gJavaPrintableStr, 0, MAX_SUB_MENUS * MAX_SUB_MENU_SIZE);
        dest_size = MAX_SUB_MENUS * MAX_SUB_MENU_SIZE;

        if (mids_getinfo_cnf_msg->mids_info.mids_name != NULL)
        {
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) GetString(STR_JAVA_INFO_NAME), dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) L" ", dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) mids_getinfo_cnf_msg->mids_info.mids_name, dest_size);
        }

        if (mids_getinfo_cnf_msg->mids_info.mids_size > 0)
        {
            S8 java_size[10];

            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) L"\n", dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) GetString(STR_JAVA_INFO_SIZE), dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) L" ", dest_size);
            sprintf(java_size, "%u", mids_getinfo_cnf_msg->mids_info.mids_size);
            mmi_asc_to_ucs2(
                (PS8) & gJavaPrintableStr[mmi_ucs2strlen((PS8) gJavaPrintableStr) << 1],
                (PS8) java_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) L" ", dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) GetString(STR_JAVA_INFO_BYTES), dest_size);
        }

        if (mids_getinfo_cnf_msg->mids_info.mids_version != NULL)
        {
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) L"\n", dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) GetString(STR_JAVA_INFO_VERSION), dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) L" ", dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) mids_getinfo_cnf_msg->mids_info.mids_version, dest_size);
        }

        if (mids_getinfo_cnf_msg->mids_info.mids_vendor != NULL)
        {
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) L"\n", dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) GetString(STR_JAVA_INFO_VENDOR), dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) L" ", dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) mids_getinfo_cnf_msg->mids_info.mids_vendor, dest_size);
        }

        if (mids_getinfo_cnf_msg->mids_info.mids_description != NULL)
        {
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) L"\n", dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) GetString(STR_JAVA_INFO_DESC), dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) L" ", dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) mids_getinfo_cnf_msg->mids_info.mids_description, dest_size);
        }

        if (mids_getinfo_cnf_msg->mids_info.mids_webside != NULL)
        {
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) L"\n", dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) GetString(STR_JAVA_INFO_WEB), dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) L" ", dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) mids_getinfo_cnf_msg->mids_info.mids_webside, dest_size);
        }

        if ((mids_getinfo_cnf_msg->mids_info.mids_authorized == MMI_TRUE) &&
            (mids_getinfo_cnf_msg->mids_info.mids_authorized_by != NULL))
        {
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) L"\n", dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) GetString(STR_JAVA_INFO_DOMAIN), dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) L" ", dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) mids_getinfo_cnf_msg->mids_info.mids_authorized_by, dest_size);
        }
       else
        {
             mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) L"\n", dest_size);
             mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) GetString(STR_JAVA_INFO_DOMAIN), dest_size);
             mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) L" ", dest_size);
             mmi_java_ucs2cat_secure(gJavaPrintableStr,  GetString(STR_JAVA_PERM_DMN_UNTRUSTED), dest_size);
         }

        if (mids_getinfo_cnf_msg->mids_info.mids_auto_start_connection != NULL)
        {
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) L"\n", dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) GetString(STR_JAVA_INFO_CONN), dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) L" ", dest_size);
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) mids_getinfo_cnf_msg->mids_info.mids_auto_start_connection, dest_size);
        }
    #ifdef __DRM_SUPPORT__

        if (mids_getinfo_cnf_msg->mids_info.mids_filename!= NULL )
        {
            mmi_java_ucs2cat_secure(gJavaPrintableStr, (PS8) L"\n-----\n", dest_size);
            mmi_rmgr_populate_drm_info((U16*)mids_getinfo_cnf_msg->mids_info.mids_filename, DRM_PERMISSION_EXECUTE, (kal_uint8*)gJavaPrintableStr, dest_size);
        }
    #endif /* __DRM_SUPPORT__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_opt_info
 * DESCRIPTION
 *  Main Menu->FunAndGames->Java->Applications->Options->Information Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_opt_info(void)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U16 nNumofItem; /* Stores no of children in the submenu */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // U16 nStrItemList[MAX_SUB_MENUS]; /* Stores the strings id of submenus returned */

    /* gFlagDontAddHistOnScroll=1; */
    mmi_frm_group_create_ex(
        APP_JAVA,
        GRP_ID_JAVA_OPT,
        mmi_java_opt_sg_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if(!mmi_frm_scrn_enter(
            GRP_ID_JAVA_OPT,
            SCR_JAVA_APP_OPTION_INFO,
            NULL,
            mmi_java_entry_opt_info,
            MMI_FRM_FULL_SCRN))
        {
            return;
        }
   // EntryNewScreen(SCR_JAVA_APP_OPTION_INFO, NULL, mmi_java_entry_opt_info, NULL);

    /* 2 Get current screen to gui buffer  for history purposes */
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_JAVA_OPT,SCR_JAVA_APP_OPTION_INFO);

    /* 3. Retrieve no of child of menu item to be displayed */
    nNumofItem = GetNumOfChild(MENU_JAVA_APP_OPTION_INFO);

    /* 5. Retrieve string ids in sequence of given menu item to be displayed */
    /* GetSequenceStringIds(MENU_JAVA_APP_OPTION_INFO,nStrItemList); */

    /* 6. Set the current menu item's parent Id */
    SetParentHandler(MENU_JAVA_APP_OPTION_INFO);

    /* 7. Register highlight handler to be called in menu screen */
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    mmi_java_transform_mids_info();
    /* 8. Display Category74 Screen */
    ShowCategory74Screen(
        STR_GLOBAL_DETAILS,
        mmi_java_get_title_icon(),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) gJavaPrintableStr,
        mmi_ucs2strlen((PS8) gJavaPrintableStr),
        guiBuffer);

    /* 9. Register function with right softkey */
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_save_opt_setting
 * DESCRIPTION
 *  Seclecting "Setting", we well send request to java to get the specific
 *  MIDlet setting.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_execute_opt_setting (void) */
void mmi_java_save_opt_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);

    if (mmi_java_check_and_display_is_busy())
    {
        return;
    }

    g_java.domain = -1;  /* for specific midlet */

    mmi_java_send_mids_get_setting_req(g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id, g_mmi_java_current_selected_mids_root);
}
U16 g_mmi_java_make_call_number[90];
/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_make_call_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MsgStruct      [void*]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_make_call_req(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ucm_make_call_para_struct sendkey_makecall_para;
    mmi_make_call_req_ind_struct *req_msg;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_msg = (mmi_make_call_req_ind_struct*)MsgStruct;
        
    mmi_ucm_init_call_para_for_sendkey(&sendkey_makecall_para);  /*will decide the dial type based on send key rules*/
    sendkey_makecall_para.dial_type = req_msg->call_type;    
    mmi_wcscpy((U16 *) g_mmi_java_make_call_number, (const U16 *)req_msg->strNumber);    
    sendkey_makecall_para.ucs2_num_uri = (U16*)&g_mmi_java_make_call_number;   
    mmi_ucm_call_launch(0, &sendkey_makecall_para);
         
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mids_get_setting_req
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_MIDS_GET_SETTING_REQ to MOD_JAM to get setting of
 * MIDS
 *  
 * PARAMETERS
 *  mids_id         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mids_get_setting_req(U32 mids_id, kal_char* root)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_get_setting_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_MIDS_GET_SETTING_REQ);
    if (g_java.msg_ctrl & SEND_MID_GET_SETTING_CTRL )
    {
        mmi_java_display_is_busy();
    }
    else
    {
        g_java.msg_ctrl |= SEND_MID_GET_SETTING_CTRL;
        msg = (mmi_java_mids_get_setting_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mids_get_setting_req_struct));
        msg->mids_id = (kal_uint32)mids_id;
        msg->storage_name = (kal_char*)root;
    
        mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP,
            MSG_ID_MMI_JAVA_MIDS_GET_SETTING_REQ, msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mids_get_setting_cnf
 * DESCRIPTION
 *  This routines handles MMI_JAVA_MIDS_GET_SETTING_CNF from MOD_JAM to display
 *  permission screen to user to modify
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_mids_get_setting_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_get_setting_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_MIDS_GET_SETTING_CNF);

    msg = (mmi_java_mids_get_setting_cnf_struct*) MsgStruct;
    if (g_java.msg_ctrl & SEND_MID_GET_SETTING_CTRL )
    {
        g_java.msg_ctrl &= (~SEND_MID_GET_SETTING_CTRL);        
        if (msg->error_code == (kal_uint32) J2ME_NO_ERROR)
        {
            g_java.mids_trusted = (U8) msg->mids_trusted;
    
            kal_mem_cpy(&(g_java.mids_setting), &(msg->mids_setting), sizeof(mmi_setting_struct));
            kal_mem_cpy(&(g_java.mids_max_setting), &(msg->mids_max_setting), sizeof(mmi_setting_struct));
        }
        else 
        {
            mmi_popup_display_simple_ext(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE, GRP_ID_JAVA_OPT, NULL);
    
            get_setting_only = MMI_FALSE;    
            return;
        }    
    
        if (!get_setting_only)
        {
            get_domain_setting = MMI_FALSE;
            mmi_java_entry_opt_setting();
        }
    
        get_setting_only = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mids_set_setting_req
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_MIDS_SET_SETTING_REQ to MOD_JAM to set setting of
 *  MIDS and set protocol event handler of MSG_ID_MMI_JAVA_MIDS_SET_SETTING_CNF
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mids_set_setting_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_set_setting_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_MIDS_SET_SETTING_REQ);

    if (g_java.msg_ctrl & SEND_MID_SET_SETTING_CTRL )
    {
        mmi_java_display_is_busy();
    }
    else
    {
        g_java.msg_ctrl |= SEND_MID_SET_SETTING_CTRL;
        msg = (mmi_java_mids_set_setting_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mids_set_setting_req_struct));
        msg->mids_id = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id;

        kal_mem_cpy(&(msg->mids_setting), &(g_java.mids_setting), sizeof(mmi_setting_struct));

        mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP,
            MSG_ID_MMI_JAVA_MIDS_SET_SETTING_REQ, msg);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_setting_cnf_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *       
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_java_setting_cnf_proc(mmi_event_struct * evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {  
        case EVT_ID_POPUP_QUIT:
            cui_inline_close(g_java_opt_setting_inline);
        break;
        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mids_set_setting_cnf
 * DESCRIPTION
 *  This routines handles MMI_JAVA_MIDS_SET_SETTING_CNF from MOD_JAM
 * PARAMETERS
 *  MsgStruct       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_mids_set_setting_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_set_setting_cnf_struct *msg;
    mmi_popup_property_struct arg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_MIDS_SET_SETTING_CNF);

    msg = (mmi_java_mids_set_setting_cnf_struct*) MsgStruct;

    if (g_java.msg_ctrl & SEND_MID_SET_SETTING_CTRL )
    {
        if (msg->error_code == J2ME_NO_ERROR)
        {
        mmi_popup_property_init(&arg);
        arg.callback = mmi_java_setting_cnf_proc;
        mmi_popup_display_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, &arg);
        }
        else
        {
        mmi_popup_property_init(&arg);
        arg.callback = mmi_java_setting_cnf_proc;
        mmi_popup_display_ext(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE, &arg);
        }
        /* only get the setting from Java again to update the latest setting value since exclusive setting may automatically
            update other setting value*/
        get_setting_only = MMI_TRUE;
        mmi_java_send_mids_get_setting_req(g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id, NULL);
        g_java.msg_ctrl &= (~SEND_MID_SET_SETTING_CTRL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_get_choice_level
 * DESCRIPTION
 *  Transfer PERMISSION_LEVEL to J2ME_CHOICE_LEVEL
 * PARAMETERS
 *  permisisonLevel     [IN]        Level of PERMISSION_LEVEL
 * RETURNS
 *  level of J2ME_CHOICE_LEVEL
 *****************************************************************************/
S8 mmi_java_get_choice_level(S8 permisisonLevel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 selected;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (permisisonLevel)
    {
        case PERMISSION_ALLOW:
        case PERMISSION_BLANKET_GRANTED:
            selected = J2ME_CHOICE_OK;
            break;

        case PERMISSION_BLANKET:
            //if (get_domain_setting)
            //{
                selected = J2ME_CHOICE_BLANKET;
                break;
            //}
        case PERMISSION_SESSION:
            selected = J2ME_CHOICE_SESSION;
            break;

        case PERMISSION_ONE_SHOT:
        case PERMISSION_DENY_SESSION:
            selected = J2ME_CHOICE_ONESHOT;
            break;

        case PERMISSION_NEVER:
        case PERMISSION_DENY:
        case PERMISSION_USER_DENIED:
            selected = J2ME_CHOICE_USERDENY;
            break;

        default:
            selected = J2ME_CHOICE_USERDENY;
            break;
    }

    return selected;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_get_perm_menu_item_count
 * DESCRIPTION
 *  Get the menu item count form a maximum permission level.
 * PARAMETERS
 *  max_level               [IN]        
 *  permisisonLevel(?)      [IN]        Level of maximum PERMISSION_LEVEL
 * RETURNS
 *  level of J2ME_CHOICE_LEVEL
 *****************************************************************************/
S32 mmi_java_get_perm_menu_item_count(S8 max_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (max_level)
    {
        case PERMISSION_ALLOW:
        case PERMISSION_BLANKET_GRANTED:
        case PERMISSION_BLANKET:
        if(get_domain_setting)
        {
            return 4;
        }
        else
        {
            return 5;
        }
        case PERMISSION_SESSION:
            return 3;

        case PERMISSION_ONE_SHOT:
        case PERMISSION_DENY_SESSION:
            return 2;

        case PERMISSION_NEVER:
        case PERMISSION_DENY:
        case PERMISSION_USER_DENIED:
            return 1;

        default:
            return 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_get_new_permission_level
 * DESCRIPTION
 *  transfer J2ME_CHOICE_LEVEL to PERMISSION_LEVEL
 * PARAMETERS
 *  choiceLevel     [IN]        Level of J2ME_CHOICE_LEVEL
 * RETURNS
 *  level of PERMISSION_LEVEL
 *****************************************************************************/
S8 mmi_java_get_new_permission_level(S8 choiceLevel, S8 max_settings, S8 org_setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 selected;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (choiceLevel)
    {
        case J2ME_CHOICE_OK:
            if (max_settings == PERMISSION_ALLOW)
                selected = (S8) PERMISSION_ALLOW;
            else
                selected = (S8) PERMISSION_BLANKET_GRANTED;
            break;
        case J2ME_CHOICE_BLANKET:
            if(get_domain_setting)
            {
            if (max_settings == PERMISSION_ALLOW)
                selected = (S8) PERMISSION_ALLOW;
            else
            selected = (S8) PERMISSION_BLANKET_GRANTED;
            }
            else
            {
                selected = (S8) PERMISSION_BLANKET;
            }
            break;
        case J2ME_CHOICE_SESSION:
            selected = (S8) PERMISSION_SESSION;
            break;
        case J2ME_CHOICE_ONESHOT:
            selected = (S8) PERMISSION_ONE_SHOT;
            break;
        case J2ME_CHOICE_USERDENY:
            if (org_setting == PERMISSION_NEVER)
                selected = (S8) PERMISSION_NEVER;
            else
            selected = (S8) PERMISSION_USER_DENIED;
            break;
        default:
            selected = (S8) PERMISSION_USER_DENIED;
            break;
    }

    return selected;
}


void mmi_java_get_value_from_inline_cui(mmi_id inline, S32 item_index, void* value)
{
    cui_inline_get_value(inline, item_index, value);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_update_mids_setting
 * DESCRIPTION
 *  Update setting of the MIDLet
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_update_mids_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    MMI_BOOL modification_not_allowed = MMI_FALSE;
    MMI_BOOL modified = MMI_FALSE;
    S8 new_perm = 0;
    S32 new_choice = 0;
    mmi_id inline_cui = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ClearInputEventHandler(MMI_DEVICE_ALL);
    
    #ifdef OGDR_SECURITY_SETTING
    if(get_domain_setting)
    {
        inline_cui = g_java_domain_inline;
    }
    else
    {
        inline_cui = g_java_opt_setting_inline;
    }
    #else
        inline_cui = g_java_opt_setting_inline;
    #endif
    
    for( i = 0 ; i < J2ME_SETTING_MAX ;i ++)
    {
        switch (i)
        {
            case J2ME_SETTING_NETWORK_ACCESS:
            mmi_java_get_value_from_inline_cui(inline_cui, JAVA_SETTING_NETWORK_ACCESS_SELECT+i*2, (void *)&new_choice);
            new_perm = mmi_java_get_new_permission_level((S8) new_choice,
                                                                                (S8)g_java.mids_max_setting.permission_network,
                                                                                (S8)g_java.mids_setting.permission_network);
            if(g_java.mids_setting.permission_network != new_perm)
                modified = MMI_TRUE;
            if ((g_java.mids_setting.permission_network == PERMISSION_ALLOW &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_OK) ||
                (g_java.mids_setting.permission_network == PERMISSION_NEVER &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                {
                    modification_not_allowed = MMI_TRUE;
                    break;
                }
            
                g_java.mids_choice_index[i] = new_choice;
                g_java.mids_setting.permission_network = new_perm;
                break;
                
            case J2ME_SETTING_AUTO_INVOCATION:
            mmi_java_get_value_from_inline_cui(inline_cui, JAVA_SETTING_NETWORK_ACCESS_SELECT+i*2, (void *)&new_choice);
            new_perm = mmi_java_get_new_permission_level((S8) new_choice,
                                                                                (S8)g_java.mids_max_setting.permission_push,
                                                                                (S8)g_java.mids_setting.permission_push);
            if(g_java.mids_setting.permission_push != new_perm)
                modified = MMI_TRUE;
            if ((g_java.mids_setting.permission_push == PERMISSION_ALLOW &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_OK) ||
                (g_java.mids_setting.permission_push == PERMISSION_NEVER &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                {
                    modification_not_allowed = MMI_TRUE;
                    break;
                }              
                g_java.mids_choice_index[i] = new_choice;
                g_java.mids_setting.permission_push = new_perm;
                break;
            case J2ME_SETTING_MESSAGING:
                mmi_java_get_value_from_inline_cui(inline_cui, JAVA_SETTING_NETWORK_ACCESS_SELECT+i*2, (void *)&new_choice);
                new_perm  = mmi_java_get_new_permission_level((S8) new_choice,
                                                                                (S8)g_java.mids_max_setting.permission_message,
                                                                                (S8)g_java.mids_setting.permission_message);
                if(g_java.mids_setting.permission_message!= new_perm)
                    modified = MMI_TRUE;
                if ((g_java.mids_setting.permission_message == PERMISSION_ALLOW &&
                        g_java.mids_choice_index[i] !=J2ME_CHOICE_OK) ||
                    (g_java.mids_setting.permission_message == PERMISSION_NEVER &&
                        g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                    {
                        modification_not_allowed = MMI_TRUE;
                        break;
                    }
                
                g_java.mids_choice_index[i] =  new_choice;
                g_java.mids_setting.permission_message = new_perm;;
                break;
            case J2ME_SETTING_MULTIMEDIA:
            mmi_java_get_value_from_inline_cui(inline_cui, JAVA_SETTING_NETWORK_ACCESS_SELECT+i*2, (void *)&new_choice);
             new_perm = mmi_java_get_new_permission_level((S8) new_choice,
                                                                                (S8)g_java.mids_max_setting.permission_multimedia,
                                                                                (S8)g_java.mids_setting.permission_multimedia);
             if(new_perm!= g_java.mids_setting.permission_multimedia)
                modified = MMI_TRUE;
            if ((g_java.mids_setting.permission_multimedia == PERMISSION_ALLOW &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_OK) ||
                (g_java.mids_setting.permission_multimedia == PERMISSION_NEVER &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                {
                    modification_not_allowed = MMI_TRUE;
                    break;
                }
                 g_java.mids_choice_index[i] = new_choice;
                g_java.mids_setting.permission_multimedia = new_perm;
                break;
            case J2ME_SETTING_DATA_READ:
                mmi_java_get_value_from_inline_cui(inline_cui, JAVA_SETTING_NETWORK_ACCESS_SELECT+i*2, (void *)&new_choice);
                new_perm = mmi_java_get_new_permission_level((S8) new_choice,
                                                                                (S8)g_java.mids_max_setting.permission_data_read,
                                                                                (S8)g_java.mids_setting.permission_data_read);
                if(new_perm!= g_java.mids_setting.permission_data_read)
                    modified = MMI_TRUE;
            if ((g_java.mids_setting.permission_data_read == PERMISSION_ALLOW &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_OK) ||
                (g_java.mids_setting.permission_data_read == PERMISSION_NEVER &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                {
                    modification_not_allowed = MMI_TRUE;
                    break;
                }

                g_java.mids_choice_index[i] = new_choice;
                g_java.mids_setting.permission_data_read = new_perm;
                break;
            case J2ME_SETTING_DATA_WRITE:
                mmi_java_get_value_from_inline_cui(inline_cui, JAVA_SETTING_NETWORK_ACCESS_SELECT+i*2, (void *)&new_choice);
                new_perm  = mmi_java_get_new_permission_level((S8) new_choice,
                                                                                (S8)g_java.mids_max_setting.permission_data_write,
                                                                                (S8)g_java.mids_setting.permission_data_write);
              if(new_perm!= g_java.mids_setting.permission_data_write)
                modified = MMI_TRUE;
            if ((g_java.mids_setting.permission_data_write == PERMISSION_ALLOW &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_OK) ||
                (g_java.mids_setting.permission_data_write == PERMISSION_NEVER &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                {
                    modification_not_allowed = MMI_TRUE;
                    break;
                }

                g_java.mids_choice_index[i] = new_choice;
                g_java.mids_setting.permission_data_write = new_perm;
                break;
            case J2ME_SETTING_LOCAL_CONNECTIVITY:
            mmi_java_get_value_from_inline_cui(inline_cui, JAVA_SETTING_NETWORK_ACCESS_SELECT+i*2, (void *)&new_choice);
            new_perm  = mmi_java_get_new_permission_level((S8) new_choice,
                                                                                (S8)g_java.mids_max_setting.permission_local_connectivity,
                                                                                (S8)g_java.mids_setting.permission_local_connectivity);
              if(new_perm!= g_java.mids_setting.permission_local_connectivity)
                modified = MMI_TRUE;
            if ((g_java.mids_setting.permission_local_connectivity == PERMISSION_ALLOW &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_OK) ||
                (g_java.mids_setting.permission_local_connectivity == PERMISSION_NEVER &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                {
                    modification_not_allowed = MMI_TRUE;
                    break;
                }

                g_java.mids_choice_index[i] = new_choice;
                g_java.mids_setting.permission_local_connectivity = new_perm;
                break;
#ifdef SUPPORT_JSR_179
            case J2ME_SETTING_LOCATION_ACCESS:
            mmi_java_get_value_from_inline_cui(inline_cui, JAVA_SETTING_NETWORK_ACCESS_SELECT+i*2, (void *)&new_choice);     
            new_perm = mmi_java_get_new_permission_level((S8) new_choice,
                                                                                (S8)g_java.mids_max_setting.permission_location_access,
                                                                                (S8)g_java.mids_setting.permission_location_access);
            if(new_perm!= g_java.mids_setting.permission_location_access)
                modified = MMI_TRUE;
            if ((g_java.mids_setting.permission_location_access== PERMISSION_ALLOW &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_OK) ||
                (g_java.mids_setting.permission_location_access == PERMISSION_NEVER &&
                    g_java.mids_choice_index[i] !=J2ME_CHOICE_USERDENY))
                {
                    modification_not_allowed = MMI_TRUE;
                    break;
                }
            
                g_java.mids_choice_index[i] = new_choice;
                g_java.mids_setting.permission_location_access = new_perm;
                break;
#endif
          }
    }
    if (modification_not_allowed && modified){

        mmi_popup_display_simple_ext(STR_JAVA_PERMISSION_SETTING_FAIL, MMI_EVENT_FAILURE, GRP_ID_JAVA_OPT, NULL);
        mmi_frm_scrn_close(GRP_ID_JAVA_OPT,SCR_JAVA_APP_OPTION_SETTING);
        return;
    }else if(!modified)
            {
                mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_JAVA_OPT, NULL);
                mmi_frm_scrn_close(GRP_ID_JAVA_OPT,SCR_JAVA_APP_OPTION_SETTING);
                return;
            }
    
    #ifdef OGDR_SECURITY_SETTING
    if (g_java.domain >= 0 )
    {
        mmi_java_send_set_default_domain_req();
    }
    else
    #endif
    {
        mmi_java_send_mids_set_setting_req();
    }
}


U16 g_mmi_java_current_selected_domain[30];
/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_opt_setting
 * DESCRIPTION
 *  Main Menu->FunAndGames->Java->Applications->Options->Setting Entry Function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_opt_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     U16* domain_select_string[4];
    U16* setting_select_string[5];
    static cui_inline_item_select_struct domain_select;
     static cui_inline_item_select_struct setting_select;
    
    /*------------Net work access --------------*/
    static cui_inline_item_caption_struct caption_network =
    {
        STR_JAVA_SETTING_NETWORK_ACCESS
    };
     /*-----------push-----------*/
     static cui_inline_item_caption_struct caption_auto =
    {
        STR_JAVA_SETTING_AUTO_INVOCATION
    };
      /*------------ Java message -------------*/
       static cui_inline_item_caption_struct caption_message =
      {
          STR_JAVA_SETTING_MESSAGING
      };
     /*------------multimedia --------------*/
      static cui_inline_item_caption_struct caption_multimedia =
     {
         STR_JAVA_SETTING_MULTIMEDIA
     };       
    /*------------Data read ---------------*/
      static cui_inline_item_caption_struct caption_data_read =
     {
         STR_JAVA_SETTING_FILE_READ
     };  
    /*-----------Data write--------------*/
     static cui_inline_item_caption_struct caption_data_write =
     {
         STR_JAVA_SETTING_FILE_WRITE
     };
     /*-----------Local connection --------------*/
     static cui_inline_item_caption_struct caption_conn =
     {
         STR_JAVA_SETTING_LOCAL_CONNECTIVITY
     };     
#ifdef SUPPORT_JSR_179
     /*-----------Location access --------------*/
     static cui_inline_item_caption_struct caption_conn_179 =
     {
         STR_JAVA_SETTING_LOCATION_ACCESS
     };          
#endif
    static cui_inline_item_softkey_struct java_opt_inline_sofkey = 
    {
        { {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0}, 
          {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
          {0, IMG_GLOBAL_COMMON_CSK} }
     };
#ifdef SUPPORT_JSR_179
    static const cui_inline_set_item_struct java_opt_setting_item[16 ] = 
#else
    static const cui_inline_set_item_struct java_opt_setting_item[14 ] = 
#endif
    {
       {JAVA_SETTING_NETWORK_ACCESS_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, &caption_network},
        {JAVA_SETTING_NETWORK_ACCESS_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &setting_select},
        {JAVA_SETTING_AUTO_INVOCATION_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, &caption_auto},
        {JAVA_SETTING_AUTO_INVOCATION_SELECT, CUI_INLINE_ITEM_TYPE_SELECT,0,&setting_select},
        {JAVA_SETTING_MESSAGING_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, &caption_message},
        {JAVA_SETTING_MESSAGING_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &setting_select},
        {JAVA_SETTING_MULTIMEDIA_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L4, &caption_multimedia},
        {JAVA_SETTING_MULTIMEDIA_SELECT, CUI_INLINE_ITEM_TYPE_SELECT,0, &setting_select},
        {JAVA_SETTING_FILE_READ_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L5, &caption_data_read},
        {JAVA_SETTING_FILE_READ_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &setting_select},
        {JAVA_SETTING_FILE_WRITE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L6, &caption_data_write},
        {JAVA_SETTING_FILE_WRITE_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &setting_select},
        {JAVA_SETTING_LOCAL_CONNECTIVITY_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION , IMG_GLOBAL_L7, &caption_conn},
        {JAVA_SETTING_LOCAL_CONNECTIVITY_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &setting_select}
#ifdef SUPPORT_JSR_179
    ,{JAVA_SETTING_LOVAL_LOCATION_ACCESS_CAPTION,CUI_INLINE_ITEM_TYPE_CAPTION,IMG_GLOBAL_L8,&caption_conn_179},
    {JAVA_SETTING_LOVAL_LOCATION_ACCESS_SELECT,CUI_INLINE_ITEM_TYPE_SELECT, 0, &domain_select}
 #endif   
    };
#ifdef SUPPORT_JSR_179
    static const cui_inline_set_item_struct java_general_domain_item[16] = 
#else
    static const cui_inline_set_item_struct java_general_domain_item[14] = 
#endif
    {
        {JAVA_SETTING_NETWORK_ACCESS_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, &caption_network},
        {JAVA_SETTING_NETWORK_ACCESS_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &domain_select},
        {JAVA_SETTING_AUTO_INVOCATION_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, &caption_auto},
        {JAVA_SETTING_AUTO_INVOCATION_SELECT, CUI_INLINE_ITEM_TYPE_SELECT,0,&domain_select},
        {JAVA_SETTING_MESSAGING_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, &caption_message},
        {JAVA_SETTING_MESSAGING_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &domain_select},
        {JAVA_SETTING_MULTIMEDIA_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L4, &caption_multimedia},
        {JAVA_SETTING_MULTIMEDIA_SELECT, CUI_INLINE_ITEM_TYPE_SELECT,0, &domain_select},
        {JAVA_SETTING_FILE_READ_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L5, &caption_data_read},
        {JAVA_SETTING_FILE_READ_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &domain_select},
        {JAVA_SETTING_FILE_WRITE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L6, &caption_data_write},
        {JAVA_SETTING_FILE_WRITE_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &domain_select},
        {JAVA_SETTING_LOCAL_CONNECTIVITY_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION , IMG_GLOBAL_L7, &caption_conn},
        {JAVA_SETTING_LOCAL_CONNECTIVITY_SELECT, CUI_INLINE_ITEM_TYPE_SELECT, 0, &domain_select}
 #ifdef SUPPORT_JSR_179    
    ,{JAVA_SETTING_LOVAL_LOCATION_ACCESS_CAPTION,CUI_INLINE_ITEM_TYPE_CAPTION,IMG_GLOBAL_L8,&caption_conn_179},
    {JAVA_SETTING_LOVAL_LOCATION_ACCESS_SELECT,CUI_INLINE_ITEM_TYPE_SELECT, 0, &domain_select}
#endif
    };
    
    const cui_inline_struct java_opt_setting_inline_screen = 
    {
        2*J2ME_SETTING_MAX,
        0,
        0,
        CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
        &java_opt_inline_sofkey,
        java_opt_setting_item
    };
    const cui_inline_struct java_general_domain_inline_screen = 
    {
        2*J2ME_SETTING_MAX,
        0,
        0,
        CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
        &java_opt_inline_sofkey,
        java_general_domain_item
    };


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   domain_select_string[0] =(U16*)GetString(STR_JAVA_PERM_USERDENY);
   domain_select_string[1] = (U16*)GetString(STR_JAVA_PERM_ONESHOT);
   domain_select_string[2] = (U16*)GetString(STR_JAVA_PERM_SESSION);
   domain_select_string[3] = (U16*)GetString(STR_JAVA_PERM_BLANKET);  

   setting_select_string[0] = (U16*)GetString(STR_JAVA_PERM_USERDENY);
   setting_select_string[1] = (U16*)GetString(STR_JAVA_PERM_ONESHOT);
   setting_select_string[2] = (U16*)GetString(STR_JAVA_PERM_SESSION), 
   setting_select_string[3] =(U16*)GetString(STR_JAVA_PERM_BLANKET);
   setting_select_string[4] =(U16*)GetString(STR_JAVA_PERM_BLANKET_GRANTED);

#ifdef OGDR_SECURITY_SETTING    
    /* Domain setting */
    if(get_domain_setting)
        {
            mmi_frm_group_create_ex(
                GRP_ID_ROOT,
                GRP_ID_JAVA_SECURITY,
                mmi_java_setting_and_security_sg_proc,
                NULL,
                MMI_FRM_NODE_SMART_CLOSE_FLAG);
        g_java_domain_inline = cui_inline_create(GRP_ID_JAVA_SECURITY,&java_general_domain_inline_screen);
        if(!mmi_wcscmp((U16*)(g_mmi_java_current_selected_domain), (U16*)get_string(STR_JAVA_PERM_DMN_3RDPARTY)))
        {
            cui_inline_set_title(g_java_domain_inline, STR_JAVA_PERM_DMN_3RDPARTY, mmi_java_get_title_icon()); 
        }
        else if(!mmi_wcscmp((U16*)(g_mmi_java_current_selected_domain), (U16*)get_string(STR_JAVA_PERM_DMN_UNTRUSTED)))        
        {
            cui_inline_set_title(g_java_domain_inline,STR_JAVA_PERM_DMN_UNTRUSTED,mmi_java_get_title_icon());   
        }
        cui_inline_set_title_icon(g_java_domain_inline,mmi_java_get_title_icon());

        cui_inline_set_item_select(
            g_java_domain_inline,
            JAVA_SETTING_NETWORK_ACCESS_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_network),
            (PU8*)&domain_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_network));

         cui_inline_set_item_select(
            g_java_domain_inline,
            JAVA_SETTING_AUTO_INVOCATION_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_push),
            (PU8*)&domain_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_push));   

         cui_inline_set_item_select(
            g_java_domain_inline,
            JAVA_SETTING_MESSAGING_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_message),
            (PU8*)&domain_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_message));     

          cui_inline_set_item_select(
            g_java_domain_inline,
            JAVA_SETTING_MULTIMEDIA_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_multimedia),
            (PU8*)&domain_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_multimedia));    

          cui_inline_set_item_select(
            g_java_domain_inline,
            JAVA_SETTING_FILE_READ_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_data_read),
            (PU8*)&domain_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_data_read));    

          cui_inline_set_item_select(
            g_java_domain_inline,
            JAVA_SETTING_FILE_WRITE_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_data_write),
            (PU8*)&domain_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_data_write));    

          cui_inline_set_item_select(
            g_java_domain_inline,
            JAVA_SETTING_LOCAL_CONNECTIVITY_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_local_connectivity),
            (PU8*)&domain_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_local_connectivity));    
#ifdef SUPPORT_JSR_179
          cui_inline_set_item_select(
            g_java_domain_inline,
            JAVA_SETTING_LOVAL_LOCATION_ACCESS_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_location_access),
            (PU8*)&domain_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_location_access)); 
#endif
        cui_inline_register_lsk_handler();
        cui_inline_register_rsk_handler();

        cui_inline_run(g_java_domain_inline);
     }
    else    /* Option setting */
#endif
        {
            mmi_frm_group_create_ex(
                APP_JAVA,
                GRP_ID_JAVA_OPT,
                mmi_java_opt_sg_proc,
                NULL,
                MMI_FRM_NODE_SMART_CLOSE_FLAG);
            g_java_opt_setting_inline = cui_inline_create(GRP_ID_JAVA_OPT,&java_opt_setting_inline_screen);
            cui_inline_set_title(g_java_opt_setting_inline, STR_GLOBAL_SETTINGS, mmi_java_get_title_icon()); 
            cui_inline_set_title_icon(g_java_opt_setting_inline,mmi_java_get_title_icon());

           cui_inline_set_item_select(
            g_java_opt_setting_inline,
            JAVA_SETTING_NETWORK_ACCESS_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_network),
            (PU8*)&setting_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_network));
         cui_inline_set_item_select(
            g_java_opt_setting_inline,
            JAVA_SETTING_AUTO_INVOCATION_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_push),
            (PU8*)&setting_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_push));   
         cui_inline_set_item_select(
            g_java_opt_setting_inline,
            JAVA_SETTING_MESSAGING_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_message),
            (PU8*)&setting_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_message));     
          cui_inline_set_item_select(
            g_java_opt_setting_inline,
            JAVA_SETTING_MULTIMEDIA_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_multimedia),
            (PU8*)&setting_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_multimedia));    
          cui_inline_set_item_select(
            g_java_opt_setting_inline,
            JAVA_SETTING_FILE_READ_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_data_read),
            (PU8*)&setting_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_data_read));    
          cui_inline_set_item_select(
            g_java_opt_setting_inline,
            JAVA_SETTING_FILE_WRITE_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_data_write),
            (PU8*)&setting_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_data_write));    
          cui_inline_set_item_select(
            g_java_opt_setting_inline,
            JAVA_SETTING_LOCAL_CONNECTIVITY_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_local_connectivity),
            (PU8*)&setting_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_local_connectivity));  
 #ifdef SUPPORT_JSR_179
          cui_inline_set_item_select(
            g_java_opt_setting_inline,
            JAVA_SETTING_LOVAL_LOCATION_ACCESS_SELECT,
            mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_location_access),
            (PU8*)&setting_select_string,
            mmi_java_get_choice_level(g_java.mids_setting.permission_location_access)); 
 #endif
            cui_inline_register_lsk_handler();
            cui_inline_register_rsk_handler();
            cui_inline_run(g_java_opt_setting_inline);
        }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_show_waiting_package_dialog_delete_cb
 * DESCRIPTION
 *  
 *  
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
mmi_ret mmi_java_show_waiting_package_dialog_delete_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_GOBACK:
        if (g_mmi_java_is_in_package)
        {
            if (g_java.msg_ctrl & SEND_MIDS_PACKAGE_CTRL)
            {
                break;
            }
            else
            {
                g_java.msg_ctrl |= SEND_MIDS_PACKAGE_CTRL;
            }
            mmi_java_send_java_abort_req();
            break;
        }
        default:
            break;
    }
     return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *   mmi_java_cancel_mids_package
 * DESCRIPTION
 *  
 *  
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_cancel_mids_package(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_java.msg_ctrl & SEND_MIDS_PACKAGE_CTRL)
    {
        return;
    }
    else
    {
        g_java.msg_ctrl |= SEND_MIDS_PACKAGE_CTRL;
    }
    
    mmi_java_send_java_abort_req();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_show_waiting_package_dialog
 * DESCRIPTION
 *  show notify dialog when vm send report of installation or deltetion
 *  
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_show_waiting_package_dialog(void)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_frm_scrn_enter(
        GRP_ID_JAVA_PACKAGE, 
        SCR_JAVA_WAITING_PACKAGE_DIALOG,
        NULL,
        mmi_java_show_waiting_package_dialog,
        MMI_FRM_FULL_SCRN))
        {
            return;
        }
    mmi_frm_scrn_set_leave_proc(GRP_ID_JAVA_PACKAGE,SCR_JAVA_WAITING_PACKAGE_DIALOG,mmi_java_show_waiting_package_dialog_delete_cb);
    ShowCategory8Screen(
        STR_JAVA_PERMISSION_TITLE,
        mmi_java_get_install_title_icon(),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        STR_GLOBAL_PLEASE_WAIT,
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    SetRightSoftkeyFunction(mmi_java_cancel_mids_package, KEY_EVENT_UP);
   
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_mids_package_req
 * DESCRIPTION
 *  This routines send MSG_ID_MMI_JAVA_MIDS_REMOVE_REQ to MOD_J2ME to send
 *  delete request of MIDS and set protocol event handler of MSG_ID_MMI_JAVA_MIDS_REMOVE_CNF and
 *  MSG_ID_MMI_JAVA_MIDS_REMOVE_CONFIRM_IND
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_mids_package_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_package_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(jam_is_busy() || g_mmi_java_is_in_package)
    {
        mmi_frm_scrn_close(GRP_ID_JAVA_PACKAGE,SCR_JAVA_PACKAGE_CONFIRM);
        mmi_java_display_is_busy();
        return;
    }
    mmi_java_set_allow_push_install(MMI_FALSE);
    /* Justin 003 waiting screen */
    g_mmi_java_is_in_package = MMI_TRUE;
    msg = (mmi_java_mids_package_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mids_package_req_struct));
    msg->package_mode = g_mmi_java_package_mode;
    if (g_mmi_java_package_mode == 0)
    {
        /* java screen */
        msg->mids_id = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id;
        msg->mids_name = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_name;
        msg->output_dir = g_mmi_java_mids_package_dir_path;
    }
    else
    {
        /* filemgr */
        msg->mids_id = -1;
        msg->file_path = g_mmi_java_mids_package_file_path;
        msg->mids_name = NULL;
        msg->output_dir = g_mmi_java_mids_package_dir_path;
    }
    mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP,
            MSG_ID_MMI_JAVA_MIDS_PACKAGE_REQ, msg);
        mmi_java_show_waiting_package_dialog();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_package_warn_user
 * DESCRIPTION
 *  This function entry the screen ask user package or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_package_warn_user(void)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_JAVA_PACKAGE,
        mmi_java_opt_sg_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    if(!mmi_frm_scrn_enter(
            GRP_ID_JAVA_PACKAGE,
            SCR_JAVA_PACKAGE_CONFIRM,
            NULL,
           mmi_java_entry_package_warn_user,
            MMI_FRM_FULL_SCRN))
        {
            return;
        }
    //EntryNewScreen(SCR_JAVA_PACKAGE_CONFIRM, NULL, mmi_java_entry_package_warn_user, NULL);
     
    ShowCategory74Screen(
        STR_JAVA_PERMISSION_TITLE,
        mmi_java_get_install_title_icon(),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU8) GetString(STR_JAVA_PACKAGE_CONFIRM),
        mmi_ucs2strlen(GetString(STR_JAVA_PACKAGE_CONFIRM)),
        NULL);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_java_send_mids_package_req, KEY_EVENT_UP);        
    SetLeftSoftkeyFunction(mmi_java_send_mids_package_req, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif
}


void mmi_java_save_as_file_evt_hdlr(mmi_event_struct * param)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_file_selector_result_event_struct * evt = (cui_file_selector_result_event_struct *) param;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->result > 0)
    {
        cui_file_selector_get_selected_filepath(
            evt->sender_id, 
            NULL, 
            g_mmi_java_mids_package_dir_path, 
            (SRV_FMGR_PATH_MAX_LEN+1) * ENCODING_LENGTH);
    cui_file_selector_close(evt->sender_id);
        mmi_java_entry_package_warn_user();
     }
    else
    {
        cui_file_selector_close(evt->sender_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_send_screen_yes_hanlder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_send_screen_yes_hanlder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;
    mmi_id fmgr_cui_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_java_package_mode == 0)
    {
         /* java screen mode */
        if (g_mmi_java_mids_package_menu_index == g_mmi_java_total_send_item_number)
        {
            FMGR_FILTER_INIT(&filter);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
            fmgr_cui_id = cui_file_selector_create(
                APP_JAVA,
                (WCHAR*) L"root",
                &filter,
               CUI_FILE_SELECTOR_STYLE_FILE_AND_PATH,
               CUI_FILE_SELECTOR_OPT_DRM_CHECK_SET_ON);
            
                cui_file_selector_run(fmgr_cui_id);
            return;
        }
    }
    else
    {
         /* filemanager mode */
        if (g_mmi_java_mids_package_menu_index == (g_mmi_java_total_send_item_number<<1))
        {
            FMGR_FILTER_INIT(&filter);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);
             fmgr_cui_id = cui_file_selector_create(
                GRP_ID_JAVA_PACKAGE,
                (WCHAR*) L"root",
                &filter,
               CUI_FILE_SELECTOR_STYLE_FILE_AND_PATH,
               CUI_FILE_SELECTOR_OPT_DRM_CHECK_SET_ON);
            
                cui_file_selector_run(fmgr_cui_id);
            return;
        }
        
        if (g_mmi_java_mids_package_menu_index < g_mmi_java_total_send_item_number)
        {
            /* use original method to send */
            g_mmi_java_mids_package_execute_menu_id = GetSeqItemId_Ext(g_mmi_java_mids_package_menu_id, g_mmi_java_mids_package_menu_index);
            srv_fmgr_types_launch_option((WCHAR*)g_mmi_java_mids_package_file_path, g_mmi_java_mids_package_execute_menu_id);
            return;
        }
    }
    if (g_mmi_java_mids_package_menu_index >= g_mmi_java_total_send_item_number)
    {
        g_mmi_java_mids_package_menu_index -= g_mmi_java_total_send_item_number;
    }
    g_mmi_java_mids_package_execute_menu_id = GetSeqItemId_Ext(g_mmi_java_mids_package_menu_id, g_mmi_java_mids_package_menu_index);
    mmi_java_entry_package_warn_user();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_package_screen_menu_handler
 * DESCRIPTION
 *  This function entry the screen ask user package or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_package_screen_menu_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_java_mids_package_menu_index = index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_send_screen_from_fgmr_deleteCB
 * DESCRIPTION
 *  This function entry the screen ask user package or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_java_entry_send_screen_deleteCB(void* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_java_mids_package_file_path)
    {
        free_ctrl_buffer(g_mmi_java_mids_package_file_path);
        g_mmi_java_mids_package_file_path = NULL;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_package_sg_proc
 * DESCRIPTION
 *  This function entry the screen ask user package or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_java_package_sg_proc(mmi_event_struct* param)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_file_selector_result_event_struct * evt = (cui_file_selector_result_event_struct *) param;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
        {
            case EVT_ID_CUI_FOLDER_SELECTOR_RESULT:
            case EVT_ID_CUI_FILE_SELECTOR_RESULT:
            {
                #if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
                    mmi_java_save_as_file_evt_hdlr(param);
                #endif
                return MMI_RET_OK;;
            }
            default:
                break;
        }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_exit_send_screen_from_fgmr
 * DESCRIPTION
 *  This function entry the screen ask user package or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_exit_send_screen_from_fgmr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < g_mmi_java_total_send_item_number; i++)
    {
        free_ctrl_buffer(g_mmi_java_mids_package_send_menu_item[i+g_mmi_java_total_send_item_number]);   
    }
}

void mmi_java_entry_send_screen_from_fmgr_entry_screen(void)    
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* guibuffer;
    U16 nStrItemList[10];
    S32 i;
    srv_fmgr_fileinfo_struct   info;
    S32 len;
    U16 *temp_string = NULL;
    U16 icon_id;
    extern MMI_BOOL mmi_fmgr_get_app_title_info(U16 app_id,U16 * title_id,U16 * icon_id,S8 * path);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_string = (U16*) GetString(STR_JAVA_MIDLET_MESSAGE);
        mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_JAVA_PACKAGE,mmi_java_package_sg_proc,NULL);
        mmi_frm_group_enter(GRP_ID_JAVA_PACKAGE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        if(!mmi_frm_scrn_enter(
                GRP_ID_JAVA_PACKAGE,
                SCR_JAVA_PACKAGE_SEND_LIST,
                mmi_java_exit_send_screen_from_fgmr,
                mmi_java_entry_send_screen_from_fmgr_entry_screen,
                MMI_FRM_FULL_SCRN))
            {
                return;
            }
        /*mmi_frm_scrn_set_leave_proc(GRP_ID_JAVA_PACKAGE, SCR_JAVA_PACKAGE_SEND_LIST, mmi_java_entry_send_screen_deleteCB);*/

        guibuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_JAVA_PACKAGE,SCR_JAVA_PACKAGE_SEND_LIST);
        // display option screen
        RegisterHighlightHandler(mmi_java_package_screen_menu_handler);
        if (g_mmi_java_mids_package_menu_id > 0)
        {
            g_mmi_java_total_send_item_number = GetNumOfChild_Ext(g_mmi_java_mids_package_menu_id);
            GetSequenceStringIds_Ext(g_mmi_java_mids_package_menu_id, nStrItemList);
            SetParentHandler(g_mmi_java_mids_package_menu_id);
        }
        else 
        {
            g_mmi_java_total_send_item_number = 0;
        }
        if (g_mmi_java_total_send_item_number >= MAX_SEND_MENU_ITEM/2)
        {
            ASSERT(0);
        }
        for (i = 0; i < g_mmi_java_total_send_item_number; i++)
        {
            g_mmi_java_mids_package_send_menu_item[i] = (U8*) GetString(nStrItemList[i]);
        }
        for (i = 0; i < g_mmi_java_total_send_item_number; i++)
        {
            len = mmi_ucs2strlen((S8*)g_mmi_java_mids_package_send_menu_item[i]);
            g_mmi_java_mids_package_send_menu_item[i+g_mmi_java_total_send_item_number] = get_ctrl_buffer((len+mmi_ucs2strlen((S8*)temp_string)+1)<<1);
            memcpy(g_mmi_java_mids_package_send_menu_item[i+g_mmi_java_total_send_item_number],
                    g_mmi_java_mids_package_send_menu_item[i], (len+1)<<1);
            mmi_ucs2cat((S8*)g_mmi_java_mids_package_send_menu_item[i+g_mmi_java_total_send_item_number],(S8*)temp_string);
        }
        /* add save as file */
        #ifdef __PLUTO_MMI_PACKAGE__
        mmi_fmgr_get_app_title_info(APP_FILEMANAGER, NULL, &icon_id, NULL);
        #endif
        g_mmi_java_mids_package_send_menu_item[g_mmi_java_total_send_item_number<<1] = (U8*) GetString(STR_JAVA_SAVE_AS_FILE);
        ShowCategory353Screen(
            (U8*) GetString(STR_GLOBAL_SEND), 
            icon_id, 
            STR_GLOBAL_OK, 
            IMG_GLOBAL_OK, 
            STR_GLOBAL_BACK, 
            IMG_GLOBAL_BACK,
            (g_mmi_java_total_send_item_number<<1) + 1,
            g_mmi_java_mids_package_send_menu_item,
            (U16*) gIndexIconsImageList, 
            NULL,
            0,
            0,
            guibuffer);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_java_entry_send_screen_yes_hanlder, KEY_EVENT_UP);            
        SetLeftSoftkeyFunction(mmi_java_entry_send_screen_yes_hanlder, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif
    }
#endif  /* #if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_send_screen_from_java
 * DESCRIPTION
 *  This function entry the screen ask user package or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_send_screen_from_java(void)
{
#if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__) && defined __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 nStrItemList[10];
    U8 *guibuffer = NULL;
    S32 i;
    S32 temp_hdler;
    U8* temp_file_folder;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_java_package_mode = 0;
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    if (g_mmi_java_mids_package_file_path)
    {
        free_ctrl_buffer(g_mmi_java_mids_package_file_path);
        g_mmi_java_mids_package_file_path = NULL;
    }
    /* XXX create temp file to get transfer method, it can be improved fileMgr interface can be changed XXX*/
    temp_file_folder = (U8*)jvm_util_get_work_sys_dir_path();
    g_mmi_java_mids_package_file_path = get_ctrl_buffer((strlen((kal_char*)temp_file_folder) + 11)<<1);
    kal_wsprintf(g_mmi_java_mids_package_file_path,"%s\\-temp.jar",temp_file_folder);
    temp_hdler = FS_Open((U16*) g_mmi_java_mids_package_file_path,  FS_CREATE_ALWAYS | FS_READ_WRITE);
    FS_Close(temp_hdler);
    
    g_mmi_java_mids_package_menu_id = srv_fmgr_types_get_send_option_menu(FMGR_TYPE_JAR, (WCHAR *)g_mmi_java_mids_package_file_path);      
    FS_Delete(g_mmi_java_mids_package_file_path);
    free_ctrl_buffer(g_mmi_java_mids_package_file_path);
    g_mmi_java_mids_package_file_path = NULL;
 
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    {
        mmi_frm_group_create(GRP_ID_JAVA_OPT, GRP_ID_JAVA_PACKAGE,mmi_java_package_sg_proc,NULL);
        mmi_frm_group_enter(GRP_ID_JAVA_PACKAGE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        if(!mmi_frm_scrn_enter(
                GRP_ID_JAVA_PACKAGE,
                SCR_JAVA_PACKAGE_SEND_LIST,
                NULL,
                mmi_java_entry_send_screen_from_java,
                MMI_FRM_FULL_SCRN))
            {
                return;
            }
        //SetDelScrnIDCallbackHandler(SCR_JAVA_PACKAGE_SEND_LIST,(HistoryDelCBPtr)mmi_java_entry_send_screen_deleteCB);
       /* mmi_frm_scrn_set_leave_proc(GRP_ID_JAVA_PACKAGE, SCR_JAVA_PACKAGE_SEND_LIST, mmi_java_entry_send_screen_deleteCB);*/

        guibuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_JAVA_PACKAGE, SCR_JAVA_PACKAGE_SEND_LIST);
        // display option screen
        RegisterHighlightHandler(mmi_java_package_screen_menu_handler);
        if (g_mmi_java_mids_package_menu_id > 0)
        {
            g_mmi_java_total_send_item_number = GetNumOfChild_Ext(g_mmi_java_mids_package_menu_id);
            GetSequenceStringIds_Ext(g_mmi_java_mids_package_menu_id, nStrItemList);
            SetParentHandler(g_mmi_java_mids_package_menu_id);
        }
        else 
        {
            g_mmi_java_total_send_item_number = 0;
        }
        if (g_mmi_java_total_send_item_number >= MAX_SEND_MENU_ITEM/2)
        {
            ASSERT(0);
        }
        for (i = 0; i < g_mmi_java_total_send_item_number; i++)
        {
            g_mmi_java_mids_package_send_menu_item[i] = (U8*) GetString(nStrItemList[i]);
        }
        /* add save as file */
        g_mmi_java_mids_package_send_menu_item[i] = (U8*) GetString(STR_JAVA_SAVE_AS_FILE);
        wgui_list_menu_enable_access_by_shortcut();       
        ShowCategory353Screen(
            (U8*) GetString(STR_GLOBAL_SEND), 
            mmi_java_get_install_title_icon(), 
            STR_GLOBAL_OK, 
            IMG_GLOBAL_OK, 
            STR_GLOBAL_BACK, 
            IMG_GLOBAL_BACK,
            g_mmi_java_total_send_item_number + 1,
            g_mmi_java_mids_package_send_menu_item,
            (U16*) gIndexIconsImageList, 
            NULL,
            0,
            0,
            guibuffer);
            
        SetLeftSoftkeyFunction(mmi_java_entry_send_screen_yes_hanlder, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_java_entry_send_screen_yes_hanlder, KEY_EVENT_UP);
    }
#endif  /* #if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__) */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_send_screen_from_fgmr
 * DESCRIPTION
 *  This function entry the screen ask user package or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_send_screen_from_fgmr(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
#if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_java_package_mode = 1;
    if (g_mmi_java_mids_package_dir_path[0]!='\0')
    {
        #if 0
/* under construction !*/
/* under construction !*/
#endif
        g_mmi_java_mids_package_dir_path[0] = '\0';
    }

    if (g_mmi_java_mids_package_file_path != NULL)
    {
        free_ctrl_buffer(g_mmi_java_mids_package_file_path);
        g_mmi_java_mids_package_file_path = NULL;
    }
        ASSERT(filepath!=NULL);
        len = get_ucs2_len((kal_wchar*)filepath);
        g_mmi_java_mids_package_file_path = get_ctrl_buffer((len+1)<<1);
        memcpy(g_mmi_java_mids_package_file_path,filepath,(len+1)<<1);
    g_mmi_java_mids_package_menu_id = srv_fmgr_types_get_send_option_menu(0, (WCHAR*) g_mmi_java_mids_package_file_path);
    mmi_java_entry_send_screen_from_fmgr_entry_screen();
#endif /*defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)*/
}


#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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


MMI_BOOL g_mmi_java_is_launching_midlet = MMI_FALSE; 
#ifdef __MMI_JAVA_LAUNCH_AFTER_INSTALL__
/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_push_install_confirm_delete_cb                                                                                                                                         
 * DESCRIPTION
 *  when the right of pre-install jar is received, ask user want to continue                                                                                                              
 *  install or not.                                                                                                                                                                       
 * PARAMETERS
 *                                                                                                                                                                                        
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_java_launch_after_install_confirm_delete_cb(void *ptr)                                                                                                                             
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_java_set_allow_push_install(KAL_TRUE);                                                                                                                                            
    g_mmi_java_is_launching_midlet = MMI_FALSE;   
    return MMI_FALSE;                                                                                                                                                                     
}


mmi_ret mmi_java_launch_after_install_confirm_screen_leave_proc(mmi_event_struct *evt)                                                                                                       
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
        mmi_java_launch_after_install_confirm_delete_cb(NULL); 
        break;                                                                                                                                                                            
    }                                                                                                                                                                                     
    return MMI_RET_OK;                                                                                                                                                                    
}


void mmi_java_entry_launch_after_install_confirm_int(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_launch_after_install_confirm
 * DESCRIPTION
 *  The entry function to ask user if they want launch directly after installation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_launch_after_install_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = g_mmi_java_install_mids_id;
    needToSendGetListReq = MMI_TRUE;
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_JAVA_CONFIRM,
        NULL,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_java_entry_launch_after_install_confirm_int();
}


void mmi_java_entry_launch_after_install_confirm_int(void)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *str;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(GRP_ID_JAVA_CONFIRM, SCR_JAVA_LAUNCH_AFTER_INSTALL, NULL, mmi_java_entry_launch_after_install_confirm_int, MMI_FRM_FULL_SCRN))                                   
    {     
        return;                                                                                                                                                                       
     }
    mmi_frm_scrn_set_leave_proc(GRP_ID_JAVA_CONFIRM, SCR_JAVA_LAUNCH_AFTER_INSTALL, mmi_java_launch_after_install_confirm_screen_leave_proc);

    /* stop push install in this screen */
    mmi_java_set_allow_push_install(MMI_FALSE);
    g_mmi_java_is_launching_midlet = MMI_TRUE;
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_JAVA_CONFIRM,SCR_JAVA_LAUNCH_AFTER_INSTALL);

    str = (U8*) get_string(STR_JAVA_LAUNCH_AFTER_INSTALL);
    ShowCategory74Screen(
        STR_JAVA_LAUNCH_ASK,
        mmi_java_get_install_title_icon(),
        STR_GLOBAL_YES,
        IMG_GLOBAL_YES,
        STR_GLOBAL_NO,
        IMG_GLOBAL_NO,
        (PU8) str,
        mmi_ucs2strlen((PS8) str),
        guiBuffer);
    g_jam_allowed_sending_abort_from_idle = KAL_FALSE;
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_java_launch_after_install_confirm_yes_hdlr, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_java_launch_after_install_confirm_yes_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_java_launch_after_install_confirm_no_hdlr, KEY_EVENT_UP);
#endif
}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_launch_ask_terminate_cb
 * DESCRIPTION
 *  Callback function to handle
 *  Ask user if they want to terminate VM first before install MIDlet
 * PARAMETERS
 *  teminate    [IN]    user select yes/No
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_launch_after_install_ask_terminate_cb(MMI_BOOL terminate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(terminate)
    {
        /* stop push install before stop_ind received */
        mmi_java_set_allow_push_install(MMI_FALSE);

        g_java.screen_after_terminate = TER_ENTRY_LAUNCH_AFTER_INSTALL;
        jam_enter_terminate_mode(g_mmi_java_current_selected_vm_id);
        g_mmi_java_current_selected_vm_id = -1;
        mmi_java_entry_terminating(MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_launch_after_install_confirm_yes_hdlr
 * DESCRIPTION
 *  Handle Function, revoked when select "YES" to launch after installation.
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_launch_after_install_confirm_yes_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count;
    kal_int32 vm_id = 0;
    extern kal_char g_mmi_java_current_selected_mids_root[];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Resume push install */
    mmi_java_set_allow_push_install(MMI_TRUE);
#if(MAX_VM_INSTANCE_NUM == 1)
    if (jam_mvm_is_vm_running(vm_id))
    {    
            g_mmi_java_current_selected_vm_id = 0;
            mmi_java_entry_cb_terminate_dialog(mmi_java_launch_after_install_ask_terminate_cb, (U16*)GetString(STR_JAVA_TERMINATE_JAVA_GAME),0);
        mmi_frm_scrn_enter(GRP_ID_JAVA_CONFIRM,SCR_JAVA_LAUNCH_AFTER_INSTALL,NULL,mmi_java_launch_after_install_confirm_yes_hdlr,MMI_FRM_FG_ONLY_SCRN);
        return;
    }
#endif /*MAX_VM_INSTANCE_NUM == 1*/
    if (mmi_java_is_in_voice_call())
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL, MMI_EVENT_FAILURE, APP_JAVA, NULL);
        mmi_frm_scrn_close(GRP_ID_JAVA_CONFIRM,SCR_JAVA_LAUNCH_AFTER_INSTALL);
        return;
    }

    needToSendGetListReq = MMI_TRUE;
    g_java.mids_info_end = g_java.mids_info_start = -1;
    g_java.mids_list_filter.filter_type = JAM_NONE_FILTER;
    g_java.total_java_app_mids = g_mmi_java_install_mids_id;
    mmi_java_fetch_mids_list(g_mmi_java_install_mids_id - 1, (UI_string_type) NULL, (PU8*) NULL, 0);
    g_java.mids_index = g_mmi_java_install_mids_id - 1;
    g_java.mid_index = 0;
        
    count = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mid_count;
    app_ucs2_str_to_asc_str((kal_int8 *)(&g_mmi_java_current_selected_mids_root[0]),(const kal_int8 *) (g_java.mids_info[g_java.mids_index - g_java.mids_info_start].storage_name));
    if (count == 1 )
    {
        g_java.mid_info[0].mid_id =1;
    }
    mmi_java_send_mid_getlist_req();
    mmi_java_set_allow_push_install(MMI_TRUE);
}
    
/*****************************************************************************
 * FUNCTION
 *  mmi_java_launch_after_install_confirm_no_hdlr
 * DESCRIPTION
 *  Handle Function, revoked when select "NO" to launch after installation.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_launch_after_install_confirm_no_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_java_set_allow_push_install(MMI_TRUE);
    g_mmi_java_is_launching_midlet = MMI_FALSE;
    mmi_frm_scrn_close_active_id();
}
#endif /*__MMI_JAVA_LAUNCH_AFTER_INSTALL__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_mids_delete_cnf
 * DESCRIPTION
 *  This routines handles MMI_JAVA_MIDS_REMOVE_CNF from MOD_J2ME to
 *  indicate user whether or not delete action is successful
 * PARAMETERS
 *  MsgStruct       [void*]  mmi_java_mids_remove_cnf_struct
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_mids_package_cnf(void *MsgStruct)
{
#if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_package_cnf_struct *msg;
    S32 str_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_java_is_in_package = MMI_FALSE;
    msg = (mmi_java_mids_package_cnf_struct*) MsgStruct;
    if (g_java.msg_ctrl & SEND_MIDS_PACKAGE_CTRL)
    {
        if (!(msg->error_code))
        {
            msg->error_code = USER_CANCEL;
            if (msg->file_path)
            {
                FS_Delete(msg->file_path);
            }
        }
    }

    g_java.msg_ctrl &= (~SEND_MIDS_PACKAGE_CTRL);
    if(msg->error_code)
    {
        switch (msg->error_code)
        {
            case DRM_PROHIBIT:
                mmi_popup_display_simple_ext(STR_GLOBAL_DRM_PROHIBITED, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
                break;
            case USER_CANCEL:
                mmi_popup_display_simple_ext(STR_JAVA_ERROR_CODE_CANCEL, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
                break;
            case UNSUPPORTED_CERT:
                mmi_popup_display_simple_ext(STR_JAVA_ERROR_CODE_VERIFY_FAILED, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
                break;
            case INSUFFICIENT_STORAGE:
                mmi_popup_display_simple_ext(STR_GLOBAL_NOT_ENOUGH_MEMORY, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
                break;
            case ROOT_DIR_FULL:
                mmi_popup_display_simple_ext(FMGR_FS_ROOT_DIR_FULL_TEXT, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
                break;
            default:
                mmi_popup_display_simple_ext(STR_JAVA_ERROR_FAIL_TO_PACKAGE, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);            
        }
    }
    else
    {
        if (g_mmi_java_mids_package_dir_path[0] != '\0')
        {
            /* save as file scenario, doesn't execute send method */
            #if 0
/* under construction !*/
/* under construction !*/
            #endif
            g_mmi_java_mids_package_dir_path[0] = '\0';
            mmi_popup_display_simple_ext(STR_GLOBAL_SAVED, MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);  
        }
        else
        {
            str_len = mmi_ucs2strlen((S8*)msg->file_path);
            if (g_mmi_java_mids_package_file_path)
            {
                free_ctrl_buffer(g_mmi_java_mids_package_file_path);   
                g_mmi_java_mids_package_file_path = NULL;
            }
            
            g_mmi_java_mids_package_file_path = get_ctrl_buffer((str_len+1)<<1);
            memcpy(g_mmi_java_mids_package_file_path,msg->file_path,(str_len+1)<<1);

            if (g_mmi_java_mids_package_menu_index >= g_mmi_java_total_send_item_number)
            {
                g_mmi_java_mids_package_menu_index -= g_mmi_java_total_send_item_number;
            }
            srv_fmgr_types_launch_option((WCHAR*)g_mmi_java_mids_package_file_path, g_mmi_java_mids_package_execute_menu_id);
        }
    }
    if (msg->file_path)
    {
        free_ctrl_buffer(msg->file_path);
    }
    mmi_frm_group_close(GRP_ID_JAVA_PACKAGE);
    mmi_java_set_allow_push_install(MMI_TRUE);
#endif /* #if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__) */    
}   


/*****************************************************************************
 * FUNCTION
 *  mmi_java_highlight_option_select
 * DESCRIPTION
 *  Handle function: revoked when user change selection in "OPTION" menu.
 * PARAMETERS
 *  nIndex      [IN]        Index of selection
 * RETURNS
 *  void
 *****************************************************************************/
/* void mmi_java_get_mid_index(S32 nIndex) */
void mmi_java_highlight_option_select(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_GET_JAVA_APP_MID_INDEX);
    g_java.mid_index = nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_opt_select_ext
 * DESCRIPTION
 *  Show the "OPTION" screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_opt_select_ext(void)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 *MID_Names[MAX_SUB_MENUS];
    U8 *MID_Icon[MAX_SUB_MENUS];
    U8 *guiBuffer;
    U32 count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = g_java.total_java_app_mid;
    for (i = 0; i < count; i++)
    {
        MID_Names[i] = g_java.mid_info[i].mid_name;
        if (g_java.mid_info[i].mid_icon)
        {
            MID_Icon[i] = g_java.mid_info[i].mid_icon;
        }
        else
        {
            MID_Icon[i] = (PU8) GetImage(IMG_JAVA_STAR1);      /* g_java.mid_info[i].mid_icon; */
        }
    }
    if(!mmi_frm_scrn_enter(GRP_ID_JAVA_OPT, SCR_JAVA_APP_OPTION_SELECT, NULL, mmi_java_entry_opt_select_ext ,MMI_FRM_FULL_SCRN))
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_JAVA_OPT, SCR_JAVA_APP_OPTION_SELECT);
    RegisterHighlightHandler(mmi_java_highlight_option_select);

    ShowCategory170Screen(
        (PU8) GetString(STR_GLOBAL_SELECT),
        (PU8) GetImage(mmi_java_get_title_icon()),
        (PU8) GetString(STR_GLOBAL_OK),
        (PU8) GetImage(IMG_GLOBAL_OK),
        (PU8) GetString(STR_GLOBAL_BACK),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        count,
        (U8 **) MID_Names,
        MID_Icon,
        0,
        0,
        guiBuffer);
    mmi_frm_scrn_close(GRP_ID_JAVA_CONFIRM, SCR_JAVA_LAUNCH_AFTER_INSTALL);
    SetLeftSoftkeyFunction(mmi_java_entry_mid_launch, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_java_entry_mid_launch,KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_opt_select
 * DESCRIPTION
 *  Show the "OPTION" screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_opt_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = g_java.total_java_app_mid;
#ifdef __PLUTO_MMI_PACKAGE__
    if(!mmi_frm_group_is_present(GRP_ID_JAVA_OPT))
    {
        if(!mmi_frm_group_is_present(APP_JAVA))
        {
            mmi_frm_group_create_ex(
                GRP_ID_ROOT,
                APP_JAVA,
                mmi_java_sg_proc,
                NULL,
                MMI_FRM_NODE_SMART_CLOSE_FLAG);
        }
        mmi_frm_group_create_ex(
        APP_JAVA,
        GRP_ID_JAVA_OPT,
        mmi_java_opt_sg_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);            
    }
#endif    
    if (count == 0)
    {
        mmi_popup_property_struct arg;
        mmi_popup_property_init(&arg);
        mmi_popup_display_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, &arg);
        mmi_frm_group_close(GRP_ID_JAVA_OPT);        
    }
    else
    {
        #ifdef __PLUTO_MMI_PACKAGE__
        mmi_java_entry_opt_select_ext();
        #elif defined (__COSMOS_MMI_PACKAGE__)
        mmi_frm_cb_dereg_event(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, vapp_java_gpio_event_hdlr, NULL);  
        vapp_java_mid_select_entry();
        #endif
    }
}

#ifdef OGDR_SECURITY_SETTING
/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_set_default_setting_cnf
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_set_default_domain_cnf(void *MsgStruct)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_java_set_default_domain_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg = (mmi_java_set_default_domain_cnf_struct*) MsgStruct;

    if (g_java.msg_ctrl & SEND_SET_DEFAULT_DOMAIN_CTRL )
    {
        if (msg->error_code == J2ME_NO_ERROR)
        {
            mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, GRP_ID_JAVA_SECURITY, NULL);
        }
        else
        {
            mmi_popup_display_simple_ext(STR_GLOBAL_UNFINISHED, MMI_EVENT_FAILURE, GRP_ID_JAVA_SECURITY, NULL);
        }
        /* only get the setting from Java again to update the latest setting value since exclusive setting may automatically
            update other setting value*/
        get_setting_only = MMI_TRUE;
        mmi_java_send_get_default_domain_req(g_java.domain);
        g_java.msg_ctrl &= (~SEND_SET_DEFAULT_DOMAIN_CTRL);
    }
    cui_inline_close(g_java_domain_inline);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_set_default_domain_req
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_set_default_domain_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_set_default_domain_req_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_java.msg_ctrl & SEND_SET_DEFAULT_DOMAIN_CTRL)
    {
        mmi_java_display_is_busy();
    }
    else
    {
        g_java.msg_ctrl |= SEND_SET_DEFAULT_DOMAIN_CTRL;

        msg = (mmi_java_set_default_domain_req_struct*) OslConstructDataPtr(sizeof(mmi_java_set_default_domain_req_struct));
        msg->domain_id = g_java.domain;
        kal_mem_cpy(&(msg->default_setting), &(g_java.mids_setting), sizeof(mmi_setting_struct));

        mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP,
            MSG_ID_MMI_JAVA_SET_DEFAULT_DOMAIN_REQ, msg);
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_get_default_domain_cnf
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_get_default_domain_cnf(void *MsgStruct)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_java_get_default_domain_cnf_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg = (mmi_java_get_default_domain_cnf_struct *) MsgStruct;


    if (msg->error_code == (kal_uint32) J2ME_NO_ERROR)
    {
        kal_mem_cpy(&(g_java.mids_setting), &(msg->default_setting), sizeof(mmi_setting_struct));
        kal_mem_cpy(&(g_java.mids_max_setting), &(msg->max_setting), sizeof(mmi_setting_struct));
    }

    if (!get_setting_only)
    {
        get_domain_setting = MMI_TRUE;
        mmi_java_entry_opt_setting();
    }

    get_setting_only = MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_get_default_domain_req
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_get_default_domain_req(S32 domain)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_get_default_domain_req_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_java_get_default_domain_req_struct*) OslConstructDataPtr(sizeof(mmi_java_get_default_domain_req_struct));
    msg->domain_id = domain;
    mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP,
        MSG_ID_MMI_JAVA_GET_DEFAULT_DOMAIN_REQ, msg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_entry_default_setting
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_entry_default_domain_setting(S32 domain)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    g_java.domain = domain;

    mmi_java_send_get_default_domain_req(domain);
}
#endif /* #ifdef OGDR_SECURITY_SETTING */


/*****************************************************************************
 * FUNCTION
 *  mmi_java_store_setting
 * DESCRIPTION
 *  store java setting back to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_store_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    srv_prof_setting_struct settings;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __PLUTO_MMI_PACKAGE__
    WriteValue(NVRAM_JAVA_SETTING_SOUND, &g_mmi_java_aud_volume_level, DS_BYTE, &error);
    #elif defined(__COSMOS_MMI_PACKAGE__)
        #ifdef __MMI_UNIQUE_MEDIA_VOL__
        srv_prof_get_profile_values(SRV_PROF_PROFILE_2, &settings);
        settings.media_vol = (srv_prof_volume_level)g_mmi_java_aud_volume_level;
        srv_prof_set_profile_values(SRV_PROF_PROFILE_2, &settings);

        srv_prof_get_profile_values(SRV_PROF_PROFILE_1, &settings);
        settings.media_vol = (srv_prof_volume_level)g_mmi_java_aud_volume_level;
        srv_prof_set_profile_values(SRV_PROF_PROFILE_1, &settings);
        #endif
    #endif
    MMI_TRACE(MMI_MEDIA_TRC_STATE, MMI_JAVA_STORE_SETTING, 1, g_mmi_java_aud_volume_level, 0);
    WriteValue(NVRAM_JAVA_SETTING_VIB, &g_mmi_java_is_vib_on, DS_BYTE, &error);
    MMI_TRACE(MMI_MEDIA_TRC_STATE, MMI_JAVA_STORE_SETTING, 2, g_mmi_java_is_vib_on, 0);
#ifdef SUPPORT_JAVA_NET_ICON_SETTING
/* under construction !*/
/* under construction !*/
#endif
#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    WriteValue(NVRAM_JAVA_SETTING_VK, &g_mmi_java_vk_permission, DS_BYTE, &error);
    MMI_TRACE(MMI_MEDIA_TRC_STATE, MMI_JAVA_STORE_SETTING, 4, g_mmi_java_vk_permission, 0);
#endif
    WriteValue(NVRAM_JAVA_SETTING_BKLIGHT_ID, &g_mmi_java_bk_light, DS_BYTE, &error);
#if defined( SUPPORT_JSR_179 ) && defined(__AGPS_SUPPORT__) 
    WriteValue(NVRAM_JAVA_SETTING_LOCATION, &g_mmi_java_location_select,DS_BYTE,&error);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_load_setting
 * DESCRIPTION
 *  load java setting from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __PLUTO_MMI_PACKAGE__
    ReadValue(NVRAM_JAVA_SETTING_SOUND, &g_mmi_java_aud_volume_level, DS_BYTE, &error);
    #elif defined(__COSMOS_MMI_PACKAGE__)
    g_mmi_java_aud_volume_level = MDI_AUD_VOL_GET_EX_LEVEL(srv_prof_get_media_vol());
    #endif
    MMI_TRACE(MMI_MEDIA_TRC_STATE, MMI_JAVA_LOAD_SETTING, 1, g_mmi_java_aud_volume_level, 0);

    /* if not init, init as 4 */
    if (g_mmi_java_aud_volume_level == 0xff)
    {
        g_mmi_java_aud_volume_level = 4;
        WriteValue(NVRAM_JAVA_SETTING_SOUND, &g_mmi_java_aud_volume_level, DS_BYTE, &error);
    }

    ReadValue(NVRAM_JAVA_SETTING_VIB, &g_mmi_java_is_vib_on, DS_BYTE, &error);
    MMI_TRACE(MMI_MEDIA_TRC_STATE, MMI_JAVA_LOAD_SETTING, 2, g_mmi_java_is_vib_on, 0);

    /* if not init, init as ON */
    if (g_mmi_java_is_vib_on == 0xff)
    {
        g_mmi_java_is_vib_on = MMI_TRUE;
        WriteValue(NVRAM_JAVA_SETTING_VIB, &g_mmi_java_is_vib_on, DS_BYTE, &error);
    }

#ifdef SUPPORT_JAVA_NET_ICON_SETTING
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

#ifdef __MMI_FOURWAYS_KEY_DISABLE__
    ReadValue(NVRAM_JAVA_SETTING_VK, &g_mmi_java_vk_permission, DS_BYTE, &error);
    MMI_TRACE(MMI_MEDIA_TRC_STATE, MMI_JAVA_LOAD_SETTING, 4, g_mmi_java_vk_permission, 0);

    /* if not init, init as first wap profile */
    if (g_mmi_java_vk_permission == 0xff)
    {
        g_mmi_java_vk_permission = 0;
        WriteValue(NVRAM_JAVA_SETTING_VK, &g_mmi_java_vk_permission, DS_BYTE, &error);
    }
#endif /* __MMI_FOURWAYS_KEY_DISABLE__ */

    ReadValue(NVRAM_JAVA_SETTING_BKLIGHT_ID, &g_mmi_java_bk_light, DS_BYTE, &error);
    
    if (g_mmi_java_bk_light == 0xff)
    {
        g_mmi_java_bk_light = 0;
        WriteValue(NVRAM_JAVA_SETTING_BKLIGHT_ID, &g_mmi_java_bk_light, DS_BYTE, &error);
    }
#if defined( SUPPORT_JSR_179 ) && defined(__AGPS_SUPPORT__)
    ReadValue(NVRAM_JAVA_SETTING_LOCATION, &g_mmi_java_location_select, DS_BYTE,&error);
    if (g_mmi_java_location_select == 0xff)
    {
        g_mmi_java_location_select = 0;
        WriteValue(NVRAM_JAVA_SETTING_LOCATION, &g_mmi_java_location_select, DS_BYTE, &error);
    }    
#endif
}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_send_restore_factory_mode_req
 * DESCRIPTION
 * send message to JVM task ask them to clean up @java
 * PARAMETERS
 *  javaCBHandler    [IN]   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_send_restore_factory_mode_req(FuncPtr javaCBHandler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sleep_count = 50;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(jam_vm_is_busy())
    {         
        jam_mvm_shutdown_all_req();
        while(jam_vm_is_busy() && sleep_count > 0)
        {
            sleep_count --;
            kal_sleep_task(20);
        }
    }
    g_mmi_java_restore_factory_call_back = javaCBHandler;
#ifdef __J2ME__
    mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP,
        MSG_ID_MMI_JAVA_RESTORE_FACTORY_MODE_REQ, NULL);
#else
    if (g_mmi_java_restore_factory_call_back)
    {
        (*g_mmi_java_restore_factory_call_back)();
        g_mmi_java_restore_factory_call_back = NULL;
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_recv_restore_factory_mode_cnf
 * DESCRIPTION
 *  java already clean @java then call back.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_java_recv_restore_factory_mode_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_java_restore_factory_call_back)
    {
        (*g_mmi_java_restore_factory_call_back)();
        g_mmi_java_restore_factory_call_back = NULL;
    }
}   


/*****************************************************************************
 * FUNCTION
 *  mmi_java_is_launch_from_idle
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  0:  not launch after installation
 *  1:  launch after installation
 *****************************************************************************/
U8 mmi_java_is_launch_from_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_java.is_push;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_jad_packageable
 * DESCRIPTION
 *  This function is call by fileMgr to determine a JAD can be package as midlet
 *  message.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL mmi_java_jad_packageable(S8* jad_file_path)
{
#if defined(__DRM_SUPPORT__) && defined(__MMI_JAVA_PACKAGE_MIDS__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* jar_file_path = NULL;
    S32 len;
    kal_int32 error_code = J2ME_NO_ERROR; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jam_set_get_jar_url_check_exist(KAL_TRUE);
    jar_file_path = get_jar_url((kal_wchar*)jad_file_path,&error_code); /* the return memory is ctrl buffer */
    if(error_code!= J2ME_NO_ERROR)
    {    
        return MMI_FALSE;
    }
    len = mmi_ucs2strlen((const S8*)jad_file_path);
    if (jar_file_path == NULL)
    {  
        jar_file_path = get_ctrl_buffer((len + 1) << 1);
        mmi_ucs2cpy((S8*)jar_file_path, (S8*)jad_file_path);
        jar_file_path[len - 1] = 'r';
    }

    if (jar_file_path)
    {
        if (DRM_is_drm_file(NULL, (kal_wchar*)jar_file_path) && DRM_interdev_movable(NULL, (kal_wchar*)jar_file_path))
        {
            free_ctrl_buffer(jar_file_path);
            return MMI_TRUE;
        }
        free_ctrl_buffer(jar_file_path);
    }
#endif
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_jad_option_enabler
 * DESCRIPTION
 *  This function is call by fileMgr to determine a JAD can be package as midlet
 *  message.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_java_jad_option_enabler(mmi_menu_id  item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct * fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8* file_path;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (mmi_java_jad_packageable((S8*)filepath))
    {
    #ifdef __PLUTO_MMI_PACKAGE__
        mmi_frm_hide_menu_item(MENU_ID_FMGR_GEN_OPTION_FORWARD_SEND);
    }
    else
    {
        mmi_frm_hide_menu_item(MENU_ID_FMGR_JAVA_OPTION_PACKAGE);
#endif
    }

}
/*****************************************************************************
 * FUNCTION
 *  mmi_java_clean_list_related_screen_when_install
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
U8 mmi_java_clean_list_related_screen_when_install(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Screen which will get list after press OK */
    /* They should be deleted because the list should be updated after install */
    mmi_frm_group_close(GRP_ID_JAVA_TERMINATE_CB);
    mmi_frm_group_close(GRP_ID_JAVA_TASK_SWITCH);

    /* Screen which use g_java.mids_info or global variables taht will be changed by install process */
    /* They should be deleted because the list should be updated after install */ 
    mmi_frm_scrn_set_leave_proc(APP_JAVA, SCR_JAVA, NULL);
    mmi_frm_group_close(APP_JAVA);
    
    mmi_frm_group_close(GRP_ID_JAVA_SETTING);  
    g_java.mids_info_start = -1;
    g_java.mids_info_end = -1;
    return MMI_TRUE;
}

/*****************************************************************************
 *  java category start
 *****************************************************************************/

#ifdef __MMI_JAVA_CATEGORY_SUPPORT__
mmi_java_filter_hdlr mmi_java_category_set_filter_hdlr;
extern void mmi_java_catagory_entry_list_screen(void);
extern void mmi_java_catagory_execute_pre_entry_function(void);
MMI_BOOL g_mmi_java_is_delete_by_self = MMI_FALSE;

/*****************************************************************************
 * FUNCTION
 *  mmi_java_catagory_cur_list_type
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
jam_category_type_enum  mmi_java_catagory_cur_list_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8)g_java.mids_list_filter.category_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_category_gplus_filter_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
void mmi_java_category_gplus_filter_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_java.mids_list_filter.filter_type = JAM_CATEGORY_FILTER;
    g_java.mids_list_filter.category_type = JAM_CATEGORY_OP01_GPLUS;
    mmi_java_catagory_execute_pre_entry_function();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_category_magicbox_filter_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
void mmi_java_category_magicbox_filter_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_java.mids_list_filter.filter_type = JAM_CATEGORY_FILTER;
    g_java.mids_list_filter.category_type = JAM_CATEGORY_OP01_MAGICBOX;
    mmi_java_catagory_execute_pre_entry_function();

}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_category_set_filter_magicbox
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
void mmi_java_category_set_filter_magicbox(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_java.mids_list_filter.filter_type = JAM_CATEGORY_FILTER;
    g_java.mids_list_filter.category_type = JAM_CATEGORY_OP01_MAGICBOX;

}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_java_category_list_screen_deleteCB
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 mmi_java_category_list_screen_deleteCB(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!g_mmi_java_is_delete_by_self)
        g_java.mids_list_filter.category_type = JAM_CATEGORY_OP01_MAGICBOX;  
    g_mmi_java_is_delete_by_self = MMI_FALSE;  
    return MMI_FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_java_catagory_execute_pre_entry_function
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
void mmi_java_catagory_execute_pre_entry_function(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scrn_node_struct node_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_mmi_java_is_delete_by_self = MMI_TRUE;
    
   if( !mmi_frm_scrn_is_present(APP_JAVA,SCR_JAVA_CATEGORY_SCREEN,MMI_FRM_NODE_ALL_FLAG))
    {
         jam_set_category_op01_hilighlight_index(0, g_java.mids_list_filter.filter_type, g_java.mids_list_filter.category_type);
    }
   /*
    mmi_frm_scrn_get_info(APP_JAVA,SCR_JAVA_CATEGORY_SCREEN,&node_info);
    if (node_info.state != MMI_FRM_SCREEN_BACKWARD)
    {    
        if (GetActiveScreenId() == SCR_JAVA_CATEGORY_SCREEN)
            GoBackHistory();
        else
            DeleteScreenIfPresent(SCR_JAVA_CATEGORY_SCREEN);    
    }
    */
    g_mmi_java_is_delete_by_self = MMI_FALSE; /*MAUI_01911410*/
    mmi_java_catagory_entry_list_screen();
}


void mmi_java_catagory_entry_list_screen_int(void);
/*****************************************************************************
 * FUNCTION
 *  mmi_java_catagory_entry_list_screen
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
void mmi_java_catagory_entry_list_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MAX_VM_INSTANCE_NUM == 1)
#if defined(J2ME_SUPPORT_PAUSE) || defined(J2ME_SUPPORT_BACKGROUND)
    if (jam_mvm_is_vm_running(0))
    {
        g_mmi_java_current_selected_vm_id = 0;
#if (MAX_VM_INSTANCE_NUM > 1) /* 20110223,SUPPORT_JAVA_SHARE_MED */
        mmi_java_entry_resume_dialog(GRP_ID_ROOT);
#endif /* MAX_VM_INSTANCE_NUM > 1 */
        return;
    }
#endif
    if (mmi_java_check_and_display_is_busy())
    {
        return;
    }
#endif /*MAX_VM_INSTANCE_NUM == 1*/
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        APP_JAVA,
        mmi_java_sg_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_java_catagory_entry_list_screen_int();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_java_catagory_entry_list_screen
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
void mmi_java_catagory_entry_list_screen_int(void)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count;
    U8 *guiBuffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_java.mids_info_end = g_java.mids_info_start = -1;

    /* get list at the very beginning */
    needToSendGetListReq = MMI_TRUE;
    mmi_java_fetch_mids_list(0, (UI_string_type) NULL, (PU8*) NULL, 0);
    count = g_java.total_java_app_mids;

#ifdef __MMI_MY_FAVORITE_JAVA_HYPERLINK__

    count += mmi_my_favorite_javabox_waplink_count();
    if (count == 0)
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, APP_JAVA, NULL);
    }
    else if(mmi_java_resume_pending_flag)
        {
            mmi_java_display_is_busy();
        }
    else
    {
        guiBuffer = mmi_frm_scrn_get_gui_buf(APP_JAVA,SCR_JAVA);
        if(!mmi_frm_scrn_enter(
            APP_JAVA,
            SCR_JAVA_CATEGORY_SCREEN,
            NULL,
            mmi_java_catagory_entry_list_screen_int,
            MMI_FRM_FULL_SCRN))
            {
                return;
            }

        RegisterHighlightHandler(mmi_my_favorite_javabox_highlight_hdlr);
        if (g_java.total_java_app_mids > JAVA_LIST_CACHE_COUNT)
        {
            #ifdef __MMI_MY_FAVORITE_JAVABOX__        
            ShowCategory185Screen(
                mmi_my_favorite_get_java_title_string(),
                mmi_java_get_title_icon(),
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                count,
                (GetItemFuncPtr) mmi_my_favorite_javabox_get_item_callback,
                NULL,
                jam_get_category_op01_hilighlight_index(g_java.mids_list_filter.filter_type, g_java.mids_list_filter.category_type),
                MMI_TRUE,
                flushListCache,
                guiBuffer);
            #else
            ShowCategory185Screen(
                STR_SCR_JAVA_CAPTION,
                mmi_java_get_title_icon(),
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                count,
                (GetItemFuncPtr) mmi_my_favorite_javabox_get_item_callback,
                NULL,
                jam_get_category_op01_hilighlight_index(g_java.mids_list_filter.filter_type, g_java.mids_list_filter.category_type),
                MMI_TRUE,
                flushListCache,
                guiBuffer);     
            #endif
        }
        else
        {
            needToSendGetListReq = MMI_FALSE;
            #ifdef __MMI_MY_FAVORITE_JAVABOX__            
            wgui_cat1032_show(
                (WCHAR*) GetString(mmi_my_favorite_get_java_title_string()),
                (PU8) GetImage(mmi_java_get_title_icon()),
                (WCHAR*) GetString(STR_GLOBAL_OPTIONS),
                (PU8) GetImage(IMG_GLOBAL_OPTIONS),
                (WCHAR*) GetString(STR_GLOBAL_BACK),
                (PU8) GetImage(IMG_GLOBAL_BACK),
                count,
                (GetAsyncItemFuncPtr)mmi_my_favorite_javabox_get_item_callback_async,
                NULL,
                jam_get_category_op01_hilighlight_index(g_java.mids_list_filter.filter_type, g_java.mids_list_filter.category_type),
                0,    
                IMG_GLOBAL_L1,
                0,
                guiBuffer,
                NULL);      
            #else
            wgui_cat1032_show(
                (WCHAR*) GetString(STR_SCR_JAVA_CAPTION),
                (PU8) GetImage(mmi_java_get_title_icon()),
                (WCHAR*) GetString(STR_GLOBAL_OPTIONS),
                (PU8) GetImage(IMG_GLOBAL_OPTIONS),
                (WCHAR*) GetString(STR_GLOBAL_BACK),
                (PU8) GetImage(IMG_GLOBAL_BACK),
                count,
                (GetAsyncItemFuncPtr)mmi_my_favorite_javabox_get_item_callback_async,
                NULL,
                jam_get_category_op01_hilighlight_index(g_java.mids_list_filter.filter_type, g_java.mids_list_filter.category_type),
                0,    
                IMG_GLOBAL_L1,
                0,
                guiBuffer,
                NULL);   
            #endif
        }
        #ifdef __MMI_FTE_SUPPORT__
        wgui_register_tap_callback(mmi_java_mids_tap_callback_funtion);
        #endif
        SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetRightSoftkeyFunction(mmi_my_favorite_back_to_main, KEY_EVENT_UP);
    }
#else

    if (count == 0)
    {
        do {
    mmi_popup_property_struct arg;
    mmi_popup_property_init(&arg);
    arg.parent_id = APP_JAVA;
    if (MMI_EVENT_FAILURE & MMI_POPUP_DISABLE_SLIDING_EFFECT)
        arg.f_sliding_effect = MMI_FALSE;
    if (MMI_EVENT_FAILURE & MMI_POPUP_DISABLE_SHOW_ICON)
        arg.f_msg_icon = MMI_FALSE;
    mmi_popup_display_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, &arg);
    } while(0);
    }else if(mmi_java_resume_pending_flag)
        {
            mmi_java_display_is_busy();
    }
    else
    {

        guiBuffer = mmi_frm_scrn_get_gui_buf(APP_JAVA,SCR_JAVA);
        if(!mmi_frm_scrn_enter(
            APP_JAVA,
            SCR_JAVA_CATEGORY_SCREEN,
            NULL,
            mmi_java_catagory_entry_list_screen_int,
            MMI_FRM_FULL_SCRN))
            {
                return;
            }

        RegisterHighlightHandler(mmi_java_highlight_get_mids_index);

        if (g_java.total_java_app_mids > JAVA_LIST_CACHE_COUNT)
        {
            ShowCategory185Screen(
                STR_SCR_JAVA_CAPTION,
                mmi_java_get_title_icon(),
                STR_GLOBAL_OPTIONS,
                IMG_GLOBAL_OPTIONS,
                STR_GLOBAL_BACK,
                IMG_GLOBAL_BACK,
                count,
                (GetItemFuncPtr) mmi_java_fetch_mids_list,
                NULL,
                 jam_get_category_op01_hilighlight_index(g_java.mids_list_filter.filter_type, g_java.mids_list_filter.category_type),
                MMI_TRUE,
                flushListCache,
                guiBuffer);
        }
        else
        {
            needToSendGetListReq = MMI_FALSE;
            wgui_cat1032_show(
                (WCHAR*) GetString(STR_SCR_JAVA_CAPTION),
                (PU8) GetImage(mmi_java_get_title_icon()),
                (WCHAR*) GetString(STR_GLOBAL_OPTIONS),
                (PU8) GetImage(IMG_GLOBAL_OPTIONS),                
                (WCHAR*) GetString(STR_GLOBAL_BACK),
                (PU8) GetImage(IMG_GLOBAL_BACK),
                count,
                (GetAsyncItemFuncPtr)mmi_java_get_list_data_async,
                NULL,
                jam_get_category_op01_hilighlight_index(g_java.mids_list_filter.filter_type, g_java.mids_list_filter.category_type),
                0,    
                IMG_GLOBAL_L1,
                0,
                guiBuffer,
                NULL);            
        }
        #ifdef __MMI_FTE_SUPPORT__
        wgui_register_tap_callback(mmi_java_mids_tap_callback_funtion);
        #endif
        SetLeftSoftkeyFunction(mmi_java_entry_opt, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(mmi_java_send_mid_getlist_req,KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);    
    }
#endif

    mmi_java_load_setting();
#endif
}

#endif
/*****************************************************************************
 *  java category end
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_java_is_allow_stopped_popup_display
 * DESCRIPTION
 *  Mask java application stopped popup for other App
 * PARAMETERS
 *  [true] popup will be displayed
 *  [false] popup will not be displayed
 * RETURNS
 *
 *****************************************************************************/
void mmi_java_is_allow_stopped_popup_display(MMI_BOOL para)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_java_allow_stopped_popup_display = para;
}

void mmi_java_network_detect_req_hdlr(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     jam_is_network_usable_struct* req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (jam_is_network_usable_struct*)MsgStruct;
    *(req->is_useable) = (kal_bool)(!mmi_java_is_no_network_service());
    kal_set_eg_events(g_java_event_group_2, JAVA_EG_NW_USEABLE, KAL_OR);
}

mmi_ret mmi_java_fmgr_java_notify_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_format_event_struct * adv_action = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(param->evt_id)
    {
    case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
    adv_action = (srv_fmgr_notification_format_event_struct*)param;
    if(!jam_is_allow_format(adv_action->drv_letter))
        return MMI_RET_ERR;
    }
    return MMI_RET_OK;
}


mmi_ret mmi_java_fmgr_card_plug_out_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_java.mids_list_filter.filter_type == JAM_DISK_FILTER &&
        g_java.mids_list_filter.disk_name == SRV_FMGR_CARD_DRV)
    mmi_frm_group_close(APP_JAVA);
    return MMI_RET_OK;
}


mmi_running_mid * g_mmi_java_running_mid_list = NULL;
kal_int32 running_index=0;
kal_int32 running_count = 0;
#if (MAX_VM_INSTANCE_NUM > 1)
kal_wchar * g_mmi_java_running_mid_name[MAX_VM_INSTANCE_NUM] = { NULL};
mmi_java_get_running_mids_req_struct * running_list_ptr = NULL;
void  mmi_java_get_running_list_scr_exit(void)
{
    kal_int32 idx = 0;
    kal_trace(JAM_JAVAAGENCY_GROUP, MMI_JAVA_GET_RUNNING_LIST_SCR_EXIT);
    for(idx = 0;idx < MAX_VM_INSTANCE_NUM; idx++)
        {
            if(g_mmi_java_running_mid_name[idx] != NULL)
            {
                free_ctrl_buffer(g_mmi_java_running_mid_name[idx]);
                g_mmi_java_running_mid_name[idx] = NULL;
            }
        }
    if(g_mmi_java_running_mid_list != NULL)
    {
        free_ctrl_buffer(g_mmi_java_running_mid_list);
        g_mmi_java_running_mid_list = NULL;
    }
    running_list_ptr = NULL;
    running_count = 0;
}
void mmi_java_running_list_lsk_hdlr(void)
{
#if defined(J2ME_SUPPORT_PAUSE) || defined(J2ME_SUPPORT_BACKGROUND)	
   g_mmi_java_current_selected_vm_id = g_mmi_java_running_mid_list[running_index].vm_id;
   mmi_java_entry_resume_dialog(GRP_ID_JAVA_TASK_MANAGER);
#endif   
}

void mmi_java_running_list_highlight_hdlr(S32 index)
{
    running_index = index;
    if (running_count > 0 && !jam_mvm_is_shutdowning() &&
        jam_mvm_midlet_is_bg_running_by_vm_id(g_mmi_java_running_mid_list[running_index].vm_id))
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS,0);
        SetLeftSoftkeyFunction(mmi_java_running_list_lsk_hdlr, KEY_EVENT_UP);  
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_java_running_list_lsk_hdlr,KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
        ClearKeyHandler(KEY_LSK, KEY_EVENT_UP);
        ChangeCenterSoftkey(0, 0);
        ClearKeyHandler(KEY_CSK, KEY_EVENT_UP);  
        SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
        SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_UP);
    }
}


  /*****************************************************************************
  * FUNCTION
  *  mmi_java_mvm_send_get_running_list_req
  * DESCRIPTION
  *
  * PARAMETERS
  *  void
  * RETURNS
  *
  *****************************************************************************/
 void mmi_java_mvm_send_get_running_list_req(void)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/

    // MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_GET_RUNNING_LIST);
     running_list_ptr = (mmi_java_get_running_mids_req_struct*) OslConstructDataPtr(sizeof(mmi_java_get_running_mids_req_struct));
     running_list_ptr->running_mid_list = &g_mmi_java_running_mid_list;
     running_list_ptr->count = &running_count; 
     mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP,
         MSG_ID_MMI_JAVA_GET_RUNNING_MIDS_LIST_REQ, running_list_ptr);
}
mmi_ret mmi_java_task_mgr_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_group_event_struct * g_evt  = (mmi_group_event_struct * )evt;
    cui_menu_event_struct *menu_evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT: // framework de-init the group
            mmi_java_get_running_list_scr_exit();
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}
void mmi_java_mvm_entry_java_task_mgr_ext(void)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index = 0;
    U8 *guiBuffer = NULL;
    S32 nNumofItem = 0; /* Stores no of children in the submenu */
    U8* icons[MAX_VM_INSTANCE_NUM] ={ NULL };
    kal_uint32 event_group;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!mmi_frm_scrn_enter(GRP_ID_JAVA_TASK_MANAGER, SCR_JAVA_RUNTIME_LIST, mmi_java_get_running_list_scr_exit,mmi_java_mvm_entry_java_task_mgr_ext, MMI_FRM_FULL_SCRN))
        return;
    mmi_java_get_running_list_scr_exit();
    mmi_java_mvm_send_get_running_list_req();
    kal_retrieve_eg_events(g_java_event_group_2, JAVA_EG_GET_RUNNING_LIST, KAL_OR_CONSUME, (kal_uint32*)&event_group, KAL_SUSPEND);    
    for(index = 0; index < running_count; index++)
    {
        g_mmi_java_running_mid_name[index] = g_mmi_java_running_mid_list[index].mid_name;
        icons[index] = (U8*) GetImage(IMG_ID_JAVA_PLAY);
    }
    guiBuffer =  mmi_frm_scrn_get_gui_buf(GRP_ID_JAVA_TASK_MANAGER, SCR_JAVA_RUNTIME_LIST);
    nNumofItem = running_count;
    kal_trace(JAM_JAVAAGENCY_GROUP,MMI_JAVA_MVM_ENTRY_JAVA_TASK_MGR_EXT,nNumofItem);
    RegisterHighlightHandler(mmi_java_running_list_highlight_hdlr);
    ShowCategory170Screen(
        (PU8) GetString(STR_ID_FNG_JAVA_TASK_MANAGER),
        (PU8) GetImage(mmi_java_get_title_icon()),
        (PU8) NULL,
        (PU8) NULL, 
        (PU8) GetString(STR_GLOBAL_BACK),
        (PU8) GetImage(IMG_GLOBAL_BACK),
        nNumofItem,
        (U8 **) g_mmi_java_running_mid_name,
        icons,
        0,
        0,
        guiBuffer);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_LEFT_ARROW, KEY_EVENT_UP);
#endif
}
 /*****************************************************************************
 * FUNCTION
 *  mmi_java_mvm_entry_java_task_mgr
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
 void mmi_java_mvm_entry_java_task_mgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 event_group;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jam_is_busy())
    {
        mmi_java_display_is_busy();
        return;
    }
    #ifdef __PLUTO_MMI_PACKAGE__
    mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_JAVA_TASK_MANAGER,
        mmi_java_task_mgr_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    mmi_java_mvm_entry_java_task_mgr_ext();
    #elif defined(__COSMOS_MMI_PACKAGE__)
    mmi_java_mvm_send_get_running_list_req();
    kal_retrieve_eg_events(g_java_event_group_2, JAVA_EG_GET_RUNNING_LIST, KAL_OR_CONSUME, (kal_uint32*)&event_group, KAL_SUSPEND);
    vapp_java_task_manager_entry(KAL_FALSE);
    #endif
}    
#endif /*(MAX_VM_INSTANCE_NUM > 1)*/

#ifdef SUPPORT_JSR_179
/*****************************************************************************
 * FUNCTION
 *  mmi_java_location_set_agps_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
void mmi_java_location_set_agps_rsp(int handle, int result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jloc_gps_set_agps_rsp_struct *p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = (jloc_gps_set_agps_rsp_struct*) construct_local_para(sizeof(jloc_gps_set_agps_rsp_struct),TD_CTRL);
    p->handle = handle;
    p->result= result;
    mmi_java_send_message_from_active_mod(MOD_JASYN, MMI_J2ME_SAP,
        MSG_ID_MMI_JAVA_SET_AGPS_RSP, p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_java_location_set_agps_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *
 *****************************************************************************/
void mmi_java_location_set_agps_req(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    jloc_gps_set_agps_req_struct *p = (jloc_gps_set_agps_req_struct*)MsgStruct;
    int ret = -1;
    int handle = p->handle;
#if defined (__AGPS_SUPPORT__) && defined (__SUPL_SUPPORT__)
    supl_mmi_qop_struct qop;
#endif
#if defined(__AGPS_CONTROL_PLANE__)
    mmi_ss_molr_begin_req_struct molr_info;
#endif /* __AGPS_CONTROL_PLANE__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p->op_type == 0)
    {
#if defined(__AGPS_CONTROL_PLANE__)
        if (p->agps_type == JLOC_GPS_USAGE_AGPS_CONTROL_PLANE)
        {
            memset(&molr_info, 0, sizeof(mmi_ss_molr_begin_req_struct));
            
            molr_info.molr.validity = L4C_SS_LCS_MOLRArg_locationMethod_valid | L4C_SS_LCS_MOLRArg_lcs_QoS_valid;
            molr_info.molr.molr_Type = L4C_SS_MOLR_Type_locationEstimate;
            molr_info.molr.locationMethod = L4C_SS_LocationMethod_msBasedEOTD;
            molr_info.molr.lcs_QoS.validity = L4C_SS_LCS_QoS_horizontal_accuracy_valid | 
                                              L4C_SS_LCS_QoS_verticalCoordinateRequest_valid |
                                              L4C_SS_LCS_QoS_vertical_accuracy_valid |
                                              L4C_SS_LCS_QoS_responseTime_valid;
            molr_info.molr.lcs_QoS.horizontal_accuracy.numOctets = 1;
            molr_info.molr.lcs_QoS.horizontal_accuracy.stringData[0] = 73;
            molr_info.molr.lcs_QoS.verticalCoordinateRequest = 1;
            molr_info.molr.lcs_QoS.vertical_accuracy.numOctets = 1;
            molr_info.molr.lcs_QoS.vertical_accuracy.stringData[0] = 73;
            molr_info.molr.lcs_QoS.responseTime.responseTimeCategory = L4C_SS_ResponseTimeCategory_delaytolerant;
            
            ret = (int)mmi_gps_mgr_start_molr(&molr_info, 
                                            (mdi_gps_uart_work_mode_enum)p->mode, 
                                            (U16*)&handle, 
                                            p->update_callback);
        }
#endif    /* __AGPS_CONTROL_PLANE__ */

#if defined(__AGPS_USER_PLANE__)
        if (p->agps_type == JLOC_GPS_USAGE_AGPS_USER_PLANE && ret < 0)
        {
            qop.horacc = 73;
            qop.veracc_used = MMI_TRUE;
            qop.veracc = 73;
            qop.maxLocAge_used = MMI_FALSE;
            qop.delay_used = MMI_FALSE;

            ret = (int)mmi_gps_mgr_open_gps((U16)handle,
                                             (mdi_gps_uart_work_mode_enum)p->mode,
                                             MMI_GPS_WORK_MODE_MB,
                                             &qop,
                                             p->update_callback);
        }
#endif /* __AGPS_USER_PLANE__ */
    }
    else 
    {
#if defined(__AGPS_CONTROL_PLANE__)
        if (p->agps_type== JLOC_GPS_USAGE_AGPS_CONTROL_PLANE)
        {
            ret = (int)mmi_gps_mgr_stop_molr((U16)handle);

        }
#endif /* __AGPS_CONTROL_PLANE__ */

#if defined(__AGPS_USER_PLANE__)
        if (p->agps_type == JLOC_GPS_USAGE_AGPS_USER_PLANE && ret < 0)
        {
            ret = (int)mmi_gps_mgr_close_gps((U16)handle, (mdi_gps_uart_work_mode_enum)p->mode, p->update_callback);
        }
#endif /* __AGPS_USER_PLANE__ */
    }

    mmi_java_location_set_agps_rsp(handle, ret);
}
#endif /* SUPPORT_JSR_179 */

MMI_BOOL mmi_java_is_sim_card_avaiable(void)
{
    return (MMI_BOOL)(
        (srv_sim_ctrl_is_available(MMI_SIM1)) 
#if (MMI_MAX_SIM_NUM >= 2)
        || (srv_sim_ctrl_is_available(MMI_SIM2))
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        ||(srv_sim_ctrl_is_available(MMI_SIM3))
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        ||(srv_sim_ctrl_is_available(MMI_SIM4))
#endif 
        ); 
}


#ifdef __COSMOS_MMI_PACKAGE__
void mmi_java_close_MIDlet_screen(void)
{
    mmi_frm_group_close(GRP_ID_JAVA_APP);
}
#endif
#else /* __J2ME__ */
#ifdef __MTK_TARGET__
#include "MMI_features.h"
#include "kal_release.h"
#include "StdC.h"


/*****************************************************************************
 * FUNCTION
 *  jvm_is_busy
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_bool jam_vm_is_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_FALSE;
}
#endif /* __MTK_TARGET__ */
#endif /* __J2ME__ */

