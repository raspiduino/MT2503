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
 * USBDevice.c
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   This file is for mmi configure usb device
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
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifdef __MMI_USB_SUPPORT__
#ifndef __COSMOS_MMI_PACKAGE__


#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "FileMgrSrvGProt.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "NotificationGprot.h"
#include "stack_config.h"
#include "mmi_rp_app_charger_def.h"
#include "wgui_categories_util.h"
#include "wgui_categories_popup.h"
#include "wgui_categories.h"
#include "wgui_softkeys.h"
#include "gui_typedef.h"
#include "GlobalResDef.h"
#include "custom_events_notify.h"
#include "GlobalConstants.h"
#include "mmi_frm_history_gprot.h"
#include "device.h"
#include "uart_sw.h"
#include "EngineerModeResDef.h"
#include "CustDataRes.h"
#include "mmi_rp_app_idle_def.h"
#include "IdleAppResDef.h"
#include "PhoneBookGprot.h"
#include "SettingGprots.h"
#include "PowerOnChargerProt.h"
#include "FMRadioProt.h"
#ifdef __MMI_ENGINEER_MODE__
#include "mmi_rp_app_engineermode1_def.h"
#endif 
#ifdef __MMI_WEBCAM__
#include "WebcamProt.h"
#endif
#include "ucmgprot.h"
#include "ucmsrvgprot.h"
#include "gpiosrvgprot.h"

#include "menucuigprot.h"
#include "BootupSrvGprot.h"
#include "ShutdownSrvGprot.h"
#include "IdleGprot.h"
#include "AlarmFrameworkProt.h"
#include "NwUsabSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"

#ifdef __DM_LAWMO_SUPPORT__
#include "DMSrvGprot.h"
#endif
#if defined(__J2ME__) && defined(__USB_COM_PORT_ENABLE__) && defined(__OP01__)
#include "Jvm_interface.h"
#endif
#ifdef __USB_TETHERING__
#include "TetheringSrvGProt.h"
#endif

/* USB Device Headder Files */
#include "USBDeviceGprot.h"
#include "USBDeviceDefs.h"
#include "USBSrvIprot.h"
#include "USBSrvGprot.h"

#include "Mmi_frm_scenario_gprot.h"
#include "mmi_rp_app_usbmmi_def.h"
#include "mmi_rp_app_restore_def.h"
#include "SmsAppSetting.h"
#ifdef __MMI_HF_SUPPORT__
#include "UcmBTSrvGprot.h"
#endif /* __MMI_HF_SUPPORT__ */
#define MMI_USB_MENU_CUI

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef
*****************************************************************************/

/***************************************************************************** 
* Extern Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Functions
*****************************************************************************/


/***************************************************************************** 
* Local Functions
*****************************************************************************/
static void mmi_usb_config_first_page(U8 mode, U8 owner);

static void mmi_usb_entry_progress_screen(void);
static void mmi_usb_close_progress_screen(void);

//static MMI_BOOL mmi_usb_permit_usb_cfg_screen_display(void);
static MMI_BOOL mmi_usb_permit_usb_cfg_screen_display_notify(mmi_scenario_id scen_id, void *arg);
//static MMI_BOOL mmi_usb_permit_usb_cfg_screen_display_test(void);
//static MMI_BOOL mmi_usb_permit_usb_cfg_screen_display_notify_dummy(mmi_scenario_id scen_id, void *arg);

/* Screen group*/
static void mmi_usb_enter_normal_group(void);
static MMI_ID mmi_usb_get_normal_group(void);
static MMI_ID mmi_usb_get_normal_group_id(void);
static void mmi_usb_close_normal_group(void);
static mmi_ret mmi_usb_normal_group_proc(mmi_event_struct *param);
static void mmi_usb_init_detect_query_list(MMI_ID menu_id);
static void mmi_usb_entry_usb_detect_query_scrn_int(void);
static mmi_ret mmi_usb_detect_query_scrn_proc (mmi_event_struct *param);
static void mmi_usb_entry_usb_detect_query_scrn(void);
static void mmi_usb_entry_progress_screen_int(void);
static mmi_ret mmi_usb_progress_leave_proc(mmi_event_struct *param);

static void mmi_usb_enter_detect_query_list(void);
static void mmi_usb_query_list_select_hdlr(cui_menu_event_struct *event);
static void mmi_usb_close_detect_query_list(void);
#if 0
/* under construction !*/
#endif
#ifdef __USB_IN_NORMAL_MODE__
static MMI_BOOL mmi_usb_need_to_reboot(void);
#endif

#ifdef __MMI_WEBCAM__
static void mmi_usb_config_webcam(void);
static void mmi_usb_exit_webcam(void);
#endif
static void mmi_usb_display_popup(U16 string, mmi_event_notify_enum type);

#ifdef __USB_TETHERING__
extern void mmi_tethering_usb_launch(void);
#endif
//extern void nvram_get_ps(kal_uint8 *port, kal_uint32 *baudrate);
#ifdef WAP_SUPPORT 
extern int wap_is_ready(void);
#endif
#ifdef MMS_SUPPORT
extern int mma_is_ready_for_usb(void);
#endif

static void mmi_usb_ms_cfg_success_notify(void);
static mmi_ret mmi_usb_ms_cfg_success_popup_cb(mmi_event_struct *evt);

#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_IME_MEMORY_CARD_SUPPORT__) || defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
static void mmi_usb_shutdown_timer_hdlr(void);
#endif
static void mmi_usb_ms_config_timeout_hdlr(void);
static void mmi_usb_mtp_config_timeout_hdlr(void);
static void mmi_usb_enter_waiting_screen(void);
static void mmi_usb_waiting_screen_key_handler(void);
static MMI_BOOL mmi_usb_ms_mtp_config_pre_check(U8 mode);
#ifdef __J2ME__
extern MMI_BOOL mmi_sat_is_group_active(void);
#endif
/***************************************************************************** 
* Local Variable
*****************************************************************************/
MMI_USB_CONTEXT g_mmi_usb_cntx;
MMI_USB_CONTEXT *mmi_usb_ptr = &g_mmi_usb_cntx;

/* USB split revise*/
/*****************************************************************************
 * FUNCTION
 *  mmi_permit_usb_cfg_screen_display
 * DESCRIPTION
 *  This function check the if usb config screen display allowed or not.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: T/F(?)
 *****************************************************************************/
