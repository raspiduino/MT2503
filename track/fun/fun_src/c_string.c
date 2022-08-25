/* ============================================================================
* C string implementation
*
* 仿照STL中string的实现
*
* 作者：skybuf  <MSN:skybuf@gmail.com>
*
* 开源代码，共享与交流之用，无版权
*


	090512change: 1. 在比较、替换、追加、复制、查找运算中增加了C字符串结尾操作
			2. 修复和erase的BUG：只调整了长度，对于在指定位置擦除非剩余字符数的操作时是个问题
*
* ========================================================================= */
#if !defined (__REMOVE_LOG_TO_FILE__)

#include "c_string.h"
#include <string.h>
#include <stdlib.h>
#include "kal_release.h"
#include "kal_trace.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "app_buff_alloc.h"     /* Declaration of buffer management API */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */
#include "c_RamBuffer.h"

#define DEFAULT_CAPACITY_SIZE_ADD		64
#define DEFAULT_CAPACITY_LIMIT			1024
#define DEFAULT_CAPACITY_NEW_MUL		1.5
#define DEFAULT_CAPACITY_RELEASE_LIMIT	2048

/**
* string的实现结构体
*/
typedef struct
{
    c_string base;					/*接口集*/
    unsigned int length;			/*字符串的当前长度*/
    unsigned int capacity;			/*当前的空间大小*/
    char* content;					/*动态字符串的内容*/
} c_string_impl_t;


static int append(struct _c_string* obj, const char* str, unsigned int pos_start, int num);
static int append_string(struct _c_string* obj, const struct _c_string* string);
static int compare(struct _c_string* obj, const char* str, unsigned int pos_start, int num, unsigned char b_uplower);
static int compare_string(struct _c_string* obj, const struct _c_string* string, unsigned char b_uplower);
static int copy(struct _c_string* obj, const char* str, unsigned int pos_start, int num);
static int copy_string(struct _c_string* obj, const struct _c_string* string);
static int erase(struct _c_string* obj, unsigned int pos_start, int num);
static int replace(struct _c_string* obj, unsigned int pos_start, int num, const char* str);
static int replace_str(struct _c_string* obj, const char* str_src, const char* str_dst);
static int insert(struct _c_string* obj, unsigned int pos_start_obj, const char* str, unsigned int pos_start_str, int num_str);
static int insert_string(struct _c_string* obj, unsigned int pos_start_obj, const struct _c_string* string);
static int insert_ch(struct _c_string* obj, unsigned int pos_start_obj, char ch, unsigned int num_ch);
static int find_first_of(struct _c_string* obj, const char* str, unsigned int pos_start, int num);
static int find_first_string_of(struct _c_string* obj, struct _c_string* string);
static int find_first_ch_of(struct _c_string* obj, char ch);
static int r_find_first_of(struct _c_string* obj, const char* str, unsigned int pos_start, int num);
static int r_find_first_string_of(struct _c_string* obj, struct _c_string* string);
static int r_find_first_ch_of(struct _c_string* obj, char ch);
static char at(struct _c_string* obj, unsigned int index);
static const char* str(struct _c_string* obj);
static void clear(struct _c_string* obj);
static unsigned char empty(struct _c_string* obj);
static int length(struct _c_string* obj);
static struct _c_string* substr(struct _c_string* obj, unsigned int pos_start, int num);
static void swap(struct _c_string* obj, struct _c_string* string);
static void to_upper(struct _c_string* obj);
static void to_lower(struct _c_string* obj);

/**
* 生成新的容量大小
*
* @param impl			c_string_impl_t实例指针
* @param capacity_new	新的容量大小
*
* @return				STRING_ALL_OK表示成功，其余表示失败
*
* @note					调整策略： 如果capacity_new不小于目前的capacity，
						则最终的容量大小为capacity_new的DEFAULT_CAPACITY_NEW_MUL倍。

						但若DEFAULT_CAPACITY_NEW_MUL倍之后，大小超越了DEFAULT_CAPACITY_LIMIT，
						则最终的容量为capacity_new+DEFAULT_CAPACITY_SIZE_ADD
*
*/
static int l_make_new_capacity(c_string_impl_t* impl, unsigned int capacity_new)
{
    int cap = (int)(capacity_new * DEFAULT_CAPACITY_NEW_MUL);	/*新容量为需要的容量的DEFAULT_CAPACITY_NEW_MUL倍*/
    /*
    	kal_prompt_trace(TRACE_INFO,"&&&    l_make_new_capacity( %d )"  ,  capacity_new  );
    	kal_prompt_trace(TRACE_INFO,"impl->capacity = %d", impl->capacity   );
    	kal_prompt_trace(TRACE_INFO,"cap = %d", cap   );
    */
    if(capacity_new < impl->capacity)
        return STRING_ALL_OK;

    /*调整新的容量*/
    if(cap > DEFAULT_CAPACITY_LIMIT)  /*扩展成DEFAULT_CAPACITY_NEW_MUL倍后大于DEFAULT_CAPACITY_LIMIT，则多增加DEFAULT_CAPACITY_SIZE_ADD字节*/
        cap = capacity_new + DEFAULT_CAPACITY_SIZE_ADD;

    {
        /*根据容量生成字符串*/
        char* data = (char*)Ram_Alloc(0, cap);


        if(!data)
            return STRING_ERR_NO_MEMORY;
        /*memset(data, 0, cap);  */ /*无需set，由length控制即可*/

        if(impl->length)
        {
            /*拷贝原有内容*/
            //strcpy(data, impl->content);
            memcpy(data, impl->content, impl->length);
        }

        /* 只有在内容指针非空的时候才释放*/
        if(impl->content)
        {
            Ram_Free(impl->content);
        }

        /*指定*/
        impl->content = data;
        impl->capacity = cap;
    }

    return STRING_ALL_OK;
}

