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
 * SmsMoMtGuiInterface.C
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

   FILENAME : SmsGuiHandler.c

   PURPOSE     : SMS GUI handlers 

   REMARKS     : nil

   AUTHOR      : Manu Vikram and Magesh k, Hiran.

   DATE     : 01-01-2003

**************************************************************/
#include "MMI_features.h"

/*  Include: MMI header file */
#include "MMIDataType.h"
#include "ems.h"
#include "gui_data_types.h"
#include "MMI_common_app_trc.h"
//#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "kal_general_types.h"
#include "GlobalConstants.h"
#include "string.h"
#include "ps_public_enum.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "GlobalResDef.h"
#include "CustMenuRes.h"
#include "Unicodexdcl.h"
#include "SmsSrvGprot.h"
#include "SmsAppType.h"
#include "MMI_trc_Int.h"
#ifdef __MMI_BPP20_SUPPORT__
#include "gui_config.h"
#include "mmi_rp_app_sms_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "BppXhtmlGprot.h"
#include "stdio.h"
#include "custom_phb_config.h"
#include "CustDataRes.h"
#include "PhbSrvGprot.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "lcd_sw_rnd.h"
#include "app_mem.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#endif

#include "MessagesMiscell.h"
#include "MessagesExDcl.h"
#include "SmsGuiInterfaceType.h"
#include "SmsAppProt.h"
#include "SmsAppUtil.h"
#include "conversions.h"

#ifdef __MMI_IMPS__
/* under construction !*/
#endif 
#include "mmi_frm_utility_gprot.h"

#if defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__)
#include "NetworkSetupDefs.h"
#include "VoIPGProt.h"
#endif /* defined(__MMI_WLAN_FEATURES__) && defined(__MMI_VOIP__) */

#include "FileMgrSrvGProt.h"

#ifdef __MMI_BPP20_SUPPORT__
#include "Conversions.h"
#include "BppCuiGprot.h"

#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif /* __USB_IN_NORMAL_MODE__ */
#endif /* __MMI_BPP20_SUPPORT__ */

#if defined(__MMI_PROV_MESSAGE_SUPPORT__) && !defined(__MMI_PROV_IN_UM__)
#include "ProvBoxAPPGProt.h"
#include "mmi_rp_app_provbox_def.h"
#endif


#include "SimCtrlSrvGProt.h"

#ifdef __MMI_MESSAGES_SMS_EMAIL__
#include "app_usedetails.h"
#endif

#ifdef __DM_LAWMO_SUPPORT__
#include "DmSrvGprot.h"
#endif

#define ONE_DIGIT(value)                  ((value) % 10)
extern EMSData *GetEMSDataForView(EMSData **p, U8 force);
extern EMSData *GetEMSDataForEdit(EMSData **p, U8 force);
#ifndef __ULC_SLIM_EMS__
extern void MoveCursorToPosition(EMSData *data, EMSPosition *dst);
#endif
//////////////////////////////////////////////////////////////////////////////////////
// local variables
//////////////////////////////////////////////////////////////////////////////////////

/********************************************************************

                  variables

********************************************************************/
msg_context_struct g_msg_cntx;

#ifdef __MMI_OP11_PROF_SOUND__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_PROF_SOUND__ */

msg_msgbox_info_struct msgbox_info;

#if (defined(__MMI_SLIM_IMG_RES__) && (MMI_MAX_SIM_NUM <= 2)) || defined(__MMI_NCENTER_SUPPORT__)

const S32 sms_msg_waiting_icon[] = 
{
    STATUS_ICON_UNREAD_VOICE
    #ifndef __MMI_STATUS_ICON_BAR_SLIM__
    ,STATUS_ICON_UNREAD_FAX,
    STATUS_ICON_UNREAD_EMAIL_MSG,
    STATUS_ICON_UNREAD_NET,
    STATUS_ICON_UNREAD_VIDEO
    #endif
};

#elif defined(__MMI_SLIM_IMG_RES__) && (MMI_MAX_SIM_NUM >= 3)

const S32 sms_msg_waiting_icon[] = 
{
    STATUS_ICON_UNREAD_VOICE_MASTER,
   #ifndef __MMI_STATUS_ICON_BAR_SLIM__ 
    STATUS_ICON_UNREAD_FAX_MASTER,
    STATUS_ICON_UNREAD_EMAIL_MASTER,
    STATUS_ICON_UNREAD_NET_MASTER,
    STATUS_ICON_UNREAD_VIDEO_MASTER,
	#endif

    STATUS_ICON_UNREAD_VOICE_SLAVE,
    #ifndef __MMI_STATUS_ICON_BAR_SLIM__ 
    STATUS_ICON_UNREAD_FAX_SLAVE,
    STATUS_ICON_UNREAD_EMAIL_SLAVE,
    STATUS_ICON_UNREAD_NET_SLAVE,
    STATUS_ICON_UNREAD_VIDEO_SLAVE,
    #endif

    STATUS_ICON_UNREAD_VOICE_SIM3,
    #ifndef __MMI_STATUS_ICON_BAR_SLIM__ 
    STATUS_ICON_UNREAD_FAX_SIM3,
    STATUS_ICON_UNREAD_EMAIL_SIM3,
    STATUS_ICON_UNREAD_NET_SIM3,
    STATUS_ICON_UNREAD_VIDEO_SIM3,
    #endif

    STATUS_ICON_UNREAD_VOICE_SIM4
     #ifndef __MMI_STATUS_ICON_BAR_SLIM__ 
     ,STATUS_ICON_UNREAD_FAX_SIM4,
    STATUS_ICON_UNREAD_EMAIL_SIM4,
    STATUS_ICON_UNREAD_NET_SIM4,
    STATUS_ICON_UNREAD_VIDEO_SIM4
    #endif
};

#else

const S32 sms_msg_waiting_icon[] = 
{
#if (MMI_MAX_SIM_NUM == 1)
    STATUS_ICON_UNREAD_VOICE_L1,
    STATUS_ICON_UNREAD_VOICE_L2,
    STATUS_ICON_UNREAD_VOICE_L1L2
    #ifndef __MMI_STATUS_ICON_BAR_SLIM__ 
     ,STATUS_ICON_UNREAD_FAX_L1,
    STATUS_ICON_UNREAD_FAX_L2,
    STATUS_ICON_UNREAD_FAX_L1L2,
    STATUS_ICON_UNREAD_EMAIL_L1,
    STATUS_ICON_UNREAD_EMAIL_L2,
    STATUS_ICON_UNREAD_EMAIL_L1L2,
    STATUS_ICON_UNREAD_NET_L1,
    STATUS_ICON_UNREAD_NET_L2,
    STATUS_ICON_UNREAD_NET_L1L2,
    STATUS_ICON_UNREAD_VIDEO_L1,
    STATUS_ICON_UNREAD_VIDEO_L2,
    STATUS_ICON_UNREAD_VIDEO_L1L2
    #endif
#elif (MMI_MAX_SIM_NUM >= 2)
    STATUS_ICON_UNREAD_VOICE_L1_MASTER,
    STATUS_ICON_UNREAD_VOICE_L2_MASTER,
    STATUS_ICON_UNREAD_VOICE_L1L2_MASTER,
    #ifndef __MMI_STATUS_ICON_BAR_SLIM__ 
    STATUS_ICON_UNREAD_FAX_L1_MASTER,
    STATUS_ICON_UNREAD_FAX_L2_MASTER,
    STATUS_ICON_UNREAD_FAX_L1L2_MASTER,
    STATUS_ICON_UNREAD_EMAIL_L1_MASTER,
    STATUS_ICON_UNREAD_EMAIL_L2_MASTER,
    STATUS_ICON_UNREAD_EMAIL_L1L2_MASTER,
    STATUS_ICON_UNREAD_NET_L1_MASTER,
    STATUS_ICON_UNREAD_NET_L2_MASTER,
    STATUS_ICON_UNREAD_NET_L1L2_MASTER,
    STATUS_ICON_UNREAD_VIDEO_L1_MASTER,
    STATUS_ICON_UNREAD_VIDEO_L2_MASTER,
    STATUS_ICON_UNREAD_VIDEO_L1L2_MASTER,
    #endif

    STATUS_ICON_UNREAD_VOICE_L1_SLAVE,
    STATUS_ICON_UNREAD_VOICE_L2_SLAVE,
    STATUS_ICON_UNREAD_VOICE_L1L2_SLAVE
    #ifndef __MMI_STATUS_ICON_BAR_SLIM__ 
    ,STATUS_ICON_UNREAD_FAX_L1_SLAVE,
    STATUS_ICON_UNREAD_FAX_L2_SLAVE,
    STATUS_ICON_UNREAD_FAX_L1L2_SLAVE,
    STATUS_ICON_UNREAD_EMAIL_L1_SLAVE,
    STATUS_ICON_UNREAD_EMAIL_L2_SLAVE,
    STATUS_ICON_UNREAD_EMAIL_L1L2_SLAVE,
    STATUS_ICON_UNREAD_NET_L1_SLAVE,
    STATUS_ICON_UNREAD_NET_L2_SLAVE,
    STATUS_ICON_UNREAD_NET_L1L2_SLAVE,
    STATUS_ICON_UNREAD_VIDEO_L1_SLAVE,
    STATUS_ICON_UNREAD_VIDEO_L2_SLAVE,
    STATUS_ICON_UNREAD_VIDEO_L1L2_SLAVE
    #endif
#if (MMI_MAX_SIM_NUM >= 3)
    ,STATUS_ICON_UNREAD_VOICE_L1_SIM3,
    STATUS_ICON_UNREAD_VOICE_L2_SIM3,
    STATUS_ICON_UNREAD_VOICE_L1L2_SIM3
    #ifndef __MMI_STATUS_ICON_BAR_SLIM__ 
    ,STATUS_ICON_UNREAD_FAX_L1_SIM3,
    STATUS_ICON_UNREAD_FAX_L2_SIM3,
    STATUS_ICON_UNREAD_FAX_L1L2_SIM3,
    STATUS_ICON_UNREAD_EMAIL_L1_SIM3,
    STATUS_ICON_UNREAD_EMAIL_L2_SIM3,
    STATUS_ICON_UNREAD_EMAIL_L1L2_SIM3,
    STATUS_ICON_UNREAD_NET_L1_SIM3,
    STATUS_ICON_UNREAD_NET_L2_SIM3,
    STATUS_ICON_UNREAD_NET_L1L2_SIM3,
    STATUS_ICON_UNREAD_VIDEO_L1_SIM3,
    STATUS_ICON_UNREAD_VIDEO_L2_SIM3,
    STATUS_ICON_UNREAD_VIDEO_L1L2_SIM3
    #endif
#endif /*(MMI_MAX_SIM_NUM >= 3) */
#if (MMI_MAX_SIM_NUM >= 4)
    ,STATUS_ICON_UNREAD_VOICE_L1_SIM4,
    STATUS_ICON_UNREAD_VOICE_L2_SIM4,
    STATUS_ICON_UNREAD_VOICE_L1L2_SIM4
    #ifndef __MMI_STATUS_ICON_BAR_SLIM__ 
    ,STATUS_ICON_UNREAD_FAX_L1_SIM4,
    STATUS_ICON_UNREAD_FAX_L2_SIM4,
    STATUS_ICON_UNREAD_FAX_L1L2_SIM4,
    STATUS_ICON_UNREAD_EMAIL_L1_SIM4,
    STATUS_ICON_UNREAD_EMAIL_L2_SIM4,
    STATUS_ICON_UNREAD_EMAIL_L1L2_SIM4,
    STATUS_ICON_UNREAD_NET_L1_SIM4,
    STATUS_ICON_UNREAD_NET_L2_SIM4,
    STATUS_ICON_UNREAD_NET_L1L2_SIM4,
    STATUS_ICON_UNREAD_VIDEO_L1_SIM4,
    STATUS_ICON_UNREAD_VIDEO_L2_SIM4,
    STATUS_ICON_UNREAD_VIDEO_L1L2_SIM4
    #endif
#endif /*(MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM) */
};

