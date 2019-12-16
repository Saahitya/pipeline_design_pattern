#include "add.h"
#include "multiply.h"
#include "open_file.h"
#include "pipeline.h"
#include "payload.h"
#include "save_file.h"
#include "blur_img.h"
#include "rotate_img.h"
#include "gray_img.h"
#include <iostream>
#define NO_IMGS 100


using namespace std;

void first_example();
// void second_example();

int main()
{
    first_example();
    // second_example();
}

void first_example()
{
    Pipeline<Payload*> *p = new Pipeline<Payload*>();
    // p->addStage(new Add());
    // p->addStage(new Multiply());
    p->addStage(new OpenFile());

    p->addStage(new BlurImg());

    p->addStage(new RotateImg());

    p->addStage(new GrayImg());

    p->addStage(new SaveFile());

    

    auto io = p->setupPipeline();
    auto i = io.first;
    auto o = io.second;

    for(int j=0; j<NO_IMGS; j++) {
        Payload *p = new Payload();

        p->inpath = "./images/big.jpeg";
        p->index = to_string(j);
        p->prefix = "./tee/big_";
        p->suffix = ".jpeg";
        p->outpath = "./output/big_" + p->index + p->suffix;

        i->push(p);
    }    

    p->startPipeline();
    // p->flushPipeline();
    // auto done = p->isPipelineFlushed();
    // std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    // p->stopPipeline();
    while(o->size() != NO_IMGS);
    // while (o->size()) {
    //     std::cout << o->front() << "\t";
    //     o->pop();
    // }
    // std::cout << std::endl;
    // std::cout << done << std::endl;

}

// void second_example()
// {
//     Pipeline<int*> *p = new Pipeline<>();
// }