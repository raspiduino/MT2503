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
 * WlanAppUI.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for WLAN UI.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifdef __TCPIP__
#include "MMI_features.h"
#ifdef __CERTMAN_SUPPORT__
#include "CertManMMIGprots.h"
#endif
#ifdef __MMI_WLAN_FEATURES__
#include "DtcntSrvIprot.h"
#include "mmi_rp_srv_status_icons_def.h"
#include "MMIDataType.h"
#include "DataAccountDef.h"
#include "DataAccountStruct.h"
#include "wndrv_cnst.h"
#include "GlobalResDef.h"
#include "Unicodexdcl.h"
#include "AlertScreen.h"
#include "CustDataRes.h"
#include "mmi_rp_app_dataaccount_def.h"
#include "mmi_frm_events_gprot.h"
#include "stdlib.h"
#include "string.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_history_gprot.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "CommonScreensResDef.h"
#include "gui_data_types.h"
#include "mmi_frm_input_gprot.h"
#include "wgui_categories_popup.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "custom_events_notify.h"
#include "CommonScreens.h"
#include "DataAccountEnum.h"
#include "wgui_categories_text_viewer.h"
#include "gui_inputs.h"
#include "wgui_inputs.h"
#include "wgui_categories.h"
#include "supc_abm_msgs.h"
#include "wndrv_supc_types.h"
#include "DataAccountProt.h"
#include "ImeGprot.h"
#include "stdio.h"
#include "wgui_categories_list.h"
#include "wgui_inline_edit.h"
#include "wgui_categories_inputs.h"
#include "gui_fixed_menuitems.h"
#include "wndrv_api.h"
#include "ModeSwitchSrvGProt.h"
#include "ProfilesSrvGprot.h"
#include "NetSetAppGprot.h"
#include "l4c_nw_cmd.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "app_url.h"
#ifdef __MMI_CCA_SUPPORT__
#include "mmi_rp_app_cca_def.h"
#endif

//remove for option slim
#if 0
#ifndef __OPTR_NONE__
/* under construction !*/
#endif
#endif
/*------------------------------ suggest Add ------------------------------*/
#include "mmi_rp_app_uiframework_def.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"
#include "stack_msgs.h"
#include "stack_config.h"
#include "nvram_common_defs.h"
#include "GpiosrvGprot.h"
#include "TimerEvents.h"
#include "DataAccountCore.h"
#include "FileMgrCUIGProt.h"

/***************************************************************************** 
 * Global variable
 *****************************************************************************/
extern auth_plugin_struct g_wlan_auth_module[];
extern MMI_BOOL is_insert_disconn;

U8 g_dtcnt_is_WEP_key;                      /* for WEP key search & connect query */
U32 modified3 = 0;
MMI_BOOL g_wapi_test_mode = MMI_FALSE;
mmi_id wlan_parent_group_id;
mmi_wlan_display_struct g_wlan_display_context;
supc_abm_bss_info_struct g_cui_hilt_profile;
supc_abm_bss_info_struct g_wlan_hilt_profile;

U8 g_wlan_highlight_index;
mmi_wlan_profile_struct g_wlan_prof_list[MAX_WLAN_DATA_ACCOUNT_NUM];
mmi_wlan_profile_struct *g_wlan_profile[MAX_WLAN_DATA_ACCOUNT_NUM];
srv_dtcnt_prof_wlan_struct g_srv_wlan_prof;
srv_dtcnt_prof_wlan_struct g_wlan_info_prof;
mmi_wlan_profile_struct  g_profile_saved_temp;
mmi_wlan_wizard_list_struct g_wizard_prfile_list[WNDRV_MAX_SCAN_RESULTS_NUM + MAX_WLAN_DATA_ACCOUNT_NUM];
mmi_wlan_wizard_list_struct g_wizard_se_temp_list[WNDRV_MAX_SCAN_RESULTS_NUM];

U8 home_page_temp_buf[MAX_ADDRESS_NAME_LEN * ENCODING_LENGTH];
U8 use_proxy_temp;
U8 proxy_addr_temp[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN * ENCODING_LENGTH];
U8 proxy_port_str_temp[(MMI_DTCNT_MAX_PORT_LENGTH + 1) * ENCODING_LENGTH];
U32 proxy_port_temp;
U8 proxy_user_name_temp[(MAX_USER_LEN + 1) * ENCODING_LENGTH];
U8 proxy_password_temp[(MAX_PASSWD_LEN + 1) * ENCODING_LENGTH];
// WLAN Power Saving Mode
U32 g_wlan_power_save_mode_index = 0;
U32 g_wlan_power_save_mode = 0;
srv_dtcnt_result_enum g_wlan_set_power_mode_state = SRV_DTCNT_RESULT_SUCCESS;


#ifdef __MMI_CCA_SUPPORT__
extern srv_dtcnt_prov_ind_evt_struct g_prov_ind;
U8 cur_wlan_prov_list_index;
#endif
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif


// SECURITY MODE ENUM ARRAY
static const srv_dtcnt_wlan_auth_mode_enum auth_mode_array[SRV_DTCNT_WLAN_AUTH_MODE_TOTAL] = 
{
    SRV_DTCNT_WLAN_AUTH_MODE_OPEN,              /* Open Network */
    SRV_DTCNT_WLAN_AUTH_MODE_WEP,               /* WEP */
#ifndef  WIFI_AUTH_PSK_ONLY
    SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X,         /* IEEE802.1x */
    SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY,          /* WPA Enterprise */
    SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY,         /* WPA2 RSN Enterprise */
    // SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX,      /* WPA WPA2 Mix Enterprise */
#endif  /* WIFI_AUTH_PSK_ONLY */
    SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK,      /* WPA Only PSK */
    SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK,     /* WPA2 Only PSK */
    // SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX_PSK,  /* WPA WPA2 Mix PSK */
#ifdef  __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT,          /* WAPICERT */
    SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK,           /* WAPIPSK */
#endif  /* __MMI_HIDE_WAPI__ */
#endif  /* __WAPI_SUPPORT__ */
};

// EDIT NETWORK INLINE CUI
static const cui_inline_item_caption_struct network_edit_name_caption = {STR_ID_DTCNT_WLAN_NAME};
static const cui_inline_item_fullscreen_edit_struct network_edit_name_full_edit =
{
    0,
    0,
    STR_ID_DTCNT_WLAN_NAME,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_SENTENCE,
    MAX_WLAN_PROF_NAME_LEN,
    NULL
};
static const cui_inline_item_caption_struct network_edit_ssid_caption = {STR_ID_DTCNT_WLAN_SSID};
static const cui_inline_item_fullscreen_edit_struct network_edit_ssid_full_edit =
{
    0,
    0,
    STR_ID_DTCNT_WLAN_SSID,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_ASCII_CHAR,
    SRV_DTCNT_PROF_MAX_SSID_LEN + 1,
    NULL
};
static const cui_inline_item_caption_struct network_edit_network_type_caption = {STR_ID_DTCNT_WLAN_NETWORK_TYPE};
static const cui_inline_item_display_only_struct network_edit_network_type_disp_only = {0};
static const cui_inline_item_caption_struct network_edit_auth_mode_caption = {STR_ID_DTCNT_WLAN_AUTH_MODE};
static const cui_inline_item_display_only_struct network_edit_auth_mode_disp_only = {0};
static const cui_inline_item_display_only_struct network_edit_security_setting_disp_only = {0};
static const cui_inline_item_display_only_struct network_edit_tcpip_setting_disp_only = {STR_ID_DTCNT_WLAN_TCPIP_SETTINGS};
static const cui_inline_item_display_only_struct network_edit_advanced_setting_disp_only = {STR_ID_DTCNT_ADVANCED_SETTING};
static const cui_inline_set_item_struct network_edit_inline_items[WLAN_CUINLINE_NETWORK_EDIT_INLINE_TOTAL] =
{
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_NAME_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (const void*)&network_edit_name_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_NAME, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&network_edit_name_full_edit},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_SSID_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (void*)&network_edit_ssid_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_SSID, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&network_edit_ssid_full_edit},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_NETWORK_TYPE_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, (void*)&network_edit_network_type_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_NETWORK_TYPE, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, (void*)&network_edit_network_type_disp_only},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_AUTH_MODE_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L4, (void*)&network_edit_auth_mode_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_AUTH_MODE, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, (void*)&network_edit_auth_mode_disp_only},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_SECURITY_SETTINGS, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, IMG_GLOBAL_L6, (void*)&network_edit_security_setting_disp_only},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_TCPIP_SETTINGS, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, IMG_GLOBAL_L7, (void*)&network_edit_tcpip_setting_disp_only},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_ADVAN_SETTINGS, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, IMG_GLOBAL_L8, (void*)&network_edit_advanced_setting_disp_only}
};
static const cui_inline_struct g_edit_inline_struct = 
{
    WLAN_CUINLINE_NETWORK_EDIT_INLINE_TOTAL,
    STR_ID_DTCNT_WLAN_NETWORK_SETTING,
    0,
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    network_edit_inline_items
};
// WEP Key Settings Inline CUI
static const cui_inline_item_caption_struct wep_key_id_caption = {STR_ID_DTCNT_WLAN_WEP_KEY_ID};
static const MMI_STR_ID wep_key_index_optional[4] = 
{
    STR_ID_DTCNT_WLAN_WEP_KEY_ID1,
    STR_ID_DTCNT_WLAN_WEP_KEY_ID2,
    STR_ID_DTCNT_WLAN_WEP_KEY_ID3,
    STR_ID_DTCNT_WLAN_WEP_KEY_ID4
};
static const cui_inline_item_select_struct wep_key_id_select = 
    {4, 0, wep_key_index_optional};
static const cui_inline_item_caption_struct wep_key_encrypt_caption = {STR_ID_DTCNT_WLAN_WEP_KEY_ENCRYPT};
static const MMI_STR_ID wep_key_len_optional[WLAN_WEP_KEY_ENCRYPT_TOTAL] = 
    {STR_ID_DTCNT_WLAN_WEP_KEY_ENCRYPT_64, STR_ID_DTCNT_WLAN_WEP_KEY_ENCRYPT_128};
static const cui_inline_item_select_struct wep_key_encrypt_select = 
    {WLAN_WEP_KEY_ENCRYPT_TOTAL, 0, wep_key_len_optional};
static const cui_inline_item_caption_struct wep_key_format_caption = {STR_ID_DTCNT_WLAN_WEP_KEY_FORMAT};
static const MMI_STR_ID wep_key_format_optional[WLAN_WEP_KEY_FORMAT_TOTAL] = 
    {STR_ID_DTCNT_WLAN_WEP_KEY_FORMAT_HEX, STR_ID_DTCNT_WLAN_WEP_KEY_FORMAT_ASCII};
static const cui_inline_item_select_struct wep_key_format_select = 
    {WLAN_WEP_KEY_FORMAT_TOTAL, 0, wep_key_format_optional};
static const cui_inline_item_caption_struct wep_key_caption = {STR_ID_DTCNT_WLAN_WEP_KEY};
static const cui_inline_item_fullscreen_edit_struct wep_key_full_edit = 
{
    0,
    0,
    STR_ID_DTCNT_WLAN_WEP_KEY,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_ASCII_PASSWORD,
    26,
    NULL
};

static const cui_inline_set_item_struct wep_key_inline_items[WLAN_CUINLINE_WEP_EDIT_INLINE_TOTAL] =
{
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY_ID_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (const void*)&wep_key_id_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY_ID, CUI_INLINE_ITEM_TYPE_SELECT, 0, (const void*)&wep_key_id_select},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY_ENCRYPT_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (const void*)&wep_key_encrypt_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY_ENCRYPT, CUI_INLINE_ITEM_TYPE_SELECT, 0, (const void*)&wep_key_encrypt_select},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY_FORMAT_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, (const void*)&wep_key_format_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY_FORMAT, CUI_INLINE_ITEM_TYPE_SELECT, 0, (const void*)&wep_key_format_select},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L4, (const void*)&wep_key_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (const void*)&wep_key_full_edit},
};

static const cui_inline_struct g_wep_key_inline_struct =
{
    WLAN_CUINLINE_WEP_EDIT_INLINE_TOTAL,
        STR_ID_DTCNT_WLAN_WEP_KEY_SETTINGS,
        0,
        CUI_INLINE_SCREEN_LOOP,
        NULL,
        wep_key_inline_items
};
// TCP_IP INLINE CUI
static const cui_inline_item_caption_struct tcpip_use_dhcp_caption = {STR_ID_DTCNT_WLAN_USE_DHCP};
static const MMI_STR_ID use_dhcp_optional[2] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};
static const cui_inline_item_select_struct tcpip_use_dhcp_select = 
{
    2, 0, use_dhcp_optional
};
static const cui_inline_item_caption_struct tcpip_ip_addr_caption = {STR_ID_DTCNT_WLAN_IPADDR};
static const cui_inline_item_ip4_struct tcpip_ip_addr = {0, 0, 0, 0};
static const cui_inline_item_caption_struct tcpip_submask_addr_caption = {STR_ID_DTCNT_WLAN_NETMASK};
static const cui_inline_item_ip4_struct tcpip_submask_addr = {0, 0, 0, 0};
static const cui_inline_item_caption_struct tcpip_gateway_addr_caption = {STR_ID_DTCNT_WLAN_GATEWAY};
static const cui_inline_item_ip4_struct tcpip_gateway_addr = {0, 0, 0, 0};
static const cui_inline_item_caption_struct tcpip_dns1_addr_caption = {STR_ID_DTCNT_WLAN_DNS1};
static const cui_inline_item_ip4_struct tcpip_dns1_addr = {0, 0, 0, 0};
static const cui_inline_item_caption_struct tcpip_dns2_addr_caption = {STR_ID_DTCNT_WLAN_DNS2};
static const cui_inline_item_ip4_struct tcpip_dns2_addr = {0, 0, 0, 0};
static const cui_inline_set_item_struct tcpip_inline_items[WLAN_CUINLINE_TCPIP_INLINE_TOTAL] = 
{
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_USEDHCP_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (void*)&tcpip_use_dhcp_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_USEDHCP, CUI_INLINE_ITEM_TYPE_SELECT, IMG_ID_DTCNT_LSK_EDIT, (void*)&tcpip_use_dhcp_select},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_IPADDR_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (void*)&tcpip_ip_addr_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_IPADDR, CUI_INLINE_ITEM_TYPE_IP4, IMG_ID_DTCNT_LSK_EDIT, (void*)&tcpip_ip_addr},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_NETMASK_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, (void*)&tcpip_submask_addr_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_NETMASK, CUI_INLINE_ITEM_TYPE_IP4, IMG_ID_DTCNT_LSK_EDIT, (void*)&tcpip_submask_addr},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_GATEWAY_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L4, (void*)&tcpip_gateway_addr_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_GATEWAY, CUI_INLINE_ITEM_TYPE_IP4, IMG_ID_DTCNT_LSK_EDIT, (void*)&tcpip_gateway_addr},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_DNS1_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L5, (void*)&tcpip_dns1_addr_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_DNS1, CUI_INLINE_ITEM_TYPE_IP4, IMG_ID_DTCNT_LSK_EDIT, (void*)&tcpip_dns1_addr},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_DNS2_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L6, (void*)&tcpip_dns2_addr_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_DNS2, CUI_INLINE_ITEM_TYPE_IP4, IMG_ID_DTCNT_LSK_EDIT, (void*)&tcpip_dns2_addr}
};
static const cui_inline_struct g_tcpip_inline_struct = 
{
    WLAN_CUINLINE_TCPIP_INLINE_TOTAL,
    STR_ID_DTCNT_WLAN_TCPIP_SETTINGS,
    0,
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    tcpip_inline_items
};
// Advanced setting
static const cui_inline_item_caption_struct advanced_homepage_caption = {STR_ID_DTCNT_HOME_PAGE};
static const cui_inline_item_fullscreen_edit_struct advanced_homepage_fsedit = 
{
    0,
    0,
    STR_ID_DTCNT_HOME_PAGE,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL | INPUT_TYPE_EXT_ASCII_ENCODING_BASE_LENGTH,
    IMM_INPUT_TYPE_URL,
    MAX_ADDRESS_NAME_LEN,
    NULL
};
static const cui_inline_item_caption_struct advanced_use_proxy_caption = {STR_ID_DTCNT_USE_PROXY};
static const MMI_STR_ID use_proxy_optional[2] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};
static const cui_inline_item_select_struct advanced_use_proxy_select =
{
    2, 0, use_proxy_optional
};
static const cui_inline_item_caption_struct advanced_proxy_address_caption = {STR_ID_DTCNT_PROXY_ADDRESS};
static const cui_inline_item_fullscreen_edit_struct advanced_proxy_address = 
{
	0,
	0,
	STR_ID_DTCNT_PROXY_ADDRESS,
	0,
	INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL | INPUT_TYPE_EXT_ASCII_ENCODING_BASE_LENGTH,
	IMM_INPUT_TYPE_URL,
	SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1,
	NULL
};

static const cui_inline_item_caption_struct advanced_proxy_port_caption = {STR_ID_DTCNT_PROXY_PORT};
static const cui_inline_item_text_edit_struct advanced_proxy_port_textedit =
{
    0,
    0,
    MMI_DTCNT_MAX_PORT_LENGTH + 1,
    IMM_INPUT_TYPE_NUMERIC,
    0,
    NULL
};
static const cui_inline_item_caption_struct advanced_proxy_username_caption = {STR_ID_DTCNT_PROXY_USER_NAME};
static const cui_inline_item_fullscreen_edit_struct advanced_proxy_username_fsedit =
{
    0,
    0,
    STR_ID_DTCNT_PROXY_USER_NAME,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_ASCII_CHAR,
    MAX_USER_LEN + 1,
    NULL
};
static const cui_inline_item_caption_struct advanced_proxy_password_caption = {STR_ID_DTCNT_PROXY_PASS_WORD};
static const cui_inline_item_fullscreen_edit_struct advanced_proxy_password_fsedit =
{
    0,
    0,
    STR_ID_DTCNT_PROXY_PASS_WORD,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_ASCII_PASSWORD,
    MAX_PASSWD_LEN + 1,
    NULL
};
static const cui_inline_set_item_struct advanced_inline_items[WLAN_ADVANCED_TOTAL] = 
{
    {WLAN_ADVAN_HOMEPAGE_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (void*)&advanced_homepage_caption},
    {WLAN_ADVAN_HOMEPAGE_FSEDIT_ID, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&advanced_homepage_fsedit},
    {WLAN_ADVAN_USER_PROXY_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (void*)&advanced_use_proxy_caption},
    {WLAN_ADVAN_USER_PROXY_SELECT_ID, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&advanced_use_proxy_select},
    {WLAN_ADVAN_PROXY_ADDR_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, (void*)&advanced_proxy_address_caption},
    {WLAN_ADVAN_PROXY_ADDR_IP4_ID, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&advanced_proxy_address},
    {WLAN_ADVAN_PROXY_PORT_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L4, (void*)&advanced_proxy_port_caption},
    {WLAN_ADVAN_PROXY_PORT_TEXTEDIT_ID, CUI_INLINE_ITEM_TYPE_TEXT_EDIT | CUI_INLINE_ITEM_NO_LEADING_ZERO, 0, (void*)&advanced_proxy_port_textedit},
    {WLAN_ADVAN_PROXY_USERNAME_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L5, (void*)&advanced_proxy_username_caption},
    {WLAN_ADVAN_PROXY_USERNAME_FSEDIT_ID, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&advanced_proxy_username_fsedit},
    {WLAN_ADVAN_PROXY_PASSWD_CAPTION_ID, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L6, (void*)&advanced_proxy_password_caption},
    {WLAN_ADVAN_PROXY_PASSWD_FSEDIT_ID, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&advanced_proxy_password_fsedit}
};
static const cui_inline_struct g_advanced_inline_struct = 
{
    WLAN_ADVANCED_TOTAL,
    STR_ID_DTCNT_ADVANCED_SETTING,
    0,
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    advanced_inline_items
};
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
// WAPI settings inline CUI
static const cui_inline_item_caption_struct wapi_cert_ase_caption = {STR_ID_DTCNT_WLAN_WAPI_ASE_CERT};
static const cui_inline_item_display_only_struct wapi_cert_ase_disp_only = {0};
static const cui_inline_item_caption_struct wapi_cert_user_caption = {STR_ID_DTCNT_WLAN_WAPI_USER_CERT};
static const cui_inline_item_display_only_struct wapi_cert_user_disp_only = {0};
static const cui_inline_item_caption_struct wapi_cert_private_key_caption = {STR_ID_DTCNT_WLAN_WAPI_PRIV_KEY_PASSWD};
static const cui_inline_item_fullscreen_edit_struct wapi_cert_private_key_full_edit =
{
    0,
    0,
    STR_ID_DTCNT_WLAN_WAPI_PRIV_KEY_PASSWD,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD,
    MAX_PASSWORD_LEN,
    NULL
};
static const cui_inline_set_item_struct wapi_cert_inline_items[WLAN_CUINLINE_WAPI_EDIT_INLINE_TOTAL] =
{
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WAPI_EDIT_ASE_CERT_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (void*)&wapi_cert_ase_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WAPI_EDIT_ASE_CERT, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, (void*)&wapi_cert_ase_disp_only},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WAPI_EDIT_USER_CERT_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (void*)&wapi_cert_user_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WAPI_EDIT_USER_CERT, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, (void*)&wapi_cert_user_disp_only},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY_FORMAT_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, (void*)&wapi_cert_private_key_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WAPI_EDIT_PRIV_KEY_PASSWD, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&wapi_cert_private_key_full_edit}
};
static const cui_inline_struct g_wapi_cert_inline_struct =
{
    WLAN_CUINLINE_WAPI_EDIT_INLINE_TOTAL,
        STR_ID_DTCNT_WLAN_WAPI_CERT_SETTINGS,
        0,
        CUI_INLINE_SCREEN_LOOP,
        NULL,
        wapi_cert_inline_items
};
// WAPI Cert. Setting Inline CUI
static const cui_inline_item_caption_struct wapi_psk_format_caption = {STR_ID_DTCNT_WLAN_WAPI_PSK_FORMAT};
static const MMI_STR_ID wapi_psk_format_optional[2] = {STR_ID_DTCNT_WLAN_WEP_KEY_FORMAT_HEX, STR_ID_DTCNT_WLAN_WEP_KEY_FORMAT_ASCII};
static const cui_inline_item_select_struct wapi_psk_format_select = 
{
    WLAN_WEP_KEY_FORMAT_TOTAL, 0, wapi_psk_format_optional
};
static const cui_inline_item_caption_struct wapi_psk_caption = {STR_ID_DTCNT_WLAN_WAPI_PSK};
static const cui_inline_item_fullscreen_edit_struct wapi_psk_full_edit = 
{
    0,
    0,
    STR_ID_DTCNT_WLAN_WAPI_PSK,
    0,
    INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
    IMM_INPUT_TYPE_ASCII_PASSWORD,
    MAX_WAPI_PSK_LEN + 1,
    NULL
};
static const cui_inline_set_item_struct wapi_psk_inline_items[WLAN_CUINLINE_WAPI_PSK_EDIT_INLINE_TOTAL] =
{
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WAPI_PSK_EDIT_KEY_FORMAT_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (void*)&wapi_psk_format_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WAPI_PSK_EDIT_KEY_FORMAT, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&wapi_psk_format_select},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WAPI_PSK_EDIT_KEY_STR, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (void*)&wapi_psk_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WAPI_PSK_EDIT_KEY, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)&wapi_psk_full_edit},
};
static const cui_inline_struct g_wapi_psk_inline_struct = 
{
    WLAN_CUINLINE_WAPI_PSK_EDIT_INLINE_TOTAL,
    STR_ID_DTCNT_WLAN_WAPI_PSK_SETTINGS,
    0,
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    wapi_psk_inline_items
};
#endif /* __MMI_HIDE_WAPI__ */
#endif /* __WAPI_SUPPORT__ */    

// Settings Inline CUI
static const MMI_STR_ID switch_optional[2] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};
static const MMI_STR_ID power_save_optional[3] = {STR_ID_DTCNT_POWER_SAVE_NEVER,
	                                              STR_ID_DTCNT_POWER_SAVE_WHEN_PLUG, 
	                                              STR_ID_DTCNT_POWER_SAVE_WHEN_OFF};

static const cui_inline_item_caption_struct auto_connect_switch_caption = {STR_ID_DTCNT_WLAN_AUTO_CONNECT};
static const cui_inline_item_select_struct auto_connect_switch = {2, 0, switch_optional};

#ifdef __CBM_BEARER_SWITCH__
static const cui_inline_item_caption_struct network_switch_caption = {STR_ID_DTCNT_WLAN_NETWORK_SWITCH};
static const cui_inline_item_select_struct network_switch = {2, 0, switch_optional};
#endif

static const cui_inline_item_caption_struct power_save_caption = {STR_ID_DTCNT_POWER_SAVE_SWITCH};
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
#else
static const cui_inline_item_select_struct power_save_switch = {3, 0, power_save_optional};
#endif

static const cui_inline_set_item_struct wlan_settings_inline_itmes[WLAN_SETTINGS_INLINE_ITEM_TOTAL] = 
{
    {CUI_INLINE_ITEM_ID_BASE + WLAN_SETTINGS_AUTO_CONNECT_CATPION_STR, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&auto_connect_switch_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_SETTINGS_AUTO_CONNECT_SELECTOR, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&auto_connect_switch},
#ifdef __CBM_BEARER_SWITCH__
    {CUI_INLINE_ITEM_ID_BASE + WLAN_SETTINGS_NETWORK_SWITCH_STR, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&network_switch_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_SETTINGS_NETWORK_SWITCH_SELECTOR, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&network_switch},
#endif
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
#endif
#else
    {CUI_INLINE_ITEM_ID_BASE + WLAN_SETTINGS_POWER_SAVE_STR, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&power_save_caption},
    {CUI_INLINE_ITEM_ID_BASE + WLAN_SETTINGS_POWER_SAVE_SELECTOR, CUI_INLINE_ITEM_TYPE_SELECT, 0, (void*)&power_save_switch},	
#endif

};

static const cui_inline_struct g_wlan_settings_inline_struct =
{
    WLAN_SETTINGS_INLINE_ITEM_TOTAL,
    STR_GLOBAL_SETTINGS,
    0,
    CUI_INLINE_SCREEN_LOOP,
    NULL,
    wlan_settings_inline_itmes
};

MMI_ID mmi_wlan_app_launch_func(void* param, U32 param_size)
{
    mmi_wlan_entry_wlan_wizard_new ();

    return wlan_parent_group_id;
}

//remove for option slim
#if 0
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_wlan_wizard_new
 * DESCRIPTION
 *  Common function to display confirmation screem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_wlan_confirm_cb(mmi_alert_result_evt_struct *evt);
void mmi_wlan_entry_wlan_wizard_new(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
    MMI_BOOL is_tethering_switch;
    srv_dtcnt_wlan_state_enum wlan_status;
    mmi_confirm_property_struct popup_property;
    mmi_confirm_property_struct arg;
#endif /* __MTK_TARGET__ */
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
    mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_SUPPORT_AT_PC_SIMULATOR)), MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
    return;
#else /* __MTK_TARGET__ */

    /* to create wlan parent group ID */
    if (mmi_frm_group_is_present(wlan_parent_group_id))
    {
        mmi_frm_group_close(wlan_parent_group_id);
    }

    wlan_parent_group_id = mmi_frm_group_create(
        GRP_ID_ROOT, 
        GRP_ID_AUTO_GEN, 
        mmi_wlan_cui_event_proc, 
        NULL);
    
    mmi_frm_group_enter(wlan_parent_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
     mmi_wlan_set_wapi_test_mode (g_wapi_test_mode);
#endif /* __MMI_HIDE_WAPI__ */    
#endif

#if defined(__FLIGHT_MODE_SUPPORT__) && defined(__MMI_TELEPHONY_SUPPORT__)
//modify for option slim
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#else
	if (srv_mode_switch_is_network_service_available() == MMI_FALSE &&
		SRV_DTCNT_WLAN_STATE_NULL == srv_dtcnt_wlan_state())
	{
		mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
		g_wlan_display_context.confirm_type = 3;

		arg.callback = (mmi_proc_func)mmi_wlan_confirm_cb;
		arg.parent_id = wlan_parent_group_id;

		mmi_confirm_display((WCHAR *)((UI_string_type)GetString(STR_ID_DTCNT_WLAN_OPEN_WLAN_UNDER_FLIGHT)), MMI_EVENT_QUERY, &arg);
		return;
	}

#endif

#endif

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
#endif

    wlan_status = srv_dtcnt_wlan_state();
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_ENTRY_STATUS, wlan_status);

    is_tethering_switch = srv_tethering_is_switching (SRV_TETHERING_TYPE_WIFI_HS);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_IS_TETHERING_IN_SWITCHING, is_tethering_switch);
    if(is_tethering_switch)
    {
        mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE)),
            MMI_EVENT_FAILURE, 
            wlan_parent_group_id, 
            NULL);
        return;
    }
    
    g_wlan_display_context.wizard_profile_changed = MMI_FALSE;
    g_wlan_display_context.sel_eap_peap_auth_type = 0;

    if(MMI_FALSE == srv_tethering_is_off (SRV_TETHERING_TYPE_WIFI_HS))
    {
        mmi_confirm_property_init(&popup_property, CNFM_TYPE_YESNO);
        popup_property.callback = (mmi_proc_func)mmi_wlan_turn_off_hotspot_confirm;
        popup_property.parent_id = wlan_parent_group_id;
        mmi_confirm_display(
            (WCHAR *)((UI_string_type)GetString(STR_ID_DTCNT_WLAN_TURN_OFF_HOTSPOT_CFM)),
            MMI_EVENT_QUERY, 
            &popup_property);
    }
    else
    {
        mmi_wlan_enable_entry_main();
    }
#endif /* __MTK_TARGET__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_enable_entry_main
 * DESCRIPTION
 *  to show the wizard new profile list
 *  
 *  This is used to shows all the related profile list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_enable_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.entry_wizard_new_list = MMI_TRUE;
    mmi_wlan_entry_find_network();
}

mmi_ret mmi_wlan_turn_off_hotspot_confirm(mmi_alert_result_evt_struct *evt)
{
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            mmi_wlan_display_waiting_screen();
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_TURN_OFF_TETHERING);
            srv_tethering_stop (SRV_TETHERING_TYPE_WIFI_HS, mmi_wlan_turn_off_hotspot_callback, NULL);
            break;
        case MMI_ALERT_CNFM_NO:
            mmi_frm_group_close(wlan_parent_group_id);
            break;
        }
    }
    return MMI_RET_OK;
    
}

void mmi_wlan_turn_off_hotspot_callback(srv_tethering_type_enum tethering_type, MMI_BOOL result, void *user_data)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_RECEIVE_TURN_OFF_TETHERING_CB, result);
    if(MMI_TRUE == result)
    {
        mmi_alert_dismiss(g_wlan_display_context.waiting_screen_id);
        mmi_wlan_enable_entry_main();    
    }
    else
    {
        mmi_frm_group_close(wlan_parent_group_id);
    }
}

void mmi_wlan_display_waiting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = wlan_parent_group_id;
    arg.callback = NULL;
    arg.f_enter_history = MMI_TRUE;
    arg.softkey[0].str = 0;
    arg.softkey[1].str = 0;
    arg.softkey[2].str = 0;
    g_wlan_display_context.waiting_screen_id = mmi_confirm_display(
                                        (WCHAR*)GetString(STR_GLOBAL_PLEASE_WAIT),
                                        MMI_EVENT_PROGRESS,
                                        &arg);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_saved_profile_opt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_saved_profile_opt(void)
{
    mmi_id wlan_menu_cui_id;

    if (g_wlan_display_context.prof_num)
    {
        wlan_menu_cui_id = cui_menu_create(
            wlan_parent_group_id, 
            CUI_MENU_SRC_TYPE_RESOURCE, 
            CUI_MENU_TYPE_OPTION, 
            MENU_ID_WLAN_WIZARD_SAVE_LIST_OPT_1, 
            MMI_TRUE, 
            NULL);
    }
    else
    {
        wlan_menu_cui_id = cui_menu_create(
            wlan_parent_group_id, 
            CUI_MENU_SRC_TYPE_RESOURCE, 
            CUI_MENU_TYPE_OPTION, 
            MENU_ID_WLAN_WIZARD_SAVE_LIST_OPT_2, 
            MMI_TRUE, 
            NULL);
    }
    cui_menu_run(wlan_menu_cui_id);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_saved_profile
 * DESCRIPTION
 *  shows the saved profile list
 *  
 *  This is used to shows the saved profile list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_saved_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 *guiBuffer = NULL;
    U8 *DataAccountName[MAX_WLAN_DATA_ACCOUNT_NUM];
    U16 icon_list[MAX_WLAN_DATA_ACCOUNT_NUM];
    U16 icon_state[MAX_WLAN_DATA_ACCOUNT_NUM];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_wlan_display_context.prof_num; i++)
    {
        DataAccountName[i] = g_wlan_profile[i]->name;

        if(g_wlan_profile[i]->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC)
        {
            icon_list[i] = IMG_ID_DTCNT_WLAN_ADHOC;
        }
        else
        {
            if(g_wlan_profile[i]->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN &&
                g_wlan_profile[i]->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE)
            {              
                icon_list[i] = IMG_ID_DTCNT_WLAN_STATION;            
            }
            else
            {
                icon_list[i] = IMG_ID_DTCNT_WLAN_SECURED_STATION;            
            }
        }
        
        if(g_wlan_display_context.connected_wlan_profile &&
           g_wlan_profile[i]->profile_id == g_wlan_display_context.connected_wlan_profile->profile_id)
        {
            if (g_wlan_display_context.rssi > -60)
            {
                icon_state[i] = IMG_ID_DTCNT_WLAN_SIGNAL3;
            }
            else if (g_wlan_display_context.rssi > -70)
            {
                icon_state[i] = IMG_ID_DTCNT_WLAN_SIGNAL2;
            }
            else if (g_wlan_display_context.rssi > -80)
            {
                icon_state[i] = IMG_ID_DTCNT_WLAN_SIGNAL1;
            }
            else
            {
                icon_state[i] = IMG_ID_DTCNT_WLAN_SIGNAL0;
            }
        }
        else 
        {
            icon_state[i] = 0;
        }
    }

    /* Reset insert mode here */
    g_wlan_display_context.insert_mode = FALSE;
    /* Refresh wifi icon in the top bar */
    mmi_wlan_update_status_icon(0, FALSE);
    
    if (!mmi_frm_scrn_enter(
            wlan_parent_group_id,
            SCR_ID_DTCNT_WLAN_WIZARD_SAVED_LIST,
            NULL,
            mmi_wlan_entry_saved_profile,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }


    if (g_wlan_display_context.wizard_profile_changed)
    {
        guiBuffer = NULL;
        g_wlan_display_context.active_wlan_profile_index = 0;
        g_wlan_display_context.wizard_profile_changed = MMI_FALSE;
    }
    else
    {
        guiBuffer = mmi_frm_scrn_get_gui_buf(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WIZARD_SAVED_LIST);
    }
    RegisterHighlightHandler(mmi_wlan_network_settings_highlight_hdlr);

    ShowCategory73Screen(
        STR_ID_DTCNT_WLAN_NETWORK_SETTINGS,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        STR_GLOBAL_OPTIONS,
        IMG_GLOBAL_OPTIONS,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_wlan_display_context.prof_num,
        (U8 **) DataAccountName,
        icon_state,
        icon_list,
        g_wlan_display_context.active_wlan_profile_index,
        guiBuffer,
        ICON_ICON_TEXT);
//#ifndef __MMI_WGUI_DISABLE_CSK__        
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_wlan_entry_network_add, KEY_EVENT_UP);
//#endif
    SetLeftSoftkeyFunction(mmi_wlan_entry_saved_profile_opt, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_network_settings_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_network_settings_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.active_wlan_profile_p = g_wlan_profile[nIndex];
    g_wlan_display_context.active_wlan_profile_index = nIndex;
    g_wlan_display_context.change_priority_profile_p = g_wlan_profile[nIndex];
    g_wlan_display_context.change_priority_profile_index = nIndex;
    
}


//remove for option slim
#if 0
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_new_wizard_list
 * DESCRIPTION
 *  Just test
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_new_wizard_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U8 i, ap_list_num, se_sa_num = 0, se_num = 0, sa_num = 0;
    U8 *guiBuffer = NULL;
    U16 icon_list[WNDRV_MAX_SCAN_RESULTS_NUM + MAX_WLAN_DATA_ACCOUNT_NUM];
    U16 iconStates[WNDRV_MAX_SCAN_RESULTS_NUM + MAX_WLAN_DATA_ACCOUNT_NUM];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wlan_prepare_wizard_list(&se_num, &sa_num, &se_sa_num);
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_SHOW_AP_LIST);
    ap_list_num = se_num + sa_num + se_sa_num;
    for (i = 0; i < ap_list_num; i++)
    {
        memset(subMenuData[i], 0, MAX_SUB_MENU_SIZE);
        switch (g_wizard_prfile_list[i].type)
        {
            case WLAN_MATCH_SE_SA_C:
            case WLAN_MATCH_SE_SA:
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_SHOW_AP_LIST_SE_SA, 
                    mmi_ucs2strlen((const CHAR *)g_wizard_prfile_list[i].p_sa->name), 
                    g_wizard_prfile_list[i].p_sa->profile_id);
                
                mmi_ucs2cpy(
                      (CHAR*)subMenuData[i],
                      (const CHAR*)g_wizard_prfile_list[i].p_sa->name);
                subMenuDataPtrs[i] = subMenuData[i];
                
                switch (g_wizard_prfile_list[i].p_se->network_type)
                {
                    case WNDRV_SUPC_NETWORK_IBSS:
                        icon_list[i] = IMG_ID_DTCNT_WLAN_ADHOC_S;
                        break;
                    default:
                        if (g_wizard_prfile_list[i].p_se->privacy > 0 ||
                            g_wizard_prfile_list[i].p_se->wpa_ie_info_p == KAL_TRUE ||
                            g_wizard_prfile_list[i].p_se->rsn_ie_info_p == KAL_TRUE)
                        {
                            icon_list[i] = IMG_ID_DTCNT_WLAN_SECURED_STATION_S;
                        }
                        else
                        {
                            icon_list[i] = IMG_ID_DTCNT_WLAN_STATION_S;
                        }
                        break;
                }
                if (g_wizard_prfile_list[i].type == WLAN_MATCH_SE_SA)
                {
                    if (g_wizard_prfile_list[i].p_se->rssi > -60)
                    {
                        iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL3;
                    }
                    else if (g_wizard_prfile_list[i].p_se->rssi > -70)
                    {
                        iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL2;
                    }
                    else if (g_wizard_prfile_list[i].p_se->rssi > -80)
                    {
                        iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL1;
                    }
                    else
                    {
                        iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL0;
                    }
                }
                else 
                {
                    if (g_wizard_prfile_list[i].p_se->rssi > -60)
                    {
                        iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL3_CONNECTED;
                    }
                    else if (g_wizard_prfile_list[i].p_se->rssi > -70)
                    {
                        iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL2_CONNECTED;
                    }
                    else if (g_wizard_prfile_list[i].p_se->rssi > -80)
                    {
                        iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL1_CONNECTED;
                    }
                    else
                    {
                        iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL0_CONNECTED;
                    }                    
                }
                break;
            }
            case WLAN_MATCH_SE:
            {
                custom_wlan_ssid_convert(
                        (const char*) g_wizard_prfile_list[i].p_se->ssid, 
                        (char*) subMenuData[i], 
                        g_wizard_prfile_list[i].p_se->ssid_len);
                subMenuDataPtrs[i] = subMenuData[i];
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_SHOW_AP_LIST_SE, 
                    mmi_ucs2strlen((const CHAR *)subMenuData[i]));
                
                switch (g_wizard_prfile_list[i].p_se->network_type)
                {
                    case WNDRV_SUPC_NETWORK_IBSS:
                        icon_list[i] = IMG_ID_DTCNT_WLAN_ADHOC;
                        break;
                    default:
                        if (g_wizard_prfile_list[i].p_se->privacy > 0 ||
                            g_wizard_prfile_list[i].p_se->wpa_ie_info_p == KAL_TRUE ||
                            g_wizard_prfile_list[i].p_se->rsn_ie_info_p == KAL_TRUE)
                        {
                            icon_list[i] = IMG_ID_DTCNT_WLAN_SECURED_STATION;
                        }
                        else
                        {
                            icon_list[i] = IMG_ID_DTCNT_WLAN_STATION;
                        }
                        break;
                }
                if (g_wizard_prfile_list[i].p_se->rssi > -60)
                {
                    iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL3;
                }
                else if (g_wizard_prfile_list[i].p_se->rssi > -70)
                {
                    iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL2;
                }
                else if (g_wizard_prfile_list[i].p_se->rssi > -80)
                {
                    iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL1;
                }
                else
                {
                    iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL0;
                }
                break;
            }
            case WLAN_MATCH_SA:
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_SHOW_AP_LIST_SA, 
                    mmi_ucs2strlen((const CHAR *)g_wizard_prfile_list[i].p_sa->name), 
                    g_wizard_prfile_list[i].p_sa->profile_id);
                
                mmi_ucs2cpy(
                      (CHAR*)subMenuData[i],
                      (const CHAR*)g_wizard_prfile_list[i].p_sa->name);
                subMenuDataPtrs[i] = subMenuData[i];
                
                switch (g_wizard_prfile_list[i].p_sa->network_type)
                {
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
                        icon_list[i] = IMG_ID_DTCNT_WLAN_ADHOC;
                        break;
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
                        if(g_wizard_prfile_list[i].p_sa->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN &&
                           g_wizard_prfile_list[i].p_sa->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE)
                        {
                            icon_list[i] = IMG_ID_DTCNT_WLAN_STATION;
                        }
                        else
                        {
                            icon_list[i] = IMG_ID_DTCNT_WLAN_SECURED_STATION;
                        }
                        break;
                }
                iconStates[i] = 0;
                break;
            }
            case WLAN_MATCH_SA_C:
                {
                mmi_ucs2cpy(
                      (CHAR*)subMenuData[i],
                      (const CHAR*)g_wizard_prfile_list[i].p_sa->name);
                subMenuDataPtrs[i] = subMenuData[i];
                switch (g_wizard_prfile_list[i].p_sa->network_type)
                {
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
                        icon_list[i] = IMG_ID_DTCNT_WLAN_ADHOC_S;
                        break;
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
                        if(g_wizard_prfile_list[i].p_sa->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN &&
                           g_wizard_prfile_list[i].p_sa->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE)
                        {
                            icon_list[i] = IMG_ID_DTCNT_WLAN_STATION_S;
                        }
                        else 
                        {
                            icon_list[i] = IMG_ID_DTCNT_WLAN_SECURED_STATION_S;
                        }
                        break;
                    }
                    iconStates[i] = IMG_ID_DTCNT_WLAN_SIGNAL3_CONNECTED;
                    break;
            } 
        }
 
    }

    if (!mmi_frm_scrn_enter(
            wlan_parent_group_id,
            SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST,
            NULL,
            mmi_wlan_entry_new_wizard_list,
            MMI_FRM_FULL_SCRN))
    {
        return;
    } 

    RegisterHighlightHandler(mmi_wlan_wizard_list_highlight_hdlr);
    if (g_wlan_display_context.wizard_profile_changed)
    {
        guiBuffer = NULL;
        g_wlan_display_context.wizard_cur_profile_list_index = 0;
        g_wlan_display_context.wizard_profile_changed = MMI_FALSE;
    }
    else
    {
        guiBuffer = mmi_frm_scrn_get_gui_buf(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST);
    }

    if (ap_list_num)
    {
        ShowCategory73Screen(
            STR_ID_DTCNT_WLAN_SCAN_RESULT,
            GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            ap_list_num,
            subMenuDataPtrs,
            (U16*) icon_list,
            iconStates,
            g_wlan_display_context.wizard_cur_profile_list_index,
            guiBuffer,
            ICON_TEXT_ICON);
        if (g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE_SA_C ||
            g_wlan_display_context.wizard_list_option == WLAN_MATCH_SA_C)
        {
//#ifndef __MMI_WGUI_DISABLE_CSK__        
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_wlan_entry_network_disconnect, KEY_EVENT_UP);
//#endif            
        }
        else
        {
//#ifndef __MMI_WGUI_DISABLE_CSK__        
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_wlan_entry_wizard_connect, KEY_EVENT_UP);
//#endif            
        }
    }
    else
    {
        ShowCategory73Screen(
            STR_ID_DTCNT_WLAN_SCAN_RESULT,
            GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            ap_list_num,
            subMenuDataPtrs,
            (U16*) icon_list,
            iconStates,
            0,
            guiBuffer,
            ICON_TEXT_ICON);
//#ifndef __MMI_WGUI_DISABLE_CSK__            
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_wlan_entry_network_add, KEY_EVENT_UP);
//#endif        
    }
	if((g_wlan_display_context.send_conn_req_ing != MMI_FALSE ||
	   srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_CONNECT_WAIT ||
	   srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT) &&
	   ( mmi_wlan_get_ui_flow () == MMI_WLAN_UI_CONNECT_BY_CUI ||
	     mmi_wlan_get_ui_flow () == MMI_WLAN_UI_CONNECT_BY_APP ||
	     mmi_wlan_get_ui_flow () == MMI_WLAN_UI_CONNECT_BY_API ))
        {
	    DisableLeftSoftkey(STRING_ID_NULL, IMAGE_ID_NULL);		
//#ifndef __MMI_WGUI_DISABLE_CSK__	    
	    ChangeCenterSoftkey(0, 0);
//#endif	    
        }
        else
        {
	    EnableLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
            SetLeftSoftkeyFunction(mmi_wlan_entry_wizard_list_opt, KEY_EVENT_UP);
        }
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_prepare_wizard_list
 * DESCRIPTION
 *  To prepare data
 * PARAMETERS
 *  se_num
 *  sa_num
 *  se_sa_num
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_prepare_wizard_list(U8 *se_num, U8 *sa_num, U8 *se_sa_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U8 i, j;
    MMI_BOOL is_matched;
    srv_dtcnt_wlan_status_enum wlan_status;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *se_num = 0;
    *sa_num = 0;
    *se_sa_num = 0;

    wlan_status = srv_dtcnt_wlan_status();
    for (i = 0; i < g_wlan_display_context.ap_list_num; i++)
    {
        is_matched = MMI_FALSE;
        bssinfo_to_profile(&g_profile_saved_temp, &g_wlan_display_context.ap_list[i], NULL, 0);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_SEARCH_AP, g_profile_saved_temp.ssid_len);
        for (j = 0; j < g_wlan_display_context.prof_num; j++)
        {
            if ((g_wlan_profile[j]->ssid_len == g_profile_saved_temp.ssid_len) &&
                (strncmp((const char*)g_wlan_profile[j]->ssid, (const char*)g_profile_saved_temp.ssid, g_profile_saved_temp.ssid_len) == 0) &&
                (g_wlan_profile[j]->network_type == g_profile_saved_temp.network_type) &&
                (g_wlan_profile[j]->auth_mode == g_profile_saved_temp.auth_mode) &&
                (g_wlan_profile[j]->encrypt_mode == g_profile_saved_temp.encrypt_mode))
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_SEARCH_AP_FOUND, g_wlan_profile[j]->ssid_len, g_wlan_profile[j]->profile_id);
                g_wizard_prfile_list[*se_sa_num].p_sa = g_wlan_profile[j];
                g_wizard_prfile_list[*se_sa_num].p_se = &g_wlan_display_context.ap_list[i];
                g_wizard_prfile_list[*se_sa_num].type = WLAN_MATCH_SE_SA;
                g_wizard_prfile_list[*se_sa_num].priority = j;
                g_wlan_profile[j]->is_search_matched = MMI_TRUE;
                is_matched = MMI_TRUE;
                if (SRV_DTCNT_WLAN_STATUS_CONNECTED == wlan_status &&
                	g_wlan_display_context.connected_wlan_profile == g_wlan_profile[j]
                	&& is_insert_disconn == MMI_FALSE)
                {
                    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_SEARCH_AP_ACTIVATE);
                	g_wizard_prfile_list[*se_sa_num].type = WLAN_MATCH_SE_SA_C;
                }
                (*se_sa_num)++;
            }
        }
        if (is_matched == MMI_FALSE)
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_SEARCH_AP_NOT_FOUND);
            g_wizard_se_temp_list[*se_num].p_se = &g_wlan_display_context.ap_list[i];
            g_wizard_se_temp_list[*se_num].p_sa = NULL;
            g_wizard_se_temp_list[*se_num].type = WLAN_MATCH_SE;
            g_wizard_se_temp_list[*se_num].priority = MAX_WLAN_DATA_ACCOUNT_NUM + 1;
            (*se_num)++;
        }
    }
    
    memcpy(&g_wizard_prfile_list[*se_sa_num], g_wizard_se_temp_list, (*se_num) * sizeof(mmi_wlan_wizard_list_struct));
    for (i = 0; i < g_wlan_display_context.prof_num; i++)
    {
        if (!g_wlan_profile[i]->is_search_matched)
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_SAVE_AP, g_wlan_profile[i]->ssid_len, g_wlan_profile[i]->profile_id);
            g_wizard_prfile_list[*se_sa_num + *se_num + *sa_num].p_se = NULL;
            g_wizard_prfile_list[*se_sa_num + *se_num + *sa_num].p_sa = g_wlan_profile[i];
            g_wizard_prfile_list[*se_sa_num + *se_num + *sa_num].type = WLAN_MATCH_SA;
            g_wizard_prfile_list[*se_sa_num + *se_num + *sa_num].priority = i;

            if (SRV_DTCNT_WLAN_STATUS_CONNECTED == wlan_status &&
               g_wlan_display_context.connected_wlan_profile == g_wlan_profile[i] &&
               is_insert_disconn == MMI_FALSE)
            {
               g_wizard_prfile_list[*se_sa_num + *se_num + *sa_num].type = WLAN_MATCH_SA_C;
            }
            (*sa_num)++;
        }
        else
        {
            g_wlan_profile[i]->is_search_matched = MMI_FALSE;
        }
    }
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_PREPARE_SPERATOR);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_wizard_list_opt
 * DESCRIPTION
 *  Wizard list option screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_wizard_list_opt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    /* Reset insert mode here */
    g_wlan_display_context.insert_mode = FALSE;
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
#else
		if(0 == g_wlan_display_context.ap_list_num + g_wlan_display_context.prof_num)
		{
			g_wlan_display_context.option_menu_cui_id = 
				cui_menu_create(
					wlan_parent_group_id, 
					CUI_MENU_SRC_TYPE_RESOURCE, 
					CUI_MENU_TYPE_OPTION, 
					MENU_ID_WLAN_WIZARD_LIST_OPT_4, 
					MMI_TRUE,
					NULL);
			
			cui_menu_run(g_wlan_display_context.option_menu_cui_id);
			return;
		}
#endif


    switch(g_wlan_display_context.wizard_list_option)
    {
        case WLAN_MATCH_SE_SA_C:
        case WLAN_MATCH_SA_C:
        {
            g_wlan_display_context.option_menu_cui_id = 
                cui_menu_create(
                    wlan_parent_group_id, 
                    CUI_MENU_SRC_TYPE_RESOURCE, 
                    CUI_MENU_TYPE_OPTION, 
                    MENU_ID_WLAN_WIZARD_LIST_OPT_1, 
                    MMI_TRUE, 
                    NULL);
            break;
        }
        case WLAN_MATCH_SE_SA:
        case WLAN_MATCH_SA:
        {
            g_wlan_display_context.option_menu_cui_id = 
                cui_menu_create(
                    wlan_parent_group_id, 
                    CUI_MENU_SRC_TYPE_RESOURCE, 
                    CUI_MENU_TYPE_OPTION, 
                    MENU_ID_WLAN_WIZARD_LIST_OPT_2, 
                    MMI_TRUE, 
                    NULL);

            break;
        }
        case WLAN_MATCH_SE:
        {
            g_wlan_display_context.option_menu_cui_id = 
                cui_menu_create(
                    wlan_parent_group_id, 
                    CUI_MENU_SRC_TYPE_RESOURCE, 
                    CUI_MENU_TYPE_OPTION, 
                    MENU_ID_WLAN_WIZARD_LIST_OPT_3, 
                    MMI_TRUE, 
                    NULL);

            break;
        }
    }

    cui_menu_run(g_wlan_display_context.option_menu_cui_id);
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wizard_list_highlight_hdlr
 * DESCRIPTION
 *  Wizard profile list highlight handler
 * PARAMETERS
 *  nIndex
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wizard_list_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U8 pos;
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#else
/* under construction !*/
#endif
#else
		pos = (U8)nIndex;
#endif

    g_wlan_display_context.wizard_cur_profile_list_index = nIndex;
    g_wlan_display_context.wizard_list_option = g_wizard_prfile_list[pos].type;
    
    if (g_wlan_display_context.wizard_list_option == WLAN_MATCH_SA || 
        g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE_SA ||
        g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE_SA_C ||
        g_wlan_display_context.wizard_list_option == WLAN_MATCH_SA_C)
    {
        g_wlan_display_context.active_wlan_profile_p = g_wizard_prfile_list[pos].p_sa;
        g_wlan_display_context.active_wlan_profile_index = g_wizard_prfile_list[pos].priority;
    }
    else if (g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE)
    {
        g_wlan_display_context.active_ap = g_wizard_prfile_list[pos].p_se;
    }
    
    if (g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE_SA_C ||
    	g_wlan_display_context.wizard_list_option == WLAN_MATCH_SA_C)
    {
//#ifndef __MMI_WGUI_DISABLE_CSK__
    	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    	SetCenterSoftkeyFunction(mmi_wlan_entry_network_disconnect, KEY_EVENT_UP);
//#endif    	
    }
    else
    {
//#ifndef __MMI_WGUI_DISABLE_CSK__    
    	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    	SetCenterSoftkeyFunction(mmi_wlan_entry_wizard_connect, KEY_EVENT_UP);
//#endif    	
    }

}

/****************************************************************************** 
 * FUNCTION
 *  mmi_wlan_confirm_cb
 * DESCRIPTION
 *  popup confirm callback process.
 * PARAMETERS
 *  evt    [IN]  alert event.
 *  
 * RETURNS
 *  Return MMI_RET_OK on success, otherwise return error code.
 ******************************************************************************/
mmi_ret mmi_wlan_confirm_cb(mmi_alert_result_evt_struct *evt)
{
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_1:
        case MMI_ALERT_CNFM_2:
	    break;
        case MMI_ALERT_CNFM_3:
            // handle softkey event here
            break;
        case MMI_ALERT_CNFM_OK:
            // handle softkey event here
            break;
        case MMI_ALERT_CNFM_YES:
            if (g_wlan_display_context.confirm_type == 1)
            {
                mmi_wlan_network_edit_save_yes();
            }
            else if (g_wlan_display_context.confirm_type == 2)
            {
                mmi_wlan_network_delete_yes();
            }
	    else if (g_wlan_display_context.confirm_type == 3)
            {
                mmi_wlan_enable_entry_main();
            }
            break;

        case MMI_ALERT_CNFM_NO:
            if (g_wlan_display_context.confirm_type == 1)
            {
                mmi_wlan_network_edit_save_no();
            }
            else if (g_wlan_display_context.confirm_type == 2 ||
                     g_wlan_display_context.confirm_type == 3)
            {
                mmi_frm_scrn_close_active_id();
            }
            break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_confirm
 * DESCRIPTION
 *  Common function to display confirmation screem
 * PARAMETERS
 *  msg             [IN]        String index of message to be displayed in confirmation screen
 *  lskFuncPtr      [IN]        LSK handler of the confirmation screen
 *  rskFuncPtr      [IN]        RSK handler of the confirmation screen
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_confirm(U16 msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);

    if (g_wlan_display_context.confirm_type == 2)
    {
        arg.f_auto_map_empty_softkey = 0;   /* deleted */
    }

	arg.callback = (mmi_proc_func)mmi_wlan_confirm_cb;
	arg.parent_id = wlan_parent_group_id;
  
    g_wlan_display_context.delete_confirm_id = mmi_confirm_display((WCHAR *)((UI_string_type)GetString(msg)), MMI_EVENT_QUERY, &arg);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_processing
 * DESCRIPTION
 *  poc registering screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (!mmi_frm_scrn_enter(
            wlan_parent_group_id,
            SCR_ID_DTCNT_WLAN_PROCESSING,
            NULL,
            mmi_wlan_entry_processing,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    ShowCategory66Screen(
        SERVICES_DATA_CONNECT_WLAN_STRING_ID,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        0,
        0,
        0, //STR_GLOBAL_BACK,
        0, //IMG_GLOBAL_BACK,
        (U8*) GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_abortable_processing
 * DESCRIPTION
 *  poc registering screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_abortable_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            wlan_parent_group_id,
            SCR_ID_DTCNT_WLAN_ABORTING,
            NULL,
            mmi_wlan_entry_abortable_processing,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    ShowCategory66Screen(
        SERVICES_DATA_CONNECT_WLAN_STRING_ID,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);

    /* Set RSK to abort searching */
    SetRightSoftkeyFunction(mmi_wlan_action_abort, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_network_disconnect
 * DESCRIPTION
 *  Data account main screen ( including GSM/GPPRS)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_network_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // send disconnect request to DTCNT SRV
    if(g_wlan_display_context.send_conn_req_ing != MMI_FALSE ||
       srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_CONNECT_WAIT ||
       srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT)
	return;
    result = srv_dtcnt_wlan_disconnect();
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_NETWORK_DISCONN, result);
    // show disconnect waiting popup
    mmi_wlan_entry_processing();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_find_network
 * DESCRIPTION
 *  poc registering screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_find_network(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_FALSE == mmi_frm_scrn_is_present(
                        wlan_parent_group_id, 
                        SCR_ID_DTCNT_WLAN_SCAN_PROCESSING, 
                        MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_wlan_send_scan_request(NULL, NULL);
    }
    
    if (!mmi_frm_scrn_enter(
        wlan_parent_group_id,
        SCR_ID_DTCNT_WLAN_SCAN_PROCESSING,
        NULL,
        mmi_wlan_entry_find_network,
        MMI_FRM_FULL_SCRN))
    {
        return;
    }
    
    mmi_frm_scrn_set_leave_proc (
            wlan_parent_group_id, 
            SCR_ID_DTCNT_WLAN_SCAN_PROCESSING, 
            mmi_wlan_searching_scr_leave_proc);

    /* if existed, redraw */

	
#ifndef  WIFI_AUTH_PSK_ONLY
    ShowCategory66Screen(
        STR_ID_DTCNT_WLAN_FIND_NETWORK,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) GetString(STR_GLOBAL_SEARCHING),
        IMG_ID_DTCNT_WLAN_POPUP_SEARCH,
        NULL);
#else

    ShowCategory66Screen(
        STR_ID_DTCNT_WLAN_FIND_NETWORK,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        0,
        0,
        STR_GLOBAL_CANCEL,
        0,
        (U8*) GetString(STR_GLOBAL_SEARCHING),
	mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
#endif

    /* Set RSK to abort searching */
    SetRightSoftkeyFunction(mmi_wlan_action_abort_find_network, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_searching_scr_leave_proc
 * DESCRIPTION
 *  invoked when leave searching screen
 * PARAMETERS
 *  mmi_ret
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_wlan_searching_scr_leave_proc(mmi_event_struct* evt)
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
            break;
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CLOSE_SEARCHING_POPUP_IN_END_KEY, g_wlan_display_context.scan_job_id);
            mmi_wlan_action_abort_find_network();
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_no_auth_settings
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_no_auth_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple(
        (WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_ERROR_NO_AUTH_SETTING)), 
        MMI_EVENT_INFO, 
        wlan_parent_group_id, 
        NULL);
}

MMI_BOOL mmi_wlan_is_empty_string(U8* scr)
{
    U8 i, name_len = 0;
    
    name_len = mmi_ucs2strlen((const CHAR *)scr) * ENCODING_LENGTH;
    if(name_len == 0)
    {
        return MMI_TRUE;
    }
    
    for(i = 0; i < name_len; i+=2)
    {
        if((scr[i] == 0x20) &&(scr[i+1] == 0))
        {
            continue;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_network_edit_save
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_network_edit_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.confirm_type = 1;
    mmi_wlan_entry_confirm(STR_GLOBAL_SAVE_ASK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_conn_status
 * DESCRIPTION
 *  Entry connection status screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_conn_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            wlan_parent_group_id,
            SCR_ID_DTCNT_WLAN_CONN_STATUS,
            NULL,
            mmi_wlan_entry_conn_status,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

	guiBuffer = mmi_frm_scrn_get_gui_buf(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_CONN_STATUS);

    mmi_wlan_update_conn_status_str();

    ShowCategory74Screen(
        STR_ID_DTCNT_WLAN_CONN_STATUS,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) subMenuData,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        guiBuffer);

    wgui_inputs_ml_set_style(0, GUI_MULTI_LINE_INPUT_BOX_DISABLE_CLIPBOARD);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_redraw_network_settings_screen
 * DESCRIPTION
 *  redraw network settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_wlan_redraw_conn_status_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wlan_update_conn_status_str();
    wgui_cat074_change_text((U8*)subMenuData, MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH, MMI_FALSE);
    return;
}

#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wapi_test_mode_switch
 * DESCRIPTION
 *  To enter wapi test mode switch screen
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wapi_test_mode_switch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U8 i = 1;
    U8 *guiBuffer;	
    U16 ShortcutList[1];
    U16 ShortcutStateIcon[1];

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            wlan_parent_group_id,
            SCR_ID_DTCNT_WLAN_WAPI_TEST_MODE_SWITCH,
            NULL,
            mmi_wlan_wapi_test_mode_switch,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }
        
    guiBuffer = GetCurrGuiBuffer(SCR_ID_DTCNT_WLAN_WAPI_TEST_MODE_SWITCH);
		
    if (g_wapi_test_mode == MMI_TRUE)
    {
        ShortcutStateIcon[0] = CHECKBOX_ON_IMAGE_ID;
    }
    else
    {
        ShortcutStateIcon[0] = CHECKBOX_OFF_IMAGE_ID;
    }
	ShortcutList[0] = STR_GLOBAL_ON;

    ShowCategory15Screen(
        STR_GLOBAL_RESET,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        STR_GLOBAL_ADD,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        i,
        ShortcutList,
        (U16*) ShortcutStateIcon,
        LIST_MENU,
        0,
        guiBuffer);
    SetLeftSoftkeyFunction(mmi_wlan_wapi_change_test_mode, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wapi_entry_ASE_cert_list
 * DESCRIPTION
 *  To enter wapi ASE cert. selection screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wapi_entry_ASE_cert_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CERTMAN_SUPPORT__
    SetProtocolEventHandler(mmi_wlan_wapi_select_ase_cert_rsp, MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);
    mmi_certman_select_certificates_ind(
        MOD_MMI, 
        (kal_bool)MMI_CERTMAN_OPEN, 
        KAL_FALSE, 
        0, 
        MMI_CERTMAN_CERT_GROUP_ROOT_CA, 
        MMI_CERTMAN_CERT_TYPE_ALL);
#endif /* __CERTMAN_SUPPORT__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wapi_entry_user_cert_list
 * DESCRIPTION
 *  To enter wapi user cert. selection screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wapi_entry_user_cert_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __CERTMAN_SUPPORT__
    SetProtocolEventHandler(mmi_wlan_wapi_select_user_cert_rsp, MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);

    /* For WAPI new cert API */
    mmi_certman_select_certificates_ind(
        MOD_MMI,
        (kal_bool)MMI_CERTMAN_OPEN, 
        KAL_FALSE, 
        0, 
        MMI_CERTMAN_CERT_GROUP_PERSONAL, 
        MMI_CERTMAN_CERT_TYPE_ALL);
#endif /* __CERTMAN_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_eap_tls_settings_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wapi_cert_edit_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (nIndex == WLAN_WAPI_EDIT_USER_CERT)
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
        SetLeftSoftkeyFunction(mmi_wlan_wapi_entry_user_cert_list, KEY_EVENT_UP);
    }
    else if (nIndex == WLAN_WAPI_EDIT_ASE_CERT)
    {
        ChangeLeftSoftkey(STR_GLOBAL_SELECT, 0);
        SetLeftSoftkeyFunction(mmi_wlan_wapi_entry_ASE_cert_list, KEY_EVENT_UP);
    }
}
#endif /* __MMI_HIDE_WAPI__ */
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    srv_dtcnt_result_enum result;
    srv_dtcnt_store_prof_qry_struct acct_id_query; 
    srv_dtcnt_store_prof_data_struct prof_info;
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#endif
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* first get user defined profile */
    memset(&acct_id_query, 0, sizeof(acct_id_query));

    acct_id_query.qry_info.filters = SRV_DTCNT_STORE_QRY_TYPE_BEARER_TYPE;
    acct_id_query.qry_info.bearer_qry_info = SRV_DTCNT_BEARER_WIFI;
    result = srv_dtcnt_store_qry_ids(&acct_id_query);
    
    if (result == SRV_DTCNT_RESULT_FS_ERROR || acct_id_query.num_ids > SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_INIT_RESULT, result, acct_id_query.num_ids);

    memset(&g_wlan_display_context, 0, sizeof(g_wlan_display_context));

    for (i = 0; i < acct_id_query.num_ids; i++)
    {
        prof_info.prof_type = SRV_DTCNT_BEARER_WIFI;
        prof_info.prof_data = &g_srv_wlan_prof;
        prof_info.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;
		
        result =  srv_dtcnt_store_qry_prof(acct_id_query.ids[i], &prof_info);

        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_INIT_PROFILE, g_srv_wlan_prof.profile_id, g_srv_wlan_prof.priority, i);

        mmi_wlan_srv2app_profile_convert(&g_srv_wlan_prof, &(g_wlan_prof_list[i]), 1);
        if (g_wlan_prof_list[i].priority > 0 && g_wlan_prof_list[i].ssid_len)
        {
            g_wlan_profile[g_wlan_prof_list[i].priority - 1] = &g_wlan_prof_list[i];
            g_wlan_display_context.prof_num++;
            if(g_wlan_prof_list[i].network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
            {
                g_wlan_display_context.infra_prof_num++;
            }
            else
            {
                g_wlan_display_context.adhoc_prof_num++;
            }
        }
        else
        {
            memset(&g_wlan_prof_list[i], 0, sizeof(mmi_wlan_profile_struct));
        }
    }

/* To read WAPI test mode configuration */
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    g_wapi_test_mode = mmi_wlan_get_wapi_test_mode ();
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_WAPI_MODE, g_wapi_test_mode);
#endif /* __MMI_HIDE_WAPI__ */
#endif

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_INIT_NUM, g_wlan_display_context.adhoc_prof_num, g_wlan_display_context.infra_prof_num);

    for (i = g_wlan_display_context.prof_num; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
    {
        g_wlan_profile[i] = NULL;
    }
    mmi_wlan_reg_all_event();
#if 0    
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_WIFI__ */
#endif
    srv_dtcnt_wlan_auto_pw_on();

}


////revise
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_network_delete_yes
 * DESCRIPTION
 *  Proceed saving profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_network_delete_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_status_enum wlan_status;
    mmi_wlan_profile_struct *cur_hilt_profile_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#else
/* under construction !*/
#endif
#else
    cur_hilt_profile_p = g_wlan_display_context.active_wlan_profile_p;
#endif


/* To do verify here*/
    wlan_status = srv_dtcnt_wlan_status();
    if ((wlan_status == SRV_DTCNT_WLAN_STATUS_CONNECTED &&
        cur_hilt_profile_p == g_wlan_display_context.connected_wlan_profile)||
        g_wlan_display_context.send_conn_req_ing == MMI_TRUE ||
        srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_CONNECT_WAIT ||
	srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT)
    {
        if ( mmi_wlan_get_ui_flow () == MMI_WLAN_UI_CONNECT_BY_CUI ||
	         mmi_wlan_get_ui_flow () == MMI_WLAN_UI_CONNECT_BY_APP ||
	         mmi_wlan_get_ui_flow () == MMI_WLAN_UI_CONNECT_BY_API )
        {
        mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_CONNECTING_NO_DEL)), 
            MMI_EVENT_FAILURE, 
            wlan_parent_group_id, 
            NULL);
        return;
    }
    }

    mmi_wlan_delete_profile (cur_hilt_profile_p);
#if 0    
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
#endif
#else
		memset(g_wlan_display_context.active_wlan_profile_p, 0, sizeof(mmi_wlan_profile_struct));
		g_wlan_display_context.active_wlan_profile_p = NULL;
#endif

    g_wlan_display_context.wizard_profile_changed = MMI_TRUE;

    mmi_popup_display_simple(
        (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_DELETED)), 
        MMI_EVENT_SUCCESS, 
        wlan_parent_group_id, 
        NULL);
}

void mmi_wlan_delete_profile(mmi_wlan_profile_struct* profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_result_enum result;
    srv_dtcnt_store_prof_data_struct wlan_prof_data;
    U8  i;
    S32 del_index = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(profile == NULL)
    {
        ASSERT(0);
    }
    
    for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
    {
        if (g_wlan_prof_list[i].priority == profile->priority)
        {
            del_index = i;

            result = srv_dtcnt_store_delete_prof(g_wlan_prof_list[del_index].profile_id, MMI_TRUE, NULL, NULL);

            if (result != SRV_DTCNT_RESULT_SUCCESS)
            {
                ASSERT(0);
            }
        }
    }

    for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
    {
        if (g_wlan_prof_list[i].priority == 0 ||
            g_wlan_prof_list[i].priority < profile->priority)
        {
            continue;
        }

        if (g_wlan_prof_list[i].priority == profile->priority)
        {
            del_index = i;
        }
        else if(g_wlan_prof_list[i].priority > profile->priority)
        {
            g_wlan_prof_list[i].priority--;
            ASSERT(g_wlan_prof_list[i].priority > 0);
            
            mmi_wlan_srv2app_profile_convert(&g_srv_wlan_prof, &(g_wlan_prof_list[i]), 0);
            wlan_prof_data.prof_data = &g_srv_wlan_prof;
            wlan_prof_data.prof_fields = (SRV_DTCNT_WLAN_PROF_FIELD_ALL & (~MMI_WLAN_ADVANCE_FIELD));
            wlan_prof_data.prof_type = SRV_DTCNT_BEARER_WIFI;

            result =  srv_dtcnt_store_update_prof(g_srv_wlan_prof.profile_id, &wlan_prof_data);
            
            if (result != SRV_DTCNT_RESULT_SUCCESS) 
            {
                ASSERT(0);
            }
            g_wlan_profile[g_wlan_prof_list[i].priority - 1] = &g_wlan_prof_list[i];
        }
    }

    if(profile->network_type ==  SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
    {
        g_wlan_display_context.infra_prof_num--;
    }
    else
    {
        g_wlan_display_context.adhoc_prof_num--;
    }
    
    g_wlan_display_context.prof_num--;

    ASSERT(del_index >= 0);
    ASSERT(g_wlan_prof_list[del_index].profile_id == profile->profile_id);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_DELETE_PROF, del_index, g_wlan_prof_list[del_index].profile_id);
    
    memset(&g_wlan_prof_list[del_index], 0, sizeof(mmi_wlan_profile_struct));

}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_network_list_change_priority
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_network_list_change_priority(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 new_priority = g_wlan_display_context.new_priority;
    U8 old_priority = g_wlan_display_context.active_wlan_profile_index + 1;
    srv_dtcnt_result_enum result;
    srv_dtcnt_store_prof_data_struct wlan_prof_data;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CHANGE_PRIO, old_priority, new_priority);

    if (new_priority == old_priority)
    {
		mmi_frm_scrn_multiple_close(wlan_parent_group_id, mmi_frm_scrn_get_active_id(), 1, 0, SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS, 1);

        return;
    }

    ASSERT(new_priority > 0);
    
    for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
    {
        if (g_wlan_prof_list[i].priority == 0)
        {
            continue;
        }

        if (g_wlan_prof_list[i].priority >= new_priority && g_wlan_prof_list[i].priority < old_priority)
        {
            g_wlan_prof_list[i].priority++;
            
            mmi_wlan_srv2app_profile_convert(&g_srv_wlan_prof, &(g_wlan_prof_list[i]), 0);
            wlan_prof_data.prof_data = &g_srv_wlan_prof;
            wlan_prof_data.prof_fields = (SRV_DTCNT_WLAN_PROF_FIELD_ALL & (~MMI_WLAN_ADVANCE_FIELD));
            wlan_prof_data.prof_type = SRV_DTCNT_BEARER_WIFI;

            result =  srv_dtcnt_store_update_prof(g_srv_wlan_prof.profile_id, &wlan_prof_data);
            
            if (result != SRV_DTCNT_RESULT_SUCCESS) 
            {
                ASSERT(0);
            }

        }
        else if (g_wlan_prof_list[i].priority <= new_priority && g_wlan_prof_list[i].priority > old_priority)
        {
            g_wlan_prof_list[i].priority--;

            ASSERT(g_wlan_prof_list[i].priority > 0);
            
            mmi_wlan_srv2app_profile_convert(&g_srv_wlan_prof, &(g_wlan_prof_list[i]), 0);
            wlan_prof_data.prof_data = &g_srv_wlan_prof;
            wlan_prof_data.prof_fields = (SRV_DTCNT_WLAN_PROF_FIELD_ALL & (~MMI_WLAN_ADVANCE_FIELD));
            wlan_prof_data.prof_type = SRV_DTCNT_BEARER_WIFI;

            result =  srv_dtcnt_store_update_prof(g_srv_wlan_prof.profile_id, &wlan_prof_data);
            
            if (result != SRV_DTCNT_RESULT_SUCCESS) 
            {
                ASSERT(0);
            }

        }
        else if (g_wlan_prof_list[i].priority == old_priority)
        {
            mmi_wlan_srv2app_profile_convert(&g_srv_wlan_prof, &(g_wlan_prof_list[i]), 0);
            wlan_prof_data.prof_data = &g_srv_wlan_prof;
            wlan_prof_data.prof_fields = (SRV_DTCNT_WLAN_PROF_FIELD_ALL & (~MMI_WLAN_ADVANCE_FIELD));
            wlan_prof_data.prof_type = SRV_DTCNT_BEARER_WIFI;

            result =  srv_dtcnt_store_update_prof(g_srv_wlan_prof.profile_id, &wlan_prof_data);
            
            if (result != SRV_DTCNT_RESULT_SUCCESS) 
            {
                ASSERT(0);
            }

        }
        g_wlan_profile[g_wlan_prof_list[i].priority - 1] = &g_wlan_prof_list[i];
    }

    g_wlan_display_context.active_wlan_profile_index = new_priority - 1;

    mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, wlan_parent_group_id, NULL);

    mmi_frm_scrn_multiple_close(wlan_parent_group_id, mmi_frm_scrn_get_active_id(), 1, 0, SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS, 1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_network_add
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_change_priority_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 priority;
    U8 network_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    priority = index;
    network_type = g_wlan_profile[g_wlan_display_context.active_wlan_profile_index]->network_type;
    
    if(network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
    {
        if(priority > g_wlan_display_context.infra_prof_num)
        {
            wgui_slide_control_previous();

            mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_CHANGE_INFRA_PRIORITY)), MMI_EVENT_FAILURE, wlan_parent_group_id, NULL);

            return;
        }
    }
    else
    {
        if(priority <= g_wlan_display_context.infra_prof_num)
        {
            wgui_slide_control_next();

            mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_CHANGE_ADHOC_PRIORITY)), MMI_EVENT_FAILURE, wlan_parent_group_id, NULL);

            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_network_add
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_network_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if((g_wlan_display_context.send_conn_req_ing != MMI_FALSE ||
	   srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_CONNECT_WAIT ||
	   srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT) &&
	   ( mmi_wlan_get_ui_flow () == MMI_WLAN_UI_CONNECT_BY_CUI ||
	     mmi_wlan_get_ui_flow () == MMI_WLAN_UI_CONNECT_BY_APP ||
	     mmi_wlan_get_ui_flow () == MMI_WLAN_UI_CONNECT_BY_API ))
	return;
    if (g_wlan_display_context.prof_num == MAX_WLAN_DATA_ACCOUNT_NUM)
    {

        mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_MEMORY_FULL)), 
            MMI_EVENT_FAILURE, 
            wlan_parent_group_id, 
            NULL);
        return;
    }
    
    g_wlan_display_context.insert_mode = TRUE;
    g_wlan_display_context.modified = FALSE;
    g_wlan_display_context.is_to_define_ap = FALSE;
    
    /* Reset temp profile */
    memset(&g_wlan_display_context.temp_profile, 0, sizeof(g_wlan_display_context.temp_profile));
#if 0    
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#else
    g_wlan_display_context.active_wlan_profile_p = &g_wlan_display_context.temp_profile;
    srv_dtcnt_wlan_init_profile(&g_srv_wlan_prof);
    mmi_wlan_srv2app_profile_convert(&g_srv_wlan_prof, g_wlan_display_context.active_wlan_profile_p, 1);
    memset(g_wlan_display_context.active_wlan_profile_p->ssid, 0, SRV_DTCNT_PROF_MAX_SSID_LEN + 1);
    memset(g_wlan_display_context.active_wlan_profile_p->name, 0, MAX_WLAN_PROF_NAME_LEN);
    mmi_wlan_store_curr_ap_into_cntx(g_wlan_display_context.active_wlan_profile_p);
#endif

    

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_network_delete
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_network_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_status_enum wlan_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wlan_status = srv_dtcnt_wlan_status();
#if 0    
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
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
#else
		if (wlan_status == SRV_DTCNT_WLAN_STATUS_CONNECTED &&
			g_wlan_display_context.active_wlan_profile_p == g_wlan_display_context.connected_wlan_profile)
		{
			mmi_popup_display_simple(
				(WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_CONNECTING_NO_DEL)), 
				MMI_EVENT_FAILURE, 
				wlan_parent_group_id, 
				NULL);
			return;
		}
#endif

    g_wlan_display_context.confirm_type = 2;
    mmi_wlan_entry_confirm(STR_ID_DTCNT_WLAN_CLEAR_CONFIRM);
}

MMI_BOOL mmi_wlan_is_same_ap(const mmi_wlan_profile_struct *fst, const mmi_wlan_profile_struct *snd)
{
    if(fst == NULL || snd == NULL)
        return MMI_FALSE;
    
    if ((fst->ssid_len == snd->ssid_len) &&
        (strncmp((const char*)fst->ssid, (const char*)snd->ssid, snd->ssid_len) == 0) &&
        (fst->network_type == snd->network_type) &&
        (fst->auth_mode == snd->auth_mode) &&
        (fst->encrypt_mode == snd->encrypt_mode))
        return MMI_TRUE;
    else
        return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  bssinfo_to_profile
 * DESCRIPTION
 *  convert supc info to wlan app.
 * PARAMETERS
 *  prof            [OUT]        wlan profile 
 *  bssinfo         [IN]         supc info
 *  passphrase      [IN]         passphrase
 *  keylen          [IN]         key length
 * RETURNS
 *  void
 *****************************************************************************/
void bssinfo_to_profile(mmi_wlan_profile_struct *prof, const supc_abm_bss_info_struct *bssinfo, const char *passphrase, int keylen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_init_profile(&g_srv_wlan_prof);
    mmi_wlan_srv2app_profile_convert(&g_srv_wlan_prof, prof, 1);
    mmi_wlan_init_profile_by_bss_info (prof, bssinfo, passphrase, keylen);
}

void mmi_wlan_fill_profile_auth_settings(
    const U32 ie_info_type,                                 /* 0: rsn_ie_info_p(WPA2) 1: wpa_ie_info_p(WPA) */
    const char *passphrase, 
    int keylen,
    const supc_ie_info_struct* supc_ie_info, 
    mmi_wlan_profile_struct*   profile)
{
    // Auth. Mode
    if((supc_ie_info->key_mgmt & WPA_KEY_MGMT_PSK) ||
       (supc_ie_info->key_mgmt & MMI_WLAN_WPA_KEY_MGMT_WPA_NONE))
    {
        if(0 == ie_info_type)
        {
            profile->auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK;
        }
        else if(1 == ie_info_type)
        {
            profile->auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK;
        }
    }
    else if (supc_ie_info->key_mgmt & WPA_KEY_MGMT_IEEE8021X)
    {
        if(0 == ie_info_type)
        {
            profile->auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY;
        }
        else if(1 == ie_info_type)
        {
            profile->auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY;
        }
    }
	if (profile->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC &&
		     supc_ie_info->key_mgmt & WPA_KEY_MGMT_PSK)
	{
	    profile->auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_TOTAL;
	}

    // Encrypt Mode
    if (profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY ||
		profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK)
    {
        profile->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP;
    }
	else if (profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY ||
		profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK)
    {
        profile->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_AES;
    }

    if (passphrase != NULL)
    {
        memcpy (profile->passphrase, passphrase, 64);
        if(keylen == 64)
        {
            mmi_wlan_hex_to_string(profile->psk, (U8 *)passphrase, 64);
        }
    }
}

void mmi_wlan_init_profile_by_bss_info(
    mmi_wlan_profile_struct  *profile, 
    const supc_abm_bss_info_struct *bssinfo, 
    const char *passphrase, 
    int keylen)
{
    // SSID
    profile->ssid_len = (U8)bssinfo->ssid_len;
    memcpy(profile->ssid, bssinfo->ssid, bssinfo->ssid_len);
    profile->passphrase_len = keylen;
    
    // Name
    memset(profile->name, 0, (SRV_DTCNT_PROF_MAX_WLAN_PROF_NAME_LEN + 1) * ENCODING_LENGTH);
    custom_wlan_ssid_convert(
        (const char*) bssinfo->ssid, 
        (char*) profile->name, 
        bssinfo->ssid_len);
    
    profile->use_dhcp = TRUE;                       // Use DHCP 
    profile->channel = bssinfo->channel_number;     // Channel number
    
    // Network Type
    switch (bssinfo->network_type)
    {
        case WNDRV_SUPC_NETWORK_AUTO_UNKNOWN:
            profile->network_type = SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA;
            break;
        case WNDRV_SUPC_NETWORK_IBSS:
            profile->network_type = SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC;
            break;
        case WNDRV_SUPC_NETWORK_INFRASTRUCTURE:
            profile->network_type = SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA;
            break;
    }

    if (bssinfo->rsn_ie_info_p == TRUE)
    {
        mmi_wlan_fill_profile_auth_settings (
            0, 
            passphrase, 
            keylen, 
            &bssinfo->rsn_ie_info, 
            profile);
    }
    else if (bssinfo->wpa_ie_info_p == TRUE)
    {
        mmi_wlan_fill_profile_auth_settings (
            1, 
            passphrase, 
            keylen, 
            &bssinfo->wpa_ie_info, 
            profile);
    }
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    else if (bssinfo->wapi_ie_info_p == TRUE)
    {
        // Auth. Mode & WAPI settings
        if(bssinfo->network_type == WNDRV_SUPC_NETWORK_INFRASTRUCTURE)
        {
            if (bssinfo->wapi_ie_info.key_mgmt & WAPI_KEY_MGMT_PSK)
            {
                profile->auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK;
                if (passphrase)
                {
                    profile->wapi_psk_format = keylen;
                    strcpy((char*)profile->wapi_psk_str, passphrase);
                }
            }
            else if (bssinfo->wapi_ie_info.key_mgmt & MMI_WLAN_WAPI_KEY_MGMT_WAI)
            {
                profile->auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT;
                if (passphrase)
                {
                    profile->wapi_ase_id = g_wlan_display_context.wapi_ase_id;
                    profile->wapi_client_id = g_wlan_display_context.wapi_client_id;
                    strcpy((char*)profile->wapi_private_key_passwd_str, passphrase);
                }
            }
        }
        // Encrypt Mode
        if (bssinfo->wapi_ie_info.group_cipher & MMI_WLAN_WAPI_CIPHER_SMS4 ||
            bssinfo->wapi_ie_info.pairwise_cipher & MMI_WLAN_WAPI_CIPHER_SMS4)
        {
            profile->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_WPI;
        }
    }
#endif /* __MMI_HIDE_WAPI__ */
#endif
    else if (bssinfo->privacy > 0)
    {
        profile->auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WEP;
        profile->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP;
        if (passphrase == NULL)
        {
            return;
        }

        switch (keylen)
        {
            case 5:
                profile->wep_key_len = WLAN_WEP_KEY_ENCRYPT_64;
                profile->wep_key_format = WLAN_WEP_KEY_FORMAT_ASCII;
                memcpy(profile->wep_key, passphrase, 5);
                break;
            case 10:
                profile->wep_key_len = WLAN_WEP_KEY_ENCRYPT_64;
                profile->wep_key_format = WLAN_WEP_KEY_FORMAT_HEX;
                memcpy(profile->wep_key, passphrase, 10);
                break;
            case 13:
                profile->wep_key_len = WLAN_WEP_KEY_ENCRYPT_128;
                profile->wep_key_format = WLAN_WEP_KEY_FORMAT_ASCII;
                memcpy(profile->wep_key, passphrase, 13);
                break;
            case 26:
                profile->wep_key_len = WLAN_WEP_KEY_ENCRYPT_128;
                profile->wep_key_format = WLAN_WEP_KEY_FORMAT_HEX;
                memcpy(profile->wep_key, passphrase, 26);
                break;
            case 0:
                break;
            default:
                ASSERT(0);
                break;
        }
        }
	else if (bssinfo->privacy == 0)
        {
            profile->auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_OPEN;
        
        if (passphrase == NULL)
        {
            return;
        }
    }
    else
    {
        profile->auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_OPEN;
        profile->encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_is_profile_matched_searched
 * DESCRIPTION
 *
 * PARAMETERS
 *  searched
 *  saved
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_wlan_is_profile_matched_searched(supc_abm_bss_info_struct *searched, mmi_wlan_profile_struct *saved)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    MMI_BOOL searched_result = MMI_FALSE;
    srv_dtcnt_wlan_status_enum wlan_status;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wlan_status = srv_dtcnt_wlan_status();

    bssinfo_to_profile(saved, searched, NULL, 0);
    for (i = 0; i < g_wlan_display_context.prof_num; i++)
    {
        if ((g_wlan_profile[i]->ssid_len == saved->ssid_len) &&
            (strncmp((const char*)g_wlan_profile[i]->ssid, (const char*)saved->ssid, saved->ssid_len) == 0) &&
            (g_wlan_profile[i]->network_type == saved->network_type) &&
            (g_wlan_profile[i]->auth_mode == saved->auth_mode) &&
            (g_wlan_profile[i]->encrypt_mode == saved->encrypt_mode))
        {
            memcpy(saved, g_wlan_profile[i], sizeof(mmi_wlan_profile_struct));
            searched_result = MMI_TRUE;
            g_wlan_profile[i]->is_search_matched = MMI_TRUE;
            if (SRV_DTCNT_WLAN_STATUS_CONNECTED == wlan_status &&
            	g_wlan_display_context.connected_wlan_profile == g_wlan_profile[i])
            {
                g_wlan_profile[i]->is_connected = MMI_TRUE;
            }
        }
        else
        {
            g_wlan_profile[i]->is_connected = MMI_FALSE;
        }
    }
  
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_PROF_MATCH, wlan_status, searched_result);

    return searched_result;    
}


////revise
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_action_abort
 * DESCRIPTION
 *  poc registering screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_action_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_result_enum retn;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.search_connect_need_save = MMI_FALSE;
    
    retn = srv_dtcnt_wlan_disconnect();
	g_wlan_display_context.send_conn_req_ing = MMI_FALSE;
#if 0	
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
#else
		mmi_wlan_set_ui_flow(MMI_WLAN_UI_ABORT_CONNECT);	   // Increase count of abort action
#endif


    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONNECT_ABORT, g_wlan_display_context.ui_flow);

    /* if add disconnect action into list, set connected ap as NULL */
    if(SRV_DTCNT_RESULT_PROCESSING == retn)
    {
        mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_DISCONNECT, FALSE);
    
        g_wlan_display_context.wizard_profile_changed = MMI_TRUE;
        g_wlan_display_context.connected_wlan_profile = NULL;
        g_wlan_display_context.ssid_len = 0;
        memset(g_wlan_display_context.ssid, 0, SRV_DTCNT_PROF_MAX_SSID_LEN + 1);
        memset(g_wlan_display_context.bssid, 0, MAX_MAC_ADDR_LEN);
    }
        
    mmi_ime_delete_editor_common_scr(SCR_ID_DTCNT_WLAN_PASSPHRASE_INPUT);
    mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_PASSPHRASE_INPUT);
    mmi_ime_delete_editor_common_scr(SCR_ID_DTCNT_WLAN_PASSPHRASE_INPUT_OPT);
    mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_PASSPHRASE_INPUT_OPT);	
    mmi_ime_delete_editor_common_scr(SCR_ID_DTCNT_WLAN_WIZARD_EAP_INPUT);
    mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WIZARD_EAP_INPUT);

    if (mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_ABORTING)
    {
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_ABORTING);
    }

    g_wlan_display_context.passphrase_str[0] = 0;
    g_wlan_display_context.passphrase_str[1] = 0;
}


////revise
void mmi_wlan_invalid_passphrase_popup(U16 prompt)
{
    mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(prompt)), 
            MMI_EVENT_FAILURE, 
            wlan_parent_group_id, 
            NULL);
    mmi_ime_delete_editor_common_scr(SCR_ID_DTCNT_WLAN_PASSPHRASE_INPUT_OPT);
    mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_PASSPHRASE_INPUT_OPT);
    mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WIZARD_EAP_INPUT);
    g_wlan_display_context.is_key_input_invalid = 1;
    
    g_wlan_display_context.passphrase_str[0] = 0;
    g_wlan_display_context.passphrase_str[1] = 0;
}


//remove for option slim
#if 0
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_wizard_connect
 * DESCRIPTION
 *  Connect to network
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_wizard_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_wlan_profile_struct *prof;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.pre_connect_by_always_ask = MMI_FALSE;
	if((g_wlan_display_context.send_conn_req_ing != MMI_FALSE ||
	   srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_CONNECT_WAIT ||
	   srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT) &&
	   ( mmi_wlan_get_ui_flow () == MMI_WLAN_UI_CONNECT_BY_CUI ||
	     mmi_wlan_get_ui_flow () == MMI_WLAN_UI_CONNECT_BY_APP ||
	     mmi_wlan_get_ui_flow () == MMI_WLAN_UI_CONNECT_BY_API ))
    {
	cui_inline_close(g_wlan_display_context.inline_find_ap);
	mmi_popup_display_simple(
                    (WCHAR*)GetString(STR_ID_DTCNT_WLAN_ERROR_CONNECT_FAIL),
                    MMI_EVENT_FAILURE,
                    wlan_parent_group_id,
                    NULL);
	return;
    }
    if (g_wlan_display_context.wizard_list_option == WLAN_MATCH_SA || 
        g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE_SA ||
        g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE_SA_C ||
        g_wlan_display_context.wizard_list_option == WLAN_MATCH_SA_C)

    {
        mmi_wlan_entry_abortable_processing();
        g_wlan_display_context.search_connect_need_save = MMI_FALSE;

        prof = g_wlan_display_context.active_wlan_profile_p;
        prof->always_ask_connect_flag = MMI_FALSE;
        prof->always_ask_before_connect_flag = MMI_FALSE;

        mmi_wlan_send_connect_request(g_wlan_display_context.active_wlan_profile_p);

        if(!prof->use_dhcp)
        {        
            memcpy(g_wlan_display_context.curr_ip_addr, prof->ip_addr, 4);
            memcpy(g_wlan_display_context.curr_netmask, prof->netmask, 4);
            memcpy(g_wlan_display_context.curr_gateway, prof->gateway, 4);
            memcpy(g_wlan_display_context.curr_dns1, prof->dns1, 4);
            memcpy(g_wlan_display_context.curr_dns2, prof->dns2, 4);
        }
    }
    else if (g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE)
    {
        mmi_wlan_pre_entry_find_network_connect();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_find_network_connect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  int(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_find_network_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char buf[SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1] = "";
    char passphrase[SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1] = "";
    int keylen = 0;
    MMI_BOOL is_valid = MMI_TRUE;
    mmi_wlan_profile_struct *prof;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((CHAR*)buf, (CHAR*)g_wlan_display_context.passphrase_str);
    g_wlan_display_context.pass_len = strlen(buf);

    if ((g_wlan_hilt_profile.rsn_ie_info_p == KAL_TRUE && 
         g_wlan_hilt_profile.rsn_ie_info.key_mgmt & MMI_WLAN_WPA_KEY_MGMT_PSK) ||
        (g_wlan_hilt_profile.wpa_ie_info_p == KAL_TRUE && 
         g_wlan_hilt_profile.wpa_ie_info.key_mgmt & MMI_WLAN_WPA_KEY_MGMT_PSK) ||
         (g_wlan_hilt_profile.wpa_ie_info_p == KAL_TRUE && 
         g_wlan_hilt_profile.wpa_ie_info.key_mgmt & MMI_WLAN_WPA_KEY_MGMT_WPA_NONE))
    {
        if (strlen(buf) < 8)
        {
            mmi_wlan_invalid_passphrase_popup(STR_ID_DTCNT_WLAN_ERROR_INVALID_PASSPHRASE);
            is_valid = MMI_FALSE;
        }
        keylen = strlen(buf);
        strcpy(passphrase, buf);
	if(is_valid == MMI_FALSE)
        {
	        memset(g_wlan_display_context.passphrase_str, 0, (SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH);
	        cui_fseditor_set_text(
	            g_wlan_display_context.wlan_editor_cui_id, 
	            (WCHAR*) g_wlan_display_context.passphrase_str, 
	            (SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH, 
	            SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN);        
	        return;
        }
    }
    else if (g_wlan_hilt_profile.privacy > 0 && 
             g_wlan_hilt_profile.rsn_ie_info_p == KAL_FALSE &&
             g_wlan_hilt_profile.wpa_ie_info_p == KAL_FALSE)
    {
        keylen = strlen(buf);
        switch (strlen(buf))
        {
            case 5:
            case 13:
                strcpy(passphrase, buf);
                break;
            case 10:
            {
                if (mmi_wlan_hex_to_string((U8 *)passphrase, (U8 *)buf, 10) == FALSE)
                {
                    mmi_wlan_invalid_passphrase_popup(STR_ID_DTCNT_WLAN_ERROR_INVALID_KEY);
                    is_valid = MMI_FALSE;
                }
                keylen = 5;
                break;
            }
            case 26:
            {
                if (mmi_wlan_hex_to_string((U8 *)passphrase, (U8 *)buf, 26) == FALSE)
                {
                    mmi_wlan_invalid_passphrase_popup(STR_ID_DTCNT_WLAN_ERROR_INVALID_KEY);
                    is_valid = MMI_FALSE;
                }
                keylen = 13;
                break;
            }
            default:
            {
                mmi_wlan_invalid_passphrase_popup(STR_ID_DTCNT_WLAN_ERROR_INVALID_KEY);
                is_valid = MMI_FALSE;
            }
        }
	if(is_valid == MMI_FALSE)
    	{
	    memset(g_wlan_display_context.passphrase_str, 0, (SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH);
	    cui_fseditor_set_text(
	            g_wlan_display_context.wlan_editor_cui_id, 
	            (WCHAR*) g_wlan_display_context.passphrase_str, 
	            (SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1) * ENCODING_LENGTH, 
	            SRV_DTCNT_PROF_MAX_WEP_KEY_LEN);        
	    return;
    	}
    }

    prof = &g_wlan_display_context.temp_profile;
    memset(&g_wlan_display_context.temp_profile, 0, sizeof(g_wlan_display_context.temp_profile));
    bssinfo_to_profile(prof, &g_wlan_hilt_profile, passphrase, keylen);
    mmi_wlan_save_default_eap_to_profile(prof);
    strcpy((char*)g_wlan_display_context.psk, passphrase);
    g_wlan_display_context.keylen = keylen;

    keylen = strlen(buf);
    if (g_wlan_hilt_profile.privacy > 0 && 
         g_wlan_hilt_profile.rsn_ie_info_p == KAL_FALSE &&
         g_wlan_hilt_profile.wpa_ie_info_p == KAL_FALSE && 
         (keylen == 10 || keylen == 26))
    {
        strcpy((char*)g_wlan_display_context.psk, buf);
        g_wlan_display_context.keylen = keylen;
    }

    g_wlan_display_context.pre_connect_by_always_ask = MMI_FALSE;
	mmi_wlan_entry_abortable_processing();

    mmi_wlan_send_connect_request(prof);

    cui_fseditor_close(g_wlan_display_context.wlan_editor_cui_id);
    g_wlan_display_context.wlan_editor_cui_id = GRP_ID_INVALID;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_pre_entry_find_network_connect
 * DESCRIPTION
 *  Data account main screen ( including GSM/GPPRS)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_pre_entry_find_network_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (g_wlan_display_context.active_ap)
    {
        // Save the highlight search ap into temp structure, avoid active_ap been modified unexpectedly
        memcpy(&g_wlan_hilt_profile, g_wlan_display_context.active_ap, sizeof(supc_abm_bss_info_struct));
        if (g_wlan_display_context.active_ap->network_type == WNDRV_SUPC_NETWORK_IBSS 
			&& g_wlan_display_context.active_ap->privacy > 0 &&
			(g_wlan_display_context.active_ap->rsn_ie_info_p == TRUE ||
			g_wlan_display_context.active_ap->wpa_ie_info_p == TRUE) &&
			g_wlan_display_context.active_ap->wpa_ie_info.key_mgmt & WPA_KEY_MGMT_PSK)
        {
            mmi_popup_display_simple(
                            (WCHAR*)GetString(STR_GLOBAL_NOT_SUPPORTED),
                            MMI_EVENT_FAILURE,
                            wlan_parent_group_id,
                            NULL);
			return;
        }
        if (!mmi_wlan_is_profile_matched_searched(&g_wlan_hilt_profile, &g_profile_saved_temp))
        {
            g_wlan_display_context.search_connect_need_save = MMI_TRUE;
            if (g_wlan_hilt_profile.rsn_ie_info_p == TRUE)
            {
                if (g_wlan_hilt_profile.rsn_ie_info.key_mgmt & MMI_WLAN_WPA_KEY_MGMT_PSK)
                {
                    if(WNDRV_SUPC_NETWORK_IBSS == g_wlan_hilt_profile.network_type)
                    {
                        mmi_popup_display_simple(
                            (WCHAR*)GetString(STR_ID_DTCNT_WLAN_ERROR_DEFINE_NETWORK_FIRST),
                            MMI_EVENT_FAILURE,
                            wlan_parent_group_id,
                            NULL);
                    }
                    else
                    {
                        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_NETWORK_CONN, 1, 0);
                        g_wlan_display_context.pass_len = SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN;
                        g_dtcnt_is_WEP_key = 0;
                        mmi_wlan_entry_passphrase_input();
                        return;
                    }
                }
                /* default eap type is EAP-PEAP + EAP-MSCHAPV2 */
                else
                {
                    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_NETWORK_CONN, 2, 0);
                    mmi_wlan_entry_default_eap_input();
                }
            }
            else if (g_wlan_hilt_profile.wpa_ie_info_p == TRUE)
            {
                if (g_wlan_hilt_profile.wpa_ie_info.key_mgmt & MMI_WLAN_WPA_KEY_MGMT_PSK)
                {
                    if(WNDRV_SUPC_NETWORK_IBSS == g_wlan_hilt_profile.network_type)
                    {
                        mmi_popup_display_simple(
                            (WCHAR*)GetString(STR_ID_DTCNT_WLAN_ERROR_DEFINE_NETWORK_FIRST),
                            MMI_EVENT_FAILURE,
                            wlan_parent_group_id,
                            NULL);
                    }
                    else
                    {
                        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_NETWORK_CONN, 3, 0);
                        
                        g_wlan_display_context.pass_len = SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN;
                        g_dtcnt_is_WEP_key = 0;
                        mmi_wlan_entry_passphrase_input();
                        return;
                    }
                }
                else if (g_wlan_hilt_profile.wpa_ie_info.key_mgmt & MMI_WLAN_WPA_KEY_MGMT_WPA_NONE)
                {
                    g_wlan_display_context.pass_len = SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN;
                    g_dtcnt_is_WEP_key = 0;
                    mmi_wlan_entry_passphrase_input();
                    return;
                }
                else
                {
                    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_NETWORK_CONN, 4, 0);
                    mmi_wlan_entry_default_eap_input();
                }    
            }
        #ifdef __WAPI_SUPPORT__
        #ifndef __MMI_HIDE_WAPI__
            else if (TRUE == g_wlan_hilt_profile.wapi_ie_info_p)
            {
                if (g_wlan_hilt_profile.wapi_ie_info.key_mgmt == WAPI_KEY_MGMT_PSK)
                {
                    g_wlan_display_context.wapi_is_auto_connect = MMI_TRUE;
                    g_dtcnt_is_WEP_key = 0;
                    g_wlan_display_context.wapi_psk_format = 0;
                    g_wlan_display_context.wapi_psk_str[0] = 0;
                    g_wlan_display_context.wapi_psk_str[1] = 0;
                    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_NETWORK_CONN, 5, 0);
                    mmi_wlan_entry_wapi_psk_settings();
                    return;
                }
                else if (g_wlan_hilt_profile.wapi_ie_info.key_mgmt == MMI_WLAN_WAPI_KEY_MGMT_WAI)
                {
                    g_wlan_display_context.wapi_is_auto_connect = MMI_TRUE;
                    g_dtcnt_is_WEP_key = 0;
                    g_wlan_display_context.wapi_ase_id = 0;
                    g_wlan_display_context.wapi_client_id = 0;
                    g_wlan_display_context.wapi_ase_name[0] = 0;
                    g_wlan_display_context.wapi_ase_name[1] = 0;
                    g_wlan_display_context.wapi_client_name[0] = 0;
                    g_wlan_display_context.wapi_client_name[1] = 0;

                    g_wlan_display_context.wapi_private_key_passwd_str[0] = 0;
                    g_wlan_display_context.wapi_private_key_passwd_str[1] = 0;
                    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_NETWORK_CONN, 6, 0);
                    mmi_wlan_entry_wapi_cert_settings();
                    return;
                }
            }
        #endif /* __MMI_HIDE_WAPI__ */
        #endif
            else if (g_wlan_hilt_profile.privacy > 0)
            {
                g_dtcnt_is_WEP_key = 1;
		g_wlan_display_context.pass_len = SRV_DTCNT_PROF_MAX_WEP_KEY_LEN;
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_NETWORK_CONN, 8, 0);
                mmi_wlan_entry_passphrase_input();
                return;
            }
            else /* No security method is applied */
            {
                mmi_wlan_profile_struct *prof = &g_wlan_display_context.temp_profile;

                memset(&g_wlan_display_context.temp_profile, 0, sizeof(g_wlan_display_context.temp_profile));
                bssinfo_to_profile(prof, &g_wlan_hilt_profile, NULL, 0);

                g_wlan_display_context.pre_connect_by_always_ask = MMI_FALSE;
                mmi_wlan_entry_abortable_processing();

                prof->always_ask_connect_flag = MMI_FALSE;                    
                mmi_wlan_send_connect_request(prof);
            }
        }
    }
}

void mmi_wlan_pre_entry_wlan_wizard(void)
{
    /* for entry new wizard profile list */
    g_wlan_display_context.entry_wizard_new_list = MMI_FALSE;
    g_wlan_display_context.wizard_cur_profile_list_index = 0;
    /* entry wlan wizard */
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
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
#else
	
		 if(mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_WIZARD_MAIN_LIST)
		 {
			  mmi_frm_display_dummy_screen();
			  mmi_frm_scrn_close_active_id();
		 }
		 else
		 {
		 mmi_wlan_entry_new_wizard_list();
		 }
			
#endif

    /* close scan waiting screen and saved ap list screen */
    mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_SCAN_PROCESSING);
    mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WIZARD_SAVED_LIST);
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_action_abort_find_network
 * DESCRIPTION
 *  poc registering screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_action_abort_find_network(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_wlan_display_context.send_conn_req_ing = MMI_FALSE;
    if (g_wlan_display_context.scan_job_id > 0)
    {
        srv_dtcnt_wlan_scan_abort(g_wlan_display_context.scan_job_id);
        
        // make cursor focused on the first item
        g_wlan_display_context.wizard_cur_profile_list_index = 0;
        g_wlan_display_context.scan_job_id = 0;
    }

    /* Refresh wifi icon on the top bar */
    mmi_wlan_set_status_bar_icon ();

    mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_SCAN_PROCESSING);

    mmi_wlan_set_ui_flow (MMI_WLAN_UI_ABORT_SCAN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_network_details
 * DESCRIPTION
 *  poc registering screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_network_details(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char tempBuf[MAX_SUBMENU_CHARACTERS];
    char tempBufUnicode[MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH];
    U8 *guiBuffer;
    U8 *info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            wlan_parent_group_id,
            SCR_ID_DTCNT_WLAN_NETWORK_DETAILS,
            NULL,
            mmi_wlan_entry_network_details,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

	guiBuffer = mmi_frm_scrn_get_gui_buf(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_NETWORK_DETAILS);

    info = (PU8) subMenuData;

    mmi_ucs2cpy((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SSID));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)L"  \n");
    if (g_wlan_display_context.active_ap->ssid_len == 0)
    {
        mmi_ucs2cat((CHAR*)info,   (const CHAR*)L"\n\n");
    }
    else
    {
        memset(tempBufUnicode, 0, MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH);
        custom_wlan_ssid_convert(
            (const char*) g_wlan_display_context.active_ap->ssid, 
            (char*) tempBufUnicode, 
            g_wlan_display_context.active_ap->ssid_len);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)tempBufUnicode);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n\n");
    }

    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n");
    switch (g_wlan_display_context.active_ap->network_type)
    {
        case WNDRV_SUPC_NETWORK_IBSS:
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE_ADHOC));
            break;
        case WNDRV_SUPC_NETWORK_INFRASTRUCTURE:
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE_INFRA));
            break;
        case WNDRV_SUPC_NETWORK_AUTO_UNKNOWN:
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_GLOBAL_AUTOMATIC));
            break;
    }
    mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n\n");

    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SIGNAL_STRENGTH));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n");
    if (g_wlan_display_context.active_ap->rssi > -40)
    {
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL0));
    }
    else if (g_wlan_display_context.active_ap->rssi > -60)
    {
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL1));
    }
    else if (g_wlan_display_context.active_ap->rssi > -70)
    {
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL2));
    }
    else if (g_wlan_display_context.active_ap->rssi > -80)
    {
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL3));
    }
    else
    {
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL4));
    }
    mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n\n");

    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SECURITY));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n");
    if (g_wlan_display_context.active_ap->rsn_ie_info_p == KAL_TRUE)
    {
        if (g_wlan_display_context.active_ap->rsn_ie_info.key_mgmt & MMI_WLAN_WPA_KEY_MGMT_PSK)
        {
            mmi_ucs2cat((CHAR*)info, (const CHAR*)L"WPA2-PSK\n\n");
        }
        else
        {
            mmi_ucs2cat((CHAR*)info, (const CHAR*)L"WPA2\n\n");
        }
    }
    else if (g_wlan_display_context.active_ap->wpa_ie_info_p == KAL_TRUE)
    {
        if (g_wlan_display_context.active_ap->wpa_ie_info.key_mgmt & MMI_WLAN_WPA_KEY_MGMT_PSK)
        {
            mmi_ucs2cat((CHAR*)info, (const CHAR*)L"WPA-PSK\n\n");
        }
        else
        {
            mmi_ucs2cat((CHAR*)info, (const CHAR*)L"WPA\n\n");
        }
    }
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    else if (MMI_TRUE == g_wlan_display_context.active_ap->wapi_ie_info_p)
    {
        if (WAPI_KEY_MGMT_PSK == g_wlan_display_context.active_ap->wapi_ie_info.key_mgmt)
        {
            mmi_ucs2cat((CHAR*)info, (const CHAR*)L"WAPI-PSK\n\n");
        }
        else if (MMI_WLAN_WAPI_KEY_MGMT_WAI == g_wlan_display_context.active_ap->wapi_ie_info.key_mgmt)
        {
            mmi_ucs2cat((CHAR*)info, (const CHAR*)L"WAPI-CERT.\n\n");
        }

    }
#endif /* __MMI_HIDE_WAPI__ */
#endif
    else if (g_wlan_display_context.active_ap->privacy > 0)
    {
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"WEP\n\n");
    }
    else
    {
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_OPEN));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n\n");
    }

    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_AP_NUMBER));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n");
    sprintf(tempBuf, "%d\n\n", g_wlan_display_context.active_ap->num_of_ap);
    mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
    mmi_ucs2cat((CHAR*)info, (const CHAR*)tempBufUnicode);

    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_LINK_SPEED));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n");
    sprintf(tempBuf, "%d Mbit/s\n", g_wlan_display_context.active_ap->max_rate / 2);
    mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
    mmi_ucs2cat((CHAR*)info, (const CHAR*)tempBufUnicode);

    ShowCategory74Screen(
        STR_GLOBAL_DETAILS,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) subMenuData,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

//remove for option slim
#if 0
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_encrypt_mode_ok
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_network_type_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.network_type = 
        (srv_dtcnt_wlan_network_type_enum)g_wlan_display_context.network_type_dummy;
    
    /* Reset authentiation mode if it is set to WPA/WPA2 or 802.1X */
    if(g_wlan_display_context.network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC)
    {
        if(g_wlan_display_context.auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY || 
           g_wlan_display_context.auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY || 
           // g_wlan_display_context.auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX || 
           g_wlan_display_context.auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
        || g_wlan_display_context.auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT
        || g_wlan_display_context.auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK
#endif /* __MMI_HIDE_WAPI__ */
#endif 
        )
        {
            g_wlan_display_context.auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_OPEN;
            g_wlan_display_context.encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE;
        }

    }
	else
	{
	    if (g_wlan_display_context.auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_TOTAL)
	    {
	        g_wlan_display_context.auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_OPEN;
            g_wlan_display_context.encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE;
	    }
    }

    g_wlan_display_context.modified = TRUE;
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_encrypt_mode_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_network_type_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.network_type_dummy = nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_network_type
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_network_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *nStrList[2];
    U16 nNumofItem = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            g_wlan_display_context.inline_setting_cui_id,
            SCR_ID_DTCNT_WLAN_NETWORK_OPERATION_MODE,
            NULL,
            mmi_wlan_entry_network_type,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_gui_buf(g_wlan_display_context.inline_setting_cui_id, SCR_ID_DTCNT_WLAN_NETWORK_OPERATION_MODE);

    if(guiBuffer == NULL)
    {
        g_wlan_display_context.network_type_dummy = g_wlan_display_context.network_type;
    }

    SetParentHandler(SCR_ID_DTCNT_WLAN_NETWORK_OPERATION_MODE);
    RegisterHighlightHandler(mmi_wlan_network_type_highlight_hdlr);

    nStrList[0] = (U8*) GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE_INFRA);
    nStrList[1] = (U8*) GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE_ADHOC);
    nNumofItem = 2;

    ShowCategory109Screen(
        STR_ID_DTCNT_WLAN_NETWORK_TYPE,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrList,
        NULL,
        g_wlan_display_context.network_type_dummy,
        guiBuffer);
//#ifndef __MMI_WGUI_DISABLE_CSK__
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_wlan_network_type_ok, KEY_EVENT_UP);
//#endif
    /* Register function with left/right softkey */
    SetLeftSoftkeyFunction(mmi_wlan_network_type_ok, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

//remove for option slim
#if 0
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_pre_entry_auth_mode
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_pre_entry_auth_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_wlan_display_context.network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC)
    {
        if(SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK == g_wlan_display_context.auth_mode)
        {
            g_wlan_display_context.sel_auth_mode = 2;
        }
		else if (SRV_DTCNT_WLAN_AUTH_MODE_TOTAL == g_wlan_display_context.auth_mode)
		{
		    g_wlan_display_context.sel_auth_mode = 0;
		}
        else
        {
            g_wlan_display_context.sel_auth_mode = g_wlan_display_context.auth_mode;
        }
    }
    else
    {
        for(index = 0; index < SRV_DTCNT_WLAN_AUTH_MODE_TOTAL; index++)
        {
            if(auth_mode_array[index] == g_wlan_display_context.auth_mode)
            {
                g_wlan_display_context.sel_auth_mode = index;
                break;
            }
        }
    }

    mmi_wlan_entry_auth_mode();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_auth_mode
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_auth_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *nStrList[SRV_DTCNT_WLAN_AUTH_MODE_TOTAL];
    U8 items = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            g_wlan_display_context.inline_setting_cui_id,
            SCR_ID_DTCNT_WLAN_NETWORK_AUTH_MODE,
            NULL,
            mmi_wlan_entry_auth_mode,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

	guiBuffer = mmi_frm_scrn_get_gui_buf(
        g_wlan_display_context.inline_setting_cui_id, 
        SCR_ID_DTCNT_WLAN_NETWORK_AUTH_MODE);

    RegisterHighlightHandler(mmi_wlan_auth_mode_highlight_hdlr);

    nStrList[items++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_OPEN);
    nStrList[items++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_SHARED);
    
    if(g_wlan_display_context.network_type != SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC)
    {
#ifndef WIFI_AUTH_PSK_ONLY
        nStrList[items++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_IEEE8021X);
        //nStrList[items++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPA_ONLY);
		nStrList[items++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX);
        nStrList[items++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY);
        // nStrList[items++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX);
#endif  /* WIFI_AUTH_PSK_ONLY */        
        //nStrList[items++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK);
		nStrList[items++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX_PSK);
        nStrList[items++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK);
#ifdef __WAPI_SUPPORT__     
#ifndef __MMI_HIDE_WAPI__
        nStrList[items++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WAPICERT);
        nStrList[items++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WAPIPSK);
#endif  /* __MMI_HIDE_WAPI__ */
#endif
    }
    else
    {
        nStrList[items++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPANONE);
    }
    
    ShowCategory109Screen(
        STR_ID_DTCNT_WLAN_AUTH_MODE,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        items,
        nStrList,
        NULL,
        g_wlan_display_context.sel_auth_mode,
        guiBuffer);
//#ifndef __MMI_WGUI_DISABLE_CSK__    
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_wlan_auth_mode_ok, KEY_EVENT_UP);
//#endif
    SetLeftSoftkeyFunction(mmi_wlan_auth_mode_ok, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_auth_mode_ok
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_auth_mode_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_auth_mode_enum new_auth_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_wlan_display_context.network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC && 
       g_wlan_display_context.sel_auth_mode == 2 /* WPA-None */)
    {
        new_auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK;
    }
    else
    {
        new_auth_mode = auth_mode_array[g_wlan_display_context.sel_auth_mode];
    }
    
    if (g_wlan_display_context.auth_mode != new_auth_mode)
    {
        switch(new_auth_mode)
        {
	    case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY:
	    case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK:
		 g_wlan_display_context.encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP;
                    break;
                   
            case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY:    
            case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK:
		 g_wlan_display_context.encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_AES;
		 break;
		
	    case SRV_DTCNT_WLAN_AUTH_MODE_WEP:
	    case SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X:
                g_wlan_display_context.encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP;
                break;
		
	    case SRV_DTCNT_WLAN_AUTH_MODE_OPEN:
                    g_wlan_display_context.encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE;
                break;
				
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
            case SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT:
            case SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK:
	        g_wlan_display_context.encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_WPI;
                break;
#endif
#endif
        }
        g_wlan_display_context.modified = TRUE;
    }

    g_wlan_display_context.auth_mode = new_auth_mode;

    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_auth_mode_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for DTCNTAppList
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_auth_mode_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.sel_auth_mode = nIndex;
}

//remove for option slim
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_wep_settings
 * DESCRIPTION
 *  WLAN TCP/IP settings editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_wep_settings(void)
{
    S32 length = 0;
    
    g_wlan_display_context.inline_wep_cui_id = cui_inline_create(
                                wlan_parent_group_id,
                                &g_wep_key_inline_struct);

    switch (g_wlan_display_context.wep_key_len)
    {
        case WLAN_WEP_KEY_ENCRYPT_64:
            if (g_wlan_display_context.wep_key_format == WLAN_WEP_KEY_FORMAT_HEX)
            {
                length = 10;
            }
            else
            {
                length = 5;
            }
            break;
        case WLAN_WEP_KEY_ENCRYPT_128:
            if (g_wlan_display_context.wep_key_format == WLAN_WEP_KEY_FORMAT_HEX)
            {
                length = 26;
            }
            else
            {
                length = 13;
            }
            break;
        default:
            ASSERT(0);
            break;            
    }

    cui_inline_set_text_len(
        g_wlan_display_context.inline_wep_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY, 
        length + 1);
    
    /* reset temp's value as ap's wep key string */
    g_wlan_display_context.sel_wep_key_index = g_wlan_display_context.wep_key_index;
    g_wlan_display_context.sel_wep_key_len = g_wlan_display_context.wep_key_len;
    g_wlan_display_context.sel_wep_key_format = g_wlan_display_context.wep_key_format;
    memset(g_wlan_display_context.sel_wep_key_str, 0, MAX_WEP_KEYSTR_LEN * ENCODING_LENGTH);
    mmi_ucs2ncpy (
        (CHAR *)g_wlan_display_context.sel_wep_key_str,
        (const CHAR *)g_wlan_display_context.wep_key_str, 
        mmi_ucs2strlen((const CHAR *)g_wlan_display_context.wep_key_str));

    cui_inline_set_value(
        g_wlan_display_context.inline_wep_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY_ID, 
        (void*)g_wlan_display_context.wep_key_index); 

    cui_inline_set_value(
        g_wlan_display_context.inline_wep_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY_ENCRYPT, 
        (void*)g_wlan_display_context.wep_key_len); 

    cui_inline_set_value(
        g_wlan_display_context.inline_wep_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY_FORMAT, 
        (void*)g_wlan_display_context.wep_key_format); 

    cui_inline_set_value(
        g_wlan_display_context.inline_wep_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY, 
        g_wlan_display_context.wep_key_str); 

    cui_inline_set_fullscreen_edit_title_icon(
		g_wlan_display_context.inline_wep_cui_id, 
		CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY, 
		GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
    cui_inline_set_title_icon(g_wlan_display_context.inline_wep_cui_id, GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
    cui_inline_run(g_wlan_display_context.inline_wep_cui_id);
}

void mmi_wlan_show_invalid_wep_key_popup(void)
{
    mmi_popup_display_simple(
        (WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_KEY)), 
        MMI_EVENT_FAILURE, 
        wlan_parent_group_id, 
        NULL);
}

void mmi_wlan_invalid_wep_key_hdlr(void)
{
    mmi_popup_display_simple(
        (WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_KEY)), 
        MMI_EVENT_FAILURE, 
        wlan_parent_group_id, 
        NULL);

    memset(g_wlan_display_context.sel_wep_key_str, 0, MAX_WEP_KEYSTR_LEN * ENCODING_LENGTH);
    cui_inline_set_value(
        g_wlan_display_context.inline_wep_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY, 
        g_wlan_display_context.sel_wep_key_str);

    cui_inline_set_screen_attributes(
        g_wlan_display_context.inline_wep_cui_id, 
        CUI_INLINE_RESET_ATTRIBUTE, 
        CUI_INLINE_SCREEN_CHANGED);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_check_wep_key_string
 * DESCRIPTION
 *  Check the wep key's validity
 * PARAMETERS
 *  U8* wep_key: [In] WEP Key String
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_wlan_check_wep_key_string(S32 wep_key_len, S32 wep_key_format, U8* wep_key)
{
    switch (wep_key_len)
    {
        case WLAN_WEP_KEY_ENCRYPT_64:
            if (wep_key_format == WLAN_WEP_KEY_FORMAT_HEX)
            {
                if (strlen((const char*)wep_key) != 10 ||
                    !is_valid_hexstring(wep_key, 10))
                {
                    return MMI_FALSE;
                } 
             }
            else
            {
                if (strlen((const char*)wep_key) != 5 ||
                    !is_valid_ascii_string(wep_key, 5))
                {
                    return MMI_FALSE; 
                }
            }
            break;
        case WLAN_WEP_KEY_ENCRYPT_128:
            if (wep_key_format == WLAN_WEP_KEY_FORMAT_HEX)
            {
                if (strlen((const char*)wep_key) != 26 ||
                    !is_valid_hexstring(wep_key, 26))
                {
                    return MMI_FALSE;
                }
            }
            else
            {
                if (strlen((const char*)wep_key) != 13 ||
                    !is_valid_ascii_string(wep_key, 13))
                {
                    return MMI_FALSE;
                }
            }
            break;
        default:
            break;
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wep_settings_save
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_wlan_wep_settings_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 wep_key[MAX_WEP_KEYSTR_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((CHAR*)wep_key, (CHAR*)g_wlan_display_context.sel_wep_key_str);

    switch (g_wlan_display_context.sel_wep_key_len)
    {
        case WLAN_WEP_KEY_ENCRYPT_64:
            if (g_wlan_display_context.sel_wep_key_format == WLAN_WEP_KEY_FORMAT_HEX)
            {
                if (strlen((const char*)wep_key) != 10 ||
                    !is_valid_hexstring(wep_key, 10))
                {
                    mmi_wlan_invalid_wep_key_hdlr();
                    return MMI_FALSE;
                } 
             }
            else
            {
                if (strlen((const char*)wep_key) != 5 ||
                    !is_valid_ascii_string(wep_key, 5))
                {
                    mmi_wlan_invalid_wep_key_hdlr();
                    return MMI_FALSE; 
                }
            }
            break;
        case WLAN_WEP_KEY_ENCRYPT_128:
            if (g_wlan_display_context.sel_wep_key_format == WLAN_WEP_KEY_FORMAT_HEX)
            {
                if (strlen((const char*)wep_key) != 26 ||
                    !is_valid_hexstring(wep_key, 26))
                {
                    mmi_wlan_invalid_wep_key_hdlr();
                    return MMI_FALSE;
                }
            }
            else
            {
                if (strlen((const char*)wep_key) != 13 ||
                    !is_valid_ascii_string(wep_key, 13))
                {
                    mmi_wlan_invalid_wep_key_hdlr();
                    return MMI_FALSE;
                }
            }
            break;
    }

    g_wlan_display_context.wep_key_index = g_wlan_display_context.sel_wep_key_index;
    g_wlan_display_context.wep_key_len = g_wlan_display_context.sel_wep_key_len;
    g_wlan_display_context.wep_key_format = g_wlan_display_context.sel_wep_key_format;
    memcpy(
        g_wlan_display_context.wep_key_str, 
        g_wlan_display_context.sel_wep_key_str,
        MAX_WEP_KEYSTR_LEN * ENCODING_LENGTH);
    
    g_wlan_display_context.modified = TRUE;    

    return MMI_TRUE;
}

void mmi_wlan_wep_key_string_formatter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 length = 0;
    S32 old_length = 0;
    U8  wep_key[MAX_WEP_KEYSTR_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch (g_wlan_display_context.sel_wep_key_len)
    {
        case WLAN_WEP_KEY_ENCRYPT_64:
            if (g_wlan_display_context.sel_wep_key_format == WLAN_WEP_KEY_FORMAT_HEX)
            {
                length = 10;
            }
            else
            {
                length = 5;
                
            }
            break;
        case WLAN_WEP_KEY_ENCRYPT_128:
            if (g_wlan_display_context.sel_wep_key_format == WLAN_WEP_KEY_FORMAT_HEX)
            {
                length = 26;
            }
            else
            {
                length = 13;
            }
            break;
        default:
            ASSERT(0);
            break;
    }

    mmi_ucs2_to_asc((CHAR*)wep_key, (CHAR*)g_wlan_display_context.sel_wep_key_str);
    old_length = strlen((const CHAR*)wep_key);
    if (old_length > length)
    {
        /* truncate key if it exceeds the limit */
        g_wlan_display_context.sel_wep_key_str[2*length] = 0;
        g_wlan_display_context.sel_wep_key_str[2*length + 1] = 0;
    }
        
    cui_inline_set_text_len(g_wlan_display_context.inline_wep_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY, 
        length + 1);
    cui_inline_set_value(g_wlan_display_context.inline_wep_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY, 
        g_wlan_display_context.sel_wep_key_str);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wep_settings_key_format_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of local currency inline selection in compute screen.
 * PARAMETERS
 *  index       [IN]        Index of selected item.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wep_settings_key_format_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_wlan_display_context.sel_wep_key_format != index)
    {
        g_wlan_display_context.sel_wep_key_format = index;
        mmi_wlan_wep_key_string_formatter();
        
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wep_settings_key_len_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of local currency inline selection in compute screen.
 * PARAMETERS
 *  index       [IN]        Index of selected item.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wep_settings_key_len_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_wlan_display_context.sel_wep_key_len != index)
    {
        g_wlan_display_context.sel_wep_key_len = index;
        mmi_wlan_wep_key_string_formatter();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wep_settings_key_id_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of local currency inline selection in compute screen.
 * PARAMETERS
 *  index       [IN]        Index of selected item.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wep_settings_key_id_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wlan_display_context.sel_wep_key_index != index)
    {
        g_wlan_display_context.sel_wep_key_index = index;
        mmi_wlan_wep_key_string_formatter();
    }
}

//remove for option slim
#if 0
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_passphrase_input
 * DESCRIPTION
 *  It download a theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_passphrase_input(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 passphrase_string[(SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_wlan_display_context.wlan_editor_cui_id = cui_fseditor_create(wlan_parent_group_id)) != 0)
    {
        if (g_dtcnt_is_WEP_key)
        {
            cui_fseditor_set_title(
                g_wlan_display_context.wlan_editor_cui_id, 
                STR_ID_DTCNT_WLAN_WEP_KEY, 
                GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
		memset(passphrase_string, 0, (SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1) * ENCODING_LENGTH);
	        cui_fseditor_set_text(
	            g_wlan_display_context.wlan_editor_cui_id, 
	            (WCHAR*) passphrase_string, 
	            (SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1) * ENCODING_LENGTH, 
	            SRV_DTCNT_PROF_MAX_WEP_KEY_LEN);
        }
        else
        {
            cui_fseditor_set_title(
                g_wlan_display_context.wlan_editor_cui_id, 
                STR_ID_DTCNT_WLAN_WPA_PASSPHRASE, 
                GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
        memset(passphrase_string, 0, (SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH);
        cui_fseditor_set_text(
            g_wlan_display_context.wlan_editor_cui_id, 
            (WCHAR*) passphrase_string, 
            (SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH, 
            SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN);
        }
        
        cui_fseditor_set_input_method(
            g_wlan_display_context.wlan_editor_cui_id, 
            IMM_INPUT_TYPE_ASCII_PASSWORD, 
            NULL, 
            INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
        
        cui_fseditor_run(g_wlan_display_context.wlan_editor_cui_id);    
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_wpa_passphrase
 * DESCRIPTION
 *  It download a theme
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_wpa_passphrase(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    U8 passphrase_in_wps[SRV_DTCNT_PROF_MAX_PSK_LEN - 2];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_wlan_display_context.passphrase_str, 0, (SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH);
    if (strlen((const char*)g_wlan_display_context.passphrase) > 0)
    {
        mmi_asc_n_to_ucs2(
            (CHAR*) g_wlan_display_context.passphrase_str,
            (CHAR*) g_wlan_display_context.passphrase,
            strlen((const char*)g_wlan_display_context.passphrase));
		g_wlan_display_context.pass_len = strlen((const char*)g_wlan_display_context.passphrase);
    }
    else
    {
        if(strlen((const char*)g_wlan_display_context.psk) > 0)
        {
            /* passpharse is empty when construct one profile for WPS conn. */
            /* the max length of passphase is 32. */
            for(index = 0; index < SRV_DTCNT_PROF_MAX_PSK_LEN - 2; index++)
            {
                passphrase_in_wps[index] = 97;
            }

            mmi_asc_n_to_ucs2(
                (CHAR*) g_wlan_display_context.passphrase_str,
                (CHAR*) passphrase_in_wps,
                SRV_DTCNT_PROF_MAX_PSK_LEN - 2);
        }
		g_wlan_display_context.pass_len = SRV_DTCNT_PROF_MAX_PSK_LEN - 2;
    }

    g_wlan_display_context.wpa_psk_modified = FALSE;
    
    if ((g_wlan_display_context.wlan_inline_editor_cui_id = cui_fseditor_create(wlan_parent_group_id)) != 0)
    {
        cui_fseditor_set_title(
            g_wlan_display_context.wlan_inline_editor_cui_id, 
            STR_ID_DTCNT_WLAN_WPA_PASSPHRASE, 
            GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
        cui_fseditor_set_text(
            g_wlan_display_context.wlan_inline_editor_cui_id, 
            (WCHAR*) g_wlan_display_context.passphrase_str, 
            (SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH, 
            SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN);
        cui_fseditor_set_input_method(
            g_wlan_display_context.wlan_inline_editor_cui_id, 
            IMM_INPUT_TYPE_ASCII_PASSWORD,
            NULL, 
            INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
        cui_fseditor_run(g_wlan_display_context.wlan_inline_editor_cui_id);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wpa_passphrase_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  int(?)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wpa_passphrase_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char passphrase[SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1] = "";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((CHAR*)passphrase, (CHAR*)g_wlan_display_context.passphrase_str);
    //g_wlan_display_context.pass_len = strlen(passphrase);
    if (strlen(passphrase) < 8)
    {
        memset(g_wlan_display_context.passphrase_str, 0, (SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH);
        
        mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_PASSPHRASE)), 
            MMI_EVENT_FAILURE, 
            wlan_parent_group_id, 
            NULL);
        
        cui_fseditor_set_text(
            g_wlan_display_context.wlan_inline_editor_cui_id, 
            (WCHAR*) g_wlan_display_context.passphrase_str, 
            (SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH, 
            SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN);
        
        return;
    }

    if (g_wlan_display_context.wpa_psk_modified)
    {
        g_wlan_display_context.modified = TRUE;
        g_wlan_display_context.wpa_psk_modified = FALSE;
    }

    if (strlen(g_wlan_display_context.psk) == 0 || g_wlan_display_context.modified == TRUE)
    {
        strcpy((char*)g_wlan_display_context.passphrase, (const char*)passphrase);
		memset(g_wlan_display_context.psk, 0, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN);
    }

    cui_fseditor_close(g_wlan_display_context.wlan_inline_editor_cui_id);
}

void mmi_wlan_network_clear_history_data(void)
{
#ifdef __CERTMAN_SUPPORT__
    g_wlan_display_context.client_ca_id = 0;
    g_wlan_display_context.root_ca_id = 0;
#endif    
    g_wlan_display_context.auth_type1 = 0;
    g_wlan_display_context.eap_ttls_auth_type = 0;
    g_wlan_display_context.eap_peap_auth_type = 0;
    memset(g_wlan_display_context.username_str, 0, MAX_USERNAME_LEN * ENCODING_LENGTH);
    memset(g_wlan_display_context.password_str, 0, MAX_PASSWORD_LEN * ENCODING_LENGTH);
    memset(g_wlan_display_context.passphrase_str, 0, (SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_network_edit_save_yes
 * DESCRIPTION
 *  Proceed saving profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_network_edit_save_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;
    U8 old_network;
    U8 ssid_length;
    U8 ssid[SRV_DTCNT_PROF_MAX_SSID_LEN + 1];
    mmi_wlan_profile_struct *active_profile;
    mmi_wlan_profile_struct *temp = NULL;
    U8 wep_key[MAX_WEP_KEYSTR_LEN];
    srv_dtcnt_wlan_status_enum wlan_status;
    U32 fields = SRV_DTCNT_WLAN_PROF_FIELD_ALL;
    mmi_chset_enum ret_charset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if the number reach the up limit, give a prompt and return */ 
    if (g_wlan_display_context.insert_mode &&
        g_wlan_display_context.prof_num == MAX_WLAN_DATA_ACCOUNT_NUM)
    {
        mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_MEMORY_FULL)), 
            MMI_EVENT_FAILURE, 
            wlan_parent_group_id, 
            NULL);
        return;
    }
	if (g_wlan_display_context.auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_TOTAL)
	{
	    mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_SUPPORTED)), 
            MMI_EVENT_FAILURE, 
            wlan_parent_group_id, 
            NULL);
        return;
	}
	if((g_wlan_display_context.send_conn_req_ing != MMI_FALSE ||
	    srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_CONNECT_WAIT ||
	   srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT) &&
	   ( mmi_wlan_get_ui_flow () == MMI_WLAN_UI_CONNECT_BY_CUI ||
	     mmi_wlan_get_ui_flow () == MMI_WLAN_UI_CONNECT_BY_APP ||
	     mmi_wlan_get_ui_flow () == MMI_WLAN_UI_CONNECT_BY_API ))
    {
        mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_CONNECTING_NO_EDIT)), 
            MMI_EVENT_FAILURE, 
            wlan_parent_group_id,
            NULL);
        cui_inline_close(g_wlan_display_context.inline_setting_cui_id);
	    return;
    }
    
    wlan_status = srv_dtcnt_wlan_status();

    /* Todo: validation required here */
    if (wlan_status == SRV_DTCNT_WLAN_STATUS_CONNECTED &&
        !g_wlan_display_context.insert_mode &&
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#else
/* under construction !*/
#endif   
#else
			g_wlan_profile[g_wlan_display_context.active_wlan_profile_index] == g_wlan_display_context.connected_wlan_profile)
#endif 

    {
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_setting_cui_id);
        mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_CONNECTING_NO_EDIT)), MMI_EVENT_FAILURE, wlan_parent_group_id, NULL);

        return;
    }

    if(g_wlan_display_context.is_to_define_ap)
    {
        active_profile = g_wlan_display_context.active_wlan_profile_p;	  
    }
    else
    {
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#else
/* under construction !*/
#endif
#else
			active_profile = g_wlan_display_context.active_wlan_profile_p;
#endif

    }

    ret_charset = mmi_chset_guess(
                   (const char* )active_profile->ssid,
                   active_profile->ssid_len,
                   (mmi_chset_enum)(0),
                   CHSET_GUESS_ALL);

    mmi_chset_convert(
		MMI_CHSET_UCS2,
        ret_charset,
        (char *)g_wlan_display_context.ssid_str,
        (char *)ssid,
        SRV_DTCNT_PROF_MAX_SSID_LEN + 1);
 
    ssid_length = strlen((const char*)ssid);
    if (ssid_length == 0)
    {

        mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_SSID)), MMI_EVENT_FAILURE, wlan_parent_group_id, NULL);

        return;
    }


    if((SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X != g_wlan_display_context.auth_mode) &&
       (SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP == g_wlan_display_context.encrypt_mode))
    {
        memset (wep_key, 0, MAX_WEP_KEYSTR_LEN);
        mmi_ucs2_to_asc((CHAR*)wep_key, (CHAR*)g_wlan_display_context.sel_wep_key_str);
        if(MMI_FALSE == mmi_wlan_check_wep_key_string (
                            g_wlan_display_context.wep_key_len, 
                            g_wlan_display_context.wep_key_format, 
                            (U8*)wep_key))
        {
            mmi_wlan_show_invalid_wep_key_popup ();
            
            return;
        }
    }
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

 
    for (i = 0; i < g_wlan_display_context.prof_num; i++)
    {
        if(active_profile == g_wlan_profile[i])
            continue;

        if ((ssid_length == g_wlan_profile[i]->ssid_len) &&
            (strncmp((const char*)g_wlan_profile[i]->ssid, (const char*)ssid, g_wlan_profile[i]->ssid_len) == 0) &&
            (g_wlan_profile[i]->network_type == g_wlan_display_context.network_type) &&
            (g_wlan_profile[i]->auth_mode == g_wlan_display_context.auth_mode) &&
            (g_wlan_profile[i]->encrypt_mode == g_wlan_display_context.encrypt_mode))
        {
            mmi_popup_display_simple(
                (WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_AP_EXISTED)), 
                MMI_EVENT_FAILURE, 
                wlan_parent_group_id, 
                NULL);
            return;
        }
    }

    if (g_wlan_display_context.auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK ||
        g_wlan_display_context.auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK)
        // g_wlan_display_context.auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX_PSK
    {
        if (g_wlan_display_context.pass_len < 8)
        {
            mmi_frm_scrn_close_active_id();

            mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_PASSPHRASE)), MMI_EVENT_FAILURE, wlan_parent_group_id, NULL);

            return;
        }
    
    }
    mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_setting_cui_id);

    active_profile->ssid_len = strlen((const char*)ssid);
    memset(active_profile->ssid, 0, SRV_DTCNT_PROF_MAX_SSID_LEN + 1);
    memcpy(active_profile->ssid, ssid, active_profile->ssid_len);
    memset(active_profile->name, 0, (SRV_DTCNT_PROF_MAX_WLAN_PROF_NAME_LEN + 1) * ENCODING_LENGTH);
    mmi_ucs2cpy((CHAR*)active_profile->name, (const CHAR*)g_wlan_display_context.name);
    
    old_network = active_profile->network_type;
    active_profile->network_type = g_wlan_display_context.network_type;
    active_profile->auth_mode = g_wlan_display_context.auth_mode;
    active_profile->encrypt_mode = g_wlan_display_context.encrypt_mode;

    if (active_profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WEP || active_profile->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP)
    {
        active_profile->wep_key_index = g_wlan_display_context.wep_key_index;
        active_profile->wep_key_len = g_wlan_display_context.wep_key_len;
        active_profile->wep_key_format = g_wlan_display_context.wep_key_format;
        mmi_ucs2_to_asc((CHAR*)active_profile->wep_key, (CHAR*)g_wlan_display_context.wep_key_str);
    }

    if (active_profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK ||
        active_profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK)
        // active_profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX_PSK
    {
        /*if(strlen((const char*)g_wlan_display_context.passphrase) == 64)
        {
            mmi_wlan_hex_to_string(active_profile->psk, g_wlan_display_context.passphrase, 64);
            memset(active_profile->passphrase, 0, sizeof(active_profile->passphrase));
            active_profile->psk[32] = 1;
        }
        else*/ if (strcmp((const char*)active_profile->passphrase, (const char*)g_wlan_display_context.passphrase) != 0 ||
            active_profile->psk[0] == 0)
        {
            strcpy((char*)active_profile->passphrase, (const char*)g_wlan_display_context.passphrase);
            active_profile->passphrase_len = strlen(g_wlan_display_context.passphrase);
        #ifdef __MTK_TARGET__
            pbkdf2_sha1(
                (const char*)active_profile->passphrase,
                (const char*)active_profile->ssid,
                active_profile->ssid_len,
                4096,
                active_profile->psk,
                32);
        #else /* __MTK_TARGET__ */ 
            strcpy((char*)active_profile->psk, (const char*)active_profile->passphrase);
        #endif /* __MTK_TARGET__ */ 
        }
    }

    if (active_profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X || 
        active_profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY ||
        active_profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY)
        // active_profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX
    {
        active_profile->auth_type1 = g_wlan_display_context.auth_type1;
        active_profile->eap_peap_auth_type = g_wlan_display_context.eap_peap_auth_type;
        active_profile->eap_ttls_auth_type = g_wlan_display_context.eap_ttls_auth_type;
#ifndef __CERTMAN_SUPPORT__
        mmi_ucs2cpy((CHAR*)active_profile->client_ca_path, (const CHAR*)g_wlan_display_context.client_ca_path);
        mmi_ucs2cpy((CHAR*)active_profile->root_ca_path, (const CHAR*)g_wlan_display_context.root_ca_path);
        mmi_ucs2cpy((CHAR*)active_profile->private_key_path, (const CHAR*)g_wlan_display_context.private_key_path);
#else
                active_profile->client_ca_id = g_wlan_display_context.client_ca_id;
                active_profile->root_ca_id = g_wlan_display_context.root_ca_id;
#endif /* __CERTMAN_SUPPORT__ */

        mmi_ucs2_to_asc((CHAR*)active_profile->private_key_passwd, (CHAR*) g_wlan_display_context.private_key_passwd_str);
        mmi_ucs2_to_asc((CHAR*)active_profile->username, (CHAR*) g_wlan_display_context.username_str);
        mmi_ucs2_to_asc((CHAR*)active_profile->password, (CHAR*) g_wlan_display_context.password_str);

        memset(g_wlan_display_context.username_str, 0, sizeof(g_wlan_display_context.username_str));
        memset(g_wlan_display_context.password_str, 0, sizeof(g_wlan_display_context.password_str));
    }
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
#ifdef __CERTMAN_SUPPORT__
    if (active_profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT)
    {
        active_profile->wapi_ase_id = g_wlan_display_context.wapi_ase_id;
        active_profile->wapi_client_id = g_wlan_display_context.wapi_client_id;
        mmi_ucs2_to_asc((CHAR*)active_profile->wapi_private_key_passwd_str, (CHAR*)g_wlan_display_context.wapi_private_key_passwd_str);
    }
#endif
    if (active_profile->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK)
    {
        mmi_ucs2_to_asc((CHAR*)active_profile->wapi_psk_str, (CHAR*)g_wlan_display_context.wapi_psk_str);
        active_profile->wapi_psk_format = g_wlan_display_context.wapi_psk_format;
    }
#endif /* __MMI_HIDE_WAPI__ */    
#endif

    if(g_wlan_display_context.allow_peap0 > 0)
    {
        active_profile->peap_version |= SUPC_PHASE1_PEAP_0;
    }
    else
    {
        active_profile->peap_version &= ~SUPC_PHASE1_PEAP_0;
    }

    if(g_wlan_display_context.allow_peap1 > 0)
    {
        active_profile->peap_version |= SUPC_PHASE1_PEAP_1;
    }
    else
    {
        active_profile->peap_version &= ~SUPC_PHASE1_PEAP_1;
    }

    active_profile->channel = (U32)g_wlan_display_context.channel_number;

    active_profile->use_dhcp = g_wlan_display_context.use_dhcp;
    memcpy(active_profile->ip_addr, g_wlan_display_context.ip_addr, 4);
    memcpy(active_profile->netmask, g_wlan_display_context.netmask, 4);
    memcpy(active_profile->gateway, g_wlan_display_context.gateway, 4);
    memcpy(active_profile->dns1, g_wlan_display_context.dns1, 4);
    memcpy(active_profile->dns2, g_wlan_display_context.dns2, 4);

    /* advanced setting */
    g_wlan_info_prof.use_proxy = g_wlan_display_context.use_proxy;
    g_wlan_info_prof.px_port = g_wlan_display_context.proxy_port;

    mmi_ucs2_to_asc((CHAR *)g_wlan_info_prof.HomePage, (CHAR *)g_wlan_display_context.home_page);
    mmi_ucs2_to_asc((CHAR *)g_wlan_info_prof.px_addr, (CHAR *)g_wlan_display_context.proxy_addr);
    mmi_ucs2_to_asc((CHAR *)g_wlan_info_prof.px_authid, (CHAR *)g_wlan_display_context.proxy_user_name);
    mmi_ucs2_to_asc((CHAR *)g_wlan_info_prof.px_authpw, (CHAR *)g_wlan_display_context.proxy_password);

    //memcpy(g_wlan_info_prof.px_addr, g_wlan_display_context.proxy_ip, MAX_PART_IP_ADDRESS);

    if (g_wlan_display_context.insert_mode == TRUE)
    {
        /* Find an empty slot index first */
        for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
        {
            if (g_wlan_prof_list[i].ssid_len == 0)
            {
                break;
            }
        }

        if(active_profile->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
        {
            if(g_wlan_display_context.adhoc_prof_num == 0)
            {
                active_profile->priority = ++g_wlan_display_context.prof_num;
                        
                memcpy(&g_wlan_prof_list[i], active_profile, sizeof(mmi_wlan_profile_struct));
                g_wlan_profile[g_wlan_prof_list[i].priority - 1] = &g_wlan_prof_list[i];
                // g_wlan_display_context.active_wlan_profile_p = &g_wlan_prof_list[i];
            }
            else
            {
                for(j = g_wlan_display_context.prof_num; j > g_wlan_display_context.infra_prof_num; j--)
                {
                    g_wlan_profile[j] = g_wlan_profile[j-1];
                    g_wlan_profile[j]->priority++;
                }

                active_profile->priority = g_wlan_display_context.infra_prof_num + 1;
                memcpy(&g_wlan_prof_list[i], active_profile, sizeof(mmi_wlan_profile_struct));
                g_wlan_profile[g_wlan_display_context.infra_prof_num] = &g_wlan_prof_list[i];
                g_wlan_display_context.prof_num++;
            }
            g_wlan_display_context.infra_prof_num++;
        }
        else 
        {
            g_wlan_display_context.adhoc_prof_num++;

            active_profile->priority = ++g_wlan_display_context.prof_num;

            memcpy(&g_wlan_prof_list[i], active_profile, sizeof(mmi_wlan_profile_struct));
            g_wlan_profile[g_wlan_prof_list[i].priority - 1] = &g_wlan_prof_list[i];
            // g_wlan_display_context.trust_list_hilt_profile_p = &g_wlan_prof_list[i];
        }
        
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EDIT_SAVE, 1);
        mmi_wlan_dtcnt_store_profile(&(g_wlan_prof_list[i]), 1, fields);                
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_EDIT_SAVE, 0);

        for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
        {
            if (active_profile == &g_wlan_prof_list[i])
            {
                break;
            }
        }
        /* changed ap profile network_type */
        if(active_profile->network_type != old_network)
        {
            /* adhoc -> Infrastructure*/
            if(active_profile->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
            {
                if(active_profile->priority == g_wlan_display_context.infra_prof_num + 1)
                {
                    g_wlan_display_context.infra_prof_num++;
                    g_wlan_display_context.adhoc_prof_num--;
                }
                else
                {
                    temp = active_profile;
                    for(j = (active_profile->priority - 1); j > g_wlan_display_context.infra_prof_num; j--)
                    {
                        g_wlan_profile[j] = g_wlan_profile[j - 1];
                        g_wlan_profile[j]->priority++;
                    }
                    g_wlan_profile[g_wlan_display_context.infra_prof_num ] = temp;
                    g_wlan_profile[g_wlan_display_context.infra_prof_num ]->priority = g_wlan_display_context.infra_prof_num + 1;
                    g_wlan_display_context.infra_prof_num++;
                    g_wlan_display_context.adhoc_prof_num--;
                }
            }
            else /* Infrastructure -> adhoc */
            {
                if(active_profile->priority == g_wlan_display_context.infra_prof_num)
                {
                    g_wlan_display_context.infra_prof_num--;
                    g_wlan_display_context.adhoc_prof_num++;
                }
                else
                {
                    temp = active_profile;
                    for(j = (g_wlan_prof_list[i].priority); j < g_wlan_display_context.infra_prof_num; j++)
                    {
                        g_wlan_profile[j-1] = g_wlan_profile[j];
                        g_wlan_profile[j]->priority--;
                    }
                    g_wlan_profile[g_wlan_display_context.infra_prof_num - 1] = temp;
                    g_wlan_profile[g_wlan_display_context.infra_prof_num - 1]->priority = g_wlan_display_context.infra_prof_num;
                    g_wlan_display_context.infra_prof_num--;
                    g_wlan_display_context.adhoc_prof_num++;
                }
            }
        }
    }

    for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
    {
        if (g_wlan_prof_list[i].priority > 0)
        {
            if (active_profile->profile_id == g_wlan_prof_list[i].profile_id)
            {
                fields = SRV_DTCNT_WLAN_PROF_FIELD_ALL;
            }
            else
            {
                fields = (SRV_DTCNT_WLAN_PROF_FIELD_ALL & (~MMI_WLAN_ADVANCE_FIELD));
            }

            mmi_wlan_dtcnt_store_profile(&(g_wlan_prof_list[i]), 0, fields);
        }
    }
    g_wlan_display_context.wizard_profile_changed = MMI_TRUE;

    mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SAVED)), MMI_EVENT_SUCCESS, wlan_parent_group_id, NULL);
    
    /* Clear history data */
    mmi_wlan_network_clear_history_data();
    mmi_wlan_save_default_eap_to_display_cntx();
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_network_edit_save_no
 * DESCRIPTION
 *  Give up saving profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_network_edit_save_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_setting_cui_id);
    mmi_frm_scrn_close_active_id();

    /* Clear temp data for username and password */
    mmi_wlan_network_clear_history_data();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_fullline_edit_screen
 * DESCRIPTION
 *  Data Account Name for Full Line Edit Screen.
 *  
 *  This is used to edit Data Account.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_fullline_edit_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.modified2 = FALSE;
    ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, IMG_GLOBAL_OPTIONS);

    SetInputMethodAndDoneCaptionIcon(
#if 0
#ifdef __WIFI_WIZARD_SUPPORT__
/* under construction !*/
#else
/* under construction !*/
#endif
#else
	GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID)
#endif
    );

    SetLeftSoftkeyFunction(EntryScrForInputMethodAndDone, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_network_edit
 * DESCRIPTION
 *  wlan
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_network_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.inline_setting_cui_id = cui_inline_create(
                                wlan_parent_group_id,
                                &g_edit_inline_struct);

    cui_inline_set_value(
        g_wlan_display_context.inline_setting_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_NAME, 
        g_wlan_display_context.name); 
    
    cui_inline_set_value(
        g_wlan_display_context.inline_setting_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_SSID, 
        g_wlan_display_context.ssid_str); 
	cui_inline_set_title_icon(g_wlan_display_context.inline_setting_cui_id, GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
    
    cui_inline_run(g_wlan_display_context.inline_setting_cui_id);
}



/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_pre_entry_network_edit
 * DESCRIPTION
 *  GPRS account editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_pre_entry_network_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_status_enum wlan_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    modified3 = 0;
    g_wlan_display_context.insert_mode = FALSE;
    g_wlan_display_context.is_to_define_ap = FALSE;
    
    // Get current wlan ps status
    wlan_status = srv_dtcnt_wlan_status();
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#else
    if(g_wlan_display_context.active_wlan_profile_p == NULL)
    {
        return;
    }
    
    if (SRV_DTCNT_WLAN_STATUS_CONNECTED == wlan_status &&
        g_wlan_profile[g_wlan_display_context.active_wlan_profile_index] == g_wlan_display_context.connected_wlan_profile)
    {
        mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_CONNECTING_NO_EDIT)), 
            MMI_EVENT_FAILURE, 
            wlan_parent_group_id,
            NULL);
        return;
    }
    g_wlan_display_context.active_wlan_profile_p = g_wlan_profile[g_wlan_display_context.active_wlan_profile_index];
    /* read proxy info */
    mmi_wlan_dtcnt_query_profile(g_wlan_display_context.active_wlan_profile_p->profile_id, &g_wlan_info_prof);

    mmi_wlan_store_curr_ap_into_cntx(g_wlan_display_context.active_wlan_profile_p);
#endif

}

void mmi_wlan_store_curr_ap_into_cntx(mmi_wlan_profile_struct *active_profile)
{
    memset(g_wlan_display_context.ssid_str, 0, (SRV_DTCNT_PROF_MAX_SSID_LEN + 1)* ENCODING_LENGTH);
    
    if (active_profile->ssid_len > 0)
    {
        custom_wlan_ssid_convert(
            (const char*) active_profile->ssid, 
            (char*) g_wlan_display_context.ssid_str, 
            active_profile->ssid_len);
    }

    g_wlan_display_context.network_type = active_profile->network_type;
    g_wlan_display_context.auth_mode = active_profile->auth_mode;
    g_wlan_display_context.encrypt_mode = active_profile->encrypt_mode;
    g_wlan_display_context.wep_key_index = active_profile->wep_key_index;
    g_wlan_display_context.wep_key_len = active_profile->wep_key_len;
    g_wlan_display_context.wep_key_format = active_profile->wep_key_format;
    g_wlan_display_context.auth_type1 = active_profile->auth_type1;
    g_wlan_display_context.eap_peap_auth_type = active_profile->eap_peap_auth_type;
    g_wlan_display_context.eap_ttls_auth_type = active_profile->eap_ttls_auth_type;
    g_wlan_display_context.channel_number = (S32)active_profile->channel;
    g_wlan_display_context.use_dhcp = active_profile->use_dhcp;
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    g_wlan_display_context.wapi_is_cert_changed = MMI_FALSE;
    g_wlan_display_context.wapi_psk_format = 0;
    g_wlan_display_context.wapi_psk_str[0] = 0;
    g_wlan_display_context.wapi_psk_str[1] = 0;
    g_wlan_display_context.wapi_ase_id = 0;
    g_wlan_display_context.wapi_client_id = 0;
    g_wlan_display_context.wapi_ase_name[0] = 0;
    g_wlan_display_context.wapi_ase_name[1] = 0;
    g_wlan_display_context.wapi_client_name[0] = 0;
    g_wlan_display_context.wapi_client_name[1] = 0;
    g_wlan_display_context.wapi_private_key_passwd_str[0] = 0;
    g_wlan_display_context.wapi_private_key_passwd_str[1] = 0;
#endif /* __MMI_HIDE_WAPI__ */
#endif
    memcpy(g_wlan_display_context.ip_addr, active_profile->ip_addr, 4);
    memcpy(g_wlan_display_context.netmask, active_profile->netmask, 4);
    memcpy(g_wlan_display_context.gateway, active_profile->gateway, 4);
    memcpy(g_wlan_display_context.dns1, active_profile->dns1, 4);
    memcpy(g_wlan_display_context.dns2, active_profile->dns2, 4);

    mmi_ucs2cpy((CHAR*)g_wlan_display_context.name, (const CHAR*)active_profile->name);

    if(active_profile->peap_version & SUPC_PHASE1_PEAP_0)
    {
        g_wlan_display_context.allow_peap0 = TRUE;
    }
    else
    {
        g_wlan_display_context.allow_peap0 = FALSE;
    }

    if(active_profile->peap_version & SUPC_PHASE1_PEAP_1)
    {
        g_wlan_display_context.allow_peap1 = TRUE;
    }
    else
    {
        g_wlan_display_context.allow_peap1 = FALSE;
    }

    memset(g_wlan_display_context.passphrase_str, 0, (SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH);    
    memset(g_wlan_display_context.passphrase, 0, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1);
    if (active_profile->passphrase_len == 32)
    {
	g_wlan_display_context.pass_len = active_profile->passphrase_len;
    }
    else
    {
        active_profile->passphrase_len = strlen(active_profile->passphrase);
        g_wlan_display_context.pass_len = active_profile->passphrase_len;
    }

    if(strlen((char *)active_profile->passphrase) > 0)
    {
        strcpy((char*)g_wlan_display_context.passphrase, (const char*)active_profile->passphrase);
    }
    else
    {
        memcpy(g_wlan_display_context.psk, active_profile->psk, SRV_DTCNT_PROF_MAX_PSK_LEN);
    }

#ifdef __CERTMAN_SUPPORT__
    memset(g_wlan_display_context.client_user_name, 0, (MAX_USERNAME_LEN + 1) *ENCODING_LENGTH);
    mmi_certman_get_cert_label(active_profile->client_ca_id, (U8*)g_wlan_display_context.client_user_name, MAX_USERNAME_LEN *ENCODING_LENGTH);
    memset(g_wlan_display_context.root_ca_name, 0, (MAX_USERNAME_LEN + 1) *ENCODING_LENGTH);
    mmi_certman_get_cert_label(active_profile->root_ca_id, (U8*)g_wlan_display_context.root_ca_name, MAX_USERNAME_LEN *ENCODING_LENGTH);

    g_wlan_display_context.client_ca_id = active_profile->client_ca_id;
    g_wlan_display_context.root_ca_id = active_profile->root_ca_id;

#else
    memset(g_wlan_display_context.client_ca_path, 0, SRV_FMGR_PATH_BUFFER_SIZE);
    mmi_ucs2cpy((CHAR*)g_wlan_display_context.client_ca_path, (const CHAR*)active_profile->client_ca_path);
    memset(g_wlan_display_context.root_ca_path, 0, SRV_FMGR_PATH_BUFFER_SIZE);
    mmi_ucs2cpy((CHAR*)g_wlan_display_context.root_ca_path, (const CHAR*)active_profile->root_ca_path);
    memset(g_wlan_display_context.private_key_path, 0, SRV_FMGR_PATH_BUFFER_SIZE);
    mmi_ucs2cpy((CHAR*)g_wlan_display_context.private_key_path, (const CHAR*)active_profile->private_key_path);
#endif /* __CERTMAN_SUPPORT__ */

#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
#ifdef __CERTMAN_SUPPORT__
    g_wlan_display_context.wapi_ase_id = active_profile->wapi_ase_id;
    g_wlan_display_context.wapi_client_id = active_profile->wapi_client_id;
    memset(g_wlan_display_context.wapi_client_name, 0, (MAX_USERNAME_LEN + 1) *ENCODING_LENGTH);
    mmi_certman_get_cert_label(active_profile->wapi_client_id, (U8*)g_wlan_display_context.wapi_client_name, MAX_USERNAME_LEN *ENCODING_LENGTH);
    memset(g_wlan_display_context.wapi_ase_name, 0, (MAX_USERNAME_LEN + 1) *ENCODING_LENGTH);
    mmi_certman_get_cert_label(active_profile->wapi_ase_id, (U8*)g_wlan_display_context.wapi_ase_name, MAX_USERNAME_LEN *ENCODING_LENGTH);
    if (strlen((const char*)active_profile->wapi_private_key_passwd_str) > 0)
    {
        memset(g_wlan_display_context.wapi_private_key_passwd_str, 0, (MAX_PASSWORD_LEN + 1) *ENCODING_LENGTH);
        mmi_asc_n_to_ucs2(
              g_wlan_display_context.wapi_private_key_passwd_str,
              active_profile->wapi_private_key_passwd_str,
            strlen((const char*)active_profile->wapi_private_key_passwd_str));
    }

#endif
    if(strlen((char *)active_profile->wapi_psk_str) > 0)
    {
        g_wlan_display_context.wapi_psk_format = active_profile->wapi_psk_format;
        memset(g_wlan_display_context.wapi_psk_str, 0, (MAX_WAPI_PSK_LEN + 1) * ENCODING_LENGTH);
        mmi_asc_n_to_ucs2(
            (CHAR*)g_wlan_display_context.wapi_psk_str,
            (CHAR*)active_profile->wapi_psk_str,
            strlen((const char*)active_profile->wapi_psk_str));
    }
#endif /* __MMI_HIDE_WAPI__ */    
#endif
    memset(g_wlan_display_context.wep_key_str, 0, MAX_WEP_KEYSTR_LEN * ENCODING_LENGTH);
    memset(g_wlan_display_context.sel_wep_key_str, 0, MAX_WEP_KEYSTR_LEN * ENCODING_LENGTH);
    if (strlen((const char*)active_profile->wep_key) > 0)
    {
        mmi_asc_n_to_ucs2(
            (CHAR*)g_wlan_display_context.wep_key_str,
            (CHAR*)active_profile->wep_key,
            strlen((const char*)active_profile->wep_key));
        
        mmi_ucs2ncpy (
            (CHAR *)g_wlan_display_context.sel_wep_key_str,
            (const CHAR *)g_wlan_display_context.wep_key_str, 
            mmi_ucs2strlen((const CHAR *)g_wlan_display_context.wep_key_str));
    }

    memset(g_wlan_display_context.private_key_passwd_str, 0, MAX_PASSWORD_LEN * ENCODING_LENGTH);
    if (strlen((const char*)active_profile->private_key_passwd) > 0)
    {
        mmi_asc_n_to_ucs2(
            (CHAR*)g_wlan_display_context.private_key_passwd_str,
            (CHAR*)active_profile->private_key_passwd,
            strlen((const char*)active_profile->private_key_passwd));
    }

    memset(g_wlan_display_context.username_str, 0, MAX_USERNAME_LEN * ENCODING_LENGTH);
    if (strlen((const char*)active_profile->username) > 0)
    {
        mmi_asc_n_to_ucs2(
            (CHAR*)g_wlan_display_context.username_str,
            (CHAR*)active_profile->username,
            strlen((const char*)active_profile->username));
    }

    memset(g_wlan_display_context.password_str, 0, MAX_PASSWORD_LEN * ENCODING_LENGTH);
    if (strlen((const char*)active_profile->password) > 0)
    {
        mmi_asc_n_to_ucs2(
            (CHAR*)g_wlan_display_context.password_str,
            (CHAR*)active_profile->password,
            strlen((const char*)active_profile->password));
    }

    /* set advanced setting */    
    g_wlan_display_context.use_proxy = g_wlan_info_prof.use_proxy;
    g_wlan_display_context.proxy_port= g_wlan_info_prof.px_port;
    
    mmi_asc_to_ucs2((CHAR *)g_wlan_display_context.home_page, (CHAR *)g_wlan_info_prof.HomePage);
    mmi_asc_to_ucs2((CHAR *)g_wlan_display_context.proxy_addr, (CHAR *)g_wlan_info_prof.px_addr);
    mmi_asc_to_ucs2((CHAR *)g_wlan_display_context.proxy_user_name, (CHAR *)g_wlan_info_prof.px_authid);
    mmi_asc_to_ucs2((CHAR *)g_wlan_display_context.proxy_password, (CHAR *)g_wlan_info_prof.px_authpw);
    
    //memcpy(g_wlan_display_context.proxy_ip, g_wlan_info_prof.px_addr, MAX_PART_IP_ADDRESS);

    /* set cursor focus on the first item when enter ttls auth. protocol screen */
    g_wlan_display_context.sel_eap_ttls_auth_type = 0;
    g_wlan_display_context.sel_eap_peap_auth_type = 0;
    // g_wlan_display_context.modified = FALSE;

    mmi_wlan_entry_network_edit();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_get_ip_info
 * DESCRIPTION
 *  Entry connection status screen
 * PARAMETERS
 *  U16 StringId
 *  PU8 ip_info
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_get_ip_info(U16 StringId, PU8 ip_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char tempBufUnicode[MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH];
    char tempBuf[MAX_SUBMENU_CHARACTERS];
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cat((CHAR*) subMenuData, GetString(StringId));
    mmi_ucs2cat((CHAR*) subMenuData, GetString(STR_ID_DTCNT_COLON));
    mmi_ucs2cat((CHAR*) subMenuData, (CHAR*) L"  ");
    sprintf(
        tempBuf,
        "%d.%d.%d.%d\n\n",
        ip_info[0],
        ip_info[1],
        ip_info[2],
        ip_info[3]);
    mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
    mmi_ucs2cat((CHAR*) subMenuData, tempBufUnicode);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_update_conn_status_str
 * DESCRIPTION
 *  Entry connection status screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_update_conn_status_str(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char tempBuf[MAX_SUBMENU_CHARACTERS];
    char tempBufUnicode[MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH];
    CHAR *info;
    srv_dtcnt_wlan_status_enum wlan_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wlan_status = srv_dtcnt_wlan_status();
    info = (CHAR*) subMenuData;

   mmi_ucs2cpy((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_PHONE_MAC));
    if (wlan_status != SRV_DTCNT_WLAN_STATUS_INACTIVE)
    {
        sprintf(
            tempBuf,
            "%02x:%02x:%02x:%02x:%02x:%02x\n\n",
            g_wlan_display_context.mac_addr[0],
            g_wlan_display_context.mac_addr[1],
            g_wlan_display_context.mac_addr[2],
            g_wlan_display_context.mac_addr[3],
            g_wlan_display_context.mac_addr[4],
            g_wlan_display_context.mac_addr[5]);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)tempBufUnicode);
		if (is_insert_disconn == MMI_TRUE)
		{
			return;
		}
    }
    else
    {
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n\n");
    }

    if (SRV_DTCNT_WLAN_STATUS_CONNECTED == wlan_status)
    {
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SSID));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"  ");
        memset(tempBufUnicode, 0, MAX_SUBMENU_CHARACTERS * ENCODING_LENGTH);
        custom_wlan_ssid_convert(
            (const char*) g_wlan_display_context.ssid, 
            (char*) tempBufUnicode, 
            g_wlan_display_context.ssid_len);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)tempBufUnicode);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n\n");

        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"BSSID");
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"  ");
        sprintf(tempBuf, "%02x:%02x:%02x:%02x:%02x:%02x\n\n", g_wlan_display_context.bssid[0], g_wlan_display_context.bssid[1],
        g_wlan_display_context.bssid[2], g_wlan_display_context.bssid[3], g_wlan_display_context.bssid[4],
        g_wlan_display_context.bssid[5]);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)tempBufUnicode);
        
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_CHANNEL));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"  ");
        sprintf(tempBuf, "%d\n\n", g_wlan_display_context.curr_channel_number);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)tempBufUnicode);

        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SIGNAL_STRENGTH));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"  ");
        if (g_wlan_display_context.rssi > -40)
        {
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL0));
        }
        else if (g_wlan_display_context.rssi > -60)
        {
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL1));
        }
        else if (g_wlan_display_context.rssi > -70)
        {
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL2));
        }
        else if (g_wlan_display_context.rssi > -80)
        {
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL3));
        }
        else
        {
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SIGNAL_LEVEL4));
        }
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n\n");

        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_LINK_SPEED));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_COLON));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"  ");
        sprintf(tempBuf, "%d Mbit/s\n\n", g_wlan_display_context.current_data_rate / 2);
        mmi_asc_to_ucs2(tempBufUnicode, tempBuf);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)tempBufUnicode);

	if (g_wlan_display_context.connected_wlan_profile->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC &&
		g_wlan_display_context.use_dhcp == MMI_TRUE)
	{
		memset(g_wlan_display_context.curr_ip_addr, 0, MAX_IPADDRES_LEN);
		memset(g_wlan_display_context.curr_netmask, 0, MAX_IPADDRES_LEN);		
		memset(g_wlan_display_context.curr_gateway, 0, MAX_IPADDRES_LEN);				
		memset(g_wlan_display_context.curr_dns1, 0, MAX_IPADDRES_LEN); 			
		memset(g_wlan_display_context.curr_dns2, 0, MAX_IPADDRES_LEN);
	}

	mmi_wlan_get_ip_info(STR_ID_DTCNT_WLAN_IPADDR, g_wlan_display_context.curr_ip_addr);
	mmi_wlan_get_ip_info(STR_ID_DTCNT_WLAN_NETMASK, g_wlan_display_context.curr_netmask);		
	mmi_wlan_get_ip_info(STR_ID_DTCNT_WLAN_GATEWAY, g_wlan_display_context.curr_gateway);				
	mmi_wlan_get_ip_info(STR_ID_DTCNT_WLAN_DNS1, g_wlan_display_context.curr_dns1);				
	mmi_wlan_get_ip_info(STR_ID_DTCNT_WLAN_DNS2, g_wlan_display_context.curr_dns2);
			
    }
}

//remove for option slim
#if 0
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_pre_entry_tcpip_settings
 * DESCRIPTION
 *  WLAN TCP/IP settings editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_pre_entry_tcpip_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.use_dhcp_dummy = g_wlan_display_context.use_dhcp;

    for (i = 0; i < MAX_IPADDRES_LEN; i++)
    {
        ReturnThreeDigitString((PU8) & g_wlan_display_context.ip_addr_str[i], g_wlan_display_context.ip_addr[i]);
        ReturnThreeDigitString((PU8) & g_wlan_display_context.netmask_str[i], g_wlan_display_context.netmask[i]);
        ReturnThreeDigitString((PU8) & g_wlan_display_context.gateway_str[i], g_wlan_display_context.gateway[i]);
        ReturnThreeDigitString((PU8) & g_wlan_display_context.dns1_str[i], g_wlan_display_context.dns1[i]);
        ReturnThreeDigitString((PU8) & g_wlan_display_context.dns2_str[i], g_wlan_display_context.dns2[i]);
    }

    mmi_wlan_entry_tcpip_settings();
}



void mmi_wlan_set_inline_dhcp_info_attr(mmi_id group_id, U8 use_dhcp)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 operation = CUI_INLINE_RESET_ATTRIBUTE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!use_dhcp)
    {
        operation = CUI_INLINE_RESET_ATTRIBUTE;
    }
    else
    {
        operation = CUI_INLINE_SET_ATTRIBUTE;
    }
    cui_inline_set_item_attributes(
                    group_id,
                    CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_IPADDR,
                    operation,
                    CUI_INLINE_ITEM_DISABLE);
    cui_inline_set_item_attributes(
                    group_id,
                    CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_NETMASK,
                    operation,
                    CUI_INLINE_ITEM_DISABLE);
    cui_inline_set_item_attributes(
                    group_id,
                    CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_GATEWAY,
                    operation,
                    CUI_INLINE_ITEM_DISABLE);
    cui_inline_set_item_attributes(
                    group_id,
                    CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_DNS1,
                    operation,
                    CUI_INLINE_ITEM_DISABLE);
    cui_inline_set_item_attributes(
                    group_id,
                    CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_DNS2,
                    operation,
                    CUI_INLINE_ITEM_DISABLE);   
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_tcpip_settings
 * DESCRIPTION
 *  WLAN TCP/IP settings editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_tcpip_settings(void)
{
    g_wlan_display_context.inline_tcp_ip_cui_id = cui_inline_create(
                                wlan_parent_group_id,
                                &g_tcpip_inline_struct);

	mmi_wlan_set_inline_dhcp_info_attr(
            g_wlan_display_context.inline_tcp_ip_cui_id, 
            g_wlan_display_context.use_dhcp);

    cui_inline_set_value(
        g_wlan_display_context.inline_tcp_ip_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_USEDHCP, 
        (void*)g_wlan_display_context.use_dhcp_dummy); 
    
    cui_inline_set_value(
        g_wlan_display_context.inline_tcp_ip_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_IPADDR, 
        (void*)g_wlan_display_context.ip_addr); 

    cui_inline_set_value(
        g_wlan_display_context.inline_tcp_ip_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_NETMASK, 
        (void*)g_wlan_display_context.netmask); 

    cui_inline_set_value(
        g_wlan_display_context.inline_tcp_ip_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_GATEWAY, 
        (void*)g_wlan_display_context.gateway); 

    cui_inline_set_value(
        g_wlan_display_context.inline_tcp_ip_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_DNS1, 
        (void*)g_wlan_display_context.dns1); 

    cui_inline_set_value(
        g_wlan_display_context.inline_tcp_ip_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_DNS2, 
        (void*)g_wlan_display_context.dns2); 
    
	cui_inline_set_title_icon(g_wlan_display_context.inline_tcp_ip_cui_id, GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
    cui_inline_run(g_wlan_display_context.inline_tcp_ip_cui_id);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_tcpip_settings_usedhcp_highlight_hdlr
 * DESCRIPTION
 *  Highlight handler of local currency inline selection in compute screen.
 * PARAMETERS
 *  index       [IN]        Index of selected item.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_tcpip_settings_usedhcp_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wlan_display_context.use_dhcp != index)
    {
        g_wlan_display_context.use_dhcp = index;
        if (g_wlan_display_context.use_dhcp)
        {
            DisableInlineItem(&wgui_inline_items[WLAN_TCPIP_IPADDR], WLAN_TCPIP_IPADDR);
            DisableInlineItem(&wgui_inline_items[WLAN_TCPIP_NETMASK], WLAN_TCPIP_NETMASK);
            DisableInlineItem(&wgui_inline_items[WLAN_TCPIP_GATEWAY], WLAN_TCPIP_GATEWAY);
            DisableInlineItem(&wgui_inline_items[WLAN_TCPIP_DNS1], WLAN_TCPIP_DNS1);
            DisableInlineItem(&wgui_inline_items[WLAN_TCPIP_DNS2], WLAN_TCPIP_DNS2);
        }
        else
        {
            EnableInlineItem(&wgui_inline_items[WLAN_TCPIP_IPADDR], WLAN_TCPIP_IPADDR);
            EnableInlineItem(&wgui_inline_items[WLAN_TCPIP_NETMASK], WLAN_TCPIP_NETMASK);
            EnableInlineItem(&wgui_inline_items[WLAN_TCPIP_GATEWAY], WLAN_TCPIP_GATEWAY);
            EnableInlineItem(&wgui_inline_items[WLAN_TCPIP_DNS1], WLAN_TCPIP_DNS1);
            EnableInlineItem(&wgui_inline_items[WLAN_TCPIP_DNS2], WLAN_TCPIP_DNS2);
        }

        RedrawCategoryFunction();
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_tcpip_get_addr
 * DESCRIPTION
 *  Get IP address from the CUI.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_FALSE : address value equals 0
 *  MMI_FALSE : address value > 0
 *****************************************************************************/
static MMI_BOOL mmi_wlan_tcpip_get_addr(mmi_id send_id, U16 item_id, U8 *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_item_ip4_struct ip4;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(send_id, item_id, &ip4);
    
    addr[0] = ip4.b1;
    addr[1] = ip4.b2;
    addr[2] = ip4.b3;
    addr[3] = ip4.b4;

    if(0 == (ip4.b1 + ip4.b2 + ip4.b3 + ip4.b4))
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
 *  mmi_wlan_tcpip_settings_save
 * DESCRIPTION
 *  LSK handler for profile editor screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_wlan_tcpip_settings_save(mmi_id send_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 item_id;
    MMI_BOOL is_valid = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_wlan_display_context.use_dhcp == TRUE)
    {
        memset(g_wlan_display_context.ip_addr, 0, MAX_IPADDRES_LEN);
        memset(g_wlan_display_context.netmask, 0, MAX_IPADDRES_LEN);
        memset(g_wlan_display_context.gateway, 0, MAX_IPADDRES_LEN);
        memset(g_wlan_display_context.dns1, 0, MAX_IPADDRES_LEN);
        memset(g_wlan_display_context.dns2, 0, MAX_IPADDRES_LEN);
    }
    else
    {
        item_id = CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_IPADDR;
        if(!mmi_wlan_tcpip_get_addr(send_id, item_id, g_wlan_display_context.ip_addr))
        {
            mmi_popup_display_simple(
                (WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_ERROR_IP_ADDR_ZERO)), 
                MMI_EVENT_FAILURE, 
                wlan_parent_group_id, 
                NULL);
            is_valid = MMI_FALSE;
        }

        item_id = CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_NETMASK;
        mmi_wlan_tcpip_get_addr(send_id, item_id, g_wlan_display_context.netmask);

        item_id = CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_GATEWAY;
        mmi_wlan_tcpip_get_addr(send_id, item_id, g_wlan_display_context.gateway);

        item_id = CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_DNS1;
        mmi_wlan_tcpip_get_addr(send_id, item_id, g_wlan_display_context.dns1);

        item_id = CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_DNS2;
        mmi_wlan_tcpip_get_addr(send_id, item_id, g_wlan_display_context.dns2);
    }

    g_wlan_display_context.modified = TRUE;

    return is_valid;
}

//remove for option slim
#if 0
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_advance_settings
 * DESCRIPTION
 *  WLAN advanced settings editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_advance_settings(void)
{
    U8 operation;

    g_wlan_display_context.wlan_advan_cui_id = cui_inline_create(
                            wlan_parent_group_id,
                            &g_advanced_inline_struct);

    mmi_ucs2cpy ((CHAR *)g_wlan_display_context.home_page_buf, (const CHAR *)g_wlan_display_context.home_page);
    if(mmi_ucs2strlen((const CHAR *)g_wlan_display_context.home_page_buf) == 0)
    {
        mmi_asc_to_ucs2((CHAR*)g_wlan_display_context.home_page_buf, (CHAR*)MMI_DTCNT_DEFAULT_URL);
    }

    cui_inline_set_value(
        g_wlan_display_context.wlan_advan_cui_id, 
        WLAN_ADVAN_HOMEPAGE_FSEDIT_ID, 
        g_wlan_display_context.home_page_buf);
    cui_inline_set_value(
        g_wlan_display_context.wlan_advan_cui_id, 
        WLAN_ADVAN_USER_PROXY_SELECT_ID, 
        (void*)g_wlan_display_context.use_proxy);
    cui_inline_set_value(
        g_wlan_display_context.wlan_advan_cui_id, 
        WLAN_ADVAN_PROXY_ADDR_IP4_ID, 
        g_wlan_display_context.proxy_addr);
    cui_inline_set_value(
        g_wlan_display_context.wlan_advan_cui_id, 
        WLAN_ADVAN_PROXY_PORT_TEXTEDIT_ID, 
        g_wlan_display_context.proxy_port_str);
    cui_inline_set_value(
        g_wlan_display_context.wlan_advan_cui_id, 
        WLAN_ADVAN_PROXY_USERNAME_FSEDIT_ID, 
        g_wlan_display_context.proxy_user_name);    
    cui_inline_set_value(
        g_wlan_display_context.wlan_advan_cui_id, 
        WLAN_ADVAN_PROXY_PASSWD_FSEDIT_ID, 
        g_wlan_display_context.proxy_password);    
    cui_inline_set_title_icon(g_wlan_display_context.wlan_advan_cui_id, GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));

    cui_inline_set_fullscreen_edit_title_icon(
		g_wlan_display_context.wlan_advan_cui_id, 
		WLAN_ADVAN_PROXY_ADDR_IP4_ID, 
		GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
    cui_inline_set_fullscreen_edit_title_icon(
		g_wlan_display_context.wlan_advan_cui_id, 
		WLAN_ADVAN_HOMEPAGE_FSEDIT_ID, 
		GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
	cui_inline_set_fullscreen_edit_title_icon(
		g_wlan_display_context.wlan_advan_cui_id, 
		WLAN_ADVAN_PROXY_USERNAME_FSEDIT_ID, 
		GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
	cui_inline_set_fullscreen_edit_title_icon(
		g_wlan_display_context.wlan_advan_cui_id, 
		WLAN_ADVAN_PROXY_PASSWD_FSEDIT_ID, 
		GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
    operation = (g_wlan_display_context.use_proxy ? CUI_INLINE_RESET_ATTRIBUTE : CUI_INLINE_SET_ATTRIBUTE);
    cui_inline_set_item_attributes(
        g_wlan_display_context.wlan_advan_cui_id,
        WLAN_ADVAN_PROXY_ADDR_IP4_ID,
        operation,
        CUI_INLINE_ITEM_DISABLE);
    cui_inline_set_item_attributes(
        g_wlan_display_context.wlan_advan_cui_id,
        WLAN_ADVAN_PROXY_PORT_TEXTEDIT_ID,
        operation,
        CUI_INLINE_ITEM_DISABLE);
    cui_inline_set_item_attributes(
        g_wlan_display_context.wlan_advan_cui_id,
        WLAN_ADVAN_PROXY_USERNAME_FSEDIT_ID,
        operation,
        CUI_INLINE_ITEM_DISABLE);
    cui_inline_set_item_attributes(
        g_wlan_display_context.wlan_advan_cui_id,
        WLAN_ADVAN_PROXY_PASSWD_FSEDIT_ID,
        operation,
        CUI_INLINE_ITEM_DISABLE);

    cui_inline_run(g_wlan_display_context.wlan_advan_cui_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_pre_entry_advance_settings
 * DESCRIPTION
 *  WLAN TCP/IP settings editing screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_pre_entry_advance_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    U8 temp_buf[12];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    sprintf((char*)temp_buf, "%d", g_wlan_display_context.proxy_port);
    mmi_asc_to_ucs2((CHAR *)g_wlan_display_context.proxy_port_str, (CHAR *)temp_buf);

    for (i = 0; i < MAX_IPADDRES_LEN; i++)
    {
        ReturnThreeDigitString((PU8) & g_wlan_display_context.ip_addr_str[i], g_wlan_display_context.proxy_ip[i]);
    }

    mmi_wlan_entry_advance_settings();
}

/*****************************************************************************
* FUNCTION
*  mmi_wlan_get_advance_setting_value
* DESCRIPTION
 *  Get advanced setting value.
* PARAMETERS
*  mmi_event_struct      [IN]        
* RETURNS
 *  Return MMI_TRUE on success, otherwise return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wlan_get_advance_setting_value(cui_event_inline_submit_struct *submit_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    //cui_inline_item_ip4_struct ip4;
    MMI_BOOL is_valid = MMI_TRUE;
    U8 url_ascii[MAX_ADDRESS_NAME_LEN];
    U8 proxy_url[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */          
    /*----------------------------------------------------------------*/   
    cui_inline_get_value(
        submit_event->sender_id, 
        WLAN_ADVAN_HOMEPAGE_FSEDIT_ID, 
        home_page_temp_buf);
    mmi_chset_ucs2_to_utf8_string((U8*)url_ascii, MAX_ADDRESS_NAME_LEN, (U8*)home_page_temp_buf);
    if (mmi_dtcnt_validate_url((PU8)home_page_temp_buf, MMI_TRUE) < 0 &&
		strcmp(url_ascii, MMI_DTCNT_DEFAULT_URL) != 0)
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_GLOBAL_INVALID_URL),
            MMI_EVENT_ERROR,
            wlan_parent_group_id,
            NULL);

        return MMI_FALSE;
    }
    
    cui_inline_get_value(
        submit_event->sender_id, 
        WLAN_ADVAN_USER_PROXY_SELECT_ID, 
        &use_proxy_temp);

    if(use_proxy_temp == 0)
    {
        
        memset(proxy_addr_temp, 0, (SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1) * ENCODING_LENGTH);        
        memset(proxy_port_str_temp, 0, (MMI_DTCNT_MAX_PORT_LENGTH + 1) * ENCODING_LENGTH);
        memset(proxy_user_name_temp, 0, (MAX_USER_LEN + 1) * ENCODING_LENGTH);
        memset(proxy_password_temp, 0, (MAX_PASSWD_LEN + 1) * ENCODING_LENGTH);
        proxy_port_temp = 0;
    }
    else
    {
        cui_inline_get_value(
            submit_event->sender_id, 
            WLAN_ADVAN_PROXY_ADDR_IP4_ID, 
            proxy_addr_temp);
		mmi_chset_ucs2_to_utf8_string((U8*)proxy_url, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN, (U8*)proxy_addr_temp);
        if (applib_url_is_valid_ext((char*)proxy_url, KAL_TRUE, KAL_FALSE) < 0 ||
			strlen(proxy_url) == 0)
        {
            mmi_popup_display_simple(
				(WCHAR*)GetString(STR_GLOBAL_INVALID_PROXY_SERVER),
				MMI_EVENT_ERROR,
				wlan_parent_group_id,
				NULL);
			return MMI_FALSE;
        }

        
        cui_inline_get_value(
            submit_event->sender_id, 
            WLAN_ADVAN_PROXY_PORT_TEXTEDIT_ID, 
            proxy_port_str_temp);

        is_valid = mmi_wlan_check_advanced_setting(use_proxy_temp, 
                    proxy_port_str_temp);

        if (!is_valid)
        {
            memset(proxy_port_str_temp, 0, (MMI_DTCNT_MAX_PORT_LENGTH + 1) * ENCODING_LENGTH);
            proxy_port_temp = 0;
            use_proxy_temp = 0;
            return is_valid;
        }

        proxy_port_temp = (U32)mmi_wcs_wtoi ((WCHAR *) proxy_port_str_temp);
                
        cui_inline_get_value(
            submit_event->sender_id, 
            WLAN_ADVAN_PROXY_USERNAME_FSEDIT_ID, 
            proxy_user_name_temp);
        
        cui_inline_get_value(
            submit_event->sender_id, 
            WLAN_ADVAN_PROXY_PASSWD_FSEDIT_ID, 
            proxy_password_temp);
    }
    
    g_wlan_display_context.modified = MMI_TRUE;

    return is_valid;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_check_advanced_setting
 * DESCRIPTION
 *  Check the port and proxy address.
 * PARAMETERS
 *  use_proxy    [IN]   use proxy 
 *  port_str     [IN]   port string   
 *  ip           [IN]   ip address.
 * RETURNS
 *  Return MMI_TRUE on success, otherwise return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL mmi_wlan_check_advanced_setting(U8 use_proxy, U8* port_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 temp_val; /* temp value may great than 65535 */
    //U32 ip_sum = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!use_proxy)
    {
        return MMI_TRUE;
    }
        
    if (!mmi_wcslen((WCHAR*)port_str))
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_ID_DTCNT_ERR_MSG_EMPTY_PORT_NUMBER),
            MMI_EVENT_ERROR,
            wlan_parent_group_id,
            NULL);

        return MMI_FALSE;
    }
    
    temp_val = (U32)mmi_wcs_wtoi ((WCHAR *) port_str);

    if (temp_val == 0 || temp_val > MMI_DTCNT_MAX_PORT_NUM)
    {
        mmi_popup_display_simple(
            (WCHAR*)GetString(STR_ID_DTCNT_ERR_MSG_INVALID_PORT),
            MMI_EVENT_ERROR,
            wlan_parent_group_id,
            NULL);

        return MMI_FALSE;
    }

    return MMI_TRUE;
}

//remove for option slim
#if 0
/* under construction !*/
/* under construction !*/
#endif
void mmi_wlan_entry_wlan_prefer_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_valid = MMI_FALSE;
    srv_dtcnt_wlan_prefer_struct* wlan_prefer_settings;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.wlan_prefer_setting_id = cui_inline_create(
                                                        wlan_parent_group_id,
                                                        &g_wlan_settings_inline_struct);
    wlan_prefer_settings = OslMalloc(sizeof(srv_dtcnt_wlan_prefer_struct));
    memset(wlan_prefer_settings, 0, sizeof(srv_dtcnt_wlan_prefer_struct));

    is_valid = srv_dtcnt_get_wlan_prefer_setting(wlan_prefer_settings);
    MMI_ASSERT(is_valid);
    
    cui_inline_set_value (
        g_wlan_display_context.wlan_prefer_setting_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_SETTINGS_AUTO_CONNECT_SELECTOR, 
        (void *)wlan_prefer_settings->is_auto_conn);
#ifdef __CBM_BEARER_SWITCH__
    cui_inline_set_value (
        g_wlan_display_context.wlan_prefer_setting_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_SETTINGS_NETWORK_SWITCH_SELECTOR, 
        (void *)wlan_prefer_settings->network_switch);
#endif
#if 0	
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#else
		cui_inline_set_value (
			g_wlan_display_context.wlan_prefer_setting_id, 
			CUI_INLINE_ITEM_ID_BASE + WLAN_SETTINGS_POWER_SAVE_SELECTOR, 
			(void *)wlan_prefer_settings->sleep_mode);
#endif

    cui_inline_set_title_icon(g_wlan_display_context.wlan_prefer_setting_id, GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
    cui_inline_run (g_wlan_display_context.wlan_prefer_setting_id);

    OslMfree(wlan_prefer_settings);
    wlan_prefer_settings = NULL;
}

void mmi_wlan_get_wlan_prefer_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_valid = MMI_FALSE;
    U8 auto_conn_switch;
    #ifdef __CBM_BEARER_SWITCH__
    U8 network_switch_wlan;
    #endif
	//U8 sleep_mode;
	srv_dtcnt_wlan_sleep_mode_enum sleep_mode;
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
#endif
#endif

    srv_dtcnt_wlan_prefer_struct* wlan_prefer_settings;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(
        g_wlan_display_context.wlan_prefer_setting_id,
        CUI_INLINE_ITEM_ID_BASE + WLAN_SETTINGS_AUTO_CONNECT_SELECTOR,
        &auto_conn_switch);
#ifdef __CBM_BEARER_SWITCH__
    cui_inline_get_value(
        g_wlan_display_context.wlan_prefer_setting_id,
        CUI_INLINE_ITEM_ID_BASE + WLAN_SETTINGS_NETWORK_SWITCH_SELECTOR,
        &network_switch_wlan);
#endif
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#else
		cui_inline_get_value(
			g_wlan_display_context.wlan_prefer_setting_id,
			CUI_INLINE_ITEM_ID_BASE + WLAN_SETTINGS_POWER_SAVE_SELECTOR,
			&sleep_mode);
#endif

    wlan_prefer_settings = OslMalloc(sizeof(srv_dtcnt_wlan_prefer_struct));
    memset(wlan_prefer_settings, 0, sizeof(srv_dtcnt_wlan_prefer_struct));
    wlan_prefer_settings->is_auto_conn = (MMI_BOOL)auto_conn_switch;
#ifdef __CBM_BEARER_SWITCH__
    wlan_prefer_settings->network_switch = network_switch_wlan;
#endif
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif    
#else
		wlan_prefer_settings->sleep_mode= sleep_mode;
#endif 

    is_valid = srv_dtcnt_set_wlan_prefer_setting(wlan_prefer_settings);
    MMI_ASSERT(is_valid);
    
    OslMfree(wlan_prefer_settings);
    wlan_prefer_settings = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_update_signal_level_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_update_signal_level_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_status_enum wlan_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TELEPHONY_SUPPORT__
    if (srv_mode_switch_is_network_service_available() == MMI_FALSE)
    {
        return;
    }
#endif /* __MMI_TELEPHONY_SUPPORT__ */

    wlan_status = srv_dtcnt_wlan_status();

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_SIGNAL_LEVEL, wlan_status);

    if (wlan_status != SRV_DTCNT_WLAN_STATUS_CONNECTED)
    {
        return;
    }

    if (g_wlan_display_context.rssi > -40)
    {
        mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT5, FALSE);
    }
    else if (g_wlan_display_context.rssi > -60)
    {
        mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT4, FALSE);
    }
    else if (g_wlan_display_context.rssi > -70)
    {
        mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT3, FALSE);
    }
    else if (g_wlan_display_context.rssi > -80)
    {
        mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT2, FALSE);
    }
    else
    {
        mmi_wlan_update_status_icon(IMG_ID_DTCNT_WLAN_STATUS_CONNECT1, FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_entry_ipaddr_conflict_ind
 * DESCRIPTION
 *  Entry new message indication
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dtcnt_entry_ipaddr_conflict_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_display_simple(
        (WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_ERROR_IP_CONFLICT)), 
        MMI_EVENT_WARNING, 
        wlan_parent_group_id, 
        NULL);
    
    if ((g_wlan_display_context.notification_pending == FALSE)
        &&(g_wlan_display_context.play_tone_flag))
    {
        g_wlan_display_context.play_tone_flag = FALSE;
        srv_prof_play_tone(SRV_PROF_TONE_WARNING,NULL);
    }
    g_wlan_display_context.notification_pending = FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_refresh_change_priority_list
 * DESCRIPTION
 *  redraw network settings screen
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void mmi_wlan_refresh_change_priority_list(void)
{
    U8  i;
    U16 icon;
    
    for (i = 0; i < g_wlan_display_context.prof_num; i++)
    {
        if(g_wlan_display_context.connected_wlan_profile &&
           g_wlan_profile[i]->profile_id == g_wlan_display_context.connected_wlan_profile->profile_id)
        {
            if (g_wlan_display_context.rssi > -60)
            {
                icon = IMG_ID_DTCNT_WLAN_SIGNAL3;
            }
            else if (g_wlan_display_context.rssi > -70)
            {
                icon = IMG_ID_DTCNT_WLAN_SIGNAL2;
            }
            else if (g_wlan_display_context.rssi > -80)
            {
                icon = IMG_ID_DTCNT_WLAN_SIGNAL1;
            }
            else
            {
                icon = IMG_ID_DTCNT_WLAN_SIGNAL0;
            }
        }
        else 
        {
            icon = 0;
        }

        Category73ChangeItemIcon(i, 0, get_image(icon));
    }

    Category73RedrawScreen();
}

void mmi_wlan_refresh_wizard_main_scrn(void)
{
    U8  i, ap_list_num, se_sa_num = 0, se_num = 0, sa_num = 0;
    U8  highlight_idx;
    U16 signal_icon = 0, type_icon = 0;
    
    mmi_wlan_prepare_wizard_list(&se_num, &sa_num, &se_sa_num);

    ap_list_num = se_num + sa_num + se_sa_num;
    for (i = 0; i < ap_list_num; i++)
    {
        memset(subMenuData[i], 0, MAX_SUB_MENU_SIZE);
        switch (g_wizard_prfile_list[i].type)
        {
            case WLAN_MATCH_SE_SA_C:
            case WLAN_MATCH_SE_SA:
            {
                mmi_ucs2cpy(
                      (CHAR*)subMenuData[i],
                      (const CHAR*)g_wizard_prfile_list[i].p_sa->name);
                subMenuDataPtrs[i] = subMenuData[i];
                switch (g_wizard_prfile_list[i].p_se->network_type)
                {
                    case WNDRV_SUPC_NETWORK_IBSS:
                        type_icon = IMG_ID_DTCNT_WLAN_ADHOC_S;
                        break;
                    default:
                        if (g_wizard_prfile_list[i].p_se->privacy > 0 ||
                            g_wizard_prfile_list[i].p_se->wpa_ie_info_p == KAL_TRUE ||
                            g_wizard_prfile_list[i].p_se->rsn_ie_info_p == KAL_TRUE)
                        {
                            type_icon = IMG_ID_DTCNT_WLAN_SECURED_STATION_S;
                        }
                        else
                        {
                            type_icon = IMG_ID_DTCNT_WLAN_STATION_S;
                        }
                        break;
                }
                if (g_wizard_prfile_list[i].type == WLAN_MATCH_SE_SA)
                {
                    if (g_wizard_prfile_list[i].p_se->rssi > -60)
                    {
                        signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL3;
                    }
                    else if (g_wizard_prfile_list[i].p_se->rssi > -70)
                    {
                        signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL2;
                    }
                    else if (g_wizard_prfile_list[i].p_se->rssi > -80)
                    {
                        signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL1;
                    }
                    else
                    {
                        signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL0;
                    }
                }
                else 
                {
                    if (g_wizard_prfile_list[i].p_se->rssi > -60)
                    {
                        signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL3_CONNECTED;
                    }
                    else if (g_wizard_prfile_list[i].p_se->rssi > -70)
                    {
                        signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL2_CONNECTED;
                    }
                    else if (g_wizard_prfile_list[i].p_se->rssi > -80)
                    {
                        signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL1_CONNECTED;
                    }
                    else
                    {
                        signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL0_CONNECTED;
                    }                    
                }
                break;
            }
            case WLAN_MATCH_SE:
            {
                custom_wlan_ssid_convert(
                    (const char*) g_wizard_prfile_list[i].p_se->ssid, 
                    (char*) subMenuData[i], 
                    g_wizard_prfile_list[i].p_se->ssid_len);
                subMenuDataPtrs[i] = subMenuData[i];
                switch (g_wizard_prfile_list[i].p_se->network_type)
                {
                    case WNDRV_SUPC_NETWORK_IBSS:
                        type_icon = IMG_ID_DTCNT_WLAN_ADHOC;
                        break;
                    default:
                        if (g_wizard_prfile_list[i].p_se->privacy > 0 ||
                            g_wizard_prfile_list[i].p_se->wpa_ie_info_p == KAL_TRUE ||
                            g_wizard_prfile_list[i].p_se->rsn_ie_info_p == KAL_TRUE)
                        {
                            type_icon = IMG_ID_DTCNT_WLAN_SECURED_STATION;
                        }
                        else
                        {
                            type_icon = IMG_ID_DTCNT_WLAN_STATION;
                        }
                        break;
                }
                if (g_wizard_prfile_list[i].p_se->rssi > -60)
                {
                    signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL3;
                }
                else if (g_wizard_prfile_list[i].p_se->rssi > -70)
                {
                    signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL2;
                }
                else if (g_wizard_prfile_list[i].p_se->rssi > -80)
                {
                    signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL1;
                }
                else
                {
                    signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL0;
                }
                break;
            }
            case WLAN_MATCH_SA:
            {
                mmi_ucs2cpy(
                      (CHAR*)subMenuData[i],
                      (const CHAR*)g_wizard_prfile_list[i].p_sa->name);
                subMenuDataPtrs[i] = subMenuData[i];
                switch (g_wizard_prfile_list[i].p_sa->network_type)
                {
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
                        type_icon = IMG_ID_DTCNT_WLAN_ADHOC;
                        break;
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
                        if(g_wizard_prfile_list[i].p_sa->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN &&
                           g_wizard_prfile_list[i].p_sa->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE)
                        {
                            type_icon = IMG_ID_DTCNT_WLAN_STATION;
                        }
                        else
                        {
                            type_icon = IMG_ID_DTCNT_WLAN_SECURED_STATION;
                        }
                        break;
                }
                signal_icon = 0;
                break;
            }
            case WLAN_MATCH_SA_C:
            {
                mmi_ucs2cpy(
                      (CHAR*)subMenuData[i],
                      (const CHAR*)g_wizard_prfile_list[i].p_sa->name);
                subMenuDataPtrs[i] = subMenuData[i];
                switch (g_wizard_prfile_list[i].p_sa->network_type)
                {
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
                        type_icon = IMG_ID_DTCNT_WLAN_ADHOC_S;
                        break;
                    case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
                        if(g_wizard_prfile_list[i].p_sa->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN &&
                           g_wizard_prfile_list[i].p_sa->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE)
                        {
                            type_icon = IMG_ID_DTCNT_WLAN_STATION_S;
                        }
                        else 
                        {
                            type_icon = IMG_ID_DTCNT_WLAN_SECURED_STATION_S;
                        }
                        break;
                    }
                    signal_icon = IMG_ID_DTCNT_WLAN_SIGNAL3_CONNECTED;
                    break;
            } 
        }
	if((g_wlan_display_context.send_conn_req_ing != MMI_FALSE ||
           srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_CONNECT_WAIT ||
	   srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT) &&
	   ( mmi_wlan_get_ui_flow () == MMI_WLAN_UI_CONNECT_BY_CUI ||
	     mmi_wlan_get_ui_flow () == MMI_WLAN_UI_CONNECT_BY_APP ||
	     mmi_wlan_get_ui_flow () == MMI_WLAN_UI_CONNECT_BY_API ))
	{
		DisableLeftSoftkey(STRING_ID_NULL, IMAGE_ID_NULL);
	}
	else
	{
	   	SetLeftSoftkeyFunction(mmi_wlan_entry_wizard_list_opt, KEY_EVENT_UP);
		EnableLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
	}
        Category73ChangeItemIcon(i, 0, get_image(type_icon));
        Category73ChangeItemIcon(i, 1, get_image(signal_icon));
    }
    Category73RedrawScreen();
    // Refresh the highlighted item
    highlight_idx = g_wlan_display_context.wizard_cur_profile_list_index;
    g_wlan_display_context.wizard_list_option = 
        g_wizard_prfile_list[highlight_idx].type;
    if (g_wlan_display_context.wizard_list_option == WLAN_MATCH_SA || 
        g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE_SA ||
        g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE_SA_C ||
        g_wlan_display_context.wizard_list_option == WLAN_MATCH_SA_C)
    {
        g_wlan_display_context.active_wlan_profile_p = g_wizard_prfile_list[highlight_idx].p_sa;
        g_wlan_display_context.active_wlan_profile_index = g_wizard_prfile_list[highlight_idx].priority;
    }
    else if (g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE)
    {
        g_wlan_display_context.active_ap = g_wizard_prfile_list[highlight_idx].p_se;
    }
    
    if (g_wlan_display_context.wizard_list_option == WLAN_MATCH_SE_SA_C ||
        g_wlan_display_context.wizard_list_option == WLAN_MATCH_SA_C)
    {
//#ifndef __MMI_WGUI_DISABLE_CSK__    
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_wlan_entry_network_disconnect, KEY_EVENT_UP);
//#endif        
    }
    else
    {
//#ifndef __MMI_WGUI_DISABLE_CSK__    
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_wlan_entry_wizard_connect, KEY_EVENT_UP);
//#endif        
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_define_network
 * DESCRIPTION
 *  shows the main menu list
 *  
 *  This is used to shows the main menu list of data account
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_define_network(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_wlan_display_context.prof_num == MAX_WLAN_DATA_ACCOUNT_NUM)
    {
        mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_MEMORY_FULL)), MMI_EVENT_FAILURE, wlan_parent_group_id, NULL);
        return;
    }
    g_wlan_display_context.active_wlan_profile_p = &g_wlan_display_context.temp_profile;
    memset(&g_wlan_display_context.temp_profile, 0, sizeof(g_wlan_display_context.temp_profile));
    bssinfo_to_profile(g_wlan_display_context.active_wlan_profile_p, g_wlan_display_context.active_ap, NULL, 0);
    memset(g_wlan_display_context.private_key_passwd_str, 0, sizeof(g_wlan_display_context.private_key_passwd_str));

    mmi_wlan_network_clear_history_data();
    mmi_wlan_save_default_eap_to_display_cntx();
    mmi_wlan_save_default_eap_to_profile(g_wlan_display_context.active_wlan_profile_p);
    
    g_wlan_display_context.insert_mode = TRUE;
    g_wlan_display_context.is_to_define_ap = TRUE;
    g_wlan_display_context.modified = TRUE;
    g_wlan_display_context.wapi_is_auto_connect = MMI_FALSE;
    mmi_wlan_store_curr_ap_into_cntx(g_wlan_display_context.active_wlan_profile_p);
}


/****************************************************************************** 
 * FUNCTION
 *  mmi_wlan_turn_on_confirm_cb
 * DESCRIPTION
 *  popup confirm callback process.
 * PARAMETERS
 *  evt    [IN]  alert event.
 *  
 * RETURNS
 *  Return MMI_RET_OK on success, otherwise return error code.
 ******************************************************************************/
mmi_ret mmi_wlan_turn_on_confirm_cb(mmi_alert_result_evt_struct *evt)
{
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_1:
        case MMI_ALERT_CNFM_2:
        case MMI_ALERT_CNFM_3:
            // handle softkey event here
            break;
        case MMI_ALERT_CNFM_OK:
            // handle softkey event here
            break;

        case MMI_ALERT_CNFM_YES:
            mmi_wlan_enable_entry_main();
            break;

        case MMI_ALERT_CNFM_NO:
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#else
/* under construction !*/
#endif
#else
						mmi_wlan_entry_saved_profile();
#endif

            break;
        }
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wizard_option_off
 * DESCRIPTION
 *  WLAN off
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wizard_option_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_deinit(NULL, NULL);
    mmi_wlan_entry_processing();
	g_wlan_display_context.deinit_when_connected = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wizard_option_on
 * DESCRIPTION
 *  WLAN on
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wizard_option_on(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct popup_property;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(MMI_FALSE == srv_tethering_is_off (SRV_TETHERING_TYPE_WIFI_HS))
    {
        mmi_confirm_property_init(&popup_property, CNFM_TYPE_YESNO);
        popup_property.callback = (mmi_proc_func)mmi_wlan_turn_off_hotspot_confirm;
        popup_property.parent_id = wlan_parent_group_id;
        mmi_confirm_display(
            (WCHAR *)((UI_string_type)GetString(STR_ID_DTCNT_WLAN_TURN_OFF_HOTSPOT_CFM)),  //STR_GLOBAL_CURRENTLY_NOT_AVAILABLE            
            MMI_EVENT_QUERY, 
            &popup_property);
    }
    else
    {
        mmi_wlan_enable_entry_main();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_change_priority
 * DESCRIPTION
 *  To change priority
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_change_priority(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 new_priority = g_wlan_display_context.new_priority;
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#else
/* under construction !*/
#endif
#else
		U8 old_priority = g_wlan_display_context.change_priority_profile_index + 1;
#endif

    srv_dtcnt_result_enum result;
    srv_dtcnt_store_prof_data_struct wlan_prof_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CHANGE_PRIO, old_priority, new_priority);

    if (new_priority == old_priority)
    {
        mmi_frm_scrn_close_active_id();
        return;
    }

    ASSERT(new_priority > 0);
    
    for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
    {
        if (g_wlan_prof_list[i].priority == 0)
        {
            continue;
        }

        if (g_wlan_prof_list[i].priority >= new_priority && g_wlan_prof_list[i].priority < old_priority)
        {
            g_wlan_prof_list[i].priority++;
            
            mmi_wlan_srv2app_profile_convert(&g_srv_wlan_prof, &(g_wlan_prof_list[i]), 0);
            wlan_prof_data.prof_data = &g_srv_wlan_prof;
            wlan_prof_data.prof_fields = (SRV_DTCNT_WLAN_PROF_FIELD_ALL & (~MMI_WLAN_ADVANCE_FIELD));
            wlan_prof_data.prof_type = SRV_DTCNT_BEARER_WIFI;

            result =  srv_dtcnt_store_update_prof(g_srv_wlan_prof.profile_id, &wlan_prof_data);
            
            if (result != SRV_DTCNT_RESULT_SUCCESS) 
            {
                ASSERT(0);
            }

        }
        else if (g_wlan_prof_list[i].priority <= new_priority && g_wlan_prof_list[i].priority > old_priority)
        {
            g_wlan_prof_list[i].priority--;

            ASSERT(g_wlan_prof_list[i].priority > 0);
            
            mmi_wlan_srv2app_profile_convert(&g_srv_wlan_prof, &(g_wlan_prof_list[i]), 0);
            wlan_prof_data.prof_data = &g_srv_wlan_prof;
            wlan_prof_data.prof_fields = (SRV_DTCNT_WLAN_PROF_FIELD_ALL & (~MMI_WLAN_ADVANCE_FIELD));
            wlan_prof_data.prof_type = SRV_DTCNT_BEARER_WIFI;

            result =  srv_dtcnt_store_update_prof(g_srv_wlan_prof.profile_id, &wlan_prof_data);
            
            if (result != SRV_DTCNT_RESULT_SUCCESS) 
            {
                ASSERT(0);
            }

        }
        else if (g_wlan_prof_list[i].priority == old_priority)
        {
            g_wlan_prof_list[i].priority = new_priority;
            mmi_wlan_srv2app_profile_convert(&g_srv_wlan_prof, &(g_wlan_prof_list[i]), 0);
            wlan_prof_data.prof_data = &g_srv_wlan_prof;
            wlan_prof_data.prof_fields = (SRV_DTCNT_WLAN_PROF_FIELD_ALL & (~MMI_WLAN_ADVANCE_FIELD));
            wlan_prof_data.prof_type = SRV_DTCNT_BEARER_WIFI;

            result =  srv_dtcnt_store_update_prof(g_srv_wlan_prof.profile_id, &wlan_prof_data);
            
            if (result != SRV_DTCNT_RESULT_SUCCESS) 
            {
                ASSERT(0);
            }

        }
        g_wlan_profile[g_wlan_prof_list[i].priority - 1] = &g_wlan_prof_list[i];
    }

    g_wlan_display_context.change_priority_profile_index = new_priority - 1;
    g_wlan_display_context.wizard_profile_changed = MMI_TRUE;
    g_wlan_display_context.wizard_priority_changed = MMI_TRUE;

    mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, wlan_parent_group_id, NULL);

    mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_NETWORK_PRIORITY);
    mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_NETWORK_SETTINGS);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wizard_change_priority_handler
 * DESCRIPTION
 *  Slide handler of change priority
 * PARAMETERS
 *  index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wizard_change_priority_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 priority;
    U8 network_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    priority = index;
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#else
/* under construction !*/
#endif
#else
		network_type = g_wlan_profile[g_wlan_display_context.change_priority_profile_index]->network_type;
#endif

    
    if(network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
    {
        if(priority > g_wlan_display_context.infra_prof_num)
        {
            wgui_slide_bar_set_value(g_wlan_display_context.infra_prof_num);

            mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_CHANGE_INFRA_PRIORITY)), MMI_EVENT_FAILURE, wlan_parent_group_id, NULL);

            return;
        }
    }
    else
    {
        if(priority <= g_wlan_display_context.infra_prof_num)
        {
            wgui_slide_bar_set_value(g_wlan_display_context.infra_prof_num + 1);

            mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_CHANGE_ADHOC_PRIORITY)), MMI_EVENT_FAILURE, wlan_parent_group_id, NULL);

            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_network_priority
 * DESCRIPTION
 *  To entry priority change screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_change_priority(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
	S32 low_limit, high_limit;
    S32 *current_value[1];
    void (*cb_func[1]) (S32 value);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

    if (!mmi_frm_scrn_enter(
            wlan_parent_group_id,
            SCR_ID_DTCNT_WLAN_NETWORK_PRIORITY,
            NULL,
            mmi_wlan_entry_change_priority,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_gui_buf(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_NETWORK_PRIORITY);
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#else
/* under construction !*/
#endif
#else
		g_wlan_display_context.new_priority = g_wlan_display_context.change_priority_profile_index + 1;
#endif


    low_limit = 1;
    high_limit = g_wlan_display_context.prof_num;

    current_value[0] = (S32 *)& g_wlan_display_context.new_priority;
    cb_func[0] = mmi_wlan_wizard_change_priority_handler;

    ShowCategory88Screen(
        STR_ID_DTCNT_WLAN_NETWORK_SETTINGS_OPT_PRIORITY,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        0,
        1,
        NULL,
        &low_limit,
        &high_limit,
        current_value,
        cb_func,
        guiBuffer);

    SetKeyHandler(NULL, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(NULL, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
//#ifndef __MMI_WGUI_DISABLE_CSK__    
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_wlan_change_priority, KEY_EVENT_UP);
//#endif    
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(mmi_wlan_change_priority, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_change_priority_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for change priority
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_change_priority_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_display_context.change_priority_profile_p = g_wlan_profile[nIndex];
    g_wlan_display_context.change_priority_profile_index = nIndex;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_change_priority_profile_list
 * DESCRIPTION
 *  To entry saved WLAN profile list
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_change_priority_profile_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 *guiBuffer = NULL;
    U8 *DataAccountName[MAX_WLAN_DATA_ACCOUNT_NUM];
    U16 icon_list[MAX_WLAN_DATA_ACCOUNT_NUM];
    U16 icon_state[MAX_WLAN_DATA_ACCOUNT_NUM];
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    if(g_wlan_display_context.prof_num == 0)
    {
        return;
    }

    for (i = 0; i < g_wlan_display_context.prof_num; i++)
    {
        DataAccountName[i] = g_wlan_profile[i]->name;
        
        if(g_wlan_profile[i]->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC)
        {
            icon_list[i] = IMG_ID_DTCNT_WLAN_ADHOC;
        }
        else
        {
            if(g_wlan_profile[i]->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN &&
               g_wlan_profile[i]->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE)
            {			   
                icon_list[i] = IMG_ID_DTCNT_WLAN_STATION;			 
            }
            else
            {
                icon_list[i] = IMG_ID_DTCNT_WLAN_SECURED_STATION;			 
            }
        }
			
        if(g_wlan_display_context.connected_wlan_profile &&
           g_wlan_profile[i]->profile_id == g_wlan_display_context.connected_wlan_profile->profile_id)
        {
            if (g_wlan_display_context.rssi > -60)
            {
            	icon_state[i] = IMG_ID_DTCNT_WLAN_SIGNAL3;
            }
            else if (g_wlan_display_context.rssi > -70)
            {
                icon_state[i] = IMG_ID_DTCNT_WLAN_SIGNAL2;
            }
            else if (g_wlan_display_context.rssi > -80)
            {
                icon_state[i] = IMG_ID_DTCNT_WLAN_SIGNAL1;
            }
            else
            {
                icon_state[i] = IMG_ID_DTCNT_WLAN_SIGNAL0;
            }
        }
        else 
        {
            icon_state[i] = 0;
        }
    }
	
    /* Reset insert mode here */
    g_wlan_display_context.insert_mode = FALSE;
    if (!mmi_frm_scrn_enter(
            wlan_parent_group_id,
            SCR_ID_DTCNT_WLAN_WIZARD_CHANGE_PRIORITY_LIST,
            NULL,
            mmi_wlan_entry_change_priority_profile_list,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }    

    guiBuffer = mmi_frm_scrn_get_gui_buf(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WIZARD_CHANGE_PRIORITY_LIST);
    
    if(!guiBuffer || g_wlan_display_context.wizard_priority_changed)
    {
        g_wlan_display_context.wizard_priority_changed = MMI_FALSE;
        g_wlan_display_context.active_wlan_profile_index = 0;
        guiBuffer = 0;
    }
    
    RegisterHighlightHandler(mmi_wlan_change_priority_highlight_hdlr);
    ShowCategory73Screen(
    STR_ID_DTCNT_WLAN_NETWORK_SETTINGS,
    GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
    STR_GLOBAL_OK,
    IMG_GLOBAL_OK,
    STR_GLOBAL_BACK,
    IMG_GLOBAL_BACK,
    g_wlan_display_context.prof_num,
    (U8 **) DataAccountName,
    icon_state,
    icon_list,
    g_wlan_display_context.active_wlan_profile_index,
    guiBuffer,
    ICON_ICON_TEXT);
//#ifndef __MMI_WGUI_DISABLE_CSK__    
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_wlan_entry_change_priority, KEY_EVENT_UP);
//#endif
    SetLeftSoftkeyFunction(mmi_wlan_entry_change_priority, KEY_EVENT_UP);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

//remove for option slim
#if 0
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_set_wapi_test_mode
 * DESCRIPTION
 *  Set WAPI test mode
 * PARAMETERS
 *  MMI_BOOL
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_set_wapi_test_mode(MMI_BOOL wapi_test_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    S16 error;
    srv_dtcnt_prof_wlan_struct* wlan_profile;
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    wlan_profile = OslMalloc(sizeof(srv_dtcnt_prof_wlan_struct));
    memset(wlan_profile, 0, sizeof(srv_dtcnt_prof_wlan_struct));
    wlan_profile->use_dhcp = wapi_test_mode;

    if(WriteRecord(NVRAM_EF_WLAN_PROFILE_LID, 
                    (U16) MAX_WLAN_DATA_ACCOUNT_NUM + 1, 
                    (void*) wlan_profile, 
                    NVRAM_MAX_WLAN_PROFILE_SIZE, 
                    (S16 *) &error) < NVRAM_MAX_WLAN_PROFILE_SIZE)
    {
        MMI_ASSERT(0);
    }

    OslMfree(wlan_profile);
    wlan_profile = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_get_wapi_test_mode
 * DESCRIPTION
 *  Get WAPI test mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_wlan_get_wapi_test_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    S16 error;
    MMI_BOOL wapi_test_mode;
    srv_dtcnt_prof_wlan_struct *wlan_profile;
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    wlan_profile = OslMalloc(sizeof(srv_dtcnt_prof_wlan_struct));
    memset(wlan_profile, 0, sizeof(srv_dtcnt_prof_wlan_struct));

    if(ReadRecord(NVRAM_EF_WLAN_PROFILE_LID, 
                    (U16) MAX_WLAN_DATA_ACCOUNT_NUM + 1, 
                    (void*) wlan_profile, 
                    NVRAM_MAX_WLAN_PROFILE_SIZE, 
                    (S16 *) &error) < NVRAM_MAX_WLAN_PROFILE_SIZE)
    {
        MMI_ASSERT(0);
    }

    wapi_test_mode = wlan_profile->use_dhcp;

    return wapi_test_mode;
}

//remove for option slim
#if 0
/* under construction !*/
/* under construction !*/
#endif
void mmi_wlan_set_ui_flow(mmi_wlan_ui_flow_enum flow)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CMCC_UI_STATUS_MACHINE, g_wlan_display_context.ui_flow, flow);
    g_wlan_display_context.ui_flow = flow;
}

mmi_wlan_ui_flow_enum mmi_wlan_get_ui_flow(void)
{
    return g_wlan_display_context.ui_flow;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wizard_option_highlight_priority
 * DESCRIPTION
 *  Highlight priority
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wizard_option_highlight_priority(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_status_enum wlan_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wlan_status = srv_dtcnt_wlan_status();

    if (wlan_status == SRV_DTCNT_WLAN_STATUS_INACTIVE)
    {
        SetLeftSoftkeyFunction(mmi_wlan_entry_change_priority, KEY_EVENT_UP);
    }
    else
    {
        SetLeftSoftkeyFunction(mmi_wlan_entry_change_priority_profile_list, KEY_EVENT_UP);
    }
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wizard_option_change_priority
 * DESCRIPTION
 *  Highlight priority
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wizard_option_change_priority(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//#ifndef __MMI_OP01_WIFI__
    srv_dtcnt_wlan_status_enum wlan_status;
//#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#else
/* under construction !*/
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
#else
    wlan_status = srv_dtcnt_wlan_status();

    if (wlan_status == SRV_DTCNT_WLAN_STATUS_INACTIVE)
    {
        mmi_wlan_entry_change_priority();
    }
    else
    {
        mmi_wlan_entry_change_priority_profile_list();
    }
#endif

}

void mmi_wlan_close_menu_cui(mmi_id *gid)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CLOSE_MENU_CUI, *gid);
    if(*gid != GRP_ID_INVALID)
    {
        cui_menu_close(*gid);
        *gid = GRP_ID_INVALID;
    }
}

void mmi_wlan_close_inline_cui(mmi_id *gid)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CLOSE_INLINE_CUI, *gid);
    if(*gid != GRP_ID_INVALID)
    {
        cui_inline_close(*gid);
        *gid = GRP_ID_INVALID;
    }
}

#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wapi_change_test_modes
 * DESCRIPTION
 *  To change the test mode configuration
 * PARAMETERS
 *  void   
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wapi_change_test_mode(void)
{
    U8 i;
    S16 error;
    if (g_wapi_test_mode)
    {
        g_wapi_test_mode = MMI_FALSE;	
    }
    else
    {
        g_wapi_test_mode = MMI_TRUE;
    }
    
    /* To clear all WLAN profile */
    for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
    {
        memset(&g_wlan_prof_list[i], 0, sizeof(mmi_wlan_profile_struct));
        if (WriteRecord(
                NVRAM_EF_WLAN_PROFILE_LID, 
                (U16)(i + 1), 
                (void*)&g_wlan_prof_list[i], 
                NVRAM_MAX_WLAN_PROFILE_SIZE, 
                &error) < NVRAM_MAX_WLAN_PROFILE_SIZE)
        {
            ASSERT(0);
        }
    }
    g_wlan_display_context.prof_num = 0;
    g_wlan_display_context.infra_prof_num = 0;
    g_wlan_display_context.adhoc_prof_num = 0;

    mmi_wlan_wapi_test_mode_switch();
}


#ifdef __CERTMAN_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_select_cert_rsp
 * DESCRIPTION
 *  Callback function when finish selecting an file for attachment
 * PARAMETERS
 *  filePath        [IN]       
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wapi_select_ase_cert_rsp(void *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_select_cert_rsp_struct *cert_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ClearProtocolEventHandler(MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);

    cert_rsp = (mmi_certman_select_cert_rsp_struct *)rsp;
    
    if(cert_rsp->result)
    {
        g_wlan_display_context.wapi_ase_id = cert_rsp->cert_ids[0];
        g_wlan_display_context.wapi_is_cert_changed = MMI_TRUE;
        mmi_certman_get_cert_label(g_wlan_display_context.wapi_ase_id, (U8*)g_wlan_display_context.wapi_ase_name, MAX_USERNAME_LEN *ENCODING_LENGTH);
        mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);

    }  
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_wapi_select_user_cert_rsp
 * DESCRIPTION
 *  Callback function when finish selecting an file for attachment
 * PARAMETERS
 *  filePath        [IN]        
 *  is_short        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_wapi_select_user_cert_rsp(void *rsp)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_select_cert_rsp_struct *cert_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(MSG_ID_MMI_CERTMAN_SELECT_CERT_RSP);
    cert_rsp = (mmi_certman_select_cert_rsp_struct *)rsp;
    
    if(cert_rsp->result)
    {
        g_wlan_display_context.wapi_client_id = cert_rsp->cert_ids[0];
        g_wlan_display_context.wapi_is_cert_changed = MMI_TRUE;
        mmi_certman_get_cert_label(g_wlan_display_context.wapi_client_id, (U8*)g_wlan_display_context.wapi_client_name, MAX_USERNAME_LEN *ENCODING_LENGTH);
        mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, GRP_ID_ROOT, NULL);

    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_wapi_cert_settings
 * DESCRIPTION
 *  entry wapi cert settings
 * PARAMETERS
 *  void 
 * RETURNS
 *  U8
 *****************************************************************************/
void mmi_wlan_entry_wapi_cert_settings(void)
{
    g_wlan_display_context.inline_wapi_cert_cui_id = cui_inline_create(
                                wlan_parent_group_id,
                                &g_wapi_cert_inline_struct);
    cui_inline_set_value(
        g_wlan_display_context.inline_wapi_cert_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WAPI_EDIT_PRIV_KEY_PASSWD, 
        g_wlan_display_context.wapi_private_key_passwd_str);
    cui_inline_set_title_icon(g_wlan_display_context.inline_wapi_cert_cui_id, GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));

    cui_inline_set_fullscreen_edit_title_icon(g_wlan_display_context.inline_wapi_cert_cui_id,
                                              CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WAPI_EDIT_PRIV_KEY_PASSWD, 
                                              GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));

    cui_inline_run(g_wlan_display_context.inline_wapi_cert_cui_id);
}

MMI_BOOL mmi_wlan_verify_wapi_pre_shared_key(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_valid = MMI_FALSE;
    U8  wapi_wep_key[MAX_WAPI_PSK_LEN + 1];
    S32 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc((CHAR*)wapi_wep_key, (CHAR*)g_wlan_display_context.wapi_psk_str);
    length = mmi_ucs2strlen((const CHAR *)g_wlan_display_context.wapi_psk_str);
    
    if (g_wlan_display_context.wapi_psk_format == 0)
    {
        if (is_valid_hexstring(wapi_wep_key, length))
        {
            is_valid = MMI_TRUE;
        }
    }
    else if(g_wlan_display_context.wapi_psk_format == 1)
    {
        if (is_valid_ascii_string(wapi_wep_key, length))
        {
            is_valid = MMI_TRUE;
        }
    }

    return is_valid;
}

void mmi_wlan_wapi_save_or_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    mmi_wlan_profile_struct *prof;
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    if (MMI_TRUE == g_wlan_display_context.wapi_is_auto_connect)
    {
        g_wlan_display_context.wapi_is_auto_connect = MMI_FALSE;
        if (!wndrv_chip_isOK())
        {
            mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_ERROR_INIT_FAIL)), MMI_EVENT_FAILURE, wlan_parent_group_id, NULL);
            return;
        }
        prof = &g_wlan_display_context.temp_profile;
        memset(&g_wlan_display_context.temp_profile, 0, sizeof(g_wlan_display_context.temp_profile));
        bssinfo_to_profile(prof, &g_wlan_hilt_profile, NULL, 0);
#ifdef __CERTMAN_SUPPORT__
        if (prof->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT)
        {
            prof->wapi_ase_id = g_wlan_display_context.wapi_ase_id;
            prof->wapi_client_id = g_wlan_display_context.wapi_client_id;
            mmi_ucs2_to_asc((CHAR*)prof->wapi_private_key_passwd_str, (CHAR*)g_wlan_display_context.wapi_private_key_passwd_str);
        }
#endif
        if (prof->auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK)
        {
            mmi_ucs2_to_asc((CHAR*)prof->wapi_psk_str, (CHAR*)g_wlan_display_context.wapi_psk_str);
            prof->wapi_psk_format = g_wlan_display_context.wapi_psk_format;
        }
        
        g_wlan_display_context.pre_connect_by_always_ask = MMI_FALSE;
        mmi_wlan_entry_abortable_processing();
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WAPI_PSK_INPUT);
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_WAPI_CERT_INPUT);
        mmi_wlan_send_connect_request(prof);

        g_wlan_display_context.modified = TRUE;
    }
    else
    {
        g_wlan_display_context.modified = TRUE;

    }
#endif /*__MMI_HIDE_WAPI__ */
#else
    {
        g_wlan_display_context.modified = TRUE;
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_wapi_psk_settings
 * DESCRIPTION
 *  entry auth mode screen for wapi test mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_wapi_psk_settings(void)
{
    g_wlan_display_context.inline_wapi_psk_cui_id = cui_inline_create(
                                wlan_parent_group_id,
                                &g_wapi_psk_inline_struct);

    cui_inline_set_value(
        g_wlan_display_context.inline_wapi_psk_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WAPI_PSK_EDIT_KEY_FORMAT, 
        (void*)g_wlan_display_context.wapi_psk_format); 
    
    cui_inline_set_value(
        g_wlan_display_context.inline_wapi_psk_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WAPI_PSK_EDIT_KEY, 
        g_wlan_display_context.wapi_psk_str); 
    cui_inline_set_title_icon(g_wlan_display_context.inline_wapi_psk_cui_id, GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));

    cui_inline_set_fullscreen_edit_title_icon(g_wlan_display_context.inline_wapi_cert_cui_id,
                                              CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WAPI_PSK_EDIT_KEY, 
                                              GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));

    cui_inline_run(g_wlan_display_context.inline_wapi_psk_cui_id);

}



/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_auth_mode_wapi_test_mode
 * DESCRIPTION
 *  entry auth mode screen for wapi test mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_auth_mode_wapi_test_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *nStrList[SRV_DTCNT_WLAN_AUTH_MODE_TOTAL];
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            g_wlan_display_context.inline_setting_cui_id,
            SCR_ID_DTCNT_WLAN_NETWORK_AUTH_MODE,
            NULL,
            mmi_wlan_entry_auth_mode,
            MMI_FRM_FULL_SCRN))
    {
        return;
    } 

    guiBuffer = mmi_frm_scrn_get_gui_buf(g_wlan_display_context.inline_setting_cui_id, SCR_ID_DTCNT_WLAN_NETWORK_AUTH_MODE);
    SetParentHandler(0);
    RegisterHighlightHandler(mmi_wlan_auth_mode_highlight_hdlr);

    nStrList[i++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_OPEN);

    if(g_wlan_display_context.network_type != SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC)
    {
    #ifdef __WAPI_SUPPORT__     
    #ifndef __MMI_HIDE_WAPI__
        nStrList[i++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WAPICERT);
        nStrList[i++] = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WAPIPSK);
    #endif /* __MMI_HIDE_WAPI__ */
    #endif
    }

    ShowCategory109Screen(
        STR_ID_DTCNT_WLAN_AUTH_MODE,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        i,
        nStrList,
        NULL,
        g_wlan_display_context.sel_auth_mode,
        guiBuffer);
	ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
	SetCenterSoftkeyFunction(mmi_wlan_auth_mode_ok_wapi_test_mode, KEY_EVENT_UP);
    /* Register function with left/right softkey */
    SetLeftSoftkeyFunction(mmi_wlan_auth_mode_ok_wapi_test_mode, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_auth_mode_ok_wapi_test_mode
 * DESCRIPTION
 *  auth mode ok function
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_auth_mode_ok_wapi_test_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_auth_mode_enum new_auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_OPEN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_wlan_display_context.network_type != SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC)
    {
        switch (g_wlan_display_context.sel_auth_mode)
        {
            case 0:
                new_auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_OPEN;
                break;
            case 1:
                new_auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT;
                break;
            case 2:
                new_auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK;
                break;
        }
    }
    else
    {
        new_auth_mode = SRV_DTCNT_WLAN_AUTH_MODE_OPEN;
    }
    if (g_wlan_display_context.auth_mode != new_auth_mode)
    {
        if (g_wlan_display_context.network_type != SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC)
        {
            switch (g_wlan_display_context.auth_mode)
            {
                case SRV_DTCNT_WLAN_AUTH_MODE_OPEN:
            #ifdef __WAPI_SUPPORT__
            #ifndef __MMI_HIDE_WAPI__
                    if (new_auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT || 
                        new_auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK)
                    {
                        g_wlan_display_context.encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_WPI;
                    }
            #endif /* __MMI_HIDE_WAPI__ */
            #endif
                    break;
    
        #ifdef __WAPI_SUPPORT__
        #ifndef __MMI_HIDE_WAPI__
                case SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT:
                case SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK:
                    if (new_auth_mode == SRV_DTCNT_WLAN_AUTH_MODE_OPEN)
                    {
                        g_wlan_display_context.encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE;
                    }
                    break;
        #endif /* __MMI_HIDE_WAPI__ */
        #endif
            }
        }
		else
        {
            g_wlan_display_context.encrypt_mode = SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE;
        }
        g_wlan_display_context.modified = TRUE;
    }

    g_wlan_display_context.auth_mode = new_auth_mode;

    mmi_frm_scrn_close_active_id();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_network_edit_fill_inline_struct_wapi_test_mode
 * DESCRIPTION
 *  fill inline structure for wapi test mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_network_edit_fill_inline_struct_wapi_test_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *pString = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Network Name Caption */
    SetInlineItemCaption(&wgui_inline_items[WLAN_NETWORK_EDIT_NAME_STR], (U8*) GetString(STR_ID_DTCNT_WLAN_NAME));

    /* Network Name */
    SetInlineItemActivation(&wgui_inline_items[WLAN_NETWORK_EDIT_NAME], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext2(
        &wgui_inline_items[WLAN_NETWORK_EDIT_NAME],
        STR_ID_DTCNT_WLAN_NAME,
#if 0
#ifdef __WIFI_WIZARD_SUPPORT__
/* under construction !*/
#else
/* under construction !*/
#endif
#else
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
#endif
        (U8*) (g_wlan_display_context.name),
        MAX_WLAN_PROF_NAME_LEN,
        IMM_INPUT_TYPE_SENTENCE /*| INPUT_TYPE_USE_ENCODING_BASED_LENGTH*/,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        NULL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[WLAN_NETWORK_EDIT_NAME], mmi_wlan_fullline_edit_screen);

    /* SSID Caption */
    SetInlineItemCaption(&wgui_inline_items[WLAN_NETWORK_EDIT_SSID_STR], (U8*) GetString(STR_ID_DTCNT_WLAN_SSID));

    /* SSID */
    SetInlineItemActivation(&wgui_inline_items[WLAN_NETWORK_EDIT_SSID], KEY_LSK, KEY_EVENT_UP);
    SetInlineItemFullScreenEdit_ext2(
        &wgui_inline_items[WLAN_NETWORK_EDIT_SSID],
        STR_ID_DTCNT_WLAN_SSID,
#if 0
#ifdef __WIFI_WIZARD_SUPPORT__
/* under construction !*/
#else
/* under construction !*/
#endif
#else
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
#endif
        (U8*) (g_wlan_display_context.ssid_str),
        SRV_DTCNT_PROF_MAX_SSID_LEN + 1,
        IMM_INPUT_TYPE_ASCII_CHAR,
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        NULL);
    SetInlineFullScreenEditCustomFunction(&wgui_inline_items[WLAN_NETWORK_EDIT_SSID], mmi_wlan_fullline_edit_screen);

    /* Operation Mode Caption */
    SetInlineItemCaption(
        &wgui_inline_items[WLAN_NETWORK_EDIT_NETWORK_TYPE_STR],
        (U8*) GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE));

    switch (g_wlan_display_context.network_type)
    {
        case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE_INFRA);
            break;
        case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE_ADHOC);
            break;
    }

    /* Operation Mode */
    SetInlineItemActivation(
        &wgui_inline_items[WLAN_NETWORK_EDIT_NETWORK_TYPE],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemDisplayOnly(
        &wgui_inline_items[WLAN_NETWORK_EDIT_NETWORK_TYPE],
        (U8*) pString);         

    switch (g_wlan_display_context.auth_mode)
    {
        case SRV_DTCNT_WLAN_AUTH_MODE_OPEN:
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_OPEN);
            break;
    #ifdef __WAPI_SUPPORT__
    #ifndef __MMI_HIDE_WAPI__
         case SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT:
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WAPICERT);
            break;
         case SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK:
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WAPIPSK);
            break;
    #endif /* __MMI_HIDE_WAPI__ */
    #endif
    }

    /* Authentication Mode Caption */
    SetInlineItemCaption(
        &wgui_inline_items[WLAN_NETWORK_EDIT_AUTH_MODE_STR],
        (U8*) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE));

    /* Authentication Mode */
    SetInlineItemActivation(&wgui_inline_items[WLAN_NETWORK_EDIT_AUTH_MODE], INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT, 0);
    SetInlineItemDisplayOnly(
        &wgui_inline_items[WLAN_NETWORK_EDIT_AUTH_MODE],
        (U8*)pString);

    switch (g_wlan_display_context.encrypt_mode)
    {
        case SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE:
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_ENCRYPT_MODE_NONE);
            break;
    #ifdef __WAPI_SUPPORT__
    #ifndef __MMI_HIDE_WAPI__
        case SRV_DTCNT_WLAN_ENCRYPT_MODE_WPI:
           pString = (PU8) GetString(STR_ID_DTCNT_WLAN_ENCRYPT_MODE_WPI);
           break;
    #endif /* __MMI_HIDE_WAPI__ */
    #endif	
    }
    /* Security Settings */
    SetInlineItemActivation(
        &wgui_inline_items[WLAN_NETWORK_EDIT_SECURITY_SETTINGS],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemDisplayOnly(
        &wgui_inline_items[WLAN_NETWORK_EDIT_SECURITY_SETTINGS],
        (U8*) GetString(STR_ID_DTCNT_WLAN_SECURITY_SETTINGS));

    switch (g_wlan_display_context.auth_mode)
    {
    #ifdef __WAPI_SUPPORT__
    #ifndef __MMI_HIDE_WAPI__
        case SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK:
            SetInlineItemDisplayOnly(
                &wgui_inline_items[WLAN_NETWORK_EDIT_SECURITY_SETTINGS],
                (U8*) GetString(STR_ID_DTCNT_WLAN_WAPI_PSK_SETTINGS));
            break;
        case SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT:
            SetInlineItemDisplayOnly(
                &wgui_inline_items[WLAN_NETWORK_EDIT_SECURITY_SETTINGS],
                (U8*) GetString(STR_ID_DTCNT_WLAN_WAPI_CERT_SETTINGS));
            break;
    #endif /* __MMI_HIDE_WAPI__ */
    #endif 
        default:
            SetInlineItemDisplayOnly(
                    &wgui_inline_items[WLAN_NETWORK_EDIT_SECURITY_SETTINGS],
                    (U8*) GetString(STR_ID_DTCNT_WLAN_ERROR_NO_AUTH_SETTING));
                DisableInlineItem(&wgui_inline_items[WLAN_NETWORK_EDIT_SECURITY_SETTINGS], WLAN_NETWORK_EDIT_SECURITY_SETTINGS);
            break;
    }
    /* TCP/IP Settings */
    SetInlineItemActivation(
        &wgui_inline_items[WLAN_NETWORK_EDIT_TCPIP_SETTINGS],
        INLINE_ITEM_ACTIVATE_WITHOUT_KEY_EVENT,
        0);
    SetInlineItemDisplayOnly(
        &wgui_inline_items[WLAN_NETWORK_EDIT_TCPIP_SETTINGS],
        (U8*) GetString(STR_ID_DTCNT_WLAN_TCPIP_SETTINGS));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_pre_entry_auth_mode_wapi_test_mode
 * DESCRIPTION
 *  pre enter auth mode for wapi test mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_pre_entry_auth_mode_wapi_test_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_wlan_display_context.network_type != SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC)
    {
        switch(g_wlan_display_context.auth_mode)
        {
        case SRV_DTCNT_WLAN_AUTH_MODE_OPEN:
            g_wlan_display_context.sel_auth_mode = 0;
            break;
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
        case SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT:
            g_wlan_display_context.sel_auth_mode = 1;
            break;
        case SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK:
            g_wlan_display_context.sel_auth_mode = 2;
            break;        
#endif /* __MMI_HIDE_WAPI__ */
#endif
        default:
            ASSERT(0);
        }
    }
    else
    {
        g_wlan_display_context.sel_auth_mode = 0;
    }
    mmi_wlan_entry_auth_mode_wapi_test_mode();
}
#endif /* __MMI_HIDE_WAPI__ */    
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_save_connected_ap
 * DESCRIPTION
 *  To save the connected profile. 
 * PARAMETERS
 *  connected_ap        [IN]     connected AP.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_save_connected_ap(supc_abm_bss_info_struct *connected_ap)
{
    mmi_wlan_profile_struct *active_profile;
    U8 i, j;
	U8 index = 0, priority = 0;
	U32 profile_id = 0;
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    char passphrase[SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1] = "";
#endif
#endif
    U32 lowest_priority_index;
    U32 highest_priority_index;
    U32 add_ap = MMI_TRUE;
    U32 fields = SRV_DTCNT_WLAN_PROF_FIELD_ALL;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_SAVE_CONN_AP);

    memset(&g_wlan_info_prof, 0, sizeof(g_wlan_info_prof));

    // g_wlan_display_context.active_wlan_profile_p = &g_wlan_display_context.temp_profile;
    active_profile = &g_wlan_display_context.temp_profile;

    mmi_asc_to_ucs2((CHAR*)g_wlan_display_context.username_str, (CHAR*)active_profile->username);
    mmi_asc_to_ucs2((CHAR*)g_wlan_display_context.password_str, (CHAR*)active_profile->password);

#ifndef __WAPI_SUPPORT__
    bssinfo_to_profile(active_profile, connected_ap, (char*)g_wlan_display_context.psk, (int)g_wlan_display_context.keylen);
#else
#ifndef __MMI_HIDE_WAPI__
    if (connected_ap->wapi_ie_info_p)
    {
        if (connected_ap->wapi_ie_info.key_mgmt & WAPI_KEY_MGMT_PSK)
        {
            mmi_ucs2_to_asc((CHAR*)passphrase, (CHAR*)g_wlan_display_context.wapi_psk_str);
            bssinfo_to_profile(active_profile, connected_ap, (char*)passphrase, (int)g_wlan_display_context.wapi_psk_format);
        }
        else if (connected_ap->wapi_ie_info.key_mgmt & MMI_WLAN_WAPI_KEY_MGMT_WAI)
        {
            mmi_ucs2_to_asc((CHAR*)passphrase, (CHAR*)g_wlan_display_context.wapi_private_key_passwd_str);
            bssinfo_to_profile(active_profile, connected_ap, (char*)passphrase, 0);
        }
    }
    else
    {
        bssinfo_to_profile(active_profile, connected_ap, (char*)g_wlan_display_context.psk, (int)g_wlan_display_context.keylen);
    }
#else
    bssinfo_to_profile(active_profile, connected_ap, (char*)g_wlan_display_context.psk, (int)g_wlan_display_context.keylen);
#endif /* __MMI_HIDE_WAPI__ */
#endif
    mmi_wlan_save_default_eap_to_profile(active_profile);

    /* Find an empty slot index first */
    for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
    {
        if (g_wlan_prof_list[i].ssid_len == 0 && g_wlan_prof_list[i].profile_id == 0)
        {
            break;
        }
    }
    /* If there is no empty slot, replay a same-type one, if no same type, not replace */
    if (i == MAX_WLAN_DATA_ACCOUNT_NUM)
    {
        add_ap = MMI_FALSE;
        fields = (SRV_DTCNT_WLAN_PROF_FIELD_ALL & (~MMI_WLAN_ADVANCE_FIELD));

        for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
        {
            if (active_profile->network_type == g_wlan_profile[i]->network_type)
            {
                index = g_wlan_profile[i]->index;
                profile_id = g_wlan_profile[i]->profile_id;
                priority = g_wlan_profile[i]->priority;
                memcpy(g_wlan_profile[i], active_profile, sizeof(mmi_wlan_profile_struct));
                g_wlan_profile[i]->index = index;
                g_wlan_profile[i]->profile_id = profile_id;
                g_wlan_profile[i]->priority = priority;
                // g_wlan_display_context.active_wlan_profile_p = g_wlan_profile[i];
                g_wlan_display_context.connected_wlan_profile = g_wlan_profile[i];
                break;
            }
        }
        if (i == MAX_WLAN_DATA_ACCOUNT_NUM)
        {
            /* If there is no infrastructure type wlan profile, replace the highest priority adhoc wlan profile */
            if (active_profile->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
            {
                highest_priority_index = 0;
                for (i = 1; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
                {
                    if (g_wlan_profile[i]->priority < g_wlan_profile[highest_priority_index]->priority)
                    {
                        highest_priority_index = i;
        }
                }
                index = g_wlan_profile[highest_priority_index]->index;
                profile_id = g_wlan_profile[highest_priority_index]->profile_id;
                priority = g_wlan_profile[highest_priority_index]->priority;
                memcpy(g_wlan_profile[highest_priority_index], active_profile, sizeof(mmi_wlan_profile_struct));
                g_wlan_profile[highest_priority_index]->index = index;
                g_wlan_profile[highest_priority_index]->profile_id = profile_id;
                g_wlan_profile[highest_priority_index]->priority = priority;
                // g_wlan_display_context.active_wlan_profile_p = g_wlan_profile[highest_priority_index];
                g_wlan_display_context.adhoc_prof_num--;
                g_wlan_display_context.infra_prof_num++;				
                g_wlan_display_context.connected_wlan_profile = g_wlan_profile[highest_priority_index];
            }
            /* If there is no adhoc type wlan profile, replace the lowest priority infrastructure wlan profile */ 
            else if (active_profile->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC)
            {
                lowest_priority_index = 0;
                for (i = 1; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
                {
                  if (g_wlan_profile[i]->priority > g_wlan_profile[lowest_priority_index]->priority)
                  {
                      lowest_priority_index = i;
                  }
                }

                index = g_wlan_profile[lowest_priority_index]->index;
                profile_id = g_wlan_profile[lowest_priority_index]->profile_id;
                priority = g_wlan_profile[lowest_priority_index]->priority;
                memcpy(g_wlan_profile[lowest_priority_index], active_profile, sizeof(mmi_wlan_profile_struct));
                g_wlan_profile[lowest_priority_index]->index = index;
                g_wlan_profile[lowest_priority_index]->profile_id = profile_id;
                g_wlan_profile[lowest_priority_index]->priority = priority;
                // g_wlan_display_context.active_wlan_profile_p = g_wlan_profile[lowest_priority_index];
                g_wlan_display_context.adhoc_prof_num++;
                g_wlan_display_context.infra_prof_num--;	                    
                g_wlan_display_context.connected_wlan_profile = g_wlan_profile[lowest_priority_index];

                srv_dtcnt_store_delete_prof(profile_id, MMI_TRUE, NULL, NULL);
                add_ap = MMI_TRUE;
                fields = SRV_DTCNT_WLAN_PROF_FIELD_ALL;
            }              
        }
        else
        {
            g_wlan_display_context.connected_wlan_profile = g_wlan_profile[i];
        }
    }
    else
    {
    if(active_profile->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
    {
        if(g_wlan_display_context.adhoc_prof_num == 0)
        {
            active_profile->priority = ++g_wlan_display_context.prof_num;
                        
            memcpy(&g_wlan_prof_list[i], active_profile, sizeof(mmi_wlan_profile_struct));
            g_wlan_profile[g_wlan_prof_list[i].priority - 1] = &g_wlan_prof_list[i];
            // g_wlan_display_context.active_wlan_profile_p = &g_wlan_prof_list[i];
        }
        else
        {
            for(j = g_wlan_display_context.prof_num; j > g_wlan_display_context.infra_prof_num; j--)
            {
                g_wlan_profile[j] = g_wlan_profile[j-1];
                g_wlan_profile[j]->priority++;
            }
            active_profile->priority = g_wlan_display_context.infra_prof_num + 1;
            
            memcpy(&g_wlan_prof_list[i], active_profile, sizeof(mmi_wlan_profile_struct));
            g_wlan_profile[g_wlan_display_context.infra_prof_num] = &g_wlan_prof_list[i];
            g_wlan_display_context.prof_num++;
        }
        g_wlan_display_context.infra_prof_num++;
    }
    else 
    {
        g_wlan_display_context.adhoc_prof_num++;
        
        active_profile->priority = ++g_wlan_display_context.prof_num;
                
        memcpy(&g_wlan_prof_list[i], active_profile, sizeof(mmi_wlan_profile_struct));
        g_wlan_profile[g_wlan_prof_list[i].priority - 1] = &g_wlan_prof_list[i];
        // g_wlan_display_context.active_wlan_profile_p = &g_wlan_prof_list[i];
    }
    g_wlan_display_context.connected_wlan_profile = &g_wlan_prof_list[i];
    }
	g_wlan_display_context.connected_wlan_profile->ap_type = SRV_DTCNT_WLAN_AP_USER_DEFINE;
    mmi_wlan_dtcnt_store_profile(g_wlan_display_context.connected_wlan_profile, add_ap, fields);
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
#endif
#endif

    
    for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
    {
        if (g_wlan_prof_list[i].priority > 0)
        {            
            fields = (SRV_DTCNT_WLAN_PROF_FIELD_ALL & (~MMI_WLAN_ADVANCE_FIELD));
            mmi_wlan_dtcnt_store_profile(&(g_wlan_prof_list[i]), 0, fields);            
        }
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_save_blacklist_ap
 * DESCRIPTION
 *  To save the blacklist profile. 
 * PARAMETERS
 *  connected_ap        [IN]     connected AP.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_save_blacklist_ap(supc_abm_bss_info_struct *connected_ap)
{
    mmi_wlan_profile_struct *active_profile;
    U8 i, j;
	U8 index = 0, priority = 0;
	U32 profile_id = 0;
    char passphrase[SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1] = "aaaaa";
    U32 lowest_priority_index;
    U32 highest_priority_index;
    U32 add_ap = MMI_TRUE;
    U32 fields = SRV_DTCNT_WLAN_PROF_FIELD_ALL;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_SAVE_CONN_AP);

    memset(&g_wlan_info_prof, 0, sizeof(g_wlan_info_prof));

    active_profile = &g_wlan_display_context.temp_profile;

    bssinfo_to_profile(active_profile, connected_ap, (char*)passphrase, 0);
	active_profile->ap_type = SRV_DTCNT_WLAN_AP_BLACK_LIST;
    mmi_wlan_save_default_eap_to_profile(active_profile);

    /* Find an empty slot index first */
    for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
    {
        if (g_wlan_prof_list[i].ssid_len == 0)
        {
            break;
        }
    }
    /* If there is no empty slot, replay a same-type one, if no same type, not replace */
    if (i == MAX_WLAN_DATA_ACCOUNT_NUM)
    {
        add_ap = MMI_FALSE;
        fields = (SRV_DTCNT_WLAN_PROF_FIELD_ALL & (~MMI_WLAN_ADVANCE_FIELD));

        for (i = 0; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
        {
            if (active_profile->network_type == g_wlan_profile[i]->network_type)
            {
                index = g_wlan_profile[i]->index;
                profile_id = g_wlan_profile[i]->profile_id;
                priority = g_wlan_profile[i]->priority;
                memcpy(g_wlan_profile[i], active_profile, sizeof(mmi_wlan_profile_struct));
                g_wlan_profile[i]->index = index;
                g_wlan_profile[i]->profile_id = profile_id;
                g_wlan_profile[i]->priority = priority;
                break;
            }
        }
        if (i == MAX_WLAN_DATA_ACCOUNT_NUM)
        {
            /* If there is no infrastructure type wlan profile, replace the highest priority adhoc wlan profile */
            if (active_profile->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
            {
                highest_priority_index = 0;
                for (i = 1; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
                {
                    if (g_wlan_profile[i]->priority < g_wlan_profile[highest_priority_index]->priority)
                    {
                        highest_priority_index = i;
        }
                }
                index = g_wlan_profile[highest_priority_index]->index;
                profile_id = g_wlan_profile[highest_priority_index]->profile_id;
                priority = g_wlan_profile[highest_priority_index]->priority;
                memcpy(g_wlan_profile[highest_priority_index], active_profile, sizeof(mmi_wlan_profile_struct));
                g_wlan_profile[highest_priority_index]->index = index;
                g_wlan_profile[highest_priority_index]->profile_id = profile_id;
                g_wlan_profile[highest_priority_index]->priority = priority;
                // g_wlan_display_context.active_wlan_profile_p = g_wlan_profile[highest_priority_index];
                g_wlan_display_context.adhoc_prof_num--;
                g_wlan_display_context.infra_prof_num++;				
            }
            /* If there is no adhoc type wlan profile, replace the lowest priority infrastructure wlan profile */ 
            else if (active_profile->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC)
            {
                lowest_priority_index = 0;
                for (i = 1; i < MAX_WLAN_DATA_ACCOUNT_NUM; i++)
                {
                  if (g_wlan_profile[i]->priority > g_wlan_profile[lowest_priority_index]->priority)
                  {
                      lowest_priority_index = i;
                  }
                }
                index = g_wlan_profile[lowest_priority_index]->index;
                profile_id = g_wlan_profile[lowest_priority_index]->profile_id;
                priority = g_wlan_profile[lowest_priority_index]->priority;
                memcpy(g_wlan_profile[lowest_priority_index], active_profile, sizeof(mmi_wlan_profile_struct));
                g_wlan_profile[lowest_priority_index]->index = index;
                g_wlan_profile[lowest_priority_index]->profile_id = profile_id;
                g_wlan_profile[lowest_priority_index]->priority = priority;
                // g_wlan_display_context.active_wlan_profile_p = g_wlan_profile[lowest_priority_index];
                g_wlan_display_context.adhoc_prof_num++;
                g_wlan_display_context.infra_prof_num--;	                    

                srv_dtcnt_store_delete_prof(profile_id, MMI_TRUE, NULL, NULL);
                add_ap = MMI_TRUE;
                fields = SRV_DTCNT_WLAN_PROF_FIELD_ALL;
            }              
        }
    }
    else
    {
    if(active_profile->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
    {
        if(g_wlan_display_context.adhoc_prof_num == 0)
        {
            active_profile->priority = ++g_wlan_display_context.prof_num;
                        
            memcpy(&g_wlan_prof_list[i], active_profile, sizeof(mmi_wlan_profile_struct));
            g_wlan_profile[g_wlan_prof_list[i].priority - 1] = &g_wlan_prof_list[i];
            // g_wlan_display_context.active_wlan_profile_p = &g_wlan_prof_list[i];
        }
        else
        {
            for(j = g_wlan_display_context.prof_num; j > g_wlan_display_context.infra_prof_num; j--)
            {
                g_wlan_profile[j] = g_wlan_profile[j-1];
                g_wlan_profile[j]->priority++;
            }
            active_profile->priority = g_wlan_display_context.infra_prof_num + 1;
            
            memcpy(&g_wlan_prof_list[i], active_profile, sizeof(mmi_wlan_profile_struct));
            g_wlan_profile[g_wlan_display_context.infra_prof_num] = &g_wlan_prof_list[i];
            g_wlan_display_context.prof_num++;
        }
        g_wlan_display_context.infra_prof_num++;
    }
    else 
    {
        g_wlan_display_context.adhoc_prof_num++;
        
        active_profile->priority = ++g_wlan_display_context.prof_num;
                
        memcpy(&g_wlan_prof_list[i], active_profile, sizeof(mmi_wlan_profile_struct));
        g_wlan_profile[g_wlan_prof_list[i].priority - 1] = &g_wlan_prof_list[i];
        // g_wlan_display_context.active_wlan_profile_p = &g_wlan_prof_list[i];
    }
    }
    mmi_wlan_dtcnt_store_profile(active_profile, add_ap, fields);

    if (active_profile->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
    {
    g_wlan_profile[g_wlan_display_context.prof_num - g_wlan_display_context.adhoc_prof_num - 1]->profile_id = active_profile->profile_id;
    }
	else
	{
	    g_wlan_profile[g_wlan_display_context.prof_num - 1]->profile_id = active_profile->profile_id;
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_find_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  profile_id      [IN]    profile id. 
 * RETURNS
 *  return the found profile on success, otherwise return NULL.
 *****************************************************************************/
mmi_wlan_profile_struct *mmi_wlan_find_profile(U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mmi_wlan_profile_struct *temp_profile;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(profile_id == 0) /* temp profile */
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONN_EVENT, g_wlan_display_context.ui_flow);
        memset(&g_profile_saved_temp, 0, sizeof(mmi_wlan_profile_struct));
        temp_profile = &g_profile_saved_temp;
        if(MMI_WLAN_UI_CONNECT_BY_CUI == mmi_wlan_get_ui_flow ())
        {
            bssinfo_to_profile(temp_profile, &g_cui_hilt_profile, NULL, 0);
        }
        else
        {
            bssinfo_to_profile(temp_profile, &g_wlan_hilt_profile, NULL, 0);
        }
        
        for (i = 0; i < g_wlan_display_context.prof_num; i++)
        {
            if ((g_wlan_profile[i]->ssid_len == temp_profile->ssid_len) &&
                (strncmp((const char*)g_wlan_profile[i]->ssid, (const char*)temp_profile->ssid, temp_profile->ssid_len) == 0) &&
                (g_wlan_profile[i]->network_type == temp_profile->network_type) &&
                (g_wlan_profile[i]->auth_mode == temp_profile->auth_mode) &&
                (g_wlan_profile[i]->encrypt_mode == temp_profile->encrypt_mode))
            {
                return g_wlan_profile[i];
            }
        }

    }
    else
    {
        for (i = 0; i < g_wlan_display_context.prof_num; i++)
        {
            if (g_wlan_profile[i]->profile_id == profile_id)
            {
                return g_wlan_profile[i];
            }
        }
    }
    
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_search_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_dtcnt_wlan_conn_res_struct      [IN]    conn_res
 * RETURNS
 *  return the found profile if success, otherwise return NULL.
 *****************************************************************************/
mmi_wlan_profile_struct* mmi_wlan_search_profile(srv_dtcnt_wlan_conn_res_struct *conn_res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    mmi_wlan_profile_struct *temp_profile;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(conn_res->profile_id == 0) /* temp profile */
    {
        memset(&g_profile_saved_temp, 0, sizeof(mmi_wlan_profile_struct));
        temp_profile = &g_profile_saved_temp;

        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONN_IND_SERACH_PROFILE, g_wlan_hilt_profile.ssid_len, g_cui_hilt_profile.ssid_len, conn_res->ssid_len);
        if ((g_wlan_hilt_profile.ssid_len == conn_res->ssid_len) &&
            (strncmp((const char*)g_wlan_hilt_profile.ssid, (const char*)conn_res->ssid, conn_res->ssid_len) == 0))
        {   
            bssinfo_to_profile(temp_profile, &g_wlan_hilt_profile, NULL, 0);
        }
        else if((g_cui_hilt_profile.ssid_len == conn_res->ssid_len) &&
                (strncmp((const char*)g_cui_hilt_profile.ssid, (const char*)conn_res->ssid, conn_res->ssid_len) == 0))
        {
            bssinfo_to_profile(temp_profile, &g_cui_hilt_profile, NULL, 0);
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONN_IND_SERACH_PROFILE_NOT_FOUND, conn_res->profile_id);
            return NULL;
        }
        
        for (i = 0; i < g_wlan_display_context.prof_num; i++)
        {
            if ((g_wlan_profile[i]->ssid_len == temp_profile->ssid_len) &&
                (strncmp((const char*)g_wlan_profile[i]->ssid, (const char*)temp_profile->ssid, temp_profile->ssid_len) == 0) &&
                (g_wlan_profile[i]->network_type == temp_profile->network_type) &&
                (g_wlan_profile[i]->auth_mode == temp_profile->auth_mode) &&
                (g_wlan_profile[i]->encrypt_mode == temp_profile->encrypt_mode))
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONN_IND_SERACH_PROFILE_FOUND, conn_res->profile_id);
                return g_wlan_profile[i];
            }
        }
    }
    else
    {
        for (i = 0; i < g_wlan_display_context.prof_num; i++)
        {
            if (g_wlan_profile[i]->profile_id == conn_res->profile_id)
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONN_IND_SERACH_PROFILE_FOUND, conn_res->profile_id);
                return g_wlan_profile[i];
            }
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONN_IND_SERACH_PROFILE_NOT_FOUND, conn_res->profile_id);
    return NULL;
}

void mmi_wlan_popup_conn_result_info(srv_dtcnt_wlan_conn_res_struct *result)
{
    U16 string_id;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONN_CNF_SHOW_RES_MSG, result->result, result->cause);
    if(result->result != SRV_DTCNT_RESULT_SUCCESS)
    {
        switch(result->cause)
        {
        case SUPC_ABM_AUTH_FAIL:
            string_id = STR_ID_DTCNT_WLAN_ERROR_AUTH_FAIL;
            break;
        case SUPC_ABM_WRONG_USER_INFO:
            string_id = STR_ID_DTCNT_WLAN_ERROR_INPUT;
            break;
        case SUPC_ABM_UNSUPPORTED_EAP_TYPE:
            string_id = STR_ID_DTCNT_WLAN_ERROR_EAP_TYPE;
            break;
        default:
            string_id = STR_ID_DTCNT_WLAN_ERROR_CONNECT_FAIL;
            break;                
        }
        mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(string_id)), 
            MMI_EVENT_FAILURE, 
            wlan_parent_group_id,
            NULL);
    }
    else
    {
        mmi_popup_display_simple(
            (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_ACTIVATED)), 
            MMI_EVENT_SUCCESS, 
            wlan_parent_group_id, 
            NULL);
    }
}

void mmi_wlan_show_activated_popup(void)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CONN_IND_SHOW_ACTIVATED_POPUP);
    mmi_popup_display_simple(
        (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_ACTIVATED)), 
        MMI_EVENT_SUCCESS, 
        wlan_parent_group_id, 
        NULL);
}

void mmi_wlan_update_auth_mode_setting(void)
{
    U8 *pString = NULL;

    switch (g_wlan_display_context.network_type)
    {
    case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
        
        switch (g_wlan_display_context.auth_mode)
        {
        case SRV_DTCNT_WLAN_AUTH_MODE_OPEN:         /* Open Network */
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_OPEN);
            break;
        case SRV_DTCNT_WLAN_AUTH_MODE_WEP:          /* WEP */
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_SHARED);
            break;
        case SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X:    /* IEEE802.1x */    
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_IEEE8021X);
            break;
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY:     /* WPA Enterprise */
            //pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPA_ONLY);
			pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX);
            break;
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY:    /* WPA2 RSN Enterprise */
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY);
            break;
#if 0            
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif            
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK: /* WPA Only PSK */
            //pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK);
			pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX_PSK);
            break;
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK:/* WPA2 Only PSK */
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK);
            break;
#if 0            
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif            
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
        case SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT:     /* WAPI CERT */
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WAPICERT);
            break;
        case SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK:      /* WAPI PSK */
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WAPIPSK);
            break;
#endif /* __MMI_HIDE_WAPI__ */
#endif
        default:
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_OPEN);
            break;
        }   /* SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA */
        
        break;
        
    case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:

        switch (g_wlan_display_context.auth_mode)
        {
        case SRV_DTCNT_WLAN_AUTH_MODE_OPEN:             /* Open Network */
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_OPEN);
            break;
        case SRV_DTCNT_WLAN_AUTH_MODE_WEP:              /* WEP */
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_SHARED);
            break;
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK:     /* WPA Only PSK */
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK:    /* WPA2 Only PSK */
        // case SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX_PSK: /* WPA WPA2 Mix PSK */
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WPANONE);
            break;
		case SRV_DTCNT_WLAN_AUTH_MODE_TOTAL:
			pString = (PU8) GetString(STR_GLOBAL_NOT_SUPPORTED);
			break;
        default:
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_OPEN);
            break;
        }   /* SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC */
        
        break;
        
    default:
        break;
    }   /* END - Network Type */

    cui_inline_set_value(g_wlan_display_context.inline_setting_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_AUTH_MODE, 
        pString); 

    // Reset the security settings item
    cui_inline_set_item_attributes(g_wlan_display_context.inline_setting_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_SECURITY_SETTINGS, 
        CUI_INLINE_RESET_ATTRIBUTE, 
        CUI_INLINE_ITEM_DISABLE);
    
    switch (g_wlan_display_context.auth_mode)
    {
    case SRV_DTCNT_WLAN_AUTH_MODE_OPEN:
        pString = (U8*) GetString(STR_ID_DTCNT_WLAN_ERROR_NO_AUTH_SETTING);
        cui_inline_set_item_attributes(g_wlan_display_context.inline_setting_cui_id, 
            CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_SECURITY_SETTINGS, 
            CUI_INLINE_SET_ATTRIBUTE, 
            CUI_INLINE_ITEM_DISABLE);
        break;
    case SRV_DTCNT_WLAN_AUTH_MODE_WEP:
        pString = (U8*) GetString(STR_ID_DTCNT_WLAN_WEP_KEY_SETTINGS);
        break;
    case SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X:
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY:
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY:
    // case SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX:
        pString = (U8*) GetString(STR_ID_DTCNT_WLAN_EAP_TYPES);
        break;
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK:
    case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK:
    // case SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX_PSK:
        pString = (U8*) GetString(STR_ID_DTCNT_WLAN_WPA_PASSPHRASE);
        break;
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    case SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK:
        pString = (U8*) GetString(STR_ID_DTCNT_WLAN_WAPI_PSK_SETTINGS);
        break;
    case SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT:
        pString = (U8*) GetString(STR_ID_DTCNT_WLAN_WAPI_CERT_SETTINGS);
        break;
#endif /* __MMI_HIDE_WAPI__ */
#endif 
    default:
        break;
    }
    
    cui_inline_set_value(
        g_wlan_display_context.inline_setting_cui_id, 
        CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_SECURITY_SETTINGS, 
        pString);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_reg_event
 * DESCRIPTION
 *  Register event callback dynamically with user data pointer.
 * PARAMETERS
 *  evt_id :      [IN]  callback execution type.
 *  user_data :   [IN]  user data pointer.
 * RETURNS
 *  Return MMI_RET_OK if success to register callback with designated user data;
 *  return MMI_RET_ERR_HAS_BEEN_REGISTERED if the designated callback with 
 *  designated user data has been registered.
 *****************************************************************************/
static mmi_ret mmi_wlan_reg_event(U16 evt_id, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return mmi_frm_cb_reg_event(evt_id, mmi_wlan_callback_handler, user_data);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_reg_all_event
 * DESCRIPTION
 *  Register all event callback dynamically.
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_RET_OK if success to register callback with designated user data;
 *  return MMI_RET_ERR_HAS_BEEN_REGISTERED if the designated callback with 
 *  designated user data has been registered.
 *****************************************************************************/
static mmi_ret mmi_wlan_reg_all_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 evt_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (evt_id = EVT_ID_SRV_DTCNT_WLAN_ACTIVE; evt_id < EVT_ID_SRV_DTCNT_TOTAL; evt_id++)
    {
	    mmi_wlan_reg_event(evt_id, NULL);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_wlan_cui_entry_event_proc
* DESCRIPTION
*  data account cui event proc
*  
* PARAMETERS
*  mmi_event_struct      [IN]        
* RETURNS
*  return MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_wlan_cui_entry_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;
    U8 idx;
    mmi_menu_id menu_ids[2];
    mmi_menu_id menu_id[2];
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;

    switch (menu_evt->parent_menu_id)
    {
        case MENU_ID_WLAN_EAP_TTLS_TYPES_OPT:
        {
            idx = srv_dtcnt_wlan_eap_ttls_types(g_wlan_display_context.sel_eap_ttls_auth_type);

            if (g_wlan_display_context.eap_ttls_auth_type & (g_wlan_auth_module[idx].val))
            {
                menu_ids[0] = MENU_ID_WLAN_EAP_TTLS_TYPES_OPT_ACTIVATE;
                menu_ids[1] = MENU_ID_WLAN_EAP_TTLS_TYPES_OPT_EDIT;

                cui_menu_set_currlist(menu_evt->sender_id, 2, menu_ids);
                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_WLAN_EAP_TTLS_TYPES_OPT_ACTIVATE, (UI_string_type)GetString(STR_GLOBAL_DEACTIVATE));
                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_WLAN_EAP_TTLS_TYPES_OPT_EDIT, (UI_string_type)GetString(STR_GLOBAL_EDIT));

            }
        	else
        	{
        		menu_ids[0] = MENU_ID_WLAN_EAP_TTLS_TYPES_OPT_ACTIVATE;
        		menu_ids[1] = MENU_ID_WLAN_EAP_TTLS_TYPES_OPT_EDIT;
        
        		cui_menu_set_currlist(menu_evt->sender_id, 2, menu_ids);
        		cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_WLAN_EAP_TTLS_TYPES_OPT_ACTIVATE, (UI_string_type)GetString(STR_GLOBAL_ACTIVATE));
        		cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_WLAN_EAP_TTLS_TYPES_OPT_EDIT, (UI_string_type)GetString(STR_GLOBAL_EDIT));  
        	}
        	break;
        }

        case MENU_ID_WLAN_EAP_TTLS_TYPES_OPT2:
        {
            idx = srv_dtcnt_wlan_eap_ttls_types(g_wlan_display_context.sel_eap_ttls_auth_type);

            if (g_wlan_display_context.eap_ttls_auth_type & (g_wlan_auth_module[idx].val))
            {
                menu_id[0] = MENU_ID_WLAN_EAP_TTLS_TYPES_OPT_ACTIVATE;

                cui_menu_set_currlist(menu_evt->sender_id, 1, menu_id);
                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_WLAN_EAP_TTLS_TYPES_OPT_ACTIVATE, (UI_string_type)GetString(STR_GLOBAL_DEACTIVATE));

            }
            else
            {
                menu_id[0] = MENU_ID_WLAN_EAP_TTLS_TYPES_OPT_ACTIVATE;

                cui_menu_set_currlist(menu_evt->sender_id, 1, menu_id);
                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_WLAN_EAP_TTLS_TYPES_OPT_ACTIVATE, (UI_string_type)GetString(STR_GLOBAL_ACTIVATE));
            }
            break;
        }
        case MENU_ID_WLAN_EAP_PEAP_TYPES_OPT:
        {
            idx = srv_dtcnt_wlan_eap_peap_types(g_wlan_display_context.sel_eap_peap_auth_type);

            if (g_wlan_display_context.eap_peap_auth_type & (g_wlan_auth_module[idx].val))
            {
                menu_ids[0] = MENU_ID_WLAN_EAP_PEAP_TYPES_OPT_ACTIVATE;
                menu_ids[1] = MENU_ID_WLAN_EAP_PEAP_TYPES_OPT_EDIT;

                cui_menu_set_currlist(menu_evt->sender_id, 2, menu_ids);

                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_WLAN_EAP_PEAP_TYPES_OPT_ACTIVATE, (UI_string_type)GetString(STR_GLOBAL_DEACTIVATE));
                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_WLAN_EAP_PEAP_TYPES_OPT_EDIT, (UI_string_type)GetString(STR_GLOBAL_EDIT));

            }
        	else
        	{
        		menu_ids[0] = MENU_ID_WLAN_EAP_PEAP_TYPES_OPT_ACTIVATE;
        		menu_ids[1] = MENU_ID_WLAN_EAP_PEAP_TYPES_OPT_EDIT;
        
        		cui_menu_set_currlist(menu_evt->sender_id, 2, menu_ids);
        
        		cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_WLAN_EAP_PEAP_TYPES_OPT_ACTIVATE, (UI_string_type)GetString(STR_GLOBAL_ACTIVATE));
        		cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_WLAN_EAP_PEAP_TYPES_OPT_EDIT, (UI_string_type)GetString(STR_GLOBAL_EDIT));
        
        	}
        
        	break;
        }

        case MENU_ID_WLAN_EAP_PEAP_TYPES_OPT2:
        {
            idx = srv_dtcnt_wlan_eap_peap_types(g_wlan_display_context.sel_eap_peap_auth_type);

            if (g_wlan_display_context.eap_peap_auth_type & (g_wlan_auth_module[idx].val))
            {
                menu_id[0] = MENU_ID_WLAN_EAP_PEAP_TYPES_OPT_ACTIVATE;

                cui_menu_set_currlist(menu_evt->sender_id, 1, menu_id);

                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_WLAN_EAP_PEAP_TYPES_OPT_ACTIVATE, (UI_string_type)GetString(STR_GLOBAL_DEACTIVATE));

            }
            else
            {
                menu_id[0] = MENU_ID_WLAN_EAP_PEAP_TYPES_OPT_ACTIVATE;

                cui_menu_set_currlist(menu_evt->sender_id, 1, menu_id);

                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_WLAN_EAP_PEAP_TYPES_OPT_ACTIVATE, (UI_string_type)GetString(STR_GLOBAL_ACTIVATE));

            }

            break;
        }
        case MENU_ID_WLAN_EAP_TYPES_OPT:
        {
            idx = srv_dtcnt_wlan_eap_types(g_wlan_display_context.sel_auth_type1);

            if (g_wlan_display_context.auth_type1 & (g_wlan_auth_module[idx].val))
            {
                menu_ids[0] = MENU_ID_WLAN_EAP_TYPES_OPT_ACTIVATE;
                menu_ids[1] = MENU_ID_WLAN_EAP_TYPES_OPT_EDIT;

                cui_menu_set_currlist(menu_evt->sender_id, 2, menu_ids);

                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_WLAN_EAP_TYPES_OPT_ACTIVATE, (UI_string_type)GetString(STR_GLOBAL_DEACTIVATE));
                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_WLAN_EAP_TYPES_OPT_EDIT, (UI_string_type)GetString(STR_GLOBAL_EDIT));

            }
			else
			{
				menu_ids[0] = MENU_ID_WLAN_EAP_TYPES_OPT_ACTIVATE;
				menu_ids[1] = MENU_ID_WLAN_EAP_TYPES_OPT_EDIT;
				
				cui_menu_set_currlist(menu_evt->sender_id, 2, menu_ids);
				
				cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_WLAN_EAP_TYPES_OPT_ACTIVATE, (UI_string_type)GetString(STR_GLOBAL_ACTIVATE));
				cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_WLAN_EAP_TYPES_OPT_EDIT, (UI_string_type)GetString(STR_GLOBAL_EDIT));
        
			}
            break;
        }


        case MENU_ID_WLAN_EAP_TYPES_OPT2:
        {
            idx = srv_dtcnt_wlan_eap_types(g_wlan_display_context.sel_auth_type1);

            if (g_wlan_display_context.auth_type1 & (g_wlan_auth_module[idx].val))
            {
                menu_id[0] = MENU_ID_WLAN_EAP_TYPES_OPT_ACTIVATE;

                cui_menu_set_currlist(menu_evt->sender_id, 1, menu_id);

                cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_WLAN_EAP_TYPES_OPT_ACTIVATE, (UI_string_type)GetString(STR_GLOBAL_DEACTIVATE));

            }
            else
            {
				menu_id[0] = MENU_ID_WLAN_EAP_TYPES_OPT_ACTIVATE;
				menu_id[1] = MENU_ID_WLAN_EAP_TYPES_OPT_EDIT;
				
				cui_menu_set_currlist(menu_evt->sender_id, 1, menu_id);
				
				cui_menu_set_item_string(menu_evt->sender_id, MENU_ID_WLAN_EAP_TYPES_OPT_ACTIVATE, (UI_string_type)GetString(STR_GLOBAL_ACTIVATE));
        
			}
            break;
        }
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif


    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_wlan_cui_hilite_event_proc
* DESCRIPTION
*  data account cui event proc
*  
* PARAMETERS
*  mmi_event_struct      [IN]        
* RETURNS
*  return MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_wlan_cui_hilite_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_wlan_cui_select_event_proc
* DESCRIPTION
*  data account cui event proc
*  
* PARAMETERS
*  mmi_event_struct      [IN]        
* RETURNS
*  return MMI_RET_OK
 *****************************************************************************/
mmi_ret mmi_wlan_cui_select_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct *menu_evt;
    FuncPtr auth_settings_hdlr;
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    menu_evt = (cui_menu_event_struct *)evt;

    switch (menu_evt->highlighted_menu_id) 
    {
    case MENU_ID_WLAN_WIZARD_LIST_OPT_NEW:
        mmi_wlan_entry_network_add();
        break;
    case MENU_ID_WLAN_WIZARD_LIST_OPT_EDIT:
        g_wlan_display_context.modified = FALSE;
        mmi_wlan_pre_entry_network_edit();
        break;
    case MENU_ID_WLAN_WIZARD_LIST_OPT_DELETE:
        mmi_wlan_entry_network_delete();
        break;
    case MENU_ID_WLAN_WIZARD_LIST_OPT_PRIORITY:
        mmi_wlan_wizard_option_change_priority();
        break;
    case MENU_ID_WLAN_WIZARD_LIST_OPT_DEFINE:
        mmi_wlan_entry_define_network();
        break;
    case MENU_ID_WLAN_WIZARD_LIST_OPT_CONNECT:
#if 0
#ifndef __MMI_OP01_WIFI__
/* under construction !*/
#else
/* under construction !*/
#endif
#else
        mmi_wlan_entry_wizard_connect();
#endif
        break;
    case MENU_ID_WLAN_WIZARD_LIST_OPT_DISCONNECT:
#if 0
#ifndef __MMI_OP01_WIFI__        
/* under construction !*/
#else
/* under construction !*/
#endif
#else
        mmi_wlan_entry_network_disconnect();
#endif
        break;
    case MENU_ID_WLAN_WIZARD_LIST_OPT_STATUS:
        mmi_wlan_entry_conn_status();
        break;
    case MENU_ID_WLAN_WIZARD_LIST_OPT_REFRESH:
        mmi_wlan_enable_entry_main();
        break;
    case MENU_ID_WLAN_WIZARD_LIST_OPT_OFF:
#if 0
#ifndef __MMI_OP01_WIFI__        
/* under construction !*/
#else
/* under construction !*/
#endif
#else
        mmi_wlan_wizard_option_off();
#endif
        break;
    case MENU_ID_WLAN_WIZARD_LIST_OPT_ON:
        mmi_wlan_wizard_option_on();
        break;
    case MENU_ID_WLAN_EAP_TTLS_TYPES_OPT_ACTIVATE:
        mmi_wlan_eap_ttls_settings_auth_type_ok();
        break;
    case MENU_ID_WLAN_EAP_TTLS_TYPES_OPT_EDIT:
    {
		index = srv_dtcnt_wlan_eap_ttls_types(g_wlan_display_context.sel_eap_ttls_auth_type);
		auth_settings_hdlr = g_wlan_auth_module[index].entry_func;
		
		ASSERT(auth_settings_hdlr != NULL);
		auth_settings_hdlr();
        break;
    }
    case MENU_ID_WLAN_EAP_PEAP_TYPES_OPT_ACTIVATE:
        mmi_wlan_eap_peap_settings_eap_type_ok();
        break;
    case MENU_ID_WLAN_EAP_PEAP_TYPES_OPT_EDIT:
    {
        index = srv_dtcnt_wlan_eap_peap_types(g_wlan_display_context.sel_eap_peap_auth_type);
        auth_settings_hdlr = g_wlan_auth_module[index].entry_func;
		
        ASSERT(auth_settings_hdlr != NULL);
		auth_settings_hdlr();
        break;
    }
    case MENU_ID_WLAN_EAP_TYPES_OPT_ACTIVATE:
        mmi_wlan_eap_type_activate();
        break;
    case MENU_ID_WLAN_EAP_TYPES_OPT_EDIT:
    {
        index = srv_dtcnt_wlan_eap_types(g_wlan_display_context.sel_auth_type1);
        auth_settings_hdlr = g_wlan_auth_module[index].entry_func;
		
        ASSERT(auth_settings_hdlr != NULL);
		auth_settings_hdlr();
        break;
    }
    case MENU_ID_WLAN_WIZARD_LIST_OPT_POWER_SAVE:
        mmi_wlan_entry_power_save_mode();
        break;
    case MENU_ID_WLAN_WIZARD_LIST_OPT_SETTING:
        mmi_wlan_entry_wlan_prefer_settings();
        break;
        
#ifdef __WPS_SUPPORT__ 
    case MENU_ID_WLAN_WIZARD_LIST_OPT_WPS_PBC:
        mmi_wlan_wps_send_conn_req (WLAN_WPS_PBC);
        break;
    case MENU_ID_WLAN_WIZARD_LIST_OPT_WPS_PIN:
        mmi_wlan_wps_send_conn_req (WLAN_WPS_PIN);
        break;
	case MENU_ID_WLAN_WIZARD_LIST_OPT_WPS:
        if (g_wlan_display_context.prof_num == 0 && g_wlan_display_context.ap_list_num == 0)
        {
            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_WLAN_WIZARD_LIST_OPT_WPS_PIN, MMI_TRUE);
        }
		else
		{
		    cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_WLAN_WIZARD_LIST_OPT_WPS_PIN, MMI_FALSE);
		}
        break;
#endif  /* __WPS_SUPPORT__ */
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

    default:
        break;
    }

    return MMI_RET_OK;
}

mmi_ret mmi_wlan_cui_close_event_proc(mmi_event_struct *evt)
{
    cui_menu_event_struct *menu_evt;

    menu_evt = (cui_menu_event_struct*)evt;
    if(g_wlan_display_context.option_menu_cui_id == menu_evt->sender_id)
    {
        mmi_wlan_close_menu_cui(&g_wlan_display_context.option_menu_cui_id);
    }
    else
    {
        cui_menu_close(menu_evt->sender_id);
    }

    return MMI_RET_OK;
}

void mmi_wlan_cui_editor_submit_evt_proc(mmi_event_struct *evt)
{
    cui_fseditor_evt_struct *fs_editor_event;
    
    fs_editor_event = (cui_fseditor_evt_struct*)evt;
    if (fs_editor_event->sender_id == g_wlan_display_context.wlan_editor_cui_id)
    {
        cui_fseditor_get_text(
            g_wlan_display_context.wlan_editor_cui_id, 
            (WCHAR*) g_wlan_display_context.passphrase_str, 
            (SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH);
        mmi_wlan_entry_find_network_connect();

    }
    if (fs_editor_event->sender_id == g_wlan_display_context.wlan_inline_editor_cui_id)
    {
        cui_fseditor_get_text(
            g_wlan_display_context.wlan_inline_editor_cui_id, 
            (WCHAR*) g_wlan_display_context.passphrase_str, 
            (SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1) * ENCODING_LENGTH);
        
        mmi_wlan_wpa_passphrase_save();
    }
}

void mmi_wlan_cui_editor_changed_evt_proc(mmi_event_struct *evt)
{
    cui_fseditor_evt_struct *fs_editor_event;
    
    fs_editor_event = (cui_fseditor_evt_struct*)evt;
    if (fs_editor_event->sender_id == g_wlan_display_context.wlan_inline_editor_cui_id)
    {
        g_wlan_display_context.wpa_psk_modified = TRUE;
    }
}

void mmi_wlan_cui_editor_abort_evt_proc(mmi_event_struct *evt)
{
    cui_fseditor_evt_struct *fs_editor_event;
    
    fs_editor_event = (cui_fseditor_evt_struct*)evt;
    cui_fseditor_close(fs_editor_event->sender_id);
}

void mmi_wlan_cui_inline_submit_evt_proc(mmi_event_struct *evt)
{
    cui_event_inline_submit_struct *inline_submit_event;

    inline_submit_event = (cui_event_inline_submit_struct*)evt;
    if (inline_submit_event->sender_id == g_wlan_display_context.inline_wep_cui_id)
    {
        cui_inline_get_value(inline_submit_event->sender_id, 
            CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY, 
            g_wlan_display_context.sel_wep_key_str); 
        
        if( MMI_TRUE == mmi_wlan_wep_settings_save())
        {
            mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_wep_cui_id);
        }
    }
    else if (inline_submit_event->sender_id == g_wlan_display_context.inline_setting_cui_id)
    { 
        cui_inline_get_value(g_wlan_display_context.inline_setting_cui_id, 
            CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_NAME, 
            g_wlan_display_context.name); 
        cui_inline_get_value(g_wlan_display_context.inline_setting_cui_id, 
            CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_SSID, 
            g_wlan_display_context.ssid_str);
        mmi_wlan_network_edit_save();
    }
    else if (inline_submit_event->sender_id == g_wlan_display_context.inline_tcp_ip_cui_id)
    { 
        if(mmi_wlan_tcpip_settings_save(inline_submit_event->sender_id))
        {
            mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_tcp_ip_cui_id);
        }
    }
    else if (inline_submit_event->sender_id == g_wlan_display_context.inline_eap_ttls_cui_id)
    {
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_eap_ttls_cui_id);
        mmi_wlan_eap_ttls_settings_save();
    }
    else if (inline_submit_event->sender_id == g_wlan_display_context.inline_eap_peap_cui_id)
    { 
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_eap_peap_cui_id);
        mmi_wlan_eap_peap_settings_save();
    }
    else if (inline_submit_event->sender_id == g_wlan_display_context.inline_eap_tls_cui_id)
    { 
        cui_inline_get_value(g_wlan_display_context.inline_eap_tls_cui_id, 
            CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_PRIV_KEY_PASSWD, 
            g_wlan_display_context.private_key_passwd_str); 
        cui_inline_get_value(g_wlan_display_context.inline_eap_tls_cui_id, 
            CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_USERNAME, 
            g_wlan_display_context.username_str);
        
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_eap_tls_cui_id);
        mmi_wlan_eap_tls_settings_save();
    }
    else if (inline_submit_event->sender_id == g_wlan_display_context.inline_eap_user_info_cui_id)
    { 
        cui_inline_get_value(g_wlan_display_context.inline_eap_user_info_cui_id, 
            CUI_INLINE_ITEM_ID_BASE + WLAN_USER_INFO_USERNAME, 
            g_wlan_display_context.username_str); 
        cui_inline_get_value(g_wlan_display_context.inline_eap_user_info_cui_id, 
            CUI_INLINE_ITEM_ID_BASE + WLAN_USER_INFO_PASSWORD, 
            g_wlan_display_context.password_str);
        
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_eap_user_info_cui_id);
        mmi_wlan_user_info_save();
    }
    else if (inline_submit_event->sender_id == g_wlan_display_context.inline_default_eap_cui_id)
    { 
        cui_inline_get_value(g_wlan_display_context.inline_default_eap_cui_id, 
            CUI_INLINE_ITEM_ID_BASE + WLAN_USER_INFO_USERNAME, 
            g_wlan_display_context.username_str); 
        cui_inline_get_value(g_wlan_display_context.inline_default_eap_cui_id, 
            CUI_INLINE_ITEM_ID_BASE + WLAN_USER_INFO_PASSWORD, 
            g_wlan_display_context.password_str);
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_default_eap_cui_id);
        mmi_wlan_save_default_eap_connect();
    }
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    else if (inline_submit_event->sender_id == g_wlan_display_context.inline_wapi_cert_cui_id)
    {
        cui_inline_get_value(g_wlan_display_context.inline_wapi_cert_cui_id, 
            CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WAPI_EDIT_PRIV_KEY_PASSWD, 
            g_wlan_display_context.wapi_private_key_passwd_str); 
        mmi_wlan_wapi_save_or_connect();
        
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_wapi_cert_cui_id);
    }
    else if (inline_submit_event->sender_id == g_wlan_display_context.inline_wapi_psk_cui_id)
    {
        cui_inline_get_value(g_wlan_display_context.inline_wapi_psk_cui_id, 
            CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WAPI_PSK_EDIT_KEY, 
            g_wlan_display_context.wapi_psk_str);

        if(MMI_FALSE == mmi_wlan_verify_wapi_pre_shared_key())
        {
            mmi_popup_display_simple(
                (WCHAR*)((UI_string_type) GetString(STR_ID_DTCNT_WLAN_ERROR_INVALID_WAI_PSK)), 
                MMI_EVENT_FAILURE, 
                wlan_parent_group_id, 
                NULL);

            memset(g_wlan_display_context.wapi_psk_str, 0, (31 + 1) * ENCODING_LENGTH);
            cui_inline_set_value(
                g_wlan_display_context.inline_wapi_psk_cui_id,
                CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WAPI_PSK_EDIT_KEY,
                g_wlan_display_context.wapi_psk_str);
            
            cui_inline_set_screen_attributes(
                g_wlan_display_context.inline_wapi_psk_cui_id, 
                CUI_INLINE_RESET_ATTRIBUTE, 
                CUI_INLINE_SCREEN_CHANGED);
        }
        else
        {
            mmi_wlan_wapi_save_or_connect();
            mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_wapi_psk_cui_id);
        }
    }            
#endif /* __MMI_HIDE_WAPI__ */
#endif
    /* Adanced settings */
    else if (inline_submit_event->sender_id == g_wlan_display_context.wlan_advan_cui_id)
    {
        MMI_BOOL is_valid;
        
        is_valid = mmi_wlan_get_advance_setting_value(inline_submit_event);
        if (is_valid)
        {
            mmi_ucs2cpy ((CHAR *)g_wlan_display_context.home_page, (const CHAR *) home_page_temp_buf);
            g_wlan_display_context.use_proxy = use_proxy_temp;
            
			mmi_ucs2cpy ((CHAR *)g_wlan_display_context.proxy_addr, (const CHAR *) proxy_addr_temp);
            
            mmi_ucs2cpy ((CHAR *)g_wlan_display_context.proxy_port_str, (const CHAR *) proxy_port_str_temp);
            g_wlan_display_context.proxy_port = proxy_port_temp;
            mmi_ucs2cpy ((CHAR *)g_wlan_display_context.proxy_user_name, (const CHAR *) proxy_user_name_temp);
            mmi_ucs2cpy ((CHAR *)g_wlan_display_context.proxy_password, (const CHAR *) proxy_password_temp);
            
            mmi_wlan_close_inline_cui(&g_wlan_display_context.wlan_advan_cui_id);
        }
        else
        {
            cui_inline_set_screen_attributes(
                g_wlan_display_context.wlan_advan_cui_id, 
                CUI_INLINE_RESET_ATTRIBUTE, 
                CUI_INLINE_SCREEN_CHANGED);
        }
    }
    /* Wlan prefer searching */
    else if (inline_submit_event->sender_id == g_wlan_display_context.wlan_prefer_setting_id)
    {
        mmi_wlan_get_wlan_prefer_settings();
        mmi_popup_display_simple_ext(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS, wlan_parent_group_id, NULL);
        mmi_wlan_close_inline_cui(&g_wlan_display_context.wlan_prefer_setting_id);
    }
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

    else
    {   
        /* Abnormal situation */
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CLOSE_INLINE_CUI, -1);
        cui_inline_close(inline_submit_event->sender_id);
    }
}

void mmi_wlan_cui_inline_set_key_evt_proc(mmi_event_struct *evt)
{
    cui_event_inline_set_key_struct *inline_setkey_event;

    inline_setkey_event = (cui_event_inline_set_key_struct*)evt;
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    if (inline_setkey_event->sender_id == g_wlan_display_context.inline_wapi_cert_cui_id)
    {
        if (inline_setkey_event->item_id == CUI_INLINE_ITEM_ID_BASE + WLAN_WAPI_EDIT_ASE_CERT)
        {
            cui_inline_set_softkey_text(g_wlan_display_context.inline_wapi_cert_cui_id, 
				                        (CUI_INLINE_ITEM_ID_BASE + WLAN_WAPI_EDIT_ASE_CERT), 
				                        MMI_LEFT_SOFTKEY, 
				                        STR_GLOBAL_SELECT);
            wgui_inline_set_lsk_function(mmi_wlan_wapi_entry_ASE_cert_list);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_wlan_wapi_entry_ASE_cert_list, KEY_EVENT_UP);

        }
        else if (inline_setkey_event->item_id == CUI_INLINE_ITEM_ID_BASE + WLAN_WAPI_EDIT_USER_CERT)
        {
            cui_inline_set_softkey_text(g_wlan_display_context.inline_wapi_cert_cui_id, 
				                        (CUI_INLINE_ITEM_ID_BASE + WLAN_WAPI_EDIT_USER_CERT), 
				                        MMI_LEFT_SOFTKEY, 
				                        STR_GLOBAL_SELECT);
            wgui_inline_set_lsk_function(mmi_wlan_wapi_entry_user_cert_list);
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_wlan_wapi_entry_user_cert_list, KEY_EVENT_UP);

        }
    }
#endif /* __MMI_HIDE_WAPI__ */
#endif
    if (inline_setkey_event->sender_id == g_wlan_display_context.inline_eap_tls_cui_id)
    {
        if (inline_setkey_event->item_id == CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_USER_CERT)
        {
            cui_inline_set_softkey_text(g_wlan_display_context.inline_eap_tls_cui_id, 
				                        (CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_USER_CERT), 
				                        MMI_LEFT_SOFTKEY, 
				                        STR_GLOBAL_SELECT);
            wgui_inline_set_lsk_function(mmi_wlan_entry_user_cert_list);
//#ifndef __MMI_WGUI_DISABLE_CSK__            
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_wlan_entry_user_cert_list, KEY_EVENT_UP);
//#endif
        }
        else if (inline_setkey_event->item_id == CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_CA_CERT)
        {
            cui_inline_set_softkey_text(g_wlan_display_context.inline_eap_tls_cui_id, 
				                        (CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_CA_CERT), 
				                        MMI_LEFT_SOFTKEY, 
				                        STR_GLOBAL_SELECT);
            wgui_inline_set_lsk_function(mmi_wlan_entry_ca_cert_list);
//#ifndef __MMI_WGUI_DISABLE_CSK__            
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_wlan_entry_ca_cert_list, KEY_EVENT_UP);
//#endif            
        }
#ifndef __CERTMAN_SUPPORT__
        else if (inline_setkey_event->item_id == CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_PRIV_KEY)
        {
            cui_inline_set_softkey_text(g_wlan_display_context.inline_eap_tls_cui_id, 
				                        (CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_PRIV_KEY), 
				                        MMI_LEFT_SOFTKEY, 
				                        STR_GLOBAL_SELECT);
            wgui_inline_set_lsk_function(mmi_wlan_entry_private_key_list);
//#ifndef __MMI_WGUI_DISABLE_CSK__            
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_wlan_entry_private_key_list, KEY_EVENT_UP);
//#endif
        }
#endif /* __CERTMAN_SUPPORT__ */
    }
    if (inline_setkey_event->sender_id == g_wlan_display_context.inline_eap_peap_cui_id)
    {
        if (inline_setkey_event->item_id == CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_PEAP_SETTINGS_CA_CERT)
        {
            cui_inline_set_softkey_text(g_wlan_display_context.inline_eap_peap_cui_id, 
				                        (CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_PEAP_SETTINGS_CA_CERT), 
				                        MMI_LEFT_SOFTKEY, 
				                        STR_GLOBAL_SELECT);
            wgui_inline_set_lsk_function(mmi_wlan_entry_ca_cert_list);
//#ifndef __MMI_WGUI_DISABLE_CSK__            
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_wlan_entry_ca_cert_list, KEY_EVENT_UP);
//#endif
        }
        else if (inline_setkey_event->item_id == CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_PEAP_SETTINGS_TUNNELED_AUTH_PROTOCOL)
        {
            cui_inline_set_softkey_text(g_wlan_display_context.inline_eap_peap_cui_id, 
				                        (CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_PEAP_SETTINGS_TUNNELED_AUTH_PROTOCOL), 
				                        MMI_LEFT_SOFTKEY, 
				                        STR_GLOBAL_SELECT);
            wgui_inline_set_lsk_function(mmi_wlan_entry_eap_peap_settings_eap_type);
//#ifndef __MMI_WGUI_DISABLE_CSK__            
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_wlan_entry_eap_peap_settings_eap_type, KEY_EVENT_UP);
//#endif
        }
    }
    if (inline_setkey_event->sender_id == g_wlan_display_context.inline_eap_ttls_cui_id)
    {
        if (inline_setkey_event->item_id == CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TTLS_SETTINGS_CA_CERT)
        {
            cui_inline_set_softkey_text(g_wlan_display_context.inline_eap_ttls_cui_id, 
				                        (CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TTLS_SETTINGS_CA_CERT), 
				                        MMI_LEFT_SOFTKEY, 
				                        STR_GLOBAL_SELECT);
            wgui_inline_set_lsk_function(mmi_wlan_entry_ca_cert_list);
//#ifndef __MMI_WGUI_DISABLE_CSK__            
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_wlan_entry_ca_cert_list, KEY_EVENT_UP);
//#endif            
        }
        else if (inline_setkey_event->item_id == CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TTLS_SETTINGS_TUNNELED_AUTH_PROTOCOL)
        {
            cui_inline_set_softkey_text(g_wlan_display_context.inline_eap_ttls_cui_id, 
				                        (CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TTLS_SETTINGS_TUNNELED_AUTH_PROTOCOL), 
				                        MMI_LEFT_SOFTKEY, 
				                        STR_GLOBAL_SELECT);
            wgui_inline_set_lsk_function(mmi_wlan_entry_eap_ttls_settings_auth_type);
//#ifndef __MMI_WGUI_DISABLE_CSK__            
            ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
            SetCenterSoftkeyFunction(mmi_wlan_entry_eap_ttls_settings_auth_type, KEY_EVENT_UP);
//#endif
        }
    }

    if (inline_setkey_event->sender_id == g_wlan_display_context.inline_setting_cui_id)
    {
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
        /* For test mode */
        if (g_wapi_test_mode)
        {
            if (inline_setkey_event->item_id == CUI_INLINE_ITEM_ID_BASE + WLAN_NETWORK_EDIT_AUTH_MODE)
            {
                cui_inline_set_softkey_text(g_wlan_display_context.inline_setting_cui_id, 
				                        (CUI_INLINE_ITEM_ID_BASE + WLAN_NETWORK_EDIT_AUTH_MODE), 
				                        MMI_LEFT_SOFTKEY, 
				                        STR_GLOBAL_SELECT);
                wgui_inline_set_lsk_function(mmi_wlan_pre_entry_auth_mode_wapi_test_mode);
                ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                SetCenterSoftkeyFunction(mmi_wlan_pre_entry_auth_mode_wapi_test_mode, KEY_EVENT_UP);

            }
            else if (inline_setkey_event->item_id == CUI_INLINE_ITEM_ID_BASE + WLAN_NETWORK_EDIT_NETWORK_TYPE)
            {
                cui_inline_set_softkey_text(g_wlan_display_context.inline_setting_cui_id, 
				                        (CUI_INLINE_ITEM_ID_BASE + WLAN_NETWORK_EDIT_NETWORK_TYPE), 
				                        MMI_LEFT_SOFTKEY, 
				                        STR_GLOBAL_SELECT);
                wgui_inline_set_lsk_function(mmi_wlan_entry_network_type);
                ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                SetCenterSoftkeyFunction(mmi_wlan_entry_network_type, KEY_EVENT_UP);

            }
            else if (inline_setkey_event->item_id == CUI_INLINE_ITEM_ID_BASE + WLAN_NETWORK_EDIT_TCPIP_SETTINGS)
            {
                cui_inline_set_softkey_text(g_wlan_display_context.inline_setting_cui_id, 
				                        (CUI_INLINE_ITEM_ID_BASE + WLAN_NETWORK_EDIT_TCPIP_SETTINGS), 
				                        MMI_LEFT_SOFTKEY, 
				                        STR_GLOBAL_EDIT);
                wgui_inline_set_lsk_function(mmi_wlan_pre_entry_tcpip_settings);
                ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                SetCenterSoftkeyFunction(mmi_wlan_pre_entry_tcpip_settings, KEY_EVENT_UP);

            }
            else if (inline_setkey_event->item_id == CUI_INLINE_ITEM_ID_BASE + WLAN_NETWORK_EDIT_SECURITY_SETTINGS)
            {
                cui_inline_set_softkey_text(g_wlan_display_context.inline_setting_cui_id, 
				                        (CUI_INLINE_ITEM_ID_BASE + WLAN_NETWORK_EDIT_SECURITY_SETTINGS), 
				                        MMI_LEFT_SOFTKEY, 
				                        STR_GLOBAL_EDIT);
                ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

                switch (g_wlan_display_context.auth_mode)
                {
                #ifdef __WAPI_SUPPORT__
                #ifndef __MMI_HIDE_WAPI__
                    case SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT:
                        wgui_inline_set_lsk_function(mmi_wlan_entry_wapi_cert_settings);
                        break;
                    case SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK:
                        wgui_inline_set_lsk_function(mmi_wlan_entry_wapi_psk_settings);
                        SetCenterSoftkeyFunction(mmi_wlan_entry_wapi_psk_settings, KEY_EVENT_UP);

                        break;
                #endif /* __MMI_HIDE_WAPI__ */
                #endif
                    default:
                        wgui_inline_set_lsk_function(mmi_wlan_entry_no_auth_settings);
                        SetCenterSoftkeyFunction(mmi_wlan_entry_no_auth_settings, KEY_EVENT_UP);

                        break;
                }
            }
        }
        else
#endif /* __MMI_HIDE_WAPI__ */
#endif
        {
            if (inline_setkey_event->item_id == CUI_INLINE_ITEM_ID_BASE + WLAN_NETWORK_EDIT_AUTH_MODE)
            {
                cui_inline_set_softkey_text(g_wlan_display_context.inline_setting_cui_id, 
				                        (CUI_INLINE_ITEM_ID_BASE + WLAN_NETWORK_EDIT_AUTH_MODE), 
				                        MMI_LEFT_SOFTKEY, 
				                        STR_GLOBAL_SELECT);
                wgui_inline_set_lsk_function(mmi_wlan_pre_entry_auth_mode);
//#ifndef __MMI_WGUI_DISABLE_CSK__                
                ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                SetCenterSoftkeyFunction(mmi_wlan_pre_entry_auth_mode, KEY_EVENT_UP);
//#endif                
            }
            else if (inline_setkey_event->item_id == CUI_INLINE_ITEM_ID_BASE + WLAN_NETWORK_EDIT_NETWORK_TYPE)
            {
                cui_inline_set_softkey_text(g_wlan_display_context.inline_setting_cui_id, 
				                        (CUI_INLINE_ITEM_ID_BASE + WLAN_NETWORK_EDIT_NETWORK_TYPE), 
				                        MMI_LEFT_SOFTKEY, 
				                        STR_GLOBAL_SELECT);
                wgui_inline_set_lsk_function(mmi_wlan_entry_network_type);
//#ifndef __MMI_WGUI_DISABLE_CSK__                
                ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                SetCenterSoftkeyFunction(mmi_wlan_entry_network_type, KEY_EVENT_UP);
//#endif                
            }
            else if (inline_setkey_event->item_id == CUI_INLINE_ITEM_ID_BASE + WLAN_NETWORK_EDIT_TCPIP_SETTINGS)
            {
                cui_inline_set_softkey_text(g_wlan_display_context.inline_setting_cui_id, 
				                        (CUI_INLINE_ITEM_ID_BASE + WLAN_NETWORK_EDIT_TCPIP_SETTINGS), 
				                        MMI_LEFT_SOFTKEY, 
				                        STR_GLOBAL_EDIT);
                wgui_inline_set_lsk_function(mmi_wlan_pre_entry_tcpip_settings);
//#ifndef __MMI_WGUI_DISABLE_CSK__                
                ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
                SetCenterSoftkeyFunction(mmi_wlan_pre_entry_tcpip_settings, KEY_EVENT_UP);
//#endif
            }
            else if (inline_setkey_event->item_id == CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_ADVAN_SETTINGS)
            {
                cui_inline_set_softkey_text(g_wlan_display_context.inline_setting_cui_id, 
				                        (CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_ADVAN_SETTINGS), 
				                        MMI_LEFT_SOFTKEY, 
				                        STR_GLOBAL_EDIT);
//#ifndef __MMI_WGUI_DISABLE_CSK__				                        
                ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
//#endif
                wgui_inline_set_lsk_function(mmi_wlan_pre_entry_advance_settings);
                SetCenterSoftkeyFunction(mmi_wlan_pre_entry_advance_settings, KEY_EVENT_UP);
            }
            else if (inline_setkey_event->item_id == CUI_INLINE_ITEM_ID_BASE + WLAN_NETWORK_EDIT_SECURITY_SETTINGS)
            {
                cui_inline_set_softkey_text(g_wlan_display_context.inline_setting_cui_id, 
				                        (CUI_INLINE_ITEM_ID_BASE + WLAN_NETWORK_EDIT_SECURITY_SETTINGS), 
				                        MMI_LEFT_SOFTKEY, 
				                        STR_GLOBAL_EDIT);
//#ifndef __MMI_WGUI_DISABLE_CSK__				                        
                ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
//#endif
                switch (g_wlan_display_context.auth_mode)
                {
                    case SRV_DTCNT_WLAN_AUTH_MODE_WEP:
                        wgui_inline_set_lsk_function(mmi_wlan_entry_wep_settings);
                        SetCenterSoftkeyFunction(mmi_wlan_entry_wep_settings, KEY_EVENT_UP);

                        break;
                    case SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X:
                    case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY:
                    case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY:
                    // case SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX:
			cui_inline_set_softkey_text(g_wlan_display_context.inline_setting_cui_id, 
						    (CUI_INLINE_ITEM_ID_BASE + WLAN_NETWORK_EDIT_SECURITY_SETTINGS), 
						    MMI_LEFT_SOFTKEY, 
						    STR_GLOBAL_SELECT);
                        wgui_inline_set_lsk_function(mmi_wlan_entry_eap_type);
                        SetCenterSoftkeyFunction(mmi_wlan_entry_eap_type, KEY_EVENT_UP);
                        break;
                    case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK:
                    case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK:
                    // case SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX_PSK:
                        wgui_inline_set_lsk_function(mmi_wlan_entry_wpa_passphrase);
                        SetCenterSoftkeyFunction(mmi_wlan_entry_wpa_passphrase, KEY_EVENT_UP);
                        break;
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
                    case SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT:
                        wgui_inline_set_lsk_function(mmi_wlan_entry_wapi_cert_settings);
                        SetCenterSoftkeyFunction(mmi_wlan_entry_wapi_cert_settings, KEY_EVENT_UP);
                        break;
                    case SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK:
                        wgui_inline_set_lsk_function(mmi_wlan_entry_wapi_psk_settings);
                        SetCenterSoftkeyFunction(mmi_wlan_entry_wapi_psk_settings, KEY_EVENT_UP);
                        break;
#endif /* __MMI_HIDE_WAPI__ */
#endif
                    default:
                    if (g_wlan_display_context.encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP)
                    {
                        wgui_inline_set_lsk_function(mmi_wlan_entry_wep_settings);
                        SetCenterSoftkeyFunction(mmi_wlan_entry_wep_settings, KEY_EVENT_UP);
                    }
                    else
                    {
                        wgui_inline_set_lsk_function(mmi_wlan_entry_no_auth_settings);
                        SetCenterSoftkeyFunction(mmi_wlan_entry_no_auth_settings, KEY_EVENT_UP);
                    }
                    break;
                } /* end of switch */
            } /* end of if */
        } /* end of if */
    }
}

void mmi_wlan_cui_inline_abort_evt_proc(mmi_event_struct *evt)
{
    cui_event_inline_abort_struct *inline_abort_event;

    inline_abort_event = (cui_event_inline_abort_struct*)evt;

    /* Empty pre-shared key string before back to main list */
    if (inline_abort_event->sender_id == g_wlan_display_context.inline_setting_cui_id)
    {
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_setting_cui_id);
        /* Clear temp data for username and password */
        mmi_wlan_network_clear_history_data();
    }
    /* make highlight item located at head */
    else if (inline_abort_event->sender_id == g_wlan_display_context.inline_eap_ttls_cui_id)
    {
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_eap_ttls_cui_id);
    }
    else if (inline_abort_event->sender_id == g_wlan_display_context.inline_default_eap_cui_id)
    {
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_default_eap_cui_id);
    }
    else if (inline_abort_event->sender_id == g_wlan_display_context.inline_wep_cui_id)
    {
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_wep_cui_id);
    }
    else if (inline_abort_event->sender_id == g_wlan_display_context.inline_tcp_ip_cui_id)
    {
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_tcp_ip_cui_id);
    }
    else if (inline_abort_event->sender_id == g_wlan_display_context.inline_eap_peap_cui_id)
    {
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_eap_peap_cui_id);
    }
    else if (inline_abort_event->sender_id == g_wlan_display_context.inline_eap_tls_cui_id)
    {
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_eap_tls_cui_id);
    }
    else if (inline_abort_event->sender_id == g_wlan_display_context.inline_eap_user_info_cui_id)
    {
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_eap_user_info_cui_id);
    }
#if 0
#ifdef __MMI_OP01_WIFI__
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

#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    else if (inline_abort_event->sender_id == g_wlan_display_context.inline_wapi_cert_cui_id)
    {
        g_wlan_display_context.wapi_is_auto_connect = MMI_FALSE;
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_wapi_cert_cui_id);
    }
    else if (inline_abort_event->sender_id == g_wlan_display_context.inline_wapi_psk_cui_id)
    {
        mmi_wlan_close_inline_cui(&g_wlan_display_context.inline_wapi_psk_cui_id);
    }
#endif /* __MMI_HIDE_WAPI__ */
#endif
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_CLOSE_INLINE_CUI, inline_abort_event->sender_id);
        cui_inline_close(inline_abort_event->sender_id);
    }
}

void mmi_wlan_cui_inline_screen_active_evt_proc(mmi_event_struct *evt)
{
    cui_event_inline_common_struct *inline_common_event;
    U8 *pString = NULL;

    inline_common_event = (cui_event_inline_common_struct*)evt;
    if (inline_common_event->sender_id == g_wlan_display_context.inline_setting_cui_id)
    {
        if(g_wlan_display_context.modified == TRUE)
        {
            cui_inline_set_screen_attributes(
                g_wlan_display_context.inline_setting_cui_id, 
                CUI_INLINE_SET_ATTRIBUTE, 
                CUI_INLINE_SCREEN_CHANGED);
        }
        cui_inline_set_fullscreen_edit_title_icon(g_wlan_display_context.inline_setting_cui_id, 
			                                      CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_NAME, 
			                                      GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));
		cui_inline_set_fullscreen_edit_title_icon(g_wlan_display_context.inline_setting_cui_id, 
			                                      CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_SSID, 
			                                      GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID));

        switch (g_wlan_display_context.network_type)
        {
        case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE_INFRA);
            break;
        case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
            pString = (PU8) GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE_ADHOC);
            break;
        }
        cui_inline_set_value(g_wlan_display_context.inline_setting_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_NETWORK_TYPE, pString); 

        if (g_wapi_test_mode)
        {
            switch (g_wlan_display_context.auth_mode)
            {
            case SRV_DTCNT_WLAN_AUTH_MODE_OPEN:
                pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_OPEN);
                break;
			case SRV_DTCNT_WLAN_AUTH_MODE_TOTAL:
				pString = (PU8) GetString(STR_GLOBAL_NOT_SUPPORTED);
				break;
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
            case SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT:
                pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WAPICERT);
                break;
            case SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK:
                pString = (PU8) GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_WAPIPSK);
                break;
#endif /* __MMI_HIDE_WAPI__ */
#endif
            }
            cui_inline_set_value(
                g_wlan_display_context.inline_setting_cui_id, 
                CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_AUTH_MODE, 
                pString); 

            switch (g_wlan_display_context.auth_mode)
            {
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
            case SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK:
                pString = (PU8) GetString(STR_ID_DTCNT_WLAN_WAPI_PSK_SETTINGS);
                break;
            case SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT:
                pString = (PU8) GetString(STR_ID_DTCNT_WLAN_WAPI_CERT_SETTINGS);
                break;
#endif /* __MMI_HIDE_WAPI__ */
#endif 
            default:
                pString = (U8*) GetString(STR_ID_DTCNT_WLAN_ERROR_NO_AUTH_SETTING);
                cui_inline_set_item_attributes(g_wlan_display_context.inline_setting_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_SECURITY_SETTINGS, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_ITEM_DISABLE);
                break;
            }
            cui_inline_set_value(g_wlan_display_context.inline_setting_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_NETWORK_EDIT_SECURITY_SETTINGS, pString); 
        }
        else
        {
            mmi_wlan_update_auth_mode_setting ();
        }
    }   /* inline_setting_cui_id */
    
    if (inline_common_event->sender_id == g_wlan_display_context.inline_wapi_cert_cui_id)
    {
        /* refresh */
        if (0 != g_wlan_display_context.wapi_ase_id &&
        mmi_ucs2strlen(g_wlan_display_context.wapi_ase_name) > 0)
        {
            cui_inline_set_value(
                g_wlan_display_context.inline_wapi_cert_cui_id, 
                CUI_INLINE_ITEM_ID_BASE + WLAN_WAPI_EDIT_ASE_CERT, 
                (PU8)g_wlan_display_context.wapi_ase_name);
        }
        else
        {
            cui_inline_set_value(
                g_wlan_display_context.inline_wapi_cert_cui_id, 
                CUI_INLINE_ITEM_ID_BASE + WLAN_WAPI_EDIT_ASE_CERT, 
                (PU8)GetString(STR_GLOBAL_NONE));
        }

        if (0 != g_wlan_display_context.wapi_client_id &&
            mmi_ucs2strlen(g_wlan_display_context.wapi_client_name) > 0)
        {
            cui_inline_set_value(
                g_wlan_display_context.inline_wapi_cert_cui_id, 
                CUI_INLINE_ITEM_ID_BASE + WLAN_WAPI_EDIT_USER_CERT, 
                (PU8)g_wlan_display_context.wapi_client_name);
        }
        else
        {
            cui_inline_set_value(
                g_wlan_display_context.inline_wapi_cert_cui_id, 
                CUI_INLINE_ITEM_ID_BASE + WLAN_WAPI_EDIT_USER_CERT, 
                (PU8)GetString(STR_GLOBAL_NONE));
        }

        if (g_wlan_display_context.wapi_is_cert_changed)
        {
            g_wlan_display_context.wapi_is_cert_changed = MMI_FALSE;
            cui_inline_set_screen_attributes(g_wlan_display_context.inline_wapi_cert_cui_id, CUI_INLINE_SET_ATTRIBUTE, CUI_INLINE_SCREEN_CHANGED);
        }
    }
    
    if (inline_common_event->sender_id == g_wlan_display_context.inline_eap_ttls_cui_id)
    {
        if ((g_wlan_display_context.modified2 == TRUE) || modified3)
        {
            cui_inline_set_screen_attributes(
                g_wlan_display_context.inline_eap_ttls_cui_id, 
                CUI_INLINE_SET_ATTRIBUTE, 
                CUI_INLINE_SCREEN_CHANGED);
        }
        pString = (U8*) GetString(STR_GLOBAL_NONE);

#ifdef __CERTMAN_SUPPORT__
        if (mmi_ucs2strlen(g_wlan_display_context.root_ca_name) > 0)
        {
            pString = (U8*)g_wlan_display_context.root_ca_name;
        }
#else
        if (mmi_ucs2strlen(g_wlan_display_context.root_ca_path) > 0)
        {
            pString = (U8*) g_wlan_display_context.root_ca_path;
        }
#endif /* __CERTMAN_SUPPORT__ */
        else
        {
            pString = (U8*) GetString(STR_GLOBAL_NONE);
        }
        cui_inline_set_value(g_wlan_display_context.inline_eap_ttls_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TTLS_SETTINGS_CA_CERT, pString);
    }
    
    if (inline_common_event->sender_id == g_wlan_display_context.inline_eap_peap_cui_id)
    {
        if ((g_wlan_display_context.modified2 == TRUE) || modified3)
        {
            cui_inline_set_screen_attributes(
                g_wlan_display_context.inline_eap_peap_cui_id, 
                CUI_INLINE_SET_ATTRIBUTE, 
                CUI_INLINE_SCREEN_CHANGED);
        }
        pString = (U8*) GetString(STR_GLOBAL_NONE);

#ifdef __CERTMAN_SUPPORT__
        if (mmi_ucs2strlen(g_wlan_display_context.root_ca_name) > 0)
        {
            pString = (U8*)g_wlan_display_context.root_ca_name;
        }
#else
        if (mmi_ucs2strlen(g_wlan_display_context.root_ca_path) > 0)
        {
            pString = (U8*) g_wlan_display_context.root_ca_path;
        }
#endif /* __CERTMAN_SUPPORT__ */
        else
        {
            pString = (U8*) GetString(STR_GLOBAL_NONE);
        }
        cui_inline_set_value(g_wlan_display_context.inline_eap_peap_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_PEAP_SETTINGS_CA_CERT, pString);     
    }
    
    if (inline_common_event->sender_id == g_wlan_display_context.inline_eap_tls_cui_id)
    {
        if (g_wlan_display_context.modified2 == TRUE)
        {
            cui_inline_set_screen_attributes(
                g_wlan_display_context.inline_eap_tls_cui_id,
                CUI_INLINE_SET_ATTRIBUTE, 
                CUI_INLINE_SCREEN_CHANGED);
        }
#ifdef __CERTMAN_SUPPORT__
        if (mmi_ucs2strlen(g_wlan_display_context.root_ca_name) > 0)
        {
            pString = (U8*)g_wlan_display_context.root_ca_name;
        }
#else
        if (mmi_ucs2strlen(g_wlan_display_context.root_ca_path) > 0)
        {
            pString = (U8*)g_wlan_display_context.root_ca_path;
        }
#endif /* __CERTMAN_SUPPORT__ */
        else
        {
            pString = (U8*)GetString(STR_GLOBAL_NONE);
        }
        cui_inline_set_value(g_wlan_display_context.inline_eap_tls_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_CA_CERT, pString); 

#ifdef __CERTMAN_SUPPORT__   
        if (mmi_ucs2strlen(g_wlan_display_context.client_user_name) > 0)
        {
            pString = (U8*)g_wlan_display_context.client_user_name;
            cui_inline_set_value(g_wlan_display_context.inline_eap_tls_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_USER_CERT, g_wlan_display_context.client_user_name); 
        }
#else
        if (mmi_ucs2strlen(g_wlan_display_context.client_ca_path) > 0)
        {
            pString = (U8*)g_wlan_display_context.client_ca_path;
        }
#endif /* __CERTMAN_SUPPORT__ */
        else
        {
            pString = (U8*)GetString(STR_GLOBAL_NONE);
        }
        cui_inline_set_value(g_wlan_display_context.inline_eap_tls_cui_id, CUI_INLINE_ITEM_ID_BASE + WLAN_EAP_TLS_SETTINGS_USER_CERT, pString); 

    }
}

/*****************************************************************************
* FUNCTION
*  mmi_wlan_cui_inline_notify_event_proc
* DESCRIPTION
*  data account cui event proc
*  
* PARAMETERS
*  mmi_event_struct      [IN]        
* RETURNS
*  return void
 *****************************************************************************/
void mmi_wlan_cui_inline_notify_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/    
    cui_event_inline_notify_struct *notify_evt;
    U8 operation;

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    notify_evt = (cui_event_inline_notify_struct *)evt;

    switch (notify_evt->event_type)
    {
    case CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED:
        if (notify_evt->sender_id == g_wlan_display_context.wlan_advan_cui_id)
        {
            switch (notify_evt->item_id)
            {                                           
            case WLAN_ADVAN_USER_PROXY_SELECT_ID:
                operation = (notify_evt->param ? CUI_INLINE_RESET_ATTRIBUTE : CUI_INLINE_SET_ATTRIBUTE);
                cui_inline_set_item_attributes(
                    notify_evt->sender_id,
                    WLAN_ADVAN_PROXY_ADDR_IP4_ID,
                    operation,
                    CUI_INLINE_ITEM_DISABLE);
                cui_inline_set_item_attributes(
                    notify_evt->sender_id,
                    WLAN_ADVAN_PROXY_PORT_TEXTEDIT_ID,
                    operation,
                    CUI_INLINE_ITEM_DISABLE);
                cui_inline_set_item_attributes(
                    notify_evt->sender_id,
                    WLAN_ADVAN_PROXY_USERNAME_FSEDIT_ID,
                    operation,
                    CUI_INLINE_ITEM_DISABLE);
                cui_inline_set_item_attributes(
                    notify_evt->sender_id,
                    WLAN_ADVAN_PROXY_PASSWD_FSEDIT_ID,
                    operation,
                    CUI_INLINE_ITEM_DISABLE);                
                break;

            default:
                break;
            }
        }
        if (notify_evt->sender_id == g_wlan_display_context.inline_tcp_ip_cui_id)
        {
            switch (notify_evt->item_id)
            { 
            case CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_TCPIP_USEDHCP:
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
				#else

				mmi_wlan_set_inline_dhcp_info_attr(notify_evt->sender_id,notify_evt->param);

				#endif

                g_wlan_display_context.use_dhcp = notify_evt->param;

                break;
                
            default:
                break;
            }
        }

        if (notify_evt->sender_id == g_wlan_display_context.inline_wep_cui_id)
        {
            switch (notify_evt->item_id)
            {
            case CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY_ID:
                mmi_wlan_wep_settings_key_id_highlight_hdlr(notify_evt->param);
                break;

            case CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY_ENCRYPT:
                mmi_wlan_wep_settings_key_len_highlight_hdlr(notify_evt->param);
                break;

            case CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY_FORMAT:
                mmi_wlan_wep_settings_key_format_highlight_hdlr(notify_evt->param);
                break;
                
            default:
                break;
            }
        }

#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
        if (notify_evt->sender_id == g_wlan_display_context.inline_wapi_psk_cui_id)
        {
            switch (notify_evt->item_id)
            {
            case CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WAPI_PSK_EDIT_KEY_FORMAT:
                g_wlan_display_context.wapi_psk_format = notify_evt->param;                
                break;

            default:
                break;
            }
        }
#endif /* __MMI_HIDE_WAPI__ */
#endif
#if 0
#ifdef __MMI_OP01_WIFI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

        break;

    case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
        if (notify_evt->sender_id == g_wlan_display_context.inline_wep_cui_id)
        {
            switch (notify_evt->item_id)
            {
            case CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY:
                cui_inline_get_value(notify_evt->sender_id, 
                    CUI_INLINE_ITEM_ID_BASE + WLAN_CUINLINE_WEP_EDIT_WEP_KEY, 
                    g_wlan_display_context.sel_wep_key_str);
                break;
            default:
                break;
            }            
        }
        break;
        
    case CUI_INLINE_NOTIFY_ITEM_CHANGED:
        break;

    default:
        break;
    }
    
}

//remove for option slim
#if 0
/* under construction !*/
/* under construction !*/
#endif
#if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_replacement_highlight_hdlr
 * DESCRIPTION
 *  This highlight handler remembers the item chosen to be replaced.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_prov_replacement_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur_wlan_prov_list_index = index;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_prov_replacement
 * DESCRIPTION
 *  This highlight handler remembers the item chosen to be replaced.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_prov_replacement(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prov_ind.cnf_callback)
    {
        g_prov_ind.cnf_callback(SRV_DTCNT_PROV_CNF_REPLACE, cur_wlan_prov_list_index);
        memset(&g_prov_ind, 0, sizeof(srv_dtcnt_prov_ind_evt_struct));
    }

    mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_INSTALL_PROFILE);
	mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_replacement
 * DESCRIPTION
 *  This function shows all WLAN profiles installed on the system such that 
 *  users can select an existing profile to be replaced.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_prov_entry_replacement(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *prof_name[MAX_WLAN_DATA_ACCOUNT_NUM];
    U8 *gui_buffer;
    U8 count = 0;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    while(g_prov_ind.prof_name_list[count] && count < MAX_WLAN_DATA_ACCOUNT_NUM - 1)
    {
        count++;
    }

    memset(prof_name, 0, MAX_WLAN_DATA_ACCOUNT_NUM * sizeof(U8 *));

    for (i = 0; i < count; i++)
    {
        prof_name[i] = (U8 *)g_prov_ind.prof_name_list[i];
    }

    /* 
         * Entry screen.
         */
    if (!mmi_frm_scrn_enter(
        wlan_parent_group_id,
        SCR_ID_DTCNT_WLAN_REPLACE_PROFILE,
        NULL,
        mmi_wlan_prov_entry_replacement,
        MMI_FRM_FULL_SCRN))
    {
        return;
    } 

    gui_buffer = mmi_frm_scrn_get_gui_buf(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_REPLACE_PROFILE);

    RegisterHighlightHandler(mmi_wlan_prov_replacement_highlight_hdlr);

    /* TODO: gIndexIconsImageList only has numeric icons from 1 to 30. */
    ShowCategory53Screen(
        STR_ID_DTCNT_WLAN_REPLACE_PROFILE,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        count,
        prof_name,
        (U16 *)gIndexIconsImageList,
        NULL,
        0,
        0,
        gui_buffer);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_wlan_prov_replacement, KEY_EVENT_UP);

    SetLeftSoftkeyFunction(mmi_wlan_prov_replacement, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_prov_profile_skip_confirm
 * DESCRIPTION
 *  This function is responsible for processing provisioning cancel confirm
 *  data account.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_wlan_prov_profile_skip_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_prov_ind.cnf_callback)
    {
        g_prov_ind.cnf_callback(SRV_DTCNT_PROV_CNF_SKIP, g_prov_ind.cur_prof_idx);
        memset(&g_prov_ind, 0, sizeof(srv_dtcnt_prov_ind_evt_struct));
    }

    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  cui_dtcnt_leave_callback
 * DESCRIPTION
 *  Account bearer list leave function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_wlan_leave_callback(mmi_event_struct* pevt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												 */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body 													 */
    /*----------------------------------------------------------------*/
    
	//	 MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_DTCNT_OTA_INTALL_ABORT);
	  
    mmi_frm_scrn_set_leave_proc (wlan_parent_group_id, SCR_ID_DTCNT_WLAN_INSTALL_PROFILE, NULL);

    if (g_prov_ind.cnf_callback)
    {
        g_prov_ind.cnf_callback(SRV_DTCNT_PROV_CNF_ABORT, g_prov_ind.cur_prof_idx);
        memset(&g_prov_ind, 0, sizeof(srv_dtcnt_prov_ind_evt_struct));
	
    }

    return MMI_RET_OK;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_prov_install_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_prov_install_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    if (g_prov_ind.cnf_callback)
    {
        g_prov_ind.cnf_callback(SRV_DTCNT_PROV_CNF_INSTALL,g_prov_ind.cur_prof_idx);
        memset(&g_prov_ind, 0, sizeof(srv_dtcnt_prov_ind_evt_struct));
    }

    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_prov_entry_install_wlan
 * DESCRIPTION
 *  To entry wlan provisioning install screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_wlan_prov_entry_install_wlan(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    srv_dtcnt_prov_wlan_ind_struct *wlan_prov_prof;

    CHAR *info;
    U8 *gui_buffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    wlan_prov_prof = (srv_dtcnt_prov_wlan_ind_struct *)g_prov_ind.prof_data;
    
    /* Obtain a temporary buffer to show messages. */
    info = (CHAR *)subMenuData;
    
    /* Profile name */
    if (wlan_prov_prof->AccountName)
    {
        mmi_ucs2cpy((CHAR*)info, GetString(STR_ID_DTCNT_WLAN_NAME));
        
        mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_COLON));
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"	");
        mmi_ucs2cat((CHAR*)info, (const CHAR*)wlan_prov_prof->AccountName);
        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n\n");
    }
    
    /* SSID */
    if (wlan_prov_prof->SSID)
    {
    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SSID));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_COLON));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)L"	");
    mmi_asc_to_ucs2(info + mmi_ucs2strlen(info) * ENCODING_LENGTH, (CHAR*)wlan_prov_prof->SSID);
    mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n\n");
    }
    
    /* Network type */
    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_COLON));
    
    mmi_ucs2cat((CHAR*)info, (const CHAR*)L"	");
	
    switch (wlan_prov_prof->network_type)
    {
        case SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC:
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE_ADHOC));
            break;
        
        case SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA:
            mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_NETWORK_TYPE_INFRA));
            break;
        
        default:
            MMI_ASSERT(0);	/* Impossible to reach here. */
    }
	
    mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n\n");
	
    /* 
     * Security solution 
     */    
    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_SECURITY));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_COLON));
    mmi_ucs2cat((CHAR*)info, (const CHAR*)L"	");
	
    switch (wlan_prov_prof->auth_mode)
    {
        case SRV_DTCNT_WLAN_AUTH_MODE_OPEN:
	
            if (wlan_prov_prof->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP) 
            {
                mmi_ucs2cat((CHAR*)info, (const CHAR*)L"WEP\n\n");
            } 
            else 
            {
                mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_OPEN));
            }
            break;
	
        case SRV_DTCNT_WLAN_AUTH_MODE_WEP:
            if (wlan_prov_prof->encrypt_mode == SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP) 
            {
                mmi_ucs2cat((CHAR*)info, (const CHAR*)L"WEP\n\n");
            } 
            else /* SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE */
            {
                mmi_ucs2cat((CHAR*)info, (const CHAR*)GetString(STR_ID_DTCNT_WLAN_AUTH_MODE_SHARED));
                mmi_ucs2cat((CHAR*)info, (const CHAR*)L"\n\n");
            }
            break;
				
        case SRV_DTCNT_WLAN_AUTH_MODE_IEEE8021X:
				
            mmi_ucs2cat((CHAR*)info, (const CHAR*)L"IEEE802.1X\n\n");
            break;

        case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY:
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY:
        // case SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX:
	
            switch (wlan_prov_prof->encrypt_mode) 
            {
                case SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP:
                    mmi_ucs2cat((CHAR*)info, (const CHAR*)L"WPA\n\n");
                    break;
            
                case SRV_DTCNT_WLAN_ENCRYPT_MODE_AES:
                    mmi_ucs2cat((CHAR*)info, (const CHAR*)L"WPA2\n\n");
                    break;
            
                default:
                    MMI_ASSERT(0);	/* Impossible to reach here. */
            }
            break;
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK:
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK:
        // case SRV_DTCNT_WLAN_AUTH_MODE_WPA_WPA2_MIX_PSK:
            if (wlan_prov_prof->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC)
            {
                /* No matter the encryption method is TKIP or AES, this is 
                             callled WPA-NONE for ad-hoc network. */
                mmi_ucs2cat((CHAR*)info, (const CHAR*)L"WPA-None\n\n");
            }
            else
            {
                /* For infrastructure mode, determine it by the encryption. */
                switch (wlan_prov_prof->encrypt_mode) 
                {
                    case SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP:
                        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"WPA-PSK\n\n");
                        break;
    					
                    case SRV_DTCNT_WLAN_ENCRYPT_MODE_AES:
                        mmi_ucs2cat((CHAR*)info, (const CHAR*)L"WPA2-PSK\n\n");
                        break;
    					
                    default:
                        MMI_ASSERT(0);	/* Impossible to reach here. */
                }
            }
            break;
	
        default:
	
            /* After profile validation, it's impossible to reach here. */
            MMI_ASSERT(0);
    }
			

    /* 
         * Entry screen. 
         */
    if (!mmi_frm_scrn_enter(
        wlan_parent_group_id,
        SCR_ID_DTCNT_WLAN_INSTALL_PROFILE,
        NULL,
        mmi_wlan_prov_entry_install_wlan,
        MMI_FRM_FULL_SCRN))
    {
        return;
    } 
	
    gui_buffer = mmi_frm_scrn_get_gui_buf(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_INSTALL_PROFILE);

    ShowCategory74Screen(
        STR_ID_CCA_INSTALL_SETTING,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        STR_GLOBAL_INSTALL,
        IMG_GLOBAL_YES,
        STR_ID_CCA_SKIP,
        IMG_GLOBAL_NO,
        (U8 *)info,
        MAX_SUB_MENUS * MAX_SUB_MENU_SIZE,
        gui_buffer);
	
    if (g_prov_ind.prov_type == SRV_DTCNT_PROV_TYPE_REPLACE)
    {
		ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
		SetCenterSoftkeyFunction(mmi_wlan_prov_entry_replacement, KEY_EVENT_UP);

    SetLeftSoftkeyFunction(mmi_wlan_prov_entry_replacement, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_wlan_prov_profile_skip_confirm, KEY_EVENT_UP);
    }
    else
    {
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_wlan_prov_install_rsp, KEY_EVENT_UP);

        SetLeftSoftkeyFunction(mmi_wlan_prov_install_rsp, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_wlan_prov_profile_skip_confirm, KEY_EVENT_UP);
    }
		
    /* Delete screens associated with previous profile. Clear delete screen 
       callback temporarily to prevent from terminating app. */
    mmi_frm_scrn_set_leave_proc (wlan_parent_group_id, SCR_ID_DTCNT_WLAN_INSTALL_PROFILE, mmi_wlan_leave_callback);
}
#endif /* defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__) */

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_prov_install_one_done
 * DESCRIPTION
 *  To update wlan profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 *****************************************************************************/
void mmi_wlan_prov_install_one_done(U32 acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    srv_dtcnt_result_enum result;
    srv_dtcnt_store_prof_qry_struct acct_id_query; 
    srv_dtcnt_store_prof_data_struct prof_info;
	
    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/

    acct_id_query.qry_info.filters = SRV_DTCNT_STORE_QRY_TYPE_BEARER_TYPE;
    acct_id_query.qry_info.bearer_qry_info = SRV_DTCNT_BEARER_WIFI;
    result = srv_dtcnt_store_qry_ids(&acct_id_query);
    
    if (result == SRV_DTCNT_RESULT_FS_ERROR || acct_id_query.num_ids > SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM)
    {
    	return;
    }
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_INIT_RESULT, result, acct_id_query.num_ids);
    
    g_wlan_display_context.prof_num = 0;
    g_wlan_display_context.infra_prof_num = 0;
    g_wlan_display_context.adhoc_prof_num = 0;
    
    for (i = 0; i < acct_id_query.num_ids; i++)
    {
        prof_info.prof_type = SRV_DTCNT_BEARER_WIFI;
        prof_info.prof_data = &g_srv_wlan_prof;
        prof_info.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;
    	
        result =  srv_dtcnt_store_qry_prof(acct_id_query.ids[i], &prof_info);
    
    	MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, MMI_WLAN_INIT_PROFILE, g_srv_wlan_prof.profile_id, g_srv_wlan_prof.priority, i);
    
        mmi_wlan_srv2app_profile_convert(&g_srv_wlan_prof, &(g_wlan_prof_list[i]), 1);
        if (g_wlan_prof_list[i].priority > 0 && g_wlan_prof_list[i].ssid_len)
        {
        	g_wlan_profile[g_wlan_prof_list[i].priority - 1] = &g_wlan_prof_list[i];
        	g_wlan_display_context.prof_num++;
        	if(g_wlan_prof_list[i].network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
        	{
        		g_wlan_display_context.infra_prof_num++;
        	}
        	else
        	{
        		g_wlan_display_context.adhoc_prof_num++;
        	}
        }
        else
        {
        	memset(&g_wlan_prof_list[i], 0, sizeof(mmi_wlan_profile_struct));
        }
    }
    
}

void mmi_wlan_set_power_mode_processing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (!mmi_frm_scrn_enter(
            wlan_parent_group_id,
            SCR_ID_DTCNT_WLAN_POWER_MODE_PROCESSING,
            NULL,
            mmi_wlan_set_power_mode_processing,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }


    ShowCategory66Screen(
        STR_ID_DTCNT_WLAN_POWER_SAVE,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        0,
        0,
        0, //STR_GLOBAL_BACK,
        0, //IMG_GLOBAL_BACK,
        (U8*) GetString(STR_GLOBAL_PLEASE_WAIT),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
    // SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_set_power_mode_cb_hdlr
 * DESCRIPTION
 * callback for set Power Save Mode
 *  
 * PARAMETERS
 *  user_data
 *  res: response from service
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_set_power_mode_cb_hdlr(void *user_data, srv_dtcnt_wlan_req_res_enum res)
{
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT,MMI_WLAN_RESULT_OF_SET_POWER_SAVE_MODE_CB,res);
    g_wlan_set_power_mode_state = SRV_DTCNT_RESULT_SUCCESS;
    if(mmi_frm_scrn_get_active_id() == SCR_ID_DTCNT_WLAN_POWER_MODE_PROCESSING)
    {
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_POWER_MODE_PROCESSING);
        
        if(SRV_DTCNT_WLAN_REQ_RES_DONE == res)
        {      
            mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, wlan_parent_group_id, NULL);
        }
        else
        {
            mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_ERROR)), MMI_EVENT_FAILURE, wlan_parent_group_id, NULL);
        }
    
        mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_POWER_SAVE_MODE);
        mmi_wlan_close_menu_cui (&g_wlan_display_context.option_menu_cui_id);    
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_power_save_mode_ok
 * DESCRIPTION
 * handler for select Power Save Mode
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/

void mmi_wlan_power_save_mode_ok(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_power_mode_enum power_mode = SRV_DTCNT_WLAN_WLAN_POWER_MODE_TOTAL;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(g_wlan_power_save_mode_index)
    {
        case 0:
            power_mode = SRV_DTCNT_WLAN_WLAN_POWER_MODE_CAM;
            break;
            
        case 1:
            power_mode = SRV_DTCNT_WLAN_WLAN_POWER_MODE_FAST_PS;
            break;

        case 2:
            power_mode = SRV_DTCNT_WLAN_WLAN_POWER_MODE_MAX_PS;
            break;

        case 3:
            power_mode = SRV_DTCNT_WLAN_WLAN_POWER_MODE_CTIA;
            break;

        default:
            break;
    }
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT,MMI_WLAN_POWER_SAVE_MODE_TO_SET,power_mode);
    if(g_wlan_set_power_mode_state == SRV_DTCNT_RESULT_PROCESSING)
    {
        mmi_wlan_set_power_mode_processing();
    }
    else
    {
        g_wlan_set_power_mode_state = srv_dtcnt_wlan_set_power_mode(power_mode, mmi_wlan_set_power_mode_cb_hdlr, NULL);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT,MMI_WLAN_RESULT_OF_SET_POWER_SAVE_MODE,g_wlan_set_power_mode_state);
        if(SRV_DTCNT_RESULT_FAILED == g_wlan_set_power_mode_state)
        {
            mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_ERROR)), MMI_EVENT_FAILURE, wlan_parent_group_id, NULL);
            mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_POWER_SAVE_MODE);
            mmi_wlan_close_menu_cui (&g_wlan_display_context.option_menu_cui_id);             
            return;
        }
        if(SRV_DTCNT_RESULT_SUCCESS == g_wlan_set_power_mode_state)
        {
            mmi_popup_display_simple((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, wlan_parent_group_id, NULL);
            mmi_frm_scrn_close(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_POWER_SAVE_MODE);
            mmi_wlan_close_menu_cui (&g_wlan_display_context.option_menu_cui_id);             
            return;

        }
        mmi_wlan_set_power_mode_processing();
    }

    
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_power_save_mode_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for Power Save Mode
 *  
 *  Index values start on zero for first Listesd item.
 * PARAMETERS
 *  nIndex      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_power_save_mode_highlight_hdlr(S32 nIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wlan_power_save_mode_index = nIndex;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_wlan_entry_power_save_mode
 * DESCRIPTION
 *  entry function for Power Save Mode
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_wlan_entry_power_save_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                  */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U8 *nStrList[4];
    U16 nNumofItem = 0;
    srv_dtcnt_wlan_power_mode_enum out_pwr_mode;
    srv_dtcnt_result_enum result_get_power_mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                       */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
            wlan_parent_group_id,
            SCR_ID_DTCNT_WLAN_POWER_SAVE_MODE,
            NULL,
            mmi_wlan_entry_power_save_mode,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_gui_buf(wlan_parent_group_id, SCR_ID_DTCNT_WLAN_POWER_SAVE_MODE);

    if(NULL == guiBuffer)
    {

    }

    RegisterHighlightHandler(mmi_wlan_power_save_mode_highlight_hdlr);

    nStrList[0] = (U8*) GetString(STR_ID_DTCNT_WLAN_POWER_MODE_CAM);
    nStrList[1] = (U8*) GetString(STR_ID_DTCNT_WLAN_POWER_MODE_FAST_PS);
    nStrList[2] = (U8*) GetString(STR_ID_DTCNT_WLAN_POWER_MODE_MAX_PS);
    nStrList[3] = (U8*) GetString(STR_ID_DTCNT_WLAN_POWER_MODE_CTIA); 
    nNumofItem = 4; 

    result_get_power_mode = srv_dtcnt_wlan_get_power_mode(&out_pwr_mode);
    if(SRV_DTCNT_RESULT_SUCCESS == result_get_power_mode)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT,MMI_WLAN_POWER_SAVE_MODE_IN_SERVICE,out_pwr_mode);
        switch(out_pwr_mode)
        {
            case SRV_DTCNT_WLAN_WLAN_POWER_MODE_CAM:
                g_wlan_power_save_mode = 0;
                break;
            case SRV_DTCNT_WLAN_WLAN_POWER_MODE_FAST_PS:
                g_wlan_power_save_mode = 1;
                break;
            case SRV_DTCNT_WLAN_WLAN_POWER_MODE_MAX_PS:
                g_wlan_power_save_mode = 2;
                break;
            case SRV_DTCNT_WLAN_WLAN_POWER_MODE_CTIA:
                g_wlan_power_save_mode = 3;
                break;
            default:
                g_wlan_power_save_mode = 0;
                
        }
    }
    
    ShowCategory109Screen(
        STR_ID_DTCNT_WLAN_POWER_SAVE,
        GetRootTitleIcon(MAIN_MENU_WLAN_WIZARD_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nNumofItem,
        nStrList,
        NULL,
        g_wlan_power_save_mode,
        guiBuffer);  

//#ifndef __MMI_WGUI_DISABLE_CSK__
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_wlan_power_save_mode_ok, KEY_EVENT_UP);
//#endif
    /* Register function with left/right softkey */
    SetLeftSoftkeyFunction(mmi_wlan_power_save_mode_ok, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

#endif /* __MMI_WLAN_FEATURES__ */ 
#endif /* __TCPIP__ */ 