#if (MMI_MAX_SIM_NUM == 2) && defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) && !defined(__MMI_SLIM_IMG_RES__) && !defined(__MMI_NCENTER_SUPPORT__)
const S32 sms_msg_waiting_icon_no_sim[] = 
{
    STATUS_ICON_UNREAD_VOICE_L1,
    STATUS_ICON_UNREAD_VOICE_L2,
    STATUS_ICON_UNREAD_VOICE_L1L2
   #ifndef __MMI_STATUS_ICON_BAR_SLIM__ 
    ,STATUS_ICON_UNREAD_FAX_L1,
    STATUS_ICON_UNREAD_FAX_L2,
    STATUS_ICON_UNREAD_FAX_L1L2,
    STATUS_ICON_UNREAD_EMAIL_L1,
    STATUS_ICON_UNREAD_EMAIL_L2,
    STATUS_ICON_UNREAD_EMAIL_L1L2,
    STATUS_ICON_UNREAD_NET_L1,
    STATUS_ICON_UNREAD_NET_L2,
    STATUS_ICON_UNREAD_NET_L1L2,
    STATUS_ICON_UNREAD_VIDEO_L1,
    STATUS_ICON_UNREAD_VIDEO_L2,
    STATUS_ICON_UNREAD_VIDEO_L1L2	
    #endif
};
#endif

#endif /* __MMI_SLIM_IMG_RES__ */

U64 g_sms_wait_icon = 0;
static void mmi_sms_set_msg_waiting_flag(U16 index);
#if (defined(__MMI_SLIM_IMG_RES__) && (MMI_MAX_SIM_NUM <= 2)) || defined(__MMI_NCENTER_SUPPORT__)
static MMI_BOOL mmi_sms_check_msg_waiting_flag(U8 ind_type);
#else
static MMI_BOOL mmi_sms_get_msg_waiting_flag(U16 index);
#endif
static void mmi_sms_reset_msg_waiting_flag(U16 index);


/****************************************************************

            generic functions

****************************************************************/
#ifdef __MMI_TELEPHONY_SUPPORT__
#if (defined(__MMI_SLIM_IMG_RES__) && (MMI_MAX_SIM_NUM <= 2)) || defined(__MMI_NCENTER_SUPPORT__)

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_msg_waiting_icon
 * DESCRIPTION
 *  Set msg icon for waiting vm/email/fax
 * PARAMETERS
 *  line        [IN]        
 *  type        [IN]        
 *  set         [IN]        
 *  a(?)        [IN]        Line
 *  c(?)        [IN]        Set/unset
 *  b(?)        [IN]        Type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_msg_waiting_icon(srv_sms_sim_enum sim_id, U8 line, U8 ind_type, U8 set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum mmi_sim = SRV_SMS_SMS_SIM_TO_MMI(sim_id);
    U32 flagIndex = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ind_type >= MAX_WAITING_TYPE_NUM)
    {
        return;
    }
    #ifdef __MMI_STATUS_ICON_BAR_SLIM__
	if(ind_type !=0)
	{
	return;
	}
     #endif

#if (MMI_MAX_SIM_NUM >= 2)
    flagIndex = mmi_frm_sim_to_index(mmi_sim) *MMI_SMS_MSG_WAITING_FLAG_NUM;
#endif

    flagIndex = flagIndex+ ind_type * MAX_WAITING_LINE_NUM + line;

    if (set)
    {
        mmi_sms_set_msg_waiting_flag(flagIndex);
    }
    else
    {
        mmi_sms_reset_msg_waiting_flag(flagIndex);
    }

    wgui_status_icon_bar_reset_icon_display(sms_msg_waiting_icon[ind_type]);

    if (srv_sms_is_sms_valid() && mmi_sms_check_msg_waiting_flag(ind_type))
    {
        wgui_status_icon_bar_set_icon_display(sms_msg_waiting_icon[ind_type]);
    }

    wgui_status_icon_bar_update();
}

#else

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_msg_waiting_icon
 * DESCRIPTION
 *  Set msg icon for waiting vm/email/fax
 * PARAMETERS
 *  line        [IN]        
 *  type        [IN]        
 *  set         [IN]        
 *  a(?)        [IN]        Line
 *  c(?)        [IN]        Set/unset
 *  b(?)        [IN]        Type
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_msg_waiting_icon(srv_sms_sim_enum sim_id, U8 line, U8 ind_type, U8 set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    mmi_sim_enum mmi_sim = SRV_SMS_SMS_SIM_TO_MMI(sim_id);
#endif
    MMI_BOOL show_icon = MMI_FALSE;
    MMI_BOOL set_falg = MMI_TRUE;
    U32 i = 0;
    U32 iconIndex = 0;
    U32 otherline = (line == 0 ? 1 : 0);
    MMI_BOOL otherline_state = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ind_type >= MAX_WAITING_TYPE_NUM)
    {
        return;
    }

#if (MMI_MAX_SIM_NUM >= 2)
    iconIndex = mmi_frm_sim_to_index(mmi_sim) *MMI_SMS_MSG_WAITING_FLAG_NUM;
#endif

    iconIndex = iconIndex+ ind_type * (MAX_WAITING_LINE_NUM + 1);

    if (mmi_sms_get_msg_waiting_flag(iconIndex + MAX_WAITING_LINE_NUM)
        || mmi_sms_get_msg_waiting_flag(iconIndex + otherline)
        )
    {
        otherline_state = MMI_TRUE;
    }

#ifdef __MMI_SLIM_IMG_RES__
    wgui_status_icon_bar_hide_icon(sms_msg_waiting_icon[iconIndex/3]);

    for (i = 0; i < (MAX_WAITING_LINE_NUM + 1); i++)
    {
        mmi_sms_reset_msg_waiting_flag(iconIndex + i);
    }
#else
    for (i = 0; i < (MAX_WAITING_LINE_NUM + 1); i++)
    {
		wgui_status_icon_bar_hide_icon(sms_msg_waiting_icon[iconIndex + i]);
		mmi_sms_reset_msg_waiting_flag(iconIndex + i);
    #if (MMI_MAX_SIM_NUM == 2) && defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) && !defined(__MMI_SLIM_IMG_RES__)&& !defined(__MMI_NCENTER_SUPPORT__)
    	wgui_status_icon_bar_hide_icon(sms_msg_waiting_icon_no_sim[ind_type * (MAX_WAITING_LINE_NUM + 1) + i]);
    #endif
    }
#endif

    if (srv_sms_is_sms_valid())
    {
        show_icon = MMI_TRUE;
    }

    if ((set > 0) && otherline_state)
    {
        iconIndex = iconIndex + MAX_WAITING_LINE_NUM;
    }
    else if (set > 0)
    {
        iconIndex = iconIndex + line;
    }
    else if (otherline_state)
    {
        iconIndex = iconIndex + otherline;
    }
    else
    {
        set_falg = MMI_FALSE;
    }

    if (set_falg)
    {
		if (show_icon)
		{
		#ifdef __MMI_SLIM_IMG_RES__
            wgui_status_icon_bar_show_icon(sms_msg_waiting_icon[iconIndex/3]);
        #else
    	#if (MMI_MAX_SIM_NUM == 2) && defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) && !defined(__MMI_SLIM_IMG_RES__)&& !defined(__MMI_NCENTER_SUPPORT__)
        	if(!srv_sim_ctrl_is_inserted(MMI_SIM1) || !srv_sim_ctrl_is_inserted(MMI_SIM2))
            {
    			wgui_status_icon_bar_show_icon(sms_msg_waiting_icon_no_sim[iconIndex%MMI_SMS_MSG_WAITING_FLAG_NUM]);
            }
            else
    	#endif
        	{
				wgui_status_icon_bar_show_icon(sms_msg_waiting_icon[iconIndex]);
            }
        #endif
		}

        mmi_sms_set_msg_waiting_flag(iconIndex);
    }
}
#endif
#endif /* __MMI_TELEPHONY_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_exit_generic
 * DESCRIPTION
 *  Exit generic function for MSG app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_exit_generic(void)
{
#ifdef __MMI_TELEPHONY_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.MessagesScrnIdDelUptoHistoryNodes = GetMessagesCurrScrnID();
    SetMessagesCurrScrnID(0);   /* messagesCurrScrnID */
    /* MTK Leo add, mini_tab_bar */
#ifdef __MMI_WGUI_MINI_TAB_BAR__
    wgui_disable_mini_tab_bar();
#endif 
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    /* MTK Leo end */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_is_new_msg_popup_scr_active
 * DESCRIPTION
 *  To get new message popup active or not.
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL
 *****************************************************************************/
pBOOL mmi_msg_is_new_msg_popup_scr_active(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_msg_cntx.isNewMessagePopup;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_init_msg_data
 * DESCRIPTION
 *  Init message data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_init_msg_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_msg_cntx.msg_dial_voicemail_from_idle_longpress = MMI_TRUE;
    g_msg_cntx.msg_ind_index = SMSAL_INVALID_INDEX;
    g_msg_cntx.msg_ind_in_idle = MMI_FALSE;
    g_msg_cntx.msg_ind_after_call = MMI_FALSE;
    g_msg_cntx.msg_class0_ind = MMI_FALSE;

    for (index = 0; index < MMI_SIM_TOTAL; index++)
    {
        g_msg_cntx.msg_full_ind[index] = MMI_FALSE;
    }

    g_msg_cntx.msg_exceed_ind = MMI_FALSE;
    g_msg_cntx.msg_waiting_ind = MMI_FALSE;
    g_msg_cntx.isNewMessagePopup = MMI_FALSE;
    g_msg_cntx.msg_status = MSG_STATUS_IDLE;
    g_msg_cntx.msg_class0_p = NULL;
    g_msg_cntx.currBoxIndex = SRV_SMS_INVALID_LIST_INDEX;
    memset(&g_msg_cntx.msg_waiting_info, 0, MAX_WAITING_LINE_NUM * sizeof(msg_waiting_ind_struct));

}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_deinit_msg_data
 * DESCRIPTION
 *  Deinit message data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_deinit_msg_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_msg_cntx.msg_class0_p != NULL)
    {
        OslMfree(g_msg_cntx.msg_class0_p);
        g_msg_cntx.msg_class0_p = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_pre_entry_write_new_msg
 * DESCRIPTION
 *  pre-entry write new sms 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_pre_entry_write_new_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TELEPHONY_SUPPORT__
    mmi_sms_group_entry(GRP_ID_ROOT);
    mmi_sms_entry_write_msg(SMS_SEND_CASE_WRITE_NEW_MSG);
#endif /* __MMI_TELEPHONY_SUPPORT__ */
}

#ifdef __MMI_TELEPHONY_SUPPORT__
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_update_unsent_icon
 * DESCRIPTION
 *  update idle top bar unsent box icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_update_unsent_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 totalunsent;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    totalunsent = srv_sms_get_list_size(SRV_SMS_BOX_UNSENT);
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
#endif /*__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_skip_end_char
 * DESCRIPTION
 *  if current sms is hiden sms, we will skip the header, as normal sms handle
 * PARAMETERS
 *  MsgTxt      [IN]        Message text         
 *  length       [IN]        The length of Message text
 * RETURNS
 *  
 *****************************************************************************/
U16 mmi_msg_skip_end_char(S8 *pOut, S8 *pIn, U16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 tmpLen = 0;
	U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(pOut == NULL || pIn == NULL)
	{
		return 0;
	}	
	while(tmpLen < length)
	{		
		if(mmi_ucs2cmp(pIn + tmpLen, "\0"))
		{
			*(pOut + i++) = *(pIn + tmpLen);
			*(pOut + i++) = *(pIn + tmpLen + 1);			
		}
		tmpLen += 2;		
	}
	*(pOut + i) = '\0';
	*(pOut + i + 1) = '\0';
	
	return i>>1;
}


#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_set_msg_waiting_flag
 * DESCRIPTION
 *  Set Slave SMS waiting flag
 * PARAMETERS
 * index        index
 *         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_set_msg_waiting_flag(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < MMI_SMS_MAX_MSG_WAITING_ICON)
    {
    	g_sms_wait_icon |= (U64)1<<index;
    }
}


#if (defined(__MMI_SLIM_IMG_RES__) && (MMI_MAX_SIM_NUM <= 2)) || defined(__MMI_NCENTER_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_check_msg_waiting_flag
 * DESCRIPTION
 *  Set Slave SMS waiting flag
 * PARAMETERS
 * index        index
 *         
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sms_check_msg_waiting_flag(U8 ind_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    U32 flag_line1;
    U32 flag_line2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < MMI_SIM_TOTAL; index++)
    {
        flag_line1 = index * (MAX_WAITING_TYPE_NUM * MAX_WAITING_LINE_NUM) + ind_type * MAX_WAITING_LINE_NUM;
        flag_line2 = flag_line1 + 1;

        if (((g_sms_wait_icon>>flag_line1)&0x01) || ((g_sms_wait_icon>>flag_line2)&0x01))
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}

