#include "MMI_features.h"
#include "kmx_input_config.h"

#ifdef  __MMI_CSTAR__

#include "gui_data_types.h"
#include "imc_symbol.h"
#include "imc.h"
#include "word_engine.h"
#include "csk2api.h"
#include "cstar_ime.h"
#include "Multitap_engine.h"
#include "kmx_input_prot.h"

static int current_input_mode = 0;
extern UI_character_type *mmi_ime_multitap_mtk_get_abc_upper_string(S32 i);

extern MMI_BOOL mmi_ime_word_change_mode(const sIMEModeDetails * mode_details_ptr, U32 reserved )
{
    current_input_mode = mode_details_ptr->imm_mode_id;
    return MMI_TRUE;
}
extern MMI_BOOL  mmi_ime_word_is_symbol_key( mmi_imm_input_mode_enum input_mode, mmi_imc_key_custom_value key_code )
{
    return MMI_TRUE;
}
extern void     mmi_ime_word_get_candidates( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    //void
    result_ptr->result_cnt = 0;
}
extern MMI_BOOL mmi_ime_word_is_wildcard(UI_character_type code)
{
    if (code == 0xF000)
    	return MMI_TRUE;
    return MMI_FALSE;
}
#define KMX_MAX_ASSOCIATION_QUERY_BUFFER 32
extern void     mmi_ime_word_get_associates( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    unsigned short buffer[KMX_MAX_ASSOCIATION_QUERY_BUFFER];
    CS_RESULT ret_val;
    S32 i, j, cnt;
    int is_pinyin = 1;
    int cur_mode;
    int asso_num = KMX_MAX_ASSOCIATION_QUERY_BUFFER;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT( NULL != param_ptr );
    
    if (param_ptr->pre_string[0] == 0)
    {
        return;
    }
    
    cur_mode = mmi_ime_sdk_get_current_input_mode();
    
    if (kmx_is_zhuyin_ime(cur_mode))
    {
        is_pinyin = 0;
    }
    else if (kmx_is_pinyin_ime(cur_mode))
    {
        is_pinyin = 1;
    }
    else
        return;


    i = 0;
    while((unsigned short)param_ptr->pre_string[i] != 0)
    {
        i++;
    }

    ret_val = HanziAsso_QueryAsso(is_pinyin, (unsigned short) param_ptr->pre_string[i - 1], buffer, &asso_num);
    
    if (ret_val == CS_ERROR_UNKNOWN)
    {
        return;
    }

    i = param_ptr->first_index;
    j = 0;
    cnt = 0;
    
    while(i < asso_num - 1 && cnt < param_ptr->desired_cnt)
    {
        if (buffer[i] == 0 )
        {
            break;
        }
        
        result_ptr->result_buffer[j++] = (UI_character_type)buffer[i++];
        result_ptr->result_buffer[j++] = 0;
        cnt++;
    }

    result_ptr->result_cnt = cnt;
    
    if (cnt == param_ptr->desired_cnt)
    {
        if (i < asso_num - 1)
        {
            if(buffer[i] != 0)
            {
                result_ptr->next_page = MMI_TRUE;
            }
            else
            {
                result_ptr->next_page = MMI_FALSE;
            }
        }
        else
        {
            result_ptr->next_page = MMI_FALSE;
        }
    }
    else
    {
        result_ptr->next_page = MMI_FALSE;
    }
}
extern MMI_BOOL  mmi_ime_word_is_redicals(UI_character_type key_code )
{
    return MMI_FALSE;
}
extern U16                mmi_ime_word_code_to_symbol(UI_character_type code)
{
    return 0xFF;
}

#define U16 unsigned short
int CstarQueryCharInfo(U16 ch, U16* buffer, int buffer_length, int mode);
MMI_BOOL mmi_ime_word_engine_get_char_info(UI_character_type ch, UI_string_type buffer, S32 buffer_length, mmi_imm_input_mode_enum mode)
{
    return (MMI_BOOL)CstarQueryCharInfo(ch, buffer, buffer_length, mode);
}