static const char* l_find_sub_str(const char* src, const char* sub_str, unsigned int pos_start, int num)
{
    unsigned int len = strlen(sub_str), len_src = strlen(src);
    const char* p_s_b = src;
    const char* p_d_b = NULL;
    int i = 0, j;

    /*调整num*/
    if(pos_start + num > len || -1 == num)
        num = len - pos_start;

    /*比较*/
    p_d_b = sub_str + pos_start;
    for(; i <= (int)len_src - num; i++)
    {
        for(j = 0; j < num; j++)
        {
            if(*(p_s_b + j) != *(p_d_b++))
                break;
        }

        if(j == num)
            return p_s_b;

        p_s_b++;
        p_d_b = sub_str + pos_start;
    }

    return NULL;
}

static const char* l_r_find_sub_str(const char* src, const char* sub_str, unsigned int pos_start, int num)
{
    unsigned int len = strlen(sub_str), len_src = strlen(src);
    const char* p_s_b = NULL;
    const char* p_d_b = NULL;
    int i = 0, j;

    /*调整num*/
    if(pos_start + num > len || -1 == num)
        num = len - pos_start;

    /*比较*/
    p_s_b = src + len_src - num;
    p_d_b = sub_str + pos_start;
    for(; i <= (int)len_src - num; i++)
    {
        for(j = 0; j < num; j++)
        {
            if(*(p_s_b + j) != *(p_d_b++))
                break;
        }

        if(j == num)
            return p_s_b;

        p_s_b--;
        p_d_b = sub_str + pos_start;
    }

    return NULL;
}

/**
* 将str中pos_start位置开始的num个字符追加到obj的尾部。
*
* @param obj			c_string实例指针
* @param str			待追加的字符串
* @param pos_start		基于0的str中的起始位置，须小于str的长度
* @param num			从str中pos_start位置起的字符数，-1表示剩余的全部
*
* @return				STRING_ALL_OK表示成功，其余表示失败
*
* @note					若pos_start+num大于str的长度，则num等同于-1，将追加剩余的字符串到obj中
*
*/
static int append(struct _c_string* obj, const char* str, unsigned int pos_start, int num)
{
    c_string_impl_t* impl = (c_string_impl_t*)obj;
    int len_str = 0, ret = STRING_ALL_OK;

    /*参数检查*/
    if(!impl)
        return STRING_ERR_INVALID_INSTANCE;

    if(!str || num < -1)
        return STRING_ERR_PARAM;

    if(!num)
        return STRING_ALL_OK;

    len_str = strlen(str);
    /*特殊情况，特殊处理*/
    if(!len_str)
        return STRING_ALL_OK;

    if(pos_start >= (unsigned int)len_str)
        return STRING_ERR_PARAM;

    /*调整num*/
    if(num > len_str - (int)pos_start || -1 == num)
        num = len_str - (int)pos_start;

    /*调整capacity*/
    if(STRING_ALL_OK != (ret = l_make_new_capacity(impl, num + impl->length)))
        return ret;

    /*追加*/
    memcpy(impl->content + impl->length, str + pos_start, num);
    impl->length += num;
//	impl->content[impl->length] = 0;
    return STRING_ALL_OK;
}

/**
* 将string追加到obj的尾部。
*
* @param obj			c_string实例指针
* @param string			待追加的c_string
*
* @return				STRING_ALL_OK表示成功，其余表示失败
*/
int append_string(struct _c_string* obj, const struct _c_string* string)
{
    c_string_impl_t* impl = (c_string_impl_t*)string;
    if(!impl)
        return STRING_ERR_INVALID_INSTANCE;

    impl->content[impl->length] = 0;
    return append(obj, impl->content, 0, -1);
}

