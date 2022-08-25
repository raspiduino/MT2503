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

/*******************************************************************************
 * Filename:
 * ---------
 * nvram_common_defs.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for MTK to config/customize NVRAM settings.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
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
 *
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef NVRAM_COMMON_DEFS_H
#define NVRAM_COMMON_DEFS_H

#ifndef NVRAM_NOT_PRESENT

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
#include "MMI_features.h"
#include "nvram_data_items.h"

#ifdef WAP_SUPPORT
#include "custom_wap_config.h"
#endif /* WAP_SUPPORT */


#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */

#ifdef __MMI_ECOMPASS__
#include "ec_nvram_header.h"
#endif

#ifdef __MMI_VUI_SHELL_SHORTCUTS__
#include "custom_shell_shortcuts_cfg.h"
#endif /* __MMI_VUI_SHELL_SHORTCUTS__ */

#ifdef __CLOG_STORAGE_BY_MMI__
#include "custom_calllog.h"
#endif

#if defined(__TCPIP_OVER_CSD__) || defined(__MMI_GPRS_FEATURES__)
#include "custom_data_account.h"   /* MAX_CSD_SIM_PROV_NUM */
#endif

#include "custom_voip_config.h"

#include "custom_phb_config.h"                  /* MMI_PHB_NUMBER_PLUS_LENGTH */
#include "custom_mmi_default_value.h"           /* MAX_SYNCML_SV_PROFILES */
#include "custom_btcm_config.h"
/**
 * Customized logical data item ID's.
 *
 */
#define NVRAM_LID_COMMAPP_BEGIN     NVRAM_EF_LAST_LID_CORE

