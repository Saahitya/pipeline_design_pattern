#ifndef BLURIMG_H
#define BLURIMG_H

#include "stage.h"
#include "payload.h"
#include <queue>

class BlurImg : public Stage<Payload*> {
public:
    BlurImg();
    virtual Payload* stage_op(Payload*);
};

#endif