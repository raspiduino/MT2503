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
 *   med_struct.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary global variables of media task.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _MED_STRUCT_H
#define _MED_STRUCT_H

/*==== DEFINES ========*/
#include "cal_comm_def.h"
#include "fd_comm_def.h"
#include "autocap_comm_def.h"
#include "kal_general_types.h"
#include "app_ltlcom.h"
#include "aud_defs.h"
#include "mpl_player.h" // mpl player interface definition
#include "mpl_recorder.h"
#include "pano_comm_def.h" // panorama spec
#include "med_aud_hal_struct.h"
#include "nvram_default_audio.h"
#ifdef __VIDEO_SUBTITLE_SUPPORT__
#include "subtitlefont_if.h"
#endif /* __MMI_VIDEO_SUBTITLE_SUPPORT__ */ 

#ifdef __VOICE_CHANGER_SUPPORT__
#include "l1audio.h"
#endif

#define MAX_CAM_FD_NO (CAMERA_FD_MAX_NO)

#define MAX_MELODY_FILE_NAME 50

/* define for kal_wchar */
#define ENCODE_BYTE   (2)

#define MAX_VM_FILE_NAME 20
#define MAX_NUM_OF_VM_LIST 20

#define MAX_MEDIA_FILE_PATH_LEN 260 /* 260 wchar, need to add 1 null terminator */

#ifndef __VR_MED_CONST__
#define __VR_MED_CONST__
#define VR_SD_MAX_GROUP_TAG_NUM 20
#define VR_SD_MAX_GROUP_NUM 4
#define VR_MAX_RCG_RESULT_NUM 10
#define VR_MAX_DB_PATH_LEN 80
#define VR_MAX_ADD_ONCE_NUM 20
#endif /* __VR_MED_CONST__ */

#ifndef __BT_MED_CONST__
#define __BT_MED_CONST__
#define BT_HFP 0
#define BT_A2DP 1
#define BT_HF 2

#define BT_A2DP_AGGRESSIVE_MODE 0
#define BT_A2DP_PASSIVE_MODE 1
#define BT_A2DP_PTS_PASSIVE_MODE 2

#define BT_HFP_EARPHONE_MODE 0
#define BT_HFP_CARKIT_MODE 1
#endif /* __BT_MED_CONST__ */

#ifndef __CTM_MED_CONST__
#define __CTM_MED_CONST__
#define CTM_SEND_TEXT_CHAR_MAX_NUM 20
#define CTM_MAX_SEND_REQ_NUM 10
typedef struct
{
    kal_int16 cprm_tone_demod_down_samp;    /* 1 (0, 1) */
    kal_uint8 input_vol;
    kal_uint8 output_vol;
} ctm_param_struct;
#endif /* __CTM_MED_CONST__ */

#define VID_MJPG_ACCURATE_TIME_SHIFT    (10)  /* shift 10 bit for accuracy */

#define MEDIA_CAM_AF_ZONE_MAX_NO (AF_ZONE_NO)

#define AUD_TTS_MAX_PROCESS_DATA_SIZE 30      /* This size shall be larger than TTS_PROCESS_DATA.*/

typedef enum
{
    MED_MTV_IMD_TYPE_SERVICE,
    MED_MTV_IMD_TYPE_CONTENT
} media_mtv_imd_type_enum;

#define VID_MAX_VIDEO_TRACK_NUM (3)
#define VID_MAX_VIDEO_SUBTITLE_NUM (MPL_SESSION_MAX_SUBTITLE_TRACK_NUM)

/*==== MESSAGE STRUCTS ==========*/


/**
  * ATV video mode.
  */
typedef enum
{
    ATV_VIDEO_NTSC,
    ATV_VIDEO_PAL
} media_mtv_atv_video_mode_enum;

typedef struct
{
    kal_uint8 play_audio;
    kal_uint8 audio_path;
    kal_uint32 audio_mode;          /**< for ATV audio mode. */
} media_config_audio_struct;

typedef struct
{
    void *image_buffer_p;           /**< assume the dimension of GDI layer is the same as LCD screen. */
    void *image_buffer2_p;
    kal_uint32 image_buffer_size;   /**< currently unused. must be 0. */

    kal_uint16 display_width;       /**< width of video */
    kal_uint16 display_height;      /**< height of video */

    kal_uint8 display_device;       /**< must be MED_DISPLAY_TO_MAIN_LCD */

    kal_uint8 lcd_id;               /**< must be MAIN_LCD */

    kal_uint32 update_layer;        /**< where the video should be drawed to */
    kal_uint32 hw_update_layer;     /**< the layers to show on LCD (inculding video, OSD, or others) */

    kal_bool force_lcd_hw_trigger;

    kal_bool visible;
    kal_uint32 brightness;
    kal_uint32 contrast;
    kal_uint32 gamma;
    kal_uint32 saturation;

    kal_int16 play_speed;           /**< 100 for 1X speed */
    kal_uint16 repeats;             /**< repeat count, 0xffff: infinite */

    kal_uint8 image_data_format;            /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    med_frame_enum frame_mode;

    /* Analog TV */
    kal_uint16 image_width;                 /* dest image width for mpeg4 encoder */
    kal_uint16 image_height;                /* dest image height for mpeg4 encoder */
    media_mtv_atv_video_mode_enum video_mode;   /* PAL or NTSC */
    mpl_recorder_format_enum_t encode_format;
    mpl_recorder_quality_enum_t encode_quality; //video_config->encode_quality;
    mpl_recorder_storage_enum_t storage; //video_config->storage;

    kal_int16 idp_rotate;           /**< IDP rotation */
    /* DDV2 */
    kal_uint32 layer_element;
    kal_uint32 blt_ctx;
    kal_uint32 blt_dev;

} media_config_video_struct;

typedef struct
{
    kal_uint8 bdscell_id[17];
    kal_bool is_usim;
    kal_char imsi[16];
    kal_bool same_imsi;
    kal_uint16 sim_id;
} media_mtv_cas_sim_struct;

typedef struct
{
    kal_uint32  net_id;         /* data account id */
    kal_uint8   prx_ip[63];        /* proxy ip */
    kal_uint8   use_proxy;
    kal_uint16  prx_port;       /* proxy port */
    kal_uint8   app_id;         /* app id */
    kal_char sg_url[30];
    kal_uint16 sg_port;
} media_mtv_cas_net_struct;


typedef struct
{
    kal_uint32 flag;
} media_mtv_service_ca_struct;


#define MEDIA_MTV_MAX_APPEND_LEN     (250 + 1)

typedef struct
{
    kal_uint32 emm_len;
    kal_uint8* emm_data;
} media_mtv_emm_info_struct;

typedef struct
{
    kal_uint32  block_len;
    kal_uint32* block_data;
} media_mtv_ca_info_struct;


typedef struct
{
    kal_uint8  net_mode;
    kal_uint16 area_code;
} media_mtv_nit_area_struct;

typedef struct
{
    kal_uint16 nYear;
    kal_uint8  nMonth;
    kal_uint8  nDay;
    kal_uint8  nHour;
    kal_uint8  nMin;
    kal_uint8  nSec;
    kal_uint8  week;
} media_mtv_nit_time_struct;

typedef struct
{
    kal_int32 desc_len;
    kal_wchar *desc;
} media_mtv_subscribe_update_desc_struct;


typedef struct
{
    kal_uint32 count;
    kal_uint32 unread_count;
    kal_uint32 first_unread_idx;
} media_mtv_imd_count_struct;

typedef struct
{
    /* Input */
    kal_int32 imd_index;
    kal_int32 desc_len; /* UCS2 len, not include null termination */

    /* Output */
    kal_bool *if_read;
    kal_wchar *desc;    
} media_mtv_imd_desc_struct;

typedef struct
{
    /* Input */
    kal_int32 imd_type;
    kal_int32 path_len; /* UCS2 len, not include null termination */
    
    kal_int32 imd_index;    
    kal_char *cid;
    
    /* Output */
    kal_wchar *path;    
} media_mtv_imd_detail_struct;

typedef struct
{
    kal_char *id;
    kal_char *gid;
} media_mtv_purchase_id_struct;

typedef struct
{
    kal_char *rid;
    void* value;
} media_mtv_esg_update_struct;

typedef struct
{
    kal_uint32 order_num;
} media_mtv_order_list_struct;

/* audio */

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
l4aud_get_audio_mode_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 mode;
}
l4aud_get_audio_mode_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 voltage;
}
l4audio_batt_voltage_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool is_battery_low;
}
l4audio_batt_state_ind_struct;

#ifdef __CLASSK_CP_SUPPORT__

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool classk_state;
}
l4audio_classk_state_ind_struct;
#endif /* __CLASSK_CP_SUPPORT__*/


/*This structure is the subset of audio_param_struct, used to put in global context */
typedef struct
{
    kal_int16 speech_input_FIR_coeffs[6][SPEECH_FIR_COEFF_NUM];
    kal_int16 speech_output_FIR_coeffs[6][SPEECH_FIR_COEFF_NUM];
    kal_uint16 selected_FIR_output_index;
    kal_uint16 speech_mode_para[8][16];
    kal_uint16 speech_volume_para[3][7][4];
}
audio_param_med_struct;

typedef struct
{
    /* Volume */
    kal_int16 vol_calibration_shift[8];
    kal_int16 vol_calibration_subband[8];
    /* Delay */
    kal_int16 delay_cal_int;
    kal_int16 delay_cal_frac;
    kal_int16 delay_cal_subband[8];
    /* Leakage */
    kal_int16 power_ratio_scale;
    kal_int16 wind_index_threshold;
    kal_int16 subband_bmg[8];
    /*Mockup Diagnosis*/
    kal_int16 mockup_level;
    kal_int16 shielding_level;
    kal_int16 NR_Level;
    /* Reserve */
    kal_int16 reserve[5];
}
audio_dual_mic_nb_param_struct;

typedef struct 
{           
    /* Volume */
    kal_int16 vol_calibration_shift[16];
    kal_int16 vol_calibration_subband[16];
    /* Delay */
    kal_int16 delay_cal_int;
    kal_int16 delay_cal_frac;
    kal_int16 delay_cal_subband[16];
    /* Leakage */
    kal_int16 power_ratio_scale;
    kal_int16 wind_index_threshold;
    kal_int16 subband_bmg[16];
    /*Mockup Diagnosis*/
    kal_int16 mockup_level;
    kal_int16 shielding_level;    
    kal_int16 NR_Level;        
    /* Reserve */
    kal_int16 reserve[5];
}
audio_dual_mic_wb_param_struct;

typedef struct
{
    audio_dual_mic_nb_param_struct nb_param; /* narrow band parameter*/
    audio_dual_mic_wb_param_struct wb_param; /* wide band parameter */
}
audio_dual_mic_param_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
l4aud_audio_get_max_volume_level_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 max_volume_level;
}
l4aud_audio_get_max_volume_level_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 max_volume_level;
}
l4aud_audio_set_max_volume_level_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
l4aud_audio_set_max_volume_level_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void* data_p;
    kal_uint8 reason; /* aud_state_change_reason_enum */
}
l4aud_audio_state_change_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint64 volume;      /* volume data */
    kal_uint8 audio_type;   /* volume type */
}
l4aud_audio_update_volume_req_struct;

/* this is the same to device_tones_struct and L1SP_Tones */
typedef struct
{
    kal_uint16 freq1;           /* First frequency                                    */
    kal_uint16 freq2;           /* Second frequency                                   */
    kal_uint16 on_duration;     /* Tone on duation, in ms unit, 0 for continuous tone */
    kal_uint16 off_duration;    /* Tone off duation, in ms unit, 0 for end of playing */
    kal_int8 next_operation;    /* Index of the next tone                             */
} aud_tones_struct;

typedef struct
{
    LOCAL_PARA_HDR
    aud_tones_struct *tone_list;
    kal_uint16 identifier;
    kal_uint8 src_id;
    kal_uint8 volume;
}
l4aud_audio_play_tone_seq_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_audio_play_tone_seq_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 identifier;
    kal_uint8 src_id;
}
l4aud_audio_stop_tone_seq_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_audio_stop_tone_seq_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 audio_type;
    kal_bool fir_on;
}
l4aud_audio_set_fir_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
l4aud_audio_set_fir_cnf_struct;

/* speech */

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 mode;
    kal_uint8 mic_volume;
    kal_uint8 sidetone_volume;
}
l4aud_sp_set_input_mode_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
l4aud_sp_set_input_mode_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool is_enable;
}
l4aud_mic_set_dual_nr_req_struct;

#ifdef __VOICE_CHANGER_SUPPORT__
typedef struct
{
    LOCAL_PARA_HDR
    SPH_VOICE_CHANGER_MODE mode;
} media_voice_changer_set_mode_req_struct;
#endif

/* voice memo */

/* informatiom struct for voice memo files */
typedef struct
{
    kal_uint32 free_space;
    kal_uint32 reserved;
    kal_uint16 no_of_vm;
    kal_wchar file_name_list[MAX_NUM_OF_VM_LIST][MAX_VM_FILE_NAME];
    kal_bool more_entry;
}
aud_vm_info_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 direction;
}
l4aud_vm_record_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_vm_record_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_wchar file_name[MAX_VM_FILE_NAME];
}
l4aud_vm_play_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_vm_play_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
l4aud_vm_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar file_name[MAX_VM_FILE_NAME];
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_vm_stop_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar file_name[MAX_VM_FILE_NAME];
    kal_uint8 src_id;
    kal_bool delete_all;
}
l4aud_vm_delete_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_vm_delete_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
l4aud_vm_abort_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_vm_abort_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
l4aud_vm_pause_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar file_name[MAX_VM_FILE_NAME];
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_vm_pause_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
l4aud_vm_resume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_vm_resume_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar file_name[MAX_VM_FILE_NAME];
    kal_uint8 src_id;
}
l4aud_vm_append_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_vm_append_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
l4aud_vm_get_info_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    aud_vm_info_struct vm_info;
    kal_uint8 src_id;
}
l4aud_vm_get_info_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar old_file_name[MAX_VM_FILE_NAME];
    kal_wchar new_file_name[MAX_VM_FILE_NAME];
    kal_uint8 src_id;
}
l4aud_vm_rename_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_vm_rename_cnf_struct;

/* indication */

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar file_name[MAX_VM_FILE_NAME];
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_vm_record_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_vm_play_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 event;
}
aud_vm_read_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 event;
}
aud_vm_write_data_ind_struct;

typedef void (*media_seek_cb_fct)(kal_uint8 reason /* aud_seek_reason_enum */ , void* param);

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 size_limit;
    kal_uint32 time_limit;
    kal_wchar file_name[MAX_MEDIA_FILE_NAME];
    kal_uint8 src_id;
    kal_uint8 format;
    kal_uint8 quality;
    kal_uint8 input_source;
    kal_bool  default_input;
}
l4aud_media_record_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_media_record_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
l4aud_media_pause_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_media_pause_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
l4aud_media_resume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_media_resume_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
l4aud_media_store_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint64 volume;
    /* set both start_offset and end_offset to 0 for backward compatible */
    kal_uint32 start_offset;    /* 0 : file begining */
    kal_uint32 end_offset;      /* 0 or file data len-1: file end */
    void *cache_p;
    kal_wchar file_name[MAX_MEDIA_FILE_NAME];
    kal_uint16 identifier;
    kal_uint8 src_id;
    kal_uint8 play_style;
    kal_uint8 output_path;
}
l4aud_media_restore_req_struct;

/* Audio trimmng */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 handle;
    kal_uint32 result;
}
l4aud_trim_result_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 handle;
    kal_uint8 event;
}
l4aud_trim_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar* file_name_in;  /* Source file */
    kal_wchar* file_name_out; /* The file to be trimmed to */
    kal_uint32* handle_p;     /* Trimming handle */
}
l4aud_trim_open_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 handle;
}
l4aud_trim_close_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 handle;
}
l4aud_trim_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 handle;
}
l4aud_trim_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 set_type;
    void* data_p;
    kal_uint16 data_len;
}
l4aud_trim_set_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 get_type;
    void* data_p;
    kal_uint16* data_len_p;
}
l4aud_trim_get_param_req_struct;


typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 vol_type;
    kal_bool mute;
}
media_aud_set_mute_req_struct;

/* indication */

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 event;
    kal_uint8 session_id;
}
aud_media_write_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 event;
}
aud_media_read_data_ind_struct, media_vid_read_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
l4aud_media_record_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 duration;
    kal_uint16 identifier;
}
l4aud_media_play_update_dur_ind_struct;

/* FM Radio Begin */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 output_path;
}
media_fmr_power_on_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_fmr_power_off_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 output_path;
}
media_fmr_set_output_path_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool is_short_antenna;
}
media_fmr_set_antenna_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 freq;
}
media_fmr_set_freq_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 mute;
}
media_fmr_mute_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 freq;
    kal_uint8 is_step_up;
}
media_fmr_check_is_valid_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 is_valid;
}
media_fmr_check_is_valid_stop_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 freq;
    kal_uint8 is_step_up;
}
media_fmr_get_signal_level_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 signal_level;
}
media_fmr_get_signal_level_cnf_struct;

typedef struct
{
   LOCAL_PARA_HDR
}
media_fmr_evaluate_threshold_req_struct;

typedef struct
{
   LOCAL_PARA_HDR
   kal_bool is_mono;
}
media_fmr_set_channel_req_struct;

typedef struct
{
   LOCAL_PARA_HDR
   kal_uint16 start_freq;
   kal_int16 space;
   kal_bool is_step_up;
   kal_bool is_preset;
}
media_fmr_seek_start_req_struct;

typedef struct
{
   LOCAL_PARA_HDR
}
media_fmr_seek_abort_req_struct;

typedef struct
{
   LOCAL_PARA_HDR
   kal_uint16 stop_freq;
   kal_uint8 signal_level;
   kal_bool is_valid;
}
media_fmr_seek_callback_ind_struct;

typedef struct
{
   LOCAL_PARA_HDR
   kal_uint16 event;
}
media_fmr_rds_callback_ind_struct;

typedef struct
{
   LOCAL_PARA_HDR
   kal_uint16 stop_freq;
   kal_uint8 signal_level;
   kal_bool is_valid;
}
media_fmr_seek_result_ind_struct;

typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8 *scan_table;
}
media_fmr_hw_scan_req_struct;


typedef struct
{
   LOCAL_PARA_HDR
}
media_fmr_hw_scan_abort_req_struct;

typedef struct
{
   LOCAL_PARA_HDR
   kal_uint16 stop_freq;
}
media_fmr_hw_scan_result_struct;


typedef struct
{
   LOCAL_PARA_HDR
   kal_uint16 data[FM_RDS_MAX_DATA_BUFF_SIZE];
   kal_uint16 data_len; /* 2 bytes per unit */
   kal_uint16 flag;
   kal_uint16 event;  
   kal_uint16 frequency;
}
media_fmr_rds_event_ind_struct;

typedef struct
{
   LOCAL_PARA_HDR
   kal_uint8 af;
   kal_uint8 ta;
}
media_fmr_rds_enable_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_fmr_rds_disable_req_struct;

/* FM Radio End */

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 seq_no;
    kal_uint8 src_id;
    kal_uint8 event;
}
aud_media_play_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 seq_no;
    kal_uint8 src_id;
    kal_uint8 event;
}
aud_media_play_stream_event_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR

}
media_aud_vib_spk_calibration_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 enabled;
}
media_aud_set_vibrator_enabled_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *audio_data;
    kal_uint32 len;
    kal_wchar file_name[MAX_MEDIA_FILE_PATH_LEN + 1];
    kal_uint8 format;
    kal_bool use_default_handle;
    kal_bool full_duration;
}
media_aud_get_duration_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_aud_get_progress_time_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 progress;
}
media_aud_set_progress_time_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar file_name[MAX_MEDIA_FILE_NAME];
}
media_aud_check_is_pure_audio_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar file_name[MAX_MEDIA_FILE_NAME];
}
media_aud_check_is_file_seekable_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar file_name[MAX_MEDIA_FILE_NAME];
}
media_aud_check_is_file_pausable_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 resource;
}
media_aud_check_is_resource_available_req_struct;


