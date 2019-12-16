#ifndef GRAYIMG_H
#define GRAYIMG_H

#include "stage.h"
#include "payload.h"
#include <queue>

class GrayImg : public Stage<Payload*> {
public:
    GrayImg();
    virtual Payload* stage_op(Payload*);
    virtual void tee(Payload *);
};

#endif