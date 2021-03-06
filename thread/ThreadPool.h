#ifndef _THREAD_POOL_H_
#define _THREAD_POOL_H_

#include "WorkerBodyBase.h"
#include "Worker.h"
#include "misc/NonCopyable.h"

class Dispatcher;

class ThreadPool: public WorkerManagerBase, public noncopyable
{
    public:
        explicit ThreadPool(int num = 0);
        ~ThreadPool();

        bool PostTask(ITask*);
        bool IsRunning() const;
        int  GetTaskNumber() const;
        bool StartPooling();

        //calling this function will shutdown threadpool in an elegant way:
        //running tasks will not abort.
        //however, on destruction, destructor will shutdown all threads using pthread_cancel,
        //which is totally out of control.
        bool StopPooling();

        //shutdown threadpool immediately.
        //killing all workers.
        void ForceShutdown();

    protected:
        virtual int CalcDefaultThreadNum() const;
        virtual int SetWorkerNotify(NotifyerBase* notifyer, int type = 0);

        bool        running_;
        Worker*     worker_;
        Dispatcher* dispatcher_;
};

#endif