/**
  * CAMERA
  */

typedef enum
{
    CAM_XENON_FLASH_OFF = 0,
    CAM_XENON_FLASH_CHARGING,
    CAM_XENON_FLASH_READY,
    CAM_XENON_FLASH_TIMEOUT,
    CAM_XENON_FLASH_LOW_BATTERY,
    CAM_XENON_FLASH_NUM
}
media_cam_xenon_flash_status_enum;

typedef struct
{
    LOCAL_PARA_HDR
    media_cam_xenon_flash_status_enum status;
}
media_cam_xenon_flash_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 cam_id;
}media_cam_set_camera_id_req_struct;


#define CAMERA_SUPPORT_ITEM_MAX_NO  (20)
typedef struct
{
    kal_bool is_support;        /* Is this camera function supportable ? */
    kal_uint32 item_count;         /* The number of the workable item */
    kal_uint32 support_item[CAMERA_SUPPORT_ITEM_MAX_NO];   /* The enum of workable item */
}media_cam_qurey_sensor_general_capability_req_struct;

typedef struct
{
    kal_uint16 image_width;
    kal_uint16 image_height;    
}media_cam_capture_image_size_info;

typedef struct
{
    kal_bool is_support;        /* Is this camera function supportable ? */
    kal_uint32 item_count;         /* The number of the workable item */
    kal_uint32 support_item[CAMERA_SUPPORT_ITEM_MAX_NO];   /* The enum of workable item */
    media_cam_capture_image_size_info image_size[CAMERA_SUPPORT_ITEM_MAX_NO];   /* the enum of workable item info */ // gellmann 12.03		
}media_cam_qurey_sensor_image_size_req_struct;

typedef struct
{
    BINNING_INFO_STRUCT IsoBinningInfo[CAM_NO_OF_ISO];

}media_cam_query_iso_binning_capability_req_struct;

typedef struct
{
    kal_bool is_support;
}media_cam_query_capture_overlay_req_struct;

typedef CAL_CAMERA_DIGITAL_ZOOM_OUT_STRUCT media_cam_zoom_capability_info_struct;

typedef struct
{
    LOCAL_PARA_HDR
    CAL_CAMERA_MODE_ENUM camera_mode;
    kal_uint32 image_size;
    media_cam_zoom_capability_info_struct* result_p;

}media_cam_zoom_capability_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    CAL_CAMERA_MODE_ENUM camera_mode;
    kal_uint32 item_id;
    void* struct_p;
}
media_cam_sensor_query_capability_req_struct;

#ifdef __STREAM_SERVER_SUPPORT__
typedef struct
{
    kal_bool is_support;                                    /* Is this camera function supportable ? */
    kal_uint32 item_count;                                  /* The number of the workable item */
    kal_uint32 support_item[CAMERA_SUPPORT_ITEM_MAX_NO];    /* The enum of workable item */
}media_cam_sensor_general_info;                            /* for mdi_camera_query_support_info */
#endif

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 seq_num;
    kal_uint16 cam_id;
    kal_uint16 app_id;
}
media_cam_power_up_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 delay_time;
}
media_cam_power_down_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 seq_num;
}
media_cam_ready_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 frame_buffer1_address;
    kal_uint32 frame_buffer2_address;
    kal_uint32 frame_buffer_size;

    kal_uint32 layer_element;
    kal_uint32 blt_ctx;
    kal_uint32 blt_dev;

    kal_uint8  ui_rotate;
    kal_uint8  image_data_format;
    kal_bool   lcd_update;
    kal_uint32 update_layer;
    kal_uint32 hw_update_layer;
    kal_uint32 src_key_color;

    kal_uint8  capture_mode;

    kal_bool   overlay_frame_mode;                /* KAL_TRUE or KAL_FALSE to enable or disable overlay function */
    kal_uint8  overlay_color_depth;              /* The color depth of overlay frame buffer */
    kal_uint8  overlay_frame_source_key;
    kal_uint16 overlay_frame_width;             /* Image width of overlay frame buffer */
    kal_uint16 overlay_frame_height;            /* Image height of overlay frame buffer */
    kal_uint32 overlay_frame_buffer_address;    /* The starting address of overlay frame buffer */
    kal_uint8  overlay_palette_size;
    kal_uint32 *overlay_palette_addr;

    kal_uint16 image_width;
    kal_uint16 image_height;
    kal_uint16 preview_width;
    kal_uint16 preview_height;
    kal_uint16 preview_offset_x;
    kal_uint16 preview_offset_y;

    kal_int16  frame_rate;
    kal_int16  contrast;
    kal_int16  brightness;
    kal_int16  saturation;
    kal_int16  sharpness_level;         /* ISP sharpness level */
    kal_int16  hue;
    kal_int16  gamma;
    kal_int16  WB;
    kal_int16  exposure;
    kal_int16  effect;
    kal_int16  zoom_step;
    kal_uint8  total_zoom_step;         /* total zoom step number */
    kal_uint32 max_zoom_factor;         /* maximum zoom factor */

    kal_int16  rotate;
    kal_int16  lcd_rotate;
//    kal_bool   night_mode;
    kal_uint8  banding_freq;
    kal_uint16 scene_mode;              /* scene mode */
    kal_uint8  ae_metering_mode;        /* AUTO, SPOT, CENTRAL WEIGHT, AVERAGE */
    kal_uint8  flash_mode;              /* AUTO, ON, OFF, REDEYE */
    kal_uint8  af_operation_mode;
    kal_uint8  af_range;                /* AUTO, MACRO, LANDSCAPE, MANUAL */
    kal_bool   binning_mode;
    kal_bool   fd_enable;
    kal_uint8  smile_required_no;

    /* LCD Setting */
    kal_uint32 roi_background_color;    /* set the background color */

    /* AF */
    kal_uint16 af_zone0_x;  /* AF Zone 0 X-coordinate, (0,0) means left-top corner */
    kal_uint16 af_zone0_y;  /* AF Zone 0 Y-coordinate */
    kal_uint16 af_zone1_x;  /* AF Zone 1 X-coordinate */
    kal_uint16 af_zone1_y;  /* AF Zone 1 Y-coordinate */
    kal_uint16 af_zone2_x;  /* AF Zone 2 X-coordinate */
    kal_uint16 af_zone2_y;  /* AF Zone 2 Y-coordinate */
    kal_uint16 af_zone3_x;  /* AF Zone 3 X-coordinate */
    kal_uint16 af_zone3_y;  /* AF Zone 3 Y-coordinate */
    kal_uint16 af_zone4_x;  /* AF Zone 4 X-coordinate */
    kal_uint16 af_zone4_y;  /* AF Zone 4 Y-coordinate */

    /* TV Setting */
    kal_uint8 tv_output_mode;
    kal_bool tv_output;
    kal_uint16 tv_output_width;                 /* image width for TV output */
    kal_uint16 tv_output_height;                /* image height for TV output */
    kal_uint16 tv_output_offset_x;              /* the offset X from TV output frame buffer to preview image */
    kal_uint16 tv_output_offset_y;              /* the offset Y from TV output frame buffer to preview image */
    kal_uint32 tv_output_buffer1_address;       /* image buffer1 for TV source buffer */
    kal_uint32 tv_output_buffer2_address;       /* image buffer2 for TV source buffer */
    kal_uint32 tv_rotate_buffer1_address;       /* rotate buffer1 for TV source buffer */
    kal_uint32 tv_rotate_buffer2_address;       /* rotate buffer2 for TV source buffer */
    kal_uint32 tv_output_buffer_size;           /* image buffer size for TV source buffer */
}
media_cam_preview_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
}
media_cam_preview_fail_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_cam_stop_req_struct;

typedef struct
{
    kal_uint32 file_size[20];
    kal_uint32 file_address[20];
}
media_jpegs_struct;


typedef struct
{
    kal_uint8  face_no;/* detected face no */
//    kal_uint32 id[MAX_CAM_FD_NO];/* id */
//    kal_uint8  priority[MAX_CAM_FD_NO];/* face priority */
    kal_uint16 rect_x0[MAX_CAM_FD_NO];  //left top point
    kal_uint16 rect_y0[MAX_CAM_FD_NO];
    kal_uint16 rect_x1[MAX_CAM_FD_NO];  //right bottom point
    kal_uint16 rect_y1[MAX_CAM_FD_NO];

    kal_bool   sd_end_flag;
    kal_uint8  smile_detected_no;
//    kal_bool   sd_detected_flag[MAX_CAM_FD_NO];
    kal_uint16 sd_rect_x0[MAX_CAM_FD_NO];
    kal_uint16 sd_rect_y0[MAX_CAM_FD_NO];
    kal_uint16 sd_rect_x1[MAX_CAM_FD_NO];
    kal_uint16 sd_rect_y1[MAX_CAM_FD_NO];

    kal_uint8 camera_scene_detected_mode;   // for ASD result
} media_cam_fd_result_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
    media_cam_fd_result_struct fd_result;
} media_cam_sd_event_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    media_cam_fd_result_struct* fd_result_p;
}media_cam_get_fd_result_struct;

typedef struct
{
    LOCAL_PARA_HDR
    media_cam_fd_result_struct fd_result;
} media_cam_fd_result_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 lcd_buffer_address;
} media_cam_fd_process_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void        *image_buffer_p;
    void        *filename_p;
    kal_uint8   *app_capture_buffer_p;
    kal_uint32  app_capture_buffer_size;
    void        **capture_buffer_p;
    kal_uint32  *file_size_p;

    media_jpegs_struct *jpegs_p;

    kal_uint8  ui_rotate;
    kal_uint8  media_mode;
    kal_uint8  source_device;
    kal_uint16 image_width;
    kal_uint16 image_height;
    kal_int16  flash_mode;
    kal_uint8  image_quality;
    kal_uint8  gray_mode;
    kal_uint8  snapshot_number;
    kal_uint32 capture_layer;   /* capture layer for capture from mem(lcd) case */
    kal_uint8  continue_capture;

    kal_uint8  capture_mode;

#if defined(__CAMERA_CAPTURE_USING_APP_MEMORY__)
    kal_uint32 capture_y_buffer_address;
    kal_uint32 capture_y_buffer_size;
    kal_uint32 capture_u_buffer_address;
    kal_uint32 capture_u_buffer_size;
    kal_uint32 capture_v_buffer_address;
    kal_uint32 capture_v_buffer_size;
#endif

    /* panorama shot only */
    kal_uint8 current_shot_number;
    kal_uint8 direction;
    /* end of panorama shot only */

    /* IPP Setting */
    kal_bool   overlay_frame_mode;              /* KAL_TRUE or KAL_FALSE */
    kal_uint8  overlay_color_depth;             /* 1/2/4/8 bpp */
    kal_uint8  overlay_frame_source_key;        /* source key of the overlay frame buffer */
    kal_uint16 overlay_frame_width;             /* overlay frame width */
    kal_uint16 overlay_frame_height;            /* overlay frame height */
    kal_uint32 overlay_frame_buffer_address;    /* bsae address of the overlay frame buffer */
    kal_uint8  overlay_palette_size;
    kal_uint32 *overlay_palette_addr;

    kal_uint8  image_data_format;           /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    /* Display Setting */
    kal_uint32 update_layer;                /* the updated layer */
    kal_uint32 hw_update_layer;             /* which layer will be applied by hw trigger or direct couple for MT6219 only */

    kal_bool display;   /* output to LCM or TV */
    kal_uint32 frame_buffer_address;
    kal_uint32 frame_buffer_size;

    kal_bool   tv_output;                     /* works when display item is KAL_TRUE */
    kal_uint16 tv_output_width;             /* image width for TV output */
    kal_uint16 tv_output_height;            /* image height for TV output */
    kal_uint16 tv_output_offset_x;          /* the offset X from TV output frame buffer to preview image */
    kal_uint16 tv_output_offset_y;          /* the offset Y from TV output frame buffer to preview image */
    kal_uint32 tv_output_buffer1_address;   /* image buffer1 for TV source buffer */
    kal_uint32 tv_output_buffer2_address;   /* image buffer2 for TV source buffer, if snapshot_number==1, this buffer is not necessary */
    kal_uint32 tv_output_buffer_size;       /* image buffer size for TV source buffer */

    kal_bool   quickview_output; /* is direct couple to another buffer */
    kal_uint8  quickview_lcd_rotate;
    kal_uint16 quickview_output_width;
    kal_uint16 quickview_output_height;
    kal_uint32 quickview_output_buffer_address;
    kal_uint32 quickview_output_buffer_size;
    /* mav / 3d image only */
    kal_uint8  mav_seq_num;

}
media_cam_capture_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 **buf_pp;
    kal_uint32 *buf_size_p;
}
media_cam_encode_image_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 param_id;
    kal_int32 value;//    kal_int16 value;
}
media_cam_set_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 flash_mode;
}
media_cam_set_flash_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 event;
    kal_uint8 cause;
}
media_cam_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 af_search_result;
    kal_uint32 af_success_zone;
}
media_cam_af_ind_struct;

typedef struct
{
    kal_uint32      af_zone_w;
    kal_uint32      af_zone_h;
    kal_uint32      af_zone_x;
    kal_uint32      af_zone_y;
}
media_cam_af_zone_struct;

typedef struct
{
    kal_uint32                  af_active_zone;
    media_cam_af_zone_struct    af_zone[MEDIA_CAM_AF_ZONE_MAX_NO];
}media_cam_af_zone_para_struct;

typedef struct
{
    LOCAL_PARA_HDR
    media_cam_af_zone_para_struct* zone_para_p;
}media_cam_af_get_zone_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 palette_size;
    kal_uint32 *palette_addr;
} media_cam_set_overlay_palette_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 count;
}
media_cam_capture_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool zoom_in;
    kal_uint8 zoom_limit;
    kal_uint8 zoom_step;
    kal_uint8 zoom_speed;
}
media_cam_start_fast_zoom_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_cam_stop_fast_zoom_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 *factor;
    kal_uint32 *step;
}
media_cam_get_fast_zoom_factor_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 *total_steps;
    kal_uint32 *current_steps;
    kal_bool *flag;
}
media_cam_get_focus_steps_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_cam_pause_pp_req_struct, media_cam_resume_pp_req_struct, media_cam_unset_fd_id_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar* filepath;
}
media_cam_save_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 fd_id;
}
media_cam_set_fd_id_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 buffer_width;
    kal_uint32 buffer_height;
    kal_uint32 buffer_address;
    kal_uint32 buffer_size;
}
media_cam_get_buff_content_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16  image_qty;
    kal_uint32  image_width;
    kal_uint32  image_height;
    kal_uint32* image_size_p;
}
media_cam_get_predicted_image_size_req_struct;

typedef struct _media_cam_start_mav_stitch_req_struct
{
    LOCAL_PARA_HDR

}media_cam_start_mav_stitch_req_struct;


/* IMAGE */

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 display_width;
    kal_uint16 display_height;

    kal_uint16 image_clip_x1;   /* clip window start x for clipping decoded image */
    kal_uint16 image_clip_x2;   /* clip window end x for clipping decoded image */
    kal_uint16 image_clip_y1;   /* clip window start y for clipping decoded image */
    kal_uint16 image_clip_y2;   /* clip window end y for clipping decoded image */

    int start_x, start_y;           /* destination position ( maybe < 0) */
    void *image_buffer_p;           /* destination buffer address */
    kal_uint32 image_buffer_size;   /* destination buffer size */
    kal_uint32 image_buffer_width;  /* destination buffer width */
    kal_uint32 image_buffer_height; /* destination buffer height */
    kal_uint8 image_buffer_format;  /* destination buffer format */

    kal_uint8 media_mode;
    kal_uint8 media_type;
    void *data;             /* source (memory pointer or file name) */
    kal_uint32 file_size;   /* source size or file size */
    kal_uint16 seq_num;     /* serial number */
    kal_uint8 blocking;     /* blocking or not */
    void (*callback) (kal_int32 result);

    /* FOR JPEG ONLY */
    kal_bool jpeg_thumbnail_mode;   /* decode thumbnail or not */
    kal_bool jpeg_retry_thumbnail;
    kal_bool image_pitch_mode;      /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;    /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes;   /* pitch width */

    kal_bool memory_output;             /* output another image for TV output */
    kal_uint16 memory_output_width;     /* image width for TV output */
    kal_uint16 memory_output_height;    /* image height for TV output */
    kal_uint32 memory_output_buffer_address;
    kal_uint32 memory_output_buffer_size;
    kal_uint16 decoded_image_width;     /* decoded image width */

    /* FOR GIF HW V2 ONLY */
    kal_uint32 cache_id;
    void *lct_addr;
    void *gct_addr;
    void *gif_info;
    kal_uint16 frame_number;
    kal_bool transparent_enable;
    kal_uint32 layer_src_key;
    kal_bool use_disposal_method;
    /* FOR PNG V1 ONLY */
    void (*blt_callback) (kal_uint8 *src, kal_uint32 src_pitch, kal_int16 src_x, kal_int16 src_y, kal_uint16 src_width, kal_uint16 src_height, kal_uint8 src_color_mode, kal_uint8 *dest, kal_uint32 dest_pitch, kal_int16 dest_x, kal_int16 dest_y, kal_uint8 dest_color_mode, kal_int16 clipx1, kal_int16 clipy1, kal_int16 clipx2, kal_int16 clipy2, kal_bool src_key_enable, kal_uint32 src_key); /* some case need MMI to bitblt to layer buffer. */

}
media_img_decode_req_struct;

