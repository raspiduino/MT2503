#ifndef __idp_fake_kal_h__
#define __idp_fake_kal_h__

#if defined(IDP_FAKE_KAL_SUPPORT)

typedef void *kal_semid;
typedef void *kal_taskid;
typedef char kal_char;
typedef kal_uint32 kal_status;

typedef enum
{
  KAL_NO_WAIT,
  KAL_INFINITE_WAIT
} kal_wait_mode;

#define KAL_NILTASK_ID (kal_taskid)NULL

extern kal_bool kal_if_hisr(void);
extern kal_bool kal_if_lisr(void);
extern kal_taskid kal_get_task_self_id(void);

extern kal_semid kal_create_sem(kal_char *name, kal_uint32 initial_count);
extern kal_status kal_take_sem(kal_semid ext_sem_id_ptr, kal_wait_mode wait_mode);
extern void kal_give_sem(kal_semid ext_sem_id_ptr);

extern void ASSERT(int const expr);

#endif

#endif
