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
 * CustCoordinates.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for define control sets and coordinate sets.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "Gui_Setting.h"
#include "wgui.h"
#include "wgui_categories.h"
#include "wgui_categories_calendar.h"
#include "wgui_categories_list.h"
#include "wgui_categories_popup.h"
#include "wgui_categories_multimedia.h"
#include "wgui_categories_mm.h"
#include "wgui_categories_CM.h"
#include "wgui_categories_dialer.h"
#include "wgui_categories_ems.h"
#include "wgui_categories_sublcd.h"
#include "wgui_virtual_keyboard.h"
#include "wgui_categories_op.h"
#include "wgui_categories_util.h"
#include "wgui_categories_uce.h"
#include "wgui_categories_sns.h"

#ifdef __MMI_DICTIONARY__
#include "DictionaryResDef.h"
#endif 
#include "wgui_draw_manager.h"
#include "wgui.h"
#ifdef __MMI_SCREEN_ROTATE__
#include "ScreenRotationGprot.h"
#if defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__)
#error "128x128 and 128x160 did not support screen rotate"
#endif 
#endif /* __MMI_SCREEN_ROTATE__ */ 

#include "wgui_categories_idlescreen_op.h"
#include "MMIDataType.h"
#include "gui_switch.h"
#include "lcd_sw_inc.h"
#include "gui_config.h"
#include "wgui_categories_text_viewer.h"
#include "wgui_categories.h"
#include "wgui_categories_inputs.h"
#include "wgui_categories_search.h"
#include "wgui_categories_idlescreen_op.h"
#include "wgui_categories_stopwatch.h"
#include "gui_data_types.h"
#include "wgui_categories_op.h"
#include "wgui_categories_enum.h"
#include "PhoneBookResDef.h"
#ifdef __MMI_FACTORY_MODE__
#include "mmi_rp_app_factorymode_def.h"
#endif
#define  __MMI_CAT_SUPPORT_ASYNC_FMGR__

#define DM_MMI_CONTENT_WIDTH_WITH_H_TAB            (MMI_CONTENT_WIDTH)
#define DM_MMI_CONTENT_HEIGHT_WITH_H_TAB           (MMI_CONTENT_HEIGHT + MMI_TITLE_HEIGHT - MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT)
#define DM_MMI_CONTENT_X_WITH_H_TAB                (MMI_CONTENT_X)
#define DM_MMI_CONTENT_Y_WITH_H_TAB                (MMI_CONTENT_Y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT - MMI_TITLE_HEIGHT)