/**
* 将str中pos_start位置开始的num个字符与obj的内容比较。
*
* @param obj			c_string实例指针
* @param str			待比较的字符串
* @param pos_start		基于0的str中的起始位置，须小于str的长度
* @param num			从str中pos_start位置起的字符数，-1表示剩余的全部
* @param b_uplower		是否区分大小写。1表示区分，0表示不区分
*
* @return				0表示相同，1表示obj>指定的字符串，-1表示obj<指定的字符串，其余表示失败。
*
* @note					若pos_start+num大于str的长度，则num等同于-1，将比较剩余的字符串
						若不区分大小写时，会将所有字符转成小写形式比较
*
*/
static int compare(struct _c_string* obj, const char* str, unsigned int pos_start, int num, unsigned char b_uplower)
{
    int len_str = 0;
    c_string_impl_t* impl = (c_string_impl_t*)obj;

    /*参数检查*/
    if(!impl)
        return STRING_ERR_INVALID_INSTANCE;

    if(!str || pos_start && pos_start >= (unsigned int)len_str || num < -1)
        return STRING_ERR_PARAM;

    if(!num)
        return 1;

    len_str = strlen(str);
    if(!len_str && !impl->length)
        return 0;

    /* added by skybuf at 090512 */
    impl->content[impl->length] = 0;

    /*根据num的大小进行比较*/
    if(num > len_str - (int)pos_start || -1 == num)
    {
        num = len_str - (int)pos_start;
        if(1 == b_uplower)
        {
            //impl->content[impl->length] = 0;     /* deleted by skybuf at 090512 */
            return strcmp(impl->content, str + pos_start);	/*大于长度，且区分大小写时，直接用strcmp*/
        }
    }

    /*逐字符比较*/
    {
        const char* s_c_p = impl->content;
        const char* d_c_p = str + pos_start;
        int num_d = 0;
        char s_c, d_c;

        while(*s_c_p && *d_c_p && num_d < num)
        {
            s_c = *(s_c_p++);
            d_c = *(d_c_p++);
            if(0 == b_uplower)
            {
                /*不区分大小写*/
                if(s_c >= 65 && s_c <= 90)
                    s_c += 32; /*转成小写*/
                if(d_c >= 65 && d_c <= 90)
                    d_c += 32; /*转成小写*/
            }

            if(s_c > d_c)
                return 1;

            if(s_c < d_c)
                return -1;

            num_d++;
        }

        if(num_d == num)
        {
            if(*s_c_p)
                return 1;
            else if(*d_c_p)
                return -1;

            return 0;
        }

        if(*s_c_p)
            return 1;

        if(*d_c_p)
            return -1;
    }

    return 0;
}

/**
* 将string与obj比较。
*
* @param obj			c_string实例指针
* @param string			待比较的c_string
* @param b_uplower		是否区分大小写。1表示区分，0表示不区分
*
* @return				0表示相同，1表示obj>指定的字符串，-1表示obj<指定的字符串，其余表示失败。
*
* @note					若不区分大小写时，会将所有字符转成小写形式比较
*
*/
static int compare_string(struct _c_string* obj, const struct _c_string* string, unsigned char b_uplower)
{
    const c_string_impl_t* str_impl = (const c_string_impl_t*)string;
    c_string_impl_t* impl = (c_string_impl_t*)obj;
    if(!str_impl)
        return STRING_ERR_INVALID_INSTANCE;

    if(impl && !impl->length && !str_impl->length)   /*content都为空时，直接处理掉*/
        return 0;

    str_impl->content[str_impl->length] = 0; // added by skybuf at 090512
    return compare(obj, str_impl->content, 0, -1, b_uplower);
}

/**
* 将str中pos_start位置开始的num个字符拷贝到obj中，obj的原有内容将被替换。
*
* @param obj			c_string实例指针
* @param str			待拷贝的字符串
* @param pos_start		基于0的str中的起始位置，须小于str的长度
* @param num			从str中pos_start位置起的字符数，-1表示剩余的全部
*
* @return				STRING_ALL_OK表示成功，其余表示失败
*
* @note					若pos_start+num大于str的长度，则num等同于-1，将拷贝剩余的字符串
*
*/
static int copy(struct _c_string* obj, const char* str, unsigned int pos_start, int num)
{
    int len_str = 0, ret = STRING_ALL_OK;
    c_string_impl_t* impl = (c_string_impl_t*)obj;

    /*参数检查*/
    if(!impl)
        return STRING_ERR_INVALID_INSTANCE;

    if(!str || num < -1)
        return STRING_ERR_PARAM;

    if(!num)
        return STRING_ALL_OK;

    len_str = strlen(str);
    /*特殊情况，特殊处理*/
    if(!len_str)
    {
        if(impl->length)
        {
            /*strcpy(impl->content, str);*/ /*无需清空，由length控制即可*/
            impl->length = 0;
        }
        return STRING_ALL_OK;
    }

    if(pos_start >= (unsigned int)len_str)
        return STRING_ERR_PARAM;

    /*调整num*/
    if(num > len_str - (int)pos_start || -1 == num)
        num = len_str - (int)pos_start;

    /*调整capacity*/
    if(STRING_ALL_OK != (ret = l_make_new_capacity(impl, num)))
        return ret;

    /*拷贝*/
    memcpy(impl->content, str + pos_start, num);
    impl->length = num;
//	impl->content[impl->length]=0;
    return STRING_ALL_OK;
}

/**
* 将string拷贝到obj中，obj的原有内容将被替换。
*
* @param obj			c_string实例指针
* @param string			待追加的c_string
*
* @return				STRING_ALL_OK表示成功，其余表示失败
*/
static int copy_string(struct _c_string* obj, const struct _c_string* string)
{
    const c_string_impl_t* str_impl = (const c_string_impl_t*)string;
    c_string_impl_t* impl = (c_string_impl_t*)obj;
    if(!str_impl)
        return STRING_ERR_INVALID_INSTANCE;

    if(impl && impl->length && !str_impl->length)
    {
        /*memset(impl->content, 0, impl->length);*/ /*无需set，由length控制即可*/
        impl->length = 0;
        return STRING_ALL_OK;
    }

    str_impl->content[str_impl->length] = 0; // added by skybuf at 090512
    return copy(obj, str_impl->content, 0, -1);
}