#else
/*****************************************************************************
 * FUNCTION
 *  mmi_sms_get_msg_waiting_flag
 * DESCRIPTION
 *  Set Slave SMS waiting flag
 * PARAMETERS
 * index        index
 *         
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_sms_get_msg_waiting_flag(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < MMI_SMS_MAX_MSG_WAITING_ICON)
    {
    	if ((g_sms_wait_icon>>index)&0x01)
        {
            return MMI_TRUE;
        }   
    }

    return MMI_FALSE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_reset_msg_waiting_flag
 * DESCRIPTION
 *  Set Slave SMS waiting flag
 * PARAMETERS
 * index        index
 *         
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_sms_reset_msg_waiting_flag(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < MMI_SMS_MAX_MSG_WAITING_ICON)
    {
        g_sms_wait_icon &= ~((U64)1<<index);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_reset_msg_waiting_flag
 * DESCRIPTION
 *  Set Slave SMS waiting flag
 * PARAMETERS
 * index        index
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_reset_msg_waiting_flag_ext(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 start = 0;
    U32 end;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    start = mmi_frm_sim_to_index(sim) *MMI_SMS_MSG_WAITING_FLAG_NUM;
#endif

    end = start + MMI_SMS_MSG_WAITING_FLAG_NUM;

    for (i = start; i < end; i++)
    {
        mmi_sms_reset_msg_waiting_flag(i);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sms_check_msg_waiting_icon
 * DESCRIPTION
 *  Set Slave SMS waiting flag
 * PARAMETERS
 * index        index
 *         
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sms_check_msg_waiting_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 index = 0;
    MMI_BOOL sms_valid = srv_sms_is_sms_valid();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__MMI_SLIM_IMG_RES__) && (MMI_MAX_SIM_NUM <= 2)) || defined(__MMI_NCENTER_SUPPORT__)
	for (index = 0; index < MAX_WAITING_TYPE_NUM; index++)
	{
		wgui_status_icon_bar_reset_icon_display(sms_msg_waiting_icon[index]);

		if (sms_valid && mmi_sms_check_msg_waiting_flag(index))
		{
			wgui_status_icon_bar_set_icon_display(sms_msg_waiting_icon[index]);	
		}
	}
#else
	for (index = 0; index < MMI_SMS_MAX_MSG_WAITING_ICON; index++)
	{
	    mmi_sim_enum mmi_sim;
    #ifdef __MMI_SLIM_IMG_RES__
        U32 icon_index = index/3;
    #else
        U32 icon_index = index;
    #endif

    #ifdef __MMI_SLIM_IMG_RES__
        if (index%3 == 0)
    #endif
        {
		    wgui_status_icon_bar_reset_icon_display(sms_msg_waiting_icon[icon_index]);
        }

	#if (MMI_MAX_SIM_NUM == 2) && defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) && !defined(__MMI_SLIM_IMG_RES__)&& !defined(__MMI_NCENTER_SUPPORT__)
    	if (index/MMI_SMS_MSG_WAITING_FLAG_NUM == 0)
        {
        	wgui_status_icon_bar_reset_icon_display(sms_msg_waiting_icon_no_sim[icon_index]);
        }
	#endif
    #ifdef __MMI_TELEPHONY_SUPPORT__
		if (sms_valid)
		{
		    mmi_sim = mmi_frm_index_to_sim(index/15);

			if (srv_sim_ctrl_is_available(mmi_sim) && mmi_sms_get_msg_waiting_flag(index))
			{
            #if (MMI_MAX_SIM_NUM == 2) && defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) && !defined(__MMI_SLIM_IMG_RES__)&& !defined(__MMI_NCENTER_SUPPORT__)
            	if(!srv_sim_ctrl_is_inserted(MMI_SIM1) || !srv_sim_ctrl_is_inserted(MMI_SIM2))
                {
                	wgui_status_icon_bar_set_icon_display(sms_msg_waiting_icon_no_sim[icon_index%MMI_SMS_MSG_WAITING_FLAG_NUM]);
                }
                else
            #endif
            	{
            		wgui_status_icon_bar_set_icon_display(sms_msg_waiting_icon[icon_index]);
            	}
			}
		}
    #endif
	}
#endif

    wgui_status_icon_bar_update();
}


#ifdef __MMI_MESSAGES_SMS_EMAIL__

static void mmi_msg_to_lower_case(PS8 ptr, PS16 U16);
static S8 *pfnUnicodeStristr(S8 *text, S8 *pattern);

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_to_lower_case
 * DESCRIPTION
 *  Convert ascii upper case character to unicode lower case
 * PARAMETERS
 *  ptr         [IN]            
 *  U16         [IN]            
 *  a(?)        [IN]            Ptr   a pointer points to an ascii character
 *  b(?)        [IN/OUT]        Word  a pointer points to an unicode character
 * RETURNS
 *  a pointer points to an unicode character(?)
 *****************************************************************************/
static void mmi_msg_to_lower_case(PS8 ptr, PS16 U16)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 two_byte_A = 0x0041;
    S16 two_byte_Z = 0x005A;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*((S16*) ptr) >= two_byte_A && *((S16*) ptr) <= two_byte_Z)
    {
        *U16 = (S16) ('a' + (*ptr) - 'A');
    }
    else
    {
        *U16 = *((S16*) (ptr));
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  pfnUnicodeStristr
 * DESCRIPTION
 *  finds pattern in given text
 * PARAMETERS
 *  text        [?]         
 *  pattern     [?]         
 *  a(?)        [IN]        Text
 *  b(?)        [IN]        Pattern
 * RETURNS
 *  a  SUCCESS     Starting address of pattern in text
 * B  FAIL     NULL
 *****************************************************************************/
static S8 *pfnUnicodeStristr(S8 *text, S8 *pattern)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *ptr = NULL;
    S8 *ret_addr = NULL;
    MMI_BOOL pattern_found = MMI_FALSE;
    S16 text_lower_case_char = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = pattern;
    while (mmi_ucs2cmp(text, "\0"))
    {
        ret_addr = text;
        mmi_msg_to_lower_case(text, &text_lower_case_char);
        while (!mmi_ucs2ncmp((S8*) & text_lower_case_char, ptr, 1))
        {
            ptr += 2;
            text += 2;
            mmi_msg_to_lower_case(text, &text_lower_case_char);

            if (!mmi_ucs2ncmp(text, "\0", 1))
            {
                break;
            }
        }   /* while... */

        if (!mmi_ucs2ncmp(ptr, "\0", 1))
        {
            pattern_found = MMI_TRUE;
            break;
        }

        if (ptr != pattern)
        {
            ptr = pattern;
        }
        else
        {
            text += 2;
        }
    }   /* while... */

    if (!pattern_found)
    {
        ret_addr = NULL;
    }

    return (S8*) ret_addr;
}   /* func().... */


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_get_email_and_subject_from_msgtxt
 * DESCRIPTION
 *  Extract all URL from message text
 * PARAMETERS
 *  pText       [IN]        Message text         
 *  txtLen      [IN]        The lenth of Message text
 * RETURNS
 *  Total URL count in message text
 *****************************************************************************/
