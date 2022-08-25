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
 *  PopulateRes.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Populate Resource Engine
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define _POPULATE_RES_C

 /****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_features.h"
#include "GlobalMenuItems.h"
#include "ResCompressConfig.h"
#include "custdatares.h"
#include "CustDataProts.h"
#include "custmenures.h"
#include "FontDCL.h"

#if defined(__FOTA_ENABLE__) || defined(__CARD_DOWNLOAD__) || defined(__ZIMAGE_SUPPORT__) || defined(__FAST_LOGO__)
#include "lcd_sw_rnd.h"
#include "ABMLoader.h"
#include "gui_resource_type.h"
#endif /* defined(__FOTA_ENABLE__) || defined(__CARD_DOWNLOAD__) || defined(__ZIMAGE_SUPPORT__) || defined(__FAST_LOGO__) */

    #include "MMIDataType.h"
    #include "mmi_res_range_def.h"
    #include "GlobalResDef.h"
    
#ifdef DEVELOPER_BUILD_FIRST_PASS
/***************************************************************************** 
*
* FIRST_PASS is for Resgen on PC
*
*****************************************************************************/
#include "CustResDef.h"
#include "SettingDefs.h"
#include "WriteResUtil.h"
#include "LegacyResPopService.h"
#include "ResgenLogCAPI.h"
#include "ExternalCMDManagerCAPI.h"
#ifdef __CAT_SUPPORT__
    #include "ResgenCatUtilCAPI.h"
#endif //__CAT_SUPPORT__

/***************************************************************************** 
* Define
*****************************************************************************/
#define  OUTPUT_IMAGE_ID_FILENAME      CUST_IMG_PATH_ROOT"\\\\images_file_list.ini"
/* 101205 audio resource Calvin Satrt */
#define  OUTPUT_AUDIO_ID_FILENAME      CUST_ADO_PATH"\\\\audio_file_list.ini"
/* 101205 audio resource Calvin End */
#define  OUTPUT_BINARY_ID_FILENAME      CUST_BINARY_PATH"\\\\binary_file_list.ini"
#define  OUTPUT_MENUTREE_ID_FILENAME   "..\\..\\Customer\\CustResource\\CustMenuTreeID_Out.c"

#define OUTPUT_DATA_FILENAME        "..\\..\\Customer\\CustResource\\CustImgDataHW.h"
#define OUTPUT_DATA_FILENAME_EXT    "..\\..\\Customer\\CustResource\\CustImgDataHWExt.h"
#define AUDIO_OUTPUT_DATA_FILENAME      "..\\..\\Customer\\CustResource\\CustAdoDataHW.h"
#define AUDIO_OUTPUT_DATA_FILENAME_EXT  "..\\..\\Customer\\CustResource\\CustAdoDataHWExt.h"
#define FONT_OUTPUT_DATA_FILENAME		"..\\..\\Customer\\CustResource\\CustFontDataHW.h"


#define RESPOP_TAG "POPULATERES"

#define RESPOP_LOG_D(format, args...) RES_LOG_D((RESPOP_TAG), (format) , ##args)
#define RESPOP_LOG_V(format, args...) RES_LOG_V((RESPOP_TAG), (format) , ##args)
#define RESPOP_LOG_W(format, args...) RES_LOG_W((RESPOP_TAG), (format) , ##args)
#define RESPOP_LOG_E(format, args...) RES_LOG_E((RESPOP_TAG), (format) , ##args)

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
#define ENFB_IMAGE_DATA_FILENAME    "..\\..\\Customer\\CustResource\\CustENFBImgData"  //100206 ENFB support
#endif

#ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
#define ENFB_FONT_DATA_FILENAME    "..\\..\\Customer\\CustResource\\CustENFBFontData"
#endif
/***************************************************************************** 
* Local Variable
*****************************************************************************/
/* for generate String list file in first pass */
FILE *StringListFile = NULL;
FILE *OutputImgIDFile = NULL;

/* 101205 audio resource Calvin Satrt */
FILE *OutputAdoIDFile = NULL;

FILE *OutputBinaryIDFile = NULL;

/* 101205 audio resource Calvin End */
FILE *OutputMenutreeIDFile = NULL;
FILE *RepeatIDListFile = NULL;  /* 102604 Calvin added */
U16 gCurrLangIndex;

#if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE)
FILE *fpMenuResourceUsage = NULL;
FILE *fpImageResourceUsage = NULL;
FILE *fpImageResourceUsageExt = NULL;
FILE *fpAudioResourceUsage = NULL;
FILE *fpStringResourceUsage = NULL;

FILE *font_data_file = NULL;
FILE *font_data_lis = NULL;
FILE *font_data_modis_lis = NULL;
FILE *font_ttf_lis = NULL;

#define MYFOPEN(fp, filename, type) \
do                                  \
{                                   \
    fp = fopen(filename, type);     \
    if (fp == NULL)                 \
    {                               \
        fprintf(stderr, "%s cannot open\n", filename);  \
    }                               \
} while (0)

#define MYFCLOSE(fp, filename)  \
    do                          \
    {                           \
        if (fp != NULL)         \
        {                       \
            fprintf(stderr, "output %s done.\n", filename); \
            fclose(fp);         \
        }                       \
    } while (0)

#define PRTRESTITLE(fp)     \
    do                      \
    {                       \
        if (fp != NULL)     \
        {                   \
            fprintf(fp, "APP_name\tRes_base\tID\tID_name\tsize\tdata\tres_filename\n"); \
        }                   \
    } while (0)
#endif /* #if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE) */

U16 CurrMaxStringNum;
U32 CurrTotalStrLen;
U16 CurrMaxStringId = 0;
U16 CurrMaxStringIdSearch;


U8 mmi_res_zip_language[MAX_LANGUAGES+1];

/***************************************************************************** 
* Local Function
*****************************************************************************/
void PopulateGlobalData(void);
#ifdef __FOTA_ENABLE__
static void PopulateFOTAData(void);
#endif /* __FOTA_ENABLE__ */
#ifdef  __MMI_WEBCAM__
static void PopulateWebcamData(void);
#endif /*  __MMI_WEBCAM__ */

static void PopulateBootupLogoData(void);

static void PopulateBinary3DData();

#ifdef __RESGEN_INTERNAL_3D_META_RESGEN_AUTO__
static void PopulateImage3DData();
#endif //__RESGEN_INTERNAL_3D_META_RESGEN_AUTO__



/****************************************************************************
* Global Variable - Extern                                                                 
*****************************************************************************/
extern U16 CurrMaxImageId;
extern U16 CurrMaxImageNum;
extern U16 CurrMaxImageIdEXT;   /* 040805 CustPack: Calvin added */
extern U16 CurrMaxImageNumEXT;  /* 040805 CustPack: Calvin added */

extern U16 CurrMaxFontIdEXT;   /* LangPack */
extern U16 CurrMaxFontNumEXT;  /* LangPack */

/* 101205 audio resource Calvin Satrt */
extern U16 CurrMaxAudioId;
extern U16 CurrMaxAudioNum;
extern U16 CurrMaxAudioIdEXT;
extern U16 CurrMaxAudioNumEXT;

/* 101205 audio resource Calvin End */

extern U16 CurrMaxMenuItemIndex;    /* Max menu IDs */
extern U16 CurrMaxStringId;
#ifndef __POPULATE_ENGINE_
extern HWND hWnd;
#endif

/* 101806 E-NFB start */
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
extern U16 CurrMaxENFBAssociatedIDNum;
#endif
/* 101806 E-NFB end */

extern CUSTOM_IMAGE_MAP ImageIdMap[];
extern CUSTOM_IMAGE_MAP ImageIdMapEXT[];
extern CUSTOM_AUDIO_MAP AudioIdMap[];
extern CUSTOM_AUDIO_MAP AudioIdMapEXT[];
extern CUSTOM_FONT_MAP FontIdMap[];
extern CUSTOM_FONT_MAP FontIdMapEXT[];
extern CUSTOM_MENU nCustMenus[];

/* Menuitem reduce memory, move registe hilite handlers to resgen */
extern RESGEN_MENU_HILITE_HANDLER   nMenuHiliteHandlers[];
extern RESGEN_MENU_HINT_HANDLER     nMenuHintHandlers[];

const CUSTOM_STRING *gpStringRes;
const CUSTOM_STRING_MAP *gpStringMapRes;
const CUSTOM_STRMAP_SEARCH *gpStrMapSearch;
extern StringResList *gStringList;

/* __CUSTPACK_MULTIBIN Calvin BEGIN */
extern int toolFlag;    /* 040805 CustPack: Calvin added */

/* __CUSTPACK_MULTIBIN Calvin END */

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
extern FILE *enfb_img_data_file;//100206 ENFB support
#endif

#ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
extern FILE *enfb_font_data_file;
#endif

/****************************************************************************
* Global Function - Extern                                                                 
*****************************************************************************/

/* Populate without compile option */
extern void PopulateNFBProgressImg(void);
//extern void PopulateMainMenuRes(void);
extern void PopulateIdleMenuRes(void);
extern void PopulatePbResData(void);
extern void PopulateCmResData(void);
extern void populateSettingMenu(void);
extern void populateFunAndGamesMenu(void);
extern void PopulateJavaRes(void);
extern void PopulateResData(void);
extern void PopulateSimDetectionMenuRes(void);
extern void PopulateSSCRes(void);

extern void PopulateOrganizerRes(void);
//#ifdef __MMI_INDICAL__
//extern void PopulateIndianCalendarRes(void);
//#endif
//#ifdef __MMI_HIJRI_CALENDAR__
//extern void PopulateHijriCalendarRes(void);
//#endif
//#ifdef __MMI_AZAAN_ALARM__
//extern void PopulateAzaanAlarmRes(void);
//#endif
extern void PopulateExtraRes(void);
extern void PopulateSATRes(void);
extern void PopulateResourcesCal(void);
extern void PopulateScreenSaverRes(void);
extern void PopulateCommonScreensResData(void);
extern void PopulateWapRes(void);
extern void PopulateMmiapiRes(void);

/* Populate with compile option */

#if 0
#if defined(__MMI_FACTORY_MODE__)
/* under construction !*/
#endif 
#endif 


#if defined(__MMI_AB_REPEATER__)
extern void populateABRepeaterMenu(void);
#endif 

#if defined(__MMI_FILE_MANAGER__) && defined(__PLUTO_MMI_PACKAGE__)
extern void PopulateFileMgrServiceResource(void);
#endif 

#if defined(__MMI_MY_FAVORITE__old)
extern void PopulateMyFavoriteRes(void);
#endif 

#if defined(__MMI_BARCODEREADER__)
extern void PopulateBarcodeReaderRes(void);
#endif 

#if defined(__MMI_BCR__)
extern void PopulateBCRRes(void);
#endif 

//#if defined(__MMI_A2DP_SUPPORT__)
//extern void PopulateAVBTRes(void);
//#endif

#if defined(__MMI_AVATAR__)
extern void PopulateAvatarRes(void);
#endif

#if defined(__MMI_VIDEO_PLAYER__)
extern void PopulateVdoPlyRes(void);
#endif 
#if defined(__MMI_STREAMING__)
//extern void PopulateStreamingRes(void);
#endif 

#if defined(__MMI_CAMCORDER__)
//extern void PopulateCamcorderRes(void);
#endif

#if defined(__MMI_VIDEO_EDITOR__)
extern void PopulateVdoEdtRes(void);
#endif

//#if defined(__MMI_FM_RADIO__)
//extern void PopulateFMRadioRes(void);
//#endif 

//#if defined(__MMI_FM_RADIO_SCHEDULE_REC__)
//extern void PopulateFMScheduleRecRes(void);
//#endif 

//#if defined(__MMI_PROV_MESSAGE_SUPPORT__)
//extern void PopulateProvBoxUIRes(void);
//#endif




#if defined(__MMI_SLIDESHOW__)
extern void PopulateSlideShowRes(void);
#endif





#ifdef __MMI_IRDA_SUPPORT__
extern void PopulateExtDevIrDARes(void);
#endif 


//#ifdef __MMI_RMGR__
//extern void PopulateRightsMgrRes(void);
//#endif

//#ifdef __DRM_SUPPORT__
//extern void PopulateDRMRes(void);
//#endif

#ifdef __MMI_VOIP__
extern void VoIPResourceData(void);
#endif /* __MMI_VOIP__ */

extern void srv_ucm_resource_data(void);



#if defined(__FOTA_ENABLE__)
extern void PopulateDMMenuList(void);
#endif 


#if defined(__MMI_MOBILE_SERVICE__)
/* under construction !*/
#endif

#if defined(__MMI_CUSTOMER_SERVICE__)
/* under construction !*/
#endif

#if defined(__MMI_MAPBAR_GIS__) || defined(__MMI_SUNAVI_GIS__) || defined(__MMI_MIGO_GIS__)
extern void PopulateGISRes(void);    
#endif 


#ifdef __CERTMAN_SUPPORT__
extern void PopulateCertManRes(void);
#endif /*__CERTMAN_SUPPORT__*/

#if defined(__MMI_EM_MISC_SOFTWARE_TRACER__)	
/* under construction !*/
#endif  

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
extern void PopulateFontResource(void);
#endif

#if defined(__MMI_MEDIA_PLAYER__)
//extern void PopulateMediaPlayerRes(void);
#endif

#ifdef __PLST_SERVICE_DB_SUPPORT__
//extern void PopulateSrvPlstRes(void);
#endif
#ifdef __QQIM_SUPPORT__
extern void PopulateQQRes(void);    
#endif

#ifdef __QQMOVIE_SUPPORT__
extern void PopulateQQMovieRes(void);    
#endif

#if defined(__UCWEB6__)
extern void PopulateUCWEBRes(void);    
#endif 

#if defined(__A8BOX_SUPPORT__)
extern void PopulateA8BoxRes(void);    
#endif 

#if defined(__MMI_VUI_HOMESCREEN__)
extern void PopulateVFHSRes(void);
#endif 

#if defined(__MMI_VUI_ENGINE__)
extern void PopulateVCPRes(void);
#endif 

#if 0
/* under construction !*/
#endif 

#ifdef __MMI_VUI_3D_CUBE_APP__
extern void PopulateVFCubeAppRes(void);
#endif

#ifdef OPERA_BROWSER
extern void PopulateOperaRes(void);
#endif 

extern void PopulatePhoneSettingSpecialRes(void);

//////////////////////////////////////////////////////////////////////////////
// Res Population static global variables
//////////////////////////////////////////////////////////////////////////////
static FILE * java_img_data_file = NULL;
static FILE * nfb_img_data_file = NULL;


/*****************************************************************************
 * FUNCTION
 *  ToolPopulateInitial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ToolPopulateInitial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0, j;
    unsigned char a[4];
    char cmd[512];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ClearHWIMageFile();
#ifndef __POPULATE_ENGINE_
    SendMessage(hWnd, WM_CLEARFILES, (WPARAM) 0, (LPARAM) 0);
#endif 
    /* 101806 E-NFB start */
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    CurrMaxENFBAssociatedIDNum = 0;
#endif
    /* 101806 E-NFB end */

    CurrMaxImageId = 0;
    CurrMaxImageNum = 0;
    CurrMaxImageIdEXT = 0;  /* 040805 CustPack: Calvin added */
    CurrMaxImageNumEXT = 0;

    CurrMaxAudioId = 0;
    CurrMaxAudioNum = 0;
    CurrMaxAudioIdEXT = 0;
    CurrMaxAudioNumEXT = 0;

    CurrMaxFontIdEXT = 0;
    CurrMaxFontNumEXT = 0;    

    CurrMaxMenuItemIndex = MAX_MENU_ITEMS;

    /* to read from NVRAM if possible -vanita */
    gCurrLangIndex = 0;

    memset(nCustMenus, 0, sizeof(CUSTOM_MENU) * MAX_MENU_ITEMS);
    /* init nParentId with an impossible value */
    for (i = 0; i < MAX_MENU_ITEMS; i++)
    {
        nCustMenus[i].nParentId = MAX_MENU_ITEMS;            
    }

    for (i = 0; i < MAX_IMAGE_IDS_SIZE; i++)
    {
        ImageIdMap[i].nImageNum = -1;
        ImageIdMapEXT[i].nImageNum = -1;    /* 040805 CustPack: Calvin added */
    }

    for (i = 0; i < MAX_AUDIO_IDS_SIZE; i++)
    {
        AudioIdMap[i].nAudioNum = -1;
        AudioIdMapEXT[i].nAudioNum = -1;
    }


    for (i = 0; i < MAX_FONT_IDS_SIZE; i++)
    {
        FontIdMapEXT[i].nFontNum = -1;
    }    
}

/* 101205 audio resource Calvin End */


/*****************************************************************************
 * FUNCTION
 *  ToolPopulateDone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ToolPopulateDone(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*  for generate string list file in first pass */
    fwprintf(StringListFile, L"##number\t%d\r\n", CurrMaxStringId);
    fclose(StringListFile);
    /* 091004 MTK Calvin added to reduce populate time */
    fclose(OutputImgIDFile);
    fclose(OutputMenutreeIDFile);
    fclose(RepeatIDListFile);   /* 102604 MTK Calvin added */
    /* MTK Calvin end */

#if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE)
    MYFCLOSE(fpMenuResourceUsage, MMI_RG_MENU_USAGE_FILE);
    MYFCLOSE(fpImageResourceUsage, MMI_RG_IMAGE_USAGE_FILE);
    MYFCLOSE(fpImageResourceUsageExt, MMI_RG_IMAGE_CONVERTED_INFO_FILE);
    MYFCLOSE(fpAudioResourceUsage, MMI_RG_AUDIO_USAGE_FILE);
    MYFCLOSE(fpStringResourceUsage, MMI_RG_STRING_USAGE_FILE);
#endif /* #if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE) */
}

/* __CUSTPACK_MULTIBIN Calvin End */

#define TYPE__(A) A##_MENU
#define TYPE_(A)  TYPE__(A)
#define TYPE(A) TYPE_(A)

/*****************************************************************************
 * FUNCTION
 *  ResPopSharedDefaultResourceInit
 * DESCRIPTION
 *  Populate Default Resource, this funciton must be invoked berfor 
 *  any resource population
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void ResPopSharedDefaultResourceInit(){
     /* add an empty image icon */
    ADD_APPLICATION_IMAGE(IMG_NONE, "..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp");

    /* 101205 audio resource Calvin Satrt */
    ADD_APPLICATION_AUDIO2(
        ADO_GLOBAL_EMPTYAUDIO,
        "..\\\\..\\\\Customer\\\\Audio\\\\EmptyAudio.mp3",
        "..\\\\..\\\\Customer\\\\Audio\\\\EmptyAudio.mp3");
    ADD_APPLICATION_AUDIO3(ADO_GLOBAL_EMPTYAUDIO_EXT, "..\\\\..\\\\Customer\\\\Audio\\\\EmptyAudio.mp3", "..\\\\..\\\\Customer\\\\Audio\\\\EmptyAudio.mp3");    /* for custpack */
    ADD_APPLICATION_AUDIO2(
        ADO_GLOBAL_NOAUDIO,
        "..\\\\..\\\\Customer\\\\Audio\\\\NoAudio.mp3",
        "..\\\\..\\\\Customer\\\\Audio\\\\NoAudio.mp3");
    ADD_APPLICATION_AUDIO2(
        ADO_GLOBAL_DEFAULT,
        "..\\\\..\\\\Customer\\\\Audio\\\\Default.mp3",
        "..\\\\..\\\\Customer\\\\Audio\\\\Default.mp3");
    /* 101205 audio resource Calvin End */

    ADD_APPLICATION_BINARY(
        BINARY_GLOBAL_NO_BINARY,
        "..\\\\..\\\\Customer\\\\Binary\\\\NoBinary.bin",
        BINARY_TYPE_VENUS_XML,
        "Empty binary data file");    
}

