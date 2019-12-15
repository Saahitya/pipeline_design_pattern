#ifndef STAGE_H
#define STAGE_H

#include "shared_queue.h"
#include <iostream>
#include <mutex>
#include <queue>
template <class T>
class Stage {
private:
    std::mutex queue_mutex;
    static bool stopFunctions;
    template <class U>
    friend class Pipeline;
    std::queue<T>* in_;
    std::queue<T>* out_;

    shared_queue<T>* s_in_;
    shared_queue<T>* s_out_;
    void setInQueue(std::queue<T>& q);
    void setOutQueue(std::queue<T>& q);
    void setInQueue(shared_queue<T>& sq);
    void setOutQueue(shared_queue<T>& sq);

    virtual T stage_op(T) = 0;
    //    virtual void operator()();
    virtual void stage_op_handler();
    virtual void non_linear_stage_op_handler();

    //public: refactored all attributes and methods to private
};

#endif