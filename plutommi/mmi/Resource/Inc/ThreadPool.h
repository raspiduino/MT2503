#pragma once
// Filename     : ThreadPool.h
// Author       : Siddharth Barman
// Date         : 18 Sept 2005
// Refactored   : 29 Sept 2010 by Greg Labute
/* Description  : Defines ThreadPool class. How to use the Thread Pool. First
                create a ThreadPool object. The default constructor will
                create 10 threads in the pool. To defer creation of the pool
                pass a pool size of 0 to the constructor.

                You can use two approaches while working with the thread
                pool.

                1. To make use of the thread pool, you will need to first
                create a function having the following signature
                DWORD WINAPI ThreadProc(LPVOID); Check the CreateThread
                documentation in MSDN to get details. Add this function to
                the pool by calling the Run() method and pass in the function
                name and a void* pointer to any object you want. The pool will
                pick up the function passed into Run() method and execute as
                threads in the pool become free.

                2. Instead of using a function pointer, you can use an object
                of a class which derives from IRunObject. Pass a pointer to
                this object in the Run() method of the thread pool. As threads
                become free, the thread pool will call the Run() method of you
                r class. You will also need to write a body for AutoDelete() f
                unction. If the return value is true, the thread pool will use
                'delete' to free the object you pass in. If it returns false,
                the thread pool will not do anything else to the object after
                calling the Run() function.

                It is possible to destroy the pool whenever you want by
                calling the Destroy() method. If you want to create a new pool
                call the Create() method.

                If this code works, it was written by Siddharth Barman, email
                siddharth_b@yahoo.com.
                _____ _                        _  ______           _
                |_   _| |                      | | | ___ \         | |
                | | | |__  _ __ ___  __ _  __| | | |_/ /__   ___ | |
                | | | '_ \| '__/ _ \/ _` |/ _` | |  __/ _ \ / _ \| |
                | | | | | | | |  __/ (_| | (_| | | | | (_) | (_) | |
                \_/ |_| |_|_|  \___|\__,_|\__,_| \_|  \___/ \___/|_|
------------------------------------------------------------------------------*/

#include <list>
#include <vector>

class ThreadPool
{
public:
    // PoolSize is the number of worker threads that will be created.
    ThreadPool(int poolSize = 10, int waitTimeForThreadsToCompleteMS = 5000);
    virtual ~ThreadPool();

    // Use this method to create the worker threads if you specified a poolSize
    // of 0 in the constructor, or if you want to change the number of worker threads.
    // Returns: true if no error.
    bool Create(int poolSize);

    // Use this method to destroy the worker threads. The destructor of
    // this class will destroy the threads automatically.
    void Destroy();

    // How many worker threads are in the pool?
    int GetPoolSize() { return m_threads.size(); }

    // This decides whether a job is added to the front or back of the queue.
    enum ThreadPriority { High, Low };

    // Run a job
    void Run(LPTHREAD_START_ROUTINE pFunc, LPVOID pData, ThreadPriority priority = Low)
        { AddJobToQueue(pFunc, pData, NULL, priority); }
    struct IRunObject
    {
        virtual ~IRunObject() {}
        virtual void Run() = 0;
        virtual bool AutoDelete() = 0;
    };
    void Run(IRunObject* job, ThreadPriority priority = Low)
        { AddJobToQueue(NULL, NULL, job, priority); }

    // This is function expected to be called by thread functions or IRunObject
    // derived. The expectation is that the code will check this 'property' of
    // the pool and stop its processing as soon as possible.
    bool CheckThreadStop()
    { return WaitForSingleObject(m_hNotifyShutdown, 0) != WAIT_TIMEOUT; }

    // How many threads are currently busy?
    int GetWorkingThreadCount();

private:
    void AddJobToQueue(
        LPTHREAD_START_ROUTINE pFunc, LPVOID pData,
        IRunObject* runObject, ThreadPriority priority);

    // This method is called by the worker threads
    HANDLE GetWaitHandle(DWORD dwThreadId);

    // The worker thread proc
    static UINT __stdcall ThreadProc(LPVOID pParam);

    // info about worker threads will be stored here
    struct ThreadData
    {
        HANDLE hWait;
        HANDLE hThread;
        DWORD dwThreadId;
    };
    typedef std::vector<ThreadData, std::allocator<ThreadData> > ThreadList;

    // jobs passed in by clients will be stored here
    struct JobData
    {
        LPTHREAD_START_ROUTINE lpStartAddress;
        LPVOID pData;
        IRunObject* runObject;
    };
    typedef std::list<JobData, std::allocator<JobData> > JobList;

#pragma warning (push)
#pragma warning (disable : 4251) // non-dll interface, ok because member is private
    JobList m_jobList;
    ThreadList m_threads;
#pragma warning (pop)

    int m_nWaitForThreadsToDieMS; // In milli-seconds
    HANDLE m_hNotifyShutdown; // notifies worker threads to terminate immediately

    CRITICAL_SECTION m_cs;
};

