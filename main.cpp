#include "add.h"
#include "multiply.h"
#include "open_file.h"
#include "pipeline.h"
#include "payload.h"
#include <iostream>
using namespace std;

int main()
{
    Pipeline<Payload>* p = new Pipeline<Payload>();
    // p->addStage(new Add());
    // p->addStage(new Multiply());
    p->addStage(new OpenFile());

    auto io = p->setupPipeline();
    auto i = io.first;
    auto o = io.second;

    Payload *pay1 = new Payload();

    pay1->path = "big.jpeg";

    i->push(*pay1);

    p->startPipeline();
    // p->flushPipeline();
    // auto done = p->isPipelineFlushed();
    // // std::this_thread::sleep_for(std::chrono::milliseconds(10200));
    p->stopPipeline();

    // while (o->size()) {
    //     std::cout << o->front() << "\t";
    //     o->pop();
    // }
    // std::cout << std::endl;
    // std::cout << done << std::endl;
}
