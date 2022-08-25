/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *   flatten_api.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Flatten related function
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 * HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * $Log$
 *
 * 01 21 2014 hung-wen.hsieh
 * removed!
 * 	.
 *
 * 12 04 2013 hung-wen.hsieh
 * removed!
 * 	.
 *
 * 10 18 2013 hung-wen.hsieh
 * removed!
 * 	.
 *
 * 11 07 2012 hung-wen.hsieh
 * removed!
 * .
 * 
 * 10 16 2012 hung-wen.hsieh
 * removed!
 * .
 * 
 * 07 24 2012 haitao.shang
 * removed!
 * .
 *
 * 07 18 2012 haitao.shang
 * removed!
 * .
 *
 * 03 21 2012 xiaoyong.ye
 * removed!
 * Check in MT6250 G2D low light flatten driver.
 *
 * 12 19 2011 xiaoyong.ye
 * removed!
 * Flatten driver optimization code check in.
 *
 * 12 19 2011 xiaoyong.ye
 * removed!
 * Flatten driver optimization for lwf check in.
 *
 * 12 05 2011 haitao.shang
 * removed!
 * .
 *
 * 11 29 2011 haitao.shang
 * removed!
 * removed!
 * [MT6255]GOVL support check in
 *
 * 10 25 2011 xiaoyong.ye
 * removed!
 * 
 * Remove user_version_code for FlattenGetOwnership().
 *
 * 10 20 2011 xiaoyong.ye
 * removed!
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/******************************************************************************
 * include directives
 ******************************************************************************/
#include "kal_release.h"
#include "drv_sw_features_display.h"
#include "drv_features_display.h"
#include "flatten_api.h"

