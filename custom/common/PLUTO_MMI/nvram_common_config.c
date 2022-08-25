/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * nvram_common_config.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file is for MTK to config the NVRAM settings.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef NVRAM_NOT_PRESENT
#ifdef NVRAM_AUTO_GEN
#include "nvram_auto_gen.h"
#endif

#include "kal_general_types.h"
#include "MMI_features.h"

#include "nvram_default_audio.h"
#include "custom_mmi_default_value.h"
#include "custom_data_account.h"
#include "drv_features.h"
//#include "camera_para.h"

#include "nvram_defs.h"
#include "nvram_enums.h"
#include "common_nvram_editor_data_item.h"
#include "nvram_common_defs.h"
#include "nvram_data_items.h"
#include "custom_nvram_config.h"        /* NVRAM_APP_RESERVED */
#if defined(__NVRAM_COMPRESS_SUPPORT__) && !defined(NVRAM_AUTO_GEN)
#include "nvram_default_value.h"
#endif

#include "custom_srv_prof_defs.h"           /* SRV_PROF_ALERT_TYPE_RING */
#include "cbm_consts.h"                     /* CBM_DEFAULT_ACCT_ID */
#include "custom_phb_config.h"
#include "custom_wap_config.h"

#include "nvram_editor_data_item.h"

#ifndef __OPTR_NONE__
#include "op_custom_wap_config.h"
#endif

#ifdef __CLOG_STORAGE_BY_MMI__
#include "custom_calllog.h"
#endif

#ifdef __MMI_VUI_SHELL_SHORTCUTS__
#include "custom_shell_shortcuts_cfg.h"
#endif

#if defined(__MMI_FRM_INPUT_EVT__)	
#include "nvram_input_event_cfg.h"
#endif/*#if defined(__MMI_FRM_INPUT_EVT__)	*/

//custpack work around solution
#ifndef __NVRAM_SUPPORT_CUSTPACK__
extern const kal_uint8 NVRAM_EF_MMI_CACHE_BYTE_DEFAULT[];
extern const kal_uint8 NVRAM_EF_MMI_CACHE_SHORT_DEFAULT[];
extern const kal_uint8 NVRAM_EF_MMI_CACHE_DOUBLE_DEFAULT[];

extern kal_uint8 COMMON_NVRAM_EF_PHB_SOS_DEFAULT[];

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    extern mmi_phb_vip_contact_struct COMMON_NVRAM_EF_PHB_VIP_CONTACT_DEFAULT[];
#endif

 
#if defined(__TCPIP_OVER_CSD__)
    extern kal_uint8 COMMON_NVRAM_EF_CSD_PROFILE_DEFAULT[];
#endif

#if defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_EM_INET_APP_SLIM__)
/* Internet Application */
    extern nvram_em_inet_custpack_struct COMMON_NVRAM_EF_INET_CUSTPACK_DEFAULT[];
#endif

#ifdef __WAP_PUSH_SUPPORT__

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    extern nvram_push_wl_addr_struct COMMON_NVRAM_EF_PUSH_WHITE_LIST_DEFAULT[];
#endif

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    extern nvram_push_bl_addr_struct COMMON_NVRAM_EF_PUSH_BLACK_LIST_DEFAULT[];
#endif
#endif

#ifdef WAP_SUPPORT
#ifdef __MMI_BROWSER_2__
    extern nvram_wap_bookmark_list_struct COMMON_NVRAM_EF_WAP_BOOKMARK_LIST_DEFAULT[];
#endif

#endif /* WAP_SUPPORT */

#ifdef __MMI_TETHERING_WIFI__
    extern nvram_ef_srv_tethering_wifi_hs_settings_struct COMMON_NVRAM_EF_SRV_TETHERING_WIFI_HS_SETTINGS_DEFAULT[];
#endif



#endif
//_______________________________
/*******************************************************
 *  Add include statement above this line
 *******************************************************/
#ifndef __OPTR_NONE__
#include "op_nvram_common_config.h"
#endif

#if defined(PLUTO_MMI) || defined(VENUS_MMI)
#include "mmi_res_range_def.h"
#include "mmi_cache_table.h"
#endif

#ifdef MRE_VERSION
#include "vmswitch.h"

#ifdef __MRE_CORE_SAFETY__
extern kal_uint8 const  NVRAM_VER_PKEY_EXT_DEFAULT[];
extern kal_uint8 const  NVRAM_MER_PKEY_MTK_DEFAULT[];
extern kal_uint8 const  NVRAM_MER_PKEY_1024BIT_DEFAULT[];
#endif

#ifdef __MRE_CORE_SANDBOX__
extern kal_uint8 const  NVRAM_VER_SYM_ENTRY_EXT_DEFAULT[];
#endif

#endif
#ifdef __CMCC_0202_SEGC_TECH__
#ifdef __MMI_CUSTOMER_SERVICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MMI_CUSTOMER_SERVICE__*/
#else /*__CMCC_0202_SEGC_TECH__*/
#ifdef __MMI_CUSTOMER_SERVICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MMI_CUSTOMER_SERVICE__*/
#endif /*__CMCC_0202_SEGC_TECH__*/


#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
#endif


#ifdef __MMI_FM_RADIO_SCHEDULER__
static char NVRAM_FMRDO_SCHEDULER_DEFAULT[NVRAM_EF_FMRDO_SCHEDULER_SIZE] =
{
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
	0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0x01, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
    0, 0xff
};
#endif /* __MMI_FM_RADIO_SCHEDULER__ */

#ifdef __MMI_THEMES_APPLICATION__
#ifdef __MMI_THEMES_V2_SUPPORT__
static kal_uint8 const NVRAM_THEMES_VALUES_DEFAULT [NVRAM_THEMES_VALUES_SIZE] =
{
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
   0x00,0x00,0x00,0x00
};
#else /* __MMI_THEMES_V2_SUPPORT__*/
static kal_uint8 const NVRAM_THEMES_VALUES_DEFAULT [NVRAM_THEMES_VALUES_SIZE] =
{
   0x00,0x00,0xFF,0xFF,0x00,0x00,0x00,0x00
};
#endif /* __MMI_THEMES_V2_SUPPORT__*/
#endif /* __MMI_THEMES_APPLICATION__*/

