
#include "c_vector.h"
#include <stdlib.h>
#include <string.h>

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

#define DEFAULT_CAPACITY_SIZE_ADD		512/*32*/
#define DEFAULT_CAPACITY_LIMIT			512
#define DEFAULT_CAPACITY_NEW_MUL		1.5
#define DEFAULT_CAPACITY_RELEASE_LIMIT	1024

typedef struct
{
    c_vector base;

    unsigned long* content;
    unsigned int length;
    unsigned int capacity;
} c_vector_impl_t;

static int copy_vec(struct _c_vector* obj, const struct _c_vector* vec);
static void* at(struct _c_vector* obj, unsigned int index);
static void* back(struct _c_vector* obj);
static void* front(struct _c_vector* obj);
static void clear(struct _c_vector* obj);
static unsigned char empty(struct _c_vector* obj);
static int erase(struct _c_vector* obj, unsigned int pos_start, int num);
static int insert(struct _c_vector* obj, unsigned int index, void* data);
static int insert_vec(struct _c_vector* obj, unsigned int index, const struct _c_vector* vec);
static int size(struct _c_vector* obj);
static int push_back(struct _c_vector* obj, void* data);
static int swap(struct _c_vector* obj, struct _c_vector* vec);
static int sort(struct _c_vector* obj, fun_sort_t fun_sort);
static int for_each(struct _c_vector* obj, fun_each_t fun_each);