/*****************************************************************************
 * FUNCTION
 *  LegcayResPopController
 * DESCRIPTION
 *  Populate Resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void LegcayResPopController(){
	ResPopInitAll();
    
	PopulateResDataPreXML();
    PopulateResDataXML();
    PopulateResDataPostXML();
    
	ResPopDeinitAll();
}

/*****************************************************************************
 * FUNCTION
 *  PopulateResData
 * DESCRIPTION
 *  Populate Resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateResData(void)
{

   /*****************************************************************************
   * Populate Resoruce
   *****************************************************************************/
    PopulateNFBProgressImg();

    RESPOP_LOG_V("Populating Golbal Resources");
    PopulateGlobalData();
#ifdef __RESGEN_INTERNAL_3D_META_RESGEN_AUTO__
	PopulateImage3DData();
#endif //__RESGEN_INTERNAL_3D_META_RESGEN_AUTO__

    PopulateBinary3DData();

//    RESPOP_LOG_V("Populating Main Menu Resources");
//    PopulateMainMenuRes();

#if !defined(__IOT__)
    RESPOP_LOG_V("Populating Idle Menu Resources");
    PopulateIdleMenuRes();

    RESPOP_LOG_V("Populating Phone Book Resources");
    PopulatePbResData();

#ifdef __PLUTO_MMI_PACKAGE__
    RESPOP_LOG_V("Populating Setting Resources");
    populateSettingMenu();
#endif

    RESPOP_LOG_V("Populating Fun & Games Resources");
    populateFunAndGamesMenu();

    RESPOP_LOG_V("Populating SIM Detect Resources");
    PopulateSimDetectionMenuRes();

    fprintf(stderr, "Populate Resource 10%%\n");

    RESPOP_LOG_V("Populating Common Screen Resources");
    PopulateCommonScreensResData();

    RESPOP_LOG_V("Populating CM Resources");
    PopulateCmResData();

    RESPOP_LOG_V("Populating SSC Resources");
    PopulateSSCRes();

#if 0 /* Moved to XML based resources */
/* under construction !*/
/* under construction !*/
#endif

    RESPOP_LOG_V("Populating Organizer Resources");
    PopulateOrganizerRes();

//#ifdef __MMI_HIJRI_CALENDAR__
//    RESPOP_LOG_V("Populating hijri calendar resources");
//    PopulateHijriCalendarRes();
//#endif

//#ifdef __MMI_AZAAN_ALARM__
//    RESPOP_LOG_V("Populating hijri calendar resources");
//    PopulateAzaanAlarmRes();
//#endif /* __MMI_AZAAN_ALARM__ */

//#ifdef __MMI_INDICAL__
//	RESPOP_LOG_V("Populating Indian Calendar Resources");
//    PopulateIndianCalendarRes();
//#endif
		

    RESPOP_LOG_V("Populating Calendar Resources");
    PopulateResourcesCal();

    fprintf(stderr, "Populate Resource 20%%\n");


#if defined(__MMI_EM_MISC_SOFTWARE_TRACER__)
/* under construction !*/
/* under construction !*/
#endif


#ifdef __CERTMAN_SUPPORT__
//	RESPOP_LOG_V("Populating CertificateManager");
//	PopulateCertManRes();
#endif /*__CERTMAN_SUPPORT__*/

#if 0   /* Cylen 0926, customize display char */
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
    RESPOP_LOG_V("Populating MMIAPI Resource");
    PopulateMmiapiRes();

//#ifdef __MMI_PROV_MESSAGE_SUPPORT__
   // PopulateProvBoxUIRes();
//#endif

#ifdef __MMI_EMAIL__
    RESPOP_LOG_V("Populating Email Resources");
    //EmailResourceData();
#endif /* __MMI_EMAIL__ */ 

#if defined(__SAT__) && defined(__PLUTO_MMI_PACKAGE__)
    RESPOP_LOG_V("Populating SAT Resources");
    PopulateSATRes();
#endif /* __SAT__ */ 

    fprintf(stderr, "Populate Resource 30%%\n");

#if 0
#ifdef __MMI_FACTORY_MODE__
/* under construction !*/
/* under construction !*/
#endif
#endif /* __MMI_FACTORY_MODE__ */ 


#ifdef __MMI_AB_REPEATER__
    RESPOP_LOG_V("Populating AB Repeater Resources");
    populateABRepeaterMenu();
#endif /* __MMI_AB_REPEATER__ */ 

#if defined(__MMI_FILE_MANAGER__) && defined(__PLUTO_MMI_PACKAGE__)
    RESPOP_LOG_V("Populating File Manager Resources");
    PopulateFileMgrServiceResource();
#endif /* __MMI_FILE_MANAGER__ */ 

    fprintf(stderr, "Populate Resource 40%%\n");

#ifdef __MMI_VIDEO_PLAYER__
    //RESPOP_LOG_V("Populating Video Player Resources");
    //PopulateVdoPlyRes();
#endif /* __MMI_VIDEO_PLAYER__ */ 

#if defined(__MMI_STREAMING__)
    //RESPOP_LOG_V("Populating Streaming Setting Resources");
    //PopulateStreamingRes();
#endif /* __MMI_STREAMING__ */ 

#ifdef __MMI_VIDEO_EDITOR__
    RESPOP_LOG_V("Populating Video Editor Resources");
    PopulateVdoEdtRes();
#endif

#if defined(__MMI_MEDIA_PLAYER__)
    //RESPOP_LOG_V("Populating Media player Resources");
    //PopulateMediaPlayerRes();
#endif

#if defined(__PLST_SERVICE_DB_SUPPORT__)
   // RESPOP_LOG_V("Populating Play list service Resources");
   // PopulateSrvPlstRes();
#endif

#ifdef __MMI_PICTURE_EDITOR_SUPPORT__
    RESPOP_LOG_V("End Populating Image Editor");
    PopulatePictureEditor();
#endif /* __MMI_PICTURE_EDITOR_SUPPORT__ */ 


    fprintf(stderr, "Populate Resource 50%%\n");

#ifdef __MMI_BARCODEREADER__
    RESPOP_LOG_V("Populating Barcode Reader Resource");
    PopulateBarcodeReaderRes();
#endif /* __MMI_BARCODEREADER__ */ 

#ifdef __MMI_BCR__
    RESPOP_LOG_V("Populating bcr Resource");
    //PopulateBCRRes();
#endif /* __MMI_BCR__ */ 

#if defined(__MMI_CAMCORDER__)
//    RESPOP_LOG_V("Populating Camcorder Resource");
//    PopulateCamcorderRes();
#endif

#ifdef __MMI_AVATAR__
    RESPOP_LOG_V("Populating Avatar Resource");
    PopulateAvatarRes();
#endif /* __MMI_AVATAR__ */

//#ifdef __MMI_A2DP_SUPPORT__
//    RESPOP_LOG_V("Populating AVBT Resource");
//    PopulateAVBTRes();
//#endif /*__MMI_A2DP_SUPPORT__*/

//#ifdef __MMI_FM_RADIO__
//    RESPOP_LOG_V("Populating FM Radio Resource");
//    PopulateFMRadioRes();
//#endif /* __MMI_FM_RADIO__ */ 

//#ifdef __MMI_FM_RADIO_SCHEDULE_REC__
//    RESPOP_LOG_V("Populating Schedule FM Radio Record Resource");
//    PopulateFMScheduleRecRes();
//#endif /* __MMI_FM_RADIO_SCHEDULE_REC__ */ 


#if defined(__MMI_SLIDESHOW__)
    RESPOP_LOG_V("Populating Slideshow Resource");
    //PopulateSlideShowRes();
#endif


#ifdef __MMI_IRDA_SUPPORT__
    RESPOP_LOG_V("Populating IRDA Resource");
    PopulateExtDevIrDARes();
#endif /* __MMI_IRDA_SUPPORT__ */ 



#if defined(WAP_SUPPORT) || defined(__MMI_MMS__)
    RESPOP_LOG_V("Populating WAP Resource");
    PopulateWapRes();
#endif /* defined(WAP_SUPPORT) || defined(__MMI_MMS__) */ 

#ifdef __MMI_VOIP__
    RESPOP_LOG_V("Populating VoIP Resources");
    VoIPResourceData();
#endif /* __MMI_VOIP__ */

    fprintf(stderr, "Populate Resource 60%%\n");
    RESPOP_LOG_V("Populating UCM Service Resources");
    srv_ucm_resource_data();


#ifndef __POPULATE_ENGINE_
    SendMessage(hWnd, WM_GENSTRFILE, (WPARAM) 0, (LPARAM) 0);
    RESPOP_LOG_V("after 1 sendmsg");

    SendMessage(hWnd, WM_GENIMGFILE, (WPARAM) 0, (LPARAM) 0);
    RESPOP_LOG_V("after 2 send msg ");

    SendMessage(hWnd, WM_GENMENUFILE, (WPARAM) 0, (LPARAM) 0);
    RESPOP_LOG_V("after 3 send msg ");
#endif /* __POPULATE_ENGINE_ */ 

#ifdef __MMI_SWFLASH__
	RESPOP_LOG_V("Populating SWFlash Resource");	
	PopulateSWFlashRes();
#endif /* __MMI_SWFLASH__ */


    //WRITE_STRING_RES_FILE;    /* Write the string resource file only for first pass */
    //WRITE_IMAGE_RES_FILE;     /* Write the image resource file only for first pass */
    //WRITE_MENU_RES_FILE;

#ifdef __FOTA_ENABLE__
    RESPOP_LOG_V("Populating FOTA Resource");	
    PopulateFOTAData();
#endif /* __FOTA_ENABLE__ */

#ifdef __CARD_DOWNLOAD__
    RESPOP_LOG_V("Populating BL Resource");	
    PopulateBLData();
#endif /* __CARD_DOWNLOAD__ */

#ifdef __MMI_WEBCAM__
    RESPOP_LOG_V("Populating Webcam Resource");	
    PopulateWebcamData();
#endif /* __MMI_WEBCAM__ */

#if defined(__ZIMAGE_SUPPORT__)
    RESPOP_LOG_V("Populating Bootup Logo Resource");	
    PopulateBootupLogoData();
#endif /* defined(__ZIMAGE_SUPPORT__) */

#if defined(__FAST_LOGO__)
    RESPOP_LOG_V("Populating Fast Logo Resource");	
    PopulateFastLogoData();
#endif /* defined(__FAST_LOGO__) */

//#ifdef __MMI_RMGR__
//    RESPOP_LOG_V("Populating Rights Manager Resources");
//    PopulateRightsMgrRes();
//#endif

//#ifdef __DRM_SUPPORT__
//    RESPOP_LOG_V("Populating DRM Task Resources");
//    PopulateDRMRes();
//#endif


#ifdef __MMI_MOBILE_SERVICE__
/* under construction !*/
/* under construction !*/
#endif/*__MMI_MOBILE_SERVICE__*/

#if defined(__MMI_CUSTOMER_SERVICE__)
/* under construction !*/
/* under construction !*/
#endif/*__MMI_CUSTOMER_SERVICE__*/

#ifdef __MMI_MY_FAVORITE__old
    RESPOP_LOG_V("Populating My Favorite Resources");
    PopulateMyFavoriteRes();
#endif /* __MMI_MY_FAVORITE__old */ 


    fprintf(stderr, "Populate Resource 80%%\n");


#if defined(__MMI_MAPBAR_GIS__) || defined(__MMI_SUNAVI_GIS__) || defined(__MMI_MIGO_GIS__)
    RESPOP_LOG_V("Populating GIS Resource");
    PopulateGISRes();
#endif 

#if defined(__MMI_VECTOR_FONT_SUPPORT__)
    RESPOP_LOG_V("Populating Vector Font Resource");
    PopulateFontResource();
#endif

#ifdef __QQIM_SUPPORT__
    RESPOP_LOG_V(("Populating QQIM Resource"));
    PopulateQQRes();
#endif

#ifdef __QQMOVIE_SUPPORT__
    RESPOP_LOG_V(("Populating QQMovie Resource"));
    PopulateQQMovieRes();
#endif

#if defined(__UCWEB6__)
    RESPOP_LOG_V("Populating UCWEB Resource");
    PopulateUCWEBRes();
#endif 

#ifdef __A8BOX_SUPPORT__
    RESPOP_LOG_V(("Populating A8BOX Resource"));
    PopulateA8boxRes();
#endif

    fprintf(stderr, "Populate Resource 90%%\n");

#ifdef __MMI_VUI_HOMESCREEN__
    RESPOP_LOG_V(("Populating VF home screen Resource"));
    PopulateVFHSRes();
#endif

#ifdef __MMI_VUI_3D_CUBE_APP__
    RESPOP_LOG_V(("Populating Venus Tst APP Resource"));
    PopulateVFCubeAppRes();
#endif

#ifdef __MMI_VUI_ENGINE__
    PopulateVCPRes();
#endif

#if 0
/* under construction !*/
/* under construction !*/
#endif

#endif /* __IOT__ */
// The Res which is populated after mmi_rp_populate_resources() execution
// must be moved into PopulateResDataPostXML()
}

/*****************************************************************************
 * FUNCTION
 *  PopulateResDataPreXML
 * DESCRIPTION
 *  Control interface of legacy resource population. The resoruce population put in this file
 *  will be populated before XML resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateResDataPreXML(){
    PopulateResData();
}

/*****************************************************************************
 * FUNCTION
 *  PopulateResDataPostXML
 * DESCRIPTION
 *  Control interface of legacy resource population. The resoruce population put in this file
 *  will be populated after XML resource.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateResDataPostXML(){
#if !defined(__IOT__)
    PopulatePhoneSettingSpecialRes();
#endif

#ifdef OPERA_BROWSER
    RESPOP_LOG_V("Populating Opera Resources");
	PopulateOperaRes();
#endif

}

/*****************************************************************************
 * FUNCTION
 *  PopulateResDataXML
 * DESCRIPTION
 *  Control interface of legacy resource population. To populae legacy reource in XML RES files
 *  such as menu and hint handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateResDataXML(){
    // Populate the XML resources at last to group legacy and offline resource population
    mmi_rp_populate_resources();
}

#ifdef __FOTA_ENABLE__
/*****************************************************************************
 * FUNCTION
 *  PopulateFOTAImage
 * DESCRIPTION
 *  Populate FOTA image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PopulateFOTAImage(char* filename_in, char* output_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    FILE *fp;
    unsigned char *buffer;
    char filename_out[] = "..\\..\\Customer\\CustResource\\CustFOTAImgData.h";
    static int test = 0;
    int size, width, height, ret, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        /* open image test */
        fp = fopen(filename_in, "rb");
        if (fp == NULL)
        {
            fprintf(stderr, "[FOTA] %s Input file failed !!\n", filename_in);
            break;
        }
        fclose(fp);
        fp == NULL;
        
        /* decode image */
        buffer = (U8*)malloc(ABMENC_BMP_FILE_BUFFER_SIZE*sizeof(char));
        if (buffer == NULL)
        {
            fprintf(stderr, "[FOTA] allocate memory failed !!\n");
            break;
        }
        memset(buffer, 0, ABMENC_BMP_FILE_BUFFER_SIZE*sizeof(char));
        ret = ABM_load(
                filename_in,
                DRV_MAINLCD_BIT_PER_PIXEL,
                IMAGE_TYPE_DEVICE_BITMAP,
                ABM_ENC_OPTION_FLAG_AB2,
                buffer,
                &size, &width, &height, MMI_FALSE, NULL);
        if (ret != ABM_ENC_RETURN_USE_AB2)
        {
            fprintf(stderr, "[FOTA] %s ABM_Load failed !!\n", filename_in);
            break;
        }
        
        /* output image */
        if (test == 0)
        {
            fp = fopen(filename_out, "w+");
            test = 1;
        }
        else
        {
            fp = fopen(filename_out, "a");
        }
        if (fp == NULL)
        {
            fprintf(stderr, "[FOTA] %s Output file failed !!\n", filename_out);
            break;
        }
        fprintf(fp, "%s", output_array);
        fprintf(fp, "\n{");
        for (i = 0; i < size; i++)
        {
            if ((i % 16) == 0)
            {
                fprintf(fp, "\n\t");
            }
            fprintf(fp, "0x%02X, ", buffer[i]);
        }
        fprintf(fp, "\n};");
        fputs("\n", fp);
        fclose(fp);
        fp = NULL;
        
        free(buffer);
        buffer = NULL;
    } while (0);
    
    if (buffer != NULL) free(buffer);
    if (fp != NULL)     fclose(fp);
}


/*****************************************************************************
 * FUNCTION
 *  PopulateFOTAData
 * DESCRIPTION
 *  Populate FOTA data resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PopulateFOTAData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #if defined(__COSMOS_MMI__)
    char filename_update_background[] = CUST_IMG_PATH"\\MainLCD\\Submenu\\Services\\FOTA\\FW_update_bg.pbm";
    char filename_update_fail[] = CUST_IMG_PATH"\\MainLCD\\Submenu\\Services\\FOTA\\FW_update_fail.pbm";
    #else
    char filename_update_background[] = CUST_IMG_PATH"\\MainLCD\\Submenu\\Services\\FOTA\\FW_update_bg.bmp";
    char filename_update_fail[] = CUST_IMG_PATH"\\MainLCD\\Submenu\\Services\\FOTA\\FW_update_fail.bmp";
    #endif
    char output_array_update_background[] = "__align(4) U8 FOTA_PBAR_IMG_DATA[] = ";
    char output_array_update_fail[] = "__align(4) U8 FOTA_FAIL_IMG_DATA[] = ";
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PopulateFOTAImage(filename_update_background, output_array_update_background);
    PopulateFOTAImage(filename_update_fail, output_array_update_fail);
}
#endif /* __FOTA_ENABLE__ */