/***************************************************************************** 
* Global Variable
*****************************************************************************/
#define CONTROL_SET_START
#if !defined(__MMI_MAINLCD_96X64__) && !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__)
const U8 dm_base_control_set[] = 
{
    3,
    DM_STATUS_BAR1,
    DM_TITLE1,
    DM_BUTTON_BAR1
};
const S16 dm_base_coordinate_set[] = 
{
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DEFAULT_TITLE_BAR_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else /* !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__) */ 
const U8 dm_base_control_set[] = 
{
    2,
    DM_TITLE1,
    DM_BUTTON_BAR1
};
const S16 dm_base_coordinate_set[] = 
{
    DM_DEFAULT_TITLE_BAR_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__) */ 

#if defined(__MMI_SCREEN_ROTATE__)

/* DM_SCR_BG is mandatory for rotated screen */
const U8 dm_base_rotated_control_set[] = 
{
    /* Double layer in popup screen do not need SCR_BG now */
    2,//3,
    //DM_SCR_BG,
    DM_TITLE1,
    DM_BUTTON_BAR1
};

const S16 dm_base_rotated_coordinate_set[] = 
{
    DM_DEFAULT_TITLE_BAR_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_ROTATED_SOFTKEY_WIDTH
};
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 

const U8 dm_base_control_set2[] = 
{
    2,
    DM_STATUS_BAR1,
    DM_BUTTON_BAR1
};
const S16 dm_base_coordinate_set2[] = 
{
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

#if defined(GUI_SUBMENU_USE_SPECIFIC_STYLE)
#if defined(GUI_SUBMENU_SHOW_STATUS_ICON)
const U8 dm_base_control_set_submenu[] = 
{
    3,
    DM_STATUS_BAR1,
    DM_TITLE1,
    DM_BUTTON_BAR1
};
const S16 dm_base_coordinate_set_submenu[] = 
{
    DM_DEFAULT_STATUS_BAR_FLAG,
#if defined(GUI_SUBMENU_USE_THICK_TITLE)
    MMI_TITLE_X, MMI_TITLE_Y, MMI_TITLE_WIDTH, MMI_THICK_TITLE_HEIGHT, DM_TITLE_SET_THICK,
#else /* defined(GUI_SUBMENU_USE_THICK_TITLE) */
    MMI_TITLE_X, MMI_TITLE_Y, MMI_TITLE_WIDTH, MMI_THIN_TITLE_HEIGHT, DM_NO_FLAGS,
#endif /* defined(GUI_SUBMENU_USE_THICK_TITLE) */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else /* defined(GUI_SUBMENU_SHOW_STATUS_ICON) */
const U8 dm_base_control_set_submenu[] = 
{
    2,
    DM_TITLE1,
    DM_BUTTON_BAR1
};
const S16 dm_base_coordinate_set_submenu[] = 
{
#if defined(GUI_SUBMENU_USE_THICK_TITLE)
    MMI_TITLE_X, 0, MMI_TITLE_WIDTH, MMI_THICK_TITLE_HEIGHT, DM_TITLE_SET_THICK,
#else /* defined(GUI_SUBMENU_USE_THICK_TITLE) */
    MMI_TITLE_X, 0, MMI_TITLE_WIDTH, MMI_THIN_TITLE_HEIGHT, DM_NO_FLAGS,
#endif /* defined(GUI_SUBMENU_USE_THICK_TITLE) */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* defined(GUI_SUBMENU_SHOW_STATUS_ICON) */
#endif /* defined(GUI_SUBMENU_USE_SPECIFIC_STYLE) */

#if defined(GUI_COMMON_USE_SPECIFIC_STYLE)
#if defined(GUI_COMMON_SHOW_STATUS_ICON)
const U8 dm_base_control_set_common[] = 
{
    3,
    DM_STATUS_BAR1,
    DM_TITLE1,
    DM_BUTTON_BAR1
};
const S16 dm_base_coordinate_set_common[] = 
{
    DM_DEFAULT_STATUS_BAR_FLAG,
#if defined(GUI_COMMON_USE_THICK_TITLE)
    MMI_TITLE_X, MMI_TITLE_Y, MMI_TITLE_WIDTH, MMI_THICK_TITLE_HEIGHT, DM_TITLE_SET_THICK,
#else /* defined(GUI_COMMON_USE_THICK_TITLE) */
    MMI_TITLE_X, MMI_TITLE_Y, MMI_TITLE_WIDTH, MMI_THIN_TITLE_HEIGHT, DM_NO_FLAGS,
#endif /* defined(GUI_COMMON_USE_THICK_TITLE) */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else /* defined(GUI_COMMON_SHOW_STATUS_ICON) */
const U8 dm_base_control_set_common[] = 
{
    2,
    DM_TITLE1,
    DM_BUTTON_BAR1
};
const S16 dm_base_coordinate_set_common[] = 
{
#if defined(GUI_COMMON_USE_THICK_TITLE)
    MMI_TITLE_X, 0, MMI_TITLE_WIDTH, MMI_THICK_TITLE_HEIGHT, DM_TITLE_SET_THICK,
#else /* defined(GUI_COMMON_USE_THICK_TITLE) */
    MMI_TITLE_X, 0, MMI_TITLE_WIDTH, MMI_THIN_TITLE_HEIGHT, DM_NO_FLAGS,
#endif /* defined(GUI_COMMON_USE_THICK_TITLE) */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* defined(GUI_COMMON_SHOW_STATUS_ICON) */
#endif /* defined(GUI_COMMON_USE_SPECIFIC_STYLE) */

const U8 category_controlled_set[] = 
{
    1,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 category_controlled_coordinate_set[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE
};

const U8 fixed_list_menu_category[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_LIST1
};

const U8 dynamic_list_menu_category[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_DYNAMIC_LIST1
};

const U8 asyncdynamic_list_menu_category[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_ASYNCDYNAMIC_LIST1
};

const S16 list_coordinate_set[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    //MMI_SUBMENU_CONTENT_X, MMI_SUBMENU_CONTENT_Y, MMI_SUBMENU_CONTENT_WIDTH, MMI_SUBMENU_CONTENT_HEIGHT, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
    DM_SUBMENU_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};

const U8 category_control_category_normal[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};
const U8 category_control_category_normal_bg[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 common_coordinate_set[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};

#if defined(__MMI_SCREEN_ROTATE__)      // TODO: revise
const S16 common_rotated_coordinate_set[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 

const U8 category_control_category_status_icon[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_STATUS_BAR1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 category_control_coordinate_set_status_icon[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category5[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set5[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_EDITOR_CONTENT_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG
};

const U8 category7[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1
};
const S16 coordinate_set7[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, MMI_TITLE_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_TITLE_HEIGHT - MMI_BUTTON_BAR_HEIGHT,
        DM_NO_FLAGS
};

const U8 category9[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_ALIGNED_AREA_START,
    DM_MULTILINE_INPUTBOX1,
    DM_IMAGE,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set9[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};

/* START VIJAY PMT 20050930 */
#if !defined(__MMI_BASIC_UI_STYLE__)
#ifdef __MMI_SMALL_LIST_SCREEN__
const U8 category10[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_RECTANGLE,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_LIST1,
    DM_BUTTON_BAR1
};

const S16 coordinate_set10[] = 
{
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,   /* Category Screen Coordinates */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,   /* greyscale rectangle */
    MMI_SMALL_SCREEN_X_OFFSET, MMI_TITLE_Y + MMI_TITLE_HEIGHT + MMI_SMALL_SCREEN_Y_OFFSET, UI_DEVICE_WIDTH - 2 * MMI_SMALL_SCREEN_X_OFFSET + 1, MMI_CONTENT_HEIGHT - 2 * MMI_SMALL_SCREEN_Y_OFFSET + 1, DM_NO_FLAGS,    /* control area */
    0, 0, 0, 0, DM_CATEGORY_CONTROL_COORDINATES, /* List */
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT,
    DM_NO_FLAGS, MMI_SOFTKEY_WIDTH        /* Button Bar */
};
#endif /* __MMI_SMALL_LIST_SCREEN__ */ 
#endif/*#if defined(__MMI_BASIC_UI_STYLE__)*/
/* END VIJAY PMT 20050930 */

/* Cascade Menu */
const U8 category800[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_LIST1,
    DM_BUTTON_BAR1
};

const S16 coordinate_set800[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, 0, 0, DM_CATEGORY_CONTROL_COORDINATES,
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS, MMI_SOFTKEY_WIDTH
};

#ifdef __MMI_SCREEN_ROTATE__
const S16 coordinate_set800_rotated[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_HEIGHT - MMI_SOFTKEY_WIDTH, MAIN_LCD_DEVICE_WIDTH, DM_CATEGORY_CONTROL_COORDINATES,
    MAIN_LCD_DEVICE_HEIGHT - MMI_SOFTKEY_WIDTH, 0, MMI_SOFTKEY_WIDTH, MAIN_LCD_DEVICE_WIDTH, DM_BUTTON_DISABLE_BACKGROUND, MMI_SOFTKEY_WIDTH
};
#endif /* __MMI_SCREEN_ROTATE__ */


const U8 category14_list[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set14_List_Page[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR, 
    DM_NO_FLAGS, 
    MMI_SOFTKEY_WIDTH
};

#ifndef GUI_MAINMENU_SHOW_STATUS_ICON
/* without status bar */
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
#endif

const U8 category14_matrix[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_TITLE1,
    DM_MATRIX_MENU1,
    DM_BUTTON_BAR1
};

const S16 coordinate_set14_Matrix[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MMI_TITLE_WIDTH, MMI_THIN_TITLE_HEIGHT, DM_NO_FLAGS,
    0, MMI_THIN_TITLE_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_THIN_TITLE_HEIGHT, DM_NO_FLAGS, 
    DM_DEFAULT_BUTTON_BAR, DM_NO_FLAGS, MMI_SOFTKEY_WIDTH
};

#else /* GUI_MAINMENU_SHOW_STATUS_ICON */

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
#endif
#if defined (__MMI_MAINLCD_320X480__) && defined(__MMI_MATRIX_MAIN_MENU_NO_TITLEBAR__)

#define CAGEGORY14_LEFT_GAP         10
#define CAGEGORY14_TOT_GAP          17
#define CAGEGORY14_RIGHT_GAP        10
#define CAGEGORY14_BOTTOM_GAP       7

const U8 category14_matrix[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_MATRIX_MENU1,
    DM_BUTTON_BAR1
};
#ifdef __MMI_FTE_SUPPORT__
const S16 coordinate_set14_Matrix[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    0, MMI_STATUS_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH,  MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_STATUS_BAR_HEIGHT, 
    DM_NO_FLAGS, 
    DM_DEFAULT_BUTTON_BAR, DM_NO_FLAGS, MMI_SOFTKEY_WIDTH
};
#else
const S16 coordinate_set14_Matrix[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    CAGEGORY14_LEFT_GAP, MMI_STATUS_BAR_HEIGHT + CAGEGORY14_TOT_GAP,
    MAIN_LCD_DEVICE_WIDTH - CAGEGORY14_LEFT_GAP - CAGEGORY14_RIGHT_GAP, 
    MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_STATUS_BAR_HEIGHT - CAGEGORY14_TOT_GAP - CAGEGORY14_BOTTOM_GAP, 
    DM_NO_FLAGS, 
    DM_DEFAULT_BUTTON_BAR, DM_NO_FLAGS, MMI_SOFTKEY_WIDTH
};
#endif
#else

const U8 category14_matrix[] = 
{
    5,
        DM_BASE_LAYER_START,
        DM_SCR_BG,
        DM_BASE_CONTROL_SET_COMMON,
        DM_MATRIX_MENU1,
        DM_BUTTON_BAR1
};

const S16 coordinate_set14_Matrix[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
        DM_CONTENT_COORDINATE_FLAG,
        DM_DEFAULT_BUTTON_BAR,
        DM_NO_FLAGS,
        MMI_SOFTKEY_WIDTH
};
#endif

#endif /* GUI_MAINMENU_SHOW_STATUS_ICON */ 

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
#endif

#ifdef __MMI_MOTION_MAINMENU__
const U8 category14_motion[] = 
{
    4,
    DM_NEW_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET2    
};

const S16 coordinate_set14_motion[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,                     /* DM_NEW_LAYER_START */
    DM_FULL_SCREEN_COORDINATE_FLAG,                     /* DM_CATEGORY_CONTROLLED_AREA */
 
};
#endif /* __MMI_MOTION_MAINMENU__ */

const U8 category15_matrix[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MATRIX_MENU1
};

#if !defined(__MMI_FTE_SUPPORT__) && (defined (__MMI_MAINLCD_240X320__) ||  defined (__MMI_MAINLCD_240X240__) || defined (__MMI_MAINLCD_320X240__)) && defined (__MMI_TOUCH_DIAL_SCREEN__)
const U8 category16[] = 
{
    5,
    DM_NEW_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BASE_LAYER_START,
 #ifdef __CAT16_MULTIEDITOR_STYLE__
 	DM_MULTILINE_INPUTBOX1,
 #else /*__CAT16_MULTIEDITOR_STYLE__*/
    DM_DIALER_INPUT_BOX1,
 #endif /*__CAT16_MULTIEDITOR_STYLE__*/
    DM_BUTTON_BAR1
};
const S16 coordinate_set16[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_DIALING_KEYPAD_LAYER_X, MMI_DIALING_KEYPAD_LAYER_Y, MMI_DIALING_KEYPAD_LAYER_WIDTH,
        MMI_DIALING_KEYPAD_LAYER_HEIGHT, DM_NO_FLAGS,
    0, 0, MMI_DIALING_KEYPAD_LAYER_WIDTH, MMI_DIALING_KEYPAD_LAYER_HEIGHT, DM_NO_FLAGS,
    MMI_DIALING_KEYPAD_LAYER_X, MMI_DIALING_KEYPAD_LAYER_Y - MMI_DIALING_BOX_HEIGHT, MMI_DIALING_KEYPAD_LAYER_WIDTH,
        MMI_DIALING_BOX_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#elif (defined(__MMI_FTE_SUPPORT__) || (defined (__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X400__) || defined (__MMI_MAINLCD_320X480__) || defined (__MMI_MAINLCD_360X640__))) && defined (__MMI_TOUCH_DIAL_SCREEN__)
const U8 category16[] = 
{
    6,
    DM_NEW_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BASE_LAYER_START,
    DM_STATUS_BAR1,
#ifdef __CAT16_MULTIEDITOR_STYLE__
	DM_MULTILINE_INPUTBOX1,
#else /*__CAT16_MULTIEDITOR_STYLE__*/
    DM_DIALER_INPUT_BOX1,
#endif /*__CAT16_MULTIEDITOR_STYLE__*/
    DM_BUTTON_BAR1
};
const S16 coordinate_set16[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_DIALING_KEYPAD_LAYER_X, MMI_DIALING_KEYPAD_LAYER_Y, MMI_DIALING_KEYPAD_LAYER_WIDTH,
        MMI_DIALING_KEYPAD_LAYER_HEIGHT, DM_NO_FLAGS,
#if defined(__MMI_MAINLCD_176X220__)
    0, 0, MMI_DIALING_KEYPAD_LAYER_WIDTH, 146, DM_NO_FLAGS,
#else
    0, 0, MMI_DIALING_KEYPAD_LAYER_WIDTH, MMI_DIALING_KEYPAD_LAYER_HEIGHT, DM_NO_FLAGS,
#endif
    DM_DEFAULT_STATUS_BAR_FLAG,
#if defined(__MMI_MAINLCD_176X220__)
    0, MMI_STATUS_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, 36, DM_NO_FLAGS,
#else
    MMI_DIALING_BOX_X, MMI_DIALING_BOX_Y, MMI_DIALING_BOX_WIDTH, MMI_DIALING_BOX_HEIGHT, DM_NO_FLAGS,
#endif
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
/* 061507 128x160 touch Start */
#elif defined (__MMI_MAINLCD_128X160__) && defined (__MMI_TOUCH_DIAL_SCREEN__)//061607 128x160 touch
const U8 category16[] = 
{
    5,
    DM_NEW_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BASE_LAYER_START,
    //DM_STATUS_BAR1,
 #ifdef __CAT16_MULTIEDITOR_STYLE__
 	DM_MULTILINE_INPUTBOX1,
 #else /*__CAT16_MULTIEDITOR_STYLE__*/
    DM_DIALER_INPUT_BOX1,
 #endif /*__CAT16_MULTIEDITOR_STYLE__*/
    DM_BUTTON_BAR1
};
const S16 coordinate_set16[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_DIALING_KEYPAD_LAYER_X, MMI_DIALING_KEYPAD_LAYER_Y, MMI_DIALING_KEYPAD_LAYER_WIDTH,
        MMI_DIALING_KEYPAD_LAYER_HEIGHT, DM_NO_FLAGS,
    0, 0, MMI_DIALING_KEYPAD_LAYER_WIDTH, 150, DM_NO_FLAGS,
    //DM_DEFAULT_STATUS_BAR_FLAG,
    0, 0/*MMI_STATUS_BAR_HEIGHT*/, MAIN_LCD_DEVICE_WIDTH, MMI_DIALING_BOX_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
/* 061507 128x160 touch Start */
#elif defined (__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X240__) ||  defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_240X400__)
/* 176x220 w/o touch screen have transparent softkey background in dialing screen. */
const U8 category16[] = 
{
    6,
    DM_NEW_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA2,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_STATUS_BAR1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set16[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_STATUS_BAR, DM_SPECIFIC_HIDE_STATUS_BAR,
#if defined(__MMI_OP12_CAT533_SUPPORT__) || defined(__WGUI_CATE_FTE_KEY_ONLY__)/* for Vodafone */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
#else /* __MMI_OP12_CAT533_SUPPORT__ || __WGUI_CATE_FTE_KEY_ONLY__ */
    DM_DEFAULT_BUTTON_BAR, DM_BUTTON_DISABLE_BACKGROUND, MMI_SOFTKEY_WIDTH
#endif /* __MMI_OP12_CAT533_SUPPORT__ || __WGUI_CATE_FTE_KEY_ONLY__ */
};
#else
/* 128x128 and 128x160 do not have transparent softkey background in dialing screen. */
const U8 category16[] = 
{
    6,
    DM_NEW_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA2,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_STATUS_BAR1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set16[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_STATUS_BAR, DM_SPECIFIC_HIDE_STATUS_BAR,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif 

#ifdef __MMI_MOTION_DIAL__
const U8 category633[] = 
{
    4,
    DM_NEW_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET2    
};

const S16 coordinate_set633[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,   
    DM_FULL_SCREEN_COORDINATE_FLAG,   /* DM_NEW_LAYER_START */
    DM_FULL_SCREEN_COORDINATE_FLAG,   /* DM_CATEGORY_CONTROLLED_AREA */                                    
};
#endif


#if defined(__MMI_FTE_SUPPORT__)
const U8 category18[] = 
{
    5,
    DM_NEW_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA2,
    DM_BASE_CONTROL_SET2
};
const S16 coordinate_set18[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};
#elif defined(WGUI_CATCALL_STYLE_2)
const U8 category18[] = 
{
    5,
    DM_NEW_LAYER_START,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_CATEGORY_CONTROLLED_AREA2,
    DM_BASE_CONTROL_SET2
};
const S16 coordinate_set18[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE, DM_NEW_LAYER_WITH_COLOR,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};
#else /* defined(WGUI_CATCALL_STYLE_2) */
const U8 category18[] = 
{
#ifdef __MMI_IMAGE_CACHE_FOR_ONE_GDI_LAYER__ 
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
#else
    3,
    DM_BASE_LAYER_START,
#endif
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set18[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
#if defined(__MMI_CATEGORY_CM_SCANLINE__)
    DM_DEFAULT_BUTTON_BAR, DM_BUTTON_DISABLE_BACKGROUND, MMI_SOFTKEY_WIDTH
#else /* __MMI_CATEGORY_CM_SCANLINE__ */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
#endif /* __MMI_CATEGORY_CM_SCANLINE__ */
};
#endif

const U8 category19[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_LIST1,
    DM_STATUS_BAR1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set19[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, MMI_STATUS_BAR_HEIGHT, 0, MAIN_LCD_DEVICE_HEIGHT - MMI_TITLE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    0, 0, 0, 0, DM_CATEGORY_CONTROL_COORDINATES,
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category20[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set20[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category21[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1
};

const U8 category22[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_MATRIX_MENU1
};
const S16 coordinate_set22[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_SUBMENU_CONTENT_COORDINATE_FLAG,
};

#ifdef UI_EMS_SUPPORT
const U8 category28[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_EMS_INPUTBOX1,
    DM_CATEGORY_CONTROLLED_AREA
};
#endif /* UI_EMS_SUPPORT */

const U8 category32[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_MULTILINE_INPUTBOX1,
    DM_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set32[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH, ((MMI_MENUITEM_HEIGHT << 1) + 6 /* editor border */), DM_NO_FLAGS,
    0, ((MMI_MENUITEM_HEIGHT << 1) + 6 /* editor border */), MAIN_LCD_DEVICE_WIDTH,
        MAIN_LCD_DEVICE_HEIGHT - ((MMI_MENUITEM_HEIGHT << 1) + 6 /* editor border */) - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 cat1049[] = 
{
    5, 
	DM_BASE_LAYER_START,
	DM_SCR_BG,
	DM_STATUS_BAR1,
	DM_LIST1,
	DM_BUTTON_BAR1
};

const S16 Coordinate_set1049[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
	DM_DEFAULT_STATUS_BAR_FLAG,
	0, 0, 0, 0, DM_CATEGORY_CONTROL_COORDINATES,
	DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 cat1070[] =
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_LIST1,
    DM_MULTILINE_INPUTBOX1
};

const S16 Coordinate_set1070[] =
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, MMI_TITLE_Y + MMI_TITLE_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_CONTENT_HEIGHT - (MMI_MENUITEM_HEIGHT << 1), DM_NO_FLAGS,
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - (MMI_MENUITEM_HEIGHT << 1) + 1, MAIN_LCD_DEVICE_WIDTH, (MMI_MENUITEM_HEIGHT << 1), DM_NO_FLAGS
};


#ifdef __MMI_DM_BW_WITHOUT_WALLPAPER__
const U8 category30[] = 
{

    2,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set30[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS
};

const U8 category33[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set33[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
#if defined (__MMI_IDLE_FULL_SCREEN__) && (!defined (__MMI_OP12_CAT533_SUPPORT__))
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT,
#if defined(__MMI_BT_DIALER_SUPPORT__)
    DM_DEFAULT_BUTTON_BAR_FLAG
#else
    DM_BUTTON_DISABLE_BACKGROUND
#endif
    ,MMI_SOFTKEY_WIDTH
#else /* defined (__MMI_IDLE_FULL_SCREEN__) */ 
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
#endif /* defined (__MMI_IDLE_FULL_SCREEN__) */ 
};
#else
const U8 category30[] = 
{

    3,
    DM_WALL_PAPER,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set30[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS
};

const U8 category33[] = 
{
    4,
    DM_WALL_PAPER,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set33[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
#if defined(__MMI_BT_DIALER_SUPPORT__) && defined(__MMI_MAINLCD_128X128__)
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT,
        DM_BUTTON_DISABLE_BACKGROUND, MMI_SOFTKEY_WIDTH + 10,
#elif defined (__MMI_IDLE_FULL_SCREEN__) && (!defined (__MMI_OP12_CAT533_SUPPORT__))
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT,
        DM_BUTTON_DISABLE_BACKGROUND, MMI_SOFTKEY_WIDTH,
#else /* defined (__MMI_IDLE_FULL_SCREEN__) */ 
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
#endif /* defined (__MMI_IDLE_FULL_SCREEN__) */ 
};
#endif
#ifdef __MMI_AVATAR__
const U8 category34[] =
{
    4,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA2,
    DM_BUTTON_BAR1
};
const S16 coordinate_set34[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
#if defined (__MMI_IDLE_FULL_SCREEN__)
            0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT,
                DM_BUTTON_DISABLE_BACKGROUND, MMI_SOFTKEY_WIDTH,
#else /* defined (__MMI_IDLE_FULL_SCREEN__) */ 
            DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
#endif /* defined (__MMI_IDLE_FULL_SCREEN__) */ 
};
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef UI_EMS_SUPPORT
const U8 category39[] = 
{
#if !defined(__MMI_MAINLCD_128X64__)
    5,
#else
    4,
#endif
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
#if !defined(__MMI_MAINLCD_128X64__)
    DM_CATEGORY_CONTROLLED_AREA,
#endif
#if(UI_DISABLE_EMS_INPUT_BOX)
    DM_MULTILINE_INPUTBOX1
#else 
    DM_EMS_INPUTBOX1
#endif 
};

const S16 coordinate_set39[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG, /* Ems header control area */
    0, 1, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, /* Multiline input box */
    DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y
};

#ifdef __MMI_FTE_SUPPORT__
const S16 coordinate_set39_iconbar[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG, /* Ems header control area */
    0, 1, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_ICON_BAR_HEIGHT, /* Multiline input box */
    DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y
};
#endif

#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
const U8 category39_slide_control[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
#if(UI_DISABLE_EMS_INPUT_BOX)
    DM_MULTILINE_INPUTBOX1,
#else 
    DM_EMS_INPUTBOX1,
#endif 
    DM_BUTTON,
    DM_BUTTON,
    DM_STRING,
};

const S16 coordinate_set39_slide_control[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_CONTENT_X, MMI_CONTENT_Y + WGUI_CAT_SLIDE_CONTROL_H, MMI_CONTENT_WIDTH, MMI_CONTENT_HEIGHT - WGUI_CAT_SLIDE_CONTROL_H, DM_NO_FLAGS,/* Ems header control area */
    0, 1, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, /* Multiline input box */
    DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    MMI_CONTENT_X, MMI_CONTENT_Y, MMI_CONTENT_WIDTH, WGUI_CAT_SLIDE_CONTROL_H, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
};

#ifdef __MMI_FTE_SUPPORT__
const S16 coordinate_set39_iconbar_slide_control[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_CONTENT_X, MMI_CONTENT_Y + WGUI_CAT_SLIDE_CONTROL_H, MMI_CONTENT_WIDTH, MMI_CONTENT_HEIGHT - WGUI_CAT_SLIDE_CONTROL_H, DM_NO_FLAGS,/* Ems header control area */
    0, 1, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_ICON_BAR_HEIGHT, /* Multiline input box */
    DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    MMI_CONTENT_X, MMI_CONTENT_Y, MMI_CONTENT_WIDTH, WGUI_CAT_SLIDE_CONTROL_H, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
};
#endif /* __MMI_FTE_SUPPORT__ */
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */
#endif /* UI_EMS_SUPPORT */


const U8 category57[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_INLINE_FIXED_LIST1
};
const S16 coordinate_set57[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
#ifndef __MMI_FTE_SUPPORT__    
    DM_COMMON_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
#else    
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
#endif
};

#if defined(__MMI_SCREEN_ROTATE__)
const S16 rotated_coordinate_set57[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,   
    MMI_ROTATED_CONTENT_X, MMI_ROTATED_CONTENT_Y, MMI_ROTATED_CONTENT_WIDTH, MMI_ROTATED_CONTENT_HEIGHT, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};
#endif

/* Should be revised for 240x320 screen */
const S16 coordinate_set57_top_infobox[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_CONTENT_X, MMI_CONTENT_Y, MAIN_LCD_DEVICE_WIDTH, 96, DM_NO_FLAGS,
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT,
        DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y
};

const U8 category61[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_IMAGE,
    DM_NEW_LAYER_START,
    DM_ALIGNED_AREA_START,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set61[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE, DM_CENTRE_ALIGN_X,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    CAT61_INFO_X, CAT61_INFO_Y, CAT61_INFO_W, CAT61_INFO_H, DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE
};
#if defined(__MMI_BT_DIALER_SUPPORT__)
//for BT dialer
const U8 category632[] =
{
    7,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_POPUP_BACKGROUND,
	DM_CATEGORY_CONTROLLED_AREA,
   // DM_ALIGNED_AREA_START,
   // DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
   // DM_ALIGNED_AREA_END,
    DM_CATEGORY_CONTROLLED_AREA2,
	DM_BUTTON_BAR1
};

const S16 coordinate_set632[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
	MMI_POP_UP_DIALOG_X,MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_POPUP_BACKGROUND_GREYSCALE,
    MMI_POP_UP_DIALOG_X+ CAT632_BORDER,MMI_POP_UP_DIALOG_Y + CAT632_BORDER, MMI_POP_UP_DIALOG_WIDTH - 2 * CAT632_BORDER, CAT632_CONTROL_AREA1_HEIGHT, DM_NO_FLAGS,

    MMI_POP_UP_DIALOG_X + CAT632_BORDER,MMI_POP_UP_DIALOG_Y + CAT632_BORDER + CAT632_CONTROL_AREA1_HEIGHT, MMI_POP_UP_DIALOG_WIDTH - 2 * CAT632_BORDER, CAT632_INPUTBOX_HEIGHT, DM_NO_FLAGS,
	
	MMI_POP_UP_DIALOG_X+ CAT632_BORDER,MMI_POP_UP_DIALOG_Y + CAT632_BORDER + CAT632_CONTROL_AREA1_HEIGHT + CAT632_INPUTBOX_HEIGHT, MMI_POP_UP_DIALOG_WIDTH-2 * CAT632_BORDER, CAT632_CONTROL_AREA2_HEIGHT, DM_NO_FLAGS,
    
	0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT,
                DM_BUTTON_DISABLE_BACKGROUND, MMI_SOFTKEY_WIDTH,
};
#endif

#ifdef __MMI_MAINLCD_128X64__
const U8 category63[] = 
{
    6,
    DM_BASE_LAYER_START,
//    DM_NEW_LAYER_START,
//    DM_POPUP_BACKGROUND,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set63[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
	UI_POPUP_BORDER_SIZE, UI_POPUP_BORDER_SIZE, MAIN_LCD_DEVICE_WIDTH - UI_POPUP_BORDER_SIZE*2, MAIN_LCD_DEVICE_HEIGHT - UI_POPUP_BORDER_SIZE*2,
    DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_FULL_SCREEN_COORDINATE_FLAG
};
#else /* __MMI_MAINLCD_128X64__ */
const U8 category63[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_CATEGORY_CONTROLLED_AREA
};
#ifdef __MMI_MAINLCD_96X64__
const S16 coordinate_set63[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE, DM_POPUP_BACKGROUND_HATCH_FILL, 
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_POPUP_SCREEN_COORDINATE_FLAG
};
#elif defined( __MMI_FTE_SUPPORT__)
const S16 coordinate_set63[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    WGUI_POPUP_FTE_BG_X, MMI_POP_UP_DIALOG_Y, WGUI_POPUP_FTE_BG_WIDTH, MMI_POP_UP_DIALOG_FULL_HEIGHT, DM_POPUP_BACKGROUND_GREYSCALE | DM_POPUP_BACKGROUND_FOR_FTE, 
    WGUI_POPUP_FTE_AREA_X, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, WGUI_POPUP_FTE_AREA_WIDTH, MMI_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_FOR_POPUP_FTE | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_POPUP_SCREEN_COORDINATE_FLAG
};
#else /* __MMI_FTE_SUPPORT__ */
const S16 coordinate_set63[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE, DM_POPUP_BACKGROUND_GREYSCALE, 
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_POPUP_SCREEN_COORDINATE_FLAG
};
#endif /* __MMI_FTE_SUPPORT__ */
#endif /* __MMI_MAINLCD_128X64__*/

#if defined(__MMI_SCREEN_ROTATE__)
const S16 rotated_coordinate_set63[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE_FLAG,
    MMI_ROTATED_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2,
        MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_POPUP_SCREEN_COORDINATE_FLAG
};
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 


#if defined(__MMI_MAINLCD_96X64__)
const U8 category66[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,  /* for @-blending layer before DM_POPUP_BACKGROUND*/
    DM_POPUP_BACKGROUND,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,    
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set66[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT-MMI_BUTTON_BAR_HEIGHT, DM_POPUP_BACKGROUND_HATCH_FILL,
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_DIALOG_HEIGHT - UI_POPUP_BORDER_SIZE*2-MMI_BUTTON_BAR_HEIGHT,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};
#elif defined(__MMI_FTE_SUPPORT__)
const U8 category66[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,  /* for @-blending layer before DM_POPUP_BACKGROUND*/
    DM_POPUP_BACKGROUND,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,    
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set66[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    WGUI_POPUP_FTE_BG_X, MMI_POP_UP_DIALOG_Y, WGUI_POPUP_FTE_BG_WIDTH, MMI_POP_UP_DIALOG_FULL_HEIGHT, DM_POPUP_BACKGROUND_FOR_FTE, 
    WGUI_POPUP_FTE_AREA_X, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, WGUI_POPUP_FTE_AREA_WIDTH, MMI_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_FOR_POPUP_FTE | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};
#elif defined(__MMI_MAINLCD_320X480__)
const U8 category66[] = 
{
    10,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_TITLE1,   /* for a blending issue, title and status bar should be before popup background */ 
    DM_POPUP_BACKGROUND,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,    
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_BUTTON_BAR1

};
const S16 coordinate_set66[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DEFAULT_TITLE_BAR_FLAG,
    DM_POPUP_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_SOFTKEY_Y - MMI_POP_UP_DIALOG_Y - UI_POPUP_BORDER_SIZE*2,
    DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    MMI_POP_UP_SOFTKEY_X, MMI_POP_UP_SOFTKEY_Y, MAIN_LCD_DEVICE_WIDTH - 2*MMI_POP_UP_SOFTKEY_X, MMI_POP_UP_SOFTKEY_HEIGHT, DM_BUTTON_DISABLE_BACKGROUND, MMI_POP_UP_SOFTKEY_WIDTH       /* Button Bar */
};

const U8 category66_no_softkey[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_POPUP_BACKGROUND,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,    
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END

};

const S16 coordinate_set66_no_softkey[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_DIALOG_HEIGHT - UI_POPUP_BORDER_SIZE*2,
    DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};
#else /* defined(__MMI_FTE_SUPPORT__) */
const U8 category66[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,  /* for @-blending layer before DM_POPUP_BACKGROUND*/
    DM_POPUP_BACKGROUND,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,    
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set66[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_NO_FLAGS,
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_DIALOG_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};
#endif /* defined(__MMI_MAINLCD_320X480__) */


#if defined(__MMI_SCREEN_ROTATE__)

#if defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_FTE_SUPPORT__)
const S16 rotated_coordinate_set66[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DEFAULT_TITLE_BAR_FLAG,
    DM_POPUP_SCREEN_COORDINATE_FLAG,
    MMI_ROTATED_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2,
        MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_ROTATED_SOFTKEY_WIDTH
};

const S16 rotated_coordinate_set66_no_softkey[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE_FLAG,
    MMI_ROTATED_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2,
        MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};
#else
const S16 rotated_coordinate_set66[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE_FLAG,
    MMI_ROTATED_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2,
        MMI_ROTATED_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};
#endif
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 

const U8 category69[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ALIGNED_AREA_START,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_SINGLELINE_INPUTBOX1    
};
const S16 coordinate_set69[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
     /* DM_ALIGNED_AREA_START */
    MMI_COMMON_CONTENT_X + CAT69_MARGIN, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH - (CAT69_MARGIN << 1), CAT69_ALIGNED_AREA_H, DM_NO_FLAGS,
    DM_DUMMY_COORDINATE, /* DM_MULTILINE_INPUTBOX1 */
    MMI_COMMON_CONTENT_X + CAT69_MARGIN, CAT69_SINGLELINE_Y, MMI_COMMON_CONTENT_WIDTH - (CAT69_MARGIN << 1), MMI_SINGLELINE_INPUTBOX_HEIGHT, DM_SINGLE_LINE_INPUTBOX_SPECIFIC_HEIGHT,
};

#ifdef __MMI_SEARCH_WEB__
#ifdef __MMI_FTE_SUPPORT__
const U8 category2001[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_RECTANGLE,
    DM_NEW_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_BUTTON,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_PANEL,
};
const S16 coordinate_set2001[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,   /* Category Screen Coordinates */
    DM_FULL_SCREEN_COORDINATE_FLAG,   /* greyscale rectangle */
    DM_FULL_SCREEN_COORDINATE_FLAG,   /* New layer */
    0, UI_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - MMI_SINGLELINE_INPUTBOX_HEIGHT, 0, 0, DM_NO_FLAGS,            /* Search button */
    //0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS, MMI_SOFTKEY_WIDTH,    /* Button Bar */
    DM_FULL_SCREEN_COORDINATE_FLAG,   /* Controlled area */
    DM_NULL_COORDINATE,                 /* Panel */
};
#else /* __MMI_FTE_SUPPORT__ */
const U8 category2001[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_RECTANGLE,
    DM_NEW_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_PANEL,
    DM_BUTTON_BAR1
};
const S16 coordinate_set2001[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,   /* Category Screen Coordinates */
    DM_FULL_SCREEN_COORDINATE_FLAG,   /* greyscale rectangle */
    DM_FULL_SCREEN_COORDINATE_FLAG,   /* New layer */
    DM_FULL_SCREEN_COORDINATE_FLAG,   /* Controlled area */
    DM_NULL_COORDINATE,                 /* Panel */
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS, MMI_SOFTKEY_WIDTH    /* Button Bar */
};
#endif
#endif /* __MMI_SEARCH_WEB__  */

const U8 category74[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set74[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};

#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
const U8 category74_slide_control[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1,
    DM_BUTTON,
    DM_BUTTON,
    DM_STRING,
    DM_CATEGORY_CONTROLLED_AREA,
};

const S16 coordinate_set74_slide_control[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_CONTENT_X, MMI_CONTENT_Y + WGUI_CAT_SLIDE_CONTROL_H, MMI_CONTENT_WIDTH, MMI_CONTENT_HEIGHT - WGUI_CAT_SLIDE_CONTROL_H, DM_NO_FLAGS,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    MMI_CONTENT_X, MMI_CONTENT_Y, MMI_CONTENT_WIDTH, WGUI_CAT_SLIDE_CONTROL_H, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    MMI_CONTENT_X, MMI_CONTENT_Y + WGUI_CAT_SLIDE_CONTROL_H, MMI_CONTENT_WIDTH, MMI_CONTENT_HEIGHT - WGUI_CAT_SLIDE_CONTROL_H, DM_NO_FLAGS,
};
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */

#if defined(__MMI_CSB_BROWSER__)||defined(__MMI_PHB_UI_IN_TABS__)||defined(__MMI_PHB_CALLER_GROUP__)||defined(__MMI_SNS_CONTACTS__)

#if defined(__MMI_MAINLCD_128X128__) || (defined(__MMI_MAINLCD_320X240__) && (!defined(__MMI_FTE_SUPPORT__)))
const U8 category3001[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    DM_MULTILINE_INPUTBOX1,
    DM_BUTTON_BAR1
};

const S16 coordinate_set3001[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,

    /* DM_HORIZONTAL_TAB_BAR */
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
         MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS,

    /* DM_MULTILINE_INPUTBOX1 */
    MMI_COMMON_CONTENT_X, MMI_HORIZONTAL_TAB_BAR_Y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, MMI_COMMON_CONTENT_WIDTH,
        MAIN_LCD_DEVICE_HEIGHT - MMI_HORIZONTAL_TAB_BAR_Y - MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,

    /* DM_BUTTON_BAR1 */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#elif defined(__MMI_MAINLCD_128X64__)
const U8 category3001[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    DM_MULTILINE_INPUTBOX1,
    DM_BUTTON_BAR1
};

const S16 coordinate_set3001[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,

    /* DM_HORIZONTAL_TAB_BAR */
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
         MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS,

    /* DM_MULTILINE_INPUTBOX1 */
    MMI_COMMON_CONTENT_X, MMI_HORIZONTAL_TAB_BAR_Y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, MMI_COMMON_CONTENT_WIDTH,
        MAIN_LCD_DEVICE_HEIGHT - MMI_HORIZONTAL_TAB_BAR_Y - MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,

    /* DM_BUTTON_BAR1 */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#elif (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_MAINLCD_320X240__))
const U8 category3001[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_MULTILINE_INPUTBOX1,
    DM_BUTTON_BAR1
};

const S16 coordinate_set3001[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
        
    /* DM_STATUS_BAR1 */
    DM_DEFAULT_STATUS_BAR_FLAG,

    /* DM_HORIZONTAL_TAB_BAR */
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
         MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS,

    /* DM_MULTILINE_INPUTBOX1 */
    MMI_COMMON_CONTENT_X, MMI_HORIZONTAL_TAB_BAR_Y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, MMI_COMMON_CONTENT_WIDTH,
        MAIN_LCD_DEVICE_HEIGHT - MMI_HORIZONTAL_TAB_BAR_Y - MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,

    /* DM_BUTTON_BAR1 */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else
const U8 category3001[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_MULTILINE_INPUTBOX1,
    DM_BUTTON_BAR1
};

const S16 coordinate_set3001[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
        
    /* DM_STATUS_BAR1 */
    DM_DEFAULT_STATUS_BAR_FLAG,

    /* DM_HORIZONTAL_TAB_BAR */
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
         MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,

    /* DM_MULTILINE_INPUTBOX1 */
    MMI_COMMON_CONTENT_X, MMI_HORIZONTAL_TAB_BAR_Y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, MMI_COMMON_CONTENT_WIDTH,
        MAIN_LCD_DEVICE_HEIGHT - MMI_HORIZONTAL_TAB_BAR_Y - MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,

    /* DM_BUTTON_BAR1 */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* defined(__MMI_MAINLCD_128X128__) */

#endif

#if defined(__MMI_CMMB_CAS_2GPP_SUPPORT__)
const U8 category3002[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1,
};

const S16 coordinate_set3002[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,

    /* DM_HORIZONTAL_TAB_BAR */
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y + MMI_TITLE_HEIGHT, MMI_HORIZONTAL_TAB_BAR_WIDTH,
         MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS,

    /* DM_MULTILINE_INPUTBOX1 */
    MMI_COMMON_CONTENT_X, MMI_HORIZONTAL_TAB_BAR_Y + MMI_TITLE_HEIGHT + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, MMI_COMMON_CONTENT_WIDTH,
        MAIN_LCD_DEVICE_HEIGHT - MMI_TITLE_HEIGHT - MMI_HORIZONTAL_TAB_BAR_Y - MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
};
#endif

#if defined(__MMI_EBOOK_READER__)
#ifdef __MMI_FTE_SUPPORT__
const U8 category3003[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set3003[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG
};

const U8 category3003_fullscreen[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_MULTILINE_INPUTBOX1,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set3003_fullscreen[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG
};
#endif /*__MMI_FTE_SUPPORT__*/
#endif

#if defined(__MMI_EBOOK_READER__)

#ifdef __MMI_TOUCH_SCREEN__
const U8 category75[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};
#else
const U8 category75[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1
};
#endif
const S16 coordinate_set75[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};
#endif
#if defined(__MMI_EBOOK_READER__)
#ifdef __MMI_TOUCH_SCREEN__
const U8 category77[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA
};
#else
const U8 category77[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_MULTILINE_INPUTBOX1
};
#endif
const S16 coordinate_set77[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG
};
#endif

#if defined(__MMI_MAINLCD_176X220__)
const U8 category83[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_CALENDAR,
    DM_STATUS_BAR1,
    DM_BUTTON_BAR1,
    DM_STRING
};
const S16 coordinate_set83[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    /* Status String */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MMI_STATUS_BAR_HEIGHT, DM_CENTRE_ALIGN_X | DM_STRING_BORDERED,
};
#elif defined(__MMI_MAINLCD_240X320__)
const U8 category83[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_CALENDAR,
    DM_STATUS_BAR1,
    DM_BUTTON_BAR1,
    DM_STRING
};
const S16 coordinate_set83[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    /* Status String */
    0, 0, MAIN_LCD_DEVICE_WIDTH, 22, DM_CENTRE_ALIGN_X | DM_STRING_BORDERED,
};
#elif defined(__MMI_MAINLCD_240X240__)
const U8 category83[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_CALENDAR,
    DM_STATUS_BAR1,
    DM_BUTTON_BAR1,
    DM_STRING
};
const S16 coordinate_set83[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    /* Status String */
    0, 0, MAIN_LCD_DEVICE_WIDTH, 22, DM_CENTRE_ALIGN_X | DM_STRING_BORDERED,
};
#elif defined(__MMI_MAINLCD_240X400__)
const U8 category83[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_CALENDAR,
    DM_STATUS_BAR1,
    DM_BUTTON_BAR1,
    DM_STRING
};
const S16 coordinate_set83[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    /* Status String */
    0, 0, MAIN_LCD_DEVICE_WIDTH, 22, DM_CENTRE_ALIGN_X | DM_STRING_BORDERED,
};
#elif defined(__MMI_MAINLCD_320X240__)
const U8 category83[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_CALENDAR,
    DM_BUTTON_BAR1,
    DM_STRING
};
const S16 coordinate_set83[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    /* Status String */
    0, 0, MAIN_LCD_DEVICE_WIDTH, 22, DM_CENTRE_ALIGN_X | DM_STRING_BORDERED
};
#elif defined(__MMI_MAINLCD_128X160__)
const U8 category83[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_CALENDAR,
    DM_BUTTON_BAR1,
    DM_STRING
};
const S16 coordinate_set83[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    /* Status String */
    0, 0, MAIN_LCD_DEVICE_WIDTH, 22, DM_CENTRE_ALIGN_X | DM_STRING_BORDERED
};
#elif defined(__MMI_MAINLCD_320X480__)
const U8 category83[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_CALENDAR,
    DM_STATUS_BAR1,
    DM_BUTTON_BAR1,
    DM_STRING
};
const S16 coordinate_set83[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    /* Status String */
    0, 0, MAIN_LCD_DEVICE_WIDTH, 22, DM_CENTRE_ALIGN_X | DM_STRING_BORDERED,
};
#else
const U8 category83[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_CALENDAR,
    DM_BUTTON_BAR1
};
const S16 coordinate_set83[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif

const U8 category85[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON,
    DM_BUTTON
};

const S16 coordinate_set85[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_TITLE_LEFT_BUTTON_FLAG,
    DM_DEFAULT_TITLE_RIGHT_BUTTON_FLAG
};

const U8 category85_no_button[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ASYNCDYNAMIC_LIST1
};


#if 0//def __MMI_WALLPAPER_ON_BOTTOM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 

#if (defined(__MMI_ANALOG_CLOCK__) || defined(__MMI_DIGITAL_CLOCK__))
const U8 category86[] = 
{
    7,
    DM_NEW_LAYER_START,
    DM_IMAGE,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_BUTTON,
    DM_BUTTON,
    DM_CATEGORY_CONTROLLED_AREA
};

const S16 coordinate_set86[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_TITLE_LEFT_BUTTON_FLAG,
    DM_DEFAULT_TITLE_RIGHT_BUTTON_FLAG,
    DM_COMMON_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};
#endif

#if defined(__MMI_MAINLCD_320X480__)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_1  (50)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_2  (150)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_3  (250)
#define WGUI_CAT088_3ITEMS_COOR_SLIDE_FLAG  (DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE)
#define WGUI_CAT088_2ITEMS_COOR_Y_OFFSET_1  (80)
#define WGUI_CAT088_2ITEMS_COOR_Y_OFFSET_2  (230)
#define WGUI_CAT088_2ITEMS_COOR_SLIDE_FLAG  (DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE)
#elif defined(__MMI_MAINLCD_240X400__)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_1  (10)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_2  (85)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_3  (160)
#define WGUI_CAT088_3ITEMS_COOR_SLIDE_FLAG  (DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE)
#define WGUI_CAT088_2ITEMS_COOR_Y_OFFSET_1  (10)
#define WGUI_CAT088_2ITEMS_COOR_Y_OFFSET_2  (120)
#define WGUI_CAT088_2ITEMS_COOR_SLIDE_FLAG  (DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE)
#elif defined(__MMI_MAINLCD_320X240__)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_1  (10)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_2  (60)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_3  (110)
#define WGUI_CAT088_3ITEMS_COOR_SLIDE_FLAG  (DM_SLIDE_CONTROL_VALUE_POS_TAIL)
#define WGUI_CAT088_2ITEMS_COOR_Y_OFFSET_1  (20)
#define WGUI_CAT088_2ITEMS_COOR_Y_OFFSET_2  (80)
#define WGUI_CAT088_2ITEMS_COOR_SLIDE_FLAG  (DM_SLIDE_CONTROL_VALUE_POS_TAIL)
#elif defined(__MMI_MAINLCD_240X320__)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_1  (10)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_2  (85)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_3  (160)
#define WGUI_CAT088_3ITEMS_COOR_SLIDE_FLAG  (DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE)
#define WGUI_CAT088_2ITEMS_COOR_Y_OFFSET_1  (10)
#define WGUI_CAT088_2ITEMS_COOR_Y_OFFSET_2  (120)
#define WGUI_CAT088_2ITEMS_COOR_SLIDE_FLAG  (DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE)
#elif defined(__MMI_MAINLCD_240X240__)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_1  (10)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_2  (60)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_3  (110)
#define WGUI_CAT088_3ITEMS_COOR_SLIDE_FLAG  (DM_SLIDE_CONTROL_VALUE_POS_TAIL)
#define WGUI_CAT088_2ITEMS_COOR_Y_OFFSET_1  (20)
#define WGUI_CAT088_2ITEMS_COOR_Y_OFFSET_2  (80)
#define WGUI_CAT088_2ITEMS_COOR_SLIDE_FLAG  (DM_SLIDE_CONTROL_VALUE_POS_TAIL)
#elif defined(__MMI_MAINLCD_176X220__)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_1  (10)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_2  (60)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_3  (110)
#define WGUI_CAT088_3ITEMS_COOR_SLIDE_FLAG  (DM_SLIDE_CONTROL_VALUE_POS_HEAD)
#define WGUI_CAT088_2ITEMS_COOR_Y_OFFSET_1  (15)
#define WGUI_CAT088_2ITEMS_COOR_Y_OFFSET_2  (90)
#define WGUI_CAT088_2ITEMS_COOR_SLIDE_FLAG  (DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE)
#elif defined(__MMI_MAINLCD_128X160__)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_1  (2)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_2  (39)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_3  (76)
#define WGUI_CAT088_3ITEMS_COOR_SLIDE_FLAG  (DM_SLIDE_CONTROL_VALUE_POS_HEAD)
#define WGUI_CAT088_2ITEMS_COOR_Y_OFFSET_1  (10)
#define WGUI_CAT088_2ITEMS_COOR_Y_OFFSET_2  (75)
#define WGUI_CAT088_2ITEMS_COOR_SLIDE_FLAG  (DM_SLIDE_CONTROL_VALUE_POS_HEAD)
#else /* defined(__MMI_MAINLCD_128X128__) */
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_1  (0)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_2  (30)
#define WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_3  (60)
#define WGUI_CAT088_3ITEMS_COOR_SLIDE_FLAG  (DM_SLIDE_CONTROL_VALUE_POS_HEAD)
#define WGUI_CAT088_2ITEMS_COOR_Y_OFFSET_1  (10)
#define WGUI_CAT088_2ITEMS_COOR_Y_OFFSET_2  (55)
#define WGUI_CAT088_2ITEMS_COOR_SLIDE_FLAG  (DM_SLIDE_CONTROL_VALUE_POS_TAIL)
#endif

/*modified by lhm for 9664*/
#ifdef __MMI_MAINLCD_96X64__
const U8 category88[] = 
{
    7,
    DM_SCR_BG,
    DM_BASE_LAYER_START,
    DM_TITLE1,
    DM_SLIDE_CONTROL,
    DM_SLIDE_CONTROL,
    DM_SLIDE_CONTROL,
    DM_BUTTON_BAR1
};
#else
const U8 category88[] = 
{
    6,
    DM_SCR_BG,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_SLIDE_CONTROL,
    DM_SLIDE_CONTROL,
    DM_SLIDE_CONTROL
};
#endif /*__MMI_MAINLCD_96X64__*/

const S16 coordinate_set88_3_item[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_1, MMI_COMMON_CONTENT_WIDTH, 0 /* unused */, WGUI_CAT088_3ITEMS_COOR_SLIDE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_2, MMI_COMMON_CONTENT_WIDTH, 0 /* unused */, WGUI_CAT088_3ITEMS_COOR_SLIDE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + WGUI_CAT088_3ITEMS_COOR_Y_OFFSET_3, MMI_COMMON_CONTENT_WIDTH, 0 /* unused */, WGUI_CAT088_3ITEMS_COOR_SLIDE_FLAG
};
const S16 coordinate_set88_2_item[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + WGUI_CAT088_2ITEMS_COOR_Y_OFFSET_1, MMI_COMMON_CONTENT_WIDTH, 0 /* unused */, WGUI_CAT088_2ITEMS_COOR_SLIDE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + WGUI_CAT088_2ITEMS_COOR_Y_OFFSET_2, MMI_COMMON_CONTENT_WIDTH, 0 /* unused */, WGUI_CAT088_2ITEMS_COOR_SLIDE_FLAG,
    DM_NULL_COORDINATE
};

/*modified by lhm for 9664*/
#ifdef __MMI_MAINLCD_96X64__
const S16 coordinate_set88_1_item[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_TITLE_X, 0, MMI_TITLE_WIDTH, MMI_TITLE_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, (MMI_COMMON_CONTENT_Y + (MMI_COMMON_CONTENT_HEIGHT >> 1) - 6) , MMI_COMMON_CONTENT_WIDTH, 0 /* unused */, DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE,
    DM_NULL_COORDINATE,
    DM_NULL_COORDINATE,
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS, MMI_SOFTKEY_WIDTH    /* Button Bar */
};
#else
const S16 coordinate_set88_1_item[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#if defined (__MMI_MAINLCD_128X64__)
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y , MMI_COMMON_CONTENT_WIDTH, 0 /* unused */, DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE,
#elif defined(__MMI_MAINLCD_128X128__)
    MMI_COMMON_CONTENT_X, (MMI_COMMON_CONTENT_Y + (MMI_COMMON_CONTENT_HEIGHT >> 2) - 6), MMI_COMMON_CONTENT_WIDTH, 0 /* unused */, DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE,
#else /* __MMI_MAINLCD_128X64__ */
    MMI_COMMON_CONTENT_X, (MMI_COMMON_CONTENT_Y + (MMI_COMMON_CONTENT_HEIGHT >> 1) - 1), MMI_COMMON_CONTENT_WIDTH, 0 /* unused */, DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE,
#endif /* __MMI_MAINLCD_128X64__ */
    DM_NULL_COORDINATE,
    DM_NULL_COORDINATE
};
#endif /*__MMI_MAINLCD_96X64__*/

#ifdef __MMI_PICTURE_EDITOR_SUPPORT__
const U8 category91[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_RECTANGLE,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BASE_CONTROL_SET_COMMON,
};
const S16 coordinate_set91[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, MMI_STATUS_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_STATUS_BAR_HEIGHT, DM_NO_FLAGS,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};
#endif

#if defined(__MMI_HIDD_SUPPORT__)
#if defined(__GDI_MEMORY_PROFILE_2__)
const U8 category95[] = 
{
    5,
    DM_NEW_LAYER_START,
    DM_IMAGE,
    DM_BASE_LAYER_START,
    DM_PANEL,
#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
    DM_BASE_CONTROL_SET_COMMON
#else /* defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) */
    DM_BUTTON_BAR1
#endif /* defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) */
};
const S16 coordinate_set95[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT/* - MMI_BUTTON_BAR_HEIGHT*/, DM_NO_FLAGS,
#if !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X480__)
#ifdef __MMI_FTE_SUPPORT__
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS, MMI_SOFTKEY_WIDTH    /* Button Bar */
#else /* __MMI_FTE_SUPPORT__ */
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT, DM_BUTTON_DISABLE_BACKGROUND, MMI_SOFTKEY_WIDTH    /* Button Bar */
#endif /* __MMI_FTE_SUPPORT__ */
#endif /* !defined(__MMI_MAINLCD_240X400__) && !defined(__MMI_MAINLCD_320X480__) */
};
#else /* defined(__GDI_MEMORY_PROFILE_2__) */
const U8 category95[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_PANEL,
    DM_BUTTON_BAR1
};
const S16 coordinate_set95[] = 
{
	DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT/* - MMI_BUTTON_BAR_HEIGHT*/, DM_NO_FLAGS,
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT, DM_BUTTON_DISABLE_BACKGROUND, MMI_SOFTKEY_WIDTH    /* Button Bar */
};
#endif /* defined(__GDI_MEMORY_PROFILE_2__) */
#endif

/* START VIJAY PMT 20050930 */
#ifdef __MMI_SMALL_EDIT_SCREEN__
const U8 category100[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_RECTANGLE,
    DM_TITLE1,
    DM_MULTILINE_INPUTBOX1,
    DM_RECTANGLE,
    DM_BUTTON_BAR1,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set100[] = 
{
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,   /* Category Screen Coordinates */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,   /* greyscale rectangle */
    MMI_SMALL_SCREEN_X_OFFSET, MMI_TITLE_Y + MMI_TITLE_HEIGHT + MMI_SMALL_SCREEN_Y_OFFSET, UI_DEVICE_WIDTH - 2 * MMI_SMALL_SCREEN_X_OFFSET, MMI_TITLE_HEIGHT, DM_NO_FLAGS,      /* title */
    MMI_SMALL_SCREEN_X_OFFSET, 1, UI_DEVICE_WIDTH - 2 * MMI_SMALL_SCREEN_X_OFFSET, MMI_CONTENT_HEIGHT - 2 * MMI_SMALL_SCREEN_Y_OFFSET - MMI_TITLE_HEIGHT + 1, DM_PREVIOUS_CONTROL_END_Y,    /* Multiline inputbox */
    MMI_SMALL_SCREEN_X_OFFSET, MMI_TITLE_Y + MMI_TITLE_HEIGHT + MMI_SMALL_SCREEN_Y_OFFSET, UI_DEVICE_WIDTH - 2 * MMI_SMALL_SCREEN_X_OFFSET, MMI_CONTENT_HEIGHT - 2 * MMI_SMALL_SCREEN_Y_OFFSET + 1, DM_NO_FLAGS,        /* Rectangle */
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS, MMI_SOFTKEY_WIDTH,    /* Button Bar */
    MMI_SMALL_SCREEN_X_OFFSET, MMI_TITLE_Y + 2 * MMI_TITLE_HEIGHT + MMI_SMALL_SCREEN_Y_OFFSET, MMI_CONTENT_WIDTH - 2 * MMI_SMALL_SCREEN_X_OFFSET - 1, MMI_CONTENT_HEIGHT - 2 * (MMI_SMALL_SCREEN_Y_OFFSET) - MMI_TITLE_HEIGHT + /* MMI_MULTITAP_HEIGHT */ +1, DM_NO_FLAGS,      /* Category Controlled Area */
};
#endif /* __MMI_SMALL_EDIT_SCREEN__ */ 
/* END VIJAY PMT 20050930 */


#if defined(__MMI_CAT103_SUPPORT__)
const U8 category103[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_DYNAMIC_LIST1,
    DM_SINGLELINE_INPUTBOX1,
    DM_CATEGORY_CONTROLLED_AREA,
};

const S16 coordinate_set103[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,    
    0, CAT103_DYNAMIC_LIST_Y, MAIN_LCD_DEVICE_WIDTH, CAT103_DYNAMIC_LIST_H, DM_NO_FLAGS,                   /* DM_DYNAMIC_LIST1 */
#if defined(__MMI_MAINLCD_240X320__) && defined(__MMI_FTE_SUPPORT__)
    0, CAT103_SINGLE_LINE_INPUTBOX_Y, MAIN_LCD_DEVICE_WIDTH, 30, DM_NO_FLAGS,  /* DM_SINGLELINE_INPUTBOX1 */
#elif  defined(__MMI_MAINLCD_240X240__) && defined(__MMI_FTE_SUPPORT__)   
	0, CAT103_SINGLE_LINE_INPUTBOX_Y, MAIN_LCD_DEVICE_WIDTH, 30, DM_NO_FLAGS,  /* DM_SINGLELINE_INPUTBOX1 */
#else
    0, CAT103_SINGLE_LINE_INPUTBOX_Y, MAIN_LCD_DEVICE_WIDTH, MMI_SINGLELINE_INPUTBOX_HEIGHT, DM_NO_FLAGS,  /* DM_SINGLELINE_INPUTBOX1 */
#endif
    0, CAT103_DYNAMIC_LIST_Y, MAIN_LCD_DEVICE_WIDTH, CAT103_DYNAMIC_LIST_H, DM_NO_FLAGS,                    /* DM_CATEGORY_CONTROLLED_AREA */            
};
#endif /* defined(__MMI_CAT103_SUPPORT__) */

#ifdef __PLUTO_MMI_PACKAGE__
#if defined(__MMI_MAINLCD_128X64__) 
const U8 category105[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set105[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG
};

#elif defined(__MMI_MAINLCD_96X64__) /*added by lhm for 9664*/
const U8 category105[] = 
{
    5,
    DM_SCR_BG,
    DM_BASE_LAYER_START,
    DM_TITLE1,
    DM_SLIDE_CONTROL,
    DM_BUTTON_BAR1
};
const S16 coordinate_set105[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_TITLE_X, 0, MMI_TITLE_WIDTH, MMI_TITLE_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, (MMI_COMMON_CONTENT_Y + (MMI_COMMON_CONTENT_HEIGHT >> 1) - 6) , MMI_COMMON_CONTENT_WIDTH, 0 /* unused */, DM_SLIDE_CONTROL_VALUE_POS_NEXT_LINE,
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS, MMI_SOFTKEY_WIDTH    /* Button Bar */
};

#else /* __MMI_MAINLCD_128X64__ */

#if defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_FTE_SUPPORT__)
const U8 category105[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET2,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set105[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG
};
#else /* __MMI_SLIM_IMG_RES__ */
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
#if defined(__MMI_MAINLCD_320X240__)
const U8 category105[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BUTTON_BAR1,
    DM_IMAGE,
    DM_BUTTON,
    DM_BUTTON
};
const S16 coordinate_set105[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    WGUI_CAT105_IMG_X, WGUI_CAT105_IMG_Y, WGUI_CAT105_IMG_W, WGUI_CAT105_IMG_H, DM_NO_FLAGS,
    WGUI_CAT105_BT1_X, WGUI_CAT105_BT1_Y, WGUI_CAT105_BT1_W, WGUI_CAT105_BT1_H, DM_NO_FLAGS,
    WGUI_CAT105_BT2_X, WGUI_CAT105_BT2_Y, WGUI_CAT105_BT2_W, WGUI_CAT105_BT2_H, DM_NO_FLAGS
};
#elif defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X240__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_128X160__)
const U8 category105[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET2,
    DM_IMAGE,
    DM_BUTTON,
    DM_BUTTON
};
const S16 coordinate_set105[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    WGUI_CAT105_IMG_X, WGUI_CAT105_IMG_Y, WGUI_CAT105_IMG_W, WGUI_CAT105_IMG_H, DM_NO_FLAGS,
    WGUI_CAT105_BT1_X, WGUI_CAT105_BT1_Y, WGUI_CAT105_BT1_W, WGUI_CAT105_BT1_H, DM_NO_FLAGS,
    WGUI_CAT105_BT2_X, WGUI_CAT105_BT2_Y, WGUI_CAT105_BT2_W, WGUI_CAT105_BT2_H, DM_NO_FLAGS
};
#else /* defined(__MMI_MAINLCD_240X320__) */
const U8 category105[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET1,
};
const S16 coordinate_set105[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG
};
#endif /* defined(__MMI_MAINLCD_240X320__) */
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
const U8 category105[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_IMAGE
};
const S16 coordinate_set105[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */ 
#endif /* __MMI_SLIM_IMG_RES__ */
#endif /* __PLUTO_MMI_PACKAGE__ */
#endif /* __MMI_MAINLCD_128X64__ */

const U8 category110[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_RECTANGLE,
    DM_LIST1,
    DM_BUTTON_BAR1
};

const S16 coordinate_set110[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,   /* Category Screen Coordinates */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,   /* greyscale rectangle */
    0, 0, 0, 0, DM_CATEGORY_CONTROL_COORDINATES, /* List */
    DM_DEFAULT_BUTTON_BAR, DM_NO_FLAGS, MMI_SOFTKEY_WIDTH        /* Button Bar */
};

#ifdef __MMI_TOUCH_SCREEN__
const U8 category111[] = 
{
    7,
    DM_BASE_LAYER_START,
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
    DM_BACK_FILL_AREA,
#else
    DM_SCR_BG,
#endif
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1,
    DM_SINGLELINE_INPUTBOX1,
    DM_SCROLL_TEXT,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set111[] =
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
    DM_FULL_SCREEN_COORDINATE_FLAG,
#endif
#ifdef __MMI_MAINLCD_320X240__
    #if defined(__MMI_VIRTUAL_KEYBOARD__) || defined(__MMI_FTE_SUPPORT__) 
        MMI_COMMON_CONTENT_X + CAT111_MARGIN, MMI_COMMON_CONTENT_Y - (MMI_TITLE_HEIGHT >> 1), MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), (MMI_MENUITEM_HEIGHT) + 6 /* editor border */, DM_FIXED_MULTILINE_INPUTBOX_HEIGHT_NO_MULTITAP, /* Because there is not title, so we move start y */
    #else
        MMI_COMMON_CONTENT_X + CAT111_MARGIN, MMI_COMMON_CONTENT_Y - (MMI_TITLE_HEIGHT >> 1), MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), (MMI_MENUITEM_HEIGHT << 1) /* editor border */, DM_FIXED_MULTILINE_INPUTBOX_HEIGHT_NO_MULTITAP, /* Because there is not title, so we move start y */
    #endif
    MMI_COMMON_CONTENT_X + CAT111_MARGIN, CAT111_GAP, MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), MMI_SINGLELINE_INPUTBOX_HEIGHT, DM_PREVIOUS_CONTROL_END_Y,
    MMI_COMMON_CONTENT_X + CAT111_MARGIN, CAT111_GAP + MMI_SINGLELINE_INPUTBOX_HEIGHT, MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), MMI_MENUITEM_HEIGHT, DM_PREVIOUS_CONTROL_END_Y,
#else
    #ifdef __MMI_FTE_SUPPORT__
        #ifdef __MMI_MAINLCD_240X320__
            MMI_COMMON_CONTENT_X + CAT111_MARGIN, MMI_COMMON_CONTENT_Y - (MMI_TITLE_HEIGHT >> 1) - (MMI_TITLE_HEIGHT >> 2), MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), (MMI_SINGLELINE_INPUTBOX_HEIGHT << 1) /* editor border */, DM_FIXED_MULTILINE_INPUTBOX_HEIGHT_NO_MULTITAP, /* Because there is not title, so we move start y */
        #elif defined(__MMI_MAINLCD_240X240__) 
			MMI_COMMON_CONTENT_X + CAT111_MARGIN, MMI_COMMON_CONTENT_Y - (MMI_TITLE_HEIGHT >> 1) - (MMI_TITLE_HEIGHT >> 2), MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), (MMI_SINGLELINE_INPUTBOX_HEIGHT << 1) /* editor border */, DM_FIXED_MULTILINE_INPUTBOX_HEIGHT_NO_MULTITAP, /* Because there is not title, so we move start y */
		#else
            MMI_COMMON_CONTENT_X + CAT111_MARGIN, MMI_COMMON_CONTENT_Y - (MMI_TITLE_HEIGHT >> 1), MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), (MMI_SINGLELINE_INPUTBOX_HEIGHT << 1) /* editor border */, DM_FIXED_MULTILINE_INPUTBOX_HEIGHT_NO_MULTITAP, /* Because there is not title, so we move start y */
        #endif
        MMI_COMMON_CONTENT_X + CAT111_MARGIN, CAT111_GAP, MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), MMI_SINGLELINE_INPUTBOX_HEIGHT, DM_PREVIOUS_CONTROL_END_Y,
        MMI_COMMON_CONTENT_X + CAT111_MARGIN + 3/* align to miltiline */, (CAT111_GAP << 1)/* align to miltiline */, MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), MMI_MENUITEM_HEIGHT, DM_PREVIOUS_CONTROL_END_Y,
    #else
        MMI_COMMON_CONTENT_X + CAT111_MARGIN, MMI_COMMON_CONTENT_Y - (MMI_TITLE_HEIGHT >> 1), MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), (MMI_MENUITEM_HEIGHT << 1) + 6 /* editor border */, DM_FIXED_MULTILINE_INPUTBOX_HEIGHT_NO_MULTITAP, /* Because there is not title, so we move start y */
        MMI_COMMON_CONTENT_X + CAT111_MARGIN, CAT111_GAP, MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), MMI_SINGLELINE_INPUTBOX_HEIGHT, DM_PREVIOUS_CONTROL_END_Y,
		#if defined(__MMI_IMAGE_CACHE_FOR_ONE_GDI_LAYER__) 
        MMI_COMMON_CONTENT_X + CAT111_MARGIN, CAT111_GAP + MMI_SINGLELINE_INPUTBOX_HEIGHT-10, MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), MMI_MENUITEM_HEIGHT, DM_PREVIOUS_CONTROL_END_Y,
        #else
        MMI_COMMON_CONTENT_X + CAT111_MARGIN, CAT111_GAP + MMI_SINGLELINE_INPUTBOX_HEIGHT, MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), MMI_MENUITEM_HEIGHT, DM_PREVIOUS_CONTROL_END_Y,
		#endif
    #endif /* __MMI_FTE_SUPPORT__ */
#endif /* __MMI_MAINLCD_320X240__ */
    DM_DUMMY_COORDINATE
};
#elif defined(__MMI_MAINLCD_96X64__) 

const U8 category111[] = 
{
    9,
    DM_BASE_LAYER_START,
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
    DM_BACK_FILL_AREA,
#else
    DM_SCR_BG,
#endif
    DM_BASE_CONTROL_SET_COMMON,
    //DM_ALIGNED_AREA_START,
    DM_MULTILINE_INPUTBOX1,
    DM_SINGLELINE_INPUTBOX1,
    //DM_ALIGNED_AREA_END,
    DM_SCROLL_TEXT,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set111[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
    DM_FULL_SCREEN_COORDINATE_FLAG,
#endif
//MMI_COMMON_CONTENT_X + CAT111_MARGIN, MMI_COMMON_CONTENT_Y - (MMI_TITLE_HEIGHT >> 1), MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), MMI_COMMON_CONTENT_HEIGHT - (MMI_MENUITEM_HEIGHT << 1) - (MMI_TITLE_HEIGHT >> 1), DM_NO_FLAGS, /* Because there is not title, so we move start y */
MMI_COMMON_CONTENT_X + CAT111_MARGIN, MMI_COMMON_CONTENT_Y - (MMI_TITLE_HEIGHT >> 1)-2, MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), MMI_SINGLELINE_INPUTBOX_HEIGHT, DM_NO_FLAGS, 
MMI_COMMON_CONTENT_X + CAT111_MARGIN, MMI_COMMON_CONTENT_Y - (MMI_TITLE_HEIGHT >> 1)+13, MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), MMI_SINGLELINE_INPUTBOX_HEIGHT, DM_NO_FLAGS, 
//DM_DUMMY_COORDINATE,
//DM_DUMMY_COORDINATE,
MMI_COMMON_CONTENT_X + CAT111_MARGIN, MMI_COMMON_CONTENT_Y + MMI_COMMON_CONTENT_HEIGHT - (12 << 1)+(MMI_TITLE_HEIGHT >> 1)+3+2, MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), 12, DM_NO_FLAGS,    /* scroll text position calculated from buttom */
DM_DUMMY_COORDINATE

};
#else
const U8 category111[] = 
{
    9,
    DM_BASE_LAYER_START,
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
    DM_BACK_FILL_AREA,
#else
    DM_SCR_BG,
#endif
    DM_BASE_CONTROL_SET_COMMON,
    DM_ALIGNED_AREA_START,
    DM_MULTILINE_INPUTBOX1,
    DM_SINGLELINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_SCROLL_TEXT,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set111[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#ifndef __MMI_WALLPAPER_ON_BOTTOM__
    DM_FULL_SCREEN_COORDINATE_FLAG,
#endif
#if defined(__MMI_MAINLCD_128X64__)
    MMI_COMMON_CONTENT_X + CAT111_MARGIN, 0, MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), (MMI_MENUITEM_HEIGHT << 1), DM_NO_FLAGS,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    MMI_COMMON_CONTENT_X + CAT111_MARGIN, ((MMI_MENUITEM_HEIGHT + 1) << 1), MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), MMI_MENUITEM_HEIGHT - 1, DM_NO_FLAGS ,   /* scroll text position calculated from buttom */
#else /* __MMI_MAINLCD_128X64__ */
    MMI_COMMON_CONTENT_X + CAT111_MARGIN, MMI_COMMON_CONTENT_Y - (MMI_TITLE_HEIGHT >> 1), MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), MMI_COMMON_CONTENT_HEIGHT - (MMI_MENUITEM_HEIGHT << 1) - (MMI_TITLE_HEIGHT >> 1), DM_NO_FLAGS, /* Because there is not title, so we move start y */
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
	#if defined(__MMI_IMAGE_CACHE_FOR_ONE_GDI_LAYER__)     
    MMI_COMMON_CONTENT_X + CAT111_MARGIN, MMI_COMMON_CONTENT_Y + MMI_COMMON_CONTENT_HEIGHT - (MMI_MENUITEM_HEIGHT << 1)- 10, MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), MMI_MENUITEM_HEIGHT, DM_NO_FLAGS  ,  /* scroll text position calculated from buttom */
    #else
    MMI_COMMON_CONTENT_X + CAT111_MARGIN, MMI_COMMON_CONTENT_Y + MMI_COMMON_CONTENT_HEIGHT - (MMI_MENUITEM_HEIGHT << 1), MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1), MMI_MENUITEM_HEIGHT, DM_NO_FLAGS  ,  /* scroll text position calculated from buttom */	
	#endif    
#endif /* __MMI_MAINLCD_128X64__ */
    DM_DUMMY_COORDINATE
};
#endif 

#ifdef __MMI_SMALL_PIN_EDIT_SCREEN__
#ifdef __MMI_FTE_SUPPORT__
const U8 category112[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_SCROLL_TEXT,
    DM_BUTTON_BAR1
};

const S16 coordinate_set112[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,

    /* DM_NEW_LAYER_START */
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /* DM_POPUP_BACKGROUND */
    WGUI_POPUP_FTE_BG_X, CAT112_POP_UP_DIALOG_Y_FTE, WGUI_POPUP_FTE_BG_WIDTH, CAT112_POP_UP_DIALOG_HEIGHT_FTE, DM_POPUP_BACKGROUND_GREYSCALE,
    /* DM_CATEGORY_CONTROLLED_AREA */
    CAT112_CONTENT_X, CAT112_ALIGNED_AREA_Y, CAT112_CONTENT_W, CAT112_ALIGNED_AREA_H, DM_NO_FLAGS,
    /* DM_SCROLL_TEXT */
    CAT112_CONTENT_X, CAT112_SCROLL_TEXT_Y, CAT112_CONTENT_W, CAT112_SCROLL_TEXT_H, DM_SCROLL_TEXT_CENTRE_ALIGN_X,
    /* DM_BUTTON_BAR1 */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

#else /* __MMI_FTE_SUPPORT__ */
const U8 category112[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_SCROLL_TEXT,
    DM_BUTTON_BAR1
};

const S16 coordinate_set112[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,

    /* DM_NEW_LAYER_START */
    DM_FULL_SCREEN_COORDINATE_FLAG,

    /* DM_POPUP_BACKGROUND */
#if defined (__MMI_TOUCH_SCREEN__) && (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_320X240__))
    #if defined(__MMI_VIRTUAL_KEYBOARD__)
        MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, CAT112_POP_UP_DIALOG_HEIGHT - MMI_VKBD_TRAY_HEIGHT - 5, DM_POPUP_BACKGROUND_GREYSCALE | DM_DRAW_POPUP_BACKGROUND_3D,
    #else
        MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, CAT112_POP_UP_DIALOG_HEIGHT - CAT112_CANDIDATE_HEIGHT - 5, DM_POPUP_BACKGROUND_GREYSCALE | DM_DRAW_POPUP_BACKGROUND_3D,
    #endif /* defined(__MMI_VIRTUAL_KEYBOARD__) */
#elif defined(__MMI_MAINLCD_320X480__)
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, CAT112_POP_UP_DIALOG_HEIGHT, DM_POPUP_BACKGROUND_GREYSCALE | DM_DRAW_POPUP_BACKGROUND_3D,
#else
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, CAT112_POP_UP_DIALOG_HEIGHT, DM_POPUP_BACKGROUND_GREYSCALE,
#endif
    
    /* DM_CATEGORY_CONTROLLED_AREA */
    CAT112_CONTENT_X, CAT112_ALIGNED_AREA_Y, CAT112_CONTENT_W, CAT112_ALIGNED_AREA_H, DM_NO_FLAGS,
    
    /* DM_SCROLL_TEXT */
    CAT112_CONTENT_X, CAT112_SCROLL_TEXT_Y, CAT112_CONTENT_W, CAT112_SCROLL_TEXT_H, DM_NO_FLAGS,

    /* DM_BUTTON_BAR1 */
#if defined(__MMI_MAINLCD_320X480__)
	DM_DEFAULT_BUTTON_BAR, DM_BUTTON_DISABLE_BACKGROUND, MMI_SOFTKEY_WIDTH
#else /* defined(__MMI_MAINLCD_320X480__) */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
#endif /* defined(__MMI_MAINLCD_320X480__) */
};
#endif /* __MMI_SMALL_PIN_EDIT_SCREEN__ */ 
#endif /* __MMI_FTE_SUPPORT__ */ 

const U8 category113[] =
{
    7,
    DM_BASE_LAYER_START,            // base layer
    DM_SCR_BG,                      // scr bg
    DM_BASE_CONTROL_SET_COMMON,     // base control set common
    DM_STRING,                      // string 1, eg. input password
    DM_STRING,                      // string 2, eg. 012345
    DM_MULTILINE_INPUTBOX1,         // string 3, eg. from xxx
    DM_CATEGORY_CONTROLLED_AREA     // flexible indicator
};

const S16 coordinate_set113[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, CAT113_START_Y + MMI_MENUITEM_HEIGHT * 0, MMI_COMMON_CONTENT_WIDTH, MMI_MENUITEM_HEIGHT, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    MMI_COMMON_CONTENT_X, CAT113_START_Y + MMI_MENUITEM_HEIGHT * 1, MMI_COMMON_CONTENT_WIDTH, MMI_MENUITEM_HEIGHT, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    MMI_COMMON_CONTENT_X, CAT113_START_Y + MMI_MENUITEM_HEIGHT * 2, MMI_COMMON_CONTENT_WIDTH, /*MMI_MENUITEM_HEIGHT*2 + 6*/CAT113_MLEDIT_HEIGHT, /*DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y*/DM_NO_FLAGS,
    DM_DUMMY_COORDINATE
};


#if defined(__MMI_CAT116_SUPPORT__)
const U8 category116[] = 
{
#if defined(__WGUI_CATE_SUPPORT_SEND_KEY__)
    7,
#else /* __WGUI_CATE_SUPPORT_SEND_KEY__ */
    6,
#endif /* __WGUI_CATE_SUPPORT_SEND_KEY__ */
    DM_SCR_BG,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET2,
    DM_MULTILINE_INPUTBOX1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_SINGLELINE_INPUTBOX1,
#if defined(__WGUI_CATE_SUPPORT_SEND_KEY__)
    DM_BUTTON,
#endif /* __WGUI_CATE_SUPPORT_SEND_KEY__ */
};
const S16 coordinate_set116[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    CAT116_MULTILINE_INPUTBOX_X, CAT116_MULTILINE_INPUTBOX_Y, CAT116_MULTILINE_INPUTBOX_W, CAT116_MULTILINE_INPUTBOX_H, DM_NO_FLAGS, /* DM_MULTILINE_INPUTBOX */
    CAT116_MULTILINE_INPUTBOX_X, CAT116_MULTILINE_INPUTBOX_Y, CAT116_MULTILINE_INPUTBOX_W, CAT116_MULTILINE_INPUTBOX_H, DM_NO_FLAGS, /* DM_CATEGORY_CONTROLLED_AREA */
    CAT116_SINGLELINE_INPUTBOX_X, CAT116_SINGLELINE_INPUTBOX_Y, CAT116_SINGLELINE_INPUTBOX_W, CAT116_SINGLELINE_INPUTBOX_H, DM_NO_FLAGS, /* DM_SINGLELINE_INPUTBOX */
#if defined(__WGUI_CATE_SUPPORT_SEND_KEY__)
    CAT116_SINGLELINE_INPUTBOX_X + CAT116_SINGLELINE_INPUTBOX_W + CAT116_SEND_BTN_OFFSET_X, CAT116_SINGLELINE_INPUTBOX_Y + CAT116_SEND_BTN_OFFSET_Y, CAT116_SEND_BTN_W, CAT116_SEND_BTN_H /* DM_BUTTON */
#endif /* __WGUI_CATE_SUPPORT_SEND_KEY__ */
};
#endif /* defined(__MMI_CAT116_SUPPORT__) */

#ifdef __MMI_BMI__
const U8 category122[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
};
const S16 coordinate_set122[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};
#endif

const U8 category123[] = 
{
    10,                              /* Justin */
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,    /* Justin: first item is processed last in pen handler */
    DM_SCR_BG,
    DM_POPUP_BACKGROUND,
    DM_STATUS_BAR1,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_BUTTON_BAR1
};
#if defined(__MMI_FTE_SUPPORT__)
const S16 coordinate_set123[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG, /* Justin: for category controlled area */
    WGUI_POPUP_FTE_BG_X, MMI_POP_UP_DIALOG_Y, WGUI_POPUP_FTE_BG_WIDTH, MMI_POP_UP_DIALOG_FULL_HEIGHT, DM_POPUP_BACKGROUND_FOR_FTE, 
    DM_DEFAULT_STATUS_BAR_FLAG,
    WGUI_POPUP_FTE_AREA_X, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MAIN_LCD_DEVICE_WIDTH - 2*WGUI_POPUP_FTE_AREA_X, MMI_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_FOR_POPUP_FTE | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

#else
const S16 coordinate_set123[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG, /* Justin: for category controlled area */
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_STATUS_BAR_FLAG,
#if defined(__MMI_MAINLCD_320X480__)
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_SOFTKEY_Y - MMI_POP_UP_DIALOG_Y - UI_POPUP_BORDER_SIZE*2,
    DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
#else   /* defined(__MMI_MAINLCD_320X480__) */
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_DIALOG_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
#endif  /* defined(__MMI_MAINLCD_320X480__) */
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
#if defined(__MMI_MAINLCD_320X480__)
    MMI_POP_UP_SOFTKEY_X, MMI_POP_UP_SOFTKEY_Y, MAIN_LCD_DEVICE_WIDTH - 2*MMI_POP_UP_SOFTKEY_X, MMI_POP_UP_SOFTKEY_HEIGHT, DM_BUTTON_DISABLE_BACKGROUND, MMI_POP_UP_SOFTKEY_WIDTH      /* Button Bar */
#else   /* defined(__MMI_MAINLCD_320X480__) */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
#endif   /* defined(__MMI_MAINLCD_320X480__) */
};
#endif /* __MMI_FTE_SUPPORT__ */

#ifdef __MMI_ECOMPASS__
const U8 category126[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
	DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_CATEGORY_CONTROLLED_AREA2
};
const S16 coordinate_set126[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};
#endif

#if 0//def __MMI_WALLPAPER_ON_BOTTOM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */ 

#if (defined(__MMI_ANALOG_CLOCK__) || defined(__MMI_DIGITAL_CLOCK__))
const U8 category128[] = 
{
    7,
    DM_NEW_LAYER_START,
    DM_IMAGE,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_BUTTON,
    DM_BUTTON,
    DM_CATEGORY_CONTROLLED_AREA
};

const S16 coordinate_set128[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_TITLE_LEFT_BUTTON_FLAG,
    DM_DEFAULT_TITLE_RIGHT_BUTTON_FLAG,
    DM_COMMON_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};
#endif

#ifdef __GDI_MEMORY_PROFILE_2__
const U8 category129[] =
{
    6,
    DM_NEW_LAYER_START,
    DM_IMAGE,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_BUTTON,
    DM_BUTTON
};
#if defined(__MMI_FTE_SUPPORT_SLIM__)
const S16 coordinate_set129[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE, DM_NEW_LAYER_WITH_COLOR,
    DM_FULL_SCREEN_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y | DM_BACK_FILL,
    DM_DEFAULT_TITLE_LEFT_BUTTON_FLAG,
    DM_DEFAULT_TITLE_RIGHT_BUTTON_FLAG
};
#else
const S16 coordinate_set129[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE, DM_NEW_LAYER_WITH_COLOR,
    DM_FULL_SCREEN_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_TITLE_LEFT_BUTTON_FLAG,
    DM_DEFAULT_TITLE_RIGHT_BUTTON_FLAG
};
#endif

#if defined(__MMI_FTE_SUPPORT_SLIM__)
const U8 category129_resize[] =
{
    6,       
    DM_SCR_BG,       
    DM_IMAGE,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_BUTTON,
    DM_BUTTON
};
const S16 coordinate_set129_resize[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y | DM_BACK_FILL | DM_RESIZE_IMAGE,
    DM_DEFAULT_TITLE_LEFT_BUTTON_FLAG,
    DM_DEFAULT_TITLE_RIGHT_BUTTON_FLAG
};
#endif

const U8 category129_no_button[] =
{
    4,
    DM_NEW_LAYER_START,
    DM_IMAGE,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON
};
const S16 coordinate_set129_no_button[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE, DM_NEW_LAYER_WITH_COLOR,
    DM_FULL_SCREEN_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};


#else /* __GDI_MEMORY_PROFILE_2__ */
const U8 category129[] =
{
    5,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON,
    DM_BUTTON
};

const S16 coordinate_set129[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_TITLE_LEFT_BUTTON_FLAG,
    DM_DEFAULT_TITLE_RIGHT_BUTTON_FLAG
};
const U8 category129_no_button[] =
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
};
const S16 coordinate_set129_no_button[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE
};
#endif /* __GDI_MEMORY_PROFILE_2__ */


const U8 category130[] =
{
    7,
    DM_NEW_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_BUTTON,
    DM_BUTTON,
	DM_CATEGORY_CONTROLLED_AREA2
};

const S16 coordinate_set130[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_TITLE_LEFT_BUTTON_FLAG,
    DM_DEFAULT_TITLE_RIGHT_BUTTON_FLAG,
	DM_FULL_SCREEN_COORDINATE_FLAG
};

const U8 category132[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_IMAGE,
    DM_BASE_CONTROL_SET_COMMON,    
};

const S16 coordinate_set132[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};

const U8 category132_fullscreen[] =
{
    3,
    DM_BASE_LAYER_START,
    DM_IMAGE,
    DM_TITLE1,
};

const S16 coordinate_set132_fullscreen[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_TITLE_HEIGHT, MMI_COMMON_CONTENT_WIDTH, (MAIN_LCD_DEVICE_HEIGHT - MMI_TITLE_HEIGHT), DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    MMI_TITLE_X, 0, MMI_TITLE_WIDTH, MMI_TITLE_HEIGHT, DM_NO_FLAGS,
};

#if defined(__MMI_SCREEN_ROTATE__)
const U8 category132_rotate[] = 
{
    4,
    DM_SCR_BG,
    DM_BASE_LAYER_START,
    DM_IMAGE,
    DM_BASE_CONTROL_SET_COMMON,    
};

const S16 coordinate_set132_rotate[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};
#endif /* defined(__MMI_SCREEN_ROTATE__) */

#ifdef __MMI_SCREEN_SAVER__
const U8 category131[] = 
{
    4,
    DM_NEW_LAYER_START,
    DM_IMAGE,
    DM_BASE_LAYER_START,
    DM_DATE_TIME_DISPLAY
};

const S16 coordinate_set131[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};
#endif

#ifndef __MMI_MAINLCD_96X64__
const U8 category141_normal[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ALIGNED_AREA_START,
    DM_MULTILINE_INPUTBOX1,
    DM_IMAGE,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set141[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};
#endif

const U8 category141_status_icon[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_STATUS_BAR1,
    DM_ALIGNED_AREA_START,
    DM_MULTILINE_INPUTBOX1,
    DM_IMAGE,
    DM_ALIGNED_AREA_END,
    DM_BUTTON_BAR1
};
const S16 coordinate_set141_status_icon[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    0, MMI_STATUS_BAR_HEIGHT, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_STATUS_BAR_HEIGHT,
        DM_NO_FLAGS,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

#ifdef __MMI_CAT143_FTE__
const U8 category143[] =
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON,
    DM_BUTTON
};

const S16 coordinate_set143[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_TITLE_LEFT_BUTTON_FLAG,
    DM_DEFAULT_TITLE_RIGHT_BUTTON_FLAG
};
#else /* __MMI_CAT143_FTE__ */
const U8 category143[] =
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};

const S16 coordinate_set143[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};
#endif /* __MMI_CAT143_FTE__ */



/* START VIJAY PMT 20050930 */
#ifdef __MMI_SMALL_IMAGE_SELECTOR_SCREEN__
const U8 category146[] = 
{
    6,
    DM_RECTANGLE,
    DM_BASE_LAYER_START,
    DM_BACK_FILL_AREA,
    DM_TITLE1,
    DM_BUTTON_BAR1,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set146[] = 
{
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,   /* Category Screen Coordinates */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,   /* greyscale rectangle */
    MMI_SMALL_SCREEN_X_OFFSET - 1, MMI_TITLE_Y + MMI_TITLE_HEIGHT + MMI_SMALL_SCREEN_Y_OFFSET-1, UI_DEVICE_WIDTH - 2 * MMI_SMALL_SCREEN_X_OFFSET + 2, MMI_CONTENT_HEIGHT - 2 * MMI_SMALL_SCREEN_Y_OFFSET + 2, DM_NO_FLAGS,    /* back fill area *///101706 image select
    MMI_SMALL_SCREEN_X_OFFSET, MMI_TITLE_Y + MMI_TITLE_HEIGHT + MMI_SMALL_SCREEN_Y_OFFSET, UI_DEVICE_WIDTH - 2 * MMI_SMALL_SCREEN_X_OFFSET, MMI_TITLE_HEIGHT, DM_NO_FLAGS,      /* title */
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS, MMI_SOFTKEY_WIDTH,    /* Button Bar */
    MMI_SMALL_SCREEN_X_OFFSET, MMI_TITLE_Y + 2 * MMI_TITLE_HEIGHT + MMI_SMALL_SCREEN_Y_OFFSET+1, UI_DEVICE_WIDTH - 2 * MMI_SMALL_SCREEN_X_OFFSET, MMI_CONTENT_HEIGHT - 2 * MMI_SMALL_SCREEN_Y_OFFSET - MMI_TITLE_HEIGHT-1, DM_NO_FLAGS, /* category control area */
};
#endif /* __MMI_SMALL_IMAGE_SELECTOR_SCREEN__ */ 
/* END VIJAY PMT 20050930 */

#ifdef __MMI_MAINLCD_96X64__
const U8 category151[] = 
{
    6,
    DM_BASE_LAYER_START,
  //  DM_SCR_BG,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_BUTTON_BAR1
};

const S16 coordinate_set151[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    UI_POPUP_BORDER_SIZE, UI_POPUP_BORDER_SIZE+MMI_STATUS_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH - UI_POPUP_BORDER_SIZE*2, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_STATUS_BAR_HEIGHT- UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM|// | DM_ALLIGNED_AREA_NO_BACK_FILL |
        DM_ALLIGNED_AREA_MULTILINE_SCROLL_IF_REQUIRED,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#elif defined(__MMI_MAINLCD_128X64__)
const U8 category151[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_BUTTON_BAR1
};

const S16 coordinate_set151[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    UI_POPUP_BORDER_SIZE, UI_POPUP_BORDER_SIZE, MAIN_LCD_DEVICE_WIDTH - UI_POPUP_BORDER_SIZE*2, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL |
        DM_ALLIGNED_AREA_MULTILINE_SCROLL_IF_REQUIRED,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else /* __MMI_MAINLCD_128X64__ */
const U8 category151[] = 
{
    9,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_POPUP_BACKGROUND,
    DM_STATUS_BAR1,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_BUTTON_BAR1
};

#ifdef __MMI_FTE_SUPPORT__

const S16 coordinate_set151[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    WGUI_POPUP_FTE_BG_X, MMI_POP_UP_DIALOG_Y, WGUI_POPUP_FTE_BG_WIDTH, MMI_POP_UP_DIALOG_FULL_HEIGHT, DM_POPUP_BACKGROUND_FOR_FTE, 
    0, 0, 0, 0, MAIN_LCD_DEVICE_WIDTH, MMI_STATUS_BAR_HEIGHT, DM_NO_FLAGS,
    WGUI_POPUP_FTE_AREA_X, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MAIN_LCD_DEVICE_WIDTH - 2*WGUI_POPUP_FTE_AREA_X, MMI_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_FOR_POPUP_FTE | DM_ALLIGNED_AREA_NO_BACK_FILL |
        DM_ALLIGNED_AREA_MULTILINE_SCROLL_IF_REQUIRED,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

#else
const S16 coordinate_set151[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_NO_FLAGS,
    0, 0, 0, 0, MAIN_LCD_DEVICE_WIDTH, MMI_STATUS_BAR_HEIGHT, DM_NO_FLAGS,
#if defined(__MMI_MAINLCD_320X480__)
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_SOFTKEY_Y - MMI_POP_UP_DIALOG_Y - UI_POPUP_BORDER_SIZE*2,
    DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL | DM_ALLIGNED_AREA_MULTILINE_SCROLL_IF_REQUIRED,
#else
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*4, MMI_POP_UP_DIALOG_HEIGHT - UI_POPUP_BORDER_SIZE*4,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL |
        DM_ALLIGNED_AREA_MULTILINE_SCROLL_IF_REQUIRED,
#endif
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
#if defined(__MMI_MAINLCD_320X480__)
    MMI_POP_UP_SOFTKEY_X, MMI_POP_UP_SOFTKEY_Y, MAIN_LCD_DEVICE_WIDTH - 2*MMI_POP_UP_SOFTKEY_X, MMI_POP_UP_SOFTKEY_HEIGHT, DM_BUTTON_DISABLE_BACKGROUND, MMI_POP_UP_SOFTKEY_WIDTH      /* Button Bar */
#else
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
#endif
};
#endif /* __MMI_FTE_SUPPORT__ */
#endif /* __MMI_MAINLCD_128X64__ */
 
//#if defined(__COSMOS_MMI_PACKAGE__)  
const U8 category152[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1
};
const S16 coordinate_set152[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};
//#endif

const U8 category154_status_icon[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_STATUS_BAR1,
    DM_BUTTON_BAR1,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set154_status_icon[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    DM_COMMON_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};

const U8 category154_normal[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set154_normal[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};

const U8 category157[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_NEW_LAYER_START,
    DM_INLINE_FIXED_LIST1
};
const S16 coordinate_set157[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};

#if defined(__MMI_MAINLCD_128X64__)
const U8 category165[] = 
{
    6,
    DM_BASE_LAYER_START,
 //   DM_NEW_LAYER_START,
 //   DM_POPUP_BACKGROUND,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_BUTTON_BAR1
};
const S16 coordinate_set165[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    UI_POPUP_BORDER_SIZE, UI_POPUP_BORDER_SIZE, MAIN_LCD_DEVICE_WIDTH - UI_POPUP_BORDER_SIZE*2, MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT - UI_POPUP_BORDER_SIZE*2,
    DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH       /* Button Bar */
};
#else /* __MMI_MAINLCD_128X64__ */
#if defined(__MMI_MAINLCD_96X64__)
const U8 category165[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_ALIGNED_AREA_START,
//    DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_BUTTON_BAR1
};
#else
const U8 category165[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
    DM_BUTTON_BAR1
};
#endif
#if defined(__MMI_MAINLCD_96X64__)
const S16 coordinate_set165[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT- MMI_SOFTKEY_HEIGHT, DM_POPUP_BACKGROUND_HATCH_FILL, 
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_DIALOG_HEIGHT- MMI_SOFTKEY_HEIGHT - UI_POPUP_BORDER_SIZE*2,
       DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM |DM_ALLIGNED_AREA_NO_BACK_FILL,//  
   // DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#elif defined (__MMI_FTE_SUPPORT__)
const S16 coordinate_set165[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    WGUI_POPUP_FTE_BG_X, MMI_POP_UP_DIALOG_Y, WGUI_POPUP_FTE_BG_WIDTH, MMI_POP_UP_DIALOG_FULL_HEIGHT, DM_POPUP_BACKGROUND_GREYSCALE | DM_POPUP_BACKGROUND_FOR_FTE, 
    WGUI_POPUP_FTE_AREA_X, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MAIN_LCD_DEVICE_WIDTH - 2*WGUI_POPUP_FTE_AREA_X, MMI_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_FOR_POPUP_FTE | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else /* __MMI_FTE_SUPPORT__ */
const S16 coordinate_set165[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT,
        DM_POPUP_BACKGROUND_GREYSCALE,
#if defined(__MMI_MAINLCD_320X480__)
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_SOFTKEY_Y - MMI_POP_UP_DIALOG_Y - UI_POPUP_BORDER_SIZE*2,
    DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
#else
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_DIALOG_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
#endif /* defined(__MMI_MAINLCD_320X480__) */
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
#if (defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_FTE_SUPPORT__))
    MMI_POP_UP_SOFTKEY_X, MMI_POP_UP_SOFTKEY_Y, MAIN_LCD_DEVICE_WIDTH - 2*MMI_POP_UP_SOFTKEY_X, MMI_POP_UP_SOFTKEY_HEIGHT, DM_BUTTON_DISABLE_BACKGROUND, MMI_POP_UP_SOFTKEY_WIDTH      /* Button Bar */
#else
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH       /* Button Bar */
#endif  /* defined(__MMI_MAINLCD_320X480__) */
};
#endif /* __MMI_FTE_SUPPORT__ */
#endif /* __MMI_MAINLCD_128X64__ */

#if defined(__MMI_SCREEN_ROTATE__)
const S16 rotated_coordinate_set165[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_ROTATED_POP_UP_DIALOG_X, MMI_ROTATED_POP_UP_DIALOG_Y, MMI_ROTATED_POP_UP_DIALOG_WIDTH,
        MMI_ROTATED_POP_UP_DIALOG_HEIGHT, DM_NO_FLAGS,
    MMI_ROTATED_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2,
        MMI_ROTATED_POP_UP_DIALOG_HEIGHT - UI_POPUP_BORDER_SIZE*2, DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_ROTATED_SOFTKEY_WIDTH
};
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 

const U8 category166[] = 
{
    2,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set166[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG
};

const U8 category171[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1,
	DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set171[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG
};

#if defined(__MMI_PHB_QUICK_SEARCH__) 

#if defined(__MMI_MAINLCD_320X240__) && !defined(__MMI_FTE_SUPPORT__)
const U8 category199[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1,
};

const S16 coordinate_set199[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,

    /* DM_HORIZONTAL_TAB_BAR */
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
         MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS, 

    /* DM_CATEGORY_CONTROLLED_AREA, coordinate not used */ 
    DM_SUBMENU_CONTENT_COORDINATE_FLAG,

    /* DM_BUTTON_BAR1 */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else /* __MMI_MAINLCD_320X240__ */
const U8 category199[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1,
    DM_BUTTON,
};

const S16 coordinate_set199[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,

    /* DM_STATUS_BAR1 */
    DM_DEFAULT_STATUS_BAR_FLAG,

    /* DM_HORIZONTAL_TAB_BAR */
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
         MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS, 

    /* DM_CATEGORY_CONTROLLED_AREA, coordinate not used */ 
    DM_SUBMENU_CONTENT_COORDINATE_FLAG,
    
    /* DM_BUTTON_BAR1 */
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_VIRTUAL_KEYBOARD__)
    DM_DEFAULT_BUTTON_BAR_FLAG, -1,/* Don't draw sofekey by draw manager, for fix performance issue */
#else
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
#endif

    /* Search button */
    0, UI_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - MMI_SINGLELINE_INPUTBOX_HEIGHT, 0, 0, DM_NO_FLAGS,
};
#endif /* __MMI_MAINLCD_320X240__ */

#ifdef __MMI_MAINLCD_320X240__
const U8 category199_scrolltext[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    DM_SCROLL_TEXT,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};

const S16 coordinate_set199_scrolltext[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,

    /* DM_HORIZONTAL_TAB_BAR */
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
         MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS, 

    /* DM_SCROLL_TEXT */
    MMI_COMMON_CONTENT_X, 0, MMI_COMMON_CONTENT_WIDTH, CAT202_SCROLL_HEIGHT, DM_PREVIOUS_CONTROL_END_Y | DM_CENTER_ALIGN_Y | DM_SCROLL_TEXT_USE_FONT_HEIGHT,

    /* DM_CATEGORY_CONTROLLED_AREA, coordinate not used */ 
    DM_SUBMENU_CONTENT_COORDINATE_FLAG,

    /* DM_BUTTON_BAR1 */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else /* __MMI_MAINLCD_320X240__ */
const U8 category199_scrolltext[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_SCROLL_TEXT,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};

const S16 coordinate_set199_scrolltext[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,

    /* DM_STATUS_BAR1 */
    DM_DEFAULT_STATUS_BAR_FLAG,

    /* DM_HORIZONTAL_TAB_BAR */
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
         MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS, 

    /* DM_SCROLL_TEXT */
    MMI_COMMON_CONTENT_X, 0, MMI_COMMON_CONTENT_WIDTH, CAT202_SCROLL_HEIGHT, DM_PREVIOUS_CONTROL_END_Y | DM_CENTER_ALIGN_Y | DM_SCROLL_TEXT_USE_FONT_HEIGHT,

    /* DM_CATEGORY_CONTROLLED_AREA, coordinate not used */ 
    DM_SUBMENU_CONTENT_COORDINATE_FLAG,

    /* DM_BUTTON_BAR1 */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* __MMI_MAINLCD_320X240__ */

#endif
#if defined(__MMI_CSB_BROWSER__)||(defined(__MMI_DICTIONARY_SMALL_SCREEN__)&&defined(__MMI_DICTIONARY__))||defined(__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__)||defined(__MMI_PHB_QUICK_SEARCH__) 
const U8 category200[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_SINGLELINE_INPUTBOX1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BASE_CONTROL_SET_SUBMENU
};

const S16 coordinate_set200[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    CAT200_INPUTBOX_X, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - CAT200_INPUTBOX_H - 1, MAIN_LCD_DEVICE_WIDTH - CAT200_INPUTBOX_X - CAT200_MARGIN_WIDTH - 1 /* border */, CAT200_INPUTBOX_H, DM_NO_FLAGS,
    DM_SUBMENU_CONTENT_COORDINATE_FLAG,
};
#endif
#if defined(__MMI_CSB_BROWSER__)||(!defined(__MMI_DICTIONARY_SMALL_SCREEN__)&&defined(__MMI_DICTIONARY__))||defined(__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__)

const U8 category201[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_DYNAMIC_LIST1,
    DM_MULTILINE_INPUTBOX1,
};
const S16 coordinate_set201[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#if defined ( __MMI_MAINLCD_320X240__)        
    MMI_SUBMENU_CONTENT_X, 0, MMI_SUBMENU_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - CAT201_EDITOR_HEIGHT, DM_NO_FLAGS,
    MMI_SUBMENU_CONTENT_X, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - CAT201_EDITOR_HEIGHT, MMI_SUBMENU_CONTENT_WIDTH, CAT201_EDITOR_HEIGHT, DM_NO_FLAGS,   /* Single Line Input box */
#else
    MMI_SUBMENU_CONTENT_X, MMI_SUBMENU_CONTENT_Y, MMI_SUBMENU_CONTENT_WIDTH, MMI_SUBMENU_CONTENT_HEIGHT - CAT201_EDITOR_HEIGHT, DM_NO_FLAGS,
    MMI_SUBMENU_CONTENT_X, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - CAT201_EDITOR_HEIGHT, MMI_SUBMENU_CONTENT_WIDTH, CAT201_EDITOR_HEIGHT, DM_NO_FLAGS,   /* Single Line Input box */
#endif
};
#endif

#if defined(__MMI_CSB_BROWSER__)||defined(__MMI_PHB_GENERIC_MULTI_SELECT__)||defined(__MMI_PHB_MULTI_OPERATION__)

const U8 category202[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_SCROLL_TEXT,
    DM_CATEGORY_CONTROLLED_AREA
};

const S16 coordinate_set202[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, CAT202_SCROLL_Y, MMI_COMMON_CONTENT_WIDTH, CAT202_SCROLL_HEIGHT, DM_CENTER_ALIGN_Y | DM_SCROLL_TEXT_USE_FONT_HEIGHT,
    DM_EDITOR_CONTENT_COORDINATE_FLAG
};


const U8 category202_noinfo[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};

const S16 coordinate_set202_noinfo[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,    
    DM_EDITOR_CONTENT_COORDINATE_FLAG
};

#endif

#ifdef __MMI_CAT203_SUPPORT__
#ifdef __MMI_FTE_SUPPORT__
const U8 category203[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_BUTTON_BAR1,
    DM_DYNAMIC_LIST1,
    DM_SINGLELINE_INPUTBOX1,
    DM_BUTTON,
    DM_CATEGORY_CONTROLLED_AREA
};

const S16 coordinate_set203[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /* DM_STATUS_BAR1 */
    DM_DEFAULT_STATUS_BAR_FLAG,
    /* DM_BUTTON_BAR1 */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    /* DM_DYNAMIC_LIST1 */
    CAT203_DYNAMIC_LIST_X, CAT203_DYNAMIC_LIST_Y, CAT203_DYNAMIC_LIST_W, CAT203_DYNAMIC_LIST_H, DM_NO_FLAGS,
    /* DM_SINGLELINE_INPUTBOX1 */
    CAT203_SL_INPUTBOX_X, CAT203_SL_INPUTBOX_Y, CAT203_SL_INPUTBOX_W, CAT203_SL_INPUTBOX_H, DM_NO_FLAGS,
    /* DM_BUTTON */
    CAT203_BACKSPACE_X, CAT203_SL_INPUTBOX_Y - CAT203_BACKSPACE_Y_BASED_ON_SL, CAT203_BACKSPACE_W, CAT203_BACKSPACE_H, DM_NO_FLAGS,
    /* DM_CATEGORY_CONTROLLED_AREA */
    CAT203_CONTENT_X, CAT203_CONTENT_Y, CAT203_CONTENT_W, CAT203_CONTENT_H, DM_NO_FLAGS,
};
#else /* __MMI_FTE_SUPPORT__ */
#ifndef __MMI_MAINLCD_128X160__
const U8 category203[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET2,
    DM_MULTILINE_INPUTBOX1,
    //DM_STRING, 
    DM_CATEGORY_CONTROLLED_AREA2,
    DM_DYNAMIC_LIST1,
    DM_CATEGORY_CONTROLLED_AREA
};

const S16 coordinate_set203[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    CAT203_CONTENT_X, CAT203_MULTI_LINE_INPUTBOX_Y, CAT203_CONTENT_W, CAT203_MULTI_LINE_INPUTBOX_H, DM_NO_FLAGS,  /* DM_SINGLELINE_INPUTBOX1 */
    CAT203_CONTENT_X, CAT203_STRING_Y, CAT203_CONTENT_W, CAT203_STRING_H, DM_NO_FLAGS,
    //CAT203_CONTENT_X, CAT203_STRING_Y, CAT203_CONTENT_W, CAT203_STRING_H, DM_LEFT_ALIGN_X | DM_CENTER_ALIGN_Y | DM_BACK_FILL, /* DM_STRING */
    CAT203_CONTENT_X, CAT203_DYNAMIC_LIST_Y, CAT203_CONTENT_W, CAT203_DYNAMIC_LIST_H, DM_NO_FLAGS,             /* DM_DYNAMIC_LIST1 */
    CAT203_CONTENT_X, CAT203_CONTENT_Y, CAT203_CONTENT_W, CAT203_CONTENT_H, DM_NO_FLAGS,             /* DM_CATEGORY_CONTROLLED_AREA */
};
#else /* __MMI_MAINLCD_128X160__ */
const U8 category203[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_BUTTON_BAR1,
    DM_MULTILINE_INPUTBOX1,
    DM_CATEGORY_CONTROLLED_AREA2,    
    DM_DYNAMIC_LIST1,
    DM_CATEGORY_CONTROLLED_AREA
};

const S16 coordinate_set203[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    CAT203_CONTENT_X, CAT203_MULTI_LINE_INPUTBOX_Y, CAT203_CONTENT_W, CAT203_MULTI_LINE_INPUTBOX_H, DM_NO_FLAGS,  /* DM_SINGLELINE_INPUTBOX1 */
    CAT203_CONTENT_X, CAT203_STRING_Y, CAT203_CONTENT_W, CAT203_STRING_H, DM_NO_FLAGS, /* DM_STRING */
    CAT203_CONTENT_X, CAT203_DYNAMIC_LIST_Y, CAT203_CONTENT_W, CAT203_DYNAMIC_LIST_H, DM_NO_FLAGS,             /* DM_DYNAMIC_LIST1 */
    CAT203_CONTENT_X, CAT203_CONTENT_Y, CAT203_CONTENT_W, CAT203_CONTENT_H, DM_NO_FLAGS,             /* DM_CATEGORY_CONTROLLED_AREA */
}; 
#endif /* __MMI_MAINLCD_128X160__ */
#endif /* __MMI_FTE_SUPPORT__ */
#endif /* __MMI_CAT203_SUPPORT__ */

#ifdef __MMI_ENGINEER_MODE__
const U8 category204[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ALIGNED_AREA_START,
    DM_SINGLELINE_INPUTBOX1,
    DM_IMAGE,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set204[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};
#endif

const U8 category205[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set205[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, MAIN_LCD_DEVICE_HEIGHT >> 1, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT >> 1, DM_CENTRE_ALIGN_X,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category210[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1,
    DM_NEW_LAYER_START,
    DM_LIST1
};

const S16 coordinate_set210[] = 
{
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,   /* Category Screen Coordinates */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,   /* greyscale rectangle */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH, /* Button Bar */
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, 0, 0, DM_CATEGORY_CONTROL_COORDINATES /* List */
};

#ifndef __MMI_SLIM_FILE_MANAGER__
const U8 category211[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_DYNAMIC_LIST1,
    DM_CATEGORY_CONTROLLED_AREA2

};

const S16 coordinate_set211[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_SUBMENU_CONTENT_COORDINATE_FLAG,
    0, 1, MMI_SUBMENU_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_MENUITEM_HEIGHT,
        DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y,
    DM_SUBMENU_CONTENT_COORDINATE_FLAG
};

const U8 category212[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_DYNAMIC_LIST1
};
const S16 coordinate_set212[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_SUBMENU_CONTENT_COORDINATE_FLAG,
    0, 1, MMI_SUBMENU_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT,
        DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y
};


const U8 category213[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_DYNAMIC_LIST1,
    DM_CATEGORY_CONTROLLED_AREA
};

const S16 coordinate_set213[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_SUBMENU_CONTENT_X, MMI_SUBMENU_CONTENT_Y, MMI_SUBMENU_CONTENT_WIDTH, MMI_SUBMENU_CONTENT_HEIGHT, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_FULL_SCREEN_COORDINATE_FLAG
};

#if defined(__MMI_SCREEN_ROTATE__)  
const S16 rotated_coordinate_set213[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_CONTENT_COORDINATE_FLAG
};
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 


const U8 category214[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_DYNAMIC_MATRIX1
};

const U8 category216[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_ASYNCDYNAMIC_LIST1
};

const S16 coordinate_set216[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_SUBMENU_CONTENT_COORDINATE_FLAG,
    DM_SUBMENU_CONTENT_COORDINATE, DM_CATEGORY_CONTROL_COORDINATES
};


const U8 category216_info[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_ASYNCDYNAMIC_LIST1,
    DM_CATEGORY_CONTROLLED_AREA2

};

const S16 coordinate_set216_info[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_SUBMENU_CONTENT_COORDINATE_FLAG,
    0, 1, MMI_SUBMENU_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_MENUITEM_HEIGHT,
        DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y,
    DM_SUBMENU_CONTENT_COORDINATE_FLAG
};


const U8 category218[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_ASYNCDYNAMIC_LIST1
};

const S16 coordinate_set218[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_SUBMENU_CONTENT_COORDINATE_FLAG
};


const U8 category218_info[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_ASYNCDYNAMIC_LIST1,
    DM_CATEGORY_CONTROLLED_AREA2

};

const S16 coordinate_set218_info[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_SUBMENU_CONTENT_X, MMI_SUBMENU_CONTENT_Y, MMI_SUBMENU_CONTENT_WIDTH, MMI_SUBMENU_CONTENT_HEIGHT - MMI_MENUITEM_HEIGHT, DM_NO_FLAGS,
    DM_SUBMENU_CONTENT_COORDINATE_FLAG
};

#if defined(GUI_COMMON_SHOW_STATUS_ICON)
const U8 category218_tab[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1
};

const S16 coordinate_set218_tab[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB, DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CATEGORY_CONTROL_COORDINATES,
	DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else   /* defined(GUI_COMMON_SHOW_STATUS_ICON)*/
const U8 category218_tab[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1
};

const S16 coordinate_set218_tab[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB, DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CATEGORY_CONTROL_COORDINATES,
	DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif    /* defined(GUI_COMMON_SHOW_STATUS_ICON)*/


#if defined(GUI_COMMON_SHOW_STATUS_ICON)
const U8 category218_info_tab[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_ASYNCDYNAMIC_LIST1,
	DM_CATEGORY_CONTROLLED_AREA2,
    DM_BUTTON_BAR1
};

const S16 coordinate_set218_info_tab[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB, DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_NO_FLAGS,
    DM_SUBMENU_CONTENT_COORDINATE_FLAG,
	DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else   /* defined(GUI_COMMON_SHOW_STATUS_ICON)*/
const U8 category218_info_tab[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    DM_ASYNCDYNAMIC_LIST1,
	DM_CATEGORY_CONTROLLED_AREA2,
    DM_BUTTON_BAR1
};

const S16 coordinate_set218_info_tab[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB, DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_NO_FLAGS,
    DM_SUBMENU_CONTENT_COORDINATE_FLAG,    
	DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif    /* defined(GUI_COMMON_SHOW_STATUS_ICON)*/

const U8 category217[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_ASYNCDYNAMIC_LIST1,
    DM_CATEGORY_CONTROLLED_AREA
};

const S16 coordinate_set217[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_SUBMENU_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_FULL_SCREEN_COORDINATE_FLAG
};
#endif /* __MMI_SLIM_FILE_MANAGER__ */

const U8 category219[] =
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
	DM_ASYNCDYNAMIC_MATRIX1,
};


const U8 category221[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set221[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

#if defined(__MMI_SCREEN_ROTATE__)

const S16 rotated_coordinate_set221[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,                         /* Category Screen Coordinates */
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_ROTATED_SOFTKEY_WIDTH   /* Button Bar */
};

#endif /* defined(__MMI_SCREEN_ROTATE__) */ 

#if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
const U8 category222[] = 
{
    4,
    DM_CATEGORY_CONTROLLED_AREA2,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set222[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,                         /* Category Screen Coordinates */
    DM_DUMMY_COORDINATE,
    DM_CONTENT_COORDINATE_FLAG
};
#else /* MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24 */
const U8 category222[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};
#endif /* MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24 */

#if defined(__MMI_MAINLCD_320X480__)
const U8 category223[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,                      /* full screen background */
    DM_BASE_CONTROL_SET_COMMON,     /* base control set */
    DM_POPUP_BACKGROUND,            /* popup background */
    DM_IMAGE,                       /* image */
    DM_CATEGORY_CONTROLLED_AREA     /* time */
};
const S16 coordinate_set223[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, WGUI_CAT223_POPUP_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_NO_FLAGS,   /* DM_POPUP_BACKGROUND */
    MMI_POP_UP_DIALOG_X + MMI_POP_UP_CONTENT_MARGIN_X, WGUI_CAT223_POPUP_Y + MMI_POP_UP_CONTENT_MARGIN_Y, MMI_POP_UP_DIALOG_WIDTH - MMI_POP_UP_CONTENT_MARGIN_X*2, MMI_POP_UP_DIALOG_HEIGHT - MMI_POP_UP_CONTENT_MARGIN_Y*2 - WGUI_CAT223_TIME_H, DM_RESIZE_IMAGE | DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,  /* DM_IMAGE */
    DM_DUMMY_COORDINATE             /* DM_CATEGORY_CONTROLLED_AREA */
};
#elif defined(__MMI_MAINLCD_176X220__)
//need draw wall paper
const U8 category223[] = 
{
    5,	
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,     /* base control set */
    DM_CATEGORY_CONTROLLED_AREA,    /* time */
    DM_IMAGE                        /* image */
};
const S16 coordinate_set223[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,            /* control area */
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + (MMI_MENUITEM_HEIGHT << 1), MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT - (MMI_MENUITEM_HEIGHT << 1), DM_RESIZE_IMAGE | DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y  /* image */
};

#else /* defined(__MMI_MAINLCD_320X480__) */
const U8 category223[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,     /* base control set */
    DM_CATEGORY_CONTROLLED_AREA,    /* time */
    DM_IMAGE                        /* image */
};
#ifdef __MMI_MAINLCD_320X240__
const S16 coordinate_set223[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,            /* control area */
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + (MMI_MENUITEM_HEIGHT), MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT - (MMI_MENUITEM_HEIGHT), DM_RESIZE_IMAGE | DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y  /* image */
};
#else
const S16 coordinate_set223[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,            /* control area */
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + (MMI_MENUITEM_HEIGHT << 1), MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT - (MMI_MENUITEM_HEIGHT << 1), DM_RESIZE_IMAGE | DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y  /* image */
};
#endif
#endif /* defined(__MMI_MAINLCD_320X480__) */

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
#endif
#if defined(__MMI_CURRENCY_CONVERTER__)||defined(__MMI_CSB_BROWSER__)||defined(__MMI_PHB_BIRTHDAY_FIELD__)
const U8 category257[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_RECTANGLE,
    DM_IMAGE,
    DM_INLINE_FIXED_LIST1
};
const S16 coordinate_set257[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG,
    3, MMI_CONTENT_Y, DM_CALCULATED_WIDTH, DM_CALCULATED_HEIGHT, DM_LEFT_ALIGN_X | DM_TOP_ALIGN_Y,
    MMI_CONTENT_X, 1, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT,
        DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y
};
#endif

const U8 category1002[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_ASYNCDYNAMIC_LIST1,
    DM_SCROLL_TEXT
};

const S16 coordinate_set1002[] =
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_SUBMENU_CONTENT_COORDINATE, DM_CATEGORY_CONTROL_COORDINATES,     /* List Menu */
    MMI_CONTENT_X , MMI_CONTENT_Y + MMI_CONTENT_HEIGHT - MMI_MENUITEM_HEIGHT, MMI_CONTENT_WIDTH, MMI_MENUITEM_HEIGHT, DM_SCROLL_TEXT_CENTER_ALIGN_Y | DM_SCROLL_TEXT_USE_FONT_HEIGHT
};

const U8 cat1002_tab[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_HORIZONTAL_TAB_BAR,
    DM_ASYNCDYNAMIC_LIST1,
    DM_SCROLL_TEXT
};
const S16 Coordinate_Set1002_tab[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
    MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS,
    DM_SUBMENU_CONTENT_COORDINATE, DM_CATEGORY_CONTROL_COORDINATES,     /* List Menu */
    MMI_CONTENT_X , MMI_CONTENT_Y + MMI_CONTENT_HEIGHT - MMI_MENUITEM_HEIGHT, MMI_CONTENT_WIDTH, MMI_MENUITEM_HEIGHT, DM_SCROLL_TEXT_CENTER_ALIGN_Y | DM_SCROLL_TEXT_USE_FONT_HEIGHT
};

const U8 categoryNSM275[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_setNSM275[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category263[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_ASYNCDYNAMIC_LIST1
};
const S16 coordinate_set263[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    MMI_CONTENT_X, 1, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_CATEGORY_CONTROL_COORDINATES    /* List Menu */
};

const U8 cat263_tab[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_HORIZONTAL_TAB_BAR,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_ASYNCDYNAMIC_LIST1
};
const S16 Coordinate_Set263_tab[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
    MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS,
    DM_CONTENT_COORDINATE_FLAG,
    MMI_CONTENT_X, 1, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_CATEGORY_CONTROL_COORDINATES
};

#ifdef __MMI_FTE_SUPPORT__
const U8 category264[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,
    DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
};

const S16 coordinate_set264[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    WGUI_POPUP_FTE_BG_X, MMI_POP_UP_DIALOG_Y, WGUI_POPUP_FTE_BG_WIDTH, MMI_POP_UP_DIALOG_FULL_HEIGHT, DM_POPUP_BACKGROUND_GREYSCALE | DM_POPUP_BACKGROUND_FOR_FTE, 
    WGUI_POPUP_FTE_AREA_X, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, WGUI_POPUP_FTE_AREA_WIDTH, MMI_POP_UP_DIALOG_FULL_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_FOR_POPUP_FTE | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};

#else
const U8 category264[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_IMAGE
};
const S16 coordinate_set264[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_POPUP_SCREEN_COORDINATE,DM_POPUP_BACKGROUND_GREYSCALE,
    DM_POPUP_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X + ((MMI_POP_UP_DIALOG_WIDTH - WGUI_CAT264_DIAL_ICON_SIZE) >> 1), MMI_POP_UP_DIALOG_Y + WGUI_CAT264_DIAL_ICON_SIZE, WGUI_CAT264_DIAL_ICON_SIZE, WGUI_CAT264_DIAL_ICON_SIZE, DM_NO_FLAGS
};
#endif /* __MMI_FTE_SUPPORT__ */

#if defined(__MMI_BTD_BOX_UI_STYLE__) || defined(__MMI_MEGAPHONE_SUPPORT__)
/* Line in */
const U8 category8001[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,     /* base control set */
    DM_CATEGORY_CONTROLLED_AREA    /* image */
};
const S16 coordinate_set8001[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,            /* control area */
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + (MMI_MENUITEM_HEIGHT << 1), MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT - (MMI_MENUITEM_HEIGHT << 1), DM_RESIZE_IMAGE | DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y  /* image */
};
#endif  // __MMI_BTD_BOX_UI_STYLE__


#ifdef __MMI_CAT265_SUPPORT__
// TBD. To Revise
const U8 category265[] = 
{
#if defined(__MMI_MAINLCD_320X240__) && !defined(__MMI_FTE_SUPPORT__)
    4,
#else /* __MMI_MAINLCD_176X220__ || __MMI_MAINLCD_320X240__ */
    5,
#endif /* __MMI_MAINLCD_176X220__ || __MMI_MAINLCD_320X240__ */

    DM_BASE_LAYER_START,
#if !defined(__MMI_MAINLCD_320X240__) || defined(__MMI_FTE_SUPPORT__)
    DM_SCR_BG,
#endif /*__MMI_MAINLCD_176X220__ && __MMI_MAINLCD_320X240__ */

#if defined ( __MMI_MAINLCD_240X400__) || defined ( __MMI_MAINLCD_320X480__)
    DM_BASE_CONTROL_SET1,
#else /* defined ( __MMI_MAINLCD_240X400__) || defined ( __MMI_MAINLCD_320X480__) */
    DM_BASE_CONTROL_SET2,
#endif /* defined ( __MMI_MAINLCD_240X400__) || defined ( __MMI_MAINLCD_320X480__) */  
    DM_CATEGORY_CONTROLLED_AREA,
    DM_ASYNCDYNAMIC_LIST1
};

const S16 coordinate_set265[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, CAT265_CONTROL_AREA_Y, MAIN_LCD_DEVICE_WIDTH, CAT265_CONTROL_AREA_HEIGHT, DM_NO_FLAGS,
    0, 0, 0, 0, DM_CATEGORY_CONTROL_COORDINATES
};
#endif /* __MMI_CAT265_SUPPORT__ */

#ifdef __KARAOKE_SUPPORT__
/* Megaphone */
const U8 category8002[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,     /* base control set */
    DM_CATEGORY_CONTROLLED_AREA    /* image */
};
const S16 coordinate_set8002[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,            /* control area */
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + (MMI_MENUITEM_HEIGHT << 1), MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT - (MMI_MENUITEM_HEIGHT << 1), DM_RESIZE_IMAGE | DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y  /* image */
};
#endif  // __MMI_BTD_BOX_UI_STYLE__

#ifdef __MMI_MOBILE_TV_CMMB_SUPPORT__
const U8 CAT1023[] = 
{
    10,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_TITLE1,
    DM_HORIZONTAL_TAB_BAR,
    DM_BUTTON,
    DM_BUTTON,
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1,
    DM_CATEGORY_CONTROLLED_AREA,
};

const S16 Coordinate_set1023[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG, /* status bar */
    MMI_TITLE_X, MMI_TITLE_Y, (MMI_TITLE_WIDTH>>1), MMI_TITLE_HEIGHT, DM_NO_FLAGS, /* title */
    MMI_HORIZONTAL_TAB_BAR_X, MMI_TITLE_Y + MMI_TITLE_HEIGHT, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS, /*horizontal tab bar*/
#if defined(__MMI_FTE_SUPPORT__)
    (MMI_TITLE_WIDTH>>1), MMI_TITLE_Y + ((MMI_TITLE_HEIGHT - MMI_TITLEBAR_BUTTON_HEIGHT)>>1) - 3, MMI_TITLEBAR_BUTTON_WIDTH + 7, MMI_TITLEBAR_BUTTON_HEIGHT + 7, DM_NO_FLAGS, /*dm button*/
    MMI_TITLE_WIDTH - 7 - MMI_TITLEBAR_BUTTON_WIDTH, MMI_TITLE_Y + ((MMI_TITLE_HEIGHT - MMI_TITLEBAR_BUTTON_HEIGHT)>>1) - 3, MMI_TITLEBAR_BUTTON_WIDTH + 7, MMI_TITLEBAR_BUTTON_HEIGHT + 7, DM_NO_FLAGS, /*dm button*/
    0, MMI_TITLE_Y + MMI_TITLE_HEIGHT + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, MAIN_LCD_DEVICE_WIDTH, 
        MMI_CONTENT_HEIGHT - MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS, /*list*/
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH, /*button bar*/
    (MMI_TITLE_WIDTH>>1) + 7 + MMI_TITLEBAR_BUTTON_WIDTH, MMI_TITLE_Y, (MMI_TITLE_WIDTH>>1) - 14 - (MMI_TITLEBAR_BUTTON_WIDTH<<1), MMI_TITLE_HEIGHT, DM_NO_FLAGS /*controled area*/
#else /*__MMI_FTE_SUPPORT__*/
    (MMI_TITLE_WIDTH>>1), MMI_TITLE_Y + ((MMI_TITLE_HEIGHT - MMI_TITLEBAR_BUTTON_HEIGHT)>>1) - 3, MMI_TITLEBAR_BUTTON_WIDTH + 6, MMI_TITLEBAR_BUTTON_HEIGHT + 7, DM_NO_FLAGS, /*dm button*/
    MMI_TITLE_WIDTH - 6 - MMI_TITLEBAR_BUTTON_WIDTH, MMI_TITLE_Y + ((MMI_TITLE_HEIGHT - MMI_TITLEBAR_BUTTON_HEIGHT)>>1) - 3, MMI_TITLEBAR_BUTTON_WIDTH + 6, MMI_TITLEBAR_BUTTON_HEIGHT + 7, DM_NO_FLAGS, /*dm button*/
    0, MMI_TITLE_Y + MMI_TITLE_HEIGHT + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, MAIN_LCD_DEVICE_WIDTH, 
        MMI_CONTENT_HEIGHT - MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS, /*list*/
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH, /*button bar*/
    (MMI_TITLE_WIDTH>>1) + 6 + MMI_TITLEBAR_BUTTON_WIDTH, MMI_TITLE_Y, (MMI_TITLE_WIDTH>>1) - 12 - (MMI_TITLEBAR_BUTTON_WIDTH<<1), MMI_TITLE_HEIGHT, DM_NO_FLAGS /*controled area*/
#endif /*__MMI_FTE_SUPPORT__*/
};

#if defined(GUI_DEFAULT_SHOW_STATUS_ICON)
const U8 CAT1008[] = 
{
#if defined (__MMI_MAINLCD_176X220__)
    7,
#else /* __MMI_MAINLCD_176X220__ */
    8,
#endif /* __MMI_MAINLCD_176X220__ */

    DM_BASE_LAYER_START,
#if !defined(__MMI_MAINLCD_176X220__)
    DM_SCR_BG,
#endif /*__MMI_MAINLCD_176X220__*/
    DM_STATUS_BAR1,
    DM_TITLE1,
    DM_HORIZONTAL_TAB_BAR,  
    DM_CATEGORY_CONTROLLED_AREA,
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1
};
const S16 Coordinate_set1008[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG, /*status bar*/
    DM_DEFAULT_TITLE_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_TITLE_Y + MMI_TITLE_HEIGHT, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS, /*horizontal tab bar*/
    0, CAT1008_CONTROL_ARE_Y, MAIN_LCD_DEVICE_WIDTH, CAT1008_CONTROL_AREA_HEIGHT, DM_NO_FLAGS, /*control area*/
    0, CAT1008_LIST_Y, MAIN_LCD_DEVICE_WIDTH, CAT1008_LIST_HEIGHT, /*DM_NO_FLAGS*/DM_CATEGORY_CONTROL_COORDINATES, /*list*/
	DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH /*button bar*/
};


const U8 Cat1009[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_TITLE1,
    DM_HORIZONTAL_TAB_BAR,    
    DM_CATEGORY_CONTROLLED_AREA,
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1
};
const S16 Coordinate_Set1009[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DEFAULT_TITLE_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_TITLE_Y + MMI_TITLE_HEIGHT, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS,/*tab bar*/
    0, 0, 0, 0, DM_CATEGORY_CONTROL_COORDINATES,
    0, MMI_TITLE_Y + MMI_TITLE_HEIGHT + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, MAIN_LCD_DEVICE_WIDTH,
        MMI_CONTENT_HEIGHT - MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_CATEGORY_CONTROL_COORDINATES,/*list*/
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

#else /* GUI_DEFAULT_SHOW_STATUS_ICON */

const U8 CAT1008[] = 
{
#if defined (__MMI_MAINLCD_176X220__)
    6,
#else /* __MMI_MAINLCD_176X220__ */
    7,
#endif /* __MMI_MAINLCD_176X220__ */

    DM_BASE_LAYER_START,
#if !defined(__MMI_MAINLCD_176X220__)
    DM_SCR_BG,
#endif /*__MMI_MAINLCD_176X220__*/
    DM_TITLE1,
    DM_HORIZONTAL_TAB_BAR,  
    DM_CATEGORY_CONTROLLED_AREA,
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1
};
const S16 Coordinate_set1008[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_TITLE_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_TITLE_Y + MMI_TITLE_HEIGHT, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS, /*horizontal tab bar*/
    0, CAT1008_CONTROL_ARE_Y, MAIN_LCD_DEVICE_WIDTH, CAT1008_CONTROL_AREA_HEIGHT, DM_NO_FLAGS, /*control area*/
    0, CAT1008_LIST_Y, MAIN_LCD_DEVICE_WIDTH, CAT1008_LIST_HEIGHT, DM_NO_FLAGS, /*list*/
	DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH /*button bar*/
};


const U8 Cat1009[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_TITLE1,
    DM_HORIZONTAL_TAB_BAR,  
    DM_CATEGORY_CONTROLLED_AREA,
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1
};
const S16 Coordinate_Set1009[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_TITLE_BAR_FLAG, /*title*/
    MMI_HORIZONTAL_TAB_BAR_X, MMI_TITLE_Y + MMI_TITLE_HEIGHT, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS,/*tab bar*/
    0, 0, 0, 0, DM_CATEGORY_CONTROL_COORDINATES,
    0, MMI_TITLE_Y + MMI_TITLE_HEIGHT + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, MAIN_LCD_DEVICE_WIDTH,
        MMI_CONTENT_HEIGHT - MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_CATEGORY_CONTROL_COORDINATES,/*list*/
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH /*button bar*/
};
#endif /* GUI_DEFAULT_SHOW_STATUS_ICON */


const U8 cat1048[] = 
{
#ifdef __MMI_FTE_SUPPORT__
    9,
#else
    8,
#endif
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_MULTILINE_INPUTBOX1,
    DM_ASYNCDYNAMIC_LIST1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_SCROLL_TEXT,
#ifdef __MMI_FTE_SUPPORT__
    DM_BUTTON_BAR1,
    DM_BUTTON
#else
    DM_BUTTON_BAR1
#endif 
};

const S16 Coordinate_set1048[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,	//background
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_SUBMENU_TITLE_X, MMI_SUBMENU_TITLE_Y, MMI_SUBMENU_TITLE_WIDTH, 
    CAT1048_MENU_Y - MMI_SUBMENU_TITLE_Y, DM_NO_FLAGS,//Multiline inputbox
	MMI_SUBMENU_CONTENT_X, CAT1048_MENU_Y, MMI_SUBMENU_CONTENT_WIDTH, CAT1048_MENU_HEIGHT,
	DM_CATEGORY_CONTROL_COORDINATES,//list
	MMI_SUBMENU_CONTENT_X, CAT1048_INFO_AREA_Y, MMI_SUBMENU_CONTENT_WIDTH, CAT1048_INFO_AREA_H,DM_NO_FLAGS,//control area
	GUI_ICONTEXT_MENUITEM_TEXT_X, CAT1048_INFO_AREA_Y,
	MMI_CONTENT_WIDTH - GUI_ICONTEXT_MENUITEM_TEXT_X, CAT1048_INFO_AREA_H, 
	DM_SCROLL_TEXT_CENTER_ALIGN_Y | DM_SCROLL_TEXT_USE_FONT_HEIGHT,//scroll text
#ifdef __MMI_FTE_SUPPORT__
	DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,//button bar
	-1, -1, -1, -1, DM_NO_FLAGS
#else 
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH//button bar
#endif 
};

#endif /*__MMI_MOBILE_TV_CMMB_SUPPORT__*/


const U8 category267[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_SCROLL_TEXT,
    DM_ASYNCDYNAMIC_LIST1,
};
const S16 coordinate_set267[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_SUBMENU_CONTENT_COORDINATE_FLAG,
    MMI_CONTENT_X, MMI_CONTENT_Y + MMI_CONTENT_HEIGHT - MMI_MENUITEM_HEIGHT, MMI_CONTENT_WIDTH,
      MMI_MENUITEM_HEIGHT, DM_SCROLL_TEXT_CENTER_ALIGN_Y | DM_SCROLL_TEXT_USE_FONT_HEIGHT,
    DM_SUBMENU_CONTENT_COORDINATE, DM_CATEGORY_CONTROL_COORDINATES,     /* List Menu */
};

const U8 cat267_tab[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_HORIZONTAL_TAB_BAR,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_SCROLL_TEXT,
    DM_ASYNCDYNAMIC_LIST1,
};
const S16 Coordinate_Set267_tab[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
    MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS,
    DM_SUBMENU_CONTENT_COORDINATE_FLAG,
    MMI_CONTENT_X, MMI_CONTENT_Y + MMI_CONTENT_HEIGHT - MMI_MENUITEM_HEIGHT, MMI_CONTENT_WIDTH,
      MMI_MENUITEM_HEIGHT, DM_SCROLL_TEXT_CENTER_ALIGN_Y | DM_SCROLL_TEXT_USE_FONT_HEIGHT,
    DM_SUBMENU_CONTENT_COORDINATE, DM_CATEGORY_CONTROL_COORDINATES,     /* List Menu */
};

const U8 Cat268_tab[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,    
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1
};
const S16 Coordinate_Set268_tab[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
    MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
    DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CATEGORY_CONTROL_COORDINATES,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category275[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set275[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

/* We are showing status bar in MMS view category screen for that we have to add one extra field(DM_STATUS_BAR1) for status bar */
#ifdef __MMI_TOUCH_SCREEN__
const U8 category276[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_TITLE1,
    DM_BUTTON_BAR1,
    DM_BUTTON,
    DM_BUTTON
};

const S16 coordinate_set276[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    0, MMI_STATUS_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_TITLE_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
    MMI_TITLEBAR_BUTTON_GAP,
#ifndef __MMI_MAINLCD_320X240__
    (MMI_STATUS_BAR_HEIGHT) +
#endif    
    (MMI_TITLE_HEIGHT >> 1) - (MMI_TITLEBAR_BUTTON_HEIGHT >> 1),
    MMI_TITLEBAR_BUTTON_WIDTH, MMI_TITLEBAR_BUTTON_HEIGHT, DM_NO_FLAGS,
    (MAIN_LCD_DEVICE_WIDTH) - (MMI_TITLEBAR_BUTTON_GAP) - (MMI_TITLEBAR_BUTTON_WIDTH) - 1,
#ifndef __MMI_MAINLCD_320X240__
    (MMI_STATUS_BAR_HEIGHT) + 
#endif   
    (MMI_TITLE_HEIGHT >> 1) - (MMI_TITLEBAR_BUTTON_HEIGHT >> 1),
    MMI_TITLEBAR_BUTTON_WIDTH, MMI_TITLEBAR_BUTTON_HEIGHT, DM_NO_FLAGS
};
#else /* __MMI_TOUCH_SCREEN__ */
const U8 category276[] = 
{
    3,
    DM_BASE_LAYER_START,
    /* DM_SCR_BG, */
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set276[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* __MMI_TOUCH_SCREEN__ */


#if defined(__MMI_MAINLCD_320X240__) && !defined(__MMI_FTE_SUPPORT__)
const U8 category280[] = 
{
#ifdef __WGUI_CAT280_SUPPORT_MMS__
    7,
#else /* __WGUI_CAT280_SUPPORT_MMS__ */
    5,
#endif /* __WGUI_CAT280_SUPPORT_MMS__ */
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_MULTILINE_INPUTBOX1,
    DM_BUTTON_BAR1,
#ifdef __WGUI_CAT280_SUPPORT_MMS__
    DM_BUTTON,
    DM_BUTTON,
#endif /* __WGUI_CAT280_SUPPORT_MMS__ */
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set280[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
#ifdef __WGUI_CAT280_SUPPORT_MMS__
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
#endif /* __WGUI_CAT280_SUPPORT_MMS__ */
    DM_DUMMY_COORDINATE
};
#else /* __MMI_MAINLCD_320X240__ */
#ifdef __MMI_FTE_SUPPORT__
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X240__) || defined(__MMI_MAINLCD_320X240__)
const U8 category280[] = 
{
#ifdef __WGUI_CAT280_SUPPORT_MMS__
    7,
#else /* __WGUI_CAT280_SUPPORT_MMS__ */
    5,
#endif /* __WGUI_CAT280_SUPPORT_MMS__ */
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
#ifdef __WGUI_CAT280_SUPPORT_MMS__
    DM_BUTTON,
    DM_BUTTON,
#endif /* __WGUI_CAT280_SUPPORT_MMS__ */
    DM_MULTILINE_INPUTBOX1,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set280[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#ifdef __WGUI_CAT280_SUPPORT_MMS__
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
#endif /* __WGUI_CAT280_SUPPORT_MMS__ */
    MMI_CONTENT_X,MMI_CONTENT_Y - MMI_TITLE_HEIGHT,MMI_CONTENT_WIDTH,MMI_CONTENT_HEIGHT + MMI_TITLE_HEIGHT, DM_FIXED_MULTILINE_INPUTBOX_HEIGHT_NO_MULTITAP,
    DM_DUMMY_COORDINATE
};
#else
const U8 category280[] = 
{
#ifdef __WGUI_CAT280_SUPPORT_MMS__
    7,
#else /* __WGUI_CAT280_SUPPORT_MMS__ */
    5,
#endif /* __WGUI_CAT280_SUPPORT_MMS__ */
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
#ifdef __WGUI_CAT280_SUPPORT_MMS__
    DM_BUTTON,
    DM_BUTTON,
#endif /* __WGUI_CAT280_SUPPORT_MMS__ */
    DM_MULTILINE_INPUTBOX1,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set280[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#ifdef __WGUI_CAT280_SUPPORT_MMS__
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
#endif /* __WGUI_CAT280_SUPPORT_MMS__ */
    DM_COMMON_CONTENT_COORDINATE, DM_FIXED_MULTILINE_INPUTBOX_HEIGHT_NO_MULTITAP,
    DM_DUMMY_COORDINATE
};
#endif /* __MMI_MAINLCD_240X320__ */
#else
const U8 category280[] = 
{
#ifdef __WGUI_CAT280_SUPPORT_MMS__
    7,
#else /* __WGUI_CAT280_SUPPORT_MMS__ */
    5,
#endif /* __WGUI_CAT280_SUPPORT_MMS__ */
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1,
#ifdef __WGUI_CAT280_SUPPORT_MMS__
    DM_BUTTON,
    DM_BUTTON,
#endif /* __WGUI_CAT280_SUPPORT_MMS__ */
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set280[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#if defined(__MMI_MAINLCD_96X64__)        
    DM_EDITOR_CONTENT_COORDINATE_FLAG,
#else/*__MMI_MAINLCD_96X64__*/    
    DM_COMMON_CONTENT_COORDINATE_FLAG,
#endif/*__MMI_MAINLCD_96X64__*/
#ifdef __WGUI_CAT280_SUPPORT_MMS__
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
#endif /* __WGUI_CAT280_SUPPORT_MMS__ */
    DM_DUMMY_COORDINATE
};
#endif /*__MMI_FTE_SUPPORT__*/
#endif

#ifdef __MMI_SUBLCD__
const U8 category301[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_STATUS_BAR1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_IMAGE
};
const S16 coordinate_set301[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, 0, 0, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
    0, 0, SUB_LCD_DEVICE_WIDTH - 1, SUB_LCD_DEVICE_HEIGHT - 1, DM_NO_FLAGS,
    0, 0, SUB_LCD_DEVICE_WIDTH, DM_CALCULATED_HEIGHT, DM_CENTRE_ALIGN_X | DM_PREVIOUS_CONTROL_END_Y
};

const U8 category303[] = {4,
    DM_BASE_LAYER_START,
    DM_STATUS_BAR1,
    DM_DATE_TIME_DISPLAY,
    DM_CATEGORY_CONTROLLED_AREA,
};
const S16 coordinate_set303[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, 0, 0, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
    0, 0, SUB_LCD_DEVICE_WIDTH - 1, SUB_LCD_DEVICE_HEIGHT - 1, DM_NO_FLAGS
};

#ifndef __MMI_SUBLCD_CHARGING_HIDE_STATUS_BAR__
const U8 category304[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_STATUS_BAR1,
    DM_IMAGE
};
const S16 coordinate_set304[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, 0, 0, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
    0, 14, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT - 14, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};
#else /* __MMI_SUBLCD_CHARGING_HIDE_STATUS_BAR__ */ 
const U8 category304[] = 
{
    2,
    DM_BASE_LAYER_START,
    DM_IMAGE
};
const S16 coordinate_set304[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};
#endif /* __MMI_SUBLCD_CHARGING_HIDE_STATUS_BAR__ */ 

const U8 category310[] = 
{
    2,
    DM_BASE_LAYER_START,
    DM_STRING
};
const S16 coordinate_set310[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};

const U8 category311[] = {4,
    DM_BASE_LAYER_START,
    DM_STATUS_BAR1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_IMAGE
};
const S16 coordinate_set311[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, 0, 0, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
    0, 0, SUB_LCD_DEVICE_WIDTH - 1, SUB_LCD_DEVICE_HEIGHT - 1, DM_NO_FLAGS,
    0, 0, SUB_LCD_DEVICE_WIDTH, DM_CALCULATED_HEIGHT, DM_CENTRE_ALIGN_X | DM_PREVIOUS_CONTROL_END_Y
};

const U8 category312[] = {5,
    DM_BASE_LAYER_START,
    DM_STATUS_BAR1,
    DM_DATE_TIME_DISPLAY,
    DM_STRING,
    DM_STRING
};
const S16 coordinate_set312[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, 0, 0, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,
    0, WGUI_CAT312_STRING_Y, SUB_LCD_DEVICE_WIDTH, WGUI_CAT312_STRING_HEIGHT, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y | DM_STRING_BORDERED,  
    0, WGUI_CAT312_STRING_Y + WGUI_CAT312_STRING_HEIGHT + 1, SUB_LCD_DEVICE_WIDTH, WGUI_CAT312_STRING_HEIGHT, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y | DM_STRING_BORDERED
};

const U8 category313[] = 
{
    2,
    DM_BASE_LAYER_START,
    DM_IMAGE
};
const S16 coordinate_set313[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
};

const U8 category314[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_TITLE1,
    DM_LIST1
};
const S16 coordinate_set314[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, SUB_LCD_DEVICE_WIDTH, MMI_SUBLCD_TITLE_HEIGHT, DM_NO_FLAGS,
    0, MMI_SUBLCD_TITLE_HEIGHT, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT - MMI_SUBLCD_TITLE_HEIGHT, DM_NO_FLAGS
};

const U8 category315[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_TITLE1,
    DM_DYNAMIC_LIST1
};
const S16 coordinate_set315[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, SUB_LCD_DEVICE_WIDTH, MMI_SUBLCD_TITLE_HEIGHT, DM_NO_FLAGS,
    0, MMI_SUBLCD_TITLE_HEIGHT, SUB_LCD_DEVICE_WIDTH, SUB_LCD_DEVICE_HEIGHT - MMI_SUBLCD_TITLE_HEIGHT, DM_NO_FLAGS
};
#endif /* __MMI_SUBLCD__ */ 

#if  defined (__MMI_MAINLCD_320X480__)
const U8 category306[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_PANEL,
    DM_BUTTON_BAR1
};
#else /* defined (__MMI_MAINLCD_320X480__) */
const U8 category306[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
#endif /* defined (__MMI_MAINLCD_320X480__) */

#if  defined (__MMI_MAINLCD_320X480__)
const S16 coordinate_set306[] = 
{
    /* Category Screen Coordinates */
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /* Control area */
    DM_FULL_SCREEN_COORDINATE_FLAG, /* Unused */
    /* Panel */
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 58, MMI_COMMON_CONTENT_WIDTH, 58, DM_NO_FLAGS,
    /* Button Bar */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else /* defined (__MMI_MAINLCD_320X480__) */
const S16 coordinate_set306[] = 
{
    /* Category Screen Coordinates */
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /* Control area */
    DM_FULL_SCREEN_COORDINATE_FLAG, /* Unused */
    /* Button Bar */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* defined (__MMI_MAINLCD_320X480__) */

#if defined (__MMI_FTE_SUPPORT__) 
const U8 category307[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_LIST1,
    DM_CATEGORY_CONTROLLED_AREA
};
#else
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X240__) || defined(__MMI_MAINLCD_240X400__)
const U8 category307[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET2,
    DM_LIST1,
    DM_CATEGORY_CONTROLLED_AREA
};
#elif defined(__MMI_MAINLCD_320X480__)
const U8 category307[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET2,
    DM_LIST1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_PANEL
};
#else
const U8 category307[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_LIST1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1,
};
#endif /* defined(__MMI_MAINLCD_240X320__) */
#endif /* __MMI_FTE_SUPPORT__ */

#if defined (__MMI_FTE_SUPPORT__) 
const S16 coordinate_set307[] = 
{
    /* Category Screen Coordinates */
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /* List */
    0, MMI_STATUS_BAR_HEIGHT + WGUI_CAT307_CONTROL_AREA_H - 1, MAIN_LCD_DEVICE_WIDTH, (MMI_MENUITEM_HEIGHT * WGUI_CAT307_NUM_LIST_ITEMS), DM_NO_FLAGS,
    /* Control area */
    0, MMI_STATUS_BAR_HEIGHT, UI_DEVICE_WIDTH, WGUI_CAT307_CONTROL_AREA_H, DM_NO_FLAGS,
};
#else
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X240__) ||defined(__MMI_MAINLCD_240X400__)
const S16 coordinate_set307[] = 
{
    /* Category Screen Coordinates */
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /* List */
    0, MMI_STATUS_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, (MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM), DM_NO_FLAGS,
    /* control area */
    DM_FULL_SCREEN_COORDINATE_FLAG, /* Unused */
};
#elif defined(__MMI_MAINLCD_320X480__)
const S16 coordinate_set307[] = 
{
    /* Category Screen Coordinates */
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /* List */
    0, MMI_STATUS_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, (MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM) + 2, DM_NO_FLAGS,
    /* Control area */
    DM_FULL_SCREEN_COORDINATE_FLAG, /* Unused */
    /* panel */
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - 58, MMI_COMMON_CONTENT_WIDTH, 58, DM_NO_FLAGS
};
#else
const S16 coordinate_set307[] = 
{
    /* Category Screen Coordinates */
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /* List */
    0, 0, MAIN_LCD_DEVICE_WIDTH, (MMI_MENUITEM_HEIGHT * WGUI_CAT_SW_TYP_MENUITEM_NUM), DM_NO_FLAGS,
    /* Control area */
    DM_FULL_SCREEN_COORDINATE_FLAG, /* Unused */
    /* Button bar */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* defined(__MMI_MAINLCD_240X320__) */
#endif /* __MMI_FTE_SUPPORT__ */


#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
const U8 category357[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_IMAGE,
    DM_INLINE_FIXED_LIST1
};
const S16 coordinate_set357[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, MMI_COMMON_CONTENT_Y, DM_CALCULATED_WIDTH, DM_CALCULATED_HEIGHT, DM_LEFT_ALIGN_X | DM_TOP_ALIGN_Y,
    MMI_COMMON_CONTENT_X, 0, MMI_COMMON_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT,
        DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y
};
#endif

#if defined(__MMI_EBOOK_READER__)
const U8 category375[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set375[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG
};

const U8 category375_fullscreen[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set375_fullscreen[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG
};
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  /* __MMI_DUAL_SIM_MASTER__ */
#ifdef __OP01__
const U8 category3010_op01[] =
{
    5,
    DM_BASE_LAYER_START,
	DM_NEW_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_CATEGORY_CONTROLLED_AREA,
	DM_BUTTON_BAR1
};
#ifdef __MMI_FTE_SUPPORT__
const S16 coordinate_set3010_op01[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
	DM_FULL_SCREEN_COORDINATE_FLAG,
    0, MMI_POP_UP_DIALOG_Y+WGUI_CAT3010_POPUP_Y_SHIFT, UI_DEVICE_WIDTH, MMI_POP_UP_DIALOG_HEIGHT -WGUI_CAT3010_POPUP_Y_SHIFT, DM_NO_FLAGS,
    WGUI_POPUP_FTE_AREA_X, MMI_POP_UP_DIALOG_Y + WGUI_CAT3010_POPUP_Y_SHIFT + WGUI_POPUP_FTE_AREA_TOP_SPACE, UI_DEVICE_WIDTH - WGUI_POPUP_FTE_AREA_X*2,
    MMI_POP_UP_DIALOG_HEIGHT - WGUI_POPUP_FTE_AREA_TOP_SPACE - WGUI_POPUP_FTE_AREA_BOTTOM_SPACE - WGUI_CAT3010_POPUP_Y_SHIFT,
    DM_NO_FLAGS,
	DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH

};
#else
const S16 coordinate_set3010_op01[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
	DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_NO_FLAGS,
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_DIALOG_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif
#endif /* __OP01__*/
#ifdef __MMI_FTE_SUPPORT__
const U8 category366[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,  
    DM_POPUP_BACKGROUND,
    DM_CATEGORY_CONTROLLED_AREA

};
const S16 coordinate_set366[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, MMI_POP_UP_DIALOG_Y, UI_DEVICE_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_NO_FLAGS,
    WGUI_POPUP_FTE_AREA_X, MMI_POP_UP_DIALOG_Y + WGUI_POPUP_FTE_AREA_TOP_SPACE, UI_DEVICE_WIDTH - WGUI_POPUP_FTE_AREA_X*2,
    MMI_POP_UP_DIALOG_HEIGHT - WGUI_POPUP_FTE_AREA_TOP_SPACE - WGUI_POPUP_FTE_AREA_BOTTOM_SPACE,
    DM_NO_FLAGS

};
#elif defined(__MMI_MAINLCD_320X480__)
const U8 category366[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_SCR_BG, 
    DM_POPUP_BACKGROUND,
    DM_STATUS_BAR1,
    DM_TITLE1,
	DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set366[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT,
        DM_POPUP_BACKGROUND_GREYSCALE,
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DEFAULT_TITLE_BAR_FLAG,
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_SOFTKEY_Y - MMI_POP_UP_DIALOG_Y - UI_POPUP_BORDER_SIZE*2,
        DM_NO_FLAGS,
    MMI_POP_UP_SOFTKEY_X, MMI_POP_UP_SOFTKEY_Y, MAIN_LCD_DEVICE_WIDTH - 2*MMI_POP_UP_SOFTKEY_X, MMI_POP_UP_SOFTKEY_HEIGHT, DM_BUTTON_DISABLE_BACKGROUND, MMI_POP_UP_SOFTKEY_WIDTH      /* Button Bar */

};
#else /* defined(__MMI_MAINLCD_320X480__) */
const U8 category366[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,  
    DM_POPUP_BACKGROUND,
    DM_CATEGORY_CONTROLLED_AREA

};
const S16 coordinate_set366[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_NO_FLAGS,
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_DIALOG_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_NO_FLAGS
};
#endif /* defined(__MMI_MAINLCD_320X480__) */

const U8 category384[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_DYNAMIC_LIST1,
    DM_SCROLL_TEXT
};

const S16 coordinate_set384[] =
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_SUBMENU_CONTENT_COORDINATE, DM_CATEGORY_CONTROL_COORDINATES,
    MMI_CONTENT_X , MMI_CONTENT_Y + MMI_CONTENT_HEIGHT - MMI_MENUITEM_HEIGHT, MMI_CONTENT_WIDTH, MMI_MENUITEM_HEIGHT, DM_SCROLL_TEXT_CENTER_ALIGN_Y | DM_SCROLL_TEXT_USE_FONT_HEIGHT,
};

const U8 CAT1024[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_ASYNCDYNAMIC_LIST1,
    DM_SCROLL_TEXT
};

const S16 coordinate_set1024[] =
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_SUBMENU_CONTENT_COORDINATE, DM_CATEGORY_CONTROL_COORDINATES,
    MMI_CONTENT_X , MMI_CONTENT_Y + MMI_CONTENT_HEIGHT - MMI_MENUITEM_HEIGHT, MMI_CONTENT_WIDTH, MMI_MENUITEM_HEIGHT, DM_SCROLL_TEXT_CENTER_ALIGN_Y | DM_SCROLL_TEXT_USE_FONT_HEIGHT,
};



#if defined(GUI_DEFAULT_SHOW_STATUS_ICON)
const U8 CAT1025[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_SCROLL_TEXT,    
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1
};

const S16 Coordinate_Set1025[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS,
    MMI_CONTENT_X, MMI_CONTENT_Y + MMI_CONTENT_HEIGHT - MMI_MENUITEM_HEIGHT, MMI_CONTENT_WIDTH,
        MMI_MENUITEM_HEIGHT, DM_SCROLL_TEXT_CENTER_ALIGN_Y | DM_SCROLL_TEXT_USE_FONT_HEIGHT, /* scroll text */
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB - MMI_MENUITEM_HEIGHT, DM_CATEGORY_CONTROL_COORDINATES,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else
const U8 CAT1025[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    /*DM_CATEGORY_CONTROLLED_AREA*/DM_SCROLL_TEXT,
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1
};
const S16 Coordinate_Set1025[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    /*DM_SUBMENU_CONTENT_COORDINATE_FLAG,*/    
	MMI_CONTENT_X, MMI_CONTENT_Y + MMI_CONTENT_HEIGHT - MMI_MENUITEM_HEIGHT, MMI_CONTENT_WIDTH,
        MMI_MENUITEM_HEIGHT, DM_SCROLL_TEXT_CENTER_ALIGN_Y | DM_SCROLL_TEXT_USE_FONT_HEIGHT, /* scroll text */
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CATEGORY_CONTROL_COORDINATES,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif

#ifdef __MMI_MAINLCD_128X64__
const U8 category6003[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};

const S16 coordinate_set6003[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,  
    WGUI_CAT6003_X, WGUI_CAT6003_Y, WGUI_CAT6003_WIDTH, WGUI_CAT6003_HEIGHT, DM_NO_FLAGS,
	DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category6003_no_sk[] = 
{
    2,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA
};

const S16 coordinate_set6003_no_sk[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,        
    WGUI_CAT6003_X, WGUI_CAT6003_Y, WGUI_CAT6003_WIDTH, WGUI_CAT6003_HEIGHT, DM_NO_FLAGS
};
#else  /* __MMI_MAINLCD_128X64__ */
const U8 category6003[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};

const S16 coordinate_set6003[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
#if defined (__MMI_FTE_SUPPORT__)
    WGUI_POPUP_FTE_BG_X, MMI_POP_UP_DIALOG_Y, WGUI_POPUP_FTE_BG_WIDTH, MMI_POP_UP_DIALOG_FULL_HEIGHT, DM_POPUP_BACKGROUND_GREYSCALE, 
#else
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_POPUP_BACKGROUND_GREYSCALE,
#endif
        
    WGUI_CAT6003_X, WGUI_CAT6003_Y, WGUI_CAT6003_WIDTH, WGUI_CAT6003_HEIGHT, DM_NO_FLAGS,

#if defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_FTE_SUPPORT__)
    MMI_POP_UP_SOFTKEY_X, MMI_POP_UP_SOFTKEY_Y, MAIN_LCD_DEVICE_WIDTH - 2*MMI_POP_UP_SOFTKEY_X, MMI_POP_UP_SOFTKEY_HEIGHT, DM_BUTTON_DISABLE_BACKGROUND, MMI_POP_UP_SOFTKEY_WIDTH      /* Button Bar */
#else
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH       /* Button Bar */
#endif  /* defined(__MMI_MAINLCD_320X480__) */
};

const U8 category6003_no_sk[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_CATEGORY_CONTROLLED_AREA
};

const S16 coordinate_set6003_no_sk[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT,
        DM_POPUP_BACKGROUND_GREYSCALE,
        
    WGUI_CAT6003_X, WGUI_CAT6003_Y, WGUI_CAT6003_WIDTH, WGUI_CAT6003_HEIGHT, DM_NO_FLAGS
};
#endif /* __MMI_MAINLCD_128X64__ */
const U8 category402[]=
{
	4,
	DM_BASE_LAYER_START,
	DM_BASE_CONTROL_SET_COMMON,
	DM_SCROLL_TEXT,
	DM_PERCENTAGE_BAR
};

const S16 coordinate_set402[]=
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#ifdef __MMI_MAINLCD_128X64__
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y+2, MAIN_LCD_DEVICE_WIDTH,1 , DM_CENTRE_ALIGN_X|DM_SCROLL_TEXT_USE_FONT_HEIGHT,
    MMI_COMMON_CONTENT_X, 1, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT, DM_PREVIOUS_CONTROL_END_Y|DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y
#else /* __MMI_MAINLCD_128X64__ */
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y+20, MAIN_LCD_DEVICE_WIDTH,1 , DM_CENTRE_ALIGN_X|DM_SCROLL_TEXT_USE_FONT_HEIGHT,
    MMI_COMMON_CONTENT_X, 1, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT, DM_PREVIOUS_CONTROL_END_Y|DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y
#endif /* __MMI_MAINLCD_128X64__ */
};

#ifndef __MMI_UCM_PLUTO_BW__
#ifndef __MMI_CATE_CM_TAB_BAR_SLIM__
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    #if defined(__MMI_MAINLCD_320X480__)
        #define CAT403_FTE_ICONBAR_HEIGHT   169
    #elif defined(__MMI_MAINLCD_240X400__)
        #define CAT403_FTE_ICONBAR_HEIGHT   143
	#elif defined(__MMI_MAINLCD_320X240__)
	    #define CAT403_FTE_ICONBAR_HEIGHT	63
    #elif defined(__MMI_MAINLCD_240X240__)
		#define CAT403_FTE_ICONBAR_HEIGHT   0
    #else /* defined(__MMI_MAINLCD_240X320__) */
        #define CAT403_FTE_ICONBAR_HEIGHT   75
    #endif
    #if defined(__MMI_DIALER_TWO_DT_DIS__) && defined(__MMI_MAINLCD_320X240__)
        #define CAT403_FTE_ICONBAR_HEIGHT   80
    #endif
#else /* __MMI_FTE_SUPPORT__ && __MMI_TOUCH_SCREEN__ */
    #define CAT403_FTE_ICONBAR_HEIGHT       0
#endif /* __MMI_FTE_SUPPORT__ && __MMI_TOUCH_SCREEN__ */

#if defined (__MMI_MAINLCD_320X240__)
const U8 category403[] = 
{
#if defined(__MMI_FTE_SUPPORT__)
    9,
#else /* __MMI_FTE_SUPPORT__ */
    7,
#endif /* __MMI_FTE_SUPPORT__ */
    DM_BASE_LAYER_START,
    DM_SCR_BG,
#if defined(__MMI_FTE_SUPPORT__)
    DM_STATUS_BAR1,
#endif /* __MMI_FTE_SUPPORT__ */
    DM_HORIZONTAL_TAB_BAR,
    DM_IMAGE,
    DM_DATE_TIME_DISPLAY,
    DM_LIST1,
#if defined(__MMI_FTE_SUPPORT__)
    DM_CATEGORY_CONTROLLED_AREA, /* for icon bar */
#endif /* __MMI_FTE_SUPPORT__ */
    DM_BUTTON_BAR1
};
const S16 coordinate_set403[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#if defined(__MMI_FTE_SUPPORT__)
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
    MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS,
#else /* __MMI_FTE_SUPPORT__ */
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
    MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
#endif /* __MMI_FTE_SUPPORT__ */
    MMI_CONTENT_X, WGUI_CAT403_IMG_Y, MMI_CONTENT_WIDTH, WGUI_CAT403_IMG_H, DM_CENTER_ALIGN_Y,
#if !defined(__MMI_FTE_SUPPORT__)
    MMI_CONTENT_X, WGUI_CAT403_MENU_Y, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - (WGUI_CAT403_MENU_Y + 1), DM_NO_FLAGS,
#else /* !__MMI_FTE_SUPPORT__ */
    MMI_CONTENT_X, WGUI_CAT403_MENU_Y, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - WGUI_CAT403_MENU_Y - CAT403_FTE_ICONBAR_HEIGHT, DM_NO_FLAGS,
	MMI_CONTENT_X, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - CAT403_FTE_ICONBAR_HEIGHT, MMI_CONTENT_WIDTH, CAT403_FTE_ICONBAR_HEIGHT, DM_NO_FLAGS,
#endif /* !__MMI_FTE_SUPPORT__ */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else /* defined (__MMI_MAINLCD_320X240__) */
const U8 category403[] = 
{
#if defined(__MMI_FTE_SUPPORT__)
    9,
#else /* defined(__MMI_FTE_SUPPORT__) */
    8,
#endif /* defined(__MMI_FTE_SUPPORT__) */
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_IMAGE,
    DM_DATE_TIME_DISPLAY,
    DM_LIST1,
#if defined(__MMI_FTE_SUPPORT__)
    DM_CATEGORY_CONTROLLED_AREA,    /* for icon bar */
#endif /* defined(__MMI_FTE_SUPPORT__) */
    DM_BUTTON_BAR1
};
const S16 coordinate_set403[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
#if !defined(__MMI_MAINLCD_128X64__)
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
#else /* __MMI_MAINLCD_128X64__ */
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y + MMI_STATUS_BAR_HEIGHT, MMI_HORIZONTAL_TAB_BAR_WIDTH,
#endif /* __MMI_MAINLCD_128X64__ */
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    MMI_CONTENT_X, WGUI_CAT403_IMG_Y, MMI_CONTENT_WIDTH, WGUI_CAT403_IMG_H, DM_CENTER_ALIGN_Y,
    MMI_CONTENT_X, WGUI_CAT403_MENU_Y, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - WGUI_CAT403_MENU_Y - CAT403_FTE_ICONBAR_HEIGHT, DM_NO_FLAGS,
#if defined(__MMI_FTE_SUPPORT__)
    MMI_CONTENT_X, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - CAT403_FTE_ICONBAR_HEIGHT, MMI_CONTENT_WIDTH, CAT403_FTE_ICONBAR_HEIGHT, DM_NO_FLAGS,
#endif /* defined(__MMI_FTE_SUPPORT__) */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* defined (__MMI_MAINLCD_320X240__) */
#endif

#ifdef __MMI_CATE_CM_TAB_BAR_SLIM__
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    #if defined(__MMI_MAINLCD_320X480__)
        #define CAT403_FTE_ICONBAR_HEIGHT   169
    #elif defined(__MMI_MAINLCD_240X400__)
        #define CAT403_FTE_ICONBAR_HEIGHT   143
	#elif defined(__MMI_MAINLCD_320X240__)
	    #define CAT403_FTE_ICONBAR_HEIGHT	63
    #else /* defined(__MMI_MAINLCD_240X320__) */
        #define CAT403_FTE_ICONBAR_HEIGHT   75
    #endif
#else /* __MMI_FTE_SUPPORT__ && __MMI_TOUCH_SCREEN__ */
    #define CAT403_FTE_ICONBAR_HEIGHT       0
#endif /* __MMI_FTE_SUPPORT__ && __MMI_TOUCH_SCREEN__ */

const U8 category403[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
	DM_CATEGORY_CONTROLLED_AREA,
    DM_IMAGE,
    DM_DATE_TIME_DISPLAY,
    DM_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set403[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,    
    //MMI_CONTENT_X, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - CAT403_FTE_ICONBAR_HEIGHT, MMI_CONTENT_WIDTH, CAT403_FTE_ICONBAR_HEIGHT, DM_NO_FLAGS,
#if !defined(__MMI_MAINLCD_128X64__)
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
#else /* __MMI_MAINLCD_128X64__ */
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y + MMI_STATUS_BAR_HEIGHT, MMI_HORIZONTAL_TAB_BAR_WIDTH,
#endif /* __MMI_MAINLCD_128X64__ */
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    MMI_CONTENT_X, WGUI_CAT403_IMG_Y, MMI_CONTENT_WIDTH, WGUI_CAT403_IMG_H, DM_CENTER_ALIGN_Y,
    MMI_CONTENT_X, WGUI_CAT403_MENU_Y, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - WGUI_CAT403_MENU_Y - CAT403_FTE_ICONBAR_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif
#endif
const U8 category404[] = 
{
    6,
    DM_NEW_LAYER_START,
    DM_IMAGE,
    DM_BASE_LAYER_START,
    DM_STATUS_BAR1,
    DM_MULTILINE_INPUTBOX1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set404[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,     /* DM_NEW_LAYER_START */
    DM_FULL_SCREEN_COORDINATE_FLAG,     /* DM_IMAGE */
    DM_DEFAULT_STATUS_BAR_FLAG,         /* STATUS_BAR */
    CAT404_INPUTBOX_X, CAT404_INPUTBOX_Y, CAT404_INPUTBOX_WIDTH, CAT404_INPUTBOX_HEIGHT, DM_FIXED_MULTILINE_INPUTBOX_HEIGHT_NO_MULTITAP,    /* DM_MULTILINE_INPUTBOX1 */
    DM_DEFAULT_BUTTON_BAR,DM_BUTTON_DISABLE_BACKGROUND, MMI_SOFTKEY_WIDTH   /* DM_BUTTON_BAR1 */
};

const U8 category409[] =
{
    9,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,
    DM_SINGLELINE_INPUTBOX1,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set409[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT,
        DM_POPUP_BACKGROUND_GREYSCALE,
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2, MMI_POP_UP_DIALOG_HEIGHT - UI_POPUP_BORDER_SIZE*2,
        DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};
#if defined(__MMI_SCREEN_ROTATE__)
const S16 rotated_coordinate_set409[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_ROTATED_POP_UP_DIALOG_X, MMI_ROTATED_POP_UP_DIALOG_Y, MMI_ROTATED_POP_UP_DIALOG_WIDTH,
        MMI_ROTATED_POP_UP_DIALOG_HEIGHT, DM_NO_FLAGS,
    MMI_ROTATED_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_ROTATED_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE*2,
        MMI_ROTATED_POP_UP_DIALOG_HEIGHT - UI_POPUP_BORDER_SIZE*2, DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM | DM_ALLIGNED_AREA_NO_BACK_FILL,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 

#if defined(__MMI_ATV_SUPPORT__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
const U8 Cat1040[]=
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_IMAGE,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 Coordinate_set1040[]=
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    //MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, (MMI_COMMON_CONTENT_HEIGHT << 1)/3, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    //MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + ((MMI_COMMON_CONTENT_HEIGHT << 1)/3), MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT/3, DM_NO_FLAGS
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, (MMI_COMMON_CONTENT_HEIGHT - WGUI_CAT1040_MULTILINE_H - MMI_MENUITEM_HEIGHT), DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + (MMI_COMMON_CONTENT_HEIGHT - WGUI_CAT1040_MULTILINE_H - MMI_MENUITEM_HEIGHT), MMI_COMMON_CONTENT_WIDTH, WGUI_CAT1040_MULTILINE_H, DM_NO_FLAGS
};
#endif /* defined(__MMI_ATV_SUPPORT__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__) */


const U8 category412[]=
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_IMAGE,
    DM_CATEGORY_CONTROLLED_AREA
};

const S16 coordinate_set412[]=
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, (MMI_MENUITEM_HEIGHT << 1), DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + (MMI_MENUITEM_HEIGHT << 1), MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT - (MMI_MENUITEM_HEIGHT << 1), DM_NO_FLAGS
};

#if defined(__MMI_SCREEN_ROTATE__)
const S16 rotated_coordinate_set412[]=
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,    /* do not display image */
    DM_COMMON_CONTENT_COORDINATE_FLAG
};
#endif /* defined(__MMI_SCREEN_ROTATE__) */

#if defined(__MMI_BARCODEREADER_LOW_LEVEL)
const U8 category415Screen[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set415[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};
#endif

const U8 category420[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1
};
const S16 coordinate_set420[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};

#if defined(__MMI_MAINLCD_320X240__)
    /* integrated title */

const U8 category425[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set425[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category425_no_tab[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ASYNCDYNAMIC_LIST1
};
const S16 coordinate_set425_no_tab[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};

#elif !(defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__))
    /* 172x220, 240x320, ... */

const U8 category425[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set425[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category425_no_tab[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ASYNCDYNAMIC_LIST1
};
const S16 coordinate_set425_no_tab[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};

#elif defined(__MMI_MAINLCD_128X160__)

const U8 category425[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set425[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category425_no_tab[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET1,
    DM_ASYNCDYNAMIC_LIST1
};
const S16 coordinate_set425_no_tab[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};

#else
    /* 128x128 */

const U8 category425[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_HORIZONTAL_TAB_BAR,
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set425[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category425_no_tab[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ASYNCDYNAMIC_LIST1
};
const S16 coordinate_set425_no_tab[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};

#endif

#ifndef __MMI_MAINLCD_128X128__
const U8 category426[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_ASYNCDYNAMIC_LIST1
};
const S16 coordinate_set426[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_SUBMENU_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
};
#endif

#if defined(GUI_COMMON_SHOW_STATUS_ICON)
const U8 category428[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_ASYNCDYNAMIC_LIST1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set428[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB - MMI_MENUITEM_HEIGHT, DM_CATEGORY_CONTROL_COORDINATES,
    DM_MMI_CONTENT_X_WITH_H_TAB, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_MENUITEM_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_MENUITEM_HEIGHT, 
        DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category428_no_tab[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ASYNCDYNAMIC_LIST1,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set428_no_tab[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT- MMI_MENUITEM_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_MENUITEM_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_MENUITEM_HEIGHT, DM_NO_FLAGS
};

#else

const U8 category428[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    DM_ASYNCDYNAMIC_LIST1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set428[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB - MMI_MENUITEM_HEIGHT, DM_CATEGORY_CONTROL_COORDINATES,
    DM_MMI_CONTENT_X_WITH_H_TAB, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_MENUITEM_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_MENUITEM_HEIGHT, 
        DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category428_no_tab[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ASYNCDYNAMIC_LIST1,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set428_no_tab[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT- MMI_MENUITEM_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_MENUITEM_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_MENUITEM_HEIGHT, DM_NO_FLAGS
};
#endif

const U8 category429[] =
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_MULTILINE_INPUTBOX1
};
const S16 coordinate_set429[] =
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, 2*MMI_MENUITEM_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + 2*MMI_MENUITEM_HEIGHT, MMI_COMMON_CONTENT_WIDTH, 
    MMI_COMMON_CONTENT_HEIGHT - 2*MMI_MENUITEM_HEIGHT, DM_NO_FLAGS
};

const U8 category430[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};

const S16 coordinate_set430[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};

#if defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_128X160__)
    /* integrated title */

const U8 category435[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set435[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

#elif !(defined(__MMI_MAINLCD_128X128__))
    /* 172x220, 240x320, ... */

const U8 category435[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set435[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

#else
    /* defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) */ 

const U8 category435[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_HORIZONTAL_TAB_BAR,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set435[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

#endif

#ifdef __MMI_CAT44X_SUPPORT__     

#if defined(__MMI_MAINLCD_320X480__)
const U8 category440[] = 
{
    8,
    DM_SCR_BG,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_SCROLL_TEXT,
    DM_SCROLL_TEXT,
    DM_MULTILINE_INPUTBOX1,
    DM_PANEL
};
const S16 coordinate_set440[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, CAT440_TOP_TEXT_AREA_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + CAT440_TEXT_AREA_LINE_SPACE, MMI_COMMON_CONTENT_WIDTH, CAT440_TOP_TEXT_AREA_HEIGHT/2-CAT440_TEXT_AREA_LINE_SPACE, DM_CENTRE_ALIGN_X|DM_SCROLL_TEXT_USE_FONT_HEIGHT,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + CAT440_TEXT_AREA_LINE_SPACE + CAT440_TOP_TEXT_AREA_HEIGHT/2, MMI_COMMON_CONTENT_WIDTH, CAT440_TOP_TEXT_AREA_HEIGHT/2-CAT440_TEXT_AREA_LINE_SPACE, DM_CENTRE_ALIGN_X|DM_SCROLL_TEXT_USE_FONT_HEIGHT,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + CAT440_TOP_TEXT_AREA_HEIGHT, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT - CAT440_TOP_TEXT_AREA_HEIGHT - CAT440_BOTTOM_PANEL_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + MMI_COMMON_CONTENT_HEIGHT - CAT440_BOTTOM_PANEL_HEIGHT, MMI_COMMON_CONTENT_WIDTH, CAT440_BOTTOM_PANEL_HEIGHT, DM_NO_FLAGS
};
#else /* LCD size */
const U8 category440[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_SCROLL_TEXT,
    DM_SCROLL_TEXT,
    DM_MULTILINE_INPUTBOX1,
    DM_PANEL
};
const S16 coordinate_set440[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, CAT440_TOP_TEXT_AREA_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + CAT440_TEXT_AREA_LINE_SPACE, MMI_COMMON_CONTENT_WIDTH, CAT440_TOP_TEXT_AREA_HEIGHT/2-CAT440_TEXT_AREA_LINE_SPACE, DM_CENTRE_ALIGN_X|DM_SCROLL_TEXT_USE_FONT_HEIGHT,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + CAT440_TEXT_AREA_LINE_SPACE + CAT440_TOP_TEXT_AREA_HEIGHT/2, MMI_COMMON_CONTENT_WIDTH, CAT440_TOP_TEXT_AREA_HEIGHT/2-CAT440_TEXT_AREA_LINE_SPACE, DM_CENTRE_ALIGN_X|DM_SCROLL_TEXT_USE_FONT_HEIGHT,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + CAT440_TOP_TEXT_AREA_HEIGHT, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT - CAT440_TOP_TEXT_AREA_HEIGHT - CAT440_BOTTOM_PANEL_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + MMI_COMMON_CONTENT_HEIGHT - CAT440_BOTTOM_PANEL_HEIGHT, MMI_COMMON_CONTENT_WIDTH, CAT440_BOTTOM_PANEL_HEIGHT, DM_NO_FLAGS
};
#endif /* LCD size */

#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__)
const U8 category443[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_PANEL
};
const S16 coordinate_set443[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT - CAT443_PANEL_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + MMI_COMMON_CONTENT_HEIGHT - CAT443_PANEL_HEIGHT, MMI_COMMON_CONTENT_WIDTH, CAT443_PANEL_HEIGHT, DM_NO_FLAGS
};
#else
const U8 category443[] = 
{
    6,
    DM_NEW_LAYER_START,
    DM_IMAGE,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_PANEL
};
const S16 coordinate_set443[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT - CAT443_PANEL_HEIGHT, DM_NO_FLAGS,
    0, 0, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT - CAT443_PANEL_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT - CAT443_PANEL_HEIGHT, DM_NO_FLAGS,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + MMI_COMMON_CONTENT_HEIGHT - CAT443_PANEL_HEIGHT, MMI_COMMON_CONTENT_WIDTH, CAT443_PANEL_HEIGHT, DM_NO_FLAGS
};
#endif

#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
const U8 category445[] = 
{
    7,
    DM_BASE_LAYER_START,    
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_STRING,
    DM_MULTILINE_INPUTBOX1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set445[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,    
    0, MMI_STATUS_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_TITLE_HEIGHT, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    CAT445_EDITOR_GAP_WIDTH, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT, MMI_CONTENT_WIDTH-CAT445_EDITOR_GAP_WIDTH*2, MAIN_LCD_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - CAT445_CONTROL_AREA_HEIGHT - MMI_TITLE_HEIGHT - MMI_STATUS_BAR_HEIGHT, DM_NO_FLAGS,
    0, MMI_TITLE_HEIGHT + MMI_STATUS_BAR_HEIGHT + (MAIN_LCD_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - CAT445_CONTROL_AREA_HEIGHT - MMI_TITLE_HEIGHT - MMI_STATUS_BAR_HEIGHT), MMI_CONTENT_WIDTH, CAT445_CONTROL_AREA_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else /* __MMI_MAINLCD_240X400__ */
const U8 category445[] = 
{
    6,
    DM_BASE_LAYER_START,    
    DM_SCR_BG,
    DM_STRING,
    DM_MULTILINE_INPUTBOX1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set445[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH, MMI_TITLE_HEIGHT, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    CAT445_EDITOR_GAP_WIDTH, MMI_TITLE_HEIGHT, MMI_CONTENT_WIDTH-CAT445_EDITOR_GAP_WIDTH*2, MAIN_LCD_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - CAT445_CONTROL_AREA_HEIGHT - MMI_TITLE_HEIGHT, DM_NO_FLAGS,
    0, MMI_TITLE_HEIGHT + (MAIN_LCD_DEVICE_HEIGHT - MMI_SOFTKEY_HEIGHT - CAT445_CONTROL_AREA_HEIGHT - MMI_TITLE_HEIGHT), MMI_CONTENT_WIDTH, CAT445_CONTROL_AREA_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* __MMI_MAINLCD_240X400__ */


const U8 category447[] = 
{
    4,
    DM_SCR_BG,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1
};
const S16 coordinate_set447[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};


const U8 category448[] = 
{
    5,
    DM_NEW_LAYER_START,
    DM_RECTANGLE,
    DM_IMAGE,        
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set448[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,        
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE, DM_CENTRE_ALIGN_X|DM_CENTER_ALIGN_Y|DM_BACK_FILL|DM_RESIZE_IMAGE,
    DM_FULL_SCREEN_COORDINATE_FLAG
};


const U8 category449[] = 
{
    7,
    DM_NEW_LAYER_START,
#if defined(__MMI_MAINLCD_320X480__)    
    DM_IMAGE,
#else
    DM_RECTANGLE,
#endif
    DM_RECTANGLE,
    DM_IMAGE,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set449[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,  
    DM_COMMON_CONTENT_COORDINATE_FLAG,
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_CENTRE_ALIGN_X|DM_CENTER_ALIGN_Y|DM_BACK_FILL|DM_RESIZE_IMAGE,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};

#endif /* __MMI_CAT44X_SUPPORT__ */


const U8 category525[]=
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_LIST1,    
    DM_BUTTON_BAR1
};


const S16 coordinate_set525[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y|DM_CATEGORY_CONTROL_COORDINATES,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

#ifdef __MMI_SMS_APP_EMS_SUPPORT__
const U8 categoryEMS[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_SUBMENU,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_MATRIX_MENU1
};
const S16 coordinate_setEMS[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_SUBMENU_CONTENT_X, MMI_SUBMENU_CONTENT_Y + CATEMS_AREA_GAP, MMI_SUBMENU_CONTENT_WIDTH, MMI_SINGLELINE_INPUTBOX_HEIGHT, DM_CENTRE_ALIGN_X|DM_SINGLE_LINE_INPUTBOX_SPECIFIC_HEIGHT,
    MMI_SUBMENU_CONTENT_X, CATEMS_AREA_GAP, MMI_SUBMENU_CONTENT_WIDTH, MMI_SUBMENU_CONTENT_HEIGHT - MMI_SINGLELINE_INPUTBOX_HEIGHT - (CATEMS_AREA_GAP << 1), DM_PREVIOUS_CONTROL_END_Y
};
#endif/*#ifdef __MMI_SMS_APP_EMS_SUPPORT__*/

const U8 category620[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_ALIGNED_AREA_START,
    DM_STRING,
    DM_STRING,
    DM_IMAGE,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set620[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};


#ifdef __UI_MMS_VIEWER_CATEGORY__
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X240__) ||defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_320X240__) 
const U8 category630[] = 
{
#if defined(GUI_COMMON_SHOW_STATUS_ICON)
    4,
#else /* defined(GUI_COMMON_SHOW_STATUS_ICON) */
    3,
#endif /* defined(GUI_COMMON_SHOW_STATUS_ICON) */
    DM_BASE_LAYER_START,
#if defined(GUI_COMMON_SHOW_STATUS_ICON)
    DM_STATUS_BAR1,
#endif /* defined(GUI_COMMON_SHOW_STATUS_ICON) */
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set630[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#if defined(GUI_COMMON_SHOW_STATUS_ICON)
	DM_DEFAULT_STATUS_BAR_FLAG, 
#endif /* defined(GUI_COMMON_SHOW_STATUS_ICON) */
	MMI_CONTENT_X, MMI_STATUS_BAR_HEIGHT, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT-MMI_BUTTON_BAR_HEIGHT-MMI_STATUS_BAR_HEIGHT,DM_NO_FLAGS,
	DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
	
};
#else /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */
const U8 category630[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set630[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
	MMI_CONTENT_X, 0, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT,
    DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y,DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) */
#endif /* __UI_MMS_VIEWER_CATEGORY__ */

#ifdef __MMI_ANIMATED_DIAL__

const U8 category631[] = 
{
    4,
    DM_NEW_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET2
};
const S16 coordinate_set631[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,                     /* DM_NEW_LAYER_START */
    DM_FULL_SCREEN_COORDINATE_FLAG,                     /* DM_CATEGORY_CONTROLLED_AREA */
};

#endif /* __MMI_ANIMATED_DIAL__ */

const U8 categoryWcScreen[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_WcScreen[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 categoryVdoScreen[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_VdoScreen[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE
};

const U8 categoryVdoScreen_button[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BASE_CONTROL_SET_COMMON,
    DM_BUTTON,
    DM_BUTTON
};

const S16 coordinate_VdoScreen_button[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_TITLE_LEFT_BUTTON_FLAG,
    DM_DEFAULT_TITLE_RIGHT_BUTTON_FLAG
};

#if 0 /* remove not used category */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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


#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
const U8 category334[] = 
{
    5,
    DM_NEW_LAYER_START,                 /* new layer */
    DM_IMAGE,                           /* background image */
    DM_BASE_LAYER_START,                /* base layer */
    DM_BASE_CONTROL_SET_COMMON,         /* base control set common */
    DM_CATEGORY_CONTROLLED_AREA         /* editable slide bar */
};

const S16 coordinate_set334[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG,
    0, 0, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
#if 0
/* under construction !*/
/* under construction !*/
#endif
    DM_COMMON_CONTENT_COORDINATE_FLAG   /* control area */
};
#endif /* __MMI_EDITABLE_AUDIO_EQUALIZER__ */


#if 0 /* remove not used category */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_MAINLCD_176X220__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined ( __MMI_MAINLCD_240X320__ )
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif 
/* under construction !*/
#if defined(__MMI_SCREEN_ROTATE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_MAINLCD_176X220__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined __MMI_MAINLCD_240X320__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif 
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 
/* under construction !*/
#endif /* remove not used category */

const U8 category227Screen[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set227[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_COMMON_CONTENT_COORDINATE_FLAG
};

#if defined ( __MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X240__) ||defined ( __MMI_MAINLCD_240X400__) || defined ( __MMI_MAINLCD_320X480__) || defined ( __MMI_MAINLCD_360X640__) 
const U8 category230Screen[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET2,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set230[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG
};
#elif defined ( __MMI_MAINLCD_320X240__)
const U8 category230Screen[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set230[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif/* defined ( __MMI_MAINLCD_240X320__) */


#if defined ( __MMI_MAINLCD_128X128__) || defined ( __MMI_MAINLCD_128X160__) ||  defined (__MMI_MAINLCD_176X220__)
const U8 category231Screen[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set231[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category232Screen[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET2,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set232[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG
};

#endif /* defined ( __MMI_MAINLCD_128X128__) || defined ( __MMI_MAINLCD_128X160__) ||  defined (__MMI_MAINLCD_176X220__) */


#if defined(__MMI_BROWSER_2__) || defined(__MMI_GADGET_SUPPORT__)
const U8 category431[] =
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
};

const S16 coordinate_set431[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,                     /* category screen coordinate */
    CAT431_X, CAT431_Y, CAT431_W, CAT431_H, DM_NO_FLAGS /* DM_CATEGORY_CONTROLLED_AREA */
};

const U8 category431_fullscreen[] =
{
    3,
    DM_BASE_LAYER_START,
    DM_TITLE1,
    DM_CATEGORY_CONTROLLED_AREA,
};

const S16 coordinate_set431_fullscreen[] =
{
    DM_FULL_SCREEN_COORDINATE_FLAG, /* category screen coordinate */
                                    /* DM_TITLE */
#if defined(GUI_COMMON_USE_THICK_TITLE)
    0, 0, MMI_COMMON_TITLE_WIDTH, MMI_COMMON_TITLE_HEIGHT, DM_TITLE_SET_THICK,
#else /* defined(GUI_COMMON_USE_THICK_TITLE) */
    0, 0, MMI_COMMON_TITLE_WIDTH, MMI_COMMON_TITLE_HEIGHT, DM_NO_FLAGS,
#endif /* defined(GUI_COMMON_USE_THICK_TITLE) */
                                    /* DM_CATEGORY_CONTROLLED_AREA */
    CAT431_FULLSCREEN_X, CAT431_FULLSCREEN_Y, CAT431_FULLSCREEN_W, CAT431_FULLSCREEN_H, DM_NO_FLAGS
};

#if defined(__MMI_SCREEN_ROTATE__)
const U8 category431_rotate[] =
{
    6,
    DM_BASE_LAYER_START,            /* base layer */
    DM_TITLE1,                      /* title */
    DM_STATUS_BAR1,                 /* statuc icon bar */
    DM_BUTTON_BAR1,                 /* softkey */
    DM_CATEGORY_CONTROLLED_AREA2,   /* softkey background */
    DM_CATEGORY_CONTROLLED_AREA,    /* touch area */
};

const S16 coordinate_set431_rotate[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,                                                                 /* category screen coordinate */
    CAT431_ROTATE_X, 0, CAT431_ROTATE_W - MMI_ROTATED_SOFTKEY_WIDTH, CAT431_ROTATE_Y, DM_NO_FLAGS,  /* DM_TITLE1 */
    DM_DEFAULT_STATUS_BAR_FLAG,                                                                     /* DM_STATUS_BAR1 */
    DM_DEFAULT_BUTTON_BAR, DM_BUTTON_DISABLE_BACKGROUND, MMI_ROTATED_SOFTKEY_WIDTH,                 /* DM_BUTTON_BAR1 */
    DM_DUMMY_COORDINATE,                                                                            /* DM_CATEGORY_CONTROLLED_AREA2 */
    CAT431_ROTATE_X, CAT431_ROTATE_Y, CAT431_ROTATE_W, CAT431_ROTATE_H, DM_NO_FLAGS                 /* DM_CATEGORY_CONTROLLED_AREA */
};

const U8 category431_rotate_fullscreen[] =
{
    3,
    DM_BASE_LAYER_START,            /* base layer */
    DM_TITLE1,                      /* title */
    DM_CATEGORY_CONTROLLED_AREA,    /* touch area */
};

const S16 coordinate_set431_rotate_fullscreen[] =
{
    DM_FULL_SCREEN_COORDINATE_FLAG, /* category screen coordinate */
    CAT431_ROTATE_FULLSCREEN_X, 0, CAT431_ROTATE_FULLSCREEN_W, CAT431_ROTATE_FULLSCREEN_Y, DM_NO_FLAGS, /* DM_TITLE1 */
    CAT431_ROTATE_FULLSCREEN_X, CAT431_ROTATE_FULLSCREEN_Y, CAT431_ROTATE_FULLSCREEN_W, CAT431_ROTATE_FULLSCREEN_H, DM_NO_FLAGS /* DM_CATEGORY_CONTROLLED_AREA */
};
#endif /* defined(__MMI_SCREEN_ROTATE__) */
#endif /* defined(__MMI_BROWSER_2__) || defined(__MMI_GADGET_SUPPORT__) */

#ifdef __MMI_OP01_DCD__
const U8 category432[] =
{
    4,
    DM_SCR_BG,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
};

const S16 coordinate_set432[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,                     /* category screen coordinate */
    CAT432_X, CAT432_Y, CAT432_W, CAT432_H, DM_NO_FLAGS /* DM_CATEGORY_CONTROLLED_AREA */
};
#endif /* __MMI_OP01_DCD__ */

#ifdef __MMI_OP11_CAT433_SUPPORT__
const U8 category433[] = 
{
    6,
    DM_NEW_LAYER_START,             /* wallpaper layer */
    DM_CATEGORY_CONTROLLED_AREA2,   /* wallpaper */
    DM_BASE_LAYER_START,            /* side-bar, status icon, softkey */
    DM_STATUS_BAR1,                 /* status icon */
    DM_BUTTON_BAR1,                 /* softkey */
    DM_CATEGORY_CONTROLLED_AREA     /* details,
                                       pop-up menu in new layer */
};
const S16 coordinate_set433[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,                 /* new layer */
    DM_DUMMY_COORDINATE,                            /* control area 2 */
    DM_DEFAULT_STATUS_BAR_FLAG,                     /* status bar */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,  /* softkey */
    MMI_CONTENT_X, MMI_STATUS_BAR_HEIGHT, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_STATUS_BAR_HEIGHT, DM_NO_FLAGS    /* control area */
};
#endif /* __MMI_OP11_CAT433_SUPPORT__ */


#ifdef __MMI_OP12_CAT533_SUPPORT__
const U8 category533[] = 
{
    6,
    DM_NEW_LAYER_START,             /* wallpaper layer */
    DM_CATEGORY_CONTROLLED_AREA2,   /* wallpaper */
    DM_BASE_LAYER_START,            /* tool-bar, status icon, softkey */
    DM_STATUS_BAR1,                 /* status icon */
    DM_BUTTON_BAR1,                 /* softkey */
    DM_CATEGORY_CONTROLLED_AREA     /* details,
                                       pop-up menu in new layer */
};

const S16 coordinate_set533[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,                 /* new layer */
    DM_DUMMY_COORDINATE,                            /* control area 2 */
    DM_DEFAULT_STATUS_BAR_FLAG,                     /* status bar */
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,  /* softkey */
    MMI_CONTENT_X, MMI_STATUS_BAR_HEIGHT, MMI_CONTENT_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_STATUS_BAR_HEIGHT, DM_NO_FLAGS    /* control area */
};
#endif /* __MMI_OP12_CAT533_SUPPORT__ */


#if defined(GUI_DEFAULT_SHOW_STATUS_ICON)
const U8 category626[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set626[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CATEGORY_CONTROL_COORDINATES,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else
const U8 category626[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    DM_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set626[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CATEGORY_CONTROL_COORDINATES,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif

#if defined(GUI_DEFAULT_SHOW_STATUS_ICON)
const U8 category627[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set627[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB - MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB  + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
const U8 category628[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_SCROLL_TEXT,    
    DM_DYNAMIC_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set628[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS,
    MMI_CONTENT_X, MMI_CONTENT_Y + MMI_CONTENT_HEIGHT - MMI_MENUITEM_HEIGHT, MMI_CONTENT_WIDTH,
        MMI_MENUITEM_HEIGHT, DM_SCROLL_TEXT_CENTER_ALIGN_Y | DM_SCROLL_TEXT_USE_FONT_HEIGHT, /* scroll text */
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB - MMI_MENUITEM_HEIGHT, DM_CATEGORY_CONTROL_COORDINATES,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
const U8 category629[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,    
    DM_DYNAMIC_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set629[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CATEGORY_CONTROL_COORDINATES,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 Cat1006[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,    
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1
};
const S16 Coordinate_Set1006[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
    MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
    DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CATEGORY_CONTROL_COORDINATES,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

#else
const U8 category627[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    DM_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set627[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
const U8 category628[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    DM_CATEGORY_CONTROLLED_AREA,    
    DM_DYNAMIC_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set628[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_SUBMENU_CONTENT_COORDINATE_FLAG,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CATEGORY_CONTROL_COORDINATES,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
const U8 category629[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,    
    DM_DYNAMIC_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set629[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CATEGORY_CONTROL_COORDINATES,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 Cat1006[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,    
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1
};
const S16 Coordinate_Set1006[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
    MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
    DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CATEGORY_CONTROL_COORDINATES,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif

#if defined(__MMI_CSB_BROWSER__)||defined(__MMI_PHB_UI_IN_TABS__)||defined(__MMI_FRM_HISTORY__)||(!defined(__MMI_NOT_TAB_SUPPORT__))
#if !defined(__MMI_MAINLCD_128X128__) && defined(GUI_DEFAULT_SHOW_STATUS_ICON)
const U8 category657[]=
{
    6, 
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_INLINE_FIXED_LIST1,
    DM_BUTTON_BAR1
};
const s16 coordinate_set657[]=
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,//status bar
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG,MMI_SOFTKEY_WIDTH
};
#elif !defined(__MMI_MAINLCD_128X128__)
const U8 category657[]=
{
    5, 
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    DM_INLINE_FIXED_LIST1,
    DM_BUTTON_BAR1
};
const s16 coordinate_set657[]=
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG,MMI_SOFTKEY_WIDTH
};
#else /* defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_176X220__) */
const U8 category657[]=
{
    4, 
    DM_BASE_LAYER_START,
    DM_HORIZONTAL_TAB_BAR,
    DM_INLINE_FIXED_LIST1,
    DM_BUTTON_BAR1
};
const s16 coordinate_set657[]=
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y,
    DM_DEFAULT_BUTTON_BAR_FLAG,MMI_SOFTKEY_WIDTH
};
#endif /* defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_176X220__) */
#endif

const U8 Category1001[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_RECTANGLE,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_LIST1,
    DM_BUTTON_BAR1
};

const S16 Coordinate_Set1001[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,   /* Category Screen Coordinates */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,   /* greyscale rectangle */
    0, 0, 0, 0, DM_NO_FLAGS,    /* control area */
    0, 0, 0, 0, DM_CATEGORY_CONTROL_COORDINATES, /* List */
    DM_DEFAULT_BUTTON_BAR_FLAG,MMI_SOFTKEY_WIDTH       /* Button Bar */
};

#ifdef __MMI_CAT1X_0P11_SUPPORT__
#ifdef GUI_COMMON_SHOW_STATUS_ICON
const U8 category1001_op11[] = 
{
    7,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_SINGLELINE_INPUTBOX1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_LIST1,
    DM_BUTTON_BAR1
};

const S16 coordinate_set1001_op11[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    0, MMI_STATUS_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_MENUITEM_HEIGHT, DM_SINGLE_LINE_INPUTBOX_SPECIFIC_HEIGHT,   /* single inputbox */
    DM_CONTENT_COORDINATE_FLAG,    /* control area */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, 
    DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y , /* List */
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT,
    DM_NO_FLAGS, MMI_SOFTKEY_WIDTH        /* Button Bar */
};
#else
const U8 category1001_op11[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_SINGLELINE_INPUTBOX1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_LIST1,
    DM_BUTTON_BAR1
};

const S16 coordinate_set1001_op11[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, 0, MAIN_LCD_DEVICE_WIDTH, MMI_MENUITEM_HEIGHT, DM_SINGLE_LINE_INPUTBOX_SPECIFIC_HEIGHT,   /* single inputbox */
    DM_CONTENT_COORDINATE_FLAG,    /* control area */
    0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, 
    DM_PREVIOUS_CONTROL_END_Y | DM_HEIGHT_OFFSET_PREVIOUS_CONTROL_END_Y , /* List */
    0, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MMI_BUTTON_BAR_HEIGHT,
    DM_NO_FLAGS, MMI_SOFTKEY_WIDTH        /* Button Bar */
};
#endif
#endif /* __MMI_CAT1X_0P11_SUPPORT__ */
const U8 Category1003[] = 
{
    5,
        DM_BASE_LAYER_START,
        DM_RECTANGLE,
        DM_CATEGORY_CONTROLLED_AREA,
        DM_LIST1,
        DM_BUTTON_BAR1
};

const S16 Coordinate_Set1003[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,   /* Category Screen Coordinates */
        0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT, DM_NO_FLAGS,   /* greyscale rectangle */
        0, 0, 0, 0, DM_NO_FLAGS,    /* control area */
        0, 0, 0, 0, DM_CATEGORY_CONTROL_COORDINATES, /* List */
        DM_DEFAULT_BUTTON_BAR, DM_NO_FLAGS, MMI_SOFTKEY_WIDTH  /* Button Bar */
};

const U8 Category1004[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_RECTANGLE,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_LIST1,
};

const S16 Coordinate_Set1004[] =
{
    DM_FULL_SCREEN_COORDINATE_FLAG,    /*Category screen coordinates*/
    DM_FULL_SCREEN_COORDINATE_FLAG, /*Greyscale rectangle*/
    0, 0, 0, 0, DM_NO_FLAGS,    /*control area*/
    0, 0, 0, 0, DM_CATEGORY_CONTROL_COORDINATES,    /*List*/
};

#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__) && defined(__MBBMS_INTER__)
const U8 category6001_scr_bg[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET1,
    DM_CATEGORY_CONTROLLED_AREA
};
const U8 category6001[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET1,
    DM_CATEGORY_CONTROLLED_AREA
};

const S16 coordinate_set6001[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG
};
#endif

const U8 category9001[] = 
{
    2,
    DM_BASE_LAYER_START,
    DM_RECTANGLE,
};

const S16 coordinate_set9001[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
};

#ifdef __J2ME__
#ifdef __MMI_FTE_SUPPORT__
const U8 Category2002[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_SCROLL_TEXT,
    DM_MULTILINE_INPUTBOX1,
};
const S16 Coordinate_Set2002[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /* DM_CATEGORY_CONTROLLED_AREA */
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, WGUI_CAT2002_TICKER_HEIGHT, DM_NO_FLAGS,
    /* DM_SCROLL_TEXT */
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + WGUI_CAT2002_TICKER_GAP_Y, MMI_COMMON_CONTENT_WIDTH, WGUI_CAT2002_TICKER_HEIGHT - WGUI_CAT2002_TICKER_GAP_Y, DM_NO_FLAGS,
    /* DM_MULTILINE_INPUTBOX1 */
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + WGUI_CAT2002_TICKER_HEIGHT, MMI_COMMON_CONTENT_WIDTH, 
        MMI_COMMON_CONTENT_HEIGHT- WGUI_CAT2002_TICKER_HEIGHT, DM_NO_FLAGS,
};
#else
const U8 Category2002[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_SCROLL_TEXT,
    DM_MULTILINE_INPUTBOX1,
};
const S16 Coordinate_Set2002[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /* DM_SCROLL_TEXT */
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + WGUI_CAT2002_TICKER_GAP_Y, MMI_COMMON_CONTENT_WIDTH, WGUI_CAT2002_TICKER_HEIGHT - WGUI_CAT2002_TICKER_GAP_Y, DM_NO_FLAGS,
    /* DM_MULTILINE_INPUTBOX1 */
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y + WGUI_CAT2002_TICKER_HEIGHT, MMI_COMMON_CONTENT_WIDTH, 
    MMI_COMMON_CONTENT_HEIGHT- WGUI_CAT2002_TICKER_HEIGHT, DM_NO_FLAGS,
};
#endif

#if !defined(GUI_EDITOR_SHOW_TITLE)     
const U8 Category2002_no_ticker[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1,
    //DM_CATEGORY_CONTROLLED_AREA
};
const S16 Coordinate_Set2002_no_ticker[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /* DM_MULTILINE_INPUTBOX1 */
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
    /* DM_CATEGORY_CONTROLLED_AREA */
    //DM_FULL_SCREEN_COORDINATE_FLAG
};
#endif /* (__MMI_MAINLCD_320X240__) */
#endif /* __J2ME__ */

const U8 category9002[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,
    DM_IMAGE,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set9002[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE, DM_ALLIGNED_AREA_EQUAL_SPACE_TOP_AND_BOTTOM,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};

const U8 category9001_op11[] =
{
    5,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set9001_op11[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_POPUP_BACKGROUND_GREYSCALE,
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE * 2, MMI_POP_UP_DIALOG_HEIGHT - UI_POPUP_BORDER_SIZE * 2, DM_NO_FLAGS
};

#ifdef __MMI_OP01_DCD_V30__
const U8 category9003_op01[] =
{
    5,
    DM_SCR_BG,
    DM_BASE_LAYER_START,
    //DM_BASE_CONTROL_SET2,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_STATUS_BAR1,
    DM_BUTTON_BAR1,
};
const S16 coordinate_set9003_op01[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,                     /* category screen coordinate */
    CAT9003_OP01_X, CAT9003_OP01_Y, CAT9003_OP01_W, CAT9003_OP01_H, DM_NO_FLAGS,/* DM_CATEGORY_CONTROLLED_AREA */
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 category9004_op01[] =
{
    5,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
    DM_POPUP_BACKGROUND,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set9004_op01[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_POP_UP_DIALOG_X, MMI_POP_UP_DIALOG_Y, MMI_POP_UP_DIALOG_WIDTH, MMI_POP_UP_DIALOG_HEIGHT, DM_POPUP_BACKGROUND_GREYSCALE,
    MMI_POP_UP_DIALOG_X + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_Y + UI_POPUP_BORDER_SIZE, MMI_POP_UP_DIALOG_WIDTH - UI_POPUP_BORDER_SIZE * 2, MMI_POP_UP_DIALOG_HEIGHT - UI_POPUP_BORDER_SIZE * 2, DM_NO_FLAGS
};
#endif /* __MMI_OP01_DCD_V30__ */

#if defined(GUI_DEFAULT_SHOW_STATUS_ICON)
const U8 category1031[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set1031[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CATEGORY_CONTROL_COORDINATES,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else
const U8 category1031[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set1031[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CATEGORY_CONTROL_COORDINATES,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif
#if defined(GUI_DEFAULT_SHOW_STATUS_ICON)
const U8 category1033[] = 
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_HORIZONTAL_TAB_BAR,
    DM_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set1033[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CATEGORY_CONTROL_COORDINATES,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#else
const U8 category1033[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_HORIZONTAL_TAB_BAR,
    DM_LIST1,
    DM_BUTTON_BAR1
};
const S16 coordinate_set1033[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    MMI_HORIZONTAL_TAB_BAR_X, MMI_HORIZONTAL_TAB_BAR_Y, MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT + MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT, DM_NO_FLAGS,
    DM_MMI_CONTENT_X_WITH_H_TAB, DM_MMI_CONTENT_Y_WITH_H_TAB, DM_MMI_CONTENT_WIDTH_WITH_H_TAB,
        DM_MMI_CONTENT_HEIGHT_WITH_H_TAB, DM_CATEGORY_CONTROL_COORDINATES,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
const U8 category9010[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
	DM_BASE_CONTROL_SET_COMMON,
	DM_CATEGORY_CONTROLLED_AREA,
	DM_CATEGORY_CONTROLLED_AREA2,
};

const S16 coordinate_set9010[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
	DM_CONTENT_COORDINATE_FLAG
};

const U8 category9010_small[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_NEW_LAYER_START,
	DM_CATEGORY_CONTROLLED_AREA,
	DM_CATEGORY_CONTROLLED_AREA2,
	DM_BUTTON_BAR1,
};

const S16 coordinate_set9010_small[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
	DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_CONTENT_COORDINATE_FLAG,
	DM_CONTENT_COORDINATE_FLAG,
    DM_DEFAULT_BUTTON_BAR_FLAG,MMI_SOFTKEY_WIDTH
};
#endif

#ifdef __MMI_TOUCH_SCREEN__
const U8 category9011[] = 
{
    3,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
	DM_CATEGORY_CONTROLLED_AREA,
};

const S16 coordinate_set9011[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,
};
#endif /* __MMI_TOUCH_SCREEN__ */


#ifdef __MMI_TC01_LTUI_SMART_MEMO__
const U8 category9007_tc01[] =
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET2,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_MULTILINE_INPUTBOX1
};

const S16 coordinate_set9007_tc01[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    WGUI_CAT9007_TC01_BG_X, WGUI_CAT9007_TC01_BG_Y, WGUI_CAT9007_TC01_BG_W, WGUI_CAT9007_TC01_BG_H, DM_NO_FLAGS, /* DM_CATEGORY_CONTROLLED_AREA */
    WGUI_CAT9007_TC01_MULTILINE_X, WGUI_CAT9007_TC01_MULTILINE_Y, WGUI_CAT9007_TC01_MULTILINE_WIDTH, WGUI_CAT9007_TC01_MULTILINE_HEIGHT, DM_NO_FLAGS /* DM_MULTILINE_INPUTBOX1 */
};

const U8 category9008_tc01[] =
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET2,
    DM_CATEGORY_CONTROLLED_AREA
};

const S16 coordinate_set9008_tc01[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    WGUI_CAT9007_TC01_BG_X, WGUI_CAT9007_TC01_BG_Y, WGUI_CAT9007_TC01_BG_W, WGUI_CAT9007_TC01_BG_H, DM_NO_FLAGS /* DM_CATEGORY_CONTROLLED_AREA */
};

const U8 category9009_tc01[] =
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET2,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_MULTILINE_INPUTBOX1
};

const S16 coordinate_set9009_tc01[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    WGUI_CAT9007_TC01_BG_X, WGUI_CAT9007_TC01_BG_Y, WGUI_CAT9007_TC01_BG_W, WGUI_CAT9007_TC01_BG_H, DM_NO_FLAGS, /* DM_CATEGORY_CONTROLLED_AREA */
    WGUI_CAT9007_TC01_MULTILINE_X, WGUI_CAT9007_TC01_MULTILINE_Y, WGUI_CAT9007_TC01_MULTILINE_WIDTH, WGUI_CAT9007_TC01_MULTILINE_HEIGHT, DM_NO_FLAGS /* DM_MULTILINE_INPUTBOX1 */
};
#endif /* __MMI_TC01_LTUI_SMART_MEMO__ */

#ifdef __ATV_SMS_SUPPORT__
#ifdef UI_EMS_SUPPORT
const U8 category9006[] =
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
#if defined (__MMI_MAINLCD_320X240__)
    DM_TITLE1,
#else
    DM_STATUS_BAR1,
#endif
    DM_EMS_INPUTBOX1,
    DM_BUTTON_BAR1,
    DM_CATEGORY_CONTROLLED_AREA

};
const S16 coordinate_set9006[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#if defined (__MMI_MAINLCD_320X240__)
    /* DM_TITLE1 */
    WGUI_CAT_MATV_TITLE_X, WGUI_CAT_MATV_TITLE_Y, WGUI_CAT_MATV_TITLE_W, WGUI_CAT_MATV_TITLE_H, DM_NO_FLAGS,
#else
    /* DM_STATUS_BAR1 */
    DM_DEFAULT_STATUS_BAR_FLAG,
#endif
    /* DM_EMS_INPUTBOX1 */
    WGUI_CAT_MATV_EDITOR_X, WGUI_CAT_MATV_EDITOR_Y, WGUI_CAT_MATV_EDITOR_W, WGUI_CAT_MATV_EDITOR_H, DM_NO_FLAGS,
    /* DM_BUTTON_BAR1 */
    DM_DEFAULT_BUTTON_BAR_FLAG,MMI_SOFTKEY_WIDTH,
    /* DM_CATEGORY_CONTROLLED_AREA */
    DM_DUMMY_COORDINATE,
};
#endif /* UI_EMS_SUPPORT */


const U8 category9007[] =
{
    6,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
#if defined (__MMI_MAINLCD_320X240__)
    DM_TITLE1,
#else
    DM_STATUS_BAR1,
#endif
    DM_MULTILINE_INPUTBOX1,
    DM_BUTTON_BAR1,
    DM_CATEGORY_CONTROLLED_AREA

};
const S16 coordinate_set9007[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#if defined (__MMI_MAINLCD_320X240__)
    /* DM_TITLE1 */
    WGUI_CAT_MATV_TITLE_X, WGUI_CAT_MATV_TITLE_Y, WGUI_CAT_MATV_TITLE_W, WGUI_CAT_MATV_TITLE_H, DM_NO_FLAGS,
#else
    /* DM_STATUS_BAR1 */
    DM_DEFAULT_STATUS_BAR_FLAG,
#endif
    /* DM_MULTILINE_INPUTBOX1 */
    WGUI_CAT_MATV_EDITOR_X, WGUI_CAT_MATV_EDITOR_Y, WGUI_CAT_MATV_EDITOR_W, WGUI_CAT_MATV_EDITOR_H, DM_NO_FLAGS,
    /* DM_BUTTON_BAR1 */
    DM_DEFAULT_BUTTON_BAR_FLAG,MMI_SOFTKEY_WIDTH,
    /* DM_CATEGORY_CONTROLLED_AREA */
    DM_DUMMY_COORDINATE,
};


const U8 category9008[] = 
{
#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
    7,
#else
    6,
#endif
    DM_BASE_LAYER_START,
    DM_SCR_BG,
#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
    DM_STATUS_BAR1,
#endif
    DM_TITLE1,
    DM_MULTILINE_INPUTBOX1,
    DM_BUTTON_BAR1,
    DM_CATEGORY_CONTROLLED_AREA
};
const S16 coordinate_set9008[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    /* DM_STATUS_BAR1 */
#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
    DM_DEFAULT_STATUS_BAR_FLAG,
#endif
    /* DM_TITLE1 */
    WGUI_CAT_MATV_TITLE_X, WGUI_CAT_MATV_TITLE_Y, WGUI_CAT_MATV_TITLE_W, WGUI_CAT_MATV_TITLE_H, DM_NO_FLAGS,
    /* DM_MULTILINE_INPUTBOX1 */
    WGUI_CAT_MATV_CONTENT_X, WGUI_CAT_MATV_CONTENT_Y + WGUI_CAT9008_HEADER_H, 
    WGUI_CAT_MATV_CONTENT_W, WGUI_CAT_MATV_CONTENT_H - WGUI_CAT9008_HEADER_H, DM_NO_FLAGS,
    /* DM_BUTTON_BAR1 */
    DM_DEFAULT_BUTTON_BAR_FLAG,MMI_SOFTKEY_WIDTH,
    /* DM_CATEGORY_CONTROLLED_AREA */
    WGUI_CAT_MATV_CONTENT_X, WGUI_CAT_MATV_CONTENT_Y, 
    WGUI_CAT_MATV_CONTENT_W, WGUI_CAT9008_HEADER_H, DM_NO_FLAGS,
};
#ifdef __MMI_MAINLCD_320X240__
#define WGUI_CAT_MATV_POPUP_Y WGUI_CAT_MATV_CONTENT_Y
#define WGUI_CAT_MATV_POPUP_H WGUI_CAT_MATV_CONTENT_H
#else
#define WGUI_CAT_MATV_POPUP_Y WGUI_CAT_MATV_TITLE_Y
#define WGUI_CAT_MATV_POPUP_H WGUI_CAT_MATV_TITLE_H+ WGUI_CAT_MATV_CONTENT_H
#endif
const U8 category9009[] = 
{
    9,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
	DM_CATEGORY_CONTROLLED_AREA,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END,
	DM_BUTTON_BAR1,
};
const S16 coordinate_set9009[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
	WGUI_CAT_MATV_CONTENT_X, WGUI_CAT_MATV_POPUP_Y, WGUI_CAT_MATV_CONTENT_W, WGUI_CAT_MATV_POPUP_H,DM_NO_FLAGS,
	WGUI_CAT_MATV_CONTENT_X, WGUI_CAT_MATV_POPUP_Y, WGUI_CAT_MATV_CONTENT_W, WGUI_CAT_MATV_POPUP_H,DM_NO_FLAGS,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
	DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH,
};
const U8 category9009_full[] = 
{
    8,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
	DM_CATEGORY_CONTROLLED_AREA,
    DM_ALIGNED_AREA_START,
    DM_IMAGE,
    DM_MULTILINE_INPUTBOX1,
    DM_ALIGNED_AREA_END
};
const S16 coordinate_set9009_full[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
	WGUI_CAT_MATV_CONTENT_X, WGUI_CAT_MATV_POPUP_Y, WGUI_CAT_MATV_CONTENT_W, WGUI_CAT_MATV_POPUP_H + MMI_SOFTKEY_BAR_HEIGHT,DM_NO_FLAGS,
	WGUI_CAT_MATV_CONTENT_X, WGUI_CAT_MATV_POPUP_Y, WGUI_CAT_MATV_CONTENT_W, WGUI_CAT_MATV_POPUP_H + MMI_SOFTKEY_BAR_HEIGHT,DM_NO_FLAGS,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE,
    DM_DUMMY_COORDINATE
};

const U8 CAT1010[] = 
{
#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
	6,
#else /*GUI_SUBMENU_SHOW_STATUS_ICON*/
    5,
#endif /*GUI_SUBMENU_SHOW_STATUS_ICON*/
	DM_BASE_LAYER_START,
	DM_SCR_BG,
#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
	DM_STATUS_BAR1,
#endif /*GUI_SUBMENU_SHOW_STATUS_ICON*/
	DM_TITLE1,
	DM_LIST1,
	DM_BUTTON_BAR1
};

const U16 coordinate_set1010[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
    DM_DEFAULT_STATUS_BAR_FLAG,
#endif /*GUI_SUBMENU_SHOW_STATUS_ICON*/
    WGUI_CAT_MATV_TITLE_X, WGUI_CAT_MATV_TITLE_Y, WGUI_CAT_MATV_TITLE_W, WGUI_CAT_MATV_TITLE_H, DM_NO_FLAGS,
	WGUI_CAT_MATV_CONTENT_X, WGUI_CAT_MATV_CONTENT_Y, WGUI_CAT_MATV_CONTENT_W, WGUI_CAT_MATV_CONTENT_H, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};

const U8 CAT1011[] = 
{
#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
	6,
#else /*GUI_SUBMENU_SHOW_STATUS_ICON*/
    5,
#endif /*GUI_SUBMENU_SHOW_STATUS_ICON*/
	DM_BASE_LAYER_START,
	DM_SCR_BG,
#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
	DM_STATUS_BAR1,
#endif /*GUI_SUBMENU_SHOW_STATUS_ICON*/
	DM_TITLE1,
	DM_DYNAMIC_LIST1,
	DM_BUTTON_BAR1
};

const U16 coordinate_set1011[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
    DM_DEFAULT_STATUS_BAR_FLAG,
#endif /*GUI_SUBMENU_SHOW_STATUS_ICON*/
    WGUI_CAT_MATV_TITLE_X, WGUI_CAT_MATV_TITLE_Y, WGUI_CAT_MATV_TITLE_W, WGUI_CAT_MATV_TITLE_H, DM_NO_FLAGS,
	WGUI_CAT_MATV_CONTENT_X, WGUI_CAT_MATV_CONTENT_Y, WGUI_CAT_MATV_CONTENT_W, WGUI_CAT_MATV_CONTENT_H, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};


const U8 CAT1013[] = 
{
#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
    6,
#else /*GUI_SUBMENU_SHOW_STATUS_ICON*/
	5,
#endif /*GUI_SUBMENU_SHOW_STATUS_ICON*/
    DM_BASE_LAYER_START,
    DM_SCR_BG,
#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
	DM_STATUS_BAR1,
#endif /*GUI_SUBMENU_SHOW_STATUS_ICON*/
	DM_TITLE1,
    //DM_BASE_CONTROL_SET_SUBMENU,
    DM_MATRIX_MENU1,
	DM_BUTTON_BAR1
};

const S16 coordinate_set1013[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
    DM_DEFAULT_STATUS_BAR_FLAG,
#endif /*GUI_SUBMENU_SHOW_STATUS_ICON*/
    WGUI_CAT_MATV_TITLE_X, WGUI_CAT_MATV_TITLE_Y, WGUI_CAT_MATV_TITLE_W, WGUI_CAT_MATV_TITLE_H, DM_NO_FLAGS,
	WGUI_CAT_MATV_CONTENT_X, WGUI_CAT_MATV_CONTENT_Y, WGUI_CAT_MATV_CONTENT_W, WGUI_CAT_MATV_CONTENT_H, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /* __ATV_SMS_SUPPORT__ */

#ifdef __MMI_MOBILE_TV_CMMB_SUPPORT__
const U8 category_2003[] = 
{
    5,
    DM_SCR_BG,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_MULTILINE_INPUTBOX1,
    DM_SINGLELINE_INPUTBOX1,
};
const S16 coordinate_set2003[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    WGUI_CAT2003_ML_X, WGUI_CAT2003_ML_Y, WGUI_CAT2003_ML_W, WGUI_CAT2003_ML_H, DM_NO_FLAGS, /* DM_MULTILINE_INPUTBOX */
    WGUI_CAT2003_SL_X, WGUI_CAT2003_SL_Y, WGUI_CAT2003_SL_W, WGUI_CAT2003_SL_H, DM_NO_FLAGS /* DM_SINGLELINE_INPUTBOX */
};
#endif

#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)||defined(__MMI_MOT_SUPPORT__)||defined(__MMI_MRE_MSPACE__)
const U8 category_3006[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_MULTILINE_INPUTBOX1,
};
const S16 coordinate_set3006[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    0, WGUI_CAT3006_CONTROL_AREA_Y, MAIN_LCD_DEVICE_WIDTH, WGUI_CAT3006_CONTROL_AREA_H, DM_NO_FLAGS,
    0, WGUI_CAT3006_ML_Y, MAIN_LCD_DEVICE_WIDTH, WGUI_CAT3006_ML_H, DM_NO_FLAGS
};
#endif

#ifdef __MMI_OP02_LEMEI__
const U8 category9002_op02[] = 
{
    5,
    DM_NEW_LAYER_START,
    DM_IMAGE,
    DM_BASE_LAYER_START,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA
};

const S16 coordinate_set9002_op02[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_FULL_SCREEN_COORDINATE_FLAG,    
    DM_FULL_SCREEN_COORDINATE_FLAG,
    //MMI_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_NO_FLAGS,
    0, MMI_STATUS_BAR_HEIGHT, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT - MMI_BUTTON_BAR_HEIGHT - MMI_STATUS_BAR_HEIGHT, DM_NO_FLAGS,
};
#endif
#ifdef __MMI_MAINLCD_128X64__
const U8 category9014[] =
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set9014[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
	0, 0, 0, 0, DM_NO_FLAGS,
    DM_DEFAULT_BUTTON_BAR_FLAG,MMI_SOFTKEY_WIDTH
};
#endif


#ifdef __SOCIAL_NETWORK_SUPPORT__
const U8 cat1051[] = 
{
#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
    6,
#else /*GUI_SUBMENU_SHOW_STATUS_ICON*/
    5,
#endif /*GUI_SUBMENU_SHOW_STATUS_ICON*/
    DM_BASE_LAYER_START,
    DM_SCR_BG,
#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
    DM_STATUS_BAR1,
#endif /*GUI_SUBMENU_SHOW_STATUS_ICON*/
    DM_CATEGORY_CONTROLLED_AREA,
    //DM_BASE_CONTROL_SET_SUBMENU,
    DM_LIST1,
    DM_BUTTON_BAR1
};


const S16 coordinate_set1051[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
    DM_DEFAULT_STATUS_BAR_FLAG,
#endif /*GUI_SUBMENU_SHOW_STATUS_ICON*/
    MMI_CONTENT_X, MMI_STATUS_BAR_HEIGHT, MMI_CONTENT_WIDTH, 
    MMI_MULTIROW_MENUITEM_HEIGHT, DM_NO_FLAGS,
    0, 0, 0, 0, DM_CATEGORY_CONTROL_COORDINATES,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};


const U8 cat1052[] = 
{
#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
    6,
#else /*GUI_SUBMENU_SHOW_STATUS_ICON*/
    5,
#endif /*GUI_SUBMENU_SHOW_STATUS_ICON*/
    DM_BASE_LAYER_START,
    DM_SCR_BG,
#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
    DM_STATUS_BAR1,
#endif /*GUI_SUBMENU_SHOW_STATUS_ICON*/
    DM_CATEGORY_CONTROLLED_AREA,
    //DM_BASE_CONTROL_SET_SUBMENU,
    DM_ASYNCDYNAMIC_LIST1,
    DM_BUTTON_BAR1
};


const S16 coordinate_set1052[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
#ifdef GUI_SUBMENU_SHOW_STATUS_ICON
    DM_DEFAULT_STATUS_BAR_FLAG,
#endif /*GUI_SUBMENU_SHOW_STATUS_ICON*/
    MMI_CONTENT_X, MMI_STATUS_BAR_HEIGHT, MMI_CONTENT_WIDTH, 
    MMI_MULTIROW_MENUITEM_HEIGHT, DM_NO_FLAGS,
    0, 0, 0, 0, DM_CATEGORY_CONTROL_COORDINATES,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};


const U8 category57_sns[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_BASE_CONTROL_SET_COMMON,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_CATEGORY_CONTROLLED_AREA2,
    DM_INLINE_FIXED_LIST1
};
const S16 coordinate_set57_sns[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_TITLE_BAR_FLAG,
#ifndef __MMI_FTE_SUPPORT__    
    DM_COMMON_CONTENT_COORDINATE, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
#else    
    MMI_COMMON_CONTENT_X, MMI_COMMON_CONTENT_Y, MMI_COMMON_CONTENT_WIDTH, MMI_COMMON_CONTENT_HEIGHT, DM_CENTRE_ALIGN_X | DM_CENTER_ALIGN_Y
#endif
};

#endif /* __SOCIAL_NETWORK_SUPPORT__ */

/*for active call screen*/
#ifdef __MMI_MAINLCD_96X64__
const U8 category9023[] = 
{
    5,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_CATEGORY_CONTROLLED_AREA,
    DM_BUTTON_BAR1
};
const S16 coordinate_set9023[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DUMMY_COORDINATE,
    DM_DEFAULT_BUTTON_BAR_FLAG, MMI_SOFTKEY_WIDTH
};
#endif /*__MMI_MAINLCD_96X64__*/

#ifdef __MMI_WEARABLE_DEVICE__

const U8 category9100[] = 
{
    4,
    DM_BASE_LAYER_START,
    DM_SCR_BG,
    DM_STATUS_BAR1,
    DM_CATEGORY_CONTROLLED_AREA,
};

const S16 coordinate_set9100[] = 
{
    DM_FULL_SCREEN_COORDINATE_FLAG,
    DM_DEFAULT_STATUS_BAR_FLAG,
    DM_DUMMY_COORDINATE
};

#endif  //__MMI_WEARABLE_DEVICE__

const dm_category_id_control_set_map_struct g_categories_controls_map[] =
    /* The sequence of category id should be listed in ascending order */
{
    {MMI_CATEGORY5_ID, (U8 *) category5, (S16 *) coordinate_set5, NULL},
#if !defined(__MMI_BASIC_UI_STYLE__)		
    {MMI_CATEGORY6_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
#endif/*__MMI_BASIC_UI_STYLE__*/    
    {MMI_CATEGORY7_ID, (U8 *) category7, (S16 *) common_coordinate_set, NULL},
    {MMI_CATEGORY9_ID, (U8 *) category9, (S16 *) coordinate_set9, NULL},
    /* START VIJAY PMT 20050930 */
#if !defined(__MMI_BASIC_UI_STYLE__)
#ifdef __MMI_SMALL_LIST_SCREEN__
    {MMI_CATEGORY10_ID, (U8 *) category10, (S16 *) coordinate_set10},
#endif /* __MMI_SMALL_LIST_SCREEN__ */
#endif/*__MMI_BASIC_UI_STYLE__*/

    /* END VIJAY PMT 20050930 */
    {MMI_CATEGORY12_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY14_LIST_ID, (U8 *) category14_list, (S16 *) coordinate_set14_List_Page, NULL},
    {MMI_CATEGORY14_MATRIX_ID, (U8 *) category14_matrix, (S16 *) coordinate_set14_Matrix, NULL},
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if defined(__MMI_SCREEN_ROTATE__)
    {MMI_CATEGORY15_LIST_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, (S16 *) common_rotated_coordinate_set},
#else /* defined(__MMI_SCREEN_ROTATE__) */ 
    {MMI_CATEGORY15_LIST_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
#endif /* defined(__MMI_SCREEN_ROTATE__) */
//    {MMI_CATEGORY15_MATRIX_ID, (U8 *) category15_matrix, (S16 *) common_coordinate_set, NULL},
    {MMI_CATEGORY16_ID, (U8 *) category16, (S16 *) coordinate_set16, NULL},
    {MMI_CATEGORY18_ID, (U8 *) category18, (S16 *) coordinate_set18, NULL},
    {MMI_CATEGORY19_ID, (U8 *) category19, (S16 *) coordinate_set19, NULL},
    {MMI_CATEGORY20_ID, (U8 *) category20, (S16 *) coordinate_set20, NULL},
    {MMI_CATEGORY21_ID, (U8 *) category21, (S16 *) common_coordinate_set, NULL},
    {MMI_CATEGORY22_ID, (U8 *) category22, (S16 *) coordinate_set22, NULL},
#ifdef UI_EMS_SUPPORT
    {MMI_CATEGORY28_ID, (U8 *) category28, (S16 *) coordinate_set5, NULL},
#endif /* UI_EMS_SUPPORT */
    {MMI_CATEGORY30_ID, (U8 *) category30, (S16 *) coordinate_set30, NULL},
#if defined(__MMI_UCM_MO_FAIL_POST_ACTION__) || defined(__J2ME__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)   
	{MMI_CATEGORY32_ID, (U8 *) category32, (S16 *) coordinate_set32, NULL},
#endif/*defined(__MMI_UCM_MO_FAIL_POST_ACTION__) || defined(__J2ME__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__) */
    {MMI_CATEGORY33_ID, (U8 *) category33, (S16 *) coordinate_set33, NULL},
#ifdef __MMI_AVATAR__
    {MMI_CATEGORY34_ID, (U8 *) category34, (S16 *) coordinate_set34, NULL},
#endif
#if 0
/* under construction !*/
#endif

#if defined(__MMI_SCREEN_ROTATE__)
#if defined(__FMGR_USE_SELF_MENU__) || defined(WIDGET_CTK_MSF_MENU)|| !defined(__MMI_BASIC_UI_STYLE__)
    {MMI_CATEGORY36_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set,
     (S16 *) common_rotated_coordinate_set},
#endif/*defined(__FMGR_USE_SELF_MENU__) || defined(WIDGET_CTK_MSF_MENU)|| !defined(__MMI_BASIC_UI_STYLE__) */     
#ifdef UI_EMS_SUPPORT
#if !defined(__MMI_MAINLCD_128X64__)
    {MMI_CATEGORY39_ID, (U8 *) category39, (S16 *) coordinate_set39, (S16 *) coordinate_set39},
#else
    {MMI_CATEGORY39_ID, (U8 *) category39, (S16 *) common_coordinate_set, (S16 *) coordinate_set39},
#endif
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
    {MMI_CATEGORY39_ID_SLIDE_CONTROL, (U8 *) category39_slide_control, (S16 *) coordinate_set39_slide_control, (S16 *) coordinate_set39_slide_control}, 
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    {MMI_CATEGORY39_ID_ICON_BAR, (U8 *) category39, (S16 *) coordinate_set39_iconbar, NULL},
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
    {MMI_CATEGORY39_ID_ICON_BAR_SLIDE_CONTROL, (U8 *) category39_slide_control, (S16 *) coordinate_set39_iconbar_slide_control, NULL},
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */
#endif
#endif /* UI_EMS_SUPPORT */
    {MMI_CATEGORY52_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set,
     (S16 *) common_rotated_coordinate_set},
#else /* defined(__MMI_SCREEN_ROTATE__) */ 
#if defined(__FMGR_USE_SELF_MENU__) || defined(WIDGET_CTK_MSF_MENU)|| !defined(__MMI_BASIC_UI_STYLE__)
    {MMI_CATEGORY36_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
#endif/*defined(__FMGR_USE_SELF_MENU__) || defined(WIDGET_CTK_MSF_MENU)|| !defined(__MMI_BASIC_UI_STYLE__)*/

#ifdef UI_EMS_SUPPORT
#if !defined(__MMI_MAINLCD_128X64__)
    {MMI_CATEGORY39_ID, (U8 *) category39, (S16 *) coordinate_set39, NULL},
#else
    {MMI_CATEGORY39_ID, (U8 *) category39, (S16 *) common_coordinate_set, (S16 *) common_coordinate_set},
#endif
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
    {MMI_CATEGORY39_ID_SLIDE_CONTROL, (U8 *) category39_slide_control, (S16 *) coordinate_set39_slide_control, NULL},  
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */
#ifdef __MMI_FTE_SUPPORT__
    {MMI_CATEGORY39_ID_ICON_BAR, (U8 *) category39, (S16 *) coordinate_set39_iconbar, NULL},
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
    {MMI_CATEGORY39_ID_ICON_BAR_SLIDE_CONTROL, (U8 *) category39_slide_control, (S16 *) coordinate_set39_iconbar_slide_control, NULL},
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */
#endif
#endif /* UI_EMS_SUPPORT */
    {MMI_CATEGORY52_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 

#if defined(__MMI_SCREEN_ROTATE__)
    {MMI_CATEGORY57_ID, (U8 *) category57, (S16 *) coordinate_set57, (S16 *)rotated_coordinate_set57},
#else 
    {MMI_CATEGORY57_ID, (U8 *) category57, (S16 *) coordinate_set57, NULL},
#endif
    {MMI_CATEGORY61_ID, (U8 *) category61, (S16 *) coordinate_set61, NULL},
 #if defined(__MMI_SCREEN_ROTATE__)
    {MMI_CATEGORY63_ID, (U8 *) category63, (S16 *) coordinate_set63, (S16 *) rotated_coordinate_set63},
    {MMI_CATEGORY66_ID, (U8 *) category66, (S16 *) coordinate_set66,
     (S16 *) rotated_coordinate_set66},
#if (defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_FTE_SUPPORT__))
        {MMI_CATEGORY66_N0_SOFTKEY_ID, (U8 *) category66_no_softkey, (S16 *) coordinate_set66_no_softkey,
     (S16 *) rotated_coordinate_set66_no_softkey},
#endif
 #else /* defined(__MMI_SCREEN_ROTATE__) */ 
    {MMI_CATEGORY63_ID, (U8 *) category63, (S16 *) coordinate_set63, NULL},
    {MMI_CATEGORY66_ID, (U8 *) category66, (S16 *) coordinate_set66, NULL},
#if (defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_FTE_SUPPORT__))
    {MMI_CATEGORY66_N0_SOFTKEY_ID, (U8 *) category66_no_softkey, (S16 *) coordinate_set66_no_softkey, NULL},
#endif
 #endif /* defined(__MMI_SCREEN_ROTATE__) */ 
    {MMI_CATEGORY69_ID, (U8 *) category69, (S16 *) coordinate_set69, NULL},
#ifdef __MMI_SEARCH_WEB__
    {MMI_CAT2001_ID, (U8 *) category2001, (S16 *) coordinate_set2001, NULL},
#endif /* __MMI_SEARCH_WEB__  */
#if defined(__MMI_MENSTRUAL__) || defined(__MMI_139_PUSH_MAIL__)
    {MMI_CATEGORY72_ID, (U8 *) category_control_category_normal_bg, (S16 *) category_controlled_coordinate_set, NULL},
#endif
#if !defined(__MMI_BASIC_UI_STYLE__) && !defined(__MMI_MAINLCD_128X64__) 
	{MMI_CATEGORY73_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
#endif/*!defined(__MMI_BASIC_UI_STYLE__) && !defined(__MMI_MAINLCD_128X64__)*/	
 #if defined(__MMI_SCREEN_ROTATE__)
    {MMI_CATEGORY74_ID, (U8 *) category74, (S16 *) coordinate_set74, (S16 *) common_rotated_coordinate_set},
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
    {MMI_CATEGORY74_ID_SLIDE_CONTROL, (U8 *) category74_slide_control, (S16 *) coordinate_set74_slide_control, (S16 *) common_rotated_coordinate_set},
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */
#if defined(__MMI_EBOOK_READER__)
    {MMI_CATEGORY75_ID, (U8 *) category75, (S16 *) coordinate_set75, (S16 *) NULL},
#endif
#if defined(OBIGO_Q03C_MMS_V01)||defined(__MMI_CSB_BROWSER__)
    {MMI_CATEGORY76_ID, (U8 *) category74, (S16 *) coordinate_set74, (S16 *) common_rotated_coordinate_set},
#endif

#if defined(__MMI_EBOOK_READER__)
    {MMI_CATEGORY77_ID, (U8 *) category77, (S16 *) coordinate_set77, NULL},
#endif

    {MMI_CATEGORY78_ID, (U8 *) category74, (S16 *) coordinate_set74, (S16 *) common_rotated_coordinate_set},
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
    {MMI_CATEGORY78_ID_SLIDE_CONTROL, (U8 *) category74_slide_control, (S16 *) coordinate_set74_slide_control, (S16 *) common_rotated_coordinate_set},
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */
#else /* defined(__MMI_SCREEN_ROTATE__) */ 
    {MMI_CATEGORY74_ID, (U8 *) category74, (S16 *) coordinate_set74, NULL},
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
    {MMI_CATEGORY74_ID_SLIDE_CONTROL, (U8 *) category74_slide_control, (S16 *) coordinate_set74_slide_control, NULL},
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */

#if defined(__MMI_EBOOK_READER__)
    {MMI_CATEGORY75_ID, (U8 *) category75, (S16 *) coordinate_set75, NULL},
#endif

#if defined(OBIGO_Q03C_MMS_V01)||defined(__MMI_CSB_BROWSER__)
    {MMI_CATEGORY76_ID, (U8 *) category74, (S16 *) coordinate_set74, NULL},
#endif

#if defined(__MMI_EBOOK_READER__)
    {MMI_CATEGORY77_ID, (U8 *) category77, (S16 *) coordinate_set77, NULL},
#endif

    {MMI_CATEGORY78_ID, (U8 *) category74, (S16 *) coordinate_set74, NULL},
#ifdef __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__
    {MMI_CATEGORY78_ID_SLIDE_CONTROL, (U8 *) category74_slide_control, (S16 *) coordinate_set74_slide_control, NULL},
#endif /* __WGUI_CAT_SLIDE_CONTROLS_SUPPORT__ */
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 
    {MMI_CATEGORY83_ID, (U8 *) category83, (S16 *) coordinate_set83, NULL},//072406 new calendar
    {MMI_CATEGORY84_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY85_ID, (U8 *) category85, (S16 *) coordinate_set85, NULL},//072406 new calendar
    {MMI_CATEGORY85_NO_BUTTON_ID, (U8 *) category85_no_button, (S16 *)list_coordinate_set, NULL},//072406 new calendar
#if (defined(__MMI_ANALOG_CLOCK__) || defined(__MMI_DIGITAL_CLOCK__))
    {MMI_CATEGORY86_ID, (U8 *) category86, (S16 *) coordinate_set86, NULL},
#endif
    {MMI_CATEGORY88_1ITEM_ID, (U8 *) category88, (S16 *) coordinate_set88_1_item, NULL},
    {MMI_CATEGORY88_2ITEM_ID, (U8 *) category88, (S16 *) coordinate_set88_2_item, NULL},
    {MMI_CATEGORY88_3ITEM_ID, (U8 *) category88, (S16 *) coordinate_set88_3_item, NULL},
#if !defined(__MMI_BASIC_UI_STYLE__)
	{MMI_CATEGORY89_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
#endif/*!defined(__MMI_BASIC_UI_STYLE__)*/	
#ifdef __MMI_PICTURE_EDITOR_SUPPORT__
    {MMI_CATEGORY91_ID, (U8 *) category91, (S16 *) coordinate_set91, NULL},
#endif
#if defined(__MMI_HIDD_SUPPORT__)
    {MMI_CATEGORY95_ID, (U8 *) category95, (S16 *) coordinate_set95, NULL},
#endif
    /* START VIJAY PMT 20050930 */
 #ifdef __MMI_SMALL_EDIT_SCREEN__
    {MMI_CATEGORY100_ID, (U8 *) category100, (S16 *) coordinate_set100},
 #endif 
 #ifdef __MMI_CAT103_SUPPORT__
    {MMI_CATEGORY103_ID, (U8 *) category103, (S16 *) coordinate_set103, NULL},
 #endif
    /* END VIJAY PMT 20050930 */
#ifdef __PLUTO_MMI_PACKAGE__
    {MMI_CATEGORY105_ID, (U8 *) category105, (S16 *) coordinate_set105, NULL},
#endif /* __PLUTO_MMI_PACKAGE__ */
    {MMI_CATEGORY109_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
#if defined(__MMI_EVENT_LIST__)    
    {MMI_CATEGORY110_ID, (U8 *) category110, (S16 *) coordinate_set110, NULL},
#endif/*#ifdef __MMI_EVENT_LIST__*/    
    {MMI_CATEGORY111_ID, (U8 *) category111, (S16 *) coordinate_set111, NULL},
    /* START VIJAY PMT 20050930 */
 #ifdef __MMI_SMALL_PIN_EDIT_SCREEN__
    {MMI_CATEGORY112_ID, (U8 *) category112, (S16 *) coordinate_set112},
 #endif 
    {MMI_CATEGORY113_ID, (U8 *) category113, (S16 *) coordinate_set113, NULL},
 #ifdef __MMI_CAT116_SUPPORT__
    {MMI_CATEGORY116_ID, (U8 *) category116, (S16 *) coordinate_set116, NULL},
 #endif
#ifdef __MMI_BMI__
    {MMI_CATEGORY122_ID, (U8 *) category122, (S16 *) coordinate_set122, NULL},
#endif
    {MMI_CATEGORY123_ID, (U8 *) category123, (S16 *) coordinate_set123, NULL},
#ifdef __MMI_ECOMPASS__
    {MMI_CATEGORY126_ID, (U8 *) category126, (S16 *) coordinate_set126, NULL},
#endif
#if (defined(__MMI_ANALOG_CLOCK__) || defined(__MMI_DIGITAL_CLOCK__))
    {MMI_CATEGORY128_ID, (U8 *) category128, (S16 *) coordinate_set128, NULL},
#endif
    {MMI_CATEGORY129_ID, (U8 *) category129, (S16 *) coordinate_set129, NULL},
	{MMI_CATEGORY129_NO_BUTTON_ID, (U8 *) category129_no_button, (S16 *) coordinate_set129_no_button, NULL},
    {MMI_CATEGORY130_ID, (U8 *) category130, (S16 *) coordinate_set130, NULL},
#ifdef __MMI_SCREEN_SAVER__
    {MMI_CATEGORY131_ID, (U8 *) category131, (S16 *) coordinate_set131, NULL},
#endif
    {MMI_CATEGORY132_ID, (U8 *) category132, (S16 *) coordinate_set132, NULL},
    {MMI_CATEGORY132_FULLSCREEN_ID, (U8 *) category132_fullscreen, (S16 *) coordinate_set132_fullscreen, NULL},
#if defined(__MMI_SCREEN_ROTATE__)
    {MMI_CATEGORY132_ROTATE_ID, (U8 *) category132_rotate, NULL, (S16 *) coordinate_set132_rotate},
#endif /* defined(__MMI_SCREEN_ROTATE__) */
#if defined(__MMI_SCREEN_ROTATE__)
    {MMI_CATEGORY140_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, (S16 *)common_rotated_coordinate_set},
#else
    {MMI_CATEGORY140_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
#endif
#ifndef __MMI_MAINLCD_96X64__
    {MMI_CATEGORY141_ID, (U8 *) category141_normal, (S16 *) coordinate_set141, NULL},
#endif
    {MMI_CATEGORY141_STATUS_ICON_ID, (U8 *) category141_status_icon, (S16 *) coordinate_set141_status_icon, NULL},
    {MMI_CATEGORY142_ID, (U8 *) category_control_category_normal, (S16 *) common_coordinate_set, NULL},
    {MMI_CATEGORY142_STATUS_ICON_ID, (U8 *) category_control_category_status_icon,
     (S16 *) category_control_coordinate_set_status_icon, NULL},
    {MMI_CATEGORY143_ID, (U8 *) category143, (S16 *) coordinate_set143, NULL},
    {MMI_CATEGORY144_ID, (U8 *) category_control_category_normal_bg, (S16 *) category_controlled_coordinate_set},
    
#if defined(__MMI_BT_DIALER_SUPPORT__)     
    {MMI_CATEGORY145_ID, (U8 *) category_control_category_normal_bg, (S16 *) category_controlled_coordinate_set, NULL},
#else
	{MMI_CATEGORY145_ID, (U8 *) category_control_category_normal, (S16 *) category_controlled_coordinate_set, NULL},
#endif

 #ifdef __MMI_SMALL_IMAGE_SELECTOR_SCREEN__
    {MMI_CATEGORY146_ID, (U8 *) category146, (S16 *) coordinate_set146},
 #endif 
#if defined(__MMI_GAME__) 
    {MMI_CATEGORY150_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
#endif/*defined(__MMI_GAME__) */
    {MMI_CATEGORY151_ID, (U8 *) category151, (S16 *) coordinate_set151, NULL},
//#if defined(__COSMOS_MMI_PACKAGE__)     
    {MMI_CATEGORY152_ID, (U8 *) category152, (S16 *) coordinate_set152, NULL},
//#endif
    {MMI_CATEGORY154_ID, (U8 *) category154_normal, (S16 *) coordinate_set154_normal, NULL},
    {MMI_CATEGORY154_STATUS_ICON_ID, (U8 *) category154_status_icon, (S16 *) coordinate_set154_status_icon, NULL},
    {MMI_CATEGORY157_ID, (U8 *) category157, (S16 *) coordinate_set157, NULL},
 #if defined(__MMI_SCREEN_ROTATE__)
    {MMI_CATEGORY165_ID, (U8 *) category165, (S16 *) coordinate_set165, (S16 *) rotated_coordinate_set165},
 #else 
    {MMI_CATEGORY165_ID, (U8 *) category165, (S16 *) coordinate_set165, NULL},
 #endif 
    {MMI_CATEGORY166_ID, (U8 *) category166, (S16 *) coordinate_set166, NULL},
    {MMI_CATEGORY170_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY171_ID, (U8 *) category171, (S16 *) coordinate_set171, NULL},
#if !defined(__MMI_BASIC_UI_STYLE__)  
    {MMI_CATEGORY172_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
#endif/*!defined(__MMI_BASIC_UI_STYLE__)  */    
    {MMI_CATEGORY174_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
#if defined(__MMI_OP01_DCD__)
    {MMI_CATEGORY182_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
#endif
    {MMI_CATEGORY184_ID, (U8 *) dynamic_list_menu_category, (S16 *) list_coordinate_set, NULL},
#if defined(__CERTMAN_SUPPORT__)    
    {MMI_CATEGORY186_ID, (U8 *) dynamic_list_menu_category, (S16 *) list_coordinate_set, NULL},
#endif/*defined(__CERTMAN_SUPPORT__)*/    

#if defined(__MMI_PHB_QUICK_SEARCH__) 
    {MMI_CATEGORY199_ID, (U8 *) category199, (S16 *) coordinate_set199, NULL},
    {MMI_CATEGORY199_SCROLLTEXT_ID, (U8 *) category199_scrolltext, (S16 *) coordinate_set199_scrolltext, NULL},    
#endif	

#if defined(__MMI_CSB_BROWSER__)||(defined(__MMI_DICTIONARY_SMALL_SCREEN__)&&defined(__MMI_DICTIONARY__))||defined(__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__)||defined(__MMI_PHB_QUICK_SEARCH__) 
    {MMI_CATEGORY200_ID, (U8 *) category200, (S16 *) coordinate_set200, NULL},
#endif

#if defined(__MMI_CSB_BROWSER__)||(!defined(__MMI_DICTIONARY_SMALL_SCREEN__)&&defined(__MMI_DICTIONARY__))||defined(__MMI_MEDIA_PLAYER_PLST_DB_ENHANCE__)
    {MMI_CATEGORY201_ID, (U8 *) category201, (S16 *) coordinate_set201, NULL},
#endif

#if defined(__MMI_CSB_BROWSER__)||defined(__MMI_PHB_GENERIC_MULTI_SELECT__)||defined(__MMI_PHB_MULTI_OPERATION__)
    {MMI_CATEGORY202_ID, (U8 *) category202, (S16 *) coordinate_set202, NULL},
    {MMI_CATEGORY202_NOINFO_ID, (U8 *) category202_noinfo, (S16 *) coordinate_set202_noinfo, NULL},
#endif
#ifdef __MMI_CAT203_SUPPORT__
    {MMI_CATEGORY203_ID, (U8 *) category203, (S16 *) coordinate_set203, NULL},
#endif /* __MMI_CAT203_SUPPORT__ */
#ifdef __MMI_ENGINEER_MODE__
    {MMI_CATEGORY204_ID, (U8 *) category204, (S16 *) coordinate_set204, NULL},
#endif
    {MMI_CATEGORY205_ID, (U8 *) category205, (S16 *) coordinate_set205, NULL},
//    {MMI_CATEGORY210_ID, (U8 *) category210, (S16 *) coordinate_set210, NULL},
#ifndef __MMI_SLIM_FILE_MANAGER__
    {MMI_CATEGORY211_ID, (U8 *) category211, (S16 *) coordinate_set211, NULL},
    {MMI_CATEGORY212_ID, (U8 *) category212, (S16 *) coordinate_set212, NULL},
#if defined(__MMI_SCREEN_ROTATE__)
    {MMI_CATEGORY213_ID, (U8 *) category213, (S16 *) coordinate_set213, (S16 *) rotated_coordinate_set213},
#else
    {MMI_CATEGORY213_ID, (U8 *) category213, (S16 *) coordinate_set213, NULL},
 #endif 
    {MMI_CATEGORY214_ID, (U8 *) category214, (S16 *) common_coordinate_set, NULL},
#ifdef __MMI_CAT_SUPPORT_ASYNC_FMGR__
    {MMI_CATEGORY216_ID, (U8 *) category216, (S16 *) coordinate_set216, NULL},
    {MMI_CATEGORY216_INFO_ID, (U8 *) category216_info, (S16 *) coordinate_set216_info, NULL},
    {MMI_CATEGORY217_ID, (U8 *) category217, (S16 *) coordinate_set217, NULL},
    {MMI_CATEGORY218_ID, (U8 *) category218, (S16 *) coordinate_set218, NULL},
    {MMI_CATEGORY218_INFO_ID, (U8 *) category218_info, (S16 *) coordinate_set218_info, NULL},
    {MMI_CATEGORY218_TAB_ID, (U8 *) category218_tab, (S16 *) coordinate_set218_tab, NULL},
    {MMI_CATEGORY218_INFO_TAB_ID, (U8 *) category218_info_tab, (S16 *) coordinate_set218_info_tab, NULL},
#endif
#endif /*__MMI_SLIM_FILE_MANAGER__*/
#ifdef __MMI_CAT_SUPPORT_ASYNC_FMGR__
    {MMI_CATEGORY219_ID, (U8 *) category219, (S16 *) common_coordinate_set, NULL},
#endif /* __MMI_CAT_SUPPORT_ASYNC_FMGR__ */
 #if defined(__MMI_SCREEN_ROTATE__)
    {MMI_CATEGORY221_ID, (U8 *) category221, (S16 *) coordinate_set221, (S16 *) rotated_coordinate_set221},
 #else 
    {MMI_CATEGORY221_ID, (U8 *) category221, (S16 *) coordinate_set221, NULL},
 #endif 
#if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
    {MMI_CATEGORY222_ID, (U8 *) category222, (S16 *) coordinate_set222, NULL},
#else /* MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24 */
    {MMI_CATEGORY222_ID, (U8 *) category222, (S16 *) common_coordinate_set, NULL},
#endif /* MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24 */
    {MMI_CATEGORY223_ID, (U8 *) category223, (S16 *) coordinate_set223, NULL},
#if 0         
 #if defined ( __MMI_SCREEN_ROTATE__)
/* under construction !*/
/* under construction !*/
 #else /* defined ( __MMI_SCREEN_ROTATE__) */ 
/* under construction !*/
/* under construction !*/
 #endif /* defined ( __MMI_SCREEN_ROTATE__) */ 
#endif 
    {MMI_CATEGORY227_ID, (U8 *) category227Screen, (S16 *) coordinate_set227, NULL},
    {MMI_CATEGORY228_ID, (U8 *) category74, (S16 *) coordinate_set74, NULL},
#if 0
/* under construction !*/
#endif
#if defined ( __MMI_MAINLCD_240X320__) || defined ( __MMI_MAINLCD_240X240__) || defined ( __MMI_MAINLCD_320X240__) || defined ( __MMI_MAINLCD_240X400__) || defined ( __MMI_MAINLCD_320X480__) || defined ( __MMI_MAINLCD_360X640__) 
    {MMI_CATEGORY230_ID, (U8 *) category230Screen, (S16 *) coordinate_set230, NULL},//052206 NITZ category Calvin
 #endif
 
#if defined ( __MMI_MAINLCD_128X128__) || defined ( __MMI_MAINLCD_128X160__) ||  defined (__MMI_MAINLCD_176X220__)
    {MMI_CATEGORY231_ID, (U8 *) category231Screen, (S16 *) coordinate_set231, NULL},
    {MMI_CATEGORY232_ID, (U8 *) category232Screen, (S16 *) coordinate_set232, NULL},
#endif

#if defined(__MMI_CURRENCY_CONVERTER__)||defined(__MMI_CSB_BROWSER__)||defined(__MMI_PHB_BIRTHDAY_FIELD__)
    {MMI_CATEGORY257_ID, (U8 *) category257, (S16 *) coordinate_set257, NULL},
#endif
#if defined(__MMI_EMAIL__)    

    {MMI_CATEGORY261_ID, (U8 *) asyncdynamic_list_menu_category, (S16 *) list_coordinate_set, NULL},
#endif/*defined(__MMI_EMAIL__)*/  
#if defined(__MMI_MMS_2__) || defined(__WAP_PUSH_SUPPORT__)
    {MMI_CATEGORY262_ID, (U8 *) asyncdynamic_list_menu_category, (S16 *) list_coordinate_set, NULL},
#endif/*#if defined(__MMI_MMS_2__) || defined(__WAP_PUSH_SUPPORT__)*/    
    {MMI_CATEGORY263_ID, (U8 *) category263, (S16 *) coordinate_set263, NULL},
    {MMI_CAT263_TAB_ID, (U8 *) cat263_tab, (S16 *) Coordinate_Set263_tab, NULL},
//    {MMI_CATEGORY264_ID, (U8 *) category264, (S16 *) coordinate_set264, NULL},
#ifdef __MMI_CAT265_SUPPORT__//051507 channel list
    {MMI_CATEGORY265_ID, (U8 *) category265, (S16 *) coordinate_set265, NULL},
    {MMI_CAT1007_ID, (U8 *)asyncdynamic_list_menu_category, (S16 *)list_coordinate_set, NULL},
#endif
#ifdef __MMI_MOBILE_TV_CMMB_SUPPORT__
    {MMI_CAT1008_ID, (U8 *)CAT1008, (S16 *)Coordinate_set1008, NULL},
    {MMI_CAT1009_ID, (U8 *) Cat1009, (S16 *) Coordinate_Set1009, NULL},
    {MMI_CAT1023_ID, (U8 *)CAT1023, (S16 *)Coordinate_set1023, NULL},
    {MMI_CAT1048_ID, (U8 *) cat1048, (S16 *) Coordinate_set1048, NULL},
    {MMI_CAT1050_ID, (U8 *) asyncdynamic_list_menu_category, (S16 *)list_coordinate_set, NULL},
#endif /*__MMI_MOBILE_TV_CMMB_SUPPORT__*/
#if defined(__MMI_EMAIL__) || defined(__UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__)
    {MMI_CATEGORY267_ID, (U8 *) category267, (S16 *) coordinate_set267, NULL},
    {MMI_CAT267_TAB_ID, (U8 *) cat267_tab, (S16 *) Coordinate_Set267_tab, NULL},
#endif/*defined(__MMI_EMAIL__) || defined(__UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__)*/    
#if __MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE__ == __UM_LIST_INLINE__
	{MMI_CATEGORY268_ID, (U8 *) asyncdynamic_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CAT268_TAB_ID, (U8 *) Cat268_tab, (S16 *) Coordinate_Set268_tab, NULL},
#endif/*__MMI_UNIFIED_MESSAGE_FOLDER_LIST_STYLE__ == __UM_LIST_INLINE__*/    
 #if defined(__MMI_UI_TWO_LINE_MENUITEM_STYLES__)
    {MMI_CATEGORY273_ID, (U8 *) dynamic_list_menu_category, (S16 *) list_coordinate_set, NULL},
 #endif 
    {MMI_CATEGORY275_ID, (U8 *) category275, (S16 *) coordinate_set275, NULL},
    {MMI_CATEGORY276_ID, (U8 *) category276, (S16 *) coordinate_set276, NULL},
	{MMI_CATEGORY280_ID, (U8 *) category280, (S16 *) coordinate_set280, NULL},
 #ifdef __MMI_SUBLCD__
    {MMI_CATEGORY301_ID, (U8 *) category301, (S16 *) coordinate_set301, NULL},
    {MMI_CATEGORY303_ID, (U8 *) category303, (S16 *) coordinate_set303, NULL},
    {MMI_CATEGORY304_ID, (U8 *) category304, (S16 *) coordinate_set304, NULL},
 #endif /* __MMI_SUBLCD__ */ 
    {MMI_CATEGORY306_ID, (U8 *) category306, (S16 *) coordinate_set306, NULL},
    {MMI_CATEGORY307_ID, (U8 *) category307, (S16 *) coordinate_set307, NULL},
 #ifdef __MMI_SUBLCD__
    {MMI_CATEGORY310_ID, (U8 *) category310, (S16 *) coordinate_set310, NULL},
    {MMI_CATEGORY311_ID, (U8 *) category311, (S16 *) coordinate_set311, NULL},
    {MMI_CATEGORY312_ID, (U8 *) category312, (S16 *) coordinate_set312, NULL},
    {MMI_CATEGORY313_ID, (U8 *) category313, (S16 *) coordinate_set313, NULL},
    {MMI_CATEGORY314_ID, (U8 *) category314, (S16 *) coordinate_set314, NULL},
    {MMI_CATEGORY315_ID, (U8 *) category315, (S16 *) coordinate_set315, NULL},
 #endif /* __MMI_SUBLCD__ */
#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
    {MMI_CATEGORY334_ID, (U8 *) category334, (S16 *) coordinate_set334, NULL},
#endif /* __MMI_EDITABLE_AUDIO_EQUALIZER__ */
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    {MMI_CATEGORY357_ID, (U8 *) category357, (S16 *) coordinate_set357, NULL},
#endif

#ifdef __MMI_DUAL_SIM_MASTER__
#if defined(__MMI_SCREEN_ROTATE__)
/* under construction !*/
#else /* __MMI_SCREEN_ROTATE__ */
/* under construction !*/
#endif /* __MMI_SCREEN_ROTATE__ */
#endif   /* __MMI_DUAL_SIM_MASTER__ */  
#if defined(__SYNCML_SUPPORT__)
    {MMI_CATEGORY366_ID, (U8 *) category366, (S16 *) coordinate_set366, NULL},
#endif/*#ifdef __SYNCML_SUPPORT__*/    
#if defined(__MMI_EBOOK_READER__)
    {MMI_CATEGORY375_ID, (U8 *) category375, (S16 *) coordinate_set375, NULL},
    {MMI_CATEGORY375_ID_FULLSCREEN, (U8 *) category375_fullscreen, (S16 *) coordinate_set375_fullscreen, NULL},
#endif
#if defined(__MMI_FTC_MULTIPULL_SUPPORT__) || (defined(__MMI_MEDIA_PLAYER__) && defined(__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__))||defined(__MMI_MEDIA_PLAYER_PLST_DB_STYLE__)    

    {MMI_CATEGORY384_ID, (U8 *) category384, (S16 *) coordinate_set384, NULL},
#endif/*#if defined(__MMI_FTC_MULTIPULL_SUPPORT__) || (defined(__MMI_MEDIA_PLAYER__) && defined(__MMI_MEDIA_PLAYER_PLST_DB_VF_STYLE__))||defined(__MMI_MEDIA_PLAYER_PLST_DB_STYLE__)*/    
    {MMI_CATEGORY402_ID, (U8 *) category402, (S16 *) coordinate_set402, NULL},
#ifndef __MMI_UCM_PLUTO_BW__
    {MMI_CATEGORY403_ID, (U8 *) category403, (S16 *) coordinate_set403, NULL},
#endif
    {MMI_CATEGORY404_ID, (U8 *) category404, (S16 *) coordinate_set404, NULL},
    {MMI_CATEGORY407_ID, (U8 *) category_control_category_normal_bg, (S16 *) common_coordinate_set, NULL},
//    {MMI_CATEGORY408_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
#if defined(__MMI_SCREEN_ROTATE__)
        {MMI_CATEGORY409_ID, (U8 *) category409, (S16 *) coordinate_set409, (S16 *) rotated_coordinate_set409},
#else /* defined(__MMI_SCREEN_ROTATE__) */ 
        {MMI_CATEGORY409_ID, (U8 *) category409, (S16 *) coordinate_set409, NULL},
#endif /* defined(__MMI_SCREEN_ROTATE__) */ 
//    {MMI_CATEGORY410_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
#if defined(__MMI_SCREEN_ROTATE__)
    {MMI_CATEGORY412_ID, (U8 *) category412, (S16 *) coordinate_set412, (S16 *) rotated_coordinate_set412},
#else /* defined(__MMI_SCREEN_ROTATE__) */
    {MMI_CATEGORY412_ID, (U8 *) category412, (S16 *) coordinate_set412, NULL},
#endif /* defined(__MMI_SCREEN_ROTATE__) */

#if defined(__MMI_BARCODEREADER_LOW_LEVEL)
    {MMI_CATEGORY415_ID, (U8 *) category415Screen, (S16 *) coordinate_set415, NULL},
#endif
    {MMI_CATEGORY420_ID, (U8 *) category420, (S16 *) coordinate_set420, NULL},
    {MMI_CATEGORY425_ID, (U8 *) category425, (S16 *) coordinate_set425, NULL},
    {MMI_CATEGORY425_NO_TAB_ID, (U8 *) category425_no_tab, (S16 *) coordinate_set425_no_tab, NULL},
#if defined(__BIP_PULL_SUPPORT__)    
#ifndef __MMI_MAINLCD_128X128__
    {MMI_CATEGORY426_ID, (U8 *) category426, (S16 *) coordinate_set426, NULL},
#endif
#endif/*#if defined(__BIP_PULL_SUPPORT__)*/
    {MMI_CATEGORY427_ID, (U8 *) asyncdynamic_list_menu_category, (S16 *) list_coordinate_set, NULL},
    {MMI_CATEGORY428_ID, (U8 *) category428, (S16 *) coordinate_set428, NULL},
    {MMI_CATEGORY428_NO_TAB_ID, (U8 *) category428_no_tab, (S16 *) coordinate_set428_no_tab, NULL},
    {MMI_CATEGORY429_ID, (U8 *) category429, (S16 *) coordinate_set429, NULL},
    {MMI_CATEGORY430_ID, (U8 *) category430, (S16 *) coordinate_set430, NULL},
#if defined(__MMI_BROWSER_2__) || defined(__MMI_GADGET_SUPPORT__)
    {MMI_CATEGORY431_ID, (U8 *) category431, (S16 *) coordinate_set431, NULL},
    {MMI_CATEGORY431_FULL_ID, (U8 *) category431_fullscreen, (S16 *) coordinate_set431_fullscreen, NULL},
#if defined(__MMI_SCREEN_ROTATE__)
    {MMI_CATEGORY431_ROTATE_ID, (U8 *) category431_rotate, NULL, (S16 *) coordinate_set431_rotate},
    {MMI_CATEGORY431_ROTATE_FULL_ID, (U8 *) category431_rotate_fullscreen, NULL, (S16 *) coordinate_set431_rotate_fullscreen},
#endif /* defined(__MMI_SCREEN_ROTATE__) */
#endif /* defined(__MMI_BROWSER_2__) || defined(__MMI_GADGET_SUPPORT__) */
#ifdef __MMI_OP01_DCD__
    {MMI_CATEGORY432_ID, (U8 *) category432, (S16 *) coordinate_set432, NULL},
#endif
#ifdef __MMI_OP11_CAT433_SUPPORT__
    {MMI_CATEGORY433_ID, (U8 *) category433, (S16 *) coordinate_set433, NULL},
#endif /* __MMI_OP11_CAT433_SUPPORT__ */
    {MMI_CATEGORY435_ID, (U8 *) category435, (S16 *) coordinate_set435, NULL},
#ifdef __MMI_CAT44X_SUPPORT__        
    {MMI_CATEGORY440_ID, (U8 *) category440, (S16 *) coordinate_set440, NULL},
    {MMI_CATEGORY443_ID, (U8 *) category443, (S16 *) coordinate_set443, NULL},
    {MMI_CATEGORY445_ID, (U8 *) category445, (S16 *) coordinate_set445, NULL},    
    {MMI_CATEGORY447_ID, (U8 *) category447, (S16 *) coordinate_set447, NULL},  
    {MMI_CATEGORY448_ID, (U8 *) category448, (S16 *) coordinate_set448, NULL}, 
    {MMI_CATEGORY449_ID, (U8 *) category449, (S16 *) coordinate_set449, NULL}, 
#endif /* __MMI_CAT44X_SUPPORT__ */ 
#if 0
/* under construction !*/
#endif//0    
#ifdef __MMI_OP12_CAT533_SUPPORT__
    {MMI_CATEGORY533_ID, (U8 *) category533, (S16 *) coordinate_set533, NULL},
#endif /* __MMI_OP12_CAT533_SUPPORT__ */
    {MMI_CATEGORY620_ID, (U8 *) category620, (S16 *) coordinate_set620, NULL},
#ifdef __UI_MMS_VIEWER_CATEGORY__
    {MMI_CATEGORY630_ID, (U8 *) category630, (S16 *) coordinate_set630, NULL},
#endif
#ifdef __MMI_ANIMATED_DIAL__
    {MMI_CATEGORY631_ID, (U8 *) category631, (S16 *) coordinate_set631, NULL},
#endif /* __MMI_ANIMATED_DIAL__ */
#ifdef __MMI_MOTION_MAINMENU__
    {MMI_CATEGORY14_MOTION_ID, (U8 *) category14_motion, (S16 *) coordinate_set14_motion, NULL},
#endif /* __MMI_MOTION_MAINMENU__ */
#ifdef __MMI_MOTION_DIAL__
    {MMI_CATEGORY633_ID, (U8 *) category633, (S16 *) coordinate_set633, NULL},
#endif /* __MMI_MOTION_DIAL__ */
#ifdef __MMI_SMS_APP_EMS_SUPPORT__
    {MMI_CATEGORY_EMS_ID, (U8 *) categoryEMS, (S16 *) coordinate_setEMS, NULL},
#endif/*#ifdef __MMI_SMS_APP_EMS_SUPPORT__*/
    {MMI_CATEGORY_WCLOCK, (U8 *) categoryWcScreen, (S16 *) coordinate_WcScreen, NULL},
    {MMI_CATEGORY_VDOPLY, (U8 *) categoryVdoScreen, (S16 *) coordinate_VdoScreen, NULL},
    {MMI_CATEGORY_VDOPLY_BUTTON, (U8 *) categoryVdoScreen_button, (S16 *) coordinate_VdoScreen_button, NULL},
    {MMI_CATEGORY_NSM275, (U8 *) categoryNSM275, (S16 *) coordinate_setNSM275, NULL},
#if (MMI_MAX_SIM_NUM >= 3)
	{MMI_CATEGORY626_ID, (U8 *) category626, (S16 *) coordinate_set626, NULL},
    {MMI_CATEGORY626_NO_TAB_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
#endif/*#if (MMI_MAX_SIM_NUM >= 3)*/    
//    {MMI_CATEGORY627_ID, (U8 *) category627, (S16 *) coordinate_set627, NULL},
//    {MMI_CATEGORY628_ID, (U8 *) category628, (S16 *) coordinate_set628, NULL},
    {MMI_CATEGORY629_ID, (U8 *) category629, (S16 *) coordinate_set629, NULL},        
#if defined(__MMI_CSB_BROWSER__)||defined(__MMI_PHB_UI_IN_TABS__)||defined(__MMI_FRM_HISTORY__)||(!defined(__MMI_NOT_TAB_SUPPORT__))
    {MMI_CATEGORY657_ID, (U8 *) category657, (S16 *) coordinate_set657, NULL},
#endif
#if defined(__MMI_CASCADED_OPTION_MENU__)

#ifdef __MMI_SCREEN_ROTATE__
    {MMI_CATEGORY_CASCADING_MENU_ID, (U8 *) category800, (S16 *) coordinate_set800, (S16 *)coordinate_set800_rotated},
#else /* __MMI_SCREEN_ROTATE__ */
    {MMI_CATEGORY_CASCADING_MENU_ID, (U8 *) category800, (S16 *) coordinate_set800, NULL},
#endif /* __MMI_SCREEN_ROTATE__ */
#endif/*#if defined(__MMI_CASCADED_OPTION_MENU__)*/
#if defined(__MMI_SEARCH_WEB_BAIDU__)
    {MMI_CAT1001_ID, (U8 *) Category1001, (S16 *) Coordinate_Set1001, NULL},
#endif/*#ifdef __MMI_SEARCH_WEB_BAIDU__*/    
#if defined(__MMI_CSB_BROWSER__)||defined(__MMI_PHB_UI_IN_TABS__)||defined(__MMI_PHB_CALLER_GROUP__)||defined(__MMI_SNS_CONTACTS__)
    {MMI_CAT3001_ID, (U8 *) category3001, (S16 *) coordinate_set3001, NULL},    
#endif

#if defined(__MMI_CMMB_CAS_2GPP_SUPPORT__)
    {MMI_CAT3002_ID, (U8 *) category3002, (S16 *) coordinate_set3002, NULL},
#endif	


#if defined(__MMI_EBOOK_READER__)
#ifdef __MMI_FTE_SUPPORT__
    {MMI_CAT3003_ID, (U8 *) category3003, (S16 *) coordinate_set3003, NULL},
    {MMI_CAT3003_ID_FULLSCREEN, (U8 *) category3003_fullscreen, (S16 *) coordinate_set3003_fullscreen, NULL},
#endif /* __MMI_FTE_SUPPORT__*/
#endif


#if defined(__MMI_CMMB_CAS_2GPP_SUPPORT__)||defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    {MMI_CAT3005_ID, (U8 *) category74, (S16 *) coordinate_set74, NULL},
#endif
#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__) && defined(__MBBMS_INTER__)
    {MMI_CAT6001_ID, (U8 *) category6001, (S16 *) coordinate_set6001, NULL},
    {MMI_CAT6001_ID_WITH_SCR_BG, (U8 *) category6001_scr_bg, (S16 *) coordinate_set6001, NULL},
#endif
    {MMI_CAT6003_ID, (U8 *) category6003, (S16 *) coordinate_set6003, NULL},
    {MMI_CAT6003_NO_SK_ID, (U8 *) category6003_no_sk, (S16 *) coordinate_set6003_no_sk, NULL},

    {MMI_CAT9001_ID, (U8 *) category9001, (S16 *) coordinate_set9001, NULL},
        
#ifdef __J2ME__
    {MMI_CAT2002_ID, (U8 *) Category2002, (S16 *) Coordinate_Set2002, NULL},
#if !defined(GUI_EDITOR_SHOW_TITLE)  
    {MMI_CAT2002_NO_TICKER_ID, (U8 *) Category2002_no_ticker, (S16 *) Coordinate_Set2002_no_ticker, NULL},
#endif /* __MMI_MAINLCD_320X240__ */
#endif /* __J2ME__ */

    {MMI_CAT1002_ID, (U8 *) category1002, (S16 *) coordinate_set1002, NULL},
 //   {MMI_CAT1002_TAB_ID, (U8 *) cat1002_tab, (S16 *) Coordinate_Set1002_tab, NULL},
#ifdef __MMI_CAT1X_0P11_SUPPORT__
    {MMI_CAT1001_OP11_ID, (U8 *) category1001_op11, (S16 *) coordinate_set1001_op11, NULL},
#endif    
    {MMI_CAT9002_ID, (U8 *) category9002, (S16 *) coordinate_set9002, NULL},
#if defined(__FMGR_FTE_TOOLBAR_SUPPORT__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))                       
    {MMI_CAT1003_ID, (U8 *) Category1003, (S16 *) Coordinate_Set1003, NULL},
#endif/*#if defined(__FMGR_FTE_TOOLBAR_SUPPORT__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))*/    
#if defined(__MMI_IME_V3__)
#ifdef __MMI_SCREEN_ROTATE__
    {MMI_CAT1004_ID, (U8 *)Category1004, (S16 *)Coordinate_Set1004, (S16 *)Coordinate_Set1004},
#else
    {MMI_CAT1004_ID, (U8 *)Category1004, (S16 *)Coordinate_Set1004, NULL},
#endif /* __MMI_SCREEN_ROTATE__ */
#endif/*#if defined(__MMI_IME_V3__)*/
#if defined(__MMI_GADGET_SUPPORT__)
    {MMI_CAT1006_ID, (U8 *) Cat1006, (S16 *) Coordinate_Set1006, NULL},
#endif/*#ifdef __MMI_GADGET_SUPPORT__*/
#if defined(__MMI_OP11_HOMESCREEN__)
/* under construction !*/
#endif
#ifdef __MMI_TC01_LTUI_SMART_MEMO__
    {MMI_CAT9007_TC01_ID, (U8 *) category9007_tc01, (S16 *) coordinate_set9007_tc01, NULL},
    {MMI_CAT9008_TC01_ID, (U8 *) category9008_tc01, (S16 *) coordinate_set9008_tc01, NULL},
    {MMI_CAT9009_TC01_ID, (U8 *) category9009_tc01, (S16 *) coordinate_set9009_tc01, NULL},
#endif /* __MMI_TC01_LTUI_SMART_MEMO__ */
	{MMI_CAT1031_ID, (U8 *) category1031, (S16 *) coordinate_set1031, NULL},
	{MMI_CAT1031_NO_TAB_ID, (U8 *) asyncdynamic_list_menu_category, (S16 *) list_coordinate_set, NULL},
//	{MMI_CAT1033_ID, (U8 *) category1033, (S16 *) coordinate_set1033, NULL},
//	{MMI_CAT1033_NO_TAB_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
     {MMI_CAT9010_ID, (U8 *) category9010, (S16 *) coordinate_set9010, NULL},
     {MMI_CAT9010_SMALL_ID, (U8 *) category9010_small, (S16 *) coordinate_set9010_small, NULL},
     {MMI_CAT9010_LIST_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
#endif
#ifdef __MMI_TOUCH_SCREEN__
    {MMI_CAT9011_ID, (U8 *) category9011, (S16 *) coordinate_set9011, NULL},
#endif
#ifdef __ATV_SMS_SUPPORT__
    {MMI_CAT9006_ID, (U8 *) category9006, (S16 *) coordinate_set9006, NULL},
    {MMI_CAT9007_ID, (U8 *) category9007, (S16 *) coordinate_set9007, NULL},
    {MMI_CAT9008_ID, (U8 *) category9008, (S16 *) coordinate_set9008, NULL},
	{MMI_CAT9009_ID, (U8 *) category9009, (S16 *) coordinate_set9009, NULL},
	{MMI_CAT9009_FULL_ID, (U8 *) category9009_full, (S16 *) coordinate_set9009_full, NULL},
    {MMI_CAT1010_ID, (U8 *) CAT1010, (S16 *) coordinate_set1010, NULL},
    {MMI_CAT1011_ID, (U8 *) CAT1011, (S16 *) coordinate_set1011, NULL},
    {MMI_CAT1013_ID, (U8 *) CAT1013, (S16 *) coordinate_set1013, NULL},
#endif /* __ATV_SMS_SUPPORT__ */
#ifdef __MMI_MOBILE_TV_CMMB_SUPPORT__
	{MMI_CAT2003_ID, (U8 *) category_2003, (S16 *) coordinate_set2003, NULL},
#endif

#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)||defined(__MMI_MOT_SUPPORT__)||defined(__MMI_MRE_MSPACE__)
    {MMI_CAT3006_ID, (U8 *) category_3006, (S16 *) coordinate_set3006, NULL},
#endif

    {MMI_CAT1024_ID, (U8 *) CAT1024, (S16 *) coordinate_set1024, NULL},
    {MMI_CAT1025_ID, (U8 *) CAT1025, (S16 *) Coordinate_Set1025, NULL},
#if defined(__MMI_WLAN_FEATURES__)    
	{MMI_CAT1049_ID, (U8 *) cat1049, (S16 *) Coordinate_set1049, NULL},
#endif/*#ifdef __MMI_WLAN_FEATURES__*/	
#if defined(__MMI_SSO__)
    {MMI_CAT1070_ID, (U8 *) cat1070, (S16 *) Coordinate_set1070, NULL},
#endif/*#if defined(__MMI_SSO__)*/    
    {MMI_CAT1071_ID, (U8 *) asyncdynamic_list_menu_category, (S16 *) list_coordinate_set, NULL},

#if defined(__MMI_ATV_SUPPORT__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
    {MMI_CAT1040_ID, (U8 *) Cat1040, (S16 *) Coordinate_set1040, NULL},
#endif /* defined(__MMI_ATV_SUPPORT__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__) */
#ifdef __MMI_OP01_DCD_V30__
    {MMI_CAT9003_OP01_ID, (U8 *) category9003_op01, (S16 *) coordinate_set9003_op01, NULL},
    {MMI_CAT9004_OP01_ID, (U8 *) category9004_op01, (S16 *) coordinate_set9004_op01, NULL},
    {MMI_CAT9005_OP01_ID, (U8 *) fixed_list_menu_category, (S16 *) list_coordinate_set, NULL},
#endif /* __MMI_OP01_DCD_V30__ */
#ifdef __MMI_OP02_LEMEI__
    {MMI_CAT9002_OP02_ID, (U8 *) category9002_op02, (S16 *) coordinate_set9002_op02, NULL},
#endif
#ifdef __OP01__
	{MMI_CAT3010_OP01_ID, (U8 *) category3010_op01, (S16 *) coordinate_set3010_op01, NULL},
#endif
#ifdef __MMI_MAINLCD_128X64__
	{MMI_CAT9014_ID, (U8*) category9014, (S16*) coordinate_set9014, NULL},
#endif
#ifdef __SOCIAL_NETWORK_SUPPORT__
    {MMI_CAT1051_ID, (U8 *) cat1051,  (S16 *) coordinate_set1051, NULL},
    {MMI_CAT1052_ID, (U8 *) cat1052,  (S16 *) coordinate_set1052, NULL},
	{MMI_CAT57_SNS_ID, (U8 *) category57_sns,  (S16 *) coordinate_set57_sns, NULL},
#endif /* __SOCIAL_NETWORK_SUPPORT__ */
#ifdef __MMI_MAINLCD_96X64__
    {MMI_CAT9023_ID, (U8 *) category9023, (S16 *) coordinate_set9023, NULL},
#endif /*__MMI_MAINLCD_96X64__*/
#if defined(__MMI_FTE_SUPPORT_SLIM__) && defined(__GDI_MEMORY_PROFILE_2__)
		{MMI_CATEGORY129_RESIZE_ID, (U8 *) category129_resize, (S16 *) coordinate_set129_resize, NULL},
#endif
#if defined(__MMI_BT_DIALER_SUPPORT__)
     //for BT dialer
	{MMI_CAT632_ID, (U8*)category632, (S16*)coordinate_set632, NULL},
#endif
#if defined(__MMI_BTD_BOX_UI_STYLE__) || defined(__MMI_MEGAPHONE_SUPPORT__)
	{MMI_CAT8001_ID, (U8*)category8001, (S16*)coordinate_set8001, NULL},
#endif
#ifdef __KARAOKE_SUPPORT__ 
	{MMI_CAT8002_ID, (U8*)category8002, (S16*)coordinate_set8002, NULL},
#endif

#ifdef __MMI_WEARABLE_DEVICE__
     //Swatch IDLE preivew
	{MMI_CAT9100_ID, (U8*)category9100, (S16*)coordinate_set9100, NULL},
#endif  //__MMI_WEARABLE_DEVICE__
};

//This array must contain sorted screen ids, since binary search will be used on this array
//const S16 g_screenid_coordinate_sets_map_entries_count = 70;

const dm_screen_id_coordinate_set_map_struct g_screenid_coordinate_sets_map[] = 
{
#ifdef __MMI_FACTORY_MODE__ //080106 cat57
    {SCR_ID_FM_CAMERA, (S16 *) coordinate_set57_top_infobox}, /* 28643 */
#endif
    {0, NULL}
};

/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  dm_get_coordinate_sets_count
 * DESCRIPTION
 *  get coordiante set address by category id
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 address of corresponding coordinate set
 *****************************************************************************/
S32 dm_get_coordinate_sets_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(g_screenid_coordinate_sets_map) / sizeof(dm_screen_id_coordinate_set_map_struct);
}   /* end of dm_get_screenid_coordinate_sets_map_entries_count */


/*****************************************************************************
 * FUNCTION
 *  dm_get_control_sets_count
 * DESCRIPTION
 *  get coordiante set address by category id
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 address of corresponding coordinate set
 *****************************************************************************/
S32 dm_get_control_sets_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(g_categories_controls_map) / sizeof(dm_category_id_control_set_map_struct);
}   /* end of dm_get_screenid_coordinate_sets_map_entries_count */


/*****************************************************************************
 * FUNCTION
 *  dm_get_base_control_set
 * DESCRIPTION
 *  get address of base control set
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 address of base control set
 *****************************************************************************/
U8 *dm_get_base_control_set(void)
{
#ifdef __MMI_SCREEN_ROTATE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_is_screen_width_height_swapped())
    {
        return (U8*) dm_base_rotated_control_set;
    }
    else
    {
        return (U8*) dm_base_control_set;
    }
#else /* __MMI_SCREEN_ROTATE__ */ 
    return (U8*) dm_base_control_set;
#endif /* __MMI_SCREEN_ROTATE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_base_coordinate_set
 * DESCRIPTION
 *  get address of base coordinate set
 * PARAMETERS
 *  void
 * RETURNS
 *  address of base coordinate set
 *****************************************************************************/
S16 *dm_get_base_coordinate_set(void)
{
#ifdef __MMI_SCREEN_ROTATE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_is_screen_width_height_swapped())
    {
        return (S16*) dm_base_rotated_coordinate_set;
    }
    else
    {
        return (S16*) dm_base_coordinate_set;
    }
#else /* __MMI_SCREEN_ROTATE__ */ 
    return (S16*) dm_base_coordinate_set;
#endif /* __MMI_SCREEN_ROTATE__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_base_control_set2
 * DESCRIPTION
 *  get address of base control set 2
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 address of base control set 2
 *****************************************************************************/
U8 *dm_get_base_control_set2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8*) dm_base_control_set2;
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_base_coordinate_set2
 * DESCRIPTION
 *  get address of base coordinate set 2
 * PARAMETERS
 *  void
 * RETURNS
 *  address of base coordinate set 2
 *****************************************************************************/
S16 *dm_get_base_coordinate_set2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S16*) dm_base_coordinate_set2;
}


#if defined(GUI_SUBMENU_USE_SPECIFIC_STYLE)
/*****************************************************************************
 * FUNCTION
 *  dm_get_base_control_set_submenu
 * DESCRIPTION
 *  get address of base control set of submenu
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 address of base control set of submenu
 *****************************************************************************/
U8 *dm_get_base_control_set_submenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8*) dm_base_control_set_submenu;
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_base_coordinate_set_submenu
 * DESCRIPTION
 *  get address of base coordinate set of submenu
 * PARAMETERS
 *  void
 * RETURNS
 *  address of base coordinate set of submenu
 *****************************************************************************/
S16 *dm_get_base_coordinate_set_submenu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S16*) dm_base_coordinate_set_submenu;
}
#endif /* defined(GUI_SUBMENU_USE_SPECIFIC_STYLE) */


#if defined(GUI_COMMON_USE_SPECIFIC_STYLE)
/*****************************************************************************
 * FUNCTION
 *  dm_get_base_control_set_common
 * DESCRIPTION
 *  get address of base control set of common
 * PARAMETERS
 *  void
 * RETURNS
 *  U8 address of base control set of common
 *****************************************************************************/
U8 *dm_get_base_control_set_common(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8*) dm_base_control_set_common;
}


/*****************************************************************************
 * FUNCTION
 *  dm_get_base_coordinate_set_COMMON
 * DESCRIPTION
 *  get address of base coordinate set of COMMON
 * PARAMETERS
 *  void
 * RETURNS
 *  address of base coordinate set common
 *****************************************************************************/
S16 *dm_get_base_coordinate_set_common(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S16*) dm_base_coordinate_set_common;
}
#endif /* defined(GUI_COMMON_USE_SPECIFIC_STYLE) */