static MMI_BOOL mmi_permit_usb_cfg_screen_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_NORMAL) &&
        (!srv_bootup_is_completed() || 
#ifdef __MMI_FILE_MANAGER__
        srv_fmgr_async_is_busy() ||
#endif
        mmi_phb_check_processing() ||
#ifdef __MMI_TELEPHONY_SUPPORT__
        (srv_sim_ctrl_get_unavailable_cause(MMI_SIM1) == SRV_SIM_CTRL_UA_CAUSE_CHV1_BLOCKED) ||
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif    	
#endif
    #if defined(__DM_LAWMO_SUPPORT__)
        srv_dm_lawmo_is_locked() ||
    #endif
    #ifdef __J2ME__
        mmi_sat_is_group_active() ||
    #endif
#ifdef __SMS_CLOUD_SUPPORT__
        mmi_sms_check_cloud_processing()||
#endif   
        srv_shutdown_is_running())) 
    {
        MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_USB_CONF_SCR_NOT_ALLOW_FALSE);
        return MMI_FALSE;
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_USB_CONF_SCR_NOT_ALLOW_TURE);
        return MMI_TRUE;
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
#endif
static MMI_BOOL mmi_usb_permit_usb_cfg_screen_display_notify(mmi_scenario_id scen_id, void *arg)
{
    srv_usb_status_enum usb_state = srv_usb_get_status();

    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_USB_PERMIT_USB_CFG_SCREEN_DISPLAY_NOTIFY, usb_state);

    if (usb_state == SRV_USBSTATUS_PLUGIN ||
        (usb_state == SRV_USBSTATUS_PLUGIN && srv_usb_is_connected())
    #ifdef __USB_IN_NORMAL_MODE__
        || srv_usb_is_leaving_ms_mode()
    #endif
        )
    {
            if ((srv_bootup_get_booting_mode() != SRV_BOOTUP_MODE_NORMAL &&
                  srv_bootup_is_completed()) ||
                  mmi_permit_usb_cfg_screen_display() == MMI_TRUE)
            {
                srv_usb_unblock_event(EVT_ID_USB_PERMIT_CFG);
                return MMI_TRUE;
            }
            else
            {
                srv_usb_block_event(EVT_ID_USB_PERMIT_CFG);
                return MMI_FALSE;
            }
    }
    else
    {
        return MMI_FALSE;
    }    
}
/*
static MMI_BOOL mmi_usb_permit_usb_cfg_screen_display_notify_dummy(mmi_scenario_id scen_id, void *arg)
{
    return MMI_TRUE;
}
*/
/*****************************************************************************
 * FUNCTION
 *  UsbDetectIndHdlr
 * DESCRIPTION
 *  This function is usb detect indication event handler
 *  
 *  PARAMETERS: void
 *  info        [?]     
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
mmi_ret mmi_usb_handle_query_permit_show(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_show_icon(STATUS_ICON_USB);
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_NON_TONE, 
    mmi_usb_permit_usb_cfg_screen_display_notify, NULL);
    return MMI_RET_OK;    
}

/* USB split revise*/
/*****************************************************************************
 * FUNCTION
 *  mmi_usb_handle_query_permit_pre_check
 * DESCRIPTION
 *  
 *  
 *  PARAMETERS: void
 *  info        [?]     
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
mmi_ret mmi_usb_handle_query_permit_pre_check(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_status_icon_bar_show_icon(STATUS_ICON_USB);
    ret = mmi_permit_usb_cfg_screen_display();
    if (ret)
    {
        srv_usb_unblock_event(EVT_ID_USB_PERMIT_CFG_PRE_CHECK);
    }
    else
    {
        srv_usb_block_event(EVT_ID_USB_PERMIT_CFG_PRE_CHECK);
    }

    return MMI_RET_OK;
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
    #ifdef __MMI_PICT_BRIDGE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_PICT_BRIDGE_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_WEBCAM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_WEBCAM__ */ 
/* under construction !*/
    #if defined(__J2ME__) && defined(__USB_COM_PORT_ENABLE__) && defined(__OP01__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
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

/*****************************************************************************
 * FUNCTION
 *  EntryUsbDetectQueryScr
 * DESCRIPTION
 *  This function is to display "Usb Config:" screen as received USB_DETECT_IND
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: none(?)
 *****************************************************************************/
mmi_ret mmi_usb_handle_plug_in(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_USB_HANDLE_PLUG_IN);

    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
    mmi_usb_enter_normal_group();
    mmi_usb_entry_usb_detect_query_scrn();
    return MMI_RET_OK;
}

static mmi_ret mmi_usb_detect_query_scrn_proc (mmi_event_struct *param)
{
    switch(param->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            mmi_usb_entry_usb_detect_query_scrn_int();
            break;

        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            srv_usb_set_status(SRV_USBSTATUS_IGNORED);
            break;

        case EVT_ID_WGUI_LSK_CLICK:
        case EVT_ID_WGUI_CSK_CLICK:
            UsbDetectScrLskHdlr();
            return MMI_RET_KEY_HANDLED;

        case EVT_ID_WGUI_RSK_CLICK:
            UsbDetectScrRskHdlr();
            return MMI_RET_KEY_HANDLED;

        case EVT_ID_ON_KEY:
            {
                mmi_frm_key_evt_struct *p = (mmi_frm_key_evt_struct *)param;
                if (p->key_code == KEY_ENTER && p->key_type == KEY_EVENT_DOWN)
                {
                    UsbDetectScrLskHdlr();
                    return MMI_RET_KEY_HANDLED;
                }
            }
            break;

        default:
            break;
    }

    return MMI_OK;
}

static void mmi_usb_entry_usb_detect_query_scrn(void)
{
    srv_usb_set_status(SRV_USBSTATUS_CONF_PAGE);
    
#if (defined(__MMI_USB_CDCACM_ONLY__) || defined(__MMI_USB_MS_ONLY__))

    mmi_frm_scrn_create(
        mmi_usb_get_normal_group_id(),
        SCR_DEV_USBDETECT,
        mmi_usb_detect_query_scrn_proc,
        NULL);

#else

    mmi_frm_scrn_create(
            mmi_usb_get_normal_group_id(),
            SCR_DEV_USBDETECT,
            mmi_usb_detect_query_scrn_proc,
            NULL);

    if (srv_bootup_get_booting_mode() == SRV_BOOTUP_MODE_NORMAL || 
        srv_bootup_is_exception_mode())
    {
        mmi_usb_enter_detect_query_list();
    }

#endif

#ifdef __MMI_FM_RADIO__
    mmi_fmrdo_search_all_channels_stop();
#endif 
}


static void mmi_usb_entry_usb_detect_query_scrn_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Watch out: must check PermitUsbCfgScreenDisplay first */

    //U8 *guiBuffer = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_USB_FUNC_DETECT_QUERY_SCR);