/*
// move to mcu\nvram\src\nvram_data_items.c
static kal_int32 const NVRAM_EF_ADC_DEFAULT[] = {
#if defined(DRV_ADC_MAX_CH_1)
   5369,
   60428
#elif defined(DRV_ADC_MAX_CH_5)
   5369,  5369, 5369, 5369, 5369,
   60428, 60428, 60428, 60428, 60428
#elif defined(DRV_ADC_MAX_CH_6)
   5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_7)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_8)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_9)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_10)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_11)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_12)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_13)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_14)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_15)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_16)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_17)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_18)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_19)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#elif defined(DRV_ADC_MAX_CH_20)
   5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,  5524,
   23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286, 23286
#endif // #if defined(DRV_ADC_MAX_CH_5)

};
*/

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
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
#else
static kal_uint8 const NVRAM_EF_AUTOTEST_DEFAULT[NVRAM_EF_AUTOTEST_SIZE] =
{
       /* [count, test0, test1, test2 ....... test229] */
	15,  0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   10,  11,  12,  13,  14, /* 16 */
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

#endif
#endif



static kal_uint8 const NVRAM_EF_QUICKTEST_DEFAULT[NVRAM_EF_QUICKTEST_SIZE] =
{
       /* [count, test0, test1, test2 ....... test229] */
	15,  0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   10,  11,  12,  13,  14, /* 16 */
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

#ifdef MOTION_SENSOR_SUPPORT

static kal_uint8 const NVRAM_EF_MOTION_SENSOR_SWITCH_DEFAULT[NVRAM_EF_MOTION_SENSOR_SWITCH_SIZE] =
{
    0x01
};

#endif /*MOTION_SENSOR_SUPPORT*/

#ifdef __MMI_EBOOK_READER__
static kal_uint8 const NVRAM_EF_EBOOK_DEFAULT_VALUE [NVRAM_EF_EBOOK_SETTING_SIZE] =
{
   0x01,0x00,0x01,0x00,0x01
};
#endif /* __MMI_EBOOK_READER__ */

#ifdef __MMI_ECOMPASS__
static kal_int32 const NVRAM_EF_ECOMPASS_DEFAULT[NVRAM_EF_ECOMPASS_SIZE * NVRAM_EF_ECOMPASS_TOTAL] =
{
	#include "ec_def_dec_ang.h"
};
#endif /* __MMI_ECOMPASS__ */

#ifdef __SYNCML_SUPPORT__

#ifdef CUSTOM_SYNCML_ACCOUNT_DEFAULT
nvram_ef_syncml_account_struct const NVRAM_EF_SYNCML_ACCOUNT_DEFAULT[NVRAM_EF_SYNCML_ACCOUNT_TOTAL] =
{
    CUSTOM_SYNCML_ACCOUNT_DEFAULT
};
#endif /* CUSTOM_SYNCML_ACCOUNT_DEFAULT */

#ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
nvram_ef_syncml_account_struct const NVRAM_EF_SYNCML_ACCOUNT_DEFAULT_FOR_PC_SYNC[NVRAM_EF_SYNCML_ACCOUNT_TOTAL] =
{
	{                               /* default profile 1 */
     0x01,                          /* Account ID */
     "",                            /* Account Name */
     "http://",                     /* Server Address */
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* Contact Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* Calendar Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* Task Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* Note Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* bookmark Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* email Address */
     "",                            /* User Name */
     "",                            /* Password */
     0x8000,                        /* Validation:valid data account*/
     {
     #if (MMI_MAX_SIM_NUM>3)
     	CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
     #endif

	 #if (MMI_MAX_SIM_NUM>2)		
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	 #endif

	 #if (MMI_MAX_SIM_NUM>1)
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	 #endif
		
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID	
	},        /* Network ID */
     "",                            /* Proxy hash*/
     "",                            /* Provurl hash*/
     0,                             /* Type */
     0,                             /* Read only*/
     0,                             /* Connection Type -- HTTP 0, WAP 1, BT 2 */
     0,                             /* App to sync */
     0,                             /* sync type - two-way sync*/
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#else
     0,
#endif
     0,                             /* regular sync - 0:none */
     0,                             /* regular sync notify */
     0,                             /* sync report 0:off 1:on */
     0,                             /* last_phb_anchor */
     0,                             /* last_cal_anchor */
     0,                             /* last_task_anchor */
     0,                             /* last_note_anchor */
     0,                             /* last_email_anchor */
     0,                             /* last_bkm_anchor */
     },
    {                               /* operator default Account 2 */
     0x02,                             /* Account ID */
     "",                            /* Account Name */
     "http://",                     /* Server Address */
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Contact Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Calendar Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Task Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Note Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* bookmark Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* email Address */
     "",                            /* User Name */
     "",                            /* Password */
     0x8000,                        /* Validation:valid data account*/     
	{
	#if (MMI_MAX_SIM_NUM>3)
		 CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	#endif

	#if (MMI_MAX_SIM_NUM>2)		 
		 CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	#endif
		 
	#if (MMI_MAX_SIM_NUM>1)
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	#endif

		CUSTOM_DEFAULT_SYNCML_DTCNT_ID  
	}, 	   /* Network ID */
     "",                            /* Proxy */
     "",                            /* Provurl*/
     0,                             /* Type */
     0,                             /* Read only*/
     0,                             /* Connection Type -- HTTP 0, WAP 1, BT 2 */
     0,                             /* App to sync */
     0,                             /* sync type - two-way sync*/
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#else
     0,
#endif
     0,                             /* regular sync - 0:none */
     0,                             /* regular sync notify */
     0,                             /* sync report 0:off 1:on */
     0,                             /* last_phb_anchor */
     0,                             /* last_cal_anchor */
     0,                             /* last_task_anchor */
     0,                             /* last_note_anchor */
     0,                             /* last_email_anchor */
     0,                             /* last_bkm_anchor */
     },
    {                               /* operator default profile 3 */
     0x03,                             /* Account ID */
     {'M', 0x00,'T', 0x00,'K', 0x00,' ', 0x00,'P', 0x00, 'C', 0x00, ' ', 0x00, 'S', 0x00, 'Y', 0x00, 'N', 0x00, 'C', 0x00, 0x00, 0x00},  /* bt Account Name */
     "MTK SYNC TOOL",                /* Server Address */
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
     "",                            /* User Name */
     "",                            /* Password */
     "./Contacts",                          /* Contact Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./Calendar",                          /* Calendar Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./Tasks",                          /* Task Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./Notes",                          /* Note Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* bookmark Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* email Address */
     "",                            /* User Name */
     "",                            /* Password */
     0x0001 | 0x0002 | 0x0004 | 0x0008 | 0x0010 | 0x0020 | 0x8000,   /* Validation */
     {
     #if (MMI_MAX_SIM_NUM>3)
     	CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
     #endif

	 #if (MMI_MAX_SIM_NUM>2)		
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	 #endif

	 #if (MMI_MAX_SIM_NUM>1)
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	 #endif
		
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID	
	},        /* Network ID */                 /* Network ID */
     "",                            /* Proxy hash */
     "",                            /* Provurl hash */
     0,                             /* Profile Type */
     0,                             /* Read only */
     1,                             /* Connection Type -- internet 0, BT 1 */
     0x01,                          /* App to sync only phonebook*/
     0,                             /* sync type - two-way sync*/
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#else
     0,
#endif
     0,                             /* regular sync - 0:none */
     0,                             /* regular sync notify */
     1,                             /* sync report 0:off 1:on */
     0,                             /* last_phb_anchor */
     0,                             /* last_cal_anchor */
     0,                             /* last_task_anchor */
     0,                             /* last_note_anchor */
     0,                             /* last_email_anchor */
     0,                             /* last_bkm_anchor */
     },
};

#else
nvram_ef_syncml_account_struct const NVRAM_EF_SYNCML_ACCOUNT_DEFAULT_FOR_NONE_PC_SYNC[NVRAM_EF_SYNCML_ACCOUNT_TOTAL] =
{
	{                               /* default profile 1 */
     0x01,                          /* Account ID */
     "",                            /* Account Name */
     "http://",                     /* Server Address */
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* Contact Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* Calendar Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* Task Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* Note Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* bookmark Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* email Address */
     "",                            /* User Name */
     "",                            /* Password */
     0x8000,                        /* Validation:valid data account*/
     {
     #if (MMI_MAX_SIM_NUM>3)
     	CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
     #endif

	 #if (MMI_MAX_SIM_NUM>2)		
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	 #endif

	 #if (MMI_MAX_SIM_NUM>1)
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	 #endif
		
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID	
	},        /* Network ID */
     "",                            /* Proxy hash*/
     "",                            /* Provurl hash*/
     0,                             /* Type */
     0,                             /* Read only*/
     0,                             /* Connection Type -- HTTP 0, WAP 1, BT 2 */
     0,                             /* App to sync */
     0,                             /* sync type - two-way sync*/
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#else
     0,
#endif
     0,                             /* regular sync - 0:none */
     0,                             /* regular sync notify */
     0,                             /* sync report 0:off 1:on */
     0,                             /* last_phb_anchor */
     0,                             /* last_cal_anchor */
     0,                             /* last_task_anchor */
     0,                             /* last_note_anchor */
     0,                             /* last_email_anchor */
     0,                             /* last_bkm_anchor */
     },
    {                               /* operator default Account 2 */
     0x02,                             /* Account ID */
     "",                            /* Account Name */
     "http://",                     /* Server Address */
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Contact Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Calendar Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Task Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Note Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* bookmark Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* email Address */
     "",                            /* User Name */
     "",                            /* Password */
     0x8000,                        /* Validation:valid data account*/     
	{
	#if (MMI_MAX_SIM_NUM>3)
		 CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	#endif

	#if (MMI_MAX_SIM_NUM>2)		 
		 CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	#endif
		 
	#if (MMI_MAX_SIM_NUM>1)
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	#endif

		CUSTOM_DEFAULT_SYNCML_DTCNT_ID  
	}, 	   /* Network ID */
     "",                            /* Proxy */
     "",                            /* Provurl*/
     0,                             /* Type */
     0,                             /* Read only*/
     0,                             /* Connection Type -- HTTP 0, WAP 1, BT 2 */
     0,                             /* App to sync */
     0,                             /* sync type - two-way sync*/
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#else
     0,
#endif
     0,                             /* regular sync - 0:none */
     0,                             /* regular sync notify */
     0,                             /* sync report 0:off 1:on */
     0,                             /* last_phb_anchor */
     0,                             /* last_cal_anchor */
     0,                             /* last_task_anchor */
     0,                             /* last_note_anchor */
     0,                             /* last_email_anchor */
     0,                             /* last_bkm_anchor */
     },
    {                               /* operator default profile 3 */
	 0x03,						   /* Account ID */
	 "", 						   /* Account Name */
	 "http://",					   /* Server Address */
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Contact Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Calendar Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Task Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                            /* Note Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* bookmark Address */
     "",                            /* User Name */
     "",                            /* Password */
     "./",                          /* email Address */
     "",                            /* User Name */
     "",                            /* Password */
     0x8000,                        /* Validation:valid data account*/    
     {
     #if (MMI_MAX_SIM_NUM>3)
     	CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
     #endif

	 #if (MMI_MAX_SIM_NUM>2)		
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	 #endif

	 #if (MMI_MAX_SIM_NUM>1)
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID,
	 #endif
		
		CUSTOM_DEFAULT_SYNCML_DTCNT_ID	
	},        /* Network ID */                 /* Network ID */
     "",                            /* Proxy hash */
     "",                            /* Provurl hash */
     0,                             /* Profile Type */
     0,                             /* Read only */
     0,                             /* Connection Type -- internet 0, BT 1 */
     0,                          /* App to sync only phonebook*/
     0,                             /* sync type - two-way sync*/
#ifdef __MMI_SYNCML_SERVER_ALERT_SYNC_SUPPORT__
/* under construction !*/
#else
     0,
#endif
     0,                             /* regular sync - 0:none */
     0,                             /* regular sync notify */
     0,                             /* sync report 0:off 1:on */
     0,                             /* last_phb_anchor */
     0,                             /* last_cal_anchor */
     0,                             /* last_task_anchor */
     0,                             /* last_note_anchor */
     0,                             /* last_email_anchor */
     0,                             /* last_bkm_anchor */
     },
};
#endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */
#endif /* __SYNCML_SUPPORT__ */

#if defined(__MMI_FWU_VIA_TFTP__)
static nvram_ef_dm_fwu_tftp_setting_struct const NVRAM_EF_DM_FWU_TFTP_SETTING_DEFAULT[]=
{
    {"172.22.216.28", 0,
    {'S', 0, 'U', 0, 'P', 0, 'E', 0, 'R', 0, 'M', 0, 'A', 0, 'N', 0, '2', 0, '9', 0, '_', 0, 'M', 0, 'A', 0, 'U', 0, 'I', 0, '_', 0, 'W', 0, '0', 0, '6', 0, '_', 0, '4', 0, '4', 0, '.', 0, 'c', 0, 'p', 0, 'r', 0}, 0,},
};
#endif /* #if defined(__MMI_FWU_VIA_TFTP__) */


#if defined(__MMI_FWU_VIA_HTTP__)
static nvram_ef_dm_fwu_http_setting_struct const NVRAM_EF_DM_FWU_HTTP_SETTING_DEFAULT[]=
{
	{"http://wap1.mtk.com.tw/",0},
};
#endif  /* #if defined(__MMI_FWU_VIA_HTTP__) */

/*Rahul*/
#if defined(OBIGO_Q03C_MMS_V01)
nvram_mmsv01_compose_settings_struct const NVRAM_EF_MMSV01_COMPOSE_SETTING_CONTENT_DEFAULT[]=
{
/*#ifdef CUSTOM_MMS_COMPOSE_SETTING_CONTENT_DEFAULT
    CUSTOM_MMS_COMPOSE_SETTING_CONTENT_DEFAULT
#else CUSTOM_MMS_COMPOSE_SETTING_CONTENT_DEFAULT*/
  {
      0,1,0,0,""
   },

};

nvram_mmsv01_sending_settings_struct const NVRAM_EF_MMSV01_SENDING_SETTING_CONTENT_DEFAULT[]=
{
/*#ifdef CUSTOM_MMS_SENDING_SETTING_CONTENT_DEFAULT
    CUSTOM_MMS_SENDING_SETTING_CONTENT_DEFAULT
#else CUSTOM_MMS_SENDING_SETTING_CONTENT_DEFAULT*/
  {
      5,0,0,1,0,0,5
   },
};
#endif

#ifdef __MMI_MMS_2__

nvram_umms_compose_settings_struct const NVRAM_EF_MMS_COMPOSE_SETTING_CONTENT_DEFAULT[]=
{

    #ifdef __MMI_SLIM_MMS_2__ 
        {
   	      0,0,255,1,20,0,0,"",5
       },
   #else

#ifdef CUSTOM_MMS_COMPOSE_SETTING_CONTENT_DEFAULT
    CUSTOM_MMS_COMPOSE_SETTING_CONTENT_DEFAULT
#else /*CUSTOM_MMS_COMPOSE_SETTING_CONTENT_DEFAULT*/
  {

      0,0,255,1,20,0,0,"","","","",5
   },
   #endif

#endif
};

nvram_umms_sending_settings_struct const NVRAM_EF_MMS_SENDING_SETTING_CONTENT_DEFAULT[]=
{
#ifdef CUSTOM_MMS_SENDING_SETTING_CONTENT_DEFAULT
    CUSTOM_MMS_SENDING_SETTING_CONTENT_DEFAULT
#else /*CUSTOM_MMS_SENDING_SETTING_CONTENT_DEFAULT*/
	#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
		{
		  0,1,0,1,0,0,0,0,255,0,1
	   },
	#else
  {
      0,0,0,1,0,0,0,0,255,0,1
   },
#endif
#endif
};

#ifndef WAP_SUPPORT
nvram_profile_content_struct const  NVRAM_EF_WAP_PROFILE_CONTENT_DEFAULT[NVRAM_PROFILE_MAX]=
{
#ifdef CUSTOM_WAP_PROFILE_CONTENT_DEFAULT
    CUSTOM_WAP_PROFILE_CONTENT_DEFAULT
#else
   { /* wap profile 1 - FET */
      1,0,80,"http://mobile.fetnet.net",10,-1,1,210,241,199,199,"",""
		  ,0
   },
   { /* wap profile 2 - CHT */
      1,0,8080,"http://wap.emome.net",11,-1,1,10,1,1,1,"",""
		  ,0
   },
   { /* wap profile 3 - Taiwan mobile */
      2,0,80,"http://ewap",12,-1,1,10,1,1,1,"",""
		  ,0
   },
   { /* wap profile 4 - CHINA MOBILE */
      1,0,80,"http://wap.monternet.com",14,-1,1,10,0,0,172,"",""
		  ,0
   },
   { /* wap profile 5 - Unicom */
      2,0,80,"http://wap.uni-info.com.cn",15,-1,1,10,0,0,172,"",""
		  ,0
   },
   { /* wap profile 6 - AIRTEL INDIA */
      1,0,8080,"http://www.google.com",17,-1,1,202,56,231,117,"",""
		  ,0
   },
	{ /* wap profile 7 - HUTCH INDIA */
      1,0,9401,"http://www.hutchworld.co.in",19,-1,1,10,10,1,100,"",""
		  ,0
   },
   { /* wap profile 8 - KGT */
      1,0,0,"",0,0,1,0,0,0,0,"",""
		  ,0
   },
   { /* wap profile 9 - Mobitai */
      1,0,0,"",0,0,1,0,0,0,0,"",""
		  ,0
   },
   { /* wap profile 10 - Empty */
      1,0,0,"",0,0,1,0,0,0,0,"",""
		  ,0
   }
#endif /*CUSTOM_WAP_PROFILE_CONTENT_DEFAULT*/
};

nvram_profile_content_struct const NVRAM_EF_MMS_PROFILE_CONTENT_DEFAULT[NVRAM_PROFILE_MAX] =
{
#ifdef CUSTOM_MMS_PROFILE_CONTENT_DEFAULT
    CUSTOM_MMS_PROFILE_CONTENT_DEFAULT
#else /*CUSTOM_MMS_PROFILE_CONTENT_DEFAULT*/
  { /* mms profile 1 - FET */
      1,0,80,"http://mms",10,-1,1,210,241,199,199,"",""
		  ,0
   },
   { /* mms profile 2 - CHT */
      1,0,8080,"http://mms.emome.net:8002",11,-1,1,10,1,1,1,"",""
		  ,0
   },
   { /* mms profile 3 - Taiwan mobile */
      1,0,80,"http://mms",12,-1,1,10,1,1,1,"",""
		  ,0
   },
   { /* mms profile 4 - CHINA MOBILE */
      1,0,80,"http://mmsc.monternet.com",14,-1,1,10,0,0,172,"",""
		  ,0
   },
   { /* mms profile 5 - Unicom */
      2,0,80,"http://mmsc.myuni.com.cn",15,-1,1,10,0,0,172,"",""
		  ,0
   },
   { /* mms profile 6 - AIRTEL INDIA */
      1,0,8080,"http://100.1.201.171:10021/mmsc",18,-1,1,100,1,201,172,"",""
		  ,0
   },
   { /* mms profile 7 - HUTCH INDIA */
      1,0,9401,"http://mms1.hutchworld.co.in/mms/",19,-1,1,10,10,1,100,"",""
		  ,0
   },
	{ /* mms profile 8 - KGT */
      1,0,0,"",0,0,1,0,0,0,0,"",""
		  ,0
   },
   { /* mms profile 9 - Mobitai */
      1,0,0,"",0,0,1,0,0,0,0,"",""
		  ,0
   },
   { /* mms profile 10 - Empty */
      1,0,0,"",0,0,1,0,0,0,0,"",""
		  ,0
   }
#endif /*CUSTOM_MMS_PROFILE_CONTENT_DEFAULT*/
 };

nvram_profile_name_array_struct const NVRAM_EF_WAP_PROFILE_NAMES_DEFAULT[NVRAM_PROFILE_MAX]=
{
#ifdef CUSTOM_WAP_PROFILE_NAMES_DEFAULT
    CUSTOM_WAP_PROFILE_NAMES_DEFAULT
#else
	2,0x00,1,0,{"FET"},
	2,0x00,1,1,{"CHT"},
	2,0x00,2,2,{"Taiwan Mobile"},
	2,0x00,1,3,{"China Mobile"},
	2,0x00,2,4,{"China Unicom"},
	2,0x00,1,5,{"Airtel"},
	2,0x00,1,6,{"Hutch"},
	2,0x00,2,0,{""},
	2,0x00,2,0,{""},
	2,0x00,2,0,{""}
#endif /*CUSTOM_WAP_PROFILE_NAMES_DEFAULT*/
};

nvram_profile_name_array_struct const NVRAM_EF_MMS_PROFILE_NAMES_DEFAULT[NVRAM_PROFILE_MAX]=
{
#ifdef CUSTOM_MMS_PROFILE_NAMES_DEFAULT
    CUSTOM_MMS_PROFILE_NAMES_DEFAULT
#else /*CUSTOM_MMS_PROFILE_NAMES_DEFAULT*/
	2,0x00,1,0,{"FET MMS"},
	2,0x00,1,1,{"CHT MMS"},
	2,0x00,1,2,{"Taiwan Mobile MMS"},
	2,0x00,1,3,{"China Mobile MMS"},
	2,0x00,2,4,{"China Unicom MMS"},
	2,0x00,1,5,{"Airtel MMS"},
	2,0x00,1,6,{"Hutch MMS"},
	2,0x00,2,0,{""},
	2,0x00,2,0,{""},
	2,0x00,2,0,{""}
#endif /*CUSTOM_MMS_PROFILE_NAMES_DEFAULT*/
};

#endif /* WAP_SUPPORT */
#endif /* __MMI_MMS_2__ */

#ifdef __WAP_PUSH_SUPPORT__
nvram_push_general_setting_struct const NVRAM_EF_PUSH_GEN_SETTING_DEFAULT[]=
{
#ifdef CUSTOM_WAP_PUSH_GEN_SET
	CUSTOM_WAP_PUSH_GEN_SET
#else
	2,0

#ifdef __MMI_WAP_PUSH_WHITE_LIST__
    ,1
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
    ,1
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */
#endif /* CUSTOM_WAP_PUSH_GEN_SET */
};
#endif /* __WAP_PUSH_SUPPORT__ */

#ifdef __MMI_BROWSER_2__
#ifdef __MMI_OP12_BRW_SEARCH_MENU__
kal_uint8 const WAP_CUSTOM_CFG_SEARCH_WEB_URL[] = {'h', 't', 't', 'p', ':', '/', '/',
'l', 'i', 'v', 'e', '.', 'v', 'o', 'd', 'a', 'f', 'o', 'n','e', '.', 'c', 'o', 'm', '\0'};
#endif /* __MMI_OP12_BRW_SEARCH_MENU__ */
#endif /* __MMI_BROWSER_2__ */

#if defined(__MMI_VIDEO_STREAM__)
/* 5 predefined URL */
/* "URL", "SERVER NAME" - in unicode */
static nvram_ef_video_predefined_url_struct const NVRAM_EF_VIDEO_PREDEFINED_URL_DEFAULT[NVRAM_EF_VIDEO_PREDEFINED_URL_COUNT]=
{
	{
        {'h', 0, 't', 0, 't', 0, 'p', 0, ':', 0, '/', 0, '/', 0, 'm', 0, '.', 0, 'y', 0, 'o', 0,
         'u', 0, 't', 0, 'u', 0, 'b', 0, 'e', 0, '.', 0, 'c', 0, 'o', 0, 'm', 0, '/', 0}, /* url 1 */
        {'Y', 0, 'o', 0, 'u', 0, 'T', 0, 'u', 0, 'b', 0, 'e', 0}   /* name 1 */
    }
#ifdef DEMO_PROJECT
    /* MTK internal test server */
	,{
	    {'h', 0, 't', 0, 't', 0, 'p', 0, ':', 0, '/', 0, '/', 0, 'w', 0, 'a', 0, 'p', 0, '1', 0,
         '.', 0, 'm', 0, 't', 0, 'k', 0, '.', 0, 'c', 0, 'o', 0, 'm', 0, '.', 0, 't', 0, 'w', 0,
         '/', 0}, /* url 2 */
        {'M', 0, 'T', 0, 'K', 0}   /* name 2 */
    }
#endif /* DEMO_PROJECT */
};

static nvram_ef_video_network_profile_struct const NVRAM_EF_VIDEO_NETWORK_PROFILE_DEFAULT[NVRAM_EF_VIDEO_NETWORK_PROFILE_TOTAL] =
{
    /* profile 1 */
    {
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {'P', 0, 'r', 0, 'o', 0, 'f', 0, 'i', 0, 'l', 0, 'e', 0, '1', 0}, /* profile_name */
        {
        #if (MMI_MAX_SIM_NUM > 3)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 2)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 1)
            CBM_DEFAULT_ACCT_ID,
        #endif
            CBM_DEFAULT_ACCT_ID
        },        /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 2 */
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {'P', 0, 'r', 0, 'o', 0, 'f', 0, 'i', 0, 'l', 0, 'e', 0, '2', 0}, /* profile_name */
        {
        #if (MMI_MAX_SIM_NUM > 3)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 2)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 1)
            CBM_DEFAULT_ACCT_ID,
        #endif
            CBM_DEFAULT_ACCT_ID
        },        /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 3 */
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {'P', 0, 'r', 0, 'o', 0, 'f', 0, 'i', 0, 'l', 0, 'e', 0, '3', 0}, /* profile_name */
        {
        #if (MMI_MAX_SIM_NUM > 3)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 2)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 1)
            CBM_DEFAULT_ACCT_ID,
        #endif
            CBM_DEFAULT_ACCT_ID
        },        /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 4 */
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {'P', 0, 'r', 0, 'o', 0, 'f', 0, 'i', 0, 'l', 0, 'e', 0, '4', 0}, /* profile_name */
        {
        #if (MMI_MAX_SIM_NUM > 3)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 2)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 1)
            CBM_DEFAULT_ACCT_ID,
        #endif
            CBM_DEFAULT_ACCT_ID
        },        /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 5 */
    {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {'P', 0, 'r', 0, 'o', 0, 'f', 0, 'i', 0, 'l', 0, 'e', 0, '5', 0}, /* profile_name */
        {
        #if (MMI_MAX_SIM_NUM > 3)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 2)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 1)
            CBM_DEFAULT_ACCT_ID,
        #endif
            CBM_DEFAULT_ACCT_ID
        },        /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    }
};

#endif  /* defined(__MMI_VIDEO_STREAM__) */

#if defined(__MMI_MEDIA_PLAYER_STREAM__) || defined(__MMI_KURO_SUPPORT__)
static nvram_ef_medply_settings_profile_struct const NVRAM_EF_MEDPLY_NETWORK_PROFILE_DEFAULT[NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL] =
{
    /* profile 1 */
    {
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0}, /* profile_name */
        {
        #if (MMI_MAX_SIM_NUM > 3)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 2)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 1)
            CBM_DEFAULT_ACCT_ID,
        #endif
            CBM_DEFAULT_ACCT_ID
        },        /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 2 */
    {
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        { 0, 0, 0, 0}, /* profile_name */
        {
        #if (MMI_MAX_SIM_NUM > 3)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 2)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 1)
            CBM_DEFAULT_ACCT_ID,
        #endif
            CBM_DEFAULT_ACCT_ID
        },        /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 3 */
    {
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0}, /* profile_name */
        {
        #if (MMI_MAX_SIM_NUM > 3)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 2)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 1)
            CBM_DEFAULT_ACCT_ID,
        #endif
            CBM_DEFAULT_ACCT_ID
        },        /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 4 */
    {
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0}, /* profile_name */
        {
        #if (MMI_MAX_SIM_NUM > 3)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 2)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 1)
            CBM_DEFAULT_ACCT_ID,
        #endif
            CBM_DEFAULT_ACCT_ID
        },        /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    },

    /* profile 5 */
    {
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0}, /* profile_name */
        {
        #if (MMI_MAX_SIM_NUM > 3)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 2)
            CBM_DEFAULT_ACCT_ID,
        #endif
        #if (MMI_MAX_SIM_NUM > 1)
            CBM_DEFAULT_ACCT_ID,
        #endif
            CBM_DEFAULT_ACCT_ID
        },        /* data account id */
        0,                              /* proxy_port */
        {0, 0, 0, 0},                   /* proxy_addr */
        0,                              /* proxy_on_off */
        32000,                          /* highest_udp_port */
        6970                            /* lowest_udp_port */
    }
};
#endif /* __MMI_MEDIA_PLAYER_STREAM__ __MMI_KURO_SUPPORT__*/

#ifdef __MMI_MEDIA_PLAYER_STREAM__
static nvram_ef_medply_video_predefined_url_struct const NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_DEFAULT[NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_COUNT]=
{
	{
        {'h', 0, 't', 0, 't', 0, 'p', 0, ':', 0, '/', 0, '/', 0, 'm', 0, '.', 0, 'y', 0, 'o', 0,
         'u', 0, 't', 0, 'u', 0, 'b', 0, 'e', 0, '.', 0, 'c', 0, 'o', 0, 'm', 0, '/', 0}, /* url 1 */
        {'Y', 0, 'o', 0, 'u', 0, 'T', 0, 'u', 0, 'b', 0, 'e', 0}   /* name 1 */
    }
#ifdef DEMO_PROJECT
    /* MTK internal test server */
	,{
	    {'h', 0, 't', 0, 't', 0, 'p', 0, ':', 0, '/', 0, '/', 0, 'w', 0, 'a', 0, 'p', 0, '1', 0,
         '.', 0, 'm', 0, 't', 0, 'k', 0, '.', 0, 'c', 0, 'o', 0, 'm', 0, '.', 0, 't', 0, 'w', 0,
         '/', 0}, /* url 2 */
        {'M', 0, 'T', 0, 'K', 0}   /* name 2 */
    }
#endif /* DEMO_PROJECT */
};
#endif

#ifdef __IOT__
nvram_ef_wifiap_mode_config_struct const COMMON_NVRAM_EF_WIFIAP_MODE_CONFIG_DEFAULT[NVRAM_EF_WIFIAP_MODE_CONFIG_TOTAL] =
{
    {1, "", "12345678"}
};
#endif /* __IOT__ */

#ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
static kal_uint8 const NVRAM_EF_DM_SR_NUMBER_DEFAULT[NVRAM_EF_DM_SR_NUMBER_SIZE] =
{
    #if defined(__OP01__)
	'1', '0', '6', '5', '4', '0', '4', '0', '\0'
    #elif defined(__OP02__)
	'1', '0', '6', '5', '5', '4', '5', '9', '\0'
    #else
	'0', '0', '0', '0', '0', '0', '0', '0', '\0' 
    #endif
};
#endif /* __MMI_DM_SELF_REGISTER_SUPPORT__ */


#ifdef __BIP_PULL_SUPPORT__
static kal_uint8 const NVRAM_EF_BT_BIP_SETTING_DEFAULT[NVRAM_EF_BT_BIP_SETTING_SIZE] =
{
	0, 0, 0, 0, 0, 0
};
#endif /* __MMI_BIP_SUPPORT__ */

#ifdef __MMI_IPSEC__
nvram_ef_ipsec_policy_struct const NVRAM_EF_IPSEC_POLICY_DEFAULT[] =
{
    0, {0, 0, 0, 0}, 0, {0, 0, 0, 0}, 1, 0, {0, 0, 0, 0}, 0, 2, 2
};
nvram_ef_ipsec_ike_struct const NVRAM_EF_IPSEC_IKE_DEFAULT[] =
{
    "", 0, 0, 0
};
#endif /* __MMI_IPSEC__ */

#if (defined __MMI_OP01_DCD__)
static kal_uint8 const NVRAM_EF_DCD_SETTING_DATA_DEFAULT[NVRAM_EF_DCD_SETTING_DATA_SIZE] = 
{
    0x01, 0x00, 0x00, 0x00, 0xFF, 0x01 
};
#elif (defined __MMI_OP01_DCD_V30__)
static kal_uint8 const NVRAM_EF_DCD_SETTING_DATA_DEFAULT[NVRAM_EF_DCD_SETTING_DATA_SIZE] = 
{
    0x01, 0x00, 0x01, 0x00, 0x01
};
#endif

#ifdef __MMI_EM_MISC_DCD__
#if (defined __DCD_V20__)
static kal_uint8 const NVRAM_EF_DCD_EM_PARAM_DATA_DEFAULT[NVRAM_EF_DCD_EM_PARAM_DATA_SIZE] = 
{
     'c',  'm',  'w',  'a',  'p', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* APN: 12B */
     'C',  'h',  'i',  'n',  'a',  ' ',  'M',  'o',  'b',  'i',  'l',  'e', /* APN name: 24B */
	 ' ',  'G',  'P',  'R',  'S', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 '0',  '1',  '0',  '.',  '0',  '0',  '0',  '.',  '0',  '0',  '0',  '.', /* gate way: 20B*/
	 '1',  '7',  '2', 0x00, 0x00, 0x00, 0x00, 0x00,
	 '8',  '0', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,                        /* port: 8B */

	 'h',  't',  't',  'p',  ':',  '/',  '/',  'd',  'c',  'd',  '.',  'm',  'o',  'n',  't', 'e', /* add channel: 64B */
     'r',  'n',  'e',  't',  '.',  'c',  'o',  'm',  '/',  's',  'e',  'r',  'v',  'i',  'c', 'e',
     '/',  'a',  'd',  'd',  'c',  'h',  'a',  'n',  'n',  'e',  'l', 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

	 'h',  't',  't',  'p',  ':',  '/',  '/',  'd',  'c',  'd',  '.',  'm',  'o',  'n',  't',  'e', /* delete channel: 64B */
     'r',  'n',  'e',  't',  '.',  'c',  'o',  'm',  '/',  's',  'e',  'r',  'v',  'i',  'c',  'e',
     '/',  'd',  'e',  'l',  'e',  't',  'e',  'c',  'h',  'a',  'n',  'n',  'e',  'l', 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

	 'h',  't',  't',  'p',  ':',  '/',  '/',  'd',  'c',  'd',  '.',  'm',  'o',  'n',  't',  'e',/* refresh: 64B */
     'r',  'n',  'e',  't',  '.',  'c',  'o',  'm',  '/',  'c',  'o',  'n',  't',  'e',  'n',  't',
     '/',  'r',  'e',  'f',  'r',  'e',  's',  'h', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 

	 'h',  't',  't',  'p',  ':',  '/',  '/',  'd',  'c',  'd',  '.',  'm',  'o',  'n',  't', 'e',/* help: 64B */
     'r',  'n',  'e',  't',  '.',  'c',  'o',  'm',  '/',  's',  'e',  'r',  'v',  'i',  'c', 'e',
     '/',  'h',  'e',  'l',  'p', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00    /* storage switch */
};
#elif (defined __DCD_V30__)
static kal_uint8 const NVRAM_EF_DCD_EM_PARAM_DATA_DEFAULT[NVRAM_EF_DCD_EM_PARAM_DATA_SIZE] = 
{
     'c',  'm',  'w',  'a',  'p', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, /* APN: 12B */
     'C',  'h',  'i',  'n',  'a',  ' ',  'M',  'o',  'b',  'i',  'l',  'e', /* APN name: 24B */
	 ' ',  'G',  'P',  'R',  'S', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	 '0',  '1',  '0',  '.',  '0',  '0',  '0',  '.',  '0',  '0',  '0',  '.', /* gate way: 20B*/
	 '1',  '7',  '2', 0x00, 0x00, 0x00, 0x00, 0x00,
	 '8',  '0', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,                        /* port: 8B */

    /* for cmcc test platform */
     'h',  't',  't',  'p',  ':',  '/',  '/',  '2',  '1',  '8',  '.',  '2',  '0',  '6',  '.', '1', /* add channel: 64B */
     '7',  '6',  '.',  '2',  '4',  '8',  ':',  '1',  '0',  '0',  '8',  '1',  '/',  's',  'e', 'r',
     'v',  'i',  'c',  'e',  '/',  'a',  'd',  'd',  'c',  'h',  'a',  'n',  'n',  'e',  'l', 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

     'h',  't',  't',  'p',  ':',  '/',  '/',  '2',  '1',  '8',  '.',  '2',  '0',  '6',  '.', '1', /* delete channel: 64B */
     '7',  '6',  '.',  '2',  '4',  '8',  ':',  '1',  '0',  '0',  '8',  '1',  '/',  's',  'e', 'r',
     'v',  'i',  'c',  'e',  '/',  'd',  'e',  'l',  'e',  't',  'e',  'c',  'h',  'a',  'n', 'n', 
     'e',  'l', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

     'h',  't',  't',  'p',  ':',  '/',  '/',  '2',  '1',  '8',  '.',  '2',  '0',  '6',  '.', '1', /* refresh: 64B */
     '7',  '6',  '.',  '2',  '4',  '8',  ':',  '1',  '0',  '0',  '8',  '0', 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

     // http://218.206.176.248:10081/service/help
     'h',  't',  't',  'p',  ':',  '/',  '/',  '2',  '1',  '8',  '.',  '2',  '0',  '6',  '.', '1', /* help: 64B */
     '7',  '6',  '.',  '2',  '4',  '8',  ':',  '1',  '0',  '0',  '8',  '1',  '/',  's',  'e', 'r',
     'v',  'i',  'c',  'e',  '/',  'h',  'e',  'l',  'p', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00    /* storage switch */
};
#endif
#endif /* __MMI_EM_MISC_DCD__ */



#ifdef __MMI_VUI_MAINMENU__
static kal_uint8 const NVRAM_EF_VENUS_MM_DEFAULT [NVRAM_EF_VENUS_MM_SIZE] =
{
   0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B
};
#endif /*__MMI_VUI_MAINMENU__*/
#ifdef __MMI_VUI_3D_MAINMENU__
static kal_uint8 const NVRAM_EF_VENUS_3D_MM_DEFAULT[NVRAM_EF_VENUS_3D_MM_SIZE] =
{
    0x00, 0x00
};
#endif
#ifdef __MMI_AZAAN_ALARM__
static mmi_hijri_azaan_nvram_struct const NVRAM_EF_AZAAN_ALARM_DEFAULT[NVRAM_AZAAN_ALARM_SIZE] =
{
    /* For Fajr */
    {
    0x05, 0X21, 0x00, 0x00,
    0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  },

    /* For Zuhr */
    {
    0x0C, 0x23, 0x00, 0x00,
    0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  },
    /* For Asr */
    {
    0x10, 0x2D, 0x00, 0x00,
    0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  },
    /* For Magrib */
    {
    0x12, 0x19, 0x00, 0x00,
    0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  },
    /* For Isha */
    {
    0x13, 0x24, 0x00, 0x00,
    0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  }
};
#endif /* __MMI_AZAAN_ALARM__ */

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
static kal_uint8 const NVRAM_EF_SRV_SMS_PDU_DEFAULT[] = {
                        /* status, 1 byte, unused flag */
                        0x00,
                        /* Reminder, 175 byte */
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                        0x00, 0x00, 0x00, 0x00, 0x00,
                        /* timestamp, 4 byte */
                        0x00, 0x00, 0x00, 0x00
                    #ifdef __SRV_SMS_MULTI_SIM__
                        /* sim_id, 2 byte */
                        , 0x01, 0x01
                    #endif
                    #ifdef __SRV_SMS_MULTI_ADDR__
                        /* addr_num, 2 byte */
                        , 0x00, 0x00
                        /* start_addr_id, 2 byte, invalid address ID */
                        , 0xFF, 0xFF
                    #endif
                    #ifdef __SRV_SMS_RESEND_COUNT__
                        /* resend_count, 1 byte */
                        , 0x00
                    #endif
                    #ifdef __SRV_SMS_DELIVERY_STATUS__
                        /* tp_st, 1 byte, invalid delivery status */
                        , 0xFF
                    #endif
                  };
#endif


#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
static nvram_ef_op11_hs32_hist_struct const NVRAM_EF_OP11_HS32_HIST_DEFAULT[NVRAM_EF_OP11_HS32_HIST_TOTAL] =
{
	{
		{0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* sidebar items */
		{
			{0x00, 0x01, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Call  0*/
			{0x00, 0x02, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Contacts (PHB) 1*/
#ifdef __MMI_UNIFIED_COMPOSER__
			{0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Message  2*/
#else
			{0x00, 0x01, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Message  2*/
#endif
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Email  3*/
			{0x00, 0x01, 0x02, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Orange Messenger  4*/
			{0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0xff, 0xff, 0xff, 0xff}, /* Orange World (WAP)  5*/
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Profile  6*/
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Alarms  7*/
			{0x00, 0x01, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Calendar  8*/
			{0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Music  9*/
			{0x00, 0x01, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Photography  10*/
#if defined(__MMI_BT_SUPPORT__) && defined(__MMI_WLAN_FEATURES__)
			{0x00, 0x01, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Connections (WIFI, BT, Flight Mode)  11*/
#elif defined(__MMI_WLAN_FEATURES__)
			{0x00, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Connections (WIFI, Flight Mode)  11*/
#elif defined(__MMI_BT_SUPPORT__)
			{0x01, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Connections (BT, Flight Mode)  11*/
#else
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Connections (Flight Mode)  11*/
#endif
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Device Status  12*/
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* SIM Toolkit  13*/
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* Take Photo 14 */
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* VIP Contacts 15 */
			{0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}, /* AP reserved (PHB for example) 16 */
			{0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff} /* */
		},
            {0xff, 0xff, 0xff, 0xff} /* wall paper panel */
	}
};
#endif /*defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)*/

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
#ifdef __SRV_CBS_SUPPORT__
static nvram_ef_srv_cbs_page_struct const NVRAM_EF_SRV_CBS_PAGE_DEFAULT[] =
                                                {
                                                    0xFFFF,
                                                    {0}
                                                };
static nvram_ef_srv_cbs_msg_node_struct const NVRAM_EF_SRV_CBS_MSG_NODE_DEFAULT[] =
                                                {
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0,
                                                    0xFFFF,
                                                    0
                                                };

static nvram_ef_srv_cbs_chnl_name_struct const NVRAM_EF_SRV_CBS_CHNL_NAME_DEFAULT[] =
                                                {
                                                    0xFFFF,
                                                    {0}
                                                };
#endif
#endif /* !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */

#ifdef __BT_SUPPORT__
#if defined(PLUTO_MMI) && defined(__LOW_COST_SUPPORT_COMMON__) // SLIM:memory reduction
static kal_uint8 const NVRAM_EF_SRV_BT_CM_DEFAULT[] = {
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xFF, 0xFF, 0xFF, 0xFF, 'M',  'T',  'K',  'B',
'T',  'D',  'E',  'V',  'I',  'C',  'E',  0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
#else
static kal_uint8 const NVRAM_EF_SRV_BT_CM_DEFAULT[] = {
0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xFF, 0xFF, 0xFF, 0xFF, 'M',  'T',  'K',  'B',
'T',  'D',  'E',  'V',  'I',  'C',  'E',  0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00
};
#endif  // SLIM:memory reduction


static kal_uint8 const NVRAM_EF_SRV_BT_CM_SYS_DEFAULT[] = {
    0xf0, 0x00, 0x00, 0x00,
#ifdef __MMI_BTBOX_NOLCD__
    'B',  'T',  'B',  'O',
    'X',  'N',  'o',  'L',
    'C',  'D',  0x00, 0x00,
#else /* __MMI_BTBOX_NOLCD__ */
    'M',  'T',  'K',  'B',
    'T',  'D',  'E',  'V',
    'I',  'C',  'E',  0x00,
#endif /* __MMI_BTBOX_NOLCD__ */
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};
#endif  /* __BT_SUPPORT__ */

#ifdef __BT_AUTO_DETECT_SUPPORT__
static kal_uint8 const NVRAM_EF_BT_AUTO_DETECT_SETTING_DEFAULT[NVRAM_EF_BT_AUTO_DETECT_SETTING_SIZE] =
{
	0x1,		/* show_bt_menu */
	0x1		/* auto_detect_bt_chip */
};
#endif /* __BT_AUTO_DETECT_SUPPORT__ */

#ifdef __MMI_PUSH_TURN_ON_OFF_SWITCH__
static kal_uint8 const NVRAM_EF_PUSH_SWITCH_SETTING_DEFAULT[NVRAM_EF_PUSH_SWITCH_SETTING_SIZE] = 
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
#endif
    0x01
};
#endif /* __MMI_PUSH_TURN_ON_OFF_SWITCH__ */

#ifdef __MMI_BROWSER_2__
#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
    #ifdef __GOOGLE_SEARCH_SUPPORT__
        const kal_uint8 COMMON_NVRAM_EF_WAP_HOMEPAGE_DEFAULT[] = {"http://www.google.com/m/search?client=ms-mtk"};
    #else
        #ifdef __MMI_SEARCH_WEB_BAIDU__ 
            const kal_uint8 COMMON_NVRAM_EF_WAP_HOMEPAGE_DEFAULT[] = {"http://www.google.com/m/search?client=ms-mtk-free"};
        #else
            const kal_uint8 COMMON_NVRAM_EF_WAP_HOMEPAGE_DEFAULT[] = {"http://www.google.com/m/search?client=ms-mtk"};
        #endif
    #endif
#endif
#endif /* __MMI_BROWSER_2__ */

#ifdef __MMI_VUI_LAUNCHER__
static kal_uint8 const NVRAM_EF_VAPP_DRAWER_ORDER_DATA_DEFAULT[NVRAM_EF_VAPP_DRAWER_ORDER_DATA_SIZE] = {0};
#endif /* __MMI_VUI_LAUNCHER__ */
#ifdef __MMI_VUI_LAUNCHER_KEY__
static kal_uint8 const NVRAM_EF_VAPP_KMM_ORDER_DATA_DEFAULT[NVRAM_EF_VAPP_KMM_ORDER_DATA_SIZE] = {0};
#endif

#ifdef __WIFI_SUPPORT__
static const kal_uint8 NVRAM_EF_WLAN_SETTING_DEFAULT[NVRAM_MAX_WLAN_SETTING_SIZE] = 
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00};
#endif /* __WIFI_SUPPORT__ */

#ifdef __MMI_VUI_LAUNCHER_KEY__
static const kal_uint8 NVRAM_EF_PHNSET_SHCUT_APP_LIST_DEFAULT[] = 
{
	'n','a','t','i','v','e','.','m','t','k','.','d','i','a','l','e','r', 0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0, 	
	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,  0, 
	'n','a','t','i','v','e','.','m','t','k','.','m','e','s','s','a','g','i','n','g', 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,
	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,	 0,  0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	
	'n','a','t','i','v','e','.','m','t','k','.','p','h','o','n','e','b','o','o','k', 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,
	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,	 0,  0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	 0,  0,  0,	
#ifdef __MMI_GB_WINGUO__
	'n','a','t','i','v','e','.','g','u','o','b','i','.','w','i','n','g','u','o','_','n','e','t', 0,  0,  0,  0,  0,  0,  0, 
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
#endif	 
#ifdef __MMI_MEDIA_PLAYER__
	'n','a','t','i','v','e','.','m','t','k','.','m','e','d','i','a','p','l','a','y','e','r', 0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
#else /* __MMI_MEDIA_PLAYER__ */
	'n','a','t','i','v','e','.','m','t','k','.','a','u','d','i','o','p','l','a','y','e','r', 0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
#endif /* __MMI_MEDIA_PLAYER__ */ 
#ifdef __MMI_MAINLCD_320X240__ /* 4 default shortcuts */ 
#if defined(__MMI_CAMCORDER__)
	'n','a','t','i','v','e','.','m','t','k','.','c','a','m','c','o','r','d','e','r', 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
#elif defined(__MMI_CAMERA__)
	'n','a','t','i','v','e','.','m','t','k','.','c','a','m','c','e','r','a', 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
#else
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
	 0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
#endif
#endif
};
#endif /* __MMI_VUI_LAUNCHER_KEY__ */

#ifdef __MMI_NSS_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__
    #ifdef __LOW_COST_SUPPORT_COMMON__
        static nvram_ef_srv_nss_struct  NVRAM_EF_SRV_NSS_PROFILE_DEFAULT[] = 
        {
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}
        };
    #else
        static nvram_ef_srv_nss_struct  NVRAM_EF_SRV_NSS_PROFILE_DEFAULT[] = 
        {
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0}
        };
    #endif/*__LOW_COST_SUPPORT_COMMON__*/
#else
    static nvram_ef_srv_nss_struct  NVRAM_EF_SRV_NSS_PROFILE_DEFAULT[] = 
        {
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},
        {0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}
        };
#endif 
#endif

#ifdef __MMI_MRE_MSPACE__
extern kal_int8 const  NVRAM_MSPACE_URL[]; 
#endif

#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
static const kal_uint8  NVRAM_EF_SYS_LANGUAGE_SSC_DEFAULT[NVRAM_EF_SYS_LANGUAGE_SSC_SIZE] =
{'*', '#', '0', '0', '4', '4', '#', 0x00, 0x00, 0x00};
#endif /*__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__*/

#if defined(__WIFI_SUPPORT__) && defined(__IOT__)
static nvram_ef_srv_dtcnt_wlan_scan_setting_struct NVRAM_EF_WLAN_SCAN_SETTING_DEFAULT[] = 
{
    {
        0x3C, 0x01, 0x00, 
        {
            {
                0x00, 
                {
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00
                }
            }, 
            {
                0x00, 
                {
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00
                }
            },
            {
                0x00, 
                {
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00
                }
            },
            {
                0x00, 
                {
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00
                }
            },
            {
                0x00, 
                {
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00
                }
            },
            {
                0x00, 
                {
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00
                }
            },
            {
                0x00, 
                {
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00
                }
            }
            
         }
    }
};
#endif


#ifndef __MMI_TELEPHONY_SUPPORT__
static nvram_ef_phone_lock_struct NVRAM_EF_PHONE_LOCK_DEFAULT=
{	
	{"1122"},
	0		
};
#endif /* __MMI_TELEPHONY_SUPPORT__ */

/**
 * Steps of defining logical data item:
 * 1> Define LID of new logical data item into `nvram_LID_cust_enum' in
 *    nvram_user_defs.h
 * 2> Define two constants: SIZE and TOTAL, in nvram_user_defs.h
 * 3> Define default value of that new logical data item in nvram_user_config.c
 * 4> Define attributes of that new logical data item into
 *    `logical_data_item_table_cust'
 * 5> Bypass.
 * 6> Change version number CODED_DATA_VERSION in nvram_user_config.c
 */
/**
 * The logical data item table.
 * Note:
 * Each logical data item must be:
 * 1> Size must be EVEN
 * 2> Size of default value must be equal to the logical data item's size.
 */
 /**
 * The rule for data item changes:
 * 1. To add a new data item, its name must be the next of the current last LID, for example,
 *     the last LID in the CT reign now is CT20, the new one must be CT21.
 * 2. Version must be increased if
 *    (a) Size is changed, or
 *    (b) Number of sections is changed, or
 *    (c) Attribute is changed, or
 *    (d) data structure is changed.
 */
ltable_entry_struct logical_data_item_table_common_app[] =
{
#ifdef __PHB_STORAGE_BY_MMI__
    #ifdef __MMI_TELEPHONY_SUPPORT__

    {
        NVRAM_EF_PHB_LID,
        NVRAM_EF_PHB_TOTAL,
        NVRAM_EF_PHB_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MP0C",
        VER(NVRAM_EF_PHB_LID)
    },
    #endif
#endif    

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    {
        NVRAM_EF_AUTOTEST_LID,
        NVRAM_EF_AUTOTEST_TOTAL,
        NVRAM_EF_AUTOTEST_SIZE ,
        NVRAM_NORMAL(NVRAM_EF_AUTOTEST_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP07",
        VER(NVRAM_EF_AUTOTEST_LID)
    },
#endif

#if defined(PLUTO_MMI) || defined(VENUS_MMI)
    {
        NVRAM_EF_CACHE_BYTE_LID,
        NVRAM_CACHE_TOTAL,
        NVRAM_CACHE_SIZE,
        NVRAM_CUSTPACK(NVRAM_EF_MMI_CACHE_BYTE_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE,
        "MM00",
        VER(NVRAM_EF_CACHE_BYTE_LID)
    },
    
    {
        NVRAM_EF_CACHE_SHORT_LID,
        NVRAM_CACHE_TOTAL,
        NVRAM_CACHE_SIZE,
        NVRAM_CUSTPACK(NVRAM_EF_MMI_CACHE_SHORT_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE,
        "MM01",
        VER(NVRAM_EF_CACHE_SHORT_LID)
    },
    
    {
        NVRAM_EF_CACHE_DOUBLE_LID,
        NVRAM_CACHE_TOTAL,
        NVRAM_CACHE_SIZE,
        NVRAM_CUSTPACK(NVRAM_EF_MMI_CACHE_DOUBLE_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE,
        "MM02",
        VER(NVRAM_EF_CACHE_DOUBLE_LID)
    },
    
    {
        NVRAM_EF_MMI_CACHE_BYTE_KEY_LID,
        NVRAM_MMI_CACHE_BYTE_KEY_TOTAL,
        NVRAM_MMI_CACHE_BYTE_KEY_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_MMI_CACHE_BYTE_KEY_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_NOT_ZIP_DEFAULT | NVRAM_ATTR_MULTI_DEFAULT,
        "MM03",
        VER(NVRAM_EF_MMI_CACHE_BYTE_KEY_LID)
    },
    
    {
        NVRAM_EF_MMI_CACHE_SHORT_KEY_LID,
        NVRAM_MMI_CACHE_SHORT_KEY_TOTAL,
        NVRAM_MMI_CACHE_SHORT_KEY_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_MMI_CACHE_SHORT_KEY_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_NOT_ZIP_DEFAULT | NVRAM_ATTR_MULTI_DEFAULT,
        "MM04",
        VER(NVRAM_EF_MMI_CACHE_SHORT_KEY_LID)
    },
    
    {
        NVRAM_EF_MMI_CACHE_DOUBLE_KEY_LID,
        NVRAM_MMI_CACHE_DOUBLE_KEY_TOTAL,
        NVRAM_MMI_CACHE_DOUBLE_KEY_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_MMI_CACHE_DOUBLE_KEY_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_NOT_ZIP_DEFAULT | NVRAM_ATTR_MULTI_DEFAULT,
        "MM05",
        VER(NVRAM_EF_MMI_CACHE_DOUBLE_KEY_LID)
    },
#endif

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    {
        NVRAM_EF_PHB_SOS_LID,
        NVRAM_EF_PHB_SOS_TOTAL,
        NVRAM_EF_PHB_SOS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP0E",
        VER(NVRAM_EF_PHB_SOS_LID)
    },

#if defined(__MMI_PHB_SPEED_DIAL__)
    {
        NVRAM_EF_PHB_SPEEDDIAL_LID,
        NVRAM_EF_PHB_SPEEDDIAL_TOTAL,
        NVRAM_EF_PHB_SPEEDDIAL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP0F",
        VER(NVRAM_EF_PHB_SPEEDDIAL_LID)
    },
#endif /* defined(__MMI_PHB_SPEED_DIAL__) */
    #ifdef __MMI_TELEPHONY_SUPPORT__

    {
        NVRAM_EF_PHB_FIELDS_LID,
        NVRAM_EF_PHB_FIELDS_TOTAL,
        NVRAM_EF_PHB_FIELDS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ,
        "MP0H",
        VER(NVRAM_EF_PHB_FIELDS_LID)
    },
    #endif
    {
        NVRAM_EF_PHB_FIELDS_MASK_LID,
        NVRAM_EF_PHB_FIELDS_MASK_TOTAL,
        NVRAM_EF_PHB_FIELDS_MASK_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIPLE,
        "MP0I",
        VER(NVRAM_EF_PHB_FIELDS_MASK_LID)
    },

#ifdef __MMI_PHB_CALLER_GROUP__
    {
        NVRAM_EF_PHB_GROUP_INFO_LID,
        NVRAM_EF_PHB_GROUP_INFO_TOTAL,
        NVRAM_EF_PHB_GROUP_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP0J",
        VER(NVRAM_EF_PHB_GROUP_INFO_LID)
    },
#endif /* __MMI_PHB_CALLER_GROUP__ */

    {
        NVRAM_EF_PHB_MY_NUMBER_LID,
        NVRAM_EF_PHB_MY_NUMBER_TOTAL,
        NVRAM_EF_PHB_MY_NUMBER_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP0K",
        VER(NVRAM_EF_PHB_MY_NUMBER_LID)
    },

#ifdef __MMI_PHB_CALLER_GROUP__
    {
        NVRAM_EF_PHB_GROUP_FIELD_LID,
        NVRAM_EF_PHB_GROUP_FIELD_TOTAL,
        NVRAM_EF_PHB_GROUP_FIELD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP0M",
        VER(NVRAM_EF_PHB_GROUP_FIELD_LID)
    },
#endif /* __MMI_PHB_CALLER_GROUP__ */

    {
        NVRAM_EF_PHB_INFO_LID,
        NVRAM_EF_PHB_INFO_TOTAL,
        NVRAM_EF_PHB_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP0Q",
        VER(NVRAM_EF_PHB_INFO_LID)
    },
#endif /* !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */

#ifdef __MMI_MESSAGES_PREDEFINED_TEMPLATE__
    {
        NVRAM_EF_SMS_LID,
        NVRAM_SMS_RECORD_TOTAL,
        NVRAM_SMS_TEMPL_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP0V",
        VER(NVRAM_EF_SMS_LID)
    },
#endif/*__MMI_MESSAGES_PREDEFINED_TEMPLATE__*/

#ifdef __DOWNLOAD__
    {
        NVRAM_EF_EMS_MY_PICTURE_NAME_LID,
        NVRAM_EMS_MY_PICTURE_NAME_RECORD_TOTAL,
        NVRAM_EMS_MY_PICTURE_NAME_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP0Z",
        VER(NVRAM_EF_EMS_MY_PICTURE_NAME_LID)
    },
    
    {
        NVRAM_EF_EMS_MY_ANIMATION_NAME_LID,
        NVRAM_EMS_MY_ANIMATION_NAME_RECORD_TOTAL,
        NVRAM_EMS_MY_ANIMATION_NAME_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP10",
        VER(NVRAM_EF_EMS_MY_ANIMATION_NAME_LID)
    },

    #ifdef __MMI_IMELODY_SUPPORT__
    {
        NVRAM_EF_EMS_MY_MELODY_NAME_LID,
        NVRAM_EMS_MY_MELODY_NAME_RECORD_TOTAL,
        NVRAM_EMS_MY_MELODY_NAME_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP11",
        VER(NVRAM_EF_EMS_MY_MELODY_NAME_LID)
    },
    #endif

#endif/*__DOWNLOAD__*/

#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
    {
        NVRAM_EF_CAMERA_SETTING_LID,
        NVRAM_EF_CAMERA_SETTING_TOTAL,
        NVRAM_EF_CAMERA_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP1B",
        VER(NVRAM_EF_CAMERA_SETTING_LID)
    },
#endif/* defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) */

#if defined (__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
    {
        NVRAM_EF_VIDEO_SETTING_LID,
        NVRAM_EF_VIDEO_SETTING_TOTAL,
        NVRAM_EF_VIDEO_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP1C",
        VER(NVRAM_EF_VIDEO_SETTING_LID)
    },
#endif/* defined (__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__) */

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    #ifdef __IP_NUMBER__
    {
        NVRAM_EF_IP_NUMBER_LID,
        NVRAM_IP_NUMBER_TOTAL,
        NVRAM_IP_NUMBER_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP1H",
        VER(NVRAM_EF_IP_NUMBER_LID)
    },
    #endif/*__IP_NUMBER__*/
#endif


#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
  #ifdef __no_remove__
    {
        NVRAM_EF_ALM_QUEUE_LID,
        NVRAM_ALM_QUEUE_TOTAL,
        NVRAM_ALM_QUEUE_SIZE ,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER ,
        NVRAM_ATTR_SW_VERNO_RESET,
        "MP1L",
        VER(NVRAM_EF_ALM_QUEUE_LID)
    },
  #endif
    
    {
        NVRAM_EF_ALM_SPOF_DATA_LID,
        NVRAM_ALM_SPOF_DATA_TOTAL,
        NVRAM_ALM_SPOF_DATA_SIZE ,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_SW_VERNO_RESET,
        "MP1M",
        VER(NVRAM_EF_ALM_SPOF_DATA_LID)
    },
    
    {
        NVRAM_EF_ALM_ALARM_DATA_LID,
        NVRAM_ALM_ALARM_DATA_TOTAL,
        NVRAM_ALM_ALARM_DATA_SIZE ,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_SW_VERNO_RESET,
        "MP1N",
        VER(NVRAM_EF_ALM_ALARM_DATA_LID)
    },
#endif /* #if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */

#ifdef __MMI_TODOLIST__
    {
        NVRAM_EF_TODO_LIST_LID,
        NVRAM_TODO_LIST_RECORD_TOTAL,
        NVRAM_TODO_LIST_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MP1O",
        VER(NVRAM_EF_TODO_LIST_LID)
    },
#endif/* __MMI_TODOLIST__ */

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
#if 0 /* Phased out greeting text */
/* under construction !*/
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
#endif /* #if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    {
        NVRAM_EF_GROUPLIST_LID,
        NVRAM_MAX_GROUP_NAME_TOTAL,
        NVRAM_MAX_GROUP_NAME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP1R",
        VER(NVRAM_EF_GROUPLIST_LID)
    },
#endif

#ifdef __MMI_FILE_MANAGER__
    {
        NVRAM_EF_WALLPAPER_FILENAME_LID,
        NVRAM_EF_WALLPAPER_FILENAME_TOTAL,
        NVRAM_EF_DISP_CACHE_SET_FILENAME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP1S",
        VER(NVRAM_EF_WALLPAPER_FILENAME_LID)
    },
#endif /* __MMI_FILE_MANAGER__ */

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    {
        NVRAM_EF_SHORTCUTS_LID,
        NVRAM_SHORTCUTS_TOTAL,
        NVRAM_SHORTCUTS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_SW_VERNO_RESET | NVRAM_ATTR_FACTORY_RESET,
        "MP1T",
        VER(NVRAM_EF_SHORTCUTS_LID)
    },
#endif


#ifdef __MMI_STOPWATCH__
    {
        NVRAM_EF_STOPWATCH_LID,
        NVRAM_EF_STOPWATCH_RECORD_TOTAL,
        NVRAM_EF_STOPWATCH_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP1W",
        VER(NVRAM_EF_STOPWATCH_LID)
    },
#endif/*__MMI_STOPWATCH__*/

#ifdef __MMI_PICTURE_EDITOR_SUPPORT__
    {
        NVRAM_PICTURE_EDITOR_LID,
        NVRAM_PICTURE_EDITOR_TOTAL,
        NVRAM_PICTURE_EDITOR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP1X",
        VER(NVRAM_PICTURE_EDITOR_LID)
    },
#endif/*__MMI_PICTURE_EDITOR_SUPPORT__*/

#ifdef __MMI_FM_RADIO__
    {
        NVRAM_EF_FM_RADIO_LID,
        NVRAM_EF_FM_RADIO_TOTAL,
        NVRAM_EF_FM_RADIO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
    #ifdef __MMI_FM_RADIO_SCHEDULER__
        NVRAM_CATEGORY_USER,
    #else
        NVRAM_CATEGORY_USER,
    #endif
        NVRAM_ATTR_AVERAGE,
        "MP1Z",
        VER(NVRAM_EF_FM_RADIO_LID)
    },
#endif/*__MMI_FM_RADIO__*/

#ifdef __MMI_FM_RADIO_SCHEDULE_REC__
    {
        NVRAM_EF_FMSR_SETTING_LID,
        NVRAM_EF_FMSR_SETTING_TOTAL,
        NVRAM_EF_FMSR_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP20",
        VER(NVRAM_EF_FMSR_SETTING_LID)
    },
#endif/*__MMI_FM_RADIO_SCHEDULE_REC__*/

#ifdef __MMI_VRSD__
    {
        NVRAM_EF_VRSD_TAG_LID,
        NVRAM_EF_VRSD_TAG_TOTAL,
        NVRAM_EF_VRSD_TAG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_CONFIDENTIAL,
        "MP21",
        VER(NVRAM_EF_VRSD_TAG_LID)
    },
#endif/*__MMI_VRSD__*/

#ifdef __MMI_VRSI__
    {
        NVRAM_EF_VRSI_TAG_LID,
        NVRAM_EF_VRSI_TAG_TOTAL,
        NVRAM_EF_VRSI_TAG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_CONFIDENTIAL,
        "MP22",
        VER(NVRAM_EF_VRSI_TAG_LID)
    },
#endif /* __MMI_VRSI__*/

#if NVRAM_EF_FMGR_FILEPATH_COUNT  /* not 0 */
    {
        NVRAM_EF_FMGR_FILEPATH_POOL_HEAD_LID,
        NVRAM_EF_FMGR_FILEPATH_POOL_HEAD_TOTAL,
        NVRAM_EF_FMGR_FILEPATH_POOL_HEAD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP23",
        VER(NVRAM_EF_FMGR_FILEPATH_POOL_HEAD_LID)
    },

    {
        NVRAM_EF_FMGR_FILEPATH_POOL_TAIL_LID,
        NVRAM_EF_FMGR_FILEPATH_POOL_TAIL_TOTAL,
        NVRAM_EF_FMGR_FILEPATH_POOL_TAIL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP24",
        VER(NVRAM_EF_FMGR_FILEPATH_POOL_TAIL_LID)
    },
#endif /* NVRAM_EF_FILEPATH_COUNT */

#ifdef __BT_SUPPORT__
    {
        NVRAM_EF_BT_INFO_LID,
        NVRAM_EF_BT_INFO_TOTAL,
        NVRAM_EF_BT_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_SRV_BT_CM_DEFAULT), //NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP25",
        VER(NVRAM_EF_BT_INFO_LID)
    },

    {
        NVRAM_EF_BT_DEV_LIST_LID,
        NVRAM_EF_BT_DEV_LIST_TOTAL,
        NVRAM_EF_BT_DEV_LIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP26",
        VER(NVRAM_EF_BT_DEV_LIST_LID)
    },

    {
        NVRAM_EF_BT_DEV_LIST_INDEX_LID,
        NVRAM_EF_BT_DEV_LIST_INDEX_TOTAL,
        NVRAM_EF_BT_DEV_LIST_INDEX_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP27",
        VER(NVRAM_EF_BT_DEV_LIST_INDEX_LID)
    },

    {
        NVRAM_EF_BT_SYS_INFO_LID,
        NVRAM_EF_BT_INFO_TOTAL,
        NVRAM_EF_BT_SYS_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_SRV_BT_CM_SYS_DEFAULT), //NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP29",
        VER(NVRAM_EF_BT_SYS_INFO_LID)
    },

#endif/*__BT_SUPPORT__*/

#ifdef __MMI_CM_BLACK_LIST__
    {
        NVRAM_EF_BLACK_LIST_LID,
        NVRAM_EF_BLACK_LIST_TOTAL,
        NVRAM_EF_BLACK_LIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP2A",
        VER(NVRAM_EF_BLACK_LIST_LID)
    },
#endif/*__MMI_CM_BLACK_LIST__*/

#if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif/* __MMI_IMPS__ */

#ifdef __MMI_AUDIO_EQUALIZER__
    {
        NVRAM_EF_AUDIO_EQUALIZER_LID,
        NVRAM_EF_AUDIO_EQUALIZER_TOTAL,
        NVRAM_EF_AUDIO_EQUALIZER_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_AUDIO_EQUALIZER_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_FACTORY_RESET | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MP2C",
        VER(NVRAM_EF_AUDIO_EQUALIZER_LID)
    },
#endif/*__MMI_AUDIO_EQUALIZER__*/

#ifdef __MMI_THEMES_APPLICATION__
    {
        NVRAM_EF_THEMES_VALUES,
        NVRAM_THEMES_VALUES_RECORDS,
        NVRAM_THEMES_VALUES_SIZE,
        NVRAM_NORMAL(NVRAM_THEMES_VALUES_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_FACTORY_RESET,
        "MP2G",
        VER(NVRAM_EF_THEMES_VALUES)
    },
#endif/*__MMI_THEMES_APPLICATION__*/

#ifdef __MMI_DOWNLOADABLE_THEMES_SUPPORT__
    {
        NVRAM_EF_THEME_MANAGER_LID,
        NVRAM_EF_THEME_MANAGER_RECORD_TOTAL,
        NVRAM_EF_THEME_MANAGER_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP2H",
        VER(NVRAM_EF_THEME_MANAGER_LID)
    },

    {
        NVRAM_EF_THEME_DOWNLOAD_LIST_LID,
        NVRAM_THEMES_DOWNLOAD_RECORDS,
        NVRAM_THEMES_DOWNLOAD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP2I",
        VER(NVRAM_EF_THEME_DOWNLOAD_LIST_LID)
    },
#endif/* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */

#ifdef __MMI_MOTION_APP__
    {
        NVRAM_EF_MOTION_DICE_LID,
        NVRAM_EF_MOTION_DICE_TOTAL,
        NVRAM_EF_MOTION_DICE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP2J",
        VER(NVRAM_EF_MOTION_DICE_LID)
    },

    {
        NVRAM_EF_MOTION_DJ_LID,
        NVRAM_EF_MOTION_DJ_TOTAL,
        NVRAM_EF_MOTION_DJ_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP2K",
        VER(NVRAM_EF_MOTION_DJ_LID)
    },
#endif/* __MMI_MOTION_APP__ */

#ifdef __MMI_BG_SOUND_EFFECT__
    {
        NVRAM_EF_BGSND_SETTING_LID,
        NVRAM_EF_BGSND_SETTING_TOTAL,
        NVRAM_EF_BGSND_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP2M",
        VER(NVRAM_EF_BGSND_SETTING_LID)
    },

    {
        NVRAM_EF_BGSND_FILEPATH_LID,
        NVRAM_EF_BGSND_FILEPATH_TOTAL,
        NVRAM_EF_BGSND_FILEPATH_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP2N",
        VER(NVRAM_EF_BGSND_FILEPATH_LID)
    },
#endif/* __MMI_BG_SOUND_EFFECT__ */

#ifdef __MMI_EBOOK_READER__
    {
        NVRAM_EF_EBOOK_SETTINGS_LID,
        NVRAM_EF_EBOOK_SETTING_TOTAL,
        NVRAM_EF_EBOOK_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_EBOOK_DEFAULT_VALUE),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_FACTORY_RESET,
        "MP30",
        VER(NVRAM_EF_EBOOK_SETTINGS_LID)
    },
#endif /* __MMI_EBOOK_READER__ */

#ifdef __MMI_BARCODEREADER__
    {
        NVRAM_EF_BARCODEREADER_SETTING_LID,
        NVRAM_EF_BARCODEREADER_SETTING_TOTAL,
        NVRAM_EF_BARCODEREADER_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP32",
        VER(NVRAM_EF_BARCODEREADER_SETTING_LID)
    },
#endif /* __MMI_BARCODEREADER__ */

#if defined(__MMI_A2DP_SUPPORT__)
    {
        NVRAM_EF_A2DP_SETTINGS_LID,
        1,
        sizeof(nvram_ef_a2dp_settings_struct),
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP36",
        VER(NVRAM_EF_A2DP_SETTINGS_LID)
    },
#endif /* __MMI_A2DP_SUPPORT__*/

#ifdef __MMI_VOIP__
    {
        NVRAM_EF_VOIP_PROF_LID,
        NVRAM_EF_VOIP_PROF_TOTAL,
        NVRAM_EF_VOIP_PROF_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP37",
        VER(NVRAM_EF_VOIP_PROF_LID)
    },

    {
        NVRAM_EF_VOIP_SETTING_LID,
        NVRAM_EF_VOIP_SETTING_TOTAL,
        NVRAM_EF_VOIP_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP38",
        VER(NVRAM_EF_VOIP_SETTING_LID)
    },
#endif /* __MMI_VOIP__*/

#ifdef __WIFI_SUPPORT__
    {
        NVRAM_EF_WLAN_SETTING_LID,
        NVRAM_MAX_WLAN_SETTING_TOTAL,
        NVRAM_MAX_WLAN_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_WLAN_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP39",
        VER(NVRAM_EF_WLAN_SETTING_LID)
    },

    {
        NVRAM_EF_WLAN_PROFILE_LID,
        NVRAM_MAX_WLAN_PROFILE_TOTAL,
        NVRAM_MAX_WLAN_PROFILE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP40",
        VER(NVRAM_EF_WLAN_PROFILE_LID)
    },
#endif /* __WIFI_SUPPORT__*/

#if defined(__EM_MODE__) && defined(__MMI_ENGINEER_MODE__)
    {
        NVRAM_EF_EM_NW_EVENT_RINGS_LID,
        NVRAM_EF_EM_NW_EVENT_RINGS_TOTAL,
        NVRAM_EF_EM_NW_EVENT_RINGS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT36",
        VER(NVRAM_EF_EM_NW_EVENT_RINGS_LID)
    },
#endif /* defined(__EM_MODE__) && defined(__MMI_ENGINEER_MODE__) */

#ifdef __MMI_NITZ__

    {
        NVRAM_EF_NITZ_NW_NAME_LID,
        NVRAM_NITZ_NW_NAME_TOTAL,
        NVRAM_NITZ_NW_NAME_SIZE ,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_SW_VERNO_RESET | NVRAM_ATTR_FACTORY_RESET,
        "MP42",
        VER(NVRAM_EF_NITZ_NW_NAME_LID)
    },
#endif /* __MMI_NITZ__ */

#if defined(__MMI_FWU_VIA_TFTP__)
    {
        NVRAM_EF_DM_FWU_TFTP_SETTING_LID,
        NVRAM_EF_DM_FWU_TFTP_SETTING_TOTAL,
        NVRAM_EF_DM_FWU_TFTP_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_DM_FWU_TFTP_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP43",
        VER(NVRAM_EF_DM_FWU_TFTP_SETTING_LID)
    },
#endif /* __MMI_FWU_VIA_TFTP__ */

#if defined(__MMI_FWU_VIA_HTTP__)
    {
        NVRAM_EF_DM_FWU_HTTP_SETTING_LID,
        NVRAM_EF_DM_FWU_HTTP_SETTING_TOTAL,
        NVRAM_EF_DM_FWU_HTTP_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_DM_FWU_HTTP_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP44",
        VER(NVRAM_EF_DM_FWU_HTTP_SETTING_LID)
    },
#endif /* #if defined(__MMI_FWU_VIA_HTTP__) */

#ifdef __MMI_AVATAR__
    {
        NVRAM_EF_AVATAR_SETTING_LID,
        NVRAM_EF_AVATAR_SETTING_TOTAL,
        NVRAM_EF_AVATAR_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP47",
        VER(NVRAM_EF_AVATAR_SETTING_LID)
    },
#endif /* __MMI_AVATAR__ */

#ifdef __MMI_BROWSER_2__
#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__

    {
        NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_LID,
        NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_RECORDS,
        NVRAM_EF_BRW_ADDRESS_HISTORY_RECORD_TITLE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP48",
        VER(NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_LID)
    },

    {
        NVRAM_EF_BRW_ADDRESS_HISTORY_URL_LID,
        NVRAM_EF_BRW_ADDRESS_HISTORY_URL_RECORDS,
        NVRAM_EF_BRW_ADDRESS_HISTORY_RECORD_URL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP49",
        VER(NVRAM_EF_BRW_ADDRESS_HISTORY_URL_LID)
    },
#endif /* #ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__ */
#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
    {
        NVRAM_EF_BRW_SEARCH_ITEM_LID,
        NVRAM_EF_BRW_SEARCH_ITEMS_RECORDS,
        NVRAM_EF_BRW_SEARCH_ITEM_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP41", 
        VER(NVRAM_EF_BRW_SEARCH_ITEM_LID)
    },
#endif /* __MMI_BRW_SEARCH_HISTORY_SUPPORT__ */
    #ifdef __MMI_BRW_ADVANCED_APP_FEATURES__
    {
        NVRAM_EF_BRW_LAST_WEB_ADDR_LID,
        NVRAM_EF_BRW_LAST_WEB_ADDR_RECORDS,
        NVRAM_EF_BRW_LAST_WEB_ADDR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP4A",
        VER(NVRAM_EF_BRW_LAST_WEB_ADDR_LID)
    },
    #endif /* __MMI_BRW_ADVANCED_APP_FEATURES__  */

#ifdef __MMI_BROWSER_2__
#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
    {
        NVRAM_EF_BRW_USER_DEFINED_HOMEPAGE_LID,
        NVRAM_EF_BRW_USER_DEFINED_HOMEPAGE_RECORDS,
        NVRAM_EF_BRW_USER_DEFINED_HOMEPAGE_SIZE,
        NVRAM_NORMAL(COMMON_NVRAM_EF_WAP_HOMEPAGE_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP4B",
        VER(NVRAM_EF_BRW_USER_DEFINED_HOMEPAGE_LID)
    },
#endif
#endif
#ifdef __MMI_Q05A_LAUNCH_SCREEN__
    {
        NVRAM_EF_BRW_SHORTCUTS_LIST_LID,
        NVRAM_EF_BRW_SHORTCUTS_LIST_RECORDS,
        NVRAM_EF_BRW_SHORTCUTS_LIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP51", 
        VER(NVRAM_EF_BRW_SHORTCUTS_LIST_LID)
    },
#endif /* __MMI_BRW_SEARCH_HISTORY_SUPPORT__ */
    #ifndef WAP_SUPPORT
    {
        NVRAM_EF_WAP_PROFILE_CONTENT_LID,
        NVRAM_EF_WAP_PROFILE_CONTENT_TOTAL,
        NVRAM_EF_WAP_PROFILE_CONTENT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_WAP_PROFILE_CONTENT_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_FACTORY_RESET | NVRAM_ATTR_MULTI_DEFAULT,
        "MP4D",
        VER(NVRAM_EF_WAP_PROFILE_CONTENT_LID)
    },

    {
        NVRAM_EF_WAP_PROFILE_NAMES_LID,
        NVRAM_EF_WAP_PROFILE_NAMES_TOTAL,
        NVRAM_EF_WAP_PROFILE_NAMES_SIZE,
        NVRAM_NORMAL(NVRAM_EF_WAP_PROFILE_NAMES_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4E",
        VER(NVRAM_EF_WAP_PROFILE_NAMES_LID)
    },

    {
        NVRAM_EF_MMS_PROFILE_CONTENT_LID,
        NVRAM_EF_MMS_PROFILE_CONTENT_TOTAL,
        NVRAM_EF_MMS_PROFILE_CONTENT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MMS_PROFILE_CONTENT_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_FACTORY_RESET | NVRAM_ATTR_MULTI_DEFAULT,
        "MP4F",
        VER(NVRAM_EF_MMS_PROFILE_CONTENT_LID)
    },

    {
        NVRAM_EF_MMS_PROFILE_NAMES_LID,
        NVRAM_EF_MMS_PROFILE_NAMES_TOTAL,
        NVRAM_EF_MMS_PROFILE_NAMES_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MMS_PROFILE_NAMES_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4G",
        VER(NVRAM_EF_MMS_PROFILE_NAMES_LID)
    },
    #endif /* WAP_SUPPORT */
#endif /* __MMI_BROWSER_2__ */

#ifdef __MMI_CSB_BROWSER__
    {
        NVRAM_EF_CSB_SETTINGS_LID,
        NVRAM_CSB_SETTINGS_TOTAL,
        NVRAM_CSB_SETTINGS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP4H",
        VER(NVRAM_EF_CSB_SETTINGS_LID),
    },
#endif /* __MMI_CSB_BROWSER__ */

#ifdef __MMI_VIDEO_STREAM__
    {
        NVRAM_EF_VIDEO_PREDEFINED_URL_LID,
        NVRAM_EF_VIDEO_PREDEFINED_URL_TOTAL,
        NVRAM_EF_VIDEO_PREDEFINED_URL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_VIDEO_PREDEFINED_URL_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP4I",
        VER(NVRAM_EF_VIDEO_PREDEFINED_URL_LID)
    },
#endif/*__MMI_VIDEO_STREAM__*/

#ifdef __MMI_VIDEO_STREAM__
    {
        NVRAM_EF_VIDEO_HISTORY_URL_LID,
        NVRAM_EF_VIDEO_HISTORY_URL_TOTAL,
        NVRAM_EF_VIDEO_HISTORY_URL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP4J",
        VER(NVRAM_EF_VIDEO_HISTORY_URL_LID)
    },
#endif/*__MMI_VIDEO_STREAM__*/

#ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
    {
        NVRAM_EF_DM_SR_NUMBER_LID,
        NVRAM_EF_DM_SR_NUMBER_TOTAL,
        NVRAM_EF_DM_SR_NUMBER_SIZE,
        NVRAM_NORMAL(NVRAM_EF_DM_SR_NUMBER_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP4K",
        VER(NVRAM_EF_DM_SR_NUMBER_LID)
    },
#endif /* __MMI_DM_SELF_REGISTER_SUPPORT__ */

#ifdef __MMI_CUSTOMER_SERVICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_CUSTOMER_SERVICE__ */

#if defined (__MMI_MMS_2__)
    {
        NVRAM_EF_UMMS_COMPOSE_SETTINGS_LID,
        NVRAM_UMMS_COMPOSE_SETTINGS_RECORDS,
        NVRAM_UMMS_COMPOSE_SETTINGS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MMS_COMPOSE_SETTING_CONTENT_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_FACTORY_RESET,
        "MP4N",
        VER(NVRAM_EF_UMMS_COMPOSE_SETTINGS_LID)
    },

    {
        NVRAM_EF_UMMS_SENDING_SETTINGS_LID,
        NVRAM_UMMS_SENDING_SETTINGS_RECORDS,
        NVRAM_UMMS_SENDING_SETTINGS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MMS_SENDING_SETTING_CONTENT_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4O",
        VER(NVRAM_EF_UMMS_SENDING_SETTINGS_LID)
    },
#endif

#if defined (OBIGO_Q03C_MMS_V01)
    {
        NVRAM_EF_MMSV01_COMPOSE_SETTINGS_LID,
        NVRAM_MMSV01_COMPOSE_SETTINGS_RECORDS,
        NVRAM_MMSV01_COMPOSE_SETTINGS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MMSV01_COMPOSE_SETTING_CONTENT_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4N",
        VER(NVRAM_EF_MMSV01_COMPOSE_SETTINGS_LID)
    },

    {
        NVRAM_EF_MMSV01_SENDING_SETTINGS_LID,
        NVRAM_MMSV01_SENDING_SETTINGS_RECORDS,
        NVRAM_MMSV01_SENDING_SETTINGS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MMSV01_SENDING_SETTING_CONTENT_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4O",
        VER(NVRAM_EF_MMSV01_SENDING_SETTINGS_LID)
    },
#endif

#ifdef __MMI_EMAIL_TEMPLATE__
    {
        NVRAM_EF_EMAIL_TEMPLATE_LID,
        NVRAM_EMAIL_RECORD_TOTAL,
        NVRAM_EMAIL_TEMPL_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP4P",
        VER(NVRAM_EF_EMAIL_TEMPLATE_LID)
    },
#endif/*__MMI_EMAIL_TEMPLATE__*/

#ifdef __MMI_LAUNCHER_APP_LIST__
    {
        NVRAM_EF_APPLIST_DATA_LID,
        NVRAM_EF_APPLIST_DATA_TOTAL,
        NVRAM_EF_APPLIST_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4R",
        VER(NVRAM_EF_APPLIST_DATA_LID)
    },
#endif /* __MMI_LAUNCHER_APP_LIST__ */

#ifdef __MMI_ATV_SUPPORT__
    {
        NVRAM_EF_MOBILE_TV_PLAYER_SETTING_LID,
        NVRAM_EF_MOBILE_TV_PLAYER_SETTING_TOTAL,
        NVRAM_EF_MOBILE_TV_PLAYER_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4S",
        VER(NVRAM_EF_MOBILE_TV_PLAYER_SETTING_LID)
    },
#endif /* __MMI_ATV_SUPPORT__ */

#ifdef __MMI_MOBILE_TV_CMMB_SUPPORT__
    {
        NVRAM_EF_DTV_PLAYER_SETTING_LID,
        NVRAM_EF_DTV_PLAYER_SETTING_TOTAL,
        NVRAM_EF_DTV_PLAYER_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4T",
        VER(NVRAM_EF_DTV_PLAYER_SETTING_LID)
    },
#endif /* __MMI_MOBILE_TV_CMMB_SUPPORT__ */

#ifdef __MMI_SLIDESHOW__
    {
        NVRAM_EF_SLIDE_SHOW_SETTING_LID,
        NVRAM_EF_SLIDE_SHOW_SETTING_TOTAL,
        NVRAM_EF_SLIDE_SHOW_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4U",
        VER(NVRAM_EF_SLIDE_SHOW_SETTING_LID)
    },
#endif/*__MMI_SLIDESHOW__*/

#ifdef __MMI_VIDEO_TELEPHONY__
    {
        NVRAM_EF_VT_SETTING_LID,
        NVRAM_EF_VT_SETTING_TOTAL,
        NVRAM_EF_VT_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4V",
        VER(NVRAM_EF_VT_SETTING_LID)
    },
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __BIP_PULL_SUPPORT__
    {
        NVRAM_EF_BT_BIP_SETTING_LID,
        NVRAM_EF_BT_BIP_SETTING_TOTAL,
        NVRAM_EF_BT_BIP_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_BT_BIP_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP4X",
        VER(NVRAM_EF_BT_BIP_SETTING_LID)
    },
#endif /* __MMI_BIP_SUPPORT__ */


#ifdef __MMI_BARCODEREADER__
    #if defined(__MMI_OP11_BARCODEREADER__)
/* under construction !*/
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

#ifdef __MMI_VIDEO_STREAM__
    {
        NVRAM_EF_VIDEO_NETWORK_PROFILE_LID,
        NVRAM_EF_VIDEO_NETWORK_PROFILE_TOTAL,
        NVRAM_EF_VIDEO_NETWORK_PROFILE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_VIDEO_NETWORK_PROFILE_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTI_DEFAULT,
        "MP55",
        VER(NVRAM_EF_VIDEO_NETWORK_PROFILE_LID)
    },
#endif/*__MMI_VIDEO_STREAM__*/

#if ((defined __MMI_OP01_DCD__) || (defined __MMI_OP01_DCD_V30__))
    {
        NVRAM_EF_DCD_SETTING_DATA_LID,
        NVRAM_EF_DCD_SETTING_DATA_TOTAL,
        NVRAM_EF_DCD_SETTING_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_DCD_SETTING_DATA_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP56",
        VER(NVRAM_EF_DCD_SETTING_DATA_LID)
    },
#endif

#ifdef __MMI_CAMCORDER__
    {
        NVRAM_EF_CAMCO_MAIN_SETTING_LID,
        NVRAM_EF_CAMCO_MAIN_SETTING_TOTAL,
        NVRAM_EF_CAMCO_MAIN_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP5D",
        VER(NVRAM_EF_CAMCO_MAIN_SETTING_LID)
    },

    {
        NVRAM_EF_CAMCO_MAIN_SETTING_SCENE_SEL_LID,
        NVRAM_EF_CAMCO_MAIN_SETTING_SCENE_SEL_TOTAL,
        NVRAM_EF_CAMCO_MAIN_SETTING_SCENE_SEL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP5E",
        VER(NVRAM_EF_CAMCO_MAIN_SETTING_SCENE_SEL_LID)
    },
#endif /* __MMI_CAMCORDER__ */


#if defined(__MMI_AUDPLY_MULTIPLE_LIST__)
    {
        NVRAM_EF_AUDPLY_LAST_PLAYLIST_PATH_LID,
        NVRAM_EF_AUDPLY_LIST_PLAYLIST_PATH_TOTAL,
        NVRAM_EF_AUDPLY_LIST_PLAYLIST_PATH_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP5K",
        VER(NVRAM_EF_AUDPLY_LAST_PLAYLIST_PATH_LID)
    },
#endif  /* __MMI_AUDPLY_MULTIPLE_LIST__ */

    /* phonebook vip contact */
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__) || defined (__MMI_VUI_WIDGET_KEY_VIP_CONTACT__)
    {
        NVRAM_EF_PHB_VIP_CONTACT_LID,
        NVRAM_EF_PHB_VIP_CONTACT_TOTAL,
        NVRAM_EF_PHB_VIP_CONTACT_SIZE,                
    #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_PHB_VIP_CONTACT_DEFAULT),
    #else
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
    #endif

    #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
    #else
        NVRAM_CATEGORY_USER /* | NVRAM_CATEGORY_FACTORY */,
    #endif
        NVRAM_ATTR_AVERAGE,
        "MP5L",
        VER(NVRAM_EF_PHB_VIP_CONTACT_LID)
    },
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__) */
    /* phonebook vip contact */

#ifdef __MMI_MESSAGES_SMS_EMAIL__
    {
        NVRAM_EF_SMS_EMAIL_LID,
        NVRAM_SMS_EMAIL_RECORD_TOTAL,
        NVRAM_SMS_EMAIL_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP5M",
        VER(NVRAM_EF_SMS_EMAIL_LID)
    },
#endif/*__MMI_MESSAGES_SMS_EMAIL__*/

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
#endif /* __MMI_OP11_HOMESCREEN__ */

#if defined(__MMI_BT_DEF_SEND_DEVICE__)
    {
        NVRAM_EF_BT_DEFDEVICE_LID,
        NVRAM_EF_BT_DEFDEVICE_TOTAL,
        NVRAM_EF_BT_DEFDEVICE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP5S",
        VER(NVRAM_EF_BT_DEFDEVICE_LID)
    },
#endif/*__MMI_BT_DEF_SEND_DEVICE__*/

#if defined(__MMI_TODOLIST__) && defined(__MMI_BIRTHDAY_REMINDER__)
    {
        NVRAM_EF_TDL_BR_LID,
        NVRAM_EF_TDL_BR_TOTAL,
        NVRAM_EF_TDL_BR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MP5T",
        VER(NVRAM_EF_TDL_BR_LID)
    },
#endif

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_OP12_TOOLBAR__)
    {
        NVRAM_EF_SMS_VOICEMAIL_TIME_LID,
        NVRAM_EF_SMS_VOICEMAIL_TIME_TOTAL,
        NVRAM_EF_SMS_VOICEMAIL_TIME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP5V",
        VER(NVRAM_EF_SMS_VOICEMAIL_TIME_LID)
    },
#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_OP12_TOOLBAR__) */

#if defined (__FLAVOR_VENDOR_SDK__) || defined(__MAUI_SDK_TEST__)
    {
        NVRAM_EF_VS_SETTING_LID,
        NVRAM_EF_VS_SETTING_TOTAL,
        NVRAM_EF_VS_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP5Z",
        VER(NVRAM_EF_VS_SETTING_LID)
    },
#endif

#ifdef __MMI_IPSEC__
    {
       NVRAM_EF_IPSEC_POLICY_LID,
       NVRAM_EF_IPSEC_POLICY_TOTAL,
       NVRAM_EF_IPSEC_POLICY_SIZE,
       NVRAM_NORMAL(NVRAM_EF_IPSEC_POLICY_DEFAULT),
       NVRAM_CATEGORY_USER,
       NVRAM_ATTR_AVERAGE,
       "MP60",
       VER(NVRAM_EF_IPSEC_POLICY_LID)
    },

    {
       NVRAM_EF_IPSEC_IKE_LID,
       NVRAM_EF_IPSEC_IKE_TOTAL,
       NVRAM_EF_IPSEC_IKE_SIZE,
       NVRAM_NORMAL(NVRAM_EF_IPSEC_IKE_DEFAULT),
       NVRAM_CATEGORY_USER,
       NVRAM_ATTR_AVERAGE,
       "MP61",
       VER(NVRAM_EF_IPSEC_IKE_LID)
    },
#endif /* __MMI_IPSEC__ */

#ifdef __OP11__ /*__MMI_PHB_ICE_CONTACT__ */
    {
        NVRAM_EF_PHB_ICE_CONTACT_LID,
        NVRAM_EF_PHB_ICE_CONTACT_TOTAL,
        NVRAM_EF_PHB_ICE_CONTACT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP63",
        VER(NVRAM_EF_PHB_ICE_CONTACT_LID)
    },
#endif /* __OP11__ */

#ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
    {
        NVRAM_EF_SMS_UD_TMEP_LID,
        NVRAM_SMS_UD_RECORD_TOTAL,
        NVRAM_SMS_UD_TEMPL_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP68",
        VER(NVRAM_EF_SMS_UD_TMEP_LID)
    },
#endif/*__MMI_MESSAGES_USERDEFINED_TEMPLATE__*/

#if defined(__SYNCML_SUPPORT__) 
    {
        NVRAM_EF_SYNCML_VIEW_LOG_LID,
        NVRAM_EF_SYNCML_VIEW_LOG_TOTAL,
        NVRAM_EF_SYNCML_VIEW_LOG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
    #ifdef __MMI_SYNCML_RESTORE_FACTORY_DEFAULT__
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
    #else
        NVRAM_ATTR_AVERAGE,
    #endif /* __MMI_SYNCML_RESTORE_FACTORY_DEFAULT__ */
        "MP69",
        VER(NVRAM_EF_SYNCML_VIEW_LOG_LID)
    },
#endif 

#ifdef __MMI_BCR__
    {
       NVRAM_EF_BCR_SETTING_LID,
       NVRAM_EF_BCR_SETTING_TOTAL,
       NVRAM_EF_BCR_SETTING_SIZE,
       NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
       NVRAM_CATEGORY_USER,
       NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
       "MP6A",
       VER(NVRAM_EF_BCR_SETTING_LID)
    },
#endif /* __MMI_BCR__ */

#ifdef __MMI_AUTO_ANSWER_MACHINE__
    {
        NVRAM_EF_ANSWER_MACHINE_SETTING_LID,
        NVRAM_EF_ANSWER_MACHINE_SETTING_TOTAL,
        NVRAM_EF_ANSWER_MACHINE_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP6B",
        VER(NVRAM_EF_ANSWER_MACHINE_SETTING_LID)
    },
#endif/*__MMI_AUTO_ANSWER_MACHINE__*/

#ifdef __MMI_OP12_TOOLBAR__
    {
        NVRAM_EF_TOOLBAR_CNTX_LID,
        NVRAM_EF_TOOLBAR_CNTX_TOTAL,
        NVRAM_EF_TOOLBAR_CNTX_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP6C",
        VER(NVRAM_EF_TOOLBAR_CNTX_LID)
    },
#endif /* __MMI_OP12_TOOLBAR__ */

#ifdef __MMI_MEDIA_PLAYER__
    {
      NVRAM_EF_MEDPLY_SETTINGS_LID,
      NVRAM_EF_MEDPLY_SETTINGS_TOTAL,
      NVRAM_EF_MEDPLY_SETTINGS_SIZE,
      NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
      NVRAM_CATEGORY_USER,
      NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
      "MP6D",
      VER(NVRAM_EF_MEDPLY_SETTINGS_LID)
    },
    
    #if defined(__MMI_MEDIA_PLAYER_STREAM__) || defined(__MMI_KURO_SUPPORT__)
    {
      NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_LID,
      NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL,
      NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_SIZE,
      NVRAM_NORMAL(NVRAM_EF_MEDPLY_NETWORK_PROFILE_DEFAULT),
      NVRAM_CATEGORY_USER,
      NVRAM_ATTR_MULTI_DEFAULT,
      "MP6E",
      VER(NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_LID)
    },
    #endif /* (__MMI_MEDIA_PLAYER_STREAM__) || defined(__MMI_KURO_SUPPORT__)*/

    #if defined(__MMI_MEDIA_PLAYER_STREAM__)
        #ifdef __MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__
            {
                  NVRAM_EF_MEDPLY_HISTORY_URL_LID,
                  NVRAM_EF_MEDPLY_HISTORY_URL_TOTAL,
                  NVRAM_EF_MEDPLY_HISTORY_URL_SIZE,
                  NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
                  NVRAM_CATEGORY_USER,
                  NVRAM_ATTR_AVERAGE,
                  "MP6F",
                  VER(NVRAM_EF_MEDPLY_HISTORY_URL_LID)
            },
        #endif  /* __MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__ */
    #endif
    {
       NVRAM_EF_MEDPLY_LAST_PLAYLIST_PATH_LID,
       NVRAM_EF_MEDPLY_LIST_PLAYLIST_PATH_TOTAL,
       NVRAM_EF_MEDPLY_LIST_PLAYLIST_PATH_SIZE,
       NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
       NVRAM_CATEGORY_USER,
       NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
       "MP6G",
       VER(NVRAM_EF_MEDPLY_LAST_PLAYLIST_PATH_LID)
    },
#endif

#ifdef __WAP_PUSH_SUPPORT__
    {
        NVRAM_EF_PUSH_GEN_SETTING_LID,
        NVRAM_EF_PUSH_GEN_SETTING_TOTAL,
        NVRAM_EF_PUSH_GEN_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_PUSH_GEN_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP6I",
        VER(NVRAM_EF_PUSH_GEN_SETTING_LID)
    },

    #ifdef __MMI_WAP_PUSH_BLACK_LIST__
    {
        NVRAM_EF_PUSH_BLACK_LIST_LID,
        NVRAM_EF_PUSH_BLACK_LIST_TOTAL,
        NVRAM_EF_PUSH_BLACK_LIST_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_PUSH_BLACK_LIST_DEFAULT),
        NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        "MP6J",
        VER(NVRAM_EF_PUSH_BLACK_LIST_LID)
    },
    #endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

    #ifdef __MMI_WAP_PUSH_WHITE_LIST__
    {
        NVRAM_EF_PUSH_WHITE_LIST_LID,
        NVRAM_EF_PUSH_WHITE_LIST_TOTAL,
        NVRAM_EF_PUSH_WHITE_LIST_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_PUSH_WHITE_LIST_DEFAULT),
        NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        "MP6K",
        VER(NVRAM_EF_PUSH_WHITE_LIST_LID)
    },
    #endif /* __MMI_WAP_PUSH_WHITE_LIST__ */
#endif /* __WAP_PUSH_SUPPORT__ */

#if !defined(__MMI_EM_INET_APP_SLIM__) && defined(__MMI_ENGINEER_MODE__)
    /* Internet Application */
    {
        NVRAM_EF_INET_CUSTPACK_LID,
        NVRAM_EF_INET_CUSTPACK_TOTAL,
        NVRAM_EF_INET_CUSTPACK_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_INET_CUSTPACK_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE,
        "MP6L",
        VER(NVRAM_EF_INET_CUSTPACK_LID)
    },
#endif

#ifdef __MMI_IPSEC__
    {
       NVRAM_EF_IPSEC_PROFILE_NAME_LID,
       NVRAM_EF_IPSEC_PROFILE_NAME_TOTAL,
       NVRAM_EF_IPSEC_PROFILE_NAME_SIZE,
       NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
       NVRAM_CATEGORY_USER,
       NVRAM_ATTR_AVERAGE,
       "MP6M",
       VER(NVRAM_EF_IPSEC_PROFILE_NAME_LID)
    },
#endif /* __MMI_IPSEC__ */

#if defined(__MMI_PICT_BRIDGE_SUPPORT__)
    {
        NVRAM_EF_PICTBRIDGE_LID,
        NVRAM_EF_PICTBRIDGE_TOTAL,
        NVRAM_EF_PICTBRIDGE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP6N",
        VER(NVRAM_EF_PICTBRIDGE_LID)
    },
#endif/* __MMI_PICT_BRIDGE_SUPPORT__*/

#ifdef __MMI_SYNCML_DEVICE_SYNC__
    {
        NVRAM_EF_SYNCML_DEV_SETTING_LID,
        NVRAM_EF_SYNCML_DEV_SETTING_TOTAL,
        NVRAM_EF_SYNCML_DEV_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP6O",
        VER(NVRAM_EF_SYNCML_DEV_SETTING_LID)
    },

    {
        NVRAM_EF_SYNCML_DEV_ACCOUNT_LID,
        NVRAM_EF_SYNCML_DEV_ACCOUNT_TOTAL,
        NVRAM_EF_SYNCML_DEV_ACCOUNT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP6P",
        VER(NVRAM_EF_SYNCML_DEV_ACCOUNT_LID)
    },

    {
        NVRAM_EF_SYNCML_DEV_SYNC_LOG_LID,
        NVRAM_EF_SYNCML_DEV_SYNC_LOG_TOTAL,
        NVRAM_EF_SYNCML_DEV_SYNC_LOG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP6Q",
        VER(NVRAM_EF_SYNCML_DEV_SYNC_LOG_LID)
    },
#endif/* __MMI_SYNCML_DEVICE_SYNC__ */

#ifdef __MMI_BROWSER_2__
    {
        NVRAM_EF_WAP_BOOKMARK_LIST_LID,
        NVRAM_EF_WAP_BOOKMARK_LIST_TOTAL_RECORDS,
        NVRAM_EF_WAP_BOOKMARK_LIST_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_WAP_BOOKMARK_LIST_DEFAULT),
        NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_MULTI_DEFAULT,
        "MP6R",
        VER(NVRAM_EF_WAP_BOOKMARK_LIST_LID)
    },
#endif /* __MMI_BROWSER_2__ */

#ifdef __MMI_CM_WHITE_LIST__
    {
        NVRAM_EF_WHITE_LIST_LID,
        NVRAM_EF_WHITE_LIST_TOTAL,
        NVRAM_EF_WHITE_LIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP6S",
        VER(NVRAM_EF_WHITE_LIST_LID)
    },
#endif/*__MMI_CM_WHITE_LIST__*/

#ifdef __MMI_FM_RADIO_SCHEDULER__
    {
        NVRAM_EF_FMRDO_SCHEDULER_LID,
        NVRAM_EF_FMRDO_SCHEDULER_TOTAL,
        NVRAM_EF_FMRDO_SCHEDULER_SIZE,
        NVRAM_NORMAL(NVRAM_FMRDO_SCHEDULER_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP6U",
        VER(NVRAM_EF_FMRDO_SCHEDULER_LID)
    },
#endif /* __MMI_FM_RADIO_SCHEDULER__ */

#ifdef __MMI_BCR__
    {
       NVRAM_EF_BCR_FIELD_SET_LID,
       NVRAM_EF_BCR_FIELD_SET_TOTAL,
       NVRAM_EF_BCR_FIELD_SET_SIZE,
       NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
       NVRAM_CATEGORY_USER,
       NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
       "MP6V",
       VER(NVRAM_EF_BCR_FIELD_SET_LID)
    },
#endif /* __MMI_BCR__ */

#ifdef __BIP_PULL_SUPPORT__
    {
        NVRAM_EF_BT_BIP_SET_FOLDER_LID,
        NVRAM_EF_BT_BIP_SETTING_TOTAL,
        NVRAM_EF_BT_BIP_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_BT_BIP_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP6W",
        VER(NVRAM_EF_BT_BIP_SET_FOLDER_LID)
    },
#endif /* __MMI_BIP_SUPPORT__ */

#ifdef __MMI_MEDIA_PLAYER_STREAM__
    {
        NVRAM_EF_MEDPLY_PREDEFINED_URL_LID,
        NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_TOTAL,
        NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP6Y",
        VER(NVRAM_EF_MEDPLY_PREDEFINED_URL_LID)
    },
#endif

#ifdef __MMI_CAMCORDER__
    {
        NVRAM_EF_CAMCO_APP_INFO_LID,
        NVRAM_EF_CAMCO_APP_INFO_TOTAL,
        NVRAM_EF_CAMCO_APP_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP7P",
        VER(NVRAM_EF_CAMCO_APP_INFO_LID)
    },

    #ifdef DUAL_CAMERA_SUPPORT
    {
        NVRAM_EF_CAMCO_SUB_SETTING_LID,
        NVRAM_EF_CAMCO_SUB_SETTING_TOTAL,
        NVRAM_EF_CAMCO_SUB_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP7Q",
        VER(NVRAM_EF_CAMCO_SUB_SETTING_LID)
    },

    {
        NVRAM_EF_CAMCO_SUB_SETTING_SCENE_SEL_LID,
        NVRAM_EF_CAMCO_SUB_SETTING_SCENE_SEL_TOTAL,
        NVRAM_EF_CAMCO_SUB_SETTING_SCENE_SEL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP7R",
        VER(NVRAM_EF_CAMCO_SUB_SETTING_SCENE_SEL_LID)
    },
    #endif /* DUAL_CAMERA_SUPPORT */
#endif /* __MMI_CAMCORDER__ */

#ifdef __EMAIL__
    /* Email Data Account */
    {
        NVRAM_EF_EMAIL_DATA_ACCOUNT_LID,
        NVRAM_EF_EMAIL_DATA_ACCOUNT_TOTAL,
        NVRAM_EF_EMAIL_DATA_ACCOUNT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ,
        "MP7S",
        VER(NVRAM_EF_EMAIL_DATA_ACCOUNT_LID)
    },
#endif/* defined(ISP_SUPPORT) && defined(DRV_ISP_6235_SERIES) && defined(BACKUP_SENSOR_SUPPORT) */

#ifdef __SYNCML_SUPPORT__
    {
        NVRAM_EF_SYNCML_ACCOUNT_LID,
        NVRAM_EF_SYNCML_ACCOUNT_TOTAL,
        NVRAM_EF_SYNCML_ACCOUNT_SIZE,
    #ifdef CUSTOM_SYNCML_ACCOUNT_DEFAULT
        NVRAM_NORMAL(NVRAM_EF_SYNCML_ACCOUNT_DEFAULT),       
    #else /* CUSTOM_SYNCML_ACCOUNT_DEFAULT */
        #ifdef __MMI_SYNCML_PC_SYNC_SUPPORT__
            NVRAM_NORMAL(NVRAM_EF_SYNCML_ACCOUNT_DEFAULT_FOR_PC_SYNC),
        #else /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */
            NVRAM_NORMAL(NVRAM_EF_SYNCML_ACCOUNT_DEFAULT_FOR_NONE_PC_SYNC),
        #endif /* __MMI_SYNCML_PC_SYNC_SUPPORT__ */
    #endif /* CUSTOM_SYNCML_ACCOUNT_DEFAULT */

    NVRAM_CATEGORY_USER,
    
    #ifdef CUSTOM_SYNCML_ACCOUNT_DEFAULT
        #ifndef __MMI_SYNCML_RESTORE_FACTORY_DEFAULT__
            NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_FACTORY_RESET,
        #else
            NVRAM_ATTR_MULTI_DEFAULT,
        #endif /* __MMI_SYNCML_RESTORE_FACTORY_DEFAULT__ */

    #else /* CUSTOM_SYNCML_ACCOUNT_DEFAULT */
            NVRAM_ATTR_MULTI_DEFAULT,
    #endif /* CUSTOM_SYNCML_ACCOUNT_DEFAULT */
        "MP7V",
        VER(NVRAM_EF_SYNCML_ACCOUNT_LID)
    },
#endif /* __SYNCML_SUPPORT__ */


     #ifdef __MMI_ECOMPASS__
    {
       NVRAM_EF_ECOMPASS_LID,
       NVRAM_EF_ECOMPASS_TOTAL,
       NVRAM_EF_ECOMPASS_SIZE,
       NVRAM_NORMAL(NVRAM_EF_ECOMPASS_DEFAULT),
       NVRAM_CATEGORY_USER,
       NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_MULTI_DEFAULT,
       "MP83",
       VER(NVRAM_EF_ECOMPASS_LID)
    },
   #endif /* __MMI_ECOMPASS__ */

#ifdef __MMI_NOTE_APP__
    {
        NVRAM_EF_NOTE_APP_LID,
        NVRAM_EF_NOTE_LIST_TOTAL,
        NVRAM_EF_NOTE_NODE_STRUCT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP84",
        VER(NVRAM_EF_NOTE_APP_LID)
    },
#endif /* __MMI_NOTE_APP__ */

#ifdef __MMI_SEARCH_WEB__
    {
        NVRAM_EF_SEARCH_WEB_HISTORY_LID,
        NVRAM_EF_SEARCH_WEB_HISTORY_TOTAL,
        NVRAM_EF_SEARCH_WEB_HISTORY_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP85",
        VER(NVRAM_EF_SEARCH_WEB_HISTORY_LID)
    },
#endif /* __MMI_SEARCH_WEB__ */

#ifdef __MMI_SEARCH_WEB_BAIDU__
    {
        NVRAM_EF_SEARCH_WEB_BAIDU_UID_LID,
        NVRAM_EF_SEARCH_WEB_BAIDU_UID_TOTAL,
        NVRAM_EF_SEARCH_WEB_BAIDU_UID_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER, 
        NVRAM_ATTR_AVERAGE,
        "MP86",
        VER(NVRAM_EF_SEARCH_WEB_BAIDU_UID_LID)
    },
#endif /* __MMI_SEARCH_WEB__ */

#ifdef __MMI_VUI_HOMESCREEN__
    {
        NVRAM_EF_VENUS_HS_WIDGET_MGR_LID,
        NVRAM_EF_VENUS_HS_WIDGET_MGR_TOTAL,
        NVRAM_EF_VENUS_HS_WIDGET_MGR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP87",
        VER(NVRAM_EF_VENUS_HS_WIDGET_MGR_LID)
    },
#endif /* __MMI_VUI_HOMESCREEN__ */

#ifdef __MMI_VUI_HOMESCREEN_MEMO__
    {
        NVRAM_EF_VENUS_HS_WIDGET_MEMO_CNTX_LID,
        NVRAM_EF_VENUS_HS_WIDGET_MEMO_CNTX_TOTAL,
        NVRAM_EF_VENUS_HS_WIDGET_MEMO_CNTX_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP88",
        VER(NVRAM_EF_VENUS_HS_WIDGET_MEMO_CNTX_LID)
    },
#endif /* __MMI_VUI_HOMESCREEN_MEMO__ */

#ifdef __MMI_VUI_MAINMENU__
    {
        NVRAM_EF_VENUS_MM_LID,
        NVRAM_EF_VENUS_MM_TOTAL,
        NVRAM_EF_VENUS_MM_SIZE,
        NVRAM_NORMAL(NVRAM_EF_VENUS_MM_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP89",
        VER(NVRAM_EF_VENUS_MM_LID)
    },
#endif /* __MMI_VUI_MAINMENU__*/

#ifdef __MMI_VUI_HOMESCREEN_PHOTO__
    {
        NVRAM_EF_VENUS_PHOTO_FILEPATH_LID,
        NVRAM_EF_VENUS_PHOTO_FILEPATH_TOTAL,
        NVRAM_EF_VENUS_PHOTO_FILEPATH_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP8A",
        VER(NVRAM_EF_VENUS_PHOTO_FILEPATH_LID)
    },
#endif /* __MMI_VUI_HOMESCREEN_PHOTO__*/

#ifdef __MMI_ZAKAT_CALCULATOR__
    {
        NVRAM_EF_ZAKAT_CALCULATOR_LID,
        NVRAM_EF_ZAKAT_CALCULATOR_TOTAL,
        NVRAM_EF_ZAKAT_CALCULATOR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP8B",
        VER(NVRAM_EF_ZAKAT_CALCULATOR_LID)
    },
#endif /* __MMI_ZAKAT_CALCULATOR__*/

#ifdef __TCPIP__
#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    {
		NVRAM_EF_CNMGR_CONNECT_DATA_LID,
		NVRAM_EF_CNMGR_CONNECT_DATA_LAST_TOTAL,
		NVRAM_EF_CNMGR_CONNECT_DATA_LAST_TOTAL_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"MP90",
		VER(NVRAM_EF_CNMGR_CONNECT_DATA_LID)
	},
#endif /* !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */
#endif /* __TCPIP__ */

#ifdef __MMI_EM_MISC_DCD__
    {
        NVRAM_EF_DCD_EM_PARAM_DATA_LID,
        NVRAM_EF_DCD_EM_PARAM_DATA_TOTAL,
        NVRAM_EF_DCD_EM_PARAM_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_DCD_EM_PARAM_DATA_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP91",
        VER(NVRAM_EF_DCD_EM_PARAM_DATA_LID)
    },
#endif /* __MMI_EM_MISC_DCD__ */

#ifdef __MMI_AZAAN_ALARM__
    {
        NVRAM_EF_AZAAN_ALARM_LID,
        NVRAM_AZAAN_ALARM_TOTAL,
        NVRAM_AZAAN_ALARM_SIZE,
        NVRAM_NORMAL(NVRAM_EF_AZAAN_ALARM_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_FACTORY_RESET,
        "MP94",
        VER(NVRAM_EF_AZAAN_ALARM_LID)
    },
#endif /* __MMI_AZAAN_ALARM__ */


#ifdef __MMI_IMAGE_VIEWER_EX__
    {
        NVRAM_EF_IVEX_SETTINGS_LID,
        NVRAM_EF_IVEX_SETTINGS_TOTAL,
        NVRAM_EF_IVEX_SETTINGS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP9D",
        VER(NVRAM_EF_IVEX_SETTINGS_LID)
    },
#endif/* __MMI_IMAGE_VIEWER_EX__ */

//#ifdef __MMI_SRV_TODOLIST__
#ifdef __MMI_CALENDAR_EVENT__
    {
        NVRAM_EF_TDL_EVENT_LID,
        NVRAM_EF_TDL_EVENT_TOTAL,
        NVRAM_EF_TDL_EVENT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MP9F",
        VER(NVRAM_EF_TDL_EVENT_LID)
    },
#endif

#ifdef __MMI_TODOLIST__
    {
        NVRAM_EF_TDL_TASK_LID,
        NVRAM_EF_TDL_TASK_TOTAL,
        NVRAM_EF_TDL_TASK_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MPA0",
        VER(NVRAM_EF_TDL_TASK_LID)
    },
#endif    
//#endif /* __MMI_SRV_TODOLIST__ */

#ifdef __DM_SCOMO_SUPPORT__
    {
        NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_LID,
        NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_TOTAL,
        NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPA1",
        VER(NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_LID)
    },
#endif /* __DM_SCOMO_SUPPORT__ */

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    {
        NVRAM_EF_SRV_SMS_PDU_LID,
        NVRAM_EF_SRV_SMS_PDU_TOTAL,
        NVRAM_EF_SRV_SMS_PDU_SIZE,
        NVRAM_NORMAL(NVRAM_EF_SRV_SMS_PDU_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MPA3",
        VER(NVRAM_EF_SRV_SMS_PDU_LID)
    },

    #ifdef __SRV_SMS_RECENT_EVENT__
    {
        NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_LID,
        NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_TOTAL,
        NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPA4",
        VER(NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_LID)
    },
    #endif /* __SRV_SMS_RECENT_EVENT__ */
#endif

#ifdef __OCSP_SUPPORT__
    {
        NVRAM_EF_CERTMAN_OCSP_URL_LID,
        NVRAM_EF_CERTMAN_OCSP_URL_TOTAL,
        NVRAM_EF_CERTMAN_OCSP_URL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPA5",
        VER(NVRAM_EF_CERTMAN_OCSP_URL_LID)
    },
#endif /*__OCSP_SUPPORT__*/


#if (defined(MRE_VERSION) && defined(__MRE_CORE_SANDBOX__))
    {
        NVRAM_EF_MRE_APP_BAN_LIST_EXT_LID,
        NVRAM_EF_MRE_APP_BAN_LIST_EXT_TOTAL,
        NVRAM_EF_MRE_APP_BAN_LIST_EXT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPA9",
        VER(NVRAM_EF_MRE_APP_BAN_LIST_EXT_LID)
    },

    {
        NVRAM_EF_MRE_SYM_ENTRY_LIST_EXT_LID,
        NVRAM_EF_MRE_SYM_ENTRY_LIST_EXT_TOTAL,
        NVRAM_EF_MRE_SYM_ENTRY_LIST_EXT_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_VER_SYM_ENTRY_EXT_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MPAB",
        VER(NVRAM_EF_MRE_SYM_ENTRY_LIST_EXT_LID)
    },
#endif

#if (defined(MRE_VERSION) && defined(__MRE_CORE_SAFETY__))
    {
        NVRAM_EF_MRE_PKEY_LIST_EXT_LID,
        NVRAM_EF_MRE_PKEY_LIST_EXT_TOTAL,
        NVRAM_EF_MRE_PKEY_LIST_EXT_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_VER_PKEY_EXT_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MPAA",
        VER(NVRAM_EF_MRE_PKEY_LIST_EXT_LID)
    },

    {
        NVRAM_EF_MRE_SYM_CONF_LIST_EXT_LID,
        NVRAM_EF_MRE_SYM_CONF_LIST_EXT_TOTAL,
        NVRAM_EF_MRE_SYM_CONF_LIST_EXT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPAC", 
        VER(NVRAM_EF_MRE_SYM_CONF_LIST_EXT_LID)
    },
#endif
    {
        NVRAM_EF_MRE_FIRST_RUNNING_LID,
        NVRAM_EF_MRE_FIRST_RUNNING_TOTAL,
        NVRAM_EF_MRE_FIRST_RUNNING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPB4",
        VER(NVRAM_EF_MRE_FIRST_RUNNING_LID)
    },
#ifdef __MRE_AM__
    {
        NVRAM_EF_AM_HS_SHORTCUT_LIST_LID,
        NVRAM_EF_AM_HS_SHORTCUT_LIST_TOTAL,
        NVRAM_EF_AM_HS_SHORTCUT_LIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPB5",
        VER(NVRAM_EF_AM_HS_SHORTCUT_LIST_LID)
    },
#endif

#ifdef __MMI_VUI_HOMESCREEN_CLOCK__
    {
        NVRAM_EF_VENUS_HS_WIDGET_CLOCK_CNTX_LID,
        NVRAM_EF_VENUS_HS_WIDGET_CLOCK_CNTX_TOTAL,
        NVRAM_EF_VENUS_HS_WIDGET_CLOCK_CNTX_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPB6",
        VER(NVRAM_EF_VENUS_HS_WIDGET_CLOCK_CNTX_LID)
    },
#endif /* __MMI_VUI_HOMESCREEN_CLOCK__ */

#ifdef __MMI_VUI_3D_CUBE_APP__
    {
        NVRAM_EF_CUBE_VIP_CONTS_LID,
        NVRAM_EF_CUBE_VIP_CONTS_TOTAL,
        NVRAM_EF_CUBE_VIP_CONTS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPB7",
        VER(NVRAM_EF_CUBE_VIP_CONTS_LID)
    },
#endif

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    {
		NVRAM_EF_OP11_HS32_HIST_LID,
        NVRAM_EF_OP11_HS32_HIST_TOTAL,
        NVRAM_EF_OP11_HS32_HIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_OP11_HS32_HIST_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPB8",
        VER(NVRAM_EF_OP11_HS32_HIST_LID)
    },
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

#ifdef __MMI_VUI_HOMESCREEN__
    {
        NVRAM_EF_VENUS_HS_SHORTCUT_MGR_LID,
        NVRAM_EF_VENUS_HS_SHORTCUT_MGR_TOTAL,
        NVRAM_EF_VENUS_HS_SHORTCUT_MGR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPB9",
        VER(NVRAM_EF_VENUS_HS_SHORTCUT_MGR_LID)
    },
#endif /* __MMI_VUI_HOMESCREEN__ */

#if (!defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) && defined(__SRV_SMS_SIM_CUST_DATA__))
    {
        NVRAM_EF_SRV_SMS_SIM_CUST_DATA_LID,
        NVRAM_EF_SRV_SMS_SIM_CUST_DATA_TOTAL,
        NVRAM_EF_SRV_SMS_SIM_CUST_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPBA",
        VER(NVRAM_EF_SRV_SMS_SIM_CUST_DATA_LID)
    },
#endif /* (!defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) && defined(__SRV_SMS_SIM_CUST_DATA__)) */

#ifdef __MMI_GADGET_SUPPORT__
    {
        NVRAM_EF_WGTMGR_DATA_LID,
        NVRAM_EF_WGTMGR_DATA_TOTAL,
        NVRAM_EF_WGTMGR_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPBB",
        VER(NVRAM_EF_WGTMGR_DATA_LID)
    },
#endif

#ifdef __MMI_SLIDESHOW__
    {
        NVRAM_EF_SLIDE_SHOW_PATH_LID,
        NVRAM_EF_SLIDE_SHOW_PATH_TOTAL,
        NVRAM_EF_SLIDE_SHOW_PATH_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPC1",
        VER(NVRAM_EF_SLIDE_SHOW_PATH_LID)
    },
#endif/*__MMI_SLIDESHOW__*/

#ifdef __MMI_SLIDESHOW__
    {
        NVRAM_EF_SLIDE_SHOW_AUDIO_LID,
        NVRAM_EF_SLIDE_SHOW_AUDIO_TOTAL,
        NVRAM_EF_SLIDE_SHOW_AUDIO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPC2",
        VER(NVRAM_EF_SLIDE_SHOW_AUDIO_LID)
    },
#endif/*__MMI_SLIDESHOW__*/

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
#ifdef __SRV_CBS_SUPPORT__

    {
        NVRAM_EF_SRV_CBS_PAGE_LID,
        NVRAM_EF_SRV_CBS_PAGE_TOTAL,
        NVRAM_EF_SRV_CBS_PAGE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_SRV_CBS_PAGE_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MPC3",
        VER(NVRAM_EF_SRV_CBS_PAGE_LID)
    },

    {
        NVRAM_EF_SRV_CBS_MSG_NODE_LID,
        NVRAM_EF_SRV_CBS_MSG_NODE_TOTAL,
        NVRAM_EF_SRV_CBS_MSG_NODE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_SRV_CBS_MSG_NODE_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MPC4",
        VER(NVRAM_EF_SRV_CBS_MSG_NODE_LID)
    },

    {
        NVRAM_EF_SRV_CBS_CHNL_NAME_LID,
        NVRAM_EF_SRV_CBS_CHNL_NAME_TOTAL,
        NVRAM_EF_SRV_CBS_CHNL_NAME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_SRV_CBS_CHNL_NAME_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MPC5",
        VER(NVRAM_EF_SRV_CBS_CHNL_NAME_LID)
    },
#endif
#if defined(__DA_SMART_SELECTION_SUPPORT__)
    {
        NVRAM_EF_DTCNT_SIM_ID_LID,
        NVRAM_MAX_DTCNT_SIM_ID_TOTAL,
        NVRAM_MAX_DTCNT_SIM_ID_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPC6",
        VER(NVRAM_EF_DTCNT_SIM_ID_LID)
    },
#endif
#endif /* !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    {
        NVRAM_EF_GROUPLIST_SIM2_LID,
        NVRAM_MAX_GROUP_NAME_TOTAL,
        NVRAM_MAX_GROUP_NAME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPC8",
        VER(NVRAM_EF_GROUPLIST_SIM2_LID)
    },
#endif

#ifdef OPERA_BROWSER
    {
        NVRAM_EF_OPERA_ADP_PROF_SETTING_LID,
        NVRAM_EF_OPERA_ADP_PROF_SETTING_TOTAL,
        NVRAM_EF_OPERA_ADP_PROF_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPC9",
        VER(NVRAM_EF_OPERA_ADP_PROF_SETTING_LID)
    },
#endif /* OPERA_BROWSER */

#ifdef __BT_HFG_PROFILE__
    {
        NVRAM_EF_BTHF_CONFIG_LID,
        NVRAM_EF_BTHF_CONFIG_TOTAL,
        NVRAM_EF_BTHF_CONFIG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPCA",
        VER(NVRAM_EF_BTHF_CONFIG_LID)
    },
#endif/* __BT_HFG_PROFILE__ */

#ifdef __MMI_FILE_MANAGER__
#ifdef __MMI_SCREEN_SAVER__
    {
        NVRAM_EF_SCREENSAVER_FILENAME_LID,
        NVRAM_EF_SCREENSAVER_FILENAME_TOTAL,
        NVRAM_EF_SCREENSAVER_FILENAME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPCB",
        VER(NVRAM_EF_SCREENSAVER_FILENAME_LID)
    },
#endif /* __MMI_SCREEN_SAVER__ */
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
    {
        NVRAM_EF_POWER_ON_OFF_DISP_FILENAME_LID,
        NVRAM_EF_POWER_ON_OFF_DISP_FILENAME_TOTAL,
        NVRAM_EF_POWER_ON_OFF_DISP_FILENAME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPCC",
        VER(NVRAM_EF_POWER_ON_OFF_DISP_FILENAME_LID)
    },
#endif
#endif /* __MMI_FILE_MANAGER__ */

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
#if !defined(__MMI_BASIC_UI_STYLE__) && !defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
    {
        NVRAM_EF_MMI_PROF_SETTING_LID,
        NVRAM_MMI_PROF_RECORD_TOTAL,
        NVRAM_MMI_PROF_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPCD",
        VER(NVRAM_EF_MMI_PROF_SETTING_LID)
    },
#endif
#endif /* !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */

#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
    {
        NVRAM_EF_SRV_SMS_STATUS_REPORT_LID,
        NVRAM_EF_SRV_SMS_STATUS_REPORT_TOTAL,
        NVRAM_EF_SRV_SMS_STATUS_REPORT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MPCF",
        VER(NVRAM_EF_SRV_SMS_STATUS_REPORT_LID)
    },
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */

#ifdef __MMI_VUI_SHELL_APP__
    {
        NVRAM_EF_VENUS_SHELL_PAGE_ORDER_LID,
        NVRAM_EF_VENUS_SHELL_PAGE_ORDER_TOTAL,
        NVRAM_EF_VENUS_SHELL_PAGE_ORDER_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPCG",
        VER(NVRAM_EF_VENUS_SHELL_PAGE_ORDER_LID)
    },
#endif /* __MMI_VUI_SHELL_APP__ */

#if defined(__CLOG_STORAGE_BY_MMI__)
  #ifdef __MMI_TELEPHONY_SUPPORT__
    {
        NVRAM_EF_CLOG_LOG_LID,
        NVRAM_EF_CLOG_LOG_TOTAL,
        NVRAM_EF_CLOG_LOG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MPD1",
        VER(NVRAM_EF_CLOG_LOG_LID)
    },

   {
        NVRAM_EF_CLOG_CALL_TIME_LID,
        NVRAM_EF_CLOG_CALL_TIME_TOTAL,
        NVRAM_EF_CLOG_CALL_TIME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MPD2",
        VER(NVRAM_EF_CLOG_CALL_TIME_LID)
    },
  #endif /* __MMI_TELEPHONY_SUPPORT__ */
#endif /* __CLOG_STORAGE_BY_MMI__ */

#ifdef __MMI_VUI_SHELL_SHORTCUTS__
    {
        NVRAM_EF_SHELL_SHORTCUTS_LID,
        NVRAM_EF_SHELL_SHORTCUTS_TOTAL,
        NVRAM_EF_SHELL_SHORTCUTS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPD3",
        VER(NVRAM_EF_SHELL_SHORTCUTS_LID)
    },
#endif /* __MMI_VUI_SHELL_SHORTCUTS__ */

#ifdef __MMI_VUI_SHELL_FAV_CONTACT__
    {
        NVRAM_EF_SHELL_FC_LID,
        NVRAM_EF_SHELL_FC_TOTAL,
        NVRAM_EF_SHELL_FC_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPD4",
        VER(NVRAM_EF_SHELL_FC_LID)
    },
#endif

#ifdef __MMI_VUI_3D_MAINMENU__
    {   // hongxi add
        NVRAM_EF_VENUS_3D_MM_LID,
        NVRAM_EF_VENUS_3D_MM_TOTAL,
        NVRAM_EF_VENUS_3D_MM_SIZE,
        NVRAM_NORMAL(NVRAM_EF_VENUS_3D_MM_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPDB",
        VER(NVRAM_EF_VENUS_3D_MM_LID)
    },
#endif

#ifdef __MMI_WLAN_FEATURES__
    {
        NVRAM_EF_CMCC_WIFI_SETTING_LID,
        NVRAM_MAX_CMCC_WIFI_SETTING_TOTAL,
        NVRAM_MAX_CMCC_WIFI_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPDO",
        VER(NVRAM_EF_CMCC_WIFI_SETTING_LID),
    },
#endif

#ifdef __BT_AUTO_DETECT_SUPPORT__
    {
        NVRAM_EF_BT_AUTO_DETECT_SETTING_LID,
        NVRAM_EF_BT_AUTO_DETECT_SETTING_TOTAL,
        NVRAM_EF_BT_AUTO_DETECT_SETTING_SIZE,
        NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_BT_AUTO_DETECT_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPC6",
        VER(NVRAM_EF_BT_AUTO_DETECT_SETTING_LID)
    },
#endif

    {
        NVRAM_EF_SRV_REMINDER_Q_LID,
        NVRAM_EF_SRV_REMINDER_Q_TOTAL,
        NVRAM_EF_SRV_REMINDER_Q_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_SW_VERNO_RESET,
        "MPDC",
        VER(NVRAM_EF_SRV_REMINDER_Q_LID)
    },


#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
    {
        NVRAM_EF_PHB_FIELD_LABEL_LID,
        NVRAM_EF_PHB_FIELD_LABEL_TOTAL,
        NVRAM_EF_PHB_FIELD_LABEL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ,
        "MPDF",
        VER(NVRAM_EF_PHB_FIELD_LABEL_LID)
    },
#endif


#ifdef __SRV_SMS_MULTI_ADDR__
    {
        NVRAM_EF_SRV_SMS_ADDR_LID,
        NVRAM_EF_SRV_SMS_ADDR_TOTAL,
        NVRAM_EF_SRV_SMS_ADDR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MPDH",
        VER(NVRAM_EF_SRV_SMS_ADDR_LID)
    },
#endif /* __SRV_SMS_MULTI_ADDR__ */

#ifdef __DM_LAWMO_SUPPORT__
    {
        NVRAM_EF_DM_APP_LAWMO_INFO_LID,
        NVRAM_EF_DM_APP_LAWMO_INFO_TOTAL,
        NVRAM_EF_DM_APP_LAWMO_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPDI",
        VER(NVRAM_EF_DM_APP_LAWMO_INFO_LID)
    },
#endif /* __DM_LAWMO_SUPPORT__ */

#if (MMI_MAX_SIM_NUM>=3)
    #if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    {
        NVRAM_EF_GROUPLIST_SIM3_LID,
        NVRAM_MAX_GROUP_NAME_TOTAL,
        NVRAM_MAX_GROUP_NAME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPDJ",
        VER(NVRAM_EF_GROUPLIST_SIM3_LID)
    },
    #endif
#endif

#if (MMI_MAX_SIM_NUM>=4)
    #if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    {
        NVRAM_EF_GROUPLIST_SIM4_LID,
        NVRAM_MAX_GROUP_NAME_TOTAL,
        NVRAM_MAX_GROUP_NAME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPDK",
        VER(NVRAM_EF_GROUPLIST_SIM4_LID)
    },
    #endif
#endif

#ifdef __MMI_139_PUSH_MAIL__
    {
        NVRAM_EF_PUSHMAIL_INFO_LID,
        NVRAM_EF_PUSHMAIL_INFO_TOTAL,
        NVRAM_EF_PUSHMAIL_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPDL",
        VER(NVRAM_EF_PUSHMAIL_INFO_LID)
    },
#endif

#ifdef __MMI_TETHERING__
    {
        NVRAM_EF_SRV_TETHERING_DTCNT_LID,
        NVRAM_EF_SRV_TETHERING_DTCNT_TOTAL,
        NVRAM_EF_SRV_TETHERING_DTCNT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPDM",
        VER(NVRAM_EF_SRV_TETHERING_DTCNT_LID)
    },
#ifdef __MMI_TETHERING_WIFI__
    {
        NVRAM_EF_SRV_TETHERING_WIFI_HS_SETTINGS_LID,
        NVRAM_EF_SRV_TETHERING_WIFI_HS_SETTINGS_TOTAL,
        NVRAM_EF_SRV_TETHERING_WIFI_HS_SETTINGS_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_SRV_TETHERING_WIFI_HS_SETTINGS_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPDN",
        VER(NVRAM_EF_SRV_TETHERING_WIFI_HS_SETTINGS_LID)
    },
#endif /* __MMI_TETHERING_WIFI__ */
#endif /* __MMI_TETHERING__ */

#ifdef __MMI_OP01_WIFI__
    {
        NVRAM_EF_CMCC_WIFI_BLACK_LIST_LID,
        NVRAM_MAX_CMCC_WIFI_BLACK_LIST_TOTAL,
        NVRAM_MAX_CMCC_WIFI_BLACK_LIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPDP",
        VER(NVRAM_EF_CMCC_WIFI_BLACK_LIST_LID)
    },
#endif

#ifdef __MMI_CM_BLACK_LIST_EXT__
    #ifdef __MMI_VIDEO_TELEPHONY__
    {
        NVRAM_EF_BLACK_LIST_VIDEO_LID,
        NVRAM_EF_BLACK_LIST_TOTAL,
        NVRAM_EF_BLACK_LIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPDQ",
        VER(NVRAM_EF_BLACK_LIST_LID)
    },
    #endif /* __MMI_VIDEO_TELEPHONY__ */
#endif/* __MMI_CM_BLACK_LIST_EXT__ */

#ifdef __MMI_CM_WHITE_LIST_EXT__
    #ifdef __MMI_VIDEO_TELEPHONY__
    {
        NVRAM_EF_WHITE_LIST_VIDEO_LID,
        NVRAM_EF_WHITE_LIST_TOTAL,
        NVRAM_EF_WHITE_LIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPDR",
        VER(NVRAM_EF_WHITE_LIST_LID)
    },
    #endif /* __MMI_VIDEO_TELEPHONY__ */
#endif/* __MMI_CM_WHITE_LIST_EXT__ */

#ifdef __MMI_PUSH_TURN_ON_OFF_SWITCH__
    {
        NVRAM_EF_PUSH_SWITCH_SETTING_LID,
        NVRAM_EF_PUSH_SWITCH_SETTING_TOTAL,
        NVRAM_EF_PUSH_SWITCH_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_PUSH_SWITCH_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPDS",
        VER(NVRAM_EF_PUSH_SWITCH_SETTING_LID)
    },
#endif /* __MMI_PUSH_TURN_ON_OFF_SWITCH__ */

#ifdef __MMI_OP01_WIFI__
    {
        NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_LID,
        NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_TOTAL,
        NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPE1",
        VER(NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_LID)
    },
#endif

#if defined(__MMI_VIDEO_TELEPHONY__) && defined(__OP01__)
    {
        NVRAM_EF_VT_SETTING_REMOTE_PIC_LID,
        NVRAM_EF_VT_SETTING_TOTAL,
        NVRAM_EF_VT_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPE2",
        VER(NVRAM_EF_VT_SETTING_REMOTE_PIC_LID)
    },
#endif /* defined(__MMI_VIDEO_TELEPHONY__) && defined(__OP01__) */

#if defined(__MMI_VUI_SHELL_OP01_HOMESCREEN__)||defined(__MMI_VUI_LAUNCHER_KEY__)
    {
        NVRAM_EF_OP01_HS_SETTING_LID,
        NVRAM_EF_OP01_HS_SETTING_TOTAL,
        NVRAM_EF_OP01_HS_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPE3",
        VER(NVRAM_EF_OP01_HS_SETTING_LID)
    },
#endif /* defined(__MMI_VUI_SHELL_OP01_HOMESCREEN__)||defined(__MMI_VUI_LAUNCHER_KEY__) */

#ifdef SYNCML_DM_SUPPORT
{
    NVRAM_EF_DM_SRV_ACC_LID,
    NVRAM_EF_DM_SRV_ACC_TOTAL,
    NVRAM_EF_DM_SRV_ACC_SIZE,
    NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
    NVRAM_CATEGORY_USER,
    NVRAM_ATTR_AVERAGE,
    "MPE4",
    VER(NVRAM_EF_DM_SRV_ACC_LID)
},
#endif /* SYNCML_DM_SUPPORT */

#ifdef __OP01_FWPBW__
    {
        NVRAM_EF_DIALER_DIRECT_DIAL_LID,
        NVRAM_EF_PHB_SPEEDDIAL_TOTAL,
        NVRAM_EF_PHB_SPEEDDIAL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPE5",
        VER(NVRAM_EF_DIALER_DIRECT_DIAL_LID)
    },
#endif
#ifdef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
    {
        NVRAM_EF_MMI_PROF_NEW_NAME_LID,
        NVRAM_MMI_PROF_NEW_RECORD_TOTAL,
        NVRAM_MMI_PROF_NEW_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPE6",
        VER(NVRAM_EF_MMI_PROF_NEW_NAME_LID),
    },

    {
        NVRAM_EF_MMI_PROF_NEW_FLAG_LID,
        NVRAM_MMI_PROF_FLAG_RECORD_TOTAL,
        NVRAM_MMI_PROF_FLAG_RECORD_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPE7",
        VER(NVRAM_EF_MMI_PROF_NEW_FLAG_LID),
    },
#endif
#if (defined(MRE_VERSION) && defined(__MRE_CORE_SAFETY__))
    {
    	NVRAM_EF_MRE_PKEY_LIST_MTK_LID,
    	NVRAM_EF_MRE_PKEY_LIST_MTK_TOTAL,
    	NVRAM_EF_MRE_PKEY_LIST_MTK_SIZE,
    	NVRAM_NORMAL_NOT_GEN(NVRAM_MER_PKEY_MTK_DEFAULT),
      NVRAM_CATEGORY_USER,
      NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MPE8",
        VER(NVRAM_EF_MRE_PKEY_LIST_MTK_LID)
    },
#endif

#ifdef __MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__
    {
        NVRAM_EF_CNMGR_SCRI_CHECK_TIME_LID,
		NVRAM_EF_CNMGR_SCRI_CHECK_TIME_TOTAL,
		NVRAM_EF_CNMGR_SCRI_CHECK_TIME_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"MPE9",
		VER(NVRAM_EF_CNMGR_SCRI_CHECK_TIME_LID)
    },
#endif /* __MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__ */

#ifdef __MMI_VUI_LAUNCHER__
    {
        NVRAM_EF_VAPP_DRAWER_ORDER_DATA_LID,
        NVRAM_EF_VAPP_DRAWER_ORDER_DATA_TOTAL,
        NVRAM_EF_VAPP_DRAWER_ORDER_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_VAPP_DRAWER_ORDER_DATA_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPEA",
        VER(NVRAM_EF_VAPP_DRAWER_ORDER_DATA_LID)
    },
    {
        NVRAM_EF_VENUS_LAUNCHER_DESKTOP_LID,
        NVRAM_EF_VENUS_LAUNCHER_DESKTOP_TOTAL,
        NVRAM_EF_VENUS_LAUNCHER_DESKTOP_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPEB",
        VER(NVRAM_EF_VENUS_LAUNCHER_DESKTOP_LID)
    },
#endif
#ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
    {
        NVRAM_EF_DMSR_SIM_IMSI_LID,
        NVRAM_EF_DM_SR_IMSI_TOTAL,
        NVRAM_EF_DM_SR_IMSI_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
    	NVRAM_ATTR_AVERAGE,
        "MPEC",
        VER(NVRAM_EF_DMSR_SIM_IMSI_LID)
    },
#endif/*__MMI_DM_SELF_REGISTER_SUPPORT__*/
#ifdef __MMI_VUI_LAUNCHER_KEY__
    {
        NVRAM_EF_VAPP_KMM_ORDER_DATA_LID,
        NVRAM_EF_VAPP_KMM_ORDER_DATA_TOTAL,
        NVRAM_EF_VAPP_KMM_ORDER_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_VAPP_KMM_ORDER_DATA_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPEE",
        VER(NVRAM_EF_VAPP_KMM_ORDER_DATA_LID)
    },
#endif /* __MMI_VUI_LAUNCHER__ */

#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
    {
        NVRAM_EF_QUICKTEST_LID,
        NVRAM_EF_QUICKTEST_TOTAL,
        NVRAM_EF_QUICKTEST_SIZE ,
        NVRAM_NORMAL(NVRAM_EF_QUICKTEST_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPG0",
        VER(NVRAM_EF_QUICKTEST_LID)
    },
#endif  /* !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */

#ifdef __NFC_SUPPORT__
	{
		NVRAM_EF_NFC_STATUS_LID,
		NVRAM_EF_NFC_STATUS_TOTAL,
		NVRAM_EF_NFC_STATUS_SIZE,
		NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
		"MPED",
		VER(NVRAM_EF_NFC_STATUS_LID)
		
	},
#endif /* __NFC_SUPPORT__ */

#ifdef __SOCIAL_NETWORK_SUPPORT__
    {
        NVRAM_EF_SRV_SNS_ACCOUNT_LID,
        NVRAM_EF_SRV_SNS_ACCOUNT_TOTAL,
        NVRAM_EF_SRV_SNS_ACCOUNT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MPEO",
        VER(NVRAM_EF_SRV_SNS_ACCOUNT_LID)
    },
#endif /* __SOCIAL_NETWORK_SUPPORT__ */

#ifdef __MMI_SSO__
    {
        NVRAM_EF_SRV_SSO_ACCOUNT_LID,
        NVRAM_EF_SRV_SSO_ACCOUNT_TOTAL,
        NVRAM_EF_SRV_SSO_ACCOUNT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MPSO",
        VER(NVRAM_EF_SRV_SSO_ACCOUNT_LID)
    },
#endif /* __MMI_SSO__ */

#ifdef __MMI_VUI_LAUNCHER_KEY__
	{
		NVRAM_EF_PHNSET_WIDGET_MGR_SYS_LIST_LID,
		NVRAM_EF_PHNSET_WIDGET_MGR_SYS_LIST_TOTAL,
		NVRAM_EF_PHNSET_WIDGET_MGR_SYS_LIST_SIZE,
		NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
		"MPEP",
		VER(NVRAM_EF_PHNSET_WIDGET_MGR_SYS_LIST_LID)	
	},
#endif

#ifdef __MMI_VUI_LAUNCHER_KEY__
		{
		NVRAM_EF_PHNSET_SHCUT_APP_LIST_LID,
		NVRAM_EF_PHNSET_SHCUT_APP_LIST_TOTAL,
		NVRAM_EF_PHNSET_SHCUT_APP_LIST_SIZE,
		NVRAM_NORMAL(NVRAM_EF_PHNSET_SHCUT_APP_LIST_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
		"MPEF",
		VER(NVRAM_EF_PHNSET_SHCUT_APP_LIST_LID)	
	},
#endif

#ifdef MOTION_SENSOR_SUPPORT
	{		
		NVRAM_EF_MOTION_SENSOR_SWITCH_LID,
		NVRAM_EF_MOTION_SENSOR_SWITCH_TOTAL,
		NVRAM_EF_MOTION_SENSOR_SWITCH_SIZE,
		NVRAM_NORMAL(NVRAM_EF_MOTION_SENSOR_SWITCH_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE| NVRAM_ATTR_FACTORY_RESET,
		"MPEG",
		VER(NVRAM_EF_MOTION_SENSOR_SWITCH_LID)
	},
#endif

#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
	{
		NVRAM_EF_NETSET_SIM_NAME_LID,
		NVRAM_EF_NETSET_SIM_NAME_TOTAL,
		NVRAM_EF_NETSET_SIM_NAME_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
		"MPEH",
		VER(NVRAM_EF_NETSET_SIM_NAME_LID)
	},  
#endif /* __MMI_DYNAMIC_SIM_DYNAMIC_UI__ */

#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
    {
		NVRAM_EF_SCREEN_LOCK_KEY_IMG_SETTING_LID,
		NVRAM_EF_SCREEN_LOCK_KEY_IMG_SETTING_TOTAL,
		NVRAM_EF_SCREEN_LOCK_KEY_IMG_SETTING_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"MPEI",
		VER(NVRAM_EF_SCREEN_LOCK_KEY_IMG_SETTING_LID)	
	},
#endif
#ifdef __MMI_NSS_SUPPORT__
    {
        NVRAM_EF_SRV_NSS_PROFILE_LID,
        NVRAM_EF_SRV_NSS_PROFILE_TOTAL,
        NVRAM_EF_SRV_NSS_PROFILE_SIZE,
        NVRAM_CUSTPACK(NVRAM_EF_SRV_NSS_PROFILE_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        "MPNS",
        VER(NVRAM_EF_SRV_NSS_PROFILE_LID)
    },
#endif    

#ifdef __MMI_MRE_MSPACE__
    {
            NVRAM_EF_SRV_MSPACE_LID,
            NVRAM_EF_SRV_MSPACE_TOTAL,
            NVRAM_EF_SRV_MSPACE_SIZE,
            NVRAM_NORMAL_NOT_GEN(NVRAM_MSPACE_URL),
            NVRAM_CATEGORY_USER,
            NVRAM_ATTR_AVERAGE,
            "MPNT",
            VER(NVRAM_EF_SRV_MSPACE_LID)   
    },
#endif

/* ADD-S 20120417 FOR CMMBCAS2GPP*/
#ifdef CMMB_CAS_2GPP_V10
    {
        NVRAM_EF_CMMB_CAS_2GPP_LID,
        NVRAM_EF_CMMB_CAS_2GPP_TOTAL,
        NVRAM_EF_CMMB_CAS_2GPP_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_CONFIDENTIAL,
        "MPNU",
        VER(NVRAM_EF_CMMB_CAS_2GPP_LID)
    },
#endif /* __MMI_MOBILE_TV_PLAYER__ */
/* ADD-E 20120417 FOR CMMBCAS2GPP*/
#ifdef __CLOUD_SUPPORT__
#ifdef __SMS_CLOUD_SUPPORT__
    {
        NVRAM_EF_SMS_USED_NUM_LID,
        NVRAM_MAX_SMS_USED_NUM_TOTAL,
        NVRAM_MAX_SMS_USED_NUM_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP71",
        VER(NVRAM_EF_SMS_USED_NUM_LID)
    },
    {
        NVRAM_EF_SMS_UID_COUNT_LID,
        NVRAM_MAX_SMS_UID_COUNT_TOTAL,
        NVRAM_MAX_SMS_UID_COUNT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP73",
        VER(NVRAM_EF_SMS_UID_COUNT_LID)
    }, 
    {
        NVRAM_EF_CLOUD_SMS_ITEM_LID,
        NVRAM_MAX_CLOUD_SMS_ITEM_TOTAL,
        NVRAM_MAX_CLOUD_SMS_ITEM_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP74",
        VER(NVRAM_EF_CLOUD_SMS_ITEM_LID)
    },    
#endif
#ifdef __VCARD_CLOUD_SUPPORT__
    {
        NVRAM_EF_VCRD_USED_NUM_LID,
        NVRAM_MAX_VCRD_USED_NUM_TOTAL,
        NVRAM_MAX_VCRD_USED_NUM_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP75",
        VER(NVRAM_EF_VCRD_USED_NUM_LID)
    },
    {
        NVRAM_EF_VCRD_UID_COUNT_LID,
        NVRAM_MAX_VCRD_UID_COUNT_TOTAL,
        NVRAM_MAX_VCRD_UID_COUNT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP77",
        VER(NVRAM_EF_VCRD_UID_COUNT_LID)
    },    
    {
        NVRAM_EF_CLOUD_VCRD_ITEM_LID,
        NVRAM_MAX_CLOUD_VCRD_ITEM_TOTAL,
        NVRAM_MAX_CLOUD_VCRD_ITEM_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP78",
        VER(NVRAM_EF_CLOUD_VCRD_ITEM_LID)
    },
    {
        NVRAM_EF_VCRD_UID_LIST_URL_LID,
        NVRAM_MAX_VCRD_UID_LIST_URL_TOTAL,
        NVRAM_MAX_VCRD_UID_LIST_URL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP79",
        VER(NVRAM_EF_VCRD_UID_LIST_URL_LID)
    },    
    {
        NVRAM_EF_VCRD_IS_CHANGE_LID,
        NVRAM_MAX_VCRD_IS_CHANGE_TOTAL,
        NVRAM_MAX_VCRD_IS_CHANGE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP7A",
        VER(NVRAM_EF_VCRD_IS_CHANGE_LID)            
    },
#endif
#endif

#if (defined(MRE_VERSION) && defined(__MRE_CORE_SAFETY__))
    {
    	NVRAM_EF_MRE_PKEY_EX_LID,
    	NVRAM_EF_MRE_PKEY_EX_TOTAL,
    	NVRAM_EF_MRE_PKEY_EX_SIZE,
    	NVRAM_NORMAL_NOT_GEN(NVRAM_MER_PKEY_1024BIT_DEFAULT),
        NVRAM_CATEGORY_USER,
    	NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MP7B",
        VER(NVRAM_EF_MRE_PKEY_EX_LID)
    },
#endif

#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
    {
    	NVRAM_EF_SYS_LANGUAGE_SSC_LID,
    	NVRAM_EF_SYS_LANGUAGE_SSC_TOTAL,
    	NVRAM_EF_SYS_LANGUAGE_SSC_SIZE,
    	NVRAM_NORMAL_NOT_GEN(NVRAM_EF_SYS_LANGUAGE_SSC_DEFAULT),
        NVRAM_CATEGORY_USER,
    	NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP7C",
        VER(NVRAM_EF_SYS_LANGUAGE_SSC_LID)
    },
#endif

#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__
    {
		NVRAM_EF_DLT_APPICON_LID,
		NVRAM_EF_DLT_APPICON_TOTAL,
		NVRAM_EF_DLT_APPICON_SIZE,
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"MP7D",
		VER(NVRAM_EF_DLT_APPICON_LID)
	},
#endif	

#ifdef __MMI_APPLIST_BARREL_SUPPORT__
    {
        NVRAM_EF_APPLIST_BARREL_EFFECT_LID,
        NVRAM_EF_APPLIST_BARREL_EFFECT_TOTAL,
        NVRAM_EF_APPLIST_BARREL_EFFECT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP7E",
        VER(NVRAM_EF_APPLIST_BARREL_EFFECT_LID)
    },
#endif

#if defined(__MMI_BT_DIALER_SUPPORT__) && !defined(__MMI_BT_BTBOX_NOLCD__)
    {
        NVRAM_BYTE_BT_DIALER_CONNSTR,
        NVRAM_BYTE_BT_DIALER_CONNSTR_TOTAL,
        NVRAM_BYTE_BT_DIALER_CONNSTR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_SW_VERNO_RESET,
        "MP80",
        VER(NVRAM_BYTE_BT_DIALER_CONNSTR)
    },
    {
        NVRAM_BYTE_BT_DIALER_AUTO_CONN,
        NVRAM_BYTE_BT_DIALER_AUTO_CONN_TOTAL,
        NVRAM_BYTE_BT_DIALER_AUTO_CONN_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_SW_VERNO_RESET,
        "MP81",
        VER(NVRAM_BYTE_BT_DIALER_AUTO_CONN)
    },
#endif
    
#ifdef __MMI_AUDPLY_WALK_PLAY__
    {
        NVRAM_EF_AUDPLY_WALK_LID,
        NVRAM_EF_AUDPLY_WALK_TOTAL,
        NVRAM_EF_AUDPLY_WALK_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP82",
        VER(NVRAM_EF_AUDPLY_WALK_LID)
    },
#endif  /* __MMI_AUDPLY_WALK_PLAY__ */

#if defined(__IOT__) 
    {
        NVRAM_EF_WIFIAP_MODE_CONFIG_LID,
        NVRAM_EF_WIFIAP_MODE_CONFIG_TOTAL,
        NVRAM_EF_WIFIAP_MODE_CONFIG_SIZE,
        NVRAM_NORMAL(COMMON_NVRAM_EF_WIFIAP_MODE_CONFIG_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP83",
        VER(NVRAM_EF_WIFIAP_MODE_CONFIG_LID)
    },
#endif /* defined(__IOT__) */

#if defined(__WIFI_SUPPORT__) && defined(__IOT__)
    {
        NVRAM_EF_WLAN_SCAN_SETTING_LID,
        NVRAM_MAX_WLAN_SCAN_SETTING_TOTAL,
        NVRAM_MAX_WLAN_SCAN_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_WLAN_SCAN_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MP84",
        VER(NVRAM_EF_WLAN_SCAN_SETTING_LID)
    },
#endif
#if defined(__CERTMAN_SUPPORT__)  
    {
        NVRAM_EF_CERTMAN_CERT_LID,
        NVRAM_EF_FM_CERTMAN_TOTAL,
        NVRAM_EF_FM_CERTMAN_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT6C",
        VER(NVRAM_EF_CERTMAN_CERT_LID)
    },
#endif/*__CERTMAN_SUPPORT__*/
	//huking
#if defined(__MMI_FRM_INPUT_EVT__)	
	//led	
	{
        NVRAM_EF_LED_INFO_LID,
        NVRAM_EF_LED_INFO_TOTAL,
        NVRAM_EF_LED_INFO_SIZE,
        NVRAM_NORMAL(nv_input_event_notify_led_info_tbl),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET| NVRAM_ATTR_MULTI_DEFAULT,
        "MP86",
        VER(NVRAM_EF_LED_INFO_LID)
    },
    //vib
	{
        NVRAM_EF_VIB_INFO_LID,
        NVRAM_EF_VIB_INFO_TOTAL,
        NVRAM_EF_VIB_INFO_SIZE,
        NVRAM_NORMAL(nv_input_event_notify_vib_info_tbl),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET| NVRAM_ATTR_MULTI_DEFAULT,
        "MP87",
        VER(NVRAM_EF_VIB_INFO_LID)
    },
    //aud
	{
        NVRAM_EF_AUD_INFO_LID,
        NVRAM_EF_AUD_INFO_TOTAL,
        NVRAM_EF_AUD_INFO_SIZE,
        NVRAM_NORMAL(nv_input_event_notify_aud_info_tbl),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET| NVRAM_ATTR_MULTI_DEFAULT,
        "MP88",
        VER(NVRAM_EF_AUD_INFO_LID)
    },    
	//notify
	{
        NVRAM_EF_NOTIFY_INFO_LID,
        NVRAM_EF_NOTIFY_INFO_TOTAL,
        NVRAM_EF_NOTIFY_INFO_SIZE,
        NVRAM_NORMAL(nv_input_event_notify_tbl),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET | NVRAM_ATTR_MULTI_DEFAULT,
        "MP89",
        VER(NVRAM_EF_NOTIFY_INFO_LID)
    },
    //input event
	{
        NVRAM_EF_INPUT_EVENT_INFO_LID,
        NVRAM_EF_INPUT_EVENT_INFO_TOTAL,
        NVRAM_EF_INPUT_EVENT_INFO_SIZE,
        NVRAM_NORMAL(nv_input_event_evt_info_tbl),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET| NVRAM_ATTR_MULTI_DEFAULT,
        "MP8A",
        VER(NVRAM_EF_INPUT_EVENT_INFO_LID)
    },
	//local		
	{
        NVRAM_EF_LOCAL_APP_INFO_LID,
        NVRAM_EF_LOCAL_APP_INFO_TOTAL,
        NVRAM_EF_LOCAL_APP_INFO_SIZE,
        NVRAM_NORMAL(nv_input_event_local_app_info_tbl),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET| NVRAM_ATTR_MULTI_DEFAULT,
        "MP8B",
        VER(NVRAM_EF_LOCAL_APP_INFO_LID)
    },
#endif/*#if defined(__MMI_FRM_INPUT_EVT__)*/    

#ifndef __MMI_TELEPHONY_SUPPORT__
    {
        NVRAM_EF_PHONE_LOCK_LID,
        NVRAM_EF_PHONE_LOCK_TOTAL,
        NVRAM_EF_PHONE_LOCK_SIZE,
        NVRAM_NORMAL(&NVRAM_EF_PHONE_LOCK_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
        "MP8C",
        VER(NVRAM_EF_PHONE_LOCK_LID)
    },
#endif  /* __MMI_TELEPHONY_SUPPORT__ */
};

nvram_ltable_tbl_struct nvram_ltable_comm_app = 
    {logical_data_item_table_common_app,     sizeof(logical_data_item_table_common_app)/sizeof(nvram_ltable_entry_struct)};

#endif /*!NVRAM_NOT_PRESENT*/


