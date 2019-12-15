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
using namespace std;

int main()
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

    // payload 1
    Payload *pay1 = new Payload();

    pay1->inpath = "./images/big.jpeg";
    pay1->outpath = "./output/big_trans.bmp";
    i->push(pay1);

    // payload 2
    Payload *pay2 = new Payload();

    pay2->inpath = "./images/orangutan_1600x1000_279157.jpg";
    pay2->outpath = "./output/orangutan_1600x1000_279157_trans.bmp";
    // i->push(pay2);

    // payload 3
    Payload *pay3 = new Payload();

    pay3->inpath = "./images/178663.jpg";
    pay3->outpath = "./output/178663_trans.bmp";
    i->push(pay3);
    i->push(pay2);

    // payload 4

    Payload *pay4 = new Payload();

    pay4->inpath = "./images/pexels-photo-414612.jpeg";
    pay4->outpath = "./output/pexels-photo-414612_trans.bmp";
    i->push(pay4);

    

    p->startPipeline();
    // p->flushPipeline();
    // auto done = p->isPipelineFlushed();
     std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    // while (o->size()) {
    //     std::cout << o->front() << "\t";
    //     o->pop();
    // }
    // std::cout << std::endl;
    // std::cout << done << std::endl;
}
