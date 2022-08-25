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
 *   lens_module.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   A Lens module device driver control interface
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mm_comm_def.h"
#include "lens_module.h"
#include "image_sensor.h"


//#if (defined(AF_SUPPORT))
kal_uint32 LensOutParaLen;


MM_ERROR_CODE_ENUM DUMMYLensOpen(void)
{	
    return MM_ERROR_NONE;		
}

MM_ERROR_CODE_ENUM DUMMYLensFeatureControl(LENS_FEATURE_ENUM FeatureId, void* pFeatureParaIn, void* pFeatureParaOut,
                                                                                    kal_uint32 FeatureParaOutLen, kal_uint32 *pRealFeatureParaOutLen)
{	
	return MM_ERROR_NONE;		
}

MM_ERROR_CODE_ENUM DUMMYLensControl(CAL_SCENARIO_ENUM ScenarioId, void *pParaIn, void *pParaOut, kal_uint32 ParaOutLen,
                                      kal_uint32 *pRealParaOutLen)
{		
	return MM_ERROR_NONE;	
}

MM_ERROR_CODE_ENUM DUMMYLensClose(void)
{		
	return MM_ERROR_NONE;		
}

LENS_FUNCTION_STRUCT DUMMYLENS_LensFuncMap=
{
    DUMMYLensOpen,		
    DUMMYLensFeatureControl,	
    DUMMYLensControl,		
    DUMMYLensClose		
};

MM_ERROR_CODE_ENUM DUMMYLENSLensFuncInit(P_LENS_FUNCTION_STRUCT *pfFunc)
{
    *pfFunc=&DUMMYLENS_LensFuncMap;

    return MM_ERROR_NONE;
}