typedef struct
{
    kal_char *filename;
    kal_char make[35];
    kal_char model[35];
    kal_char orientation[11];
    kal_char x_resolution[24];
    kal_char y_resolution[24];
    kal_char resolution_unit[12];
    kal_char software[35];
    kal_char date_time[35];
    kal_char ycbcr_positioning[9];
    kal_char exif_ifd[14];

    kal_char exposure_time[24];
    kal_char fnumber[24];
    kal_char exposure_program[18];
    kal_char iso_speed_ratings[6];
    kal_char exif_version[20];
    kal_char date_time_original[35];
    kal_char date_time_digitized[35];
    kal_char components_config[6];
    kal_char exposure_bias_value[24];
    kal_char metering_mode[24];
    kal_char light_source[17];
    kal_char flash[80];
    kal_char maker_note[20];
    kal_char flashpix_version[20];
    kal_char color_space[13];
    kal_char pixel_x_dimension[14];
    kal_char pixel_y_dimension[14];
    kal_char exposure_mode[16];
    kal_char digital_zoom_ratio[24];
    kal_char scene_capture_type[12];

} media_img_exif_info_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    media_img_exif_info_struct *exif_info;
}
media_img_exif_decode_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 seq_num;
    kal_uint16 image_width;
    kal_uint16 image_height;
}
media_img_decode_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 cause;
    kal_uint32 arg0;
    kal_uint32 arg1;
}
media_img_decode_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 image_width;
    kal_uint16 image_height;
    kal_uint8 image_quality;
    void *image_buffer_p;
    kal_uint32 image_buffer_size;
    kal_uint32 expected_encode_size;
    kal_uint16 target_width;
    kal_uint16 target_height;
    kal_uint8 media_mode;
    kal_uint8 media_type;
    void *data;
    kal_uint32 file_buffer_len;
    kal_int32 *file_size_p;
    kal_uint16 seq_num;
    kal_uint8 blocking;
    kal_uint8 gray_mode;
    kal_uint8 input_type;
    kal_uint8 background_encode;
    kal_uint8 jpeg_yuv_mode;    /* YUV420, YUV422 or Gray mode */

    kal_bool thumbnail_mode;    /* add thumbnail in JPEG file or not */
    kal_uint16 thumbnail_width;
    kal_uint16 thumbnail_height;

    kal_bool overlay_frame_mode;                /* KAL_TRUE or KAL_FALSE */
    kal_uint8 overlay_color_depth;              /* 1/2/4/8 bpp */
    kal_uint8 overlay_frame_source_key;         /* source key of the overlay frame buffer */
    kal_uint16 overlay_frame_width;             /* overlay frame width */
    kal_uint16 overlay_frame_height;            /* overlay frame height */
    kal_uint32 overlay_frame_buffer_address;    /* bsae address of the overlay frame buffer */
}
media_img_encode_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 seq_num;
}
media_img_encode_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 cause;
}
media_img_encode_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_img_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 src_image_address;    /* the source image buffer start address */
    kal_uint32 dest_image_address;                  /* the destination image buffer start address */
    kal_uint32 dest_buffer_size;                    /* the buffer size of destination image buffer size */
    kal_uint16 src_width;                           /* the width of image source */
    kal_uint16 src_height;                          /* the height of image source */
    kal_uint16 src_pitch;                           /* the pitch width of image source */
    kal_uint16 target_width;                        /* the width of target image */
    kal_uint16 target_height;                       /* the height of target image */
    kal_uint16 image_clip_x1;                       /* image clip window start x */
    kal_uint16 image_clip_x2;                       /* image clip window end x */
    kal_uint16 image_clip_y1;                       /* image clip window start y */
    kal_uint16 image_clip_y2;                       /* image clip window end x */
    kal_uint16 seq_num;                             /* use for non-blocking mode */
    kal_uint8 blocking;
    kal_uint8 type;                                 /* IBR1_TYPE_RGB565 or IBR1_TYPE_RGB888 */
    kal_uint8 data_order;                           /* IBR1_ORDER_BGR888 or IBR1_ORDER_RGB888 */
    kal_bool image_pitch_mode;                      /* KAL_TRUE or KAL_FALSE for block mode of decoded image */
    kal_uint8 image_data_format;                    /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    kal_uint16 image_pitch_bytes;                   /* pitch width */
}
media_img_resize_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 seq_num;
}
media_img_resize_done_ind_struct;

/* VIDEO */
typedef enum
{
    MED_AVI_SAVE_TYPE_DATA,
    MED_AVI_SAVE_TYPE_IDX,
    MED_AVI_SAVE_TYPE_TERMINATE
} media_avi_save_type_enum;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 layer_element;
    kal_uint32 blt_ctx;
    kal_uint32 blt_dev;

    /* reserved temperary */
    kal_uint16 preview_offset_x;        /* preview offset_x from lcd_offset_x */
    kal_uint16 preview_offset_y;        /* preview offset_y from lcd_offset_y */


    /* new parameters */
    kal_uint8 ui_rot_angle;                         /* MM_IMAGE_ROTATE_ENUM */
    kal_uint8 image_data_format;                    /* MM_IMAGE_FORMAT_ENUM */
    kal_uint16 preview_width;
    kal_uint16 preview_height;
    kal_uint32 frame_buffer_addr1;
    kal_uint32 frame_buffer_addr2;
    kal_uint32 frame_buffer_size;
    kal_uint32 encode_one_frame_duration; // ms
    kal_uint16 image_width;
    kal_uint16 image_height;
    kal_bool lcd_update;
    kal_bool force_lcd_hw_trigger;

    kal_uint8 zoom_step;
    kal_int16 contrast;
    kal_int16 brightness;
    kal_int16 saturation;
    kal_int16 WB;
    kal_int16 exposure;
    kal_int16 effect;
    kal_uint16 sharpness;
    kal_uint8 banding_freq;
    kal_uint8 af_operation_mode;                /* AUTO, MACRO, INFINITE, MANUAL */
    kal_uint8 af_range;                         /* AUTO, MACRO, LANDSCAPE, MANUAL */
    kal_uint8 scene_mode;           /* NORMALSCENE, PORTRAIT, LANDSCAPE, SPORT, FLOWER, NIGHTSCENE */

/* old paramters */
    kal_int16 hue;
    kal_int16 gamma;
    kal_int16 zoom_factor;
    kal_int16 flash_mode;
    kal_bool night_mode;

    kal_uint16 storage;
    kal_uint8 encode_quality;
    kal_uint8 bit_stream_type;
    kal_uint8 gray_mode;
    kal_uint16 seq_num;

    kal_uint8 lcd_id;

    /* IPP Setting */
    kal_bool overlay_frame_mode;                /* KAL_TRUE or KAL_FALSE to enable or disable overlay function */
    kal_uint8 overlay_color_depth;              /* The color depth of overlay frame buffer */
    kal_uint8 overlay_frame_source_key;
    kal_uint16 overlay_frame_width;             /* Image width of overlay frame buffer */
    kal_uint16 overlay_frame_height;            /* Image height of overlay frame buffer */
    kal_uint32 overlay_frame_buffer_address;    /* The starting address of overlay frame buffer */
 
#ifdef __STREAM_SERVER_SUPPORT__
	kal_int32 audio_rtp_handle;
	kal_int32 video_rtp_handle;
#endif

}
media_vid_preview_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 af_search_result;
    kal_uint32 af_success_zone;
}
media_vid_af_ind_struct;

typedef struct
{
    kal_uint32      af_zone_w;
    kal_uint32      af_zone_h;
    kal_uint32      af_zone_x;
    kal_uint32      af_zone_y;
}
media_vid_af_zone_struct;

typedef struct
{
    kal_uint32                  af_active_zone;
    media_vid_af_zone_struct    af_zone[MEDIA_CAM_AF_ZONE_MAX_NO];
}media_vid_af_zone_para_struct;

typedef struct
{
    LOCAL_PARA_HDR
    media_vid_af_zone_para_struct* zone_para_p;
}media_vid_af_get_zone_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32* size;
}media_vid_get_reserved_disc_size_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 event;
    kal_int32 cause;
}
media_vid_event_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_mode;
    kal_uint8 media_type;
    kal_uint8 record_audio;
    kal_uint8 encode_quality;
    kal_uint8 encode_rotate;     /* MM_IMAGE_ROTATE_ENUM */
    kal_uint16 image_width;
    kal_uint16 image_height;
    void *data;
    kal_uint32 file_size_limit;
    kal_uint32 time_limit;
    kal_uint16 seq_num;

}
media_vid_record_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_vid_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_vid_rec_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 seq_num;
}
media_vid_record_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool is_yuv;
}
media_vid_record_yuv_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 event;
}
media_vid_encode_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 event;
}
media_vid_read_audio_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 event;
}
media_vid_read_video_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 event;
}
media_vid_read_meta_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar *file_path;
}
media_vid_file_merge_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_vid_clean_file_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 result;
}
media_vid_file_merge_done_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar *file_name_p;
    kal_uint16 seq_num;
    kal_uint16 cache_in_mem;
}
media_vid_open_file_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 image_width;
    kal_uint16 image_height;
    kal_uint64 total_time;
    kal_uint16 seq_num;
    kal_int32 handle;
    kal_int32 file_handle;
    kal_bool is_seekable;
#ifdef __VIDEO_CLIPPER_SUPPORT__     
    kal_bool is_proprietary;
#endif
#ifdef __VIDEO_3D_ANAGLYPH__    
    kal_uint32 track_num;
    mpl_player_video_track_info_t track_info[VID_MAX_VIDEO_TRACK_NUM];
#endif    
#ifdef __VIDEO_SUBTITLE_SUPPORT__    
    kal_uint32 subtitle_num;
    mpl_player_subtitle_track_info_t subtitle_info[VID_MAX_VIDEO_SUBTITLE_NUM];
#endif  

}
media_vid_file_ready_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
}
media_vid_close_file_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_mode;
    kal_uint8 media_type;
    void *data;
    kal_uint32 data_size;
    kal_uint16 seq_num;
    med_track_enum open_track;
    mpl_scenario_enum scenario;
    kal_uint8 blocking;
    kal_bool enable_aud_only;   /* allows to open aud only video */

    /* content info */
    kal_uint16 *image_width;
    kal_uint16 *image_height;
    kal_uint64 *total_time;
    kal_int32 *handle;
    kal_bool *is_seekable;
#ifdef __VIDEO_CLIPPER_SUPPORT__    
    kal_bool *is_proprietary;
#endif
    kal_uint16 app_id;
    /* file handle */
    kal_int32 *file_handle;      /* FS_HANDLE */
#ifdef __VIDEO_3D_ANAGLYPH__    
    kal_uint32 *track_num;
    mpl_player_video_track_info_t *track_info;
#endif    
#ifdef __VIDEO_SUBTITLE_SUPPORT__    
    kal_uint32 *subtitle_num;
    mpl_player_subtitle_track_info_t *subtitle_info;

    mpl_player_external_api_t extern_api;
#endif

}
media_vid_open_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_vid_close_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_mode;
    kal_uint8 media_type;
    void *data;
    kal_uint16 display_width;
    kal_uint16 display_height;
    void *image_buffer_p;
    kal_int16 zoom_factor;
    kal_int16 frame_rate;
    kal_int16 contrast;
    kal_int16 brightness;
    kal_int16 play_speed;
    kal_uint8 play_audio;
    kal_uint8 display_device;
    kal_uint8 audio_path;
    kal_uint16 seq_num;
    kal_uint16 repeats;

    kal_uint8 lcd_id;
    kal_uint32 update_layer;
    kal_uint32 hw_update_layer;
    kal_uint8 image_data_format;            /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    med_frame_enum frame_mode;
    mpl_renderer_3d_mode_enum mode_3d;
    kal_bool force_lcd_hw_trigger;
    kal_uint16 idp_rotate;
    kal_uint32 layer_element;
    kal_uint32 blt_ctx;
    kal_uint32 blt_dev;

    /* Subtitle */
    kal_uint16 subtitle_width;
    kal_uint16 subtitle_height;
    void *subtitle_buffer_p;
    kal_uint8 subtitle_data_format;     
    kal_uint32 subtitle_layer_element;
    kal_uint32 subtitle_blt_ctx;
    kal_uint32 subtitle_blt_dev;
}
media_vid_play_req_struct;

typedef media_vid_play_req_struct media_vid_resume_visual_update_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 seq_num;
}
media_vid_play_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 event;
}
media_vid_decode_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 event;
}
media_vid_edt_encode_event_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_bool stop_preview;
}
media_vid_pause_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_vid_resume_req_struct;

typedef struct
{
    kal_uint64 stop_time;
}
media_vid_stop_time_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_vid_check_med_ready_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 get_frame;
    kal_uint32 frame_num;
    kal_uint64 time;
    kal_uint16 display_width;
    kal_uint16 display_height;
    void *image_buffer_p;
    kal_uint8 blocking;
    kal_uint16 seq_num;
    kal_bool force_seek;
    med_track_enum seek_track; /* Only for streaming currently */
    kal_int16 idp_rotate;

    kal_uint8 image_data_format;            /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    med_frame_enum frame_mode;
}
media_vid_seek_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 display_width;
    kal_uint16 display_height;
    void *image_buffer_p;
    kal_int16 idp_rotate;
    kal_uint8 image_data_format;
    med_frame_enum frame_mode;
    mpl_renderer_3d_mode_enum mode_3d;
    /* Subtitle*/
    kal_uint16 subtitle_width;
    kal_uint16 subtitle_height;
    void *subtitle_buffer_p;
    kal_uint8 subtitle_data_format;
}
media_vid_get_frame_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 seq_num;
}
media_vid_seek_done_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void *image_buffer_p;
    kal_uint32 image_buffer_size;
}
media_vid_snapshot_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint64 *cur_time_p;
}
media_vid_get_play_time_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_vid_alloc_limited_avi_res_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
}
media_vid_free_limited_avi_res_req_struct;


/**************************/
/*      Video Editor      */
/**************************/
typedef enum
{
    MED_VID_EDT_RES_TYPE_IMAGE,
    MED_VID_EDT_RES_TYPE_VIDEO,

    /* add before this */
    MED_VID_EDT_RES_TYPE_TOTAL
} media_vid_edt_res_type_enum;

typedef struct
{
    kal_bool    is_use;                 /* use this layer or not */
	kal_bool 	source_key_enable;		/* enable/disable source key for specified layer */
	kal_uint32 	source_key;				/* source key color in RGB565 format for specified layer */
	kal_bool	opacity_enable;			/* enable/disable opacity for specified layer */
	kal_uint8	opacity_value;			/* opacity value for specified layer */
	kal_uint16	offset_x;				/* x axis offset from main window for specified layer */
	kal_uint16	offset_y;				/* y axis offset from main widnow for specified layer */
	kal_uint16	width;					/* layer buffer height of specified layer */
	kal_uint16	height;				    /* layer buffer width of specified layer */
	kal_uint32	frame_buffer_address;	/* frame buffer start address of specified layer */
} media_vid_edt_layer_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;     /* video handle */
}
media_vid_edt_set_active_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 encode_video_width;   /* encode result(dest) width */
    kal_int32 encode_video_height;  /* encode result(dest) height */
    kal_wchar *filename;            /* file name of encoded video */
}
media_vid_edt_enc_open_req_struct;


typedef struct
{
    LOCAL_PARA_HDR

}
media_vid_edt_enc_close_req_struct;



typedef struct
{
    LOCAL_PARA_HDR
    media_vid_edt_res_type_enum resource_type;  /* resource type */

    kal_int32 video_handle;     /* video resource */
    kal_uint8 *img_buf_ptr;     /* image resource - must be RGB565 format */
    kal_uint32 img_buf_size;    /* image buffer size */

    media_vid_edt_layer_struct extra_layer_1;   /* extra layer */
    media_vid_edt_layer_struct extra_layer_2;   /* extra layer */

    kal_uint32 start_time;      /* resource start time */
    kal_uint32 end_time;        /* resource end time */

    kal_bool is_use_bgm;        /* use bgm or not */
    kal_uint32 bgm_start_time;  /* bgm's start time */
    kal_uint32 bgm_end_time;    /* bgm's end time */
}
media_vid_edt_enc_append_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 seq_num;             /* session id */
    kal_wchar *filename;            /* file name of encoded video */
}
media_vid_edt_enc_merge_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
}
media_vid_edt_enc_stop_merge_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 seq_num;
}
media_vid_edt_enc_merge_done_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *data_p;              /* bgm file name or source buffer ptr */
    kal_uint32 data_size;           /* if it is MEDIA_ARRAY, this shoulbe be buffer size */
    kal_uint8 media_mode;           /* media mode */
    kal_uint8 media_type;           /* media type */
    kal_uint64 *aud_duration_p;     /* audio duration of this bgm */
}
media_vid_edt_open_bgm_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
}
media_vid_edt_close_bgm_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *data_p;              /* bgm file name or source buffer ptr */
    kal_uint32 data_size;           /* if it is MEDIA_ARRAY, this shoulbe be buffer size */
    kal_uint8 media_mode;           /* media mode */
    kal_uint8 media_type;           /* media type */
    kal_uint64 *aud_duration_p;     /* audio duration of this bgm */
}
media_vid_edt_open_silence_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
}
media_vid_edt_close_silence_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_bool init;                  /* init or deinit */
}
media_vid_edt_init_req_struct;


/**************************/
/*  Video Progressive DL  */
/**************************/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 *percent_p;
}
media_vid_get_pdl_percent_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint64 *max_time_p;
}
media_vid_get_pdl_max_time_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *file_buf_p;
    kal_uint32 buf_size;
}
media_vid_check_is_pdl_req_struct;


#define MEDIA_VID_MAX_CONTENT_DESC_LEN  80

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint64 duration;
    kal_uint64 vid_duration;
    kal_uint64 aud_duration;
    kal_uint32 width;
    kal_uint32 height;
    kal_uint32 audio_channel_num;
    kal_uint32 audio_sampling_rate;
    kal_uint8  track_info;
    kal_int32 file_handle;
    kal_uint32 aud_format;
    const void* sdp;
}
media_vid_get_media_info_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 audio_start_frame_num;
}
media_vid_play_restart_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
}
media_vid_audio_play_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 device;
}
media_vid_set_display_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
}
media_vid_pause_visual_update_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_vid_update_blt_pause_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 layer_element;
    kal_uint32 blt_ctx;
    kal_uint32 blt_dev;

    kal_uint8 ui_rot_angle;                         /* MM_IMAGE_ROTATE_ENUM */
    kal_uint8 image_data_format;                    /* MM_IMAGE_FORMAT_ENUM */
    kal_uint32 frame_buffer_addr1;
    kal_uint32 frame_buffer_addr2;
    kal_uint32 frame_buffer_size;
    kal_uint16 image_width;
    kal_uint16 image_height;

    kal_uint16 buffer_width;            /* preview buffer width */
    kal_uint16 buffer_height;           /* preview buffer height */
    kal_uint16 preview_width;           /* preview width */
    kal_uint16 preview_height;          /* preview height */
    kal_uint16 preview_offset_x;        /* preview offset_x from lcd_offset_x */
    kal_uint16 preview_offset_y;        /* preview offset_y from lcd_offset_y */
    kal_uint8 lcd_id;                   /* lcd id */
    kal_bool lcd_update;                /* update lcd or not */
}
media_vid_update_blt_resume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 param_id;
    void *value;
}
media_vid_set_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 param_id;
    void *value;
}
media_vid_get_param_req_struct;

typedef struct
{
    kal_uint8 *buf_ptr;
    kal_uint32 buf_size;
}
media_vid_param_scramble_buffer_struct;

    
/* Web camera */

typedef struct
{
    kal_uint16 width;
    kal_uint16 height;
    kal_uint8 *start_addr;
    kal_uint32 size;
}
webcam_default_jpeg_file_info;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 cam_id;
}media_webcam_set_camera_id_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 rotate;
    kal_uint16 banding;
    kal_uint16 seq_num; /* sequence num */
    kal_uint16 app_id;
}
media_webcam_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 seq_num; /* sequence num */
    kal_bool camera_workable;
}
media_webcam_start_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 seq_num;  /* sequence num */
}
media_webcam_abort_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_webcam_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    webcam_default_jpeg_file_info *file_info;
    kal_uint8 no_of_jpeg_files;
}
media_webcam_pause_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 rotate;
}
media_webcam_resume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_webcam_capture_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 rotate;
}
media_webcam_rotate_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 event;
}
media_webcam_encode_req_struct;


/* TV out */

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 tv_output_mode;
    kal_uint8 tv_output_format;
    kal_uint16 tv_output_width;     /* image width for TV output */
    kal_uint16 tv_output_height;    /* image height for TV output */
}
media_tvo_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_tvo_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 tv_output_mode;
    kal_uint8 tv_output_format;
    kal_uint16 tv_output_width;     /* image width for TV output */
    kal_uint16 tv_output_height;    /* image height for TV output */
    kal_bool    tv_output_vertical_filter;
}
media_tvo_set_mode_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
}
media_tvo_tv_connect_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
}
media_tvo_av_cable_detect_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 type;
    kal_uint8 para;
}
media_tvo_set_param_req_struct;