/**
 * Note:
 * This enumeration must begin from NVRAM_LID_CUST_BEGIN!!!
 * Besides, there must be at least one user-defined logical data item.
 */
    typedef enum
    {
        /* Belows are ID's of user defined logical data items. Could be assigned to any category  */
        NVRAM_EF_AUTOTEST_LID  = NVRAM_LID_COMMAPP_BEGIN,
        NVRAM_EF_CACHE_BYTE_LID,
        NVRAM_EF_CACHE_SHORT_LID,
        NVRAM_EF_CACHE_DOUBLE_LID,
    #ifdef __PHB_STORAGE_BY_MMI__
    
    #ifdef __MMI_TELEPHONY_SUPPORT__
        NVRAM_EF_PHB_LID,
    #endif
    #endif        
        NVRAM_EF_PHB_SOS_LID,
        NVRAM_EF_PHB_SPEEDDIAL_LID,
        NVRAM_EF_PHB_RES_LID,
        
    #ifdef __MMI_TELEPHONY_SUPPORT__
        NVRAM_EF_PHB_FIELDS_LID,            /* __MMI_PHB_OPTIONAL_FIELD__ */
    #endif
    
        NVRAM_EF_PHB_FIELDS_MASK_LID,
        NVRAM_EF_PHB_GROUP_INFO_LID,
        NVRAM_EF_PHB_MY_NUMBER_LID,
        NVRAM_EF_PHB_EMAIL_SORT_LID,        /* __MMI_PHB_EMAIL_SORT__ */
        NVRAM_EF_PHB_GROUP_FIELD_LID,
        NVRAM_EF_PHB_BIRTHDAY_LID,          /* __MMI_PHB_BIRTHDAY_FIELD__ */
        NVRAM_EF_PHB_INFO_LID,              /* __MMI_PHB_INFO_FIELD__ */
        NVRAM_EF_PHB_IMPS_LID,              /* __MMI_PHB_IMPS_FIELD__ */
        NVRAM_EF_PHB_POC_LID,               /* __MMI_PHB_POC_FIELD__ */
        NVRAM_EF_PHB_VOIP_LID,              /* __MMI_VOIP__ */
        NVRAM_EF_SMS_LID,                   /* __MMI_MESSAGES_PREDEFINED_TEMPLATE__ */
        NVRAM_EF_EMS_MY_PICTURE_NAME_LID,   /* __DOWNLOAD__ */
        NVRAM_EF_EMS_MY_ANIMATION_NAME_LID,
        NVRAM_EF_EMS_MY_MELODY_NAME_LID,    /* __MMI_IMELODY_SUPPORT__ && __DOWNLOAD__ */
        NVRAM_EF_CAMERA_SETTING_LID,
        NVRAM_EF_VIDEO_SETTING_LID,         /* __MMI_VIDEO_RECORDER__ */
        NVRAM_EF_IP_NUMBER_LID,             /* __IP_NUMBER__ */
     #ifdef __no_remove__   
        NVRAM_EF_ALM_QUEUE_LID,
     #endif   
        NVRAM_EF_ALM_SPOF_DATA_LID,
        NVRAM_EF_ALM_ALARM_DATA_LID,
        NVRAM_EF_TODO_LIST_LID,             /* __MMI_TODOLIST__ */
        NVRAM_EF_GROUPLIST_LID,
        NVRAM_EF_GROUPLIST_SIM2_LID,
        NVRAM_EF_WALLPAPER_FILENAME_LID,
        NVRAM_EF_SHORTCUTS_LID,
        NVRAM_EF_MMI_PROF_SETTING_LID,
        NVRAM_EF_STOPWATCH_LID,             /* __MMI_STOPWATCH__ */
        NVRAM_PICTURE_EDITOR_LID,           /* __MMI_PICTURE_EDITOR_SUPPORT__ */
        NVRAM_EF_FM_RADIO_LID,              /* __MMI_FM_RADIO__ */
        NVRAM_EF_FMSR_SETTING_LID,          /* __MMI_FM_RADIO_SCHEDULE_REC__ */
        NVRAM_EF_VRSD_TAG_LID,              /* __MMI_VRSD__ */
        NVRAM_EF_VRSI_TAG_LID,              /* __MMI_VRSI__ */
#if NVRAM_EF_FMGR_FILEPATH_COUNT
        NVRAM_EF_FMGR_FILEPATH_POOL_HEAD_LID,
        NVRAM_EF_FMGR_FILEPATH_POOL_TAIL_LID,
 #endif       
#ifndef __BCM_SUPPORT__
        NVRAM_EF_BT_INFO_LID,               /* __BT_SUPPORT__ */
        NVRAM_EF_BT_DEV_LIST_LID,           /* __BT_SUPPORT__ */
        NVRAM_EF_BT_DEV_LIST_INDEX_LID,           /* __BT_SUPPORT__ */
        NVRAM_EF_BT_SYS_INFO_LID,           /* __BT_SUPPORT__ */
#endif
        NVRAM_EF_BLACK_LIST_LID,            /* __MMI_CM_BLACK_LIST__ */
        NVRAM_EF_IMPS_LID,                  /* __MMI_IMPS__ */
        NVRAM_EF_AUDIO_EQUALIZER_LID,       /* __MMI_AUDIO_EQUALIZER__ */
        NVRAM_EF_THEMES_VALUES,             /* __MMI_THEMES_APPLICATION__ */
        NVRAM_EF_THEME_MANAGER_LID,         /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
        NVRAM_EF_THEME_DOWNLOAD_LIST_LID,   /* __MMI_DOWNLOADABLE_THEMES_SUPPORT__ */
        NVRAM_EF_MOTION_DICE_LID,           /* __MMI_MOTION_APP__ */
        NVRAM_EF_MOTION_DJ_LID,             /* __MMI_MOTION_APP__ */
        NVRAM_EF_BGSND_SETTING_LID,         /* __MMI_BG_SOUND_EFFECT__ */
        NVRAM_EF_BGSND_FILEPATH_LID,        /* __MMI_BG_SOUND_EFFECT__ */
#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
        NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_LID,
        NVRAM_EF_BRW_ADDRESS_HISTORY_URL_LID,
#endif /* #ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__ */
#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
        NVRAM_EF_BRW_SEARCH_ITEM_LID,
#endif
    #ifdef __MMI_Q05A_LAUNCH_SCREEN__
        NVRAM_EF_BRW_SHORTCUTS_LIST_LID,
    #endif
        NVRAM_EF_WAP_PROFILE_CONTENT_LID,
        NVRAM_EF_MMS_PROFILE_CONTENT_LID,
        NVRAM_EF_WAP_PROFILE_NAMES_LID,
        NVRAM_EF_MMS_PROFILE_NAMES_LID,

	/* __MMI_EBOOK_READER__ */
        NVRAM_EF_EBOOK_SETTINGS_LID,

        NVRAM_EF_BARCODEREADER_SETTING_LID,


        /* Audio Player Bluetooth Settings */
        NVRAM_EF_A2DP_SETTINGS_LID,
        NVRAM_EF_VOIP_PROF_LID,             /* __MMI_VOIP__*/
        NVRAM_EF_VOIP_SETTING_LID,          /* __MMI_VOIP__*/
        NVRAM_EF_WLAN_SETTING_LID,
        NVRAM_EF_WLAN_PROFILE_LID,
#ifdef __CLOUD_SUPPORT__
#ifdef __SMS_CLOUD_SUPPORT__
        NVRAM_EF_SMS_USED_NUM_LID,
        NVRAM_EF_SMS_UID_COUNT_LID,
        NVRAM_EF_CLOUD_SMS_ITEM_LID,
#endif
#ifdef __VCARD_CLOUD_SUPPORT__
        NVRAM_EF_VCRD_USED_NUM_LID,
        NVRAM_EF_VCRD_UID_COUNT_LID,
        NVRAM_EF_CLOUD_VCRD_ITEM_LID,
        NVRAM_EF_VCRD_UID_LIST_URL_LID,
        NVRAM_EF_VCRD_IS_CHANGE_LID,
#endif
#endif
        NVRAM_EF_EM_NW_EVENT_RINGS_LID,
        /*NITZ PLMN */
        NVRAM_EF_NITZ_NW_NAME_LID,

        NVRAM_EF_DM_FWU_TFTP_SETTING_LID,
        NVRAM_EF_DM_FWU_HTTP_SETTING_LID,


        NVRAM_EF_AVATAR_SETTING_LID,
        NVRAM_EF_CSB_SETTINGS_LID,

        /* Generic Browser */
        NVRAM_EF_BRW_LAST_WEB_ADDR_LID,
#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
        NVRAM_EF_BRW_USER_DEFINED_HOMEPAGE_LID,
#endif
        NVRAM_EF_VIDEO_PREDEFINED_URL_LID,  /* __MMI_VIDEO_STREAM__ */
        NVRAM_EF_VIDEO_HISTORY_URL_LID,     /* __MMI_VIDEO_STREAM__ */
        NVRAM_EF_DM_SR_NUMBER_LID,	    /* __MMI_DM_SELF_REGISTER_SUPPORT__ */
        NVRAM_EF_CUSTSER_SETTING_LID,       /* __MMI_CUSTOMER_SERVICE__*/
        NVRAM_EF_UMMS_COMPOSE_SETTINGS_LID,
        NVRAM_EF_UMMS_SENDING_SETTINGS_LID,
#ifdef OBIGO_Q03C_MMS_V01
        NVRAM_EF_MMSV01_COMPOSE_SETTINGS_LID,
        NVRAM_EF_MMSV01_SENDING_SETTINGS_LID,
#endif
        NVRAM_EF_EMAIL_TEMPLATE_LID,        /* __MMI_EMAIL_TEMPLATE__ */
        NVRAM_EF_LANGLN_LK_SETTING_LID,
        NVRAM_EF_LANGLN_PRESEL_INFO_LID,

        NVRAM_EF_APPLIST_DATA_LID,
        NVRAM_EF_MOBILE_TV_PLAYER_SETTING_LID,
        NVRAM_EF_DTV_PLAYER_SETTING_LID,

        NVRAM_EF_LANGLN_BSK_SETTING_LID,
        NVRAM_EF_SLIDE_SHOW_SETTING_LID,    /* __MMI_SLIDESHOW__ */
        NVRAM_EF_VT_SETTING_LID,
        NVRAM_EF_BT_BIP_SETTING_LID, /* __MMI_BIP_SUPPORT__ */
        NVRAM_EF_BARCODEREADER_OP11_SETTING_LID,

        NVRAM_EF_VIDEO_NETWORK_PROFILE_LID,
        NVRAM_EF_DCD_SETTING_DATA_LID, /*__MMI_OP01_DCD__*/
        NVRAM_EF_CAMCO_MAIN_SETTING_LID,
        NVRAM_EF_CAMCO_MAIN_SETTING_SCENE_SEL_LID,


        NVRAM_EF_AUDPLY_LAST_PLAYLIST_PATH_LID,
        NVRAM_EF_AUDPLY_WALK_LID,

        /* phonebook vip contact */
        NVRAM_EF_PHB_VIP_CONTACT_LID,
        /* phonebook vip contact */

        NVRAM_EF_SMS_EMAIL_LID, /* __MMI_MESSAGES_SMS_EMAIL__ */
        NVRAM_EF_HOMESCREEN_CNTX_LID,   /* __MMI_OP11_HOMESCREEN__ */

        NVRAM_EF_BT_DEFDEVICE_LID,

		NVRAM_EF_TDL_BR_LID,

		NVRAM_EF_SMS_VOICEMAIL_TIME_LID,        /* __MMI_OP11_HOMESCREEN__ __MMI_OP12_TOOLBAR__*/
        NVRAM_EF_VS_SETTING_LID,
        NVRAM_EF_IPSEC_POLICY_LID,
        NVRAM_EF_IPSEC_IKE_LID,
        NVRAM_EF_PHB_DEFAULT_NUMBER_LID,

        NVRAM_EF_PHB_ICE_CONTACT_LID,

        NVRAM_EF_SMS_UD_TMEP_LID,                       /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */

        NVRAM_EF_SYNCML_VIEW_LOG_LID,
        NVRAM_EF_BCR_SETTING_LID, /*bcr setting id*/
        NVRAM_EF_ANSWER_MACHINE_SETTING_LID,

        NVRAM_EF_TOOLBAR_CNTX_LID,      /* __MMI_OP12_TOOLBAR__ */

        NVRAM_EF_MEDPLY_SETTINGS_LID,
        NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_LID,
        NVRAM_EF_MEDPLY_LAST_PLAYLIST_PATH_LID,
        NVRAM_EF_MEDPLY_HISTORY_URL_LID,
		NVRAM_EF_PUSH_GEN_SETTING_LID,
		NVRAM_EF_PUSH_BLACK_LIST_LID,
		NVRAM_EF_PUSH_WHITE_LIST_LID,

        NVRAM_EF_INET_CUSTPACK_LID, /* Internet Application */
        NVRAM_EF_IPSEC_PROFILE_NAME_LID,

        NVRAM_EF_PICTBRIDGE_LID, /* pictbridge */

        NVRAM_EF_SYNCML_DEV_SETTING_LID,	/* Syncml Device */
        NVRAM_EF_SYNCML_DEV_ACCOUNT_LID,
        NVRAM_EF_SYNCML_DEV_SYNC_LOG_LID,
        NVRAM_EF_WAP_BOOKMARK_LIST_LID,
        NVRAM_EF_WHITE_LIST_LID,            /* __MMI_CM_WHITE_LIST__ */
        NVRAM_EF_FMRDO_SCHEDULER_LID,          /* __MMI_FM_RADIO_SCHEDULER__ */
        NVRAM_EF_BCR_FIELD_SET_LID,
        NVRAM_EF_BT_BIP_SET_FOLDER_LID, /* __MMI_BIP_SUPPORT__ */

        NVRAM_EF_MEDPLY_PREDEFINED_URL_LID,

        NVRAM_EF_CAMCO_APP_INFO_LID,
        NVRAM_EF_CAMCO_SUB_SETTING_LID,
        NVRAM_EF_CAMCO_SUB_SETTING_SCENE_SEL_LID,
        NVRAM_EF_EMAIL_DATA_ACCOUNT_LID,    /* Email Data Account */
        NVRAM_EF_ECOMPASS_LID,
        NVRAM_EF_SYNCML_ACCOUNT_LID,

		NVRAM_EF_NOTE_APP_LID,  /* __MMI_NOTE_APP__ */

        NVRAM_EF_SEARCH_WEB_HISTORY_LID,    /* __MMI_SEARCH_WEB__ */
        NVRAM_EF_SEARCH_WEB_BAIDU_UID_LID,  /* __MMI_SEARCH_WEB_BAIDU__ */

        NVRAM_EF_VENUS_HS_WIDGET_MGR_LID,           /* __MMI_VUI_HOMESCREEN__ */
        NVRAM_EF_VENUS_HS_WIDGET_MEMO_CNTX_LID,     /* Venus home screen Memo widget */
        NVRAM_EF_VENUS_MM_LID,                       /* __MMI_VUI_MAINMENU__ */
        NVRAM_EF_VENUS_PHOTO_FILEPATH_LID,          /* __MMI_VUI_HOMESCREEN_PHOTO__ */

        NVRAM_EF_CNMGR_CONNECT_DATA_LID,
        NVRAM_EF_DCD_EM_PARAM_DATA_LID, /*__MMI_EM_MISC_DCD__*/
        NVRAM_EF_ZAKAT_CALCULATOR_LID,
        NVRAM_EF_AZAAN_ALARM_LID,                   /* __MMI_AZAAN_ALARM__ */
        NVRAM_EF_IVEX_SETTINGS_LID,        /* __MMI_IMAGE_VIEWER_EX__ */

        NVRAM_EF_TDL_EVENT_LID,
        NVRAM_EF_TDL_TASK_LID,

        NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_LID,
        NVRAM_EF_SRV_SMS_PDU_LID,
		NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_LID,	/* __SRV_SMS_RECENT_EVENT__ */

        NVRAM_EF_CERTMAN_OCSP_URL_LID,

        NVRAM_EF_AM_HS_SHORTCUT_LIST_LID,

	    NVRAM_EF_MRE_APP_BAN_LIST_EXT_LID,
    	NVRAM_EF_MRE_PKEY_LIST_EXT_LID,
    	NVRAM_EF_MRE_SYM_ENTRY_LIST_EXT_LID,
    	NVRAM_EF_MRE_SYM_CONF_LIST_EXT_LID,
    	NVRAM_EF_MRE_FIRST_RUNNING_LID,
        NVRAM_EF_VENUS_HS_WIDGET_CLOCK_CNTX_LID,     /* Venus home screen clock widget */
        NVRAM_EF_CUBE_VIP_CONTS_LID,    /* Vip contact arrays */

    	NVRAM_EF_OP11_HS32_HIST_LID, /* __MMI_OP11_HOMESCREEN_0301__ || __MMI_OP11_HOMESCREEN_0302__ */
        NVRAM_EF_VENUS_HS_SHORTCUT_MGR_LID,         /* __MMI_VUI_HOMESCREEN__ */

        NVRAM_EF_SRV_SMS_SIM_CUST_DATA_LID,     /* __SRV_SMS_SIM_CUST_DATA__ */
        NVRAM_EF_WGTMGR_DATA_LID,

        NVRAM_EF_SLIDE_SHOW_PATH_LID,
        NVRAM_EF_SLIDE_SHOW_AUDIO_LID,
        NVRAM_EF_OPERA_ADP_PROF_SETTING_LID,    /* OPERA_BROWSER */
#ifdef __SRV_CBS_SUPPORT__
        NVRAM_EF_SRV_CBS_PAGE_LID,
        NVRAM_EF_SRV_CBS_MSG_NODE_LID,
        NVRAM_EF_SRV_CBS_CHNL_NAME_LID,
#endif
#if defined(__DA_SMART_SELECTION_SUPPORT__)
        NVRAM_EF_DTCNT_SIM_ID_LID,
#endif
        NVRAM_EF_BTHF_CONFIG_LID,
#ifdef __MMI_FILE_MANAGER__
#ifdef __MMI_SCREEN_SAVER__
        NVRAM_EF_SCREENSAVER_FILENAME_LID,
#endif /* __MMI_SCREEN_SAVER__ */
#ifdef __MMI_POWER_ON_OFF_DISPLAY__
        NVRAM_EF_POWER_ON_OFF_DISP_FILENAME_LID,
#endif
#endif /* __MMI_FILE_MANAGER__ */
        NVRAM_EF_PHB_VT_CONTACT_LID,

        NVRAM_EF_SRV_SMS_STATUS_REPORT_LID,
        NVRAM_EF_VENUS_SHELL_PAGE_ORDER_LID,
    #ifdef __MMI_TELEPHONY_SUPPORT__

        /* For CallLog */
        NVRAM_EF_CLOG_LOG_LID,                      /* __CLOG_STORAGE_BY_MMI__*/
        NVRAM_EF_CLOG_CALL_TIME_LID,                /* __CLOG_STORAGE_BY_MMI__*/
    #endif
        NVRAM_EF_SHELL_SHORTCUTS_LID,
        NVRAM_EF_SHELL_FC_LID,
        NVRAM_EF_VENUS_3D_MM_LID,
        #ifdef __MMI_WLAN_FEATURES__
        NVRAM_EF_CMCC_WIFI_SETTING_LID,
        #endif 
        NVRAM_EF_BT_AUTO_DETECT_SETTING_LID,		/* __BT_AUTO_DETECT_SUPPORT__ */
        NVRAM_EF_MMI_CACHE_BYTE_KEY_LID,
        NVRAM_EF_MMI_CACHE_SHORT_KEY_LID,
        NVRAM_EF_MMI_CACHE_DOUBLE_KEY_LID,
        NVRAM_EF_SRV_REMINDER_Q_LID,

        NVRAM_EF_SRV_SMS_ADDR_LID,                  /* __SRV_SMS_MULTI_ADDR__ */
        NVRAM_EF_DM_APP_LAWMO_INFO_LID,
#if (MMI_MAX_SIM_NUM>=3)
		NVRAM_EF_GROUPLIST_SIM3_LID,
#endif
		
#if (MMI_MAX_SIM_NUM>=4)
		NVRAM_EF_GROUPLIST_SIM4_LID,
#endif
        NVRAM_EF_PUSHMAIL_INFO_LID,         /* __MMI_139_PUSH_MAIL__ */

        /* CMCC TD WIFI */
        //NVRAM_EF_CMCC_WIFI_SETTING_LID,
        NVRAM_EF_CMCC_WIFI_BLACK_LIST_LID,

        NVRAM_EF_SRV_TETHERING_DTCNT_LID,
        NVRAM_EF_SRV_TETHERING_WIFI_HS_SETTINGS_LID,

        NVRAM_EF_BLACK_LIST_VIDEO_LID,            /* __MMI_CM_BLACK_LIST_EXT__ */
        NVRAM_EF_WHITE_LIST_VIDEO_LID,            /* __MMI_CM_WHITE_LIST_EXT__ */
        NVRAM_EF_PUSH_SWITCH_SETTING_LID,   /* __MMI_PUSH_TURN_ON_OFF_SWITCH__ */

        NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_LID,          /* __MMI_OP01_WIFI__ */

        NVRAM_EF_VT_SETTING_REMOTE_PIC_LID,

        NVRAM_EF_OP01_HS_SETTING_LID,            /* __MMI_VUI_SHELL_OP01_HOMESCREEN__ */
        NVRAM_EF_DM_SRV_ACC_LID,
        NVRAM_EF_DIALER_DIRECT_DIAL_LID,
        NVRAM_EF_MRE_PKEY_LIST_MTK_LID,

    #ifdef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
        NVRAM_EF_MMI_PROF_NEW_NAME_LID,
        NVRAM_EF_MMI_PROF_NEW_FLAG_LID,
    #endif
        NVRAM_EF_CNMGR_SCRI_CHECK_TIME_LID,
        
    #if defined(__MMI_VUI_LAUNCHER__)
        NVRAM_EF_VAPP_DRAWER_ORDER_DATA_LID,
        NVRAM_EF_VENUS_LAUNCHER_DESKTOP_LID,
    #endif
    #ifdef __MMI_VUI_LAUNCHER_KEY__
        NVRAM_EF_VAPP_KMM_ORDER_DATA_LID,
    #endif /* defined(__MMI_VUI_LAUNCHER__) */

        NVRAM_EF_QUICKTEST_LID,

    #ifdef __NFC_SUPPORT__
		NVRAM_EF_NFC_STATUS_LID,
    #endif
    #ifdef __SOCIAL_NETWORK_SUPPORT__
        NVRAM_EF_SRV_SNS_ACCOUNT_LID,
    #endif /* __SOCIAL_NETWORK_SUPPORT__ */
        NVRAM_EF_SRV_SSO_ACCOUNT_LID,
	#ifdef __MMI_VUI_LAUNCHER_KEY__
		NVRAM_EF_PHNSET_WIDGET_MGR_SYS_LIST_LID,
		NVRAM_EF_PHNSET_SHCUT_APP_LIST_LID,
	#endif

	#ifdef MOTION_SENSOR_SUPPORT
		NVRAM_EF_MOTION_SENSOR_SWITCH_LID,
	#endif
	#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
		NVRAM_EF_NETSET_SIM_NAME_LID,
	#endif

    #ifdef __MMI_VUI_SCREEN_LOCK_KEY__
        NVRAM_EF_SCREEN_LOCK_KEY_IMG_SETTING_LID,
    #endif
    #ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
        NVRAM_EF_DMSR_SIM_IMSI_LID,
    #endif
	#ifdef __MMI_NSS_SUPPORT__
    NVRAM_EF_SRV_NSS_PROFILE_LID,      /*__MMI_NSS_SUPPORT__*/
    #endif
    #ifdef __MMI_MRE_MSPACE__
        NVRAM_EF_SRV_MSPACE_LID,
    #endif

    /* ADD-S  20120417 FOR CMMBCAS2GPP*/	
#ifdef CMMB_CAS_2GPP_V10
    NVRAM_EF_CMMB_CAS_2GPP_LID,
#endif
    NVRAM_EF_MRE_PKEY_EX_LID,

#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
    NVRAM_EF_SYS_LANGUAGE_SSC_LID,
#endif /* __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__*/

#ifdef __MMI_APPLIST_BARREL_SUPPORT__
    NVRAM_EF_APPLIST_BARREL_EFFECT_LID,
#endif

#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__		
    NVRAM_EF_DLT_APPICON_LID,
#endif	
#if defined(__MMI_BT_DIALER_SUPPORT__) && !defined(__MMI_BT_BTBOX_NOLCD__)
    NVRAM_BYTE_BT_DIALER_CONNSTR,   
    NVRAM_BYTE_BT_DIALER_AUTO_CONN,
#endif
#if defined(__CERTMAN_SUPPORT__) 
    NVRAM_EF_CERTMAN_CERT_LID, 
#endif
#ifdef __IOT__
    NVRAM_EF_WIFIAP_MODE_CONFIG_LID,
#endif /* __IOT__ */
#if defined(__WIFI_SUPPORT__) && defined(__IOT__)
    NVRAM_EF_WLAN_SCAN_SETTING_LID,
#endif

//hukingnvarm
#if defined(__MMI_FRM_INPUT_EVT__)
	NVRAM_EF_LED_INFO_LID,
	NVRAM_EF_VIB_INFO_LID,
	NVRAM_EF_AUD_INFO_LID,
	NVRAM_EF_NOTIFY_INFO_LID,
	NVRAM_EF_INPUT_EVENT_INFO_LID,
	NVRAM_EF_LOCAL_APP_INFO_LID,
#endif/*#if defined(__MMI_FRM_INPUT_EVT__)*/

#ifndef __MMI_TELEPHONY_SUPPORT__
	NVRAM_EF_PHONE_LOCK_LID,
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    /* ADD-E  20120417 FOR CMMBCAS2GPP*/
/**************************************************************************
 *   Add new entry in the tail with its compile optoin                    *
 *   Add new entry in the tail with its compile optoin                    *
 *   Add new entry in the tail with its compile optoin                    *
 **************************************************************************/
        NVRAM_EF_LAST_LID_COMMAPP
    } nvram_lid_commapp_enum;


