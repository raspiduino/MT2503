
/* ============================================================================
* C string interface
* 
* 仿照STL中string的接口，实现C版本的string。
*
* 作者：skybuf  <MSN:skybuf@gmail.com>
* 
* 开源代码，共享与交流之用，无版权
*
* ========================================================================= */
#ifndef __C_STRING_H__
#define __C_STRING_H__

#ifdef _cplusplus
extern "C"{
#endif

#if !defined (__REMOVE_LOG_TO_FILE__)

/*错误值定义*/
#define STRING_ALL_OK					0				/*完好，没有错误*/
#define STRING_ERR_NO_MEMORY			-100			/*内存不足*/
#define STRING_ERR_INVALID_INSTANCE		-101			/*无效的c_string实例*/
#define STRING_ERR_PARAM				-102			/*参数错误*/



/**
* c_string的接口集。
*/
typedef struct _c_string
{
	/**
	* 将str中pos_start位置开始的num个字符追加到obj的尾部。
	*
	* @param obj			c_string实例指针
	* @param str			待追加的字符串
	* @param pos_start		基于0的str中的起始位置，须小于str的长度
	* @param num			从str中pos_start位置起的字符数，-1表示剩余的全部
	*
	* @return				ALL_OK表示成功，其余表示失败
	*
	* @note					若pos_start+num大于str的长度，则num等同于-1，将追加剩余的字符串到obj中
	*
	*/
	int (*append)(struct _c_string* obj, const char* str, unsigned int pos_start, int num);
	/**
	* 将string追加到obj的尾部。
	*
	* @param obj			c_string实例指针
	* @param string			待追加的c_string
	*
	* @return				ALL_OK表示成功，其余表示失败
	*/
	int (*append_string)(struct _c_string* obj, const struct _c_string* string);

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
	int (*compare)(struct _c_string* obj, const char* str, unsigned int pos_start, int num, unsigned char b_uplower);

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
	int (*compare_string)(struct _c_string* obj, const struct _c_string* string, unsigned char b_uplower);

	/**
	* 将str中pos_start位置开始的num个字符拷贝到obj中，obj的原有内容将被替换。
	*
	* @param obj			c_string实例指针
	* @param str			待拷贝的字符串
	* @param pos_start		基于0的str中的起始位置，须小于str的长度
	* @param num			从str中pos_start位置起的字符数，-1表示剩余的全部
	*
	* @return				ALL_OK表示成功，其余表示失败
	*
	* @note					若pos_start+num大于str的长度，则num等同于-1，将拷贝剩余的字符串
	*
	*/
	int (*copy)(struct _c_string* obj, const char* str, unsigned int pos_start, int num);
	/**
	* 将string拷贝到obj中，obj的原有内容将被替换。
	*
	* @param obj			c_string实例指针
	* @param string			待追加的c_string
	*
	* @return				ALL_OK表示成功，其余表示失败
	*/
	int (*copy_string)(struct _c_string* obj, const struct _c_string* string);

	/**
	* 将obj中从pos_start位置开始的num个字符擦除
	*
	* @param obj			c_string实例指针
	* @param pos_start		基于0的str中的起始位置，须小于str的长度
	* @param num			从str中pos_start位置起的字符数，-1表示剩余的全部。
	*
	* @return				ALL_OK表示成功，其余表示失败
	*
	* @note					若pos_start+num大于obj中字符串的长度，则num等同于-1，将擦除剩余的字符串
	*
	*/
	int (*erase)(struct _c_string* obj, unsigned int pos_start, int num);

	/**
	* 将obj中从pos_start位置开始的num个字符替换成str
	*
	* @param obj			c_string实例指针
	* @param pos_start		基于0的obj中字符串的起始位置，须小于obj的长度
	* @param num			从obj中字符串中pos_start位置起的字符数，-1表示剩余的全部
	* @param str			可替换的字符串
	*
	* @return				ALL_OK表示成功，其余表示失败
	*
	* @note					若pos_start+num大于obj中字符串的长度，则num等同于-1，将替换剩余的字符串
	*
	*/
	int (*replace)(struct _c_string* obj, unsigned int pos_start, int num, const char* str);
	/**
	* 将obj中的str_src字符串替换成str_dst
	*
	* @param obj			c_string实例指针
	* @param str_src		待替换的字符串
	* @param str_dst		可替换的字符串
	*
	* @return				ALL_OK表示成功，其余表示失败
	*/
	int (*replace_str)(struct _c_string* obj, const char* str_src, const char* str_dst);

	/**
	* 将str中pos_start_str位置开始的num_str个字符插入到obj的pos_start_obj位置
	*
	* @param obj			c_string实例指针
	* @param pos_start_obj	obj中的插入位置，基于0
	* @param str			待插入的字符串
	* @param pos_start_str	基于0的str中的起始位置，须小于str的长度
	* @param num_str		从str中pos_start_str位置起的字符数，-1表示剩余的全部
	*
	* @return				ALL_OK表示成功，其余表示失败
	*
	* @note					若pos_start_str+num_str大于obj中字符串的长度，则num_str等同于-1，将插入剩余的字符串
	*
	*/
	int (*insert)(struct _c_string* obj, unsigned int pos_start_obj, const char* str,unsigned int pos_start_str, int num_str);
	/**
	* 将string插入到obj的pos_start_obj位置
	*
	* @param obj			c_string实例指针
	* @param pos_start_obj	obj中的插入位置，基于0
	* @param string			待插入的c_string
	*
	* @return				ALL_OK表示成功，其余表示失败
	*/
	int (*insert_string)( struct _c_string* obj, unsigned int pos_start_obj, const struct _c_string* string );
	/**
	* 将num_ch个ch插入到obj的pos_start_obj位置
	*
	* @param obj			c_string实例指针
	* @param pos_start_obj	obj中的插入位置，基于0
	* @param ch				待插入的字符
	* @param num_ch			待插入的字符数
	*
	* @return				ALL_OK表示成功，其余表示失败
	*/
	int (*insert_ch)(struct _c_string* obj, unsigned int pos_start_obj, char ch, unsigned int num_ch);

	/**
	* 在obj中顺序查找子字符串的首次出现位置，基于0。子字符串由str中pos_start开始的num个字符组成
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
	int (*find_first_of)(struct _c_string* obj, const char* str, unsigned int pos_start, int num);
	/**
	* 在obj中顺序查找子字符串string的首次出现位置，基于0
	*
	* @param obj			c_string实例指针
	* @param string			待查找的子字符串
	*
	* @return				子字符串的起始位置，-1表示没有找到，<-1表示失败
	*/
	int (*find_first_string_of)(struct _c_string* obj, struct _c_string* string);
	/**
	* 在obj中顺序查找字符ch首次出现的位置，基于0
	*
	* @param obj			c_string实例指针
	* @param ch				待查找的字符
	*
	* @return				字符的起始位置，-1表示没有找到，<-1表示失败
	*/
	int (*find_first_ch_of)(struct _c_string* obj, char ch);

	/**
	* 在obj中逆序查找子字符串的首次出现位置，基于0。子字符串由str中pos_start开始的num个字符组成
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
	int (*r_find_first_of)(struct _c_string* obj, const char* str, unsigned int pos_start, int num);
	/**
	* 在obj中逆序查找子字符串string的首次出现位置，基于0
	*
	* @param obj			c_string实例指针
	* @param string			待查找的子字符串
	*
	* @return				子字符串的逆起始位置，-1表示没有找到，<-1表示失败
	*/
	int (*r_find_first_string_of)(struct _c_string* obj, struct _c_string* string);
	/**
	* 在obj中逆查找字符ch首次出现的位置，基于0
	*
	* @param obj			c_string实例指针
	* @param ch				待查找的字符
	*
	* @return				字符串逆起始位置，-1表示没有找到，<-1表示失败
	*/
	int (*r_find_first_ch_of)(struct _c_string* obj, char ch);

	/**
	* 得到obj中位于index位置的字符
	*
	* @param obj			c_string实例指针
	* @param index			索引，基于0
	*
	* @return				字符，返回0表示错误
	*
	*/
	char (*at)(struct _c_string* obj, unsigned int index);
	/**
	* 得到obj中的字符串
	*
	* @param obj			c_string实例指针
	*
	* @return				字符串
	*/
	const char* (*str)(struct _c_string* obj);
	/**
	* 清空obj中的内容
	*
	* @param obj			c_string实例指针
	*
	* @return				无
	*/
	void (*clear)(struct _c_string* obj);

	/**
	* 测试obj是否为空
	*
	* @param obj			c_string实例指针
	*
	* @return				1表示为空，0表示有内容，其余表示失败
	*/
	unsigned char (*empty)(struct _c_string* obj);
	/**
	* 得到obj中字符串的长度
	*
	* @param obj			c_string实例指针
	*
	* @return				长度， <0表示失败
	*/
	int (*length)(struct _c_string* obj);

	/**
	* 得到obj中从pos_start开始的num个字符组成的子字符串
	*
	* @param obj			c_string实例指针
	* @param pos_start		基于0的obj中子字符串的起始位置
	* @param num			从pos_start开始的字符数，-1表示剩余的全部
	*
	* @return				c_string实例指针，由子字符串构成
	*
	* @note					返回的实例指针必须用c_string_release回收。
	*
	*						若pos_start+num大于obj的长度，则num等同于-1，将得到剩余的子字符串
	*
	*/
	struct _c_string* (*substr)(struct _c_string* obj, unsigned int pos_start, int num);
	/**
	* 将obj与string中的内容交换
	*
	* @param obj			c_string实例指针
	* @param string 		c_string实例指针
	*
	* @return				无
	*/
	void (*swap)(struct _c_string* obj, struct _c_string* string);

	/**
	* 将obj中的字符串转换成大写
	*
	* @param obj			c_string实例指针
	*
	* @return				无
	*/
	void (*to_upper)(struct _c_string* obj);
	/**
	* 将obj中的字符串转换成小写
	*
	* @param obj			c_string实例指针
	*
	* @return				无
	*/
	void (*to_lower)(struct _c_string* obj);
	
}c_string;

/**
* c_string对象管理者初始化函数
*
* @return				ALL_OK表示成功，其余表示失败
*
* @note					通常，一个程序内会使用较多的字符串，而绝大部分字符串会比较短，
						如果每个string对象都是从堆上分配新的内存来存储所表示的字符串，
						则效率低下，且还可能产生内存碎片。

						引入c_string对象管理者是为了将那些不用的c_string对象暂存下来，等下次需要
						生成c_string时，优先使用先前不用的c_string对象，这样就避免了上述的问题。


						在初次调用c_string_create时，请务必调用此函数！！否则会创建失败。
*/
int c_string_mgr_init(void);

/**
* c_string对象管理者回收
*
* 				
* @note					通常，一个程序内会使用较多的字符串，而绝大部分字符串会比较短，
						如果每个string对象都是从堆上分配新的内存来存储所表示的字符串，
						则效率低下，且还可能产生内存碎片。

						引入c_string对象管理者是为了将那些不用的c_string对象暂存下来，等下次需要
						生成c_string时，优先使用先前不用的c_string对象，这样就避免了上述的问题。
  
	
						在程序退出时，请务必调用此函数！！否则会内存泄露。
*/
void c_string_mgr_release(void);

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
c_string* c_string_create(const char* str, unsigned int pos_start, int num);

/**
* c_string实例回收接口
*
* @param obj			c_string实例指针，由c_string_create或者substr返回
*
* @return				无
*/
void c_string_release(c_string* obj);


/**
* 方便使用的宏定义。命名参照了BREW接口的命名方式
*/
#define STRINGMGR_INIT()													c_string_mgr_init()
#define STRINGMGR_RELEASE()													c_string_mgr_release()

#define STRING_CreateInstance(p_instance, p_str, pos_start, num)			p_instance = c_string_create(p_str, pos_start, num)
#define STRING_Release(p_instance)											c_string_release(p_instance)

#define STRING_Append( obj, str, pos_start, num )							obj->append(obj, str, pos_start, num)
#define STRING_AppendString( obj, string )									obj->append_string(obj, string)
#define STRING_Compare( obj, str, pos_start, num, b_uplower )				obj->compare(obj, str, pos_start, num, b_uplower)
#define STRING_CompareString( obj, string, b_uplower )						obj->compare_string(obj, string, b_uplower)
#define STRING_Copy( obj, str, pos_start, num )								obj->copy(obj, str, pos_start, num)
#define STRING_CopyString( obj, string )									obj->copy_string(obj, string)
#define STRING_Erase( obj, pos_start, num )									obj->erase(obj, pos_start, num)
#define STRING_Replace( obj, pos_start, num, str)							obj->replace(obj, pos_start, num, str)
#define STRING_ReplaceStr( obj, str_src, str_dst )							obj->replace_str( obj, str_src, str_dst )
#define STRING_Insert( obj, pos_start_obj, str, pos_start_str, num_str)		obj->insert(obj, pos_start_obj, str, pos_start_str, num_str)
#define STRING_InsertString( obj, pos_start_obj, string )					obj->insert_string(obj, pos_start_obj, string)
#define STRING_InsertCh(obj, pos_start_obj, ch, num_ch)						obj->insert_ch(obj, pos_start_obj, ch, num_ch)
#define STRING_Find( obj, str, pos_start, num )								obj->find_first_of(obj, str, pos_start, num)
#define STRING_FindString( obj, string )									obj->find_first_string_of(obj, string)
#define STRING_FindCh( obj, ch )											obj->find_first_ch_of(obj, ch)
#define STRING_RFind( obj,  str,  pos_start, num )							obj->r_find_first_of(obj,  str,  pos_start, num)
#define STRING_RFindString( obj, string )									obj->r_find_first_string_of(obj, string)
#define STRING_RFindCh( obj, ch )											obj->r_find_first_ch_of(obj, ch)
#define STRING_At( obj, index )												obj->at(obj, index)
#define STRING_Str( obj )													obj->str(obj)
#define STRING_Clear( obj )													obj->clear(obj)
#define STRING_Empty( obj )													obj->empty(obj)
#define STRING_Length( obj )												obj->length(obj)
#define STRING_Substr( obj,  pos_start,  num )								obj->substr(obj,  pos_start,  num)
#define STRING_Swap( obj,  string )											obj->swap(obj,  string)
#define STRING_ToUpper( obj )												obj->to_upper(obj)
#define STRING_ToLower( obj )												obj->to_lower(obj)

#endif /*__REMOVE_LOG_TO_FILE__*/

#ifdef _cplusplus
}
#endif

#endif