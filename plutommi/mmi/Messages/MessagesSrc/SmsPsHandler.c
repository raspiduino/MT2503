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
 * SmsPsHandler.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for MMI SMS APP.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/**************************************************************

   FILENAME : SmsPsHandler.c

   PURPOSE     : It handles protocol SMS messages. 

   REMARKS     : nil

   AUTHOR      : Magesh K, Hiran 

   DATE     : 01-01-2003

**************************************************************/
#include "MMI_features.h"
#ifdef __MMI_TELEPHONY_SUPPORT__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui_typedef.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "ps_public_struct.h"
#include "mmi_rp_app_sms_def.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "kal_release.h"
#include "DebugInitDef_Int.h"
#include "string.h"
#include "nvram_common_defs.h"
#include "SmsAppGprot.h"
#include "GpioSrvGprot.h"
#include "mmi_frm_input_gprot.h"
#include "Unicodexdcl.h"
#include "custom_mmi_default_value.h"
#include "mmi_frm_events_gprot.h"
#include "CustDataRes.h"
#include "gui_data_types.h"
#include "UmSrvStruct.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "mmi_frm_queue_gprot.h"
#include "NotificationGprot.h"
#ifdef __UM_SUPPORT__
#include "mmi_rp_app_unifiedmessage_def.h"
#endif
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
#include "FileMgrSrvGProt.h"
#endif
#include "UmSrvDefs.h"

#include "MessagesMiscell.h"
#include "MessagesExDcl.h"
#include "SmsGuiInterfaceProt.h"
#include "SMsGuiInterfaceType.h"
#include "SmsPsHandler.h"
#include "l4c2smsal_struct.h"
#include "ems.h"
#include "SmsSrvGprot.h"
#include "UMGProt.h"

#ifdef __MMI_UNIFIED_COMPOSER__
#include "UcAppGprot.h"
#endif /* __MMI_UNIFIED_COMPOSER__ */

#ifdef __MMI_MSG_UM_LOW_MEMORY_COST__
#include "DateTimeGprot.h"
#endif /* __MMI_MSG_UM_LOW_MEMORY_COST__ */


#if defined(__MMI_VUI_HOMESCREEN__)
#include "IdleRecentEventGprot.h"
#endif /* __MMI_VUI_HOMESCREEN__ */

#include "DateTimeType.h"
#include "IdleNotificationManagerGprot.h"
#include "SmsAppType.h"
#include "SmsAppProt.h"
#include "SmsAppMsg.h"
#include "SmsAppUtil.h"
#include "UcmSrvGprot.h"

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
#include "UmSrvDefs.h"
#endif /*__SRV_UM_THREAD_MESSAGE_SUPPORT__*/

#include "SimCtrlSrvGProt.h"
#include "IdleGprot.h"
#include "ModeSwitchSrvGprot.h"

extern const S32 sms_msg_waiting_icon[];
#if (MMI_MAX_SIM_NUM == 2) && defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) && !defined(__MMI_SLIM_IMG_RES__)&& !defined(__MMI_NCENTER_SUPPORT__)
extern const S32 sms_msg_waiting_icon_no_sim[];
#endif

#ifdef __MMI_OPERATOR_LOGO__
extern void mmi_op_logo_parse_ota_data(void);
#endif 

#ifdef __MMI_CLI_ICON__
extern void mmi_cli_icon_parse_ota_data(void);
#endif 
#ifndef __ULC_SLIM_EMS__
extern void MoveCursorToPosition(EMSData *data, EMSPosition *dst);
#endif
extern void mmi_sms_reset_msg_waiting_flag_ext(mmi_sim_enum sim);

extern EMSData *GetEMSDataForView(EMSData **p, U8 force);
extern EMSData *GetEMSDataForEdit(EMSData **p, U8 force);
static void mmi_sms_update_msg_screen(MMI_BOOL is_update_msg, MMI_BOOL is_update_icon);
static void mmi_sms_update_new_sms_ind(srv_sms_storage_enum storage_type);

static void mmi_sms_sim_enable_icon_update(mmi_sim_enum sim);
static void mmi_sms_sim_disable_icon_update(mmi_sim_enum sim);
static void mmi_sms_sim_ctrl_change_sms_close(void);


/*******************************************************


            protocol event handler           


*******************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_sim_disable_icon_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_sim_disable_icon_update(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !((defined(__MMI_SLIM_IMG_RES__) && (MMI_MAX_SIM_NUM <= 2)) || defined(__MMI_NCENTER_SUPPORT__))
    U32 start = 0;
    U32 end;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__MMI_SLIM_IMG_RES__) && (MMI_MAX_SIM_NUM <= 2)) || defined(__MMI_NCENTER_SUPPORT__)
    //mmi_sms_reset_msg_waiting_flag_ext(sim);
    mmi_sms_check_msg_waiting_icon();
#else
#ifdef __MMI_SLIM_IMG_RES__
    start = mmi_frm_sim_to_index(sim) *MAX_WAITING_TYPE_NUM;
#elif (MMI_MAX_SIM_NUM >= 2)
    start = mmi_frm_sim_to_index(sim) *15;
#endif

#ifdef __MMI_SLIM_IMG_RES__
    end = start + MAX_WAITING_TYPE_NUM;
#else
    end = start + 15;
#endif

    for (; start < end; start++)
    {
        wgui_status_icon_bar_reset_icon_display (sms_msg_waiting_icon[start]);
    #if (MMI_MAX_SIM_NUM == 2) && defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) && !defined(__MMI_SLIM_IMG_RES__)&& !defined(__MMI_NCENTER_SUPPORT__)
        if(!srv_sim_ctrl_is_inserted(MMI_SIM1) && !srv_sim_ctrl_is_inserted(MMI_SIM2))
        {
            wgui_status_icon_bar_reset_icon_display(sms_msg_waiting_icon_no_sim[start%MMI_SMS_MSG_WAITING_FLAG_NUM]);
        }
        else
        {
            mmi_sms_check_msg_waiting_icon();
        }
    #endif
    }

    wgui_status_icon_bar_update();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_sim_enable_icon_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_sim_enable_icon_update(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_mode_switch_is_network_service_available())
    {
        mmi_sms_check_msg_waiting_icon();
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_sms_sim_ctrl_change_sms_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_sim_ctrl_change_sms_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GRP_ID_INVALID != g_sms_gid)
    {
        mmi_frm_group_close(g_sms_gid);
    }

    mmi_sms_vm_group_close();
#ifdef __MMI_TELEPHONY_SUPPORT__
    mmi_sms_settings_group_close();
#endif /* __MMI_TELEPHONY_SUPPORT__ */
#ifdef __MMI_MESSAGES_TEMPLATE__
    mmi_sms_template_group_close();
#endif
}
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_sim_ctrl_availability_changed_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_sim_ctrl_availability_changed_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_availability_changed_evt_struct *availability_changed_evt = (srv_sim_ctrl_availability_changed_evt_struct*)evt;
    mmi_sim_enum changed_sim = MMI_SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_SIM_CTRL_UA_CAUSE_BT_ACCESS_PROFILE == availability_changed_evt->unavailable_cause)
    {
        mmi_sms_sim_ctrl_change_sms_close();
    }

    changed_sim = availability_changed_evt->sim;

    if ((availability_changed_evt->is_available_before)
        && (availability_changed_evt->is_available_now == MMI_FALSE)
        )
    {
        mmi_sms_sim_disable_icon_update(changed_sim);
    }

    if ((MMI_FALSE == availability_changed_evt->is_available_before)
        && (availability_changed_evt->is_available_now)
        )
    {
        mmi_sms_sim_enable_icon_update(changed_sim);
    }

    return MMI_RET_OK;
}