/**
 * For each logical data item, defines its constants of `size' and `number of records'
 * For linear-fixed, TOTAL is greater than 1, and SIZE is size of each record;
 * for transparent, TOTAL must be exaclty 1, and SIZE is size of entire data item.
 *
 * Each logical data item must be:
 * Size of default value must be equal to the logical data item's size.
 */

/************************************
 * Custom MMI Define Start
 ************************************/
/* for mmi cache *//* Move to other file */
#define NVRAM_CACHE_SIZE               504      /* For Cache file */
#define NVRAM_CACHE_TOTAL              1        /* For Cache file */

#define NVRAM_MMI_CACHE_BYTE_KEY_SIZE      504      /* dependency to the cache size and the key size */
#define NVRAM_MMI_CACHE_BYTE_KEY_TOTAL     4

#define NVRAM_MMI_CACHE_SHORT_KEY_SIZE     504      /* dependency to the cache size and the key size */
#define NVRAM_MMI_CACHE_SHORT_KEY_TOTAL    2

#define NVRAM_MMI_CACHE_DOUBLE_KEY_SIZE    504      /* dependency to the cache size and the key size */
#define NVRAM_MMI_CACHE_DOUBLE_KEY_TOTAL   1


#define NVRAM_CSB_SETTINGS_SIZE			48
#define NVRAM_CSB_SETTINGS_TOTAL		1

#define NVRAM_EF_CUST_SIZE             16
#define NVRAM_EF_CUST_TOTAL            2

#define NVRAM_DOWNLOAD_IMAGE_RECORD_SIZE     40
#define NVRAM_DOWNLOAD_IMAGE_RECORD_TOTAL    1

#define NVRAM_DOWNLOAD_TONE_RECORD_SIZE      40
#define NVRAM_DOWNLOAD_TONE_RECORD_TOTAL     1

#define NVRAM_DOWNLOAD_MELODY_RECORD_SIZE    40
#define NVRAM_DOWNLOAD_MELODY_RECORD_TOTAL   1

#define NVRAM_EF_TEST_1_SIZE                 10
#define NVRAM_EF_TEST_1_TOTAL                2

#define NVRAM_EF_PHONEBOOK_SIZE        16
#define NVRAM_EF_PHONEBOOK_TOTAL       2

#ifdef __MMI_THEMES_APPLICATION__
#ifdef __MMI_THEMES_V2_SUPPORT__
#define NVRAM_THEMES_VALUES_SIZE       124
#else
#define NVRAM_THEMES_VALUES_SIZE       8
#endif
#define NVRAM_THEMES_VALUES_RECORDS    1
#endif /* __MMI_THEMES_APPLICATION__ */

#define NVRAM_THEMES_DOWNLOAD_SIZE        1282
#define NVRAM_THEMES_DOWNLOAD_RECORDS     1

#define NVRAM_MAX_GROUP_NAME_SIZE      sizeof(nvram_group_lists_struct)
#define NVRAM_MAX_GROUP_NAME_TOTAL     11

#define NVRAM_COMPOSE_RINGTONE_TOTAL   1
#define NVRAM_COMPOSE_RINGTONE_SIZE    40*5

#define NVRAM_IP_NUMBER_TOTAL          1
#define NVRAM_IP_NUMBER_SIZE           22*4

#define NVRAM_SHORTCUTS_SIZE           256
#define NVRAM_SHORTCUTS_TOTAL       2

#ifdef __MMI_CUSTOMER_SERVICE__
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_MESSAGES_PREDEFINED_TEMPLATE__
#define NVRAM_SMS_TEMPL_RECORD_SIZE    84
#define NVRAM_SMS_RECORD_TOTAL         31
#endif /* __MMI_MESSAGES_PREDEFINED_TEMPLATE__ */

#ifdef __MMI_MESSAGES_USERDEFINED_TEMPLATE__
#define NVRAM_SMS_UD_TEMPL_RECORD_SIZE    324
#define NVRAM_SMS_UD_RECORD_TOTAL         11
#endif /* __MMI_MESSAGES_USERDEFINED_TEMPLATE__ */

#ifdef __MMI_EMAIL_TEMPLATE__
#define NVRAM_EMAIL_TEMPL_RECORD_SIZE    84
#define NVRAM_EMAIL_RECORD_TOTAL         31
#endif /* __MMI_EMAIL_TEMPLATE__ */

#ifdef __MOD_SMSAL__
#define NVRAM_SMS_MAX_DIGITS_SMS        21
#endif /* __MOD_SMSAL__ */


#ifdef __MMI_MESSAGES_SMS_EMAIL__
#define NVRAM_SMS_EMAIL_RECORD_SIZE         sizeof(nvram_sms_email_address_struct)
#define NVRAM_SMS_EMAIL_RECORD_TOTAL        4
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

#ifdef __DOWNLOAD__
#define NVRAM_EMS_MY_PICTURE_NAME_RECORD_SIZE      140
#define NVRAM_EMS_MY_PICTURE_NAME_RECORD_TOTAL  1

#define NVRAM_EMS_MY_ANIMATION_NAME_RECORD_SIZE  140
#define NVRAM_EMS_MY_ANIMATION_NAME_RECORD_TOTAL    1
#ifdef __MMI_IMELODY_SUPPORT__
#define NVRAM_EMS_MY_MELODY_NAME_RECORD_SIZE     140
#define NVRAM_EMS_MY_MELODY_NAME_RECORD_TOTAL           1
#endif /* __MMI_IMELODY_SUPPORT__ */
#endif /* __DOWNLOAD__ */
    /* NVRAM for Data Account Application. */
#define NVRAM_DATA_ACCOUNT_RECORD_SIZE    200
#define NVRAM_DATA_ACCOUNT_RECORD_TOTAL   4


#ifdef __TCPIP_OVER_CSD__
/**
 * CSD profile
 */
/*[MAUI_00778420]*/
#if defined(__L4_MAX_NAME_60__)
#define NVRAM_EF_CSD_PROFILE_SIZE               216
#else
#define NVRAM_EF_CSD_PROFILE_SIZE               186
#endif
#define NVRAM_EF_CSD_PROFILE_TOTAL              10
#endif /* __TCPIP_OVER_CSD__ */

/**
 * External Melody
 */
#define NVRAM_EF_EXT_MELODY_INFO_SIZE              1748 /* 1696 */
#define NVRAM_EF_EXT_MELODY_INFO_TOTAL             1



/*---------------------- CallLog Begin ---------------------------------------*/
#if defined(__CLOG_STORAGE_BY_MMI__)

/*------- For Call log --------*/

/* CID number length */
#define NVRAM_CLOG_PHB_NUM_PLUS_MAX_LEN     (MMI_PHB_NUMBER_PLUS_LENGTH)
#define NVRAM_CLOG_VOIP_URI_MAX_LEN         (VOIP_URI_LEN - 1)

#ifdef __MMI_VOIP__
#define NVRAM_CLOG_CID_MAX_LEN   \
    (NVRAM_CLOG_PHB_NUM_PLUS_MAX_LEN > NVRAM_CLOG_VOIP_URI_MAX_LEN ? NVRAM_CLOG_PHB_NUM_PLUS_MAX_LEN : NVRAM_CLOG_VOIP_URI_MAX_LEN)
#else
#define NVRAM_CLOG_CID_MAX_LEN              (NVRAM_CLOG_PHB_NUM_PLUS_MAX_LEN)
#endif

#if (defined(__MMI_CLOG_SLIM__) && !defined(__MMI_VOIP__))
#define NVRAM_CLOG_CID_BCD_MAX_LEN              (NVRAM_CLOG_CID_MAX_LEN / 2 + 1)
#else
#define NVRAM_CLOG_CID_BCD_MAX_LEN              (NVRAM_CLOG_CID_MAX_LEN + 1)
#endif


/* Name length */
#define NVRAM_CLOG_NAME_MAX_LEN             (MMI_PHB_NAME_LENGTH)

/* Log size */
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
#define NVRAM_EF_CLOG_LOG_SIZE              (sizeof(nvram_ef_clog_logs_struct))

#define NVRAM_EF_CLOG_LOG_PARAM_SIZE        sizeof(nvram_ef_clog_call_log_struct)
#define NVRAM_EF_CLOG_LOG_PEND_SIZE         (NVRAM_EF_CLOG_LOG_SIZE - NVRAM_EF_CLOG_LOG_PARAM_SIZE)
#define NVRAM_EF_CLOG_LOG_PEND_LEN          (NVRAM_EF_CLOG_LOG_PEND_SIZE / 4)
#else 
#define NVRAM_EF_CLOG_LOG_SIZE              sizeof(nvram_ef_clog_log_union)
#define NVRAM_EF_CLOG_LOG_PARAM_SIZE        sizeof(nvram_ef_clog_base_log_struct)
#define NVRAM_EF_CLOG_LOG_PEND_SIZE         (NVRAM_EF_CLOG_LOG_SIZE - NVRAM_EF_CLOG_LOG_PARAM_SIZE)
#define NVRAM_EF_CLOG_LOG_PEND_LEN          (NVRAM_EF_CLOG_LOG_PEND_SIZE / 4)
#endif 

/* NVRAM Record default value */
#define NVRAM_EF_CLOG_DEFAULT

/* NVRAM Record Size */
#define NVRAM_EF_CLOG_SIZE                  sizeof(nvram_ef_clog_log_struct)

/* NVRAM Record Total number */
#ifdef __MMI_CLOG_SLIM_FOR_MT6261__
#define NVRAM_EF_CLOG_LOG_TOTAL             (CUSTOM_CLOG_MAX_LOG_NUM / CUSTOM_CLOG_NUM_PER_RECORD)
#else /* __MMI_CLOG_SLIM_FOR_MT6261__ */
#define NVRAM_EF_CLOG_LOG_TOTAL             CUSTOM_CLOG_MAX_LOG_NUM
#endif /* __MMI_CLOG_SLIM_FOR_MT6261__ */

/*------- For Call Time --------*/
#define NVRAM_EF_CLOG_CALL_TIME_SIZE        sizeof(nvram_ef_clog_call_time_struct)
#define NVRAM_EF_CLOG_CALL_TIME_TOTAL       (12) /* sim_num & call_type_num = 4 * 3 */

#endif /* __CLOG_STORAGE_BY_MMI__ */

/*---------------------- CallLog End -----------------------------------------*/





#if defined (PLUTO_MMI)
#define NVRAM_EF_PHB_DEFAULT NVRAM_EF_ZERO_DEFAULT
#else
#define NVRAM_EF_PHB_DEFAULT NVRAM_EF_FF_DEFAULT
#endif

#ifdef __PHB_STORAGE_BY_MMI__
#define NVRAM_EF_PHB_SIZE                  (sizeof(mmi_phb_name_struct))
#define NVRAM_EF_PHB_TOTAL                 MAX_PHB_PHONE_ENTRY
#endif

#define NVRAM_EF_PHB_FIELDS_MASK_SIZE      (MMI_PHB_FIELDS_MASK_COUNT * MMI_PHB_FIELDS_MASK_SIZE)
#define NVRAM_EF_PHB_FIELDS_MASK_TOTAL     ((MMI_PHB_FIELDS_MASK_TOTAL - 1) / MMI_PHB_FIELDS_MASK_COUNT + 1)

#define NVRAM_EF_PHB_FIELDS_SIZE           (sizeof(mmi_phb_optional_fields_struct))
#define NVRAM_EF_PHB_FIELDS_TOTAL          MAX_PHB_PHONE_ENTRY

#define NVRAM_EF_PHB_INFO_SIZE             (sizeof(mmi_phb_info_struct))
#define NVRAM_EF_PHB_INFO_TOTAL            MAX_PHB_PHONE_ENTRY

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
#define NVRAM_EF_PHB_BIRTHDAY_SIZE         (sizeof(mmi_phb_bday_struct))
#define NVRAM_EF_PHB_BIRTHDAY_TOTAL        MAX_PHB_PHONE_ENTRY
#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */

#ifdef __MMI_PHB_CALLER_GROUP__
#define NVRAM_EF_PHB_GROUP_FIELD_SIZE      (MMI_PHB_GROUP_FIELD_COUNT * MMI_PHB_GROUP_FIELD_SIZE)
#define NVRAM_EF_PHB_GROUP_FIELD_TOTAL     ((MMI_PHB_GROUP_FIELD_TOTAL - 1) / MMI_PHB_GROUP_FIELD_COUNT + 1)

#define NVRAM_EF_PHB_GROUP_INFO_SIZE       (sizeof(mmi_phb_group_info_struct) * MMI_PHB_GROUP_COUNT)
#define NVRAM_EF_PHB_GROUP_INFO_TOTAL      1
#endif /* __MMI_PHB_CALLER_GROUP__ */

#define NVRAM_EF_PHB_MY_NUMBER_SIZE        (sizeof(mmi_phb_my_number_struct))
#define NVRAM_EF_PHB_MY_NUMBER_TOTAL       1

#define NVRAM_EF_PHB_SPEEDDIAL_SIZE        (sizeof(mmi_phb_speed_dial_struct))
#define NVRAM_EF_PHB_SPEEDDIAL_TOTAL       MMI_PHB_SPEED_DIAL_COUNT

#define NVRAM_EF_PHB_SOS_SIZE              (sizeof(mmi_phb_sos_number_struct))
#define NVRAM_EF_PHB_SOS_TOTAL             MMI_PHB_SOS_NUMBER_COUNT

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_WIDGET_KEY_VIP_CONTACT__)
#define NVRAM_EF_PHB_VIP_CONTACT_SIZE      (sizeof(mmi_phb_vip_contact_struct)) * MMI_PHB_VIP_CONTACT_COUNT
#define NVRAM_EF_PHB_VIP_CONTACT_TOTAL     1
#endif /* defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) || defined(__MMI_OP11_HOMESCREEN__)*/

#ifdef __OP11__ /*__MMI_PHB_ICE_CONTACT__ */
#define NVRAM_EF_PHB_ICE_CONTACT_SIZE      (sizeof(mmi_phb_ice_contact_struct)) * MMI_PHB_ICE_CONTACT_COUNT
#define NVRAM_EF_PHB_ICE_CONTACT_TOTAL     1
#endif /* __OP11__ */

