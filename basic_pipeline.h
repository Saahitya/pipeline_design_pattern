#ifndef BASIC_PIPELINE_H
#define BASIC_PIPELINE_H

#include <vector>
#include "stage.h"

class BasicPipeline {
  private:
    vector<Stage*> pipeline_stages;
    int no_of_pipeline_stages;
  
  public:
    BasicPipeline() {
      no_of_pipeline_stages=0;
    }

    void Execute(vector<int>& input);
    void AddStage(Stage *stage);

};

#endif //BASIC_PIPELINE_H