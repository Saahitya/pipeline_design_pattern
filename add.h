#ifndef ADD_H
#define ADD_H

#include "stage.h"
#include <queue>

class Add : public Stage {
public:
    Add(std::queue<int>* in, std::queue<int>* out);
    Add();
    virtual int stage_operation(int);
};

#endif