#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
#define NVRAM_EF_PHB_FIELD_LABEL_SIZE      (sizeof(kal_uint16) * (MMI_PHB_FIELD_LABEL_LENGTH + 1))
#define NVRAM_EF_PHB_FIELD_LABEL_TOTAL     (MMI_PHB_FIELD_LABEL_COUNT * MMI_PHB_FIELD_LABEL_FIELD)
#endif

#ifdef __MMI_AVATAR__
/**
 * AVATAR Settings
 */
#define NVRAM_EF_AVATAR_SETTING_TOTAL       1
#define NVRAM_EF_AVATAR_SETTING_SIZE        512
#endif

#ifdef __MMI_ATV_SUPPORT__
/**
 * Mobile TV Player Settings
 */
#define NVRAM_EF_MOBILE_TV_PLAYER_SETTING_TOTAL       1
#define NVRAM_EF_MOBILE_TV_PLAYER_SETTING_SIZE       30
#endif

#ifdef __MMI_MOBILE_TV_CMMB_SUPPORT__
/**
 * DTV Player Settings
 */
#define NVRAM_EF_DTV_PLAYER_SETTING_TOTAL       1
#define NVRAM_EF_DTV_PLAYER_SETTING_SIZE       sizeof(nvram_dtv_player_setting_struct)
#endif

#ifdef __MMI_LAUNCHER_APP_LIST__

#include "lcd_sw_inc.h"
//TODO: maybe move to another custom header folder
#if ((LCD_WIDTH == 240) && (LCD_HEIGHT == 320)) /* QVGA */
#define NVRAM_EF_APPLIST_PANEL_APP_NUM (108) //(4*3) 9 pages
#define NVRAM_EF_APPLIST_BAR_APP_NUM (4)
#elif ((LCD_WIDTH == 320) && (LCD_HEIGHT == 240))
#define NVRAM_EF_APPLIST_PANEL_APP_NUM (100) //(2*5) 10 pages
#define NVRAM_EF_APPLIST_BAR_APP_NUM (5)
#else
#define NVRAM_EF_APPLIST_PANEL_APP_NUM (112) //(4*4) 7 pages
#define NVRAM_EF_APPLIST_BAR_APP_NUM (4)
#endif

typedef struct
{
    kal_uint32 bar_id[NVRAM_EF_APPLIST_BAR_APP_NUM];
    kal_uint32 panel_id[NVRAM_EF_APPLIST_PANEL_APP_NUM];    
}mmi_applist_data_struct;

#define NVRAM_EF_APPLIST_DATA_TOTAL       1
#define NVRAM_EF_APPLIST_DATA_SIZE  (sizeof(mmi_applist_data_struct))
#endif


#ifdef __MMI_BARCODEREADER__
/**
 * Barcode Reader Settings
 */
#define NVRAM_EF_BARCODEREADER_SETTING_TOTAL       1
#define NVRAM_EF_BARCODEREADER_SETTING_SIZE        30

#if defined(__MMI_OP11_BARCODEREADER__)
/* under construction !*/
/* under construction !*/
    #endif
#endif

#ifdef __MMI_BCR__
/**
 * BCR Settings
 */
#define NVRAM_EF_BCR_SETTING_TOTAL       1
#define NVRAM_EF_BCR_SETTING_SIZE        32

#define NVRAM_EF_BCR_FIELD_SET_TOTAL     1
#define NVRAM_EF_BCR_FIELD_SET_SIZE      32

#endif

#ifdef __MMI_IPSEC__
/**
 * IPSec Settings MMI
 */
#define NVRAM_EF_IPSEC_POLICY_TOTAL                 3
#define NVRAM_EF_IPSEC_POLICY_SIZE                  sizeof(nvram_ef_ipsec_policy_struct)
#define NVRAM_EF_IPSEC_IKE_TOTAL                    3
#define NVRAM_EF_IPSEC_IKE_SIZE                     sizeof(nvram_ef_ipsec_ike_struct)
#endif /* __MMI_IPSEC__ */

#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
/**
 * Camera Settings
 */
#define NVRAM_EF_CAMERA_SETTING_TOTAL              1
#ifdef __CAMERA_FEATURE_EFFECT_CUSTOM__
#define NVRAM_EF_CAMERA_SETTING_SIZE               84
#else
#define NVRAM_EF_CAMERA_SETTING_SIZE               60
#endif
#endif /* defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__) */

#if defined (__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
/**
 * Video Settings
 */
#define NVRAM_EF_VIDEO_SETTING_TOTAL               1
#define NVRAM_EF_VIDEO_SETTING_SIZE                135
#endif /* defined (__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__) */

#ifdef __MMI_PHOTOEDITOR__
/**
 * Photo Editor Settings
 */
#define NVRAM_EF_PHOTO_EDITOR_SETTING_TOTAL        1
#define NVRAM_EF_PHOTO_EDITOR_SETTING_SIZE         200
#endif /* __MMI_PHOTOEDITOR__ */


#define	NVRAM_EF_MRE_PKEY_LIST_EXT_SIZE  1832
#define	NVRAM_EF_MRE_PKEY_LIST_EXT_TOTAL 2

#define	NVRAM_EF_MRE_APP_BAN_LIST_EXT_SIZE  1056
#define	NVRAM_EF_MRE_APP_BAN_LIST_EXT_TOTAL 1

#define	NVRAM_EF_MRE_SYM_ENTRY_LIST_EXT_SIZE 1608
#define	NVRAM_EF_MRE_SYM_ENTRY_LIST_EXT_TOTAL 1

#define	NVRAM_EF_MRE_SYM_CONF_LIST_EXT_SIZE  	136
#define	NVRAM_EF_MRE_SYM_CONF_LIST_EXT_TOTAL	1
#define	NVRAM_EF_MRE_FIRST_RUNNING_SIZE 17
#define	NVRAM_EF_MRE_FIRST_RUNNING_TOTAL 1

#define	NVRAM_EF_MRE_PKEY_LIST_MTK_SIZE  1832
#define	NVRAM_EF_MRE_PKEY_LIST_MTK_TOTAL 1

#define	NVRAM_EF_MRE_PKEY_EX_SIZE  192
#define	NVRAM_EF_MRE_PKEY_EX_TOTAL 1


#ifdef __MRE_AM__
#define	NVRAM_EF_AM_HS_SHORTCUT_LIST_SIZE sizeof(nvram_am_hs_shortcut_t)
#define	NVRAM_EF_AM_HS_SHORTCUT_LIST_TOTAL 5
#endif

/**
 * File Manager FilePath Pool Settings
 */
#if defined (__MMI_CAMERA__) || defined(__MMI_CAMCORDER__)
#define NVRAM_EF_FMGR_FILEPATH_CAMERA             1
#else
#define NVRAM_EF_FMGR_FILEPATH_CAMERA             0
#endif

#if defined(__MMI_VIDEO_PLAYER__) || (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__))
#define NVRAM_EF_FMGR_FILEPATH_VIDEO              1
#else
#define NVRAM_EF_FMGR_FILEPATH_VIDEO              0
#endif

#ifdef __MMI_PHOTOEDITOR__
#define NVRAM_EF_FMGR_FILEPATH_PHOEDT             1
#else
#define NVRAM_EF_FMGR_FILEPATH_PHOEDT             0
#endif

#ifdef __MMI_VIDEO_STREAM__
#define NVRAM_EF_FMGR_FILEPATH_VIDEO_STREAM       1
#else
#define NVRAM_EF_FMGR_FILEPATH_VIDEO_STREAM       0
#endif

#ifdef __MMI_VIDEO_EDITOR__
#define NVRAM_EF_FMGR_FILEPATH_VDOEDT            1
#else
#define NVRAM_EF_FMGR_FILEPATH_VDOEDT            0
#endif /* __MMI_VIDEO_EDITOR__ */

#ifdef __MMI_SLIDESHOW__
#define NVRAM_EF_FMGR_FILEPATH_SLIDESHOW          2
#else
#define NVRAM_EF_FMGR_FILEPATH_SLIDESHOW          0
#endif

#if defined(__MMI_IMAGE_VIEWER__) || defined(__MMI_FILE_MANAGER__)
#define NVRAM_EF_FMGR_FILEPATH_IMAGE_VIEWER          2
#else
#define NVRAM_EF_FMGR_FILEPATH_IMAGE_VIEWER          0
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
#else
#define NVRAM_EF_FMGR_FILEPATH_COUNT 0
#endif
#ifdef __PS_SERVICE__
/**
 * ABM_GPRS_PROFILE
 */
#ifdef __MMI_OP01_GPRS_DATACFG__
/* under construction !*/
#else
#ifdef __SLIM_NWK_PROFILE__
#define NVRAM_EF_ABM_GPRS_PROFILE_TOTAL            5
#else
#define NVRAM_EF_ABM_GPRS_PROFILE_TOTAL            10
#endif
#endif /* __MMI_OP01_GPRS_DATACFG__ */

#define NVRAM_EF_ABM_GPRS_PROFILE_SIZE             252

#endif /* __PS_SERVICE__ */

    /* changes for the Greeting Text */
#define NVRAM_SETTING_SIZE                      60
#define NVRAM_SETTING_TOTAL                     1

#ifdef __MMI_BT_DIALER_SUPPORT__
#define  NVRAM_BYTE_BT_DIALER_CONNSTR_SIZE    100       
#define  NVRAM_BYTE_BT_DIALER_CONNSTR_TOTAL     1
#define  NVRAM_BYTE_BT_DIALER_AUTO_CONN_TOTAL   1
#define  NVRAM_BYTE_BT_DIALER_AUTO_CONN_SIZE    (sizeof(nvram_bt_cm_dev_struct)) * (__BT_MAX_LINK_NUM__)
#endif

#if defined(__IOT__) 
#define  NVRAM_EF_CONFIG_WIFIAP_MODE_MAX_SSID_LEN       (32 + 1)
#define  NVRAM_EF_CONFIG_WIFIAP_MODE_MAX_PSK_LEN        (63 + 1)
#define  NVRAM_EF_WIFIAP_MODE_CONFIG_SIZE               sizeof(nvram_ef_wifiap_mode_config_struct)
#define  NVRAM_EF_WIFIAP_MODE_CONFIG_TOTAL              1
#endif /* defined(__IOT__) */

/**
 * ADC
 */
// move to mcu\interface\ps\nvram_data_items.h
//#define NVRAM_EF_ADC_SIZE        (ADC_MAX_CHANNEL * 8)
//#define NVRAM_EF_ADC_TOTAL      1

/**
 * Wallpaper and Screensaver file name
 */
#define NVRAM_EF_DISP_CACHE_SET_FILENAME_SIZE     548     /* Cong Zhou, sizeof(mmi_setting_display_cache_file_nvram_struct) */
#define NVRAM_EF_DISP_DIRECT_SET_FILENAME_SIZE 520

#if defined(__MMI_SUB_WALLPAPER__) && defined(__MMI_VUI_LAUNCHER_KEY__)
#define NVRAM_EF_WALLPAPER_FILENAME_TOTAL      3     
#elif defined(__MMI_SUB_WALLPAPER__) || defined(__MMI_VUI_SCREEN_LOCK_KEY__)
#define NVRAM_EF_WALLPAPER_FILENAME_TOTAL      2
#else
#define NVRAM_EF_WALLPAPER_FILENAME_TOTAL      1	/*add screen lock wallpaper*/
#endif

#define NVRAM_EF_SCREENSAVER_FILENAME_SIZE (NVRAM_EF_DISP_CACHE_SET_FILENAME_SIZE)
#define NVRAM_EF_SCREENSAVER_FILENAME_TOTAL 3

#define NVRAM_EF_POWER_ON_OFF_DISP_FILENAME_SIZE (NVRAM_EF_DISP_CACHE_SET_FILENAME_SIZE)
#define NVRAM_EF_POWER_ON_OFF_DISP_FILENAME_TOTAL 2

#define   NVRAM_EF_AUTOTEST_SIZE         40//  250
#define   NVRAM_EF_AUTOTEST_TOTAL        2

#define   NVRAM_EF_QUICKTEST_SIZE         40//  250
#define   NVRAM_EF_QUICKTEST_TOTAL        2

#define   NVRAM_EF_MOTION_SENSOR_SWITCH_TOTAL   1
#define   NVRAM_EF_MOTION_SENSOR_SWITCH_SIZE    1

#ifdef __MMI_STOPWATCH__
    /*
     * Stopwatch
     */
#ifdef __UCS2_ENCODING
#define NVRAM_EF_STOPWATCH_RECORD_SIZE  1152
#else
#define NVRAM_EF_STOPWATCH_RECORD_SIZE  980
#endif
#define NVRAM_EF_STOPWATCH_RECORD_TOTAL   1
#endif /* __MMI_STOPWATCH__ */

#ifdef __MMI_PICTURE_EDITOR_SUPPORT__
#define NVRAM_PICTURE_EDITOR_TOTAL 1
#define NVRAM_PICTURE_EDITOR_SIZE  40*5
#endif /* __MMI_PICTURE_EDITOR_SUPPORT__ */

#ifdef __UCS2_ENCODING
#define NVRAM_EF_THEME_MANAGER_RECORD_SIZE  1840
#else
#define NVRAM_EF_THEME_MANAGER_RECORD_SIZE   580
#endif
#define NVRAM_EF_THEME_MANAGER_RECORD_TOTAL  1

#ifdef __MMI_VRSD__
    /*
     * Voice Recognition - SD
     */
#define NVRAM_EF_VRSD_TAG_SIZE      80
#define NVRAM_EF_VRSD_TAG_TOTAL     1
#endif /* __MMI_VRSD__ */

#ifdef __MMI_VRSI__
    /*
     * Voice Recognition - SI
     */
#define NVRAM_EF_VRSI_TAG_SIZE      120
#define NVRAM_EF_VRSI_TAG_TOTAL     1
#endif /* __MMI_VRSI__ */
    /*
     * Bluetooth
     */
