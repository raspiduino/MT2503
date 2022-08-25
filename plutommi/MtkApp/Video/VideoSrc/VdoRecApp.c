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
 *   VdoRecApp.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Video Recorder Applcation.
 *
 * Author:
 * -------
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#if defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
#include "wgui_inline_edit.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "med_api.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_media_app_trc.h"
#include "kal_trace.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_prot.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "app_mem.h"
#include "mmi_rp_app_vdorec_def.h"
#include "gdi_lcd_config.h"
#include "lcd_sw_inc.h"
#include "gdi_include.h"
#include "gui.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "GlobalResDef.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_rp_file_type_def.h"
#include "fs_type.h"
#include "custom_mmi_default_value.h"
#include "stdio.h"
#include "fs_func.h"
#include "AlertScreen.h"
#include "ScreenRotationGprot.h"
#include "gui_data_types.h"
#include "CustDataRes.h"
#include "gdi_const.h"
#include "kal_public_api.h"
#include "FileMgrResDef.h"
#include "fs_errcode.h"
#include "gdi_features.h"
#include "gdi_datatype.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "CommonScreensResDef.h"
#include "gui_typedef.h"
#include "gui_effect_oem.h"
#include "wgui_touch_screen.h"
#include "mdi_audio.h"
#include "GpioSrvGprot.h"
#include "gpiosrvgprot.h"
#include "gui_themes.h"
#include "mmi_frm_history_gprot.h"
#include "PixcomFontEngine.h"
#include "mms_api.h"
#include "custom_events_notify.h"
#include "wgui_categories_popup.h"
#include "wgui_include.h"
#include "wgui_categories.h"
#include "wgui_categories_list.h"
#include "CustMenuRes.h"
#include "stack_config.h"
#include "MMI_features_video.h"     /* features */
#include "AMGprot.h"                /* for check vre background running */
#include "IdleGprot.h"
#include "wgui_categories_multimedia.h"
#include "gui_font_size.h"

/* framework related headers */
#include "CommonScreens.h"          /* Popup */
#include "FileMgrSrvGProt.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif
#include "AlarmFrameworkProt.h"     /* alarm framework */
#include "ModeSwitchSrvGprot.h"     /* flight mode */

/* gdi, mid, video rec headers */
#include "lcd_if.h"
#include "mdi_datatype.h"
#include "mdi_include.h"
#include "mdi_video.h"              /* mdi video library */

#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
#endif 

#include "VdoRecCuiGprot.h"
#include "CameraCuiGprot.h"
#include "filemgrcuigprot.h"
#include "MenuCuiGprot.h"
#include "inlinecuigprot.h"

/* video recoder related */
#include "resource_video_skins.h"   /* UI custom config */

#include "VdoRecResDef.h"
#include "VdoRecApp.h"
#include "VdoRecGProt.h"
#include "VdoPlyGProt.h"            /* entry function */
#include "ScrLockerGprot.h"

#include "MMI_ap_dcm_config.h"


#if defined(__MMI_BT_SUPPORT__) || defined(__MMI_OPP_SUPPORT__)
#include "BTMMIObexGprots.h"
#endif /* __MMI_BT_SUPPORT__ || __MMI_OPP_SUPPORT__ */ 

#include "BTMMIScrGprots.h"
#include "BTMMIObexGprots.h"

#if defined(__DIRECT_SENSOR_SUPPORT__) || defined(__DIRECT_SENSOR_V2_SUPPORT__)
#include "image_sensor.h"
#endif 

#ifdef __MMI_CAMERA__
#include "mdi_camera.h"
#include "CameraApp.h"
#endif

#ifdef __VDOREC_FEATURE_EMAIL_SUPPORT__
#include "EmailAppGProt.h"
#endif

#ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__
#include "CallSetSrvGprot.h"
#endif 

#ifdef __MMI_UCM__
#include "UCMGProt.h"
#include "UcmSrvGProt.h"
#endif /* __MMI_UCM__ */

#include "VdoRecCuiGprot.h"
#include "CameraCuiGprot.h"

#ifdef __MMI_OP01_DCD__
#include "DCDGprot.h"

extern void mmi_dcd_line_taken(void);
extern void mmi_dcd_line_given(void);
extern MMI_BOOL mmi_dcd_is_syncing(void);
extern void mmi_dcd_running_conflict_prompt(void);
#endif

#ifdef __VDOREC_FEATURE_BT_SEND_SUPPORT__
#include "Btsendcuigprot.h"
#endif
#include "ProfilesSrvGprot.h"
#if defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
#include "gui_touch_feedback.h"
#endif

#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) 
#include "mmi_msg_struct.h"
#include "device.h"
#include "mmi_cb_mgr_gprot.h"
#endif

#ifdef __MMI_VIDEO_PLAYER__

#include "mmi_rp_app_vdoply_def.h"
#ifdef __VDOPLY_FEATURE_CROSS_LAYEROUT__
#define MMI_VDOPLY_BG_COLOR		gdi_act_color_from_rgb(255, 248, 248, 248)
#else
#define MMI_VDOPLY_BG_COLOR     GDI_COLOR_BLACK
#endif
#endif


/***************************************************************************** 
* Define
*****************************************************************************/
#define DUMMY_COMMAND               (0)
#define HINT_POPUP_FADE_TIME        (2000)
#define VDOREC_DRAW_OSD_DELAY       (50)

#if defined(__MDI_VIDEO_HW_ROTATOR_SUPPORT__) && defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)
#define __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
#endif

#if defined(__GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__) && (defined(__LANDSCAPE_UI_ON_PORTRAIT_LCM__) || defined(__LANDSCAPE_UI_ON_PORTRAIT_LCM_SLIM_VERSION__))
#define __VDOREC_DOUBLE_BUFFER_SUPPORT__
#endif

#ifdef __MMI_VIDEO_RECORDER_SLIM__
#define __VDOREC_FEATURE_MULTI_REGION_SUPPORT__
#define __VDOREC_FEATURE_HIDE_HINT__
#else
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)
#define __VDOREC_FEATURE_MULTI_REGION_SUPPORT__
#endif
#endif

#ifdef __MMI_VIDEO_RECORDER_SLIM__
#define __VDOREC_FEATURE_EXT_REQ_DISABLE__
#endif


/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern wgui_inline_item wgui_inline_items[];
//extern BOOL r2lMMIFlag;

/****************************************************************************
* Global Function                                                           
*****************************************************************************/
extern void custom_start_flashlight(kal_uint8 red_level, kal_uint8 green_level, kal_uint8 blue_level, kal_uint8 duty);
extern void custom_stop_flashlight(void);

/***************************************************************************** 
* Local Variable
*****************************************************************************/
vdorec_context_struct g_vdorec_cntx;
MMI_BOOL mmi_vdorec_qty_codec_size[VDOREC_SETTING_VIDEO_QTY_COUNT][VDOREC_SETTING_VIDEO_FORMAT_COUNT][VDOREC_SETTING_VIDEO_SIZE_COUNT];
U32 support_wb_item[VDOREC_SETTING_WB_COUNT];
U32 support_effect_item[VDOREC_SETTING_EFFECT_COUNT];

static S32 total_pre_region_size = 0;

typedef struct
{
	U8 Idx;
	U8 Val;
}VdoRecGenMapStruct;


/***************************************************************************** 
* Local Function
*****************************************************************************/

/* app */
static void mmi_vdorec_post_to_parent(U16 evt_id, CHAR *file_path);
static void mmi_vdorec_load_setting(void);
static void mmi_vdorec_store_setting(void);
static void mmi_vdorec_clear_osd_layer(gdi_handle handle);

static void mmi_vdorec_blt_screen(void);
static void mmi_vdorec_restore_setting(void);
static void mmi_vdorec_get_save_filename(CHAR *file_buf_p);
static void mmi_vdorec_disply_popup(MMI_STR_ID str_id, mmi_event_notify_enum eventy_type, S32 popup_result_type);
#ifdef __VDOREC_FEATURE_WB__
static void mmi_vdorec_entry_wb_screen(void);
#endif
/* preview */
static BOOL mmi_vdorec_check_and_display_error_popup(void);

static void mmi_vdorec_resize_preview_layer(void);

static void mmi_vdorec_get_video_size(S32 *video_width, S32 *video_height);
//static U16 mmi_vdorec_get_zoom_factor(void);
static void mmi_vdorec_lsk_press_hdlr(void);
static void mmi_vdorec_lsk_release_hdlr(void);
static void mmi_vdorec_rsk_press_hdlr(void);
static void mmi_vdorec_rsk_release_hdlr(void);
static void mmi_vdorec_ck_press_hdlr(void);
static void mmi_vdorec_ck_release_hdlr(void);

#if defined(__VDOREC_FEATURE_EV__) && !defined(__VDOREC_FEATURE_FTE_SUPPORT__)
static void mmi_vdorec_inc_ev_key_press_hdlr(void);
static void mmi_vdorec_inc_ev_key_release_hdlr(void);
static void mmi_vdorec_dec_ev_key_press_hdlr(void);
static void mmi_vdorec_dec_ev_key_release_hdlr(void);
#endif /* __VDOREC_FEATURE_EV__ */

#ifdef __VDOREC_FEATURE_ZOOM__
static void mmi_vdorec_start_zoom(void *is_zoom_in);
static void mmi_vdorec_zoom_in_key_press_hdlr(void);
static void mmi_vdorec_zoom_in_key_release_hdlr(void);
static void mmi_vdorec_zoom_out_key_press_hdlr(void);
static void mmi_vdorec_zoom_out_key_release_hdlr(void);
static void mmi_vdorec_start_fast_zoom(void *is_zoom_in);
static void mmi_vdorec_stop_fast_zoom(void);
#endif /* __VDOREC_FEATURE_ZOOM__ */ 

static void mmi_vdorec_turn_on_led_highlight(void);
static void mmi_vdorec_turn_off_led_highlight(void);
static void mmi_vdorec_record_result_hdlr_callback(MDI_RESULT result, void* user_data);

#ifndef __MMI_VIDEO_RECORDER_SLIM__

#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
static void mmi_vdorec_video_size_hotkey_press(void);
#endif

#ifdef __VDOREC_FEATURE_VIDEO_QTY__
static void mmi_vdorec_video_qty_hotkey_press(void);
#endif

#if 0
#ifdef __VDOREC_FEATURE_NIGHT__
/* under construction !*/
#endif 
#endif

#ifdef __VDOREC_FEATURE_WB__
static void mmi_vdorec_wb_hotkey_press(void);
#endif 

#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
static void mmi_vdorec_led_highlight_hotkey_press(void);
#endif 

#ifdef __VDOREC_FEATURE_RECORD_AUD__
static void mmi_vdorec_record_aud_hotkey_press(void);
#endif 

#endif  /*__MMI_VIDEO_RECORDER_SLIM__*/

static void mmi_vdorec_start_preview(void);
static void mmi_vdorec_enter_state(U16 state);


#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__)
mmi_ret mmi_vdorec_clam_close_event_hdlr(mmi_event_struct *evt);
#endif 

static void mmi_vdorec_entry_app_internal(void);
static void mmi_vdorec_exit_app(void);

#ifdef __MMI_SUBLCD__
static void mmi_vdorec_draw_sublcd_icon(void);
static void mmi_vdorec_entry_sublcd_screen(void);
static void mmi_vdorec_exit_sublcd_screen(void);
#endif /* __MMI_SUBLCD__ */ 

static void mmi_vdorec_record_timer_cyclic(void);
static void mmi_vdorec_set_softkey(U16 lsk_str_id, U16 rsk_str_id, U16 lsk_img_id, U16 rsk_img_id, U16 ck_img_id);
static void mmi_vdorec_draw_style_text(CHAR *str, S32 offset_x, S32 offset_y, S32 truncate_width, video_style_text_struct *style_txt);
static void mmi_vdorec_init_ui(void);
static void mmi_vdorec_draw_osd(U32 component);
static void mmi_vdorec_draw_title(void);
#ifndef __MMI_VIDEO_RECORDER_SLIM__
static void mmi_vdorec_draw_status(void);
#endif
static void mmi_vdorec_draw_softkey(void);
static void mmi_vdorec_draw_panel_state(void);
static void mmi_vdorec_draw_panel_ev(void);
static void mmi_vdorec_draw_panel_zoom(void);
static void mmi_vdorec_draw_panel_timer(void);

#ifndef __VDOREC_HIDE_HINT__
static void mmi_vdorec_hide_hint(void);
static void mmi_vdorec_draw_hint(void);
static void mmi_vdorec_set_hint(CHAR *hint_str1, CHAR *hint_str2, U16 fade_time);
#endif
static void mmi_vdorec_null_key_event(void);


/* save */
#if !defined(__VDOREC_FEATURE_DIRECT_SAVE__) 
static void mmi_vdorec_save_confirm_no(void);
static void mmi_vdorec_entry_save_confirm_screen(void);
#ifdef __VDOREC_FEATURE_SAVE_CONFIRM_FWTO__
static void mmi_vdorec_save_confirm_forward_to(void);
#endif
#endif
static void mmi_vdorec_save_result_hdlr_callback(MDI_RESULT result, void* user_data);
static void mmi_vdorec_exit_saving_screen(void);
static void mmi_vdorec_entry_saving_screen(void);

/* menu */
static void mmi_vdorec_entry_option_screen(void);
static void mmi_vdorec_entry_camcoder_setting_screen(void);

#ifndef __VDOREC_FEATURE_MERGE_MENU__
static void mmi_vdorec_entry_video_setting_screen(void);
#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 

#ifdef __VDOREC_FEATURE_EFFECT__
static void mmi_vdorec_set_effect_setting_value(void);
static void mmi_vdorec_entry_effect_setting_screen(void);
#endif

#ifdef __VDOREC_FEATURE_STORAGE__
static void mmi_vdorec_entry_set_app_storage_screen(BOOL is_option_storage);
static void mmi_vdorec_entry_set_storage_screen_internal(void);
#endif /* __VDOREC_FEATURE_STORAGE__ */ 

#ifdef __VDOREC_FEATURE_RESTORE_DEFAULT__
static void mmi_vdorec_entry_restore_default_confirm_yes(void);
static void mmi_vdorec_entry_restore_default_confirm_screen(void);
#endif

#if defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_vdorec_touch_scr_pen_down_hdlr(mmi_pen_point_struct pos);
static void mmi_vdorec_touch_scr_pen_up_hdlr(mmi_pen_point_struct pos);
static void mmi_vdorec_touch_scr_pen_move_hdlr(mmi_pen_point_struct pos);
static BOOL mmi_vdorec_touch_scr_hit_test(S32 pos_x, S32 pos_y, vdorec_ui_touch_struct *touch_obj);
#endif /* defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ /* __VDOREC_FEATURE_TOUCH_SCREEN__ & __MMI_TOUCH_SCREEN__ */

#ifdef __VDOREC_FEATURE_SWITCH_TO_CAMERA__
static void mmi_vdorec_switch_to_camera_hdlr(void);
#endif /* __VDOREC_FEATURE_SWITCH_TO_CAMERA__ */

#ifdef __VDOREC_FEATURE_MMS_SUPPORT__
void mmi_vdorec_highlight_to_mms(void);
static void mmi_vdorec_to_mms_hdlr(void);
#endif

#ifdef __VDOREC_FEATURE_EMAIL_SUPPORT__
void mmi_vdorec_highlight_to_email(void);
static void mmi_vdorec_to_email_hdlr(void);
#endif

#ifdef __VDOREC_FEATURE_BT_SEND_SUPPORT__
void mmi_vdorec_highlight_to_bluetooth(void);
static void mmi_vdorec_to_BT_hdlr(void);
#endif 

#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
static void mmi_vdorec_entry_preview_option_screen(void);
static void mmi_vdorec_entry_preview_video_screen(void);
static void mmi_vdorec_fsm_preview_stop(void);
static void mmi_vdorec_fsm_preview_play(void);
static void mmi_vdorec_play_timer_cyclic(void);
static void mmi_vdorec_delete_saved_vdo_confirm(void);
static void mmi_vdorec_del_key_press_hdlr(void);
static void mmi_vdorec_del_key_release_hdlr(void);
static void mmi_vdorec_preview_idle_timeout_hdlr(void);
static void mmi_vdorec_preview_idle_timeout_cancel(void);
#endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

#if (!defined(__VDOREC_FEATURE_DIRECT_SAVE__) && !defined(__VDOREC_FEATURE_SLIM_UE__))||defined(__VDOREC_FEATURE_PREVIEW_SAVED_FILE__)
static void mmi_vdorec_hide_unaviailable_send_options(void);
#endif

#if !defined(__VDOREC_FEATURE_DIRECT_SAVE__) && !defined(__VDOREC_FEATURE_SLIM_UE__)
static void mmi_vdorec_entry_send_screen(void);
#endif
static void mmi_vdorec_load_saved_filename(CHAR *filepath);

static void mmi_vdorec_draw_panel_progress_bar(U8 ratio);
static void mmi_vdorec_clear_panel_progress_bar(void);
#ifdef __VDOREC_FEATURE_LIMIT_PROGRESS_BAR__
static void mmi_vdorec_update_progress_ratio(void);
#endif
static BOOL mmi_vdorec_is_draw_progress_bar(void);

static void mmi_vdorec_clear_zoom(void);
static void mmi_vdorec_clear_ev(void);
#ifndef __MMI_VIDEO_RECORDER_SLIM__
#ifdef VDOREC_TOGGLE_HIDE_OSD_KEY
static void mmi_vdorec_toggle_osd_key_press_hdlr(void);
#endif
#endif
static BOOL mmi_vdorec_is_in_bgcall(void);

/*init variable of compile option*/
static void mmi_vdorec_init_according_to_compile_option(void);

/*fast zoom related function*/
static void mmi_vdorec_draw_zoom_osd(void);

#ifdef __VDOREC_USING_BLT_REGION__
static void mmi_vdorec_merge_blt_rgn(S32 x, S32 y, S32 w, S32 h);
static void mmi_vdorec_set_merge_region(S32 x, S32 y, S32 w, S32 h);
#endif

static U8 mmi_vdorec_pre_key_listen_hdlr(void);
static U8 mmi_vdorec_post_key_listen_hdlr(void);
static void mmi_vdorec_reset_watchdog_time_out_handler(void);
static void mmi_vdorec_watchdog_time_out_handler(void);
static BOOL mmi_vdorec_entry_app_pre_check(CHAR *p_filepath);

#ifndef __MMI_VIDEO_RECORDER_SLIM__
#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
static MMI_BOOL mmi_vdorec_malloc_app_mem(void);
static void mmi_vdorec_app_mem_stop_callback(void);
static void mmi_vdorec_app_mem_success_callback(void);
static void mmi_vdorec_app_mem_cancel_callback(mmi_frm_appmem_evt_struct* event);
static void mmi_vdorec_free_app_mem(void);
#endif
#endif

static void mmi_vdorec_delete_group(void);
static mmi_ret mmi_vdorec_listen_key_proc(mmi_event_struct *evt);
static void mmi_vdorec_auto_adjust_size_and_format(void);
static void mmi_vdorec_drv_not_ready_process(void);
static void mmi_vdorec_storage_change(void);

#ifdef __VDOREC_FEATURE_RSK_DELETE__
void mmi_vdorec_preview_continue(void);
#endif

static MMI_BOOL mmi_vdorec_check_valid_drv(void);

static MMI_BOOL mmi_vdorec_disable_gprs(void);
static void mmi_vdorec_allow_gprs(void);
static void mmi_vdorec_query_info_table(void);

static BOOL mmi_vdorec_map_search(U16 idx,U32*val,VdoRecGenMapStruct* pTable,S32 count);



/****************************************************************************
* Setting command map                                                                
*****************************************************************************/
VdoRecGenMapStruct vdorec_qty_mdi2mmi_map[4] = 
{
	{MDI_VIDEO_REC_QTY_LOW,VDOREC_SETTING_VIDEO_QTY_LOW},
	{MDI_VIDEO_REC_QTY_NORMAL,VDOREC_SETTING_VIDEO_QTY_NORMAL},
	{MDI_VIDEO_REC_QTY_FINE,VDOREC_SETTING_VIDEO_QTY_FINE},
	{MDI_VIDEO_REC_QTY_HIGH,VDOREC_SETTING_VIDEO_QTY_HIGH}
};

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QVGA__
#define VDORECSIZEMAPTALBECOUNT 13
#else
#define VDORECSIZEMAPTALBECOUNT 12
#endif

VdoRecGenMapStruct vdorec_size_mdi2mmi_map[VDORECSIZEMAPTALBECOUNT] = 
{
	{MDI_VIDEO_REC_RESOLUTION_176x208,VDOREC_SETTING_VIDEO_SIZE_WP_QCIF1},
	{MDI_VIDEO_REC_RESOLUTION_240x320,VDOREC_SETTING_VIDEO_SIZE_WP_QVGA},
	{MDI_VIDEO_REC_RESOLUTION_240x400,VDOREC_SETTING_VIDEO_SIZE_WP_WQVGA},
	{MDI_VIDEO_REC_RESOLUTION_320x480,VDOREC_SETTING_VIDEO_SIZE_WP_HVGA},
	{MDI_VIDEO_REC_RESOLUTION_480x800,VDOREC_SETTING_VIDEO_SIZE_WP_WVGA},
	{MDI_VIDEO_REC_RESOLUTION_640x480,VDOREC_SETTING_VIDEO_SIZE_VGA},
	{MDI_VIDEO_REC_RESOLUTION_640x368,VDOREC_SETTING_VIDEO_SIZE_NHD},
	{MDI_VIDEO_REC_RESOLUTION_480x320,VDOREC_SETTING_VIDEO_SIZE_HVGA},
	{MDI_VIDEO_REC_RESOLUTION_432x240,VDOREC_SETTING_VIDEO_SIZE_CIF2},
	{MDI_VIDEO_REC_RESOLUTION_400x240,VDOREC_SETTING_VIDEO_SIZE_WQVGA},
	{MDI_VIDEO_REC_RESOLUTION_352x288,VDOREC_SETTING_VIDEO_SIZE_CIF},
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QVGA__	
	{MDI_VIDEO_REC_RESOLUTION_320x240,VDOREC_SETTING_VIDEO_SIZE_QVGA},
#endif	
	{MDI_VIDEO_REC_RESOLUTION_176x144,VDOREC_SETTING_VIDEO_SIZE_QCIF}
};

VdoRecGenMapStruct vdorec_format_mdi2mmi_map[4] = 
{
	{MDI_VIDEO_VIDEO_FORMAT_3GP,VDOREC_SETTING_VIDEO_FORMAT_3GP},
	{MDI_VIDEO_VIDEO_FORMAT_MP4,VDOREC_SETTING_VIDEO_FORMAT_MP4},
	{MDI_VIDEO_VIDEO_FORMAT_MJPEG,VDOREC_SETTING_VIDEO_FORMAT_MJPEG},
	{MDI_VIDEO_VIDEO_FORMAT_H264,VDOREC_SETTING_VIDEO_FORMAT_H264}
};




/*********** WB ***********/
const U8 vdorec_wb_command_map[VDOREC_SETTING_WB_COUNT + 1] = 
{
    MDI_VIDEO_WB_AUTO,  /* CAMREA_SETTING_WB_AUTO */
    MDI_VIDEO_WB_DAYLIGHT,  /* VDOREC_SETTING_WB_DAYLIGHT */
    MDI_VIDEO_WB_TUNGSTEN,  /* VDOREC_SETTING_WB_TUNGSTEN */
    MDI_VIDEO_WB_FLUORESCENT,   /* VDOREC_SETTING_WB_FLUORESCENT */
    MDI_VIDEO_WB_CLOUD, /* VDOREC_SETTING_WB_CLOUD */
    MDI_VIDEO_WB_INCANDESCENCE, /* VDOREC_SETTING_WB_INCANDESCENCE */

    DUMMY_COMMAND
};

/*********** EV ***********/
const U8 vdorec_ev_command_map[VDOREC_SETTING_EV_COUNT + 1] = 
{
#ifdef __VDOREC_FEATURE_EV_4__
    MDI_VIDEO_EV_N4,    /* VDOREC_SETTING_EV_N4 */
#endif 

#ifdef __VDOREC_FEATURE_EV_3__
    MDI_VIDEO_EV_N3,    /* VDOREC_SETTING_EV_N3 */
#endif 

#ifdef __VDOREC_FEATURE_EV_2__
    MDI_VIDEO_EV_N2,    /* VDOREC_SETTING_EV_N2 */
#endif 

    MDI_VIDEO_EV_N1,    /* VDOREC_SETTING_EV_N1 */
    MDI_VIDEO_EV_0,     /* VDOREC_SETTING_EV_0 */
    MDI_VIDEO_EV_P1,    /* VDOREC_SETTING_EV_P1 */

#ifdef __VDOREC_FEATURE_EV_2__
    MDI_VIDEO_EV_P2,    /* VDOREC_SETTING_EV_P2 */
#endif 

#ifdef __VDOREC_FEATURE_EV_3__
    MDI_VIDEO_EV_P3,    /* VDOREC_SETTING_EV_P3 */
#endif 

#ifdef __VDOREC_FEATURE_EV_4__
    MDI_VIDEO_EV_P4,    /* VDOREC_SETTING_EV_P4 */
#endif 

    DUMMY_COMMAND
};

/*********** Banding ***********/
const U8 vdorec_banding_command_map[VDOREC_SETTING_BANDING_COUNT + 1] = 
{
    MDI_VIDEO_BANDING_50HZ,
    MDI_VIDEO_BANDING_60HZ,

    DUMMY_COMMAND
};

/*********** EFFECT ***********/
const U8 vdorec_effect_command_map[VDOREC_SETTING_EFFECT_COUNT + 1] = 
{
    MDI_VIDEO_EFFECT_NOMRAL,
    MDI_VIDEO_EFFECT_GRAYSCALE,
    MDI_VIDEO_EFFECT_SEPIA,
    MDI_VIDEO_EFFECT_SEPIA_GREEN,
    MDI_VIDEO_EFFECT_SEPIA_BLUE,
    MDI_VIDEO_EFFECT_COLOR_INVERT,
    MDI_VIDEO_EFFECT_GRAY_INVERT,
    MDI_VIDEO_EFFECT_BLACKBOARD,
    MDI_VIDEO_EFFECT_WHITEBOARD,
    MDI_VIDEO_EFFECT_COPPER_CARVING,
    MDI_VIDEO_EFFECT_BLUE_CARVING,
    MDI_VIDEO_EFFECT_EMBOSSMENT,
    MDI_VIDEO_EFFECT_CONTRAST,
    MDI_VIDEO_EFFECT_JEAN,
    MDI_VIDEO_EFFECT_SKETCH,
    MDI_VIDEO_EFFECT_OIL,
    DUMMY_COMMAND
};

/*********** Video Size ***********/
const U8 vdorec_video_size_command_map[VDOREC_SETTING_VIDEO_SIZE_COUNT + 1] = 
{
	MDI_VIDEO_VIDEO_SIZE_WP_QCIF,
	MDI_VIDEO_VIDEO_SIZE_WP_QVGA,
	MDI_VIDEO_VIDEO_SIZE_WP_WQVGA,
	MDI_VIDEO_VIDEO_SIZE_WP_HVGA,
	MDI_VIDEO_VIDEO_SIZE_WP_WVGA,
    MDI_VIDEO_VIDEO_SIZE_QCIF,
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QVGA__
    MDI_VIDEO_VIDEO_SIZE_QVGA,
#endif 
	MDI_VIDEO_VIDEO_SIZE_CIF,
	MDI_VIDEO_VIDEO_SIZE_WQVGA,
	MDI_VIDEO_VIDEO_SIZE_CIF_2,
	MDI_VIDEO_VIDEO_SIZE_HVGA,
	MDI_VIDEO_VIDEO_SIZE_NHD,
	MDI_VIDEO_VIDEO_SIZE_VGA,

    DUMMY_COMMAND
};

/*********** Video Qty ***********/
const U8 vdorec_video_qty_command_map[VDOREC_SETTING_VIDEO_QTY_COUNT + 1] = 
{
#ifdef __VDOREC_FEATURE_VIDEO_QTY_LOW__
    MDI_VIDEO_REC_QTY_LOW,
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_QTY_NORMAL__
    MDI_VIDEO_REC_QTY_NORMAL,
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_QTY_HIGH__
    MDI_VIDEO_REC_QTY_HIGH,
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_QTY_FINE__
        MDI_VIDEO_REC_QTY_FINE,
#endif 

    DUMMY_COMMAND
};


/*********** Video Format ***********/
const U8 vdorec_video_format_command_map[VDOREC_SETTING_VIDEO_FORMAT_COUNT + 1] = 
{
    MDI_VIDEO_VIDEO_FORMAT_3GP,
    MDI_VIDEO_VIDEO_FORMAT_MP4,
    MDI_VIDEO_VIDEO_FORMAT_MJPEG,
    MDI_VIDEO_VIDEO_FORMAT_H264,

    DUMMY_COMMAND
};

#ifdef __VDOREC_FEATURE_TIME_LIMIT__

/*************time limit ************/
const U32 vdorec_video_time_limit_command_map[VDOREC_SETTING_TIME_LIMIT_COUNT + 1] = 
{
    0,                              /* no limit */
    VDOREC_FEATURE_TIME_LIMIT_1,
    VDOREC_FEATURE_TIME_LIMIT_2,
    VDOREC_FEATURE_TIME_LIMIT_3,
    
    DUMMY_COMMAND
};

#endif  /*__VDOREC_FEATURE_TIME_LIMIT__*/

#ifdef __VDOREC_FEATURE_SIZE_LIMIT__

/*************size limit ************/
const U32 vdorec_video_size_limit_command_map[VDOREC_SETTING_SIZE_LIMIT_COUNT + 1] = 
{
    0,                              /* no limit */
    VDOREC_FEATURE_SIZE_LIMIT_1,
    VDOREC_FEATURE_SIZE_LIMIT_2,
    VDOREC_FEATURE_SIZE_LIMIT_3,
    
    DUMMY_COMMAND
};
#endif  /*__VDOREC_FEATURE_SIZE_LIMIT__*/


#ifdef __VDOREC_FEATURE_QTY_TABLE_ENABLE__
typedef struct 
{
    U16 qty;
    U16 codec;
    U16 resolution;
    U16 birate;
} mmi_vdorec_qty_mapping_table_struct;
#endif


/*****************************************************************************
*
* Applcation Related
*
*****************************************************************************/
#ifdef __MMI_SCREEN_LOCK_ANY_TIME__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_notify_screen_lock_hdlr
 * DESCRIPTION
 *  VDOREC handle screen  lock function.
 * PARAMETERS
 *  evt     [IN]        The event for lock screen
 * RETURNS
 *  mmi_ret event handle result
 *****************************************************************************/
extern mmi_ret mmi_vdorec_notify_screen_lock_hdlr(mmi_event_struct *evt)
{
   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scr_locker_pre_lock_evt_struct* lock_event;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING:
		{
			if ((mmi_frm_group_get_active_id()== g_vdorec_cntx.cur_gid) &&  (NULL != g_vdorec_cntx.cur_gid))
			{
			    if(g_vdorec_cntx.state == VDOREC_STATE_EXIT)
            	{
                	return MMI_RET_OK;
            	}
           		else if(g_vdorec_cntx.state == VDOREC_STATE_PAUSE || g_vdorec_cntx.state == VDOREC_STATE_RECORD)
           		{
                	lock_event = (mmi_scr_locker_pre_lock_evt_struct*)evt;

                	if(lock_event->lock_mode == MMI_SCR_LOCKER_LOCK_MODE_POWER_KEY)
                	{
                    	return MMI_RET_ERR;
                	}
                	else if(lock_event->lock_mode == MMI_SCR_LOCKER_LOCK_MODE_AUTO_LOCK)
                	{
                    	return MMI_RET_ERR;
                	}
            	}
           		else
           		{
                	return MMI_RET_ERR;
            	}	
			}         
        	break;
		}
       default:
       	    return MMI_RET_OK;
    }
    return MMI_RET_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_post_to_parent
 * DESCRIPTION
 *  post event
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_vdorec_post_to_parent(U16 evt_id, CHAR *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_vdorec_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
    MMI_FRM_INIT_GROUP_EVENT(&evt, sizeof(cui_vdorec_event_struct), g_vdorec_cntx.cur_gid); //? 
    
    evt.evt_id = evt_id;
    evt.file_path = file_path;
    mmi_frm_group_post_to_parent (g_vdorec_cntx.cur_gid, (mmi_group_event_struct *)&evt);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_enter_from_cui
 * DESCRIPTION
 *  Entry video recorder and record a video with requested size 
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
void mmi_vdorec_enter_from_cui(mmi_id cur_gid, p_cui_vdorec_run_struct p_args)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_FROM_EXTERNAL);

    {
        U16 buf_filepath[SRV_FMGR_PATH_BUFFER_SIZE];

        //mmi_vdorec_load_setting();
        mmi_vdoply_get_storage_file_path((CHAR *)buf_filepath);
        
        if (mmi_vdorec_entry_app_pre_check((CHAR *)buf_filepath) == MMI_FALSE)
        {
            return; /* pre check failed, video recorder is not available now. */
        }
    }

    if (mmi_frm_group_is_present(g_vdorec_cntx.cur_gid))
    {
        mmi_vdorec_delete_group();
    }
    
    //mmi_vdorec_load_setting();    
    g_vdorec_cntx.is_ext_req = MMI_TRUE;
    g_vdorec_cntx.is_entry_from_cui = MMI_TRUE;
    g_vdorec_cntx.is_use_ext_req_path = MMI_FALSE;       
    g_vdorec_cntx.ext_req_size = p_args->max_file_size;
    g_vdorec_cntx.ext_rec_time = p_args->max_record_time;
    
#if defined(__VDOREC_FEATURE_SLIM_UE__) && defined(__VDOREC_FEATURE_PREVIEW_SAVED_FILE__)
    g_vdorec_cntx.is_enter_play_video_scr = FALSE;
#endif
    
    /* video cant record so accurate */
    if (g_vdorec_cntx.ext_req_size < mmi_vdorec_get_min_external_request_size())
    {
        mmi_vdorec_post_to_parent(CUI_VDOREC_RECORD_EVENT_RESULT_FAILED, NULL);
        return ;
    }
    
    if (p_args->file_path != NULL)
    {
        g_vdorec_cntx.is_use_ext_req_path = MMI_TRUE;        
        mmi_ucs2ncpy((CHAR *)g_vdorec_cntx.filepath, (CHAR *)p_args->file_path, SRV_FMGR_PATH_BUFFER_SIZE);
    }
    
#if defined(__MMI_OP12_CAMERA_VDOREC_CUSTOMIZE__) && defined(__VDOREC_FEATURE_VIDEO_SIZE_SQCIF__)
    g_vdorec_cntx.ext_video_size = VDOREC_SETTING_VIDEO_SIZE_SQCIF;
    g_vdorec_cntx.old_video_size = g_vdorec_cntx.setting.video_size; /* store video size, store back after return */
#endif
    
#ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__
    g_vdorec_cntx.old_call_mode = FALSE;
#endif

    /* enter video recorder */
    mmi_frm_group_enter(cur_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    g_vdorec_cntx.cur_gid = cur_gid;

#ifndef __MMI_VIDEO_RECORDER_SLIM__    
#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    if (g_vdorec_cntx.app_mem_bufer == NULL)
    {
        if (!mmi_vdorec_malloc_app_mem())
        {
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_VDOREC,
                IMG_ID_VDOREC_APP_ICON,
                VDOREC_APP_MEMORY_BUFFER_SIZE,
                mmi_vdorec_app_mem_success_callback);
            mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_VDOREC, mmi_vdorec_app_mem_cancel_callback);
            return;
        }
    }
#endif
#endif

    g_vdorec_cntx.is_giveup_popup_rotate = MMI_TRUE;
    mmi_vdorec_entry_app_internal();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_get_min_external_request_size
 * DESCRIPTION
 *  get minal external request size (in K), reasonal size for 1 sec
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
U32 mmi_vdorec_get_min_external_request_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MJPG_ENCODE
    /* Motion JPEG */
    return 60;
#else
    /* MPEG4 */
    return 30;
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_is_in_app
 * DESCRIPTION
 *  is in video recorder app or not
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL mmi_vdorec_is_in_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_vdorec_cntx.state != VDOREC_STATE_EXIT)
        return TRUE;
    else
        return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_hilight_app
 * DESCRIPTION
 *  highlight vdorec menuitem
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_hilight_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HILIGHT_APP);

    SetLeftSoftkeyFunction(mmi_vdorec_lauch, KEY_EVENT_UP);
}

#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
/*****************************************************************************
* FUNCTION
*  mmi_vdorec_malloc_app_mem
* DESCRIPTION
*  apply app based ASM
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL mmi_vdorec_malloc_app_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_vdorec_cntx.app_mem_bufer  
        = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_VDOREC, VDOREC_APP_MEMORY_BUFFER_SIZE);

    if (g_vdorec_cntx.app_mem_bufer == NULL)
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
*  mmi_vdorec_free_app_mem
* DESCRIPTION
*  free app based ASM
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_free_app_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_vdorec_cntx.app_mem_bufer)
    {
        applib_mem_ap_free(g_vdorec_cntx.app_mem_bufer);
    
        g_vdorec_cntx.app_mem_bufer = NULL;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_app_mem_stop_callback
* DESCRIPTION
*  app mem stop call back
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_app_mem_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Free Memory */
    mmi_vdorec_free_app_mem();
    
    /*Notify MMI that this application is already stopped */
    applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_VDOREC, KAL_TRUE);
    
    if (mmi_frm_group_is_present(g_vdorec_cntx.cur_gid))
    {
        mmi_vdorec_delete_group();
    }
    
    g_vdorec_cntx.gdi_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    g_vdorec_cntx.app_mem_bufer = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_app_mem_cancel_callback
 * DESCRIPTION
 *  init vdorec applcation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_app_mem_cancel_callback(mmi_frm_appmem_evt_struct* event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_vdorec_delete_group();        
    mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_VDOREC, NULL);
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_app_mem_success_callback
* DESCRIPTION
*  malloc memory success callback
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_app_mem_success_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_VDOREC, mmi_vdorec_app_mem_cancel_callback);
    
    mmi_vdorec_lauch();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_init_app
 * DESCRIPTION
 *  init vdorec applcation
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_INIT_APP);

    g_vdorec_cntx.state = VDOREC_STATE_EXIT;
    g_vdorec_cntx.last_error = MDI_RES_VDOREC_SUCCEED;
    g_vdorec_cntx.is_saving = FALSE;
    g_vdorec_cntx.is_sub_display = FALSE;
    g_vdorec_cntx.is_setting_loaded = FALSE;

    g_vdorec_cntx.zoom_limit = 100; /*first time enter in, init zoom limit*/
    g_vdorec_cntx.cur_gid = GRP_ID_INVALID;
    g_vdorec_cntx.gdi_layer_handle = GDI_LAYER_EMPTY_HANDLE;
	g_vdorec_cntx.have_saved = MMI_FALSE;
	g_vdorec_cntx.is_end_key = MMI_FALSE;
	g_vdorec_cntx.is_show_saving = MMI_TRUE;

#ifndef __MMI_VIDEO_RECORDER_SLIM__	
#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    applib_mem_ap_register(APPLIB_MEM_AP_ID_VDOREC,STR_ID_VDOREC_APP_NAME,
        IMG_ID_VDOREC_APP_ICON, mmi_vdorec_app_mem_stop_callback);
#endif
#endif
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_inc_ev
 * DESCRIPTION
 *  increase ev value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_EV__
static void mmi_vdorec_inc_ev(void)
{
#if !defined(__VDOREC_FEATURE_FTE_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_EV_INC, g_vdorec_cntx.setting.ev);

    if (g_vdorec_cntx.setting.ev < VDOREC_SETTING_EV_COUNT - 1)
    {
        g_vdorec_cntx.setting.ev++;

        mdi_video_rec_update_para_ev(vdorec_ev_command_map[g_vdorec_cntx.setting.ev]);

        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_EV);
        mmi_vdorec_blt_screen();

        if (g_vdorec_cntx.is_first_time_ev)
        {
            /* first time ev, will wait longer to ev again */
            gui_start_timer(VDOREC_INC_INTERVAL_FIRST, mmi_vdorec_inc_ev);
            g_vdorec_cntx.is_first_time_ev = FALSE;
        }
        else
        {
            gui_start_timer(VDOREC_INC_INTERVAL, mmi_vdorec_inc_ev);
        }
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_dec_ev
 * DESCRIPTION
 *  decrease ev value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_dec_ev(void)
{
#if !defined(__VDOREC_FEATURE_FTE_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DEC_EV, g_vdorec_cntx.setting.ev);

    if (g_vdorec_cntx.setting.ev > 0)
    {
        g_vdorec_cntx.setting.ev--;

        mdi_video_rec_update_para_ev(vdorec_ev_command_map[g_vdorec_cntx.setting.ev]);

        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_EV);

        mmi_vdorec_blt_screen();

        if (g_vdorec_cntx.is_first_time_ev)
        {
            /* first time ev, will wait longer to ev again */
            gui_start_timer(VDOREC_INC_INTERVAL_FIRST, mmi_vdorec_dec_ev);
            g_vdorec_cntx.is_first_time_ev = FALSE;
        }
        else
        {
            gui_start_timer(VDOREC_INC_INTERVAL, mmi_vdorec_dec_ev);
        }
    }
#endif
}
#endif

#if defined(__VDOREC_FEATURE_EV__) && !defined(__VDOREC_FEATURE_FTE_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_inc_ev_key_press_hdlr
 * DESCRIPTION
 *  right arrow press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_inc_ev_key_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_EV_INC_PRESS);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
    }

#ifdef __VDOREC_FEATURE_RECORDING_EV__
    /* not in preview & record state */
    if ((g_vdorec_cntx.state != VDOREC_STATE_PREVIEW) &&
        (g_vdorec_cntx.state != VDOREC_STATE_RECORD) && (g_vdorec_cntx.state != VDOREC_STATE_PAUSE))
    {
        return;
    }
#else /* __VDOREC_FEATURE_RECORDING_EV__ */ 
    /* not in preview state */
    if (g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_RECORDING_EV__ */ 

    if (!g_vdorec_cntx.is_ev_inc_key_pressed)
    {
        g_vdorec_cntx.is_ev_inc_key_pressed = TRUE;
        g_vdorec_cntx.is_first_time_ev = TRUE;
        mmi_vdorec_inc_ev();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_inc_ev_key_release_hdlr
 * DESCRIPTION
 *  right arrow release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_inc_ev_key_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_EV_INC_RELEASE);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
        mmi_vdorec_watchdog_time_out_handler();
    }

    /* cancel timer */
    gui_cancel_timer(mmi_vdorec_inc_ev);
    g_vdorec_cntx.is_ev_inc_key_pressed = FALSE;

#ifdef __VDOREC_FEATURE_RECORDING_EV__
    /* not in preview & record state */
    if ((g_vdorec_cntx.state != VDOREC_STATE_PREVIEW) &&
        (g_vdorec_cntx.state != VDOREC_STATE_RECORD) && (g_vdorec_cntx.state != VDOREC_STATE_PAUSE))
    {
        return;
    }
#else /* __VDOREC_FEATURE_RECORDING_EV__ */ 
    /* not in preview state */
    if (g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_RECORDING_EV__ */ 

    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_EV);
    mmi_vdorec_blt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_dec_ev_key_press_hdlr
 * DESCRIPTION
 *  left arrow press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_dec_ev_key_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_EV_DEC_PRESS);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
    }

#ifdef __VDOREC_FEATURE_RECORDING_EV__
    /* not in preview & record state */
    if ((g_vdorec_cntx.state != VDOREC_STATE_PREVIEW) &&
        (g_vdorec_cntx.state != VDOREC_STATE_RECORD) && (g_vdorec_cntx.state != VDOREC_STATE_PAUSE))
    {
        return;
    }
#else /* __VDOREC_FEATURE_RECORDING_EV__ */ 
    /* not in preview state */
    if (g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_RECORDING_EV__ */ 

    if (!g_vdorec_cntx.is_ev_dec_key_pressed)
    {
        g_vdorec_cntx.is_ev_dec_key_pressed = TRUE;
        g_vdorec_cntx.is_first_time_ev = TRUE;
        mmi_vdorec_dec_ev();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_dec_ev_key_release_hdlr
 * DESCRIPTION
 *  left arrow release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_dec_ev_key_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_EV_DEC_RELEASE);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
        mmi_vdorec_watchdog_time_out_handler();
    }

    /* cancel timer */
    gui_cancel_timer(mmi_vdorec_dec_ev);
    g_vdorec_cntx.is_ev_dec_key_pressed = FALSE;

#ifdef __VDOREC_FEATURE_RECORDING_EV__
    /* not in preview & record state */
    if ((g_vdorec_cntx.state != VDOREC_STATE_PREVIEW) &&
        (g_vdorec_cntx.state != VDOREC_STATE_RECORD) && (g_vdorec_cntx.state != VDOREC_STATE_PAUSE))
    {
        return;
    }
#else /* __VDOREC_FEATURE_RECORDING_EV__ */ 
    /* not in preview state */
    if (g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_RECORDING_EV__ */ 

    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_EV);
    mmi_vdorec_blt_screen();
}
#endif /* __VDOREC_FEATURE_EV__ */ 

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_turn_on_led_highlight
 * DESCRIPTION
 *  turn on led highlight
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_turn_on_led_highlight(void)
{
#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 duty;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    duty = g_vdorec_cntx.setting.led_value;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_TURN_ON_LED, duty);

#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__
    if (g_vdorec_cntx.setting.led_highlight)
    {
        custom_start_flashlight(1, 1, 1, duty);
    }
#else /* __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__ */ 
    /* __VDOREC_FEATURE_LED_HIGHLIGHT_7_COLOR__ */
    switch (g_vdorec_cntx.setting.led_highlight)
    {
        case VDOREC_SETTING_LED_HIGHLIGHT_WHITE:
            custom_start_flashlight(1, 1, 1, duty);
            break;

        case VDOREC_SETTING_LED_HIGHLIGHT_RED:
            custom_start_flashlight(1, 0, 0, duty);
            break;

        case VDOREC_SETTING_LED_HIGHLIGHT_GREEN:
            custom_start_flashlight(0, 1, 0, duty);
            break;

        case VDOREC_SETTING_LED_HIGHLIGHT_BLUE:
            custom_start_flashlight(0, 0, 1, duty);
            break;

        case VDOREC_SETTING_LED_HIGHLIGHT_YELLOW:
            custom_start_flashlight(1, 1, 0, duty);
            break;

        case VDOREC_SETTING_LED_HIGHLIGHT_PURPLE:
            custom_start_flashlight(1, 0, 1, duty);
            break;

        case VDOREC_SETTING_LED_HIGHLIGHT_CYAN:
            custom_start_flashlight(0, 1, 1, duty);
            break;
    }
#endif /* __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__ */ 

#endif /* __VDOREC_FEATURE_LED_HIGHLIGHT__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_turn_off_led_highlight
 * DESCRIPTION
 *  turn off led highlight
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_turn_off_led_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_TURN_OFF_LED);

    custom_stop_flashlight();
#endif 
}


#ifndef __MMI_VIDEO_RECORDER_SLIM__

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_wb_hotkey_press
 * DESCRIPTION
 *  wb hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
static void mmi_vdorec_video_size_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR str_buf[256];
    S32 video_width;
    S32 video_height;
    S32 current_preview_layer_width;
    S32 current_preview_layer_height;
    S32 previous_preview_layer_width;
    S32 previous_preview_layer_height;
    mdi_camera_zoom_info p_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_VIDEO_SIZE_HOTKEY_PRESS);

    /*if not in preview state, will forbit hotkey*/
    if(g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }

    if (g_vdorec_cntx.setting.video_size < VDOREC_SETTING_VIDEO_SIZE_COUNT - 1)
    {
        g_vdorec_cntx.setting.video_size++;
    }
    else
    {
        g_vdorec_cntx.setting.video_size = 0;
    }
    
    mmi_ucs2cpy((CHAR *) str_buf, (CHAR *) L"[ ");
    mmi_ucs2cat((CHAR *) str_buf, (CHAR *) GetString(STR_ID_VDOREC_VIDEO_SIZE));
    mmi_ucs2cat((CHAR *) str_buf, (CHAR *) L" ]");
    
    /* draw osd */
    mmi_vdorec_set_hint(
        (CHAR *) str_buf,
        (CHAR *) GetString((U16) (g_vdorec_cntx.setting.video_size + STR_ID_VDOREC_VIDEO_SIZE_START + 1)),
        HINT_POPUP_FADE_TIME);
    
    /*video size changed, so need stop and then start video*/
    mdi_video_rec_preview_stop();
    g_vdorec_cntx.is_preview_started = MMI_FALSE;

    /*get the previous preview layer width*/
    gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);
    gdi_layer_get_dimension(&previous_preview_layer_width, &previous_preview_layer_height);
    gdi_layer_pop_and_restore_active();

    mmi_vdorec_resize_preview_layer();

    /*get the current preview layer width*/
    gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);
    gdi_layer_get_dimension(&current_preview_layer_width, &current_preview_layer_height);
    gdi_layer_pop_and_restore_active();

    /*if the preview windown width and height has changed , we should clear preview layer date, for it maybe confused*/
    if ((previous_preview_layer_width != current_preview_layer_width) ||
        (previous_preview_layer_height != current_preview_layer_height))
    {
        gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
    }
    if (!mmi_vdorec_is_in_bgcall())
    {
        mmi_vdorec_start_preview();
    }

    /*if video size changed, the zoom value should be reset*/
    g_vdorec_cntx.setting.zoom = VDOREC_DEFAULT_SETTING_ZOOM;     
    mdi_video_rec_update_para_zoom(g_vdorec_cntx.setting.zoom);
    /*video size changed, need reget the zoom limit*/
    mmi_vdorec_get_video_size(&video_width, &video_height);

    mdi_video_rec_query_zoom_info(&p_info);
    g_vdorec_cntx.zoom_limit = p_info.max_zoom_factor;
    g_vdorec_cntx.max_zoom_steps = p_info.zoom_steps;

    /* if zoom is like 2.6x, round it to 2.0x */
    //g_vdorec_cntx.zoom_limit /= 10;
    //g_vdorec_cntx.zoom_limit *= 10;

    if (g_vdorec_cntx.zoom_limit < 100)
    {
        g_vdorec_cntx.zoom_limit = 100;
    }

#ifdef __VDOREC_HIDE_HINT__
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_STATUS | VDOREC_OSD_COMPONENT_ZOOM);
#else
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_HINT | VDOREC_OSD_COMPONENT_STATUS | VDOREC_OSD_COMPONENT_ZOOM);
#endif

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        /*if enter new screen ,should redraw full screen, for some area is use layer background to fill color*/
        mmi_vdorec_set_merge_region(0,0, g_vdorec_cntx.lcd_width, g_vdorec_cntx.lcd_height);
    }
	#endif

    mmi_vdorec_blt_screen();
}
#endif


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_video_qty_hotkey_press
* DESCRIPTION
*  video qty hotkey press hdlr
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __VDOREC_FEATURE_VIDEO_QTY__
static void mmi_vdorec_video_qty_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR str_buf[256];
    S32 previous_video_width;
    S32 previous_video_height;
    S32 current_video_width;
    S32 current_video_height;
    S32 current_preview_layer_width;
    S32 current_preview_layer_height;
    S32 previous_preview_layer_width;
    S32 previous_preview_layer_height;
    S32 layer_offset_x, layer_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_QTY_HOTKEY_PRESS);

    /*if not in preview state, will forbit hotkey*/
    if(g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }

    mmi_vdorec_get_video_size(&previous_video_width, &previous_video_height);

    if (g_vdorec_cntx.setting.video_qty < VDOREC_SETTING_VIDEO_QTY_COUNT - 1)
    {
        g_vdorec_cntx.setting.video_qty++;
    }
    else
    {
        g_vdorec_cntx.setting.video_qty = 0;
    }

    mmi_ucs2cpy((CHAR *) str_buf, (CHAR *) L"[ ");
    mmi_ucs2cat((CHAR *) str_buf, (CHAR *) GetString(STR_ID_VDOREC_VIDEO_QTY));
    mmi_ucs2cat((CHAR *) str_buf, (CHAR *) L" ]");

    /* draw osd */
    mmi_vdorec_set_hint(
        (CHAR *) str_buf,
        (CHAR *) GetString((U16) (g_vdorec_cntx.setting.video_qty + STR_ID_VDOREC_VIDEO_QTY_START  + 1)),
        HINT_POPUP_FADE_TIME);

    mmi_vdorec_auto_adjust_size_and_format();
    mmi_vdorec_get_video_size(&current_video_width, &current_video_height);

    /* for quality only used in preview start, so I stop and restart preview*/
    mdi_video_rec_preview_stop();

    // preview windown changed, so need to clear video area
        gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);
        gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();

    /*get the previous preview layer width*/
    gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);
    gdi_layer_get_dimension(&previous_preview_layer_width, &previous_preview_layer_height);
    gdi_layer_pop_and_restore_active();

    mmi_vdorec_resize_preview_layer();

    /*get the current preview layer width*/
    gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);
    gdi_layer_get_dimension(&current_preview_layer_width, &current_preview_layer_height);
    gdi_layer_pop_and_restore_active();
    
    /*if the preview windown width and height has changed , we should clear preview layer date, for it maybe confused*/
    if ((previous_preview_layer_width != current_preview_layer_width) ||
        (previous_preview_layer_height != current_preview_layer_height))
    {
        gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();

    #ifdef GDI_USING_LAYER_BACKGROUND
        gdi_layer_set_background(GDI_COLOR_BLACK);
    #endif

    #ifdef __VDOREC_FEATURE_QVGA_RECORD_SUPPORT__
    #ifdef __VDOREC_HIDE_HINT__
        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_STATUS | VDOREC_OSD_COMPONENT_ZOOM);
    #else
        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_HINT | VDOREC_OSD_COMPONENT_STATUS | VDOREC_OSD_COMPONENT_ZOOM);
    #endif
    #else
    #ifdef __VDOREC_HIDE_HINT__
        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_STATUS);
    #else
        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_HINT | VDOREC_OSD_COMPONENT_STATUS);
    #endif
    #endif
    }
    else
    {
    #ifdef GDI_USING_LAYER_BACKGROUND
        gdi_layer_set_background(GDI_COLOR_BLACK);
    #endif

    #ifdef __VDOREC_FEATURE_QVGA_RECORD_SUPPORT__
    #ifdef __VDOREC_HIDE_HINT__
        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_STATUS | VDOREC_OSD_COMPONENT_ZOOM);
    #else
        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_HINT | VDOREC_OSD_COMPONENT_STATUS | VDOREC_OSD_COMPONENT_ZOOM);
    #endif
    #else
    #ifdef __VDOREC_HIDE_HINT__
        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_STATUS);
    #else
        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_HINT | VDOREC_OSD_COMPONENT_STATUS);
    #endif
    #endif
    }
    
    #ifdef __VDOREC_USING_BLT_REGION__
    /*if enter new screen ,should redraw full screen, for some area is use layer background to fill color*/
    mmi_vdorec_set_merge_region(0,0, g_vdorec_cntx.lcd_width, g_vdorec_cntx.lcd_height);
    #endif	  

    mmi_vdorec_blt_screen();

    if (!mmi_vdorec_is_in_bgcall())
    {
        mmi_vdorec_start_preview();
    }
}
#endif

/*****************************************************************************
* FUNCTION
*  mmi_vdorec_night_hotkey_press
* DESCRIPTION
*  night mode hotkey press hdlr
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __VDOREC_FEATURE_NIGHT__
static void mmi_vdorec_night_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR str_buf[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_NIGHT_HOTKEY_PRESS);
 
    /*if not in preview state, will forbit hotkey*/
    if(g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }

    if (g_vdorec_cntx.setting.night < VDOREC_SETTING_NIGHT_COUNT - 1)
    {
        g_vdorec_cntx.setting.night++;
    }
    else
    {
        g_vdorec_cntx.setting.night = 0;
    }
    
    mmi_ucs2cpy((CHAR *) str_buf, (CHAR *) L"[ ");
    mmi_ucs2cat((CHAR *) str_buf, (CHAR *) GetString(STR_ID_VDOREC_NIGHT));
    mmi_ucs2cat((CHAR *) str_buf, (CHAR *) L" ]");
    
    /* draw osd */
    mmi_vdorec_set_hint(
        (CHAR *) str_buf,
        (CHAR *) GetString((U16) (g_vdorec_cntx.setting.night + STR_ID_VDOREC_NIGHT_START + 1)),
        HINT_POPUP_FADE_TIME);
    
#ifdef __VDOREC_HIDE_HINT__
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_STATUS);
#else
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_STATUS | VDOREC_OSD_COMPONENT_HINT);
#endif
    
    mdi_video_rec_update_para_night(g_vdorec_cntx.setting.night);
    
    mmi_vdorec_blt_screen();
}
#endif 

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_wb_hotkey_press
 * DESCRIPTION
 *  wb hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_WB__
static void mmi_vdorec_wb_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR str_buf[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_WB_HOTKEY_PRESS);
 
    /*if not in preview state, will forbit hotkey*/
    if(g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }

    if (g_vdorec_cntx.setting.wb < g_vdorec_cntx.wb_item)
    {
        g_vdorec_cntx.setting.wb++;
		if(g_vdorec_cntx.setting.wb == g_vdorec_cntx.wb_item)
		{
			g_vdorec_cntx.setting.wb = 0;
		}
    }
    else
    {
        g_vdorec_cntx.setting.wb = 0;
    }
    
    mmi_ucs2cpy((CHAR *) str_buf, (CHAR *) L"[ ");
    mmi_ucs2cat((CHAR *) str_buf, (CHAR *) GetString(STR_ID_VDOREC_WB));
    mmi_ucs2cat((CHAR *) str_buf, (CHAR *) L" ]");
    
    /* update osd */
    mmi_vdorec_set_hint(
        (CHAR *) str_buf,
        (CHAR *) GetString((U16) (support_wb_item[g_vdorec_cntx.setting.wb] + STR_ID_VDOREC_WB_START + 1)),
        HINT_POPUP_FADE_TIME);
    
#ifdef __VDOREC_HIDE_HINT__
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_STATUS);
#else
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_HINT | VDOREC_OSD_COMPONENT_STATUS);
#endif
    
    mdi_video_rec_update_para_wb(vdorec_wb_command_map[support_wb_item[g_vdorec_cntx.setting.wb]]);
    
    mmi_vdorec_blt_screen();
}
#endif 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_led_highlight_hotkey_press
 * DESCRIPTION
 *  led highlight hotkey pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
static void mmi_vdorec_led_highlight_hotkey_press(void)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR str_buf[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_LED_HIGHLIGHT_HOTKEY_PRESS);

    /*if not in preview state, will forbit hotkey*/
    if(g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }

    if (g_vdorec_cntx.setting.led_highlight < VDOREC_SETTING_LED_HIGHLIGHT_COUNT - 1)
    {
        g_vdorec_cntx.setting.led_highlight++;
    }
    else
    {
        g_vdorec_cntx.setting.led_highlight = 0;
    }
    
    mmi_ucs2cpy((CHAR *) str_buf, (CHAR *) L"[ ");
    mmi_ucs2cat((CHAR *) str_buf, (CHAR *) GetString(STR_ID_VDOREC_LED_HIGHLIGHT));
    mmi_ucs2cat((CHAR *) str_buf, (CHAR *) L" ]");
    
    /* update osd */
    mmi_vdorec_set_hint(
        (CHAR *) str_buf,
        (CHAR *) GetString((U16) (g_vdorec_cntx.setting.led_highlight + STR_ID_VDOREC_LED_HIGHLIGHT_START + 1)),
        HINT_POPUP_FADE_TIME);
    
#ifdef __VDOREC_HIDE_HINT__
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_STATUS);
#else
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_HINT | VDOREC_OSD_COMPONENT_STATUS);
#endif
    
    /* turn on/of led */
    if (g_vdorec_cntx.setting.led_highlight == VDOREC_SETTING_LED_HIGHLIGHT_OFF)
    {
        mmi_vdorec_turn_off_led_highlight();
    }
    else
    {
        mmi_vdorec_turn_on_led_highlight();
    }
    
    mmi_vdorec_turn_on_led_highlight();
    
    mmi_vdorec_blt_screen();
}
#endif 


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_record_aud_hotkey_press
* DESCRIPTION
*  record audio hotkey press hdlr
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __VDOREC_FEATURE_RECORD_AUD__
static void mmi_vdorec_record_aud_hotkey_press(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR str_buf[256];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_RECORD_AUD_HOTKEY_PRESS);

    /*if not in preview state, will forbit hotkey*/
    if(g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        return;
    }

    if (g_vdorec_cntx.setting.record_aud < VDOREC_SETTING_RECORD_AUD_COUNT - 1)
    {
        g_vdorec_cntx.setting.record_aud++;
    }
    else
    {
        g_vdorec_cntx.setting.record_aud = 0;
    }
    
    /* for record audio used in preview start, so I stop and restart preview*/
    mdi_video_rec_preview_stop();
    g_vdorec_cntx.is_preview_started = MMI_FALSE;

    if (!mmi_vdorec_is_in_bgcall())
    {
        mmi_vdorec_start_preview();
    }
    
    mmi_ucs2cpy((CHAR *) str_buf, (CHAR *) L"[ ");
    mmi_ucs2cat((CHAR *) str_buf, (CHAR *) GetString(STR_ID_VDOREC_RECORD_AUD));
    mmi_ucs2cat((CHAR *) str_buf, (CHAR *) L" ]");
    
    /* update osd */
    mmi_vdorec_set_hint(
        (CHAR *) str_buf,
        (CHAR *) GetString((U16) (g_vdorec_cntx.setting.record_aud + STR_ID_VDOREC_RECORD_AUD_START + 1)),
        HINT_POPUP_FADE_TIME);
    
#ifdef __VDOREC_HIDE_HINT__
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_STATUS);
#else
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_HINT | VDOREC_OSD_COMPONENT_STATUS);
#endif
        
    mmi_vdorec_blt_screen();
}
#endif 

#endif  /*__MMI_VIDEO_RECORDER_SLIM__*/


#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) 
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_clam_close_event_hdlr
 * DESCRIPTION
 *  handle clam close event
 * PARAMETERS
 *  ptr     [IN]        mmi_event_struct ptr
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret mmi_vdorec_clam_close_event_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_pre_post_protocol_event_struct *pevt = (mmi_frm_pre_post_protocol_event_struct *)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_CLAM_CLOSE_EVENT_HDLR);

    if (pevt->message->msg_id == MSG_ID_MMI_EQ_GPIO_DETECT_IND)
    {
        mmi_eq_gpio_detect_ind_struct *ind = (mmi_eq_gpio_detect_ind_struct *)pevt->message->local_para_ptr;
        if (ind->gpio_device == EXT_DEV_CLAM_CLOSE)
        {
            mmi_frm_scrn_close_active_id();
        }
    }
    return MMI_RET_OK;
}

#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_video_setting_set_value
 * DESCRIPTION
 *  camcoder setting lsk press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_video_setting_set_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __VDOREC_FEATURE_MERGE_MENU__

    /* merge "Video Setting" items into "CamCoder Setting" */
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    cui_inline_get_value(g_vdorec_cntx.setting_img_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_SIZE_SELECT, (void*)&value);
    g_vdorec_cntx.setting.video_size= value;
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_QTY__
    cui_inline_get_value(g_vdorec_cntx.setting_img_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_QTY_SELECT, (void*)&value);
    g_vdorec_cntx.setting.video_qty= value;
#endif 

#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    cui_inline_get_value(g_vdorec_cntx.setting_img_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_SIZE_LIMIT_SELECT, (void*)&value);
    g_vdorec_cntx.setting.size_limit= value;
#endif 

#ifdef __VDOREC_FEATURE_TIME_LIMIT__
    cui_inline_get_value(g_vdorec_cntx.setting_img_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_TIME_LIMIT_SELECT, (void*)&value);
    g_vdorec_cntx.setting.time_limit= value;
#endif 

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    cui_inline_get_value(g_vdorec_cntx.setting_img_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_RECORD_AUD_SELECT, (void*)&value);
    g_vdorec_cntx.setting.record_aud= value;
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
    cui_inline_get_value(g_vdorec_cntx.setting_img_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_FORMAT_SELECT, (void*)&value);
    g_vdorec_cntx.setting.video_format= value;
#endif 
#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_CAMCORDER_SETTING_LSK_PRESS);
    mmi_vdorec_store_setting();
#if 0
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_camcoder_setting_set_value
 * DESCRIPTION
 *  camcoder setting lsk press
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_camcoder_setting_set_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 value;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0    
#ifdef __VDOREC_FEATURE_WB__
/* under construction !*/
/* under construction !*/
#endif 
#endif
#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
    cui_inline_get_value(g_vdorec_cntx.setting_camcorder_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_LED_HIGHLIGHT_SELECT, (void*)&value);
    g_vdorec_cntx.setting.led_highlight = value;
#endif 

#ifdef __VDOREC_FEATURE_EV__
    cui_inline_get_value(g_vdorec_cntx.setting_camcorder_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_EV_SELECT, (void*)&value);
    g_vdorec_cntx.setting.ev= value;
#endif 

#ifdef __VDOREC_FEATURE_NIGHT__
    cui_inline_get_value(g_vdorec_cntx.setting_camcorder_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_NIGHT_SELECT, (void*)&value);
    g_vdorec_cntx.setting.night= value;
#endif 

#ifdef __VDOREC_FEATURE_BANDING__
    cui_inline_get_value(g_vdorec_cntx.setting_camcorder_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_BANDING_SELECT, (void*)&value);
    g_vdorec_cntx.setting.banding= value;
#endif 

#ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__
    cui_inline_get_value(g_vdorec_cntx.setting_camcorder_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_CALL_ACCEPT_OPTION_SELECT, (void*)&value);
    g_vdorec_cntx.setting.accept_call= value;
#endif

#ifdef __VDOREC_FEATURE_MERGE_MENU__

    /* merge "Video Setting" items into "CamCoder Setting" */
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    cui_inline_get_value(g_vdorec_cntx.setting_camcorder_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_SIZE_SELECT, (void*)&value);
    g_vdorec_cntx.setting.video_size= value;
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_QTY__
    cui_inline_get_value(g_vdorec_cntx.setting_camcorder_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_QTY_SELECT, (void*)&value);
    #ifdef __VDOREC_FEATURE_ZOOM__
    if (value != g_vdorec_cntx.setting.video_qty)
    {
        g_vdorec_cntx.setting.zoom = VDOREC_DEFAULT_SETTING_ZOOM;
    }
    #endif
    g_vdorec_cntx.setting.video_qty= value;
#endif 

#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    cui_inline_get_value(g_vdorec_cntx.setting_camcorder_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_SIZE_LIMIT_SELECT, (void*)&value);
    g_vdorec_cntx.setting.size_limit= value;
#endif 

#ifdef __VDOREC_FEATURE_TIME_LIMIT__
    cui_inline_get_value(g_vdorec_cntx.setting_camcorder_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_TIME_LIMIT_SELECT, (void*)&value);
    g_vdorec_cntx.setting.time_limit= value;
#endif 

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    cui_inline_get_value(g_vdorec_cntx.setting_camcorder_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_RECORD_AUD_SELECT, (void*)&value);
    g_vdorec_cntx.setting.record_aud= value;
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
    cui_inline_get_value(g_vdorec_cntx.setting_camcorder_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_FORMAT_SELECT, (void*)&value);
    g_vdorec_cntx.setting.video_format= value;
#endif 

#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_CAMCORDER_SETTING_LSK_PRESS);
    mmi_vdorec_store_setting();
#if 0
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_del_app_screen_hdlr
 * DESCRIPTION
 *  del app screen callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_vdorec_del_app_screen_hdlr(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	#ifdef __DIRECT_SENSOR_SUPPORT__
    CHAR buf_filepath[SRV_FMGR_PATH_BUFFER_SIZE];
	#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DEL_APP_SCREEN_HDLR);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
    }

#ifdef __DIRECT_SENSOR_SUPPORT__
    /* 
     * 6223 will call mdi_video_rec_limited_avi_deinit here, 
     * so we need to stop rec first 
     */

    if (g_vdorec_cntx.state == VDOREC_STATE_RECORD)
    {
        mdi_video_rec_record_stop();
    }
    else if (g_vdorec_cntx.state == VDOREC_STATE_PREVIEW)
    {
        mdi_video_rec_preview_stop();
        g_vdorec_cntx.is_preview_started = MMI_FALSE;
    }
    else if (g_vdorec_cntx.state == VDOREC_STATE_PAUSE)
    {
        mdi_video_rec_record_stop();
        mdi_video_rec_preview_stop();
        g_vdorec_cntx.is_preview_started = MMI_FALSE;
    }

    g_vdorec_cntx.state = VDOREC_STATE_EXIT;

    /* free resouce */
    if (g_vdorec_cntx.is_limit_avi_inited)
    {
        mdi_video_rec_limited_avi_deinit();
        g_vdorec_cntx.is_limit_avi_inited = MMI_FALSE;
    }

    /* clean tmp files */
    mmi_vdoply_get_storage_file_path(buf_filepath);
    mdi_video_rec_delete_unsaved_file(buf_filepath);

#else

    /* always clean up tmp files */
    //mmi_vdoply_get_storage_file_path(buf_filepath);
    //mdi_video_rec_delete_unsaved_file(buf_filepath);
    
#endif /* __DIRECT_SENSOR_SUPPORT__ */

    g_vdorec_cntx.is_change_storage = FALSE;

#if defined(__MMI_OP12_CAMERA_VDOREC_CUSTOMIZE__) && defined(__VDOREC_FEATURE_VIDEO_SIZE_SQCIF__)
	#ifndef __VDOREC_FEATURE_EXT_REQ_DISABLE__
    if (g_vdorec_cntx.is_ext_req)
    {
        g_vdorec_cntx.setting.video_size = g_vdorec_cntx.old_video_size; /* restore the video size setting to original */
    }
	#endif
#endif  /* defined(__MMI_OP12_CAMERA_VDOREC_CUSTOMIZE__) && defined(__VDOREC_FEATURE_VIDEO_SIZE_SQCIF__) */

    g_vdorec_cntx.is_foward_to = FALSE;
    
    g_vdorec_cntx.cur_gid = GRP_ID_INVALID;

#ifndef __MMI_VIDEO_RECORDER_SLIM__
#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    mmi_vdorec_free_app_mem();
#endif
#endif
    return MMI_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_select_storage_rsp_hdlr
 * DESCRIPTION
 *  This function is to sort widget with quick sort algorithm
 * PARAMETERS
 *  left:  [IN] left position 
 *  right: [IN] right position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_select_storage_rsp_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_storage_selector_result_event_struct *param = 
        (cui_storage_selector_result_event_struct *)evt;
    CHAR storage_filepath[SRV_FMGR_PATH_BUFFER_SIZE];
    S32 create_result;    
    U16 prev_storage;
    CHAR buf[64];
    CHAR buf_filepath[SRV_FMGR_PATH_BUFFER_SIZE];
    U8 drv_letter;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (param->result > 0) /* user selects a storage */
    {
        prev_storage = mmi_vdoply_get_storage();
        drv_letter = (U8)param->result;
        mmi_vdoply_set_storage((U16)drv_letter);
        
        sprintf(buf, "%c:\\", drv_letter);
        mmi_asc_to_ucs2(buf_filepath, buf);
        
        /* check if photo path exist or not */
        mmi_vdoply_get_storage_file_path(buf_filepath);
        create_result = mmi_vdoply_create_file_dir(buf_filepath);
        
        if (create_result != FS_NO_ERROR)
        {
            if (create_result == FS_WRITE_PROTECTION)
            {
                mmi_vdorec_disply_popup(
                    FMGR_FS_WRITE_PROTECTION_TEXT,
                    MMI_EVENT_FAILURE,
                    MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);    
            }
            else if (create_result == FS_DISK_FULL)
            {
                mmi_vdorec_disply_popup(
                    FMGR_FS_DISK_FULL_TEXT,
                    MMI_EVENT_FAILURE,
                    MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);    
            }
            else if (create_result == FS_ROOT_DIR_FULL)
            {
                mmi_vdorec_disply_popup(
                    FMGR_FS_ROOT_DIR_FULL_TEXT,
                    MMI_EVENT_FAILURE,
                    MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);     
            }
            else
            {
                /* other file system error */
                mmi_vdorec_disply_popup(
                    STR_ID_VDOREC_NOTIFY_STORAGE_NOT_READY,
                    MMI_EVENT_FAILURE,
                    MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);                    
            }
                    
            /* restore prev storage setting */      
            mmi_vdoply_set_storage((U16)prev_storage);
        
            /* after popup, will re-enter storage screen */              
            return;
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
    #endif
    }
    else
    {
        /* allocate storage path buffer */
        //memset(storage_filepath, 0, SRV_FMGR_PATH_BUFFER_SIZE);
        /* drv is valid, create directory */
        mmi_vdoply_get_storage_file_path(storage_filepath);
        create_result = mmi_vdoply_create_file_dir(storage_filepath);
        if (create_result < 0)
        {
            mmi_frm_group_close(g_vdorec_cntx.cur_gid);
        }        
    }
    
#if defined(__VDOREC_FEATURE_SLIM_UE__) && defined(__VDOREC_FEATURE_PREVIEW_SAVED_FILE__)
    g_vdorec_cntx.is_enter_play_video_scr = FALSE;
#endif
    /* close File Manger CUI */
    cui_storage_selector_close(param->sender_id);
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_app_group_proc
* DESCRIPTION
*  app group proc
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret mmi_vdorec_app_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct* menu_event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_event = (cui_menu_event_struct*)evt;
    switch (evt->evt_id)
    {        
    case EVT_ID_GROUP_DEINIT:
        mmi_vdorec_del_app_screen_hdlr();
		
		#ifdef __MMI_AP_DCM_VDOREC__
			  mmi_ap_post_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_VDOREC);
		#endif
		
        break; 

    case EVT_ID_POPUP_QUIT:
        if (((mmi_event_popoupcallback_result_struct*)evt)->user_tag == (void*)MMI_VDOREC_POPUP_RESULT_PROCESS_DELETE_GROUP)
        {
            mmi_vdorec_delete_group();
        }
        else if (((mmi_event_popoupcallback_result_struct*)evt)->user_tag == (void*)MMI_VDOREC_POPUP_RESULT_PROCESS_DELETE_SCREEN)
        {
            mmi_frm_scrn_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVED_PREVIEW);
        }
        break;
	case EVT_ID_GROUP_GOBACK_IN_END_KEY:
		g_vdorec_cntx.is_end_key = MMI_TRUE;
		break;
    /* sent from File Manager CUI, indicate the storage selected by users  */
    case EVT_ID_CUI_STORAGE_SELECTOR_RESULT:
        mmi_vdorec_select_storage_rsp_hdlr(evt);
        break;
            
    /*menu cui*/
    case EVT_ID_CUI_MENU_LIST_ENTRY:
    {
        /*cui_menu_set_currlist_flags(menu_event->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);*/
        mmi_menu_id m_menuitem;
        S32 i;
        S32 nItems;
        
        nItems =  cui_menu_get_currlist_item_count(menu_event->sender_id);
        for (i = 0; i< nItems; i++)
        {
            m_menuitem = cui_menu_get_currlist_menu_id_from_index(menu_event->sender_id, i);
            cui_menu_set_non_leaf_item(menu_event->sender_id, m_menuitem, MMI_FALSE);
        }
        /*  cui_menu_set_currlist_flags(menu_event->sender_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);*/
        break;
    }

    case EVT_ID_CUI_MENU_ITEM_SELECT:
        switch (menu_event->highlighted_menu_id)
        {
    #if defined(__VDOREC_FEATURE_SWITCH_TO_CAMERA__)
        case MENU_ID_VDOREC_TO_CAMERA:
            mmi_vdorec_switch_to_camera_hdlr();
            break;
    #endif
        case MENU_ID_VDOREC_CAMCODER_SETTING:
            mmi_vdorec_entry_camcoder_setting_screen();
            break;
    #ifdef __VDOREC_FEATURE_EFFECT__
        case MENU_ID_VDOREC_EFFECT_SETTING:
            mmi_vdorec_entry_effect_setting_screen();
            break;
    #endif
    #ifndef  __VDOREC_FEATURE_MERGE_MENU__
        case MENU_ID_VDOREC_VIDEO_SETTING:
            mmi_vdorec_entry_video_setting_screen();
            break;
    #endif
    #ifdef __VDOREC_FEATURE_WB__
        case MENU_ID_VDOREC_WHITE_BALANCE:
            mmi_vdorec_entry_wb_screen();
            break;
    #endif
    #ifdef __VDOREC_FEATURE_STORAGE__
        case MENU_ID_VDOREC_STORAGE:
            mmi_vdorec_entry_set_app_storage_screen(FALSE);
            break;
    #endif

    #ifdef __VDOREC_FEATURE_RESTORE_DEFAULT__
        case MENU_ID_VDOREC_RESTORE_DEFAULT:
            mmi_vdorec_entry_restore_default_confirm_screen();
            break;
    #endif
        default:
            cui_menu_close(menu_event->sender_id);
            break;
        }
        break;

    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
    {
    #if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
        mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    #endif

    #ifdef __MMI_INLINE_SLIM__
        {
            U32 number = 0;
            U16 item_id;
            U32 i;
            cui_event_inline_notify_struct *notify;

            notify = (cui_event_inline_notify_struct*)evt;
            number = cui_inline_get_instance_item_count(notify->sender_id) / 2;                 

            for (i = 0; i < number; i++)
            {
				item_id = cui_inline_get_item_id_by_index(notify->sender_id, i*2); 
                cui_inline_set_item_icon(notify->sender_id, item_id, IMG_GLOBAL_L1 + i);
            }
        }
    #endif
        
        break;
    }
    
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        cui_menu_set_rotate_screen(menu_event->sender_id, MMI_FRM_SCREEN_ROTATE_0);
        cui_menu_close(menu_event->sender_id);
        break;

    case EVT_ID_CUI_INLINE_SET_KEY:
    {
        SetCenterSoftkeyFunction(get_softkey_function(KEY_EVENT_UP,MMI_LEFT_SOFTKEY), KEY_EVENT_UP);
        break;
    }
    case EVT_ID_CUI_INLINE_SUBMIT:
    {
        //cui_event_inline_submit_struct *submit = (cui_event_inline_submit_struct *)evt;
        if (g_vdorec_cntx.setting_camcorder_inline_gid == menu_event->sender_id)
        {
            mmi_vdorec_camcoder_setting_set_value();
        }
        else if (g_vdorec_cntx.setting_img_inline_gid == menu_event->sender_id)
        {
            mmi_vdorec_video_setting_set_value();
        }
        cui_menu_close(menu_event->sender_id);
        break;
    }
    
    case EVT_ID_CUI_INLINE_ABORT:
    {
        cui_event_inline_abort_struct *abort = (cui_event_inline_abort_struct*)evt;
        cui_inline_close(abort->sender_id);
        break;
    }    
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_lauch
 * DESCRIPTION
 *  Video recoder entry point
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_lauch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_APP);
	
		#ifdef __MMI_AP_DCM_VDOREC__
		mmi_ap_send_dcm_load_evt(DYNAMIC_CODE_COMPRESS_VDOREC);
		#endif
    
    {
        U16 buf_filepath[SRV_FMGR_PATH_BUFFER_SIZE];

        //mmi_vdorec_load_setting();
        mmi_vdoply_get_storage_file_path((CHAR *)buf_filepath);
    
        g_vdorec_cntx.is_giveup_popup_rotate = MMI_TRUE;

        if (mmi_vdorec_entry_app_pre_check((CHAR *)buf_filepath) == MMI_FALSE)
        {
            return; /* pre check failed, video recorder is not available now. */
        }
    }

    /* disable external reqeust flag */
    g_vdorec_cntx.is_ext_req = MMI_FALSE;
    g_vdorec_cntx.is_entry_from_cui = MMI_FALSE;
    g_vdorec_cntx.is_use_ext_req_path = MMI_FALSE;
#ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__   
    g_vdorec_cntx.old_call_mode = MMI_FALSE;
#endif

#if defined(__VDOREC_FEATURE_SLIM_UE__) && defined(__VDOREC_FEATURE_PREVIEW_SAVED_FILE__)
    g_vdorec_cntx.is_enter_play_video_scr = FALSE;
#endif

    
    if (mmi_frm_group_is_present(g_vdorec_cntx.cur_gid))
    {
        mmi_vdorec_delete_group();
    }

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    g_vdorec_cntx.cur_gid = mmi_frm_group_create_ex(
        GRP_ID_ROOT,
        GRP_ID_AUTO_GEN,
        mmi_vdorec_app_group_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

#ifndef __MMI_VIDEO_RECORDER_SLIM__    
#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    if (g_vdorec_cntx.app_mem_bufer == NULL)
    {
        if (!mmi_vdorec_malloc_app_mem())
        {
            mmi_frm_appmem_prompt_to_release_mem(
                APPLIB_MEM_AP_ID_VDOREC,
                IMG_ID_VDOREC_APP_ICON,
                VDOREC_APP_MEMORY_BUFFER_SIZE,
                mmi_vdorec_app_mem_success_callback);
            mmi_frm_appmem_set_cancel_callback(APPLIB_MEM_AP_ID_VDOREC, mmi_vdorec_app_mem_cancel_callback);
            return;
        }
    }
#endif
#endif

    g_vdorec_cntx.is_giveup_popup_rotate = MMI_TRUE;
    mmi_vdorec_entry_app_internal();
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_disable_gprs
* DESCRIPTION
*  disable gprs when enter vdorec
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL mmi_vdorec_disable_gprs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__DIRECT_SENSOR_SUPPORT__) || defined(__DIRECT_SENSOR_V2_SUPPORT__)
#if defined(__TCPIP__)
    {
        srv_cbm_result_error_enum cbm_result;
        cbm_result = cbm_register_app_id(&g_vdorec_cntx.cbm_app_id);

        if (cbm_result != 0)
        {
            MMI_STR_ID string_id;
            mmi_event_notify_enum popup_type;
            
            srv_cbm_get_nwk_srv_error_info(cbm_result, &string_id, &popup_type);
            mmi_vdorec_disply_popup(
                string_id,
                popup_type,
                MMI_VDOREC_POPUP_RESULT_PROCESS_DELETE_GROUP);
            
            srv_cbm_allow_nwk_srv(SRV_CBM_BEARER_GPRS, g_vdorec_cntx.cbm_app_id);
            cbm_deregister_app_id(g_vdorec_cntx.cbm_app_id);

            return MMI_FALSE;
        }
        else
        {
            cbm_result = srv_cbm_disallow_nwk_srv(SRV_CBM_BEARER_GPRS, g_vdorec_cntx.cbm_app_id);
            if (cbm_result != 0)
            {
                MMI_STR_ID string_id;
                mmi_event_notify_enum popup_type;
                
                srv_cbm_get_nwk_srv_error_info(cbm_result, &string_id, &popup_type);
                
                mmi_vdorec_disply_popup(
                    string_id,
                    popup_type,
                    MMI_VDOREC_POPUP_RESULT_PROCESS_DELETE_GROUP);
                
                srv_cbm_allow_nwk_srv(SRV_CBM_BEARER_GPRS, g_vdorec_cntx.cbm_app_id);
                cbm_deregister_app_id(g_vdorec_cntx.cbm_app_id);
                return MMI_FALSE;
            }
        }
    }
#endif
#endif /* __DIRECT_SENSOR_SUPPORT__ */

        return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_allow_gprs
* DESCRIPTION
*  allow gprs when exit vdorec
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_allow_gprs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__DIRECT_SENSOR_SUPPORT__) || defined(__DIRECT_SENSOR_V2_SUPPORT__)
#if defined(__TCPIP__)
    srv_cbm_allow_nwk_srv(SRV_CBM_BEARER_GPRS, g_vdorec_cntx.cbm_app_id);
    cbm_deregister_app_id(g_vdorec_cntx.cbm_app_id);
#endif
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_panel_ev
 * DESCRIPTION
 *  draw panel ev
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_panel_ev(void)
{
#if defined(__VDOREC_FEATURE_EV__) && !defined(__VDOREC_FEATURE_FTE_SUPPORT__)	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_offset_x;
    S32 layer_offset_y;    
    S32 image_width;
    S32 image_height;
    U16 image_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_PANEL_EV);

    gdi_layer_push_and_set_active(g_vdorec_cntx.ev_draw_layer);
    
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

#ifdef __VDOREC_FEATURE_SLIM_UE__
    {
        S32 ev_image_shift = 0;
        S32 ev_value_shift = 0;
        S32 offset_x = 0;
        S32 offset_y = 0;
        S32 blt_region_x = 0;
        S32 blt_region_y = 0;
        S32 blt_region_w = 0;
        S32 blt_region_h = 0;

        blt_region_x = g_vdorec_osd_cntx.panel.ev.offset_x;
        blt_region_y = g_vdorec_osd_cntx.panel.ev.offset_y;
        offset_x = g_vdorec_osd_cntx.panel.ev.offset_x - layer_offset_x;
        offset_y = g_vdorec_osd_cntx.panel.ev.offset_y - layer_offset_y;
        
        if (g_vdorec_cntx.setting.ev < VDOREC_DEFAULT_SETTING_EV)
        {
            ev_image_shift = -1;
            ev_value_shift = VDOREC_DEFAULT_SETTING_EV - g_vdorec_cntx.setting.ev;
        }
        else if (g_vdorec_cntx.setting.ev > VDOREC_DEFAULT_SETTING_EV)
        {
            ev_image_shift = 1;
            ev_value_shift = g_vdorec_cntx.setting.ev - VDOREC_DEFAULT_SETTING_EV;
        }
        /* draw "ev" */        
        gdi_image_draw_id(
            offset_x,
            offset_y,
            (U16) IMG_ID_VDOREC_OSD_EV_HEAD);
        gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_EV_HEAD ,&image_width, &image_height);

		#ifdef __VDOREC_USING_BLT_REGION__
        if (g_vdorec_cntx.is_use_blt_region)
        {
            blt_region_w += image_width;
            blt_region_h = image_height;
        }
		#endif

        /* draw "+", " ", "-" */
        offset_x += image_width;
        gdi_image_draw_id(
            offset_x,
            offset_y,
            (U16) (IMG_ID_VDOREC_OSD_EV_Z + ev_image_shift));
        gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_EV_Z ,&image_width, &image_height);

		#ifdef __VDOREC_USING_BLT_REGION__
        if (g_vdorec_cntx.is_use_blt_region)
        {
            blt_region_w += image_width;
        }
		#endif

        /* draw ev value */
        offset_x += image_width;
        gdi_image_draw_id(
            offset_x,
            offset_y,
            (U16) (IMG_ID_VDOREC_OSD_EV_0 + ev_value_shift)); 

		#ifdef __VDOREC_USING_BLT_REGION__
        if (g_vdorec_cntx.is_use_blt_region)
        {
            gdi_image_get_dimension_id((IMG_ID_VDOREC_OSD_EV_0 + ev_value_shift), &image_width, &image_height);
            blt_region_w += image_width;
            mmi_vdorec_merge_blt_rgn(
                blt_region_x,
                blt_region_y,
                blt_region_w,
                blt_region_h);
        }
		#endif
    }        
#else

    gdi_image_draw_id(
        g_vdorec_osd_cntx.panel.ev.offset_x - layer_offset_x,
        g_vdorec_osd_cntx.panel.ev.offset_y - layer_offset_y,
        (U16) (IMG_ID_VDOREC_OSD_EV_START + g_vdorec_cntx.setting.ev + 1));

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_EV_START + 1, &image_width, &image_height);
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_osd_cntx.panel.ev.offset_x,
            g_vdorec_osd_cntx.panel.ev.offset_y,
            image_width,
            image_height);
    }
	#endif

#endif  /*__VDOREC_FEATURE_SLIM_UE__*/

    /* ev inc */
	if (g_vdorec_cntx.setting.ev >= VDOREC_SETTING_EV_COUNT - 1)
	{
	    image_id = IMG_ID_VDOREC_TOUCH_OSD_EV_INC_DIS;
	}
	else if((g_vdorec_cntx.touch_ev_inc.is_press) || (g_vdorec_cntx.is_ev_inc_key_pressed))
	{
	    image_id = IMG_ID_VDOREC_TOUCH_OSD_EV_INC_SEL;
	}
	else
	{
	    image_id = IMG_ID_VDOREC_TOUCH_OSD_EV_INC;
	}
    gdi_image_draw_id(
        g_vdorec_osd_cntx.panel.ev_inc.offset_x - layer_offset_x,
        g_vdorec_osd_cntx.panel.ev_inc.offset_y - layer_offset_y,
        image_id);

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        gdi_image_get_dimension_id(image_id, &image_width, &image_height);
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_osd_cntx.panel.ev_inc.offset_x,
            g_vdorec_osd_cntx.panel.ev_inc.offset_y,
            image_width,
            image_height);
    }
	#endif

    /* ev dec */
	if (g_vdorec_cntx.setting.ev == 0)
	{
	    image_id = IMG_ID_VDOREC_TOUCH_OSD_EV_DEC_DIS;
	}
	else if ((g_vdorec_cntx.touch_ev_dec.is_press) || (g_vdorec_cntx.is_ev_dec_key_pressed))		
    {
        image_id = IMG_ID_VDOREC_TOUCH_OSD_EV_DEC_SEL;
    }
    else
    {
        image_id = IMG_ID_VDOREC_TOUCH_OSD_EV_DEC;
    }
    gdi_image_draw_id(
        g_vdorec_osd_cntx.panel.ev_dec.offset_x - layer_offset_x,
        g_vdorec_osd_cntx.panel.ev_dec.offset_y - layer_offset_y,
        image_id);

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        gdi_image_get_dimension_id(image_id, &image_width, &image_height);
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_osd_cntx.panel.ev_dec.offset_x,
            g_vdorec_osd_cntx.panel.ev_dec.offset_y,
            image_width,
            image_height);
    }
	#endif

    gdi_layer_pop_and_restore_active();

#endif /* __VDOREC_FEATURE_EV__ */ 
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_usb_mode_hdlr2
* DESCRIPTION
*  usb mode hdlr
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret mmi_vdorec_usb_mode_hdlr2(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_USB_SUPPORT__
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_USB_MODE_HDLR);

    if (g_vdorec_cntx.is_saving)
    {
        mdi_video_rec_stop_save();
        g_vdorec_cntx.is_saving = FALSE;
        mmi_frm_scrn_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVING);
    }
#endif
    return MMI_RET_OK;
}


#ifdef __VDOREC_FEATURE_STORAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_hint_storage
 * DESCRIPTION
 *  hint storage
 * PARAMETERS
 *  index       [IN]        
 *  a(?)        [IN]        Hilight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_hint_storage(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HINT_STORAGE);

    memset((CHAR *) hintData[(index)], 0, sizeof(hintData[(index)]));
    if (FS_NO_ERROR != FS_GetDevStatus(mmi_vdoply_get_storage() ,FS_MOUNT_STATE_ENUM))
    {
        mmi_vdoply_set_storage((U16) SRV_FMGR_PUBLIC_DRV);
    }
    
    srv_fmgr_drv_get_name(
        (U8)mmi_vdoply_get_storage(), 
        (WCHAR*)&hintData[index], 
        (U8)((SRV_FMGR_DRV_MAX_NAME_LEN + 1 ) * ENCODING_LENGTH));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_app_storage_screen
 * DESCRIPTION
 *  entry app storage setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_set_app_storage_screen(BOOL is_option_storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    #ifndef __VDOREC_FEATURE_SLIM_UE__ 
    U16 buf_filepath[SRV_FMGR_PATH_BUFFER_SIZE/2];
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_SET_APP_STORAGE_SCREEN);

#ifndef __VDOREC_FEATURE_SLIM_UE__
    mmi_vdoply_get_storage_file_path((CHAR *)buf_filepath);

    if (mdi_video_rec_has_unsaved_file((CHAR *)buf_filepath))
    {
        mmi_vdorec_disply_popup(
            STR_ID_VDOREC_NOTIFY_PLZ_SAVE_FIRST,
            MMI_EVENT_INFO,
            MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
    }
    else
#endif  /*__VDOREC_FEATURE_SLIM_UE__*/
    {
        /* change storage for App -> Storage */
        /* this is used when enter app, the storage is not exist or folder cant be created */
        g_vdorec_cntx.is_option_storage = is_option_storage;    
        mmi_vdorec_entry_set_storage_screen_internal();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_set_storage_screen_internal
 * DESCRIPTION
 *  entry storage setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_set_storage_screen_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id g_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif
    /* create and run storage CUI */
    g_id = cui_storage_selector_create(g_vdorec_cntx.cur_gid, (U8)mmi_vdoply_get_storage(), 0);
	cui_storage_selector_set_title(g_id, NULL, GetRootTitleIcon(MENU_ID_VDOREC_APP));
	cui_storage_selector_set_ui_style(g_id, CUI_FMGR_UI_STYLE_BANNER_LIST);    /* NEED TEST */

    cui_storage_selector_run(g_id);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_SET_STORAGE_SCREEN_INTERNAL);
}
#endif /* __VDOREC_FEATURE_STORAGE__ */ 


#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_delete_saved_vdo_hdlr
 * DESCRIPTION
 *  delete saved video.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_delete_saved_vdo_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DELETE_SAVED_VDO_HDLR);

    fs_ret = FS_Delete((WCHAR*)g_vdorec_cntx.filepath);

    if (fs_ret == FS_NO_ERROR)
    {
    #if 0
/* under construction !*/
    #endif
    }
    else
    {
        mmi_vdorec_disply_popup(
            srv_fmgr_fs_error_get_string(fs_ret),
            MMI_EVENT_FAILURE,
            MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
    }
    mmi_frm_scrn_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_PREVIEW_OPTION);
    mmi_frm_scrn_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVED_PREVIEW);
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_delete_confirm_cb
* DESCRIPTION
*  delete video confirm callback
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_vdorec_delete_confirm_cb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            mmi_vdorec_delete_saved_vdo_hdlr();
            break;
        case MMI_ALERT_CNFM_NO:
            mmi_frm_scrn_close_active_id();
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_delete_saved_vdo_confirm
 * DESCRIPTION
 *  confirm screen of delete saved video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_delete_saved_vdo_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DELETE_SAVED_VDO_CONFIRM);

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)mmi_vdorec_delete_confirm_cb;
    arg.parent_id = g_vdorec_cntx.cur_gid;
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    arg.rotation = MMI_FRM_SCREEN_ROTATE_270;
#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 
    arg.f_auto_map_empty_softkey = MMI_FALSE;

    mmi_confirm_display((WCHAR *)((UI_string_type)get_string(STR_ID_VDOREC_NOTIFY_DELETE_CONFIRM)), MMI_EVENT_QUERY, &arg);
}


#if defined(__VDOREC_FEATURE_RSK_DELETE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_preview_continue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_preview_continue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_PREVIEW_CONTINUE);

    mmi_frm_scrn_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVED_PREVIEW);
    mmi_frm_group_close(SCR_ID_VDOREC_PREVIEW_OPTION);
}
#endif /* defined(__VDOREC_FEATURE_RSK_DELETE__) */


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_preview_option_group_proc
 * DESCRIPTION
 *  preview video option event proc
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_vdorec_preview_option_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt_id)
    {
    case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
    case EVT_ID_CUI_MENU_ITEM_SELECT:
        if (menu_evt->parent_menu_id == MENU_ID_VDOREC_PREVIEW_OPTION)
        {
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_VDOREC_DELETE:
                    mmi_vdorec_delete_saved_vdo_confirm();
                    break;

            #ifdef __VDOREC_FEATURE_RSK_DELETE__
                case MENU_ID_VDOREC_CONTINUE:
                    mmi_vdorec_preview_continue();
                    break;
            #endif

            #ifdef __VDOREC_FEATURE_MMS_SUPPORT__
                case MENU_ID_VDOREC_TO_MMS:
                    mmi_vdorec_to_mms_hdlr();
                    break;
            #endif

            #ifdef __VDOREC_FEATURE_EMAIL_SUPPORT__
                case MENU_ID_VDOREC_TO_EMAIL:
                    mmi_vdorec_to_email_hdlr();
                    break;
            #endif

            #ifdef __VDOREC_FEATURE_BT_SEND_SUPPORT__
                case MENU_ID_VDOREC_TO_BT:
                    mmi_vdorec_to_BT_hdlr();
                    break;
            #endif
            }
        }
        else
        {
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_VDOREC_DELETE:
                    mmi_vdorec_delete_saved_vdo_confirm();
                    break;

            #ifdef __VDOREC_FEATURE_RSK_DELETE__
                case MENU_ID_VDOREC_CONTINUE:
                    mmi_vdorec_preview_continue();
                    break;
            #endif
            
            #ifdef __VDOREC_FEATURE_MMS_SUPPORT__
                case MENU_ID_VDOREC_TO_MMS:
                    mmi_vdorec_to_mms_hdlr();
                    break;
            #endif

            #ifdef __VDOREC_FEATURE_EMAIL_SUPPORT__
                case MENU_ID_VDOREC_TO_EMAIL:
                    mmi_vdorec_to_email_hdlr();
                    break;
            #endif

            #ifdef __VDOREC_FEATURE_BT_SEND_SUPPORT__
                case MENU_ID_VDOREC_TO_BT:
                    mmi_vdorec_to_BT_hdlr();
                    break;
            #endif
            }
        }
        break;

    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_entry_preview_option_screen
* DESCRIPTION
*  entry preview video option
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_entry_preview_option_screen(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if 0
/* under construction !*/
/* under construction !*/
    #endif
    mmi_frm_group_create_ex(
        g_vdorec_cntx.cur_gid,
        SCR_ID_VDOREC_PREVIEW_OPTION,
        mmi_vdorec_preview_option_group_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

#if (!defined(__VDOREC_FEATURE_DIRECT_SAVE__) && !defined(__VDOREC_FEATURE_SLIM_UE__))||defined(__VDOREC_FEATURE_PREVIEW_SAVED_FILE__)    
    mmi_vdorec_hide_unaviailable_send_options();
#endif
        
    menu_gid = cui_menu_create(
        SCR_ID_VDOREC_PREVIEW_OPTION, 
        CUI_MENU_SRC_TYPE_RESOURCE, 
        CUI_MENU_TYPE_FROM_RESOURCE, 
        MENU_ID_VDOREC_PREVIEW_OPTION, 
        MMI_TRUE, 
        NULL);
    
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    cui_menu_set_rotate_screen(menu_gid, MMI_FRM_SCREEN_ROTATE_270);
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 

    cui_menu_set_default_title_by_id(menu_gid, STR_GLOBAL_OPTIONS, NULL);//GetRootTitleIcon(MENU_ID_VDOREC_APP));
    cui_menu_set_default_left_softkey_by_id(menu_gid, STR_GLOBAL_OK);
    cui_menu_set_default_right_softkey_by_id(menu_gid, STR_GLOBAL_BACK);
    cui_menu_run(menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_preview_idle_timeout_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_preview_idle_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_PREVIEW_IDLE_TIMEROUT_HDLR);

    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_preview_idle_timeout_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_preview_idle_timeout_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_PREVIEW_IDLE_TIMEOUT_CANCEL);

    gui_cancel_timer(mmi_vdorec_preview_idle_timeout_hdlr);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_exit_preview_video_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_exit_preview_video_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    gdi_handle base_layer_handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_EXIT_PREVIEW_VIDEO_SCREEN);

    gui_cancel_timer(mmi_vdorec_play_timer_cyclic);
    mmi_vdorec_preview_idle_timeout_cancel();       /* cancel preview timeout timer */
    
    if (g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_PLAY)
    {
        mdi_video_ply_stop();
        mdi_video_ply_close_clip_file();
    }
    else if (g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_STOP)
    {
        mdi_video_ply_close_clip_file();
    }

    g_vdorec_cntx.video_duration = 0;
    g_vdorec_cntx.state = VDOREC_STATE_EXIT;
    g_vdorec_cntx.is_del_key_pressed = FALSE;

    //gdi_layer_flatten_previous_to_base();  

    gdi_layer_get_base_handle(&base_layer_handle);
    gdi_layer_push_and_set_active(base_layer_handle);
    gdi_layer_set_rotate(GDI_LCD_LAYER_ROTATE_0);
    gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();
    
    /* free bg layer */

    /* free preview layers */
    if (g_vdorec_cntx.preview_layer_handle != 0)
    {
        mdi_util_hw_layer_free(g_vdorec_cntx.preview_layer_handle);
        g_vdorec_cntx.preview_layer_handle = 0;
    }

	#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    /*release tmp layer handle*/
    if (g_vdorec_cntx.is_use_hw_rotate)
    {
        for (i = 0 ; i < g_vdorec_cntx.osd_layer_region_count ; i ++)
        {
            gdi_layer_free(g_vdorec_cntx.tmp_osd_layer_region_handle[i]);
            g_vdorec_cntx.tmp_osd_layer_region_handle[i] = GDI_LAYER_EMPTY_HANDLE;
            
            //mmi_frm_scrmem_free(g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[i]);
            //g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[i] = NULL;    
        }
    }
	#endif

    
#ifdef __VDOREC_FEATURE_SHOW_STATUS_BAR__
    wgui_status_icon_set_display_layer(g_vdorec_cntx.prev_status_bar_layer_handle);
    
    if (g_vdorec_cntx.status_bar_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_vdorec_cntx.status_bar_layer_handle);
        g_vdorec_cntx.status_bar_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }
#endif /* __VDOPLY_FEATURE_SHOW_STATUS_BAR__ */

	#ifndef __VDOREC_FEATURE_MULTI_REGION_SUPPORT__
    if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE)
    {
        if (g_vdorec_cntx.osd_layer_handle)
        {
            gdi_layer_free(g_vdorec_cntx.osd_layer_handle);
            g_vdorec_cntx.osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;
            mmi_frm_scrmem_free(g_vdorec_cntx.osd_layer_buf_ptr);
            g_vdorec_cntx.osd_layer_buf_ptr = NULL;
        }
    }
    #else
    {
        for (i = 0 ; i < g_vdorec_cntx.osd_layer_region_count ; i++)
        {
            if (g_vdorec_cntx.osd_layer_region_handle[i] != GDI_LAYER_EMPTY_HANDLE)
            {
                gdi_layer_free(g_vdorec_cntx.osd_layer_region_handle[i]);
                g_vdorec_cntx.osd_layer_region_handle[i] = GDI_LAYER_EMPTY_HANDLE;
                
                mmi_frm_scrmem_free(g_vdorec_cntx.osd_layer_region_handle_ptr[i]);
                g_vdorec_cntx.osd_layer_region_handle_ptr[i] = NULL;
            }
        }
    }
	#endif
	
#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    /* restore base layer rotation */

    gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);

    gdi_layer_resize(UI_device_width, UI_device_height);

    /* clear in black layer if it is horizontal view */
    gdi_layer_clear(GDI_COLOR_BLACK);
    
#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

    /* restore rotate layer flag */
    gdi_lcd_set_rotate_by_layer(g_vdorec_cntx.prev_rotate_by_layer);

    /* disable multi layer */
    gdi_layer_multi_layer_disable();

    /* resume alignment timer */
    UI_disable_alignment_timers();

    /* resume LED patten */
    srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_START);

    /* let MMI can sleep */
    srv_backlight_turn_off();

    /* resume background audio */
    mdi_audio_resume_background_play();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_TRUE);
#endif

    if (g_vdorec_cntx.gdi_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_vdorec_cntx.gdi_layer_handle);
        g_vdorec_cntx.gdi_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }

#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) 
    mmi_frm_cb_dereg_event(EVT_ID_PRE_PROTOCOL, mmi_vdorec_clam_close_event_hdlr, NULL);
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */

    /* exit sublcd */
#ifdef __MMI_SUBLCD__
    /* exit app screen if exist , and not exit because toggle self capture to sublcd */
    if (g_vdorec_cntx.is_sub_display)
    {
        GoBackSubLCDHistory();
        g_vdorec_cntx.is_sub_display = FALSE;
    }
#endif /* __MMI_SUBLCD__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_preview_video_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_preview_video_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U8 *guiBuffer;
    mdi_video_info_struct v_info;
    MMI_BOOL entry_ret;
    PU8 base_layer_ptr;
    S32 buffer_size;
    //S32 layer_offset_x;
    //S32 layer_offset_y;
    //S32 layer_width;
    //S32 layer_height;
    
    mdi_util_create_hw_layer_extmemory_in_struct layer_in;
    mdi_util_create_hw_layer_out_struct layer_out;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_PREVIEW_VIDEO_SCREEN);

#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) && defined(__MTK_TARGET__)
    /* back to idle if clam is closed */
    if (srv_clam_is_close())
    {
        mmi_idle_display();
        return;
    }
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) && defined(__MTK_TARGET__) */ 

    entry_ret = mmi_frm_scrn_enter (g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVED_PREVIEW, mmi_vdorec_exit_preview_video_screen, mmi_vdorec_entry_preview_video_screen, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }

    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
    mmi_frm_scrn_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_PREVIEW_OPTION);
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    entry_full_screen();

    //guiBuffer = mmi_frm_scrn_get_gui_buf(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVED_PREVIEW);

    /* entry sublcd */
#ifdef __MMI_SUBLCD__
    if (!mmi_is_redrawing_bk_screens())
    {
        if (!g_vdorec_cntx.is_sub_display)
        {
            ForceSubLCDScreen(mmi_vdorec_entry_sublcd_screen);
        }
    }
#endif /* __MMI_SUBLCD__ */ 

#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) 
    mmi_frm_cb_reg_event(EVT_ID_PRE_PROTOCOL, mmi_vdorec_clam_close_event_hdlr, NULL);
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */ 

    /* hook to touch screen callback */
#if defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_pen_down_handler(mmi_vdorec_touch_scr_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_vdorec_touch_scr_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_vdorec_touch_scr_pen_move_hdlr);
#endif /* defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ 

   /*******************************************************************
   * Init proper global state for video applcation  
   ********************************************************************/
    
    srv_profiles_stop_tone(SRV_PROF_TONE_KEYPAD);           /* force all playing keypad tone off */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);      /* disable key pad tone */
    gdi_layer_multi_layer_enable();                         /* enable multi_layer */
    mdi_audio_suspend_background_play();                    /* suspend background play */
    UI_disable_alignment_timers();                          /* disalbe align timer */
    srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_STOP);                             /* stop LED patten */
    gdi_layer_clear(GDI_COLOR_BLACK);
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);                                     /* stop MMI sleep */

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_FALSE);
#endif

    gui_set_font(&MMI_medium_font);                         /* use medium font */

    g_vdorec_cntx.prev_rotate_by_layer = gdi_lcd_get_rotate_by_layer();

    /***************************************************************************** 
     * Create layers 
     *****************************************************************************/
#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__

	#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    if (g_vdorec_cntx.is_use_hw_rotate)
    {
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);
    }
    #else
    {
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);
    }
	#endif

#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

   /************ base layer layer ************/
    gdi_layer_get_base_handle(&g_vdorec_cntx.bg_layer_handle);

    gdi_layer_push_and_set_active(g_vdorec_cntx.bg_layer_handle);
    gdi_layer_get_buffer_ptr(&base_layer_ptr);
    gdi_layer_pop_and_restore_active();

#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__

	#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    if (g_vdorec_cntx.is_use_hw_rotate)
    {
        g_vdorec_cntx.lcd_width = UI_device_width;
        g_vdorec_cntx.lcd_height = UI_device_height;
    }
    #else
    {
        g_vdorec_cntx.lcd_width = UI_device_height;
        g_vdorec_cntx.lcd_height = UI_device_width;
    }
	#endif
#else /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 
    g_vdorec_cntx.lcd_width = UI_device_width;
    g_vdorec_cntx.lcd_height = UI_device_height;

#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 
    
    /************ preview window layer ************/

    g_vdorec_cntx.preview_wnd_width = g_vdorec_osd_cntx.preview_wnd.rect.width;
    g_vdorec_cntx.preview_wnd_height = g_vdorec_osd_cntx.preview_wnd.rect.height;
    g_vdorec_cntx.preview_wnd_offset_x = g_vdorec_osd_cntx.preview_wnd.rect.offset_x;
    g_vdorec_cntx.preview_wnd_offset_y = g_vdorec_osd_cntx.preview_wnd.rect.offset_y;


#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__

#ifdef __MMI_SCREEN_ROTATE__
    mmi_frm_set_self_rotation_flag(MMI_FRM_SCREEN_ROTATE_270);
#endif 
/*

    if (g_vdorec_cntx.is_use_hw_rotate && !g_vdorec_cntx.is_use_hw_rotate_by_lcd)
    {
        layer_offset_x = 
            UI_device_width - 
            g_vdorec_cntx.preview_wnd_offset_y - 
            g_vdorec_cntx.preview_wnd_height;
        layer_offset_y = g_vdorec_cntx.preview_wnd_offset_x;
        layer_width = g_vdorec_cntx.preview_wnd_height;
        layer_height = g_vdorec_cntx.preview_wnd_width;   
    }
    else
    { 
        layer_offset_x = g_vdorec_cntx.preview_wnd_offset_x;
        layer_offset_y = g_vdorec_cntx.preview_wnd_offset_y;
        layer_width = g_vdorec_cntx.preview_wnd_width;
        layer_height = g_vdorec_cntx.preview_wnd_height;    
    }
    */

    /*gdi_layer_create(
        0,
        0,
        g_vdorec_cntx.preview_wnd_width,
        g_vdorec_cntx.preview_wnd_height,
        &g_vdorec_cntx.preview_layer_handle);*/

    buffer_size = g_vdorec_cntx.preview_wnd_width * g_vdorec_cntx.preview_wnd_height * VDOREC_BUFFER_DEPTH;
    layer_in.buffer = base_layer_ptr;
    layer_in.buffer_size = buffer_size;
    layer_in.offset_x = g_vdorec_cntx.preview_wnd_offset_x;
    layer_in.offset_y = g_vdorec_cntx.preview_wnd_offset_y;
    layer_in.width = g_vdorec_cntx.preview_wnd_width;
    layer_in.height = g_vdorec_cntx.preview_wnd_height;
    layer_in.scenario_id = MDI_MULTIMEDIA_RRECORD;
    g_vdorec_cntx.preview_layer_handle = mdi_util_hw_layer_create_with_extmemory(&layer_in, &layer_out);

    gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);

	#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    if(g_vdorec_cntx.is_use_hw_rotate)
    {    
        gdi_layer_set_rotate(GDI_LAYER_ROTATE_90);
    }
	#endif

    //gdi_layer_clear(GDI_COLOR_BLACK);

#ifdef GDI_USING_LAYER_BACKGROUND
    gdi_layer_set_background(GDI_COLOR_BLACK);
#endif  

#else /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

    /*gdi_layer_create(
        g_vdorec_cntx.preview_wnd_offset_x,
        g_vdorec_cntx.preview_wnd_offset_y,
        g_vdorec_cntx.preview_wnd_width,
        g_vdorec_cntx.preview_wnd_height,
        &g_vdorec_cntx.preview_layer_handle);*/

    buffer_size = g_vdorec_cntx.preview_wnd_width * g_vdorec_cntx.preview_wnd_height * VDOREC_BUFFER_DEPTH;
    layer_in.buffer = base_layer_ptr;
    layer_in.buffer_size = buffer_size;
    layer_in.offset_x = g_vdorec_cntx.preview_wnd_offset_x;
    layer_in.offset_y = g_vdorec_cntx.preview_wnd_offset_y;
    layer_in.width = g_vdorec_cntx.preview_wnd_width;
    layer_in.height = g_vdorec_cntx.preview_wnd_height;
    layer_in.scenario_id = MDI_MULTIMEDIA_RRECORD;
    g_vdorec_cntx.preview_layer_handle = mdi_util_hw_layer_create_with_extmemory(&layer_in, &layer_out);

    gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);
    gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
    //gdi_layer_clear(GDI_COLOR_BLACK);

#ifdef GDI_USING_LAYER_BACKGROUND
    gdi_layer_set_background(GDI_COLOR_BLACK);
#endif  

#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

    gdi_layer_pop_and_restore_active();

    /* resized preview layer */
#if defined(__VDOREC_FEATURE_VIDEO_SIZE__) || defined(__VDOREC_FEATURE_QVGA_RECORD_SUPPORT__)
    mmi_vdorec_resize_preview_layer();
#endif 
    g_vdorec_cntx.osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;

   /****************************************************************************
   * draw skin                                                                 
   *****************************************************************************/
    mmi_vdorec_init_ui();

    gdi_layer_reset_clip(); /* use full screen clip */
    gui_reset_text_clip();  /* use full screen text clip */

    gdi_layer_lock_frame_buffer();

    /* bg image */
   
#ifdef __VDOREC_FEATURE_SHOW_STATUS_BAR__
    wgui_status_icon_bar_set_target_layer(
        WGUI_STATUS_ICON_BAR_H_BAR,
        g_vdorec_cntx.status_bar_layer_handle);
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
#endif /* __VDOREC_FEATURE_SHOW_STATUS_BAR__ */
    
    mmi_vdorec_set_softkey(STR_GLOBAL_OPTIONS, STR_GLOBAL_BACK, 0, 0, IMG_ID_VDOREC_SK_PLAY);

    mmi_vdorec_draw_osd(
        VDOREC_OSD_COMPONENT_SOFTKEY|
        VDOREC_OSD_COMPONENT_TIMER);

    gdi_layer_unlock_frame_buffer();

	#ifndef __VDOREC_FEATURE_MULTI_REGION_SUPPORT__
	if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE)
    {
        gdi_layer_set_blt_layer(
            g_vdorec_cntx.preview_layer_handle,
            g_vdorec_cntx.osd_layer_handle,
            0,
            0);
    }
    #else 
	#ifdef __VDOREC_FEATURE_MULTI_REGION_LAYER_2__
	if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_TWO)
    {
        gdi_layer_set_blt_layer(
        g_vdorec_cntx.preview_layer_handle,
        g_vdorec_cntx.osd_layer_region_handle[0],
        g_vdorec_cntx.osd_layer_region_handle[1],
        g_vdorec_cntx.osd_layer_region_handle[2]);
    }
    else 
	#endif
		if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_THREE)
    {
        gdi_layer_set_blt_layer(
            g_vdorec_cntx.preview_layer_handle,
            g_vdorec_cntx.osd_layer_region_handle[0],
            g_vdorec_cntx.osd_layer_region_handle[1],
            g_vdorec_cntx.osd_layer_region_handle[2]);
    }
#ifdef GDI_6_LAYERS
    else
    {    
        gdi_layer_set_blt_layer_ext(
            g_vdorec_cntx.preview_layer_handle,
            g_vdorec_cntx.osd_layer_region_handle[0],
            g_vdorec_cntx.osd_layer_region_handle[1],
            g_vdorec_cntx.osd_layer_region_handle[2],
            g_vdorec_cntx.osd_layer_region_handle[3],
            0);
    }
#endif
	#endif

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        /*if enter new screen ,should redraw full screen, for some area is use layer background to fill color*/
        mmi_vdorec_set_merge_region(0,0, g_vdorec_cntx.lcd_width, g_vdorec_cntx.lcd_height);
    }
	#endif
    
    mmi_vdorec_blt_screen();

    /* this function is entry by small screen's history draw, no need to open file */
    if (mmi_is_redrawing_bk_screens())
    {
        return;
    }

    g_vdorec_cntx.record_time = 0;

    if (!mmi_vdorec_is_in_bgcall())
    {
        /* open video file */
        //mmi_ucs2cpy(g_vdorec_cntx.filepath, (PS8)L"d:\\videos\\PWRONOFF.mpg");
        g_vdorec_cntx.last_error = mdi_video_ply_open_clip_file(0, g_vdorec_cntx.filepath, &v_info);
        if (!mmi_vdorec_check_and_display_error_popup())
        {
            g_vdorec_cntx.video_duration = v_info.total_time_duration;
            gui_start_timer(5000, mmi_vdorec_preview_idle_timeout_hdlr);
            mmi_vdorec_enter_state(VDOREC_STATE_VIDEO_PREVIEW_STOP);
        }        
    }
    else
    {
        gui_start_timer(5000, mmi_vdorec_preview_idle_timeout_hdlr);
        mmi_vdorec_enter_state(VDOREC_STATE_VIDEO_PREVIEW_BGCALL);
    }
   
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_play_timer_cyclic
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_play_timer_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_PLAY_TIMER_CYCLIC);

    mdi_video_ply_get_cur_play_time(&(g_vdorec_cntx.record_time));
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_TIMER);
    mmi_vdorec_blt_screen();

    if (g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_PLAY)
    {
        gui_start_timer(200, mmi_vdorec_play_timer_cyclic);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_preview_play_finish_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_preview_play_finish_callback(MDI_RESULT res, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_PREVIW_PLAY_FINISH_CALLBACK);

    gui_cancel_timer(mmi_vdorec_play_timer_cyclic);
    if (g_vdorec_cntx.last_error >= MDI_RES_VDOPLY_SUCCEED ||
        !mmi_vdorec_check_and_display_error_popup())
    {
        g_vdorec_cntx.record_time = g_vdorec_cntx.video_duration;
        mmi_vdorec_enter_state(VDOREC_STATE_VIDEO_PREVIEW_STOP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_fsm_preview_play
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_fsm_preview_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 blt_layer_flag;
    U32 play_layer_flag;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_FSM_PREVIEW_PLAY);

    mmi_vdorec_set_softkey(STR_GLOBAL_OPTIONS, STR_GLOBAL_BACK, 0, 0, IMG_ID_VDOREC_SK_PLAY_PAUSE);

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        /*if enter new screen ,should redraw full screen, for some area is use layer background to fill color*/
        mmi_vdorec_set_merge_region(0,0, g_vdorec_cntx.lcd_width, g_vdorec_cntx.lcd_height);
    }
	#endif

    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
    mmi_vdorec_blt_screen();
    /* open video and play */

/*config the video layer*/
    play_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
    blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0;

	#ifndef __VDOREC_FEATURE_MULTI_REGION_SUPPORT__
    if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE)
    {
        blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
    }
    #else
    {
        if (g_vdorec_cntx.osd_layer_region_handle[0])
        {
            blt_layer_flag |= GDI_LAYER_ENABLE_LAYER_1;
        }
        
        if (g_vdorec_cntx.osd_layer_region_handle[1])
        {
            blt_layer_flag |= GDI_LAYER_ENABLE_LAYER_2;
        }
        
        if (g_vdorec_cntx.osd_layer_region_handle[2])
        {
            blt_layer_flag |= GDI_LAYER_ENABLE_LAYER_3;
        }
        
#ifdef GDI_6_LAYERS
        if (g_vdorec_cntx.osd_layer_region_handle[3])
        {
            blt_layer_flag |= GDI_LAYER_ENABLE_LAYER_4;
        }
#endif
    }
	#endif

    /* video will be open before enter play state */
    mdi_video_ply_seek(g_vdorec_cntx.record_time);

#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    mdi_video_ply_play(
        g_vdorec_cntx.preview_layer_handle,
        blt_layer_flag,
        play_layer_flag,
        1,
        TRUE,
        TRUE,
        MDI_DEVICE_SPEAKER2 ,
        MDI_VIDEO_LCD_ROTATE_270,
        100,
        mmi_vdorec_preview_play_finish_callback,
        0);
#else   /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */
    mdi_video_ply_play(
        g_vdorec_cntx.preview_layer_handle,
        blt_layer_flag,
        play_layer_flag,
        1,
        TRUE,
        TRUE,
        MDI_DEVICE_SPEAKER2 ,
        MDI_VIDEO_LCD_ROTATE_0,
        100,
        mmi_vdorec_preview_play_finish_callback,
        0);
#endif  /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */

    gui_start_timer(200, mmi_vdorec_play_timer_cyclic);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_fsm_preview_stop
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_fsm_preview_stop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_FSM_PREVIEW_STOP);

    mmi_vdorec_set_softkey(STR_GLOBAL_OPTIONS, STR_GLOBAL_BACK, 0, 0, IMG_ID_VDOREC_SK_PLAY);
    
    gui_cancel_timer(mmi_vdorec_play_timer_cyclic);   

    mdi_video_ply_stop();

    if (g_vdorec_cntx.record_time == g_vdorec_cntx.video_duration)
    {
        mdi_video_ply_seek_and_get_frame(0, g_vdorec_cntx.preview_layer_handle);
        g_vdorec_cntx.record_time = 0;
        gui_start_timer(5000, mmi_vdorec_preview_idle_timeout_hdlr);
    }
    else
    {
        mdi_video_ply_seek_and_get_frame(g_vdorec_cntx.record_time, g_vdorec_cntx.preview_layer_handle);
    }    
    
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY | VDOREC_OSD_COMPONENT_TIMER);

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        /*if enter new screen ,should redraw full screen, for some area is use layer background to fill color*/
        mmi_vdorec_set_merge_region(0,0, g_vdorec_cntx.lcd_width, g_vdorec_cntx.lcd_height);
    }
	#endif

    mmi_vdorec_blt_screen();
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_del_key_press_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_del_key_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DEL_KEY_PRESS_HDLR);

    if (!g_vdorec_cntx.is_del_key_pressed)
    {
        g_vdorec_cntx.is_del_key_pressed = TRUE;
        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
        mmi_vdorec_blt_screen();
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_del_key_release_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_del_key_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DEL_KEY_RELEASE_HDLR);

    if (g_vdorec_cntx.is_del_key_pressed)
    {

        g_vdorec_cntx.is_del_key_pressed = FALSE;
        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
        mmi_vdorec_blt_screen();
        switch(g_vdorec_cntx.state)
        {
            case VDOREC_STATE_VIDEO_PREVIEW_PLAY:
            case VDOREC_STATE_VIDEO_PREVIEW_STOP:
            case VDOREC_STATE_VIDEO_PREVIEW_BGCALL:
                mmi_vdorec_delete_saved_vdo_confirm();
                break;

            default:
                MMI_ASSERT(0);
                return;
        }
    }
}
#endif  /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

#if (!defined(__VDOREC_FEATURE_DIRECT_SAVE__) && !defined(__VDOREC_FEATURE_SLIM_UE__))||defined(__VDOREC_FEATURE_PREVIEW_SAVED_FILE__)

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_hide_unavailable_send_options
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_hide_unaviailable_send_options(void)
{
#ifndef __VDOREC_FEATURE_SLIM_UE__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #if defined(__VDOREC_FEATURE_MERGE_SEND_OPTION__)    
    BOOL hide_send_menu = TRUE;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* following menu items should be hidden when in */
    /* 1. external request                           */
    /* 2. flight mode                                */
    /* 3. or sim is not ready (mms)                  */

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HIDE_UNAVIAILABLE_SEND_OPTIONS);

    #ifdef __VDOREC_FEATURE_BT_SEND_SUPPORT__
        if (g_vdorec_cntx.is_ext_req)
        {
            mmi_frm_hide_menu_item(MENU_ID_VDOREC_TO_BT);
        }
        else if (!mmi_bt_is_to_display_bt_menu())
        {
            mmi_frm_hide_menu_item(MENU_ID_VDOREC_TO_BT);
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_ID_VDOREC_TO_BT);
        #if defined(__VDOREC_FEATURE_MERGE_SEND_OPTION__)
            hide_send_menu = FALSE;
        #endif
        }
    #else
        /*mmi_frm_hide_menu_item(MENU_ID_VDOREC_TO_BT);*/
    #endif /* __VDOREC_FEATURE_BT_SEND_SUPPORT__ */      

    #if defined(__VDOREC_FEATURE_EMAIL_SUPPORT__)
        if (!mmi_email_is_email_can_forward() || !srv_mode_switch_is_network_service_available() || g_vdorec_cntx.is_ext_req)
        {
            mmi_frm_hide_menu_item(MENU_ID_VDOREC_TO_EMAIL);      
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_ID_VDOREC_TO_EMAIL);
        #if defined(__VDOREC_FEATURE_MERGE_SEND_OPTION__)
            hide_send_menu = FALSE;        
        #endif

        }
    #else
        /*mmi_frm_hide_menu_item(MENU_ID_VDOREC_TO_EMAIL);      */
    #endif /* defined(__VDOREC_FEATURE_EMAIL_SUPPORT__) */

    #if defined(__VDOREC_FEATURE_MMS_SUPPORT__)
        if(!mms_is_ready() || g_vdorec_cntx.is_ext_req)
        {
            mmi_frm_hide_menu_item(MENU_ID_VDOREC_TO_MMS);
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_ID_VDOREC_TO_MMS);
        #if defined(__VDOREC_FEATURE_MERGE_SEND_OPTION__)
            hide_send_menu = FALSE;        
        #endif
        }
    #else
        /*mmi_frm_unhide_menu_item(MENU_ID_VDOREC_TO_MMS);*/
    #endif /* __VDOREC_FEATURE_MMS_SUPPORT__ */

    #if defined(__VDOREC_FEATURE_MERGE_SEND_OPTION__)
        if (hide_send_menu)
        {
            mmi_frm_hide_menu_item(MENU_ID_VDOREC_SEND);
        }
        else
        {
            mmi_frm_unhide_menu_item(MENU_ID_VDOREC_SEND);
        }
    #endif /* __VDOREC_FEATURE_MERGE_SEND_OPTION__ */

#endif  /*__VDOREC_FEATURE_SLIM_UE__*/
}
#endif

#if !defined(__VDOREC_FEATURE_DIRECT_SAVE__) && !defined(__VDOREC_FEATURE_SLIM_UE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_send_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_send_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U16 ItemIcons[16] = 
    {
        IMG_GLOBAL_L1, 
            IMG_GLOBAL_L2,
            IMG_GLOBAL_L3,
            IMG_GLOBAL_L4,
            IMG_GLOBAL_L5,
            IMG_GLOBAL_L6,
            IMG_GLOBAL_L7,
            IMG_GLOBAL_L8,
            IMG_GLOBAL_L9,
            IMG_GLOBAL_L10,
            IMG_GLOBAL_L11,
            IMG_GLOBAL_L12,
            IMG_GLOBAL_L13,
            IMG_GLOBAL_L14,
            IMG_GLOBAL_L15,
            IMG_GLOBAL_L16
    };
    U8 *guiBuffer;
    MMI_BOOL entry_ret;
    U16 nItems;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_SEND_SCREEN);

    entry_ret = mmi_frm_scrn_enter (g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SEND, NULL, mmi_vdorec_entry_send_screen, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_gui_buf(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SEND);

#if (!defined(__VDOREC_FEATURE_DIRECT_SAVE__) && !defined(__VDOREC_FEATURE_SLIM_UE__))||defined(__VDOREC_FEATURE_RSK_DELETE__)
    mmi_vdorec_hide_unaviailable_send_options();
#endif
    
    nItems = GetNumOfChild_Ext(MENU_ID_VDOREC_SEND);
    GetSequenceStringIds_Ext(MENU_ID_VDOREC_SEND, ItemList);
    SetParentHandler(MENU_ID_VDOREC_SEND);

    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

    ShowCategory52Screen(
        STR_GLOBAL_SEND,
        GetRootTitleIcon(MENU_ID_VDOREC_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        ItemIcons,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction((mmi_void_funcptr_type)mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}
#endif  /*!defined(__VDOREC_FEATURE_DIRECT_SAVE__)*/


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_load_saved_filename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_load_saved_filename(CHAR * filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_LOAD_SAVED_FILENAME);

    mmi_vdorec_load_setting();
    mmi_ucs2ncat(filepath, g_vdorec_cntx.setting.save_name, SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
}

#ifdef __VDOREC_FEATURE_LIMIT_PROGRESS_BAR__

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_update_progress_ratio
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_update_progress_ratio(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 progress_time = 0;
    U32 progress_size = 0;
    U64 current_time_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_UPDATE_PROGRESS_RATIO);
    
    /* calculate size limit */
    current_time_size = mdi_video_rec_get_record_file_size();       /* in bytes */
    if (g_vdorec_cntx.is_ext_req)
    {
        if (g_vdorec_cntx.ext_req_size != 0)
        {
            progress_size = (U32) current_time_size / (U32) g_vdorec_cntx.ext_req_size / 10;
        }
    }
    else if (g_vdorec_cntx.setting.size_limit != 0)
    {
        progress_size =
            (U32) current_time_size / vdorec_video_size_limit_command_map[g_vdorec_cntx.setting.size_limit] / 10;
    }

    /* calculate time limit */
    /* g_vdorec_cntx.record_time */
    if (g_vdorec_cntx.is_ext_req)
    {
        if (g_vdorec_cntx.ext_rec_time != 0)
        {
            progress_time = (U32)g_vdorec_cntx.record_time / (U32) g_vdorec_cntx.ext_rec_time / 10;
        }
    }
    else if (g_vdorec_cntx.setting.time_limit != 0)
    {
        progress_time =
            (U32)g_vdorec_cntx.record_time / (U32) vdorec_video_time_limit_command_map[g_vdorec_cntx.setting.time_limit] / 10;

    }

    /* update progress */
    if (progress_time == 0 && progress_size == 0)
    {
        g_vdorec_cntx.progress = 0;
    }
    else
    {
        if (progress_time > progress_size)
        {
            g_vdorec_cntx.progress = (progress_time > g_vdorec_cntx.progress)? (U16) progress_time : g_vdorec_cntx.progress;
        }
        else
        {
            g_vdorec_cntx.progress = (progress_size > g_vdorec_cntx.progress)? (U16) progress_size : g_vdorec_cntx.progress;
        }  
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_clear_panel_progress_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_clear_panel_progress_bar(void)
{
#ifdef __VDOREC_FEATURE_LIMIT_PROGRESS_BAR__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    S32 layer_offset_x;
    S32 layer_offset_y;
    S32 offset_x1, offset_y1, offset_x2, offset_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_CLEAR_PANEL_PROGRESS_BAR);

    gdi_layer_push_and_set_active(g_vdorec_cntx.timer_draw_layer);

    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_image_get_dimension_id(IMG_ID_VDOREC_PROGRESS_FILL, &image_width, &image_height);

    offset_x1 = g_vdorec_osd_cntx.panel.progress_bar.offset_x - layer_offset_x;
    offset_y1 = g_vdorec_osd_cntx.panel.progress_bar.offset_y - layer_offset_y;
    offset_x2 = g_vdorec_osd_cntx.panel.progress_bar.offset_x + image_width - layer_offset_x;
    offset_y2 = g_vdorec_osd_cntx.panel.progress_bar.offset_y + image_height - layer_offset_y;

    gdi_draw_solid_rect(offset_x1, offset_x2, offset_y1, offset_y2, GDI_COLOR_TRANSPARENT);

    gdi_layer_pop_and_restore_active();

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_osd_cntx.panel.progress_bar.offset_x, 
            g_vdorec_osd_cntx.panel.progress_bar.offset_y, 
            image_width, 
            image_height);
    }
	#endif
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_progress_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_panel_progress_bar(U8 ratio)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __VDOREC_FEATURE_LIMIT_PROGRESS_BAR__    
    S32 layer_offset_x;
    S32 layer_offset_y;
    S32 bar_width;
    S32 bar_height;
    GDI_RESULT tmp;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_PANEL_PROGRESS_BAR, ratio);

    if (!mmi_vdorec_is_draw_progress_bar())
    {
        return;
    }

#ifdef __VDOREC_FEATURE_LIMIT_PROGRESS_BAR__
    gdi_layer_push_and_set_active(g_vdorec_cntx.progress_draw_layer);

    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_image_get_dimension_id(IMG_ID_VDOREC_PROGRESS_FILL, &bar_width, &bar_height);

    /* draw_background */
    tmp = gdi_image_draw_id(g_vdorec_osd_cntx.panel.progress_bar.offset_x - layer_offset_x,
                      g_vdorec_osd_cntx.panel.progress_bar.offset_y - layer_offset_y,
                      IMG_ID_VDOREC_PROGRESS_EMPTY);
    /* set clip, draw fill progress */
    if (ratio != 0)
    {
        //gdi_layer_push_clip();
        gdi_layer_push_and_set_clip(
            g_vdorec_osd_cntx.panel.progress_bar.offset_x - layer_offset_x,
            g_vdorec_osd_cntx.panel.progress_bar.offset_y - layer_offset_y,
            g_vdorec_osd_cntx.panel.progress_bar.offset_x - layer_offset_x + bar_width * ratio / 100,
            g_vdorec_osd_cntx.panel.progress_bar.offset_y - layer_offset_y + bar_height);
        gdi_image_draw_id(
            g_vdorec_osd_cntx.panel.progress_bar.offset_x - layer_offset_x,
            g_vdorec_osd_cntx.panel.progress_bar.offset_y - layer_offset_y,
            IMG_ID_VDOREC_PROGRESS_FILL);
        gdi_layer_pop_clip();
    }

    gdi_layer_pop_and_restore_active();

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_osd_cntx.panel.progress_bar.offset_x,
            g_vdorec_osd_cntx.panel.progress_bar.offset_y,
            bar_width * ratio / 100,
            bar_height);
    }
	#endif
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_is_draw_progress_bar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_vdorec_is_draw_progress_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret = FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_IS_DRAW_PROGRESS_BAR);

#ifndef __VDOREC_FEATURE_LIMIT_PROGRESS_BAR__
	return ret;
#else
    if (g_vdorec_cntx.is_ext_req)
     {
         if ((g_vdorec_cntx.ext_req_size != 0) || (g_vdorec_cntx.ext_rec_time != 0))
         {
            ret = TRUE;
         }
     }
     else if ((g_vdorec_cntx.setting.size_limit != 0) || (g_vdorec_cntx.setting.time_limit != 0))
     {
         ret = TRUE;
     }
     return ret;
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_clear_ev
* DESCRIPTION
*  clear ev icon
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_clear_ev(void)
{
#if defined(__VDOREC_FEATURE_EV__) && !defined(__VDOREC_FEATURE_FTE_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    S32 layer_offset_x;
    S32 layer_offset_y;
    S32 offset_x1, offset_y1, offset_x2, offset_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    gdi_layer_push_and_set_active(g_vdorec_cntx.ev_draw_layer);
    
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

#ifdef __VDOREC_FEATURE_SLIM_UE__
    /* clear "+" ," ", "-" */
    offset_x1 = g_vdorec_osd_cntx.panel.ev.offset_x - layer_offset_x;
    offset_y1 = g_vdorec_osd_cntx.panel.ev.offset_y - layer_offset_y;

    gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_EV_HEAD ,&image_width, &image_height);
    offset_x1 += image_width;
    
    /* clear ev value, ev value is in front of ev_dec */
    offset_x2 = g_vdorec_osd_cntx.panel.ev_dec.offset_x - layer_offset_x;
    offset_y2 = g_vdorec_osd_cntx.panel.ev_dec.offset_y - layer_offset_y;    

    gdi_draw_solid_rect(offset_x1, offset_y1, offset_x2, offset_y2, GDI_COLOR_TRANSPARENT);

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_osd_cntx.panel.ev.offset_x + image_width, 
            g_vdorec_osd_cntx.panel.ev.offset_y, 
            g_vdorec_osd_cntx.panel.ev_dec.offset_x - g_vdorec_osd_cntx.panel.ev.offset_x, 
            image_height);
    }
	#endif
    
#else
    
    // clear ev head
    gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_EV_0, &image_width, &image_height);
    
    offset_x1 = g_vdorec_osd_cntx.panel.ev.offset_x - layer_offset_x;
    offset_y1 = g_vdorec_osd_cntx.panel.ev.offset_y - layer_offset_y;
    offset_x2 = g_vdorec_osd_cntx.panel.ev.offset_x + image_width - layer_offset_x;
    offset_y2 = g_vdorec_osd_cntx.panel.ev.offset_y + image_height - layer_offset_y;
    
    gdi_draw_solid_rect(offset_x1, offset_y1, offset_x2, offset_y2, GDI_COLOR_TRANSPARENT);

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_osd_cntx.panel.ev.offset_x, 
            g_vdorec_osd_cntx.panel.ev.offset_y, 
            image_width, 
            image_height);
    }
	#endif
#endif  /*__VDOREC_FEATURE_SLIM_UE__*/

    // clear ev inc
    gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_EV_INC, &image_width, &image_height);
    
    offset_x1 = g_vdorec_osd_cntx.panel.ev_inc.offset_x - layer_offset_x;
    offset_y1 = g_vdorec_osd_cntx.panel.ev_inc.offset_y - layer_offset_y;
    offset_x2 = g_vdorec_osd_cntx.panel.ev_inc.offset_x + image_width - layer_offset_x;
    offset_y2 = g_vdorec_osd_cntx.panel.ev_inc.offset_y + image_height - layer_offset_y;
    
    gdi_draw_solid_rect(offset_x1, offset_y1, offset_x2, offset_y2, GDI_COLOR_TRANSPARENT);

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_osd_cntx.panel.ev_inc.offset_x, 
            g_vdorec_osd_cntx.panel.ev_inc.offset_y, 
            image_width, 
            image_height);
    }
	#endif

    // clear ev dec
    gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_EV_DEC, &image_width, &image_height);
    
    offset_x1 = g_vdorec_osd_cntx.panel.ev_dec.offset_x - layer_offset_x;
    offset_y1 = g_vdorec_osd_cntx.panel.ev_dec.offset_y - layer_offset_y;
    offset_x2 = g_vdorec_osd_cntx.panel.ev_dec.offset_x + image_width - layer_offset_x;
    offset_y2 = g_vdorec_osd_cntx.panel.ev_dec.offset_y + image_height - layer_offset_y;
    
    gdi_draw_solid_rect(offset_x1, offset_y1, offset_x2, offset_y2, GDI_COLOR_TRANSPARENT);

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_osd_cntx.panel.ev_dec.offset_x, 
            g_vdorec_osd_cntx.panel.ev_dec.offset_y, 
            image_width, 
            image_height);
    }
	#endif

    gdi_layer_pop_and_restore_active();
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_notify_storage_change_evt_hdlr
* DESCRIPTION
*  storage change hdlr
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret mmi_vdorec_notify_storage_change_evt_hdlr(mmi_event_struct *evt)
{
#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE)
    {
        srv_fmgr_notification_set_def_storage_event_struct *fmgr_event = (srv_fmgr_notification_set_def_storage_event_struct*)evt; 
        if (fmgr_event->state == SRV_FMGR_NOTIFICATION_STATE_AFTER)
        {
            mmi_vdoply_set_storage((U16)fmgr_event->drv_letter);            
        }
        
    }
#endif
    return MMI_RET_OK;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_is_in_bgcall
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_vdorec_is_in_bgcall(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_IS_IN_BG_CALL);

#ifdef __MMI_UCM__
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
#else
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_delete_all_from_history
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_vdorec_delete_all_from_history(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DELETE_ALL_FROM_HISTORY);
    
    mmi_frm_group_close(g_vdorec_cntx.cur_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_init_according_to_compile_option
 * DESCRIPTION
 *  init variable according to the compile option
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_init_according_to_compile_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_INIT_ACCORDING_COMPILE_OPTION);

	/*get the layer count*/
#ifndef __VDOREC_FEATURE_MULTI_REGION_SUPPORT__
    g_vdorec_cntx.osd_layer_region_count = VDOREC_OSD_LAYER_COUNT_ONE;
#else    

#ifdef __VDOREC_FEATURE_MULTI_REGION_LAYER_2__
    g_vdorec_cntx.osd_layer_region_count = VDOREC_OSD_LAYER_COUNT_TWO;
#endif

#ifdef __VDOREC_FEATURE_MULTI_REGION_LAYER_3__
    g_vdorec_cntx.osd_layer_region_count = VDOREC_OSD_LAYER_COUNT_THREE;
#endif
    
#ifdef __VDOREC_FEATURE_MULTI_REGION_LAYER_4__
    g_vdorec_cntx.osd_layer_region_count = VDOREC_OSD_LAYER_COUNT_FOUR;
#endif

#endif

#ifdef __VDOREC_FEATURE_MULTI_REGION_SUPPORT__
	g_vdorec_cntx.osd_layer_region_count = VDOREC_OSD_LAYER_COUNT_THREE;
#endif

	for(i=0;i<4;i++)
	{
		g_vdorec_cntx.osd_layer_region_handle[i] = GDI_LAYER_EMPTY_HANDLE;
		g_vdorec_cntx.tmp_osd_layer_region_handle[i] = GDI_LAYER_EMPTY_HANDLE;
	}

	/*display hint or not*/
#ifdef __VDOREC_FEATURE_HIDE_HINT__
	g_vdorec_osd_cntx.hint.is_show = FALSE;
#endif
	
	/*display timer or not*/
#ifdef __VDOREC_FEATURE_HIDE_TIMER__
	g_vdorec_cntx.is_timer_show = MMI_FALSE;
#else
	g_vdorec_cntx.is_timer_show = MMI_TRUE;
#endif

#ifdef __VDOREC_FEATURE_ZOOM__
	g_vdorec_cntx.is_zoom_support = MMI_TRUE;
#else
	g_vdorec_cntx.is_zoom_support = MMI_FALSE;
#endif

#ifdef __VDOREC_FEATURE_FAST_ZOOM__
	g_vdorec_cntx.is_fast_zoom_support = MMI_TRUE;
#else
	g_vdorec_cntx.is_fast_zoom_support = MMI_FALSE;
#endif


#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    g_vdorec_cntx.is_use_hw_rotate = MMI_TRUE;
#ifdef __MDI_VIDEO_HW_ROTATOR_BY_LCD__
    g_vdorec_cntx.is_use_hw_rotate_by_lcd = MMI_TRUE;
#else
    g_vdorec_cntx.is_use_hw_rotate_by_lcd = MMI_FALSE;
#endif
#else
    g_vdorec_cntx.is_use_hw_rotate = MMI_FALSE;
#endif

#ifdef __VDOREC_USING_BLT_REGION__
    g_vdorec_cntx.is_use_blt_region = MMI_FALSE;
#endif

#ifdef __VDOREC_PREVIEW_WATCHDOG_TIMEOUT__
    g_vdorec_cntx.is_watchdog_support = MMI_TRUE;
#else
    g_vdorec_cntx.is_watchdog_support = MMI_FALSE;
#endif

#ifndef __MMI_VIDEO_RECORDER_SLIM__
#ifdef VDOREC_TOGGLE_HIDE_OSD_KEY
    if (VDOREC_TOGGLE_HIDE_OSD_KEY != -1)
    {
        g_vdorec_cntx.is_support_toggle_osd = MMI_FALSE;
    }
    else
    {
        g_vdorec_cntx.is_support_toggle_osd = MMI_FALSE;
    }
#else
    g_vdorec_cntx.is_support_toggle_osd = MMI_FALSE;
#endif
#endif

    g_vdorec_cntx.is_gdi_double_buffer_enable = MMI_FALSE;
#ifdef __VDOREC_DOUBLE_BUFFER_SUPPORT__
    g_vdorec_cntx.is_gdi_double_buffer_enable = MMI_TRUE;
#endif
}

#ifdef __VDOREC_USING_BLT_REGION__
/*****************************************************************************
* FUNCTION
*  mmi_mscr_merge_blt_rgn
* DESCRIPTION
*  merge blt region
* PARAMETERS
*  void        
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_merge_blt_rgn(S32 x, S32 y, S32 w, S32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    S32 x2, y2, real_x = 0, real_y = 0, real_w = 0, real_h = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_MERGE_BLT_REGION_BEFORE, x, y, w, h);

    if (x < 0)
    {
        x = 0;
    }
    if (y < 0)
    {
        y = 0;
    }

	#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    if (g_vdorec_cntx.is_use_hw_rotate)
    {
        real_x = g_vdorec_cntx.lcd_width - h - y;
        real_y = x;
        real_w = h;
        real_h = w;
    }
    #else
    {
        real_x = x;
        real_y = y;
        real_w = w;
        real_h = h;
    }
	#endif

    if (g_vdorec_cntx.blt_area_w == 0 || g_vdorec_cntx.blt_area_h == 0)
    {
        mmi_vdorec_set_merge_region(real_x, real_y, real_w, real_h);
        return;
    }
    x2 = g_vdorec_cntx.blt_area_x + g_vdorec_cntx.blt_area_w;
    y2 = g_vdorec_cntx.blt_area_y + g_vdorec_cntx.blt_area_h;
    
    if (g_vdorec_cntx.blt_area_x > real_x)
    {
        g_vdorec_cntx.blt_area_x = real_x;
    }
    if (g_vdorec_cntx.blt_area_y > real_y)
    {
        g_vdorec_cntx.blt_area_y = real_y;
    }
    if (x2 < real_x + real_w)
    {
        x2 = real_x + real_w;
    }
    if (y2 < real_y + real_h)
    {
        y2 = real_y + real_h;
    }  
    g_vdorec_cntx.blt_area_w = x2 - g_vdorec_cntx.blt_area_x;
    g_vdorec_cntx.blt_area_h = y2 - g_vdorec_cntx.blt_area_y;

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_MERGE_BLT_REGION_AFTER, 
        g_vdorec_cntx.blt_area_x, g_vdorec_cntx.blt_area_y, g_vdorec_cntx.blt_area_w, g_vdorec_cntx.blt_area_h);
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_set_merge_region
* DESCRIPTION
*  set the blt area
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_set_merge_region(S32 x, S32 y, S32 w, S32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SET_BLT_REGION, x, y, w, h);

    g_vdorec_cntx.blt_area_x = x;
    g_vdorec_cntx.blt_area_y = y;
    g_vdorec_cntx.blt_area_w = w;
    g_vdorec_cntx.blt_area_h = h;
}
#endif


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_listen_key_proc
* DESCRIPTION
*  key proc function for video recorder
* PARAMETERS
*  evt      : [IN]  key event
* RETURNS
*  MMI_RET_OK to continue key event routing
*  MMI_RET_KEY_HANDLED to stop key event routing
*****************************************************************************/
static mmi_ret mmi_vdorec_listen_key_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_evt->evt_id == EVT_ID_PRE_KEY)
    {
        if (g_vdorec_cntx.state == VDOREC_STATE_PREVIEW)
        {
            mmi_vdorec_pre_key_listen_hdlr();
        }
    #ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
        else if (g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_STOP ||
            g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_BGCALL)
        {
            mmi_vdorec_preview_idle_timeout_cancel();
        }
    #endif
    }
    else if (key_evt->evt_id == EVT_ID_POST_KEY)
    {
        if (g_vdorec_cntx.state == VDOREC_STATE_PREVIEW)
        {
            mmi_vdorec_post_key_listen_hdlr();
        }
    #ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
        else if (g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_STOP ||
            g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_BGCALL)
        {
            if (g_vdorec_cntx.record_time == 0)
                gui_start_timer(5000, mmi_vdorec_preview_idle_timeout_hdlr);
        }
    #endif
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_pre_key_listen_hdlr
* DESCRIPTION
*  use pre key to stop watch dog
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static U8 mmi_vdorec_pre_key_listen_hdlr(void)
{
#ifdef __VDOREC_PREVIEW_WATCHDOG_TIMEOUT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_PRE_KEY_LISTEN_HDLR);

    mmi_vdorec_reset_watchdog_time_out_handler();
#endif

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_post_key_listen_hdlr
* DESCRIPTION
*  use post key to restore watch dog
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static U8 mmi_vdorec_post_key_listen_hdlr(void)
{
#ifdef __VDOREC_PREVIEW_WATCHDOG_TIMEOUT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_POST_KEY_LISTEN_HDLR);

    mmi_vdorec_reset_watchdog_time_out_handler();
    mmi_vdorec_watchdog_time_out_handler();
#endif

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_reset_watchdog_time_out_handler
* DESCRIPTION
*  reset watch dog
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_reset_watchdog_time_out_handler(void)
{
#ifdef __VDOREC_PREVIEW_WATCHDOG_TIMEOUT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_RESET_WATCHDOG);

    gui_cancel_timer(mmi_vdorec_watchdog_time_out_handler);
    g_vdorec_cntx.watchdog_listen_duration = 0;
#endif /* __VDOREC_PREVIEW_WATCHDOG_TIMEOUT__ */ 
}


/*****************************************************************************
* FUNCTION
*  mmi_bcr_watchdog_time_out_handler
* DESCRIPTION
*  watch dog listen handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_watchdog_time_out_handler(void)
{
#ifdef __VDOREC_PREVIEW_WATCHDOG_TIMEOUT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_START_WATCH_DOG);

    if (g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
    {
        /*if you start watch dog when vdorec is not in preview state, will give no response*/
        return;
    }

    if (g_vdorec_cntx.watchdog_listen_duration < MMI_VDOREC_WATCHDOG_TIMEOUT_DUR_MAX/MMI_VDOREC_WATCHDOG_TIMEOUT_DUR_INTERVAL)
    {
        g_vdorec_cntx.watchdog_listen_duration++;
        gui_start_timer(MMI_VDOREC_WATCHDOG_TIMEOUT_DUR_INTERVAL, mmi_vdorec_watchdog_time_out_handler);
    }
    else
    {
        if (mmi_frm_scrn_get_active_id() == SCR_ID_VDOREC_APP)
        {
            mmi_frm_scrn_close_active_id();
        }
    }
#endif /* __VDOREC_PREVIEW_WATCHDOG_TIMEOUT__ */ 
}


#ifdef __VDOREC_FEATURE_MMS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_to_mms_hdlr
 * DESCRIPTION
 *  mms forward handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_to_mms_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_TO_MMS_HDLR);

    mms_content_insert_hdlr(g_vdorec_cntx.filepath);
    mmi_frm_scrn_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SEND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_to_mms
 * DESCRIPTION
 *  mms forward hilighte handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_highlight_to_mms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HIGHLIGHT_TO_MMS);

    SetLeftSoftkeyFunction(mmi_vdorec_to_mms_hdlr, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_vdorec_to_mms_hdlr, KEY_EVENT_UP);
}
#endif


#ifdef __VDOREC_FEATURE_EMAIL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_to_email_hdlr
 * DESCRIPTION
 *  mms forward hilighte handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_to_email_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_OP11_CAMERA_VDOREC_CUSTOMIZE__    
    mmi_email_app_send_param_struct email_param;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_TO_EMAIL_HDLR);

#ifdef __MMI_OP11_CAMERA_VDOREC_CUSTOMIZE__
    mmi_email_app_send_attch_to_addr(g_vdorec_cntx.filepath);
#else /* __MMI_OP11_CAMERA_VDOREC_CUSTOMIZE__ */
    mmi_email_app_send_init_param_to_null(&email_param);
    email_param.attch_file_path = (CHAR*)g_vdorec_cntx.filepath;
    mmi_email_app_send(&email_param, EMAIL_ATTCH_FILL_FLAG);
#endif /* __MMI_OP11_CAMERA_VDOREC_CUSTOMIZE__ */

    mmi_frm_scrn_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SEND);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_to_email
 * DESCRIPTION
 *  mms forward hilighte handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_highlight_to_email(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HIGHLIGHT_TO_EMAIL);

    SetLeftSoftkeyFunction(mmi_vdorec_to_email_hdlr, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_vdorec_to_email_hdlr, KEY_EVENT_UP);
}
#endif /*  __VDOREC_FEATURE_EMAIL_SUPPORT__*/


#ifdef __VDOREC_FEATURE_BT_SEND_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_to_BT_hdlr
 * DESCRIPTION
 *  to BT hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_to_BT_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_bt_sending_para_struct para;
    cui_bt_sending_obj_struct obj;
    
    obj.data.obj_type = CUI_BT_SENDIND_USE_FILE;
    obj.data.u.file.path = (PU16)g_vdorec_cntx.filepath;
    obj.name = NULL;
    
    para.total = 1;
    para.obj = &obj;
    
#ifdef __MMI_BT_DEF_SEND_DEVICE__
    para.option = CUI_BT_SENDIND_OPT_DEFAULT_DEVICE;
#else
    para.option = CUI_BT_SENDIND_OPT_NORMAL;
#endif

    cui_bt_sending_launch(g_vdorec_cntx.cur_gid, &para);

    mmi_frm_scrn_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SEND);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_TO_BT_HDLR);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_highlight_to_bluetooth
 * DESCRIPTION
 *  to BT hilight hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_highlight_to_bluetooth(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HILIGHT_TO_BLUETOOTH);

    SetLeftSoftkeyFunction(mmi_vdorec_to_BT_hdlr, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_vdorec_to_BT_hdlr, KEY_EVENT_UP);
}
#endif /* __VDOREC_FEATURE_BT_SEND_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_delete_group
 * DESCRIPTION
 *  vdorec group deinit
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_delete_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdorec_cntx.is_ext_req)
    {
        mmi_vdorec_post_to_parent(CUI_VDOREC_RECORD_EVENT_RESULT_CLOSE_ME, NULL);
    }
    else
    {
        mmi_frm_group_close(g_vdorec_cntx.cur_gid);   
    }
	#ifdef __MMI_AP_DCM_VDOREC__
	mmi_ap_send_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_VDOREC);
	#endif
}
#ifdef __VDOREC_FEATURE_SWITCH_TO_CAMERA__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_switch_to_camera_hdlr
 * DESCRIPTION
 *  switch to camera app.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_switch_to_camera_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SWITCH_TO_CAMERA_HDLR);

    switch(g_vdorec_cntx.state)
    {
        case VDOREC_STATE_RECORD:
        case VDOREC_STATE_PAUSE:
        case VDOREC_STATE_VIDEO_PREVIEW_PLAY:
        case VDOREC_STATE_VIDEO_PREVIEW_STOP:
            return;

        case VDOREC_STATE_BG_CALL:
        case VDOREC_STATE_VIDEO_PREVIEW_BGCALL:
            mmi_vdorec_disply_popup(
                STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL,
                MMI_EVENT_FAILURE,
                MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
            break;
            
        default:
            if (g_vdorec_cntx.is_ext_req)
            {
                /*do nothing*/
                return;
            }
            else
            {
                MMI_BOOL is_lauch = MMI_TRUE;
            
                if (is_lauch)    
                {
                    /* aim to avoid screen change when close vdorec group */
                    //EntryNewScreen(SCR_ID_VDOREC_END, NULL, NULL, NULL);
                    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_DEFAULT);
                    mmi_vdorec_delete_group();
                    mmi_camera_lauch();
                }
                else
                {
                    cui_camera_run_struct camera_struct;                    
                    cui_camera_struct_init(&camera_struct);
                    
                    //g_vdorec_cntx.camera_gid = cui_camera_ex_create(APP_CAMERA, mmi_vdorec_app_group_proc);
                    //cui_camera_ex_run(APP_VDOREC, g_vdorec_cntx.camera_gid, &camera_struct);
                    g_vdorec_cntx.camera_gid = cui_camera_create(g_vdorec_cntx.cur_gid);
                    cui_camera_run(g_vdorec_cntx.camera_gid, &camera_struct);
                }
            }
            break;
    }
}
#endif /* __VDOREC_FEATURE_SWITCH_TO_CAMERA__ */

#ifndef __MMI_VIDEO_RECORDER_SLIM__
#ifdef VDOREC_TOGGLE_HIDE_OSD_KEY
/*****************************************************************************
* FUNCTION
*  mmi_vdorec_toggle_osd_key_press_hdlr
* DESCRIPTION
*  show/hide osd hdlr
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_toggle_osd_key_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_vdorec_cntx.is_osd_hide = (MMI_BOOL)~g_vdorec_cntx.is_osd_hide;

    if (g_vdorec_cntx.state == VDOREC_STATE_PREVIEW)
    {
        if (g_vdorec_cntx.is_osd_hide)
        {
            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_CLEAR_ZOOM | VDOREC_OSD_COMPONENT_CLEAR_EV | VDOREC_OSD_COMPONENT_CLEAR_STATUS);
        }
        else
        {
            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM | VDOREC_OSD_COMPONENT_EV | VDOREC_OSD_COMPONENT_STATUS);
        }
    }
    else if ((g_vdorec_cntx.state == VDOREC_STATE_RECORD) || (g_vdorec_cntx.state == VDOREC_STATE_PAUSE))
    {
        if (g_vdorec_cntx.is_osd_hide)
        {
            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_CLEAR_ZOOM | VDOREC_OSD_COMPONENT_CLEAR_EV);
        }
        else
        {
            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM | VDOREC_OSD_COMPONENT_EV);
        }
    }

    mmi_vdorec_blt_screen();
}
#endif
#endif

/*****************************************************************************
* FUNCTION
*  mmi_vdorec_use_phone_storage_hdlr
* DESCRIPTION
*  check the driver is valid or not
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_use_phone_storage_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_vdoply_set_storage((U16) SRV_FMGR_PUBLIC_DRV);
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_storage_change
* DESCRIPTION
*  change storage
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_storage_change(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32  total_drv_num;
    SRV_FMGR_DRVLIST_HANDLE drv_list;
    U16 storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    drv_list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY);
    total_drv_num = srv_fmgr_drivelist_count(drv_list); 
    srv_fmgr_drivelist_destroy(drv_list);

    storage = mmi_vdoply_get_storage();

    if (total_drv_num == 0)
    {
        /* no storage is avaible right now, need to plug memory card */
        mmi_vdorec_disply_popup(
            STR_GLOBAL_INSERT_MEMORY_CARD,
            MMI_EVENT_INFO, 
            MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
    }
    else if (total_drv_num == 1)
    {
        if (SRV_FMGR_PUBLIC_DRV == SRV_FMGR_CARD_DRV || storage == SRV_FMGR_PHONE_DRV)
        {
            mmi_vdorec_disply_popup(
                srv_fmgr_fs_error_get_string(FS_DRIVE_NOT_FOUND),
                MMI_EVENT_FAILURE,
                MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
        }
        else
        {
            mmi_vdorec_drv_not_ready_process();    
        }
    }
    else
    {
        /* more than 2 storage is avaible */
        #ifdef __VDOREC_FEATURE_STORAGE__
        mmi_vdorec_entry_set_app_storage_screen(TRUE);
        #endif
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_drv_not_ready_process_cb
* DESCRIPTION
*  driver is not ready
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_vdorec_drv_not_ready_process_cb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            mmi_vdorec_use_phone_storage_hdlr();
            break;

        case MMI_ALERT_CNFM_NO:
            mmi_frm_scrn_close_active_id();
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_drv_not_ready_process
* DESCRIPTION
*  driver is not ready proc
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_drv_not_ready_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)mmi_vdorec_drv_not_ready_process_cb;
    arg.parent_id = g_vdorec_cntx.cur_gid;
    arg.rotation = MMI_FRM_SCREEN_ROTATE_0;
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    arg.rotation = MMI_FRM_SCREEN_ROTATE_270;
#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 

    mmi_confirm_display((WCHAR *)((UI_string_type)get_string(STR_GLOBAL_MC_REMOVED_USE_PHONE)), MMI_EVENT_QUERY, &arg);
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_check_valid_drv
* DESCRIPTION
*  check the driver is valid or not
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL mmi_vdorec_check_valid_drv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    storage = mmi_vdoply_get_storage();

    if (FS_NO_ERROR == FS_GetDevStatus(storage, FS_MOUNT_STATE_ENUM))
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
 *  mmi_vdorec_draw_panel_timer
 * DESCRIPTION
 *  draw panel timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_draw_panel_timer_ext(void *timer_ptr, U32 time, MMI_BOOL is_record_timer)
{
	S32 hour;
    S32 hour_remain;
    S32 min;
    S32 sec;
	S32 layer_offset_x;
    S32 layer_offset_y;
	S32 width,height;
	U16 image_id, col_image_id;
	U16 image_id2 = 0;
	U16 i;
	S32 offset_x, offset_y;
	S32 *hr_0_offset_x_ptr;
	vdorec_timer_struct *timer = (vdorec_timer_struct*)timer_ptr;

	hour = time / 3600;
    hour_remain = time % 3600;
    min = hour_remain / 60;
    sec = hour_remain % 60;

    if (hour > 99)
    {
        hour = 99;
    }

	#ifdef __MMI_MEDIA_PLAYER__
		image_id = IMG_ID_VDOREC_TIME_NUMBER_0;
		col_image_id = IMG_ID_VDOREC_TIME_COL;
	#else
		#ifndef __MMI_VIDEO_RECORDER_SLIM__
		image_id = is_record_timer ? IMG_ID_VDOREC_TIME_NUMBER_0 : IMG_ID_VDOPLY_OSD_TIMER_0;
		col_image_id = is_record_timer ? IMG_ID_VDOREC_TIME_COL : IMG_ID_VDOPLY_OSD_TIMER_COL;
		#else
		image_id = IMG_ID_VDOPLY_OSD_TIMER_0;
		col_image_id = IMG_ID_VDOPLY_OSD_TIMER_COL;
		#endif
	#endif

	gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
	gdi_image_get_dimension_id(image_id, &width, &height);

    /* bg */
    gdi_draw_solid_rect(
        timer->hr_0_offset_x - layer_offset_x,
        timer->offset_y - layer_offset_y,
        timer->sec_1_offset_x - layer_offset_x + width,
        timer->offset_y - layer_offset_y + height,
				#ifdef __MMI_MEDIA_PLAYER__
				(GDI_COLOR_TRANSPARENT)
				#else		
				(is_record_timer ? GDI_COLOR_TRANSPARENT : MMI_VDOPLY_BG_COLOR)
				#endif
        );

	hr_0_offset_x_ptr = &timer->hr_0_offset_x;
	offset_y = timer->offset_y - layer_offset_y;
	for(i=0; i<8; i++)
	{
		offset_x = *(hr_0_offset_x_ptr + i) - layer_offset_x;
		switch(i)
		{
			case 0:
				image_id2 = image_id + (U16) hour / 10;
				break;
			case 1:
				image_id2 = image_id + (U16) hour % 10;
				break;
			case 2:
			case 5:
				image_id2 = col_image_id;
				break;
			case 3:
				image_id2 = image_id + (U16) min / 10;
				break;
			case 4:
				image_id2 = image_id + (U16) min % 10;
				break;
			case 6:
				image_id2 = image_id + (U16) sec / 10;
				break;
			case 7:
				image_id2 = image_id + (U16) sec % 10;
				break;
		}

		gdi_image_draw_id(offset_x, offset_y, (U16) image_id2);
	}

	#ifdef __VDOREC_USING_BLT_REGION__
	if(is_record_timer && g_vdorec_cntx.is_use_blt_region)
	{
        mmi_vdorec_merge_blt_rgn(
            timer->hr_0_offset_x,
            timer->offset_y,
            timer->sec_1_offset_x + width - timer->hr_0_offset_x,
            height);
	}
	#endif
}




/*****************************************************************************
*
*	Following area is DCM region which for compressing rodata and code
*	As pragma will link APIs that not be called, we place APIs which you want to compress together.
*	if you want to add another APIs, place those here too.
*	
*****************************************************************************/
#ifdef __MMI_AP_DCM_VDOREC__
#pragma arm section rodata = "DYNAMIC_CODE_VDOREC_RODATA", code = "DYNAMIC_CODE_VDOREC_ROCODE"
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_clear_osd_layer
 * DESCRIPTION
 *  clear osd layer 
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
static void mmi_vdorec_clear_osd_layer(gdi_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gdi_layer_push_and_set_active(handle);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_blt_screen
 * DESCRIPTION
 *  blt full screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_blt_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_BLT_SCREEN);

	#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    if (g_vdorec_cntx.is_use_hw_rotate)
    {
    	#ifndef __VDOREC_FEATURE_MULTI_REGION_SUPPORT__
        if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE)
        {
			#ifdef __VDOREC_USING_BLT_REGION__        
            if (g_vdorec_cntx.is_use_blt_region)
            {
                S32 layer_width, layer_height;
                S32 x, y, w, h;
                
                gdi_layer_push_and_set_active(g_vdorec_cntx.tmp_osd_layer_region_handle[0]);
                gdi_layer_get_dimension(&layer_width, &layer_height);
                gdi_layer_pop_and_restore_active();
                
                /*the blt region is rotated, so we mush rotated the bacy*/
                x = g_vdorec_cntx.blt_area_y;
                y = g_vdorec_cntx.lcd_width - g_vdorec_cntx.blt_area_x - g_vdorec_cntx.blt_area_w;
                w = g_vdorec_cntx.blt_area_h;
                h = g_vdorec_cntx.blt_area_w;
                
                mdi_util_rotate_osd_partial_region_for_hw_rotator(
                    g_vdorec_cntx.tmp_osd_layer_region_handle[0], 
                    x, 
                    y, 
                    w, 
                    h, 
                    g_vdorec_cntx.osd_layer_handle);
            }
            else
			#endif				
            {
                mdi_util_rotate_osd_for_hw_rotator(g_vdorec_cntx.tmp_osd_layer_region_handle[0], g_vdorec_cntx.osd_layer_handle);
            }
        }
        #else
        {
			U32 i;
		
            for (i = 0 ; i < g_vdorec_cntx.osd_layer_region_count; i++)
            {
                if (g_vdorec_cntx.is_osd_layer_updated[i] 
					&& (g_vdorec_cntx.osd_layer_region_handle[i] != GDI_LAYER_EMPTY_HANDLE))
                {
                    mdi_util_rotate_osd_for_hw_rotator(g_vdorec_cntx.tmp_osd_layer_region_handle[i], g_vdorec_cntx.osd_layer_region_handle[i]);
                }
            }
        }
		#endif
    }
	#endif

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        gdi_layer_blt_previous(
            g_vdorec_cntx.blt_area_x, 
            g_vdorec_cntx.blt_area_y, 
            g_vdorec_cntx.blt_area_x + g_vdorec_cntx.blt_area_w - 1,
            g_vdorec_cntx.blt_area_y + g_vdorec_cntx.blt_area_h - 1);
    }
    else
	#endif
    {
        {
        	#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
            if (g_vdorec_cntx.is_use_hw_rotate)
            {
                gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            }
            #else
            {
            #if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)
                gdi_layer_blt_previous(0, 0, UI_device_height - 1, UI_device_width - 1);
            #else 
                gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            #endif
            }
			#endif
        }
    }

	#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    /* if use dirty region, will make the two buffer the same, it is for next drawing. */
    if (g_vdorec_cntx.is_use_hw_rotate)
    {
    	#ifndef __VDOREC_FEATURE_MULTI_REGION_SUPPORT__
        if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE)
        {
        	#ifdef __VDOREC_USING_BLT_REGION__
            if (g_vdorec_cntx.is_use_blt_region)
            {
                S32 layer_width, layer_height;
                S32 x, y, w, h;
                
                gdi_layer_push_and_set_active(g_vdorec_cntx.tmp_osd_layer_region_handle[0]);
                gdi_layer_get_dimension(&layer_width, &layer_height);
                gdi_layer_toggle_double();
                gdi_layer_pop_and_restore_active();
                
                /*the blt region is rotated, so we mush rotated the bacy*/
                x = g_vdorec_cntx.blt_area_y;
                y = g_vdorec_cntx.lcd_width - g_vdorec_cntx.blt_area_x - g_vdorec_cntx.blt_area_w;
                w = g_vdorec_cntx.blt_area_h;
                h = g_vdorec_cntx.blt_area_w;
                
                gdi_layer_push_and_set_active(g_vdorec_cntx.osd_layer_handle);
                gdi_layer_toggle_double();
                
                mdi_util_rotate_osd_partial_region_for_hw_rotator(
                    g_vdorec_cntx.tmp_osd_layer_region_handle[0], 
                    x, 
                    y, 
                    w, 
                    h, 
                    g_vdorec_cntx.osd_layer_handle);
                
                gdi_layer_toggle_double();
                gdi_layer_pop_and_restore_active();
                mmi_vdorec_set_merge_region(0, 0, 0, 0);
            }
            else
			#endif	
            {
                /* nothing needed*/
            }
        }
		#endif
    }
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_load_setting
 * DESCRIPTION
 *  load setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_load_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_LOAD_SETTING);

    /* read storage setting from video player */
    mmi_vdoply_load_setting();

    /* if already loaded into memory, do not need load again */
    if (!g_vdorec_cntx.is_setting_loaded)
    {
        ReadRecordSlim(NVRAM_EF_VIDEO_SETTING_LID, 1, (void*)&g_vdorec_cntx.setting, NVRAM_EF_VIDEO_SETTING_SIZE);

        /* first time init */
        if (g_vdorec_cntx.setting.wb == 0xffff)
        {
            mmi_vdorec_restore_setting();
        }

        g_vdorec_cntx.setting.led_value = VDOREC_DEFAULT_PREVIEW_LED_VALUE;
   
        g_vdorec_cntx.is_setting_loaded = TRUE;
    }

	mmi_vdorec_auto_adjust_size_and_format();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_store_setting
 * DESCRIPTION
 *  store setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_store_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_STORE_SETTING);

    WriteRecordSlim(NVRAM_EF_VIDEO_SETTING_LID, 1, (void*)&g_vdorec_cntx.setting, NVRAM_EF_VIDEO_SETTING_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_restore_setting
 * DESCRIPTION
 *  restore setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_restore_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_RESTORE_SETTING);
    
    g_vdorec_cntx.setting.wb = VDOREC_DEFAULT_SETTING_WB;
    g_vdorec_cntx.setting.ev = VDOREC_DEFAULT_SETTING_EV;
    g_vdorec_cntx.setting.led_highlight = VDOREC_DEFAULT_SETTING_LED_HIGHLIGHT;
    g_vdorec_cntx.setting.night = VDOREC_DEFAULT_SETTING_NIGHT;
    g_vdorec_cntx.setting.banding = VDOREC_DEFAULT_SETTING_BANDING;

    g_vdorec_cntx.setting.effect = VDOREC_DEFAULT_SETTING_EFFECT;

    g_vdorec_cntx.setting.video_size = VDOREC_DEFAULT_SETTING_VIDEO_SIZE;
    g_vdorec_cntx.setting.video_qty = VDOREC_DEFAULT_SETTING_VIDEO_QTY;
    g_vdorec_cntx.setting.size_limit = VDOREC_DEFAULT_SETTING_SIZE_LIMIT;
    g_vdorec_cntx.setting.time_limit = VDOREC_DEFAULT_SETTING_TIME_LIMIT;
    g_vdorec_cntx.setting.record_aud = VDOREC_DEFAULT_SETTING_RECORD_AUD;
    g_vdorec_cntx.setting.video_format = VDOREC_DEFAULT_SETTING_VIDEO_FORMAT;

    g_vdorec_cntx.setting.brightness = 128;
    g_vdorec_cntx.setting.contrast = 128;
    g_vdorec_cntx.setting.zoom = VDOREC_DEFAULT_SETTING_ZOOM;

    #ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__
    g_vdorec_cntx.setting.accept_call = VDOREC_DEFAULT_ACCEPT_CALL;
    #endif

    mmi_vdorec_auto_adjust_size_and_format();

    mmi_vdorec_store_setting();

}



/*****************************************************************************
* FUNCTION
*  mmi_vdorec_auto_adjust_size_and_format
* DESCRIPTION
*  get video resolution and codec
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static BOOL mmi_vdorec_map_search(U16 idx,U32*val,VdoRecGenMapStruct* pTable,S32 count)
{
	S32 i;

	for(i=0;i<count;i++)
	{
		if(pTable[i].Idx == idx)
		{
			*val = pTable[i].Val;
			return FALSE;
		}
	}

	return TRUE;
}
static void mmi_vdorec_auto_adjust_size_and_format(void)
{
#ifdef __VDOREC_FEATURE_QTY_TABLE_ENABLE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_rec_spec_struct video_rec_table;    
    U32 i;
    U16 count;
    U32 p = 0, q = 0, r = 0;
    MMI_BOOL is_real_item = MMI_TRUE;
	U32 temp_p = 0, temp_q = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(mmi_vdorec_qty_codec_size, 0, sizeof(MMI_BOOL)*VDOREC_SETTING_VIDEO_QTY_COUNT*VDOREC_SETTING_VIDEO_FORMAT_COUNT*VDOREC_SETTING_VIDEO_SIZE_COUNT);
    
    /* get capability */
    count = mdi_video_rec_query_entry_num_of_video_spec_table();
    for(i=0; i < count; i++)
    {
        mdi_video_rec_get_video_spec_by_index(i, &video_rec_table, sizeof(video_rec_table));

		if(mmi_vdorec_map_search(video_rec_table.quality,&r,vdorec_qty_mdi2mmi_map,4))
		{
			r = VDOREC_SETTING_VIDEO_QTY_FINE;
			is_real_item = MMI_FALSE;
		}

		if(mmi_vdorec_map_search(video_rec_table.video_size,&p,vdorec_size_mdi2mmi_map,VDORECSIZEMAPTALBECOUNT))
		{
			p = VDOREC_SETTING_VIDEO_SIZE_QCIF;
			is_real_item = MMI_FALSE;
		}

		if(mmi_vdorec_map_search(video_rec_table.video_format,&q,vdorec_format_mdi2mmi_map,4))
		{
			q = VDOREC_SETTING_VIDEO_FORMAT_MP4;
			is_real_item = MMI_FALSE;
		}

        if(is_real_item)
        {
            mmi_vdorec_qty_codec_size[r][q][p] = MMI_TRUE;
            if(r == g_vdorec_cntx.setting.video_qty )
            {
            	if(p >= temp_p)
            	{
                	temp_q = q;
                	temp_p = p;
            	}
            }

        }
        else
        {
            is_real_item = MMI_TRUE;
            mmi_vdorec_qty_codec_size[r][q][p] = MMI_FALSE;
        }
    }
	g_vdorec_cntx.setting.video_size = temp_p;
	g_vdorec_cntx.setting.video_format = temp_q;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_get_save_filename
 * DESCRIPTION
 *  get next file name to be recorded
 * PARAMETERS
 *  file_buf_p      [?]     
 *  a  UUT      filename buffer ptr(?)
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_get_save_filename(CHAR *file_buf_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S8 buffer[25];
    //S8 UCS2_buffer[25];
    //S8 UCS2_testname[50];
    //S8 UCS2_alpha[10];
    S16 error = 0;
    U16 filename_seq_no;
    U16 alpha_count;
    U16 alpha_index;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_GET_SAVE_FILE_NAME);
    /* get/store sequentail number */
    ReadValueSlim(NVRAM_VDOREC_FILENAME_SEQ_NO, &filename_seq_no, DS_SHORT);

    if (filename_seq_no == 0xffff)
    {
        filename_seq_no = 1;    /* init value */
    }

    g_vdorec_cntx.filename_seq_no = filename_seq_no;
    alpha_count = 'Z' - 'A' + 1;

    while(1)
    {
        alpha_index = 0;

        //sprintf((PS8)buffer, "MOV%04d", g_vdorec_cntx.filename_seq_no);
        //mmi_asc_to_ucs2((PS8)UCS2_buffer, (PS8)buffer);

        while (1)
        {
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #if defined(MP4_ENCODE)
/* under construction !*/
        #elif defined(MJPG_ENCODE)
/* under construction !*/
        #else
/* under construction !*/
        #endif /* chip version */
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
		if(g_vdorec_cntx.setting.video_format  == VDOREC_SETTING_VIDEO_FORMAT_MJPEG)
    {
    	 kal_wsprintf((WCHAR*)file_buf_p, "%wMOV%04d%c.avi", 
                (WCHAR*)g_vdorec_cntx.storage_filepath,
                g_vdorec_cntx.filename_seq_no, 
                'A' + alpha_index);
    }
    else
    {
    	kal_wsprintf((WCHAR*)file_buf_p, "%wMOV%04d%c.3gp", 
                (WCHAR*)g_vdorec_cntx.storage_filepath,
                g_vdorec_cntx.filename_seq_no, 
                'A' + alpha_index);
    }
    #endif
        
            file_handle = FS_Open((WCHAR*) file_buf_p, FS_READ_ONLY);

            if (file_handle >= 0)
            {
                /* file exist */
                FS_Close(file_handle);
                alpha_index++;
            }
            else
            {
                /* file not exit. return */
                WriteValueSlim(NVRAM_VDOREC_FILENAME_SEQ_NO, &g_vdorec_cntx.filename_seq_no, DS_SHORT);
                mmi_ucs2ncpy(g_vdorec_cntx.setting.save_name, (CHAR *)srv_fmgr_path_get_filename_ptr((WCHAR*)(file_buf_p)), SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
                mmi_vdorec_store_setting();
                return;
            }

            if (alpha_index >= alpha_count - 1)
            {
                g_vdorec_cntx.filename_seq_no++;
                /* leave internal while */
                break;
            }
        }
    }
//#endif /* __MMI_CAMERA_RECORDER_ONE_KEY_TOGGLE__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_disply_popup
 * DESCRIPTION
 *  display popup. will roate if is horizontal screen
 * PARAMETERS
 *  str_ptr             [IN]        String pointer
 *  img_id              [IN]        Image id
 *  image_on_bottom     [IN]        Is image on bottom
 *  tone_duration       [IN]        Tone duration
 *  tone_id             [IN]        Tine id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_disply_popup(MMI_STR_ID str_id, mmi_event_notify_enum eventy_type, S32 popup_result_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DISPLAY_POPUP, eventy_type);
    mmi_popup_property_init(&arg);
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__)

    if (GRP_ID_INVALID != g_vdorec_cntx.cur_gid)
    {
        arg.parent_id = g_vdorec_cntx.cur_gid;
        arg.user_tag = (void *)((void*)popup_result_type);
    }
    arg.rotation = (g_vdorec_cntx.is_giveup_popup_rotate) ? MMI_FRM_SCREEN_ROTATE_0 : MMI_FRM_SCREEN_ROTATE_270;
    mmi_popup_display_ext(str_id, eventy_type, &arg);
        
#elif defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    if (mmi_frm_get_screen_rotate() == MMI_FRM_SCREEN_ROTATE_270 ||
        gdi_lcd_get_rotate() == GDI_LAYER_ROTATE_270)
    {
        /* rotate the popup only if the screen is being rotated */
        if (GRP_ID_INVALID != g_vdorec_cntx.cur_gid)
        {
            arg.parent_id = g_vdorec_cntx.cur_gid;
            arg.user_tag = (void *)((void*)popup_result_type);            
        }
        arg.rotation = (g_vdorec_cntx.is_giveup_popup_rotate) ? MMI_FRM_SCREEN_ROTATE_0 : MMI_FRM_SCREEN_ROTATE_270;
        mmi_popup_display_ext(str_id, eventy_type, &arg);
    }
    else
    {
        if (GRP_ID_INVALID == g_vdorec_cntx.cur_gid)
        {
            mmi_popup_display_ext(str_id, eventy_type, NULL);
        }
        else
        {
            mmi_popup_display_simple_ext(str_id, eventy_type, g_vdorec_cntx.cur_gid, (void*)popup_result_type);
        }
    }
#else /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 
    if (GRP_ID_INVALID == g_vdorec_cntx.cur_gid)
    {
        mmi_popup_display_ext(str_id, (mmi_event_notify_enum)eventy_type, NULL);
    }
    else
    {
        mmi_popup_display_simple_ext(str_id, (mmi_event_notify_enum)eventy_type, g_vdorec_cntx.cur_gid, (void*)popup_result_type);
    }
#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__) */ 

    #ifdef __MMI_AP_DCM_VDOREC__
    mmi_ap_send_dcm_unload_evt(DYNAMIC_CODE_COMPRESS_VDOREC);
    #endif

}


/*****************************************************************************
*
* Preview Screen
*
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_check_and_display_error_popup
 * DESCRIPTION
 *  display error popup.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_vdorec_check_and_display_error_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = STR_GLOBAL_ERROR;
    mmi_event_notify_enum event_type = MMI_EVENT_FAILURE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_CHECK_AND_DISPLAY_POPUP, g_vdorec_cntx.last_error);

    if (g_vdorec_cntx.last_error != MDI_RES_VDOREC_SUCCEED)
    {
        /* clear record keys */
        ClearKeyHandler(VDOREC_RECORD_KEY, KEY_EVENT_UP);
		
        if (VDOREC_RECORD_EXTRA_KEY1 != -1)
        {
            ClearKeyHandler((U16)(VDOREC_RECORD_EXTRA_KEY1), KEY_EVENT_UP);
        }
		
        if (VDOREC_RECORD_EXTRA_KEY2 != -1)
        {
            ClearKeyHandler((U16)(VDOREC_RECORD_EXTRA_KEY2), KEY_EVENT_UP);
        }

        ClearInputEventHandler(MMI_DEVICE_KEY);
        str_id = mdi_util_get_mdi_error_info(g_vdorec_cntx.last_error, &event_type);
        switch (g_vdorec_cntx.last_error)
        {
                /* followings are serious error, has to exit app */
            case MDI_RES_VDOREC_ERR_HW_NOT_READY:
            case MDI_RES_VDOREC_ERR_POWER_ON_FAILED:
            case MDI_RES_VDOREC_ERR_PREVIEW_FAILED:
            case MDI_RES_VDOREC_ERR_SAVE_FILE_FAILED:
            case MDI_RES_VDOREC_ERR_MEMORY_INSUFFICIENT:
            //case MDI_RES_VDOREC_ERR_RECORD_FAILED:
                mmi_vdorec_disply_popup(
                    str_id,
                    event_type, MMI_VDOREC_POPUP_RESULT_PROCESS_DELETE_GROUP);
                break;

            case MDI_RES_VDOPLY_ERR_MEMORY_INSUFFICIENT:
                if (mmi_frm_scrn_is_present(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVED_PREVIEW, MMI_FRM_NODE_ALL_FLAG))
                {
                    mmi_vdorec_disply_popup(
                        str_id,
                        event_type, MMI_VDOREC_POPUP_RESULT_PROCESS_DELETE_SCREEN);
                }
                else
                {
                    mmi_vdorec_disply_popup(
                        str_id,
                        event_type, MMI_VDOREC_POPUP_RESULT_PROCESS_DELETE_GROUP);
                }
                break;

            /* error of open saved video file  */
            case MDI_RES_VDOPLY_ERR_FAILED:
            case MDI_RES_VDOPLY_ERR_OPEN_FILE_FAILED:
            case MDI_RES_VDOPLY_ERR_PLAY_FAILED:
            case MDI_RES_VDOPLY_ERR_SEEK_FAILED:
            case MDI_RES_VDOPLY_ERR_INVALID_RESOULTION:
            case MDI_RES_VDOPLY_ERR_UNSUPPORTED_FORMAT:
            case MDI_RES_VDOPLY_ERR_DRM_PROHIBITED:
            case MDI_RES_VDOPLY_ERR_DRM_DURATION_USED:
                mmi_vdorec_disply_popup(
                    str_id,
                    event_type, 
                    MMI_VDOREC_POPUP_RESULT_PROCESS_DELETE_SCREEN);
                break;

            default:
                mmi_vdorec_disply_popup(
                    str_id,
                    event_type,
                    MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
        }

        g_vdorec_cntx.last_error = MDI_RES_VDOREC_SUCCEED;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_resize_preview_layer
 * DESCRIPTION
 *  resize preview layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_resize_preview_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 video_width;
    S32 video_height;
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_vdorec_get_video_size(&video_width, &video_height);

    gdi_util_fit_box(
        GDI_UTIL_MODE_LONG_SIDE_FIT,
        g_vdorec_cntx.preview_wnd_width,
        g_vdorec_cntx.preview_wnd_height,
        video_width,
        video_height,
        &resized_offset_x,
        &resized_offset_y,
        &resized_width,
        &resized_height);

    gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);

    resized_width = (resized_width >> 1) << 1;
    resized_height = (resized_height >> 1) << 1;
    gdi_layer_resize(resized_width, resized_height);
    gdi_layer_set_position(
        g_vdorec_cntx.preview_wnd_offset_x + resized_offset_x,
        g_vdorec_cntx.preview_wnd_offset_y + resized_offset_y);

    gdi_layer_pop_and_restore_active();

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_RESIZE_PREVIEW_LAYER, video_width, video_height);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_get_video_size
 * DESCRIPTION
 *  get zoom factor based on feature define
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_get_video_size(S32 *video_width, S32 *video_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *video_width = 176;
    *video_height = 144;
	
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_VGA)
    {
        *video_width = 640;
        *video_height = 480;
    }
	if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_NHD)
    {
        *video_width = 640;
        *video_height = 368;
    }
	if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_HVGA)
    {
        *video_width = 480;
        *video_height = 320;
    }
	if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_CIF2)
    {
        *video_width = 432;
        *video_height = 240;
    }
	if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_WQVGA)
    {
        *video_width = 400;
        *video_height = 240;
    }
	if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_CIF)
    {
        *video_width = 352;
        *video_height = 288;
    }

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_SQCIF)
    {
        *video_width = 129;
        *video_height = 96;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__ */ 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_QQVGA)
    {
        *video_width = 160;
        *video_height = 120;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__ */ 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QCIF__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_QCIF)
    {
        *video_width = 176;
        *video_height = 144;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_QCIF__ */ 

#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QVGA__
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_QVGA)
    {
        *video_width = 320;
        *video_height = 240;
    }
#endif /* __VDOREC_FEATURE_VIDEO_SIZE_QVGA__ */ 

	
    if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_WP_WVGA)
    {
        *video_width = 480;
        *video_height = 800;
    }
	if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_WP_HVGA)
    {
        *video_width = 320;
        *video_height = 480;
    }
	if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_WP_WQVGA)
    {
        *video_width = 240;
        *video_height = 400;
    }
	if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_WP_QVGA)
    {
        *video_width = 240;
        *video_height = 320;
    }
	if (g_vdorec_cntx.setting.video_size == VDOREC_SETTING_VIDEO_SIZE_WP_QCIF1)
    {
        *video_width = 176;
        *video_height = 208;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_GET_VIDEO_SIZE, *video_width, *video_height);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_lsk_press_hdlr
 * DESCRIPTION
 *  lsk press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_lsk_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_LSK_PRESS);
		
    g_vdorec_cntx.is_lsk_pressed = TRUE;
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
    mmi_vdorec_blt_screen(); 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_lsk_release_hdlr
 * DESCRIPTION
 *  lsk release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_lsk_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_LSK_RELEASE);

    g_vdorec_cntx.is_lsk_pressed = FALSE;
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
    mmi_vdorec_blt_screen();
    
#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
    switch(g_vdorec_cntx.state)
    {
        case VDOREC_STATE_VIDEO_PREVIEW_PLAY:
        case VDOREC_STATE_VIDEO_PREVIEW_STOP:
        case VDOREC_STATE_VIDEO_PREVIEW_BGCALL:
            mmi_vdorec_entry_preview_option_screen();
            break;
            
        default:
            mmi_vdorec_entry_option_screen();
            break;
    }
#else /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__*/
    mmi_vdorec_entry_option_screen();
#endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_rsk_press_hdlr
 * DESCRIPTION
 *  rsk press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_rsk_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_RSK_PRESS);
    
    {
        g_vdorec_cntx.is_rsk_pressed = TRUE;
        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
        mmi_vdorec_blt_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_rsk_release_hdlr
 * DESCRIPTION
 *  rsk release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_rsk_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_RSK_RELEASE);
    
    g_vdorec_cntx.is_rsk_pressed = FALSE;
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
    mmi_vdorec_blt_screen();

    switch (g_vdorec_cntx.state)
    {
        case VDOREC_STATE_PREVIEW:
        case VDOREC_STATE_BG_CALL:

			#ifndef __VDOREC_FEATURE_EXT_REQ_DISABLE__
            if (g_vdorec_cntx.is_ext_req)
            {   
                mmi_vdorec_post_to_parent(CUI_VDOREC_RECORD_EVENT_RESULT_FAILED, NULL);
                return;
            }
            else
			#endif	
            {
                mmi_frm_scrn_close_active_id();
            }
            break;

        case VDOREC_STATE_RECORD:
        case VDOREC_STATE_PAUSE:
            mdi_video_rec_record_stop();
            gui_cancel_timer(mmi_vdorec_record_timer_cyclic);
            
            #if defined(__VDOREC_FEATURE_DIRECT_SAVE__) || defined(__VDOREC_FEATURE_SLIM_UE__)
                g_vdorec_cntx.is_saving = TRUE;
				g_vdorec_cntx.is_show_saving = MMI_TRUE;
                mmi_vdorec_entry_saving_screen();
            #else
                mmi_vdorec_entry_save_confirm_screen();
            #endif /* __VDOREC_FEATURE_DIRECT_SAVE__ */
            break;
            
        case VDOREC_STATE_VIDEO_PREVIEW_PLAY:
        case VDOREC_STATE_VIDEO_PREVIEW_STOP:
        case VDOREC_STATE_VIDEO_PREVIEW_BGCALL:
            #ifdef __VDOREC_FEATURE_RSK_DELETE__
                mmi_vdorec_delete_saved_vdo_confirm();
            #else
                mmi_frm_scrn_close_active_id();
            #endif
                break;
        
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_null_key_event
 * DESCRIPTION
 *  ck press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_null_key_event(void)
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
 *  mmi_vdorec_ck_press_hdlr
 * DESCRIPTION
 *  ck press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_ck_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_CK_PRESS);

    {
        g_vdorec_cntx.is_ck_pressed = TRUE;

        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
        mmi_vdorec_blt_screen();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_ck_release_hdlr
 * DESCRIPTION
 *  ck release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_ck_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_CK_RELEASE);
    
    g_vdorec_cntx.is_ck_pressed = FALSE;

    if (mmi_vdorec_is_in_bgcall())
    {
        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
        mmi_vdorec_blt_screen();
        /* do not change state */
        mmi_vdorec_disply_popup(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL,
            MMI_EVENT_FAILURE,
            MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
        return;
    }

    switch (g_vdorec_cntx.state)
    {
        case VDOREC_STATE_PREVIEW:

			#ifndef __VDOREC_HIDE_HINT__
            /*if in preview screen you press record key, will clear hint*/
            mmi_vdorec_set_hint(NULL, NULL, 0);
            /*if hint has drawed, should cancel hind hint timer*/
            gui_cancel_timer(mmi_vdorec_hide_hint);
			#endif

            mmi_vdorec_draw_osd(
                VDOREC_OSD_COMPONENT_CLEAR_STATUS | 
                VDOREC_OSD_COMPONENT_SOFTKEY |
                VDOREC_OSD_COMPONENT_HINT
				);
            mmi_vdorec_blt_screen();
            mmi_vdorec_enter_state(VDOREC_STATE_RECORD);
            break;

        case VDOREC_STATE_PAUSE:
            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
            mmi_vdorec_blt_screen();
            mmi_vdorec_enter_state(VDOREC_STATE_RECORD);
            break;

        case VDOREC_STATE_RECORD:
            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
            mmi_vdorec_blt_screen();
            mmi_vdorec_enter_state(VDOREC_STATE_PAUSE);        
            break;

#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
        case VDOREC_STATE_VIDEO_PREVIEW_PLAY:
            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
            mmi_vdorec_blt_screen();
            mdi_video_ply_get_cur_play_time(&g_vdorec_cntx.record_time);
            mmi_vdorec_enter_state(VDOREC_STATE_VIDEO_PREVIEW_STOP);


            break;
        case VDOREC_STATE_VIDEO_PREVIEW_STOP:
            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
            mmi_vdorec_blt_screen();
            mmi_vdorec_enter_state(VDOREC_STATE_VIDEO_PREVIEW_PLAY);
            break;
#endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

    }

}

#ifdef __VDOREC_FEATURE_ZOOM__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_start_zoom
 * DESCRIPTION
 *  zoom in
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_start_zoom(void *is_zoom_in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __VDOREC_FEATURE_RECORDING_ZOOM__
        if ((g_vdorec_cntx.state != VDOREC_STATE_PREVIEW) &&
            (g_vdorec_cntx.state != VDOREC_STATE_RECORD) && (g_vdorec_cntx.state != VDOREC_STATE_PAUSE))
        {
            return;
        }
    #else /* __VDOREC_FEATURE_RECORDING_ZOOM__ */ 
        if (g_vdorec_cntx.state != VDOREC_STATE_PREVIEW)
        {
            return;
        }
    #endif /* __VDOREC_FEATURE_RECORDING_ZOOM__ */

    if (is_zoom_in)
    {
        if (g_vdorec_cntx.setting.zoom < g_vdorec_cntx.max_zoom_steps)
            g_vdorec_cntx.setting.zoom += 1;
    }
    else
    {
        if (g_vdorec_cntx.setting.zoom > 0)
            g_vdorec_cntx.setting.zoom -= 1;
    }

    mdi_video_rec_update_para_zoom(g_vdorec_cntx.setting.zoom);
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM);
    mmi_vdorec_blt_screen();

    if (g_vdorec_cntx.is_fast_zoom_support){
        gui_start_timer_ex(VDOREC_INC_INTERVAL_FIRST, mmi_vdorec_start_fast_zoom, is_zoom_in);
		//gui_start_timer(VDOREC_INC_INTERVAL_FIRST, mmi_vdorec_start_fast_zoom_out);
		g_vdorec_cntx.is_first_time_zoom = FALSE;            
	}
	else{
		if (g_vdorec_cntx.is_first_time_zoom){
		    gui_start_timer_ex(VDOREC_INC_INTERVAL_FIRST, mmi_vdorec_start_zoom, is_zoom_in);
			//gui_start_timer(VDOREC_INC_INTERVAL_FIRST, mmi_vdorec_zoom_out);
			g_vdorec_cntx.is_first_time_zoom = FALSE;            
		}
		else{
			gui_start_timer_ex(VDOREC_INC_INTERVAL, mmi_vdorec_start_zoom, is_zoom_in);
		}
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_zoom_in_key_press_hdlr
 * DESCRIPTION
 *  up arrow press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_zoom_in_key_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ZOOM_IN_KEY_PRESS);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
    }

#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
    if (g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_PLAY ||
        g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_STOP ||
        g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_BGCALL)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

    if (!g_vdorec_cntx.is_zoom_in_key_pressed)
    {
        g_vdorec_cntx.is_zoom_in_key_pressed = TRUE;
        g_vdorec_cntx.is_first_time_zoom = TRUE;
		mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM);
    	mmi_vdorec_blt_screen();
        mmi_vdorec_start_zoom((void*)TRUE);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_zoom_in_key_release_hdlr
 * DESCRIPTION
 *  up arrow release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_zoom_in_key_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ZOOM_IN_KEY_RELEASE);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
        mmi_vdorec_watchdog_time_out_handler();
    }

#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
    if (g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_PLAY ||
        g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_STOP ||
        g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_BGCALL)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

    g_vdorec_cntx.is_zoom_in_key_pressed = FALSE;
    
    if (g_vdorec_cntx.is_fast_zoom_support)
    {
        mmi_vdorec_stop_fast_zoom();
        gui_cancel_timer(mmi_vdorec_draw_zoom_osd);
        gui_cancel_timer((FuncPtr)mmi_vdorec_start_fast_zoom);
    }
    else
    {
        gui_cancel_timer((FuncPtr)mmi_vdorec_start_zoom);
    }

    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM);
    mmi_vdorec_blt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_zoom_out_key_press_hdlr
 * DESCRIPTION
 *  down arrow press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_zoom_out_key_press_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ZOOM_OUT_KEY_PRESS);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
        mmi_vdorec_watchdog_time_out_handler();
    }

#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
    if (g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_PLAY ||
        g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_STOP ||
        g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_BGCALL)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */
    
    if (!g_vdorec_cntx.is_zoom_out_key_pressed)
    {
        g_vdorec_cntx.is_zoom_out_key_pressed = TRUE;
        g_vdorec_cntx.is_first_time_zoom = TRUE;
		mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM);
    	mmi_vdorec_blt_screen();

        mmi_vdorec_start_zoom((void*)FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_zoom_out_key_release_hdlr
 * DESCRIPTION
 *  up arrow release hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_zoom_out_key_release_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ZOOM_OUT_KEY_RELEASE);

#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
    if (g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_PLAY ||
        g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_STOP ||
        g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_BGCALL)
    {
        return;
    }
#endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

    
    g_vdorec_cntx.is_zoom_out_key_pressed = FALSE;

    if (g_vdorec_cntx.is_fast_zoom_support)
    {
        mmi_vdorec_stop_fast_zoom();
        gui_cancel_timer(mmi_vdorec_draw_zoom_osd);
        gui_cancel_timer((FuncPtr)mmi_vdorec_start_fast_zoom);
    }
    else
    {
        gui_cancel_timer((FuncPtr)mmi_vdorec_start_zoom);
    }

    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM);
    mmi_vdorec_blt_screen();
}
#endif /* __VDOREC_FEATURE_ZOOM__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_record_result_hdlr_callback
 * DESCRIPTION
 *  record result callback hdlr
 * PARAMETERS
 *  result      [IN]        
 *  a(?)        [IN]        Current state
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_record_result_hdlr_callback(MDI_RESULT result, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_RECORD_RESULT_HDLR_CALLBACK, result);

    if (!mmi_vdorec_check_valid_drv())
    {
        mmi_vdorec_disply_popup(
            srv_fmgr_fs_error_get_string(FS_DRIVE_NOT_FOUND),
            MMI_EVENT_FAILURE,
            MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
        return;
    }

    MMI_ASSERT((g_vdorec_cntx.state == VDOREC_STATE_RECORD) || (g_vdorec_cntx.state == VDOREC_STATE_PAUSE));

    gui_cancel_timer(mmi_vdorec_record_timer_cyclic);
#ifdef __VDOREC_FEATURE_EV__    
    gui_cancel_timer(mmi_vdorec_dec_ev);
    gui_cancel_timer(mmi_vdorec_inc_ev);
#endif /* __VDOREC_FEATURE_EV__ */

#ifdef __VDOREC_FEATURE_ZOOM__
    gui_cancel_timer((FuncPtr)mmi_vdorec_start_zoom);
    //gui_cancel_timer(mmi_vdorec_start_zoom);
#endif /* __VDOREC_FEATURE_ZOOM__ */ 

	#ifndef __VDOREC_FEATURE_EXT_REQ_DISABLE__
    if (g_vdorec_cntx.is_ext_req)
    {
        if (result == MDI_RES_VDOREC_DISK_FULL)
        {
            mmi_vdorec_disply_popup(
                FMGR_FS_DISK_FULL_TEXT,
                MMI_EVENT_FAILURE,
                MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
            return;
        }
        else if (result == MDI_RES_VDOREC_REACH_SIZE_LIMIT)
        {
            mmi_vdorec_disply_popup(
                STR_ID_VDOREC_SIZE_LIMIT,
                MMI_EVENT_FAILURE,
                MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
            return;
        }
        else if (result == MDI_RES_VDOREC_REACH_TIME_LIMIT)
        {
            mmi_vdorec_disply_popup(
                STR_ID_VDOREC_TIME_LIMIT,
                MMI_EVENT_FAILURE,
                MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
            return;
        }
        else if (result == MDI_RES_VDOREC_ERR_FAILED)
        {
            if (mmi_frm_group_is_present(g_vdorec_cntx.cur_gid))
            {
                mmi_vdorec_disply_popup(
                    STR_ID_VDOREC_NOTIFY_ERROR,
                    MMI_EVENT_FAILURE,
                    MMI_VDOREC_POPUP_RESULT_PROCESS_DELETE_GROUP);
                return;
            }
        }
        else if (result == MDI_RES_VDOREC_ERR_STORAGE_TOO_SLOW)
        {
            if (mmi_frm_group_is_present(g_vdorec_cntx.cur_gid))
            {
                mmi_vdorec_disply_popup(
                    STR_ID_VDOREC_NOTIFY_STORAGE_TOO_SLOW,
                    MMI_EVENT_FAILURE,
                    MMI_VDOREC_POPUP_RESULT_PROCESS_DELETE_GROUP);
                return;
            }
        }        
        else
        {
            /* unhandle return */
            MMI_ASSERT(0);
        }

        mmi_vdorec_post_to_parent(CUI_VDOREC_RECORD_EVENT_RESULT_FAILED, NULL);
        return;
    }
    else
	#endif	
    {
        if (result == MDI_RES_VDOREC_DISK_FULL)
        {
            mmi_vdorec_disply_popup(
                FMGR_FS_DISK_FULL_TEXT,
                MMI_EVENT_FAILURE,
                MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
            return;
        }
        else if (result == MDI_RES_VDOREC_REACH_SIZE_LIMIT)
        {
            mmi_vdorec_disply_popup(
                STR_ID_VDOREC_SIZE_LIMIT,
                MMI_EVENT_INFO,
                MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
            return;
        }
        else if (result == MDI_RES_VDOREC_REACH_TIME_LIMIT)
        {
            mmi_vdorec_disply_popup(
                STR_ID_VDOREC_TIME_LIMIT,
                MMI_EVENT_FAILURE,
                MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
            return;
        }
        else if (result == MDI_RES_VDOREC_ERR_FAILED)
        {
            mmi_vdorec_disply_popup(
                STR_ID_VDOREC_NOTIFY_ERROR,
                MMI_EVENT_FAILURE,
                MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
            return;
        }
        else if (result == MDI_RES_VDOREC_ERR_STORAGE_TOO_SLOW)
        {
            mmi_vdorec_disply_popup(
                STR_ID_VDOREC_NOTIFY_STORAGE_TOO_SLOW,
                MMI_EVENT_FAILURE,
                MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
            return;
        }               
        else
        {
            /* unhandle return */
            MMI_ASSERT(0);
        }

    }

#if 0
    #if defined(__VDOREC_FEATURE_DIRECT_SAVE__) || defined(__VDOREC_FEATURE_SLIM_UE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
    #endif /* __VDOREC_FEATURE_DIRECT_SAVE__ */
#endif	
}

#ifdef __VDOREC_FEATURE_SLIM_UE__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_init_setting
 * DESCRIPTION
 *  init setting when first entry app
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_init_slim_setting(void)
{
    /* when entry new app on slim, only use old video qty, others will use default */
    g_vdorec_cntx.setting.wb          = VDOREC_DEFAULT_SETTING_WB;
    g_vdorec_cntx.setting.ev          = VDOREC_DEFAULT_SETTING_EV;
    g_vdorec_cntx.setting.night       = VDOREC_DEFAULT_SETTING_NIGHT;
    g_vdorec_cntx.setting.banding     = VDOREC_DEFAULT_SETTING_BANDING;
    g_vdorec_cntx.setting.effect      = VDOREC_DEFAULT_SETTING_EFFECT;
    g_vdorec_cntx.setting.size_limit  = VDOREC_DEFAULT_SETTING_SIZE_LIMIT;
    g_vdorec_cntx.setting.time_limit  = VDOREC_DEFAULT_SETTING_TIME_LIMIT;
    g_vdorec_cntx.setting.record_aud  = VDOREC_DEFAULT_SETTING_RECORD_AUD;
    #ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__
    g_vdorec_cntx.setting.accept_call = VDOREC_DEFAULT_ACCEPT_CALL;
    #endif        
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_start_preview
 * DESCRIPTION
 *  Start preview
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_start_preview(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_video_setting_struct video_preview_data;
    U32 blt_layer_flag = 0;
    U32 preview_layer_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_START_PREVIEW);

    memset(&video_preview_data, 0, sizeof(video_preview_data));

    video_preview_data.wb = vdorec_wb_command_map[support_wb_item[g_vdorec_cntx.setting.wb]];
    video_preview_data.ev = vdorec_ev_command_map[g_vdorec_cntx.setting.ev];
    video_preview_data.banding = vdorec_banding_command_map[g_vdorec_cntx.setting.banding];
    video_preview_data.effect = vdorec_effect_command_map[support_effect_item[g_vdorec_cntx.setting.effect]];
    video_preview_data.zoom = g_vdorec_cntx.setting.zoom;
    video_preview_data.brightness = 128;
    video_preview_data.contrast = 128;
    video_preview_data.saturation = 128;
    //video_preview_data.hue = 0;
    video_preview_data.preview_rotate = VDOREC_MAINLCD_ROTATE;
    #ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    video_preview_data.lcm_rotate = MDI_VIDEO_LCD_ROTATE_270;
    #else 
    video_preview_data.lcm_rotate = MDI_VIDEO_LCD_ROTATE_0;
    #endif
    video_preview_data.night = g_vdorec_cntx.setting.night;
    video_preview_data.video_qty = vdorec_video_qty_command_map[g_vdorec_cntx.setting.video_qty];
	mmi_vdorec_auto_adjust_size_and_format();
    #ifdef __DIRECT_SENSOR_SUPPORT__
    /* MT6223 do not have resizer, the record size should be the same as preview size */
    video_preview_data.video_size = MDI_VIDEO_VIDEO_SIZE_USER_DEFINE;
    video_preview_data.user_def_width = g_vdorec_cntx.preview_wnd_width;
    video_preview_data.user_def_height = g_vdorec_cntx.preview_wnd_height;
    #else /* __DIRECT_SENSOR_SUPPORT__ */
    video_preview_data.video_size = vdorec_video_size_command_map[g_vdorec_cntx.setting.video_size];
    //video_preview_data.user_def_width = 0;
    //video_preview_data.user_def_height = 0;
    #endif /* __DIRECT_SENSOR_SUPPORT__ */
    
    video_preview_data.video_format = vdorec_video_format_command_map[g_vdorec_cntx.setting.video_format];
    
    #ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    switch (g_vdorec_cntx.setting.size_limit)
    {

        case VDOREC_SETTING_SIZE_LIMIT_1:
            video_preview_data.size_limit = VDOREC_FEATURE_SIZE_LIMIT_1;
            break;

        case VDOREC_SETTING_SIZE_LIMIT_2:
            video_preview_data.size_limit = VDOREC_FEATURE_SIZE_LIMIT_2;
            break;

        case VDOREC_SETTING_SIZE_LIMIT_3:
            video_preview_data.size_limit = VDOREC_FEATURE_SIZE_LIMIT_3;
            break;

        default:
            video_preview_data.size_limit = 0;
            break;
    }
    #else /* __VDOREC_FEATURE_SIZE_LIMIT__ */ 
    /* no size limit */
    //video_preview_data.size_limit = 0;
    #endif /* __VDOREC_FEATURE_SIZE_LIMIT__ */ 
    #ifdef __VDOREC_FEATURE_TIME_LIMIT__
    switch (g_vdorec_cntx.setting.time_limit)
    {
        case VDOREC_SETTING_TIME_LIMIT_1:
            video_preview_data.time_limit = VDOREC_FEATURE_TIME_LIMIT_1 * 1000;
            break;

        case VDOREC_SETTING_TIME_LIMIT_2:
            video_preview_data.time_limit = VDOREC_FEATURE_TIME_LIMIT_2 * 1000;
            break;

        case VDOREC_SETTING_TIME_LIMIT_3:
            video_preview_data.time_limit = VDOREC_FEATURE_TIME_LIMIT_3 * 1000;
            break;

        default:
            video_preview_data.time_limit = 0;
            break;
    }
    #endif /* __VDOREC_FEATURE_SIZE_LIMIT__ */ 

	#ifndef __VDOREC_FEATURE_EXT_REQ_DISABLE__
    /* if this is an external record request */
    if (g_vdorec_cntx.is_ext_req)
    {
        /* use only external req record size */
        //video_preview_data.size_limit = 0;
        if (g_vdorec_cntx.ext_req_size > 0 || g_vdorec_cntx.ext_req_size == 0)
        {
            video_preview_data.size_limit = g_vdorec_cntx.ext_req_size;
        }
        if (g_vdorec_cntx.ext_rec_time > 0 || g_vdorec_cntx.ext_rec_time == 0)
        {
            video_preview_data.time_limit = g_vdorec_cntx.ext_rec_time;
        }
    }
	#endif

#ifdef __VDOREC_FEATURE_RECORD_AUD__
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
    #endif
    video_preview_data.record_aud = g_vdorec_cntx.setting.record_aud;
#else /* __VDOREC_FEATURE_RECORD_AUD__ */ 
    video_preview_data.record_aud = TRUE;
#endif /* __VDOREC_FEATURE_RECORD_AUD__ */
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    /*config the video layer*/
    preview_layer_flag = GDI_LAYER_ENABLE_LAYER_0;
    blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0;

	#ifndef __VDOREC_FEATURE_MULTI_REGION_SUPPORT__
    if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE)
    {
        blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
    }
    #else
    {
        if (g_vdorec_cntx.osd_layer_region_handle[0])
        {
            blt_layer_flag |= GDI_LAYER_ENABLE_LAYER_1;
        }
        
        if (g_vdorec_cntx.osd_layer_region_handle[1])
        {
            blt_layer_flag |= GDI_LAYER_ENABLE_LAYER_2;
        }
        
        if (g_vdorec_cntx.osd_layer_region_handle[2])
        {
            blt_layer_flag |= GDI_LAYER_ENABLE_LAYER_3;
        }
        
#ifdef GDI_6_LAYERS
        if (g_vdorec_cntx.osd_layer_region_handle[3])
        {
            blt_layer_flag |= GDI_LAYER_ENABLE_LAYER_4;
        }
#endif
    }
	#endif
	
#if 0    
/* under construction !*/
#ifdef __MDI_DISPLAY_YUYV422_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

    g_vdorec_cntx.last_error 
        = mdi_video_rec_preview_start(
            g_vdorec_cntx.preview_layer_handle,
            blt_layer_flag,
            preview_layer_flag,
            MMI_TRUE,
            &video_preview_data);
    g_vdorec_cntx.is_preview_started = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_enter_state
 * DESCRIPTION
 *  enter state
 * PARAMETERS
 *  state       [IN]        
 *  a(?)        [IN]        Next state to be entered
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_enter_state(U16 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 prev_time_sec;
    S32 video_width;
    S32 video_height;
    U16 prev_state;
    U16 prev_zoom;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTER_STATE, state);

    /* flush key event */
    ClearKeyEvents();
    ClearInputEventHandler(MMI_DEVICE_KEY);
    g_vdorec_cntx.is_lsk_pressed = FALSE;
    g_vdorec_cntx.is_rsk_pressed = FALSE;
    g_vdorec_cntx.is_ck_pressed = FALSE;
#ifdef __VDOREC_FEATURE_ZOOM__
    g_vdorec_cntx.is_zoom_in_key_pressed = FALSE;
    g_vdorec_cntx.is_zoom_out_key_pressed = FALSE;
#endif
#ifdef __VDOREC_FEATURE_EV__
    g_vdorec_cntx.is_ev_inc_key_pressed = FALSE;
    g_vdorec_cntx.is_ev_dec_key_pressed = FALSE;
#endif

#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
    g_vdorec_cntx.is_del_key_pressed = FALSE;
#endif /*  __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

	SetKeyDownHandler(mmi_vdorec_lsk_press_hdlr, KEY_LSK);
	SetKeyUpHandler(mmi_vdorec_lsk_release_hdlr, KEY_LSK);

	if(state == VDOREC_STATE_PAUSE || state == VDOREC_STATE_RECORD)
	{
		SetKeyDownHandler(UI_dummy_function, KEY_LSK);
		SetKeyUpHandler(UI_dummy_function, KEY_LSK);
	}

	SetKeyDownHandler(mmi_vdorec_rsk_press_hdlr, KEY_RSK);
	SetKeyUpHandler(mmi_vdorec_rsk_release_hdlr, KEY_RSK);

#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
#if defined(__VDOREC_FEATURE_EV__) && !defined(__VDOREC_FEATURE_FTE_SUPPORT__)
	SetKeyDownHandler(mmi_vdorec_inc_ev_key_press_hdlr, KEY_DOWN_ARROW);
	SetKeyUpHandler(mmi_vdorec_inc_ev_key_release_hdlr, KEY_DOWN_ARROW);
	SetKeyRepeatHandler(UI_dummy_function, KEY_DOWN_ARROW);
	SetKeyDownHandler(mmi_vdorec_dec_ev_key_press_hdlr, KEY_UP_ARROW);
	SetKeyUpHandler(mmi_vdorec_dec_ev_key_release_hdlr, KEY_UP_ARROW);
	SetKeyRepeatHandler(UI_dummy_function, KEY_UP_ARROW);
#endif /* __VDOREC_FEATURE_EV__ */
#ifdef __VDOREC_FEATURE_ZOOM__
	SetKeyDownHandler(mmi_vdorec_zoom_out_key_press_hdlr, KEY_LEFT_ARROW);
	SetKeyUpHandler(mmi_vdorec_zoom_out_key_release_hdlr, KEY_LEFT_ARROW);
	SetKeyRepeatHandler(UI_dummy_function, KEY_LEFT_ARROW);
	SetKeyDownHandler(mmi_vdorec_zoom_in_key_press_hdlr, KEY_RIGHT_ARROW);
	SetKeyUpHandler(mmi_vdorec_zoom_in_key_release_hdlr, KEY_RIGHT_ARROW);
	SetKeyRepeatHandler(UI_dummy_function, KEY_RIGHT_ARROW);
#endif /* __VDOREC_FEATURE_ZOOM__ */
#else /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ /* normal view */
#if defined(__VDOREC_FEATURE_EV__) && !defined(__VDOREC_FEATURE_FTE_SUPPORT__)
	SetKeyDownHandler(mmi_vdorec_inc_ev_key_press_hdlr, KEY_RIGHT_ARROW);
	SetKeyUpHandler(mmi_vdorec_inc_ev_key_release_hdlr, KEY_RIGHT_ARROW);
	SetKeyRepeatHandler(UI_dummy_function, KEY_RIGHT_ARROW);
	SetKeyDownHandler(mmi_vdorec_dec_ev_key_press_hdlr, KEY_LEFT_ARROW);
	SetKeyUpHandler(mmi_vdorec_dec_ev_key_release_hdlr, KEY_LEFT_ARROW);
	SetKeyRepeatHandler(UI_dummy_function, KEY_LEFT_ARROW);
#endif /* __VDOREC_FEATURE_EV__ */    
#ifdef __VDOREC_FEATURE_ZOOM__
	SetKeyDownHandler(mmi_vdorec_zoom_out_key_press_hdlr, KEY_DOWN_ARROW);
	SetKeyUpHandler(mmi_vdorec_zoom_out_key_release_hdlr, KEY_DOWN_ARROW);
	SetKeyRepeatHandler(UI_dummy_function, KEY_DOWN_ARROW);
	SetKeyDownHandler(mmi_vdorec_zoom_in_key_press_hdlr, KEY_UP_ARROW);
	SetKeyUpHandler(mmi_vdorec_zoom_in_key_release_hdlr, KEY_UP_ARROW);
	SetKeyRepeatHandler(UI_dummy_function, KEY_UP_ARROW);
#endif /* __VDOREC_FEATURE_ZOOM__ */
#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

#ifndef __MMI_VIDEO_RECORDER_SLIM__
#ifdef __VDOREC_FEATURE_ZOOM__
	SetKeyDownHandler(mmi_vdorec_zoom_out_key_press_hdlr, KEY_VOL_DOWN);
	SetKeyUpHandler(mmi_vdorec_zoom_out_key_release_hdlr, KEY_VOL_DOWN);
	SetKeyRepeatHandler(UI_dummy_function, KEY_VOL_DOWN);
	SetKeyDownHandler(mmi_vdorec_zoom_in_key_press_hdlr, KEY_VOL_UP);
	SetKeyUpHandler(mmi_vdorec_zoom_in_key_release_hdlr, KEY_VOL_UP);
	SetKeyRepeatHandler(UI_dummy_function, KEY_VOL_UP);
#endif /* __VDOREC_FEATURE_ZOOM__ */
#endif
    /* have dedicate record key */
	SetKeyDownHandler(mmi_vdorec_ck_press_hdlr, VDOREC_RECORD_KEY);
	SetKeyUpHandler(mmi_vdorec_ck_release_hdlr, VDOREC_RECORD_KEY);

#ifdef __VDOREC_FEATURE_SWITCH_TO_CAMERA__
    /* key 0 will not use 
    	SetKeyDownHandler(mmi_vdorec_ck_press_hdlr, KEY_0);
	SetKeyUpHandler(mmi_vdorec_ck_release_hdlr, KEY_0);
    */
#ifdef __MMI_CAMERA__
    if (VDOREC_SWITCH_TO_CAMERA_KEY != -1 && !g_vdorec_cntx.is_ext_req)
    {
		SetKeyDownHandler(mmi_vdorec_switch_to_camera_hdlr, (U16)VDOREC_SWITCH_TO_CAMERA_KEY);
    }
#endif /* __MMI_CAMERA__ */
#endif  /* __VDOREC_FEATURE_SWITCH_TO_CAMERA__ */


    if (VDOREC_RECORD_EXTRA_KEY1 != -1)
    {
		SetKeyDownHandler(mmi_vdorec_ck_press_hdlr, (U16)(VDOREC_RECORD_EXTRA_KEY1));
		SetKeyUpHandler(mmi_vdorec_ck_release_hdlr, (U16)(VDOREC_RECORD_EXTRA_KEY1));
		SetKeyLongpressHandler(mmi_vdorec_null_key_event, (U16)(VDOREC_RECORD_EXTRA_KEY1));
    }

    if (VDOREC_RECORD_EXTRA_KEY2 != -1)
    {
		SetKeyDownHandler(mmi_vdorec_ck_press_hdlr, (U16)(VDOREC_RECORD_EXTRA_KEY2));
		SetKeyUpHandler(mmi_vdorec_ck_release_hdlr, (U16)(VDOREC_RECORD_EXTRA_KEY2));
		SetKeyLongpressHandler(mmi_vdorec_null_key_event, (U16)(VDOREC_RECORD_EXTRA_KEY2));
    }

	
#ifndef __MMI_VIDEO_RECORDER_SLIM__
    /* hot keys */
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    if (VDOREC_VIDEO_SIZE_KEY != -1)
    {
		SetKeyDownHandler(mmi_vdorec_video_size_hotkey_press, (U16)VDOREC_VIDEO_SIZE_KEY);
    }
#endif

#ifdef __VDOREC_FEATURE_VIDEO_QTY__
    if (VDOREC_VIDEO_QTY_KEY != -1)
    {
		SetKeyDownHandler(mmi_vdorec_video_qty_hotkey_press, (U16)VDOREC_VIDEO_QTY_KEY);
    }
#endif

#if 0
#ifdef __VDOREC_FEATURE_NIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __VDOREC_FEATURE_NIGHT__ */
#endif

    
#ifdef __VDOREC_FEATURE_WB__
    if (VDOREC_WB_KEY != -1)
    {
		SetKeyDownHandler(mmi_vdorec_wb_hotkey_press, (U16)VDOREC_WB_KEY);
    }
#endif /* __VDOREC_FEATURE_WB__ */ 

#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
    if (VDOREC_LED_HIGHLIGHT_KEY != -1)
    {
		SetKeyDownHandler(mmi_vdorec_led_highlight_hotkey_press, (U16)VDOREC_LED_HIGHLIGHT_KEY);
    }
#endif /* __VDOREC_FEATURE_LED_HIGHLIGHT__ */ 

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    if (VDOREC_RECORD_AUD_KEY != -1)
    {
		SetKeyDownHandler(mmi_vdorec_record_aud_hotkey_press, (U16)VDOREC_RECORD_AUD_KEY);
    }
#endif /* __VDOREC_FEATURE_RECORD_AUD__ */ 

#endif  /*__MMI_VIDEO_RECORDER_SLIM__*/

#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
    if (state == VDOREC_STATE_VIDEO_PREVIEW_PLAY || state == VDOREC_STATE_VIDEO_PREVIEW_STOP)
    {
        if (VDOREC_DELETE_KEY != -1)
        {
			SetKeyDownHandler(mmi_vdorec_del_key_press_hdlr, (U16)VDOREC_DELETE_KEY);
			SetKeyUpHandler(mmi_vdorec_del_key_release_hdlr, (U16)VDOREC_DELETE_KEY);
        }
    }
#endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

#ifndef __MMI_VIDEO_RECORDER_SLIM__
#ifdef VDOREC_TOGGLE_HIDE_OSD_KEY
    if (g_vdorec_cntx.is_support_toggle_osd)
    {
        if (state == VDOREC_STATE_PREVIEW || state == VDOREC_STATE_RECORD ||
            state == VDOREC_STATE_PAUSE || state == VDOREC_STATE_BG_CALL)
        {
			SetKeyDownHandler(mmi_vdorec_toggle_osd_key_press_hdlr, (U16)VDOREC_TOGGLE_HIDE_OSD_KEY);
        }
    }
#endif
#endif

    mmi_frm_scrn_set_key_proc(g_vdorec_cntx.cur_gid, mmi_frm_scrn_get_active_id(), mmi_vdorec_listen_key_proc); 
    switch (state)
    {
        case VDOREC_STATE_PREVIEW:
        {
            prev_state = g_vdorec_cntx.state;
            g_vdorec_cntx.state = state;

            if (g_vdorec_cntx.is_watchdog_support)
            {
                mmi_vdorec_reset_watchdog_time_out_handler();
                mmi_vdorec_watchdog_time_out_handler();

            }

            if (mmi_vdorec_is_in_bgcall())
            {
                mdi_util_show_not_available_in_call_hint(g_vdorec_cntx.preview_layer_handle, 0, 0, 
                    g_vdorec_cntx.preview_wnd_width, g_vdorec_cntx.preview_wnd_height);
            }

            mmi_vdorec_set_softkey(STR_GLOBAL_OPTIONS, STR_GLOBAL_BACK, 0, 0, IMG_ID_VDOREC_SK_RECORD);
            mmi_vdorec_draw_osd(
        		VDOREC_OSD_COMPONENT_STATUS|
        		VDOREC_OSD_COMPONENT_EV|
        		VDOREC_OSD_COMPONENT_ZOOM|
        		VDOREC_OSD_COMPONENT_SOFTKEY);
            mmi_vdorec_blt_screen();

            /* start preview */
            if (!mmi_vdorec_is_in_bgcall())
            {
                mmi_vdorec_start_preview();
            }
            
            /* error check */
            if (mmi_vdorec_check_and_display_error_popup() == TRUE)     /* TRUE means has error */
            {
                return;
            }

            if (prev_state == VDOREC_STATE_EXIT)
            {
                mdi_camera_zoom_info p_info;
                
                /* get zoom limit after preview start */
                mmi_vdorec_get_video_size(&video_width, &video_height);
                prev_zoom = g_vdorec_cntx.zoom_limit;
                
                mdi_video_rec_query_zoom_info(&p_info);
                g_vdorec_cntx.zoom_limit = p_info.max_zoom_factor;
                g_vdorec_cntx.max_zoom_steps = p_info.zoom_steps;

                /* if zoom is like 2.6x, round it to 2.0x */
                //g_vdorec_cntx.zoom_limit /= 10;
                //g_vdorec_cntx.zoom_limit *= 10;

                if (g_vdorec_cntx.zoom_limit < 100)
                {
                    g_vdorec_cntx.zoom_limit = 100;
                }

                if (prev_zoom != g_vdorec_cntx.zoom_limit)
                {
                #ifdef __VDOREC_FEATURE_ZOOM__
                    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM);
                #endif
                    mmi_vdorec_blt_screen();
                }
            }
                        
        }
            break;

        case VDOREC_STATE_RECORD:
        {
            S32 create_result;
            U16 string_id = STR_GLOBAL_ERROR;
            S32 event_type = MMI_EVENT_FAILURE;

            if (!mmi_vdorec_check_valid_drv())
            {
                mmi_vdorec_storage_change();
                return;
            }

            create_result = mmi_vdoply_create_file_dir((CHAR *) g_vdorec_cntx.storage_filepath);;
            if (create_result != FS_NO_ERROR)
            {
                string_id = srv_fmgr_fs_error_get_string_and_popup_type(create_result, &event_type);

                mmi_vdorec_disply_popup(
                    string_id,
                    (mmi_event_notify_enum)event_type,
                    MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);

                return;
            }

            prev_state = g_vdorec_cntx.state;
            g_vdorec_cntx.state = state;

            if (g_vdorec_cntx.is_watchdog_support)
            {
                mmi_vdorec_reset_watchdog_time_out_handler();
            }

            if (prev_state == VDOREC_STATE_PAUSE)
            {
                g_vdorec_cntx.last_error = mdi_video_rec_record_resume();

                /* 
                 * this may happend Meida send out record finsih message but MMI not receive it,
                 * meanwhile MMI try to pasue.
                 * MDI will ignore this meassge when some one call pause API at this situation, so
                 * MMI has to enter save screen
                 */
                if (g_vdorec_cntx.last_error == MDI_RES_VDOREC_RECORD_ALREADY_STOP)
                {
                #if defined(__VDOREC_FEATURE_DIRECT_SAVE__) || defined(__VDOREC_FEATURE_SLIM_UE__)
                    g_vdorec_cntx.is_saving = TRUE;
                    g_vdorec_cntx.is_show_saving = MMI_TRUE;
                    mmi_vdorec_entry_saving_screen();
                #else
                    mmi_vdorec_entry_save_confirm_screen();
                #endif /* __VDOREC_FEATURE_DIRECT_SAVE__ */
                    return;
                }
            }
            else
            {
                if (srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) != SRV_PROF_RET_PROFILE_ACTIVATED)
                {
                    #if defined(__OP11__)
                        srv_prof_play_tone(SRV_PROF_TONE_GENERAL_TONE, NULL);
                    #else
                        srv_prof_play_tone(SRV_PROF_TONE_WARNING, NULL);
                    #endif
                }
                kal_sleep_task(50);                     /* sleep mmi to avoid the record tone is being recorded */
                mmi_frm_start_scenario(MMI_SCENARIO_ID_VDO_REC);            
                /* before record start, commit the seq num */
                ReadValueSlim(NVRAM_VDOREC_FILENAME_SEQ_NO, &g_vdorec_cntx.filename_seq_no, DS_SHORT);
                g_vdorec_cntx.filename_seq_no++;
                WriteValueSlim(NVRAM_VDOREC_FILENAME_SEQ_NO, &g_vdorec_cntx.filename_seq_no, DS_SHORT);

                g_vdorec_cntx.last_error = mdi_video_rec_record_start(g_vdorec_cntx.filepath, mmi_vdorec_record_result_hdlr_callback,NULL);
            }

            /* error check */
            if (mmi_vdorec_check_and_display_error_popup() == TRUE)     /* TRUE means has error */
            {
                return;
            }
            
            /* draw softkey in OSD layer */	
            mmi_vdorec_set_softkey(0, STR_GLOBAL_STOP, 0, 0, IMG_ID_VDOREC_SK_PAUSE);
            
        		#ifdef __VDOREC_FEATURE_LIMIT_PROGRESS_BAR__
            if (mmi_vdorec_is_draw_progress_bar())
            {
                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY|VDOREC_OSD_COMPONENT_TIMER|VDOREC_OSD_COMPONENT_PROGRESS|VDOREC_OSD_COMPONENT_STATE);
            }
            else
        		#endif
            {
                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY|VDOREC_OSD_COMPONENT_TIMER|VDOREC_OSD_COMPONENT_STATE);
            }

            mmi_vdorec_blt_screen();

            /* start draw timer */
            mmi_vdorec_record_timer_cyclic();
        }
            break;

        case VDOREC_STATE_PAUSE:
        {
            g_vdorec_cntx.state = state;

            mmi_vdorec_set_softkey(0, STR_GLOBAL_STOP, 0, 0, IMG_ID_VDOREC_SK_RESUME);

            gui_cancel_timer(mmi_vdorec_record_timer_cyclic);
            if (g_vdorec_cntx.is_timer_show)
            {
                /* draw the record time when before stopping on screen */
                prev_time_sec = (U32) (g_vdorec_cntx.record_time / 1000);            
                mdi_video_rec_get_cur_record_time(&g_vdorec_cntx.record_time);
                if ((g_vdorec_cntx.record_time / 1000) > prev_time_sec)
                {
                    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_TIMER | VDOREC_OSD_COMPONENT_SOFTKEY|VDOREC_OSD_COMPONENT_STATE);
                }
                else
                {
                    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY|VDOREC_OSD_COMPONENT_STATE);
                }
			}
            else
            {
                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY|VDOREC_OSD_COMPONENT_STATE);
            }
            mmi_vdorec_blt_screen();

            //if (!g_vdorec_cntx.is_pen_down_update)
            {
                g_vdorec_cntx.last_error = mdi_video_rec_record_pause(KAL_FALSE);
                
                /* 
                * this may happend Meida send out record finsih message but MMI not receive it,
                * meanwhile MMI try to pasue.
                * MDI will ignore this meassge when some one call pause API at this situation, so
                * MMI has to enter save screen
                */
                if (g_vdorec_cntx.last_error == MDI_RES_VDOREC_RECORD_ALREADY_STOP)
                {
                #if defined(__VDOREC_FEATURE_DIRECT_SAVE__) || defined(__VDOREC_FEATURE_SLIM_UE__)
                    g_vdorec_cntx.is_saving = TRUE;
					g_vdorec_cntx.is_show_saving = MMI_TRUE;
                    mmi_vdorec_entry_saving_screen();
                #else
                    mmi_vdorec_entry_save_confirm_screen();
                #endif /* __VDOREC_FEATURE_DIRECT_SAVE__ */
                    return;
                }
                else if (g_vdorec_cntx.last_error == MDI_RES_VDOREC_DISK_FULL)
                {
                    mmi_vdorec_disply_popup(
                        FMGR_FS_DISK_FULL_TEXT,
                        MMI_EVENT_FAILURE,
                        MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
                    return;
                }
                else if (g_vdorec_cntx.last_error == MDI_RES_VDOREC_REACH_SIZE_LIMIT)
                {
                    mmi_vdorec_disply_popup(
                        STR_ID_VDOREC_SIZE_LIMIT,
                        MMI_EVENT_INFO,
                        MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
                    return;
                }
                else if (g_vdorec_cntx.last_error == MDI_RES_VDOREC_REACH_TIME_LIMIT)
                {
                    mmi_vdorec_disply_popup(
                        STR_ID_VDOREC_TIME_LIMIT,
                        MMI_EVENT_INFO,
                        MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
                    return;
                }
                /* pasue error check */
                if (mmi_vdorec_check_and_display_error_popup() == TRUE)     /* TRUE means has error */
                {
                    return;
                }
            }
        }
            break;
    #ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
        case VDOREC_STATE_VIDEO_PREVIEW_PLAY:
        #ifdef __MMI_CAMERA__
            if (VDOREC_SWITCH_TO_CAMERA_KEY != -1 && !g_vdorec_cntx.is_ext_req)
            {
				SetKeyDownHandler(UI_dummy_function, (U16)VDOREC_SWITCH_TO_CAMERA_KEY);
            }
        #endif /* __MMI_CAMERA__ */

            mmi_vdorec_fsm_preview_play();
            g_vdorec_cntx.state = state;

            if (VDOREC_SWITCH_TO_CAMERA_KEY != -1)
            {
				SetKeyDownHandler(UI_dummy_function, (U16)VDOREC_SWITCH_TO_CAMERA_KEY);
            }
            if (VDOREC_DELETE_KEY != -1)
            {
				SetKeyDownHandler(mmi_vdorec_del_key_press_hdlr, (U16)VDOREC_DELETE_KEY);
				SetKeyUpHandler(mmi_vdorec_del_key_release_hdlr, (U16)VDOREC_DELETE_KEY);
            }
            /* overwrite record key */
			SetKeyUpHandler((mmi_void_funcptr_type)mmi_frm_scrn_close_active_id, VDOREC_RECORD_KEY);
        
            break;
            
        case VDOREC_STATE_VIDEO_PREVIEW_STOP:
        #ifdef __MMI_CAMERA__
            if (VDOREC_SWITCH_TO_CAMERA_KEY != -1 && !g_vdorec_cntx.is_ext_req)
            {
				SetKeyDownHandler(UI_dummy_function, (U16)VDOREC_SWITCH_TO_CAMERA_KEY);
            }
        #endif /* __MMI_CAMERA__ */

            g_vdorec_cntx.state = state;
            mmi_vdorec_fsm_preview_stop();
            if (VDOREC_SWITCH_TO_CAMERA_KEY != -1)
            {
				SetKeyDownHandler(UI_dummy_function, (U16)VDOREC_SWITCH_TO_CAMERA_KEY);
            }
            if (VDOREC_DELETE_KEY != -1)
            {
				SetKeyDownHandler(mmi_vdorec_del_key_press_hdlr, (U16)VDOREC_DELETE_KEY);
				SetKeyUpHandler(mmi_vdorec_del_key_release_hdlr, (U16)VDOREC_DELETE_KEY);
            }
            /* overwrite record key */            
			SetKeyUpHandler((mmi_void_funcptr_type)mmi_frm_scrn_close_active_id, VDOREC_RECORD_KEY);
            break;
            
        case VDOREC_STATE_VIDEO_PREVIEW_BGCALL:
        #ifdef __MMI_CAMERA__
            if (VDOREC_SWITCH_TO_CAMERA_KEY != -1 && !g_vdorec_cntx.is_ext_req)
            {
				SetKeyDownHandler(UI_dummy_function, (U16)VDOREC_SWITCH_TO_CAMERA_KEY);
            }
        #endif /* __MMI_CAMERA__ */

            g_vdorec_cntx.state = state;
            if (VDOREC_SWITCH_TO_CAMERA_KEY != -1)
            {
				SetKeyDownHandler(UI_dummy_function, (U16)VDOREC_SWITCH_TO_CAMERA_KEY);
            }
            if (VDOREC_DELETE_KEY != -1)
            {
				SetKeyDownHandler(mmi_vdorec_del_key_press_hdlr, (U16)VDOREC_DELETE_KEY);
				SetKeyUpHandler(mmi_vdorec_del_key_release_hdlr, (U16)VDOREC_DELETE_KEY);
            }
            /* overwrite record key */            
			SetKeyUpHandler((mmi_void_funcptr_type)mmi_frm_scrn_close_active_id, VDOREC_RECORD_KEY);
            break;
    #endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */
    
        default:
            MMI_ASSERT(0);
            break;

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_app_pre_check
 * DESCRIPTION
 *  return wheather video recorder should be available now.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static BOOL mmi_vdorec_entry_app_pre_check(CHAR * p_filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cur_storage;
    MMI_STR_ID string_id;
    mmi_event_notify_enum event_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_APP_PRE_CHECK);

#if defined(__MMI_BACKGROUND_CALL__)
    if (mmi_vdorec_is_in_bgcall())
    {
        string_id = mmi_ucm_get_error_info(MMI_UCM_ERR_IS_BG_CALL, &event_type);
        mmi_vdorec_disply_popup(
            string_id,
            event_type,
            MMI_VDOREC_POPUP_RESULT_PROCESS_DELETE_GROUP);
        return MMI_FALSE;
    }
#endif /* __MMI_BACKGROUND_CALL__ */

#ifdef __MMI_USB_SUPPORT__
#if defined(__USB_IN_NORMAL_MODE__)
    if (srv_usb_is_in_mass_storage_mode() && srv_usb_check_path_exported((WCHAR*)p_filepath))
    {
        /* phone drive is exported, cant use this app */
        string_id = mmi_usb_get_error_info(SRV_USB_ERROR_UNAVAILABLE, &event_type);
        mmi_vdorec_disply_popup(
            string_id,
            event_type,
            MMI_VDOREC_POPUP_RESULT_PROCESS_DELETE_GROUP);
        return MMI_FALSE;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 
#endif

#ifdef __VDOREC_FEATURE_STORAGE__
    /* check if there is no storage or not*/
    {
        SRV_FMGR_DRVLIST_HANDLE drv_list;
        U8  total_drv_num;

        drv_list = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY);
        total_drv_num = (U8)srv_fmgr_drivelist_count(drv_list); 
        srv_fmgr_drivelist_destroy(drv_list);

        if (total_drv_num == 0)
        {
            mmi_vdorec_disply_popup(
                STR_GLOBAL_INSERT_MEMORY_CARD,
                MMI_EVENT_FAILURE,
                MMI_VDOREC_POPUP_RESULT_PROCESS_DELETE_GROUP);
            return MMI_FALSE;
        }
    }
#endif

#ifdef __MMI_BT_SUPPORT__
    /* if is 6223 or 6225 series, cant concurrent with background BT action */
    if (mmi_bt_is_receiving())
    {
        mmi_vdorec_disply_popup(
            STR_ID_VDOREC_NOTIFY_BT_IS_WORKING,
            MMI_EVENT_FAILURE,
            MMI_VDOREC_POPUP_RESULT_PROCESS_DELETE_GROUP);
        return MMI_FALSE;
    }
#endif /* __MMI_BT_SUPPORT__ */


//#if !defined(MDI_VIDEO_MT6228_SERIES)
    /* this is used to solve MMS background send, which will cause bandwidth not enoguth */
    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_DATA_CSD_ALL, NULL) > 0)
    {
        mmi_vdorec_disply_popup(
            STR_ID_VDOREC_NOTIFY_SYSTEM_TOO_BUSY,
            MMI_EVENT_FAILURE,
            MMI_VDOREC_POPUP_RESULT_PROCESS_DELETE_GROUP);
        return MMI_FALSE;
    }
//#endif /* !defined(MDI_VIDEO_MT6228_SERIES) */

    /* 
     * Check if device is busy, this may happened user abort file copying, 
     * but driver is till aborting 
     */
    cur_storage = mmi_vdoply_get_storage();

    if (FS_GetDevStatus(cur_storage, FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY)
    {
        mmi_vdorec_disply_popup(
            STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
            MMI_EVENT_FAILURE,
            MMI_VDOREC_POPUP_RESULT_PROCESS_DELETE_GROUP);
        return MMI_FALSE;
    }

#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) && defined(__MTK_TARGET__)
    /* back to idle if clam is closed */
    if (srv_clam_is_close())
    {
        mmi_idle_display();
        return MMI_FALSE;
    }
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) && defined(__MTK_TARGET__) */ 


#if defined(__MMI_OP01_DCD__)
    if (mmi_dcd_is_syncing())
    {
        string_id = mmi_dcd_get_error_info(MMI_DCD_ERR_IS_SYNCING, &event_type);
        mmi_vdorec_disply_popup(
            string_id,
            event_type,
            MMI_VDOREC_POPUP_RESULT_PROCESS_DELETE_GROUP);

        return MMI_FALSE;
    }
    else
    {
        mmi_dcd_line_taken();
    }
#endif

    /*
     *  vre will steal med memory and use app memory, when vre is background running, enter vdorec
     *  if use hw rotator, will popup OOM when apply app memory while vre, so need not to check
     *  otherwise, mdi video recorder does not have enough med memory, it will assert fail
     *  so need to check if vre is using med memory when enter vdorec
     */
#ifndef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    if (mmi_am_is_using_media_memory())
    {
        S32 popup_type;
        string_id = mmi_am_get_error_info(MMI_MRE_ERR_IS_UNAVAILABLE, &popup_type);
        mmi_vdorec_disply_popup(
            string_id,
            MMI_EVENT_FAILURE,
            MMI_VDOREC_POPUP_RESULT_PROCESS_DELETE_GROUP);
        return FALSE;
    }
#endif

#ifdef __VDOREC_FEATURE_STORAGE__
    if (g_vdorec_cntx.is_change_storage)
    {
        g_vdorec_cntx.is_direct_exit = TRUE;
        g_vdorec_cntx.is_change_storage = FALSE;

        mmi_frm_scrn_enter (g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_APP, mmi_vdorec_exit_app, mmi_vdorec_entry_app_internal, MMI_FRM_UNKNOW_SCRN);

        return MMI_FALSE;
    }
#endif /* __VDOREC_FEATURE_STORAGE__ */    

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_app_internal
 * DESCRIPTION
 *  video record app entry point
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_app_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR buf_filepath[SRV_FMGR_PATH_BUFFER_SIZE];
#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    //S32 layer_offset_x;
    //S32 layer_offset_y;
    S32 layer_width = 0;
    S32 layer_height = 0;
#endif
    MMI_BOOL entry_ret;
    PU8 base_layer_ptr;
    S32 buffer_size;
    U8 *guiBuffer;
    
    mdi_util_create_hw_layer_extmemory_in_struct preview_layer_in;
    mdi_util_create_hw_layer_out_struct preview_layer_out;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_APP_INTERNAL);

    /* load setting */
    mmi_vdorec_load_setting();
    mmi_vdoply_get_storage_file_path(buf_filepath);

    if (mmi_vdorec_entry_app_pre_check(buf_filepath) == MMI_FALSE)
    {
        return; /* pre check failed, video recorder is not available now. */
    }

    if (mmi_vdorec_disable_gprs() == MMI_FALSE)
    {
        return;
    }

    g_vdorec_cntx.is_giveup_popup_rotate = MMI_FALSE;

    entry_ret = mmi_frm_scrn_enter (g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_APP, mmi_vdorec_exit_app, mmi_vdorec_entry_app_internal, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }
    g_vdorec_cntx.is_end_key = MMI_FALSE;
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);

    //mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGHEST_SCRN);
    //mmi_frm_start_scenario(MMI_SCENARIO_ID_VDO_REC);
    mmi_vdorec_init_according_to_compile_option();

#ifdef __MMI_BT_SUPPORT__
    mmi_bt_disable_receiving();   /* disable BT back ground receive. remember to resume when exit this screen */
#endif

#ifdef __MMI_SCREEN_SWITCH_EFFECT__     /* disable SSE */
    gui_screen_switch_effect_block(MMI_TRUE);
#endif

    g_vdorec_cntx.is_direct_exit = FALSE;
    
    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    entry_full_screen();

    guiBuffer = mmi_frm_scrn_get_gui_buf(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_APP);
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
    /* entry sublcd */
#ifdef __MMI_SUBLCD__
    if (!mmi_is_redrawing_bk_screens())
    {
        if (!g_vdorec_cntx.is_sub_display)
        {
            ForceSubLCDScreen(mmi_vdorec_entry_sublcd_screen);
        }
    }
#endif /* __MMI_SUBLCD__ */ 

#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) 
    mmi_frm_cb_reg_event(EVT_ID_PRE_PROTOCOL, mmi_vdorec_clam_close_event_hdlr, NULL);
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */ 

    /* hook to touch screen callback */
#if defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_pen_down_handler(mmi_vdorec_touch_scr_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_vdorec_touch_scr_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_vdorec_touch_scr_pen_move_hdlr);
#endif /* defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ 

    if (guiBuffer == NULL)
    {
        /* each time newly enter vdorec, zoom will be reset to default */
        g_vdorec_cntx.setting.zoom = VDOREC_DEFAULT_SETTING_ZOOM;
        g_vdorec_cntx.zoom_limit = VDOREC_FEAUTRE_ZOOM_LIMIT;
    #ifdef __VDOREC_FEATURE_SLIM_UE__
        mmi_vdorec_init_slim_setting();
    #endif

    #ifdef __DIRECT_SENSOR_SUPPORT__
        mdi_video_rec_limited_avi_init();
        g_vdorec_cntx.is_limit_avi_inited = MMI_TRUE;
    #endif

#if defined(__MMI_OP12_CAMERA_VDOREC_CUSTOMIZE__) && defined(__VDOREC_FEATURE_VIDEO_SIZE_SQCIF__)
        if(g_vdorec_cntx.is_ext_req && VDOREC_SETTING_VIDEO_SIZE_COUNT != g_vdorec_cntx.ext_video_size)
        {
            g_vdorec_cntx.setting.video_size = g_vdorec_cntx.ext_video_size;
        }
#endif
    }

    /* init some golbal value */
    g_vdorec_cntx.last_error = MDI_RES_VDOREC_SUCCEED;
    g_vdorec_cntx.record_time = 0;
    g_vdorec_cntx.is_lsk_pressed = FALSE;
    g_vdorec_cntx.is_rsk_pressed = FALSE;
    g_vdorec_cntx.is_ck_pressed = FALSE;
#ifdef __VDOREC_FEATURE_ZOOM__
    g_vdorec_cntx.is_zoom_in_key_pressed = FALSE;
    g_vdorec_cntx.is_zoom_out_key_pressed = FALSE;
#endif
#ifdef __VDOREC_FEATURE_EV__
    g_vdorec_cntx.is_ev_inc_key_pressed = FALSE;
    g_vdorec_cntx.is_ev_dec_key_pressed = FALSE;
#endif
#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
    g_vdorec_cntx.is_del_key_pressed = FALSE;
#endif /*  __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

    /* clear hint buffer */
    //memset(g_vdorec_cntx.hint1_buf, 0, VDOREC_HINT_BUF_SIZE);
    //memset(g_vdorec_cntx.hint2_buf, 0, VDOREC_HINT_BUF_SIZE);

    *((U16*)g_vdorec_cntx.hint1_buf) = 0;
    *((U16*)g_vdorec_cntx.hint2_buf) = 0;

    /* allocate storage path by using submenu's buffer */
    g_vdorec_cntx.storage_filepath = gui_malloc(SRV_FMGR_PATH_BUFFER_SIZE);

    /* check if path is valid or not. if not will pop up a screen after the preview screen is shown */
    //cur_storage = mmi_vdoply_get_storage();

    /* if no error. load path into buffer */
    mmi_vdoply_get_storage_file_path((CHAR *) g_vdorec_cntx.storage_filepath);
    
   /*******************************************************************
   * Init proper global state for video applcation  
   ********************************************************************/
    /* force all playing keypad tone off */
    srv_profiles_stop_tone(SRV_PROF_TONE_KEYPAD);

    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    /* enable multi_layer */
    gdi_layer_multi_layer_enable();

    /* suspend background play */
    mdi_audio_suspend_background_play();
    
    /* disable background play timeout for FM/sensor switch during using same power*/
    mdi_audio_stop_background_timer();        

    /* disalbe align timer */
    UI_disable_alignment_timers();

    /* stop LED patten */
    srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_STOP);

    /* 
     * This is used to solve a very rare situation. When playing a IMELODY 
     * with backlight on/off, and the screen previous to this screen is a 
     * horizontal screen. Before enter this screen, the IMELODY turn off the
     * backlight. While exit previous screen, the layer rotate back to normal
     * size and the content is not correct. So when calling srv_backlight_turn_on, 
     * LCD is in sleepin state and draw wrong content to LCD.
     * So we need to clear the buffer first to avoid this situation.
     */
    gdi_layer_clear(GDI_COLOR_BLACK);

   /* 
    * set this to avoid tearing 
    * gdi will help to cover this before, now app should set this itself 
    */
    g_vdorec_cntx.old_tear_flag = (MMI_BOOL)gdi_lcd_set_te_ctrl(KAL_TRUE);

    /* stop MMI sleep */
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_FALSE);
#endif

    /* use medium font */
    gui_set_font(&MMI_medium_font);

    g_vdorec_cntx.prev_rotate_by_layer = gdi_lcd_get_rotate_by_layer();

    /* if no TV-out, rotate by layer */
    gdi_lcd_set_rotate_by_layer(TRUE);

    /***************************************************************************** 
     * Create layers 
     *****************************************************************************/
#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__

	#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    if (g_vdorec_cntx.is_use_hw_rotate)
    {
        /* MT6238/53 series, will use IDP/LCD rotator */
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);      
    }
    #else 
    {
        /* defined(MDI_VIDEO_MT6238_SERIES) */
        gdi_lcd_set_rotate(GDI_LAYER_ROTATE_270);
    }
	#endif

#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

   /************ base layer layer ************/
    gdi_layer_get_base_handle(&g_vdorec_cntx.bg_layer_handle);
    
    gdi_layer_push_and_set_active(g_vdorec_cntx.bg_layer_handle);
    gdi_layer_get_buffer_ptr(&base_layer_ptr);
    gdi_layer_pop_and_restore_active();

#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    g_vdorec_cntx.lcd_width = UI_device_height;
    g_vdorec_cntx.lcd_height = UI_device_width;

	#ifndef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    if (!g_vdorec_cntx.is_use_hw_rotate)
    {
        /* if not use hw rotator, we will change the bg layer to horizontal size */
        /* if use hw rotator, we will change the bg layer to portrait size */
        gdi_layer_resize(g_vdorec_cntx.lcd_width, g_vdorec_cntx.lcd_height);
    }
    #else
    {
        g_vdorec_cntx.lcd_width = UI_device_width;
        g_vdorec_cntx.lcd_height = UI_device_height;
    }
	#endif

#else /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 
    g_vdorec_cntx.lcd_width = UI_device_width;
    g_vdorec_cntx.lcd_height = UI_device_height;

#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

    /************ preview window layer ************/
#ifdef __DIRECT_SENSOR_SUPPORT__
    g_vdorec_cntx.preview_wnd_width = IMAGE_VIDEO_PREVIEW_WIDTH;
    g_vdorec_cntx.preview_wnd_height = IMAGE_VIDEO_PREVIEW_HEIGHT;

    g_vdorec_cntx.preview_wnd_offset_x = g_vdorec_osd_cntx.preview_wnd.rect.offset_x;
    g_vdorec_cntx.preview_wnd_offset_x += 
          ((g_vdorec_osd_cntx.preview_wnd.rect.width - IMAGE_VIDEO_PREVIEW_WIDTH) >> 1);        
    
    g_vdorec_cntx.preview_wnd_offset_y = g_vdorec_osd_cntx.preview_wnd.rect.offset_y;
    g_vdorec_cntx.preview_wnd_offset_y += 
        ((g_vdorec_osd_cntx.preview_wnd.rect.height - IMAGE_VIDEO_PREVIEW_HEIGHT) >> 1);            

#else /* __DIRECT_SENSOR_SUPPORT__ */
    g_vdorec_cntx.preview_wnd_width = g_vdorec_osd_cntx.preview_wnd.rect.width;
    g_vdorec_cntx.preview_wnd_height = g_vdorec_osd_cntx.preview_wnd.rect.height;
    g_vdorec_cntx.preview_wnd_offset_x = g_vdorec_osd_cntx.preview_wnd.rect.offset_x;
    g_vdorec_cntx.preview_wnd_offset_y = g_vdorec_osd_cntx.preview_wnd.rect.offset_y;
#endif /* __DIRECT_SENSOR_SUPPORT__ */

#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__

#ifdef __MMI_SCREEN_ROTATE__
    mmi_frm_set_self_rotation_flag(MMI_FRM_SCREEN_ROTATE_270);
#endif 

	#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    if (g_vdorec_cntx.is_use_hw_rotate && !g_vdorec_cntx.is_use_hw_rotate_by_lcd)
    {
        /*layer_offset_x = 
            UI_device_width - 
            g_vdorec_cntx.preview_wnd_offset_y - 
            g_vdorec_cntx.preview_wnd_height;
            layer_offset_y = g_vdorec_cntx.preview_wnd_offset_x;*/
        layer_width = g_vdorec_cntx.preview_wnd_height;
        layer_height = g_vdorec_cntx.preview_wnd_width;
    }
    #else
    { 
        /*layer_offset_x = g_vdorec_cntx.preview_wnd_offset_x;
             layer_offset_y = g_vdorec_cntx.preview_wnd_offset_y;*/
        layer_width = g_vdorec_cntx.preview_wnd_width;
        layer_height = g_vdorec_cntx.preview_wnd_height;    
    }
	#endif
	
    /*gdi_layer_create(
        layer_offset_x,
        layer_offset_y,
        layer_width,
        layer_height,
        &g_vdorec_cntx.preview_layer_handle);*/

    buffer_size = layer_width * layer_height * VDOREC_BUFFER_DEPTH;

    preview_layer_in.buffer = base_layer_ptr;
    preview_layer_in.buffer_size = buffer_size;
    preview_layer_in.offset_x = g_vdorec_cntx.preview_wnd_offset_x;
    preview_layer_in.offset_y = g_vdorec_cntx.preview_wnd_offset_y;
    preview_layer_in.width = g_vdorec_cntx.preview_wnd_width;
    preview_layer_in.height = g_vdorec_cntx.preview_wnd_height;
    preview_layer_in.scenario_id = MDI_MULTIMEDIA_RRECORD;
    g_vdorec_cntx.preview_layer_handle = mdi_util_hw_layer_create_with_extmemory(&preview_layer_in, &preview_layer_out);

    gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);

	#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    if(g_vdorec_cntx.is_use_hw_rotate)
    {    
        gdi_layer_set_rotate(GDI_LAYER_ROTATE_90);
    }
	#endif

    //gdi_layer_clear(GDI_COLOR_BLACK);

#ifdef GDI_USING_LAYER_BACKGROUND
    gdi_layer_set_background(GDI_COLOR_BLACK);
#endif

#else /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

    /*gdi_layer_create(
        g_vdorec_cntx.preview_wnd_offset_x,
        g_vdorec_cntx.preview_wnd_offset_y,
        g_vdorec_cntx.preview_wnd_width,
        g_vdorec_cntx.preview_wnd_height,
        &g_vdorec_cntx.preview_layer_handle);*/

    buffer_size = g_vdorec_cntx.preview_wnd_width * g_vdorec_cntx.preview_wnd_height * VDOREC_BUFFER_DEPTH;

    preview_layer_in.buffer = base_layer_ptr;
    preview_layer_in.buffer_size = buffer_size;
    preview_layer_in.offset_x = g_vdorec_cntx.preview_wnd_offset_x;
    preview_layer_in.offset_y = g_vdorec_cntx.preview_wnd_offset_y;
    preview_layer_in.width = g_vdorec_cntx.preview_wnd_width;
    preview_layer_in.height = g_vdorec_cntx.preview_wnd_height;
    preview_layer_in.scenario_id = MDI_MULTIMEDIA_RRECORD;
    g_vdorec_cntx.preview_layer_handle = mdi_util_hw_layer_create_with_extmemory(&preview_layer_in, &preview_layer_out);

    gdi_layer_push_and_set_active(g_vdorec_cntx.preview_layer_handle);
    gdi_layer_set_rotate(GDI_LAYER_ROTATE_0);
    //gdi_layer_clear(GDI_COLOR_BLACK);

#ifdef GDI_USING_LAYER_BACKGROUND
    gdi_layer_set_background(GDI_COLOR_BLACK);
#endif

#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

    gdi_layer_pop_and_restore_active();

    /* resized preview layer */
    mmi_vdorec_resize_preview_layer();

   /***************************************************************************** 
   * register interrupt event hdlr
   *****************************************************************************/
    #ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__
        if (!g_vdorec_cntx.setting.accept_call)
        {
            g_vdorec_cntx.old_call_mode = 
                (srv_callset_blacklist_get_mode(NULL) & SRV_CALLSET_BLACKLIST_REJECT_ALL) ? TRUE : FALSE;
            srv_callset_blacklist_switch_mode(SRV_CALLSET_BLACKLIST_REJECT_ALL, MMI_TRUE, NULL);
        }
    #endif /* __VDOREC_FEATURE_CALL_ACCEPT_OPTION__ */

    //mmi_frm_block_general_interrupt_event(
    //    MMI_FRM_INT_CHARGER | 
    //    MMI_FRM_INT_USB_CHARGER |
    //    MMI_FRM_INT_SMS | 
    //    MMI_FRM_INT_FMGR_CARD | 
    //    MMI_FRM_INT_WAP_MMS | 
    //    MMI_FRM_INT_BT_TASK |
    //    MMI_FRM_INT_MMI_JAVA_TIMEALARM_PUSH);

   /****************************************************************************
   * draw skin                                                                 
   *****************************************************************************/
    mmi_vdorec_init_ui();
	mmi_vdorec_query_info_table();

    gdi_layer_reset_clip(); /* use full screen clip */
    gui_reset_text_clip();  /* use full screen text clip */

    gdi_layer_lock_frame_buffer(); 

    g_vdorec_cntx.progress = 0;

    mmi_vdorec_set_softkey(STR_GLOBAL_OPTIONS, STR_GLOBAL_BACK, 0, 0, IMG_ID_VDOREC_SK_RECORD);

    mmi_vdorec_draw_osd(
        VDOREC_OSD_COMPONENT_STATUS|
        VDOREC_OSD_COMPONENT_EV|
        VDOREC_OSD_COMPONENT_ZOOM|
        VDOREC_OSD_COMPONENT_SOFTKEY);

    gdi_layer_unlock_frame_buffer();

	#ifndef __VDOREC_FEATURE_MULTI_REGION_SUPPORT__
	if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE)
	{
		gdi_layer_set_blt_layer(
			g_vdorec_cntx.preview_layer_handle,
			g_vdorec_cntx.osd_layer_handle,
			0,
			0);
	}
    #else
	#ifdef __VDOREC_FEATURE_MULTI_REGION_LAYER_2__
	if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_TWO)
	{
		gdi_layer_set_blt_layer(
			g_vdorec_cntx.preview_layer_handle,
			g_vdorec_cntx.osd_layer_region_handle[0],
			g_vdorec_cntx.osd_layer_region_handle[1],
			g_vdorec_cntx.osd_layer_region_handle[2]);
	}
	else 
	#endif	
		if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_THREE)
	{
		gdi_layer_set_blt_layer(
			g_vdorec_cntx.preview_layer_handle,
			g_vdorec_cntx.osd_layer_region_handle[0],
			g_vdorec_cntx.osd_layer_region_handle[1],
			g_vdorec_cntx.osd_layer_region_handle[2]);
	}
#ifdef GDI_6_LAYERS
	else
	{    
		gdi_layer_set_blt_layer_ext(
			g_vdorec_cntx.preview_layer_handle,
			g_vdorec_cntx.osd_layer_region_handle[0],
			g_vdorec_cntx.osd_layer_region_handle[1],
			g_vdorec_cntx.osd_layer_region_handle[2],
			g_vdorec_cntx.osd_layer_region_handle[3],
			0);
	}
#endif
	#endif

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        /*if enter new screen ,should redraw full screen, for some area is use layer background to fill color*/
        mmi_vdorec_set_merge_region(0,0, g_vdorec_cntx.lcd_width, g_vdorec_cntx.lcd_height);
    }
	#endif

#ifdef __TC01__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    if (mdi_video_rec_has_unsaved_file(buf_filepath) == TRUE)
    {
        //do not draw anything
    }
    else
    {
    mmi_vdorec_blt_screen();
    }
#endif

    /* this function is entry by small screen's history draw, no need to open file */
    if (mmi_is_redrawing_bk_screens())
    {
        return;
    }

    /* power on HW */
    if (g_vdorec_cntx.last_error == MDI_RES_VDOREC_SUCCEED && !mmi_vdorec_is_in_bgcall())
    {
        /* do not power on if is in call */
        g_vdorec_cntx.last_error = mdi_video_rec_power_on(0);
    }
    mmi_vdorec_auto_adjust_size_and_format();
    if (mmi_vdorec_check_and_display_error_popup() != TRUE) /* !TRUE means error popup displayed */
    {
        /* 
         * if record finish has popup, it will not entry saving directly, 
         * after popup gone, we have to enter saving procedure 
         */

        /* ask media if there is a unsaved file */
        mmi_vdoply_get_storage_file_path(buf_filepath);

		#ifndef __VDOREC_FEATURE_EXT_REQ_DISABLE__
        if (g_vdorec_cntx.is_ext_req && guiBuffer == NULL)
        {
            /* delete unsaved file */
            mdi_video_rec_delete_unsaved_file(buf_filepath);

            if (!g_vdorec_cntx.is_use_ext_req_path)
            {
                /* not using ext req path, we have to get a filename */
                mmi_vdorec_get_save_filename(g_vdorec_cntx.filepath);
            }
            
            mmi_vdorec_enter_state(VDOREC_STATE_PREVIEW);
            mmi_vdorec_turn_on_led_highlight();
        }
        else
		#endif	
        {
            mmi_vdoply_get_storage_file_path(g_vdorec_cntx.filepath);
            mmi_vdorec_load_saved_filename(g_vdorec_cntx.filepath);
            if (mdi_video_rec_has_unsaved_file(buf_filepath) == TRUE)
            {
            	 if(guiBuffer != NULL)
             	 {
             		mmi_vdorec_entry_save_confirm_screen();
					return;
                 }
			     else
			     {
                	#if defined(__VDOREC_FEATURE_DIRECT_SAVE__)
                    	g_vdorec_cntx.is_saving = TRUE;
						g_vdorec_cntx.is_show_saving = MMI_TRUE;
                    	mmi_vdorec_entry_saving_screen();
						//g_vdorec_cntx.is_enter_play_video_scr = TRUE;
					#if defined(__VDOREC_FEATURE_SLIM_UE__) && defined(__VDOREC_FEATURE_PREVIEW_SAVED_FILE__)
                		if (guiBuffer && !g_vdorec_cntx.is_ext_req && g_vdorec_cntx.is_enter_play_video_scr)
                		{
                    		g_vdorec_cntx.is_enter_play_video_scr = FALSE;
                    		mmi_vdorec_entry_preview_video_screen();
                    		return;
                		}
            		#endif
                    	return;
                	#else
				    	g_vdorec_cntx.is_saving = TRUE;
						g_vdorec_cntx.is_show_saving = MMI_FALSE;
                   		 mmi_vdorec_entry_saving_screen();
						//g_vdorec_cntx.is_enter_play_video_scr = TRUE;
						#if defined(__VDOREC_FEATURE_SLIM_UE__) && defined(__VDOREC_FEATURE_PREVIEW_SAVED_FILE__)
                		if (guiBuffer && !g_vdorec_cntx.is_ext_req && g_vdorec_cntx.is_enter_play_video_scr)
                		{
                    		g_vdorec_cntx.is_enter_play_video_scr = FALSE;
                    		mmi_vdorec_entry_preview_video_screen();
                    		return;
                		}
            	    #endif
                    	return;
                #endif
			     	}
            }

            /* generate a new filename */
            mmi_vdorec_get_save_filename(g_vdorec_cntx.filepath);
            mmi_vdorec_enter_state(VDOREC_STATE_PREVIEW);
            mmi_vdorec_turn_on_led_highlight();                
        }
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_exit_app
 * DESCRIPTION
 *  video recorder ext function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_exit_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    gdi_handle base_layer_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_EXIT_APP);
    //mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGHEST_SCRN);
    
    if (g_vdorec_cntx.state == VDOREC_STATE_PAUSE || g_vdorec_cntx.state == VDOREC_STATE_RECORD)
    {
    mmi_frm_end_scenario(MMI_SCENARIO_ID_VDO_REC);
    }
    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
    }

    mmi_vdorec_allow_gprs();

    if (g_vdorec_cntx.is_direct_exit)
    {
        /* 
         * when enter app and we found that we need to change storage, we will show 
         * change strage screen directly, so we dont need execute this exit function 
         */
        return;
    }

#if defined(__MMI_OP01_DCD__)
    mmi_dcd_line_given();
#endif

    /* cancel active timer */
    gui_cancel_timer(mmi_vdorec_record_timer_cyclic);

	#ifndef __VDOREC_HIDE_HINT__
    gui_cancel_timer(mmi_vdorec_hide_hint);
	#endif

#ifdef __VDOREC_FEATURE_ZOOM__
    /*stop zoom*/
	if (g_vdorec_cntx.is_fast_zoom_support)
	{
		mmi_vdorec_stop_fast_zoom();
		gui_cancel_timer(mmi_vdorec_draw_zoom_osd);
		gui_cancel_timer((FuncPtr)mmi_vdorec_start_fast_zoom);
		//gui_cancel_timer(mmi_vdorec_start_fast_zoom);
	}
	else
	{
		mmi_vdorec_stop_fast_zoom();
		gui_cancel_timer((FuncPtr)mmi_vdorec_start_zoom);
		//gui_cancel_timer(mmi_vdorec_start_zoom);
	}
#endif /* __VDOREC_FEATURE_ZOOM__ */ 

#ifdef __VDOREC_FEATURE_EV__
    gui_cancel_timer(mmi_vdorec_inc_ev);
    gui_cancel_timer(mmi_vdorec_dec_ev);
#endif /* __VDOREC_FEATURE_EV__ */

    if (g_vdorec_cntx.state == VDOREC_STATE_PREVIEW)
    {
        mdi_video_rec_preview_stop();
        g_vdorec_cntx.is_preview_started = MMI_FALSE;
    }
    else if (g_vdorec_cntx.state == VDOREC_STATE_PAUSE || g_vdorec_cntx.state == VDOREC_STATE_RECORD)
    {    
        mdi_video_rec_record_stop();
		#if defined(__VDOREC_FEATURE_SLIM_UE__) && defined(__VDOREC_FEATURE_PREVIEW_SAVED_FILE__)
		g_vdorec_cntx.is_enter_play_video_scr = TRUE;
		#endif
		//kal_prompt_trace(MOD_MMI_MEDIA_APP,"[VDOREC]exit end key = %d",g_vdorec_cntx.is_end_key);
		if(g_vdorec_cntx.is_end_key == MMI_TRUE)
		{
			g_vdorec_cntx.last_error = mdi_video_rec_save_file(g_vdorec_cntx.filepath, mmi_vdorec_save_result_hdlr_callback,NULL);
			g_vdorec_cntx.have_saved = MMI_TRUE;
			if (g_vdorec_cntx.last_error != 0)
        	{
            	mdi_video_rec_delete_unsaved_file(g_vdorec_cntx.storage_filepath);
				g_vdorec_cntx.have_saved = MMI_FALSE;
				//kal_prompt_trace(MOD_MMI_MEDIA_APP,"[VDOREC]exit end key1 = %d",g_vdorec_cntx.is_end_key);
        	}
			g_vdorec_cntx.is_end_key = MMI_FALSE;
			#if defined(__VDOREC_FEATURE_SLIM_UE__) && defined(__VDOREC_FEATURE_PREVIEW_SAVED_FILE__)
			g_vdorec_cntx.is_enter_play_video_scr = FALSE;
			#endif
		}
		//kal_prompt_trace(MOD_MMI_MEDIA_APP,"[VDOREC]has_unsaved_file = %d",2);
		if (g_vdorec_cntx.have_saved)
        {
           mdi_video_rec_stop_save();
		   //kal_prompt_trace(MOD_MMI_MEDIA_APP,"[VDOREC]has_unsaved_file = %d",3);
           g_vdorec_cntx.have_saved = MMI_FALSE;
        }
        g_vdorec_cntx.is_preview_started = MMI_FALSE;
    }

	g_vdorec_cntx.state = VDOREC_STATE_EXIT;

    mmi_vdorec_store_setting();

    mdi_video_rec_power_off();

    mmi_vdorec_turn_off_led_highlight();

    /*for we use base layer as preview layer handle, so we must reset and clear base layer image*/
    gdi_layer_get_base_handle(&base_layer_handle);
    gdi_layer_push_and_set_active(base_layer_handle);
    gdi_layer_set_rotate(GDI_LCD_LAYER_ROTATE_0);
    gdi_layer_resize(LCD_WIDTH, LCD_HEIGHT);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

    /*continue flatten*/
    //gdi_layer_flatten_previous_to_base();

    /* free layer */
	#ifdef __VDOREC_DOUBLE_BUFFER_SUPPORT__
    if (g_vdorec_cntx.is_gdi_double_buffer_enable)
    {
        #ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
        gdi_bltdb_disable();
        #endif
    }
	#endif

    /* free preview layers */
    if (g_vdorec_cntx.preview_layer_handle != 0)
    {
        mdi_util_hw_layer_free(g_vdorec_cntx.preview_layer_handle);
        g_vdorec_cntx.preview_layer_handle = 0;
    }

    /*release tmp layer handle*/
	#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
    if (g_vdorec_cntx.is_use_hw_rotate)
    {
        for (i = 0 ; i < g_vdorec_cntx.osd_layer_region_count ; i ++)
        {
            if (g_vdorec_cntx.tmp_osd_layer_region_handle[i] != GDI_LAYER_EMPTY_HANDLE)
            {
                gdi_layer_free(g_vdorec_cntx.tmp_osd_layer_region_handle[i]);
                g_vdorec_cntx.tmp_osd_layer_region_handle[i] = GDI_LAYER_EMPTY_HANDLE;
            }

            #ifdef __MMI_VIDEO_RECORDER_SLIM__
            if(g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[i] != NULL)
            {
                mmi_frm_scrmem_free(g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[i]);
            }
            #endif
            
            g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[i] = NULL;    
        }
    }
	#endif
    
#ifdef __VDOREC_FEATURE_SHOW_STATUS_BAR__
    wgui_status_icon_set_display_layer(g_vdorec_cntx.prev_status_bar_layer_handle);
    
    if (g_vdorec_cntx.status_bar_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_vdorec_cntx.status_bar_layer_handle);
        g_vdorec_cntx.status_bar_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }
#endif /* __VDOPLY_FEATURE_SHOW_STATUS_BAR__ */

	#ifndef __VDOREC_FEATURE_MULTI_REGION_SUPPORT__
    if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE)
    {
        if (g_vdorec_cntx.osd_layer_handle)
        {
            gdi_layer_free(g_vdorec_cntx.osd_layer_handle);
            mmi_frm_scrmem_free(g_vdorec_cntx.osd_layer_buf_ptr);
            g_vdorec_cntx.osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;
            g_vdorec_cntx.osd_layer_buf_ptr = NULL;
        }
    }
    #else
    {
        for (i = 0 ; i < g_vdorec_cntx.osd_layer_region_count ; i++)
        {
            if (g_vdorec_cntx.osd_layer_region_handle[i] != GDI_LAYER_EMPTY_HANDLE)
            {
                gdi_layer_free(g_vdorec_cntx.osd_layer_region_handle[i]);
                g_vdorec_cntx.osd_layer_region_handle[i] = GDI_LAYER_EMPTY_HANDLE;
                
                mmi_frm_scrmem_free(g_vdorec_cntx.osd_layer_region_handle_ptr[i]);

				#ifdef __MMI_VIDEO_RECORDER_SLIM__
				mmi_frm_scrmem_free(g_vdorec_cntx.osd_layer_region_handle_ptr2[i]);
				g_vdorec_cntx.osd_layer_region_handle_ptr2[i] = NULL;
				#endif
				
                g_vdorec_cntx.osd_layer_region_handle_ptr[i] = NULL;
            }
        }
    }
	#endif
   
#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__

    gdi_lcd_set_rotate(GDI_LAYER_ROTATE_0);

    gdi_layer_resize(UI_device_width, UI_device_height);

    /* clear in black layer if it is horizontal view */
    gdi_layer_clear(GDI_COLOR_BLACK);
    
#endif /* __VDOREC_FEATURE_HORIZONTAL_VIEW__ */ 

    /* restore rotate layer flag */
    gdi_lcd_set_rotate_by_layer(g_vdorec_cntx.prev_rotate_by_layer);

    /* disable multi layer */
    gdi_layer_multi_layer_disable();

    /* resume alignment timer */
    UI_disable_alignment_timers();

    /* resume LED patten */
    srv_gpio_play_pattern((srv_gpio_pattern_id_enum)srv_led_pattern_get_bg_pattern(), SRV_GPIO_PATN_PLAY_START);

    /* let MMI can sleep */
    srv_backlight_turn_off();

    /* resume background audio */
    mdi_audio_resume_background_play();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    mmi_fe_set_antialias(MMI_TRUE);
#endif

	gdi_lcd_set_te_ctrl((kal_bool)g_vdorec_cntx.old_tear_flag);

    /* free buffer */
    gui_free(g_vdorec_cntx.storage_filepath);
    g_vdorec_cntx.storage_filepath = NULL;

    /* exit sublcd */
#ifdef __MMI_SUBLCD__
    /* exit app screen if exist , and not exit because toggle self capture to sublcd */
    if (g_vdorec_cntx.is_sub_display)
    {
        GoBackSubLCDHistory();
        g_vdorec_cntx.is_sub_display = FALSE;
    }
#endif /* __MMI_SUBLCD__ */ 


#ifdef __MMI_BT_SUPPORT__
    mmi_bt_enable_receiving();   /* enable BT back ground receive. remember to resume when exit this screen */
#endif

	#ifndef __MMI_VIDEO_RECORDER_SLIM__
    if (g_vdorec_cntx.gdi_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(g_vdorec_cntx.gdi_layer_handle);
        g_vdorec_cntx.gdi_layer_handle = GDI_LAYER_EMPTY_HANDLE;
    }
	#endif

    #ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__
    if (!g_vdorec_cntx.setting.accept_call)
    {
        /* restore */
        srv_callset_blacklist_switch_mode(SRV_CALLSET_BLACKLIST_REJECT_ALL, g_vdorec_cntx.old_call_mode, NULL);
    }
    #endif /* __VDOREC_FEATURE_CALL_ACCEPT_OPTION__ */

#if defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) 
    mmi_frm_cb_dereg_event(EVT_ID_PRE_PROTOCOL, mmi_vdorec_clam_close_event_hdlr, NULL);
#endif /* defined(__MMI_CLAMSHELL__) && !defined(__MMI_SLIDE__) */

}




/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_record_timer_cyclic
 * DESCRIPTION
 *  record timer cyclic to get and draw timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_record_timer_cyclic(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 prev_time_in_sec;
    #ifdef __VDOREC_FEATURE_LIMIT_PROGRESS_BAR__
    U64 prev_progress;
    #endif
    U32 time_in_sec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_RECORD_TIMER_CYLIC, g_vdorec_cntx.is_timer_show);

	if (!g_vdorec_cntx.is_timer_show)
	{
		return;
	}

    prev_time_in_sec = (U32) (g_vdorec_cntx.record_time / 1000);

    mdi_video_rec_get_cur_record_time(&g_vdorec_cntx.record_time);
    time_in_sec = (U32) (g_vdorec_cntx.record_time / 1000);

    if ((time_in_sec > prev_time_in_sec) || (prev_time_in_sec == 0))
    {
        mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_TIMER);
        mmi_vdorec_blt_screen();
    }
    
	/*draw progress*/
    #ifdef __VDOREC_FEATURE_LIMIT_PROGRESS_BAR__
        if (mmi_vdorec_is_draw_progress_bar())
        {
            prev_progress = g_vdorec_cntx.progress;
            mmi_vdorec_update_progress_ratio();
            if (g_vdorec_cntx.progress > prev_progress)
            {
                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_PROGRESS);
                mmi_vdorec_blt_screen();
            }
         }
    #endif
    gui_start_timer(200, mmi_vdorec_record_timer_cyclic);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_save_result_hdlr_callback
 * DESCRIPTION
 *  callback function when save is done
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_save_result_hdlr_callback(MDI_RESULT result, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR buf_filepath[SRV_FMGR_PATH_BUFFER_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SAVE_RESULT_HDLR_CALLBACK, result);

    g_vdorec_cntx.is_saving = FALSE;
	g_vdorec_cntx.have_saved = MMI_FALSE;
	if(result < 0)
	{
		mmi_vdoply_get_storage_file_path(buf_filepath);
        mdi_video_rec_delete_unsaved_file(buf_filepath);
	}

    /* if video recorder is already removed from history , do not show popup */
    if (mmi_frm_scrn_get_state(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_APP) != MMI_SCENARIO_STATE_INACTIVE)
    {
        return;
    }

    if (g_vdorec_cntx.is_foward_to)
    {
    #if (defined(__VDOREC_FEATURE_MMS_SUPPORT__) || defined(__VDOREC_FEATURE_BT_SEND_SUPPORT__) || defined(__VDOREC_FEATURE_EMAIL_SUPPORT__)) && !defined(__VDOREC_FEATURE_DIRECT_SAVE__) && !defined(__VDOREC_FEATURE_SLIM_UE__)

        /* link to foward to */
        if (SCR_ID_VDOREC_SAVING == mmi_frm_scrn_get_active_id())
        {
            /* enter only not in call and wap not in call */
            if (result >= 0)
            {
                /* foward to MMS */
                mmi_vdorec_entry_send_screen();
                g_vdorec_cntx.is_foward_to = FALSE;
                mmi_frm_scrn_multiple_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVING, MMI_TRUE, 0, SCR_ID_VDOREC_APP, MMI_FALSE);
                return;
            }
            else if (result == MDI_RES_VDOREC_ERR_DISK_FULL)
            {
                mmi_vdorec_disply_popup(
                    FMGR_FS_DISK_FULL_TEXT,
                    MMI_EVENT_FAILURE,
                    MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
            }
            else
            {
                mmi_vdorec_disply_popup(
                    STR_GLOBAL_FAILED_TO_SAVE,
                    MMI_EVENT_FAILURE,
                    MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
            }

            mmi_frm_scrn_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVING);
            mmi_frm_scrn_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVE_CONFIRM);
            
            /* if clam is close, delete one more screen, avoid enter video recorder */
            if (srv_clam_is_close())
            {
                mmi_frm_group_close(g_vdorec_cntx.cur_gid);
            }

        }
        else
        {
            /*
             * when it is in MT, do nothing, will handle foward
             * to after back from MT 
             */

            mmi_frm_node_struct screen_struct;
            
            mmi_frm_node_info_init(&screen_struct);
            
            screen_struct.id = SCR_ID_VDOREC_SEND;
            screen_struct.entry_proc = (mmi_proc_func)mmi_vdorec_entry_send_screen;
            mmi_frm_scrn_insert(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVING, &screen_struct, MMI_FRM_NODE_AFTER_FLAG);
            mmi_frm_scrn_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVING);

            g_vdorec_cntx.save_result = result;
            g_vdorec_cntx.is_save_done_when_mt = FALSE;
            return;

        }

    #endif /* __VDOREC_FEATURE_MMS_SUPPORT__ */ 

    }
    else
    {
    	#ifndef __VDOREC_FEATURE_EXT_REQ_DISABLE__
        if (g_vdorec_cntx.is_ext_req)
        {
            //mmi_frm_scrn_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVING);
            
            if (SCR_ID_VDOREC_SAVING == mmi_frm_scrn_get_active_id())
            {
                /* enter only not in call and wap not in call */
                if (result >= 0)
                {
                    mmi_vdorec_post_to_parent(CUI_VDOREC_RECORD_EVENT_RESULT_SUCCESS, (CHAR *)g_vdorec_cntx.filepath);
                    return;
                }
                else if (result == MDI_RES_VDOREC_ERR_DISK_FULL)
                {
                    if (mmi_frm_group_is_present(g_vdorec_cntx.cur_gid))
                    {
                        mmi_vdorec_disply_popup(
                            FMGR_FS_DISK_FULL_TEXT,
                            MMI_EVENT_FAILURE,
                            MMI_VDOREC_POPUP_RESULT_PROCESS_DELETE_GROUP);
                        return;
                    }
                }
                else
                {
                    if (mmi_frm_group_is_present(g_vdorec_cntx.cur_gid))
                    {
                        mmi_vdorec_disply_popup(
                            STR_GLOBAL_FAILED_TO_SAVE,
                            MMI_EVENT_FAILURE,
                            MMI_VDOREC_POPUP_RESULT_PROCESS_DELETE_GROUP);
                        return;
                    }
                }
            }
            else
            {
                if (result >= 0)
                {
                    mmi_vdorec_post_to_parent(CUI_VDOREC_RECORD_EVENT_RESULT_SUCCESS, (CHAR *)g_vdorec_cntx.filepath);
                    return;
                }
            }

            /* not in saving screen */
            mmi_vdorec_post_to_parent(CUI_VDOREC_RECORD_EVENT_RESULT_FAILED, NULL);                       
            return;
        }
        else
		#endif	
        {
            /* Alarm playing */
            if (AlmIsTonePlaying())
                return;

            /* is in call, they have higher priority, do not show popup */
            if (SCR_ID_VDOREC_SAVING == mmi_frm_scrn_get_active_id())
            {
                /* enter only not in call and wap not in call */
                if (result >= 0)
                {
                #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif        
                #if defined(__VDOREC_FEATURE_PREVIEW_SAVED_FILE__) && defined(__MTK_TARGET__)
                    /* insert preview screen to Hisotry, so after popup, will return to preview screen */
                    /* don't care gui_buffer & input_buffer, since we won't handle it. */
                    //GenericExitScreen(SCR_ID_VDOREC_PREVIEW_OPTION, mmi_vdorec_entry_preview_video_screen);
                    {
                        mmi_frm_node_struct screen_struct;
                        
                        mmi_frm_node_info_init(&screen_struct);

                        screen_struct.id = SCR_ID_VDOREC_SAVED_PREVIEW;
                        screen_struct.entry_proc = (mmi_proc_func)mmi_vdorec_entry_preview_video_screen;
                        mmi_frm_scrn_insert(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_APP, &screen_struct, MMI_FRM_NODE_AFTER_FLAG);
                    }
                #endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */
                
                }
                else if (result == MDI_RES_VDOREC_ERR_DISK_FULL)
                {
                    mmi_vdorec_disply_popup(
                        FMGR_FS_DISK_FULL_TEXT,
                        MMI_EVENT_FAILURE,
                        MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
                }
                else
                {
                    mmi_vdorec_disply_popup(
                        STR_GLOBAL_FAILED_TO_SAVE,
                        MMI_EVENT_FAILURE,
                        MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
                }

                kal_sleep_task(100);    /* wait about 500ms when show saving, for user can see saving popup clearly */

                mmi_frm_scrn_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVING);
                #if !defined(__VDOREC_FEATURE_DIRECT_SAVE__) && !defined(__VDOREC_FEATURE_SLIM_UE__)
                    mmi_frm_scrn_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVE_CONFIRM);
                #endif
                /* if clam is close, delete one more screen, avoid enter video recorder */
                if (srv_clam_is_close())
                {
                    mmi_frm_group_close(g_vdorec_cntx.cur_gid); 
                }
            }
            else
            {
                mmi_frm_scrn_multiple_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVING, MMI_TRUE, 0, SCR_ID_VDOREC_APP, MMI_FALSE);
            }
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_exit_saving_screen
 * DESCRIPTION
 *  enter save screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_exit_saving_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_EXIT_SAVE_SCREEN);

    /* resume background play */
    mdi_audio_resume_background_play();
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_saving_leave_proc
* DESCRIPTION
*  saving screen leave proc
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static /*mmi_proc_func*/ mmi_ret mmi_vdorec_saving_leave_proc(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(event->evt_id)
    {
    case EVT_ID_SCRN_DELETE_REQ:
        if (g_vdorec_cntx.is_saving)
        {
            return MMI_RET_ERR;    /* if is saving, will not delete this screen from history */
        }
        else
        {
            return MMI_RET_OK;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_saving_screen
 * DESCRIPTION
 *  enter save screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_saving_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    CHAR buf_filepath[SRV_FMGR_PATH_BUFFER_SIZE];
    MMI_BOOL entry_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_SAVING_SCREEN);

#if (defined(__VDOREC_FEATURE_MMS_SUPPORT__) || defined(__VDOREC_FEATURE_BT_SEND_SUPPORT__) || defined(__VDOREC_FEATURE_EMAIL_SUPPORT__)) && !defined(__VDOREC_FEATURE_DIRECT_SAVE__) && !defined(__VDOREC_FEATURE_SLIM_UE__)
    if (g_vdorec_cntx.is_save_done_when_mt && g_vdorec_cntx.is_foward_to)
    {
        /* save done while in MT, when back from MT, will enter here */
        g_vdorec_cntx.is_save_done_when_mt = FALSE;

        if (g_vdorec_cntx.save_result >= 0)
        {
            mmi_frm_scrn_multiple_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVING, MMI_TRUE, 0, SCR_ID_VDOREC_APP, MMI_FALSE);
            return;
        }
        else if (g_vdorec_cntx.save_result == MDI_RES_VDOREC_ERR_DISK_FULL)
        {
            mmi_vdorec_disply_popup(
                FMGR_FS_DISK_FULL_TEXT,
                MMI_EVENT_FAILURE,
                MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
        }
        else
        {
            mmi_vdorec_disply_popup(
                STR_GLOBAL_FAILED_TO_SAVE,
                MMI_EVENT_FAILURE,
                MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
        }

        /* if clam is close, delete one more screen, avoid enter video recorder */
        if (srv_clam_is_close())
        {
            mmi_frm_group_close(g_vdorec_cntx.cur_gid);
        }

        return;
    }
#endif /* __VDOREC_FEATURE_MMS_SUPPORT__ */ 

    /* suspend background play */
    mdi_audio_suspend_background_play();

    entry_ret = mmi_frm_scrn_enter (g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVING, mmi_vdorec_exit_saving_screen, (FuncPtr)mmi_vdorec_entry_saving_screen, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }
        
    guiBuffer = mmi_frm_scrn_get_gui_buf(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVING);

    if ((guiBuffer != NULL))
    {
        if (!g_vdorec_cntx.is_saving)   
        {
            /* when in saving, some one interupt me, I have process the result, so just close the screen*/
            mmi_frm_scrn_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVING);
            return;
        }
    }
    else
    {
        g_vdorec_cntx.is_saving = TRUE;
    }
    mmi_frm_scrn_set_leave_proc(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVING, (mmi_proc_func)mmi_vdorec_saving_leave_proc);

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

	if(g_vdorec_cntx.is_show_saving)
	{
	  ShowCategory66Screen(
        CAT66_AREA_NONE,
        CAT66_AREA_NONE,
        0,
        0,
        0,
        0,
        (PU8) GetString(STR_GLOBAL_SAVING),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
	}
    if (!guiBuffer)
    {
        g_vdorec_cntx.last_error = mdi_video_rec_save_file(g_vdorec_cntx.filepath, mmi_vdorec_save_result_hdlr_callback,NULL);
		g_vdorec_cntx.have_saved = MMI_TRUE;
        if (mmi_vdorec_check_and_display_error_popup() == TRUE) /* TRUE means has error */
        {
            /* if has error, cant save, delete temp file */
            mdi_video_rec_delete_unsaved_file(buf_filepath);
            return;
        }
    }

    /* clear end key, this action cant be abort */
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
}



/*****************************************************************************
*
* Menu Screens
*
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_option_screen
 * DESCRIPTION
 *  entry option menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_option_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
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
#endif
#ifdef __TC01__
/* under construction !*/
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_OPTION_SCREEN);
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 
    g_vdorec_cntx.setting_menu_gid = cui_menu_create(
                                                g_vdorec_cntx.cur_gid, 
                                                CUI_MENU_SRC_TYPE_RESOURCE, 
                                                CUI_MENU_TYPE_FROM_RESOURCE, 
                                                MENU_ID_VDOREC_OPTION, 
                                                MMI_TRUE, 
                                                NULL);
    
#if defined(__CAMERA_OSD_HORIZONTAL__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
    cui_menu_set_rotate_screen(g_vdorec_cntx.setting_menu_gid, MMI_FRM_SCREEN_ROTATE_270);
#endif /* defined(__CAMERA_OSD_HORIZONTAL__) */ 
#ifdef __VDOREC_FEATURE_SWITCH_TO_CAMERA__

	#ifndef __VDOREC_FEATURE_EXT_REQ_DISABLE__
    if (g_vdorec_cntx.is_ext_req)
    {
        /* hide switch to cam */        
        cui_menu_set_item_hidden(g_vdorec_cntx.setting_menu_gid, MENU_ID_VDOREC_TO_CAMERA, MMI_TRUE);
    }
    else
	#endif	
    {
        cui_menu_set_item_hidden(g_vdorec_cntx.setting_menu_gid, MENU_ID_VDOREC_TO_CAMERA, MMI_FALSE);
    }
#endif /* __VDOREC_FEATURE_SWITCH_TO_CAMERA__ */

#ifdef __VDOREC_FEATURE_STORAGE__
    if (SRV_FMGR_PUBLIC_DRV == SRV_FMGR_CARD_DRV)
    {
        cui_menu_set_item_hidden(g_vdorec_cntx.setting_menu_gid, MENU_ID_VDOREC_STORAGE, MMI_TRUE);
    }
#endif

#ifdef __TC01__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    cui_menu_set_default_title_by_id(
        g_vdorec_cntx.setting_menu_gid,
        STR_GLOBAL_OPTIONS,
        GetRootTitleIcon(MENU_ID_VDOREC_APP));
    cui_menu_set_default_left_softkey_by_id(g_vdorec_cntx.setting_menu_gid, STR_GLOBAL_OK);
    cui_menu_set_default_right_softkey_by_id(g_vdorec_cntx.setting_menu_gid, STR_GLOBAL_BACK);
    cui_menu_run(g_vdorec_cntx.setting_menu_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_camcoder_setting_screen
 * DESCRIPTION
 *  entry camcoder setting screen (inline selection screen)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_camcoder_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if 0    
#ifdef __VDOREC_FEATURE_WB__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __VDOREC_FEATURE_WB_AUTO__
/* under construction !*/
#endif
#ifdef __VDOREC_FEATURE_WB_DAYLIGHT__
/* under construction !*/
#endif
#ifdef __VDOREC_FEATURE_WB_TUNGSTEN__
/* under construction !*/
#endif
#ifdef __VDOREC_FEATURE_WB_FLUORESCENT__
/* under construction !*/
#endif
#ifdef __VDOREC_FEATURE_WB_CLOUD__
/* under construction !*/
#endif
#ifdef __VDOREC_FEATURE_WB_INCANDESCENCE__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
#endif

#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
    static const cui_inline_item_caption_struct g_vdorec_il_led_highlight_cap ={STR_ID_VDOREC_LED_HIGHLIGHT};
    static const U16 g_vdorec_il_led_highlight_select_str[] =
        {
        #ifdef __VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__
        STR_ID_VDOREC_LED_HIGHLIGHT_OFF,
        STR_ID_VDOREC_LED_HIGHLIGHT_ON,
        #endif
        #ifdef __VDOREC_FEATURE_LED_HIGHLIGHT_7_COLOR__
        STR_ID_VDOREC_LED_HIGHLIGHT_OFF,
        STR_ID_VDOREC_LED_HIGHLIGHT_WHITE,
        STR_ID_VDOREC_LED_HIGHLIGHT_RED,
        STR_ID_VDOREC_LED_HIGHLIGHT_GREEN,
        STR_ID_VDOREC_LED_HIGHLIGHT_BLUE,
        STR_ID_VDOREC_LED_HIGHLIGHT_YELLOW,
        STR_ID_VDOREC_LED_HIGHLIGHT_PURPLE,
        STR_ID_VDOREC_LED_HIGHLIGHT_CYAN,
        #endif        
        };
    static const cui_inline_item_select_struct g_vdorec_il_led_highlight_select = 
    {
        sizeof(g_vdorec_il_led_highlight_select_str)/sizeof(U16), 0, (U16*)g_vdorec_il_led_highlight_select_str
    };
#endif 

#ifdef __VDOREC_FEATURE_EV__
    static const cui_inline_item_caption_struct g_vdorec_il_ev_cap ={STR_ID_VDOREC_EV};
    static const U16 g_vdorec_il_ev_select_str[] =
        {
        #ifdef __VDOREC_FEATURE_EV_4__
        STR_ID_VDOREC_EV_N4,
        #endif
        #ifdef __VDOREC_FEATURE_EV_3__
        STR_ID_VDOREC_EV_N3,
        #endif
        #ifdef __VDOREC_FEATURE_EV_2__
        STR_ID_VDOREC_EV_N2,
        #endif
        STR_ID_VDOREC_EV_N1,
        STR_ID_VDOREC_EV_0,
        STR_ID_VDOREC_EV_P1,
        #ifdef __VDOREC_FEATURE_EV_2__
        STR_ID_VDOREC_EV_P2,
        #endif
        #ifdef __VDOREC_FEATURE_EV_3__
        STR_ID_VDOREC_EV_P3,
        #endif
        #ifdef __VDOREC_FEATURE_EV_4__
        STR_ID_VDOREC_EV_P4,
        #endif
        };
    static const cui_inline_item_select_struct g_vdorec_il_ev_select = 
    {
        sizeof(g_vdorec_il_ev_select_str)/sizeof(U16), 0, (U16*)g_vdorec_il_ev_select_str
    };
#endif 

#ifdef __VDOREC_FEATURE_NIGHT__
static const cui_inline_item_caption_struct g_vdorec_il_night_cap ={STR_ID_VDOREC_NIGHT};
static const U16 g_vdorec_il_night_select_str[] =
    {
        STR_ID_VDOREC_NIGHT_OFF,
        STR_ID_VDOREC_NIGHT_ON,
    };
static const cui_inline_item_select_struct g_vdorec_il_night_select = 
{
    sizeof(g_vdorec_il_night_select_str)/sizeof(U16), 0, (U16*)g_vdorec_il_night_select_str
};
#endif 

#ifdef __VDOREC_FEATURE_BANDING__
static const cui_inline_item_caption_struct g_vdorec_il_banding_cap ={STR_ID_VDOREC_BANDING};
static const U16 g_vdorec_il_banding_select_str[] =
    {
    STR_ID_VDOREC_BANDING_50HZ,
    STR_ID_VDOREC_BANDING_60HZ,
    };
static const cui_inline_item_select_struct g_vdorec_il_banding_select = 
{
    sizeof(g_vdorec_il_banding_select_str)/sizeof(U16), 0, (U16*)g_vdorec_il_banding_select_str
};
#endif 


#ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__
static const cui_inline_item_caption_struct g_vdorec_il_accept_call_cap ={STR_ID_VDOREC_ACCEPT_CALL};
static const U16 g_vdorec_il_accept_call_select_str[] =
    {
    STR_ID_VDOREC_ACCEPT_CALL_OFF,
    STR_ID_VDOREC_ACCEPT_CALL_ON,
    };
static const cui_inline_item_select_struct g_vdorec_il_accept_call_select = 
{
    sizeof(g_vdorec_il_accept_call_select_str)/sizeof(U16), 0, (U16*)g_vdorec_il_accept_call_select_str
};
#endif /* __VDOREC_FEATURE_CALL_ACCEPT_OPTION__ */


#ifdef __VDOREC_FEATURE_MERGE_MENU__

    /* merge "Video Setting" items into "CamCoder Setting" */
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
static const cui_inline_item_caption_struct g_vdorec_il_video_size_cap ={STR_ID_VDOREC_VIDEO_SIZE};
static const U16 g_vdorec_il_video_size_select_str[] =
    {
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__
        STR_ID_VDOREC_VIDEO_SIZE_SQCIF,
#endif
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__
        STR_ID_VDOREC_VIDEO_SIZE_QQVGA,
#endif
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QCIF__
        STR_ID_VDOREC_VIDEO_SIZE_QCIF,
#endif
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QVGA__
        STR_ID_VDOREC_VIDEO_SIZE_QVGA,
#endif
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_CIF__
        STR_ID_VDOREC_VIDEO_SIZE_CIF,
#endif
    };
static const cui_inline_item_select_struct g_vdorec_il_video_size_select = 
{
    sizeof(g_vdorec_il_video_size_select_str)/sizeof(U16), 0, (U16*)g_vdorec_il_video_size_select_str
};
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_QTY__
    #if defined(__VDOREC_FEATURE_QVGA_RECORD_SUPPORT__)
    static const cui_inline_item_caption_struct g_vdorec_il_video_qty_cap ={STR_ID_VDOREC_VIDEO_QTY2};
    static const U16 g_vdorec_il_video_qty_select_str[] =
        {
#ifdef __VDOREC_FEATURE_VIDEO_QTY_LOW__
            STR_ID_VDOREC_VIDEO_QTY2_LOW,
#endif
#ifdef __VDOREC_FEATURE_VIDEO_QTY_NORMAL__
            STR_ID_VDOREC_VIDEO_QTY2_NORMAL,
#endif
#ifdef __VDOREC_FEATURE_VIDEO_QTY_HIGH__
            STR_ID_VDOREC_VIDEO_QTY2_HIGH,
#endif
#ifdef __VDOREC_FEATURE_VIDEO_QTY_FINE__
            STR_ID_VDOREC_VIDEO_QTY2_FINE,
#endif
        };
    static const cui_inline_item_select_struct g_vdorec_il_video_qty_select = 
    {
        sizeof(g_vdorec_il_video_qty_select_str)/sizeof(U16), 0, (U16*)g_vdorec_il_video_qty_select_str
    };
    #else
    static const cui_inline_item_caption_struct g_vdorec_il_video_qty_cap ={STR_ID_VDOREC_VIDEO_QTY};
    static const U16 g_vdorec_il_video_qty_select_str[] =
        {
#ifdef __VDOREC_FEATURE_VIDEO_QTY_LOW__
            STR_ID_VDOREC_VIDEO_QTY_LOW,
#endif
#ifdef __VDOREC_FEATURE_VIDEO_QTY_NORMAL__
            STR_ID_VDOREC_VIDEO_QTY_NORMAL,
#endif
#ifdef __VDOREC_FEATURE_VIDEO_QTY_HIGH__
            STR_ID_VDOREC_VIDEO_QTY_HIGH,
#endif
#ifdef __VDOREC_FEATURE_VIDEO_QTY_FINE__
            STR_ID_VDOREC_VIDEO_QTY_FINE,
#endif
        };
    static const cui_inline_item_select_struct g_vdorec_il_video_qty_select = 
    {
        sizeof(g_vdorec_il_video_qty_select_str)/sizeof(U16), 0, (U16*)g_vdorec_il_video_qty_select_str
    };
    #endif 
#endif 

#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
static const cui_inline_item_caption_struct g_vdorec_il_size_limit_cap ={STR_ID_VDOREC_SIZE_LIMIT};
static const U16 g_vdorec_il_size_limit_select_str[] =
    {
    STR_ID_VDOREC_SIZE_LIMIT_NO_LIMIT,
    STR_ID_VDOREC_SIZE_LIMIT_1,
    STR_ID_VDOREC_SIZE_LIMIT_2,
    STR_ID_VDOREC_SIZE_LIMIT_3,
    };
static const cui_inline_item_select_struct g_vdorec_il_size_limit_select = 
{
    sizeof(g_vdorec_il_size_limit_select_str)/sizeof(U16), 0, (U16*)g_vdorec_il_size_limit_select_str
};
#endif 

#ifdef __VDOREC_FEATURE_TIME_LIMIT__
static const cui_inline_item_caption_struct g_vdorec_il_time_limit_cap ={STR_ID_VDOREC_TIME_LIMIT};
static const U16 g_vdorec_il_time_limit_select_str[] =
    {
    STR_ID_VDOREC_TIME_LIMIT_NO_LIMIT,
    STR_ID_VDOREC_TIME_LIMIT_1,
    STR_ID_VDOREC_TIME_LIMIT_2,
    STR_ID_VDOREC_TIME_LIMIT_3,
    };
static const cui_inline_item_select_struct g_vdorec_il_time_limit_select = 
{
    sizeof(g_vdorec_il_time_limit_select_str)/sizeof(U16), 0, (U16*)g_vdorec_il_time_limit_select_str
};
#endif 

#ifdef __VDOREC_FEATURE_RECORD_AUD__
static const cui_inline_item_caption_struct g_vdorec_il_record_aud_cap ={STR_ID_VDOREC_RECORD_AUD};
static const U16 g_vdorec_il_record_aud_select_str[] =
    {
    STR_ID_VDOREC_RECORD_AUD_OFF,
    STR_ID_VDOREC_RECORD_AUD_ON,
    };
static const cui_inline_item_select_struct g_vdorec_il_record_aud_select = 
{
    sizeof(g_vdorec_il_record_aud_select_str)/sizeof(U16), 0, (U16*)g_vdorec_il_record_aud_select_str
};
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
static const cui_inline_item_caption_struct g_vdorec_il_video_format_cap ={STR_ID_VDOREC_VIDEO_FORMAT};
static const U16 g_vdorec_il_video_format_select_str[] =
    {
    STR_ID_VDOREC_VIDEO_FORMAT_3GP,
    STR_ID_VDOREC_VIDEO_FORMAT_MP4,
    };
static const cui_inline_item_select_struct g_vdorec_il_video_format_select = 
{
    sizeof(g_vdorec_il_video_format_select_str)/sizeof(U16), 0, (U16*)g_vdorec_il_video_format_select_str
};
#endif 

#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 

    static const cui_inline_set_item_struct g_mmi_vdorec_setting_comcorder_inline_item[] =
    {
#if 0    
#ifdef __VDOREC_FEATURE_WB__
/* under construction !*/
/* under construction !*/
#endif
#endif
#if defined(__VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__) || defined(__VDOREC_FEATURE_LED_HIGHLIGHT_7_COLOR__)
    {MMI_VDOREC_SETTING_CAMCORDER_IL_LED_HIGHLIGHT_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    0,  (void*)&g_vdorec_il_led_highlight_cap},
    {MMI_VDOREC_SETTING_CAMCORDER_IL_LED_HIGHLIGHT_SELECT,     CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,     0,  (void*)&g_vdorec_il_led_highlight_select},
#endif

#ifdef __VDOREC_FEATURE_EV__
    {MMI_VDOREC_SETTING_CAMCORDER_IL_EV_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    0,  (void*)&g_vdorec_il_ev_cap},
    {MMI_VDOREC_SETTING_CAMCORDER_IL_EV_SELECT,  CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,     0,  (void*)&g_vdorec_il_ev_select},
#endif 

#ifdef __VDOREC_FEATURE_NIGHT__
    {MMI_VDOREC_SETTING_CAMCORDER_IL_NIGHT_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    0,  (void*)&g_vdorec_il_night_cap},
    {MMI_VDOREC_SETTING_CAMCORDER_IL_NIGHT_SELECT,  CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,     0,  (void*)&g_vdorec_il_night_select},
#endif 

#ifdef __VDOREC_FEATURE_BANDING__
    {MMI_VDOREC_SETTING_CAMCORDER_IL_BANDING_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    0,  (void*)&g_vdorec_il_banding_cap},
    {MMI_VDOREC_SETTING_CAMCORDER_IL_BANDING_SELECT,  CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,     0,  (void*)&g_vdorec_il_banding_select},
#endif 

#ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__
    {MMI_VDOREC_SETTING_CAMCORDER_IL_CALL_ACCEPT_OPTION_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    0,  (void*)&g_vdorec_il_accept_call_cap},
    {MMI_VDOREC_SETTING_CAMCORDER_IL_CALL_ACCEPT_OPTION_SELECT,  CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,     0,  (void*)&g_vdorec_il_accept_call_select},
#endif

#ifdef __VDOREC_FEATURE_MERGE_MENU__
    /* merge "Video Setting" items into "CamCoder Setting" */
#ifdef __VDOREC_FEATURE_VIDEO_QTY__
    {MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_QTY_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    0,  (void*)&g_vdorec_il_video_qty_cap},
    {MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_QTY_SELECT,  CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,     0,  (void*)&g_vdorec_il_video_qty_select},
#endif 

#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    {MMI_VDOREC_SETTING_CAMCORDER_IL_SIZE_LIMIT_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    0,  (void*)&g_vdorec_il_size_limit_cap},
    {MMI_VDOREC_SETTING_CAMCORDER_IL_SIZE_LIMIT_SELECT,  CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,     0,  (void*)&g_vdorec_il_size_limit_select},
#endif 

#ifdef __VDOREC_FEATURE_TIME_LIMIT__
    {MMI_VDOREC_SETTING_CAMCORDER_IL_TIME_LIMIT_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    0,  (void*)&g_vdorec_il_time_limit_cap},
    {MMI_VDOREC_SETTING_CAMCORDER_IL_TIME_LIMIT_SELECT,  CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,     0,  (void*)&g_vdorec_il_time_limit_select},
#endif 

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    {MMI_VDOREC_SETTING_CAMCORDER_IL_RECORD_AUD_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    0,  (void*)&g_vdorec_il_record_aud_cap},
    {MMI_VDOREC_SETTING_CAMCORDER_IL_RECORD_AUD_SELECT,  CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,     0,  (void*)&g_vdorec_il_record_aud_select},
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
    {MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_FORMAT_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    0,  (void*)&g_vdorec_il_video_format_cap},
    {MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_FORMAT_SELECT,  CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,     0,  (void*)&g_vdorec_il_video_format_select},
#endif 
#endif /* __VDOREC_FEATURE_MERGE_MENU__ */     
    };

	
	#ifndef __MMI_VIDEO_RECORDER_SLIM__ //apply new inline cui
    static const cui_inline_item_softkey_struct softkey = 
    {
        {{STR_GLOBAL_SAVE, 0},
         {STR_GLOBAL_BACK, 0},   
         {0, IMG_GLOBAL_COMMON_CSK},}
    };
	#endif
    
    static const cui_inline_struct g_mmi_vdorec_setting_comcorder_inline = 
    {
        VDOREC_CAMCODER_SETTING_ITEM_COUNT * 2,
        STR_GLOBAL_SETTINGS,
        0,
        CUI_INLINE_SCREEN_DISABLE_DONE | CUI_INLINE_SCREEN_DEFAULT_TEXT,
		#ifndef __MMI_VIDEO_RECORDER_SLIM__ //apply new inline cui
        	&softkey,
    	#else
			NULL,
		#endif
        g_mmi_vdorec_setting_comcorder_inline_item
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_CAMCORDER_SETTING_SCREEN);
    
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 
    g_vdorec_cntx.setting_img_inline_gid = 0;
    g_vdorec_cntx.setting_camcorder_inline_gid = cui_inline_create(g_vdorec_cntx.cur_gid, &g_mmi_vdorec_setting_comcorder_inline);
#if 0
#ifdef __VDOREC_FEATURE_WB__
/* under construction !*/
#endif
#endif
#if defined(__VDOREC_FEATURE_LED_HIGHLIGHT_ON_OFF__) || defined(__VDOREC_FEATURE_LED_HIGHLIGHT_7_COLOR__)
    cui_inline_set_value(g_vdorec_cntx.setting_camcorder_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_LED_HIGHLIGHT_SELECT, (void*)g_vdorec_cntx.setting.led_highlight);
#endif
    
#ifdef __VDOREC_FEATURE_EV__
    cui_inline_set_value(g_vdorec_cntx.setting_camcorder_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_EV_SELECT, (void*)g_vdorec_cntx.setting.ev);
#endif 
    
#ifdef __VDOREC_FEATURE_NIGHT__
    cui_inline_set_value(g_vdorec_cntx.setting_camcorder_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_NIGHT_SELECT, (void*)g_vdorec_cntx.setting.night);
#endif 
    
#ifdef __VDOREC_FEATURE_BANDING__
    cui_inline_set_value(g_vdorec_cntx.setting_camcorder_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_BANDING_SELECT, (void*)g_vdorec_cntx.setting.banding);
#endif 

#ifdef __VDOREC_FEATURE_CALL_ACCEPT_OPTION__
    cui_inline_set_value(g_vdorec_cntx.setting_camcorder_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_CALL_ACCEPT_OPTION_SELECT, (void*)g_vdorec_cntx.setting.accept_call);
#endif

#ifdef __VDOREC_FEATURE_MERGE_MENU__
    /* merge "Video Setting" items into "CamCoder Setting" */
#ifdef __VDOREC_FEATURE_VIDEO_QTY__
    cui_inline_set_value(g_vdorec_cntx.setting_camcorder_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_QTY_SELECT, (void*)g_vdorec_cntx.setting.video_qty);
#endif 

#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    cui_inline_set_value(g_vdorec_cntx.setting_camcorder_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_SIZE_LIMIT_SELECT, (void*)g_vdorec_cntx.setting.size_limit);
#endif 

#ifdef __VDOREC_FEATURE_TIME_LIMIT__
    cui_inline_set_value(g_vdorec_cntx.setting_camcorder_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_TIME_LIMIT_SELECT, (void*)g_vdorec_cntx.setting.time_limit);
#endif 

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    cui_inline_set_value(g_vdorec_cntx.setting_camcorder_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_RECORD_AUD_SELECT, (void*)g_vdorec_cntx.setting.record_aud);
#endif 

#ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
    cui_inline_set_value(g_vdorec_cntx.setting_camcorder_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_FORMAT_SELECT, (void*)g_vdorec_cntx.setting.video_format);
#endif 
#endif /* __VDOREC_FEATURE_MERGE_MENU__ */     

	#ifndef __VDOREC_FEATURE_EXT_REQ_DISABLE__
    if (g_vdorec_cntx.is_ext_req)
    {
#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    cui_inline_delete_item(g_vdorec_cntx.setting_camcorder_inline_gid,MMI_VDOREC_SETTING_CAMCORDER_IL_SIZE_LIMIT_CAPTION);
    cui_inline_delete_item(g_vdorec_cntx.setting_camcorder_inline_gid,MMI_VDOREC_SETTING_CAMCORDER_IL_SIZE_LIMIT_SELECT);
#endif 

#ifdef __VDOREC_FEATURE_TIME_LIMIT__
    cui_inline_delete_item(g_vdorec_cntx.setting_camcorder_inline_gid,MMI_VDOREC_SETTING_CAMCORDER_IL_TIME_LIMIT_CAPTION);
    cui_inline_delete_item(g_vdorec_cntx.setting_camcorder_inline_gid,MMI_VDOREC_SETTING_CAMCORDER_IL_TIME_LIMIT_SELECT);
#endif 
    }
	#endif
	
    cui_inline_set_title(
        g_vdorec_cntx.setting_camcorder_inline_gid, 
        STR_ID_VDOREC_CAMCODER_SETTING, 
        GetRootTitleIcon(MENU_ID_VDOREC_APP));
    cui_inline_run(g_vdorec_cntx.setting_camcorder_inline_gid);
}



/*****************************************************************************
*
*  Save Screen
*
*****************************************************************************/

#if !defined(__VDOREC_FEATURE_DIRECT_SAVE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_save_confirm_no
 * DESCRIPTION
 *  enter save screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_save_confirm_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR buf_filepath[SRV_FMGR_PATH_BUFFER_SIZE];
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SAVE_CONFIRM_NO);

    /* delete unsaved file */
    mmi_vdoply_get_storage_file_path(buf_filepath);
    mdi_video_rec_delete_unsaved_file(buf_filepath);

    if (g_vdorec_cntx.is_ext_req && g_vdorec_cntx.is_use_ext_req_path)
    {
        /* use external path, do nothing */
    }
    else
    {
        /* the seq num is already increase, so if we dont want to save this file, decrease it */
        ReadValueSlim(NVRAM_VDOREC_FILENAME_SEQ_NO, &g_vdorec_cntx.filename_seq_no, DS_SHORT);

        if (g_vdorec_cntx.filename_seq_no > 1)
        {
            g_vdorec_cntx.filename_seq_no--;
        }
           
        WriteValueSlim(NVRAM_VDOREC_FILENAME_SEQ_NO, &g_vdorec_cntx.filename_seq_no, DS_SHORT);
    }

	#ifndef __VDOREC_FEATURE_EXT_REQ_DISABLE__
    if (g_vdorec_cntx.is_ext_req)
    {
#ifdef __VDOREC_FEATURE_BACK_TO_PREVIEW_SCREEN_IF_NOT_ADD__
        mmi_frm_scrn_close_active_id();
#else
        /* delete all video recorder screen */
        if (g_vdorec_cntx.is_ext_req)
        {
            mmi_vdorec_post_to_parent(CUI_VDOREC_RECORD_EVENT_RESULT_FAILED, NULL);
        }
        else
        {
            mmi_frm_scrn_close_active_id();
        }
#endif
    }
    else
	#endif	
    {
        mmi_frm_scrn_close_active_id();
    }
   
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_exit_save_confirm
* DESCRIPTION
*  exit save confirm
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_exit_save_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	#ifndef __MMI_WGUI_DISABLE_CSK__
    ResetCenterSoftkey();
	#endif
	
    if (g_vdorec_cntx.save_confirm_tone_id)
    {
        srv_prof_stop_tone(SRV_PROF_TONE_WARNING);
        g_vdorec_cntx.save_confirm_tone_id = SRV_PROF_TONE_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_save_confirm_screen
 * DESCRIPTION
 *  enter save confirm screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_save_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_send_support = MMI_FALSE;
    MMI_BOOL entry_ret;
    U8 *guiBuffer;
    U16 image_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_SAVE_CONFIRM_SCREEN);

	ClearInputEventHandler(MMI_DEVICE_KEY);
    
#ifdef __VDOREC_FEATURE_MMS_SUPPORT__
    if (mms_is_ready())
    {
        is_send_support = MMI_TRUE;
    }
    else
    {
        is_send_support = MMI_FALSE;
    }
#else
    is_send_support = MMI_FALSE;
#endif

    if (!is_send_support)
    {
    #ifdef __VDOREC_FEATURE_BT_SEND_SUPPORT__
        is_send_support = mmi_bt_is_to_display_bt_menu();
    #else
        is_send_support = MMI_FALSE;
    #endif
    }
    
    if (!is_send_support)
    {
    #ifdef __VDOREC_FEATURE_EMAIL_SUPPORT__
        is_send_support = (MMI_BOOL)mmi_email_is_email_can_forward();
    #else 
        is_send_support = MMI_FALSE;
    #endif
    }
    
#ifdef  __VDOREC_FEATURE_DIRECT_SAVE__
    is_send_support = MMI_FALSE;
#endif

#ifndef __VDOREC_FEATURE_EXT_REQ_DISABLE__
if (g_vdorec_cntx.is_ext_req)
{
    is_send_support = MMI_FALSE;
}
#endif

/* do some pre-work before use category*/

    image_id = mmi_get_event_based_image(MMI_EVENT_QUERY);
    g_vdorec_cntx.save_confirm_tone_id = mmi_get_event_based_sound(MMI_EVENT_QUERY);

    entry_ret = mmi_frm_scrn_enter (g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVE_CONFIRM, mmi_vdorec_exit_save_confirm, mmi_vdorec_entry_save_confirm_screen, MMI_FRM_UNKNOW_SCRN);
    mmi_frm_scrn_clear_attribute(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVE_CONFIRM, MMI_SCRN_ATTRIB_ADD_HISTORY);
    if (!entry_ret)
    {
        return;
    }

    guiBuffer = mmi_frm_scrn_get_gui_buf(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_SAVING);

#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif
    
        g_vdorec_cntx.is_foward_to = FALSE;
        g_vdorec_cntx.is_save_done_when_mt = FALSE;
        
#if (defined(__VDOREC_FEATURE_MMS_SUPPORT__) || defined(__VDOREC_FEATURE_BT_SEND_SUPPORT__) || defined(__VDOREC_FEATURE_EMAIL_SUPPORT__)) && !defined(__VDOREC_FEATURE_DIRECT_SAVE__) && !defined(__VDOREC_FEATURE_SLIM_UE__)        
        if (is_send_support)
        {
        	#ifndef __MMI_WGUI_DISABLE_CSK__
            EnableCenterSoftkey(0, IMG_ID_VDOREC_FORWARD_TO_MMS);
			#endif

            ShowCategory163Screen(
                get_string(STR_GLOBAL_YES), 
                get_image(IMG_GLOBAL_YES), 
                get_string(STR_GLOBAL_NO), 
                get_image(IMG_GLOBAL_NO), 
                get_string(STR_GLOBAL_SAVE_ASK), 
                image_id, 
                NULL);
            register_center_softkey_to_enter_key();
            SetCenterSoftkeyFunction((FuncPtr)mmi_vdorec_entry_saving_screen, KEY_EVENT_UP);
        }
        else
#endif        
        {
        	#ifndef __MMI_WGUI_DISABLE_CSK__
            EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
			#endif
			
            ShowCategory163Screen(
                get_string(STR_GLOBAL_YES), 
                get_image(IMG_GLOBAL_YES), 
                get_string(STR_GLOBAL_NO), 
                get_image(IMG_GLOBAL_NO), 
                get_string(STR_GLOBAL_SAVE_ASK), 
                image_id, 
                NULL);
			g_vdorec_cntx.is_show_saving = MMI_TRUE;
            SetCenterSoftkeyFunction((FuncPtr)mmi_vdorec_entry_saving_screen, KEY_EVENT_UP);
        }        

    if (!guiBuffer)
    {
        srv_prof_play_tone(g_vdorec_cntx.save_confirm_tone_id, NULL);
    }
	g_vdorec_cntx.is_show_saving = MMI_TRUE;

    SetRightSoftkeyFunction(mmi_vdorec_save_confirm_no, KEY_EVENT_UP);
    SetLeftSoftkeyFunction((FuncPtr)mmi_vdorec_entry_saving_screen, KEY_EVENT_UP);
}

#ifdef __VDOREC_FEATURE_SAVE_CONFIRM_FWTO__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_save_confirm_forward_to
 * DESCRIPTION
 *  forward to key pressed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_save_confirm_forward_to(void)
{
#if (defined(__VDOREC_FEATURE_MMS_SUPPORT__) || defined(__VDOREC_FEATURE_BT_SEND_SUPPORT__) || defined(__VDOREC_FEATURE_EMAIL_SUPPORT__)) && !defined(__VDOREC_FEATURE_DIRECT_SAVE__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SAVE_FORWARD_TO);

    g_vdorec_cntx.is_foward_to = TRUE;
	g_vdorec_cntx.is_show_saving = MMI_TRUE;
    mmi_vdorec_entry_saving_screen();
#endif /* defined(__VDOREC_FEATURE_MMS_SUPPORT__) && !defined(__VDOREC_FEATURE_DIRECT_SAVE__) */ 
}
#endif
#endif  /*__VDOREC_FEATURE_DIRECT_SAVE__*/



/*****************************************************************************
* FUNCTION
*  mmi_vdorec_hint_wb
* DESCRIPTION
*  wb hint
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __VDOREC_FEATURE_WB__
void mmi_vdorec_hint_wb(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HINT_WB);

    //memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_ucs2cpy(
        (CHAR*) hintData[index],
        (CHAR*) GetString((U16) (STR_ID_VDOREC_WB_START + support_wb_item[g_vdorec_cntx.setting.wb] + 1)));
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_set_wb_value
* DESCRIPTION
*  set wb value
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_set_wb_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SET_WB_VALUE);
#if 0
/* under construction !*/
#endif
    g_vdorec_cntx.setting.wb = (U16) GetCurrHiliteID();
    mmi_vdorec_store_setting();
    mmi_frm_scrn_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_VIDEO_WB);
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_entry_wb_screen
* DESCRIPTION
*  entry wb setting
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_entry_wb_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[32] = {0};
    MMI_BOOL entry_ret;
    U32 i;
    U8 *guiBuffer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_WB_SCREEN);

    entry_ret = mmi_frm_scrn_enter (g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_VIDEO_WB, NULL, mmi_vdorec_entry_wb_screen, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }

#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif
    
    guiBuffer = mmi_frm_scrn_get_gui_buf(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_VIDEO_WB);

    SetParentHandler(MENU_ID_VDOREC_WHITE_BALANCE);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

    for (i = 0 ; i < g_vdorec_cntx.wb_item; i++)
    {
        ItemList[i] = STR_ID_VDOREC_WB_START + support_wb_item[i] + 1;
    }

    ShowCategory11Screen(
        STR_ID_VDOREC_WB,
        GetRootTitleIcon(MENU_ID_VDOREC_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_vdorec_cntx.wb_item,
        ItemList,
        g_vdorec_cntx.setting.wb,
        guiBuffer);

    SetLeftSoftkeyFunction(mmi_vdorec_set_wb_value, KEY_EVENT_UP);
    ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_vdorec_set_wb_value, KEY_EVENT_UP);
    SetRightSoftkeyFunction((mmi_void_funcptr_type)mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}
#endif /* __VDOREC_FEATURE_WB__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_video_setting_screen
 * DESCRIPTION
 *  entry video setting screen (inline selection)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef __VDOREC_FEATURE_MERGE_MENU__
static void mmi_vdorec_entry_video_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    static const cui_inline_item_caption_struct g_vdorec_il_video_size_cap ={STR_ID_VDOREC_VIDEO_SIZE};
    static const U16 g_vdorec_il_video_size_select_str[] =
        {
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_SQCIF__
                STR_ID_VDOREC_VIDEO_SIZE_SQCIF,
#endif
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QQVGA__
                STR_ID_VDOREC_VIDEO_SIZE_QQVGA,
#endif
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QCIF__
                STR_ID_VDOREC_VIDEO_SIZE_QCIF,
#endif
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_QVGA__
                STR_ID_VDOREC_VIDEO_SIZE_QVGA,
#endif
#ifdef __VDOREC_FEATURE_VIDEO_SIZE_CIF__
                STR_ID_VDOREC_VIDEO_SIZE_CIF,
#endif
        };
    static const cui_inline_item_select_struct g_vdorec_il_video_size_select = 
    {
        sizeof(g_vdorec_il_video_size_select_str)/sizeof(U16), 0, (U16*)g_vdorec_il_video_size_select_str
    };
#endif 
    
#ifdef __VDOREC_FEATURE_VIDEO_QTY__
    #if defined(__VDOREC_FEATURE_QVGA_RECORD_SUPPORT__)
    static const cui_inline_item_caption_struct g_vdorec_il_video_qty_cap ={STR_ID_VDOREC_VIDEO_QTY2};
    static const U16 g_vdorec_il_video_qty_select_str[] =
        {
#ifdef __VDOREC_FEATURE_VIDEO_QTY_LOW__
                    STR_ID_VDOREC_VIDEO_QTY2_LOW,
#endif
#ifdef __VDOREC_FEATURE_VIDEO_QTY_NORMAL__
            STR_ID_VDOREC_VIDEO_QTY2_NORMAL,
#endif
#ifdef __VDOREC_FEATURE_VIDEO_QTY_HIGH__
            STR_ID_VDOREC_VIDEO_QTY2_HIGH,
#endif
#ifdef __VDOREC_FEATURE_VIDEO_QTY_FINE__
            STR_ID_VDOREC_VIDEO_QTY2_FINE,
#endif
        };
    static const cui_inline_item_select_struct g_vdorec_il_video_qty_select = 
    {
        sizeof(g_vdorec_il_video_qty_select_str)/sizeof(U16), 0, (U16*)g_vdorec_il_video_qty_select_str
    };
    #else
    static const cui_inline_item_caption_struct g_vdorec_il_video_qty_cap ={STR_ID_VDOREC_VIDEO_QTY};
    static const U16 g_vdorec_il_video_qty_select_str[] =
        {
#ifdef __VDOREC_FEATURE_VIDEO_QTY_LOW__
            STR_ID_VDOREC_VIDEO_QTY_LOW,
#endif
#ifdef __VDOREC_FEATURE_VIDEO_QTY_NORMAL__
            STR_ID_VDOREC_VIDEO_QTY_NORMAL,
#endif
#ifdef __VDOREC_FEATURE_VIDEO_QTY_HIGH__
            STR_ID_VDOREC_VIDEO_QTY_HIGH,
#endif
#ifdef __VDOREC_FEATURE_VIDEO_QTY_FINE__
            STR_ID_VDOREC_VIDEO_QTY_FINE,
#endif
        };
    static const cui_inline_item_select_struct g_vdorec_il_video_qty_select = 
    {
        sizeof(g_vdorec_il_video_qty_select_str)/sizeof(U16), 0, (U16*)g_vdorec_il_video_qty_select_str
    };
    #endif 
#endif 

    
        /* always use external limit when entry from external request */
    #ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    static const cui_inline_item_caption_struct g_vdorec_il_size_limit_cap ={STR_ID_VDOREC_SIZE_LIMIT};
    static const U16 g_vdorec_il_size_limit_select_str[] =
    {
        STR_ID_VDOREC_SIZE_LIMIT_NO_LIMIT,
        STR_ID_VDOREC_SIZE_LIMIT_1,
        STR_ID_VDOREC_SIZE_LIMIT_2,
        STR_ID_VDOREC_SIZE_LIMIT_3,
    };
    static const cui_inline_item_select_struct g_vdorec_il_size_limit_select = 
    {
        sizeof(g_vdorec_il_size_limit_select_str)/sizeof(U16), 0, (U16*)g_vdorec_il_size_limit_select_str
    };
    #endif 
    
    #ifdef __VDOREC_FEATURE_TIME_LIMIT__
    static const cui_inline_item_caption_struct g_vdorec_il_time_limit_cap ={STR_ID_VDOREC_TIME_LIMIT};
    static const U16 g_vdorec_il_time_limit_select_str[] =
        {
        STR_ID_VDOREC_TIME_LIMIT_NO_LIMIT,
        STR_ID_VDOREC_TIME_LIMIT_1,
        STR_ID_VDOREC_TIME_LIMIT_2,
        STR_ID_VDOREC_TIME_LIMIT_3,
        };
    static const cui_inline_item_select_struct g_vdorec_il_time_limit_select = 
    {
        sizeof(g_vdorec_il_time_limit_select_str)/sizeof(U16), 0, (U16*)g_vdorec_il_time_limit_select_str
    };
    #endif 
    
#ifdef __VDOREC_FEATURE_RECORD_AUD__
    static const cui_inline_item_caption_struct g_vdorec_il_record_aud_cap ={STR_ID_VDOREC_RECORD_AUD};
    static const U16 g_vdorec_il_record_aud_select_str[] =
        {
        STR_GLOBAL_OFF,
        STR_GLOBAL_ON,
        };
    static const cui_inline_item_select_struct g_vdorec_il_record_aud_select = 
    {
        sizeof(g_vdorec_il_record_aud_select_str)/sizeof(U16), 0, (U16*)g_vdorec_il_record_aud_select_str
    };
#endif 
    
    /*if qvga record support, will not display format, format is related with video quality*/
#ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
    static const cui_inline_item_caption_struct g_vdorec_il_video_format_cap ={STR_ID_VDOREC_VIDEO_FORMAT};
    static const U16 g_vdorec_il_video_format_select_str[] =
    {
        STR_ID_VDOREC_VIDEO_FORMAT_3GP,
        STR_ID_VDOREC_VIDEO_FORMAT_MP4,
    };
    static const cui_inline_item_select_struct g_vdorec_il_video_format_select = 
    {
        sizeof(g_vdorec_il_video_format_select_str)/sizeof(U16), 0, (U16*)g_vdorec_il_video_format_select_str
    };
#endif 

    static const cui_inline_set_item_struct g_mmi_vdorec_setting_image_inline_item[] =
    {
    #ifdef __VDOREC_FEATURE_VIDEO_SIZE__
        {MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_SIZE_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    0,  (void*)&g_vdorec_il_video_size_cap},
        {MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_SIZE_SELECT,     CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,     0,  (void*)&g_vdorec_il_video_size_select},
    #endif 
    
    #ifdef __VDOREC_FEATURE_VIDEO_QTY__
        {MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_QTY_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    0,  (void*)&g_vdorec_il_video_qty_cap},
        {MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_QTY_SELECT,     CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,     0,  (void*)&g_vdorec_il_video_qty_select},
    #endif 
    
    /* always use external limit when entry from external request */
    #ifdef __VDOREC_FEATURE_SIZE_LIMIT__
        {MMI_VDOREC_SETTING_CAMCORDER_IL_SIZE_LIMIT_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    0,  (void*)&g_vdorec_il_size_limit_cap},
        {MMI_VDOREC_SETTING_CAMCORDER_IL_SIZE_LIMIT_SELECT,     CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,     0,  (void*)&g_vdorec_il_size_limit_select},
    #endif 
    
    #ifdef __VDOREC_FEATURE_TIME_LIMIT__
        {MMI_VDOREC_SETTING_CAMCORDER_IL_TIME_LIMIT_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    0,  (void*)&g_vdorec_il_time_limit_cap},
        {MMI_VDOREC_SETTING_CAMCORDER_IL_TIME_LIMIT_SELECT,     CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,     0,  (void*)&g_vdorec_il_time_limit_select},
    #endif 
    
    #ifdef __VDOREC_FEATURE_RECORD_AUD__
        {MMI_VDOREC_SETTING_CAMCORDER_IL_RECORD_AUD_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    0,  (void*)&g_vdorec_il_record_aud_cap},
        {MMI_VDOREC_SETTING_CAMCORDER_IL_RECORD_AUD_SELECT,     CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,     0,  (void*)&g_vdorec_il_record_aud_select},
    #endif 
    
        /*if qvga record support, will not display format, format is related with video quality*/
    #ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
        {MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_FORMAT_CAPTION,    CUI_INLINE_ITEM_TYPE_CAPTION | CUI_INLINE_ITEM_LEFT_JUSTIFY,    0,  (void*)&g_vdorec_il_video_format_cap},
        {MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_FORMAT_SELECT,     CUI_INLINE_ITEM_TYPE_SELECT | CUI_INLINE_ITEM_CENTER_JUSTIFY,     0,  (void*)&g_vdorec_il_video_format_select},
    #endif 
    };

	#ifndef __MMI_VIDEO_RECORDER_SLIM__ //apply new inline cui
    static const cui_inline_item_softkey_struct softkey = 
    {
        {{STR_GLOBAL_SAVE, 0},
         {STR_GLOBAL_BACK, 0},   
         {0, IMG_GLOBAL_COMMON_CSK},}
    };
	#endif
    
    static const cui_inline_struct g_vdorec_setting_image_inline_screen = 
    {
        VDOREC_VIDEO_SETTING_ITEM_COUNT * 2,
        STR_GLOBAL_SETTINGS,
        0,
        CUI_INLINE_SCREEN_DISABLE_DONE | CUI_INLINE_SCREEN_DEFAULT_TEXT,
		#ifndef __MMI_VIDEO_RECORDER_SLIM__ //apply new inline cui
        	&softkey,
    	#else
			NULL,
		#endif        
        g_mmi_vdorec_setting_image_inline_item
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 
    g_vdorec_cntx.setting_camcorder_inline_gid = 0;
    g_vdorec_cntx.setting_img_inline_gid = cui_inline_create(g_vdorec_cntx.cur_gid, &g_vdorec_setting_image_inline_screen);
    #ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    cui_inline_set_value(g_vdorec_cntx.setting_img_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_SIZE_SELECT, (void*)g_vdorec_cntx.setting.video_size);
    #endif 
    
    #ifdef __VDOREC_FEATURE_VIDEO_QTY__
    cui_inline_set_value(g_vdorec_cntx.setting_img_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_QTY_SELECT, (void*)g_vdorec_cntx.setting.video_qty);
    #endif 
    
    /* always use external limit when entry from external request */
    #ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    cui_inline_set_value(g_vdorec_cntx.setting_img_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_SIZE_LIMIT_SELECT, (void*)g_vdorec_cntx.setting.size_limit);
    #endif 
    
    #ifdef __VDOREC_FEATURE_TIME_LIMIT__
    cui_inline_set_value(g_vdorec_cntx.setting_img_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_TIME_LIMIT_SELECT, (void*)g_vdorec_cntx.setting.time_limit);
    #endif 
    
    #ifdef __VDOREC_FEATURE_RECORD_AUD__
    cui_inline_set_value(g_vdorec_cntx.setting_img_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_RECORD_AUD_SELECT, (void*)g_vdorec_cntx.setting.record_aud);
    #endif 
    
        /*if qvga record support, will not display format, format is related with video quality*/
    #ifdef __VDOREC_FEATURE_VIDEO_FORMAT__
    cui_inline_set_value(g_vdorec_cntx.setting_img_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_FORMAT_SELECT, (void*)g_vdorec_cntx.setting.video_format);
    #endif 

	#ifndef __VDOREC_FEATURE_EXT_REQ_DISABLE__
    if(g_vdorec_cntx.is_ext_req)
    {
    /* always use external limit when entry from external request */
    #ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    cui_inline_delete_item(g_vdorec_cntx.setting_img_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_SIZE_LIMIT_CAPTION);
    cui_inline_delete_item(g_vdorec_cntx.setting_img_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_SIZE_LIMIT_SELECT);
    #endif 
    #ifdef __VDOREC_FEATURE_TIME_LIMIT__
    cui_inline_delete_item(g_vdorec_cntx.setting_img_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_TIME_LIMIT_CAPTION);
    cui_inline_delete_item(g_vdorec_cntx.setting_img_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_TIME_LIMIT_SELECT);
    #endif 
    }
	#endif

	#if defined(__VDOREC_FEATURE_QTY_TABLE_ENABLE__)
	cui_inline_delete_item(g_vdorec_cntx.setting_img_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_FORMAT_CAPTION);
    cui_inline_delete_item(g_vdorec_cntx.setting_img_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_FORMAT_SELECT);
	
	cui_inline_delete_item(g_vdorec_cntx.setting_img_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_SIZE_CAPTION);
    cui_inline_delete_item(g_vdorec_cntx.setting_img_inline_gid, MMI_VDOREC_SETTING_CAMCORDER_IL_VIDEO_SIZE_SELECT);
	#endif

    cui_inline_set_title(
        g_vdorec_cntx.setting_img_inline_gid, 
        STR_ID_VDOREC_VIDEO_SETTING, 
        GetRootTitleIcon(MENU_ID_VDOREC_APP));
    cui_inline_run(g_vdorec_cntx.setting_img_inline_gid);
}
#endif /* __VDOREC_FEATURE_MERGE_MENU__ */ 


#ifdef __VDOREC_FEATURE_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_hint_effect_setting
 * DESCRIPTION
 *  hint effect setting
 * PARAMETERS
 *  index       [IN]        
 *  a(?)        [IN]        Hilight index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_vdorec_hint_effect_setting(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HINT_EFFECT_SETTING);

    //memset((PS8) hintData[(index)], 0, sizeof(hintData[(index)]));
    mmi_ucs2cpy(
        (CHAR*) hintData[index],
        (CHAR*) GetString((U16) (STR_ID_VDOREC_EFFECT_START + support_wb_item[g_vdorec_cntx.setting.effect] + 1)));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_set_effect_setting_value
 * DESCRIPTION
 *  effect setting set value
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_set_effect_setting_value(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SET_EFFECT_SETTING_VALUE);
#if 0
/* under construction !*/
#endif
    g_vdorec_cntx.setting.effect = (U16) GetCurrHiliteID();
    mmi_vdorec_store_setting();
    mmi_frm_scrn_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_EFFECT_SETTING);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_effect_setting_screen
 * DESCRIPTION
 *  entry effect setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_effect_setting_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[16];
    U8 *gui_buffer;
    MMI_BOOL entry_ret;
	U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_EFFECT_SETTING_SCREEN);

    entry_ret = mmi_frm_scrn_enter (g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_EFFECT_SETTING, NULL, mmi_vdorec_entry_effect_setting_screen, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_gui_buf(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_EFFECT_SETTING);

    //nItems = GetNumOfChild(MENU_ID_VDOREC_EFFECT_SETTING);
    //GetSequenceStringIds(MENU_ID_VDOREC_EFFECT_SETTING, ItemList);
    SetParentHandler(MENU_ID_VDOREC_EFFECT_SETTING);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
    for (i = 0 ; i < g_vdorec_cntx.effect_count_item; i++)
    {
        ItemList[i] = STR_ID_VDOREC_EFFECT_START + support_effect_item[i] + 1;
    }

    /* rotate UI */
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    mmi_frm_screen_rotate(MMI_FRM_SCREEN_ROTATE_270);
#endif 

    ShowCategory11Screen(
        STR_ID_VDOREC_EFFECT_SETTING,
        GetRootTitleIcon(MENU_ID_VDOREC_APP),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        g_vdorec_cntx.effect_count_item,
        ItemList,
        g_vdorec_cntx.setting.effect,   /* current index */
        gui_buffer);

    SetLeftSoftkeyFunction(mmi_vdorec_set_effect_setting_value, KEY_EVENT_UP);
    ChangeCenterSoftkey(0,IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_vdorec_set_effect_setting_value, KEY_EVENT_UP);
    SetRightSoftkeyFunction((mmi_void_funcptr_type)mmi_frm_scrn_close_active_id, KEY_EVENT_UP);   
}
#endif /* __VDOREC_FEATURE_EFFECT__*/ 


#ifdef __VDOREC_FEATURE_RESTORE_DEFAULT__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_restore_default_confirm_yes
 * DESCRIPTION
 *  restore default confirm yes.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_restore_default_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_RESTORE_DEFAULT_CONFIRM_YES);

#if defined(__VDOREC_FEATURE_SLIM_UE__) && defined(__VDOREC_FEATURE_PREVIEW_SAVED_FILE__)
    g_vdorec_cntx.is_enter_play_video_scr = FALSE;
#endif

    /* restore default values */
    mmi_vdorec_restore_setting();
    
    /* restore storage vdoply part - storage */
    mmi_vdoply_set_storage((U16)SRV_FMGR_PUBLIC_DRV);
    mmi_vdoply_store_setting();

#if 0
/* under construction !*/
#endif
    mmi_frm_scrn_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_RESTORE_DEFAULT);
    mmi_frm_scrn_close(g_vdorec_cntx.cur_gid, SCR_ID_VDOREC_OPTION);
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_restore_confirm_cb
* DESCRIPTION
*  restore confirm callback
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static mmi_ret mmi_vdorec_restore_confirm_cb(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            mmi_vdorec_entry_restore_default_confirm_yes();
            break;
        case MMI_ALERT_CNFM_NO:
            mmi_frm_scrn_close_active_id();
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_restore_default_confirm_screen
 * DESCRIPTION
 *  entry restore default confirm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_restore_default_confirm_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;   
    #ifndef __VDOREC_FEATURE_SLIM_UE__
    CHAR buf_filepath[SRV_FMGR_PATH_BUFFER_SIZE];
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_RESTORE_DEFAULT_CONFIRM_SCREEN);

#ifndef __VDOREC_FEATURE_SLIM_UE__
    /* check current storage have unsaved file or not */
    mmi_vdoply_get_storage_file_path(buf_filepath);
    if (mdi_video_rec_has_unsaved_file(buf_filepath))
    {
        mmi_vdorec_disply_popup(
            STR_ID_VDOREC_NOTIFY_PLZ_SAVE_FIRST,
            MMI_EVENT_INFO,
            MMI_VDOREC_POPUP_RESULT_PROCESS_NONE);
        return;
    }
#endif /*__VDOREC_FEATURE_SLIM_UE__*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.callback = (mmi_proc_func)mmi_vdorec_restore_confirm_cb;
    arg.parent_id = g_vdorec_cntx.cur_gid;
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) && defined(__MMI_SCREEN_ROTATE__)
    arg.rotation = MMI_FRM_SCREEN_ROTATE_270;
#endif
    mmi_confirm_display((WCHAR *)((UI_string_type)get_string(STR_ID_VDOREC_NOTIFY_RESTORE_DEFAULT_CONFIRM)), MMI_EVENT_QUERY, &arg);
}

#endif  /*__VDOREC_FEATURE_RESTORE_DEFAULT__*/


/*****************************************************************************
*
*  Touch Screen Support
*
*****************************************************************************/

/*****************************************************************************
* FUNCTION
*  mmi_vdorec_touch_feedback_action
* DESCRIPTION
*  touch feedback
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_vdorec_touch_feedback_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vdorec_cntx.state == VDOREC_STATE_PREVIEW)
    {
        gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_touch_scr_pen_down_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen down
 * PARAMETERS
 *  pos     [IN]        Pen down position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_touch_scr_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)
    S32 tmp_x;
    S32 tmp_y;
#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_TOUCH_SCR_PEN_DOWN_HDLR);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
    }

#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)

    /* cord tranfrom, since already rotate */
    tmp_x = pos.x;
    tmp_y = pos.y;
    pos.x = tmp_y;
    pos.y = (UI_device_width - 1) - tmp_x;

#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 

#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
    if (g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_PLAY ||
         g_vdorec_cntx.state == VDOREC_STATE_VIDEO_PREVIEW_STOP)
    {
        /* cancel idle timer */
        mmi_vdorec_preview_idle_timeout_cancel();
        
        if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_del))
        {
            mmi_vdorec_touch_feedback_action();
            g_vdorec_cntx.touch_del.is_press = TRUE;
            mmi_vdorec_del_key_press_hdlr();
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_DEL;
            return;
        }
        /* bypass EV/Zoom in video preview mode */
    #ifdef __VDOREC_FEATURE_EV__ 
        if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ev_inc) ||
            mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ev_dec))
        {
            return;
        }
    #endif /* __VDOREC_FEATURE_EV__ */
    #ifdef __VDOREC_FEATURE_ZOOM__
        if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_zoom_inc) ||
            mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_zoom_dec))
        {
            return;
        }
    #endif /* __VDOREC_FEATURE_ZOOM__ */
    }
#endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */


#ifdef __VDOREC_FEATURE_EV__ 
    /* ev inc */
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ev_inc))
    {
        if (g_vdorec_cntx.setting.ev >= VDOREC_SETTING_EV_COUNT - 1)
        {
            return;
        }

        mmi_vdorec_touch_feedback_action();
        g_vdorec_cntx.touch_ev_inc.is_press = TRUE;
        g_vdorec_cntx.is_first_time_ev = TRUE;
        mmi_vdorec_inc_ev();

        g_vdorec_cntx.touch_object = VDOREC_TOUCH_EV_INC;
        return;
    }

    /* ev dec */
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ev_dec))
    {
        if (g_vdorec_cntx.setting.ev == 0)
        {
            return;
        }

        mmi_vdorec_touch_feedback_action();
        g_vdorec_cntx.touch_ev_dec.is_press = TRUE;
        g_vdorec_cntx.is_first_time_ev = TRUE;
        mmi_vdorec_dec_ev();

        g_vdorec_cntx.touch_object = VDOREC_TOUCH_EV_DEC;
        return;
    }
#endif /* __VDOREC_FEATURE_EV__ */   


#ifdef __VDOREC_FEATURE_ZOOM__  
    /* zoom inc */
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_zoom_inc))
    {
        mmi_vdorec_touch_feedback_action();
        g_vdorec_cntx.touch_zoom_inc.is_press = TRUE;
        g_vdorec_cntx.is_first_time_zoom = TRUE;
        mmi_vdorec_start_zoom((void*)TRUE);
        g_vdorec_cntx.touch_object = VDOREC_TOUCH_ZOOM_INC;
        return;
    }

    /* zoom dec */
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_zoom_dec))
    {
        mmi_vdorec_touch_feedback_action();
        g_vdorec_cntx.touch_zoom_dec.is_press = TRUE;

        mmi_vdorec_start_zoom((void*)FALSE);
        g_vdorec_cntx.is_first_time_zoom = TRUE;
        g_vdorec_cntx.touch_object = VDOREC_TOUCH_ZOOM_DEC;
        return;
    }
#endif /* __VDOREC_FEATURE_ZOOM__ */

    /* rsk */
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_rsk))
    {
        mmi_vdorec_touch_feedback_action();
        mmi_vdorec_rsk_press_hdlr();

        {
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_RSK;
        }
        return;
    }

    /* lsk */
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_lsk))
    {
        mmi_vdorec_touch_feedback_action();
        mmi_vdorec_lsk_press_hdlr();
        g_vdorec_cntx.touch_object = VDOREC_TOUCH_LSK;
        return;
    }

    /* ck */
    if (mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ck))
    {
        {
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_CK;
        }
        mmi_vdorec_ck_press_hdlr();
        
        return;
    }

#if 0
#ifndef __VDOREC_FEATURE_SLIM_UE__
/* under construction !*/
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
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
#ifdef __VDOREC_FEATURE_VIDEO_QTY__
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
#ifdef __VDOREC_FEATURE_NIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_WB__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_RECORD_AUD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
/* under construction !*/
#ifdef __VDOREC_FEATURE_TIME_LIMIT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif  /*__VDOREC_FEATURE_SLIM_UE__*/
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_touch_scr_pen_up_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen up
 * PARAMETERS
 *  pos     [IN]        Pen up position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_touch_scr_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_TOUCH_PEN_UP_HDLR);

    if (g_vdorec_cntx.is_watchdog_support)
    {
        mmi_vdorec_reset_watchdog_time_out_handler();
        mmi_vdorec_watchdog_time_out_handler();
    }

    if (g_vdorec_cntx.touch_object == VDOREC_TOUCH_NONE)
    {
        return;
    }

    switch (g_vdorec_cntx.touch_object)
    {
        case VDOREC_TOUCH_EV_INC:
        #ifdef __VDOREC_FEATURE_EV__            
            g_vdorec_cntx.touch_ev_inc.is_press = FALSE;
            g_vdorec_cntx.is_ev_inc_key_pressed = FALSE;

            gui_cancel_timer(mmi_vdorec_inc_ev);

            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_EV);
            mmi_vdorec_blt_screen();
        #endif /* __VDOREC_FEATURE_EV__ */
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;

        case VDOREC_TOUCH_EV_DEC:
        #ifdef __VDOREC_FEATURE_EV__              
            g_vdorec_cntx.touch_ev_dec.is_press = FALSE;
            g_vdorec_cntx.is_ev_dec_key_pressed = FALSE;

            gui_cancel_timer(mmi_vdorec_dec_ev);

            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_EV);
            mmi_vdorec_blt_screen();
        #endif /* __VDOREC_FEATURE_EV__ */            
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;

        case VDOREC_TOUCH_ZOOM_INC:
        #ifdef __VDOREC_FEATURE_ZOOM__            
            g_vdorec_cntx.touch_zoom_inc.is_press = FALSE;
            g_vdorec_cntx.is_zoom_in_key_pressed = FALSE;

            mmi_vdorec_stop_fast_zoom();
            gui_cancel_timer(mmi_vdorec_draw_zoom_osd);
            gui_cancel_timer((FuncPtr)mmi_vdorec_start_fast_zoom);
        
            gui_cancel_timer((FuncPtr)mmi_vdorec_start_zoom);
            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM);
            mmi_vdorec_blt_screen();
        #endif /* __VDOREC_FEATURE_ZOOM__ */
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;

        case VDOREC_TOUCH_ZOOM_DEC:
        #ifdef __VDOREC_FEATURE_ZOOM__                    
            g_vdorec_cntx.touch_zoom_dec.is_press = FALSE;
            g_vdorec_cntx.is_zoom_out_key_pressed = FALSE;

            mmi_vdorec_stop_fast_zoom();
            gui_cancel_timer(mmi_vdorec_draw_zoom_osd);
            gui_cancel_timer((FuncPtr)mmi_vdorec_start_fast_zoom);
        
            gui_cancel_timer((FuncPtr)mmi_vdorec_start_zoom);
            mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM);
            mmi_vdorec_blt_screen();
        #endif /* __VDOREC_FEATURE_ZOOM__ */        
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;

        case VDOREC_TOUCH_RSK:
            mmi_vdorec_rsk_release_hdlr();
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;

        case VDOREC_TOUCH_LSK:
            mmi_vdorec_lsk_release_hdlr();
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;

        case VDOREC_TOUCH_CK:
            mmi_vdorec_ck_release_hdlr();
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;
            
    #ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
        case VDOREC_TOUCH_DEL:
            g_vdorec_cntx.touch_del.is_press = FALSE;
            mmi_vdorec_del_key_release_hdlr();
            g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            break;
    #endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_touch_scr_pen_move_hdlr
 * DESCRIPTION
 *  touch screen hdlr when pen move
 * PARAMETERS
 *  pos     [IN]        Pen move position
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_touch_scr_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)
    S32 tmp_x;
    S32 tmp_y;
#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_TOUCH_SCR_PEN_MOVE);

    if (g_vdorec_cntx.touch_object == VDOREC_TOUCH_NONE)
    {
        return;
    }

#if defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__)

    /* cord tranfrom, since already rotate */
    tmp_x = pos.x;
    tmp_y = pos.y;
    pos.x = tmp_y;
    pos.y = (UI_device_width - 1) - tmp_x;

#endif /* defined(__VDOREC_FEATURE_HORIZONTAL_VIEW__) */ 

    switch (g_vdorec_cntx.touch_object)
    {
        case VDOREC_TOUCH_EV_INC:
        #ifdef __VDOREC_FEATURE_EV__             
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ev_inc))
            {
                /* if move out */
                g_vdorec_cntx.touch_ev_inc.is_press = FALSE;
                g_vdorec_cntx.is_ev_inc_key_pressed = FALSE;

                gui_cancel_timer(mmi_vdorec_inc_ev);

                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_EV);
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
        #endif /* __VDOREC_FEATURE_EV__ */                 
            break;

        case VDOREC_TOUCH_EV_DEC:
        #ifdef __VDOREC_FEATURE_EV__             
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ev_dec))
            {
                /* if move out */
                g_vdorec_cntx.touch_ev_dec.is_press = FALSE;
                g_vdorec_cntx.is_ev_dec_key_pressed = FALSE;

                gui_cancel_timer(mmi_vdorec_dec_ev);

                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_EV);
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
        #endif /* __VDOREC_FEATURE_EV__ */                 
            break;

        case VDOREC_TOUCH_ZOOM_INC:
        #ifdef __VDOREC_FEATURE_ZOOM__            
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_zoom_inc))
            {
                /* if move out */
                g_vdorec_cntx.touch_zoom_inc.is_press = FALSE;
                g_vdorec_cntx.is_zoom_in_key_pressed = FALSE;

                if (g_vdorec_cntx.is_fast_zoom_support)
                {
                    mmi_vdorec_stop_fast_zoom();
                    gui_cancel_timer(mmi_vdorec_draw_zoom_osd);
                    gui_cancel_timer((FuncPtr)mmi_vdorec_start_fast_zoom);
                }

                gui_cancel_timer((FuncPtr)mmi_vdorec_start_zoom);
                
                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM);
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
        #endif /* __VDOREC_FEATURE_ZOOM__ */      
            break;

        case VDOREC_TOUCH_ZOOM_DEC:
        #ifdef __VDOREC_FEATURE_ZOOM__            
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_zoom_dec))
            {
                /* if move out */
                g_vdorec_cntx.touch_zoom_dec.is_press = FALSE;
                g_vdorec_cntx.is_zoom_out_key_pressed = FALSE;

                if (g_vdorec_cntx.is_fast_zoom_support)
                {
                    mmi_vdorec_stop_fast_zoom();
                    gui_cancel_timer(mmi_vdorec_draw_zoom_osd);
                    gui_cancel_timer((FuncPtr)mmi_vdorec_start_fast_zoom);
                }
                
                gui_cancel_timer((FuncPtr)mmi_vdorec_start_zoom);
                
                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM);
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
        #endif /* __VDOREC_FEATURE_ZOOM__ */                  
            break;

        case VDOREC_TOUCH_RSK:
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_rsk))
            {
                /* if move out */
                g_vdorec_cntx.is_rsk_pressed = FALSE;

                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
            break;

        case VDOREC_TOUCH_LSK:
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_lsk))
            {
                /* if move out */
                g_vdorec_cntx.is_lsk_pressed = FALSE;

                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
            break;

        case VDOREC_TOUCH_CK:
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_ck))
            {
                /* if move out */
                g_vdorec_cntx.is_ck_pressed = FALSE;

                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
            break;

        #ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
            case VDOREC_TOUCH_DEL:
            if (!mmi_vdorec_touch_scr_hit_test(pos.x, pos.y, &g_vdorec_cntx.touch_del))
            {
                /* if move out */
                g_vdorec_cntx.touch_del.is_press= FALSE;
                g_vdorec_cntx.is_del_key_pressed = FALSE;

                mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_SOFTKEY);
                mmi_vdorec_blt_screen();

                g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;
            }
            break;
        #endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_touch_scr_hit_test
 * DESCRIPTION
 *  test if is within touch region
 * PARAMETERS
 *  pos_x           [IN]        Position x
 *  pos_y           [IN]        Position y
 *  touch_obj       [?]         
 *  touch(?)        [IN]        Touch object structure
 * RETURNS
 * BOOL
 *****************************************************************************/
static BOOL mmi_vdorec_touch_scr_hit_test(S32 pos_x, S32 pos_y, vdorec_ui_touch_struct *touch_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_TOUCH_SCR_HIT_TEST);

    if ((pos_x >= touch_obj->offset_x) &&
        (pos_x < touch_obj->offset_x + touch_obj->width) &&
        (pos_y >= touch_obj->offset_y) && (pos_y < touch_obj->offset_y + touch_obj->height))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }

}
#endif /* defined(__VDOREC_FEATURE_TOUCH_SCREEN__) && defined(__MMI_TOUCH_SCREEN__) */ /* __VDOREC_FEATURE_TOUCH_SCREEN__ & __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_sublcd_icon
 * DESCRIPTION
 *  draw a sublcd icon.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void mmi_vdorec_draw_sublcd_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    S32 lcd_width;
    S32 lcd_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_SUBLCD_ICON);

    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_lcd_get_dimension(&lcd_width, &lcd_height);

    gdi_layer_reset_clip();

    gdi_layer_clear_background(GDI_COLOR_WHITE);
    gdi_image_get_dimension_id(IMG_ID_VDOREC_SUBLCD_ICON, &image_width, &image_height);
    gdi_image_draw_id((lcd_width - image_width) >> 1, (lcd_height - image_height) >> 1, IMG_ID_VDOREC_SUBLCD_ICON);
    gdi_layer_blt_base_layer(0, 0, lcd_width - 1, lcd_height - 1);

    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_entry_sublcd_screen
 * DESCRIPTION
 *  entry sublcd screen, if still remain on standard MMI sublcd screen, time update will
 *  redraw sublcd while mainlcd is previewing, will cause driver assert.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_entry_sublcd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_ENTRY_SUBLCD_SCREEN);

    ExecSubLCDCurrExitHandler();
    ShowCategory331Screen();
    SetSubLCDExitHandler(mmi_vdorec_exit_sublcd_screen);

    /* draw a icon on sub */
    mmi_vdorec_draw_sublcd_icon();

    g_vdorec_cntx.is_sub_display = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_exit_sublcd_screen
 * DESCRIPTION
 *  exit sublcd screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_exit_sublcd_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode SubLCDHistory;

    /* someone may exit/draw sublcd first then exit mainlcd, this may cause driver assert */
    /* also stop preview here */

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_EXIT_SUBLCD_SCREEN);

    if (g_vdorec_cntx.state == VDOREC_STATE_PREVIEW)
    {
        mdi_video_rec_preview_stop();
        g_vdorec_cntx.is_preview_started = MMI_FALSE;
    }
    else if (g_vdorec_cntx.state == VDOREC_STATE_PAUSE || g_vdorec_cntx.state == VDOREC_STATE_RECORD)
    {
        mdi_video_rec_record_stop();
        mdi_video_rec_preview_stop();
        g_vdorec_cntx.is_preview_started = MMI_FALSE;
    }

    g_vdorec_cntx.state = VDOREC_STATE_EXIT;

    /* exit sub */
    g_vdorec_cntx.is_sub_display = FALSE;

    SubLCDHistory.entryFuncPtr = mmi_vdorec_entry_sublcd_screen;
    AddSubLCDHistory(&SubLCDHistory);
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_draw_zoom_osd
* DESCRIPTION
*  draw zoom osd
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_draw_zoom_osd(void)
{
#ifdef __VDOREC_FEATURE_FAST_ZOOM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_ZOOM_OSD);

    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_ZOOM);
    mmi_vdorec_blt_screen();
    
    if (g_vdorec_cntx.is_fast_zoom)
    {
        gui_start_timer(VDOREC_INC_INTERVAL_FIRST, mmi_vdorec_draw_zoom_osd);
    }
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_vdorec_clear_zoom
* DESCRIPTION
*  clear zoom icon
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_clear_zoom(void)
{
#ifndef __MMI_VIDEO_RECORDER_SLIM__

#ifdef __VDOREC_FEATURE_ZOOM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;
    S32 layer_offset_x;
    S32 layer_offset_y;
    S32 offset_x1, offset_y1, offset_x2, offset_y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    gdi_layer_push_and_set_active(g_vdorec_cntx.ev_draw_layer);
    
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

#ifndef __VDOREC_FEATURE_SLIM_UE__
    // clear zoom head
    gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_ZOOM_HEAD, &image_width, &image_height);
    
    offset_x1 = g_vdorec_osd_cntx.panel.zoom.offset_x - layer_offset_x;
    offset_y1 = g_vdorec_osd_cntx.panel.zoom.offset_y - layer_offset_y;
    offset_x2 = g_vdorec_osd_cntx.panel.zoom.offset_x + image_width - layer_offset_x;
    offset_y2 = g_vdorec_osd_cntx.panel.zoom.offset_y + image_height - layer_offset_y;
    
    gdi_draw_solid_rect(offset_x1, offset_y1, offset_x2, offset_y2, GDI_COLOR_TRANSPARENT);

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_osd_cntx.panel.zoom.offset_x, 
            g_vdorec_osd_cntx.panel.zoom.offset_y, 
            image_width, 
            image_height);
    }
	#endif

    // clear digit
    gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_ZOOM_HEAD, &image_width, &image_height);
    
    offset_x1 = g_vdorec_osd_cntx.panel.zoom.offset_x - layer_offset_x;
    offset_y1 = g_vdorec_osd_cntx.panel.zoom.offset_y - layer_offset_y;
    offset_x2 = g_vdorec_osd_cntx.panel.zoom_inc.offset_x + image_width - layer_offset_x;
    offset_y2 = g_vdorec_osd_cntx.panel.zoom_inc.offset_y + image_height - layer_offset_y;
    
    gdi_draw_solid_rect(offset_x1, offset_y1, offset_x2, offset_y2, GDI_COLOR_TRANSPARENT);

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_osd_cntx.panel.zoom_dec.offset_x, 
            g_vdorec_osd_cntx.panel.zoom_dec.offset_y, 
            image_width, 
            image_height);
    }
	#endif
#endif  /*__VDOREC_FEATURE_SLIM_UE__*/
    
    // clear zoom inc
    gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC, &image_width, &image_height);
    
    offset_x1 = g_vdorec_osd_cntx.panel.zoom_inc.offset_x - layer_offset_x;
    offset_y1 = g_vdorec_osd_cntx.panel.zoom_inc.offset_y - layer_offset_y;
    offset_x2 = g_vdorec_osd_cntx.panel.zoom_inc.offset_x + image_width - layer_offset_x;
    offset_y2 = g_vdorec_osd_cntx.panel.zoom_inc.offset_y + image_height - layer_offset_y;
    
    gdi_draw_solid_rect(offset_x1, offset_y1, offset_x2, offset_y2, GDI_COLOR_TRANSPARENT);

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_osd_cntx.panel.zoom_inc.offset_x, 
            g_vdorec_osd_cntx.panel.zoom_inc.offset_y, 
            image_width, 
            image_height);
    }
	#endif
    
    // clear zoom dec
    gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC, &image_width, &image_height);
    
    offset_x1 = g_vdorec_osd_cntx.panel.zoom_dec.offset_x - layer_offset_x;
    offset_y1 = g_vdorec_osd_cntx.panel.zoom_dec.offset_y - layer_offset_y;
    offset_x2 = g_vdorec_osd_cntx.panel.zoom_dec.offset_x + image_width - layer_offset_x;
    offset_y2 = g_vdorec_osd_cntx.panel.zoom_dec.offset_y + image_height - layer_offset_y;
    
    gdi_draw_solid_rect(offset_x1, offset_y1, offset_x2, offset_y2, GDI_COLOR_TRANSPARENT);

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_osd_cntx.panel.zoom_dec.offset_x, 
            g_vdorec_osd_cntx.panel.zoom_dec.offset_y, 
            image_width, 
            image_height);
    }
	#endif
    
    gdi_layer_pop_and_restore_active();
#endif

#endif
}


#ifdef __VDOREC_FEATURE_ZOOM__

/*****************************************************************************
* FUNCTION
*  mmi_vdorec_start_fast_zoom
* DESCRIPTION
*  start fast zoom in
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_start_fast_zoom(void *is_zoom_in)
{
#ifdef __VDOREC_FEATURE_FAST_ZOOM__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_zoom;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vdorec_cntx.is_fast_zoom = MMI_TRUE;
    if(is_zoom_in)
    {
      is_zoom = MMI_TRUE;
    }
    else
    {
      is_zoom = MMI_FALSE;
    }
    gui_start_timer(VDOREC_INC_INTERVAL, mmi_vdorec_draw_zoom_osd);
    mdi_video_rec_start_fast_zoom(is_zoom, (U8) g_vdorec_cntx.max_zoom_steps, 1, 1);
#endif
}

/*****************************************************************************
* FUNCTION
*  mmi_vdorec_stop_fast_zoom
* DESCRIPTION
*  stop the fast zoom
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_stop_fast_zoom(void)
{
#ifdef __VDOREC_FEATURE_FAST_ZOOM__
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 current_idx;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_STOP_FAST_ZOOM);

    mdi_video_rec_stop_fast_zoom();

    /*need update the zoom factor*/
    if (g_vdorec_cntx.is_fast_zoom_support && g_vdorec_cntx.is_fast_zoom)
    {
        mdi_video_rec_get_fast_zoom_step(&current_idx);
        g_vdorec_cntx.setting.zoom = current_idx;
    }
    g_vdorec_cntx.is_fast_zoom = MMI_FALSE;
#endif
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_title
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_title(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str_width;
    S32 str_height;
    S32 offset_x;
    S32 offset_y;
    S32 layer_offset_x;
    S32 layer_offset_y;
    CHAR * str_ptr;
    video_rect_struct *bbox_rect_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_TITLE);

	if (!g_vdorec_osd_cntx.title.is_draw_app_name)
	{
		return;
	}

    gdi_layer_push_and_set_active(g_vdorec_cntx.title_draw_layer);

    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    /* display filename */
    if (g_vdorec_osd_cntx.title.is_draw_app_name)
    {   
        bbox_rect_p = &g_vdorec_osd_cntx.title.rect;

        gui_set_text_clip(
            bbox_rect_p->offset_x - layer_offset_x,
            bbox_rect_p->offset_y - layer_offset_y,
            bbox_rect_p->offset_x + bbox_rect_p->width - layer_offset_x - 1,
            bbox_rect_p->offset_y + bbox_rect_p->height - layer_offset_y - 1);

        str_ptr = (CHAR *) GetString(STR_ID_VDOREC_APP_NAME);

        gui_measure_string((UI_string_type) str_ptr, &str_width, &str_height);

        if (g_vdorec_osd_cntx.title.v_align == VIDEO_ALIGN_TOP)
        {
            offset_y = 0;
        }
        else if (g_vdorec_osd_cntx.title.v_align == VIDEO_ALIGN_BOTTOM)
        {
            offset_y = bbox_rect_p->height - str_height;
        }
        else    /* center */
        {
            offset_y = (bbox_rect_p->height - str_height) >> 1;
        }

        offset_y += bbox_rect_p->offset_y;

        if (g_vdorec_osd_cntx.title.h_align == VIDEO_ALIGN_LEFT)
        {
            offset_x = 0;
        }
        else if (g_vdorec_osd_cntx.title.h_align == VIDEO_ALIGN_RIGHT)
        {
            offset_x = bbox_rect_p->width - str_width;
        }
        else
        {
            offset_x = (bbox_rect_p->width - str_width) >> 1;
        }

        offset_x += bbox_rect_p->offset_x;

        mmi_vdorec_draw_style_text(
            str_ptr, 
            offset_x - layer_offset_x, 
            offset_y - layer_offset_y, 
            0,
            &g_vdorec_osd_cntx.title.style_text);

        gui_reset_text_clip();  /* restore clip to full screen */

		#ifdef __VDOREC_USING_BLT_REGION__
        if (g_vdorec_cntx.is_use_blt_region)
        {
            mmi_vdorec_merge_blt_rgn(
                bbox_rect_p->offset_x,
                bbox_rect_p->offset_y,
                bbox_rect_p->width,
                bbox_rect_p->height);
        }
		#endif
    }
    
#ifdef __VDOREC_FEATURE_SHOW_STATUS_BAR__
    wgui_status_icon_bar_update();  
#endif /* __VDOREC_FEATURE_SHOW_STATUS_BAR__ */

    gdi_layer_pop_and_restore_active();
}


#ifndef __MMI_VIDEO_RECORDER_SLIM__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_status_osd_icon
 * DESCRIPTION
 *  draw video recorder status icons.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_clear_status_osd_icon
	(video_icon_struct *icon,
	U16 id,
	S32 layer_offset_x,
	S32 layer_offset_y
	)
{
    S32 image_width, image_height;

	if(icon->is_show)
	{
		gdi_image_get_dimension_id(id, &image_width, &image_height);
		gdi_draw_solid_rect(																		
			icon->offset_x - layer_offset_x,												
			icon->offset_y - layer_offset_y,												
			icon->offset_x + image_width - layer_offset_x,								
			icon->offset_y + image_height - layer_offset_y,								
			GDI_COLOR_TRANSPARENT); 
		
#ifdef __VDOREC_USE_BLT_REGION__			
            if (g_vdorec_cntx.is_use_blt_region)                                                        
            {                                                                                           
                mmi_vdorec_merge_blt_rgn(                                                               
                    icon->offset_x, icon->offset_y, image_width, image_height);     
            }                   
#endif		
	}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_clear_status
 * DESCRIPTION
 *  clear video recorder status icons.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_clear_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    video_osd_vdorec_status_struct *status_p;
    S32 layer_offset_x, layer_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_CLEAR_STATUS, g_vdorec_osd_cntx.status.is_show);

    if (!g_vdorec_osd_cntx.status.is_show)
    {
        return;
    }

    status_p = &g_vdorec_osd_cntx.status;

    gdi_layer_push_and_set_active(g_vdorec_cntx.status_draw_layer);

    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
	mmi_vdorec_clear_status_osd_icon
		(&status_p->video_size,
		IMG_ID_VDOREC_OSD_VIDEO_SIZE_START+1,
		layer_offset_x,
		layer_offset_y);
#endif
    
#ifdef __VDOREC_FEATURE_VIDEO_QTY__
	mmi_vdorec_clear_status_osd_icon
		(&status_p->video_qty,
		IMG_ID_VDOREC_OSD_VIDEO_QTY_START+1,
		layer_offset_x,
		layer_offset_y);
#endif
    
#ifdef __VDOREC_FEATURE_NIGHT__
	mmi_vdorec_clear_status_osd_icon
		(&status_p->night,
		IMG_ID_VDOREC_OSD_NIGHT_ON,
		layer_offset_x,
		layer_offset_y);	            
#endif 
    
#ifdef __VDOREC_FEATURE_WB__
	mmi_vdorec_clear_status_osd_icon
		(&status_p->wb,
		IMG_ID_VDOREC_OSD_WB_START+1,
		layer_offset_x,layer_offset_y);
#endif
    
#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
	mmi_vdorec_clear_status_osd_icon
		(&status_p->led_highlight,
		IMG_ID_VDOREC_OSD_LED_HIGHLIGHT_START+1,
		layer_offset_x,
		layer_offset_y);
#endif 
    
#ifdef __VDOREC_FEATURE_RECORD_AUD__
	mmi_vdorec_clear_status_osd_icon
		(&status_p->record_aud,
		IMG_ID_VDOREC_OSD_RECORD_AUD_START+1,
		layer_offset_x,
		layer_offset_y);
#endif 
    
#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
	mmi_vdorec_clear_status_osd_icon
		(&status_p->size_limit,
		IMG_ID_VDOREC_OSD_SIZE_LIMIT_START+1,
		layer_offset_x,
		layer_offset_y);
#endif 
    
#ifdef __VDOREC_FEATURE_TIME_LIMIT__
	mmi_vdorec_clear_status_osd_icon
		(&status_p->time_limit,
		IMG_ID_VDOREC_OSD_TIME_LIMIT_START+1,
		layer_offset_x,
		layer_offset_y);
#endif 

    gdi_layer_pop_and_restore_active();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_status_osd_icon
 * DESCRIPTION
 *  draw video recorder status icons.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_status_osd_icon
	(video_icon_struct *icon,
	U16 id,
	U16 id_offset,
	S32 layer_offset_x,
	S32 layer_offset_y
	)
{
    S32 image_width, image_height;

	if(icon->is_show)
	{
		gdi_image_get_dimension_id(id, &image_width, &image_height);
		gdi_image_draw_id(icon->offset_x - layer_offset_x,                                
                           icon->offset_y - layer_offset_y,                               
                           id+id_offset);
		
#ifdef __VDOREC_USE_BLT_REGION__			
       	if (g_vdorec_cntx.is_use_blt_region)                                                        
        {                                                                                           
        	mmi_vdorec_merge_blt_rgn(                                                               
            	icon->offset_x, icon->offset_y, image_width, image_height);     
        }                   
#endif		
	}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_status
 * DESCRIPTION
 *  draw video recorder status icons.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    video_osd_vdorec_status_struct *status_p;
    S32 layer_offset_x, layer_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_STATUS, g_vdorec_osd_cntx.status.is_show);

    if (!g_vdorec_osd_cntx.status.is_show)
    {
        return;
    }

    #ifdef __VDOREC_FEATURE_SLIM_UE__
        mmi_vdorec_clear_status();
    #endif

    status_p = &g_vdorec_osd_cntx.status;

    gdi_layer_push_and_set_active(g_vdorec_cntx.status_draw_layer);
    
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

   /****** draw icon MACRO ******/
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
	mmi_vdorec_draw_status_osd_icon
		(&status_p->video_size,
		IMG_ID_VDOREC_OSD_VIDEO_SIZE_START+1,
		g_vdorec_cntx.setting.video_size,
		layer_offset_x,
		layer_offset_y);
#endif

#ifdef __VDOREC_FEATURE_VIDEO_QTY__
	mmi_vdorec_draw_status_osd_icon
		(&status_p->video_qty,
		IMG_ID_VDOREC_OSD_VIDEO_QTY_START+1,
		g_vdorec_cntx.setting.video_qty,
		layer_offset_x,
		layer_offset_y);	
#endif

#ifdef __VDOREC_FEATURE_NIGHT__
    #ifdef __VDOREC_FEATURE_SLIM_UE__
    if (g_vdorec_cntx.setting.night != VDOREC_DEFAULT_SETTING_NIGHT)
    #endif
    {
		mmi_vdorec_draw_status_osd_icon
			(&status_p->night,
			IMG_ID_VDOREC_OSD_NIGHT_START+1,
			g_vdorec_cntx.setting.night,
			layer_offset_x,
			layer_offset_y);
    }
#endif 

#ifdef __VDOREC_FEATURE_WB__
    #ifdef __VDOREC_FEATURE_SLIM_UE__
    if (g_vdorec_cntx.setting.wb != VDOREC_DEFAULT_SETTING_WB)
    #endif
    {
		U16 temp;
	
    	temp = g_vdorec_cntx.setting.wb;
		g_vdorec_cntx.setting.wb = support_wb_item[g_vdorec_cntx.setting.wb];
		mmi_vdorec_draw_status_osd_icon
			(&status_p->wb,
			IMG_ID_VDOREC_OSD_WB_START+1,
			g_vdorec_cntx.setting.wb,
			layer_offset_x,
			layer_offset_y);		
		g_vdorec_cntx.setting.wb = temp;
    }
#endif

#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
    #ifdef __VDOREC_FEATURE_SLIM_UE__
    if (g_vdorec_cntx.setting.led_highlight != VDOREC_DEFAULT_SETTING_LED_HIGHLIGHT)
    #endif
    {
		mmi_vdorec_draw_status_osd_icon
			(&status_p->led_highlight,
			IMG_ID_VDOREC_OSD_LED_HIGHLIGHT_START+1,
			g_vdorec_cntx.setting.led_highlight,
			layer_offset_x,
			layer_offset_y);		
    }
#endif 

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    #ifdef __VDOREC_FEATURE_SLIM_UE__
    if (g_vdorec_cntx.setting.record_aud != VDOREC_DEFAULT_SETTING_RECORD_AUD)
    #endif
    {
		mmi_vdorec_draw_status_osd_icon
			(&status_p->record_aud,
			IMG_ID_VDOREC_OSD_RECORD_AUD_START+1,
			g_vdorec_cntx.setting.record_aud,
			layer_offset_x,
			layer_offset_y);		
    }
#endif 

#ifdef __VDOREC_FEATURE_SIZE_LIMIT__
    #ifdef __VDOREC_FEATURE_SLIM_UE__
    if (g_vdorec_cntx.setting.size_limit != VDOREC_DEFAULT_SETTING_SIZE_LIMIT)
    #endif
    {
		mmi_vdorec_draw_status_osd_icon
			(&status_p->size_limit,
			IMG_ID_VDOREC_OSD_SIZE_LIMIT_START+1,
			g_vdorec_cntx.setting.size_limit,
			layer_offset_x,
			layer_offset_y);		
    }
#endif 

#ifdef __VDOREC_FEATURE_TIME_LIMIT__
    #ifdef __VDOREC_FEATURE_SLIM_UE__
    if (g_vdorec_cntx.setting.time_limit != VDOREC_DEFAULT_SETTING_TIME_LIMIT)
    #endif
    {
		mmi_vdorec_draw_status_osd_icon
			(&status_p->time_limit,
			IMG_ID_VDOREC_OSD_TIME_LIMIT_START+1,
			g_vdorec_cntx.setting.time_limit,
			layer_offset_x,
			layer_offset_y);			
    }
#endif 

    gdi_layer_pop_and_restore_active();
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_softkey
 * DESCRIPTION
 *  draw softkey bar (softkey)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_softkey_icon
		(
#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__		
		vdorec_ui_touch_struct *touch,
#endif
		U16 sk_img_id,gdi_handle sk_draw_layer,BOOL press,
		WGUI_SOFTKEY_ENUM type,
		video_pos_struct *pos)
{
    S32 img_width;
    S32 img_height;
    S32 layer_offset_x;
    S32 layer_offset_y;
    S32 sk_offset_x;
    S32 sk_offset_y;
	S32 offseta;
	S32 offsetb;
	S32 offsetc;
    U16 image_id = 0;

#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
	vdorec_ui_touch_struct *touch_p;
#endif /* __VDOREC_FEATURE_TOUCH_SCREEN__ */ 

   	gdi_image_get_dimension_id(sk_img_id, &img_width, &img_height);
        
    sk_offset_x = pos->offset_x;
    sk_offset_y = pos->offset_y;
        
#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
    touch_p = touch;
    touch_p->offset_x = sk_offset_x;
    touch_p->offset_y = sk_offset_y;
    touch_p->width = img_width;
    touch_p->height = img_height;
#endif /* __VDOREC_FEATURE_TOUCH_SCREEN__ */ 
     
    gdi_layer_push_and_set_active(sk_draw_layer);
        
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

	// calculate offset
	if(type == MMI_CENTER_SOFTKEY)
	{
		offseta = 0;
		offsetb = 1;
		offsetc = 1;
	}
	else if(type == MMI_LEFT_SOFTKEY)
	{
		offseta = -1;
		offsetb = -1;
		offsetc = 0;
	}
	else
	{
		offseta = 0;
		offsetb = 0;
		offsetc = 0;
	}

	// draw solid rect
    gdi_draw_solid_rect(
       	sk_offset_x - layer_offset_x, 
       	sk_offset_y - layer_offset_y + offseta, 
        sk_offset_x + img_width + offsetb, 
        sk_offset_y + img_height + offsetc, 
        GDI_COLOR_TRANSPARENT);

	image_id = press?(sk_img_id+1):sk_img_id;

#ifdef __VDOREC_FEATURE_SLIM_UE__
	if(type == MMI_CENTER_SOFTKEY)
	{
   		sk_offset_x++;
    	sk_offset_y++;
		image_id = sk_img_id;
	}
#endif /* __VDOREC_FEATURE_SLIM_UE__ */   	
	
    gdi_image_draw_id(
        sk_offset_x - layer_offset_x, 
        sk_offset_y - layer_offset_y, 
        image_id);
        
    gdi_layer_pop_and_restore_active();
		
}


static void mmi_vdorec_draw_softkey_string
		(
#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
		vdorec_ui_touch_struct *touch,
#endif
		U16 sk_str_id,gdi_handle sk_draw_layer,BOOL press,
		WGUI_SOFTKEY_ENUM type,
		video_style_text_struct *pos,mmi_frm_screen_rotate_enum rotate)
{
	S32 layer_offset_x;
	S32 layer_offset_y;
	S32 sk_offset_x;
	S32 sk_offset_y;
	S32 truncated_w;
	S32 str_width;
	S32 str_height;
	S32 offseta;
	S32 offsetb;
	CHAR * sk_str_ptr;
	MMI_BOOL empty_str;
	WGUI_SOFTKEY_ENUM temp_type;

#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
	vdorec_ui_touch_struct *touch_p;
#endif 
	if(type == WGUI_MAX_SOFTKEYS)
	{
		empty_str = MMI_TRUE;
		temp_type = MMI_LEFT_SOFTKEY;
	}
	else
	{
		empty_str = MMI_FALSE;
		temp_type = type;
	}

	sk_str_ptr = GetString(sk_str_id);

	wgui_softkey_get_offset(
		(UI_string_type)sk_str_ptr, 
		&sk_offset_x, 
		&sk_offset_y, 
		&truncated_w, 
		temp_type,
		rotate);
	
	gui_measure_string((UI_string_type) sk_str_ptr, &str_width, &str_height);

	#if defined (__MMI_BIDI_ALG__)
	if(mmi_fe_get_r2l_state())
	{
		sk_offset_x -= str_width;
	}
	#endif

	gdi_layer_push_and_set_active(sk_draw_layer);
	gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

	if(empty_str) //means LSK is empty
	{
		g_vdorec_cntx.lsk_bound_box.offset_x = sk_offset_x;
		g_vdorec_cntx.lsk_bound_box.offset_y = sk_offset_y;
		g_vdorec_cntx.lsk_bound_box.width = str_width;
		g_vdorec_cntx.lsk_bound_box.height = str_height;

		gdi_draw_solid_rect(
			sk_offset_x - layer_offset_x - 1, 
			sk_offset_y - layer_offset_y - 1, 
			sk_offset_x - layer_offset_x + str_width + 1, 
			sk_offset_y - layer_offset_y + str_height + 1, 
			GDI_COLOR_TRANSPARENT);
	}
	else
	{
		if(type == MMI_RIGHT_SOFTKEY)
		{
			offseta = -4;
			offsetb = 7;
		}
		else
		{
			offseta = 0;
			offsetb = 1;
		}
	
		gdi_draw_solid_rect(
			sk_offset_x - layer_offset_x + offseta, 
			sk_offset_y - layer_offset_y + offseta, 
			sk_offset_x + str_width + offsetb, 
			sk_offset_y + str_height + offsetb, 
			GDI_COLOR_TRANSPARENT);
			
		if (press)
		{
			sk_offset_x++;
			sk_offset_y++;
		}
	
		mmi_vdorec_draw_style_text(
			sk_str_ptr,
			sk_offset_x - layer_offset_x,
			sk_offset_y - layer_offset_y,
			truncated_w,
			pos);
	}
	
	gdi_layer_pop_and_restore_active();
	
	#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
	touch_p = touch;

	if(empty_str)
	{
		touch_p->offset_x = 0;
		touch_p->offset_y = 0;
		touch_p->width = 0;
		touch_p->height = 0;
	}
	else
	{
		touch_p->offset_x = sk_offset_x;
		touch_p->offset_y = sk_offset_y;
		touch_p->width = str_width;
		touch_p->height = str_height;		
	}
    #endif /* __VDOREC_FEATURE_TOUCH_SCREEN__ */ 
}


static void mmi_vdorec_draw_softkey(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 image_id = 0;
	MMI_BOOL is_pressed;
    mmi_frm_screen_rotate_enum rotate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_SOFTKEY);

    gdi_layer_reset_clip();

#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
    rotate = MMI_FRM_SCREEN_ROTATE_270;
#else
    rotate = MMI_FRM_SCREEN_ROTATE_0;
#endif
    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_BUTTON));

    if ((g_vdorec_osd_cntx.softkey.is_lsk_icon != FALSE) && (g_vdorec_cntx.lsk_img_id != 0))
    {
		mmi_vdorec_draw_softkey_icon
		(
#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__	
		&g_vdorec_cntx.touch_lsk,
#endif			
		g_vdorec_cntx.lsk_img_id,
		g_vdorec_cntx.lsk_draw_layer,
		g_vdorec_cntx.is_lsk_pressed,
		MMI_LEFT_SOFTKEY,
		&g_vdorec_osd_cntx.softkey.icon_lsk_pos
		);
    }
    else
    {
		if(g_vdorec_cntx.lsk_str_id != 0)
		{
			mmi_vdorec_draw_softkey_string
			(
#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__		
			&g_vdorec_cntx.touch_lsk,
#endif				
			g_vdorec_cntx.lsk_str_id,
			g_vdorec_cntx.lsk_draw_layer,
			g_vdorec_cntx.is_lsk_pressed,
			MMI_LEFT_SOFTKEY,
			&g_vdorec_osd_cntx.softkey.lsk_text,
			rotate
			);
        }
		
		if(g_vdorec_cntx.lsk_str_id == 0 && g_vdorec_cntx.lsk_img_id == 0)
		{
			mmi_vdorec_draw_softkey_string
			(
#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__		
			&g_vdorec_cntx.touch_lsk,
#endif				
			STR_GLOBAL_OPTIONS,
			g_vdorec_cntx.lsk_draw_layer,
			g_vdorec_cntx.is_lsk_pressed,
			WGUI_MAX_SOFTKEYS,
			NULL,
			rotate
			);
		}
    }
       

    if ((g_vdorec_osd_cntx.softkey.is_rsk_icon != FALSE) && (g_vdorec_cntx.rsk_img_id != 0))
    {
		// normal case
		image_id = g_vdorec_cntx.rsk_img_id;
		is_pressed = (MMI_BOOL)g_vdorec_cntx.is_rsk_pressed;
		
		/*currently del key and rsk location are both rsk, but the image are different*/
#if defined(__VDOREC_FEATURE_PREVIEW_SAVED_FILE__) && defined(__VDOREC_FEATURE_RSK_DELETE__)
		if (SCR_ID_VDOREC_SAVED_PREVIEW == mmi_frm_scrn_get_active_id())
		{
            image_id = IMG_ID_VDOREC_SK_DELETE;   
			is_pressed = g_vdorec_cntx.is_del_key_pressed;
		}
#endif

		mmi_vdorec_draw_softkey_icon
		(
#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
		&g_vdorec_cntx.touch_rsk,
#endif			
		image_id,
		g_vdorec_cntx.rsk_draw_layer,
		is_pressed,
		MMI_RIGHT_SOFTKEY,
		&g_vdorec_osd_cntx.softkey.icon_rsk_pos
		);

    }   
    else
    {
        /* rsk string */
        if (g_vdorec_cntx.rsk_str_id != NULL)
        {
			mmi_vdorec_draw_softkey_string
			(
#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
			&g_vdorec_cntx.touch_rsk,
#endif			
			g_vdorec_cntx.rsk_str_id,
			g_vdorec_cntx.rsk_draw_layer,
			g_vdorec_cntx.is_rsk_pressed,
			MMI_RIGHT_SOFTKEY,
			&g_vdorec_osd_cntx.softkey.rsk_text,
			rotate
			);
        }
    }

    if (g_vdorec_osd_cntx.softkey.is_ck_icon)
    {
        /* draw c key */
        if (g_vdorec_cntx.ck_img_id != 0)
        {
			mmi_vdorec_draw_softkey_icon
			(
#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
			&g_vdorec_cntx.touch_ck,
#endif			
			g_vdorec_cntx.ck_img_id,
			g_vdorec_cntx.ck_draw_layer,
			g_vdorec_cntx.is_ck_pressed,
			MMI_CENTER_SOFTKEY,
			&g_vdorec_osd_cntx.softkey.icon_ck_pos
			);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_set_softkey
 * DESCRIPTION
 *  Set softkey string ptr that will be draw
 * PARAMETERS
 *  lsk_str_ptr     [IN]        Lsk string pointer
 *  rsk_str_ptr     [IN]        Rsk string pointer
 *  lsk_img_id      [IN]        Lsk image id
 *  rsk_img_id      [IN]        Rsk image id
 *  ck_img_id       [IN]        Ck_image id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_set_softkey(U16 lsk_str_id, U16 rsk_str_id, U16 lsk_img_id, U16 rsk_img_id, U16 ck_img_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SET_SOFTKEY);
    
    g_vdorec_cntx.lsk_str_id = lsk_str_id;
    g_vdorec_cntx.rsk_str_id = rsk_str_id;
    g_vdorec_cntx.lsk_img_id = lsk_img_id;
    g_vdorec_cntx.rsk_img_id = rsk_img_id;
    g_vdorec_cntx.ck_img_id = ck_img_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_panel_state
 * DESCRIPTION
 *  draw panel state (stop, pause, record)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_panel_state(void)
{
#ifndef __MMI_VIDEO_RECORDER_SLIM__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 layer_offset_x;
    S32 layer_offset_y;    
    S32 image_width;
    S32 image_height;
    gdi_color color = GDI_COLOR_RED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_PANEL_STATE);

    /*state is always showed with timer*/
    if (!g_vdorec_cntx.is_timer_show)
    {
         return;
    }

    gdi_layer_push_and_set_active(g_vdorec_cntx.state_draw_layer);

    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_image_get_dimension_id(IMG_ID_VDOREC_TIME_NUMBER_0, &image_width, &image_height);

    if (g_vdorec_cntx.state != VDOREC_STATE_RECORD)
    {
        color = GDI_COLOR_GREEN;
    }

    gdi_draw_solid_circle(
        g_vdorec_cntx.timer.hr_0_offset_x - VDOREC_TIME_STATE_REDIUS * 2 - 1 - layer_offset_x,
        g_vdorec_cntx.timer.offset_y + ((image_height - VDOREC_TIME_STATE_REDIUS * 2) >> 1) + VDOREC_TIME_STATE_REDIUS - layer_offset_y,
        VDOREC_TIME_STATE_REDIUS,
        color);

    gdi_layer_pop_and_restore_active();

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_cntx.timer.hr_0_offset_x - VDOREC_TIME_STATE_REDIUS * 3 - 1,
            g_vdorec_cntx.timer.offset_y,
            VDOREC_TIME_STATE_REDIUS >> 1,
            VDOREC_TIME_STATE_REDIUS >> 1);
    }
	#endif
#endif	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_panel_zoom
 * DESCRIPTION
 *  draw panel zoom
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_panel_zoom(void)
{
#ifndef __MMI_VIDEO_RECORDER_SLIM__

#ifdef __VDOREC_FEATURE_ZOOM__	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifndef __VDOREC_FEATURE_SLIM_UE__
    U32 current_zoom_factor;
    S32 factor_offset_x;
    S32 factor_offset_y;
    S16 zoom_region_x = 0;
    S16 zoom_region_y = 0;
    S16 zoom_region_w = 0;
    S16 zoom_region_h = 0;
    #endif
    S32 layer_offset_x;
    S32 layer_offset_y;
#ifdef __VDOREC_USING_BLT_REGION__	
    S32 image_width;
    S32 image_height;
#endif	
    U32 curr_digit;
    U16 image_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_PANEL_ZOOM);

    gdi_layer_push_and_set_active(g_vdorec_cntx.zoom_draw_layer);
    
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);
    gdi_set_alpha_blending_source_layer(g_vdorec_cntx.zoom_draw_layer);

#ifndef __VDOREC_FEATURE_SLIM_UE__

    /* zooming icon */
    gdi_image_draw_id(
        g_vdorec_osd_cntx.panel.zoom.offset_x - layer_offset_x,
        g_vdorec_osd_cntx.panel.zoom.offset_y - layer_offset_y,
        IMG_ID_VDOREC_TOUCH_OSD_ZOOM_HEAD);

    /*zoom factor*/
    if (g_vdorec_cntx.setting.zoom == 0)
    {
        current_zoom_factor = 10;
    }
    else
    {
        mdi_video_rec_get_fast_zoom_factor(&current_zoom_factor);
        current_zoom_factor /= 10;
    }

    factor_offset_x = g_vdorec_osd_cntx.panel.zoom.offset_x - layer_offset_x;
    factor_offset_y = g_vdorec_osd_cntx.panel.zoom.offset_y - layer_offset_y;

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        zoom_region_x = g_vdorec_osd_cntx.panel.zoom.offset_x;
        zoom_region_y = g_vdorec_osd_cntx.panel.zoom.offset_y;
        zoom_region_w = 0;
        zoom_region_h = 0;
    }
	#endif

    gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_ZOOM_HEAD, &image_width, &image_height);
    factor_offset_x += image_width;

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        zoom_region_w += image_width;
        zoom_region_h = image_height;
    }
	#endif

    /*first zoom digit*/
    curr_digit = current_zoom_factor / 10 % 10;
    gdi_image_draw_id(factor_offset_x, factor_offset_y, (U16)(IMG_ID_VDOREC_EFFECT_NUMBER_0 + curr_digit));

    /*draw dot*/
    gdi_image_get_dimension_id(IMG_ID_VDOREC_EFFECT_NUMBER_0, &image_width, &image_height);
    factor_offset_x += image_width;

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        zoom_region_w += image_width;
    }
	#endif
	
    gdi_image_draw_id(factor_offset_x, factor_offset_y, IMG_ID_VDOREC_EFFECT_DOT);

    /*second zoom digit*/
    gdi_image_get_dimension_id(IMG_ID_VDOREC_EFFECT_DOT, &image_width, &image_height);
    factor_offset_x += image_width;

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        zoom_region_w += image_width;
    }
	#endif
	
    curr_digit = current_zoom_factor % 10;
    gdi_image_draw_id(factor_offset_x, factor_offset_y, (U16)(IMG_ID_VDOREC_EFFECT_NUMBER_0 + curr_digit));

    /*get last digit width*/
    gdi_image_get_dimension_id(IMG_ID_VDOREC_EFFECT_NUMBER_0, &image_width, &image_height);

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        zoom_region_w += image_width;
    }
	#endif

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            zoom_region_x,
            zoom_region_y,
            zoom_region_w,
            zoom_region_h);
    }
	#endif

#endif  /*__VDOREC_FEATURE_SLIM_UE__*/

#ifdef __VDOREC_FEATURE_SLIM_UE__
#ifndef __VDOREC_FEATURE_FTE_SUPPORT__
	/* zoom head icon */
	gdi_image_draw_resized_id(
		g_vdorec_osd_cntx.panel.zoom.offset_x - layer_offset_x,
		g_vdorec_osd_cntx.panel.zoom.offset_y - layer_offset_y,
		54,
		12,
		IMG_ID_VDOREC_TOUCH_OSD_ZOOM_HEAD);
#else
	/* zoom head icon */
	gdi_image_draw_resized_id(
		g_vdorec_osd_cntx.panel.zoom.offset_x - layer_offset_x,
		g_vdorec_osd_cntx.panel.zoom.offset_y - layer_offset_y-2,
		72,
		18,
		IMG_ID_VDOREC_TOUCH_OSD_ZOOM_HEAD);
#endif
#endif

    /* zoom inc */
    if (g_vdorec_cntx.is_fast_zoom_support && g_vdorec_cntx.is_fast_zoom)
    {
        mdi_video_rec_get_fast_zoom_step(&curr_digit);
        g_vdorec_cntx.setting.zoom = curr_digit;
    }
    
	if (g_vdorec_cntx.setting.zoom == g_vdorec_cntx.max_zoom_steps)
	{
	    image_id = IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC_DIS;
	}
	else if (g_vdorec_cntx.touch_zoom_inc.is_press || g_vdorec_cntx.is_zoom_in_key_pressed)
	{
	    image_id = IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC_SEL;
	}
	else
	{
	    image_id = IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC;
	}
    gdi_image_draw_id(
        g_vdorec_osd_cntx.panel.zoom_inc.offset_x - layer_offset_x,
        g_vdorec_osd_cntx.panel.zoom_inc.offset_y - layer_offset_y,
        image_id);
    
	#ifdef __VDOREC_USING_BLT_REGION__
	gdi_image_get_dimension_id(image_id, &image_width, &image_height);
    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_osd_cntx.panel.zoom_inc.offset_x,
            g_vdorec_osd_cntx.panel.zoom_inc.offset_y,
            image_width,
            image_height);
    }
	#endif

	/* zoom dec */
	if (g_vdorec_cntx.setting.zoom == 0)
	{
	    image_id = IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC_DIS;
	}
    else if ((g_vdorec_cntx.touch_zoom_dec.is_press) || (g_vdorec_cntx.is_zoom_out_key_pressed))
    {
        image_id = IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC_SEL;
    }
    else
    {
        image_id = IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC;
    }
    gdi_image_draw_id(
        g_vdorec_osd_cntx.panel.zoom_dec.offset_x - layer_offset_x,
        g_vdorec_osd_cntx.panel.zoom_dec.offset_y - layer_offset_y,
        image_id);

	#ifdef __VDOREC_USING_BLT_REGION__
	gdi_image_get_dimension_id(image_id, &image_width, &image_height);
    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_osd_cntx.panel.zoom_dec.offset_x,
            g_vdorec_osd_cntx.panel.zoom_dec.offset_y,
            image_width,
            image_height);
    }
	#endif	
    
    gdi_layer_pop_and_restore_active();
#endif /* __VDOREC_FEATURE_ZOOM__ */ 
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_clear_panel_timer
 * DESCRIPTION
 *  draw panel timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_clear_timer(void)
{
#ifndef __MMI_VIDEO_RECORDER_SLIM__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 offset_x1, offset_y1, offset_x2, offset_y2, digit_width, digit_height, layer_offset_x, layer_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_CLEAR_TIMER, g_vdorec_cntx.is_timer_show);

	if (!g_vdorec_cntx.is_timer_show)
	{
		return;
	}

    gdi_layer_push_and_set_active(g_vdorec_cntx.timer_draw_layer);
    
    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_image_get_dimension_id(IMG_ID_VDOREC_TIME_NUMBER_0, &digit_width, &digit_height);

    offset_x1 = g_vdorec_cntx.timer.hr_0_offset_x - layer_offset_x;
    offset_y1 = g_vdorec_cntx.timer.offset_y - layer_offset_y;
    offset_x2 = g_vdorec_cntx.timer.sec_1_offset_x + digit_width - layer_offset_x;
    offset_y2 = g_vdorec_cntx.timer.offset_y + digit_height - layer_offset_y;

    gdi_draw_solid_rect(offset_x1, offset_y1, offset_x2, offset_y2, GDI_COLOR_TRANSPARENT);

    gdi_layer_pop_and_restore_active();

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_cntx.timer.hr_0_offset_x, 
            g_vdorec_cntx.timer.offset_y, 
            g_vdorec_cntx.timer.sec_1_offset_x + digit_width - g_vdorec_cntx.timer.hr_0_offset_x, 
            digit_height);
    }
	#endif
#endif	
}

static void mmi_vdorec_draw_panel_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 rec_time;
    
	  /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_PANEL_TIMER, g_vdorec_cntx.is_timer_show);

	  if (!g_vdorec_cntx.is_timer_show)
	  {
		   return;
	  }

    gdi_layer_push_and_set_active(g_vdorec_cntx.timer_draw_layer);
   
    rec_time = (U32) (g_vdorec_cntx.record_time / 1000);

    mmi_vdorec_draw_panel_timer_ext((void*)&g_vdorec_cntx.timer, rec_time, MMI_FALSE);
    
    gdi_layer_pop_and_restore_active();
}


#ifdef __VDOREC_FEATURE_MULTI_REGION_SUPPORT__
/*****************************************************************************
* FUNCTION
*  mmi_vdorec_get_layer_handle_by_position
* DESCRIPTION
*  get component is on which layer
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#pragma no_inline
static gdi_handle mmi_vdorec_get_layer_handle_by_position(S32 offset_x, S32 offset_y, U32 component)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle handle = GDI_LAYER_EMPTY_HANDLE;
	video_rect_struct *rect_ptr[4];
    video_rect_struct *ptr;

	S32 region;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
                          
    rect_ptr[0] = &g_vdorec_osd_cntx.osd_layer_region.region_0;                    
    rect_ptr[1] = &g_vdorec_osd_cntx.osd_layer_region.region_1;                    
    rect_ptr[2] = &g_vdorec_osd_cntx.osd_layer_region.region_2;  
    rect_ptr[3] = &g_vdorec_osd_cntx.osd_layer_region.region_3;  

	for(region = 0; region <4; region++)
	{
		ptr = rect_ptr[region];
		if ((offset_x >= ptr->offset_x) &&					
				(offset_x <= ptr->offset_x + ptr->width) && 
				(offset_y >= ptr->offset_y) &&					
				(offset_y <= ptr->offset_y + ptr->height))  
			{
				#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__			
				if (g_vdorec_cntx.is_use_hw_rotate)
				{
					handle = g_vdorec_cntx.tmp_osd_layer_region_handle[region];	  
				}
				#else					
				{
					handle = g_vdorec_cntx.osd_layer_region_handle[region];
				}
				#endif
				
				g_vdorec_cntx.osd_layer_region_mask[region] |= component;

				break;
			}		 
	}
    
                                                                 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_GET_LAYER_HANDLE_BY_POSITION, handle);

    return  handle;
}
#endif

#pragma no_inline
static void mmi_vdorec_init_ui_region(video_rect_struct *rect_ptr,S32 region,PU8 gdi_layer_buffer_ptr)
{
    S32 region_buf_size;
	S32 offset_x = 0;
    S32 offset_y = 0;
    S32 width = 0;
    S32 height = 0;
	PU8 buffer;

    region_buf_size = rect_ptr->width*rect_ptr->height*VDOREC_BUFFER_DEPTH;    

    g_vdorec_cntx.osd_layer_region_handle_ptr[region] 
		= (PU8) mmi_frm_scrmem_alloc_framebuffer(region_buf_size);

	#ifdef __MMI_VIDEO_RECORDER_SLIM__
	buffer = g_vdorec_cntx.osd_layer_region_handle_ptr2[region] 
		= (PU8) mmi_frm_scrmem_alloc_framebuffer(region_buf_size);
	#else
	buffer = (PU8)gdi_layer_buffer_ptr+total_pre_region_size;
	#endif

	#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__		
    if (g_vdorec_cntx.is_use_hw_rotate)
    {            
    	offset_x = g_vdorec_cntx.lcd_width - rect_ptr->offset_y - rect_ptr->height;
        offset_y = rect_ptr->offset_x;
        width = rect_ptr->height;
        height = rect_ptr->width;
    }
    #else
    {
    	offset_x = rect_ptr->offset_x;
        offset_y = rect_ptr->offset_y;
        width = rect_ptr->width;
        height = rect_ptr->height;
   	}
	#endif
	
	#ifdef __VDOREC_DOUBLE_BUFFER_SUPPORT__
  if (g_vdorec_cntx.is_gdi_double_buffer_enable)
  {
    	gdi_layer_create_using_outside_memory(
        	offset_x,
            offset_y,
            width,
            height,
            &g_vdorec_cntx.osd_layer_region_handle[region],
            (PU8)g_vdorec_cntx.osd_layer_region_handle_ptr[region],
            region_buf_size);
	}
	#else
  {
		gdi_layer_create_cf_double_using_outside_memory(
        	GDI_COLOR_FORMAT_16,
            offset_x,
            offset_y,
            width,
            height,
            &g_vdorec_cntx.osd_layer_region_handle[region],
            (PU8)g_vdorec_cntx.osd_layer_region_handle_ptr[region],
            region_buf_size,
            buffer,
            region_buf_size);		
 	}
	#endif

	#ifndef __MMI_VIDEO_RECORDER_SLIM__
	total_pre_region_size += region_buf_size;
	#endif
		
    mmi_vdorec_clear_osd_layer(g_vdorec_cntx.osd_layer_region_handle[region]);

}

#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
#pragma no_inline
static void mmi_vdorec_init_ui_rotate(video_rect_struct *rect_ptr,S32 region)
{
    S32 region_buf_size;

    region_buf_size = rect_ptr->width*rect_ptr->height*VDOREC_BUFFER_DEPTH;

	#ifdef __MMI_VIDEO_RECORDER_SLIM__
	g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[region]
		= (PU8) mmi_frm_scrmem_alloc_framebuffer(region_buf_size);
	#else
    g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[region] 
		= g_vdorec_cntx.app_mem_bufer + total_pre_region_size;	
	#endif
			
	gdi_layer_create_using_outside_memory(
    	rect_ptr->offset_x,
        rect_ptr->offset_y,
        rect_ptr->width,        
        rect_ptr->height,        
        &g_vdorec_cntx.tmp_osd_layer_region_handle[region],   
        (PU8)g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[region],
        (S32)region_buf_size);

	total_pre_region_size += region_buf_size;

	mmi_vdorec_clear_osd_layer(g_vdorec_cntx.tmp_osd_layer_region_handle[region]);
}
#endif


static void mmi_vdorec_init_ui(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 digit_width;
    S32 col_width;
    S32 height;

  	#ifdef __VDOREC_FEATURE_MULTI_REGION_SUPPORT__
    video_osd_vodrec_panel_struct *panel_ptr;    
    video_osd_softkey_struct *sk_ptr;   
	#endif
    
#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
    vdorec_ui_touch_struct *touch_p;
#endif 
    PU8 gdi_layer_buffer_ptr = NULL;
	total_pre_region_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_INIT_UI);

	#ifdef __VDOREC_DOUBLE_BUFFER_SUPPORT__
    if (g_vdorec_cntx.is_gdi_double_buffer_enable)
    {
        #ifdef __GDI_BLT_WITH_DOUBLE_BUF_SUPPORT__
        gdi_bltdb_enable(GDI_BLTDB_ENABLE_ONLY_WHEN_HW_UPDATE);
        #endif
    }
	#endif

#ifdef __VDOREC_FEATURE_SHOW_STATUS_BAR__
    gdi_layer_create(
        0, 
        0, 
        UI_DEVICE_WIDTH, 
        MMI_STATUS_BAR_HEIGHT, 
        &g_vdorec_cntx.status_bar_layer_handle);
    
    gdi_layer_push_and_set_active(g_vdorec_cntx.status_bar_layer_handle);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
    
    g_vdorec_cntx.prev_status_bar_layer_handle = 
        wgui_status_icon_bar_get_target_layer(WGUI_STATUS_ICON_BAR_H_BAR);
    wgui_status_icon_bar_set_target_layer(
        WGUI_STATUS_ICON_BAR_H_BAR,
        g_vdorec_cntx.status_bar_layer_handle);
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
    wgui_set_wallpaper_on_bottom(MMI_TRUE);
    
#else /* __VDOREC_FEATURE_SHOW_STATUS_BAR__ */
    g_vdorec_cntx.status_bar_layer_handle = GDI_LAYER_EMPTY_HANDLE;
#endif /* __VDOREC_FEATURE_SHOW_STATUS_BAR__ */

	#ifndef __MMI_VIDEO_RECORDER_SLIM__
    /*currently in order to save memory, we will steal GDI memory, 
    NOTE : we only use the memory, but do not use the handle */
    if ((g_vdorec_cntx.gdi_layer_handle == GDI_LAYER_EMPTY_HANDLE) && !g_vdorec_cntx.is_gdi_double_buffer_enable)
    {
        gdi_layer_create(
            0,
            0,
            LCD_HEIGHT,        
            LCD_WIDTH,        
            &g_vdorec_cntx.gdi_layer_handle);
        gdi_layer_push_and_set_active(g_vdorec_cntx.gdi_layer_handle);
        gdi_layer_get_buffer_ptr(&gdi_layer_buffer_ptr);
        gdi_layer_pop_and_restore_active();
    }
    //gdi_layer_free(g_vdorec_cntx.gdi_layer_handle);
    /* steal done */
	#endif

	#ifndef __VDOREC_FEATURE_MULTI_REGION_SUPPORT__
    if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE) 
    {
        /************ osd layer ************/
        /* create a double layer frame from outside memory */
        if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE)
        {
        	#ifdef __VDOREC_DOUBLE_BUFFER_SUPPORT__
            if (g_vdorec_cntx.is_gdi_double_buffer_enable)
            {
                g_vdorec_cntx.osd_layer_buf_ptr = mmi_frm_scrmem_alloc_framebuffer(VDOREC_OSD_BUFFER_SIZE);
                
                gdi_layer_create_using_outside_memory(
                    0,
                    0,
                    g_vdorec_cntx.lcd_width,
                    g_vdorec_cntx.lcd_height,
                    &g_vdorec_cntx.osd_layer_handle,
                    (PU8)g_vdorec_cntx.osd_layer_buf_ptr,
                    VDOREC_OSD_BUFFER_SIZE);

                mmi_vdorec_clear_osd_layer(g_vdorec_cntx.osd_layer_handle);
            }
            #else
            {
                g_vdorec_cntx.osd_layer_buf_ptr = mmi_frm_scrmem_alloc_framebuffer(VDOREC_OSD_BUFFER_SIZE);
                
                gdi_layer_create_cf_double_using_outside_memory(
                    GDI_COLOR_FORMAT_16,
                    0,
                    0,
                    g_vdorec_cntx.lcd_width,
                    g_vdorec_cntx.lcd_height,
                    &g_vdorec_cntx.osd_layer_handle,
                    (PU8)g_vdorec_cntx.osd_layer_buf_ptr,
                    VDOREC_OSD_BUFFER_SIZE,
                    (PU8)gdi_layer_buffer_ptr,
                    VDOREC_OSD_BUFFER_SIZE);
                
                gdi_layer_push_and_set_active(g_vdorec_cntx.osd_layer_handle);
                gdi_layer_clear(GDI_COLOR_TRANSPARENT);                
                gdi_layer_toggle_double();                
                gdi_layer_clear(GDI_COLOR_TRANSPARENT);                
                gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
                gdi_layer_pop_and_restore_active();
            }
			#endif
        }
        else
        {
            g_vdorec_cntx.osd_layer_handle = GDI_LAYER_EMPTY_HANDLE;
        }   

		#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
        if (g_vdorec_cntx.is_use_hw_rotate)
        {
            g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[0] = g_vdorec_cntx.app_mem_bufer;

            gdi_layer_create_using_outside_memory(
                0,
                0,
                LCD_HEIGHT,        
                LCD_WIDTH,        
                &g_vdorec_cntx.tmp_osd_layer_region_handle[0],   
                (PU8)g_vdorec_cntx.tmp_osd_layer_region_handle_ptr[0],
                (S32)VDOREC_OSD_BUFFER_SIZE);

            mmi_vdorec_clear_osd_layer(g_vdorec_cntx.tmp_osd_layer_region_handle[0]);          
        }
		#endif
    }
    #else
    {

		/* region 0 */
		mmi_vdorec_init_ui_region
			(
			&g_vdorec_osd_cntx.osd_layer_region.region_0,
			0,
			gdi_layer_buffer_ptr
			);
	
		/* region 1 */
		#ifndef __MMI_VIDEO_RECORDER_SLIM__
		mmi_vdorec_init_ui_region
			(
			&g_vdorec_osd_cntx.osd_layer_region.region_1,
			1,
			gdi_layer_buffer_ptr
			);
		#else
		#ifdef __VDOREC_FEATURE_HORIZONTAL_VIEW__
		mmi_vdorec_init_ui_region
			(
			&g_vdorec_osd_cntx.osd_layer_region.region_1,
			1,
			gdi_layer_buffer_ptr
			);
		
		#endif
		#endif
		
		/* region 2 */
		if ((g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_THREE) ||
			(g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_FOUR))
		{
			mmi_vdorec_init_ui_region
				(
				&g_vdorec_osd_cntx.osd_layer_region.region_2,
				2,
				gdi_layer_buffer_ptr
				);
		}
		else
		{
			g_vdorec_cntx.osd_layer_region_handle[2] = GDI_LAYER_EMPTY_HANDLE;
		}
	
		/* region 3 */
		#ifndef __MMI_VIDEO_RECORDER_SLIM__
		if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_FOUR)
		{
			mmi_vdorec_init_ui_region
				(
				&g_vdorec_osd_cntx.osd_layer_region.region_3,
				3,
				gdi_layer_buffer_ptr
				);
		}
		else
		#endif	
		{
			g_vdorec_cntx.osd_layer_region_handle[3] = GDI_LAYER_EMPTY_HANDLE;
		}


		#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
        if (g_vdorec_cntx.is_use_hw_rotate)
        {
            /*HW rotate tmp layer*/
            total_pre_region_size = 0;
			
            /* region 0 */
			mmi_vdorec_init_ui_rotate
				(
				&g_vdorec_osd_cntx.osd_layer_region.region_0,
				0
				);
            
            /* region 1 */
			#ifndef __MMI_VIDEO_RECORDER_SLIM__
			mmi_vdorec_init_ui_rotate
				(
				&g_vdorec_osd_cntx.osd_layer_region.region_1,
				1
				);
			#else
			#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
			mmi_vdorec_init_ui_rotate
				(
				&g_vdorec_osd_cntx.osd_layer_region.region_1,
				1
				);
		
			#endif
			#endif
			
            
            /* region 2 */
            if ((g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_THREE) ||
            (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_FOUR))
            {
                mmi_vdorec_init_ui_rotate
					(
					&g_vdorec_osd_cntx.osd_layer_region.region_2,
					2
					);
            }
            else
            {
                g_vdorec_cntx.tmp_osd_layer_region_handle[2] = GDI_LAYER_EMPTY_HANDLE;
            }
                
            /* region 3 */
			#ifndef __MMI_VIDEO_RECORDER_SLIM__
            if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_FOUR)
            {
                mmi_vdorec_init_ui_rotate
					(
					&g_vdorec_osd_cntx.osd_layer_region.region_3,
					3
					);                
            }
            else
			#endif	
            {
                g_vdorec_cntx.tmp_osd_layer_region_handle[3] = GDI_LAYER_EMPTY_HANDLE;
            }
        }
		#endif
        
    }
	#endif

	#ifdef __VDOREC_FEATURE_MULTI_REGION_SUPPORT__
    if (g_vdorec_cntx.osd_layer_region_count != VDOREC_OSD_LAYER_COUNT_ONE) 
    {
        /*init region layer mask*/
        g_vdorec_cntx.osd_layer_region_mask[0] = 0;

        panel_ptr = &g_vdorec_osd_cntx.panel;
        g_vdorec_cntx.ev_draw_layer = mmi_vdorec_get_layer_handle_by_position(panel_ptr->ev.offset_x, panel_ptr->ev.offset_y, VDOREC_OSD_COMPONENT_EV | VDOREC_OSD_COMPONENT_CLEAR_EV);
        g_vdorec_cntx.zoom_draw_layer = mmi_vdorec_get_layer_handle_by_position(panel_ptr->zoom.offset_x, panel_ptr->zoom.offset_y, VDOREC_OSD_COMPONENT_ZOOM | VDOREC_OSD_COMPONENT_CLEAR_ZOOM);
        g_vdorec_cntx.timer_draw_layer = mmi_vdorec_get_layer_handle_by_position(panel_ptr->timer.offset_x, panel_ptr->timer.offset_y, VDOREC_OSD_COMPONENT_TIMER | VDOREC_OSD_COMPONENT_CLEAR_TIMER);
        /*currently we make the state in front of timer, so they are the same layer*/
        g_vdorec_cntx.state_draw_layer = mmi_vdorec_get_layer_handle_by_position(panel_ptr->timer.offset_x, panel_ptr->timer.offset_y, VDOREC_OSD_COMPONENT_STATE);

        #ifdef __VDOREC_FEATURE_LIMIT_PROGRESS_BAR__
        if (mmi_vdorec_is_draw_progress_bar())
        {
            g_vdorec_cntx.progress_draw_layer = mmi_vdorec_get_layer_handle_by_position(panel_ptr->progress_bar.offset_x, panel_ptr->progress_bar.offset_y, VDOREC_OSD_COMPONENT_PROGRESS | VDOREC_OSD_COMPONENT_CLEAR_PROGRESS);
        }
        #endif
        sk_ptr = &g_vdorec_osd_cntx.softkey;
        g_vdorec_cntx.ck_draw_layer = mmi_vdorec_get_layer_handle_by_position(sk_ptr->icon_ck_pos.offset_x, sk_ptr->icon_ck_pos.offset_y, VDOREC_OSD_COMPONENT_SOFTKEY);
        g_vdorec_cntx.lsk_draw_layer = mmi_vdorec_get_layer_handle_by_position(sk_ptr->icon_lsk_pos.offset_x, sk_ptr->icon_lsk_pos.offset_y, VDOREC_OSD_COMPONENT_SOFTKEY);
        g_vdorec_cntx.rsk_draw_layer = mmi_vdorec_get_layer_handle_by_position(sk_ptr->icon_rsk_pos.offset_x, sk_ptr->icon_rsk_pos.offset_y, VDOREC_OSD_COMPONENT_SOFTKEY);     
        
        if (g_vdorec_osd_cntx.title.is_draw_app_name)
        {       
            g_vdorec_cntx.title_draw_layer = mmi_vdorec_get_layer_handle_by_position(g_vdorec_osd_cntx.title.rect.offset_x, g_vdorec_osd_cntx.title.rect.offset_y, VDOREC_OSD_COMPONENT_TITLE); 
        }
        
        g_vdorec_cntx.status_draw_layer = mmi_vdorec_get_layer_handle_by_position(g_vdorec_osd_cntx.status.video_size.offset_x, g_vdorec_osd_cntx.status.video_size.offset_y, VDOREC_OSD_COMPONENT_STATUS | VDOREC_OSD_COMPONENT_CLEAR_STATUS); 

		#ifndef __MMI_VIDEO_RECORDER_SLIM__
        g_vdorec_cntx.hint_draw_layer = mmi_vdorec_get_layer_handle_by_position(g_vdorec_osd_cntx.hint.rect.offset_x, g_vdorec_osd_cntx.hint.rect.offset_y, VDOREC_OSD_COMPONENT_HINT); 
		#endif
		
    }
    #else
    {
    	#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
        if (g_vdorec_cntx.is_use_hw_rotate)
        {
            /* if have HW rotator support, we will draw to a tmp buffer, then rotate to bg buffer */
            g_vdorec_cntx.ev_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
            g_vdorec_cntx.zoom_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
            g_vdorec_cntx.timer_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
            g_vdorec_cntx.state_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
            g_vdorec_cntx.rsk_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
            g_vdorec_cntx.lsk_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
            g_vdorec_cntx.ck_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
            g_vdorec_cntx.title_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
            g_vdorec_cntx.status_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
            g_vdorec_cntx.hint_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
            g_vdorec_cntx.progress_draw_layer = g_vdorec_cntx.tmp_osd_layer_region_handle[0];
        }
        #else
        {
            g_vdorec_cntx.ev_draw_layer = g_vdorec_cntx.osd_layer_handle;
            g_vdorec_cntx.zoom_draw_layer = g_vdorec_cntx.osd_layer_handle;
            g_vdorec_cntx.timer_draw_layer = g_vdorec_cntx.osd_layer_handle;
            g_vdorec_cntx.state_draw_layer = g_vdorec_cntx.osd_layer_handle;
            g_vdorec_cntx.rsk_draw_layer = g_vdorec_cntx.osd_layer_handle;
            g_vdorec_cntx.lsk_draw_layer = g_vdorec_cntx.osd_layer_handle;
            g_vdorec_cntx.ck_draw_layer = g_vdorec_cntx.osd_layer_handle;
            g_vdorec_cntx.title_draw_layer = g_vdorec_cntx.osd_layer_handle;
            
            g_vdorec_cntx.status_draw_layer = g_vdorec_cntx.osd_layer_handle;
            g_vdorec_cntx.hint_draw_layer = g_vdorec_cntx.osd_layer_handle;
            g_vdorec_cntx.progress_draw_layer = g_vdorec_cntx.osd_layer_handle;
            
        #ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
            //g_vdorec_cntx.del_draw_layer = g_vdorec_cntx.osd_layer_handle;
        #endif
        }
		#endif
    }
	#endif
    
    /* timer */
	#ifndef __MMI_VIDEO_RECORDER_SLIM__
    gdi_image_get_dimension_id(IMG_ID_VDOREC_TIME_COL, &col_width, &height);
    gdi_image_get_dimension_id(IMG_ID_VDOREC_TIME_NUMBER_0, &digit_width, &height);
	digit_width += 2;
	#else
	gdi_image_get_dimension_id(IMG_ID_VDOPLY_OSD_TIMER_COL, &col_width, &height);
    gdi_image_get_dimension_id(IMG_ID_VDOPLY_OSD_TIMER_0, &digit_width, &height);
	digit_width += 2;
	#endif
    g_vdorec_cntx.timer.offset_y = g_vdorec_osd_cntx.panel.timer.offset_y;

    g_vdorec_cntx.timer.hr_0_offset_x = g_vdorec_osd_cntx.panel.timer.offset_x;
    g_vdorec_cntx.timer.hr_1_offset_x = g_vdorec_cntx.timer.hr_0_offset_x + digit_width;
    g_vdorec_cntx.timer.col_0_offset_x = g_vdorec_cntx.timer.hr_1_offset_x + digit_width;
    g_vdorec_cntx.timer.min_0_offset_x = g_vdorec_cntx.timer.col_0_offset_x + col_width;
    g_vdorec_cntx.timer.min_1_offset_x = g_vdorec_cntx.timer.min_0_offset_x + digit_width;
    g_vdorec_cntx.timer.col_1_offset_x = g_vdorec_cntx.timer.min_1_offset_x + digit_width;
    g_vdorec_cntx.timer.sec_0_offset_x = g_vdorec_cntx.timer.col_1_offset_x + col_width;
    g_vdorec_cntx.timer.sec_1_offset_x = g_vdorec_cntx.timer.sec_0_offset_x + digit_width;

#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
    g_vdorec_cntx.touch_object = VDOREC_TOUCH_NONE;

    /* init touch region */

#ifdef __VDOREC_FEATURE_EV__
    /* ev inc */
    touch_p = &g_vdorec_cntx.touch_ev_inc;
    touch_p->offset_x = g_vdorec_osd_cntx.panel.ev_inc.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.panel.ev_inc.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_EV_INC, &touch_p->width, &touch_p->height);

    /* ev dec */
    touch_p = &g_vdorec_cntx.touch_ev_dec;
    touch_p->offset_x = g_vdorec_osd_cntx.panel.ev_dec.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.panel.ev_dec.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_EV_DEC, &touch_p->width, &touch_p->height);
#endif /* __VDOREC_FEATURE_EV__ */

#ifndef __MMI_VIDEO_RECORDER_SLIM__
#ifdef __VDOREC_FEATURE_ZOOM__ 
    /* zoom inc */
    touch_p = &g_vdorec_cntx.touch_zoom_inc;
    touch_p->offset_x = g_vdorec_osd_cntx.panel.zoom_inc.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.panel.zoom_inc.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_ZOOM_INC, &touch_p->width, &touch_p->height);

    /* zoom dec */
    touch_p = &g_vdorec_cntx.touch_zoom_dec;
    touch_p->offset_x = g_vdorec_osd_cntx.panel.zoom_dec.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.panel.zoom_dec.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_TOUCH_OSD_ZOOM_DEC, &touch_p->width, &touch_p->height);
#endif /* __VDOREC_FEATURE_EV__ */
#endif

    /***************** 1. video size *******************/
    
#ifdef __VDOREC_FEATURE_VIDEO_SIZE__
    touch_p = &g_vdorec_cntx.touch_video_size;
    touch_p->offset_x = g_vdorec_osd_cntx.status.video_size.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.status.video_size.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_VIDEO_SIZE_START + 1, &touch_p->width, &touch_p->height);
#endif

    /***************** 2. video qty ********************/
    
#ifndef __MMI_VIDEO_RECORDER_SLIM__
#ifdef __VDOREC_FEATURE_VIDEO_QTY__
    touch_p = &g_vdorec_cntx.touch_video_qty;
    touch_p->offset_x = g_vdorec_osd_cntx.status.video_qty.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.status.video_qty.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_VIDEO_QTY_START + 1, &touch_p->width, &touch_p->height);
#endif
#endif
    /***************** 3. night ************************/
    
#ifdef __VDOREC_FEATURE_NIGHT__
    touch_p = &g_vdorec_cntx.touch_night;
    touch_p->offset_x = g_vdorec_osd_cntx.status.night.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.status.night.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_NIGHT_START + 1, &touch_p->width, &touch_p->height);
#endif

    /***************** 4. wb ***************************/

#ifdef __VDOREC_FEATURE_WB__
    touch_p = &g_vdorec_cntx.touch_wb;
    touch_p->offset_x = g_vdorec_osd_cntx.status.wb.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.status.wb.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_WB_START + 1, &touch_p->width, &touch_p->height);
#endif

    /***************** 5. led highlight ****************/

#ifdef __VDOREC_FEATURE_LED_HIGHLIGHT__
    touch_p = &g_vdorec_cntx.touch_led_highlight;
    touch_p->offset_x = g_vdorec_osd_cntx.status.led_highlight.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.status.led_highlight.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_LED_HIGHLIGHT_START + 1, &touch_p->width, &touch_p->height);
#endif

    /***************** 6. record audio *****************/

#ifdef __VDOREC_FEATURE_RECORD_AUD__
    touch_p = &g_vdorec_cntx.touch_record_aud;
    touch_p->offset_x = g_vdorec_osd_cntx.status.record_aud.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.status.record_aud.offset_y;
    touch_p->is_press = FALSE;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_OSD_RECORD_AUD_START + 1, &touch_p->width, &touch_p->height);
#endif

#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
    touch_p = &g_vdorec_cntx.touch_del;
    touch_p->is_press = FALSE;
    touch_p->offset_x = g_vdorec_osd_cntx.panel.zoom.offset_x;
    touch_p->offset_y = g_vdorec_osd_cntx.panel.zoom.offset_y;
    gdi_image_get_dimension_id(IMG_ID_VDOREC_SK_DELETE, &touch_p->width, &touch_p->height);
#endif /* __VDOREC_FEATURE_PREVIEW_SAVED_FILE__ */

#endif /* __VDOREC_FEATURE_TOUCH_SCREEN__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_style_text
 * DESCRIPTION
 *  draw styled text
 * PARAMETERS
 *  str             [IN]        String
 *  offset_x        [IN]        Offset x
 *  offset_y        [IN]        Offset y
 *  truncate_width  [IN]        Tauncate width
 *  style_txt       [IN]        Text style
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_style_text(CHAR * str, S32 offset_x, S32 offset_y, S32 truncate_width, video_style_text_struct *style_txt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_STYLE_TEXT);

    #if defined (__MMI_BIDI_ALG__)
    if(mmi_fe_get_r2l_state())
    {
        offset_x += gui_get_string_width((UI_string_type) str);
    }
    #endif

    if (style_txt->style == VIDEO_TEXT_STYLE_NORMAL)
    {
        if (truncate_width != 0)
        {
            gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
            gui_print_truncated_text(offset_x, offset_y, truncate_width, (UI_string_type)str);
        }
        else
        {
            gui_move_text_cursor(offset_x, offset_y);
            gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
            gui_print_text((UI_string_type) str);
        }
    }
    else if (style_txt->style == VIDEO_TEXT_STYLE_BORDER)
    {
        if (truncate_width != 0)
        {        
            gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
            gui_set_text_border_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
            gui_print_truncated_borderd_text(offset_x, offset_y, truncate_width, (UI_string_type)str);
        }
        else
        {
            gui_move_text_cursor(offset_x, offset_y);
            gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
            gui_set_text_border_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
            gui_print_bordered_text((UI_string_type) str);
        }
    }
    else if (style_txt->style == VIDEO_TEXT_STYLE_SHADOW)
    {
        if (truncate_width != 0)
        {            
            gui_set_text_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
            gui_print_truncated_text(offset_x + 1, offset_y + 1, truncate_width, (UI_string_type)str);
            
            gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
            gui_print_truncated_text(offset_x, offset_y, truncate_width, (UI_string_type)str);
        }
        else
        {
            gui_move_text_cursor(offset_x + 1, offset_y + 1);
            gui_set_text_color(gui_color(style_txt->style_r, style_txt->style_g, style_txt->style_b));
            gui_print_text((UI_string_type) str);

            gui_move_text_cursor(offset_x, offset_y);
            gui_set_text_color(gui_color(style_txt->r, style_txt->g, style_txt->b));
            gui_print_text((UI_string_type) str);
        }
    }
    else
    {
        MMI_ASSERT(0);
    }

}

#ifndef __VDOREC_HIDE_HINT__
/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_hide_hint
 * DESCRIPTION
 *  Hide hint
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_hide_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_HIDE_HINT);

    mmi_vdorec_set_hint(NULL, NULL, 0);
    mmi_vdorec_draw_osd(VDOREC_OSD_COMPONENT_HINT);
    mmi_vdorec_blt_screen();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_hint
 * DESCRIPTION
 *  enter save screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_hint(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 str1_width;
    S32 str1_height;
    S32 str2_width;
    S32 str2_height;
    S32 str1_offset_x;
    S32 str1_offset_y;
    S32 str2_offset_x;
    S32 str2_offset_y;
    S32 spacing;
    S32 layer_offset_x;
    S32 layer_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_DRAW_HINT, g_vdorec_osd_cntx.hint.is_show);

    if (!g_vdorec_osd_cntx.hint.is_show)
    {
        return;
    }

    gdi_layer_push_and_set_active(g_vdorec_cntx.hint_draw_layer);

    gdi_layer_get_position(&layer_offset_x, &layer_offset_y);

    gdi_draw_solid_rect(
        g_vdorec_osd_cntx.hint.rect.offset_x - layer_offset_x, 
        g_vdorec_osd_cntx.hint.rect.offset_y - layer_offset_y, 
        g_vdorec_osd_cntx.hint.rect.offset_x + g_vdorec_osd_cntx.hint.rect.width - layer_offset_x, 
        g_vdorec_osd_cntx.hint.rect.offset_y + g_vdorec_osd_cntx.hint.rect.height - layer_offset_y, 
        GDI_COLOR_TRANSPARENT);

    if (g_vdorec_cntx.hint1_buf != NULL)
    {
        gui_measure_string((UI_string_type) g_vdorec_cntx.hint1_buf, &str1_width, &str1_height);

        if (g_vdorec_cntx.hint2_buf == NULL)
        {
            str1_offset_x = (str1_width < g_vdorec_osd_cntx.hint.rect.width)?
                            ((g_vdorec_osd_cntx.hint.rect.width - str1_width) >> 1):
                            0;

            str1_offset_y = (g_vdorec_osd_cntx.hint.rect.height - str1_height) >> 1;
        }
        else
        {
            gui_measure_string((UI_string_type) g_vdorec_cntx.hint2_buf, &str2_width, &str2_height);
            
            str1_offset_x = (str1_width < g_vdorec_osd_cntx.hint.rect.width)?
                            ((g_vdorec_osd_cntx.hint.rect.width - str1_width) >> 1):
                            0;

            /* use string1_height only becuz string 2 is usually longer and may be truncated in some cases */
            spacing = g_vdorec_osd_cntx.hint.rect.height - (str1_height << 1); 
            spacing = (spacing > 0) ? (spacing / 3 + 1) : 0;

            str1_offset_y = spacing;

            str2_offset_x = (str2_width < g_vdorec_osd_cntx.hint.rect.width)?
                            ((g_vdorec_osd_cntx.hint.rect.width - str2_width) >> 1):
                            0;
            str2_offset_y = spacing * 2 + 1 + str1_height;
        }

        str1_offset_x += g_vdorec_osd_cntx.hint.rect.offset_x - layer_offset_x;
        str1_offset_y += g_vdorec_osd_cntx.hint.rect.offset_y - layer_offset_y;
        str2_offset_x += g_vdorec_osd_cntx.hint.rect.offset_x - layer_offset_x;
        str2_offset_y += g_vdorec_osd_cntx.hint.rect.offset_y - layer_offset_y;

        gdi_layer_reset_clip();
        gui_reset_text_clip();

        mmi_vdorec_draw_style_text(
            g_vdorec_cntx.hint1_buf,
            str1_offset_x,
            str1_offset_y,
            g_vdorec_osd_cntx.hint.rect.width,
            &g_vdorec_osd_cntx.hint.style_text);

        if (g_vdorec_cntx.hint2_buf != NULL)
        {
            mmi_vdorec_draw_style_text(
                g_vdorec_cntx.hint2_buf,
                str2_offset_x,
                str2_offset_y,
                g_vdorec_osd_cntx.hint.rect.width,
                &g_vdorec_osd_cntx.hint.style_text);
        }

        if (g_vdorec_cntx.fade_time != 0)
        {
            gui_start_timer(HINT_POPUP_FADE_TIME, mmi_vdorec_hide_hint);
        }

    }

    gdi_layer_pop_and_restore_active();

	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_merge_blt_rgn(
            g_vdorec_osd_cntx.hint.rect.offset_x, 
            g_vdorec_osd_cntx.hint.rect.offset_y, 
            g_vdorec_osd_cntx.hint.rect.width, 
            g_vdorec_osd_cntx.hint.rect.height);
    }
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_set_hint
 * DESCRIPTION
 *  set hint string
 * PARAMETERS
 *  hint_str1       [IN]        String 1
 *  hint_str2       [IN]        String 2
 *  fade_time       [IN]        Hint fade out time
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_set_hint(CHAR * hint_str1, CHAR * hint_str2, U16 fade_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_VDOREC_SET_HINT);

    /* clear buffer */
    //memset(g_vdorec_cntx.hint1_buf, 0, VDOREC_HINT_BUF_SIZE);
    //memset(g_vdorec_cntx.hint2_buf, 0, VDOREC_HINT_BUF_SIZE);

	*((U16*)(g_vdorec_cntx.hint1_buf)) = 0;
    *((U16*)(g_vdorec_cntx.hint2_buf)) = 0;

    if (hint_str1 != NULL)
    {
        mmi_ucs2ncpy((CHAR *) g_vdorec_cntx.hint1_buf, (CHAR *) hint_str1, VDOREC_HINT_CHAR_COUNT);
    }

    if (hint_str2 != NULL)
    {
        mmi_ucs2ncpy((CHAR *) g_vdorec_cntx.hint2_buf, (CHAR *) hint_str2, VDOREC_HINT_CHAR_COUNT);
    }

    g_vdorec_cntx.fade_time = fade_time;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_vdorec_draw_osd
 * DESCRIPTION
 *  draw osd, currently, all the component is in osd layer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_vdorec_draw_osd(U32 component)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __VDOREC_USING_BLT_REGION__
    if (g_vdorec_cntx.is_use_blt_region)
    {
        mmi_vdorec_set_merge_region(0, 0, 0, 0);
    }
	#endif

	#ifndef __VDOREC_FEATURE_MULTI_REGION_SUPPORT__
    if (g_vdorec_cntx.osd_layer_region_count == VDOREC_OSD_LAYER_COUNT_ONE)
    {
        gdi_layer_push_and_set_active(g_vdorec_cntx.osd_layer_handle);
        
        /* toggle double buffer */
        if (gdi_layer_is_double(g_vdorec_cntx.osd_layer_handle))
        {
            gdi_layer_toggle_double();

			#ifndef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
            if (!g_vdorec_cntx.is_use_hw_rotate)
            {
                /*for 6253 serial, we will use tmp buffer for drawing, this copy is useless,
                  so remove this to update performance*/
                gdi_layer_copy_double();
            }
			#endif
        }

        gdi_layer_pop_and_restore_active();
    }
    #else    
    {
		U32 i = 0;
		
        /*prepare the region 0 OSD buffer*/
		/*this algo will have some error, and need to modify much, so I just copy*/
        for (i = 0; i< g_vdorec_cntx.osd_layer_region_count; i++)
        {
            if ((g_vdorec_cntx.osd_layer_region_mask[i] & component)
				&& (g_vdorec_cntx.osd_layer_region_handle[i] != GDI_LAYER_EMPTY_HANDLE))
            {

				#ifdef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
                if (g_vdorec_cntx.is_use_hw_rotate)
                {
                    g_vdorec_cntx.is_osd_layer_updated[i] = MMI_TRUE;
                }
                #else
                {
                    g_vdorec_cntx.is_osd_layer_updated[i] = MMI_FALSE;
                }
				#endif
				
                gdi_layer_push_and_set_active(g_vdorec_cntx.osd_layer_region_handle[i]);
                
                if (gdi_layer_is_double(g_vdorec_cntx.osd_layer_region_handle[i]))
                {
                    gdi_layer_toggle_double();

					#ifndef __VDOREC_ROTATE_OSD_FOR_HW_ROTATOR__
                    if (!g_vdorec_cntx.is_use_hw_rotate)
                    {
                        /*for 6253 serial, we will use tmp buffer for drawing, this copy is useless,
                        			so remove this to update performance*/
                        gdi_layer_copy_double();
                    }
					#endif
                }  
                
                gdi_layer_pop_and_restore_active();
            }
            else
            {
                g_vdorec_cntx.is_osd_layer_updated[i] = MMI_FALSE;
            }
        }
    }
	#endif

	gui_lock_double_buffer();

	#ifdef __VDOREC_FEATURE_PREVIEW_SAVED_FILE__
	if (SCR_ID_VDOREC_SAVED_PREVIEW == mmi_frm_scrn_get_active_id())
    {
        if (component & VDOREC_OSD_COMPONENT_TITLE)
        {
            mmi_vdorec_draw_title();
        }

        if (component & VDOREC_OSD_COMPONENT_TIMER)
        {
            mmi_vdorec_draw_panel_timer();
        }

        if (component & VDOREC_OSD_COMPONENT_SOFTKEY)
        {
            mmi_vdorec_draw_softkey();
        }

        if (component & VDOREC_OSD_COMPONENT_DELETE)
        {
            mmi_vdorec_draw_softkey();
        }
    }
    else
	#endif	
    {
        /* clear*/
		
		#ifndef __MMI_VIDEO_RECORDER_SLIM__
        if (component & VDOREC_OSD_COMPONENT_CLEAR_STATUS)
        {
            mmi_vdorec_clear_status();
        }
		#endif

        if (component & VDOREC_OSD_COMPONENT_CLEAR_TIMER)
        {
            mmi_vdorec_clear_timer();
        }

		#ifndef __MMI_VIDEO_RECORDER_SLIM__
        if (component & VDOREC_OSD_COMPONENT_CLEAR_PROGRESS)
        {
            mmi_vdorec_clear_panel_progress_bar();
        }
		#endif

		#ifndef __MMI_VIDEO_RECORDER_SLIM__
        if (component & VDOREC_OSD_COMPONENT_CLEAR_EV)
        {
            mmi_vdorec_clear_ev();
        }
		#endif

		#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
        if (component & VDOREC_OSD_COMPONENT_CLEAR_ZOOM)
        {
            mmi_vdorec_clear_zoom();
        }
		#endif

        /* drawing */
		
		#ifndef __MMI_VIDEO_RECORDER_SLIM__
        if (component & VDOREC_OSD_COMPONENT_STATUS)
        {
            mmi_vdorec_draw_status();
        }
		#endif

		#ifndef __MMI_VIDEO_RECORDER_SLIM__
        if (component&VDOREC_OSD_COMPONENT_HINT)
        {
            mmi_vdorec_draw_hint();
        }
		#endif

		#ifndef __MMI_VIDEO_RECORDER_SLIM__
        if (component&VDOREC_OSD_COMPONENT_STATE)
        {
            mmi_vdorec_draw_panel_state();
        }
		#endif

		#ifndef __MMI_VIDEO_RECORDER_SLIM__
        if (component&VDOREC_OSD_COMPONENT_EV)
        {
            mmi_vdorec_draw_panel_ev();
        }
		#endif

		#ifdef __VDOREC_FEATURE_TOUCH_SCREEN__
        if (component&VDOREC_OSD_COMPONENT_ZOOM)
        {
            mmi_vdorec_draw_panel_zoom();
        }
		#endif
        
        if (component&VDOREC_OSD_COMPONENT_SOFTKEY)
        {
            mmi_vdorec_draw_softkey();
        }

		#ifndef __MMI_VIDEO_RECORDER_SLIM__
        if (component&VDOREC_OSD_COMPONENT_TITLE)
        {
            mmi_vdorec_draw_title();
        }
		#endif

		#ifndef __MMI_VIDEO_RECORDER_SLIM__
        if (component&VDOREC_OSD_COMPONENT_PROGRESS)
        {
            mmi_vdorec_draw_panel_progress_bar((U8)g_vdorec_cntx.progress);
        }
		#endif
        
        if (component&VDOREC_OSD_COMPONENT_TIMER)
        {
            mmi_vdorec_draw_panel_timer();
        }
    }    
	gui_unlock_double_buffer();
}



/*****************************************************************************
* FUNCTION
*  mmi_vdorec_query_info_table
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_vdorec_query_info_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_camera_sensor_general_info cap_info;
	int idx = 0;
	int temp_idx = 0;
	U16 wb = 0;
	U16 effect = 0;
	MMI_BOOL is_wb_manual_item = MMI_FALSE;
	MMI_BOOL is_no_effect_item = MMI_FALSE;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mdi_video_rec_query_support_info(MDI_CAMERA_SETTING_WB, &cap_info);
	g_vdorec_cntx.wb_item = cap_info.item_count;
    for (idx = 0; idx < cap_info.item_count; idx++)
    {
    	is_wb_manual_item = MMI_FALSE;
        wb = cap_info.support_item[idx];
	
        switch (wb)
        {
            case MDI_CAMERA_WB_AUTO:
                wb = VDOREC_SETTING_WB_AUTO;
                break;

            case MDI_CAMERA_WB_DAYLIGHT:
                wb = VDOREC_SETTING_WB_DAYLIGHT;
                break;

            case MDI_CAMERA_WB_TUNGSTEN:
                wb = VDOREC_SETTING_WB_TUNGSTEN;
                break;

            case MDI_CAMERA_WB_FLUORESCENT:
                wb = VDOREC_SETTING_WB_FLUORESCENT;
                break;

            case MDI_CAMERA_WB_CLOUD:
                wb = VDOREC_SETTING_WB_CLOUD;
                break;

            case MDI_CAMERA_WB_INCANDESCENCE:
                wb = VDOREC_SETTING_WB_INCANDESCENCE;
                break;
			case MDI_CAMERA_WB_MANUAL:
				g_vdorec_cntx.wb_item -= 1;
				is_wb_manual_item = MMI_TRUE;
				break;

            default:
                wb = VDOREC_SETTING_WB_AUTO;
                break;
        }
		
		if(!is_wb_manual_item)
		{
			support_wb_item[temp_idx]= wb;
			temp_idx++;
		}
    }

	temp_idx = 0;
	mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_EFFECT, &cap_info);
	g_vdorec_cntx.effect_count_item = cap_info.item_count;
	for (idx = 0; idx < cap_info.item_count; idx++)
    {
    	is_no_effect_item = MMI_FALSE;
        effect = cap_info.support_item[idx];
        switch (effect)
        {
            case MDI_CAMERA_EFFECT_NOMRAL:
                effect = VDOREC_SETTING_EFFECT_NORMAL;
                break;
            case MDI_CAMERA_EFFECT_GRAYSCALE:
                effect = VDOREC_SETTING_EFFECT_GRAYSCALE;
                break;

            case MDI_CAMERA_EFFECT_SEPIA:
               effect = VDOREC_SETTING_EFFECT_SEPIA;
                break;

            case MDI_CAMERA_EFFECT_SEPIA_GREEN:
                effect = VDOREC_SETTING_EFFECT_SEPIA_GREEN;
                break;

            case MDI_CAMERA_EFFECT_SEPIA_BLUE:
                effect = VDOREC_SETTING_EFFECT_SEPIA_BLUE;
                break;

            case MDI_CAMERA_EFFECT_COLOR_INVERT:
                effect = VDOREC_SETTING_EFFECT_COLOR_INVERT;
                break;

            case MDI_CAMERA_EFFECT_GRAY_INVERT:
                effect = VDOREC_SETTING_EFFECT_GRAY_INVERT;
                break;

            case MDI_CAMERA_EFFECT_BLACKBOARD:
                effect = VDOREC_SETTING_EFFECT_BLACKBOARD;
                break;

            case MDI_CAMERA_EFFECT_WHITEBOARD:
                effect = VDOREC_SETTING_EFFECT_WHITEBOARD;
                break;

            case MDI_CAMERA_EFFECT_COPPER_CARVING:
                effect = VDOREC_SETTING_EFFECT_COPPER_CARVING;
                break;

            case MDI_CAMERA_EFFECT_BLUE_CARVING:
                effect = VDOREC_SETTING_EFFECT_BLUE_CARVING;
                break;

            case MDI_CAMERA_EFFECT_EMBOSSMENT:
                effect = VDOREC_SETTING_EFFECT_EMBOSSMENT;
                break;

            case MDI_CAMERA_EFFECT_CONTRAST:
                effect = VDOREC_SETTING_EFFECT_CONTRAST;
                break;

            case MDI_CAMERA_EFFECT_JEAN:
                effect = VDOREC_SETTING_EFFECT_JEAN;
                break;

            case MDI_CAMERA_EFFECT_SKETCH:
                effect = VDOREC_SETTING_EFFECT_SKETCH;
                break;

            case MDI_CAMERA_EFFECT_OIL:
                effect = VDOREC_SETTING_EFFECT_OIL;
                break;

            default:
                g_vdorec_cntx.effect_count_item -= 1;
				is_no_effect_item = MMI_TRUE;
                break;

        }
		if(!is_no_effect_item)
		{
			support_effect_item[temp_idx]= effect;
			temp_idx++;
		}
    }

}


#ifdef __MMI_AP_DCM_VDOREC__
#pragma arm section rodata, code
#endif



#endif /* __MMI_VIDEO_RECORDER__ && __MMI_CAMCORDER__ */ 
