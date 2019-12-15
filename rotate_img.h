#ifndef ROTATEIMG_H
#define ROTATEIMG_H

#include "stage.h"
#include "payload.h"
#include <queue>

class RotateImg : public Stage<Payload*> {
public:
    RotateImg();
    virtual Payload* stage_op(Payload*);
};

#endif