#ifdef __CARD_DOWNLOAD__
/*****************************************************************************
 * FUNCTION
 *  PopulateFOTAImage
 * DESCRIPTION
 *  Populate FOTA image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PopulateBLImage(char* filename_in, char* output_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    FILE *fp;
    unsigned char *buffer;
    char filename_out[] = "..\\..\\Customer\\CustResource\\CustBLImgData.h";
    static int test = 0;
    int size, width, height, ret, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        /* open image test */
        fp = fopen(filename_in, "rb");
        if (fp == NULL)
        {
            fprintf(stderr, "[BL] %s Input file failed !!\n", filename_in);
            break;
        }
        fclose(fp);
        fp == NULL;
        
        /* decode image */
        buffer = (U8*)malloc(ABMENC_BMP_FILE_BUFFER_SIZE*sizeof(char));
        if (buffer == NULL)
        {
            fprintf(stderr, "[BL] allocate memory failed !!\n");
            break;
        }
        memset(buffer, 0, ABMENC_BMP_FILE_BUFFER_SIZE*sizeof(char));
        ret = ABM_load(
                filename_in,
                DRV_MAINLCD_BIT_PER_PIXEL,
                IMAGE_TYPE_DEVICE_BITMAP,
                ABM_ENC_OPTION_FLAG_AB2,
                buffer,
                &size, &width, &height, MMI_FALSE, NULL);
        if (ret != ABM_ENC_RETURN_USE_AB2)
        {
            fprintf(stderr, "[BL] %s ABM_Load failed !!\n", filename_in);
            break;
        }
        
        /* output image */
        if (test == 0)
        {
            fp = fopen(filename_out, "w+");
            test = 1;
        }
        else
        {
            fp = fopen(filename_out, "a");
        }
        if (fp == NULL)
        {
            fprintf(stderr, "[BL] %s Output file failed !!\n", filename_out);
            break;
        }
        fprintf(fp, "%s", output_array);
        fprintf(fp, "\n{");
        for (i = 0; i < size; i++)
        {
            if ((i % 16) == 0)
            {
                fprintf(fp, "\n\t");
            }
            fprintf(fp, "0x%02X, ", buffer[i]);
        }
        fprintf(fp, "\n};");
        fputs("\n", fp);
        fclose(fp);
        fp = NULL;
        
        free(buffer);
        buffer = NULL;
    } while (0);
    
    if (buffer != NULL) free(buffer);
    if (fp != NULL)     fclose(fp);
}


/*****************************************************************************
 * FUNCTION
 *  PopulateBLData
 * DESCRIPTION
 *  Populate boot loader data resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PopulateBLData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #if defined(__COSMOS_MMI__)
    char filename_update_background[] = CUST_IMG_PATH"\\MainLCD\\Submenu\\Services\\FOTA\\FW_update_bg.pbm";
    char filename_update_fail[] = CUST_IMG_PATH"\\MainLCD\\Submenu\\Services\\FOTA\\FW_update_fail.pbm";
    #else
    char filename_update_background[] = CUST_IMG_PATH"\\MainLCD\\Submenu\\Services\\FOTA\\FW_update_bg.bmp";
    char filename_update_fail[] = CUST_IMG_PATH"\\MainLCD\\Submenu\\Services\\FOTA\\FW_update_fail.bmp";
    #endif
    char output_array_update_background[] = "__align(4) U8 BL_PBAR_IMG_DATA[] = ";
    char output_array_update_fail[] = "__align(4) U8 BL_FAIL_IMG_DATA[] = ";
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PopulateBLImage(filename_update_background, output_array_update_background);
    PopulateBLImage(filename_update_fail, output_array_update_fail);
}
#endif /* __LCD_DRIVER_IN_BL__ */



#if defined(__MMI_WEBCAM__)
/*****************************************************************************
 * FUNCTION
 *  PopulateFOTAData
 * DESCRIPTION
 *  Populate FOTA data resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PopulateWebcamData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fp_in = NULL, *fp_out = NULL;
    char filename_in0[] = CUST_IMG_PATH"\\MainLCD\\Active\\webcam\\webcam_jpeg_0.jpg";
    char filename_in1[] = CUST_IMG_PATH"\\MainLCD\\Active\\webcam\\webcam_jpeg_1.jpg";
    char filename_in2[] = CUST_IMG_PATH"\\MainLCD\\Active\\webcam\\webcam_jpeg_2.jpg";
    char output_name0[] = "webcam_pause_img_0";
    char output_name1[] = "webcam_pause_img_1";
    char output_name2[] = "webcam_pause_img_2";
    char filename_out[] = "..\\..\\Customer\\CustResource\\CustWebcamImgData.h";
    char buff[256];
    int count, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        fp_out = fopen(filename_out, "w");
        if (fp_out == NULL)
        {
            RESPOP_LOG_V("[WEBCAM] Output file failed !!");
            break;
        }

        for (i = 0 ; i < 3 ; i++)
        {
            int j, file_size = 0, o = 0;
            char *filename = NULL, *output_name = NULL;

            switch (i)
            {
                case 0:
                    filename = filename_in0;
                    output_name = output_name0;
                    break;
                case 1:
                    filename = filename_in1;
                    output_name = output_name1;
                    break;
                case 2:
                    filename = filename_in2;
                    output_name = output_name2;
                    break;
                default:
                    break;        
            }

            fp_in = fopen(filename, "rb");
            if (fp_in == NULL)
            {
                RESPOP_LOG_V("[WEBCAM] Input image 1 failed,\t%s !!", filename);
                break;
            }
            fprintf(fp_out, "const U8 %s[] = \n", output_name);
            fprintf(fp_out, "{\n\t");
            fseek(fp_in, 0, SEEK_END);
            file_size = ftell(fp_in);
            fseek(fp_in, 0, SEEK_SET);
            for (j = 0; j < file_size; j++)
            {
                fprintf(fp_out, "0x%02X, ", fgetc(fp_in));
                o++;
                if ((o % 16) == 0)
                {
                    fprintf(fp_out, "\n\t");
                }
            }
            fprintf(fp_out, "\n};\n");
        }
    } while (0);

    if (fp_in != NULL)  fclose(fp_in);
    if (fp_out != NULL) fclose(fp_out);
}
#endif /* defined(__MMI_WEBCAM__) */


#if defined(__ZIMAGE_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  PopulateBootupLogoData
 * DESCRIPTION
 *  Populate boot up logo data resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PopulateBootupLogoData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fp = NULL, *fp_temp = NULL;
    char filename_in[] = CUST_IMG_PATH"\\MainLCD\\Active\\poweronoff\\logo.BMP";
    char filename_temp[] = "TEMPIMAGE";
    char output_name[] = "bootup_logo_img";
#ifdef __ZIMAGE_LOGO_ANIMATED_SUPPORT__	
    char filename_in_ani[4][256] =
    {
        CUST_IMG_PATH"\\MainLCD\\Active\\poweronoff\\logo1.BMP",
        CUST_IMG_PATH"\\MainLCD\\Active\\poweronoff\\logo2.BMP",
        CUST_IMG_PATH"\\MainLCD\\Active\\poweronoff\\logo3.BMP",
        CUST_IMG_PATH"\\MainLCD\\Active\\poweronoff\\logo4.BMP"
    };
    char output_name_ani[4][32] = 
    {
        "bootup_logo_img_1",
        "bootup_logo_img_2",
        "bootup_logo_img_3",
        "bootup_logo_img_4"
    };
#endif
    char filename_out[] = "..\\..\\Customer\\CustResource\\CustBootupImgData.h";
    char buff[256];
    int ret, count, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        /* decode image */
        ret = BMPLoader(filename_in, filename_temp, DRV_MAINLCD_BIT_PER_PIXEL, "", MMI_FALSE, NULL);
        if (ret == 0)
        {
            fprintf(stderr, "[BOOTUP LOGO] %s BMPLoader failed !!\n", filename_in);
            break;
        }

        /* output data */
        fp = fopen(filename_out, "w");
        if (fp == NULL)
        {
            RESPOP_LOG_V("[BOOTUP LOGO] Output file failed !!");
            break;
        }

        fp_temp = fopen(filename_temp, "rb");
        if (fp_temp == NULL)
        {
            RESPOP_LOG_V("[BOOTUP LOGO] Read raw data file failed !!");
            break;
        }

        fprintf(fp, "#if !defined(__MTK_TARGET__)\n\t#define __align(x)\n#endif\n");
        fprintf(fp, "__align(4) const U8 %s[] = \n", output_name);
        while (!feof(fp_temp))
        {
            count = fread(buff, sizeof(char), 256, fp_temp);
            if (count)
            {
                fwrite(buff, sizeof(char), count, fp);
            }
        }
        fputs("\n", fp);
    } while (0);

    if (fp_temp != NULL)     fclose(fp_temp);

#ifdef __ZIMAGE_LOGO_ANIMATED_SUPPORT__	

    for (i = 0; i < 4; i ++)
    {
        /* decode image */
        ret = BMPLoader(filename_in_ani[i], filename_temp, DRV_MAINLCD_BIT_PER_PIXEL, "", MMI_FALSE, NULL);
        if (ret == 0)
        {
            fprintf(stderr, "[BOOTUP LOGO] %s BMPLoader failed !!\n", filename_in_ani[i]);
            break;
        }

        fp_temp = fopen(filename_temp, "rb");
        if (fp_temp == NULL)
        {
            RESPOP_LOG_V("[BOOTUP LOGO] Read raw data file failed !!");
            break;
        }

        fprintf(fp, "__align(4) const U8 %s[] = \n", output_name_ani[i]);
        while (!feof(fp_temp))
        {
            count = fread(buff, sizeof(char), 256, fp_temp);
            if (count)
            {
                fwrite(buff, sizeof(char), count, fp);
            }
        }
        fputs("\n", fp);
        if (fp_temp != NULL)     
            fclose(fp_temp);
    } 
#endif


    if (fp != NULL)     fclose(fp);
}
#endif /* defined(__ZIMAGE_SUPPORT__) */


#if defined(__FAST_LOGO__)
/*****************************************************************************
 * FUNCTION
 *  PopulateFastLogoData
 * DESCRIPTION
 *  Populate fast logo data resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateFastLogoData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fp = NULL;
    char filename_in[] = CUST_IMG_PATH"\\MainLCD\\Active\\poweronoff\\logo.BMP";
    char filename_temp[] = "TEMPIMAGE";
    char output_name[] = "g_fast_logo_img";
    char filename_out[] = "..\\..\\Customer\\CustResource\\CustFastLogoImgData.h";
    unsigned char *buffer;
    int size, width, height, ret, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        /* open image test */
        fp = fopen(filename_in, "rb");
        if (fp == NULL)
        {
            fprintf(stderr, "[FastLogo] %s Input file failed !!\n", filename_in);
            break;
        }
        fclose(fp);
        fp == NULL;
        
        /* decode image */
        buffer = (U8*)malloc(ABMENC_BMP_FILE_BUFFER_SIZE*sizeof(char));
        if (buffer == NULL)
        {
            fprintf(stderr, "[FastLogo] allocate memory failed !!\n");
            break;
        }
        memset(buffer, 0, ABMENC_BMP_FILE_BUFFER_SIZE*sizeof(char));
        ret = ABM_load(
                filename_in,
                DRV_MAINLCD_BIT_PER_PIXEL,
                IMAGE_TYPE_DEVICE_BITMAP,
                ABM_ENC_OPTION_FLAG_AB2,
                buffer,
                &size, &width, &height, MMI_FALSE, NULL);
        if (ret != ABM_ENC_RETURN_USE_AB2)
        {
            fprintf(stderr, "[FastLogo] %s ABM_Load failed !!\n", filename_in);
            break;
        }

        /* output image */
        fp = fopen(filename_out, "w+");
        if (fp == NULL)
        {
            fprintf(stderr, "[FastLogo] %s Output file failed !!\n", filename_out);
            break;
        }

        fprintf(fp, "#if !defined(__MTK_TARGET__)\n\t#define __align(x)\n#endif\n");
        fprintf(fp, "__align(4) static const U8 %s[] = \n{", output_name);
        for (i = 0; i < size; i++)
        {
            if ((i % 16) == 0)
            {
                fprintf(fp, "\n\t");
            }
            fprintf(fp, "0x%02X, ", buffer[i]);
        }
        fprintf(fp, "\n};\n");
    } while (0);
    
    if (buffer != NULL) free(buffer);
    if (fp != NULL)     fclose(fp);
}
#endif /* defined(__FAST_LOGO__) */


#if 1

/*
 * the global images for L1-L30 use bmp image type in 128x64 project,
 * but use bmp image type in others projects.
*/
#if defined(__MMI_MAINLCD_128X64__)
    #define __IMG_EXT_NAME__	".BMP"
#else /* __MMI_MAINLCD_128X64__ */
    #define __IMG_EXT_NAME__    ".bmp"
#endif /* __MMI_MAINLCD_128X64__ */

/* define for COSMOS_SLIM */ 
#if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
    #define __L_NB1__  "L_NB1"
    #define __L_NB2__  "L_NB1"
    #define __L_NB3__  "L_NB1"
    #define __L_NB4__  "L_NB1"
    #define __L_NB5__  "L_NB1"
    #define __L_NB6__  "L_NB1"
    #define __L_NB7__  "L_NB1"
    #define __L_NB8__  "L_NB1"
    #define __L_NB9__  "L_NB1"
    #define __L_NB10__ "L_NB1"
    #define __L_NB11__ "L_NB1"
    #define __L_NB12__ "L_NB1"
    #define __L_NB13__ "L_NB1"
    #define __L_NB14__ "L_NB1"
    #define __L_NB15__ "L_NB1"
    #define __L_NB16__ "L_NB1"
    #define __L_NB17__ "L_NB1"
    #define __L_NB18__ "L_NB1"
    #define __L_NB19__ "L_NB1"
    #define __L_NB20__ "L_NB1"
    #define __L_NB21__ "L_NB1"
    #define __L_NB22__ "L_NB1"
    #define __L_NB23__ "L_NB1"
    #define __L_NB24__ "L_NB1"
    #define __L_NB25__ "L_NB1"
    #define __L_NB26__ "L_NB1"
    #define __L_NB27__ "L_NB1"
    #define __L_NB28__ "L_NB1"
    #define __L_NB29__ "L_NB1"
    #define __L_NB30__ "L_NB1"
#else
    #define __L_NB1__  "L_NB1"
    #define __L_NB2__  "L_NB2"
    #define __L_NB3__  "L_NB3"
    #define __L_NB4__  "L_NB4"
    #define __L_NB5__  "L_NB5"
    #define __L_NB6__  "L_NB6"
    #define __L_NB7__  "L_NB7"
    #define __L_NB8__  "L_NB8"
    #define __L_NB9__  "L_NB9"
    #define __L_NB10__ "L_NB10"
    #define __L_NB11__ "L_NB11"
    #define __L_NB12__ "L_NB12"
    #define __L_NB13__ "L_NB13"
    #define __L_NB14__ "L_NB14"    
    #define __L_NB15__ "L_NB15"
    #define __L_NB16__ "L_NB16"
    #define __L_NB17__ "L_NB17"
    #define __L_NB18__ "L_NB18"
    #define __L_NB19__ "L_NB19"
    #define __L_NB20__ "L_NB20"
    #define __L_NB21__ "L_NB21"
    #define __L_NB22__ "L_NB22"
    #define __L_NB23__ "L_NB23"
    #define __L_NB24__ "L_NB24"
    #define __L_NB25__ "L_NB25"
    #define __L_NB26__ "L_NB26"
    #define __L_NB27__ "L_NB27"
    #define __L_NB28__ "L_NB28"
    #define __L_NB29__ "L_NB29"
    #define __L_NB30__ "L_NB30"
#endif