/* MMA */

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handler;
    kal_wchar* file_path;
    kal_uint8 *data;
    kal_int32 size;
    kal_uint16 app_id;
    kal_int16 repeats;
    kal_uint8 media_type;
    kal_bool progressive_dl; /* Is a progressive download file */
    kal_uint8 output_path;
}
media_mma_open_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handler;
    kal_wchar* file_path;
    kal_uint8 *data;
    kal_int32 size;
    kal_uint16 app_id;
    kal_int16 repeats;
    kal_uint8 media_type;
    kal_bool progressive_dl; /* Is a progressive download file */
    kal_uint8 output_path;
    void *user_data;
}
media_mma_open_async_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 result;
    kal_int32 handle;
    void *user_data;
}
media_mma_open_async_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 *cache_tbl;
}
media_mma_set_cache_table_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 media_type;
}
media_mma_close_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 param_type;
    void *param_value;
}
media_mma_set_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool turn_on;
}
media_mma_build_BLISRC_table_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 media_type;
}
media_mma_play_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 media_type;
}
media_mma_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 media_type;
}
media_mma_pause_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 media_type;
}
media_mma_resume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_wchar* file_path;
    kal_uint8* data;
    kal_uint32 data_len;
    void *audio_info;
    kal_uint16 app_id;
    kal_uint8 media_type;
}
media_mma_get_audio_info_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 media_type;
    kal_bool use_default_handle;
}
media_mma_get_duration_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 media_type;
}
media_mma_get_current_time_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_int32 start_time;
    kal_uint8 media_type;
}
media_mma_set_start_time_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_int32 stop_time;
    kal_uint8 media_type;
}
media_mma_set_stop_time_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 media_type;
}
media_mma_get_volume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 media_type;
    kal_uint8 volume;
}
media_mma_set_volume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_int32 rate;
    kal_uint8 media_type;
}
media_mma_set_rate_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_int32 tempo;
    kal_uint8 media_type;
}
media_mma_set_tempo_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_int32 pitch;
    kal_uint8 media_type;
}
media_mma_set_pitch_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 *buf;
    kal_uint16 len;
    kal_uint8 media_type;
}
media_mma_send_long_msg_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 media_type;
    kal_uint8 type;
    kal_uint8 data1;
    kal_uint8 data2;
}
media_mma_send_short_msg_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handler;
    kal_uint8 *data;
    kal_int32 size;
    kal_int16 repeats;
    kal_uint8 media_type;
    kal_bool fast_pass;
}
media_mma_open_device_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 media_type;
}
media_mma_close_device_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 media_type;
    kal_uint8 channel;
    kal_uint8 level;
}
media_mma_set_channel_volume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 media_type;
    kal_uint8 channel;
    kal_uint8 bank;
    kal_uint8 program;
}
media_mma_set_program_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 *data;
    kal_int32 size;
    kal_int16 repeats;
    kal_uint8 media_type;
}
media_mma_set_data_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_int32* pitch_p;
    kal_uint8 media_type;
}
media_mma_get_pitch_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 media_type;
    kal_int32* max_rate_p;
    kal_int32* min_rate_p;
}
media_mma_get_rate_range_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_int32* rate_p;
    kal_uint8 media_type;
}
media_mma_get_rate_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_int32* tempo_p;
    kal_uint8 media_type;
}
media_mma_get_tempo_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8* volume_p;
    kal_uint8 media_type;
    kal_uint8 channel;
}
media_mma_get_channel_volume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_int16* bank_p;
    kal_int8* program_p;
    kal_uint8 media_type;
    kal_uint8 channel;
}
media_mma_get_program_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_bool* is_bank_support_p;
    kal_uint8 media_type;
}
media_mma_get_is_bank_support_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_bool* is_sp_midi_p;
    kal_uint8 media_type;
}
media_mma_get_is_sp_midi_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    const kal_int16** buf_p;
    kal_int16* len_p;
    kal_uint8 media_type;
    kal_bool custom;
}
media_mma_get_bank_list_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    const kal_int8** buf_p;
    kal_int16* len_p;
    kal_int16 bank;
    kal_uint8 media_type;
}
media_mma_get_program_list_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    const kal_uint8** name_p;
    kal_int16 bank;
    kal_uint8 media_type;
    kal_int8 program;
}
media_mma_get_program_name_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    const kal_uint8** name_p;
    kal_int16 bank;
    kal_uint8 media_type;
    kal_int8 program;
    kal_int8 key;
}
media_mma_get_key_name_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 media_type;
    kal_bool  is_finish;
}
media_mma_pdl_write_data_ind_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint32 cache_sec;
    kal_uint32* percent;
}
media_mma_pdl_get_buf_percent_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 event;
}
media_mma_play_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 event;
}
media_mma_process_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint16 player_id;
    kal_uint16 seq_id;
    kal_uint8 result;
}
media_mma_callback_ind_struct;

/* VR related messages */
typedef struct
{
    kal_uint8 mode;
    kal_uint8 language;
    LOCAL_PARA_HDR
}
media_vr_get_version_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 *sim;
    kal_int16 *diff;
    kal_int16 *rej;
    kal_uint8 mode;
    kal_uint8 language;
}
media_vr_get_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 sim;
    kal_int16 diff;
    kal_int16 rej;
    kal_uint8 mode;
    kal_uint8 language;
}
media_vr_set_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint16 app_id;
    kal_uint8 mode;
    kal_uint8 language;
    kal_uint8 group_id;
}
media_vr_init_rcg_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_int32 result;
    kal_uint16 id_length;
    kal_uint16 id_array[VR_MAX_RCG_RESULT_NUM];
}
media_vr_rcg_result_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint16 app_id;
    kal_uint16 word_id;
    kal_uint8 mode;
    kal_uint8 language;
    kal_uint8 group_id;
}
media_vr_init_trn_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_int32 result;
}
media_vr_trn_result_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint8 seq_no;
}
media_vr_voice_in_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_int32 result;
}
media_vr_voice_in_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 word_id;
    kal_uint8 mode;
    kal_uint8 language;
    kal_uint8 group_id;
}
media_vr_del_tag_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 word_id;
    kal_uint8 mode;
    kal_uint8 language;
    kal_uint8 group_id;
}
media_vr_check_tag_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 *id_length_p;
    kal_uint16 *id_array;
    kal_uint8 mode;
    kal_uint8 language;
    kal_uint8 group_id;
}
media_vr_sync_db_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 word_id;
    kal_uint16 identifier;
    kal_uint8 mode;
    kal_uint8 language;
    kal_uint8 group_id;
}
media_vr_play_tag_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 *folder_name;
    kal_uint8 mode;
    kal_uint8 language;
    kal_uint8 group_id;
}
media_vr_get_dir_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 id_length;
    kal_uint16 id_array[VR_MAX_ADD_ONCE_NUM];
    kal_uint8 mode;
    kal_uint8 language;
    kal_uint8 group_id;
}
media_vr_add_tag_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_vr_abort_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
}
media_vr_abort_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 device;
}
media_aud_set_headset_mode_output_path_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 app_id;
} media_vrsi_init_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint8 *grammar;
    kal_uint16 **name_list;
    kal_int32 *long_list;
    kal_uint8 *is_name_list;
    kal_uint16 *id_list;
    kal_uint16 tag_num;
} media_vrsi_add_tags_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint8 *grammar;
    kal_uint16 *tag_name;
    kal_int32 tag_long;
    kal_uint8 lang;
} media_vrsi_start_trn_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint8 pmp_mode;
} media_vrsi_trn_prompt_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint16 tag_id;
} media_vrsi_trn_result_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint8 *grammar;
    kal_uint16 limit;
    kal_uint8 lang;
} media_vrsi_start_rcg_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint8 pmp_mode;
} media_vrsi_rcg_prompt_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint16 res_type;
} media_vrsi_rcg_result_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint8 proc_type;
} media_vrsi_process_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint8 *grammar;
    kal_uint16 tag_id;
    kal_uint8 volume;
    kal_uint8 output_path;
} media_vrsi_play_tag_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint16 *text;
    kal_uint8 volume;
    kal_uint8 output_path;
    kal_uint8 lang;
} media_vrsi_play_tts_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *grammar;
    kal_int32 *tag_num;
} media_vrsi_get_tagnum_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *grammar;
    kal_int32 tag_num;
    kal_uint16 *id_list;
    kal_uint16 **name_list;
    kal_int32 *long_list;
} media_vrsi_get_taginfo_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *grammar;
    kal_int32 tag_num;
    kal_uint16 *id_list;
} media_vrsi_del_tags_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *grammar;
} media_vrsi_reset_tags_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *grammar;
    kal_int32 tag_num;
    kal_uint16 *id_list;
    kal_uint16 **name_list;
    kal_uint8 *sync_flag;
} media_vrsi_sync_db_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
} media_vrsi_abort_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
} media_vrsi_close_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
} media_vrsi_err_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
} media_vrsi_play_tag_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
} media_vrsi_play_tts_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 *id_list;
    kal_uint16 **name_list;
    kal_int32 *long_list;
    kal_uint16 res_type;
    kal_uint16 tag_num;
    kal_int16 pre_cmd;
    kal_int16 post_cmd;
} media_aud_vrsi_cmd_rcg_result_struct;

/*
 *  Sound Effect
 */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *data_p;
    kal_uint32 size;
} media_snd_check_byte_stream_format_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar *file_name_p;
} media_snd_check_file_format_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *data_p;
    kal_int32 size;
    kal_int16 repeats;
    kal_uint16 identifier;
    kal_uint8 volume;
    kal_uint8 output_path;
	kal_uint8 format;
} media_snd_play_byte_stream_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar *file_name_p;
    kal_int16 repeats;
    kal_uint16 identifier;
    kal_uint8 volume;
    kal_uint8 output_path;
} media_snd_play_file_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 snd_handle;
    kal_uint8 src_id;
    kal_uint8 event;
} media_snd_play_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 result;
    kal_uint16 identifier;
} media_snd_play_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 volume;
    kal_uint8 direction;
} media_snd_set_volume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    ctm_param_struct ctm_param;
    kal_uint8 ctm_interface;
} media_ctm_open_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
} media_ctm_open_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
} media_ctm_close_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
} media_ctm_close_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
} media_ctm_connect_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
} media_ctm_connect_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
} media_ctm_connected_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 num_of_char;
    kal_wchar text[CTM_SEND_TEXT_CHAR_MAX_NUM + 1];
} media_ctm_send_text_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
} media_ctm_send_text_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 num_of_char;
    kal_wchar text[CTM_SEND_TEXT_CHAR_MAX_NUM + 1];
} media_ctm_recv_text_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 event;
} media_ctm_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *top_p;
    kal_uint8 *val_p;
} media_aud_get_spectrum_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
} media_aud_start_calc_spectrum_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
} media_aud_stop_calc_spectrum_req_struct;

/*
 *  Audio Post Process
 */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *data_p;
    kal_uint32 size;
    kal_uint16 format;
} media_stretch_check_stream_format_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar *file_path;
} media_stretch_check_file_format_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 speed;
} media_stretch_set_speed_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 mode;
} media_reverb_set_mode_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 mode;
} media_surround_turn_on_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8 magnitude[NVRAM_EF_AUDIO_EQUALIZER_BAND_NUM];
} media_aud_eq_set_magnitude_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 level;
} media_aud_pitch_shifting_set_level_req_struct;


/*
*  General TTS
*/
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 attr_id;
    kal_uint32 attr_value;
} media_aud_tts_set_attr_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 handle;
    kal_uint32 seq_no;
    kal_uint8 data[AUD_TTS_MAX_PROCESS_DATA_SIZE];
    kal_uint8 event;
}media_aud_tts_play_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 *tts_string;
    kal_uint16 str_type;
    kal_uint16 lang;
    kal_uint16 app_type;
    kal_uint16 gander;
    kal_uint16 identifier;
    kal_uint16 app_id;
    kal_uint8  volume;
    kal_uint8  output_path;
    kal_uint8  pitch;
    kal_uint8  speed;
} media_aud_tts_play_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
} media_aud_tts_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
} media_aud_tts_pause_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
} media_aud_tts_resume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 data[AUD_TTS_MAX_PROCESS_DATA_SIZE];
} media_aud_tts_update_info_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 key;
	kal_int32 keyLength;
}
media_aud_kt_process_callback_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 key;
	kal_int32 keyLength;
}
media_aud_kt_detect_ind_struct;

/* ---- bt audio begin ---- */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 connect_id;
    kal_uint8 profile;   /* 0: HFP, 1: A2DP */
    kal_uint8 mode;      /* HFP => 0: Earphone, 1: Car Kit /// A2DP => 0: INT mode, 1: ACP mode, 2: ACP mode for PTS only*/
	void* pContext;
	void* req_context;
} media_bt_audio_open_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 result;
    kal_uint16 error_cause;
    kal_uint8 profile;
} media_bt_audio_open_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 profile;
	kal_uint8 connect_id;
} media_bt_audio_open_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 profile;
} media_bt_audio_close_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 result;
    kal_uint8 profile;
} media_bt_audio_close_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 cause;
    kal_uint8 profile;
	kal_uint8 connect_id;
} media_bt_audio_close_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 profile;
} media_bt_audio_turn_on_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 profile;
} media_bt_audio_turn_off_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 	       mode;
} media_bt_audio_set_sco_mode_req_struct;



/* ---- bt audio end ---- */

#define IN_PROC_CALL_MAX_DATA_LEN  (20)
typedef void (*media_in_proc_call_ext_type) (void* pv_data, kal_uint16 ui2_data_len);
typedef struct
{
    LOCAL_PARA_HDR
    media_in_proc_call_ext_type pf_func;
    kal_uint8  pui1_data[IN_PROC_CALL_MAX_DATA_LEN];
    kal_uint16 ui2_data_len;
} media_in_proc_call_ext_req_struct;


#ifndef __BT_A2DP_CODEC_TYPES__
#define __BT_A2DP_CODEC_TYPES__
typedef struct
{
	kal_uint8 min_bit_pool;
	kal_uint8 max_bit_pool;
	kal_uint8 block_len; // b0: 16, b1: 12, b2: 8, b3: 4
	kal_uint8 subband_num; // b0: 8, b1: 4
	kal_uint8 alloc_method; // b0: loudness, b1: SNR
	kal_uint8 sample_rate; // b0: 48000, b1: 44100, b2: 32000, b3: 16000
	kal_uint8 channel_mode; // b0: joint stereo, b1: stereo, b2: dual channel, b3: mono
} bt_a2dp_sbc_codec_cap_struct;

typedef struct
{
	kal_uint8 layer; // b0: layerIII, b1: layerII, b0: layerI
	kal_bool CRC;
	kal_uint8 channel_mode; // b0: joint stereo, b1: stereo, b2: dual channel, b3: mono
	kal_bool MPF; // is support MPF-2
	kal_uint8 sample_rate; // b0: 48000, b1: 44100, b2: 32000, b3: 24000, b4: 22050, b5: 16000
	kal_bool VBR; // is support VBR
	kal_uint16 bit_rate; // bit-rate index in ISO 11172-3 , b0:0000 ~ b14: 1110
} bt_a2dp_mp3_codec_cap_struct; /* all MPEG-1,2 Audio */


typedef struct
{
	kal_uint8 object_type; // b4: M4-scalable, b5: M4-LTP, b6: M4-LC, b7: M2-LC
	kal_uint16 sample_rate; // b0~b11: 96000,88200,64000,48000,44100,32000,24000,22050,16000,12000,11025,8000
	kal_uint8 channels; // b0: 2, b1: 1
	kal_bool VBR; // is supported VBR
	kal_uint32 bit_rate; // constant/peak bits per second in 23 bit UiMsbf, 0:unknown
} bt_a2dp_aac_codec_cap_struct; /* all MPEG-2,4 AAC */

typedef struct
{
	kal_uint8 version; // 1:ATRAC, 2:ATRAC2, 3:ATRAC3
	kal_uint8 channel_mode; // b0: joint stereo, b1: dual, b2: single
	kal_uint8 sample_rate; // b0: 48000, b1: 44100
	kal_bool VBR; // is supported VBR
	kal_uint32 bit_rate; // bit-rate index in ATRAC, b0: 0x0012 ~ b18: 0x0000
	kal_uint16 max_sul; // sound unit length in 16 bits UiMsbf
} bt_a2dp_atrac_codec_cap_struct; /* all ATRAC family */

typedef union
{
	bt_a2dp_sbc_codec_cap_struct sbc;
	bt_a2dp_mp3_codec_cap_struct mp3;
	bt_a2dp_aac_codec_cap_struct aac;
	bt_a2dp_atrac_codec_cap_struct atrac;
} bt_a2dp_audio_codec_cap_struct;

typedef struct
{
	kal_uint8 codec_type; // SBC, MP3
	bt_a2dp_audio_codec_cap_struct codec_cap;
} bt_a2dp_audio_cap_struct;
#endif /* __BT_A2DP_CODEC_TYPES__ */

typedef struct
{
    LOCAL_PARA_HDR
    bt_a2dp_audio_cap_struct cfg;
    kal_uint32 seq_no;
    kal_uint8 stream_handle;
    kal_bool immediate;
} media_bt_open_codec_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 seq_no;
    kal_uint8 stream_handle;
} media_bt_close_codec_ind_struct;

#ifdef __BT_SPEAKER_SUPPORT__
typedef struct
{
    LOCAL_PARA_HDR
    bt_a2dp_audio_cap_struct cfg;
    kal_uint32 seq_no;
    kal_uint8 stream_handle;
    kal_bool immediate;
} media_bt_open_sink_codec_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 stream_handle;
	kal_uint8 result; //0 means success, others fail
} media_bt_open_sink_codec_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 stream_handle;
	kal_uint8 result; //0 means success, others fail
} media_bt_close_sink_codec_cnf_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 stream_handle;
	kal_uint8 events; //Media_Event in L1audio.h, 3,4,7 means codec stopped
} media_bt_sink_codec_ind_struct;

#endif

#ifdef __LINE_IN_SUPPORT__
typedef struct
{
	LOCAL_PARA_HDR
	kal_bool on; //0: turn off line in, 1: turn off line in
} media_enable_bt_box_linein_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_bool force_use; //0: not force use linein mic, 1: force use line in mic
} media_force_use_linein_mic_req_struct;

#endif

//#ifdef __MEGAPHONE_SUPPORT__
typedef struct
{
	LOCAL_PARA_HDR
	kal_bool on; //0: turn off megaphone, 1: turn in megaphone
} media_enable_megaphone_req_struct;
//#endif


#ifdef __KARAOKE_SUPPORT__
typedef struct
{
	LOCAL_PARA_HDR
	Media_Kara_opt_mode mode; //0 none, 1 play only, 2 record only, 3 play & record
	kal_wchar file_name[MAX_MEDIA_FILE_NAME];  //karaoke record file path, if no record, set it null
} media_set_karaoke_mode_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	Media_KaraRec_Mix_CH channel; //0 none, 1 left, 2 right, 3 both
} media_set_karaoke_channel_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 uNum;
	kal_uint16 uDen;
} media_set_karaoke_digitgain_req_struct;

#ifdef __KARAOKE_NEED_KEEP_SRC_PATH__

typedef struct
{
	LOCAL_PARA_HDR
	kal_wchar rec_path[MAX_MEDIA_FILE_NAME];  //karaoke record file path, if no record, set it null
	kal_uint32 msRecordStartTime;
	kal_uint32 msAudioSeekTime;
} media_karaoke_remix_turn_on_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
} media_karaoke_remix_turn_off_req_struct;


typedef struct
{
	LOCAL_PARA_HDR
	Media_KaraRec_Mix_CH channelMode; //0 none, 1 play only, 2 record only, 3 play & record
} media_karaoke_set_remix_mode_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 audio_gain;
} media_karaoke_set_remix_audio_gain_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 voice_gain;
} media_karaoke_set_remix_voice_gain_req_struct;
#endif /*__KARAOKE_NEED_KEEP_SRC_PATH__*/


#endif

#ifdef __VAD_SUPPORT__
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool on;
	void* param;
} media_switch_vad_on_off_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 level;
} media_set_vad_level_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
} media_vad_detect_ind_struct;
#endif


/*=============================
 * Constants
 *=============================*/

