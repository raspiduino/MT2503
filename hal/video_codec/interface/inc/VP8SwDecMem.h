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
 *   VP8SwDecMem.h
 *
 * Project:
 * --------
 *	MTK
 *
 * Description:
 * ------------
 *   The API module user interface of the Decoder.
 *
 * Author:
 * -------
 * -------
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 ****************************************************************************/

#ifndef VP8SWDECMEM_H
#define VP8SWDECMEM_H

#ifdef __cplusplus
extern "C"
    {
#endif

#define VP8SwDecExtSize_128x96    (35213)
#define VP8SwDecExtSize_176x144   (40028)
#define VP8SwDecExtSize_240x192	  (47456)
#define VP8SwDecExtSize_320x240	  (58253)
#define VP8SwDecExtSize_400x240	  (65018)
#define VP8SwDecExtSize_352x288	  (66755)
#define VP8SwDecExtSize_432x240	  (67724)
#define VP8SwDecExtSize_480x320	  (84803)
#define VP8SwDecExtSize_640x368	  (112865)
#define VP8SwDecExtSize_640x480	  (136973)
#define VP8SwDecExtSize_720x480	  (150038)
#define VP8SwDecExtSize_800x480	  (163103)
#define VP8SwDecExtSize_848x480	  (170942)
#define VP8SwDecExtSize_864x480	  (173555)
#define VP8SwDecExtSize_720x576	  (173222)
#define VP8SwDecExtSize_800x608	  (197375)
#define VP8SwDecExtSize_1024x768  (297965)
#define VP8SwDecExtSize_1280x720  (343553)
#define VP8SwDecExtSize_1280x960  (445613)
#define VP8SwDecExtSize_1280x1024 (472829)
#define VP8SwDecExtSize_1408x1152 (576389)
#define VP8SwDecExtSize_1600x1200 (675533)
#define VP8SwDecExtSize_1920x1088 (732245)



#define VP8SwDecIntraModeExtSize_128x96	     VP8SwDecExtSize_128x96    
#define VP8SwDecIntraModeExtSize_176x144	 VP8SwDecExtSize_176x144   
#define VP8SwDecIntraModeExtSize_240x192	 VP8SwDecExtSize_240x192	  
#define VP8SwDecIntraModeExtSize_320x240	 VP8SwDecExtSize_320x240	  
#define VP8SwDecIntraModeExtSize_400x240	 VP8SwDecExtSize_400x240	  
#define VP8SwDecIntraModeExtSize_352x288	 VP8SwDecExtSize_352x288	  
#define VP8SwDecIntraModeExtSize_432x240	 VP8SwDecExtSize_432x240	  
#define VP8SwDecIntraModeExtSize_480x320	 VP8SwDecExtSize_480x320	  
#define VP8SwDecIntraModeExtSize_640x368	 VP8SwDecExtSize_640x368	  
#define VP8SwDecIntraModeExtSize_640x480	 VP8SwDecExtSize_640x480	  
#define VP8SwDecIntraModeExtSize_720x480	 VP8SwDecExtSize_720x480	  
#define VP8SwDecIntraModeExtSize_800x480	 VP8SwDecExtSize_800x480	  
#define VP8SwDecIntraModeExtSize_848x480	 VP8SwDecExtSize_848x480	  
#define VP8SwDecIntraModeExtSize_864x480	 VP8SwDecExtSize_864x480	  
#define VP8SwDecIntraModeExtSize_720x576	 VP8SwDecExtSize_720x576	  
#define VP8SwDecIntraModeExtSize_800x608	 VP8SwDecExtSize_800x608	  
#define VP8SwDecIntraModeExtSize_1024x768    VP8SwDecExtSize_1024x768  
#define VP8SwDecIntraModeExtSize_1280x720    VP8SwDecExtSize_1280x720  
#define VP8SwDecIntraModeExtSize_1280x960    VP8SwDecExtSize_1280x960  
#define VP8SwDecIntraModeExtSize_1280x1024   VP8SwDecExtSize_1280x1024 
#define VP8SwDecIntraModeExtSize_1408x1152   VP8SwDecExtSize_1408x1152 
#define VP8SwDecIntraModeExtSize_1600x1200   VP8SwDecExtSize_1600x1200 
#define VP8SwDecIntraModeExtSize_1920x1088   VP8SwDecExtSize_1920x1088 

#ifdef __cplusplus
    }
#endif
    
#endif /* VP8SWDECMEM_H */

