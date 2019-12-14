#ifndef SAVEFILE_H
#define SAVEFILE_H

#include "stage.h"
#include "payload.h"
#include <queue>

class SaveFile : public Stage<Payload*> {
public:
    SaveFile();
    virtual Payload* stage_op(Payload*);
};

#endif