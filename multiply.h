#ifndef MULTIPLY_H
#define MULTIPLY_H

#include <queue>
#include "base_functor.h"
#include <iostream>


class Multiply: public BaseFunctor
{
public:
  Multiply(std::queue<int> *in, std::queue<int> *out);
  Multiply();
  virtual int stage_operation(int);
};
#endif