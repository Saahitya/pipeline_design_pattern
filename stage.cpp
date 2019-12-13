#include "stage.h"
#include <chrono>
#include <thread>

template<class T>
bool Stage<T>::stopFunctions = true;

template<class T>
void Stage<T>::operator()()
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
template<class T>
void Stage<T>::setInQueue(std::queue<T>& q)
{
    in_ = &q;
}
template<class T>
void Stage<T>::setOutQueue(std::queue<T>& q)
{
    out_ = &q;
}
template class Stage<int>;
