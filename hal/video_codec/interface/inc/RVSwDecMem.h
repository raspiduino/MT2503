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
 *   RVSwDecMem.h
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 ****************************************************************************/

#ifndef RVSWDECMEM_H
#define RVSWDECMEM_H
#ifdef __RM_DEC_SUPPORT__
#ifdef __cplusplus
extern "C"
    {
#endif


	#define RVSwDecExtSize_NOT_SUPPORT -1
#if defined(MT6236) || defined(MT6236B)	
	#define RVSwDecExtSize_128x96     (21*1024+1500)
	#define RVSwDecExtSize_176x144    (42*1024+1500)                        
	#define RVSwDecExtSize_320x240    (125*1024+1500)
	#define RVSwDecExtSize_400x240    (156*1024+1500)
	#define RVSwDecExtSize_352x288    (165*1024+1500)
	#define RVSwDecExtSize_432x240    (168*1024+1500)
	#define RVSwDecExtSize_480x320    (249*1024+1500)
	#define RVSwDecExtSize_640x368    (382*1024+1500)
	#define RVSwDecExtSize_640x480    (498*1024+1500)
	#define RVSwDecExtSize_720x480    (560*1024+1500)
	#define RVSwDecExtSize_800x480    (622*1024+1500)
	#define RVSwDecExtSize_848x480    (659*1024+1500)
	#define RVSwDecExtSize_720x576    (671*1024+1500)
	#define RVSwDecExtSize_800x608    (787*1024+1500)
	#define RVSwDecExtSize_1024x768   (1282*1024+1500)
	#define RVSwDecExtSize_1280x720   (1502*1024+1500)
	#define RVSwDecExtSize_1280x960   (2003*1024+1500)
	#define RVSwDecExtSize_1280x1024  (2136*1024+1500)
	#define RVSwDecExtSize_1408x1152  (2643*1024+1500)
	#define RVSwDecExtSize_1600x1200  (3129*1024+1500)
	#define RVSwDecExtSize_1920x1088  (3404*1024+1500)

	#define RVSwDecIntraModeExtSize_128x96     (21*1024+1500)
	#define RVSwDecIntraModeExtSize_176x144    (42*1024+1500)
	#define RVSwDecIntraModeExtSize_320x240    (125*1024+1500)
	#define RVSwDecIntraModeExtSize_400x240    (156*1024+1500)
	#define RVSwDecIntraModeExtSize_352x288    (165*1024+1500)
	#define RVSwDecIntraModeExtSize_432x240    (168*1024+1500)
	#define RVSwDecIntraModeExtSize_480x320    (249*1024+1500)
	#define RVSwDecIntraModeExtSize_640x368    (382*1024+1500)
	#define RVSwDecIntraModeExtSize_640x480    (498*1024+1500)
	#define RVSwDecIntraModeExtSize_720x480    (560*1024+1500)
	#define RVSwDecIntraModeExtSize_800x480    (622*1024+1500)
	#define RVSwDecIntraModeExtSize_848x480    (659*1024+1500)
	#define RVSwDecIntraModeExtSize_720x576    (671*1024+1500)
	#define RVSwDecIntraModeExtSize_800x608    (787*1024+1500)
	#define RVSwDecIntraModeExtSize_1024x768   (1282*1024+1500)
	#define RVSwDecIntraModeExtSize_1280x720   (1502*1024+1500)
	#define RVSwDecIntraModeExtSize_1280x960   (2003*1024+1500)
	#define RVSwDecIntraModeExtSize_1280x1024  (2136*1024+1500)
	#define RVSwDecIntraModeExtSize_1408x1152  (2643*1024+1500)
	#define RVSwDecIntraModeExtSize_1600x1200  (3129*1024+1500)
	#define RVSwDecIntraModeExtSize_1920x1088  (3404*1024+1500)

#elif (defined(MT6253T)||defined(MT6253))
	#define RVSwDecExtSize_128x96          (21*1024+1500)
	#define RVSwDecExtSize_176x144         (42*1024+1500)
	#define RVSwDecExtSize_320x240         (125*1024+1500)
	#define RVSwDecExtSize_400x240         (156*1024+1500)
	#define RVSwDecExtSize_352x288         (165*1024+1500)
	#define RVSwDecExtSize_432x240         (168*1024+1500)
	#define RVSwDecExtSize_480x320         (249*1024+1500)
	#define RVSwDecExtSize_640x368         (382*1024+1500)
	#define RVSwDecExtSize_640x480         (498*1024+1500)
	#define RVSwDecExtSize_720x480         (564*1024+1500)
	#define RVSwDecExtSize_800x480         (627*1024+1500)
	#define RVSwDecExtSize_848x480         (664*1024+1500)
	#define RVSwDecExtSize_720x576         (677*1024+1500)
	#define RVSwDecExtSize_800x608         (793*1024+1500)
	#define RVSwDecExtSize_1024x768        (1282*1024+1500)
	#define RVSwDecExtSize_1280x720        (1502*1024+1500)
	#define RVSwDecExtSize_1280x960        (2003*1024+1500)
	#define RVSwDecExtSize_1280x1024       (2136*1024+1500)
	#define RVSwDecExtSize_1408x1152       (2643*1024+1500)
	#define RVSwDecExtSize_1600x1200       (3129*1024+1500)
	#define RVSwDecExtSize_1920x1088       (3404*1024+1500)

	#define RVSwDecIntraModeExtSize_128x96          (21*1024+1500)
	#define RVSwDecIntraModeExtSize_176x144         (42*1024+1500)
	#define RVSwDecIntraModeExtSize_320x240         (125*1024+1500)
	#define RVSwDecIntraModeExtSize_400x240         (156*1024+1500)
	#define RVSwDecIntraModeExtSize_352x288         (165*1024+1500)
	#define RVSwDecIntraModeExtSize_432x240         (168*1024+1500)
	#define RVSwDecIntraModeExtSize_480x320         (249*1024+1500)
	#define RVSwDecIntraModeExtSize_640x368         (382*1024+1500)
	#define RVSwDecIntraModeExtSize_640x480         (498*1024+1500)
	#define RVSwDecIntraModeExtSize_720x480         (564*1024+1500)
	#define RVSwDecIntraModeExtSize_800x480         (627*1024+1500)
	#define RVSwDecIntraModeExtSize_848x480         (664*1024+1500)
	#define RVSwDecIntraModeExtSize_720x576         (677*1024+1500)
	#define RVSwDecIntraModeExtSize_800x608         (793*1024+1500)
	#define RVSwDecIntraModeExtSize_1024x768        (1282*1024+1500)
	#define RVSwDecIntraModeExtSize_1280x720        (1502*1024+1500)
	#define RVSwDecIntraModeExtSize_1280x960        (2003*1024+1500)
	#define RVSwDecIntraModeExtSize_1280x1024       (2136*1024+1500)
	#define RVSwDecIntraModeExtSize_1408x1152       (2643*1024+1500)
	#define RVSwDecIntraModeExtSize_1600x1200       (3129*1024+1500)
	#define RVSwDecIntraModeExtSize_1920x1088       (3404*1024+1500)
#elif defined(MT6253E)||defined(MT6253L)|| defined(MT6252H) || defined(MT6252)|| defined(MT6276) || defined(MT6575) || defined(MT6256) || defined(MT6235) || defined(MT6235B) || defined(MT6255)
	#define RVSwDecExtSize_128x96          ((34   + 2)*1024+1500)
	#define RVSwDecExtSize_176x144         ((55   + 2)*1024+1500)
	#define RVSwDecExtSize_320x240         ((140  + 2)*1024+1500)
	#define RVSwDecExtSize_400x240         ((172  + 2)*1024+1500)
	#define RVSwDecExtSize_352x288         ((180  + 2)*1024+1500)
	#define RVSwDecExtSize_432x240         ((185  + 2)*1024+1500)
	#define RVSwDecExtSize_480x320         ((266  + 2)*1024+1500)
	#define RVSwDecExtSize_640x368         ((401  + 2)*1024+1500)
	#define RVSwDecExtSize_640x480         ((517  + 2)*1024+1500)
	#define RVSwDecExtSize_720x480         ((581  + 2)*1024+1500)
	#define RVSwDecExtSize_800x480         ((644  + 2)*1024+1500)
	#define RVSwDecExtSize_848x480         ((682  + 2)*1024+1500)
	#define RVSwDecExtSize_720x576         ((693  + 2)*1024+1500)
	#define RVSwDecExtSize_800x608         ((810  + 2)*1024+1500)
	#define RVSwDecExtSize_1024x768        ((1301 + 2)*1024+1500)
	#define RVSwDecExtSize_1280x720        ((1523 + 2)*1024+1500)
	#define RVSwDecExtSize_1280x960        ((2023 + 2)*1024+1500)
	#define RVSwDecExtSize_1280x1024       ((2157 + 2)*1024+1500)
	#define RVSwDecExtSize_1408x1152       ((2664 + 2)*1024+1500)
	#define RVSwDecExtSize_1600x1200       ((3151 + 2)*1024+1500)
	#define RVSwDecExtSize_1920x1088       ((3429 + 2)*1024+1500) 

	#define RVSwDecIntraModeExtSize_128x96          ((34   + 2)*1024+1500)
	#define RVSwDecIntraModeExtSize_176x144         ((55   + 2)*1024+1500)
	#define RVSwDecIntraModeExtSize_320x240         ((140  + 2)*1024+1500)
	#define RVSwDecIntraModeExtSize_400x240         ((172  + 2)*1024+1500)
	#define RVSwDecIntraModeExtSize_352x288         ((180  + 2)*1024+1500)
	#define RVSwDecIntraModeExtSize_432x240         ((185  + 2)*1024+1500)
	#define RVSwDecIntraModeExtSize_480x320         ((266  + 2)*1024+1500)
	#define RVSwDecIntraModeExtSize_640x368         ((401  + 2)*1024+1500)
	#define RVSwDecIntraModeExtSize_640x480         ((517  + 2)*1024+1500)
	#define RVSwDecIntraModeExtSize_720x480         ((581  + 2)*1024+1500)
	#define RVSwDecIntraModeExtSize_800x480         ((644  + 2)*1024+1500)
	#define RVSwDecIntraModeExtSize_848x480         ((682  + 2)*1024+1500)
	#define RVSwDecIntraModeExtSize_720x576         ((693  + 2)*1024+1500)
	#define RVSwDecIntraModeExtSize_800x608         ((810  + 2)*1024+1500)
	#define RVSwDecIntraModeExtSize_1024x768        ((1301 + 2)*1024+1500)
	#define RVSwDecIntraModeExtSize_1280x720        ((1523 + 2)*1024+1500)
	#define RVSwDecIntraModeExtSize_1280x960        ((2023 + 2)*1024+1500)
	#define RVSwDecIntraModeExtSize_1280x1024       ((2157 + 2)*1024+1500)
	#define RVSwDecIntraModeExtSize_1408x1152       ((2664 + 2)*1024+1500)
	#define RVSwDecIntraModeExtSize_1600x1200       ((3151 + 2)*1024+1500)
	#define RVSwDecIntraModeExtSize_1920x1088       ((3429 + 2)*1024+1500)

#else
#error "not support V2 on this chip"
#endif
#endif

#ifdef __cplusplus
    }
#endif
#endif /* RVSWDECMEM_H */

