#include "pipeline.h"
#include <algorithm>
#include <functional>
#include <iostream>

Pipeline::Pipeline()
{
}

void Pipeline::addStage(Stage* bf)
{
    stages_.push_back(bf);
}

std::pair<std::queue<int>*, std::queue<int>*> Pipeline::setupPipeline()
{
    queues_.resize(stages_.size() + 1);
    int index = 0;
    Stage::stopFunctions = true;
    std::cout << std::boolalpha;
    for (auto it = begin(stages_); it != end(stages_); ++it) {
        (*it)->setInQueue(queues_[index]);
        (*it)->setOutQueue(queues_[index + 1]);
        ++index;
    }

    return make_pair(&queues_[0], &queues_[queues_.size() - 1]);
}

void Pipeline::startPipeline()
{
    Stage::stopFunctions = false;
    for (auto it = begin(stages_); it != end(stages_); ++it) {
        std::thread th([&](Stage* bf) { bf->operator()(); }, *it);
        // std::thread th(**it);
        th.detach();
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

        // (**it)();
    }
}

void Pipeline::stopPipeline()
{
    while (!(this->isPipelineFlushed()))
        ;
    Stage::stopFunctions = true;
}

bool Pipeline::isPipelineFlushed()
{
    return std::all_of(begin(queues_), end(queues_) - 1, [](auto q) { return !q.size(); });
}

//use flushPipeline only when the pipeline is stopped
bool Pipeline::flushPipeline()
{
    std::cout << Stage::stopFunctions << " hey yeah \n";
    if (Stage::stopFunctions) {
        std::for_each(begin(queues_), end(queues_) - 1, [](auto& q) { while(!q.empty()){q.pop();}; });
        return true;
    }
    return false;
}