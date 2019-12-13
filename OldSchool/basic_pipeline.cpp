#include "basic_pipeline.h"
#include "stage.h"
#include <iostream>

void BasicPipeline::Execute(vector<int>& input)
{
    for (Stage* stage : pipeline_stages) {
        stage->Execute(input);
    }
}

void BasicPipeline::AddStage(Stage* stage)
{
    pipeline_stages.push_back(stage);
}
