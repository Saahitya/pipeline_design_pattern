#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "stage.h"
#include <iostream>
#include <queue>

class Multiply : public Stage<int> {
public:
    Multiply();
    virtual int stage_op(int);
};
#endif