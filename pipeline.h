#ifndef PIPELINE_H
#define PIPELINE_H

#include "base_functor.h"
#include <chrono>
#include <queue>
#include <thread>
#include <vector>

class Pipeline {
private:
    std::vector<BaseFunctor*> stages_;
    std::vector<std::queue<int>> queues_;

public:
    Pipeline();
    void addStage(BaseFunctor* bf);
    std::pair<std::queue<int>*, std::queue<int>*> setupPipeline();
    void startPipeline();
    void stopPipeline();
    bool isPipelineFlushed();
};

#endif