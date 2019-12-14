#ifndef OPENFILE_H
#define OPENFILE_H

#include "stage.h"
#include "payload.h"
#include <queue>

class OpenFile : public Stage<Payload*> {
public:
    OpenFile();
    virtual Payload* stage_op(Payload*);
};

#endif