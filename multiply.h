#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "stage.h"
#include <iostream>
#include <queue>

template <class T>
class Multiply : public Stage<T> {
public:
    Multiply(T num);
    virtual T stage_op(T);

private:
    T num_;
};
#endif