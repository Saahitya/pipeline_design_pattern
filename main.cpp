#include "add.h"
#include "multiply.h"
#include "pipeline.h"
#include "payload.h"
#include <iostream>
using namespace std;

void first_example();
void second_example();
void third_example();

int main()
{
    // first_example();
    // second_example();
    third_example();
}


//basic example of simple pipeline with basic operations and fundamental datatypes done with stages being templatized. 
void first_example()
{
    Pipeline<int> *p = new Pipeline<int>();

    p->addStage(new Multiply<int>(3));

    p->addStage(new Add<int>(3));

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


//example with no stages set up and data sent comes out.
void second_example()
{
    Pipeline<Payload*> *p = new Pipeline<Payload*>();


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

void third_example()
{
    Pipeline<int> *p = new Pipeline<int>();

    // p->addStageWithCount(new Multiply<int>(3), 1);

    // p->addStageWithCount(new Add<int>(3), 1);

    p->addStage(new Multiply<int>(3));
    p->addStage(new Add<int>(3));
    // p->addStage(new Add<int>(3));
    auto io = p->setupNonLinearPipeline();
    auto i = io.first;
    auto o = io.second;

    i->push(1);

    i->push(2);
    std::cout << "popinters are " << i << " " << o << std::endl;
    p->startNonLinearPipeline();
    // p->flushPipeline();
    // auto done = p->isPipelineFlushed();
    // std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    // p->stopPipeline();
    while(o->size() != 2);
    int count = 2;
    std::cout << std::endl;
    while (!o->empty()) {
        
        // while(count) {
        int num;
        o->wait_and_pop(num);
        // if(ispop) {
        std::cout << num << "\t"; --count;
        // }
        // }
    }


    std::cout <<  std::endl;
}