#if (defined(__MMI_USB_CDCACM_ONLY__) || defined(__MMI_USB_MS_ONLY__))
    {
        U16 str_title;

    #ifdef __MMI_USB_CDCACM_ONLY__

        #ifdef __USB_COM_PORT_ENABLE__
        /* CDCACM Mode only */
        str_title = STR_USB_CONFIG_CDCACM_ONLY;
        #endif

    #else /* __MMI_USB_CDCACM_ONLY__ */ /* __MMI_USB_MS_ONLY__ */

        /* MS Mode only */
        #ifdef __USB_MASS_STORAGE_ENABLE__        
        str_title = STR_USB_CONFIG_MS_ONLY;
        #endif

    #endif /* __MMI_USB_CDCACM_ONLY__ */ 

        ShowCategory165Screen(
            STR_GLOBAL_YES,
            0,
            STR_GLOBAL_NO,
            0,
            get_string(str_title),
            mmi_get_event_based_image(MMI_EVENT_QUERY),
            0);
#ifndef __MMI_WGUI_DISABLE_CSK__
       ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
    }

#else /* (defined(__MMI_USB_CDCACM_ONLY__) || defined(__MMI_USB_MS_ONLY__)) */ 

    /* Both Mass Storage and CDCACM mode */
    if (srv_bootup_get_booting_mode() != SRV_BOOTUP_MODE_NORMAL && 
        !srv_bootup_is_exception_mode())
    {
        /* If alarm/charger power on, display MS config confirm */
        ShowCategory165Screen(
            STR_GLOBAL_YES,
            0,
            STR_GLOBAL_NO,
            0,
            get_string(STR_USB_CONFIG_MS_ONLY),
            mmi_get_event_based_image(MMI_EVENT_QUERY),
            0);
#ifndef __MMI_WGUI_DISABLE_CSK__
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
#endif
    }

#endif /* (defined(__MMI_USB_CDCACM_ONLY__) || defined(__MMI_USB_MS_ONLY__)) */ 
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
#if defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)        /* 041205 Calvin modified */
/* under construction !*/
#endif    
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  UsbDetectScrENDKeyHdlr
 * DESCRIPTION
 *  This function is END key handler at usb config page.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *****************************************************************************/
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

/*****************************************************************************
 * FUNCTION
 *  UsbDetectScrRskHdlr
 * DESCRIPTION
 *  This function is right softkey handler at usb config page.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *****************************************************************************/
void UsbDetectScrRskHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_reminder_is_reminder_active())
    {
        mmi_usb_close_detect_query_list();
        srv_usb_set_status(SRV_USBSTATUS_IGNORED);
    }
    else
    {
        srv_usb_start_ms_shutdown();
    }
}


/*****************************************************************************
 * FUNCTION
 *  UsbDetectScrLskHdlr
 * DESCRIPTION
 *  This function is left softkey handler at usb config page.
 *  (Press left softkey means start to config usb device as certain function)
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: highlightedItemIndex, the usb function index(?)
 *****************************************************************************/
void UsbDetectScrLskHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    if (srv_usb_is_dm_lock())
    {
        mmi_usb_display_popup(STR_GLOBAL_INVALID, MMI_EVENT_FAILURE);
        return;
    }
#endif

#if (defined(__MMI_USB_CDCACM_ONLY__) || defined(__MMI_USB_MS_ONLY__))

    #ifdef __MMI_USB_CDCACM_ONLY__
        #ifdef __USB_COM_PORT_ENABLE__
        mmi_usb_config_first_page(DEVUSB_CFG_ACTION_CDC_ACM, SRV_USB_COMPORT_PS);
        #endif
        
    #else /* __MMI_USB_CDCACM_ONLY__ */ /* __MMI_USB_MS_ONLY__ */

        /* MS Mode only */
        #ifdef __USB_MASS_STORAGE_ENABLE__
        srv_usb_start_ms_shutdown();
        #endif

    #endif /* __MMI_USB_CDCACM_ONLY__ */ 

#else

    srv_usb_start_ms_shutdown();

#endif

#if 0
/* under construction !*/
/* under construction !*/
    #ifdef __USB_MASS_STORAGE_ENABLE__        
/* under construction !*/
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #else
/* under construction !*/
            #endif
/* under construction !*/
    #endif /* #ifdef __USB_MASS_STORAGE_ENABLE__ */
/* under construction !*/
    #ifdef __USB_COM_PORT_ENABLE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}



/*****************************************************************************
 * FUNCTION
 *  mmi_usb_config_cdc_acm
 * DESCRIPTION
 *  Display transition screen and send usb config request (MSG_ID_MMI_EQ_USBCONFIG_REQ) to HW
 *  
 *  PARAMETERS: mode, ms or cdcacm
 *  mode        [IN]        
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
void mmi_usb_config_cdc_acm(U8 owner)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U8 ps_port;
    //U32 ps_baudrate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __USB_TETHERING__
    if (!srv_tethering_is_off(SRV_TETHERING_TYPE_USB))
    {
        mmi_usb_display_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE);
        return;
    }
#endif

#ifdef __MMI_IRDA_SUPPORT__
    if (mmi_irda_is_ircomm_active() == MMI_TRUE)
    {
        /* currently, when IrComm is active, switch port not allow! */
        mmi_usb_display_popup(STR_ID_USB_IRCOMM_OCCUPY_CDCACM, MMI_EVENT_FAILURE);
        return;
    }
#endif /* __MMI_IRDA_SUPPORT__ */ 

    //nvram_get_ps(&ps_port, &ps_baudrate);
    if (srv_usb_get_ps_port() == uart_port_null)
    {
        mmi_usb_display_popup(STR_ID_USB_UART2_OCCUPIED, MMI_EVENT_FAILURE);
        return;
    }

#ifdef __USB_DATA_CONNECTION__
    if (owner == SRV_USB_CDROM)
    {
    	  srv_usb_set_status(SRV_USBSTATUS_CDROM);
        srv_usb_send_config_to_hw(DEVUSB_CFG_ACTION_CDROM);
        return;
    }
#endif

    srv_usb_set_owner(owner);
    srv_usb_set_status(SRV_USBSTATUS_CDCACM_PROC);

#ifdef __MMI_USB_MULTIPLE_COMPORT_SUPPORT__
    #if defined(__J2ME__) && defined(__USB_COM_PORT_ENABLE__) && defined(__OP01__)
        if (srv_usb_get_owner() == SRV_USB_COMPORT_JAVA)
        {
            srv_usb_send_config_to_hw(DEVUSB_CFG_ACTION_CDC_ACM);
        }
        else
    #endif
        {
            srv_usb_send_config_to_hw(DEVUSB_CFG_ACTION_MULTI_COM);
        }