extern MMI_BOOL mmi_ime_word_init( void )
{
    return MMI_TRUE;
}
void mmi_ime_word_leave_current_mode(void)
{
    //void
}
void mmi_ime_word_deinit(void)
{
    //void
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ime_word_symbol_to_code
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
UI_character_type mmi_ime_word_symbol_to_code(U16 symbol)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (MMI_IMC_IS_SYMB_TONE(symbol))
    {
        switch (symbol)
        {
            case MMI_IMC_SYMB_TONE_1:
                return 0x02C9;
                
            case MMI_IMC_SYMB_TONE_2:
                return 0x02CA;
            case MMI_IMC_SYMB_TONE_3:
                return 0x02C7;
            case MMI_IMC_SYMB_TONE_4:
                return 0x02CB;
            case MMI_IMC_SYMB_TONE_5:
                return 0x02D9;
            default:
                ASSERT(0);
        }
    }
#if defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__)
    else if (MMI_IMC_IS_SYMB_STROKE(symbol))
    {
        switch(symbol)
        {
        case MMI_IMC_SYMB_STROKE_WILDCARD:
            return 0xF000;            
            
        case MMI_IMC_SYMB_STROKE_DOWN:
            return 0xF001;            
            
        case MMI_IMC_SYMB_STROKE_DOT:
            return 0xF002;            
            
        case MMI_IMC_SYMB_STROKE_OVER:
            return 0xF004;            
            
        case MMI_IMC_SYMB_STROKE_OVER_DOWN:
            return 0xF005;            
            
        case MMI_IMC_SYMB_STROKE_LEFT:
            return 0xF007;
            
        default:
            return 0;            
        }
    }
#endif /* defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__) */
#if defined(__MMI_LANG_SM_CHINESE__)
    else if (MMI_IMC_IS_SYMB_PY(symbol))
    {
        return symbol - MMI_IMC_SYMB_PY_BASE + 'a';
    }
#endif /* #if defined(__MMI_LANG_SM_CHINESE__) */
#if defined(__MMI_LANG_TR_CHINESE__)
    else if (MMI_IMC_IS_SYMB_ZY(symbol))
    {
        return symbol - MMI_IMC_SYMB_ZY_BASE + 0x3105;
    }
#endif /* #if defined(__MMI_LANG_TR_CHINESE__) */

    return 0;
}

#if defined(__MMI_CSTAR_SM_CHINESE__) || defined(__MMI_CSTAR_TR_CHINESE__)

static const mmi_imc_symb_stroke_enum g_cstar_keys_stroke[MMI_IMC_SYMB_KEY_MAX - MMI_IMC_SYMB_KEY_BASE] =
{
    (mmi_imc_symb_stroke_enum)0,                         /* MMI_IMC_SYMB_KEY_0 */
    MMI_IMC_SYMB_STROKE_OVER,  /* MMI_IMC_SYMB_KEY_1 */
    MMI_IMC_SYMB_STROKE_DOWN,  /* MMI_IMC_SYMB_KEY_2 */
    MMI_IMC_SYMB_STROKE_LEFT,  /* MMI_IMC_SYMB_KEY_3 */
    MMI_IMC_SYMB_STROKE_DOT,   /* MMI_IMC_SYMB_KEY_4 */
    MMI_IMC_SYMB_STROKE_OVER_DOWN, /* MMI_IMC_SYMB_KEY_5 */
    MMI_IMC_SYMB_STROKE_WILDCARD, /* MMI_IMC_SYMB_KEY_6 */
    (mmi_imc_symb_stroke_enum)0,   /* MMI_IMC_SYMB_KEY_7 */
    (mmi_imc_symb_stroke_enum)0,   /* MMI_IMC_SYMB_KEY_8 */
    (mmi_imc_symb_stroke_enum)0,   /* MMI_IMC_SYMB_KEY_9 */
    (mmi_imc_symb_stroke_enum)0,   /* MMI_IMC_SYMB_KEY_STAR */
    (mmi_imc_symb_stroke_enum)0    /* MMI_IMC_SYMB_KEY_POUND */
};

static void   mmi_ime_cstar_get_spellings_stroke( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  i;
    U8  symb;
    UI_string_type temp_str;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ASSERT( NULL != param_ptr );
    if ( 0 == param_ptr->elembuf_cnt )
        return;
    
    temp_str = result_ptr->result_buffer;
    
    for ( i = 0; i < param_ptr->elembuf_cnt; ++i )
    {
        symb = (U8)param_ptr->elembuf_ptr[i];
        if ( MMI_FALSE != MMI_IMC_IS_SYMB_KEY(symb) )
        {
            if (g_cstar_keys_stroke[symb - MMI_IMC_SYMB_KEY_BASE])
            {
                *temp_str = mmi_ime_word_symbol_to_code((U8)g_cstar_keys_stroke[symb - MMI_IMC_SYMB_KEY_BASE]);
                temp_str++;
            }
            else /* Invalid key */
            {
                i = 0;
                temp_str = result_ptr->result_buffer;
                break;
            }
        }
        else
        {
            i = 0;
            temp_str = result_ptr->result_buffer;
            break;
        }       
    }

    *temp_str = 0;

    result_ptr->result_cnt = i;
    
}
#endif

