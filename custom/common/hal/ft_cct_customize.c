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
 *
 * Filename:
 * ---------
 *  ft_cct_customize.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file contains ft task customized bt funcitons in META mode.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "ft_cct_customize.h"
#include "camera_nvram_def.h"
//#if (defined(DRV_ISP_6238_SERIES))	
#if (defined(ISP_SUPPORT) && defined(DRV_ISP_6238_SERIES))
#include "kal_non_specific_general_types.h" // RHR add
kal_uint32 g_camera_lid[]={
//#if (defined(DRV_ISP_6238_SERIES))	
#if(!(defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT)))	
        NVRAM_EF_CAMERA_PARA1_LID,
        NVRAM_EF_CAMERA_PARA2_LID,
        NVRAM_EF_CAMERA_DEFECT1_LID,
        NVRAM_EF_CAMERA_DEFECT2_LID,
        NVRAM_EF_CAMERA_SHADING1_LID,
        NVRAM_EF_CAMERA_SHADING2_LID,
#if defined(DRV_ISP_PCA_SUPPORT)
        NVRAM_EF_CAMERA_PCA_LID,
#endif
#else
        NVRAM_EF_CAMERA_PARA1_MAIN_LID,
        NVRAM_EF_CAMERA_PARA2_MAIN_LID,
        NVRAM_EF_CAMERA_DEFECT1_MAIN_LID,
        NVRAM_EF_CAMERA_DEFECT2_MAIN_LID,
        NVRAM_EF_CAMERA_SHADING1_MAIN_LID,
        NVRAM_EF_CAMERA_SHADING2_MAIN_LID,  
#if defined(DRV_ISP_PCA_SUPPORT)
        NVRAM_EF_CAMERA_PCA_MAIN_LID,
#endif
//#if (defined(CMOS_SENSOR_SUB)) //keep this sequence
        NVRAM_EF_CAMERA_PARA1_SUB_LID,
        NVRAM_EF_CAMERA_PARA2_SUB_LID,
        NVRAM_EF_CAMERA_DEFECT1_SUB_LID,
        NVRAM_EF_CAMERA_DEFECT2_SUB_LID,
        NVRAM_EF_CAMERA_SHADING1_SUB_LID,
        NVRAM_EF_CAMERA_SHADING2_SUB_LID,	
#if defined(DRV_ISP_PCA_SUPPORT)
        NVRAM_EF_CAMERA_PCA_SUB_LID,
#endif
//#endif
//#if (defined(CMOS_SENSOR_BAK1)) //keep this sequence
        NVRAM_EF_CAMERA_PARA1_MAIN_BAK1_LID,
        NVRAM_EF_CAMERA_PARA2_MAIN_BAK1_LID,
        NVRAM_EF_CAMERA_DEFECT1_MAIN_BAK1_LID,
        NVRAM_EF_CAMERA_DEFECT2_MAIN_BAK1_LID,
        NVRAM_EF_CAMERA_SHADING1_MAIN_BAK1_LID,
        NVRAM_EF_CAMERA_SHADING2_MAIN_BAK1_LID,  
#if defined(DRV_ISP_PCA_SUPPORT)
        NVRAM_EF_CAMERA_PCA_MAIN_BAK1_LID,
#endif
//#endif
//#if (defined(CMOS_SENSOR_SUB_BAK1)) //keep this sequence
        NVRAM_EF_CAMERA_PARA1_SUB_BAK1_LID,
        NVRAM_EF_CAMERA_PARA2_SUB_BAK1_LID,
        NVRAM_EF_CAMERA_DEFECT1_SUB_BAK1_LID,
        NVRAM_EF_CAMERA_DEFECT2_SUB_BAK1_LID,
        NVRAM_EF_CAMERA_SHADING1_SUB_BAK1_LID,
        NVRAM_EF_CAMERA_SHADING2_SUB_BAK1_LID,
#if defined(DRV_ISP_PCA_SUPPORT)
        NVRAM_EF_CAMERA_PCA_SUB_BAK1_LID,
#endif
//#endif
#endif//#if(!(defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT)))	        
/*
#else
		 NVRAM_EF_CAMERA_PARA_LID
#if (!(defined(MT6219)||defined(MT6228)))
		,NVRAM_EF_CAMERA_GAMMA_LID
#endif
#if (!defined(MT6219))
		,NVRAM_EF_CAMERA_DEFECT_LID
		,NVRAM_EF_CAMERA_LENS_LID
#endif

*/
	};