#else
        srv_usb_send_config_to_hw(DEVUSB_CFG_ACTION_CDC_ACM);
#endif

}

/*****************************************************************************
 * FUNCTION
 *  mmi_usb_config_first_page
 * DESCRIPTION
 *  Display transition screen and send usb config request (MSG_ID_MMI_EQ_USBCONFIG_REQ) to HW
 *  
 *  PARAMETERS: mode, ms or cdcacm
 *  mode        [IN]        
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
static MMI_BOOL mmi_usb_check_sys_ready()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(WAP_SUPPORT) || defined(MMS_SUPPORT)
    if (srv_nw_usab_is_any_network_available())
    {
    #ifdef WAP_SUPPORT
        if (!wap_is_ready())
            return MMI_FALSE;
    #endif
    #ifdef MMS_SUPPORT
        if (!mma_is_ready_for_usb())
            return MMI_FALSE;
    #endif
    }
#endif
    return MMI_TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_usb_ms_mtp_config_pre_check
 * DESCRIPTION
 *  purpose is to check whether we can configure just now or not
 *  
 *  PARAMETERS:
 
 *  RETURNS:
 *  
 *****************************************************************************/
static MMI_BOOL mmi_usb_ms_mtp_config_pre_check(U8 mode)
{
    if(srv_usb_is_ms_exit_done() == MMI_FALSE)
    {
        mmi_usb_enter_waiting_screen();

        if(mode == DEVUSB_CFG_ACTION_MASS_STORAGE)
        {
            StartTimer(USB_WAIT_FOR_MASS_STORAGE, 150, mmi_usb_ms_config_timeout_hdlr);

        }
        else if(mode == DEVUSB_CFG_ACTION_MTP)
        {
            StartTimer(USB_WAIT_FOR_MASS_STORAGE, 150, mmi_usb_mtp_config_timeout_hdlr);
        }
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_usb_ms_config_timeout_hdlr
 * DESCRIPTION
 *  purpose is to wait till ms can be configured
 *  
 *  PARAMETERS:
 
 *  RETURNS:
 *  
 *****************************************************************************/
static void mmi_usb_ms_config_timeout_hdlr()
{
    StopTimer(USB_WAIT_FOR_MASS_STORAGE);
    
    if(srv_usb_is_ms_exit_done() == MMI_FALSE)
    {
        StartTimer(USB_WAIT_FOR_MASS_STORAGE, 150, mmi_usb_ms_config_timeout_hdlr);
    }
    else
    {
        mmi_usb_config_first_page(DEVUSB_CFG_ACTION_MASS_STORAGE, SRV_USB_MS_STORAGE_MS);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_usb_mtp_config_timeout_hdlr
 * DESCRIPTION
 *  purpose is to wait till ms can be configured
 *  
 *  PARAMETERS:
 
 *  RETURNS:
 *  
 *****************************************************************************/
static void mmi_usb_mtp_config_timeout_hdlr()
{
    StopTimer(USB_WAIT_FOR_MASS_STORAGE);

    if(srv_usb_is_ms_exit_done() == MMI_FALSE)
    {
        StartTimer(USB_WAIT_FOR_MASS_STORAGE, 150, mmi_usb_mtp_config_timeout_hdlr);
    }
    else
    {
        mmi_usb_config_first_page(DEVUSB_CFG_ACTION_MTP, SRV_USB_MS_STORAGE_MTP);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_usb_enter_waiting_screen
 * DESCRIPTION
 *  purpose is to wait till ms can be configured
 *  
 *  PARAMETERS:
 
 *  RETURNS:
 *  
 *****************************************************************************/
static void mmi_usb_enter_waiting_screen()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    mmi_usb_enter_normal_group();
    mmi_frm_scrn_close(mmi_usb_get_normal_group_id(), SCR_ID_USB_WAIT);

    group_id = mmi_usb_get_normal_group_id();
	
    if (!mmi_frm_scrn_enter(group_id, 
            SCR_ID_USB_WAIT, 
            NULL, 
            mmi_usb_enter_waiting_screen, 
            (mmi_frm_scrn_type_enum)0))
    {
        return;
    }
    ShowCategory66Screen(
        0,
        0,
        0,
        0,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        (U8*) GetString(STR_GLOBAL_PLEASE_WAIT),
        IMG_GLOBAL_PROGRESS,
        NULL);
    ClearAllKeyHandler();
    SetKeyUpHandler(mmi_usb_waiting_screen_key_handler,KEY_RSK);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_usb_waiting_screen_key_handler
 * DESCRIPTION
 *  purpose is to wait till ms can be configured
 *  
 *  PARAMETERS:

 *  RETURNS:
 *  
 *****************************************************************************/
static void mmi_usb_waiting_screen_key_handler()
{
    mmi_frm_scrn_close(mmi_usb_get_normal_group_id(), SCR_ID_USB_WAIT);
    StopTimer(USB_WAIT_FOR_MASS_STORAGE);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_usb_config_first_page
 * DESCRIPTION
 *  Display transition screen and send usb config request (MSG_ID_MMI_EQ_USBCONFIG_REQ) to HW
 *  
 *  PARAMETERS: mode, ms or cdcacm
 *  mode        [IN]        
 *  RETURNS: void(?)
 *  GLOBALS AFFECTED: none(?)
 *****************************************************************************/
static void mmi_usb_config_first_page(U8 mode, U8 owner)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_mode_enum bootup_mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_USB_FUNC_CONF_FIRST_PAGE, mode);

#ifdef __USB_TETHERING__
    if (!srv_tethering_is_off(SRV_TETHERING_TYPE_USB))
    {
        mmi_usb_display_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE);
        mmi_frm_scrn_close(mmi_usb_get_normal_group_id(), SCR_ID_USB_WAIT);
        return;
    }
#endif

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0
        #ifdef __MMI_HF_SUPPORT__
          || srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_ALL, NULL) > 0
        #endif /* __MMI_HF_SUPPORT__ */
        )
    {
        mmi_usb_display_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL, MMI_EVENT_FAILURE);
        mmi_frm_scrn_close(mmi_usb_get_normal_group_id(), SCR_ID_USB_WAIT);
        return;
    }
    srv_usb_set_owner(owner);

#ifdef __USB_IN_NORMAL_MODE__

    #if defined(__MSDC_NOT_SUPPORT_HOT_PLUG__) || defined(__MSDC_TFLASH_DAT3_1BIT_HOT_PLUG__)
    if (!srv_usb_is_any_exported_drive())
    {
        mmi_usb_display_popup(STR_ID_USB_NO_MS_FOR_PC, MMI_EVENT_FAILURE);
        srv_usb_set_status(SRV_USBSTATUS_IGNORED);
        mmi_frm_scrn_close(mmi_usb_get_normal_group_id(), SCR_ID_USB_WAIT);
        return;
    }
    #endif /* defined(__MSDC_NOT_SUPPORT_HOT_PLUG__) || defined(__MSDC_TFLASH_DAT3_1BIT_HOT_PLUG__)*/

#endif /* __USB_IN_NORMAL_MODE__*/

    mmi_usb_entry_progress_screen();
    mmi_usb_close_detect_query_list();

#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_IME_MEMORY_CARD_SUPPORT__) || defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
    mmi_usb_display_popup(STR_USB_SHUTDOWN_SCR, MMI_EVENT_PROGRESS);
    srv_usb_set_status(SRV_USBSTATUS_MS_PROC);
    StartTimer(USB_SHUTDOWN_FOR_MASS_STORAGE, 1500, mmi_usb_shutdown_timer_hdlr);
#else

#ifdef __USB_IN_NORMAL_MODE__
    if (!mmi_usb_need_to_reboot())
    {
        if (!mmi_usb_check_sys_ready())
        {
            mmi_usb_display_popup(STR_ID_USB_SYS_NOT_READY, MMI_EVENT_FAILURE);
            mmi_usb_close_progress_screen();
            srv_usb_set_status(SRV_USBSTATUS_IGNORED);
            mmi_frm_scrn_close(mmi_usb_get_normal_group_id(), SCR_ID_USB_WAIT);
            return;
        }
        else
        {
            srv_usb_set_status(SRV_USBSTATUS_MS_PROC);
            srv_usb_enter_ms_proc();
        }
     }
     else
#endif /* __USB_IN_NORMAL_MODE__*/
    {
        //mmi_usb_display_popup(STR_USB_SHUTDOWN_SCR, MMI_EVENT_PROGRESS);
        bootup_mode = srv_bootup_get_booting_mode();
        
        if ((bootup_mode == SRV_BOOTUP_MODE_USB) || 
            (bootup_mode == SRV_BOOTUP_MODE_ALARM) ||
            (bootup_mode == SRV_BOOTUP_MODE_CHARGE))
        {
            srv_usb_start_ms_shutdown();
            srv_usb_set_status(SRV_USBSTATUS_MS_PROC);
        }
        else
        {
            /* USB split revise*/
            srv_usb_send_config_to_hw(mode);
            srv_usb_set_status(SRV_USBSTATUS_MS_PROC);
        }
    }      


#endif


}

#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__) || defined(__MMI_IME_MEMORY_CARD_SUPPORT__) || defined(__MMI_HANDWRITING_MEMORY_CARD_SUPPORT) || defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)

/*****************************************************************************
 * FUNCTION
 *  mmi_usb_shutdown_timer_hdlr
 * DESCRIPTION
 *  Shutdown for Mass storage
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
static void mmi_usb_shutdown_timer_hdlr()
{
    srv_shutdown_normal_start(APP_USBMMI);
}
#endif


/* ===========================================================================================  */
/* ===  Send Message to Protocol Stack  */
/* ===========================================================================================  */

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
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_usb_entry_progress_screen
 * DESCRIPTION
 *  USB progress screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_usb_entry_progress_screen(void)
{
    mmi_usb_enter_normal_group();
    mmi_frm_scrn_close(mmi_usb_get_normal_group_id(), SCR_ID_USB_PROGRESS);
    mmi_usb_entry_progress_screen_int();
}

static void mmi_usb_entry_progress_screen_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_USB_ENTRY_PROGRESS_SCREEN_INT);

    group_id = mmi_usb_get_normal_group_id();
	
    if (!mmi_frm_scrn_enter(group_id, 
            SCR_ID_USB_PROGRESS, 
            NULL, 
            mmi_usb_entry_progress_screen_int, 
            (mmi_frm_scrn_type_enum)0))
    {
        return;
    }
    ShowCategoryDummyScreen();
    mmi_frm_scrn_set_leave_proc(group_id, SCR_ID_USB_PROGRESS, mmi_usb_progress_leave_proc);
}

