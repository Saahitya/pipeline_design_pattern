#include "add.h"
#include "multiply.h"
#include "open_file.h"
#include "pipeline.h"
#include "payload.h"
#include "save_file.h"
#include <iostream>
using namespace std;

void first_example();
void second_example();

int main()
{
    first_example();
    second_example();
}

void first_example()
{
    Pipeline<int> *p = new Pipeline<int>();

    p->addStage(new Multiply());

    p->addStage(new Add<int>());

    auto io = p->setupPipeline();
    auto i = io.first;
    auto o = io.second;

    i->push(1);

    i->push(2);

    p->startPipeline();
    // p->flushPipeline();
    // auto done = p->isPipelineFlushed();
    // std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    p->stopPipeline();

    while (o->size()) {
        std::cout << o->front() << "\t";
        o->pop();
    }
    std::cout << std::endl;
    // std::cout << done << std::endl;
}

void second_example()
{
    Pipeline<Payload*> *p = new Pipeline<Payload*>();

    p->addStage(new OpenFile());

    p->addStage(new SaveFile());

    auto io = p->setupPipeline();
    auto i = io.first;
    auto o = io.second;

    Payload *pay1 = new Payload();
    pay1->num = 2;
    i->push(pay1);

    Payload *pay2 = new Payload();
    pay2->num = 3;
    i->push(pay2);

    p->startPipeline();
    // p->flushPipeline();
    // auto done = p->isPipelineFlushed();
    // std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    p->stopPipeline();

    while (o->size()) {
        std::cout << o->front()->num << "\t";
        o->pop();
    }
    std::cout << std::endl;
    // std::cout << done << std::endl;

}