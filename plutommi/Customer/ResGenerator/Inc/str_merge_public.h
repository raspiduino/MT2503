#ifndef __STR_MERGE_PUBLIC_H__
#define __STR_MERGE_PUBLIC_H__

/* record string merge result */
#define STRMERGE_LOAD_REF_LIST_ERR 1
#define STRMERGE_LOAD_SSC_ERR 2

#define STRMERGE_NO_ERR 0
#define STRMERGE_ERR_MSG_LEN_MAX 200


void str_merge_set_err(int err_code, wchar_t * msg);
int str_merge_get_err(wchar_t ** msg);
int  MergeStrRes(void);
int  GenerateStrResFile(void);


#endif //__STR_MERGE_PUBLIC_H__