extern void     mmi_ime_word_get_spellings( mmi_ime_query_param_struct_p param_ptr, mmi_ime_query_result_struct_p result_ptr )
{
#if defined(__MMI_CSTAR_SM_CHINESE__) || defined(__MMI_CSTAR_TR_CHINESE__)
    int mode = current_input_mode;
    if(
    #if defined(__MMI_CSTAR_SM_CHINESE__) && defined(__MMI_CSTAR_TR_CHINESE__)
        mode == IMM_INPUT_MODE_SM_STROKE ||
        mode == IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE ||
        mode == IMM_INPUT_MODE_TR_STROKE ||
        mode == IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE
    #elif defined(__MMI_CSTAR_SM_CHINESE__)
        mode == IMM_INPUT_MODE_SM_STROKE ||
        mode == IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE
    #else
        mode == IMM_INPUT_MODE_TR_STROKE ||
        mode == IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE
    #endif
        )
    {
        mmi_ime_cstar_get_spellings_stroke(param_ptr, result_ptr);
    }
#endif
}

#if defined(__MMI_IME_MAGIC_ONE__)
extern MMI_BOOL mmi_ime_word_is_magic_key( mmi_imm_input_mode_enum input_mode, mmi_imc_key_custom_value key_code )
{
    return 0;
}
#endif

#if defined(__MMI_IME_USER_DATABASE__)

extern mmi_ime_word_add_new_word_ret_value_enum mmi_ime_word_add_new_word(mmi_imm_input_mode_enum input_mode, UI_string_type str_ptr)
{
    return 0;
}

extern MMI_BOOL mmi_ime_word_update_word_frequency(mmi_imm_input_mode_enum input_mode, UI_string_type str_ptr)
{
    return 0;
}

extern MMI_BOOL mmi_ime_word_load_user_database(void)
{
    return 1;
}

extern MMI_BOOL mmi_ime_word_save_user_database(void)
{
    return 1;
}

extern void mmi_ime_word_scan_and_add_new_words(UI_string_type str_ptr)
{
}

#endif /* defined(__MMI_IME_USER_DATABASE__) */

extern mmi_imc_symbol_key_enum mmi_ime_word_map_char_to_symbol(mmi_imm_input_mode_enum input_mode, UI_character_type char_code)
{
    return (mmi_imc_symbol_key_enum)0;
}

void mmi_ime_word_add_separator_to_candidate_buffer(UI_character_type * destination_buffer, UI_character_type * source_buffer, S32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (i < num && source_buffer[i] != 0)
    {
        destination_buffer[j] = source_buffer[i];
        destination_buffer[j + 1] = 0; /* Default separator is '\0' */
        i++;
        j += 2;
    }

    destination_buffer[j] = 0;
}


void   mmi_ime_word_change_word_case(mmi_ime_word_capital_state_enum capital_state)
{

}

static MMI_BOOL mmi_ime_multitap_vendor_valid_key_check( mmi_imc_symbol_key_enum sym)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_ime_word_is_symbol_key(mmi_ime_sdk_get_current_input_mode(), sym);
}

valid_key_check_func mmi_ime_multitap_vendor_query_key_check_function( mmi_imm_input_mode_enum input_mode )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    
    return mmi_ime_multitap_vendor_valid_key_check;
}

MMI_BOOL mmi_ime_multitap_vendor_change_mode( const sIMEModeDetails *mode_details_ptr, U32 reserved )
{
	return MMI_TRUE;
}

/* KMX TEMP HANDLE */
static UI_string_type kmx_dummy_vendor_get_string(S32 index)
{
	return mmi_ime_multitap_mtk_get_abc_upper_string(index);
}

get_multitap_string mmi_ime_multitap_vendor_get_string_func( mmi_imm_input_mode_enum input_mode )
{
	return kmx_dummy_vendor_get_string;
}

MMI_BOOL mmi_ime_multitap_vendor_init( void )
{
	return MMI_TRUE;
}

void mmi_ime_multitap_vendor_deinit( void )
{

}
#endif
