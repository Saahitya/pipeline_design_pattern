#include "pipeline.h"
#include <iostream>
#include <algorithm>
#include <functional>


Pipeline::Pipeline()
{
}

void Pipeline::addStage(BaseFunctor *bf)
{
    stages_.push_back(bf);
}

std::pair<std::queue<int>*, std::queue<int>*> Pipeline::setupPipeline()
{
    queues_.resize(stages_.size()+1);
    int index = 0;
    BaseFunctor::stopFunctions = false;
    std::cout << std::boolalpha;
    for(auto it = begin(stages_); it != end(stages_); ++it)
    {
        (*it)->setInQueue(queues_[index]);
        (*it)->setOutQueue(queues_[index+1]);
        ++index;
    }

    return make_pair(&queues_[0], &queues_[queues_.size()-1]);
}

void Pipeline::startPipeline()
{
    for(auto it = begin(stages_); it != end(stages_); ++it)
    {
        std::thread th([&](BaseFunctor *bf){bf->operator()();}, *it);
        // std::thread th(**it);
        th.detach();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        // (**it)();
    }
}

void Pipeline::stopPipeline()
{
    while(!(this->isPipelineFlushed()));
    BaseFunctor::stopFunctions = true;
}

bool Pipeline::isPipelineFlushed()
{
    return std::all_of(begin(queues_), end(queues_)-1, [](auto q){return !q.size();});
}