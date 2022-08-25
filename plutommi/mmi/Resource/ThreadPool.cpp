#include <windows.h>
#include "ThreadPool.h"
#include <process.h>
#include <assert.h>
#include "ResgenLogCAPI.h"

#define THREADP_TAG "THREADPOLL"

#define THREADP_LOG_D(format, args...) RES_LOG_D((THREADP_TAG), (format) , ##args)
#define THREADP_LOG_V(format, args...) RES_LOG_V((THREADP_TAG), (format) , ##args)
#define THREADP_LOG_W(format, args...) RES_LOG_W((THREADP_TAG), (format) , ##args)
#define THREADP_LOG_E(format, args...) RES_LOG_E((THREADP_TAG), (format) , ##args)

ThreadPool::ThreadPool(int poolSize, int waitTimeForThreadsToCompleteMS)
{
    m_nWaitForThreadsToDieMS = waitTimeForThreadsToCompleteMS;
    m_hNotifyShutdown = NULL;

    InitializeCriticalSection(&m_cs);

    if (poolSize > 0 && !Create(poolSize))
    {
        THREADP_LOG_E("Unable to create thread pool due to lack of memory.");
        throw "Unable to create thread pool";
    }
}

ThreadPool::~ThreadPool()
{
    Destroy();
    DeleteCriticalSection(&m_cs);
}

bool ThreadPool::Create(int poolSize)
{
    Destroy();
    if (poolSize == 0)
        return true;

    // create the event which will signal the threads to stop
    m_hNotifyShutdown = CreateEvent(NULL, TRUE, FALSE, NULL);
    assert(m_hNotifyShutdown != NULL);
    if (m_hNotifyShutdown == NULL)
        return false;

    // create the threads
    for (int nIndex = 0; nIndex < poolSize; ++nIndex)
    {
        UINT uThreadId;
        HANDLE hThread = (HANDLE)_beginthreadex(
            NULL, 0, ThreadPool::ThreadProc, this,
            CREATE_SUSPENDED, (UINT*)&uThreadId);
        DWORD dwThreadId = uThreadId;
        assert(INVALID_HANDLE_VALUE != hThread);

        if (hThread == INVALID_HANDLE_VALUE){
            THREADP_LOG_E("Thread %d creation failed in ThreadPool::Create()", nIndex);
            return false;
        }

        // add the entry to the thread list
        ThreadData td;
        td.hWait = CreateEvent(NULL, TRUE, FALSE, NULL);
        td.hThread = hThread;
        td.dwThreadId = dwThreadId;
        THREADP_LOG_V("Create Thread, ID = %d", td.dwThreadId);
        m_threads.push_back(td);
        ResumeThread(hThread);
    }
    return true;
}

void ThreadPool::Destroy()
{
    // Never created?
    if (!m_hNotifyShutdown)
        return;

    // tell all threads to shutdown.
    SetEvent(m_hNotifyShutdown);
    int timElapsed = 0;
    while (GetWorkingThreadCount() > 0 && timElapsed < m_nWaitForThreadsToDieMS)
    {
        Sleep(100); // give the threads a chance to complete
        timElapsed += 100;
    }

    // walk through the events and threads and close them all
    for (ThreadList::iterator iter = m_threads.begin(); iter != m_threads.end(); ++iter)
    {
        THREADP_LOG_V("Close hWait handle: 0x%x, thread ID = %d", iter->hWait, iter->dwThreadId);
        if(CloseHandle(iter->hWait)== 0){
            THREADP_LOG_E("Cannnot close hWait handle, error = 0x%x", GetLastError());
        }

        THREADP_LOG_V("Close hThread handle: 0x%x, thread ID = %d", iter->hThread, iter->dwThreadId);		
        if(CloseHandle(iter->hThread)==0){
            THREADP_LOG_E("Cannnot close hThread handle, error = 0x%x", GetLastError());
        }
    }

    // close the shutdown event
    CloseHandle(m_hNotifyShutdown);
    m_hNotifyShutdown = NULL;

    // free any jobs not released
    for (JobList::iterator funcIter = m_jobList.begin();
        funcIter != m_jobList.end(); funcIter++)
        if (funcIter->runObject && funcIter->runObject->AutoDelete())
            delete funcIter->runObject;

    // empty all collections
    m_jobList.clear();
    m_threads.clear();
}