kal_uint32 g_camera_lid_count = sizeof(g_camera_lid)/sizeof(kal_uint32);


#if (defined(ISP_SUPPORT))

camera_para_struct_copy	g_camera_para_table[]=
{
#if(!(defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT)))	
	 { "NVRAM_EF_CAMERA_PARA1_LID",		"nvram_camera_para_struct",		"camera_para"		    	}	
	,{ "NVRAM_EF_CAMERA_PARA2_LID",		"nvram_camera_3a_struct",	    		"camera_3a"          	 }
	,{ "NVRAM_EF_CAMERA_DEFECT1_LID",	"nvram_camera_defect1_struct",		"camera_defect1"	   	 }
	,{ "NVRAM_EF_CAMERA_DEFECT2_LID",	"nvram_camera_defect2_struct",		"camera_defect2"		}
      ,{ "NVRAM_EF_CAMERA_SHADING1_LID",	"nvram_camera_shading1_struct",	"camera_shading1"		}
      ,{ "NVRAM_EF_CAMERA_SHADING2_LID",	"nvram_camera_shading2_struct",	"camera_shading2"		}
#if defined(DRV_ISP_PCA_SUPPORT)
	,{ "NVRAM_EF_CAMERA_PCA_LID",	"nvram_camera_pca_struct",	"camera_pca"		}
#endif
#else
	 { "NVRAM_EF_CAMERA_PARA1_MAIN_LID",	"nvram_camera_para_struct",		"camera_para_main"	 	}	
	,{ "NVRAM_EF_CAMERA_PARA2_MAIN_LID",	"nvram_camera_3a_struct",	    		"camera_3a_main"    	       }
	,{ "NVRAM_EF_CAMERA_DEFECT1_MAIN_LID",	"nvram_camera_defect1_struct",		"camera_deect1_main"	    	}
	,{ "NVRAM_EF_CAMERA_DEFECT2_MAIN_LID",	"nvram_camera_defect2_struct",		"camera_defect2_main"		}
      ,{ "NVRAM_EF_CAMERA_SHADING1_MAIN_LID",	"nvram_camera_shading1_struct",	"camera_shading1_main"	}
      ,{ "NVRAM_EF_CAMERA_SHADING2_MAIN_LID",	"nvram_camera_shading2_struct",	"camera_shading2_main"	}
#if defined(DRV_ISP_PCA_SUPPORT)
	,{ "NVRAM_EF_CAMERA_PCA_MAIN_LID",	"nvram_camera_pca_struct",	"camera_pca_main"	}
#endif
//#if (defined(CMOS_SENSOR_SUB)) /*keep this sequence*/
	,{ "NVRAM_EF_CAMERA_PARA1_SUB_LID",		"nvram_camera_para_struct",		"camera_para_sub"	 	}	
	,{ "NVRAM_EF_CAMERA_PARA2_SUB_LID",		"nvram_camera_3a_struct",	    		"camera_3a_sub"    	       }
	,{ "NVRAM_EF_CAMERA_DEFECT1_SUB_LID",	"nvram_camera_defect1_struct",		"camera_deect1_sub"	    	}
	,{ "NVRAM_EF_CAMERA_DEFECT2_SUB_LID",	"nvram_camera_defect2_struct",		"camera_defect2_sub"		}
      ,{ "NVRAM_EF_CAMERA_SHADING1_SUB_LID",	"nvram_camera_shading1_struct",	"camera_shading1_sub"	}
      ,{ "NVRAM_EF_CAMERA_SHADING2_SUB_LID",	"nvram_camera_shading2_struct",	"camera_shading2_sub"	}
#if defined(DRV_ISP_PCA_SUPPORT)
	,{ "NVRAM_EF_CAMERA_PCA_SUB_LID",	"nvram_camera_pca_struct",	"camera_pca_sub"	}
#endif
//#endif
//#if (defined(CMOS_SENSOR_BAK1)) /*keep this sequence*/
	,{ "NVRAM_EF_CAMERA_PARA1_MAIN_BAK1_LID",		"nvram_camera_para_struct",		"camera_para_main_bak1"	 	}	
	,{ "NVRAM_EF_CAMERA_PARA2_MAIN_BAK1_LID",		"nvram_camera_3a_struct",	    		"camera_3a_main_bak1"    	       }
	,{ "NVRAM_EF_CAMERA_DEFECT1_MAIN_BAK1_LID",	"nvram_camera_defect1_struct",			"camera_deect1_main_bak1"	    	}
	,{ "NVRAM_EF_CAMERA_DEFECT2_MAIN_BAK1_LID",	"nvram_camera_defect2_struct",			"camera_defect2_main_bak1"	}
      ,{ "NVRAM_EF_CAMERA_SHADING1_MAIN_BAK1_LID",	"nvram_camera_shading1_struct",	"camera_shading1_main_bak1"	}
      ,{ "NVRAM_EF_CAMERA_SHADING2_MAIN_BAK1_LID",	"nvram_camera_shading2_struct",	"camera_shading2_main_bak1"	}
#if defined(DRV_ISP_PCA_SUPPORT)
	,{ "NVRAM_EF_CAMERA_PCA_MAIN_BAK1_LID",	"nvram_camera_pca_struct",	"camera_pca_main_bak1"	}
#endif
//#endif
//#if (defined(CMOS_SENSOR_SUB_BAK1)) /*keep this sequence*/
	,{ "NVRAM_EF_CAMERA_PARA1_SUB_BAK1_LID",		"nvram_camera_para_struct",		"camera_para_sub_bak1"	 	}	
	,{ "NVRAM_EF_CAMERA_PARA2_SUB_BAK1_LID",		"nvram_camera_3a_struct",	    		"camera_3a_sub_bak1"    	       }
	,{ "NVRAM_EF_CAMERA_DEFECT1_SUB_BAK1_LID",	"nvram_camera_defect1_struct",			"camera_deect1_sub_bak1"	    	}
	,{ "NVRAM_EF_CAMERA_DEFECT2_SUB_BAK1_LID",	"nvram_camera_defect2_struct",			"camera_defect2_sub_bak1"		}
      ,{ "NVRAM_EF_CAMERA_SHADING1_SUB_BAK1_LID",	"nvram_camera_shading1_struct",		"camera_shading1_sub_bak1"	}
      ,{ "NVRAM_EF_CAMERA_SHADING2_SUB_BAK1_LID",	"nvram_camera_shading2_struct",		"camera_shading2_sub_bak1"	}
#if defined(DRV_ISP_PCA_SUPPORT)
	,{ "NVRAM_EF_CAMERA_PCA_SUB_BAK1_LID",	"nvram_camera_pca_struct",		"camera_pca_sub_bak1"	}
#endif
//#endif
#endif//#if(!(defined(DUAL_CAMERA_SUPPORT) || defined(BACKUP_SENSOR_SUPPORT)))	        
};

