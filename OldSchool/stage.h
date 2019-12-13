#ifndef STAGE_H
#define STAGE_H

#include <vector>

using namespace std;

class Stage {
  public:
    virtual void Execute(vector<int>& input)=0;
    virtual ~Stage() {};
};

class Stage1: public Stage {
  public:
    virtual void Execute(vector<int>& input);
};

class Stage2: public Stage {
  public:
    virtual void Execute(vector<int>& input);
};

#endif