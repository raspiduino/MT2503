/* Needed header files of the compile option in XML files, if you need others need to add here */

#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_SDK_TEST">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
   
    <STRING id="STR_ID_VS_MM_AUDIO_001">"vs_mm_audio_001_play_id"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_002">"vs_mm_audio_002_play_string"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_003">"vs_mm_audio_003_play_string_vol_path"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_004">"vs_mm_audio_004_play_string_portion_vol_path"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_005">"vs_mm_audio_005_play_string_vol_path_non_block"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_006">"vs_mm_audio_006_play_file"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_007">"vs_mm_audio_007_play_file_vol_path"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_008">"vs_mm_audio_008_play_file_portion_vol_path"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_009">"vs_mm_audio_009_record"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_010">"vs_mm_audio_010_bg_play"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_011">"vs_mm_audio_011_snd_play_string"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_012">"vs_mm_audio_012_snd_play_file"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_013">"vs_mm_audio_013_build_cache"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_014">"vs_mm_audio_014_tts"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_015">"vs_mm_audio_015_eq"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_016">"vs_mm_audio_016_reverb"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_017">"vs_mm_audio_017_surround"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_018">"vs_mm_audio_018_spectrum"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_019">"vs_mm_audio_019_stretch_file"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_020">"vs_mm_audio_020_stretch_string"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_021">"vs_mm_audio_021_speech"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_022">"vs_mm_audio_022_fmr"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_023">"vs_mm_audio_023_mma"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_024">"vs_mm_audio_024_play_error_file"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_025">"vs_mm_audio_025_stream_play"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_026">"vs_mm_audio_026_bass"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_027">"vs_mm_audio_027_bt_volume"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_028">"vs_mm_audio_028_play_text"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_029">"vs_mm_audio_029_bg_play_by_app"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_030">"vs_mm_audio_030_play_vocie_tag"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_031">"vs_mm_audio_031_vr_record"</STRING>
    <STRING id="STR_ID_VS_MM_VIDEO_001">"vs_mm_video_001_file_play"</STRING>
    <STRING id="STR_ID_VS_MM_VIDEO_002">"vs_mm_video_002_clip_play"</STRING>
    <STRING id="STR_ID_VS_MM_VIDEO_003">"vs_mm_video_003_id_play"</STRING>
    <STRING id="STR_ID_VS_MM_VIDEO_004">"vs_mm_video_004_buffer_play"</STRING>
    <STRING id="STR_ID_VS_MM_VIDEO_005">"vs_mm_video_005_record"</STRING>
    <STRING id="STR_ID_VS_MM_VIDEO_006">"vs_mm_video_006_record_error"</STRING>
    <STRING id="STR_ID_VS_MM_VIDEO_007">"vs_mm_video_007_stream_play"</STRING>
    <STRING id="STR_ID_VS_MM_VIDEO_008">"vs_mm_video_008_pdl"</STRING>
    <STRING id="STR_ID_VS_MM_CAMERA_001">"vs_mm_camera_001"</STRING>
    <STRING id="STR_ID_VS_MM_CAMERA_002">"vs_mm_camera_002"</STRING>
    <STRING id="STR_ID_VS_MM_CAMERA_003">"vs_mm_camera_003"</STRING>
    <STRING id="STR_ID_VS_MM_CAMERA_004">"vs_mm_camera_004"</STRING>
    <STRING id="STR_ID_VS_MM_MAIN">"multimedia test"</STRING>
    <STRING id="STR_ID_VS_MM_PASS">"Pass"</STRING>
    <STRING id="STR_ID_VS_MM_FAIL">"Fail"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO">"audio test"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_TTS">"hello world"</STRING>
    <STRING id="STR_ID_VS_MM_VIDEO">"video test"</STRING>
    <STRING id="STR_ID_VS_MM_CAMERA">"camera test"</STRING>
    <STRING id="STR_ID_VS_MM_PROFILE">"profile"</STRING>
    <STRING id="STR_ID_VS_MM_BITSTREAM">"bitstream"</STRING>
    <STRING id="STR_ID_VS_MM_IDLESCREEN">"idlescreen"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_032">"vs_mm_audio_032"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_033">"vs_mm_audio_033"</STRING>
    <STRING id="STR_ID_VS_MM_AUDIO_034">"vs_mm_audio_034"</STRING>
    
    
    <!------------------DRM------------------------->
		<STRING id="STR_ID_VS_MM_DRM">"DRM"</STRING>
    <STRING id="STR_ID_VS_MM_DRM_001">"drm_install_object"</STRING>
    <STRING id="STR_ID_VS_MM_DRM_002">"drm_consume"</STRING>
    <STRING id="STR_ID_VS_MM_DRM_003">"drm_file_rights_register"</STRING>
    <STRING id="STR_ID_VS_MM_DRM_004">"drm_content_object"</STRING>
    <STRING id="STR_ID_VS_MM_DRM_005">"drm_get_meta"</STRING>
    <STRING id="STR_ID_VS_MM_DRM_006">"drm_permission_check"</STRING>
		<STRING id="STR_ID_VS_MM_DRM_007">"drm_file_seek"</STRING>
		<STRING id="STR_ID_VS_MM_DRM_008">"drm_sd_check"</STRING>    
    <STRING id="STR_ID_VS_MM_DRM_009">"drm_consume_timed"</STRING>
    <STRING id="STR_ID_VS_MM_DRM_010">"drm_consume_module"</STRING>
    <STRING id="STR_ID_VS_MM_DRM_011">"drm_consume_timed_module"</STRING>
    <STRING id="STR_ID_VS_MM_DRM_012">"drm_consume_cid"</STRING>
    <STRING id="STR_ID_VS_MM_DRM_013">"drm_consume_timed_cid"</STRING>
    <STRING id="STR_ID_VS_MM_DRM_014">"drm_cancel_process"</STRING>
    <STRING id="STR_ID_VS_MM_DRM_015">"DRM Test All"</STRING>
    <!------------------DRM-END------------------------>
    <STRING id="STR_ID_VS_MM_TEST_ALL">"test all"</STRING>
    
    <STRING id="STR_ID_VS_IDLESCREEN_001">"vs_service_idlescreen_001_nw_get_name"</STRING>
    <STRING id="STR_ID_VS_IDLESCREEN_002">"vs_service_idlescreen_002_nw_get_name_ex"</STRING>
    <STRING id="STR_ID_VS_IDLESCREEN_003">"vs_service_idlescreen_003_nw_get_name_if_any"</STRING>
    <STRING id="STR_ID_VS_IDLESCREEN_004">"vs_service_idlescreen_004_nw_get_spn"</STRING>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="IMG_ID_VS_MM_PLAY">"..\\\\DevResource\\\\Images\\\\boy.gif"</IMAGE>
    <IMAGE id="IMG_ID_VS_MM_CLOCK">"..\\\\DevResource\\\\Images\\\\smile.png"</IMAGE>
    <IMAGE id="IMG_ID_VS_MM_MAIN">"..\\\\DevResource\\\\Images\\\\smile.png"</IMAGE>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    <!--Menu Tree Area-->
    /* MM Main Menu*/
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_001" str="STR_ID_VS_MM_AUDIO_001" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_002" str="STR_ID_VS_MM_AUDIO_002" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_003" str="STR_ID_VS_MM_AUDIO_003" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_004" str="STR_ID_VS_MM_AUDIO_004" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_005" str="STR_ID_VS_MM_AUDIO_005" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_006" str="STR_ID_VS_MM_AUDIO_006" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_007" str="STR_ID_VS_MM_AUDIO_007" img="IMG_ID_VS_MM_MAIN" />     
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_008" str="STR_ID_VS_MM_AUDIO_008" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_009" str="STR_ID_VS_MM_AUDIO_009" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_010" str="STR_ID_VS_MM_AUDIO_010" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_011" str="STR_ID_VS_MM_AUDIO_011" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_012" str="STR_ID_VS_MM_AUDIO_012" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_013" str="STR_ID_VS_MM_AUDIO_013" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_014" str="STR_ID_VS_MM_AUDIO_014" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_015" str="STR_ID_VS_MM_AUDIO_015" img="IMG_ID_VS_MM_MAIN" />     
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_016" str="STR_ID_VS_MM_AUDIO_016" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_017" str="STR_ID_VS_MM_AUDIO_017" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_018" str="STR_ID_VS_MM_AUDIO_018" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_019" str="STR_ID_VS_MM_AUDIO_019" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_020" str="STR_ID_VS_MM_AUDIO_020" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_021" str="STR_ID_VS_MM_AUDIO_021" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_022" str="STR_ID_VS_MM_AUDIO_022" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_023" str="STR_ID_VS_MM_AUDIO_023" img="IMG_ID_VS_MM_MAIN" />     
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_024" str="STR_ID_VS_MM_AUDIO_024" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_025" str="STR_ID_VS_MM_AUDIO_025" img="IMG_ID_VS_MM_MAIN" /> 
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_026" str="STR_ID_VS_MM_AUDIO_026" img="IMG_ID_VS_MM_MAIN" /> 
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_027" str="STR_ID_VS_MM_AUDIO_027" img="IMG_ID_VS_MM_MAIN" /> 
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_028" str="STR_ID_VS_MM_AUDIO_028" img="IMG_ID_VS_MM_MAIN" /> 
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_029" str="STR_ID_VS_MM_AUDIO_029" img="IMG_ID_VS_MM_MAIN" /> 
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_029" str="STR_ID_VS_MM_AUDIO_029" img="IMG_ID_VS_MM_MAIN" /> 
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_030" str="STR_ID_VS_MM_AUDIO_030" img="IMG_ID_VS_MM_MAIN" /> 
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_031" str="STR_ID_VS_MM_AUDIO_031" img="IMG_ID_VS_MM_MAIN" /> 
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_032" str="STR_ID_VS_MM_AUDIO_032" img="IMG_ID_VS_MM_MAIN" /> 
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_033" str="STR_ID_VS_MM_AUDIO_033" img="IMG_ID_VS_MM_MAIN" /> 
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_034" str="STR_ID_VS_MM_AUDIO_034" img="IMG_ID_VS_MM_MAIN" /> 
    <MENUITEM id="MENU_ID_VS_MM_AUDIO_TEST_ALL" str="STR_ID_VS_MM_TEST_ALL" img="IMG_ID_VS_MM_MAIN" /> 
    <MENU id="MENU_ID_VS_MM_AUDIO" type="APP_SUB" str="STR_ID_VS_MM_AUDIO" img="IMG_ID_VS_MM_MAIN">
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_001</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_002</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_003</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_004</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_005</MENUITEM_ID>          
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_006</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_007</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_008</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_009</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_010</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_011</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_012</MENUITEM_ID>   
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_013</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_014</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_015</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_016</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_017</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_018</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_019</MENUITEM_ID>          
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_020</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_021</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_022</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_023</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_024</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_025</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_026</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_027</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_028</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_029</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_030</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_031</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_032</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_033</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_034</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO_TEST_ALL</MENUITEM_ID>          
    </MENU>
        
    <MENUITEM id="MENU_ID_VS_MM_VIDEO_001" str="STR_ID_VS_MM_VIDEO_001" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_VIDEO_002" str="STR_ID_VS_MM_VIDEO_002" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_VIDEO_003" str="STR_ID_VS_MM_VIDEO_003" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_VIDEO_004" str="STR_ID_VS_MM_VIDEO_004" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_VIDEO_005" str="STR_ID_VS_MM_VIDEO_005" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_VIDEO_006" str="STR_ID_VS_MM_VIDEO_006" img="IMG_ID_VS_MM_MAIN" />
    <MENUITEM id="MENU_ID_VS_MM_VIDEO_007" str="STR_ID_VS_MM_VIDEO_007" img="IMG_ID_VS_MM_MAIN" />
    <MENUITEM id="MENU_ID_VS_MM_VIDEO_008" str="STR_ID_VS_MM_VIDEO_008" img="IMG_ID_VS_MM_MAIN" />
    <MENUITEM id="MENU_ID_VS_MM_VIDEO_TEST_ALL" str="STR_ID_VS_MM_TEST_ALL" img="IMG_ID_VS_MM_MAIN" /> 
    <MENU id="MENU_ID_VS_MM_VIDEO" type="APP_SUB" str="STR_ID_VS_MM_VIDEO" img="IMG_ID_VS_MM_MAIN">
        <MENUITEM_ID>MENU_ID_VS_MM_VIDEO_001</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_VIDEO_002</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_VIDEO_003</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_VIDEO_004</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_VIDEO_005</MENUITEM_ID>          
        <MENUITEM_ID>MENU_ID_VS_MM_VIDEO_006</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_VIDEO_007</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_VIDEO_008</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_VIDEO_TEST_ALL</MENUITEM_ID>
    </MENU> 
    
    <MENUITEM id="MENU_ID_VS_MM_CAMERA_001" str="STR_ID_VS_MM_CAMERA_001" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_CAMERA_002" str="STR_ID_VS_MM_CAMERA_002" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_CAMERA_003" str="STR_ID_VS_MM_CAMERA_003" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_CAMERA_004" str="STR_ID_VS_MM_CAMERA_004" img="IMG_ID_VS_MM_MAIN" />    
    <MENUITEM id="MENU_ID_VS_MM_CAMERA_TEST_ALL" str="STR_ID_VS_MM_TEST_ALL" img="IMG_ID_VS_MM_MAIN" />     
    <MENU id="MENU_ID_VS_MM_CAMERA" type="APP_SUB" str="STR_ID_VS_MM_CAMERA" img="IMG_ID_VS_MM_MAIN">
        <MENUITEM_ID>MENU_ID_VS_MM_CAMERA_001</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_CAMERA_002</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_CAMERA_003</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_CAMERA_004</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_CAMERA_TEST_ALL</MENUITEM_ID>
    </MENU> 
    

    
    <!------------------DRM------------------------->
    <MENUITEM id="MENU_ID_VS_MM_DRM_001" str="STR_ID_VS_MM_DRM_001" img="IMG_ID_VS_MM_MAIN" />   
    <MENUITEM id="MENU_ID_VS_MM_DRM_002" str="STR_ID_VS_MM_DRM_002" img="IMG_ID_VS_MM_MAIN" />
    <MENUITEM id="MENU_ID_VS_MM_DRM_003" str="STR_ID_VS_MM_DRM_003" img="IMG_ID_VS_MM_MAIN" />
    <MENUITEM id="MENU_ID_VS_MM_DRM_004" str="STR_ID_VS_MM_DRM_004" img="IMG_ID_VS_MM_MAIN" />
    <MENUITEM id="MENU_ID_VS_MM_DRM_005" str="STR_ID_VS_MM_DRM_005" img="IMG_ID_VS_MM_MAIN" />
    <MENUITEM id="MENU_ID_VS_MM_DRM_006" str="STR_ID_VS_MM_DRM_006" img="IMG_ID_VS_MM_MAIN" />
    <MENUITEM id="MENU_ID_VS_MM_DRM_007" str="STR_ID_VS_MM_DRM_007" img="IMG_ID_VS_MM_MAIN" />
   	<MENUITEM id="MENU_ID_VS_MM_DRM_008" str="STR_ID_VS_MM_DRM_008" img="IMG_ID_VS_MM_MAIN" />
   	<MENUITEM id="MENU_ID_VS_MM_DRM_009" str="STR_ID_VS_MM_DRM_009" img="IMG_ID_VS_MM_MAIN" />
   	<MENUITEM id="MENU_ID_VS_MM_DRM_010" str="STR_ID_VS_MM_DRM_010" img="IMG_ID_VS_MM_MAIN" />
   	<MENUITEM id="MENU_ID_VS_MM_DRM_011" str="STR_ID_VS_MM_DRM_011" img="IMG_ID_VS_MM_MAIN" />
   	<MENUITEM id="MENU_ID_VS_MM_DRM_012" str="STR_ID_VS_MM_DRM_012" img="IMG_ID_VS_MM_MAIN" />
   	<MENUITEM id="MENU_ID_VS_MM_DRM_013" str="STR_ID_VS_MM_DRM_013" img="IMG_ID_VS_MM_MAIN" />
   	<MENUITEM id="MENU_ID_VS_MM_DRM_014" str="STR_ID_VS_MM_DRM_014" img="IMG_ID_VS_MM_MAIN" />
   	<MENUITEM id="MENU_ID_VS_MM_DRM_015" str="STR_ID_VS_MM_DRM_015" img="IMG_ID_VS_MM_MAIN" />
   	
   	 
    <MENU id="MENU_ID_VS_MM_DRM" type="APP_SUB" str="STR_ID_VS_MM_DRM" img="IMG_ID_VS_MM_MAIN">
    <MENUITEM_ID>MENU_ID_VS_MM_DRM_001</MENUITEM_ID>
    <MENUITEM_ID>MENU_ID_VS_MM_DRM_002</MENUITEM_ID>
    <MENUITEM_ID>MENU_ID_VS_MM_DRM_003</MENUITEM_ID>
    <MENUITEM_ID>MENU_ID_VS_MM_DRM_004</MENUITEM_ID>
    <MENUITEM_ID>MENU_ID_VS_MM_DRM_005</MENUITEM_ID>
    <MENUITEM_ID>MENU_ID_VS_MM_DRM_006</MENUITEM_ID>
    <MENUITEM_ID>MENU_ID_VS_MM_DRM_007</MENUITEM_ID>
    <MENUITEM_ID>MENU_ID_VS_MM_DRM_008</MENUITEM_ID>
    <MENUITEM_ID>MENU_ID_VS_MM_DRM_009</MENUITEM_ID>
    <MENUITEM_ID>MENU_ID_VS_MM_DRM_010</MENUITEM_ID>
    <MENUITEM_ID>MENU_ID_VS_MM_DRM_011</MENUITEM_ID>
    <MENUITEM_ID>MENU_ID_VS_MM_DRM_012</MENUITEM_ID>
    <MENUITEM_ID>MENU_ID_VS_MM_DRM_013</MENUITEM_ID>
    <MENUITEM_ID>MENU_ID_VS_MM_DRM_014</MENUITEM_ID>
    <MENUITEM_ID>MENU_ID_VS_MM_DRM_015</MENUITEM_ID>
    </MENU>
    
    
    <!------------------DRM-END------------------------>

    <MENUITEM id="MENU_ID_VS_MM_PROFILE" str="STR_ID_VS_MM_PROFILE" img="IMG_ID_VS_MM_MAIN" />
    <MENUITEM id="MENU_ID_VS_MM_BITSTREAM" str="STR_ID_VS_MM_BITSTREAM" img="IMG_ID_VS_MM_MAIN" />
    <MENUITEM id="MENU_ID_VS_IDLESCREEN" str="STR_ID_VS_MM_IDLESCREEN" img="IMG_ID_VS_MM_MAIN" />
    <MENUITEM id="MENU_ID_VS_MM_TEST_ALL" str="STR_ID_VS_MM_TEST_ALL" img="IMG_ID_VS_MM_MAIN" />
    
    <MENU id="MENU_ID_VS_MM_MAIN" type="APP_MAIN" str="STR_ID_VS_MM_MAIN" img="IMG_ID_VS_MM_MAIN">
        <MENUITEM_ID>MENU_ID_VS_MM_AUDIO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_VIDEO</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_CAMERA</MENUITEM_ID>
				<MENUITEM_ID>MENU_ID_VS_MM_DRM</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_PROFILE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_BITSTREAM</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_IDLESCREEN</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VS_MM_TEST_ALL</MENUITEM_ID>
    </MENU>
 

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    
    <SCREEN id="SCR_ID_VS_MM_MAIN"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO_PLAY"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO_BG_PLAY"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO_RECORD"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO_TTS"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO_EQ"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO_REVERB"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO_SURROUND"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO_VIBRATOR"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO_SPECTRUM"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO_STRETCH"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO_SPEECH"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO_FRM"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO_MMA"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO_STREAM"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO_BASS"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO_BT_VOLUME"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO_FMR_RDS"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO_BG_PLAY_BY_APP"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO_030"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO_031"/>
    <SCREEN id="SCR_ID_VS_MM_AUDIO_032"/>	
    <SCREEN id="SCR_ID_VS_MM_AUDIO_033"/>	
    <SCREEN id="SCR_ID_VS_MM_AUDIO_034"/>	
    <SCREEN id="SCR_ID_VS_MM_VIDEO"/>
    <SCREEN id="SCR_ID_VS_MM_VIDEO_FILE_OPTION"/>
    <SCREEN id="SCR_ID_VS_MM_VIDEO_FILE_SETTING"/>
    <SCREEN id="SCR_ID_VS_MM_VIDEO_001_FILE_PLAY"/>
    <SCREEN id="SCR_ID_VS_MM_VIDEO_0_FILE_PLAY"/>
    <SCREEN id="SCR_ID_VS_MM_VIDEO_007_CLIP_PLAY"/>
    <SCREEN id="SCR_ID_VS_MM_VIDEO_011"/>
    <SCREEN id="SCR_ID_VS_MM_VIDEO_012"/>
    <SCREEN id="SCR_ID_VS_MM_VIDEO_013"/>
    <SCREEN id="SCR_ID_VS_MM_VIDEO_014"/>
    <SCREEN id="SCR_ID_VS_MM_VIDEO_015"/>
    <SCREEN id="SCR_ID_VS_MM_CAMERA_011"/>
    <SCREEN id="SCR_ID_VS_MM_CAMERA_012"/>
    <SCREEN id="SCR_ID_VS_MM_CAMERA_013"/>
    <SCREEN id="SCR_ID_VS_MM_CAMERA_014"/>
    <SCREEN id="SCR_ID_VS_MM_CAMERA_015"/>
    <SCREEN id="SCR_ID_VS_MM_CAMERA"/>
    <SCREEN id="SCR_ID_VS_MM_DRM"/>
    <SCREEN id="SCR_ID_VS_MM_BITSTREAM"/>
    <SCREEN id="SCR_ID_VS_MM_BITSTREAM_AUDIO_RECORD"/>
    <SCREEN id="SCR_ID_VS_PROFILE_001"/>
    <SCREEN id="SCR_ID_VS_PROFILE_002"/>
    <SCREEN id="SCR_ID_VS_PROFILE_003"/>
    <SCREEN id="SCR_ID_VS_PROFILE_004"/>
    <SCREEN id="SCR_ID_VS_PROFILE_005"/>
    <SCREEN id="SCR_ID_VS_PROFILE_006"/>
    <SCREEN id="SCR_ID_VS_PROFILE_007"/>
    <SCREEN id="SCR_ID_VS_PROFILE_008"/>
    <SCREEN id="SCR_ID_VS_PROFILE_009"/>
    <SCREEN id="SCR_ID_VS_PROFILE_010"/>
    <SCREEN id="SCR_ID_VS_IDLESCREEN_001"/>
    <SCREEN id="SCR_ID_VS_IDLESCREEN_002"/>
    <SCREEN id="SCR_ID_VS_IDLESCREEN_003"/>
    <SCREEN id="SCR_ID_VS_IDLESCREEN_004"/>
    <SCREEN id="SCR_ID_VS_IDLESCREEN_005"/>
    <SCREEN id="SCR_ID_VS_IDLESCREEN_006"/>
    <SCREEN id="SCR_ID_VS_IDLESCREEN_007"/>
    <SCREEN id="SCR_ID_VS_IDLESCREEN_008"/>
    <SCREEN id="SCR_ID_VS_IDLESCREEN_009"/>
    <SCREEN id="SCR_ID_VS_IDLESCREEN_010"/>
 
    <!------------------------------------------------------Audio---------------------------------------------------------->

    <AUDIO id="AUD_ID_VS_MM_SND_PLAY">CUST_ADO_PATH"\\\\SDK_TEST\\\\Effect07.wav"</AUDIO>
    <AUDIO id="AUD_ID_VS_MM_WAV_PLAY">CUST_ADO_PATH"\\\\SDK_TEST\\\\audio.wav"</AUDIO>
  	<AUDIO id="AUD_ID_VS_MM_IMY_PLAY">CUST_ADO_PATH"\\\\SDK_TEST\\\\audio.imy"</AUDIO>
    <AUDIO id="AUD_ID_VS_MM_AMR_PLAY">CUST_ADO_PATH"\\\\SDK_TEST\\\\audio.amr"</AUDIO>
    <AUDIO id="AUD_ID_VS_MM_MID_PLAY">CUST_ADO_PATH"\\\\SDK_TEST\\\\audio.mid"</AUDIO>
    <AUDIO id="AUD_ID_VS_MM_AWB_PLAY">CUST_ADO_PATH"\\\\SDK_TEST\\\\audio.awb"</AUDIO>
    <MEDIA id="VDO_ID_VS_MM_AVI_PLAY">CUST_IMG_PATH"\\\\MainLCD\\\\SDK_TEST\\\\video.avi"</MEDIA>
    <MEDIA id="VDO_ID_VS_MM_3GP_PLAY">CUST_IMG_PATH"\\\\MainLCD\\\\SDK_TEST\\\\video.3gp"</MEDIA>
    <MEDIA id="VDO_ID_VS_MM_MP4_PLAY">CUST_IMG_PATH"\\\\MainLCD\\\\SDK_TEST\\\\video.mp4"</MEDIA>


</APP>

#endif