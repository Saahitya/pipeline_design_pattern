#include "pipeline.h"
#include "shared_queue.h"
#include "payload.h"
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
    stage_instance_counts_.push_back(1);
}

template <class T>
void Pipeline<T>::addStageWithCount(Stage<T>* bf, int count)
{
    stages_.push_back(bf);
    stage_instance_counts_.push_back(count);
}

// template <class T>
// std::pair<std::queue<T>*, std::queue<T>*> Pipeline<T>::setupPipeline()
// {
//     queues_.resize(stages_.size() + 1);
//     int index = 0;
//     Stage<T>::stopFunctions = true;
//     std::cout << std::boolalpha;
//     for (auto it = begin(stages_); it != end(stages_); ++it) {
//         (*it)->setInQueue(queues_[index]);
//         (*it)->setOutQueue(queues_[index + 1]);
//         ++index;
//     }

//     return make_pair(&queues_[0], &queues_[queues_.size() - 1]);
// }

template <class T>
std::pair<shared_queue<T>*, shared_queue<T>*> Pipeline<T>::setupPipeline()
{
    shared_queues_.resize(stages_.size() + 1);
    int index = 0;
    Stage<T>::stopFunctions = true;
    std::cout << std::boolalpha;
    for (auto it = begin(stages_); it != end(stages_); ++it) {
        (*it)->setInQueue(shared_queues_[index]);
        (*it)->setOutQueue(shared_queues_[index + 1]);
        ++index;
    }

    return std::make_pair(&shared_queues_[0], &shared_queues_[shared_queues_.size() - 1]);
}


// template <class T>
// void Pipeline<T>::startPipeline()
// {
//     Stage<T>::stopFunctions = false;
//     for (auto it = begin(stages_); it != end(stages_); ++it) {
//         std::thread th([&](Stage<T>* bf) { bf->stage_op_handler(); }, *it);
//         // std::thread th(**it);
//         th.detach();
//         // std::this_thread::sleep_for(std::chrono::milliseconds(1));

//         // (**it)();
//     }
// }

template <class T>
void Pipeline<T>::startPipeline()
{
    Stage<T>::stopFunctions = false;
    for (auto it = begin(stages_); it != end(stages_); ++it) {
        // for(int i = 1; i <= stage_instance_counts_[it-begin(stages_)]; ++i) {
            std::thread th([&](Stage<T>* bf) { bf->stage_op_handler(); }, *it);
            // std::thread th(**it);
            th.detach();
            // std::this_thread::sleep_for(std::chrono::milliseconds(1));
        // }
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
// template <class T>
// bool Pipeline<T>::isPipelineFlushed()
// {
//     return std::all_of(begin(queues_), end(queues_) - 1, [](std::queue<T>& q) { return !q.size(); });
// }

template <class T>
bool Pipeline<T>::isPipelineFlushed()
{
    return std::all_of(begin(shared_queues_), end(shared_queues_) - 1, [](shared_queue<T>& q) { return !q.size(); });
}


//use flushPipeline only when the pipeline is stopped
// template <class T>
// bool Pipeline<T>::flushPipeline()
// {
//     if (Stage<T>::stopFunctions) {
//         // std::for_each(begin(queues_), end(queues_) - 1, [](std::queue<T>& q) { while(!q.empty()){q.pop();}; });
//         return true;
//     }
//     return false;
// }

template <class T>
bool Pipeline<T>::flushPipeline()
{
    if (Stage<T>::stopFunctions) {
        std::for_each(begin(shared_queues_), end(shared_queues_) - 1, [](shared_queue<T>& q) { while(!q.empty()){T temp; q.wait_and_pop(temp);}; });
        return true;
    }
    return false;
}


//needed to prevent linker errors
template class Pipeline<int>;
template class Pipeline<float>;
template class Pipeline<Payload>;
template class Pipeline<Payload*>;