#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_sim_ctrl_sim_ctrl_change_detected_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_sim_ctrl_sim_ctrl_change_detected_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_event_detected_evt_struct *sim_ctrl_changed_evt = (srv_sim_ctrl_event_detected_evt_struct*)evt;
    mmi_sim_enum changed_sim = SRV_SMS_SIM_1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_SIM_CTRL_EVENT_DET_INSERTED != sim_ctrl_changed_evt->type)
    {
        mmi_sms_sim_ctrl_change_sms_close();
    }
    changed_sim = sim_ctrl_changed_evt->sim;

    switch (sim_ctrl_changed_evt->type)
    {
        case SRV_SIM_CTRL_EVENT_DET_BT_ACCESS_ON:
        case SRV_SIM_CTRL_EVENT_DET_DISCONNECTED:
        case SRV_SIM_CTRL_EVENT_DET_REMOVED:
    #ifdef __SIM_RECOVERY_ENHANCEMENT__
        case SRV_SIM_CTRL_EVENT_DET_RECOVERY_START:
    #endif /* __SIM_RECOVERY_ENHANCEMENT__ */
        {
            mmi_sms_sim_disable_icon_update(changed_sim);

            if (sim_ctrl_changed_evt->type == SRV_SIM_CTRL_EVENT_DET_REMOVED)
            {
                mmi_sms_reset_msg_waiting_flag_ext(changed_sim);
            }
            break;
        }

        case SRV_SIM_CTRL_EVENT_DET_BT_ACCESS_OFF:
        case SRV_SIM_CTRL_EVENT_DET_CONNECTED:
        case SRV_SIM_CTRL_EVENT_DET_REINIT_VERIFIED:
    #ifdef __SIM_RECOVERY_ENHANCEMENT__
        case SRV_SIM_CTRL_EVENT_DET_RECOVERY_END:
    #endif /* __SIM_RECOVERY_ENHANCEMENT__ */
        {
            mmi_sms_sim_enable_icon_update(changed_sim);
            break;
        }
        
        case SRV_SIM_CTRL_EVENT_DET_INSERTED:
        default:
        {
            break;
        }
     }
    
    return MMI_RET_OK;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_mode_switch_finish_evt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_mode_switch_finish_evt_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_notify_struct *flight_mode_evt = (srv_mode_switch_notify_struct*)evt;
    S32 i = 0;
    S32 max;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY)
    {
        if ((flight_mode_evt->gsm_curr_mode != SRV_MODE_SWITCH_ALL_OFF)
            &&(flight_mode_evt->gsm_select_mode == SRV_MODE_SWITCH_ALL_OFF)
            )
        {
        #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
            wgui_status_icon_bar_hide_icon(STATUS_ICON_SMS_SENDING);
        #endif

        #if (defined(__MMI_SLIM_IMG_RES__) && (MMI_MAX_SIM_NUM <= 2))  || defined(__MMI_NCENTER_SUPPORT__)
            max = MAX_WAITING_TYPE_NUM;
        #elif defined(__MMI_SLIM_IMG_RES__) && (MMI_MAX_SIM_NUM >= 3)
            max = MMI_SMS_MAX_MSG_WAITING_ICON/3;
        #else
            max = MMI_SMS_MAX_MSG_WAITING_ICON;
        #endif

            for (i = 0; i < max; i++)
            {
            #if (MMI_MAX_SIM_NUM == 2) && defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) && !defined(__MMI_SLIM_IMG_RES__)&& !defined(__MMI_NCENTER_SUPPORT__)
                if(!srv_sim_ctrl_is_inserted(MMI_SIM1) || !srv_sim_ctrl_is_inserted(MMI_SIM2))
                {
                    wgui_status_icon_bar_reset_icon_display(sms_msg_waiting_icon_no_sim[i%MMI_SMS_MSG_WAITING_FLAG_NUM]);
                }
                else
            #endif
                wgui_status_icon_bar_reset_icon_display(sms_msg_waiting_icon[i]);
            }

            wgui_status_icon_bar_update();
        }
        else if (flight_mode_evt->gsm_select_mode != SRV_MODE_SWITCH_ALL_OFF)
        {
            mmi_sms_check_msg_waiting_icon();
        #ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
            srv_sms_send_from_storage_schedule();
        #endif
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_ready_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_handle_ready_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_sms_ready_struct *event_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_info = (srv_sms_event_sms_ready_struct*)event_data->event_info;

    /* The case of SMS not Ready is only happened when SIM Refresh */
    if (event_info->is_sms_ready == MMI_TRUE)
    {
      #if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        mmi_sms_update_sidebar_info();
        mmi_sms_update_shct_data();
        mmi_voicemail_update_op11_hs32_vm_shct_data();
    #endif /* #if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

    #ifdef __MMI_VUI_HOMESCREEN__
        if ((mmi_hs_is_on_recent_event() == MMI_TRUE))
        {
            mmi_msg_hs_update_sms_recent_event(MMI_HS_MAX_RECENT_EVENT_NUM);
        }
    #endif /* __MMI_VUI_HOMESCREEN__ */

        mmi_sms_set_msg_icon(MMI_TRUE, SRV_SMS_SIM_1);
    #if (MMI_MAX_SIM_NUM >= 2)
        mmi_sms_set_msg_icon(MMI_TRUE, SRV_SMS_SIM_2);
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        mmi_sms_set_msg_icon(MMI_TRUE, SRV_SMS_SIM_3);
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        mmi_sms_set_msg_icon(MMI_TRUE, SRV_SMS_SIM_4);
    #endif

    #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        mmi_msg_update_unsent_icon();
        if (srv_mode_switch_is_network_service_available())
        {
            srv_sms_send_from_storage_schedule();
        }
    #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

    #ifdef __MMI_UM_ITERATOR_VIEWER__
        g_sms_cntx.iter_viewer_result = NULL;
    #endif /* __MMI_UM_ITERATOR_VIEWER__ */
    }
    else
    {
        if (g_sms_gid != GRP_ID_INVALID)
        {
            mmi_frm_group_close(g_sms_gid);
        }
        mmi_sms_vm_group_close();
#ifdef __MMI_TELEPHONY_SUPPORT__
        mmi_sms_settings_group_close();
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    #ifdef __MMI_MESSAGES_TEMPLATE__
        mmi_sms_template_group_close();
    #endif

        mmi_sms_hide_msg_icon(SRV_SMS_SIM_1);
    #if (MMI_MAX_SIM_NUM >= 2)
        mmi_sms_hide_msg_icon(SRV_SMS_SIM_2);
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        mmi_sms_hide_msg_icon(SRV_SMS_SIM_3);
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        mmi_sms_hide_msg_icon(SRV_SMS_SIM_4);
    #endif

    #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
	#if 0
/* under construction !*/
	#endif
    #endif
    }

    return MMI_RET_OK;
}


#ifdef __MMI_NCENTER_SUPPORT__
#include "vsrv_ncenter.h"
#include "umncentergprot.h"
#include "UcmGprot.h"
#include "voicemail.h"
#include "mmi_rp_srv_status_icons_def.h"
#include "NotificationSettingSrvGprot.h"

#define MMI_SMS_MSG_WAITING_LINE_NUM      (2)
#define MMI_SMS_MAX_WAITING_CENTER_NUM    (6)

typedef enum
{
    MMI_SMS_NEW_VOCIEMAIL_WAITING_IND  = 0x00,
    MMI_SMS_NEW_FAX_WAITING_IND        = 0x01,
    MMI_SMS_NEW_EMAIL_WAITING_IND      = 0x02,
    MMI_SMS_NEW_NET_MSG_WAITING_IND    = 0x03,
    MMI_SMS_NEW_VEDIO_WAITING_IND      = 0x04,
    MMI_SMS_MAX_MSG_WAITING_TYPE       = 0x05
}mmi_sms_msg_waiting_type_enum;

typedef enum
{
    MMI_MSG_WAITING_LINE1, /* line 1 */
    MMI_MSG_WAITING_LINE2, /* line 2 */
    MMI_MSG_WAITING_NOT_SUPPORT, /* not support */
    MMI_MSG_WAITING_LINE_END /* End of the enum */
}mmi_msg_waiting_line_id_enum;

typedef struct{
    U8 waitingNum;
    U8 indType;
    MMI_BOOL isShowNum;
    MMI_BOOL isValid;
}mmi_sms_waiting_data_struct;

typedef struct{
    U8 lineNo; /* Number of Line*/
    U8 mspNo;
    U8 waitingNum;
    U8 indType;
    MMI_BOOL isShowNum;
    MMI_BOOL isClear;
    MMI_BOOL isfromStorage;
}mmi_sms_waiting_ind_info_struct;

mmi_sms_waiting_data_struct msgWaitingInfo[MMI_SIM_TOTAL][MMI_SMS_MSG_WAITING_LINE_NUM][MMI_SMS_MAX_MSG_WAITING_TYPE];

static const vsrv_notification_id ncenter_notify_id[] = 
{
    MMI_SMS_NCENTER_ID_UNREAD_VOICE_LINE1
    ,MMI_SMS_NCENTER_ID_UNREAD_VOICE_LINE2
    ,MMI_SMS_NCENTER_ID_UNREAD_FAX
    ,MMI_SMS_NCENTER_ID_UNREAD_EMAIL
    ,MMI_SMS_NCENTER_ID_UNREAD_NET
    ,MMI_SMS_NCENTER_ID_UNREAD_VIDEO

#if (MMI_MAX_SIM_NUM >= 2)
    ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_VOICE_LINE1
    ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_VOICE_LINE2
    ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_FAX
    ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_EMAIL
    ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_NET
    ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_VIDEO
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_VOICE_LINE1
    ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_VOICE_LINE2
    ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_FAX
    ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_EMAIL
    ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_NET
    ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_VIDEO
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_VOICE_LINE1
    ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_VOICE_LINE2
    ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_FAX
    ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_EMAIL
    ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_NET
    ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_VIDEO
#endif
};

extern U64 g_sms_wait_icon;

static void mmi_sms_get_waiting_text(mmi_sim_enum mmi_sim, mmi_msg_waiting_line_id_enum line_id, U8 WaitingType, U16 *ucs2_buff, U32 size);

MMI_BOOL mmi_sms_get_waiting_info_flag(mmi_sim_enum mmi_sim, U32 line_no, U32 waiting_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 flagIndex = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    flagIndex = mmi_frm_sim_to_index(mmi_sim) *MMI_SMS_MSG_WAITING_LINE_NUM *MMI_SMS_MAX_MSG_WAITING_TYPE;
#endif

    flagIndex = flagIndex+ waiting_type * MMI_SMS_MSG_WAITING_LINE_NUM + line_no;
    
    MMI_ASSERT(flagIndex < 64);

    if ((g_sms_wait_icon>>flagIndex)&0x01)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

void mmi_sms_set_waiting_info_flag(mmi_sim_enum mmi_sim, U8 lineNo, U8 waitingType, MMI_BOOL showFlag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 flagIndex = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    flagIndex = mmi_frm_sim_to_index(mmi_sim) *MMI_SMS_MSG_WAITING_LINE_NUM *MMI_SMS_MAX_MSG_WAITING_TYPE;
#endif

    flagIndex = flagIndex+ waitingType * MMI_SMS_MSG_WAITING_LINE_NUM + lineNo;

    MMI_ASSERT(flagIndex < 64);

    if (showFlag)
    {
        g_sms_wait_icon |= (U64)1<<flagIndex;
    }
    else
    {
        g_sms_wait_icon &= ~((U64)1<<flagIndex);
    }

    //S16 error;
    //if (WriteValue(VAPP_SMS_MSG_WAITING_HIDE_FLAG, &m_hideFlag, DS_DOUBLE, &error) < 0)
    //{
    //    MMI_ASSERT(0);
    //}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_waiting_dial_mailbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_waiting_dial_mailbox(mmi_sim_enum mmi_sim, U8 line_no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    U32 index;
    U16 mailbox_addr[MAX_CC_ADDR_LEN +1 ];
    mmi_ucm_make_call_para_struct makecall_para; 
    static const srv_sms_mailbox_struct *mailbox;
    srv_ucm_call_type_enum call_type[] =
    {
        SRV_UCM_VOICE_CALL_TYPE
#if (MMI_MAX_SIM_NUM >= 2)
        ,SRV_UCM_VOICE_CALL_TYPE_SIM2
#endif 
#if (MMI_MAX_SIM_NUM >= 3)
        ,SRV_UCM_VOICE_CALL_TYPE_SIM3
#endif 
#if (MMI_MAX_SIM_NUM >= 4)
        ,SRV_UCM_VOICE_CALL_TYPE_SIM4
#endif 
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
    mailbox =  srv_sms_get_mailbox_setting(SRV_SMS_MMI_SIM_TO_SMS(mmi_sim));
    mmi_ucs2cpy((CHAR*)mailbox_addr, (CHAR*)mailbox->p_mailbox_number[line_no]);

    mmi_ucm_init_call_para(&makecall_para);
    makecall_para.ucs2_num_uri = mailbox_addr;   
    index = mmi_frm_sim_to_index(mmi_sim);
    makecall_para.dial_type = call_type[index];
    makecall_para.adv_para.module_id = SRV_UCM_MODULE_ORIGIN_VOICE_MAIL;

    mmi_ucm_call_launch(GRP_ID_ROOT, &makecall_para);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_check_is_show_waiting_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_sim            [IN]         
 *  line_id               [IN]        
 *  WaitingType      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_check_is_show_waiting_num(mmi_sim_enum mmi_sim, mmi_msg_waiting_line_id_enum line_id, U8 WaitingType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 simIndex = mmi_frm_sim_to_index(mmi_sim);
    MMI_BOOL showNum = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
    if (line_id == MMI_MSG_WAITING_NOT_SUPPORT)
    {
        mmi_sms_waiting_data_struct *cache_info[MMI_SMS_MSG_WAITING_LINE_NUM];

        cache_info[0] = &(msgWaitingInfo[simIndex][0][WaitingType]);
        cache_info[1] = &(msgWaitingInfo[simIndex][0][WaitingType]);

        if ((cache_info[0]->isValid && !(cache_info[0]->isShowNum))
            || (cache_info[1]->isValid && !(cache_info[1]->isShowNum))
            )
        {
            showNum = MMI_FALSE;
        }
    }
    else
    {
        showNum = msgWaitingInfo[simIndex][line_id][WaitingType].isShowNum;
    }

    return showNum;
}



U8 mmi_sms_get_waiting_num(mmi_sim_enum mmi_sim, mmi_msg_waiting_line_id_enum line_id, U8 WaitingType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 simIndex = mmi_frm_sim_to_index(mmi_sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
    if (line_id != MMI_MSG_WAITING_LINE2)
    {
        line_id = MMI_MSG_WAITING_LINE1;
    }

    return msgWaitingInfo[simIndex][line_id][WaitingType].waitingNum;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_check_is_valid_waiting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_sim            [IN]         
 *  line_id               [IN]        
 *  WaitingType      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_sms_check_is_valid_waiting(mmi_sim_enum mmi_sim, mmi_msg_waiting_line_id_enum line_id, U8 WaitingType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 simIndex = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
    simIndex = mmi_frm_sim_to_index(mmi_sim);

    if (line_id != MMI_MSG_WAITING_LINE2)
    {
        line_id = MMI_MSG_WAITING_LINE1;
    }

    if (msgWaitingInfo[simIndex][line_id][WaitingType].isValid
        && mmi_sms_get_waiting_info_flag(mmi_sim, (U32)line_id, (U32)WaitingType)
        )
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


void mmi_sms_waiting_show_state_change(mmi_sim_enum mmi_sim, mmi_msg_waiting_line_id_enum lineId, mmi_sms_msg_waiting_type_enum waitingType, MMI_BOOL show)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 statusIcon[] = 
    {
        STATUS_ICON_UNREAD_VOICE
        #ifndef __MMI_STATUS_ICON_BAR_SLIM__
        ,STATUS_ICON_UNREAD_FAX
        ,STATUS_ICON_UNREAD_EMAIL_MSG
        ,STATUS_ICON_UNREAD_NET
        ,STATUS_ICON_UNREAD_VIDEO
        #endif
    };
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
    mmi_sms_set_waiting_info_flag(mmi_sim, lineId, waitingType, show);

    if (show)
    {
        //show waiting status icon
        //wgui_status_icon_bar_set_icon_display(statusIcon[waitingType]);
        //wgui_status_icon_bar_update();
    }
    else
    {
        MMI_BOOL hide_icon = MMI_TRUE;

        for (index = 0; index < MMI_SIM_TOTAL; index++)
        {
            mmi_sim_enum curSim = mmi_frm_index_to_sim(index);

            if (mmi_sms_check_is_valid_waiting(curSim, MMI_MSG_WAITING_LINE1, waitingType))
            {
                hide_icon = MMI_FALSE;
                break;
            }
            else if (mmi_sms_check_is_valid_waiting(curSim, MMI_MSG_WAITING_LINE2, waitingType))
            {
                hide_icon = MMI_FALSE;
                break;
            }
        }

        if (hide_icon)
        {
            mmi_event_notify_enum event_type[] = 
            {
                MMI_EVENT_MESSAGE_SIM1_WAITING
                ,MMI_EVENT_MESSAGE_SIM2_WAITING
            #if (MMI_MAX_SIM_NUM >= 3)
                ,MMI_EVENT_MESSAGE_SIM3_WAITING
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                ,MMI_EVENT_MESSAGE_SIM4_WAITING
            #endif
            };
            NMGR_HANDLE waiting_nmgr_handle;

            for (index = 0; index < MMI_SIM_TOTAL; index++)
            {
                waiting_nmgr_handle = mmi_frm_nmgr_compose_alert_handle(APP_UNIFIEDMESSAGE, event_type[index], statusIcon[waitingType]);
                if (waiting_nmgr_handle)
                {
                    mmi_frm_nmgr_alert_cancel(waiting_nmgr_handle);
                }
            }
            waiting_nmgr_handle = mmi_frm_nmgr_compose_alert_handle(APP_UNIFIEDMESSAGE, 0, statusIcon[waitingType]);
            if (waiting_nmgr_handle)
            {
                mmi_frm_nmgr_alert_cancel(waiting_nmgr_handle);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_msg_waiting_ind_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pMsgIndExt      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_handle_msg_waiting_callback(vsrv_notification_handle handle, vsrv_nintent intent, void* userData, U32 userDataSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                        */
    /*----------------------------------------------------------------*/
    vsrv_notification_id eventType[] = 
    {
        MMI_SMS_NCENTER_ID_UNREAD_VOICE_LINE1
        ,MMI_SMS_NCENTER_ID_UNREAD_VOICE_LINE2
        ,MMI_SMS_NCENTER_ID_UNREAD_FAX
        ,MMI_SMS_NCENTER_ID_UNREAD_EMAIL
        ,MMI_SMS_NCENTER_ID_UNREAD_NET
        ,MMI_SMS_NCENTER_ID_UNREAD_VIDEO

    #if (MMI_MAX_SIM_NUM >= 2)
        ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_VOICE_LINE1
        ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_VOICE_LINE2
        ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_FAX
        ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_EMAIL
        ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_NET
        ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_VIDEO
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_VOICE_LINE1
        ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_VOICE_LINE2
        ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_FAX
        ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_EMAIL
        ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_NET
        ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_VIDEO
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_VOICE_LINE1
        ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_VOICE_LINE2
        ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_FAX
        ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_EMAIL
        ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_NET
        ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_VIDEO
    #endif
    };
    U32 index;
    U32 size = sizeof(eventType);
    U32 *entry_id = (U32*)userData;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
    for (index = 0; index < size; index++)
    {
        mmi_sim_enum mmi_sim = mmi_frm_index_to_sim(index/6);
        mmi_sms_msg_waiting_type_enum waitingType;
        U32 limit = index%6;

        if (limit == 0 || limit == 1)
        {
            waitingType = MMI_SMS_NEW_VOCIEMAIL_WAITING_IND;
        }
        else
        {
            waitingType = (mmi_sms_msg_waiting_type_enum)(limit - 1);
        }

        if (eventType[index] == entry_id[0])
        {
            if (intent.type == VSRV_NINTENT_TYPE_LANGUAGE_CHANGED)
            {
                U32 line_id = 0;
                WCHAR main_text[MMI_NEW_MSG_WAITING_INFO_LEN];

                if (waitingType == MMI_SMS_NEW_VOCIEMAIL_WAITING_IND)
                {
                    line_id = limit;
                }
                mmi_sms_get_waiting_text(mmi_sim, line_id, waitingType,(U16*)main_text, MMI_NEW_MSG_WAITING_INFO_LEN);
                vsrv_ncenter_set_notification_maintext_str(handle, main_text);
                vsrv_ncenter_notify_notification(handle);

                return;
            }

            if (intent.type == VSRV_NINTENT_TYPE_LAUNCH)
            {
                if (waitingType == MMI_SMS_NEW_VOCIEMAIL_WAITING_IND)
                {
                    mmi_sms_waiting_dial_mailbox(mmi_sim, limit);
                }
            }

            if ((intent.type == VSRV_NINTENT_TYPE_LAUNCH) || (intent.type == VSRV_NINTENT_TYPE_CLEAR))
            {
                if (waitingType == MMI_SMS_NEW_VOCIEMAIL_WAITING_IND)
                {
                #if (MMI_MAX_SIM_NUM >= 2)
                    mmi_sim_enum curr_mmi_sim = g_msg_cntx.msg_waiting_info[g_msg_cntx.msg_waiting_line_number].curr_sim;
                #endif

              //      mmi_sms_waiting_show_state_change(mmi_sim, (mmi_msg_waiting_line_id_enum)limit, waitingType, MMI_FALSE);  //Akhil

                    if (g_msg_cntx.msg_waiting_line_number == limit && g_msg_cntx.msg_waiting_ind == waitingType + 1
                    #if (MMI_MAX_SIM_NUM >= 2)
                        && (curr_mmi_sim == mmi_sim) 
                    #endif
                        )
                    {
                        g_msg_cntx.msg_waiting_info[limit].number[waitingType] = 0;

                        /* clear notification manager */
                        if (g_msg_cntx.msg_waiting_ind == 1)
                        {
                         #ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
                            mmi_nmgr_refresh(MMI_NMGR_APP_MESSAGE_WAITING, MMI_NMGR_OPTION_USE_DEFAULT);
                         #endif
                        }

                        g_msg_cntx.msg_waiting_ind = 0;
                    }
                }
                else
                {
                    mmi_sms_waiting_show_state_change(mmi_sim, MMI_MSG_WAITING_LINE1, waitingType , MMI_FALSE);
                    mmi_sms_waiting_show_state_change(mmi_sim, MMI_MSG_WAITING_LINE2, waitingType , MMI_FALSE);
                }
            }

            break;
        }
    }
}


static void mmi_sms_get_waiting_text(mmi_sim_enum mmi_sim, mmi_msg_waiting_line_id_enum line_id, U8 WaitingType, U16 *ucs2_buff, U32 size)
{
    U16 stringId = 0;
    MMI_BOOL isShowNum = mmi_sms_check_is_show_waiting_num(mmi_sim, line_id, WaitingType);
    U16 waitingNum = 0;

    if (isShowNum)
    {
        if (MMI_MSG_WAITING_NOT_SUPPORT == line_id)
        {
            if (mmi_sms_check_is_valid_waiting(mmi_sim, MMI_MSG_WAITING_LINE2, WaitingType))
            {
                waitingNum += mmi_sms_get_waiting_num(mmi_sim, MMI_MSG_WAITING_LINE2, WaitingType);
            }

            if (mmi_sms_check_is_valid_waiting(mmi_sim, MMI_MSG_WAITING_LINE1, WaitingType))
            {
                waitingNum += mmi_sms_get_waiting_num(mmi_sim, MMI_MSG_WAITING_LINE1, WaitingType);
            }
        }
        else
        {
            waitingNum = mmi_sms_get_waiting_num(mmi_sim, line_id, WaitingType);

            if (MMI_SMS_NEW_VOCIEMAIL_WAITING_IND != WaitingType)
            {
                if (MMI_MSG_WAITING_LINE1 == line_id)
                {
                    if (mmi_sms_check_is_valid_waiting(mmi_sim, MMI_MSG_WAITING_LINE2, WaitingType))
                    {
                        waitingNum += mmi_sms_get_waiting_num(mmi_sim, MMI_MSG_WAITING_LINE2, WaitingType);
                    }
                }
                else if (MMI_MSG_WAITING_LINE2 == line_id)
                {
                    if (mmi_sms_check_is_valid_waiting(mmi_sim, MMI_MSG_WAITING_LINE1, WaitingType))
                    {
                        waitingNum += mmi_sms_get_waiting_num(mmi_sim, MMI_MSG_WAITING_LINE1, WaitingType);
                    }
                }
            }
        }
    }

    if (isShowNum && (waitingNum >= 1) && (waitingNum < 255))
    {
        if (waitingNum == 1)
        {
            switch (WaitingType)
            {
                case MMI_SMS_NEW_VOCIEMAIL_WAITING_IND:
                    if (MMI_MSG_WAITING_LINE2 == line_id)
                    {
                        stringId = STR_ID_SMS_LINE2_VOICEMAIL_NUM_IND;
                    }
                    else
                    {
                        stringId = STR_ID_SMS_NEW_VOICEMAIL_NUM_IND;
                    }
                    break;
                case MMI_SMS_NEW_FAX_WAITING_IND:
                    stringId = STR_ID_SMS_NEW_FAX_NUM_IND;
                    break;
                case MMI_SMS_NEW_EMAIL_WAITING_IND:
                    stringId = STR_ID_SMS_NEW_EMAIL_NUM_IND;
                    break;
                case MMI_SMS_NEW_NET_MSG_WAITING_IND:
                    stringId = STR_ID_SMS_NEW_NET_MSG_NUM_IND;
                    break;
                case MMI_SMS_NEW_VEDIO_WAITING_IND:
                    stringId = STR_ID_SMS_NEW_VEDIO_NUM_IND;
                    break;
                default:
                    MMI_ASSERT(0);
                    break;
            }
        }
        else
        {
            switch (WaitingType)
            {
                case MMI_SMS_NEW_VOCIEMAIL_WAITING_IND:
                    if (MMI_MSG_WAITING_LINE2 == line_id)
                    {
                        stringId = STR_ID_SMS_LINE2_VOICEMAIL_NUM_IND_PLURAL;
                    }
                    else
                    {
                        stringId = STR_ID_SMS_NEW_VOICEMAIL_NUM_IND_PLURAL;
                    }
                    break;
                case MMI_SMS_NEW_FAX_WAITING_IND:
                    stringId = STR_ID_SMS_NEW_FAX_NUM_IND_PLURAL;
                    break;
                case MMI_SMS_NEW_EMAIL_WAITING_IND:
                    stringId = STR_ID_SMS_NEW_EMAIL_NUM_IND_PLURAL;
                    break;
                case MMI_SMS_NEW_NET_MSG_WAITING_IND:
                    stringId = STR_ID_SMS_NEW_NET_MSG_NUM_IND_PLURAL;
                    break;
                case MMI_SMS_NEW_VEDIO_WAITING_IND:
                    stringId = STR_ID_SMS_NEW_VEDIO_NUM_IND_PLURAL;
                    break;
                default:
                    MMI_ASSERT(0);
                    break;
            }
        }
    }
    else
    {
        switch (WaitingType)
        {
            case MMI_SMS_NEW_VOCIEMAIL_WAITING_IND:
                //stringId = STR_ID_SMS_NEW_VOCIEMAIL_WAITING;
                if (MMI_MSG_WAITING_LINE2 == line_id)
                {
                    stringId = STR_ID_SMS_LINE2_NEW_VOCIEMAIL_WAITING;
                }
                else
                {
                    stringId = STR_ID_SMS_NEW_VOCIEMAIL_WAITING;
                }
                break;
            case MMI_SMS_NEW_FAX_WAITING_IND:
                stringId = STR_ID_SMS_NEW_FAX_WAITING;
                break;
            case MMI_SMS_NEW_EMAIL_WAITING_IND:
                stringId = STR_ID_SMS_NEW_EMAIL_WAITING;
                break;
            case MMI_SMS_NEW_NET_MSG_WAITING_IND:
                stringId = STR_ID_SMS_NEW_NET_MSG_WAITING;
                break;
            case MMI_SMS_NEW_VEDIO_WAITING_IND:
                stringId = STR_ID_SMS_NEW_VEDIO_WAITING;
                break;
            default:
                MMI_ASSERT(0);
                break;
        }
    }

    if (isShowNum && (waitingNum >= 1) && (waitingNum < 255))
    {
        U8 ascii_num[10];
        memset(ascii_num, 0, 10);
        sprintf((CHAR*)ascii_num, "%d ", waitingNum);
        mmi_asc_to_ucs2((CHAR*) ucs2_buff, (CHAR*) ascii_num);
        mmi_ucs2cat((CHAR*)ucs2_buff, (CHAR*)GetString(stringId));
    }
    else
    {
        mmi_ucs2cpy((CHAR*)ucs2_buff, (CHAR*)GetString(stringId));
    }
}


void mmi_sms_add_waiting_info_ind(mmi_sms_waiting_ind_info_struct *info, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum mmi_sim = SRV_SMS_SMS_SIM_TO_MMI(sim_id);
    U32 simIndex = mmi_frm_sim_to_index(mmi_sim);
    mmi_msg_waiting_line_id_enum line_id = (mmi_msg_waiting_line_id_enum)info->lineNo;
    mmi_sms_waiting_data_struct *addInfo = &msgWaitingInfo[simIndex][line_id][info->indType];
    S32 statusIcon[] = 
    {
        STATUS_ICON_UNREAD_VOICE
        #ifndef __MMI_STATUS_ICON_BAR_SLIM__
        ,STATUS_ICON_UNREAD_FAX
        ,STATUS_ICON_UNREAD_EMAIL_MSG
        ,STATUS_ICON_UNREAD_NET
        ,STATUS_ICON_UNREAD_VIDEO
        #endif
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
    if (info->indType < MMI_SMS_MAX_MSG_WAITING_TYPE)
    {
        addInfo->waitingNum = info->waitingNum;
        addInfo->indType = info->indType;
        addInfo->isShowNum = info->isShowNum;
        addInfo->isValid = MMI_TRUE;

        if (addInfo->isShowNum && addInfo->waitingNum == 0xFF)
        {
            addInfo->isShowNum = MMI_FALSE; 
            addInfo->waitingNum = 0;
        }

        //show status icon
        mmi_sms_waiting_show_state_change(mmi_sim, line_id, (mmi_sms_msg_waiting_type_enum)info->indType, MMI_TRUE);

    {
        vsrv_ngroup_handle group_handle;
        vsrv_notification_handle notify_handle;
        U32 sim_index = mmi_frm_sim_to_index(SRV_SMS_SMS_SIM_TO_MMI(sim_id));
        U16 sim_str_id[] = {
        STR_GLOBAL_SIM_1
    
    #if (MMI_MAX_SIM_NUM >= 2)
        ,STR_GLOBAL_SIM_2
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        ,STR_GLOBAL_SIM_3
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        ,STR_GLOBAL_SIM_4
    #endif
        };
        WCHAR main_text[MMI_NEW_MSG_WAITING_INFO_LEN];
        U8 line_no = info->lineNo;
        U8 ind_type = info->indType;
        vsrv_notification_id nt_id[] = {
            MMI_SMS_NCENTER_ID_UNREAD_VOICE_LINE1,
            MMI_SMS_NCENTER_ID_UNREAD_FAX,
            MMI_SMS_NCENTER_ID_UNREAD_EMAIL,
            MMI_SMS_NCENTER_ID_UNREAD_NET,
            MMI_SMS_NCENTER_ID_UNREAD_VIDEO
        #if (MMI_MAX_SIM_NUM >= 2)
            ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_VOICE_LINE1
            ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_FAX
            ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_EMAIL
            ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_NET
            ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_VIDEO
        #endif
        #if (MMI_MAX_SIM_NUM >= 3)
            ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_VOICE_LINE1
            ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_FAX
            ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_EMAIL
            ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_NET
            ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_VIDEO
        #endif
        #if (MMI_MAX_SIM_NUM >= 4)
            ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_VOICE_LINE1
            ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_FAX
            ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_EMAIL
            ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_NET
            ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_VIDEO
        #endif
        };
        static U32 entry_id;
        
        
        group_handle = mmi_um_create_ncenter_group();
    
        if ((line_no == MMI_MSG_WAITING_LINE2) && (ind_type == MMI_SMS_NEW_VOCIEMAIL_WAITING_IND))
        {
            entry_id = nt_id[sim_index*MAX_WAITING_TYPE_NUM] + 1; /* vociemail line 2 */
        }
        else
        {
            entry_id = nt_id[sim_index*MAX_WAITING_TYPE_NUM + ind_type];
        }

        notify_handle = vsrv_ncenter_query_notification(group_handle, entry_id);
    
        if (notify_handle == NULL)
        {
            notify_handle = vsrv_ncenter_create_notification(VSRV_NOTIFICATION_TYPE_EVENT,
                                group_handle,
                                entry_id);
        }

        mmi_sms_get_waiting_text(mmi_sim, line_id, ind_type,(U16*)main_text, MMI_NEW_MSG_WAITING_INFO_LEN);

        vsrv_ncenter_set_notification_maintext_str(notify_handle, main_text);
    
    #if (MMI_MAX_SIM_NUM >= 2)
        vsrv_ncenter_set_notification_subtext_id(notify_handle, sim_str_id[sim_index]);
    #endif
    
        vsrv_ncenter_set_notification_intent_callback(notify_handle,
                mmi_sms_handle_msg_waiting_callback,
                &entry_id,
                4);
    
        vsrv_ncenter_notify_notification(notify_handle);
    }
        //m_signalMsgWaitingStateChanged.postEmit(mmi_sim, line_id, (vapp_sms_msg_waiting_type_enum)addInfo->indType, MMI_TRUE);
    }
}

void mmi_sms_clear_waiting_info_ind(mmi_sms_waiting_ind_info_struct *info, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_sim_enum mmi_sim = SRV_SMS_SMS_SIM_TO_MMI(sim_id);
    U32 simIndex = mmi_frm_sim_to_index(mmi_sim);
    mmi_msg_waiting_line_id_enum line_id = (mmi_msg_waiting_line_id_enum)info->lineNo;
    mmi_sms_waiting_data_struct *clearInfo;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
    if (line_id != MMI_MSG_WAITING_LINE2)
    {
        line_id = MMI_MSG_WAITING_LINE1;
    }

    clearInfo = &msgWaitingInfo[simIndex][line_id][info->indType];

    memset(clearInfo, 0, sizeof(mmi_sms_waiting_data_struct));

    mmi_sms_waiting_show_state_change(mmi_sim, line_id, (mmi_sms_msg_waiting_type_enum)info->indType,MMI_FALSE);

{
    vsrv_ngroup_handle group_handle;
    vsrv_notification_handle notify_handle;
    U32 sim_index = mmi_frm_sim_to_index(SRV_SMS_SMS_SIM_TO_MMI(sim_id));
    vsrv_notification_id nt_id[] = {
    MMI_SMS_NCENTER_ID_UNREAD_VOICE_LINE1,
    MMI_SMS_NCENTER_ID_UNREAD_FAX,
    MMI_SMS_NCENTER_ID_UNREAD_EMAIL,
    MMI_SMS_NCENTER_ID_UNREAD_NET,
    MMI_SMS_NCENTER_ID_UNREAD_VIDEO
#if (MMI_MAX_SIM_NUM >= 2)
    ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_VOICE_LINE1
    ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_FAX
    ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_EMAIL
    ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_NET
    ,MMI_SMS_NCENTER_ID_SIM2_UNREAD_VIDEO
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_VOICE_LINE1
    ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_FAX
    ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_EMAIL
    ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_NET
    ,MMI_SMS_NCENTER_ID_SIM3_UNREAD_VIDEO
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_VOICE_LINE1
    ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_FAX
    ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_EMAIL
    ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_NET
    ,MMI_SMS_NCENTER_ID_SIM4_UNREAD_VIDEO
#endif
    };
    static U32 entry_id;

    group_handle = mmi_um_create_ncenter_group();

    if ((line_id == MMI_MSG_WAITING_LINE2) && ( info->indType == MMI_SMS_NEW_VOCIEMAIL_WAITING_IND))
    {
        entry_id = nt_id[sim_index*MAX_WAITING_TYPE_NUM] + 1; /* vociemail line 2 */
    }
    else
    {
        entry_id = nt_id[sim_index*MAX_WAITING_TYPE_NUM +  info->indType];
    }

    notify_handle = vsrv_ncenter_query_notification(group_handle, entry_id);

    if (notify_handle != NULL)
    {
        WCHAR main_text[MMI_NEW_MSG_WAITING_INFO_LEN];

        if (info->indType == MMI_SMS_NEW_VOCIEMAIL_WAITING_IND)
        {
            vsrv_ncenter_close_notification(notify_handle);
        }
        else
        {
            if ((mmi_sms_check_is_valid_waiting(mmi_sim, MMI_MSG_WAITING_LINE1, info->indType))
                || (mmi_sms_check_is_valid_waiting(mmi_sim, MMI_MSG_WAITING_LINE2, info->indType))
                )
            {
                if (line_id == MMI_MSG_WAITING_LINE1)
                {
                    line_id = MMI_MSG_WAITING_LINE2;
                }
                else
                {
                    line_id = MMI_MSG_WAITING_LINE1;
                }
            
                mmi_sms_get_waiting_text(mmi_sim, line_id, info->indType,(U16*)main_text, MMI_NEW_MSG_WAITING_INFO_LEN);
                vsrv_ncenter_set_notification_maintext_str(notify_handle, main_text);
                vsrv_ncenter_notify_notification(notify_handle);
            }
            else
            {
                vsrv_ncenter_close_notification(notify_handle);
            }
        }
    }
}

    //m_signalMsgWaitingStateChanged.postEmit(mmi_sim, line_id, (vapp_sms_msg_waiting_type_enum)info->indType, MMI_FALSE);   
}


mmi_ret mmi_sms_msg_waiting_preview_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    U32 index;
    U32 size = MMI_SMS_MAX_WAITING_CENTER_NUM * MMI_SIM_TOTAL;
    U32 *entry_id = (U32*)evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
    if (entry_id == NULL)
    {
         return MMI_RET_OK;
    }

    for (index = 0; index < size; index++)
    {
        mmi_sim_enum mmi_sim = mmi_frm_index_to_sim(index/MMI_SMS_MAX_WAITING_CENTER_NUM);
        U32 limit = index%MMI_SMS_MAX_WAITING_CENTER_NUM;

        if (ncenter_notify_id[index] == entry_id[0])
        {
            if(evt->evt_id == EVT_ID_NMGR_POPUP_APP_LAUNCH || evt->evt_id == EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH)
            {
                if (limit == 0 || limit == 1)
                {
                    mmi_sms_waiting_dial_mailbox(mmi_sim, limit);
                }
            }
            else if (evt->evt_id == EVT_ID_NMGR_ALERT_END)
            {
                //mmi_frm_nmgr_alert_cancel(waiting_nmgr_handle[index]);
                //waiting_nmgr_handle[index] = NULL;
            }
            break;
        }
    }

    return MMI_RET_OK;
}

void mmi_msg_handle_msg_waiting_ind_ext(l4csmsal_msg_waiting_ind_ext_struct *pMsgIndExt, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_waiting_ind_info_struct info;
    U8 line_no = pMsgIndExt->line_no;
    U8 ind_type = pMsgIndExt->ind_type;
#if (MMI_MAX_SIM_NUM >= 2)
    mmi_sim_enum ind_mmi_sim = SRV_SMS_SMS_SIM_TO_MMI(sim_id);
    mmi_sim_enum curr_mmi_sim = g_msg_cntx.msg_waiting_info[g_msg_cntx.msg_waiting_line_number].curr_sim;
#else
    mmi_sim_enum ind_mmi_sim = MMI_SIM1;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MSG_REL4_SUPPORT__
    if (srv_sms_check_r4_support())
    {
        if (pMsgIndExt->line_no >= 1) /* R4R5 mode, only show the Line1, ignore the Line2 */
        {
            return;
        }
    }
    else
#else /* __MMI_MSG_REL4_SUPPORT__ */
    if (pMsgIndExt->line_no >= MMI_SMS_MSG_WAITING_LINE_NUM)
    {
        return;
    }
#endif /* __MMI_MSG_REL4_SUPPORT__ */

    info.lineNo = pMsgIndExt->line_no;
    info.mspNo = pMsgIndExt->msp_no;
    info.waitingNum = pMsgIndExt->waiting_num;
    info.indType = pMsgIndExt->ind_type;
    info.isShowNum = pMsgIndExt->is_show_num;
    info.isClear = pMsgIndExt->is_clear;
    info.isfromStorage = pMsgIndExt->is_from_storage;

    if (pMsgIndExt->is_clear)
    {
        mmi_sms_clear_waiting_info_ind(&info, sim_id);
    }        
    else
    {
        mmi_sms_add_waiting_info_ind(&info, sim_id);
    }

    if (pMsgIndExt->is_clear)
    {
        g_msg_cntx.msg_waiting_info[line_no].number[ind_type] = 0;

        if (g_msg_cntx.msg_waiting_line_number == line_no && g_msg_cntx.msg_waiting_ind == ind_type + 1
        #if (MMI_MAX_SIM_NUM >= 2)
            && (curr_mmi_sim == ind_mmi_sim) 
        #endif
            )
        {
            /* clear notification manager */
            if (g_msg_cntx.msg_waiting_ind == 1)
            {
            #ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
                mmi_nmgr_refresh(MMI_NMGR_APP_MESSAGE_WAITING, MMI_NMGR_OPTION_USE_DEFAULT);
            #endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/
            }
            g_msg_cntx.msg_waiting_ind = 0;
        }
    }        
    else
    {
        g_msg_cntx.msg_waiting_info[line_no].number[ind_type] = pMsgIndExt->waiting_num;

    #if (MMI_MAX_SIM_NUM >= 2)
        g_msg_cntx.msg_waiting_info[line_no].curr_sim = ind_mmi_sim;
    #endif

        g_msg_cntx.msg_waiting_is_show_number = pMsgIndExt->is_show_num;        
        g_msg_cntx.msg_waiting_line_number = line_no;

         //if (ind_type == MMI_SMS_NEW_VOCIEMAIL_WAITING_IND)
        {
            //mmi_msg_msg_waiting_ind(ind_type);
            mmi_frm_nmgr_alert_struct alert_info;
            U32 sim_index = mmi_frm_sim_to_index(ind_mmi_sim);
            mmi_event_notify_enum event_type[] = 
            {
                MMI_EVENT_MESSAGE_SIM1_WAITING
                ,MMI_EVENT_MESSAGE_SIM2_WAITING
            #if (MMI_MAX_SIM_NUM >= 3)
                ,MMI_EVENT_MESSAGE_SIM3_WAITING
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
                ,MMI_EVENT_MESSAGE_SIM4_WAITING
            #endif
            };
            S32 status_image_id[] = 
            {
                IMG_SI_UNREAD_VOICE
                 #ifndef __MMI_STATUS_ICON_BAR_SLIM__
                ,IMG_SI_UNREAD_FAX
                ,IMG_SI_UNREAD_EMAIL_MSG
                ,IMG_SI_UNREAD_NET
                ,IMG_SI_UNREAD_VIDEO
                #endif
            };
            static U32 entry_id;
            U32 handle_index;
            U16 stringId = 0;
            WCHAR temp[MMI_NEW_MSG_WAITING_INFO_LEN+1];

            handle_index = sim_index*MMI_SMS_MAX_WAITING_CENTER_NUM + ind_type;
            if ((line_no != MMI_MSG_WAITING_LINE1) || (ind_type != MMI_SMS_NEW_VOCIEMAIL_WAITING_IND))
            {
                handle_index++;
            }
            entry_id = ncenter_notify_id[handle_index];

            memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct)); 

            if (info.isfromStorage)
            {
                alert_info.app_id = APP_UNIFIEDMESSAGE;
                alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK;
                alert_info.behavior_mask = FORCE_ICON_ONLY;
                alert_info.status_bar_icon_para.icon_id = sms_msg_waiting_icon[ind_type];
                mmi_frm_nmgr_alert(&alert_info);
                return;
            }

            alert_info.app_id = APP_UNIFIEDMESSAGE;
            alert_info.scen_id = MMI_SCENARIO_ID_MESSAGE_WAITING;
        #if (MMI_MAX_SIM_NUM >= 2)
            sim_index = mmi_frm_sim_to_index(ind_mmi_sim);
            alert_info.event_type = event_type[sim_index];
        #else
            alert_info.event_type = MMI_EVENT_SIM1_NEW_MSG_WAITING_VOICEMAIL;
        #endif
            alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK | MMI_FRM_NMGR_UI_POPUP_MASK |MMI_FRM_NMGR_UI_STATUS_BAR_MASK;
            alert_info.behavior_mask = PREFER_POPUP; //PREFER_POPUP; // or PREFER_STATUS_BAR. PREFER_ICON_ONLY

            /*fill in the status bar information*/
            alert_info.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
            alert_info.status_bar_para.image_type = NATIVE_APP_TYPE;
            alert_info.status_bar_para.image.id = status_image_id[ind_type];

            mmi_sms_get_waiting_text(ind_mmi_sim, line_no, ind_type, temp, MMI_NEW_MSG_WAITING_INFO_LEN);

            if (ind_type == MMI_SMS_NEW_VOCIEMAIL_WAITING_IND)
            {
                WCHAR number[MAX_CC_ADDR_LEN + 1];
                WCHAR name[SRV_SMS_MAX_PROFILE_NAME_LEN + 1];

                mmi_ucs2cpy((CHAR*)name, (CHAR*)srv_sms_get_mailbox_setting(sim_id)->p_mailbox_name[line_no]);
                mmi_ucs2cpy((CHAR*)number, (CHAR*)srv_sms_get_mailbox_setting(sim_id)->p_mailbox_number[line_no]);

                if (name[0] != '\0')
                {
                    mmi_ucs2cpy((CHAR*)temp, (CHAR*)GetString(STR_ID_SMS_NEW_VOCIEMAIL_WAITING_FROM));
                    mmi_ucs2cat((CHAR*)temp, (CHAR*)name);
                }
                else if (number[0] != '\0')
                {
                    mmi_ucs2cpy((CHAR*)temp, GetString(STR_ID_SMS_NEW_VOCIEMAIL_WAITING_FROM));
                    mmi_ucs2cat((CHAR*)temp, (CHAR*)number);
                }
            }
            alert_info.status_bar_para.display_string = temp;

            /*fill in the popup information*/
            if (ind_type == MMI_SMS_NEW_VOCIEMAIL_WAITING_IND)
            {
                alert_info.popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE;

            }
            else
            {
                alert_info.popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_ONE_BUTTON_TYPE;
            }
            //alert_info.popup_para.image_type = NATIVE_APP_TYPE;
            //alert_info.popup_para.image.id = status_image_id[ind_type];
            alert_info.popup_para.popup_string = temp;
            alert_info.popup_para.popup_button_string = (WCHAR*)GetString(STR_GLOBAL_DIAL);
            //alert_info.behavior_mask = PREFER_POPUP; 

            /*fill in the status bar icon information*/
            alert_info.status_bar_icon_para.icon_id = sms_msg_waiting_icon[ind_type];

            /*fill in the app launch callback*/
            alert_info.app_proc_para.scrn_group_proc = mmi_sms_msg_waiting_preview_proc;
            alert_info.app_proc_para.user_data = &entry_id; 
            alert_info.app_proc_para.data_size =4;
            mmi_frm_nmgr_alert(&alert_info);
        }
    }
}

#else

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_msg_waiting_ind_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pMsgIndExt      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_handle_msg_waiting_ind_ext(l4csmsal_msg_waiting_ind_ext_struct *pMsgIndExt, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    mmi_sim_enum ind_mmi_sim = SRV_SMS_SMS_SIM_TO_MMI(sim_id);
#endif
    U8 max_waiting_line = MAX_WAITING_LINE_NUM;
    U8 line_no = pMsgIndExt->line_no;
    U8 ind_type = pMsgIndExt->ind_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MSG_REL4_SUPPORT__
    if (srv_sms_check_r4_support() == MMI_TRUE)
    {
        max_waiting_line = 1; /* R4R5 mode, only show the Line1, ignore the Line2 */
    }
#endif /* __MMI_MSG_REL4_SUPPORT__ */

    if ((line_no >= max_waiting_line)
        ||(ind_type >= MAX_WAITING_TYPE_NUM)
        )
    {
        return;
    }

    if (pMsgIndExt->is_clear)
    {
    #if (MMI_MAX_SIM_NUM >= 2)
        mmi_sim_enum curr_mmi_sim = g_msg_cntx.msg_waiting_info[g_msg_cntx.msg_waiting_line_number].curr_sim;
    #endif

        g_msg_cntx.msg_waiting_info[line_no].number[ind_type] = 0;

        mmi_msg_set_msg_waiting_icon(sim_id, line_no, ind_type, 0);

        if (g_msg_cntx.msg_waiting_line_number == line_no && g_msg_cntx.msg_waiting_ind == ind_type + 1
        #if (MMI_MAX_SIM_NUM >= 2)
            && (curr_mmi_sim == ind_mmi_sim) 
        #endif
            )
        {
        #ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
            if (GetMessagesCurrScrnID() == SCR_ID_MSG_MSG_WAITING_IND)
            {
                mmi_sms_go_back_from_msg_waiting_ind();
            }
        #endif
            /* clear notification manager */
            if (g_msg_cntx.msg_waiting_ind == 1)
            {
            #ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
                mmi_nmgr_refresh(MMI_NMGR_APP_MESSAGE_WAITING, MMI_NMGR_OPTION_USE_DEFAULT);
            #endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/
            }

            g_msg_cntx.msg_waiting_ind = 0;
        }
    }        
    else
    {
        g_msg_cntx.msg_waiting_info[line_no].number[ind_type] = pMsgIndExt->waiting_num;

    #if (MMI_MAX_SIM_NUM >= 2)
        g_msg_cntx.msg_waiting_info[line_no].curr_sim = ind_mmi_sim;
    #endif

        /* Only display icon for message indication in storage, not from network. */
        if (pMsgIndExt->is_from_storage)
        {
            mmi_msg_set_msg_waiting_icon(sim_id, line_no, ind_type, 1);

            return;
        }
        
        g_msg_cntx.msg_waiting_is_show_number = pMsgIndExt->is_show_num;        
        g_msg_cntx.msg_waiting_line_number = line_no;        
        mmi_msg_msg_waiting_ind(ind_type);
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_msg_waiting_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_handle_msg_waiting_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_msg_waitting_struct* event_info = (srv_sms_event_msg_waitting_struct*)event_data->event_info;
    mmi_sms_msg_waiting_ind_struct *msgInd = (mmi_sms_msg_waiting_ind_struct*)event_info->msg_data;
    l4csmsal_msg_waiting_ind_ext_struct msgIndExt;
    srv_sms_sim_enum sim_id = event_info->sim_id;
    mmi_sim_enum mmi_sim = MMI_SIM1;
    U8 ext_ind = msgInd->ext_indicator;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    mmi_sim = SRV_SMS_SMS_SIM_TO_MMI(sim_id);   
#endif /* (MMI_MAX_SIM_NUM >= 2) */ 

    if (srv_sim_ctrl_get_unavailable_cause(mmi_sim) == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED)
    {
        return MMI_RET_OK;
    }

    msgIndExt.line_no = msgInd->line_no;
    msgIndExt.msp_no = msgInd->msp_no;
    msgIndExt.waiting_num = msgInd->waiting_num;
    msgIndExt.ind_type = msgInd->ind_type;
    msgIndExt.is_show_num = msgInd->is_show_num;
    msgIndExt.is_clear = msgInd->is_clear;
    msgIndExt.is_from_storage = msgInd->is_from_storage;

    if (msgIndExt.waiting_num == 0xFF)
    {
        msgIndExt.is_show_num = MMI_FALSE;
    }

    mmi_msg_handle_msg_waiting_ind_ext(&msgIndExt, sim_id);

#ifdef __MMI_SMS_FOR_HOMESCREEN__
    if (msgIndExt.ind_type == 0)
    {
        if (msgIndExt.is_clear)
        {
            g_msg_cntx.msg_waiting_vm_num = 0;
        }
        else
        {
            if (msgIndExt.is_show_num)
            {
                g_msg_cntx.msg_waiting_vm_num = msgIndExt.waiting_num;
            }
            else
            {
                g_msg_cntx.msg_waiting_vm_num = 1;
            }
        }
    #if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        mmi_voicemail_update_op11_hs32_vm_shct_data();
    #endif        
    }
#endif /* __MMI_SMS_FOR_HOMESCREEN__ */

    for (i = 0; i < ext_ind; i++)
    {
        memcpy(&msgIndExt, &(msgInd->msg_waiting[i]), sizeof(l4csmsal_msg_waiting_ind_ext_struct));

        mmi_msg_handle_msg_waiting_ind_ext(&msgIndExt, sim_id);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_deliver_report_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_handle_deliver_report_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_new_status_report_struct *event_info = (srv_sms_event_new_status_report_struct*)event_data->event_info;
    srv_sms_status_report_struct *report_data = &event_info->report_data;
#ifndef __MMI_UM_REPORT_BOX__
    srv_sms_status_report_struct *dest_report;
#endif /* __MMI_UM_REPORT_BOX__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UM_REPORT_BOX__
    if (g_sms_cntx.report_count == MMI_SMS_MAX_REPORT_NUM)
    {
        U32 i;

        /* Remove Oldest one (first Index) */
        OslMfree(g_sms_cntx.report_data[0]);

        for (i = 0; i < (MMI_SMS_MAX_REPORT_NUM - 1); i++)
        {
            g_sms_cntx.report_data[i] = g_sms_cntx.report_data[i + 1];
        }

        g_sms_cntx.report_count--;
    }

    MMI_ASSERT(g_sms_cntx.report_count < MMI_SMS_MAX_REPORT_NUM);

    dest_report = OslMalloc(sizeof(srv_sms_status_report_struct));

    memcpy(dest_report, report_data, sizeof(srv_sms_status_report_struct));
    g_sms_cntx.report_data[g_sms_cntx.report_count] = dest_report;
#else /* __MMI_UM_REPORT_BOX__ */
    g_sms_cntx.curr_report_id = event_info->report_id;
#endif /* __MMI_UM_REPORT_BOX__ */

    if (g_sms_cntx.report_count < MMI_SMS_MAX_REPORT_NUM)
    {
        g_sms_cntx.report_count++;
    }

    mmi_sms_entry_delivery_report_ind();
    {
        /* notify for update ncenter */
	#ifdef __UM_SUPPORT__
        srv_um_refresh_ind_struct *refresh_ind;
        
        refresh_ind = (srv_um_refresh_ind_struct*)OslConstructDataPtr(sizeof(srv_um_refresh_ind_struct));
        refresh_ind->msg_type = SRV_UM_MSG_SMS;
        refresh_ind->refresh_type = SRV_UM_REFRESH_NEW_INCOMING_MSG;
        refresh_ind->msg_box_type = SRV_UM_MSG_BOX_REPORT;

        refresh_ind->msg_id = event_info->report_id;
        refresh_ind->addr_number = 1;
        refresh_ind->addr_type = SRV_UM_ADDR_PHONE_NUMBER;
        mmi_asc_to_wcs((WCHAR*)refresh_ind->address, (char*)report_data->number);
        mmi_frm_send_ilm((oslModuleType)MOD_MMI, (oslMsgType)MSG_ID_MMI_UM_REFRESH_IND, (oslParaType*)refresh_ind, NULL);
	#endif
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_mem_full_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_handle_mem_full_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_mem_full_struct *event_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_info = (srv_sms_event_mem_full_struct*)event_data->event_info;

    if (event_info->mem_type == SRV_SMS_MEM_NORMAL
    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        || event_info->mem_type == SRV_SMS_MEM_ME_ONLY
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
       )
    {
    #if (MMI_MAX_SIM_NUM >= 2)
        {
            U32 index;
            mmi_sim_enum mmi_sim = SRV_SMS_SMS_SIM_TO_MMI(event_info->sim_id);
            index = mmi_frm_sim_to_index(mmi_sim);
            g_msg_cntx.msg_full_ind[index] = MMI_TRUE;
        }
    #else
        g_msg_cntx.msg_full_ind[0] = MMI_TRUE;
    #endif /*  (MMI_MAX_SIM_NUM >= 2) */

        mmi_sms_set_msg_icon(MMI_TRUE, event_info->sim_id);
    }
#if (defined( __OP01__ ))
    if (event_info->mem_type == SRV_SMS_MEM_SIM_ONLY)
    {
        /*
        mmi_sms_nmgr_display_popup(
                            (UI_string_type) GetString(STR_SMS_SIM_MEMORY_EXCEEDED),
                            MMI_EVENT_INFO);
                            */
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_HIGH_SCRN, MMI_EVENT_INFO, (UI_string_type) GetString(STR_SMS_SIM_MEMORY_EXCEEDED));

    }
#endif
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_mem_exceed_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_handle_mem_exceed_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_mem_exceed_struct *pMemExceed = (srv_sms_event_mem_exceed_struct*)event_data->event_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pMemExceed->mem_type == SRV_SMS_MEM_NORMAL || pMemExceed->mem_type == SRV_SMS_MEM_SIM_ONLY)
    {
        g_msg_cntx.msg_exceed_ind = MMI_TRUE;
        g_msg_cntx.msg_exceed_type = pMemExceed->mem_type;

    #if (MMI_MAX_SIM_NUM >= 2)
        g_msg_cntx.msg_exceed_sim = SRV_SMS_SMS_SIM_TO_MMI(pMemExceed->sim_id);
    #endif /* __MMI_DUAL_SIM_MASTER__ */

        srv_backlight_turn_on((srv_backlight_timer_type_enum)1);

        if (IsMMIInIdleState())
        {
            ClearKeyEvents();
            if (IsKeyPadLockState())
            {
                 mmi_idle_display();
            }
            else
            {
                mmi_msg_entry_mem_exceed_ind();
            }
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_mem_avail_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_handle_mem_avail_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_mem_available_struct *event_info;
    srv_sms_sim_enum sim_id;
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    srv_sms_mem_enum ind_mem_type;
    srv_sms_mem_enum ecd_mem_type;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_info = (srv_sms_event_mem_available_struct*)event_data->event_info;
    sim_id = event_info->sim_id;

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    ind_mem_type = event_info->mem_type;
    ecd_mem_type = g_msg_cntx.msg_exceed_type;
#endif

#if (MMI_MAX_SIM_NUM >= 2)
    {
        U32 index;
        mmi_sim_enum mmi_sim = SRV_SMS_SMS_SIM_TO_MMI(sim_id);
        index = mmi_frm_sim_to_index(mmi_sim);
        g_msg_cntx.msg_full_ind[index] = MMI_FALSE;

        if ((mmi_sim == g_msg_cntx.msg_exceed_sim)
        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            && ((ind_mem_type == ecd_mem_type) || ((ind_mem_type&ecd_mem_type) == SRV_SMS_MEM_ME_ONLY))
        #endif
            )
        {
            mmi_frm_scrn_close(mmi_idle_get_group_id(), SCR_ID_MSG_EXCEED_IND);

            g_msg_cntx.msg_exceed_ind = MMI_FALSE;
        }
    }
#else /*  (MMI_MAX_SIM_NUM >= 2) */
    g_msg_cntx.msg_full_ind[0] = MMI_FALSE;

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    if ((ind_mem_type == ecd_mem_type) || ((ind_mem_type&ecd_mem_type) == SRV_SMS_MEM_ME_ONLY))
#endif
    {
        mmi_frm_scrn_close(mmi_idle_get_group_id(),SCR_ID_MSG_EXCEED_IND);

        g_msg_cntx.msg_exceed_ind = MMI_FALSE;
    }
#endif

    mmi_sms_set_msg_icon(MMI_TRUE, sim_id);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_class0_msg_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 *  content     [?]     
 * RETURNS
 *  
 *****************************************************************************/
void mmi_msg_handle_class0_msg_ind(srv_sms_event_new_sms_struct* event_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_new_msg_struct *new_msg_data = (srv_sms_new_msg_struct*)event_info->msg_data;
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */
    S8 *unicodecontent = (S8*)event_info->content;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_msg_cntx.msg_class0_p != NULL)
    {
        if (g_msg_cntx.msg_class0_p->data != NULL)
        {
            OslMfree(g_msg_cntx.msg_class0_p->data);
            g_msg_cntx.msg_class0_p->data = NULL;
        }
        OslMfree(g_msg_cntx.msg_class0_p);
        g_msg_cntx.msg_class0_p = NULL;
    }
    g_msg_cntx.msg_class0_p = OslMalloc(sizeof(msg_class0_msg_struct));
    g_msg_cntx.msg_class0_p->length = (U16) new_msg_data->message_len;
    g_msg_cntx.msg_class0_p->dcs = new_msg_data->dcs;
    g_msg_cntx.msg_class0_p->totalseg = new_msg_data->total_seg;
#if (MMI_MAX_SIM_NUM >= 2)
    g_msg_cntx.msg_class0_p->curr_sim = SRV_SMS_SMS_SIM_TO_MMI(sim_id);
#endif /* __MMI_DUAL_SIM_MASTER__ */

    mmi_asc_to_ucs2((S8*)g_msg_cntx.msg_class0_p->number, (S8*)new_msg_data->number);
    memcpy(&(g_msg_cntx.msg_class0_p->timestamp), &(new_msg_data->timestamp), sizeof(MYTIME));

    g_msg_cntx.msg_class0_p->data = OslMalloc(g_msg_cntx.msg_class0_p->length + ENCODING_LENGTH);
    memset((S8*) g_msg_cntx.msg_class0_p->data, 0, g_msg_cntx.msg_class0_p->length + ENCODING_LENGTH);
    memcpy((S8*) g_msg_cntx.msg_class0_p->data, (S8*) unicodecontent, g_msg_cntx.msg_class0_p->length);

    g_class0_sms_info.fo = new_msg_data->fo;
    memcpy(g_class0_sms_info.sc_addr, new_msg_data->sc_number, SRV_SMS_MAX_ADDR_LEN);
    g_class0_sms_info.sc_addr[SRV_SMS_MAX_ADDR_LEN] = '\0';
    memcpy(g_class0_sms_info.number, new_msg_data->number, SRV_SMS_MAX_ADDR_LEN);
    g_class0_sms_info.number[SRV_SMS_MAX_ADDR_LEN] = '\0';
    memcpy(&(g_class0_sms_info.timestamp), &(new_msg_data->timestamp), sizeof(MYTIME));

    mmi_msg_class0_msg_ind();
}

#ifdef __MMI_TELEPHONY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_msg_new_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_get_msg_new_callback(mmi_sms_result_enum result, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SMS_RESULT_OK)
    {
        mmi_sms_msg_status_enum msg_status = *(mmi_sms_msg_status_enum*)data;

        g_sms_cntx.curr_msg_status = msg_status;

        if ((g_sms_gid == mmi_frm_group_get_active_id())
            && (SCR_ID_SMS_PROCESSING == mmi_frm_scrn_get_active_id()))
        {
            mmi_sms_entry_viewer();
            mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_PROCESSING);
        }
        else if (mmi_frm_scrn_is_present(g_sms_gid, SCR_ID_SMS_PROCESSING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
            mmi_frm_node_struct new_node_info;
            new_node_info.id = SCR_ID_SMS_VIEWER;
            new_node_info.entry_proc = (mmi_proc_func)mmi_sms_entry_viewer;
            mmi_frm_scrn_replace(g_sms_gid, SCR_ID_SMS_PROCESSING , &new_node_info);
        }
    }
    else
    {
        mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_PROCESSING);
    }
}
#endif/*__MMI_TELEPHONY_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_msg_new
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_msg_new(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.msg_ind_in_idle = MMI_FALSE;

    if (srv_sms_is_msg_exist(g_msg_cntx.msg_ind_index) == MMI_FALSE)
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_UNFINISHED,
            MMI_EVENT_FAILURE);
    }
    else
    {
        g_sms_cntx.msg_ind_in_idle = MMI_FALSE;
        g_sms_cntx.curr_list_type = MMI_SMS_LIST_INBOX;
        g_sms_cntx.curr_box_type = SRV_SMS_BOX_INBOX;
        g_sms_cntx.curr_msg_id = g_sms_cntx.ind_msg_index;
#ifdef __MMI_TELEPHONY_SUPPORT__
        mmi_sms_read_msg(g_sms_cntx.curr_msg_id, MMI_TRUE, mmi_sms_get_msg_new_callback);
#endif/*__MMI_TELEPHONY_SUPPORT__*/
    }
}


#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_sim_msg_new
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_get_sim_msg_new(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.sim_msg_ind_in_idle = MMI_FALSE;

    /* Go back to Idle screen if the new msg is deleted by AT or SIM refresh is ongoing. */
    if (srv_sms_is_msg_exist(g_msg_cntx.sim_msg_ind_index) == MMI_FALSE)
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_UNFINISHED,
            MMI_EVENT_FAILURE);
    }
    else
    {
        /* disallow re-entering SMS application when there is a pending SMS job running in the background */
        if (srv_sms_is_sms_ready() == MMI_TRUE)
        {       
            mmi_um_pre_entry_simbox();        
        }    
        else
        {
            mmi_sms_display_popup_ext(
                STR_SMS_MSG_NOT_READY_YET,
                MMI_EVENT_FAILURE);
            mmi_nmgr_refresh(MMI_NMGR_APP_SIM_SMS, MMI_NMGR_OPTION_USE_DEFAULT);
        }
    }
}
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */


#ifdef __MMI_OP12_MESSAGE_VOICEMAIL__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_protocol_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_protocol_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_OP12_MESSAGE_VOICEMAIL__
    srv_sms_set_interrupt_event_handler(EVT_ID_SRV_SMS_NEW_MSG, mmi_msg_handle_new_mt_voicemail, NULL);
#endif /* __MMI_OP12_MESSAGE_VOICEMAIL__ */
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_new_sms_flag
 * DESCRIPTION
 *  check whether new sms is vailded in idle, if invalide, need to clear flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_handle_new_sms_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_msg_need_change_new_sms_flag() == MMI_TRUE)
    {
        g_msg_cntx.msg_ind_in_idle = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_need_change_new_sms_flag
 * DESCRIPTION
 *  check whether new sms is vailded in idle, if invalide, need to clear flag
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_msg_need_change_new_sms_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_msg_cntx.msg_ind_in_idle == MMI_TRUE)
    {
        if (g_msg_cntx.msg_ind_index == SRV_SMS_INVALID_MSG_ID)
        {
            result = MMI_TRUE;
        }
        else
        {
            if ((srv_sms_is_msg_exist(g_msg_cntx.msg_ind_index) == MMI_TRUE) &&
                (srv_sms_get_msg_status(g_msg_cntx.msg_ind_index) & SRV_SMS_STATUS_UNREAD))
            {
                result = MMI_TRUE;
            }
        }
    }

    return result;
}


#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_handle_new_sim_sms_flag
 * DESCRIPTION
 *  check whether new sim sms is vailded in idle, if invalide, need to clear flag
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_msg_need_change_new_sim_sms_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_msg_cntx.sim_msg_ind_in_idle == MMI_TRUE)
    {
        if (g_msg_cntx.sim_msg_ind_index == SRV_SMS_INVALID_MSG_ID)
        {
            result = MMI_TRUE;
        }
        else
        {
            if  ((srv_sms_is_msg_exist(g_msg_cntx.sim_msg_ind_index) == MMI_TRUE) &&
                (srv_sms_get_msg_status(g_msg_cntx.sim_msg_ind_index) & SRV_SMS_STATUS_UNREAD)) 
            {
                result = MMI_TRUE;
            }
        }
    }

    return result;
}
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_handle_sms_update_sending_icon_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_handle_sms_update_sending_icon_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    static U16 showIconCount = 0;
    srv_sms_event_update_sending_icon_struct *event_info = 
                        (srv_sms_event_update_sending_icon_struct*)event_data->event_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event_info->is_show)
    {
        showIconCount++;
        #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        BlinkStatusIcon(STATUS_ICON_SMS_SENDING);
        #endif  //__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    }
    else
    {
        if (showIconCount)
        {
            showIconCount--;
        }

        if (showIconCount == 0)
        {
            #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
            wgui_status_icon_bar_hide_icon(STATUS_ICON_SMS_SENDING);
            #endif  //__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        }
    }
    return MMI_RET_OK;
}


#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_handle_sms_update_unsent_msg_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_handle_sms_update_unsent_msg_status(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_update_unsent_msg_status_struct *event_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_info = (srv_sms_event_update_unsent_msg_status_struct*)event_data->event_info;

    switch (event_info->status)
    {
        case SRV_SMS_SEND_SUCCESS:
        case SRV_SMS_SEND_SENDING:
        {
            mmi_msg_update_unsent_icon();
            break;
        }

        case SRV_SMS_SEND_FAIL:
        {
            if (event_info->is_send_abort == MMI_FALSE)
            {
                mmi_sms_notify_send_failed(event_info->msg_id);
            }
            break;
        }

        case SRV_SMS_SEND_WAITING:  
        default:
            break;
    }

    return MMI_RET_OK;
}
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_handle_new_msg_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_sms_handle_new_msg_ind(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_new_sms_struct* event_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_info = (srv_sms_event_new_sms_struct*)event_data->event_info;

    if (event_info->msg_id == SRV_SMS_INVALID_MSG_ID)
    {
        mmi_msg_handle_class0_msg_ind(event_info);
    }
    else
    {
        mmi_msg_new_msg_ind(event_info);
        {
            /* send indication to UM */
	#ifdef __UM_SUPPORT__
            srv_um_refresh_ind_struct *refresh_ind;
            srv_sms_new_msg_struct *msg_data = (srv_sms_new_msg_struct*)event_info->msg_data;
            refresh_ind = (srv_um_refresh_ind_struct*)OslConstructDataPtr(sizeof(srv_um_refresh_ind_struct));
            refresh_ind->msg_type = SRV_UM_MSG_SMS;
            refresh_ind->refresh_type = SRV_UM_REFRESH_NEW_INCOMING_MSG;

        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            if (msg_data->storage_type == SRV_SMS_STORAGE_SIM)
            {
                refresh_ind->msg_box_type = SRV_UM_MSG_BOX_SIM;
            }
            else
        #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
            {
                refresh_ind->msg_box_type = SRV_UM_MSG_BOX_INBOX;
            }

            refresh_ind->msg_id = event_info->msg_id;
            refresh_ind->addr_number = 1;
            refresh_ind->addr_type = SRV_UM_ADDR_PHONE_NUMBER;
            mmi_asc_to_wcs((WCHAR*)refresh_ind->address, (char*)msg_data->number);
            mmi_frm_send_ilm((oslModuleType)MOD_MMI, (oslMsgType)MSG_ID_MMI_UM_REFRESH_IND, (oslParaType*)refresh_ind, NULL);
	#endif
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_handle_ind_dumy_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_sms_handle_ind_dumy_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_RET_OK;
}


#ifdef __MMI_SMS_DETAILS_INFO__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_handle_msg_details_scrn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void mmi_sms_handle_msg_details_scrn(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((msg_id == g_sms_cntx.curr_msg_id)
        && mmi_frm_scrn_is_present(g_sms_gid, SCR_ID_SMS_OPTION_DETAILS, MMI_FRM_NODE_ALL_FLAG))
    {
        if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) <= 0)
        {
            mmi_sms_display_popup_ext(
                STR_ID_SMS_MESSAGES_UPDATED,
                MMI_EVENT_PROGRESS);
        }

        mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_OPTION_DETAILS);
    }
}
#endif /* __MMI_SMS_DETAILS_INFO__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_handle_msg_del_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_sms_handle_msg_del_event(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_delete_struct *event_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_info = (srv_sms_event_delete_struct*)event_data->event_info;

    if (event_info->msg_id == g_sms_cntx.curr_msg_id || event_info->msg_id == g_sms_cntx.ind_msg_index)
    {
    #ifdef __MMI_UM_ITERATOR_VIEWER__
        if (mmi_frm_scrn_is_present(g_sms_gid, SCR_ID_SMS_VIEWER, MMI_FRM_NODE_ALL_FLAG)
            && (MMI_FALSE == g_sms_cntx.is_from_hs)
            && (g_sms_cntx.is_del_msg)
            )
        {
            mmi_sms_update_msg_screen(MMI_FALSE, MMI_FALSE);
        }
        else
    #endif
        {
            mmi_sms_update_msg_screen(MMI_TRUE, MMI_FALSE);
        }
    }

    if(event_info->msg_info.status & SRV_SMS_STATUS_UNREAD)
    {
        mmi_sms_update_new_sms_ind(event_info->msg_info.storage_type);
    }

