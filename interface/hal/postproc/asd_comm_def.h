/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/*
**
** Copyright 2008, The Android Open Source Project
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/
#ifndef _ASD_COMM_DEF_H_
#define _ASD_COMM_DEF_H_

#include "kal_release.h"


/*****************************************************************************
	ASD Defines and State Machine / Proc Mode
******************************************************************************/
#define ASD_IM_WIDTH    		(160)				// default max image width
#define ASD_IM_HEIGHT   		(120)				// default max image height
#define ASD_IMAGE_SIZE 			(ASD_IM_WIDTH*ASD_IM_HEIGHT*2)	// Image buffer size
#define ASD_WORKING_BUFFER_SIZE (ASD_IMAGE_SIZE*9) // working buffer size W*H*2*9
#define ASD_DECIDER_LOG_HEADER 512
#define ASD_DECIDER_LOG_BYTE_PER_CYCLE 256
#define ASD_DECIDER_LOG_MAX_CYCLE 600
#define ASD_DECIDER_BUFFER_SIZE (((ASD_DECIDER_LOG_BYTE_PER_CYCLE*ASD_DECIDER_LOG_MAX_CYCLE+ASD_DECIDER_LOG_HEADER+ASD_IMAGE_SIZE+31)>>5)<<5)
#define ASD_BUFFER_SIZE 	 (((ASD_IMAGE_SIZE+ASD_WORKING_BUFFER_SIZE+ASD_DECIDER_BUFFER_SIZE+31)>>5)<<5)

//#define ASD_LOG_DEBUG_INFO
#ifdef ASD_LOG_DEBUG_INFO
#define ASD_LOG_BUFFER_SIZE			(0) // Log	
#else
#define ASD_LOG_BUFFER_SIZE			(0) //BYTES
#endif
/*****************************************************************************
	Decider Sub-Module
******************************************************************************/
// from decider_core.h
/* all possible scene types enum, only 7 scenes are available for this MP */
typedef enum
{
    ASD_DECIDER_UI_AUTO=0,
    ASD_DECIDER_UI_N   =1,
    ASD_DECIDER_UI_B   =2,
    ASD_DECIDER_UI_P   =3,
    ASD_DECIDER_UI_L   =4,
    ASD_DECIDER_UI_NB  =5,
    ASD_DECIDER_UI_NP  =6,
    ASD_DECIDER_UI_NL  =7,
    ASD_DECIDER_UI_BP  =8,
    ASD_DECIDER_UI_BL  =9,
    ASD_DECIDER_UI_PL  =10,
    ASD_DECIDER_UI_NBP =11,
    ASD_DECIDER_UI_NBL =12,
    ASD_DECIDER_UI_NPL =13,
    ASD_DECIDER_UI_BPL =14,
    ASD_DECIDER_UI_NBPL=15,
    ASD_DECIDER_UI_SCENE_NUM
} ASD_DECIDER_UI_SCENE_TYPE_ENUM;

/* tuning param, time smooth weight vector customized options enum, time smooth range */
typedef enum
{
    ASD_TIME_WEIGHT_RANGE_1CYCLE=1,
	ASD_TIME_WEIGHT_RANGE_2CYCLE=2,
	ASD_TIME_WEIGHT_RANGE_3CYCLE=3,
	ASD_TIME_WEIGHT_RANGE_4CYCLE=4,
	ASD_TIME_WEIGHT_RANGE_5CYCLE=5,
	ASD_TIME_WEIGHT_RANGE_6CYCLE=6,
	ASD_TIME_WEIGHT_RANGE_7CYCLE=7,
	ASD_TIME_WEIGHT_RANGE_8CYCLE=8,
	ASD_TIME_WEIGHT_RANGE_9CYCLE=9,
	ASD_TIME_WEIGHT_RANGE_10CYCLE=10,
    ASD_TIME_WEIGHT_RANGE_CYCLE_MAX
} ASD_DECIDER_TIME_WEIGHT_RANGE_ENUM;

/* tuning param, time smooth weight vector customized options enum, time smooth type */
typedef enum
{
    ASD_TIME_WEIGHT_AVERAGE=0,     /* the same weight on each cycle results */
	ASD_TIME_WEIGHT_LATER_HIGHER,  /* higher weight on later cycle results */
    ASD_TIME_WEIGHT_IDX_WEIGHT_TYPE_NUM
} ASD_DECIDER_TIME_WEIGHT_TYPE_ENUM;

/* ASD */
typedef struct
{
    kal_bool    AeIsBacklit; /* AE Backlit Condition from AE algorithm */
    kal_bool    AeIsStable;  /* AE converge to stable situation */
    kal_bool    AwbIsStable; /* AWB converge to stable situation */
    kal_bool    AfIsStable;  /* Af converge to stable situation */
    kal_uint16 AwbCurRgain; /* Current AWB R channel gain */
    kal_uint16 AwbCurBgain; /* Current AWB B channel gain */
    kal_uint16 AfPosition;  /* Current lens position */
    kal_uint8   AeEv;   /* AE Ev value */
    kal_int16  AeFaceEnhanceEv;        /* AE Ev value from face */
} ASD_PROC_AAA_PARA, *P_ASD_PROC_AAA_PARA;

/* final ASD call back  */
typedef struct
{
    ASD_DECIDER_UI_SCENE_TYPE_ENUM AsdScene;
} ASD_FINAL_RESULT_STRUCT, *P_ASD_FINAL_RESULT_STRUCT;

#endif //_ASD_COMM_DEF_H_

