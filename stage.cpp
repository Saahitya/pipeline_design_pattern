#include "stage.h"
#include "payload.h"
#include "shared_queue.h"
#include <chrono>
#include <thread>

template <class T>
bool Stage<T>::stopFunctions = true;

//template<class T>
//void Stage<T>::operator()()
//{
//    T ele = 0;
//    bool isEleMinus1 = false;
//    while (!stopFunctions) {
//        // std::this_thread::sleep_for(std::chrono::milliseconds(10));
//        while (in_->size() == 0)
//            ;
//        std::lock_guard<std::mutex> guard(queue_mutex);
//        isEleMinus1 = (in_->front() == -1) ? true : false;
//        ele = isEleMinus1 ? -1 : this->stage_op(in_->front());
//        in_->pop();
//        if (ele != -1)
//            out_->push(ele);
//        else
//            out_->push(-1);
//    }
//}

template <class T>
void Stage<T>::stage_op_handler()
{
    T ele;
    while (!stopFunctions) {        
        // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        while (in_->size() == 0)
            ;
        std::lock_guard<std::mutex> guard(queue_mutex);
        ele = this->stage_op(in_->front());
        in_->pop();
        out_->push(ele);
    }
}

template <class T>
void Stage<T>::non_linear_stage_op_handler()
{
    T ele;
    while (!stopFunctions) {         
        // std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        std::lock_guard<std::mutex> guard(queue_mutex);
        // s_in_->wait_and_pop(ele);
        ele = this->stage_op(ele);
        out_->push(ele);
    }
}

template <class T>
T Stage<T>::stage_op(T ele)
{
    // std::cout << "Why the heck is this calling the base class function" << std::endl;
    return ele;
}

template <class T>
void Stage<T>::setInQueue(std::queue<T>& q)
{
    in_ = &q;
}
template <class T>
void Stage<T>::setOutQueue(std::queue<T>& q)
{
    out_ = &q;
}

template <class T>
void Stage<T>::setInQueue(shared_queue<T>& q)
{
    s_in_ = &q;
}
template <class T>
void Stage<T>::setOutQueue(shared_queue<T>& q)
{
    s_out_ = &q;
}

//needed to prevent linker errors
template class Stage<int>;
template class Stage<float>;
template class Stage<Payload>;
template class Stage<Payload*>;