/*****************************************************************************
 * FUNCTION
 *  PopulateGlobalData
 * DESCRIPTION
 *  Populate Global Resource
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateGlobalData()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    /* ---------------- Common Global String (start) ----------------------- */
    /* Global string listed here are shared by Pluto and Cosmos */
    ADD_APPLICATION_STRING2(STR_GLOBAL_0, "0", "Global String- 0");
    ADD_APPLICATION_STRING2(STR_GLOBAL_1, "1", "Global String- 1");
    ADD_APPLICATION_STRING2(STR_GLOBAL_2, "2", "Global String- 2");
    ADD_APPLICATION_STRING2(STR_GLOBAL_3, "3", "Global String- 3");
    ADD_APPLICATION_STRING2(STR_GLOBAL_4, "4", "Global String- 4");
    ADD_APPLICATION_STRING2(STR_GLOBAL_5, "5", "Global String- 5");
    ADD_APPLICATION_STRING2(STR_GLOBAL_6, "6", "Global String- 6");
    ADD_APPLICATION_STRING2(STR_GLOBAL_7, "7", "Global String- 7");
    ADD_APPLICATION_STRING2(STR_GLOBAL_8, "8", "Global String- 8");
    ADD_APPLICATION_STRING2(STR_GLOBAL_9, "9", "Global String- 9");
    ADD_APPLICATION_STRING2(STR_GLOBAL_10, "10", "Global String- 10");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ABORT, "Abort", "Global String- Abort");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ABORTING, "Aborting", "Global String- Aborting");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ACCEPT,"Accept","Global String- Accept");    
    ADD_APPLICATION_STRING2(STR_GLOBAL_ACCOUNTS,"Accounts",	"Accounts- configuration folder");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ACTIVATE, "Activate", "Global String- Activate");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ACTIVATED, "Activated", "Global String- Activated");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ADD, "Add", "Global String- Add");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ADDRESS, "Address", "Global String- Address");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ADVANCED, "Advanced", "Global String- Advanced");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ALARM, "Alarm", "Global String- Alarm");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ALWAYS_ASK, "Always ask", "Global String- Always ask");
    ADD_APPLICATION_STRING2(STR_GLOBAL_AS_EMAIL, "As Email", "Global String- As Email- sub option of sending command");
    ADD_APPLICATION_STRING2(STR_GLOBAL_AS_MULTIMEDIA_MSG, "As multimedia message", "Global String- As multimedia message- sub option of sending command");
    ADD_APPLICATION_STRING2(STR_GLOBAL_AS_TEXT_MESSAGE, "As text message", "Global String- As text message- sub option of sending command");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ATTACHMENT, "Attachment", "Global String- Attachment");
    ADD_APPLICATION_STRING2(STR_GLOBAL_AUTHENTICATION,"Authentication","Global String- Authentication");
    ADD_APPLICATION_STRING2(STR_GLOBAL_AUTOMATIC,"Automatic","Global String- Automatic");
    ADD_APPLICATION_STRING2(STR_GLOBAL_BACK, "Back", "Global String- Back");
    ADD_APPLICATION_STRING2(STR_GLOBAL_BLUETOOTH, "Bluetooth", "Global String- Bluetooth");
    ADD_APPLICATION_STRING2(STR_GLOBAL_BUSY_TRY_LATER, "Busy", "STR_GLOBAL_BUSY_TRY_LATER");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CANCEL, "Cancel", "Global String- Cancel");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CANCELLING, "Cancelling", "Global String- Cancelling");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CLEAR, "Clear", "Global String- Clear");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CLOSE, "Close", "Global String- Close");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CONFIRM, "Confirm", "Global String- Confirm");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CONNECT, "Connect", "Global String- Connect");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CONNECTING, "Connecting", "Global String- Connecting");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CONTENT, "Content", "Global String- Content");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CONTINUE, "Cont.", "Global String- Cont.- use as LSK for length limit");
    ADD_APPLICATION_STRING2(STR_GLOBAL_COPY, "Copy", "Global String- Copy");
    ADD_APPLICATION_STRING2(STR_GLOBAL_COPYING, "Copying", "Global String- Copying");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE, "Currently not available", "Global String- the services/operations aren't workable in some situations");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL, "Not available during the call", "Global String- the services/operations aren't workable during the call");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CUSTOM, "Custom", "Global String- Custom- user defined");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DATA_ACCOUNT, "Data account", "Global String- Data account");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DATA_ACCOUNTS, "Data accounts", "Global String- Data accounts");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DATA_CONN_SETTING, "Data connection settings", "Global String- Data connection settings");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DATE, "Date", "Global String- Date");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DEACTIVATE, "Deactivate", "Global String- Deactivate");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DEFAULT, "Default", "Global String- Default");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DELETE, "Delete", "Global String- Delete");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DELETE_ALL, "Delete All", "Global String- Delete All");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DELETED, "Deleted", "Global String- Deleted");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DELETING, "Deleting", "Global String- Deleting");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DETAILS, "Details", "Global String- Details");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DIALLED_CALLS, "Dialled call", "Global string- Dialled calls");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DIAL, "Call", "Global String- Call");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DISCARD,"Discard","Global String- Discard");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DISCONNECT, "Disconnect", "Global String- Disconnect");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DISCONNECTING, "Disconnecting", "Global String- Disconnecting");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DONE, "Done", "Global String- Done");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DOWNLOAD, "Download", "STR_GLOBAL_DOWNLOAD");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DOWNLOAD_ASK, "Download?", "STR_GLOBAL_DOWNLOAD_ASK");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DOWNLOADING, "Downloading", "STR_GLOBAL_DOWNLOADING");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DRAFTS, "Drafts", "Global String- Drafts");
  //  ADD_APPLICATION_STRING2(STR_GLOBAL_DRM_FILE_EXISTS, "File Exists", "Global String- File Exists");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DRM_FS_ERROR, "File Access Error", "Global String- File Access Error");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DRM_INVALID_FORMAT, "Format Error", "Global String- Format Error");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DRM_NON_DRM, "Not DRM File", "Global String- Not DRM File");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DRM_PROCESSING, "DRM Processing", "Global String- DRM Processing");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DRM_PROHIBITED, "DRM Prohibited", "Global String- DRM Prohibited");
  //  ADD_APPLICATION_STRING2(STR_GLOBAL_DRM_RO_RECEIVED, "DRM Rights Received", "Global String- DRM Rights Received");
  //  ADD_APPLICATION_STRING2(STR_GLOBAL_DRM_SIZE_TOO_BIG, "Size Too Big", "Global String- Size Too Big");
    ADD_APPLICATION_STRING2(STR_GLOBAL_EARPHONE_IN, "Earphone plugged in!", "Global String- String Associated with Ear Phone Plug In Popup.");
    ADD_APPLICATION_STRING2(STR_GLOBAL_EARPHONE_OUT, "Earphone plugged Out", "Global String- Earphone plugged Out");
    ADD_APPLICATION_STRING2(STR_GLOBAL_EDIT, "Edit", "Global String- Edit");
    ADD_APPLICATION_STRING2(STR_GLOBAL_EDIT_BEFORE_CALL, "Edit before call", "Global String- Edit before call");
    ADD_APPLICATION_STRING2(STR_GLOBAL_EMAIL, "Email", "Global String- Email");
    ADD_APPLICATION_STRING2(STR_GLOBAL_EMPTY, "Empty", "Global String- Empty");
    ADD_APPLICATION_STRING2(STR_GLOBAL_EMPTY_LIST, "<Empty>", "Global String- <Empty>");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ERROR, "Error", "Global String- Error");
    ADD_APPLICATION_STRING2(STR_GLOBAL_EXIT, "Exit", "Global String- Exit");
    ADD_APPLICATION_STRING2(STR_GLOBAL_FAILED, "Failed", "Global String- Failed");
    ADD_APPLICATION_STRING2(STR_GLOBAL_FAILED_TO_SAVE, "Failed to save", "Global String- Failed to save");
    ADD_APPLICATION_STRING2(STR_GLOBAL_FAILED_TO_SEND, "Failed to send", "Global String- Failed to send");
    ADD_APPLICATION_STRING2(STR_GLOBAL_FAST, "Fast", "Global String- Fast");
    ADD_APPLICATION_STRING2(STR_GLOBAL_FILE_ALREADY_EXISTS, "File already exists", "Global String- File already exists");
    ADD_APPLICATION_STRING2(STR_GLOBAL_FILE_NOT_FOUND, "File not found", "Global string- File not found");
    ADD_APPLICATION_STRING2(STR_GLOBAL_FILENAME, "Filename", "Global String- Filename");
 //   ADD_APPLICATION_STRING2(STR_GLOBAL_FORMAT, "Format", "Global String- Format- the type of file");
    ADD_APPLICATION_STRING2(STR_GLOBAL_FORWARD, "Forward", "Global String- Forward- send message to other recipients");
    ADD_APPLICATION_STRING2(STR_GLOBAL_GO_TO, "Go to", "Global String- Go to- connect the URL");
    ADD_APPLICATION_STRING2(STR_GLOBAL_GPRS, "GPRS", "Global String- GPRS");
  //  ADD_APPLICATION_STRING2(STR_GLOBAL_GSM, "GSM", "Global String- GSM");
    ADD_APPLICATION_STRING2(STR_GLOBAL_HELP, "Help", "Global String- Help- show the usage tips or notes");
    ADD_APPLICATION_STRING2(STR_GLOBAL_HIGH, "High", "Global String- High");
    ADD_APPLICATION_STRING2(STR_GLOBAL_HTTP, "HTTP", "Global String- HTTP");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INBOX, "Inbox", "Global String- Inbox");
  //  ADD_APPLICATION_STRING2(STR_GLOBAL_INCOMING_CALL, "Incoming call", "Global String- Incoming call");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INPUT_METHOD, "Input Method", "Global String- Input Method");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INSERT_SIM_CARD, "Please insert a SIM card", "Gloabl String - Please insert a SIM card"); 
    ADD_APPLICATION_STRING2(STR_GLOBAL_INSTALL, "Install", "Global String- Install");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INSUFFICIENT_MEMORY, "Insufficient memory", "Global String- Insufficient memory- not enough RAM to operate");    
    ADD_APPLICATION_STRING2(STR_GLOBAL_INVALID, "Invalid", "Global String- Invalid");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INVALID_DATA_ACCOUNT, "Invalid data account. Configure?", "Global String- Invalid data account. Configure?");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INVALID_EMAIL_ADDRESS, "Invalid Email address", "Global String- Invalid Email address");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INVALID_EMAIL_ADDRESSES, "Invalid Email addresses", "Global String- Invalid Email addresses");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INVALID_FILENAME, "Invalid filename", "Global String- Invalid filename");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INVALID_FORMAT, "Invalid format", "Global String- Invalid format");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INVALID_INPUT, "Invalid input", "Global String- Invalid input");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INVALID_NUMBER, "Invalid number", "Global String- Invalid number");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INVALID_NUMBERS, "Invalid numbers", "Global String- Invalid numbers");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INVALID_RECIPIENTS, "Invalid recipients", "Global String- Invalid recipients");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INVALID_URL, "Invalid URL", "Global String- Invalid URL");
    ADD_APPLICATION_STRING2(STR_GLOBAL_LIST, "List", "Global String- List");
    ADD_APPLICATION_STRING2(STR_GLOBAL_LOADING, "Loading", "Global String- Loading");
    ADD_APPLICATION_STRING2(STR_GLOBAL_LOGIN, "Login", "Global String- Login");
    ADD_APPLICATION_STRING2(STR_GLOBAL_LOGO, "Logo", "Global String- Logo");
    ADD_APPLICATION_STRING2(STR_GLOBAL_LOGOUT, "Logout", "Global String- Logout");
    ADD_APPLICATION_STRING2(STR_GLOBAL_LOW, "Low", "Global String- Low");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MANUAL, "Manual", "Global String- Manual");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MARK, "Mark", "Global String- Mark");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MARK_ALL, "Mark all", "Global String- Mark all");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MAXIMUM, "Maximum", "Global String- Maximum");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MEDIUM, "Medium", "Global String- Medium");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MEMORY_CARD, "Memory card", "Global String- Memory card");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MEMORY_FULL, "Memory full", "Global String- Memory full- indicate user not save again");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MEMORY_STATUS, "Memory status", "Global String- Memory status");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MESSAGE, "Message", "Global String- Message");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MISSED_CALLS, "Missed calls", "Global String- Missed calls");
	#ifdef MMS_SUPPORT	
    ADD_APPLICATION_STRING2(STR_GLOBAL_MMS, "MMS", "Global String- MMS");
	#endif
    ADD_APPLICATION_STRING2(STR_GLOBAL_MODE, "Mode", "Global String- Mode");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MOVE, "Move", "Global String- Move");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MOVING, "Moving", "Global String- Moving");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MULTIMEDIA_MESSAGE, "Multimedia message", "Global String- Multimedia message");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MUTE, "Mute", "Global String- Mute");
    ADD_APPLICATION_STRING2(STR_GLOBAL_NETWORK_SETTINGS, "Network settings", "Global String- Network settings");
    ADD_APPLICATION_STRING2(STR_GLOBAL_NO, "No", "Global String- No");
    ADD_APPLICATION_STRING2(STR_GLOBAL_NO_MEMORY_CARD, "No Memory Card", "[Notify-No Memory Card]");
    ADD_APPLICATION_STRING2(STR_GLOBAL_NONE, "None", "Global String- None");
    ADD_APPLICATION_STRING2(STR_GLOBAL_NORMAL, "Normal", "Global String- Normal");
    ADD_APPLICATION_STRING2(STR_GLOBAL_NOT_AVAILABLE, "Not Available", "Global String- Not Available");
    ADD_APPLICATION_STRING2(STR_GLOBAL_NOT_AVAILABLE_DURING_VIDEO_CALL, "Not available during video call", "Global String- Not available during video call");
    ADD_APPLICATION_STRING2(STR_GLOBAL_NOT_ENOUGH_MEMORY, "Not enough memory", "Global String- Not enough memory- memory is too small to save");
    ADD_APPLICATION_STRING2(STR_GLOBAL_NOT_SUPPORT_AT_PC_SIMULATOR, "Not supported on PC simulator", "Global String- Not supported on PC simulator");
    ADD_APPLICATION_STRING2(STR_GLOBAL_NOT_SUPPORTED, "Not supported", "Global String- Not supported");
    ADD_APPLICATION_STRING2(STR_GLOBAL_OFF, "Off", "Global String- Off");
    ADD_APPLICATION_STRING2(STR_GLOBAL_OK, "Ok", "Global String- OK");
    ADD_APPLICATION_STRING2(STR_GLOBAL_ON, "On", "Global String- On");
    ADD_APPLICATION_STRING2(STR_GLOBAL_OPEN, "Open", "Global String- Open");
    ADD_APPLICATION_STRING2(STR_GLOBAL_OPTIONS, "Option", "Global String- Options");
    ADD_APPLICATION_STRING2(STR_GLOBAL_OUTBOX, "Outbox", "Global String- Outbox");
    ADD_APPLICATION_STRING2(STR_GLOBAL_OVERWRITE_EXISTING_FILE, "Overwrite existing file?", "Global String- Overwrite existing file?");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PASSWORD, "Password","Global String- Password menu");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PAUSE, "Pause","Global String- Pause");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PHONE, "Phone","Global String- Phone");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PICTURE, "Picture","Global String- Picture");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PLAY, "Play","Global String- Play");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PLEASE_WAIT, "Please Wait", "Global String- Please Wait");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PLEASE_INPUT_THE_FILENAME, "Please input the filename", "Global String- Prompt user the filename is empty");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PREFERRED_STORAGE, "Preferred storage", "Global String- Preferred storage");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PREV, "Prev.", "Global String- Prev.");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PREVIEW, "Preview", "Global String- Preview");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PRINT, "Print", "Global String- Print");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PRIORITY, "Priority", "Global String- Priority");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PROXY, "Proxy", "Global String- Proxy");
    ADD_APPLICATION_STRING2(STR_GLOBAL_QUIT, "Quit", "Global String- Quit");
    ADD_APPLICATION_STRING2(STR_GLOBAL_READ, "Read", "Global String- Read");
    ADD_APPLICATION_STRING2(STR_GLOBAL_RECEIVED, "Received", "Global String- Received");
    ADD_APPLICATION_STRING2(STR_GLOBAL_RECEIVED_CALLS, "Received calls", "Global string- Received calls");
    ADD_APPLICATION_STRING2(STR_GLOBAL_RECEIVING, "Receiving", "Global String- Receiving");
    ADD_APPLICATION_STRING2(STR_GLOBAL_RECIPIENTS, "Recipients", "Global String- Recipients- recipient list name");
    ADD_APPLICATION_STRING2(STR_GLOBAL_REFRESH, "Refresh", "Global String- Refresh");
    ADD_APPLICATION_STRING2(STR_GLOBAL_REMOVE, "Remove", "Global String- Remove- delete the reference link or remove accessory from phone");
    ADD_APPLICATION_STRING2(STR_GLOBAL_REMOVED, "Removed", "Global String- Removed- remove successfully");
    ADD_APPLICATION_STRING2(STR_GLOBAL_RENAME, "Rename", "Global String- Rename");
    ADD_APPLICATION_STRING2(STR_GLOBAL_REPLACE, "Replace", "Global String- Replace");
    ADD_APPLICATION_STRING2(STR_GLOBAL_REPLY, "Reply", "Global String- Reply");
    ADD_APPLICATION_STRING2(STR_GLOBAL_RESEND, "Resend", "Global String- Resend");
    ADD_APPLICATION_STRING2(STR_GLOBAL_RESET, "Reset", "Global String- Reset");
    ADD_APPLICATION_STRING2(STR_GLOBAL_RESUME, "Resume", "Global String- Resume");
    ADD_APPLICATION_STRING2(STR_GLOBAL_RINGTONE, "Ringtone", "Global String- Ringtone");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SAVE, "Save", "Global String- Save");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SAVE_ASK, "Save?", "Global String- Save?");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SAVE_TO_PHONEBOOK, "Save to Phonebook", "Global String- Save to Phonebook");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SAVED, "Saved", "Global String- Saved");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SAVING, "Saving", "Global String- Saving");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SEARCH, "Search", "Global String- Search");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SEARCHING, "Searching", "Global String- Searching");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SELECT, "Select", "Global String- Select");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SEND, "Send", "Global String- Send");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SEND_MESSAGE, "Send message", "Global String- Send message");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SEND_MULTIMEDIA_MESSAGE, "Send multimedia message", "The option of send multimedia message");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SEND_TEXT_MESSAGE, "Send text message", "The option of send text message");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SENDING, "Sending", "Global String- Sending");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SENT, "Sent", "Global String- Sent- send successfully");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SETTINGS, "Settings", "Global String- Settings");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SILENT, "Silent", "Global String- Silent");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SIM, "SIM", "Global String- SIM");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SIM_1, "SIM1", "Global String- SIM1");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SIM_2, "SIM2", "Global String- SIM2");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SIM_3, "SIM3", "Global String- SIM3");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SIM_4, "SIM4", "Global String- SIM4");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SLOW, "Slow", "Global String- Slow");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SORT_BY, "Sort by", "Global String- Sort by- include sub options");
    ADD_APPLICATION_STRING2(STR_GLOBAL_START, "Start", "Global String- Start");
    ADD_APPLICATION_STRING2(STR_GLOBAL_STOP, "Stop", "Global String- Stop");
    ADD_APPLICATION_STRING2(STR_GLOBAL_STORAGE, "Storage", "Global String- Storage");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SUBJECT, "Subject", "Global String- Subject");
    ADD_APPLICATION_STRING2(STR_GLOBAL_TEXT, "Text", "Global String- Text");
    ADD_APPLICATION_STRING2(STR_GLOBAL_TEXT_MESSAGE, "Text message", "Global String- Text message- SMS");
    ADD_APPLICATION_STRING2(STR_GLOBAL_TIME, "Time", "Global String- Time");
    ADD_APPLICATION_STRING2(STR_GLOBAL_UNAVAILABLE_IN_FLIGHT_MODE, "Unavailable in flight mode", "Global String- Unavailable in flight mode");
    ADD_APPLICATION_STRING2(STR_GLOBAL_UNAVAILABLE_SIM, "Unavailable SIM", "Global String- Unavailable SIM");
    ADD_APPLICATION_STRING2(STR_GLOBAL_UNFINISHED, "Unfinished", "Global String- Unfinished");
    ADD_APPLICATION_STRING2(STR_GLOBAL_UNMARK, "Unmark", "Global String- Unmark");
    ADD_APPLICATION_STRING2(STR_GLOBAL_UNMARK_ALL, "Unmark all", "Global String- Unmark all");
    ADD_APPLICATION_STRING2(STR_GLOBAL_UNSUPPORTED_FORMAT, "Unsupported Format", "Global String- Unsupported Format");
    ADD_APPLICATION_STRING2(STR_GLOBAL_UPDATE, "Update", "Global String- Update");
    ADD_APPLICATION_STRING2(STR_GLOBAL_URL, "URL", "Global String- URL");
    ADD_APPLICATION_STRING2(STR_GLOBAL_USE, "Use", "Global String- Use");
    ADD_APPLICATION_STRING2(STR_GLOBAL_USE_TEMPLATE, "Use Template", "Global String- Use Template");
    ADD_APPLICATION_STRING2(STR_GLOBAL_USERNAME, "User Name", "Global String- User name menu");
    ADD_APPLICATION_STRING2(STR_GLOBAL_VIA_BLUETOOTH, "Via Bluetooth", "Global String- Via Bluetooth- sub option of sending command");
    ADD_APPLICATION_STRING2(STR_GLOBAL_VIA_INFRARED, "Via infrared", "Global String- Via infrared- sub option of sending command");
    ADD_APPLICATION_STRING2(STR_GLOBAL_VIDEO, "Video", "Global String- Video");
    ADD_APPLICATION_STRING2(STR_GLOBAL_VIEW, "View", "Global String- View");
    ADD_APPLICATION_STRING2(STR_GLOBAL_VOLUME, "Volume", "Global String- Volume");
    ADD_APPLICATION_STRING2(STR_GLOBAL_WALLPAPER, "Wallpaper", "Global String- Wallpaper");
    ADD_APPLICATION_STRING2(STR_GLOBAL_WAP, "WAP", "Global String- WAP");
    ADD_APPLICATION_STRING2(STR_GLOBAL_WIFI, "Wi-Fi", "Global String- Wi-Fi");
  //  ADD_APPLICATION_STRING2(STR_GLOBAL_YEAR, "Year", "Global String- Year");
    ADD_APPLICATION_STRING2(STR_GLOBAL_YES, "Yes", "Global String- Yes");

    ADD_APPLICATION_STRING2(STR_GLOBAL_INSERT_MEMORY_CARD, "Please insert memory card", "Global String- Please insert memory card");
    
    ADD_APPLICATION_STRING2(STR_GLOBAL_MC_REMOVED_USE_PHONE, "Memory card removed. Use phone?", "Global String- Memory card removed. Use phone?" );
    ADD_APPLICATION_STRING2(STR_GLOBAL_MC_REMOVED, "Memory card removed", "Global String- Memory card removed" );
    ADD_APPLICATION_STRING2(STR_GLOBAL_MC_INSERTED, "Memory card inserted", "Global String- Memory card inserted" );
    ADD_APPLICATION_STRING2(STR_GLOBAL_OTG_REMOVED_USE_PHONE, "OTG device removed. Phone will be used.", "Global String- OTG device removed. Phone will be used." );
    ADD_APPLICATION_STRING2(STR_GLOBAL_OTG_REMOVED_USE_PHONE_QUERY, "OTG device removed. Use phone?", "Global String- OTG device removed. Use phone?" );
    ADD_APPLICATION_STRING2(STR_GLOBAL_OTG_REMOVED, "OTG device removed", "Global String- OTG device removed" );
    ADD_APPLICATION_STRING2(STR_GLOBAL_OTG_CONNECTED, "OTG device connected", "Global String- OTG device connected" );

    ADD_APPLICATION_STRING2(STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE, "Not available in mass storage mode", "Global String- Not available in mass storage mode" );
    ADD_APPLICATION_STRING2(STR_GLOBAL_NO_NUMBER, "No number", "Global String- No number" );

    ADD_APPLICATION_STRING2(STR_GLOBAL_SUNDAY, "Sunday", "Global String- Sunday");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MONDAY, "Monday", "Global String- Monday");
    ADD_APPLICATION_STRING2(STR_GLOBAL_TUESDAY, "Tuesday", "Global String- Tuesday");
    ADD_APPLICATION_STRING2(STR_GLOBAL_WEDNESDAY, "Wednesday", "Global String- Wednesday");
    ADD_APPLICATION_STRING2(STR_GLOBAL_THURSDAY, "Thursday", "Global String- Thursday");
    ADD_APPLICATION_STRING2(STR_GLOBAL_FRIDAY, "Friday", "Global String- Friday");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SATURDAY, "Saturday", "Global String- Saturday");
    
    
    ADD_APPLICATION_STRING2(STR_GLOBAL_SUNDAY_SHORT, "Sun", "Global String- Sun");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MONDAY_SHORT, "Mon", "Global String- Mon");
    ADD_APPLICATION_STRING2(STR_GLOBAL_TUESDAY_SHORT, "Tue", "Global String- Tue");
    ADD_APPLICATION_STRING2(STR_GLOBAL_WEDNESDAY_SHORT, "Wed", "Global String- Wed");
    ADD_APPLICATION_STRING2(STR_GLOBAL_THURSDAY_SHORT, "Thu", "Global String- Thu");
    ADD_APPLICATION_STRING2(STR_GLOBAL_FRIDAY_SHORT, "Fri", "Global String- Fri");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SATURDAY_SHORT, "Sat", "Global String- Sat");
    
    
    ADD_APPLICATION_STRING2(STR_GLOBAL_JANUARY_SHORT, "Jan", "Global String- Jan");
    ADD_APPLICATION_STRING2(STR_GLOBAL_FEBRUARY_SHORT, "Feb", "Global String- Feb");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MARCH_SHORT, "Mar", "Global String- Mar");
    ADD_APPLICATION_STRING2(STR_GLOBAL_APRIL_SHORT, "Apr", "Global String- Apr");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MAY_SHORT, "May", "Global String- May");
    ADD_APPLICATION_STRING2(STR_GLOBAL_JUNE_SHORT, "Jun", "Global String- Jun");
    ADD_APPLICATION_STRING2(STR_GLOBAL_JULY_SHORT, "Jul", "Global String- Jul");
    ADD_APPLICATION_STRING2(STR_GLOBAL_AUGEST_SHORT, "Aug", "Global String- Aug");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SEPTEMBER_SHORT, "Sep", "Global String- Sep");
    ADD_APPLICATION_STRING2(STR_GLOBAL_OCTOBER_SHORT, "Oct", "Global String- Oct");
    ADD_APPLICATION_STRING2(STR_GLOBAL_NOVEMBER_SHORT, "Nov", "Global String- Nov");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DECEMBER_SHORT, "Dec", "Global String- Dec");
    

    ADD_APPLICATION_STRING2(STR_GLOBAL_DIAL_VIDEO_CALL, "Video call", "Global String- Video call" );
    ADD_APPLICATION_STRING2(STR_GLOBAL_DELETE_ASK, "Delete?", "Global String- Delete ask" );
    ADD_APPLICATION_STRING2(STR_GLOBAL_DELETE_ALL_ASK, "Delete all?", "Global String- Delete all ask" );
    ADD_APPLICATION_STRING2(STR_GLOBAL_USE_AS, "Use as", "Global String- Use as" );
    ADD_APPLICATION_STRING2(STR_GLOBAL_STATUS, "Status", "Global String- Status" );
    /* ---------------- Common Global String ( end ) ----------------------- */

    /* ------------------- Cosmos and FTE only (Start)---------------------- */
    /*  Globla listed here are used by Cosmos and FTE only.  */