LENS_LIST_STRUCT LensList[MAX_LENS_NUMBER+1] =
{
    ADD_LENS_MODULE(NULL_SENSOR_ID,DUMMYLENS,IMAGE_SENSOR_MAIN),
#if(defined(SUNNY_S5M03G_MT9P012_AD5820))
    #if (defined(MT9P012_RAW_MAIN)||defined(MT9P012_RAW_BAK1)||defined(MT9P012_RAW_SUB)||defined(MT9P012_RAW_SUB_BAK1))
        #if(defined(MT9P012_RAW_MAIN))
            ADD_LENS_MODULE(MT9P012_SENSOR_ID,SunnyS5m03gMt9p012Ad5820,IMAGE_SENSOR_MAIN),
        #endif    
        #if(defined(MT9P012_RAW_BAK1))
            ADD_LENS_MODULE(MT9P012_SENSOR_ID,SunnyS5m03gMt9p012Ad5820,IMAGE_SENSOR_BAK1),
        #endif    
        #if(defined(MT9P012_RAW_SUB))
            ADD_LENS_MODULE(MT9P012_SENSOR_ID,SunnyS5m03gMt9p012Ad5820,IMAGE_SENSOR_SUB),
        #endif    
        #if(defined(MT9P012_RAW_SUB_BAK1))
            ADD_LENS_MODULE(MT9P012_SENSOR_ID,SunnyS5m03gMt9p012Ad5820,IMAGE_SENSOR_SUB_BAK1),
        #endif    

    #else
        #if(defined(MT9P012_MIPI_RAW_MAIN))
            ADD_LENS_MODULE(MT9P012_MIPI_SENSOR_ID,SunnyS5m03gMt9p012Ad5820,IMAGE_SENSOR_MAIN),
        #endif    
        #if(defined(MT9P012_MIPI_RAW_BAK1))
            ADD_LENS_MODULE(MT9P012_MIPI_SENSOR_ID,SunnyS5m03gMt9p012Ad5820,IMAGE_SENSOR_BAK1),
        #endif    
        #if(defined(MT9P012_MIPI_RAW_SUB))
            ADD_LENS_MODULE(MT9P012_MIPI_SENSOR_ID,SunnyS5m03gMt9p012Ad5820,IMAGE_SENSOR_SUB),
        #endif    
        #if(defined(MT9P012_MIPI_RAW_SUB_BAK1))
            ADD_LENS_MODULE(MT9P012_MIPI_SENSOR_ID,SunnyS5m03gMt9p012Ad5820,IMAGE_SENSOR_SUB_BAK1),
        #endif    
    #endif
#endif    

#if(defined(FOXCONN_ATCM_5011_MT9P012_AD5820))
    #if (defined(MT9P012_RAW_MAIN)||defined(MT9P012_RAW_BAK1)||defined(MT9P012_RAW_SUB)||defined(MT9P012_RAW_SUB_BAK1))
        #if(defined(MT9P012_RAW_MAIN))
            ADD_LENS_MODULE(MT9P012_SENSOR_ID,FoxconnAtcm5011Mt9p012Ad5820,IMAGE_SENSOR_MAIN),
        #endif    
        #if(defined(MT9P012_RAW_BAK1))
            ADD_LENS_MODULE(MT9P012_SENSOR_ID,FoxconnAtcm5011Mt9p012Ad5820,IMAGE_SENSOR_BAK1),
        #endif    
        #if(defined(MT9P012_RAW_SUB))
            ADD_LENS_MODULE(MT9P012_SENSOR_ID,FoxconnAtcm5011Mt9p012Ad5820,IMAGE_SENSOR_SUB),
        #endif    
        #if(defined(MT9P012_RAW_SUB_BAK1))
            ADD_LENS_MODULE(MT9P012_SENSOR_ID,FoxconnAtcm5011Mt9p012Ad5820,IMAGE_SENSOR_SUB_BAK1),
        #endif    

    #else
        #if(defined(MT9P012_MIPI_RAW_MAIN))
            ADD_LENS_MODULE(MT9P012_MIPI_SENSOR_ID,FoxconnAtcm5011Mt9p012Ad5820,IMAGE_SENSOR_MAIN),
        #endif    
        #if(defined(MT9P012_MIPI_RAW_BAK1))
            ADD_LENS_MODULE(MT9P012_MIPI_SENSOR_ID,FoxconnAtcm5011Mt9p012Ad5820,IMAGE_SENSOR_BAK1),
        #endif    
        #if(defined(MT9P012_MIPI_RAW_SUB))
            ADD_LENS_MODULE(MT9P012_MIPI_SENSOR_ID,FoxconnAtcm5011Mt9p012Ad5820,IMAGE_SENSOR_SUB),
        #endif    
        #if(defined(MT9P012_MIPI_RAW_SUB_BAK1))
            ADD_LENS_MODULE(MT9P012_MIPI_SENSOR_ID,FoxconnAtcm5011Mt9p012Ad5820,IMAGE_SENSOR_SUB_BAK1),
        #endif    
    #endif
#endif


#if(defined(AKEER_OV5642_AD5820))
    #if (defined(OV5642_RAW_MAIN)||defined(OV5642_RAW_BAK1)||defined(OV5642_RAW_SUB)||defined(OV5642_RAW_SUB_BAK1))
        #if(defined(OV5642_RAW_MAIN))
            ADD_LENS_MODULE(OV5642_SENSOR_ID,AkeerOv5642Ad5820,IMAGE_SENSOR_MAIN),
        #endif    
        #if(defined(OV5642_RAW_BAK1))
            ADD_LENS_MODULE(OV5642_SENSOR_ID,AkeerOv5642Ad5820,IMAGE_SENSOR_BAK1),
        #endif    
        #if(defined(OV5642_RAW_SUB))
            ADD_LENS_MODULE(OV5642_SENSOR_ID,AkeerOv5642Ad5820,IMAGE_SENSOR_SUB),
        #endif    
        #if(defined(OV5642_RAW_SUB_BAK1))
            ADD_LENS_MODULE(OV5642_SENSOR_ID,AkeerOv5642Ad5820,IMAGE_SENSOR_SUB_BAK1),
        #endif    

    #else
        #if(defined(OV5642_MIPI_RAW_MAIN))
            ADD_LENS_MODULE(OV5642_MIPI_SENSOR_ID,AkeerOv5642Ad5820,IMAGE_SENSOR_MAIN),
        #endif    
        #if(defined(OV5642_MIPI_RAW_BAK1))
            ADD_LENS_MODULE(OV5642_MIPI_SENSOR_ID,AkeerOv5642Ad5820,IMAGE_SENSOR_BAK1),
        #endif    
        #if(defined(OV5642_MIPI_RAW_SUB))
            ADD_LENS_MODULE(OV5642_MIPI_SENSOR_ID,AkeerOv5642Ad5820,IMAGE_SENSOR_SUB),
        #endif    
        #if(defined(OV5642_MIPI_RAW_SUB_BAK1))
            ADD_LENS_MODULE(OV5642_MIPI_SENSOR_ID,AkeerOv5642Ad5820,IMAGE_SENSOR_SUB_BAK1),
        #endif    
    #endif
#endif    

#if(defined(ABICO_WZ36A333_OV3640_SITI_MD118B))
    #if (defined(OV3640_RAW_MAIN)||defined(OV3640_RAW_BAK1)||defined(OV3640_RAW_SUB)||defined(OV3640_RAW_SUB_BAK1))
	    #if(defined(OV3640_RAW_MAIN))
		    ADD_LENS_MODULE(OV3640_SENSOR_ID,AbicoWz36a333Ov3640SitiMd118b,IMAGE_SENSOR_MAIN),
	    #endif	  
	    #if(defined(OV3640_RAW_BAK1))
		    ADD_LENS_MODULE(OV3640_SENSOR_ID,AbicoWz36a333Ov3640SitiMd118b,IMAGE_SENSOR_BAK1),
	    #endif	  
	    #if(defined(OV3640_RAW_SUB))
		    ADD_LENS_MODULE(OV3640_SENSOR_ID,AbicoWz36a333Ov3640SitiMd118b,IMAGE_SENSOR_SUB),
	    #endif	  
	    #if(defined(OV3640_RAW_SUB_BAK1))
		    ADD_LENS_MODULE(OV3640_SENSOR_ID,AbicoWz36a333Ov3640SitiMd118b,IMAGE_SENSOR_SUB_BAK1),
	    #endif	  
	#endif	  
#endif

#if(defined(SUNNY_Q5M04B_MT9P015_BH6412GUL))
    #if (defined(MT9P015_RAW)||defined(MT9P015_RAW_BAK1)||defined(MT9P015_RAW_SUB)||defined(MT9P015_RAW_SUB_BAK1))
	    #if(defined(MT9P015_RAW_MAIN))
		    ADD_LENS_MODULE(MT9P015_SENSOR_ID,SunnyQ5m04bMt9p015Bh6412gul,IMAGE_SENSOR_MAIN),
	    #endif	  
	    #if(defined(MT9P015_RAW_BAK1))
		    ADD_LENS_MODULE(MT9P015_SENSOR_ID,SunnyQ5m04bMt9p015Bh6412gul,IMAGE_SENSOR_BAK1),
	    #endif	  
	    #if(defined(MT9P015_RAW_SUB))
		    ADD_LENS_MODULE(MT9P015_SENSOR_ID,SunnyQ5m04bMt9p015Bh6412gul,IMAGE_SENSOR_SUB),
	    #endif	  
	    #if(defined(MT9P015_RAW_SUB_BAK1))
		    ADD_LENS_MODULE(MT9P015_SENSOR_ID,SunnyQ5m04bMt9p015Bh6412gul,IMAGE_SENSOR_SUB_BAK1),
	    #endif	  
	#endif	  
#endif

#if(defined(SUNNY_P5D01A_ET8EV3_AD5820))
	#if (defined(ET8EV3_MIPI_RAW)||defined(ET8EV3_MIPI_RAW_BAK1)||defined(ET8EV3_MIPI_RAW_SUB)||defined(ET8EV3_MIPI_RAW_SUB_BAK1))
	    #if(defined(ET8EV3_MIPI_RAW_MAIN))
	        ADD_LENS_MODULE(ET8EV3_MIPI_SENSOR_ID,SunnyP5d01aEt8ev3Ad5820,IMAGE_SENSOR_MAIN),
	    #endif    
	    #if(defined(ET8EV3_MIPI_RAW_BAK1))
	        ADD_LENS_MODULE(ET8EV3_MIPI_SENSOR_ID,SunnyP5d01aEt8ev3Ad5820,IMAGE_SENSOR_BAK1),
	    #endif    
	    #if(defined(ET8EV3_MIPI_RAW_SUB))
	        ADD_LENS_MODULE(ET8EV3_MIPI_SENSOR_ID,SunnyP5d01aEt8ev3Ad5820,IMAGE_SENSOR_SUB),
	    #endif    
	    #if(defined(ET8EV3_MIPI_RAW_SUB_BAK1))
	        ADD_LENS_MODULE(ET8EV3_MIPI_SENSOR_ID,SunnyP5d01aEt8ev3Ad5820,IMAGE_SENSOR_SUB_BAK1),
	    #endif    
	#endif	  
#endif    

};



// for camera HAL
MM_ERROR_CODE_ENUM GetAfLensInitFunc(P_LENS_LIST_STRUCT *pLensList)
{
    *pLensList=&LensList[0];

	return MM_ERROR_NONE;
}



//#endif //#if (defined(AF_SUPPORT))