#ifdef __BT_SUPPORT__
#define NVRAM_EF_BT_INFO_SIZE            (sizeof(srv_bt_cm_nvram_struct))

#define NVRAM_EF_BT_SYS_INFO_SIZE        (sizeof(srv_bt_cm_sys_nvram_struct))

#define NVRAM_EF_BT_INFO_TOTAL           (1)

#define NVRAM_EF_BT_DEV_LIST_SIZE        (sizeof(srv_bt_cm_dev_struct_int))

#define NVRAM_EF_BT_DEV_LIST_TOTAL       (SRV_BT_CM_MAX_PAIRED_DEVICE_LIST + SRV_BT_CM_MAX_USED_DEVICE_LIST)

#define NVRAM_EF_BT_DEV_LIST_INDEX_SIZE  (sizeof(srv_bt_cm_nvram_dev_list_index_struct)) // 20 + 20(pad size)
#define NVRAM_EF_BT_DEV_LIST_INDEX_TOTAL (1)
#endif /* __BT_SUPPORT__ */ 

#ifdef __MMI_CM_BLACK_LIST__
    /*
     * Black list
     */
#define NVRAM_EF_BLACK_LIST_SIZE    20*42*2
#define NVRAM_EF_BLACK_LIST_TOTAL      1
#endif /* __MMI_CM_BLACK_LIST__ */

#ifdef __MMI_CM_WHITE_LIST__
    /*
     * White list
     */
#define NVRAM_EF_WHITE_LIST_SIZE    20*42*2
#define NVRAM_EF_WHITE_LIST_TOTAL      1
#endif /* __MMI_CM_WHITE_LIST__ */

#ifdef __MMI_ECOMPASS__
#define NVRAM_EF_ECOMPASS_SIZE       ECOMPASS_GEN_LID_SIZE
#define NVRAM_EF_ECOMPASS_TOTAL      ECOMPASS_GEN_TOTAL_RECORDS
#endif /* __MMI_ECOMPASS__ */

#if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_IMPS__) */

#if defined __MMI_PICT_BRIDGE_SUPPORT__
#define NVRAM_EF_PICTBRIDGE_SIZE    100
#define NVRAM_EF_PICTBRIDGE_TOTAL      1
#endif /* __MMI_PICT_BRIDGE_SUPPORT__ */


    /*
     * Schedule FM Radio Settings
     */
#ifdef __MMI_FM_RADIO_SCHEDULE_REC__
#define NVRAM_EF_FMSR_SETTING_SIZE     300
#define NVRAM_EF_FMSR_SETTING_TOTAL    4
#endif /* __MMI_FM_RADIO_SCHEDULE_REC__ */
    /*
     * Motion App
     */
#ifdef __MMI_MOTION_APP__
#define NVRAM_EF_MOTION_DICE_SIZE   636
#define NVRAM_EF_MOTION_DICE_TOTAL  10

#define NVRAM_EF_MOTION_DJ_SIZE     16
#define NVRAM_EF_MOTION_DJ_TOTAL    6
#endif /* __MMI_MOTION_APP__ */

/* Profile Srv*/
#if !defined(__MMI_BASIC_UI_STYLE__) && !defined(__MMI_PROF_ADD_DEL_PROF_SUPPORT__)
#define NVRAM_MMI_PROF_RECORD_SIZE     sizeof(nvram_mmi_prof_setting_struct)
#define NVRAM_MMI_PROF_RECORD_TOTAL    1
#endif

/*NEW ADD PROFILE*/
#ifdef __MMI_PROF_ADD_DEL_PROF_SUPPORT__
#define NVRAM_MMI_PROF_NEW_RECORD_SIZE     sizeof(nvram_mmi_prof_new_name_struct)
#define NVRAM_MMI_PROF_NEW_RECORD_TOTAL    1

/*NEW FLAG*/
#define NVRAM_MMI_PROF_FLAG_RECORD_SIZE     sizeof(nvram_mmi_prof_new_flag_struct)
#define NVRAM_MMI_PROF_FLAG_RECORD_TOTAL    1
#endif

/**
 * Calling Background Sound Effect
 */
#ifdef __MMI_BG_SOUND_EFFECT__
#define NVRAM_EF_BGSND_SETTING_SIZE       20
#define NVRAM_EF_BGSND_SETTING_TOTAL      1

#define NVRAM_EF_BGSND_FILEPATH_SIZE      520
#define NVRAM_EF_BGSND_FILEPATH_TOTAL     10    /* Shall same as "BGSND_MAX_EXT_EFFECT" in "BGSoundType.h" */
#endif /* __MMI_BG_SOUND_EFFECT__ */

    /* OBIGOQO5 */
#ifndef __MMI_SLIM_MMS_2__
#define NVRAM_UMMS_COMPOSE_SETTINGS_SIZE		1844
#else
#define NVRAM_UMMS_COMPOSE_SETTINGS_SIZE		272
#endif
#define NVRAM_UMMS_COMPOSE_SETTINGS_RECORDS     1
#define NVRAM_UMMS_SENDING_SETTINGS_SIZE        20
#define NVRAM_UMMS_SENDING_SETTINGS_RECORDS     1


#if defined(OBIGO_Q03C_MMS_V01)

#define NVRAM_MMSV01_COMPOSE_SETTINGS_SIZE		264
#define NVRAM_MMSV01_COMPOSE_SETTINGS_RECORDS     1
#define NVRAM_MMSV01_SENDING_SETTINGS_SIZE        8
#define NVRAM_MMSV01_SENDING_SETTINGS_RECORDS     1
#endif

#ifdef WAP_SUPPORT
#ifdef __MMI_WAP_PUSH_WHITE_LIST__
#define NVRAM_EF_PUSH_WHITE_LIST_SIZE      (sizeof(nvram_push_addr_struct) * NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD)
#define NVRAM_EF_PUSH_WHITE_LIST_TOTAL     ((NVRAM_PUSH_MAX_NUM_WHITE_LIST/(NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD + 1)) + 1)
#endif /* __MMI_WAP_PUSH_WHITE_LIST__ */

#define NVRAM_EF_PUSH_GEN_SETTING_SIZE     sizeof(nvram_push_general_setting_struct)
#define NVRAM_EF_PUSH_GEN_SETTING_TOTAL    1

#ifdef __MMI_WAP_PUSH_BLACK_LIST__
#define NVRAM_EF_PUSH_BLACK_LIST_SIZE      (sizeof(nvram_push_addr_struct) * NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD)
#define NVRAM_EF_PUSH_BLACK_LIST_TOTAL     ((NVRAM_PUSH_MAX_NUM_BLACK_LIST/(NVRAM_PUSH_MAX_ENTRY_IN_ONE_RECORD + 1)) + 1)
#endif /* __MMI_WAP_PUSH_BLACK_LIST__ */

#endif /* WAP_SUPPORT */

#ifdef __MMI_BROWSER_2__
#define TITLES_PER_RECORD  20
#define URLS_PER_RECORD    7
#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
#define NVRAM_EF_BRW_ADDRESS_HISTORY_RECORD_TITLE_SIZE      (42 * TITLES_PER_RECORD)
#define NVRAM_EF_BRW_ADDRESS_HISTORY_RECORD_URL_SIZE     (256 * URLS_PER_RECORD)
#define NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_RECORDS       ((CUSTOM_WAP_CFG_N_NBR_HISTORY%TITLES_PER_RECORD) ? ((CUSTOM_WAP_CFG_N_NBR_HISTORY/TITLES_PER_RECORD) +1) : (CUSTOM_WAP_CFG_N_NBR_HISTORY/TITLES_PER_RECORD))
#define NVRAM_EF_BRW_ADDRESS_HISTORY_URL_RECORDS         ((CUSTOM_WAP_CFG_N_NBR_HISTORY%URLS_PER_RECORD) ? ((CUSTOM_WAP_CFG_N_NBR_HISTORY/URLS_PER_RECORD) +1) : (CUSTOM_WAP_CFG_N_NBR_HISTORY/URLS_PER_RECORD))
#endif /* #ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__ */
#define	NVRAM_EF_BRW_LAST_WEB_ADDR_SIZE		1024
#define	NVRAM_EF_BRW_LAST_WEB_ADDR_RECORDS	1
#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
#define	NVRAM_EF_BRW_USER_DEFINED_HOMEPAGE_SIZE		512
#define	NVRAM_EF_BRW_USER_DEFINED_HOMEPAGE_RECORDS	1
#endif

#ifdef __MMI_Q05A_LAUNCH_SCREEN__
#define SHORTCUT_ENTERIES_PER_RECORD        ((2*1024)/ sizeof(nvram_brw_shortcuts_item_struct))
#define NVRAM_EF_BRW_SHORTCUTS_LIST_SIZE      (sizeof(nvram_brw_shortcuts_item_struct) * SHORTCUT_ENTERIES_PER_RECORD)
#define NVRAM_EF_BRW_SHORTCUTS_LIST_RECORDS       ((CUSTOM_WAP_CFG_N_NBR_SHORTCUTS/SHORTCUT_ENTERIES_PER_RECORD) ? ((CUSTOM_WAP_CFG_N_NBR_SHORTCUTS/SHORTCUT_ENTERIES_PER_RECORD) +1) : (CUSTOM_WAP_CFG_N_NBR_SHORTCUTS/SHORTCUT_ENTERIES_PER_RECORD))
#endif

#ifndef WAP_SUPPORT
/*for Browser profile*/
#define NVRAM_EF_WAP_PROFILE_CONTENT_SIZE		sizeof(nvram_profile_content_struct)
#define NVRAM_EF_WAP_PROFILE_CONTENT_TOTAL	10
#define NVRAM_EF_WAP_PROFILE_NAMES_SIZE		sizeof(nvram_profile_name_array_struct)
#define NVRAM_EF_WAP_PROFILE_NAMES_TOTAL		1

/*for MMS profile*/
#define NVRAM_EF_MMS_PROFILE_CONTENT_SIZE		sizeof(nvram_profile_content_struct)
#define NVRAM_EF_MMS_PROFILE_CONTENT_TOTAL	10
#define NVRAM_EF_MMS_PROFILE_NAMES_SIZE		sizeof(nvram_profile_name_array_struct)
#define NVRAM_EF_MMS_PROFILE_NAMES_TOTAL		1
#endif /* WAP_SUPPORT */

#endif /* __MMI_BROWSER_2__ */

#ifdef __MMI_BROWSER_2__

#define NVRAM_EF_WAP_BOOKMARK_LIST_SIZE	           (sizeof(nvram_wap_bookmark_struct) * NVRAM_WAP_BOOKMARK_MAX_ENTRY_IN_ONE_RECORD)
#define NVRAM_EF_WAP_BOOKMARK_LIST_TOTAL_RECORDS   ((NVRAM_WAP_BOOKMARK_MAX_NUM_BOOKMARKS/(NVRAM_WAP_BOOKMARK_MAX_ENTRY_IN_ONE_RECORD + 1)) + 1)

#endif /* __MMI_BROWSER_2__ */

#ifdef __MMI_FM_RADIO_SCHEDULER__
#define NVRAM_EF_FMRDO_SCHEDULER_SIZE  250
#define NVRAM_EF_FMRDO_SCHEDULER_TOTAL  1
#endif /* __MMI_FM_RADIO_SCHEDULER__ */

#ifdef __MMI_EBOOK_READER__
#define NVRAM_EF_EBOOK_SETTING_SIZE    5
#define NVRAM_EF_EBOOK_SETTING_TOTAL   1
#endif

#ifdef __SYNCML_SUPPORT__
/*
 * 	byte 0: profile,
 *	byte 1: applications,
 * 	byte 2: regularity,
 *	byte 3: power on snyc,
 *	byte 4: type,
 *	byte 5: sas,
 *	byte 6: report,
 *	byte 7- last anchors
 */
#define NVRAM_EF_SYNCML_APP_NUM 6

#define NVRAM_EF_SYNCML_VIEW_LOG_SIZE    sizeof(nvram_ef_syncml_view_log_struct)
#define NVRAM_EF_SYNCML_VIEW_LOG_TOTAL   (MAX_SYNCML_SV_PROFILES)

#ifdef __MMI_SYNCML_DEVICE_SYNC__
/* Device Sync */
#define NVRAM_EF_SYNCML_DEV_SETTING_TOTAL    1
#define NVRAM_EF_SYNCML_DEV_SETTING_SIZE     sizeof(nvram_ef_syncml_device_setting_struct)

#define NVRAM_EF_SYNCML_DEV_ACCOUNT_TOTAL    MAX_SYNCML_DEV_NUM
#define NVRAM_EF_SYNCML_DEV_ACCOUNT_SIZE     sizeof(nvram_ef_syncml_device_account_struct)

#define NVRAM_EF_SYNCML_DEV_SYNC_LOG_TOTAL    MAX_SYNCML_DEV_NUM
#define NVRAM_EF_SYNCML_DEV_SYNC_LOG_SIZE     sizeof(nvram_ef_syncml_view_log_struct)
#endif /* __MMI_SYNCML_DEVICE_SYNC__ */

#define NVRAM_EF_SYNCML_ACCOUNT_SIZE    sizeof(nvram_ef_syncml_account_struct)
#define NVRAM_EF_SYNCML_ACCOUNT_TOTAL   MAX_SYNCML_SV_PROFILES

#endif /* __SYNCML_SUPPORT__ */


#define NVRAM_EF_VOIP_PROF_SIZE			568
#define NVRAM_EF_VOIP_PROF_TOTAL		10

#define NVRAM_EF_VOIP_SETTING_SIZE      142
#define NVRAM_EF_VOIP_SETTING_TOTAL     1
#define NVRAM_MAX_DTCNT_SIM_ID_SIZE          28
#define NVRAM_MAX_DTCNT_SIM_ID_TOTAL                1

#ifdef __WIFI_SUPPORT__
#ifdef __WAPI_SUPPORT__
#define NVRAM_MAX_WLAN_SETTING_SIZE			12
#else /* !__WAPI_SUPPORT__ */
#define NVRAM_MAX_WLAN_SETTING_SIZE			12
#endif /* __WAPI_SUPPORT__ */
#define NVRAM_MAX_WLAN_SETTING_TOTAL		1

