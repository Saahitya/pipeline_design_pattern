#ifndef ADD_H
#define ADD_H

#include "stage.h"
#include <queue>

class Add : public Stage<float> {
public:
    Add();
    virtual float stage_op(float);
};

#endif