void mmi_msg_get_email_and_subject_from_msgtxt(S8 *pText, U16 txtLen, S8 *pEmail,U16 emailLen, S8 *pSubject, U16 subLen, U16 *actual_email_ucs2_length, U16 *actual_sub_ucs2_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 Pattern[6];
	PS8 pSubprefix[2] = { "##", "(" };
	PS8 pSubpostfix[2] = { "#", ")" };
	MMI_BOOL isSubject = MMI_FALSE;
    PS8 ptr = NULL;
	PS8 pSubStart = NULL;
	PS8 pSubEnd = NULL;
	PS8 pEnd = NULL;
	S8 *MsgTxt = pText;
	U32 len = 0;
	U8 i = 0;
	U32 prefixLen = 0;
    U16 temp_actual_email_ucs2_length = 0;
    U16 temp_actual_sub_ucs2_length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pEmail != NULL)
    {
        *pEmail = '\0';
        *(pEmail + 1)  = '\0';
    }
    if (pSubject != NULL)
    {
        *pSubject = '\0';
        *(pSubject + 1)  = '\0';
    }
        
	for (i = 0; i < 2; i++)
	{
		MsgTxt = pText;
		memset(Pattern, 0, 6);
		mmi_asc_to_ucs2(Pattern, pSubprefix[i]);
		pSubStart = pfnUnicodeStristr(MsgTxt, Pattern);
		if (pSubStart != NULL)
		{
			U32 tmpLen;

			memset(Pattern, 0, 6);
			mmi_asc_to_ucs2(Pattern, pSubpostfix[i]);
			tmpLen = strlen(pSubprefix[i])<<1;
			MsgTxt = pSubStart + tmpLen;
			pSubEnd = pfnUnicodeStristr(MsgTxt, Pattern);
			if (pSubEnd != NULL)
			{
				if (ptr == NULL || pSubStart < ptr)
				{
					prefixLen = tmpLen;
					ptr = pSubStart;
					pEnd = pSubEnd;
				}
			}
		}
	}
	MsgTxt = pText;
	memset(Pattern, 0, 6);
	mmi_asc_to_ucs2(Pattern, " ");
    /* search the " " in the MsgTxt */
    pSubStart = pfnUnicodeStristr(MsgTxt, Pattern);	
 
	if (ptr != NULL && pSubStart == NULL || (ptr != NULL && pSubStart != NULL &&
		ptr < pSubStart))
	{
		isSubject = MMI_TRUE;
	}
	else
	{	
	    ptr = pSubStart;
		prefixLen = 2;
	}

	MsgTxt = pText;		
	if (ptr != NULL)
	{
        U8 tmpData[MAX_SMS_EMAIL_NUMBER];
	        
		len = (U32)(ptr - MsgTxt);
		if (len > emailLen)
		{
			len = emailLen;
		}
		mmi_ucs2ncpy(pEmail, MsgTxt, len>>1);
        temp_actual_email_ucs2_length = len>>1;
		mmi_ucs2_to_asc((S8*) tmpData, (S8*) pEmail);
		if (applib_is_valid_email_address((char*)tmpData) == KAL_FALSE)
		{
		    memset(pEmail, 0, emailLen);
			ptr = MsgTxt;
            prefixLen = 0;
            temp_actual_email_ucs2_length = 0;
		}
		
		memset(Pattern, 0, 6);
		mmi_asc_to_ucs2(Pattern, pSubprefix[0]);
		pSubStart = pfnUnicodeStristr(MsgTxt, Pattern);
		ptr += prefixLen;

		if (pSubject != NULL && ptr != NULL)
		{
			if (isSubject)
			{
				len = (U32)(pEnd - ptr);	
			}
			else
			{
				len = (U32)txtLen - (U32)(ptr - pText);				
			}
			if (len > subLen)
			{
				len = subLen;
			}
			mmi_ucs2ncpy((S8*)pSubject, (S8*) ptr, len>>1);
		}
	}	
	else if (pSubject != NULL)
	{
		len = subLen;
		if (txtLen < subLen)
		{
			len = txtLen;
		}
		if (len > subLen)
		{
			len = subLen;
		}
		mmi_ucs2ncpy((S8*)pSubject, (S8*) pText, len>>1);
        temp_actual_sub_ucs2_length = len>>1;
	}
    
    if (actual_email_ucs2_length)
    {
        *actual_email_ucs2_length = temp_actual_email_ucs2_length;
    }
    
    if (actual_sub_ucs2_length)
    {
        *actual_sub_ucs2_length = temp_actual_sub_ucs2_length;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_remove_email_address_from_msgtxt
 * DESCRIPTION
 *  Remove email address from message text
 * PARAMETERS
 *  data       [IN]        Ems buffer
 * RETURNS
 *  
 *****************************************************************************/
void mmi_msg_remove_email_address_from_msgtxt(EMSData *data, U16 len)
{
	if (len > 0)
	{
#ifndef __ULC_SLIM_EMS__
        U16 char_num_to_remove = (U16)(len + 1);/* Add one charactor for seperate char ' ' or '' */
        EMSPosition position;

        position = data->CurrentPosition;
		ResetCurrentPosition(data);
		ForwardCurrentPosition(data, char_num_to_remove);			
		CancelCurrentPosition(data, char_num_to_remove);
        MoveCursorToPosition(data, &position);
#else /* __ULC_SLIM_EMS__ */
        mmi_msg_remove_email_address_from_text_only_msgtxt(data->textBuffer, len);
#endif  /* __ULC_SLIM_EMS__ */
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_remove_email_address_from_text_only_msgtxt
 * DESCRIPTION
 *  Remove email address from message text
 * PARAMETERS
 *  data       [IN]        Ems buffer
 * RETURNS
 *  
 *****************************************************************************/
void mmi_msg_remove_email_address_from_text_only_msgtxt(S8 *data, U16 text_length)
{
	if (text_length > 0)
	{
        U16 total_length = mmi_ucs2strlen(data);
        mmi_ucs2ncpy(data, data + text_length, (total_length - text_length - 1));
	}
}


#endif /* __MMI_MESSAGES_SMS_EMAIL__ */


#ifdef __MMI_BPP20_SUPPORT__
/*
MACRO
*/
#define MMI_MSG_BPP_FILE_PATH_LEN           40
#define MMI_MSG_BPP_FILE_NAME_LEN           40
#define MMI_MSG_BPP_FULL_FILE_NAME_LEN      (MMI_MSG_BPP_FILE_PATH_LEN + MMI_MSG_BPP_FILE_NAME_LEN)

#define MMI_MSG_BPP_FOLDER_NAME             "bpp_ems"

#define MAX_EMS_PREDEFINED_ANIMATIONS       15

#define MMI_MSG_BPP_BUFF_SIZE				1024
#define MMI_MSG_BPP_TEMP_BUFF_SIZE			128
#define MMI_MSG_BPP_MAX_ENCODING_CHAR_NUM	((MMI_MSG_BPP_BUFF_SIZE - 1) / 3)	

#define EMS_BPP_TEXT_SIZE_LARGE				130
#define EMS_BPP_TEXT_SIZE_NORMAL			100
#define EMS_BPP_TEXT_SIZE_SMALL				70

#define EMS_BPP_TEXT_STYLE_BOLD				"bold"
#define EMS_BPP_TEXT_STYLE_ITALIC			"italic"
#define EMS_BPP_TEXT_STYLE_UNDERLINE		"underline"
#define EMS_BPP_TEXT_STYLE_STRIKE_THROUGH	"line-through"

#define EMS_BPP_TEXT_ALIGN_LEFT				"left"
#define EMS_BPP_TEXT_ALIGN_RIGHT			"right"
#define EMS_BPP_TEXT_ALIGN_CENTER			"center"


#define MMI_MSG_BPP_IMAGE_FILE_NAME			"bpp_ems_image_%d.jpg"

#define MMI_MSG_BPP_SPACE_CHAR				"&nbsp;"
#define MMI_MSG_BPP_CR_CHAR					"<br />"

#define MMI_MSG_BPP_TAB_TO_SPACE_SIZE		4

#ifndef EMS_ESCAPE_CHARACTER
#define EMS_ESCAPE_CHARACTER                0x1B
#endif

#define MMI_MSG_BPP_MAX_NUMBER_FIELD_LEN		40
#define MMI_MSG_BPP_MAX_TIMESTAMP_FIELD_LEN		50

static MMI_ID mmi_sms_bpp_gid = GRP_ID_INVALID;
static MMI_ID mmi_sms_bpp_parent_gid = GRP_ID_ROOT;

/*
Static Function Declaration
*/
static S32 mmi_msg_bpp_print_ems(void);

static S32 mmi_msg_bpp_compose_xhtml_file(
			   U32 handle,
			   WCHAR *pfile_name,
			   U32 *size);

static MMI_BOOL mmi_msg_bpp_compose_css_style(U32 inst, void *xhtml, CHAR *buff);
static MMI_BOOL mmi_msg_bpp_compose_body(void *xhtml, CHAR *buff);

static MMI_BOOL mmi_msg_bpp_compose_number(void *xhtml, CHAR *buff);
static MMI_BOOL mmi_msg_bpp_compose_timestamp(void *xhtml, CHAR *buff);
static MMI_BOOL mmi_msg_bpp_compose_content(void *xhtml, CHAR *buff);

static MMI_BOOL mmi_msg_bpp_compose_text(void *xhtml, CHAR *buff, WCHAR* curr_text, U32 ucs2_len);

#if (!UI_DISABLE_EMS_CATEGORY_SCREENS)
static MMI_BOOL mmi_msg_bpp_compose_object(
                    void *xhtml,
					CHAR *buff,
                    EMSObject *object,
                    U16 object_count,
                    MMI_BOOL is_gen_pic);
static MMI_BOOL mmi_msg_encode_ems_picture_to_jpeg(EMSObject *object, S8* jpeg_file_name);
static void mmi_msg_draw_ems_picture(U8* src, S32 src_size, S32 w, S32 h, S32 bits_per_pixel);
static MMI_BOOL mmi_msg_bpp_check_duplicated_picture(EMSObject *scr_obj, EMSObject *dest_obj);
static MMI_BOOL mmi_msg_bpp_create_folder(void);
static void mmi_msg_bpp_get_folder_name(S8* file_name_buff);
static void mmi_msg_bpp_get_image_file_name(S8* file_name_buff, U16 image_count);
#endif /* (!UI_DISABLE_EMS_CATEGORY_SCREENS) */

static void mmi_msg_bpp_print_deinit(void);


/*
Structure Declaration
*/
typedef enum
{
	BPP_PRINT_EDIT_EMS,
	BPP_PRINT_VIEW_EMS,
	BPP_PRINT_EMS_TOTAL
}mmi_msg_bpp_ems_type_enum;


typedef enum
{
	MSG_BPP_ERR_OK,
	MSG_BPP_ERR_FS_ROOT_DIR_FULL,
	MSG_BPP_ERR_FS_DISK_FULL,
	MSG_BPP_ERR_OTHER,
	MSG_BPP_ERR_TOTAL
}mmi_msg_bpp_ems_error_enum;

typedef struct
{
	EMSData *ems_data;
	U32 buf_remain;
	U16 msg_index;
    MMI_BOOL is_from;
    mmi_msg_bpp_ems_error_enum error_code;
	mmi_msg_bpp_ems_type_enum print_ems_type;
}mmi_msg_bpp_print_data_struct;


/*
static variable
*/
#if (!UI_DISABLE_EMS_CATEGORY_SCREENS)
const static U16 mmi_msg_ems_predef_animations[MAX_EMS_PREDEFINED_ANIMATIONS] = 
{
	EMS_BI_ANIMATION_0_ID,
    EMS_BI_ANIMATION_1_ID,
    EMS_BI_ANIMATION_2_ID,
    EMS_BI_ANIMATION_3_ID,
    EMS_BI_ANIMATION_4_ID,
    EMS_BI_ANIMATION_5_ID,
    EMS_BI_ANIMATION_6_ID,
    EMS_BI_ANIMATION_7_ID,
    EMS_BI_ANIMATION_8_ID,
    EMS_BI_ANIMATION_9_ID,
    EMS_BI_ANIMATION_10_ID,
    EMS_BI_ANIMATION_11_ID,
    EMS_BI_ANIMATION_12_ID,
    EMS_BI_ANIMATION_13_ID,
    EMS_BI_ANIMATION_14_ID
};
#endif /* (!UI_DISABLE_EMS_CATEGORY_SCREENS) */

static mmi_msg_bpp_print_data_struct *msg_print_data;

/*****************************************************************************
 * FUNCTION
 *  mmi_sms_bpp_print_group_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  evt  event struct
 * RETURNS
 *  
 *****************************************************************************/
static mmi_ret mmi_sms_bpp_print_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_INACTIVE:
            if (!mmi_frm_scrn_get_count(mmi_sms_bpp_gid))
            {
                mmi_frm_group_close(mmi_sms_bpp_gid);
            }
            break;

        case EVT_ID_GROUP_DEINIT:
            mmi_msg_bpp_print_deinit();
            mmi_sms_bpp_gid = GRP_ID_INVALID;
            mmi_sms_bpp_parent_gid= GRP_ID_ROOT;
            break;

        case EVT_BT_PRINT_START:
            break;

         case EVT_BT_PRINT_DATA_REQ:
            {
                U32 size;
                evt_bt_print_data_req_struct *prnt_evt = (evt_bt_print_data_req_struct *)evt;
                WCHAR *file = prnt_evt->storage.u.file;
                S32 result = mmi_msg_bpp_compose_xhtml_file(prnt_evt->inst, file, &size);

                if (result == BPP_E_OK)
                {
                    prnt_evt->storage.content_type= BT_PRINT_CONTENT_XHTML;
                    prnt_evt->storage.more = 0;
                    prnt_evt->storage.size = size;

                    cui_bt_printing_set_data(prnt_evt->inst, &prnt_evt->storage);
                }
            }        
          
            break;

        case EVT_BT_PRINT_COMPLETE:
            mmi_msg_bpp_print_deinit();
            mmi_frm_group_close(mmi_sms_bpp_gid);
            mmi_sms_bpp_gid = GRP_ID_INVALID;
            mmi_sms_bpp_parent_gid= GRP_ID_ROOT;
            break;

        default:
            break;
    }
 
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_bpp_pre_print_ems
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_bpp_pre_print_ems(MMI_ID parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sms_status_enum curr_msg_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_PRINT_INBOX_EMS);

    if (parent_gid == GRP_ID_INVALID)
    {
        return;
    }

    if (mmi_sms_bpp_gid != GRP_ID_INVALID)
    {
        mmi_frm_group_close(mmi_sms_bpp_gid);
    }

    mmi_sms_bpp_gid = mmi_frm_group_create_ex(
        parent_gid,
        GRP_ID_AUTO_GEN,
        mmi_sms_bpp_print_group_proc,
        NULL,
        0);

    mmi_sms_bpp_parent_gid = parent_gid;

    curr_msg_status = srv_sms_get_msg_status(g_sms_cntx.curr_msg_id);

	if (msg_print_data != NULL)
	{
		OslMfree(msg_print_data);
	}
	msg_print_data = OslMalloc(sizeof(mmi_msg_bpp_print_data_struct));

	GetEMSDataForView(&msg_print_data->ems_data, 0);

	msg_print_data->print_ems_type = BPP_PRINT_VIEW_EMS;	

	msg_print_data->msg_index = g_sms_cntx.curr_msg_id;

    if ((curr_msg_status & SRV_SMS_STATUS_UNREAD) ||
        (curr_msg_status & SRV_SMS_STATUS_READ))
    {
        msg_print_data->is_from = MMI_TRUE;
    }
    else
    {
        msg_print_data->is_from = MMI_FALSE;
    }

	msg_print_data->buf_remain = MMI_MSG_BPP_BUFF_SIZE;
    msg_print_data->error_code = MSG_BPP_ERR_OK;

	if (!mmi_msg_bpp_print_ems())
	{
        if (msg_print_data != NULL)
        {
            OslMfree(msg_print_data);
            msg_print_data = NULL;
        }
        mmi_frm_group_close(mmi_sms_bpp_gid);
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_bpp_print_ems
 * DESCRIPTION
 *  print EMS
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
static S32 mmi_msg_bpp_print_ems(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 hjob = 0;
#ifndef JPG_ENCODE
    EMSObject *curr_object = msg_print_data->ems_data->listHead;
    MMI_BOOL is_need_encode_jpeg = MMI_FALSE;
#endif /* JPG_ENCODE */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_PRINT_EMS);

#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        return 0;
    }
#endif /* __USB_IN_NORMAL_MODE__ */

#ifndef JPG_ENCODE
    while (curr_object != NULL)
    {
        if ((curr_object->Type == EMS_TYPE_PREDEF_SND)  ||
            (curr_object->Type == EMS_TYPE_USERDEF_SND) ||
            (curr_object->Type == EMS_TYPE_PREDEF_ANM)  ||
            (curr_object->Type == EMS_TYPE_USERDEF_ANM) ||
            (curr_object->Type == EMS_TYPE_PIC))
        {
            is_need_encode_jpeg = MMI_TRUE;
        }

        curr_object = curr_object->next;
    }

    if (is_need_encode_jpeg == MMI_TRUE)
    {
        mmi_sms_display_popup_ext(
            STR_GLOBAL_NOT_SUPPORTED,
            MMI_EVENT_FAILURE);

        return 0;
    }
#endif /* JPG_ENCODE */

    hjob = cui_bt_printing_launch(mmi_sms_bpp_gid, BT_PRINT_MESSAGE, NULL, 0);
    if (!hjob)
        return 0;
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_PRINT_EMS_1, hjob);

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_bpp_compose_xhtml_file
 * DESCRIPTION
 *  construct bpp xhtml file for the sms/ems print
 * PARAMETERS
 *  handle		[IN]  	BBP Instance handle
 *  pfile_name 	[IN]	the file name of the xhtml to be generated
 *  page_info	[IN]	page information 
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 mmi_msg_bpp_compose_xhtml_file(U32 inst, WCHAR* pfile_name, U32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *pbuf;
    void * xhtml = NULL;
    U32 result = BPP_E_OK;
    xhtml_output_struct out;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	pbuf = (S8*)OslMalloc(MMI_MSG_BPP_BUFF_SIZE);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_XHTML_FILE, inst, pbuf);

	if(pbuf == NULL)
    {
        goto EMS_BPP_ERROR_CLEAN;
    }
    out.type = XHTML_OUT_FILE;
    out.u.file = pfile_name;

    xhtml = bpp_xhtml_open(cui_bt_printing_xhtml_version(inst), &out);
    if (!xhtml)
        goto EMS_BPP_ERROR_CLEAN;

    bpp_xhtml_element_begin(xhtml, XHTML_ELE_HEAD, NULL, 0);

    bpp_xhtml_empty_element(xhtml, XHTML_ELE_TITLE, NULL, 0);

    bpp_xhtml_style_begin(xhtml, NULL);

    if (!cui_bt_printing_style_rules(inst, xhtml))
    {
		MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_XHTML_FILE_1);
        goto EMS_BPP_ERROR_CLEAN;
    }

	if (!mmi_msg_bpp_compose_css_style(inst, xhtml, pbuf))
	{
		MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_XHTML_FILE_2);
		goto EMS_BPP_ERROR_CLEAN;
	}

    bpp_xhtml_style_end(xhtml);
    bpp_xhtml_element_end(xhtml, XHTML_ELE_HEAD);

	
	if (!mmi_msg_bpp_compose_body(xhtml, pbuf))
	{
		MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_XHTML_FILE_3);
		goto EMS_BPP_ERROR_CLEAN;
	}

    *size = bpp_xhtml_close(xhtml);
    xhtml = NULL;

    if (pbuf)
    {
        OslMfree(pbuf);
    }
    
	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_XHTML_FILE_4);
    return BPP_E_OK;

