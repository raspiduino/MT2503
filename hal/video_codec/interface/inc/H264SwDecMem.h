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
 *   H264SwDecMem.h
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef H264SWDECMEM_H
#define H264SWDECMEM_H

#ifdef __cplusplus
extern "C"
    {
#endif


#if (defined(MT6235) || defined(MT6235B) || defined(MT6236) || defined(MT6236B) || defined(MT6256)  || defined(MT6276))
#define H264_FP1_SERIES
#endif

#if (defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252))
#define H264_FP2_SERIES
#endif

#if (defined(MT6575) || defined(MT6573))
#define H264_SP_SERIES
#endif

//#if (defined(MT6235) || defined(MT6235B) || defined(MT6236) || defined(MT6236B) || defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252) || defined(MT6256)  || defined(MT6276))
#if 1
//#if (defined(H264_FP2_SERIES) && defined(__SW_VIDEO_MAX_RESOLUTION__))
//    #define H264SwDecExtSize_128x96     (170*1024)
//    #define H264SwDecExtSize_176x144    (250*1024) 
//    #define H264SwDecExtSize_240x192    (375*1024)  
//    #define H264SwDecExtSize_320x240    (500*1024) 
//    #define H264SwDecExtSize_400x240    (600*1024) 
//    #define H264SwDecExtSize_352x288    (610*1024) 
//    #define H264SwDecExtSize_432x240    (620*1024) 
//    #define H264SwDecExtSize_480x320    (900*1024)  
//    #define H264SwDecExtSize_640x368    (900*1024) 
//    #define H264SwDecExtSize_640x480    (900*1024) 
//    #define H264SwDecExtSize_720x480    (900*1024) 
//    #define H264SwDecExtSize_800x480    (900*1024) 
//    #define H264SwDecExtSize_848x480    (900*1024) 
//    #define H264SwDecExtSize_864x480    (900*1024) 	 
//    #define H264SwDecExtSize_720x576    (900*1024)
//    #define H264SwDecExtSize_800x608    (900*1024)
//    #define H264SwDecExtSize_1024x768   (900*1024)
//    #define H264SwDecExtSize_1280x720   (900*1024)
//    #define H264SwDecExtSize_1280x960   (900*1024)
//    #define H264SwDecExtSize_1280x1024  (900*1024)
//    #define H264SwDecExtSize_1408x1152  (900*1024)
//    #define H264SwDecExtSize_1600x1200  (900*1024)
//    #define H264SwDecExtSize_1920x1088  (900*1024)
//#else /* (defined(H264_FP2_SERIES) && defined(__SW_VIDEO_MAX_RESOLUTION__)) */
   #define H264SwDecExtSize_128x96_BP     71052	  //70860		//(3*1024 +170*1024  -128*96*2)
   #define H264SwDecExtSize_176x144_BP    91155	  //90759		//(3*1024 +250*1024  -176*144*2) 
   #define H264SwDecExtSize_240x192_BP    123055	//122335	//(5*1024 +375*1024  -240*192*2) 
   #define H264SwDecExtSize_320x240_BP    170280	//169080	//(6*1024 +500*1024  -320*240*2) 
   #define H264SwDecExtSize_400x240_BP    199865	//198365	//(7*1024 +600*1024  -400*240*2) 
   #define H264SwDecExtSize_352x288_BP    207986	//206402	//(6*1024 +610*1024  -352*288*2) 
   #define H264SwDecExtSize_432x240_BP    211699	//210079	//(7*1024 +620*1024  -432*240*2) 
   #define H264SwDecExtSize_480x320_BP    288250	//285850	//(8*1024 +870*1024  -480*320*2)  
   #define H264SwDecExtSize_640x368_BP    414060	//410380	//(11*1024+1260*1024 -640*368*2) 
   #define H264SwDecExtSize_640x480_BP    523820	//519020	//(11*1024+1610*1024 -640*480*2) 
   #define H264SwDecExtSize_720x480_BP    582805	//577405	//(12*1024+1800*1024 -720*480*2) 
   #define H264SwDecExtSize_800x480_BP    641790	//635790	//(13*1024+1990*1024 -800*480*2) 
   #define H264SwDecExtSize_848x480_BP    677181	//670821	//(14*1024+2100*1024 -848*480*2) 
   #define H264SwDecExtSize_864x480_BP    688978	//682498	//(12*1024+2140*1024 -864*480*2)
   #define H264SwDecExtSize_720x576_BP    688645	//682165	//(12*1024+2140*1024 -720*576*2)
   #define H264SwDecExtSize_800x608_BP    798590	//790990	//(13*1024+2480*1024 -800*608*2)
   #define H264SwDecExtSize_1024x768_BP   1258532 //1246244	//(17*1024+3950*1024 -1024*768*2)
   #define H264SwDecExtSize_1280x720_BP   1466100 //1451700	//(21*1024+4600*1024 -1280*720*2)
   #define H264SwDecExtSize_1280x960_BP   1936500 //1917300	//(21*1024+6100*1024 -1280*960*2)
   #define H264SwDecExtSize_1280x1024_BP  2061940 //2041460	//(21*1024+6500*1024 -1280*1024*2)
   #define H264SwDecExtSize_1408x1152_BP  2538908 //2513564	//(23*1024+8010*1024 -1408*1152*2)
   #define H264SwDecExtSize_1600x1200_BP  2995640 //2965640	//(26*1024+9460*1024 -1600*1200*2)
   #define H264SwDecExtSize_1920x1088_BP  3255100 //3222460	//(31*1024+10280*1024-1920*1088*2)
   
   #define H264SwDecExtSize_128x96_MPHP      88332		//155296  
   #define H264SwDecExtSize_176x144_MPHP     126795 	//264352   
   #define H264SwDecExtSize_240x192_MPHP     187855 	//320874
   #define H264SwDecExtSize_320x240_MPHP     278280 	//694016  
   #define H264SwDecExtSize_400x240_MPHP     334865		//854400  
   #define H264SwDecExtSize_352x288_MPHP     350546 	//899136  
   #define H264SwDecExtSize_432x240_MPHP     357499		//918560  
   #define H264SwDecExtSize_480x320_MPHP     504250		//1335168 
   #define H264SwDecExtSize_640x368_MPHP     745260		//2019072 
   #define H264SwDecExtSize_640x480_MPHP     955820		//2617152 
   #define H264SwDecExtSize_720x480_MPHP     1068805	//2937728 
   #define H264SwDecExtSize_800x480_MPHP     1181790	//3258304 
   #define H264SwDecExtSize_848x480_MPHP     1249581	//3450656 
   #define H264SwDecExtSize_864x480_MPHP     1272178	//3514464 
   #define H264SwDecExtSize_720x576_MPHP     1271845	//3514464 
   #define H264SwDecExtSize_800x608_MPHP     1482590	//4112704 
   #define H264SwDecExtSize_1024x768_MPHP    2364452	//6616640 
   #define H264SwDecExtSize_1280x720_MPHP    2762100	//7745024 
   #define H264SwDecExtSize_1280x960_MPHP    3664500	//10308224
   #define H264SwDecExtSize_1280x1024_MPHP   3905140	//10991744
   #define H264SwDecExtSize_1408x1152_MPHP   4819868 	//13589408
   #define H264SwDecExtSize_1600x1200_MPHP   5695640	//16076160
   #define H264SwDecExtSize_1920x1088_MPHP   6192700	//17486656      
//#endif /* (defined(H264_FP2_SERIES) && defined(__SW_VIDEO_MAX_RESOLUTION__)) */

#define H264SwDecIntraModeExtSize_128x96_BP    71052	//69132	//79680  
#define H264SwDecIntraModeExtSize_176x144_BP   91155	//87195	//103584
#define H264SwDecIntraModeExtSize_240x192_BP   123055	//115855	//136828   
#define H264SwDecIntraModeExtSize_320x240_BP   170280	//158280	//197696  
#define H264SwDecIntraModeExtSize_400x240_BP   199865	//184865	//232864  
#define H264SwDecIntraModeExtSize_352x288_BP   207986	//192146	//242560  
#define H264SwDecIntraModeExtSize_432x240_BP   211699	//195499	//246944  
#define H264SwDecIntraModeExtSize_480x320_BP   288250	//264250	//338016  
#define H264SwDecIntraModeExtSize_640x368_BP   414060	//377260	//487680  
#define H264SwDecIntraModeExtSize_640x480_BP   523820	//475820	//618272  
#define H264SwDecIntraModeExtSize_720x480_BP   582805	//528805	//688416  
#define H264SwDecIntraModeExtSize_800x480_BP   641790	//581790	//758592  
#define H264SwDecIntraModeExtSize_848x480_BP   677181	//613581	//800704  
#define H264SwDecIntraModeExtSize_864x480_BP   688978	//624178	//814368
#define H264SwDecIntraModeExtSize_720x576_BP   688645	//623845	//814368  
#define H264SwDecIntraModeExtSize_800x608_BP   798590	//722590	//945152
#define H264SwDecIntraModeExtSize_1024x768_BP  1258532//1135652	//1492352 
#define H264SwDecIntraModeExtSize_1280x720_BP  1466100//1132100	//1739264 
#define H264SwDecIntraModeExtSize_1280x960_BP  1936500//1744500	//2298944 
#define H264SwDecIntraModeExtSize_1280x1024_BP 2061940//1857140	//2448192 
#define H264SwDecIntraModeExtSize_1408x1152_BP 2538908//2285468	//3015648 
#define H264SwDecIntraModeExtSize_1600x1200_BP 2995640//2695640	//3559040 
#define H264SwDecIntraModeExtSize_1920x1088_BP 3255100//2928700	//3867680 

#define H264SwDecIntraModeExtSize_128x96_MPHP    71052	//79680  
#define H264SwDecIntraModeExtSize_176x144_MPHP   91155	//103584
#define H264SwDecIntraModeExtSize_240x192_MPHP   123055	//136828   
#define H264SwDecIntraModeExtSize_320x240_MPHP   170280	//197696  
#define H264SwDecIntraModeExtSize_400x240_MPHP   199865	//232864  
#define H264SwDecIntraModeExtSize_352x288_MPHP   207986	//242560  
#define H264SwDecIntraModeExtSize_432x240_MPHP   211699	//246944  
#define H264SwDecIntraModeExtSize_480x320_MPHP   288250	//338016  
#define H264SwDecIntraModeExtSize_640x368_MPHP   414060	//487680  
#define H264SwDecIntraModeExtSize_640x480_MPHP   523820	//618272  
#define H264SwDecIntraModeExtSize_720x480_MPHP   582805	//688416  
#define H264SwDecIntraModeExtSize_800x480_MPHP   641790	//758592  
#define H264SwDecIntraModeExtSize_848x480_MPHP   677181	//800704  
#define H264SwDecIntraModeExtSize_864x480_MPHP   688978	//814368
#define H264SwDecIntraModeExtSize_720x576_MPHP   688645	//814368  
#define H264SwDecIntraModeExtSize_800x608_MPHP   798590	//945152
#define H264SwDecIntraModeExtSize_1024x768_MPHP  1258532	//1492352 
#define H264SwDecIntraModeExtSize_1280x720_MPHP  1466100	//1739264 
#define H264SwDecIntraModeExtSize_1280x960_MPHP  1936500	//2298944 
#define H264SwDecIntraModeExtSize_1280x1024_MPHP 2061940	//2448192 
#define H264SwDecIntraModeExtSize_1408x1152_MPHP 2538908	//3015648 
#define H264SwDecIntraModeExtSize_1600x1200_MPHP 2995640	//3559040 
#define H264SwDecIntraModeExtSize_1920x1088_MPHP 3255100	//3867680 

#define H264SwDecLevel10        (148*1024 + 512 )
#define H264SwDecLevel1b        (148*1024 + 512 )
#define H264SwDecLevel11        (337*1024 + 512 )
#define H264SwDecLevel12        (891*1024       )
#define H264SwDecLevel13        (891*1024       )
#define H264SwDecLevel20        (891*1024       )
#define H264SwDecLevel21        (1782*1024      )
#define H264SwDecLevel22        (3037*1024 + 512)
#define H264SwDecLevel30        (3037*1024 + 512)
#define H264SwDecLevel31        (6750*1024      )
#define H264SwDecLevel32        (7680*1024 + 512)
#define H264SwDecLevel40        (12288*1024     )
#define H264SwDecLevel41        (12288*1024     )
#define H264SwDecLevel42        (13056*1024     )
#define H264SwDecLevel50        (41400*1024     )
#define H264SwDecLevel51        (69120*1024     )

#else
/* under construction !*/
#endif /* CHIP SERIES */ 


#ifdef __cplusplus
    }
#endif
    
#endif /* H264SWDECMEM_H */