#ifdef __WAPI_SUPPORT__
#define NVRAM_MAX_WLAN_PROFILE_SIZE			(792 + 80)
#else /* !__WAPI_SUPPORT__ */
#define NVRAM_MAX_WLAN_PROFILE_SIZE			(792)
#endif /* __CERTMAN_SUPPORT__ */

#ifdef __WAPI_SUPPORT__
#define NVRAM_MAX_WLAN_PROFILE_TOTAL		31
#else
#ifdef __WIFI_SLIM__
#define NVRAM_MAX_WLAN_PROFILE_TOTAL		10
#else
#define NVRAM_MAX_WLAN_PROFILE_TOTAL		30
#endif
#endif

#endif /* __WIFI_SUPPORT__*/

#ifdef __CLOUD_SUPPORT__
#ifdef __SMS_CLOUD_SUPPORT__
#define NVRAM_MAX_SMS_USED_NUM_TOTAL       1
#define NVRAM_MAX_SMS_USED_NUM_SIZE        4
#define NVRAM_MAX_SMS_UID_COUNT_TOTAL      1
#define NVRAM_MAX_SMS_UID_COUNT_SIZE       4
#define NVRAM_MAX_CLOUD_SMS_ITEM_TOTAL     SMS_PHONE_ENTRY
#define NVRAM_MAX_CLOUD_SMS_ITEM_SIZE      76
#endif

#ifdef __VCARD_CLOUD_SUPPORT__
#define NVRAM_MAX_VCRD_USED_NUM_TOTAL      1
#define NVRAM_MAX_VCRD_USED_NUM_SIZE       4     
#define NVRAM_MAX_VCRD_UID_COUNT_TOTAL     1
#define NVRAM_MAX_VCRD_UID_COUNT_SIZE      4
#define NVRAM_MAX_CLOUD_VCRD_ITEM_TOTAL    MAX_PHB_PHONE_ENTRY
#define NVRAM_MAX_CLOUD_VCRD_ITEM_SIZE    76
 
#define NVRAM_MAX_VCRD_UID_LIST_URL_SIZE    450
#define NVRAM_MAX_VCRD_UID_LIST_URL_TOTAL   1
#define NVRAM_MAX_VCRD_IS_CHANGE_SIZE       4
#define NVRAM_MAX_VCRD_IS_CHANGE_TOTAL      1
#endif 
#endif 

#ifdef __OCSP_SUPPORT__
#define NVRAM_EF_CERTMAN_OCSP_URL_SIZE    512
#define NVRAM_EF_CERTMAN_OCSP_URL_TOTAL    1
#define NVRAM_EF_CERTMAN_OCSP_URL_LID_VERNO   "000"
#endif /* __OCSP_SUPPORT__ */

//#if defined(__MODEM_EM_MODE__) || defined(__SLIM_MODEM_EM_MODE__)
#if defined(__MMI_ENGINEER_MODE__)
/* Max no of event: 100, store ring_id (2 bytes) for each event */
#define NVRAM_EF_EM_NW_EVENT_RINGS_SIZE     sizeof(nvram_ef_em_nw_event_setting_struct)
#define NVRAM_EF_EM_NW_EVENT_RINGS_TOTAL    1
#endif /* defined(__EM_MODE__) && defined(__MMI_ENGINEER_MODE__) */
//#endif   //mtk02514_em

#if defined(__MMI_FWU_VIA_TFTP__)
#define NVRAM_EF_DM_FWU_TFTP_SETTING_SIZE     sizeof(nvram_ef_dm_fwu_tftp_setting_struct)
#define NVRAM_EF_DM_FWU_TFTP_SETTING_TOTAL    1
#endif /* #if defined(__MMI_FWU_VIA_TFTP__) */

#if defined(__MMI_FWU_VIA_HTTP__)
#define NVRAM_EF_DM_FWU_HTTP_SETTING_SIZE     sizeof(nvram_ef_dm_fwu_http_setting_struct)
#define NVRAM_EF_DM_FWU_HTTP_SETTING_TOTAL    1
#endif /* #if defined(__MMI_FWU_VIA_HTTP__) */



#ifdef __MMI_VIDEO_STREAM__
/**
 * Video Streaming URL
 */
#ifdef __MTK_INTERNAL__
/* under construction !*/
#else
#define NVRAM_EF_VIDEO_PREDEFINED_URL_COUNT   (1)  /* (1)YouTube (sync with nvram_common_config.c */
#endif
#define NVRAM_EF_VIDEO_PREDEFINED_URL_SIZE    (sizeof(nvram_ef_video_predefined_url_struct) * NVRAM_EF_VIDEO_PREDEFINED_URL_COUNT)
#define NVRAM_EF_VIDEO_PREDEFINED_URL_TOTAL   (1)

#define NVRAM_EF_VIDEO_HISTORY_URL_SIZE       (sizeof(nvram_ef_video_history_url_struct))
#define NVRAM_EF_VIDEO_HISTORY_URL_TOTAL      (5)

#define NVRAM_EF_VIDEO_NETWORK_PROFILE_SIZE   (sizeof(nvram_ef_video_network_profile_struct))
#define NVRAM_EF_VIDEO_NETWORK_PROFILE_TOTAL  (5)
#endif /* __MMI_VIDEO_STREAM__ */

/**
* DM Self-Register Number
*/
#ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
#define NVRAM_EF_DM_SR_NUMBER_SIZE         	22
#define NVRAM_EF_DM_SR_NUMBER_TOTAL        	1
#endif /* __MMI_DM_SELF_REGISTER_SUPPORT__ */

#ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
#define NVRAM_EF_DM_SR_IMSI_SIZE         	17
#define NVRAM_EF_DM_SR_IMSI_TOTAL        	1
#endif /* __MMI_DM_SELF_REGISTER_SUPPORT__ */



#ifdef __MMI_SLIDESHOW__
/**
 * SLIDESHOW Settings
 */
#define NVRAM_EF_SLIDE_SHOW_SETTING_TOTAL        1
#define NVRAM_EF_SLIDE_SHOW_SETTING_SIZE         64

#define NVRAM_EF_SLIDE_SHOW_PATH_TOTAL        1
#define NVRAM_EF_SLIDE_SHOW_PATH_SIZE         520

#define NVRAM_EF_SLIDE_SHOW_AUDIO_TOTAL        1
#define NVRAM_EF_SLIDE_SHOW_AUDIO_SIZE         520

#endif /* __MMI_SLIDESHOW__ */

#ifdef __MMI_VIDEO_TELEPHONY__
/**
 * MMI VT setting
 */
#define NVRAM_EF_VT_SETTING_TOTAL       1
#define NVRAM_EF_VT_SETTING_SIZE        520
#endif /* __MMI_VIDEO_TELEPHONY__ */

/*
 * BT_BIP
 */
#ifdef __BIP_PULL_SUPPORT__
#define NVRAM_EF_BT_BIP_SETTING_SIZE  520
#define NVRAM_EF_BT_BIP_SETTING_TOTAL 1
#endif



#ifdef __MMI_MEDIA_PLAYER__
/*
 * Media player
 */
#define NVRAM_EF_MEDPLY_SETTINGS_SIZE   (533+1 + 2 + 1 +2 + 4)
#define NVRAM_EF_MEDPLY_SETTINGS_TOTAL  (1)

#if defined(__MMI_MEDIA_PLAYER_STREAM__) || defined (__MMI_KURO_SUPPORT__)
#define NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_SIZE    (sizeof(nvram_ef_medply_settings_profile_struct))
#define NVRAM_EF_MEDPLY_SETTINGS_NETWORK_PROFILE_TOTAL   (5)
#endif

#ifdef  __MMI_MEDIA_PLAYER_STREAM__
#ifdef __MTK_INTERNAL__
/* under construction !*/
#else
#define NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_COUNT   (1)  /* (1)YouTube (sync with nvram_common_config.c */
#endif
#define NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_SIZE    (sizeof(nvram_ef_medply_video_predefined_url_struct) * NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_COUNT)
#define NVRAM_EF_MEDPLY_VIDEO_PREDEFINED_URL_TOTAL   (1)
#endif

#ifdef __MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__
#define NVRAM_EF_MEDPLY_HISTORY_URL_SIZE       			(sizeof(nvram_ef_medply_history_url_struct))
#define NVRAM_EF_MEDPLY_HISTORY_URL_TOTAL      			(20)
#endif

#define NVRAM_EF_MEDPLY_LIST_PLAYLIST_PATH_SIZE  520
#define NVRAM_EF_MEDPLY_LIST_PLAYLIST_PATH_TOTAL 1
#endif /* __MMI_MEDIA_PLAYER__ */

/*
 * DCD Setting profile
 */
#if (defined __MMI_OP01_DCD__)
#define NVRAM_EF_DCD_SETTING_DATA_SIZE  6
#define NVRAM_EF_DCD_SETTING_DATA_TOTAL 1
#elif (defined __MMI_OP01_DCD_V30__)
#define NVRAM_EF_DCD_SETTING_DATA_SIZE  5
#define NVRAM_EF_DCD_SETTING_DATA_TOTAL 1
#endif

#ifdef __MMI_EM_MISC_DCD__
#define NVRAM_EF_DCD_EM_PARAM_DATA_SIZE  321
#define NVRAM_EF_DCD_EM_PARAM_DATA_TOTAL 1
#endif /* __MMI_EM_MISC_DCD__ */

#ifdef __MMI_CAMCORDER__
#define NVRAM_EF_CAMCO_APP_INFO_TOTAL 1
#define NVRAM_EF_CAMCO_APP_INFO_SIZE  (sizeof(nvram_ef_camco_app_info_struct))

#define NVRAM_EF_CAMCO_MAIN_SETTING_TOTAL 1
#define NVRAM_EF_CAMCO_MAIN_SETTING_SIZE  (sizeof(nvram_ef_camco_setting_struct))

#define NVRAM_EF_CAMCO_MAIN_SETTING_SCENE_SEL_TOTAL 1
#define NVRAM_EF_CAMCO_MAIN_SETTING_SCENE_SEL_SIZE  (sizeof(nvram_ef_camco_setting_scene_sel_struct))

#ifdef DUAL_CAMERA_SUPPORT
#define NVRAM_EF_CAMCO_SUB_SETTING_TOTAL 1
#define NVRAM_EF_CAMCO_SUB_SETTING_SIZE  (sizeof(nvram_ef_camco_setting_struct))

#define NVRAM_EF_CAMCO_SUB_SETTING_SCENE_SEL_TOTAL 1
#define NVRAM_EF_CAMCO_SUB_SETTING_SCENE_SEL_SIZE  (sizeof(nvram_ef_camco_setting_scene_sel_struct))
#endif /* DUAL_CAMERA_SUPPORT */
#endif /* __MMI_CAMCORDER__ */


#ifdef __MMI_AUDPLY_MULTIPLE_LIST__
#define NVRAM_EF_AUDPLY_LIST_PLAYLIST_PATH_SIZE  520
#define NVRAM_EF_AUDPLY_LIST_PLAYLIST_PATH_TOTAL 1
#endif  /* __MMI_AUDPLY_MULTIPLE_LIST__ */

#ifdef __MMI_AUDPLY_WALK_PLAY__
typedef struct
{
    kal_uint16 stack[5];  //MMI_AUDPLY_WALK_MAX_DEPTH_DIRECTORY * sizeof(mmi_audply_walk_stack_node_struct)
    kal_uint16 current_path[260];  //current play file path
    kal_uint16 stack_index;
} mmi_audply_walk_record_struct;

#define NVRAM_EF_AUDPLY_WALK_LID_VERNO	"000"
#define NVRAM_EF_AUDPLY_WALK_SIZE  sizeof(mmi_audply_walk_record_struct)
#define NVRAM_EF_AUDPLY_WALK_TOTAL 1
#endif  /* __MMI_AUDPLY_WALK_PLAY__ */

/*
 * Idle screen
 */
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP11_HOMESCREEN__ */

#ifdef __MMI_OP12_TOOLBAR__
#define NVRAM_EF_TOOLBAR_CNTX_TOTAL     1
#define NVRAM_EF_TOOLBAR_CNTX_SIZE      6
#endif /* __MMI_OP12_TOOLBAR__ */

#ifdef __MMI_VUI_HOMESCREEN__
#define NVRAM_EF_VENUS_HS_WIDGET_MGR_TOTAL      1
#define NVRAM_EF_VENUS_HS_WIDGET_MGR_SIZE       586

#define NVRAM_EF_VENUS_HS_SHORTCUT_MGR_TOTAL    1
#define NVRAM_EF_VENUS_HS_SHORTCUT_MGR_SIZE     286

#define NVRAM_EF_VENUS_HS_WIDGET_MEMO_CNTX_TOTAL    1
#define NVRAM_EF_VENUS_HS_WIDGET_MEMO_CNTX_SIZE     66

#define NVRAM_EF_VENUS_HS_WIDGET_CLOCK_CNTX_TOTAL    1
#define NVRAM_EF_VENUS_HS_WIDGET_CLOCK_CNTX_SIZE     sizeof(vadp_v2p_hs_clock_struct)
#endif /* __MMI_VUI_HOMESCREEN__ */

#ifdef __MMI_VUI_MAINMENU__
#define NVRAM_EF_VENUS_MM_TOTAL    1
#define NVRAM_EF_VENUS_MM_SIZE     12
#endif /*__MMI_VUI_MAINMENU__*/

#ifdef __MMI_VUI_HOMESCREEN_PHOTO__
#define NVRAM_EF_VENUS_PHOTO_FILEPATH_TOTAL 1
#define NVRAM_EF_VENUS_PHOTO_FILEPATH_SIZE  520
#endif

#ifdef __MMI_IMAGE_VIEWER_EX__
#define NVRAM_EF_IVEX_SETTINGS_SIZE    10
#define NVRAM_EF_IVEX_SETTINGS_TOTAL  1
#endif