int ThreadPool::GetWorkingThreadCount()
{
    int nCount = 0;
    EnterCriticalSection(&m_cs);
    for (ThreadList::iterator iter = m_threads.begin(); iter != m_threads.end(); ++iter)
        if (WaitForSingleObject(iter->hWait, 0) == WAIT_OBJECT_0)
            ++nCount;
    LeaveCriticalSection(&m_cs);
    return nCount;
}

void ThreadPool::AddJobToQueue(
    LPTHREAD_START_ROUTINE pFunc, LPVOID pData,
    IRunObject* runObject, ThreadPriority priority)
{
    assert(pFunc != NULL || runObject != NULL);
    JobData jobData;
    jobData.lpStartAddress = pFunc;
    jobData.pData = pData;
    jobData.runObject = runObject;

    // add it to the list
    EnterCriticalSection(&m_cs);
    {
        if (priority == Low)
            m_jobList.push_back(jobData);
        else
            m_jobList.push_front(jobData);

        // See if any threads are free
        for (ThreadList::iterator iter = m_threads.begin(); iter != m_threads.end(); ++iter)
        {
            if (WaitForSingleObject(iter->hWait, 0) == WAIT_TIMEOUT)
            {
                // here is a free thread, wake it up
                SetEvent(iter->hWait);
                break;
            }
        }
    }
    LeaveCriticalSection(&m_cs);
}

// Called by the worker thread to get its wake-up event handle
HANDLE ThreadPool::GetWaitHandle(DWORD dwThreadId)
{
    HANDLE hWait = NULL;
    EnterCriticalSection(&m_cs);
    for (ThreadList::iterator iter = m_threads.begin(); !hWait && iter != m_threads.end(); ++iter)
        if (iter->dwThreadId == dwThreadId)
            hWait = iter->hWait;
    LeaveCriticalSection(&m_cs);
    return hWait;
}

// static method:
// This is the worker thread function which will run
// continuously till the Thread Pool is deleted.
UINT __stdcall ThreadPool::ThreadProc(LPVOID pParam)
{
    ThreadPool* pool = static_cast<ThreadPool*>(pParam);
    assert(NULL != pool);
    if (pool == NULL)
        return 1;

    DWORD dwThreadId = GetCurrentThreadId();
    HANDLE hWaits[2] = { pool->GetWaitHandle(dwThreadId), pool->m_hNotifyShutdown };
    bool bContinue = true;
    while (bContinue)
    {
        DWORD waitResult = WaitForMultipleObjects(2, hWaits, FALSE, INFINITE);
        if (waitResult == WAIT_FAILED)
            throw "Wait failed";
        if (waitResult == WAIT_OBJECT_0 || waitResult == WAIT_OBJECT_0 + 1)
        {
            // Shutting down?
            if (pool->CheckThreadStop())
                break;

            // We have been woken up.  Get the next available job
            EnterCriticalSection(&pool->m_cs);
            JobList::iterator iter = pool->m_jobList.begin();
            if (iter == pool->m_jobList.end())
            {
                // No job available, go back to sleep
                ResetEvent(hWaits[0]);
                LeaveCriticalSection(&pool->m_cs);
                continue;
            }
            else
            {
                // Get the job and remove it from the queue
                LPTHREAD_START_ROUTINE proc = iter->lpStartAddress;
                LPVOID data = iter->pData;
                IRunObject* runObject = iter->runObject;
                pool->m_jobList.pop_front();
                LeaveCriticalSection(&pool->m_cs);

                // Run the job
                if (proc)
                    proc(data);
                else if (runObject)
                {
                    bool autoDelete = runObject->AutoDelete();
                    runObject->Run(); // may execute "delete this"
                    if (autoDelete)
                        delete runObject;
                }
            }
        }
    }
    // Thread is shutting down
    ResetEvent(hWaits[0]);
    return 0;
}

