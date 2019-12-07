#include "stage.h"
#include <chrono>
#include <thread>

bool Stage::stopFunctions = true;

void Stage::operator()()
{
    int ele = 0;
    bool isEleMinus1 = false;
    while (!stopFunctions) {
        // std::this_thread::sleep_for(std::chrono::milliseconds(10));
        while (in_->size() == 0)
            ;
        std::lock_guard<std::mutex> guard(queue_mutex);
        isEleMinus1 = (in_->front() == -1) ? true : false;
        ele = isEleMinus1 ? -1 : this->stage_operation(in_->front());
        in_->pop();
        if (ele != -1)
            out_->push(ele);
        else
            out_->push(-1);
    }
}

// int BaseFunctor::stage_operation(int ele)
// {
//     std::cout << "Why the heck is this calling the base class function" << std::endl;
//     return ele;
// }

void Stage::setInQueue(std::queue<int>& q)
{
    in_ = &q;
}

void Stage::setOutQueue(std::queue<int>& q)
{
    out_ = &q;
}