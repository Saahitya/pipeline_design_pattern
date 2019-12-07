#ifndef PIPELINE_H
#define PIPELINE_H

#include "stage.h"
#include <chrono>
#include <queue>
#include <thread>
#include <vector>

class Pipeline {
private:
    std::vector<Stage*> stages_;
    std::vector<std::queue<int>> queues_;

public:
    Pipeline();
    void addStage(Stage* bf);
    std::pair<std::queue<int>*, std::queue<int>*> setupPipeline();
    void startPipeline();
    void stopPipeline();
    bool isPipelineFlushed();
    bool flushPipeline();
};

#endif