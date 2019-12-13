#include "pipeline.h"
#include <algorithm>
#include <functional>
#include <iostream>

template <class T>
Pipeline<T>::Pipeline()
{
}

template <class T>
void Pipeline<T>::addStage(Stage<T>* bf)
{
    stages_.push_back(bf);
}

template <class T>
std::pair<std::queue<T>*, std::queue<T>*> Pipeline<T>::setupPipeline()
{
    queues_.resize(stages_.size() + 1);
    int index = 0;
    Stage<T>::stopFunctions = true;
    std::cout << std::boolalpha;
    for (auto it = begin(stages_); it != end(stages_); ++it) {
        (*it)->setInQueue(queues_[index]);
        (*it)->setOutQueue(queues_[index + 1]);
        ++index;
    }

    return make_pair(&queues_[0], &queues_[queues_.size() - 1]);
}
template <class T>
void Pipeline<T>::startPipeline()
{
    Stage<T>::stopFunctions = false;
    for (auto it = begin(stages_); it != end(stages_); ++it) {
        std::thread th([&](Stage<T>* bf) { bf->stage_op_handler(); }, *it);
        // std::thread th(**it);
        th.detach();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        // (**it)();
    }
}

template <class T>
void Pipeline<T>::stopPipeline()
{
    while (!(this->isPipelineFlushed()))
        ;
    Stage<T>::stopFunctions = true;
}
template <class T>
bool Pipeline<T>::isPipelineFlushed()
{
    return std::all_of(begin(queues_), end(queues_) - 1, [](auto q) { return !q.size(); });
}

//use flushPipeline only when the pipeline is stopped
template <class T>
bool Pipeline<T>::flushPipeline()
{
    std::cout << Stage<T>::stopFunctions << " hey yeah \n";
    if (Stage<T>::stopFunctions) {
        std::for_each(begin(queues_), end(queues_) - 1, [](auto& q) { while(!q.empty()){q.pop();}; });
        return true;
    }
    return false;
}

//template class Pipeline<int>;
template class Pipeline<float>;