/**
* 将obj中从pos_start位置开始的num个字符擦除
*
* @param obj			c_string实例指针
* @param pos_start		基于0的str中的起始位置，须小于str的长度
* @param num			从str中pos_start位置起的字符数，-1表示剩余的全部。
*
* @return				STRING_ALL_OK表示成功，其余表示失败
*
* @note					若pos_start+num大于obj中字符串的长度，则num等同于-1，将擦除剩余的字符串
*
*/
static int erase(struct _c_string* obj, unsigned int pos_start, int num)
{
    c_string_impl_t* impl = (c_string_impl_t*)obj;

    /*参数检查*/
    if(!impl)
        return STRING_ERR_INVALID_INSTANCE;

    if(num < -1 || pos_start && pos_start >= impl->length)
        return STRING_ERR_PARAM;

    if(!num || !impl->length)
        return STRING_ALL_OK;

    if(0 == pos_start && (num >= (int)(impl->length - pos_start) || num == -1))/*相当于clear*/
    {
        clear(obj);
        return STRING_ALL_OK;
    }

    if(num > (int)(impl->length - pos_start))
        impl->length = pos_start + 1; /*擦除末尾的，调整长度即可*/
    else
    {
        char* s_c_p = impl->content + pos_start;
        char* d_c_p = impl->content + pos_start + num;

        while(*d_c_p)
        {
            *(s_c_p++) = *(d_c_p++);
        }

        impl->length -= num; /*调整length*/
    }

    return STRING_ALL_OK;
}

/**
* 将obj中从pos_start位置开始的num个字符替换成str
*
* @param obj			c_string实例指针
* @param pos_start		基于0的obj中字符串的起始位置，须小于obj的长度
* @param num			从obj中字符串中pos_start位置起的字符数，-1表示剩余的全部
* @param str			可替换的字符串
*
* @return				STRING_ALL_OK表示成功，其余表示失败
*
* @note					若pos_start+num大于obj中字符串的长度，则num等同于-1，将替换剩余的字符串
*
*/
static int replace(struct _c_string* obj, unsigned int pos_start, int num, const char* str)
{
    int len_str = 0;
    int ret = STRING_ALL_OK;
    c_string_impl_t* impl = (c_string_impl_t*)obj;

    /*参数检查*/
    if(!impl)
        return STRING_ERR_INVALID_INSTANCE;

    if(!str || num < -1)
        return STRING_ERR_PARAM;

    if(!num)
        return STRING_ALL_OK;

    len_str = strlen(str);
    /*特殊情况，特殊处理*/
    if(!len_str)
    {
        /*替换成空字符串，等同于擦除*/
        return erase(obj, pos_start, num);
    }

    if(pos_start && pos_start >= impl->length)
        return STRING_ERR_PARAM;

    /*调整num*/
    if(num > (int)(impl->length - pos_start) || -1 == num)
        num = impl->length - pos_start;

    /*生成新的容量*/
    if(STRING_ALL_OK != (ret = l_make_new_capacity(impl, impl->length - num + len_str)))
        return ret;

    /*如果替换剩余的全部，则直接拷贝即可，否则搬移*/
    if(num == (int)(impl->length - pos_start))
        strcpy(impl->content + pos_start, str);
    else
    {
        int n_time = len_str - num;/*注意，n_time可能为负值*/
        char* p_start;
        impl->content[impl->length] = 0;  //added by skybuf at 090512

        if(n_time > 0)
        {
            p_start = impl->content + impl->length - 1;
            while(p_start != impl->content + pos_start + num - 1)
            {
                *(p_start + n_time) = *p_start;
                p_start--;
            }
        }
        else
        {
            p_start = impl->content + pos_start + num;
            while(*p_start)
            {
                *(p_start - n_time) = *p_start;
                p_start++;
            }

            *(p_start - n_time) = 0;
        }

        memcpy(impl->content + pos_start, str, len_str);
    }

    impl->length = impl->length - num + len_str;
//	impl->content[impl->length] = 0;
    return STRING_ALL_OK;
}

/**
* 将obj中的str_src字符串替换成str_dst
*
* @param obj			c_string实例指针
* @param str_src		待替换的字符串
* @param str_dst		可替换的字符串
*
* @return				STRING_ALL_OK表示成功，其余表示失败
*/
static int replace_str(struct _c_string* obj, const char* str_src, const char* str_dst)
{
    c_string_impl_t* impl = (c_string_impl_t*)obj;
    char* p_s = NULL;
    const char* p_s_sub = NULL;
    int ret = STRING_ALL_OK;

    /*参数检查*/
    if(!impl)
        return STRING_ERR_INVALID_INSTANCE;

    if(!str_src || !str_dst)
        return STRING_ERR_PARAM;

    if(!strlen(str_src) || !impl->length)
        return STRING_ALL_OK;

    /*查找每一个sub str，替换之*/
    p_s = impl->content;
    p_s_sub = l_find_sub_str(p_s, str_src, 0, -1);
    while(p_s_sub)
    {
        ret = replace(obj, p_s_sub - impl->content, strlen(str_src), str_dst);
        if(STRING_ALL_OK != ret)
            return ret;

        p_s_sub += strlen(str_dst);
        p_s_sub = l_find_sub_str(p_s_sub, str_src, 0, -1); /*替换成功后，需跳过替换后的内容查找*/
    }

    return 0;
}