#define MAX_RTP_NUM             (10)
#define MAX_CSRC_NUM            (1)
#define MAX_RR_NUM              (1)
#define MAX_APP_NUM             (2)
#define MAX_RB_NUM              (3)
#define MAX_SDES_CHUNK_NUM      (2)
#define MAX_SDES_ITEM_NUM       (5)
#define MAX_SDES_DATA_LEN       (64)
#define MAX_RTP_HEADER_EXT      (16)
#define MAX_SSRC_IN_RTCP_BYE    (3)
#define MAX_RTCP_BY_LEAVE_LEN   (32)
#define MAX_APP_DATA_LEN        (128)


#define RTP_SUCCESS             (0)
#define RTP_GENERAL_ERROR       (-1)
#define RTP_SOC_WOULD_BLOCK     (-2)
#define RTP_SOC_OTHER_ERROR     (-3)
#define RTP_CONFLICT_SSRC       (-4)
#define RTP_SRTP_AUTH_FAIL      (-5)
#define MAX_RTP_SOCK_ADDR_LEN   28

#define MAX_SRTP_CRYPTO_LEN	    50

/* RTP VoIP extension */

/*=============================
 * Enums
 *=============================*/

typedef enum
{
    RTP_DTMF_TYPE_INBAND,
    RTP_DTMF_TYPE_RFC2833,
    RTP_DTMF_TYPE_TOTAL
} rtp_dtmf_type_enum;

typedef enum
{
    RTP_DTMF_CODE_0,
    RTP_DTMF_CODE_1,
    RTP_DTMF_CODE_2,
    RTP_DTMF_CODE_3,
    RTP_DTMF_CODE_4,
    RTP_DTMF_CODE_5,
    RTP_DTMF_CODE_6,
    RTP_DTMF_CODE_7,
    RTP_DTMF_CODE_8,
    RTP_DTMF_CODE_9,
    RTP_DTMF_CODE_STAR,
    RTP_DTMF_CODE_HASH,
    RTP_DTMF_CODE_TOTAL
} rtp_dtmf_code_enum;

typedef enum
{
    RTCP_SR = 200,
    RTCP_RR,
    RTCP_SDES,
    RTCP_BYE,
    RTCP_APP
} rtcp_type_enum;


typedef enum
{
    RTCP_SR_MASK    = 0x01,
    RTCP_RR_MASK    = 0x02,
    RTCP_SDES_MASK  = 0x04,
    RTCP_BYE_MASK   = 0x08,
    RTCP_APP_MASK   = 0x10
} rtcp_type_mask_enum;


typedef enum
{
    RTCP_SDES_END,
    RTCP_SDES_CNAME,
    RTCP_SDES_NAME,
    RTCP_SDES_EMAIL,
    RTCP_SDES_PHONE,
    RTCP_SDES_LOC,
    RTCP_SDES_TOOL,
    RTCP_SDES_NOTE,
    RTCP_SDES_PRIV,
    RTCP_SDES_TOTAL
} rtcp_sdes_type_enum;

typedef enum
{
    RTP_NOTIFY_NONE,
    RTP_NOTIFY_SOC,
    RTP_NOTIFY_PACKET,
    RTP_NOTIFY_TOTAL
} rtp_notify_type_enum;

typedef enum
{
    RTP_SEND_RTP    = 0x01,
    RTP_RECV_RTP    = 0x02
} rtp_packet_notify_event_enum;

typedef enum
{
    RTP_SOC_NTFY_READ_IND,
    RTP_SOC_NTFY_WRITE_IND,
    RTP_SOC_SEND_RET,
    RTP_SOC_RECV_RET,
    RTCP_SOC_NTFY_READ_IND,
    RTCP_SOC_NTFY_WRITE_IND,
    RTCP_SOC_SEND_RET,
    RTCP_SOC_RECV_RET,
    RTCP_SOC_TOTAL
} rtp_soc_notify_type_enum;

typedef enum
{
    SRTP_ENCRYPT_RTP    = 0X01,
    SRTP_ENCRYPT_RTCP   = 0X02,
    SRTP_AUTH_RTP       = 0x04,
    SRTP_AUTH_RTCP      = 0x08,
    SRTP_METHOD_DEFAULT = 0X0F
} rtp_srtp_method_enum;

typedef enum
{
    SRTP_CRYPTO_NONE,
    SRTP_CRYPTO_AES_CM_128_HMAC_SHA1_80,
    SRTP_CRYPTO_AES_CM_128_HMAC_SHA1_32,
    SRTP_CRYPTO_F8_128_HMAC_SHA1_80,
    SRTP_CRYPTO_TOTAL
} rtp_srtp_crypto_suites_enum;

typedef enum
{
    SRTP_FEC_ORDER_NONE,
    SRTP_FEC_ORDER_FEC_SRTP,
    SRTP_FEC_ORDER_SRTP_FEC,
    SRTP_FEC_ORDER_TOTAL
} rtp_srtp_fec_order_enum;

typedef enum
{
    VOIP_IDLE           = 0x00,
    VOIP_ENCODE         = 0x01,
    VOIP_DECODE         = 0x02,
    VOIP_ENCODE_DECODE  = 0x03
} voip_status_enum;

typedef enum
{
    VOIP_CODEC_NONE     = 0x0000,
    VOIP_CODEC_AMR      = 0x0001,
    VOIP_CODEC_G729     = 0x0002,
    VOIP_CODEC_G7231    = 0x0004,
    VOIP_CODEC_G726_16  = 0x0008,
    VOIP_CODEC_G726_24  = 0x0010,
    VOIP_CODEC_G726_32  = 0x0020,
    VOIP_CODEC_G726_40  = 0X0040,
    VOIP_CODEC_PCMA     = 0X0080,
    VOIP_CODEC_PCMU     = 0X0100,
    VOIP_CODEC_CN                   = 0X0200,
    VOIP_CODEC_G729_ANNEXB_PRESENT  = 0x0400,
    VOIP_CODEC_G729_ANNEXB          = 0x0800,
    VOIP_CODEC_G7231_ANNEXA_PRESENT = 0x1000,
    VOIP_CODEC_G7231_ANNEXA         = 0x2000
}voip_codec_enum;


typedef enum
{
    VOIP_AMR_IDX_0  = 0x01,
    VOIP_AMR_IDX_1  = 0x02,
    VOIP_AMR_IDX_2  = 0x04,
    VOIP_AMR_IDX_3  = 0x08,
    VOIP_AMR_IDX_4  = 0x10,
    VOIP_AMR_IDX_5  = 0x20,
    VOIP_AMR_IDX_6  = 0x40,
    VOIP_AMR_IDX_7  = 0x80,
    VOIP_AMR_IDX_8  = 0xFF
} voip_amr_idx_enum;

typedef enum
{
    VOIP_G7231_RATE_0530 = 1,
    VOIP_G7231_RATE_0630 = 2
} voip_g7231_rate_enum;

typedef enum
{
    VOIP_RTP_DISCONNECT_NONE,
    VOIP_RTP_DISCONNECT_NO_RTP_PKT_WARNING,
    VOIP_RTP_DISCONNECT_NO_RTP_PKT_DISCONNECT,
    VOIP_RTP_DISCONNECT_HIGH_ERR_RATE,
    VOIP_RTP_DISCONNECT_ICMP_UNREACHABLE,
    VOIP_RTP_DISCONNECT_TOTAL
} voip_rtp_disconnect_type_enum;


/*=============================
 * structs
 *=============================*/

typedef struct
{
    kal_uint32  ssrc;
    kal_uint8   fraction_lost;
    kal_int16   cumul_packet_lost;
    kal_uint32  last_sequence;
    kal_uint32  jitter;
    kal_uint32  lsr;
    kal_uint32  dlsr;
} rtcp_info_rb_struct;


typedef struct
{
    kal_uint32  ssrc;
    kal_uint32  ntp_timestamp_m;
    kal_uint32  ntp_timestamp_l;
    kal_uint32  rtp_timestamp;
    kal_uint32  packet_sent;
    kal_uint32  octet_sent;
    kal_uint8   no_report_block;
    rtcp_info_rb_struct report_block[MAX_RB_NUM];
} rtcp_info_sr_struct;


typedef struct
{
    kal_uint32  ssrc;
    kal_uint8   no_report_block;
    rtcp_info_rb_struct report_block[MAX_RB_NUM];
} rtcp_info_rr_struct;


typedef struct
{
    kal_uint8   type;
    kal_uint8   no_data;
    kal_uint8   data[MAX_SDES_DATA_LEN];
} rtcp_info_sdes_item_struct;


typedef struct
{
    kal_uint32  ssrc;
    kal_uint8   No_item;
    rtcp_info_sdes_item_struct  Item[MAX_SDES_ITEM_NUM];
} rtcp_info_sdes_chunk_struct;


typedef struct
{
    kal_uint8   no_chunk;
    rtcp_info_sdes_chunk_struct chunk[MAX_SDES_CHUNK_NUM];
} rtcp_info_sdes_struct;



typedef struct
{
    kal_uint32  ssrc;
    kal_uint8   sub_type;
    kal_uint8   name[4];
    kal_uint8   no_data;
    kal_uint8   data[MAX_APP_DATA_LEN];
} rtcp_info_app_struct;


typedef struct
{
    kal_uint32  ssrc[MAX_SSRC_IN_RTCP_BYE];
    kal_uint8   no_ssrc;
    kal_uint8   no_leave_reason;
    kal_uint8   leave_reason[MAX_RTCP_BY_LEAVE_LEN];
} rtcp_info_bye_struct;


typedef struct
{
    kal_uint8   marker;
    kal_uint8   payload_type;
    kal_uint8   no_csrc;
    kal_uint32  csrc[MAX_CSRC_NUM] ;
    kal_uint16  seq_number;
    kal_uint32  time_stamp;
    kal_uint32  ssrc;
    kal_uint8   ext_avaliable;
    kal_uint8   ext[MAX_RTP_HEADER_EXT];
    kal_uint32  rtp_header_len;
} rtp_info_struct;


typedef struct
{
    kal_uint8               valid_packet_mask;
    rtcp_info_sr_struct     sr;
    rtcp_info_sdes_struct   sdes;
    rtcp_info_bye_struct    bye;
    kal_uint8               no_rr;
    rtcp_info_rr_struct     rr[MAX_RR_NUM];
    kal_uint8               no_app;
    rtcp_info_app_struct    app[MAX_APP_NUM];
} rtcp_info_struct;


typedef struct
{
    kal_uint8   crypto_suite;                           //rtp_srtp_crypto_suites_enum
    kal_uint8   send_key_n_salt[MAX_SRTP_CRYPTO_LEN];   //NULL termination
    kal_uint8   recv_key_n_salt[MAX_SRTP_CRYPTO_LEN];   //NULL termination
    kal_uint8   lifetime_available;                     //KAL_TRUE / KAL_FALSE
    kal_uint64  lifetime;
    kal_uint8   KDR_available;                          //KAL_TRUE / KAL_FALSE
    kal_uint8   KDR;                                    //(2^64, KDR = 64)
    kal_uint8   MKI_available;                          //KAL_TRUE / KAL_FALSE
    kal_uint8   MKI_len;
    kal_uint8   MKI;
    kal_uint8   FEC_order;                              //rtp_srtp_fec_order_enum
    kal_uint16  FEC_key_len;                            //reserved
    kal_uint8*  FEC_key;                                //reserved
    kal_uint8   crypt_auth_mask;                        //rtp_srtp_method_enum
    kal_uint8   WSH_available;                          //KAL_TRUE / KAL_FALSE
    kal_uint16  WSH;
} srtp_crypto_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32  nwk_account_id;
    kal_uint8   local_ip[MAX_RTP_SOCK_ADDR_LEN];
    kal_uint8   remote_ip[MAX_RTP_SOCK_ADDR_LEN];
    kal_uint16  remote_rtp_port;
    kal_uint16  remote_rtcp_port;
    kal_uint16  local_rtp_port;
    kal_uint16  local_rtcp_port;
    kal_uint8   soc_qos_param;
} med_rtp_create_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
} med_rtp_close_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   remote_ip[MAX_RTP_SOCK_ADDR_LEN];
    kal_uint16  remote_rtp_port;
    kal_uint16  remote_rtcp_port;
} med_rtp_set_remote_addr_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   soc_enable;
    kal_uint8   packet_enable;
    kal_uint8   packet_mask;
} med_rtp_set_notify_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   soc_enable;
    kal_uint8   packet_enable;
    kal_uint8   packet_mask;
} med_rtp_clear_notify_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   *payload;
    kal_uint32  payload_len;
	kal_uint32  timestamp;
	kal_bool fgFrameEnd;
} med_rtp_send_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   *buffer;
    kal_int32   buffer_size;
    rtp_info_struct *param;
} med_rtp_recv_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   packet_mask;
    kal_uint32  ssrc;
    kal_uint8   no_app;
    rtcp_info_app_struct *app;
} med_rtp_send_rtcp_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    rtcp_info_struct *rtcp_info;
} med_rtp_recv_rtcp_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   mask;               /* rtp_set_value_mask_enum */
    kal_uint32  timestamp;
    kal_uint32  seqnumber;
    kal_uint8   payload_type;
    kal_uint8   sdes_type;
    kal_uint8   no_sdes_data;
    kal_uint8   *sdes_data;
    kal_uint8   dtmf_payload_type;
} med_rtp_set_value_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint16  *seqnumber;
    kal_uint32  *ssrc;
} med_rtp_get_value_req_struct;

#ifdef __STREAM_SERVER_SUPPORT__
typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint16  *seqnumber;
	kal_uint32  *timestamp;
} med_rtp_get_first_packet_info_struct;
#endif
typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   dtmf_code;
    kal_uint8   send_type;
} med_rtp_send_dtmf_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
} med_rtp_send_dtmf_stop_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   crypto_suite;                           //rtp_srtp_crypto_suites_enum
    kal_uint8   send_key_n_salt[MAX_SRTP_CRYPTO_LEN];   //NULL termination
    kal_uint8   recv_key_n_salt[MAX_SRTP_CRYPTO_LEN];   //NULL termination
    kal_uint8   lifetime_available;                     //KAL_TRUE / KAL_FALSE
    kal_uint64  lifetime;
    kal_uint8   KDR_available;                          //KAL_TRUE / KAL_FALSE
    kal_uint8   KDR;                                    //(2^64, KDR = 64)
    kal_uint8   MKI_available;                          //KAL_TRUE / KAL_FALSE
    kal_uint8   MKI_len;
    kal_uint8   MKI;
    kal_uint8   FEC_order;                              //rtp_srtp_fec_order_enum
    kal_uint16  FEC_key_len;                            //reserved
    kal_uint8*  FEC_key;                                //reserved
    kal_uint8   crypt_auth_mask;                        //rtp_srtp_method_enum
    kal_uint8   WSH_available;                          //KAL_TRUE / KAL_FALSE
    kal_uint16  WSH;
} med_rtp_check_srtp_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    srtp_crypto_struct *srtp_crypto;
} med_rtp_get_srtp_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   crypto_suite;                           //rtp_srtp_crypto_suites_enum
    kal_uint8   send_key_n_salt[MAX_SRTP_CRYPTO_LEN];   //NULL termination
    kal_uint8   recv_key_n_salt[MAX_SRTP_CRYPTO_LEN];   //NULL termination
    kal_uint8   lifetime_available;                     //KAL_TRUE / KAL_FALSE
    kal_uint64  lifetime;
    kal_uint8   KDR_available;                          //KAL_TRUE / KAL_FALSE
    kal_uint8   KDR;                                    //(2^64, KDR = 64)
    kal_uint8   MKI_available;                          //KAL_TRUE / KAL_FALSE
    kal_uint8   MKI_len;
    kal_uint8   MKI;
    kal_uint8   FEC_order;                              //rtp_srtp_fec_order_enum
    kal_uint16  FEC_key_len;                            //reserved
    kal_uint8*  FEC_key;                                //reserved
    kal_uint8   crypt_auth_mask;                        //rtp_srtp_method_enum
    kal_uint8   WSH_available;                          //KAL_TRUE / KAL_FALSE
    kal_uint16  WSH;
} med_rtp_set_srtp_param_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint16  codec_type;
    kal_uint16  modeset;
} med_voip_init_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
} med_voip_encoding_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
} med_voip_encoding_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
} med_voip_decoding_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
} med_voip_decoding_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   *voip_state;
    kal_uint16  *codec_type;
    kal_uint16  *ptime;
    kal_uint16  *maxptime;
    kal_uint16  *modeset_mask;
} med_voip_get_value_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_uint8   voip_set_value_mask;
    kal_uint16  ptime;
    kal_uint16  maxptime;
    kal_uint16  modeset_mask;
} med_voip_set_value_req_struct;


typedef struct {
   kal_uint8    amr_modeset;    /* voip_amr_idx_enum */
   kal_uint8    g7231_rate;     /* voip_g7231_rate_enum */
} med_voip_codec_cap_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   require_type;                   /* voip_status_enum */
    kal_uint16  *codec_type;                    /* voip_codec_enum */
    med_voip_codec_cap_struct   *codec_details;
} med_voip_get_codec_cap_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
} med_voip_mixer_add_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
} med_voip_mixer_remove_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8    event_type;    /* voip_rtp_disconnect_type_enum */
} med_voip_rtp_disconnect_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8    rtp_handle;
    kal_int32   result;
    kal_uint32  ssrc;
    kal_uint8   notify_type;    /* rtp_notify_type_enum */
    kal_uint8   event_type;     /* rtp_packet_notify_event_enum / rtp_soc_notify_type_enum */
} med_rtp_notify_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32  event;
    void        *handle;
    void        *host_data;
} med_voip_l1_encoding_callback_ind_struct;


/* Constants */
#define STREAM_MAX_TITLE_LEN        32
#define MED_MAX_LINK_PATH_LEN 520       /* 512 + NULL terminator */
#define MED_MAX_IP_LEN 4
#define MED_MAX_PROXY_ADDR_LEN (63)
#define STREAM_BUFFER_PRE_DL_LEN    (5000)
#define STREAM_BUFFER_MIN_PRE_DL_LEN    (3000)        /* 3000 ms buffer len, */

/* Enums */
typedef enum
{
    MEDIA_STREAM_RTP_CONNECT_TYPE_UDP,
    MEDIA_STREAM_RTP_CONNECT_TYPE_TCP
} media_stream_rtp_connect_type_enum;

typedef enum
{
    MEDIA_STREAM_CONN_TYPE_NONE,
    MEDIA_STREAM_CONN_TYPE_RTSP_URL,
    MEDIA_STREAM_CONN_TYPE_SDP_FILE
} media_stream_conn_type_enum;

typedef enum
{
    MEDIA_STREAM_MEDIA_TYPE_NONE    = 0,
    MEDIA_STREAM_MEDIA_TYPE_AUDIO   = 0x01,
    MEDIA_STREAM_MEDIA_TYPE_VIDEO   = 0x02
} media_stream_media_type_enum;

typedef enum
{
    MEDIA_STREAM_PLAY_TYPE_BOTH,
    MEDIA_STREAM_PLAY_TYPE_AUDIO_ONLY,
    MEDIA_STREAM_PLAY_TYPE_VIDEO_ONLY,
    MEDIA_STREAM_PLAY_TYPE_NONE
} media_stream_play_type_enum;

/* Structures */

typedef struct
{
    kal_uint16  image_width;
    kal_uint16  image_height;
    kal_uint64  total_time;
    kal_uint32  sampleing_freq;
    kal_uint8   channel_num;
    kal_uint8   media_format;               /* Media_Format enum in l1audio.h */
} media_stream_get_info_struct;

