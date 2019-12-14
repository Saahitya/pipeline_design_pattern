#ifndef ADD_H
#define ADD_H

#include "stage.h"
#include <queue>

template <class T>
class Add : public Stage<T> {
public:
    Add();
    virtual T stage_op(T);
};

#endif