/**
* 将str中pos_start_str位置开始的num_str个字符插入到obj的pos_start_obj位置
*
* @param obj			c_string实例指针
* @param pos_start_obj	obj中的插入位置，基于0
* @param str			待插入的字符串
* @param pos_start_str	基于0的str中的起始位置，须小于str的长度
* @param num_str		从str中pos_start_str位置起的字符数，-1表示剩余的全部
*
* @return				STRING_ALL_OK表示成功，其余表示失败
*
* @note					若pos_start_str+num_str大于obj中字符串的长度，则num_str等同于-1，将插入剩余的字符串
*
*/
static int insert(struct _c_string* obj, unsigned int pos_start_obj, const char* str, unsigned int pos_start_str, int num_str)
{
    int len_str = 0;
    int ret = STRING_ALL_OK;
    c_string_impl_t* impl = (c_string_impl_t*)obj;
    char* p_e = NULL;

    /*参数检查*/
    if(!impl)
        return STRING_ERR_INVALID_INSTANCE;

    if(!str || pos_start_obj && pos_start_obj >= impl->length || pos_start_str && pos_start_str >= (int)strlen(str) || num_str < -1)
        return STRING_ERR_PARAM;

    if(!num_str)
        return STRING_ALL_OK;

    /*修正num_str*/
    len_str = strlen(str);
    if(-1 == num_str || num_str + (int)pos_start_str > len_str)
        num_str = len_str - pos_start_str;

    /*重新生成capacity*/
    ret = l_make_new_capacity(impl, impl->length + num_str);
    if(STRING_ALL_OK != ret)
        return ret;

    /*移动字符串*/
    p_e = impl->content + impl->length - 1;
    while(p_e != impl->content + pos_start_obj)
    {
        *(p_e + num_str) = *p_e;
        p_e--;
    }
    *(p_e + num_str) = *p_e; /*补上pos_start_obj的*/

    /*拷贝*/
    memcpy(impl->content + pos_start_obj, str, num_str);
    impl->length += num_str;
//	impl->content[impl->length] = 0;
    return 0;
}

/**
* 将string插入到obj的pos_start_obj位置
*
* @param obj			c_string实例指针
* @param pos_start_obj	obj中的插入位置，基于0
* @param string			待插入的c_string
*
* @return				STRING_ALL_OK表示成功，其余表示失败
*/
static int insert_string(struct _c_string* obj, unsigned int pos_start_obj, const struct _c_string* string)
{
    const c_string_impl_t* str_impl = (const c_string_impl_t*)string;
    c_string_impl_t* impl = (c_string_impl_t*)obj;
    if(!str_impl)
        return STRING_ERR_INVALID_INSTANCE;

    if(impl && !str_impl->length)
        return STRING_ALL_OK;

    impl->content[impl->length] = 0;//added by skybuf at 090512
    return insert(obj, pos_start_obj, impl->content, 0, -1);
}

/**
* 将num_ch个ch插入到obj的pos_start_obj位置
*
* @param obj			c_string实例指针
* @param pos_start_obj	obj中的插入位置，基于0
* @param ch				待插入的字符
* @param num_ch			待插入的字符数
*
* @return				STRING_ALL_OK表示成功，其余表示失败
*/
static int insert_ch(struct _c_string* obj, unsigned int pos_start_obj, char ch, unsigned int num_ch)
{
    int ret = STRING_ALL_OK;
    c_string_impl_t* impl = (c_string_impl_t*)obj;
    char* p_e = NULL;

    /*参数检查*/
    if(!impl)
        return STRING_ERR_INVALID_INSTANCE;

    if(pos_start_obj >= impl->length)
        return STRING_ERR_PARAM;

    if(!num_ch)
        return STRING_ALL_OK;

    /*重新生成capacity*/
    ret = l_make_new_capacity(impl, impl->length + num_ch);
    if(STRING_ALL_OK != ret)
        return ret;

    /*移动字符串*/
    p_e = impl->content + impl->length - 1;
    while(p_e != impl->content + pos_start_obj)
    {
        *(p_e + num_ch) = *p_e;
        p_e--;
    }
    *(p_e + num_ch) = *p_e; /*补上pos_start_obj的*/

    impl->length += num_ch;
    /*拷贝*/
    while(num_ch--)
    {
        *(p_e++) = ch;
    }
//	impl->content[impl->length] = 0;
    return 0;
}

/**
* 在obj中顺序查找子字符串的首次出现位置，子字符串由str中pos_start开始的num个字符组成
*
* @param obj			c_string实例指针
* @param str			待查找的字符串
* @param pos_start		基于0的str中的起始位置
* @param num			从pos_start开始的字符数，-1表示剩余的全部
*
* @return				子字符串的起始位置，-1表示没有找到，<-1表示失败
*
* @note					若pos_start+num大于str的长度，则num等同于-1，将查找剩余的字符串
*
*/
static int find_first_of(struct _c_string* obj, const char* str, unsigned int pos_start, int num)
{
    c_string_impl_t* impl = (c_string_impl_t*)obj;
    const char* p_sub_str = NULL;

    if(!obj)
        return STRING_ERR_INVALID_INSTANCE;

    if(!str || num < -1)
        return STRING_ERR_PARAM;

    if(!impl->length || !strlen(str))
        return -1;

    if(pos_start >= strlen(str))  /*检查完是否为空后，再判断是否越界*/
        return STRING_ERR_PARAM;

    impl->content[impl->length] = 0;  //added by skybuf at 090512
    p_sub_str = l_find_sub_str(impl->content, str, pos_start, num);

    return (p_sub_str ? (p_sub_str - impl->content) : -1);
}