EMS_BPP_ERROR_CLEAN:
    if(pbuf)
    {
        OslMfree(pbuf);
    }
    if (xhtml)
        bpp_xhtml_close(xhtml);
   
    if ((msg_print_data->error_code == MSG_BPP_ERR_FS_DISK_FULL) ||
        (msg_print_data->error_code == MSG_BPP_ERR_FS_ROOT_DIR_FULL))
        result = BPP_E_DISK_FULL;
    else
        result = BPP_E_FAIL;
   
    return result; 
}

#define EmsCount(ele)   sizeof(ele)/sizeof(ele[0])
static const xhtml_prop_struct EmsParaProps[] = 
{
    {XHTML_PROP_FONT_SIZE, "100%"},
    {XHTML_PROP_TEXT_ALIGN, "%s"}
};

static const xhtml_rule_struct EmsParaRule = 
{
    "para_%d", XHTML_ELE_PARA, STYLE_RULE_CLASS, EmsParaProps, EmsCount(EmsParaProps)
};

static const xhtml_prop_struct EmsSpanProps[] = 
{
    {XHTML_PROP_FONT_SIZE,      "%d%%"},
    {XHTML_PROP_FONT_STYLE,     "%s"},
    {XHTML_PROP_FONT_WEIGHT,    "%s"},
    {XHTML_PROP_COLOR,          "%s"},
    {XHTML_PROP_TEXT_DECORATION, "%s"},
};

static const xhtml_rule_struct EmsSpanRule = 
{
    "format_text_%d", XHTML_ELE_SPAN, STYLE_RULE_CLASS, EmsSpanProps, EmsCount(EmsSpanProps)
};

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_bpp_compose_css_style
 * DESCRIPTION
 *  Compose the CSS of the text format
 * PARAMETERS
 *  fh			[IN]	file handle of the xhtml file
 * 	pbuf		[IN]	Buffer for write file  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_msg_bpp_compose_css_style(U32 inst, void *xhtml, CHAR *buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	EMSObject *curr_object = NULL;
	EMSObject *prev_txt_align_obj = NULL;
	CHAR *p_buff = buff;
	U16 format_object_count = 0;
	U16 paragraph_count = 0;
    xhtml_prop_struct para_props[2], span_props[6];
    xhtml_rule_struct para_rule, span_rule;
    U32 count, len;
	MMI_BOOL result = MMI_FALSE;
    enum {para_size, para_align, para_count};
    enum {span_size, span_style, span_weight, span_color, span_text, span_count};

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_CSS_STYLE);

    memcpy(para_props, EmsParaProps, sizeof(EmsParaProps));

	para_rule = EmsParaRule;

    sprintf(p_buff, "para_%d", paragraph_count++);
    para_rule.name = p_buff;
    para_rule.props = para_props;
    para_rule.prop_count = 1;

    bpp_xhtml_style_rule(xhtml, &para_rule, 1);

	curr_object = msg_print_data->ems_data->listHead;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_CSS_STYLE_1, curr_object);

	while (curr_object)
	{
		U8 object_type = curr_object->Type;

    	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_CSS_STYLE_2, object_type);
	
		if (object_type == EMS_TYPE_TEXT_FORMAT)
		{
    		MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_CSS_STYLE_3, curr_object->data->text_format.Alignment);

            if (curr_object->data->text_format.Alignment != EMS_ALIGN_LANG_DEP)
            {
                MMI_BOOL stype_rule1 = MMI_FALSE;
                MMI_BOOL stype_rule2 = MMI_FALSE;
                S8* align_str = NULL;

                if (prev_txt_align_obj == NULL)
                {
                    if (curr_object->OffsetToText > 0)
        			{
                        stype_rule1 = MMI_TRUE;
                    }

                    stype_rule2 = MMI_TRUE;
                }
                else
                {
                    if ((curr_object->data->text_format.Alignment != prev_txt_align_obj->data->text_format.Alignment) ||
                        (curr_object->OffsetToText > (prev_txt_align_obj->OffsetToText + prev_txt_align_obj->data->text_format.textLength)))
                    {
                        if (curr_object->OffsetToText > (prev_txt_align_obj->OffsetToText + prev_txt_align_obj->data->text_format.textLength))
                        {
                            stype_rule1 = MMI_TRUE;
                        }

                        stype_rule2 = MMI_TRUE;
                    }
                }

                if (stype_rule1)
                {
                    sprintf(p_buff, EmsParaRule.name, paragraph_count++);
                    para_rule.name = p_buff;
                    para_rule.prop_count = 1;

                    bpp_xhtml_style_rule(xhtml, &para_rule, 1);
                }

                if (stype_rule2)
                {
                    switch (curr_object->data->text_format.Alignment)
    			    {
    	   			    case EMS_ALIGN_LEFT:
    					    align_str = EMS_BPP_TEXT_ALIGN_LEFT;
    					    break;
    					
    					case EMS_ALIGN_CENTER:
    						align_str = EMS_BPP_TEXT_ALIGN_CENTER;
    						break;
    						
    	   				case EMS_ALIGN_RIGHT:
    						align_str = EMS_BPP_TEXT_ALIGN_RIGHT;
    						break;
    						
    					default:
    						MMI_ASSERT(0);
    						break;
                    }
                    para_props[para_align].value = align_str;

                    sprintf(p_buff, EmsParaRule.name, paragraph_count++);
                    para_rule.name = p_buff;
                    para_rule.prop_count = 2;
                    
                    bpp_xhtml_style_rule(xhtml, &para_rule, 1);
                }

                prev_txt_align_obj = curr_object;
            }

            count = 0;
            p_buff = buff;
            
			if (curr_object->data->text_format.FontSize != EMS_FONTSIZE_NORMAL)
			{
				U8 font_size = 0;
				
				switch (curr_object->data->text_format.FontSize)
				{
					case EMS_FONTSIZE_LARGE:
						font_size = EMS_BPP_TEXT_SIZE_LARGE;
						break;
						
					case EMS_FONTSIZE_SMALL:
						font_size = EMS_BPP_TEXT_SIZE_SMALL;
						break;

					default:
						MMI_ASSERT(0);
						break;
				}
                span_props[count].name = EmsSpanProps[span_size].name;
                len = sprintf(p_buff, EmsSpanProps[span_size].value, font_size);
                span_props[count++].value = p_buff;

                p_buff += len + 1;
			}

			if (curr_object->data->text_format.isBold)
			{
                span_props[count].name = EmsSpanProps[span_weight].name;
                len = sprintf(p_buff, EmsSpanProps[span_weight].value, EMS_BPP_TEXT_STYLE_BOLD);
                span_props[count++].value = p_buff;

                p_buff += len + 1;
			}

			if (curr_object->data->text_format.isItalic)
			{
                span_props[count].name = EmsSpanProps[span_style].name;
                len = sprintf(p_buff, EmsSpanProps[span_style].value, EMS_BPP_TEXT_STYLE_ITALIC);
                span_props[count++].value = p_buff;

                p_buff += len + 1;
			}

			if (curr_object->data->text_format.isUnderline)
			{
                span_props[count].name = EmsSpanProps[span_text].name;
                len = sprintf(p_buff, EmsSpanProps[span_text].value, EMS_BPP_TEXT_STYLE_UNDERLINE);
                span_props[count++].value = p_buff;

                p_buff += len + 1;
			}

			if (curr_object->data->text_format.isStrikethrough)
			{
                span_props[count].name = EmsSpanProps[span_text].name;
                len = sprintf(p_buff, EmsSpanProps[span_text].value, EMS_BPP_TEXT_STYLE_STRIKE_THROUGH);
                span_props[count++].value = p_buff;

                p_buff += len + 1;
			}

            span_rule = EmsSpanRule;
            sprintf(p_buff, EmsSpanRule.name, format_object_count);
            span_rule.name = p_buff;
            span_rule.props = span_props;
            span_rule.prop_count = count;

            bpp_xhtml_style_rule(xhtml, &span_rule, 1);

			format_object_count++;
		}
		
		curr_object = curr_object->next;
	}

    if (prev_txt_align_obj == NULL)
    {
        sprintf(p_buff, EmsParaRule.name, paragraph_count++);
        para_rule.name = p_buff;
        para_rule.prop_count = 1;
        bpp_xhtml_style_rule(xhtml, &para_rule, 1);
    }
    else
    {
        if ((prev_txt_align_obj->OffsetToText + prev_txt_align_obj->data->text_format.textLength) <
            msg_print_data->ems_data->textLength)
        {
            sprintf(p_buff, EmsParaRule.name, paragraph_count++);
            para_rule.name = p_buff;
            para_rule.prop_count = 1;
            bpp_xhtml_style_rule(xhtml, &para_rule, 1);
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_CSS_STYLE_4);

	result = MMI_TRUE;

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_bpp_compose_body
 * DESCRIPTION
 *  Compose the xhtml body
 * PARAMETERS
 *  fh			[IN]	file handle of the xhtml file
 * 	pbuf		[IN]	Buffer for write file  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_msg_bpp_compose_body(void *xhtml, CHAR *buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL result = MMI_FALSE;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_BODY);

	//<body>
	bpp_xhtml_element_begin(xhtml, XHTML_ELE_BODY, NULL, 0);
	
	if (!mmi_msg_bpp_compose_number(xhtml, buff))
	{
	    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_BODY_1);
        goto EMS_BPP_ERROR_CLEAN;
	}

	if (!mmi_msg_bpp_compose_timestamp(xhtml, buff))
	{
    	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_BODY_2);
        goto EMS_BPP_ERROR_CLEAN;
	}

	if (!mmi_msg_bpp_compose_content(xhtml, buff))
	{
       	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_BODY_3);
        goto EMS_BPP_ERROR_CLEAN;
	}

    bpp_xhtml_element_end(xhtml, XHTML_ELE_BODY);
    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_BODY_4);
	
	result = MMI_TRUE;
	
