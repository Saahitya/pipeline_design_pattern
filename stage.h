#ifndef STAGE_H
#define STAGE_H

#include <iostream>
#include <mutex>
#include <queue>
template <class T>
class Stage {
private:
    std::mutex queue_mutex;
    static bool stopFunctions;
    template<class U> friend class Pipeline;
    std::queue<T>* in_;
    std::queue<T>* out_;
    void setInQueue(std::queue<T>& q);
    void setOutQueue(std::queue<T>& q);
    virtual T stage_op(T) = 0;
//    virtual void operator()();
    virtual void stage_op_handler();

//public: refactored all attributes and methods to private
};

#endif