/**
* 在obj中顺序查找子字符串string的首次出现位置
*
* @param obj			c_string实例指针
* @param string			待查找的子字符串
*
* @return				子字符串的起始位置，-1表示没有找到，<-1表示失败
*/
static int find_first_string_of(struct _c_string* obj, struct _c_string* string)
{
    const c_string_impl_t* str_impl = (const c_string_impl_t*)string;
    c_string_impl_t* impl = (c_string_impl_t*)obj;
    if(!str_impl)
        return STRING_ERR_INVALID_INSTANCE;

    if(impl && !str_impl->length)
        return -1;

    impl->content[impl->length] = 0;  //added by skybuf at 090512
    return find_first_of(obj, ((c_string_impl_t*)string)->content, 0, -1);
}

/**
* 在obj中顺序查找字符ch首次出现的位置
*
* @param obj			c_string实例指针
* @param ch				待查找的字符
*
* @return				字符的起始位置，-1表示没有找到，<-1表示失败
*/
static int find_first_ch_of(struct _c_string* obj, char ch)
{
    char temp[2];
    temp[0] = ch;
    temp[1] = 0;

    return find_first_of(obj, temp, 0, -1);
}

/* 在obj中逆序查找子字符串的首次出现位置，子字符串由str中pos_start开始的num个字符组成
*
* @param obj			c_string实例指针
* @param str			待查找的字符串
* @param pos_start		基于0的str中的起始位置
* @param num			从pos_start开始的字符数，-1表示剩余的全部
*
* @return				子字符串的逆起始位置，-1表示没有找到，<-1表示失败
*
* @note					若pos_start+num大于str的长度，则num等同于-1，将查找剩余的字符串
*
*/
static int r_find_first_of(struct _c_string* obj, const char* str, unsigned int pos_start, int num)
{
    c_string_impl_t* impl = (c_string_impl_t*)obj;
    const char* p_sub_str = NULL;

    if(!impl)
        return STRING_ERR_INVALID_INSTANCE;

    if(!str || num < -1)
        return STRING_ERR_PARAM;

    if(!impl->length || !strlen(str))
        return -1;

    if(pos_start >= strlen(str))   /*检查完是否为空后，再判断是否越界*/
        return STRING_ERR_PARAM;

    impl->content[impl->length] = 0;  //added by skybuf at 090512
    p_sub_str = l_r_find_sub_str(impl->content, str, pos_start, num);

    return (p_sub_str ? (p_sub_str - impl->content) : -1);
}

/**
* 在obj中逆序查找子字符串string的首次出现位置
*
* @param obj			c_string实例指针
* @param string			待查找的子字符串
*
* @return				子字符串的逆起始位置，-1表示没有找到，<-1表示失败
*/
static int r_find_first_string_of(struct _c_string* obj, struct _c_string* string)
{
    const c_string_impl_t* str_impl = (const c_string_impl_t*)string;
    c_string_impl_t* impl = (c_string_impl_t*)obj;
    if(!str_impl)
        return STRING_ERR_INVALID_INSTANCE;

    if(impl && !str_impl->length)
        return -1;

    impl->content[impl->length] = 0;  //added by skybuf at 090512
    return r_find_first_of(obj, ((c_string_impl_t*)string)->content, 0, -1);
}

/**
* 在obj中逆查找字符ch首次出现的位置
*
* @param obj			c_string实例指针
* @param ch				待查找的字符
*
* @return				字符串逆起始位置，-1表示没有找到，<-1表示失败
*/
static int r_find_first_ch_of(struct _c_string* obj, char ch)
{
    char temp[2];
    temp[0] = ch;
    temp[1] = 0;

    return r_find_first_of(obj, temp, 0, -1);
}

/**
* 得到obj中位于index位置的字符
*
* @param obj			c_string实例指针
* @param index			索引，基于0
*
* @return				字符，返回0表示错误
*
*/
static char at(struct _c_string* obj, unsigned int index)
{
    c_string_impl_t* impl = (c_string_impl_t*)obj;

    if(!impl)
        return 0;

    if(index >= impl->length || !impl->length)
        return 0;

    return impl->content[index];
}
/**
* 得到obj中的字符串
*
* @param obj			c_string实例指针
*
* @return				字符串， NULL表示失败
*/
static const char* str(struct _c_string* obj)
{
    c_string_impl_t* impl = (c_string_impl_t*)obj;

    if(!impl)
        return NULL;

    /*获取之前重设*/
    if(impl->content)
        impl->content[impl->length] = 0;

    return impl->content;
}

/**
* 清空obj中的内容
*
* @param obj			c_string实例指针
*
* @return				无
*/
static void clear(struct _c_string* obj)
{
    c_string_impl_t* impl = (c_string_impl_t*)obj;

    if(impl && impl->length)
    {
        memset(impl->content, 0, impl->length);
        impl->length = 0;
    }
}

/**
* 测试obj是否为空
*
* @param obj			c_string实例指针
*
* @return				1表示为空，0表示有内容，其余表示失败
*/
static unsigned char empty(struct _c_string* obj)
{
    c_string_impl_t* impl = (c_string_impl_t*)obj;
    if(!impl)
        return 1;

    return impl->length ? 0 : 1;
}