/**
* 生成新的容量大小
*
* @param impl			c_vector_impl_t实例指针
* @param capacity_new	新的容量大小
*
* @return				VECTOR_ALL_OK表示成功，其余表示失败
*
* @note					调整策略： 如果capacity_new不小于目前的capacity，
						则最终的容量大小为capacity_new的DEFAULT_CAPACITY_NEW_MUL倍。

						但若DEFAULT_CAPACITY_NEW_MUL倍之后，大小超越了DEFAULT_CAPACITY_LIMIT，
						则最终的容量为capacity_new+DEFAULT_CAPACITY_SIZE_ADD
*
*/
static int l_make_new_capacity(c_vector_impl_t* impl, unsigned int capacity_new)
{
    int cap = (int)(capacity_new * DEFAULT_CAPACITY_NEW_MUL);	/*新容量为需要的容量的DEFAULT_CAPACITY_NEW_MUL倍*/
    if(capacity_new <= impl->capacity)
        return VECTOR_ALL_OK;

    /*调整新的容量*/
    if(cap > DEFAULT_CAPACITY_LIMIT)  /*扩展成DEFAULT_CAPACITY_NEW_MUL倍后大于DEFAULT_CAPACITY_LIMIT，则多增加DEFAULT_CAPACITY_SIZE_ADD字节*/
        cap = capacity_new + DEFAULT_CAPACITY_SIZE_ADD;

    {
        /*根据容量生成内容*/
        unsigned long* data = (unsigned long*)Ram_Alloc(0, cap * sizeof(unsigned long));
        if(!data)
            return VECTOR_ERR_NO_MEMORY;

        if(impl->length)
        {
            /*拷贝原有内容*/
            memcpy(data, impl->content, sizeof(unsigned long) * impl->length);
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

    return VECTOR_ALL_OK;
}


/**
* 将vec的内容拷贝到obj中，obj的原有内容将被覆盖
*
* @param obj			c_vector实例指针
* @param vec			待拷贝的c_vector实例指针
*
* @return				VECTOR_ALL_OK表示成功，其余表示失败
*
*/
static int copy_vec(struct _c_vector* obj, const struct _c_vector* vec)
{
    int ret = VECTOR_ALL_OK;
    c_vector_impl_t* impl = (c_vector_impl_t*)obj;
    c_vector_impl_t* impl_vec = (c_vector_impl_t*)vec;
    if(!impl || !impl_vec)
        return VECTOR_ERR_INVALID_INSTANCE;

    if(!impl_vec->length)
    {

        impl->length = 0;
        return VECTOR_ALL_OK;
    }

    if(VECTOR_ALL_OK != (ret = l_make_new_capacity(impl, impl_vec->length)))
        return ret;

    memcpy(impl->content, impl_vec->content, sizeof(unsigned long)*impl_vec->length);
    impl->length = impl_vec->length;
    return VECTOR_ALL_OK;
}

/**
* 将obj中位于index处的元素。index基于0
*
* @param obj			c_vector实例指针
* @param index			下标
*
* @return				相应的元素，NULL表示失败
*
*/
static void* at(struct _c_vector* obj, unsigned int index)
{
    c_vector_impl_t* impl = (c_vector_impl_t*)obj;
    if(!impl || index >= impl->length)
        return NULL;

    return (void*)impl->content[index];
}

/**
* 取obj中的最后一个元素
*
* @param obj			c_vector实例指针
*
* @return				相应的元素，NULL表示失败
*
*/
static void* back(struct _c_vector* obj)
{
    c_vector_impl_t* impl = (c_vector_impl_t*)obj;
    if(!impl || !impl->length)
        return NULL;

    return (void*)impl->content[impl->length - 1];
}
/**
* 取obj中的第一个元素
*
* @param obj			c_vector实例指针
*
* @return				相应的元素，NULL表示失败
*
*/
static void* front(struct _c_vector* obj)
{
    c_vector_impl_t* impl = (c_vector_impl_t*)obj;
    if(!impl || !impl->length)
        return NULL;

    return (void*)impl->content[0];
}

/**
* 清空obj
*
* @param obj			c_vector实例指针
*
* @return				无
*
*/
static void clear(struct _c_vector* obj)
{
    c_vector_impl_t* impl = (c_vector_impl_t*)obj;
    if(!impl || !impl->length)
        return;

    impl->length = 0;
    return;
}
/**
* 判断obj是否为空
*
* @param obj			c_vector实例指针
*
* @return				0表示不为空，1表示为空
*
*/
static unsigned char empty(struct _c_vector* obj)
{
    c_vector_impl_t* impl = (c_vector_impl_t*)obj;
    if(!impl)
        return 1;

    return impl->length ? 0 : 1;
}

/**
* 擦除obj中从pos_start开始的num个元素
*
* @param obj			c_vector实例指针
* @param pos_start		obj中的下标，基于0
* @param obj			待擦除的元素的数目，若=-1，则表示擦除从pos_start开始的剩余元素
*
* @return				VECTOR_ALL_OK表示成功，否则为失败
*
* @note					若干num+pos_start>obj的size，则num等同于-1
*
*/
static int erase(struct _c_vector* obj, unsigned int pos_start, int num)
{
    c_vector_impl_t* impl = (c_vector_impl_t*)obj;
    if(!impl)
        return VECTOR_ERR_INVALID_INSTANCE;

    if(pos_start && pos_start >= impl->length || num < -1)
        return VECTOR_ERR_PARAM;

    if(!impl->length || 0 == num)
        return VECTOR_ALL_OK;

    /*调整num*/
    if(pos_start + num > impl->length || -1 == num)
        num = impl->length - pos_start;


    if(pos_start + num < impl->length)
    {
        /*移位*/
        unsigned long* p_s = impl->content + pos_start;
        int num_temp = impl->length - pos_start;
        while(num_temp)
        {
            *p_s = *(p_s + num);
            p_s++;
            num_temp--;
        }
    }
    impl->length -= num;

    return VECTOR_ALL_OK;
}

/**
* 将data插入到obj的index处
*
* @param obj			c_vector实例指针
* @param index			obj中的下标，基于0
* @param data			待插入的元素
*
* @return				VECTOR_ALL_OK表示成功，否则为失败
*
*/
static int insert(struct _c_vector* obj, unsigned int index, void* data)
{
    int ret = VECTOR_ALL_OK;
    unsigned int pos = 0;
    c_vector_impl_t* impl = (c_vector_impl_t*)obj;
    if(!impl)
        return VECTOR_ERR_INVALID_INSTANCE;

    if(!data || index >= impl->length)
        return VECTOR_ERR_PARAM;

    if(VECTOR_ALL_OK != (ret = l_make_new_capacity(impl, impl->length + 1)))
        return ret;

    for(pos = impl->length; pos > index; pos--)
    {
        impl->content[pos] = impl->content[pos - 1];
    }
    impl->content[index] = (unsigned long)data;
    impl->length += 1;
    return VECTOR_ALL_OK;
}

/**
* 将vec插入到obj的index处
*
* @param obj			c_vector实例指针
* @param index			obj中的下标，基于0
* @param vec			待插入的c_vector实例指针
*
* @return				VECTOR_ALL_OK表示成功，否则为失败
*
*/
static int insert_vec(struct _c_vector* obj, unsigned int index, const struct _c_vector* vec)
{
    int ret = VECTOR_ALL_OK;
    unsigned int pos = 0;
    c_vector_impl_t* impl = (c_vector_impl_t*)obj;
    c_vector_impl_t* impl_vec = (c_vector_impl_t*)vec;
    if(!impl || !impl_vec)
        return VECTOR_ERR_INVALID_INSTANCE;

    if(index >= impl->length)
        return VECTOR_ERR_PARAM;

    if(VECTOR_ALL_OK != (ret = l_make_new_capacity(impl, impl->length + impl_vec->length)))
        return ret;

    /*移位*/
    if(impl_vec->length > impl->length - index)
    {
        /*没有交叉，直接用memcpy*/
        memcpy(impl->content + index + impl_vec->length, impl->content + index, sizeof(unsigned long) * (impl->length - index));
    }
    else
    {
        for(pos = impl->length - 1; pos >= index; pos--)
        {
            impl->content[pos + impl_vec->length] = impl->content[pos];
        }
    }

    memcpy(impl->content + index, impl_vec->content, impl_vec->length * sizeof(unsigned long));
    impl->length += impl_vec->length;
    return VECTOR_ALL_OK;
}

/**
* 将data追加到obj中
*
* @param obj			c_vector实例指针
* @param data			带追加的元素
*
* @return				VECTOR_ALL_OK表示成功，否则为失败
*
*/
static int push_back(struct _c_vector* obj, void* data)
{
    int ret = VECTOR_ALL_OK;
    c_vector_impl_t* impl = (c_vector_impl_t*)obj;
    if(!impl)
        return VECTOR_ERR_INVALID_INSTANCE;

    if(!data)
        return VECTOR_ERR_PARAM;

    if(VECTOR_ALL_OK != (ret = l_make_new_capacity(impl, impl->length + 1)))
        return ret;

    impl->content[impl->length] = (unsigned long)data;
    impl->length += 1;
    return VECTOR_ALL_OK;
}

/**
* obj中元素的个数
*
* @param obj			c_vector实例指针
*
* @return				元素的个数，<0表示失败
*
*/
static 	int size(struct _c_vector* obj)
{
    c_vector_impl_t* impl = (c_vector_impl_t*)obj;
    if(!impl)
        return VECTOR_ERR_INVALID_INSTANCE;

    return impl->length;
}

/**
* 将obj和vec的内容交换
*
* @param obj			c_vector实例指针
* @param obj			带交换内容的c_vector实例指针
*
* @return				VECTOR_ALL_OK表示成功，否则为失败
*
*/
static int swap(struct _c_vector* obj, struct _c_vector* vec)
{
    c_vector_impl_t temp;
    c_vector_impl_t* impl = (c_vector_impl_t*)obj;
    c_vector_impl_t* impl_vec = (c_vector_impl_t*)vec;
    if(!impl || !impl_vec)
        return VECTOR_ERR_INVALID_INSTANCE;

    memcpy(&temp,		impl,		sizeof(c_vector_impl_t));
    memcpy(impl,		impl_vec,	sizeof(c_vector_impl_t));
    memcpy(impl_vec,	&temp,		sizeof(c_vector_impl_t));

    return VECTOR_ALL_OK;
}

/**
* 将obj的内容排序
*
* @param obj			c_vector实例指针
* @param fun_sort		指定排序策略的函数的回调指针
*
* @return				VECTOR_ALL_OK表示成功，否则为失败
*
*/
static int sort(struct _c_vector* obj, fun_sort_t fun_sort)
{
    unsigned long temp;
    unsigned int pos, pos_sort, pos_max;
    c_vector_impl_t* impl = (c_vector_impl_t*)obj;
    if(!impl)
        return VECTOR_ERR_INVALID_INSTANCE;

    if(!fun_sort)
        return VECTOR_ERR_PARAM;

    if(impl->length < 2)
        return VECTOR_ALL_OK;

    /*只有两个元素，直接处理*/
    if(impl->length == 2)
    {
        if(-1 == fun_sort((void*)impl->content[0], (void*)impl->content[1]))
        {
            temp = impl->content[0];
            impl->content[0] = impl->content[1];
            impl->content[1] = temp;
        }

        return VECTOR_ALL_OK;
    }

    /*冒泡排序*/
    for(pos = 0; pos < impl->length - 1; pos++)
    {
        pos_max = pos;
        for(pos_sort = pos + 1; pos_sort < impl->length; pos_sort++)
        {
            if(-1 == fun_sort((void*)impl->content[pos_sort], (void*)impl->content[pos_max]))
                pos_max = pos_sort;
        }

        if(pos_max != pos)
        {
            temp					= impl->content[pos];
            impl->content[pos]		= impl->content[pos_max];
            impl->content[pos_max]	= temp;
        }
    }

    return VECTOR_ALL_OK;
}

/**
* 用obj的中的每个元素调用下fun_each
*
* @param obj			c_vector实例指针
* @param fun_each		待调用的函数
*
* @return				VECTOR_ALL_OK表示成功，否则为失败
*
*/
static int for_each(struct _c_vector* obj, fun_each_t fun_each)
{
    unsigned int pos = 0;
    c_vector_impl_t* impl = (c_vector_impl_t*)obj;
    if(!impl)
        return VECTOR_ERR_INVALID_INSTANCE;

    if(!fun_each)
        return VECTOR_ERR_PARAM;

    for(; pos < impl->length; pos++)
        fun_each((void*)impl->content[pos]);

    return VECTOR_ALL_OK;
}

/**
* vector对象链
*/
typedef struct _list_objs
{
    c_vector_impl_t* data;			/*vector对象*/
    unsigned char b_valid;			/*此对象是否还在使用*/
    struct _list_objs* next;		/*下一对象*/
} c_vector_list_objs;

/**
* vector对象链管理者
*/
typedef struct
{
    c_vector_list_objs* start;		/*对象链的头结点*/
    c_vector_list_objs* end;		/*对象链的尾结点*/
    unsigned int num;				/*对象的数目*/
} c_vector_list_objs_mgr;

static c_vector_list_objs_mgr* l_mgr;


/**
* c_vector对象管理者初始化函数
*
* @return				ALL_OK表示成功，其余表示失败
*
* @note					引入c_vector对象管理者是为了将那些不用的c_vector对象暂存下来，等下次需要
						生成c_vector时，优先使用先前不用的c_vector对象，对于频繁使用c_vector对象
						的来说，会提高效率，减少内存碎片。但c_vector对象管理者不是必须的

*/
int c_vector_mgr_init(void)
{
    if(l_mgr)
        return VECTOR_ALL_OK;

    l_mgr = (c_vector_list_objs_mgr*)Ram_Alloc(0, sizeof(c_vector_list_objs_mgr));
    if(!l_mgr)
        return VECTOR_ERR_NO_MEMORY;

    memset(l_mgr, 0, sizeof(c_vector_list_objs_mgr));
    return VECTOR_ALL_OK;
}

/**
* c_vector对象管理者回收
*
*
* @note					引入c_vector对象管理者是为了将那些不用的c_vector对象暂存下来，等下次需要
						生成c_vector时，优先使用先前不用的c_vector对象，对于频繁使用c_vector对象
						的来说，会提高效率，减少内存碎片。但c_vector对象管理者不是必须的


						一旦调用了c_vector_mgr_init()，在程序退出时，请务必调用此函数！！否则会内存泄露。
*/
void c_vector_mgr_release(void)
{
    if(l_mgr)
    {
        c_vector_list_objs* temp = NULL;
        while(l_mgr->start)						/*release每个c_vector对象*/
        {

            /*NOTE： 此处可以定位出哪些obj正在被使用中，可收集之，或给警告*/

            Ram_Free(l_mgr->start->data->content);
            Ram_Free(l_mgr->start->data);
            temp = l_mgr->start;
            l_mgr->start = l_mgr->start->next;
            Ram_Free(temp);
        }

        Ram_Free(l_mgr);
        l_mgr = NULL;
    }
}

/**
* c_vector实例创建接口
*
* @return				c_vector实例指针
*
*/
c_vector* c_vector_create(void)
{
    c_vector_impl_t* obj = NULL;
    c_vector_list_objs* temp = NULL;
    if(l_mgr)   /*是否使用了对象池*/
    {
        /*优先从list中找*/
        temp = l_mgr->start;
        while(temp)
        {
            if(!temp->b_valid)
            {
                /*无效，则表示此对象已经无人使用，可以做为新的*/

                temp->b_valid = 1; /*置为有效*/
                return (c_vector*)temp->data;
            }

            temp = temp->next;
        }
    }

    /*list中没有满足条件的，生成*/
    obj = (c_vector_impl_t*)Ram_Alloc(0, sizeof(c_vector_impl_t));
    if(!obj)
        return NULL;
    if(l_mgr)   /*是否使用了对象池*/
    {
        /*生成节点*/
        temp = (c_vector_list_objs*)Ram_Alloc(0, sizeof(c_vector_list_objs));
        if(!temp)
        {
            Ram_Free(obj);
            return NULL;
        }
    }
    memset(obj,		0, sizeof(c_vector_impl_t));


    /*设置接口*/
    obj->base.at			= at;
    obj->base.back			= back;
    obj->base.clear			= clear;
    obj->base.copy_vec		= copy_vec;
    obj->base.empty			= empty;
    obj->base.erase			= erase;
    obj->base.for_each		= for_each;
    obj->base.front			= front;
    obj->base.insert		= insert;
    obj->base.insert_vec	= insert_vec;
    obj->base.push_back		= push_back;
    obj->base.size			= size;
    obj->base.sort			= sort;
    obj->base.swap			= swap;

    if(l_mgr)   /*是否使用了对象池*/
    {
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
    }

    return (c_vector*)obj;
}

/**
* c_vector实例回收接口
*
* @param obj			c_vector实例指针
*
*/
void c_vector_release(c_vector* obj)
{
    c_vector_impl_t* impl = (c_vector_impl_t*)obj;
    if(impl)
    {
        if(l_mgr)
        {
            /*查找此obj是否已有对应节点*/
            c_vector_list_objs* temp = l_mgr->start;
            while(temp)
            {
                if(temp->data == impl)
                {
                    /*在节点中*/

                    /*如果原来的容量大于指定值，则先释放掉  modified bu skybuf at 08.2.12*/
                    if(temp->data->capacity > DEFAULT_CAPACITY_RELEASE_LIMIT)
                    {
                        Ram_Free(temp->data->content);
                        temp->data->content		= NULL;
                        temp->data->capacity	= 0;
                    }
                    /*end modified*/

                    temp->data->length = 0;

                    /*置为无效*/
                    temp->b_valid = 0;
                    return;
                }

                temp = temp->next;
            }
        }


        Ram_Free(impl->content);
        Ram_Free(impl);
    }
}
