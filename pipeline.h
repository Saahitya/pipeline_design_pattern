#ifndef PIPELINE_H
#define PIPELINE_H

#include "stage.h"
#include <chrono>
#include <queue>
#include <thread>
#include <vector>

template <class T>
class Pipeline {
private:
    std::vector<Stage<T>*> stages_;
    std::vector<std::queue<T>> queues_;

public:
    Pipeline();
    void addStage(Stage<T>* bf);
    std::pair<std::queue<T>*, std::queue<T>*> setupPipeline();
    void startPipeline();
    void stopPipeline();
    bool isPipelineFlushed();
    bool flushPipeline();
};

#endif