typedef struct
{
    kal_uint8 media_mode;
    kal_uint8 media_type;
    void *data;
    kal_uint16 display_width;
    kal_uint16 display_height;
    void *image_buffer_p;

    kal_int16 zoom_factor;
    kal_int16 frame_rate;

    kal_int16 play_speed;
    kal_uint8 play_audio;
    kal_uint8 display_device;
    kal_uint8 audio_path;
    kal_uint16 seq_num;
    kal_uint16 repeats;                     /* repeat count, 0xffff: infinite */

    kal_uint8 lcd_id;
    kal_uint32 update_layer;
    kal_uint32 hw_update_layer;
    kal_uint8 image_data_format;            /* IMGDMA_IBW_OUTPUT_RGB565 or IMGDMA_IBW_OUTPUT_RGB888 */
    med_frame_enum frame_mode;
    mpl_renderer_3d_mode_enum mode_3d;

    kal_bool force_lcd_hw_trigger;
    kal_int16 idp_rotate;
    kal_uint32 layer_element;
    kal_uint32 blt_ctx;
    kal_uint32 blt_dev;

} media_stream_set_info_struct;

typedef struct
{
    kal_uint32  param_id;
    kal_int16   value;
} media_stream_set_param_struct;

typedef enum
{
    STREAM_PARAM_GET_INFO     = 0,
    STREAM_PARAM_BUF_STATUS   = 1
} media_stream_param_type_enum;

typedef struct
{
    kal_uint64 buffered_time;
    kal_uint32 buffer_percentage;
} media_stream_param_buf_status_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   *session_id;
    kal_uint16 app_id;
} media_stream_init_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
    kal_uint16  request_id;
    kal_uint32  net_id;
    kal_uint8   type;                               /* media_stream_conn_type_enum */
    kal_wchar*  link_path;
    kal_bool    use_proxy;
    kal_uint8   proxy_addr[MED_MAX_PROXY_ADDR_LEN];
    kal_uint16  proxy_port;
    kal_uint16  lowest_udp_port;
    kal_uint16  highest_udp_port;

    mpl_scenario_enum scenario;
    kal_uint16  prefer_transport;                   /* stream_rtp_connect_type_t */

} media_stream_connect_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
    kal_uint8   abort_type;
} media_stream_abort_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
} media_stream_force_abort_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
    kal_uint64  stop_time;
} media_stream_set_stop_time_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 session_id;
    kal_uint8 elapse_ticks;
    kal_uint8 sleep_ticks;
} media_stream_set_sleep_time_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
    kal_uint16  request_id;
    kal_uint64  start_time;
    kal_uint32  prebuffer_time;
} media_stream_seek_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
} media_stream_get_dl_percentage_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
    kal_uint16   request_id;
} media_stream_play_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
} media_stream_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
} media_stream_disconnect_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
} media_stream_deinit_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
    kal_uint8   type;   /* stream_param_type_enum */
    void*       param;
} media_stream_get_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 session_id;
    media_stream_set_info_struct    info;
} media_stream_set_info_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 session_id;
    kal_uint16 level;
} media_stream_set_audio_level_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 session_id;
} media_stream_switch_screen_videostop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 session_id;
} media_stream_switch_screen_videostart_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 session_id;
    media_stream_set_param_struct    param;
} media_stream_set_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
    kal_uint64 *playing_time;
} media_stream_get_playing_time_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32   result;     /* med_result_enum */
    kal_uint8   session_id;
    kal_uint16   request_id;
    kal_uint8   type_mask;  /* media_stream_media_type_enum */
    kal_uint8   seekable;   /* kal_true , kal_false */
    kal_uint64  media_len;
    kal_uint64  media_bw;
    kal_uint8   title[STREAM_MAX_TITLE_LEN];
    kal_int32   pdcf_handle;        /* DRM pdcf handle if (is_DRM_pdcf == kal_true) */
    kal_uint8   is_DRM_pdcf;        /* kal_true, kal_false */
    kal_uint8   rec_allowed;
    kal_uint8   fw_allowed;
} media_stream_connected_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   type_mask;  /* media_stream_media_type_enum */
    kal_uint32   event;
} media_stream_l1_callback_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32   result;     /* med_result_enum */
    kal_uint8   session_id;
    kal_uint16   request_id;
} media_stream_seek_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32   result;     /* med_result_enum */
    kal_uint8   session_id;
    kal_uint16   request_id;
} media_stream_play_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8   session_id;
} media_stream_bgplay_videostop_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 session_id;
    kal_uint8 play_style;    /* media_stream_play_type_enum */
    kal_uint8 a_track_no;   /* not using now */
    kal_uint8 v_track_no;   /* not using now */
} media_stream_set_track_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 session_id;
    kal_wchar* p_filepath;
} media_stream_rec_open_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 session_id;
} media_stream_rec_close_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 session_id;
    kal_wchar* p_filename;
} media_stream_rec_save_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 result;
    kal_uint8 session_id;
} media_stream_rec_save_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 session_id;
} media_stream_rec_save_abort_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8  type_mask;
    /* buffer header */
    kal_uint8  *p_buffer;
    kal_uint32 buff_size;
    kal_uint64 time_stamp;
    kal_uint32 flags;
    void       *p_private_data;
    void       *p_user_data;
}media_stream_l1_putframe_callback_ind_struct;

/**
  * @defgroup MTV_SAP
  * @{
  */

/**
  * Valid configurations.
  */
typedef enum
{
    MEDIA_MTV_CONFIG_VIDEO  = 0x00000001,   /**< video configuration */
    MEDIA_MTV_CONFIG_AUDIO  = 0x00000002,   /**< audio configuration */
    MEDIA_MTV_CONFIG_RECORD = 0x00000004    /**< record configuration */
} media_mtv_config_enum;

/**
  * System events.
  */
typedef enum
{
    MEDIA_MTV_SYSTEM_OPENED = 0,                /**< the system is opened */
    MEDIA_MTV_SYSTEM_CLOSED,                    /**< the system is closed */
    MEDIA_MTV_SYSTEM_FATAL_ERROR,               /**< fatal error. For example, hardware function is not available */
    MEDIA_MTV_SYSTEM_BAD_RECEPTION = 10,        /**< the signal reception is bad */
    MEDIA_MTV_SYSTEM_GOOD_RECEPTION,            /**< the signal reception is good */
    MEDIA_MTV_SYSTEM_DATE_TIME = 20,            /**< gives information relating to the present time and date */
    MEDIA_MTV_SYSTEM_EMERGENCY_MSG = 30,        /**< new emergency message is available */
    MEDIA_MTV_SYSTEM_ESG_NEW_AVAILABLE = 40,    /**< new ESG is available */
    MEDIA_MTV_SYSTEM_ESG_DOWNLOADED,            /**< ESG is downloaded */
    MEDIA_MTV_SYSTEM_ESG_UPDATED,               /**< ESG is updated */
    MEDIA_MTV_SYSTEM_UNSAVED_RECORDING_DISCARDED = 50
} media_mtv_system_event_enum;

/**
  * Service activity. Activities can be OR'ed together to specify multiple activities
  * at the same time.
  */
typedef enum
{
    MEDIA_MTV_SERVICE_ACTIVITY_PLAY      = 0x00000001,   /**< play media data */
    MEDIA_MTV_SERVICE_ACTIVITY_RECORD    = 0x00000002,   /**< record media data */
    MEDIA_MTV_SERVICE_ACTIVITY_DUMP      = 0x00000004    /**< dump media data into file */
} media_mtv_service_activity_enum;

/**
  * Service types: the order should sync with mdi_mtv_service_type_enum
  */
typedef enum
{
    MEDIA_MTV_SERVICE_UNKNOWN,          /**< unknown service */
    MEDIA_MTV_SERVICE_DIGITAL_RADIO,    /**< digital radio */
    MEDIA_MTV_SERVICE_DIGITAL_TV,       /**< digital TV */
    MEDIA_MTV_SERVICE_ANALOG_TV,        /**< analog TV */
    MEDIA_MTV_SERVICE_MOT_SLIDESHOW,    /**< MOT slide show */
    MEDIA_MTV_SERVICE_TPEG,             /**< Transport Protocol Experts Group */
    MEDIA_MTV_SERVICE_BWS,              /**< Broadcast WebSite */
    MEDIA_MTV_SERVICE_FILE_DOWNLOAD,    /**< file download */
    MEDIA_MTV_SERVICE_CA                /**< CA related */
} media_mtv_service_type_enum;

/**
  * Service sources.
  */
typedef enum
{
    MEDIA_MTV_SERVICES_FROM_LIVE_SIGNAL,    /**< scanning services from live signal */
    MEDIA_MTV_SERVICES_FROM_LOCAL_DATABASE  /**< load service info from local cache */
} media_mtv_service_source_enum;

/**
  * Frequency band.
  */
typedef enum
{
    MEDIA_MTV_INVALID_BAND,

    /* TDMB */
    MEDIA_MTV_TDMB_KOREA_BAND,
    MEDIA_MTV_TDMB_BAND_III,
    MEDIA_MTV_TDMB_L_BAND,
    MEDIA_MTV_TDMB_CANADA_BAND,
    MEDIA_MTV_TDMB_CHINESE_BAND,
    MEDIA_MTV_TDMB_BAND_II,
    MEDIA_MTV_TDMB_BAND_IF,
    /* CMMB */
    MEDIA_MTV_CMMB_U_BAND,

    /* Analog TV */
    MEDIA_MTV_ATV_BEGIN,
    MEDIA_MTV_ATV_AFGHANISTAN = MEDIA_MTV_ATV_BEGIN,
    MEDIA_MTV_ATV_ARGENTINA,
    MEDIA_MTV_ATV_AUSTRALIA,
    MEDIA_MTV_ATV_BRAZIL,
    MEDIA_MTV_ATV_BURMA,
    MEDIA_MTV_ATV_CAMBODIA,
    MEDIA_MTV_ATV_CANADA,
    MEDIA_MTV_ATV_CHILE,
    MEDIA_MTV_ATV_CHINA,
    MEDIA_MTV_ATV_CHINA_HONGKONG,
    MEDIA_MTV_ATV_CHINA_SHENZHEN,
    MEDIA_MTV_ATV_EUROPE_EASTERN,
    MEDIA_MTV_ATV_EUROPE_WESTERN,
    MEDIA_MTV_ATV_FRANCE,
    MEDIA_MTV_ATV_FRENCH_COLONIE,
    MEDIA_MTV_ATV_INDIA,
    MEDIA_MTV_ATV_INDONESIA,
    MEDIA_MTV_ATV_IRAN,
    MEDIA_MTV_ATV_ITALY,
    MEDIA_MTV_ATV_JAPAN,
    MEDIA_MTV_ATV_KOREA,
    MEDIA_MTV_ATV_LAOS,
    MEDIA_MTV_ATV_MALAYSIA,
    MEDIA_MTV_ATV_MEXICO,
    MEDIA_MTV_ATV_NEWZEALAND,
    MEDIA_MTV_ATV_PAKISTAN,
    MEDIA_MTV_ATV_PARAGUAY,
    MEDIA_MTV_ATV_PHILIPPINES,
    MEDIA_MTV_ATV_PORTUGAL,
    MEDIA_MTV_ATV_RUSSIA,
    MEDIA_MTV_ATV_SINGAPORE,
    MEDIA_MTV_ATV_SOUTHAFRICA,
    MEDIA_MTV_ATV_SPAIN,
    MEDIA_MTV_ATV_TAIWAN,  //42
    MEDIA_MTV_ATV_THAILAND,
    MEDIA_MTV_ATV_TURKEY,
    MEDIA_MTV_ATV_UNITED_ARAB_EMIRATES,
    MEDIA_MTV_ATV_UNITED_KINGDOM,
    MEDIA_MTV_ATV_USA,
    MEDIA_MTV_ATV_URUGUAY,
    MEDIA_MTV_ATV_VENEZUELA,
    MEDIA_MTV_ATV_VIETNAM,
    MEDIA_MTV_ATV_IRELAND,
    MEDIA_MTV_ATV_MOROCCO,
    MEDIA_MTV_ATV_END = MEDIA_MTV_ATV_MOROCCO,

    /* full scan */
    MEDIA_MTV_ANY_BAND
} media_mtv_band_enum;

/**
  * ATV audio mode.
  */
typedef enum
{
    /* default by service */
    ATV_DEFAULT_MODE    = 0x00000000,

    /* MTS auto update use */
    ATV_MTS_MONO        = 0x00000001,
    ATV_MTS_STEREO      = 0x00000002,
    ATV_MTS_SAP         = 0x00000004,

    /* Japan & Korea MPX */
    ATV_MPX_MONO        = 0x00000008,
    ATV_MPX_STEREO      = 0x00000010,
    ATV_MPX_SUB         = 0x00000020,
    ATV_MPX_MAIN_SUB    = 0x00000040,
    ATV_MPX_MAIN        = 0x00000080,
    /* Euro */
    ATV_FM_MONO         = 0x00000100,
    ATV_A2_STEREO       = 0x00000200,
    ATV_A2_DUAL1        = 0x00000400,
    ATV_A2_DUAL2        = 0x00000800,
    ATV_NICAM_MONO      = 0x00001000,
    ATV_NICAM_STEREO    = 0x00002000,
    ATV_NICAM_DUAL1     = 0x00004000,
    ATV_NICAM_DUAL2     = 0x00008000,

    ATV_FMRDO_MONO      = 0x00010000,
    ATV_FMRDO_STEREO    = 0x00020000
} media_mtv_atv_audio_mode_enum;

/**
  * Service flags.
  */
typedef enum
{
    MEDIA_MTV_SERVICE_FREE = 0x01,          /**< the service is available for free */
    MEDIA_MTV_SERVICE_CLEAR_TO_AIR = 0x02,  /**< the service is not scrambled */
    MEDIA_MTV_SERVICE_UNSUBSCRIBED = 0x04,  /**< the service is unsubscribed */
    MEDIA_MTV_SERVICE_SUBSCRIBED = 0x08     /**< the service is subscribed */
} media_mtv_service_flag_enum;

/**
  * Service state.
  */
typedef enum
{
    MEDIA_MTV_SERVICE_STATE_STOPPED,        /**< the service has been started */
    MEDIA_MTV_SERVICE_STATE_STARTED,        /**< the service is ready for play, record, or other purposes */
    MEDIA_MTV_SERVICE_STATE_READY           /**< the service has been stopped */
} media_mtv_service_state_enum;

/**
  * Service events.
  */
typedef enum
{
    MEDIA_MTV_SERVICE_STARTED,              /**< a service has been started */
    MEDIA_MTV_SERVICE_READY,                /**< a service is ready for play, record, or other purposes */
    MEDIA_MTV_SERVICE_STOPPED,              /**< a service has been stopped */
    MEDIA_MTV_SERVICE_ABORTED,              /**< some error has happened for a service */
    MEDIA_MTV_SERVICE_ADDED,                /**< a new service is available */
    MEDIA_MTV_SERVICE_REMOVED,              /**< an existing service is removed */
    MEDIA_MTV_SERVICE_UPDATED,              /**< information of an existing service is updated */
    MEDIA_MTV_SERVICE_ACCESS_GRANTED,       /**< access to a service is granted */
    MEDIA_MTV_SERVICE_ACCESS_DENIED,        /**< access to a service is denied */
    MEDIA_MTV_SERVICE_BAD_RECEPTION,        /**< the signal reception is bad */
    MEDIA_MTV_SERVICE_GOOD_RECEPTION,       /**< the signal reception is good */
    MEDIA_MTV_SERVICE_FATAL_ERROR,          /**< fatal error. For example, hardware function is not available */
    MEDIA_MTV_SERVICE_DATE_TIME,            /**< gives information relating to the present time and date */
    MEDIA_MTV_SERVICE_PROGRAM_INFO,         /**< @see media_mtv_program_info_struct */
    MEDIA_MTV_SERVICE_EMERGENCY_MSG,        /**< new emergency message is available */
    MEDIA_MTV_SERVICE_ESG_NEW_AVAILABLE,    /**< new ESG is available */
    MEDIA_MTV_SERVICE_ESG_DOWNLOADED,       /**< ESG is downloaded */
    MEDIA_MTV_SERVICE_ESG_UPDATED,          /**< ESG is updated */
    MEDIA_MTV_SERVICE_SG_UPDATE_RET,        /**< ESG fails to update */
    MEDIA_MTV_SERVICE_UPGRADE_RET,          /**< Upgrade result */
    MEDIA_MTV_SERVICE_INTERACTIVITY_RETRIEVE_RET, /**< Interactivity retrieve result */
    MEDIA_MTV_SERVICE_AREA_RETRIEVE_RET,    /**< Area retrieve result */
    MEDIA_MTV_SERVICE_GBA_RET,              /**< GBA process result */
    MEDIA_MTV_SERVICE_ACCOUNT_INQUIRY_DONE, /**< Account inquiry done */
    MEDIA_MTV_SERVICE_SUBSCRIPTION_UPDATE_RET, /**< ESG is updated */
    MEDIA_MTV_SERVICE_SUBSCRIBE_DONE,        /**< Subscribe done */
    MEDIA_MTV_SERVICE_UNSUBSCRIBE_DONE,       /**< Unsubscribe done */
    MEDIA_MTV_SERVICE_MSK_RETRIEVE_DONE,       /**< MSK retrieve done */
    MEDIA_MTV_SERVICE_IMD_READY,             /**< IMD ready */
    MEDIA_MTV_SERVICE_SET_EMM_DONE,
    MEDIA_MTV_SERVICE_GET_CA_DONE
} media_mtv_service_event_enum;

/**
  * Parameter for service event MEDIA_MTV_SERVICE_PROGRAM_INFO.
  */
typedef struct
{
    kal_uint32 record_count;

    struct
    {
        kal_uint32 date;        /* 16-bit MJD */
        kal_uint32 time;        /* 24-bit UTC */
        kal_uint32 duration;    /* in seconds */
        kal_wchar title[256];   /* program title */

    } records[2]; /**< 0 is for current program and 1 for next program */

} media_mtv_program_info_struct;

/**
  * Service parameters that represent various status or setting you can query
  * or change for a service.
  */
typedef enum
{
    MEDIA_MTV_SERVICE_PARAM_AUDIO_SAMPLE_RATE,      /* 0 */
    MEDIA_MTV_SERVICE_PARAM_AUDIO_CHANNEL_NUMBER,   /* 1 */

    /* AnalogTV */
    MEDIA_MTV_SERVICE_PARAM_PAUSE,                  /* 2 */
    MEDIA_MTV_SERVICE_PARAM_RESUME,                 /* 3 */
    MEDIA_MTV_SERVICE_PARAM_DISABLE,                /* 4 */
    MEDIA_MTV_SERVICE_PARAM_NAME,                   /* 5 */
    MEDIA_MTV_SERVICE_PARAM_AUDIO_MODE,             /* 6 */
    MEDIA_MTV_SERVICE_PARAM_VIDEO_MODE,             /* 7 */
    MEDIA_MTV_SERVICE_PARAM_SERVICE_INFO_BY_INDEX,  /* 8 */

    /* CMMB */
    MEDIA_MTV_SERVICE_PARAM_SUBSCRIBE,              /* 9 */
    MEDIA_MTV_SERVICE_PARAM_UNSUBSCRIBE,            /* 10 */
    MEDIA_MTV_SERVICE_PARAM_ACCOUNT_INQUIRY,        /* 11 */
    MEDIA_MTV_SERVICE_PARAM_SERVICE_CA,             /* 12 */
    MEDIA_MTV_SERVICE_PARAM_DOWNLOAD_SG,            /* 13 */
    MEDIA_MTV_SERVICE_PARAM_UPDATE_SG,              /* 14 */
    MEDIA_MTV_SERVICE_PARAM_SIM_INFO,               /* 15 */
    MEDIA_MTV_SERVICE_PARAM_NET_INFO,               /* 16 */
    MEDIA_MTV_SERVICE_PARAM_GBA,                    /* 17 */
    MEDIA_MTV_SERVICE_PARAM_SUBSCRIPTOIN_UPDATE,        /* 18 */
    MEDIA_MTV_SERVICE_PARAM_CANCEL_SUBSCRIPTOIN_UPDATE, /* 19 */
    MEDIA_MTV_SERVICE_PARAM_MSK_RETRIEVE,               /* 20 */
    MEDIA_MTV_SERVICE_PARAM_PURIFY_PROG_REMINDER,       /* 21 */
    MEDIA_MTV_SERVICE_PARAM_PREVIEW_DATA_DOWNLOADED,    /* 22 */
    MEDIA_MTV_SERVICE_PARAM_UPGRADE_QUERY,              /* 23 */
    MEDIA_MTV_SERVICE_PARAM_AREA_SET_RETRIEVE,          /* 24 */
    MEDIA_MTV_SERVICE_PARAM_INTERACTIVITY_RETRIEVE,     /* 25 */
    MEDIA_MTV_SERVICE_PARAM_IMD_COUNT,                  /* 26 */
    MEDIA_MTV_SERVICE_PARAM_IMD_DESC,                   /* 27 */
    MEDIA_MTV_SERVICE_PARAM_IMD_DETAIL,                 /* 28 */
    MEDIA_MTV_SERVICE_PARAM_SUBSCRIBE_UPDATE_DESC,      /* 29 */  /* add for desc */
    MEDIA_MTV_SERVICE_PARAM_SET_EMM,
    MEDIA_MTV_SERVICE_PARAM_CA_QUERY,
    MEDIA_MTV_SERVICE_PARAM_NIT_TIME,
    MEDIA_MTV_SERVICE_PARAM_NIT_AREA,

    /* player */
    MEDIA_MTV_SERVICE_PARAM_PLAYER_SET_SLEEP_TIME,   /* 28 */
    MEDIA_MTV_SERVICE_PARAM_BRIGHTNESS,     /* 29 */
    MEDIA_MTV_SERVICE_PARAM_CONTRAST,       /* 30 */
    MEDIA_MTV_SERVICE_PARAM_SATURATION      /* 31 */
} media_mtv_service_param_enum;