#if defined(__COSMOS_MMI__) || defined(__VENUS_UI_ENGINE__)	
    ADD_APPLICATION_STRING2(STR_GLOBAL_SUBMIT,"Submit","Accept");
    ADD_APPLICATION_STRING2(STR_GLOBAL_UDP_PORT, "UDP port", "Global String- UDP port");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CLIPBOARD, "Clipboard", "Global String- Clipboard");

    ADD_APPLICATION_STRING2(STR_GLOBAL_ADD_TO_EXISTING_CONTACT, "Add to existing contact", "Global String- Add to existing contact");
    ADD_APPLICATION_STRING2(STR_GLOBAL_AM, "AM", "Global String- AM");
    ADD_APPLICATION_STRING2(STR_GLOBAL_AUDIO, "Audio", "Global String- Audio");
    ADD_APPLICATION_STRING2(STR_GLOBAL_BOOKMARKS, "Bookmarks", "Global String- Bookmarks");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CHOOSE_STORAGE, "Choose storage", "Global String- Choose storage");
    ADD_APPLICATION_STRING2(STR_GLOBAL_CREATE_NEW_CONTACT, "Create new contact", "Global String- Create new contact");
    ADD_APPLICATION_STRING2(STR_GLOBAL_DAY, "Day", "Global String- Day");
    ADD_APPLICATION_STRING2(STR_GLOBAL_EARPHONE, "Earphone", "Global String- Earphone");
    ADD_APPLICATION_STRING2(STR_GLOBAL_EXPORT, "Export", "Global String- Export");
    ADD_APPLICATION_STRING2(STR_GLOBAL_FILENAME_ALREADY_EXISTS, "Filename already exists", "Global String- Filename already exists");
    ADD_APPLICATION_STRING2(STR_GLOBAL_FOLD, "Fold", "Global String- Fold");
    ADD_APPLICATION_STRING2(STR_GLOBAL_GO_TO_URL, "Go to URL", "Global String- Go to URL");
    ADD_APPLICATION_STRING2(STR_GLOBAL_HOME, "Home", "Global String- Home");
    ADD_APPLICATION_STRING2(STR_GLOBAL_HOUR, "Hour", "Global String- Hour");
    ADD_APPLICATION_STRING2(STR_GLOBAL_IMPORT, "Import", "Global String- Import");
    ADD_APPLICATION_STRING2(STR_GLOBAL_INSTALLING, "Installing", "Global String- Installing");
    ADD_APPLICATION_STRING2(STR_GLOBAL_LANDSCAPE, "Landscape", "Global String- Landscape");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MIN, "Min", "Global String- Min");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MORE, "More", "Global String- More");
    ADD_APPLICATION_STRING2(STR_GLOBAL_MULTIMEDIA, "Multimedia", "Global String- Multimedia");	
    ADD_APPLICATION_STRING2(STR_GLOBAL_NEXT, "Next", "Global String- Next");	
    ADD_APPLICATION_STRING2(STR_GLOBAL_PM, "PM", "Global String- PM");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PORTRAIT, "Portrait", "Global String- Portrait");
    ADD_APPLICATION_STRING2(STR_GLOBAL_PRIMARY_SIM, "Primary SIM", "Global String- Primary SIM");
    ADD_APPLICATION_STRING2(STR_GLOBAL_REFRESHING, "Refreshing", "Global String- Refreshing");
    ADD_APPLICATION_STRING2(STR_GLOBAL_REMINDER, "Reminder", "Global String- Reminder");
    ADD_APPLICATION_STRING2(STR_GLOBAL_RESTORE, "Restore", "Global String- Restore");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SEC, "Sec", "Global String- Sec");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SECONDARY_SIM, "Secondary SIM", "Global String- Secondary SIM");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SECURITY, "Security", "Global String- Security");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SELECT_ALL, "Select all", "Global String- Select all");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SET_AS, "Set as", "Global String- Set as");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SHARE, "Share", "Global String- Share");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SMS, "SMS", "Global String- SMS");
    ADD_APPLICATION_STRING2(STR_GLOBAL_SORT, "Sort", "Global String- Sort");
    ADD_APPLICATION_STRING2(STR_GLOBAL_TEMPLATE, "Template", "Global String- Template");
    ADD_APPLICATION_STRING2(STR_GLOBAL_UNNAMED, "Unnamed", "Global String- Unnamed" );	
    ADD_APPLICATION_STRING2(STR_GLOBAL_UNSELECT_ALL, "Unselect all", "Global String- Unselect all");
    ADD_APPLICATION_STRING2(STR_GLOBAL_UPLOAD, "Upload", "Global String- Upload");
    ADD_APPLICATION_STRING2(STR_GLOBAL_VIBRATION, "Vibration", "Global String- Vibration");
    ADD_APPLICATION_STRING2(STR_GLOBAL_WEEK, "WEEK", "Global String- Week");
    ADD_APPLICATION_STRING2(STR_GLOBAL_WIFI_ONLY, "Wi-Fi only", "Global String- Wi-Fi only");
#endif /*__COSMOS_MMI__ || __VENUS_UI_ENGINE__ */
    /* ---------------------- Cosmos and FTE only (end) ---------------------- */
	
    ADD_APPLICATION_IMAGE2(IMG_GLOBAL_OK, "..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp", "Global Image-Ok");
    ADD_APPLICATION_IMAGE2(IMG_GLOBAL_BACK, "..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp", "Global Image-Back");
    ADD_APPLICATION_IMAGE2(IMG_GLOBAL_YES, "..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp", "Global Image-Yes");
    ADD_APPLICATION_IMAGE2(IMG_GLOBAL_NO, "..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp", "Global Image-No");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_OPTIONS,
        "..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp",
        "Global Image-Options");
{
    S32 force_type = AUTO_TYPE;

    /* force ABM to speed up 6223 + QVGA */
#if defined(__CPU_ARM7EJ_S__) && defined(__MMI_MAINLCD_240X320__)
    force_type = FORCE_ABM;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
    ADD_APPLICATION_IMAGE2(IMG_GLOBAL_CLEAR, "..\\\\..\\\\Customer\\\\Images\\\\EmptyImage.bmp", "Global Image-Clear");

    ADD_APPLICATION_IMAGE2(IMG_VICON, CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\checkbox\\\\CK_V.bmp", "Status Image");
#ifndef __MMI_ALARM_SLIM__
    #if defined(__COSMOS_MMI__)
    ADD_APPLICATION_IMAGE2(IMG_STATUS, CUST_IMG_PATH "\\\\MainLCD\\\\Alarm\\\\OA_STATU.pbm", "Status Image");
    #else
    ADD_APPLICATION_IMAGE2(IMG_STATUS, CUST_IMG_PATH "\\\\MainLCD\\\\Alarm\\\\OA_STATU.bmp", "Status Image");
    #endif
    ADD_APPLICATION_IMAGE2(IMG_TIME, CUST_IMG_PATH "\\\\MainLCD\\\\Alarm\\\\OA_TIME.bmp", "Time Image");
    ADD_APPLICATION_IMAGE2(IMG_REPEAT, CUST_IMG_PATH "\\\\MainLCD\\\\Alarm\\\\OA_REPT.bmp", "Repeat Image");
#endif
    ADD_APPLICATION_IMAGE2(
        IMG_CAL,
        CUST_IMG_PATH "\\\\MainLCD\\\\SubMenu\\\\Settings\\\\DateAndTime\\\\ST_CALEN.bmp",
        "Calendar Image");
//popup icon slim
#ifndef __MMI_POPUP_NO_SHOW_ICON__	
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_QUESTION,
        CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_QUE"__MMI_RES_TYPE_POPUP_SCREEN__,
        "Question Mark image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_SAVE,
        CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_SAV"__MMI_RES_TYPE_POPUP_SCREEN__,
        "saved image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_DELETED,
        CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_DEL"__MMI_RES_TYPE_POPUP_SCREEN__,
        "deleted image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_WARNING,
        CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_WARN"__MMI_RES_TYPE_POPUP_SCREEN__,
        "warning image");
#if defined(__MMI_MAINLCD_128X64__) || defined(__MMI_FTE_SUPPORT__)
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_PROGRESS,
        CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_PRO",
        "Progress Image");
#else
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_PROGRESS,
        CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_PRO"__MMI_RES_TYPE_POPUP_SCREEN__,
        "Progress Image");
#endif
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_ERROR,
        CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_ERR"__MMI_RES_TYPE_POPUP_SCREEN__,
        "Error Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_INFO,
        CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_INF"__MMI_RES_TYPE_POPUP_SCREEN__,
        "Info Image");
    ADD_APPLICATION_IMAGE2(
        IMG_EARPHONE_POPUP_SUBLCD,
        CUST_IMG_PATH "\\\\SUBLCD\\\\Active\\\\SB_EAR.BMP",
        "Sub LCD Image Associated with Ear Phone Plug In Popup.");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_SUCCESS,
        CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_SUC"__MMI_RES_TYPE_POPUP_SCREEN__,
        "Success Image");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_FAIL,
        CUST_IMG_PATH "\\\\MainLCD\\\\Warningpage\\\\PopUpPage\\\\PP_FAIL"__MMI_RES_TYPE_POPUP_SCREEN__,
        "Failure Image");
#endif/*__MMI_POPUP_NO_SHOW_ICON__*/

    ADD_APPLICATION_IMAGE2(IMG_GLOBAL_DEFAULT, "..\\\\..\\\\Customer\\\\Images\\\\Default.bmp", "default image");
	//CSK icon slim
#ifndef __MMI_WGUI_DISABLE_CSK__
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_CALL_CSK,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Call_CSK.bmp",
        "call CSK icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_COMMON_CSK,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Common_CSK.bmp",
        "common CSK icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_DIAL_PAD_CSK,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Dial_Pad_CSK.bmp",
        "dial pad CSK icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_FORWARD_MSG_CSK,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Forward_Msg_CSK.bmp",
        "forward message CSK icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_MARK_CSK,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Mark_CSK.bmp",
        "mark CSK icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_NEXT_CSK,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Next_CSK.bmp",
        "next CSK icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_OPTION_CSK,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Option_CSK.bmp",
        "option CSK icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_REPLY_MSG_CSK,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Reply_Msg_CSK.bmp",
        "reply message CSK icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_SAVE_CSK,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Save_CSK.bmp",
        "save CSK icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_SEARCH_CSK,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Softkey\\\\SearchWeb_CSK.bmp",
        "search CSK icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_SEND_MSG_CSK,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Send_Msg_CSK.bmp",
        "send message CSK icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_OPTION_CSK,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Common_CSK.bmp",
        "option CSK icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_WEB_BROWSER_CSK,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Web_Browser_CSK.bmp",
        "web browser CSK icon");

    /* Remove these CSK icon after W10.17 - Start */
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_PHB_CSK,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Phonebook_CSK.bmp",
        "phonebook CSK icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_SELECT_CSK,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Select_CSK.bmp",
        "select CSK icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_VIEW_CSK,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Softkey\\\\View_CSK.bmp",
        "view CSK icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_READ_MSG_CSK,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Read_Msg_CSK.bmp",
        "read message CSK icon");

    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_BOOKMARK_CSK,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Bookmark_CSK.bmp",
        "bookmark CSK icon");
    /* Remove these CSK icon after W10.17 - End */
#endif/*__MMI_WGUI_DISABLE_CSK__*/

//icon bar icon slim
#ifdef __MMI_ICON_BAR_SUPPORT__
#ifdef __MMI_FTE_SUPPORT__
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_ADD_CONTACT,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_add_contact.png",
        "AddContact ToolBar icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_ADD_CONTACT_DISABLED,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_add_contact_dis.png",
        "AddContact ToolBar disabled icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_ADD,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_add_new.png",
        "Add ToolBar icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_ADD_DISABLED,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_add_new_dis.png",
        "Add ToolBar disabled icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_ATTACHMENT,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_attachment.png",
        "Attachment ToolBar icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_ATTACHMENT_DISABLED,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_attachment_dis.png",
        "Attachment ToolBar disabled icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_BOOKMARK,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_bookmark.png",
        "Bookmark ToolBar icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_BOOKMARK_DISABLED,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_bookmark_dis.png",
        "Bookmark ToolBar disabled icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_CALL,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_call.png",
        "Call ToolBar icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_CALL_DISABLED,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_call_dis.png",
        "Call ToolBar disabled icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_DELETE,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_delete.png",
        "Delete ToolBar icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_DELETE_DISABLED,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_delete_dis.png",
        "Delete ToolBar disabled icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_DETAIL,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_detail.png",
        "Detail ToolBar icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_DETAIL_DISABLED,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_detail_dis.png",
        "Detail ToolBar disabled icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_EDIT,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_edit_data.png",
        "Edit ToolBar icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_EDIT_DISABLED,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_edit_data_dis.png",
        "Edit ToolBar disabled icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_FORWARD_MESSAGE,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_forward_message.png",
        "Forward ToolBar icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_FORWARD_MESSAGE_DISABLED,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_forward_message_dis.png",
        "Forward ToolBar disabled icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_MEETING,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_meeting.png",
        "Meeting ToolBar icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_MEETING_DISABLED,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_meeting_dis.png",
        "Meeing ToolBar disabled icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_OPEN,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_open.png",
        "Open ToolBar icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_OPEN_DISABLED,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_open_dis.png",
        "Open ToolBar disabled icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_REPLY_MESSAGE,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_reply_message.png",
        "Reply ToolBar icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_REPLY_MESSAGE_DISABLED,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_reply_message_dis.png",
        "Reply ToolBar disabled icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_SEARCH,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_search.png",
        "Search ToolBar icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_SEARCH_DISABLED,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_search_dis.png",
        "Search ToolBar disabled icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_SEND_MESSAGE,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_send_message.png",
        "Send ToolBar icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_SEND_MESSAGE_DISABLED,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_send_message_dis.png",
        "Send ToolBar disabled icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_WRITE_MESSAGE,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_write_message.png",
        "Write ToolBar icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_WRITE_MESSAGE_DISABLED,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_write_message_dis.png",
        "Write ToolBar disabled icon");
#endif /* __MMI_FTE_SUPPORT__ */
#endif/*__MMI_ICON_BAR_SUPPORT__*/

    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_SIM1,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\SIM\\\\SIM1.bmp",
        "Global sim1 image for Gemini+");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_SIM2,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\SIM\\\\SIM2.bmp",
        "Global sim2 image for Gemini+");
#if (MMI_MAX_SIM_NUM >= 3)     
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_SIM3,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\SIM\\\\SIM3.bmp",
        "Global sim3 image for Gemini+");
#if (MMI_MAX_SIM_NUM == 4) 
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_SIM4,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\SIM\\\\SIM4.bmp",
        "Global sim4 image for Gemini+");
