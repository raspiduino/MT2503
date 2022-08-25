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
 *   MP4SwEncMem.h
 *
 * Project:
 * --------
 *	MTK
 *
 * Description:
 * ------------

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
 ****************************************************************************/

#ifndef ___MP4SWENCDEFS_H_
#define ___MP4SWENCDEFS_H_

#ifdef __cplusplus
extern "C"
    {
#endif

#if defined(MT6236) || defined(MT6236B)
  #define MP4SwEncTargetOptResHVGA
#elif defined(MT6253)
  #define MP4SwEncTargetOptResQVGA  
  #define MP4SwEncTargetOptResZERO
#else
  #define MP4SwEncTargetOptResZERO
#endif

#if defined(MP4SwEncOptResQCIF)
#define MP4SwEncTargetOptWidth    176
#define MP4SwEncTargetOptHeight   144
#elif defined(MP4SwEncTargetOptResQVGA)
#define MP4SwEncTargetOptWidth    320
#define MP4SwEncTargetOptHeight   240
#elif defined(MP4SwEncTargetOptResCIF)
#define MP4SwEncTargetOptWidth    352
#define MP4SwEncTargetOptHeight   288
#elif defined(MP4SwEncTargetOptResHVGA)
#define MP4SwEncTargetOptWidth    480
#define MP4SwEncTargetOptHeight   320
#elif defined(MP4SwEncTargetOptResnHD)
#define MP4SwEncTargetOptWidth    640
#define MP4SwEncTargetOptHeight   360  
#elif defined(MP4SwEncTargetOptResVGA)
#define MP4SwEncTargetOptWidth    640
#define MP4SwEncTargetOptHeight   480  
#elif defined(MP4SwEncTargetOptResD1)
#define MP4SwEncTargetOptWidth    720
#define MP4SwEncTargetOptHeight   480  
#elif defined(MP4SwEncTargetOptRes720p)
#define MP4SwEncTargetOptWidth    1280
#define MP4SwEncTargetOptHeight   720  
#elif defined(MP4SwEncTargetOptResZERO)
#define MP4SwEncTargetOptWidth    2
#define MP4SwEncTargetOptHeight   2
#else
#error "undefined optimal resolution."
#endif
typedef enum
{
  MP4SWENC_QUALITY_LOW    = 0,
  MP4SWENC_QUALITY_NORMAL = 1,
  MP4SWENC_QUALITY_GOOD   = 2,
  MP4SWENC_QUALITY_FINE   = 3,
  MP4SWENC_QUALITY_VT     = 4,  
  MP4SWENC_QUALITY_CUSTOM = 255
} MP4SwEncQualityLevel;

typedef struct
{
  unsigned int  width;
  unsigned int  height;
  unsigned int  bit_rate;
  unsigned int  frame_rate;
  unsigned int  intra_vop_rate;
  unsigned int  intra_successive;
  unsigned int  qp_init;
  unsigned int  qp_max;
  unsigned int  qp_min;
  unsigned int  algorithm_select;
  unsigned int  rate_hard_limit_multiple;
  unsigned int  rate_balance_interval;
} MP4SwEncRecordSetting;

#define Fcore_bitstream_buffer_size_QCIF          32000
#define Fcore_bitstream_buffer_size_QVGA          32000
#define Fcore_bitstream_buffer_size_CIF           32000
#define Fcore_bitstream_buffer_size_WQVGA         40000
#define Fcore_bitstream_buffer_size_HVGA          64000
#define Fcore_bitstream_buffer_size_nHD           98240
#define Fcore_bitstream_buffer_size_VGA           128000
#define Fcore_bitstream_buffer_size_D1            144000
#define Fcore_bitstream_buffer_size_WVGA          160000
#define Fcore_bitstream_buffer_size_4CIF          168960
#define Fcore_bitstream_buffer_size_WVGA_848x480  169600
#define Fcore_bitstream_buffer_size_D1_720x576    172800
#define Fcore_bitstream_buffer_size_FWVGA         172800
#define Fcore_bitstream_buffer_size_SVGA          202720
#define Fcore_bitstream_buffer_size_XGA           327680
#define Fcore_bitstream_buffer_size_720p          384000
#define Fcore_bitstream_buffer_size_unknown       0

#define RES_ZERO            0
#define RES_QCIF            1
#define RES_QVGA            2
#define RES_WQVGA           3
#define RES_CIF             4
#define RES_HVGA            5
#define RES_nHD             6
#define RES_VGA             7
#define RES_D1              8
#define RES_WVGA            9
#define RES_4CIF  10
#define RES_WVGA_848x480   11
#define RES_D1_720x576   12
#define RES_FWVGA  13
#define RES_SVGA    14
#define RES_XGA  15
#define RES_720p  16


#ifdef ENC_SUPPORT_ALGORITHM_INDEXED
#define MP4SwEncFrameBufferNum    7
#else
#if defined(MT6575) || defined(MT6256) //Hybrid Reconstructed as reference
#define MP4SwEncFrameBufferNum    4
#else
#define MP4SwEncFrameBufferNum    3
#endif
#endif

#ifdef MT6276
#define MP4SwEncFBSize_Padding_H 16
#define MP4SwEncFBSize_Padding_V 4
#elif defined(MT6575) || defined(MT6256) //Hybrid
#define MP4SwEncFBSize_Padding_H 0
#define MP4SwEncFBSize_Padding_V 0
#else
#define MP4SwEncFBSize_Padding_H 16
#define MP4SwEncFBSize_Padding_V 2
#endif

#if defined(MT6575) || defined(MT6256) //Hybrid
#define MP4SwEncFBSize_QCIF           ((176  + MP4SwEncFBSize_Padding_H) * ((144+31)/32*32 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_QVGA           ((320  + MP4SwEncFBSize_Padding_H) * ((240+31)/32*32 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_CIF            ((352  + MP4SwEncFBSize_Padding_H) * ((288+31)/32*32 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_WQVGA          ((400  + MP4SwEncFBSize_Padding_H) * ((240+31)/32*32 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_HVGA           ((480  + MP4SwEncFBSize_Padding_H) * ((320+31)/32*32 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_nHD            ((640  + MP4SwEncFBSize_Padding_H) * ((368+31)/32*32 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_VGA            ((640  + MP4SwEncFBSize_Padding_H) * ((480+31)/32*32 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_D1             ((720  + MP4SwEncFBSize_Padding_H) * ((480+31)/32*32 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_WVGA           ((800  + MP4SwEncFBSize_Padding_H) * ((480+31)/32*32 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_4CIF           ((704  + MP4SwEncFBSize_Padding_H) * ((576+31)/32*32 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_WVGA_848x480   ((848  + MP4SwEncFBSize_Padding_H) * ((480+31)/32*32 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_D1_720x576     ((720  + MP4SwEncFBSize_Padding_H) * ((576+31)/32*32 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_FWVGA          ((864  + MP4SwEncFBSize_Padding_H) * ((480+31)/32*32 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_SVGA           ((800  + MP4SwEncFBSize_Padding_H) * ((608+31)/32*32 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_XGA            ((1024 + MP4SwEncFBSize_Padding_H) * ((768+31)/32*32 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_720p           ((1280 + MP4SwEncFBSize_Padding_H) * ((720+31)/32*32 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#else
#define MP4SwEncFBSize_QCIF           ((176  + MP4SwEncFBSize_Padding_H) * (144 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_QVGA           ((320  + MP4SwEncFBSize_Padding_H) * (240 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_CIF            ((352  + MP4SwEncFBSize_Padding_H) * (288 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_WQVGA          ((400  + MP4SwEncFBSize_Padding_H) * (240 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_HVGA           ((480  + MP4SwEncFBSize_Padding_H) * (320 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_nHD            ((640  + MP4SwEncFBSize_Padding_H) * (368 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_VGA            ((640  + MP4SwEncFBSize_Padding_H) * (480 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_D1             ((720  + MP4SwEncFBSize_Padding_H) * (480 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_WVGA           ((800  + MP4SwEncFBSize_Padding_H) * (480 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_4CIF           ((704  + MP4SwEncFBSize_Padding_H) * (576 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_WVGA_848x480   ((848  + MP4SwEncFBSize_Padding_H) * (480 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_D1_720x576     ((720  + MP4SwEncFBSize_Padding_H) * (576 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_FWVGA          ((864  + MP4SwEncFBSize_Padding_H) * (480 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_SVGA           ((800  + MP4SwEncFBSize_Padding_H) * (608 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_XGA            ((1024 + MP4SwEncFBSize_Padding_H) * (768 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#define MP4SwEncFBSize_720p           ((1280 + MP4SwEncFBSize_Padding_H) * (720 + MP4SwEncFBSize_Padding_V) * MP4SwEncFrameBufferNum)
#endif

/*
#ifdef MP4SwEncMaxVidCodRes_QCIF
#define Fcore_bitstream_buffer_size      Fcore_bitstream_buffer_size_QCIF
#elif defined(MP4SwEncMaxVidCodRes_QVGA)
#define Fcore_bitstream_buffer_size      Fcore_bitstream_buffer_size_QVGA
#elif defined(MP4SwEncMaxVidCodRes_CIF)
#define Fcore_bitstream_buffer_size      Fcore_bitstream_buffer_size_CIF
#elif defined(MP4SwEncMaxVidCodRes_WQVGA)
#define Fcore_bitstream_buffer_size      Fcore_bitstream_buffer_size_WQVGA
#elif defined(MP4SwEncMaxVidCodRes_HVGA)
#define Fcore_bitstream_buffer_size      Fcore_bitstream_buffer_size_HVGA
#elif defined(MP4SwEncMaxVidCodRes_nHD)
#define Fcore_bitstream_buffer_size      Fcore_bitstream_buffer_size_nHD
#elif defined(MP4SwEncMaxVidCodRes_VGA)
#define Fcore_bitstream_buffer_size      Fcore_bitstream_buffer_size_VGA
#elif defined(MP4SwEncMaxVidCodRes_D1)
#define Fcore_bitstream_buffer_size      Fcore_bitstream_buffer_size_D1
#elif defined(MP4SwEncMaxVidCodRes_WVGA)
#define Fcore_bitstream_buffer_size      Fcore_bitstream_buffer_size_WVGA
#elif defined(MP4SwEncMaxVidCodRes_720p)
#define Fcore_bitstream_buffer_size      Fcore_bitstream_buffer_size_720p
#else
#define Fcore_bitstream_buffer_size      Fcore_bitstream_buffer_size_unknown
#endif
*/

#ifdef MT6276 //5000 is for pEncInst_v & other dual processor buffer
#define MP4SwEncContextSize_QCIF            (22128+Fcore_bitstream_buffer_size_QCIF)
#define MP4SwEncContextSize_QVGA            (25920+Fcore_bitstream_buffer_size_QVGA)
#define MP4SwEncContextSize_CIF             (27854+Fcore_bitstream_buffer_size_CIF)
#define MP4SwEncContextSize_WQVGA           (27440+Fcore_bitstream_buffer_size_WQVGA)
#define MP4SwEncContextSize_HVGA            (31360+Fcore_bitstream_buffer_size_HVGA)
#define MP4SwEncContextSize_nHD             (37120+Fcore_bitstream_buffer_size_nHD)
#define MP4SwEncContextSize_VGA             (41600+Fcore_bitstream_buffer_size_VGA)
#define MP4SwEncContextSize_D1      	     	(44716+Fcore_bitstream_buffer_size_D1)
#define MP4SwEncContextSize_WVGA            (48536+Fcore_bitstream_buffer_size_WVGA)
#define MP4SwEncContextSize_4CIF            (49760+Fcore_bitstream_buffer_size_QCIF)
#define MP4SwEncContextSize_WVGA_848x480		(50828+Fcore_bitstream_buffer_size_WVGA_848x480)
#define MP4SwEncContextSize_D1_720x576      (50656+Fcore_bitstream_buffer_size_D1_720x576)
#define MP4SwEncContextSize_FWVGA           (51592+Fcore_bitstream_buffer_size_WVGA)
#define MP4SwEncContextSize_SVGA            (57336+Fcore_bitstream_buffer_size_SVGA)
#define MP4SwEncContextSize_XGA             (84576+Fcore_bitstream_buffer_size_XGA)
#define MP4SwEncContextSize_720p            (97856+Fcore_bitstream_buffer_size_720p)
#elif defined(MT6575) || defined(MT6256) //EncDrvHybrid_Init need additional (mbPerVop*INPUT_IMAGE_BUFFER_SIZE*(sizeof(mv_s)+sizeof(u8)+sizeof(u8)))
#define MP4SwEncContextSize_QCIF            (22128+99*4*10)
#define MP4SwEncContextSize_QVGA            (25920+300*4*10)
#define MP4SwEncContextSize_CIF             (27854+396*4*10)
#define MP4SwEncContextSize_WQVGA           (27440+375*4*10)
#define MP4SwEncContextSize_HVGA            (31360+600*4*10)
#define MP4SwEncContextSize_nHD             (37120+920*4*10)
#define MP4SwEncContextSize_VGA             (41600+1200*4*10)
#define MP4SwEncContextSize_D1              (44320+1350*4*10)
#define MP4SwEncContextSize_WVGA            (47040+1500*4*10)
#define MP4SwEncContextSize_4CIF            (49760+1584*4*10)
#define MP4SwEncContextSize_WVGA_848x480    (37120+1590*4*10)
#define MP4SwEncContextSize_D1_720x576      (41600+1620*4*10)
#define MP4SwEncContextSize_FWVGA           (51592+1620*4*10)
#define MP4SwEncContextSize_SVGA            (44320+1900*4*10)
#define MP4SwEncContextSize_XGA             (47040+3072*4*10)
#define MP4SwEncContextSize_720p            (82560+3600*4*10)
#elif defined(WIN32)
#define MP4SwEncContextSize_QCIF            21438
#define MP4SwEncContextSize_QVGA            24024
#define MP4SwEncContextSize_CIF             25112
#define MP4SwEncContextSize_WQVGA           25094
#define MP4SwEncContextSize_HVGA            27664
#define MP4SwEncContextSize_nHD             31504
#define MP4SwEncContextSize_VGA             34304
#define MP4SwEncContextSize_D1              36124
#define MP4SwEncContextSize_WVGA            37944
#define MP4SwEncContextSize_4CIF            60864
#define MP4SwEncContextSize_WVGA_848x480    60864
#define MP4SwEncContextSize_D1_720x576      60864
#define MP4SwEncContextSize_FWVGA           60864
#define MP4SwEncContextSize_SVGA            60864
#define MP4SwEncContextSize_XGA             60864
#define MP4SwEncContextSize_720p            60864
#else
#define MP4SwEncContextSize_QCIF          21654
#define MP4SwEncContextSize_QVGA          23640
#define MP4SwEncContextSize_CIF           24536
#define MP4SwEncContextSize_WQVGA         24560
#define MP4SwEncContextSize_HVGA          26680
#define MP4SwEncContextSize_nHD           29880
#define MP4SwEncContextSize_VGA           32120
#define MP4SwEncContextSize_D1            33640
#define MP4SwEncContextSize_WVGA          35160
#define MP4SwEncContextSize_4CIF          53880
#define MP4SwEncContextSize_WVGA_848x480  53880
#define MP4SwEncContextSize_D1_720x576    53880
#define MP4SwEncContextSize_FWVGA         53880
#define MP4SwEncContextSize_SVGA          53880
#define MP4SwEncContextSize_XGA           53880
#define MP4SwEncContextSize_720p          53880
#endif

#ifdef MP4SwEncTargetOptResQCIF
#define MP4SwEncTargetOptIntMemSize       MP4SwEncContextSize_QCIF
#elif defined(MP4SwEncTargetOptResQVGA)
#define MP4SwEncTargetOptIntMemSize       MP4SwEncContextSize_QVGA
#elif defined(MP4SwEncTargetOptResCIF)
#define MP4SwEncTargetOptIntMemSize       MP4SwEncContextSize_CIF
#elif defined(MP4SwEncTargetOptResWQVGA)
#define MP4SwEncTargetOptIntMemSize       MP4SwEncContextSize_WQVGA
#elif defined(MP4SwEncTargetOptResHVGA)
#define MP4SwEncTargetOptIntMemSize       MP4SwEncContextSize_HVGA
#elif defined(MP4SwEncTargetOptResnHD)
#define MP4SwEncTargetOptIntMemSize       MP4SwEncContextSize_nHD
#elif defined(MP4SwEncTargetOptResVGA)
#define MP4SwEncTargetOptIntMemSize       MP4SwEncContextSize_VGA
#elif defined(MP4SwEncTargetOptResWVGA)
#define MP4SwEncTargetOptIntMemSize       MP4SwEncContextSize_WVGA
#elif defined(MP4SwEncTargetOptResD1)
#define MP4SwEncTargetOptIntMemSize       MP4SwEncContextSize_D1
#elif defined(MP4SwEncTargetOptRes720p)
#define MP4SwEncTargetOptIntMemSize       MP4SwEncContextSize_720p
#else
#define MP4SwEncTargetOptIntMemSize       0
#endif

#if MP4SwEncContextSize_QCIF > MP4SwEncTargetOptIntMemSize
#define MP4SwEncExtContextSize_QCIF   MP4SwEncContextSize_QCIF
#else
#define MP4SwEncExtContextSize_QCIF   0
#endif

#if MP4SwEncContextSize_QVGA > MP4SwEncTargetOptIntMemSize
#define MP4SwEncExtContextSize_QVGA   MP4SwEncContextSize_QVGA
#else
#define MP4SwEncExtContextSize_QVGA   0
#endif

#if MP4SwEncContextSize_CIF > MP4SwEncTargetOptIntMemSize
#define MP4SwEncExtContextSize_CIF    MP4SwEncContextSize_CIF
#else
#define MP4SwEncExtContextSize_CIF    0
#endif

#if MP4SwEncContextSize_WQVGA > MP4SwEncTargetOptIntMemSize
#define MP4SwEncExtContextSize_WQVGA  MP4SwEncContextSize_WQVGA
#else
#define MP4SwEncExtContextSize_WQVGA  0
#endif

#if MP4SwEncContextSize_HVGA > MP4SwEncTargetOptIntMemSize
#define MP4SwEncExtContextSize_HVGA   MP4SwEncContextSize_HVGA
#else
#define MP4SwEncExtContextSize_HVGA   0
#endif

#if MP4SwEncContextSize_nHD > MP4SwEncTargetOptIntMemSize
#define MP4SwEncExtContextSize_nHD    MP4SwEncContextSize_nHD
#else
#define MP4SwEncExtContextSize_nHD    0
#endif

#if MP4SwEncContextSize_VGA  > MP4SwEncTargetOptIntMemSize
#define MP4SwEncExtContextSize_VGA    MP4SwEncContextSize_VGA
#else
#define MP4SwEncExtContextSize_VGA    0
#endif

#if MP4SwEncContextSize_D1   > MP4SwEncTargetOptIntMemSize
#define MP4SwEncExtContextSize_D1     MP4SwEncContextSize_D1
#else
#define MP4SwEncExtContextSize_D1     0
#endif

#if MP4SwEncContextSize_WVGA  > MP4SwEncTargetOptIntMemSize
#define MP4SwEncExtContextSize_WVGA     MP4SwEncContextSize_WVGA
#else
#define MP4SwEncExtContextSize_WVGA   0
#endif

#if MP4SwEncContextSize_4CIF  > MP4SwEncTargetOptIntMemSize
#define MP4SwEncExtContextSize_4CIF     MP4SwEncContextSize_4CIF
#else
#define MP4SwEncExtContextSize_4CIF   0
#endif

#if MP4SwEncContextSize_WVGA_848x480  > MP4SwEncTargetOptIntMemSize
#define MP4SwEncExtContextSize_WVGA_848x480     MP4SwEncContextSize_WVGA_848x480
#else
#define MP4SwEncExtContextSize_WVGA_848x480   0
#endif

#if MP4SwEncContextSize_D1_720x576  > MP4SwEncTargetOptIntMemSize
#define MP4SwEncExtContextSize_D1_720x576     MP4SwEncContextSize_D1_720x576
#else
#define MP4SwEncExtContextSize_D1_720x576   0
#endif

#if MP4SwEncContextSize_FWVGA  > MP4SwEncTargetOptIntMemSize
#define MP4SwEncExtContextSize_FWVGA     MP4SwEncContextSize_FWVGA
#else
#define MP4SwEncExtContextSize_FWVGA   0
#endif

#if MP4SwEncContextSize_SVGA  > MP4SwEncTargetOptIntMemSize
#define MP4SwEncExtContextSize_SVGA     MP4SwEncContextSize_SVGA
#else
#define MP4SwEncExtContextSize_SVGA   0
#endif

#if MP4SwEncContextSize_XGA  > MP4SwEncTargetOptIntMemSize
#define MP4SwEncExtContextSize_XGA     MP4SwEncContextSize_XGA
#else
#define MP4SwEncExtContextSize_XGA   0
#endif

#if MP4SwEncContextSize_720p > MP4SwEncTargetOptIntMemSize
#define MP4SwEncExtContextSize_720p   MP4SwEncContextSize_720p
#else
#define MP4SwEncExtContextSize_720p   0
#endif


#define ExtMemMargin    2048


#ifdef __cplusplus
    }
#endif

#endif