#ifdef __MMI_UM_ITERATOR_VIEWER__
    if (event_info->msg_id == g_sms_cntx.curr_msg_id)
    {
        mmi_sms_iter_viewer_handle_curr_msg_deleted();
    }
#endif /* __MMI_UM_ITERATOR_VIEWER__ */

#ifdef __MMI_SMS_DETAILS_INFO__
    mmi_sms_handle_msg_details_scrn(event_info->msg_id);
#endif /* __MMI_SMS_DETAILS_INFO__ */

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_handle_msg_update_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_sms_handle_msg_update_event(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_update_struct *event_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_sms_ready() == MMI_TRUE)
    {
        event_info = (srv_sms_event_update_struct*)event_data->event_info;

        if (event_info->change_para_flag & SRV_SMS_PARA_STATUS)
        {
            if ((event_info->old_msg_info.status == SRV_SMS_STATUS_UNREAD) ||
                (event_info->old_msg_info.status == SRV_SMS_STATUS_READ))
            {
            #if (MMI_MAX_SIM_NUM >= 2)
                if (event_info->old_msg_info.sim_id == SRV_SMS_SIM_2)
                {
                    mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_2);
                }
                else
            #endif
                {
                    mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_1);
                }
            }

        #ifdef __MMI_SMS_DETAILS_INFO__
        #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
            if ((event_info->old_msg_info.status == SRV_SMS_STATUS_UNSENT) &&
                (event_info->new_msg_info.status == SRV_SMS_STATUS_SENT)
                )
            {
                mmi_sms_handle_msg_details_scrn(event_info->msg_id);
            }
        #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
        #endif /* __MMI_SMS_DETAILS_INFO__ */
        }

        if ((event_info->old_msg_info.status & SRV_SMS_STATUS_UNREAD)
            && (event_info->new_msg_info.status & SRV_SMS_STATUS_READ)
            )
        {
            mmi_sms_update_new_sms_ind(event_info->old_msg_info.storage_type);
        }

    #ifdef __MMI_SMS_DETAILS_INFO__
    #ifdef __MMI_UM_REPORT_STATUS_IN_SENT_BOX__
        if (event_info->change_para_flag & SRV_SMS_PARA_DELIVERY_STATUS)
        {
            if ((event_info->old_msg_info.status == SRV_SMS_STATUS_SENT) &&
                (event_info->new_msg_info.status == SRV_SMS_STATUS_SENT)
                )
            {
                if ((SCR_ID_SMS_OPTION_DETAILS == mmi_frm_scrn_get_active_id())
                    && (event_info->msg_id == g_sms_cntx.curr_msg_id)
                    )
                {
                    mmi_sms_display_popup_ext(
                        STR_ID_SMS_MESSAGES_UPDATED,
                        MMI_EVENT_PROGRESS);
                }
            }
        }
    #endif /* __MMI_UM_REPORT_STATUS_IN_SENT_BOX__ */
    #endif /* __MMI_SMS_DETAILS_INFO__ */
    }

    return MMI_RET_OK;
}