/**
* 得到obj中字符串的长度
*
* @param obj			c_string实例指针
*
* @return				长度， <0表示失败
*/
static int length(struct _c_string* obj)
{
    c_string_impl_t* impl = (c_string_impl_t*)obj;


    if(!impl)
        return STRING_ERR_INVALID_INSTANCE;

    return impl->length;

}

/**
* 得到obj中从pos_start开始的num个字符组成的子字符串
*
* @param obj			c_string实例指针
* @param pos_start		基于0的obj中子字符串的起始位置
* @param num			从pos_start开始的字符数，-1表示剩余的全部
*
* @return				c_string实例指针，由子字符串构成.NULL表示失败
*
* @note					返回的实例指针必须用c_string_release回收。
*
*						若pos_start+num大于obj的长度，则num等同于-1，将得到剩余的子字符串
*
*/
static struct _c_string* substr(struct _c_string* obj, unsigned int pos_start, int num)
{
    c_string_impl_t* impl = (c_string_impl_t*)obj;
    if(!impl)
        return NULL;

    if(pos_start && pos_start >= impl->length)
        return NULL;

    return c_string_create(impl->content, pos_start, num);
}

/**
* 将obj与string中的内容交换
*
* @param obj			c_string实例指针
* @param string 		c_string实例指针
*
* @return				无
*/
static void swap(struct _c_string* obj, struct _c_string* string)
{
    c_string_impl_t temp;
    c_string_impl_t* impl_obj = (c_string_impl_t*)obj;
    c_string_impl_t* impl_string = (c_string_impl_t*)string;

    if(!impl_obj || !impl_string)
        return;

    memcpy(&temp,		impl_obj,		sizeof(c_string_impl_t));
    memcpy(impl_obj,	impl_string,	sizeof(c_string_impl_t));
    memcpy(impl_string,	&temp,			sizeof(c_string_impl_t));
}

/**
* 将obj中的字符串转换成大写
*
* @param obj			c_string实例指针
*
* @return				无
*/
static void to_upper(struct _c_string* obj)
{
    unsigned int i = 0;
    c_string_impl_t* impl = (c_string_impl_t*)obj;
    if(!impl)
        return;

    for(; i < impl->length; i++)
    {
        if(impl->content[i] >= 97 && impl->content[i] <= 122)
            impl->content[i] -= 32;
    }
}
/**
* 将obj中的字符串转换成小写
*
* @param obj			c_string实例指针
*
* @return				无
*/
static void to_lower(struct _c_string* obj)
{
    unsigned int i = 0;
    c_string_impl_t* impl = (c_string_impl_t*)obj;
    if(impl)
    {
        for(; i < impl->length; i++)
        {
            if(impl->content[i] >= 65 && impl->content[i] <= 90)
                impl->content[i] += 32;
        }
    }
}

/**
* string对象链
*/
typedef struct _list_objs
{
    c_string_impl_t* data;			/*string对象*/
    unsigned char b_valid;			/*此对象是否还在使用*/
    struct _list_objs* next;		/*下一对象*/
} c_string_list_objs;

/**
* string对象链管理者
*/
typedef struct
{
    c_string_list_objs* start;		/*对象链的头结点*/
    c_string_list_objs* end;		/*对象链的尾结点*/
    unsigned int num;				/*对象的数目*/
} c_string_list_objs_mgr;

static c_string_list_objs_mgr* l_mgr;
/**
* c_string对象管理者初始化函数
*

* @note					通常，每个string都是比较短的字符串，如果每个string都是从堆上分配新的内存，
						则，效率低下，且还可能生成内存碎片。

						引入c_string对象管理者是为了将那些不用的c_string对象暂存下来，等下次需要
						生成c_string时，优先使用先前不用的c_string对象，这样就避免了上述的问题。


						在初次调用c_string_create时，请务必调用此函数！！否则会创建失败。
*/
int c_string_mgr_init(void)
{
    if(l_mgr)
        return STRING_ALL_OK;

    l_mgr = (c_string_list_objs_mgr*)Ram_Alloc(0, sizeof(c_string_list_objs_mgr));
    if(!l_mgr)
        return STRING_ERR_NO_MEMORY;

    memset(l_mgr, 0, sizeof(c_string_list_objs_mgr));
    return STRING_ALL_OK;
}

/**
* c_string对象管理者回收
*

* @note					通常，每个string都是比较短的字符串，如果每个string都是从堆上分配新的内存，
						则，效率低下，且还可能生成内存碎片。

						引入c_string对象管理者是为了将那些不用的c_string对象暂存下来，等下次需要
						生成c_string时，优先使用先前不用的c_string对象，这样就避免了上述的问题。


						在程序退出时，请务必调用此函数！！否则会内存泄露。
*/
void c_string_mgr_release(void)
{
    if(l_mgr)
    {
        c_string_list_objs* temp = NULL;
        while(l_mgr->start)						/*release每个c_string对象*/
        {

            /*NOTE： 此处可以定位出哪些obj正在被使用中，可收集之，或给警告*/

            Ram_Free(l_mgr->start->data->content);
            l_mgr->start->data->content = NULL;
            Ram_Free(l_mgr->start->data);
            l_mgr->start->data = NULL;
            temp = l_mgr->start;
            l_mgr->start = l_mgr->start->next;
            Ram_Free(temp);
            temp = NULL;
        }

        Ram_Free(l_mgr);
        l_mgr = NULL;
    }
}


