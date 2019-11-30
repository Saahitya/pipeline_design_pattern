#ifndef ADD_H
#define ADD_H

#include <queue>
#include "base_functor.h"

class Add: public BaseFunctor
{
public:
  Add(std::queue<int> *in, std::queue<int> *out);
  Add();
  virtual int stage_operation(int);
};

#endif