kal_uint32 g_camera_para_table_size = sizeof(g_camera_para_table) / sizeof(camera_para_struct_copy);
#endif

#endif

#if (defined(ISP_SUPPORT)&&( defined(DRV_ISP_6238_SERIES)))
kal_bool custom_ft_util_check_if_dual_camera_sensor_support(void)
{
	#if (defined(DUAL_CAMERA_SUPPORT))
		return KAL_TRUE;
	#else
		return KAL_FALSE;
	#endif
}

kal_bool custom_ft_util_check_if_backup_camera_sensor_support(void)
{
	#if (defined(BACKUP_SENSOR_SUPPORT))
		return KAL_TRUE;
	#else
		return KAL_FALSE;
	#endif

}

kal_bool custom_ft_util_check_if_camera_YUV_support(void)
{
	#if (defined(YUV_SENSOR_SUPPORT))
		return KAL_TRUE;
	#else
		return KAL_FALSE;
	#endif
}

kal_bool custom_ft_util_check_if_camera_mshutter_support(void)
{
	#if (defined(MSHUTTER_SUPPORT))		
		return KAL_TRUE;
	#else
		return KAL_FALSE;
	#endif
}
#endif
/*
kal_bool custom_ft_util_check_main_sensor_type_not_YUV(void)
{      
	#if (defined(SENSOR_TYPE))
		#if (SENSOR_TYPE = YUV)
			return KAL_TRUE;
		#else if(SENSOR_TYPE = RAW)
			return KAL_FALSE;	
		#else
			return KAL_FALSE;
		#endif  
	#else
		return KAL_FALSE;
	#endif
		//return SENSOR_NONE;
}

kal_bool custom_ft_util_check_sub_sensor_type_not_YUV(void)
{
	return KAL_TRUE;
	
	#if (defined(SENSOR_TYPE_SUB))
		#if (SENSOR_TYPE_SUB == YUV)
			return SENSOR_YUV;
		#else if(SENSOR_TYPE == RAW)
			return SENSOR_RAW;
		#else
			return SENSOR_NONE;
		#endif  
	#else
		return SENSOR_NONE;
	
}
*/
//============================================================================================