#ifdef __cplusplus
extern "C" {
#endif

extern kal_uint32 SaveAndSetIRQMask(void);
extern void RestoreIRQMask(kal_uint32);
extern kal_bool INT_QueryExceptionStatus(void);

#if defined(__GOVL_SUPPORT__) 

#include "flatten_api_internal.h"

#include "G2d_common_api.h"
#include "G2d_enum.h"

static FlattenCnxtStruct flatten_cnxt = {0};

#if defined(__GOVL_SUPPORT__)
static FlattenLayerStruct flatten_layer_data[DRV_GOVL_LAYER_TOTAL_COUNT] = {0};
#else
static FlattenLayerStruct flatten_layer_data[4] = {0};
#endif

#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
static G2D_HANDLE_STRUCT *g2d_handle;
#endif

static FlattenCtrlStruct flatten_ctrl_data = {0};
kal_bool system_init_status = KAL_FALSE;//to record the system_init_status

//Initialize in drv_init_phase1
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif
void FlattenInit(void)
{
#if defined(MT6236) 
    FlattenInit_6236( );
#elif defined(MT6276)
    FlattenInit_6276( );
#elif defined(MT6255)
    FlattenInit_6255( );
#elif defined(MT6250)	
    FlattenInit_6250( );
#elif (defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
    FlattenInit_6260( );
#endif
    flatten_cnxt.flatten_interface_user_count = 0;
    flatten_cnxt.occupy_user = 0;
    flatten_cnxt.flatten_interface_mutex = kal_create_sem("Flatten_API_Interface", 1);
}
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif

kal_uint32 FlattenGetUserHandle(void)
{ 
    kal_uint32 save_irq_mask;
    kal_uint32 user_handle;

    save_irq_mask = SaveAndSetIRQMask();
    user_handle = ++flatten_cnxt.flatten_interface_user_count;
    RestoreIRQMask(save_irq_mask);

    return user_handle;
}

FlattenResultEnum FlattenGetOwnership(kal_uint32 handle, kal_bool wait, kal_bool use_sw_flatten)
{
    FlattenResultEnum result = FLATTEN_RESULT_OK;
    
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
        //Get G2D ownership
        if(G2D_STATUS_OK != g2dGetHandle(&g2d_handle,G2D_CODEC_TYPE_HW,(KAL_TRUE == wait)?G2D_GET_HANDLE_MODE_BLOCKING_UNTIL_GET_HANDLE : G2D_GET_HANDLE_MODE_DIRECT_RETURN_HANDLE))
        {
            result = FLATTEN_RESULT_DEVICE_BUSY;
            goto FAIL;
        }
        //Set G2D owner
        if(G2D_STATUS_OK != g2dSetOwner(g2d_handle,G2D_CODEC_OWNER_GOVL))
        {
            result = FLATTEN_RESULT_DEVICE_BUSY;
            goto FAIL;
        }
        //Set callback function
        //if(KAL_TRUE == system_init_status)
        {
            system_init_status = kal_query_systemInit();// only in systemInit needs to check
        }    
        if ( (KAL_TRUE == system_init_status) || (INT_QueryExceptionStatus()) )
        {
            g2dSetCallbackFunction(g2d_handle,NULL);
        }
        else
        {
            #if defined(MT6255)
            g2dSetCallbackFunction(g2d_handle,(G2D_CALLBACK_FUNC_PTR)(FlattenHisr_6255));
            #elif defined(MT6250)
            g2dSetCallbackFunction(g2d_handle,(G2D_CALLBACK_FUNC_PTR)(FlattenHisr_6250));
            #elif (defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
            g2dSetCallbackFunction(g2d_handle,(G2D_CALLBACK_FUNC_PTR)(FlattenHisr_6260));
            #endif
        }
        if ( (0 == handle) || (flatten_cnxt.flatten_interface_user_count < handle) )
        {
            result = FLATTEN_RESULT_ILLEGAL_ARGUMENT;
            goto FAIL;
        }
        flatten_cnxt.occupy_user = handle; //use g2d lock for flatten user
        goto EXIT;
#else//defined(MT6255)....
    kal_uint32 save_irq_mask;
    save_irq_mask = SaveAndSetIRQMask();
    if ( (0 == handle) || (flatten_cnxt.flatten_interface_user_count < handle) )
    {
        result = FLATTEN_RESULT_ILLEGAL_ARGUMENT;
        RestoreIRQMask(save_irq_mask);
        goto EXIT;
    }
    //if(KAL_TRUE == system_init_status)
    {
        system_init_status = kal_query_systemInit();// only in systemInit needs to check
    } 
    RestoreIRQMask(save_irq_mask);

    //handle get ownership
    if ( (KAL_TRUE == system_init_status) || (INT_QueryExceptionStatus()) )
    {
        if (0 == flatten_cnxt.occupy_user) //Flatten APIs are available
        {
            flatten_cnxt.occupy_user = handle;
        } 
        else 
        {
            //there is someone occupy Flatten APIs, but when system inits or exception happens, we can not wait.
            result = FLATTEN_RESULT_DEVICE_BUSY;
            #if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
                //Release G2D ownership
                if(G2D_STATUS_OK != g2dReleaseHandle(g2d_handle))
                {
                    ASSERT(0);
                }
            #endif//defined(MT6255)...
            goto EXIT;
        }
    } 
    else //if ( (KAL_TRUE == system_init_status) || (INT_QueryExceptionStatus()) )
    { 
        if (KAL_TRUE == wait) 
        {
            kal_take_sem(flatten_cnxt.flatten_interface_mutex, KAL_INFINITE_WAIT);
            flatten_cnxt.occupy_user = handle;
        }
        else //if (KAL_TRUE == wait) 
        {
            if (KAL_SUCCESS == kal_take_sem(flatten_cnxt.flatten_interface_mutex, KAL_NO_WAIT))
            {                
                    flatten_cnxt.occupy_user = handle;
            }
            else //if (KAL_SUCCESS == kal_take_sem(flatten_cnxt.flatten_interface_mutex, KAL_NO_WAIT))
            { 
                result = FLATTEN_RESULT_DEVICE_BUSY;
                #if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
                    //Release G2D ownership
                    if(G2D_STATUS_OK != g2dReleaseHandle(g2d_handle))
                    {
                        ASSERT(0);
                    }
                #endif//defined(MT6250)...
                goto EXIT;
            }
        }        
    }
#endif//defined(MT6255)...
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
FAIL:
    //Release G2D ownership
    if(G2D_STATUS_OK != g2dReleaseHandle(g2d_handle))
    {
        ASSERT(0);
    }
#endif//defined(MT6255)...
EXIT:
    return result;    
}

FlattenResultEnum FlattenReleaseOwnership(kal_uint32 handle)
{ 
    FlattenResultEnum result = FLATTEN_RESULT_OK;
    //kal_uint32 save_irq_mask;
    
//    save_irq_mask = SaveAndSetIRQMask();
//    if ( (0 == handle) || (flatten_cnxt.flatten_interface_user_count < handle) || (flatten_cnxt.occupy_user != handle) )
    if ( (0 == handle) || (flatten_cnxt.occupy_user != handle) )

    {
        result = FLATTEN_RESULT_ILLEGAL_ARGUMENT;
//        RestoreIRQMask(save_irq_mask);
        goto EXIT;
    }       
//    RestoreIRQMask(save_irq_mask);
    flatten_cnxt.occupy_user = 0;
#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    //Release G2D ownership
    if(G2D_STATUS_OK != g2dReleaseHandle(g2d_handle))
    {
        ASSERT(0);
    }
#else //defined(MT6255)...
    if ( (KAL_TRUE == system_init_status) || (INT_QueryExceptionStatus()) )
    { 
        //nothing
    }
    else
    {
        kal_give_sem(flatten_cnxt.flatten_interface_mutex);
    }
#endif//!defined(MT6255)...
EXIT:
    return result;
}

FlattenResultEnum FlattenConfigLayer(kal_uint32 handle, FlattenLayerType flatten_layer, FlattenLayerStruct *flatten_layer_config)
{
    FlattenResultEnum result = FLATTEN_RESULT_OK;
    //kal_uint32 save_irq_mask;
//    save_irq_mask = SaveAndSetIRQMask();
//    if ( (0 == handle) || (flatten_cnxt.flatten_interface_user_count < handle) || (flatten_cnxt.occupy_user != handle) )
    if ( (0 == handle) || (flatten_cnxt.occupy_user != handle) )
    {
        result = FLATTEN_RESULT_ILLEGAL_ARGUMENT;
//        RestoreIRQMask(save_irq_mask);
        goto EXIT;
    }       
//    RestoreIRQMask(save_irq_mask);

    switch(flatten_layer)
    {
        case FLATTEN_LAYER0:
            kal_mem_cpy(&flatten_layer_data[0], flatten_layer_config, sizeof(FlattenLayerStruct));
            break;
        case FLATTEN_LAYER1:
            kal_mem_cpy(&flatten_layer_data[1], flatten_layer_config, sizeof(FlattenLayerStruct));
            break;
        case FLATTEN_LAYER2:
            kal_mem_cpy(&flatten_layer_data[2], flatten_layer_config, sizeof(FlattenLayerStruct));
            break;
        case FLATTEN_LAYER3:
            kal_mem_cpy(&flatten_layer_data[3], flatten_layer_config, sizeof(FlattenLayerStruct));
            break;
        default:
            result = FLATTEN_RESULT_ILLEGAL_ARGUMENT;
            break;
    }

EXIT:
    return result;
}

FlattenResultEnum FlattenStart(kal_uint32 handle, FlattenCtrlStruct *flatten_ctrl_config)
{ 
    FlattenResultEnum result;
    //kal_uint32 save_irq_mask;
 #if defined(FLATTEN_PERFORMANCE_PROFILING_SUPPORT)
 SLA_CustomLogging("FLS", 1);//FLS:Start Flatten setting register time profile
 #endif   
//    save_irq_mask = SaveAndSetIRQMask();
//    if ( (0 == handle) || (flatten_cnxt.flatten_interface_user_count < handle) || (flatten_cnxt.occupy_user != handle) )
    if ( (0 == handle) || (flatten_cnxt.occupy_user != handle) )
    {
        result = FLATTEN_RESULT_ILLEGAL_ARGUMENT;
//        RestoreIRQMask(save_irq_mask);
        goto EXIT;
    }       
//    RestoreIRQMask(save_irq_mask);
    kal_mem_cpy(&flatten_ctrl_data, flatten_ctrl_config, sizeof(FlattenCtrlStruct));

#if defined(MT6236)
    result = FlattenStart_6236(flatten_layer_data, flatten_ctrl_config);
#elif defined(MT6276)
    result = FlattenStart_6276(flatten_layer_data, flatten_ctrl_config);
#elif defined(MT6255)
    result = FlattenStart_6255(flatten_layer_data, flatten_ctrl_config);
#elif defined(MT6250)
    result = FlattenStart_6250(flatten_layer_data, flatten_ctrl_config);    
#elif (defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502))
    result = FlattenStart_6260(flatten_layer_data, flatten_ctrl_config);    
#endif

EXIT:
    return result;
}
#else //#if defined(__GOVL_SUPPORT__) 

//Initialize in drv_init_phase1
void FlattenInit(void)
{
}

kal_uint32 FlattenGetUserHandle(void)
{ 
    return 0;
}

FlattenResultEnum FlattenGetOwnership(kal_uint32 handle, kal_bool wait, kal_bool use_sw_flatten)
{ 
    return FLATTEN_RESULT_FAIL;
}

FlattenResultEnum FlattenReleaseOwnership(kal_uint32 handle)
{
    return FLATTEN_RESULT_FAIL;
}

FlattenResultEnum FlattenConfigLayer(kal_uint32 handle, FlattenLayerType flatten_layer, FlattenLayerStruct *flatten_layer_config)
{
    return FLATTEN_RESULT_FAIL;
}

FlattenResultEnum FlattenStart(kal_uint32 handle, FlattenCtrlStruct *flatten_ctrl_config)
{
    return FLATTEN_RESULT_FAIL;
}

#endif //#if defined(__GOVL_SUPPORT__) 

#ifdef __cplusplus
}
#endif

