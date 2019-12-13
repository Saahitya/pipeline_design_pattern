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
    friend class Pipeline;

public:
    std::queue<T>* in_;
    std::queue<T>* out_;
    virtual void operator()();
    virtual int stage_operation(int) = 0;
    void setInQueue(std::queue<T>& q);
    void setOutQueue(std::queue<T>& q);
};

#endif