EMS_BPP_ERROR_CLEAN:
	return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_bpp_compose_number
 * DESCRIPTION
 *  Compose the number field
 * PARAMETERS
 *  fh			[IN]	file handle of the xhtml file
 * 	pbuf		[IN]	Buffer for write file   
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_msg_bpp_compose_number(void *xhtml, CHAR *buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 number_field[(MMI_MSG_BPP_MAX_NUMBER_FIELD_LEN * 2) * ENCODING_LENGTH];
    S8 number[(SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
	U16 name[MMI_PHB_NAME_LENGTH + 1];
	U16 number_field_len;
    xhtml_attr_struct attr;
    CHAR *p_buff = buff;
	MMI_BOOL result = MMI_FALSE;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_NUMBER);

    sprintf(p_buff, "para_%d", 0);
    attr.name = XHTML_ATTR_CLASS;
    attr.value = p_buff;

    bpp_xhtml_element_begin(xhtml, XHTML_ELE_PARA, &attr, 1);

	if (msg_print_data->print_ems_type == BPP_PRINT_VIEW_EMS)
	{
		U16 field_name_id;

        if (msg_print_data->is_from == MMI_TRUE)
        {
			field_name_id = STR_ID_SMS_FROM;
        }
        else
        {
			field_name_id = STR_SMS_MESSAGE_HEADER_TO;
        }

		mmi_ucs2cpy(number_field, GetString(field_name_id));

        srv_sms_get_msg_address(msg_print_data->msg_index, number);

	    srv_phb_get_name_by_number((U16*)number, name, MMI_PHB_NAME_LENGTH);
		if (mmi_ucs2strlen((S8*)name))
		{
		    mmi_ucs2cat(number_field, (S8*)name);
		}
		else
		{
		    mmi_ucs2cat(number_field, number);
		}
	}
	else
	{
		mmi_ucs2cpy(number_field, GetString(STR_SMS_MESSAGE_HEADER_TO));
	}

	number_field_len = (U16)(mmi_ucs2strlen(number_field) * ENCODING_LENGTH);
	if (!mmi_msg_bpp_compose_text(xhtml, buff, (WCHAR *)number_field, number_field_len))
	{
    	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_NUMBER_1);
		goto EMS_BPP_ERROR_CLEAN;
	}

    bpp_xhtml_element_end(xhtml, XHTML_ELE_PARA);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_NUMBER_2);

	result = MMI_TRUE;
	
EMS_BPP_ERROR_CLEAN:
	return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_bpp_compose_timestamp
 * DESCRIPTION
 *  Compose the timestamp field
 * PARAMETERS
 *  fh			[IN]	file handle of the xhtml file
 * 	pbuf		[IN]	Buffer for write file
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_msg_bpp_compose_timestamp(void *xhtml, CHAR *buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 timestamp_field[MMI_MSG_BPP_MAX_TIMESTAMP_FIELD_LEN * ENCODING_LENGTH];
	U16 timestamp_field_len;
    xhtml_attr_struct attr;
    CHAR *p_buff = buff;
	MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_TIMESTAMP);

    sprintf(p_buff, "para_%d", 0);

    attr.name = XHTML_ATTR_CLASS;
    attr.value = p_buff;

    bpp_xhtml_element_begin(xhtml, XHTML_ELE_PARA, &attr, 1);

	//Time Field
	mmi_ucs2cpy(timestamp_field, GetString(STR_ID_SMS_BPP_TIME_FIELD));

	if (msg_print_data->print_ems_type == BPP_PRINT_VIEW_EMS)
	{
        S8 ts_date[(MAX_TIMESTAMP_SIZE + 1) * ENCODING_LENGTH];
        S8 ts_time[(MAX_TIMESTAMP_SIZE + 1) * ENCODING_LENGTH];

		mmi_sms_get_msg_date_time(
			msg_print_data->msg_index,
		    ts_date,
		    ts_time);

	    mmi_ucs2cat(timestamp_field, ts_date);		
		mmi_ucs2cat(timestamp_field, (S8*)L" ");
		mmi_ucs2cat(timestamp_field, ts_time);
	}

	timestamp_field_len = (U16)(mmi_ucs2strlen(timestamp_field) * ENCODING_LENGTH);
	if (!mmi_msg_bpp_compose_text(xhtml, p_buff, (WCHAR *)timestamp_field, timestamp_field_len))
	{
		MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_TIMESTAMP_1);
		goto EMS_BPP_ERROR_CLEAN;
	}

    bpp_xhtml_element_end(xhtml, XHTML_ELE_PARA);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_TIMESTAMP_2);
	
	result = MMI_TRUE;
	
EMS_BPP_ERROR_CLEAN:
	return result;
}


#if (!UI_DISABLE_EMS_CATEGORY_SCREENS)
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_bpp_compose_body
 * DESCRIPTION
 *  Compose the content field
 * PARAMETERS
 *  fh			[IN]	file handle of the xhtml file
 * 	pbuf		[IN]	Buffer for write file
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_msg_bpp_compose_content(void *xhtml, CHAR *buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	EMSData *bpp_ems_data = msg_print_data->ems_data;
	EMSObject *curr_object;
	EMSObject *curr_txt_fmt = NULL;
	EMSObject *curr_txt_align = NULL;
	U16 prev_offset = 0;
	U16 curr_offset = 0;
	S16 format_count = -1;
	U16 paragraph_count = 1;
	S8* curr_text;
	U16 curr_text_len = 0;
    xhtml_attr_struct attr;
	MMI_BOOL result = MMI_FALSE;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_CONTENT);

    if (!mmi_msg_bpp_create_folder())
    {
        goto EMS_BPP_ERROR_CLEAN;
    }
    
    attr.name = XHTML_ATTR_CLASS;
    attr.value = buff;

	//<p class = "para_0">
	sprintf(buff, "para_%d", 0);

    bpp_xhtml_element_begin(xhtml, XHTML_ELE_PARA, &attr, 1);

	curr_text = GetString(STR_ID_SMS_BPP_CONTENT_FIELD);
	curr_text_len = mmi_ucs2strlen(curr_text) * ENCODING_LENGTH;
	if (!mmi_msg_bpp_compose_text(xhtml, buff, (WCHAR *)GetString(STR_ID_SMS_BPP_CONTENT_FIELD), curr_text_len))
	{
    	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_CONTENT_1);
		goto EMS_BPP_ERROR_CLEAN;
	}

    bpp_xhtml_element_end(xhtml, XHTML_ELE_PARA);

	//Content
	//<p class = "para_1">
	sprintf(buff, "para_%d", paragraph_count++);
    bpp_xhtml_element_begin(xhtml, XHTML_ELE_PARA, &attr, 1);

	curr_object = bpp_ems_data->listHead;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_CONTENT_2, curr_object);

	while(curr_object)
	{
		U8 object_type = curr_object->Type;

		curr_offset = curr_object->OffsetToText;

		if(curr_offset > prev_offset)
		{
            if (curr_txt_fmt != NULL)
            {
		        U16 txt_fmt_end_offset = curr_txt_fmt->OffsetToText + curr_txt_fmt->data->text_format.textLength;

				//<span class = "format_text_n">
                sprintf(buff, "format_text_%d", format_count);
                bpp_xhtml_element_begin(xhtml, XHTML_ELE_SPAN, &attr, 1);

                if (curr_offset >= txt_fmt_end_offset)
                {
    		        curr_text = (S8*)(bpp_ems_data->textBuffer + prev_offset);
    		        curr_text_len = txt_fmt_end_offset - prev_offset;

                    //formated text
        			if (!mmi_msg_bpp_compose_text(xhtml, buff, (WCHAR *)curr_text, curr_text_len))
        			{
            			MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_CONTENT_3);
        				goto EMS_BPP_ERROR_CLEAN;
        			}

                    bpp_xhtml_element_end(xhtml, XHTML_ELE_SPAN);

    		        curr_text = (S8*)(bpp_ems_data->textBuffer + txt_fmt_end_offset);
                    curr_text_len = curr_offset - txt_fmt_end_offset;

                    curr_txt_fmt = NULL;
                }
                else
                {
		            curr_text = (S8*)(bpp_ems_data->textBuffer + prev_offset);
		            curr_text_len = curr_offset - prev_offset;
                }
            }
            else
            {
		        curr_text = (S8*)(bpp_ems_data->textBuffer + prev_offset);
		        curr_text_len = curr_offset - prev_offset;
            }

            if (curr_txt_align != NULL)
            {
		        U16 txt_align_end_offset = curr_txt_align->OffsetToText + curr_txt_align->data->text_format.textLength;

                if (curr_offset > txt_align_end_offset)
                {
                    bpp_xhtml_element_end(xhtml, XHTML_ELE_PARA);

                    sprintf(buff, "para_%d", paragraph_count++);
                    bpp_xhtml_element_begin(xhtml, XHTML_ELE_PARA, &attr, 1);

                    curr_txt_align = NULL;
                }
            }

			if (!mmi_msg_bpp_compose_text(xhtml, buff, (WCHAR *)curr_text, curr_text_len))
			{
    			MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_CONTENT_3);
				goto EMS_BPP_ERROR_CLEAN;
			}

			if (curr_txt_fmt != NULL)
			{
                bpp_xhtml_element_end(xhtml, XHTML_ELE_SPAN);
			}
        }

		MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_CONTENT_4, object_type);

		switch(object_type)
		{
   			case EMS_TYPE_TEXT_FORMAT:
			{
                MMI_BOOL need_add_para = MMI_FALSE;

                if (curr_object->data->text_format.Alignment != EMS_ALIGN_LANG_DEP)
				{
				    if (curr_txt_align == NULL)
                    {            
                        if (curr_object->OffsetToText > 0)
                        {
                            need_add_para = MMI_TRUE;
                        }
                    }
                    else
                    {
                        if (curr_object->data->text_format.Alignment != curr_txt_align->data->text_format.Alignment)
                        {
                            need_add_para = MMI_TRUE;
                        }
                    }

                    curr_txt_align = curr_object;
                }
                else
                {
                    if (curr_txt_align != NULL)
                    {
                        need_add_para = MMI_TRUE;
                    }

                    curr_txt_align = NULL;
                }

                if (need_add_para == MMI_TRUE)
                {
                    //</p>
                    bpp_xhtml_element_end(xhtml, XHTML_ELE_PARA);

                    //<p class = "para_n">
                    sprintf(buff, "para_%d", paragraph_count++);
                    bpp_xhtml_element_begin(xhtml, XHTML_ELE_PARA, &attr, 1);
                }

                curr_txt_fmt = curr_object;

                //the count number of the first text format is 0;
                format_count++;
			}
			break;
			
   		case EMS_TYPE_PREDEF_SND:
   		case EMS_TYPE_USERDEF_SND:
   		case EMS_TYPE_PREDEF_ANM:
   		case EMS_TYPE_USERDEF_ANM:
   		case EMS_TYPE_PIC:
        {
            EMSObject *temp_obj = bpp_ems_data->listHead;
            MMI_BOOL is_need_gen_pic = MMI_TRUE;
            MMI_BOOL need_add_para = MMI_FALSE;
            U16 object_count = 0;
            
            while (temp_obj != curr_object)
            {
                if (mmi_msg_bpp_check_duplicated_picture(curr_object, temp_obj) == MMI_TRUE)                    
                {
                    is_need_gen_pic = MMI_FALSE;
                    break;
                }

                object_count++;

                temp_obj = temp_obj->next;
            }

            temp_obj = curr_object->next;

            while (temp_obj != NULL && temp_obj->Type != EMS_TYPE_TEXT_FORMAT)
            {
                temp_obj = temp_obj->next;
            }

            if (temp_obj != NULL)
            {
                //First object in a new paragraph
                if ((curr_object->OffsetToText > 0) &&
                    (temp_obj->OffsetToText == curr_object->OffsetToText) &&
                    ((curr_object->prev == NULL) || (curr_object->prev->OffsetToText != curr_object->OffsetToText)))
                {
                    if (curr_txt_align == NULL)
                    {
                        if (temp_obj->data->text_format.Alignment != EMS_ALIGN_LANG_DEP)
                        {
                            need_add_para = MMI_TRUE;
                            curr_txt_align = temp_obj;
                        }
                    }
                    else
                    {
                        if (temp_obj->data->text_format.Alignment != curr_txt_align->data->text_format.Alignment)
                        {
                            need_add_para = MMI_TRUE;
                            curr_txt_align = temp_obj;
                        }
                    }
                }
            }

            if (need_add_para == MMI_TRUE)
            {
                //</p>
                bpp_xhtml_element_end(xhtml, XHTML_ELE_PARA);

                //<p class = "para_n">
                sprintf(buff, "para_%d", paragraph_count++);
                bpp_xhtml_element_begin(xhtml, XHTML_ELE_PARA, &attr, 1);
            }

            if (!mmi_msg_bpp_compose_object(xhtml, buff, curr_object, object_count, is_need_gen_pic))
            {
                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_CONTENT_6);
                goto EMS_BPP_ERROR_CLEAN;
            }
   			break;
   		}

		default:
			break;
		}

		prev_offset = curr_offset;
		curr_object = curr_object->next;
	}

	if (bpp_ems_data->textLength > prev_offset)
    {
        if (curr_txt_fmt != NULL)
        {
	        U16 txt_fmt_end_offset = curr_txt_fmt->OffsetToText + curr_txt_fmt->data->text_format.textLength;

			//<span class = "format_text_n">
			sprintf(buff, "format_text_%d", format_count);
            bpp_xhtml_element_begin(xhtml, XHTML_ELE_SPAN, &attr, 1);

            if (txt_fmt_end_offset <= bpp_ems_data->textLength)
            {
		        curr_text = (S8*)(bpp_ems_data->textBuffer + prev_offset);
		        curr_text_len = txt_fmt_end_offset - prev_offset;

                //formated text
    			if (!mmi_msg_bpp_compose_text(xhtml, buff, (WCHAR *)curr_text, curr_text_len))
    			{
        			MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_CONTENT_3);
    				goto EMS_BPP_ERROR_CLEAN;
    			}

                //</span>
                bpp_xhtml_element_end(xhtml, XHTML_ELE_SPAN);

		        curr_text = (S8*)(bpp_ems_data->textBuffer + txt_fmt_end_offset);
                curr_text_len = bpp_ems_data->textLength - txt_fmt_end_offset;

                curr_txt_fmt = NULL;
            }
            else
            {
            	curr_text = (S8*)(bpp_ems_data->textBuffer + prev_offset);
            	curr_text_len = bpp_ems_data->textLength - prev_offset;
            }
        }
        else
        {
        	curr_text = (S8*)(bpp_ems_data->textBuffer + prev_offset);
        	curr_text_len = bpp_ems_data->textLength - prev_offset;
        }

        if (curr_txt_align != NULL)
        {
	        U16 txt_align_end_offset = curr_txt_align->OffsetToText + curr_txt_align->data->text_format.textLength;

            if (txt_align_end_offset < bpp_ems_data->textLength)
            {
                //</p>
                bpp_xhtml_element_end(xhtml, XHTML_ELE_PARA);

                //<p class = "para_n">
                sprintf(buff, "para_%d", paragraph_count);
                bpp_xhtml_element_begin(xhtml, XHTML_ELE_PARA, &attr, 1);

                curr_txt_align = NULL;
            }
        }

		if (!mmi_msg_bpp_compose_text(xhtml, buff, (WCHAR *)curr_text, curr_text_len))
		{
			MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_CONTENT_3);
			goto EMS_BPP_ERROR_CLEAN;
		}

		if (curr_txt_fmt != NULL)
		{
            bpp_xhtml_element_end(xhtml, XHTML_ELE_SPAN);
		}
    }

    bpp_xhtml_element_end(xhtml, XHTML_ELE_PARA);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_CONTENT_8);

	result = MMI_TRUE;
	
