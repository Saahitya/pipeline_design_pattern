#ifndef STAGE_H
#define STAGE_H

#include <iostream>
#include <mutex>
#include <queue>

class Stage {
private:
    std::mutex queue_mutex;
    static bool stopFunctions;
    friend class Pipeline;

public:
    std::queue<int>* in_;
    std::queue<int>* out_;
    virtual void operator()();
    virtual int stage_operation(int) = 0;
    void setInQueue(std::queue<int>& q);
    void setOutQueue(std::queue<int>& q);
};

#endif