#endif /* (MMI_MAX_SIM_NUM == 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */


    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TABBAR_SIM1,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\SIM\\\\TAB\\\\Tab_sim1.bmp",
        "Global tabbar sim1 image for Gemini+");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TABBAR_SIM2,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\SIM\\\\TAB\\\\Tab_sim2.bmp",
        "Global tabbar sim2 image for Gemini+");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TABBAR_SIM3,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\SIM\\\\TAB\\\\Tab_sim3.bmp",
        "Global tabbar sim3 image for Gemini+");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TABBAR_SIM4,
        CUST_IMG_PATH "\\\\MainLCD\\\\UIElement\\\\SIM\\\\TAB\\\\Tab_sim4.bmp",
        "Global tabbar sim4 image for Gemini+");

    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_VIDEO_CALL,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_video_call.png",
        "Video call ToolBar icon");
    ADD_APPLICATION_IMAGE2(
        IMG_GLOBAL_TOOLBAR_VIDEO_CALL_DISABLED,
        CUST_IMG_PATH "\\\\MainLCD\\\\ToolBar\\\\TB_video_call_disabled.png",
        "Video call ToolBar disabled icon");
}
#endif

static int readline(FILE* f, U8 *line, int size)
{
	char c;
	int len = 0;
	
	while (len < size && (c = fgetc(f) ) != EOF && c != '\n')
	{
		line[len] = c;
        ++len;
		line[len] = '\0';
	}
	return len;
}
#ifdef __RESGEN_INTERNAL_3D_META_RESGEN_AUTO__
static void PopulateImage3DData()
{
    FILE * fp = NULL;
    fp = fopen("temp\\mmi_rp_image_populate_with_meta.txt", "r");
    if (fp == NULL)
    {
        return;
    }
	
    U8 line[2048];
    while (!feof(fp) )
    {
        int len = readline(fp, line, 2048);
        if (len != 0)
        {
            char *name = NULL;
            int id = 0;
            int i;
            for (i = 0; i < len; ++i)
            {
                if (line[i] == ' ')
                {
                    name = line + i + 1;
                    line[i] = '\0';
                    sscanf(line, "%d", &id);
                    ADD_APPLICATION_IMAGE2(id, name, "Generated by PopulateImage3DData()");
                    break;
                }
            }
        }
    }
    
}
#endif // __RESGEN_INTERNAL_3D_META_RESGEN_AUTO__

#ifndef __RESGEN_INTERNAL_3D_META_RESGEN_AUTO__
#define RESGEN_3D_RELOC_PY_FILE     "resgen_reloc_handle.py"
#define RESGEN_3D_RELOC_POP_FILE    "temp\\mmi_rp_binary3d_populate.txt"
#else
#define RESGEN_3D_RELOC_PY_FILE     "resgen_reloc_3d_dev_meta_handle.py"
#define RESGEN_3D_RELOC_POP_FILE    "temp\\mmi_rp_binary3d_populate_with_meta.txt"
#endif //__RESGEN_INTERNAL_3D_META_RESGEN_AUTO__

static void PopulateBinary3DData()
{
    FILE * fp = NULL;

    fflush (stdout);
    if(0 != execute_ext_command("..\\..\\..\\" "tools\\python25\\python" " " RESGEN_3D_RELOC_PY_FILE))
    {
        // Use RES_LOG_PENDING_FATAL provided by Resgn log framework 
        // instead of mtk_resgen_set_error
        // mtk_resgen_set_error();
        RESPOP_LOG_E("Error!! 3D resource reloc FAIL: external python script " RESGEN_3D_RELOC_PY_FILE " return error.");
        RES_LOG_PENDING_FATAL(RESPOP_TAG, "Error!! 3D Resource relocation FAIL !!","External python script " RESGEN_3D_RELOC_PY_FILE " return error.","Please check the error message of TAG Py-RESGEN_RELOC_3D_DEV_META_HANDLE in this log file");
        fprintf(stderr, "\n** Error!! External python script " RESGEN_3D_RELOC_PY_FILE " return error. \n** Please check the error message of the TAG Py-RESGEN_RELOC_3D_DEV_META_HANDLE in resgen_mtk_resgenerator_run.log\n");
    }
    fflush (stdout);

    // 3D Binary resource are pushed to offline DB.
    // That can be read by population script (resgen_populate.py) directly
    // There is no need to handle it here now.
    

}


void ResPopImageSlimInit(){
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0, j;
    unsigned char a[4];
    char path[] = CUST_IMG_PATH;
    char postfix[] = " 2>> .//debug//3rd_tool.log";
    char cmd[512];

    /* MTK Leo add */
    FILE *OutputImgDataFile = NULL;
    FILE *nfb_img_data_file = NULL;
    FILE *java_img_data_file = NULL;//100206 ENFB support

    /* MTK Leo end */

    //[Image][1] SLIM SUBMENU2 FILE COPY--------------------------------
    fprintf(stderr, "Start copy unzip images use copy_images.bat output 3rd_tool.txt\n");
    sprintf(cmd, "copy_images.bat ");
    j = 16;
    for (i = 0; i < strlen(path); i++)
    {
        if (!(path[i] == '\\' && path[i + 1] == '\\'))
        {
            cmd[j] = path[i];
            j++;
        }
    }
    cmd[j] = '\0';


    sprintf(cmd, "%s%s", cmd, postfix);
    execute_ext_command(cmd);
    //------------------------------------------------------------------
}

void ResPopNFBImageInit(){
    //[Image][2] NFB image population init -----------------------------
    // The output file will be CustNFBProgressImg.h CustNFBProgressImg.c
    int io_result = 0;
    FILE* nfb_img_res_file_local = NULL;
    nfb_img_res_file_local = fopen(NFB_IMAGE_RES_FILENAME, "w");
    RESPOP_LOG_V("ResPopNFBImageInit - start to write CustNFBProgressImg.c");

    if (nfb_img_res_file_local == NULL)
    {
        RESPOP_LOG_E("nfb_img_res_file_local could not open!\n");
    }
    else
    {
        RESPOP_LOG_V("ResPopNFBImageInit - write start pattern of CustNFBProgressImg.c");
        fprintf(nfb_img_res_file_local, "#include \"CustDataRes.h\" \n");
        fprintf(nfb_img_res_file_local, "#include \"CustNFBProgressImg.h\" \n");
        fprintf(nfb_img_res_file_local, "const U8* nfb_progress_images[]={\n");
        fflush(nfb_img_res_file_local);
        // Release nfb_img_res_file_local resource
        io_result = fclose(nfb_img_res_file_local);
        // nfb_img_res_file_local must be reset to NULL
        // Sinece resgen use the value to check if the NFB output file handle is available or not
        nfb_img_res_file_local = NULL;
        if(io_result !=0)
        {
            RESPOP_LOG_E("nfb_img_res_file_local close failed, err code of fcloase = %d", io_result);
        }
    }

    RESPOP_LOG_V("ResPopNFBImageInit -  start to write CustNFBProgressImg.h");
    nfb_img_data_file = fopen(NFB_IMAGE_DATA_FILENAME, "w");
    if (nfb_img_data_file == NULL)
    {
        RESPOP_LOG_E("nfb_img_data_file could not open!");
    }
    else
    {
        RESPOP_LOG_V("ResPopNFBImageInit - write start pattern of CustNFBProgressImg.h");
        fprintf(nfb_img_data_file, "#if ( !defined (__MTK_TARGET__) )\n\t#define __align(x)\n#endif\n");
        fflush(nfb_img_data_file);
        io_result = fclose(nfb_img_data_file);
        nfb_img_data_file = NULL;
        if(io_result !=0)
        {
            RESPOP_LOG_E("nfb_img_data_file close failed, err code of fcloase = %d", io_result);
        }
    }

    //------------------------------------------------------------------
}

void ResPopStringIdListInit(){
    //[String][3] String population init -------------------------------
    // Clean  CustStrList.txt
    StringListFile = fopen(CUS_STR_RES_FILENAME, "wb");
    if (StringListFile == NULL)
    {
        RESPOP_LOG_E("StringListFile could not open!");
    }
    //------------------------------------------------------------------
}


void ResPopImageIdListInit(){
    //[Image][4] Initialize images_file_list.ini -----------------------
    // Clean images_file_list.ini

    /* 091004 MTK Calvin added to reduce populate time */
    OutputImgIDFile = fopen(OUTPUT_IMAGE_ID_FILENAME, "w");
    if (OutputImgIDFile == NULL)
    {
        RESPOP_LOG_E("OutputImgIDFile could not open!");
        exit(2);
    }
    fclose(OutputImgIDFile);

    // Open and write the first line of images_file_list.ini
    OutputImgIDFile = fopen(OUTPUT_IMAGE_ID_FILENAME, "a");
    if (OutputImgIDFile == NULL)
    {
        RESPOP_LOG_E("OutputImgIDFile could not open again!");
    }
    fprintf(OutputImgIDFile, "[Image File List]\n");
    //------------------------------------------------------------------
}

void ResPopMenuIdListInit(){
    //[Menu][5] Initialize CustMenuTree output file---------------------
    // Clean CustMenuTreeID_Out.c		
    OutputMenutreeIDFile = fopen(OUTPUT_MENUTREE_ID_FILENAME, "w");
    if (OutputMenutreeIDFile == NULL)
    {
        RESPOP_LOG_E("OutputMenutreeIDFile could not open!");
    }
    fclose(OutputMenutreeIDFile);

    // Open  CustMenuTreeID_Out.c 
    // Init global veriabal OutputMenutreeIDFile
    OutputMenutreeIDFile = fopen(OUTPUT_MENUTREE_ID_FILENAME, "a");
    if (OutputMenutreeIDFile == NULL)
    {
        RESPOP_LOG_E("OutputMenutreeIDFile could not open again!");
    }
    /* MTK Calvin end */
    //------------------------------------------------------------------
}

void ResPopAudioIdListInit(){
    //[AUDIO][6] Initialize audio_file_list.ini  -----------------------
    // Clean audio_file_list.ini
    /* 101205 audio resource Calvin Satrt */
    OutputAdoIDFile = fopen(OUTPUT_AUDIO_ID_FILENAME, "w");
    if (OutputAdoIDFile == NULL)
    {
        RESPOP_LOG_E("OutputAdoIDFile could not open!");
        exit(2);
    }
    fclose(OutputAdoIDFile);

    // Open audio_file_list.ini
    // Initialize global variable OutputAdoIDFile
    OutputAdoIDFile = fopen(OUTPUT_AUDIO_ID_FILENAME, "a");
    if (OutputAdoIDFile == NULL)
    {
        RESPOP_LOG_E("OutputAdoIDFile could not open again!");
    }
    fprintf(OutputAdoIDFile, "[Audio File List]\n");
    /* 101205 audio resource Calvin End */
    //------------------------------------------------------------------
};


void ResPopBinaryIdListInit(){
    //[Binary][7] Initialize binary_file_list.ini-----------------------
    // Clean binary_file_list.ini
    OutputBinaryIDFile = fopen(OUTPUT_BINARY_ID_FILENAME, "w");
    if (OutputBinaryIDFile == NULL)
    {
        RESPOP_LOG_E("OutputBinaryIDFile could not open!");
        exit(0);
    }
    fclose(OutputBinaryIDFile);

    // Open binary_file_list.init
    // Initialize global variable OutputBinaryIDFile
    OutputBinaryIDFile = fopen(OUTPUT_BINARY_ID_FILENAME, "a");
    if (OutputBinaryIDFile == NULL)
    {
        RESPOP_LOG_E("OutputBinaryIDFile could not open again!");
    }
    fprintf(OutputBinaryIDFile, "[Binary File List]\n");
    //------------------------------------------------------------------
}

void ResPopSharedRepeadIdInit(){
    //[Shared][8] Initialize repeat_id_list.txt ------------------------		
    /* 102604 MTK Calvin added */
    // Clean repeat_id_list.txt
    // Initialize global variable RepeatIDListFile
    RepeatIDListFile = fopen(MMI_RG_REPEAT_ID_FILE, "w");
    if (RepeatIDListFile == NULL)
    {
        RESPOP_LOG_E("RepeatIDListFile could not open!");
        exit(2);
    }
    fclose(RepeatIDListFile);
    // Open repeat_id_list.txt for all resource population functions
    // Initialize global variable RepeatIDListFile
    RepeatIDListFile = fopen(MMI_RG_REPEAT_ID_FILE, "a");
    if (RepeatIDListFile == NULL)
    {
        RESPOP_LOG_E("RepeatIDListFile could not open again!");
        exit(2);
    }
    fprintf(RepeatIDListFile, "StrId\tEnum_Value\t\tString or Image\n");
    /* MTK Calvin end */
    //------------------------------------------------------------------
}

void ResPopFontObjListInit(){
    //[Font][9] Initialize font resource meta files---------------------		
    // Font log files:
    // MMI_RG_VF_OBJ_LIST_FILE				--> "vf_obj.txt"
    // MMI_RG_VF_MODIS_OBJ_LIST_FILE	--> "vf_modis_obj.txt"
    // MMI_RG_VF_TTF_LIST_FILE				--> "ttf_list.txt"

    // Clean vf_obj.txt
    font_data_lis = fopen(MMI_RG_VF_OBJ_LIST_FILE, "w");
    //fprintf(font_data_lis, "COMPOBJS += \n");
    MYFCLOSE(font_data_lis, MMI_RG_VF_OBJ_LIST_FILE);

    // Clean ttf_list.txt
    font_ttf_lis = fopen(MMI_RG_VF_TTF_LIST_FILE, "w");
    MYFCLOSE(font_ttf_lis, MMI_RG_VF_TTF_LIST_FILE);

    // Open ttf_list.txt for font population
    // initialize global variable font_ttf_lis
    font_ttf_lis = fopen(MMI_RG_VF_TTF_LIST_FILE, "a");

    // clean vf_modis_obj.txt
    font_data_lis = fopen(MMI_RG_VF_MODIS_OBJ_LIST_FILE, "w");    
    MYFCLOSE(font_data_lis, MMI_RG_VF_MODIS_OBJ_LIST_FILE);

    // open vf_modis_obj.txt
    // initialize global variable font_data_lis
    font_data_lis = fopen(MMI_RG_VF_OBJ_LIST_FILE, "a");

    // Open vf_obj.txt
    // initialize font_data_modis_lis
    font_data_modis_lis = fopen(MMI_RG_VF_MODIS_OBJ_LIST_FILE, "a");
    RESPOP_LOG_E("[FONT]vf_obj.txt open");
    //------------------------------------------------------------------
}

void ResPopMenuUsageMetaFileInit(){
#if !defined(PRODUCTION_RELEASE)
    //[Menu][10] Open Menu usage meta file (menu_resource_usage.txt)----
    // Open menu_resource_usage.txt
    // Initialize global variable fpMenuResourceUsage
    MYFOPEN(fpMenuResourceUsage, MMI_RG_MENU_USAGE_FILE, "w");
    // Print the title of menu resources
    PRTRESTITLE(fpMenuResourceUsage);
    //------------------------------------------------------------------
#endif //PRODUCTION_RELEASE
}

void ResPopImageUsageMetaFileInit(){
#if !defined(PRODUCTION_RELEASE)
    //[Image][11] Open Image usage meta file (image_resource_usage.txt)-
    // Open image_resource_usage.txt
    // Initialize global variable fpMenuResourceUsage
    MYFOPEN(fpImageResourceUsage, MMI_RG_IMAGE_USAGE_FILE, "w");
    MYFOPEN(fpImageResourceUsageExt, MMI_RG_IMAGE_CONVERTED_INFO_FILE, "w");
    // Print the title of image resources 
    PRTRESTITLE(fpImageResourceUsage);
    //------------------------------------------------------------------
#endif //PRODUCTION_RELEASE
}

void ResPopAudioUsageMetaFileInit(){
#if !defined(PRODUCTION_RELEASE)
    //[Audio][12] Open audio usage meta file (audio_resource_usage.txt)-
    // Open audio_resource_usage.txt
    // Initialize global resource fpAudioResourceUsage
    MYFOPEN(fpAudioResourceUsage, MMI_RG_AUDIO_USAGE_FILE, "w");
    // Print the title of audio resources
    PRTRESTITLE(fpAudioResourceUsage);
    //------------------------------------------------------------------
#endif //PRODUCTION_RELEASE
}

void ResPopStringUsageMetaFileInit(){
#if !defined(PRODUCTION_RELEASE)
    // [String][13] Open string usage meta file (string_resource.txt)
    // Open string_resource_usage.txt
    // Initialize global variable fpStringResourceUsage
    MYFOPEN(fpStringResourceUsage, MMI_RG_STRING_USAGE_FILE, "w");
    // Print the title of string resource
    PRTRESTITLE(fpStringResourceUsage);
    //------------------------------------------------------------------
#endif //PRODUCTION_RELEASE
}

void ResPopSharedPrintResBaseTable(){
    // [Shared][14] Print res based table (resource_base_table.txt)-----
#if !defined(PRODUCTION_RELEASE)
    /* Print resource base mapping table */
    U32 i = 0;
    FILE *fp;

    fp = fopen(MMI_RG_RES_BASE_TABLE_FILE, "w");
    if (fp != NULL)
    {
        fprintf(fp, "min\tmax\tappname\n");
        while (1)
        {
            if (strncmp(g_mmi_resource_base_table[i].appname, "END", 3) == 0)
            {
                break;
            }
            else
            {
                fprintf(fp, "%d\t%d\t%s\n",
                    g_mmi_resource_base_table[i].min,
                    g_mmi_resource_base_table[i].max,
                    g_mmi_resource_base_table[i].appname);
                i++;            
            }
        }
        fclose(fp);
    }

    fprintf(stderr, "output resource_base_table.txt done.\n");
    //------------------------------------------------------------------
#endif //PRODUCTION_RELEASE
}


// Dependendt global variable: java_img_data_file
void ResPopJavaGameDataFileInit(){
    // [Java][14] Clean Java image output file (CustGameDataHW.h)-------
    java_img_data_file = fopen(JAVA_GAME_FILENAME, "w");//100206 ENFB support
    if (java_img_data_file == NULL)
    {
        RESPOP_LOG_E("OutputAdoIDFile could not open!\n");
        exit(2);
    }
    fclose(java_img_data_file);
    //------------------------------------------------------------------
}


void ResPopStringIdListWriteHeader(){
    // [String][15] Initialize variables for string population----------
    unsigned char a[4];
    a[0] = 0xFF;
    a[1] = 0xFE;
    a[2] = 0x4E;
    a[3] = 0x00;

    // Output string list file header (unit code)
    fprintf(StringListFile, a);
    fprintf(StringListFile, "%c", a[3]);
    fwprintf(StringListFile, L"Number Of Languages\t1\r\n");
    fwprintf(StringListFile, L"Enum Value\tID\tDescription\tEnglish\r\n");
    //------------------------------------------------------------------
}

// Splitted from ClearHWIMageFile
void ResPopImageDataFileInit(){
    // [Image][16] Initialize the content of CustImgDataHW.h  ----------
    // Open and write init content of CustImgDataHW.h
    FILE * fp = fopen(OUTPUT_DATA_FILENAME, "w+");
    if (fp)
    {
        fprintf(fp, "#if ( !defined (__MTK_TARGET__) )\n\t#define __align(x)\n#endif\n");
        fclose(fp);
    }

    // Open and write init content of CustImgDataHWExt.h
    /* __CUSTPACK_MULTIBIN Calvin BEGIN */
    fp = fopen(OUTPUT_DATA_FILENAME_EXT, "w+"); /* 040805 CustPack: Calvin added */
    /* __CUSTPACK_MULTIBIN Calvin END */
    if (fp)
    {
        fprintf(fp, "#if ( !defined (__MTK_TARGET__) )\n\t#define __align(x)\n#endif\n");
#ifdef __CAT_SUPPORT__
        fprintf(fp,ResgenCATGetRegionStartStatment(MMIRESOURCE_CAT_RES_TYPE_ID_IMG));
#endif //__CAT_SUPPORT__
        fclose(fp);
    }
    //------------------------------------------------------------------
}

