#include "ProgramExecutor.h"

void ProgramExecutor::executeWorkflow(blueprint &&workflow) {
    if (workflow.queue.empty() || workflow.blocks.empty()){
        return;
    }
    vector<string> input;
    vector<string> output;
    conveyor curStage = {output, input, workflow.queue.front(), false, true};
    for(auto i: workflow.queue){
        workflow.blocks[i]->execute(curStage);
        curStage.input = curStage.output;
        curStage.output = input;
        curStage.output.clear();
        curStage.haveInput = curStage.haveOutput;
    }
}
