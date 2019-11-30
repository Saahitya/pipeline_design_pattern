#ifndef ADD_H
#define ADD_H

#include "base_functor.h"
#include <queue>

class Add : public BaseFunctor {
public:
    Add(std::queue<int>* in, std::queue<int>* out);
    Add();
    virtual int stage_operation(int);
};

#endif