void ResPopAudioDataFileInit(){
    // [Audio][17] Initialize the content of CustAdoDataHW.h -----------
    // Open and write init content of CustAdoDataHW.h
    /* 101205 audio resource Calvin Satrt */
    FILE * fp = fopen(AUDIO_OUTPUT_DATA_FILENAME, "w+");
    if (fp)
    {
        fprintf(fp, "#if ( !defined (__MTK_TARGET__) )\n\t#define __align(x)\n#endif\n");
        fclose(fp);
    }
    // Open and write init content of CustAdoDataHWExt.h
    fp = fopen(AUDIO_OUTPUT_DATA_FILENAME_EXT, "w+");
    if (fp)
    {
        fprintf(fp, "#if ( !defined (__MTK_TARGET__) )\n\t#define __align(x)\n#endif\n");
#ifdef __CAT_SUPPORT__
        fprintf(fp,ResgenCATGetRegionStartStatment(MMIRESOURCE_CAT_RES_TYPE_ID_ADO));
#endif //__CAT_SUPPORT__
        fclose(fp);
    }
    /* 101205 audio resource Calvin End */
    //------------------------------------------------------------------
}

void ResPopFontDataFileInit(){
    // [Font][17] Initialize the content of CustFontDataHW.h ----------
    // Open and write init content of CustFontDataHW.h
    FILE *fp = fopen(FONT_OUTPUT_DATA_FILENAME, "w+");
    if (fp)
    {
        fprintf(fp, "#ifndef __CUSTFONTDATAHW_H__\n#define __CUSTFONTDATAHW_H__\n");
        fprintf(fp, "#if !defined(__MTK_TARGET__)\n    #define __align(x)\n#endif /* !defined(__MTK_TARGET__) */\n");
        fclose(fp);
    }
    //------------------------------------------------------------------
}

void ResPopImageENFBDataFileInit(){
    // [Image][18] Open the CustENFBImgData ----------------------------
    /* 100206 ENFB support Satrt */
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__

    // Open and clean the file CustENFBImgData
    enfb_img_data_file = fopen(ENFB_IMAGE_DATA_FILENAME, "w+");

    if (enfb_img_data_file)
    {
        fclose(enfb_img_data_file);
    }
    // Open custENFBImgData
    // initialize global variable enfb_img_data_file
    enfb_img_data_file = fopen(ENFB_IMAGE_DATA_FILENAME, "ab");
#endif
    /* 100206 ENFB support End */
}

void ResPopFontENFBDataFileInit(){
#ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
    enfb_font_data_file = fopen(ENFB_FONT_DATA_FILENAME, "w+");

    if (enfb_font_data_file)
    {
        fclose(enfb_font_data_file);
    }
    
    enfb_font_data_file = fopen(ENFB_FONT_DATA_FILENAME, "ab");
#endif
}


void ResPopImageCurrIndexInit(){
    // [Image][19] Init global data for image population ---------------
    /* 101205 audio resource Calvin Satrt */
    CurrMaxImageId = 0;
    CurrMaxImageNum = 0;
    /* __CUSTPACK_MULTIBIN Calvin BEGIN */
    CurrMaxImageIdEXT = 0;  /* 040805 CustPack: Calvin added */
    CurrMaxImageNumEXT = 0;
    /* __CUSTPACK_MULTIBIN Calvin END */
    //------------------------------------------------------------------
}

void ResPopFontCurrIndexInit(){ 
    // [Font][19] Init global data for font population -----------------
    CurrMaxFontIdEXT = 0;
    CurrMaxFontNumEXT = 0; 
    //------------------------------------------------------------------
}

void ResPopAudioCurrIndexInit(){ 
    // [Audio][22] Init global data for audio population ---------------
    CurrMaxAudioId = 0;
    CurrMaxAudioNum = 0;
    CurrMaxAudioIdEXT = 0;
    CurrMaxAudioNumEXT = 0;
    //------------------------------------------------------------------
}

void ResPopMenuCurrIndexInit(){
    // [Menu][23] Init global data for Menu population -----------------
    CurrMaxMenuItemIndex = MAX_MENU_ITEMS;
    /* 101205 audio resource Calvin End */
    //------------------------------------------------------------------
}


void ResPopSharedENFBCurrIndexInit(){
    // [Shared][24] Init global data for ENFB population----------------
    /* 101806 E-NFB start */
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    CurrMaxENFBAssociatedIDNum = 0;
#endif
    /* 101806 E-NFB end */
    //------------------------------------------------------------------
}

void ResPopStringCurrIndexInit(){
    // [String][25] Init global data for string population--------------
    /* to read from NVRAM if possible -vanita */
    gCurrLangIndex = 0;
    //------------------------------------------------------------------
}


void ResPopMenuParentIdsInit(){
    // [Menu][26] Init global data for font population--------------
    int i = 0;
    memset(nCustMenus, 0, sizeof(CUSTOM_MENU) * MAX_MENU_ITEMS);
    /* init nParentId with an impossible value */
    for (i = 0; i < MAX_MENU_ITEMS; i++)
    {
        nCustMenus[i].nParentId = MAX_MENU_ITEMS;            
    }
    //------------------------------------------------------------------
}

void ResPopStingCompressInit(){
    // [String][27] Init configuration settings for string population---
    /* Resource compression support */
    int i = 0;
    memset(mmi_res_zip_language, 0, sizeof(U8)*(MAX_LANGUAGES+1));

#if defined( __MMI_RESOURCE_STR_COMPRESS__ )
    for(i = 0 ; i <=MAX_LANGUAGES; i++ ){
        mmi_res_zip_language[i] = 1;
    }
#endif //__MMI_RESOURCE_STR_COMPRESS__
    //------------------------------------------------------------------
}

void ResPopMenuHandlersInit(){
    // [Menu][28] Init global variables for Hint handler population ----		
    /* Menuitem reduce memory, move registe hilite handlers to resgen */
    memset(nMenuHiliteHandlers, 0, sizeof(RESGEN_MENU_HILITE_HANDLER) * MAX_MENU_ITEMS);
    memset(nMenuHintHandlers, 0, sizeof(RESGEN_MENU_HINT_HANDLER) * MAX_MENU_ITEMS);    
    //------------------------------------------------------------------
}

void ResPopImageIdMapInit(){
    // [Image][29] Init global variables for image population -----------		
    int i = 0;
    fprintf(stderr, "Populate Resource 0%%\n");
    // initialize ImageIdMap and ImageIdMapEXT
    for (i = 0; i < MAX_IMAGE_IDS_SIZE; i++)
    {
        ImageIdMap[i].nImageNum = -1;
        /* __CUSTPACK_MULTIBIN Calvin BEGIN */
        ImageIdMapEXT[i].nImageNum = -1;    /* 040805 CustPack: Calvin added */
        /* __CUSTPACK_MULTIBIN Calvin END */
    }
}

void ResPopFontIdMapInit(){
    // [Font][30] Init global variables for font population -----------
    // initialize FontIdMapEXT	
    int i = 0;
    for (i = 0; i < MAX_FONT_IDS_SIZE; i++)
    {
        FontIdMapEXT[i].nFontNum = -1;    /* LangPack */
    }
    //------------------------------------------------------------------
}

void ResPopAudioIdMapInit(){
    // [Audio][31] Init global variables for Audio population ----------		   
    /* 101205 audio resource Calvin Satrt */
    // init AudioIdMap and AudioIdMapEXT
    int i =0;
    for (i = 0; i < MAX_AUDIO_IDS_SIZE; i++)
    {
        AudioIdMap[i].nAudioNum = -1;
        AudioIdMapEXT[i].nAudioNum = -1;
    }
    /* 101205 audio resource Calvin End */
    //------------------------------------------------------------------
}

void ResPopInitAll(){
    //[Image][0] SLIM SUBMENU2 FILE COPY
    ResPopImageSlimInit();

    //[Image][1] NFB image population init -----------------------------
    ResPopNFBImageInit();

    //[String][2] String population init -------------------------------
    ResPopStringIdListInit();

    //[Image][3] Initialize images_file_list.ini -----------------------
    ResPopImageIdListInit();

    //[Menu][4] Initialize CustMenuTree output file---------------------
    ResPopMenuIdListInit();

    //[AUDIO][5] Initialize audio_file_list.ini  -----------------------
    ResPopAudioIdListInit();

    //[Binary][6] Initialize binary_file_list.ini-----------------------
    ResPopBinaryIdListInit();

    //[Shared][7] Initialize repeat_id_list.txt ------------------------		
    ResPopSharedRepeadIdInit();

    //[Font][8] Initialize font resource meta files---------------------		
    ResPopFontObjListInit();

    //[Menu][9] Open Menu usage meta file (menu_resource_usage.txt)----
    ResPopMenuUsageMetaFileInit();

    //[Image][10] Open Image usage meta file (image_resource_usage.txt)-
    ResPopImageUsageMetaFileInit();

    //[Audio][11] Open audio usage meta file (audio_resource_usage.txt)-
    ResPopAudioUsageMetaFileInit();

    // [String][12] Open string usage meta file (string_resource.txt)
    ResPopStringUsageMetaFileInit();

    // [Shared][13] Print res based table (resource_base_table.txt)-----
    ResPopSharedPrintResBaseTable();

    // [Java][14] Clean Java image output file (CustGameDataHW.h)-------
    ResPopJavaGameDataFileInit();

    // [String][15] Initialize variables for string population----------
    ResPopStringIdListWriteHeader();

    // [Image][16] Initialize the content of CustImgDataHW.h  ----------
#ifndef __POPULATE_NO_IMAGE_DATA__
    ResPopImageDataFileInit();
#endif

    // [Audio][17] Initialize the content of CustAdoDataHW.h -----------
    ResPopAudioDataFileInit();

    // [Font][18] Initialize the content of CustFontDataHW.h ----------
    ResPopFontDataFileInit();

    // [Image][19] Open the CustENFBImgData ----------------------------	
    ResPopImageENFBDataFileInit();

    ResPopFontENFBDataFileInit();

#ifndef __POPULATE_ENGINE_
    SendMessage(hWnd, WM_CLEARFILES, (WPARAM) 0, (LPARAM) 0);
#endif

    // [Image][20] Init global data for image population ---------------
    ResPopImageCurrIndexInit();

    // [Font][21] Init global data for font population -----------------
    ResPopFontCurrIndexInit();

    // [Audio][22] Init global data for audio population ---------------
    ResPopAudioCurrIndexInit();

    // [Menu][23] Init global data for Menu population -----------------
    ResPopMenuCurrIndexInit();

    // [Shared][24] Init global data for ENFB population---------------- 
    ResPopSharedENFBCurrIndexInit();

    // [String][25] Init global data for string population--------------
    ResPopStringCurrIndexInit();

    // [Menu][26] Init global data for font population--------------	
    ResPopMenuParentIdsInit();

    // [String][27] Init configuration settings for string population---
    ResPopStingCompressInit();

    // [Menu][28] Init global variables for Hint handler population ----		
    ResPopMenuHandlersInit();

    // [Image][29] Init global variables for image population -----------		 
    ResPopImageIdMapInit();

    // [Font][30] Init global variables for font population -----------
    ResPopFontIdMapInit();

    // [Audio][31] Init global variables for Audio population ----------           
    ResPopAudioIdMapInit();

    // [Shared][32] Populat default resources --------------------------
    ResPopSharedDefaultResourceInit();

}

void ResPopImageBinaryExecPostActions(){
    // [Image][Binary][34] Executed posted image/binary population -----		   
    // res img post processing
#ifndef __POPULATE_NO_IMAGE_DATA__
    FILE * extImgFp = NULL;
    RESPOP_LOG_V("ResPopImageBinaryExecPostActions: Start post image/binary population");
    fflush(stdout);
    ProcessResgenPngImages();
    RESPOP_LOG_V("ResPopImageBinaryExecPostActions: Fininished post image/binary population");
    fflush(stdout);
    extImgFp = fopen(OUTPUT_DATA_FILENAME_EXT, "a"); /* 040805 CustPack: Calvin added */
    if (extImgFp != NULL)
    {
    	
#ifdef __CAT_SUPPORT__
        fprintf(extImgFp,ResgenCATGetRegionEndStatment());
#endif // __CAT_SUPPORT__
        fclose(extImgFp);
    }
#else //__POPULATE_NO_IMAGE_DATA__
    ProcessResgenPngImages();
#endif //__POPULATE_NO_IMAGE_DATA__
    // -----------------------------------------------------------------
}

void ResPopNFBImageDeinit(){
    // [Image][35] Deinit NFB imgage data file output ------------------		   
    // The output file is CustNFBProgressImg.c
    int io_result = 0;
    FILE* nfb_img_res_file_local = NULL;  // Use stack variable instaed of original gloabl variable design

    RESPOP_LOG_V("ResPopNFBImageDeinit - finishing CustNFBProgressImg.c output ...");

    // Open NFB output file 
    RESPOP_LOG_V("ResPopNFBImageDeinit - Open file: %s ", NFB_IMAGE_RES_FILENAME);
    fflush(stdout);
    nfb_img_res_file_local = fopen(NFB_IMAGE_RES_FILENAME, "a");

    // Show File desciptor value in output
    RESPOP_LOG_V("ResPopNFBImageDeinit - File descriptor of %s: 0x%x", NFB_IMAGE_RES_FILENAME, nfb_img_res_file_local);
    fflush(stdout);

    if (nfb_img_res_file_local != NULL)
    {
        extern MMI_BOOL g_mmi_res_nfb_used;

        if (g_mmi_res_nfb_used == FALSE)
        {
            RESPOP_LOG_V("ResPopNFBImageDeinit - No nfb resource declared, output NULL to resource array");
            fprintf(nfb_img_res_file_local, "NULL\n");
        }
		
        io_result = fprintf(nfb_img_res_file_local, "\n};\n");
        RESPOP_LOG_V("Write the end pattern of CustNFBProgressImg.c");
        fflush(stdout);

        if(io_result < 0)
        {
            RESPOP_LOG_E("Writting the end pattern of CustNFBProgressImg.c is failed");
            fflush(stdout);
        }

        RESPOP_LOG_V("ResPopNFBImageDeinit - Close file: %s, File descriptor: 0x%x", NFB_IMAGE_RES_FILENAME, nfb_img_res_file_local);
        fflush(stdout);
        fflush(nfb_img_res_file_local);		
        fclose(nfb_img_res_file_local);
    }else{
        RESPOP_LOG_E("FD of CustNFBProgressImg.c (nfb_img_res_file_local) can't be NULL!!");
        fflush(nfb_img_res_file_local);	
    }
    // -----------------------------------------------------------------
}

void ResPopStringIdListDeinit(){
    // [String][36] Finihsed String list file output(CustStrList.txt)---
    /*  for generate string list file in first pass */
    fwprintf(StringListFile, L"##number\t%d\r\n", CurrMaxStringId);
    fclose(StringListFile);
    // -----------------------------------------------------------------
}

void ResPopImageIdListDeinit(){
    // [Image][37] Deinit images_file_list.ini output-------------------
    /* 091004 MTK Calvin added to reduce populate time */
    fclose(OutputImgIDFile);
    // -----------------------------------------------------------------
}

void ResPopAudioIdListDeinit(){
    // [Audio][38] Deinit audio_file_list.ini output-------------------
    /* 101205 audio resource Calvin Satrt */
    fclose(OutputAdoIDFile);
    /* 101205 audio resource Calvin End */
    // -----------------------------------------------------------------
}


void ResPopBinaryIdListDeinit(){
    // [Binary][39] Deinit binary_file_list.ini output------------------
    fclose(OutputBinaryIDFile);
    // -----------------------------------------------------------------
}

void ResPopMenuUsageMetaFileDeinit(){
#if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE)
    // [Menu][40] Deinit menu_resource_usage.txt output-----------------
    MYFCLOSE(fpMenuResourceUsage, MMI_RG_MENU_USAGE_FILE);
    // -----------------------------------------------------------------
#endif // _POPULATE_RES_C && PRODUCTION_RELEASE
}

void ResPopImageUsageMetaFileDeinit(){
#if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE)
    // [Image][41] Deinit image_resource_usage.txt output---------------   
    MYFCLOSE(fpImageResourceUsage, MMI_RG_IMAGE_USAGE_FILE);
    MYFCLOSE(fpImageResourceUsageExt, MMI_RG_IMAGE_CONVERTED_INFO_FILE);
    // -----------------------------------------------------------------
#endif // _POPULATE_RES_C && PRODUCTION_RELEASE
}

void ResPopAudioUsageMetaFileDeinit(){
#if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE)
    // [Audio][42] Deinit audio_resource_usage.txt output--------------- 
    MYFCLOSE(fpAudioResourceUsage, MMI_RG_AUDIO_USAGE_FILE);
    // -----------------------------------------------------------------
#endif // _POPULATE_RES_C && PRODUCTION_RELEASE
}


void ResPopStringUsageMetaFileDeinit(){
#if defined(_POPULATE_RES_C) && !defined(PRODUCTION_RELEASE)
    // [String][43] Deinit string_resource_usage.txt output------------- 
    MYFCLOSE(fpStringResourceUsage, MMI_RG_STRING_USAGE_FILE);
    // -----------------------------------------------------------------
#endif // _POPULATE_RES_C && PRODUCTION_RELEASE
}

void ResPopMenuIdListDeinit(){
    // [Menu][44] Deinit CustMenuTreeID_Out.c output ------------------- 
    if(OutputMenutreeIDFile != NULL) fclose(OutputMenutreeIDFile);
    // -----------------------------------------------------------------
}

void ResPopSharedRepeadIdListDeinit(){
    // [Shared][45] Deinit repeat_id_list.txt output--------------------
    if(RepeatIDListFile != NULL) fclose(RepeatIDListFile);   /* 102604 MTK Calvin added */
    /* MTK Calvin end */
    // -----------------------------------------------------------------
}

void ResPopAudioDeinit(){
    // [Audio][34] Deinit CustAdoDataHwExt.h output------------------------
    FILE * extAudioFp = NULL;
    extAudioFp = fopen(AUDIO_OUTPUT_DATA_FILENAME_EXT, "a");
    if (extAudioFp != NULL)
    {
#ifdef __CAT_SUPPORT__
        fprintf(extAudioFp,ResgenCATGetRegionEndStatment());
#endif //__CAT_SUPPORT__
        fclose(extAudioFp);
    }
    // -----------------------------------------------------------------
}


void ResPopImageENFBDataFileDeinit(){
    // [Image][46] Deinit CustENFBImgData output------------------------
#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    if(enfb_img_data_file != NULL) fclose(enfb_img_data_file);//100206 ENFB support
#endif
}

void ResPopFontENFBDataFileDeinit(){
#ifdef __MMI_FONT_THIRD_ROM_SUPPORT__
    if(enfb_font_data_file != NULL) fclose(enfb_font_data_file);
#endif
}

