
#include "ntpd_comm.h"
#include "ntp_fp.h"
#include "ntp_lists.h"
#include "recvbuff.h"
#include "ntpd_mem.h"

#ifdef DEBUG
static void uninit_recvbuff(void);
#endif 

/*
 * Memory allocation
 */
static unsigned long full_recvbufs;     /* number of recvbufs on fulllist */
static unsigned long free_recvbufs;     /* number of recvbufs on freelist */
static unsigned long total_recvbufs;    /* total recvbufs currently in use */
static unsigned long lowater_adds;      /* number of times we have added memory */
static unsigned long buffer_shortfall;  /* number of missed free receive buffers
                                           between replenishments */

static ISC_LIST(recvbuf_t) full_recv_list;  /* Currently used recv buffers */
     static recvbuf_t *free_recv_list;      /* Currently unused buffers */

#if defined(SYS_WINNT)

/*
 * For Windows we need to set up a lock to manipulate the
 * recv buffers to prevent corruption. We keep it lock for as
 * short a time as possible
 */
     static CRITICAL_SECTION RecvLock;

# define LOCK()		EnterCriticalSection(&RecvLock)
# define UNLOCK()	LeaveCriticalSection(&RecvLock)
#else /* defined(SYS_WINNT) */ 
# define LOCK()
# define UNLOCK()
#endif /* defined(SYS_WINNT) */ 


/*****************************************************************************
 * FUNCTION
 *  free_recvbuffs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
     unsigned long free_recvbuffs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return free_recvbufs;
}


/*****************************************************************************
 * FUNCTION
 *  full_recvbuffs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
unsigned long full_recvbuffs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return full_recvbufs;
}


/*****************************************************************************
 * FUNCTION
 *  total_recvbuffs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
unsigned long total_recvbuffs(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return total_recvbufs;
}


/*****************************************************************************
 * FUNCTION
 *  lowater_additions
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
unsigned long lowater_additions(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return lowater_adds;
}


/*****************************************************************************
 * FUNCTION
 *  initialise_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buff        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void initialise_buffer(recvbuf_t *buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(buff, 0, sizeof(*buff));
}


/*****************************************************************************
 * FUNCTION
 *  create_buffers
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nbufs       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void create_buffers(int nbufs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    register recvbuf_t *bufp;
    int i, abuf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    abuf = nbufs + buffer_shortfall;
    buffer_shortfall = 0;

    for (i = 0; i < abuf; i++)
    {
        /*
         * Allocate each buffer individually so they can be
         * free()d during ntpd shutdown on DEBUG builds to
         * keep them out of heap leak reports.
         */
        bufp = ntpd_malloc(sizeof(*bufp));

        memset(bufp, 0, sizeof(*bufp));
        LINK_SLIST(free_recv_list, bufp, link.next);
        /* //bufp++; */
        free_recvbufs++;
        total_recvbufs++;
    }
    lowater_adds++;
}


/*****************************************************************************
 * FUNCTION
 *  init_recvbuff
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nbufs       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void init_recvbuff(int nbufs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Init buffer free list and stat counters
     */
    ISC_LIST_INIT(full_recv_list);
    free_recvbufs = total_recvbufs = 0;
    full_recvbufs = lowater_adds = 0;

    create_buffers(nbufs);
}


/*****************************************************************************
 * FUNCTION
 *  uninit_recvbuff
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void uninit_recvbuff(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    recvbuf_t *rbunlinked;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((rbunlinked = ISC_LIST_HEAD(full_recv_list)) != NULL)
    {
        ISC_LIST_DEQUEUE_TYPE(full_recv_list, rbunlinked, link, recvbuf_t);
        ntpd_free(rbunlinked);
    }

    do
    {
        UNLINK_HEAD_SLIST(rbunlinked, free_recv_list, link.next);
        if (rbunlinked != NULL)
            ntpd_free(rbunlinked);
    } while (rbunlinked != NULL);
}

/*
 * freerecvbuf - make a single recvbuf available for reuse
 */


/*****************************************************************************
 * FUNCTION
 *  freerecvbuf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rb      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void freerecvbuf(recvbuf_t *rb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rb == NULL)
    {

        return;
    }

    LOCK();
    (rb->used)--;
    if (rb->used != 0)
    {
        /* msyslog(LOG_ERR, "******** freerecvbuff non-zero usage: %d *******", rb->used); */
    }
    LINK_SLIST(free_recv_list, rb, link.next);
    free_recvbufs++;
    UNLOCK();
}


/*****************************************************************************
 * FUNCTION
 *  add_full_recv_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rb      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void add_full_recv_buffer(recvbuf_t *rb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rb == NULL)
    {
        /* //msyslog(LOG_ERR, "add_full_recv_buffer received NULL buffer"); */
        return;
    }
    LOCK();
    ISC_LINK_INIT(rb, link);
    ISC_LIST_APPEND(full_recv_list, rb, link);
    full_recvbufs++;
    UNLOCK();
}


/*****************************************************************************
 * FUNCTION
 *  get_free_recv_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
recvbuf_t *get_free_recv_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    recvbuf_t *buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LOCK();
    UNLINK_HEAD_SLIST(buffer, free_recv_list, link.next);
    if (buffer != NULL)
    {
        free_recvbufs--;
        initialise_buffer(buffer);
        (buffer->used)++;
    }
    else
        buffer_shortfall++;
    UNLOCK();
    return (buffer);
}

#ifdef HAVE_IO_COMPLETION_PORT


/*****************************************************************************
 * FUNCTION
 *  get_free_recv_buffer_alloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
recvbuf_t *get_free_recv_buffer_alloc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    recvbuf_t *buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buffer = get_free_recv_buffer();
    if (NULL == buffer)
    {
        create_buffers(RECV_INC);
        buffer = get_free_recv_buffer();
    }
    NTP_ENSURE(buffer != NULL);
    return (buffer);
}
#endif /* HAVE_IO_COMPLETION_PORT */ 


/*****************************************************************************
 * FUNCTION
 *  get_full_recv_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
recvbuf_t *get_full_recv_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    recvbuf_t *rbuf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    LOCK();

#ifdef HAVE_SIGNALED_IO
    /*
     * make sure there are free buffers when we
     * wander off to do lengthy packet processing with
     * any buffer we grab from the full list.
     * 
     * fixes malloc() interrupted by SIGIO risk
     * (Bug 889)
     */
    if (NULL == free_recv_list || buffer_shortfall > 0)
    {
        /*
         * try to get us some more buffers
         */
        create_buffers(RECV_INC);
    }
#endif /* HAVE_SIGNALED_IO */ 

    /*
     * try to grab a full buffer
     */
    rbuf = ISC_LIST_HEAD(full_recv_list);
    if (rbuf != NULL)
    {
        ISC_LIST_DEQUEUE_TYPE(full_recv_list, rbuf, link, recvbuf_t);
        --full_recvbufs;
    }
    else
        /*
         * Make sure we reset the full count to 0
         */
        full_recvbufs = 0;
    UNLOCK();
    return (rbuf);
}

/*
 * Checks to see if there are buffers to process
 */


/*****************************************************************************
 * FUNCTION
 *  has_full_recv_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int has_full_recv_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ISC_LIST_HEAD(full_recv_list) != NULL)
        return (NTP_TRUE);
    else
        return (NTP_FALSE);
}