/*
 * Bluetooth Auto Prompt
 */
#ifdef __MMI_BT_DEF_SEND_DEVICE__
#define NVRAM_EF_BT_DEFDEVICE_SIZE    (sizeof(nvram_ef_bt_defdev_struct))
#define NVRAM_EF_BT_DEFDEVICE_TOTAL   10
#endif /*__MMI_BT_DEF_SEND_DEVICE__*/

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_OP12_TOOLBAR__)
#define NVRAM_EF_SMS_VOICEMAIL_TIME_TOTAL			2
#define NVRAM_EF_SMS_VOICEMAIL_TIME_SIZE			(sizeof(MYTIME))
#endif /* defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_OP12_TOOLBAR__) */

#if defined (__FLAVOR_VENDOR_SDK__) || defined(__MAUI_SDK_TEST__)
#define NVRAM_EF_VS_SETTING_TOTAL  1
#define NVRAM_EF_VS_SETTING_SIZE   (sizeof(nvram_ef_vs_setting_struct))
#endif


/*
 * Auto Answer Machine Settings
 */
#ifdef __MMI_AUTO_ANSWER_MACHINE__
#define NVRAM_EF_ANSWER_MACHINE_SETTING_SIZE     634
#define NVRAM_EF_ANSWER_MACHINE_SETTING_TOTAL    1
#endif /* __MMI_AUTO_ANSWER_MACHINE__ */


/* Internet Application */
#if defined(__MMI_ENGINEER_MODE__) && !defined(__MMI_EM_INET_APP_SLIM__)
#define NVRAM_EF_INET_MAX_UA_STRING_LEN     (255)
#define NVRAM_EF_INET_MAX_UA_PROFILE_LEN    (255)
#define NVRAM_EF_INET_CUSTPACK_SIZE         sizeof(nvram_em_inet_custpack_struct)
#define NVRAM_EF_INET_CUSTPACK_TOTAL        (1)
#endif

#ifdef __MMI_IPSEC__
/**
 * IPSec Settings MMI profile name
 */
#define NVRAM_EF_IPSEC_PROFILE_NAME_SIZE  sizeof(nvram_ef_ipsec_profile_name_struct)
#define NVRAM_EF_IPSEC_PROFILE_NAME_TOTAL 3
#endif /* __MMI_IPSEC__ */

#ifdef __EMAIL__
/* Email Data Account */
#define NVRAM_EF_EMAIL_DATA_ACCOUNT_SIZE    sizeof(nvram_ef_email_data_account_struct)
#define NVRAM_EF_EMAIL_DATA_ACCOUNT_TOTAL   20
#endif /* __EMAIL__ */

#ifdef __MMI_NOTE_APP__
#define NVRAM_EF_NOTE_LIST_TOTAL			MMI_MAX_NOTE_ITEM
#define NVRAM_EF_NOTE_NODE_STRUCT_SIZE      sizeof(nvram_ef_note_app_node_struct)
#endif /* __MMI_NOTE_APP__ */

#ifdef __MMI_ZAKAT_CALCULATOR__
#define NVRAM_EF_ZAKAT_CALCULATOR_SIZE      sizeof(nvram_zakat_calculator_data_record_struct)
#define NVRAM_EF_ZAKAT_CALCULATOR_TOTAL     27
#endif /* __MMI_ZAKAT_CALCULATOR__ */

#ifdef __MMI_SEARCH_WEB__
#define NVRAM_EF_SEARCH_WEB_HISTORY_LID_VERNO           "000"
#define NVRAM_EF_SEARCH_WEB_HISTORY_VALID_MAGIC_NUMBER  0x642ba1d0
#define NVRAM_EF_SEARCH_WEB_HISTORY_MAX_STRING_LEN      32
#define NVRAM_EF_SEARCH_WEB_HISTORY_MAX_ENTRY_NUM       5
#define NVRAM_EF_SEARCH_WEB_HISTORY_SIZE                sizeof(nvram_ef_search_web_history_struct)
#define NVRAM_EF_SEARCH_WEB_HISTORY_TOTAL               1

#ifdef __MMI_SEARCH_WEB_BAIDU__
#define NVRAM_EF_SEARCH_WEB_BAIDU_UID_LID_VERNO         "000"
#define NVRAM_EF_SEARCH_WEB_BAIDU_UID_MAX_LEN           48
#define NVRAM_EF_SEARCH_WEB_BAIDU_UID_SIZE              sizeof(nvram_ef_search_web_baidu_uid_struct)
#define NVRAM_EF_SEARCH_WEB_BAIDU_UID_TOTAL             1
#endif

#endif
#ifdef __TCPIP__
#if !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI)
#define NVRAM_EF_CNMGR_CONNECT_DATA_LAST_TOTAL_SIZE sizeof(nvram_ef_cnmgr_connect_data_struct)
#define NVRAM_EF_CNMGR_CONNECT_DATA_LAST_TOTAL      (MMI_MAX_SIM_NUM * 4 + 1)
#endif /* !defined(EMPTY_MMI) && !defined(EXTERNAL_MMI) */
#endif /* __TCPIP__ */
#ifdef __MMI_EM_GPRS_CNMGR_SCRI_SUPPORT__
#define NVRAM_EF_CNMGR_SCRI_CHECK_TIME_SIZE     sizeof(nvram_ef_cnmgr_scri_check_time_struct)
#define NVRAM_EF_CNMGR_SCRI_CHECK_TIME_TOTAL    1
#endif
#ifdef __MMI_FM_RADIO__
#define NVRAM_EF_FM_RADIO_CHANNEL   30 /* Better less than 30 channels, or it may exceed the maximum NVRAM record size */
#define NVRAM_EF_FM_RADIO_TOTAL     1
#define NVRAM_EF_FM_RADIO_SIZE      (NVRAM_EF_FM_RADIO_CHANNEL * 26) /* Same as "sizeof(mmi_fmrdo_channel_list_struct) */
#endif /* __MMI_FM_RADIO__ */
#if defined(__CERTMAN_SUPPORT__) 
#define NVRAM_EF_CERTMAN_CHANNEL   1 
#define NVRAM_EF_FM_CERTMAN_TOTAL     1
#define NVRAM_EF_FM_CERTMAN_SIZE      (NVRAM_EF_CERTMAN_CHANNEL * 2) 
#endif /* __CERTMAN_SUPPORT__ */

#ifdef __DM_LAWMO_SUPPORT__
#define NVRAM_EF_DM_APP_LAWMO_INFO_SIZE sizeof(nvram_ef_dm_app_lawmo_info_struct)
#define NVRAM_EF_DM_APP_LAWMO_INFO_TOTAL 1
#endif /* __DM_LAWMO_SUPPORT__ */
#ifdef __DM_SCOMO_SUPPORT__
#define NVRAM_EF_DM_MAX_ID_LEN      32
#define NVRAM_EF_DM_MAX_NAME_LEN    64
#define NVRAM_EF_DM_MAX_URL_LEN 128
#define NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_SIZE sizeof(nvram_ef_dm_app_scomo_report_info_struct)
#define NVRAM_EF_DM_APP_SCOMO_REPORT_INFO_TOTAL 1
#endif /* __DM_SCOMO_SUPPORT__ */


#define NVRAM_EF_SRV_SMS_MAX_ADDR_LEN       21
#ifdef __EMS_NON_STD_7BIT_CHAR__
#define NVRAM_EF_SRV_SMS_MAX_SEG            (((MMI_SMS_MAX_MSG_SEG * 153) + 66) / 67)
#else /* __EMS_NON_STD_7BIT_CHAR__ */
#define NVRAM_EF_SRV_SMS_MAX_SEG            MMI_SMS_MAX_MSG_SEG
#endif /* __EMS_NON_STD_7BIT_CHAR__ */

#define NVRAM_EF_SRV_SMS_REMINDER_LEN       175
#define NVRAM_EF_SRV_SMS_PDU_SIZE           (sizeof(nvram_ef_srv_sms_pdu_struct))
#define NVRAM_EF_SRV_SMS_PDU_TOTAL          (SMS_PHONE_ENTRY)

#ifdef __SRV_SMS_RECENT_EVENT__
#define NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_TOTAL      1
#define NVRAM_EF_SRV_SMS_RECENT_EVENT_BITMAP_SIZE		((SMS_PHONE_ENTRY + SMS_SIM_ENTRY * NVRAM_DUAL_RECORD + 7) / 8)
#endif /* __SRV_SMS_RECENT_EVENT__ */

#ifdef __SRV_SMS_SIM_CUST_DATA__
#define NVRAM_EF_SRV_SMS_SIM_CUST_DATA_TOTAL            1
#define NVRAM_EF_SRV_SMS_CUST_SYS_NUM                   (NVRAM_DUAL_RECORD)
#define NVRAM_EF_SRV_SMS_CUST_PUB_NUM                   4
#define NVRAM_EF_SRV_SMS_CUST_IMSI_LEN                  17
#define NVRAM_EF_SRV_SMS_SIM_CUST_DATA_SIZE		        (sizeof(nvram_ef_srv_sms_sim_cust_data_struct))
#endif /* __SRV_SMS_SIM_CUST_DATA__ */

#ifdef __MMI_VUI_3D_CUBE_APP__
#define NVRAM_EF_CUBE_VIP_CONTS_COUNT   6
#define NVRAM_EF_CUBE_VIP_CONTS_SIZE	16
#define NVRAM_EF_CUBE_VIP_CONTS_TOTAL	1
#endif /* __MMI_VUI_3D_CUBE_APP__ */

#if defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
#define NVRAM_EF_OP11_HS32_HIST_SIZE    (sizeof(nvram_ef_op11_hs32_hist_struct))
#define NVRAM_EF_OP11_HS32_HIST_TOTAL   1
#endif /*defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)*/

#ifdef __MMI_GADGET_SUPPORT__
#define NVRAM_EF_WGTMGR_DATA_SIZE    (2000)
#define NVRAM_EF_WGTMGR_DATA_TOTAL   (1)
#endif
#ifdef __SRV_CBS_SUPPORT__
#define NVRAM_EF_SRV_CBS_PAGE_SIZE              sizeof(nvram_ef_srv_cbs_page_struct)
#define NVRAM_EF_SRV_CBS_PAGE_CONTENT_LEN       94
#define NVRAM_EF_SRV_CBS_PAGE_NUM               (30)
#define NVRAM_EF_SRV_CBS_PAGE_TOTAL             (NVRAM_EF_SRV_CBS_PAGE_NUM * NVRAM_DUAL_RECORD)

#define NVRAM_EF_SRV_CBS_MSG_NODE_SIZE          sizeof(nvram_ef_srv_cbs_msg_node_struct)
#define NVRAM_EF_SRV_CBS_MSG_NODE_NUM           5
#define NVRAM_EF_SRV_CBS_MSG_NODE_TOTAL         (NVRAM_EF_SRV_CBS_MSG_NODE_NUM * NVRAM_DUAL_RECORD)

#define NVRAM_EF_SRV_CBS_CHNL_NAME_SIZE         sizeof(nvram_ef_srv_cbs_chnl_name_struct)
#define NVRAM_EF_SRV_CBS_CHNL_NAME_LEN          10
#define NVRAM_EF_SRV_CBS_CHNL_NAME_NUM          40
#define NVRAM_EF_SRV_CBS_CHNL_NAME_TOTAL        (NVRAM_EF_SRV_CBS_CHNL_NAME_NUM * NVRAM_DUAL_RECORD)
#endif
#ifdef OPERA_BROWSER
#define NVRAM_EF_OPERA_ADP_PROF_SETTING_SIZE    (sizeof(nvram_ef_opera_adp_prof_setting_struct))
#define NVRAM_EF_OPERA_ADP_PROF_SETTING_TOTAL   1
#endif /* OPERA_BROWSER */

#ifdef __BT_HFG_PROFILE__
#define NVRAM_EF_BTHF_CONFIG_SIZE      (sizeof(nvram_ef_bthf_config_struct))
#define NVRAM_EF_BTHF_CONFIG_TOTAL     1
#endif /* __BT_HFG_PROFILE__ */

#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
#define NVRAM_EF_SRV_SMS_STATUS_REPORT_TOTAL        20
#define NVRAM_EF_SRV_SMS_STATUS_REPORT_SIZE         (sizeof(nvram_ef_srv_sms_status_report_struct))
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */

#ifdef __MMI_VUI_SHELL_APP__
#define NVRAM_EF_VENUS_SHELL_PAGE_ORDER_SIZE  16
#define NVRAM_EF_VENUS_SHELL_PAGE_ORDER_TOTAL 1
#endif /* __MMI_VUI_SHELL_APP__ */

#ifdef __MMI_VUI_SHELL_SHORTCUTS__
#define NVRAM_EF_SHELL_SHORTCUTS_SIZE      (sizeof(nvram_ef_shell_shortcuts_item_struct))
#define NVRAM_EF_SHELL_SHORTCUTS_TOTAL     (VAPP_SHELL_SHCT_MAX_ITEM)
#endif /* __MMI_VUI_SHELL_SHORTCUTS__ */

#ifdef __MMI_VUI_SHELL_FAV_CONTACT__
#define NVRAM_EF_SHELL_FC_SIZE      (sizeof(vapp_shell_fc_id_struct))
#define NVRAM_EF_SHELL_FC_TOTAL     (1)
#endif

#ifdef __MMI_VUI_3D_MAINMENU__
#define NVRAM_EF_VENUS_3D_MM_TOTAL    1
#define NVRAM_EF_VENUS_3D_MM_SIZE     70
#endif

#ifdef __MMI_WLAN_FEATURES__
#define NVRAM_MAX_CMCC_WIFI_SETTING_TOTAL 1
#define NVRAM_MAX_CMCC_WIFI_SETTING_SIZE 12
#endif

#ifdef __BT_AUTO_DETECT_SUPPORT__
#define NVRAM_EF_BT_AUTO_DETECT_SETTING_TOTAL	1
#define NVRAM_EF_BT_AUTO_DETECT_SETTING_SIZE     	2
#endif


