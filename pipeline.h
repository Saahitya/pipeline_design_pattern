#ifndef PIPELINE_H
#define PIPELINE_H

#include <vector>
#include <queue>
#include <thread>
#include <chrono>
#include "base_functor.h"

class Pipeline
{
private:
    std::vector<BaseFunctor*> stages_;
    std::vector<std::queue<int>> queues_;
public:
    Pipeline();
    void addStage(BaseFunctor *bf);
    std::pair<std::queue<int>*, std::queue<int>*> setupPipeline();
    void startPipeline();
    void stopPipeline();
};

#endif