/**
  * Player events.
  */
typedef enum
{
    MEDIA_MTV_PLAYER_STARTED,               /**< the player has been started */
    MEDIA_MTV_PLAYER_TIMESHIFT_PAUSED,      /**< the playback of time-shift content has been paused */
    MEDIA_MTV_PLAYER_TIMESHIFT_DELAYED,     /**< delayed (buffered) content is played */
    MEDIA_MTV_PLAYER_TIMESHIFT_LIVE,        /**< live broadcast content is played */
    MEDIA_MTV_PLAYER_TIMESHIFT_ERROR,       /**< a time-shift error has occurred */
    MEDIA_MTV_PLAYER_BEGINNING_OF_CONTENT,  /**< a rewind hits the beginning of time-shift buffer */
    MEDIA_MTV_PLAYER_END_OF_CONTENT,        /**< a forward playback catches up with the live recording point */
    MEDIA_MTV_PLAYER_SNAPSHOT_TAKEN,        /**< a video snapshot has been taken. the event parameter will be the snapshot filename.  */
    MEDIA_MTV_PLAYER_DYNAMIC_LABEL,         /**< a dynamic label is available. the event parameter will be a null-terminated wchar string. */
    MEDIA_MTV_PLAYER_ERROR,                 /**< an internal error of player has happened. the client should stop the player immediately. */
    MEDIA_MTV_PLAYER_STOPPED,               /**< the player has been stopped */
    MEDIA_MTV_PLAYER_RATE_CHANGE            /**< the playbacl rate has been changed */
} media_mtv_player_event_enum;

/**
  * Recorder events.
  */
typedef enum
{
    MEDIA_MTV_RECORDER_STARTED,             /**< the recorder has been started */
    MEDIA_MTV_RECORDER_SAVING,              /**< file saving is in progress */
    MEDIA_MTV_RECORDER_SAVING_SUCCEEDED,    /**< file saving is succeeded */
    MEDIA_MTV_RECORDER_SAVING_FAILED,       /**< file saving is failed */
    MEDIA_MTV_RECORDER_ERROR,               /**< an internal error of recorder has happened. the client should stop the recorder immediately. */
    MEDIA_MTV_RECORDER_STOPPED,             /**< the recorder has been stopped. the event parameter will be the recorded filename. */
    MEDIA_MTV_RECORDER_RECORDING_DISCARDED  /**< indicate that recording has been discarded */
} media_mtv_recorder_event_enum;

/**
  * Player states.
  */
typedef enum
{
    MEDIA_MTV_PLAYER_STATE_STOPPED,     /**< the player is stopped */
    MEDIA_MTV_PLAYER_STATE_PLAYING,     /**< the player is playing the media */
    MEDIA_MTV_PLAYER_STATE_PAUSED       /**< the player is paused */
} media_mtv_player_state_enum;

/**
  * Recorder states.
  */
typedef enum
{
    MEDIA_MTV_RECORDER_STATE_STOPPED,   /**< the recorder is started */
    MEDIA_MTV_RECORDER_STATE_STARTED,   /**< the recorder is stopped */
    MEDIA_MTV_RECORDER_STATE_SAVING     /**< the recorder is saving the recorded program */
} media_mtv_recorder_state_enum;

/**
  * MTV mode.
  */
typedef enum
{
    MEDIA_MTV_OPEN_MODE_TDMB,   /**< TDMB */
    MEDIA_MTV_OPEN_MODE_CMMB,   /**< CMMB */
    MEDIA_MTV_OPEN_MODE_ATV     /**< AnalogTV */
} media_mtv_mode_enum;

/**
  * favorite type
  */
typedef enum
{
    MEDIA_MTV_FAVO_CHANNEL,
    MEDIA_MTV_FAVO_CONTENT,
    MEDIA_MTV_FAVO_LOCAL_PURCHASE_ITEM,
    MEDIA_MTV_FAVO_EB
} media_mtv_favorite_type_enum;

typedef struct
{
    kal_uint32 ref_id;
    kal_char* rid;
    kal_int32 lang_type;
    void *applib_time;
    kal_wchar *keyword;
    kal_uint32 start_idx;
    kal_uint32 query_num;
} media_mtv_esg_query_struct;
/**
  * Parameter for MSG_ID_MEDIA_MTV_OPEN_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32* context;    /**< opaque context data */
    kal_uint16 app_id;
    media_mtv_mode_enum mode;
    void *init_param;
    kal_int32* result;
} media_mtv_open_req_struct;

/**
  * Recording settings.
  */
typedef struct
{
    kal_bool enable_timeshift;          /**< indicate whether to enable time-shift */
    kal_uint32 max_timeshift_delay;     /**< maximum time-shift delay in seconds. set it to 0 if don't care */
    kal_uint32 max_timeshift_buffer_kb; /**< maximum time-shift buffer size. set it to 0 if don't care */
    kal_wchar* record_dir;              /**< the directory to save recorded programs */
} media_mtv_config_record_struct;

#define MEDIA_MTV_REQ_HEADER \
   kal_uint32 context; \
   kal_int32* result;

/**
  * Parameter for MSG_ID_MEDIA_MTV_CONFIG_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 fields;                      /**< bitfields to indicate which configurations are valid. @see media_mtv_config_enum */
    media_config_video_struct video;        /**< video output settings */
    media_config_audio_struct audio;        /**< audio output settings */
    media_mtv_config_record_struct record;  /**< record settings */
} media_mtv_config_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_FIND_UNSAVED_RECORDING_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_bool* found;  /**< indicates whether there is any unsaved recording */
} media_mtv_find_unsaved_recording_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_RECOVER_RECORDING_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 seq_no;  /**< allow the client to discard late indication */
} media_mtv_recover_recording_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_ABORT_RECOVERING_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
} media_mtv_abort_recovering_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_DISCARD_UNSAVED_RECORDING_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
} media_mtv_discard_unsaved_recording_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_COMPLETE_RECOVERING_IND.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    kal_uint32 seq_no;  /**< allow the client to discard late indication */
    kal_uint32 error;
} media_mtv_complete_recovering_ind_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_SEARCH_SERVICES_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 seq_no;  /**< allow the client to discard late indication */
    kal_uint32 source;          /**< specifies where the services info comes from. @see media_mtv_service_source_enum */
    kal_uint32 band;   /**< only used when source is MEDIA_MTV_SERVICES_FROM_LIVE_SIGNAL @see media_mtv_band_enum */
    void *param;
} media_mtv_search_services_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_SEARCH_PROGRESS_IND.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    kal_uint32 seq_no;          /**< allow the client to discard late indication */
    kal_uint32 percentage;      /**< search progress in percentage */
} media_mtv_search_progress_ind_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_ABORT_SEARCHING_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
} media_mtv_abort_searching_req_struct;

/**
  * Service information.
  */
typedef struct
{
    kal_uint32 service_id;      /**< unique service ID */
    kal_wchar* service_name;    /**< the service name */
    kal_uint32 service_number;  /**< service number for easy access */
    kal_uint32 service_type;    /**< the service type. @see media_mtv_service_type_enum */
    kal_uint32 service_flags;   /**< the service flags. @see media_mtv_service_flag_enum */
    kal_uint32 service_freq;    /**< the service freq. */

    /* Analog TV */
    kal_uint32 audio_mode;              /**< the current audio mode. @see matvctrl.h */
    kal_uint32 supported_audio_mode;    /**< supported audio mode. @see matvctrl.h */
    kal_uint32 video_mode;              /**< the video mode. @see media_mtv_atv_video_mode_enum */
} media_mtv_service_info_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_SERVICE_FOUND_IND.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    kal_uint32 seq_no;  /**< allow the client to discard late indication */
    kal_uint32 service_count;
    media_mtv_service_info_struct service_info[10];
} media_mtv_service_found_ind_struct;


/* this is the struct for account inquiry done event */
typedef struct
{
    kal_uint8   fragment_id[20];
    kal_uint8   purchaseitem_id[30];
    kal_wchar   purchaseitem_name[32+1];
    kal_wchar   purchaseitem_desc[32+1];
    kal_uint8  type;
    kal_uint8   period;
    float       price;
} media_mtv_fragment_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    kal_uint32  purchase_count;
    media_mtv_fragment_struct  purchase_info[5];
} media_mtv_account_inquiry_ind_struct;

/* this is the struct for recommended city found event */
typedef struct
{
    kal_wchar   city_name[32+1];
} media_mtv_city_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    kal_uint32  city_count;
    media_mtv_city_struct  city_info[3];
} media_mtv_city_found_ind_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_SYSTEM_EVENT_IND.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    kal_uint32 event;           /**< event code. @see media_mtv_system_event_enum */
    kal_uint32 parameter;       /**< event parameter which depends on what kind of event is sent */
} media_mtv_system_event_ind_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_START_SERVICE_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 seq_no;          /**< allow the client to discard late indication */
    kal_uint32 service_id;      /**< the service to start */
    kal_uint32 activities;      /**< the activities to start. @see media_mtv_service_activity_enum */
} media_mtv_start_service_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_SERVICE_EVENT_IND.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    kal_uint32 seq_no;          /**< allow the client to discard late indication */
    kal_uint32 service_id;      /**< the service where the status comes from */
    kal_uint32 event;           /**< event code. @see media_mtv_service_event_enum */
    kal_uint32 parameter;       /**< event parameter which depends on what kind of event is sent */
    kal_wchar  append_data[MEDIA_MTV_MAX_APPEND_LEN];        /**< for description string */
} media_mtv_service_event_ind_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_START_TIMESHIFT_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
    kal_uint32 seq_no;      /**< allow the client to discard late indication */
} media_mtv_start_timeshift_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_PLAYER_PLAY_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
    kal_uint32 seq_no;      /**< allow the client to discard late indication */
} media_mtv_player_play_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_PLAYER_PAUSE_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
} media_mtv_player_pause_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_PLAYER_STOP_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
} media_mtv_player_stop_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_PLAYER_PAUSE_VISUAL_UPDATE_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
} media_mtv_player_pause_visual_update_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_PLAYER_RESUME_VISUAL_UPDATE_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
} media_mtv_player_resume_visual_update_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_PLAYER_SEEK_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
    kal_uint32 delay;    /**< time-shift delay in milliseconds */
} media_mtv_player_seek_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_PLAYER_SET_RATE_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
    kal_int32 rate;             /**< playback rate in unit of 1/1000. negative value for reversed playback. */
} media_mtv_player_set_rate_req_struct;


typedef struct
{
    kal_uint32 buffer_width;
    kal_uint32 buffer_height;
    kal_uint8 *buffer_address;
    kal_uint32 buffer_size;
    kal_uint8 image_data_format;
    med_frame_enum frame_mode;
} media_mtv_buf_content_struct;

typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
    kal_wchar* file_path;

    media_mtv_buf_content_struct *buf;
} media_mtv_player_snapshot_req_struct;

/**
  * Player status information.
  */
typedef struct
{
    kal_uint32 state;           /**< @see media_mtv_player_state_enum */
    kal_uint32 play_delay;      /**< playback delay in milliseconds */
    kal_uint32 max_delay;       /**< maximum delay in milliseconds */
    kal_uint32 buffer_duration; /**< allowable buffer duration in milliseconds. buffer_duration will always be larger than max_delay. */
    kal_int32 play_rate;        /**< current play rate */
} media_mtv_player_status_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_PLAYER_GET_STATUS_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
    media_mtv_player_status_struct* status;
} media_mtv_player_get_status_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_SERVICE_GET_INFO_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;               /**< the service to query */
    media_mtv_service_info_struct* info; /**< the info struct to fill in */
} media_mtv_service_get_info_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_PLAYER_EVENT_IND.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    kal_uint32 seq_no;          /**< allow the client to discard late indication */
    kal_uint32 service_id;      /**< the service where the status comes from */
    kal_uint32 event;           /**< event code. @see media_mtv_player_event_enum */
    kal_uint32 parameter;       /**< event parameter which depends on what kind of event is sent */
} media_mtv_player_event_ind_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_RECORDER_START_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
    const kal_wchar* service_name;
    kal_uint32 seq_no;  /**< allow the client to discard late indication */
} media_mtv_recorder_start_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_RECORDER_STOP_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
} media_mtv_recorder_stop_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_RECORDER_PAUSE_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
} media_mtv_recorder_pause_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_RECORDER_RESUME_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
} media_mtv_recorder_resume_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_RECORDER_SAVE_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
    kal_wchar *file_path;
    kal_uint32 seq_no;  /**< allow the client to discard late indication */
} media_mtv_recorder_save_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_RESTART_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
    kal_uint32 seq_no;
} media_mtv_restart_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_RECORDER_DISCARD_RECORDING_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
    kal_uint32 seq_no;
} media_mtv_recorder_discard_recording_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_RECORDER_ABORT_SAVING_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
} media_mtv_recorder_abort_saving_req_struct;

/**
  * Recorder status information.
  */
typedef struct
{
    kal_uint32 state;               /**< @see media_mtv_recorder_state_enum */
    kal_uint32 recorded_duration;   /**< current recorder duration in seconds */
} media_mtv_recorder_status_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_RECORDER_GET_STATUS_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
    media_mtv_recorder_status_struct* status;   /**< address of status struct */
} media_mtv_recorder_get_status_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_RECORDER_EVENT_IND.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    kal_uint32 seq_no;          /**< allow the client to discard late indication */
    kal_uint32 service_id;      /**< the service where the status comes from */
    kal_uint32 event;           /**< event code. @see media_mtv_recorder_event_enum */
    kal_uint32 parameter;       /**< event parameter which depends on what kind of event is sent */
} media_mtv_recorder_event_ind_struct;

typedef struct
{
    kal_int32 elapse_ticks;           /**< event code. @see media_mtv_player_event_enum */
    kal_int32 sleep_ticks;       /**< event parameter which depends on what kind of event is sent */
} media_mtv_player_sleep_time_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_SET_PARAM_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;  /**< the service to change */
    kal_uint32 param;       /**< the parameter ID. @see media_mtv_service_param_enum */
    kal_uint32 value;       /**< the parameter value */
} media_mtv_set_param_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_GET_PARAM_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;  /**< the service to query */
    kal_uint32 param;       /**< the parameter ID. @see media_mtv_service_param_enum */
    kal_uint32* value;      /**< the parameter value */
} media_mtv_get_param_req_struct;

typedef struct
{
    media_mtv_service_state_enum state; /**< service state */
    kal_uint32 signal_strength;         /**< the signal strength. valid range is 0 to 100. */

    /**
      * Indicates whether timeshift is available or not. For example, if the disk free space gets low,
      * time-shift will be disabled forcely. MMI can check this flag to decide whether the user can do
      * trick-mode playback or recording.
      */
    kal_bool timeshift_available;

} media_mtv_service_status_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_SERVICE_GET_STATUS_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;
    media_mtv_service_status_struct* status;    /**< address of status struct */
} media_mtv_service_get_status_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_STOP_SERVICE_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    kal_uint32 service_id;  /**< the service to stop */
} media_mtv_stop_service_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_CLOSE_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
} media_mtv_close_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_MEDIA_MTV_ESG_DOWNLOAD_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
} media_mtv_media_mtv_esg_download_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_MEDIA_MTV_ESG_ABORT_DOWNLOADING_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
} media_mtv_media_mtv_esg_abort_downloading_req_struct;

/**
  * Recorder states.
  */
typedef enum
{
    MEDIA_MTV_ESG_SOURCE_DEFAULT,   /**< select default db in SP */
    MEDIA_MTV_ESG_SOURCE_MBBMS      /**< MBBMS db for extra query */
} media_mtv_esg_source_enum;

/**
  * Parameter for MSG_ID_MEDIA_MTV_ESG_OPEN_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32* context;    /**< opaque context data */
    kal_uint16 app_id;
    media_mtv_esg_source_enum source;
    kal_int32* result;
} media_mtv_esg_open_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_ESG_CLOSE_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    media_mtv_esg_source_enum source;
} media_mtv_esg_close_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_ESG_QUERY_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    media_mtv_esg_source_enum source;
    kal_int32 type;
    media_mtv_esg_query_struct *query;
} media_mtv_esg_query_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_ESG_GET_RESULTS_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    media_mtv_esg_source_enum source;
    kal_int32 type;
    void **buf_p;
} media_mtv_esg_get_results_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_ESG_QUERY_FINISH_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    media_mtv_esg_source_enum source;
} media_mtv_esg_query_finish_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_ESG_ADD_FAVORITE_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    media_mtv_favorite_type_enum type;
    kal_uint32 id;
    kal_char *rid;
} media_mtv_esg_add_favorite_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_ESG_DEL_FAVORITE_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    media_mtv_favorite_type_enum type;
    kal_uint32 id;
    kal_char *rid;
} media_mtv_esg_del_favorite_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_CAS_TASK_START_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    void* task_p;
} media_mtv_cas_os_task_start_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_CAS_GET_CARD_INFO_REQ
  */
typedef struct
{
    kal_char number[8];
} media_mtv_cas_card_info_struct;

typedef struct
{
    LOCAL_PARA_HDR
    MEDIA_MTV_REQ_HEADER
    media_mtv_cas_card_info_struct *card_info;    /**< address of card info struct */
} media_mtv_cas_get_card_info_req_struct;


/**
  * Parameter for MSG_ID_MEDIA_MTV_ASYNC_WRITE.
  */
typedef struct
{
    LOCAL_PARA_HDR
    void* io;       /**< the pointer to async I/O object */
} media_mtv_async_write_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MTV_ASYNC_CALLBACK.
  */
typedef struct
{
    LOCAL_PARA_HDR
    void (*callback)(void* param);  /**< the callback fucntion */
    void* param;                    /**< the opaque parameter for calback function */
} media_mtv_async_callback_req_struct;


