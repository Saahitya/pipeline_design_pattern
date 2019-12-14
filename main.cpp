#include "add.h"
#include "multiply.h"
#include "open_file.h"
#include "pipeline.h"
#include "payload.h"
#include "save_file.h"
#include <iostream>
using namespace std;

int main()
{
    Pipeline<Payload*> *p = new Pipeline<Payload*>();
    // p->addStage(new Add());
    // p->addStage(new Multiply());
    p->addStage(new OpenFile());

    p->addStage(new SaveFile());

    auto io = p->setupPipeline();
    auto i = io.first;
    auto o = io.second;

    // payload 1
    Payload *pay1 = new Payload();

    pay1->inpath = "big.jpeg";
    pay1->outpath = "./output/big_trans.bmp";
    i->push(pay1);

    // payload 2
    Payload *pay2 = new Payload();

    pay2->inpath = "big.jpeg";
    pay2->outpath = "./output/big_trans.jpeg";
    i->push(pay2);

    p->startPipeline();
    // p->flushPipeline();
    // auto done = p->isPipelineFlushed();
    // std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    p->stopPipeline();

    // while (o->size()) {
    //     std::cout << o->front() << "\t";
    //     o->pop();
    // }
    // std::cout << std::endl;
    // std::cout << done << std::endl;
}