static mmi_ret mmi_usb_progress_leave_proc(mmi_event_struct *param)
{
    srv_usb_status_enum usb_state = srv_usb_get_status();

    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_USB_PROGRESS_LEAVE_PROC);
	
    switch(param->evt_id)
    {
        case EVT_ID_SCRN_DELETE_REQ:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
            if (usb_state == SRV_USBSTATUS_MS_PROC)
            {
                return MMI_RET_ERR;
            }
            else
            {
                return MMI_RET_ALLOW_CLOSE;
            }
            
        default:
            return MMI_RET_ALLOW_CLOSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_usb_close_progress_screen
 * DESCRIPTION
 *  Close USB progress screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_usb_close_progress_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(mmi_usb_get_normal_group_id(), SCR_ID_USB_PROGRESS);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_usb_get_error_info
 * DESCRIPTION
 *  Function to get the error information includes popup type and string
 * PARAMETERS
 *  error_result:   [IN]    error result type
 *  popup_type:     [OUT]   get the error popup type
 * RETURNS
 *  Get the error popup string id.
 *****************************************************************************/
MMI_STR_ID mmi_usb_get_error_info(S32 error_result, mmi_event_notify_enum* popup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (popup_type)
    *popup_type = MMI_EVENT_FAILURE;
#ifdef  __MTP_ENABLE__
    if (srv_usb_get_owner() == SRV_USB_MS_STORAGE_MTP)
        return STR_ID_USB_NOT_AVAILABLE_IN_MTP_MODE;
#endif
    return STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_usb_app_unavailable_popup
 * DESCRIPTION
 *  To make a warning if the app. is disable in MS mode
 * PARAMETERS
 *  stringId        [IN]        0 will popup "USB: Can't access the storage now"; app specific string otherwise
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_usb_app_unavailable_popup(U16 stringId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (stringId == 0)
    {
        mmi_usb_display_popup((U16)mmi_usb_get_error_info(0, NULL), MMI_EVENT_FAILURE);
    }
    else
    {
        mmi_usb_display_popup(stringId, MMI_EVENT_FAILURE);
    }

}

mmi_ret mmi_usb_config_rsp_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U8 mode = *(U8*)evt->user_data;
    srv_usb_config_result_struct *result = (srv_usb_config_result_struct*)evt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_USB_CONFIG_RSP_CALLBACK, 
	    result->mode, result->suc);
	
	if (!result->suc)
	{
            mmi_usb_display_popup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);
            mmi_frm_scrn_close(mmi_usb_get_normal_group_id(), SCR_ID_USB_WAIT);
            mmi_usb_close_progress_screen();           
            mmi_usb_close_detect_query_list();
            return MMI_RET_OK;
	}
	
    switch (result->mode)
    {
        case DEVUSB_CFG_ACTION_MASS_STORAGE:
    #ifdef __MTP_ENABLE__			
        case DEVUSB_CFG_ACTION_MTP:
    #endif
        {
    #if 0
        #ifdef __MMI_BACKGROUND_CALL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
         #endif /* #ifndef __MMI_BACKGROUND_CALL__ */
/* under construction !*/
            #ifdef __USB_IN_NORMAL_MODE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
            mmi_usb_ms_cfg_success_notify();
    #endif
        }
                break;

		#ifdef __MMI_PICT_BRIDGE_SUPPORT__
        case DEVUSB_CFG_ACTION_PICTBRIGE: /* PictBrige */
            mmi_usb_display_popup(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS);
            mmi_usb_close_detect_query_list();
            break;
        #endif /* __MMI_PICT_BRIDGE_SUPPORT__ */

        case DEVUSB_CFG_ACTION_STOP_MS:
        case DEVUSB_CFG_ACTION_STOP_MTP:
        case DEVUSB_CFG_ACTION_WEBCAM:
            break;
            
        default:
            mmi_usb_display_popup(STR_GLOBAL_DONE, MMI_EVENT_SUCCESS);
            mmi_usb_close_progress_screen();
            mmi_usb_close_detect_query_list();
            break;
        }
    return MMI_RET_OK;
}