/**
  * Parameter for MSG_ID_MEDIA_ESG_ADD_PARSE_COMMAND
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 service_idx;
    kal_uint32 table_idx;
    void*      param;
}media_esg_parse_command_struct;
  

/**
  * Parameter for MSG_ID_TDMB_DATA_INDICATION.
  */
typedef struct
{
    LOCAL_PARA_HDR
    void* demod;
} media_mtv_demod_data_ind_struct;

/**
  * Parameter for MSG_ID_MEDIA_ATV_SCAN_PROGRESS_IND.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    kal_uint32 percentage;
    kal_uint32 ch_num;
} media_atv_scan_progress_ind_struct;

/**
  * Parameter for MSG_ID_MEDIA_CAMERA_SCAN_PROGRESS_IND.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    kal_uint32 percentage;
    kal_uint32 ch_num;
} media_camera_scan_progress_ind_struct;

/**
  * Parameter for MSG_ID_MEDIA_ATV_EVENT_IND.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    kal_uint32 event;
    kal_uint32 param;
} media_atv_event_ind_struct;

/**
  * Parameter for MSG_ID_MEDIA_CAMERA_EVENT_IND.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    kal_uint32 event;
    kal_uint32 param;
} media_camera_event_ind_struct;

/**
  * Parameter for MSG_ID_MEDIA_ATV_REC_AUDIO_DATA_IND.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    kal_uint8 event;

} media_atv_rec_audio_data_ind_struct;

/**
  * Parameter for MSG_ID_MEDIA_ATV_REC_VIDEO_DATA_IND.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    kal_uint8 event;

} media_atv_rec_video_data_ind_struct;

/**
  * Parameter for MSG_ID_MEDIA_ATV_REC_START_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;

} media_atv_rec_start_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_ATV_REC_START_CNF.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;

} media_atv_rec_start_cnf_struct;

/**
  * Parameter for MSG_ID_MEDIA_ATV_REC_STOP_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;

} media_atv_rec_stop_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_ATV_REC_STOP_CNF.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;

} media_atv_rec_stop_cnf_struct;

/**
  * Parameter for MSG_ID_MEDIA_ATV_REC_VIDEO_FINISH_IND.
  */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 context;
    kal_int16 result;

} media_atv_rec_video_finish_ind_struct;

/** @} */

/*
 * vcall messages
 */
typedef enum
{
    VCALL_VIEW_HIDE,
    VCALL_VIEW_SHOW_IMAGE,
    VCALL_VIEW_SHOW_VIDEO,

    VCALL_VIEW_TOTAL
} media_vcall_view_type_enum;

typedef enum
{
    VCALL_ENC_QTY_LOW = 0,
    VCALL_ENC_QTY_NORMAL,
    VCALL_ENC_QTY_FINE,

    VCALL_ENC_QTY_TOTAL
} media_vcall_enc_qty_enum;


typedef struct
{
    kal_uint32 layer_element;
    kal_uint32 blt_ctx;
    kal_uint32 blt_dev;
    kal_uint16 encode_width;
    kal_uint16 encode_height;
    kal_uint16 preview_width;
    kal_uint16 preview_height;
    void *preview_buffer_p;
    kal_uint32 preview_buffer_size;

    kal_uint8 lcd_id;
    kal_bool lcd_update;

    kal_uint8 cam_id;

    kal_int16 exposure;
    kal_int16 contrast;
    kal_int16 saturation;
    kal_int16 sharpness;
    kal_int16 hue;
    kal_int16 WB;
    kal_int16 effect;
    kal_uint8 banding_freq;
    kal_uint8 encode_quality;
    kal_uint16 seq_num;

    kal_uint8 zoom_step;
    kal_int16 zoom_factor;

    kal_uint8 af_operation_mode;
    kal_uint8 af_range;

    kal_uint8 dsc_mode;
    kal_bool night_mode;

    kal_uint8  image_data_format;

    kal_bool notify_peer;
    
    kal_uint16 memory_allocator;
    kal_uint16 ui_rotate;

} media_vcall_record_struct;

typedef struct
{
    kal_uint32 layer_element;
    kal_uint32 blt_ctx;
    kal_uint32 blt_dev;
    kal_uint16 display_width;
    kal_uint16 display_height;
    void *display_buffer_p;
    kal_uint32 display_buffer_size;

    kal_uint8 peer_enc_qty;

    kal_uint16 seq_num;
    kal_uint8 lcd_id;
    kal_uint16 lcd_start_x;
    kal_uint16 lcd_start_y;
    kal_uint16 lcd_end_x;
    kal_uint16 lcd_end_y;
    kal_uint16 roi_offset_x;
    kal_uint16 roi_offset_y;
    kal_uint32 update_layer;
    kal_uint32 hw_update_layer;

    kal_uint32 roi_background_color;        /* set the background color */

    kal_uint8 image_data_format;

    kal_uint16 memory_allocator;

    kal_uint16 ui_rotate;

} media_vcall_playback_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool   is_set;    
    kal_uint32 main_w;
    kal_uint32 main_h;
    kal_uint32 sub_w;
    kal_uint32 sub_h;    
    
}media_vcall_set_memory_param_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 param_id;
    kal_int16 value;
}media_vcall_set_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool  is_peer_view;
    kal_uint32 buffer_width;
    kal_uint32 buffer_height;
    kal_uint32 buffer_address;
    kal_uint32 buffer_size;

}media_vcall_get_buf_content_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    media_vcall_view_type_enum recorder_view_type;
    media_vcall_view_type_enum player_view_type;
    media_vcall_record_struct recorder;
    media_vcall_playback_struct player;
} media_vcall_video_codec_open_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
} media_vcall_video_codec_close_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
} media_vcall_channel_report_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 event_seq_no;
    void *param;
} media_vcall_video_encode_data_ready_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 event_seq_no;
    void *param;
} media_vcall_video_decode_data_ready_ind_struct;


typedef enum
{
    VCALL_VIDEO_SIZE_QCIF,
    VCALL_VIDEO_SIZE_SQCIF

} media_vcall_video_size_enum;

typedef enum
{
    VCALL_EVENT_CHANGE_ENCODE_SIZE,
    VCALL_EVENT_CHANGE_ENCODE_QUALITY,
    VCALL_EVENT_UPDATE_LCD,
    VCALL_EVENT_ENC_PATH_BUILT,
    VCALL_EVENT_DEC_CH_CHANGE
} media_vcall_codec_event_enum;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 seq_no;
    media_vcall_codec_event_enum codec_event;
    kal_int32 para;
} media_vcall_video_codec_report_ind_struct;

/**
 * BCR (Business Card Recognition)
 */
typedef struct
{
    LOCAL_PARA_HDR
}
media_cam_bcr_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_cam_bcr_clear_raw_data_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 mode;
}
media_cam_bcr_recog_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_cam_bcr_abort_recog_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
}
media_cam_bcr_clear_recog_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void **capture_buffer_p;
    kal_uint16 image_width;
    kal_uint16 image_height;
} media_cam_bcr_capture_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void *raw_buffer;
    kal_uint16 image_width;
    kal_uint16 image_height;
} media_cam_bcr_set_raw_req_struct;

typedef struct
{
    kal_uint16 field_type;
    kal_uint32 x1;
    kal_uint32 y1;
    kal_uint32 x2;
    kal_uint32 y2;
    kal_wchar recog_string[256];
} media_cam_bcr_recog_info_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint8 recog_number;
    media_cam_bcr_recog_info_struct* recog_info;
} media_cam_bcr_recog_result_ind_struct;

typedef enum
{
    MEDIA_CAM_BCR_UNKNOWN = 0,
    MEDIA_CAM_BCR_NAME = 1,
    MEDIA_CAM_BCR_POSITION,
    MEDIA_CAM_BCR_COMPANY,
    MEDIA_CAM_BCR_ADDRESS,
    MEDIA_CAM_BCR_PHONE,
    MEDIA_CAM_BCR_FAX,
    MEDIA_CAM_BCR_BBCALL,
    MEDIA_CAM_BCR_MOBIL,
    MEDIA_CAM_BCR_EMAIL,
    MEDIA_CAM_BCR_COMPANYNO,
    MEDIA_CAM_BCR_HOMEPAGE,
    MEDIA_CAM_BCR_OTHERS,
    MEDIA_CAM_BCR_ENG_NAME,
    MEDIA_CAM_BCR_ENG_POSITION,
    MEDIA_CAM_BCR_ENG_COMPANY,
    MEDIA_CAM_BCR_ENG_ADDRESS,
    MEDIA_CAM_BCR_TELEX,
    MEDIA_CAM_BCR_SUB_PHONE,

    MEDIA_CAM_BCR_DEPARTMENT,
    MEDIA_CAM_BCR_ENG_DEPARTMENT,
    MEDIA_CAM_BCR_MAILNUM,

    MEDIA_CAM_BCR_TOTAL_FIELD_COUNT
} media_cam_bcr_field_type;

typedef enum
{
    MEDIA_CAM_BCR_TRADITIONAL_MODE = 0x0001,
    MEDIA_CAM_BCR_SIMPLIFIED_MODE = 0x0002,
    MEDIA_CAM_BCR_ENGLISH_MODE = 0x004,
    MEDIA_CAM_BCR_TOTAL_MODE
} media_cam_bcr_recog_mode;

/**
 * End of BCR (Business Card Recognition)
 */
typedef struct
{
    kal_bool is_support;        /* Is this camera function supportable ? */
    kal_uint16 item_count;         /* the number of the workable item*/
    kal_uint16 support_item[MAX_CAMERA_SUPPORT_ITEM_COUNT];   /* the enum of workable item */
}cam_fun_info;

typedef struct
{
    kal_bool is_support;
    kal_uint16 zoom_steps;
    kal_uint16 max_zoom_factor;
}cam_zoom_info;


typedef void (*get_info_callback) (cam_fun_info *p_info);
typedef void (*get_zoom_callback) (cam_zoom_info *p_info);
typedef  kal_uint32 (* sensor_feature_control) (kal_uint32 feature_id, void* p_feature_para_input,void* p_feature_para_output, kal_uint16 feature_para_output_length);

typedef struct {
	get_info_callback get_capture_mode_ability;
	get_info_callback get_camera_scene_ability;
	get_info_callback get_capture_size_ability;
	get_info_callback get_flashlight_ability;
	get_info_callback get_af_range_ability;
	get_info_callback get_iso_ability;
	get_info_callback get_binning_ability;
	get_info_callback get_wb_ability;
	get_info_callback get_effect_ability;
	get_info_callback get_af_mode_ability;
	get_info_callback get_ae_meter_ability;
	get_info_callback get_sharpness_ability;
	get_info_callback get_contrast_ability;
	get_info_callback get_saturation_ability;
	get_info_callback get_ev_ability;
	get_info_callback get_banding_ability;
	get_zoom_callback get_zoom_ability;
	get_info_callback get_video_scene_ability;
	get_info_callback get_video_codec_ability;
	get_info_callback get_video_size_ability;
	sensor_feature_control get_common_ability;
}camera_capability_func_struct;


/**
 * Camera Panorama Support
 */
#define MEDIA_CAM_MAX_PANORAMA_IMAGE_NUM (PANO_MAX_INPUT_IMAGE_NUM)

typedef struct _media_cam_start_stitch_req_struct
{
    LOCAL_PARA_HDR
    kal_uint8 seq_no;
    kal_uint8 direction;
    kal_uint8 num_of_jpegs;
    kal_uint32 source_width;
    kal_uint32 source_height;
    kal_uint32 target_buffer_address;
    kal_uint32 target_buffer_size;
    kal_uint32 jpeg_buffer_p[MEDIA_CAM_MAX_PANORAMA_IMAGE_NUM];
    kal_uint32 jpeg_buffer_size[MEDIA_CAM_MAX_PANORAMA_IMAGE_NUM];
    kal_bool   quickview_output; /* is direct couple to another buffer */
    kal_uint16 quickview_output_width;
    kal_uint16 quickview_output_height;
    kal_uint32 quickview_output_buffer_address;
    kal_uint32 quickview_output_buffer_size;
    kal_bool   quickview_output_resize_by_buffer_size_enable;   /* enable resize panorama quickview image by given buffer size instead of given width/height */

}media_cam_start_stitch_req_struct, media_v_cam_start_stitch_req_struct;

typedef struct _media_cam_stop_stitch_req_struct
{
    LOCAL_PARA_HDR

}media_cam_stop_stitch_req_struct, media_cam_resume_stitch_req_struct, media_cam_reset_panoarama_3a_req_struct, media_cam_pause_stitch_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 seq_no;
    kal_int16 result;
    kal_uint32 jpeg_file_address;
    kal_uint32 jpeg_file_size;
    kal_uint32 jpeg_file_width;
    kal_uint32 jpeg_file_height;

}media_cam_stitch_result_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 quickview_content_start_x;
    kal_uint16 quickview_content_start_y;
    kal_uint16 quickview_content_width;
    kal_uint16 quickview_content_height;

}media_cam_panorama_quickview_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 quickview_roi_x;
    kal_uint16 quickview_roi_y;
    kal_uint16 quickview_roi_width;
    kal_uint16 quickview_roi_height;
    kal_bool   is_jaia_qvi_buf_aligned;
    
}media_cam_panorama_encode_req_struct;

typedef struct
{
    kal_bool ready_to_shot;
    kal_int16 mv_x; // relative to first frame when entering preview
    kal_int16 mv_y;
    kal_uint16 overlap_ratio; // 64 base
    kal_uint8 stitch_dir;
    kal_uint8 move_hint_dir;

} media_cam_autocap_result_struct;

typedef struct
{
    LOCAL_PARA_HDR
    media_cam_autocap_result_struct* autocap_result_p;
}media_cam_get_autocap_result_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 buffer_address;
    kal_uint32 buffer_size;

}media_cam_set_stitch_mem_req_struct, media_v_cam_set_stitch_mem_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 buffer_type;
    kal_int16 result;
    kal_uint32 buffer_address;
    kal_uint32 buffer_size;

}media_cam_hdr_result_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar *filename_p;
}
media_cam_stop_hdr_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar *captured_filename_p;
    kal_wchar *hdr_filename_p;
}
media_cam_save_hdr_images_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 image_resolution;
    kal_uint16 image_width;
    kal_uint16 image_height;
}media_cam_cap_resolution_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool is_active;
}media_cam_profiling_set_active_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 buffer_address;
    kal_uint32 buffer_size;
}media_cam_profiling_set_buffer_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 log_id;
}media_cam_profiling_log_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 buffer_address;
}media_cam_profiling_get_append_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint32 buffer_address; /* Encode data buffer address */
    kal_uint32 buffer_size; /* Encode data buffer size */
    kal_uint8 seq_num;
}media_cam_mav_result_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 captured_number; /* 1~9 */
    kal_uint8 total_number; /* fixed to 9 */
    kal_uint8 seq_num;
} media_cam_mav_capture_image_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 acc_x;
    kal_int32 acc_y;
} media_cam_gyro_result_ind_struct;

/**
  * Bitstream API configurations.
  */

typedef enum
{
    MED_BITSTREAM_CODEC_TYPE_NONE,
    MED_BITSTREAM_CODEC_TYPE_AMR,

    MED_STREAM_CODEC_TYPE_TOTAL
} med_bitstream_codec_type_enum;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 *handle;
    kal_uint8 codec_type;
    /* parameters below are only for pcm type*/
    kal_bool isStereo; /* KAL_FALSE: mono, KAL_TRUE: stereo*/
    kal_int8 bitPerSample; /* 8 or 16, commonly use 16 bits*/
    kal_uint16 sampleFreq; /* 8000, 11025, 12000, 16000, 22050, 24000, 32000, 44100, 48000*/
}
media_bitstream_audio_open_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
}
media_bitstream_audio_close_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint32 *total_size;
    kal_uint32 *free_size;
}
media_bitstream_audio_get_buffer_status_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8* p_app_buf;
    kal_uint32 app_buf_size;
    kal_uint32 *p_used_size;
}
media_bitstream_audio_put_data_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint64 timestamp;
    kal_int32 handle;
    kal_uint8* p_app_buf;
    kal_uint32 app_buf_size;
}
media_bitstream_audio_put_frame_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint32 start_time;
    kal_uint8 audio_path;
    kal_uint8 volume;
}
media_bitstream_audio_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
}
media_bitstream_audio_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
}
media_bitstream_audio_finished_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint32 *play_time;
}
media_bitstream_audio_get_play_time_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 event;
}
media_bitstream_audio_callback_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 event;
}
media_bitstream_audio_driver_event_ind_struct;

/* Bitstream record */
typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 *handle_p;
    kal_uint8 codec_type;
    kal_uint8 quality;
}
media_bitstream_record_open_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
}
media_bitstream_record_close_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
}
media_bitstream_record_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
}
media_bitstream_record_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    void* data_p;
    kal_uint16 data_len;
    kal_uint8 set_type;
}
media_bitstream_record_set_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    void* data_p;
    kal_uint16* data_len_p;
    kal_uint8 get_type;
}
media_bitstream_record_get_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 event;
}
media_bitstream_record_callback_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 handle;
    kal_uint8 event;
}
media_bitstream_record_driver_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 event;
    kal_uint8 session_id;
}
media_vid_mp4_aud_write_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 event;
}
media_vid_mp4_decode_event_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    void *user_data;
    kal_uint8 event;
    kal_uint32 session_id;
}
media_vid_media_player_aud_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 event;
    kal_uint32 session_id;
}
media_vid_media_player_vid_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
}
media_vid_mply_vid_buf_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_VID_CALL_PROC_REQ
  */
typedef struct
{
    LOCAL_PARA_HDR
    void (*proc)(void* param);  /**< the callback procedure */
    void* param;                /**< the opaque parameter for calback procedure */
} media_vid_call_proc_struct;



typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 event;
    kal_uint8 session_id;
}
media_mjpg_aud_write_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 result;
    kal_uint16 seq_num;
}
media_mjpg_play_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 event;
    void* data_p;
}
media_mjpg_decode_event_ind_struct;


/* VAL */

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 seq_num;
    kal_uint16 cam_id;
    kal_uint16 app_id;
}
media_vid_power_up_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_vid_power_down_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_bool zoom_in;
    kal_uint8 zoom_limit;
    kal_uint8 zoom_step;
    kal_uint8 zoom_speed;
}
media_vid_start_fast_zoom_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_vid_stop_fast_zoom_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 *factor;
    kal_uint32 *step;
}
media_vid_get_fast_zoom_factor_req_struct;

typedef CAL_CAMERA_DIGITAL_ZOOM_OUT_STRUCT media_vid_zoom_capability_info_struct;
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 image_size;
    media_vid_zoom_capability_info_struct* result_p;

}media_vid_zoom_capability_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 param_id;
    kal_int16 value;
}
media_vid_rec_set_param_req_struct;


typedef struct
{
    LOCAL_PARA_HDR
    void* data_p;
    kal_uint8 src_id;
    kal_uint8 event;
}
mpl_recorder_read_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint64 *cur_time_p;
}
media_vid_get_record_time_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint64 *cur_frame_num_p;
}
media_vid_get_record_frame_num_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint64 *cur_size_p;
}
media_vid_get_record_size_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void (*callback)(void* param, void* param1);
    void* param;
    void* param1;
}
mp4_recorder_async_callback_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    void (*callback)(void* param, void* param1);
    void* param;
    void* param1;
}
avi_recorder_async_callback_req_struct;

/**
  * Parameter for MSG_ID_MEDIA_MPL_ASYNC_CALLBACK_REQ.
  */
typedef struct
{
    LOCAL_PARA_HDR
    void (*callback)(void* param);  /**< the callback fucntion */
    void* param;                    /**< the opaque parameter for calback function */
} media_mpl_async_callback_req_struct;

#ifdef __STREAM_SERVER_SUPPORT__
#define __MED_AT_DEBUG__
#endif 


#endif /* _MED_STRUCT_H */