/**
* c_string实例指针创建接口，将str中从pos_start位置开始的num个字符作为实例的值
*
* @param str			将作为c_string实例的值的字符串。
* @param pos_start		str中的起始位置，基于0
* @param num			从pos_start位置开始的字符数，-1表示剩余的全部
*
* @return				c_string实例指针, NULL表示失败
*
* @note					str可以为NULL，此时c_string实例的值为空字符串。
						pos_start和num只有在str不为空时才有效。

						若pos_start+num大于str的长度，则num等同于-1
*/
c_string* c_string_create(const char* str_src, unsigned int pos_start, int num)
{
    c_string_impl_t* obj = NULL;
    c_string_list_objs* temp = NULL;
    if(!l_mgr)
        return NULL;

    if(str_src && (pos_start && pos_start >= strlen(str_src) || num < -1))
        return NULL;
//      kal_prompt_trace(TRACE_INFO,"@@@   c_string_create()   1  "    );

    /*优先从list中找*/
    temp = l_mgr->start;
    while(temp)
    {
        if(!temp->b_valid)
        {
            /*无效，则表示此对象已经无人使用，可以做为新的*/
//      kal_prompt_trace(TRACE_INFO,"@@@   c_string_create()   2  "    );

            temp->b_valid = 1; /*置为有效*/

            /*设定内容*/
            if(str_src)
                copy((c_string*)temp->data, str_src, pos_start, num);

            return (c_string*)temp->data;
        }

        temp = temp->next;
    }

    /*list中没有满足条件的，生成*/
    obj = (c_string_impl_t*)Ram_Alloc(0, sizeof(c_string_impl_t));
    if(!obj)
        return NULL;
    /*生成节点*/
    temp = (c_string_list_objs*)Ram_Alloc(0, sizeof(c_string_list_objs));
    if(!temp)
    {
        Ram_Free(obj);
        obj = NULL;
        return NULL;
    }
    memset(obj,		0, sizeof(c_string_impl_t));

    /*设定内容*/
    if(str_src)
        copy((c_string*)obj, str_src, pos_start, num);

    /*设置接口*/
    obj->base.append					= append;
    obj->base.append_string				= append_string;
    obj->base.at						= at;
    obj->base.clear						= clear;
    obj->base.compare					= compare;
    obj->base.compare_string			= compare_string;
    obj->base.copy						= copy;
    obj->base.copy_string				= copy_string;
    obj->base.empty						= empty;
    obj->base.erase						= erase;
    obj->base.find_first_ch_of			= find_first_ch_of;
    obj->base.find_first_of				= find_first_of;
    obj->base.find_first_string_of		= find_first_string_of;
    obj->base.insert					= insert;
    obj->base.insert_ch					= insert_ch;
    obj->base.insert_string				= insert_string;
    obj->base.r_find_first_ch_of		= r_find_first_ch_of;
    obj->base.r_find_first_of			= r_find_first_of;
    obj->base.r_find_first_string_of	= r_find_first_string_of;
    obj->base.replace					= replace;
    obj->base.replace_str				= replace_str;
    obj->base.str						= str;
    obj->base.substr					= substr;
    obj->base.swap						= swap;
    obj->base.length					= length;
    obj->base.to_lower					= to_lower;
    obj->base.to_upper					= to_upper;


    /*配置节点*/
    temp->b_valid	= 1;
    temp->data		= obj;
    temp->next		= NULL;

    /*加入链表*/
    l_mgr->num++;
    if(!l_mgr->start)
        l_mgr->start = l_mgr->end = temp;
    else
    {
        l_mgr->end->next	= temp;
        l_mgr->end			= temp;
    }

    return (c_string*)obj;
}

/**
* c_string实例回收接口
*
* @param obj			c_string实例指针，由c_string_create或者substr返回
*
* @return				无
*/
void c_string_release(c_string* obj)
{
    c_string_list_objs* temp = NULL;
    c_string_impl_t* impl = (c_string_impl_t*)obj;

//   kal_prompt_trace(TRACE_INFO,"@@@   c_string_release()   1  "    );

    if(impl)
    {
        /*查找此obj是否已有对应节点*/
//        kal_prompt_trace(TRACE_INFO,"@@@   c_string_release()   2  "    );

        temp = l_mgr->start;
        while(temp)
        {
//            kal_prompt_trace(TRACE_INFO,"@@@   c_string_release()   3  "    );

            if(temp->data == impl)
            {
                /*在节点中*/
//            kal_prompt_trace(TRACE_INFO,"@@@   c_string_release()   4  "    );

                /*清空原来的内容*/
                if(temp->data->length)
                {
//                                kal_prompt_trace(TRACE_INFO,"@@@   c_string_release()   5  "    );
                    memset(temp->data->content, 0, temp->data->length);
                    temp->data->length = 0;
                }

                /*置为无效*/
                temp->b_valid = 0;
                return;
            }

            temp = temp->next;
        }
//		            kal_prompt_trace(TRACE_INFO,"@@@   c_string_release()   6  "    );

        /*不在节点中，深度怀疑非正常使用，但还是处理了比较好*/
        Ram_Free(impl->content);
        impl->content = NULL;
        Ram_Free(impl);
        impl = NULL;
    }
}

#endif /*__REMOVE_LOG_TO_FILE__*/