static void mmi_usb_ms_cfg_success_notify(void)
{
    mmi_popup_property_struct prop;
    
    mmi_popup_property_init(&prop);
    prop.parent_id = mmi_usb_get_normal_group_id();
    prop.callback = (mmi_proc_func)mmi_usb_ms_cfg_success_popup_cb;

#ifdef __USB_IN_NORMAL_MODE__
        if (!srv_usb_is_any_exported_drive())
        {
            mmi_popup_display_ext(STR_ID_USB_NO_MS_FOR_PC, 
                MMI_EVENT_INFO, 
                &prop);
        }
        else
#endif
        {
            mmi_popup_display_ext(STR_GLOBAL_DONE, 
                MMI_EVENT_SUCCESS, 
                &prop);
        }

    mmi_frm_scrn_close(mmi_usb_get_normal_group_id(), SCR_ID_USB_WAIT);
}

static mmi_ret mmi_usb_ms_cfg_success_popup_cb(mmi_event_struct *evt)
{
    if (EVT_ID_POPUP_QUIT == evt->evt_id)
    {
    #ifdef __MMI_BACKGROUND_CALL__
        if ((srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0) ||
            (srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0))
        {
            MMI_ID marker_screen;
            MMI_ID start_screen;
            
            marker_screen = mmi_ucm_get_marker_scrn_id();
            start_screen = mmi_frm_scrn_get_neighbor_id(GRP_ID_ROOT, marker_screen, MMI_FRM_NODE_BEFORE_FLAG);
            mmi_frm_close_to_idle_group_with_start_id(start_screen);
            mmi_usb_close_progress_screen();
        }
        else
        {
            //mmi_idle_display();
            mmi_frm_close_to_idle_group_with_start_id(mmi_usb_get_normal_group_id());
        }
    #else
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0
         #ifdef __MMI_HF_SUPPORT__
             && srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_ALL, NULL) == 0
         #endif /* __MMI_HF_SUPPORT__ */
            )
        {
            //mmi_idle_display();
            mmi_frm_close_to_idle_group_with_start_id(mmi_usb_get_normal_group_id());
        }
        else
        {
            MMI_ID marker_screen;
            MMI_ID start_screen;

            marker_screen = mmi_ucm_get_marker_scrn_id();
            start_screen = mmi_frm_scrn_get_neighbor_id(GRP_ID_ROOT, marker_screen, MMI_FRM_NODE_BEFORE_FLAG);
            mmi_frm_close_to_idle_group_with_start_id(start_screen);
            mmi_usb_close_progress_screen();
        }
    #endif /* #ifndef __MMI_BACKGROUND_CALL__ */
    }
    return MMI_RET_OK;
}

mmi_ret mmi_usb_mmi_notify_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_usb_mmi_notify_action_enum act = (srv_usb_mmi_notify_action_enum)(0xFFFF & (int)(evt->user_data));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(act)
    {
        case SRV_USB_MMI_NOTIFY_PLUGOUT:
            wgui_status_icon_bar_hide_icon(STATUS_ICON_USB);
            break;
            
        case SRV_USB_MMI_NOTIFY_POWER_OFF_REMOVED:
            mmi_usb_close_normal_group();
            mmi_usb_close_power_off_screen();
            break;

        case SRV_USB_MMI_NOTIFY_REMOVED:
            //BatteryIndicationPopupEx(STR_USB_CHARGER_REMOVED);
            break;
            
        case SRV_USB_MMI_NOTIFY_CLOSE_CFG_LIST:
            mmi_usb_close_detect_query_list();
            break;

        case SRV_USB_MMI_NOTIFY_CLOSE_PROGRESS:
            mmi_usb_close_progress_screen();
            break;

        case SRV_USB_MMI_NOTIFY_EXIT_WEBCAM:
        #ifdef __MMI_WEBCAM__
            mmi_usb_close_detect_query_list();
            mmi_usb_exit_webcam();
        #endif
            break;

        case SRV_USB_MMI_NOTIFY_CFG_ERROR:
            mmi_usb_display_popup(STR_GLOBAL_ERROR, 
                MMI_EVENT_FAILURE);
            break;
            
        default:
            break;
    }

    return MMI_RET_OK;
}

mmi_ret mmi_usb_alm_state_callback(mmi_event_struct *evt)
{
    return (mmi_ret)mmi_alm_is_in_alarm();
}

/* Screen group*/
static MMI_ID g_usb_normal_mode_group;
static MMI_ID g_query_list_menu_id;

static void mmi_usb_enter_normal_group(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body													  */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_USB_ENTER_NORMAL_GROUP, g_usb_normal_mode_group);
    
    if (g_usb_normal_mode_group != GRP_ID_INVALID)
    {
        return;
    }
    g_usb_normal_mode_group = mmi_frm_group_create_ex(GRP_ID_ROOT, 
        GRP_ID_USB_MMI, 
        mmi_usb_normal_group_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
}

