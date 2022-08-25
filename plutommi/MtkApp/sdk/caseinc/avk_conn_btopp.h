#include "mmi_features.h"
#ifdef __MAUI_SDK_TEST__

#define VS_BTOPP_OPTOIN_SIZE 10

typedef enum 
{
    VS_BTOPP_ITEM_PREPARE,
    VS_BTOPP_ITEM_START,
    //VS_BTOPP_ITEM_DO,
    //VS_BTOPP_ITEM_ABT,
    VS_BTOPP_ITEM_FINISH,
    VS_BTOPP_ITEM_TEST_ALL
}vs_BTOPP_menu_item;

extern void vs_btopp_entry_scr(void);

extern void vs_btopp_prepare(void);
extern void vs_btopp_start(void);
//extern void vs_btopp_do(void);
extern void vs_btopp_abt(void);
extern void vs_btopp_finish(void);
extern void vs_btopp_test_all(void);

#endif /* __MAUI_SDK_TEST__ */

