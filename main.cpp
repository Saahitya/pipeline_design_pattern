#include <iostream>
#include "pipeline.h"
#include "multiply.h"
#include "add.h"

using namespace std;

int main()
{
  Pipeline *p = new Pipeline();
  p->addStage(new Add());
  p->addStage(new Multiply());

  auto io = p->setupPipeline();
  auto i = io.first;
  auto o = io.second;

  // i->push(10); i->push(20); i->push(30); i->push(40); i->push(-1);

  for(int x=0; x < 1000; ++x)
  {
    i->push(x);
  }
  
  p->startPipeline();
  std::this_thread::sleep_for(std::chrono::milliseconds(10));
  p->stopPipeline();


  while(o->size()) {
    std::cout << o->front() << "\t";
    o->pop();
  }
  std::cout << std::endl;

}