static MMI_ID mmi_usb_get_normal_group(void)
{
    mmi_usb_enter_normal_group();
    return g_usb_normal_mode_group;
}

static MMI_ID mmi_usb_get_normal_group_id(void)
{
    if (g_usb_normal_mode_group == GRP_ID_INVALID)
    {
        MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_USB_GET_NORMAL_GROUP_ID);
        return GRP_ID_USB_MMI;
    }
    return g_usb_normal_mode_group;
}

static void mmi_usb_close_normal_group(void)
{
    if (g_usb_normal_mode_group == GRP_ID_INVALID)
    {
        return;
    }
    mmi_frm_group_close(g_usb_normal_mode_group);
    g_usb_normal_mode_group = GRP_ID_INVALID;
}

static mmi_ret mmi_usb_normal_group_proc(mmi_event_struct *param)
{
    cui_menu_event_struct *menu_evt;

    menu_evt = (cui_menu_event_struct*)param;
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_USB_NORMAL_GROUP_PROC, menu_evt->evt_id);
    
    switch(menu_evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            g_usb_normal_mode_group = GRP_ID_INVALID;
            mmi_usb_waiting_screen_key_handler();
            break;
            
        case EVT_ID_CUI_MENU_LIST_ENTRY:
            mmi_usb_init_detect_query_list(menu_evt->sender_id);
            break;
            
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            mmi_usb_query_list_select_hdlr(menu_evt);
            break;
            
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            mmi_usb_close_detect_query_list();
            srv_usb_set_status(SRV_USBSTATUS_IGNORED);
            mmi_usb_waiting_screen_key_handler();
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}

typedef enum
{
#ifdef __USB_MASS_STORAGE_ENABLE__
    MENU_ID_USB_MS,
#endif
#ifdef __MMI_WEBCAM__
    MENU_ID_USB_WEBCAM,
#endif
#ifdef __USB_COM_PORT_ENABLE__
    MENU_ID_USB_CDCAM_DATA,
#endif
#ifdef __MMI_PICT_BRIDGE_SUPPORT__
    MENU_ID_USB_PICTBRIDGE,
#endif
#if defined(__J2ME__) && defined(__USB_COM_PORT_ENABLE__) && defined(__OP01__)
    MENU_ID_USB_COMPORT_JAVA,
#endif
#ifdef  __MTP_ENABLE__
    MENU_ID_USB_MTP,
#endif
#ifdef __USB_TETHERING__
    MENU_ID_USB_TETHERING,
#endif
#ifdef __USB_DATA_CONNECTION__
    MENU_ID_USB_DATA_CONN,
#endif
    MENU_ID_USB_NUM
} mmi_usb_menu_id_enum;
        
static void mmi_usb_init_detect_query_list(MMI_ID menu_id)
{
    S32 i;
    mmi_menu_id items[] = {
#ifdef __USB_MASS_STORAGE_ENABLE__
    	   MENU_ID_USB_MS,
#endif
#ifdef __MMI_WEBCAM__
    	   MENU_ID_USB_WEBCAM,
#endif
#ifdef __USB_DATA_CONNECTION__
        MENU_ID_USB_DATA_CONN,
#endif
#ifdef __USB_COM_PORT_ENABLE__
    		MENU_ID_USB_CDCAM_DATA,
#endif
#ifdef __MMI_PICT_BRIDGE_SUPPORT__
    		MENU_ID_USB_PICTBRIDGE,
#endif
#if defined(__J2ME__) && defined(__USB_COM_PORT_ENABLE__) && defined(__OP01__)
    		MENU_ID_USB_COMPORT_JAVA,
#endif
#ifdef  __MTP_ENABLE__
    		MENU_ID_USB_MTP,
#endif
#ifdef __USB_TETHERING__
        MENU_ID_USB_TETHERING,
#endif
    		0
    		};
    U16 strings[] = 
    {
#ifdef __USB_MASS_STORAGE_ENABLE__        
    STR_USB_CONFIG_MS,
#endif
#ifdef __MMI_WEBCAM__
    STR_ID_USB_WEBCAM,
#endif 
#ifdef __USB_DATA_CONNECTION__
    STR_ID_USB_CDROM,
#endif
#ifdef __USB_COM_PORT_ENABLE__
    STR_USB_CONFIG_CDCACM_DATA,
#endif
#ifdef __MMI_PICT_BRIDGE_SUPPORT__
    STR_USB_CONFIG_PICT_BRIGE,
#endif
#if defined(__J2ME__) && defined(__USB_COM_PORT_ENABLE__) && defined(__OP01__)
    STR_USB_CONFIG_COMPORT_JAVA,
#endif
#ifdef  __MTP_ENABLE__
    STR_USB_CONFIG_MTP,
#endif
#ifdef __USB_TETHERING__
    STR_ID_USB_TETHERING,
#endif
        0
    };
    
    cui_menu_set_currlist_title(menu_id, (WCHAR*)GetString(STR_USB_CONFIG_TITLE), NULL);
    cui_menu_set_currlist(menu_id, MENU_ID_USB_NUM, (MMI_MENU_ID*)items);
    cui_menu_set_currlist_left_softkey(menu_id, (WCHAR*)GetString(STR_GLOBAL_OK));
    cui_menu_set_currlist_right_softkey(menu_id, (WCHAR*)GetString(STR_GLOBAL_BACK));
    for (i = 0; i < MENU_ID_USB_NUM; i++)
    {
    	cui_menu_set_item_string(menu_id, items[i], (WCHAR*)GetString(strings[i]));
    }

    cui_menu_set_currlist_flags(menu_id, CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS);
}

static void mmi_usb_enter_detect_query_list(void)
{
    g_query_list_menu_id = cui_menu_create_and_run(mmi_usb_get_normal_group(),
        CUI_MENU_SRC_TYPE_APPCREATE, 
        CUI_MENU_TYPE_APPSUB, 
        0, 
        MMI_FALSE, 
        NULL);
}

static void mmi_usb_query_list_select_hdlr(cui_menu_event_struct *event)
{
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_USB_QUERY_LIST_SELECT_HDLR, event->highlighted_menu_id);

#ifdef __DM_LAWMO_SUPPORT__
    if (srv_usb_is_dm_lock())
    {
        mmi_usb_display_popup(STR_GLOBAL_INVALID, MMI_EVENT_FAILURE);
        return;
    }