void ResPopFontObjListDeInit(){
    // [Font][47] Deinit Font obj list output -------------------------- 
    MYFCLOSE(font_data_lis, MMI_RG_VF_OBJ_LIST_FILE);
    MYFCLOSE(font_data_modis_lis, MMI_RG_VF_MODIS_OBJ_LIST_FILE);
    MYFCLOSE(font_ttf_lis, MMI_RG_VF_TTF_LIST_FILE);
    fprintf(stderr, "Populate Resource 100%%\n");
    RESPOP_LOG_V("[FONT]font_data_lis close ");
    // -----------------------------------------------------------------
}
void ResPopFontDataFileDeInit(){
	// [Font]Deinit CustFontDataHW.h output --------------------------
	FILE *fp = fopen(FONT_OUTPUT_DATA_FILENAME, "a");
    if (fp)
    {
        fprintf(fp, "\n#define POP_FONT_FILES %d\n\n",CurrMaxFontNumEXT);
        fprintf(fp, "#endif /* __CUSTFONTDATAHW_H__ */\n");
        fclose(fp);
    }
	
	RESPOP_LOG_V("[FONT]CustFontDataHW.h deinit");
}

void ResPopDeinitAll(){
    // [Image][Binary][34] Executed posted image/binary population -----		   
    ResPopImageBinaryExecPostActions();

    // [Audio][34] Deinit CustAdoDataHwExt.h output------------------------
    ResPopAudioDeinit();

    // [Image][35] Deinit NFB imgage data file output ------------------		   
    ResPopNFBImageDeinit();

    // [String][36] Finihsed String list file output(CustStrList.txt)---
    ResPopStringIdListDeinit();

    // [Image][37] Deinit images_file_list.ini output-------------------
    ResPopImageIdListDeinit();

    // [Audio][38] Deinit audio_file_list.ini output-------------------
    ResPopAudioIdListDeinit();

    // [Binary][39] Deinit binary_file_list.ini output------------------
    ResPopBinaryIdListDeinit();

    // [Menu][40] Deinit menu_resource_usage.txt output-----------------
    ResPopMenuUsageMetaFileDeinit();

    // [Image][41] Deinit image_resource_usage.txt output---------------   
    ResPopImageUsageMetaFileDeinit();

    // [Audio][42] Deinit audio_resource_usage.txt output--------------- 
    ResPopAudioUsageMetaFileDeinit();

    // [String][43] Deinit string_resource_usage.txt output------------- 
    ResPopStringUsageMetaFileDeinit();

    // [Menu][44] Deinit CustMenuTreeID_Out.c output ------------------- 
    ResPopMenuIdListDeinit();

    // [Shared][45] Deinit repeat_id_list.txt output -------------------
    ResPopSharedRepeadIdListDeinit();

    // [Image][46] Deinit CustENFBImgData output------------------------
    ResPopImageENFBDataFileDeinit();

    // [Font][47] Deinit Font obj list output -------------------------- 
    ResPopFontObjListDeInit();	
    
    // [Font]Deinit CustFontDataHW.h output --------------------------
    ResPopFontDataFileDeInit();		

    ResPopFontENFBDataFileDeinit();
}

#else /* DEVELOPER_BUILD_FIRST_PASS */ 


#include "mmi_frm_gprot.h"

#if defined(__MMI_RESOURCE_STR_LZMA_COMPRESS__)
    #include "CompressResUtil.h"
#endif //__MMI_RESOURCE_STR_LZMA_COMPRESS__

#ifdef __MMI_RESOURCE_IMAGE_GROUP_COMPRESS__
    #include "ResCacheUtil.h"
#endif //__MMI_IMAGE_GROUP_COMPRESS__
#if defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__) || defined(__MMI_RESOURCE_AUDIO_COMPRESS__) || defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_RESOURCE_IMAGE_COMPRESS__) || defined(__DSP_COMPRESS__)


#include "simple_memory_manager.h"
#include "drv_gfx_stack_switch_manager.h"
#include "app_zlib.h"
#include "init_memory_stack.h"
#include "App_mem_med.h"

#define RESORCE_DECOMPRESS_WORKING_BUFFER_SIZE     (100 * 1024)
static STSMM _resource_decompress_smm;


static void *mmi_res_unzip_malloc(void *opaque, unsigned int items, unsigned int size)
{
    unsigned int total_bytes;
    void *buffer_ptr = NULL;
    
    if (opaque)
    {
        items += size - size;   /// make compiler happy
    }
    total_bytes = items * size;
    
    buffer_ptr = smmMallocAligned(&_resource_decompress_smm, total_bytes, 4);

    ASSERT(buffer_ptr != NULL);

    return buffer_ptr;

}



static void mmi_res_unzip_free(void *opaque, void *address)
{
    return;
}




S32 mmi_res_decompress(U8 *dest, U32 destLen, const U8 *source, U32 sourceLen, void *pool_addr)
{
    S32 ret;
    U32 decpz_data_size = destLen;
    U32 size;

    ASSERT(pool_addr != NULL);

    smmInit(&_resource_decompress_smm, pool_addr, RESORCE_DECOMPRESS_WORKING_BUFFER_SIZE);
        
#if defined(__MTK_TARGET__)
        {
            /// try to switch stack for better performance
            kal_uint32 stack_size = JPEG_STACK_SIZE;
            void *stack_ptr = drv_gfx_stkmgr_get_stack(stack_size);
            
            if (stack_ptr)
            {
                ret = INT_SwitchStackToRun(stack_ptr, stack_size, (kal_func_ptr)uncompress_mtk, 6,
                    dest, (uLongf*)&decpz_data_size,
                    source, sourceLen, 
                    mmi_res_unzip_malloc, mmi_res_unzip_free);
                
                drv_gfx_stkmgr_release_stack(stack_ptr);
            }
            else
            {
                ret = uncompress_mtk(dest, (uLongf*)&decpz_data_size, source, sourceLen, 
                    mmi_res_unzip_malloc, mmi_res_unzip_free);
            }
        }
#else
        ret = uncompress_mtk(dest, (uLongf*)&decpz_data_size, source, sourceLen, 
                    mmi_res_unzip_malloc, mmi_res_unzip_free);
#endif
            
        ASSERT(0 == ret);
        ASSERT(decpz_data_size == destLen);

        return 0;
}

#endif /* __MMI_RESOURCE_STR_ZLIB_COMPRESS__ || __MMI_RESOURCE_AUDIO_COMPRESS__ || __MMI_FONT_COMPRESSION__ || __MMI_RESOURCE_IMAGE_COMPRESS__ || __DSP_COMPRESS__ */


#ifdef __MMI_RESOURCE_AUDIO_COMPRESS__
extern const unsigned short mmi_res_zip_aud_count;
extern const res_compress_list_struct mmi_res_zip_aud_struct[];
#endif /* __MMI_RESOURCE_AUDIO_COMPRESS__ */


#ifdef __MMI_RESOURCE_IMAGE_COMPRESS__
extern const unsigned short mmi_res_zip_img_count;
extern const res_compress_list_struct mmi_res_zip_img_struct[];
#endif /* __MMI_RESOURCE_IMAGE_COMPRESS__ */



/***************************************************************************** 
*
* Not FIRST_PASS, for MMI to get global resource info
*
*****************************************************************************/
U16 CurrMaxStringNum;
U32 CurrTotalStrLen;
U16 CurrMaxStringId;
U16 CurrMaxStringIdSearch;
U16 gCurrLangIndex;

MMI_BOOL g_is16bit;
#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
MMI_BOOL g_isf16bit; /* fixed string 16bit flag */
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

static MMI_BOOL mmi_res_is_inited = MMI_FALSE;

const CUSTOM_STRING *gpStringRes;
const CUSTOM_STRING_MAP *gpStringMapRes;
const CUSTOM_STRING_MAP_16 *gpStringMapRes16;
const CUSTOM_STRMAP_SEARCH *gpStrMapSearch;
extern StringResList *gStringList;

#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
const CUSTOM_STRING *gpStringResDup;
U32 gMaxNonDupStrOffset;
extern U16 gMaxDeployedLangs;

/* fixed string */
const CUSTOM_STRING *gpFixedStringRes;
const CUSTOM_STRING_MAP *gpFixedStringMapRes;
const CUSTOM_STRING_MAP_16 *gpFixedStringMapRes16;
U16 CurrFixedMaxStringNum;
U16 CurrFixedMaxStringId;
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  PopulateResGetBaseIDTable
 * DESCRIPTION
 *  Dummy function to make ARM linker happy such that developers can access
 *  g_mmi_resource_base_table in Trace32/VC++ even though the variable is not used
 *  in other places.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void *PopulateResGetBaseIDTable(void)
{
#if !defined(PRODUCTION_RELEASE)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (void*)g_mmi_resource_base_table;
#else /* !defined(PRODUCTION_RELEASE) */ 
    return NULL;
#endif /* !defined(PRODUCTION_RELEASE) */ 
}

#ifdef __MMI_FONT_COMPRESSION__
#include "fontres.h"
extern mmi_font_compress_info *gFontZipInfo;
//extern const mmi_font_compress_info mtk_internal_font_compress_info[];
#endif /* __MMI_FONT_COMPRESSION__ */

#if defined(__MMI_RESOURCE_STR_THIRD_ROM__) || defined(__MMI_RESOURCE_STR_LZMA_COMPRESS__)
extern void mmi_res_load_string_data(S8 gCurrLangIndex);
#endif //__MMI_RESOURCE_STR_THIRD_ROM__ || __MMI_RESOURCE_STR_LZMA_COMPRESS__

/*****************************************************************************
 * FUNCTION
 *  PopulateResData
 * DESCRIPTION
 *  Populate Resource, assign resource info to global variable
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void PopulateResData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__) || defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_RESOURCE_AUDIO_COMPRESS__) || defined(__MMI_RESOURCE_IMAGE_COMPRESS__) || defined(__MMI_RESOURCE_STR_LZMA_COMPRESS__)
    S32 i;
    U32 tick_time = 0;
#endif

#if defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__) || defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_RESOURCE_AUDIO_COMPRESS__) || defined(__MMI_RESOURCE_IMAGE_COMPRESS__) 
    U32 size = RESORCE_DECOMPRESS_WORKING_BUFFER_SIZE;
#endif

    U32 tick_start = 0;
    void *buff_pool = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_res_is_inited)
        return;
#if defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__) || defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_RESOURCE_AUDIO_COMPRESS__) || defined(__MMI_RESOURCE_IMAGE_COMPRESS__)
    buff_pool = (void*)applib_asm_alloc_anonymous(size);
#endif
    
    mmi_res_dynamic_str_init();

    mmi_res_hide_dim_menu_init();

    kal_get_time(&tick_start);
    MMI_TRACE(MMI_FW_TRC_G2_GUI, MMI_RESGEN_ZIP_TIME_CHECK, 0, tick_start, tick_start* 4.615);

#ifndef __POPULATE_NO_STRING_DATA__
#if defined(__MMI_RESOURCE_STR_THIRD_ROM__) || defined(__MMI_RESOURCE_STR_LZMA_COMPRESS__)
    mmi_res_load_string_data(0);
#endif /* __MMI_RESOURCE_STR_LZMA_COMPRESS__ */
#endif

#ifdef __MMI_RESOURCE_STR_ZLIB_COMPRESS__
    kal_get_time(&tick_time);
    MMI_TRACE(MMI_FW_TRC_G2_GUI, MMI_RESGEN_ZIP_TIME_CHECK, 1, tick_time, (tick_time - tick_start)* 4.615);
    i = 0; /* decompress default language, 'gCurrLangIndex = 0;' */
    if (gStringList[i].pStringResZip != NULL)
    {
        mmi_res_decompress((U8*)gStringList[i].pStringRes, gStringList[i].nResSize, (U8*)gStringList[i].pStringResZip, gStringList[i].nResZipSize, buff_pool);
        mmi_res_decompress((U8*)gStringList[i].pStringMap, gStringList[i].nMapSize, (U8*)gStringList[i].pStringMapZip, gStringList[i].nMapZipSize, buff_pool);
    }    
    i = gMaxDeployedLangs; /* decompress duplicate language */
    if (gStringList[i].pStringResZip != NULL)
    {
        mmi_res_decompress((U8*)gStringList[i].pStringRes, gStringList[i].nResSize, (U8*)gStringList[i].pStringResZip, gStringList[i].nResZipSize, buff_pool);
    }
    if(gStringList[i + 1].pStringResZip != NULL)
    {
        mmi_res_decompress((U8*)gStringList[i + 1].pStringRes, gStringList[i + 1].nResSize, (U8*)gStringList[i + 1].pStringResZip, gStringList[i + 1].nResZipSize, buff_pool);
        mmi_res_decompress((U8*)gStringList[i + 1].pStringMap, gStringList[i + 1].nMapSize, (U8*)gStringList[i + 1].pStringMapZip, gStringList[i + 1].nMapZipSize, buff_pool);
    }

    kal_get_time(&tick_time);
    MMI_TRACE(MMI_FW_TRC_G2_GUI, MMI_RESGEN_ZIP_TIME_CHECK, 1, tick_time, (tick_time - tick_start)* 4.615);
#endif /*__MMI_RESOURCE_STR_ZLIB_COMPRESS__*/

#ifdef __MMI_FONT_COMPRESSION__
    /* Font uncompress */
    for (i = 0; ; i++)
    {
        if (gFontZipInfo[i].org_data_ptr == NULL)
        {
            break;
        }

        mmi_res_decompress(gFontZipInfo[i].org_data_ptr, gFontZipInfo[i].org_data_size, gFontZipInfo[i].zip_data_ptr, gFontZipInfo[i].zip_data_size, buff_pool);
    }
    kal_get_time(&tick_time);
    MMI_TRACE(MMI_FW_TRC_G2_GUI, MMI_RESGEN_ZIP_TIME_CHECK, 4, tick_time, (tick_time - tick_start)* 4.615);
  /*      
    for (i = 0; ; i++)
    {
        if (mtk_internal_font_compress_info[i].org_data_ptr == NULL)
        {
            break;
        }
        
        mmi_res_decompress(mtk_internal_font_compress_info[i].org_data_ptr, mtk_internal_font_compress_info[i].org_data_size, mtk_internal_font_compress_info[i].zip_data_ptr, mtk_internal_font_compress_info[i].zip_data_size, buff_pool);
    }
*/
    kal_get_time(&tick_time);
    MMI_TRACE(MMI_FW_TRC_G2_GUI, MMI_RESGEN_ZIP_TIME_CHECK, 5, tick_time, (tick_time - tick_start)* 4.615);
        
#endif /* __MMI_FONT_COMPRESSION__ */

#ifdef __MMI_RESOURCE_AUDIO_COMPRESS__
    
    for(i=0; i< mmi_res_zip_aud_count; i++)
    {
        mmi_res_decompress(
            mmi_res_zip_aud_struct[i].zi_name, 
            mmi_res_zip_aud_struct[i].zi_len, 
            mmi_res_zip_aud_struct[i].ro_name, 
            mmi_res_zip_aud_struct[i].ro_len,
            buff_pool);
    }
    kal_get_time(&tick_time);
    MMI_TRACE(MMI_FW_TRC_G2_GUI, MMI_RESGEN_ZIP_TIME_CHECK, 2, tick_time, (tick_time - tick_start)* 4.615);
        
#endif /*__MMI_RESOURCE_AUDIO_COMPRESS__*/

#ifdef __MMI_RESOURCE_IMAGE_COMPRESS__

    for(i=0; i< mmi_res_zip_img_count; i++)
    {
        mmi_res_decompress(
            mmi_res_zip_img_struct[i].zi_name, 
            mmi_res_zip_img_struct[i].zi_len, 
            mmi_res_zip_img_struct[i].ro_name, 
            mmi_res_zip_img_struct[i].ro_len,
            buff_pool);
    }
    kal_get_time(&tick_time);
    MMI_TRACE(MMI_FW_TRC_G2_GUI, MMI_RESGEN_ZIP_TIME_CHECK, 3, tick_time, (tick_time - tick_start)* 4.615);
        
#endif /*__MMI_RESOURCE_IMAGE_COMPRESS__*/

#ifndef __POPULATE_NO_STRING_DATA__
    gCurrLangIndex = 0;
    gpStringRes = gStringList[gCurrLangIndex].pStringRes;
#ifndef __MMI_RESOURCE_ENFB_SUPPORT__
    gpStringResDup = gStringList[gMaxDeployedLangs].pStringRes;
    /* check if there are any duplicated strings generated */
    if (gpStringResDup)
    {
        /* on dup case, nTotalStrMap stores the high 16 bits and 
         * nTotalStrMapSearch stores the low 16 bits of max offset within non dup strings
         */
        gMaxNonDupStrOffset = (U32)gStringList[gMaxDeployedLangs].nTotalStrMap;
        gMaxNonDupStrOffset = gMaxNonDupStrOffset << 16;
        gMaxNonDupStrOffset += gStringList[gMaxDeployedLangs].nTotalStrMapSearch;
    }
    else
    {
        /* on non dup case, assign it as max value of U32 type to prevent GetString from accessing gpStringResDup */
        gMaxNonDupStrOffset = 0xFFFFFFFF;
    }

    /* fixed string */
    gpFixedStringRes = gStringList[gMaxDeployedLangs + 1].pStringRes;
    CurrFixedMaxStringNum = gStringList[gMaxDeployedLangs + 1].nTotalStrRes;
    g_isf16bit = gStringList[gMaxDeployedLangs + 1].is16bit;
    if(g_isf16bit)
        gpFixedStringMapRes16 = (CUSTOM_STRING_MAP_16 *)gStringList[gMaxDeployedLangs + 1].pStringMap;
    else
        gpFixedStringMapRes = (CUSTOM_STRING_MAP *)gStringList[gMaxDeployedLangs + 1].pStringMap;
    CurrFixedMaxStringId = gStringList[gMaxDeployedLangs + 1].nTotalStrMap;
#endif /* __MMI_RESOURCE_ENFB_SUPPORT__ */
    g_is16bit = gStringList[gCurrLangIndex].is16bit;
    if (g_is16bit)
        gpStringMapRes16 = (CUSTOM_STRING_MAP_16 *)gStringList[gCurrLangIndex].pStringMap;
    else
        gpStringMapRes = (CUSTOM_STRING_MAP *)gStringList[gCurrLangIndex].pStringMap;
    gpStrMapSearch = gStringList[gCurrLangIndex].pStrMapSearch;
    CurrMaxStringNum = gStringList[gCurrLangIndex].nTotalStrRes;
    CurrMaxStringId = gStringList[gCurrLangIndex].nTotalStrMap;
    CurrMaxStringIdSearch = gStringList[gCurrLangIndex].nTotalStrMapSearch;

#endif //__POPULATE_NO_STRING_DATA__

#if defined(__MMI_RESOURCE_STR_ZLIB_COMPRESS__) || defined(__MMI_FONT_COMPRESSION__) || defined(__MMI_RESOURCE_AUDIO_COMPRESS__) || defined(__MMI_RESOURCE_IMAGE_COMPRESS__)   
    applib_asm_free_anonymous(buff_pool);
#endif

    mmi_res_is_inited = MMI_TRUE;
    return;
}

#endif /* DEVELOPER_BUILD_FIRST_PASS */ 