EMS_BPP_ERROR_CLEAN:
	return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_bpp_compose_object
 * DESCRIPTION
 *  Compose the EMS Object except the Format text
 * PARAMETERS
 *  fh			[IN]	file handle of the xhtml file
 * 	pbuf		[IN]	Buffer for write file
 *  object		[IN]	EMS object
 *	oject_count	[IN]	Oject counter
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_msg_bpp_compose_object(void *xhtml, CHAR* buff, EMSObject *object, U16 object_count, MMI_BOOL is_gen_pic)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 jpeg_file_name[(MMI_MSG_BPP_FULL_FILE_NAME_LEN + 1) * ENCODING_LENGTH];
    MMI_BOOL is_pic_exist = MMI_TRUE;
    xhtml_img_attr_struct image;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_OBJECT, object_count);

    mmi_msg_bpp_get_image_file_name(jpeg_file_name, object_count);

    if (is_gen_pic == MMI_TRUE)
    {
        if (mmi_msg_encode_ems_picture_to_jpeg(object, jpeg_file_name) == MMI_FALSE)
        {        
            is_pic_exist = MMI_FALSE;
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_OBJECT_1);
        }
    }

    if (is_pic_exist == MMI_TRUE)
    {
        memset(&image, 0, sizeof(image));
        image.src = (WCHAR *)jpeg_file_name;
        bpp_xhtml_image_element(xhtml, &image);
    }

    return is_pic_exist; 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_encode_ems_picture_to_jpeg
 * DESCRIPTION
 *  Encode the EMS object to JPEG picture file
 * PARAMETERS
 *  object				[IN]	object to be encoded      
 *	jpeg_file_name		[IN]	the file name of the generated JPEG picture
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_msg_encode_ems_picture_to_jpeg(EMSObject *object, S8* jpeg_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT gdi_ret;
	gdi_handle src_layer;
    S32 width;
	S32 height;
    U8 *buf_ptr;
    S32 buf_size;
	U8 object_type = object->Type;
	MMI_BOOL succ = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_ENCODE_EMS_PICTURE_TO_JPEG, object_type);

	switch (object_type)
	{
   		case EMS_TYPE_PREDEF_SND:
		{
			gdi_ret = gdi_image_get_dimension_id(EMS_EDITOR_SOUND_OBJECT_ID, &width, &height);

			if (gdi_ret != GDI_SUCCEED)
			{
				succ = MMI_FALSE;
			}
			break;
   		}
		
   		case EMS_TYPE_USERDEF_SND:
		{
			gdi_ret = gdi_image_get_dimension_id(EMS_EDITOR_MELODY_OBJECT_ID, &width, &height);

			if (gdi_ret != GDI_SUCCEED)
			{
				succ = MMI_FALSE;
			}
			break;
   		}

   		case EMS_TYPE_PREDEF_ANM:
		{
			U16 image_id;

			image_id = mmi_msg_ems_predef_animations[object->PredefNo];

			gdi_ret = gdi_image_get_dimension_id(image_id, &width, &height);

			if (gdi_ret != GDI_SUCCEED)
			{
				succ = MMI_FALSE;
			}
			break;			

		}
			
   		case EMS_TYPE_USERDEF_ANM:
		{
			width = object->data->animation.hDim;
			height = object->data->animation.vDim;
			break;
		}

		case EMS_TYPE_PIC:
		{
			width = object->data->picture.hDim;
			height = object->data->picture.vDim;
			break;
		}

		default:
			MMI_ASSERT(0);
			break;
	}

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_ENCODE_EMS_PICTURE_TO_JPEG_1, succ);

	if (succ == MMI_FALSE)
	{
		return MMI_FALSE;
	}
	
	buf_size = (width* height* GDI_MAINLCD_BIT_PER_PIXEL) >> 3;
	buf_size = ((buf_size + 3) / 4) * 4;

    buf_ptr = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_SMS_BPP, buf_size);
	if (buf_ptr == NULL)
    {
		return MMI_FALSE;
    }
	
	gdi_ret = gdi_layer_create_using_outside_memory(
		0,
		0,
		width,
		height,
		&src_layer,
		(PU8)buf_ptr,
		(S32)buf_size);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_ENCODE_EMS_PICTURE_TO_JPEG_2, gdi_ret);

	if (gdi_ret != GDI_SUCCEED)
	{
        applib_mem_ap_free(buf_ptr);
		return MMI_FALSE;
	}

	gdi_layer_push_and_set_active(src_layer);
	gdi_layer_clear(GDI_COLOR_WHITE);

	succ = MMI_TRUE;

	do
	{
		switch (object_type)
		{
	   		case EMS_TYPE_PREDEF_SND:
			{
				gdi_ret = gdi_image_draw_id(0, 0, EMS_EDITOR_SOUND_OBJECT_ID);

				MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_ENCODE_EMS_PICTURE_TO_JPEG_3, gdi_ret);

				if (GDI_SUCCEED != gdi_ret) 
		        {   
					succ = MMI_FALSE;
				}
				break;
	   		}
			
	   		case EMS_TYPE_USERDEF_SND:
			{
				gdi_ret = gdi_image_draw_id(0, 0, EMS_EDITOR_MELODY_OBJECT_ID);

				MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_ENCODE_EMS_PICTURE_TO_JPEG_4, gdi_ret);

				if (GDI_SUCCEED != gdi_ret) 
		        {   
					succ = MMI_FALSE;
				}
				break;
	   		}

	   		case EMS_TYPE_PREDEF_ANM:
			{
				PU8 image = get_image(mmi_msg_ems_predef_animations[object->PredefNo]);

				//Draw the first frame bitmap of the animation
            	gdi_ret = gdi_image_draw_animation_single_frame(
									0,
									0,
									image,
									0);

				MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_ENCODE_EMS_PICTURE_TO_JPEG_5, gdi_ret);

				if (GDI_SUCCEED != gdi_ret) 
		        {   
					succ = MMI_FALSE;
				}
				
				break;			
			}
				
	   		case EMS_TYPE_USERDEF_ANM:
			{
				S32 src_size = (S32)object->data->animation.pdu_length;

				if (object->data->animation.cFrame > 0)
				{
					src_size = src_size / object->data->animation.cFrame;

				}
				
				//Draw the first frame bitmap of the animation
				mmi_msg_draw_ems_picture(
                        (U8*)object->data->picture.pdu,
                        src_size,
                        object->data->animation.hDim,
                        object->data->animation.vDim,
                        object->data->picture.bitsPerPixel);
				break;
			}

			case EMS_TYPE_PIC:
			{
				mmi_msg_draw_ems_picture(
                        (U8*)object->data->picture.pdu,
                        object->data->picture.pdu_length,
                        object->data->picture.hDim,
                        object->data->picture.vDim,
                        object->data->picture.bitsPerPixel);
				break;
			}

			default:
				MMI_ASSERT(0);
				break;
		}

		if (succ == MMI_FALSE)
		{
			break;
		}

		gdi_ret = gdi_image_encode_layer_to_jpeg(src_layer, (S8*)jpeg_file_name);

    	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_ENCODE_EMS_PICTURE_TO_JPEG_6, gdi_ret);

        switch (gdi_ret)
        {
            case GDI_IMAGE_ENCODER_ERR_ROOT_DIR_FULL:
                msg_print_data->error_code = MSG_BPP_ERR_FS_ROOT_DIR_FULL;
                break;
                
            case GDI_IMAGE_ENCODER_ERR_DISK_FULL:
                msg_print_data->error_code = MSG_BPP_ERR_FS_DISK_FULL;
                break;
        
            default:
                break;  
        }

		if (GDI_SUCCEED != gdi_ret) 
        {   
			succ = MMI_FALSE;
			break;
		}

	} while(0);

	gdi_layer_pop_and_restore_active();

	gdi_layer_free(src_layer);

    applib_mem_ap_free(buf_ptr);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_ENCODE_EMS_PICTURE_TO_JPEG_7, succ);

    if (succ)
    {
        FS_SetAttributes((const WCHAR *)jpeg_file_name, FS_ATTR_HIDDEN);
    }
	
	return succ;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_draw_ems_picture                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
 * DESCRIPTION
 *  draw the EMS picture in the outside_memory
 * PARAMETERS
 *  src					[IN]	Bitmap of the picture
 *  src_size			[IN]    src buffer size
 *  w					[IN]	Width of the picture
 *	h					[IN]	Height of the picture
 *	bits_per_pixel      [IN]	Bits per pixel
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_draw_ems_picture(U8* src, S32 src_size, S32 w, S32 h, S32 bits_per_pixel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	gdi_color palette[64]; // maximum is 64 colors
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_DRAW_EMS_PICTURE);

    switch(bits_per_pixel)
    {
	    case 1:
			palette[0] = gdi_act_color_from_rgb(255,255,255,255); 	// white
			palette[1] = gdi_act_color_from_rgb(255,0,0,0); 		// black
	        break;

	    case 2:
            palette[0] = gdi_act_color_from_rgb(255,0,0,0); 		// black
            palette[1] = gdi_act_color_from_rgb(255,85,85,85); 		// dark grey
            palette[2] = gdi_act_color_from_rgb(255,170,170,170); 	// light grey
            palette[3] = gdi_act_color_from_rgb(255,255,255,255); 	// white
	        break;

	    case 6:
		{
            S32 r, g, b, index;
            const static S32 value[] = {0, 85, 170, 255};

            index = 0;
            for(r = 0; r < 4; r++)
            {
                for(g = 0; g < 4; g++)
                {
					for(b = 0; b < 4; b++, index++)
					{
                        palette[index] = gdi_act_color_from_rgb(255, value[r], value[g], value[b]);
					}
                }
            }
			
	        break;
		}

		default:
	        MMI_ASSERT(0); // strange bits_per_pixel
	        break;
    }

    // check the palette is the same as source key
    {
        MMI_BOOL source_key_enable;
        gdi_color source_key_value;
        int i;
        
        gdi_layer_get_source_key(&source_key_enable, &source_key_value);
        if(source_key_enable)
        {
            for(i = (1 << bits_per_pixel) - 1; i >= 0; i--)
                if(palette[i] == source_key_value)
                    palette[i] = source_key_value ^ 1;
        }
    }
    
    gdi_bits_draw(
        0,
        0,
        src,
        src_size,
        w,
        h,
        bits_per_pixel,
        palette);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_msg_bpp_check_duplicated_picture
 * DESCRIPTION
 *  Check the two object is generated a same picutre
 * PARAMETERS
 *  scr_obj			[IN]	compared object 1
 *	dest_obj		[IN]	compared object 2
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_msg_bpp_check_duplicated_picture(EMSObject *scr_obj, EMSObject *dest_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    MMI_BOOL ret = MMI_FALSE;
    
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_CHECK_DUPLICATED_PICTURE, dest_obj->Type, scr_obj->Type);

    if (dest_obj->Type == scr_obj->Type)
    {
        switch (scr_obj->Type)
        {
            case EMS_TYPE_PREDEF_SND:
            case EMS_TYPE_USERDEF_SND:
                ret = MMI_TRUE;
                break;

            case EMS_TYPE_PREDEF_ANM:
                if (dest_obj->PredefNo == scr_obj->PredefNo)
                {
                    ret = MMI_TRUE;
                }
                break;

            case EMS_TYPE_PIC:
                if ((dest_obj->data->picture.bitsPerPixel == scr_obj->data->picture.bitsPerPixel) &&
                    (dest_obj->data->picture.vDim == scr_obj->data->picture.vDim) &&
                    (dest_obj->data->picture.hDim == scr_obj->data->picture.hDim) &&
                    (dest_obj->data->picture.pdu_length == scr_obj->data->picture.pdu_length))
                {
                    if (memcmp(dest_obj->data->picture.pdu, scr_obj->data->picture.pdu,
                               dest_obj->data->picture.pdu_length) == 0)
                    {
                        ret = MMI_TRUE;
                    }
                }
                break;
                
            case EMS_TYPE_USERDEF_ANM:
                if ((dest_obj->data->animation.bitsPerPixel == scr_obj->data->animation.bitsPerPixel) &&
                    (dest_obj->data->animation.vDim == scr_obj->data->animation.vDim) &&
                    (dest_obj->data->animation.hDim == scr_obj->data->animation.hDim) &&
                    (dest_obj->data->animation.cFrame == scr_obj->data->animation.cFrame) &&
                    (dest_obj->data->animation.cRepeat == scr_obj->data->animation.cRepeat) &&
                    (dest_obj->data->animation.Duration == scr_obj->data->animation.Duration) &&
                    (dest_obj->data->animation.pdu_length == scr_obj->data->animation.pdu_length))

                {
                    if (memcmp(dest_obj->data->animation.pdu, scr_obj->data->animation.pdu,
                               dest_obj->data->animation.pdu_length) == 0)
                    {
                        ret = MMI_TRUE;
                    }
                }
                break;

            default:
                break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_CHECK_DUPLICATED_PICTURE_1, ret);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_bpp_create_folder
 * DESCRIPTION
 *  Create a folder for storing generated ems picture
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_msg_bpp_create_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 folder_name[(MMI_MSG_BPP_FILE_PATH_LEN + 1) * ENCODING_LENGTH];
    FS_HANDLE file_handle;
    MMI_BOOL result = MMI_TRUE;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_msg_bpp_get_folder_name(folder_name);

    file_handle = FS_CreateDir((WCHAR*)folder_name);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_CREATE_FOLDER, file_handle);

    if (file_handle < 0)
    {
        if (file_handle == FS_FILE_EXISTS)
        {
            file_handle = FS_XDelete((WCHAR*)folder_name, 
                              FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, 
                              NULL, 
                              0);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_CREATE_FOLDER_1, file_handle);

            if (file_handle < 0)
            {
                result = MMI_FALSE;
            }
            else
            {
                file_handle = FS_CreateDir((WCHAR*)folder_name);

                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_CREATE_FOLDER_2, file_handle);

                if (file_handle < 0)
                {
                    switch (file_handle)
                    {
                        case FS_ROOT_DIR_FULL:
                            msg_print_data->error_code = MSG_BPP_ERR_FS_ROOT_DIR_FULL;
                            break;
                            
                        case FS_DISK_FULL:
                            msg_print_data->error_code = MSG_BPP_ERR_FS_DISK_FULL;
                            break;

                        default:
                            break;  
                    }

                    result = MMI_FALSE;
                }
                else
                {
                    FS_SetAttributes((WCHAR*)folder_name, FS_ATTR_DIR | FS_ATTR_HIDDEN);
                }
            }
        }
        else
        {
            switch (file_handle)
            {
                case FS_ROOT_DIR_FULL:
                    msg_print_data->error_code = MSG_BPP_ERR_FS_ROOT_DIR_FULL;
                    break;
                    
                case FS_DISK_FULL:
                    msg_print_data->error_code = MSG_BPP_ERR_FS_DISK_FULL;
                    break;

                default:
                    break;  
            }

            result = MMI_FALSE;
        }
    }
    else
    {
        FS_SetAttributes((WCHAR*)folder_name, FS_ATTR_DIR | FS_ATTR_HIDDEN);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_bpp_get_folder_name
 * DESCRIPTION
 *  Get the BPP picture folder
 * PARAMETERS
 *	file_name_buff		[OUT]	the file name buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_bpp_get_folder_name(S8* file_name_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 folder_name[(MMI_MSG_BPP_FILE_PATH_LEN + 1) * ENCODING_LENGTH];
    S32 driveName;
    S8 temp[4];
    S8 ucs2_temp[8];

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    driveName = SRV_FMGR_PUBLIC_DRV;

    if (driveName < 0)
    {
        driveName = SRV_FMGR_SYSTEM_DRV;
    }

    sprintf(temp, "%c:\\", (S8)driveName);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_GET_FOLDER_NAME, (S8)driveName);

    mmi_asc_to_ucs2((S8*)ucs2_temp, temp);
    mmi_ucs2cpy(file_name_buff, ucs2_temp);
    mmi_asc_to_ucs2(folder_name, MMI_MSG_BPP_FOLDER_NAME);
    mmi_ucs2cat(file_name_buff, folder_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_bpp_get_image_file_name
 * DESCRIPTION
 *  Get the generated image's file name
 * PARAMETERS
 *  file_name_buff		[OUT]       File name buffer     
 *	image_count		    [IN]	    image count
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void mmi_msg_bpp_get_image_file_name(S8* file_name_buff, U16 image_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 acs_image_name[MMI_MSG_BPP_FILE_NAME_LEN + 1];
	S8 ucs2_image_name[(MMI_MSG_BPP_FILE_NAME_LEN + 1) * ENCODING_LENGTH];

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	sprintf(acs_image_name, MMI_MSG_BPP_IMAGE_FILE_NAME, image_count);
    mmi_asc_to_ucs2(ucs2_image_name, acs_image_name);

    mmi_msg_bpp_get_folder_name(file_name_buff);
    mmi_ucs2cat(file_name_buff, (S8*)L"\\");
    mmi_ucs2cat(file_name_buff, ucs2_image_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_bpp_print_deinit
 * DESCRIPTION
 *  Deinit the print(Delete the gerenated file and malloc buffer)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_bpp_print_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_PRINT_DEINIT);

	if (msg_print_data != NULL)
	{
        S8 folder_name[(MMI_MSG_BPP_FILE_PATH_LEN + 1) * ENCODING_LENGTH];

        mmi_msg_bpp_get_folder_name(folder_name);

        FS_XDelete((WCHAR*)folder_name, 
            FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, 
            NULL, 
            0);

		OslMfree(msg_print_data);
		msg_print_data = NULL;
	}
}

#else /* (!UI_DISABLE_EMS_CATEGORY_SCREENS) */
/*****************************************************************************
 * FUNCTION
 *  mmi_msg_bpp_compose_content
 * DESCRIPTION
 *  Compose the content field
 * PARAMETERS
 *  fh			[IN]	file handle of the xhtml file
 * 	pbuf		[IN]	Buffer for write file
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_msg_bpp_compose_content(void *xhtml, CHAR *buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	EMSData *print_data = msg_print_data->ems_data;
	S8* curr_text;
	U16 curr_text_len;
	S8 temp[MMI_MSG_BPP_BUFF_SIZE];
	U16 paragraph_count = 0;
    xhtml_attr_struct attr;
	MMI_BOOL ret = MMI_FALSE;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_CONTENT1);

	//<p class = "paragraph_0">
	sprintf(buff, "para_%d", 0);
    attr.name = XHTML_ATTR_CLASS;
    attr.value = buff;

    bpp_xhtml_element_begin(xhtml, XHTML_ELE_PARA, &attr, 1);
    
	curr_text = GetString(STR_ID_SMS_BPP_CONTENT_FIELD);
	curr_text_len = mmi_ucs2strlen(curr_text) * ENCODING_LENGTH;
	if (!mmi_msg_bpp_compose_text(xhtml, buff, (WCHAR *)GetString(STR_ID_SMS_BPP_CONTENT_FIELD), curr_text_len))
	{
    	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_CONTENT1_1);
		goto EMS_BPP_ERROR_CLEAN;
	}

    bpp_xhtml_element_end(xhtml, XHTML_ELE_PARA);	

	//Content
	//<p class = "para_0">
	sprintf(buff, "para_%d", paragraph_count++);
    bpp_xhtml_element_begin(xhtml, XHTML_ELE_PARA, &attr, 1);

	if (!mmi_msg_bpp_compose_text(xhtml, buff, (WCHAR*) print_data->textBuffer, print_data->textLength))
	{
    	MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_CONTENT1_2);
		goto EMS_BPP_ERROR_CLEAN;
	}

	//</p>
	bpp_xhtml_element_end(xhtml, XHTML_ELE_PARA);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_CONTENT1_3);

	ret = MMI_TRUE;
	
EMS_BPP_ERROR_CLEAN:
	return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_bpp_print_deinit
 * DESCRIPTION
 *  Deinit the print(Delete the gerenated file and malloc buffer)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_msg_bpp_print_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_PRINT_DEINIT);

	if (msg_print_data != NULL)
	{
		OslMfree(msg_print_data);
		msg_print_data = NULL;
	}
}

#endif /* (!UI_DISABLE_EMS_CATEGORY_SCREENS) */


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_bpp_compose_text
 * DESCRIPTION
 *  Convert the UCS2 text to UTF-8, and write it in the xhtml file
 * PARAMETERS
 *  fh			[IN]	file handle of the xhtml file
 * 	pbuf		[IN]	Buffer for write file
 *	curr_text	[IN]	UCS2 text
 *	ucs2_len	[IN]    Buffer size of the curr_text
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL mmi_msg_bpp_compose_text(void *xhtml, CHAR * buff, WCHAR *text, U32 text_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *out = buff;
    WCHAR *in = text;
	MMI_BOOL result = MMI_FALSE;
    U32 count, len, i;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_MMI_MSG_BPP_COMPOSE_TEXT, text_len);

    text_len /= 2;

    count = text_len > MMI_MSG_BPP_MAX_ENCODING_CHAR_NUM ? MMI_MSG_BPP_MAX_ENCODING_CHAR_NUM:text_len;
    
    for (i = 0; i < count; i++, in++)
    {
        if (*in != EMS_ESCAPE_CHARACTER)
        {
            len = mmi_chset_ucs2_to_utf8(out, *in);
            out += len;
        }
    }
    *out = '\0';

    bpp_xhtml_element_data(xhtml, buff);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_bpp_app_mem_stop_callback
 * DESCRIPTION
 *  SMS BPP ASM stop callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_bpp_app_mem_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_SMS_BPP, KAL_TRUE);
}
#endif /* __MMI_BPP20_SUPPORT__ */

 
#ifdef __DM_LAWMO_SUPPORT__
/*****************************************************************************
 * FUNCTION
*  mmi_msg_lawmo_proc
* DESCRIPTION
*  callback the result back to LAWMO
* PARAMETERS
*  callback_data
* RETURNS
*  void
*****************************************************************************/
extern mmi_ret mmi_msg_lawmo_proc(mmi_event_struct* event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_lawmo_wipe_ind_evt_struct *lawmo_wipe_ind  = (srv_dm_lawmo_wipe_ind_evt_struct*)event;
    if (lawmo_wipe_ind->cmd == SRV_DM_LAWMO_WIPE_CMD_FINISH)
    {
        g_msg_cntx.msg_class0_ind = MMI_FALSE;//class0 off
        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_1);
    #if (MMI_MAX_SIM_NUM == 2)
        mmi_sms_set_msg_icon(MMI_FALSE, SRV_SMS_SIM_2);
    #endif
    #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
        mmi_msg_update_unsent_icon();
    #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
    }
    return MMI_OK;
}

#endif

#endif /* __MMI_TELEPHONY_SUPPORT__ */

