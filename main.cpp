#include "add.h"
#include "multiply.h"
#include "pipeline.h"
#include <iostream>

using namespace std;

int main()
{
    Pipeline<float>* p = new Pipeline<float>();
    p->addStage(new Add());
    //    p->addStage(new Multiply());

    auto io = p->setupPipeline();
    auto i = io.first;
    auto o = io.second;

    // i->push(10); i->push(20); i->push(30); i->push(40); i->push(-1);

    for (float x = 0; x < 1000; ++x) {
        i->push(x / 10.0);
    }
    p->startPipeline();
    p->flushPipeline();
    auto done = p->isPipelineFlushed();
    // std::this_thread::sleep_for(std::chrono::milliseconds(10200));
    p->stopPipeline();

    while (o->size()) {
        std::cout << o->front() << "\t";
        o->pop();
    }
    std::cout << std::endl;
    std::cout << done << std::endl;
}