#ifdef __UM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_handle_um_enter_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_sms_handle_um_enter_folder(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_entry_folder_evt_struct* event_data = (mmi_um_entry_folder_evt_struct*)evt;
    srv_um_msg_box_enum um_msg_box = event_data->msg_box;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (um_msg_box & SRV_UM_MSG_BOX_INBOX)
    {
        g_msg_cntx.msg_ind_in_idle = MMI_FALSE;
    }

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    if (um_msg_box & SRV_UM_MSG_BOX_SIM)
    {
        g_msg_cntx.sim_msg_ind_in_idle = MMI_FALSE;
    }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

#ifdef __MMI_UM_REPORT_BOX__
    if (um_msg_box & SRV_UM_MSG_BOX_REPORT)
    {
        g_sms_cntx.report_count = 0;
    }
#endif /* __MMI_UM_REPORT_BOX__ */

    return MMI_RET_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_update_msg_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_update_msg      [IN]
 *  is_update_icon      [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void mmi_sms_update_msg_screen(MMI_BOOL is_update_msg, MMI_BOOL is_update_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_refresh = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((is_update_msg)
        && mmi_frm_scrn_is_present(g_sms_gid, SCR_ID_SMS_VIEWER, MMI_FRM_NODE_ALL_FLAG))
    {
        is_refresh = MMI_TRUE;
    }

    /* For the case of SIM Refresh, the msg screens should be deleted in mmi_frm_sms_sim_refresh_ind() */
    /* If the SMS screens cannot be deleted, do not show the done pupup. */
    if (is_refresh == MMI_TRUE)
    {
        /* Do not interrupt calling screen */
        if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) <= 0)
        {
            mmi_sms_display_popup_ext(
                STR_ID_SMS_MESSAGES_UPDATED,
                MMI_EVENT_PROGRESS);
        }

        /* Viewer related */
        if (g_sms_gid != GRP_ID_INVALID)
        {
            mmi_frm_group_close(g_sms_gid);
        }
    }