#endif

    /*if ( (srv_usb_get_status() == SRV_USBSTATUS_PLUGOUT))
    {
    	mmi_usb_display_popup(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE);
    	mmi_usb_close_detect_query_list();
    	return;
    }
    
    if ( (srv_usb_get_status() != SRV_USBSTATUS_CONF_PAGE))
    {
    	return;
    }*/
    
    switch(event->highlighted_menu_id)
    {
    #ifdef __USB_MASS_STORAGE_ENABLE__
        case MENU_ID_USB_MS:
            {
                if(mmi_usb_ms_mtp_config_pre_check(DEVUSB_CFG_ACTION_MASS_STORAGE) == MMI_TRUE)
                {
            mmi_usb_config_first_page(DEVUSB_CFG_ACTION_MASS_STORAGE, SRV_USB_MS_STORAGE_MS);
                }
            }
            break;
    #endif

    #ifdef __MMI_WEBCAM__
	
        case MENU_ID_USB_WEBCAM:
            mmi_usb_config_webcam();
            break;
    #endif
    
    #ifdef __USB_COM_PORT_ENABLE__
        case MENU_ID_USB_CDCAM_DATA:
            mmi_usb_config_cdc_acm(SRV_USB_COMPORT_PS);
            break;
    #endif
    
    #ifdef __MMI_PICT_BRIDGE_SUPPORT__
        case MENU_ID_USB_PICTBRIDGE:

        #ifdef MMI_ON_HARDWARE_P

            srv_usb_set_status(SRV_USBSTATUS_PICTBRIGE);
            mmi_usb_display_popup(STR_USB_PICT_BRIGE_CONFIGING, MMI_EVENT_PROGRESS);
            srv_usb_send_config_to_hw(DEVUSB_CFG_ACTION_PICTBRIGE);      
	
        #else /* MMI_ON_HARDWARE_P */ 
            mmi_usb_close_detect_query_list();
        #endif /* MMI_ON_HARDWARE_P */   

            break;
    #endif
    
    #if defined(__J2ME__) && defined(__USB_COM_PORT_ENABLE__) && defined(__OP01__)
        case MENU_ID_USB_COMPORT_JAVA:
            mmi_usb_config_cdc_acm(SRV_USB_COMPORT_JAVA);
            break;
    #endif
    
    #ifdef  __MTP_ENABLE__
        case MENU_ID_USB_MTP:
            {
                if(mmi_usb_ms_mtp_config_pre_check(DEVUSB_CFG_ACTION_MTP) == MMI_TRUE)
                {
            mmi_usb_config_first_page(DEVUSB_CFG_ACTION_MTP, SRV_USB_MS_STORAGE_MTP);
                }
            }
            break;
    #endif

    #ifdef __USB_TETHERING__
        case MENU_ID_USB_TETHERING:
            if (!srv_tethering_is_off(SRV_TETHERING_TYPE_USB))
            {
                mmi_usb_display_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE);
                return;
            }
            srv_usb_set_status(SRV_USBSTATUS_USBTETHERING);
            mmi_tethering_usb_launch();
            mmi_usb_close_detect_query_list();
            break;
    #endif
            
    #ifdef __USB_DATA_CONNECTION__
        case MENU_ID_USB_DATA_CONN:
        	  mmi_usb_config_cdc_acm(SRV_USB_CDROM);
            break;
    #endif
    
        default:
            mmi_usb_close_detect_query_list();
            break;
    }
}

static void mmi_usb_close_detect_query_list(void)
{
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_USB_CLOSE_DETECT_QUERY_LIST);
    
    mmi_frm_scrn_close(mmi_usb_get_normal_group_id(), SCR_DEV_USBDETECT);
    if (g_query_list_menu_id != GRP_ID_INVALID)
    {
        cui_menu_close(g_query_list_menu_id);
        g_query_list_menu_id = GRP_ID_INVALID;
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
#endif

#ifdef __USB_IN_NORMAL_MODE__
/*****************************************************************************
 * FUNCTION
 *  mmi_usb_need_to_reboot
 * DESCRIPTION
 *  Check if it it necessary to reboot for USB mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_usb_need_to_reboot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bootup_mode_enum mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    mode = srv_bootup_get_booting_mode();
    
    MMI_TRACE(MMI_COMMON_TRC_G8_DEV, TRC_MMI_USB_NEED_TO_REBOOT, mode);
    
#ifdef __USB_IN_NORMAL_MODE_IMPROVE__
    if (mode == SRV_BOOTUP_MODE_USB ||
        mode == SRV_BOOTUP_MODE_ALARM ||
        mode == SRV_BOOTUP_MODE_CHARGE)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }    
#elif !defined(__FS_CARD_SUPPORT__) && !defined(NAND_SUPPORT)
    return MMI_TRUE;
#elif !defined(__FS_CARD_SUPPORT__) && defined(__NOR_NOT_PRESENT__)
    return MMI_TRUE;
#else 
    if (mode == SRV_BOOTUP_MODE_USB ||
        mode == SRV_BOOTUP_MODE_ALARM ||
        mode == SRV_BOOTUP_MODE_CHARGE)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
#endif 
}

#endif

#ifdef __MMI_WEBCAM__

static void mmi_usb_config_webcam(void)
{
#ifdef __USB_TETHERING__
    if (!srv_tethering_is_off(SRV_TETHERING_TYPE_USB))
    {
        mmi_usb_display_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, MMI_EVENT_FAILURE);
        return;
    }
#endif
#ifndef __MMI_BACKGROUND_CALL__ 
	if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        mmi_usb_display_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL, MMI_EVENT_FAILURE);
        return;
    }
#endif 
    mmi_webcam_enter();
    mmi_usb_close_detect_query_list();
}

static void mmi_usb_exit_webcam(void)
{
    mmi_webcam_exit();
}

#endif /* __MMI_WEBCAM__*/

static void mmi_usb_display_popup(U16 string, mmi_event_notify_enum type)
{
    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, type, (WCHAR*)GetString(string));
}


#endif /* __COSMOS_MMI_PACKAGE__*/

#else /* __MMI_USB_SUPPORT__ */

#include "MMIDataType.h"
/*
mmi_ret mmi_usb_shutdown_handler(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}
*/
mmi_ret mmi_usb_handle_query_permit_show(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

mmi_ret mmi_usb_handle_query_permit_pre_check(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

mmi_ret mmi_usb_handle_plug_in(mmi_event_struct *evt)
{
	  return MMI_RET_OK;
}

mmi_ret mmi_usb_config_rsp_callback(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

mmi_ret mmi_usb_mmi_notify_callback(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

mmi_ret mmi_usb_alm_state_callback(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

#endif /* __MMI_USB_SUPPORT__ */ 