/* Reminder */
#define REMINDER_Q_TOTAL (NUM_OF_ALM + \
			NUM_OF_CAL + \
			NUM_OF_TASK + \
			NUM_OF_SPOF + \
			NUM_OF_FAC_ALM + \
			NUM_OF_FMSR + \
			NUM_OF_BR + \
			NUM_OF_FMRDO + \
			NUM_OF_SYNCML + \
			NUM_OF_AZAAN + \
			NUM_OF_THM_ALM)

#define NVRAM_EF_SRV_REMINDER_Q_SIZE	(16 * (REMINDER_Q_TOTAL)) /* sizeof(srv_reminder_q_node_type) */
#define NVRAM_EF_SRV_REMINDER_Q_TOTAL	1		 /* Max q size */

#ifdef __SRV_SMS_MULTI_ADDR__
#define NVRAM_EF_SRV_SMS_ADDR_SIZE          (sizeof(nvram_ef_srv_sms_addr_struct))
#define NVRAM_EF_SRV_SMS_ADDR_TOTAL         (SMS_PHONE_ENTRY)
#endif /* __SRV_SMS_MULTI_ADDR__ */

#ifdef __MMI_139_PUSH_MAIL__
#define NVRAM_EF_PUSHMAIL_INFO_SIZE  672 //sizeof(t_EmailSet)
#define NVRAM_EF_PUSHMAIL_INFO_TOTAL (1)
#endif

#ifdef __MMI_TETHERING__
#define NVRAM_EF_SRV_TETHERING_DTCNT_SIZE       sizeof(nvram_ef_srv_tethering_dtcnt_struct)
#ifdef GEMINI_PLUS
#define NVRAM_EF_SRV_TETHERING_DTCNT_TOTAL      GEMINI_PLUS
#elif defined(__GEMINI__)
#define NVRAM_EF_SRV_TETHERING_DTCNT_TOTAL      2
#else
#define NVRAM_EF_SRV_TETHERING_DTCNT_TOTAL      1
#endif


#define NVRAM_EF_SRV_TETHERING_WIFI_HS_SETTINGS_SIZE       sizeof(nvram_ef_srv_tethering_wifi_hs_settings_struct)
#define NVRAM_EF_SRV_TETHERING_WIFI_HS_MAX_SSID_LEN       (32 + 1)
#define NVRAM_EF_SRV_TETHERING_WIFI_HS_MAX_PSK_LEN        (63 + 1)
#define NVRAM_EF_SRV_TETHERING_WIFI_HS_SETTINGS_TOTAL      1
#endif /* __MMI_TETHERING__ */

#ifdef __MMI_OP01_WIFI__
#define NVRAM_MAX_CMCC_WIFI_BLACK_LIST_SIZE   108
#define NVRAM_MAX_CMCC_WIFI_BLACK_LIST_TOTAL  30
#endif

#ifdef __MMI_PUSH_TURN_ON_OFF_SWITCH__
#define NVRAM_EF_PUSH_SWITCH_SETTING_SIZE   sizeof(nvram_ef_push_switch_setting_struct)
#define NVRAM_EF_PUSH_SWITCH_SETTING_TOTAL  1
#endif /* __MMI_PUSH_TURN_ON_OFF_SWITCH__ */

#ifdef __MMI_OP01_WIFI__
#define NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_SIZE   257
#define NVRAM_EF_WLAN_PROXY_EXCLUSIVE_IP_ADDR_TOTAL  10
#endif /* __MMI_OP01_WIFI__ */

#if defined(__MMI_VUI_SHELL_OP01_HOMESCREEN__)||defined(__MMI_VUI_LAUNCHER_KEY__)
#define NVRAM_EF_OP01_HS_SETTING_SIZE    (sizeof(nvram_ef_op01_hs_setting_struct))
#define NVRAM_EF_OP01_HS_SETTING_TOTAL   1
#endif /* __MMI_VUI_SHELL_OP01_HOMESCREEN__ */

#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
#define NVRAM_EF_SYS_LANGUAGE_SSC_SIZE  (10)
#define NVRAM_EF_SYS_LANGUAGE_SSC_TOTAL (1)
#endif //__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__

#ifdef SYNCML_DM_SUPPORT
#define NVRAM_EF_DM_SRV_ACC_SIZE            sizeof(nvram_ef_dm_srv_acc_struct)
#define NVRAM_EF_DM_SRV_ACC_TOTAL           1
#define NVRAM_EF_DM_SRV_ACC_MAX_URI_LEN     128
#define NVRAM_EF_DM_SRV_ACC_MAX_ID_LEN      32
#endif /* SYNCML_DM_SUPPORT */

#ifdef __MMI_VUI_LAUNCHER__
#define NVRAM_EF_VAPP_DRAWER_ORDER_DATA_TOTAL   3
#define NVRAM_EF_VAPP_DRAWER_ORDER_DATA_SIZE    2040
#define NVRAM_EF_VENUS_LAUNCHER_DESKTOP_TOTAL   1
#define NVRAM_EF_VENUS_LAUNCHER_DESKTOP_SIZE    2000
#endif
#ifdef __MMI_VUI_LAUNCHER_KEY__
#ifdef __MMI_MAINLCD_240X400__
#define NVRAM_EF_VAPP_KMM_ORDER_DATA_TOTAL   5
#define NVRAM_EF_VAPP_KMM_ORDER_DATA_SIZE    1260
#elif defined(__MMI_MAINLCD_320X240__)
#define NVRAM_EF_VAPP_KMM_ORDER_DATA_TOTAL   3
#define NVRAM_EF_VAPP_KMM_ORDER_DATA_SIZE    1920
#else
#define NVRAM_EF_VAPP_KMM_ORDER_DATA_TOTAL   3
#define NVRAM_EF_VAPP_KMM_ORDER_DATA_SIZE    2040
#endif

#endif /* __MMI_VUI_LAUNCHER_KEY__ */

#ifdef __MMI_DOWNLOADABLE_APPICON_SUPPORT__
#define NVRAM_EF_DLT_APPICON_TOTAL      1
#define	NVRAM_EF_DLT_APPICON_SIZE       520
#define NVRAM_EF_DLT_APPICON_LID_VERNO "000"
#endif
#ifdef __NFC_SUPPORT__
#define	NVRAM_EF_NFC_STATUS_LID_VERNO		"000"
#define NVRAM_EF_NFC_STATUS_SIZE			1
#define NVRAM_EF_NFC_STATUS_TOTAL			1
#endif

#ifdef __SOCIAL_NETWORK_SUPPORT__
#define NVRAM_EF_SRV_SNS_MAX_LEN_ID      40
#define NVRAM_EF_SRV_SNS_MAX_LEN_KEY     128
#define NVRAM_EF_SRV_SNS_MAX_LEN_NAME    75
#define NVRAM_EF_SRV_SNS_MAX_LEN_PIC_URL 256
#define NVRAM_EF_SRV_SNS_ACCOUNT_SIZE    sizeof(nvram_ef_srv_sns_provider_struct)
#define NVRAM_EF_SRV_SNS_ACCOUNT_TOTAL   8
#endif /* __SOCIAL_NETWORK_SUPPORT__ */

#define NVRAM_EF_SRV_SSO_NAME_SIZE       64
#define NVRAM_EF_SRV_SSO_CREDENTIAL_SIZE 4+512+512+512+256 /* yahoo */
#define NVRAM_EF_SRV_SSO_ACCOUNT_SIZE    sizeof(nvram_ef_srv_sso_account_struct)
#define NVRAM_EF_SRV_SSO_ACCOUNT_TOTAL   8

#ifdef __MMI_VUI_LAUNCHER_KEY__
#define	NVRAM_EF_PHNSET_WIDGET_MGR_SYS_LIST_LID_VERNO		"000"
#define NVRAM_EF_PHNSET_WIDGET_MGR_SYS_LIST_SIZE		sizeof(nvram_ef_phnset_widget_mgr_sys_list_struct)
#define NVRAM_EF_PHNSET_WIDGET_MGR_SYS_LIST_TOTAL		1
#endif

#ifdef __MMI_VUI_LAUNCHER_KEY__
#define NVRAM_EF_PHNSET_SHCUT_APP_LIST_LID_VERNO	"000"
#define NVRAM_EF_PHNSET_SHCUT_APP_LIST_SIZE			sizeof(nvram_ef_phnset_shcut_app_list_struct)
#define NVRAM_EF_PHNSET_SHCUT_APP_LIST_TOTAL		1
#endif
#ifdef __MMI_DYNAMIC_SIM_DYNAMIC_UI__
#define	NVRAM_EF_NETSET_SIM_NAME_LID_VERNO		"000"
#define NVRAM_EF_NETSET_SIM_NAME_SIZE			sizeof(nvram_ef_netset_sim_name_struct)
#define NVRAM_EF_NETSET_SIM_NAME_TOTAL			4
#endif

#ifdef __MMI_VUI_SCREEN_LOCK_KEY__
#define	NVRAM_EF_SCREEN_LOCK_KEY_IMG_SETTING_LID_VERNO		"000"
#define NVRAM_EF_SCREEN_LOCK_KEY_IMG_SETTING_SIZE		    sizeof(nvram_ef_screen_lock_key_img_setting_struct)
#define NVRAM_EF_SCREEN_LOCK_KEY_IMG_SETTING_TOTAL		    1
#endif

#ifdef __MMI_NSS_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__
    #ifdef __LOW_COST_SUPPORT_COMMON__
        #define NVRAM_EF_SRV_NSS_PROFILE_TOTAL         32
    #else
        #define NVRAM_EF_SRV_NSS_PROFILE_TOTAL         100
    #endif/*__LOW_COST_SUPPORT_COMMON__*/
#else
    #define NVRAM_EF_SRV_NSS_PROFILE_TOTAL         32
#endif/*__COSMOS_MMI_PACKAGE__*/
#define NVRAM_EF_SRV_NSS_PROFILE_SIZE             sizeof(nvram_ef_srv_nss_struct)
#endif

#ifdef __MMI_MRE_MSPACE__
#define	NVRAM_EF_SRV_MSPACE_LID_VERNO		"000"
#define NVRAM_EF_SRV_MSPACE_SIZE		    520
#define NVRAM_EF_SRV_MSPACE_TOTAL		    2
#endif

/* ADD-S  20120417 FOR CMMBCAS2GPP*/	
#ifdef CMMB_CAS_2GPP_V10	
#define	NVRAM_EF_CMMB_CAS_2GPP_LID_VERNO		"000"
#define    NVRAM_EF_CMMB_CAS_2GPP_TOTAL       1
#define    NVRAM_EF_CMMB_CAS_2GPP_SIZE       64
#endif
/* ADD-E  20120417 FOR CMMBCAS2GPP*/

#ifdef __MMI_APPLIST_BARREL_SUPPORT__
#define NVRAM_EF_APPLIST_BARREL_EFFECT_TOTAL            1
#define NVRAM_EF_APPLIST_BARREL_EFFECT_SIZE             1
#define NVRAM_EF_APPLIST_BARREL_EFFECT_LID_VERNO       "000"
#endif

#if defined(__WIFI_SUPPORT__) && defined(__IOT__)
#define NVRAM_MAX_WLAN_SCAN_SETTING_TOTAL	        1
#define NVRAM_MAX_WLAN_SCAN_SETTING_SIZE            sizeof(nvram_ef_srv_dtcnt_wlan_scan_setting_struct)
#define NVRAM_EF_WLAN_SCAN_SETTING_LID_VERNO        "000"
#endif

#if defined(__MMI_FRM_INPUT_EVT__)

//huking

//led
#define NVRAM_EF_LED_INFO_TOTAL INPUT_EVENT_LED_ID_END
#define NVRAM_EF_LED_INFO_SIZE sizeof(nvram_input_event_led_notify)
#define NVRAM_EF_LED_INFO_LID_VERNO "000"

//vib
#define NVRAM_EF_VIB_INFO_TOTAL INPUT_EVENT_VIB_IND_END
#define NVRAM_EF_VIB_INFO_SIZE sizeof(nvram_input_event_vib_notify)
#define NVRAM_EF_VIB_INFO_LID_VERNO "000"

//aud
#define NVRAM_EF_AUD_INFO_TOTAL INPUT_EVENT_MAX_AUD
#define NVRAM_EF_AUD_INFO_SIZE sizeof(nvram_input_event_aud_notify)
#define NVRAM_EF_AUD_INFO_LID_VERNO "000"

//notify
#define NVRAM_EF_NOTIFY_INFO_TOTAL INPUT_EVENT_MAX_NOTIFY
#define NVRAM_EF_NOTIFY_INFO_SIZE sizeof(nvram_input_event_notify_info)
#define NVRAM_EF_NOTIFY_INFO_LID_VERNO "000"

//input event
#define NVRAM_EF_INPUT_EVENT_INFO_TOTAL INPUT_EVENT_MAX_EVT
#define NVRAM_EF_INPUT_EVENT_INFO_SIZE sizeof(nvram_input_event_evt_info)
#define NVRAM_EF_INPUT_EVENT_INFO_LID_VERNO "000"

//local app info
#define NVRAM_EF_LOCAL_APP_INFO_TOTAL   INPUT_EVENT_TOTAL_LOCAL_APP
#define NVRAM_EF_LOCAL_APP_INFO_SIZE    sizeof(nvram_input_event_local_app_info)
#define NVRAM_EF_LOCAL_APP_INFO_LID_VERNO  "000"
#endif/*#if defined(__MMI_FRM_INPUT_EVT__)*/

#ifndef __MMI_TELEPHONY_SUPPORT__

#define NVRAM_EF_PHONE_LOCK_TOTAL            1
#define NVRAM_EF_PHONE_LOCK_SIZE             sizeof(nvram_ef_phone_lock_struct)
#define NVRAM_EF_PHONE_LOCK_LID_VERNO       "000"

#endif /* __MMI_TELEPHONY_SUPPORT__ */

#ifdef __cplusplus
}
#endif

#endif /* NVRAM_NOT_PRESENT */
#endif /* NVRAM_COMMON_DEFS_H */

