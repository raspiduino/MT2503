
/* ============================================================================
* C vector interface
* 
* 仿照STL中vector的接口，实现C版本的vector。
*
* 作者：skybuf  <MSN:skybuf@gmail.com>
* 
* 开源代码，共享与交流之用，无版权
*
* ========================================================================= */
#ifndef __C_VECTOR_H__
#define __C_VECTOR_H__

#ifdef _cplusplus
extern "C"{
#endif


/*错误值定义*/
#define VECTOR_ALL_OK					0				/*完好，没有错误*/
#define VECTOR_ERR_NO_MEMORY			-100			/*内存不足*/
#define VECTOR_ERR_INVALID_INSTANCE		-101			/*无效的c_vector实例*/
#define VECTOR_ERR_PARAM				-102			/*参数错误*/

/**
* 排序策略指定回调函数类型定义
*
* @param data1			待比较的元素1
* @param data2			待比较的元素2
*
* @return				以vector元素从左往右的顺序看，-1表示data1放在data2的右面， 1表示data1放在data2的左面，0表示相等
*
*/
typedef int (*fun_sort_t)(void* data1, void* data2);

/**
* for_each回调函数类型定义，用于为c_vector中的每个元素调用一遍each函数
*
* @param data			c_vector中的元素
*
* @return				无
*
*/
typedef void (*fun_each_t)(void* data);

/**
* c_vector的接口集。
*/
typedef struct _c_vector
{	
	/**
	* 将vec的内容拷贝到obj中，obj的原有内容将被覆盖
	*
	* @param obj			c_vector实例指针
	* @param vec			待拷贝的c_vector实例指针
	*
	* @return				VECTOR_ALL_OK表示成功，其余表示失败
	*
	*/
	int (*copy_vec)(struct _c_vector* obj, const struct _c_vector* vec);

	/**
	* 将obj中位于index处的元素。index基于0
	*
	* @param obj			c_vector实例指针
	* @param index			下标
	*
	* @return				相应的元素，NULL表示失败
	*
	*/
	void* (*at)(struct _c_vector* obj, unsigned int index);
	/**
	* 取obj中的最后一个元素
	*
	* @param obj			c_vector实例指针
	*
	* @return				相应的元素，NULL表示失败
	*
	*/
	void* (*back)(struct _c_vector* obj);
	/**
	* 取obj中的第一个元素
	*
	* @param obj			c_vector实例指针
	*
	* @return				相应的元素，NULL表示失败
	*
	*/
	void* (*front)(struct _c_vector* obj);

	/**
	* 清空obj
	*
	* @param obj			c_vector实例指针
	*
	* @return				无
	*
	*/
	void (*clear)(struct _c_vector* obj);
	/**
	* 判断obj是否为空
	*
	* @param obj			c_vector实例指针
	*
	* @return				0表示不为空，1表示为空
	*
	*/
	unsigned char (*empty)(struct _c_vector* obj);

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
	int (*erase)(struct _c_vector* obj, unsigned int pos_start, int num);
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
	int (*insert)(struct _c_vector* obj, unsigned int index, void* data);
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
	int (*insert_vec)(struct _c_vector* obj, unsigned int index, const struct _c_vector* vec);

	/**
	* 将data追加到obj中
	*
	* @param obj			c_vector实例指针
	* @param data			带追加的元素
	*
	* @return				VECTOR_ALL_OK表示成功，否则为失败
	*
	*/
	int (*push_back)(struct _c_vector* obj, void* data);

	/**
	* obj中元素的个数
	*
	* @param obj			c_vector实例指针
	*
	* @return				元素的个数，<0表示失败
	*
	*/
	int (*size)(struct _c_vector* obj);

	/**
	* 将obj和vec的内容交换
	*
	* @param obj			c_vector实例指针
	* @param obj			带交换内容的c_vector实例指针
	*
	* @return				VECTOR_ALL_OK表示成功，否则为失败
	*
	*/
	int (*swap)(struct _c_vector* obj, struct _c_vector* vec);

	/**
	* 将obj的内容排序
	*
	* @param obj			c_vector实例指针
	* @param fun_sort		指定排序策略的函数的回调指针
	*
	* @return				VECTOR_ALL_OK表示成功，否则为失败
	*
	*/
	int (*sort)(struct _c_vector* obj, fun_sort_t fun_sort);

	/**
	* 用obj的中的每个元素调用下fun_each
	*
	* @param obj			c_vector实例指针
	* @param fun_each		待调用的函数
	*
	* @return				VECTOR_ALL_OK表示成功，否则为失败
	*
	*/
	int (*for_each)(struct _c_vector* obj, fun_each_t fun_each);
}c_vector;


/**
* c_vector对象管理者初始化函数
*
* @return				ALL_OK表示成功，其余表示失败
*
* @note					引入c_vector对象管理者是为了将那些不用的c_vector对象暂存下来，等下次需要
						生成c_vector时，优先使用先前不用的c_vector对象，对于频繁使用c_vector对象
						的来说，会提高效率，减少内存碎片。但c_vector对象管理者不是必须的

*/
int c_vector_mgr_init(void);

/**
* c_vector对象管理者回收
*
* 				
* @note					引入c_vector对象管理者是为了将那些不用的c_vector对象暂存下来，等下次需要
						生成c_vector时，优先使用先前不用的c_vector对象，对于频繁使用c_vector对象
						的来说，会提高效率，减少内存碎片。但c_vector对象管理者不是必须的
  
	
						一旦调用了c_vector_mgr_init()，在程序退出时，请务必调用此函数！！否则会内存泄露。
*/
void c_vector_mgr_release(void);

/**
* c_vector实例创建接口
*
* @return				c_vector实例指针
*
*/
c_vector* c_vector_create(void);

/**
* c_vector实例回收接口
*
* @param obj			c_vector实例指针
*
*/
void c_vector_release(c_vector* obj);




/**
* 方便使用的宏定义。命名参照了BREW接口的命名方式
*/
#define VECTORMGR_INIT()									c_vector_mgr_init()
#define VECTORMGR_RELEASE()									c_vector_mgr_release()

#define VECTOR_CreateInstance(p_instance)					p_instance = c_vector_create()
#define VECTOR_Release(p_instance)							c_vector_release(p_instance)

#define VECTOR_CopyVec( obj, vec )							obj->copy_vec(obj, vec)
#define VECTOR_At( obj, index )								obj->at(obj, index)
#define VECTOR_Back( obj )									obj->back(obj)
#define VECTOR_Front( obj )									obj->front(obj)
#define VECTOR_Clear( obj )									obj->clear(obj)
#define VECTOR_Empty( obj )									obj->empty(obj)
#define VECTOR_Erase( obj, pos_start, num )					obj->erase(obj, pos_start, num)
#define VECTOR_Insert( obj, index, data )					obj->insert( obj, index, data )
#define VECTOR_InsertVec( obj, index, vec)					obj->insert_vec(obj, index, vec)
#define VECTOR_Size(obj)									obj->size(obj)
#define VECTOR_PushBack( obj, data )						obj->push_back(obj, data)
#define VECTOR_Swap( obj, vec )								obj->swap(obj, vec)
#define VECTOR_Sort( obj, fun_sort )						obj->sort(obj, fun_sort)
#define VECTOR_ForEach( obj, fun_each )						obj->for_each(obj, fun_each)

#ifdef _cplusplus
}
#endif

#endif