#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    mmi_sms_update_sidebar_info();
    mmi_sms_update_shct_data();
#endif /* #if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    mmi_msg_update_unsent_icon();
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

    /* For L4C_AT_SMS_DELETE, if new msg is deleted, will clear new msg flag */

    mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_1);
#if (MMI_MAX_SIM_NUM == 2)
    mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_2);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_update_new_sms_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_update_msg      [IN]
 *  is_update_icon      [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void mmi_sms_update_new_sms_ind(srv_sms_storage_enum storage_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* For L4C_AT_SMS_DELETE, if new msg is deleted, will clear new msg flag */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    if ((storage_type == SRV_SMS_STORAGE_SIM) && g_msg_cntx.sim_msg_ind_in_idle)
    {
        if (srv_sms_is_msg_exist(g_msg_cntx.sim_msg_ind_index) == MMI_TRUE)
        {
            srv_sms_status_enum status;

            status = srv_sms_get_msg_status(g_msg_cntx.sim_msg_ind_index);

            if (status & SRV_SMS_STATUS_READ)
            {
                g_msg_cntx.sim_msg_ind_in_idle = MMI_FALSE;
            }
        }
        else
        {
            g_msg_cntx.sim_msg_ind_in_idle = MMI_FALSE;
        }

    #ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
        mmi_nmgr_refresh(MMI_NMGR_APP_SIM_SMS, MMI_NMGR_OPTION_USE_DEFAULT);
    #endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/
    }
    else if (storage_type == SRV_SMS_STORAGE_ME)
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    {
        if (g_msg_cntx.msg_ind_in_idle)
        {
            if (srv_sms_is_msg_exist(g_msg_cntx.msg_ind_index) == MMI_TRUE)
            {
                srv_sms_status_enum status;

                status = srv_sms_get_msg_status(g_msg_cntx.msg_ind_index);

                if (status & SRV_SMS_STATUS_READ)
                {
                    g_msg_cntx.msg_ind_in_idle = MMI_FALSE;
                }
            }
            else
            {
                g_msg_cntx.msg_ind_in_idle = MMI_FALSE;
            }

        #ifndef __MMI_PLUTO_3232_IDLE_NMGR_SLIM__
            mmi_nmgr_refresh(MMI_NMGR_APP_SMS, MMI_NMGR_OPTION_USE_DEFAULT);
        #endif /*__MMI_PLUTO_3232_IDLE_NMGR_SLIM__*/
        }
    }
}


#ifdef __MMI_UM_ITERATOR_VIEWER__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_um_box_to_sms_box
 * DESCRIPTION
 *  convert the UM box type to SMS type
 * PARAMETERS
 *  msg_box_type        [IN]     UM Box type   
 * RETURNS
 *  void
 *****************************************************************************/
static srv_sms_box_enum mmi_sms_um_box_to_sms_box(srv_um_msg_box_enum um_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_box_enum sms_box_type = SRV_SMS_BOX_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (um_box_type & SRV_UM_MSG_BOX_INBOX)
    {
        sms_box_type |= SRV_SMS_BOX_INBOX;
    }

    if (um_box_type & SRV_UM_MSG_BOX_UNSENT)
    {
        sms_box_type |= SRV_SMS_BOX_UNSENT;
    }

    if (um_box_type & SRV_UM_MSG_BOX_SENT)
    {
        sms_box_type |= SRV_SMS_BOX_OUTBOX;
    }

    if (um_box_type & SRV_UM_MSG_BOX_DRAFT)
    {
        sms_box_type |= SRV_SMS_BOX_DRAFTS;
    }

#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__  
    if (um_box_type & SRV_UM_MSG_BOX_ARCHIVE)
    {
        sms_box_type |= SRV_SMS_BOX_ARCHIVE;
    }
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    if (um_box_type & SRV_UM_MSG_BOX_SIM)
    {
        sms_box_type |= SRV_SMS_BOX_SIM;
    }
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

#ifdef __MMI_UM_REPORT_BOX__
    if (um_box_type & SRV_UM_MSG_BOX_REPORT)
    {
        sms_box_type |= SRV_SMS_BOX_REPORT;
    }
#endif /* __MMI_UM_REPORT_BOX__ */

    return sms_box_type;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_iterator_viewer_refresh_hdlr
 * DESCRIPTION
 *  Handle message being deleted or moved to archive when at iterator viewer
 *  screen.
 * PARAMETERS
 *  is_update_msg      [IN]
 *  is_update_icon      [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
mmi_ret mmi_sms_iterator_viewer_refresh_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_refresh_evt_struct* refresh_ind = (mmi_um_refresh_evt_struct*)evt;
    srv_sms_box_enum sms_msg_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_msg_box_type = mmi_sms_um_box_to_sms_box(refresh_ind->msg_box);
    if ((g_sms_cntx.curr_box_type & sms_msg_box_type) && (mmi_frm_scrn_get_active_id() == SCR_ID_SMS_VIEWER || 
        (mmi_frm_scrn_is_present(g_sms_gid, SCR_ID_SMS_VIEWER, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))))
    {
    #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
        mmi_frm_gesture_stop_listen_event();
    #endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) */

        if (mmi_sms_iter_viewer_query_indexing())
        {
            mmi_sms_iter_viewer_entry_viewer_scrn();
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_iter_viewer_handle_curr_msg_deleted
 * DESCRIPTION
 *  If the current msg has been deleted or moved at iterator viewer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_iter_viewer_handle_curr_msg_deleted(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_um_iter_viewer_result_struct *iter_viewer_result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    iter_viewer_result = g_sms_cntx.iter_viewer_result;

    if (iter_viewer_result)
    {
    #if defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__)
        mmi_frm_gesture_stop_listen_event();
    #endif /* defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_GESTURES_FRAMEWORK__) */

        if ((iter_viewer_result->prev_launch_func_ptr == NULL) && (iter_viewer_result->next_launch_func_ptr == NULL))
        {
            mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_VIEWER);
            return;
        }
        else if (iter_viewer_result->next_launch_func_ptr == NULL)
        {
            iter_viewer_result->prev_launch_func_ptr(g_sms_parent_gid, iter_viewer_result->prev_msg_id, g_sms_cntx.user_data, CUI_MSG_VIEWER_TYPE_ITERATOR);
            mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_VIEWER);
        }
        else
        {
            iter_viewer_result->next_launch_func_ptr(g_sms_parent_gid, iter_viewer_result->next_msg_id, g_sms_cntx.user_data, CUI_MSG_VIEWER_TYPE_ITERATOR);
            mmi_frm_scrn_close(g_sms_gid, SCR_ID_SMS_VIEWER);
        }
    }
}
#endif /* __MMI_UM_ITERATOR_VIEWER__ */




/*****************************************************************************
 * FUNCTION
 *  mmi_sms_shutdown_deinit_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_sms_shutdown_deinit_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DeInitMessagesApp();

    return MMI_RET_OK;
}


#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_tcard_plug_out_handling
 * DESCRIPTION
 *  mmi_sms_tcard_plug_out_handling
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret  mmi_sms_tcard_plug_out_handling(mmi_event_struct *param)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
		 if (srv_sms_get_msg_storage_type(g_sms_cntx.curr_msg_id) == SRV_SMS_STORAGE_TCARD)
		 {
				 mmi_frm_group_close(g_sms_gid);
				 g_sms_gid = GRP_ID_INVALID;
		 }
		return MMI_RET_OK;
}
#endif


#endif /* __MMI_TELEPHONY_SUPPORT__ */ 

