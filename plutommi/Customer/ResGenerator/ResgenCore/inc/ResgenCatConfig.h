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
 *   ResgenCatConfig.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Static configuration of Resgen CAT components 
 *
 * Author:
 * -------
 * -------
 *
*==============================================================================
 *                 HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifndef __RESGEN_CAT_CONFIG_H__
#define __RESGEN_CAT_CONFIG_H__
 
// Rserved space for the veriation of compression rate of string reosurce
#define MMIRESOURCE_CAT_STR_COMPRESS_RESERVED_MARGIN_SIZE_BYTE 20

// Reserved sacpce ZI space (runtime memory space) of string resource
// It should be set to 0 since the tool side has not support reserved space for 
// string resource
#define MMIRESORUCE_CAT_STR_COMPRESS_RESERVED_ZI_SIZE 0

// Reserved space for image resource, 
// it sould be set to 0 since the tool side havs not support reserved space for 
// image resource
#define MMIRESOURCE_CAT_IMG_RESERVED_SIZE_BYTE  0


// CAT Resource Type IDs
#define MMIRESOURCE_CAT_RES_TYPE_ID_IMG 0
#define MMIRESOURCE_CAT_RES_TYPE_ID_ADO 1
#define MMIRESOURCE_CAT_RES_TYPE_ID_STR 2	
#define MMIRESOURCE_CAT_RES_TYPE_ID_COMPRESSED_STR 3	

// Section names for CAT resources
#define MMIRESOURCE_CAT_RES_SECTION_NAME_IMG "CAT_RODATA_IMG"
#define MMIRESOURCE_CAT_RES_SECTION_NAME_ADO "CAT_RODATA_ADO"
#define MMIRESOURCE_CAT_RES_SECTION_NAME_STR "CAT_RODATA_STR"
#define MMIRESOURCE_CAT_RES_SECTION_NAME_STR_NO_ZIMAGE "CAT_RODATA_STR_NO_ZIMAGE"
    
#endif // __RESGEN_CAT_CONFIG_H__
