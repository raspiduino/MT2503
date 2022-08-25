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
 *   camera_tuning_para.c
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   Camera Operation Parameter for sensor driver related.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features.h"

#include "isp_comm_if.h"

#if(defined(YUV_MAIN_CAMERA) || defined(YUV_BAK1_CAMERA) ||defined(YUV_SUB_CAMERA) || defined(YUV_SUB_BAK1_CAMERA) )


#define YUV_CAMERA_SENSOR_REG_DEFAULT_VALUE {{0x0,0x0}}
#define YUV_CAMERA_SENSOR_CCT_DEFAULT_VALUE {{ 0xFFFFFFFF, 0x08 } ,{ 0x0209, 0x0008 } ,{ 0x0207, 0x0008 } ,{ 0x020D, 0x0008 } ,{ 0x020B, 0x0008 }}

#if defined(__CAMERA_NVRAM_REDUCTION__)
const nvram_camera_para_struct YUV_CAMERA_PARA_DEFAULT_VALUE=
{
    	{YUV_CAMERA_SENSOR_REG_DEFAULT_VALUE,
	 YUV_CAMERA_SENSOR_CCT_DEFAULT_VALUE,
	}
};

#else
const nvram_camera_para_struct YUV_CAMERA_PARA_DEFAULT_VALUE=
{
	/* STRUCT: ISP */
	{
		/* ARRAY: ISP.reg[144+8] */
		{
      0xA4021842, 0x1FFF0FFF, 0x000203FD, 0x000202FF,         // CAM+000h~00Ch ,0
			0x00300091, /*0xA8A8A8A8*/0x00, 0x00000040, 0x00000081,         // CAM+010h~01Ch ,4
			0x00000000, 0x06000030, 0x40010000, 0x40030000,         // CAM+020h~02Ch ,8 
			0x80FF0100, 0x00800080, 0x00800080, 0x00000000,         // CAM+030h~03Ch ,12
			0x00000000, 0x03C9A800, 0x0880081F, 0x0000043F,         // CAM+040h~04Ch ,16
			0x00000000, 0x00000008, 0x00408010, 0xFF0190B7,         // CAM+050h~05Ch ,20
			0x00000000, 0x10107000, 0x40404040, 0x00800080,         // CAM+060h~06Ch ,24
			0x00800080, 0x000000F1, 0x000001A0, 0x00000000,         // CAM+070h~07Ch ,28
			0x00000000, 0x00000000, 0x00000000, 0x00000000,         // CAM+080h~08Ch ,32
			0x00000000, 0x00000000, 0x00000000, 0x00000000,         // CAM+090h~09Ch ,36
			0x00000000, 0x00000000, 0x00000000, 0x00000000,         // CAM+0A0h~0ACh ,40
			0x00000000, 0x00000000, 0x00000000, 0x00000000,         // CAM+0B0h~0BCh ,44
			0x00000000, 0x00000000, 0x00000000, 0x00000000,         // CAM+0C0h~0CCh ,48
			0x00000000, 0x00000000, 0x00000000, 0x00000000,         // CAM+0D0h~0DCh ,52
			0x00000000, 0x00000000, 0x00000000, 0x00000000,         // CAM+0E0h~0ECh ,56
			0x00000000, 0x00000000, 0x00000000, 0x00000000        // CAM+0F0h~0FCh ,60
			
		}
	},
   //ISPTUNING
    {
                //idx
                {
						0x0,0x3,0x3,0x3,0x1,0x1,0x1,0x0
                },
          
                //shadingReg
                {
                        {
                            0x30000000, 0x4066207F, 0x40000000, 0x0064007E,0x19191919	//Preview
                        },
                        {
                            0x30000000, 0x60924098, 0x40000000, 0x008C0094,0x19191919	//Capture
                        },                        
                        {
                            0x30000000, 0x6048404B, 0x40000000, 0x004A004C,0x19191919	//Binning
                         }
                },

                //nr1Reg
                {
                        {
                          0x000000F5, 0x000650A0, 0x00000678, 0x02040608,
                          0x08080808, 0x02040608, 0x08080808, 0x02040608,
                          0x08080808, 0x02040608, 0x08080808
                        },
                       {
                          0x000000F5, 0x000750A0, 0x00000678, 0x04060808,
                          0x08080808, 0x04060808, 0x08080808, 0x04060808,
                          0x08080808, 0x04060808, 0x08080808
                        },
                       {
                          0x000000F5, 0x000750A0, 0x00000678, 0x06080A0A,
                          0x08080808, 0x06080A0A, 0x08080808, 0x06080A0A,
                          0x08080808, 0x06080A0A, 0x08080808
                        },
                       {
                          0x000000F5, 0x000750A0, 0x00000678, 0x06080A0A,
                          0x08080808, 0x06080A0A, 0x08080808, 0x06080A0A,
                          0x08080808, 0x06080A0A, 0x08080808
                        },
                       {
                          0x000000F5, 0x000850A0, 0x00000678, 0x06080A0A,
                          0x08080808, 0x06080A0A, 0x08080808, 0x06080A0A,
                          0x08080808, 0x06080A0A, 0x08080808
                        },
                       {
                          0x000000F5, 0x000850A0, 0x00000678, 0x06080A0A,
                          0x08080808, 0x06080A0A, 0x08080808, 0x06080A0A,
                          0x08080808, 0x06080A0A, 0x08080808
                        },
                       {
                          0x000000F5, 0x000890A0, 0x00000678, 0x0F0F0F0F,
                          0x0F0F0F0F, 0x0F0F0F0F, 0x0F0F0F0F, 0x0F0F0F0F,
                          0x0F0F0F0F, 0x0F0F0F0F, 0x0F0F0F0F
                        }

                },


                //nr2Reg
                {
                       {
                          0x00000003, 0x00000000, 0x00942266, 0x02040606, 0x02040606
                        },
                       {
                          0x00000003, 0x00000000, 0x00942266, 0x03050707, 0x03050707
                        },
                       {
                          0x00000003, 0x00000000, 0x00942277, 0x04060808, 0x04060808
                        },
                       {
                          0x00000003, 0x00000000, 0x009C3388, 0x06080A0A, 0x06080A0A
                        },
                       {
                          0x00000003, 0x00000000, 0x00A44488, 0x06080A0A, 0x06080A0A
                        },
                       {
                          0x00000003, 0x00000000, 0x00A44488, 0x080A0C0C, 0x080A0C0C
                        },
                       {
                          0x00000003, 0x00000000, 0x00A44488, 0x0A0C0E0E, 0x0A0C0E0E
                        }
                },
                        
                //edgeReg
                {
                       {
                          0x4002086C, 0x00200804, 0x06060404
                        },
                       {
                          0x20020821, 0x000C0806, 0x04030201
                        },
                       {
                          0x30020821, 0x00080402, 0x0A080604
                        },
                       {
                          0x30020821, 0x00080402, 0x0C0A0806
                        },
                       {
                          0x40020821, 0x00080402, 0x1814100C
                        },
                       {
                          0x60020821, 0x00080402, 0x1A16120E
                        },
                       {
                           0x60020821, 0x00080402, 0x1A16120E
                        }
                 },

                //autodefect
                {
                        {
                            0x000000F5, 0x50285050, 0x006003A0, 0x00300050,0x00000895
                        },
                        {
                            0x000000F5, 0x50285050, 0x006003A0, 0x00300050,0x00000895
                        },

                        {
                            0x000000F5, 0x50285050, 0x006003A0, 0x00300050,0x00000895
                         }
                },
                            
                //saturation
                {
                        {
                            0x00000001, 0x1020E0F0, 0x081E1E1E, 0x080A0000
                        },
                        {
                            0x00000001, 0x1020E0F0, 0x20464846, 0x200A0000
                        },
                        {
                            0x00000001, 0x1020E0F0, 0x244A4C4A, 0x240A0000
                        },
                        {
                            0x00000001, 0x1020E0F0, 0x284C4E4C, 0x240A0000
                        },

                        {
                            0x00000001, 0x1020E0F0, 0x284C4E4C, 0x240A0000
                        },
                        {
                            0x00000001, 0x1020E0F0, 0x284C4E4C, 0x240A0000
                        },

                        {
                            0x00000001, 0x1020E0F0, 0x284C4E4C, 0x240A0000
                         }
                },

                //contrast
                {
                       {
                          0x00000009, 0x400F0000, 0xFF00003D
                        },
                       {
                          0x00000009, 0x40000000, 0xFF000040
                        },
                       {
                          0x00000009, 0x40E20000, 0xFF000049
                        }
                }

   	   
     },

     //MShutter
     {  
        0x000001F4, 0x00000000        
     },

	{YUV_CAMERA_SENSOR_REG_DEFAULT_VALUE,
	 YUV_CAMERA_SENSOR_CCT_DEFAULT_VALUE,
	}

};
const nvram_camera_3a_struct YUV_CAMERA_3A_DEFAULT_VALUE={0};
const nvram_camera_defect1_struct YUV_CAMERA_DEFECT1_DEFAULT_VALUE={0};
const nvram_camera_defect2_struct YUV_CAMERA_DEFECT2_DEFAULT_VALUE={0};
const nvram_camera_shading1_struct YUV_CAMERA_SHADING1_DEFAULT_VALUE={0};
const nvram_camera_shading2_struct YUV_CAMERA_SHADING2_DEFAULT_VALUE={0};
#if defined(DRV_ISP_PCA_SUPPORT)
const nvram_camera_pca_struct YUV_CAMERA_PCA_DEFAULT_VALUE={0};
#endif
#endif
#endif

